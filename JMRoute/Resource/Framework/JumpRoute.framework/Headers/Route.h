//
//  Route.h
//  JumpRoute
//
//  Created by joker on 2017/7/21.
//  Copyright © 2017年 joker. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RouteMiddlewareProtocol.h"
@class RouteRequest;
@class RouteHandle;

@interface Route : NSObject
-(void)registerRouteList;
/**
 注册一个route表达式
 */
-(void)registerBlock:(RouteRequest *(^)(RouteRequest * request))routeHandlerBlock forRoute:(NSString *)route;
-(void)registerHandler:(RouteHandle *)handler forRoute:(NSString *)route;
-(void)setObject:(id)obj forKeyedSubscript:(NSString *)key;
-(id)objectForKeyedSubscript:(NSString *)key;

/**
 检测url是否能够被处理
 */
-(BOOL)canHandleWithURL:(NSURL *)url;


/**
 处理url请求
 */
-(BOOL)handleURL:(NSURL *)URL primitiveParameters:(NSDictionary *)primitiveParameters targetCallBack:(void(^)(NSError *, id responseObject))targetCallBack withCompletionBlock:(void(^)(BOOL handled, NSError *error))completionBlock;

-(void)addMiddleware:(id<RouteMiddleware>)middleware;
-(void)removeMiddleware:(id<RouteMiddleware>)middleware;

@end
