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
 *  vtst_rt.h
 *
 * Project:
 * --------
 *  Venus Regression Test
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VTST_RT_CP_H_
#define _VTST_RT_CP_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Autotest Item Predeclaration
 * Please add your test item here
 *****************************************************************************/
// Interaction Items > Components
// Common CP
VtstTestResultEnum vtst_rt_text_frame(VfxU32 param);
VtstTestResultEnum vtst_rt_marquee(VfxU32 param);
VtstTestResultEnum vtst_rt_scrollable(VfxU32 param);
VtstTestResultEnum vtst_rt_menu(VfxU32 param);
VtstTestResultEnum vtst_rt_wheel(VfxU32 param);
VtstTestResultEnum vtst_rt_image_button(VfxU32 param);
VtstTestResultEnum vtst_rt_aligner(VfxU32 param);
VtstTestResultEnum vtst_rt_segment_button(VfxU32 param);
VtstTestResultEnum vtst_rt_confirm_Popup(VfxU32 param);
VtstTestResultEnum vtst_rt_command_Popup(VfxU32 param);
VtstTestResultEnum vtst_rt_list_menu(VfxU32 param);
VtstTestResultEnum vtst_rt_group_list_menu(VfxU32 param);
VtstTestResultEnum vtst_rt_reflection(VfxU32 param);
// Cosmos CP
#if defined(__MMI_VUI_COSMOS_CP__)
VtstTestResultEnum vtst_rt_async_image_frame(VfxU32 param);
VtstTestResultEnum vtst_rt_mem_test(VfxU32 param);
VtstTestResultEnum vtst_rt_tab_title_bar(VfxU32 param);
VtstTestResultEnum vtst_rt_tab_bar(VfxU32 param);
VtstTestResultEnum vtst_rt_slider(VfxU32 param);
VtstTestResultEnum vtst_rt_loading_popup(VfxU32 param);
VtstTestResultEnum vtst_rt_menu_popup(VfxU32 param);
VtstTestResultEnum vtst_rt_vcp_form(VfxU32 param);
VtstTestResultEnum vtst_rt_switch(VfxU32 param);
VtstTestResultEnum vtst_rt_function_bar(VfxU32 param);
VtstTestResultEnum vtst_rt_question_Popup(VfxU32 param);
VtstTestResultEnum vtst_rt_more_command_Popup(VfxU32 param);
VtstTestResultEnum vtst_rt_select_Popup(VfxU32 param);
VtstTestResultEnum vtst_rt_text_view(VfxU32 param);
VtstTestResultEnum vtst_rt_text_view_single_view(VfxU32 param);
VtstTestResultEnum vtst_rt_text_view_single_editor(VfxU32 param);
VtstTestResultEnum vtst_rt_text_view_multi_view(VfxU32 param);
VtstTestResultEnum vtst_rt_text_view_multi_editor(VfxU32 param);
VtstTestResultEnum vtst_rt_contact_selector(VfxU32 param);
VtstTestResultEnum vtst_rt_input_popup(VfxU32 param);
VtstTestResultEnum vtst_rt_title_bar(VfxU32 param);
VtstTestResultEnum vtst_rt_bubble_effect(VfxU32 param);
VtstTestResultEnum vtst_rt_activity_indicator(VfxU32 param);
VtstTestResultEnum vtst_rt_progress_indicator(VfxU32 param);
VtstTestResultEnum vtst_rt_tool_bar(VfxU32 param);
VtstTestResultEnum vtst_rt_panel_bar(VfxU32 param);
VtstTestResultEnum vtst_rt_time_picker(VfxU32 param);
VtstTestResultEnum vtst_rt_date_picker(VfxU32 param);
VtstTestResultEnum vtst_rt_menu_seek_bar(VfxU32 param);
VtstTestResultEnum vtst_rt_button(VfxU32 param);
#endif
// FTE CP
#ifndef __MMI_VUI_COSMOS_CP__
VtstTestResultEnum vtst_rt_command_title(VfxU32 param);
VtstTestResultEnum vtst_rt_waiting_icon(VfxU32 param);
#if defined(__MMI_VUI_SHELL_CP__)
VtstTestResultEnum vtst_rt_vcp_inline(VfxU32 param);
#endif
#endif

// Interaction Items > CP Develop
// Common CP
VtstTestResultEnum vtst_rt_page_panel(VfxU32 param);
VtstTestResultEnum vtst_rt_frame_effect(VfxU32 param);
#ifdef __PLUTO_MMI_PACKAGE__
VtstTestResultEnum vtst_rt_image_flow(VfxU32 param);
#endif
// Cosmos CP
#if defined(__MMI_VUI_COSMOS_CP__)
VtstTestResultEnum vtst_rt_picker(VfxU32 param);
VtstTestResultEnum vtst_rt_info_balloon(VfxU32 param);
#endif
// FTE CP
#ifndef __MMI_VUI_COSMOS_CP__
VtstTestResultEnum vtst_rt_option_menu(VfxU32 param);
#endif




/***************************************************************************** 
 * Menu Define
 * Please define menu structure here
 *****************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
// Text component Test
VTST_BEGIN_DEF_MENU(L"TextView & TextEditor", text_cp_test_item)
    VTST_DEF_ITEM_TEST(L"Single line text view",    vtst_rt_text_view_single_view, 0)
    VTST_DEF_ITEM_TEST(L"Single line text editor",  vtst_rt_text_view_single_editor, 0)
    VTST_DEF_ITEM_TEST(L"Multi line text view",     vtst_rt_text_view_multi_view, 0)
    VTST_DEF_ITEM_TEST(L"Multi line text editor",   vtst_rt_text_view_multi_editor, 0)
    VTST_DEF_ITEM_TEST(L"Unit function test",       vtst_rt_text_view, 0)
VTST_END_DEF_MENU(text_cp_test_item)
#endif

// Interaction Test > Components
VTST_BEGIN_DEF_MENU(L"Components", cp)
// Common CP
    VTST_DEF_ITEM_TEST(L"VcpBaseMenu",          vtst_rt_menu, 0)
    VTST_DEF_ITEM_TEST(L"VcpGroupListMenu",     vtst_rt_group_list_menu, 0)
    VTST_DEF_ITEM_TEST(L"VcpImageButton",       vtst_rt_image_button, 0)
    VTST_DEF_ITEM_TEST(L"VcpListMenu",          vtst_rt_list_menu, 0)
    VTST_DEF_ITEM_TEST(L"Marquee",              vtst_rt_marquee, 0)
    VTST_DEF_ITEM_TEST(L"VcpCofirmPopup",       vtst_rt_confirm_Popup, 0)
    VTST_DEF_ITEM_TEST(L"VcpComanndPopup",      vtst_rt_command_Popup, 0)
    VTST_DEF_ITEM_TEST(L"Scrollable",           vtst_rt_scrollable, 0)
    VTST_DEF_ITEM_TEST(L"VcpSegmentButton",     vtst_rt_segment_button, 0)
    VTST_DEF_ITEM_TEST(L"Text Frame",           vtst_rt_text_frame, 0)
    VTST_DEF_ITEM_TEST(L"VcpWheelMenu",         vtst_rt_wheel, 0)
    VTST_DEF_ITEM_TEST(L"VcpContentClone",      vtst_rt_reflection, 0)
    
//Cosmos CP
#if defined(__MMI_VUI_COSMOS_CP__)  
    VTST_DEF_ITEM_TEST(L"CP memory measurement",    vtst_rt_mem_test, 0)
    VTST_DEF_ITEM_TEST(L"VcpAsyncImageFrame",   vtst_rt_async_image_frame, 0)
    VTST_DEF_ITEM_TEST(L"VcpQuestionPopup",     vtst_rt_question_Popup, 0)
    VTST_DEF_ITEM_TEST(L"VcpFunctionBar",       vtst_rt_function_bar, 0)    
    VTST_DEF_ITEM_TEST(L"VcpTimePicker",        vtst_rt_time_picker, 0)
    VTST_DEF_ITEM_TEST(L"VcpDatePicker",        vtst_rt_date_picker, 0)
    VTST_DEF_ITEM_TEST(L"VcpButton",            vtst_rt_button, 0)
    VTST_DEF_ITEM_TEST(L"VcpActivityIndicator", vtst_rt_activity_indicator, 0)
    VTST_DEF_ITEM_TEST(L"VcpProgressIndicator", vtst_rt_progress_indicator, 0)
    VTST_DEF_ITEM_TEST(L"Menu Seek Bar",        vtst_rt_menu_seek_bar, 0)
    VTST_DEF_ITEM_TEST(L"VcpPanelBar",          vtst_rt_panel_bar, 0)
    VTST_DEF_ITEM_TEST(L"VcpMoreComanndPopup",  vtst_rt_more_command_Popup, 0)
    VTST_DEF_ITEM_TEST(L"VcpSelectPopup",       vtst_rt_select_Popup, 0)
    VTST_DEF_ITEM_TEST(L"VcpSwitch",            vtst_rt_switch, 0)
    VTST_DEF_ITEM_TEST(L"VcpSlider",            vtst_rt_slider, 0)    
    VTST_DEF_ITEM_TEST(L"VcpLoadingPopup",            vtst_rt_loading_popup, 0)    
    VTST_DEF_ITEM_TEST(L"VcpTabTitleBar",       vtst_rt_tab_title_bar, 0)
    VTST_DEF_ITEM_TEST(L"VcpTabBar",            vtst_rt_tab_bar, 0)
    VTST_DEF_ITEM_TEST(L"VcpMenuPopup",         vtst_rt_menu_popup, 0)
    VTST_DEF_ITEM_TEST(L"VcpForm",		        vtst_rt_vcp_form, 0)   
    VTST_DEF_ITEM_MENU(L"VcpTextView & VcpTextEditor",   text_cp_test_item)
    VTST_DEF_ITEM_TEST(L"VcpInputPopup",        vtst_rt_input_popup, 0)
    VTST_DEF_ITEM_TEST(L"VcpTitleBar",          vtst_rt_title_bar, 0)
    VTST_DEF_ITEM_TEST(L"VcpToolBar",           vtst_rt_tool_bar, 0)
    VTST_DEF_ITEM_TEST(L"VcpBubbleEffect",      vtst_rt_bubble_effect, 0)
#endif
//FTE CP
#if !defined(__MMI_VUI_COSMOS_CP__)  
#if defined(__MMI_VUI_SHELL_CP__)
    VTST_DEF_ITEM_TEST(L"Inline Menu",          vtst_rt_vcp_inline, 0)
#endif
    VTST_DEF_ITEM_TEST(L"VcpWaitingIcon",       vtst_rt_waiting_icon, 0)
#endif    
     
VTST_END_DEF_MENU(cp)

// Interaction Test > CP Develop
VTST_BEGIN_DEF_MENU(L"CP Develop", cpDev)
// Common CP
    VTST_DEF_ITEM_TEST(L"Page Panel",       vtst_rt_page_panel, 0)
    VTST_DEF_ITEM_TEST(L"Frame Effect",     vtst_rt_frame_effect, 0)
#ifdef __PLUTO_MMI_PACKAGE__
    VTST_DEF_ITEM_TEST(L"Image Flow",       vtst_rt_image_flow, 0)
#endif
    VTST_DEF_ITEM_TEST(L"Frame Aligner",    vtst_rt_aligner, 0)
// Cosmos CP
#ifdef __COSMOS_MMI_PACKAGE__
    VTST_DEF_ITEM_TEST(L"picker",           vtst_rt_picker, 0)
    VTST_DEF_ITEM_TEST(L"VcpInfoBallon",    vtst_rt_info_balloon, 0)
    VTST_DEF_ITEM_TEST(L"VcpContactSelector",   vtst_rt_contact_selector, 0)
    VTST_DEF_ITEM_TEST(L"Ncenter",    vtst_sample_ncenter_entry, 0)
#endif
// FTE CP
#ifndef __MMI_VUI_COSMOS_CP__
    VTST_DEF_ITEM_TEST(L"Option Menu",      vtst_rt_option_menu, 0)
    VTST_DEF_ITEM_TEST(L"Command Title",    vtst_rt_command_title, 0)
#endif
VTST_END_DEF_MENU(cpDev)

#endif // _VTST_RT_H_

