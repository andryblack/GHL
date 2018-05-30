package com.GHL;

import android.widget.EditText;

import android.view.KeyEvent;
import android.view.inputmethod.BaseInputConnection;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputConnection;

import android.graphics.Canvas;

import android.text.InputType;
import android.text.TextWatcher;
import android.text.Editable;


import com.GHL.Log;

class InvisibleEdit extends EditText {
    private long m_instance = 0;
    Activity m_activity;
    GHLInputConnection ic;
    boolean m_text_mode = false;
    boolean m_block_events = false;

    private static final String TAG = "GHL-input";

    class GHLInputConnection extends BaseInputConnection {
        Editable m_editable;
        public GHLInputConnection(InvisibleEdit targetView, boolean fullEditor) {
            super(targetView, fullEditor);
            m_editable = targetView.getText();
        }

        @Override
        public Editable getEditable () {
            if (m_text_mode) {
                return getText();
            }
            return super.getEditable();
        }

        @Override
        public boolean sendKeyEvent(KeyEvent event) {
            if (m_text_mode && event.getKeyCode() != KeyEvent.KEYCODE_ENTER) {
                return super.sendKeyEvent(event);
            }
            final KeyEvent finalEvent = event;
            m_activity.runOnUiThread(new Runnable(){
                 @Override
                 public void run() {
                    Activity.nativeOnKey(m_instance,finalEvent.getKeyCode(),finalEvent.getUnicodeChar(),finalEvent.getAction());
                }
            });
            return true;
        }
        @Override
        public boolean commitText(CharSequence text, int newCursorPosition) {
            if (m_text_mode) {
                boolean res = super.commitText(text,newCursorPosition);
                return res;
            }
            final CharSequence finalText = text;
            m_activity.runOnUiThread(new Runnable(){
                 @Override
                 public void run() {
                    for (int i=0;i<finalText.length();i++) {
                        char c = finalText.charAt(i);
                        Activity.nativeOnKey(m_instance,0,c,0);
                        Activity.nativeOnKey(m_instance,0,c,1);
                    }
                }
            });
            return true;
        }

        @Override
        public boolean setComposingText (CharSequence text, int newCursorPosition) {
            Log.i(TAG,"setComposingText: " + text);
            if (m_text_mode) {
                boolean res =  super.setComposingText(text,newCursorPosition);
                return res;
            }
            final CharSequence finalText = text;
            m_activity.runOnUiThread(new Runnable(){
                 @Override
                 public void run() {
                    for (int i=0;i<finalText.length();i++) {
                        char c = finalText.charAt(i);
                        Activity.nativeOnKey(m_instance,0,c,0);
                        Activity.nativeOnKey(m_instance,0,c,1);
                    }
                }
            });
            return true;
        }
        @Override
        public boolean deleteSurroundingText(int beforeLength, int afterLength) {
            if (m_text_mode) {
                return super.deleteSurroundingText(beforeLength,afterLength);
            }
            if (beforeLength > 0 && afterLength == 0) {
                Activity.nativeOnKey(m_instance,KeyEvent.KEYCODE_DEL,0,0);
                Activity.nativeOnKey(m_instance,KeyEvent.KEYCODE_DEL,0,1);
            }

            return true;
        }
    }


    public InvisibleEdit(Activity context,long instance) {
        super(context);
        m_activity = context;
        m_instance = instance;
        
        setFocusableInTouchMode(true);
        setFocusable(true);
        addTextChangedListener(new TextWatcher() {
            @Override
            public void afterTextChanged(Editable s) {
                Log.d(TAG,"afterTextChanged:");
                sendText();
            }
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }
            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                Log.d(TAG,"onTextChanged:" + s);
            }
        });
    }

    void sendText() {
        if (m_text_mode && !m_block_events) {
            Activity.nativeOnTextInputChanged(m_instance,
                getText().toString(),
                utf32position(getSelectionEnd()));
        }
    }
    @Override
    public boolean dispatchKeyEventPreIme ( KeyEvent event) {
        if (m_text_mode && (event.getKeyCode() != KeyEvent.KEYCODE_ENTER)
                && (event.getKeyCode() != KeyEvent.KEYCODE_BACK)) {
            return super.dispatchKeyEventPreIme(event);
        }
        final KeyEvent finalEvent = event;
        m_activity.runOnUiThread( new Runnable() {
            @Override
            public void run() {
                if (finalEvent.getKeyCode() == KeyEvent.KEYCODE_BACK) {
                    Activity.nativeOnKeyboardHide(m_instance);
                } else {
                    Activity.nativeOnKey(m_instance,finalEvent.getKeyCode(), finalEvent.getUnicodeChar(), finalEvent.getAction() );
                }
            }
        });
        return true;
    }

    @Override
    public InputConnection onCreateInputConnection(EditorInfo outAttrs) {
        ic = new GHLInputConnection(this, true);

        outAttrs.inputType = InputType.TYPE_CLASS_TEXT;
        outAttrs.imeOptions = EditorInfo.IME_FLAG_NO_EXTRACT_UI
                | 33554432 /* API 11: EditorInfo.IME_FLAG_NO_FULLSCREEN */
                | EditorInfo.IME_ACTION_DONE;

        return ic;
    }


    @Override
    protected void onLayout(boolean v, int x, int y, int w, int h) {
        Log.d(TAG,"onLayout " + x + "," + y + "," + w + "," + h );
        final int fx = x;
        final int fy = y;
        final int fw = w;
        final int fh = h;
        m_activity.runOnUiThread(new Runnable(){
             @Override
             public void run() {
                Activity.nativeOnScreenRectChanged(m_instance,fx,fy,fw,fh);
            }
        });
        super.onLayout(v,x,y,w,h);
    }


    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
    }

    public void setTextMode(String text,int cursor_position) {
        m_text_mode = true;
        m_block_events = true;
        setText(text);
        setSelection(utf16position(cursor_position));
        m_block_events = false;
    }
    public void setKeyMode() {
        m_text_mode = false;
        m_block_events = true;
        setText("");
        m_block_events = false;
    }

    boolean isSurrogateHighCharacter(char ch) {
        return (ch >= 0xD800) && (ch <= 0xDBFF);
    }

    int utf32position(int index) {
        int idx = 0;
        int i =0;
        String text = getText().toString();
        while (idx<index) {
            char ch = text.charAt(idx);
            if (isSurrogateHighCharacter(ch)) {
                idx += 2;
            } else {
                idx += 1;
            }
            ++i;
        }
        return i;
    }

    int utf16position(int index) {
        int idx = 0;
        int i =0;
        String text = getText().toString();
        while (i<index) {
            char ch = text.charAt(idx);
            if (isSurrogateHighCharacter(ch)) {
                idx += 2;
            } else {
                idx += 1;
            }
            ++i;
        }
        return idx;
    }


}