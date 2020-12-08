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
 *  vsrv_network.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "GUI/vadp_p2v_theme_info.h"
#include "gui_data_types.h"
#include "CustThemesRes.h"

#include "vfx_object.h"
#include "vfx_basic_type.h"

#define UI_FILLED_AREA_TYPE_COLOR                           0x00000000
#define UI_FILLED_AREA_TYPE_GRADIENT_COLOR                  0x00000001
#define UI_FILLED_AREA_TYPE_TEXTURE                         0x00000002
#define UI_FILLED_AREA_TYPE_BITMAP                          0x00000003

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/*
 * Porting Plutommi to Venus UI
 */ 
#ifdef __cplusplus
extern "C"
{
#endif
extern MMI_theme *current_MMI_theme;
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Global function
 *****************************************************************************/

VadpTheme::VadpTheme()
{   
    
}

void VadpTheme::onInit()
{
    
    VfxObject::onInit();
}


void VadpTheme::onDeinit()
{
    
    VfxObject::onDeinit();
}


void VadpTheme::GetColor(vadp_theme_color_enum theme_content, VfxColor* color)
{

    switch(theme_content)
    {
    case LSK_UP_TEXT_COLOR:
        *color = VfxColor(
            current_MMI_theme->LSK_up_text_color->alpha, 
            current_MMI_theme->LSK_up_text_color->r,
            current_MMI_theme->LSK_up_text_color->g,
            current_MMI_theme->LSK_up_text_color->b);
    case LSK_DOWN_TEXT_COLOR:
        *color = VfxColor(
            current_MMI_theme->LSK_down_text_color->alpha, 
            current_MMI_theme->LSK_down_text_color->r,
            current_MMI_theme->LSK_down_text_color->g,
            current_MMI_theme->LSK_down_text_color->b);
    case RSK_UP_TEXT_COLOR:
        *color = VfxColor(
            current_MMI_theme->LSK_up_text_color->alpha, 
            current_MMI_theme->LSK_up_text_color->r,
            current_MMI_theme->LSK_up_text_color->g,
            current_MMI_theme->LSK_up_text_color->b);
    case RSK_DOWN_TEXT_COLOR:
        *color = VfxColor(
            current_MMI_theme->LSK_down_text_color->alpha, 
            current_MMI_theme->LSK_down_text_color->r,
            current_MMI_theme->LSK_down_text_color->g,
            current_MMI_theme->LSK_down_text_color->b);
    case SOFTKEY_TEXT_BORDER_COLOR: 
        *color = VfxColor(
            current_MMI_theme->softkey_text_border_color->alpha, 
            current_MMI_theme->softkey_text_border_color->r,
            current_MMI_theme->softkey_text_border_color->g,
            current_MMI_theme->softkey_text_border_color->b);
    }
}

UI_filled_area* VadpTheme::GetFiller(vadp_theme_filler_enum theme_content)
{ 
    switch(theme_content)
    {
    case IDLE_BKG_FILLER:
        return current_MMI_theme->idle_bkg_filler;
    case MAIN_MENU_BKG_FILLER:
        return current_MMI_theme->main_menu_bkg_filler;
    case SUB_MENU_BKG_FILLER:
        return current_MMI_theme->sub_menu_bkg_filler;
    case SOFTKEY_BAR_BKG_FILLER:
        return current_MMI_theme->softkey_bar_bkg_filler;
    case STATUS_BAR_BKG_FILLER: 
        return current_MMI_theme->status_icon_bar_filler;
    default:
        return NULL;
    }
    return NULL;
}
