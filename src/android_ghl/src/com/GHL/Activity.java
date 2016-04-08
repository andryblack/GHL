package com.GHL;
import android.os.Bundle;
import android.content.Intent;
import android.content.Context;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;

import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.BaseInputConnection;
import android.view.inputmethod.InputConnection;

import android.view.WindowManager;
import android.view.KeyEvent;
import android.view.ViewGroup;

import android.widget.AbsoluteLayout;
import android.widget.EditText;

import android.text.InputType;

import android.R;

import android.os.Looper;
import android.os.Handler;

public class Activity  extends android.app.NativeActivity  {

    static native boolean nativeOnKey(int keycode,long unicode,long action);
    class InvisibleEdit extends View {
        GHLInputConnection ic;
        
        class GHLInputConnection extends BaseInputConnection {
           
            public GHLInputConnection(InvisibleEdit targetView, boolean fullEditor) {
                super(targetView, fullEditor);
            }

            @Override
            public boolean sendKeyEvent(KeyEvent event) {
                final KeyEvent finalEvent = event;
                runOnRenderThread(new Runnable(){
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
                runOnRenderThread(new Runnable(){
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
                runOnRenderThread(new Runnable(){
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
            runOnRenderThread( new Runnable() {
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
            runOnRenderThread( new Runnable() {
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
    }

    private InvisibleEdit m_text_edit;
    private ViewGroup m_layout;
    private Handler m_render_thread_handler;

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


    public void reportRenderThread() {
        m_render_thread_handler = new Handler(Looper.myLooper());
    }

    public void runOnRenderThread(Runnable r) {
        if (m_render_thread_handler != null) {
            if (!m_render_thread_handler.post(r)) {
                r.run();
            }
        } else {
            r.run();
        }
    }

    public void showSoftKeyboard() {
        runOnUiThread(new Runnable(){
             //@override
             public void run() {
                AbsoluteLayout.LayoutParams params = new AbsoluteLayout.LayoutParams(
                    10, 10, 0, 0);

                if (m_text_edit == null) {
                    m_text_edit = new InvisibleEdit(Activity.this);
                    m_layout.addView(m_text_edit, params);
                } else {
                    m_text_edit.setLayoutParams(params);
                }
                m_text_edit.setVisibility(View.VISIBLE);
                m_text_edit.requestFocus();

                InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
                imm.showSoftInput(m_text_edit, 0);
            }
        });
    }

    public void hideSoftKeyboard() {
        runOnUiThread(new Runnable(){
             //@override
             public void run() {
                if (m_text_edit != null) {
                    m_text_edit.setVisibility(View.GONE);
                    InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
                    imm.hideSoftInputFromWindow(m_text_edit.getWindowToken(), 0);
                }
            }
        });
    }

    
    

    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        ensureLoadLibrary();
        m_layout = new AbsoluteLayout(this);
        setContentView(m_layout);
    }
    
    protected void onDestroy(){
        super.onDestroy();
        ensureLoadLibrary();
    }
    
    protected void onPause(){
        super.onPause();
        ensureLoadLibrary();
    }
    
    protected void onResume(){
        super.onResume();
        ensureLoadLibrary();
    }
    
    protected void onStart(){
        super.onStart();
        ensureLoadLibrary();
    }
    
    protected void onStop(){
        super.onStop();
        ensureLoadLibrary();
    }
    
    protected void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        ensureLoadLibrary();
    }
    
    protected void onActivityResult(int requestCode,
                                        int resultCode,
                                        Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        ensureLoadLibrary();
    }

}
