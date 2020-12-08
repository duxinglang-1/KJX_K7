/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *  vcp_res.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the image, and string resource ID for the Venus
 *  components.
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
#ifndef VCP_RES_H
#define VCP_RES_H

#include "MMIDataType.h"
#include "mmi_features.h"

#ifdef __MMI_VUI_ENGINE__
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "mmi_rp_srv_venus_component_button_def.h"
#include "mmi_rp_srv_venus_component_tab_bar_def.h"
#include "mmi_rp_srv_venus_component_segment_button_def.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "mmi_rp_srv_venus_component_switch_def.h"
#include "mmi_rp_srv_venus_component_scrollable_def.h"
#endif

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_srv_venus_component_tab_title_bar_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_venus_component_info_balloon_def.h"
#include "mmi_rp_srv_venus_component_activity_indicator_def.h"
#include "mmi_rp_srv_venus_component_form_def.h"
#include "mmi_rp_srv_venus_component_function_bar_def.h"
#include "mmi_rp_srv_venus_component_progress_indicator_def.h"
#include "mmi_rp_srv_venus_component_title_bar_def.h"  // Should be nav_title_bar
#endif

#ifdef __MMI_VUI_ENGINE__
#if !defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_srv_venus_component_softkey_def.h"
#include "mmi_rp_srv_venus_component_command_title_def.h"
#include "mmi_rp_srv_venus_component_inline_menu_def.h"
#include "mmi_rp_srv_venus_component_option_menu_def.h"
#include "mmi_rp_srv_venus_component_waiting_icon_def.h"
#endif
#endif

 /**********************************************************************
 * Venus home screen string ID definitions:
 **********************************************************************/
typedef enum
{
    VCP_STR_BEGIN = VENUS_COMPONENTS_BASE,
        
 
    VCP_STR_END
} VCP_STR_ENUM;


 /**********************************************************************
 * Venus home screen image ID definitions:
 **********************************************************************/
typedef enum
{
    VCP_IMG_BEGIN = VENUS_COMPONENTS_BASE,
        
    /******************************************************************
     * Scrollbar image IDs:
     ******************************************************************/
    VCP_IMG_SCROLL_BTN_UP_N,
    VCP_IMG_SCROLL_BTN_UP_P,
    VCP_IMG_SCROLL_BTN_DOWN_N,
    VCP_IMG_SCROLL_BTN_DOWN_P,
    VCP_IMG_SCROLL_BG_N,
    VCP_IMG_SCROLL_BG_P,
    VCP_IMG_SCROLL_BG_EFFECT,
    VCP_IMG_SCROLL_CURSOR_P,    
    VCP_IMG_SCROLL_CURSOR_N,    
    
    VCP_IMG_END
} VCP_IMG_ENUM;

typedef enum
{
    VTST_IMG_SCROLLBAR_BG2_N = VCP_IMG_END,
    VTST_IMG_SCROLLBAR_BG2_P,
    VTST_IMG_SCROLLBAR_BG4_N,
    VTST_IMG_SCROLLBAR_BG4_P,
    VTST_IMG_SCROLLBAR_BG5_N,
    VTST_IMG_SCROLLBAR_BG5_P,
    VTST_IMG_SCROLLBAR_BG_ANIM,
    VTST_IMG_SCROLLBAR_BG_ANIM2,
    VTST_IMG_SCROLLBAR_BG_EFFECT4,
    VTST_IMG_SCROLLBAR_BG_EFFECT5,
    VTST_IMG_SCROLLBAR_BG_N,
    VTST_IMG_SCROLLBAR_BG_P,
    VTST_IMG_SCROLL_BTN_DOWN2_H,
    VTST_IMG_SCROLL_BTN_DOWN2_N,
    VTST_IMG_SCROLL_BTN_DOWN2_P,
    VTST_IMG_SCROLL_BTN_DOWN4_N,
    VTST_IMG_SCROLL_BTN_DOWN4_P,
    VTST_IMG_SCROLL_BTN_DOWN5_N,
    VTST_IMG_SCROLL_BTN_DOWN5_P,
    VTST_IMG_SCROLL_BTN_DOWN_G,
    VTST_IMG_SCROLL_BTN_DOWN_H,
    VTST_IMG_SCROLL_BTN_DOWN_N,
    VTST_IMG_SCROLL_BTN_DOWN_P,
    VTST_IMG_SCROLL_BTN_UP2_H,
    VTST_IMG_SCROLL_BTN_UP2_N,
    VTST_IMG_SCROLL_BTN_UP2_P,
    VTST_IMG_SCROLL_BTN_UP4_N,
    VTST_IMG_SCROLL_BTN_UP4_P,
    VTST_IMG_SCROLL_BTN_UP5_N,
    VTST_IMG_SCROLL_BTN_UP5_P,
    VTST_IMG_SCROLL_BTN_UP_G,
    VTST_IMG_SCROLL_BTN_UP_H,
    VTST_IMG_SCROLL_BTN_UP_N,
    VTST_IMG_SCROLL_BTN_UP_P,
    VTST_IMG_SCROLL_CURSOR2_N,
    VTST_IMG_SCROLL_CURSOR2_P,
    VTST_IMG_SCROLL_CURSOR4_N,
    VTST_IMG_SCROLL_CURSOR4_P,
    VTST_IMG_SCROLL_CURSOR5_N,
    VTST_IMG_SCROLL_CURSOR5_P,
    VTST_IMG_SCROLL_CURSOR_N,
    VTST_IMG_SCROLL_CURSOR_P,
    VTST_IMG_SCRTEST_BG
}VTST_IMG_ENUM;

#endif /* VCP_RES_H */
