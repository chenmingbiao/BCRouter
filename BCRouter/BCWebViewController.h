//
//  BCWebViewController.h
//  BCRouterExample
//
//  Created by billchan on 7/28/16.
//  Copyright © 2016 cmb. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BCViewController.h"

@interface BCWebViewController : BCViewController <UIWebViewDelegate>

@property (strong, nonatomic) UIWebView *webView;

- (void)loadRequest;
- (void)reloadToolBar;

@end
