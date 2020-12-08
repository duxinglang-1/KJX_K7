/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   wgui_categories_op.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *  Operator related categories for common utilities
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
 *============================================================================
 ****************************************************************************/
 
#ifndef __WGUI_CATEGORIES_OP_H__
#define __WGUI_CATEGORIES_OP_H__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
#include "wgui.h"
#include "gdi_lcd_config.h"
#include "gdi_include.h"


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#if defined(__MMI_OP01_DCD__)

/* DOM-NOT_FOR_SDK-BEGIN */
/* cat432_pen_handler is for registering the touch panel event handler */
typedef MMI_BOOL (*cat432_pen_handler)  (mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);
/* DOM-NOT_FOR_SDK-END */

#define CAT432_X                    MMI_CONTENT_X 
#define CAT432_Y                    MMI_COMMON_CONTENT_Y 
#define CAT432_W                    MMI_CONTENT_WIDTH 
#define CAT432_H                    MMI_COMMON_CONTENT_HEIGHT
#define SCRMEM_CAT432_POOL_SIZE     ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL + 7) >> 3)

/**************************************************************
  * FUNCTION
  *  ShowCategory432Screen
  * Description
  *  DCD story viewer category screen
  * 
  * <img name="wgui_cat432_img1" />
  * PARAMETERS
  *  title                         : [IN ] (TITLE) Title for the screen
  *  title_icon                    : [IN ] (N/A) Icon shown with the title
  *  left_softkey                  : [IN ] (LSK) Left softkey label
  *  left_softkey_icon             : [IN ] (N/A) Icon for the Left softkey
  *  right_softkey                 : [IN ] (RSK) Right softkey label
  *  right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
  *  pen_handler                   : [IN ] (N/A) pen event callback function
  *  agent                         : [IN ] (N/A) DCD agent
  *  history_buffer                : [IN ] (N/A) History buffer
  * Returns
  *  void                                                   
  **************************************************************/
extern void ShowCategory432Screen(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                cat432_pen_handler pen_handler,
                void* agent,
                UI_buffer_type history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void ExitCategory432Screen(void);
/* DOM-NOT_FOR_SDK-END */

#endif  /* defined(__MMI_OP01_DCD__) */

#if defined(__MMI_OP11_HOMESCREEN__)
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
#endif /* defined(__MMI_OP11_HOMESCREEN__) */

#ifdef __MMI_OP01_DCD_V30__
#define CAT9003_OP01_X                    MMI_CONTENT_X 
#define CAT9003_OP01_Y                    MMI_STATUS_BAR_HEIGHT 
#define CAT9003_OP01_W                    MMI_CONTENT_WIDTH 
#define CAT9003_OP01_H                    (MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT)
#define SCRMEM_CAT9003_OP01_POOL_SIZE     ((GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL + 7) >> 3)


/* DOM-NOT_FOR_SDK-BEGIN */
/* cat432_pen_handler is for registering the touch panel event handler */
typedef MMI_BOOL (*cat9003_op01_pen_handler)  (mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);
/* DOM-NOT_FOR_SDK-END */

extern void wgui_cat9003_op01_show(
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                cat9003_op01_pen_handler pen_handler,
                void* agent,
                UI_buffer_type history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void wgui_cat9003_op01_exit(void);
/* DOM-NOT_FOR_SDK-END */

#endif /* __MMI_OP01_DCD_V30__ */

#if defined(__MMI_TC01_LTUI_SMART_MEMO__)

/* Control area or background layout */
#define WGUI_CAT9007_TC01_OFFSET_X (15)
#define WGUI_CAT9007_TC01_OFFSET_Y (25)
#define WGUI_CAT9007_TC01_BG_X  (WGUI_CAT9007_TC01_OFFSET_X)
#define WGUI_CAT9007_TC01_BG_Y  (MMI_STATUS_BAR_HEIGHT + WGUI_CAT9007_TC01_OFFSET_Y)
#define WGUI_CAT9007_TC01_BG_W  (MMI_CONTENT_WIDTH - 2 * WGUI_CAT9007_TC01_OFFSET_X)
#define WGUI_CAT9007_TC01_BG_H  (MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 2 * WGUI_CAT9007_TC01_OFFSET_Y)

/* Multiline editor layout */
#define WGUI_CAT9007_TC01_MARGIN_GAP_V     (5)  /* vertical gap between background and multiline */
#define WGUI_CAT9007_TC01_MULTILINE_WIDTH  (132)
#define WGUI_CAT9007_TC01_MULTILINE_HEIGHT (99)
#define WGUI_CAT9007_TC01_MULTILINE_X      (WGUI_CAT9007_TC01_BG_X + ((WGUI_CAT9007_TC01_BG_W - WGUI_CAT9007_TC01_MULTILINE_WIDTH) >> 1))
#define WGUI_CAT9007_TC01_MULTILINE_Y      (WGUI_CAT9007_TC01_BG_Y + WGUI_CAT9007_TC01_MARGIN_GAP_V)

/* Date time layout */
#define WGUI_CAT9007_TC01_DATE_TIME_X        (WGUI_CAT9007_TC01_MULTILINE_X)
#define WGUI_CAT9007_TC01_DATE_TIME_Y        (WGUI_CAT9007_TC01_MULTILINE_Y + WGUI_CAT9007_TC01_MULTILINE_HEIGHT + 9 /* gap for look fine */)

/**************************************************************
  * FUNCTION
  *  wgui_cat9007_tc01_show
  * Description
  *  Text memo viewer category screen
  * 
  * <img name="wgui_cat9001_t01_img1" />
  * PARAMETERS
  *  title                         : [IN ] (TITLE) Title for the screen
  *  title_icon                    : [IN ] (N/A) Icon shown with the title
  *  left_softkey                  : [IN ] (LSK) Left softkey label
  *  left_softkey_icon             : [IN ] (N/A) Icon for the Left softkey
  *  right_softkey                 : [IN ] (RSK) Right softkey label
  *  right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
  *  pen_handler                   : [IN ] (N/A) pen event callback function
  *  agent                         : [IN ] (N/A) DCD agent
  *  history_buffer                : [IN ] (N/A) History buffer
  * Returns
  *  void
  **************************************************************/
extern void wgui_cat9007_tc01_show(
                WCHAR *left_softkey,
                PU8 left_softkey_icon,
                WCHAR *right_softkey,
                PU8 right_softkey_icon,
                MMI_IMG_ID image_background,
                WCHAR *message,
                color text_color,
                U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void wgui_cat9007_tc01_init_data_time(void);
extern void wgui_cat9007_tc01_close_clock(void);
extern void wgui_cat9007_tc01_set_text_color(color c);
extern void wgui_cat9007_tc01_show_bracket(void);
/* DOM-NOT_FOR_SDK-END */


/* Image memo layout */
#define WGUI_CAT9008_TC01_IMAGE_X      (WGUI_CAT9007_TC01_MULTILINE_X)
#define WGUI_CAT9008_TC01_IMAGE_Y      (WGUI_CAT9007_TC01_MULTILINE_Y)
#define WGUI_CAT9008_TC01_IMAGE_WIDTH  (WGUI_CAT9007_TC01_MULTILINE_WIDTH)  /* assure width : height = 4 : 3 for camera image ratio */
#define WGUI_CAT9008_TC01_IMAGE_HEIGHT (WGUI_CAT9007_TC01_MULTILINE_HEIGHT) /* assure width : height = 4 : 3 for camera image ratio */

/**************************************************************
  * FUNCTION
  *  wgui_cat9008_tc01_show
  * Description
  *  Text memo viewer category screen
  * 
  * <img name="wgui_cat9008_tc01_img1" />
  * PARAMETERS
  *  title                         : [IN ] (TITLE) Title for the screen
  *  title_icon                    : [IN ] (N/A) Icon shown with the title
  *  left_softkey                  : [IN ] (LSK) Left softkey label
  *  left_softkey_icon             : [IN ] (N/A) Icon for the Left softkey
  *  right_softkey                 : [IN ] (RSK) Right softkey label
  *  right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
  *  pen_handler                   : [IN ] (N/A) pen event callback function
  *  agent                         : [IN ] (N/A) DCD agent
  *  history_buffer                : [IN ] (N/A) History buffer
  * Returns
  *  void
  **************************************************************/
extern void wgui_cat9008_tc01_show(
                WCHAR *left_softkey,
                PU8 left_softkey_icon,
                WCHAR *right_softkey,
                PU8 right_softkey_icon,
                MMI_IMG_ID image_background,
                S8 *memo_image_path,
                color text_color,
                U8 *history_buffer);


/**************************************************************
  * FUNCTION
  *  wgui_cat9009_tc01_show
  * Description
  *  Text memo viewer category screen
  * 
  * <img name="wgui_cat9009_tc01_img1" />
  * PARAMETERS
  *  title                         : [IN ] (TITLE) Title for the screen
  *  title_icon                    : [IN ] (N/A) Icon shown with the title
  *  left_softkey                  : [IN ] (LSK) Left softkey label
  *  left_softkey_icon             : [IN ] (N/A) Icon for the Left softkey
  *  right_softkey                 : [IN ] (RSK) Right softkey label
  *  right_softkey_icon            : [IN ] (N/A) Icon for the right softkey
  *  pen_handler                   : [IN ] (N/A) pen event callback function
  *  agent                         : [IN ] (N/A) DCD agent
  *  history_buffer                : [IN ] (N/A) History buffer
  * Returns
  *  void
  **************************************************************/
extern void wgui_cat9009_tc01_show(
                WCHAR *left_softkey,
                PU8 left_softkey_icon,
                WCHAR *right_softkey,
                PU8 right_softkey_icon,
                MMI_IMG_ID image_background,
                color text_color,
                U32 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void wgui_cat9009_tc01_set_rsk_func(void (*f) (void), MMI_key_event_type k);
extern void wgui_cat9009_tc01_append_string(U32 input_type, U8 *buffer, S32 buffer_size, U8 *s, U8 *history_buffer);
/* DOM-NOT_FOR_SDK-END */

#endif /* defined(__MMI_TC01_LTUI_SMART_MEMO__) */

#ifdef __cplusplus
}
#endif 

#ifdef __MMI_OP02_LEMEI__
extern void wgui_cat9002_op02_show(UI_string_type title,
                                        PU8 title_icon,
                                        UI_string_type left_softkey,
                                        PU8 left_softkey_icon,
                                        UI_string_type right_softkey,
                                        PU8 right_softkey_icon);

extern void wgui_cat9002_op02_set_button1_hdlr(void (*handler) (void));
extern void wgui_cat9002_op02_set_button2_hdlr(void (*handler) (void));
extern void wgui_cat9002_op02_set_button3_hdlr(void (*handler) (void));
#endif /*__MMI_OP02_LEMEI__*/
#endif /* __WGUI_CATEGORIES_OP_H__ */ 

