//
//  AppDelegate.m
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/5.
//

#import "AppDelegate.h"
#import "GLHomeViewController.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.appWindow = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    GLHomeViewController *rootViewController = [[GLHomeViewController alloc] init];
    UINavigationController *naviController = [[UINavigationController alloc] initWithRootViewController:rootViewController];
    self.appWindow.rootViewController = naviController;
    [self.appWindow makeKeyAndVisible];
    return YES;
}

@end
