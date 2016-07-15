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
import android.widget.RelativeLayout;
import android.widget.EditText;

import android.text.InputType;

import android.R;

import android.os.Looper;
import android.os.Handler;

import android.graphics.Canvas;
import android.graphics.*;

import android.util.Log;

public class Activity  extends android.app.NativeActivity  {

    private static final String TAG = "GHL";

    static native boolean nativeOnKey(int keycode,long unicode,long action);
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
        final Activity self = this;
        runOnUiThread(new Runnable(){
             //@override
             public void run() {
                

                if (m_text_edit == null) {
                    ViewGroup.LayoutParams params = new ViewGroup.LayoutParams(
                        ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT);
                    m_text_edit = new InvisibleEdit(Activity.this);
                    m_text_edit.setId(100500);
                    self.addContentView(m_text_edit,params);
                    m_text_edit.getViewTreeObserver().addOnGlobalLayoutListener(new android.view.ViewTreeObserver.OnGlobalLayoutListener() {
                        @Override 
                        public void onGlobalLayout() {
                            Rect r = new Rect();
                            m_text_edit.getWindowVisibleDisplayFrame(r);
                            final Rect fr = r;
                            runOnRenderThread(new Runnable() {
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
        });
    }

    public void hideSoftKeyboard() {
        runOnUiThread(new Runnable(){
             //@override
             public void run() {
                if (m_text_edit != null) {
                    InputMethodManager imm = (InputMethodManager)getSystemService(Context.INPUT_METHOD_SERVICE);
                    imm.hideSoftInputFromWindow(m_text_edit.getWindowToken(), 0);
                }
            }
        });
    }



    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        ensureLoadLibrary();
    }

    @Override
    protected void onDestroy(){
        super.onDestroy();
        ensureLoadLibrary();
    }

    @Override
    protected void onPause(){
        super.onPause();
        ensureLoadLibrary();
    }

    @Override
    protected void onResume(){
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
