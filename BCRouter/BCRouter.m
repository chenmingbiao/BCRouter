//
//  BCRouter.m
//  BCRouterExample
//
//  Created by billchan on 7/28/16.
//  Copyright © 2016 cmb. All rights reserved.
//

#import "BCRouter.h"
#import "BCWebViewController.m"
#import <objc/runtime.h>
#import <UIKit/UIKit.h>

@interface BCRouter()

@property (nonatomic, strong) NSMutableDictionary *urlConfig;

@end

@implementation BCRouter

+ (instancetype)sharedRouter
{
    static BCRouter *_sharedRouter = nil;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        _sharedRouter = [[self alloc] init];
    });
    return _sharedRouter;
}

+ (NSMutableDictionary *)config
{
    static NSMutableDictionary *config;
    if (nil == config) {
        config = [[NSMutableDictionary alloc] init];
    }
    
    return config;
}

- (UIViewController *)viewControllerForURL:(NSURL *)url withQuery:(NSDictionary *)query
{
    UIViewController *viewController = nil;
    NSString *host = url.host;
    NSString *home = [NSString stringWithFormat:@"%@://%@", url.scheme, url.host];
    
    if ([self URLAvailable:url]) {
        if ([[_urlConfig objectForKey:home] isKindOfClass:[UIViewController class]]) {
            viewController = (UIViewController *)[_urlConfig objectForKey:home];
        }
        else if ([[_urlConfig objectForKey:host] isKindOfClass:[UIViewController class]]) {
            viewController = (UIViewController *)[_urlConfig objectForKey:host];
        }
        else if (nil == query) {
            Class class;
            if ([_urlConfig.allKeys containsObject:home]) {
                class = NSClassFromString([_urlConfig objectForKey:host]);
            }
            else if ([_urlConfig.allKeys containsObject:host]) {
                class = NSClassFromString([_urlConfig objectForKey:host]);
            }
            viewController = (UIViewController *)[[class alloc] initWithURL:url];
        }
        else {
            Class class;
            if ([_urlConfig.allKeys containsObject:home]) {
                class = NSClassFromString([_urlConfig objectForKey:home]);
            }
            else if ([_urlConfig.allKeys containsObject:host]) {
                class = NSClassFromString([_urlConfig objectForKey:host]);
            }
            viewController = (UIViewController *)[[class alloc] initWithURL:url query:query];
        }
    }
    else if ([@"http" isEqualToString:[url scheme]]) {
        viewController = (UIViewController *)[[BCWebViewController alloc] initWithURL:url
                                                                                query:query];

    }
    
    return viewController;
}

- (BOOL)URLAvailable:(NSURL *)url
{
    return [_urlConfig.allKeys containsObject:url.host]
    || [_urlConfig.allKeys containsObject:[NSString stringWithFormat:@"%@://%@",
                                            url.scheme, url.host]];
}

@end
