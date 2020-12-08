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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VTST_RT_MC_H_
#define _VTST_RT_MC_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Autotest Item Predeclaration
 * Please add your test item here
 *****************************************************************************/

// Test Items > App FW
VtstTestResultEnum vtst_rt_appscreen(VfxU32 param);
VtstTestResultEnum vtst_rt_archive(VfxU32 param);
VtstTestResultEnum vtst_rt_cui(VfxU32 param);

// Interaction Test > Interaction AppFW
VtstTestResultEnum vtst_rt_appscreen(VfxU32 param);
VtstTestResultEnum vtst_rt_alert(VfxU32 param);

// Interaction Test > Interaction Memory
VtstTestResultEnum vtst_rt_asm(VfxU32 param);
VtstTestResultEnum vtst_rt_newMem(VfxU32 param);
VtstTestResultEnum vtst_rt_tepmem(VfxU32 param);
VtstTestResultEnum vtst_rt_cache_mem(VfxU32 param);
VtstTestResultEnum vtst_rt_asm_v1(VfxU32 param);

#ifdef __COSMOS_MMI_PACKAGE__
VtstTestResultEnum vtst_rt_nmgr(VfxU32 param);
#endif

/***************************************************************************** 
 * Menu Define
 * Please define menu structure here
 *****************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__

// Test Items > App FW
VTST_BEGIN_DEF_MENU(L"App FW", app)
    VTST_DEF_ITEM_TEST(L"Screen",       vtst_rt_appscreen, 0)
    VTST_DEF_ITEM_TEST(L"Archive",      vtst_rt_archive, 0)
    VTST_DEF_ITEM_TEST(L"Cui",          vtst_rt_cui, 0)
VTST_END_DEF_MENU(app)

// Interaction Test > Interaction AppFW
VTST_BEGIN_DEF_MENU(L"Interaction AppFW", iappfw)
    VTST_DEF_ITEM_TEST(L"Alert",   vtst_rt_alert, 0)
#ifdef __COSMOS_MMI_PACKAGE__    
//    VTST_DEF_ITEM_TEST(L"Notification", vtst_rt_nmgr, 0)
#endif  
VTST_END_DEF_MENU(iappfw)

// Interaction Test > Interaction Memory
VTST_BEGIN_DEF_MENU(L"Interaction Memory", inter_memory)
    VTST_DEF_ITEM_TEST(L"ASM",          vtst_rt_asm, 0)
    VTST_DEF_ITEM_TEST(L"New Memory",   vtst_rt_newMem, 0)
    VTST_DEF_ITEM_TEST(L"Temp_Mem",     vtst_rt_tepmem, 0)
#ifdef __COSMOS_MMI_PACKAGE__
    VTST_DEF_ITEM_TEST(L"Cache Memory", vtst_rt_cache_mem, 0)  
#endif
    VTST_DEF_ITEM_TEST(L"ASM v1",       vtst_rt_asm_v1, 0)
VTST_END_DEF_MENU(inter_memory)

#endif

#endif // _VTST_RT_H_

