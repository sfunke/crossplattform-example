#include <jni.h>
#include <string>
#include "../../../../../shared/SharedCore.h"

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
