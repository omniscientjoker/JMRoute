//
//  AppDelegate.m
//  JMRoute
//
//  Created by joker on 2017/7/14.
//  Copyright © 2017年 joker. All rights reserved.
//

#import "AppDelegate.h"
#import <JumpRoute/Route.h>
#import <JumpRoute/RouteHandle.h>
#import "RootViewController.h"
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    self.JMroute = [[Route alloc]init];
    [self.JMroute registerHandler:[[RouteHandle alloc] init] forRoute:@"JMRoute://com.JM1028.JMRoute/chat/ChatViewController"];
    [self.JMroute registerHandler:[[RouteHandle alloc] init] forRoute:@"JMRoute://com.JM1028.JMRoute/mail/MailViewController"];
    
    self.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    self.window.rootViewController = [[UINavigationController alloc] initWithRootViewController:[[RootViewController alloc] init]];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    return YES;
    
}


- (void)applicationWillResignActive:(UIApplication *)application {
    
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    
}

- (void)applicationWillTerminate:(UIApplication *)application {
    
}
@end
