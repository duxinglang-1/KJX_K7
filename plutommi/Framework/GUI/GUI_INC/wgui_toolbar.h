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
 *  wgui_toolbar.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Toolbar - UI component
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

#ifndef __WGUI_TOOLBAR_H__
#define __WGUI_TOOLBAR_H__

#include "MMI_features.h"

#ifdef __MMI_OP12_TOOLBAR__

#include "gui_toolbar.h"

/* typedef */
typedef struct
{
     mmi_gui_toolbar_state_enum toolbar_state;
     mmi_gui_toolbar_popout_menu_state_enum menu_state[GUI_TOOLBAR_MAX_MENU];
     S32 popout_menu_index; /* module index */
     S32 popout_menu_highlight; /* menu highlight */
     S32 popout_menu_first_item;
} wgui_toolbar_history_struct;


/* extern APIs */
extern void wgui_toolbar_get_history(wgui_toolbar_history_struct *history);
extern void wgui_toolbar_set_history(wgui_toolbar_history_struct * history);
extern void wgui_toolbar_create(
                S32 x, S32 y,
                S32 max_width,S32 max_height,
                GDI_HANDLE toolbar_layer, 
                GDI_HANDLE popout_menu_layer, 
                GDI_HANDLE wallpaper_layer,
                S32 number_of_toolbar_menu, 
                PU8 *icons_of_toolbar_menu_normal, 
                PU8 *icons_of_toolbar_menu_highlight,
                wgui_toolbar_getmenudata_funcptr_type *get_menu_data_callback,
                wgui_toolbar_popout_menu_highlighthandler_funcptr_type *menu_highlight_handler,
                mmi_gui_toolbar_popout_menu_state_enum *popout_menu_state);
extern void wgui_toolbar_close(void);
extern void wgui_toolbar_show(void);
extern void wgui_toolbar_move(S32 x, S32 y);
extern void wgui_toolbar_resize(S32 max_width, S32 max_height);
extern void wgui_toolbar_set_layers(
                GDI_HANDLE toolbar_layer, 
                GDI_HANDLE popout_menu_layer, 
                GDI_HANDLE wallpaper_layer);
extern void wgui_toolbar_set_bar_state(mmi_gui_toolbar_state_enum state);
extern void wgui_toolbar_redraw(void);
extern void wgui_toolbar_update_popout_menu(void);
extern void wgui_toolbar_set_popout_menu_state(S32 index, mmi_gui_toolbar_popout_menu_state_enum state);
extern void wgui_toolbar_change_bar_icon(S32 index, PU8 icon_normal, PU8 icon_highlight);
extern MMI_BOOL wgui_toolbar_is_active(void);
extern void wgui_toolbar_change_popout_menu_highlight(S32 index, S32 highlight_position);

#endif /* __MMI_OP12_TOOLBAR__ */
#endif /* __WGUI_TOOLBAR_H__ */


