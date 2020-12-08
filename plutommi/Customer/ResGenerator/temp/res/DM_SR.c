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
 *  DM_SR.res (DmSelfRegister.res)
 *
 * Project:
 * -------- 
 *  MAUI, 10A
 *
 * Description:
 * ------------
 *  Resource refered from: DmSelfRegister.c, EngineerMode.res
 *
 * Author:
 * -------
 *  Jie Hao (mtk80027)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 18 2012 yuxiong.feng
 * [MAUI_03171160] [timer id remove]remove to res file
 * .
 *
 * 03 04 2012 yuxiong.feng
 * [MAUI_03130549] Please turn on "Device Name" & "Master Switch" on EM->Misc->DM Self Register
 * .
 *
 * 10 03 2011 yuxiong.feng
 * [MAUI_03040332] [TD][DM]DM should not self register after restore facatory settings
 * .
 *
 * 06 07 2011 yuxiong.feng
 * [MAUI_02954526] [DM] App/Srv split check in
 * .
 *
 * 12 06 2010 jie.hao
 * [MAUI_02642955] [NVRAM Revise] New MMI Catch register (xml)
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#include "CustResDef.h"

#if defined(__MMI_DM_SELF_REGISTER_SUPPORT__)


<?xml version = "1.0" encoding="UTF-8"?>

<APP id="SRV_DM_SR">

    <!----------------- Include Area --------------------------------------->


    <!----------------- Screen Id -----------------------------------------> 


    <!----------------- String Id ------------------------------------------> 


    <!----------------- Image Id ------------------------------------------> 

    <!----------------- Timer Id ------------------------------------------> 
    <TIMER id="DM_SR_REPEAT_TIMER_ID"/> 
    <TIMER id="DM_SR_IMSI_REPEAT_TIMER_ID"/>
    <TIMER id="DM_SR_SIM2_IMSI_REPEAT_TIMER_ID"/>
    <!-----------------Menu Resource Area---------------------------------->

   
    <!-----------------Menu Resource Area---------------------------------->

    
    <!-----------------NVRAM Cache data Resource-------------------------------------->

    <CACHEDATA type="byte" id="NVRAM_DM_SELF_REGISTER_RESULT" restore_flag="FALSE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> CMCC DM Settings </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_DM_SELF_REGISTER_SIM" restore_flag="FALSE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> DUAL DM SIM Settings </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_DM_SELF_REGISTER_MASTER_SWITCH" restore_flag="FALSE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> CMCC DM Settings </DESCRIPTION>
    </CACHEDATA>


</APP>


#endif    /* __MMI_DM_SELF_REGISTER_SUPPORT__ */


