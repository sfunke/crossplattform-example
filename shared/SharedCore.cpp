//
// Created by Steffen Funke on 27.04.17.
// Copyright (c) 2017 Steffen Funke. All rights reserved.
//

#include "SharedCore.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

const char* CPP_BASE_STRING = "CPP says hello world to %s";

using namespace std;

string mat2str(cv::Mat &mat) {
    int type = mat.type();
    string r = "Type: ";

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch ( depth ) {
        case CV_8U:  r += "8U"; break;
        case CV_8S:  r += "8S"; break;
        case CV_16U: r += "16U"; break;
        case CV_16S: r += "16S"; break;
        case CV_32S: r += "32S"; break;
        case CV_32F: r += "32F"; break;
        case CV_64F: r += "64F"; break;
        default:     r += "User"; break;
    }

    r += " | Channels: ";
    r += (chans+'0');
    r += " | ";
    r += to_string(mat.cols);
    r += "x";
    r += to_string(mat.rows);

    return r.c_str();
}


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

    cout << mat2str(image) << endl;
    cv::Mat sub;
    cv::cvtColor(image, sub, cv::COLOR_BGRA2GRAY);
    cv::GaussianBlur(sub, sub, cv::Size(7, 7), 1.5, 1.5);
    cv::Canny(sub, sub, 0, 30, 3);
    cv::cvtColor(sub, sub, cv::COLOR_GRAY2BGRA);
    sub.copyTo(image);
}