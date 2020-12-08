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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    imui_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   header file for imui_api.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifndef __IMUI_API_H__
#define __IMUI_API_H__


#include "IMERes.h"
#include "mmi_frm_gprot.h"

#include "Imc_config.h"
#include "wgui_virtual_keyboard.h"

/*RHR check-in*/
#include "ImeGprot.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "gui_buttons.h"
#include "gui_virtual_keyboard_language_type.h"
#include "gui_virtual_keyboard.h"
#include "kal_non_specific_general_types.h"
#include "gui_theme_struct.h"
/*RHR chek-in*/
/*****************************************************************************
 * Definitions
 *****************************************************************************/
#define MMI_IMUI_CUSTOM_UI_CONTROL_SIZE (10)
 
typedef enum
{
    MMI_IMUI_INFORMATION_BAR = 0,
    MMI_IMUI_VIRTUAL_KEYBOARD,
    MMI_IMUI_COMPOSITION_AREA,
    MMI_IMUI_CANDIDATE_AREA,
    MMI_IMUI_INPUT_AREA,
    MMI_IMUI_TITLE_AREA,
    MMI_IMUI_MULTI_BLOCK_AREA,
    MMI_IMUI_IME_HINT_AREA,
    MMI_IMUI_SINGLE_BLOCK_AREA,
    MMI_IMUI_IME_INDICATOR_AREA,
    MMI_IMUI_IME_INDICATOR_AREA_FLOATING,
    /* the max number could not exceed 16 because mmi_imc_fsm_struct */
    MMI_IMUI_CLIPBOARD_FLOATING_MENU,
    MMI_IMUI_CANDIDATE_GRID_AREA,
    MMI_IMUI_CUSTOM_CONTROL_BEGIN,
    MMI_IMUI_CUSTOM_CONTROL_END = MMI_IMUI_CUSTOM_CONTROL_BEGIN + MMI_IMUI_CUSTOM_UI_CONTROL_SIZE,
    MMI_IMUI_CONTROL_MAX
} mmi_imui_control_type_enum;

#define MMI_IMUI_RESULT_TRUE (1)
#define MMI_IMUI_RESULT_FALSE (0)

/*UI mask*/
#define MMI_IMUI_CONTROL_MASK(i) (0x01 << (i)) /* i is one of mmi_imui_control_type_enum */

#define MMI_IMUI_MAKE_MESSAGE(msg, msg_id, param_0, param_1) {\
                                                              (msg).message_id = (U8)(msg_id); \
                                                              (msg).param_0 = (U32)(param_0); \
                                                              (msg).param_1 = (U32)(param_1); \
                                                             }
#define POINT_CHECK_BOUND(x, y, x1, y1, width, height) ((x) >= (x1) && (y) >= (y1) && (x) < ((x1) + (width)) && (y) < ((y1) + (height)))

#define MMI_IMUI_SELECTION_AREA_STYLE_ARROW         0x0001
#define MMI_IMUI_SELECTION_AREA_STYLE_LABEL         0x0002
#define MMI_IMUI_SELECTION_AREA_STYLE_STAR          0x0004
#define MMI_IMUI_SELECTION_AREA_STYLE_WAVE          0x0008
#define MMI_IMUI_SELECTION_AREA_STYLE_CURSOR        0x0010
#define MMI_IMUI_SELECTION_AREA_STYLE_BORDER        0x0020
#define MMI_IMUI_SELECTION_AREA_STYLE_SEPARATOR     0x0040 /* Neessay when use MMI_IMUI_SELECTION_AREA_FLAG_FIX_GRID */
#define MMI_IMUI_SELECTION_AREA_STYLE_SPACE_AFTER_APOSTROPHE  0x0080
#define MMI_IMUI_SELECTION_AREA_STYLE_EXPAND_BUTTON        0x0100


#define MMI_IMUI_CANDIDATE_GRID_STYLE_NAVIGATION_AND_BACK     0x0001  //candidate grid where delete, up, down, back key in end column



#define MMI_IMUI_SELECTION_AREA_FLAG_FOCUS            0x0001
#define MMI_IMUI_SELECTION_AREA_FLAG_PRE_PAGE         0x0002
#define MMI_IMUI_SELECTION_AREA_FLAG_NEXT_PAGE        0x0004
#define MMI_IMUI_SELECTION_AREA_FLAG_SHOW_ARROW       0x0008
#define MMI_IMUI_SELECTION_AREA_FLAG_LARGE_FONT       0x0010
#define MMI_IMUI_SELECTION_AREA_FLAG_FIX_GRID         0x0020 /* For only one character in a candidate item */
#define MMI_IMUI_SELECTION_AREA_FLAG_R2L              0x0040
#define MMI_IMUI_SELECTION_AREA_FLAG_SPACE            0x0080
#define MMI_IMUI_SELECTION_AREA_FLAG_CENTER_INDEX     0x0100
#define MMI_IMUI_SELECTION_AREA_FLAG_LAST_PAGE        0x0200
#define MMI_IMUI_SELECTION_AREA_FLAG_SHOW_STAR        0x0400
#define MMI_IMUI_SELECTION_AREA_FLAG_DISABLE_LABEL   0x0800
#define MMI_IMUI_SELECTION_AREA_FLAG_RESERVE             0x1000
#define MMI_IMUI_SELECTION_AREA_FLAG_VERTICAL         0x2000
#define MMI_IMUI_SELECTION_AREA_FLAG_FLOATING         0x4000
#define MMI_IMUI_SELECTION_AREA_FLAG_AUTO_RESIZABLE   0x8000
#define MMI_IMUI_SELECTION_AREA_FLAG_SHOW_EXPAND_BUTTON   0x10000
#define MMI_IMUI_SELECTION_AREA_FLAG_SCROLLING_COMPOSITION_BOX 0x20000


#define MMI_IMUI_INPUT_AREA_STYLE_WAVE        0x0001
#define MMI_IMUI_INPUT_AREA_STYLE_CURSOR      0x0002
#define MMI_IMUI_INPUT_AREA_STYLE_BORDER      0x0004
#define MMI_IMUI_INPUT_AREA_STYLE_CENTER_ALIGN      0x0008


#define MMI_IMUI_INPUT_AREA_FLAG_FOCUS         0x0001
#define MMI_IMUI_INPUT_AREA_FLAG_R2L        0x0002

#if defined(__MMI_MAINLCD_240X400__)
    #define MMI_IMUI_MULTI_BLOCK_HEIGHT 100
#elif defined(__MMI_MAINLCD_240X320__)
    #define MMI_IMUI_MULTI_BLOCK_HEIGHT 80
#elif defined(__MMI_MAINLCD_320X480__)   
    #define MMI_IMUI_MULTI_BLOCK_HEIGHT 150
#elif defined(__MMI_MAINLCD_480X800__)   
    #define MMI_IMUI_MULTI_BLOCK_HEIGHT 200
#else
    #define MMI_IMUI_MULTI_BLOCK_HEIGHT 60    
#endif

#define MMI_IMUI_SINGLE_BLOCK_MAX_TAB_NUM 5
#define MMI_IMUI_POPUP_LIST_MAX_ITEM_NUM 8


/*****************************************************************************
 * Enums
 *****************************************************************************/

typedef enum {
    MMI_IMUI_MESSAGE_INIT_UI             = 0x0,
    MMI_IMUI_MESSAGE_EXIT,
    MMI_IMUI_MESSAGE_CREATE_CANDIDATE_BOX,      /*param_0: selection area style*/
	MMI_IMUI_MESSAGE_CREATE_CANDIDATE_BOX_GRID,
    MMI_IMUI_MESSAGE_CREATE_COMPOSITION_BOX,    /*param_0: selection area style*/
    MMI_IMUI_MESSAGE_CREATE_VITUAL_KEYBOARD,
    MMI_IMUI_MESSAGE_CREATE_INFORMATION_BAR,    /*param_0: information bar rect(mmi_imc_rect *)*/
    MMI_IMUI_MESSAGE_CREATE_MULTI_BLOCK_AREA,
    MMI_IMUI_MESSAGE_CREATE_SINGLE_BLOCK_AREA,
    MMI_IMUI_MESSAGE_CREATE_INPUT_BOX,
    MMI_IMUI_MESSAGE_CREATE_TITLE_BOX,
    MMI_IMUI_MESSAGE_CREATE_IME_INDICATOR,
    MMI_IMUI_MESSAGE_CREATE_CLIPBOARD_FLOATING_MENU,
    MMI_IMUI_MESSAGE_SHOW_CLIPBOARD_FLOATING_MENU,
    MMI_IMUI_MESSAGE_SHOW_INDICATOR_FLOATING,
    MMI_IMUI_MESSAGE_HIDE_INDICATOR_FLOATING,
    MMI_IMUI_MESSAGE_HIDE_CLIPBOARD_FLOATING_MENU,
    MMI_IMUI_MESSAGE_UPDATE_CLIPBOARD_FLOATING_MENU,
    MMI_IMUI_MESSAGE_SET_VIRTUAL_KEYBOARD,    /*param_0: input mode, param_1: is thers candidate box above virtual keyboard*/
    MMI_IMUI_MESSAGE_SET_HAND_WRITING_STYLE,  /*param_0: hand writing style*/
    MMI_IMUI_MESSAGE_SET_HAND_WRITING_AREAS,  /*param_0: first area, param_1: area after first stroke*/
    MMI_IMUI_MESSAGE_UPDATE_INPUT_AREA,
    MMI_IMUI_MESSAGE_SHOW_INPUT_BOX,
    MMI_IMUI_MESSAGE_HIDE_INPUT_BOX,
    MMI_IMUI_MESSAGE_SHOW_CANDIDATE_GRID_BOX,
    MMI_IMUI_MESSAGE_HIDE_CANDIDATE_GRID_BOX,
    MMI_IMUI_MESSAGE_INPUT_SET_FOCUS,
    MMI_IMUI_MESSAGE_INPUT_CANCEL_FOCUS,
    MMI_IMUI_MESSAGE_UPDATE_TITLE_AREA,
    MMI_IMUI_MESSAGE_SHOW_TITLE_BOX,
    MMI_IMUI_MESSAGE_HIDE_TITLE_BOX,
    MMI_IMUI_MESSAGE_SHOW_CANDIDATE_BOX,
    MMI_IMUI_MESSAGE_HIDE_CANDIDATE_BOX,
    MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX,    /*param_0: point to mmi_imui_update_selection_area_struct*/
	MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX_GRID,
    MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX,
    MMI_IMUI_MESSAGE_CANDIDATE_BOX_GET_INDEX,
	MMI_IMUI_MESSAGE_CANDIDATE_GRID_BOX_GET_INDEX,
    MMI_IMUI_MESSAGE_CANDIDATE_SET_FOCUS,
    MMI_IMUI_MESSAGE_CANDIDATE_CANCEL_FOCUS,
    MMI_IMUI_MESSAGE_SHOW_COMPOSITION_BOX,
    MMI_IMUI_MESSAGE_HIDE_COMPOSITION_BOX,
    MMI_IMUI_MESSAGE_UPDATE_COMPOSITION_BOX,  /*param_0: point to mmi_imui_update_selection_area_struct*/
    MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX,
    MMI_IMUI_MESSAGE_COMPOSITION_BOX_GET_INDEX,
    MMI_IMUI_MESSAGE_COMPOSITION_SET_FOCUS,
    MMI_IMUI_MESSAGE_COMPOSITION_CANCEL_FOCUS,
	MMI_IMUI_MESSAGE_REMOVE_VERTICAL_FLAG,
    MMI_IMUI_MESSAGE_SHOW_VIRTUAL_KEYBOARD,
    MMI_IMUI_MESSAGE_SHOW_DISABLED_VIRTUAL_KEYBOARD,
    MMI_IMUI_MESSAGE_HIDE_VIRTUAL_KEYBOARD,
    MMI_IMUI_MESSAGE_GET_VK_AREA_HEIGHT,
    MMI_IMUI_MESSAGE_GET_VK_TYPE,
    MMI_IMUI_MESSAGE_SHOW_MULTI_BLOCK,
    MMI_IMUI_MESSAGE_HIDE_MULTI_BLOCK,
    MMI_IMUI_MESSAGE_SHOW_SINGLE_BLOCK,
    MMI_IMUI_MESSAGE_HIDE_SINGLE_BLOCK,
    MMI_IMUI_MESSAGE_GET_MULTI_BLOCK_AREA,    /* param_0: point to the first area, param_1: point to the second area*/
    MMI_IMUI_MESSAGE_GET_SINGLE_BLOCK_AREA,    /* param_0: point to the hw ara block */
    MMI_IMUI_MESSAGE_IS_STROKE_DOWN_IN_EXTRA_BLOCK,  /* param_0: tab index */
    MMI_IMUI_MESSAGE_REDRAW,
    MMI_IMUI_MESSAGE_REDRAW_FLOATING_CONTROLS,
    MMI_IMUI_MESSAGE_HIDE_ALL,
    MMI_IMUI_MESSAGE_SET_BACK_GROUND_REDRAW_FUNC, /*param_0: back ground redraw function (mmi_imui_draw_back_ground_funcptr)*/
    MMI_IMUI_MESSAGE_DRAW_STROKE,
    MMI_IMUI_MESSAGE_DRAW_INFORMATION_BAR,
    MMI_IMUI_MESSAGE_GET_IME_INFOR_WIDTH,
    MMI_IMUI_MESSAGE_CLEAR_STROKE,
    MMI_IMUI_MESSAGE_SET_STROKE_COLOR,        /*param_0: point to the color*/
    MMI_IMUI_MESSAGE_PEN_DOWN_EVENT,
    MMI_IMUI_MESSAGE_PEN_MOVE_EVENT,
    MMI_IMUI_MESSAGE_PEN_UP_EVENT,
    MMI_IMUI_MESSAGE_PEN_ABORT_EVENT,
    MMI_IMUI_MESSAGE_PEN_LONG_TAP_EVENT,
    MMI_IMUI_MESSAGE_PEN_REPEAT_EVENT,
    MMI_IMUI_MESSAGE_FLOATING_UI_PEN_DOWN_EVENT,
    MMI_IMUI_MESSAGE_SET_NEW_WORD_PROMPT,
    MMI_IMUI_MESSAGE_GET_MAX_CANDIDATE_WIDTH,
    MMI_IMUI_MESSAGE_GET_IME_HINT_WIDTH,
    MMI_IMUI_MESSAGE_GET_IME_HINT_HEIGHT,
    MMI_IMUI_MESSAGE_DRAW_IME_HINT,
	MMI_IMUI_MESSAGE_FIXED_IMUI_HEIGHT,
    MMI_IMUI_MESSAGE_CONFIG_REDRAW_VK,
	MMI_IMUI_MESSAGE_FLOATING_IMUI_HEIGHT,
	MMI_IMUI_MESSAGE_GET_FLOATING_IMUI_SET,
	MMI_IMUI_MESSAGE_SET_IMUI_PARAMETERS,
	MMI_IMUI_MESSAGE_GET_IMUI_PARAMETERS,
	MMI_IMUI_MESSAGE_GET_LAST_SHOWED_IMUI_SET,
    MMI_IMUI_MESSAGE_SET_VK_STYLE, /* to set vk style (qwerty or alphanumeric or others....) */
    MMI_IMUI_MESSAGE_CHECK_FLOATING_UI_CONTAIN_POINT,
    MMI_IMUI_GET_VK_KEY_POSITION,
    MMI_IMUI_SET_HW_EXTRA_BLOCK_INDICATOR,
    MMI_IMUI_DOES_FLOATING_UI_COVER_IME_INDICATOR,
    MMI_IMUI_SET_FLOATING_CANDIDATE_BOX,
    MMI_IMUI_CHECK_OVERLAP_WITH_CURRENT_FLOATING_UI,
    MMI_IMUI_GET_FLOATING_UI_RECT,
    MMI_IMUI_MESSAGE_GET_EXTRA_IMUI_LAYER_HANDLER,
    MMI_IMUI_MESSAGE_EXIT_HANDWRITING_ON_DISCONNECT,
    MMI_IMUI_MESSAGE_ADD_CONTROL,  /* param_0: the imui control to be added */
    MMI_IMUI_MESSAGE_IS_IN_CONTROL_SET,  /* param_0: the imui control to be checked */
    MMI_IMUI_MESSAGE_SET_VISIBLE_CONTROL,   /* param_0: the imui control to show */
    MMI_IMUI_MESSAGE_SET_HIDDEN_CONTROL,    /* param_0: the imui control to hide */
    MMI_IMUI_MESSAGE_IS_VISIBLE_CONTROL,    /* param_0: the imui control to be checked */
    MMI_IMUI_MESSAGE_IS_PREVIOUS_VISIBLE_CONTROL,   /* param_0: the imui control to be checked */
    MMI_IMUI_MESSAGE_IS_PREVIOUS_VISIBLE_FLOATING_CONTROL,   /* param_0: the imui control to be checked */
    MMI_IMUI_MESSAGE_REDRAW_IMUI_BACKGROUND,    /* param_0: the rect to be redraw */
    MMI_IMUI_MESSAGE_IS_VIRTUAL_KEYBOARD_HIDDEN,
    MMI_IMUI_MESSAGE_INVALIDATE_VK,
    MMI_IMUI_DOES_UI_COVER_IME_INDICATOR,
    //belowing message is for VKv3
    MMI_IMUI_MESSAGE_SET_VK,
    MMI_IMUI_MESSAGE_GET_QWERTY_VK_KEY_MAPPING,
    MMI_IMUI_MESSAGE_IS_SYMBOL_VK_TYPE,
    MMI_IMUI_MESSAGE_SET_VK_SHIFT_STATE,
    MMI_IMUI_MESSAGE_GET_VK_AREA_RECT,
    MMI_IMUI_MESSAGE_ADD_TOGGLE_STATE_ID_VK,
    MMI_IMUI_MESSAGE_REMOVE_TOGGLE_STATE_ID_VK,
    MMI_IMUI_MESSAGE_SET_ACTIVE_ROW_ID_VK,
    MMI_IMUI_MESSAGE_REDRAW_TOGGLE_STATE_VK,
    MMI_IMUI_MESSAGE_REDRAW_ACTIVE_ROW_VK,
    
    //newly added handwriting message @2012-1-16
    MMI_IMUI_MESSAGE_GET_OVER_VK_AREA,
    MMI_IMUI_MESSAGE_GET_HALF_SCREEN_AREA,			
    MMI_IMUI_MESSAGE_GET_SINGLE_BLOCK_FULL_SCREEN_AREA,
    
/*Above this line, the messages are from external to IMUI
  Below this line, the messages are from IMUI to external*/
    MMI_IMUI_MESSAGE_PEN_DOWN_IN_INFORMATION_BAR,
    MMI_IMUI_MESSAGE_PEN_DOWN_IN_VIRTUAL_KEYBOARD,
    MMI_IMUI_MESSAGE_PEN_DOWN_IN_CANDIDATE_BOX,     /*param_0: selection event*/
    MMI_IMUI_MESSAGE_PEN_DOWN_IN_CANDIDATE_GRID_BOX,
    MMI_IMUI_MESSAGE_PEN_DOWN_IN_COMPOSITION_BOX,
    MMI_IMUI_MESSAGE_PEN_UP_IN_INFORMATION_BAR,
    MMI_IMUI_MESSAGE_PEN_UP_IN_VIRTUAL_KEYBOARD,
    MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_BOX,
	MMI_IMUI_MESSAGE_PEN_UP_IN_CANDIDATE_GRID_BOX,
    MMI_IMUI_MESSAGE_PEN_UP_IN_COMPOSITION_BOX,
    MMI_IMUI_MESSAGE_PEN_MOVE_IN_INFORMATION_BAR,
    MMI_IMUI_MESSAGE_PEN_MOVE_IN_VIRTUAL_KEYBOARD,
    MMI_IMUI_MESSAGE_PEN_MOVE_IN_CANDIDATE_BOX,
	MMI_IMUI_MESSAGE_PEN_MOVE_IN_CANDIDATE_GRID_BOX,
    MMI_IMUI_MESSAGE_PEN_MOVE_IN_COMPOSITION_BOX,
    MMI_IMUI_MESSAGE_SELECT_AREA_DISABLE_LABEL,
    MMI_IMUI_MESSAGE_RESERVE_CANDIDATE_AREA,
    MMI_IMUI_MESSAGE_PEN_LONGTAP_IN_VIRTUAL_KEYBOARD,
	MMI_IMUI_MESSAGE_PEN_LONGTAP_IN_CANDIDATE_GRID_BOX,
    MMI_IMUI_MESSAGE_PEN_DOWN_IN_IME_HINT,
    MMI_IMUI_MESSAGE_PEN_UP_IN_IME_HINT,
    MMI_IMUI_MESSAGE_PEN_MOVE_IN_IME_HINT,
    MMI_IMUI_MESSAGE_PEN_ABORT_IN_VIRTUAL_KEYBOARD,
    MMI_IMUI_MESSAGE_PEN_REPEAT_IN_VIRTUAL_KEYBOARD,
	MMI_IMUI_MESSAGE_PEN_REPEAT_IN_CANDIDATE_GRID_BOX,
    MMI_IMUI_MESSAGE_VK_DRAW_DISABLE,
    MMI_IMUI_MESSAGE_VK_DRAW_ENABLE,
    MMI_IMUI_MESSAGE_RECREATE_HW_BLOCK,
    MMI_IMUI_MESSAGE_UPDATE_VK,
    MMI_IMUI_MESSAGE_ADD_VERTICAL_FLAG
    /* TODO: add your UI messages */
#ifdef __MMI_CSTAR_PHRASE_INPUT__
    ,MMI_IMUI_MESSAGE_PEN_DOWN_IN_INPUT_BOX
    ,MMI_IMUI_MESSAGE_PEN_UP_IN_INPUT_BOX
#endif
}   mmi_imui_message_id_enum;

typedef enum {
   MMI_IMUI_SELECTION_AREA_PEN_NONE,
   MMI_IMUI_SELECTION_AREA_PEN_TEXT,
   MMI_IMUI_SELECTION_AREA_PEN_RIGHT_ARROW,
   MMI_IMUI_SELECTION_AREA_PEN_LEFT_ARROW,
   MMI_IMUI_SELECTION_AREA_PEN_EXPAND
}mmi_imui_selection_area_pen_event_enum;

typedef enum {
   MMI_IMUI_SELECTION_AREA_GRID_PEN_NONE,
   MMI_IMUI_SELECTION_AREA_GRID_PEN_TEXT,
   MMI_IMUI_SELECTION_AREA_GRID_PEN_DELETE,
   MMI_IMUI_SELECTION_AREA_GRID_PEN_NAVIGATION_UP,
   MMI_IMUI_SELECTION_AREA_GRID_PEN_NAVIGATION_DOWN,
   MMI_IMUI_SELECTION_AREA_GRID_PEN_BACK
}mmi_imui_selection_area_grid_pen_event_enum;


/*****************************************************************************
 * Typedef
 *****************************************************************************/
 

typedef void (*mmi_imui_command_funcptr)(mmi_imui_message_struct_p msg_ptr);



typedef struct
{
    UI_string_type str_ptr;
    UI_character_type separator;
    S32 count;
    S32 highlight_index;
    U32 flags;
} mmi_imui_update_selection_area_struct, *mmi_imui_update_selection_area_struct_p;

typedef struct
{
    UI_string_type str_ptr;
    S32 highlight_start_index;
    S32 highlight_num;
    S32 wave_start_index;
    S32 wave_num;
    S32 cursor_index;
    U32 flags;
} mmi_imui_update_input_area_struct, *mmi_imui_update_input_area_struct_p;

#ifdef __MMI_CLIPBOARD_FLOATING_MENU__

#define MMI_IMUI_CLIPBOARD_FOLATING_MENU_NUM    3

typedef enum
{
    MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_NONE = 0,
    MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_COPY,
    MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_COPY_ALL,
    MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_CUT,
    MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_CUT_ALL,
    MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_PASTE,
    MMI_IMUI_CLIPBOARD_FLOATING_MENU_ITEM_TYPE_MAX,
} mmi_imui_clipboard_floating_menu_type_enum;



typedef struct
{
    mmi_imui_clipboard_floating_menu_type_enum button_type;
    text_button button;
} mmi_imui_clipboard_floating_menu_item_struct, mmi_imui_clipboard_floating_menu_item_struct_p;

typedef struct
{
    mmi_imui_clipboard_floating_menu_item_struct menu_item[MMI_IMUI_CLIPBOARD_FOLATING_MENU_NUM];
    S32 count;
    S32 highlight_index;
    U32 flags;
} mmi_imui_update_clipboard_floating_menu_struct, *mmi_imui_update_clipboard_floating_menu_struct_p;
#endif /* __MMI_CLIPBOARD_FLOATING_MENU__ */

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)

typedef struct
{
    gui_virtual_keyboard_language_enum vk_type;
    U32 vk_style;
    U32 has_cand_box;
    gui_virtual_keyboard_event_callback_func_ptr event_callback;
    gui_virtual_keyboard_display_callback_func_ptr disp_callback;
} mmi_imui_virtual_keyboard_parameter, *mmi_imui_virtual_keyboard_parameter_p;

#endif /* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
typedef struct
{
    gui_virtual_keyboard_language_enum vk_type;
    U32 vk_style;
    U32 has_cand_box;
} mmi_imui_virtual_keyboard_parameter, *mmi_imui_virtual_keyboard_parameter_p;

#endif/* defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) */

#if defined(__MMI_IME_FTE_ENHANCE__)

typedef struct
{
    S16 x, y, max_width, max_height;
    U8 count;	
    PU8 str_content[MMI_IMUI_POPUP_LIST_MAX_ITEM_NUM];
} mmi_imui_popup_list_parameter, *mmi_imui_popup_list_parameter_p;

typedef struct
{
    MMI_BOOL image_content;
    U8 tab_num;
    U8 tab_highlight;
    PU8 content[MMI_IMUI_SINGLE_BLOCK_MAX_TAB_NUM];
} mmi_imui_single_block_hw_parameter, *mmi_imui_single_block_hw_parameter_p;
#endif

typedef enum
{
	MMI_IMUI_CANDIDATE_GRID_DELETE=0,
        MMI_IMUI_CANDIDATE_GRID_NAVIGATION_UP,
	MMI_IMUI_CANDIDATE_GRID_NAVIGATION_DOWN,
	MMI_IMUI_CANDIDATE_GRID_BACK
}mmi_imui_candidate_grid_style1, mmi_imui_candidate_grid_style1_p;
/*****************************************************************************
*  Global variables
*****************************************************************************/
extern UI_ime_theme *current_ime_theme;

/*****************************************************************************
*  Global Functions
*****************************************************************************/

/* imui functions */
#if defined(__MMI_IME_V3__) && !defined(__NO_HANDWRITING__)
extern void mmi_imui_get_handwriting_area(mmi_pen_handwriting_area_struct *rect);
#endif
#if defined(__MMI_IME_SCROLLING_COMPOSITION__)
extern MMI_BOOL mmi_imui_is_scrolling_box_shown(void);
#endif
extern void mmi_imui_add_control(mmi_imui_control_type_enum imui_control);
extern MMI_BOOL mmi_imui_is_in_control_set(mmi_imui_control_type_enum imui_control);
extern U32 mmi_imui_get_control_showed_flag(void);
extern void mmi_imui_set_control_showed_flag(U32 control, MMI_BOOL isenable);
extern MMI_BOOL mmi_imui_is_visible_control(U32 control);

extern U32  mmi_imui_send_message( mmi_imui_message_struct_p msg_ptr, mmi_imui_command_funcptr command_callback ); 
extern void mmi_imui_exit_screen(void);
extern UI_string_type mmi_imui_get_inputmode_string(MMI_BOOL *is_smart);
#ifdef __MMI_CLIPBOARD_FLOATING_MENU__
extern S32 mmi_imui_create_clipboard_floating_menu_item(mmi_imui_update_clipboard_floating_menu_struct_p menu, S32 count, S32 x, S32 y);
#endif

#if defined(__MMI_IME_INDICATOR_ON_STATUS_ICON_BAR__)
extern MMI_BOOL mmi_imui_create_ime_indicator(void);
extern void mmi_imui_close_ime_indicator(void);
extern void mmi_imui_update_ime_indicator(void);
#endif

#ifdef __MMI_CSTAR_PHRASE_INPUT__
extern void mmi_imui_set_active_control(mmi_imui_control_type_enum control);
extern mmi_imui_control_type_enum mmi_imui_get_active_control(void);
extern void mmi_imui_set_active_control_by_ui_msg(mmi_imui_message_struct_p msg_ptr);
#endif

#endif /* !defined(__IMUI_API_H__) */ 

