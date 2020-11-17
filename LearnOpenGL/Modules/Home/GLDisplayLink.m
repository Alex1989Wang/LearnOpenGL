//
//  GLDisplayLink.m
//  LearnOpenGL
//
//  Created by JiangWang on 2020/11/17.
//

#import "GLDisplayLink.h"
#import <UIKit/UIKit.h>

@interface GLDisplayLink()
@property (nonatomic, strong) CADisplayLink *link;
@end

@implementation GLDisplayLink

- (void)start {
    if (!self.link) {
        self.link = [CADisplayLink displayLinkWithTarget:self selector:@selector(fired)];
        [self.link addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSRunLoopCommonModes];
    }
}

- (void)invalidate {
    if (self.link) {
        [self.link invalidate];
        self.link = nil;
    }
}

- (void)fired {
    if ([self.delegate respondsToSelector:@selector(displayLinkFired:)]) {
        [self.delegate displayLinkFired:self];
    }
}

@end
