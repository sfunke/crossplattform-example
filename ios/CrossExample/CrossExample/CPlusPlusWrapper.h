//
//  CPlusPlusWrapper.h
//  CrossExample
//
//  Created by Steffen Funke on 27.04.17.
//  Copyright © 2017 Steffen Funke. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CPlusPlusWrapper : NSObject
+ (NSString *)getCppString:(NSString *)myString;
- (id) initWithImageView:(UIImageView *)imageView;
- (void)start;
@end
