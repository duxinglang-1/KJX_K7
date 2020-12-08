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
 * wgui_status_icon_bar.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WGUI_STATUS_ICON_BAR_H__
#define __WGUI_STATUS_ICON_BAR_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "gui_typedef.h"
#include "gui_status_icon.h"

#include "MMIDataType.h"
#include "gui_status_icon_bar.h"


/****************************************************************************
 * Macro
 ****************************************************************************/

/* The timer of blinking and animating icon */
#if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3))
#define WGUI_STATUS_ICON_BAR_TIMER_RATE                     (1000)
#else
#define WGUI_STATUS_ICON_BAR_TIMER_RATE                     (500)
#endif

/* Max number of icon show in mainlcd horizontal status icon bar */
#define WGUI_STATUS_ICON_BAR_MAINLCD_H_ICON_LIST_NUM        (18)
/* Max number of icon show in mainlcd vertical status icon bar */
#define WGUI_STATUS_ICON_BAR_MAINLCD_V_ICON_LIST_NUM        (8)
/* Max number of icon show in sublcd horizontal status icon bar */
#define WGUI_STATUS_ICON_BAR_SUBLCD_ICON_LIST_NUM           (6)

/* Max number of element show in status icon bar */
#define WGUI_STATUS_ICON_BAR_ELEMENT_NUM                    (3)
#define WGUI_STATUS_ICON_BAR_ELEMENT_MAINLCD_H_LIST_NUM     (3)

#ifdef __MMI_LCD_PARTIAL_ON__
/* Max number of icon show in partial screen */
#define WGUI_STATUS_ICON_BAR_PARTIAL_ICON_LIST_NUM          (4)
#endif


/****************************************************************************
 * Struct
 ****************************************************************************/

typedef struct
{
    /* The icon id of status icon */
    S32 icon_id;
    /* The image id of status icon */
    S32 image_id;
    /* The group of status icon */
    gui_status_icon_bar_icon_group_enum group;
} wgui_status_icon_bar_icon_image_map_struct;

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
extern S32 wgui_status_icon_bar_clock_element_id;
#endif

extern gui_status_icon_bar_struct wgui_status_icon_bar_bars[];
extern S32 wgui_status_icon_bar_horizontal_icon_list[];
extern S32 wgui_status_icon_bar_vertical_icon_list[];
extern S32 wgui_status_icon_bar_sublcd_horizontal_icon_list[];
extern S32 wgui_status_icon_bar_mainlcd_horizontal_element_list[];
extern gui_status_icon_bar_icon_struct wgui_status_icon_bar_icons[];
extern gui_status_icon_bar_element_struct wgui_status_icon_bar_elements[];
extern gui_status_icon_bar_struct wgui_status_icon_bar_bars[];

#ifdef __MMI_LCD_PARTIAL_ON__
extern S32 wgui_status_icon_bar_partial_list_display[];
extern S16 wgui_status_icon_bar_partial_display_icon_number;
#endif
#ifdef __MMI_VUI_ENGINE__
extern void wgui_status_icon_bar_add_instance(wgui_status_icon_bar_enum bar_id, status_icon_bar_chain_node_struct* chain_node);

extern void wgui_status_icon_bar_del_instance(wgui_status_icon_bar_enum bar_id, status_icon_bar_chain_node_struct* chain_node);
#endif

#endif /* __WGUI_STATUS_ICON_BAR_H__ */

