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
 *  FileMgrSrvTestTable.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager service internal prototype header.
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef SRV_FMGR_TEST_TABLE_H
#define SRV_FMGR_TEST_TABLE_H

#ifndef _FMGR_INTERNAL_SOURCE_C_
#error "This header is only for FileManager source!"
#endif

#ifndef SRV_FMGR_TESTBED_ENABLE
#error "Testbed not enable"
#endif

/***************************************************************************** 
 * Function declare
 *****************************************************************************/

SrvFtstTestResultEnum srv_ftst_rt_path(U32 param);
SrvFtstTestResultEnum srv_ftst_rt_storage(U32 param);
SrvFtstTestResultEnum srv_ftst_rt_types(U32 param);
SrvFtstTestResultEnum srv_ftst_rt_ffl_travel(U32 param);
SrvFtstTestResultEnum srv_ftst_rt_ffl_travel2(U32 param);
SrvFtstTestResultEnum srv_ftst_rt_ffl_travel3(U32 param);
SrvFtstTestResultEnum srv_ftst_rt_asyncfs(U32 param);
SrvFtstTestResultEnum srv_ftst_rt_custicon(U32 param);
SrvFtstTestResultEnum srv_ftst_rt_misc(U32 param);

/***************************************************************************** 
 * Menu Define
 * Please define menu structure here
 *****************************************************************************/

SRV_FTST_BEGIN_DEF_MENU(L"FMGR Srv Test", srv_fmgr_test)
    SRV_FTST_DEF_ITEM_TEST(L"Path",             srv_ftst_rt_path,           0)
    SRV_FTST_DEF_ITEM_TEST(L"Stroage",          srv_ftst_rt_storage,        0)
    SRV_FTST_DEF_ITEM_TEST(L"Types",            srv_ftst_rt_types,          0)
    SRV_FTST_DEF_ITEM_TEST(L"Folder travel",    srv_ftst_rt_ffl_travel,     0)
    SRV_FTST_DEF_ITEM_TEST(L"Folder travel - Copy", srv_ftst_rt_ffl_travel2, 0)
    SRV_FTST_DEF_ITEM_TEST(L"Folder travel - LOD", srv_ftst_rt_ffl_travel3, 0)
    SRV_FTST_DEF_ITEM_TEST(L"Async FS",         srv_ftst_rt_asyncfs,        0)
    SRV_FTST_DEF_ITEM_TEST(L"Cust icon",        srv_ftst_rt_custicon,       0)
    SRV_FTST_DEF_ITEM_TEST(L"Misc",             srv_ftst_rt_misc,           0)
SRV_FTST_END_DEF_MENU(srv_fmgr_test)

// Top
SRV_FTST_BEGIN_DEF_MENU(L"Testbed root", main)
    SRV_FTST_DEF_ITEM_MENU(L"FMGR Srv Test",    srv_fmgr_test)
SRV_FTST_END_DEF_MENU(main)


#endif /* SRV_FMGR_TEST_TABLE_H */
