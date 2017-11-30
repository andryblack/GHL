package com.GHL;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.content.Intent;
import android.content.Context;
import android.content.pm.ApplicationInfo;
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
import android.text.Editable;

import android.R;

import android.os.Looper;
import android.os.Handler;

import android.graphics.Canvas;
import android.graphics.*;

import android.media.AudioManager;

import com.GHL.Log;
import android.widget.TextView;

public class Activity  extends android.app.NativeActivity  {

    private static final String TAG = "GHL";

    static native boolean nativeOnKey(int keycode,long unicode,long action);
    static native void nativeOnKeyboardHide();
    static native void nativeOnTextInputDismiss();
    static native void nativeOnTextInputAccepted(String text);
    static native void nativeOnTextInputChanged(String text);

    static native void nativeOnScreenRectChanged(int left, int top, int width, int height);
    static native boolean nativeOnIntent(Intent i);

    class InvisibleEdit extends EditText {
        
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
            @Override
            public boolean deleteSurroundingText(int beforeLength, int afterLength) {
                if (beforeLength > 0 && afterLength == 0) {
                    nativeOnKey(KeyEvent.KEYCODE_DEL,0,0);
                    nativeOnKey(KeyEvent.KEYCODE_DEL,0,1);
                }

                return true;
            }
        }


        public InvisibleEdit(Activity context) {
            super(context);
            setFocusableInTouchMode(true);
            setFocusable(true);
        }

        @Override
        public boolean dispatchKeyEventPreIme ( KeyEvent event) {
            final KeyEvent finalEvent = event;
            runOnUiThread( new Runnable() {
                @Override
                public void run() {
                    if (finalEvent.getKeyCode() == KeyEvent.KEYCODE_BACK) {
                        nativeOnKeyboardHide();
                    } else {
                        nativeOnKey(finalEvent.getKeyCode(), finalEvent.getUnicodeChar(), finalEvent.getAction() );
                    }
                }
            });
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
        protected void onLayout(boolean v, int x, int y, int w, int h) {
            Log.d(TAG,"onLayout " + x + "," + y + "," + w + "," + h );
            final int fx = x;
            final int fy = y;
            final int fw = w;
            final int fh = h;
            Activity.this.runOnUiThread(new Runnable(){
                 @Override
                 public void run() {
                    nativeOnScreenRectChanged(fx,fy,fw,fh);
                }
            });
            
        }


        @Override
        protected void onDraw(Canvas canvas) {
               
        }
    }

	private static boolean libloaded = false;
    public static void ensureLoadLibraryForContext( android.content.Context context ) {
         if (libloaded) {
            return;
        }
        String libname = "main";
        try {
            ApplicationInfo ai = context.getPackageManager().getApplicationInfo(context.getPackageName(), 
                 PackageManager.GET_META_DATA);  
            if (ai.metaData != null) {
                String ln = ai.metaData.getString(android.app.NativeActivity.META_DATA_LIB_NAME);
                if (ln != null) libname = ln;
            }
        } catch (Exception e) {
            android.util.Log.e(TAG,"Error getting activity info" + e);
        }
        System.loadLibrary(libname);
        libloaded = true;
    }
    public void ensureLoadLibrary(  ) {
       ensureLoadLibraryForContext(getApplicationContext());
    }


    public boolean showSoftKeyboard() {
        Log.v(TAG, "showSoftKeyboard");
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                showTextEditImpl();
            }
        });
        return true;
    }

    public boolean hideSoftKeyboard() {
        Log.v(TAG, "hideSoftKeyboard");
        InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
        boolean res = false;

        if (m_text_edit_window != null) {
            EditText text_edit = (EditText)(m_text_edit_window.getContentView()).findViewWithTag("text_edit");
            imm.hideSoftInputFromWindow(text_edit.getWindowToken(), 0);
            m_text_edit_window.dismiss();
        }
        if (m_text_input_window != null) {
            EditText text_input = (EditText)(m_text_input_window.getContentView()).findViewWithTag("text_input");
            imm.hideSoftInputFromWindow(text_input.getWindowToken(), 0);
            m_text_input_window.dismiss();
        }
        return res;
    }



    private PopupWindow m_text_input_window = null;
    private PopupWindow m_text_edit_window = null;


    public void showTextInput(int accept_button,String placeholder) {
        Log.v(TAG, "showTextInput");
        final int accept_button_f = accept_button;
        final String placeholder_f = placeholder;
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                showTextInputImpl(accept_button_f,placeholder_f);
            }
        });
    }



    private void showTextInputImpl(int accept_button,String placeholder) {
        
        if (m_text_input_window == null) {
            Log.v(TAG, "create text_input");

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
                        final String text = textView.getText().toString();
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                nativeOnTextInputAccepted(text);
                            }
                        });
                        if (m_text_input_window!=null) 
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
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            nativeOnTextInputDismiss();
                        }
                    });
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


    private void showTextEditImpl() {
        boolean create = false;

        if (m_text_edit_window == null) {
            Log.v(TAG, "create text_edit");
            create = true;

            LinearLayout containerLayout = new LinearLayout(this);


            InvisibleEdit et = new InvisibleEdit(this);

            et.setTag("text_edit");
            et.setGravity(Gravity.BOTTOM);
            et.setBackgroundDrawable(new ColorDrawable(Color.TRANSPARENT));
            et.setOnEditorActionListener(new TextView.OnEditorActionListener() {
                @Override
                public boolean onEditorAction(TextView textView, int i, KeyEvent keyEvent) {
                    if (i == EditorInfo.IME_ACTION_DONE ) {
                        runOnUiThread( new Runnable() {
                            @Override
                            public void run() {
                                nativeOnKey(KeyEvent.KEYCODE_ENTER,0,0);
                                nativeOnKey(KeyEvent.KEYCODE_ENTER,0,1);
                            }
                        });
                        
                       return true;
                    }
                    return false;
                }
            });


            et.setTextIsSelectable(false);

            final EditText fet = et;

           
            LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT,
                    LinearLayout.LayoutParams.MATCH_PARENT);
            params.gravity = Gravity.FILL;
            params.setMargins(0,0,0,0);
            
            containerLayout.setOrientation(LinearLayout.VERTICAL);
            containerLayout.addView(et, params);
            
            PopupWindow popUpWindow = new PopupWindow(containerLayout,320,32,true);

            m_text_edit_window = popUpWindow;
            m_text_edit_window.setBackgroundDrawable(new ColorDrawable(Color.TRANSPARENT));
            m_text_edit_window.setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_ADJUST_RESIZE);
            m_text_edit_window.setOutsideTouchable(false);
            m_text_edit_window.setTouchable(false);

            m_text_edit_window.update();

            m_text_edit_window.setOnDismissListener(new PopupWindow.OnDismissListener() {
                @Override
                public void onDismiss() {
                    final View view = getWindow().getDecorView();
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            nativeOnScreenRectChanged(0,0,
                                view.getWidth(),
                                view.getHeight());
                        }
                    });
                }
            });
        }


        m_text_edit_window.setWidth(getWindow().getDecorView().getWidth());
        m_text_edit_window.setHeight(WindowManager.LayoutParams.FILL_PARENT);

        m_text_edit_window.showAtLocation(getWindow().getDecorView(), Gravity.FILL_VERTICAL, 0, 0);
        m_text_edit_window.update();

        final EditText text_edit = (EditText)(m_text_edit_window.getContentView()).findViewWithTag("text_edit");
        if (text_edit != null) {
            Log.v(TAG,"Activate edit input");
            text_edit.setText("");
            final InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
            Handler handler = new Handler(Looper.getMainLooper());
            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    text_edit.requestFocus();
                    imm.showSoftInput(text_edit, 0);
                }
            }, 0);

        }

        
    }



    
    public boolean openURL(String url) {
        startActivity(new Intent(Intent.ACTION_VIEW, android.net.Uri.parse(url)));
        return true;
    }



    @Override
    protected void onCreate(Bundle savedInstanceState){
        ensureLoadLibrary();
        Log.v(TAG, "onCreate");
        super.onCreate(savedInstanceState);
        //setVolumeControlStream(AudioManager.STREAM_MUSIC);
    }

    @Override
    protected void onDestroy(){
        ensureLoadLibrary();
        Log.v(TAG, "onDestroy");
        super.onDestroy();
    }

    @Override
    protected void onPause(){
        ensureLoadLibrary();
        Log.v(TAG, "onPause");
        super.onPause();
    }

    @Override
    protected void onResume(){
        ensureLoadLibrary();
        Log.v(TAG, "onResume");
        super.onResume();

        Intent i = getIntent();
        if (i!=null) {
            if (i.getBooleanExtra("com.GHL.intent_handled",false) == false) {
                Log.v(TAG, "new intent " + i.toString());
                if (nativeOnIntent(i)) {
                    i.putExtra("com.GHL.intent_handled",true);
                }
            } else {
                Log.v(TAG, "processed intent " + i.toString());
            }
        }
    }

    @Override
    protected void onStart(){
        ensureLoadLibrary();
        Log.v(TAG, "onStart");
        super.onStart();
    }

    @Override
    protected void onStop(){
        ensureLoadLibrary();
         Log.v(TAG, "onStop");
        super.onStop();
        
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        ensureLoadLibrary();
        super.onSaveInstanceState(outState);
    }

    @Override
    protected void onActivityResult(int requestCode,
                                        int resultCode,
                                        Intent data) {
        ensureLoadLibrary();
        super.onActivityResult(requestCode, resultCode, data);
    }
    @Override
    protected void onNewIntent(Intent intent) {
        ensureLoadLibrary();
        Log.v(TAG,"onNewIntent " + intent.toString());
        super.onNewIntent(intent);
        setIntent(intent);
    }

}
