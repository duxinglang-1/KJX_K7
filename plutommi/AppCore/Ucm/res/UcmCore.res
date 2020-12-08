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
 *  UcmCore.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM app core res file
 *
 * Author:
 * -------
 *  Sijia Long (mtk80880)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 20 2012 sijia.long
 * [MAUI_03172212] [UCM] Timer id
 * .
 *
 * 03 30 2012 sijia.long
 * [MAUI_03155151] [APP CORE] UCM PLUTO & COSMOS
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "CustomCfg.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in mmi_res_range_def.h */
<APP id="CORE_UCM">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------Event Resource Area----------------------------------->


    <!-----------------------------------Nvram Resource Area----------------------------------->
#ifdef __MMI_DUAL_MIC_SUPPORT__
    <CACHEDATA type="byte" id="NVRAM_UCM_DUAL_MIC_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Dual mic status setting </DESCRIPTION>
    </CACHEDATA>
#endif /* __MMI_DUAL_MIC_SUPPORT__ */

    <!-----------------------------------Timer Resource Area----------------------------------->
    <TIMER id="UCM_AUTO_ANSWER_TIMER"/>
    <TIMER id="CM_ALERT_NOTIFYDURATION_TIMER"/>
    <TIMER id="CM_CTR_TIMER"/>
    <TIMER id="CM_AUTO_QUICK_END_TIMER"/>
    <TIMER id="CM_VIB_NOTIFYDURATION_TIMER"/>


    <!-----------------------------------String Resource Area---------------------------------->
#if (MMI_MAX_SIM_NUM == 1) || defined(__GENERAL_TTS__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <STRING id="STR_ID_UCM_VOICE_INCOMING"/>
#endif /* (MMI_MAX_SIM_NUM == 1) || defined(__GENERAL_TTS__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */


    <!-----------------------------------Image Resource Area----------------------------------->


    <!-----------------------------------Audio Resource Area----------------------------------->


</APP>
