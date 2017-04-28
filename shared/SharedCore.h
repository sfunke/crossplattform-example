//
// Created by Steffen Funke on 27.04.17.
// Copyright (c) 2017 Steffen Funke. All rights reserved.
//

#ifndef CROSSEXAMPLE_SHAREDCORE_H
#define CROSSEXAMPLE_SHAREDCORE_H

#include <iostream>
#include <opencv2/core/mat.hpp>

/**
 * Example Code taken from here:
 * http://stackoverflow.com/a/18334548/1128600
 * https://github.com/ademar111190/CppAndroidIosExample
 *
 * Dummy function called from iOS or Android
 * @param myString is passed in from iOS or Android
 * @return an concatenated String
 */
const char* concatMyStringWithCppString(const char* myString);
void processImage(cv::Mat &image);
#endif //CROSSEXAMPLE_SHAREDCORE_H
