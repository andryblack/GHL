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
import android.text.InputFilter;

import android.R;

import android.os.Looper;
import android.os.Handler;

import android.graphics.*;

import android.media.AudioManager;

import com.GHL.Log;
import android.widget.TextView;

import com.GHL.SystemFont;

public class Activity  extends android.app.NativeActivity  {

    private static final String TAG = "GHL";

    static native boolean nativeOnKey(long instance,int keycode,long unicode,long action);
    static native void nativeOnKeyboardHide(long instance);
    static native void nativeOnTextInputDismiss(long instance);
    static native void nativeOnTextInputAccepted(long instance,String text);
    static native void nativeOnTextInputChanged(long instance,String text,int cursor_position);

    static native void nativeOnScreenRectChanged(long instance,int left, int top, int width, int height);
    static native boolean nativeOnIntent(long instance,Intent i);

    private long m_instance = 0;

    

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
                showTextEditImpl(null,0);
            }
        });
        return true;
    }

    public void showTextEdit(String text,int cursor_position) {
        Log.v(TAG, "showTextEdit");
        final String text_f = text;
        final int cursor_position_f = cursor_position;
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                showTextEditImpl(text_f,cursor_position_f);
            }
        });
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


    public void showTextInput(int accept_button,
                                String placeholder,
                                int max_length) {
        Log.v(TAG, "showTextInput");
        final int accept_button_f = accept_button;
        final String placeholder_f = placeholder;
        final int max_length_f = max_length;
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                showTextInputImpl(accept_button_f,placeholder_f,max_length_f);
            }
        });
    }



    private void showTextInputImpl(int accept_button,
        String placeholder,
        int max_length) {
        
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
                                nativeOnTextInputAccepted(m_instance,text);
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
                            nativeOnTextInputDismiss(m_instance);
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
            text_input.setTextIsSelectable(true);
            text_input.setImeOptions(accept_button);
            text_input.setText("");
            if (max_length != 0) {
                text_input.setFilters(new InputFilter[] { new InputFilter.LengthFilter(max_length) });
            } else {
                text_input.setFilters(new InputFilter[] { });
            }
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


    private void showTextEditImpl(
        String text,
        int cursor_position) {
        boolean create = false;

        if (m_text_edit_window == null) {
            Log.v(TAG, "create text_edit");
            create = true;

            LinearLayout containerLayout = new LinearLayout(this);


            InvisibleEdit et = new InvisibleEdit(this,m_instance);

            et.setTag("text_edit");
            et.setGravity(Gravity.BOTTOM);
            et.setBackgroundDrawable(new ColorDrawable(Color.TRANSPARENT));
            et.setImeOptions(EditorInfo.IME_ACTION_DONE);
            et.setOnEditorActionListener(new TextView.OnEditorActionListener() {
                @Override
                public boolean onEditorAction(TextView textView, int i, KeyEvent keyEvent) {
                    Log.d(TAG,"onEditorAction: " + i);
                    if (i == EditorInfo.IME_ACTION_DONE ) {
                        runOnUiThread( new Runnable() {
                            @Override
                            public void run() {
                                nativeOnKey(m_instance,KeyEvent.KEYCODE_ENTER,0,0);
                                nativeOnKey(m_instance,KeyEvent.KEYCODE_ENTER,0,1);
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
                            nativeOnScreenRectChanged(m_instance,0,0,
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

        final InvisibleEdit text_edit = (InvisibleEdit)(m_text_edit_window.getContentView()).findViewWithTag("text_edit");
        if (text_edit != null) {
            Log.v(TAG,"Activate edit input");
            if (text != null) {
                Log.i(TAG,"Activate text edit mode");
                text_edit.setTextMode(text,cursor_position);
            } else {
                text_edit.setKeyMode();
            }
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
        try {
            Log.i(TAG,"open URL: " + url);
            startActivity(new Intent(Intent.ACTION_VIEW, android.net.Uri.parse(url)));
        } catch (Exception e) {
            return false;
        } 
        return true;
    }

    public void setInstance(long inst) {
        m_instance = inst;
        Log.v(TAG, "setInstance: " + inst);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState){
        ensureLoadLibrary();
        Log.v(TAG, "onCreate");
        super.onCreate(savedInstanceState);

        //Hide toolbar
        int SDK_INT = android.os.Build.VERSION.SDK_INT;
        if(SDK_INT >= 19)
        {
            setImmersiveSticky();

            View decorView = getWindow().getDecorView();
            decorView.setOnSystemUiVisibilityChangeListener
                    (new View.OnSystemUiVisibilityChangeListener() {
                @Override
                public void onSystemUiVisibilityChange(int visibility) {
                    setImmersiveSticky();
                }
            });
        }
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
        hideSoftKeyboard();
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
                if (nativeOnIntent(m_instance,i)) {
                    i.putExtra("com.GHL.intent_handled",true);
                }
            } else {
                Log.v(TAG, "processed intent " + i.toString());
            }
        }

        //Hide toolbar
        hideToolbar();
        hideSoftKeyboard();
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

    protected void setImmersiveSticky() {
        View decorView = getWindow().getDecorView();
        decorView.setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN
                | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_LAYOUT_STABLE);
    }
    protected void hideToolbar() {
        int SDK_INT = android.os.Build.VERSION.SDK_INT;
        if(SDK_INT >= 11 && SDK_INT < 14)
        {
            getWindow().getDecorView().setSystemUiVisibility(View.STATUS_BAR_HIDDEN);
        }
        else if(SDK_INT >= 14 && SDK_INT < 19)
        {
            getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN );
        }
        else if(SDK_INT >= 19)
        {
            setImmersiveSticky();
        }
    }

    public SystemFont createSystemFont() {
        return new SystemFont();
    }
}
