# JniTest
开始学习jni的入门项目，操作流程如下  

1.编写接口java 文件  

package com.liux.example.jnitest;
public class JniTest {  
      public native static void sayHello();  
      public native static String  stringFromJNI();  
}  


2.根据该文件生成相应的.h文件（com_liux_example_jnitest_JniTest.h），命令如下:  
javah -cp app/build/intermediates/classes/debug/  -d jni com.liux.example.jnitest.JniTest  
注意:
如果是用得Activity作为含有native方法的接口类：需要包含相应的支持包:  
javah -cp ~/Android/Sdk/extras/android/support/v7/appcompat/libs/android-support-v7-appcompat.jar:
  ~/Android/Sdk/extras/android/support/v4/android-support-v4.jar:~/Android/Sdk/platforms/android-23/android.jar:
  ~/android_workspace/JniTest/app/build/intermediates/classes/debug/  -d jni com.liux.example.jnitest.HelloJni  
(windows分割方式为';',linux下为':')  

3.编辑.c文件（hello-jni.c），内容如下:  
\#include \<jni.h\>  
\#include \<android/log.h\>  

\#define  LOG_TAG    "native-dev"  
\#define  LOGI(...)  \__android_log_print(ANDROID_LOG_INFO, LOG_TAG, \__VA_ARGS__)  

JNIEXPORT void JNICALL Java_com_liux_example_jnitest_JniTest_sayHello(JNIEnv* env, jobject obj)  
{  
  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "Need to print : %d %s",1, "hello-jni");  
};  

JNIEXPORT jstring Java_com_liux_example_jnitest_JniTest_stringFromJNI( JNIEnv* env,jobject thiz ){  
      return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled with ABI .");  
}  

4.编辑Android.mk，内容如下:  
LOCAL_PATH := $(call my-dir)  
include $(CLEAR_VARS)  
LOCAL_MODULE    := hello-jni  
LOCAL_SRC_FILES := hello-jni.c  
LOCAL_LDLIBS    := -lm -llog  
include $(BUILD_SHARED_LIBRARY)  

5.编辑Application.mk，内容如下：  
APP_ABI := all

6.生成.so  
 ~/download/android-ndk-r10e/ndk-build  

7.把生成的libs文件夹拷贝到app下  
8.运行程序  
