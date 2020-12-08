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
 *  ImgEdtSrvTestTable.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Imgage Editing service test menu table
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
#ifdef SRV_IES_TESTBED_ENABLE

#ifndef __SRV_IES_TEST_TABLE_H__
#define __SRV_IES_TEST_TABLE_H__

#include "ImgEdtSrvTestItems.h"

/***************************************************************************** 
 * Menu Define
 * Please define menu structure here
 *****************************************************************************/
SRV_IES_TST_BEGIN_DEF_MENU(L"IES Srv Test File", srv_ies_test_render)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Render Preview",    srv_ies_test_rt_test_render, IESTestFile::IES_TEST_RENDER_PREVIEW)
SRV_IES_TST_END_DEF_MENU(srv_ies_test_render)

SRV_IES_TST_BEGIN_DEF_MENU(L"IES Effect Test", srv_ies_test_effect)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Color Adjust",      srv_ies_tst_rt_test_effect, IESTestFile::IES_TEST_COLOR_ADJUST)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Negative",          srv_ies_tst_rt_test_effect, IESTestFile::IES_TEST_NEGATIVE_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Grayscale",         srv_ies_tst_rt_test_effect, IESTestFile::IES_TEST_GRAYSCALE_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Mirror",            srv_ies_tst_rt_test_effect, IESTestFile::IES_TEST_MIRROR_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Brightness",        srv_ies_tst_rt_test_effect, IESTestFile::IES_TEST_BRIGHTNESS_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Contrast ",         srv_ies_tst_rt_test_effect, IESTestFile::IES_TEST_CONTRAST_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Speia ",            srv_ies_tst_rt_test_effect, IESTestFile::IES_TEST_SEPIA_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Sharpness ",        srv_ies_tst_rt_test_effect, IESTestFile::IES_TEST_SHARPNESS_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"IES Oil Paint ",        srv_ies_tst_rt_test_effect, IESTestFile::IES_TEST_OIL_PAINT_EFFECT)
SRV_IES_TST_END_DEF_MENU(srv_ies_test_effect)

SRV_IES_TST_BEGIN_DEF_MENU(L"IES Srv Test Caps", srv_ies_test_caps)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS contrast",         srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_CONTRAST_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS sepia",            srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_SEPIA_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS brightness",       srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_BRIGHTNESS_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS clipart",          srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_CLIPART_OPERATION)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS grayscale",        srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_GRAYSCALE_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS grayscale neg",    srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_GRAYSCALE_NEG_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS hueSaturation",    srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_HUE_SATURATION_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS mirror",           srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_MIRROR_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS negative",         srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_NEGATIVE_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS oil paint",        srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_OIL_PAINT_EFFECT)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS rotation",         srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_IMAGE_ROTATION)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS scribble",         srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_SCRIBBLE_OPERATION)
    SRV_IES_TST_DEF_ITEM_TEST(L"CAPS sharpness",        srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_SHARPNESS_EFFECT)
	SRV_IES_TST_DEF_ITEM_TEST(L"CAPs zoom2x",           srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_IMAGE_ZOOM2X)
	SRV_IES_TST_DEF_ITEM_TEST(L"CAPs zoom4x",           srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_IMAGE_ZOOM4X)
	SRV_IES_TST_DEF_ITEM_TEST(L"CAPs pan2x",            srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_IMAGE_PAN2X)
	SRV_IES_TST_DEF_ITEM_TEST(L"CAPs pan4x",            srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_IMAGE_PAN4X)
	SRV_IES_TST_DEF_ITEM_TEST(L"CAPs animZoom",         srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_ANIMATION_ZOOM)
	SRV_IES_TST_DEF_ITEM_TEST(L"CAPs animPan",          srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_ANIMATION_PAN)
	SRV_IES_TST_DEF_ITEM_TEST(L"CAPs speedview",        srv_ies_tst_rt_test_caps, IESTestCAPs::CAPS_TEST_CREATE_SPEEDVIEW)
SRV_IES_TST_END_DEF_MENU(srv_ies_test_caps)

// Top menu
SRV_IES_TST_BEGIN_DEF_MENU(L"Testbed root", srv_ies_testbed_main)
    SRV_IES_TST_DEF_ITEM_MENU(L"IES Test Render",       srv_ies_test_render)
    SRV_IES_TST_DEF_ITEM_MENU(L"IES Test Effect",       srv_ies_test_effect)
    SRV_IES_TST_DEF_ITEM_MENU(L"IES Test Caps",         srv_ies_test_caps)
SRV_IES_TST_END_DEF_MENU(srv_ies_testbed_main)

#endif /* __SRV_IES_TEST_TABLE_H__ */

#endif /* SRV_IES_TESTBED_ENABLE */
