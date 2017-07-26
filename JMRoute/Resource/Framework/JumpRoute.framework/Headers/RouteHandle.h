//
//  RouteHandle.h
//  JumpRoute
//
//  Created by joker on 2017/7/21.
//  Copyright © 2017年 joker. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class RouteRequest;



@interface RouteHandle : NSObject

-(BOOL)shouldHandleWithRequest:(RouteRequest *)request;

-(UIViewController *)targetViewControllerWithRequest:(RouteRequest *)request;
-(UIViewController *)sourceViewControllerForTransitionWithRequest:(RouteRequest *)request;

-(BOOL)handleRequest:(RouteRequest *)request error:(NSError *__autoreleasing *)error;
-(BOOL)transitionWithWithRequest:(RouteRequest *)request sourceViewController:(UIViewController *)sourceViewController targetViewController:(UIViewController *)targetViewController isPreferModal:(BOOL)isPreferModal error:(NSError *__autoreleasing *)error;
- (BOOL)preferModalPresentationWithRequest:(RouteRequest *)request;


@end
