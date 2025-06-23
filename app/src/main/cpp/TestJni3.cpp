//
// Created by Administrator on 2025/5/22/周四.
//
//
// Created by ddup on 2024/6/27.
//
#include "com_example_ndkdemo_test3_TestJni3.h"
#include <stdlib.h>
#include <stdio.h>

#include <android/log.h>

#define TAG "ddup"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型


/**
 * 让C代码调用Java中JNI类的public int add(int x ,int y)
 */
extern "C"
void Java_com_example_ndkdemo_test3_TestJni3_callbackAdd(JNIEnv *env, jobject jobj) {
//1.得到字节码
//jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = (*env).FindClass("com/example/ndkdemo/test3/TestJni3");
//2.得到方法
//jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
//最后一个参数是方法签名
    jmethodID jmethodId = (*env).GetMethodID(jclazz, "add", "(II)I");
//3.实例化该类
    jobject jobject1 = (*env).AllocObject(jclazz);
//4.调用方法
//jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    jint value = (*env).CallIntMethod(jobject1, jmethodId, 99, 1);
//成功调用
    LOGE("value==%d\n", value);
};

/***
 * 让C代码调用
 * public void helloFromJava()
 */
extern "C"
void JNICALL Java_com_example_ndkdemo_test3_TestJni3_callbackHelloFromJava
(JNIEnv *env, jobject jobj) {
//1.得到字节码
//jclass      (*FindClass)(JNIEnv*, const char*);
jclass jclazz = (*env).FindClass("com/example/ndkdemo/test3/TestJni3");
//2.得到方法
//jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
//最后一个参数是方法签名
jmethodID jmethodIds = (*env).GetMethodID(jclazz, "helloFromJava", "()V");
//3.实例化该类
jobject jobject1 = (*env).AllocObject(jclazz);
//4.调用方法
//jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
(*env).CallVoidMethod(jobject1, jmethodIds);
};

/***
 * 让C代码调用
 * public void printString(String s)
 *
 */
extern "C"
void JNICALL Java_com_example_ndkdemo_test3_TestJni3_callbackPrintString
(JNIEnv *env, jobject jobj) {
//1.得到字节码
//jclass      (*FindClass)(JNIEnv*, const char*);
jclass jclazz = (*env).FindClass("com/example/ndkdemo/test3/TestJni3");
//2.得到方法
//jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
//最后一个参数是方法签名
jmethodID jmethodIds = (*env).GetMethodID(jclazz, "printString", "(Ljava/lang/String;)V");
//3.实例化该类
jobject jobject1 = (*env).AllocObject(jclazz);
//4.调用方法
//jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
// jstring     (*NewStringUTF)(JNIEnv*, const char*);
jstring jst = (*env).NewStringUTF("I am Android!");
(*env).CallVoidMethod(jobject1, jmethodIds, jst);
};

/**
 * 让C代码调用
 * public static void sayHello(String s)
 *
 */
extern "C"
void JNICALL Java_com_example_ndkdemo_test3_TestJni3_callbackSayHello
(JNIEnv *env, jobject jobj) {
//1.得到字节码
//jclass      (*FindClass)(JNIEnv*, const char*);
jclass jclazz = (*env).FindClass("com/example/ndkdemo/test3/TestJni3");
//2.得到方法
// jmethodID   (*GetStaticMethodID)(JNIEnv*, jclass, const char*, const char*);
//最后一个参数是方法签名
jmethodID jmethodIds = (*env).GetStaticMethodID(jclazz, "sayHello",
                                                 "(Ljava/lang/String;)V");
jstring jst = (*env).NewStringUTF("I am Android!");
(*env).CallStaticVoidMethod(jclazz, jmethodIds, jst);
};

