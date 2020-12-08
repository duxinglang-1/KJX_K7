/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   vapp_sound_settings.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Sound Settings resource file
 *
 * Author:
 * -------
 *   Kinse Lin (mtk01393)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * 06 11 2012 yufei.shen
 * [MAUI_03200411] [Performance]cache added
 * .
 *
 * 06 11 2012 yufei.shen
 * [MAUI_03200411] [Performance]cache added
 * .
 *
 * 03 20 2012 yufei.shen
 * [MAUI_03151780] Volume icon shown differently when connect with BT Headset
 * .
 *
 * 12 26 2011 yufei.shen
 * [MAUI_03097776] [soundsettings]SIM Hot swap check in MAUI & 11B
 * .
 *
 * 09 09 2011 yufei.shen
 * [MAUI_03014631] [UE]Icon on ring volume setting is shown in black color.
 * .
 *
 * 08 05 2011 yufei.shen
 * [MAUI_02998959] volume dialog pop up theme change
 * .
 *
 * 08 04 2011 yufei.shen
 * [MAUI_02998974] Gemini + check in
 * .
 *
 * 03 23 2011 kinse.lin
 * [MAUI_02657295] [FTO][Settings]It show a invalid string regarding sound settings
 * .
 *
 * 03 09 2011 kinse.lin
 * [MAUI_02654820] [Settings]It shoudl keep insistency
 * .
 *
 * 03 04 2011 kinse.lin
 * [MAUI_02653019] [Settings]The max icon tangency with screen
 * .
 *
 * 03 04 2011 kinse.lin
 * [MAUI_02872682] # [Cosmos Todo] [FM Radio] Resource naming revise
 * .
 *
 * 02 17 2011 kinse.lin
 * [MAUI_02871520] [Sound Setting] check in Single SIM modification
 * .
 *
 * 01 18 2011 kinse.lin
 * [MAUI_02648567] [Known Issue][FM Radio][LD] Auto search list : String show STR_ID_FM_AUTO_LIST_EMPTY
 * .
 *
 * 01 05 2011 kinse.lin
 * [MAUI_02856507] [COSMOS] check in to MAUI, 11A and IT Branch
 * .
 *
 * 12 31 2010 kinse.lin
 * [MAUI_02856507] [COSMOS] check in to MAUI, 11A and IT Branch
 * .
 *
 * 12 24 2010 kinse.lin
 * [MAUI_02850366] [COSMOS] check in to MAUI / IT branch
 * .
 *
 * 12 23 2010 shinn.lin
 * [MAUI_02852469] add type attribute for venus app in <APP> tag
 * .
 *
 * 11 10 2010 kinse.lin
 * [MAUI_02836756] [COSMOS] check in COSMOS code to MAUI
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "CustResDef.h"
#include "mmi_features.h"

<?xml version = "1.0" encoding = "UTF-8"?>
<APP id = "VAPP_SOUND_SETTINGS" name = "STR_ID_VAPP_SND_SET_TITLE" type="venus">

#ifdef __LOW_COST_SUPPORT_COMMON__
    <MEMORY heap="200*1024" cui="VCUI_TONE_SELECTOR" vrt_mem_factor="1.0"/>
#else
    <MEMORY heap="200*1024" cui="VCUI_TONE_SELECTOR"/>
#endif

<!-----------------------------------------------------String Section------------------------------------------------------>
    <STRING id="STR_ID_VAPP_SND_SET_TITLE"/>
    <STRING id="STR_ID_VAPP_SND_SET_SILENT_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_SILENT_HINT"/>
    <STRING id="STR_ID_VAPP_SND_SET_VIB_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_VIB_HINT"/>
    <STRING id="STR_ID_VAPP_SND_SET_RING_VOL_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_RING_VOL_HINT"/>
    <STRING id="STR_ID_VAPP_SND_SET_NOTI_SND_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_NOTI_SND_HINT"/>
    <STRING id="STR_ID_VAPP_SND_SET_AS_RING_TONE"/>
    <STRING id="STR_ID_VAPP_SND_SET_INCOMING_CALL_TITLE"/>
    <STRING id="STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE"/>
    <STRING id="STR_ID_VAPP_SND_SET_SIM1_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_SIM2_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_SIM3_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_SIM4_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_MESSAGE_TITLE"/>
    <STRING id="STR_ID_VAPP_SND_SET_MESSAGE_TONE"/>
    <STRING id="STR_ID_VAPP_SND_SET_MAIL_TITLE"/>
    <STRING id="STR_ID_VAPP_SND_SET_MAIL_TONE"/>
    <STRING id="STR_ID_VAPP_SND_SET_DEVICE_SND_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_TOUCH_VIB_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_TOUCH_VIB_HINT"/>
    <STRING id="STR_ID_VAPP_SND_SET_TOUCH_SND_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_TOUCH_SND_HINT"/>
    <STRING id="STR_ID_VAPP_SND_SET_DIAL_PAD_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_DIAL_PAD_HINT"/>
    <STRING id="STR_ID_VAPP_SND_SET_SYSTEM_ALERT_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_SYSTEM_ALERT_HINT"/>
    <STRING id="STR_ID_VAPP_SND_SET_POWER_SND_CAP"/>
    <STRING id="STR_ID_VAPP_SND_SET_POWER_SND_HINT"/>

<!-----------------------------------------------------Image Section------------------------------------------------------>

<!-----------------------------------------------------Audio Section------------------------------------------------------>
    <AUDIO id="AUD_ID_VAPP_SND_SET_PREVIEW" flag="MULTIBIN">CUST_ADO_PATH"\\\\UserProfiles\\\\tone1.wav"</AUDIO>

<!-----------------------------------------------------Evt Section------------------------------------------------------>

#ifdef __SIM_HOT_SWAP_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc= "vapp_sound_settings_sim_ctrl_change_detected_hdlr"/>
#endif

</APP>
