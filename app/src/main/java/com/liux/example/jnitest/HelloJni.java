package com.liux.example.jnitest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.liux.example.jnitest.R;

public class HelloJni extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);

//        JniTest.sayHello();

        TextView tv = new TextView(this);
        tv.setText( JniTest.stringFromJNI() );
        setContentView(tv);

        JniTest.sayHello();
    }

    static {
        System.loadLibrary("hello-jni");
    }
}
