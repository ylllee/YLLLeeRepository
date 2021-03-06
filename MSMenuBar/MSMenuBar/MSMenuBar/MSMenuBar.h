//
//  MSMenuBar.h
//  MSMenuBar
//
//  Created by limingshan on 16/5/30.
//  Copyright © 2016年 limingshan. All rights reserved.
//

/**
 * 颜色rgb自定义
 */
#define kColorWith(r,g,b,al) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:al]

//菜单栏高度
#define kMenu_height 40
//菜单栏选中后标题文本颜色
#define kTitleSelectedColor kColorWith(51, 158, 210, 1)
//菜单栏标题字体大小
#define kMenuTitle_font 14


#import <UIKit/UIKit.h>

#import "UIViewExt.h"

@class MSMenuBar;

@protocol MSMenuBarDelegate <NSObject>

- (void)msMenuBar:(MSMenuBar *)msMenuBar didEditButtonClicked:(UIButton *)button;

@end

@interface MSMenuBar : UIView<UIScrollViewDelegate> {
    #pragma mark ========= 菜单栏的设置 =========
    //菜单栏标题label数组
    NSArray *_menuCellArray;
    //菜单栏背景视图
    UIView *_menuBarBgView;
    //菜单栏滚动视图
    UIScrollView *_menuBarScrollView;
    //菜单栏左右遮罩视图
    UIImageView *_maskLeftImageView;
    UIImageView *_maskRightImageView;
    //编辑按钮
    UIButton *_menuEditButton;
    //菜单栏选中下划线
    UIView *_menuSelectedLine;
    //菜单栏索引位置
    NSInteger _menuCellSelectedIndex;
    //菜单栏不滚动的最大范围
    CGFloat _scroll_max;
    //保存菜单栏所有menuCell的数组
    NSMutableArray *_allMenuCell;
    #pragma mark ========= 内容视图的设置 =========
    //内容视图的底部视图
    UIScrollView *_contentScrollView;
}

@property (nonatomic, weak) id <MSMenuBarDelegate> delegate;

#pragma mark ========= 菜单栏的设置 =========
/**
 * 标题数组
 */
@property (nonatomic, strong) NSArray *menuTitles;

/**
 * 菜单栏高度
 */
@property (nonatomic, assign) CGFloat menuBarHeight;

/**
 * 菜单栏标题字体_默认
 */
@property (nonatomic, strong) UIFont *menuBarTitleNormalFont;

/**
 * 菜单栏标题字体_选中
 */
@property (nonatomic, strong) UIFont *menuBarTitleSelectedFont;

/**
 * 菜单栏标题字体颜色_选中
 */
@property (nonatomic, strong) UIColor *menuTitleSelectedColor;

/**
 * 菜单栏标题字体颜色_默认
 */
@property (nonatomic, strong) UIColor *menuTitleNormalColor;

/**
 * 菜单栏标题选中下划线颜色
 */
@property (nonatomic, strong) UIColor *menuTitleSelectedLineColor;

/*
 *  菜单栏控件选中按钮索引位置
 */
@property (nonatomic, assign) NSInteger selectedIndex;

/*
 * 菜单栏的表框的颜色
 */
@property (nonatomic, strong) UIColor *menuLayerBorderColor;

/*
 * 菜单栏的表框的宽度
 */
@property (nonatomic, assign) CGFloat menuLayerBorderWidth;

/*
 * 菜单栏的背景颜色
 */
@property (nonatomic, strong) UIColor *menuBarBgColor;

/*
 * 菜单栏是否显示遮罩视图
 */
@property (nonatomic, assign) BOOL isShowMaskViews;

#pragma mark ========= 内容视图的设置 =========
/*
 *  内容视图数组
 */
@property (nonatomic, strong) NSArray *contentViews;

/*
 *  菜单栏添加标题 内容视图添加视图
 */
- (void)addMenuTitle:(NSString *)menuTitle contentView:(UIView *)contentView;

/*
 *  菜单栏移除标题 内容视图移除视图
 */
- (void)removeMenuTitleAndContentViewWithIndex:(NSInteger)removeIndex;

/*
 *  更新菜单栏标题和内容视图
 */
- (void)reloadMenuBarWithMenuTitles:(NSArray *)menuTitles contentViews:(NSArray *)contentViews;
















@end
