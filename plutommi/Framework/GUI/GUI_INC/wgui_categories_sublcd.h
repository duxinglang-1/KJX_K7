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
 *  wgui_categories_sublcd.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Sublcd display related categories.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef WGUI_CATEGORIES_SUBLCD_H
#define WGUI_CATEGORIES_SUBLCD_H

#include "MMI_features.h"

/* <hExpand noExpand> DO NOT REMOVE THIS LINE */
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
#include "wgui_dynamic_menus.h"
#include "wgui_dynamic_menuitems.h"
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
/* </hExpand> DO NOT REMOVE THIS LINE */

#include "MMIDataType.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#define CATEGORY311_TEXT_SCROLL_GAP    (32)
#define CATEGORY311_TEXT_SCROLL_SIZE   (3)
#define CATEGORY311_TEXT_SCROLL_TIME   (700)
#define CATEGORY311_TEXT_SCROLL_WAIT   (1000)
#define CATEGORY311_TEXT_SCROLL_X      (0)
#define CATEGORY311_TEXT_SCROLL_Y      (18)

#ifdef __MMI_SUB_WALLPAPER__
#define MAX_SUB_WALLPAPER_FRAME        (20)
#endif 
/* DOM-NOT_FOR_SDK-BEGIN */
extern void (*SUBLCD_ExitCategoryFunction) (void);
extern void (*SUBLCD_RedrawCategoryFunction) (void);
extern U8 *(*SUBLCD_GetCategoryHistory) (U8 *buffer);
extern S32(*SUBLCD_GetCategoryHistorySize) (void);

extern PU8 SUBLCD_MMI_animated_icon;
extern S32 SUBLCD_MMI_animated_icon_x;
extern S32 SUBLCD_MMI_animated_icon_y;
extern UI_animated_image_handle SUBLCD_MMI_animated_icon_handle;

#ifdef __MMI_SUBLCD__
extern S32 SUB_LCD_device_width;
extern S32 SUB_LCD_device_height;
#endif /* __MMI_SUBLCD__ */ 

extern void show_status_icon_sublcd(S16 icon_ID);
extern void SUBLCD_screens_show_status_icons(void);
extern void SUBLCD_screens_hide_status_icons(void);
extern void ShowSubLCDStatusIconsTitle(void);
/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  ShowCategory301Screen
 * DESCRIPTION
 *  Displays the category301 screen
 * 
 * <img name="wgui_cat301_img1" />
 * PARAMETERS
 *   message                       : [IN ] (UNLIM) Message string
 *   message_icon                  : [IN ] (N/A) Message icon
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_301(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory301Screen(
 *         (PU8) GetString(STR_ID_CSB_DUMMY_TEXT),
 *         0,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory301Screen(U8 *message, U16 message_icon, U8 *history_buffer);
extern void ExitCategory301Screen(void);

extern void RedrawCategory302Screen(void);
/*****************************************************************************
 * FUNCTION
 *  ShowCategory302Screen
 * DESCRIPTION
 *  Displays the category302 screen  (Clears SUB LCD)
 * 
 * <img name="wgui_cat302_img1" />
 * PARAMETERS
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_302(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory302Screen(NULL);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory302Screen(U8 *history_buffer);
extern void ExitCategory302Screen(void);

/*****************************************************************************
 * FUNCTION
 *  ShowCategory303Screen
 * DESCRIPTION
 *  Displays the category303 screen :- sub lcd screen display details of 2 cities on sublcd
 * 
 * <img name="wgui_cat303_img1" />
 * PARAMETERS
 *   message1                      : [IN ] (N/A) String of message1
 *   message2                      : [IN ] (N/A) String of message2
 *   time_diff1                    : [IN ] (N/A) Time difference1
 *   time_diff2                    : [IN ] (N/A) Time difference2
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_303(void)
 * {
 *     FLOAT diff1, diff2;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     diff1 = 3.5;
 *     diff2 = 2.5;
 * 
 *     ShowCategory303Screen(
 *         (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
 *         (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
 *         diff1,
 *         diff2,
 *         NULL);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory303Screen(
                U8 *message1,
                U8 *message2,
                FLOAT time_diff1,
                FLOAT time_diff2,
                U8 *history_buffer);
extern void ExitCategory303Screen(void);

/*****************************************************************************
 * FUNCTION
 *  ShowCategory304Screen
 * DESCRIPTION
 *  Displays the category304 screen
 * 
 * <img name="wgui_cat304_img1" />
 * PARAMETERS
 *   message_icon                  : [IN ] (N/A) Message icon
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_304(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory304Screen(IMG_GLOBAL_OK, 0);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory304Screen(U16 message_icon, U8 *history_buffer);
extern void ExitCategory304Screen(void);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory310Screen
 * DESCRIPTION
 *  Show category 310 screen
 * 
 * <img name="wgui_cat310_img1" />
 * PARAMETERS
 *   string                        : [IN ] (N/A) string to show
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_310(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory310Screen(get_string(STR_GLOBAL_LOGO));
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory310Screen(UI_string_type string);

/*****************************************************************************
 * FUNCTION
 *  ShowCategory311Screen
 * DESCRIPTION
 *  Displays the category311 screen:- dispaly the mesage and icon on sublcd
 *  if text s longer than sublcd witdth then scroll text
 * 
 * <img name="wgui_cat311_img1" />
 * PARAMETERS
 *   message                       : [IN ] (N/A) Message string
 *   message_icon                  : [IN ] (N/A) Message icon
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_311(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory311Screen((U8*) GetString(STR_ID_CSB_DUMMY_TEXT), IMG_GLOBAL_OK, NULL);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory311Screen(U8 *message, U16 message_icon, U8 *history_buffer);
extern void ExitCategory311Screen(void);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory312Screen
 * DESCRIPTION
 *  Displays the category312 screen:- show one city detail on sub lcd screen
 *                                 : [1  ] (N/A) STRING     message to be displayed
 *                                 : [2  ] (N/A) MYTIME      time difference
 * 
 * <img name="wgui_cat312_img1" />
 * PARAMETERS
 *   message                       : [IN ] (N/A) Message string
 *   time_diff_312                 : [IN ] (N/A) Time difference
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_312(void)
 * {
 *     FLOAT time_difference;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     time_difference = 1;
 * 
 *     ShowCategory312Screen((U8*) GetString(STR_ID_CSB_DUMMY_TEXT), time_difference, NULL);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory312Screen(U8 *message, FLOAT time_diff_312, U8 *history_buffer);
extern void ExitCategory312Screen(void);
extern void wgui_cat312_refresh_info(void);
extern void wgui_cat312_setinfo2(U8 *message);
extern void wgui_cat312_setinfo1(U8 *message);
/*****************************************************************************
 * FUNCTION
 *  ShowCategory313Screen
 * DESCRIPTION
 *  Displays the category313 screen
 * 
 * <img name="wgui_cat313_img1" />
 * PARAMETERS
 *   message_icon                  : [IN ] (N/A) Message icon
 *   history_buffer                : [IN ] (N/A) History Buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_313(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory313Screen(IMG_SUBLCD_SYSTEM_SHUTDOWN, NULL);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory313Screen(U16 message_icon, U8 *history_buffer);
extern void ExitCategory313Screen(void);

/*****************************************************************************
 * FUNCTION
 *  ShowCategory314Screen
 * DESCRIPTION
 *  show category 314 screen
 * 
 * <img name="wgui_cat314_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon ID
 *   number_of_items               : [IN ] (N/A) Total count of number
 *   list_of_items                 : [IN ] (SUBICONTEXT) String list of items
 *   list_of_icons                 : [IN ] (N/A) Icon list of items
 *   list_of_descriptions          : [IN ] (N/A) Description list of items
 *   highlighted_item              : [IN ] (N/A) Highlighted item
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_314(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     U16 ItemList[2];
 *     U16 ItemIcon[2];
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ItemList[0] = STR_ID_CSB_MENUITEM1_TEXT;
 *     ItemList[1] = STR_ID_CSB_MENUITEM2_TEXT;
 * 
 *     ItemIcon[0] = IMG_PROFILES_OUTDOOR;
 *     ItemIcon[1] = IMG_PROFILES_OUTDOOR;
 * 
 *     ShowCategory314Screen(
 *         (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
 *         0,
 *         2,
 *         ItemList,
 *         ItemIcon,
 *         NULL,
 *         0,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory314Screen(
                U8 *title,
                U16 title_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                U8 **list_of_descriptions,
                S32 highlighted_item,
                U8 *history_buffer);
extern void ExitCategory314Screen(void);
extern void UpdateCategory314KeyStateInd(MMI_BOOL state);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory315Screen
 * DESCRIPTION
 *  
 * 
 * <img name="wgui_cat315_img1" />
 * PARAMETERS
 *   title                         : [IN ] (N/A) Title string
 *   title_icon                    : [IN ] (N/A) Title icon id
 *   number_of_items               : [IN ] (N/A) Total count of number
 *   get_item_func                 : [IN ] (N/A) Get item callback
 *   get_hint_func                 : [IN ] (N/A) Get hint callback
 *   highlighted_item              : [IN ] (N/A) Highltighted item
 *   disable_data_cache            : [IN ] (N/A) Whether caching of dynamic data is disabled
 *   flush_data_callback           : [IN ] (N/A) Callback function invoked before data is reloaded
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory315Screen(
        U8 *title,
        U16 title_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        MMI_BOOL disable_data_cache,
        void (*flush_data_callback) (void),
        U8 *history_buffer);
extern void ShowSubLCDLogoString(void);

#ifdef __MMI_SUB_WALLPAPER__
/*****************************************************************************
 * FUNCTION
 *  SUBLCD_UpdateWallpaper
 * DESCRIPTION
 *  a function to update sublcd wallpaper
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void SUBLCD_UpdateWallpaper(void);
/* DOM-NOT_FOR_SDK-BEGIN */
extern void SUBLCD_StartWallpaperAnimation(void);
extern void SUBLCD_StopWallpaperAnimation(void);
/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  SUBLCD_SetIdleScreenWallpaperID
 * DESCRIPTION
 *  set idle screen wallpaper ID
 * PARAMETERS
 *  image_ID        [IN]        Image ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void SUBLCD_SetIdleScreenWallpaperID(U16 image_ID);
/*****************************************************************************
 * FUNCTION
 *  SUBLCD_SetIdleScreenWallpaperName
 * DESCRIPTION
 *  set Idel screen wallpapaer name
 * PARAMETERS
 *  name        [IN]        name of wallpaper
 * RETURNS
 *  void
 *****************************************************************************/
extern void SUBLCD_SetIdleScreenWallpaperName(UI_string_type name);
/*****************************************************************************
 * FUNCTION
 *  SUBLCD_CheckWallpaperFrameCount
 * DESCRIPTION
 *  to check if the image frame out of limit
 * PARAMETERS
 *  name        [IN]        Image path
 * RETURNS
 *  void
 *****************************************************************************/
extern BOOL SUBLCD_CheckWallpaperFrameCount(UI_string_type name);
#endif /* __MMI_SUB_WALLPAPER__ */ 

extern void gui_rotate_180_sublcd(void);

#ifndef WGUI_CAT312_STRING_Y
#define WGUI_CAT312_STRING_Y (13)
#endif /* WGUI_CAT312_STRING_Y */

#ifndef WGUI_CAT312_STRING_HEIGHT
#define WGUI_CAT312_STRING_HEIGHT (13 * 2)
#endif /* WGUI_CAT312_STRING_HEIGHT */

#endif /* WGUI_CATEGORIES_SUBLCD_H */ 


