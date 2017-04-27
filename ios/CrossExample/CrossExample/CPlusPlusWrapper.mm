//
//  CPlusPlusWrapper.m
//  CrossExample
//
//  Created by Steffen Funke on 27.04.17.
//  Copyright © 2017 Steffen Funke. All rights reserved.
//

#import "CPlusPlusWrapper.h"
#import "SharedCore.h"

@implementation CPlusPlusWrapper
+ (NSString *)getCppString:(NSString *)myString {

    const char *cppString = concatMyStringWithCppString([myString UTF8String]);

    return [NSString stringWithUTF8String:cppString];
}
@end
