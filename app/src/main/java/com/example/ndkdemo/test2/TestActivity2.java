package com.example.ndkdemo.test2;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.example.ndkdemo.Nativelib1;
import com.example.ndkdemo.R;

/**
 * Java调用C
 */
public class TestActivity2 extends AppCompatActivity {

    private TextView tvTest;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_test2);
        tvTest = findViewById(R.id.tv_test);
    }

    /**
     * 加法
     * @param v
     */
    public void onTest1(View v) {
        tvTest.setText(new TestJni2().add(1, 2) + "");
    }

    /**
     *
     * @param v
     */
    public void onTest2(View v) {
        tvTest.setText(new TestJni2().sayHello("test2"));
    }

    /**
     *
     * @param v
     */
    public void onTest3(View v) {
        int[] test3 = new int[]{1, 2, 3, 4, 5};
        tvTest.setText(new TestJni2().increaseArrayEles(test3).toString());
    }

    /**
     * test4
     * @param v
     */
    public void onTest4(View v) {
        tvTest.setText(new TestJni2().checkPwd("test") + "");
    }


}