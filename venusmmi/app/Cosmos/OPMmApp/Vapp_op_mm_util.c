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
 *  Vapp_op_mm_util.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Mainmenu helper function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "Vapp_op_mm_util.h"

#ifdef __MMI_OP02_MIDLET_WO_STORE__
// java.Midlet Suite Vendor.联通应用商店
const WCHAR wo_store[] = {
    'j', 'a', 'v', 'a', '.', 'M', 'i', 'd', 'l', 'e', 't', ' ', 'S', 'u', 'i', 't', 'e', ' ', 'V', 'e', 'n', 'd', 'o', 'r', '.', 
    0x8054, 0x901a, 0x5e94, 0x7528, 0x5546, 0x5e97, 0x0000};
#endif

#ifdef __MMI_OP02_MIDLET_PUSH_MAIL__
// java.ChinaUnicom.手机邮箱
const WCHAR push_mail[] = {
    'j', 'a', 'v', 'a', '.', 'C', 'h', 'i', 'n', 'a', 'U', 'n', 'i', 'c', 'o', 'm', '.',  
    0x624b, 0x673a, 0x90ae, 0x7bb1, 0x0000};
#endif

#ifdef __MMI_OP02_MIDLET_MOBILE_TV__
// java.融创天下.手机电视
const WCHAR mobile_tv[] = {
    'j', 'a', 'v', 'a', '.', 
    0x878d, 0x521b, 0x5929, 0x4e0b, '.', 0x624b, 0x673a, 0x7535, 0x89c6, 0x0000};
#endif

#ifdef __MMI_OP01_MIDLET_FETION__
// java.中国移动有限公司.飞信
const WCHAR fetion[] = {
    'j', 'a', 'v', 'a', '.', 
    0x4E2D, 0x56FD, 0x79FB, 0x52A8, 0x6709, 0x9650, 0x516C, 0x53F8, '.', 0x98DE, 0x4FE1, 0x0000};
#endif

#ifdef __MMI_OP01_MIDLET_MUSIC_WALKMAN__
// java.中国移动.音乐随身听
const WCHAR music_walkman[] = {
    'j', 'a', 'v', 'a', '.', 
    0x4E2D, 0x56FD, 0x79FB, 0x52A8, '.', 0x97F3, 0x4E50, 0x968F, 0x8EAB, 0x542C, 0x0000};
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_STOCK__
// java.Netgen Inc.手机证券
const WCHAR mobile_stock[] = {
    'j', 'a', 'v', 'a', '.', 'N', 'e', 't', 'g', 'e', 'n', ' ', 'I', 'n', 'c', '.', 
    0x624B, 0x673A, 0x8BC1, 0x5238, 0x0000};
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_MAP__
// java.GuanTu.手机地图
const WCHAR mobile_map[] = {
    'j', 'a', 'v', 'a', '.', 'G', 'u', 'a', 'n', 'T', 'u', '.', 
    0x624B, 0x673A, 0x5730, 0x56FE, 0x0000};
#endif

#ifdef __MMI_OP01_MIDLET_MOBILE_READ__
// java.Midlet Suite Vendor.手机阅读
const WCHAR mobile_read[] = {
    'j', 'a', 'v', 'a', '.', 'M', 'i', 'd', 'l', 'e', 't', ' ', 'S', 'u', 'i', 't', 'e', ' ', 'V', 'e', 'n', 'd', 'o', 'r', '.', 
    0x624B, 0x673A, 0x9605, 0x8BFB, 0x0000};
#endif

const vapp_op_midlet_info_struct vapp_op_midlet_info[] = 
{
#ifdef __MMI_OP01_MIDLET_FETION__
            {VAPP_OP01_MIDLET_FETION, fetion},
#endif
#ifdef __MMI_OP01_MIDLET_MUSIC_WALKMAN__
            {VAPP_OP01_MIDLET_MUSIC_WALKMAN, music_walkman},
#endif
#ifdef __MMI_OP01_MIDLET_MOBILE_STOCK__
            {VAPP_OP01_MIDLET_MOBILE_STOCK, mobile_stock},
#endif
#ifdef __MMI_OP01_MIDLET_MOBILE_MAP__
            {VAPP_OP01_MIDLET_MOBILE_MAP, mobile_map},
#endif
#ifdef __MMI_OP01_MIDLET_MOBILE_MARKET__
            {VAPP_OP01_MIDLET_MOBILE_MARKET, L"java.YTXT.MM"},
#endif
#ifdef __MMI_OP01_MIDLET_MOBILE_READ__
            {VAPP_OP01_MIDLET_MOBILE_READ, mobile_read},
#endif
#ifdef __MMI_OP02_MIDLET_WO_STORE__
    {VAPP_OP02_MIDLET_WO_STORE, wo_store},
#endif
#ifdef __MMI_OP02_MIDLET_116114__
    {VAPP_OP02_MIDLET_116114, L"java.ChinaUnicom.116114"},
#endif
#ifdef __MMI_OP02_MIDLET_MOBILE_MUSIC__
    {VAPP_OP02_MIDLET_MOBILE_MUSIC, L"java.HuaWei Music.MusicClient"},
#endif
#ifdef __MMI_OP02_MIDLET_PUSH_MAIL__
    {VAPP_OP02_MIDLET_PUSH_MAIL, push_mail},
#endif
#ifdef __MMI_OP02_MIDLET_MOBILE_TV__
    {VAPP_OP02_MIDLET_MOBILE_TV, mobile_tv},
#endif
    {VAPP_OP_MIDLET_TOTAL, NULL}
};


/*****************************************************************************
 * FUNCTION
 *  vapp_op_get_midlet_count
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
U32 vapp_op_get_midlet_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(vapp_op_midlet_info) / sizeof(vapp_op_midlet_info_struct) - 1;
}


