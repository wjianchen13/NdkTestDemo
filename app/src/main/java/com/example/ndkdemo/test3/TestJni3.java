package com.example.ndkdemo.test3;


import android.util.Log;

/**
 * @Author: ddup
 * @Date: 2024/6/27
 * @Description: C代码调用Java代码
 * https://article.juejin.cn/post/7395868215622696972
 */
public class TestJni3 {

    //public int add(int x, int y)
    public native void callbackAdd();

    /**
     * public void helloFromJava()
     */
    public native void callbackHelloFromJava();

    /**
     * public void printString(String s)
     */
    public native void callbackPrintString();

    /**
     * public static void sayHello(String s)
     */
    public native void callbackSayHello();

    public int add(int x, int y) {
        Log.e("ddup", "add()  x=" + x + " y=" + y);
        return x + y;
    }

    public void helloFromJava() {
        Log.e("ddup", "helloFromJava");
    }

    public void printString(String s) {
        Log.e("ddup", "C中输入的：" + s);
    }

    public static void sayHello(String s) {
        Log.e("ddup", "我是java代码中的JNI" +
                ".java中的sayHello(String s)静态方法,我被C调用了：" + s);
    }
}