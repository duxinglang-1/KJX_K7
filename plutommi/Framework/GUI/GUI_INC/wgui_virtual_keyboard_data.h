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
 *   wgui_virtual_keyboard_data.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Virtual Keyboard - UI Component
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WGUI_VIRTUAL_KEYBOARD_DATA_H__
#define __WGUI_VIRTUAL_KEYBOARD_DATA_H__

#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__

#include "wgui_virtual_keyboard.h"
#include "wgui_categories_defs.h"
#include "gui_virtual_keyboard_res.h"
    #include "MMI_features.h"
    #include "gui_virtual_keyboard_language_type.h"
    #include "gui_virtual_keyboard.h"
    #include "kal_non_specific_general_types.h"
    #include "MMIDataType.h"

#if defined(__MMI_TOUCH_SCREEN__)
/***************************************************************************** 
* Define
*****************************************************************************/
wgui_virtual_keyboard_layout_struct const gui_virtual_keyboard_empty_tray_layout =
{
    0,                                  /* resolution width */
    0,                                  /* resolution height */
    0,                                  /* width */
    0,                                  /* height */
    0,                                  /* count */
    NULL,                               /* bg_id */
    GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY,    /* language */
    GUI_VIRTUAL_KEYBOARD_ALIGN_END,     /* align type */
    MMI_FALSE,                          /* is_rotate */
    MMI_FALSE,                          /* is_round_rect */
    MMI_FALSE,                          /* is rotate support */
    NULL,                               /* key list pointer */
};

wgui_virtual_keyboard_layout_struct const gui_virtual_keyboard_layout_end =
{
    0,                                  /* resolution width */
    0,                                  /* resolution height */
    0,                                  /* width */
    0,                                  /* height */
    0,                                  /* count */
    NULL,                               /* bg_id */
    GUI_VIRTUAL_KEYBOARD_MAX_LANG,      /* language */
    GUI_VIRTUAL_KEYBOARD_ALIGN_END,     /* align type */
    MMI_FALSE,                          /* is_rotate */
    MMI_FALSE,                          /* is_round_rect */
    MMI_FALSE,                          /* is rotate support */
    NULL,                               /* key list pointer */
};

#define VK_LAYOUT_KEY                      gui_virtual_keyboard_key_struct
#define VK_LAYOUT_PROJECT                 wgui_virtual_keyboard_layout_struct
#define VK_LAYOUT_KEY_PTR                   gui_virtual_keyboard_key_struct_p const
#define VK_LAYOUT_PROJECT_PTR                 wgui_virtual_keyboard_layout_struct_p const

#define VK_LAYOUT_DATA_BODY
    #include "VKB.dat"

    wgui_virtual_keyboard_layout_struct_p wgui_virtual_keyboard_layout_list[] =
    {
    #undef VK_LAYOUT_DATA_BODY
        #include "VKB.dat"
        (VK_LAYOUT_PROJECT_PTR)&gui_virtual_keyboard_empty_tray_layout,
        (VK_LAYOUT_PROJECT_PTR)&gui_virtual_keyboard_layout_end
    };
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__ */

#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__

#include "wgui_virtual_keyboard.h"
#include "wgui_categories_defs.h"
    #include "MMI_features.h"
    #include "gui_virtual_keyboard_language_type.h"
    #include "gui_virtual_keyboard.h"
    #include "kal_non_specific_general_types.h"
    #include "MMIDataType.h"

#if defined(__MMI_TOUCH_SCREEN__)
/***************************************************************************** 
* Define
*****************************************************************************/
    wgui_virtual_keyboard_layout_struct const gui_virtual_keyboard_empty_tray_layout =
    {
        0,  //height
        0,  //width
        0,  //background image id

        0,  //margin_x x
        0,  //margin_y y
        0,  //row num
        NULL,    //row_list
        GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY,    //keyboard type
        0,  //vk_attribute
        MMI_FALSE,  //is rotate
        MMI_FALSE,  //is shift support
        MMI_FALSE,  //is chache
        NULL    //key type list
    };

    wgui_virtual_keyboard_layout_struct const gui_virtual_keyboard_layout_end =
    {
        0,  //height
        0,  //width
        0,  //background image id

        0,  //margin_x x
        0,  //margin_y y
        0,  //row num
        NULL,    //row_list
        GUI_VIRTUAL_KEYBOARD_MAX_LANG,    //keyboard type
        0,  //vk_attribute
        MMI_FALSE,  //is rotate
        MMI_FALSE,  //is shift support
        MMI_FALSE,  //is chache
        NULL    //key type list
    };


#include "virtual_keyboard3_res.h"

#ifndef __IMEHW_DCM_SUPPORT__
const wgui_virtual_keyboard_layout_struct* wgui_virtual_keyboard_layout_list = keyBoardTable;
#else
const wgui_virtual_keyboard_layout_struct* wgui_virtual_keyboard_layout_list = NULL;
#endif
    
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__ */

#endif /* __WGUI_VIRTUAL_KEYBOARD_DATA_H__ */ 

