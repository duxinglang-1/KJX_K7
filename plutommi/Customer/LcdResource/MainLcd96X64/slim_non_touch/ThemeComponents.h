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
/********************************************************************************
* Filename:
* ---------
*	ThemeComponents.h
*
* Project:
* --------
*	MAUI
*
* Description:
* ------------
*	This file contains all themes structure
*
* Version:
* ------------
*	DEVELOPER VERSION
*
*******************************************************************************/
/******************************************************************************
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *============================================================================== 
*******************************************************************************/
#if !defined(__MTK_TARGET__)
	#define __align(x)
#endif


CONST_HARDWARE UI_filled_area inputbox_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,//|UI_FILLED_AREA_SINGLE_BORDER,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area scrollbar_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,//|UI_FILLED_AREA_SINGLE_BORDER,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},		//{126,186,0,50}
 		{0,0,0,100},
 		{0,0,0,100},			//{42,62,0,50}
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area scrollbar_indicator_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,//|UI_FILLED_AREA_SINGLE_BORDER,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};


CONST_HARDWARE UI_filled_area title_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,  //UI_FILLED_AREA_TYPE_BITMAP,
 		UI_IMAGE_ID_NULL,           //(U8*)img_title_filler_defaultTheme,
 		NULL,
 		{0,0,0,100},                //{66,96,215,100},
 		{0,0,0,100},
 		{255,255,255,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area list_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area list_normal_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area list_selected_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area list_disabled_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area matrix_selected_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},//
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area list_main_menu_normal_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area list_main_menu_selected_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},//
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area list_main_menu_disabled_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area matrix_main_menu_selected_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area general_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area popup_description_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,//|UI_FILLED_AREA_SINGLE_BORDER,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_list_normal_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_list_selected_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_list_disabled_item_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_edit_focussed_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_edit_unfocussed_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_edit_noboundary_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area PIN_inputbox_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,//|UI_FILLED_AREA_SINGLE_BORDER,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area PIN_screen_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area network_screen_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,//|UI_FILLED_AREA_SINGLE_BORDER,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area CM_screen_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area dialer_inputbox_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area virtual_keyboard_key_down_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,225,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{255,255,255,100},
 		0};

CONST_HARDWARE UI_filled_area small_list_menu_normal_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area small_list_screen_border_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};


CONST_HARDWARE UI_filled_area menuitem_single_line_highlight_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area menuitem_two_line_highlight_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area menuitem_multirow_highlight_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area menuitem_thick_highlight_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area menuitem_thick_with_tab_highlight_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area symbol_picker_highlight_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area matrix_highlight_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area main_menu_bkg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},    // {248,248,248,100}
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area sub_menu_bkg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},  // {248,248,248,100}
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area idle_bkg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area status_icon_bar_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};		

CONST_HARDWARE UI_filled_area softkey_bar_bkg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,		//UI_FILLED_AREA_TYPE_BITMAP,
 		UI_IMAGE_ID_NULL,			//(U8*)img_softkey_bar_bkg_filler_defaultTheme,
 		NULL,
 		{0,0,0,100},				//{205,205,205,205}
 		{255,255,255,100},
 		{255,255,255,100},
 		{255,255,255,100},
 		255};

CONST_HARDWARE UI_filled_area tab_title_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};


CONST_HARDWARE UI_filled_area thick_title_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{255,255,255,100},
 		{0,0,0,100},
 		0};



CONST_HARDWARE UI_filled_area small_screen_title_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};


CONST_HARDWARE UI_filled_area tab_normal_tab_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{255,255,255,100},
 		{255,255,255,100},
 		{255,255,255,100},
 		255};

CONST_HARDWARE UI_filled_area tab_highlight_tab_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 	    {255,255,255,100},
 		{255,255,255,100},
 		{255,255,255,100},
 		{255,255,255,100},
 		255};

CONST_HARDWARE UI_filled_area tab_blink_tab_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 	    {255,255,255,100},
 		{255,255,255,100},
 		{255,255,255,100},
 		{255,255,255,100},
 		255};





CONST_HARDWARE UI_filled_area cascade_menu_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area cascade_menu_highlight_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};








CONST_HARDWARE UI_filled_area ime_focused_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{255,255,255,100},
 		{255,255,255,100},
 		0};

CONST_HARDWARE UI_filled_area ime_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{255,255,255,100},
 		{255,255,255,100},
 		0};


CONST_HARDWARE UI_filled_area popup_softkey_bar_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area small_list_menu_highlight_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};


CONST_HARDWARE UI_filled_area special_screen_bkg_filler_defaultTheme={
		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area ime_information_bar_background_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,//|UI_FILLED_AREA_SINGLE_BORDER,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{255,255,255,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_datetime_focussed_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,//|UI_FILLED_AREA_SINGLE_BORDER,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_datetime_unfocussed_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,//|UI_FILLED_AREA_SINGLE_BORDER,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_item_progress_bar_highlight_bg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_item_progress_bar_unhighlight_bg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};


CONST_HARDWARE UI_filled_area inline_item_progress_bar_normal_progress_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area inline_item_progress_bar_step_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};


CONST_HARDWARE UI_filled_area calendar_current_bg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area calendar_current_bg_for_idle_filler_defaultTheme={
		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area popup_screen_bg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,0},
 		{255,255,255,100},//{0,0,0,100}
 		{255,255,255,0},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area rotated_popup_screen_bg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,0},
 		{0,0,0,100},
 		0};

CONST_HARDWARE UI_filled_area singleline_editor_bg_filler_defaultTheme={
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{255,255,255,100},
 		{0,0,0,100},
 		{0,0,0,0},
 		{0,0,0,100},
 		0};

CONST_HARDWARE color lite_disp_scr_bg_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color LSK_up_text_color_defaultTheme={255,255,255,0};

CONST_HARDWARE color LSK_down_text_color_defaultTheme={255,255,255,0};		//{170,240,0,0}

CONST_HARDWARE color LSK_disabled_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color inputbox_normal_text_color_defaultTheme={255,255,255,0};		//{0,0,64,0}

CONST_HARDWARE color inputbox_selected_text_color_defaultTheme={0,0,0,100};			//{255,255,255,100}

CONST_HARDWARE color inputbox_selector_color_defaultTheme={255,255,255,100};		//{51,88,171,100}

CONST_HARDWARE color inputbox_cursor_color_defaultTheme={255,255,255,0};			//{0,128,192,0}

CONST_HARDWARE color title_text_color_defaultTheme={255,255,255,100};		//{0,0,64,100}

CONST_HARDWARE color title_text_border_color_defaultTheme={0,0,0,100};		//{255,255,255,100}

CONST_HARDWARE color title_shortcut_text_color_defaultTheme={255,255,255,100};   //{0,0,0,100}

CONST_HARDWARE color list_normal_text_color_defaultTheme={255,255,255,0};    //{0,0,64,0}

CONST_HARDWARE color list_selected_text_color_defaultTheme={0,0,0,100};   //{255,255,255,100}

CONST_HARDWARE color list_disabled_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color matrix_normal_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color matrix_selected_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color matrix_disabled_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color list_main_menu_normal_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color list_main_menu_selected_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color list_main_menu_disabled_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color matrix_main_menu_normal_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color matrix_main_menu_selected_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color matrix_main_menu_disabled_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color popup_description_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color CM_screen_text_color_defaultTheme={0,0,0,0};

CONST_HARDWARE color datetime_bar_background_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color datetime_bar_duration_background_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color datetime_bar_date_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color datetime_bar_time_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color datetime_bar_duration_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color datetime_bar_AOC_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color information_bar_color_defaultTheme={0,0,0,20};

CONST_HARDWARE color input_method_text_color_defaultTheme={255,255,255,0};    //{0,130,198,0};

CONST_HARDWARE color remaining_length_text_color_defaultTheme={255,255,255,0};	//{0,0,64,0}

CONST_HARDWARE color inline_edit_focussed_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color inline_edit_unfocussed_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color inline_edit_selected_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color inline_edit_selector_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color inline_edit_cursor_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color inline_list_normal_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color inline_list_selected_text_color_defaultTheme={0,0,0,0};

CONST_HARDWARE color inline_list_disabled_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color PIN_inputbox_normal_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color PIN_inputbox_selected_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color PIN_inputbox_selector_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color PIN_inputbox_cursor_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color dialer_inputbox_normal_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color dialer_inputbox_selected_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color dialer_inputbox_selector_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color dialer_inputbox_cursor_color_defaultTheme={255,255,255,0};

CONST_HARDWARE color virtual_keyboard_key_down_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color virtual_keyboard_key_up_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color virtual_keyboard_dead_key_down_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color virtual_keyboard_dead_key_up_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color virtual_keyboard_disp_area_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color idle_scr_date_color_defaultTheme={255,255,255,100};//{0,0,0,0};

CONST_HARDWARE color idle_scr_time_color_defaultTheme={255,255,255,100};//{0,0,0,0};

CONST_HARDWARE color idle_scr_date_border_color_defaultTheme={0,0,0,100};//{255,255,255,100};

CONST_HARDWARE color idle_scr_time_border_color_defaultTheme={0,0,0,100};//{255,255,255,0};

CONST_HARDWARE color idle_scr_network_name_color_defaultTheme={255,255,255,0};

CONST_HARDWARE color idle_scr_network_name_border_color_defaultTheme={0,0,0,0};

CONST_HARDWARE color idle_scr_network_status_color_defaultTheme={255,255,255,0};

CONST_HARDWARE color idle_scr_network_status_border_color_defaultTheme={0,0,0,0};

CONST_HARDWARE color idle_scr_network_extra_color_defaultTheme={255,255,255,0};

CONST_HARDWARE color idle_scr_network_extra_border_color_defaultTheme={0,0,0,0};

CONST_HARDWARE color popup_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color idle_scr_weekday_color_defaultTheme={255,255,255,255};

CONST_HARDWARE color idle_scr_weekday_border_color_defaultTheme={0,0,0,255};

CONST_HARDWARE color date_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color date_text_border_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color time_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color time_text_border_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color analog_hand_hour_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color analog_hand_min_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color analog_axis_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color softkey_text_border_color_defaultTheme={0,0,0,100};    //{20,62,0,100};

CONST_HARDWARE color tab_title_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color tab_title_text_border_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color tab_title_shortcut_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_title_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_horizontal_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_horizontal_border_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_vertical_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_horizontal_string_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_one_task_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_multi_task_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_menstrual_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_PP_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_danger_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_invalid_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_valid_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_invalid_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_highlight_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_infobox_bg_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_infobox_entry_bg_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_infobox_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color thick_title_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color thick_title_text_border_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color thick_title_shortcut_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color cascade_menu_separator_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color cascade_menu_normal_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color cascade_menu_selected_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color cascade_menu_disabled_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color cascade_menu_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color inputbox_base_line_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color inputbox_ems_cr_base_line_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color dialer_inputbox_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color dialer_inputbox_text_border_color_defaultTheme={0,0,255,100};

CONST_HARDWARE color calendar_title_bg_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_horizontal_string_bg_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_vertical_select_bg_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_cell_array_bg_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_frame_line_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_cell_line_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_cell_current_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_popup_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_popup_bg_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_popup_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_horizontal_string_text_for_idle_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_horizontal_string_bg_for_idle_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_cell_valid_text_for_idle_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_cell_invalid_text_for_idle_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_cell_array_bg_for_idle_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_cell_current_text_for_idle_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_cell_highlight_for_idle_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_frame_line_for_idle_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color calendar_cell_line_for_idle_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color arrow_indication_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color arrow_indication_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color dcd_idle_read_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color dcd_idle_unread_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color dcd_story_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color dcd_story_visited_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color dcd_story_unvisited_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color dcd_story_highlight_bar_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color idle_scr_sim2_network_name_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color idle_scr_sim2_network_name_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color idle_scr_sim2_network_status_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color idle_scr_sim2_network_status_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color main_menu_title_color_defaultTheme={255,255,255,100};   // {0,0,64,100}

CONST_HARDWARE color main_menu_title_border_color_defaultTheme={0,0,0,100};  //{255,255,255,100};

CONST_HARDWARE color ime_underline_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_indicator_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_focused_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_border_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color ime_separator_normal_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color ime_focused_separator_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_label_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_cursor_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_arrow_disable_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color ime_arrow_down_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_arrow_up_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_cand_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_cand_highlighted_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color ime_cand_highlight_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_comp_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_comp_highlighted_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color ime_comp_highlight_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_input_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_input_highlighted_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_input_highlight_color_defaultTheme={255,225,255,100};

CONST_HARDWARE color ime_stroke_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_highlighted_stroke_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color ime_stroke_highlight_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color media_player_content_text_color_defaultTheme={0,0,0,0};

CONST_HARDWARE color media_player_content_text_border_color_defaultTheme={255,255,255,0};

CONST_HARDWARE color two_line_second_line_text_color_defaultTheme={255,255,255,0};		//{0,0,64,0}

CONST_HARDWARE color two_line_second_line_highlight_text_color_defaultTheme={0,0,0,100};		//{0,0,50,100}

CONST_HARDWARE color multirow_third_line_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color multirow_third_line_highlight_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color list_grid_line_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color voip_dialer_editor_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color header_information_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color popup_embedded_softkey_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color popup_embedded_softkey_text_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color small_list_menu_highlight_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color small_list_menu_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_idle_large_current_day_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_idle_large_current_date_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color icon_bar_hint_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color virtual_keyboard_key_disabled_bg_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color virtual_keyboard_key_disabled_text_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color uce_screen_subject_color_defaultTheme={255,255,255,0};

CONST_HARDWARE color inline_multiline_readonly_bg_color_defaultTheme={255,255,255,100};

CONST_HARDWARE color icon_bar_item_text_normal_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color icon_bar_item_text_disable_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_title_text_color_for_idle_defaultTheme={0,0,0,100};

CONST_HARDWARE color calendar_cell_event_text_color_for_idle_defaultTheme={0,0,0,100};

CONST_HARDWARE color inputbox_default_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color clipboard_floating_menu_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color icon_bar_item_text_border_normal_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color icon_bar_item_text_border_disable_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color softkey_down_text_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color softkey_disabled_text_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color CM_screen_text_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color inline_item_progress_bar_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color editor_small_screen_border_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color editor_recipient_button_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color stopwatch_active_timer_text_color_defaultTheme={0,0,0,100};

CONST_HARDWARE color stopwatch_inactive_timer_text_color_defaultTheme={0,0,0,100};

