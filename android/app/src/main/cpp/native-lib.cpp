#include <jni.h>
#include <string>
#include <opencv2/core/hal/interface.h>
#include <cstdlib>
#include <opencv2/core/mat.hpp>
#include "../../../../../shared/SharedCore.h"

extern "C" {
JNIEXPORT jstring JNICALL
Java_com_example_crossexample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */,
        jstring myString
) {

    const char *stringUTFChars = env->GetStringUTFChars(myString, 0);
    jstring newJString = env->NewStringUTF(concatMyStringWithCppString(stringUTFChars));

    return newJString;
}

JNIEXPORT void JNICALL
Java_com_example_crossexample_MainActivity_processFrame(JNIEnv *env, jobject instance,
                                                        jlong matAddrGray) {
    cv::Mat &mGr = *(cv::Mat *) matAddrGray;
    processImage(mGr);
}
}
