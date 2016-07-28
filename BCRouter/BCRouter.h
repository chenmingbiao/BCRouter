//  The MIT License (MIT)
//
//  Copyright (c) 2016 LIGHT mbillchan@gmail.com
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the “Software”), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class BCViewController;
@class BCSlideNavigationController;

@interface BCRouter : NSObject

@property (nonatomic, unsafe_unretained)    UINavigationController          *currentNav;
@property (nonatomic, unsafe_unretained)    UITabBarController              *currentTab;
@property (nonatomic, unsafe_unretained)    BCSlideNavigationController     *currentSlide;
@property (nonatomic, unsafe_unretained)    BCViewController                *currentVC;

@property (nonatomic, strong)               NSString                        *transitionType;
@property (nonatomic, strong)               NSString                        *transitionSubtype;

+ (instancetype)sharedRouter;

- (void)setViewControllerName:(NSString *)className forURL:(NSString *)url;
- (void)setViewController:(UIViewController *)vc forURL:(NSString *)url;
- (void)setViewControllersForKeysFromDictionary:(NSDictionary *)dict;

- (void)openURL:(NSURL *)url withQuery:(NSDictionary *)query;
- (void)openURL:(NSURL *)url;
- (BOOL)URLAvailable:(NSURL *)url;
- (UIViewController *)viewControllerForURL:(NSURL *)url withQuery:(NSDictionary *)query;

@end

