/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_launcher_mre.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the MRE launcher's resources.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 * 
 * 08 03 2012 ch.ko
 * [MAUI_03222219] [DLUI] Support to handle VPP file path in the ROM
 * Check-in patch.
 *
 * 07 10 2012 ch.ko
 * [MAUI_03211939] [UE] the launcher does not restore when we plug out USB
 * Check-in patch and revise codes.
 *
 * 06 20 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Support to embed downloadable app icon in the MRE launcher.
 *
 * 06 15 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Revise codes.
 *
 * 06 14 2012 ch.ko
 * [MAUI_03202128] [1] Assert fail: Caller Address: 0x10937066 Line: 323 - MMI File: venusmmi\app\common\launcher\vapp_launcher.cpp, Function: VappLauncher::releaseView()
 * Support to release launcher heap in an async way.
 *
 * 06 01 2012 ch.ko
 * [MAUI_03165607] [Cosmos Slim] Check-in patch
 * Support launcher to use ASM as runtime heap.
 *
 * 05 18 2012 ch.ko
 * [MAUI_03163831] [DLUI] Check-in patch
 * Check-in MRE launcher memory model.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_MRE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_LAUNCHER_MRE"
     name="STR_ID_VAPP_LAUNCHER_MRE"
     type="venus"
     hidden_in_mainmenu="true">

    <!-- System Resource Area-------------------------------------------------->

    <MEMORY base="$(VAPP_LAUNCHER_MRE_ASM_SIZE)" inc="vapp_launcher_mre_def.h"/>


    <!-- Screen Resource Area ---------------------------------------------->

    <SCREEN id="GRP_ID_VAPP_LAUNCHER_MRE_ASM"/>


    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_LAUNCHER_MRE"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_MRE_CANNOT_LOAD_LAUNCHER"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_MRE_NOT_ENOUGH_MEMORY"/>


    <!-- Image Resource Area--------------------------------------------------->


    <!-- Event Area (Sender) -------------------------------------------------->


    <!-- Event Area (Receiver) ------------------------------------------------>

    <RECEIVER id="EVT_ID_VAPP_LAUNCHER_SYS_INIT" proc="VappLauncherMreFactoryPublisher"/>


</APP>

#endif /* defined(__MMI_VUI_LAUNCHER_MRE__) */

