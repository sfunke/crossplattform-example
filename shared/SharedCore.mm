//
// Created by Steffen Funke on 27.04.17.
// Copyright (c) 2017 Steffen Funke. All rights reserved.
//

#include "SharedCore.h"

const char* CPP_BASE_STRING = "cpp says hello world to %s";

const char* concatMyStringWithCppString(const char* myString) {
    char* concatenedString = new char[strlen(CPP_BASE_STRING) + strlen(myString)];
    sprintf(concatenedString, CPP_BASE_STRING, myString);
    return concatenedString;
}