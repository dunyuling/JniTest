#include <jni.h>
#include <android/log.h>

#define  LOG_TAG    "native-dev"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

JNIEXPORT void JNICALL Java_com_liux_example_jnitest_JniTest_sayHello
  (JNIEnv* env, jobject obj) {
  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, "Need to print : %d %s",1, "hello-jni");
  };


JNIEXPORT jstring Java_com_liux_example_jnitest_JniTest_stringFromJNI( JNIEnv* env,
                                                  jobject thiz ){


    return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled with ABI .");
}
