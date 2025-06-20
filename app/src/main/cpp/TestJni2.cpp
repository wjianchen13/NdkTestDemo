//
// Created by ddup on 2024/6/27.
//
#include "com_example_ndkdemo_test2_TestJni2.h"
#include "string.h"
#include <stdlib.h>

#include <android/log.h>

#define TAG "ddup"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型
extern "C"
JNIEXPORT char *JNICALL
Java_com_example_MyClass_myMethod(JNIEnv
                                  *env,
                                  jobject obj, jstring jstr) {
    const char *cstr = (*env).GetStringUTFChars(jstr,
                                                JNI_FALSE);// 使用 cstr 进行操作，并获取结果（假设结果为 result）

    (*env).ReleaseStringUTFChars(jstr, cstr);

    char *result = (char *) malloc(strlen(cstr) + 1);
    strcpy(result, cstr);

    return result;
}

/**
 * jint:返回值
 * Java_全类名_方法名
 * JNIEnv *env
 */
extern "C"
jint Java_com_example_ndkdemo_test2_TestJni2_add
        (JNIEnv *env, jobject jobj, jint ji, jint jj) {
    int result = ji + jj;
    return result;
};

/**

     * 从java传入字符串，C代码进行拼接
     *
     * @param s I am from java
     * @return I am from java and I am from c
*/
extern "C"
jstring Java_com_example_ndkdemo_test2_TestJni2_sayHello
        (JNIEnv *env, jobject jobj, jstring jstring1) {
    LOGE("fromJava1==%s\n", "");
    char *fromJava = Java_com_example_MyClass_myMethod(env, jobj, jstring1);
    LOGE("fromJava2==%s\n", fromJava);
    char *fromC = " and I am from C";
    //拼接函数，拼接后得到的结果放到第一个参数里面
    strcat(fromJava, fromC);//把拼接的结果放在第一个参数里面
    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    LOGE("fromJava3==%s\n", fromJava);
    return (*env).NewStringUTF(fromJava);
};

/**
 * 给每个元素加10
 * 场景：图片处理，颜色矩阵(就是数组)，进行数组的处理
 */
extern "C"
jintArray Java_com_example_ndkdemo_test2_TestJni2_increaseArrayEles
        (JNIEnv *env, jobject jobj, jintArray jintArray1) {
    //1.得到数组的长度
    //jsize       (*GetArrayLength)(JNIEnv*, jarray);
    jsize size = (*env).GetArrayLength(jintArray1);
    //2.得到数组的元素
    // jint*       (*GetIntArrayElements)(JNIEnv*, jintArray, jboolean*);
    jint *intArray = (*env).GetIntArrayElements(jintArray1,
                                                 JNI_FALSE);//这里传0 false表示 在同一份内存操作，不开辟新的内存
    //3.遍历数组，给每个元素加10
    int i;
    for (i = 0; i < size; i++) {
        *(intArray + i) += 10;
    }
    //4. 同步修改到 Java 层
    (*env).ReleaseIntArrayElements(jintArray1, intArray, 0);
    //5.返回结果
    return jintArray1;
};

/**
 * 应用：检查密码是否正确，如果正确返回200，否则返回400
 */
extern "C"
jint Java_com_example_ndkdemo_test2_TestJni2_checkPwd
        (JNIEnv *env, jobject jobj, jstring jstring1) {
    //假设服务器的密码是123456
    char *origin = "123456";
    char *fromUser = Java_com_example_MyClass_myMethod(env, jobj, jstring1);
    //函数比较字符串是否相同
    int code = strcmp(origin, fromUser);
    LOGE("code==%d\n", code);
    if (code == 0) {
        return 200;
    } else {
        return 400;
    }
};

