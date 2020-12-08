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
 *  wgui_side_bar.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sidebar - UI component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 
/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

#ifndef __WGUI_SIDE_BAR_H__
#define __WGUI_SIDE_BAR_H__

#include "MMI_features.h"

#ifdef __MMI_OP11_SIDEBAR__

#include "gui_side_bar.h"

#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"

typedef struct
{
    S32 no_popup_v_bar_index;
    mmi_gui_side_bar_state_enum state;
    S32 popup_menu_highlight_item;
    S32 popup_menu_first_display_item;
    S32 popup_menu_last_display_item;
} wgui_side_bar_history_struct;

extern void wgui_side_bar_register_left_arrow_key_handler(FuncPtr funcPtr, U16 keyType);
extern void wgui_side_bar_register_right_arrow_key_handler(FuncPtr funcPtr, U16 keyType);

extern void wgui_side_bar_create(
                    S32 x, S32 y,
                    S32 max_width,S32 max_height,
                    GDI_HANDLE side_bar_layer, GDI_HANDLE popout_menu_layer, GDI_HANDLE wallpaper_layer,
                    S32 number_of_side_bar_menu, 
                    PU8 *icons_of_side_bar_menu_normal, PU8 *icons_of_side_bar_menu_highlight,
                    wgui_sidebar_getindicator_funcptr_type *get_indicators_callback, 
                    wgui_sidebar_getmenudata_funcptr_type *get_menu_data_callback,
                    wgui_sidebar_popout_menu_highlighthandler_funcptr_type *menu_highlight_handler);
            
extern void wgui_side_bar_show(void);
extern void wgui_side_bar_close(void);

extern void wgui_side_bar_update_indicators(S32 side_bar_menu_index);

extern void wgui_side_bar_register_left_arrow_key_handler(FuncPtr funcPtr, U16 keyType);
extern void wgui_side_bar_register_right_arrow_key_handler(FuncPtr funcPtr, U16 keyType);

extern void wgui_side_bar_redraw_bar(void);
extern void wgui_side_bar_redraw_popout_menu(void);
extern void wgui_side_bar_redraw_indicators(void);

extern void wgui_side_bar_move(S32 x, S32 y);
extern void wgui_side_bar_resize(S32 max_width, S32 max_height);
extern void wgui_side_bar_set_layers(GDI_HANDLE side_bar_layer, GDI_HANDLE popout_menu_layer, GDI_HANDLE wallpaper_layer);

extern void wgui_side_bar_get_history(wgui_side_bar_history_struct *history);
extern void wgui_side_bar_set_history(wgui_side_bar_history_struct * history);

extern void wgui_side_bar_update_popout_menu(void);
extern void wgui_side_bar_get_popout_menu_layout(UI_font_type *command_font, UI_font_type *data_font, 
        S32 *command_width, S32 *data_width);
extern void wgui_side_bar_register_highlight_handler(wgui_sidebar_popout_side_bar_highlighthandler_funcptr_type handler);
extern void wgui_side_bar_reset_to_inactive(void);
extern void wgui_side_bar_redraw(void);


#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL wgui_side_bar_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);
#endif /* __MMI_TOUCH_SCREEN__ */

#endif /* __MMI_OP11_SIDEBAR__ */
#endif /* __WGUI_SIDE_BAR_H__ */


