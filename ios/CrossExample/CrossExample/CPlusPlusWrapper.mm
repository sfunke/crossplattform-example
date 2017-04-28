//
//  CPlusPlusWrapper.m
//  CrossExample
//
//  Created by Steffen Funke on 27.04.17.
//  Copyright © 2017 Steffen Funke. All rights reserved.
//

#import "CPlusPlusWrapper.h"
#import "SharedCore.h"
#import <opencv2/videoio/cap_ios.h>

// Class extension to adopt the delegate protocol
@interface CPlusPlusWrapper () <CvVideoCameraDelegate> {
}
@end

@implementation CPlusPlusWrapper{
    CvVideoCamera *videoCamera;
    UIImageView *previewImageView;
}
+ (NSString *)getCppString:(NSString *)myString {

    const char *cppString = concatMyStringWithCppString([myString UTF8String]);

    return [NSString stringWithUTF8String:cppString];
}

- (id)initWithImageView:(UIImageView *)imageView {

    videoCamera = [[CvVideoCamera alloc] initWithParentView:imageView];
    //videoCamera = [[CvVideoCamera alloc] init];
    videoCamera.defaultAVCaptureDevicePosition = AVCaptureDevicePositionBack;
    videoCamera.defaultAVCaptureSessionPreset = AVCaptureSessionPresetHigh;
    videoCamera.defaultAVCaptureVideoOrientation = AVCaptureVideoOrientationPortrait;
    videoCamera.defaultFPS = 20;
    //videoCamera.rotateVideo = true;
    //videoCamera.useAVCaptureVideoPreviewLayer = YES;

    // ... set up the camera
    videoCamera.delegate = self;
    return self;
}

- (void)start {
    [videoCamera start];
}


#pragma mark CvVideoCameraDelegate
- (void)processImage:(cv::Mat &)image {
    processImage(image);
}

@end
