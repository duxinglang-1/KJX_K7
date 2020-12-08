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
 * gui_status_icon_bar.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for status icon bars control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __GUI_STATUS_ICON_BAR_H__
#define __GUI_STATUS_ICON_BAR_H__

#include "wgui_categories.h"
#include "wgui_include.h"

#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "kal_general_types.h"

#if defined (WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT) ||defined (__MMI_FTE_SUPPORT__) ||defined (__COSMOS_MMI_PACKAGE__)
    #ifndef WGUI_STATUS_ICON_SHOW_ELEMENT
    #define WGUI_STATUS_ICON_SHOW_ELEMENT
    #endif
#endif

/****************************************************************************
 * Struct
 ****************************************************************************/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
#define WGUI_STATUS_ICON_BAR_EVENTS_NUM      10
#define WGUI_STATUS_ICON_BAR_EVENTS_COUNT      (STATUS_ICON_MAINLCD_LEFT_REGION_END - STATUS_ICON_MAINLCD_LEFT_REGION_START + 1)
#endif

#if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__))
#define WGUI_STATUS_ICON_BAR_FADE_MAX_STEP         5

typedef enum
{
    WGUI_STATUS_ICON_BAR_INFO_HIDE,
    WGUI_STATUS_ICON_BAR_INFO_FADE_IN,
    WGUI_STATUS_ICON_BAR_INFO_FADE_OUT,
    WGUI_STATUS_ICON_BAR_INFO_SHOW,
    WGUI_STATUS_ICON_BAR_INFO_START_SHOW,
    WGUI_STATUS_ICON_BAR_EVENTS_HIDE,
    EVT_ID_STATUS_ICON_BAR_INFO_MAX
} status_icon_bar_info_enum;

typedef enum
{
    WGUI_STATUS_ICON_BAR_ICON_TYPE_RESOURCE,
    WGUI_STATUS_ICON_BAR_ICON_TYPE_MEM,
    WGUI_STATUS_ICON_BAR_ICON_TYPE_FILE,
    WGUI_STATUS_ICON_BAR_ICON_TYPE_MAX
}status_icon_bar_icon_type;

#endif

typedef enum
{
    WGUI_STATUS_ICON_BAR_UPDATE_AUTO,
    WGUI_STATUS_ICON_BAR_UPDATE_ALL,
    WGUI_STATUS_ICON_BAR_UPDATE_ALL_EXCEPT_CLOCK,
    WGUI_STATUS_ICON_BAR_UPDATE_TYPE_NUM    
}status_icon_bar_update_type_enum;

typedef struct _status_icon_bar_chain_node_struct
{
    void *instance;
    void (*update_screen_callback)(void *handle);
    struct _status_icon_bar_chain_node_struct *prev;
    struct _status_icon_bar_chain_node_struct *next;
}status_icon_bar_chain_node_struct;

typedef struct
{
    /* The coordinate of status icon bar */
    S32 x, y;
    /* The size of status icon bar */
    S32 width, height;
    /* The flag of status icon bar */
    U32 flags;
    /* The clip of status icon bar */
    S32 x1, y1, x2, y2;
    /* The target lcd of status icon bar */
    gdi_handle target_lcd;
    /* The target layer of status icon bar */
    gdi_handle target_layer;
    /* The alpha blend(abm) layer of status icon bar */
    gdi_handle alpha_blend_layer;
    /* The hide callback of status icon bar */
    void (*hide_callback)(void);
    /* The pointer to the display icon id array */
    S32 *icon_list;
    /* The pointer to the display element id array */
    S32 *element_list;
    /* The number of icon in display array */
    S16 n_icons;
    /* The number of element in display array */
    S16 n_elements;
    /* Whether rotate or not */
    MMI_BOOL rotate_flag_for_wap;
#ifdef __MMI_VUI_ENGINE__
    S32 instance_count;
    status_icon_bar_chain_node_struct *chain_head;
#endif /* __MMI_VUI_ENGINE__ */
    void (*IME_callback)(S32 x1, S32 y1, S32 x2, S32 y2);
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    S32  bar_id;
    S32  all_show_events[WGUI_STATUS_ICON_BAR_EVENTS_COUNT];
    S32  n_all_events;
#endif
#if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__))
    status_icon_bar_info_enum  info_state; 
    status_icon_bar_info_enum  previous_state;
    PU8 info_icon_image;
    U32 info_icon_type;
    S32 info_icon_size;
    U8 info_icon_format;
    S32  count;
    S32  fade_step;
    UI_string_type info_string;
    void *param;
    void (*info_callback)(status_icon_bar_info_enum state, void* param);
#endif /* defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__) */
    S32  warning_info_w;
    UI_string_type warning_info_string;

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    S32 n_signal;
    S32 n_sms_full;
#endif
#if (defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    S32 new_icon_id;
#endif
    status_icon_bar_update_type_enum update_type;
} gui_status_icon_bar_struct;


/****************************************************************************
 * Function
 ****************************************************************************/
extern gdi_handle gui_status_icon_bar_setup_target_lcd_and_layer(gui_status_icon_bar_struct * bar);
extern void gui_status_icon_bar_restore_target_lcd_and_layer(gui_status_icon_bar_struct * bar, gdi_handle old_lcd_handle);
extern void gui_status_icon_bar_enable_rotate_for_wap(gui_status_icon_bar_struct *bar, MMI_BOOL enable);
extern void gui_status_icon_bar_enable_double_buffer(gui_status_icon_bar_struct *bar, MMI_BOOL enable);
extern MMI_BOOL gui_status_icon_bar_whether_double_buffer(gui_status_icon_bar_struct *bar);
extern void gui_status_icon_bar_redraw(gui_status_icon_bar_struct *bar);
extern void (*gui_status_icon_bar_show)(gui_status_icon_bar_struct *bar);
extern void (*gui_status_icon_bar_hide)(gui_status_icon_bar_struct *bar);
extern void (*gui_status_icon_bar_arrange)(void);
extern void (*gui_status_icon_bar_show_sublcd_horizontal_background)(S32 x1, S32 y1, S32 x2, S32 y2);
extern void gui_status_icon_bar_initialize(void);
extern void gui_status_icon_bar_close(gui_status_icon_bar_struct *bar);
extern void gui_status_icon_bar_enable_display(gui_status_icon_bar_struct *bar, MMI_BOOL enable);
extern MMI_BOOL gui_status_icon_bar_is_display(gui_status_icon_bar_struct *bar);
extern void gui_status_icon_bar_enable_background(gui_status_icon_bar_struct *bar, MMI_BOOL enable);
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
extern void gui_status_icon_bar_enable_special_style(gui_status_icon_bar_struct *bar, MMI_BOOL enable, MMI_BOOL transparent);
extern void gui_status_icon_bar_set_background_id(gui_status_icon_bar_struct *bar, S32 id);
#endif
extern void gui_status_icon_bar_set_flag(gui_status_icon_bar_struct *bar, U32 flag);
extern U32  gui_status_icon_bar_get_flag(gui_status_icon_bar_struct *bar);
extern void gui_status_icon_bar_set_clip(gui_status_icon_bar_struct *bar, S32 x1, S32 y1, S32 x2, S32 y2);
extern void gui_status_icon_bar_get_clip(gui_status_icon_bar_struct *bar, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
extern void gui_status_icon_bar_set_target_lcd(gui_status_icon_bar_struct *bar, gdi_handle target_lcd);
extern gdi_handle gui_status_icon_bar_get_target_lcd(gui_status_icon_bar_struct *bar);
extern void gui_status_icon_bar_set_target_layer(gui_status_icon_bar_struct *bar, gdi_handle target_layer);
extern gdi_handle gui_status_icon_bar_get_target_layer(gui_status_icon_bar_struct *bar);
extern void gui_status_icon_bar_set_alpha_blend_layer(gui_status_icon_bar_struct *bar, gdi_handle alpha_blend_layer);
extern gdi_handle gui_status_icon_bar_get_alpha_blend_layer(gui_status_icon_bar_struct *bar);
extern void gui_status_icon_bar_move(gui_status_icon_bar_struct *bar, S32 x, S32 y);
extern void gui_status_icon_bar_resize(gui_status_icon_bar_struct *bar, S32 width, S32 height);
extern void gui_status_icon_bar_register_hide_callback(gui_status_icon_bar_struct *bar, void (*hide_callback)(void));

extern void gui_status_icon_bar_register_IME_callback(gui_status_icon_bar_struct *bar, void (*IME_callback)(S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_status_icon_bar_reset_IME_callback(gui_status_icon_bar_struct *bar);

#endif /* __GUI_STATUS_ICON_BAR_H__ */

