//
//  DefineConfig.h
//  JMRoute
//
//  Created by joker on 2017/8/15.
//  Copyright © 2017年 joker. All rights reserved.
//

#ifndef DefineConfig_h
#define DefineConfig_h


#define JM_SCREEN                  [UIScreen mainScreen].bounds
#define JM_SCREEN_HEIGHT           [UIScreen mainScreen].bounds.size.height
#define JM_SCREEN_WIDTH            [UIScreen mainScreen].bounds.size.width
#define JM_STATUSBAR_HEIGHT        [[UIApplication sharedApplication] statusBarFrame].size.height

//RGB颜色
#define kColorWithRGB(rgbValue) \[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 \green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 \blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:1.0]
#define kColorRGB(r,g,b) [UIColor colorWithRed: (r/255.0) green:(g/255.0) blue:(b/255.0) alpha:1.0]

//字符串数组判断
#define IsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]))
#define IsStrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref)isEqualToString:@""]))
#define IsArrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref) count] == 0))

//定义keyWindow宏
#define KEYWINDOWS [UIApplication sharedApplication].keyWindow
//定义rootViewController宏
#define ROOTVIEWCONTROLLER [UIApplication sharedApplication].keyWindow.rootViewController
//定义最顶层的DISPLAYVIEWCONTROLLER，如果是present出来的Viewcontroller，windows栈中展示给用户看的rootviewcontroller
#define DISPLAYVIEWCONTROLLER ((UIWindow *)[[UIApplication sharedApplication].windows lastObject]).rootViewController

///线程执行方法 GCD
#define PERFORMSEL_BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define PERFORMSEL_SYNC_BACK(block) dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define PERFORMSEL_MAIN(block) dispatch_async(dispatch_get_main_queue(),block)

//图片
#define BundleImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer]]
#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle]pathForResource:file ofType:ext]]
#define IMAGE(A) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:A ofType:nil]]

typedef void (^VoidBlock) (void);
static inline void  mainBlock(VoidBlock block){
    dispatch_async(dispatch_get_main_queue(), ^{
        block();
    });
}
static inline void  asynchronousBlock(VoidBlock block){
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        block();
    });
}
#endif /* DefineConfig_h */
