#include <jni.h>
#include <string>
#include "../../../../../shared/SharedCore.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_crossexample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */,
        jstring myString
) {

    const char *stringUTFChars = env->GetStringUTFChars(myString, 0);
    jstring newJString = env->NewStringUTF(concatMyStringWithCppString(stringUTFChars));

    return newJString;
}
