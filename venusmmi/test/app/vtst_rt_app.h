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

#ifndef _VTST_RT_APP_H_
#define _VTST_RT_APP_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Autotest Item Predeclaration
 * Please add your test item here
 *****************************************************************************/
// Sample Code
VtstTestResultEnum vtst_sample_setting_entry(VfxU32 param);
VtstTestResultEnum vtst_contact_list_entry(VfxU32 param);
VtstTestResultEnum vtst_sample_add_contact(VfxU32 param);
VtstTestResultEnum vtst_sample_ncenter_entry(VfxU32 param);

// Cosmos APP entry point
#ifdef __COSMOS_MMI_PACKAGE__
/* Please add cosmos app entry point here... */
VtstTestResultEnum vtst_rt_vapp_worldclock(VfxU32 param);
VtstTestResultEnum vtst_callset_launch(VfxU32 param);
VtstTestResultEnum vtst_fmgr_testbed_launch(VfxU32 param);
VtstTestResultEnum vtst_sample_setting_framework(VfxU32 param);
#endif /*__COSMOS_MMI_PACKAGE__*/

/***************************************************************************** 
 * Menu Define
 * Please define menu structure here
 *****************************************************************************/

// Sample Code
VTST_BEGIN_DEF_MENU(L"Sample Code", sample_code)
#ifdef __COSMOS_MMI_PACKAGE__
    VTST_DEF_ITEM_TEST(L"Setting",              vtst_sample_setting_entry, 0)
    VTST_DEF_ITEM_TEST(L"Contact list",         vtst_contact_list_entry,0)
    VTST_DEF_ITEM_TEST(L"Add Contact",          vtst_sample_add_contact, 0)
#else
VTST_DEF_ITEM_TEST(L" ",          NULL,0)
#endif
VTST_END_DEF_MENU(sample_code)

// Cosmos APP entry
/* Please add Cosmos APP entry here */
#ifdef __COSMOS_MMI_PACKAGE__
VTST_BEGIN_DEF_MENU(L"Cosmos", cosmos)
    VTST_DEF_ITEM_TEST(L"File Manager",         vtst_fmgr_testbed_launch, 0)
    VTST_DEF_ITEM_TEST(L"Setting",              vtst_sample_setting_framework, 0)
VTST_END_DEF_MENU(cosmos)
#endif 

#endif // _VTST_RT_H_

