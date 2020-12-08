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
 *  wgui_categories_dialer.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Dialer related categories.
 *
 *  Author:
 * -------
 *  Viki Hung (MTK01926)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef WGUI_CATEGORIES_DIALER_H
#define WGUI_CATEGORIES_DIALER_H


#include "MMI_features.h"
/* <hExpand noExpand> DO NOT REMOVE THIS LINE */
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
#include "wgui_categories.h"
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
/* </hExpand> DO NOT REMOVE THIS LINE */
#ifdef __MMI_ANIMATED_DIAL__

/***************************************************************************** 
 * Include
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/
/* 
 * WGUI_ANIM_DIAL_MULTITAP_TIMEOUT is the time after that the multitap will be over,
 * and the cursor will move to the next position
 */
#ifdef __MTK_TARGET__
    #define WGUI_ANIM_DIAL_MULTITAP_TIMEOUT              (600)    /* Target repeat timer is 500 */
#else
    #define WGUI_ANIM_DIAL_MULTITAP_TIMEOUT              (1100)   /* Modis repeat timer is 1000 */
#endif
/* 
 * WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL is the max digit level
 * when the number of user keyin digits are more than the screen can show, 
 * the digits will become smaller to let the screen can show more digits
 */
#define WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL          (2)
/* 
 * ANIM_DIAL_TEXT is length of one character in the dial buffer
 */   
#define WGUI_ANIM_DIAL_TEXT_LENGTH       ENCODING_LENGTH

#define WGUI_ANIM_DIAL_REDRAW_X1 (0)
#define WGUI_ANIM_DIAL_REDRAW_Y1 (MMI_STATUS_BAR_HEIGHT)
#define WGUI_ANIM_DIAL_REDRAW_X2 (MAIN_LCD_DEVICE_WIDTH)
#define WGUI_ANIM_DIAL_REDRAW_Y2 (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 1)

#if defined(__MMI_MAINLCD_176X220__)
#define WGUI_ANIM_DIAL_CONTENT_X (5)
#define WGUI_ANIM_DIAL_CONTENT_Y (MMI_STATUS_BAR_HEIGHT + 10)
#define WGUI_ANIM_DIAL_CONTENT_W (MAIN_LCD_DEVICE_WIDTH - 10)
#define WGUI_ANIM_DIAL_CONTENT_H (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WGUI_ANIM_DIAL_CONTENT_Y)
#endif
#if defined(__MMI_MAINLCD_240X320__)
#define WGUI_ANIM_DIAL_CONTENT_X (20)
#define WGUI_ANIM_DIAL_CONTENT_Y (MMI_STATUS_BAR_HEIGHT + 10)
#define WGUI_ANIM_DIAL_CONTENT_W (MAIN_LCD_DEVICE_WIDTH - 40)
#define WGUI_ANIM_DIAL_CONTENT_H (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WGUI_ANIM_DIAL_CONTENT_Y)
#endif

#define WGUI_ANIM_DIAL_DIGIT_IN_LINE_0   (5)
#define WGUI_ANIM_DIAL_DIGIT_IN_LINE_1   (7)

#define WGUI_ANIM_DIAL_FLY_IN_ANIM_TIME (40)

typedef struct _wgui_animated_dial_cntx_struct
    {
        S32 x, y;                       /* left up point of region to show images */
        S32 width, height;              /* width and height of region to show images */
        S32 text_gap[WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL];                /* the gap between two images */
        S32 line_gap[WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL];                /* the gap between line and line */
        S32 word_num[WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL];                /* the number of words that can be shown on screen */
        S32 line_word_num[WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL];           /* the number of words in one line */

        S32 img_w[WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL];
        S32 img_h[WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL];                   /* the dimention of images */
        S32 anim_max_frame[WGUI_ANIM_DIAL_TOTAL_IMG_SIZE_LEVEL];          /* the max frame number of animation */
        S32 img_size_level;             /* when the screen can't contain all dial numbers, show smaller imgs */
        S32 max_img_size_level;
       
        S32 curr_cursor_pos;            /* the current position of cursor */
        S32 final_text_pos;              /* the current number of dial numbers in the buffer */
        S32 start_draw_pos;             /* the index of dial numbers to draw first */

        S32 dial_buffer_length;         /* the total lentgh of buffer */
        S32 text_length;                /* number of grid that is used to save one char in buffer */

        gdi_handle anim_handle;         /* GDI_NULL_HANDLE if animation play done */
        gdi_handle cursor_handle;       /* animation handle of cursor */
        
        S32 draw_animation;             /* which animation to draw */
        S32 multitap_index;             /* -1 if is not in multitap mode, otherwise represent index in multitap_cahr */
        
        S32 cursor_x, cursor_y;         /* the (x,y) position of cursor */

        S32 fly_in_frame;         /* the current frame is playing. -1 if not playing */
        S32 fly_in_timeslice;     /* the time slice of animation */
        S32 fly_in_final_x;       /* the final position of the "fly in object" */
        S32 fly_in_final_y;
        S32 fly_in_x;             /* the x position of img in the current frame */
        S32 fly_in_y;             /* the y position of img in the current frame */
        S32 fly_in_dx;            /* the distance in x-axis between each frame */
        S32 fly_in_dy;            /* the distance in y-axis between each frame */
        S32 anim_keycode;        /* the img id */

        UI_buffer_type dial_buffer;     /* buffer to save dial numbers already entered */
        UI_character_type *multitap_char;				/* contain the characters when KEY_STAR multitap */
        FuncPtr zero_key_func[1][4];     /* to store the zero key hander for multitap */

        void (*anim_dial_RSK_key_up_func) (void);
        BOOL is_buf_empty;
    } wgui_animated_dial_cntx_struct;


/***************************************************************************** 
 * FUNCTION
 *  ShowCategory631Screen
 * DESCRIPTION
 *  Displays the category631 screen(Animated Dialing Screen)
 *  [FTE]: not support
 * PARAMETERS
 *  left_softkey            : [IN](LSK)        Left softkey label
 *  left_softkey_icon       : [IN](N/A)        Icon for the Left softkey
 *  right_softkey           : [IN](RSK)        Right softkey label
 *  right_softkey_icon      : [IN](N/A)        Icon for the right softkey
 *  Buffer                  : [IN](N/A)        Message string
 *  BufferLength            : [IN](N/A)        Length of buffer
 *  history_buffer          : [IN](N/A)        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory631Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *Buffer,
                U32 BufferLength,
                U8 *history_buffer);

extern wgui_animated_dial_cntx_struct *g_anim_dial_cntx_p;

/*****************************************************************************
 * FUNCTION
 *  wgui_anim_dial_register_RSK_function
 * DESCRIPTION
 *  Register RSK callback function
 * PARAMETERS
 *  f      [IN]      RSK callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_anim_dial_register_RSK_function(void (*f) (void));
#endif /* __MMI_ANIMATED_DIAL__ */


#if defined(__MMI_MOTION_DIAL__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_tab_bars.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* disable back key means when there is only one digit shown in the screen,
 * press clear key will return to idle screen without back key in RSK 
 */
#define WGUI_CAT633_DISABLE_DIALER_BACK_KEY (1)

/* 
 * WGUI_CAT633_MULTITAP_TIMEOUT is the time after that the multitap will be over,
 * and the cursor will move to the next position
 */
#define WGUI_CAT633_MULTITAP_TIMEOUT   (800)
#define WGUI_CAT633_DIAL_KEY_NUMBER    (10)  /* key: digit key(0-9) */
    
    typedef struct _wgui_cat633_cntx_struct
    {
        UI_buffer_type dial_buffer_unicode;     /* buffer to save dial numbers already entered */
        S32 multitap_charater_index;             /* -1 if is not in multitap mode, otherwise represent index in multitap_char */
        UI_character_type *multitap_char;       /* contain the characters when multitap */
        MMI_BOOL RSK_label_clear;
#ifndef __MMI_WITH_C_KEY__
        UI_string_type RSK_label_original_string;
        PU8 RSK_label_original_icon;
#endif /* __MMI_WITH_C_KEY__ */
    } wgui_cat633_cntx_struct;
    
/***************************************************************************** 
 * FUNCTION
 *  ShowCategory633Screen
 * DESCRIPTION
 *  Displays the category633 screen(Motion Dialing Screen)
 *  [FTE]: not support
 * PARAMETERS
 *  left_softkey            : [IN](LSK)        Left softkey label
 *  left_softkey_icon       : [IN](N/A)        Icon for the Left softkey
 *  right_softkey           : [IN](RSK)        Right softkey label
 *  right_softkey_icon      : [IN](N/A)        Icon for the right softkey
 *  Buffer                  : [IN](N/A)        Message string
 *  BufferLength            : [IN](N/A)        Length of buffer
 *  history_buffer          : [IN](N/A)        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
    extern void ShowCategory633Screen(
                    UI_string_type left_softkey,
                    PU8 left_softkey_icon,
                    UI_string_type right_softkey,
                    PU8 right_softkey_icon,
                    U8 *Buffer,
                    U32 BufferLength,
                    U8 *history_buffer);
    extern void ExitCategory633Screen(void);
/*****************************************************************************
 * FUNCTION
 *  wgui_cat633_register_RSK_function
 * DESCRIPTION
 *  Register RSK callback function
 * PARAMETERS
 *  f      : [IN](N/A)      RSK callback function
 * RETURNS
 *  void
 *****************************************************************************/
    extern void wgui_cat633_register_RSK_function(void (*f) (void));
#endif /* defined(__MMI_MOTION_DIAL__) */

/*****************************************************************************
 * FUNCTION
 *  wgui_multitap_0_long_press_key_handler
 * DESCRIPTION
 *  the long press key handler of KEY_0 when __MMI_MULTITAP_KEY_0__ is defined
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat016_multitap_0_long_press_key_handler(void);
/*****************************************************************************
 * FUNCTION
 *  wgui_cat16_register_empty_function
 * DESCRIPTION
 *  register not empty function
 * PARAMETERS
 *  f       [IN]        not empty function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat016_register_empty_function(void (*f) (void));

/*****************************************************************************
 * FUNCTION
 *  wgui_cat016_register_not_empty_function
 * DESCRIPTION
 *  register empty function
 * PARAMETERS
 *  f       [IN]       empty function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat016_register_not_empty_function(void (*f) (void));


#endif /* WGUI_CATEGORIES_DIALER_H */ 


