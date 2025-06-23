package com.example.ndkdemo.test3;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.example.ndkdemo.Nativelib1;
import com.example.ndkdemo.R;

/**
 * C调用Java
 */
public class TestActivity3 extends AppCompatActivity {

    private TextView tvTest;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_test3);
        tvTest = findViewById(R.id.tv_test);
    }

    public void onTest1(View v) {
        new TestJni3().callbackAdd();
    }

    public void onTest2(View v) {
        new TestJni3().callbackHelloFromJava();
    }

    public void onTest3(View v) {
        new TestJni3().callbackPrintString();
    }

    public void onTest4(View v) {
        new TestJni3().callbackSayHello();
    }

}