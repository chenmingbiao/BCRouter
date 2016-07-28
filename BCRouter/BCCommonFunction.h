//
//  BCCommonFunction.h
//  BCRouterExample
//
//  Created by billchan on 7/28/16.
//  Copyright © 2016 cmb. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define PROTOCOL        @"PROTOCOL"
#define HOST            @"HOST"
#define PARAMS          @"PARAMS"
#define URI             @"URI"

@interface NSURL (UMURL)

- (NSURL *)addParams:(NSDictionary*)params;
- (NSDictionary *)params;
- (NSString *)protocol;

@end

@interface NSString (UMString)
- (BOOL)containsString:(NSString *)string options:(NSStringCompareOptions)options;
- (BOOL)containsString:(NSString *)string;
- (NSString *)urlencode;
- (NSString *)urldecode;

@end

@interface UIView (UMView)

- (CGFloat)left;
- (void)setLeft:(CGFloat)x;
- (CGFloat)top;
- (void)setTop:(CGFloat)y;
- (CGFloat)right;
- (void)setRight:(CGFloat)right;
- (CGFloat)bottom;
- (void)setBottom:(CGFloat)bottom;
- (CGFloat)centerX;
- (void)setCenterX:(CGFloat)centerX;
- (CGFloat)centerY;
- (void)setCenterY:(CGFloat)centerY;
- (CGFloat)width;
- (void)setWidth:(CGFloat)width;
- (CGFloat)height;
- (void)setHeight:(CGFloat)height;
- (CGPoint)origin;
- (void)setOrigin:(CGPoint)origin;
- (CGSize)size;
- (void)setSize:(CGSize)size;
- (void)removeAllSubviews;

@end
