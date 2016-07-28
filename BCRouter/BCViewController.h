//
//  BCViewController.h
//  BCRouterExample
//
//  Created by billchan on 7/28/16.
//  Copyright © 2016 cmb. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BCCommonFunction.h"

@interface BCViewController : UIViewController

@property (unsafe_unretained, nonatomic) BCNavigationController         *navigator;
@property (strong, nonatomic) NSDictionary                              *params;
@property (strong, nonatomic) NSDictionary                              *query;
@property (strong, nonatomic) NSURL                                     *url;

- (id)initWithURL:(NSURL *)aUrl;
- (id)initWithURL:(NSURL *)aUrl query:(NSDictionary *)query;
- (void)openedFromViewControllerWithURL:(NSURL *)aUrl;
- (BOOL)shouldOpenViewControllerWithURL:(NSURL *)aUrl;

@end
