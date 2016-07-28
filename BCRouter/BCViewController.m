//
//  BCViewController.m
//  BCRouterExample
//
//  Created by billchan on 7/28/16.
//  Copyright © 2016 cmb. All rights reserved.
//

#define ANIMATION_DURATION          0.3f
#define DEFAULT_SLIDE_VC_WIDTH      320.0f - 44.0f
#define SILENT_DISTANCE             40.0f
#define SILENT_DISTANCE_B           20.0f

#import "BCViewController.h"

@interface BCViewController ()
@end

@implementation BCViewController

#pragma mark - public

- (id)initWithURL:(NSURL *)aUrl
{
    self = [super initWithNibName:nil bundle:nil];
    if (self) {
        _url = aUrl;
        _params = [aUrl params];
    }
    return self;
}

- (id)initWithURL:(NSURL *)aUrl query:(NSDictionary *)aQuery {
    self = [super initWithNibName:nil bundle:nil];
    if (self) {
        self.url = aUrl;
        self.params = [aUrl params];
        self.query = aQuery;
    }
    return self;
}

- (void)openedFromViewControllerWithURL:(NSURL *)aUrl
{
}

- (BOOL)shouldOpenViewControllerWithURL:(NSURL *)aUrl
{
    return YES;
}

#pragma mark

- (void)viewDidLoad
{
    [super viewDidLoad];
}

@end
