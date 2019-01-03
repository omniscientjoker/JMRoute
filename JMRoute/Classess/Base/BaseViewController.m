//
//  BaseViewController.m
//  JMRoute
//
//  Created by joker on 2017/7/25.
//  Copyright © 2017年 joker. All rights reserved.
//

#import "BaseViewController.h"

@interface BaseViewController ()

@end

@implementation BaseViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.route = ((AppDelegate *)[UIApplication sharedApplication].delegate).JMroute;
    [self.route addMiddleware:self];
}

-(NSDictionary *)middlewareHandleRequestWith:(RouteRequest *__autoreleasing *)primitiveRequest error:(NSError *__autoreleasing *)error{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [self.route removeMiddleware:self];
    });
    return nil;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}
@end
