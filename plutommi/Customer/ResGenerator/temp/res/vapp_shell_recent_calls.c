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
 *  CallLog.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Resource file.
 *
 * Author:
 * -------
 *  Fachao Zhang (mtk80513)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 15 2010 fachao.zhang
 * [MAUI_02640419] [FTO] calllog check in
 * .
 *
 * 11 18 2010 fachao.zhang
 * [MAUI_02641036] [NVRAM Cache Migrate] from /nvram_mgr.res to APP.res
 * .
 *
 * Jun 2 2010 mtk80513
 * [MAUI_02203659] [Shell][Recent calls] Support New layout with shadow and bg image tap
 * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_VUI_SHELL_RECENT_CALLS__

<APP id="APP_VENUS_SHELL_RECENT_CALLS">

#ifndef __MMI_VUI_SHELL_RECENT_CALLS_SLIM__
#define SHELL_RC_ROOT  CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\CallLog\\\\"
#else
#define SHELL_RC_ROOT  CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell_Low\\\\CallLog\\\\"
#endif

    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_SHELL_STR_RECENT_CALLS"/>
    <STRING id="VAPP_SHELL_STR_RC_NO_CALLS"/>
    <STRING id="VAPP_SHELL_STR_RC_UNNAMED"/>
    <STRING id="VAPP_SHELL_STR_RC_UNKNOWN"/>
    <STRING id="VAPP_SHELL_STR_RC_TODAY"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="VAPP_SHELL_IMG_RC_TAB_ALL_CALL_NORMAL">    SHELL_RC_ROOT"AllCall_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_TAB_ALL_CALL_HILITE">    SHELL_RC_ROOT"AllCall_High.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_TAB_MISSED_CALL_NORMAL"> SHELL_RC_ROOT"MissedCall_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_TAB_MISSED_CALL_HILITE"> SHELL_RC_ROOT"MissedCall_High.png"</IMAGE>

#if (MMI_MAX_SIM_NUM >= 4)
    <IMAGE id="VAPP_SHELL_IMG_RC_LM_SIM4">            SHELL_RC_ROOT"List_MissedCall_4.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LD_SIM4">            SHELL_RC_ROOT"List_DialedCall_4.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LR_SIM4">            SHELL_RC_ROOT"List_ReceivedCall_4.png"</IMAGE>
#endif /* (MMI_MAX_SIM_NUM >= 4) */

#if (MMI_MAX_SIM_NUM >= 3)
    <IMAGE id="VAPP_SHELL_IMG_RC_LM_SIM3">            SHELL_RC_ROOT"List_MissedCall_3.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LD_SIM3">            SHELL_RC_ROOT"List_DialedCall_3.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LR_SIM3">            SHELL_RC_ROOT"List_ReceivedCall_3.png"</IMAGE>
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if (MMI_MAX_SIM_NUM >= 2)
    <IMAGE id="VAPP_SHELL_IMG_RC_LM_SIM1">            SHELL_RC_ROOT"List_MissedCall_1.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LD_SIM1">            SHELL_RC_ROOT"List_DialedCall_1.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LR_SIM1">            SHELL_RC_ROOT"List_ReceivedCall_1.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LM_SIM2">            SHELL_RC_ROOT"List_MissedCall_2.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LD_SIM2">            SHELL_RC_ROOT"List_DialedCall_2.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LR_SIM2">            SHELL_RC_ROOT"List_ReceivedCall_2.png"</IMAGE>
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#if (MMI_MAX_SIM_NUM == 1)
    <IMAGE id="VAPP_SHELL_IMG_RC_LIST_MISSED">            SHELL_RC_ROOT"List_MissedCall.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LIST_DIALED">            SHELL_RC_ROOT"List_DialedCall.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_LIST_RECVED">            SHELL_RC_ROOT"List_ReceivedCall.png"</IMAGE>
#endif /* (MMI_MAX_SIM_NUM == 1) */

    <IMAGE id="VAPP_SHELL_IMG_RC_BG_SHADOW">    SHELL_RC_ROOT"BG_Shadow.9slice.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_BG_TOP">       SHELL_RC_ROOT"BG_01.9slice.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_RC_BG_TAIL">      SHELL_RC_ROOT"BG_02.9slice.png"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <CACHEDATA type="short" id="NVRAM_SHELL_RECENT_CALLS_TAB_IDX">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>




</APP>

#endif /* __MMI_VUI_SHELL_RECENT_CALLS__ */
