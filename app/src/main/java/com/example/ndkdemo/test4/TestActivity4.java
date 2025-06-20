package com.example.ndkdemo.test4;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.example.ndkdemo.Nativelib1;
import com.example.ndkdemo.R;

/**
 * JNI的常用API
 */
public class TestActivity4 extends AppCompatActivity {

    private TextView tvTest;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_test4);
        tvTest = findViewById(R.id.tv_test);
    }

    /**
     * 获取当前 JNI 的版本号
     * @param v
     */
    public void onTest1(View v) {
        tvTest.setText(new TestJni4().getVersion() + "");
    }



}