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
 *   wgui_tab_bars.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Tab Bar - Category component
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/


#ifndef _WGUI_TAB_BARS_H
#define _WGUI_TAB_BARS_H

/***************************************************************************** 
* Include
*****************************************************************************/
#include "wgui.h"
#include "gui_tab_bars.h"
#include "wgui_include.h"

/***************************************************************************** 
* Define
*****************************************************************************/

#define UI_MAX_TAB_BAR_ITEMS     20

#ifdef __MMI_WGUI_MINI_TAB_BAR__

#define MAX_MINI_TAB_BAR_ITEMS   16
#define WGUI_MINI_TAB_BAR_ENABLED   0x00000001
#define WGUI_MINI_TAB_BAR_IN_PARENT 0x00000002

#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 

/***************************************************************************** 
* Typedef 
*****************************************************************************/


#ifdef __MMI_WGUI_MINI_TAB_BAR__

typedef struct _MINI_TAB_BAR_STRUCT
{
    S32 x, y;                                           /* coordinates */
    S32 width, height;                                  /* size of mini tab bar */
    color bg_color;                                     /* background color */
    color selected_item_color;                          /* selected item color */
    color normal_item_color;                            /* normal item color */
    U8 num_of_items;                                    /* Number of items in tab */
    U8 curr_index;                                      /* currently highlighted item index (start from 0) */
    U16 menu_item_id[MAX_MINI_TAB_BAR_ITEMS];           /* ID of each menuitem in tab */
    FuncPtr item_entry_func[MAX_MINI_TAB_BAR_ITEMS];    /* Entry function of each menuitem in tab */
    S32 flags;                                          /* Information & state flag */
    /* target lcd of mini tab bar */
    gdi_handle target_lcd;
    /* target layer of mini tab bar */
    gdi_handle target_layer;
    /* the alpha blend layer of mini tab bar */
    gdi_handle alpha_blend_layer;
    /* hide callback function of mini tab bar, use to hide the mini tab bar */
    void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2);
} gui_mini_tab_bar_struct;

#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

extern horizontal_tab_bar MMI_horizontal_tab_bar;
extern tab_bar_item_type MMI_tab_bar_items[UI_MAX_TAB_BAR_ITEMS];
extern UI_window_title_theme *current_tab_title_theme;



#endif /* _WGUI_TAB_BARS_H */ 


