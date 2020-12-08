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
 *  wgui_categories_popup.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Popup Screen related categories.
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
#ifndef WGUI_CATEGORIES_POPUP_H
#define WGUI_CATEGORIES_POPUP_H
#include "MMI_features.h"

/* <hExpand noExpand> DO NOT REMOVE THIS LINE */
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
#include "Gui_data_types.h"
#include "CustThemesRes.h"
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
/* </hExpand> DO NOT REMOVE THIS LINE */

#if (defined __MMI_TOUCH_SCREEN__)
#include "wgui_touch_screen.h"
#endif

#include "Gui_Setting.h"
#include "MMIDataType.h"
#include "CustThemesRes.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "wgui_categories_list.h"
#include "wgui.h"
/*  POPUP default timer 1000  */
#define UI_POPUP_NOTIFYDURATION_TIME            1000
/*  POPUP default timer 2000  */
#define UI_POPUP_NOTIFYDURATION_TIME_2000       2000

/* DOM-NOT_FOR_SDK-BEGIN */
#if defined(__MMI_MAINLCD_240X320__)
    #define UI_POPUP_BORDER_SIZE 4
#elif defined(__MMI_MAINLCD_128X64__)
	#define UI_POPUP_BORDER_SIZE 1
#else
    #define UI_POPUP_BORDER_SIZE 3
#endif

#if defined(__MMI_MAINLCD_320X480__)
#define WGUI_CAT264_DIAL_ICON_SIZE 25
#else
#define WGUI_CAT264_DIAL_ICON_SIZE 20
#endif

#ifdef __MMI_MAINLCD_240X320__
    #define WGUI_POPUP_FTE_AREA_TOP_SPACE  12
    #define WGUI_POPUP_FTE_AREA_BOTTOM_SPACE 12
    #define WGUI_POPUP_FTE_AREA_SPACE 10
#elif defined(__MMI_MAINLCD_320X240__)
    #define WGUI_POPUP_FTE_AREA_TOP_SPACE  10
    #define WGUI_POPUP_FTE_AREA_BOTTOM_SPACE 10
    #define WGUI_POPUP_FTE_AREA_SPACE 5
#else
    #define WGUI_POPUP_FTE_AREA_TOP_SPACE  19
    #define WGUI_POPUP_FTE_AREA_BOTTOM_SPACE 19
    #define WGUI_POPUP_FTE_AREA_SPACE 10
#endif
#if defined(__MMI_MAINLCD_320X480__)
    #define WGUI_POPUP_FTE_AREA_MIN_HEIGHT 132
#else
    #define WGUI_POPUP_FTE_AREA_MIN_HEIGHT 132
#endif
/* Y and Height is computed by the actual height of elements */
#define WGUI_POPUP_FTE_AREA_X 10
#define WGUI_POPUP_FTE_AREA_WIDTH (MAIN_LCD_DEVICE_WIDTH - 2*WGUI_POPUP_FTE_AREA_X)

#define WGUI_POPUP_FTE_BG_X 0
#define WGUI_POPUP_FTE_BG_WIDTH MAIN_LCD_DEVICE_WIDTH

#ifdef __MMI_FWUI_SLIM__
  #ifndef __MMI_UI_POPUP_SLIM__
  #define __MMI_UI_POPUP_SLIM__
  #endif
#endif

/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  wgui_draw_pop_up_screen_background
 * DESCRIPTION
 *  draw the background of popup screns
 * PARAMETERS
 *   x1                            : [IN ] <N/A /> Start x position
 *   y1                            : [IN ] <N/A /> Start y position
 *   x2                            : [IN ] <N/A /> End x position
 *   y2                            : [IN ] <N/A /> End y posityion
 *   f                             : [IN ] <N/A /> Filled pattern
 *   enable_3D_effect              : [IN ] <N/A /> It will no use from 08A
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_draw_pop_up_screen_background(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                UI_filled_area *f,
                MMI_BOOL enable_3D_effect);


/*****************************************************************************
 * FUNCTION
 *  wgui_draw_pop_up_screen_background_style2
 * DESCRIPTION
 *  draw the background of popup screns
 * PARAMETERS
 *   x1                            : [IN ] <N/A /> Start x position
 *   y1                            : [IN ] <N/A /> Start y position
 *   x2                            : [IN ] <N/A /> End x position
 *   y2                            : [IN ] <N/A /> End y posityion
 *   f                             : [IN ] <N/A /> Filled pattern
 *   top                           : [IN ] <N/A /> Whether to display top border
 *   bottom                        : [IN ] <N/A /> Whether to display bottom border
 *   left                          : [IN ] <N/A /> Whether to display left border
 *   right                         : [IN ] <N/A /> Whether to display right border
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_draw_pop_up_screen_background_style2(
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2,
                UI_filled_area *f,
                MMI_BOOL top,
                MMI_BOOL bottom,
                MMI_BOOL left,
                MMI_BOOL right);


/*****************************************************************************
 * FUNCTION
 *  wgui_draw_small_screen_background
 * DESCRIPTION
 *  draw the background of popup screens (use color)
 * PARAMETERS
 *   x1                            : [IN ] <N/A /> Start x position
 *   y1                            : [IN ] <N/A /> Start y position
 *   x2                            : [IN ] <N/A /> End x position
 *   y2                            : [IN ] <N/A /> End y posityion
 *   f                             : [IN ] <N/A /> Filled pattern
 *   enable_3D_effect              : [IN ] <N/A /> It will no use from 08A
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_draw_small_screen_background(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
extern void RedrawCategory62Screen(void);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory62Screen
 * DESCRIPTION
 *  Displays the category62 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat062_img1" />
 * PARAMETERS
 *   message                       : [IN ] (POPUP) Message string
 *   message_icon                  : [IN ] <N/A /> 	 Message icon
 *   history_buffer                : [IN ] <N/A /> 	 History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_62(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory62Screen(STR_ID_CSB_CATEGORY_TEXT, PopupImageGroup[current_popup_index], guiBuffer);
 *     current_popup_index++;
 *     if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
 *     {
 *         current_popup_index = 0;
 *     }
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory62Screen(U16 message, U16 message_icon, U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void ExitCategory62Screen(void);
extern void ExitCategoryPopupScreen(void);

extern void RedrawCategory63Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory63Screen
 * DESCRIPTION
 *  It is a category screen to show a pop-up screen to user.
 *  Its backgroun is the previous screen after grey in the content.
 *  Generally, it will auto disappears in a period of time. App user shuold handle it.
 *  <FTE: support(tool bar is not avaiable) />
 * <img name="wgui_cat062_img1" />
 * PARAMETERS
 *   message                       : [IN ] (POPUP) Message string
 *   message_icon                  : [IN ] <N/A /> 	 Message icon
 *   history_buffer                : [IN ] <N/A /> 	 History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_63(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory63Screen((U8*)get_string(STR_ID_CSB_CATEGORY_TEXT), PopupImageGroup[current_popup_index], guiBuffer);
 *   
 *     current_popup_index++;
 *     if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
 *     {
 *         current_popup_index = 0;
 *     }
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory63Screen(U8 *message, U16 message_icon, U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void ExitCategory63Screen(void);
/* DOM-NOT_FOR_SDK-END */
#if (defined __MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat63_register_pen_down_handler
 * DESCRIPTION
 *  Register application's private pen down handler.
 *  This API should be called after ShowCategory63Screen.
 *  Application should return:  MMI_TRUE if the event is handled.
 *                              MMI_FALSE, otherwise
 *  <FTE: support(tool bar is not avaiable) />
 * PARAMETERS
 *   pen_handler                   : [IN ] <N/A /> pen event handler
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat63_register_pen_down_handler(mmi_pen_handler pen_handler);
#endif

/* DOM-NOT_FOR_SDK-BEGIN */   
extern void RedrawCategory64Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory64Screen
 * DESCRIPTION
 *  Displays the category64 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat062_img1" />
 * PARAMETERS
 *   message                       : [IN ] <POPUP /> Message string
 *   message_icon                  : [IN ] <N/A /> 	 Message icon
 *   history_buffer                : [IN ] <N/A /> 	 History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_64(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory64Screen(STR_ID_CSB_CATEGORY_TEXT, PopupImageGroup[current_popup_index], guiBuffer);
 *     current_popup_index++;
 *     if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
 *     {
 *         current_popup_index = 0;
 *     }
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory64Screen(U16 message, U16 message_icon, U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */   
extern void ExitCategory64Screen(void);
/* DOM-NOT_FOR_SDK-END */
#if (defined __MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat65_register_pen_down_handler
 * DESCRIPTION
 *  register application's private pen down handler
 *  This API should be called after ShowCategory65Screen
 *  Application should return:  MMI_TRUE if the event is handled
 *                              MMI_FALSE, otherwise
 * PARAMETERS
 *   pen_handler                   : [IN ] <N/A /> pen event handler
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat65_register_pen_down_handler(mmi_pen_handler pen_handler);
#endif


/*****************************************************************************
 * FUNCTION
 *  ShowCategory65Screen
 * DESCRIPTION
 *  Displays the category65 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat062_img1" />
 * PARAMETERS
 *   message                       : [IN ] <N/A /> Message string
 *   message_icon                  : [IN ] <N/A /> Message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_65(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory65Screen((U8*)get_string(STR_ID_CSB_CATEGORY_TEXT), PopupImageGroup[current_popup_index], guiBuffer);
 *     current_popup_index++;
 *     if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
 *     {
 *         current_popup_index = 0;
 *     }
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
 
#ifdef __MMI_TOUCH_SCREEN__
extern void ShowCategory65Screen(U8 *message, U16 message_icon, U8 *history_buffer);
#else
#define ShowCategory65Screen(_arg1, _arg2, _arg3) ShowCategory63Screen(_arg1, _arg2, _arg3)
#endif

/* DOM-NOT_FOR_SDK-BEGIN */  
extern void RedrawCategory65Screen(void);
extern void ExitCategory65Screen(void);

extern void ExitCategory121Screen(void);
extern void RedrawCategory121Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory121Screen
 * DESCRIPTION
 *  Displays the category121 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat121_img1" />
 * PARAMETERS
 *   left_softkey                  : [IN ] <LSK /> Left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> Icon for the right softkey
 *   right_softkey                 : [IN ] <RSK /> Right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> Icon for the left softkey
 *   message                       : [IN ] <POPUP />  String to display
 *   message_icon                  : [IN ] <N/A /> Icon to display
 *   history_buffer                : [IN ] <N/A /> History buffer
 *   flag                          : [IN ] <N/A /> Value shpuld be 0/1 -
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_121(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 *     
 *     mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Message");
 * 
 *     ShowCategory121Screen(
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         g_buffer,
 *         ALARM_ANIMATION_INDICATION_IMAGEID,
 *         guiBuffer,
 *         1);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory121Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *message,
                U16 message_icon,
                U8 *history_buffer,
                U8 flag);

/* DOM-NOT_FOR_SDK-BEGIN */  
extern void ShowCategory121Screen_int(
            U16 left_softkey,
            U16 right_softkey,
            U8 *message,
            U16 message_icon,
            U8 *history_buffer,
            U8 flag);
#define ShowCategory121Screen(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8)\
    ShowCategory121Screen_int(_arg1, _arg3, _arg5, _arg6, _arg7, _arg8)
extern void RedrawCategory123Screen(void);
extern void ExitCategory123Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory123Screen
 * DESCRIPTION
 *  Displays the category123 screen with status bar at the top
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat123_img1" />
 * PARAMETERS
 *   title                         : [IN ] <TITLE /> =0 and title_icon=0, then status bar is displayed instead of the title
 *   title_icon                    : [IN ] <N/A /> Title icon
 *   left_softkey                  : [IN ] <LSK /> Left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> Icon for the left softkey
 *   right_softkey                 : [IN ] <RSK /> Right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> Icon for the right softkey
 *   message                       : [IN ] <POPUPCONFIRM /> Notification message
 *   message_icon                  : [IN ] <N/A /> message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_123(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory123Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         STR_ID_CSB_DUMMY_TEXT,
 *         IMG_GLOBAL_QUESTION,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory123Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 message,
                U16 message_icon,
                U8 *history_buffer);
/* DOM-NOT_FOR_SDK-BEGIN */
extern void ShowCategory123Screen_int(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                U16 message,
                U16 message_icon,
                U8 *history_buffer);
#define ShowCategory123Screen(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8,_arg9)\
    ShowCategory123Screen_int(_arg1, _arg2, _arg3, _arg5, _arg7, _arg8,_arg9)

extern void RedrawCategory124Screen(void);
extern void ExitCategory124Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory124Screen
 * DESCRIPTION
 *  Displays the category124 screen with status bar at the top
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat123_img1" />
 * PARAMETERS
 *   title                         : [IN ] <TITLE /> =0 and title_icon=0, then status bar is displayed instead of the title
 *   title_icon                    : [IN ] <N/A /> 
 *   left_softkey                  : [IN ] <LSK /> Left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> Icon for the left softkey
 *   right_softkey                 : [IN ] <RSK /> Right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> Icon for the right softkey
 *   message                       : [IN ] <POPUPCONFIRM /> Notification message
 *   message_icon                  : [IN ] <N/A /> 
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory124Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *message,
                U16 message_icon,
                U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void ShowCategory124Screen_int(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                U8  *message,
                U16 message_icon,
                U8 *history_buffer);
#define ShowCategory124Screen(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8,_arg9)\
    ShowCategory124Screen_int(_arg1, _arg2, _arg3, _arg5, _arg7, _arg8,_arg9)

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory151Screen
 * DESCRIPTION
 *  Displays the category151 screen with status bar at the top
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat151_img1" />
 * PARAMETERS
 *   title                         : [IN ] <TITLE /> =0 and title_icon=0, then status bar is displayed instead of the title
 *   title_icon                    : [IN ] <N/A /> Title icon
 *   left_softkey                  : [IN ] <LSK /> Left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> Icon for the left softkey
 *   right_softkey                 : [IN ] <RSK /> Right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> Icon for the right softkey
 *   message                       : [IN ] <UNLIM /> Notification message
 *   message_icon                  : [?  ] <N/A /> Message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_151(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category151");
 * 
 *     ShowCategory151Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         (PU8) g_buffer,
 *         (PU8) GetImage(IMG_GLOBAL_OK),
 *         guiBuffer);
 *     
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory151Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *message,
                U8 *message_icon,
                U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */  
extern void ShowCategory151Screen_int(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                U8 *message,
                U8 *message_icon,
                U8 *history_buffer);
#define ShowCategory151Screen(_arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8,_arg9)\
    ShowCategory151Screen_int(_arg1, _arg2, _arg3, _arg5, _arg7, _arg8,_arg9)

extern void ExitCategory151Screen(void);
extern void RedrawCategory151Screen(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory162Screen
 * DESCRIPTION
 *  Displays the category162 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat163_img1" />
 * PARAMETERS
 *   left_softkey                  : [IN ] <LSK /> String ID of left softkey
 *   left_softkey_icon             : [IN ] <N/A /> Image ID of left softkey
 *   right_softkey                 : [IN ] <RSK /> String ID of right softkey
 *   right_softkey_icon            : [IN ] <N/A /> Image ID of right softkey
 *   message                       : [IN ] <POPUPCONFIRM /> String ID of message
 *   message_icon                  : [IN ] <N/A /> Image ID of message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_162(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory162Screen(
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         STR_ID_CSB_DUMMY_TEXT,
 *         IMG_GLOBAL_QUESTION,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory162Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 message,
                U16 message_icon,
                U8 *history_buffer);
                
/* DOM-NOT_FOR_SDK-BEGIN */  
extern void ExitCategory162Screen(void);

extern void RedrawCategory163Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory163Screen
 * DESCRIPTION
 *  It is a category screen to show a pop-up screen to user.
 *  Its background is the previous screen after grey in the content.
 *  Generally, it is to let user to confirm a action.
 *  <FTE: support(tool bar is not avaiable) />
 * <img name="wgui_cat163_img1" />
 * PARAMETERS
 *   left_softkey                  : [IN ] <LSK /> Left softkey string
 *   left_softkey_icon             : [IN ] <N/A /> Left softkey icon
 *   right_softkey                 : [IN ] <RSK /> Right softkey string
 *   right_softkey_icon            : [IN ] <N/A /> Right softkey icon
 *   message                       : [IN ] <POPUPCONFIRM /> Message string
 *   message_icon                  : [IN ] <N/A /> Message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_163(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory163Screen(
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         get_string(STR_ID_CSB_DUMMY_TEXT),
 *         IMG_GLOBAL_QUESTION,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory163Screen(
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer);
/* DOM-NOT_FOR_SDK-BEGIN */   
extern void ShowCategory163Screen_int(
                UI_string_type left_softkey,
                UI_string_type right_softkey,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer);
#define ShowCategory163Screen(_arg1,_arg2,_arg3,_arg4,_arg5,_arg6,_arg7)\
    ShowCategory163Screen_int(_arg1,_arg3,_arg5,_arg6,_arg7)
extern void ExitCategory163Screen(void);

extern void RedrawCategory164Screen(void);
/* DOM-NOT_FOR_SDK-END */


typedef enum
{
    NO_POPUP_IMAGE,
    IMAGE_BUFFER,
    IMAGE_BUFFER_WITHOUT_HEADER,
    IMAGE_FILE_PATH,
    IMAGE_TYPE_TOTAL
}wgui_cat_popup_icon_type_enum;

/*****************************************************************************
 * FUNCTION
 *  ShowCategory163Screen_ext
 * DESCRIPTION
 *  Displays the category63 screen, support image buffer and image file
 * PARAMETERS
 *  left_softkey            [IN]  LSK string             
 *  right_softkey           [IN]  RSK string
 *  message                 [IN]  Message string
 *  message_icon_type       [IN]  Message icon type
 *  message_icon            [IN]  Message icon buffer
 *  message_icon_size       [IN]  Message icon buffer size
 *  message_icon_format     [IN]  Message icon format
 *  message_icon_file_path  [IN]  Message icon file name
 *  history_buffer          [IN]  History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory163Screen_ext(
                UI_string_type left_softkey,
                UI_string_type right_softkey,
                UI_string_type message,
                wgui_cat_popup_icon_type_enum message_icon_type,
                PU8 message_icon,
                S32 message_icon_size,
                U8 message_icon_format,
                UI_string_type message_icon_file_path,
                U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory164Screen
 * DESCRIPTION
 *  Displays the category164 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat163_img1" />
 * PARAMETERS
 *   left_softkey                  : [IN ] <LSK /> String ID of left softkey
 *   left_softkey_icon             : [IN ] <N/A /> Image ID of left softkey
 *   right_softkey                 : [IN ] <RSK /> String ID of right softkey
 *   right_softkey_icon            : [IN ] <N/A /> Image ID of right softkey
 *   message                       : [IN ] <POPUPCONFIRM /> String ID of message
 *   message_icon                  : [IN ] <N/A /> Image ID of message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_164(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory164Screen(
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         STR_GLOBAL_SAVE,
 *         IMG_GLOBAL_QUESTION,
 *         NULL);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory164Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 message,
                U16 message_icon,
                U8 *history_buffer);
                
/* DOM-NOT_FOR_SDK-BEGIN */   
extern void ShowCategory164Screen_int(
                U16 left_softkey,
                U16 right_softkey,
                U16 message,
                U16 message_icon,
                U8 *history_buffer);
#define ShowCategory164Screen(_arg1,_arg2,_arg3,_arg4,_arg5,_arg6,_arg7)\
    ShowCategory164Screen_int(_arg1,_arg3,_arg5,_arg6,_arg7)
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  wgui_popup_hide_lsk
 * DESCRIPTION
 *   hide left softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_popup_hide_lsk(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_popup_hide_rsk
 * DESCRIPTION
 *  hide left softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_popup_hide_rsk(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_popup_hide_rsk
 * DESCRIPTION
 *  hide left softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_popup_hide_csk(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_popup_set_softkey_theme
 * DESCRIPTION
 *  set popup softkey theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_popup_set_softkey_theme(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_popup_reset_softkey_theme
 * DESCRIPTION
 *  reset popup softkey theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_popup_reset_softkey_theme(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_popup_set_softkey_flag
 * DESCRIPTION
 *  set popup softkey flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_popup_set_softkey_flag(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_popup_reset_softkey_flag
 * DESCRIPTION
 *  reset popup softkey flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_popup_reset_softkey_flag(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_popup_draw_region_with_background_color
 * DESCRIPTION
 *  clear a region to background color
 * PARAMETERS
 *   x1                            : [IN ] <N/A /> start x position
 *   y1                            : [IN ] <N/A /> start y position
 *   x2                            : [IN ] <N/A /> end x position
 *   y2                            : [IN ] <N/A /> end y position
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_popup_draw_region_with_background_color(S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory165Screen_ext
 * DESCRIPTION
 *  Displays the category165 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat163_img1" />
 * PARAMETERS
 *   left_softkey                  : [IN ] <LSK /> left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> left softkey icon
 *   right_softkey                 : [IN ] <RSK /> right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> right softkey icon
 *   message                       : [IN ] <POPUPCONFIRM /> Message string
 *   message_icon                  : [IN ] <N/A /> message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_165(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory165Screen(
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         get_string(STR_ID_CSB_DUMMY_TEXT),
 *         IMG_GLOBAL_QUESTION,
 *         0);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory165Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer);
/* DOM-NOT_FOR_SDK-BEGIN */  
extern void ShowCategory165Screen_int(
                U16 left_softkey,
                U16 right_softkey,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer);
#define ShowCategory165Screen(_arg1,_arg2,_arg3,_arg4,_arg5,_arg6,_arg7)\
    ShowCategory165Screen_int(_arg1,_arg3,_arg5,_arg6,_arg7)

extern void ExitCategory165Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_popup_update_string
 * DESCRIPTION
 *  Update status of progress for popup screen
 * PARAMETERS
 *  message                       : [IN ] (POPUPCONFIRM) Message string
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat_popup_update_string(UI_string_type message);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory165Screen_ext
 * DESCRIPTION
 *  Displays the category165 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat165_img2" />
 * PARAMETERS
 *   left_softkey                  : [IN ] <LSK /> left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> left softkey icon
 *   right_softkey                 : [IN ] <RSK /> right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> right softkey icon
 *   message                       : [IN ] <POPUPCONFIRM /> Message string
 *   message_icon                  : [IN ] <N/A /> message icon
 *   duration                      : [IN ] <N/A /> count down number
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory165Screen_ext(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                S32 duration,
                U8 *history_buffer);
/* DOM-NOT_FOR_SDK-BEGIN */  
extern void ShowCategory165Screen_ext_int(
                U16 left_softkey,
                U16 right_softkey,
                UI_string_type message,
                U16 message_icon,
                S32 duration,
                U8 *history_buffer);

#define ShowCategory165Screen_ext(_arg1,_arg2,_arg3,_arg4,_arg5,_arg6,_arg7,_arg8)\
    ShowCategory165Screen_ext_int(_arg1,_arg3,_arg5,_arg6,_arg7,_arg8)
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  SetCat165TimerExpireFunc
 * DESCRIPTION
 *  Set popup countdown callback function
 * PARAMETERS
 *   f                             : [IN ] <N/A /> 
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCat165TimerExpireFunc(FuncPtr f);

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)


/*****************************************************************************
 * FUNCTION
 *  UpdateCalibrationScreen
 * DESCRIPTION
 *  Updates Multiline buffer contents before redrawing calibration setting screens.
 * PARAMETERS
 *   image_id                      : [IN ] <N/A /> Image ID
 *   cali_x                        : [IN ] <N/A /> The position of central point of image X(i.e. the calibration point)
 *   cali_y                        : [IN ] <N/A /> The position of central point of image Y
 *  string          							 : [IN](CALIBRIATION_TOP_LEFT_TEXT        
 *                      									CALIBRIATION_BOTTOM_RIGHT_TEXT
 *                      								  CALIBRIATION_CENTER_TEXT)   Calibration string
 *   state                         : [IN ] <N/A /> Casted from PHNSET_CALIBRATION_STATE_ENUM
 *   redraw                        : [IN ] <N/A /> Redraw the category screen
 * RETURNS
 *  void
 * REMARKS
 *  We should avoid overlapping of image and text
 *****************************************************************************/
extern void UpdateCalibrationScreen(U16 image_id, S16 cali_x, S16 cali_y, U16 string, U16 state, MMI_BOOL redraw);

/* DOM-NOT_FOR_SDK-BEGIN */  
extern void ExitCalibrationScreen(void);
extern void RedrawCalibrationScreen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCalibrationScreen
 * DESCRIPTION
 *  Shows Calibration Screen
 *  <img name="wgui_cat_cali_img1" />
 * PARAMETERS
 *   image_id                      : [IN ] <N/A /> Image ID
 *   cali_x                        : [IN ] <N/A /> Calibration position x
 *   cali_y                        : [IN ] <N/A /> Calibration position y
 *   string                        : [IN ] <CALIBRIATION_WELCOME_TEXT /> Calibration string
 *   state                         : [IN ] <N/A /> Format of screen
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCalibrationScreen(U16 image_id, S16 cali_x, S16 cali_y, U16 string, U16 state);



/*****************************************************************************
 * FUNCTION
 *  ShowCategory264Screen
 * DESCRIPTION
 *  show category 264 
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat264_img1" />
 * PARAMETERS
 *   message                       : [IN ] (C264_1) Char array of message
 *   message_icon                  : [IN ] <N/A /> Byte array of message icon
 *   dial_icon                     : [IN ] <N/A /> Image ID of the dial icon
 *   para                          : [IN ] <N/A /> Non-used now
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_264(void)
 * {
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory264Screen(
 *         get_string(STR_ID_CSB_CATEGORY_TEXT),
 *         get_image(IMG_PROFILES_OUTDOOR),
 *         IMG_CSK_DIAL_ICON,
 *         NULL,
 *         NULL);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory264Screen(UI_string_type message, PU8 message_icon, U16 dial_icon, void *para, U8 *history_buffer);
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

#ifdef __MMI_HANDWRITING_PAD__


/*****************************************************************************
 * FUNCTION
 *  UpdateTestControlAreaScreen
 * DESCRIPTION
 *  Updates Multiline buffer contents before redrawing test control area screens.
 * PARAMETERS
 *   pos                           : [IN ] <N/A /> The position of the click point
 *   string                        : [IN ] <N/A /> String to show
 *   state                         : [IN ] <N/A /> Casted from PHNSET_CALIBRATION_STATE_ENUM
 *   redraw                        : [IN ] <N/A /> Redraw the category screen
 * RETURNS
 *  the state in testing control area screen
 * REMARKS
 *  We should avoid overlapping of image and text
 *****************************************************************************/
extern U16 UpdateTestControlAreaScreen(mmi_pen_point_struct pos, U16 string, U16 state, MMI_BOOL redraw);


/* DOM-NOT_FOR_SDK-BEGIN */  
extern void ExitTestControlAreaScreen(void);
extern void RedrawTestControlAreaScreen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowTestControlAreaScreen
 * DESCRIPTION
 *  Shows Control Area Screen
 * PARAMETERS
 *   pos                           : [IN ] <N/A /> position 
 *   string                        : [IN ] <CALIBRIATION_TEST_WELCOME_TEXT /> string to show
 *   state                         : [IN ] <N/A /> state
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowTestControlAreaScreen(mmi_pen_point_struct pos, U16 string, U16 state);

#endif /* __MMI_HANDWRITING_PAD__ */ 



/*****************************************************************************
 * FUNCTION
 *  ShowCategory366Screen
 * DESCRIPTION
 *  Displays the category366 screen, it support update string dynamically. but 
 *   the string position is fixed to area except image.
 *   [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat366_img1" />
 * PARAMETERS
 *   title                         : [IN ] <TITLE /> Title for the screen
 *   title_icon                    : [IN ] <N/A /> Icon shown with the title
 *   left_softkey                  : [IN ] <LSK /> Left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> Icon for the left softkey
 *   right_softkey                 : [IN ] <RSK /> Right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> Icon for the right softkey
 *   message                       : [IN ] <POPUPCONFIRM /> Notification message
 *   message_icon                  : [IN ] <N/A /> Message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_366(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory366Screen(
 *         get_string(STR_ID_CSB_CATEGORY_TEXT),
 *         0,
 *         get_string(STR_ID_CSB_LSK_TEXT),
 *         0,
 *         get_string(STR_ID_CSB_RSK_TEXT),
 *         0,
 *         get_string(STR_GLOBAL_SEARCHING),
 *         PopupImageGroup[current_popup_index],
 *         guiBuffer);
 *     current_popup_index++;
 *     if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
 *     {
 *         current_popup_index = 0;
 *     }
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory366Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        UI_string_type message,
        U16 message_icon,
        U8 *history_buffer);
/* DOM-NOT_FOR_SDK-BEGIN */  
extern void ShowCategory366Screen_int(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        UI_string_type message,
        U16 message_icon,
        U8 *history_buffer);

#define ShowCategory366Screen(_arg1,_arg2,_arg3,_arg4,_arg5,_arg6,_arg7,_arg8,_arg9)\
        ShowCategory366Screen_int(_arg1,_arg2,_arg3,_arg5,_arg7,_arg8,_arg9)
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat366_update_progress_string
 * DESCRIPTION
 *  Update status of progress for category66screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat366_update_progress_string(void);


/* DOM-NOT_FOR_SDK-BEGIN */
#if defined (__MMI_FTE_SUPPORT__)

#define WGUI_CAT6003_X (WGUI_POPUP_FTE_BG_X + UI_POPUP_BORDER_SIZE + 5)
#define WGUI_CAT6003_Y (MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE)
#define WGUI_CAT6003_WIDTH (WGUI_POPUP_FTE_BG_WIDTH - UI_POPUP_BORDER_SIZE*2 - 10)
#define WGUI_CAT6003_HEIGHT (MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2)

#else /* __MMI_FTE_SUPPORT__ */

#if defined(__MMI_MAINLCD_320X480__)
#define WGUI_CAT6003_X (MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE)
#define WGUI_CAT6003_Y (MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE)
#define WGUI_CAT6003_WIDTH (MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2)
#define WGUI_CAT6003_HEIGHT (MMI_POP_UP_SOFTKEY_Y - MMI_POP_UP_DIALOG_Y - UI_POPUP_BORDER_SIZE*2)
#elif defined(__MMI_MAINLCD_128X64__)
#define WGUI_CAT6003_X (0)
#define WGUI_CAT6003_Y (0)
#define WGUI_CAT6003_WIDTH (128)
#define WGUI_CAT6003_HEIGHT (64 - MMI_BUTTON_BAR_HEIGHT)
#else /* LCD size */
#define WGUI_CAT6003_X (MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE)
#define WGUI_CAT6003_Y (MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE)
#define WGUI_CAT6003_WIDTH (MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2)
#define WGUI_CAT6003_HEIGHT (MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2)
#endif /* LCD size */

#endif /* __MMI_FTE_SUPPORT__ */

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat6003_show
 * DESCRIPTION
 *  Displays the category6003 screen, do not support Hisotry, small progress screeen
 *  [FTE]: support(tool bar is not avaiable)
 * PARAMETERS
 *  left_softkey          : [IN]     <LSK /> Left softkey label
 *  right_softkey         : [IN]     <RSK /> Right softkey label
 *  message               : [IN]     <C6003_1 /> Message string
 *  sub_message           : [IN]     <C6003_1 /> Message sub string
 *  percentage            : [IN]     <N/A /> Percentage of progress Ex:80 => 80%
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat6003_show(
                U16 left_softkey,
                U16 right_softkey,
                WCHAR* message,
                WCHAR* sub_message,
                U8 percentage);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat6003_update_all
 * DESCRIPTION
 *  Update the category6003 screen
 * PARAMETERS
 *  message               : [IN]     <C6003_1 /> Message string
 *  sub_message           : [IN]     <C6003_1 /> Message sub string
 *  percentage            : [IN]     <N/A /> Percentage of progress Ex:80 => 80%
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat6003_update_all(
                WCHAR* message,
                WCHAR* sub_message,
                U8 percentage);
/*****************************************************************************
 * FUNCTION
 *  cat66_update_progress_string
 * DESCRIPTION
 *  Update status of progress for category66screen
 *  [IMPORTANT] Please notice that this function will not redo the layout.
 *  [IMPORTANT] The updated string length can't longer than length of the first string.
 *  [IMPORTANT] Otherwise the updated string will be trunacated.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    extern void cat66_update_progress_string(void);
/*****************************************************************************
 * FUNCTION
 *  ShowCategory66Screen
 * DESCRIPTION
 *  Displays the category66 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat066_img1" />
 * PARAMETERS
 *   title                         : [IN ] <TITLE /> Title for the screen
 *   title_icon                    : [IN ] <N/A /> Icon shown with the title
 *   left_softkey                  : [IN ] <LSK /> Left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> Icon for the left softkey
 *   right_softkey                 : [IN ] <RSK /> Right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> Icon for the right softkey
 *   message                       : [IN ] <POPUPCONFIRM /> Notification message
 *   message_icon                  : [IN ] <N/A /> Message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_66(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory66Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         (PU8) GetString(STR_GLOBAL_SEARCHING),
 *         PopupImageGroup[current_popup_index],
 *         guiBuffer);
 *     current_popup_index++;
 *     if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
 *     {
 *         current_popup_index = 0;
 *     }
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
    extern void ShowCategory66Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *message,
                    U16 message_icon,
                    U8 *history_buffer);
    extern void ExitCategory66Screen(void);
/* DOM-NOT_FOR_SDK-BEGIN */  
extern void ShowCategory66Screen_int(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 right_softkey,
                    U8 *message,
                    U16 message_icon,
                    U8 *history_buffer);

#define ShowCategory66Screen(_arg1,_arg2,_arg3,_arg4,_arg5,_arg6,_arg7,_arg8,_arg9)\
        ShowCategory66Screen_int(_arg1,_arg2,_arg3,_arg5,_arg7,_arg8,_arg9)
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory8Screen
 * DESCRIPTION
 *  Displays the category8 screen
 *  [FTE]: support(tool bar is not avaiable)
 * <img name="wgui_cat066_img1" />
 * PARAMETERS
 *   title                         : [IN ] <TITLE /> Title for the screen
 *   title_icon                    : [IN ] <N/A /> Icon shown with the title
 *   left_softkey                  : [IN ] <LSK /> Left softkey label
 *   left_softkey_icon             : [IN ] <N/A /> Icon for the left softkey
 *   right_softkey                 : [IN ] <RSK /> Right softkey label
 *   right_softkey_icon            : [IN ] <N/A /> Icon for the right softkey
 *   message                       : [IN ] <POPUPCONFIRM /> Notification message
 *   message_icon                  : [IN ] <N/A /> Message icon
 *   history_buffer                : [IN ] <N/A /> History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_8(void)
 * {
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory8Screen(
 *         STR_ID_CSB_CATEGORY_TEXT,
 *         0,
 *         STR_ID_CSB_LSK_TEXT,
 *         0,
 *         STR_ID_CSB_RSK_TEXT,
 *         0,
 *         STR_ID_CSB_DUMMY_TEXT,
 *         IMG_GLOBAL_WARNING,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * 
 * }
 * </code>
 *****************************************************************************/
    extern void ShowCategory8Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message,
                    U16 message_icon,
                    U8 *history_buffer);
/* DOM-NOT_FOR_SDK-BEGIN */  
    extern void ShowCategory8Screen_int(
                        U16 title,
                        U16 title_icon,
                        U16 left_softkey,
                        U16 right_softkey,
                        U16 message,
                        U16 message_icon,
                        U8 *history_buffer);
    
#define ShowCategory8Screen(_arg1,_arg2,_arg3,_arg4,_arg5,_arg6,_arg7,_arg8,_arg9)\
        ShowCategory8Screen_int(_arg1,_arg2,_arg3,_arg5,_arg7,_arg8,_arg9)
/* DOM-NOT_FOR_SDK-END */

    extern void ShowCategory208Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S8 *message,
                    U16 message_icon,
                    U8 *history_buffer);
/* DOM-NOT_FOR_SDK-BEGIN */  
    extern void ShowCategory208Screen_int(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 right_softkey,
                    S8 *message,
                    U16 message_icon,
                    U8 *history_buffer);
    
#define ShowCategory208Screen(_arg1,_arg2,_arg3,_arg4,_arg5,_arg6,_arg7,_arg8,_arg9)\
        ShowCategory208Screen_int(_arg1,_arg2,_arg3,_arg5,_arg7,_arg8,_arg9)
/* DOM-NOT_FOR_SDK-END */

extern void wgui_popup_enable_clear_background(void);
extern void wgui_popup_disable_clear_background(void);
extern MMI_BOOL wgui_popup_is_enable_clear_background(void);

#ifdef __ATV_SMS_SUPPORT__  
extern void wgui_cat9009_show(
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        UI_string_type message,
        U16 message_icon,
        U8 *history_buffer);
#endif

#ifdef __OP01__
#ifdef __MMI_MAINLCD_320X480__
#define WGUI_CAT3010_POPUP_Y_SHIFT 25
#else
#define WGUI_CAT3010_POPUP_Y_SHIFT 5
#endif
typedef void(* wgui_cat3010_op01_state_callback_func_type)(MMI_BOOL isChecked);
extern void wgui_cat3010_op01_show(
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        UI_string_type message1,
		UI_string_type message2,
		wgui_cat3010_op01_state_callback_func_type state_callback,
		MMI_BOOL isChecked,
        U8 *history_buffer);
#endif
#endif /* WGUI_CATEGORIES_POPUP_H */ 


