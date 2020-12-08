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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VTST_RT_VRT_H_
#define _VTST_RT_VRT_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Autotest Item Predeclaration
 * Please add your test item here
 *****************************************************************************/

// Interaction Items > VRT
VtstTestResultEnum vtst_rt_autoanim(VfxU32 param);
VtstTestResultEnum vtst_rt_autoanim_2(VfxU32 param);
VtstTestResultEnum vtst_rt_timeline_target(VfxU32 param);
VtstTestResultEnum vtst_rt_timeline_sync(VfxU32 param);
VtstTestResultEnum vtst_rt_timeline_timing(VfxU32 param);
VtstTestResultEnum vtst_rt_frame_property_effect(VfxU32 param);
VtstTestResultEnum vtst_rt_transform(VfxU32 param);
VtstTestResultEnum vtst_rt_vf_scr(VfxU32 param);
VtstTestResultEnum vtst_rt_draw_cmd_queue(VfxU32 param);
VtstTestResultEnum vtst_rt_dirty_region(VfxU32 param);

/***************************************************************************** 
 * Menu Define
 * Please define menu structure here
 *****************************************************************************/

// Interaction Test > VRT
VTST_BEGIN_DEF_MENU(L"VRT", vrt)
    VTST_DEF_ITEM_TEST(L"Auto Animation",   vtst_rt_autoanim, 0)
    VTST_DEF_ITEM_TEST(L"Auto Animation 2", vtst_rt_autoanim_2, 0)
    VTST_DEF_ITEM_TEST(L"Timeline",         vtst_rt_timeline, 0)
    VTST_DEF_ITEM_TEST(L"Timeline Timing",  vtst_rt_timeline_timing, 0)
    VTST_DEF_ITEM_TEST(L"FPE",              vtst_rt_frame_property_effect, 0)
    VTST_DEF_ITEM_TEST(L"Transform",        vtst_rt_transform, 0)
#ifdef __COSMOS_MMI_PACKAGE__
    VTST_DEF_ITEM_TEST(L"VideoFrame",       vtst_rt_vf_scr, 0)    
#endif
    VTST_DEF_ITEM_TEST(L"Draw Cmd Queue",   vtst_rt_draw_cmd_queue, 0)
#ifdef __COSMOS_MMI_PACKAGE__
    VTST_DEF_ITEM_TEST(L"Dirty Scan",       vtst_rt_dirty_region, 0)
#endif
VTST_END_DEF_MENU(vrt)


#endif /* _VTST_RT_VRT_H_ */

