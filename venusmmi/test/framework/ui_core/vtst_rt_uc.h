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

#ifndef _VTST_RT_UC_H_
#define _VTST_RT_UC_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Autotest Item Predeclaration
 * Please add your test item here
 *****************************************************************************/

// Test Items > Base
VtstTestResultEnum vtst_rt_basic_types(VfxU32 param);

// Test Items > PME
VtstTestResultEnum vtst_rt_object(VfxU32 param);
VtstTestResultEnum vtst_rt_signal(VfxU32 param);
VtstTestResultEnum vtst_rt_weakref(VfxU32 param);

// Test Items > MVC
VtstTestResultEnum vtst_rt_allocate(VfxU32 param);
VtstTestResultEnum vtst_rt_vfx(VfxU32 param);
VtstTestResultEnum vtst_rt_frame_create(VfxU32 param);
VtstTestResultEnum vtst_rt_control(VfxU32 param);
VtstTestResultEnum vtst_rt_focus(VfxU32 param);
VtstTestResultEnum vtst_rt_timer(VfxU32 param);
VtstTestResultEnum vtst_rt_timer_switch(VfxU32 param);
VtstTestResultEnum vtst_rt_timeline_create(VfxU32 param);
VtstTestResultEnum vtst_fallback_image_create(VfxU32 param);

// Interaction Test > Report
VtstTestResultEnum vtst_rt_vfx_report(VfxU32 param);

// Interaction Items > Interaction MVC
VtstTestResultEnum vtst_rt_renderer(VfxU32 param);
VtstTestResultEnum vtst_rt_scr_rotate(VfxU32 param);
VtstTestResultEnum vtst_rt_landscape(VfxU32 param);
VtstTestResultEnum vtst_rt_first_frame(VfxU32 param);
VtstTestResultEnum vtst_rt_frame(VfxU32 param);
VtstTestResultEnum vtst_rt_frame_z_order(VfxU32 param);
VtstTestResultEnum vtst_rt_draw_context(VfxU32 param);
VtstTestResultEnum vtst_rt_frame_content(VfxU32 param);
VtstTestResultEnum vtst_rt_frame_filter(VfxU32 param);
VtstTestResultEnum vtst_rt_timeline(VfxU32 param);
VtstTestResultEnum vtst_rt_pen(VfxU32 param);
VtstTestResultEnum vtst_rt_pen_route(VfxU32 param);
VtstTestResultEnum vtst_rt_pen_delay(VfxU32 param);
VtstTestResultEnum vtst_rt_font(VfxU32 param);
VtstTestResultEnum vtst_rt_vector_font(VfxU32 param);
VtstTestResultEnum vtst_rt_vrt_timer(VfxU32 param);
VtstTestResultEnum vtst_rt_hittest(VfxU32 param);
VtstTestResultEnum vtst_rt_timeline_target(VfxU32 param);
VtstTestResultEnum vtst_rt_timeline_sync(VfxU32 param);

// Interaction Items > Device
VtstTestResultEnum vtst_rt_dev_touch_feedback(VfxU32 param);

/***************************************************************************** 
 * Menu Define
 * Please define menu structure here
 *****************************************************************************/
// Test Items > Base
VTST_BEGIN_DEF_MENU(L"Base", base)
    VTST_DEF_ITEM_TEST(L"Basic Types",  vtst_rt_basic_types, 0)
VTST_END_DEF_MENU(base)

// Test Items > PME
VTST_BEGIN_DEF_MENU(L"PME", pme)
    VTST_DEF_ITEM_TEST(L"Allocate",         vtst_rt_allocate, 0)
    VTST_DEF_ITEM_TEST(L"Object",           vtst_rt_object, 0)
    VTST_DEF_ITEM_TEST(L"Signal",           vtst_rt_signal, 0)
    VTST_DEF_ITEM_TEST(L"WeakRef",          vtst_rt_weakref, 0)
VTST_END_DEF_MENU(pme)

// Test Items > MVC
VTST_BEGIN_DEF_MENU(L"MVC", mvc)
    VTST_DEF_ITEM_TEST(L"VFX",          vtst_rt_vfx, 0)
    VTST_DEF_ITEM_TEST(L"Frame",        vtst_rt_frame_create, 0)
    VTST_DEF_ITEM_TEST(L"Control",      vtst_rt_control, 0)
    VTST_DEF_ITEM_TEST(L"Focus",        vtst_rt_focus, 0)
    VTST_DEF_ITEM_TEST(L"Timer",        vtst_rt_timer, 0)
    VTST_DEF_ITEM_TEST(L"Timer Switch", vtst_rt_timer_switch, 0)
    VTST_DEF_ITEM_TEST(L"Timeline",     vtst_rt_timeline_create, 0)
    VTST_DEF_ITEM_TEST(L"Fallback Image", vtst_fallback_image_create, 0)
VTST_END_DEF_MENU(mvc)

// Interaction Test > Report
VTST_BEGIN_DEF_MENU(L"Report", report)
    VTST_DEF_ITEM_TEST(L"Size Report",      vtst_rt_vfx_report, 0)
VTST_END_DEF_MENU(report)

// Interaction Test > Interaction MVC
VTST_BEGIN_DEF_MENU(L"Interaction MVC", inter_mvc)
    VTST_DEF_ITEM_TEST(L"Renderer: MSNF.",  vtst_rt_renderer, 0)
    VTST_DEF_ITEM_TEST(L"Screen Rotate",    vtst_rt_scr_rotate, 0)
    VTST_DEF_ITEM_TEST(L"Landscape",        vtst_rt_landscape, 0)
    VTST_DEF_ITEM_TEST(L"First Frame",      vtst_rt_first_frame, 0)
    VTST_DEF_ITEM_TEST(L"Frame",            vtst_rt_frame, 0)
    VTST_DEF_ITEM_TEST(L"Frame Z Order",    vtst_rt_frame_z_order, 0)
    VTST_DEF_ITEM_TEST(L"Draw Context",     vtst_rt_draw_context, 0)
    VTST_DEF_ITEM_TEST(L"Frame Content",    vtst_rt_frame_content, 0)
    VTST_DEF_ITEM_TEST(L"Frame Filter",     vtst_rt_frame_filter, 0)
    VTST_DEF_ITEM_TEST(L"Timeline Target",  vtst_rt_timeline_target, 0)
    VTST_DEF_ITEM_TEST(L"Timeline Sync",    vtst_rt_timeline_sync, 0)
    VTST_DEF_ITEM_TEST(L"Pen Events",       vtst_rt_pen, 0)
    VTST_DEF_ITEM_TEST(L"Pen Event Routing", vtst_rt_pen_route, 0)
    VTST_DEF_ITEM_TEST(L"Pen Event Delay",  vtst_rt_pen_delay, 0)
    VTST_DEF_ITEM_TEST(L"Fonts",            vtst_rt_font, 0)
    VTST_DEF_ITEM_TEST(L"Vector Font",      vtst_rt_vector_font, 0)
    VTST_DEF_ITEM_TEST(L"VRT Timer",        vtst_rt_vrt_timer, 0)
    VTST_DEF_ITEM_TEST(L"Hit Test",         vtst_rt_hittest, 0)
VTST_END_DEF_MENU(inter_mvc)

// Interaction Test > Device
VTST_BEGIN_DEF_MENU(L"Device", inter_device)
    VTST_DEF_ITEM_TEST(L"Touch Feedback",   vtst_rt_dev_touch_feedback, 0)
VTST_END_DEF_MENU(inter_device)

#endif // _VTST_RT_H_

