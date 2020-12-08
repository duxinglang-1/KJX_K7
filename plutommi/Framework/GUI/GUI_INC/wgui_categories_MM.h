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
 *  wgui_categories_MM.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Main Menu related categories.
 *
 *  Author:
 * -------
 *  Leo Hu (MTK00563)
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __WGUI_CATEGORIES_MM_H__
#define __WGUI_CATEGORIES_MM_H__

#include "MMI_features.h"

#include "MMIDataType.h"
#include "gui_data_types.h"
#include "wgui_draw_manager.h"
#if defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
#include "AppMgrSrvGprot.h"
#endif

/* 1: Enables animated wallpapers in Idle screen
   0: Disables animated wallpapers in Idle screen                    */
#ifdef __MMI_ANIMATED_WALLPAPERS__
#define ENABLE_ANIMATED_WALLPAPERS              1
//#else 
//#define ENABLE_ANIMATED_WALLPAPERS              0
#endif 

/* 1: Enables direct main menu implementation (fast but fixed to 3x3 grid)
   0: Uses standard main menu implementation (slow with flexible grid)     */
#define ENABLE_DIRECT_MAIN_MENU_IMPLEMENTATION     1

/* 1: Enables one pixel spacing around the main menu                 */
/* 0: No spacing around the main menu                          */
/* This applies only to direct main menu                          */
#define DIRECT_MAIN_MENU_BOUNDARY_SPACING       0

/* Use this to define the amount by which the icons displayed
   in unfocussed state (first frame) are shifted in the main menu       */
#define DIRECT_MAIN_MENU_FIRST_FRAME_SHIFT_X    -5
#define DIRECT_MAIN_MENU_FIRST_FRAME_SHIFT_Y    -5

/* Set this to 1 to be able to change icons along with the title. This is
   done externally using the highlight handler registered to the main menu
   Set to 0 for normal operation                               */
#define DISABLE_MAIN_MENU_HIGHLIGHT_TITLE_UPDATE   1

/*#if (defined (__MMI_MAINLCD_240X400__)  || defined (__MMI_MAINLCD_320X480__)) \  */
#if (defined (__MMI_MAINLCD_320X480__))\
	&& !defined(__MMI_OP01_MENU_12MATRIX__) && !defined(__MMI_OP02_MAINMENU_12MATRIX__)\
	&& !defined(__MMI_OP01_MENU_9MATRIX__) && !defined(__MMI_OP02_MAINMENU_9MATRIX__)
	#define __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__
#endif/* for new list_matrix menu style */
//#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__

#if defined(__MMI_MAINLCD_240X320__)
#define MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH   65
#define MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_COUNT 3
#define MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT 20
#define MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP 3
#define MMI_BI_DEGREE_MAIN_MENU_GAP 3
#elif defined(__MMI_MAINLCD_320X240__) /* defined(__MMI_MAINLCD_240X320__) */ 
#define MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH  36
#define MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT 2
#define MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP 0
#define MMI_BI_DEGREE_MAIN_MENU_GAP 3
#elif defined(__MMI_MAINLCD_240X400__)
#define MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH   45
#define MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_COUNT 3
#define MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT 40
#define MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP 3
#define MMI_BI_DEGREE_MAIN_MENU_GAP 3
#elif defined(__MMI_MAINLCD_320X480__)
#define MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH   50
#define MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_COUNT 3
#define MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT 0
#define MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP 3
#define MMI_BI_DEGREE_MAIN_MENU_GAP 0
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#define MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH   40
#define MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_ROW_COUNT 2
#define MMI_BI_DEGREE_MAIN_MENU_NAVI_BAR_HEIGHT 20
#define MMI_BI_DEGREE_MAIN_MENU_ICON_TEXT_GAP 3
#define MMI_BI_DEGREE_MAIN_MENU_GAP 3
#endif /* defined(__MMI_MAINLCD_240X320__) */
//#endif

#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_MAINLCD_320X480__        
    #define MMI_UI_LIST_ROW_NUM 6
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH 314
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT 59
#elif defined __MMI_MAINLCD_240X320__
    #define MMI_UI_LIST_ROW_NUM 5
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH 234
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT 45
#elif defined __MMI_MAINLCD_240X400__            
    #define MMI_UI_LIST_ROW_NUM 5
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH 234
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT 58
#else /* __MMI_MAINLCD_240X320__ */ 
    #define MMI_UI_LIST_ROW_NUM 5
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH 234
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT 58
#endif /* __MMI_MAINLCD_240X320__ */ 
#else /* __MMI_FTE_SUPPORT__*/
#ifdef __MMI_MAINLCD_320X480__        
    #define MMI_UI_LIST_ROW_NUM 6
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH 295
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT 63
#elif defined __MMI_MAINLCD_240X320__
    #define MMI_UI_LIST_ROW_NUM 6
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH 224
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT 40
#elif defined __MMI_MAINLCD_240X400__            
    #define MMI_UI_LIST_ROW_NUM 4
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH 217
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT 76
#elif defined __MMI_MAINLCD_320X240__   
    #define MMI_UI_LIST_ROW_NUM 3
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH 308
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT 58 
#else /* __MMI_MAINLCD_240X320__ */ 
    #define MMI_UI_LIST_ROW_NUM 3
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_WIDTH 224
    #define MMI_LIST_MAINMENU_HIGHLIGHT_IMAGE_HEIGHT 40
#endif /* __MMI_MAINLCD_240X320__ */ 
#endif /* __MMI_FTE_SUPPORT__ */

typedef struct _matrix_main_menu_category_history
{
    U16 history_ID;
    S16 highlighted_item;
    U32 flags;
} matrix_main_menu_category_history;

typedef struct _circular_menu_category_history
{
    U16 history_ID;
    S16 highlighted_item;
    U32 flags;
} circular_menu_category_history;

typedef struct _matrix_main_menu
{
    S32 x, y;
    U32 flags;
    S32 n_items;
    S32 highlighted_item;
    PU8 *list_of_items;
    void (*item_highlighted) (S32 item_index);
    void (*item_unhighlighted) (S32 item_index);
    bitmap highlight_area;
    S32 save_x, save_y;
} matrix_main_menu;


extern matrix_main_menu _wgui_main_menu;
extern UI_string_type _wgui_main_menu_item_strings[];

extern U8 set_circular_menu_category_history(U16 history_ID, U8 *history_buffer);
extern void get_circular_menu_category_history(U16 history_ID, U8 *history_buffer);

extern void RedrawCategory14Screen(void);


#if defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat9015_show
 * DESCRIPTION
 *  Displays the category9015 screen . this is a scrren to show main menu
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items_info      [IN]        Array of items
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
/*extern void wgui_cat9015_show(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        srv_app_info_struct *list_of_items_info,
        S32 highlighted_item,
        U8 *history_buffer);*/
#endif /* __MMI_MAINMENU_SPREAD_SUPPORT__ */


/***************************************************************************************
  * FUNCTION:  ShowCategory14Screen
  * Description
  * Displays the category14 screen . this is a scrren to show main menu
  * [FTE]: support(tool bar is not avaiable)
  * <xtable>
  * Matrix                     Page                            List
  * -------------------------  ------------------------------  -------------------------
  * <image wgui_cat014_img1>   <image wgui_cat014_img2>        <image wgui_cat014_img3>
  * All items are list         User can see each menu item     Each menu item is
  *  within a matrix. Most      independent of another. Every   shown as the simple
  *  of the items can be        menu item will be displayed     list with large
  *  seen within a screen.      on a different screen page.     icons.
  * </xtable>
  * 
  * Parameters
  * title :               [IN ] (TITLE) Title for the screen
  * title_icon :          [IN ] (N/A) Icon displayed with the title
  * left_softkey :        [IN ] (LSK) Left softkey label
  * left_softkey_icon :   [IN ] (N/A) Left softkey icon
  * right_softkey :       [IN ] (RSK) Right softkey label
  * right_softkey_icon :  [IN ] (N/A) Right softkey icon
  * number_of_items :     [IN ] (N/A) Number of items in the menu
  * list_of_items :       [IN ] (MATRIX,LISTMAIN,PAGEITEM) Array of items
  * list_of_icons :       [IN ] (N/A) Array of icons
  * flags :               [IN ] (N/A) (see explanation below)
  * highlighted_item :    [IN ] (N/A) Default item to be highlighted (if
  *                       there is no history)
  * history_buffer :      [IN ] (N/A) History buffer
  * Returns
  *  void
  * Example
  * <code>
  * void EntryScreen_14LST(void)
  * {
  *     U8 *guiBuffer = NULL;
  *     U16 ItemList[] = 
  *     {
  *         STR_ID_CSB_MENUITEM1_TEXT,
  *         STR_ID_CSB_MENUITEM2_TEXT,
  *         STR_ID_CSB_MENUITEM3_TEXT,
  *         STR_ID_CSB_MENUITEM4_TEXT,
  *         STR_ID_CSB_MENUITEM5_TEXT,
  *         STR_ID_CSB_MENUITEM6_TEXT
  *     };
  *
  *     U16 Iconlist[] = 
  *     {
  *         IMG_PROFILES_OUTDOOR,
  *         IMG_PROFILES_OUTDOOR,
  *         IMG_PROFILES_OUTDOOR,
  *         IMG_PROFILES_OUTDOOR,
  *         IMG_PROFILES_OUTDOOR,
  *         IMG_PROFILES_OUTDOOR
  *     };
  *
  *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *
  *     ShowCategory14Screen(
  *         STR_ID_CSB_CATEGORY_TEXT,
  *         0,
  *         STR_ID_CSB_LSK_TEXT,
  *         0,
  *         STR_ID_CSB_RSK_TEXT,
  *         0,
  *         6,
  *         ItemList,
  *         Iconlist,
  *         LIST_MENU,
  *         0,
  *         (U8*) guiBuffer);
  *
  *     csb_set_key_handlers();
  * }
  * </code>                                                                             
  ***************************************************************************************/
extern void ShowCategory14Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer);
extern void ExitCategory14Screen(void);
extern S32 GetCategory14HistorySize(void);
extern U8 *GetCategory14History(U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  initialize_mainmenu_title_icons
 * DESCRIPTION
 *  Called once during bootup to initialize category screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void initialize_mainmenu_title_icons(void);
extern void draw_bg_animation(void);
extern void draw_bg(void);

#if defined(__MMI_MAINLCD_240X400__)


/*****************************************************************************
 * FUNCTION
 *  initialize_mainmenu_controlarea_image
 * DESCRIPTION
 *  Called once during bootup to initialize category screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void initialize_mainmenu_controlarea_image(void);
extern void category14_redraw_controlarea_callback(dm_coordinates *coordinate);
#endif

#ifdef __MMI_MAINLCD_128X64__
extern void wgui_cat9014_show(
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        S32 highlighted_item,
        U8 *history_buffer);
#endif
#endif /* __WGUI_CATEGORIES_MM_H__ */ 


