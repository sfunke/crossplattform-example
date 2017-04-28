//
// Created by Steffen Funke on 27.04.17.
// Copyright (c) 2017 Steffen Funke. All rights reserved.
//

#include "SharedCore.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

const char* CPP_BASE_STRING = "CPP says hello world to %s";

const char* concatMyStringWithCppString(const char* myString) {
    CV_VERSION;
    char* concatenedString = new char[strlen(CPP_BASE_STRING) + strlen(myString)];
    sprintf(concatenedString, CPP_BASE_STRING, myString);
    return concatenedString;
}

void processImage(cv::Mat &image) {
    for (int k = 0; k < 2000; k++) {
        int i = rand() % image.cols;
        int j = rand() % image.rows;
        image.at<uchar>(j, i) = 255;
    }
}