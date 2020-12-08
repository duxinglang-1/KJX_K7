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
 *  photoeditorcui.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PhotoEditor CUI program file
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
 *
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
#ifndef _PHOEDT_CUI_C_
#define _PHOEDT_CUI_C_

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_PHOTOEDITOR__

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "photoeditorcui.h"
#include "PhotoEditor.h"
#include "Mmi_rp_app_phoedt_def.h"
#include "Drm_def.h"
#include "Drm_gprot.h"  /* DRM support */
#include "MMI_trc_Int.h"
#include "MMI_media_app_trc.h"
#include "Unicodexdcl.h"
#include "Filemgrcuigprot.h"
#include "Menucuigprot.h"
#include "PhotoEditorCuiConfig.h"
#include "CommonScreens.h"      /* Popup screens */
#include "CommonScreensResDef.h"
#include "wgui_categories_fmgr.h"
#include "FileMgrResDef.h"      /* fmgr string */
#include "FileMgrType.h"
#include "Drm_gprot.h"          /* DRM support */
#include "Gui_font_size.h"      /* gui_font_get_type */
#include "GPIOSrvGProt.h"
#include "CustMenuRes.h"        /* GetNumOfChild_Ext */
#include "wgui_categories_util.h"   /* GetRootTitleIcon */
#include "wgui_categories_popup.h"  /* wgui_cat6003_show */
#include "wgui_categories_text_viewer.h"    /* category74 */
#include "wgui_include.h"       /* wgui_softkey_get_offset */


/*****************************************************************************
* Define
*****************************************************************************/
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define PHOEDT_CUI_DISPLAY_POPUP_CONFIRM(parent_gid, message_str, confirm_type)   \
    do{                                                             \
        mmi_confirm_property_struct arg;                            \
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);           \
        arg.callback = cui_phoedt_confirm_proc;                     \
        arg.parent_id = (parent_gid);                               \
        arg.user_tag = (void*)(confirm_type);                       \
        mmi_confirm_display(                                        \
            (WCHAR*)(message_str),                                  \
            MMI_EVENT_QUERY,                                        \
            &arg);                                                  \
    }while(MMI_FALSE)

#define PHOEDT_CUI_DISPLAY_POPUP(parent_gid, message_str, event_id)     \
    mmi_popup_display_simple(                   \
        (WCHAR*)(message_str),                  \
        (mmi_event_notify_enum)(event_id),      \
        (parent_gid),                           \
        NULL)

#define PHOEDT_SEND_TO_PARENT(event_id, filepath)   \
    do{                                                                                                     \
        if(NULL != g_phoedt_cui_cntx_p && g_phoedt_cui_cntx_p->cui_gid != GRP_ID_INVALID)                   \
        {                                                                                                   \
            cui_phoedt_event_struct evt;                                                                    \
            MMI_FRM_INIT_GROUP_EVENT(&evt, event_id, g_phoedt_cui_cntx_p->cui_gid);                         \
            evt.file_path = (filepath);                                                                     \
            mmi_frm_group_send_to_parent(g_phoedt_cui_cntx_p->cui_gid, (mmi_group_event_struct*)&evt);      \
        }                                                                                                   \
    }while(MMI_FALSE)

#define PHOEDT_SEND_TO_PARENT_NO_RESULT(event_id)   \
    do{                                         \
        if(NULL != g_phoedt_cui_cntx_p && g_phoedt_cui_cntx_p->cui_gid != GRP_ID_INVALID)                   \
        {                                                                                                   \
            cui_phoedt_event_struct evt;                                                                    \
            MMI_FRM_INIT_GROUP_EVENT(&evt, event_id, g_phoedt_cui_cntx_p->cui_gid);                         \
            evt.file_path = NULL;                                                                           \
            mmi_frm_group_send_to_parent(g_phoedt_cui_cntx_p->cui_gid, (mmi_group_event_struct*)&evt);      \
        }                                                                                                   \
    }while(MMI_FALSE)

#define PHOEDT_SEND_TO_PARENT_NO_RESULT_WITH_GID(gid, event_id)   \
    do{                                         \
        cui_phoedt_event_struct evt;                                                                        \
        MMI_FRM_INIT_GROUP_EVENT(&evt, event_id, gid);                                                      \
        evt.file_path = NULL;                                                                               \
        mmi_frm_group_send_to_parent(gid, (mmi_group_event_struct*)&evt);                                   \
    }while(MMI_FALSE)

#define CUI_PHOEDT_DRAW_SOFTKEY(lsk_str, rsk_str, is_clear_bg, csk_icon)    \
    cui_phoedt_draw_softkey(        \
        lsk_str,                    \
        rsk_str,                    \
        is_clear_bg,                \
        csk_icon)

#define PHOEDT_TRACE_IES_RESULT(ret)                    \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IES_RESULT, ret, __LINE__)

#define PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ret)         \
    cui_phoedt_handle_ies_err_code(g_phoedt_cui_cntx_p->cui_gid, ret, __LINE__)

#define PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(gid, ret)    \
    cui_phoedt_handle_ies_err_code(gid, ret, __LINE__)

#define PHOEDT_LSK_UP_TEXT_COLOR                (*current_MMI_theme->LSK_up_text_color)
#define PHOEDT_LSK_DOWN_TEXT_COLOR              (*current_MMI_theme->LSK_down_text_color)
#define PHOEDT_RSK_UP_TEXT_COLOR                (*current_MMI_theme->RSK_up_text_color)
#define PHOEDT_RSK_DOWN_TEXT_COLOR              (*current_MMI_theme->RSK_down_text_color)
#define PHOEDT_SOFTKEY_TEXT_BORDER_COLOR        (*current_MMI_theme->softkey_text_border_color)
#define PHOEDT_SOFTKEY_DOWN_TEXT_BORDER_COLOR   (*current_MMI_theme->softkey_down_text_border_color)
#define PHOEDT_TITLE_TEXT_COLOR                 (*current_MMI_theme->title_text_color)
#define PHOEDT_TITLE_TEXT_BORDER_COLOR          (*current_MMI_theme->title_text_border_color)

#define PHOEDT_ICON_CENTER_X_ON_IMG                             \
    (cui_phoedt_convert_offset_x_scrn2img(                      \
         g_phoedt_cui_cntx_p->curr_act.para.icon.location.x +   \
         (g_phoedt_cui_cntx_p->curr_act.para.icon.size >> 1)))

#define PHOEDT_ICON_CENTER_Y_ON_IMG                             \
    (cui_phoedt_convert_offset_y_scrn2img(                      \
         g_phoedt_cui_cntx_p->curr_act.para.icon.location.y +   \
         (g_phoedt_cui_cntx_p->curr_act.para.icon.size >> 1)))

#define PHOEDT_ICON_SIZE_ON_IMG                                 \
    max(min(cui_phoedt_convert_distance_scrn2img(g_phoedt_cui_cntx_p->curr_act.para.icon.size - (PHOEDT_ICON_BORDER_GAP * 2)), \
            g_phoedt_cui_cntx_p->curr_act.para.icon.srv_max),   \
        g_phoedt_cui_cntx_p->curr_act.para.icon.srv_min)

#define PHOEDT_ICON_HIDE_ICON_BORDER()                          \
    g_phoedt_cui_cntx_p->curr_act.para.icon.location.x = -10;   \
    g_phoedt_cui_cntx_p->curr_act.para.icon.location.x = -10;   \
    g_phoedt_cui_cntx_p->curr_act.para.icon.size = 1

#define PHOEDT_CUI_ICON_ID(idx)                                 \
    (IMG_ID_PHOEDT_ICON_START + 1 + idx)

#define PHOEDT_CUI_SMALL_ICON_ID(idx)                           \
    (IMG_ID_PHOEDT_ICON_1_SMALL + idx)

#define PHOEDT_CUI_FRAME_ID(idx)                                \
    (IMG_ID_PHOEDT_FRAME_START + 1 + idx)

#define PHOEDT_ADD_ICON_CURR_MAX_SIZE(srv_limit_max)            \
    min(PHOEDT_ADD_ICON_MAX_SIZE,                               \
        cui_phoedt_convert_distance_img2scrn(srv_limit_max) / PHOEDT_ADD_ICON_ZOOM_STEP * PHOEDT_ADD_ICON_ZOOM_STEP)

#define PHOEDT_ADD_ICON_CURR_MIN_SIZE(srv_limit_min)            \
    max(PHOEDT_ADD_ICON_MIN_SIZE,                               \
        ((cui_phoedt_convert_distance_img2scrn(srv_limit_min) + (PHOEDT_ICON_BORDER_GAP * 2) + PHOEDT_ADD_ICON_ZOOM_STEP) /      \
          PHOEDT_ADD_ICON_ZOOM_STEP * PHOEDT_ADD_ICON_ZOOM_STEP))

/*****************************************************************************
* Global Variable
*****************************************************************************/
extern BOOL         r2lMMIFlag;
extern MMI_theme    *current_MMI_theme;

/*****************************************************************************
* Local Vairable
*****************************************************************************/
static phoedt_cui_cntx_struct       *g_phoedt_cui_cntx_p;
static phoedt_cui_run_para_struct   *g_phoedt_cui_run_para_p;   /* used to keep run para during asm prompt screen */


#ifdef __MMI_PHOEDT_STYLE_FTE__
#if defined(__MMI_MAINLCD_240X320__)
static const phoedt_layout_struct g_phoedt_layout =
{
    {240, 47},                          /* adjust_bg_size */
    {0, 236},                           /* adjust_first_bg */
    {23, 23},                           /* adjust_icon_size */
    {14, 249},                          /* adjust_first_icon */
    {200, 32},                          /* adjust_bar_size */
    {36, 244},                          /* adjust_first_bar */
    10,                                 /* adjust_bar_margin */
    {23, 23},                           /* adjust_slider_size */
    5,                                  /* adjust_slider_off_y_on_bar */
    24,                                 /* adjust_icon_interval */

#ifdef __MMI_PHOEDT_DOODLE__
    {30, 20},                           /* doodle_up_down_size */
    {30, 20},                           /* doodle_button_size */
    {13, 14},                           /* doodle_color_rect_size */
    {50, 264},                          /* doodle_bg_expand_size */
    {50, 84},                           /* doodle_bg_collapse_size */
    {0, 15},                            /* doodle_bg */
    {10, 24},                           /* doodle_up_down */
    {10, 49},                           /* doodle_line_title */
    {{10, 74}, {10, 99}, {10, 124}},    /* doodle_line */
    {10, 149},                          /* doodle_color */
    {19, 152},                          /* doodle_color_rect */
    {10, 174},                          /* doodle_eraser_title_long */
    {10, 74},                           /* doodle_eraser_title_short */
    {{10, 199}, {10, 224}, {10, 249}},  /* doodle_eraser */
#endif /* __MMI_PHOEDT_DOODLE__ */

#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    {23, 23},                           /* clip_indicator_size */
    {23, 23},                           /* clip_indicator_sel_size */
#endif

    {39, 38},                           /* arrow_size */
    {15, 25},                           /* left_arrow */
    {186, 25},                          /* right_arrow */

    {39, 38},                           /* button_size */
    {80, 247},                          /* button_21 */
    {120, 247},                         /* button_22 */
    {61, 247},                          /* button_31 */
    {100, 247},                         /* button_32 */
    {139, 247}                          /* button_33 */
};
#elif defined(__MMI_MAINLCD_240X400__)
static const phoedt_layout_struct g_phoedt_layout =
{
    {240, 47},                          /* adjust_bg_size */
    {0, 316},                           /* adjust_first_bg */
    {23, 23},                           /* adjust_icon_size */
    {14, 329},                          /* adjust_first_icon */
    {200, 32},                          /* adjust_bar_size */
    {36, 324},                          /* adjust_first_bar */
    10,                                 /* adjust_bar_margin */
    {23, 23},                           /* adjust_slider_size */
    5,                                  /* adjust_slider_off_y_on_bar */
    24,                                 /* adjust_icon_interval */

#ifdef __MMI_PHOEDT_DOODLE__
    {30, 20},                           /* doodle_up_down_size */
    {30, 20},                           /* doodle_button_size */
    {13, 14},                           /* doodle_color_rect_size */
    {50, 264},                          /* doodle_bg_expand_size */
    {50, 84},                           /* doodle_bg_collapse_size */
    {0, 55},                            /* doodle_bg */
    {10, 64},                           /* doodle_up_down */
    {10, 89},                           /* doodle_line_title */
    {{10, 114}, {10, 139}, {10, 164}},  /* doodle_line */
    {10, 189},                          /* doodle_color */
    {19, 192},                          /* doodle_color_rect */
    {10, 214},                          /* doodle_eraser_title_long */
    {10, 114},                          /* doodle_eraser_title_short */
    {{10, 239}, {10, 264}, {10, 289}},  /* doodle_eraser */
#endif /* __MMI_PHOEDT_DOODLE__ */

#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    {23, 23},                           /* clip_indicator_size */
    {23, 23},                           /* clip_indicator_sel_size */
#endif

    {39, 38},                           /* arrow_size */
    {15, 25},                           /* left_arrow */
    {186, 25},                          /* right_arrow */

    {39, 38},                           /* button_size */
    {80, 313},                          /* button_21 */
    {120, 313},                         /* button_22 */
    {61, 313},                          /* button_31 */
    {100, 313},                         /* button_32 */
    {139, 313}                          /* button_33 */
};
#elif defined(__MMI_MAINLCD_320X480__)
static const phoedt_layout_struct g_phoedt_layout =
{
    {320, 61},                          /* adjust_bg_size */
    {0, 368},                           /* adjust_first_bg */
    {30, 30},                           /* adjust_icon_size */
    {20, 384},                          /* adjust_first_icon */
    {252, 32},                          /* adjust_bar_size */
    {58, 381},                          /* adjust_first_bar */
    10,                                 /* adjust_bar_margin */
    {24, 24},                           /* adjust_slider_size */
    1,                                  /* adjust_slider_off_y_on_bar */
    31,                                 /* adjust_icon_interval */

#ifdef __MMI_PHOEDT_DOODLE__
    {51, 40},                           /* doodle_up_down_size */
    {51, 40},                           /* doodle_button_size */
    {22, 22},                           /* doodle_color_rect_size */
    {64, 408},                          /* doodle_bg_expand_size */
    {64, 128},                          /* doodle_bg_collapse_size */
    {0, 22},                            /* doodle_bg */
    {7, 25},                            /* doodle_up_down */
    {7, 65},                            /* doodle_line_title */
    {{7, 105}, {7, 145}, {7, 185}},     /* doodle_line */
    {7, 225},                           /* doodle_color */
    {22, 234},                          /* doodle_color_rect */
    {7, 265},                           /* doodle_eraser_title_long */
    {7, 105},                           /* doodle_eraser_title_short */
    {{7, 305}, {7, 345}, {7, 385}},     /* doodle_eraser */
#endif /* __MMI_PHOEDT_DOODLE__ */

#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    {30, 30},                           /* clip_indicator_size */
    {30, 30},                           /* clip_indicator_sel_size */
#endif

    {43, 43},                           /* arrow_size */
    {48, 46},                           /* left_arrow */
    {225, 46},                          /* right_arrow */

    {43, 43},                           /* button_size */
    {111, 383},                         /* button_21 */
    {166, 383},                         /* button_22 */
    {83, 383},                          /* button_31 */
    {138, 383},                         /* button_32 */
    {193, 383}                          /* button_33 */
};
#elif defined(__MMI_MAINLCD_320X240__)
static const phoedt_layout_struct g_phoedt_layout =
{
    {320, 38},                          /* adjust_bg_size */
    {0, 163},                           /* adjust_first_bg */
    {23, 23},                           /* adjust_icon_size */
    {43, 171},                          /* adjust_first_icon */
    {200, 32},                          /* adjust_bar_size */
    {66, 166},                          /* adjust_first_bar */
    10,                                 /* adjust_bar_margin */
    {23, 23},                           /* adjust_slider_size */
    5,                                  /* adjust_slider_off_y_on_bar */
    15,                                 /* adjust_icon_interval */

#ifdef __MMI_PHOEDT_DOODLE__
    {20, 30},                           /* doodle_up_down_size */
    {20, 30},                           /* doodle_button_size */
    {13, 14},                           /* doodle_color_rect_size */
    {264, 50},                          /* doodle_bg_expand_size */
    {84, 50},                           /* doodle_bg_collapse_size */
    {28, 150},                          /* doodle_bg */
    {38, 160},                          /* doodle_up_down */
    {63, 160},                          /* doodle_line_title */
    {{88, 160}, {113, 160}, {138, 160}},/* doodle_line */
    {163, 160},                         /* doodle_color */
    {167, 168},                         /* doodle_color_rect */
    {188, 160},                         /* doodle_eraser_title_long */
    {88, 160},                          /* doodle_eraser_title_short */
    {{213, 160}, {238, 160}, {263, 160}},   /* doodle_eraser */
#endif /* __MMI_PHOEDT_DOODLE__ */

#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    {23, 23},                           /* clip_indicator_size */
    {23, 23},                           /* clip_indicator_sel_size */
#endif

    {39, 38},                           /* arrow_size */
    {55, 25},                           /* left_arrow */
    {226, 25},                          /* right_arrow */

    {39, 38},                           /* button_size */
    {120, 167},                         /* button_21 */
    {160, 167},                         /* button_22 */
    {100, 167},                         /* button_31 */
    {140, 167},                         /* button_32 */
    {180, 167}                          /* button_33 */
};
#else
#error "[photo editor][photo artist]Please add new layout configuration according to new LCD resolution"
#endif

#else /* __MMI_PHOEDT_STYLE_FTE__ */
#if defined(__MMI_MAINLCD_176X220__)
static const phoedt_layout_struct g_phoedt_layout =
{
    {17, 17},                                               /* adjust_icon_size */
    {5, MMI_TITLE_HEIGHT},                                  /* adjust_first_icon */
    {135, 9},                                               /* adjust_bar_size */
    {5 + (17 + 5), MMI_TITLE_HEIGHT + ((17 - 9) >> 1)},     /* adjust_first_bar */
    8,                                                      /* adjust_bar_margin */
    {15, 15},                                               /* adjust_slider_size */
    (9 - 15) >> 1,                                          /* adjust_slider_off_y_on_bar */
    5,                                                      /* adjust_icon_interval */

#ifdef __MMI_PHOEDT_DOODLE__
    {20, 20},       /* doodle_button_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (20 + 5) * 0},        /* doodle_hide */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (20 + 5) * 1},        /* doodle_type */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (20 + 5) * 2},        /* doodle_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (20 + 5) * 3},        /* doodle_color */
#endif /* __MMI_PHOEDT_DOODLE__ */

    {20, 20},       /* arrow_size */
    {(UI_DEVICE_WIDTH >> 1) - 50 - 20, MMI_TITLE_HEIGHT},       /* left_arrow */
    {(UI_DEVICE_WIDTH >> 1) + 50, MMI_TITLE_HEIGHT},            /* right_arrow */
    {20, 20},       /* button_size */
    {((UI_DEVICE_WIDTH - 20 * 2 - 3 * 1) >> 1) + (20 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_21 */
    {((UI_DEVICE_WIDTH - 20 * 2 - 3 * 1) >> 1) + (20 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_22 */
    {((UI_DEVICE_WIDTH - 20 * 3 - 3 * 2) >> 1) + (20 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_32 */
    {((UI_DEVICE_WIDTH - 20 * 3 - 3 * 2) >> 1) + (20 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_32 */
    {((UI_DEVICE_WIDTH - 20 * 3 - 3 * 2) >> 1) + (20 + 3) * 2, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_32 */
};
#elif defined(__MMI_MAINLCD_240X320__)
static const phoedt_layout_struct g_phoedt_layout =
{
    {26, 26},                                               /* adjust_icon_size */
    {5, MMI_TITLE_HEIGHT},                                  /* adjust_first_icon */
    {195, 21},                                              /* adjust_bar_size */
    {5 + (26 + 5), MMI_TITLE_HEIGHT + ((26 - 21) >> 1)},    /* adjust_first_bar */
    10,                                                     /* adjust_bar_margin */
    {13, 17},                                               /* adjust_slider_size */
    (21 - 17) >> 1,                                         /* adjust_slider_off_y_on_bar */
    5,                                                      /* adjust_icon_interval */

#ifdef __MMI_PHOEDT_DOODLE__
    {30, 30},       /* doodle_button_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 0},        /* doodle_hide */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 1},        /* doodle_type */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 2},        /* doodle_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 3},        /* doodle_color */
#endif /* __MMI_PHOEDT_DOODLE__ */

    {20, 20},       /* arrow_size */
    {(UI_DEVICE_WIDTH >> 1) - 70 - 20, MMI_TITLE_HEIGHT},       /* left_arrow */
    {(UI_DEVICE_WIDTH >> 1) + 70, MMI_TITLE_HEIGHT},            /* right_arrow */
    {20, 20},       /* button_size */
    {((UI_DEVICE_WIDTH - 20 * 2 - 3 * 1) >> 1) + (20 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_21 */
    {((UI_DEVICE_WIDTH - 20 * 2 - 3 * 1) >> 1) + (20 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_22 */
    {((UI_DEVICE_WIDTH - 20 * 3 - 3 * 2) >> 1) + (20 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_32 */
    {((UI_DEVICE_WIDTH - 20 * 3 - 3 * 2) >> 1) + (20 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_32 */
    {((UI_DEVICE_WIDTH - 20 * 3 - 3 * 2) >> 1) + (20 + 3) * 2, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_32 */
};
#elif defined(__MMI_MAINLCD_320X240__)
static const phoedt_layout_struct g_phoedt_layout =
{
    {26, 26},                                               /* adjust_icon_size */
    {5, MMI_TITLE_HEIGHT},                                  /* adjust_first_icon */
    {244, 22},                                              /* adjust_bar_size */
    {5 + (26 + 5), MMI_TITLE_HEIGHT + ((26 - 22) >> 1)},    /* adjust_first_bar */
    10,                                                     /* adjust_bar_margin */
    {13, 17},                                               /* adjust_slider_size */
    (22 - 17) >> 1,                                         /* adjust_slider_off_y_on_bar */
    5,                                                      /* adjust_icon_interval */

#ifdef __MMI_PHOEDT_DOODLE__
    {30, 30},       /* doodle_button_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 0},        /* doodle_hide */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 1},        /* doodle_type */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 2},        /* doodle_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 3},        /* doodle_color */
#endif /* __MMI_PHOEDT_DOODLE__ */

    {20, 20},       /* arrow_size */
    {(UI_DEVICE_WIDTH >> 1) - 70 - 20, MMI_TITLE_HEIGHT},       /* left_arrow */
    {(UI_DEVICE_WIDTH >> 1) + 70, MMI_TITLE_HEIGHT},            /* right_arrow */
    {20, 20},       /* button_size */
    {((UI_DEVICE_WIDTH - 20 * 2 - 3 * 1) >> 1) + (20 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_21 */
    {((UI_DEVICE_WIDTH - 20 * 2 - 3 * 1) >> 1) + (20 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_22 */
    {((UI_DEVICE_WIDTH - 20 * 3 - 3 * 2) >> 1) + (20 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_32 */
    {((UI_DEVICE_WIDTH - 20 * 3 - 3 * 2) >> 1) + (20 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_32 */
    {((UI_DEVICE_WIDTH - 20 * 3 - 3 * 2) >> 1) + (20 + 3) * 2, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 20},     /* button_32 */
};
#elif defined(__MMI_MAINLCD_240X400__)
static const phoedt_layout_struct g_phoedt_layout =
{
    {26, 26},                                               /* adjust_icon_size */
    {5, MMI_TITLE_HEIGHT},                                  /* adjust_first_icon */
    {195, 21},                                              /* adjust_bar_size */
    {5 + (26 + 5), MMI_TITLE_HEIGHT + ((26 - 21) >> 1)},    /* adjust_first_bar */
    10,                                                     /* adjust_bar_margin */
    {13, 13},                                               /* adjust_slider_size */
    (21 - 13) >> 1,                                         /* adjust_slider_off_y_on_bar */
    5,                                                      /* adjust_icon_interval */

#ifdef __MMI_PHOEDT_DOODLE__
    {30, 30},       /* doodle_button_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 0},        /* doodle_hide */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 1},        /* doodle_type */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 2},        /* doodle_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 3},        /* doodle_color */
#endif /* __MMI_PHOEDT_DOODLE__ */

    {29, 26},       /* arrow_size */
    {(UI_DEVICE_WIDTH >> 1) - 70 - 29, MMI_TITLE_HEIGHT},       /* left_arrow */
    {(UI_DEVICE_WIDTH >> 1) + 70, MMI_TITLE_HEIGHT},            /* right_arrow */
    {39, 38},       /* button_size */
    {((UI_DEVICE_WIDTH - 39 * 2 - 3 * 1) >> 1) + (39 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 38},     /* button_21 */
    {((UI_DEVICE_WIDTH - 39 * 2 - 3 * 1) >> 1) + (39 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 38},     /* button_22 */
    {((UI_DEVICE_WIDTH - 39 * 3 - 3 * 2) >> 1) + (39 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 38},     /* button_32 */
    {((UI_DEVICE_WIDTH - 39 * 3 - 3 * 2) >> 1) + (39 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 38},     /* button_32 */
    {((UI_DEVICE_WIDTH - 39 * 3 - 3 * 2) >> 1) + (39 + 3) * 2, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 38},     /* button_32 */
};
#elif defined(__MMI_MAINLCD_320X480__)
static const phoedt_layout_struct g_phoedt_layout =
{
    {26, 26},                                               /* adjust_icon_size */
    {5, MMI_TITLE_HEIGHT},                                  /* adjust_first_icon */
    {244, 22},                                              /* adjust_bar_size */
    {5 + (26 + 5), MMI_TITLE_HEIGHT + ((26 - 22) >> 1)},    /* adjust_first_bar */
    10,                                                     /* adjust_bar_margin */
    {16, 16},                                               /* adjust_slider_size */
    (22 - 16) >> 1,                                         /* adjust_slider_off_y_on_bar */
    5,                                                      /* adjust_icon_interval */

#ifdef __MMI_PHOEDT_DOODLE__
    {30, 30},       /* doodle_button_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 0},        /* doodle_hide */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 1},        /* doodle_type */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 2},        /* doodle_size */
    {3, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (30 + 5) * 3},        /* doodle_color */
#endif /* __MMI_PHOEDT_DOODLE__ */

    {37, 32},       /* arrow_size */
    {(UI_DEVICE_WIDTH >> 1) - 70 - 37, MMI_TITLE_HEIGHT},       /* left_arrow */
    {(UI_DEVICE_WIDTH >> 1) + 70, MMI_TITLE_HEIGHT},            /* right_arrow */
    {37, 37},       /* button_size */
    {((UI_DEVICE_WIDTH - 37 * 2 - 3 * 1) >> 1) + (37 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 37},     /* button_21 */
    {((UI_DEVICE_WIDTH - 37 * 2 - 3 * 1) >> 1) + (37 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 37},     /* button_22 */
    {((UI_DEVICE_WIDTH - 37 * 3 - 3 * 2) >> 1) + (37 + 3) * 0, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 37},     /* button_32 */
    {((UI_DEVICE_WIDTH - 37 * 3 - 3 * 2) >> 1) + (37 + 3) * 1, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 37},     /* button_32 */
    {((UI_DEVICE_WIDTH - 37 * 3 - 3 * 2) >> 1) + (37 + 3) * 2, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3 - 37},     /* button_32 */
};
#else
#error "[photo editor][photo artist]Please add new layout configuration according to new LCD resolution"
#endif
#endif /* __MMI_PHOEDT_STYLE_FTE__ */


#ifdef __MMI_PHOEDT_DOODLE__
#ifdef __MMI_ALPHA_LAYER_SUPPORT__
static const color g_phoedt_doodle_line_color_list[PHOEDT_TEXT_COLOR_COUNT] =
{
    {0, 200, 255, 255},
    {61, 102, 206, 255},
    {115, 241, 252, 255},
    {145, 61, 206, 255},
    {203, 161, 205, 255},
    {255, 53, 240, 255},
    {244, 154, 193, 255},
    {254, 132, 0, 255},
    {255, 240, 0, 255},
    {254, 0, 24, 255},
    {249, 173, 129, 255},
    {89, 189, 69, 255},
    {201, 231, 197, 255},
    {0, 114, 54, 255},
    {196, 223, 155, 255},
    {96, 57, 19, 255},
    {200, 159, 113, 255},
    {27, 20, 100, 255},
    {255, 255, 255, 255},
    {200, 200, 200, 255},
    {150, 150, 150, 255},
    {100, 100, 100, 255},
    {0, 0, 0, 255}
};
#else /* !defined(__MMI_PHOEDT_USE_FAKE_BASELAYER__) */
static const color g_phoedt_doodle_line_color_list[PHOEDT_TEXT_COLOR_COUNT] =
{
    {0, 200, 255},
    {61, 102, 206},
    {115, 241, 252},
    {145, 61, 206},
    {203, 161, 205},
    {255, 53, 240},
    {244, 154, 193},
    {254, 132, 0},
    {255, 240, 0},
    {254, 0, 24},
    {249, 173, 129},
    {89, 189, 69},
    {201, 231, 197},
    {0, 114, 54},
    {196, 223, 155},
    {96, 57, 19},
    {200, 159, 113},
    {27, 20, 100},
    {255, 255, 255},
    {200, 200, 200},
    {150, 150, 150},
    {100, 100, 100},
    {0, 0, 0}
};
#endif /* !defined(__MMI_PHOEDT_USE_FAKE_BASELAYER__) */


#ifdef __MMI_PHOEDT_STYLE_FTE__
/* line size cannot use 1 pixel cause SCALADO will handle it abnormal, and that SCALADO design */
static const U32 g_phoedt_doodle_size[PHOEDT_DOODLE_SIZE_COUNT] =
{
    7, 5, 3
};
#else
static const U32 g_phoedt_doodle_size[PHOEDT_DOODLE_SIZE_COUNT] =
{
    3, 5, 7
};
#endif /* __MMI_PHOEDT_STYLE_FTE__ */
#endif /* __MMI_PHOEDT_DOODLE__ */


/*****************************************************************************
* internal APIs
*****************************************************************************/
#define PHOEDT_LOGIC_MANAGER
static MMI_BOOL cui_phoedt_mem_malloc_memory(phoedt_cui_run_para_struct *run_para);
static void cui_phoedt_mem_prompt_cancel_cb(mmi_frm_appmem_evt_struct *evt);
static void cui_phoedt_mem_prompt_success_cb(void);
static void cui_phoedt_mem_free_memory(void);
static void cui_phoedt_release_resource(void);
static void cui_phoedt_run_int(
    MMI_ID cui_gid, p_cui_phoedt_run_struct p_args,
    PU8 memory, U32 memory_size, MMI_BOOL is_send_available);
static void cui_phoedt_enter_pre_popup_group(void);
static void cui_phoedt_enter_before_edit_group(void);
static void cui_phoedt_enter_edit_group(void);
static void cui_phoedt_close_edit_group(void);
static void cui_phoedt_enter_after_edit_group(void);
static MMI_BOOL cui_phoedt_check_enter_format(phoedt_cui_run_para_struct para);
static void cui_phoedt_exit_curr_phoart(void);
static void cui_phoedt_reset_curr_change_para(void);
static MMI_BOOL cui_phoedt_check_if_reach_limitation(phoedt_limit_type_enum limit_type);
static void cui_phoedt_process_main_menu_items(MMI_ID owner_id);
static void cui_phoedt_set_changed_count(phoedt_change_type_enum change);
#ifdef __MMI_TOUCH_SCREEN__
static MMI_BOOL cui_phoedt_is_touch_item_pressed(phoedt_touch_item_enum item);
#endif /* __MMI_TOUCH_SCREEN__ */
static MMI_BOOL cui_phoedt_is_key_pressed(mmi_keypads_enum key_code);
static MMI_BOOL cui_phoedt_if_drop_key_event(void);
static void cui_phoedt_reset_interact_item_state(void);
static void cui_phoedt_init_image_display_info(void);
static void cui_phoedt_reset_image_display_info(void);
static void cui_phoedt_update_image_curr_size(void);
static phoedt_rect_struct cui_phoedt_get_adjust_static_obj_rect(phoedt_adjust_static_obj_type_enum obj, U16 idx);
#ifdef __MMI_TOUCH_SCREEN__
static phoedt_touch_item_enum cui_phoedt_get_pen_on_obj(mmi_pen_point_struct pos);
static MMI_BOOL cui_phoedt_main_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
static MMI_BOOL cui_phoedt_clip_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
static MMI_BOOL cui_phoedt_effect_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
static MMI_BOOL cui_phoedt_adjust_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
static MMI_BOOL cui_phoedt_icon_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
static MMI_BOOL cui_phoedt_frame_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
static MMI_BOOL cui_phoedt_flip_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
static MMI_BOOL cui_phoedt_rotate_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
#ifdef __MMI_PHOEDT_DOODLE__
static MMI_BOOL cui_phoedt_doodle_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
#endif /* __MMI_PHOEDT_DOODLE__ */
#endif /* __MMI_TOUCH_SCREEN__ */
static MMI_BOOL cui_phoedt_move_rect_in_an_area_by_info(
    const phoedt_rect_struct        available_rect,
    phoedt_rect_struct              *move_rect,
    const phoedt_move_info_struct   move_info);
static void cui_phoedt_move_rect_in_an_area_by_points(
    const phoedt_rect_struct        available_rect,
    phoedt_rect_struct              *move_rect,
    const phoedt_pos_struct         start,
    const phoedt_pos_struct         end);
static MMI_BOOL cui_phoedt_change_clip_rect_in_an_area_by_info(
    const phoedt_clip_rect_adjust_edge_enum     edge,
    const phoedt_rect_struct                    available_rect,
    phoedt_rect_struct                          *clip_rect,
    const phoedt_move_info_struct               move_info);
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
static void cui_phoedt_adjust_fix_ratio_clip_rect_in_an_area(
    const phoedt_touch_item_enum    obj,
    const phoedt_rect_struct        available_rect,
    phoedt_rect_struct              *move_rect,
    const phoedt_size_struct        w_h_ratio);
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
static void cui_phoedt_change_clip_rect_in_an_area_by_points(
    const phoedt_touch_item_enum    obj,
    const phoedt_rect_struct        available_rect,
    phoedt_rect_struct              *move_rect,
    const phoedt_pos_struct         start,
    const phoedt_pos_struct         end);
#endif /* __MMI_TOUCH_SCREEN__ */
static mmi_ret cui_phoedt_proc(mmi_event_struct *evt);
static mmi_ret cui_phoedt_confirm_proc(mmi_event_struct *evt);
static mmi_ret cui_phoedt_filename_editor_proc(mmi_event_struct *evt);
static mmi_ret cui_phoedt_folder_selector_proc(mmi_event_struct *evt);
static mmi_ret cui_phoedt_menu_proc(mmi_event_struct *evt);
static mmi_ret cui_phoedt_menu_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_select_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_clip_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_save_as_other_size_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_main_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_send_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_frame_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_help_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_effect_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_adjust_entry_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_clip_select_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_save_as_other_size_select_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_main_select_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_send_select_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_frame_select_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_effect_select_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_adjust_select_proc(cui_menu_event_struct *evt_menu);
static mmi_ret cui_phoedt_menu_help_select_proc(cui_menu_event_struct *evt_menu);
static void cui_phoedt_save(void);
static void cui_phoedt_save_file(void);
static void cui_phoedt_save_job_done_callback(srv_ies_result result, void *userData);
static void cui_phoedt_update_saving_progress(void);
static void cui_phoedt_save_callback(phoedt_save_result_enum result);
static void cui_phoedt_save_background_callback(phoedt_save_result_enum result);
static void cui_phoedt_undo_confirm(void);
static void cui_phoedt_undo_last_change(void);
static void cui_phoedt_set_key_proc(MMI_ID group, MMI_ID screen);
static mmi_ret cui_phoedt_key_proc(mmi_event_struct *evt);
static void cui_phoedt_main_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
static void cui_phoedt_clip_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
static void cui_phoedt_effect_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
static void cui_phoedt_adjust_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
static void cui_phoedt_icon_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
static void cui_phoedt_frame_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
static void cui_phoedt_flip_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
static void cui_phoedt_rotate_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
#ifdef __MMI_PHOEDT_DOODLE__
static void cui_phoedt_doodle_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
#endif /* __MMI_PHOEDT_DOODLE__ */
static void cui_phoedt_set_pen_hdlrs(void);
#ifdef __MMI_TOUCH_SCREEN__
static void cui_phoedt_pen_down_hdlr(mmi_pen_point_struct pos);
static void cui_phoedt_pen_up_hdlr(mmi_pen_point_struct pos);
static void cui_phoedt_pen_move_hdlr(mmi_pen_point_struct pos);
static void cui_phoedt_pen_abort_hdlr(mmi_pen_point_struct pos);
static void cui_phoedt_main_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
static void cui_phoedt_clip_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
static void cui_phoedt_effect_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
static void cui_phoedt_adjust_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
static void cui_phoedt_icon_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
static void cui_phoedt_frame_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
static void cui_phoedt_flip_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
static void cui_phoedt_rotate_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
#ifdef __MMI_PHOEDT_DOODLE__
static void cui_phoedt_doodle_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
#endif /* __MMI_PHOEDT_DOODLE__ */
#endif /* __MMI_TOUCH_SCREEN__*/
static void cui_phoedt_clip_move_rect(phoedt_move_direction_enum move_direction);
static void cui_phoedt_clip_move_cyclic(void);
#if !defined(__MMI_PHOEDT_STYLE_FTE_CLIP__)
static void cui_phoedt_clip_rect_zoom_in(void);
static void cui_phoedt_clip_rect_zoom_out(void);
static void cui_phoedt_clip_switch_state(void);
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
static void cui_phoedt_adjust_change_value_left(void);
static void cui_phoedt_adjust_change_value_right(void);
static void cui_phoedt_adjust_set_value_by_pos(phoedt_pos_struct pos);
static void cui_phoedt_adjust_select_item(U16 idx);
static void cui_phoedt_adjust_switch_item(phoedt_switch_direction_enum switch_direction);
static void cui_phoedt_effect_switch(phoedt_switch_direction_enum switch_direction);
static void cui_phoedt_frame_switch(phoedt_switch_direction_enum switch_direction);
static void cui_phoedt_icon_move_icon(phoedt_move_direction_enum move_direction);
static void cui_phoedt_icon_move_cyclic(void);
static void cui_phoedt_icon_zoom_in(void);
static void cui_phoedt_icon_zoom_out(void);
static void cui_phoedt_icon_adjust_after_zoom(void);
static void cui_phoedt_icon_rotate(void);
static void cui_phoedt_flip(phoedt_flip_direction_enum flip_direction);
static void cui_phoedt_rotate(phoedt_rotate_direction_enum rotate_direction);
#ifdef __MMI_PHOEDT_DOODLE__
static void cui_phoedt_doodle_switch_hide(void);
#ifdef __MMI_PHOEDT_STYLE_FTE__
static void cui_phoedt_doodle_switch_line_size(phoedt_doodle_size_enum size);
static void cui_phoedt_doodle_switch_eraser_size(phoedt_doodle_size_enum size);
#else /* __MMI_PHOEDT_STYLE_FTE__ */
static void cui_phoedt_doodle_switch_type(void);
static void cui_phoedt_doodle_switch_size(void);
#endif /* __MMI_PHOEDT_STYLE_FTE__ */
#endif /* __MMI_PHOEDT_DOODLE__ */
#ifdef __MMI_TOUCH_SCREEN__
static void cui_phoedt_config_pen_config_sampling_period(void);
static void cui_phoedt_restore_pen_config_sampling_period(void);
#endif /* __MMI_TOUCH_SCREEN__ */
static void cui_phoedt_cancel_ies_job(srv_ies_job_handle *job);
static MMI_BOOL cui_phoedt_start_curr_change(void);
static void cui_phoedt_end_curr_change(MMI_BOOL is_apply);
static void cui_phoedt_apply_curr_change(void);
static void cui_phoedt_cancel_curr_change(void);
static void cui_phoedt_give_up_curr_change(void);
static MMI_BOOL cui_phoedt_start_clip(void);
static void cui_phoedt_apply_clip(void);
static void cui_phoedt_cancel_clip(void);
static MMI_BOOL cui_phoedt_start_adjust(void);
static void cui_phoedt_apply_adjust(void);
static void cui_phoedt_cancel_adjust(void);
static MMI_BOOL cui_phoedt_start_effect(void);
static void cui_phoedt_apply_effect(void);
static void cui_phoedt_cancel_effect(void);
static MMI_BOOL cui_phoedt_start_icon(void);
static void cui_phoedt_apply_icon(void);
static void cui_phoedt_cancel_icon(void);
static MMI_BOOL cui_phoedt_start_frame(void);
static void cui_phoedt_apply_frame(void);
static void cui_phoedt_cancel_frame(void);
static MMI_BOOL cui_phoedt_start_flip(void);
static void cui_phoedt_apply_flip(void);
static void cui_phoedt_cancel_flip(void);
static MMI_BOOL cui_phoedt_start_rotate(void);
static void cui_phoedt_apply_rotate(void);
static void cui_phoedt_cancel_rotate(void);
#ifdef __MMI_PHOEDT_DOODLE__
static MMI_BOOL cui_phoedt_start_doodle(void);
static void cui_phoedt_apply_doodle(void);
static void cui_phoedt_cancel_doodle(void);
#endif /* __MMI_PHOEDT_DOODLE__ */


#define PHOEDT_UI_MANAGER
static void cui_phoedt_entry_main_screen(void);
static void cui_phoedt_exit_main_screen(void);
static void cui_phoedt_entry_main_option_screen(void);
static void cui_phoedt_entry_send_list_screen(void);
static void cui_phoedt_entry_frame_list_screen(void);
static void cui_phoedt_entry_effect_list_screen(void);
static void cui_phoedt_entry_adjust_list_screen(void);
static void cui_phoedt_entry_clip_list_screen(void);
static void cui_phoedt_entry_help_list_screen(void);
static void cui_phoedt_entry_folder_selector_screen(void);
static void cui_phoedt_entry_filename_editor_screen(void);
static void cui_phoedt_entry_filename_editor_internal(void);
static void cui_phoedt_entry_saving_screen(MMI_ID parent_gid);
static void cui_phoedt_entry_saving_screen_internal(mmi_scrn_essential_struct* scrn_data);
static void cui_phoedt_cancel_save_job(void);
static mmi_ret cui_phoedt_saving_end_key_proc(mmi_event_struct *evt);
static void cui_phoedt_exit_saving_screen(void);
static void cui_phoedt_entry_matrix_selector_screen(void);
static void cui_phoedt_exit(void);
static void cui_phoedt_matrix_selector_highlight_hdlr(S32 idx);
static void cui_phoedt_matrix_selector_draw_image_callback(
                S32         idx,
                S32         page_start_idx,
                S32         page_end_idx,
                MMI_BOOL    is_hilighted,
                MMI_BOOL    is_need_update,
                MMI_BOOL    is_new_page,
                S32         x1,
                S32         y1,
                S32         x2,
                S32         y2);
static void cui_phoedt_matrix_selector_select_hdlr(void);
static void cui_phoedt_matrix_selector_cancel_hdlr(void);
static void cui_phoedt_entry_cui_screens(phoedt_cui_run_para_struct *run_para);
static void cui_phoedt_entry_edit_screen(void);
static void cui_phoedt_entry_help_screen(void);
static void cui_phoedt_exit_edit_screen(void);
static void cui_phoedt_stop_move_element_timers(void);
static void cui_phoedt_create_preview_layer(void);
static void cui_phoedt_free_preview_layer(void);
static void cui_phoedt_create_osd_layer(void);
static void cui_phoedt_free_osd_layer(void);
static void cui_phoedt_draw_osd(void);
static void cui_phoedt_draw_main_osd(void);
static void cui_phoedt_draw_add_icon_osd(void);
static void cui_phoedt_draw_add_effect_osd(void);
static void cui_phoedt_draw_add_frame_osd(void);
static void cui_phoedt_draw_adjust_osd(void);
#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
static void cui_phoedt_init_clip_osd_indicators(void);
static void cui_phoedt_draw_clip_osd_indicators(void);
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
static void cui_phoedt_draw_clip_osd(void);
static void cui_phoedt_draw_flip_osd(void);
static void cui_phoedt_draw_rotate_osd(void);
#ifdef __MMI_PHOEDT_DOODLE__
static void cui_phoedt_draw_doodle_osd(void);
static void cui_phoedt_doodle_draw_doodle(phoedt_pos_struct start, phoedt_pos_struct end);
#endif /* #ifdef __MMI_PHOEDT_DOODLE__ */
static void cui_phoedt_draw_softkey(
                MMI_STR_ID lsk_str,
                MMI_STR_ID rsk_str,
                MMI_BOOL is_clear_bg,
                MMI_IMG_ID csk_img);
static void cui_phoedt_draw_title(
                MMI_STR_ID  title,
                MMI_BOOL    is_bracketed,
                MMI_STR_ID  sub_title,
                MMI_BOOL    is_clear_bg);
static void cui_phoedt_draw_button(S32 x, S32 y, S32 w, S32 h, MMI_IMG_ID btn_img_id, MMI_BOOL is_sel);
static void cui_phoedt_draw_image_border(void);


#define PHOEDT_EFFECTS_MANAGER
static void cui_phoedt_init_ies_capacity(void);
static MMI_BOOL cui_phoedt_handle_ies_err_code(MMI_ID gid, srv_ies_result err_code, U32 line);
static void cui_phoedt_create_ies_resource(void);
static void cui_phoedt_release_ies_resource(void);
static void cui_phoedt_ies_resource_reload_image(void);
static phoedt_adjust_item_struct* cui_phoedt_adjust_find_free_adjust_para_items(S32 count);
static phoedt_adjust_struct* cui_phoedt_get_curr_adjust_item(void);
static phoedt_effect_struct* cui_phoedt_get_curr_effect_item(void);
static U32 cui_phoedt_get_pitchBytes(void);
static srv_ies_colorformat_enum cui_phoedt_get_ies_color_format(void);
static MMI_BOOL cui_phoedt_preview_image(MMI_BOOL reset_preview_rect);


#define PHOEDT_UTILITY_USAGE
static MMI_STR_ID cui_phoedt_is_valide_size(const WCHAR *filepath);
static S32 cui_phoedt_convert_distance_scrn2img(S32 len_in);
static S32 cui_phoedt_convert_distance_img2scrn(S32 len_in);
static S32 cui_phoedt_convert_offset_x_scrn2img(S32 x_in);
static S32 cui_phoedt_convert_offset_y_scrn2img(S32 y_in);
static srv_ies_rot_enum cui_phoedt_get_rotate_app2ies(const phoedt_rotate_enum r_in);
static phoedt_move_info_struct* cui_phoedt_get_curr_move_info(void);
static void cui_phoedt_get_adjust_para_icons(
    srv_ies_effect_param_enum   para_id,
    MMI_IMG_ID                  *icon);
static phoedt_path_relationship_enum cui_phoedt_check_path_relationship(
    const WCHAR     *ext_path,
    const MMI_BOOL  ext_is_folder,
    const WCHAR     *int_path);
static void cui_phoedt_rh_exit_cb(void);
static void cui_phoedt_rh_save_cb(void);
static void cui_phoedt_rh_reentry_cb(MMI_BOOL result, phoedt_rh_reentry_para_union *para);


typedef struct
{
    void (*draw_osd) ();
    MMI_BOOL (*start) ();
    void (*apply) ();
    void (*cancel) ();
#ifdef __MMI_TOUCH_SCREEN__
    MMI_BOOL (*get_pen_on_obj) (mmi_pen_point_struct pos, phoedt_touch_item_enum *obj);
    void (*pen_hdlr) (phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos);
#endif
    void (*key_hdlr) (mmi_keypads_enum key_code, mmi_key_types_enum key_evt);
}cui_phoedt_action_hdlrs;
static const cui_phoedt_action_hdlrs g_phoedt_action_hdlrs[] =
{
    /* PHOEDT_ACTION_TYPE_NONE */
    {
        cui_phoedt_draw_main_osd,
        NULL,
        NULL,
        NULL,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_main_get_pen_on_obj,
        cui_phoedt_main_pen_hdlr,
    #endif
        cui_phoedt_main_key_hdlr,
    },

    /* PHOEDT_ACTION_TYPE_LOADING */
    {
        cui_phoedt_draw_main_osd,
        NULL,
        NULL,
        NULL,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_main_get_pen_on_obj,
        cui_phoedt_main_pen_hdlr,
    #endif
        cui_phoedt_main_key_hdlr,
    },

    /* PHOEDT_ACTION_TYPE_FRAME */
    {
        cui_phoedt_draw_add_frame_osd,
        cui_phoedt_start_frame,
        cui_phoedt_apply_frame,
        cui_phoedt_cancel_frame,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_frame_get_pen_on_obj,
        cui_phoedt_frame_pen_hdlr,
    #endif
        cui_phoedt_frame_key_hdlr,
    },
    
    /* PHOEDT_ACTION_TYPE_EFFECT */
    {
        cui_phoedt_draw_add_effect_osd,
        cui_phoedt_start_effect,
        cui_phoedt_apply_effect,
        cui_phoedt_cancel_effect,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_effect_get_pen_on_obj,
        cui_phoedt_effect_pen_hdlr,
    #endif
        cui_phoedt_effect_key_hdlr,
    },
    
    /* PHOEDT_ACTION_TYPE_ADJUST */
    {
        cui_phoedt_draw_adjust_osd,
        cui_phoedt_start_adjust,
        cui_phoedt_apply_adjust,
        cui_phoedt_cancel_adjust,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_adjust_get_pen_on_obj,
        cui_phoedt_adjust_pen_hdlr,
    #endif
        cui_phoedt_adjust_key_hdlr,
    },
    
    /* PHOEDT_ACTION_TYPE_ICON */
    {
        cui_phoedt_draw_add_icon_osd,
        cui_phoedt_start_icon,
        cui_phoedt_apply_icon,
        cui_phoedt_cancel_icon,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_icon_get_pen_on_obj,
        cui_phoedt_icon_pen_hdlr,
    #endif
        cui_phoedt_icon_key_hdlr,
    },
    
    /* PHOEDT_ACTION_TYPE_CLIP */
    {
        cui_phoedt_draw_clip_osd,
        cui_phoedt_start_clip,
        cui_phoedt_apply_clip,
        cui_phoedt_cancel_clip,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_clip_get_pen_on_obj,
        cui_phoedt_clip_pen_hdlr,
    #endif
        cui_phoedt_clip_key_hdlr,
    },
    
    /* PHOEDT_ACTION_TYPE_FLIP */
    {
        cui_phoedt_draw_flip_osd,
        cui_phoedt_start_flip,
        cui_phoedt_apply_flip,
        cui_phoedt_cancel_flip,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_flip_get_pen_on_obj,
        cui_phoedt_flip_pen_hdlr,
    #endif
        cui_phoedt_flip_key_hdlr,
    },
    
    /* PHOEDT_ACTION_TYPE_ROTATE */
    {
        cui_phoedt_draw_rotate_osd,
        cui_phoedt_start_rotate,
        cui_phoedt_apply_rotate,
        cui_phoedt_cancel_rotate,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_rotate_get_pen_on_obj,
        cui_phoedt_rotate_pen_hdlr,
    #endif
        cui_phoedt_rotate_key_hdlr,
    }
    
#ifdef __MMI_PHOEDT_DOODLE__
    ,
    /* PHOEDT_ACTION_TYPE_DOODLE */
    {
        cui_phoedt_draw_doodle_osd,
        cui_phoedt_start_doodle,
        cui_phoedt_apply_doodle,
        cui_phoedt_cancel_doodle,
    #ifdef __MMI_TOUCH_SCREEN__
        cui_phoedt_doodle_get_pen_on_obj,
        cui_phoedt_doodle_pen_hdlr,
    #endif
        cui_phoedt_doodle_key_hdlr,
    }
#endif
};


/*****************************************************************************
* FUNCTION
*  cui_phoedt_mem_malloc_memory
* DESCRIPTION
*  get cui used memory
* PARAMETERS
*  None
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_mem_malloc_memory(phoedt_cui_run_para_struct *run_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            is_external_mem = MMI_FALSE;
    PU8                 mem_ptr         = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(PHOEDT_APP_BASED_MEM_SIZE >= PHOEDT_CUI_NEED_SIZE);

    if(NULL == run_para->memory)
    {
        mem_ptr = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_PHOEDT, PHOEDT_CUI_NEED_SIZE);

        if(NULL == mem_ptr)
        {
            g_phoedt_cui_run_para_p = run_para;
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_PHOEDT,
                IMG_ID_PHOEDT_APP_ICON,
                PHOEDT_CUI_NEED_SIZE,
                cui_phoedt_mem_prompt_success_cb);

            mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_PHOEDT, cui_phoedt_mem_prompt_cancel_cb);
        }
    }
    else
    {
        is_external_mem = MMI_TRUE;
        mem_ptr = run_para->memory;
    }

    if(NULL != mem_ptr)
    {
        /* assign memory to different usage */
        g_phoedt_cui_cntx_p = (phoedt_cui_cntx_struct*)mem_ptr;
        kal_mem_set(g_phoedt_cui_cntx_p, 0, PHOEDT_CUI_CNTX_SIZE);

        g_phoedt_cui_cntx_p->preview_buf = mem_ptr + PHOEDT_CUI_CNTX_SIZE;
        g_phoedt_cui_cntx_p->ies_buf = mem_ptr + PHOEDT_CUI_CNTX_SIZE + PHOEDT_FRAME_BUFFER_SIZE;

        g_phoedt_cui_cntx_p->is_external_mem = is_external_mem;
    }

    return mem_ptr == NULL ? MMI_FALSE : MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_mem_prompt_cancel_cb
* DESCRIPTION
*  cui_phoedt_mem_prompt_cancel_cb
* PARAMETERS
*  evt          [IN]
* RETURNS
*  None
*****************************************************************************/
static void cui_phoedt_mem_prompt_cancel_cb(mmi_frm_appmem_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(g_phoedt_cui_run_para_p->self_gid);

    g_phoedt_cui_run_para_p = NULL;

    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_PHOEDT, NULL);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_mem_prompt_success_cb
* DESCRIPTION
*  cui_phoedt_mem_prompt_success_cb
* PARAMETERS
*  evt          [IN]
* RETURNS
*  None
*****************************************************************************/
static void cui_phoedt_mem_prompt_success_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE == cui_phoedt_mem_malloc_memory(g_phoedt_cui_run_para_p))
    {
        MMI_ASSERT(0);
        return;
    }

    cui_phoedt_entry_cui_screens(g_phoedt_cui_run_para_p);

    g_phoedt_cui_run_para_p = NULL;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_mem_free_memory
* DESCRIPTION
*  release cui used memory
* PARAMETERS
*  None
* RETURNS
*  None
*****************************************************************************/
static void cui_phoedt_mem_free_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != g_phoedt_cui_cntx_p)
    {
        if(MMI_FALSE == g_phoedt_cui_cntx_p->is_external_mem)
        {
            if(GRP_ID_INVALID != g_phoedt_cui_cntx_p->cui_gid)
            {
                applib_mem_ap_free(g_phoedt_cui_cntx_p);
                g_phoedt_cui_cntx_p = NULL;
                mmi_phoedt_rh_remove_ins();
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
        else
        {
            g_phoedt_cui_cntx_p = NULL;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_release_resource
* DESCRIPTION
*  release cui used memory, ies resource and layer
* PARAMETERS
*  None
* RETURNS
*  None
*****************************************************************************/
static void cui_phoedt_release_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != g_phoedt_cui_cntx_p && GRP_ID_INVALID != g_phoedt_cui_cntx_p->cui_gid)
    {
        /* preview layer is created by using APP based memory,
        so free it once when exit app */
        cui_phoedt_free_preview_layer();

        cui_phoedt_free_osd_layer();

        cui_phoedt_release_ies_resource();

        cui_phoedt_mem_free_memory();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_enter_pre_popup_group
* DESCRIPTION
*  enter before edit group: contain screens between main option and edit screens
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_enter_pre_popup_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == mmi_frm_group_is_present(GRP_ID_PHOEDT_PRE_POPUP_GROUP) &&
        MMI_TRUE == mmi_frm_group_is_in_active_serial(GRP_ID_PHOEDT_PRE_POPUP_GROUP))
    {
        return;
    }
    mmi_frm_group_close(GRP_ID_PHOEDT_PRE_POPUP_GROUP);

    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_PHOEDT_PRE_POPUP_GROUP,
        NULL,
        NULL);

    mmi_frm_group_enter(
        GRP_ID_PHOEDT_PRE_POPUP_GROUP,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
}



/*****************************************************************************
* FUNCTION
*  mmi_phoedt_enter_before_edit_group
* DESCRIPTION
*  enter before edit group: contain screens between main option and edit screens
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_enter_before_edit_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_group_get_state(GRP_ID_PHOEDT_BEFORE_EDIT_GROUP) == MMI_SCENARIO_STATE_NONE)
    {
        MMI_ASSERT(mmi_frm_group_get_state(GRP_ID_PHOEDT_EDIT_GROUP) != MMI_SCENARIO_STATE_NONE);

        mmi_frm_group_create(
            GRP_ID_PHOEDT_EDIT_GROUP,
            GRP_ID_PHOEDT_BEFORE_EDIT_GROUP,
            cui_phoedt_proc,
            NULL);

        mmi_frm_group_enter(GRP_ID_PHOEDT_BEFORE_EDIT_GROUP, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_phoedt_enter_after_edit_group
* DESCRIPTION
*  enter after edit group: contain screens after edit screens, like doodle color select screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_enter_after_edit_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_group_get_state(GRP_ID_PHOEDT_AFTER_EDIT_GROUP) == MMI_SCENARIO_STATE_NONE)
    {
        MMI_ASSERT(mmi_frm_group_get_state(GRP_ID_PHOEDT_EDIT_GROUP) != MMI_SCENARIO_STATE_NONE);

        mmi_frm_group_create(
            GRP_ID_PHOEDT_EDIT_GROUP,
            GRP_ID_PHOEDT_AFTER_EDIT_GROUP,
            cui_phoedt_proc,
            NULL);

        mmi_frm_group_enter(GRP_ID_PHOEDT_AFTER_EDIT_GROUP, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_check_enter_format
* DESCRIPTION
*  check pre edit and terminate it
* PARAMETERS
*  void
* RETURNS
*  can enter or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_check_enter_format(phoedt_cui_run_para_struct para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID      err_str_id  =   cui_phoedt_is_supported_format_ext(para.filepath_buf);
    MMI_BOOL        ret         =   MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PHOEDT_RES_DUMMY_ID != err_str_id)
    {
        cui_phoedt_enter_pre_popup_group();

        PHOEDT_CUI_DISPLAY_POPUP(GRP_ID_PHOEDT_PRE_POPUP_GROUP, GetString(err_str_id), MMI_EVENT_FAILURE);

        /* this block is for MAUI_02739188, if enter failed, should let parent know and close myself */
        PHOEDT_SEND_TO_PARENT_NO_RESULT_WITH_GID(para.self_gid, EVT_ID_CUI_PHOEDT_RESULT_FAILED);
        PHOEDT_SEND_TO_PARENT_NO_RESULT_WITH_GID(para.self_gid, EVT_ID_CUI_PHOEDT_RESULT_CLOSE_ME);
        /* end of this block */

        ret = MMI_FALSE;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_exit_curr_phoart
* DESCRIPTION
*  cui_phoedt_exit_curr_phoart
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_exit_curr_phoart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != g_phoedt_cui_cntx_p && GRP_ID_INVALID != g_phoedt_cui_cntx_p->cui_gid)
    {
        PHOEDT_SEND_TO_PARENT_NO_RESULT(EVT_ID_CUI_PHOEDT_RESULT_FAILED);

        PHOEDT_SEND_TO_PARENT_NO_RESULT(EVT_ID_CUI_PHOEDT_RESULT_CLOSE_ME);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_reset_curr_change_para
* DESCRIPTION
*  Reset change parameters
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_reset_curr_change_para(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&g_phoedt_cui_cntx_p->curr_act.para, 0, sizeof(phoedt_action_para_union));
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_check_if_reach_limitation
* DESCRIPTION
*
* PARAMETERS
*  limit_type       [IN]
* RETURNS
*  MM_TRUE, reach the limitation; MMI_FALSE, not reach the limitation
*****************************************************************************/
static MMI_BOOL cui_phoedt_check_if_reach_limitation(phoedt_limit_type_enum limit_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL                ret         = MMI_FALSE;
    U32                     idx;
    U32                     cnt         = 0;
    U32                     limit       = g_phoedt_limit_values[limit_type];
    phoedt_action_type_enum limit_act   = PHOEDT_ACTION_TYPE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_phoedt_limit_values[PHOEDT_LIMIT_TYPE_TOTAL] >= g_phoedt_cui_cntx_p->change_cntx.count);

    if(PHOEDT_LIMIT_TYPE_TOTAL == limit_type)
    {
        if(limit == g_phoedt_cui_cntx_p->change_cntx.count)
        {
            ret = MMI_TRUE;
        }
    }
    else
    {
        switch(limit_type)
        {
        case PHOEDT_LIMIT_TYPE_FRAME:
            {
                limit_act = PHOEDT_ACTION_TYPE_FRAME;
            }
            break;

        case PHOEDT_LIMIT_TYPE_ICON:
            {
                limit_act = PHOEDT_ACTION_TYPE_ICON;
            }
            break;

    #ifdef __MMI_PHOEDT_DOODLE__
        case PHOEDT_LIMIT_TYPE_DOODLE:
            {
                limit_act = PHOEDT_ACTION_TYPE_DOODLE;
            }
            break;
    #endif /* __MMI_PHOEDT_DOODLE__ */

    #ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MTK_INTERNAL__ */
        }

        for(idx = 0; idx < g_phoedt_cui_cntx_p->change_cntx.count; idx++)
        {
            if(limit_act == g_phoedt_cui_cntx_p->change_cntx.changes[idx])
            {
                cnt++;
            }
        }

        MMI_ASSERT(cnt <= limit);

        if(cnt == limit)
        {
            ret = MMI_TRUE;
        }
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_process_main_menu_items
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_process_main_menu_items(MMI_ID owner_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == cui_phoedt_check_if_reach_limitation(PHOEDT_LIMIT_TYPE_TOTAL))
    {
        cui_menu_set_item_hidden(
            owner_id,
            MENU_ID_PHOEDT_ADD_EFFECT,
            MMI_TRUE);

        cui_menu_set_item_hidden(
            owner_id,
            MENU_ID_PHOEDT_ADJUST,
            MMI_TRUE);

        cui_menu_set_item_hidden(
            owner_id,
            MENU_ID_PHOEDT_ADD_FRAME,
            MMI_TRUE);

        cui_menu_set_item_hidden(
            owner_id,
            MENU_ID_PHOEDT_ADD_ICON,
            MMI_TRUE);

        cui_menu_set_item_hidden(
            owner_id,
            MENU_ID_PHOEDT_FLIP,
            MMI_TRUE);

        cui_menu_set_item_hidden(
            owner_id,
            MENU_ID_PHOEDT_CLIP,
            MMI_TRUE);

        cui_menu_set_item_hidden(
            owner_id,
            MENU_ID_PHOEDT_ROTATE,
            MMI_TRUE);

    #ifdef __MMI_PHOEDT_DOODLE__
        cui_menu_set_item_hidden(
            owner_id,
            MENU_ID_PHOEDT_DOODLE,
            MMI_TRUE);
    #endif
    }
    else
    {
        if(MMI_TRUE == cui_phoedt_check_if_reach_limitation(PHOEDT_LIMIT_TYPE_FRAME))
        {
            cui_menu_set_item_hidden(
                owner_id,
                MENU_ID_PHOEDT_ADD_FRAME,
                MMI_TRUE);
        }

        if(MMI_TRUE == cui_phoedt_check_if_reach_limitation(PHOEDT_LIMIT_TYPE_ICON))
        {
            cui_menu_set_item_hidden(
                owner_id,
                MENU_ID_PHOEDT_ADD_ICON,
                MMI_TRUE);
        }

    #ifdef __MMI_PHOEDT_DOODLE__
        if(MMI_TRUE == cui_phoedt_check_if_reach_limitation(PHOEDT_LIMIT_TYPE_DOODLE))
        {
            cui_menu_set_item_hidden(
                owner_id,
                MENU_ID_PHOEDT_DOODLE,
                MMI_TRUE);
        }
    #endif /* __MMI_PHOEDT_DOODLE__ */
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_set_changed_count
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_set_changed_count(phoedt_change_type_enum change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(change)
    {
    case PHOEDT_CHANGE_TYPE_CHANGE:
        {
            g_phoedt_cui_cntx_p->change_cntx.changes[g_phoedt_cui_cntx_p->change_cntx.count] =
                g_phoedt_cui_cntx_p->curr_act.action;
            g_phoedt_cui_cntx_p->change_cntx.count++;
            g_phoedt_cui_cntx_p->undo_available = MMI_TRUE;
        }
        break;

    case PHOEDT_CHANGE_TYPE_UNDO:
        {
            MMI_ASSERT(g_phoedt_cui_cntx_p->change_cntx.count > 0);
            g_phoedt_cui_cntx_p->change_cntx.count--;
            g_phoedt_cui_cntx_p->undo_available = MMI_FALSE;
        }
        break;

    case PHOEDT_CHANGE_TYPE_RESET:
        {
            g_phoedt_cui_cntx_p->change_cntx.count = 0;
            g_phoedt_cui_cntx_p->undo_available = MMI_FALSE;
        }
        break;

    default:
        break;
    }

    if(0 == g_phoedt_cui_cntx_p->change_cntx.count)
    {
        mmi_phoedt_rh_set_not_saved(MMI_FALSE);
    }
    else
    {
        mmi_phoedt_rh_set_not_saved(MMI_TRUE);
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_is_touch_item_pressed
* DESCRIPTION
*  check if the specific item is pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL cui_phoedt_is_touch_item_pressed(phoedt_touch_item_enum item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == g_phoedt_cui_cntx_p->touch_cntx.is_pen_down &&
       item == g_phoedt_cui_cntx_p->touch_cntx.obj)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_is_key_pressed
* DESCRIPTION
*  check if the specific key is pressed
* PARAMETERS
*  void
* RETURNS
*  Pressed or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_is_key_pressed(mmi_keypads_enum key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == g_phoedt_cui_cntx_p->key_cntx.is_key_down &&
       key_code == g_phoedt_cui_cntx_p->key_cntx.key_code)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_if_drop_key_event
* DESCRIPTION
*  check if should drop current key event
* PARAMETERS
*  void
* RETURNS
*  should drop the event or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_if_drop_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHOEDT_DOODLE__
    if(PHOEDT_ACTION_TYPE_DOODLE == g_phoedt_cui_cntx_p->curr_act.action &&
       MMI_TRUE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd)
    {
        return MMI_TRUE;
    }
    else
#endif /* #ifdef __MMI_PHOEDT_DOODLE__ */
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_reset_interact_item_state
* DESCRIPTION
*  reset interact item state info
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_reset_interact_item_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == g_phoedt_cui_cntx_p)
    {
        return;
    }
#ifdef __MMI_TOUCH_SCREEN__
    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down     = MMI_FALSE;
    g_phoedt_cui_cntx_p->touch_cntx.obj             = PHOEDT_TOUCH_ITEM_NONE;
#endif /* __MMI_TOUCH_SCREEN__ */

    g_phoedt_cui_cntx_p->key_cntx.is_key_down       = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_init_image_display_info
* DESCRIPTION
*  init image display info according the change of shown_rect
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_init_image_display_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_phoedt_cui_cntx_p->image_info.shown_rect.size.w > UI_device_width ||
       g_phoedt_cui_cntx_p->image_info.shown_rect.size.h > UI_device_height)
    {
        gdi_image_util_fit_bbox(
            UI_device_width, UI_device_height,
            g_phoedt_cui_cntx_p->image_info.shown_rect.size.w,
            g_phoedt_cui_cntx_p->image_info.shown_rect.size.h,
            &g_phoedt_cui_cntx_p->display_info.img_rect.offset.x,
            &g_phoedt_cui_cntx_p->display_info.img_rect.offset.y,
            &g_phoedt_cui_cntx_p->display_info.img_rect.size.w,
            &g_phoedt_cui_cntx_p->display_info.img_rect.size.h);
    }
    else
    {
        g_phoedt_cui_cntx_p->display_info.img_rect.size.w = g_phoedt_cui_cntx_p->image_info.shown_rect.size.w;
        g_phoedt_cui_cntx_p->display_info.img_rect.size.h = g_phoedt_cui_cntx_p->image_info.shown_rect.size.h;
        g_phoedt_cui_cntx_p->display_info.img_rect.offset.x =
            (UI_device_width - g_phoedt_cui_cntx_p->display_info.img_rect.size.w) >> 1;
        g_phoedt_cui_cntx_p->display_info.img_rect.offset.y =
            (UI_device_height - g_phoedt_cui_cntx_p->display_info.img_rect.size.h) >> 1;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_reset_image_display_info
* DESCRIPTION
*  reset image display info to show full image fit screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_reset_image_display_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->image_info.shown_rect.offset.x = 0;
    g_phoedt_cui_cntx_p->image_info.shown_rect.offset.y = 0;
    g_phoedt_cui_cntx_p->image_info.shown_rect.size.w = g_phoedt_cui_cntx_p->image_info.curr_size.w;
    g_phoedt_cui_cntx_p->image_info.shown_rect.size.h = g_phoedt_cui_cntx_p->image_info.curr_size.h;

    cui_phoedt_init_image_display_info();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_update_image_curr_size
* DESCRIPTION
*  update current image size from srv ies
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_update_image_curr_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IMG_CURR_SIZE,
        g_phoedt_cui_cntx_p->image_info.curr_size.w, g_phoedt_cui_cntx_p->image_info.curr_size.h);

    ies_ret = srv_ies_image_get_current_size(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        &g_phoedt_cui_cntx_p->image_info.curr_size.w,
        &g_phoedt_cui_cntx_p->image_info.curr_size.h);
    PHOEDT_TRACE_IES_RESULT(ies_ret);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IMG_CURR_SIZE,
        g_phoedt_cui_cntx_p->image_info.curr_size.w, g_phoedt_cui_cntx_p->image_info.curr_size.h);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_get_adjust_static_obj_rect
* DESCRIPTION
*  get adjust osd static obj rect
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static phoedt_rect_struct cui_phoedt_get_adjust_static_obj_rect(phoedt_adjust_static_obj_type_enum obj, U16 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_rect_struct          ret_rect;
    phoedt_size_struct          icon_size               = g_phoedt_layout.adjust_icon_size;
    U16                         icon_interval           = g_phoedt_layout.adjust_icon_interval;
    phoedt_pos_struct           firstPos                = g_phoedt_layout.adjust_first_icon;
    phoedt_size_struct          eachSize                = g_phoedt_layout.adjust_icon_size;
    phoedt_adjust_struct        *curr_adjust            = cui_phoedt_get_curr_adjust_item();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHOEDT_STYLE_FTE__
    #define ADJUST_DIR (-1)
    item_idx = curr_adjust->para_count - item_idx - 1;
#else
    #define ADJUST_DIR (1)
#endif

    switch(obj)
    {
    case PHOEDT_ADJUST_STATIC_OBJ_TYPE_ICON:
        {
            firstPos = g_phoedt_layout.adjust_first_icon;
            eachSize = g_phoedt_layout.adjust_icon_size;
        }
        break;

    case PHOEDT_ADJUST_STATIC_OBJ_TYPE_BAR:
        {
            firstPos = g_phoedt_layout.adjust_first_bar;
            eachSize = g_phoedt_layout.adjust_bar_size;
        }
        break;

#ifdef __MMI_PHOEDT_STYLE_FTE__
    case PHOEDT_ADJUST_STATIC_OBJ_TYPE_BG:
        {
            firstPos = g_phoedt_layout.adjust_first_bg;
            eachSize = g_phoedt_layout.adjust_bg_size;
        }
        break;
#endif

    default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

    ret_rect.offset.x = firstPos.x;
    ret_rect.offset.y = firstPos.y + ((icon_size.h + icon_interval) * item_idx * ADJUST_DIR);
    ret_rect.size = eachSize;

    return ret_rect;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_get_pen_on_obj
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static phoedt_touch_item_enum cui_phoedt_get_pen_on_obj(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_touch_item_enum      obj             = PHOEDT_TOUCH_ITEM_NONE;
    wgui_component_info_struct  cop;
    MMI_BOOL                    keep_check      = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].get_pen_on_obj)
        keep_check = g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].get_pen_on_obj(pos, &obj);
    else 
        MMI_ASSERT(0);

    if(MMI_TRUE == keep_check)
    {
        cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            obj = PHOEDT_TOUCH_ITEM_LSK;
        }

        cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            obj = PHOEDT_TOUCH_ITEM_CSK;
        }

        cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            obj = PHOEDT_TOUCH_ITEM_RSK;
        }
    }

    return obj;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_main_get_pen_on_obj
* DESCRIPTION
*  get pen on obj in main screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_main_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *obj = PHOEDT_TOUCH_ITEM_NONE;

    return MMI_TRUE;
}


#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_get_pen_on_obj
* DESCRIPTION
*  FTE ONLY: get pen on obj in clip screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_clip_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;
    phoedt_rect_struct          rect;
    MMI_BOOL                    moving          = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rect = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect;

    *obj = PHOEDT_TOUCH_ITEM_NONE;

    /* if user is moving the edge or rect, will not check all the items */
    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTUP) ||
       MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN) ||
       MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP) ||
       MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN) ||
       MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RECT))
    {
        moving = MMI_TRUE;
    }

    if(MMI_FALSE == moving)
    {
        cop.pos_x = rect.offset.x;
        cop.pos_y = rect.offset.y;
        cop.width = rect.size.w;
        cop.height = rect.size.h;

        if(MMI_TRUE == wgui_test_object_position(pos,
            g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP]))
        {
            *obj = PHOEDT_TOUCH_ITEM_CLIP_LEFTUP;
        }
        else if(MMI_TRUE == wgui_test_object_position(pos,
            g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN]))
        {
            *obj = PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN;
        }
        else if(MMI_TRUE == wgui_test_object_position(pos,
            g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP]))
        {
            *obj = PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP;
        }
        else if(MMI_TRUE == wgui_test_object_position(pos,
            g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN]))
        {
            *obj = PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN;
        }
        else if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = PHOEDT_TOUCH_ITEM_CLIP_RECT;
        }
    }

    if(MMI_FALSE == moving)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


#else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_get_pen_on_obj
* DESCRIPTION
*  get pen on obj in clip screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_clip_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;
    phoedt_rect_struct          rect;
    MMI_BOOL                    moving          = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rect = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect;

    *obj = PHOEDT_TOUCH_ITEM_NONE;

    if(PHOEDT_CLIP_TYPE_FIX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
    {
        /* if user is moving the rect, will not check all the items */
        if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RECT))
        {
            moving = MMI_TRUE;
        }

        if(MMI_FALSE == moving)
        {
            cop.pos_x = rect.offset.x;
            cop.pos_y = rect.offset.y;
            cop.width = rect.size.w;
            cop.height = rect.size.h;
            if(MMI_TRUE == wgui_test_object_position(pos, cop))
            {
                *obj = PHOEDT_TOUCH_ITEM_CLIP_RECT;
            }

            cop.pos_x = g_phoedt_layout.button_21.x;
            cop.pos_y = g_phoedt_layout.button_21.y;
            cop.width = g_phoedt_layout.button_size.w;
            cop.height = g_phoedt_layout.button_size.h;
            if(MMI_TRUE == wgui_test_object_position(pos, cop))
            {
                *obj = PHOEDT_TOUCH_ITEM_CLIP_ZOOMIN;
            }

            cop.pos_x = g_phoedt_layout.button_22.x;
            cop.pos_y = g_phoedt_layout.button_22.y;
            cop.width = g_phoedt_layout.button_size.w;
            cop.height = g_phoedt_layout.button_size.h;
            if(MMI_TRUE == wgui_test_object_position(pos, cop))
            {
                *obj = PHOEDT_TOUCH_ITEM_CLIP_ZOOMOUT;
            }
        }
    }
    else if(PHOEDT_CLIP_TYPE_MANUAL_CLIP == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
    {
        /* if user is moving the edge or rect, will not check all the items */
        if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHT) ||
           MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_DOWN) ||
           MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN) ||
           MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFT) ||
           MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_UP) ||
           MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTUP) ||
           MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RECT))
        {
            moving = MMI_TRUE;
        }

        switch(g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_state)
        {
        case PHOEDT_CLIP_STATE_RIGHTDOWN:
            {
                if(MMI_FALSE == moving)
                {
                    cop.pos_x = (rect.offset.x + rect.size.w - 1) - PHOEDT_CLIP_EDGE_RANGE_RADIUS;
                    cop.pos_y = rect.offset.y - PHOEDT_CLIP_EDGE_RANGE_RADIUS;
                    cop.width = 1 + (PHOEDT_CLIP_EDGE_RANGE_RADIUS << 1);
                    cop.height = rect.size.h + (PHOEDT_CLIP_EDGE_RANGE_RADIUS << 1);
                    if(MMI_TRUE == wgui_test_object_position(pos, cop))
                    {
                        *obj = PHOEDT_TOUCH_ITEM_CLIP_RIGHT;
                    }

                    cop.pos_x = rect.offset.x - PHOEDT_CLIP_EDGE_RANGE_RADIUS;
                    cop.pos_y = (rect.offset.y + rect.size.h - 1) - PHOEDT_CLIP_EDGE_RANGE_RADIUS;
                    cop.width = rect.size.w + (PHOEDT_CLIP_EDGE_RANGE_RADIUS << 1);
                    cop.height = 1 + (PHOEDT_CLIP_EDGE_RANGE_RADIUS << 1);
                    if(MMI_TRUE == wgui_test_object_position(pos, cop))
                    {
                        if(PHOEDT_TOUCH_ITEM_CLIP_RIGHT == *obj)
                        {
                            *obj = PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN;
                        }
                        else
                        {
                            *obj = PHOEDT_TOUCH_ITEM_CLIP_DOWN;
                        }
                    }
                }
            }
            break;

        case PHOEDT_CLIP_STATE_LEFTUP:
            {
                if(MMI_FALSE == moving)
                {
                    cop.pos_x = rect.offset.x - PHOEDT_CLIP_EDGE_RANGE_RADIUS;
                    cop.pos_y = rect.offset.y - PHOEDT_CLIP_EDGE_RANGE_RADIUS;
                    cop.width = 1 + (PHOEDT_CLIP_EDGE_RANGE_RADIUS << 1);
                    cop.height = rect.size.h + (PHOEDT_CLIP_EDGE_RANGE_RADIUS << 1);
                    if(MMI_TRUE == wgui_test_object_position(pos, cop))
                    {
                        *obj = PHOEDT_TOUCH_ITEM_CLIP_LEFT;
                    }

                    cop.pos_x = rect.offset.x - PHOEDT_CLIP_EDGE_RANGE_RADIUS;
                    cop.pos_y = rect.offset.y - PHOEDT_CLIP_EDGE_RANGE_RADIUS;
                    cop.width = rect.size.w + (PHOEDT_CLIP_EDGE_RANGE_RADIUS << 1);
                    cop.height = 1 + (PHOEDT_CLIP_EDGE_RANGE_RADIUS << 1);
                    if(MMI_TRUE == wgui_test_object_position(pos, cop))
                    {
                        if(PHOEDT_TOUCH_ITEM_CLIP_LEFT == *obj)
                        {
                            *obj = PHOEDT_TOUCH_ITEM_CLIP_LEFTUP;
                        }
                        else
                        {
                            *obj = PHOEDT_TOUCH_ITEM_CLIP_UP;
                        }
                    }
                }
            }
            break;

        case PHOEDT_CLIP_STATE_MOVE:
            {
                cop.pos_x = rect.offset.x;
                cop.pos_y = rect.offset.y;
                cop.width = rect.size.w;
                cop.height = rect.size.h;
                if(MMI_TRUE == wgui_test_object_position(pos, cop))
                {
                    *obj = PHOEDT_TOUCH_ITEM_CLIP_RECT;
                }
            }
            break;

        default:
            {
                MMI_ASSERT(0);
            }
            break;
        }

        if(MMI_FALSE == moving)
        {
            cop.pos_x = g_phoedt_layout.button_32.x;
            cop.pos_y = g_phoedt_layout.button_32.y;
            cop.width = g_phoedt_layout.button_size.w;
            cop.height = g_phoedt_layout.button_size.h;
            if(MMI_TRUE == wgui_test_object_position(pos, cop))
            {
                *obj = PHOEDT_TOUCH_ITEM_CLIP_STATE_ICON;
            }
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

    if(MMI_FALSE == moving)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_effect_get_pen_on_obj
* DESCRIPTION
*  get pen on obj in effect screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_effect_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *obj = PHOEDT_TOUCH_ITEM_NONE;

    cop.pos_x = g_phoedt_layout.left_arrow.x;
    cop.pos_y = g_phoedt_layout.left_arrow.y;
    cop.width = g_phoedt_layout.arrow_size.w;
    cop.height = g_phoedt_layout.arrow_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_PREV;
    }

    cop.pos_x = g_phoedt_layout.right_arrow.x;
    cop.pos_y = g_phoedt_layout.right_arrow.y;
    cop.width = g_phoedt_layout.arrow_size.w;
    cop.height = g_phoedt_layout.arrow_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_NEXT;
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_get_pen_on_obj
* DESCRIPTION
*  get pen on obj in adjust screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_adjust_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;
    U16                         curr_item_idx;
    U16                         para_count;
    U16                         idx;
    phoedt_rect_struct          rect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_item_idx   = g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx;
    para_count      = g_phoedt_cui_cntx_p->ies_capacity.adjusts[g_phoedt_cui_cntx_p->curr_act.para.adjust.idx].para_count;

    *obj = PHOEDT_TOUCH_ITEM_NONE;

    for(idx = 0; idx < para_count; idx++)
    {
        rect = cui_phoedt_get_adjust_static_obj_rect(PHOEDT_ADJUST_STATIC_OBJ_TYPE_ICON, idx);
        cop.pos_x = rect.offset.x;
        cop.pos_y = rect.offset.y;
        cop.width = rect.size.w;
        cop.height = rect.size.h;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = (phoedt_touch_item_enum)(PHOEDT_TOUCH_ITEM_ADJUST_ICON + idx);
        }
    }

    rect = cui_phoedt_get_adjust_static_obj_rect(PHOEDT_ADJUST_STATIC_OBJ_TYPE_BAR, curr_item_idx);
    cop.pos_x = rect.offset.x;
    cop.pos_y = rect.offset.y;
    cop.width = rect.size.w;
    cop.height = rect.size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_ADJUST_BAR;
    }

    cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.adjust_slider;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_ADJUST_SLIDER;
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_icon_get_pen_on_obj
* DESCRIPTION
*  get pen on obj in add icon screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_icon_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *obj = PHOEDT_TOUCH_ITEM_NONE;

    cop.pos_x = g_phoedt_cui_cntx_p->curr_act.para.icon.location.x;
    cop.pos_y = g_phoedt_cui_cntx_p->curr_act.para.icon.location.y;
    cop.width = g_phoedt_cui_cntx_p->curr_act.para.icon.size;
    cop.height = g_phoedt_cui_cntx_p->curr_act.para.icon.size;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_ICON_ICON;
    }

    cop.pos_x = g_phoedt_layout.button_31.x;
    cop.pos_y = g_phoedt_layout.button_31.y;
    cop.width = g_phoedt_layout.button_size.w;
    cop.height = g_phoedt_layout.button_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_ICON_ROTATE;
    }

    cop.pos_x = g_phoedt_layout.button_32.x;
    cop.pos_y = g_phoedt_layout.button_32.y;
    cop.width = g_phoedt_layout.button_size.w;
    cop.height = g_phoedt_layout.button_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_ICON_ZOOMIN;
    }

    cop.pos_x = g_phoedt_layout.button_33.x;
    cop.pos_y = g_phoedt_layout.button_33.y;
    cop.width = g_phoedt_layout.button_size.w;
    cop.height = g_phoedt_layout.button_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_ICON_ZOOMOUT;
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_frame_get_pen_on_obj
* DESCRIPTION
*  get pen on obj in add frame screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_frame_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *obj = PHOEDT_TOUCH_ITEM_NONE;

    cop.pos_x = g_phoedt_layout.left_arrow.x;
    cop.pos_y = g_phoedt_layout.left_arrow.y;
    cop.width = g_phoedt_layout.arrow_size.w;
    cop.height = g_phoedt_layout.arrow_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_PREV;
    }

    cop.pos_x = g_phoedt_layout.right_arrow.x;
    cop.pos_y = g_phoedt_layout.right_arrow.y;
    cop.width = g_phoedt_layout.arrow_size.w;
    cop.height = g_phoedt_layout.arrow_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_NEXT;
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_flip_get_pen_on_obj
* DESCRIPTION
*  get pen on obj in flip screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_flip_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *obj = PHOEDT_TOUCH_ITEM_NONE;

    cop.pos_x = g_phoedt_layout.button_21.x;
    cop.pos_y = g_phoedt_layout.button_21.y;
    cop.width = g_phoedt_layout.button_size.w;
    cop.height = g_phoedt_layout.button_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_FLIP_HORZ;
    }

    cop.pos_x = g_phoedt_layout.button_22.x;
    cop.pos_y = g_phoedt_layout.button_22.y;
    cop.width = g_phoedt_layout.button_size.w;
    cop.height = g_phoedt_layout.button_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_FLIP_VERT;
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_rotate_get_pen_on_obj
* DESCRIPTION
*  get pen on obj in rotate screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_rotate_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *obj = PHOEDT_TOUCH_ITEM_NONE;

    cop.pos_x = g_phoedt_layout.button_21.x;
    cop.pos_y = g_phoedt_layout.button_21.y;
    cop.width = g_phoedt_layout.button_size.w;
    cop.height = g_phoedt_layout.button_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_ROTATE_CCW;
    }

    cop.pos_x = g_phoedt_layout.button_22.x;
    cop.pos_y = g_phoedt_layout.button_22.y;
    cop.width = g_phoedt_layout.button_size.w;
    cop.height = g_phoedt_layout.button_size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_ROTATE_CW;
    }

    return MMI_TRUE;
}


#ifdef __MMI_PHOEDT_DOODLE__
#ifdef __MMI_PHOEDT_STYLE_FTE__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_get_pen_on_obj
* DESCRIPTION
*  FTE ONLY: get pen on obj in doodle screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_doodle_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;
    MMI_BOOL                    doodling    = MMI_FALSE;
    U32                         idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *obj = PHOEDT_TOUCH_ITEM_NONE;

    cop.pos_x = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x;
    cop.pos_y = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y;
    cop.width = g_phoedt_cui_cntx_p->display_info.img_rect.size.w;
    cop.height = g_phoedt_cui_cntx_p->display_info.img_rect.size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_DOODLE_DOODLE;
        if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_DOODLE_DOODLE))
        {
            doodling = MMI_TRUE;
        }
    }

    if(MMI_FALSE == doodling)
    {
        cop.pos_x = g_phoedt_layout.doodle_up_down.x;
        cop.pos_y = g_phoedt_layout.doodle_up_down.y;
        cop.width = g_phoedt_layout.doodle_up_down_size.w;
        cop.height = g_phoedt_layout.doodle_up_down_size.h;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = PHOEDT_TOUCH_ITEM_DOODLE_HIDE;
        }

        if(MMI_FALSE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd)
        {
            for(idx = 0; idx < PHOEDT_DOODLE_SIZE_COUNT; idx++)
            {
                cop.pos_x = g_phoedt_layout.doodle_line[idx].x;
                cop.pos_y = g_phoedt_layout.doodle_line[idx].y;
                cop.width = g_phoedt_layout.doodle_button_size.w;
                cop.height = g_phoedt_layout.doodle_button_size.h;
                if(MMI_TRUE == wgui_test_object_position(pos, cop))
                {
                    *obj = (phoedt_touch_item_enum)(PHOEDT_TOUCH_ITEM_DOODLE_LINE_1 + idx);
                }

                cop.pos_x = g_phoedt_layout.doodle_eraser[idx].x;
                cop.pos_y = g_phoedt_layout.doodle_eraser[idx].y;
                cop.width = g_phoedt_layout.doodle_button_size.w;
                cop.height = g_phoedt_layout.doodle_button_size.h;
                if(MMI_TRUE == wgui_test_object_position(pos, cop))
                {
                    *obj = (phoedt_touch_item_enum)(PHOEDT_TOUCH_ITEM_DOODLE_ERASER_1 + idx);
                }
            }

            cop.pos_x = g_phoedt_layout.doodle_color.x;
            cop.pos_y = g_phoedt_layout.doodle_color.y;
            cop.width = g_phoedt_layout.doodle_button_size.w;
            cop.height = g_phoedt_layout.doodle_button_size.h;
            if(MMI_TRUE == wgui_test_object_position(pos, cop))
            {
                *obj = PHOEDT_TOUCH_ITEM_DOODLE_COLOR;
            }
        }
    }

    if (MMI_FALSE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd &&
        MMI_FALSE== doodling)
    {
        cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = PHOEDT_TOUCH_ITEM_LSK;
        }

        cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = PHOEDT_TOUCH_ITEM_CSK;
        }

        cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = PHOEDT_TOUCH_ITEM_RSK;
        }
    }

    return MMI_FALSE;
}


#else /* __MMI_PHOEDT_STYLE_FTE__ */
/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_get_pen_on_obj
* DESCRIPTION
*  get pen on obj in doodle screen
* PARAMETERS
*  pos          [IN]
*  obj          [OUT]
* RETURNS
*  still search softkey or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_doodle_get_pen_on_obj(mmi_pen_point_struct pos, phoedt_touch_item_enum *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct  cop;
    MMI_BOOL                    doodling    = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *obj = PHOEDT_TOUCH_ITEM_NONE;
    cop.pos_x = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x;
    cop.pos_y = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y;
    cop.width = g_phoedt_cui_cntx_p->display_info.img_rect.size.w;
    cop.height = g_phoedt_cui_cntx_p->display_info.img_rect.size.h;
    if(MMI_TRUE == wgui_test_object_position(pos, cop))
    {
        *obj = PHOEDT_TOUCH_ITEM_DOODLE_DOODLE;
        if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_DOODLE_DOODLE))
        {
            doodling = MMI_TRUE;
        }
    }

    if(MMI_FALSE == doodling)
    {
        cop.pos_x = g_phoedt_layout.doodle_hide.x;
        cop.pos_y = g_phoedt_layout.doodle_hide.y;
        cop.width = g_phoedt_layout.doodle_button_size.w;
        cop.height = g_phoedt_layout.doodle_button_size.h;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = PHOEDT_TOUCH_ITEM_DOODLE_HIDE;
        }

        if(MMI_FALSE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd)
        {
            cop.pos_x = g_phoedt_layout.doodle_type.x;
            cop.pos_y = g_phoedt_layout.doodle_type.y;
            cop.width = g_phoedt_layout.doodle_button_size.w;
            cop.height = g_phoedt_layout.doodle_button_size.h;
            if(MMI_TRUE == wgui_test_object_position(pos, cop))
            {
                *obj = PHOEDT_TOUCH_ITEM_DOODLE_TYPE;
            }

            cop.pos_x = g_phoedt_layout.doodle_size.x;
            cop.pos_y = g_phoedt_layout.doodle_size.y;
            cop.width = g_phoedt_layout.doodle_button_size.w;
            cop.height = g_phoedt_layout.doodle_button_size.h;
            if(MMI_TRUE == wgui_test_object_position(pos, cop))
            {
                *obj = PHOEDT_TOUCH_ITEM_DOODLE_SIZE;
            }

            if(PHOEDT_DOODLE_TYPE_LINE == g_phoedt_cui_cntx_p->curr_act.para.doodle.type)
            {
                cop.pos_x = g_phoedt_layout.doodle_color.x;
                cop.pos_y = g_phoedt_layout.doodle_color.y;
                cop.width = g_phoedt_layout.doodle_button_size.w;
                cop.height = g_phoedt_layout.doodle_button_size.h;
                if(MMI_TRUE == wgui_test_object_position(pos, cop))
                {
                    *obj = PHOEDT_TOUCH_ITEM_DOODLE_COLOR;
                }
            }
        }
    }

    if (MMI_FALSE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd &&
        MMI_FALSE== doodling)
    {
        cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = PHOEDT_TOUCH_ITEM_LSK;
        }

        cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = PHOEDT_TOUCH_ITEM_CSK;
        }

        cop = g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk;
        if(MMI_TRUE == wgui_test_object_position(pos, cop))
        {
            *obj = PHOEDT_TOUCH_ITEM_RSK;
        }
    }

    return MMI_FALSE;
}
#endif /* __MMI_PHOEDT_STYLE_FTE__ */
#endif /* __MMI_PHOEDT_DOODLE__ */
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_move_rect_in_an_area_by_info
* DESCRIPTION
*  move a rect in another rect
* PARAMETERS
*  available_rect   [IN]        available area
*  move_rect        [IN/OUT]    the rect that is moved in available_rect
*  move_info        [IN]        move info, step, direction
* RETURNS
*  indicate if can move more, MMI_TRUE: can move more; MMI_FALSE: cannot move more
*****************************************************************************/
static MMI_BOOL cui_phoedt_move_rect_in_an_area_by_info(
    const phoedt_rect_struct        available_rect,
    phoedt_rect_struct              *move_rect,
    const phoedt_move_info_struct   move_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    can_move_more   = MMI_TRUE;
    U32         step            = move_info.step;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(move_info.direction)
    {
    case PHOEDT_MOVE_DIR_LEFT:
        {
            move_rect->offset.x -= step;
            if(move_rect->offset.x < available_rect.offset.x)
            {
                move_rect->offset.x = available_rect.offset.x;
                can_move_more = MMI_FALSE;
            }
        }
        break;

    case PHOEDT_MOVE_DIR_RIGHT:
        {
            move_rect->offset.x += step;
            if((move_rect->offset.x + move_rect->size.w) > (available_rect.offset.x + available_rect.size.w))
            {
                move_rect->offset.x = (available_rect.offset.x + available_rect.size.w) - move_rect->size.w;
                can_move_more = MMI_FALSE;
            }
        }
        break;

    case PHOEDT_MOVE_DIR_UP:
        {
            move_rect->offset.y -= step;
            if(move_rect->offset.y < available_rect.offset.y)
            {
                move_rect->offset.y = available_rect.offset.y;
                can_move_more = MMI_FALSE;
            }
        }
        break;

    case PHOEDT_MOVE_DIR_DOWN:
        {
            move_rect->offset.y += step;
            if((move_rect->offset.y + move_rect->size.h) > (available_rect.offset.y + available_rect.size.h))
            {
                move_rect->offset.y = (available_rect.offset.y + available_rect.size.h) - move_rect->size.h;
                can_move_more = MMI_FALSE;
            }
        }
        break;

    default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
    return can_move_more;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_move_rect_in_an_area_by_points
* DESCRIPTION
*  move the clip rect by two points
* PARAMETERS
*  available_rect   [IN]        available area
*  move_rect        [IN/OUT]    the rect that is moved in available_rect
*  start            [IN]
*  end              [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_move_rect_in_an_area_by_points(
    const phoedt_rect_struct        available_rect,
    phoedt_rect_struct              *move_rect,
    const phoedt_pos_struct         start,
    const phoedt_pos_struct         end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_move_info_struct     move_info;
    S32                         diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* process horizontal direction */
    diff = end.x - start.x;
    if(0 <= diff)
    {
        move_info.direction = PHOEDT_MOVE_DIR_RIGHT;
        move_info.step = diff;
    }
    else if(0 > diff)
    {
        move_info.direction = PHOEDT_MOVE_DIR_LEFT;
        move_info.step = diff * (-1);
    }
    if(0 != diff)
    {
        cui_phoedt_move_rect_in_an_area_by_info(available_rect, move_rect, move_info);
    }

    /* process vertical direction */
    diff = end.y - start.y;
    if(0 <= diff)
    {
        move_info.direction = PHOEDT_MOVE_DIR_DOWN;
        move_info.step = diff;
    }
    else if(0 > diff)
    {
        move_info.direction = PHOEDT_MOVE_DIR_UP;
        move_info.step = diff * (-1);
    }
    if(0 != diff)
    {
        cui_phoedt_move_rect_in_an_area_by_info(available_rect, move_rect, move_info);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_change_clip_rect_in_an_area_by_info
* DESCRIPTION
*  change clip rect by move info
* PARAMETERS
*  obj              [IN]
*  available_rect   [IN]        available area
*  clip_rect        [IN/OUT]    the rect that is moved in available_rect
*  move_info        [IN]        move info, step, direction
* RETURNS
*  indicate if can change more, MMI_TRUE: can change more; MMI_FALSE: cannot change more
*****************************************************************************/
static MMI_BOOL cui_phoedt_change_clip_rect_in_an_area_by_info(
    const phoedt_clip_rect_adjust_edge_enum     edge,
    const phoedt_rect_struct                    available_rect,
    phoedt_rect_struct                          *clip_rect,
    const phoedt_move_info_struct               move_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            can_change_more = MMI_TRUE;
    S32                 step            = move_info.step;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(move_info.direction)
    {
    case PHOEDT_MOVE_DIR_LEFT:
        {
            switch(edge)
            {
            case PHOEDT_CLIP_RECT_ADJUST_EDGE_LEFT:
                {
                    if(clip_rect->offset.x - step < available_rect.offset.x)
                    {
                        step = clip_rect->offset.x - available_rect.offset.x;
                        can_change_more = MMI_FALSE;
                    }

                    clip_rect->offset.x -= step;
                    clip_rect->size.w += step;
                }
                break;

            case PHOEDT_CLIP_RECT_ADJUST_EDGE_RIGHT:
                {
                    if(clip_rect->size.w - step < PHOEDT_MIN_IMG_WIDTH)
                    {
                        step = clip_rect->size.w - PHOEDT_MIN_IMG_WIDTH;
                        can_change_more = MMI_FALSE;
                    }

                    clip_rect->size.w -= step;
                }
                break;

            default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break;

    case PHOEDT_MOVE_DIR_RIGHT:
        {
            switch(edge)
            {
            case PHOEDT_CLIP_RECT_ADJUST_EDGE_LEFT:
                {
                    if(clip_rect->size.w - step < PHOEDT_MIN_IMG_WIDTH)
                    {
                        step = clip_rect->size.w - PHOEDT_MIN_IMG_WIDTH;
                        can_change_more = MMI_FALSE;
                    }

                    clip_rect->size.w -= step;
                    clip_rect->offset.x += step;
                }
                break;

            case PHOEDT_CLIP_RECT_ADJUST_EDGE_RIGHT:
                {
                    if((clip_rect->offset.x + clip_rect->size.w) + step > available_rect.offset.x + available_rect.size.w)
                    {
                        step = (available_rect.offset.x + available_rect.size.w) - (clip_rect->offset.x + clip_rect->size.w);
                        can_change_more = MMI_FALSE;
                    }

                    clip_rect->size.w += step;
                }
                break;

            default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break;

    case PHOEDT_MOVE_DIR_UP:
        {
            switch(edge)
            {
            case PHOEDT_CLIP_RECT_ADJUST_EDGE_UP:
                {
                    if(clip_rect->offset.y - step < available_rect.offset.y)
                    {
                        step = clip_rect->offset.y - available_rect.offset.y;
                        can_change_more = MMI_FALSE;
                    }

                    clip_rect->offset.y -= step;
                    clip_rect->size.h += step;
                }
                break;

            case PHOEDT_CLIP_RECT_ADJUST_EDGE_DOWN:
                {
                    if(clip_rect->size.h - step < PHOEDT_MIN_IMG_HEIGHT)
                    {
                        step = clip_rect->size.h - PHOEDT_MIN_IMG_HEIGHT;
                        can_change_more = MMI_FALSE;
                    }

                    clip_rect->size.h -= step;
                }
                break;

            default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break;

    case PHOEDT_MOVE_DIR_DOWN:
        {
            switch(edge)
            {
            case PHOEDT_CLIP_RECT_ADJUST_EDGE_UP:
                {
                    if(clip_rect->size.h - step < PHOEDT_MIN_IMG_HEIGHT)
                    {
                        step = clip_rect->size.h - PHOEDT_MIN_IMG_HEIGHT;
                        can_change_more = MMI_FALSE;
                    }

                    clip_rect->size.h -= step;
                    clip_rect->offset.y += step;
                }
                break;

            case PHOEDT_CLIP_RECT_ADJUST_EDGE_DOWN:
                {
                    if((clip_rect->offset.y + clip_rect->size.h) + step > available_rect.offset.y + available_rect.size.h)
                    {
                        step = (available_rect.offset.y + available_rect.size.h) - (clip_rect->offset.y + clip_rect->size.h);
                        can_change_more = MMI_FALSE;
                    }

                    clip_rect->size.h += step;
                }
                break;

            default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        }
        break;

    default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

    return can_change_more;
}


#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_fix_ratio_clip_rect_in_an_area
* DESCRIPTION
*  FTE ONLY: change clip rect by move infomation
* PARAMETERS
*  obj              [IN]
*  available_rect   [IN]        available area
*  clip_rect        [IN/OUT]    the rect that is moved in available_rect
*  w_h_ratio        [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_adjust_fix_ratio_clip_rect_in_an_area(
    const phoedt_touch_item_enum    obj,
    const phoedt_rect_struct        available_rect,
    phoedt_rect_struct              *move_rect,
    const phoedt_size_struct        w_h_ratio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ava_y1;
    S32 ava_y2;
    S32 rect_w;
    S32 rect_h;
    S32 rect_max_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PHOEDT_CLIP_TYPE_FIX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
    {
        ava_y1 = available_rect.offset.y;
        ava_y2 = available_rect.offset.y + available_rect.size.h - 1;

        rect_h = w_h_ratio.h * move_rect->size.w / w_h_ratio.w;

        switch(obj)
        {
        case PHOEDT_TOUCH_ITEM_CLIP_LEFTUP:
                {
                    /* adjust y */
                    rect_max_h = move_rect->offset.y + move_rect->size.h - ava_y1;

                    move_rect->offset.y = move_rect->offset.y + move_rect->size.h - rect_h;
                    move_rect->size.h = rect_h;

                    if (rect_h < PHOEDT_MIN_IMG_HEIGHT || rect_h > rect_max_h)
                    {
                        if(rect_h < PHOEDT_MIN_IMG_HEIGHT)
                        {
                            move_rect->offset.y = move_rect->offset.y + move_rect->size.h - PHOEDT_MIN_IMG_HEIGHT;
                            move_rect->size.h = PHOEDT_MIN_IMG_HEIGHT;
                        }
                        else if(rect_h > rect_max_h)
                        {
                            move_rect->offset.y = ava_y1;
                            move_rect->size.h = rect_max_h;
                        }
                        rect_w = w_h_ratio.w * move_rect->size.h / w_h_ratio.h;
                        move_rect->offset.x = move_rect->offset.x + move_rect->size.w - rect_w;
                        move_rect->size.w = rect_w;
                    }
                }
                break;

            case PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN:
                {
                    /* adjust y */
                    rect_max_h = ava_y2 - move_rect->offset.y + 1;

                    move_rect->size.h = rect_h;

                    if (rect_h < PHOEDT_MIN_IMG_HEIGHT || rect_h > rect_max_h)
                    {
                        if(rect_h < PHOEDT_MIN_IMG_HEIGHT)
                        {
                            move_rect->size.h = PHOEDT_MIN_IMG_HEIGHT;
                        }
                        else if(rect_h > rect_max_h)
                        {
                            move_rect->size.h = rect_max_h;
                        }
                        rect_w = w_h_ratio.w * move_rect->size.h / w_h_ratio.h;
                        move_rect->offset.x = move_rect->offset.x + move_rect->size.w - rect_w;
                        move_rect->size.w = rect_w;
                    }
                }
                break;

            case PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP:
                {
                    /* adjust y */
                    rect_max_h = move_rect->offset.y + move_rect->size.h - ava_y1;

                    move_rect->offset.y = move_rect->offset.y + move_rect->size.h - rect_h;
                    move_rect->size.h = rect_h;

                    if (rect_h < PHOEDT_MIN_IMG_HEIGHT || rect_h > rect_max_h)
                    {
                        if(rect_h < PHOEDT_MIN_IMG_HEIGHT)
                        {
                            move_rect->offset.y = move_rect->offset.y + move_rect->size.h - PHOEDT_MIN_IMG_HEIGHT;
                            move_rect->size.h = PHOEDT_MIN_IMG_HEIGHT;
                        }
                        else if(rect_h > rect_max_h)
                        {
                            move_rect->offset.y = ava_y1;
                            move_rect->size.h = rect_max_h;
                        }
                        move_rect->size.w = w_h_ratio.w * move_rect->size.h / w_h_ratio.h;
                    }
                }
                break;

            case PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN:
                {
                    /* adjust y */
                    rect_max_h = ava_y2 - move_rect->offset.y + 1;

                    move_rect->size.h = rect_h;

                    if (rect_h < PHOEDT_MIN_IMG_HEIGHT || rect_h > rect_max_h)
                    {
                        if(rect_h < PHOEDT_MIN_IMG_HEIGHT)
                        {
                            move_rect->size.h = PHOEDT_MIN_IMG_HEIGHT;
                        }
                        else if(rect_h > rect_max_h)
                        {
                            move_rect->size.h = rect_max_h;
                        }
                        move_rect->size.w = w_h_ratio.w * move_rect->size.h / w_h_ratio.h;
                    }
                }
                break;

            default:
                break;
        }
    }
}
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_change_clip_rect_in_an_area_by_points
* DESCRIPTION
*  change clip rect by two points
* PARAMETERS
*  obj              [IN]
*  available_rect   [IN]        available area
*  clip_rect        [IN/OUT]    the rect that is moved in available_rect
*  start            [IN]
*  end              [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_change_clip_rect_in_an_area_by_points(
    const phoedt_touch_item_enum    obj,
    const phoedt_rect_struct        available_rect,
    phoedt_rect_struct              *move_rect,
    const phoedt_pos_struct         start,
    const phoedt_pos_struct         end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_move_info_struct     move_info;
    S32                         diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* process horizontal direction */
    diff = end.x - start.x;
    if(0 <= diff)
    {
        move_info.direction = PHOEDT_MOVE_DIR_RIGHT;
        move_info.step = diff;
    }
    else if(0 > diff)
    {
        move_info.direction = PHOEDT_MOVE_DIR_LEFT;
        move_info.step = diff * (-1);
    }
    if(0 != diff)
    {
        switch(obj)
        {
    #ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
        case PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN:
    #else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
        case PHOEDT_TOUCH_ITEM_CLIP_LEFT:
    #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
        case PHOEDT_TOUCH_ITEM_CLIP_LEFTUP:
            {
                cui_phoedt_change_clip_rect_in_an_area_by_info(
                    PHOEDT_CLIP_RECT_ADJUST_EDGE_LEFT, available_rect, move_rect, move_info);
            }
            break;

    #ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
        case PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP:
    #else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
        case PHOEDT_TOUCH_ITEM_CLIP_RIGHT:
    #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
        case PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN:
            {
                cui_phoedt_change_clip_rect_in_an_area_by_info(
                    PHOEDT_CLIP_RECT_ADJUST_EDGE_RIGHT, available_rect, move_rect, move_info);
            }
            break;

        default:
            break;
        }
    }

    if(PHOEDT_CLIP_TYPE_MANUAL_CLIP == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
    {
        /* process vertical direction */
        diff = end.y - start.y;
        if(0 <= diff)
        {
            move_info.direction = PHOEDT_MOVE_DIR_DOWN;
            move_info.step = diff;
        }
        else if(0 > diff)
        {
            move_info.direction = PHOEDT_MOVE_DIR_UP;
            move_info.step = diff * (-1);
        }
        if(0 != diff)
        {
            switch(obj)
            {
        #ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
            case PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP:
        #else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
            case PHOEDT_TOUCH_ITEM_CLIP_UP:
        #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
            case PHOEDT_TOUCH_ITEM_CLIP_LEFTUP:
                {
                    cui_phoedt_change_clip_rect_in_an_area_by_info(
                        PHOEDT_CLIP_RECT_ADJUST_EDGE_UP, available_rect, move_rect, move_info);
                }
                break;

        #ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
            case PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN:
        #else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
            case PHOEDT_TOUCH_ITEM_CLIP_DOWN:
        #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
            case PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN:
                {
                    cui_phoedt_change_clip_rect_in_an_area_by_info(
                        PHOEDT_CLIP_RECT_ADJUST_EDGE_DOWN, available_rect, move_rect, move_info);
                }
                break;

            default:
                break;
            }
        }
    }
#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
    else
    {
        cui_phoedt_adjust_fix_ratio_clip_rect_in_an_area(
            obj, available_rect, move_rect,
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio);
    }
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_proc
* DESCRIPTION
*
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret         ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == cui_menu_is_menu_event(evt->evt_id))
    {
        ret = cui_phoedt_menu_proc(evt);
    }
    else
    {
        switch(evt->evt_id)
        {
        case EVT_ID_GROUP_DEINIT:
            {
                mmi_scenario_evt_struct *scenario_evt = (mmi_scenario_evt_struct*)evt;
                if(NULL != g_phoedt_cui_cntx_p && scenario_evt->targ_group == g_phoedt_cui_cntx_p->cui_gid)
                {
                    cui_phoedt_release_resource();
                }
            }
            break;

            /* fmgr CUI begin ********************************************************/
        case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
            ret = cui_phoedt_folder_selector_proc(evt);
            break;
            /* fmgr CUI end **********************************************************/

            /* filename editor CUI begin *********************************************/
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
            ret = cui_phoedt_filename_editor_proc(evt);
            break;
            /* filename editor CUI end ***********************************************/

        default:
            break;
        }
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_confirm_proc
* DESCRIPTION
*
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                     ret             = MMI_RET_OK;
    mmi_alert_result_evt_struct *alert_evt      = (mmi_alert_result_evt_struct*)evt;
    U32                         confirm_type    = (U32)alert_evt->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(EVT_ID_ALERT_QUIT == evt->evt_id)
    {
        switch (alert_evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
                switch(confirm_type)
                {
                case PHOEDT_CONFIRM_TYPE_UNDO:                  cui_phoedt_undo_last_change();              break;
                case PHOEDT_CONFIRM_TYPE_SAVE_FOR_SEND:         cui_phoedt_entry_folder_selector_screen();  break;
                case PHOEDT_CONFIRM_TYPE_EXIT:                  cui_phoedt_exit_curr_phoart();              break;
                default:                                       MMI_ASSERT(0);                              break;
                }
            }
            break;

        default:
            break;
        }
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_filename_editor_proc
* DESCRIPTION
*
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_filename_editor_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret         ret         = MMI_RET_OK;
    U16             error_str;
    cui_filename_editor_result_event_struct *filename_editor_evt = (cui_filename_editor_result_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            if(filename_editor_evt->result > 0)
            {
                /* save the filename */
                mmi_wcscpy(g_phoedt_cui_cntx_p->new_file.filename, filename_editor_evt->filename);
                cui_phoedt_save();
                cui_filename_editor_close(filename_editor_evt->sender_id);
            }
            else if(filename_editor_evt->result == 0)
            {
                cui_filename_editor_close(filename_editor_evt->sender_id);
            }
            else
            {
                error_str = srv_fmgr_fs_error_get_string(filename_editor_evt->result);

                PHOEDT_CUI_DISPLAY_POPUP(
                    g_phoedt_cui_cntx_p->cui_gid,
                    GetString(error_str),
                    MMI_EVENT_FAILURE);
            }
        }
        break;

    default:
        break;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_folder_selector_proc
* DESCRIPTION
*
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_folder_selector_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_folder_selector_result_event_struct *evt_fs         = (cui_folder_selector_result_event_struct *)evt;
    FS_DiskInfo                             disk_info;
    FS_HANDLE                               fs_handle;
    WCHAR                                   drv_name[4];
    mmi_ret                                 ret             = MMI_RET_OK;
    S32                                     fmgr_ret        = evt_fs->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(fmgr_ret > FS_NO_ERROR)
    {
        fmgr_ret = cui_folder_selector_get_selected_filepath(
            evt_fs->sender_id,
            NULL,
            g_phoedt_cui_cntx_p->new_file.filepath,
            (PHOEDT_FULL_PATH_BUFFER_LEN * ENCODING_LENGTH));
    }
    else if(fmgr_ret == FS_NO_ERROR)
    {
        cui_folder_selector_close(evt_fs->sender_id);
        return ret;
    }

    if(fmgr_ret < FS_NO_ERROR)
    {
        /* fs error */
        PHOEDT_CUI_DISPLAY_POPUP(
            g_phoedt_cui_cntx_p->cui_gid,
            GetString(srv_fmgr_fs_error_get_string(fmgr_ret)),
            MMI_EVENT_FAILURE);

        cui_folder_selector_close(evt_fs->sender_id);
        return ret;
    }

    mmi_wcsncpy(drv_name, g_phoedt_cui_cntx_p->new_file.filepath, 3);

    fs_handle = FS_GetDiskInfo(drv_name, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (fs_handle >= 0)
    {
        /* check memory card lock */
        if (disk_info.WriteProtect)
        {
            PHOEDT_CUI_DISPLAY_POPUP(
                g_phoedt_cui_cntx_p->cui_gid,
                GetString(STR_ID_PHOEDT_NOTIFY_UNLOCK_MEMORY_CARD),
                MMI_EVENT_FAILURE);

            cui_folder_selector_close(evt_fs->sender_id);
            return ret;
        }

        cui_phoedt_entry_filename_editor_screen();
        cui_folder_selector_close(evt_fs->sender_id);
    }
    else
    {
        fs_handle = FS_Open(g_phoedt_cui_cntx_p->new_file.filepath, FS_OPEN_DIR | FS_READ_ONLY);
        if (fs_handle < 0)
        {
            PHOEDT_CUI_DISPLAY_POPUP(
                g_phoedt_cui_cntx_p->cui_gid,
                GetString((U16)srv_fmgr_fs_error_get_string(fs_handle)),
                srv_fmgr_fs_error_get_popup_type(fs_handle));

            cui_folder_selector_close(evt_fs->sender_id);
            return ret;
        }
        FS_Close(fs_handle);

        /* file system error */
        PHOEDT_CUI_DISPLAY_POPUP(
            g_phoedt_cui_cntx_p->cui_gid,
            GetString(FMGR_FS_INVALID_FILE_SYSTEM_TEXT),
            MMI_EVENT_FAILURE);

        cui_folder_selector_close(evt_fs->sender_id);
        return ret;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_menu_proc
* DESCRIPTION
*
* PARAMETERS
*  evt              [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;
    cui_menu_event_struct   *menu_evt   = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        break;

    case EVT_ID_CUI_MENU_LIST_ENTRY:
        ret = cui_phoedt_menu_entry_proc(menu_evt);
        break;

    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        ret = cui_phoedt_menu_select_proc(menu_evt);
        break;

    default:
        break;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_menu_entry_proc
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt_menu->parent_menu_id)
    {
    case MENU_ID_PHOEDT_OPTION:
        ret = cui_phoedt_menu_main_entry_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_SEND:
        ret = cui_phoedt_menu_send_entry_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_ADD_FRAME_LIST:
        ret = cui_phoedt_menu_frame_entry_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_ADD_EFFECT:
        ret = cui_phoedt_menu_effect_entry_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_ADJUST:
        ret = cui_phoedt_menu_adjust_entry_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_HELP_LIST:
        ret = cui_phoedt_menu_help_entry_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_CLIP:
        ret = cui_phoedt_menu_clip_entry_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_SAVE_AS_OTHER_SIZE:
        ret = cui_phoedt_menu_save_as_other_size_entry_proc(evt_menu);
        break;

    default:
        break;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_menu_select_proc
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt_menu->parent_menu_id)
    {
    case MENU_ID_PHOEDT_OPTION:
        ret = cui_phoedt_menu_main_select_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_SEND:
        ret = cui_phoedt_menu_send_select_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_ADD_FRAME_LIST:
        ret = cui_phoedt_menu_frame_select_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_ADD_EFFECT:
        ret = cui_phoedt_menu_effect_select_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_ADJUST:
        ret = cui_phoedt_menu_adjust_select_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_HELP_LIST:
        ret = cui_phoedt_menu_help_select_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_CLIP:
        ret = cui_phoedt_menu_clip_select_proc(evt_menu);
        break;

    case MENU_ID_PHOEDT_SAVE_AS_OTHER_SIZE:
        ret = cui_phoedt_menu_save_as_other_size_select_proc(evt_menu);
        break;

    default:
        break;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_clip_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(evt_menu->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_save_as_other_size_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_main_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                     ret         = MMI_RET_OK;
    U32                         num;
    U32                         idx;
    MMI_MENU_ID                 child;
    filetypes_file_type_enum    file_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* keep the new_file path is the same with the org_file path for send function */
    mmi_wcscpy(g_phoedt_cui_cntx_p->new_file.filepath, g_phoedt_cui_cntx_p->org_file.filepath);

    /* unhide all children */
    num = cui_menu_get_currlist_item_count(evt_menu->sender_id);
    for(idx = 0; idx < num; idx++)
    {
        child = cui_menu_get_currlist_menu_id_from_index(evt_menu->sender_id, idx);
        cui_menu_set_item_hidden(evt_menu->sender_id, child, MMI_FALSE);
    }

    /* send ************************************************************************/
    if(MMI_FALSE == g_phoedt_cui_cntx_p->send_cntx.is_available)
    {
        cui_menu_set_item_hidden(
            evt_menu->sender_id,
            MENU_ID_PHOEDT_SEND,
            MMI_TRUE);
    }
    else
    {
        FS_HANDLE fs_ret;

        if(0 == g_phoedt_cui_cntx_p->change_cntx.count)
        {
            file_type = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath(g_phoedt_cui_cntx_p->org_file.filepath);
        }
        else
        {
            file_type = FMGR_TYPE_JPG;
        }

        /* first will check only by file type to decide if show the send option,
        this is to avoid in flight mode, use filepath to query will get none in some project,
        but use file type to query will get several items, this is inconsistent */
        fs_ret = srv_fmgr_types_get_send_option_menu(file_type, NULL);

        if(FS_NO_ERROR < fs_ret)
        {
            g_phoedt_cui_cntx_p->send_cntx.parent_menu_id = fs_ret;
            num = GetNumOfChild_Ext(g_phoedt_cui_cntx_p->send_cntx.parent_menu_id);

            if(0 < num)
            {
                if(0 == g_phoedt_cui_cntx_p->change_cntx.count)
                {
                    g_phoedt_cui_cntx_p->send_cntx.parent_menu_id =
                        srv_fmgr_types_get_send_option_menu(file_type, g_phoedt_cui_cntx_p->org_file.filepath);

                    if(0 < num)
                    {
                        /* this is normal case to show the sub-items */
                        cui_menu_set_non_leaf_item(
                            evt_menu->sender_id,
                            MENU_ID_PHOEDT_SEND,
                            MMI_TRUE);
                    }
                    else
                    {
                        /* this case will show send, but have non sub-items,
                        so select send will popup "no option to forward"
                        set this id to dummy for popup in select proc */
                        g_phoedt_cui_cntx_p->send_cntx.parent_menu_id = PHOEDT_RES_DUMMY_ID;
                    }
                }
                else
                {
                    /* here will show send, and when select it, will popup "Save for send" */
                }
            }
            else
            {
                /* there is no option to forward this type of file, so will not show the send item
                include of a case:
                first entry photo editor, will not show send item cause cannot forward the specific type of file which the original file is
                but after use apply some effect, will show send item, casue can forward jpg file */
                cui_menu_set_item_hidden(
                    evt_menu->sender_id,
                    MENU_ID_PHOEDT_SEND,
                    MMI_TRUE);
            }
        }
        else
        {
            g_phoedt_cui_cntx_p->send_cntx.parent_menu_id = PHOEDT_RES_DUMMY_ID;
            cui_menu_set_item_hidden(
                evt_menu->sender_id,
                MENU_ID_PHOEDT_SEND,
                MMI_TRUE);
        }
    }

    /* effect *******************************************************************************/
    if(0 == g_phoedt_cui_cntx_p->ies_capacity.effect_count)
    {
        cui_menu_set_item_hidden(
            evt_menu->sender_id,
            MENU_ID_PHOEDT_ADD_EFFECT,
            MMI_TRUE);
    }

    /* adjust ******************************************************************************/
    if(0 == g_phoedt_cui_cntx_p->ies_capacity.adjust_count)
    {
        cui_menu_set_item_hidden(
            evt_menu->sender_id,
            MENU_ID_PHOEDT_ADJUST,
            MMI_TRUE);
    }

    /* clip *******************************************************************************/
    /* set to leaf node */
    cui_menu_set_non_leaf_item(
        evt_menu->sender_id,
        MENU_ID_PHOEDT_CLIP,
        MMI_FALSE);

    if(PHOEDT_MIN_IMG_WIDTH >= g_phoedt_cui_cntx_p->image_info.curr_size.w ||
       PHOEDT_MIN_IMG_HEIGHT >= g_phoedt_cui_cntx_p->image_info.curr_size.h)
    {
        cui_menu_set_item_hidden(
            evt_menu->sender_id,
            MENU_ID_PHOEDT_CLIP,
            MMI_TRUE);
    }

    /* help ******************************************************************************/
    if (mmi_frm_kbd_is_key_supported(KEY_LEFT_ARROW) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(KEY_RIGHT_ARROW) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(KEY_UP_ARROW) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(KEY_DOWN_ARROW) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_FLIP_HORZ_1) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_FLIP_HORZ_2) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_FLIP_VERT_1) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_FLIP_VERT_2) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_ICON_ROTATE) == MMI_FALSE ||
    #ifndef __MMI_PHOEDT_STYLE_FTE_CLIP__
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_MANUAL_CLIP_STATE) == MMI_FALSE ||
    #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_ROTATE_CCW) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_ROTATE_CW) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_ZOOM_IN) == MMI_FALSE ||
        mmi_frm_kbd_is_key_supported(PHOEDT_KEY_MAP_ZOOM_OUT) == MMI_FALSE)
    {
        cui_menu_set_item_hidden(
            evt_menu->sender_id,
            MENU_ID_PHOEDT_HELP,
            MMI_TRUE);
    }

    cui_phoedt_process_main_menu_items(evt_menu->sender_id);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_menu_send_entry_proc
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_send_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;
    MMI_MENU_ID             childs[MAX_SUB_MENUS];
    MMI_STR_ID              strings[MAX_SUB_MENUS];
    U16                     num;
    U16                     idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = GetNumOfChild_Ext(g_phoedt_cui_cntx_p->send_cntx.parent_menu_id);

    GetSequenceItemIds_Ext(
        g_phoedt_cui_cntx_p->send_cntx.parent_menu_id, childs);

    GetSequenceStringIds_Ext(
        g_phoedt_cui_cntx_p->send_cntx.parent_menu_id, strings);

    cui_menu_set_currlist(evt_menu->sender_id, num, childs);

    cui_menu_set_currlist_flags(evt_menu->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    for(idx = 0; idx < num; idx++)
    {
        cui_menu_set_item_string(
            evt_menu->sender_id,
            childs[idx],
            (WCHAR*)GetString(strings[idx]));
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_menu_frame_entry_proc
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_frame_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_flags(evt_menu->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_help_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send */
    if(MMI_FALSE == g_phoedt_cui_cntx_p->send_cntx.is_available)
    {
        cui_menu_set_item_hidden(
            evt_menu->sender_id,
            MENU_ID_PHOEDT_SEND_HELP,
            MMI_TRUE);
    }

    /* effect */
    if(0 == g_phoedt_cui_cntx_p->ies_capacity.effect_count)
    {
        cui_menu_set_item_hidden(
            evt_menu->sender_id,
            MENU_ID_PHOEDT_EFFECT_HELP,
            MMI_TRUE);
    }

    cui_menu_set_currlist_flags(evt_menu->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_menu_effect_entry_proc
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_effect_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;
    MMI_MENU_ID             item_list[PHOEDT_EFFECT_MAX_COUNT];
    MMI_STR_ID              name_list[PHOEDT_EFFECT_MAX_COUNT];
    U32                     idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(idx = 0; idx < g_phoedt_cui_cntx_p->ies_capacity.effect_count; idx++)
    {
        item_list[idx] = idx;
        name_list[idx] = g_phoedt_cui_cntx_p->ies_capacity.effects[idx].name;
    }

    cui_menu_set_currlist(evt_menu->sender_id, g_phoedt_cui_cntx_p->ies_capacity.effect_count, item_list);

    for(idx = 0; idx < g_phoedt_cui_cntx_p->ies_capacity.effect_count; idx++)
    {
        cui_menu_set_item_string(evt_menu->sender_id, idx, (WCHAR*)GetString(name_list[idx]));
    }

    cui_menu_set_currlist_flags(evt_menu->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_menu_adjust_entry_proc
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_adjust_entry_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;
    MMI_MENU_ID             item_list[PHOEDT_ADJUST_MAX_COUNT];
    MMI_STR_ID              name_list[PHOEDT_ADJUST_MAX_COUNT];
    U32                     idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(idx = 0; idx < g_phoedt_cui_cntx_p->ies_capacity.adjust_count; idx++)
    {
        item_list[idx] = idx;
        name_list[idx] = g_phoedt_cui_cntx_p->ies_capacity.adjusts[idx].name;
    }

    cui_menu_set_currlist(evt_menu->sender_id, g_phoedt_cui_cntx_p->ies_capacity.adjust_count, item_list);

    for(idx = 0; idx < g_phoedt_cui_cntx_p->ies_capacity.adjust_count; idx++)
    {
        cui_menu_set_item_string(evt_menu->sender_id, idx, (WCHAR*)GetString(name_list[idx]));
    }

    cui_menu_set_currlist_flags(evt_menu->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_clip_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;
    U16                     def_ratio   = PHOEDT_CLIP_RECT_DEFAULT_RATIO;
    U16                     min_ratio   = PHOEDT_CLIP_RECT_MIN_RATIO;
    phoedt_size_struct      clip_rect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_CLIP;

    switch(evt_menu->highlighted_menu_id)
    {
    case MENU_ID_PHOEDT_MAINLCD_CLIP:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_FIX_RATIO;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w = UI_device_width;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h = UI_device_height;
        }
        break;

    case MENU_ID_PHOEDT_CLIP_ORIGINAL_RATIO:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_FIX_RATIO;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w = g_phoedt_cui_cntx_p->image_info.org_size.w;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h = g_phoedt_cui_cntx_p->image_info.org_size.h;
        }
        break;

#ifdef __MMI_SUBLCD__
    case MENU_ID_PHOEDT_SUBLCD_CLIP:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_FIX_RATIO;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w = SUBLCD_WIDTH;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h = SUBLCD_HEIGHT;
        }
        break;
#endif /* __MMI_SUBLCD__ */

    case MENU_ID_PHOEDT_CLIP_16TO9_RATIO:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_FIX_RATIO;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w = 16;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h = 9;
        }
        break;

    case MENU_ID_PHOEDT_CLIP_9TO16_RATIO:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_FIX_RATIO;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w = 9;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h = 16;
        }
        break;

    case MENU_ID_PHOEDT_CLIP_4TO3_RATIO:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_FIX_RATIO;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w = 4;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h = 3;
        }
        break;

    case MENU_ID_PHOEDT_CLIP_3TO4_RATIO:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_FIX_RATIO;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w = 3;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h = 4;
        }
        break;

    case MENU_ID_PHOEDT_CLIP_3TO2_RATIO:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_FIX_RATIO;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w = 3;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h = 2;
        }
        break;

    case MENU_ID_PHOEDT_CLIP_2TO3_RATIO:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_FIX_RATIO;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w = 2;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h = 3;
        }
        break;

    case MENU_ID_PHOEDT_MANUAL_CLIP:
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type = PHOEDT_CLIP_TYPE_MANUAL_CLIP;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_state = PHOEDT_CLIP_STATE_RIGHTDOWN;
        }
        break;

    default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

    if(PHOEDT_CLIP_TYPE_FIX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
    {
        gdi_image_util_fit_bbox(
            g_phoedt_cui_cntx_p->display_info.img_rect.size.w,
            g_phoedt_cui_cntx_p->display_info.img_rect.size.h,
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.w,
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio.h,
            &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.x,
            &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.y,
            &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w,
            &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h);
    }
    else
    {
        gdi_image_util_fit_bbox(
            g_phoedt_cui_cntx_p->display_info.img_rect.size.w,
            g_phoedt_cui_cntx_p->display_info.img_rect.size.h,
            UI_device_width, UI_device_height,
            &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.x,
            &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.y,
            &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w,
            &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h);
    }

    for(min_ratio = PHOEDT_CLIP_RECT_MIN_RATIO;
        min_ratio <= PHOEDT_CLIP_RECT_MAX_RATIO;
        min_ratio += PHOEDT_CLIP_RECT_STEP_RATION)
    {
        clip_rect.w = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w * min_ratio / 100;

        clip_rect.h = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h * min_ratio / 100;

        if(PHOEDT_MIN_IMG_WIDTH < clip_rect.w && PHOEDT_MIN_IMG_HEIGHT < clip_rect.h)
        {
            /* have found the min clip ratio */
            break;
        }
    }

    if(min_ratio > PHOEDT_CLIP_RECT_MAX_RATIO)
    {
        /* the image is too small to clip */
        PHOEDT_CUI_DISPLAY_POPUP(
            g_phoedt_cui_cntx_p->cui_gid,
            (WCHAR*)GetString(STR_ID_PHOEDT_NOTIFY_UNFIT_FOR_EDIT),
            MMI_EVENT_FAILURE);
    }
    else
    {
        def_ratio = min_ratio +
            ((PHOEDT_CLIP_RECT_MAX_RATIO - min_ratio) >> 1)
            / PHOEDT_CLIP_RECT_STEP_RATION * PHOEDT_CLIP_RECT_STEP_RATION;

        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w =
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w * def_ratio / 100;

        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h =
        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h * def_ratio / 100;

        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.x = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x +
            ((g_phoedt_cui_cntx_p->display_info.img_rect.size.w - g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w) >> 1);

        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.y = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y +
            ((g_phoedt_cui_cntx_p->display_info.img_rect.size.h - g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h) >> 1);

    #if !defined(__MMI_PHOEDT_STYLE_FTE_CLIP__)
        if(PHOEDT_CLIP_TYPE_FIX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
        {
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.curr_min_ratio = min_ratio;
            g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio = def_ratio;
        }
    #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */

        cui_phoedt_entry_edit_screen();
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_save_as_other_size_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_SAVE_FILE;
    switch(evt_menu->highlighted_menu_id)
    {
    case MENU_ID_PHOEDT_SAVE_AS_FIT_1280X960:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 1280;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 960;
        }
        break;

    case MENU_ID_PHOEDT_SAVE_AS_FIT_960X1280:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 960;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 1280;
        }
        break;

    case MENU_ID_PHOEDT_SAVE_AS_FIT_640X480:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 640;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 480;
        }
        break;

    case MENU_ID_PHOEDT_SAVE_AS_FIT_480X640:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 480;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 640;
        }
        break;

    case MENU_ID_PHOEDT_SAVE_AS_FIT_320X240:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 320;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 240;
        }
        break;

    case MENU_ID_PHOEDT_SAVE_AS_FIT_240X320:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 240;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 320;
        }
        break;

    case MENU_ID_PHOEDT_SAVE_AS_FIT_176X146:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 176;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 146;
        }
        break;

    case MENU_ID_PHOEDT_SAVE_AS_FIT_146X176:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 146;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 176;
        }
        break;

    case MENU_ID_PHOEDT_SAVE_AS_FIT_160X120:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 160;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 120;
        }
        break;

    case MENU_ID_PHOEDT_SAVE_AS_FIT_120X160:
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w = 120;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h = 160;
        }
        break;

    default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
    cui_phoedt_entry_folder_selector_screen();
    cui_menu_close(evt_menu->sender_id);

    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_main_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt_menu->highlighted_menu_id)
    {
    case MENU_ID_PHOEDT_SAVE_AS:
        {
            g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_SAVE_FILE;
            g_phoedt_cui_cntx_p->curr_act.para.save.output_size = g_phoedt_cui_cntx_p->image_info.curr_size;
            cui_phoedt_entry_folder_selector_screen();
        }
        break;

    case MENU_ID_PHOEDT_SEND:
        {
            if(0 == g_phoedt_cui_cntx_p->change_cntx.count)
            {
                if(PHOEDT_RES_DUMMY_ID == g_phoedt_cui_cntx_p->send_cntx.parent_menu_id)
                {
                    /* the send item is shown, but there is no sub-item in it, then in list entry proc has set
                    g_phoedt_cui_cntx_p->send_cntx.parent_menu_id to PHOEDT_RES_DUMMY_ID to mark for this case */
                    PHOEDT_CUI_DISPLAY_POPUP(
                        g_phoedt_cui_cntx_p->cui_gid,
                        (WCHAR*)GetString(STR_ID_FMGR_NO_FORWARD_OPTION),
                        MMI_EVENT_FAILURE);
                }
            }
            else
            {
                g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_SAVE_FOR_SEND;
                g_phoedt_cui_cntx_p->curr_act.para.save.output_size = g_phoedt_cui_cntx_p->image_info.curr_size;
                PHOEDT_CUI_DISPLAY_POPUP_CONFIRM(
                    g_phoedt_cui_cntx_p->cui_gid,
                    (WCHAR*)GetString(STR_ID_PHOEDT_NOTIFY_UNSAVE_SEND),
                    PHOEDT_CONFIRM_TYPE_SAVE_FOR_SEND);
            }
        }
        break;

    case MENU_ID_PHOEDT_ADD_EFFECT:
        {
            cui_phoedt_entry_effect_list_screen();
        }
        break;

    case MENU_ID_PHOEDT_ADJUST:
        {
            cui_phoedt_entry_adjust_list_screen();
        }
        break;

    case MENU_ID_PHOEDT_ADD_ICON:
        {
            g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_ICON;
            cui_phoedt_entry_matrix_selector_screen();
        }
        break;

    case MENU_ID_PHOEDT_ADD_FRAME:
        {
            g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_FRAME;
            cui_phoedt_entry_frame_list_screen();
        }
        break;

    case MENU_ID_PHOEDT_CLIP:
        {
            cui_phoedt_entry_clip_list_screen();
        }
        break;

    case MENU_ID_PHOEDT_FLIP:
        {
            g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_FLIP;
            cui_phoedt_entry_edit_screen();
        }
        break;

    case MENU_ID_PHOEDT_ROTATE:
        {
            g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_ROTATE;
            cui_phoedt_entry_edit_screen();
        }
        break;

#ifdef __MMI_PHOEDT_DOODLE__
    case MENU_ID_PHOEDT_DOODLE:
        {
            g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_DOODLE;
            cui_phoedt_entry_edit_screen();
        }
        break;
#endif /* #ifdef __MMI_PHOEDT_DOODLE__ */

    case MENU_ID_PHOEDT_UNDO:
        {
            g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_UNDO;
            cui_phoedt_undo_confirm();
        }
        break;

    case MENU_ID_PHOEDT_HELP:
        {
            g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_HELP;
            cui_phoedt_entry_help_list_screen();
        }
        break;

    default:
        break;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_send_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;
    S32                     send_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_SEND;
    send_ret = srv_fmgr_types_launch_option((WCHAR*)g_phoedt_cui_cntx_p->new_file.filepath, evt_menu->highlighted_menu_id);
    if(FS_NO_ERROR > send_ret)
    {
        PHOEDT_CUI_DISPLAY_POPUP(
            g_phoedt_cui_cntx_p->cui_gid,
            (WCHAR*)GetString(srv_fmgr_fs_error_get_string(send_ret)),
            MMI_EVENT_FAILURE);
    }
    if(0 == send_ret)
    {
        MMI_ASSERT(0);
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_frame_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt_menu->highlighted_menu_id)
    {
    case MENU_ID_PHOEDT_FRAME_1:
    case MENU_ID_PHOEDT_FRAME_2:
    case MENU_ID_PHOEDT_FRAME_3:
    case MENU_ID_PHOEDT_FRAME_4:
    case MENU_ID_PHOEDT_FRAME_5:
    case MENU_ID_PHOEDT_FRAME_6:
    case MENU_ID_PHOEDT_FRAME_7:
    case MENU_ID_PHOEDT_FRAME_8:
    case MENU_ID_PHOEDT_FRAME_9:
    case MENU_ID_PHOEDT_FRAME_10:
    case MENU_ID_PHOEDT_FRAME_11:
    case MENU_ID_PHOEDT_FRAME_12:
        g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx = (U16)(evt_menu->highlighted_menu_id - MENU_ID_PHOEDT_FRAME_1);
        cui_phoedt_entry_edit_screen();
        break;

    default:
        break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_effect_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_EFFECT;

    g_phoedt_cui_cntx_p->curr_act.para.effect.idx =
        cui_menu_get_index_in_currlist_from_menu_id(evt_menu->sender_id, evt_menu->highlighted_menu_id);

    cui_phoedt_entry_edit_screen();

    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_adjust_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_ADJUST;

    g_phoedt_cui_cntx_p->curr_act.para.adjust.idx =
        cui_menu_get_index_in_currlist_from_menu_id(evt_menu->sender_id, evt_menu->highlighted_menu_id);

    cui_phoedt_entry_edit_screen();

    return ret;
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  evt_menu             [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_menu_help_select_proc(cui_menu_event_struct *evt_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.para.help.item = evt_menu->highlighted_menu_id;
    cui_phoedt_entry_help_screen();
    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_save
* DESCRIPTION
*  start to save as the image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE       fs_handle;
    S32             path_len;
    S32             name_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path_len = mmi_wcslen(g_phoedt_cui_cntx_p->new_file.filepath);
    name_len = mmi_wcslen(g_phoedt_cui_cntx_p->new_file.filename);

    if (path_len + name_len + PHOEDT_MAX_FILENAME_EXT_CHAR > PHOEDT_FULL_PATH_CHAR)
    {
        /* to avoid over flow */
        PHOEDT_CUI_DISPLAY_POPUP(
            g_phoedt_cui_cntx_p->cui_gid,
            GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT),
            MMI_EVENT_FAILURE);

        /* do not close filename editor */
        return;
    }

    /* add new filename to path */
    kal_wsprintf(
        g_phoedt_cui_cntx_p->new_file.filepath + path_len,
        "%w.jpg", g_phoedt_cui_cntx_p->new_file.filename);

    fs_handle = FS_Open(g_phoedt_cui_cntx_p->new_file.filepath, FS_READ_ONLY);

    if (fs_handle >= FS_NO_ERROR)
    {
        FS_Close(fs_handle);
        PHOEDT_CUI_DISPLAY_POPUP(
            g_phoedt_cui_cntx_p->cui_gid,
            GetString(FMGR_FS_FILE_EXISTS_TEXT),
            MMI_EVENT_FAILURE);

        /* do not close filename editor */
        return;
    }
    else if (fs_handle != FS_FILE_NOT_FOUND)
    {
        PHOEDT_CUI_DISPLAY_POPUP(
            g_phoedt_cui_cntx_p->cui_gid,
            GetString((U16)srv_fmgr_fs_error_get_string(fs_handle)),
            srv_fmgr_fs_error_get_popup_type(fs_handle));

        /* close filename editor */
        mmi_frm_group_close(GRP_ID_PHOEDT_EDIT_GROUP);
        return;
    }

    g_phoedt_cui_cntx_p->curr_act.para.save.parent_gid = g_phoedt_cui_cntx_p->cui_gid;
    g_phoedt_cui_cntx_p->curr_act.para.save.is_bg_save = MMI_FALSE;
    g_phoedt_cui_cntx_p->curr_act.para.save.callback = cui_phoedt_save_callback;

    cui_phoedt_save_file();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_save_file
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  is save done, MMI_FALSE: async saving, MMI_TRUE: block saving
*****************************************************************************/
static void cui_phoedt_save_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result  ies_ret     = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_entry_saving_screen(g_phoedt_cui_cntx_p->curr_act.para.save.parent_gid);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SAVE_OUTPUT_SIZE,
        g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w, g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h);

    ies_ret = srv_ies_image_render_file_async(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        g_phoedt_cui_cntx_p->new_file.filepath,
        g_phoedt_cui_cntx_p->curr_act.para.save.output_size.w,
        g_phoedt_cui_cntx_p->curr_act.para.save.output_size.h,
        SRV_IES_RENDER_KEEP_AR,
        cui_phoedt_save_job_done_callback,
        NULL,
        &g_phoedt_cui_cntx_p->curr_act.para.save.job);

    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(g_phoedt_cui_cntx_p->curr_act.para.save.parent_gid, ies_ret))
    {
        g_phoedt_cui_cntx_p->curr_act.para.save.state = PHOEDT_SAVE_STATE_SAVING;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_save_job_done_callback
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_save_job_done_callback(srv_ies_result result, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID      gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != g_phoedt_cui_cntx_p && MMI_TRUE == g_phoedt_cui_cntx_p->curr_act.para.save.is_bg_save)
    {
        gid = GRP_ID_PHOEDT_PRE_POPUP_GROUP;
    }
    else
    {
        gid = g_phoedt_cui_cntx_p->cui_gid;
    }

    if(NULL != g_phoedt_cui_cntx_p)
    {
        if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(gid, result))
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.state = PHOEDT_SAVE_STATE_SAVED;
            cui_phoedt_update_saving_progress();
        }
        else
        {
            if(NULL != g_phoedt_cui_cntx_p->curr_act.para.save.callback)
            {
                g_phoedt_cui_cntx_p->curr_act.para.save.callback(PHOEDT_SAVE_RESULT_ERROR);
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_update_saving_progress
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_update_saving_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result  ies_ret     = SRV_IES_OK;
    U32             percent     = 0;
    MMI_BOOL        update      = MMI_FALSE;
    MMI_BOOL        done        = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == g_phoedt_cui_cntx_p)
    {
        return;
    }

    if(PHOEDT_SAVE_STATE_SAVING == g_phoedt_cui_cntx_p->curr_act.para.save.state)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SAVE_GET_PERCENT,
            g_phoedt_cui_cntx_p->cat6003_cntx.percent, percent);

        ies_ret = srv_ies_job_query_progress(
            g_phoedt_cui_cntx_p->curr_act.para.save.job,
            &percent);
        PHOEDT_TRACE_IES_RESULT(ies_ret);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SAVE_GET_PERCENT,
            g_phoedt_cui_cntx_p->cat6003_cntx.percent, percent);

        if(percent > g_phoedt_cui_cntx_p->cat6003_cntx.percent)
        {
            g_phoedt_cui_cntx_p->cat6003_cntx.percent = (U8)percent;
            update = MMI_TRUE;
        }

        if(100 > g_phoedt_cui_cntx_p->cat6003_cntx.percent)
        {
            gui_start_timer(PHOEDT_UPDATE_PROGRESS_DURATION, cui_phoedt_update_saving_progress);
        }
        else if(100 == g_phoedt_cui_cntx_p->cat6003_cntx.percent)
        {
            update = MMI_TRUE;
            done = MMI_TRUE;
        }
        else
        {
            /* should not be here */
            MMI_ASSERT(0);
        }
    }
    else if(PHOEDT_SAVE_STATE_SAVED == g_phoedt_cui_cntx_p->curr_act.para.save.state)
    {
        g_phoedt_cui_cntx_p->cat6003_cntx.percent = 100;
        update = MMI_TRUE;
        done = MMI_TRUE;
    }

    if(MMI_TRUE == done)
    {
        gui_cancel_timer(cui_phoedt_update_saving_progress);
    }

    if(MMI_TRUE == update)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SAVE_UPDATE_PERCENT, g_phoedt_cui_cntx_p->cat6003_cntx.percent);

        if(SCR_ID_PHOEDT_SAVING == mmi_frm_scrn_get_active_id())
        {
            wgui_cat6003_update_all(
                g_phoedt_cui_cntx_p->cat6003_cntx.message,
                g_phoedt_cui_cntx_p->cat6003_cntx.sub_message,
                g_phoedt_cui_cntx_p->cat6003_cntx.percent);
        }
    }

    if(PHOEDT_SAVE_STATE_SAVED == g_phoedt_cui_cntx_p->curr_act.para.save.state)
    {
        if(NULL != g_phoedt_cui_cntx_p->curr_act.para.save.callback)
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.callback(PHOEDT_SAVE_RESULT_DONE);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_save_callback
* DESCRIPTION
*  cui_phoedt_save_callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_save_callback(phoedt_save_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(result)
    {
        case PHOEDT_SAVE_RESULT_DONE:
            {
                if(NULL != g_phoedt_cui_cntx_p && PHOEDT_SAVE_STATE_SAVED == g_phoedt_cui_cntx_p->curr_act.para.save.state)
                {
                    phoedt_action_type_enum action = g_phoedt_cui_cntx_p->curr_act.action;
                    
                    /* close processing screen */
                    mmi_frm_scrn_close_active_id();
                    
                    cui_phoedt_set_changed_count(PHOEDT_CHANGE_TYPE_RESET);
                    if(PHOEDT_ACTION_TYPE_SAVE_FILE == action)
                    {
                        PHOEDT_SEND_TO_PARENT(
                            EVT_ID_CUI_PHOEDT_RESULT_SUCCESS,
                            g_phoedt_cui_cntx_p->new_file.filepath);

                        PHOEDT_SEND_TO_PARENT_NO_RESULT(EVT_ID_CUI_PHOEDT_RESULT_CLOSE_ME);
                    }
                    else if(PHOEDT_ACTION_TYPE_SAVE_FOR_SEND == action)
                    {
                        /* send will not invoke parent to do anything. */
                        cui_phoedt_entry_send_list_screen();

                        cui_phoedt_ies_resource_reload_image();
                    }
                }
            }
            break;

        case PHOEDT_SAVE_RESULT_CANCELED:
        case PHOEDT_SAVE_RESULT_ERROR:
        case PHOEDT_SAVE_RESULT_IN_END_KEY:
            break;

        default:
            {
                MMI_ASSERT(0);
            }
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_save_background_callback
* DESCRIPTION
*  cui_phoedt_save_background_callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_save_background_callback(phoedt_save_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(result)
    {
        case PHOEDT_SAVE_RESULT_DONE:
            {
                if(PHOEDT_SAVE_STATE_SAVED == g_phoedt_cui_cntx_p->curr_act.para.save.state)
                {
                    PHOEDT_SEND_TO_PARENT(
                        EVT_ID_CUI_PHOEDT_RESULT_SUCCESS,
                        g_phoedt_cui_cntx_p->new_file.filepath);

                    PHOEDT_SEND_TO_PARENT_NO_RESULT(EVT_ID_CUI_PHOEDT_RESULT_CLOSE_ME);

                    mmi_frm_scrn_close(GRP_ID_PHOEDT_PRE_POPUP_GROUP, SCR_ID_PHOEDT_SAVING);
                }
            }
            break;

        case PHOEDT_SAVE_RESULT_CANCELED:
        case PHOEDT_SAVE_RESULT_ERROR:
        case PHOEDT_SAVE_RESULT_IN_END_KEY:
            break;

        default:
            {
                MMI_ASSERT(0);
            }
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_undo_confirm
* DESCRIPTION
*  undo last change
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_undo_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == g_phoedt_cui_cntx_p->undo_available)
    {
        PHOEDT_CUI_DISPLAY_POPUP_CONFIRM(
            g_phoedt_cui_cntx_p->cui_gid,
            (WCHAR*)GetString(STR_ID_PHOEDT_NOTIFY_UNDO),
            PHOEDT_CONFIRM_TYPE_UNDO);
    }
    else
    {
        PHOEDT_CUI_DISPLAY_POPUP(
            g_phoedt_cui_cntx_p->cui_gid,
            (WCHAR*)GetString(STR_ID_PHOEDT_NOTIFY_CANNOT_UNDO),
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_undo_last_change
* DESCRIPTION
*  undo last change
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_undo_last_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result  ies_ret     = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_UNDO);

    ies_ret = srv_ies_image_undo(g_phoedt_cui_cntx_p->ies_hdles.img);
    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_update_image_curr_size();

        cui_phoedt_reset_image_display_info();

        cui_phoedt_preview_image(MMI_FALSE);

        cui_phoedt_set_changed_count(PHOEDT_CHANGE_TYPE_UNDO);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_set_key_proc
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_set_key_proc(MMI_ID group, MMI_ID screen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_key_proc(
        group,
        screen,
        cui_phoedt_key_proc);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_key_proc
* DESCRIPTION
*  distribute key event
* PARAMETERS
*  evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_phoedt_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct  *key_evt        = (mmi_frm_key_evt_struct*)evt;
    mmi_keypads_enum        key_code        = (mmi_keypads_enum)key_evt->key_code;
    mmi_key_types_enum      key_type        = (mmi_key_types_enum)key_evt->key_type;
    MMI_BOOL                key_valide      = MMI_TRUE;
    MMI_BOOL                is_apply        = MMI_FALSE;
    mmi_ret                 ret             = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == g_phoedt_cui_cntx_p || KEY_END == key_code)
    {
        return ret;
    }

    ret = MMI_RET_KEY_HANDLED;

    if(MMI_TRUE == cui_phoedt_if_drop_key_event())
    {
        return ret;
    }

    switch(key_evt->evt_id)
    {
    case EVT_ID_PRE_KEY:
        {
            switch(key_type)
            {
            case KEY_EVENT_DOWN:
                {
                    MMI_ASSERT(MMI_FALSE == g_phoedt_cui_cntx_p->key_cntx.is_key_down);

                    g_phoedt_cui_cntx_p->key_cntx.is_key_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->key_cntx.key_code = key_code;

                    switch(key_code)
                    {
                    case KEY_LSK:
                        {
                            key_valide = MMI_FALSE;
                        }
                        break;

                    case KEY_RSK:
                        {
                            key_valide = MMI_FALSE;
                        }
                        break;

                    case KEY_CSK:
                        {
                            key_valide = MMI_FALSE;
                        }
                        break;

                    default:
                        break;
                    }

                    if(MMI_FALSE == key_valide)
                    {
                        cui_phoedt_draw_osd();
                        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
                    }
                }
                break;

            case KEY_EVENT_UP:
                {
                    if(MMI_FALSE == g_phoedt_cui_cntx_p->key_cntx.is_key_down ||
                       key_code != g_phoedt_cui_cntx_p->key_cntx.key_code)
                    {
                        key_valide = MMI_FALSE;
                    }
                    else if(PHOEDT_ACTION_TYPE_NONE != g_phoedt_cui_cntx_p->curr_act.action && 
                            PHOEDT_ACTION_TYPE_LOADING != g_phoedt_cui_cntx_p->curr_act.action)
                    {
                        switch(key_code)
                        {
                        case KEY_LSK:
                            {
                                key_valide = MMI_FALSE;
                                is_apply = MMI_TRUE;
                            }
                            break;

                        case KEY_RSK:
                            {
                                key_valide = MMI_FALSE;
                                is_apply = MMI_FALSE;
                            }
                            break;

                        case KEY_CSK:
                            {
                                key_valide = MMI_FALSE;
                                is_apply = MMI_TRUE;
                            }
                            break;

                        default:
                            break;
                        }

                        if(MMI_FALSE == key_valide)
                        {
                            cui_phoedt_reset_interact_item_state();
                            cui_phoedt_draw_osd();
                            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

                            cui_phoedt_end_curr_change(is_apply);
                        }
                    }
                    cui_phoedt_reset_interact_item_state();
                }
                break;

            default:
                {
                    key_valide = MMI_FALSE;
                }
                break;
            }
        }
        break;

    default:
        {
            key_valide = MMI_FALSE;
        }
        break;
    }

    if(MMI_TRUE == key_valide)
    {
        if (NULL != g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].key_hdlr)
            g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].key_hdlr(key_code, key_type);
        else
            MMI_ASSERT(0);
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_main_key_hdlr
* DESCRIPTION
*  distribut key event of main screen
* PARAMETERS
*  key_code         [IN]
*  key_evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_main_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_evt)
    {
    case KEY_EVENT_UP:
        {
            cui_phoedt_reset_interact_item_state();

            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            switch(key_code)
            {
            case KEY_LSK:
                {
                    if (PHOEDT_ACTION_TYPE_LOADING != g_phoedt_cui_cntx_p->curr_act.action)
                    {
                        cui_phoedt_entry_main_option_screen();
                    }
                }
                break;

            case KEY_RSK:
                {
                    cui_phoedt_exit();
                }
                break;

            case KEY_CSK:
                {
                    cui_phoedt_entry_folder_selector_screen();
                    g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_SAVE_FILE;
                    g_phoedt_cui_cntx_p->curr_act.para.save.output_size = g_phoedt_cui_cntx_p->image_info.curr_size;
                }
                break;

            default:
                break;
            }
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_key_hdlr
* DESCRIPTION
*  cui_phoedt_clip_key_hdlr
* PARAMETERS
*  key_code         [IN]
*  key_evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_clip_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    key_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_evt)
    {
    case KEY_EVENT_DOWN:
        {
            switch(key_code)
            {
            case KEY_LEFT_ARROW:
                {
                    cui_phoedt_clip_move_rect(PHOEDT_MOVE_DIR_LEFT);
                }
                break;

            case KEY_RIGHT_ARROW:
                {
                    cui_phoedt_clip_move_rect(PHOEDT_MOVE_DIR_RIGHT);
                }
                break;

            case KEY_UP_ARROW:
                {
                    cui_phoedt_clip_move_rect(PHOEDT_MOVE_DIR_UP);
                }
                break;

            case KEY_DOWN_ARROW:
                {
                    cui_phoedt_clip_move_rect(PHOEDT_MOVE_DIR_DOWN);
                }
                break;

            default:
                {
                #if !defined(__MMI_PHOEDT_STYLE_FTE_CLIP__)
                    if(PHOEDT_CLIP_TYPE_FIX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
                    {
                        U16 scale_state = g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio;
                        if(PHOEDT_KEY_MAP_ZOOM_IN == key_code)
                        {
                            if(PHOEDT_CLIP_RECT_MAX_RATIO > scale_state)
                            {
                                key_valid = MMI_TRUE;
                            }
                        }
                        else if(PHOEDT_KEY_MAP_ZOOM_OUT == key_code)
                        {
                            if(g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.curr_min_ratio < scale_state)
                            {
                                key_valid = MMI_TRUE;
                            }
                        }
                    }
                    else if(PHOEDT_CLIP_TYPE_MANUAL_CLIP == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
                    {
                        if(PHOEDT_KEY_MAP_MANUAL_CLIP_STATE == key_code)
                        {
                            key_valid = MMI_TRUE;
                        }
                    }
                #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
                }
                break;
            }

            if(MMI_TRUE == key_valid)
            {
                g_phoedt_cui_cntx_p->key_cntx.is_key_down = MMI_TRUE;
                g_phoedt_cui_cntx_p->key_cntx.key_code = key_code;
                cui_phoedt_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
        }
        break;

    case KEY_EVENT_UP:
        {
            cui_phoedt_reset_interact_item_state();

            switch(g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
            {
            case PHOEDT_CLIP_TYPE_FIX_RATIO:
                {
                    switch(key_code)
                    {
                    case KEY_LEFT_ARROW:
                    case KEY_RIGHT_ARROW:
                    case KEY_UP_ARROW:
                    case KEY_DOWN_ARROW:
                        {
                            gui_cancel_timer(cui_phoedt_clip_move_cyclic);
                        }
                        break;

                #if !defined(__MMI_PHOEDT_STYLE_FTE_CLIP__)
                    case PHOEDT_KEY_MAP_ZOOM_IN:
                        {
                            cui_phoedt_clip_rect_zoom_in();
                        }
                        break;

                    case PHOEDT_KEY_MAP_ZOOM_OUT:
                        {
                            cui_phoedt_clip_rect_zoom_out();
                        }
                        break;
                #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */

                    default:
                        break;
                    }
                }
                break;

            case PHOEDT_CLIP_TYPE_MANUAL_CLIP:
                {
                    switch(key_code)
                    {
                    case KEY_LEFT_ARROW:
                    case KEY_RIGHT_ARROW:
                    case KEY_UP_ARROW:
                    case KEY_DOWN_ARROW:
                        {
                            gui_cancel_timer(cui_phoedt_clip_move_cyclic);
                        }
                        break;

                #if !defined(__MMI_PHOEDT_STYLE_FTE_CLIP__)
                    case PHOEDT_KEY_MAP_MANUAL_CLIP_STATE:
                        {
                            cui_phoedt_clip_switch_state();
                        }
                        break;
                #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */

                    default:
                        break;
                    }
                }
                break;

            default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }

            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_key_hdlr
* DESCRIPTION
*  ecui_phoedt_adjust_key_hdlr
* PARAMETERS
*  key_code         [IN]
*  key_evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_adjust_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    key_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_evt)
    {
    case KEY_EVENT_DOWN:
        {
            switch(key_code)
            {
            case KEY_LEFT_ARROW:
                {
                    key_valid = MMI_TRUE;
                    cui_phoedt_adjust_change_value_left();
                }
                break;

            case KEY_RIGHT_ARROW:
                {
                    key_valid = MMI_TRUE;
                    cui_phoedt_adjust_change_value_right();
                }
                break;

            case KEY_UP_ARROW:
                {
                    key_valid = MMI_TRUE;
                    cui_phoedt_adjust_switch_item(PHOEDT_SWITCH_DIR_PREV);
                }
                break;

            case KEY_DOWN_ARROW:
                {
                    key_valid = MMI_TRUE;
                    cui_phoedt_adjust_switch_item(PHOEDT_SWITCH_DIR_NEXT);
                }
                break;

            default:
                break;
            }

            if(MMI_TRUE == key_valid)
            {
                g_phoedt_cui_cntx_p->key_cntx.is_key_down = MMI_TRUE;
                g_phoedt_cui_cntx_p->key_cntx.key_code = key_code;
                cui_phoedt_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
        }
        break;

    case KEY_EVENT_UP:
        {
            cui_phoedt_reset_interact_item_state();
            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_effect_key_hdlr
* DESCRIPTION
*  cui_phoedt_effect_key_hdlr
* PARAMETERS
*  key_code         [IN]
*  key_evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_effect_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    key_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_evt)
    {
    case KEY_EVENT_DOWN:
        {
            switch(key_code)
            {
            case KEY_LEFT_ARROW:
            case KEY_RIGHT_ARROW:
                {
                    key_valid = MMI_TRUE;
                }
                break;

            default:
                break;
            }

            if(MMI_TRUE == key_valid)
            {
                g_phoedt_cui_cntx_p->key_cntx.is_key_down = MMI_TRUE;
                g_phoedt_cui_cntx_p->key_cntx.key_code = key_code;
                cui_phoedt_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
        }
        break;

    case KEY_EVENT_UP:
        {
            cui_phoedt_reset_interact_item_state();

            switch(key_code)
            {
            case KEY_LEFT_ARROW:
                {
                    cui_phoedt_effect_switch(PHOEDT_SWITCH_DIR_PREV);
                }
                break;

            case KEY_RIGHT_ARROW:
                {
                    cui_phoedt_effect_switch(PHOEDT_SWITCH_DIR_NEXT);
                }
                break;

            default:
                break;
            }

            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_icon_key_hdlr
* DESCRIPTION
*  cui_phoedt_icon_key_hdlr
* PARAMETERS
*  key_code         [IN]
*  key_evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_icon_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    key_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_evt)
    {
    case KEY_EVENT_DOWN:
        {
            switch(key_code)
            {
            case KEY_LEFT_ARROW:
                {
                    cui_phoedt_icon_move_icon(PHOEDT_MOVE_DIR_LEFT);
                }
                break;

            case KEY_RIGHT_ARROW:
                {
                    cui_phoedt_icon_move_icon(PHOEDT_MOVE_DIR_RIGHT);
                }
                break;

            case KEY_UP_ARROW:
                {
                    cui_phoedt_icon_move_icon(PHOEDT_MOVE_DIR_UP);
                }
                break;

            case KEY_DOWN_ARROW:
                {
                    cui_phoedt_icon_move_icon(PHOEDT_MOVE_DIR_DOWN);
                }
                break;

            default:
                {
                    if(PHOEDT_KEY_MAP_ZOOM_IN == key_code ||
                       PHOEDT_KEY_MAP_ZOOM_OUT == key_code ||
                       PHOEDT_KEY_MAP_ICON_ROTATE == key_code)
                    {
                        key_valid = MMI_TRUE;
                    }
                }
                break;
            }

            if(MMI_TRUE == key_valid)
            {
                g_phoedt_cui_cntx_p->key_cntx.is_key_down = MMI_TRUE;
                g_phoedt_cui_cntx_p->key_cntx.key_code = key_code;
                cui_phoedt_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
        }
        break;

    case KEY_EVENT_UP:
        {
            cui_phoedt_reset_interact_item_state();

            switch(key_code)
            {
            case KEY_LEFT_ARROW:
            case KEY_RIGHT_ARROW:
            case KEY_UP_ARROW:
            case KEY_DOWN_ARROW:
                {
                    gui_cancel_timer(cui_phoedt_icon_move_cyclic);
                }
                break;

            case PHOEDT_KEY_MAP_ZOOM_IN:
                {
                    cui_phoedt_icon_zoom_in();
                }
                break;

            case PHOEDT_KEY_MAP_ZOOM_OUT:
                {
                    cui_phoedt_icon_zoom_out();
                }
                break;

            case PHOEDT_KEY_MAP_ICON_ROTATE:
                {
                    cui_phoedt_icon_rotate();
                }
                break;

            default:
                break;
            }

            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_frame_key_hdlr
* DESCRIPTION
*  cui_phoedt_frame_key_hdlr
* PARAMETERS
*  key_code         [IN]
*  key_evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_frame_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    key_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_evt)
    {
    case KEY_EVENT_DOWN:
        {
            switch(key_code)
            {
            case KEY_LEFT_ARROW:
            case KEY_RIGHT_ARROW:
                {
                    key_valid = MMI_TRUE;
                }
                break;

            default:
                break;
            }

            if(MMI_TRUE == key_valid)
            {
                g_phoedt_cui_cntx_p->key_cntx.is_key_down = MMI_TRUE;
                g_phoedt_cui_cntx_p->key_cntx.key_code = key_code;
                cui_phoedt_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
        }
        break;

    case KEY_EVENT_UP:
        {
            cui_phoedt_reset_interact_item_state();

            switch(key_code)
            {
            case KEY_LEFT_ARROW:
                {
                    cui_phoedt_frame_switch(PHOEDT_SWITCH_DIR_PREV);
                }
                break;

            case KEY_RIGHT_ARROW:
                {
                    cui_phoedt_frame_switch(PHOEDT_SWITCH_DIR_NEXT);
                }
                break;

            default:
                break;
            }

            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_flip_key_hdlr
* DESCRIPTION
*  cui_phoedt_flip_key_hdlr
* PARAMETERS
*  key_code         [IN]
*  key_evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_flip_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    key_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_evt)
    {
    case KEY_EVENT_DOWN:
        {
            switch(key_code)
            {
            default:
                {
                    if(PHOEDT_KEY_MAP_FLIP_HORZ_1 == key_code ||
                       PHOEDT_KEY_MAP_FLIP_HORZ_2 == key_code ||
                       PHOEDT_KEY_MAP_FLIP_VERT_1 == key_code ||
                       PHOEDT_KEY_MAP_FLIP_VERT_2 == key_code)
                    {
                        key_valid = MMI_TRUE;
                    }
                }
                break;
            }

            if(MMI_TRUE == key_valid)
            {
                g_phoedt_cui_cntx_p->key_cntx.is_key_down = MMI_TRUE;
                g_phoedt_cui_cntx_p->key_cntx.key_code = key_code;
                cui_phoedt_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
        }
        break;

    case KEY_EVENT_UP:
        {
            cui_phoedt_reset_interact_item_state();

            switch(key_code)
            {
            case PHOEDT_KEY_MAP_FLIP_HORZ_1:
            case PHOEDT_KEY_MAP_FLIP_HORZ_2:
                {
                    cui_phoedt_flip(PHOEDT_FLIP_DIR_HORI);
                }
                break;

            case PHOEDT_KEY_MAP_FLIP_VERT_1:
            case PHOEDT_KEY_MAP_FLIP_VERT_2:
                {
                    cui_phoedt_flip(PHOEDT_FLIP_DIR_VERT);
                }
                break;

            default:
                break;
            }

            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_rotate_key_hdlr
* DESCRIPTION
*  cui_phoedt_rotate_key_hdlr
* PARAMETERS
*  key_code         [IN]
*  key_evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_rotate_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    key_valid = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_evt)
    {
    case KEY_EVENT_DOWN:
        {
            switch(key_code)
            {
            default:
                {
                    if(PHOEDT_KEY_MAP_ROTATE_CCW == key_code ||
                       PHOEDT_KEY_MAP_ROTATE_CW == key_code)
                    {
                        key_valid = MMI_TRUE;
                    }
                }
                break;
            }

            if(MMI_TRUE == key_valid)
            {
                g_phoedt_cui_cntx_p->key_cntx.is_key_down = MMI_TRUE;
                g_phoedt_cui_cntx_p->key_cntx.key_code = key_code;
                cui_phoedt_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
        }
        break;

    case KEY_EVENT_UP:
        {
            cui_phoedt_reset_interact_item_state();

            switch(key_code)
            {
            case PHOEDT_KEY_MAP_ROTATE_CCW:
                {
                    cui_phoedt_rotate(PHOEDT_ROTATE_DIR_CCW);
                }
                break;

            case PHOEDT_KEY_MAP_ROTATE_CW:
                {
                    cui_phoedt_rotate(PHOEDT_ROTATE_DIR_CW);
                }
                break;

            default:
                break;
            }

            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        break;

    default:
        break;
    }
}


#ifdef __MMI_PHOEDT_DOODLE__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_key_hdlr
* DESCRIPTION
*  cui_phoedt_doodle_key_hdlr
* PARAMETERS
*  key_code         [IN]
*  key_evt          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_doodle_key_hdlr(mmi_keypads_enum key_code, mmi_key_types_enum key_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_PHOEDT_DOODLE__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_set_pen_hdlrs
* DESCRIPTION
*  set pen hdlrs
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_set_pen_hdlrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(cui_phoedt_pen_down_hdlr);
    wgui_register_pen_up_handler(cui_phoedt_pen_up_hdlr);
    wgui_register_pen_move_handler(cui_phoedt_pen_move_hdlr);
    wgui_register_pen_abort_handler(cui_phoedt_pen_abort_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_pen_down_hdlr
* DESCRIPTION
*  pen down hdlr
* PARAMETERS
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_touch_item_enum      obj         = cui_phoedt_get_pen_on_obj(pos);
    MMI_BOOL                    pen_on_sk   = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(MMI_FALSE == g_phoedt_cui_cntx_p->touch_cntx.is_pen_down);

    switch(obj)
    {
    case PHOEDT_TOUCH_ITEM_LSK:
    case PHOEDT_TOUCH_ITEM_RSK:
    case PHOEDT_TOUCH_ITEM_CSK:
        {
            pen_on_sk = MMI_TRUE;
            g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
            g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
    }

    if(MMI_FALSE == pen_on_sk && PHOEDT_TOUCH_ITEM_NONE != obj)
    {
        if (NULL != g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].pen_hdlr)
            g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].pen_hdlr(PHOEDT_PEN_EVENT_DOWN, obj, pos);
        else
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_pen_up_hdlr
* DESCRIPTION
*  pen up hdlr
* PARAMETERS
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_touch_item_enum      obj         = cui_phoedt_get_pen_on_obj(pos);
    MMI_BOOL                    pen_on_sk   = MMI_FALSE;
    MMI_BOOL                    is_apply    = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj) &&
       PHOEDT_ACTION_TYPE_NONE != g_phoedt_cui_cntx_p->curr_act.action && 
       PHOEDT_ACTION_TYPE_LOADING != g_phoedt_cui_cntx_p->curr_act.action)
    {
        switch(obj)
        {
        case PHOEDT_TOUCH_ITEM_LSK:
            {
                pen_on_sk = MMI_TRUE;
                is_apply = MMI_TRUE;
            }
            break;

        case PHOEDT_TOUCH_ITEM_RSK:
            {
                pen_on_sk = MMI_TRUE;
                is_apply = MMI_FALSE;
            }
            break;

        case PHOEDT_TOUCH_ITEM_CSK:
            {
                pen_on_sk = MMI_TRUE;
                is_apply = MMI_TRUE;
            }
            break;
        }

        if(MMI_TRUE == pen_on_sk)
        {
            cui_phoedt_reset_interact_item_state();
            cui_phoedt_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            cui_phoedt_end_curr_change(is_apply);
        }
    }

    if(MMI_FALSE == pen_on_sk)
    {
        if (NULL != g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].pen_hdlr)
            g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].pen_hdlr(PHOEDT_PEN_EVENT_UP, obj, pos);
        else
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_pen_move_hdlr
* DESCRIPTION
*  pen move hdlr
* PARAMETERS
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_touch_item_enum      obj         = cui_phoedt_get_pen_on_obj(pos);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE == g_phoedt_cui_cntx_p->touch_cntx.is_pen_down)
    {
        /* must have a pen down event */
        return;
    }

    if (NULL != g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].pen_hdlr)
        g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].pen_hdlr(PHOEDT_PEN_EVENT_MOVE, obj, pos);
    else
        MMI_ASSERT(0);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_pen_abort_hdlr
* DESCRIPTION
*  pen abort hdlr
* PARAMETERS
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_pen_abort_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_reset_interact_item_state();
    cui_phoedt_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_main_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            update          = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_UP:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                cui_phoedt_reset_interact_item_state();

                /* must update osd before run the function to shown the release effect of softkey */
                cui_phoedt_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_LSK:
                    {
                        cui_phoedt_entry_main_option_screen();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_RSK:
                    {
                        cui_phoedt_exit();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_CSK:
                    {
                        cui_phoedt_entry_folder_selector_screen();
                        g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_SAVE_FILE;
                        g_phoedt_cui_cntx_p->curr_act.para.save.output_size = g_phoedt_cui_cntx_p->image_info.curr_size;
                    }
                    break;
                }
            }
            else
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_FALSE == cui_phoedt_is_touch_item_pressed(obj))
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    if(MMI_TRUE == update)
    {
        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_pen_hdlr
* DESCRIPTION
*  FTE ONLY:
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_clip_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            is_move         = MMI_FALSE;
    MMI_BOOL            update          = MMI_FALSE;
    phoedt_rect_struct  available_rect;
    phoedt_rect_struct  *clip_rect;
    phoedt_pos_struct   curr_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    available_rect  = g_phoedt_cui_cntx_p->display_info.img_rect;
    clip_rect      = &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect;

    curr_pos.x = pos.x;
    curr_pos.y = pos.y;

    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            switch(obj)
            {
            case PHOEDT_TOUCH_ITEM_CLIP_RECT:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                }
                break;

            case PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP:
            case PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN:
            case PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN:
            case PHOEDT_TOUCH_ITEM_CLIP_LEFTUP:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                    update = MMI_TRUE;
                }
                break;

            default:
                break;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_CLIP_LEFTUP:
                case PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN:
                case PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP:
                case PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN:
                    {
                        cui_phoedt_change_clip_rect_in_an_area_by_points(
                            obj, available_rect, clip_rect,
                            g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_CLIP_RECT:
                    {
                        is_move = MMI_TRUE;
                    }
                    break;

                default:
                    break;
                }
            }

            cui_phoedt_reset_interact_item_state();
            update = MMI_TRUE;
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RECT))
            {
                wgui_component_info_struct  cop;
                cop.pos_x = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x;
                cop.pos_y = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y;
                cop.width = g_phoedt_cui_cntx_p->display_info.img_rect.size.w;
                cop.height = g_phoedt_cui_cntx_p->display_info.img_rect.size.h;
                if(MMI_TRUE == wgui_test_object_position(pos, cop))
                {
                    is_move = MMI_TRUE;
                    update = MMI_TRUE;
                }
                else
                {
                    cui_phoedt_reset_interact_item_state();
                    update = MMI_TRUE;
                }
            }
            else if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTUP) ||
                    MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN) ||
                    MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP) ||
                    MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN))
            {
                wgui_component_info_struct cop;

                cui_phoedt_change_clip_rect_in_an_area_by_points(
                    g_phoedt_cui_cntx_p->touch_cntx.obj, available_rect, clip_rect,
                    g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);

                update = MMI_TRUE;

                cop.pos_x = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x -
                    ((g_phoedt_layout.clip_indicator_sel_size.w + 1) >> 1);
                cop.pos_y = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y -
                    ((g_phoedt_layout.clip_indicator_sel_size.h + 1) >> 1);
                cop.width = g_phoedt_cui_cntx_p->display_info.img_rect.size.w +
                    g_phoedt_layout.clip_indicator_sel_size.w;
                cop.height = g_phoedt_cui_cntx_p->display_info.img_rect.size.h +
                    g_phoedt_layout.clip_indicator_sel_size.h;
                if(MMI_FALSE == wgui_test_object_position(pos, cop))
                {
                    cui_phoedt_reset_interact_item_state();
                }
            }
            else
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    if(MMI_TRUE == is_move)
    {
        cui_phoedt_move_rect_in_an_area_by_points(
            available_rect, clip_rect,
            g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);
    }

    g_phoedt_cui_cntx_p->touch_cntx.last_pos = curr_pos;

    if(MMI_TRUE == update)
    {
        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


#else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_pen_hdlr
* DESCRIPTION
*
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_clip_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            is_move         = MMI_FALSE;
    MMI_BOOL            update          = MMI_FALSE;
    phoedt_rect_struct  available_rect;
    phoedt_rect_struct  *clip_rect;
    phoedt_pos_struct   curr_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    available_rect  = g_phoedt_cui_cntx_p->display_info.img_rect;
    clip_rect       = &g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect;

    curr_pos.x = pos.x;
    curr_pos.y = pos.y;

    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            switch(obj)
            {
            case PHOEDT_TOUCH_ITEM_CLIP_ZOOMIN:
            case PHOEDT_TOUCH_ITEM_CLIP_ZOOMOUT:
            case PHOEDT_TOUCH_ITEM_CLIP_STATE_ICON:
            case PHOEDT_TOUCH_ITEM_CLIP_RECT:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                    update = MMI_TRUE;
                }
                break;

            case PHOEDT_TOUCH_ITEM_CLIP_RIGHT:
            case PHOEDT_TOUCH_ITEM_CLIP_DOWN:
            case PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN:
            case PHOEDT_TOUCH_ITEM_CLIP_LEFT:
            case PHOEDT_TOUCH_ITEM_CLIP_UP:
            case PHOEDT_TOUCH_ITEM_CLIP_LEFTUP:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                }
                break;

            default:
                break;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_CLIP_ZOOMIN:
                    {
                        cui_phoedt_clip_rect_zoom_in();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_CLIP_ZOOMOUT:
                    {
                        cui_phoedt_clip_rect_zoom_out();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_CLIP_STATE_ICON:
                    {
                        cui_phoedt_clip_switch_state();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_CLIP_RIGHT:
                case PHOEDT_TOUCH_ITEM_CLIP_DOWN:
                case PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN:
                case PHOEDT_TOUCH_ITEM_CLIP_LEFT:
                case PHOEDT_TOUCH_ITEM_CLIP_UP:
                case PHOEDT_TOUCH_ITEM_CLIP_LEFTUP:
                    {
                        cui_phoedt_change_clip_rect_in_an_area_by_points(
                            obj, available_rect, clip_rect,
                            g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_CLIP_RECT:
                    {
                        is_move = MMI_TRUE;
                    }
                    break;

                default:
                    break;
                }
            }

            cui_phoedt_reset_interact_item_state();
            update = MMI_TRUE;
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RECT))
            {
                wgui_component_info_struct  cop;
                cop.pos_x = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x;
                cop.pos_y = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y;
                cop.width = g_phoedt_cui_cntx_p->display_info.img_rect.size.w;
                cop.height = g_phoedt_cui_cntx_p->display_info.img_rect.size.h;
                if(MMI_TRUE == wgui_test_object_position(pos, cop))
                {
                    is_move = MMI_TRUE;
                    update = MMI_TRUE;
                }
                else
                {
                    cui_phoedt_reset_interact_item_state();
                    update = MMI_TRUE;
                }
            }
            else if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHT) ||
                    MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_DOWN) ||
                    MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN) ||
                    MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFT) ||
                    MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_UP) ||
                    MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTUP))
            {
                wgui_component_info_struct cop;

                cui_phoedt_change_clip_rect_in_an_area_by_points(
                    g_phoedt_cui_cntx_p->touch_cntx.obj, available_rect, clip_rect,
                    g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);

                update = MMI_TRUE;

                cop.pos_x = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x;
                cop.pos_y = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y;
                cop.width = g_phoedt_cui_cntx_p->display_info.img_rect.size.w;
                cop.height = g_phoedt_cui_cntx_p->display_info.img_rect.size.h;
                if(MMI_FALSE == wgui_test_object_position(pos, cop))
                {
                    cui_phoedt_reset_interact_item_state();
                }
            }
            else
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    if(MMI_TRUE == is_move)
    {
        cui_phoedt_move_rect_in_an_area_by_points(
            available_rect, clip_rect,
            g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);
    }

    g_phoedt_cui_cntx_p->touch_cntx.last_pos = curr_pos;

    if(MMI_TRUE == update)
    {
        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_effect_pen_hdlr
* DESCRIPTION
*
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_effect_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            update          = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            switch(obj)
            {
            case PHOEDT_TOUCH_ITEM_PREV:
            case PHOEDT_TOUCH_ITEM_NEXT:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                    update = MMI_TRUE;
                }
                break;

            default:
                break;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_PREV:
                    {
                        cui_phoedt_effect_switch(PHOEDT_SWITCH_DIR_PREV);
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_NEXT:
                    {
                        cui_phoedt_effect_switch(PHOEDT_SWITCH_DIR_NEXT);
                    }
                    break;

                default:
                    break;
                }
            }

            cui_phoedt_reset_interact_item_state();
            update = MMI_TRUE;
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_FALSE == cui_phoedt_is_touch_item_pressed(obj))
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    if(MMI_TRUE == update)
    {
        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_pen_hdlr
* DESCRIPTION
*
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_adjust_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            update          = MMI_FALSE;
    phoedt_pos_struct   curr_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_pos.x = pos.x;
    curr_pos.y = pos.y;

    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            if(PHOEDT_TOUCH_ITEM_ADJUST_ICON <= obj && PHOEDT_TOUCH_ITEM_ADJUST_ICON_END > obj)
            {
                cui_phoedt_adjust_select_item(obj - PHOEDT_TOUCH_ITEM_ADJUST_ICON);
                update = MMI_TRUE;
            }
            else
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_ADJUST_BAR:
                    {
                        g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                        g_phoedt_cui_cntx_p->touch_cntx.obj = PHOEDT_TOUCH_ITEM_ADJUST_SLIDER;
                        cui_phoedt_adjust_set_value_by_pos(curr_pos);
                        update = MMI_TRUE;
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_ADJUST_SLIDER:
                    {
                        g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                        g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                        update = MMI_TRUE;
                    }
                    break;

                default:
                    break;
                }
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_ADJUST_BAR:
                    {
                        cui_phoedt_adjust_set_value_by_pos(curr_pos);
                    }
                    break;

                default:
                    break;
                }
            }

            cui_phoedt_reset_interact_item_state();
            update = MMI_TRUE;
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ADJUST_SLIDER))
            {
                cui_phoedt_adjust_set_value_by_pos(curr_pos);
                update = MMI_TRUE;
            }
            else
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    if(MMI_TRUE == update)
    {
        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_icon_pen_hdlr
* DESCRIPTION
*
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_icon_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL                update          = MMI_FALSE;
    MMI_BOOL                preview         = MMI_FALSE;
    phoedt_rect_struct      available_rect;
    phoedt_rect_struct      icon_rect;
    phoedt_pos_struct       curr_pos;
    phoedt_pos_struct       last_pos;
    srv_ies_result          ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_pos.x = pos.x;
    curr_pos.y = pos.y;

    last_pos.x = g_phoedt_cui_cntx_p->touch_cntx.last_pos.x;
    last_pos.y = g_phoedt_cui_cntx_p->touch_cntx.last_pos.y;

    available_rect = g_phoedt_cui_cntx_p->display_info.img_rect;

    icon_rect.offset = g_phoedt_cui_cntx_p->curr_act.para.icon.location;
    icon_rect.size.w = g_phoedt_cui_cntx_p->curr_act.para.icon.size;
    icon_rect.size.h = icon_rect.size.w;

    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            switch(obj)
            {
            case PHOEDT_TOUCH_ITEM_ICON_ICON:
            case PHOEDT_TOUCH_ITEM_ICON_ROTATE:
            case PHOEDT_TOUCH_ITEM_ICON_ZOOMIN:
            case PHOEDT_TOUCH_ITEM_ICON_ZOOMOUT:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                    update = MMI_TRUE;
                }
                break;

            default:
                break;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_ICON_ROTATE:
                    {
                        cui_phoedt_icon_rotate();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_ICON_ZOOMIN:
                    {
                        cui_phoedt_icon_zoom_in();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_ICON_ZOOMOUT:
                    {
                        cui_phoedt_icon_zoom_out();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_ICON_ICON:
                    {
                        cui_phoedt_move_rect_in_an_area_by_points(
                            available_rect, &icon_rect, last_pos, curr_pos);

                        g_phoedt_cui_cntx_p->curr_act.para.icon.location.x = icon_rect.offset.x;
                        g_phoedt_cui_cntx_p->curr_act.para.icon.location.y = icon_rect.offset.y;

                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ICON_ADJUST_POS,
                            g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx,
                            g_phoedt_cui_cntx_p->curr_act.para.icon.location.x,
                            g_phoedt_cui_cntx_p->curr_act.para.icon.location.y,
                            PHOEDT_ICON_CENTER_X_ON_IMG, PHOEDT_ICON_CENTER_Y_ON_IMG);

                        ies_ret = srv_ies_icon_adjust_pos(
                            g_phoedt_cui_cntx_p->ies_hdles.img,
                            PHOEDT_ICON_CENTER_X_ON_IMG,
                            PHOEDT_ICON_CENTER_Y_ON_IMG);

                        if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
                        {
                            preview = MMI_TRUE;
                        }
                        else
                        {
                            cui_phoedt_cancel_curr_change();
                            cui_phoedt_close_edit_group();
                        }
                    }
                    break;

                default:
                    break;
                }
            }

            cui_phoedt_reset_interact_item_state();
            update = MMI_TRUE;
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ICON_ICON))
            {
                wgui_component_info_struct cop;
                cop.pos_x = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x;
                cop.pos_y = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y;
                cop.width = g_phoedt_cui_cntx_p->display_info.img_rect.size.w;
                cop.height = g_phoedt_cui_cntx_p->display_info.img_rect.size.h;
                if(MMI_FALSE == wgui_test_object_position(pos, cop))
                {
                    cui_phoedt_reset_interact_item_state();
                    update = MMI_TRUE;
                }
                else
                {
                    cui_phoedt_move_rect_in_an_area_by_points(
                        available_rect, &icon_rect, last_pos, curr_pos);

                    g_phoedt_cui_cntx_p->curr_act.para.icon.location.x = icon_rect.offset.x;
                    g_phoedt_cui_cntx_p->curr_act.para.icon.location.y = icon_rect.offset.y;

                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ICON_ADJUST_POS,
                        g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx,
                        g_phoedt_cui_cntx_p->curr_act.para.icon.location.x,
                        g_phoedt_cui_cntx_p->curr_act.para.icon.location.y,
                        PHOEDT_ICON_CENTER_X_ON_IMG, PHOEDT_ICON_CENTER_Y_ON_IMG);

                    ies_ret = srv_ies_icon_adjust_pos(
                        g_phoedt_cui_cntx_p->ies_hdles.img,
                        PHOEDT_ICON_CENTER_X_ON_IMG,
                        PHOEDT_ICON_CENTER_Y_ON_IMG);

                    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
                    {
                        preview = MMI_TRUE;
                        update = MMI_TRUE;
                    }
                    else
                    {
                        cui_phoedt_cancel_curr_change();
                        cui_phoedt_close_edit_group();
                    }
                }
            }
            else if(MMI_FALSE == cui_phoedt_is_touch_item_pressed(obj))
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    g_phoedt_cui_cntx_p->touch_cntx.last_pos.x = pos.x;
    g_phoedt_cui_cntx_p->touch_cntx.last_pos.y = pos.y;

    if(MMI_TRUE == preview || MMI_TRUE == update)
    {
        if(MMI_TRUE == preview)
        {
            cui_phoedt_preview_image(MMI_FALSE);
        }

        if(MMI_TRUE == update)
        {
            cui_phoedt_draw_osd();
        }

        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_frame_pen_hdlr
* DESCRIPTION
*
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_frame_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            update          = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            switch(obj)
            {
            case PHOEDT_TOUCH_ITEM_PREV:
            case PHOEDT_TOUCH_ITEM_NEXT:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                    update = MMI_TRUE;
                }
                break;

            default:
                break;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_PREV:
                    {
                        cui_phoedt_frame_switch(PHOEDT_SWITCH_DIR_PREV);
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_NEXT:
                    {
                        cui_phoedt_frame_switch(PHOEDT_SWITCH_DIR_NEXT);
                    }
                    break;

                default:
                    break;
                }
            }

            cui_phoedt_reset_interact_item_state();
            update = MMI_TRUE;
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_FALSE == cui_phoedt_is_touch_item_pressed(obj))
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    if(MMI_TRUE == update)
    {
        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_flip_pen_hdlr
* DESCRIPTION
*
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_flip_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            update          = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            switch(obj)
            {
            case PHOEDT_TOUCH_ITEM_FLIP_HORZ:
            case PHOEDT_TOUCH_ITEM_FLIP_VERT:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                    update = MMI_TRUE;
                }
                break;

            default:
                break;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_FLIP_HORZ:
                    {
                        cui_phoedt_flip(PHOEDT_FLIP_DIR_HORI);
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_FLIP_VERT:
                    {
                        cui_phoedt_flip(PHOEDT_FLIP_DIR_VERT);
                    }
                    break;

                default:
                    break;
                }
            }

            cui_phoedt_reset_interact_item_state();
            update = MMI_TRUE;
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_FALSE == cui_phoedt_is_touch_item_pressed(obj))
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    if(MMI_TRUE == update)
    {
        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_rotate_pen_hdlr
* DESCRIPTION
*
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_rotate_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            update          = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            switch(obj)
            {
            case PHOEDT_TOUCH_ITEM_ROTATE_CCW:
            case PHOEDT_TOUCH_ITEM_ROTATE_CW:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                    update = MMI_TRUE;
                }
                break;

            default:
                break;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_ROTATE_CCW:
                    {
                        cui_phoedt_rotate(PHOEDT_ROTATE_DIR_CCW);
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_ROTATE_CW:
                    {
                        cui_phoedt_rotate(PHOEDT_ROTATE_DIR_CW);
                    }
                    break;

                default:
                    break;
                }
            }

            cui_phoedt_reset_interact_item_state();
            update = MMI_TRUE;
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_FALSE == cui_phoedt_is_touch_item_pressed(obj))
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    if(MMI_TRUE == update)
    {
        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
}


#ifdef __MMI_PHOEDT_DOODLE__
#ifdef __MMI_PHOEDT_STYLE_FTE__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_pen_hdlr
* DESCRIPTION
*  FTE ONLY:
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_doodle_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            update              = MMI_FALSE;
    MMI_BOOL            preview             = MMI_FALSE;
    phoedt_pos_struct   curr_pos;
    phoedt_pos_struct   blt_left_top;
    phoedt_pos_struct   blt_right_bottom;
    MMI_BOOL            skip_doodle_point   = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    blt_left_top.x = 0;
    blt_left_top.y = 0;

    blt_right_bottom.x = UI_device_width - 1;
    blt_right_bottom.y = UI_device_height - 1;

    curr_pos.x = pos.x;
    curr_pos.y = pos.y;

    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            switch(obj)
            {
            case PHOEDT_TOUCH_ITEM_DOODLE_HIDE:
            case PHOEDT_TOUCH_ITEM_DOODLE_LINE_1:
            case PHOEDT_TOUCH_ITEM_DOODLE_LINE_2:
            case PHOEDT_TOUCH_ITEM_DOODLE_LINE_3:
            case PHOEDT_TOUCH_ITEM_DOODLE_ERASER_1:
            case PHOEDT_TOUCH_ITEM_DOODLE_ERASER_2:
            case PHOEDT_TOUCH_ITEM_DOODLE_ERASER_3:
            case PHOEDT_TOUCH_ITEM_DOODLE_COLOR:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                    update = MMI_TRUE;
                }
                break;

            case PHOEDT_TOUCH_ITEM_DOODLE_DOODLE:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                }
                break;

            default:
                break;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            update = MMI_TRUE;
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_DOODLE_HIDE:
                    {
                        cui_phoedt_doodle_switch_hide();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_DOODLE_LINE_1:
                case PHOEDT_TOUCH_ITEM_DOODLE_LINE_2:
                case PHOEDT_TOUCH_ITEM_DOODLE_LINE_3:
                    {
                        cui_phoedt_doodle_switch_line_size((phoedt_doodle_size_enum)(obj - PHOEDT_TOUCH_ITEM_DOODLE_LINE_1));
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_DOODLE_ERASER_1:
                case PHOEDT_TOUCH_ITEM_DOODLE_ERASER_2:
                case PHOEDT_TOUCH_ITEM_DOODLE_ERASER_3:
                    {
                        cui_phoedt_doodle_switch_eraser_size((phoedt_doodle_size_enum)(obj - PHOEDT_TOUCH_ITEM_DOODLE_ERASER_1));
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_DOODLE_COLOR:
                    {
                        /* draw osd to show the button release effect */
                        cui_phoedt_draw_osd();
                        gdi_layer_blt_previous(blt_left_top.x, blt_left_top.y, blt_right_bottom.x, blt_right_bottom.y);

                        cui_phoedt_entry_matrix_selector_screen();
                        update = MMI_FALSE;
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_DOODLE_DOODLE:
                    {
                        cui_phoedt_doodle_draw_doodle(g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);
                        blt_left_top.x = min(g_phoedt_cui_cntx_p->touch_cntx.last_pos.x, curr_pos.x) - PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_left_top.y = min(g_phoedt_cui_cntx_p->touch_cntx.last_pos.y, curr_pos.y) - PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_right_bottom.x = max(g_phoedt_cui_cntx_p->touch_cntx.last_pos.x, curr_pos.x) + PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_right_bottom.y = max(g_phoedt_cui_cntx_p->touch_cntx.last_pos.y, curr_pos.y) + PHOEDT_DOODLE_UPDATE_RADIUS;
                        preview = MMI_TRUE;
                    }
                    break;

                default:
                    break;
                }
            }
            cui_phoedt_reset_interact_item_state();
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_DOODLE_DOODLE:
                    {
                        cui_phoedt_doodle_draw_doodle(g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);
                        blt_left_top.x = min(g_phoedt_cui_cntx_p->touch_cntx.last_pos.x, curr_pos.x) - PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_left_top.y = min(g_phoedt_cui_cntx_p->touch_cntx.last_pos.y, curr_pos.y) - PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_right_bottom.x = max(g_phoedt_cui_cntx_p->touch_cntx.last_pos.x, curr_pos.x) + PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_right_bottom.y = max(g_phoedt_cui_cntx_p->touch_cntx.last_pos.y, curr_pos.y) + PHOEDT_DOODLE_UPDATE_RADIUS;
                        preview = MMI_TRUE;
                        update = MMI_TRUE;
                    }
                    break;

                default:
                    break;
                }
            }
            else if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_DOODLE_DOODLE) && PHOEDT_TOUCH_ITEM_NONE == obj)
            {
                /* skip this point and keep on doodle */
                skip_doodle_point = MMI_TRUE;
            }
            else
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    if(MMI_FALSE == skip_doodle_point)
    {
        g_phoedt_cui_cntx_p->touch_cntx.last_pos.x = pos.x;
        g_phoedt_cui_cntx_p->touch_cntx.last_pos.y = pos.y;
    }

    if(MMI_TRUE == preview || MMI_TRUE == update)
    {
        if(MMI_TRUE == preview)
        {
            cui_phoedt_preview_image(MMI_FALSE);
        }

        if(MMI_TRUE == update)
        {
            cui_phoedt_draw_osd();
        }

        gdi_layer_blt_previous(blt_left_top.x, blt_left_top.y, blt_right_bottom.x, blt_right_bottom.y);
    }
}


#else /* __MMI_PHOEDT_STYLE_FTE__ */
/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_pen_hdlr
* DESCRIPTION
*
* PARAMETERS
*  pen_evt      [IN]
*  obj          [IN]
*  pos          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_doodle_pen_hdlr(phoedt_pen_event_enum pen_evt, phoedt_touch_item_enum obj, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            update          = MMI_FALSE;
    MMI_BOOL            preview         = MMI_FALSE;
    phoedt_pos_struct   curr_pos;
    phoedt_pos_struct   blt_left_top;
    phoedt_pos_struct   blt_right_bottom;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    blt_left_top.x = 0;
    blt_left_top.y = 0;

    blt_right_bottom.x = UI_device_width - 1;
    blt_right_bottom.y = UI_device_height - 1;

    curr_pos.x = pos.x;
    curr_pos.y = pos.y;

    switch(pen_evt)
    {
    case PHOEDT_PEN_EVENT_DOWN:
        {
            switch(obj)
            {
            case PHOEDT_TOUCH_ITEM_DOODLE_HIDE:
            case PHOEDT_TOUCH_ITEM_DOODLE_TYPE:
            case PHOEDT_TOUCH_ITEM_DOODLE_SIZE:
            case PHOEDT_TOUCH_ITEM_DOODLE_COLOR:
            case PHOEDT_TOUCH_ITEM_DOODLE_DOODLE:
                {
                    g_phoedt_cui_cntx_p->touch_cntx.is_pen_down = MMI_TRUE;
                    g_phoedt_cui_cntx_p->touch_cntx.obj = obj;
                }
                break;

            default:
                break;
            }
        }
        break;

    case PHOEDT_PEN_EVENT_UP:
        {
            update = MMI_TRUE;
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_DOODLE_HIDE:
                    {
                        cui_phoedt_doodle_switch_hide();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_DOODLE_TYPE:
                    {
                        cui_phoedt_doodle_switch_type();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_DOODLE_SIZE:
                    {
                        cui_phoedt_doodle_switch_size();
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_DOODLE_COLOR:
                    {
                        cui_phoedt_entry_matrix_selector_screen();
                        update = MMI_FALSE;
                    }
                    break;

                case PHOEDT_TOUCH_ITEM_DOODLE_DOODLE:
                    {
                        cui_phoedt_doodle_draw_doodle(g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);
                        blt_left_top.x = min(g_phoedt_cui_cntx_p->touch_cntx.last_pos.x, curr_pos.x) - PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_left_top.y = min(g_phoedt_cui_cntx_p->touch_cntx.last_pos.y, curr_pos.y) - PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_right_bottom.x = max(g_phoedt_cui_cntx_p->touch_cntx.last_pos.x, curr_pos.x) + PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_right_bottom.y = max(g_phoedt_cui_cntx_p->touch_cntx.last_pos.y, curr_pos.y) + PHOEDT_DOODLE_UPDATE_RADIUS;
                        preview = MMI_TRUE;
                        /* no need to redraw osd */
                        update = MMI_FALSE;                        
                    }
                    break;

                default:
                    break;
                }
            }
            cui_phoedt_reset_interact_item_state();
        }
        break;

    case PHOEDT_PEN_EVENT_MOVE:
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(obj))
            {
                switch(obj)
                {
                case PHOEDT_TOUCH_ITEM_DOODLE_DOODLE:
                    {
                        cui_phoedt_doodle_draw_doodle(g_phoedt_cui_cntx_p->touch_cntx.last_pos, curr_pos);
                        blt_left_top.x = min(g_phoedt_cui_cntx_p->touch_cntx.last_pos.x, curr_pos.x) - PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_left_top.y = min(g_phoedt_cui_cntx_p->touch_cntx.last_pos.y, curr_pos.y) - PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_right_bottom.x = max(g_phoedt_cui_cntx_p->touch_cntx.last_pos.x, curr_pos.x) + PHOEDT_DOODLE_UPDATE_RADIUS;
                        blt_right_bottom.y = max(g_phoedt_cui_cntx_p->touch_cntx.last_pos.y, curr_pos.y) + PHOEDT_DOODLE_UPDATE_RADIUS;
                        preview = MMI_TRUE;
                        /* no need to redraw osd */
                    }
                    break;

                default:
                    break;
                }
            }
            else
            {
                cui_phoedt_reset_interact_item_state();
                update = MMI_TRUE;
            }
        }
        break;

    default:
        break;
    }

    g_phoedt_cui_cntx_p->touch_cntx.last_pos.x = pos.x;
    g_phoedt_cui_cntx_p->touch_cntx.last_pos.y = pos.y;

    if(MMI_TRUE == preview || MMI_TRUE == update)
    {
        if(MMI_TRUE == preview)
        {
            cui_phoedt_preview_image(MMI_FALSE);
        }

        if(MMI_TRUE == update)
        {
            cui_phoedt_draw_osd();
        }

        gdi_layer_blt_previous(blt_left_top.x, blt_left_top.y, blt_right_bottom.x, blt_right_bottom.y);
    }
}
#endif /* __MMI_PHOEDT_STYLE_FTE__ */
#endif /* __MMI_PHOEDT_DOODLE__ */
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_move
* DESCRIPTION
*  handle key move event for fix ratio and manual clip screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_clip_move_rect(phoedt_move_direction_enum move_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_move_info_struct     *move_info  = cui_phoedt_get_curr_move_info();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    move_info->step = PHOEDT_MOVE_STEP_MIN;
    move_info->direction = move_direction;

    cui_phoedt_clip_move_cyclic();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_move_cyclic
* DESCRIPTION
*  continuly move the edge or the rect
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_clip_move_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_move_info_struct     *move_info      = cui_phoedt_get_curr_move_info();
    MMI_BOOL                    timer_valid     = MMI_TRUE;
    MMI_BOOL                    is_move         = MMI_FALSE;
    phoedt_rect_struct          clip_rect       = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect;
    phoedt_rect_struct          available_rect  = g_phoedt_cui_cntx_p->display_info.img_rect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
    {
    case PHOEDT_CLIP_TYPE_FIX_RATIO:
        {
            is_move = MMI_TRUE;
        }
        break;

    case PHOEDT_CLIP_TYPE_MANUAL_CLIP:
        {
        #ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
            is_move = MMI_TRUE;
        #else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
            switch(move_info->direction)
            {
            case PHOEDT_MOVE_DIR_LEFT:
            case PHOEDT_MOVE_DIR_RIGHT:
                {
                    switch(g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_state)
                    {
                    case PHOEDT_CLIP_STATE_LEFTUP:
                        {
                            cui_phoedt_change_clip_rect_in_an_area_by_info(
                                PHOEDT_CLIP_RECT_ADJUST_EDGE_LEFT, available_rect, &clip_rect, *move_info);
                        }
                        break;

                    case PHOEDT_CLIP_STATE_RIGHTDOWN:
                        {
                            cui_phoedt_change_clip_rect_in_an_area_by_info(
                                PHOEDT_CLIP_RECT_ADJUST_EDGE_RIGHT, available_rect, &clip_rect, *move_info);
                        }
                        break;

                    case PHOEDT_CLIP_STATE_MOVE:
                        {
                            is_move = MMI_TRUE;
                        }
                        break;

                    default:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                    }
                }
                break;

            case PHOEDT_MOVE_DIR_UP:
            case PHOEDT_MOVE_DIR_DOWN:
                {
                    switch(g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_state)
                    {
                    case PHOEDT_CLIP_STATE_LEFTUP:
                        {
                            cui_phoedt_change_clip_rect_in_an_area_by_info(
                                PHOEDT_CLIP_RECT_ADJUST_EDGE_UP, available_rect, &clip_rect, *move_info);
                        }
                        break;

                    case PHOEDT_CLIP_STATE_RIGHTDOWN:
                        {
                            cui_phoedt_change_clip_rect_in_an_area_by_info(
                                PHOEDT_CLIP_RECT_ADJUST_EDGE_DOWN, available_rect, &clip_rect, *move_info);
                        }
                        break;

                    case PHOEDT_CLIP_STATE_MOVE:
                        {
                            is_move = MMI_TRUE;
                        }
                        break;

                    default:
                        {
                            MMI_ASSERT(0);
                        }
                        break;
                    }
                }
                break;

            default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }
        #endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
        }
        break;

    default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

    if(MMI_TRUE == is_move)
    {
        timer_valid = cui_phoedt_move_rect_in_an_area_by_info(available_rect, &clip_rect, *move_info);
    }

    g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect = clip_rect ;

    cui_phoedt_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    if(MMI_TRUE == timer_valid)
    {
        /* make the move step bigger */
        move_info->step += PHOEDT_MOVE_STEP_DIFF;
        if(move_info->step > PHOEDT_MOVE_STEP_MAX)
        {
            move_info->step = PHOEDT_MOVE_STEP_MAX;
        }

        gui_start_timer(PHOEDT_MOVE_STEP_DURATION, cui_phoedt_clip_move_cyclic);
    }
}


#if !defined(__MMI_PHOEDT_STYLE_FTE_CLIP__)
/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_rect_zoom_in
* DESCRIPTION
*  scale up the clip rect when in fix ratio clip
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_clip_rect_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_rect_struct      clip_o      = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect;
    phoedt_rect_struct      clip_n;
    phoedt_rect_struct      img_rect    = g_phoedt_cui_cntx_p->display_info.img_rect;
    phoedt_size_struct      ratio       = g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(PHOEDT_CLIP_TYPE_FIX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type);
    MMI_ASSERT(PHOEDT_CLIP_RECT_MAX_RATIO >= g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio);

    if(PHOEDT_CLIP_RECT_MAX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio)
    {
        return;
    }

    gdi_image_util_fit_bbox(
        img_rect.size.w, img_rect.size.h, ratio.w, ratio.h,
        &clip_n.offset.x, &clip_n.offset.y, &clip_n.size.w, &clip_n.size.h);

    g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio += PHOEDT_CLIP_RECT_STEP_RATION;

    clip_n.size.w = clip_n.size.w * g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio / 100;
    clip_n.size.h = clip_n.size.h * g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio / 100;

    clip_n.offset.x = clip_o.offset.x - ((clip_n.size.w - clip_o.size.w) >> 1);
    clip_n.offset.y = clip_o.offset.y - ((clip_n.size.h - clip_o.size.h) >> 1);

    if(clip_n.offset.x < img_rect.offset.x)
    {
        clip_n.offset.x = img_rect.offset.x;
    }

    if(clip_n.offset.x + clip_n.size.w > img_rect.offset.x + img_rect.size.w)
    {
        clip_n.offset.x = img_rect.offset.x + img_rect.size.w - clip_n.size.w;
    }

    MMI_ASSERT(clip_n.offset.x >= img_rect.offset.x);

    if(clip_n.offset.y < img_rect.offset.y)
    {
        clip_n.offset.y = img_rect.offset.y;
    }

    if(clip_n.offset.y + clip_n.size.h > img_rect.offset.y + img_rect.size.h)
    {
        clip_n.offset.y = img_rect.offset.y + img_rect.size.h - clip_n.size.h;
    }

    MMI_ASSERT(clip_n.offset.y >= img_rect.offset.y);

    g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect = clip_n;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_rect_zoom_out
* DESCRIPTION
*  scale down the clip rect when in fix ratio clip
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_clip_rect_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_rect_struct      clip_o      = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect;
    phoedt_rect_struct      clip_n;
    phoedt_rect_struct      img_rect    = g_phoedt_cui_cntx_p->display_info.img_rect;
    phoedt_size_struct      ratio       = g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.w_h_ratio;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(PHOEDT_CLIP_TYPE_FIX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type);
    MMI_ASSERT(g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.curr_min_ratio <=
        g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio);

    if(g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.curr_min_ratio ==
       g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio)
    {
        return;
    }

    gdi_image_util_fit_bbox(img_rect.size.w, img_rect.size.h, ratio.w, ratio.h, &clip_n.offset.x, &clip_n.offset.y, &clip_n.size.w, &clip_n.size.h);

    g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio -= PHOEDT_CLIP_RECT_STEP_RATION;

    clip_n.size.w = clip_n.size.w * g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio / 100;
    clip_n.size.h = clip_n.size.h * g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio / 100;

    clip_n.offset.x = clip_o.offset.x + ((clip_o.size.w - clip_n.size.w) >> 1);
    clip_n.offset.y = clip_o.offset.y + ((clip_o.size.h - clip_n.size.h) >> 1);

    if(clip_n.offset.x < img_rect.offset.x)
    {
        clip_n.offset.x = img_rect.offset.x;
    }

    if(clip_n.offset.x + clip_n.size.w > img_rect.offset.x + img_rect.size.w)
    {
        clip_n.offset.x = img_rect.offset.x + img_rect.size.w - clip_n.size.w;
    }

    MMI_ASSERT(clip_n.offset.x >= img_rect.offset.x);

    if(clip_n.offset.y < img_rect.offset.y)
    {
        clip_n.offset.y = img_rect.offset.y;
    }

    if(clip_n.offset.y + clip_n.size.h > img_rect.offset.y + img_rect.size.h)
    {
        clip_n.offset.y = img_rect.offset.y + img_rect.size.h - clip_n.size.h;
    }

    MMI_ASSERT(clip_n.offset.y >= img_rect.offset.y);

    g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect = clip_n;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_clip_switch_state
* DESCRIPTION
*  switch the clip state when in manual clip
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_clip_switch_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_state++;
    g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_state %= PHOEDT_CLIP_STATE_COUNT;
}
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_change_value_left
* DESCRIPTION
*  change the adjust value smaller
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_adjust_change_value_left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_adjust_struct        *curr_adj       = cui_phoedt_get_curr_adjust_item();
    S32                         curr_item_idx   = g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx;
    phoedt_adjust_range_struct  *adj_para       = &curr_adj->para_items[curr_item_idx].para;
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(adj_para->value >= adj_para->min);

    if(adj_para->value > adj_para->min)
    {
        adj_para->value -= adj_para->step;
    }

    if(adj_para->value < adj_para->min)
    {
        adj_para->value = adj_para->min;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ADJUST_CHANGE_VALUE,
        g_phoedt_cui_cntx_p->curr_act.para.adjust.idx, curr_item_idx,
        adj_para->min, adj_para->max, adj_para->init, adj_para->value, adj_para->step);

    ies_ret = srv_ies_effect_set_param_int(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        curr_item_idx,
        adj_para->value);

    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_preview_image(MMI_FALSE);
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_change_value_right
* DESCRIPTION
*  change the adjust value bigger
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_adjust_change_value_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_adjust_struct        *curr_adj       = cui_phoedt_get_curr_adjust_item();
    S32                         curr_item_idx   = g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx;
    phoedt_adjust_range_struct  *adj_para       = &curr_adj->para_items[curr_item_idx].para;
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(adj_para->value <= adj_para->max);

    if(adj_para->value < adj_para->max)
    {
        adj_para->value += adj_para->step;
    }

    if(adj_para->value > adj_para->max)
    {
        adj_para->value = adj_para->max;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ADJUST_CHANGE_VALUE,
        g_phoedt_cui_cntx_p->curr_act.para.adjust.idx, curr_item_idx,
        adj_para->min, adj_para->max, adj_para->init, adj_para->value, adj_para->step);

    ies_ret = srv_ies_effect_set_param_int(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        curr_item_idx,
        adj_para->value);

    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_preview_image(MMI_FALSE);
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_set_value_by_pos
* DESCRIPTION
*  set adjust value by position which in screen coordinate system.
*  will calculate the value by the position offset on adjust bar.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_adjust_set_value_by_pos(phoedt_pos_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_adjust_struct        *curr_adj       = cui_phoedt_get_curr_adjust_item();
    S32                         curr_item_idx   = g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx;
    phoedt_adjust_range_struct  *adj_para       = &curr_adj->para_items[curr_item_idx].para;
    phoedt_rect_struct          bar             = cui_phoedt_get_adjust_static_obj_rect(PHOEDT_ADJUST_STATIC_OBJ_TYPE_BAR, curr_item_idx);
    S32                         bar_range       = bar.size.w - (g_phoedt_layout.adjust_bar_margin << 1);
    S32                         value_range     = adj_para->max - adj_para->min;
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(pos.x <= (bar.offset.x + g_phoedt_layout.adjust_bar_margin))
    {
        adj_para->value = adj_para->min;
    }
    else if(pos.x >= (bar.offset.x + bar.size.w - 1 - g_phoedt_layout.adjust_bar_margin))
    {
        adj_para->value = adj_para->max;
    }
    else
    {
        adj_para->value = (S32)(value_range * (pos.x - (bar.offset.x + g_phoedt_layout.adjust_bar_margin)) / bar_range) + adj_para->min;
        if(adj_para->value >= 0)
        {
            adj_para->value = (S32)(adj_para->value / adj_para->step + 0.5) * adj_para->step;
        }
        else
        {
            adj_para->value = (S32)(adj_para->value / adj_para->step - 0.5) * adj_para->step;
        }
    }

    if(adj_para->value < adj_para->min)
    {
        adj_para->value = adj_para->min;
    }

    if(adj_para->value > adj_para->max)
    {
        adj_para->value = adj_para->max;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ADJUST_CHANGE_VALUE,
        g_phoedt_cui_cntx_p->curr_act.para.adjust.idx, curr_item_idx,
        adj_para->min, adj_para->max, adj_para->init, adj_para->value, adj_para->step);

    ies_ret = srv_ies_effect_set_param_int(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        curr_item_idx,
        adj_para->value);

    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_preview_image(MMI_FALSE);
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_select_prev_item
* DESCRIPTION
*  select adjust item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_adjust_select_item(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_adjust_struct    *curr_adj = cui_phoedt_get_curr_adjust_item();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx = idx;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_switch_item
* DESCRIPTION
*  switch adjust highlighted item
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_adjust_switch_item(phoedt_switch_direction_enum switch_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_adjust_struct    *curr_adj = cui_phoedt_get_curr_adjust_item();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PHOEDT_SWITCH_DIR_PREV == switch_direction)
    {
        g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx += (curr_adj->para_count - 1);
    }
    else if(PHOEDT_SWITCH_DIR_NEXT == switch_direction)
    {
        g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx ++;
    }
    else
    {
        /* para error */
        MMI_ASSERT(0);
    }

    g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx %= curr_adj->para_count;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_effect_switch
* DESCRIPTION
*  switch effect
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_effect_switch(phoedt_switch_direction_enum switch_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;
    MMI_BOOL                    is_err          = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_EFFECT_SWITCH, switch_direction);

    do
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CANCEL_EFFECT, g_phoedt_cui_cntx_p->curr_act.para.effect.idx);
        ies_ret = srv_ies_effect_cancel_adjust(
            g_phoedt_cui_cntx_p->ies_hdles.img);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            break;
        }

        if(PHOEDT_SWITCH_DIR_PREV == switch_direction)
        {
            g_phoedt_cui_cntx_p->curr_act.para.effect.idx += (g_phoedt_cui_cntx_p->ies_capacity.effect_count - 1);
        }
        else if(PHOEDT_SWITCH_DIR_NEXT == switch_direction)
        {
            g_phoedt_cui_cntx_p->curr_act.para.effect.idx ++;
        }
        else
        {
            /* para error */
            MMI_ASSERT(0);
        }

        g_phoedt_cui_cntx_p->curr_act.para.effect.idx %= g_phoedt_cui_cntx_p->ies_capacity.effect_count;

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_START_EFFECT, g_phoedt_cui_cntx_p->curr_act.para.effect.idx);
        ies_ret = srv_ies_effect_begin_adjust(
            g_phoedt_cui_cntx_p->ies_hdles.img,
            cui_phoedt_get_curr_effect_item()->id);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            break;
        }

        is_err = MMI_FALSE;
    }while(MMI_FALSE);

    if(MMI_FALSE == is_err)
    {
        cui_phoedt_preview_image(MMI_FALSE);
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_frame_switch
* DESCRIPTION
*  switch frame
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_frame_switch(phoedt_switch_direction_enum switch_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;
    MMI_BOOL                    is_err          = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_FRAME_SWITCH, switch_direction);

    do
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CANCEL_FRAME, g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx);
        ies_ret = srv_ies_frame_cancel(g_phoedt_cui_cntx_p->ies_hdles.img);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            break;
        }

        if(PHOEDT_SWITCH_DIR_PREV == switch_direction)
        {
            g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx += (PHOEDT_FRAME_COUNT - 1);
        }
        else if(PHOEDT_SWITCH_DIR_NEXT == switch_direction)
        {
            g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx ++;
        }
        else
        {
            /* para error */
            MMI_ASSERT(0);
        }

        g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx %= PHOEDT_FRAME_COUNT;

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_START_FRAME, g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx);
        ies_ret = srv_ies_frame_begin_from_id(
            g_phoedt_cui_cntx_p->ies_hdles.img,
            PHOEDT_CUI_FRAME_ID(g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx));
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            break;
        }

        is_err = MMI_FALSE;
    }while(MMI_FALSE);

    if(MMI_FALSE == is_err)
    {
        cui_phoedt_preview_image(MMI_FALSE);
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_icon_move_icon
* DESCRIPTION
*  move the icon to the specific direction
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_icon_move_icon(phoedt_move_direction_enum move_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_move_info_struct     *move_info  = cui_phoedt_get_curr_move_info();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    move_info->step = PHOEDT_MOVE_STEP_MIN;
    move_info->direction = move_direction;

    cui_phoedt_icon_move_cyclic();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_icon_move_cyclic
* DESCRIPTION
*  move the icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_icon_move_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_move_info_struct     *move_info      = cui_phoedt_get_curr_move_info();
    U32                         step            = cui_phoedt_convert_distance_scrn2img(move_info->step);
    MMI_BOOL                    timer_valid     = MMI_TRUE;
    phoedt_rect_struct          icon_rect;
    phoedt_rect_struct          available_rect  = g_phoedt_cui_cntx_p->display_info.img_rect;
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon_rect.offset = g_phoedt_cui_cntx_p->curr_act.para.icon.location;
    icon_rect.size.w = g_phoedt_cui_cntx_p->curr_act.para.icon.size;
    icon_rect.size.h = icon_rect.size.w;

    timer_valid = cui_phoedt_move_rect_in_an_area_by_info(available_rect, &icon_rect, *move_info);

    g_phoedt_cui_cntx_p->curr_act.para.icon.location = icon_rect.offset;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ICON_ADJUST_POS,
        g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx,
        g_phoedt_cui_cntx_p->curr_act.para.icon.location.x,
        g_phoedt_cui_cntx_p->curr_act.para.icon.location.y,
        PHOEDT_ICON_CENTER_X_ON_IMG, PHOEDT_ICON_CENTER_Y_ON_IMG);

    ies_ret = srv_ies_icon_adjust_pos(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        PHOEDT_ICON_CENTER_X_ON_IMG,
        PHOEDT_ICON_CENTER_Y_ON_IMG);

    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_preview_image(MMI_FALSE);

        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        if(MMI_TRUE == timer_valid)
        {
            /* make the move step bigger */
            move_info->step += PHOEDT_MOVE_STEP_DIFF;
            if(move_info->step > PHOEDT_MOVE_STEP_MAX)
            {
                move_info->step = PHOEDT_MOVE_STEP_MAX;
            }

            gui_start_timer(PHOEDT_MOVE_STEP_DURATION, cui_phoedt_icon_move_cyclic);
        }
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_icon_zoom_in
* DESCRIPTION
*  zoom in the icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_icon_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_phoedt_cui_cntx_p->curr_act.para.icon.max >= g_phoedt_cui_cntx_p->curr_act.para.icon.size);

    if(g_phoedt_cui_cntx_p->curr_act.para.icon.max == g_phoedt_cui_cntx_p->curr_act.para.icon.size)
    {
        return;
    }

    g_phoedt_cui_cntx_p->curr_act.para.icon.size += PHOEDT_ADD_ICON_ZOOM_STEP;

    MMI_ASSERT(g_phoedt_cui_cntx_p->curr_act.para.icon.max >= g_phoedt_cui_cntx_p->curr_act.para.icon.size);

    g_phoedt_cui_cntx_p->curr_act.para.icon.location.x -= (PHOEDT_ADD_ICON_ZOOM_STEP >> 1);
    g_phoedt_cui_cntx_p->curr_act.para.icon.location.y -= (PHOEDT_ADD_ICON_ZOOM_STEP >> 1);

    cui_phoedt_icon_adjust_after_zoom();

    cui_phoedt_preview_image(MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_icon_zoom_out
* DESCRIPTION
*  zoom out the icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_icon_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_phoedt_cui_cntx_p->curr_act.para.icon.min <= g_phoedt_cui_cntx_p->curr_act.para.icon.size);

    if(g_phoedt_cui_cntx_p->curr_act.para.icon.min == g_phoedt_cui_cntx_p->curr_act.para.icon.size)
    {
        return;
    }

    g_phoedt_cui_cntx_p->curr_act.para.icon.size -= PHOEDT_ADD_ICON_ZOOM_STEP;

    MMI_ASSERT(g_phoedt_cui_cntx_p->curr_act.para.icon.min <= g_phoedt_cui_cntx_p->curr_act.para.icon.size);

    g_phoedt_cui_cntx_p->curr_act.para.icon.location.x += (PHOEDT_ADD_ICON_ZOOM_STEP >> 1);
    g_phoedt_cui_cntx_p->curr_act.para.icon.location.y += (PHOEDT_ADD_ICON_ZOOM_STEP >> 1);

    cui_phoedt_icon_adjust_after_zoom();

    cui_phoedt_preview_image(MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_icon_rotate
* DESCRIPTION
*  rotate the icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_icon_adjust_after_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;
    S32                         icon_size       = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_phoedt_cui_cntx_p->curr_act.para.icon.location.x < g_phoedt_cui_cntx_p->display_info.img_rect.offset.x)
    {
        g_phoedt_cui_cntx_p->curr_act.para.icon.location.x = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x;
    }
    else if(g_phoedt_cui_cntx_p->curr_act.para.icon.location.x + g_phoedt_cui_cntx_p->curr_act.para.icon.size >
            g_phoedt_cui_cntx_p->display_info.img_rect.offset.x + g_phoedt_cui_cntx_p->display_info.img_rect.size.w)
    {
        g_phoedt_cui_cntx_p->curr_act.para.icon.location.x =
            g_phoedt_cui_cntx_p->display_info.img_rect.offset.x +
            g_phoedt_cui_cntx_p->display_info.img_rect.size.w -
            g_phoedt_cui_cntx_p->curr_act.para.icon.size;
    }

    if(g_phoedt_cui_cntx_p->curr_act.para.icon.location.y < g_phoedt_cui_cntx_p->display_info.img_rect.offset.y)
    {
        g_phoedt_cui_cntx_p->curr_act.para.icon.location.y = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y;
    }
    else if(g_phoedt_cui_cntx_p->curr_act.para.icon.location.y + g_phoedt_cui_cntx_p->curr_act.para.icon.size >
            g_phoedt_cui_cntx_p->display_info.img_rect.offset.y + g_phoedt_cui_cntx_p->display_info.img_rect.size.h)
    {
        g_phoedt_cui_cntx_p->curr_act.para.icon.location.y =
            g_phoedt_cui_cntx_p->display_info.img_rect.offset.y +
            g_phoedt_cui_cntx_p->display_info.img_rect.size.h -
            g_phoedt_cui_cntx_p->curr_act.para.icon.size;
    }

    icon_size = PHOEDT_ICON_SIZE_ON_IMG;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ICON_ADJUST_ALL,
        g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx,
        g_phoedt_cui_cntx_p->curr_act.para.icon.location.x,
        g_phoedt_cui_cntx_p->curr_act.para.icon.location.y,
        PHOEDT_ICON_CENTER_X_ON_IMG, PHOEDT_ICON_CENTER_Y_ON_IMG,
        g_phoedt_cui_cntx_p->curr_act.para.icon.size, icon_size,
        g_phoedt_cui_cntx_p->curr_act.para.icon.rotate);

    ies_ret = srv_ies_icon_adjust(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        PHOEDT_ICON_CENTER_X_ON_IMG,
        PHOEDT_ICON_CENTER_Y_ON_IMG,
        icon_size,
        icon_size,
        cui_phoedt_get_rotate_app2ies(g_phoedt_cui_cntx_p->curr_act.para.icon.rotate));

    if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_icon_rotate
* DESCRIPTION
*  rotate the icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_icon_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.para.icon.rotate++;
    g_phoedt_cui_cntx_p->curr_act.para.icon.rotate %= PHOEDT_ROTATE_COUNT;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ICON_ADJUST_ROTATE,
        g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx,
        g_phoedt_cui_cntx_p->curr_act.para.icon.rotate);

    ies_ret = srv_ies_icon_adjust_rotation(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        cui_phoedt_get_rotate_app2ies(g_phoedt_cui_cntx_p->curr_act.para.icon.rotate));

    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_preview_image(MMI_FALSE);
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_flip
* DESCRIPTION
*  flip image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_flip(phoedt_flip_direction_enum flip_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret     = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PHOEDT_FLIP_DIR_HORI == flip_direction)
    {
        g_phoedt_cui_cntx_p->curr_act.para.flip.horz =
            g_phoedt_cui_cntx_p->curr_act.para.flip.horz == MMI_TRUE ? MMI_FALSE : MMI_TRUE;
    }
    else if(PHOEDT_FLIP_DIR_VERT == flip_direction)
    {
        g_phoedt_cui_cntx_p->curr_act.para.flip.vert =
            g_phoedt_cui_cntx_p->curr_act.para.flip.vert == MMI_TRUE ? MMI_FALSE : MMI_TRUE;
    }
    else
    {
        /* para error */
        MMI_ASSERT(0);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_FLIP_ADJUST,
        g_phoedt_cui_cntx_p->curr_act.para.flip.vert, g_phoedt_cui_cntx_p->curr_act.para.flip.horz);

    ies_ret = srv_ies_image_flip_adjust(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        g_phoedt_cui_cntx_p->curr_act.para.flip.horz,
        g_phoedt_cui_cntx_p->curr_act.para.flip.vert);

    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_preview_image(MMI_FALSE);
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_rotate
* DESCRIPTION
*  rotate image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_rotate(phoedt_rotate_direction_enum rotate_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_rot_enum            rotate;
    srv_ies_result              ies_ret     = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PHOEDT_ROTATE_DIR_CCW == rotate_direction)
    {
        g_phoedt_cui_cntx_p->curr_act.para.rotate += PHOEDT_ROTATE_COUNT - 1;
    }
    else if(PHOEDT_ROTATE_DIR_CW == rotate_direction)
    {
        g_phoedt_cui_cntx_p->curr_act.para.rotate ++;
    }
    else
    {
        /* para error */
        MMI_ASSERT(0);
    }

    g_phoedt_cui_cntx_p->curr_act.para.rotate %= PHOEDT_ROTATE_COUNT;

    rotate = cui_phoedt_get_rotate_app2ies(g_phoedt_cui_cntx_p->curr_act.para.rotate);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ROTATE_ADJUST,
        g_phoedt_cui_cntx_p->curr_act.para.rotate);

    ies_ret = srv_ies_image_rotate_adjust(g_phoedt_cui_cntx_p->ies_hdles.img, rotate);
    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_update_image_curr_size();

        cui_phoedt_reset_image_display_info();

        cui_phoedt_preview_image(MMI_FALSE);
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


#ifdef __MMI_PHOEDT_DOODLE__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_switch_hide
* DESCRIPTION
*  swith hide
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_doodle_switch_hide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd =
        g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd == MMI_TRUE ? MMI_FALSE : MMI_TRUE;
}


#ifdef __MMI_PHOEDT_STYLE_FTE__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_switch_type
* DESCRIPTION
*  FTE ONLY: switch doodle type to line and set its size
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_doodle_switch_line_size(phoedt_doodle_size_enum size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret     = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.para.doodle.type = PHOEDT_DOODLE_TYPE_LINE;
    g_phoedt_cui_cntx_p->curr_act.para.doodle.size = size;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SET_LINE_SIZE,
        g_phoedt_doodle_size[g_phoedt_cui_cntx_p->curr_act.para.doodle.size]);

    ies_ret = srv_ies_doodle_set_line_width(
        g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle,
        g_phoedt_doodle_size[g_phoedt_cui_cntx_p->curr_act.para.doodle.size]);
    if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_close_edit_group();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_switch_eraser_size
* DESCRIPTION
*  FTE ONLY: switch doodle type to eraser and set its size
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_doodle_switch_eraser_size(phoedt_doodle_size_enum size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.para.doodle.type = PHOEDT_DOODLE_TYPE_ERASER;
    g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size = size;
}


#else /* __MMI_PHOEDT_STYLE_FTE__ */
/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_switch_type
* DESCRIPTION
*  switch type
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_doodle_switch_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.para.doodle.type++;
    g_phoedt_cui_cntx_p->curr_act.para.doodle.type %= PHOEDT_DOODLE_TYPE_COUNT;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_switch_size
* DESCRIPTION
*  switch size
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_doodle_switch_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret     = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PHOEDT_DOODLE_TYPE_LINE == g_phoedt_cui_cntx_p->curr_act.para.doodle.type)
    {
        g_phoedt_cui_cntx_p->curr_act.para.doodle.size++;
        g_phoedt_cui_cntx_p->curr_act.para.doodle.size %= PHOEDT_DOODLE_SIZE_COUNT;

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SET_LINE_SIZE,
            g_phoedt_doodle_size[g_phoedt_cui_cntx_p->curr_act.para.doodle.size]);

        ies_ret = srv_ies_doodle_set_line_width(
            g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle,
            g_phoedt_doodle_size[g_phoedt_cui_cntx_p->curr_act.para.doodle.size]);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            cui_phoedt_cancel_curr_change();
            cui_phoedt_close_edit_group();
        }
    }
    else
    {
        g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size++;
        g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size %= PHOEDT_DOODLE_SIZE_COUNT;
    }
}
#endif /* __MMI_PHOEDT_STYLE_FTE__ */
#endif /* __MMI_PHOEDT_DOODLE__ */


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_config_pen_config_sampling_period
* DESCRIPTION
*  cui_phoedt_config_pen_config_sampling_period
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_config_pen_config_sampling_period(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            need_high   = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_phoedt_cui_cntx_p->curr_act.action)
    {
    #ifdef __MMI_PHOEDT_DOODLE__
        case PHOEDT_ACTION_TYPE_DOODLE:
            {
                need_high = MMI_TRUE;
            }
            break;
    #endif /* __MMI_PHOEDT_DOODLE__ */

        case PHOEDT_ACTION_TYPE_CLIP:
            {
                need_high = MMI_TRUE;
            }
            break;

        default:
            break;
    }

    if(MMI_TRUE == need_high)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SET_SAMPLING_PERIOD, MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);
        mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_restore_pen_config_sampling_period
* DESCRIPTION
*  cui_phoedt_restore_pen_config_sampling_period
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_restore_pen_config_sampling_period(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SET_SAMPLING_PERIOD, MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_ies_job
* DESCRIPTION
*  cui_phoedt_cancel_ies_job
* PARAMETERS
*  job          [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_ies_job(srv_ies_job_handle *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result          ies_ret = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != job && NULL != *job)
    {
        ies_ret = srv_ies_job_cancel(*job);
        PHOEDT_TRACE_IES_RESULT(ies_ret);

        *job = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_start_curr_change
* DESCRIPTION
*  cui_phoedt_start_curr_change
* PARAMETERS
*  void
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_start_curr_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            ret                 = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].start)
        ret = g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].start();

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_end_curr_change
* DESCRIPTION
*  if in select area screen, then apply means entry doodle screen,
*  not apply means back to main screen.
*  else apply means apply curr change and back to main screen,
*  not apply means back to previous screen(same as close edit screen).
* PARAMETERS
*  is_apply         [IN]    apply curr change or cancel it, in acturally
*                           it also means handle LSK(CSK)event or RSK event
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_end_curr_change(MMI_BOOL is_apply)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == is_apply)
    {
        cui_phoedt_apply_curr_change();
        cui_phoedt_close_edit_group();
    }
    else
    {
        cui_phoedt_cancel_curr_change();
        cui_phoedt_reset_curr_change_para();
        /* back to previous screen */
        mmi_frm_scrn_close(GRP_ID_PHOEDT_EDIT_GROUP, SCR_ID_PHOEDT_EDIT);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_apply_curr_change
* DESCRIPTION
*  apply curr change
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_apply_curr_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(PHOEDT_ACTION_STATE_STARTED == g_phoedt_cui_cntx_p->curr_act.state);

    if (NULL != g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].apply)
        g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].apply();
    else
        MMI_ASSERT(0);

    if (PHOEDT_ACTION_TYPE_CLIP == g_phoedt_cui_cntx_p->curr_act.action || 
        /* Cause part of osd is drawn on preview layer */
        PHOEDT_ACTION_TYPE_ICON == g_phoedt_cui_cntx_p->curr_act.action)
    {
        g_phoedt_cui_cntx_p->curr_act.preview_after_end = MMI_TRUE;
        //cui_phoedt_reset_image_display_info();
        //cui_phoedt_preview_image(MMI_FALSE);
    }

    g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_ENDED;
    cui_phoedt_set_changed_count(PHOEDT_CHANGE_TYPE_CHANGE);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_curr_change
* DESCRIPTION
*  cancel curr change, will give up curr change and render to preview the image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_curr_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL        preview             = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(PHOEDT_ACTION_STATE_STARTED == g_phoedt_cui_cntx_p->curr_act.state);

    cui_phoedt_give_up_curr_change();

    switch(g_phoedt_cui_cntx_p->curr_act.action)
    {
    case PHOEDT_ACTION_TYPE_CLIP:
        break;
        
    case PHOEDT_ACTION_TYPE_ADJUST:
#ifdef __MMI_PHOEDT_DOODLE__
    case PHOEDT_ACTION_TYPE_DOODLE:
#endif /* #ifdef __MMI_PHOEDT_DOODLE__ */
    case PHOEDT_ACTION_TYPE_EFFECT:
    case PHOEDT_ACTION_TYPE_FRAME:
    case PHOEDT_ACTION_TYPE_ICON:
        {
            g_phoedt_cui_cntx_p->curr_act.preview_after_end = MMI_TRUE;
        }
        break;

    case PHOEDT_ACTION_TYPE_FLIP:
        {
            if(MMI_FALSE != g_phoedt_cui_cntx_p->curr_act.para.flip.vert ||
               MMI_FALSE != g_phoedt_cui_cntx_p->curr_act.para.flip.horz)
            {
                g_phoedt_cui_cntx_p->curr_act.preview_after_end = MMI_TRUE;
            }
        }
        break;

    case PHOEDT_ACTION_TYPE_ROTATE:
        {
            if(PHOEDT_ROTATE_0 != g_phoedt_cui_cntx_p->curr_act.para.rotate)
            {
                g_phoedt_cui_cntx_p->curr_act.preview_after_end = MMI_TRUE;
            }
        }
        break;

    default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

    if(MMI_TRUE == preview)
    {
        cui_phoedt_reset_image_display_info();
        cui_phoedt_preview_image(MMI_FALSE);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_give_up_curr_change
* DESCRIPTION
*  only give up current change
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_give_up_curr_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PHOEDT_ACTION_STATE_STARTED == g_phoedt_cui_cntx_p->curr_act.state)
    {
        if (NULL != g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].cancel)
            g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].cancel();
        
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_ENDED;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_start_clip
* DESCRIPTION
*  cui_phoedt_start_clip
* PARAMETERS
*  void
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_start_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            ret                 = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_apply_clip
* DESCRIPTION
*  apply clip and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_apply_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_rect_struct          img_clip_rect;
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_clip_rect.offset.x = cui_phoedt_convert_offset_x_scrn2img(g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.x);
    img_clip_rect.offset.y = cui_phoedt_convert_offset_y_scrn2img(g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.y);
    img_clip_rect.size.w = cui_phoedt_convert_distance_scrn2img(g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w);
    img_clip_rect.size.h = cui_phoedt_convert_distance_scrn2img(g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CLIP,
        img_clip_rect.offset.x, img_clip_rect.offset.y, img_clip_rect.size.w, img_clip_rect.size.h);

    ies_ret = srv_ies_image_crop(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        img_clip_rect.offset.x,
        img_clip_rect.offset.y,
        img_clip_rect.size.w,
        img_clip_rect.size.h);

    if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        g_phoedt_cui_cntx_p->image_info.curr_size = img_clip_rect.size;

        cui_phoedt_reset_image_display_info();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_clip
* DESCRIPTION
*  cancel clip and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_start_adjust
* DESCRIPTION
*  cui_phoedt_start_adjust
* PARAMETERS
*  void
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_start_adjust(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret             = SRV_IES_OK;
    MMI_BOOL                    ret                 = MMI_TRUE;
    MMI_BOOL                    need_cancel         = MMI_FALSE;
    phoedt_adjust_struct        *curr_adj           = cui_phoedt_get_curr_adjust_item();
    S32                         curr_item_idx       = 0;
    phoedt_adjust_range_struct  *adj_para           = &curr_adj->para_items[curr_item_idx].para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do{
        g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx = curr_item_idx;

        adj_para->value = adj_para->init;

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_START_ADJUST,
            g_phoedt_cui_cntx_p->curr_act.para.adjust.idx, curr_item_idx,
            adj_para->min, adj_para->max, adj_para->init, adj_para->value, adj_para->step);

        ies_ret = srv_ies_effect_begin_adjust(
            g_phoedt_cui_cntx_p->ies_hdles.img,
            curr_adj->id);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            ret = MMI_FALSE;
            break;
        }

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_ADJUST_CHANGE_VALUE,
            g_phoedt_cui_cntx_p->curr_act.para.adjust.idx, curr_item_idx,
            adj_para->min, adj_para->max, adj_para->init, adj_para->value, adj_para->step);

        ies_ret = srv_ies_effect_set_param_int(
            g_phoedt_cui_cntx_p->ies_hdles.img,
            curr_item_idx,
            adj_para->value);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            ret = MMI_FALSE;
            need_cancel = MMI_TRUE;
            break;
        }
    }while(MMI_FALSE);

    if(MMI_FALSE == ret)
    {
        if(MMI_TRUE == need_cancel)
        {
            g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
            cui_phoedt_give_up_curr_change();
        }
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_ENDED;
        cui_phoedt_close_edit_group();
    }
    else
    {
        cui_phoedt_preview_image(MMI_FALSE);
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_apply_adjust
* DESCRIPTION
*  apply adjust and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_apply_adjust(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;
    phoedt_adjust_struct        *curr_adj       = cui_phoedt_get_curr_adjust_item();
    U16                         curr_item_idx;
    phoedt_adjust_range_struct  adj_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_item_idx   = g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx;
    adj_para        = curr_adj->para_items[curr_item_idx].para;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_APPLY_ADJUST,
        g_phoedt_cui_cntx_p->curr_act.para.adjust.idx, curr_item_idx,
        adj_para.min, adj_para.max, adj_para.init, adj_para.value, adj_para.step);

    ies_ret = srv_ies_effect_end_adjust(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_adjust
* DESCRIPTION
*  cancel adjust and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_adjust(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;
    phoedt_adjust_struct        *curr_adj       = cui_phoedt_get_curr_adjust_item();
    U16                         curr_item_idx;
    phoedt_adjust_range_struct  adj_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_item_idx = g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx;
    adj_para = curr_adj->para_items[curr_item_idx].para;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CANCEL_ADJUST,
        g_phoedt_cui_cntx_p->curr_act.para.adjust.idx, curr_item_idx,
        adj_para.min, adj_para.max, adj_para.init, adj_para.value, adj_para.step);

    ies_ret = srv_ies_effect_cancel_adjust(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_start_effect
* DESCRIPTION
*  cui_phoedt_start_effect
* PARAMETERS
*  void
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_start_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret             = SRV_IES_OK;
    MMI_BOOL            ret                 = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_START_EFFECT, g_phoedt_cui_cntx_p->curr_act.para.effect.idx);
    ies_ret = srv_ies_effect_begin_adjust(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        cui_phoedt_get_curr_effect_item()->id);
    if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        ret = MMI_FALSE;
    }

    if(MMI_FALSE == ret)
    {
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_ENDED;
        cui_phoedt_close_edit_group();
    }
    else
    {
        cui_phoedt_preview_image(MMI_FALSE);
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_apply_effect
* DESCRIPTION
*  apply effect and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_apply_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;
    phoedt_effect_struct        *curr_effect    = cui_phoedt_get_curr_effect_item();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_APPLY_EFFECT, g_phoedt_cui_cntx_p->curr_act.para.effect.idx);

    ies_ret = srv_ies_effect_end_adjust(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_effect
* DESCRIPTION
*  cancel effect and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;
    phoedt_effect_struct        *curr_effect    = cui_phoedt_get_curr_effect_item();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CANCEL_EFFECT, g_phoedt_cui_cntx_p->curr_act.para.effect.idx);

    ies_ret = srv_ies_effect_cancel_adjust(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_start_icon
* DESCRIPTION
*  cui_phoedt_start_icon
* PARAMETERS
*  void
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_start_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret             = SRV_IES_OK;
    MMI_BOOL            ret                 = MMI_TRUE;
    MMI_BOOL            need_cancel         = MMI_FALSE;
    S32                 icon_size           = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do{
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_START_ICON, g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx);
        ies_ret = srv_ies_icon_begin_from_id(
            g_phoedt_cui_cntx_p->ies_hdles.img,
            PHOEDT_CUI_ICON_ID(g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx));
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            ret = MMI_FALSE;
            break;
        }

        srv_ies_icon_get_min_max_adjustable_size(
            g_phoedt_cui_cntx_p->ies_hdles.img,
            &g_phoedt_cui_cntx_p->curr_act.para.icon.srv_min,
            &g_phoedt_cui_cntx_p->curr_act.para.icon.srv_max);

        g_phoedt_cui_cntx_p->curr_act.para.icon.max = PHOEDT_ADD_ICON_CURR_MAX_SIZE(
            g_phoedt_cui_cntx_p->curr_act.para.icon.srv_max);
        g_phoedt_cui_cntx_p->curr_act.para.icon.min = PHOEDT_ADD_ICON_CURR_MIN_SIZE(
            g_phoedt_cui_cntx_p->curr_act.para.icon.srv_min);

        if(g_phoedt_cui_cntx_p->curr_act.para.icon.max < g_phoedt_cui_cntx_p->curr_act.para.icon.min ||
           g_phoedt_cui_cntx_p->display_info.img_rect.size.w < g_phoedt_cui_cntx_p->curr_act.para.icon.min ||
           g_phoedt_cui_cntx_p->display_info.img_rect.size.h < g_phoedt_cui_cntx_p->curr_act.para.icon.min)
        {
            PHOEDT_ICON_HIDE_ICON_BORDER();

            PHOEDT_CUI_DISPLAY_POPUP(
                g_phoedt_cui_cntx_p->cui_gid,
                (WCHAR*)GetString(STR_ID_PHOEDT_NOTIFY_UNFIT_FOR_EDIT),
                MMI_EVENT_FAILURE);

            ret = MMI_FALSE;
            need_cancel = MMI_TRUE;
            break;
        }

        if(PHOEDT_ADD_ICON_DEF_SIZE > g_phoedt_cui_cntx_p->curr_act.para.icon.max)
        {
            g_phoedt_cui_cntx_p->curr_act.para.icon.size = g_phoedt_cui_cntx_p->curr_act.para.icon.max;
        }
        else if(PHOEDT_ADD_ICON_DEF_SIZE < g_phoedt_cui_cntx_p->curr_act.para.icon.min)
        {
            g_phoedt_cui_cntx_p->curr_act.para.icon.size = g_phoedt_cui_cntx_p->curr_act.para.icon.min;
        }
        else
        {
            g_phoedt_cui_cntx_p->curr_act.para.icon.size = PHOEDT_ADD_ICON_DEF_SIZE;
        }

        g_phoedt_cui_cntx_p->curr_act.para.icon.location.x =
            (UI_device_width - g_phoedt_cui_cntx_p->curr_act.para.icon.size)>> 1;
        g_phoedt_cui_cntx_p->curr_act.para.icon.location.y =
            (UI_device_height - g_phoedt_cui_cntx_p->curr_act.para.icon.size)>> 1;
        g_phoedt_cui_cntx_p->curr_act.para.icon.rotate = PHOEDT_ROTATE_0;

        icon_size = PHOEDT_ICON_SIZE_ON_IMG;

        ies_ret = srv_ies_icon_adjust(
            g_phoedt_cui_cntx_p->ies_hdles.img,
            PHOEDT_ICON_CENTER_X_ON_IMG,
            PHOEDT_ICON_CENTER_Y_ON_IMG,
            icon_size,
            icon_size,
            cui_phoedt_get_rotate_app2ies(g_phoedt_cui_cntx_p->curr_act.para.icon.rotate));
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            ret = MMI_FALSE;
            need_cancel = MMI_TRUE;
            break;
        }
    }while(MMI_FALSE);

    if(MMI_FALSE == ret)
    {
        if(MMI_TRUE == need_cancel)
        {
            g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
            cui_phoedt_give_up_curr_change();
        }
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_ENDED;
        cui_phoedt_close_edit_group();
    }
    else
    {
        cui_phoedt_preview_image(MMI_FALSE);
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_apply_icon
* DESCRIPTION
*  apply icon and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_apply_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_APPLY_ICON, g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx);

    ies_ret = srv_ies_icon_end(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_icon
* DESCRIPTION
*  cancel add icon and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CANCEL_ICON, g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx);

    ies_ret = srv_ies_icon_cancel(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_start_frame
* DESCRIPTION
*  cui_phoedt_start_frame
* PARAMETERS
*  void
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_start_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret             = SRV_IES_OK;
    MMI_BOOL            ret                 = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_START_FRAME, g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx);
    ies_ret = srv_ies_frame_begin_from_id(
        g_phoedt_cui_cntx_p->ies_hdles.img,
        PHOEDT_CUI_FRAME_ID(g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx));
    if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        ret = MMI_FALSE;
    }

    if(MMI_FALSE == ret)
    {
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_ENDED;
        cui_phoedt_close_edit_group();
    }
    else
    {
        cui_phoedt_preview_image(MMI_FALSE);
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_apply_frame
* DESCRIPTION
*  apply frame and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_apply_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_APPLY_FRAME, g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx);

    ies_ret = srv_ies_frame_end(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_frame
* DESCRIPTION
*  cancel add frame and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CANCEL_FRAME, g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx);

    ies_ret = srv_ies_frame_cancel(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_start_flip
* DESCRIPTION
*  cui_phoedt_start_flip
* PARAMETERS
*  void
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_start_flip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret             = SRV_IES_OK;
    MMI_BOOL            ret                 = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_START_FLIP,
        g_phoedt_cui_cntx_p->curr_act.para.flip.vert, g_phoedt_cui_cntx_p->curr_act.para.flip.horz);
    ies_ret = srv_ies_image_flip_begin(g_phoedt_cui_cntx_p->ies_hdles.img);
    if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        ret = MMI_FALSE;
    }

    if(MMI_FALSE == ret)
    {
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_ENDED;
        cui_phoedt_close_edit_group();
    }
    else
    {
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_apply_flip
* DESCRIPTION
*  apply flip and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_apply_flip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_APPLY_FLIP,
        g_phoedt_cui_cntx_p->curr_act.para.flip.vert, g_phoedt_cui_cntx_p->curr_act.para.flip.horz);

    ies_ret = srv_ies_image_flip_end(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_flip
* DESCRIPTION
*  cancel flip and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_flip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CANCEL_FLIP,
        g_phoedt_cui_cntx_p->curr_act.para.flip.vert, g_phoedt_cui_cntx_p->curr_act.para.flip.horz);

    ies_ret = srv_ies_image_flip_cancel(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_start_rotate
* DESCRIPTION
*  cui_phoedt_start_rotate
* PARAMETERS
*  void
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_start_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret             = SRV_IES_OK;
    MMI_BOOL            ret                 = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_START_ROTATE, g_phoedt_cui_cntx_p->curr_act.para.rotate);
    ies_ret = srv_ies_image_rotate_begin(g_phoedt_cui_cntx_p->ies_hdles.img);
    if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
    {
        ret = MMI_FALSE;
    }

    if(MMI_FALSE == ret)
    {
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_ENDED;
        cui_phoedt_close_edit_group();
    }
    else
    {
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_apply_rotate
* DESCRIPTION
*  apply rotate and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_apply_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_APPLY_ROTATE, g_phoedt_cui_cntx_p->curr_act.para.rotate);

    ies_ret = srv_ies_image_rotate_end(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_rotate
* DESCRIPTION
*  cancel rotate and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_rotate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CANCEL_ROTATE, g_phoedt_cui_cntx_p->curr_act.para.rotate);

    ies_ret = srv_ies_image_rotate_cancel(g_phoedt_cui_cntx_p->ies_hdles.img);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);

    cui_phoedt_update_image_curr_size();
    cui_phoedt_reset_image_display_info();
}


#ifdef __MMI_PHOEDT_DOODLE__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_start_doodle
* DESCRIPTION
*  cui_phoedt_start_doodle
* PARAMETERS
*  void
* RETURNS
*  success or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_start_doodle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret             = SRV_IES_OK;
    MMI_BOOL            ret                 = MMI_TRUE;
    MMI_BOOL            need_cancel         = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do{
        g_phoedt_cui_cntx_p->curr_act.para.doodle.size = PHOEDT_DOODLE_SIZE_SMALL;
        g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size = PHOEDT_DOODLE_SIZE_SMALL;

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_START_DOODLE);
        ies_ret = srv_ies_doodle_create(
            g_phoedt_cui_cntx_p->ies_hdles.preview,
            &g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            ret = MMI_FALSE;
            break;
        }

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SET_LINE_SIZE,
            g_phoedt_doodle_size[g_phoedt_cui_cntx_p->curr_act.para.doodle.size]);

        ies_ret = srv_ies_doodle_set_line_width(
            g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle,
            g_phoedt_doodle_size[g_phoedt_cui_cntx_p->curr_act.para.doodle.size]);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            ret = MMI_FALSE;
            need_cancel = MMI_TRUE;
            break;
        }

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SET_LINE_COLOR,
            g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx,
            g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].r,
            g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].g,
            g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].b);

        ies_ret = srv_ies_doodle_set_color(
            g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle,
            g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].r,
            g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].g,
            g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].b);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
        {
            ret = MMI_FALSE;
            need_cancel = MMI_TRUE;
            break;
        }
    }while(MMI_FALSE);

    if(MMI_FALSE == ret)
    {
        if(MMI_TRUE == need_cancel)
        {
            g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
            cui_phoedt_give_up_curr_change();
        }
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_ENDED;
        cui_phoedt_close_edit_group();
    }
    else
    {
        cui_phoedt_preview_image(MMI_FALSE);
        g_phoedt_cui_cntx_p->curr_act.state = PHOEDT_ACTION_STATE_STARTED;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_apply_doodle
* DESCRIPTION
*  apply doodle and back to man screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_apply_doodle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_APPLY_DOODLE);

    ies_ret = srv_ies_doodle_commit_and_destroy(g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_cancel_doodle
* DESCRIPTION
*  cancel doodle and back to main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_cancel_doodle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CANCEL_DOODLE);

    ies_ret = srv_ies_doodle_cancel_and_destroy(g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle);
    PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret);
}
#endif /* __MMI_PHOEDT_DOODLE__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_enter_edit_group
* DESCRIPTION
*  enter edit group: contain edit screens and before/after edit group
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_enter_edit_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_group_get_state(GRP_ID_PHOEDT_EDIT_GROUP) == MMI_SCENARIO_STATE_NONE)
    {
        mmi_frm_group_create(
            g_phoedt_cui_cntx_p->cui_gid,
            GRP_ID_PHOEDT_EDIT_GROUP,
            cui_phoedt_proc,
            NULL);

        mmi_frm_group_enter(GRP_ID_PHOEDT_EDIT_GROUP, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_close_edit_group
* DESCRIPTION
*  close edit group: contain edit screens and before/after edit group
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_close_edit_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_PHOEDT_EDIT_GROUP);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_main_screen
* DESCRIPTION
*  entry main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE == mmi_frm_scrn_enter(
        g_phoedt_cui_cntx_p->cui_gid,
        SCR_ID_PHOEDT_MAIN,
        cui_phoedt_exit_main_screen,
        cui_phoedt_entry_main_screen,
        MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* MAUI_02729116, when entry should reset key and pen status */
    cui_phoedt_reset_interact_item_state();

    if (PHOEDT_ACTION_TYPE_LOADING != g_phoedt_cui_cntx_p->curr_act.action)
    {
        g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_NONE;
    }
    else
    {
        S32 image_width, image_height;
        gdi_image_get_dimension_id(IMG_ID_PHOEDT_APP_PROCESS, &image_width, &image_height);
        gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->preview_layer);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_anim_draw_id(
            (UI_device_width - image_width) >> 1, 
            (UI_device_height - image_height) >> 1,
            IMG_ID_PHOEDT_APP_PROCESS,
            &g_phoedt_cui_cntx_p->curr_act.para.loading.loading_hdl);
        gdi_layer_pop_and_restore_active();
    }

    cui_phoedt_create_osd_layer();
    gdi_layer_set_blt_layer(
        g_phoedt_cui_cntx_p->preview_layer,
        g_phoedt_cui_cntx_p->osd_layer, 
        GDI_LAYER_EMPTY_HANDLE, 
        GDI_LAYER_EMPTY_HANDLE);

    if(g_phoedt_cui_cntx_p->curr_act.preview_after_end == MMI_TRUE)
    {
        g_phoedt_cui_cntx_p->curr_act.preview_after_end = MMI_FALSE;
        cui_phoedt_reset_image_display_info();
        if(MMI_FALSE == cui_phoedt_preview_image(MMI_FALSE))
        {
            return;
        }
    }

    cui_phoedt_set_key_proc(g_phoedt_cui_cntx_p->cui_gid, SCR_ID_PHOEDT_MAIN);
    cui_phoedt_set_pen_hdlrs();

    cui_phoedt_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_MAIN_SCREEN_END);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_exit_main_screen
* DESCRIPTION
*  exit edit screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_exit_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == g_phoedt_cui_cntx_p)
    {
        /* photo editor already not exist, then do nothing */
        return;
    }

    /* MAUI_02729116, when exit should reset key and pen status,
    then draw new osd on the layer and flatten to base */
    cui_phoedt_reset_interact_item_state();

    cui_phoedt_draw_osd();

    gdi_layer_flatten_previous_to_base();

    cui_phoedt_free_osd_layer();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_main_option_screen
* DESCRIPTION
*  open option menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_main_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID          cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset all parameters */
    cui_phoedt_reset_curr_change_para();

    cui_id = cui_menu_create(
        g_phoedt_cui_cntx_p->cui_gid,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_FROM_RESOURCE,
        MENU_ID_PHOEDT_OPTION,
        MMI_FALSE,
        NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_menu_set_default_title(
        cui_id,
        (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_PHOEDT_APP)));

    cui_menu_run(cui_id);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_send_list_screen
* DESCRIPTION
*  open send option menu
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_send_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID                      cui_id;
    U16                         num;
    FS_HANDLE                   fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_UNKNOWN, g_phoedt_cui_cntx_p->new_file.filepath);

    if(FS_NO_ERROR < fs_ret)
    {
        g_phoedt_cui_cntx_p->send_cntx.parent_menu_id = fs_ret;
        num = GetNumOfChild_Ext(g_phoedt_cui_cntx_p->send_cntx.parent_menu_id);

        if(0 < num)
        {
            cui_id = cui_menu_create(
                g_phoedt_cui_cntx_p->cui_gid,
                CUI_MENU_SRC_TYPE_APPCREATE,
                CUI_MENU_TYPE_OPTION,
                MENU_ID_PHOEDT_SEND,
                MMI_FALSE,
                NULL);

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

            cui_menu_set_default_title(
                cui_id,
                (WCHAR*)GetString(STR_GLOBAL_SEND),
                (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_PHOEDT_APP)));

            cui_menu_run(cui_id);
            return;
        }
    }

    g_phoedt_cui_cntx_p->send_cntx.parent_menu_id = PHOEDT_RES_DUMMY_ID;
    PHOEDT_CUI_DISPLAY_POPUP(
        g_phoedt_cui_cntx_p->cui_gid,
        (WCHAR*)GetString(STR_ID_FMGR_NO_FORWARD_OPTION),
        MMI_EVENT_FAILURE);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_frame_list_screen
* DESCRIPTION
*  open frame list screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_frame_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID                      cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_enter_edit_group();
    cui_phoedt_enter_before_edit_group();

    cui_id = cui_menu_create(
        GRP_ID_PHOEDT_BEFORE_EDIT_GROUP,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_PHOEDT_ADD_FRAME_LIST,
        MMI_FALSE,
        NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_menu_set_default_title(
        cui_id,
        (WCHAR*)GetString(STR_ID_PHOEDT_ADD_FRAME),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_PHOEDT_APP)));

    cui_menu_run(cui_id);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_effect_list_screen
* DESCRIPTION
*  open effect list screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_effect_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID                      cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_enter_edit_group();
    cui_phoedt_enter_before_edit_group();

    cui_id = cui_menu_create(
        GRP_ID_PHOEDT_BEFORE_EDIT_GROUP,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_PHOEDT_ADD_EFFECT,
        MMI_FALSE,
        NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_menu_set_default_title(
        cui_id,
        (WCHAR*)GetString(STR_ID_PHOEDT_ADD_EFFECT),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_PHOEDT_APP)));

    cui_menu_run(cui_id);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_adjust_list_screen
* DESCRIPTION
*  open adjust list screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_adjust_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID                      cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_enter_edit_group();
    cui_phoedt_enter_before_edit_group();

    cui_id = cui_menu_create(
        GRP_ID_PHOEDT_BEFORE_EDIT_GROUP,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_PHOEDT_ADJUST,
        MMI_FALSE,
        NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_menu_set_default_title(
        cui_id,
        (WCHAR*)GetString(STR_ID_PHOEDT_ADJUST),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_PHOEDT_APP)));

    cui_menu_run(cui_id);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_clip_list_screen
* DESCRIPTION
*  open clip list screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_clip_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID                      cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_enter_edit_group();
    cui_phoedt_enter_before_edit_group();

    cui_id = cui_menu_create(
        GRP_ID_PHOEDT_BEFORE_EDIT_GROUP,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_PHOEDT_CLIP,
        MMI_FALSE,
        NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_menu_set_default_title(
        cui_id,
        (WCHAR*)GetString(STR_ID_PHOEDT_CLIP),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_PHOEDT_APP)));

    cui_menu_run(cui_id);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_help_list_screen
* DESCRIPTION
*  open help list screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_help_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID                      cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_enter_edit_group();
    cui_phoedt_enter_before_edit_group();

    cui_id = cui_menu_create(
        GRP_ID_PHOEDT_BEFORE_EDIT_GROUP,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_PHOEDT_HELP_LIST,
        MMI_FALSE,
        NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_menu_set_default_title(
        cui_id,
        (WCHAR*)GetString(STR_GLOBAL_HELP),
        (UI_image_type)GetImage(GetRootTitleIcon(MENU_ID_PHOEDT_APP)));

    cui_menu_run(cui_id);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_folder_selector_screen
* DESCRIPTION
*  entry fmgr to select a folder to save the new image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_folder_selector_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID      cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_id = cui_folder_selector_create(
        g_phoedt_cui_cntx_p->cui_gid,
        (WCHAR*)L"root",
        CUI_FOLDER_SELECTOR_STYLE_READ,
        CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_ALL | CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_folder_selector_run(cui_id);
}



/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_filename_editor_screen
* DESCRIPTION
*  entry edit filename screen, this function will prepare valid filename and
*  call an internal editor function for screen display
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_filename_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR       buf_filename[PHOEDT_FULL_FILENAME_BUFFER_LEN];
    WCHAR       buf_filepath[PHOEDT_FULL_PATH_BUFFER_LEN];
    S32         seq_num;
    MYTIME      currenttime;
    FS_HANDLE   file_handle;
    S32         path_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&currenttime);
    kal_wsprintf(
        buf_filename,
        "%02d-%02d-%02d-%02d-%02d",
        currenttime.nDay,
        currenttime.nMonth,
        currenttime.nYear%((currenttime.nYear/100)*100),
        currenttime.nHour,
        currenttime.nMin);

    path_len = mmi_wcslen(g_phoedt_cui_cntx_p->new_file.filepath);
    path_len += mmi_wcslen(buf_filename);
    path_len += PHOEDT_MAX_FILENAME_EXT_CHAR;

    if(path_len > PHOEDT_FULL_PATH_CHAR)
    {
        /* to avoid over flow */
        PHOEDT_CUI_DISPLAY_POPUP(
            g_phoedt_cui_cntx_p->cui_gid,
            GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT),
            MMI_EVENT_FAILURE);

        return;
    }

    kal_wsprintf(buf_filepath, "%w%w.jpg", g_phoedt_cui_cntx_p->new_file.filepath, buf_filename);

    file_handle = FS_Open(buf_filepath, FS_READ_ONLY);

    if(file_handle >= FS_NO_ERROR)
    {
        FS_Close(file_handle);

        path_len += 5;  /* 5 = strlen("(001)")*/
        if(path_len > PHOEDT_FULL_PATH_CHAR)
        {
            /* to avoid over flow */
            PHOEDT_CUI_DISPLAY_POPUP(
                g_phoedt_cui_cntx_p->cui_gid,
                GetString(PHOEDT_FULL_PATH_CHAR),
                MMI_EVENT_FAILURE);

            return;
        }

        /* add seq num */
        seq_num = 1;
        mmi_wcscpy(g_phoedt_cui_cntx_p->new_file.filename, buf_filename);

        while (MMI_TRUE)
        {
            kal_wsprintf(buf_filename, "%w(%03d)", g_phoedt_cui_cntx_p->new_file.filename, seq_num);
            kal_wsprintf(buf_filepath, "%w%w.jpg", g_phoedt_cui_cntx_p->new_file.filepath, buf_filename);

            file_handle = FS_Open(buf_filepath, FS_READ_ONLY);

            if(file_handle >= FS_NO_ERROR)
            {
                /* file exist */
                FS_Close(file_handle);
                seq_num++;
            }
            else
            {
                /* file not exit */
                break;
            }

            /* will overwrite existing function if exceed 100 */
            if(seq_num == 100)
            {
                break;
            }

        }
    }
    mmi_wcscpy(g_phoedt_cui_cntx_p->new_file.filename, buf_filename);

    cui_phoedt_entry_filename_editor_internal();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_editor_filename_internal
* DESCRIPTION
*  entry edit filename internal function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_filename_editor_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID      cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_enter_edit_group();

    cui_id = cui_filename_editor_create(
          GRP_ID_PHOEDT_EDIT_GROUP,
          (WCHAR*)g_phoedt_cui_cntx_p->new_file.filename,
          (PHOEDT_FULL_FILENAME_BUFFER_LEN) * ENCODING_LENGTH,
          PHOEDT_FULL_FILENAME_CHAR,
          (WCHAR*)g_phoedt_cui_cntx_p->new_file.filepath,
          (WCHAR*)L"jpg");

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_CUI_ID, cui_id, __LINE__);

    cui_filename_editor_set_title(
        cui_id,
        STR_ID_PHOEDT_EDIT_FILENAME,
        GetRootTitleIcon(MENU_ID_PHOEDT_APP));

    cui_filename_editor_run(cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_phoedt_entry_saving_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  parent_gid      [IN]    the screen's parent group id
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_phoedt_entry_saving_screen(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(GRP_ID_INVALID != parent_gid);

    mmi_frm_scrn_first_enter(
        parent_gid,
        SCR_ID_PHOEDT_SAVING,
        (FuncPtr)cui_phoedt_entry_saving_screen_internal,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_phoedt_entry_saving_screen_internal
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_phoedt_entry_saving_screen_internal(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == mmi_frm_scrn_enter(
        scrn_data->group_id,
        scrn_data->scrn_id,
        cui_phoedt_exit_saving_screen,
        (FuncPtr)cui_phoedt_entry_saving_screen,
        MMI_FRM_FG_ONLY_SCRN))
    {
        /* disable the GPIO backlight mechanism,
        keep the backlight alwarys on during saving progress */
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

        g_phoedt_cui_cntx_p->cat6003_cntx.message = (WCHAR*)GetString(STR_GLOBAL_SAVING);
        g_phoedt_cui_cntx_p->cat6003_cntx.sub_message = NULL;
        g_phoedt_cui_cntx_p->cat6003_cntx.percent = 0;

        /* Show saving screen */
        wgui_cat6003_show(
            PHOEDT_RES_DUMMY_ID,
            STR_GLOBAL_CANCEL,
            g_phoedt_cui_cntx_p->cat6003_cntx.message,
            g_phoedt_cui_cntx_p->cat6003_cntx.sub_message,
            g_phoedt_cui_cntx_p->cat6003_cntx.percent);

        /* Set Right softkey function to abort saving */
        SetRightSoftkeyFunction(cui_phoedt_cancel_save_job, KEY_EVENT_UP);
        mmi_frm_scrn_set_key_proc(scrn_data->group_id, scrn_data->scrn_id, cui_phoedt_saving_end_key_proc);

        gui_start_timer(PHOEDT_UPDATE_PROGRESS_DURATION, cui_phoedt_update_saving_progress);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_phoedt_cancel_save_job
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_phoedt_cancel_save_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  cui_phoedt_saving_end_key_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_phoedt_saving_end_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct  *key_evt    = (mmi_frm_key_evt_struct *)evt;
    mmi_ret                 ret         = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_PRE_KEY)
    {
        if (NULL != g_phoedt_cui_cntx_p && key_evt->key_code == KEY_END && key_evt->key_type == KEY_EVENT_DOWN)
        {
            g_phoedt_cui_cntx_p->curr_act.para.save.is_in_end_key = MMI_TRUE;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  cui_phoedt_exit_saving_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_phoedt_exit_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != g_phoedt_cui_cntx_p && PHOEDT_SAVE_STATE_SAVING == g_phoedt_cui_cntx_p->curr_act.para.save.state)
    {
        gui_cancel_timer(cui_phoedt_update_saving_progress);

        cui_phoedt_cancel_ies_job(&g_phoedt_cui_cntx_p->curr_act.para.save.job);
        mmi_wcscpy(g_phoedt_cui_cntx_p->new_file.filepath, g_phoedt_cui_cntx_p->org_file.filepath);

        g_phoedt_cui_cntx_p->curr_act.para.save.state = PHOEDT_SAVE_STATE_CANCELED;

        if(NULL != g_phoedt_cui_cntx_p->curr_act.para.save.callback)
        {
            if(MMI_TRUE == g_phoedt_cui_cntx_p->curr_act.para.save.is_in_end_key)
            {
                g_phoedt_cui_cntx_p->curr_act.para.save.callback(PHOEDT_SAVE_RESULT_IN_END_KEY);
            }
            else
            {
                g_phoedt_cui_cntx_p->curr_act.para.save.callback(PHOEDT_SAVE_RESULT_CANCELED);
            }
        }
    }

    /* restore the GPIO backlight mechanism */
    srv_backlight_turn_off();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_matrix_selector_screen
* DESCRIPTION
*  entry select matrix select screen
*  including select icon, select frame, select color
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_matrix_selector_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8          *gui_buffer;
    MMI_ID      parent_gid      = GRP_ID_INVALID;
    MMI_ID      scrn_id         = SCR_ID_INVALID;
    S32         highlight_idx   = 0;
    U16         total_count     = 0;
    MMI_STR_ID  title_str_id    = PHOEDT_RES_DUMMY_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_phoedt_cui_cntx_p->curr_act.action)
    {
    case PHOEDT_ACTION_TYPE_ICON:
        {
            cui_phoedt_enter_edit_group();
            cui_phoedt_enter_before_edit_group();
            parent_gid = GRP_ID_PHOEDT_BEFORE_EDIT_GROUP;
            scrn_id = SCR_ID_PHOEDT_ICON_SELECT;
            highlight_idx = 0;
            title_str_id = STR_ID_PHOEDT_ADD_ICON;
            total_count = PHOEDT_ICON_COUNT;
        }
        break;

#ifdef __MMI_PHOEDT_DOODLE__
    case PHOEDT_ACTION_TYPE_DOODLE:
        {
            cui_phoedt_enter_after_edit_group();
            parent_gid = GRP_ID_PHOEDT_AFTER_EDIT_GROUP;
            scrn_id = SCR_ID_PHOEDT_DOODLE_COLOR_SELECT;
            highlight_idx = g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx;
            title_str_id = STR_ID_PHOEDT_DOODLE_COLOR;
            total_count = sizeof(g_phoedt_doodle_line_color_list) / sizeof(color);
        }
        break;
#endif /* #ifdef __MMI_PHOEDT_DOODLE__ */

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */
    }

    if(!mmi_frm_scrn_enter(
            parent_gid,
            scrn_id,
            NULL,
            cui_phoedt_entry_matrix_selector_screen,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    cui_phoedt_reset_interact_item_state();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(cui_phoedt_matrix_selector_highlight_hdlr);

    ShowCategory214Screen(
        title_str_id,
        GetRootTitleIcon(MENU_ID_PHOEDT_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        total_count,                                    /* num of item */
        (Cat214DrawImageFuncPtr)cui_phoedt_matrix_selector_draw_image_callback, /* draw image callback */
        NULL,                                           /* hide image callback */
        PHOEDT_MATRIX_ICONS_PER_COL,                    /* number per col, para name is different with the actural mean */
        PHOEDT_MATRIX_ICONS_PER_ROW,                    /* number per row, para name is different with the actural mean */
        highlight_idx,                                  /* hilighted item */
        (U8*)gui_buffer);

    SetRightSoftkeyFunction(cui_phoedt_matrix_selector_cancel_hdlr, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(cui_phoedt_matrix_selector_select_hdlr, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(cui_phoedt_matrix_selector_select_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_exit
* DESCRIPTION
*  if no change, close phoart. if changed, popup confirm.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PHOEDT_ACTION_TYPE_LOADING == g_phoedt_cui_cntx_p->curr_act.action)
    {
        cui_phoedt_cancel_ies_job(&g_phoedt_cui_cntx_p->curr_act.para.loading.job);
    }

    if(0 == g_phoedt_cui_cntx_p->change_cntx.count)
    {
        cui_phoedt_exit_curr_phoart();
    }
    else
    {
        PHOEDT_CUI_DISPLAY_POPUP_CONFIRM(
            g_phoedt_cui_cntx_p->cui_gid,
            GetString(STR_ID_PHOEDT_NOTIFY_EXIT_CONFIRM),
            PHOEDT_CONFIRM_TYPE_EXIT);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_matrix_selector_highlight_hdlr
* DESCRIPTION
*  cui_phoedt_matrix_selector_highlight_hdlr
* PARAMETERS
*  idx      [IN]    highlight index
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_matrix_selector_highlight_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->item_selector.select_idx = idx;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_matrix_selector_draw_image_callback
* DESCRIPTION
*  cui_phoedt_matrix_selector_draw_image_callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_matrix_selector_draw_image_callback(
                S32         idx,
                S32         page_start_idx,
                S32         page_end_idx,
                MMI_BOOL    is_hilighted,
                MMI_BOOL    is_need_update,
                MMI_BOOL    is_new_page,
                S32         x1,
                S32         y1,
                S32         x2,
                S32         y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         image_width;
    S32         image_height;
    S32         resized_image_width;
    S32         resized_image_height;
    S32         offset_x;
    S32         offset_y;
    U16         image_id;
    S32         box_width;
    S32         box_height;

#ifdef __MMI_PHOEDT_DOODLE__
    U32         color_R;
    U32         color_G;
    U32         color_B;
#endif /* #ifdef __MMI_PHOEDT_DOODLE__ */

    GDI_HANDLE  act_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_TRUE == is_need_update && NULL != g_phoedt_cui_cntx_p)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);

        box_width = x2 - x1 + 1;
        box_height = y2 - y1 + 1;

        switch(g_phoedt_cui_cntx_p->curr_act.action)
        {
        case PHOEDT_ACTION_TYPE_ICON:
            {
                image_id = PHOEDT_CUI_SMALL_ICON_ID(idx);
                gdi_image_get_dimension_id(image_id, &image_width, &image_height);

                gdi_util_fit_box(
                    GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT,
                    box_width, box_height, image_width, image_height,
                    &offset_x, &offset_y, &resized_image_width, &resized_image_height);

                gdi_layer_get_active(&act_handle);
                gdi_image_draw_resized_id(
                    offset_x + x1, offset_y + y1,
                    resized_image_width, resized_image_height, image_id);
            }
            break;

    #ifdef __MMI_PHOEDT_DOODLE__
        case PHOEDT_ACTION_TYPE_DOODLE:
            {
                image_id = IMG_ID_PHOEDT_DOODLE_COLOR_ICON;
                gdi_image_get_dimension_id(image_id, &image_width, &image_height);

                offset_x = ((box_width - image_width) >> 1) + x1;
                offset_y = ((box_height - image_height) >> 1) + y1;

                color_R = g_phoedt_doodle_line_color_list[idx].r;
                color_G = g_phoedt_doodle_line_color_list[idx].g;
                color_B = g_phoedt_doodle_line_color_list[idx].b;

                gdi_draw_frame_rect(
                    offset_x,
                    offset_y,
                    offset_x + image_width,
                    offset_y + image_height,
                    gdi_act_color_from_rgb(255, color_R, color_G, color_B),
                    PHOEDT_IMAGE_BORDER_COLOR,
                    PHOEDT_IMAGE_BORDER_WIDTH);
            }
            break;
    #endif /* #ifdef __MMI_PHOEDT_DOODLE__ */

        default:
            MMI_ASSERT(0);
        }

        gdi_layer_pop_clip();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_matrix_selector_select_hdlr
* DESCRIPTION
*  select a matrix icon handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_matrix_selector_select_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result      ies_ret     = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_phoedt_cui_cntx_p->curr_act.action)
    {
    case PHOEDT_ACTION_TYPE_ICON:
        {
            g_phoedt_cui_cntx_p->curr_act.para.icon.icon_idx = g_phoedt_cui_cntx_p->item_selector.select_idx;
            cui_phoedt_entry_edit_screen();
        }
        break;

#ifdef __MMI_PHOEDT_DOODLE__
    case PHOEDT_ACTION_TYPE_DOODLE:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SET_LINE_COLOR,
                g_phoedt_cui_cntx_p->item_selector.select_idx,
                g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->item_selector.select_idx].r,
                g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->item_selector.select_idx].g,
                g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->item_selector.select_idx].b);

            ies_ret = srv_ies_doodle_set_color(
                g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle,
                g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->item_selector.select_idx].r,
                g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->item_selector.select_idx].g,
                g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->item_selector.select_idx].b);

            if(MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT(ies_ret))
            {
                g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx = g_phoedt_cui_cntx_p->item_selector.select_idx;
            }
            mmi_frm_scrn_close_active_id();
        }
        break;
#endif /* #ifdef __MMI_PHOEDT_DOODLE__ */

    default:
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_matrix_selector_cancel_hdlr
* DESCRIPTION
*  RSK handler of matrix selector
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_matrix_selector_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_phoedt_cui_cntx_p->curr_act.action)
    {
    case PHOEDT_ACTION_TYPE_ICON:
#ifdef __MMI_PHOEDT_DOODLE__
    case PHOEDT_ACTION_TYPE_DOODLE:
#endif /* #ifdef __MMI_PHOEDT_DOODLE__ */
        {
            mmi_frm_scrn_close_active_id();
        }
        break;

    default:
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_cui_screens
* DESCRIPTION
*  entry edit screen, including all screens in which user can preview the changed image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_cui_screens(phoedt_cui_run_para_struct *run_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phoedt_cui_cntx_p->cui_gid = run_para->self_gid;
    mmi_wcscpy(g_phoedt_cui_cntx_p->org_file.filepath, run_para->filepath_buf);
    g_phoedt_cui_cntx_p->send_cntx.is_available = run_para->is_send_available;

    mmi_frm_group_enter(g_phoedt_cui_cntx_p->cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_LOADING;
    cui_phoedt_create_preview_layer();
    cui_phoedt_entry_main_screen();
    cui_phoedt_create_ies_resource();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_edit_screen
* DESCRIPTION
*  entry edit screen, including all screens in which user can preview the changed image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_edit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8     gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_enter_edit_group();

    if(MMI_FALSE == mmi_frm_scrn_enter(
        GRP_ID_PHOEDT_EDIT_GROUP,
        SCR_ID_PHOEDT_EDIT,
        cui_phoedt_exit_edit_screen,
        cui_phoedt_entry_edit_screen,
        MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* MAUI_02729116, when entry should reset key and pen status */
    cui_phoedt_reset_interact_item_state();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    cui_phoedt_create_osd_layer();
    gdi_layer_set_blt_layer(
        g_phoedt_cui_cntx_p->preview_layer,
        g_phoedt_cui_cntx_p->osd_layer,
        GDI_LAYER_EMPTY_HANDLE, GDI_LAYER_EMPTY_HANDLE);

    cui_phoedt_set_key_proc(GRP_ID_PHOEDT_EDIT_GROUP, SCR_ID_PHOEDT_EDIT);
    cui_phoedt_set_pen_hdlrs();

    if(NULL == gui_buffer)
    {
        if(MMI_FALSE == cui_phoedt_start_curr_change())
        {
            cui_phoedt_close_edit_group();
            return;
        }
    }

#ifdef __MMI_TOUCH_SCREEN__
    cui_phoedt_config_pen_config_sampling_period();
#endif /* __MMI_TOUCH_SCREEN__ */

    cui_phoedt_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_entry_help_screen
* DESCRIPTION
*  entry help screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_entry_help_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR   *buffer;
    S32     buffer_size;
    PU8     gui_buffer;
    U16     info_id = 0;
    U16     title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_enter_edit_group();

    if(MMI_FALSE == mmi_frm_scrn_enter(
        GRP_ID_PHOEDT_EDIT_GROUP,
        SCR_ID_PHOEDT_EDIT,
        NULL,
        cui_phoedt_entry_help_screen,
        MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    switch(g_phoedt_cui_cntx_p->curr_act.para.help.item)
    {
    case MENU_ID_PHOEDT_SAVE_HELP:
        {
            info_id = STR_ID_PHOEDT_HELP_SAVE_INFO;
            title_id = STR_ID_PHOEDT_SAVE_AS;
        }
        break;

    case MENU_ID_PHOEDT_SEND_HELP:
        {
            info_id = STR_ID_PHOEDT_HELP_SEND_INFO;
            title_id = STR_GLOBAL_SEND;
        }
        break;

    case MENU_ID_PHOEDT_EFFECT_HELP:
        {
            info_id = STR_ID_PHOEDT_HELP_EFFECT_INFO;
            title_id = STR_ID_PHOEDT_ADD_EFFECT;
        }
        break;

    case MENU_ID_PHOEDT_FRAME_HELP:
        {
            info_id = STR_ID_PHOEDT_HELP_FRAME_INFO;
            title_id = STR_ID_PHOEDT_ADD_FRAME;
        }
        break;

    case MENU_ID_PHOEDT_ICON_HELP:
        {
            info_id = STR_ID_PHOEDT_HELP_ICON_INFO;
            title_id = STR_ID_PHOEDT_ADD_ICON;
        }
        break;

    case MENU_ID_PHOEDT_CLIP_HELP:
        {
        #ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
            info_id = STR_ID_PHOEDT_HELP_CLIP_INFO_FTE;
        #else
            info_id = STR_ID_PHOEDT_HELP_CLIP_INFO;
        #endif
            title_id = STR_ID_PHOEDT_CLIP;
        }
        break;

#ifdef __MMI_PHOEDT_DOODLE__
    case MENU_ID_PHOEDT_DOODLE_HELP:
        {
        #ifdef __MMI_PHOEDT_STYLE_FTE__
            info_id = STR_ID_PHOEDT_HELP_DOODLE_INFO_FTE;
        #else
            info_id = STR_ID_PHOEDT_HELP_DOODLE_INFO;
        #endif
            title_id = STR_ID_PHOEDT_DOODLE;
        }
        break;
#endif

    default:
        break;
    }

    buffer = (WCHAR*)GetString(info_id);
    buffer_size = mmi_wcslen(buffer);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory74Screen(
        title_id,
        GetRootTitleIcon(MENU_ID_PHOEDT_APP),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) buffer,
        buffer_size,
        gui_buffer);

    /* go back to help list screen */
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_exit_edit_screen
* DESCRIPTION
*  exit edit screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_exit_edit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == g_phoedt_cui_cntx_p)
    {
        /* photo editor already not exist, then do nothing */
        return;
    }

#ifdef __MMI_TOUCH_SCREEN__
    cui_phoedt_restore_pen_config_sampling_period();
#endif /* __MMI_TOUCH_SCREEN__ */

    cui_phoedt_stop_move_element_timers();

    /* MAUI_02729116, when exit should reset key and pen status,
    then draw new osd on the layer and flatten to base */
    cui_phoedt_reset_interact_item_state();

    cui_phoedt_draw_osd();

    gdi_layer_flatten_previous_to_base();

    cui_phoedt_free_osd_layer();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_stop_move_element_timers
* DESCRIPTION
*  stop the timers which used to move icon, image, clip rect
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_stop_move_element_timers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(cui_phoedt_clip_move_cyclic);
    gui_cancel_timer(cui_phoedt_icon_move_cyclic);
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_create_preview_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(GDI_LAYER_EMPTY_HANDLE == g_phoedt_cui_cntx_p->preview_layer)
    {
        gdi_layer_create_cf_using_outside_memory(
            PHOEDT_CURRENT_COLOR_FORMAT,
            0, 0, UI_device_width, UI_device_height,
            &g_phoedt_cui_cntx_p->preview_layer, g_phoedt_cui_cntx_p->preview_buf, PHOEDT_FRAME_BUFFER_SIZE);
    }
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_free_preview_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(GDI_LAYER_EMPTY_HANDLE != g_phoedt_cui_cntx_p->preview_layer)
    {
        gdi_layer_free(g_phoedt_cui_cntx_p->preview_layer);
        g_phoedt_cui_cntx_p->preview_layer = GDI_LAYER_EMPTY_HANDLE;
    }
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_create_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(GDI_LAYER_EMPTY_HANDLE == g_phoedt_cui_cntx_p->osd_layer)
    {
        gdi_layer_create_cf(
            PHOEDT_CURRENT_COLOR_FORMAT,
            0, 0, UI_device_width, UI_device_height,
            &g_phoedt_cui_cntx_p->osd_layer);

        /* TODO: cause this layer maybe blt out before call draw_osd,
        so clear it to transparent to show preview layer in this case */
        gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
* FUNCTION
*
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_free_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(GDI_LAYER_EMPTY_HANDLE != g_phoedt_cui_cntx_p->osd_layer)
    {
        gdi_layer_free(g_phoedt_cui_cntx_p->osd_layer);
        g_phoedt_cui_cntx_p->osd_layer = GDI_LAYER_EMPTY_HANDLE;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_osd
* DESCRIPTION
*  draw screen's osd, change list 116035 has change the FTE osd, not draw fake bg on osd layer
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == g_phoedt_cui_cntx_p)
    {
        return;
    }

    if (NULL != g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].draw_osd)
        g_phoedt_action_hdlrs[g_phoedt_cui_cntx_p->curr_act.action].draw_osd();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_main_osd
* DESCRIPTION
*  draw main screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_main_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID  lsk_id = STR_GLOBAL_OPTIONS;
    MMI_STR_ID  rsk_id = STR_GLOBAL_EXIT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_MAIN != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    cui_phoedt_draw_image_border();

    if (PHOEDT_ACTION_TYPE_LOADING == g_phoedt_cui_cntx_p->curr_act.action)
    {
        lsk_id = PHOEDT_RES_DUMMY_ID;
        rsk_id = STR_GLOBAL_CANCEL;
    }

    CUI_PHOEDT_DRAW_SOFTKEY(lsk_id, rsk_id, MMI_FALSE, IMG_GLOBAL_SAVE_CSK);

    cui_phoedt_draw_title(STR_ID_PHOEDT_APP_NAME, MMI_FALSE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_add_icon_osd
* DESCRIPTION
*  draw add icon screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_add_icon_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            is_sel;
    S32                 icon_x1;
    S32                 icon_y1;
    S32                 icon_x2;
    S32                 icon_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    /* one pixel larger then the icon on every side */
    icon_x1 = g_phoedt_cui_cntx_p->curr_act.para.icon.location.x;
    icon_y1 = g_phoedt_cui_cntx_p->curr_act.para.icon.location.y;
    icon_x2 = icon_x1 + g_phoedt_cui_cntx_p->curr_act.para.icon.size - 1;
    icon_y2 = icon_y1 + g_phoedt_cui_cntx_p->curr_act.para.icon.size - 1;

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    cui_phoedt_draw_image_border();

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->preview_layer);
    /* draw icon border */
#ifdef __MMI_TOUCH_SCREEN__
    if(cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ICON_ICON))
    {
        /* add border for icon when drag it */
        S32 i;
        for (i = 0; i < PHOEDT_ICON_BORDER_WIDTH; i++)
        {
            gdi_draw_rect(icon_x1 + i, icon_y1 + i, icon_x2 - i, icon_y2 - i, PHOEDT_ICON_BORDER_COLOR);
        }
    }
    else
#endif /* __MMI_TOUCH_SCREEN__ */
    {
        /* show only four corners */
        /* left-top horizontal */
        gdi_draw_solid_rect(
            icon_x1, icon_y1,
            icon_x1 + PHOEDT_ICON_BORDER_CORNER_LENGH - 1, icon_y1 + PHOEDT_ICON_BORDER_WIDTH - 1,
            PHOEDT_ICON_BORDER_COLOR);

        /* left-top vertical */
        gdi_draw_solid_rect(
            icon_x1, icon_y1 + PHOEDT_ICON_BORDER_WIDTH, icon_x1 + PHOEDT_ICON_BORDER_WIDTH - 1,
            icon_y1 + PHOEDT_ICON_BORDER_CORNER_LENGH - 1,
            PHOEDT_ICON_BORDER_COLOR);

        /* right-top horizontal */
        gdi_draw_solid_rect(
            icon_x2 - PHOEDT_ICON_BORDER_CORNER_LENGH + 1, icon_y1,
            icon_x2, icon_y1 + PHOEDT_ICON_BORDER_WIDTH - 1,
            PHOEDT_ICON_BORDER_COLOR);

        /* right-top vertical */
        gdi_draw_solid_rect(
            icon_x2 - PHOEDT_ICON_BORDER_WIDTH + 1, icon_y1 + PHOEDT_ICON_BORDER_WIDTH,
            icon_x2, icon_y1 + PHOEDT_ICON_BORDER_CORNER_LENGH - 1,
            PHOEDT_ICON_BORDER_COLOR);

        /* left-bottom horizontal */
        gdi_draw_solid_rect(
            icon_x1, icon_y2 - PHOEDT_ICON_BORDER_WIDTH + 1,
            icon_x1 + PHOEDT_ICON_BORDER_CORNER_LENGH - 1, icon_y2,
            PHOEDT_ICON_BORDER_COLOR);

        /* left-bottom vertical */
        gdi_draw_solid_rect(
            icon_x1, icon_y2 - PHOEDT_ICON_BORDER_CORNER_LENGH + 1,
            icon_x1 + PHOEDT_ICON_BORDER_WIDTH - 1, icon_y2 - PHOEDT_ICON_BORDER_WIDTH,
            PHOEDT_ICON_BORDER_COLOR);

        /* right-bottom horizontal */
        gdi_draw_solid_rect(
            icon_x2 - PHOEDT_ICON_BORDER_CORNER_LENGH + 1, icon_y2 - PHOEDT_ICON_BORDER_WIDTH + 1,
            icon_x2, icon_y2,
            PHOEDT_ICON_BORDER_COLOR);

        /* right-bottom vertical */
        gdi_draw_solid_rect(
            icon_x2 - PHOEDT_ICON_BORDER_WIDTH + 1, icon_y2 - PHOEDT_ICON_BORDER_CORNER_LENGH + 1,
            icon_x2, icon_y2 - PHOEDT_ICON_BORDER_WIDTH,
            PHOEDT_ICON_BORDER_COLOR);
    }
    gdi_layer_pop_and_restore_active();
    
    /* draw "R" */
    if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_ICON_ROTATE)
#ifdef __MMI_TOUCH_SCREEN__
    || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ICON_ROTATE)
#endif /* __MMI_TOUCH_SCREEN__ */
    )
    {
        is_sel = MMI_TRUE;
    }
    else
    {
        is_sel = MMI_FALSE;
    }
    cui_phoedt_draw_button(
        g_phoedt_layout.button_31.x, 
        g_phoedt_layout.button_31.y, 
        g_phoedt_layout.button_size.w, 
        g_phoedt_layout.button_size.h, 
        IMG_ID_PHOEDT_ROTATE_RIGHT_ICON,
        is_sel);

    /* draw "+" */
    if(g_phoedt_cui_cntx_p->curr_act.para.icon.max == g_phoedt_cui_cntx_p->curr_act.para.icon.size)
    {
        cui_phoedt_draw_button(
            g_phoedt_layout.button_32.x, 
            g_phoedt_layout.button_32.y, 
            g_phoedt_layout.button_size.w, 
            g_phoedt_layout.button_size.h, 
            IMG_ID_PHOEDT_SCALE_UP_ICON_DISABLE,
            MMI_FALSE);
    }
    else 
    {
        if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_ZOOM_IN)
    #ifdef __MMI_TOUCH_SCREEN__
        || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ICON_ZOOMIN)
    #endif /* __MMI_TOUCH_SCREEN__ */
        )
        {
            is_sel = MMI_TRUE;
        }
        else
        {
            is_sel = MMI_FALSE;
        }
        cui_phoedt_draw_button(
            g_phoedt_layout.button_32.x, 
            g_phoedt_layout.button_32.y, 
            g_phoedt_layout.button_size.w, 
            g_phoedt_layout.button_size.h, 
            IMG_ID_PHOEDT_SCALE_UP_ICON,
            is_sel);
    }

    /* draw "-" */
    if(g_phoedt_cui_cntx_p->curr_act.para.icon.min == g_phoedt_cui_cntx_p->curr_act.para.icon.size)
    {
        cui_phoedt_draw_button(
            g_phoedt_layout.button_33.x, 
            g_phoedt_layout.button_33.y, 
            g_phoedt_layout.button_size.w, 
            g_phoedt_layout.button_size.h, 
            IMG_ID_PHOEDT_SCALE_DOWN_ICON_DISABLE,
            MMI_FALSE);
    }
    else 
    {
        if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_ZOOM_OUT)
    #ifdef __MMI_TOUCH_SCREEN__
        || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ICON_ZOOMOUT)
    #endif /* __MMI_TOUCH_SCREEN__ */
        )
        {
            is_sel = MMI_TRUE;
        }
        else
        {
            is_sel = MMI_FALSE;
        }
        cui_phoedt_draw_button(
            g_phoedt_layout.button_33.x, 
            g_phoedt_layout.button_33.y, 
            g_phoedt_layout.button_size.w, 
            g_phoedt_layout.button_size.h, 
            IMG_ID_PHOEDT_SCALE_DOWN_ICON,
            is_sel);
    }

    CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);

    cui_phoedt_draw_title(STR_ID_PHOEDT_ADD_ICON, MMI_TRUE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_add_effect_osd
* DESCRIPTION
*  draw add effect screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_add_effect_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_effect_struct    *curr_effect = cui_phoedt_get_curr_effect_item();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    cui_phoedt_draw_image_border();

    CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);

    cui_phoedt_draw_title(STR_ID_PHOEDT_ADD_EFFECT, MMI_TRUE, curr_effect->name, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_add_frame_osd
* DESCRIPTION
*  draw add frame screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_add_frame_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    cui_phoedt_draw_image_border();

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->osd_layer);

    CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);

    cui_phoedt_draw_title(
        STR_ID_PHOEDT_ADD_FRAME, MMI_TRUE,
        STR_ID_PHOEDT_FRAME_START + 1 + g_phoedt_cui_cntx_p->curr_act.para.frame.frame_idx,
        MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}


#ifdef __MMI_PHOEDT_STYLE_FTE__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_adjust_osd
* DESCRIPTION
*  draw adjust screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_adjust_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_adjust_struct        *curr_adjust            = cui_phoedt_get_curr_adjust_item();
    U16                         curr_item_idx;
    phoedt_rect_struct          icon_rect;
    phoedt_rect_struct          bar_rect;
    U16                         bar_margin              = g_phoedt_layout.adjust_bar_margin;
    S16                         slider_offset_y_on_bar  = g_phoedt_layout.adjust_slider_off_y_on_bar;
    phoedt_pos_struct           slider_offset;
    phoedt_adjust_range_struct  curr_para;
    S32                         idx;
    MMI_STR_ID                  name;
    MMI_IMG_ID                  icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_item_idx = g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx;

    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    cui_phoedt_draw_image_border();

    for(idx = 0; idx < curr_adjust->para_count; idx++)
    {        
        icon_rect = cui_phoedt_get_adjust_static_obj_rect(PHOEDT_ADJUST_STATIC_OBJ_TYPE_BG, idx);
        if(idx == curr_item_idx)
        {
            icon = IMG_ID_PHOEDT_ADJUST_BAR_HL;
        }
        else
        {
            icon = IMG_ID_PHOEDT_ADJUST_BAR_BG;
        }
        gdi_image_draw_resized_id(
            icon_rect.offset.x, 
            icon_rect.offset.y,
            icon_rect.size.w, 
            icon_rect.size.h,
            icon);

        gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->osd_layer);
        /* draw icon */
        icon_rect = cui_phoedt_get_adjust_static_obj_rect(PHOEDT_ADJUST_STATIC_OBJ_TYPE_ICON, idx);
        cui_phoedt_draw_button(
            icon_rect.offset.x, 
            icon_rect.offset.y,
            icon_rect.size.w, 
            icon_rect.size.h,
            curr_adjust->para_items[idx].icon,
            MMI_FALSE);
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

    name = curr_adjust->para_items[curr_item_idx].name;
    curr_para = curr_adjust->para_items[curr_item_idx].para;

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->osd_layer);
    /* draw the bar */
    bar_rect = cui_phoedt_get_adjust_static_obj_rect(PHOEDT_ADJUST_STATIC_OBJ_TYPE_BAR, curr_item_idx);
    gdi_image_draw_resized_id(
        bar_rect.offset.x,
        bar_rect.offset.y,
        bar_rect.size.w,
        bar_rect.size.h,
        IMG_ID_PHOEDT_ADJUST_BAR);

    /* draw the slider */
    slider_offset.x = bar_rect.offset.x + bar_margin - g_phoedt_layout.adjust_slider_size.w / 2 +
        (curr_para.value - curr_para.min) * (bar_rect.size.w - bar_margin * 2) / (curr_para.max - curr_para.min);

    slider_offset.y = bar_rect.offset.y + slider_offset_y_on_bar;

    if(MMI_TRUE == cui_phoedt_is_key_pressed(KEY_LEFT_ARROW) ||
       MMI_TRUE == cui_phoedt_is_key_pressed(KEY_RIGHT_ARROW)
#ifdef __MMI_TOUCH_SCREEN__
    || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ADJUST_SLIDER)
#endif /* __MMI_TOUCH_SCREEN__ */
    )
    {
    #ifdef __MMI_PHOEDT_STYLE_FTE__
        icon = IMG_ID_PHOEDT_ADJUST_SLIDER_SEL;
    #else /* __MMI_PHOEDT_STYLE_FTE__ */
        icon = IMG_ID_PHOEDT_ADJUST_SLIDER;
    #endif /* __MMI_PHOEDT_STYLE_FTE__ */
    }
    else
    {
        icon = IMG_ID_PHOEDT_ADJUST_SLIDER;
    }
    gdi_image_draw_id(
        slider_offset.x,
        slider_offset.y,
        icon);
    gdi_pop_and_restore_alpha_blending_source_layer();

#ifdef __MMI_TOUCH_SCREEN__
    g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.adjust_slider.pos_x = slider_offset.x;
    g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.adjust_slider.pos_y = slider_offset.y;
    g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.adjust_slider.width = g_phoedt_layout.adjust_slider_size.w;
    g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.adjust_slider.height = g_phoedt_layout.adjust_slider_size.h;
#endif /* __MMI_TOUCH_SCREEN__ */

    CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);

    cui_phoedt_draw_title(name, MMI_TRUE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}


#else /* __MMI_PHOEDT_STYLE_FTE__ */
/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_adjust_osd
* DESCRIPTION
*  draw adjust screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_adjust_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_adjust_struct        *curr_adjust            = cui_phoedt_get_curr_adjust_item();
    U16                         curr_item_idx;
    phoedt_rect_struct          icon_rect;
    phoedt_rect_struct          bar_rect;
    U16                         bar_margin              = g_phoedt_layout.adjust_bar_margin;
    S16                         slider_offset_y_on_bar  = g_phoedt_layout.adjust_slider_off_y_on_bar;
    phoedt_pos_struct           slider_offset;
    phoedt_adjust_range_struct  curr_para;
    S32                         idx;
    MMI_STR_ID                  name;
    MMI_BOOL                    is_sel;
    MMI_IMG_ID                  icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_item_idx = g_phoedt_cui_cntx_p->curr_act.para.adjust.curr_item_idx;

    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    cui_phoedt_draw_image_border();

    for(idx = 0; idx < curr_adjust->para_count; idx++)
    {
        /* draw icon before the bar and slider */
        icon_rect = cui_phoedt_get_adjust_static_obj_rect(PHOEDT_ADJUST_STATIC_OBJ_TYPE_ICON, idx);

        if(idx == curr_item_idx)
        {
            is_sel = MMI_TRUE;
        }
        else
        {
            is_sel = MMI_FALSE;
        }
        cui_phoedt_draw_button(
            icon_rect.offset.x, 
            icon_rect.offset.y,
            icon_rect.size.w, 
            icon_rect.size.h,
            curr_adjust->para_items[idx].icon,
            is_sel);
    }

    name = curr_adjust->para_items[curr_item_idx].name;
    curr_para = curr_adjust->para_items[curr_item_idx].para;

    /* draw the bar */
    bar_rect = cui_phoedt_get_adjust_static_obj_rect(PHOEDT_ADJUST_STATIC_OBJ_TYPE_BAR, curr_item_idx);
    gdi_image_draw_id(
        bar_rect.offset.x,
        bar_rect.offset.y,
        IMG_ID_PHOEDT_ADJUST_BAR);

    /* draw the slider */
    slider_offset.x = bar_rect.offset.x + bar_margin - g_phoedt_layout.adjust_slider_size.w / 2 +
        (curr_para.value - curr_para.min) * (bar_rect.size.w - bar_margin * 2) / (curr_para.max - curr_para.min);

    slider_offset.y = bar_rect.offset.y + slider_offset_y_on_bar;

    if(MMI_TRUE == cui_phoedt_is_key_pressed(KEY_LEFT_ARROW) ||
       MMI_TRUE == cui_phoedt_is_key_pressed(KEY_RIGHT_ARROW)
#ifdef __MMI_TOUCH_SCREEN__
    || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ADJUST_SLIDER)
#endif /* __MMI_TOUCH_SCREEN__ */
    )
    {
    #ifdef __MMI_PHOEDT_STYLE_FTE__
        icon = IMG_ID_PHOEDT_ADJUST_SLIDER_SEL;
    #else /* __MMI_PHOEDT_STYLE_FTE__ */
        icon = IMG_ID_PHOEDT_ADJUST_SLIDER;
    #endif /* __MMI_PHOEDT_STYLE_FTE__ */
    }
    else
    {
        icon = IMG_ID_PHOEDT_ADJUST_SLIDER;
    }
    gdi_image_draw_id(
        slider_offset.x,
        slider_offset.y,
        icon);

#ifdef __MMI_TOUCH_SCREEN__
    g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.adjust_slider.pos_x = slider_offset.x;
    g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.adjust_slider.pos_y = slider_offset.y;
    g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.adjust_slider.width = g_phoedt_layout.adjust_slider_size.w;
    g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.adjust_slider.height = g_phoedt_layout.adjust_slider_size.h;
#endif /* __MMI_TOUCH_SCREEN__ */

    CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);

    cui_phoedt_draw_title(name, MMI_TRUE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}
#endif /* __MMI_PHOEDT_STYLE_FTE__ */


#ifdef __MMI_PHOEDT_STYLE_FTE_CLIP__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_init_clip_osd_indicators
* DESCRIPTION
*  FTE ONLY: init clip osd indicators coordinate
* PARAMETERS
*  None
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_init_clip_osd_indicators(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                         rect_x1;
    S32                         rect_y1;
    S32                         rect_x2;
    S32                         rect_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rect_x1 = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.x;
    rect_y1 = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.y;
    rect_x2 = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.x +
        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w - 1;
    rect_y2 = g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.y +
        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h - 1;

    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTUP))
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].pos_x =
            rect_x1 - (g_phoedt_layout.clip_indicator_sel_size.w / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].pos_y =
            rect_y1 - (g_phoedt_layout.clip_indicator_sel_size.h / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].width =
            g_phoedt_layout.clip_indicator_sel_size.w;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].height =
            g_phoedt_layout.clip_indicator_sel_size.h;
        }
    else
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].pos_x =
            rect_x1 - (g_phoedt_layout.clip_indicator_size.w / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].pos_y =
            rect_y1 - (g_phoedt_layout.clip_indicator_size.h / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].width =
            g_phoedt_layout.clip_indicator_size.w;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].height =
            g_phoedt_layout.clip_indicator_size.h;
    }

    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN))
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].pos_x =
            rect_x1 - (g_phoedt_layout.clip_indicator_sel_size.w / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].pos_y =
            rect_y2 - (g_phoedt_layout.clip_indicator_sel_size.h / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].width =
            g_phoedt_layout.clip_indicator_sel_size.w;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].height =
            g_phoedt_layout.clip_indicator_sel_size.h;
    }
    else
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].pos_x =
            rect_x1 - (g_phoedt_layout.clip_indicator_size.w / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].pos_y =
            rect_y2 - (g_phoedt_layout.clip_indicator_size.h / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].width =
            g_phoedt_layout.clip_indicator_size.w;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].height =
            g_phoedt_layout.clip_indicator_size.h;
    }

    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP))
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].pos_x =
            rect_x2 - (g_phoedt_layout.clip_indicator_sel_size.w / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].pos_y =
            rect_y1 - (g_phoedt_layout.clip_indicator_sel_size.h / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].width =
            g_phoedt_layout.clip_indicator_sel_size.w;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].height =
            g_phoedt_layout.clip_indicator_sel_size.h;
    }
    else
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].pos_x =
            rect_x2 - (g_phoedt_layout.clip_indicator_size.w / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].pos_y =
            rect_y1 - (g_phoedt_layout.clip_indicator_size.h / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].width =
            g_phoedt_layout.clip_indicator_size.w;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].height =
            g_phoedt_layout.clip_indicator_size.h;
    }

    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN))
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].pos_x =
            rect_x2 - (g_phoedt_layout.clip_indicator_sel_size.w / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].pos_y =
            rect_y2 - (g_phoedt_layout.clip_indicator_sel_size.h / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].width =
            g_phoedt_layout.clip_indicator_sel_size.w;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].height =
            g_phoedt_layout.clip_indicator_sel_size.h;
    }
    else
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].pos_x =
            rect_x2 - (g_phoedt_layout.clip_indicator_size.w / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].pos_y =
            rect_y2 - (g_phoedt_layout.clip_indicator_size.h / 2);
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].width =
            g_phoedt_layout.clip_indicator_size.w;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].height =
            g_phoedt_layout.clip_indicator_size.h;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_clip_osd_indicators
* DESCRIPTION
*  FTE ONLY: clip osd indicators
* PARAMETERS
*  None
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_clip_osd_indicators(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_IMG_ID          icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTUP))
    {
        icon = IMG_ID_PHOEDT_CLIP_INDICATOR_SEL;
    }
    else
    {
        icon = IMG_ID_PHOEDT_CLIP_INDICATOR;
    }
    gdi_image_draw_id(
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].pos_x,
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTUP].pos_y,
        icon);

    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_LEFTDOWN))
    {
        icon = IMG_ID_PHOEDT_CLIP_INDICATOR_SEL;
    }
    else
    {
        icon = IMG_ID_PHOEDT_CLIP_INDICATOR;
    }
    gdi_image_draw_id(
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].pos_x,
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_LEFTDOWN].pos_y,
        icon);

    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTUP))
    {
        icon = IMG_ID_PHOEDT_CLIP_INDICATOR_SEL;
    }
    else
    {
        icon = IMG_ID_PHOEDT_CLIP_INDICATOR;
    }
    gdi_image_draw_id(
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].pos_x,
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTUP].pos_y,
        icon);

    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RIGHTDOWN))
    {
        icon = IMG_ID_PHOEDT_CLIP_INDICATOR_SEL;
    }
    else
    {
        icon = IMG_ID_PHOEDT_CLIP_INDICATOR;
    }
    gdi_image_draw_id(
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].pos_x,
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.clip_indicators[PHOEDT_CLIP_INDICATOR_RIGHTDOWN].pos_y,
        icon);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_clip_osd
* DESCRIPTION
*  FTE ONLY: clip osd
* PARAMETERS
*  None
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_clip_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    cui_phoedt_init_clip_osd_indicators();

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    /* for blending image bg around the indicators */
    cui_phoedt_draw_clip_osd_indicators();

    /* mask *******************************************************************/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        g_phoedt_cui_cntx_p->display_info.img_rect.offset.x,
        g_phoedt_cui_cntx_p->display_info.img_rect.offset.y,
        g_phoedt_cui_cntx_p->display_info.img_rect.offset.x + g_phoedt_cui_cntx_p->display_info.img_rect.size.w - 1,
        g_phoedt_cui_cntx_p->display_info.img_rect.offset.y + g_phoedt_cui_cntx_p->display_info.img_rect.size.h - 1);
    gdi_image_draw_id(0, 0, IMG_ID_PHOEDT_CLIP_MASK);
    gdi_layer_pop_clip();

    /* border *******************************************************************/
    cui_phoedt_draw_image_border();

    /* transparent rect*******************************************************/
    gdi_image_draw_resized_id(
        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.x,
        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.y,
        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w,
        g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h,
        IMG_ID_PHOEDT_CLIP_FRAME);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->osd_layer);
    cui_phoedt_draw_clip_osd_indicators();
    gdi_pop_and_restore_alpha_blending_source_layer();

    CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);

    cui_phoedt_draw_title(STR_ID_PHOEDT_CLIP, MMI_TRUE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_layer_pop_and_restore_active();
}


#else /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */
/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_clip_osd
* DESCRIPTION
*  draw clip screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_clip_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16                 rect_width;
    MMI_BOOL            is_sel;
    S32                 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }
    
    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    cui_phoedt_draw_image_border();

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || defined(__MMI_PHOEDT_STYLE_FTE__)
    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);
    gdi_layer_flatten(g_phoedt_cui_cntx_p->preview_layer, 0, 0, 0);
    gdi_layer_pop_and_restore_active();
    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->osd_layer);
#else
    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);
#endif

#ifdef __MMI_TOUCH_SCREEN__
    if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_RECT))
    {
        rect_width = PHOEDT_CLIP_RECT_WIDTH_SEL;
    }
    else
#endif /* __MMI_TOUCH_SCREEN__ */
    {
        rect_width = PHOEDT_CLIP_RECT_WIDTH;
    }

    for (i = 0; i < rect_width; i++)
    {
        gdi_draw_rect(
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.x + i,
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.y + i,
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.x + g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.w - 1 - i,
            g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.offset.y + g_phoedt_cui_cntx_p->curr_act.para.clip.clip_rect.size.h - 1 - i,
            PHOEDT_CLIP_RECT_COLOR);
    }

    if(PHOEDT_CLIP_TYPE_FIX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.clip_type)
    {
        /* draw scale up icon */
        if(PHOEDT_CLIP_RECT_MAX_RATIO == g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio)
        {
            cui_phoedt_draw_button(
                g_phoedt_layout.button_21.x, 
                g_phoedt_layout.button_21.y, 
                g_phoedt_layout.button_size.w,
                g_phoedt_layout.button_size.h,
                IMG_ID_PHOEDT_SCALE_UP_ICON_DISABLE,
                MMI_FALSE);
        }
        else 
        {
            if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_ZOOM_IN)
        #ifdef __MMI_TOUCH_SCREEN__
            || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_ZOOMIN)
        #endif /* __MMI_TOUCH_SCREEN__ */
            )
            {
                is_sel = MMI_TRUE;
            }
            else
            {
                is_sel = MMI_FALSE;
            }
            cui_phoedt_draw_button(
                g_phoedt_layout.button_21.x, 
                g_phoedt_layout.button_21.y, 
                g_phoedt_layout.button_size.w,
                g_phoedt_layout.button_size.h,
                IMG_ID_PHOEDT_SCALE_UP_ICON,
                is_sel);
        }

        /* draw scale down icon */
        if(g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.curr_min_ratio ==
           g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_ratio.scale_ratio)
        {
            cui_phoedt_draw_button(
                g_phoedt_layout.button_22.x, 
                g_phoedt_layout.button_22.y, 
                g_phoedt_layout.button_size.w,
                g_phoedt_layout.button_size.h,
                IMG_ID_PHOEDT_SCALE_DOWN_ICON_DISABLE,
                MMI_FALSE);
        }
        else
        {
            if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_ZOOM_OUT)
        #ifdef __MMI_TOUCH_SCREEN__
            || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_ZOOMOUT)
        #endif /* __MMI_TOUCH_SCREEN__ */
            )
            {
                is_sel = MMI_TRUE;
            }
            else
            {
                is_sel = MMI_FALSE;
            }
            cui_phoedt_draw_button(
                g_phoedt_layout.button_22.x, 
                g_phoedt_layout.button_22.y, 
                g_phoedt_layout.button_size.w,
                g_phoedt_layout.button_size.h,
                IMG_ID_PHOEDT_SCALE_DOWN_ICON,
                is_sel);
        }
    }
    else
    {
        MMI_IMG_ID  icon;
        if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_MANUAL_CLIP_STATE)
    #ifdef __MMI_TOUCH_SCREEN__
        || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CLIP_STATE_ICON)
    #endif /* __MMI_TOUCH_SCREEN__ */
        )
        {
            is_sel = MMI_TRUE;
        }
        else
        {
            is_sel = MMI_FALSE;
        }

        switch(g_phoedt_cui_cntx_p->curr_act.para.clip.state.clip_state)
        {
            case PHOEDT_CLIP_STATE_LEFTUP:
                {
                    icon = IMG_ID_PHOEDT_MANUAL_CLIP_LEFTUP_ICON;
                }
                break;

            case PHOEDT_CLIP_STATE_RIGHTDOWN:
                {
                    icon = IMG_ID_PHOEDT_MANUAL_CLIP_RIGHTDOWN_ICON;
                }
                break;

            case PHOEDT_CLIP_STATE_MOVE:
                {
                    icon = IMG_ID_PHOEDT_MANUAL_CLIP_MOVE_ICON;
                }
                break;

            default:
                {
                    MMI_ASSERT(0);
                    icon = PHOEDT_RES_DUMMY_ID;
                }
                break;
        }
        cui_phoedt_draw_button(
            g_phoedt_layout.button_32.x, 
            g_phoedt_layout.button_32.y, 
            g_phoedt_layout.button_size.w,
            g_phoedt_layout.button_size.h,
            icon,
            is_sel);
    }

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);

    cui_phoedt_draw_title(STR_ID_PHOEDT_CLIP, MMI_TRUE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}
#endif /* __MMI_PHOEDT_STYLE_FTE_CLIP__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_flip_osd
* DESCRIPTION
*  draw flip screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_flip_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            is_sel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    cui_phoedt_draw_image_border();

    if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_FLIP_HORZ_1) ||
       MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_FLIP_HORZ_2)
#ifdef __MMI_TOUCH_SCREEN__
    || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_FLIP_HORZ)
#endif /* __MMI_TOUCH_SCREEN__ */
    )
    {
        is_sel = MMI_TRUE;
    }
    else
    {
        is_sel = MMI_FALSE;
    }
    cui_phoedt_draw_button(
        g_phoedt_layout.button_21.x,
        g_phoedt_layout.button_21.y,
        g_phoedt_layout.button_size.w,
        g_phoedt_layout.button_size.h,
        IMG_ID_PHOEDT_FLIP_HOR_ICON,
        is_sel);

    if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_FLIP_VERT_1) ||
       MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_FLIP_VERT_2)
#ifdef __MMI_TOUCH_SCREEN__
    || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_FLIP_VERT)
#endif /* __MMI_TOUCH_SCREEN__ */
    )
    {
        is_sel = MMI_TRUE;
    }
    else
    {
        is_sel = MMI_FALSE;
    }
    cui_phoedt_draw_button(
        g_phoedt_layout.button_21.x,
        g_phoedt_layout.button_21.y,
        g_phoedt_layout.button_size.w,
        g_phoedt_layout.button_size.h,
        IMG_ID_PHOEDT_FLIP_VER_ICON,
        is_sel);

    CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);

    cui_phoedt_draw_title(STR_ID_PHOEDT_FLIP, MMI_TRUE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_rotate_osd
* DESCRIPTION
*  draw rotate screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_rotate_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL            is_sel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    cui_phoedt_draw_image_border();

    if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_ROTATE_CCW)
#ifdef __MMI_TOUCH_SCREEN__
    || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ROTATE_CCW)
#endif /* __MMI_TOUCH_SCREEN__ */
    )
    {
        is_sel = MMI_TRUE;
    }
    else
    {
        is_sel = MMI_FALSE;
    }
    cui_phoedt_draw_button(
        g_phoedt_layout.button_21.x,
        g_phoedt_layout.button_21.y,
        g_phoedt_layout.button_size.w,
        g_phoedt_layout.button_size.h,
        IMG_ID_PHOEDT_ROTATE_LEFT_ICON,
        is_sel);

    if(MMI_TRUE == cui_phoedt_is_key_pressed(PHOEDT_KEY_MAP_ROTATE_CW)
#ifdef __MMI_TOUCH_SCREEN__
    || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_ROTATE_CW)
#endif /* __MMI_TOUCH_SCREEN__ */
    )
    {
        is_sel = MMI_TRUE;
    }
    else
    {
        is_sel = MMI_FALSE;
    }
    cui_phoedt_draw_button(
        g_phoedt_layout.button_22.x,
        g_phoedt_layout.button_22.y,
        g_phoedt_layout.button_size.w,
        g_phoedt_layout.button_size.h,
        IMG_ID_PHOEDT_ROTATE_RIGHT_ICON,
        is_sel);

    CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);

    cui_phoedt_draw_title(STR_ID_PHOEDT_ROTATE, MMI_TRUE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}


#ifdef __MMI_PHOEDT_DOODLE__
#ifdef __MMI_PHOEDT_STYLE_FTE__
/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_doodle_button
* DESCRIPTION
*  draw doodle button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_doodle_button(S32 x, S32 y, S32 w, S32 h, MMI_IMG_ID btn_img_id, MMI_BOOL is_sel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hlWidth, hlHeight;
    S32 iconWidth, iconHeight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->osd_layer);
    gdi_image_get_dimension_id(IMG_ID_PHOEDT_DOODLE_HL, &hlWidth, &hlHeight);
    gdi_image_get_dimension_id(btn_img_id, &iconWidth, &iconHeight);
    if (MMI_TRUE == is_sel)
    {
        gdi_image_draw_id(x + ((iconWidth - hlWidth) >> 1), y + ((iconHeight - hlHeight) >> 1), IMG_ID_PHOEDT_DOODLE_HL);
    }  
    gdi_image_draw_id(x, y, btn_img_id);
    gdi_pop_and_restore_alpha_blending_source_layer();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_doodle_toolbar_bg
* DESCRIPTION
*  FTE ONLY: doodle draw osd background
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_doodle_toolbar_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE  activeHdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd)
    {
        gdi_image_draw_resized_id(
            g_phoedt_layout.doodle_bg.x,
            g_phoedt_layout.doodle_bg.y,
            g_phoedt_layout.doodle_bg_expand_size.w,
            g_phoedt_layout.doodle_bg_expand_size.h,
            IMG_ID_PHOEDT_TOOLBAR_BG);
    }
    else
    {
        gdi_image_draw_resized_id(
            g_phoedt_layout.doodle_bg.x,
            g_phoedt_layout.doodle_bg.y,
            g_phoedt_layout.doodle_bg_collapse_size.w,
            g_phoedt_layout.doodle_bg_collapse_size.h,
            IMG_ID_PHOEDT_TOOLBAR_BG);
    }

    gdi_layer_get_active(&activeHdl);
    gdi_push_and_set_alpha_blending_source_layer(activeHdl);
    /* draw line title */   
    cui_phoedt_draw_doodle_button(
        g_phoedt_layout.doodle_line_title.x,
        g_phoedt_layout.doodle_line_title.y,
        g_phoedt_layout.doodle_button_size.w,
        g_phoedt_layout.doodle_button_size.h,
        IMG_ID_PHOEDT_DOODLE_LINE_TITLE,
        MMI_FALSE);
    
    if (MMI_FALSE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd)
    {
        /* draw eraser title */
        cui_phoedt_draw_doodle_button(
            g_phoedt_layout.doodle_eraser_title_long.x,
            g_phoedt_layout.doodle_eraser_title_long.y,
            g_phoedt_layout.doodle_button_size.w,
            g_phoedt_layout.doodle_button_size.h,
            IMG_ID_PHOEDT_DOODLE_ERASER_TITLE,
            MMI_FALSE);
    }
    else
    {
        /* draw eraser title */
        cui_phoedt_draw_doodle_button(
            g_phoedt_layout.doodle_eraser_title_short.x,
            g_phoedt_layout.doodle_eraser_title_short.y,
            g_phoedt_layout.doodle_button_size.w,
            g_phoedt_layout.doodle_button_size.h,
            IMG_ID_PHOEDT_DOODLE_ERASER_TITLE,
            MMI_FALSE);
    }
    gdi_pop_and_restore_alpha_blending_source_layer();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_doodle_osd
* DESCRIPTION
*  FTE ONLY: doodle draw osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_doodle_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                     i;
    U32                     color_R;
    U32                     color_G;
    U32                     color_B;
    MMI_BOOL                is_sel;

    /* to avoid appear two hilight in the screen when press down another item */
    MMI_BOOL                show_selected_item  = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    cui_phoedt_draw_image_border();
    cui_phoedt_draw_doodle_toolbar_bg();

    /* draw icon */
    /* draw hide icon */
    if (MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_DOODLE_HIDE))
    {
        is_sel = MMI_TRUE;
    }
    else
    {
        is_sel = MMI_FALSE;
    }
    if (MMI_TRUE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd)
    {
        cui_phoedt_draw_doodle_button(
            g_phoedt_layout.doodle_up_down.x,
            g_phoedt_layout.doodle_up_down.y,
            g_phoedt_layout.doodle_up_down_size.w,
            g_phoedt_layout.doodle_up_down_size.h,
            IMG_ID_PHOEDT_DOODLE_DOWN,
            is_sel);
    }
    else
    {
        cui_phoedt_draw_doodle_button(
            g_phoedt_layout.doodle_up_down.x,
            g_phoedt_layout.doodle_up_down.y,
            g_phoedt_layout.doodle_up_down_size.w,
            g_phoedt_layout.doodle_up_down_size.h,
            IMG_ID_PHOEDT_DOODLE_UP,
            is_sel);
    }

    if (MMI_FALSE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd)
    {
        /* doodle line icon */
        for(i = 0; i < PHOEDT_DOODLE_SIZE_COUNT; i++)
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed((phoedt_touch_item_enum)(PHOEDT_TOUCH_ITEM_DOODLE_LINE_1 + i)))
            {
                is_sel = MMI_TRUE;
                show_selected_item = MMI_FALSE;
            }
            else
            {
                is_sel = MMI_FALSE;
            }
            cui_phoedt_draw_doodle_button(
                g_phoedt_layout.doodle_line[i].x,
                g_phoedt_layout.doodle_line[i].y,
                g_phoedt_layout.doodle_button_size.w,
                g_phoedt_layout.doodle_button_size.h,
                (MMI_ID_TYPE)(IMG_ID_PHOEDT_DOODLE_LINE_1 + i),
                is_sel);
        }

        /* doodle color icon */
        if(MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_DOODLE_COLOR))
        {
            is_sel = MMI_TRUE;
            show_selected_item = MMI_FALSE;
        }
        else
        {
            is_sel = MMI_FALSE;
        }

        cui_phoedt_draw_doodle_button(
            g_phoedt_layout.doodle_color.x,
            g_phoedt_layout.doodle_color.y,
            g_phoedt_layout.doodle_button_size.w,
            g_phoedt_layout.doodle_button_size.h,
            (MMI_ID_TYPE)(IMG_ID_PHOEDT_DOODLE_COLOR),
            is_sel);

        color_R = g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].r;
        color_G = g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].g;
        color_B = g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].b;
        gdi_draw_solid_rect(
            g_phoedt_layout.doodle_color_rect.x,
            g_phoedt_layout.doodle_color_rect.y,
            g_phoedt_layout.doodle_color_rect.x + g_phoedt_layout.doodle_color_rect_size.w - 1,
            g_phoedt_layout.doodle_color_rect.y + g_phoedt_layout.doodle_color_rect_size.h - 1,
            gdi_act_color_from_rgb(255, color_R, color_G, color_B));

        /* doodle eraser icon */
        for(i = 0; i < PHOEDT_DOODLE_SIZE_COUNT; i++)
        {
            if(MMI_TRUE == cui_phoedt_is_touch_item_pressed((phoedt_touch_item_enum)(PHOEDT_TOUCH_ITEM_DOODLE_ERASER_1 + i)))
            {
                is_sel = MMI_TRUE;
                show_selected_item = MMI_FALSE;
            }
            else
            {
                is_sel = MMI_FALSE;
            }
            cui_phoedt_draw_doodle_button(
                g_phoedt_layout.doodle_eraser[i].x,
                g_phoedt_layout.doodle_eraser[i].y,
                g_phoedt_layout.doodle_button_size.w,
                g_phoedt_layout.doodle_button_size.h,
                (MMI_ID_TYPE)(IMG_ID_PHOEDT_DOODLE_ERASER_1 + i),
                is_sel);
        }

        /* current selected icon */
        if(MMI_TRUE == show_selected_item)
        {
            if(PHOEDT_DOODLE_TYPE_LINE == g_phoedt_cui_cntx_p->curr_act.para.doodle.type) /* line */
            {
                cui_phoedt_draw_doodle_button(
                    g_phoedt_layout.doodle_line[g_phoedt_cui_cntx_p->curr_act.para.doodle.size].x,
                    g_phoedt_layout.doodle_line[g_phoedt_cui_cntx_p->curr_act.para.doodle.size].y,
                    g_phoedt_layout.doodle_button_size.w,
                    g_phoedt_layout.doodle_button_size.h,
                    (MMI_ID_TYPE)(IMG_ID_PHOEDT_DOODLE_LINE_1 + (U16)(g_phoedt_cui_cntx_p->curr_act.para.doodle.size)),
                    MMI_TRUE);
            }
            else   /* eraser */
            {
                cui_phoedt_draw_doodle_button(
                    g_phoedt_layout.doodle_eraser[g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size].x,
                    g_phoedt_layout.doodle_eraser[g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size].y,
                    g_phoedt_layout.doodle_button_size.w,
                    g_phoedt_layout.doodle_button_size.h,
                    (MMI_ID_TYPE)(IMG_ID_PHOEDT_DOODLE_ERASER_1 + (U16)(g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size)),
                    MMI_TRUE);
            }
        }

        /* draw softkey */
        CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);
    }

    cui_phoedt_draw_title(STR_ID_PHOEDT_DOODLE, MMI_TRUE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}

#else/* __MMI_PHOEDT_STYLE_FTE__ */
/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_doodle_osd
* DESCRIPTION
*  draw doodle screen's osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_doodle_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL                is_sel;
    MMI_IMG_ID              icon;
    U32                     color_R;
    U32                     color_G;
    U32                     color_B;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->osd_layer);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    cui_phoedt_draw_image_border();

    /* draw hide icon */
    if(MMI_TRUE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd)
    {
        is_sel = MMI_TRUE;
    }
    else
    {
        is_sel = MMI_FALSE;
    }
    cui_phoedt_draw_button(
        g_phoedt_layout.doodle_hide.x,
        g_phoedt_layout.doodle_hide.y,
        g_phoedt_layout.doodle_button_size.w,
        g_phoedt_layout.doodle_button_size.h,
        IMG_ID_PHOEDT_HIDE_ICON,
        is_sel);

    if(MMI_FALSE == g_phoedt_cui_cntx_p->curr_act.para.doodle.is_hide_osd)
    {
        /* doodle type icon */
        if(PHOEDT_DOODLE_TYPE_LINE == g_phoedt_cui_cntx_p->curr_act.para.doodle.type)
        {
            icon = IMG_ID_PHOEDT_LINE_ICON;
        }
        else
        {
            icon = IMG_ID_PHOEDT_ERASER_ICON;
        }
        cui_phoedt_draw_button(
            g_phoedt_layout.doodle_type.x,
            g_phoedt_layout.doodle_type.y,
            g_phoedt_layout.doodle_button_size.w,
            g_phoedt_layout.doodle_button_size.h,
            icon,
            MMI_FALSE);

        /* doodle size icon*/
        if(PHOEDT_DOODLE_TYPE_LINE == g_phoedt_cui_cntx_p->curr_act.para.doodle.type)
        {
            icon = IMG_ID_PHOEDT_SIZE_SMALL_ICON + (U16)(g_phoedt_cui_cntx_p->curr_act.para.doodle.size);
        }
        else   /* eraser */
        {
            icon = IMG_ID_PHOEDT_SIZE_ERASER_SMALL_ICON + (U16)(g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size);
        }
        cui_phoedt_draw_button(
            g_phoedt_layout.doodle_size.x,
            g_phoedt_layout.doodle_size.y,
            g_phoedt_layout.doodle_button_size.w,
            g_phoedt_layout.doodle_button_size.h,
            icon,
            MMI_FALSE);

        if(PHOEDT_DOODLE_TYPE_LINE == g_phoedt_cui_cntx_p->curr_act.para.doodle.type)  /* line */
        {
            /* doodle color icon*/
            icon = IMG_ID_PHOEDT_DOODLE_COLOR_ICON;
            color_R = g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].r;
            color_G = g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].g;
            color_B = g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].b;
            gdi_draw_frame_rect(
                g_phoedt_layout.doodle_color.x,
                g_phoedt_layout.doodle_color.y,
                g_phoedt_layout.doodle_color.x + g_phoedt_layout.doodle_button_size.w,
                g_phoedt_layout.doodle_color.y + g_phoedt_layout.doodle_button_size.h,
                gdi_act_color_from_rgb(255, color_R, color_G, color_B),
                PHOEDT_IMAGE_BORDER_COLOR,
                PHOEDT_IMAGE_BORDER_WIDTH);
        }

        CUI_PHOEDT_DRAW_SOFTKEY(STR_GLOBAL_DONE, STR_GLOBAL_CANCEL, MMI_FALSE, IMG_GLOBAL_COMMON_CSK);
    }

    cui_phoedt_draw_title(STR_ID_PHOEDT_DOODLE, MMI_TRUE, PHOEDT_RES_DUMMY_ID, MMI_FALSE);

    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_pop_and_restore_active();
}
#endif /* __MMI_PHOEDT_STYLE_FTE__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_doodle_draw_doodle
* DESCRIPTION
*  draw doodle
* PARAMETERS
*  start            [IN]
*  end              [IN]
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_doodle_draw_doodle(phoedt_pos_struct start, phoedt_pos_struct end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result  ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_ID_PHOEDT_EDIT != mmi_frm_scrn_get_active_id())
    {
        return;
    }

    switch(g_phoedt_cui_cntx_p->curr_act.para.doodle.type)
    {
    case PHOEDT_DOODLE_TYPE_LINE:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_DRAW_LINE,
                start.x, start.y, end.x, end.y, g_phoedt_doodle_size[g_phoedt_cui_cntx_p->curr_act.para.doodle.size],
                g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx,
                g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].r,
                g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].g,
                g_phoedt_doodle_line_color_list[g_phoedt_cui_cntx_p->curr_act.para.doodle.color_idx].b);

            ies_ret = srv_ies_doodle_add_line(
                g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle,
                start.x, start.y, end.x, end.y);
            PHOEDT_TRACE_IES_RESULT(ies_ret);
        }
        break;

    case PHOEDT_DOODLE_TYPE_ERASER:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_DRAW_ERASER,
                start.x, start.y, end.x, end.y, g_phoedt_doodle_size[g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size]);

            ies_ret = srv_ies_doodle_erase_line(
                g_phoedt_cui_cntx_p->curr_act.para.doodle.ies_doodle_hdle,
                start.x, start.y, end.x, end.y, g_phoedt_doodle_size[g_phoedt_cui_cntx_p->curr_act.para.doodle.eraser_size]);
            PHOEDT_TRACE_IES_RESULT(ies_ret);
        }
        break;

    default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
}
#endif /* __MMI_PHOEDT_DOODLE__ */


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_softkey
* DESCRIPTION
*  lsk press hdlr
* PARAMETERS
*  lsk_str         [IN]        Lsk string
*  rsk_str         [IN]        Rsk string
*  is_clear_bg     [IN]        Clear background flag
*  csk_img         [IN]        Image id for csk
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_softkey(
                MMI_STR_ID lsk_str,
                MMI_STR_ID rsk_str,
                MMI_BOOL is_clear_bg,
                MMI_IMG_ID csk_img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x;
    S32 offset_y;
    S32 x1;
    S32 x2;
    S32 y1;
    S32 y2;
    S32 truncated_width;
    MMI_BOOL truncated = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if has softkey need update */
    if((lsk_str == PHOEDT_RES_DUMMY_ID) &&
       (rsk_str == PHOEDT_RES_DUMMY_ID) &&
       (csk_img == PHOEDT_RES_DUMMY_ID))
    {
        return;
    }
    gdi_layer_push_clip();
    gdi_layer_push_text_clip();
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    x1 = 0;
    y1 = UI_device_height - MMI_button_bar_height;
    x2 = UI_device_width - 1;
    y2 = UI_device_height - 1;

    /* clear softkey background */
    if(MMI_TRUE == is_clear_bg)
    {
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    }

    /* draw lsk */
    if(PHOEDT_RES_DUMMY_ID != lsk_str)
    {
        truncated = wgui_softkey_get_offset(
            (UI_string_type)GetString(lsk_str),
            &offset_x,
            &offset_y,
            &truncated_width,
            MMI_LEFT_SOFTKEY,
            mmi_frm_get_screen_rotate());
        gui_measure_string((UI_string_type)GetString(lsk_str), &str_width, &str_height);

    #ifdef __MMI_TOUCH_SCREEN__
        if(TRUE == r2lMMIFlag)
        {
            offset_x = offset_x - str_width;
        }
    #endif /* __MMI_TOUCH_SCREEN__ */

        if(MMI_TRUE == cui_phoedt_is_key_pressed(KEY_LSK)
    #ifdef __MMI_TOUCH_SCREEN__
        || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_LSK)
    #endif /* __MMI_TOUCH_SCREEN__ */
        )
        {
            offset_x++;
            offset_y++;
            gui_set_text_color(PHOEDT_LSK_DOWN_TEXT_COLOR);
            gui_set_text_border_color(PHOEDT_SOFTKEY_DOWN_TEXT_BORDER_COLOR);
        }
        else
        {
            gui_set_text_color(PHOEDT_LSK_UP_TEXT_COLOR);
            gui_set_text_border_color(PHOEDT_SOFTKEY_TEXT_BORDER_COLOR);
        }

        gui_move_text_cursor(offset_x, offset_y);

        if(MMI_TRUE == truncated)
        {
            gui_print_truncated_borderd_text(
                offset_x,
                offset_y,
                truncated_width,
                (UI_string_type)GetString(lsk_str));
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
            gui_print_bordered_text((UI_string_type)GetString(lsk_str));
        }

    #ifdef __MMI_TOUCH_SCREEN__
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk.pos_x = offset_x;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk.pos_y = offset_y;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk.width = str_width;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk.height = str_height;
    #endif
    }
#ifdef __MMI_TOUCH_SCREEN__
    else
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk.pos_x = 0;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk.pos_y = 0;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk.width = 0;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.lsk.height = 0;
    }
#endif /* __MMI_TOUCH_SCREEN__ */

    /* draw rsk */
    if(PHOEDT_RES_DUMMY_ID != rsk_str)
    {
        truncated = wgui_softkey_get_offset(
            (UI_string_type)GetString(rsk_str),
            &offset_x,
            &offset_y,
            &truncated_width,
            MMI_RIGHT_SOFTKEY,
            mmi_frm_get_screen_rotate());
        gui_measure_string((UI_string_type)GetString(rsk_str), &str_width, &str_height);

    #ifdef __MMI_TOUCH_SCREEN__
        if(TRUE == r2lMMIFlag)
        {
            offset_x = offset_x - str_width;
        }
    #endif /* __MMI_TOUCH_SCREEN__ */

        if(MMI_TRUE == cui_phoedt_is_key_pressed(KEY_RSK)
    #ifdef __MMI_TOUCH_SCREEN__
        || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_RSK)
    #endif /* __MMI_TOUCH_SCREEN__ */
        )
        {
            offset_x++;
            offset_y++;
            gui_set_text_color(PHOEDT_RSK_DOWN_TEXT_COLOR);
            gui_set_text_border_color(PHOEDT_SOFTKEY_DOWN_TEXT_BORDER_COLOR);
        }
        else
        {
            gui_set_text_color(PHOEDT_RSK_UP_TEXT_COLOR);
            gui_set_text_border_color(PHOEDT_SOFTKEY_TEXT_BORDER_COLOR);
        }

        gui_move_text_cursor(offset_x, offset_y);

        if(MMI_TRUE == truncated)
        {
            gui_print_truncated_borderd_text(
                offset_x,
                offset_y,
                truncated_width,
                (UI_string_type)GetString(rsk_str));
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
            gui_print_bordered_text((UI_string_type)GetString(rsk_str));
        }

    #ifdef __MMI_TOUCH_SCREEN__
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk.pos_x = offset_x;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk.pos_y = offset_y;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk.width = str_width;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk.height = str_height;
    #endif
    }
#ifdef __MMI_TOUCH_SCREEN__
    else
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk.pos_x = 0;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk.pos_y = 0;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk.width = 0;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.rsk.height = 0;
    }
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_FTE_SUPPORT__
    /* do not draw the icon, but keep the key's function */
    csk_img = PHOEDT_RES_DUMMY_ID;
#endif
    /* draw csk */
    if(PHOEDT_RES_DUMMY_ID != csk_img)
    {
        gdi_image_get_dimension_id(csk_img, &str_width, &str_height);

        offset_y = UI_device_height - MMI_button_bar_height + ((MMI_button_bar_height - str_height) >> 1);
        offset_x = (UI_device_width - str_width) >> 1;

        if(MMI_TRUE == cui_phoedt_is_key_pressed(KEY_CSK)
    #ifdef __MMI_TOUCH_SCREEN__
        || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_CSK)
    #endif /* __MMI_TOUCH_SCREEN__ */
        )
        {
            offset_x++;
            offset_y++;
        }
        gdi_image_draw_id(offset_x, offset_y, csk_img);

    #ifdef __MMI_TOUCH_SCREEN__
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk.pos_x = offset_x;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk.pos_y = offset_y;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk.width = str_width;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk.height = str_height;
    #endif /* __MMI_TOUCH_SCREEN__ */
    }
#ifdef __MMI_TOUCH_SCREEN__
    else
    {
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk.pos_x = 0;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk.pos_y = 0;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk.width = 0;
        g_phoedt_cui_cntx_p->touch_cntx.dyn_comp.csk.height = 0;
    }
#endif /* __MMI_TOUCH_SCREEN__ */

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_clip();
    gdi_layer_pop_text_clip();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_title
* DESCRIPTION
*  draw title
* PARAMETERS
*  title            [IN]        Title string
*  is_bracketed     [IN]        Does the title have prefix and suffix
*  sub_title        [IN]        Selection string
*  is_clear_bg      [IN]        Clear background flag
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_title(
                MMI_STR_ID  title,
                MMI_BOOL    is_bracketed,
                MMI_STR_ID  sub_title,
                MMI_BOOL    is_clear_bg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    is_sel;
    S32         x1;
    S32         x2;
    S32         y1;
    S32         y2;
    S32         offset_x;
    S32         offset_y;
    S32         str_width;
    S32         str_height;
    WCHAR       title_str[PHOEDT_MAX_TITLE_CHARACTERS + 1]; /* including the null character */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PHOEDT_RES_DUMMY_ID == title && PHOEDT_RES_DUMMY_ID == sub_title)
    {
        return;
    }

    gdi_layer_push_clip();
    gdi_layer_push_text_clip();
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->preview_layer);

    x1 = 0;
    y1 = 0;
    x2 = UI_device_width - 1;
    y2 = MMI_title_height * 2;

    gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_TITLE));
    gui_set_text_color(PHOEDT_TITLE_TEXT_COLOR);
    gui_set_text_border_color(PHOEDT_TITLE_TEXT_BORDER_COLOR);

    if(PHOEDT_RES_DUMMY_ID != title)
    {
        /* clear background */
        if(MMI_TRUE == is_clear_bg)
        {
            gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
        }

        if((mmi_wcslen((WCHAR*)GetString(STR_ID_PHOEDT_TITLE_PREFIX)) +
            mmi_wcslen((WCHAR*)GetString(STR_ID_PHOEDT_TITLE_SUFFIX)) +
            mmi_wcslen((WCHAR*)GetString(title))) > PHOEDT_MAX_TITLE_CHARACTERS)
        {
            /* to check buffer overflow */
            MMI_ASSERT(0);
        }

        if(MMI_TRUE == is_bracketed)
        {
            kal_wsprintf(title_str, "%w%w%w",
                (WCHAR*)GetString(STR_ID_PHOEDT_TITLE_PREFIX),
                (WCHAR*)GetString(title),
                (WCHAR*)GetString(STR_ID_PHOEDT_TITLE_SUFFIX));
        }
        else
        {
            mmi_wcscpy(title_str, (WCHAR*)GetString(title));
        }

        gui_measure_string((UI_string_type)title_str, &str_width, &str_height);

        offset_x = (UI_device_width - str_width) >> 1;
        offset_y = (MMI_title_height - str_height) >> 1;

        if(TRUE == r2lMMIFlag)
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        gui_print_bordered_text((UI_string_type)title_str);
    }

    if(PHOEDT_RES_DUMMY_ID != sub_title)
    {
        gui_measure_string((UI_string_type)GetString(sub_title), &str_width, &str_height);

        /* draw selection text */
        offset_x = (UI_device_width - str_width) >> 1;
        offset_y = g_phoedt_layout.left_arrow.y + ((g_phoedt_layout.arrow_size.h - str_height + 1) / 2);

        if(TRUE == r2lMMIFlag)
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        gui_print_bordered_text((UI_string_type)GetString(sub_title));

        /* Draw Arrow */
        /* left */
        if(MMI_TRUE == cui_phoedt_is_key_pressed(KEY_LEFT_ARROW)
    #ifdef __MMI_TOUCH_SCREEN__
        || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_PREV)
    #endif /* __MMI_TOUCH_SCREEN__ */
        )
        {
            is_sel = MMI_TRUE;
        }
        else
        {
            is_sel = MMI_FALSE;
        }
        cui_phoedt_draw_button(
            g_phoedt_layout.left_arrow.x,
            g_phoedt_layout.left_arrow.y,
            g_phoedt_layout.arrow_size.w,
            g_phoedt_layout.arrow_size.h,
            IMG_ID_PHOEDT_LEFT_ARROW,
            is_sel);

        /* right */
        if(MMI_TRUE == cui_phoedt_is_key_pressed(KEY_RIGHT_ARROW)
    #ifdef __MMI_TOUCH_SCREEN__
        || MMI_TRUE == cui_phoedt_is_touch_item_pressed(PHOEDT_TOUCH_ITEM_NEXT)
    #endif /* __MMI_TOUCH_SCREEN__ */
        )
        {
            is_sel = MMI_TRUE;
        }
        else
        {
            is_sel = MMI_FALSE;
        }
        cui_phoedt_draw_button(
            g_phoedt_layout.right_arrow.x,
            g_phoedt_layout.right_arrow.y,
            g_phoedt_layout.arrow_size.w,
            g_phoedt_layout.arrow_size.h,
            IMG_ID_PHOEDT_RIGHT_ARROW,
            is_sel);
    }

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_clip();
    gdi_layer_pop_text_clip();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_button
* DESCRIPTION
*  draw button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_button(S32 x, S32 y, S32 w, S32 h, MMI_IMG_ID btn_img_id, MMI_BOOL is_sel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHOEDT_STYLE_FTE__
    gdi_image_draw_id(x, y, btn_img_id);
    if (MMI_TRUE == is_sel)
    {
        gdi_push_and_set_alpha_blending_source_layer(g_phoedt_cui_cntx_p->osd_layer);
        gdi_image_draw_id(x, y, IMG_ID_PHOEDT_BTN_HL);
        gdi_pop_and_restore_alpha_blending_source_layer();
    }    
#else
    if (MMI_TRUE == is_sel)
        gdi_image_draw_id(x, y, btn_img_id + 1);
    else
        gdi_image_draw_id(x, y, btn_img_id);
#endif
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_draw_image_border
* DESCRIPTION
*  draw image border
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_draw_image_border(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_x1 = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x;
    S32 img_y1 = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y;
    S32 img_x2 = g_phoedt_cui_cntx_p->display_info.img_rect.offset.x +
        g_phoedt_cui_cntx_p->display_info.img_rect.size.w - 1;
    S32 img_y2 = g_phoedt_cui_cntx_p->display_info.img_rect.offset.y +
        g_phoedt_cui_cntx_p->display_info.img_rect.size.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->preview_layer);

    if((img_x1 - 1 >= 0) && (img_x2 + 1 <= UI_device_width - 1))
    {
        /* left border */
        gdi_draw_line(img_x1 - 1, img_y1 - 1, img_x1 - 1, img_y2 + 1, PHOEDT_IMAGE_BORDER_COLOR);

        /* right border */
        gdi_draw_line(img_x2 + 1, img_y1 - 1, img_x2 + 1, img_y2 + 1, PHOEDT_IMAGE_BORDER_COLOR);
    }

    if((img_y1 - 1 >= 0) && (img_y2 + 1 <= UI_device_height - 1))
    {
        /* top border */
        gdi_draw_line(img_x1 - 1, img_y1 - 1, img_x2 + 1, img_y1 - 1, PHOEDT_IMAGE_BORDER_COLOR);

        /* bottom border */
        gdi_draw_line(img_x1 - 1, img_y2 + 1, img_x2 + 1, img_y2 + 1, PHOEDT_IMAGE_BORDER_COLOR);
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_init_ies_capacity
* DESCRIPTION
*  init the image editor servie capacity
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_init_ies_capacity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32                         total_count;
    U32                         para_count;
    U32                         idx;
    U32                         effect_idx;
    U32                         para_idx;
    U32                         adjust_idx;
    srv_ies_effect_enum         effect_id;
    srv_ies_effect_param_enum   para_info_id;
    phoedt_adjust_item_struct   *para_items;
    S32                         dis;
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_INIT_IES_BEGIN);

    g_phoedt_cui_cntx_p->ies_capacity.adjust_count = 0;
    g_phoedt_cui_cntx_p->ies_capacity.effect_count = 0;
    for(idx = 0; idx < PHOEDT_ADJUST_ITEM_TOTAL_COUNT; idx++)
    {
        g_phoedt_cui_cntx_p->ies_capacity.adjust_para_items[idx].is_used = MMI_FALSE;
    }

    total_count = srv_ies_effect_get_available_count();

    PHOEDT_TRACE_IES_RESULT(total_count);
    MMI_ASSERT((PHOEDT_EFFECT_MAX_COUNT + PHOEDT_ADJUST_MAX_COUNT) >= total_count);

    for(idx = 0; idx < total_count; idx++)
    {
        effect_id = srv_ies_effect_get_available_id(idx);

        ies_ret = srv_ies_effect_get_param_count(effect_id, &para_count);
        PHOEDT_TRACE_IES_RESULT(ies_ret);

        if(0 == para_count)
        {
            MMI_ASSERT(PHOEDT_EFFECT_MAX_COUNT > g_phoedt_cui_cntx_p->ies_capacity.effect_count);

            effect_idx = g_phoedt_cui_cntx_p->ies_capacity.effect_count;

            /* Init effect info, like name and id~~ */
            g_phoedt_cui_cntx_p->ies_capacity.effects[effect_idx].id = effect_id;
            ies_ret = srv_ies_effect_get_effect_name(
                effect_id,
                &g_phoedt_cui_cntx_p->ies_capacity.effects[effect_idx].name);
            PHOEDT_TRACE_IES_RESULT(ies_ret);

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_INIT_IES_EFFECT,
                g_phoedt_cui_cntx_p->ies_capacity.effects[effect_idx].id,
                g_phoedt_cui_cntx_p->ies_capacity.effects[effect_idx].name);

            g_phoedt_cui_cntx_p->ies_capacity.effect_count++;
        }
        else
        {
            MMI_ASSERT(PHOEDT_ADJUST_MAX_COUNT > g_phoedt_cui_cntx_p->ies_capacity.adjust_count);

            para_items = cui_phoedt_adjust_find_free_adjust_para_items(para_count);
            adjust_idx = g_phoedt_cui_cntx_p->ies_capacity.adjust_count;

            /* Init adjust info, like name and id~~ */
            g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].id = effect_id;
            ies_ret = srv_ies_effect_get_effect_name(
                effect_id,
                &g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].name);
            PHOEDT_TRACE_IES_RESULT(ies_ret);
            g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_count = para_count;
            g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items = para_items;

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_INIT_IES_ADJUST,
                g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].id,
                g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].name,
                g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_count);

            for(para_idx = 0; para_idx < para_count; para_idx++)
            {
                ies_ret = srv_ies_effect_get_param_name(
                    effect_id,
                    para_idx,
                    &g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].name);
                PHOEDT_TRACE_IES_RESULT(ies_ret);

                ies_ret = srv_ies_effect_get_param_id(
                    effect_id,
                    para_idx,
                    &para_info_id);
                PHOEDT_TRACE_IES_RESULT(ies_ret);

                ies_ret = srv_ies_effect_get_param_default(
                    effect_id,
                    para_idx,
                    &g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.init);
                PHOEDT_TRACE_IES_RESULT(ies_ret);

                ies_ret = srv_ies_effect_get_param_range(
                    effect_id,
                    para_idx,
                    &g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.min,
                    &g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.max);
                PHOEDT_TRACE_IES_RESULT(ies_ret);

                cui_phoedt_get_adjust_para_icons(
                    para_info_id,
                    &g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].icon);

                dis = g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.max - g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.min;

                if(dis > PHOEDT_ADJUST_MAX_STEP_COUNT)
                {
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.step = dis / PHOEDT_ADJUST_MAX_STEP_COUNT;
                }
                else
                {
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.step = 1;
                }

                g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.value =
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.init;

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_INIT_IES_ADJUST_PARA,
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].id, para_idx, para_info_id,
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].name,
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].icon,
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.min,
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.max,
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.init,
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.step,
                    g_phoedt_cui_cntx_p->ies_capacity.adjusts[adjust_idx].para_items[para_idx].para.value);
            }

            g_phoedt_cui_cntx_p->ies_capacity.adjust_count++;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_INIT_IES_END,
        g_phoedt_cui_cntx_p->ies_capacity.effect_count, g_phoedt_cui_cntx_p->ies_capacity.adjust_count);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_handle_ies_err_code
* DESCRIPTION
*  cui_phoedt_handle_ies_err_code
* PARAMETERS
*  err_code         [IN]
* RETURNS
*  handled the error or not a error
*****************************************************************************/
static MMI_BOOL cui_phoedt_handle_ies_err_code(MMI_ID gid, srv_ies_result err_code, U32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR       *err_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IES_RESULT, err_code, line);

    if(SRV_IES_OK != err_code)
    {
        err_str = (WCHAR*)GetString(srv_ies_util_error_get_string(err_code));

        PHOEDT_CUI_DISPLAY_POPUP(gid, err_str, MMI_EVENT_FAILURE);

        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_create_meta_job_done_callback
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_create_meta_job_done_callback(srv_ies_result result, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;
    MMI_BOOL                    sucess          = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT (NULL != g_phoedt_cui_cntx_p);

    gdi_anim_stop(g_phoedt_cui_cntx_p->curr_act.para.loading.loading_hdl);

    if (MMI_FALSE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, result))
    {
        do {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_GET_IES_META);
            ies_ret = srv_ies_job_get_meta(
                g_phoedt_cui_cntx_p->curr_act.para.loading.job,            
                &g_phoedt_cui_cntx_p->ies_hdles.meta);
            if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
            {
                break;
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_SET_IES_META_INFO);
            ies_ret = srv_ies_image_set_meta_info(
                g_phoedt_cui_cntx_p->ies_hdles.img,          
                g_phoedt_cui_cntx_p->ies_hdles.meta);
            if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
            {
                break;
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_IES_PREVIEW);
            ies_ret = srv_ies_preview_create(
                g_phoedt_cui_cntx_p->ies_hdles.img,
                &g_phoedt_cui_cntx_p->ies_hdles.preview,
                g_phoedt_cui_cntx_p->preview_buf,
                PHOEDT_FRAME_BUFFER_SIZE,
                UI_device_width,
                UI_device_height,
                cui_phoedt_get_pitchBytes(),
                cui_phoedt_get_ies_color_format());
            if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
            {
                break;
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IMG_ORG_SIZE,
                g_phoedt_cui_cntx_p->image_info.org_size.w, g_phoedt_cui_cntx_p->image_info.org_size.h);
            ies_ret = srv_ies_image_get_source_size(
                g_phoedt_cui_cntx_p->ies_hdles.img,
                &g_phoedt_cui_cntx_p->image_info.org_size.w,
                &g_phoedt_cui_cntx_p->image_info.org_size.h);
            if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
            {
                break;
            }
            g_phoedt_cui_cntx_p->image_info.curr_size = g_phoedt_cui_cntx_p->image_info.org_size;
            sucess = MMI_TRUE;
        }while(MMI_FALSE);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IMG_ORG_SIZE,
            g_phoedt_cui_cntx_p->image_info.org_size.w, g_phoedt_cui_cntx_p->image_info.org_size.h);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IMG_CURR_SIZE,
            g_phoedt_cui_cntx_p->image_info.curr_size.w, g_phoedt_cui_cntx_p->image_info.curr_size.h);
    }

    g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_NONE;
    if (MMI_TRUE == sucess)
    {
        cui_phoedt_reset_image_display_info();
        if(MMI_FALSE == cui_phoedt_preview_image(MMI_FALSE))
        {
            return;
        }
        cui_phoedt_init_ies_capacity();
        cui_phoedt_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
    else
    {
        cui_phoedt_exit_curr_phoart();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_create_ies_resource
* DESCRIPTION
*  cui_phoedt_create_ies_resource
*  error popup should in root_id to make sure it will be shown.
*  cause if it comes after exit pre confirm, then because the cui_id is not active,
*  the popup will not be shown
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_create_ies_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_IES_SESSION, APP_PHOEDT, PHOEDT_IES_BUFFER_SIZE);
        ies_ret = srv_ies_app_session_create(
            APP_PHOEDT,
            SRV_IES_FEATURE_ALL,
            g_phoedt_cui_cntx_p->ies_buf,
            PHOEDT_IES_BUFFER_SIZE,
            &g_phoedt_cui_cntx_p->ies_hdles.session);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
        {
            break;
        }

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_IES_IMAGE);
        ies_ret = srv_ies_image_create_from_file(
            g_phoedt_cui_cntx_p->ies_hdles.session,
            g_phoedt_cui_cntx_p->org_file.filepath,
            NULL,
            &g_phoedt_cui_cntx_p->ies_hdles.img);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
        {
            break;
        }

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CREATE_IES_META);
        ies_ret = srv_ies_meta_create_from_file_async(
            g_phoedt_cui_cntx_p->ies_hdles.session,
            g_phoedt_cui_cntx_p->org_file.filepath,
            UI_device_width,
            UI_device_height,
            cui_phoedt_create_meta_job_done_callback,
            NULL,
            &g_phoedt_cui_cntx_p->curr_act.para.loading.job);
        if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
        {
            break;
        }
        return;
    }while(MMI_FALSE);
    
    cui_phoedt_exit_curr_phoart();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_release_ies_resource
* DESCRIPTION
*  cui_phoedt_release_ies_resource
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_release_ies_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this is because if there till some effect is running, SRV will assert */
    cui_phoedt_give_up_curr_change();

    if(NULL != g_phoedt_cui_cntx_p->ies_hdles.preview)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_DESTORY_IES_PREVIEW);
        ies_ret = srv_ies_preview_destroy(g_phoedt_cui_cntx_p->ies_hdles.preview);
        PHOEDT_TRACE_IES_RESULT(ies_ret);

        g_phoedt_cui_cntx_p->ies_hdles.preview = NULL;
    }

    if(NULL != g_phoedt_cui_cntx_p->ies_hdles.meta)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_DESTORY_IES_META);
        srv_ies_meta_destroy(g_phoedt_cui_cntx_p->ies_hdles.meta);
        PHOEDT_TRACE_IES_RESULT(ies_ret);

        g_phoedt_cui_cntx_p->ies_hdles.meta = NULL;
    }

    if(NULL != g_phoedt_cui_cntx_p->ies_hdles.img)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_DESTORY_IES_IMAGE);
        srv_ies_image_destroy(g_phoedt_cui_cntx_p->ies_hdles.img);
        PHOEDT_TRACE_IES_RESULT(ies_ret);

        g_phoedt_cui_cntx_p->ies_hdles.img = NULL;
    }

    if(NULL != g_phoedt_cui_cntx_p->ies_hdles.session)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_DESTORY_IES_SESSION);
        srv_ies_app_session_destroy(g_phoedt_cui_cntx_p->ies_hdles.session);
        PHOEDT_TRACE_IES_RESULT(ies_ret);

        g_phoedt_cui_cntx_p->ies_hdles.session = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_ies_resource_reload_image
* DESCRIPTION
*  cui_phoedt_ies_resource_reload_image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_ies_resource_reload_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(g_phoedt_cui_cntx_p->org_file.filepath, g_phoedt_cui_cntx_p->new_file.filepath);

    cui_phoedt_release_ies_resource();

    cui_phoedt_create_ies_resource();
    g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_LOADING;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_adjust_find_free_adjust_para_items
* DESCRIPTION
*  find free adjust para items
* PARAMETERS
*  the needed count
* RETURNS
*  the pointer of the first free item
*****************************************************************************/
static phoedt_adjust_item_struct* cui_phoedt_adjust_find_free_adjust_para_items(S32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     first_idx;
    S32     idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(idx = 0; idx < PHOEDT_ADJUST_ITEM_TOTAL_COUNT; idx++)
    {
        if(MMI_FALSE == g_phoedt_cui_cntx_p->ies_capacity.adjust_para_items[idx].is_used)
        {
            break;
        }
    }

    MMI_ASSERT(PHOEDT_ADJUST_ITEM_TOTAL_COUNT != idx);

    first_idx = idx;

    for(idx = 0; idx < count; idx++)
    {
        MMI_ASSERT(PHOEDT_ADJUST_ITEM_TOTAL_COUNT != first_idx + idx);
        g_phoedt_cui_cntx_p->ies_capacity.adjust_para_items[first_idx + idx].is_used = MMI_TRUE;
    }

    return &g_phoedt_cui_cntx_p->ies_capacity.adjust_para_items[first_idx];
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_get_curr_adjust_item
* DESCRIPTION
*  get the pointer of current adjust item
* PARAMETERS
*  void
* RETURNS
*  the pointer of current adjust item
*****************************************************************************/
static phoedt_adjust_struct* cui_phoedt_get_curr_adjust_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(PHOEDT_ADJUST_MAX_COUNT > g_phoedt_cui_cntx_p->curr_act.para.adjust.idx);

    return &g_phoedt_cui_cntx_p->ies_capacity.adjusts[g_phoedt_cui_cntx_p->curr_act.para.adjust.idx];
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_get_curr_effect_item
* DESCRIPTION
*  get the pointer of current effect item
* PARAMETERS
*  void
* RETURNS
*  the pointer of current effect item
*****************************************************************************/
static phoedt_effect_struct* cui_phoedt_get_curr_effect_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(PHOEDT_EFFECT_MAX_COUNT > g_phoedt_cui_cntx_p->curr_act.para.effect.idx);

    return &g_phoedt_cui_cntx_p->ies_capacity.effects[g_phoedt_cui_cntx_p->curr_act.para.effect.idx];
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_get_pitchBytes
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  error code
*****************************************************************************/
static U32 cui_phoedt_get_pitchBytes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (UI_device_width * PHOEDT_CURRENT_COLOR_FORMAT);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_get_ies_color_format
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  error code
*****************************************************************************/
static srv_ies_colorformat_enum cui_phoedt_get_ies_color_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_colorformat_enum        cf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(PHOEDT_CURRENT_COLOR_FORMAT)
    {
    case GDI_COLOR_FORMAT_16:
        cf = SRV_IES_COLORFORMAT_RGB565;
        break;

    case GDI_COLOR_FORMAT_24:
        cf = SRV_IES_COLORFORMAT_RGB888;
        break;

    default:
        MMI_ASSERT(0);
        break;
    }

    return cf;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_preview_image
* DESCRIPTION
*  get the image from ies to preview layer
*  error popup should in root_id to make sure it will be shown.
*  cause if it shown in cui_id, then when close cui_id, it will be closed too, popup will flashed
* PARAMETERS
*  void
* RETURNS
*  sucess or not
*****************************************************************************/
static MMI_BOOL cui_phoedt_preview_image(MMI_BOOL reset_preview_rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              ies_ret         = SRV_IES_OK;
    MMI_BOOL                    ret             = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do{
        if(NULL != g_phoedt_cui_cntx_p->ies_hdles.preview)
        {
            if(MMI_TRUE == reset_preview_rect)
            {
                if(g_phoedt_cui_cntx_p->image_info.shown_rect.size.w < UI_device_width &&
                   g_phoedt_cui_cntx_p->image_info.shown_rect.size.h < UI_device_height)
                {
                    float               pan_x;
                    float               pan_y;
                    phoedt_pos_struct   shown_center;
                    phoedt_pos_struct   img_center;

                    shown_center.x =
                        g_phoedt_cui_cntx_p->image_info.shown_rect.offset.x + (g_phoedt_cui_cntx_p->image_info.shown_rect.size.w >> 1);
                    shown_center.y =
                        g_phoedt_cui_cntx_p->image_info.shown_rect.offset.y + (g_phoedt_cui_cntx_p->image_info.shown_rect.size.h >> 1);

                    img_center.x = g_phoedt_cui_cntx_p->image_info.curr_size.w >> 1;
                    img_center.y = g_phoedt_cui_cntx_p->image_info.curr_size.h >> 1;

                    pan_x = (float)(shown_center.x - img_center.x) / (float)img_center.x;
                    pan_y = (float)(shown_center.y - img_center.y) / (float)img_center.y;

                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IES_PREVIEW_SET_ZOOM_AND_PEN,
                        1.0f, pan_x, pan_y);

                    ies_ret = srv_ies_preview_set_zoom_and_pan(
                        g_phoedt_cui_cntx_p->ies_hdles.preview,
                        1.0f, pan_x, pan_y);
                    if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
                    {
                        cui_phoedt_exit_curr_phoart();
                        break;
                    }
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IES_PREVIEW_SET_RECT,
                        g_phoedt_cui_cntx_p->image_info.shown_rect.offset.x,
                        g_phoedt_cui_cntx_p->image_info.shown_rect.offset.y,
                        g_phoedt_cui_cntx_p->image_info.shown_rect.size.w,
                        g_phoedt_cui_cntx_p->image_info.shown_rect.size.h);

                    ies_ret = srv_ies_preview_set_zoom_rect(
                        g_phoedt_cui_cntx_p->ies_hdles.preview,
                        g_phoedt_cui_cntx_p->image_info.shown_rect.offset.x,
                        g_phoedt_cui_cntx_p->image_info.shown_rect.offset.y,
                        g_phoedt_cui_cntx_p->image_info.shown_rect.size.w,
                        g_phoedt_cui_cntx_p->image_info.shown_rect.size.h);
                    if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
                    {
                        cui_phoedt_exit_curr_phoart();
                        break;
                    }
                }
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IES_BEGIN_RENDER);
            ies_ret = srv_ies_preview_render(g_phoedt_cui_cntx_p->ies_hdles.preview);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IES_END_RENDER);

            if(SRV_IES_OK != ies_ret)
            {
                /* specific handle, if ies render half of the image, and error happen,
                must clear the layer to black and then blt, to avoid blt half of the image */
                gdi_layer_push_and_set_active(g_phoedt_cui_cntx_p->preview_layer);
                gdi_layer_clear(PHOEDT_IMAGE_CANVAS_COLOR);
                gdi_layer_pop_and_restore_active();
            }

            if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
            {
                cui_phoedt_exit_curr_phoart();
                break;
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IES_IMG_AREA_RECT,
                g_phoedt_cui_cntx_p->display_info.img_rect.offset.x,
                g_phoedt_cui_cntx_p->display_info.img_rect.offset.y,
                g_phoedt_cui_cntx_p->display_info.img_rect.size.w,
                g_phoedt_cui_cntx_p->display_info.img_rect.size.h);

            ies_ret = srv_ies_preview_get_canvas_rect(
                g_phoedt_cui_cntx_p->ies_hdles.preview,
                &g_phoedt_cui_cntx_p->display_info.img_rect.offset.x,
                &g_phoedt_cui_cntx_p->display_info.img_rect.offset.y,
                &g_phoedt_cui_cntx_p->display_info.img_rect.size.w,
                &g_phoedt_cui_cntx_p->display_info.img_rect.size.h);
            if(MMI_TRUE == PHOEDT_TRACE_AND_HANDLE_IES_RESULT_WITH_GID(GRP_ID_ROOT, ies_ret))
            {
                cui_phoedt_exit_curr_phoart();
                break;
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_IES_IMG_AREA_RECT,
                g_phoedt_cui_cntx_p->display_info.img_rect.offset.x,
                g_phoedt_cui_cntx_p->display_info.img_rect.offset.y,
                g_phoedt_cui_cntx_p->display_info.img_rect.size.w,
                g_phoedt_cui_cntx_p->display_info.img_rect.size.h);

            ret = MMI_TRUE;
        }
    }while(0);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_convert_distance_scrn2img
* DESCRIPTION
*  covert from screen coordinate system to image coordinate system
* PARAMETERS
*  len_in       [IN]    distance in screen coordinate system
* RETURNS
*  len_out
*****************************************************************************/
static S32 cui_phoedt_convert_distance_scrn2img(S32 len_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float  ratio_img2scrn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(0 != g_phoedt_cui_cntx_p->display_info.img_rect.size.w);

    ratio_img2scrn =
        (float)g_phoedt_cui_cntx_p->image_info.shown_rect.size.w / (float)g_phoedt_cui_cntx_p->display_info.img_rect.size.w;

    return (S32)(ratio_img2scrn * len_in);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_convert_distance_img2scrn
* DESCRIPTION
*  covert from image coordinate system to screen coordinate system
* PARAMETERS
*  len_in       [IN]    distance in image coordinate system
* RETURNS
*  len_out
*****************************************************************************/
static S32 cui_phoedt_convert_distance_img2scrn(S32 len_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float  ratio_scrn2img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(0 != g_phoedt_cui_cntx_p->image_info.shown_rect.size.w);

    ratio_scrn2img =
        (float)g_phoedt_cui_cntx_p->display_info.img_rect.size.w / (float)g_phoedt_cui_cntx_p->image_info.shown_rect.size.w;

    return (S32)(ratio_scrn2img * len_in);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_convert_offset_x_scrn2img
* DESCRIPTION
*  covert from screen coordinate system to image coordinate system
* PARAMETERS
*  x_in         [IN]    offset x in screen coordinate system
* RETURNS
*  len_out
*****************************************************************************/
static S32 cui_phoedt_convert_offset_x_scrn2img(S32 x_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         distance;
    S32         sign;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    distance = x_in - g_phoedt_cui_cntx_p->display_info.img_rect.offset.x;
    if(0 != distance)
    {
        sign = distance / abs(distance);
        distance = abs(distance);
        distance = cui_phoedt_convert_distance_scrn2img(distance);
        distance = sign * distance;
        return g_phoedt_cui_cntx_p->image_info.shown_rect.offset.x + distance;
    }
    else
    {
        return g_phoedt_cui_cntx_p->image_info.shown_rect.offset.x;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_convert_offset_y_scrn2img
* DESCRIPTION
*  covert from screen coordinate system to image coordinate system
* PARAMETERS
*  y_in         [IN]    offset y in screen coordinate system
* RETURNS
*  len_out
*****************************************************************************/
static S32 cui_phoedt_convert_offset_y_scrn2img(S32 y_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         distance;
    S32         sign;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    distance = y_in - g_phoedt_cui_cntx_p->display_info.img_rect.offset.y;
    if(0 != distance)
    {
        sign = distance / abs(distance);
        distance = abs(distance);
        distance = cui_phoedt_convert_distance_scrn2img(distance);
        distance = sign * distance;
        return g_phoedt_cui_cntx_p->image_info.shown_rect.offset.y + distance;
    }
    else
    {
        return g_phoedt_cui_cntx_p->image_info.shown_rect.offset.y;
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_get_rotate_app2ies
* DESCRIPTION
*  transfor rotate type
* PARAMETERS
*  r_in         [IN]    rotate type in app system
* RETURNS
*  rotate type in ies system
*****************************************************************************/
static srv_ies_rot_enum cui_phoedt_get_rotate_app2ies(const phoedt_rotate_enum r_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_rot_enum    r_out   = SRV_IES_ROT_0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(r_in)
    {
    case PHOEDT_ROTATE_0:
        {
            r_out = SRV_IES_ROT_0;
        }
        break;

    case PHOEDT_ROTATE_90:
        {
            r_out = SRV_IES_ROT_90;
        }
        break;

    case PHOEDT_ROTATE_180:
        {
            r_out = SRV_IES_ROT_180;
        }
        break;

    case PHOEDT_ROTATE_270:
        {
            r_out = SRV_IES_ROT_270;
        }
        break;

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */
    }
    return r_out;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_get_curr_move_info
* DESCRIPTION
*  get curr move info struct pointer
* PARAMETERS
*  void
* RETURNS
*  pointer of current move info
*****************************************************************************/
static phoedt_move_info_struct* cui_phoedt_get_curr_move_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_move_info_struct     *move_info  = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_phoedt_cui_cntx_p->curr_act.action)
    {
    #ifdef __MMI_PHOEDT_DOODLE__
        case PHOEDT_ACTION_TYPE_DOODLE:
            {
                move_info = &g_phoedt_cui_cntx_p->curr_act.para.doodle.move_info;
            }
            break;
    #endif /* #ifdef __MMI_PHOEDT_DOODLE__ */

        case PHOEDT_ACTION_TYPE_ICON:
            {
                move_info = &g_phoedt_cui_cntx_p->curr_act.para.icon.move_info;
            }
            break;

        case PHOEDT_ACTION_TYPE_CLIP:
            {
                move_info = &g_phoedt_cui_cntx_p->curr_act.para.clip.move_info;
            }
            break;

    #ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MTK_INTERNAL__ */
    }

    return move_info;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_get_adjust_para_icons
* DESCRIPTION
*  cui_phoedt_get_adjust_para_icons
* PARAMETERS
*  para_id      [IN]
*  icon         [OUT]
* RETURNS
*  pointer of current move info
*****************************************************************************/
static void cui_phoedt_get_adjust_para_icons(
    srv_ies_effect_param_enum   para_id,
    MMI_IMG_ID                  *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         count   = sizeof(g_phoedt_adjust_para_icons) / sizeof(g_phoedt_adjust_para_icons[0]);
    S32         idx     = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(idx = 0; idx < count; idx++)
    {
        if(g_phoedt_adjust_para_icons[idx].para_id == para_id)
        {
            if(NULL != icon)
            {
                *icon = g_phoedt_adjust_para_icons[idx].para_icon;
            }
            break;
        }
    }

    if(idx >= count)
    {
        if(NULL != icon)
        {
            *icon = PHOEDT_RES_DUMMY_ID;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_check_path_relationship
* DESCRIPTION
*  cui_phoedt_check_path_relationship
* PARAMETERS
*  ext_path         [IN]    external path, maybe the deleting folder or file ext.
*  ext_is_folder    [IN]    if ext_path is a folder path
*  int_path         [IN]    internal path, maybe photo editor's origianl filepath or new filepath
* RETURNS
*  PHOEDT_PATH_RELATIONSHIP_NONE            : not related at all
*  PHOEDT_PATH_RELATIONSHIP_SAME_DRV        : the two path only have the save drv letter
*  PHOEDT_PATH_RELATIONSHIP_N_LINE_FOLDER   : ext_path is a n-line parent of int_path
*  PHOEDT_PATH_RELATIONSHIP_1_LINE_FOLDER   : ext_path is the direct parent of int_path
*  PHOEDT_PATH_RELATIONSHIP_SAME_FILE       : ext_path is exactlly the same path with int_path
*****************************************************************************/
static phoedt_path_relationship_enum cui_phoedt_check_path_relationship(
    const WCHAR     *ext_path,
    const MMI_BOOL  ext_is_folder,
    const WCHAR     *int_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_path_relationship_enum   ret         = PHOEDT_PATH_RELATIONSHIP_NONE;
    S32                             int_len;
    S32                             ext_len;
    S32                             idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != g_phoedt_cui_cntx_p && GRP_ID_INVALID != g_phoedt_cui_cntx_p->cui_gid && NULL != ext_path && NULL != int_path)
    {
        int_len = mmi_wcslen(int_path);
        ext_len = mmi_wcslen(ext_path);

        if(ext_len <= int_len)
        {
            for(idx = 0; idx < int_len; idx++)
            {
                if(int_path[idx] != ext_path[idx])
                {
                    break;
                }
            }

            if(idx == int_len && MMI_FALSE == ext_is_folder)
            {
                ret = PHOEDT_PATH_RELATIONSHIP_SAME_FILE;
            }
            else if(idx == ext_len && ext_len == srv_fmgr_path_get_filename_pos(int_path))
            {
                ret = PHOEDT_PATH_RELATIONSHIP_1_LINE_FOLDER;
            }
            else if(idx > 3 && int_path[idx - 1] == '\\')
            {
                ret = PHOEDT_PATH_RELATIONSHIP_N_LINE_FOLDER;
            }
            else if(idx > 0)
            {
                ret = PHOEDT_PATH_RELATIONSHIP_SAME_DRV;
            }
        }
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_rh_save_cb
* DESCRIPTION
*  save background when user choose "Yes" on "Save pre edit" pop up screen.
*  this is used to handle reentry case
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_rh_save_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE       fs_handle;
    U16             filename_seq_no;
    WCHAR           filepath[PHOEDT_FULL_PATH_BUFFER_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filename_seq_no = 0;
    while(MMI_TRUE)
    {
        kal_wsprintf(filepath, "%c:\\Photoedit(%03d)_temp.jpg", SRV_FMGR_PUBLIC_DRV, filename_seq_no);

        fs_handle = FS_Open(filepath, FS_READ_ONLY);
        if(fs_handle >= FS_NO_ERROR)
        {
            FS_Close(fs_handle);
            filename_seq_no++;
        }
        else
        {
            break;
        }

        /* will overwrite existing function if exceed 100 */
        if(filename_seq_no == 100)
        {
            break;
        }
    }

    if(NULL != g_phoedt_cui_cntx_p &&
       GRP_ID_INVALID != g_phoedt_cui_cntx_p->cui_gid &&
       mmi_frm_group_is_present(g_phoedt_cui_cntx_p->cui_gid)) /* save phoart edit */
    {
        cui_phoedt_give_up_curr_change();

        cui_phoedt_enter_pre_popup_group();

        g_phoedt_cui_cntx_p->curr_act.action = PHOEDT_ACTION_TYPE_SAVE_FILE;
        g_phoedt_cui_cntx_p->curr_act.para.save.parent_gid = GRP_ID_PHOEDT_PRE_POPUP_GROUP;
        g_phoedt_cui_cntx_p->curr_act.para.save.is_bg_save = MMI_TRUE;
        g_phoedt_cui_cntx_p->curr_act.para.save.output_size = g_phoedt_cui_cntx_p->image_info.curr_size;
        g_phoedt_cui_cntx_p->curr_act.para.save.callback = cui_phoedt_save_background_callback;
        mmi_wcscpy(g_phoedt_cui_cntx_p->new_file.filepath, filepath);

        cui_phoedt_save_file();
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_rh_exit_cb
* DESCRIPTION
*  cui_phoedt_rh_exit_cb
* PARAMETERS
*  void
* RETURNS
*  mmi_ret
*****************************************************************************/
static void cui_phoedt_rh_exit_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_exit_curr_phoart();
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_rh_reentry_cb
* DESCRIPTION
*  cui_phoedt_rh_reentry_cb
* PARAMETERS
*  void
* RETURNS
*  mmi_ret
*****************************************************************************/
static void cui_phoedt_rh_reentry_cb(MMI_BOOL result, phoedt_rh_reentry_para_union *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_node_struct       cui_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE == result)
    {
        PHOEDT_SEND_TO_PARENT_NO_RESULT_WITH_GID(para->cui_para.self_gid, EVT_ID_CUI_PHOEDT_RESULT_FAILED);
        PHOEDT_SEND_TO_PARENT_NO_RESULT_WITH_GID(para->cui_para.self_gid, EVT_ID_CUI_PHOEDT_RESULT_CLOSE_ME);
    }
    else
    {
        /* to check if the parent is till exist */
        if(MMI_RET_OK != mmi_frm_group_get_info(para->cui_para.self_gid, &cui_group))
        {
            return;
        }

        if(MMI_FALSE == mmi_frm_group_is_present(cui_group.parent))
        {
            return;
        }

        MMI_ASSERT(NULL == g_phoedt_cui_cntx_p);

        if(MMI_FALSE == cui_phoedt_mem_malloc_memory(&para->cui_para))
        {
            return;
        }

        cui_phoedt_entry_cui_screens(&para->cui_para);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_fmgr_notify_hdlr
* DESCRIPTION
*  cui_phoedt_fmgr_notify_hdlr
* PARAMETERS
*  void
* RETURNS
*  mmi_ret
*****************************************************************************/
extern mmi_ret cui_phoedt_fmgr_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret         ret         = MMI_RET_OK;
    WCHAR           drv[PHOEDT_DRV_PATH_BUFFER_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL != g_phoedt_cui_cntx_p && GRP_ID_INVALID != g_phoedt_cui_cntx_p->cui_gid)
    {
        switch(evt->evt_id)
        {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            {
                srv_fmgr_notification_dev_plug_event_struct *plug_out =
                    (srv_fmgr_notification_dev_plug_event_struct*)evt;
                S32     count = plug_out->count;

                while(count > 0)
                {
                    kal_wsprintf(drv, "%c", plug_out->drv_letters[count - 1]);
                    if(PHOEDT_PATH_RELATIONSHIP_SAME_DRV <=
                        cui_phoedt_check_path_relationship(drv, MMI_TRUE, g_phoedt_cui_cntx_p->org_file.filepath))
                    {
                        cui_phoedt_exit_curr_phoart();

                        break;
                    }
                    else
                    {
                        if(PHOEDT_ACTION_TYPE_SAVE_FILE == g_phoedt_cui_cntx_p->curr_act.action ||
                            PHOEDT_ACTION_TYPE_SAVE_FOR_SEND == g_phoedt_cui_cntx_p->curr_act.action)
                        {
                            if(PHOEDT_PATH_RELATIONSHIP_SAME_DRV <=
                                cui_phoedt_check_path_relationship(drv, MMI_TRUE, g_phoedt_cui_cntx_p->new_file.filepath) &&
                                GRP_ID_INVALID != mmi_frm_group_is_present(GRP_ID_PHOEDT_EDIT_GROUP))    /* filename editor exists */
                            {
                                /* close filename editor */
                                mmi_frm_group_close(GRP_ID_PHOEDT_EDIT_GROUP);
                            }
                        }
                    }

                    count--;
                }
            }
            break;

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
            {
                srv_fmgr_notification_dev_soft_mount_event_struct *mount =
                    (srv_fmgr_notification_dev_soft_mount_event_struct*)evt;

                if(MMI_FALSE == mount->mount)
                {
                    kal_wsprintf(drv, "%c", mount->drv_letter);
                    if(PHOEDT_PATH_RELATIONSHIP_SAME_DRV <=
                        cui_phoedt_check_path_relationship(drv, MMI_TRUE, g_phoedt_cui_cntx_p->org_file.filepath))
                    {
                        cui_phoedt_exit_curr_phoart();
                    }
                }
            }
            break;

        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
            {
                srv_fmgr_notification_format_event_struct *format =
                    (srv_fmgr_notification_format_event_struct*)evt;

                if(SRV_FMGR_NOTIFICATION_STATE_QUERY == format->state)
                {
                    kal_wsprintf(drv, "%c", format->drv_letter);
                    if(PHOEDT_PATH_RELATIONSHIP_SAME_DRV <=
                        cui_phoedt_check_path_relationship(drv, MMI_TRUE, g_phoedt_cui_cntx_p->org_file.filepath))
                    {
                        ret = MMI_RET_ERR;
                    }
                }
            }
            break;

        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
            {
                srv_fmgr_notification_adv_action_event_struct *adv_act =
                    (srv_fmgr_notification_adv_action_event_struct*)evt;
                MMI_BOOL is_folder = (adv_act->src_fileinfo.attribute == FS_ATTR_DIR) ? MMI_TRUE : MMI_FALSE;

                if(SRV_FMGR_NOTIFICATION_STATE_QUERY == adv_act->state)
                {
                    switch(adv_act->action)
                    {
                        case SRV_FMGR_NOTIFICATION_ACTION_MOVE:
                        case SRV_FMGR_NOTIFICATION_ACTION_RENAME:
                        case SRV_FMGR_NOTIFICATION_ACTION_DELETE:
                            {
                                if(PHOEDT_PATH_RELATIONSHIP_N_LINE_FOLDER <=
                                    cui_phoedt_check_path_relationship(adv_act->src_filepath, is_folder, g_phoedt_cui_cntx_p->org_file.filepath))
                                {
                                    ret = MMI_RET_ERR;
                                }
                            }
                            break;

                        case SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL:
                            {
                                if(MMI_TRUE == FMGR_FILTER_IS_SET_IMAGE(adv_act->filter))
                                {
                                    if(PHOEDT_PATH_RELATIONSHIP_1_LINE_FOLDER <=
                                        cui_phoedt_check_path_relationship(adv_act->src_filepath, MMI_TRUE, g_phoedt_cui_cntx_p->org_file.filepath))
                                    {
                                        ret = MMI_RET_ERR;
                                    }
                                }
                                else if(FMGR_FILTER_IS_SET(adv_act->filter, FMGR_TYPE_ALL))
                                {
                                    if(PHOEDT_PATH_RELATIONSHIP_N_LINE_FOLDER <=
                                        cui_phoedt_check_path_relationship(adv_act->src_filepath, MMI_TRUE, g_phoedt_cui_cntx_p->org_file.filepath))
                                    {
                                        ret = MMI_RET_ERR;
                                    }
                                }
                            }
                            break;

                        default:
                            break;
                    }
                }
            }
            break;

        default:
            break;
        }
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_create
* DESCRIPTION
*  create g_phoedt_cui_cntx_p->cui_gid group for photo art cui
* PARAMETERS
*  parent_id    [IN]    parent group id
* RETURNS
*  phoart cui group id
*****************************************************************************/
extern MMI_ID cui_phoedt_create(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID      self_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CUI_CREATE, parent_id, self_gid);

    self_gid = mmi_frm_group_create(
        parent_id,
        GRP_ID_AUTO_GEN,
        cui_phoedt_proc,
        NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CUI_CREATE, parent_id, self_gid);

    return self_gid;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_run
* DESCRIPTION
*  start to run photo art cui
* PARAMETERS
*  p_args       [IN] you can call cui_phoedt_struct_init first to init the args and then set your values.
* RETURNS
*  void
*****************************************************************************/
extern void cui_phoedt_run(MMI_ID cui_gid, p_cui_phoedt_run_struct p_args)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_run_int(cui_gid, p_args, NULL, 0, MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_run
* DESCRIPTION
*  phoedt internal function
* PARAMETERS
*  p_args       [IN] you can call cui_phoedt_struct_init first to init the args and then set your values.
* RETURNS
*  void
*****************************************************************************/
extern void cui_phoedt_run_ext(
    MMI_ID cui_gid, p_cui_phoedt_run_struct p_args,
    PU8 memory, U32 memory_size, MMI_BOOL is_send_available)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_phoedt_run_int(cui_gid, p_args, memory, memory_size, is_send_available);
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_run
* DESCRIPTION
*  phoedt internal function
* PARAMETERS
*  p_args       [IN] you can call cui_phoedt_struct_init first to init the args and then set your values.
* RETURNS
*  void
*****************************************************************************/
static void cui_phoedt_run_int(
    MMI_ID cui_gid, p_cui_phoedt_run_struct p_args,
    PU8 memory, U32 memory_size, MMI_BOOL is_send_available)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phoedt_rh_reentry_para_union para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CUI_RUN, cui_gid);

    mmi_wcscpy(para.cui_para.filepath_buf, p_args->origin_filepath);
    para.cui_para.self_gid = cui_gid;
    para.cui_para.memory = memory;
    para.cui_para.is_send_available = is_send_available;

    if(MMI_FALSE == cui_phoedt_check_enter_format(para.cui_para))
    {
        return;
    }
    else
    {
        mmi_phoedt_rh_add_ins(
            &para,
            cui_phoedt_rh_save_cb,
            cui_phoedt_rh_exit_cb,
            cui_phoedt_rh_reentry_cb);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_close
* DESCRIPTION
*  close photo art cui
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void cui_phoedt_close(MMI_ID cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_PHOEDT_CUI_CLOSE, cui_gid);

    if(NULL != g_phoedt_cui_cntx_p && cui_gid == g_phoedt_cui_cntx_p->cui_gid)
    {
        mmi_frm_group_close(g_phoedt_cui_cntx_p->cui_gid);
    }
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_is_valide_size
* DESCRIPTION
*  check the image size limitation
* PARAMETERS
*  void
* RETURNS
*  support or not: PHOEDT_RES_DUMMY_ID means ok, others will be error str id
*****************************************************************************/
static MMI_STR_ID cui_phoedt_is_valide_size(const WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID      err_str_id  = PHOEDT_RES_DUMMY_ID;
    GDI_RESULT      gdi_ret;
    S32             width;
    S32             height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_ret = gdi_image_get_dimension_file((CHAR*)filepath, &width, &height);

    do{
        if(gdi_ret < 0 || width <= 0 || height <= 0)
        {
            err_str_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
            break;
        }

        if((width <= PHOEDT_MIN_IMG_WIDTH) ||
           (height <= PHOEDT_MIN_IMG_HEIGHT))
        {
            err_str_id = STR_ID_PHOEDT_NOTIFY_UNFIT_FOR_EDIT;
            break;

        }
    }while(MMI_FALSE);

    return err_str_id;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_is_supported_format
* DESCRIPTION
*  check if support the image format, now it do not support virtual file
* PARAMETERS
*  filepath         [IN]
* RETURNS
*  support or not
*****************************************************************************/
extern MMI_BOOL cui_phoedt_is_supported_format(const WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL    support = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(PHOEDT_RES_DUMMY_ID != cui_phoedt_is_supported_format_ext(filepath))
    {
        support = MMI_FALSE;
    }

    return support;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_is_supported_format_ext
* DESCRIPTION
*  check if support the image format, now it do not support virtual file
* PARAMETERS
*  filepath         [IN]
* RETURNS
*  support or not: PHOEDT_RES_DUMMY_ID means ok, others will be error str id
*****************************************************************************/
extern MMI_STR_ID cui_phoedt_is_supported_format_ext(const WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL        is_drm      = MMI_FALSE;
    WCHAR           path[PHOEDT_FULL_PATH_BUFFER_LEN];
    MMI_STR_ID      err_str_id  = PHOEDT_RES_DUMMY_ID;
    srv_ies_result  ret         = SRV_IES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(path, filepath);

    /* check DRM */
#ifdef __DRM_SUPPORT__
    if(DRM_METHOD_NONE != DRM_get_object_method(0, path))
    {
        is_drm = MMI_TRUE;
    }
#endif

    if(MMI_TRUE == is_drm)
    {
        err_str_id = STR_GLOBAL_DRM_PROHIBITED;
    }
    else
    {
        ret= srv_ies_util_is_file_supported(path);
        if(SRV_IES_OK != ret)
        {
            err_str_id = srv_ies_util_error_get_string(ret);
        }

        if(PHOEDT_RES_DUMMY_ID == err_str_id)
        {
            err_str_id = cui_phoedt_is_valide_size(path);
        }
    }

    return err_str_id;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_is_phoedt_event
* DESCRIPTION
*  to adjust if the evt is come from photo editor cui
* PARAMETERS
*  evt       [IN] group event
* RETURNS
*  void
*****************************************************************************/
extern MMI_BOOL cui_phoedt_is_phoedt_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id > EVT_ID_CUI_PHOEDT_BEGIN && evt->evt_id < EVT_ID_CUI_PHOEDT_END)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  cui_phoedt_struct_init
* DESCRIPTION
*  init photo art cui run struct
* PARAMETERS
*  p_args       [IN] you can call cui_phoedt_struct_init first to init the args and then set your values.
* RETURNS
*  void
*****************************************************************************/
extern void cui_phoedt_struct_init(p_cui_phoedt_run_struct p_args)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_args->origin_filepath = NULL;
}

#endif
#endif /* _PHOEDT_CUI_C_ */
