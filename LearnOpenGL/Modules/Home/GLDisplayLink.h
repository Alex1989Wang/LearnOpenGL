//
//  GLDisplayLink.h
//  LearnOpenGL
//
//  Created by JiangWang on 2020/11/17.
//

#import <Foundation/Foundation.h>

@class GLDisplayLink;

NS_ASSUME_NONNULL_BEGIN

@protocol GLDisplayLinkDelegate <NSObject>

- (void)displayLinkFired:(GLDisplayLink *)displayLink;

@end

@interface GLDisplayLink : NSObject

@property (nonatomic, weak) id<GLDisplayLinkDelegate> delegate;

- (void)start;

- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
