/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER 
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  wgui_categories_sns.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Some SNS special categories.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WGUI_CATEGORIES_SNS_H__
#define __WGUI_CATEGORIES_SNS_H__

#if defined(__SOCIAL_NETWORK_SUPPORT__)

#include "wgui_categories_list.h"
#include "gdi_include.h"

typedef struct 
{
    PU8 tn_icon_filepath;
	U16 tn_icon_id;
    PU8 status_icon;
    PU8 type_icon;
    PU8 user_name;
    PU8 user_status;
}wgui_cat_sns_title;


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define WGUI_CAT_SNS_TITLE_Y		(get_status_bar_height())
#define WGUI_CAT_SNS_TITLE_HEIGHT	(get_multirow_menuitem_height())

#define WGUI_CAT_SNS_ITEM_NONE					(0)
#define WGUI_CAT_SNS_ITEM_LOADING				(1)
#define	WGUI_CAT_SNS_ITEM_MORE					(1<<1)
#define WGUI_CAT_SNS_ITEM_ADDCOUNT				(1<<2)
#define WGUI_CAT_SNS_ITEM_LOADING_SHOW			(1<<3)
#define WGUI_CAT_SNS_ITEM_NEW_MSG				(1<<4)

#if defined(__MMI_MAINLCD_320X480__)
    #define WGUI_CAT1057_THUMBNAIL_W			(30)
    #define WGUI_CAT1057_THUMBNAIL_H			(30)
    #define WGUI_THUMBNAIL_LEFT_RIGHT_GAP		(13)
    #define WGUI_THUMBNAIL_TOP_BOM_GAP			(5)
    #define WGUI_THUMBNAIL_DETAIL_HEIGHT		(80)
	#define WGUI_CAT_TEXT_TEXT_GAP				(2)
	#define WGUI_CAT1057_MENUITEM_HEIGHT		(80)
	#define WGUI_CAT1057_THUMBNAIL_ITEM_HEIGHT	(40)
    #define WGUI_CATE_SNS_LIKE_IMG_WIDTH		(15)
    #define WGUI_CATE_SNS_COMMENT_IMG_WIDTH		(15)
    #define WGUI_CATE_SNS_STRING_GAP			(2)
#elif defined(__MMI_MAINLCD_240X320__)
    #define WGUI_CAT1057_THUMBNAIL_W			(30)
	#define WGUI_CAT1057_THUMBNAIL_H			(30)
    #define WGUI_THUMBNAIL_LEFT_RIGHT_GAP		(7)
    #define WGUI_THUMBNAIL_TOP_BOM_GAP			(5)
    #define WGUI_THUMBNAIL_DETAIL_HEIGHT		(80)
	#define WGUI_CAT_TEXT_TEXT_GAP				(0)
	#define WGUI_CAT1057_MENUITEM_HEIGHT		(80)
	#define WGUI_CAT1057_THUMBNAIL_ITEM_HEIGHT	(40)
    #define WGUI_CATE_SNS_LIKE_IMG_WIDTH		(15)
    #define WGUI_CATE_SNS_COMMENT_IMG_WIDTH 	(15)
    #define WGUI_CATE_SNS_STRING_GAP			(2)
#elif defined(__MMI_MAINLCD_240X480__)
    #define WGUI_CAT1057_THUMBNAIL_W			(30)
	#define WGUI_CAT1057_THUMBNAIL_H			(30)
    #define WGUI_THUMBNAIL_LEFT_RIGHT_GAP		(7)
    #define WGUI_THUMBNAIL_TOP_BOM_GAP			(5)
    #define WGUI_THUMBNAIL_DETAIL_HEIGHT		(80)
	#define WGUI_CAT_TEXT_TEXT_GAP				(0)
	#define WGUI_CAT1057_MENUITEM_HEIGHT		(80)
	#define WGUI_CAT1057_THUMBNAIL_ITEM_HEIGHT	(40)
    #define WGUI_CATE_SNS_LIKE_IMG_WIDTH		(15)
    #define WGUI_CATE_SNS_COMMENT_IMG_WIDTH 	(15)
    #define WGUI_CATE_SNS_STRING_GAP			(2)
#else
    #define WGUI_CAT1057_THUMBNAIL_W			(30)
	#define WGUI_CAT1057_THUMBNAIL_H			(30)
    #define WGUI_THUMBNAIL_LEFT_RIGHT_GAP		(7)
    #define WGUI_THUMBNAIL_TOP_BOM_GAP			(5)
    #define WGUI_THUMBNAIL_DETAIL_HEIGHT		(80)
	#define WGUI_CAT_TEXT_TEXT_GAP				(0)
	#define WGUI_CAT1057_MENUITEM_HEIGHT		(80)
	#define WGUI_CAT1057_THUMBNAIL_ITEM_HEIGHT	(40)
    #define WGUI_CATE_SNS_LIKE_IMG_WIDTH		(15)
    #define WGUI_CATE_SNS_COMMENT_IMG_WIDTH 	(15)
    #define WGUI_CATE_SNS_STRING_GAP			(2)
#endif


#define WGUI_CAT_SNS_THUMBNAIL_W	(get_multirow_menuitem_height() - WGUI_THUMBNAIL_TOP_BOM_GAP - 3)
#define WGUI_CAT_SNS_THUMBNAIL_H	(get_multirow_menuitem_height() - WGUI_THUMBNAIL_TOP_BOM_GAP - 3)


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1052_refresh_list
 * DESCRIPTION
 *  Refresh sns async dynamic list menu
 *  Please notice that only those categories which do not have list effect are suggested to refresh
 * PARAMETERS
 *  number_of_items     [IN]        number of menu-items
 *  highlighted_item    [IN]        currently highlighted item
 *  get_item_func       [IN]        get item function callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1052_refresh_list(
		S32 number_of_items,
		S32 highlighted_item,
		CatGetAsyncItemFuncPtr get_item_func);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1052_refresh
 * DESCRIPTION
 *  Refresh sns async dynamic list menu
 *  Please notice that only those categories which do not have list effect are suggested to refresh
 * PARAMETERS
 *  number_of_items     [IN]        number of menu-items
 *  highlighted_item    [IN]        currently highlighted item
 *  get_item_func       [IN]        get item function callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1052_refresh(
                    S32 number_of_items,
                    S32 highlighted_item,
                    CatGetAsyncItemFuncPtr get_item_func);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1051_show
 * DESCRIPTION
 *  Displays the fixed list menu with control area as title
 *  Option menu screen at SNS
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  left_softkey		[IN]		string ID of left softkey
 *  right_softkey		[IN]		string ID of right softkey
 *  number_of_items	[IN]        Number of items
 *  list_of_items		[IN]        List of text items.
 *  highlighted_item	[IN]        This is the default item that will be highlighted (if there is no history)
 *  history_buffer		[IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1051_show(
                wgui_cat_sns_title *title,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                PU8 *list_of_items,
                S32 highlighted_item,
                U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1052_show
 * DESCRIPTION
 *  Displays the async dynamic list menu for single large text
 *  Happenings screen from option menu at SNS
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  list_icon			[IN]		Default icon after large text
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1052_show(
                wgui_cat_sns_title *title,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                CatGetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1053_show
 * DESCRIPTION
 *  Displays the async dynamic list menu for thumbnail image
 *  Album screen at SNS
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  get_img_path_func	[IN]		function for get item thumbnail icon file path
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1053_show(
                wgui_cat_sns_title *title,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                CatGetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1054_show
 * DESCRIPTION
 *  Displays the async dynamic list menu for 2 text
 *  Notifications screen at SNS
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  title_icon			[IN]		Title icon for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  highlighted_tab		[IN]		Default tab item to be highlighted
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1054_show(
                PU8 title,
                PU8 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                CatGetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                S8 highlighted_tab,    
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1055_show
 * DESCRIPTION
 *  Displays the async dynamic list menu for thumbnail and text
 *  SNS friends screen at SNS
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  title_icon			[IN]		Title icon for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  get_img_path_func	[IN]		function for get item thumbnail icon file path
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1055_show(
                PU8 title,
                PU8 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                CatGetAsyncItemFuncPtr get_item_func,
                checkbox_get_image_funcptr_type get_state_func,
                checkbox_clicked_funcptr_type set_state_func,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1056_show
 * DESCRIPTION
 *  Displays the async dynamic list menu with item button
 *  SNS account screen at SNS
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  title_icon			[IN]		Title icon for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  list_icon			[IN]		Default icon for cal icon width and height
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1056_show(
                PU8 title,
                PU8 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                CatGetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                U16 list_icon,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1057_show
 * DESCRIPTION
 *  Displays the async dynamic list menu with item button and tab bar
 *  Happening item layout screen from main menu and Notifications at SNS
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  title_icon			[IN]		Title icon for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  get_img_path_func	[IN]		function for get item thumbnail icon file path
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  highlighted_tab		[IN]		Default tab to be highlighted (if there is no history)
 *  status_icon		[IN]		Default status icon for calc icon width and height
 *  type_icon			[IN]		Default type icon for calc icon width and height
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1057_show(
                PU8 title,
                PU8 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                CatGetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                S32 highlighted_tab,
                U16 status_icon,
                U16 type_icon,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1058_show
 * DESCRIPTION
 *  Displays the async dynamic list menu for happening detail
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1058_show(
				wgui_cat_sns_title *title,
	            U16 left_softkey,
	            U16 right_softkey,
	            S32 number_of_items,
	            CatGetAsyncItemFuncPtr get_item_func,
	            S32 highlighted_item,
	            U8 *history_buffer,
	            S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1059_show
 * DESCRIPTION
 *  Displays the async dynamic list menu with sns title
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  get_img_path_func	[IN]		function for get item thumbnail icon file path
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  highlighted_tab		[IN]		Default tab to be highlighted (if there is no history)
 *  list_icon0			[IN]		Default list icon0 for calc icon width and height
 *  list_icon1			[IN]		Default list icon1 for calc icon width and height
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1059_show(
				wgui_cat_sns_title *title,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                CatGetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                U16 list_icon0,
                U16 list_icon1,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1059_show
 * DESCRIPTION
 *  Displays the async dynamic list menu with sns title
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  get_img_path_func	[IN]		function for get item thumbnail icon file path
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1060_show(
				wgui_cat_sns_title *title,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                CatGetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag);


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_sns_register_get_attachment_icon_buffer_callback
 * DESCRIPTION
 *  Register search function (for APP)
 * PARAMETERS
 *  search_function     [IN]        Function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cate_sns_register_get_attachment_icon_buffer_callback(gdi_image_cache_bmp_struct(*get_attachment_icon_buffer) (S32, U32));


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_sns_get_attachment_icon_size
 * DESCRIPTION
 *  Register search function (for APP)
 * PARAMETERS
 *  search_function     [IN]        Function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cate_sns_get_attachment_icon_size(PU8 filePath, S32 *width_p, S32 *height_p);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1061_show
 * DESCRIPTION
 *  Quick search screen, support tab bar.
 * PARAMETERS
 *  left_softkey            [IN]        Left soft key label
 *  left_softkey_icon       [IN]        Left soft key icon
 *  right_softkey           [IN]        Right soft key label
 *  right_softkey_icon      [IN]        Right soft key icon
 *  highlighted_tab         [IN]        Highlighted tab
 *  tab_title               [IN]        Tab title
 *  number_of_items         [IN]        Number of items
 *  info_message            [IN]        Text in info area, NULL will not show info area
 *  get_item_func           [IN]        Callback function of get menu item 
 *  get_hint_func           [IN]        Callback function of get menu item hint
 *  get_state_func          [IN]        Callback function of get state, NULL will not show check box
 *  set_state_func          [IN]        Callback function of state changed, NULL will not show check box
 *  highlighted_item        [IN]        Highlighted item index
 *  left_icon               [IN]        Menuitme left icon 
 *  right_icon              [IN]        Menuitme right icon 
 *  buffer                  [IN]        Buffer
 *  buffer_max_length       [IN]        Buffer max length
 *  history_buffer          [IN]        Histpry buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat1061_show(
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S8 highlighted_tab,
        UI_string_type tab_title,
        UI_string_type info_message,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 highlighted_item,
        PU8 left_icon,
        PU8 right_icon,
        U8 *buffer,
        S32 buffer_max_length,
        U8 *history_buffer);

extern void wgui_cate_sns_show_title(S32 x, S32 y, S32 width, S32 height, wgui_cat_sns_title *area);

#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#endif /* __WGUI_CATEGORIES_SNS_H__ */
