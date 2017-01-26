package com.GHL;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.content.Intent;
import android.content.Context;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;

import android.view.MotionEvent;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.BaseInputConnection;
import android.view.inputmethod.InputConnection;

import android.view.WindowManager;
import android.view.KeyEvent;
import android.view.ViewGroup;
import android.view.Gravity;

import android.widget.AbsoluteLayout;
import android.widget.RelativeLayout;
import android.widget.LinearLayout;
import android.widget.EditText;
import android.widget.PopupWindow;

import android.text.InputType;

import android.R;

import android.os.Looper;
import android.os.Handler;

import android.graphics.Canvas;
import android.graphics.*;

import android.media.AudioManager;

import android.util.Log;
import android.widget.TextView;

public class Activity  extends android.app.NativeActivity  {

    private static final String TAG = "GHL";

    static native boolean nativeOnKey(int keycode,long unicode,long action);
    static native void nativeOnTextInputDismiss();
    static native void nativeOnTextInputAccepted(String text);
    static native void nativeOnTextInputChanged(String text);

    static native void nativeOnScreenRectChanged(int left, int top, int width, int height);

    class InvisibleEdit extends View {
        GHLInputConnection ic;
        
        class GHLInputConnection extends BaseInputConnection {
           
            public GHLInputConnection(InvisibleEdit targetView, boolean fullEditor) {
                super(targetView, fullEditor);
            }

            @Override
            public boolean sendKeyEvent(KeyEvent event) {
                final KeyEvent finalEvent = event;
                Activity.this.runOnUiThread(new Runnable(){
                     @Override
                     public void run() {
                        nativeOnKey(finalEvent.getKeyCode(),finalEvent.getUnicodeChar(),finalEvent.getAction());
                    }
                });
                return true;
            }
            @Override
            public boolean commitText(CharSequence text, int newCursorPosition) {
                final CharSequence finalText = text;
                Activity.this.runOnUiThread(new Runnable(){
                     @Override
                     public void run() {
                        for (int i=0;i<finalText.length();i++) {
                            char c = finalText.charAt(i);
                            nativeOnKey(0,c,0);
                            nativeOnKey(0,c,1);
                        }
                    }
                });
                return true;
            }
            @Override
            public boolean setComposingText (CharSequence text, int newCursorPosition) {
                final CharSequence finalText = text;
                Activity.this.runOnUiThread(new Runnable(){
                     @Override
                     public void run() {
                        for (int i=0;i<finalText.length();i++) {
                            char c = finalText.charAt(i);
                            nativeOnKey(0,c,0);
                            nativeOnKey(0,c,1);
                        }
                    }
                });
                return true;
            }
        }



        public InvisibleEdit(Activity context) {
            super(context);
            setFocusableInTouchMode(true);
            setFocusable(true);
            //setImeOptions(EditorInfo.IME_FLAG_NO_EXTRACT_UI);
        }


        @Override public boolean dispatchKeyEvent (KeyEvent event) {
            final KeyEvent finalEvent = event;
            runOnUiThread( new Runnable() {
                @Override
                public void run() {
                    nativeOnKey(finalEvent.getKeyCode(), finalEvent.getUnicodeChar(), finalEvent.getAction() );
                }
            });
            return true;
        }
          
        @Override
        public boolean dispatchKeyEventPreIme ( KeyEvent event) {
            final KeyEvent finalEvent = event;
            runOnUiThread( new Runnable() {
                @Override
                public void run() {
                    nativeOnKey(finalEvent.getKeyCode(), finalEvent.getUnicodeChar(), finalEvent.getAction() );
                }
            });
            return true;
        }

        @Override
        public boolean onCheckIsTextEditor() {
            return true;
        }

        
        @Override
        public InputConnection onCreateInputConnection(EditorInfo outAttrs) {
            ic = new GHLInputConnection(this, true);

            outAttrs.inputType = InputType.TYPE_CLASS_TEXT | InputType.TYPE_TEXT_VARIATION_VISIBLE_PASSWORD;
            outAttrs.imeOptions = EditorInfo.IME_FLAG_NO_EXTRACT_UI
                    | 33554432 /* API 11: EditorInfo.IME_FLAG_NO_FULLSCREEN */;

            return ic;
        }
        
        @Override
        protected void onSizeChanged(int w, int h, int oldw, int oldh) {
            super.onSizeChanged(w, h, oldw, oldh);
            Log.v(TAG, "onSizeChanged " + oldw + "x" + oldh+"->"+w+"x"+h);
        }

        @Override
        protected void onDraw(Canvas canvas) {
               
        }
    }

    private InvisibleEdit m_text_edit;

	private static boolean libloaded = false;
    private void ensureLoadLibrary() {
        if (libloaded) {
            return;
        }
        String libname = "main";
        try {
            ActivityInfo ai = getPackageManager().getActivityInfo(
                                                     getIntent().getComponent(), PackageManager.GET_META_DATA);
            if (ai.metaData != null) {
                String ln = ai.metaData.getString(android.app.NativeActivity.META_DATA_LIB_NAME);
                if (ln != null) libname = ln;
            }
        } catch (PackageManager.NameNotFoundException e) {
            throw new RuntimeException("Error getting activity info", e);
        }
        System.loadLibrary(libname);
        libloaded = true;
    }


    public void showSoftKeyboard() {
        if (m_text_edit == null) {
            ViewGroup.LayoutParams params = new ViewGroup.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT);
            m_text_edit = new InvisibleEdit(Activity.this);
            //m_text_edit.setId(100500);
            addContentView(m_text_edit,params);
            m_text_edit.getViewTreeObserver().addOnGlobalLayoutListener(new android.view.ViewTreeObserver.OnGlobalLayoutListener() {
                @Override 
                public void onGlobalLayout() {
                    Rect r = new Rect();
                    m_text_edit.getWindowVisibleDisplayFrame(r);
                    final Rect fr = r;
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            nativeOnScreenRectChanged(fr.left,fr.top,fr.width(),fr.height());
                        }
                    });
                }
            });
        } 
        m_text_edit.setVisibility(View.VISIBLE);
        m_text_edit.requestFocus();
        
        getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_VISIBLE|
            WindowManager.LayoutParams.SOFT_INPUT_ADJUST_RESIZE);

        InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
        imm.showSoftInput(m_text_edit, 0);
    }


    private PopupWindow m_text_input_window = null;


    public void showTextInput(int accept_button,String placeholder) {
        Log.v(TAG, "showTextInput");
        if (m_text_input_window == null) {
            Log.v(TAG, "create");

            LinearLayout containerLayout = new LinearLayout(this);


            EditText et = new EditText(this);

            et.setTag("text_input");
            et.setGravity(Gravity.BOTTOM);
            et.setInputType(InputType.TYPE_CLASS_TEXT);
            et.setImeOptions(EditorInfo.IME_ACTION_DONE);
            et.setOnEditorActionListener(new TextView.OnEditorActionListener() {
                @Override
                public boolean onEditorAction(TextView textView, int i, KeyEvent keyEvent) {
                    if (i == EditorInfo.IME_ACTION_DONE ||
                            i == EditorInfo.IME_ACTION_SEND) {

                        nativeOnTextInputAccepted(textView.getText().toString());
                        m_text_input_window.dismiss();
                        return true;
                    }
                    return false;
                }
            });


            et.setFocusable(true);


            LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT,
                    LinearLayout.LayoutParams.MATCH_PARENT);
            params.gravity = Gravity.BOTTOM;
            params.setMargins(0,0,0,0);
            
            containerLayout.setOrientation(LinearLayout.VERTICAL);
            containerLayout.addView(et, params);
            
            PopupWindow popUpWindow = new PopupWindow(containerLayout,320,32,true);

            m_text_input_window = popUpWindow;
            m_text_input_window.setBackgroundDrawable(new ColorDrawable(Color.TRANSPARENT));
            m_text_input_window.setFocusable(true);
            m_text_input_window.setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_ADJUST_RESIZE);
            m_text_input_window.setOutsideTouchable(true);
            m_text_input_window.setTouchable(true);

            m_text_input_window.setOnDismissListener(new PopupWindow.OnDismissListener() {
                @Override
                public void onDismiss() {
                    nativeOnTextInputDismiss();
                }
            });
            m_text_input_window.update();


        }


        m_text_input_window.setWidth(getWindow().getDecorView().getWidth());
        m_text_input_window.setHeight(WindowManager.LayoutParams.WRAP_CONTENT);

        m_text_input_window.showAtLocation(getWindow().getDecorView(), Gravity.BOTTOM, 0, 0);
        m_text_input_window.update();

        final EditText text_input = (EditText)(m_text_input_window.getContentView()).findViewWithTag("text_input");
        if (text_input != null) {
            Log.v(TAG,"Activate text input");
            text_input.setImeOptions(accept_button);
            text_input.setText("");
            if (placeholder!=null) {
                text_input.setHint(placeholder);
            } else {
                text_input.setHint("");
            }
            final InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
            Handler handler = new Handler(Looper.getMainLooper());
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    text_input.requestFocus();
                    imm.showSoftInput(text_input, 0);
                }
            }, 0);
        }

        
    }



    public void hideSoftKeyboard() {
        InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);

        if (m_text_edit != null) {
            imm.hideSoftInputFromWindow(m_text_edit.getWindowToken(), 0);
            m_text_edit.setVisibility(View.VISIBLE);
        }
        if (m_text_input_window != null) {
            EditText text_input = (EditText)(m_text_input_window.getContentView()).findViewWithTag("text_input");
            imm.hideSoftInputFromWindow(text_input.getWindowToken(), 0);
            m_text_input_window.dismiss();
        }
    }

    public boolean openURL(String url) {
        startActivity(new Intent(Intent.ACTION_VIEW, android.net.Uri.parse(url)));
        return true;
    }



    @Override
    protected void onCreate(Bundle savedInstanceState){
        Log.v(TAG, "onCreate");
        super.onCreate(savedInstanceState);
        ensureLoadLibrary();
        //setVolumeControlStream(AudioManager.STREAM_MUSIC);
    }

    @Override
    protected void onDestroy(){
        Log.v(TAG, "onDestroy");
        super.onDestroy();
        ensureLoadLibrary();
    }

    @Override
    protected void onPause(){
        Log.v(TAG, "onPause");
        super.onPause();
        ensureLoadLibrary();
    }

    @Override
    protected void onResume(){
        Log.v(TAG, "onResume");
        super.onResume();
        ensureLoadLibrary();
    }

    @Override
    protected void onStart(){
        super.onStart();
        ensureLoadLibrary();
    }

    @Override
    protected void onStop(){
        super.onStop();
        ensureLoadLibrary();
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        ensureLoadLibrary();
    }

    @Override
    protected void onActivityResult(int requestCode,
                                        int resultCode,
                                        Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        ensureLoadLibrary();
    }

}
