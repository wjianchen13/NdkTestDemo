package com.example.ndkdemo.test2;

/**
 * @Author: ddup
 * @Date: 2024/6/27
 * @Description: java调C代码
 * https://article.juejin.cn/post/7395868215622696972
 */
public class TestJni2 {

    /**
     *
     * @param x
     * @param y
     * @return
     */
    public native int add(int x, int y);

    /**
     * 从java传入字符串，C代码进行拼接
     *
     * @param s I am from java
     * @return I am from java and I am from c
     */
    public native String sayHello(String s);

    /**
     * 让C代码给每个元素都加上10
     *
     * @param intArray
     * @return
     */
    public native int[] increaseArrayEles(int[] intArray);

    /**
     *
     * @param pwd
     * @return
     */
    public native int checkPwd(String pwd);
}
