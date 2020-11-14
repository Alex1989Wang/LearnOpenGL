//
//  GLEffectRenderViewController.h
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/7.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, GLLearnCases) {
    GLLearnCasesTriangle,
    GLLearnCasesRectangle,
    
    /// the count of cases
    GLLearnCasesCount,
};

@interface GLEffectRenderViewController : UIViewController

@property (nonatomic, assign) GLLearnCases glcase;

- (instancetype)initWithType:(GLLearnCases)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
