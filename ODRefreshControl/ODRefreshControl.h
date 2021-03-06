//
//  ODRefreshControl.h
//  ODRefreshControl
//
//  Created by Fabio Ritrovato on 6/13/12.
//  Copyright (c) 2012 orange in a day. All rights reserved.
//
// https://github.com/Sephiroth87/ODRefreshControl
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@interface ODRefreshControl : UIControl {
    CAShapeLayer *_shapeLayer;
    CAShapeLayer *_arrowLayer;
    CAShapeLayer *_highlightLayer;
    UIView *_activity;
    BOOL _refreshing;
    BOOL _canRefresh;
    BOOL _ignoreInset;
    BOOL _ignoreOffset;
    BOOL _didSetInset;
    BOOL _hasSectionHeaders;
    CGFloat _lastOffset;
	BOOL _stayAtInsetTop;
}

@property (nonatomic, readonly) BOOL refreshing;
@property (nonatomic, strong) UIColor *tintColor;
@property (nonatomic) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
@property (nonatomic, strong) UIColor *activityIndicatorViewColor; // iOS5 or more

/**
 * YES, to position the bottom edge of control at the top of contentInsets.
 * Handy when the top part of the scroll view is actually obscured by something (and thus has content inset).
 */
@property (nonatomic, getter = shouldStayAtInsetTop) BOOL stayAtInsetTop;
/** Regulates control bottom margin in case `stayAtInsetTop` is enabled. */
@property (nonatomic) CGFloat bottomPadding;

- (id)initInScrollView:(UIScrollView *)scrollView;

// use custom activity indicator
- (id)initInScrollView:(UIScrollView *)scrollView activityIndicatorView:(UIView *)activity;

// Tells the control that a refresh operation was started programmatically
- (void)beginRefreshing;

// Tells the control the refresh operation has ended
- (void)endRefreshing;

- (void)startKeyValueObserving;
- (void)stopKeyValueObserving;

@end