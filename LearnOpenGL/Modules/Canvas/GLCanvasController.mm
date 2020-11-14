//
//  GLCanvasController.m
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/5.
//

#import "GLCanvasController.h"

@interface GLCanvasController()
@property (nonatomic, assign) BOOL initialized;
@property (nonatomic, assign) NSInteger modifications;
@end

@implementation GLCanvasController
@synthesize canvas = _canvas;

- (instancetype)init {
    self = [super init];
    if (self) {
        _modifications = 0;
    }
    return self;
}

#pragma mark Public
- (void)initializeGL {
    if (self.initialized) { return; }
    [self canvas];
    [EAGLContext setCurrentContext:self.canvas.context];
    self.initialized = YES;
}

- (void)redrawCanvas {
    self.modifications++;
}

#pragma mark Accessors
- (GLCanvas *)canvas {
    if (!_canvas) {
        EAGLContext *context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
        CGFloat dimension = [UIScreen mainScreen].bounds.size.width;
        CGRect canvasRect = CGRectMake(0, 0, dimension, dimension);
        _canvas = [[GLCanvas alloc] initWithFrame:canvasRect context:context];
        _canvas.backgroundColor = [UIColor systemGrayColor];
        _canvas.enableSetNeedsDisplay = YES;
    }
    return _canvas;
}

- (void)setModifications:(NSInteger)modifications {
    _modifications = modifications;
    if (modifications > 0) {
        [self.canvas setNeedsDisplay];
        _modifications--;
    }
    if (self.renderer) {
        self.renderer->render();
    }
}

@end
