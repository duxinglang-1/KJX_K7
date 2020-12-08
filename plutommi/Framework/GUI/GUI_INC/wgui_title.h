/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  Wgui_title.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for title
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

#ifndef __WGUI_TITLE_H__
#define __WGUI_TITLE_H__

#include "MMI_features.h"
#include "CustMenuRes.h"
#include "gui_config.h"
#include "wgui.h"
#include "gui_menu_shortcut.h"
#include "gui_title.h"
#include "wgui_include.h"

#define WGUI_TITLE_CHANGE_ICON           0x00000001
#define WGUI_TITLE_CHANGE_ICON2          0x00000002
#define WGUI_TITLE_CHANGE_TEXT           0x00000004

#define WGUI_TITLE_SHORTCUT_CHANGE_GOTO         0x00000001
#define WGUI_TITLE_SHORTCUT_CHANGE_PRE_GOTO     0x00000002
#define WGUI_TITLE_SHORTCUT_CHANGE_ALL     (WGUI_TITLE_SHORTCUT_CHANGE_PRE_GOTO | WGUI_TITLE_SHORTCUT_CHANGE_GOTO)

extern UI_string_type MMI_title_string;
extern PU8 MMI_title_icon;
extern PU8 MMI_title_icon2;
extern gui_title_struct g_wgui_title_bar;


#ifdef __MMI_VUI_ENGINE__

/*****************************************************************************
 * <group dom_title_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_title_register_venus_update_screen
 * DESCRIPTION
 *  Register the venus update screen callback function and handle
 * PARAMETERS
 *  venus_update_screen_callback    : [IN]    The venus update sceen callback function
 *  venus_update_screen_handle      : [IN]    The venus update screen handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_title_register_venus_update_screen(
        void (*venus_update_screen_callback)(void *handle),
        void *venus_update_screen_handle);

#endif /* __MMI_VUI_ENGINE__ */


/*****************************************************************************
 * <group dom_title_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_title_get_string
 * DESCRIPTION
 *  Get title's string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U8* wgui_title_get_string(void);

/*****************************************************************************
 * <group dom_title_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_title_disable_menu_shortcut_display
 * DESCRIPTION
 *  Set shortcut show or not
 * PARAMETERS
 *  disable_displaye_menu_shortcut  : [IN]    Whether disable shortcut show or not
 * RETURNS
 *  void
 *****************************************************************************/
 #ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
 void wgui_title_disable_menu_shortcut_display(MMI_BOOL disable_displaye_menu_shortcut);
 #else
 #define wgui_title_disable_menu_shortcut_display(_arg) 
 #endif


 /*****************************************************************************
  * <group dom_title_wgui_layer_property_setting>
  * FUNCTION
  *  wgui_title_set_shortcut_count
  * DESCRIPTION
  *  Set the max number allowed in the menu shortcut
  *  This is based on the number of items in the menu.
  * PARAMETERS
  *  n_items	 : [IN] 	   The max number of allowed	
  * RETURNS
  *  void
  * REMARKS
  *  This function will meansure the size of shortcut 
  *  and according to the size of shortcut, move to the right position
  *****************************************************************************/

void wgui_title_set_shortcut_count(S32 n_items);


/*****************************************************************************
 * <group dom_title_wgui_layer_property_setting>
 * FUNCTION
 *  set_menu_item_count
 * DESCRIPTION
 *  Set the max allowed number of menu shortcut
 * PARAMETERS
 *  n_items     : [IN]        The max allowed number of menu shortcut
 * RETURNS
 * return zero
 *****************************************************************************/
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
S32 set_menu_item_count(S32 n_items);
#else
#define set_menu_item_count(_arg) 
#endif


/*****************************************************************************
 * <group dom_title_wgui_layer_basic>
 * FUNCTION
 *  gui_redraw_menu_shortcut
 * DESCRIPTION
 *  Redraw menu shortcut and blt out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 #ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
void gui_redraw_menu_shortcut(void);
 #else
 #define gui_redraw_menu_shortcut() 
 //#define gui_redraw_menu_shortcut 0
 #endif

#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
 /*****************************************************************************
  * <group dom_title_wgui_layer_property_setting>
  * FUNCTION
  *  wgui_title_set_no_icon_shct
  * DESCRIPTION
  *  Set title have shortcut or not
  * PARAMETERS
  *  no_icon_shct		 : [IN]    Whether have shortcut or not 	 
  * RETURNS
  *  void
  * REMARKS
  *  When the no_icon_shct set MMI_TRUE, the title will not show right icon and shortcut 
  *  otherwise the one of right icon and shortcut will be showed
  *****************************************************************************/
void wgui_title_set_no_icon_shct(MMI_BOOL no_icon_shct);
#else
#define wgui_title_set_no_icon_shct(_arg) 
#endif


/*****************************************************************************
 * <group dom_title_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_reset_disable_shortcut_display
 * DESCRIPTION
 *  Enable shortcut display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 #ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
void wgui_reset_disable_shortcut_display(void);
 #else
 #define wgui_reset_disable_shortcut_display() 
 #endif


#define MMI_menu_shortcut_box (g_wgui_title_bar.sc)

#endif /* __WGUI_TITLE_H__ */ 


