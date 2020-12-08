/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_cal_edit.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  implementation of Add/Edit event/task screen
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
 
/***************************************************************************** 
* Include
*****************************************************************************/
extern "C" 
{	
#include "todolistsrvgprot.h"
#include "app_datetime.h"
#include "custom_mmi_default_value.h"
#include "unicodexdcl.h"
#include "vcalsrvgprot.h"
#include "generalsettingsrvgprot.h"
}

#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif


#include "globalresdef.h"

#include "mmi_rp_srv_venus_component_popup_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_calendar_def.h"

#include "vfx_base_popup.h" // include for vcp_info_balloon.h
#include "vfx_system.h"
#include "vfx_screen.h"
#include "vfx_font_desc.h"

#include "vcp_button.h"
#include "vcp_date_picker.h"
#include "vcp_function_bar.h"
#include "vcp_global_popup.h"
#include "vcp_info_balloon.h"
#include "vcp_navi_title_bar.h"
#include "vcp_time_picker.h"
#include "vcp_tool_bar.h"


#include "vapp_nmgr_gprot.h"
#include "vapp_cal_utility.h"
#include "vapp_cal_edit.h"
#ifndef __MMI_VCALENDAR__
#pragma arm section code = "DYNAMIC_CODE_CLNDR_ROCODE", rodata = "DYNAMIC_CODE_CLNDR_RODATA"
#endif
/***************************************************************************** 
 * Definition
 *****************************************************************************/
//data picker popup UI layout
#if defined(__MMI_MAINLCD_320X480__)

    #define VAPP_CAL_DATE_PICKER_POPUP_LR_GAP 10
    #define VAPP_CAL_DATE_PICKER_POPUP_WIDTH (VCP_DATE_PICKER_WIDTH + 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP)
    #define VAPP_CAL_DATE_PICKER_POPUP_TD_GAP 10
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_HEIGHT 45
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT 30
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_WIDTH  (VAPP_CAL_DATE_PICKER_POPUP_WIDTH - 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP)
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_X 8
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_Y 3
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP 20
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP 6
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_GAP 13
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_SHADOW 8
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH ((VAPP_CAL_DATE_PICKER_POPUP_WIDTH - VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP - 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP) / 2)
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_FONT   VFX_FONT_DESC_VF_SIZE(20)
    //time picker popup UI layout
    #define VAPP_CAL_TIME_PICKER_POPUP_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_LR_GAP   VAPP_CAL_DATE_PICKER_POPUP_LR_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_TD_GAP   VAPP_CAL_DATE_PICKER_POPUP_TD_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_HEIGHT    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_HEIGHT
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_HEIGHT    VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_X    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_X
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_Y    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_Y
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_TOP_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_MID_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_BOTTOM_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_FONT   VAPP_CAL_DATE_PICKER_POPUP_TITLE_FONT

#elif defined(__MMI_MAINLCD_480X800__)

    #define VAPP_CAL_DATE_PICKER_POPUP_LR_GAP 15
    #define VAPP_CAL_DATE_PICKER_POPUP_WIDTH (VCP_DATE_PICKER_WIDTH + 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP)
    #define VAPP_CAL_DATE_PICKER_POPUP_TD_GAP 12
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_HEIGHT 60
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT 40
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_WIDTH  (VAPP_CAL_DATE_PICKER_POPUP_WIDTH - 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP)
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_X 20
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_Y 6
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP 28
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP 10
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_GAP 13
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_SHADOW 14
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH ((VAPP_CAL_DATE_PICKER_POPUP_WIDTH - VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP - 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP) / 2)
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_FONT   VFX_FONT_DESC_VF_SIZE(26)
    //time picker popup UI layout   
    #define VAPP_CAL_TIME_PICKER_POPUP_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_LR_GAP   VAPP_CAL_DATE_PICKER_POPUP_LR_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_TD_GAP   VAPP_CAL_DATE_PICKER_POPUP_TD_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_HEIGHT    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_HEIGHT
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_HEIGHT    VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_X    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_X
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_Y    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_Y
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_TOP_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_MID_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_BOTTOM_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_FONT   VAPP_CAL_DATE_PICKER_POPUP_TITLE_FONT
    
#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )

    #define VAPP_CAL_DATE_PICKER_POPUP_LR_GAP 7
    #define VAPP_CAL_DATE_PICKER_POPUP_WIDTH (VCP_DATE_PICKER_WIDTH + 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP)
    #define VAPP_CAL_DATE_PICKER_POPUP_TD_GAP 6
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_HEIGHT 30
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT 20
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_WIDTH  (VAPP_CAL_DATE_PICKER_POPUP_WIDTH - 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP)
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_X 10
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_Y 3
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP 14
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP 5
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_GAP 6
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_SHADOW 7
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH ((VAPP_CAL_DATE_PICKER_POPUP_WIDTH - VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP - 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP) / 2)
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_FONT   VFX_FONT_DESC_VF_SIZE(13)
    //time picker popup UI layout   
    #define VAPP_CAL_TIME_PICKER_POPUP_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_LR_GAP   VAPP_CAL_DATE_PICKER_POPUP_LR_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_TD_GAP   VAPP_CAL_DATE_PICKER_POPUP_TD_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_HEIGHT    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_HEIGHT
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_HEIGHT    VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_X    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_X
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_Y    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_Y
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_TOP_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_MID_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_BOTTOM_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_FONT   VAPP_CAL_DATE_PICKER_POPUP_TITLE_FONT

#else //temp value

    #define VAPP_CAL_DATE_PICKER_POPUP_LR_GAP 15
    #define VAPP_CAL_DATE_PICKER_POPUP_WIDTH (VCP_DATE_PICKER_WIDTH + 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP)
    #define VAPP_CAL_DATE_PICKER_POPUP_TD_GAP 12
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_HEIGHT 60
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT 40
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_WIDTH  (VAPP_CAL_DATE_PICKER_POPUP_WIDTH - 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP)
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_X 20
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_Y 6
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP 28
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP 10
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_GAP 13
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_SHADOW 14
    #define VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH ((VAPP_CAL_DATE_PICKER_POPUP_WIDTH - VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP - 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP) / 2)
    #define VAPP_CAL_DATE_PICKER_POPUP_TITLE_FONT   VFX_FONT_DESC_VF_SIZE(26)
    //time picker popup UI layout   
    #define VAPP_CAL_TIME_PICKER_POPUP_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_LR_GAP   VAPP_CAL_DATE_PICKER_POPUP_LR_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_TD_GAP   VAPP_CAL_DATE_PICKER_POPUP_TD_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_HEIGHT    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_HEIGHT
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_HEIGHT    VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_WIDTH    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_WIDTH
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_X    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_X
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_TEXT_Y    VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_Y
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_TOP_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_MID_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_BUTTON_BOTTOM_GAP VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_GAP
    #define VAPP_CAL_TIME_PICKER_POPUP_TITLE_FONT   VAPP_CAL_DATE_PICKER_POPUP_TITLE_FONT
    
#endif


//customized date time form item UI layout
#if defined(__MMI_MAINLCD_320X480__)
    #define VAPP_CAL_DATETIME_FORM_ITEM_HEIGHT 84
    #define VAPP_CAL_DATETIME_FORM_ITEM_LR_GAP 8
    #define VAPP_CAL_DATETIME_FORM_ITEM_CAPTION_TOP_GAP 7
    #define VAPP_CAL_DATETIME_FORM_ITEM_CAPTION_HEIGHT 24
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_TOP_GAP 2
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_GAP 4
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_DATE_WIDTH 176
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_TIME_WIDTH 124
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_HEIGHT 47
#elif defined (__MMI_MAINLCD_480X800__)
    #define VAPP_CAL_DATETIME_FORM_ITEM_HEIGHT 100
    #define VAPP_CAL_DATETIME_FORM_ITEM_LR_GAP 18
    #define VAPP_CAL_DATETIME_FORM_ITEM_CAPTION_TOP_GAP 3
    #define VAPP_CAL_DATETIME_FORM_ITEM_CAPTION_HEIGHT 24
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_TOP_GAP 4
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_GAP 7
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_DATE_WIDTH 250
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_TIME_WIDTH 184
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_HEIGHT 65
#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )
    #define VAPP_CAL_DATETIME_FORM_ITEM_HEIGHT 70
    #define VAPP_CAL_DATETIME_FORM_ITEM_LR_GAP 8
    #define VAPP_CAL_DATETIME_FORM_ITEM_CAPTION_TOP_GAP 3
    #define VAPP_CAL_DATETIME_FORM_ITEM_CAPTION_HEIGHT 24
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_TOP_GAP 2
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_GAP 3
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_DATE_WIDTH 137
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_TIME_WIDTH 85
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_HEIGHT 35      
#else //  temp value
    #define VAPP_CAL_DATETIME_FORM_ITEM_HEIGHT 100
    #define VAPP_CAL_DATETIME_FORM_ITEM_LR_GAP 18
    #define VAPP_CAL_DATETIME_FORM_ITEM_CAPTION_TOP_GAP 3
    #define VAPP_CAL_DATETIME_FORM_ITEM_CAPTION_HEIGHT 24
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_TOP_GAP 4
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_GAP 7
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_DATE_WIDTH 250
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_TIME_WIDTH 184
    #define VAPP_CAL_DATETIME_FORM_ITEM_BTN_HEIGHT 65
#endif

/********************************************************************************/
/**************************IMPLEMENTATION****************************************/
/********************************************************************************/

//IVcpListMenuContentProvider

VfxBool VappCalCategoryListPage::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        text = getCategoryString(index);
    }

    return VFX_TRUE;
}


VfxBool VappCalCategoryListPage::getItemImage(
    VfxU32 index,                   
    VcpListMenuFieldEnum fieldType,  
    VfxImageSrc &image              
    ) 
{
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        image = getCategoryIcon(index);
    }

    return VFX_TRUE;
}


VfxImageSrc VappCalCategoryListPage::getCategoryIcon(VfxU8 index)
{
    VfxImageSrc image;

    image.setNull();
    image.setResId(IMG_ID_VAPP_CAL_PERSONAL + index);

    return image;
}


VfxU32 VappCalCategoryListPage::getCount() const
{
    return VAPP_CAL_CATEGORY_TOTAL;   
}


VcpListMenuItemStateEnum VappCalCategoryListPage::getItemState(
    VfxU32 index   // [IN] index of the item
    ) const
{
    if (index == m_selected)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }


    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


void VappCalCategoryListPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_CAL_CATEGORY);
    setTopBar(bar);

    VcpListMenu *listMenu;
    VFX_OBJ_CREATE(listMenu, VcpListMenu, this);
    listMenu->setSize(getSize());
    listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    listMenu->setContentProvider(this);
    listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);

    listMenu->m_signalItemTapped.connect(this, &VappCalCategoryListPage::onSelectionChanged);

}


void VappCalCategoryListPage::onSelectionChanged(VcpListMenu *menu, VfxU32 index)
{        
    m_signalSelectNewItem.emit(this, index);
    getMainScr()->popPage();
}


VfxWString VappCalCategoryListPage::getCategoryString(VfxU8 index)
{

    return VFX_WSTR_RES(STR_ID_VAPP_CAL_PERSONAL + index);//ordered  Strings
}


VfxBool VappCalRepeatListPage::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

        text = getRepeatString(index);
    }

    return VFX_TRUE;
}



VfxU32 VappCalRepeatListPage::getCount() const
{
    return VAPP_CAL_REPEAT_TOTAL;   
}


VcpListMenuItemStateEnum VappCalRepeatListPage::getItemState(
    VfxU32 index   // [IN] index of the item
    ) const
{
    if (index == m_selected)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;

}


void VappCalRepeatListPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_CAL_REPEATITION);
    setTopBar(bar);

    VcpListMenu *listMenu;
    VFX_OBJ_CREATE(listMenu, VcpListMenu, this);
    listMenu->setSize(getSize());
    listMenu->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);
    listMenu->setContentProvider(this);
    listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);

    listMenu->m_signalItemTapped.connect(this, &VappCalRepeatListPage::onSelectionChanged);

}


void VappCalRepeatListPage::onSelectionChanged(VcpListMenu *menu, VfxU32 index)
{      
    m_signalSelectNewItem.emit(this, index);
    getMainScr()->popPage();
}


VfxWString VappCalRepeatListPage::getRepeatString(VfxU8 index)
{
    return VFX_WSTR_RES(STR_ID_VAPP_CAL_NEVER + index);   //ordered Strings
}





VfxBool VappCalReminderListPage::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    if (m_special)
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

            text = getSpecialReminderString(index);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            if (index != VAPP_CAL_REMINDER_NEVER)
            {      
                text = getReminderAdditionalString();
            }
        }
    }
    else
    {

        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

            text = getReminderString(index);
        }
    }

    return VFX_TRUE;
}



VfxU32 VappCalReminderListPage::getCount() const
{
    if (m_special)
    {
        return VAPP_CAL_REMINDER_SPECIAL_TOTAL;   
    }
    else
    {
        return VAPP_CAL_REMINDER_TOTAL;
    }
}


VcpListMenuItemStateEnum VappCalReminderListPage::getItemState(
    VfxU32 index   // [IN] index of the item
    ) const
{
    if (index == m_selected)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;

}


void VappCalReminderListPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_CAL_REMINDER);
    setTopBar(bar);


    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setContentProvider(this);
    if (m_special)
    {
        m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT_EX);
    }
    else
    {
        m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    }
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);


    m_listMenu->m_signalItemTapped.connect(this, &VappCalReminderListPage::onSelectionChanged);

}


void VappCalReminderListPage::onSelectionChanged(VcpListMenu *menu, VfxU32 index)
{      
    srv_tdl_event_struct *event;

    VfxU32 alarmType;


    alarmType = index;

    // check if need popup confict
    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        event = (srv_tdl_event_struct *)m_data;
        VAPP_CAL_CATEGORY_ENUM categoryUI = VappCalEditPage::convertCategoryStoM((srv_vcal_category_type_enum)(event->category));

        if (categoryUI == VAPP_CAL_CATEGORY_SPECIALDAY ||
            categoryUI == VAPP_CAL_CATEGORY_BIRTHDAY)
        {
        //adjust reminder type to the real value 
        //according to the VAPP_CAL_REMINDER_ENUM
            alarmType = VappCalReminderListPage::convertToDataIndex(index);
        }
    }


    if (!VappCalEditPage::checkreminderValidation(m_data, m_vcalType, (VAPP_CAL_REMINDER_ENUM)alarmType))
    {
        VcpConfirmPopup *popup;

        VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
        popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        popup->setText((VfxResId)STR_ID_VAPP_CAL_ALARM_EXPIRED_SHORT);
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setAutoDestory(VFX_TRUE);
        popup->show(VFX_TRUE);
        m_listMenu->updateAllItems();
        return;
    }

    m_signalSelectNewItem.emit(this, index);
    getMainScr()->popPage();
}


VfxWString VappCalReminderListPage::getReminderString(VfxU8 index)
{
    VfxWString text = VFX_WSTR_EMPTY;

    switch (index)
    {
    case VAPP_CAL_REMINDER_NEVER:
        text.loadFromRes((VfxResId)STR_ID_VAPP_CAL_NEVER);
        break;
    default:      
        text.loadFromRes((VfxResId)(STR_ID_VAPP_CAL_5MIN_EARLIER + index - 1));
        break;
    }

    return text;
}


VfxWString VappCalReminderListPage::getSpecialReminderString(VfxU8 index)
{
    // index shoulde be the real UI index.
    // VAPP_CAL_REMINDER_NEVER
    // VAPP_CAL_REMINDER_1DAY_EARLIER
    // VAPP_CAL_REMINDER_3DAYS_EARLIER
    // VAPP_CAL_REMINDER_1WEEK_EARLIER
    // the obove 4 value are used in the reminder list of birthday and special day.


    return getReminderString(convertToDataIndex(index));

}

VfxWString VappCalReminderListPage::getReminderAdditionalString()
{
    VfxDateTime dateTime;
    dateTime.setTime(9, 0, 0);

    VfxWString str;
    str = VFX_WSTR_RES(STR_ID_VAPP_CAL_LEFT_PARENTHESES);
    str += dateTime.getDateTimeString(VFX_DATE_TIME_TIME_HOUR|VFX_DATE_TIME_TIME_MINUTE);
    str += VFX_WSTR_RES(STR_ID_VAPP_CAL_RIGHT_PARENTHESES);
    return str;
}


VfxU32 VappCalReminderListPage::convertToUIIndex(VfxU32 dataIndex)
{
    VfxU32 ret;

    ret  = dataIndex;

    if (dataIndex != VAPP_CAL_REMINDER_NEVER)
    {
        ret -= VAPP_CAL_REMINDER_1HOUR_EARLIER;
    }

    return ret;
}


VfxU32 VappCalReminderListPage::convertToDataIndex(VfxU32 UIIndex)
{
    VfxU32 ret;

    ret  = UIIndex;

    if (UIIndex != VAPP_CAL_REMINDER_NEVER)
    {
        ret += VAPP_CAL_REMINDER_1HOUR_EARLIER;
    }

    return ret;
}


#ifdef __MMI_TASK_APP__
VfxBool VappCalPriorityListPage::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        text = getPriorityString(index);
    }

    return VFX_TRUE;
}


VfxBool VappCalPriorityListPage::getItemImage(
    VfxU32 index,                   
    VcpListMenuFieldEnum fieldType,  
    VfxImageSrc &image              
    ) 
{
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        switch (index)
        {
        case 0:
            image.setResId(IMG_ID_VAPP_CAL_HIGH);
            break;
        case 1:
            image.setResId(IMG_ID_VAPP_CAL_MEDIUM);
            break;
        case 2:
            image.setResId(IMG_ID_VAPP_CAL_LOW);
            break;
        default:
            break;
        }
    }

    return VFX_TRUE;
}


VfxU32 VappCalPriorityListPage::getCount() const
{
    return VAPP_CAL_PRIORITY_TOTAL;   
}


VcpListMenuItemStateEnum VappCalPriorityListPage::getItemState(
    VfxU32 index   // [IN] index of the item
    ) const
{
    if (index == m_selected)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;

}


void VappCalPriorityListPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_CAL_PRIORITY);
    setTopBar(bar);

    VcpListMenu *listMenu;
    VFX_OBJ_CREATE(listMenu, VcpListMenu, this);
    listMenu->setSize(getSize());
    listMenu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    listMenu->setContentProvider(this);
    listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);

    listMenu->m_signalItemTapped.connect(this, &VappCalPriorityListPage::onSelectionChanged);

}


void VappCalPriorityListPage::onSelectionChanged(VcpListMenu *menu, VfxU32 index)
{        
    m_signalSelectNewItem.emit(this, index);
    getMainScr()->popPage();
}


VfxWString VappCalPriorityListPage::getPriorityString(VfxU8 index)
{
    VfxWString text;  
    text.loadFromRes(STR_ID_VAPP_CAL_HIGH + index);

    return text;
}
#endif /*__MMI_TASK_APP__*/

/***************************************************************************** 
 * Class VappCalEditPage Implementation
 ******************************************************************************/
VFX_IMPLEMENT_CLASS("VappCalEditPage", VappCalEditPage, VfxPage);

const VAPP_CAL_REPEAT_ENUM VappCalEditPage::s_srv2AppRepeat[SRV_TDL_RULE_TOTAL] =
{
    VAPP_CAL_REPEAT_NEVER,
    VAPP_CAL_REPEAT_DAILY,
    VAPP_CAL_REPEAT_WEEKDAY,
    VAPP_CAL_REPEAT_WEEKLY,
    VAPP_CAL_REPEAT_MONTHLY,
    VAPP_CAL_REPEAT_YEARLY
};

const srv_tdl_repeat_rule_enum VappCalEditPage::s_app2SrvRepeat[VAPP_CAL_REPEAT_TOTAL] =
{
    SRV_TDL_RULE_ONCE,
    SRV_TDL_RULE_DAILY,
    SRV_TDL_RULE_DAYS,
    SRV_TDL_RULE_WEEKLY,
    SRV_TDL_RULE_MONTHLY,
    SRV_TDL_RULE_YEARLY
};


const srv_vcal_category_type_enum VappCalEditPage::s_app2SrvCategory[VAPP_CAL_CATEGORY_TOTAL] = 
{
    SRV_VCAL_CATEGORY_TYPE_REMINDER,
    SRV_VCAL_CATEGORY_TYPE_MEETING,
    SRV_VCAL_CATEGORY_TYPE_ANNIVERSARY,
    SRV_VCAL_CATEGORY_TYPE_BIRTHDAY,
    SRV_VCAL_CATEGORY_TYPE_DATE
};

#ifdef __MMI_TASK_APP__
const VAPP_CAL_PRIORITY_ENUM VappCalEditPage::s_srv2AppPriority[SRV_VCAL_PRIORITY_TOTAL] =
{
    VAPP_CAL_PRIORITY_LOW,
    VAPP_CAL_PRIORITY_MEDIUM,
    VAPP_CAL_PRIORITY_HIGH
};

const srv_vcal_priority_enum VappCalEditPage::s_app2SrvPriority[VAPP_CAL_PRIORITY_TOTAL] =
{
    SRV_VCAL_PRIORITY_HIGH,
    SRV_VCAL_PRIORITY_MEDIUM,
    SRV_VCAL_PRIORITY_LOW
};
#endif   /*__MMI_TASK_APP__*/

#ifndef __MMI_VCALENDAR__
#pragma arm section code, rodata
#endif
const VAPP_CAL_CATEGORY_ENUM VappCalEditPage::s_srv2AppCategory[SRV_VCAL_CATEGORY_TYPE_TOTAL] = 
{
    VAPP_CAL_CATEGORY_PERSONAL, // Reminder
    VAPP_CAL_CATEGORY_MEETING,	// Meeting
    VAPP_CAL_CATEGORY_PERSONAL, // Course
    VAPP_CAL_CATEGORY_OTHER, 	// Date
    VAPP_CAL_CATEGORY_PERSONAL, // Call
    VAPP_CAL_CATEGORY_SPECIALDAY,// Aniversary
    VAPP_CAL_CATEGORY_BIRTHDAY	// Bday
};

void VappCalEditPage::setReminderFirstLaunchTime(const MYTIME *baseTime, 
                                                    MYTIME *remimderTime, 
                                                    VAPP_CAL_REMINDER_ENUM reminderType, 
                                                    VfxBool allDay,
                                                    VAPP_CAL_CATEGORY_ENUM category)
{
    //time is the base time(start time or due time) to compute according to reminder type.

    MYTIME decrement;
    MYTIME baseTimeTemp, *base;

    if (reminderType == VAPP_CAL_REMINDER_NEVER)
    {
        return;
    }

    base = (MYTIME*)baseTime;

    if (allDay)
    {
        memcpy(&baseTimeTemp, baseTime, sizeof(MYTIME));
        baseTimeTemp.nHour = 0;
        baseTimeTemp.nMin = 0;
        baseTimeTemp.nSec = 0;
        base = &baseTimeTemp;

        // birthday and special day are 9:00 to remind defaultly.
        if (category == VAPP_CAL_CATEGORY_BIRTHDAY ||
            category == VAPP_CAL_CATEGORY_SPECIALDAY)
        {
            baseTimeTemp.nHour = 9; 
        }

    }


    memset(&decrement, 0, sizeof(MYTIME));
    switch(reminderType)
    {
    case VAPP_CAL_REMINDER_5MINS_EARLIER:
        decrement.nMin= 5;
        break;

    case VAPP_CAL_REMINDER_15MINS_EARLIER:
        decrement.nMin = 15;
        break;

    case VAPP_CAL_REMINDER_30MINS_EARLIER:
        decrement.nMin = 30;
        break;

    case VAPP_CAL_REMINDER_1HOUR_EARLIER:
        decrement.nHour = 1;
        break;

    case VAPP_CAL_REMINDER_1DAY_EARLIER:
        decrement.nDay = 1;
        break;

    case VAPP_CAL_REMINDER_3DAYS_EARLIER:
        decrement.nDay = 3;
        break;

    case VAPP_CAL_REMINDER_1WEEK_EARLIER:
        decrement.nDay = 7;
        break;

    default:
        break;
    }

    applib_dt_decrease_time(
            (applib_time_struct*)base,
            (applib_time_struct*)&decrement,
            (applib_time_struct*)remimderTime);

}

VfxBool VappCalEditPage::reminderTimeIsInvalid(const MYTIME *reminderTime)
{
    applib_time_struct currTime;

    applib_dt_get_date_time(&currTime);

    if (applib_dt_compare_time(&currTime, (applib_time_struct*)reminderTime, NULL)
        >= DT_TIME_EQUAL)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappCalEditPage::checkreminderValidation(const void *data, 
                        srv_tdl_vcal_enum vcalType, 
                        VAPP_CAL_REMINDER_ENUM reminderType)
{

    VfxBool ret = VFX_TRUE;

    if (vcalType == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_struct *event;
        event = (srv_tdl_event_struct*)data;
        MYTIME reminderTime;

        if (reminderType != VAPP_CAL_REMINDER_NEVER)
        {
            setReminderFirstLaunchTime(&(event->start_time), 
                                &reminderTime,
                                reminderType,
                                (VfxBool)(event->all_day),
                                convertCategoryStoM((srv_vcal_category_type_enum)(event->category)));

            if (event->repeat.rule == SRV_TDL_RULE_ONCE &&
                reminderTimeIsInvalid(&reminderTime))
            {
                ret = VFX_FALSE;
            }
        }
    }
#ifdef __MMI_TASK_APP__
    else
    {
        srv_tdl_task_struct *task;
        task = (srv_tdl_task_struct*)data;
        MYTIME reminderTime;

        if (reminderType != VAPP_CAL_REMINDER_NEVER)
        {
            setReminderFirstLaunchTime(&(task->due_time), 
                                &reminderTime, 
                                reminderType);
        //no repeat field for cosmos task.
            if (reminderTimeIsInvalid(&reminderTime))
            {
                ret = VFX_FALSE;
            }
        }
    }
#endif

    MMI_TRACE(CALENDAR_TRC_GROUP, VAPP_CAL_CHECK_REMINDER_RESULT, vcalType, ret);

    return ret;
}

VAPP_CAL_CATEGORY_ENUM VappCalEditPage::convertCategoryStoM(const srv_vcal_category_type_enum &category)
{
    if (category < SRV_VCAL_CATEGORY_TYPE_TOTAL)
    {
        return s_srv2AppCategory[category];
    }

    return VAPP_CAL_CATEGORY_PERSONAL;
}

#ifndef __MMI_VCALENDAR__
#pragma arm section code = "DYNAMIC_CODE_CLNDR_ROCODE", rodata = "DYNAMIC_CODE_CLNDR_RODATA"
#endif
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
VfxWString VappCalEditPage::getBirthdayAppendString()
{
    return VFX_WSTR_RES(STR_ID_VAPP_CAL_BIR_POSTFIX);
}
#endif




VAPP_CAL_DATE_VALID_ENUM VappCalEditPage::checkStartDateValidation(applib_time_struct *time)
{

    if (time->nYear < (VfxU16)VAPP_CAL_MIN_YEAR)
    {
        return VAPP_CAL_DATE_LESS_THAN_MIN_YEAR;
    }
    else if (time->nYear > VAPP_CAL_MAX_YEAR)
    {
        return VAPP_CAL_DATE_GREATER_THAN_MAX_YEAR;
    }

    return VAPP_CAL_DATE_NORMAL;
}


void VappCalEditPage::initData()
{
    VfxU32 size = 
    (m_vcalType == SRV_TDL_VCAL_EVENT ? sizeof(srv_tdl_event_struct) : sizeof(srv_tdl_task_struct));

    VFX_ALLOC_MEM(m_data, size, this);
    VFX_ASSERT(m_data);


    //get data from service by m_index
    //if ADD, init the initial data with default value.

    if (m_operation == VAPP_CAL_OPERATION_TYPE_ADD)
    {
        VfxDateTime dt;

        memset(m_data, 0, size);

        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            srv_tdl_event_struct *event;
            #ifdef __MMI_PHB_BIRTHDAY_FIELD__
            if (m_phbAddBirthday)
            {
                event = (srv_tdl_event_struct*)m_data;
                event->all_day = VFX_TRUE;
                event->alarm.type = VAPP_CAL_REMINDER_1DAY_EARLIER;
                event->category = convertCategoryMtoS(VAPP_CAL_CATEGORY_BIRTHDAY);
                event->vcal = SRV_TDL_VCAL_EVENT;
                event->repeat.rule = SRV_TDL_RULE_YEARLY;
                event->present = 1;

                VAPP_CAL_DATE_VALID_ENUM ret;
                ret = checkStartDateValidation(&m_initDateForAdd);
                if (ret == VAPP_CAL_DATE_LESS_THAN_MIN_YEAR)
                {
                    // adjust to min year
                    m_initDateForAdd.nYear = (VfxU16)VAPP_CAL_MIN_YEAR;
                    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                    balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_CAL_YEAE_BEYOND_MIN));
                }
                else if (ret == VAPP_CAL_DATE_GREATER_THAN_MAX_YEAR)
                {
                    // adjust to max year
                    m_initDateForAdd.nYear = (VfxU16)VAPP_CAL_MAX_YEAR;
                    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                    balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_CAL_YEAE_BEYOND_MAX));
                }
                setInitDateTime();
                VfxU32 tempLen = vfx_sys_wcslen(getBirthdayAppendString());
                vfx_sys_wcsncpy((VfxWChar*)(event->subject), m_phbBirthName, VAPP_CAL_MAX_SUBJECT_LEN - tempLen);
                mmi_ucs2cat((VfxChar*)(event->subject), (VfxChar*)(getBirthdayAppendString().getBuf()));
            }
            else
            #endif  /*__MMI_PHB_BIRTHDAY_FIELD__*/  
            {
                event = (srv_tdl_event_struct*)m_data;
                event->all_day = VFX_FALSE;
                event->alarm.type = VAPP_CAL_REMINDER_15MINS_EARLIER;
                event->category = convertCategoryMtoS(VAPP_CAL_CATEGORY_PERSONAL);
                event->vcal = SRV_TDL_VCAL_EVENT;
                event->repeat.rule = SRV_TDL_RULE_ONCE;
                event->present = 1;
                setInitDateTime();
                //vfx_sys_wcscpy((VfxWChar*)(event->subject), getDefaultSubjectString().getBuf());
            }
        }
        #ifdef __MMI_TASK_APP__
        else //SRV_TDL_VCAL_TASK
        {
            srv_tdl_task_struct *task;
            task = (srv_tdl_task_struct*)m_data;
            setInitDateTime();
            task->priority = SRV_VCAL_PRIORITY_MEDIUM;
            task->alarm.type = VAPP_CAL_REMINDER_15MINS_EARLIER;
            task->repeat.rule = SRV_TDL_RULE_ONCE;
            task->vcal = SRV_TDL_VCAL_TASK;
            task->present = 1;
            //vfx_sys_wcscpy((VfxWChar*)(task->subject), getDefaultSubjectString().getBuf());
        }
        #endif
        
    }
    else //(m_operation == VAPP_CAL_OPERATION_TYPE_EDIT)
    {
#ifdef __MMI_TASK_APP__
        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {    
            VFX_ASSERT(srv_tdl_event_get((srv_tdl_event_struct *)m_data, size, m_eventbuffer.source_id,m_eventbuffer.event_id) == SRV_TDL_RESULT_OK);
        }

        else if (m_vcalType == SRV_TDL_VCAL_TASK)
        {
            VFX_ASSERT(srv_tdl_get(m_data, size, m_vcalType, m_index) == SRV_TDL_RESULT_OK);
        }
#else
        VFX_ASSERT(srv_tdl_event_get((srv_tdl_event_struct *)m_data, size, m_eventbuffer.source_id,m_eventbuffer.event_id) == SRV_TDL_RESULT_OK);

#endif
    }

}

void VappCalEditPage::setInitDateTime()
{
    // init date of Start and To are the current date.
    // init time : if the current is 21:25
    //             Start time is 22:00
    //             To time is 23:00 (start time + 1 hour)
    // init time special case 1: 
    //             if the current is 22:25
    //             Start time is 23:00
    //             To time is 00:00 of next day.
    // init time special case 2: 
    //             if the current is 23:25
    //             Start time is 00:00 of next day.
    //             To time is 01:00 of next day.

    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_struct *event;

        event = (srv_tdl_event_struct*)m_data;
        applib_dt_get_date_time((applib_time_struct*)(&(event->start_time)));

        //use init date to initialize event date field only, excluding time field.
        event->start_time.nYear = m_initDateForAdd.nYear;
        event->start_time.nMonth= m_initDateForAdd.nMonth;
        event->start_time.nDay = m_initDateForAdd.nDay;
        event->start_time.nMin = 0;
        event->start_time.nSec = 0;

        applib_time_struct incTime;
        memset(&incTime, 0, sizeof(applib_time_struct));
        incTime.nHour = 1;
        applib_dt_increase_time((applib_time_struct*)&event->start_time, &incTime, (applib_time_struct*)&event->start_time);

        applib_dt_increase_time((applib_time_struct*)&event->start_time, &incTime, (applib_time_struct*)&event->end_time);

        if (VappCalUtility::dateTimeIsOutOfBounder(event->start_time.nYear, convertCategoryStoM((srv_vcal_category_type_enum)event->category))
            || VappCalUtility::dateTimeIsOutOfBounder(event->end_time.nYear, convertCategoryStoM((srv_vcal_category_type_enum)event->category)))
        {
            applib_dt_get_date_time((applib_time_struct*)(&(event->start_time)));
            event->start_time.nYear = m_initDateForAdd.nYear;
            event->start_time.nMonth= m_initDateForAdd.nMonth;
            event->start_time.nDay = m_initDateForAdd.nDay;
            event->start_time.nMin = 0;
            event->start_time.nSec = 0;

            event->end_time = event->start_time;
        }
    }
    
#ifdef __MMI_TASK_APP__
    else
    {
        srv_tdl_task_struct *task;
        task = (srv_tdl_task_struct*)m_data;
        applib_dt_get_date_time((applib_time_struct*)(&(task->due_time )));

        //use init date to initialize event date field only, excluding time field.
        task->due_time.nYear = m_initDateForAdd.nYear;
        task->due_time.nMonth= m_initDateForAdd.nMonth;
        task->due_time.nDay = m_initDateForAdd.nDay;

        task->due_time.nMin = 0;
        task->due_time.nSec = 0;
        applib_time_struct incTime;
        memset(&incTime, 0, sizeof(applib_time_struct));
        incTime.nHour = 1;
        applib_dt_increase_time((applib_time_struct*)&task->due_time, &incTime, (applib_time_struct*)&task->due_time);

        if (VappCalUtility::dateTimeIsOutOfBounder(task->due_time.nYear, VAPP_CAL_CATEGORY_PERSONAL))
        {
            applib_dt_get_date_time((applib_time_struct*)(&(task->due_time )));
            task->due_time.nYear = m_initDateForAdd.nYear;
            task->due_time.nMonth= m_initDateForAdd.nMonth;
            task->due_time.nDay = m_initDateForAdd.nDay;

            task->due_time.nMin = 0;
            task->due_time.nSec = 0;
        }
    }
#endif  /*__MMI_TASK_APP__*/
}


void VappCalEditPage::adjustData()
{
    //adjust Start/To time and data
    srv_tdl_event_struct *event;

    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        event = (srv_tdl_event_struct*)m_data;

        event->alarm.snooze = 0;
        event->alarm.snooze_interval = 4;

        if (event->all_day)
        {
        //set time to 00:00 ~ 23:59
        event->start_time.nHour = 0;
        event->start_time.nMin = 0;
        event->end_time.nHour = 23;
        event->end_time.nMin = 59;
        }

   

        if (event->alarm.type == VAPP_CAL_REMINDER_NEVER)
        {
            memset(&(event->alarm.first_launch), 0, sizeof(MYTIME));
        }


        if (event->repeat.rule == SRV_TDL_RULE_DAYS)
        {
            event->repeat.dows = setWeekDays();
        }

        if (vfx_sys_wcslen((const VfxWChar*)(event->subject)) == 0)
        {
            vfx_sys_wcscpy((VfxWChar*)(event->subject), getDefaultSubjectString().getBuf());
        }
    }
    
#ifdef __MMI_TASK_APP__
    else
    {
    
        srv_tdl_task_struct *task;
        task = (srv_tdl_task_struct*)m_data;

        task->alarm.snooze = 0;
        task->alarm.snooze_interval = 4;


        if (task->alarm.type == VAPP_CAL_REMINDER_NEVER)
        {
            memset(&(task->alarm.first_launch), 0, sizeof(MYTIME));
        }

        if (vfx_sys_wcslen((const VfxWChar*)(task->subject)) == 0)
        {
            vfx_sys_wcscpy((VfxWChar*)(task->subject), getDefaultSubjectString().getBuf());
        }

    }
    #endif  /*__MMI_TASK_APP__*/

}


VfxU8 VappCalEditPage::setWeekDays()
{
    // set weekdays from Monday to Friday

    VfxU8 index, ret = 0;

    for (index = 1; index <= 5; index++)
    {
        ret |= GetWeekDayMASK(index);
    }

    return ret;
}




VfxBool VappCalEditPage::saveData()
{
    VfxBool result = VFX_FALSE;
    
    VfxWString str;
    VAPP_CAL_REMINDER_ENUM reminderType = VAPP_CAL_REMINDER_TOTAL;
    srv_tdl_event_struct *event = NULL;
    
#ifdef __MMI_TASK_APP__
    srv_tdl_task_struct *task = NULL;
#endif

    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        event = (srv_tdl_event_struct *)m_data;
        reminderType = (VAPP_CAL_REMINDER_ENUM)(((srv_tdl_event_struct*)m_data)->alarm.type);
        event->src_id = m_eventbuffer.source_id;
    }
    
#ifdef __MMI_TASK_APP__
    else
    {
        task = (srv_tdl_task_struct *)m_data;
        reminderType = (VAPP_CAL_REMINDER_ENUM)(((srv_tdl_task_struct*)m_data)->alarm.type);
    }
    #endif

    if (!checkreminderValidation(m_data, m_vcalType, reminderType))
    {
        vapp_nmgr_global_popup_show_confirm_one_button_id(
                                            MMI_SCENARIO_ID_DEFAULT,
                                            VCP_POPUP_TYPE_WARNING, 
                                            STR_ID_VAPP_CAL_ALARM_EXPIRED, 
                                            STR_GLOBAL_OK, 
                                            VCP_POPUP_BUTTON_TYPE_NORMAL, 
                                            NULL, 
                                            NULL);


        return VFX_FALSE;
    } 
    else
    {
        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            setReminderFirstLaunchTime(&(event->start_time), 
            &(event->alarm.first_launch),
            (VAPP_CAL_REMINDER_ENUM)event->alarm.type,
            (VfxBool)(event->all_day),
            convertCategoryStoM((srv_vcal_category_type_enum)(event->category)));
        }
#ifdef __MMI_TASK_APP__
        else
        {
            setReminderFirstLaunchTime(&(task->due_time), 
            &(task->alarm.first_launch), 
            (VAPP_CAL_REMINDER_ENUM)task->alarm.type);
        }
        #endif
        adjustData();
    }

  
    if (m_operation == VAPP_CAL_OPERATION_TYPE_ADD)
    {
    
#ifdef __MMI_TASK_APP__
        if(m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            if(srv_tdl_event_add((srv_tdl_event_struct *)m_data,SRV_TDL_EVENT_SOURCE_LOCAL,&(m_eventbuffer.event_id)) == SRV_TDL_RESULT_OK)
            {
                result = VFX_TRUE;
            }
        }
        else
        {
        
            VfxU16 index;
            if(srv_tdl_add(m_data, m_vcalType, &index) == SRV_TDL_RESULT_OK)
                result = VFX_TRUE;
        }
#else
        if(srv_tdl_event_add((srv_tdl_event_struct *)m_data,SRV_TDL_EVENT_SOURCE_LOCAL,&(m_eventbuffer.event_id)) == SRV_TDL_RESULT_OK)
        {
            result = VFX_TRUE;
        }    
#endif

    }
    else
    {
        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            if (srv_tdl_event_update((srv_tdl_event_struct *)m_data,m_eventbuffer.source_id,m_eventbuffer.event_id)== SRV_TDL_RESULT_OK)
            {
                result = VFX_TRUE;
            }
        }
#ifdef __MMI_TASK_APP__
        else
        {
            if (srv_tdl_update(m_data, m_vcalType, m_index) == SRV_TDL_RESULT_OK)
                result = VFX_TRUE;
        }
#endif

    }
#ifndef __LOW_COST_SUPPORT_COMMON__
    if ((result)&&(m_operation == VAPP_CAL_OPERATION_TYPE_ADD))
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_SUCCESS, VFX_WSTR_RES(STR_ID_VAPP_CAL_EVT_SAVED));
    }
#endif

    //m_signalDataUpdated.emit(this);
    return result;
}



VfxWString VappCalEditPage::getDefaultSubjectString()
{
    return VFX_WSTR_RES(STR_ID_VAPP_CAL_NO_CONTENT);
}


void VappCalEditPage::onDeinit()
{
    if (m_data)
    {
        VFX_FREE_MEM(m_data);        
    }
    if ( VAPP_CAL_OPERATION_TYPE_EDIT == m_operation)
    {
        if(m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_OP,VappCalEditPage::onEventDataChangeCallBack, getObjHandle());	 
        }
        
        #if defined(__MMI_TASK_APP__)
        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_OP,VappCalEditPage::onDataChangeCallBack, getObjHandle());	
        #endif
    }

    VfxPage::onDeinit();
}


void VappCalEditPage::initEventFormContent()
{

    srv_tdl_event_struct *event = (srv_tdl_event_struct*)m_data;

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);

    //subject
    VcpFormItemTextInput *subject;
    VFX_OBJ_CREATE(subject, VcpFormItemTextInput, m_form);
    subject->setLabelText((VfxResId)STR_ID_VAPP_CAL_SUBJECT);
    ((VcpTextEditor*)(subject->getTextBox()))->setText((VfxWChar*)(event->subject), VAPP_CAL_MAX_SUBJECT_LEN, VFX_TRUE);

#ifdef __MMI_CAL_FUNCBAR__
    //set function bar
    VFX_OBJ_CREATE(m_subjectFBar, VcpFunctionBar, this);
    m_subjectFBar->addItem(VAPP_CAL_FBAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_CAL_PREV)); // TODO: replace string
    m_subjectFBar->addItem(VAPP_CAL_FBAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_CAL_NEXT)); // TODO: replace string
    m_subjectFBar->addItem(VAPP_CAL_FBAR_SAVE, VFX_WSTR_RES(STR_ID_VAPP_CAL_SAVE)); 
    m_subjectFBar->setItemSpecial(VAPP_CAL_FBAR_SAVE);
    m_subjectFBar->setDisableItem(VAPP_CAL_FBAR_PREV, VFX_TRUE);
    (subject->getTextBox())->setFunctionBar(m_subjectFBar);
    m_subjectFBar->m_signalButtonTap.connect(this, &VappCalEditPage::onSubjectFBarTap);
#endif

    //start date time  and To date time
    VappCalEditDateTimeItem *start, *to;
    VfxDateTime dt;

    applib_time_struct time;
    VAPP_CAL_CATEGORY_ENUM categoryUI = convertCategoryStoM((srv_vcal_category_type_enum)(event->category));

    if (categoryUI == VAPP_CAL_CATEGORY_SPECIALDAY ||
    categoryUI == VAPP_CAL_CATEGORY_BIRTHDAY)
    {
        VFX_OBJ_CREATE(start, VappCalEditDateTimeItem, m_form);
        start->setLabelText((VfxResId)STR_ID_VAPP_CAL_DATE);
        memcpy(&time, &(event->start_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);
        start->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        start->changeDateLarge(VFX_TRUE);
        start->m_btnTime->setHidden(VFX_TRUE);
        start->m_signalButtonClicked.connect(this, &VappCalEditPage::onStartDateTimeItemClick);
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
        if (m_phbAddBirthday)
        {
            start->m_btnDate->setIsDisabled(VFX_TRUE);
            start->setIsDisabled(VFX_TRUE);
        }
#endif

        VFX_OBJ_CREATE(to, VappCalEditDateTimeItem, m_form);
        to->setLabelText((VfxResId)STR_ID_VAPP_CAL_TO);
        memcpy(&time, &(event->end_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);
        to->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        //must set time for Time button even if it is possible not to be displayed
        //because if will be displayed when switching allDat cell.
        to->setTime(dt.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));		
        to->m_signalButtonClicked.connect(this, &VappCalEditPage::onEndDateTimeItemClick);
        to->setIsHidden(VFX_TRUE);
    }
    else
    {
        VFX_OBJ_CREATE(start, VappCalEditDateTimeItem, m_form);
        start->setLabelText((VfxResId)STR_ID_VAPP_CAL_START);
        memcpy(&time, &(event->start_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);
        start->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        //must set time for Time button even if it is possible not to be displayed
        //because if will be displayed when switching allDat cell. 
        start->setTime(dt.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));
        if (event->all_day)
        {
            start->changeDateLarge(VFX_TRUE);
            start->m_btnTime->setHidden(VFX_TRUE);
        }
        start->m_signalButtonClicked.connect(this, &VappCalEditPage::onStartDateTimeItemClick);


        VFX_OBJ_CREATE(to, VappCalEditDateTimeItem, m_form);
        to->setLabelText((VfxResId)STR_ID_VAPP_CAL_TO);
        memcpy(&time, &(event->end_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);
        to->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        //must set time for Time button even if it is possible not to be displayed
        //because if will be displayed when switching allDat cell.
        to->setTime(dt.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));
        if (event->all_day)
        {
            to->changeDateLarge(VFX_TRUE);
            to->m_btnTime->setHidden(VFX_TRUE);
        }
        to->m_signalButtonClicked.connect(this, &VappCalEditPage::onEndDateTimeItemClick);
    }


    // allDay
    VcpFormItemSwitchCell *allDay;
    VFX_OBJ_CREATE(allDay, VcpFormItemSwitchCell, m_form);
    allDay->setMainText((VfxResId)STR_ID_VAPP_CAL_ALL_DAY);
    allDay->setSwitchStatus((VfxBool)(event->all_day));
    allDay->setIsTappable(VFX_FALSE);
    allDay->m_signalSwitchChangeReq.connect(this, &VappCalEditPage::allDaySwitchChangeState);
    allDay->m_signalToggleAnimationDone.connect(this,&VappCalEditPage::allDaySwitchChangeReq);
    if (categoryUI == VAPP_CAL_CATEGORY_SPECIALDAY ||
    categoryUI == VAPP_CAL_CATEGORY_BIRTHDAY)
    {
        allDay->setIsDisabled(VFX_TRUE);
    }


    //Category
    //Edit page :can not edit category , so do not display this cell item
    VcpFormItemLauncherCell *category = NULL;
    if (m_operation == VAPP_CAL_OPERATION_TYPE_ADD)
    {
        VFX_OBJ_CREATE(category, VcpFormItemLauncherCell, m_form);
        category->setMainText((VfxResId)STR_ID_VAPP_CAL_CATEGORY);
        category->setHintText(VappCalCategoryListPage::getCategoryString(categoryUI));
        category->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        category->m_signalTap.connect(this, &VappCalEditPage::onItemClicked);     
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
        if (m_phbAddBirthday)
        {
            category->setIsDisabled(VFX_TRUE);
        }
#endif
    }


    //repeat
    VcpFormItemLauncherCell *repeat;
    VFX_OBJ_CREATE(repeat, VcpFormItemLauncherCell, m_form);
    repeat->setMainText((VfxResId)STR_ID_VAPP_CAL_REPEATITION);
    repeat->setHintText(VappCalRepeatListPage::getRepeatString
    (convertRepeatStoM((srv_tdl_repeat_rule_enum)(event->repeat.rule))));
    repeat->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    repeat->m_signalTap.connect(this, &VappCalEditPage::onItemClicked);

    // check repeat
    if (durationIsMoreThan1Day(&(event->start_time), &(event->end_time)))
    {
        repeat->setHintText(VappCalRepeatListPage::getRepeatString(VAPP_CAL_REPEAT_NEVER));
        repeat->setIsDisabled(VFX_TRUE);
        event->repeat.rule = SRV_TDL_RULE_ONCE;
    }
    else
    {
        repeat->setIsDisabled(VFX_FALSE);
    }

    if (categoryUI == VAPP_CAL_CATEGORY_BIRTHDAY ||	categoryUI == VAPP_CAL_CATEGORY_SPECIALDAY)
    {
        repeat->setIsDisabled(VFX_TRUE);
    }

    //reminder
    VcpFormItemLauncherCell *reminder;
    VFX_OBJ_CREATE(reminder, VcpFormItemLauncherCell, m_form);
    reminder->setMainText((VfxResId)STR_ID_VAPP_CAL_REMINDER);
    VfxWString str = VappCalReminderListPage::getReminderString(event->alarm.type);
    if (categoryUI == VAPP_CAL_CATEGORY_BIRTHDAY ||
        categoryUI == VAPP_CAL_CATEGORY_SPECIALDAY)
    {
        if (event->alarm.type != VAPP_CAL_REMINDER_NEVER)
        {
            str += VappCalReminderListPage::getReminderAdditionalString();
        }
    }
    reminder->setHintText(str);
    reminder->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    reminder->m_signalTap.connect(this, &VappCalEditPage::onItemClicked);


    //Location
    VcpFormItemTextInput *location;
    VFX_OBJ_CREATE(location, VcpFormItemTextInput, m_form);
    location->setLabelText((VfxResId)STR_ID_VAPP_CAL_LOC);
    //location->setText(VFX_WSTR_STATIC(event->location));
    ((VcpTextEditor*)(location->getTextBox()))->setText((VfxWChar*)(event->location), VAPP_CAL_MAX_LOCATION_LEN, VFX_TRUE);
    
#ifdef __MMI_CAL_FUNCBAR__
    //set function bar
    VFX_OBJ_CREATE(m_locationFBar, VcpFunctionBar, this);
    m_locationFBar->addItem(VAPP_CAL_FBAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_CAL_PREV)); // TODO: replace string
    m_locationFBar->addItem(VAPP_CAL_FBAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_CAL_NEXT)); // TODO: replace string
    m_locationFBar->addItem(VAPP_CAL_FBAR_SAVE, VFX_WSTR_RES(STR_ID_VAPP_CAL_SAVE)); 
    m_locationFBar->setItemSpecial(VAPP_CAL_FBAR_SAVE);
    (location->getTextBox())->setFunctionBar(m_locationFBar);
    m_locationFBar->m_signalButtonTap.connect(this, &VappCalEditPage::onLocationFBarTap);
#endif

    //Note
    VcpFormItemTextInput *note;
    VFX_OBJ_CREATE(note, VcpFormItemTextInput, m_form);
    note->setLabelText((VfxResId)STR_ID_VAPP_CAL_NOTE);
    ((VcpTextEditor*)(note->getTextBox()))->setText((VfxWChar*)(event->details), VAPP_CAL_MAX_NOTE_LEN, VFX_TRUE);
    
#ifdef __MMI_CAL_FUNCBAR__
    //set function bar
    VFX_OBJ_CREATE(m_noteFBar, VcpFunctionBar, this);
    m_noteFBar->addItem(VAPP_CAL_FBAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_CAL_PREV)); // TODO: replace string
    m_noteFBar->addItem(VAPP_CAL_FBAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_CAL_NEXT)); // TODO: replace string
    m_noteFBar->addItem(VAPP_CAL_FBAR_SAVE, VFX_WSTR_RES(STR_ID_VAPP_CAL_SAVE)); 
    m_noteFBar->setItemSpecial(VAPP_CAL_FBAR_SAVE);
    m_noteFBar->setDisableItem(VAPP_CAL_FBAR_NEXT, VFX_TRUE);
    (note->getTextBox())->setFunctionBar(m_noteFBar);
    m_noteFBar->m_signalButtonTap.connect(this, &VappCalEditPage::onNoteFBarTap);
#endif

    //add item and layout
    m_form->addItem(subject, VAPP_CAL_EDIT_SUBJECT);
    m_form->insertSeparator(VAPP_CAL_EDIT_SUBJECT);
    m_form->addItem(start, VAPP_CAL_EDIT_START);
    m_form->insertSeparator(VAPP_CAL_EDIT_START);

    m_form->addItem(to, VAPP_CAL_EDIT_TO);
    m_form->insertSeparator(VAPP_CAL_EDIT_TO);

    m_form->addItem(allDay, VAPP_CAL_EDIT_ALL_DAY);
    if (m_operation == VAPP_CAL_OPERATION_TYPE_ADD)
    {
        m_form->addItem(category, VAPP_CAL_EDIT_CATEGORY);
    }
    m_form->addItem(repeat, VAPP_CAL_EDIT_REPEAT);
    m_form->addItem(reminder, VAPP_CAL_EDIT_REMINDER);
    m_form->addItem(location, VAPP_CAL_EDIT_LOCATION);
    m_form->addItem(note, VAPP_CAL_EDIT_NOTE);

    if(event->src_id != SRV_TDL_EVENT_SOURCE_LOCAL)
    {
        subject->setIsDisabled(VFX_TRUE);
        allDay->setIsDisabled(VFX_TRUE);
        start->setIsDisabled(VFX_TRUE);
        to->setIsDisabled(VFX_TRUE);
        repeat->setIsDisabled(VFX_TRUE);
        location->setIsDisabled(VFX_TRUE);
        note->setIsDisabled(VFX_TRUE);
    }

}

#ifdef __MMI_TASK_APP__
void VappCalEditPage::onPriorityChanged(VappCalPriorityListPage* sender, VfxU32 index)
{
    VfxWString text;
    srv_tdl_task_struct *task = (srv_tdl_task_struct*)m_data;

    task->priority = (VfxU8)convertPriorityMtoS((VAPP_CAL_PRIORITY_ENUM)index);

    text = sender->getPriorityString(index);

    ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_PRIORITY)))->setHintText(text);

}

void VappCalEditPage::initTaskFormContent()
{

    srv_tdl_task_struct *task = (srv_tdl_task_struct*)m_data;

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
    VFX_FRAME_ALIGNER_MODE_SIDE,
    VFX_FRAME_ALIGNER_MODE_SIDE,
    VFX_FRAME_ALIGNER_MODE_SIDE,
    VFX_FRAME_ALIGNER_MODE_SIDE);


    //subject
    VcpFormItemTextInput *subject;
    VFX_OBJ_CREATE(subject, VcpFormItemTextInput, m_form);
    subject->setLabelText((VfxResId)STR_ID_VAPP_CAL_SUBJECT);
    ((VcpTextEditor*)(subject->getTextBox()))->setText((VfxWChar*)(task->subject), VAPP_CAL_MAX_SUBJECT_LEN, VFX_TRUE);
    //set function bar
    VFX_OBJ_CREATE(m_subjectFBar, VcpFunctionBar, this);
    m_subjectFBar->addItem(VAPP_CAL_FBAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_CAL_PREV)); // TODO: replace string
    m_subjectFBar->addItem(VAPP_CAL_FBAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_CAL_NEXT)); // TODO: replace string
    m_subjectFBar->addItem(VAPP_CAL_FBAR_SAVE, VFX_WSTR_RES(STR_ID_VAPP_CAL_SAVE)); 
    m_subjectFBar->setItemSpecial(VAPP_CAL_FBAR_SAVE);
    m_subjectFBar->setDisableItem(VAPP_CAL_FBAR_PREV, VFX_TRUE);
    (subject->getTextBox())->setFunctionBar(m_subjectFBar);
    m_subjectFBar->m_signalButtonTap.connect(this, &VappCalEditPage::onSubjectFBarTap);


    //priority
    VcpFormItemLauncherCell *priority;
    VFX_OBJ_CREATE(priority, VcpFormItemLauncherCell, m_form);
    priority->setMainText((VfxResId)STR_ID_VAPP_CAL_PRIORITY);
    priority->setHintText
    (VappCalPriorityListPage::getPriorityString(convertPriorityStoM((srv_vcal_priority_enum)(task->priority))));
    priority->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    priority->m_signalTap.connect(this, &VappCalEditPage::onItemClicked);


    //Due date and time
    VfxDateTime dt;

    applib_time_struct time;
    VappCalEditDateTimeItem *due;
    VFX_OBJ_CREATE(due, VappCalEditDateTimeItem, m_form);
    due->setLabelText((VfxResId)STR_ID_VAPP_CAL_DUE_TO);
    memcpy(&time, &(task->due_time), sizeof(applib_time_struct));
    dt.setDateTime(&time);
    due->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
    due->setTime(dt.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));
    due->m_signalButtonClicked.connect(this, &VappCalEditPage::onStartDateTimeItemClick);


    //reminder
    VcpFormItemLauncherCell *reminder;
    VFX_OBJ_CREATE(reminder, VcpFormItemLauncherCell, m_form);
    reminder->setMainText((VfxResId)STR_ID_VAPP_CAL_REMINDER);
    reminder->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    reminder->setHintText(VappCalReminderListPage::getReminderString(task->alarm.type));
    reminder->m_signalTap.connect(this, &VappCalEditPage::onItemClicked);

    //Note
    VcpFormItemTextInput *note;
    VFX_OBJ_CREATE(note, VcpFormItemTextInput, m_form);
    note->setLabelText((VfxResId)STR_ID_VAPP_CAL_NOTE);
    //note->setText(VFX_WSTR_STATIC(task->note));
    ((VcpTextEditor*)(note->getTextBox()))->setText((VfxWChar*)(task->details), VAPP_CAL_MAX_NOTE_LEN, VFX_TRUE);
    //set function bar
    VFX_OBJ_CREATE(m_noteFBar, VcpFunctionBar, this);
    m_noteFBar->addItem(VAPP_CAL_FBAR_PREV, VFX_WSTR_RES(STR_ID_VAPP_CAL_PREV)); // TODO: replace string
    m_noteFBar->addItem(VAPP_CAL_FBAR_NEXT, VFX_WSTR_RES(STR_ID_VAPP_CAL_NEXT)); // TODO: replace string
    m_noteFBar->addItem(VAPP_CAL_FBAR_SAVE, VFX_WSTR_RES(STR_ID_VAPP_CAL_SAVE)); 
    m_noteFBar->setItemSpecial(VAPP_CAL_FBAR_SAVE);
    m_noteFBar->setDisableItem(VAPP_CAL_FBAR_NEXT, VFX_TRUE);
    (note->getTextBox())->setFunctionBar(m_noteFBar);
    m_noteFBar->m_signalButtonTap.connect(this, &VappCalEditPage::onNoteFBarTap);


    //layout
    m_form->addItem(subject, VAPP_CAL_EDIT_SUBJECT);
    m_form->insertSeparator(VAPP_CAL_EDIT_SUBJECT);
    m_form->addItem(priority, VAPP_CAL_EDIT_PRIORITY);
    m_form->addItem(due, VAPP_CAL_EDIT_START);
    m_form->insertSeparator(VAPP_CAL_EDIT_START);
    m_form->addItem(reminder, VAPP_CAL_EDIT_REMINDER);
    m_form->addItem(note, VAPP_CAL_EDIT_NOTE);


}
#endif

void VappCalEditPage::onInit()
{
    VfxPage::onInit();


    initData();



    // title 
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        if (m_operation == VAPP_CAL_OPERATION_TYPE_ADD)
        {
            bar->setTitle((VfxResId)STR_ID_VAPP_CAL_ADD_EVT);
        }
        else
        {
            mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_EVENT_OP, onEventDataChangeCallBack, getObjHandle());
            
            #if defined(__MMI_TASK_APP__)
            mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_OP, onDataChangeCallBack, getObjHandle());
            #endif

            bar->setTitle((VfxResId)STR_ID_VAPP_CAL_EDIT_EVT);
        }
    }
    
#ifdef __MMI_TASK_APP__
    else
    {
        if (m_operation == VAPP_CAL_OPERATION_TYPE_ADD)
        {
            bar->setTitle((VfxResId)STR_ID_VAPP_CAL_ADD_TASK);
        }
        else
        {
            mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_OP, onDataChangeCallBack, getObjHandle());

            bar->setTitle((VfxResId)STR_ID_VAPP_CAL_EDIT_TASK);
        }
    }
    #endif  /*__MMI_TASK_APP__*/
    setTopBar(bar);
    creatpage();



}




void VappCalEditPage::creatpage()
{
    //init body 
#ifdef __MMI_TASK_APP__
    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        initEventFormContent();
    }
    else
    {
        initTaskFormContent();
    }    
#else
    initEventFormContent(); 
#endif

    //toolbar
    VcpToolBar *toolbar;
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
    toolbar->addItem(VAPP_CAL_TOOLBAR_EDIT_SAVE, (VfxResId)STR_ID_VAPP_CAL_SAVE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolbar->addItem(VAPP_CAL_TOOLBAR_EDIT_CANCEL, (VfxResId)STR_ID_VAPP_CAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    toolbar->m_signalButtonTap.connect(this, &VappCalEditPage::onTBClick);
    setBottomBar(toolbar);

}


mmi_ret VappCalEditPage::onEventDataChangeCallBack(mmi_event_struct *param)
{
    if(param->evt_id != EVT_ID_SRV_TDL_EVENT_OP)
    {
        return MMI_RET_OK;
    }

    VappCalEditPage *page = (VappCalEditPage *)handleToObject((VfxObjHandle)param->user_data);
    if(page == NULL)
        return MMI_RET_OK;


    srv_tdl_event_op_struct *event = (srv_tdl_event_op_struct *)param;
    VfxBool isValidPage =  ((event->event_id == page->m_eventbuffer.event_id)&&(event->source_id == page->m_eventbuffer.source_id))? VFX_TRUE : VFX_FALSE;

    if(!isValidPage)
    {
        return MMI_RET_OK;
    }

    page->closeRelativePage(event->op_type);
    return MMI_RET_OK;

}


void VappCalEditPage::closeRelativePage(srv_tdl_operator_enum op_type)
{
    switch (op_type)
    {
    case SRV_TDL_OP_DELETE:
    case SRV_TDL_OP_UPDATE:
    {
        if(getMainScr()->isPageIdValid(VAPP_REPETITION_PAGE))
        {
            getMainScr()->closePage(VAPP_REPETITION_PAGE);  
        }
        if(getMainScr()->isPageIdValid(VAPP_REMINDER_PAGE))
        {
            getMainScr()->closePage(VAPP_REMINDER_PAGE);  
        }
        if(getMainScr()->isPageIdValid(VAPP_EDIT_PRIORITY_PAGE))
        {
            getMainScr()->closePage(VAPP_EDIT_PRIORITY_PAGE);  
        }
        getMainScr()->closePage(getId());
    }
        break;
    default:
        break;
    }
}


#if defined(__MMI_TASK_APP__)
mmi_ret VappCalEditPage::onDataChangeCallBack(mmi_event_struct *param)
{
    if (param->evt_id != EVT_ID_SRV_TDL_OP)
    {
        return MMI_RET_OK;
    }

    srv_tdl_op_evt_struct *event = (srv_tdl_op_evt_struct *)param; 
    VappCalEditPage *page = (VappCalEditPage *)handleToObject((VfxObjHandle)param->user_data);
    if (page == NULL)
        return MMI_RET_OK;

    VfxBool isValidPage =  (event->store_idx == page->m_index)? VFX_TRUE : VFX_FALSE;

    if (!isValidPage)
    {
        return MMI_RET_OK;
    }

    page->closeRelativePage(event->op_type);
    return MMI_RET_OK;
}
#endif

void VappCalEditPage::onUpdateData()
{
    VFX_OBJ_CLOSE(m_form);

    if (m_data)
    {
        VFX_FREE_MEM(m_data);        
    }

    initData();
    #ifdef __MMI_TASK_APP__
    if (SRV_TDL_VCAL_EVENT == m_vcalType)
    {
        initEventFormContent();
    }
    else
    {
        initTaskFormContent();
    }
    #else
    initEventFormContent();
    #endif /*__MMI_TASK_APP__*/
}

#ifdef __MMI_CAL_FUNCBAR__
void VappCalEditPage::onSubjectFBarTap(VfxObject* sender, VfxId id)
{
    VcpFormItemTextInput *text;
    
    switch (id)
    {
    case VAPP_CAL_FBAR_PREV:
        break;
    case VAPP_CAL_FBAR_NEXT:
        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            //location
            text = (VcpFormItemTextInput*)(m_form->getItem(VAPP_CAL_EDIT_LOCATION));
        }
        else
        {
            //note
            text = (VcpFormItemTextInput*)(m_form->getItem(VAPP_CAL_EDIT_NOTE));
        }
        (text->getTextBox())->activate();
        break;
    case VAPP_CAL_FBAR_SAVE:
        if(saveData())
        {
            getMainScr()->popPage();
        }
        break;
    default:
        break;
    }
}

void VappCalEditPage::onLocationFBarTap(VfxObject* sender, VfxId id)
{
    VcpFormItemTextInput *text;
    
    switch (id)
    {
    case VAPP_CAL_FBAR_PREV:
        //subject
        text = (VcpFormItemTextInput*)(m_form->getItem(VAPP_CAL_EDIT_SUBJECT));
        (text->getTextBox())->activate();
        m_form->scrollItemToView(VAPP_CAL_EDIT_SUBJECT, VCPFORM_SCROLL_TOP);
        break;
    case VAPP_CAL_FBAR_NEXT:
        //note
        text = (VcpFormItemTextInput*)(m_form->getItem(VAPP_CAL_EDIT_NOTE));
        (text->getTextBox())->activate();
        break;
    case VAPP_CAL_FBAR_SAVE:
       if(saveData())
        {
            getMainScr()->popPage();
        }
        break;        
    default:
        break;
    }
}


void VappCalEditPage::onNoteFBarTap(VfxObject* sender, VfxId id)
{
    VcpFormItemTextInput *text;
    
    switch (id)
    {
    case VAPP_CAL_FBAR_PREV:
        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            //location
            text = (VcpFormItemTextInput*)(m_form->getItem(VAPP_CAL_EDIT_LOCATION));
        }
        #ifdef __MMI_TASK_APP__
        else
        {
            //subject
            text = (VcpFormItemTextInput*)(m_form->getItem(VAPP_CAL_EDIT_SUBJECT));
        }
        #endif
        (text->getTextBox())->activate();
        break;
    case VAPP_CAL_FBAR_SAVE:
        if (saveData())
        {
            getMainScr()->popPage();
        }
        break;        
    default:
        break;
    }
}
#endif /*__MMI_CAL_FUNCBAR__*/

void VappCalEditPage::onItemClicked(VcpFormItemCell* sender, VfxId id)
{
    srv_tdl_event_struct *event = NULL;
    
#ifdef __MMI_TASK_APP__
    srv_tdl_task_struct *task = NULL;
#endif

    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        event = (srv_tdl_event_struct*)m_data;
    }
#ifdef __MMI_TASK_APP__
    else
    {
        task = (srv_tdl_task_struct*)m_data;
    }
#endif

    switch (id)
    {
    case VAPP_CAL_EDIT_CATEGORY:

        VappCalCategoryListPage *pageCategory;

        VFX_OBJ_CREATE_EX(pageCategory, VappCalCategoryListPage, this, (convertCategoryStoM((srv_vcal_category_type_enum)(event->category))));
        getMainScr()->pushPage(0, pageCategory);
        pageCategory->m_signalSelectNewItem.connect(this, &VappCalEditPage::onCategoryChanged);

        break;

    case VAPP_CAL_EDIT_REPEAT:

        VappCalRepeatListPage *pageRepeat;

        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            VFX_OBJ_CREATE_EX(pageRepeat, VappCalRepeatListPage, 
            this, (convertRepeatStoM((srv_tdl_repeat_rule_enum)(event->repeat.rule))));
        }

        getMainScr()->pushPage(VAPP_REPETITION_PAGE, pageRepeat);
        pageRepeat->m_signalSelectNewItem.connect(this, &VappCalEditPage::onRepeatChanged);

        break;

    case VAPP_CAL_EDIT_REMINDER:

       VappCalReminderListPage *pageReminder;
        VfxBool specialType;
        VfxU32 reminder;

        specialType = VFX_FALSE;

        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            reminder = event->alarm.type;
            if (convertCategoryStoM((srv_vcal_category_type_enum)(event->category)) == VAPP_CAL_CATEGORY_SPECIALDAY ||
            convertCategoryStoM((srv_vcal_category_type_enum)(event->category)) == VAPP_CAL_CATEGORY_BIRTHDAY)
            {
                specialType = VFX_TRUE;
                reminder = VappCalReminderListPage::convertToUIIndex(event->alarm.type);
            }
        }
#ifdef __MMI_TASK_APP__
        else
        {
            reminder = task->alarm.type;
        }
#endif

        VFX_OBJ_CREATE_EX(pageReminder, 
                    VappCalReminderListPage, 
                    this, 
                    (reminder, specialType, m_data, m_vcalType)); 


        getMainScr()->pushPage(VAPP_REMINDER_PAGE, pageReminder);
        pageReminder->m_signalSelectNewItem.connect(this, &VappCalEditPage::onReminderChanged);

        break;   
        
#ifdef __MMI_TASK_APP__
    case VAPP_CAL_EDIT_PRIORITY:

        VappCalPriorityListPage *pagePriority;

        VFX_OBJ_CREATE_EX(pagePriority, VappCalPriorityListPage, this,
                (convertPriorityStoM((srv_vcal_priority_enum)(task->priority))));
        getMainScr()->pushPage(VAPP_EDIT_PRIORITY_PAGE, pagePriority);
        pagePriority->m_signalSelectNewItem.connect(this, &VappCalEditPage::onPriorityChanged);

        break; 
#endif

    default:
        break;
    }
}


void VappCalEditPage::onCategoryChanged(VappCalCategoryListPage* sender, VfxU32 index)
{
    //category can be changed only in ADD operation page.
    //and only used by Event.


    VfxWString text;
    srv_tdl_event_struct *event;
    event = (srv_tdl_event_struct*)m_data;


    text = sender->getCategoryString(index);
    ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_CATEGORY)))->setHintText(text);
    event->category = (VfxU8)convertCategoryMtoS((VAPP_CAL_CATEGORY_ENUM)index);



    //re-layout: start ,to, allday, repeat,reminder
    //And update cell to initial value when changing category

    VappCalEditDateTimeItem *start = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_START));
    VappCalEditDateTimeItem *to = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_TO));
    VcpFormItemSwitchCell *allDay = (VcpFormItemSwitchCell*)(m_form->getItem(VAPP_CAL_EDIT_ALL_DAY));
    VcpFormItemLauncherCell *repeat = (VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REPEAT));
    VcpFormItemLauncherCell *reminder = (VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REMINDER));
    VfxDateTime dt;

    applib_time_struct time;


    if (index == VAPP_CAL_CATEGORY_SPECIALDAY ||
        index == VAPP_CAL_CATEGORY_BIRTHDAY)
    {
        start->changeDateLarge(VFX_TRUE);
        start->m_btnTime->setHidden(VFX_TRUE);
        start->setLabelText((VfxResId)STR_ID_VAPP_CAL_DATE);

        to->setIsHidden(VFX_TRUE);

        //setInitDateTime();
        memcpy(&time, &(event->start_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);
        start->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));

        allDay->setSwitchStatus(VFX_TRUE);
        allDay->setIsDisabled(VFX_TRUE);
        event->all_day = VFX_TRUE;

        repeat->setHintText(VappCalRepeatListPage::getRepeatString(VAPP_CAL_REPEAT_YEARLY));
        repeat->setIsDisabled(VFX_TRUE);
        event->repeat.rule = SRV_TDL_RULE_YEARLY;
        event->alarm.type = VAPP_CAL_REMINDER_1DAY_EARLIER;

        VfxWString strReminder;
        strReminder = VappCalReminderListPage::getReminderString(VAPP_CAL_REMINDER_1DAY_EARLIER);
        if (event->alarm.type != VAPP_CAL_REMINDER_NEVER)
        {
            strReminder += VappCalReminderListPage::getReminderAdditionalString();
        }
        reminder->setHintText(strReminder);
    }
    else
    {
        start->setLabelText((VfxResId)STR_ID_VAPP_CAL_START);
        start->changeDateLarge(VFX_FALSE);
        start->m_btnTime->setHidden(VFX_FALSE);

        to->setIsHidden(VFX_FALSE);
        to->changeDateLarge(VFX_FALSE);
        to->m_btnTime->setHidden(VFX_FALSE);

        //setInitDateTime();

        memcpy(&time, &(event->start_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);
        start->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        start->setTime(dt.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));

        memcpy(&time, &(event->end_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);
        to->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        to->setTime(dt.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));

        allDay->setSwitchStatus(VFX_FALSE);
        allDay->setIsDisabled(VFX_FALSE);
        event->all_day = VFX_FALSE;

        repeat->setHintText(VappCalRepeatListPage::getRepeatString(VAPP_CAL_REPEAT_NEVER));
        repeat->setIsDisabled(VFX_FALSE);
        event->repeat.rule = SRV_TDL_RULE_ONCE;

        reminder->setHintText(VappCalReminderListPage::getReminderString(VAPP_CAL_REMINDER_NEVER));
        event->alarm.type = VAPP_CAL_REMINDER_NEVER;

    }


}


void VappCalEditPage::onRepeatChanged(VappCalRepeatListPage* sender, VfxU32 index)
{
        VfxWString text;

        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            srv_tdl_event_struct *event;
            event = (srv_tdl_event_struct *)m_data;

            event->repeat.rule = convertRepeatMtoS((VAPP_CAL_REPEAT_ENUM)index);

            if (!checkreminderValidation(m_data, m_vcalType, 
                            (VAPP_CAL_REMINDER_ENUM)(event->alarm.type)))
            {
                ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REMINDER)))
                ->setHintText(VappCalReminderListPage::getReminderString(VAPP_CAL_REMINDER_NEVER));
                event->alarm.type = VAPP_CAL_REMINDER_NEVER;
                memset(&(event->alarm.first_launch), 0, sizeof(MYTIME));
            }

        }


        text = sender->getRepeatString(index);
        ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REPEAT)))->setHintText(text);

}


void VappCalEditPage::closeVK()
{
    VcpFormItemTextInput* textInput;


    textInput = (VcpFormItemTextInput*)m_form->getItem(VAPP_CAL_EDIT_SUBJECT);
    textInput->getTextBox()->deactivate();
    textInput = (VcpFormItemTextInput*)m_form->getItem(VAPP_CAL_EDIT_NOTE);
    textInput->getTextBox()->deactivate();
    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        textInput = (VcpFormItemTextInput*)m_form->getItem(VAPP_CAL_EDIT_LOCATION);
        textInput->getTextBox()->deactivate();
    }
}


void VappCalEditPage::onStartDateTimeItemClick(VfxObject *obj, VfxId id)
{
    srv_tdl_event_struct *event;
    
#ifdef __MMI_TASK_APP__
    srv_tdl_task_struct *task;
#endif
    VcpDatePickerStruct date;
    VcpTimePickerStruct time;

    closeVK();
    
    switch (id)
    {
    case VAPP_CAL_EDIT_DATETIME_BTN_DATE:
        VFX_OBJ_CREATE_EX(m_datePickerPopup, VappCalDatePickerPopup, 
                        this, (VFX_FALSE, m_data, m_vcalType, VAPP_CAL_DATETIIME_START, (VfxPage*)getParent()));
        
        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            event = (srv_tdl_event_struct*)m_data;
            date.year = event->start_time.nYear;
            date.month = event->start_time.nMonth;
            date.day = event->start_time.nDay;
        }
#ifdef __MMI_TASK_APP__
        else
        {
            task = (srv_tdl_task_struct*)m_data;
            date.year = task->due_time.nYear;
            date.month = task->due_time.nMonth;
            date.day = task->due_time.nDay;
        }
#endif
        applib_time_struct contentTime ,theEaliestTime,theLaterTime;
        memset(&contentTime,0,sizeof(applib_time_struct));
        memset(&theEaliestTime,0,sizeof(applib_time_struct));
        memset(& theLaterTime,0,sizeof(applib_time_struct));

        contentTime.nYear = date.year;
        contentTime.nMonth = date.month;
        contentTime.nDay = date.day;

        theEaliestTime.nYear = 1970;
        theEaliestTime.nMonth = 1;
        theEaliestTime.nDay = 1;

        theLaterTime.nYear = 2030;
        theLaterTime.nMonth = 12;
        theLaterTime.nDay = 31;

        if (CompareTime(contentTime,theEaliestTime,NULL) < 0)
        {
            memcpy(&contentTime,&theEaliestTime,sizeof(applib_time_struct));
        }
        else if (CompareTime(contentTime,theLaterTime,NULL) > 0)
        {
            memcpy(&contentTime,&theLaterTime,sizeof(applib_time_struct));
        }

        date.year = contentTime.nYear;
        date.month = contentTime.nMonth;
        date.day =  contentTime.nDay;

        m_datePickerPopup->m_datePicker->setDate(date);

        m_datePickerPopup->m_signalButtonClicked.connect(this, 
        &VappCalEditPage::onBtnStartDatePopupBtnClick);
        m_datePickerPopup->setAutoDestory(VFX_TRUE);
        m_datePickerPopup->show(VFX_TRUE);
        break;

    case VAPP_CAL_EDIT_DATETIME_BTN_TIME:
        VFX_OBJ_CREATE_EX(m_timePickerPopup, VappCalTimePickerPopup, 
                        this, (m_data, m_vcalType, VAPP_CAL_DATETIIME_START, (VfxPage*)getParent()));
        
        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            event = (srv_tdl_event_struct*)m_data;
            time.hour = event->start_time.nHour;
            time.minute = event->start_time.nMin;
        }
#ifdef __MMI_TASK_APP__
        else
        {
            task = (srv_tdl_task_struct*)m_data;
            time.hour = task->due_time.nHour;
            time.minute = task->due_time.nMin;
        }
#endif

        m_timePickerPopup->m_timePicker->setTime(time);
        m_timePickerPopup->m_signalButtonClicked.connect(this, 
                            &VappCalEditPage::onBtnStartTimePopupBtnClick);
        m_timePickerPopup->setAutoDestory(VFX_TRUE);
        m_timePickerPopup->show(VFX_TRUE);        
        break;
        
    default:        
        break;
    }

}


void VappCalEditPage::onEndDateTimeItemClick(VfxObject *obj, VfxId id)
{
    srv_tdl_event_struct *event;
    VcpDatePickerStruct date;
    VcpTimePickerStruct time;

    if (m_vcalType != SRV_TDL_VCAL_EVENT)
    {
        return; // impossible
    }

    closeVK();
    
    switch (id)
    {
    case VAPP_CAL_EDIT_DATETIME_BTN_DATE:
        VFX_OBJ_CREATE_EX(m_datePickerPopup, VappCalDatePickerPopup, 
                        this, (VFX_FALSE, m_data, m_vcalType, VAPP_CAL_DATETIIME_END, (VfxPage*)getParent()));
        
        event = (srv_tdl_event_struct*)m_data;
        date.year = event->end_time.nYear;
        date.month = event->end_time.nMonth;
        date.day = event->end_time.nDay;

        m_datePickerPopup->m_datePicker->setDate(date);
        m_datePickerPopup->m_signalButtonClicked.connect(this, 
                            &VappCalEditPage::onBtnEndDatePopupBtnClick);
        m_datePickerPopup->setAutoDestory(VFX_TRUE);
        m_datePickerPopup->show(VFX_TRUE);
        break;
        
    case VAPP_CAL_EDIT_DATETIME_BTN_TIME:
        VFX_OBJ_CREATE_EX(m_timePickerPopup, VappCalTimePickerPopup,
                        this, (m_data, m_vcalType, VAPP_CAL_DATETIIME_END, (VfxPage*)getParent()));
        

        event = (srv_tdl_event_struct*)m_data;
        time.hour = event->end_time.nHour;
        time.minute = event->end_time.nMin;
              
        m_timePickerPopup->m_timePicker->setTime(time);
        m_timePickerPopup->m_signalButtonClicked.connect(this, 
                            &VappCalEditPage::onBtnEndTimePopupBtnClick);
        m_timePickerPopup->setAutoDestory(VFX_TRUE);
        m_timePickerPopup->show(VFX_TRUE);        
        break;
        
    default:        
        break;
    }

}


void VappCalEditPage::onBtnStartDatePopupBtnClick(VfxObject *obj, VfxId id)
{
    VcpDatePickerStruct date;
    VfxDateTime dt;

    srv_tdl_event_struct *event;
    VappCalEditDateTimeItem *startItem = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_START));
    VappCalEditDateTimeItem *toItem = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_TO));

    switch (id)
    {
    case VAPP_CAL_DATE_PICKER_POPUP_BTN_LEFT: //OK
        date = m_datePickerPopup->m_datePicker->getDate();

        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            event = (srv_tdl_event_struct*)m_data;
            event->start_time.nYear = date.year;
            event->start_time.nMonth = date.month;
            event->start_time.nDay = date.day;
            VAPP_CAL_CATEGORY_ENUM category = convertCategoryStoM((srv_vcal_category_type_enum)(event->category));

            // process end time
            if (category == VAPP_CAL_CATEGORY_SPECIALDAY ||
                category == VAPP_CAL_CATEGORY_BIRTHDAY)
            {
                event->end_time.nYear = date.year;
                event->end_time.nMonth = date.month;
                event->end_time.nDay = date.day;
            }
            else
            {
                applib_time_struct incTime;
                memset(&incTime, 0, sizeof(applib_time_struct));
                incTime.nHour = 1;

                applib_dt_increase_time((applib_time_struct*)&event->start_time, &incTime, (applib_time_struct*)&event->end_time);

                if (VappCalUtility::dateTimeIsOutOfBounder(event->start_time.nYear, category)
                || VappCalUtility::dateTimeIsOutOfBounder(event->end_time.nYear, category))
                {
                    event->end_time = event->start_time;
                }
            }

            // check repeat
            if (durationIsMoreThan1Day(&(event->start_time), &(event->end_time)))
            {
                VcpFormItemLauncherCell *repeat;
                repeat = (VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REPEAT));
                repeat->setHintText(VappCalRepeatListPage::getRepeatString(VAPP_CAL_REPEAT_NEVER));
                repeat->setIsDisabled(VFX_TRUE);
                event->repeat.rule = SRV_TDL_RULE_ONCE;
            }
            else
            {
                if ((category != VAPP_CAL_CATEGORY_SPECIALDAY) && (category != VAPP_CAL_CATEGORY_BIRTHDAY))
                {
                    VcpFormItemLauncherCell *repeat;
                    repeat = (VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REPEAT));
                    repeat->setIsDisabled(VFX_FALSE);
                }
            }

            // check reminder
            if (!checkreminderValidation(m_data, m_vcalType, 
                        (VAPP_CAL_REMINDER_ENUM)(event->alarm.type)))
            {
                VcpFormItemLauncherCell *reminder;
                reminder = ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REMINDER)));
                reminder->setHintText(VappCalReminderListPage::getReminderString(VAPP_CAL_REMINDER_NEVER));
                event->alarm.type = VAPP_CAL_REMINDER_NEVER;
                memset(&(event->alarm.first_launch), 0, sizeof(MYTIME));
            }
            else
            {
                setReminderFirstLaunchTime(&(event->start_time), 
                                    &(event->alarm.first_launch),
                                    (VAPP_CAL_REMINDER_ENUM)event->alarm.type,
                                    (VfxBool)(event->all_day),
                                    convertCategoryStoM((srv_vcal_category_type_enum)(event->category)));
            }
            dt.setDateTime((applib_time_struct*)&(event->start_time));
            startItem->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));

            dt.setDateTime((applib_time_struct*)&(event->end_time));
            toItem->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        }
#ifdef __MMI_TASK_APP__
        else
        {
        
            srv_tdl_task_struct *task;
            task = (srv_tdl_task_struct*)m_data;
            task->due_time.nYear = date.year;
            task->due_time.nMonth = date.month;
            task->due_time.nDay = date.day;

            // check reminder
            if (!checkreminderValidation(m_data, m_vcalType, 
                        (VAPP_CAL_REMINDER_ENUM)(task->alarm.type)))
            {
                VcpFormItemLauncherCell *reminder;
                reminder = ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REMINDER)));
                reminder->setHintText(VappCalReminderListPage::getReminderString(VAPP_CAL_REMINDER_NEVER));
                task->alarm.type = VAPP_CAL_REMINDER_NEVER;
                memset(&(task->alarm.first_launch), 0, sizeof(MYTIME));
            }
            else
            {
                setReminderFirstLaunchTime(&(task->due_time), 
                &(task->alarm.first_launch),
                (VAPP_CAL_REMINDER_ENUM)task->alarm.type);
            }
            
            dt.setDateTime((applib_time_struct*)&(task->due_time));
            startItem->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        }
#endif
                
        break;
    default:
        break;
    }
}


void VappCalEditPage::onBtnEndDatePopupBtnClick(VfxObject *obj, VfxId id)
{
    VcpDatePickerStruct date;
    VfxDateTime dt;

    srv_tdl_event_struct *event;
    applib_time_struct applibTime;
    VappCalEditDateTimeItem *endItem = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_TO));

    if (m_vcalType != SRV_TDL_VCAL_EVENT)
    {
        //impossible
        return;
    }

    switch (id)
    {
    case VAPP_CAL_DATE_PICKER_POPUP_BTN_LEFT: // OK
        date = m_datePickerPopup->m_datePicker->getDate();

        event = (srv_tdl_event_struct*)m_data;
        event->end_time.nYear = date.year;
        event->end_time.nMonth = date.month;
        event->end_time.nDay = date.day;


        // check repeat
        if (durationIsMoreThan1Day(&(event->start_time), &(event->end_time)))
        {
            VcpFormItemLauncherCell *repeat;
            repeat = (VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REPEAT));
            repeat->setHintText(VappCalRepeatListPage::getRepeatString(VAPP_CAL_REPEAT_NEVER));
            repeat->setIsDisabled(VFX_TRUE);
            event->repeat.rule = SRV_TDL_RULE_ONCE;
        }
        else
        {
            VcpFormItemLauncherCell *repeat;
            repeat = (VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REPEAT));
            repeat->setIsDisabled(VFX_FALSE);
        }

        // check reminder
        if (!checkreminderValidation(m_data, m_vcalType, 
                    (VAPP_CAL_REMINDER_ENUM)(event->alarm.type)))
        {
            VcpFormItemLauncherCell *reminder; 
            reminder = ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REMINDER)));
            reminder->setHintText(VappCalReminderListPage::getReminderString(VAPP_CAL_REMINDER_NEVER));
            event->alarm.type = VAPP_CAL_REMINDER_NEVER;
            memset(&(event->alarm.first_launch), 0, sizeof(MYTIME));
        }
            
        memcpy(&applibTime, &(event->end_time), sizeof(applib_time_struct));

        dt.setDateTime(&applibTime);
        endItem->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        
        break;
   
    default:
        break;
    }
}


void VappCalEditPage::onBtnStartTimePopupBtnClick(VfxObject *obj, VfxId id)
{
    VcpTimePickerStruct pickerTime;
    VfxDateTime dt;
    srv_tdl_event_struct *event;
    VappCalEditDateTimeItem *startItem = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_START));
    VappCalEditDateTimeItem *toItem = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_TO));

    switch (id)
    {
    case VAPP_CAL_DATE_PICKER_POPUP_BTN_LEFT: //OK
        pickerTime = m_timePickerPopup->m_timePicker->getTime();

        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            event = (srv_tdl_event_struct*)m_data;
            event->start_time.nHour= pickerTime.hour;
            event->start_time.nMin = pickerTime.minute;
            VAPP_CAL_CATEGORY_ENUM category = convertCategoryStoM((srv_vcal_category_type_enum)(event->category));

            applib_time_struct incTime;
            memset(&incTime, 0, sizeof(applib_time_struct));
            incTime.nHour = 1;

            applib_dt_increase_time((applib_time_struct*)&event->start_time, &incTime, (applib_time_struct*)&event->end_time);

            if (VappCalUtility::dateTimeIsOutOfBounder(event->start_time.nYear, category)
            || VappCalUtility::dateTimeIsOutOfBounder(event->end_time.nYear, category))
            {
                event->end_time = event->start_time;
            }

            // check repeat
            if (durationIsMoreThan1Day(&(event->start_time), &(event->end_time)))
            {
                VcpFormItemLauncherCell *repeat;
                repeat = (VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REPEAT));
                repeat->setHintText(VappCalRepeatListPage::getRepeatString(VAPP_CAL_REPEAT_NEVER));
                repeat->setIsDisabled(VFX_TRUE);
                event->repeat.rule = SRV_TDL_RULE_ONCE;
            }
            else
            {
                VcpFormItemLauncherCell *repeat;
                repeat = (VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REPEAT));
                repeat->setIsDisabled(VFX_FALSE);
            }

            // check reminder
            if (!checkreminderValidation(m_data, m_vcalType, 
                        (VAPP_CAL_REMINDER_ENUM)(event->alarm.type)))
            {
                VcpFormItemLauncherCell *reminder;
                reminder = ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REMINDER)));
                reminder->setHintText(VappCalReminderListPage::getReminderString(VAPP_CAL_REMINDER_NEVER));
                event->alarm.type = VAPP_CAL_REMINDER_NEVER;
                memset(&(event->alarm.first_launch), 0, sizeof(MYTIME));
            }
            else
            {
                setReminderFirstLaunchTime(&(event->start_time), 
                                &(event->alarm.first_launch),
                                (VAPP_CAL_REMINDER_ENUM)event->alarm.type,
                                (VfxBool)(event->all_day),
                                convertCategoryStoM((srv_vcal_category_type_enum)(event->category)));
            }
            
            dt.setDateTime((applib_time_struct*)&event->start_time);
            startItem->setTime(dt.getDateTimeString(
                            VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));

            dt.setDateTime((applib_time_struct*)&event->end_time);
            toItem->setTime(dt.getDateTimeString(
                            VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));
            toItem->setDate(dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK));
        }
#ifdef __MMI_TASK_APP__
        else
        {
            srv_tdl_task_struct *task;
            task = (srv_tdl_task_struct*)m_data;
            task->due_time.nHour = pickerTime.hour;
            task->due_time.nMin = pickerTime.minute;

            // check reminder
            if (!checkreminderValidation(m_data, m_vcalType, 
                        (VAPP_CAL_REMINDER_ENUM)(task->alarm.type)))
            {
                VcpFormItemLauncherCell *reminder;
                reminder = ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REMINDER)));
                reminder->setHintText(VappCalReminderListPage::getReminderString(VAPP_CAL_REMINDER_NEVER));
                task->alarm.type = VAPP_CAL_REMINDER_NEVER;
                memset(&(task->alarm.first_launch), 0, sizeof(MYTIME));
            }
            else
            {
                setReminderFirstLaunchTime(&(task->due_time), 
                                &(task->alarm.first_launch),
                                (VAPP_CAL_REMINDER_ENUM)task->alarm.type);
            }
            
            dt.setDateTime((applib_time_struct*)&task->due_time);
                        startItem->setTime(dt.getDateTimeString(
                        VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));
        }
#endif
                
        break;
        
    default:
        break;
    }

}


void VappCalEditPage::onBtnEndTimePopupBtnClick(VfxObject *obj, VfxId id)
{
    VcpTimePickerStruct pickerTime;
    VfxDateTime dt;
    srv_tdl_event_struct *event;
    applib_time_struct applibTime;
    VappCalEditDateTimeItem *endItem = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_TO));

    if (m_vcalType != SRV_TDL_VCAL_EVENT)
    {
        return; //impossible
    }

    switch (id)
    {
    case VAPP_CAL_DATE_PICKER_POPUP_BTN_LEFT: //OK
        pickerTime = m_timePickerPopup->m_timePicker->getTime();


        event = (srv_tdl_event_struct*)m_data;
        event->end_time.nHour= pickerTime.hour;
        event->end_time.nMin = pickerTime.minute;

        memcpy(&applibTime, &(event->end_time), sizeof(applib_time_struct));

        dt.setDateTime(&applibTime);
        endItem->setTime(dt.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));
        
        break;
        
    
        
    default:
        break;
    }

}


VfxBool VappCalEditPage::durationIsMoreThan1Day(const MYTIME *start, const MYTIME *to)
{
    if (start->nYear != to->nYear || start->nMonth != to->nMonth || start->nDay != to->nDay)
    {
        return VFX_TRUE;
    }    

    return VFX_FALSE;
}


VfxBool VappCalEditPage::endTimeIsLessThanStartTime(const MYTIME *start, const MYTIME *to)
{
    if (applib_dt_compare_time((applib_time_struct*)start, (applib_time_struct*)to, NULL)
        == DT_TIME_GREATER)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;

}



#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappCalEditPage::onReminderChanged(VappCalReminderListPage* sender, VfxU32 index)
{
    VfxWString text;
    VfxU32 alarmType;


    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
    
        srv_tdl_event_struct *event = (srv_tdl_event_struct *)m_data;
       
        VAPP_CAL_CATEGORY_ENUM categoryUI = convertCategoryStoM((srv_vcal_category_type_enum)(event->category));

        if (categoryUI == VAPP_CAL_CATEGORY_SPECIALDAY ||
            categoryUI == VAPP_CAL_CATEGORY_BIRTHDAY)
        {

            text = sender->getSpecialReminderString(index);

            //adjust reminder type to the real value 
            //according to the VAPP_CAL_REMINDER_ENUM
            alarmType = VappCalReminderListPage::convertToDataIndex(index);

            if (alarmType != VAPP_CAL_REMINDER_NEVER)
            {
                text += VappCalReminderListPage::getReminderAdditionalString();
            }
        }
        else
        {
            alarmType = index;
            text = sender->getReminderString(index);
        }


        setReminderFirstLaunchTime(&(event->start_time), 
                            &(event->alarm.first_launch),
                            (VAPP_CAL_REMINDER_ENUM)alarmType,
                            (VfxBool)(event->all_day),
                            categoryUI);

        event->alarm.type = (VfxU8)alarmType;
    }
    
#ifdef __MMI_TASK_APP__
    else
    {
    
        srv_tdl_task_struct *task = (srv_tdl_task_struct *)m_data;
        
        alarmType = index;
        text = sender->getReminderString(index);


        setReminderFirstLaunchTime(&(task->due_time), 
                            &(task->alarm.first_launch),
                            (VAPP_CAL_REMINDER_ENUM)alarmType);

        task->alarm.type = (VfxU8)alarmType;
    }
#endif

    ((VcpFormItemLauncherCell*)(m_form->getItem(VAPP_CAL_EDIT_REMINDER)))->setHintText(text);


}


void VappCalEditPage::onTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case VAPP_CAL_TOOLBAR_EDIT_SAVE:
        if(saveData())
        {
            getMainScr()->popPage();
        }
        break;
    case VAPP_CAL_TOOLBAR_EDIT_CANCEL:
        getMainScr()->popPage();
        break;
    default:
        break;
    } 


}


void VappCalEditPage::allDaySwitchChangeState(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    item->setSwitchStatus(newStatus);
}



void VappCalEditPage::allDaySwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    // allDay is only used by Event.

    VappCalEditDateTimeItem *start, *to; 

    item->setSwitchStatus(newStatus);
    start = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_START));
    to = (VappCalEditDateTimeItem*)(m_form->getItem(VAPP_CAL_EDIT_TO));

    srv_tdl_event_struct *event = (srv_tdl_event_struct*)m_data;


    if (newStatus == VFX_TRUE) //ALL DAY ON
    {
        // hide Start time and To time
        // resize Start date and To date

        start->changeDateLarge(VFX_TRUE);
        start->m_btnTime->setHidden(VFX_TRUE);

        to->changeDateLarge(VFX_TRUE);
        to->m_btnTime->setHidden(VFX_TRUE);

        event->all_day = VFX_TRUE;

    }
    else // ALL DAY OFF
    {
        start->changeDateLarge(VFX_FALSE);
        start->m_btnTime->setHidden(VFX_FALSE);

        to->changeDateLarge(VFX_FALSE);
        to->m_btnTime->setHidden(VFX_FALSE);

        event->all_day = VFX_FALSE;
    }



    if (!checkreminderValidation(m_data, m_vcalType, 
        (VAPP_CAL_REMINDER_ENUM)(event->alarm.type)))
    {
        ((VcpFormItemLauncherCell*)(m_form->getItem
                (VAPP_CAL_EDIT_REMINDER)))->setHintText(
                VappCalReminderListPage::getReminderString(VAPP_CAL_REMINDER_NEVER));
        event->alarm.type = VAPP_CAL_REMINDER_NEVER;
        memset(&(event->alarm.first_launch), 0, sizeof(MYTIME));
    }

}


VAPP_CAL_REPEAT_ENUM VappCalEditPage::convertRepeatStoM(const srv_tdl_repeat_rule_enum &repeat)
{
    if (repeat < SRV_TDL_RULE_TOTAL)
    {
        return s_srv2AppRepeat[repeat];
    }

    return VAPP_CAL_REPEAT_NEVER;
}


srv_tdl_repeat_rule_enum VappCalEditPage::convertRepeatMtoS(const VAPP_CAL_REPEAT_ENUM &repeat)
{
    if (repeat < VAPP_CAL_REPEAT_TOTAL)
    {
        return s_app2SrvRepeat[repeat]; 
    }

    return SRV_TDL_RULE_ONCE;
}






srv_vcal_category_type_enum VappCalEditPage::convertCategoryMtoS(const VAPP_CAL_CATEGORY_ENUM &category)
{
    if (category < VAPP_CAL_CATEGORY_TOTAL)
    {
        return s_app2SrvCategory[category];
    }

    return SRV_VCAL_CATEGORY_TYPE_REMINDER; //default value
}

#ifdef __MMI_TASK_APP__

VAPP_CAL_PRIORITY_ENUM VappCalEditPage::convertPriorityStoM(const srv_vcal_priority_enum &priority)
{


    if (priority < SRV_VCAL_PRIORITY_TOTAL)
    {
        return s_srv2AppPriority[priority];
    }

    return VAPP_CAL_PRIORITY_MEDIUM;
}


srv_vcal_priority_enum VappCalEditPage::convertPriorityMtoS(const VAPP_CAL_PRIORITY_ENUM &priority)
{

    if (priority < VAPP_CAL_PRIORITY_TOTAL)
    {
        return s_app2SrvPriority[priority];
    }

    return SRV_VCAL_PRIORITY_MEDIUM; //default value
}
#endif   /*__MMI_TASK_APP__*/

/***************************************************************************** 
 * Class VappCalEditDateTimeItem
 *****************************************************************************/

VappCalEditDateTimeItem::VappCalEditDateTimeItem():
    m_btnDate(NULL),
    m_btnTime(NULL),
    m_date(VFX_WSTR_EMPTY),
    m_time(VFX_WSTR_EMPTY),
    m_large(VFX_FALSE)
{}


void VappCalEditDateTimeItem::onUpdate()
{
    VcpFormItemLabeledControl::onUpdate();

    VfxRect targetRect = getControlRect();      

    if (m_large)
    {   
        if (m_btnDate)
        {
            m_btnDate->setSize(targetRect.getWidth(), targetRect.getHeight());	
        }
    }
    else
    {    
        VfxS32 width = targetRect.size.width;
        if (m_btnDate)
        {
            targetRect.size.width = (VfxU32)((targetRect.getWidth() - VAPP_CAL_DATETIME_FORM_ITEM_BTN_GAP) * 0.6f);
            m_btnDate->setRect(targetRect);		
        }

        if (m_btnTime)
        {
            targetRect.origin.x += m_btnDate->getSize().width + VAPP_CAL_DATETIME_FORM_ITEM_BTN_GAP;
            targetRect.size.width =  (VfxU32)((width - VAPP_CAL_DATETIME_FORM_ITEM_BTN_GAP) * 0.4f);      
            m_btnTime->setRect(targetRect);
        }
    }
}

void VappCalEditDateTimeItem::setDate(const VfxWString &date)
{
    m_date = date;

    if (m_btnDate)
    {
        m_btnDate->setText(date);
    }
}


void VappCalEditDateTimeItem::setTime(const VfxWString &time)
{
    m_time = time;

    if (m_btnTime)
    {
        m_btnTime->setText(time);
    }
}


void VappCalEditDateTimeItem::onInit()
{
    VcpFormItemLabeledControl::onInit();

    setLabelPosition(VCPFORM_TOP_LEFT);

    VFX_OBJ_CREATE(m_btnDate, VcpButton, this);


    m_btnDate->setText(m_date);
    m_btnDate->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
    m_btnDate->setId(VAPP_CAL_EDIT_DATETIME_BTN_DATE);
    m_btnDate->m_signalClicked.connect(this, &VappCalEditDateTimeItem::onBtnClick);

    VFX_OBJ_CREATE(m_btnTime, VcpButton, this);

    m_btnTime->setText(m_time); 
    m_btnTime->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
    m_btnTime->setId(VAPP_CAL_EDIT_DATETIME_BTN_TIME);
    m_btnTime->m_signalClicked.connect(this, &VappCalEditDateTimeItem::onBtnClick);
}


void VappCalEditDateTimeItem::changeDateLarge(VfxBool islarge)
{
    m_large = islarge;
    checkUpdate();
}


void VappCalEditDateTimeItem::onBtnClick(VfxObject* sender, VfxId id)
{
    m_signalButtonClicked.emit(this, (VappCalEditDateTimeItemButtonEnum)id);
}


void VappCalDatePickerPopup::onInit()
{
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);
    
    // title background
    VFX_OBJ_CREATE(m_titleBg, VfxFrame, this);        
    m_titleBg->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_TOP));
    m_titleBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_titleBg->setSize(VAPP_CAL_DATE_PICKER_POPUP_WIDTH, 
                    VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT);
    m_titleBg->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_BOTTOM));
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setIsCached(VFX_TRUE);
    m_background->setPos(0, VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT);
    m_background->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_titleFrame, VfxTextFrame, this);
    m_titleFrame->setString((VfxResId)STR_ID_VAPP_CAL_DATE_SETTING);
    m_titleFrame->setRect(VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_X, 
                        VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_Y, 
                        VAPP_CAL_DATE_PICKER_POPUP_TITLE_TEXT_WIDTH, 
                        VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT);
    m_titleFrame->setColor(VFX_COLOR_WHITE);
    m_titleFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_titleFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
   
    m_titleFrame->setFont(VfxFontDesc(
                    VAPP_CAL_DATE_PICKER_POPUP_TITLE_FONT, 
                    VFX_FONT_DESC_ATTR_NORMAL,
                    VFX_FE1_9));
    m_titleFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_titleFrame->setAutoAnimate(VFX_TRUE);

    // total height
    VfxS32 totalHeight = VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT  + VAPP_CAL_DATE_PICKER_POPUP_TD_GAP;

    //Date picker
    VFX_OBJ_CREATE(m_datePicker, VcpDatePicker, this);
    m_datePicker->setPos(VfxPoint(VAPP_CAL_DATE_PICKER_POPUP_LR_GAP, totalHeight));
    VcpDatePickerStruct date;
    date.year = VAPP_CAL_MIN_YEAR;
    date.month = 1;
    date.day = 1;
    m_datePicker->setMinDate(date);
    date.year = VAPP_CAL_MAX_YEAR;
    date.month = 12;
    date.day = 31;
    m_datePicker->setMaxDate(date);

    switch(srv_setting_get_date_format())
    {
    case SETTING_DATE_FORMAT_DD_MM_YYYY:
        m_datePicker->setFormat(VCP_DATE_PICKER_FORMAT_DDMMYYYY);
        break;
    case SETTING_DATE_FORMAT_MM_DD_YYYY:
        m_datePicker->setFormat(VCP_DATE_PICKER_FORMAT_MMDDYYYY);
        break;
    case SETTING_DATE_FORMAT_YYYY_MM_DD:
        m_datePicker->setFormat(VCP_DATE_PICKER_FORMAT_YYYYMMDD);
        break;
    default:
        break;
    }

    // total height
    totalHeight += m_datePicker->getBounds().getHeight();

    // draw line
    VfxImageFrame *seperator;
    VFX_OBJ_CREATE(seperator, VfxImageFrame, this);
    seperator->setResId(IMG_ID_VAPP_CAL_PICKER_SEPERATOR);
    seperator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    seperator->setPos(VAPP_CAL_DATE_PICKER_POPUP_LR_GAP, (totalHeight + VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP / 2 - 1));
    seperator->setSize(VAPP_CAL_DATE_PICKER_POPUP_WIDTH - 2 * VAPP_CAL_DATE_PICKER_POPUP_LR_GAP, 2);

    VFX_OBJ_CREATE(m_leftButton, VcpButton, this);
    VfxU16 buttonH = m_leftButton->getSize().height;
    m_leftButton->setText((VfxResId)STR_GLOBAL_OK);
    m_leftButton->setRect(VfxRect(
                            VAPP_CAL_DATE_PICKER_POPUP_LR_GAP, 
                            totalHeight + VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP,
                            VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH, 
                            buttonH));
    m_leftButton->m_signalClicked.connect(this, &VappCalDatePickerPopup::onButtonClick);
    m_leftButton->setTextColor(VfxColorResHelper(CLR_COSMOS_TEXT_MAIN));
    m_leftButton->setId(VAPP_CAL_DATE_PICKER_POPUP_BTN_LEFT);
    m_leftButton->setAutoAnimate(VFX_TRUE);


    VFX_OBJ_CREATE(m_rightButton, VcpButton, this);
    m_rightButton->setText((VfxResId)STR_GLOBAL_CANCEL);
    m_rightButton->setRect(VfxRect(
                            (VAPP_CAL_DATE_PICKER_POPUP_LR_GAP + 
                            VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH + 
                            VAPP_CAL_DATE_PICKER_POPUP_BUTTON_MID_GAP), 
                            totalHeight + VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP,
                            VAPP_CAL_DATE_PICKER_POPUP_BUTTON_WIDTH, 
                            buttonH));
    m_rightButton->m_signalClicked.connect(this, &VappCalDatePickerPopup::onButtonClick);
    m_rightButton->setTextColor(VfxColorResHelper(CLR_COSMOS_TEXT_MAIN));
    m_rightButton->setId(VAPP_CAL_DATE_PICKER_POPUP_BTN_RIGHT);
    m_rightButton->setAutoAnimate(VFX_TRUE);

    if (!m_usedByJumpToDate)
    {
        m_rightButton->setStyle(VCP_BUTTON_STYLE_GREY);
    }

    totalHeight += (buttonH + 
                    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_TOP_GAP + 
                    VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_GAP);

    totalHeight += VAPP_CAL_DATE_PICKER_POPUP_BUTTON_BOTTOM_SHADOW;

    m_background->setSize(VAPP_CAL_DATE_PICKER_POPUP_WIDTH, totalHeight - VAPP_CAL_DATE_PICKER_POPUP_TITLE_HEIGHT);

    setBounds(0, 0, VAPP_CAL_DATE_PICKER_POPUP_WIDTH, totalHeight);
}

VfxBool VappCalDatePickerPopup::onKeyInput(VfxKeyEvent & event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)	
    {
        leave(VFX_TRUE);
        return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}

void VappCalDatePickerPopup::setUsedByJumpToDate(void)
{
    m_titleFrame->setString((VfxResId)STR_ID_VAPP_CAL_JUMP_TO_DATE);
    
    m_leftButton->setText((VfxResId)STR_ID_VAPP_CAL_TODAY);
    
    m_rightButton->setText((VfxResId)STR_ID_VAPP_CAL_GO);
    
    checkUpdate(); 
}

void VappCalDatePickerPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    if (!m_usedByJumpToDate)
    {
        if (id == VAPP_CAL_DATE_PICKER_POPUP_BTN_LEFT && //btn OK
            m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            srv_tdl_event_struct *event = (srv_tdl_event_struct*)m_data;

            MYTIME temp;
            VcpDatePickerStruct pickerDate;

            pickerDate = m_datePicker->getDate();

            memset(&temp, 0, sizeof(MYTIME));
            temp.nYear = pickerDate.year;
            temp.nMonth = pickerDate.month;
            temp.nDay = pickerDate.day;
            
            if (m_pickerType == VAPP_CAL_DATETIIME_END)
            {
                temp.nHour = event->end_time.nHour;
                temp.nMin= event->end_time.nMin;
                
                //check validation
                if (VappCalEditPage::endTimeIsLessThanStartTime(&(event->start_time), &temp))
                {
                    displayErrorPopup();
                    return;
                }
            }
        }
        
    }
    
    m_signalButtonClicked.emit(this, (VappCalDatePickerPopupButtonEnum)id);
    leave(VFX_TRUE);
}


void VappCalDatePickerPopup::displayErrorPopup(void)
{
    VcpConfirmPopup *popup;

    VFX_OBJ_CREATE(popup, VcpConfirmPopup, m_parentPage);
    popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    popup->setText((VfxResId)STR_ID_VAPP_CAL_ENDTIME_CHECK_NOTE);
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setAutoDestory(VFX_TRUE);
    popup->show(VFX_TRUE);
}



void VappCalTimePickerPopup::onInit()
{
    VappCalDatePickerPopup::onInit();
    VFX_OBJ_CLOSE(m_datePicker);
    
    m_titleFrame->setString((VfxResId)STR_ID_VAPP_CAL_TIME_SETTING);

    VFX_OBJ_CREATE(m_timePicker, VcpTimePicker, this);
    m_timePicker->setPos(VfxPoint(VAPP_CAL_TIME_PICKER_POPUP_LR_GAP,  VAPP_CAL_TIME_PICKER_POPUP_TITLE_HEIGHT +  VAPP_CAL_TIME_PICKER_POPUP_TD_GAP));
    if (srv_setting_get_time_format() == SETTING_TIME_FORMAT_24_HOURS)
    {
        m_timePicker->setIs24HourView(VFX_TRUE);
    }
    m_leftButton->m_signalClicked.connect(this, &VappCalTimePickerPopup::onButtonClick);
    m_rightButton->m_signalClicked.connect(this, &VappCalTimePickerPopup::onButtonClick);
}

void VappCalTimePickerPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    if (id == VAPP_CAL_TIME_PICKER_POPUP_BTN_LEFT && //btn OK
        m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_struct *event = (srv_tdl_event_struct*)m_data;

        MYTIME temp;
        VcpTimePickerStruct pickerTime;

        pickerTime = m_timePicker->getTime();

        memset(&temp, 0, sizeof(MYTIME));
        temp.nHour = pickerTime.hour;
        temp.nMin = pickerTime.minute;

        if (m_pickerType == VAPP_CAL_DATETIIME_END)
        {
            temp.nYear= event->end_time.nYear;
            temp.nMonth = event->end_time.nMonth;
            temp.nDay = event->end_time.nDay;
                
            //check validation
            if (VappCalEditPage::endTimeIsLessThanStartTime(&(event->start_time), &temp))
            {
                displayErrorPopup();
                return;
            }
        }
    }
    
    m_signalButtonClicked.emit(this, (VappCalDatePickerPopupButtonEnum)id);
    leave(VFX_TRUE);
}
#ifndef __MMI_VCALENDAR__
#pragma arm section code, rodata
#endif
