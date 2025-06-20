#include "com_example_ndkdemo_test4_TestJni4.h"
#include <stdlib.h>
#include <stdio.h>

#include <android/log.h>

#define TAG "TestJni4"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型


/**
 * 获取当前 JNI 的版本号
 */
extern "C"
jint Java_com_example_ndkdemo_test4_TestJni4_getVersion(JNIEnv *env, jobject obj) {
    LOGE("===========> TestJni4_getVersion env:%s", env);
    LOGE("===========> TestJni4_getVersion jobject:%s", obj);
    return env->GetVersion();
}

