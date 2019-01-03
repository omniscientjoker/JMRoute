//
//  BaseViewController.h
//  JMRoute
//
//  Created by joker on 2017/7/25.
//  Copyright © 2017年 joker. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JumpRoute/JumpRoute.h>
#import "AppDelegate.h"
@interface BaseViewController : UIViewController <RouteMiddleware>
@property(nonatomic,weak)Route * route;
@end
