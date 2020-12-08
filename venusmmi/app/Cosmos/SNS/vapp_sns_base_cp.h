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
 *   vapp_sns_main.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements Sns class declaration.
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
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#ifndef __VAPP_SNS_BASE_CP_H__
#define __VAPP_SNS_BASE_CP_H__
 
#include "MMI_features.h"

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "MMIDataType.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_var_height_menu.h"
#include "vcp_photo_border_frame.h"
#include "vcp_async_image_frame.h"
#include "vcp_image_button.h"

//#include "SnsTypes.h"
#ifdef __cplusplus
extern "C"
#endif
{
    #include "SnsSrvTypes.h"
    #include "Gdi_const.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define VAPP_SNS_MAIN_FONT_COLOR            VFX_COLOR_RES(CLR_ID_VAPP_SNS_MAIN_TEXT)
#define VAPP_SNS_MAIN_FONT_COLOR_DISABLED   VFX_COLOR_RES(CLR_ID_VAPP_SNS_MAIN_TEXT_DISABLED)
#define VAPP_SNS_HINT_TEXT_COLOR            VFX_COLOR_RES(CLR_ID_VAPP_SNS_HINT_TEXT)
#define VAPP_SNS_HINT_TEXT_COLOR_DISABLED   VFX_COLOR_RES(CLR_ID_VAPP_SNS_HINT_TEXT_DISABLED)
#define VAPP_SNS_MAIN_FONT_HIGHLIGHT_COLOR  VFX_COLOR_RES(CLR_ID_VAPP_SNS_MAIN_TEXT_HIGHLIGHT)

#define VAPP_SNS_IMAGE_BG_COLOR             VFX_COLOR_RES(CLR_ID_VAPP_SNS_IMAGE_BG)
#define VAPP_SNS_IMAGE_BORDER_COLOR         VFX_COLOR_RES(CLR_ID_VAPP_SNS_IMAGE_BORDER)
#endif 

#define VAPP_SNS_ITEM_LANCHER_CELL_MAX_ID_NUM 5
#define VAPP_SNS_ITEM_LANCHER_CELL_MAX_TITLE_IMAGE_NUM 3

typedef struct vapp_sns_id_list {
    VfxU32 key;
    VfxChar *value;
} vapp_sns_id_list_struct; 

typedef struct vapp_sns_image_list {
    vapp_sns_id_list_struct id;
    VfxWString filename;
    VfxBool tappable;
} vapp_sns_image_list_struct; 


// Cell status
enum VappSnsRequestCellStatus {
    VAPP_SNS_REQUEST_CELL_STATUS_NONE = 0,
    VAPP_SNS_REQUEST_CELL_STATUS_FOCUSED,
    VAPP_SNS_REQUEST_CELL_STATUS_ACCEPTING,
    VAPP_SNS_REQUEST_CELL_STATUS_ACCEPTED,
    VAPP_SNS_REQUEST_CELL_STATUS_REJECTING,
    VAPP_SNS_REQUEST_CELL_STATUS_REJECTED,
    VAPP_SNS_REQUEST_CELL_STATUS_FAILED,
};

// Indicate the font size
enum VappSnsFontSize {

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    VAPP_SNS_FONT_SIZE_PROFILE_TITLE    = 18,
    VAPP_SNS_FONT_SIZE_PROFILE_MAINTEXT = 13,
    VAPP_SNS_FONT_SIZE_TITLE            = 18,
    VAPP_SNS_FONT_SIZE_MAINTEXT         = 13,
    VAPP_SNS_FONT_SIZE_HINT             = 13,

#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_400X240__)
    VAPP_SNS_FONT_SIZE_PROFILE_TITLE    = 18,
    VAPP_SNS_FONT_SIZE_PROFILE_MAINTEXT = 13,
    VAPP_SNS_FONT_SIZE_TITLE            = 18,
    VAPP_SNS_FONT_SIZE_MAINTEXT         = 13,
    VAPP_SNS_FONT_SIZE_HINT             = 13,

#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X320__)
    VAPP_SNS_FONT_SIZE_PROFILE_TITLE    = 20,
    VAPP_SNS_FONT_SIZE_PROFILE_MAINTEXT = 14,
    VAPP_SNS_FONT_SIZE_TITLE            = 20,
    VAPP_SNS_FONT_SIZE_MAINTEXT         = 14,
    VAPP_SNS_FONT_SIZE_HINT             = 14,
#elif defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_800X480__)
    VAPP_SNS_FONT_SIZE_PROFILE_TITLE    = 36,
    VAPP_SNS_FONT_SIZE_PROFILE_MAINTEXT = 26,
    VAPP_SNS_FONT_SIZE_TITLE            = 30,
    VAPP_SNS_FONT_SIZE_MAINTEXT         = 21,
    VAPP_SNS_FONT_SIZE_HINT             = 18,
#endif
};

// Indicate item layout
enum VappSnsItemLayout {
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
    VAPP_SNS_ITEM_LEFT_MARGIN           = 5, 
    VAPP_SNS_ITEM_UP_MARGIN             = 8, 
    VAPP_SNS_ITEM_RIGHT_MARGIN          = 5, 
    VAPP_SNS_ITEM_DOWN_MARGIN           = 8, 
    VAPP_SNS_ITEM_MAX_HEIGHT            = 130, 

    /* Refresh button */
    VAPP_SNS_ITEM_REFRESHCELL_HEIGHT    = 48,
    VAPP_SNS_ITEM_BUTTON_MARGIN         = 5,
    VAPP_SNS_ITEM_BUTTON_MIN_WIDTH      = 38,

    /* Launcher cell size */
    VAPP_SNS_ITEM_STD_MARGIN            = 5,
    VAPP_SNS_ITEM_TITLE_CONTENT_MARGIN  = 1,
    VAPP_SNS_ITEM_CONTENT_IMAGE_MARGIN  = 3,
    VAPP_SNS_ITEM_CENTRAL_MARGIN        = 5,
    VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH     = 45,
    VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT    = 45,
    VAPP_SNS_ITEM_TITLE_IMAGE_BORDER    = 4,
    VAPP_SNS_ITEM_TITLE_WIDTH           = 160,
    VAPP_SNS_ITEM_TITLE_HEIGHT          = 20,
    VAPP_SNS_ITEM_CONTENT_WIDTH         = (LCD_WIDTH - VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH - VAPP_SNS_ITEM_STD_MARGIN * 2 - VAPP_SNS_ITEM_CENTRAL_MARGIN),
    VAPP_SNS_ITEM_CONTENT_HEIGHT        = 0,
    VAPP_SNS_ITEM_CONTENT_MAX_LINES     = 20,
    VAPP_SNS_ITEM_DATE_WIDTH            = 60,
    VAPP_SNS_ITEM_DATE_HEIGHT           = 15,
    VAPP_SNS_ITEM_HINT_WIDTH            = 160,
    VAPP_SNS_ITEM_HINT_HEIGHT           = 15,
    VAPP_SNS_ITEM_CONTENT_IMAGE_WIDTH   = 75,
    VAPP_SNS_ITEM_CONTENT_IMAGE_HEIGHT  = 48,
    VAPP_SNS_ITEM_ICON_WIDTH            = 20,
    VAPP_SNS_ITEM_ICON_HEIGHT           = 20,
    VAPP_SNS_ITEM_BUTTON_WIDTH          = 35,
    VAPP_SNS_ITEM_BUTTON_HEIGHT         = 35,

    /* Text view layout */
    VAPP_SNS_ITEM_TEXT_VIEW_IMAGE_WIDTH  = 120,
    VAPP_SNS_ITEM_TEXT_VIEW_IMAGE_HEIGHT = 90,

    /* Launch cell min height */
    VAPP_SNS_ITEM_LAUNCHER_CELL_MIN_H   = VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH + VAPP_SNS_ITEM_STD_MARGIN * 2,

    /* Caption item layout */
    VAPP_SNS_ITEM_CAPTION_ICON_POS_X    = 40,
    VAPP_SNS_ITEM_CAPTION_ICON_POS_Y    = (VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT - VAPP_SNS_ITEM_ICON_HEIGHT),
    VAPP_SNS_ITEM_CAPTION_REFRESH_W     = 24,
    VAPP_SNS_ITEM_CAPTION_REFRESH_H     = 24,  
    VAPP_SNS_ITEM_CAPTION_HEIGHT        = (VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT + VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_DOWN_MARGIN),

    /* View more button layout */
    VAPP_SNS_ITEM_VIEW_MORE_WIDTH       = GDI_LCD_WIDTH, 
    VAPP_SNS_ITEM_VIEW_MORE_HEIGHT      = 20 + VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_DOWN_MARGIN, 

    /* VappSnsFormItemNameCp layout */
    VAPP_SNS_FORM_ITEM_IMAGE_WIDTH      = 66,
    VAPP_SNS_FORM_ITEM_IMAGE_HEIGHT     = 66,

    /* VappSnsEditorPage layout */
    VAPP_SNS_EDITOR_PAGE_TOP_MARGIN     = 4,
    VAPP_SNS_EDITOR_PAGE_BUTTON_MARGIN  = 8,
    VAPP_SNS_EDITOR_PAGE_EDITOR_MIN_H   = 32,     

    /* VappSnsAcctSelButton layout */
    VAPP_SNS_ACCT_SEL_BUTTON_WIDTH      = LCD_WIDTH - VAPP_SNS_ITEM_LEFT_MARGIN - VAPP_SNS_ITEM_LEFT_MARGIN,
    VAPP_SNS_ACCT_SEL_BUTTON_HEIGHT     = 35,

    VAPP_SNS_ITEM_REQUEST_STATUS_HEIGHT = 45,

    /* Account setting text and button size */
    VAPP_SNS_ACCT_SETTING_MARGIN        = 13,

    
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_400X240__)
    VAPP_SNS_ITEM_LEFT_MARGIN           = 5, 
    VAPP_SNS_ITEM_UP_MARGIN             = 8, 
    VAPP_SNS_ITEM_RIGHT_MARGIN          = 5, 
    VAPP_SNS_ITEM_DOWN_MARGIN           = 8, 
    VAPP_SNS_ITEM_MAX_HEIGHT            = 210, 

    /* Refresh button */
    VAPP_SNS_ITEM_REFRESHCELL_HEIGHT    = 48,
    VAPP_SNS_ITEM_BUTTON_MARGIN         = 5,
    VAPP_SNS_ITEM_BUTTON_MIN_WIDTH      = 38,

    /* Launcher cell size */
    VAPP_SNS_ITEM_STD_MARGIN            = 5,
    VAPP_SNS_ITEM_TITLE_CONTENT_MARGIN  = 1,
    VAPP_SNS_ITEM_CONTENT_IMAGE_MARGIN  = 3,
    VAPP_SNS_ITEM_CENTRAL_MARGIN        = 5,
    VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH     = 45,
    VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT    = 45,
    VAPP_SNS_ITEM_TITLE_IMAGE_BORDER    = 4,
    VAPP_SNS_ITEM_TITLE_WIDTH           = 160,
    VAPP_SNS_ITEM_TITLE_HEIGHT          = 20,
    VAPP_SNS_ITEM_CONTENT_WIDTH         = (LCD_WIDTH - VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH - VAPP_SNS_ITEM_STD_MARGIN * 2 - VAPP_SNS_ITEM_CENTRAL_MARGIN),
    VAPP_SNS_ITEM_CONTENT_HEIGHT        = 0,
    VAPP_SNS_ITEM_CONTENT_MAX_LINES     = 20,
    VAPP_SNS_ITEM_DATE_WIDTH            = 60,
    VAPP_SNS_ITEM_DATE_HEIGHT           = 15,
    VAPP_SNS_ITEM_HINT_WIDTH            = 160,
    VAPP_SNS_ITEM_HINT_HEIGHT           = 15,
    VAPP_SNS_ITEM_CONTENT_IMAGE_WIDTH   = 75,
    VAPP_SNS_ITEM_CONTENT_IMAGE_HEIGHT  = 48,
    VAPP_SNS_ITEM_ICON_WIDTH            = 20,
    VAPP_SNS_ITEM_ICON_HEIGHT           = 20,
    VAPP_SNS_ITEM_BUTTON_WIDTH          = 35,
    VAPP_SNS_ITEM_BUTTON_HEIGHT         = 35,
    
    /* Text view layout */
    VAPP_SNS_ITEM_TEXT_VIEW_IMAGE_WIDTH  = 120,
    VAPP_SNS_ITEM_TEXT_VIEW_IMAGE_HEIGHT = 90,

    /* Launch cell min height */
    VAPP_SNS_ITEM_LAUNCHER_CELL_MIN_H   = VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH + VAPP_SNS_ITEM_STD_MARGIN * 2,

    /* Caption item layout */
    VAPP_SNS_ITEM_CAPTION_ICON_POS_X    = 40,
    VAPP_SNS_ITEM_CAPTION_ICON_POS_Y    = (VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT - VAPP_SNS_ITEM_ICON_HEIGHT),
    VAPP_SNS_ITEM_CAPTION_REFRESH_W     = 24,
    VAPP_SNS_ITEM_CAPTION_REFRESH_H     = 24,  
    VAPP_SNS_ITEM_CAPTION_HEIGHT        = (VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT + VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_DOWN_MARGIN),

    /* View more button layout */
    VAPP_SNS_ITEM_VIEW_MORE_WIDTH       = GDI_LCD_WIDTH, 
    VAPP_SNS_ITEM_VIEW_MORE_HEIGHT      = 20 + VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_DOWN_MARGIN, 

    /* VappSnsFormItemNameCp layout */
    VAPP_SNS_FORM_ITEM_IMAGE_WIDTH      = 66,
    VAPP_SNS_FORM_ITEM_IMAGE_HEIGHT     = 66,

    /* VappSnsEditorPage layout */
    VAPP_SNS_EDITOR_PAGE_TOP_MARGIN     = 4,
    VAPP_SNS_EDITOR_PAGE_BUTTON_MARGIN  = 8,
    VAPP_SNS_EDITOR_PAGE_EDITOR_MIN_H   = 32,    

    /* VappSnsAcctSelButton layout */
    VAPP_SNS_ACCT_SEL_BUTTON_WIDTH      = LCD_WIDTH - VAPP_SNS_ITEM_LEFT_MARGIN - VAPP_SNS_ITEM_LEFT_MARGIN,
    VAPP_SNS_ACCT_SEL_BUTTON_HEIGHT     = 35,

    VAPP_SNS_ITEM_REQUEST_STATUS_HEIGHT = 45,
    
    /* Account setting text and button size */
    VAPP_SNS_ACCT_SETTING_MARGIN        = 18,    
    
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X320__)
    VAPP_SNS_ITEM_LEFT_MARGIN           = 8, 
    VAPP_SNS_ITEM_UP_MARGIN             = 8, 
    VAPP_SNS_ITEM_RIGHT_MARGIN          = 8, 
    VAPP_SNS_ITEM_DOWN_MARGIN           = 8, 
    VAPP_SNS_ITEM_MAX_HEIGHT            = 261, 

    /* Refresh button */
    VAPP_SNS_ITEM_REFRESHCELL_HEIGHT    = 68,
    VAPP_SNS_ITEM_BUTTON_MARGIN         = 5,
    VAPP_SNS_ITEM_BUTTON_MIN_WIDTH      = 58,

    /* Launcher cell size */
    VAPP_SNS_ITEM_STD_MARGIN            = 8,
    VAPP_SNS_ITEM_TITLE_CONTENT_MARGIN  = 1,
    VAPP_SNS_ITEM_CONTENT_IMAGE_MARGIN  = 3,
    VAPP_SNS_ITEM_CENTRAL_MARGIN        = 8,
    VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH     = 45,
    VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT    = 45,
    VAPP_SNS_ITEM_TITLE_IMAGE_BORDER    = 4,
    VAPP_SNS_ITEM_TITLE_WIDTH           = 180,
    VAPP_SNS_ITEM_TITLE_HEIGHT          = 20,
    VAPP_SNS_ITEM_CONTENT_WIDTH         = (LCD_WIDTH - VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH - VAPP_SNS_ITEM_STD_MARGIN * 2 - VAPP_SNS_ITEM_CENTRAL_MARGIN),
    VAPP_SNS_ITEM_CONTENT_HEIGHT        = 0,
    VAPP_SNS_ITEM_CONTENT_MAX_LINES     = 20,
    VAPP_SNS_ITEM_DATE_WIDTH            = 70,
    VAPP_SNS_ITEM_DATE_HEIGHT           = 20,
    VAPP_SNS_ITEM_HINT_WIDTH            = 180,
    VAPP_SNS_ITEM_HINT_HEIGHT           = 20,
    VAPP_SNS_ITEM_CONTENT_IMAGE_WIDTH   = 110,
    VAPP_SNS_ITEM_CONTENT_IMAGE_HEIGHT  = 70,
    VAPP_SNS_ITEM_ICON_WIDTH            = 20,
    VAPP_SNS_ITEM_ICON_HEIGHT           = 20,
    VAPP_SNS_ITEM_BUTTON_WIDTH          = 45,
    VAPP_SNS_ITEM_BUTTON_HEIGHT         = 45,

    /* Text view layout */
    VAPP_SNS_ITEM_TEXT_VIEW_IMAGE_WIDTH  = 150,
    VAPP_SNS_ITEM_TEXT_VIEW_IMAGE_HEIGHT = 120,

    /* Launch cell min height */
    VAPP_SNS_ITEM_LAUNCHER_CELL_MIN_H   = VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH + VAPP_SNS_ITEM_STD_MARGIN * 2,

    /* Caption item layout */    
    VAPP_SNS_ITEM_CAPTION_ICON_POS_X    = 43,
    VAPP_SNS_ITEM_CAPTION_ICON_POS_Y    = (VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT - VAPP_SNS_ITEM_ICON_HEIGHT),
    VAPP_SNS_ITEM_CAPTION_REFRESH_W     = 35,
    VAPP_SNS_ITEM_CAPTION_REFRESH_H     = 35,  
    VAPP_SNS_ITEM_CAPTION_HEIGHT        = (VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT + VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_DOWN_MARGIN),

    /* View more button layout */
    VAPP_SNS_ITEM_VIEW_MORE_WIDTH       = GDI_LCD_WIDTH, 
    VAPP_SNS_ITEM_VIEW_MORE_HEIGHT      = 20 + VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_DOWN_MARGIN, 

    /* VappSnsFormItemNameCp layout */
    VAPP_SNS_FORM_ITEM_IMAGE_WIDTH      = 66,
    VAPP_SNS_FORM_ITEM_IMAGE_HEIGHT     = 66,

    /* VappSnsEditorPage layout */
    VAPP_SNS_EDITOR_PAGE_TOP_MARGIN     = 4,
    VAPP_SNS_EDITOR_PAGE_BUTTON_MARGIN  = 14,
    VAPP_SNS_EDITOR_PAGE_EDITOR_MIN_H   = 36,    

    /* VappSnsAcctSelButton layout */
    VAPP_SNS_ACCT_SEL_BUTTON_WIDTH      = LCD_WIDTH - VAPP_SNS_ITEM_LEFT_MARGIN - VAPP_SNS_ITEM_LEFT_MARGIN,
    VAPP_SNS_ACCT_SEL_BUTTON_HEIGHT     = 54,

    VAPP_SNS_ITEM_REQUEST_STATUS_HEIGHT = 40,

    /* Account setting text and button size */
    VAPP_SNS_ACCT_SETTING_MARGIN        = 20,  

#elif defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_800X480__)
    VAPP_SNS_ITEM_LEFT_MARGIN           = 14, 
    VAPP_SNS_ITEM_UP_MARGIN             = 14, 
    VAPP_SNS_ITEM_RIGHT_MARGIN          = 14, 
    VAPP_SNS_ITEM_DOWN_MARGIN           = 14, 
    VAPP_SNS_ITEM_MAX_HEIGHT            = 436, 

    /* Refresh button */
    VAPP_SNS_ITEM_REFRESHCELL_HEIGHT    = 68,
    VAPP_SNS_ITEM_BUTTON_MARGIN         = 5,
    VAPP_SNS_ITEM_BUTTON_MIN_WIDTH      = 60,

    /* Launcher cell size */
    VAPP_SNS_ITEM_STD_MARGIN            = 14,
    VAPP_SNS_ITEM_TITLE_CONTENT_MARGIN  = 2,
    VAPP_SNS_ITEM_CONTENT_IMAGE_MARGIN  = 5,
    VAPP_SNS_ITEM_CENTRAL_MARGIN        = 16,
    VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH     = 60,
    VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT    = 60,
    VAPP_SNS_ITEM_TITLE_IMAGE_BORDER    = 4,
    VAPP_SNS_ITEM_TITLE_WIDTH           = 250,
    VAPP_SNS_ITEM_TITLE_HEIGHT          = 30,
    VAPP_SNS_ITEM_CONTENT_WIDTH         = (LCD_WIDTH - VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH - VAPP_SNS_ITEM_STD_MARGIN * 2 - VAPP_SNS_ITEM_CENTRAL_MARGIN),
    VAPP_SNS_ITEM_CONTENT_HEIGHT        = 0,
    VAPP_SNS_ITEM_CONTENT_MAX_LINES     = 20,
    VAPP_SNS_ITEM_DATE_WIDTH            = 80,
    VAPP_SNS_ITEM_DATE_HEIGHT           = 20,
    VAPP_SNS_ITEM_HINT_WIDTH            = 250,
    VAPP_SNS_ITEM_HINT_HEIGHT           = 20,
    VAPP_SNS_ITEM_CONTENT_IMAGE_WIDTH   = 120,
    VAPP_SNS_ITEM_CONTENT_IMAGE_HEIGHT  = 80,
    VAPP_SNS_ITEM_ICON_WIDTH            = 32,
    VAPP_SNS_ITEM_ICON_HEIGHT           = 32,
    VAPP_SNS_ITEM_BUTTON_WIDTH          = 45,
    VAPP_SNS_ITEM_BUTTON_HEIGHT         = 45,

    /* Text view layout */
    VAPP_SNS_ITEM_TEXT_VIEW_IMAGE_WIDTH  = 200,
    VAPP_SNS_ITEM_TEXT_VIEW_IMAGE_HEIGHT = 150,
    
    /* Launch cell min height */
    VAPP_SNS_ITEM_LAUNCHER_CELL_MIN_H   = VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH + VAPP_SNS_ITEM_STD_MARGIN * 2,

    /* Caption item layout */
    VAPP_SNS_ITEM_CAPTION_ICON_POS_X    = 58,
    VAPP_SNS_ITEM_CAPTION_ICON_POS_Y    = (VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT - VAPP_SNS_ITEM_ICON_HEIGHT),
    VAPP_SNS_ITEM_CAPTION_REFRESH_W     = 45,
    VAPP_SNS_ITEM_CAPTION_REFRESH_H     = 45,  
    VAPP_SNS_ITEM_CAPTION_HEIGHT        = (VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT + VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_DOWN_MARGIN),

    /* View more button layout */
    VAPP_SNS_ITEM_VIEW_MORE_WIDTH       = GDI_LCD_WIDTH, 
    VAPP_SNS_ITEM_VIEW_MORE_HEIGHT      = 30 + VAPP_SNS_ITEM_UP_MARGIN + VAPP_SNS_ITEM_DOWN_MARGIN, 

    /* VappSnsFormItemNameCp layout */
    VAPP_SNS_FORM_ITEM_IMAGE_WIDTH      = 116,
    VAPP_SNS_FORM_ITEM_IMAGE_HEIGHT     = 116,

    /* VappSnsEditorPage layout */
    VAPP_SNS_EDITOR_PAGE_TOP_MARGIN     = 8,
    VAPP_SNS_EDITOR_PAGE_BUTTON_MARGIN  = 26,
    VAPP_SNS_EDITOR_PAGE_EDITOR_MIN_H   = 60,   

    /* VappSnsAcctSelButton layout */
    VAPP_SNS_ACCT_SEL_BUTTON_WIDTH      = LCD_WIDTH - VAPP_SNS_ITEM_LEFT_MARGIN - VAPP_SNS_ITEM_LEFT_MARGIN,
    VAPP_SNS_ACCT_SEL_BUTTON_HEIGHT     = 70,

    VAPP_SNS_ITEM_REQUEST_STATUS_HEIGHT = 60,

    /* Account setting text and button size */
    VAPP_SNS_ACCT_SETTING_MARGIN        = 20,  

#endif

    VAPP_SNS_ITEM_LANCHERCELL_HEIGHT    = (VAPP_SNS_ITEM_TITLE_HEIGHT + 
                                            VAPP_SNS_ITEM_CONTENT_HEIGHT + 
                                            VAPP_SNS_ITEM_STD_MARGIN * 2),
                                            
    VAPP_SNS_ITEM_LANCHERCELL_H_W_IMAGE = (VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT + 
                                            VAPP_SNS_ITEM_STD_MARGIN * 2),

    VAPP_SNS_ITEM_LANCHERCELLEX_HEIGHT  = (VAPP_SNS_ITEM_TITLE_HEIGHT + 
                                            VAPP_SNS_ITEM_CONTENT_HEIGHT + 
                                            VAPP_SNS_ITEM_CONTENT_IMAGE_HEIGHT +
                                            VAPP_SNS_ITEM_STD_MARGIN * 3),

    VAPP_SNS_ITEM_TEXTVIEWCELL_HEIGHT   = 90
};

/* VappSnsMsgSender */
enum VappSnsMsgSenderLayout {
#if defined(__MMI_MAINLCD_320X480__) /* HVGA */
    /* size */
    VAPP_SNS_MSG_SENDER_LEFT_MARGIN     = (8), 
    VAPP_SNS_MSG_SENDER_UP_MARGIN       = (8), 
    VAPP_SNS_MSG_SENDER_RIGHT_MARGIN    = (8), 
    VAPP_SNS_MSG_SENDER_DOWN_MARGIN     = (5), 
    VAPP_SNS_MSG_SENDER_INTERNAL_MARGIN = (5), 
    // -- button
    VAPP_SNS_MSG_SENDER_BUTTON_WIDTH    = (80), 
    VAPP_SNS_MSG_SENDER_BUTTON_HEIGHT   = (39), 
#elif defined(__MMI_MAINLCD_480X800__) /* WVGA */
    /* size */
    VAPP_SNS_MSG_SENDER_LEFT_MARGIN     = (14), 
    VAPP_SNS_MSG_SENDER_UP_MARGIN       = (10), 
    VAPP_SNS_MSG_SENDER_RIGHT_MARGIN    = (9), 
    VAPP_SNS_MSG_SENDER_DOWN_MARGIN     = (10), 
    VAPP_SNS_MSG_SENDER_INTERNAL_MARGIN = (10), 
    // -- button
    VAPP_SNS_MSG_SENDER_BUTTON_WIDTH    = (116), 
    VAPP_SNS_MSG_SENDER_BUTTON_HEIGHT   = (68), 
#elif defined(__MMI_MAINLCD_240X320__) /* QVGA */
    /* size */
    VAPP_SNS_MSG_SENDER_LEFT_MARGIN     = (5), 
    VAPP_SNS_MSG_SENDER_UP_MARGIN       = (5), 
    VAPP_SNS_MSG_SENDER_RIGHT_MARGIN    = (5), 
    VAPP_SNS_MSG_SENDER_DOWN_MARGIN     = (4), 
    VAPP_SNS_MSG_SENDER_INTERNAL_MARGIN = (5), 
    // -- button
    VAPP_SNS_MSG_SENDER_BUTTON_WIDTH    = (60), 
    VAPP_SNS_MSG_SENDER_BUTTON_HEIGHT   = (36), 
#elif defined(__MMI_MAINLCD_240X400__) /* WQVGA */
    /* size */
    VAPP_SNS_MSG_SENDER_LEFT_MARGIN     = (5), 
    VAPP_SNS_MSG_SENDER_UP_MARGIN       = (5), 
    VAPP_SNS_MSG_SENDER_RIGHT_MARGIN    = (5), 
    VAPP_SNS_MSG_SENDER_DOWN_MARGIN     = (4), 
    VAPP_SNS_MSG_SENDER_INTERNAL_MARGIN = (5), 
    // -- button
    VAPP_SNS_MSG_SENDER_BUTTON_WIDTH    = (60), 
    VAPP_SNS_MSG_SENDER_BUTTON_HEIGHT   = (36),
#else
    /* size */
    VAPP_SNS_MSG_SENDER_LEFT_MARGIN     = (8), 
    VAPP_SNS_MSG_SENDER_UP_MARGIN       = (8), 
    VAPP_SNS_MSG_SENDER_RIGHT_MARGIN    = (8), 
    VAPP_SNS_MSG_SENDER_DOWN_MARGIN     = (5), 
    VAPP_SNS_MSG_SENDER_INTERNAL_MARGIN = (5), 
    // -- button
    VAPP_SNS_MSG_SENDER_BUTTON_WIDTH    = (80), 
    VAPP_SNS_MSG_SENDER_BUTTON_HEIGHT   = (39), 
#endif /* __MMI_MAINLCD_?X?__ */
    // -- editor
    VAPP_SNS_MSG_SENDER_EDITOR_WIDTH            = (GDI_LCD_WIDTH - VAPP_SNS_MSG_SENDER_LEFT_MARGIN - VAPP_SNS_MSG_SENDER_RIGHT_MARGIN - VAPP_SNS_MSG_SENDER_INTERNAL_MARGIN - VAPP_SNS_MSG_SENDER_BUTTON_WIDTH), 
    VAPP_SNS_MSG_SENDER_EDITOR_MIN_HEIGHT       = (VAPP_SNS_MSG_SENDER_BUTTON_HEIGHT), 
    VAPP_SNS_MSG_SENDER_EDITOR_MAX_PERCENTAGE   = (2), 
    VAPP_SNS_MSG_SENDER_EDITOR_MAX_HEIGHT       = (VAPP_SNS_MSG_SENDER_EDITOR_MIN_HEIGHT * VAPP_SNS_MSG_SENDER_EDITOR_MAX_PERCENTAGE), 
    // -- whole component
    VAPP_SNS_MSG_SENDER_WIDTH   = (GDI_LCD_WIDTH), 
    VAPP_SNS_MSG_SENDER_HEIGHT  = (VAPP_SNS_MSG_SENDER_UP_MARGIN + VAPP_SNS_MSG_SENDER_EDITOR_MIN_HEIGHT + VAPP_SNS_MSG_SENDER_DOWN_MARGIN), 
    /* position */
    // -- button
    VAPP_SNS_MSG_SENDER_BUTTON_X = (GDI_LCD_WIDTH - VAPP_SNS_MSG_SENDER_RIGHT_MARGIN - VAPP_SNS_MSG_SENDER_BUTTON_WIDTH), 
    VAPP_SNS_MSG_SENDER_BUTTON_Y = (VAPP_SNS_MSG_SENDER_UP_MARGIN), 
    // -- editor
    VAPP_SNS_MSG_SENDER_EDITOR_X = (VAPP_SNS_MSG_SENDER_LEFT_MARGIN), 
    VAPP_SNS_MSG_SENDER_EDITOR_Y = (VAPP_SNS_MSG_SENDER_UP_MARGIN)
};

/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
class IVappSnsListContentProvider;

// IVappSnsListContentProvider class declaration
class IVappSnsListContentProvider
{
// Overridable
public:
    // Get list item
    virtual VfxFrame *getItem(VfxS32 group, VfxS32 index) = 0;

    // Get list count
    virtual VfxU32 getCount() = 0;

    // Get cell  is hittable or not
    virtual VfxBool getCellIsDisabled(VfxS32 index) = 0;

    // Get empty text
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) = 0;
    
};

// VappSnsListCp class declaration
class VappSnsListCp : public VcpVarHeightMenu
{
    VFX_DECLARE_CLASS(VappSnsListCp);

// Constructor / Descturctor
public:
    // Default constructor
    VappSnsListCp(VcpVarHeightMenu::VcpVarHeightMenuLayoutType type = VcpVarHeightMenu::LAYOUT_NORMAL);

// Protected
protected:
    virtual void onInit();

    virtual void onDeinit();

// Overridable
protected:
    // Create list cell 
    virtual VfxFrame *createCell(
        VfxS32 group, 
        VfxS32 pos
    );

    // Get list cell count
    virtual VfxU32 getCount();

    // Get item height
    virtual VfxU32 getItemHeight(
        VfxU32 index      // [IN] The index of the item
    );

    // Show text when menu is empty 
    virtual VfxBool getMenuEmptyText(
        VfxWString & text,
        VcpListMenuTextColorEnum & color
    );

// Method
public:
    // Set content provider
    void setProvider(
        IVappSnsListContentProvider *provider
    );

    // Get content provider
    IVappSnsListContentProvider *getProvider();

    // Set default height
    void setItemDefaultHeight(
        VfxS32 height
    );

    // Get default height
    VfxS32 getItemDefaultHeight();


    // Var height cell bounds changed
    void onItemBoundsChanged(
        VfxFrame *frame, 
        const VfxRect &rect
    );


    // Bounds changed
    virtual void onBoundsChanged(
        VfxFrame *frame,
        const VfxRect &rect
    );

private:
    void onHeightChanged(
        VcpMenuPos menupos,
        VfxSize size
    );

// Private
private:
    enum {
        ITEM_DEFAULT_HEIGHT = VAPP_SNS_ITEM_LAUNCHER_CELL_MIN_H
    };

    // Content provider
    IVappSnsListContentProvider *m_provider;

    // Item default height
    VfxU32 m_defaultHeight;

    // Item update signal
    VfxSignal2 <VcpMenuPos, VfxSize> m_signalHeightChanged;
};


// VappSnsPhotoBorderFrame class declaration
class VappSnsPhotoBorderFrame : public VcpPhotoBorderFrame
{
    VFX_DECLARE_CLASS(VappSnsPhotoBorderFrame);

// Constructor / Descturctor
public:
    VappSnsPhotoBorderFrame();

public:
    void setImgContent(
        const VfxImageSrc &image1, 
        const VfxImageSrc &image2 = VFX_IMAGE_SRC_NULL
    );

    void setImgContent(
        const VfxWString &filename1, 
        const VfxWString &filename2 = VFX_WSTR_NULL, 
        VfxS32 previewImgId = 0, 
        VfxBool isAsync = VFX_TRUE
    );
   
    void setImgContentFrame(VfxFrame *content)
    {
        if (!m_hasSetImg)
        {
            m_hasSetImg = VFX_TRUE;
            
            setImageFrame(content);
        }
    }

    VfxFrame *getImgContentFrame()
    {
        return getImageFrame();
    }

    VfxBool getIsHasImgContentFrame()
    {
        return m_hasSetImg;
    }
    
    VfxS32 getImgBorderWidth()
    {
        return VAPP_SNS_ITEM_TITLE_IMAGE_BORDER;
    }

    const VfxImageSrc &getImgContentSrc();

    const VfxImageList &getImgContentList();

    void releaseAsyncImgFrame();

    static void *memAllocator(VfxU32 size, void *userData);

    static void memDeallocator(void *mem, void *userData);

private:
    VfxBool m_hasSetImg;
    
    // Title image content frame
    VfxFrame *m_imgContent;

    // Title image sub frame1
    VfxFrame *m_subImg1;

    // Title image sub frame2
    VfxFrame *m_subImg2;

    // Title async image sub frame1
    VcpAsyncImageFrame *m_subAsyncImg1;

    // Title async image sub frame2
    VcpAsyncImageFrame *m_subAsyncImg2;

};

// VappSnsItemCaption class declaration
class VappSnsItemCaption : public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsItemCaption);

// Contructor / Destructor
public:
    // Default constructor
    VappSnsItemCaption();

// Enum
public:
    // Layout mode
    enum LayoutMode {
        LAYOUT_MODE_NORNAL,
        LAYOUT_MODE_TEXT_ONLY
    };

// Overridable    
protected:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Pen event input
    virtual VfxBool onPenInput(VfxPenEvent &event);

    // Refresh button tapped handler
    virtual void onAttachedButtonClicked(VfxObject *sender, VfxId id);

    // Image tappable handler
    virtual void onImageTapped();

// Implementation
public:
    // Set layout mode
    void setMode(LayoutMode mode);

    // Set image frame
    void setImage(const VfxImageSrc &image);

    // Set image frame
    void setImage(const VfxImageList &imageList, VfxId key1 = 1, VfxId key2 = 2);

    // Get image
    const VfxImageSrc &getImage();

    // Set text frame
    void setText(const VfxWString &text, VfxChar *userId, VfxU8 userIdLen);

    // Get text
    const VfxWString &getText();

    // Get user id
    VfxChar *getUserId();

    // Set icon frame
    void setIcon(const VfxImageSrc &icon, VfxU32 providerId);

    // Get icon
    const VfxImageSrc &getIcon();

    // Get provider id
    VfxU32 getProviderId();

    // Set attched button image
    void setAttchedBtnImage(const VcpStateImage &image);

    // Hide the attached button
    void setIsAttachedBtnHidden(VfxBool hidden);

    // Enable the attached button
    void disableAttachedBtn(VfxBool disable);

    // Get attached button
    VcpImageButton *getAttachedBtn();

    // Tappable flag
    void setIsTappable(VfxBool isTappable);

// Signal
public:
    // Text clicked signal
    VfxSignal1 <VfxObject *> m_signalTextTapped;

    // Image clicked signal
    VfxSignal1 <VfxObject *> m_signalImageTapped;

    // Attach button clicked signal
    VfxSignal1 <VfxObject *> m_signalAttachedBtnClicked;

// Enum        
private:
    enum {
        IMAGE_WIDTH     = VAPP_SNS_ITEM_TITLE_IMAGE_WIDTH, 
        IMAGE_HEIGHT    = VAPP_SNS_ITEM_TITLE_IMAGE_HEIGHT,
        TEXT_WIDTH      = VAPP_SNS_ITEM_TITLE_WIDTH,
        TEXT_HEIGHT     = VAPP_SNS_ITEM_TITLE_HEIGHT,
        ICON_WIDTH      = VAPP_SNS_ITEM_ICON_WIDTH,
        ICON_HEIGHT     = VAPP_SNS_ITEM_ICON_HEIGHT,
        ICON_POS_X      = VAPP_SNS_ITEM_CAPTION_ICON_POS_X,
        ICON_POS_Y      = VAPP_SNS_ITEM_CAPTION_ICON_POS_Y,
        REFRESH_WIDTH   = VAPP_SNS_ITEM_CAPTION_REFRESH_W,
        REFRESH_HEIGHT  = VAPP_SNS_ITEM_CAPTION_REFRESH_H,

        ITEM_HEIGHT     = VAPP_SNS_ITEM_CAPTION_HEIGHT
    };

    enum ItemState {
        ITEM_STATE_HIGHLIGHTED,
        ITEM_STATE_NORMAL
    };

// Variable
private:
    // Item state
    ItemState m_state;    

    // Layout mode
    LayoutMode m_mode;
    
    // Image frame
    VappSnsPhotoBorderFrame *m_imageFrame;

    // Text frame
    VfxTextFrame *m_textFrame;

    // User id
    VfxChar *m_userId;

    // Image icon frame
    VfxImageFrame *m_iconFrame;

    // Refresh icon frame
    VcpImageButton *m_attachedFrame;

    // Provider id
    VfxU32 m_providerId;

    // Tappable flag
    VfxBool m_isTappable;
    
};

// VappSnsItemTextView class declaration
class VappSnsItemTextView : public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsItemTextView);

// Contructor / Destructor
public:
    // Default constructor
    VappSnsItemTextView(
        void *data = NULL
    );

// Overridable
protected:
    // Init function
    virtual void onInit();

// Implementation
public:
    // Set auto resized
    void setAutoResized(
        VfxBool value
    );

    // Get text view frame
    VcpTextView *getTextView();

    // Set text
    void setMainText(
        const VfxWString &text,
        VfxBool isSupportHyperLink = VFX_TRUE
    );

    // Set buttom rich frame
    void setRichText(
       const VfxWString &left,
       VfxBool belongTextView,
       const VfxWString &right = VFX_WSTR_NULL,
       const VfxImageSrc &image = VFX_IMAGE_SRC_NULL
    );

    // Get cell size
    VfxSize getCellSize();

    // Set text view size
    void setTextViewSize(
        VfxSize size
    );

    // Bounds changed
    void onBoundsChanged(
        VfxFrame *frame, 
        const VfxRect &rect
    );

private:
    // On keyword clicked
    void onKeywordClicked(
        VcpTextKeyWordEnum type,
        VfxWChar *text,
        VfxS32 length
    );

// Variable
private:
    // User data
    void *m_data;

    // Text view
    VcpTextView *m_textView;

    // Rich text format
    VcpRichTextCustomFrame m_richText;    

    // Margin frame
    VfxFrame* m_marginFrame;

    // Truncate mode
    VcpTextTruncateModeEnum m_truncateMode;

    // Max height
    VfxU32 m_maxHeight;

    // Has rich text flag
    VfxBool m_hasRichText;

    // Rich text frame belong text view frame flag
    VfxBool m_belongTextView;

    // Summary frame
    VfxFrame *m_summaryFrame;

    // Auto resize
    VfxBool m_autoResized;

};


/* Variable height menu cell - used in VcpVarHeightMenu list */
// VappSnsItemBase class declaration
class VappSnsItemBase : public VcpVarHeightMenuCell
{
    VFX_DECLARE_CLASS(VappSnsItemBase);

// Enum
public:
    // Item state
    enum ItemState {
        ITEM_STATE_HIGHLIGHTED,
        ITEM_STATE_NORMAL
    };

// Constructor / Destructor
public:
    // Constructor with item type and item id
    VappSnsItemBase(VcpMenuPos menuPos = VcpMenuPos(0, 0));

// Overridable
protected:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Pen input
    virtual VfxBool onPenInput(VfxPenEvent & event);

    // On bounds changed
    virtual void onBoundsChanged(VfxFrame *frame, const VfxRect &rect);    

public:
    // Force update function
    virtual void forceUpdate();
    
// Implementation
public:
    // Set id 
    void setId(VfxId id);

    // Get id
    VfxId getId();

    // Set need to relayout
    void setNeedRelayout(VfxBool needRelayout);

    // Get need to relayout
    VfxBool getNeedRelayout();

    // Set tappable flag
    void setTappable(VfxBool isTappable);
    
    // Get tappable flag
    VfxBool getTappable();

    // Set item state
    void setState(ItemState state);

    // Get item state
    ItemState getState();

    // Set text color
    void setTextColor(VfxTextFrame *frame, const VfxColor &color);

    // Set has a separator line
    void setHasSeparator(VfxBool value);

    // Get has a separator line
    VfxBool getHasSeparator();

    // Set data pointer
    void setProviderId(VfxU32 providerId);

    // Get data pointer
    VfxU32 getProviderId();

    // Set time stamp
    void setTimeStamp(VfxU32 timeStamp);

    // Get time stamp
    VfxU32 getTimeStamp();

    // Add id
    VfxBool addExtendId(VfxId key, VfxChar *value, VfxU16 valueLen);

    // Get id
    VfxChar *getExtendId(VfxId key);

// Signal
public:
    // Tapped signal
    VfxSignal2 <VfxObject*, VfxId> m_signalTapped; 

// Variable
private:
    // Item state
    ItemState m_state;

    // Item id
    VfxId m_id;

    // Tappable flag
    VfxBool m_isTappable;

    // Separator frame
    VfxFrame *m_separator;

    // Provider id
    VfxU32 m_providerId; 

    // Time stamp
    VfxU32 m_timeStamp;

    // Extend id num
    VfxU8 m_extendIdNum;

    // Extend id list 
    vapp_sns_id_list_struct m_extendIdList[VAPP_SNS_ITEM_LANCHER_CELL_MAX_ID_NUM];    

    // Relayout flag
    VfxBool m_needRelayout;
};


// VappSnsItemTextViewCell class declaration
class VappSnsItemTextViewCell : public VappSnsItemBase
{
    VFX_DECLARE_CLASS(VappSnsItemTextViewCell);

// Constrcutor / Destructor
public:
    // Default constructor
    VappSnsItemTextViewCell(        
        void *data = NULL,
        VcpMenuPos menuPos = VcpMenuPos(0, 0)
    );

// Protected
protected:
    // Init function
    virtual void onInit();

// Implementation
public:
    // Set auto resized
    void setAutoResized(
        VfxBool value
    );

    // Set truncate mode
    void setTruncatedMode(
        VcpTextTruncateModeEnum mode
    ); 

    // Set text view height
    void setTextViewSize(
        VfxSize size
    );

    // Set text
    void setMainText(
        const VfxWString &text
    );

    // Set buttom rich frame
    void setRichText(
       const VfxWString &left,
       VfxBool belongTextView,
       const VfxWString &right = VFX_WSTR_NULL,
       const VfxImageSrc &image = VFX_IMAGE_SRC_NULL
    );

// Variable
private:
    // SNS text view
    VappSnsItemTextView *m_snsTextView;

    // Data
    void* m_data;
};


// VappSnsItemRefreshCell class declaration
class VappSnsItemRefreshCell : public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsItemRefreshCell);

// Constrcutor / Destructor
public:
    // Default constructor
    VappSnsItemRefreshCell();

// Enum
public:
    enum BUTTON_ID{
        BUTTON_ID_MAIN      = 0,
        BUTTON_ID_ATTACHED  = 1
    };

    enum LAYOUT_MARGIN{
        DEFAULT_CELL_HEIGHT = VAPP_SNS_ITEM_REFRESHCELL_HEIGHT,
        BUTTON_MARGIN = VAPP_SNS_ITEM_BUTTON_MARGIN,
        BUTTON_MIN_WIDTH = VAPP_SNS_ITEM_BUTTON_MIN_WIDTH
    };


// Protected
protected:
    // On button click
    virtual void onButtonClicked(
        VfxObject *sender,
        VfxId id
    );

// Implementation
public:
    // Set text and user id
    // TODO: replace resid to string and image dircetly
    void setInfo(const VfxWString &text, const VcpStateImage &btnImg, const VfxWString &btnStr);

    // The the attached button is tappable or not
    void setIsAttachedBtnTappable(VfxBool tappable);

    // Set the attched button background
    void setAttchedBtnBgImgList(const VcpStateImage &bgImage);

    // Set has a separator line
    void setHasSeparator(VfxBool value);

    // Get has a separator line
    VfxBool getHasSeparator();

// Signal
public:
    // Tapped signal
    VfxSignal2 <VfxObject*, VfxId> m_signalTapped; 

    // Button click signal
    VfxSignal0 m_signalAttachedBtnClicked;
    
// Variable
private:
    // Main button
    VcpButton *m_mainBtn;

    // Image button
    VcpButton *m_attchedBtn;

    // Separator frame
    VfxFrame *m_separator;

    // High light flag
    VfxBool m_highlighted;
};


// VappSnsItemViewMoreCell class declaration
class VappSnsItemViewMoreCell : public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsItemViewMoreCell);

    // Item state
    enum VappSnsItemViewMoreState {
        VAPP_SNS_ITEM_VIEW_MORE_HIGHLIGHTED,
        VAPP_SNS_ITEM_VIEW_MORE_NORMAL
    };

// Constrcutor
public:
    VappSnsItemViewMoreCell();

// signal
public:
    // Tapped signal
    VfxSignal2 <VfxObject*, VfxId> m_signalTapped; 

// Method
public:
    void setText(const VfxWString &text);
    VfxTextFrame* getText() {return m_text;}
    void setHasSeparator(VfxBool isSeperator);

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

// member variables
private:
    VfxTextFrame *m_text;
    VfxFrame *m_separator;
    VappSnsItemViewMoreState m_state;
};


// VappSnsItemLauncherCell class declaration
class VappSnsItemLauncherCell : public VappSnsItemBase
{
    VFX_DECLARE_CLASS(VappSnsItemLauncherCell);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsItemLauncherCell(VcpMenuPos menuPos = VcpMenuPos(0, 0));
    
    VappSnsItemLauncherCell(VcpMenuPos menuPos, void *userData);    

// Enum
public:
    enum LayoutMode {
        LAYOUT_MODE_NORMAL,
        LAYOUT_MODE_EXTEND,
        LAYOUT_MODE_NO_ICON,
        LAYOUT_MODE_TEXT_ONLY,
    };

    // Hint position
    enum HintPosition{
        HINT_POSITION_TOP,
        HINT_POSITION_BUTTOM
    };

// Override
protected:
    // Init function
    virtual void onInit();

    // Deinit function 
    virtual void onDeinit();

    // Update function
    virtual void onUpdate();

    // Pen input event
    virtual VfxBool onPenInput(VfxPenEvent &event);

    // Cell tapped event
    virtual void onCellTapped(VfxObject *sender, VfxId id);
    
    // Title or title image tapped
    virtual void onTitleTapped(VfxObject *sender, VfxChar *userId, VfxU32 provider);

// Implementation
public:
    // Set max size
    void setMaxHeight(VfxU32 height);

    // Set data pointer
    void setData(void *dataPtr);

    // Get data pointer
    void *getData();

    // Set layout mode
    void setMode(
        LayoutMode mode
    );

    // Get user id
    VfxChar *getUserId();

    // Get content id
    VfxChar *getContentId();

    // Get content image id
    VfxChar *getContentImgId();

    // Set content max lines
    void setContentMaxLines(
        VfxU32 lines
    );
    
    // Set title / user name
    virtual void setTitle(
        const VfxWString &text,
        VfxBool isTappable, 
        VfxChar *userId = NULL, 
        VfxU8 userIdLen = 0
    );

    // Set title image
    virtual void setTitleImage(
        const VfxImageSrc &image, 
        VfxBool isTappable
    );

    // Set multiple title image
    virtual void setTitleImage(
        const VfxImageSrc &image1,
        const VfxImageSrc &image2,
        VfxBool isTappable
    );

    // Set async file name
    virtual void setTitleImage(
        const VfxWString &filename1,
        VfxBool isTappable = VFX_TRUE,
        VfxS32 previewImgId = 0 // TODO: change the loading image
    );

    // Set async file name
    virtual void setTitleImage(
        const VfxWString &filename1,
        const VfxWString &filename2,
        VfxBool isTappable = VFX_TRUE,
        VfxS32 previewImgId = 0 // TODO: change the loading image
    );

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // Set title frame
    virtual void setTitleImage(
        VfxFrame *frame,
        VfxBool isTappable = VFX_TRUE
    );

    // Set content / description
    virtual void setContent(
        const VfxWString &text,
        VfxS32 maxLines = 0,            // [IN] When the maxLines is set to 0, the content will auto resize within the max size 
        VfxChar *contentId = NULL,
        VfxU8 contentIdLen = 0
    );


    // Set content image
    virtual void setContentImage(
        const VfxImageSrc &image, 
        VfxChar *contentImgId = NULL,
        VfxU8 contentImgIdLen = 0
    );

    // Set content image
    virtual void setContentImage(
        const VfxWString &filename,
        VfxChar *contentImgId = NULL,
        VfxU8 contentImgIdLen = 0,
        VfxS32 previewImgId = 0 // TODO: change the loading image
    );

    // Set hint info
    virtual void setHintText(
        HintPosition pos,
        const VfxWString &text
    );

    // Set logo
    virtual void setIcon(
        const VfxImageSrc &image,
        VfxU32 providerId
    );

    // Set read status
    virtual void setReadStatus(
        VfxBool isRead,
        VfxBool forceUpdate = VFX_TRUE
    );

// Implementation
public:
    // Get title text
    const VfxWString &getTitleText();    

    // Get title image
    const VfxImageSrc &getTitleImage();

    // Get title image path
    void getTitleImagePath(VfxWString &str);

    // Get title image frame
    const VfxImageList &getTitleImageList();

    // Get content text
    const VfxWString &getContentText();

    // Get content image
    const VfxImageSrc &getContentImage();

    // Get content image path
    void getContentImagePath(VfxWString &str);

    // Get hint text
    const VfxWString &getHintText(        
        HintPosition pos
    );

    // Get icon image
    const VfxImageSrc &getIconImage();

    // Get read statue
    VfxBool getReadStatus();

    // Get release flag
    VfxBool getIsAsyncReleased()
    {
        return m_isAsyncReleased;
    }

    // Set release flag
    void setIsAsyncReleased(VfxBool isReleased)
    {
        m_isAsyncReleased = isReleased;
    }

    // Release image resource
    void releaseAsyncImgFrame();

    // Memory allocator
    static void *memAllocator(
        VfxU32 size, 
        void *userData
    );

    // Memory deallocator
    static void memDeallocator(
        void *mem,     
        void *userData
    );

private:
    // Title image tapped
    void onTitleImgTapped();

    // Content image gdi result
    void onGetContentImgGdiResult(
        GDI_RESULT result
    );

// Signal
public:
    // The title or title image tapped signal
    VfxSignal3 <VfxObject*, VfxChar*, VfxU32> m_signalTitleTapped;

// Variable
protected:
    // Title frame
    VfxTextFrame *m_title;
    
    // Title image frame
    VappSnsPhotoBorderFrame *m_titleImage;

    // Content frame
    VfxTextFrame *m_content;

    // Content image
    VfxImageFrame *m_contentImg;

    // Async content image
    VcpAsyncImageFrame *m_contentImage;
    
    // Time stamp frame
    VfxTextFrame *m_topHint;

    // Hint info frame
    VfxTextFrame *m_buttomHint;

    // Logo image
    VfxImageFrame *m_iconImage;

private:
    // Title image enum 
    enum {
        TITLE_IMAGE_ID_1 = 1,
        TITLE_IMAGE_ID_2 = 2
    };

    // Layout mode
    LayoutMode m_mode;

    // User data
    void *m_data;

    // Indicate the title cell is tappable or not
    VfxBool m_isTitleTappable;

    // Indicate the title image is tappable or not
    VfxBool m_isTitleImgTappable;

    // Title state flag
    VfxBool m_titleHighlight;

    // User id
    VfxChar *m_userId;

    // Title image list
    vapp_sns_image_list_struct m_titleImageList[VAPP_SNS_ITEM_LANCHER_CELL_MAX_TITLE_IMAGE_NUM];

    // Title image list
    VfxImageList m_titleImgList;

    // Title image content frame
    VfxFrame *m_titleImgContent;

    // Content id
    VfxChar *m_contentId;

    // Content max lines
    VfxU32 m_maxLines;

    // Content image id
    VfxChar *m_contentImgId;

    // Max height
    VfxS32 m_maxHeight;
    
    // Default height
    VfxS32 m_defaultHeight;

    // Read status
    VfxBool m_isRead;

    // Is ayns image relased
    VfxBool m_isAsyncReleased;

    // Title image path
    VfxWChar *m_TitleImgPath;

    // Content image path
    VfxWChar *m_contentImgPath;
};


// VappSnsListMenuItemSearchBar class declaration
class VappSnsListMenuItemSearchBar : public VcpListMenuCellClientBaseFrame
{
    VFX_DECLARE_CLASS(VappSnsListMenuItemSearchBar);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsListMenuItemSearchBar();

// Overridable
public:
    virtual void onCreateElements(void);
    virtual void onCloseElements(void);
    virtual void onLayoutElements(void);
    virtual void onUpdateElements(void);

    void setTextEditorString(const VfxWString &text, VfxS32 maxLen);

// Implementation
private:
    // Text editor activated states changed 
    void onEditorActivated(VcpTextEditor *sender, VfxBool isActivate);

    // Button clicked event
    void onButtonClicked(VfxObject *sender, VfxId id);

// Signal
public:
    // Search button clicked signal
    VfxSignal2 <VcpTextEditor *, VfxWChar *> m_signalSeachButtonClicked;

    // Back button clicked signal
    VfxSignal1 <VcpTextEditor *> m_signalBackButtonClicked;

// Variable
private:
    enum {
        LEFT_MARGIN         = 8,
        RIGHT_MARGIN        = 8,
        TOP_BOTTOM_MARGIN   = 8,
        BUTTON_WIDTH        = 50
    };

    enum ButtonIdEnum {
        BUTTON_ID_SEARCH,
        BUTTON_ID_BACK
    };

    // Text editor
    VcpTextEditor *m_textEditor;

    // Function bar
    VcpFunctionBar *m_FunctionBar;

    // The shadow image of search bar
    VfxImageFrame *m_shadow;

    // Search button
    VcpButton *m_searchBtn;

    // Back button
    VcpButton *m_backBtn;

};


/* Account selection cell - used in post/upload  */
// VappSnsAcctSelButton class declaration
class VappSnsAcctSelButton : public VcpArrowButton
{
    VFX_DECLARE_CLASS(VappSnsAcctSelButton);

// Constructor / Destructor
public:
    // Default constructor
    VappSnsAcctSelButton();

    VappSnsAcctSelButton(
        srv_sns_feature_category category, 
        VfxU8 feature = 0, 
        VfxBool supportRotate = VFX_FALSE       //[IN] the page created by button is support rotate or not
    );

// Override
protected:
    // Init function
    virtual void onInit();

    // Deinit function 
    virtual void onDeinit();

// Implementation
public:
    // Get selected number
    VfxU8 getSelectedNum();

    // Get selected accounts
    void getSelectedAccts(VfxU32 *accounts = NULL);
    
private:
    // Button clicked
    void onButtonClicked(VfxObject *sender, VfxId id);

    // Accout selected
    void onAccountSelected(VfxPage *page);

// Signal
public:
    // Selected signal
    VfxSignal0 m_signalAccountSelected;

// Variable
private:
    // Support rotate flag
    VfxBool m_supportRotate;

    // Category
    srv_sns_feature_category m_category;

    // Feature
    VfxU8 m_feature;

    // Provider selection page
    VfxPage *m_page;

    // Selected account
    VfxU32 *m_selectedAccts;

    // Selected num
    VfxU8 m_selectNum;
};

// VappSnsFormItemNameCp class declaration
class VappSnsFormItemNameCp : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VappSnsFormItemNameCp);

// Constructor / Destructor
public: 
    // Default constructor
    VappSnsFormItemNameCp();

// Override
protected:
    // Init function
    virtual void onInit();

    // Update function
    virtual void onUpdate();

// Implemetation
public:
    // Set image
    void setImage(const VfxImageSrc &image);

    // Set title
    void setTitle(const VfxWString &title);

    // Set content
    void setContent(const VfxWString &content);

// Variable
private:
    enum {
        // TODO: resolutions
        STD_MARGIN      = VAPP_SNS_ITEM_STD_MARGIN,
        IMAGE_WIDTH     = VAPP_SNS_FORM_ITEM_IMAGE_WIDTH,
        IMAGE_HEIGHT    = VAPP_SNS_FORM_ITEM_IMAGE_HEIGHT,
        TITLE_WIDTH     = LCD_WIDTH - IMAGE_WIDTH - STD_MARGIN * 3,
        CONTENT_WIDTH   = LCD_WIDTH - IMAGE_WIDTH - STD_MARGIN * 3,
        TOTAL_HEIGHT    = IMAGE_HEIGHT + STD_MARGIN * 2
    };

    // Image
    VcpPhotoBorderFrame *m_image;

    // Title text
    VfxTextFrame *m_title;

    // Content text
    VfxTextFrame *m_content;
};

// VappSnsFormItemLabelViewer class declaration
class VappSnsFormItemLabelViewer : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VappSnsFormItemLabelViewer);

// Enum
public:
    // Layout mode
    enum LayoutMode {
        LAYOUT_MODE_SINGLE_LINE,
        LAYOUT_MODE_MUTIPLE_LINE
    };

    // Button index
    enum ButtonIndex {
        BUTTON_INDEX_1,
        BUTTON_INDEX_2
    };

// Constructor / Destructor
public:
    VappSnsFormItemLabelViewer();

// Override
protected:
    // Init function
    virtual void onInit();

    // Update function
    virtual void onUpdate();

    // Button clicked handler
    virtual void onButtonClicked(VfxObject *sender, VfxId id);

// Implementation
public:
    void setLayoutMode(LayoutMode mode);

    // Set label and text
    void setText(const VfxWString& label, const VfxWString& text);

    // Set hide button
    void setHideButton(VfxBool hideBtn);

    // Set button
    void setButton(ButtonIndex index, VfxId id, const VfxWString &text, VfxBool disable = VFX_FALSE);

    // From bounds changed handler
    virtual void onFormBoundsChanged(VfxFrame *frame, const VfxRect &rect);

// Signal
public:
    // Button clicked signal
    VfxSignal2 <VfxObject*, VfxId> m_signalButtonClicked;

// Variable
private:
    // Layout mode
    LayoutMode m_mode;
    
    // Has button flag
    VfxBool m_hideButton;

    // Label frame
    VfxTextFrame *m_label;

    // Text frame
    VfxTextFrame *m_text;

    // Button 1
    VcpButton *m_button1;

    // Button 2
    VcpButton *m_button2;

};


#ifdef __MMI_SNS_MESSAGES__
class VappSnsMsgSender : public VfxControl
{
    VFX_DECLARE_CLASS(VappSnsMsgSender);

// Constructor
public:
    VappSnsMsgSender();

// Method
public:
    void setId(VfxId id);
    VfxId getId();
    void setInfo(VfxChar *threadId, VfxU32 threadIdLen, VfxU32 providerId);
    void setMaxInputLength(VfxS32 length);
    void setMaxInputHeight(VfxU32 minHeight, VfxU32 maxHeight);
    VfxWChar *getInputText();
    // TODO:VcpTextEditor *getEditor();

// signals
    VfxSignal3 <VfxObject *, VfxId, VfxS32> m_signalReplyClicked;

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual void onReplyClicked(VfxObject *obj, VfxId id);

private:
    void updateLayout();
    void onBtnBoundsChanged(VfxFrame *obj, const VfxRect &rect);
    void onTextChanged(VcpTextEditor *obj);

// member variables
private:
    VfxId m_id;
    VcpTextEditor *m_editor;
    VcpButton *m_sendBtn;
    VfxChar *m_threadId;
    VfxU32 m_providerId;
};
#endif /* __MMI_SNS_MESSAGES__ */

class VappSnsAsyncPhotoBorderFrame : public VcpPhotoBorderFrame
{
    VFX_DECLARE_CLASS(VappSnsAsyncPhotoBorderFrame);

public:
    VappSnsAsyncPhotoBorderFrame();
    VappSnsAsyncPhotoBorderFrame(const VfxWString &imagePath, VfxS32 previewImageId, VfxSize size);

protected:
    virtual void onInit();
    
public:
    VcpAsyncImageFrame* getAsyncImage();
    void setImage(VfxWChar* path);

private:
    void onHandleGdiResult(GDI_RESULT result);

    static void* allocMem(VfxU32 size, void *userData);
    static void freeMem(void *mem, void *userData);
private:
    mmi_id m_groupId;
    VfxS32 m_previewImgId;
    VcpAsyncImageFrame *m_asyncImg;
    VfxSize m_size;
    VfxWString m_path;
};

#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#endif /* VAPP_SNS_BASE_CP_H */
