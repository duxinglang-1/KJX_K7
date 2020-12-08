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
 *  photoeditorcui.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PhotoEditor CUI header file
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _PHOEDT_CUI_H_
#define _PHOEDT_CUI_H_

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_PHOTOEDITOR__


#include "photoeditorcuigprot.h"

#include "Gdi_include.h"
#include "FileMgrSrvGProt.h"


#include "PhotoEditorCuiConfig.h"
#include "ImgEdtSrvGProt.h"
#include "GlobalConstants.h"


#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif


/* include filename and ext filename */
#define PHOEDT_FULL_PATH_CHAR               (SRV_FMGR_PATH_MAX_LEN)
#define PHOEDT_FULL_PATH_BUFFER_LEN         (PHOEDT_FULL_PATH_CHAR + 1)


/* include filename and ext filename */
#define PHOEDT_DRV_PATH_CHAR                (3)
#define PHOEDT_DRV_PATH_BUFFER_LEN          (PHOEDT_DRV_PATH_CHAR + 1)


#define PHOEDT_RES_DUMMY_ID                 (0)


/*****************************************************************************
* Define
*****************************************************************************/
#ifdef __MMI_FTE_SUPPORT__
#define __MMI_PHOEDT_STYLE_FTE__
#ifdef __MMI_TOUCH_SCREEN__
#define __MMI_PHOEDT_STYLE_FTE_CLIP__
#endif
#endif

#ifdef __MMI_TOUCH_SCREEN__
#define __MMI_PHOEDT_DOODLE__
#endif


#define PHOEDT_ALIGN_BYTES         (4)


#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
#if defined(__MMI_MAINLCD_320X480__)
#define PHOEDT_MIN_IMG_WIDTH                (30)    /* (g_phoedt_layout.clip_indicator_sel_size.w) */
#define PHOEDT_MIN_IMG_HEIGHT               (30)    /* (g_phoedt_layout.clip_indicator_sel_size.h) */
#else /* defined(__MMI_MAINLCD_320X480__) */
#define PHOEDT_MIN_IMG_WIDTH                (23)    /* (g_phoedt_layout.clip_indicator_sel_size.w) */
#define PHOEDT_MIN_IMG_HEIGHT               (23)    /* (g_phoedt_layout.clip_indicator_sel_size.h) */
#endif /* defined(__MMI_MAINLCD_320X480__) */
#else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
#define PHOEDT_MIN_IMG_WIDTH                (10)    /* mininum editable source image width */
#define PHOEDT_MIN_IMG_HEIGHT               (10)    /* mininum editable source image height */
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */


/* memory config***************************************************************/
#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
#define PHOEDT_LAYER_BITS_PER_PIXEL (24)
#define PHOEDT_CURRENT_COLOR_FORMAT (GDI_COLOR_FORMAT_24)
#else
#define PHOEDT_LAYER_BITS_PER_PIXEL (GDI_MAINLCD_BIT_PER_PIXEL)
#define PHOEDT_CURRENT_COLOR_FORMAT (GDI_COLOR_FORMAT_16)
#endif

#define PHOEDT_FRAME_BUFFER_SIZE    ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT * PHOEDT_LAYER_BITS_PER_PIXEL)>>3)
#define PHOEDT_IES_BUFFER_SIZE      (1024 * 1024 * 6)

#define PHOEDT_CUI_CNTX_SIZE        (sizeof(phoedt_cui_cntx_struct) + \
                                     (PHOEDT_ALIGN_BYTES - (sizeof(phoedt_cui_cntx_struct) % PHOEDT_ALIGN_BYTES)))

#define PHOEDT_CUI_NEED_SIZE        (PHOEDT_FRAME_BUFFER_SIZE + PHOEDT_IES_BUFFER_SIZE + PHOEDT_CUI_CNTX_SIZE)
/* memory config***************************************************************/


#define PHOEDT_IMAGE_CANVAS_COLOR           (GDI_COLOR_BLACK)
#define PHOEDT_IMAGE_BORDER_COLOR           (GDI_COLOR_WHITE)
#define PHOEDT_IMAGE_BORDER_WIDTH           (1)

#define PHOEDT_ICON_BORDER_COLOR            (GDI_COLOR_RED)
#define PHOEDT_ICON_BORDER_CORNER_LENGH     (4)
#define PHOEDT_ICON_BORDER_WIDTH            (2)
#define PHOEDT_ICON_BORDER_GAP              (PHOEDT_ICON_BORDER_WIDTH + 2)  /* reserve 2 more pixels for avoid border overlap with icon */


#if defined(__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X480__)
#define PHOEDT_MATRIX_ICONS_PER_ROW         (4)
#define PHOEDT_MATRIX_ICONS_PER_COL         (5)
#else /* __MMI_MAINLCD_240X400__ */
#define PHOEDT_MATRIX_ICONS_PER_ROW         (3)
#define PHOEDT_MATRIX_ICONS_PER_COL         (3)
#endif /* __MMI_MAINLCD_240X400__ */


#define PHOEDT_FRAME_COUNT                  (IMG_ID_PHOEDT_FRAME_END - IMG_ID_PHOEDT_FRAME_START - 1)
#define PHOEDT_ICON_COUNT                   (IMG_ID_PHOEDT_ICON_END - IMG_ID_PHOEDT_ICON_START - 1)


#ifndef __MMI_PHOEDT_STYLE_FTE_CLIP__
#define PHOEDT_CLIP_RECT_COLOR              (GDI_COLOR_RED)
#define PHOEDT_CLIP_RECT_WIDTH              (1)
#define PHOEDT_CLIP_RECT_WIDTH_SEL          (2)
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */


#define PHOEDT_CLIP_RECT_MAX_RATIO          (100)
#define PHOEDT_CLIP_RECT_MIN_RATIO          (10)
#define PHOEDT_CLIP_RECT_STEP_RATION        (10)
#define PHOEDT_CLIP_RECT_DEFAULT_RATIO      (50)


#define PHOEDT_CLIP_EDGE_RANGE_RADIUS       (5)


#define PHOEDT_IMAGE_ZOOMIN_STEP            (120)


#define PHOEDT_TEXT_COLOR_COUNT             (23)


#define PHOEDT_MOVE_STEP_MIN                (1)
#define PHOEDT_MOVE_STEP_MAX                (7)
#define PHOEDT_MOVE_STEP_DIFF               (2)
#define PHOEDT_MOVE_STEP_DURATION           (100)


/* exclude ext filename */
#define PHOEDT_MAX_FILENAME_CHAR            (20)
#define PHOEDT_MAX_FILENAME_EXT_CHAR        (SRV_FMGR_PATH_MAX_FILE_EXT_LEN)


/* include "." & ext filename */
#define PHOEDT_FULL_FILENAME_CHAR           (PHOEDT_MAX_FILENAME_CHAR + 1 + PHOEDT_MAX_FILENAME_EXT_CHAR)
#define PHOEDT_FULL_FILENAME_BUFFER_LEN     (PHOEDT_FULL_FILENAME_CHAR + 1)


#define PHOEDT_ADD_ICON_DEF_SIZE            (50)  /* default width of add icon */
#define PHOEDT_ADD_ICON_MAX_SIZE            ((g_phoedt_cui_cntx_p->display_info.img_rect.size.h <       \
                                              g_phoedt_cui_cntx_p->display_info.img_rect.size.w ?       \
                                              g_phoedt_cui_cntx_p->display_info.img_rect.size.h :       \
                                              g_phoedt_cui_cntx_p->display_info.img_rect.size.w) /      \
                                             PHOEDT_ADD_ICON_ZOOM_STEP * PHOEDT_ADD_ICON_ZOOM_STEP)
#define PHOEDT_ADD_ICON_MIN_SIZE            (20)
#define PHOEDT_ADD_ICON_ZOOM_STEP           (10)


#define PHOEDT_MAX_TITLE_CHARACTERS         (MAX_SUBMENU_CHARACTERS)


#define PHOEDT_UPDATE_PROGRESS_DURATION     (100)


#define PHOEDT_DOODLE_UPDATE_RADIUS         (5)


#define PHOEDT_KEY_MAP_ZOOM_OUT             (KEY_POUND)
#define PHOEDT_KEY_MAP_ZOOM_IN              (KEY_STAR)
#define PHOEDT_KEY_MAP_MANUAL_CLIP_STATE    (KEY_STAR)
#define PHOEDT_KEY_MAP_ROTATE_CW            (KEY_RIGHT_ARROW)
#define PHOEDT_KEY_MAP_ROTATE_CCW           (KEY_LEFT_ARROW)
#define PHOEDT_KEY_MAP_FLIP_HORZ_1          (KEY_RIGHT_ARROW)
#define PHOEDT_KEY_MAP_FLIP_HORZ_2          (KEY_LEFT_ARROW)
#define PHOEDT_KEY_MAP_FLIP_VERT_1          (KEY_UP_ARROW)
#define PHOEDT_KEY_MAP_FLIP_VERT_2          (KEY_DOWN_ARROW)
#define PHOEDT_KEY_MAP_ICON_ROTATE          (KEY_0)


/*****************************************************************************
* typedef
*****************************************************************************/
typedef enum
{
    PHOEDT_CONFIRM_TYPE_SAVE_FOR_SEND,
    PHOEDT_CONFIRM_TYPE_UNDO,
    PHOEDT_CONFIRM_TYPE_EXIT,

    PHOEDT_CONFIRM_TYPE_COUNT
} phoedt_confirm_type_enum;


typedef enum
{
    PHOEDT_PATH_RELATIONSHIP_NONE,
    PHOEDT_PATH_RELATIONSHIP_SAME_DRV,
    PHOEDT_PATH_RELATIONSHIP_N_LINE_FOLDER,
    PHOEDT_PATH_RELATIONSHIP_1_LINE_FOLDER,
    PHOEDT_PATH_RELATIONSHIP_SAME_FILE,

    PHOEDT_PATH_RELATIONSHIP_COUNT
} phoedt_path_relationship_enum;


typedef enum
{
    PHOEDT_CHANGE_TYPE_CHANGE,
    PHOEDT_CHANGE_TYPE_UNDO,
    PHOEDT_CHANGE_TYPE_RESET,

    PHOEDT_CHANGE_TYPE_COUNT
} phoedt_change_type_enum;


typedef enum
{
    PHOEDT_SAVE_STATE_BEGINED,
    PHOEDT_SAVE_STATE_SAVING,
    PHOEDT_SAVE_STATE_SAVED,
    PHOEDT_SAVE_STATE_CANCELED,

    PHOEDT_SAVE_STATE_COUNT
} phoedt_save_state_enum;


typedef enum
{
    PHOEDT_SAVE_RESULT_DONE,
    PHOEDT_SAVE_RESULT_CANCELED,
    PHOEDT_SAVE_RESULT_ERROR,
    PHOEDT_SAVE_RESULT_IN_END_KEY,

    PHOEDT_SAVE_RESULT_COUNT
}phoedt_save_result_enum;


typedef enum
{
    PHOEDT_FILE_SOURCE_FROM_FILE,
    PHOEDT_FILE_SOURCE_FROM_CAMERA,

    PHOEDT_SEL_FILE_OPTION_COUNT
}phoedt_file_source_enum;


typedef enum
{
    PHOEDT_ACTION_TYPE_NONE,
    PHOEDT_ACTION_TYPE_LOADING,
    PHOEDT_ACTION_TYPE_FRAME,
    PHOEDT_ACTION_TYPE_EFFECT,
    PHOEDT_ACTION_TYPE_ADJUST,
    PHOEDT_ACTION_TYPE_ICON,
    PHOEDT_ACTION_TYPE_CLIP,
    PHOEDT_ACTION_TYPE_FLIP,
    PHOEDT_ACTION_TYPE_ROTATE,
#ifdef __MMI_PHOEDT_DOODLE__
    PHOEDT_ACTION_TYPE_DOODLE,
#endif

    PHOEDT_ACTION_TYPE_SAVE_FILE,
    PHOEDT_ACTION_TYPE_SAVE_FOR_SEND,
    PHOEDT_ACTION_TYPE_SEND,
    PHOEDT_ACTION_TYPE_UNDO,
    PHOEDT_ACTION_TYPE_HELP,

    PHOEDT_ACTION_TYPE_COUNT
}phoedt_action_type_enum;


typedef enum
{
    PHOEDT_ACTION_STATE_ENDED,
    PHOEDT_ACTION_STATE_STARTED,

    PHOEDT_ACTION_STATE_COUNT
}phoedt_action_state_enum;


typedef enum
{
    PHOEDT_MOVE_DIR_LEFT,
    PHOEDT_MOVE_DIR_RIGHT,
    PHOEDT_MOVE_DIR_UP,
    PHOEDT_MOVE_DIR_DOWN,

    PHOEDT_MOVE_DIR_COUNT
}phoedt_move_direction_enum;


typedef enum
{
    PHOEDT_CLIP_TYPE_FIX_RATIO,
    PHOEDT_CLIP_TYPE_MANUAL_CLIP,

    PHOEDT_CLIP_TYPE_COUNT
} phoedt_clip_type_enum;


typedef enum
{
    PHOEDT_ADJUST_STATIC_OBJ_TYPE_ICON,
    PHOEDT_ADJUST_STATIC_OBJ_TYPE_BAR,
#ifdef __MMI_PHOEDT_STYLE_FTE__
    PHOEDT_ADJUST_STATIC_OBJ_TYPE_BG,
#endif

    PHOEDT_ADJUST_STATIC_OBJ_TYPE_COUNT
}phoedt_adjust_static_obj_type_enum;


typedef enum
{
    PHOEDT_CLIP_STATE_RIGHTDOWN,
    PHOEDT_CLIP_STATE_LEFTUP,
#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    PHOEDT_CLIP_STATE_RIGHTUP,
    PHOEDT_CLIP_STATE_LEFTDOWN,
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
    PHOEDT_CLIP_STATE_MOVE,

    PHOEDT_CLIP_STATE_COUNT
}phoedt_clip_state_enum;


typedef enum
{
    PHOEDT_CLIP_RECT_ADJUST_EDGE_UP,
    PHOEDT_CLIP_RECT_ADJUST_EDGE_DOWN,
    PHOEDT_CLIP_RECT_ADJUST_EDGE_LEFT,
    PHOEDT_CLIP_RECT_ADJUST_EDGE_RIGHT,

    PHOEDT_CLIP_RECT_ADJUST_EDGE_COUNT
}phoedt_clip_rect_adjust_edge_enum;


typedef enum
{
    PHOEDT_ROTATE_0,
    PHOEDT_ROTATE_90,
    PHOEDT_ROTATE_180,
    PHOEDT_ROTATE_270,

    PHOEDT_ROTATE_COUNT
}phoedt_rotate_enum;


typedef enum
{
    PHOEDT_ROTATE_DIR_CCW,
    PHOEDT_ROTATE_DIR_CW,

    PHOEDT_ROTATE_DIR_COUNT
}phoedt_rotate_direction_enum;


typedef enum
{
    PHOEDT_FLIP_DIR_HORI,
    PHOEDT_FLIP_DIR_VERT,

    PHOEDT_FLIP_DIR_COUNT
}phoedt_flip_direction_enum;


typedef enum
{
    PHOEDT_SWITCH_DIR_PREV,
    PHOEDT_SWITCH_DIR_NEXT,

    PHOEDT_SWITCH_DIR_COUNT
}phoedt_switch_direction_enum;


#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
typedef enum
{
    PHOEDT_CLIP_INDICATOR_LEFTUP,
    PHOEDT_CLIP_INDICATOR_RIGHTUP,
    PHOEDT_CLIP_INDICATOR_LEFTDOWN,
    PHOEDT_CLIP_INDICATOR_RIGHTDOWN,

    PHOEDT_CLIP_INDICATOR_COUNT
}phoedt_clip_indicator_enum;
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */


#ifdef __MMI_PHOEDT_DOODLE__
typedef enum
{
    PHOEDT_DOODLE_TYPE_LINE,
    PHOEDT_DOODLE_TYPE_ERASER,

    PHOEDT_DOODLE_TYPE_COUNT
}phoedt_doodle_type_enum;


typedef enum
{
#ifdef __MMI_PHOEDT_STYLE_FTE__
    PHOEDT_DOODLE_SIZE_LARGE,
    PHOEDT_DOODLE_SIZE_MEDIUM,
    PHOEDT_DOODLE_SIZE_SMALL,
#else
    PHOEDT_DOODLE_SIZE_SMALL,
    PHOEDT_DOODLE_SIZE_MEDIUM,
    PHOEDT_DOODLE_SIZE_LARGE,
#endif

    PHOEDT_DOODLE_SIZE_COUNT
}phoedt_doodle_size_enum;
#endif /* __MMI_PHOEDT_DOODLE__ */


#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    PHOEDT_PEN_EVENT_DOWN,
    PHOEDT_PEN_EVENT_MOVE,
    PHOEDT_PEN_EVENT_UP,

    PHOEDT_PEN_EVENT_COUNT
}phoedt_pen_event_enum;


typedef enum
{
    /* nothing */
    PHOEDT_TOUCH_ITEM_NONE,

    /* softkeys */
    PHOEDT_TOUCH_ITEM_LSK,
    PHOEDT_TOUCH_ITEM_RSK,
    PHOEDT_TOUCH_ITEM_CSK,

    /* arrows */
    PHOEDT_TOUCH_ITEM_PREV,
    PHOEDT_TOUCH_ITEM_NEXT,

    /* adjust */
    PHOEDT_TOUCH_ITEM_ADJUST_ICON,
    /* here will have serveral items */
    PHOEDT_TOUCH_ITEM_ADJUST_ICON_END = PHOEDT_TOUCH_ITEM_ADJUST_ICON + PHOEDT_ADJUST_ITEM_TOTAL_COUNT,
    PHOEDT_TOUCH_ITEM_ADJUST_BAR,
    PHOEDT_TOUCH_ITEM_ADJUST_SLIDER,

    /* clip */
    PHOEDT_TOUCH_ITEM_CLIP_RECT,
    PHOEDT_TOUCH_ITEM_CLIP_LEFTUP,
    PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN,
#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN,
    PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP,
#else
    PHOEDT_TOUCH_ITEM_CLIP_UP,
    PHOEDT_TOUCH_ITEM_CLIP_DOWN,
    PHOEDT_TOUCH_ITEM_CLIP_LEFT,
    PHOEDT_TOUCH_ITEM_CLIP_RIGHT,
    PHOEDT_TOUCH_ITEM_CLIP_ZOOMIN,
    PHOEDT_TOUCH_ITEM_CLIP_ZOOMOUT,
    PHOEDT_TOUCH_ITEM_CLIP_STATE_ICON,
#endif

    /* flip */
    PHOEDT_TOUCH_ITEM_FLIP_VERT,
    PHOEDT_TOUCH_ITEM_FLIP_HORZ,

    /* rotate */
    PHOEDT_TOUCH_ITEM_ROTATE_CCW,
    PHOEDT_TOUCH_ITEM_ROTATE_CW,

    /* add icon */
    PHOEDT_TOUCH_ITEM_ICON_ICON,
    PHOEDT_TOUCH_ITEM_ICON_ZOOMIN,
    PHOEDT_TOUCH_ITEM_ICON_ZOOMOUT,
    PHOEDT_TOUCH_ITEM_ICON_ROTATE,

    /* add frame & select area for doodle */
    PHOEDT_TOUCH_ITEM_SEL_AREA_IMAGE,
    PHOEDT_TOUCH_ITEM_SEL_AREA_ZOOMIN,
    PHOEDT_TOUCH_ITEM_SEL_AREA_ZOOMOUT,

#ifdef __MMI_PHOEDT_DOODLE__
    /* doodle */
    PHOEDT_TOUCH_ITEM_DOODLE_DOODLE,
    PHOEDT_TOUCH_ITEM_DOODLE_HIDE,
    PHOEDT_TOUCH_ITEM_DOODLE_COLOR,
#ifdef __MMI_PHOEDT_STYLE_FTE__
    PHOEDT_TOUCH_ITEM_DOODLE_LINE_1,
    PHOEDT_TOUCH_ITEM_DOODLE_LINE_2,
    PHOEDT_TOUCH_ITEM_DOODLE_LINE_3,
    PHOEDT_TOUCH_ITEM_DOODLE_ERASER_1,
    PHOEDT_TOUCH_ITEM_DOODLE_ERASER_2,
    PHOEDT_TOUCH_ITEM_DOODLE_ERASER_3,
#else /* __MMI_PHOEDT_STYLE_FTE__ */
    PHOEDT_TOUCH_ITEM_DOODLE_TYPE,
    PHOEDT_TOUCH_ITEM_DOODLE_SIZE,
#endif /* __MMI_PHOEDT_STYLE_FTE__ */
#endif /* __MMI_PHOEDT_DOODLE__ */

    PHOEDT_TOUCH_ITEM_COUNT
} phoedt_touch_item_enum;
#endif /* __MMI_TOUCH_SCREEN__ */


typedef struct
{
    S32 x;
    S32 y;
}phoedt_pos_struct;


typedef struct
{
    S32 w;
    S32 h;
}phoedt_size_struct;


typedef struct
{
    phoedt_size_struct      img_size;
}phoedt_input_limit_struct;


typedef struct
{
#ifdef __MMI_PHOEDT_STYLE_FTE__
    phoedt_size_struct      adjust_bg_size;
    phoedt_pos_struct       adjust_first_bg;
#endif
    phoedt_size_struct      adjust_icon_size;
    phoedt_pos_struct       adjust_first_icon;
    phoedt_size_struct      adjust_bar_size;
    phoedt_pos_struct       adjust_first_bar;
    U16                     adjust_bar_margin;
    phoedt_size_struct      adjust_slider_size;
    S16                     adjust_slider_off_y_on_bar;
    U16                     adjust_icon_interval;

#ifdef __MMI_PHOEDT_DOODLE__
#ifdef __MMI_PHOEDT_STYLE_FTE__
    phoedt_size_struct      doodle_up_down_size;
    phoedt_size_struct      doodle_button_size;
    phoedt_size_struct      doodle_color_rect_size;
#ifdef __MMI_PHOEDT_STYLE_FTE__
    phoedt_size_struct      doodle_bg_expand_size;
    phoedt_size_struct      doodle_bg_collapse_size;
    phoedt_pos_struct       doodle_bg;
#else
    phoedt_pos_struct       doodle_line_bg;
    phoedt_pos_struct       doodle_eraser_bg;
    phoedt_pos_struct       doodle_bg_bottom_long;
    phoedt_pos_struct       doodle_bg_bottom_short;
#endif
    phoedt_pos_struct       doodle_up_down;
    phoedt_pos_struct       doodle_line_title;
    phoedt_pos_struct       doodle_line[PHOEDT_DOODLE_SIZE_COUNT];
    phoedt_pos_struct       doodle_color;
    phoedt_pos_struct       doodle_color_rect;
    phoedt_pos_struct       doodle_eraser_title_long;
    phoedt_pos_struct       doodle_eraser_title_short;
    phoedt_pos_struct       doodle_eraser[PHOEDT_DOODLE_SIZE_COUNT];
#else
    phoedt_size_struct      doodle_button_size;
    phoedt_pos_struct       doodle_hide;
    phoedt_pos_struct       doodle_type;
    phoedt_pos_struct       doodle_size;
    phoedt_pos_struct       doodle_color;
#endif /* __MMI_PHOEDT_STYLE_FTE__ */
#endif /* __MMI_PHOEDT_DOODLE__ */

#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    phoedt_size_struct      clip_indicator_size;
    phoedt_size_struct      clip_indicator_sel_size;
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */

    phoedt_size_struct      arrow_size;
    phoedt_pos_struct       left_arrow;
    phoedt_pos_struct       right_arrow;

    phoedt_size_struct      button_size;

    phoedt_pos_struct       button_21;
    phoedt_pos_struct       button_22;

    phoedt_pos_struct       button_31;
    phoedt_pos_struct       button_32;
    phoedt_pos_struct       button_33;
}phoedt_layout_struct;


typedef struct
{
    phoedt_pos_struct    offset;
    phoedt_size_struct   size;
}phoedt_rect_struct;


typedef struct
{
    phoedt_rect_struct      img_rect;   /* ref to LCD */
}phoedt_display_info_struct;


typedef struct
{
    phoedt_size_struct      curr_size;
    phoedt_size_struct      org_size;
    phoedt_rect_struct      shown_rect; /* ref to image */
}phoedt_image_info_struct;


typedef struct
{
#ifndef __MMI_PHOEDT_STYLE_FTE_CLIP__
    U16                             scale_ratio;
    U16                             curr_min_ratio;
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
    phoedt_size_struct              w_h_ratio;
}phoedt_clip_ratio_struct;


typedef union
{
    phoedt_clip_state_enum          clip_state;
    phoedt_clip_ratio_struct        clip_ratio;
}phoedt_clip_state_union;


typedef struct
{
    U32                             step;
    phoedt_move_direction_enum      direction;
}phoedt_move_info_struct;


typedef struct
{
    MMI_BOOL                    horz;
    MMI_BOOL                    vert;
}phoedt_flip_para_struct;


typedef struct
{
    U16                         frame_idx;
    phoedt_move_info_struct     move_info;
}phoedt_frame_para_struct;


typedef struct
{
    phoedt_clip_type_enum       clip_type;
    phoedt_clip_state_union     state;
    phoedt_rect_struct          clip_rect;  /* ref to LCD */
    phoedt_move_info_struct     move_info;
}phoedt_clip_para_struct;


typedef struct
{
    U16                     icon_idx;
    phoedt_pos_struct       location;       /* icon location on the screen */
    S32                     size;           /* icon size on the screen */
    S32                     max;            /* icon limit on the screen */
    S32                     min;            /* icon limit on the screen */
    S32                     srv_max;        /* icon limit on the image */
    S32                     srv_min;        /* icon limit on the image */
    phoedt_rotate_enum      rotate;
    phoedt_move_info_struct move_info;
}phoedt_add_icon_para_struct;


#ifdef __MMI_PHOEDT_DOODLE__
typedef struct
{
    phoedt_move_info_struct     move_info;
    MMI_BOOL                    is_hide_osd;
    srv_ies_doodle_info_handle  ies_doodle_hdle;
    phoedt_doodle_type_enum     type;
    phoedt_doodle_size_enum     size;
    phoedt_doodle_size_enum     eraser_size;
    U16                         color_idx;
}phoedt_doodle_para_struct;
#endif /* #define __MMI_PHOEDT_DOODLE__ */


typedef void (*callback)(void);
typedef void (*phoedt_save_callback)(phoedt_save_result_enum);

typedef struct
{
    srv_ies_job_handle          job;
    GDI_HANDLE                  loading_hdl;
}phoedt_loading_para_struct;


typedef struct
{
    phoedt_save_state_enum      state;
    srv_ies_job_handle          job;
    phoedt_size_struct          output_size;
    MMI_BOOL                    is_bg_save;
    MMI_BOOL                    is_in_end_key;
    MMI_ID                      parent_gid;
    phoedt_save_callback        callback;
}phoedt_save_para_struct;


typedef struct
{
    MMI_MENU_ID                 item;
}phoedt_help_para_struct;


typedef struct
{
    U16                         idx;
    U16                         curr_item_idx;
}phoedt_adjust_para_struct;


typedef struct
{
    U16                         idx;
}phoedt_effect_para_struct;


typedef struct
{
    S32                 min;
    S32                 max;
    S32                 init;
    S32                 value;
    S32                 step;
}phoedt_adjust_range_struct;


typedef struct
{
    srv_ies_effect_enum id;
    MMI_STR_ID          name;
}phoedt_effect_struct;


typedef struct
{
    MMI_BOOL                        is_used;
    MMI_STR_ID                      name;
    MMI_IMG_ID                      icon;
    MMI_IMG_ID                      icon_sel;
    phoedt_adjust_range_struct      para;
}phoedt_adjust_item_struct;


typedef struct
{
    srv_ies_effect_enum                 id;
    MMI_STR_ID                          name;
    U16                                 para_count;
    phoedt_adjust_item_struct           *para_items;
}phoedt_adjust_struct;


typedef struct
{
    phoedt_effect_struct                effects[PHOEDT_EFFECT_MAX_COUNT];
    phoedt_adjust_struct                adjusts[PHOEDT_ADJUST_MAX_COUNT];
    phoedt_adjust_item_struct           adjust_para_items[PHOEDT_ADJUST_ITEM_TOTAL_COUNT];
    U32                                 effect_count;
    U32                                 adjust_count;
}phoedt_ies_capacity_info_struct;


typedef union
{
    phoedt_loading_para_struct  loading;
    phoedt_save_para_struct     save;
    phoedt_effect_para_struct   effect;
    phoedt_adjust_para_struct   adjust;
    phoedt_frame_para_struct    frame;
    phoedt_rotate_enum          rotate;
    phoedt_flip_para_struct     flip;
    phoedt_clip_para_struct     clip;
    phoedt_add_icon_para_struct icon;

#ifdef __MMI_PHOEDT_DOODLE__
    phoedt_doodle_para_struct   doodle;
#endif /* #ifdef __MMI_PHOEDT_DOODLE__ */

    phoedt_help_para_struct     help;
}phoedt_action_para_union;


typedef struct
{
    phoedt_action_type_enum         action;
    phoedt_action_state_enum        state;
    MMI_BOOL                        preview_after_end;
    phoedt_action_para_union        para;
}phoedt_action_struct;


typedef struct
{
    WCHAR                               filepath[PHOEDT_FULL_PATH_BUFFER_LEN];
}phoedt_original_file_info_struct;


typedef struct
{
    WCHAR                               filepath[PHOEDT_FULL_PATH_BUFFER_LEN];
    WCHAR                               filename[PHOEDT_FULL_FILENAME_BUFFER_LEN];
}phoedt_new_file_info_struct;


typedef struct
{
    S32                                 select_idx;
}phoedt_item_selector_struct;


typedef struct
{
    MMI_BOOL                            is_key_down;
    mmi_keypads_enum                    key_code;
}phoedt_key_context_struct;


#ifdef __MMI_TOUCH_SCREEN__
typedef struct
{
    wgui_component_info_struct          lsk;
    wgui_component_info_struct          csk;
    wgui_component_info_struct          rsk;

#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    wgui_component_info_struct          clip_indicators[PHOEDT_CLIP_INDICATOR_COUNT];
#endif

    wgui_component_info_struct          adjust_slider;
}phoedt_dynamic_components_struct;


typedef struct
{
    MMI_BOOL                            is_pen_down;
    phoedt_pos_struct                   last_pos;
    phoedt_touch_item_enum              obj;
    phoedt_dynamic_components_struct    dyn_comp;
}phoedt_touch_screen_context_struct;
#endif /* __MMI_TOUCH_SCREEN__ */


typedef struct
{
    srv_ies_image_handle                img;
    srv_ies_app_session_handle          session;
    srv_ies_preview_handle              preview;
    srv_ies_meta_handle                 meta;
}phoedt_ies_handle_struct;


typedef struct
{
    WCHAR*                  message;
    WCHAR*                  sub_message;
    U8                      percent;
}phoedt_cat6003_cntx_struct;


typedef struct
{
    MMI_BOOL                            is_available;
    MMI_MENU_ID                         parent_menu_id;
}phoedt_send_cntx_struct;


typedef struct
{
    phoedt_action_type_enum             changes[PHOEDT_LIMIT_CHANGE_COUNT_TOTAL];
    U32                                 count;
}phoedt_change_cntx_struct;


typedef struct
{
    GDI_HANDLE                          prcessing_icon_handle;
    srv_ies_job_handle                  job;
}phoedt_nb_preview_cntx_struct;


typedef struct
{
    MMI_ID                              cui_gid;

    MMI_BOOL                            is_external_mem;

    MMI_BOOL                            undo_available;

    phoedt_change_cntx_struct           change_cntx;

    phoedt_cat6003_cntx_struct          cat6003_cntx;

    phoedt_nb_preview_cntx_struct       nb_preview_cntx;

    phoedt_send_cntx_struct             send_cntx;

    phoedt_ies_capacity_info_struct     ies_capacity;
    PU8                                 ies_buf;
    phoedt_ies_handle_struct            ies_hdles;

    gdi_handle                          preview_layer;
    PU8                                 preview_buf;
    gdi_handle                          osd_layer;

    phoedt_display_info_struct          display_info;
    phoedt_image_info_struct            image_info;

    phoedt_original_file_info_struct    org_file;
    phoedt_new_file_info_struct         new_file;

    phoedt_action_struct                curr_act;

    phoedt_item_selector_struct         item_selector;

    phoedt_key_context_struct           key_cntx;

#ifdef __MMI_TOUCH_SCREEN__
    phoedt_touch_screen_context_struct  touch_cntx;
#endif /* __MMI_TOUCH_SCREEN__ */
}phoedt_cui_cntx_struct;


typedef struct
{
    MMI_ID                  self_gid;
    PU8                     memory;
    MMI_BOOL                is_send_available;
    WCHAR                   filepath_buf[PHOEDT_FULL_PATH_BUFFER_LEN];
}phoedt_cui_run_para_struct;


/* these APIs are used by PhotoArtEX.c */
extern MMI_STR_ID cui_phoedt_is_supported_format_ext(const WCHAR *filepath);
extern void cui_phoedt_run_ext(
    MMI_ID cui_gid, p_cui_phoedt_run_struct p_args,
    PU8 memory, U32 memory_size, MMI_BOOL is_send_available);
extern mmi_ret cui_phoedt_fmgr_notify_hdlr(mmi_event_struct *evt);

#endif /* __MMI_PHOTOEDITOR__ */
#endif /* _PHOEDT_CUI_H_ */

