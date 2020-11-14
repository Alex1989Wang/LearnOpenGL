//
//  GLEffectRenderViewController.m
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/7.
//

#import "GLEffectRenderViewController.h"
#import "GLCanvasController.h"
#include "GLRenderer.hpp"
#include "GLTriangleRenderer.hpp"
#include "GLRectangleRenderer.hpp"

@interface GLEffectRenderViewController ()

@property (nonatomic, strong) GLCanvasController *canvasController;

@property (nonatomic) Renderer::GLRenderer *renderer;

@property (nonatomic, strong) CADisplayLink *link;

@end

@implementation GLEffectRenderViewController

- (instancetype)initWithCoder:(NSCoder *)coder {
    NSAssert(NO, @"not implemented");
    return [self initWithType:GLLearnCasesTriangle];
}

- (instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    return [self initWithType:GLLearnCasesTriangle];
}

- (instancetype)initWithType:(GLLearnCases)type {
    self = [super initWithNibName:nil bundle:nil];
    if (self) {
        _glcase = type;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.canvasController = [[GLCanvasController alloc] init];
    [self.canvasController initializeGL];
    CGFloat dimension = self.view.bounds.size.width;
    self.canvasController.canvas.frame = CGRectMake(0, 0, dimension, dimension);
    [self.view addSubview:self.canvasController.canvas];
    
    // make render
    [self makeRenderer];
    
    // render
    self.link = [CADisplayLink displayLinkWithTarget:self selector:@selector(renderDisplay)];
    [self.link addToRunLoop:[NSRunLoop mainRunLoop] forMode:NSRunLoopCommonModes];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
}

- (void)dealloc {
    if (self.link) {
        [self.link invalidate];
        self.link = nil;
    }
    if (self.renderer) {
        delete self.renderer;
    }
}

#pragma mark Actions
- (void)renderDisplay {
    [self.canvasController redrawCanvas];
}

#pragma mark Private
- (void)makeRenderer {
    if (!self.renderer) {
        switch (self.glcase) {
            case GLLearnCasesTriangle: {
                self.renderer = new Renderer::GLTriangleRenderer();
                break;
            }
            case GLLearnCasesRectangle: {
                self.renderer = new Renderer::GLRectangleRenderer();
                break;
            }
            default:
                break;
        }
    }
    self.canvasController.renderer = self.renderer;
}

@end
