/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  DialerCui.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the dialer CUI.
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
 * 04 17 2012 f.wang
 * [MAUI_03168964] Move TimerID to app res file.
 * .
 *
 * 03 08 2012 f.wang
 * [MAUI_03143458] [FTE2.0][Dynamic_SIM_DYNAMIC_UI_and_SIM_name]New feature check in
 * .
 *
 * 03 08 2012 f.wang
 * [MAUI_03143458] [FTE2.0][Dynamic_SIM_DYNAMIC_UI_and_SIM_name]New feature check in
 * .
 *
 * 02 22 2012 f.wang
 * [MAUI_03134994] Dialer tts voice report check in
 * .
 *
 * Jun 22 2010 mtk01585
 * [MAUI_02567833] [Idle] Revise codes by using XML resources
 * Check-in XML resources.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="CUI_DIALER">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h,mmi_rp_srv_editor_def.h"/>


    <!----- String Resource Area ---------------------------------------------->
    <STRING id="STR_ID_CUI_DIALER_NO_SPEED_DIAL_NUM"/>

#if defined(__MMI_VOIP__)
    <STRING id="STR_ID_CUI_DIALER_CHANGE_MODE"/>
#endif

#if defined(__MMI_DIALER_SEARCH__)
    <STRING id="STR_ID_CUI_DIALER_SEARCH_CONTACTS"/>
    <STRING id="STR_ID_CUI_DIALER_SEARCH"/>
    <STRING id="STR_ID_CUI_DIALER_SEARCH_ON"/>
    <STRING id="STR_ID_CUI_DIALER_SEARCH_OFF"/>
#endif /* defined(__MMI_DIALER_SEARCH__) */

#if  defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) 
    <STRING id="STR_ID_SELECT_SIMCARD"/>

#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_CUI_DIALER_CALL_FROM_SIM1"/>
    <STRING id="STR_ID_CUI_DIALER_CALL_FROM_SIM2"/>
#if (MMI_MAX_SIM_NUM >= 3)
    <STRING id="STR_ID_CUI_DIALER_CALL_FROM_SIM3"/>
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    <STRING id="STR_ID_CUI_DIALER_CALL_FROM_SIM4"/>
#endif
#endif

#endif

#if defined(__GENERAL_TTS__)  
    <STRING id="STR_ID_CUI_DIALER_TTS_SETTING"/>
#endif /* defined(__GENERAL_TTS__)*/	

    <!----- Image Resource Area ----------------------------------------------->


    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="GRP_ID_CUI_DIALER_SEARCH_SETTING"/>
    <SCREEN id="SCR_ID_CUI_DIALER_MAIN"/>
#if defined(__MMI_DIALER_SEARCH__)
    <SCREEN id="SCR_ID_CUI_DIALER_SEARCH_CONFIG"/>
#endif

#if  defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <SCREEN id = "GRP_ID_SIM_SELECT"/>
#endif

#if defined(__GENERAL_TTS__)
    <SCREEN id="GRP_ID_CUI_DIALER_TTS_SETTING"/>
#endif /* defined(__GENERAL_TTS__)*/

    <!----- Menu Resource Area ------------------------------------------------>

#if defined(__GENERAL_TTS__)    
	<MENUITEM id="MENU_ID_CUI_DIALER_TTS" str="STR_ID_CUI_DIALER_TTS_SETTING"/>
#endif /* defined(__GENERAL_TTS__)*/	

    <MENU id="MENU_ID_CUI_DIALER_MENU" type="OPTION" str="STR_GLOBAL_OPTIONS">

        <MENUITEM id="MENU_ID_CUI_DIALER_DIAL" str="STR_GLOBAL_DIAL"/>
        <MENUITEM id="MENU_ID_CUI_DIALER_SAVE_CONTACT" str="STR_GLOBAL_SAVE_TO_PHONEBOOK"/>

    #if defined(__MMI_DIALER_SEARCH__)
        <MENUITEM id="MENU_ID_CUI_DIALER_DIALER_SEARCH" str="STR_ID_CUI_DIALER_SEARCH"/>
    #endif

    #if defined(__MMI_VOIP__)
        <MENUITEM id="MENU_ID_CUI_DIALER_CHANGE_MODE" str="STR_ID_CUI_DIALER_CHANGE_MODE"/>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    #endif /* defined(__MMI_VOIP__) */

    </MENU>

#if  defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)

    <MENU id="MENU_ID_CUI_DIALER_SIM_SELECT_MENU" type="OPTION" str="STR_ID_SELECT_SIMCARD">

#if (MMI_MAX_SIM_NUM >= 2)
	<MENUITEM id="MENU_ID_CUI_DIALER_CALL_FROM_SIM1" str="STR_ID_CUI_DIALER_CALL_FROM_SIM1" />
	<MENUITEM id="MENU_ID_CUI_DIALER_CALL_FROM_SIM2" str="STR_ID_CUI_DIALER_CALL_FROM_SIM2" />
#if (MMI_MAX_SIM_NUM >= 3)
	<MENUITEM id="MENU_ID_CUI_DIALER_CALL_FROM_SIM3" str="STR_ID_CUI_DIALER_CALL_FROM_SIM3" />
#endif 	
#if (MMI_MAX_SIM_NUM >= 4)	
	<MENUITEM id="MENU_ID_CUI_DIALER_CALL_FROM_SIM4" str="STR_ID_CUI_DIALER_CALL_FROM_SIM4" />
#endif
#endif

    </MENU>
#endif

#if defined(__GENERAL_TTS__)
    <MENU id="MENU_ID_CUI_DIALER_TTS_SETTING" type="APP_SUB" str="STR_GLOBAL_OPTIONS" flag="RADIO">
    
        <MENUITEM id="MENU_ID_CUI_DIALER_TTS_OFF" str="STR_GLOBAL_OFF" />
        <MENUITEM id="MENU_ID_CUI_DIALER_TTS_ON" str="STR_GLOBAL_ON" />

    </MENU>
#endif /*defined(__GENERAL_TTS__)*/

    <!----- Nvram Data Area ------------------------------------------------>

    <CACHEDATA type="byte" id="NVRAM_IDLE_DIALER_TTS_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> TTS setting on / off </DESCRIPTION>
    </CACHEDATA>

    <!----- Timer ID Area -------------------------------------------------->
    
    <TIMER id="EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER"/>
#ifdef __OP01_FWPBW__
    <TIMER id="DIALER_PLAY_GSM_READY_TIMER"/>
    <TIMER id="DIALER_PLAY_GSM_BUSY_TIMER"/>
    <TIMER id="DIALER_PLAY_GSM_BUSY_DELAY_TIMER"/>
#endif

</APP>

