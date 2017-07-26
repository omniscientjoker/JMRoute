//
//  RootViewController.m
//  Mail&IMTest
//
//  Created by joker on 16/10/10.
//  Copyright © 2016年 joker. All rights reserved.
//

#import "RootViewController.h"

#import <JumpRoute/JumpRoute.h>
#import "AppDelegate.h"
@interface RootViewController ()<RouteMiddleware>
@property(nonatomic,weak)Route * route;
@end

@implementation RootViewController

- (void)viewDidLoad{
    [super viewDidLoad];
    self.route = ((AppDelegate *)[UIApplication sharedApplication].delegate).JMroute;
    [self.route addMiddleware:self];
    
    UIButton * btn = [UIButton new];
    btn.frame = CGRectMake(50, 100, 200, 40);
    btn.backgroundColor = [UIColor blueColor];
    [btn setTitle:@"mail" forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(clickBtnDown:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
    
    UIButton * btn2 = [UIButton new];
    btn2.frame = CGRectMake(50, 300, 200, 40);
    btn2.backgroundColor = [UIColor orangeColor];
    [btn2 setTitle:@"chat" forState:UIControlStateNormal];
    [btn2 addTarget:self action:@selector(clickBtnDown2:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn2];
    
    
    
}

-(void)clickBtnDown:(id)sender{
    [self.route handleURL:[NSURL URLWithString:@"JMRoute://com.JM1028.JMRoute/mail/&user=100&passw=009"] primitiveParameters:@{@"user":@"Neo~🙃🙃"} targetCallBack:^(NSError *error, id responseObject) {
        NSLog(@"UserCallBack");
    } withCompletionBlock:^(BOOL handled, NSError *error) {
        NSLog(@"UserHandleCompletion");
    }];
    
}
-(void)clickBtnDown2:(id)sender{
    [self.route handleURL:[NSURL URLWithString:@"JMRoute://com.JM1028.JMRoute/chat/ChatViewController"] primitiveParameters:@{@"user":@"Neo~🙃🙃"} targetCallBack:^(NSError *error, id responseObject) {
        NSLog(@"UserCallBack");
    } withCompletionBlock:^(BOOL handled, NSError *error) {
        NSLog(@"UserHandleCompletion");
    }];
    
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
