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
 *  wgui_categories_CM.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Call Management related categories.
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
#ifndef WGUI_CATEGORIES_CM_H
#define WGUI_CATEGORIES_CM_H

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_typedef.h"
#include "MMIDataType.h"
#include "gdi_lcd_config.h"
#include "gdi_include.h"
#include "wgui.h"
#include "kal_general_types.h"
#include "ImeGprot.h"
#include "gui_data_types.h"
#include "custom_mmi_default_value.h"
#include "MMI_features.h"
#include "wgui_tab_bars.h"

/* DOM-NOT_FOR_SDK-BEGIN */
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define DURATION_CM_HEIGHT          15
#define SHOW_DURATION               1
#define NO_DURATION                 0
/* DOM-NOT_FOR_SDK-END */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__MMI_PHB_CALLER_VIDEO__)
#define __CATE_CM_VIDEO_PLAY_SUPPORT__
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

#if defined(__MMI_PHB_CALLER_RES__)
#define __CATE_CM_PHB_CALLER_RES__
#endif /*__MMI_PHB_CALLER_RES__*/

#if defined(__LCM_SCANLINE_ROTATION_SUPPORT__)	\
    && defined(__MMI_WALLPAPER_ON_BOTTOM__) 	\
	&& (defined(__CATE_CM_VIDEO_PLAY_SUPPORT__) || defined(__MMI_SWFLASH__))	\
	&& (!defined(__MMI_FTE_SUPPORT__) && !defined(WGUI_CATCALL_STYLE_2))
#ifndef __MMI_CATEGORY_CM_SCANLINE__
#define __MMI_CATEGORY_CM_SCANLINE__
#endif /* __MMI_CATEGORY_CM_SCANLINE__ */
#endif

#ifdef __MMI_CAT116_SUPPORT__
#if defined(__MMI_TOUCH_SCREEN__)
#define __WGUI_CATE_SUPPORT_SEND_KEY__
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_CAT116_SUPPORT__ */


#if defined(__MMI_FTE_SUPPORT__) && (!defined(__MMI_TOUCH_DIAL_SCREEN__)||!defined(__MMI_TOUCH_SCREEN__))
#define __WGUI_CATE_FTE_KEY_ONLY__
#endif /* __MMI_FTE_SUPPORT__ && !__MMI_TOUCH_DIAL_SCREEN__ */

#if !defined(__MMI_EDITOR_DIALER_SUPPORT__)
#define __CAT16_MULTIEDITOR_STYLE__
#endif /*__MMI_EDITOR_DIALER_SUPPORT__*/

#if !defined(__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__)
#define __WGUI_CM_FTE_SLIM__
#endif /*__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__*/

#if defined(__SLIM_UCM__)
#define __WGUI_CATE_FTE_RES_SLIM__
#endif /*__SLIM_UCM__*/

#if defined(__MMI_MAINLCD_128X128__)
#define __WGUI_CATE_CM_MOMT_COMMON_STYLE__
#endif /*__MMI_MAINLCD_128X128__*/
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
/* MOMT call screen resource type */
typedef enum
{
    WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID = 0,   /* image resource */
    WGUI_CATE_MOMT_RES_TYPE_VIDEO_ID,       /* video resource */
    WGUI_CATE_MOMT_RES_TYPE_SWFLASH_ID,     /* swflash resource */
    WGUI_CATE_MOMT_RES_TYPE_IMAGE_FILE,     /* image file */
    WGUI_CATE_MOMT_RES_TYPE_VIDEO_FILE,     /* video file */
    WGUI_CATE_MOMT_RES_TYPE_SWFLASH_FILE,   /* swflash file */
    WGUI_CATE_MOMT_RES_TYPE_AVATAR_FILE     /* avatar file */
} wgui_cate_momt_res_type_enum;


#if defined(__MMI_FTE_SUPPORT__)
/* structure for FTE call related screen icon bar item */
typedef struct
{
    UI_string_type label;   /* string, MSLT region ID: C017_2. if unlock item, C017_3 */
    UI_image_type icon;     /* icon image */
    UI_image_type up;       /* item background up state image */
    UI_image_type down;     /* item background down state image */
    UI_image_type disable;  /* item background disable state image */
    FuncPtr handler;        /* item handler while this item is selected */
} wgui_catcall_fte_iconbar_item_struct;

/* notification handler while the call related screen is touched or released */
typedef void (*wgui_catcall_fte_is_screen_touch_handler)(MMI_BOOL is_touched);
#endif /* defined(__MMI_FTE_SUPPORT__) */


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/* Category 16 */
#if ((!defined ( __MMI_MAINLCD_128X128__ ) && !defined ( __MMI_MAINLCD_128X160__ )) && defined(__GDI_MEMORY_PROFILE_2__))
#if !defined(__MMI_TOUCH_DIAL_SCREEN__)
#if defined(__MMI_ALPHA_BLENDING__)
/*****************************************************************************
 * FUNCTION
 *  cat16_swflash_callback
 * DESCRIPTION
 *  swflash callback
 * PARAMETERS
 *  offset_x    :  [IN] (N/A)        offset x
 *  offset_y    :  [IN] (N/A)        offset y
 *  width       :  [IN] (N/A)        width
 *  height      :  [IN] (N/A)        height
 * RETURNS
 *  void
 *****************************************************************************/
void cat16_swflash_callback(S32 offset_x, S32 offset_y, S32 width, S32 height);
#endif /* defined(__MMI_ALPHA_BLENDING__) */
#endif /* !defined(__MMI_TOUCH_DIAL_SCREEN__) */
#endif /* (!defined ( __MMI_MAINLCD_128X128__ ) && !defined ( __MMI_MAINLCD_128X160__ )) && defined (__GDI_MEMORY_PROFILE_2__) ) */

/* DOM-NOT_FOR_SDK-BEGIN */
#if defined(__CATE_CM_VIDEO_PLAY_SUPPORT__) || defined(__MMI_SWFLASH__)
#define SCRMEM_CATMOMT_POOL_SIZE ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL + 7) >> 3)
#else /* __CATE_CM_VIDEO_PLAY_SUPPORT__ || __MMI_SWFLASH__ */
#define SCRMEM_CATMOMT_POOL_SIZE 0
#endif /* defined(__CATE_CM_VIDEO_PLAY_SUPPORT__) || defined(__MMI_SWFLASH__) */

extern void RedrawCategory16Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*******************************************************************************************
  * FUNCTION
  * ShowCategory16Screen
  * Description
  * Displays the category16 screen(Dialing Screen)
  * 
  * <img name="wgui_cat016_img1" />
  * 128x128
  * 
  * <img name="wgui_cat016_img2" />
  * 128x160 with touch
  * 
  * <img name="wgui_cat016_img3" />
  * 176x220 with touch
  * 
  * <img name="wgui_cat016_img4" />
  * 240x320
  * 
  * <img name="wgui_cat016_img5" />
  * 240x320 with touch
  * 
  * Parameters
  * left_softkey :        [IN] (LSK) Left softkey label
  * left_softkey_icon :   [IN] (N/A) Icon for the Left softkey
  * right_softkey :       [IN] (RSK) Right softkey label
  * right_softkey_icon :  [IN] (N/A) Icon for the right softkey
  * Buffer :              [IN] (N/A) Message string
  * BufferLength :        [IN] (N/A) Length of buffer
  * history_buffer :      [IN] (N/A) History buffer
  * Returns
  *  void
  * Example
  * <code>
  * void EntryScreen_16(void)
  * {
  *    U8 *guiBuffer = NULL;
  * 
  *    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  * 
  *    memset(g_buffer, NULL, MAX_LOCAL_BUFFER);
  * 
  *      ShowCategory16Screen(STR_ID_CSB_LSK_TEXT,
  *          NULL,
  *          STR_ID_CSB_RSK_TEXT,
  *          NULL,
  *          (U8*) g_buffer,
  *          G_BUF_STRING_LEN,
  *          guiBuffer);
  * }
  * </code>                                                                                 
  *******************************************************************************************/
extern void ShowCategory16Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *Buffer,
                U32 BufferLength,
                U8 *history_buffer);

extern void ShowCategory16Screen_int(
                U16 left_softkey,
                U16 right_softkey,
                U8 *Buffer,
                U32 BufferLength,
                U8 *history_buffer);

#define ShowCategory16Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6)	\
	ShowCategory16Screen_int(_arg0, _arg2, _arg4, _arg5, _arg6)
/*****************************************************************************
 * FUNCTION
 *  SetCategory16RightSoftkeyFunction
 * DESCRIPTION
 *  set the RSK function of dialing scrren.
 * PARAMETERS
 *  f      : [IN] (N/A)        Function pointer
 *  k      : [IN] (N/A)        Event type
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory16RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);

/*****************************************************************************
 * FUNCTION
 *  RegisterCategory16NavigationKeys
 * DESCRIPTION
 *  Register the keys ofdialing scrren.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void RegisterCategory16NavigationKeys(void);


#if defined(__MMI_FTE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  wgui_catcall_fte_setup
 * DESCRIPTION
 *  used "before" show category function
 *  setup icon bar for category 17, 403
 * PARAMETERS
 *  number_of_items     : [IN] (N/A) Number of icon bar items
 *  items               : [IN] (N/A) Item array
 *  unlock_item         : [IN] (N/A) Unlock button item
 *  is_touch_handler    : [IN] (N/A) Handler to handler whether the whole screen is touched
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_catcall_fte_setup(
                S32 number_of_items,
                wgui_catcall_fte_iconbar_item_struct *items,
                wgui_catcall_fte_iconbar_item_struct unlock_item,
                wgui_catcall_fte_is_screen_touch_handler is_touch_handler
                );

#ifdef __WGUI_CM_FTE_SLIM__
extern void wgui_catcall_fte_setup_ex(
                wgui_catcall_fte_iconbar_item_struct unlock_item,
                wgui_catcall_fte_is_screen_touch_handler is_touch_handler
                );
#endif /*__WGUI_CM_FTE_SLIM__*/
/*****************************************************************************
 * FUNCTION
 *  wgui_catcall_iconbar_set_item
 * DESCRIPTION
 *  used "after" show category function
 *  update the content of the icon bar in the current active for category 17, 403
 * PARAMETERS
 *  idx                         : [IN] (N/A) Index of which item to update
 *  label                       : [IN] (C017_2) String
 *  icon                        : [IN] (N/A) Icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_catcall_fte_iconbar_set_item(
                S32 idx,
                UI_string_type label,
                UI_image_type icon);


/*****************************************************************************
 * FUNCTION
 *  wgui_catcall_fte_iconbar_enable_item
 * DESCRIPTION
 *  used "after" show category function
 *  hide / display one item of the icon bar in the current active for category 17, 403
 * PARAMETERS
 *  idx                         : [IN] (N/A) Index of which button to update
 *  is_disable                  : [IN] (N/A) Whether to hide this button
 *  label                       : [IN] (C017_2) String
 *  icon                        : [IN] (N/A) Icon
 * RETURNS
 *  void
 *****************************************************************************/
extern void  wgui_catcall_fte_iconbar_enable_item(
                S32 idx,
                MMI_BOOL is_disable,
                UI_string_type label,
                UI_image_type icon);


/*****************************************************************************
 * FUNCTION
 *  wgui_catcall_fte_lock_screen
 * DESCRIPTION
 *  used "after" show category function
 *  whether to lock for category 17, 403
 * PARAMETERS
 *  is_lock_screen              : [IN] (N/A) True for lock, false for unlock
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_catcall_fte_lock_screen(MMI_BOOL is_lock_screen);

#endif /* defined(__MMI_FTE_SUPPORT__) */


/*******************************************************************************************
  * FUNCTION
  * ShowCategory17Screen
  * Description
  * Show category ShowCategory17Screen screen.
  * 
  * <img name="wgui_cat017_img1" />
  * 128x128
  * 
  * <img name="wgui_cat017_img2" />
  * 240x320
  * 
  * Parameters
  * title_id :                [IN] (TITLE)
  * left_softkey :            [IN] (LSK) Lsk string id
  * left_softkey_icon :       [IN] (N/A) Lsk image id
  * right_softkey :           [IN] (RSK) Rsk string id
  * right_softkey_icon :      [IN] (N/A) Rsk image id
  * NotificationStringId :    [IN] (C017_1) Notification string,
  *                           notification string
  * NameOrNumber :            [IN] (UNLIM) Name or number text, name or
  *                           number text
  * IP_Number :               [IN] (UNLIM) String of IP number
  * CallLine :                [IN] (N/A) Image ID of line indicator(Zero for
  *                           not displaying line indicators)
  * default_image_id :        [IN] (N/A) Image ID of default displayed image
  * resource_id :             [IN] (N/A) Image ID of displayed resource (if
  *                           any)
  * resource_filename :       [IN] (N/A) String of displayed iamge filename
  *                           (if any)
  * resource_type :           [IN] (N/A) Enum value of which resource type
  * repeat_count :            [IN] (N/A) Repeat count, used for video only,
  *                           0 means infiniate loop
  * is_visaul_update :        [IN] (N/A) Update video's visual
  * is_aud_enable :           [IN] (N/A) Audio of animation
  * is_play_aud_when_start :  [IN] (N/A) Play video at start
  * history_buffer :          [IN] (N/A) History buffer
  * Returns
  *  void
  * Example
  * <code>
  * void EntryScreen_17(void)
  * {
  *    U8 *guiBuffer = NULL;
  *    U8 display_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;
  * 
  *    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  * 
  *    AnsiiToUnicodeString((PS8) temp_buf, (PS8) &quot;JOE17&quot;);
  * 
  *    ShowCategory17Screen(
  *          0,
  *          STR_ID_CSB_LSK_TEXT,
  *          NULL,
  *          STR_ID_CSB_RSK_TEXT,
  *          NULL,
  *          NULL,
  *          temp_buf,
  *          NULL,
  *          IMG_CM_ICON_LINE2,
  *          IMG_PHB_DEFAULT,
  *          IMG_PHB_DEFAULT,
  *          NULL,
  *          display_type,
  *          0,
  *          FALSE,
  *          FALSE,
  *          FALSE,
  *          (U8*) guiBuffer);
  * }
  * </code>                                                                                 
  *******************************************************************************************/
extern void ShowCategory17Screen(
                U16 title_id,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 NotificationStringId,
                PU8 NameOrNumber,
                PU8 IP_Number,
                U16 CallLine,
                U16 default_image_id,
                U16 resource_id,
                CHAR* resource_filename,
                wgui_cate_momt_res_type_enum resource_type,
                U16 repeat_count,
                BOOL is_visaul_update,
                BOOL is_aud_enable,
                BOOL is_play_aud_when_start,
                PU8 history_buffer);

extern void ShowCategory17Screen_int(
                U16 title_id,
                U16 left_softkey,
                U16 right_softkey,
                U16 NotificationStringId,
                PU8 NameOrNumber,
                PU8 IP_Number,
                U16 CallLine,
                U16 default_image_id,
                U16 resource_id,
                CHAR* resource_filename,
                wgui_cate_momt_res_type_enum resource_type,
                U16 repeat_count,
                BOOL is_visaul_update,
                BOOL is_aud_enable,
                BOOL is_play_aud_when_start,
                PU8 history_buffer);

#define ShowCategory17Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, \
	        _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)	\
	ShowCategory17Screen_int(_arg0, _arg1, _arg3, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, \
	        _arg11, _arg12, _arg13, _arg14, _arg15, _arg16, _arg17)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat017_is_media_played
 * DESCRIPTION
 *  Check whether video or swflash is playing now
 *  This function MUST BE after ShowCategory17Screen
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL wgui_cat017_is_media_played(void);

/*****************************************************************************
 * FUNCTION
 *  StopCategory17Video
 * DESCRIPTION
 *  Stop Category 17 screen's video clip.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void StopCategory17Video(void);

/*****************************************************************************
 * FUNCTION
 *  DisableCategory17Audio
 * DESCRIPTION
 *  Disable Category 17 screen video' audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void DisableCategory17Audio(void);

/*****************************************************************************
 * FUNCTION
 *  EnableCategory17Audio
 * DESCRIPTION
 *  Enable Category 17 screen video' audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void EnableCategory17Audio(void);

/*****************************************************************************
 * FUNCTION
 *  MOMTHideAnimation
 * DESCRIPTION
 *  Stop and grey MOMT Call image files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void MOMTHideAnimation(void);
 
/*****************************************************************************
 * FUNCTION
 *  IsCategory17VideoValid
 * DESCRIPTION
 *  Call this function to check if Cat17 show video success or not
 *  This function MUST BE after ShowCategory17Screen
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL IsCategory17VideoValid(void);

/*****************************************************************************
 * FUNCTION
 *  IsCategory17SWFlashValid
 * DESCRIPTION
 *  Call this function to check if Cat17 show swflash success or not
 *  This function MUST BE after ShowCategory17Screen
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL IsCategory17SWFlashValid(void);

/*****************************************************************************
 * FUNCTION
 *  IsCategory17AvatarValid
 * DESCRIPTION
 *  Call this function to check if Cat17 show avatar success or not
 *  This function MUST BE after ShowCategory17Screen
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL IsCategory17AvatarValid(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_catcall_set_button
 * DESCRIPTION
 *  for application to set the string and function of calling button
 * PARAMETERS
 *  str    : [IN]    string pointer
 *  func   : [IN] (N/A)   function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_catcall_set_button(UI_string_type str, FuncPtr func);

/*****************************************************************************
 * FUNCTION
 *  wgui_catcall_set_number_type_icons
 * DESCRIPTION
 *  set number type icons for call-related category screens, 17 and 18
 * PARAMETERS
 *  icons   : [IN]  arrays of image resource IDs, currently only one item in the array for 17 and 18
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_catcall_set_number_type_icons(U16 *icons);

/*******************************************************************************************
  * FUNCTION
  * ShowCategory18Screen
  * Description
  * Show Cateogry 18, for MO MT call. for call disconnecting screen
  * 
  * <img name="wgui_cat018_img1" />
  * 128x128
  * 
  * <img name="wgui_cat018_img2" />
  * 240x320
  * 
  * Parameters
  * title_id :              [IN] (TITLE)
  * left_softkey :          [IN] (LSK) Lsk string id
  * left_softkey_icon :     [IN] (N/A) Lsk image id
  * right_softkey :         [IN] (RSK) Rsk string id
  * right_softkey_icon :    [IN] (N/A) Rsk image id
  * NotificationStringId :  [IN] (C018_1) Notification string, notification
  *                         string
  * NameOrNumber :          [IN] (UNLIM) Name or number text, name or number
  *                         text
  * IP_Number :             [IN] (UNLIM) String of IP number
  * CallLine :              [IN] (N/A) Image ID of line indicator(Zero for
  *                         not displaying line indicators)
  * image_id :              [IN] (N/A) Resource to be displayed (ID)
  * image_filename :        [IN] (N/A) Resource to be displayed (file)
  * isDisconnecting :       [IN] (N/A) Whether the call is disconnecting
  * history_buffer :        [IN] (N/A) History buffer
  * Returns
  *  void
  * Example
  * <code>
  * void EntryScreen_18(void)
  * {
  *    U8 *guiBuffer = NULL;
  * 
  *    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  * 
  *    AnsiiToUnicodeString((PS8) temp_buf, (PS8) &quot;MAC18&quot;);
  *    ShowCategory18Screen(
  *       0,
  *       STR_ID_CSB_LSK_TEXT,
  *       NULL,
  *       STR_ID_CSB_RSK_TEXT,
  *       NULL,
  *       0,
  *       temp_buf,
  *       NULL,
  *       IMG_CM_ICON_LINE2,
  *       IMG_PHB_DEFAULT,
  *       NULL,
  *       FALSE,
  *       (U8*) guiBuffer);
  * }
  * </code>                                                                                 
  *******************************************************************************************/
extern void ShowCategory18Screen(
                U16 title_id,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 NotificationStringId,
                PU8 NameOrNumber,
                PU8 IP_Number,
                U16 CallLine,
                U16 image_id,
                CHAR* image_filename,
                MMI_BOOL isDisconnecting,
                PU8 history_buffer);

/*******************************************************************************************
  * FUNCTION
  * ShowCategory19Screen
  * Description
  * Displays the active calls screen
  * 
  * <img name="wgui_cat019_img1" />
  *
  * PARAMETERS
  *  left_softkey            [IN] (LSK)        Left softkey label
  *  left_softkey_icon       [IN] (N/A)        Icon for the Left softkey
  *  right_softkey           [IN] (RSK)        Right softkey label
  *  right_softkey_icon      [IN] (N/A)        Icon for the right softkey
  *  number_of_calls         [IN] (N/A)        Number of active calls
  *  CallList                [IN] (C019_1)     String array for identifying the calls
  *  CallLines               [IN] (N/A)        Image ID array of line indicator, Zero array for not displaying line indicators
  *  CallStates              [IN] (N/A)        Image ID array of call state
  *  CurrCallTime            [IN] (N/A)        Current call duration timer structure
  *  highlighted_item        [IN] (N/A)        Current highlighted item
  *  history_buffer          [IN] (N/A)        History
  * RETURNS
  *  void
  * Example
  * <code>
  * void EntryScreen_19(void)
  * {
  *    MYTIME time;
  *    U8 *guiBuffer = NULL;
  *    S32    index;
  *    U8 *itemlist[6];
  *    U16    nImgIds[6];
  *    U16 callstates[2];
  * 
  *    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  * 
  *    callstates[0] = IMG_CM_ICON_LINE2;
  *    callstates[1] = IMG_CM_ICON_LINE1;
  * 
  *    for (index = 0; index &lt; 6; index++)
  *    {
  *        itemlist[index] = (U8*) GetString(STR_ID_CSB_MENUITEM1_TEXT + index);
  *        nImgIds[index] = 19210;
  *    }
  * 
  *    GetDateTime(&amp;time);
  * 
  *    ShowCategory19Screen(STR_ID_CSB_LSK_TEXT,
  *       NULL,
  *       STR_ID_CSB_RSK_TEXT,
  *       NULL,
  *       index ,
  *       itemlist,
  *       callstates,
  *       nImgIds,
  *       (UI_time*)&amp;time,
  *       0,
  *       guiBuffer);
  * }
  * </code>                                                                                 
  *******************************************************************************************/
extern void ShowCategory19Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_calls,
                U8 **CallList,
                U16 *CallLines,
                U16 *CallStates,
                MYTIME *CurrCallTime,
                S32 highlighted_item,
                U8 *history_buffer);

/* caller media information sturct */
typedef struct
{
    CHAR* resource_filename;                      /* from file */
    U16 resource_id;                            /* from resource */
    wgui_cate_momt_res_type_enum resource_type; /* resource type */
} WGUI_CATCALL_CALLER_MEDIA_INFO;

/*****************************************************************************
 * FUNCTION
 *  ShowCategory20Screen
 * DESCRIPTION
 *  Displays the single active call screen
 *
 * <img name="wgui_cat020_img1" />
 * PARAMETERS
 *  left_softkey           : [IN] (LSK)        Left softkey label
 *  left_softkey_icon      : [IN] (N/A)        Icon for the Left softkey
 *  right_softkey          : [IN] (RSK)        Right softkey label
 *  right_softkey_icon     : [IN] (N/A)        Icon for the right softkey
 *  CallType               : [IN] (N/A)        Call type string, currently not available
 *  NameOrNumber           : [IN] (UNLIM)      String for identifying the call
 *  CallDuration           : [IN] (N/A)        Call duration timer structure
 *  CallLine               : [IN] (N/A)        Image ID of line indicator(Zero for not displaying line indicators)
 *  CallState              : [IN] (N/A)        Image ID of call state
 *  CallerMedia            : [IN] (N/A)        Caller image, if NULL, use CallState as default, currently only for HVGA category call style 2
 *  isDisconnecting        : [IN] (N/A)        Whether the call is disconnecting
 *  history_buffer         : [IN] (N/A)        History buffer
 * RETURNS
 *  void
 * EXAMPLE
 *<code>
 * void EntryScreen_20(void)
 * {
 *   MYTIME time;
 *   U8 *guiBuffer = NULL;
 *   EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);    
 *   
 *   memset(g_buffer, NULL, MAX_LOCAL_BUFFER);
 *   AnsiiToUnicodeString((PS8) g_buffer, (PS8) "Category20");
 *   
 *   GetDateTime(&time);
 *
 *   ShowCategory20Screen(STR_ID_CSB_LSK_TEXT,
 *       NULL, 
 *       STR_ID_CSB_RSK_TEXT,
 *       NULL, 
 *       (U8*) g_buffer,
 *       (UI_time*)&time,
 *       IMG_CM_ICON_LINE1,
 *       NULL,
 *       MMI_TRUE,
 *       guiBuffer);
 *
 * }
 *</code>
 *****************************************************************************/
extern void ShowCategory20Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *CallType,
                U8 *NameOrNumber,
                MYTIME *CurrCallTime,
                U16 CallLine,
                U16 CallState,
                WGUI_CATCALL_CALLER_MEDIA_INFO *CallerMedia,
                MMI_BOOL isDisconnecting,
                U8 *history_buffer);

extern void ShowCategory20Screen_int(
                U16 left_softkey,
                U16 right_softkey,
                U8 *CallType,
                U8 *NameOrNumber,
                MYTIME *CurrCallTime,
                U16 CallLine,
                U16 CallState,
                WGUI_CATCALL_CALLER_MEDIA_INFO *CallerMedia,
                MMI_BOOL isDisconnecting,
                U8 *history_buffer);

#define ShowCategory20Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)	\
	ShowCategory20Screen_int(_arg0, _arg2, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat020_update_duration
 * DESCRIPTION
 *  update the duration of category 20, for application usage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat020_update_duration(void);

#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
void SetDialingKeypadEmergencyFunckey(MMI_BOOL IsEmergency);

/*****************************************************************************
 * FUNCTION
 *  SetDialingKeypadCallHandler
 * DESCRIPTION
 *  Set hte callback function for Dialing Icon of touch dialing screen
 *  This depends on the compile option, __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__.
 *  While this option is on, in touch dialing keypad, there will be two or more function buttons to use.
 * PARAMETERS
 *  handler    : [IN] (N/A)        keypad call handle function
 * RETURNS
 *  void
 *****************************************************************************/
void SetDialingKeypadCallHandler(void (*handler) (void));

#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
/*****************************************************************************
 * FUNCTION
 *  SetDialingKeypadCall2Handler
 * DESCRIPTION
 *  Set hte callback function for Dialing Icon 2 of touch dialing screen
 *  This depends on the compile option, __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__.
 *  While this option is on, in touch dialing keypad, there will be two or more function buttons to use.
 * PARAMETERS
 *  handler    : [IN] (N/A)        keypad call handle function
 * RETURNS
 *  void
 *****************************************************************************/
void SetDialingKeypadCall2Handler(void (*handler) (void));
#endif /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */


/*****************************************************************************
 * FUNCTION
 *  SetDialingKeypadVideoHandler
 * DESCRIPTION
 *  Set hte callback function for Video call Icon of touch dialing screen
 *  This depends on the compile option, __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__.
 *  While this option is on, in touch dialing keypad, there will be two or more function buttons to use.
 * PARAMETERS
 *  handler    : [IN] (N/A)        keypad callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetDialingKeypadVideoHandler(void (*handler) (void));


/*****************************************************************************
 * FUNCTION
 *  SetDialingKeypadPhonebookHandler
 * DESCRIPTION
 *  Set hte callback function for Phonebook Icon of touch dialing screen
 *  This depends on the compile option, __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__.
 *  While this option is on, in touch dialing keypad, there will be two or more function buttons to use.
 * PARAMETERS
 *  handler    : [IN] (N/A)        keypad callback function
 * RETURNS
 *  void
 *****************************************************************************/
void SetDialingKeypadPhonebookHandler(void (*handler) (void));
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 

/*****************************************************************************
 * FUNCTION
 *  SetDialingInputCursorToFirst
 * DESCRIPTION
 *  set dialer input region cursor to before first char.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetDialingInputCursorToFirst(void);


/* DOM-NOT_FOR_SDK-BEGIN */
#if defined(__MMI_MAINLCD_320X240__) && defined(__MMI_FTE_SUPPORT__)
#define WGUI_CAT403_IMG_Y   (MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT)
#elif !defined(__MMI_MAINLCD_128X64__)
#define WGUI_CAT403_IMG_Y   (MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT)
#else /* __MMI_MAINLCD_128X64__ */
#define WGUI_CAT403_IMG_Y	(MMI_STATUS_BAR_HEIGHT)
#endif /* __MMI_MAINLCD_128X64__ */
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_240X400__)
#define WGUI_CAT403_IMG_H   22
#elif defined(__MMI_MAINLCD_128X64__)
#define WGUI_CAT403_IMG_H	MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT
#elif defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__)
#define WGUI_CAT403_IMG_H	22
#else
#define WGUI_CAT403_IMG_H   MMI_MENUITEM_HEIGHT
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_240X400__) */
#define WGUI_CAT403_MENU_Y  (WGUI_CAT403_IMG_Y + WGUI_CAT403_IMG_H)
/* DOM-NOT_FOR_SDK-END */

/*******************************************************************************************
  * FUNCTION
  * ShowCategory403Screen
  * Description
  * Show category 403 screen(VoIP Active Call Screen)
  * 
  * <img name="wgui_cat403_img1" />
  * Parameters
  * title :               [IN] (TITLE) Title for the screen
  * title_icon :          [IN] (N/A) Icon shown with the title
  * left_softkey :        [IN] (LSK) Left softkey label
  * left_softkey_icon :   [IN] (N/A) Icon for the Left softkey
  * right_softkey :       [IN] (RSK) Right softkey label
  * right_softkey_icon :  [IN] (N/A) Icon for the right softkey
  * n_tabs :              [IN] (N/A) Total number of tabs
  * highlighted_tab :     [IN] (N/A) The index of highlighted tab
  * tab_items :           [IN] (TAB) Array of tab item data
  * CallDuration :        [IN] (N/A) Duration time
  * list_of_items :       [IN] (C403_1) Array of list menu item data
  * list_of_icons :       [IN] (N/A) Array of list menu item icon
  * number_of_items :     [IN] (N/A) Total number of menu items
  * highlighted_item :    [IN] (N/A) Index of highlighted menu item
  * history_buffer :      [IN] (N/A) history buffer
  * Returns
  *  void
  * Example
  * <code>
  * void EntryScreen_403(void)
  * {
  *    tab_bar_item_type MMI_tab_bar_items[2];
  *    MYTIME currTime;
  *    U8 *guiBuffer = NULL;
  *    U8 *itemlist[3];
  *    U8 index;
  * 
  *    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  * 
  *    MMI_tab_bar_items[0].icon = (U8*) GetImage(gIndexIconsImageList[0]);
  *    MMI_tab_bar_items[1].icon = (U8*) GetImage(gIndexIconsImageList[1]);
  *    MMI_tab_bar_items[0].text = NULL;
  *    MMI_tab_bar_items[1].text = NULL;
  *    MMI_tab_bar_items[0].flags = 0;
  *    MMI_tab_bar_items[1].flags = 0;
  * 
  *    for (index = 0; index &lt; 3; index++)
  *    {
  *        itemlist[index] = (U8*) GetString(STR_ID_CSB_DUMMY_TEXT);
  *    }
  * 
  *    DTGetRTCTime(&amp;currTime);
  * 
  *    ShowCategory403Screen(
  *        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
  *        NULL,
  *        STR_ID_CSB_LSK_TEXT,
  *        0,
  *        STR_ID_CSB_RSK_TEXT,
  *        0,
  *        (S8) 2,
  *        (S8) 0,
  *        MMI_tab_bar_items,
  *        &amp;currTime,
  *        itemlist,
  *        NULL,
  *        3,
  *        0,
  *        guiBuffer);
  * }
  * </code>                                                                                 
  *******************************************************************************************/
extern void ShowCategory403Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S8 n_tabs,
                S8 highlighted_tab,
                tab_bar_item_type *tab_items,
                MYTIME *CallDuration,
                U16 duration_icon,
                U8 **list_of_items,
                U16 *list_of_icons,
                S32 number_of_items,
                U16 highlighted_item,
                U8 *history_buffer);


extern void ShowCategory403Screen_int(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S8 n_tabs,
                S8 highlighted_tab,
                tab_bar_item_type *tab_items,
                MYTIME *CallDuration,
                U16 duration_icon,
                U8 **list_of_items,
                U16 *list_of_icons,
                S32 number_of_items,
                U16 highlighted_item,
                U8 *history_buffer);

#define ShowCategory403Screen(_arg0, _arg1, _arg2, _arg3, _arg4, _arg5, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)	\
	ShowCategory403Screen_int(_arg0, _arg1, _arg2, _arg4, _arg6, _arg7, _arg8, _arg9, _arg10, _arg11, _arg12, _arg13, _arg14, _arg15)
/*****************************************************************************
 * FUNCTION
 *  UpdateCategory403TabBar
 * DESCRIPTION
 *  Update 403 tab bar
 * PARAMETERS
 *  title              : [IN] (TITLE)      Title for the screen
 *  n_tabs             : [IN] (N/A)        Total number of tabs
 *  highlighted_tab    : [IN] (N/A)        The index of highlighted tab
 *  tab_items          : [IN] (TAB)        Array of tab item data
 * RETURNS
 *  void
 *****************************************************************************/
extern void UpdateCategory403TabBar(
                UI_string_type title,
                S8 n_tabs,
                S8 highlighted_tab,
                tab_bar_item_type *tab_items);

/*****************************************************************************
 * FUNCTION
 *  Category403UnBlinkTab
 * DESCRIPTION
 *  stop blinking tab
 * PARAMETERS
 *  tab    : [IN] (N/A)        tab index
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category403UnBlinkTab(S8 tab);

/*****************************************************************************
 * FUNCTION
 *  Category403BlinkTab
 * DESCRIPTION
 *  start blinking tab
 * PARAMETERS
 *  tab    : [IN] (N/A)        tab index
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category403BlinkTab(S8 tab);

/*****************************************************************************
 * FUNCTION
 *  SetCategory403TabSelectCallback
 * DESCRIPTION
 *  set category 403 tab bar select callback
 * PARAMETERS
 *  select_callback    : [IN] (N/A)        callback function
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory403TabSelectCallback(void (*select_callback) (int index));

/*****************************************************************************
 * FUNCTION
 *  wgui_cat403_update_duration
 * DESCRIPTION
 *  update the duration of category 403, for application usage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat403_update_duration(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat403_set_duration
 * DESCRIPTION
 *  set new duration of category 403, for application usage
 * PARAMETERS
 *  CallDuration  [IN]  start time
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat403_set_duration(MYTIME *CallDuration);

/* DOM-NOT_FOR_SDK-BEGIN */
#if defined(__MMI_MAINLCD_96X64__)
    #define CAT404_INPUTBOX_X		(24)
    #define CAT404_INPUTBOX_Y		(93)
    #define CAT404_INPUTBOX_WIDTH	(192)
    #define CAT404_INPUTBOX_HEIGHT	(102)
#elif defined(__MMI_MAINLCD_128X64__)
    #define CAT404_INPUTBOX_X		(24)
    #define CAT404_INPUTBOX_Y		(93)
    #define CAT404_INPUTBOX_WIDTH	(192)
    #define CAT404_INPUTBOX_HEIGHT	(102)
#elif defined(__MMI_MAINLCD_128X36__)// baiwenlin 20130821  
    #define CAT404_INPUTBOX_X		(24)
    #define CAT404_INPUTBOX_Y		(93)
    #define CAT404_INPUTBOX_WIDTH	(192)
    #define CAT404_INPUTBOX_HEIGHT	(102)
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
    #define CAT404_INPUTBOX_X       (25)
    #define CAT404_INPUTBOX_Y       (100)
    #define CAT404_INPUTBOX_WIDTH   (270)
    #define CAT404_INPUTBOX_HEIGHT  (145)
#elif defined(__MMI_MAINLCD_240X400__)
    #define CAT404_INPUTBOX_X       (24)
    #define CAT404_INPUTBOX_Y       (100)
    #define CAT404_INPUTBOX_WIDTH   (192)
    #define CAT404_INPUTBOX_HEIGHT  (116)
#elif defined(__MMI_MAINLCD_320X240__)
    #define CAT404_INPUTBOX_X       (17)
    #define CAT404_INPUTBOX_Y       (49)
    #define CAT404_INPUTBOX_WIDTH   (280)
    #define CAT404_INPUTBOX_HEIGHT  (60)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__)
    #define CAT404_INPUTBOX_X       (24)
    #define CAT404_INPUTBOX_Y       (93)
    #define CAT404_INPUTBOX_WIDTH   (192)
    #define CAT404_INPUTBOX_HEIGHT  (102)
#elif defined(__MMI_MAINLCD_176X220__)
    #define CAT404_INPUTBOX_X       (17)
    #define CAT404_INPUTBOX_Y       (62)
    #define CAT404_INPUTBOX_WIDTH   (144)
    #define CAT404_INPUTBOX_HEIGHT  (62)
#elif defined(__MMI_MAINLCD_128X160__)
    #define CAT404_INPUTBOX_X       (8)
    #define CAT404_INPUTBOX_Y       (39)
    #define CAT404_INPUTBOX_WIDTH   (110)
    #define CAT404_INPUTBOX_HEIGHT  (38)
#elif defined(__MMI_MAINLCD_128X128__)
    #define CAT404_INPUTBOX_X       (9)
    #define CAT404_INPUTBOX_Y       (51)
    #define CAT404_INPUTBOX_WIDTH   (110)
    #define CAT404_INPUTBOX_HEIGHT  (50)
#endif
/* DOM-NOT_FOR_SDK-END */

/*******************************************************************************************
  * FUNCTION
  *  ShowCategory404Screen
  * Description
  * Displays the category404 screen(VoIP Dialing Screen)
  * 
  * <img name="wgui_cat404_img1" />
  * Parameters
  * left_softkey :        [IN] (LSK) Left softkey label
  * left_softkey_icon :   [IN] (N/A) Icon for the Left softkey
  * right_softkey :       [IN] (RSK) Right softkey label
  * right_softkey_icon :  [IN] (N/A) Icon for the right softkey
  * bg_image :            [IN] (N/A) Background image id
  * Buffer :              [IN] (N/A) Message string
  * BufferLength :        [IN] (N/A) Length of buffer
  * history_buffer :      [IN] (N/A) History buffer
  * Returns
  *  void
  * Example
  * <code>
  * void EntryScreen_404(void)
  * {
  *    U8 *guiBuffer = NULL;
  * 
  *    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);
  * 
  *    memset(g_buffer, NULL, MAX_LOCAL_BUFFER);
  *    AnsiiToUnicodeString((PS8) g_buffer, (PS8) &quot;Category404&quot;);
  * 
  *    ShowCategory404Screen(
  *        STR_ID_CSB_LSK_TEXT,
  *        0,
  *        STR_ID_CSB_RSK_TEXT,
  *        0,
  *        NULL,
  *        (U8*) g_buffer,
  *        MAX_LOCAL_BUFFER,
  *        guiBuffer);
  * 
  * }
  * </code>                                                                                 
  *******************************************************************************************/
extern void ShowCategory404Screen(
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            U16 bg_image,
            U8 *Buffer,
            U32 BufferLength,
            U8 *history_buffer);


#if defined(__MMI_CAT116_SUPPORT__)
    
    #define CAT116_CONTENT_X (1)
    #define CAT116_CONTENT_Y (MMI_STATUS_BAR_HEIGHT + 2)
    #define CAT116_CONTENT_W (MAIN_LCD_DEVICE_WIDTH - 2*CAT116_CONTENT_X)
    #define CAT116_CONTENT_H (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 2 /* border */ - MMI_STATUS_BAR_HEIGHT - 2 /* border */)
#if defined(__WGUI_CATE_SUPPORT_SEND_KEY__)

    #if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_480X800__)
        #if defined (__MMI_FTE_SUPPORT__)
            #define CAT116_SEND_BTN_OFFSET_X	(2)
            #define CAT116_SEND_BTN_W	(56)
            #define CAT116_SEND_BTN_H	(35)
        #else /* __MMI_FTE_SUPPORT__ */
            #define CAT116_SEND_BTN_OFFSET_X	(2)
            #define CAT116_SEND_BTN_W	(43)
            #define CAT116_SEND_BTN_H	(25)
        #endif /* __MMI_FTE_SUPPORT__ */
	#elif defined(__MMI_MAINLCD_320X240__)
        #if defined (__MMI_FTE_SUPPORT__)
        	#define CAT116_SEND_BTN_OFFSET_X	(2)
        	#define CAT116_SEND_BTN_W	(46)
        	#define CAT116_SEND_BTN_H	(30)
        #else /* __MMI_FTE_SUPPORT__ */
        	#define CAT116_SEND_BTN_OFFSET_X	(2)
        	#define CAT116_SEND_BTN_W	(50)
        	#define CAT116_SEND_BTN_H	(24)
        #endif /* __MMI_FTE_SUPPORT__ */
    #elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_240X240__)
        #if defined (__MMI_FTE_SUPPORT__)
            #define CAT116_SEND_BTN_OFFSET_X	(2)
            #define CAT116_SEND_BTN_W	(46)
            #define CAT116_SEND_BTN_H	(32)
        #else /* __MMI_FTE_SUPPORT__ */
            #define CAT116_SEND_BTN_OFFSET_X	(2)
            #define CAT116_SEND_BTN_W	(35)
            #define CAT116_SEND_BTN_H	(22)
        #endif /* __MMI_FTE_SUPPORT__ */
    #else
        #if defined (__MMI_FTE_SUPPORT__)
            #define CAT116_SEND_BTN_OFFSET_X	(0)
            #define CAT116_SEND_BTN_W	(0)
            #define CAT116_SEND_BTN_H	(0)
        #else /* __MMI_FTE_SUPPORT__ */
            #define CAT116_SEND_BTN_OFFSET_X	(0)
            #define CAT116_SEND_BTN_W	(0)
            #define CAT116_SEND_BTN_H	(0)
        #endif /* __MMI_FTE_SUPPORT__ */
    #endif /* lcd size */
	
    #define CAT116_SEND_BTN_OFFSET_Y	((MMI_SINGLELINE_INPUTBOX_HEIGHT - CAT116_SEND_BTN_H) / 2)
	
#endif /* __WGUI_CATE_SUPPORT_SEND_KEY__ */

    #define CAT116_SINGLELINE_INPUTBOX_X (CAT116_CONTENT_X)
    #define CAT116_SINGLELINE_INPUTBOX_Y (CAT116_CONTENT_Y + CAT116_CONTENT_H - MMI_SINGLELINE_INPUTBOX_HEIGHT - 1)
#if defined(__WGUI_CATE_SUPPORT_SEND_KEY__)
    #define CAT116_SINGLELINE_INPUTBOX_W (CAT116_CONTENT_W - CAT116_SEND_BTN_W - 2*CAT116_SEND_BTN_OFFSET_X)
#else /* __WGUI_CATE_SUPPORT_SEND_KEY__ */
    #define CAT116_SINGLELINE_INPUTBOX_W (CAT116_CONTENT_W)
#endif /* __WGUI_CATE_SUPPORT_SEND_KEY__ */
    #define CAT116_SINGLELINE_INPUTBOX_H (MMI_SINGLELINE_INPUTBOX_HEIGHT)

    #define CAT116_MULTILINE_INPUTBOX_X (CAT116_CONTENT_X)
    #define CAT116_MULTILINE_INPUTBOX_Y (CAT116_CONTENT_Y)
    #define CAT116_MULTILINE_INPUTBOX_W (CAT116_CONTENT_W)
    #define CAT116_MULTILINE_INPUTBOX_H (CAT116_CONTENT_H - CAT116_SINGLELINE_INPUTBOX_H - INFORMATION_BAR_HEIGHT)

    /* get if the string can be displayed by medium font */ 
    #define wgui_cat116_is_display_string  wgui_is_display_medium_font_string

/*****************************************************************************
 * FUNCTION
 *  wgui_cat116_set_right_softkey_function
 * DESCRIPTION
 *  set category116 right softkey function
 * PARAMETERS
 *  f      : [IN] (N/A) right softkey function
 *  k      : [IN] (N/A) key event type   
 * RETURNS
 *  void
 *****************************************************************************/    
extern void wgui_cat116_set_right_softkey_function(void (*f) (void), MMI_key_event_type k);
/* DOM-NOT_FOR_SDK-BEGIN */ 
#define wgui_cat116_set_right_softkey_function(_arg0, _arg1) wgui_inputs_category_set_rsk_func(_arg0)
/* DOM-NOT_FOR_SDK-END */

extern void (*g_wgui_cat116_resize_and_draw_func) (S32);

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat116_get_hw_area
 * DESCRIPTION
 *  Get hand writing area 
 * PARAMETERS
 *  x      : [IN/OUT] (N/A)  X coordinate of hand writing area
 *  y      : [IN/OUT] (N/A)  Y coordinate of hand writing area
 *  w      : [IN/OUT] (N/A)  Width of hand writing area
 *  h      : [IN/OUT] (N/A)  Height of  hand writing area
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat116_get_hw_area(S32*, S32*, S32*, S32*);
#endif    

/*****************************************************************************
 * FUNCTION
 *  ShowCategory116Screen
 * DESCRIPTION
 *  Display Orange call plan screen
 * 
 * <img name="wgui_cat116_img1" />
 * PARAMETERS
 *  left_softkey               : [IN] (LSK)       Left softkey label
 *  left_softkey_icon          : [IN] (N/A)       Icon for the Left softkey
 *  right_softkey              : [IN] (RSK)       Right softkey label
 *  right_softkey_icon         : [IN] (N/A)       Icon for the right softkey
 *  message                    : [IN] (UNLIM)     Message shown in multiline inputbox
 *  input_buffer               : [IN] (N/A)       Singleline inputbox input buffer
 *  input_buffer_size          : [IN] (N/A)       Input buffer size (Orange call plan max is 183)
 *  input_type                 : [IN] (N/A)       Input method
 *  history_buffer             : [IN] (N/A)       History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory116Screen(
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                UI_string_type message,
                UI_buffer_type input_buffer,
                S32 input_buffer_size,
                U32 input_type,
                UI_buffer_type history_buffer);

#if defined(__WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__)

#include "gui_inputs.h"

extern U32 wgui_cate_get_highlight_list(HILITE_STR **list);
#endif /* __WGUI_CATE_SUPPORT_HIGHLIGHT_LIST__ */

#if defined(__WGUI_CATE_SUPPORT_SEND_KEY__)
extern void wgui_cat116_set_send_btn_func(FuncPtr send_btn_func);
#endif	/* __WGUI_CATE_SUPPORT_SEND_KEY__ */


#endif /* defined(__MMI_CAT116_SUPPORT__) */

#ifdef __MMI_MAINLCD_96X64__

typedef enum
{
	WGUI_CAT9023_ACTIVE_CALL,
	WGUI_CAT9023_HELD_CALL,
	WGUI_CAT9023_NO_CALL
} wgui_cat9023_calls_enum;

typedef struct
{
  U8 *active_caller;
  U8 *held_caller;
  U16 active_call_icon;
  U16 held_call_icon;
  MYTIME *active_call_duration;
  U8 *held_call_str;
  wgui_cat9023_calls_enum call_flag;
} wgui_cat9023_call_info_struct;
/*****************************************************************************
 * FUNCTION
 *  wgui_cat9023_update_duration
 * DESCRIPTION
 *  update the duration of category 9023, for application usage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat9023_update_duration(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9023_set_duration
 * DESCRIPTION
 *  set new duration of category 9023, for application usage
 * PARAMETERS
 *  CallDuration  [IN]  start time
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat9023_set_duration(MYTIME *CallDuration);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat9023_show
 * DESCRIPTION
 *  Display active call screen
 * PARAMETERS
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  CM_info                     [IN]        Call inforamtion
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat9023_show(
                U16  left_softkey,
                U16  right_softkey,
                wgui_cat9023_call_info_struct *CM_info,
                U8 *history_buffer);
#endif /*__MMI_MAINLCD_96X64__*/
#endif /* WGUI_CATEGORIES_CM_H */ 


