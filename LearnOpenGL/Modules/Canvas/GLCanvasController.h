//
//  GLCanvasController.h
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/5.
//

#import <Foundation/Foundation.h>
#import "GLCanvas.h"
#include "GLRenderer.hpp"

NS_ASSUME_NONNULL_BEGIN

@interface GLCanvasController : NSObject

/// gl  canvas
@property (nonatomic, strong, readonly) GLCanvas *canvas;

@property (nonatomic) Renderer::GLRenderer *renderer;

- (void)initializeGL;

/// redraw
- (void)redrawCanvas;

@end

NS_ASSUME_NONNULL_END
