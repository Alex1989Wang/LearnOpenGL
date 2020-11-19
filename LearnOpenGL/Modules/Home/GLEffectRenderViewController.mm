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
#include "GLTextureRenderer.hpp"

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
            case GLLearnCasesTexure: {
                NSString *vsPath = [self shaderPathWithFileName:@"TextureRenderer_frag.glsl"];
                NSString *fsPath = [self shaderPathWithFileName:@"TextureRenderer_vert.glsl"];
                const char *cStrVSPath = [vsPath cStringUsingEncoding:NSUTF8StringEncoding];
                const char *cStrFSPath = [fsPath cStringUsingEncoding:NSUTF8StringEncoding];
                Renderer::GLTextureRenderer *p_texture_renderer = new Renderer::GLTextureRenderer(cStrVSPath, cStrFSPath);
                NSString *imagePath = [[NSBundle mainBundle] pathForResource:@"container" ofType:@"jpg"];
                const char *cStringPath = [imagePath cStringUsingEncoding:NSUTF8StringEncoding];
                p_texture_renderer->setTextureImagePath(cStringPath);
                self.renderer = p_texture_renderer;
                break;
            }
            default:
                break;
        }
    }
    self.canvasController.renderer = self.renderer;
}

- (NSString *)shaderPathWithFileName:(NSString *)name {
    NSString *bundlePath = [[NSBundle mainBundle] pathForResource:@"Shaders" ofType:@"bundle"];
    return [NSString stringWithFormat:@"%@/%@", bundlePath, name];;
}

@end
