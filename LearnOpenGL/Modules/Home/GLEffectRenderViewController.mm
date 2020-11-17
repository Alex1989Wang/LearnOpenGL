//
//  GLEffectRenderViewController.m
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/7.
//

#import "GLEffectRenderViewController.h"
#import "GLCanvasController.h"
#import "GLDisplayLink.h"
#include "GLRenderer.hpp"
#include "GLTriangleRenderer.hpp"
#include "GLRectangleRenderer.hpp"

@interface GLEffectRenderViewController ()<GLDisplayLinkDelegate>

@property (nonatomic, strong) GLCanvasController *canvasController;

@property (nonatomic) Renderer::GLRenderer *renderer;

@property (nonatomic, strong) GLDisplayLink *link;

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
    self.link = [[GLDisplayLink alloc] init];
    self.link.delegate = self;
    [self.link start];
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
        self.renderer = nullptr;
    }
}

#pragma mark - GLDisplayLink
- (void)displayLinkFired:(GLDisplayLink *)displayLink {
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
