//
//  RouteMiddlewareProtocol.h
//  JumpRoute
//
//  Created by joker on 2017/7/21.
//  Copyright © 2017年 joker. All rights reserved.
//

#import <Foundation/Foundation.h>
@class RouteRequest;
@protocol RouteMiddleware <NSObject>

-(NSDictionary *)middlewareHandleRequestWith:(RouteRequest *__autoreleasing *)primitiveRequest error:(NSError *__autoreleasing *)error;

@end
