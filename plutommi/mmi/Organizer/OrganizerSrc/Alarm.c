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
 * Alarm.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm application related screens.
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
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it) 
 */

/**************************************************************

   FILENAME : Alarm.c

   PURPOSE     : Handling of Alarm Application

   REMARKS     : nil

   AUTHOR      : Neeraj Sharma, Gautam Saluja

   DATE     : June 9,03

**************************************************************/
#include "MMI_features.h"


/*****************************************************************************
* Header files
*****************************************************************************/

//#include "ProtocolEvents.h"

#include "AlarmProt.h"
#include "AlarmDef.h"
#include "AlarmFrameworkProt.h"
#include "HomeScreenOp11V32Gprot.h"
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#endif
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
#include "Aud_Defs.h"
#include "conversions.h"
#include "ToneSelectorCuiGprot.h"
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */

#include "MenuCuiGprot.h"
#include "InlineCuiGprot.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_app_profiles_def.h"
#include "FileMgrSrvGprot.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "gui_data_types.h"
#include "mmi_rp_app_alarm_def.h"
#include "GlobalResDef.h"
#include "ImeGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"
#include "mmi_rp_app_uiframework_def.h"
#include "nvram_common_defs.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_frm_input_gprot.h"
#include "gpiosrvgprot.h"
#include "CommonScreensResDef.h"
#include "mdi_audio.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_theme_mgr.h"
#include "ReminderSrvGprot.h"
#include "AlarmSrvGprot.h"
#include "UcmSrvGprot.h"
#include "UcmGProt.h"

/*****************************************************************************
* Typedef  
*****************************************************************************/
#ifndef __MMI_DEV_NEW_SLIM__
typedef MMI_BOOL (*AlmSearchCallback)(U8, MYTIME *, MMI_BOOL);
typedef MMI_BOOL (*AlmCompareCallback)(U8, U8, MMI_BOOL);
#endif

/*****************************************************************************
* Global Variables 
*****************************************************************************/


 /*****************************************************************************
 * Define
 *****************************************************************************/
#ifndef __MMI_DEV_NEW_SLIM__
#define ALARM_DEFAULT_RING_ID AUD_ID_PROF_RING1
#endif

/*****************************************************************************
 * Local Variables 
 *****************************************************************************/
#ifndef __MMI_DEV_NEW_SLIM__
static U16 gAlmFreqList[ALM_FREQ_TOTAL];   /* array to store frequency type of alarm */
#else
const static U16 gAlmFreqList[ALM_FREQ_TOTAL]=
{
	ALARM_ONCE_STRING,
	ALARM_EVREYDAY_STRING,
	ALARM_DAYS_STRING
};
#endif
static const U8 g_alm_freq_set[ALARM_FREQ_NUM] = {ALM_FREQ_ONCE, ALM_FREQ_EVERYDAY, ALM_FREQ_DAYS};
const static U16 gAlmOnOffString[NUM_STATE_FOR_ALM] =
{
    STR_GLOBAL_OFF,
    STR_GLOBAL_ON
};  /* array to store on/off state of an alarm */
static U8 gAlmDaysStates[NUM_DAYS];                    /* signifies the days alarm has been set for in case of freq weekdays */
#ifdef __ORIGINAL_DOW__
static U8 gAlmZeroDaysStates[NUM_DAYS];
#endif
#ifdef __MMI_ALM_CUST_VOLUME__
const static U16 gAlmVolumeList[LEVEL7 + 1] =
{
    STR_GLOBAL_1,
    STR_GLOBAL_2,
    STR_GLOBAL_3,
    STR_GLOBAL_4,
    STR_GLOBAL_5,
    STR_GLOBAL_6,
    STR_GLOBAL_7
};
#endif /* __MMI_ALM_CUST_VOLUME__ */ 

#ifdef __MMI_ALM_SNOOZE_SETTING__
const static U16 gAlmSettingSnooze[ALM_SNOOZE_INTERVAL_SETTING_NUM] =
{
	 STR_GLOBAL_OFF,
	 STR_GLOBAL_1,
	 STR_GLOBAL_3,
	 STR_GLOBAL_5,
	 STR_GLOBAL_10
};


#endif 
#ifdef __MMI_ALM_ALERT_TYPE__
#ifndef __MMI_DEV_NEW_SLIM__
static U16 gAlmSettingAlertType[ALM_ALERT_TYPE_SETTING_NUM];
#else
const static U16 gAlmSettingAlertType[ALM_ALERT_TYPE_SETTING_NUM]=
{
	STR_ID_PROF_VIB_AND_RING,
	STR_ID_PROF_RING_ONLY,
	STR_ID_PROF_VIB_ONLY
};
#endif 
#endif
/*
 *  use can select fmradio as alarm tone
 */
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
const static U16 g_alm_audio_options_string[NUM_AUDIO_OPTIONS] =
{
    STR_ID_ALM_AUDIO_OPTIONS_TONE,
    STR_ID_ALM_AUDIO_OPTIONS_FMRADIO
};  /* array to store the audio option strings */

static U8 g_alm_aud_opt_fmrdo_channel_index;
static U16 g_alm_fmrdo_prev_freq;
static UI_character_type channel_manual_input_buffer[MAX_MANUAL_INPUT_LEN];
static BOOL g_alm_fmrdo_read_channel_name = FALSE;

#endif
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
static U16 g_alm_audio_options_curselitem[MAX_NAME_INPUT_LEN];
static U16 g_alm_prev_audio_option_value;
static U16 g_alm_prev_tone_value;

static S32 g_alm_audio_option_previndex;                   /* the index of the selected audio option i.e. FM or tone. */

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
static U16 g_alm_tone_curselitem[MAX_EXT_MELODY_NAME_WIDTH];
#else /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */
static U16 g_alm_tone_curselitem[(41 + 1) * ENCODING_LENGTH];
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 
#endif

static U8 g_alm_tone_path[SRV_FMGR_PATH_BUFFER_SIZE];
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */

static void mmi_alm_display_popup(void);


/* Dummy data for inline data */
static const cui_inline_item_caption_struct g_mmi_alm_inline_caption_data[]  = 
{
    {ALARM_REPEAT_STRING},
    {STR_GLOBAL_VOLUME},
#ifdef __MMI_ALM_CUSTOMIZE_TONE__         
    {STR_ID_ALM_AUDIO_OPTIONS},
#else
    {STR_GLOBAL_EMPTY},
#endif
    {ALARMS_SETTING_SNOOZE_INTERVAL},
    {STR_ID_PROF_ALERT_TYPE},
//#ifdef __MMI_INLINE_SLIM__    
#ifdef __MMI_DEV_NEW_SLIM__
    {STR_GLOBAL_STATUS},
#endif
#ifdef __MMI_DEV_NEW_SLIM__
	{STR_GLOBAL_TIME}
#endif
};

static const cui_inline_item_select_struct g_mmi_alm_inline_select_state = 
{
    2, 0, gAlmOnOffString
};

#ifdef __ORIGINAL_DOW__
static const cui_inline_item_select_struct g_mmi_alm_inline_select_repeat = 
{
    ALARM_FREQ_NUM, 0, gAlmFreqList
};
#endif

#ifdef __MMI_ALM_CUST_VOLUME__
static const cui_inline_item_select_struct g_mmi_alm_inline_select_vol =   
{
    LEVEL7 + 1, 0, gAlmVolumeList
};
#endif

#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
static const cui_inline_item_select_struct g_mmi_alm_inline_select_audio =  
{
    NUM_AUDIO_OPTIONS, 0, g_alm_audio_options_string
};
#endif

#ifdef __MMI_ALM_SNOOZE_SETTING__
static const cui_inline_item_select_struct g_mmi_alm_inline_select_snooze = 
{
    ALM_SNOOZE_INTERVAL_SETTING_NUM, 3, gAlmSettingSnooze
};
#endif

#ifdef __MMI_ALM_ALERT_TYPE__
static const cui_inline_item_select_struct g_mmi_alm_inline_select_alert = 
{
    ALM_ALERT_TYPE_SETTING_NUM, 0, gAlmSettingAlertType
};
#endif /* __MMI_ALM_ALERT_TYPE__ */

#ifdef __MMI_ALM_CUSTOMIZE_TONE__
static const cui_inline_item_display_only_struct g_mmi_alm_fake_inline_display_only_data = 
{
    STR_GLOBAL_0, STR_GLOBAL_0
};
#endif

static const cui_inline_item_time_struct g_mmi_alm_inline_time = 
{
    {0, 0, 0, 0, 0, 0}, 0
};

#ifdef __ORIGINAL_DOW__
static const cui_inline_item_dow_select_struct g_mmi_alm_inline_dow_data = 
{
    (PU8)gAlmDaysStates
};
#endif

/* inline item */
static const cui_inline_set_item_struct g_mmi_alm_inline_item[MMI_ALM_INLINE_TOTAL] = 
{
    /* on-off status caption */
//#ifdef __MMI_INLINE_SLIM__
#ifdef __MMI_DEV_NEW_SLIM__
#ifndef __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_STATUS_CAPTION, 
     CUI_INLINE_ITEM_TYPE_CAPTION, 
		 0, 
     &g_mmi_alm_inline_caption_data[5]},
#endif 
#endif     
    /* on-off status */
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_STATUS, 
     CUI_INLINE_ITEM_TYPE_SELECT, 
#ifdef __MMI_DEV_NEW_SLIM__
     0,
#else
     IMG_STATUS, 
#endif
     (void*)&g_mmi_alm_inline_select_state},

    /* time */
#ifdef __MMI_DEV_NEW_SLIM__
#ifndef __MMI_MAINLCD_96X64__
		{CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TIME_CAPTION, 
		 CUI_INLINE_ITEM_TYPE_CAPTION, 	
		 0,
		 &g_mmi_alm_inline_caption_data[6]},
#endif
#endif
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TIME,   
     CUI_INLINE_ITEM_TYPE_TIME, 
 #ifdef __MMI_DEV_NEW_SLIM__
     0,
 #else
     IMG_TIME, 
 #endif
     &g_mmi_alm_inline_time},
#ifdef __MMI_ALM_SNOOZE_SETTING__
#ifndef __MMI_MAINLCD_96X64__
	 {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_SNOOZE_CAPTION, 
	  CUI_INLINE_ITEM_TYPE_CAPTION, 
	  0, 
	  &g_mmi_alm_inline_caption_data[3]},
#endif	  
	 {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_SNOOZE,		   
	  CUI_INLINE_ITEM_TYPE_SELECT, 
	  0, 
	  &g_mmi_alm_inline_select_snooze},

#endif /* __MMI_ALM_SNOOZE_SETTING__ */
     
    /* repeat caption */
#ifndef __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_REPEAT_CAPTION, 
     CUI_INLINE_ITEM_TYPE_CAPTION, 
  #ifdef __MMI_DEV_NEW_SLIM__
     0,
  #else
     IMG_REPEAT, 
  #endif
     &g_mmi_alm_inline_caption_data[0]},
#endif

#ifndef __ORIGINAL_DOW__
    /* repeat */
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_REPEAT,         
     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 
     0, 
     NULL},
#else
    /* repeat */
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_REPEAT,         
     CUI_INLINE_ITEM_TYPE_SELECT, 
     0, 
     &g_mmi_alm_inline_select_repeat},

    /* day of week */
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_DOW,    
     CUI_INLINE_ITEM_TYPE_DOW | CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT | CUI_INLINE_ITEM_FULL_WIDTH, 
     0, 
     &g_mmi_alm_inline_dow_data},
#endif /* __ORIGINAL_DOW__ */

#ifdef __MMI_ALM_CUST_VOLUME__
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_CUST_VOL_CAPTION, 
     CUI_INLINE_ITEM_TYPE_CAPTION, 
     ALARM_VOLUME_IMAGEID, 
     &g_mmi_alm_inline_caption_data[1]},
     
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_CUST_VOL,         
     CUI_INLINE_ITEM_TYPE_SELECT, 
     0, 
     &g_mmi_alm_inline_select_vol},
#endif 

#ifdef __MMI_ALM_CUSTOMIZE_TONE__
#ifndef __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_CAPTION, 
     CUI_INLINE_ITEM_TYPE_CAPTION, 
   #ifdef __MMI_DEV_NEW_SLIM__
   	 0,
   #else
     IMG_ALM_AUD_OPT, 
   #endif
     &g_mmi_alm_inline_caption_data[2]},
#endif
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__     
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_SELECT, 
     CUI_INLINE_ITEM_TYPE_SELECT, 
     0, 
     &g_mmi_alm_inline_select_audio},
#endif     
    
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 
     0, 
     &g_mmi_alm_fake_inline_display_only_data},
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */

#ifdef __MMI_ALM_ALERT_TYPE__
#ifndef __MMI_MAINLCD_96X64__
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_ALERT_TYPE_CAPTION,
     CUI_INLINE_ITEM_TYPE_CAPTION, 
  #ifdef __MMI_DEV_NEW_SLIM__   
     0,
  #else
     ALARMS_SET_ALERT_TYPE_IMAGEID, 
  #endif
     &g_mmi_alm_inline_caption_data[4]},
#endif
     
    {CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_ALERT_TYPE,        
     CUI_INLINE_ITEM_TYPE_SELECT,
     0, 
     &g_mmi_alm_inline_select_alert}
#endif /* __MMI_ALM_ALERT_TYPE__ */

};

#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
static const cui_inline_item_text_edit_struct g_mmi_alm_inline_man_text = 
{
    0, 
    0, 
    MAX_MANUAL_INPUT_LEN, 
    IMM_INPUT_TYPE_DECIMAL_NUMERIC, 
    0, 
    NULL
};

static const cui_inline_set_item_struct g_mmi_alm_inline_man_item = 
{
    CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_alm_inline_man_text
};


/* group id for inline man input */
static MMI_ID g_mmi_alm_inline_grp_id;


static const cui_inline_struct g_mmi_alm_man_input_inline_data = 
{
    1,
    STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_MAN_INPUT,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    &g_mmi_alm_inline_man_item
};
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */

static const cui_inline_struct g_mmi_alm_edit_inline_data = 
{
    sizeof(g_mmi_alm_inline_item)/sizeof(cui_inline_set_item_struct),
    STR_GLOBAL_EDIT,
    0,
    0,
    NULL,
    g_mmi_alm_inline_item
};
#define MMI_ALM_MAX_REPEAT_TIME_STRING_LEN (MAX_SUBMENU_CHARACTERS)
static WCHAR g_mmi_alm_repeat_time_string[MMI_ALM_MAX_REPEAT_TIME_STRING_LEN];

/*****************************************************************************
 * Local function 
 *****************************************************************************/
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
static void mmi_alm_entry_fmrdo_manual_input_opt_done(void);
static void mmi_alm_entry_fmrdo_manual_input_opt_play(void);
static U16 mmi_alm_get_fm_channel_freq(U16 channel_index);
static CHAR* mmi_alm_get_fm_channel_name(U16 channel_index);
static MMI_BOOL mmi_alm_is_valid_freq(U16 freq);
static MMI_BOOL mmi_alm_get_tone_string(CHAR** tone_string);
#endif 
static WCHAR* mmi_alm_inline_get_repeat_type_string(void);

static mmi_ret mmi_alm_group_proc(mmi_event_struct* evt);
static void mmi_alm_entry_alm_list_scrn(mmi_scrn_essential_struct* scrn_data);
#ifndef __MMI_DEV_NEW_SLIM__
static U16 mmi_alm_get_curr_group(void);
static void mmi_alm_set_curr_group(U16 grp_id);
#endif

static void EntryAlmEditScreen(MMI_ID parent_id);
static MMI_BOOL mmi_alm_is_valid_cust_repeat(U8 repeat_type, U8 *selected_mask);
#ifdef __ORIGINAL_DOW__
static void mmi_alm_entry_disable_alm_confirm(void);
#endif
static void mmi_alm_alert_pop_handler(mmi_alert_result_evt_struct *alert_evt);

#ifndef __ORIGINAL_DOW__
static U8 g_alm_temp_repeat_type;
static U8 g_alm_temp_custom_repeat_week_day[NUM_DAYS];
static S32 g_alm_temp_highlighted_week_day;
static MMI_BOOL g_alm_repeat_type_changed;
#ifndef __MMI_DEV_NEW_SLIM__
typedef enum
{
    ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH,
    ALARM_CUSTOM_OPTIONS_DONE,
    
    ALARM_CUSTOM_OPTIONS_TOTAL
} mmi_alm_custom_options_enum;
#endif
static void mmi_alm_entry_repeat_type_menu(void);
static void mmi_alm_entry_repeat_type_custom_menu(MMI_ID parent_gid);
static void mmi_alm_entry_repeat_type_custom_menu_int(mmi_scrn_essential_struct *data);
static void mmi_alm_entry_repeat_type_custom_option_menu(void);
static void mmi_alm_repeat_type_custom_switch_status(S32 item_index);
static void mmi_alm_repeat_type_custom_csk_hdlr(void);
static mmi_ret mmi_alm_repeat_type_proc(mmi_event_struct *evt);
static void mmi_alm_init_repeat_type_main_menu(MMI_ID cui_gid);
static void mmi_alm_init_custom_options_menu(MMI_ID cui_gid);
#endif
/*****************************************************************************
 * Global Variables 
 *****************************************************************************/
alm_context_struct g_alm_cntx;

#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
extern mmi_fmrdo_struct g_fmrdo;    /* defined in FMRadioSrc.c */
extern pBOOL mmi_fmrdo_channel_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
extern S32 mmi_fmrdo_channel_list_item_hint(S32 item_index, UI_string_type *hint_array);
extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */ 

/*****************************************************************************
 * Global Function
 *****************************************************************************/
#ifdef	__MMI_CALENDAR_FDOW__     // __MMI_DEV_NEW_SLIM__
extern U8 mmi_clndr_get_week_first_day();
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_alm_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_alm_display_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    
    arg.parent_id = GRP_ID_ROOT;//GRP_ID_ALM_EDITOR;
    arg.callback = (mmi_proc_func)NULL;
	g_alm_cntx.user_tag = STR_GLOBAL_SAVED;
    arg.user_tag = &g_alm_cntx.user_tag;
    
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED),
                      MMI_EVENT_SUCCESS, 
                      &arg);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightAlmMenu
 * DESCRIPTION
 *  Highlight handler of alarm menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAlmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_96X64__
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(EntryAlmMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(EntryAlmMenu, KEY_EVENT_UP);
#else
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetLeftSoftkeyFunction(AlmPrepareInlineScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(AlmPrepareInlineScreen, KEY_EVENT_UP);
#endif
}

#ifndef __MMI_DEV_NEW_SLIM__	

/*****************************************************************************
 * FUNCTION
 *  AlmInit
 * DESCRIPTION
 *  Initailization function. Set the highlight handlers and get required strings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* fill inline selection strings */
#ifdef __MMI_ALM_ALERT_TYPE__
    gAlmSettingAlertType[ALM_ALERT_VIBRATION_AND_RING] = STR_ID_PROF_VIB_AND_RING;
    gAlmSettingAlertType[ALM_ALERT_RING] = STR_ID_PROF_RING_ONLY;
    gAlmSettingAlertType[ALM_ALERT_VIBRATION] = STR_ID_PROF_VIB_ONLY;
#endif /* __MMI_ALM_ALERT_TYPE__ */ 

    for (j = 0; j < ALARM_FREQ_NUM; j++)
    {
        gAlmFreqList[j] = g_alm_freq_set[j] + ALARM_ONCE_STRING - 1;
    }    
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
    g_alm_cntx.audio_select = MMI_FALSE;
#endif
}

#endif

/*****************************************************************************
 * FUNCTION
 *  AlmInitNvram
 * DESCRIPTION
 *  Gets the information from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmInitNvram(void)
{
    /*----------------------------------------------------------------*/
#ifdef __MMI_DEV_NEW_SLIM__
	#ifdef __MMI_ALM_CUSTOMIZE_TONE__
    g_alm_cntx.audio_select = MMI_FALSE;
	#endif
	g_alm_cntx.default_tone = ALARM_DEFAULT_RING_ID;
#else
	g_alm_cntx.default_tone = mmi_alm_default_ring_id();
#endif
	g_alm_cntx.active_alm_idx = 0xFF;
	g_alm_cntx.is_tone_playing = MMI_FALSE;

    if (srv_alm_active_alms() != 0)
    {
        AlmActivateIndicator();
    }
    else
    {
        AlmDeactivateIndicator();
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightAlmIndex
 * DESCRIPTION
 *  Highlight handler of alarm item in alarm screen.
 *  Store current highlight index.
 * PARAMETERS
 *  nIndex      [IN]        
 *  S32(?)      [IN]        Index of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAlmIndex(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_cntx.CurrHiliteAlarm = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryAlmMenu
 * DESCRIPTION
 *  Entry function of Alarm application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAlmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DEV_NEW_SLIM__
	mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_ALM_LIST, mmi_alm_group_proc, NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
	g_alm_cntx.curr_gid = GRP_ID_ALM_LIST;
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_ALM_LIST, mmi_alm_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_ALM_LIST, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_alm_set_curr_group(GRP_ID_ALM_LIST);
#endif
	g_alm_cntx.CurrHiliteAlarm = 0;

    mmi_frm_scrn_first_enter(
        GRP_ID_ALM_LIST,
        SCR_ID_ALM_LIST,
        (FuncPtr)mmi_alm_entry_alm_list_scrn,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_alm_list_scrn
 * DESCRIPTION
 *  Entry function of Alarm application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_alm_entry_alm_list_scrn(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 i;
    U16 alarm_states_icon[NUM_OF_ALM];
    MYTIME almTime;
	srv_alm_node_type *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            scrn_data->group_id, 
            SCR_ID_ALM_LIST, 
            NULL, 
            (FuncPtr)mmi_alm_entry_alm_list_scrn, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    /* Use FM radio list before FM radio initialize */
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
    mmi_alm_aud_fmrdo_init_channe_list();
#endif

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    g_alm_cntx.IsDOWSet = 0;

    /* construct displayed string and icon */
    for (i = 0; i < NUM_OF_ALM; i++)
    {
    	node = (srv_alm_node_type *)srv_alm_read(i);
        almTime.nHour = node->Hour;
        almTime.nMin = node->Min;
        time_string(&almTime, (UI_string_type) subMenuDataPtrs[i], DT_IDLE_SCREEN);
#ifdef __MMI_DEV_NEW_SLIM__
	alarm_states_icon[i] = (node->State == SET_STATE ? CHECKBOX_ON_IMAGE_ID : CHECKBOX_OFF_IMAGE_ID);
#else
        if (node->State == SET_STATE)
        {
            alarm_states_icon[i] = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            alarm_states_icon[i] = CHECKBOX_OFF_IMAGE_ID;
        }
#endif   
    }

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);

	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory53Screen(
        STR_GLOBAL_ALARM,
        GetRootTitleIcon(ORGANIZER_ALARM_MENU),
        STR_GLOBAL_EDIT,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NUM_OF_ALM,
        subMenuDataPtrs,
        alarm_states_icon,
        0,
        0,
        (S32) g_alm_cntx.CurrHiliteAlarm,
        guiBuffer);
    wgui_restore_list_menu_slim_style();

    SetLeftSoftkeyFunction(AlmPrepareInlineScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

	SetCenterSoftkeyFunction(AlmPrepareInlineScreen, KEY_EVENT_UP);

    RegisterHighlightHandler(HighlightAlmIndex);
}


/*****************************************************************************
 * FUNCTION
 *  EntryAlmSaveConfirmation
 * DESCRIPTION
 *  Display confirmation screen for setting alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAlmSaveConfirmation(void)
{
    #ifndef __MMI_DEV_NEW_SLIM__
    mmi_confirm_property_struct arg_confirm;
	#endif
    mmi_popup_property_struct arg_popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check if the currently selected option is ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL and some channel is selected for it */
    #ifdef __MMI_ALM_FM_RADIO_SUPPORT__
    if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL)
    {
        U16 index;
        BOOL valid_chan = TRUE;

        if (g_alm_cntx.CurrHiliteAudioOptionValue == 0 || 
            g_alm_cntx.CurrHiliteAudioOptionValue > FM_RADIO_CHANNEL_NUM)
        {
            valid_chan = FALSE;
        }
        else
        {
            index = g_alm_cntx.CurrHiliteAudioOptionValue - 1;
            if (!mmi_alm_is_valid_freq(mmi_alm_get_fm_channel_freq(index)))
            {
                valid_chan = FALSE;
            }
        }

        if (!valid_chan)
        {                                     
            mmi_popup_property_init(&arg_popup);
        
            arg_popup.parent_id = GRP_ID_ALM_EDITOR;
            arg_popup.callback = (mmi_proc_func)NULL;
            g_alm_cntx.user_tag = STR_ID_ALM_FMRDO_INCOMPLETE_CHANNEL_INFO;
            arg_popup.user_tag = &g_alm_cntx.user_tag;
            
            mmi_popup_display((WCHAR*)GetString(STR_ID_ALM_FMRDO_INCOMPLETE_CHANNEL_INFO),
                              MMI_EVENT_FAILURE, 
                              &arg_popup); 

            return;
        }
    }
    #endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */
	
	#ifdef	__MMI_ALM_CUSTOMIZE_TONE__
    if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_TONE &&
        g_alm_cntx.CurrHiliteAudioOptionValue == ALARM_TONE_FILE)
    {
    	S32 error_code = srv_fmgr_fs_path_exist((WCHAR *)g_alm_cntx.tone_path);
        if (error_code < 0)
        {
            mmi_popup_property_init(&arg_popup);
        
            arg_popup.parent_id = GRP_ID_ALM_EDITOR;
            arg_popup.callback = (mmi_proc_func)NULL;
            g_alm_cntx.user_tag = STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
            arg_popup.user_tag = &g_alm_cntx.user_tag;
            
            mmi_popup_display((WCHAR*)GetString(STR_ID_ALM_AUDIO_OPTIONS_TONE_FILE_NOT_AVAILABLE),
                              MMI_EVENT_FAILURE, 
                              &arg_popup); 
            return;
        }
    }
    #endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 

#if 0  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  AlmPrepareInlineScreen
 * DESCRIPTION
 *  This fuction builds the display information of the selected alarm, and then enter
 *  alarm screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmPrepareInlineScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 j;
	srv_alm_node_type *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_MAINLCD_96X64__
	g_alm_cntx.curr_gid = GRP_ID_ROOT;
	g_alm_cntx.CurrHiliteAlarm = 0;
	#endif


	node = (srv_alm_node_type *)srv_alm_read(g_alm_cntx.CurrHiliteAlarm);

    g_alm_cntx.curr_hour = node->Hour;
    g_alm_cntx.curr_min = node->Min;

    g_alm_cntx.CurrHiliteState = node->State;
    g_alm_cntx.CurrHiliteFreq = mmi_alm_get_order_in_alm_freq(node->Freq);

#ifdef __MMI_ALM_CUST_VOLUME__
    g_alm_cntx.CurrHiliteVol = node->Volume;
#endif 

    if (g_alm_freq_set[g_alm_cntx.CurrHiliteFreq] == ALM_FREQ_DAYS)     /* not Days */
    {
        for (j = 0; j < NUM_DAYS; j++)
        {
            gAlmDaysStates[j] = ((((node->Days) & (0x1 << j)) == 0) ? 0 : 1);
        }
    }
    else
    {
        memset(gAlmDaysStates, 0, 7);
    }

    /* Audio options in alarm */
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
    g_alm_cntx.CurrHiliteAudioOption = node->AudioOption;
    #ifdef __MMI_ALM_FM_RADIO_SUPPORT__    
    if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL)
    {
        U16 freq = 0;
        U16 index = g_alm_cntx.CurrHiliteAudioOptionValue = node->AudioOptionValue;
        
        if ((index > 0) && (index <= FM_RADIO_CHANNEL_NUM))
        {
            freq = mmi_alm_get_fm_channel_freq(index - 1);
        }

        /* In invalid frequency, restore to default ring tone */
        if (!mmi_alm_is_valid_freq(freq))
        {
            g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_TONE;
	#ifndef __MMI_DEV_NEW_SLIM__ 
            g_alm_cntx.CurrHiliteAudioOptionValue = mmi_alm_default_ring_id();
    #else
			g_alm_cntx.CurrHiliteAudioOptionValue =ALARM_DEFAULT_RING_ID;
	#endif	
        }
        g_alm_prev_audio_option_value = g_alm_cntx.CurrHiliteAudioOptionValue;
    }
    else if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_MANUAL)
    {
        g_alm_cntx.CurrHiliteAudioOptionValue = node->AudioOptionValue;
        g_alm_prev_audio_option_value = g_alm_cntx.CurrHiliteAudioOptionValue;
    }
    else    /* ALM_AUDIO_OPTIONS_TONE */
    #endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */
    {
        if (node->AudioOptionValue > 0)
        {
            g_alm_cntx.CurrHiliteAudioOptionValue = node->AudioOptionValue;
            if (node->AudioOptionValue == ALARM_TONE_FILE)
            {
                mmi_ucs2cpy((CHAR *)g_alm_cntx.tone_path, (CHAR *)node->tone_path);
            }
        }
        else
        {
    #ifndef __MMI_DEV_NEW_SLIM__ 
            g_alm_cntx.CurrHiliteAudioOptionValue = mmi_alm_default_ring_id();
    #else
			g_alm_cntx.CurrHiliteAudioOptionValue =ALARM_DEFAULT_RING_ID;
	#endif
        }
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__ 		
        g_alm_prev_tone_value= g_alm_cntx.CurrHiliteAudioOptionValue;
#endif
    }
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 

#ifdef __MMI_ALM_SNOOZE_SETTING__
    //g_alm_cntx.CurrHilightSnoozeInterval = node->SnoozeInterval - 1;
	if (node->SnoozeInterval == 0)
    {
        g_alm_cntx.CurrHilightSnoozeInterval = ALARM_SNOOZE_OFF;
    }
    if (node->SnoozeInterval == 1)
    {
        g_alm_cntx.CurrHilightSnoozeInterval = ALARM_SNOOZE_PERIOD_ONE;
    }
    if (node->SnoozeInterval == 3)
    {
        g_alm_cntx.CurrHilightSnoozeInterval = ALARM_SNOOZE_PERIOD_THREE;
    }  
    if (node->SnoozeInterval == 5)
    {
        g_alm_cntx.CurrHilightSnoozeInterval = ALARM_SNOOZE_PERIOD_FIVE;
    }
    if (node->SnoozeInterval == 10)
    {
        g_alm_cntx.CurrHilightSnoozeInterval = ALARM_SNOOZE_PERIOD_TEN;
    }
#endif 

#ifdef __MMI_ALM_ALERT_TYPE__
    g_alm_cntx.CurrHilightAlertType = node->AlertType;
#endif 

    if (mmi_frm_group_is_present(GRP_ID_ALM_LIST))
    {
        EntryAlmEditScreen(GRP_ID_ALM_LIST);
    }
    else
    {
	EntryAlmEditScreen(GRP_ID_ROOT);
    }
}

#ifdef __ORIGINAL_DOW__
/*****************************************************************************
 * FUNCTION
 *  HighlightAlmInlineRepeat
 * DESCRIPTION
 *  Highlight handler of Repeat inline selection item in editor screen.
 *  Enable DOW component when selecting "Days"
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAlmInlineRepeat(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_alm_freq_set[index] == ALM_FREQ_DAYS)
    {
    	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(g_alm_cntx.CurrHiliteAlarm);
		
        if (g_alm_cntx.IsDOWSet == 0)
        {
            /* if the user did not select DOW yet */
            if (node->Days == 0)
            {
                memset(gAlmDaysStates, 1, 7);
                gAlmDaysStates[0] = 0;
                gAlmDaysStates[6] = 0;
            }

            g_alm_cntx.IsDOWSet = 1;
            
            cui_inline_set_value(g_alm_cntx.curr_gid, 
                                 CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_DOW,
                                 gAlmDaysStates);
            
            cui_inline_set_item_attributes(g_alm_cntx.curr_gid, 
                                CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_DOW,
                                CUI_INLINE_RESET_ATTRIBUTE,
                                CUI_INLINE_ITEM_DISABLE);
        }
    }
    else
    {
        g_alm_cntx.IsDOWSet = 0;
		
		cui_inline_set_value(g_alm_cntx.curr_gid, 
							 CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_DOW,
							 gAlmZeroDaysStates);

        
        cui_inline_set_item_attributes(g_alm_cntx.curr_gid, 
                                       CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_DOW,
                                       CUI_INLINE_SET_ATTRIBUTE,
                                       CUI_INLINE_ITEM_DISABLE);
    }

    cui_inline_redraw_screen(g_alm_cntx.curr_gid);
}
#endif /* __ORIGINAL_DOW__ */


#ifdef __MMI_ALM_CUSTOMIZE_TONE__
/*****************************************************************************
 * FUNCTION
 *  mmi_alarm_entry_tone_selector
 * DESCRIPTION
 *  When the external file is deleted, Profile will call the function to update ring tone id.
 * PARAMETERS
 *  ToneId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alarm_entry_tone_selector(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id ts_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ts_gid = cui_tone_selector_create(GRP_ID_ALM_EDITOR)) != GRP_ID_INVALID)
    {
        U16 filter = 0;
        
        CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_RING);
        CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_DLT_RING);
        CUI_TONE_SELECTOR_FILTER_SET(filter, CUI_TONE_SELECTOR_FILTER_EXT_FILE);
        cui_tone_selector_set_filter(ts_gid, filter);
        cui_tone_selector_set_title_id(ts_gid, STR_ID_ALM_AUDIO_OPTIONS, GetRootTitleIcon(MAIN_MENU_ORGANIZER_MENUID));
        
        if (g_alm_cntx.CurrHiliteAudioOptionValue != ALARM_TONE_FILE)
{
            cui_tone_selector_set_highlight_tone (ts_gid, g_alm_cntx.CurrHiliteAudioOptionValue);
    }

        cui_tone_selector_run(ts_gid);
    }
}
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 

#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_aud_opt_fmrdo
 * DESCRIPTION
 *  The entry function for the screen displaying options for fmradio audio option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_alm_entry_aud_opt_fmrdo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    mmi_id cui_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_create(GRP_ID_ALM_EDITOR, 
                                  GRP_ID_ALM_AUDIO_OPTION, 
                                  mmi_alm_group_proc, 
                                  NULL);

    mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
#ifdef __MMI_DEV_NEW_SLIM__

	cui_menu_id = cui_menu_create_and_run(grp_id, 
                                  CUI_MENU_SRC_TYPE_RESOURCE, 
                                  CUI_MENU_TYPE_OPTION, 
                                  MENU_ID_ALM_AUDIO_OPT_FMRADIO, 
                                  MMI_FALSE, 
                                  NULL);
#else

    cui_menu_id = cui_menu_create(grp_id, 
                                  CUI_MENU_SRC_TYPE_RESOURCE, 
                                  CUI_MENU_TYPE_OPTION, 
                                  MENU_ID_ALM_AUDIO_OPT_FMRADIO, 
                                  MMI_FALSE, 
                                  NULL);

    cui_menu_run(cui_menu_id);

#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_aud_opt_fmrdo_channel_list
 * DESCRIPTION
 *  The entry function for the screen displaying the FM channels.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_aud_opt_fmrdo_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
            GRP_ID_ALM_AUDIO_OPTION, 
            SCR_ID_ALM_AUDIO_OPT_FMRADIO_CHANNEL_LIST, 
            NULL, 
            mmi_alm_entry_aud_opt_fmrdo_channel_list, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    //EntryNewScreen(SCR_ID_ALM_AUDIO_OPT_FMRADIO_CHANNEL_LIST, NULL, mmi_alm_entry_aud_opt_fmrdo_channel_list, NULL);

    /* register highlight handler */
    RegisterHighlightHandler(mmi_alm_aud_opt_fmrdo_channel_list_highlight_hdlr);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();//GetCurrGuiBuffer(SCR_ID_ALM_AUDIO_OPT_FMRADIO_CHANNEL_LIST);

    if (gui_buffer == NULL)
    {
        if ((g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL) &&
            (g_alm_cntx.CurrHiliteAudioOptionValue > 0))
        {
            g_alm_aud_opt_fmrdo_channel_index = g_alm_cntx.CurrHiliteAudioOptionValue - 1;
        }
        else
        {
            g_alm_aud_opt_fmrdo_channel_index = 0;
        }
    }

	EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);

    ShowCategory184Screen(
        STR_ID_ALM_AUDIO_OPTIONS_FMRADIO_CHANNELLIST,
        GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        FM_RADIO_CHANNEL_NUM,
        mmi_fmrdo_channel_list_item,
        mmi_fmrdo_channel_list_item_hint,
        g_alm_aud_opt_fmrdo_channel_index,
        gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_opt_fmrdo_channel_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for the FM Channels Screen.
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_aud_opt_fmrdo_channel_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_aud_opt_fmrdo_channel_index = index;

    if (mmi_alm_get_fm_channel_freq(g_alm_aud_opt_fmrdo_channel_index) == 0)
    {
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ChangeLeftSoftkey(0, 0);
	ChangeCenterSoftkey(0, 0);
    }
    else
    {// Wen comment
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_alm_entry_aud_opt_fmrdo_channel_options, KEY_EVENT_UP);
	    ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        SetCenterSoftkeyFunction(mmi_alm_entry_aud_opt_fmrdo_channel_options, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_aud_opt_fmrdo_channel_options
 * DESCRIPTION
 *  The entry function for the channel options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_aud_opt_fmrdo_channel_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    mmi_id cui_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    grp_id = mmi_frm_group_create(GRP_ID_ALM_AUDIO_OPTION, 
                                  GRP_ID_ALM_AUDIO_FM_CHANNEL_OPTION, 
                                  mmi_alm_group_proc, 
                                  NULL);

    mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_id = cui_menu_create(grp_id, 
                                  CUI_MENU_SRC_TYPE_APPCREATE, 
                                  CUI_MENU_TYPE_OPTION, 
                                  MENU_ID_ALM_FMRADIO_CHANNEL_LIST_OPTION, 
                                  MMI_FALSE, 
                                  NULL);

    cui_menu_run(cui_menu_id);

    //SetKeyHandler(mmi_alm_aud_opt_fmrdo_channel_opt_lsk_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_opt_fmrdo_channel_opt_select
 * DESCRIPTION
 *  LSK function for the FM Radio channel options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_alm_aud_opt_fmrdo_channel_opt_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL;
    g_alm_cntx.CurrHiliteAudioOptionValue = g_alm_aud_opt_fmrdo_channel_index + 1;
    g_alm_prev_audio_option_value = g_alm_cntx.CurrHiliteAudioOptionValue;
    
    g_alm_cntx.audio_select = MMI_TRUE;
    mmi_frm_group_close(GRP_ID_ALM_AUDIO_OPTION);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_opt_fmrdo_channel_opt_play
 * DESCRIPTION
 *  LSK function for the FM Radio channel options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_alm_aud_opt_fmrdo_channel_opt_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     g_alm_fmrdo_prev_freq = mmi_alm_get_fm_channel_freq(g_alm_aud_opt_fmrdo_channel_index);
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
    else
#endif /* __MMI_BACKGROUND_CALL__ */
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (!srv_earphone_is_plug_in())
    {
        mmi_popup_property_struct arg;
        /*
    	mmi_display_popup_with_sg(
            GRP_ID_ALM_AUDIO_OPTION,
            (UI_string_type) GetString(STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE), 
            MMI_EVENT_INFO,
            0); */
        mmi_popup_property_init(&arg);
    
        arg.parent_id = GRP_ID_ALM_AUDIO_OPTION;
        arg.callback = (mmi_proc_func)NULL;
        g_alm_cntx.user_tag = STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE;
        arg.user_tag = &g_alm_cntx.user_tag;
        
        mmi_popup_display((WCHAR*)GetString(STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE),
                          MMI_EVENT_INFO, 
                          &arg); 
    }
    else
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
    {
        mmi_alm_entry_fmrdo_prev_channel();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_manual_input_inline_group_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_alm_manual_input_inline_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    
//#ifdef __MMI_ALM_AUDIO_OPTIONS__           
         case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    
                /* mannual input */
                if (menu_evt->parent_menu_id == MENU_ID_ALM_FMRADIO_MAN_INPUT_OPTION)
                {
                    mmi_menu_id menu_list[2] = {
                            MENU_ID_ALM_FMRADIO_OPTION_DONE, 
                            MENU_ID_ALM_FMRADIO_OPTION_PREVIEW
                        };
					
		    cui_menu_set_default_title_image(menu_evt->sender_id, (UI_image_type)GetImage(GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID)));
                    cui_menu_set_default_title_string(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_OPTIONS));
                    cui_menu_set_currlist(menu_evt->sender_id, 2, menu_list);
                    cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_ALM_FMRADIO_OPTION_DONE, (WCHAR*)GetString(STR_GLOBAL_DONE));
                    cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_ALM_FMRADIO_OPTION_PREVIEW, (WCHAR*)GetString(STR_GLOBAL_PLAY));
                }
            }
            break;
            
        case EVT_ID_CUI_MENU_LIST_EXIT:
            {
            }
            break;
            
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
            }
            break;
            
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
                if (menu_evt->parent_menu_id == MENU_ID_ALM_FMRADIO_MAN_INPUT_OPTION)
                {
                    if (menu_evt->highlighted_menu_id == MENU_ID_ALM_FMRADIO_OPTION_DONE)
                    {
                        mmi_alm_entry_fmrdo_manual_input_opt_done();
                    }
                    else if (menu_evt->highlighted_menu_id == MENU_ID_ALM_FMRADIO_OPTION_PREVIEW)
                    {
                        mmi_alm_entry_fmrdo_manual_input_opt_play();
                    }                
                }
           }
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;
//#endif /* __MMI_ALM_AUDIO_OPTIONS__ */
        case EVT_ID_POPUP_QUIT:
        {
	    if (evt->user_data != NULL)
	    {
                U16 grp_id = *(U16 *)evt->user_data;
                mmi_frm_group_close(grp_id);
           }        
        }        
        break;
        //INLINE item
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        { 

            break;
    		}
        case EVT_ID_CUI_INLINE_NOTIFY:
            {
			cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)evt;
			if (notify->event_type == CUI_INLINE_NOTIFY_TEXT_EMPTY)
			{
				cui_inline_set_softkey_text(g_mmi_alm_inline_grp_id,
								CUI_INLINE_ITEM_ID_BASE,
								MMI_LEFT_SOFTKEY,
								0);
				SetLeftSoftkeyFunction(0, KEY_EVENT_UP);
				cui_inline_set_softkey_text(g_mmi_alm_inline_grp_id,
								CUI_INLINE_ITEM_ID_BASE,
								MMI_LEFT_SOFTKEY,
								0);				
				ChangeCenterSoftkey(0, 0);
				SetCenterSoftkeyFunction(0, KEY_EVENT_UP);

            }
	    else if (notify->event_type == CUI_INLINE_NOTIFY_TEXT_NOT_EMPTY)
            {
				cui_inline_set_softkey_text(g_mmi_alm_inline_grp_id,
											CUI_INLINE_ITEM_ID_BASE,
											MMI_LEFT_SOFTKEY,
											STR_GLOBAL_OPTIONS);
				
				SetLeftSoftkeyFunction(mmi_alm_fmrdo_manual_input_options, KEY_EVENT_UP);
				ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
				SetCenterSoftkeyFunction(mmi_alm_fmrdo_manual_input_options, KEY_EVENT_UP);				
            }
            break;
		}
                 
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            mmi_alm_fmrdo_manual_input_options();
            break;
        }    
                
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(g_mmi_alm_inline_grp_id);
            break;
        }
                
        case EVT_ID_CUI_INLINE_GROUP_DEINIT:
        {

        }
        break;
    
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_fmrdo_manual_input
 * DESCRIPTION
 *  The entry function for the manual input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_fmrdo_manual_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_frm_group_create(GRP_ID_ALM_AUDIO_OPTION, 
                          GRP_ID_ALM_AUDIO_OPTION_MAN_INPUT, 
                          mmi_alm_manual_input_inline_group_proc, 
                          NULL);
    
      mmi_frm_group_enter(GRP_ID_ALM_AUDIO_OPTION_MAN_INPUT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    g_mmi_alm_inline_grp_id = cui_inline_create(GRP_ID_ALM_AUDIO_OPTION_MAN_INPUT, &g_mmi_alm_man_input_inline_data);

    if (g_mmi_alm_inline_grp_id != GRP_ID_INVALID)
    {
        cui_inline_set_title_icon(g_mmi_alm_inline_grp_id, GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID));

		/* The previous one is Channel list */
		if (g_alm_prev_audio_option_value > 0 && g_alm_prev_audio_option_value <= FM_RADIO_CHANNEL_NUM)
		{
			U16 list_index = g_alm_prev_audio_option_value - 1;
			
			kal_wsprintf(
				channel_manual_input_buffer,
				"%d.%d",
				mmi_alm_get_fm_channel_freq(list_index) / 10,
				mmi_alm_get_fm_channel_freq(list_index) % 10);
		}
		else if (g_alm_cntx.CurrHiliteAudioOption != ALM_AUDIO_OPTIONS_FMRADIO_MANUAL || g_alm_cntx.CurrHiliteAudioOptionValue == 0)
		{
			memset(channel_manual_input_buffer, 0, 2);
		}
		else
		{
			kal_wsprintf(
				channel_manual_input_buffer,
				"%d.%d",
				g_alm_cntx.CurrHiliteAudioOptionValue / 10,
				g_alm_cntx.CurrHiliteAudioOptionValue % 10);
		}

        cui_inline_set_item_text_edit(g_mmi_alm_inline_grp_id, 
                                      CUI_INLINE_ITEM_ID_BASE, 
                                      channel_manual_input_buffer, 
                                      MAX_MANUAL_INPUT_LEN, 
                                      IMM_INPUT_TYPE_DECIMAL_NUMERIC, 
                                      0, 
                                      NULL, 
                                      0);

        cui_inline_set_item_attributes(g_mmi_alm_inline_grp_id, 
                                        CUI_INLINE_ITEM_ID_BASE, 
                                        CUI_INLINE_SET_ATTRIBUTE, 
                                        CUI_INLINE_ITEM_LEFT_JUSTIFY | CUI_INLINE_ITEM_FULL_WIDTH | CUI_INLINE_ITEM_BOUNDARY);
        cui_inline_run(g_mmi_alm_inline_grp_id);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_ALM_AUDIO_OPTION_MAN_INPUT);
    }
}


MMI_BOOL mmi_alm_fmrdo_check_freq_and_popup(U16 *input_freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(g_mmi_alm_inline_grp_id, 
                         CUI_INLINE_ITEM_ID_BASE + 0, 
                         channel_manual_input_buffer);
    
    freq = mmi_fmrdo_get_freq_from_str(channel_manual_input_buffer);

    if (freq == 0xffff) 
    {
        mmi_popup_property_struct arg;

        mmi_popup_property_init(&arg);
    
        arg.parent_id = GRP_ID_ALM_AUDIO_OPTION_MAN_INPUT;
        arg.callback = (mmi_proc_func)NULL;
        g_alm_cntx.user_tag = STR_ID_FMRDO_VALID_FM_DECIMAL;
        arg.user_tag = &g_alm_cntx.user_tag;
        
        mmi_popup_display((WCHAR*)GetString(STR_ID_FMRDO_VALID_FM_DECIMAL),
                          MMI_EVENT_FAILURE, 
                          &arg); 

	return MMI_FALSE;
    }
    else if (!mmi_alm_is_valid_freq(freq)) 
    {
        mmi_popup_property_struct arg;

        mmi_popup_property_init(&arg);
    
        arg.parent_id = GRP_ID_ALM_AUDIO_OPTION_MAN_INPUT;
        arg.callback = (mmi_proc_func)NULL;
        g_alm_cntx.user_tag = STR_ID_ALM_FMRDO_VALID_FM_BANDWIDTH;
        arg.user_tag = &g_alm_cntx.user_tag;
        
        mmi_popup_display((WCHAR*)GetString(STR_ID_ALM_FMRDO_VALID_FM_BANDWIDTH),
                          MMI_EVENT_FAILURE, 
                          &arg); 

	return MMI_FALSE;
    }

    *input_freq = freq;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_fmrdo_manual_input_options
 * DESCRIPTION
 *  The LSK function for manual input screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_fmrdo_manual_input_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        mmi_alm_entry_fmrdo_manual_input_options();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_fmrdo_manual_input_opt_done
 * DESCRIPTION
 *  Entry function for the manual input options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_alm_entry_fmrdo_manual_input_opt_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_alm_fmrdo_check_freq_and_popup(&freq))
	{
		return;
	}

     g_alm_cntx.CurrHiliteAudioOptionValue = freq;
    g_alm_prev_audio_option_value = freq;
    g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_FMRADIO_MANUAL;

    g_alm_cntx.audio_select = MMI_TRUE;

    mmi_frm_group_close(GRP_ID_ALM_AUDIO_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_fmrdo_manual_input_opt_play
 * DESCRIPTION
 *  Entry function for the manual input options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_alm_entry_fmrdo_manual_input_opt_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_alm_fmrdo_check_freq_and_popup(&freq))
	{
		return;
	}

    g_alm_fmrdo_prev_freq = freq;
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
		mmi_ucm_app_entry_error_message();
        return;
    }
    else
#endif /* __MMI_BACKGROUND_CALL__ */
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (!srv_earphone_is_plug_in())
    {
        mmi_popup_property_struct arg;
        /*
        mmi_display_popup_with_sg(
            GRP_ID_ALM_AUDIO_OPTION,
            (UI_string_type) GetString(STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE), 
            MMI_EVENT_INFO,
            0);*/
        
        mmi_popup_property_init(&arg);
    
        arg.parent_id = GRP_ID_ALM_AUDIO_OPTION;
        arg.callback = (mmi_proc_func)NULL;
        g_alm_cntx.user_tag = STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE;
        arg.user_tag = &g_alm_cntx.user_tag;
        
        mmi_popup_display((WCHAR*)GetString(STR_ID_ALM_FMRDO_PLEASE_PLUG_IN_EARPHONE),
                          MMI_EVENT_INFO, 
                          &arg);
    }
    else
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
    {
        mmi_alm_entry_fmrdo_prev_channel();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_fmrdo_manual_input_options
 * DESCRIPTION
 *  Entry function for the manual input options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_fmrdo_manual_input_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    cui_menu_id = cui_menu_create(GRP_ID_ALM_AUDIO_OPTION_MAN_INPUT, 
                                  CUI_MENU_SRC_TYPE_APPCREATE, 
                                  CUI_MENU_TYPE_OPTION, 
                                  MENU_ID_ALM_FMRADIO_MAN_INPUT_OPTION, 
                                  MMI_FALSE, 
                                  NULL);

    cui_menu_run(cui_menu_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_fmrdo_prev_channel
 * DESCRIPTION
 *  Entry function for the preview screen
 * PARAMETERS
 *  void
 *  index(?)        [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_entry_fmrdo_prev_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str[32];
    U8 vol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_ALM_AUDIO_OPTION, 
            SCR_ID_ALM_FMRDO_PREV,
            mmi_alm_exit_fmrdo_prev_channel, 
            NULL, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    kal_wsprintf(str, "FM %d.%d", g_alm_fmrdo_prev_freq / 10, g_alm_fmrdo_prev_freq % 10);

	mdi_audio_suspend_background_play();
    /* mdi function calls */
    vol = mmi_fmrdo_get_volume();
    mdi_audio_stop_fmr();
    mdi_audio_set_volume(AUD_VOLUME_FMR, vol);
    mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER2, NULL, NULL);
    mdi_fmr_set_freq(g_alm_fmrdo_prev_freq);

    ShowCategory66Screen(
        STR_GLOBAL_PLAY,
        GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) str,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_exit_fmrdo_prev_channel
 * DESCRIPTION
 *  The interface for calling the mdi function for stopping the FM Radio.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_exit_fmrdo_prev_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_stop_fmr();
	mdi_audio_resume_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightAlmInlineAudioOptions
 * DESCRIPTION
 *  Highlight handler of Alarm Audio Options inline selection item in editor screen.
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightAlmInlineAudioOptions(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* temp_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If selection item changed */
    if (g_alm_cntx.CurrHiliteAudioOption != index)
    {
        if (index == ALM_AUDIO_OPTIONS_TONE) /* Tone */
        {
            g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_TONE;
			if (g_alm_prev_tone_value == 0)
			{
				g_alm_prev_tone_value = mmi_alm_default_ring_id();

                temp_string = GetString(srv_prof_get_string_id_from_srv_audio_id(g_alm_prev_tone_value));
				mmi_ucs2cpy((CHAR*)g_alm_tone_curselitem, temp_string);
			}
            
            g_alm_cntx.CurrHiliteAudioOptionValue = g_alm_prev_tone_value;
            temp_string = (CHAR*)g_alm_tone_curselitem;            
        }
        else if (index == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL) /* FM radio */
        {
            if (g_alm_prev_audio_option_value > 0 && g_alm_prev_audio_option_value <= FM_RADIO_CHANNEL_NUM)
            {
                g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL;
            }
            else
            {
                g_alm_cntx.CurrHiliteAudioOption = ALM_AUDIO_OPTIONS_FMRADIO_MANUAL;
            }
            
            g_alm_cntx.CurrHiliteAudioOptionValue = g_alm_prev_audio_option_value;
            
            temp_string = (CHAR*)g_alm_audio_options_curselitem;          
        }
        else 
        {
            g_alm_cntx.CurrHiliteAudioOptionValue = 0;
            temp_string = GetString(STR_GLOBAL_EMPTY_LIST); 

        }
        cui_inline_set_value(g_alm_cntx.curr_gid, 
                                    CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                         (void*)temp_string);

        cui_inline_redraw_screen(g_alm_cntx.curr_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_fmrdo_init_channe_list
 * DESCRIPTION
 *  This function is to check if the channel in FM radio initialized.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_aud_fmrdo_init_channe_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_ready && !g_alm_fmrdo_read_channel_name)
    {
        ReadRecord(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE, &error);

        if(g_fmrdo.channel_list.name[0][0] == 0xFFFF)
            {
            memset(&g_fmrdo.channel_list, 0, sizeof(mmi_fmrdo_channel_list_struct));
        }

        g_alm_fmrdo_read_channel_name = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_aud_fmrdo_play_alarm
 * DESCRIPTION
 *  This function is to play the FM radio when alarm expired.
 * PARAMETERS
 *  alarm_index     [IN]        
 *  volume          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_aud_fmrdo_play_alarm(U8 alarm_index, U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = 0;
	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(alarm_index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if FM Radio freqency set */
    if (node->AudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL)
    {
        mmi_alm_aud_fmrdo_init_channe_list();

        if ((node->AudioOptionValue > 0) &&
            (node->AudioOptionValue <= FM_RADIO_CHANNEL_NUM))
        {
            freq = mmi_alm_get_fm_channel_freq(node->AudioOptionValue - 1);
        }

    }
    else if (node->AudioOption == ALM_AUDIO_OPTIONS_FMRADIO_MANUAL)
    {
        freq = node->AudioOptionValue;
    }

    if (mmi_alm_is_valid_freq(freq))
    {
    	MMI_BOOL fm_flag;
		
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    	if (!srv_earphone_is_plug_in())
		{
			fm_flag = MMI_FALSE;
		}
		else
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */
		{
			fm_flag = MMI_TRUE;
		}

		if (fm_flag)
	{
            mdi_audio_stop_fmr();
            mdi_audio_set_volume(MDI_VOLUME_FMR, volume);
            mdi_fmr_power_on_with_path(MDI_DEVICE_SPEAKER_BOTH, NULL, NULL);
            mdi_fmr_set_freq(freq);
        }
	else
	{
	    srv_prof_play_tone(SRV_PROF_TONE_ALARM, NULL);
	}

    }
    /* Play default ring tone and restore alarm to default value */
    else
    {
        node->AudioOption = ALM_AUDIO_OPTIONS_TONE;
        node->AudioOptionValue = mmi_alm_default_ring_id();
		
		srv_alm_write(alarm_index, node);

        srv_prof_play_tone(SRV_PROF_TONE_ALARM, NULL);
    }

}
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */

#ifdef __MMI_ALM_CUSTOMIZE_TONE__
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_check_tone_extension
 * DESCRIPTION
 *  Initialize inline structure of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static CHAR* mmi_alm_check_tone_extension(const WCHAR* tone_string, const WCHAR *hide_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
    CHAR* temp_string;
	WCHAR *ext_ptr;
	const WCHAR *const_ext_ptr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                     					 */
    /*----------------------------------------------------------------*/
	temp_string = (CHAR*)srv_fmgr_path_get_filename_ptr((WCHAR*)tone_string);
	const_ext_ptr = srv_fmgr_path_get_extension_const_ptr(tone_string);
	
	if (const_ext_ptr == NULL)
	{
		return temp_string;
	}
	if (mmi_ucs2icmp((const CHAR*)const_ext_ptr, (const CHAR*)hide_ext) != 0)
	{
		return temp_string;
	}
	
    /* Only show file name */
	mmi_ucs2cpy((CHAR*)g_alm_tone_path, temp_string);
	ext_ptr = srv_fmgr_path_get_extension_ptr((WCHAR*)g_alm_tone_path);
	*(ext_ptr - 1) = 0;
	
	return (CHAR*)g_alm_tone_path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_update_tone_string
 * DESCRIPTION
 *  Initialize inline structure of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_alm_get_tone_string(CHAR** tone_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* temp_string;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
    if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL)
    {
        if ((g_alm_cntx.CurrHiliteAudioOptionValue > 0) &&
            (g_alm_cntx.CurrHiliteAudioOptionValue <= FM_RADIO_CHANNEL_NUM))
        {
            U8 list_index = g_alm_cntx.CurrHiliteAudioOptionValue - 1;

            if (mmi_ucs2strlen(mmi_alm_get_fm_channel_name(list_index)) != 0)
            {
                mmi_ucs2cpy((CHAR*) g_alm_audio_options_curselitem, (CHAR*)mmi_alm_get_fm_channel_name(list_index));
            }
            else
            {
                kal_wsprintf(
                    g_alm_audio_options_curselitem,
                    "FM %d.%d",
                    mmi_alm_get_fm_channel_freq(list_index) / 10,
                    mmi_alm_get_fm_channel_freq(list_index) % 10);
            }
        }
        else
        {
            mmi_ucs2cpy((CHAR*)g_alm_audio_options_curselitem, GetString(STR_GLOBAL_EMPTY_LIST));
        }

        temp_string = (CHAR*)g_alm_audio_options_curselitem;
    
    }
    else if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_FMRADIO_MANUAL)
    {
        if (g_alm_cntx.CurrHiliteAudioOptionValue > 0)
        {
            kal_wsprintf(
                g_alm_audio_options_curselitem,
                "FM %d.%d",
                g_alm_cntx.CurrHiliteAudioOptionValue / 10,
                g_alm_cntx.CurrHiliteAudioOptionValue % 10);
        }
        else
        {
            mmi_ucs2cpy((CHAR*) g_alm_audio_options_curselitem, GetString(STR_GLOBAL_EMPTY_LIST));
        }

        temp_string = (CHAR*)g_alm_audio_options_curselitem;
    }
    else
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */
    {
        U16 sel_tone = g_alm_cntx.CurrHiliteAudioOptionValue;
        U16 string_size;
        
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
        DYNAUDIOINFO *download_theme_tones = NULL;

        if (mmi_tm_get_current_theme_ringtone())
        {
            GetThemeV2TonesInfo(&download_theme_tones);
        }
        
        if (download_theme_tones != NULL && sel_tone == download_theme_tones[0].AudioId)
        {              
           temp_string = GetString(STR_ID_PROF_CURR_THEME);
        }
        else
#endif /* defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__) */ 
        {
            U16 string_id;
            
            if(g_alm_cntx.CurrHiliteAudioOptionValue == ALARM_TONE_FILE)
            {
				if (srv_fmgr_fs_path_exist((const WCHAR *)g_alm_cntx.tone_path) < 0)
				{
				#ifndef __MMI_DEV_NEW_SLIM__
					string_id = srv_prof_get_string_id_from_srv_audio_id(mmi_alm_default_ring_id());
				#else
					string_id = srv_prof_get_string_id_from_srv_audio_id(ALARM_DEFAULT_RING_ID);
				#endif
					
	            	if (string_id != NULL)
	        		{
	        			temp_string = GetString(string_id);
				#ifndef __MMI_DEV_NEW_SLIM__ 
	        			g_alm_cntx.CurrHiliteAudioOptionValue = mmi_alm_default_ring_id();
			    #else
						g_alm_cntx.CurrHiliteAudioOptionValue =ALARM_DEFAULT_RING_ID;
				#endif
	        		}
					else
					{
		                g_alm_cntx.CurrHiliteAudioOptionValue = 0;
		                temp_string = GetString(STR_GLOBAL_EMPTY);
					}
		#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
					g_alm_prev_tone_value = g_alm_cntx.CurrHiliteAudioOptionValue;
		#endif
				}
				else
				{
				temp_string = mmi_alm_check_tone_extension((const WCHAR *)g_alm_cntx.tone_path, L"mp3");
            }
				
            }
            else if ((string_id = srv_prof_get_string_id_from_srv_audio_id(sel_tone)) != 0)
            {
                temp_string = GetString(string_id);
            }
            else
            {
                g_alm_cntx.CurrHiliteAudioOptionValue = 0;
                temp_string = GetString(STR_GLOBAL_EMPTY);           
            }
        }
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__

        string_size = sizeof(g_alm_tone_curselitem) / 2;
        if (mmi_ucs2strlen(temp_string) > string_size-1)
        {
            mmi_ucs2ncpy((CHAR*)g_alm_tone_curselitem, temp_string, string_size - 1);
        }
        else
        {
            mmi_ucs2cpy((CHAR*)g_alm_tone_curselitem, temp_string);
        }
#endif
    }

   *tone_string = temp_string;
   
   return MMI_TRUE;    
}
#endif /*__MMI_ALM_CUSTOMIZE_TONE__*/

#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
static U16 mmi_alm_get_fm_channel_freq(U16 channel_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_fmrdo.channel_list.freq[channel_index];
}

static CHAR* mmi_alm_get_fm_channel_name(U16 channel_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (CHAR*)g_fmrdo.channel_list.name[channel_index];
}

static MMI_BOOL mmi_alm_is_valid_freq(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(freq >= MIN_FM_FREQUENCY && freq <= MAX_FM_FREQUENCY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_remove_channel_list_screen
 * DESCRIPTION
 *  Function to delete alarm channel list screen from history to void conflict with FM application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_alm_remove_channel_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
    mmi_frm_group_close(GRP_ID_ALM_AUDIO_OPTION);
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */

}
#endif

#ifdef __ORIGINAL_DOW__
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_disable_confirm_yes
 * DESCRIPTION
 *  To check if cust repeat is valid
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if valid
 *****************************************************************************/
static void mmi_alm_entry_disable_alm_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_ALM_EDITOR;
    arg.callback = (mmi_proc_func)NULL;
    g_alm_cntx.user_tag = STR_ID_ALM_DISABLE_ASK;
    arg.user_tag = &g_alm_cntx.user_tag;
    
    mmi_confirm_display((WCHAR*)GetString(STR_ID_ALM_DISABLE_ASK), MMI_EVENT_QUERY, &arg);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_is_valid_cust_repeat
 * DESCRIPTION
 *  To check if cust repeat is valid
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if valid
 *****************************************************************************/
static MMI_BOOL mmi_alm_is_valid_cust_repeat(U8 repeat_type, U8 *selected_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (repeat_type == ALM_FREQ_DAYS)     /* not Days */
    {
        for (i = 0; i < NUM_DAYS; i++)
        {
            if (selected_mask[i] != 0)
            {
                return MMI_TRUE;
            }
        }
        
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}

#ifndef __MMI_DEV_NEW_SLIM__
/*****************************************************************************
 * FUNCTION
 *  AlmIsInlineEditorChanged
 * DESCRIPTION
 *  To check if alarm is changed in inline editor screen.
 * PARAMETERS
 *  index       [IN]        Index of inline selection
 * RETURNS
 *  TURE if alarm is changed; otherwise, FLASE.
 *****************************************************************************/
BOOL AlmIsInlineEditorChanged(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_time_struct inline_time;
	srv_alm_node_type *node = (srv_alm_node_type *)srv_alm_read(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(g_alm_cntx.curr_gid, 
                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TIME, 
                         &inline_time);
    
    g_alm_cntx.curr_hour = (U8)inline_time.date_time.hour;
    g_alm_cntx.curr_min = (U8)inline_time.date_time.minute;
    
    if (
#ifdef __MMI_ALM_CUST_VOLUME__
           (node->Volume != g_alm_cntx.CurrHiliteVol) ||
#endif 
           (node->State != g_alm_cntx.CurrHiliteState) ||
           #ifdef __MMI_DEV_NEW_SLIM__
           (node->Freq != g_alm_freq_set[g_alm_cntx.CurrHiliteFreq])||  
           #else
           (node->Freq != mmi_alm_get_alarm_freq(g_alm_cntx.CurrHiliteFreq)) ||
           #endif
           (node->Hour != inline_time.date_time.hour) || 
           (node->Min != inline_time.date_time.minute))
    {
        return TRUE;
    }
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
    else if ((node->AudioOption != g_alm_cntx.CurrHiliteAudioOption))
    {
        return TRUE;
    }
    else if (node->AudioOptionValue != g_alm_cntx.CurrHiliteAudioOptionValue)
    {
        return TRUE;
    }
	else if (memcmp(node->tone_path, &g_alm_cntx.tone_path,wcslen((wchar_t *)g_alm_cntx.tone_path)+1))
	{
		return TRUE;
	}
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
    else if (g_alm_freq_set[g_alm_cntx.CurrHiliteFreq] == ALM_FREQ_DAYS)
    {
        return TRUE;
    }
#ifdef __MMI_ALM_SNOOZE_SETTING__
		else if (node->SnoozeInterval != (U8) g_alm_cntx.CurrHiliteSnoozeValue)
		{
			return TRUE;
		}
#endif /* __MMI_ALM_SNOOZE_SETTING__ */ 

#ifdef __MMI_ALM_ALERT_TYPE__
    else if (node->AlertType != (U8) g_alm_cntx.CurrHilightAlertType)
    {
        return TRUE;
    }
#endif /* __MMI_ALM_ALERT_TYPE__ */ 
    else
    {
        return FALSE;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  EntryAlmEditScreen
 * DESCRIPTION
 *  Display inline editor screen of alarm.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryAlmEditScreen(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DEV_NEW_SLIM__
	mmi_frm_group_create_ex(parent_id, GRP_ID_ALM_EDITOR, mmi_alm_group_proc, NULL,MMI_FRM_NODE_SMART_CLOSE_FLAG);
#else
    mmi_frm_group_create(parent_id, GRP_ID_ALM_EDITOR, mmi_alm_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_ALM_EDITOR, MMI_FRM_NODE_SMART_CLOSE_FLAG);

#endif
    g_alm_cntx.curr_gid = cui_inline_create(GRP_ID_ALM_EDITOR, &g_mmi_alm_edit_inline_data);
    if (g_alm_cntx.curr_gid != GRP_ID_INVALID)
    {       
        /* Use screen base memory to display short name of external melody*/
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
        /* when alarm edit screen is not in history, clear the global buffer & prev var */
        //if (inputBuffer == NULL)
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
        {   
            if (g_alm_cntx.CurrHiliteAudioOption == ALM_AUDIO_OPTIONS_TONE)
            {
                g_alm_prev_tone_value = g_alm_cntx.CurrHiliteAudioOptionValue; 
                g_alm_prev_audio_option_value = 0;
            }
            else
            {
                g_alm_prev_tone_value = 0;
                g_alm_prev_audio_option_value = g_alm_cntx.CurrHiliteAudioOptionValue;
            }
                    
            mmi_ucs2cpy((CHAR*)g_alm_audio_options_curselitem, (CHAR*)GetString(STR_GLOBAL_EMPTY_LIST));
            mmi_ucs2cpy((CHAR*)g_alm_tone_curselitem, (CHAR*)GetString(STR_GLOBAL_EMPTY_LIST));
        }
#endif
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */
        AlmFillInlineEditStruct(); 

       // cui_inline_set_title_icon(g_alm_cntx.curr_gid, GetRootTitleIcon(ORGANIZER_ALARM_MENU));
        cui_inline_run (g_alm_cntx.curr_gid);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_ALM_EDITOR);
    }

}


/*****************************************************************************
 * FUNCTION
 *  AlmFillInlineEditStruct
 * DESCRIPTION
 *  Initialize inline structure of input screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmFillInlineEditStruct()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_set_item_time_struct time_struct;
    applib_time_struct curr_time;
    CHAR *temp_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ON/OFF */
    cui_inline_set_value(g_alm_cntx.curr_gid, 
                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_STATUS, 
                         (void*)g_alm_cntx.CurrHiliteState);
    cui_inline_set_item_attributes(g_alm_cntx.curr_gid, 
                                   CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_STATUS,
                                   CUI_INLINE_SET_ATTRIBUTE,
                                   CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT);

    /* time */
    GetDateTime(&curr_time);
 
    time_struct.date_format = 0;
    time_struct.date_time.year = curr_time.nYear;
    time_struct.date_time.month = curr_time.nMonth;
    time_struct.date_time.day = curr_time.nDay;

    time_struct.date_time.hour = g_alm_cntx.curr_hour;
    time_struct.date_time.minute = g_alm_cntx.curr_min;    
    time_struct.date_time.second = curr_time.nSec;

    cui_inline_set_value(g_alm_cntx.curr_gid, 
                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TIME, 
                         &time_struct);
    cui_inline_set_item_attributes(g_alm_cntx.curr_gid, 
                                   CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TIME,
                                   CUI_INLINE_SET_ATTRIBUTE,
                                   CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT);

    /* Repeat */
#ifndef __ORIGINAL_DOW__    
     cui_inline_set_value(g_alm_cntx.curr_gid, 
                          CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_REPEAT, 
                          (void*)mmi_alm_inline_get_repeat_type_string());
#else
     cui_inline_set_value(g_alm_cntx.curr_gid, 
                          CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_REPEAT, 
                          (void*)g_alm_cntx.CurrHiliteFreq);

    /* day of week */
    if (g_alm_freq_set[g_alm_cntx.CurrHiliteFreq] != ALM_FREQ_DAYS)     /* not Days */
    {
        memset(gAlmDaysStates, 0, 7);
        cui_inline_set_item_attributes(g_alm_cntx.curr_gid, 
                               CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_DOW,
                               CUI_INLINE_SET_ATTRIBUTE,
                               CUI_INLINE_ITEM_DISABLE);
    }
    
    cui_inline_set_value(g_alm_cntx.curr_gid, 
                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_DOW,
                         gAlmDaysStates);

    /* day of week */
    if (g_alm_freq_set[g_alm_cntx.CurrHiliteFreq] != ALM_FREQ_DAYS)     /* not Days */
    {
          cui_inline_set_item_attributes(g_alm_cntx.curr_gid, 
                                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_DOW,
                                         CUI_INLINE_SET_ATTRIBUTE,
                                         CUI_INLINE_ITEM_DISABLE);
    }
#endif

#ifdef __MMI_ALM_CUST_VOLUME__

    cui_inline_set_value(g_alm_cntx.curr_gid, 
                     CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_CUST_VOL, 
                     (void*)g_alm_cntx.CurrHiliteVol);


#endif /* __MMI_ALM_CUST_VOLUME__ */ 

    /* Customize Ring Tone and FM alarm */
//#ifdef __MMI_ALM_AUDIO_OPTIONS__
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
	if (g_alm_cntx.CurrHiliteAudioOption > ALM_AUDIO_OPTIONS_TONE)
	{
		g_alm_audio_option_previndex =	ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL;
	}
	else
	{
		g_alm_audio_option_previndex = ALM_AUDIO_OPTIONS_TONE;
	}

    cui_inline_set_value(g_alm_cntx.curr_gid, 
                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_SELECT, 
                         (void*)g_alm_audio_option_previndex);
#endif
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
    mmi_alm_get_tone_string(&temp_string);
    cui_inline_set_value(g_alm_cntx.curr_gid, 
                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                         (void*)temp_string);
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 

#ifdef __MMI_ALM_SNOOZE_SETTING__
     cui_inline_set_value(g_alm_cntx.curr_gid, 
                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_SNOOZE, 
                         (void*)g_alm_cntx.CurrHilightSnoozeInterval);
    
#endif /* __MMI_ALM_SNOOZE_SETTING__ */

#ifdef __MMI_ALM_ALERT_TYPE__
    cui_inline_set_value(g_alm_cntx.curr_gid, 
                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_ALERT_TYPE, 
                         (void*)g_alm_cntx.CurrHilightAlertType);

#endif /* __MMI_ALM_ALERT_TYPE__ */ 
}

#ifdef __MMI_ALM_SNOOZE_SETTING__
void AlmSetSnooze(U8 *snooze_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_alm_cntx.CurrHilightSnoozeInterval == ALARM_SNOOZE_OFF)
        {
            (*snooze_val) = 0;
        }
        else if (g_alm_cntx.CurrHilightSnoozeInterval == ALARM_SNOOZE_PERIOD_ONE)
        {
            (*snooze_val) = (U8)1;			
        }
        else if (g_alm_cntx.CurrHilightSnoozeInterval == ALARM_SNOOZE_PERIOD_THREE)
        {
            (*snooze_val) = (U8)3;			
        }
        else if (g_alm_cntx.CurrHilightSnoozeInterval == ALARM_SNOOZE_PERIOD_FIVE)
        {
            (*snooze_val) = (U8)5;			
        }
        else
        {
            (*snooze_val) = (U8)10;			
        }
}

#endif

/*****************************************************************************
 * FUNCTION
 *  AlmSaveInlineEdit
 * DESCRIPTION
 *  Save alarm to nvram and set/cancel alarm to driver accordingly.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlmSaveInlineEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	alm_nvram_struct *alm_node = (srv_alm_node_type *)srv_alm_read(g_alm_cntx.CurrHiliteAlarm);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ALM_SNOOZE_SETTING__
	AlmSetSnooze(&(g_alm_cntx.CurrHiliteSnoozeValue));
#endif
  #ifndef __MMI_DEV_NEW_SLIM__
    if (AlmIsInlineEditorChanged(g_alm_cntx.CurrHiliteAlarm))
  #endif
    {
        S32 j;
        S32 i = g_alm_cntx.CurrHiliteAlarm;
	#ifdef __MMI_DEV_NEW_SLIM__
		cui_inline_set_item_time_struct inline_time;
        alm_node->Freq = g_alm_freq_set[g_alm_cntx.CurrHiliteFreq];
		cui_inline_get_value(g_alm_cntx.curr_gid, 
                         CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TIME, 
                         &inline_time);
    	g_alm_cntx.curr_hour = (U8)inline_time.date_time.hour;
    	g_alm_cntx.curr_min = (U8)inline_time.date_time.minute;
	#else
		alm_node->Freq = mmi_alm_get_alarm_freq(g_alm_cntx.CurrHiliteFreq);
	#endif
        alm_node->Days = 0;

        if (alm_node->Freq == ALM_FREQ_DAYS)
        {           
            for (j = 0; j < NUM_DAYS; j++)
            {
                alm_node->Days |= (gAlmDaysStates[j] << j);
            }

            if (alm_node->Days == 0)
            {
                alm_node->Freq = ALM_FREQ_ONCE;
            }
        }

        alm_node->State = (U8) g_alm_cntx.CurrHiliteState;
        alm_node->Hour = g_alm_cntx.curr_hour;
        alm_node->Min = g_alm_cntx.curr_min;
        alm_node->Snooze = 0;

    #ifdef __MMI_ALM_CUST_VOLUME__
        alm_node->Volume = (U8) g_alm_cntx.CurrHiliteVol;
    #endif 

        /* Alarm Audio Setting */
    #ifdef __MMI_ALM_CUSTOMIZE_TONE__
        if (g_alm_cntx.CurrHiliteAudioOptionValue != 0)
        {
            alm_node->AudioOption 	   = (U8)g_alm_cntx.CurrHiliteAudioOption;
            alm_node->AudioOptionValue = g_alm_cntx.CurrHiliteAudioOptionValue;

            if (alm_node->AudioOptionValue == ALARM_TONE_FILE)
            {
                // should check the file path
                mmi_ucs2cpy((CHAR*)alm_node->tone_path, (CHAR*)g_alm_cntx.tone_path);
            }
        }
        else    /* Should not enter here because it already check before save */
        {
            alm_node->AudioOption = ALM_AUDIO_OPTIONS_TONE;
		#ifndef __MMI_DEV_NEW_SLIM__
            alm_node->AudioOptionValue = mmi_alm_default_ring_id();
		#else
			 alm_node->AudioOptionValue = ALARM_DEFAULT_RING_ID;
		#endif
        }
    #endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 

    #ifdef __MMI_ALM_SNOOZE_SETTING__
	 	AlmSetSnooze(&(alm_node->SnoozeInterval));
    #endif 
    #ifdef __MMI_ALM_ALERT_TYPE__
        alm_node->AlertType = (U8) g_alm_cntx.CurrHilightAlertType;
    #endif 
        srv_alm_write(i, alm_node);

        if (g_alm_cntx.CurrHiliteState == SET_STATE)
        {
            AlmActivateIndicator();
        }
        else
        {
            if (srv_alm_active_alms() == 0)
            {
                AlmDeactivateIndicator();
            }
        }
    }

#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
    if (((alm_node->AudioOption == ALM_AUDIO_OPTIONS_FMRADIO_CHANNEL) ||
         (alm_node->AudioOption == ALM_AUDIO_OPTIONS_FMRADIO_MANUAL)) &&
        alm_node->State == TRUE &&
#ifdef __MMI_ALM_ALERT_TYPE__
        alm_node->AlertType != ALM_ALERT_VIBRATION &&
#endif
        MMI_TRUE)
    {
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
        mmi_confirm_property_struct arg;

        mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
        arg.parent_id = GRP_ID_ALM_EDITOR;
        arg.callback = (mmi_proc_func)NULL;
	arg.f_enter_history = 1;
        g_alm_cntx.user_tag = STR_ID_ALM_FMRDO_HEADFONE_REMINDER;
        arg.user_tag = &g_alm_cntx.user_tag;
        
        mmi_confirm_display((WCHAR*)GetString(STR_ID_ALM_FMRDO_HEADFONE_REMINDER), 
                            MMI_EVENT_INFO, 
                            &arg);
#else /* __MMI_FM_RADIO_BIND_EARPHONE__ */
        {   
            mmi_alm_display_popup();
			mmi_frm_group_close(GRP_ID_ALM_EDITOR);
        }
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */
    }
    else
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */
    {
 #ifdef __MMI_MAINLCD_96X64__ 
       mmi_alm_display_popup();
 #endif
 //       mmi_alm_display_popup();
		mmi_frm_group_close(GRP_ID_ALM_EDITOR);
    }
}

#ifdef __MMI_CALENDAR_FDOW__
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_inline_get_repeat_type_string
 * DESCRIPTION
 *  Get repeat type string of current setting 
 * PARAMETERS
 *  
 * RETURNS
 *  static WCHAR*
 *****************************************************************************/
static void mmi_alm_inline_get_repeate_string(U8 i)
 {
  S32 buf_len = MMI_ALM_MAX_REPEAT_TIME_STRING_LEN;
				if (gAlmDaysStates[i])
	    		{
	                if (g_mmi_alm_repeat_time_string[0] != 0)
	            	{
	                    /* There is already a weekday, add "," for display */
						if(buf_len > kal_wstrlen(L", "))
						{
	            	        mmi_wcscat(g_mmi_alm_repeat_time_string, L", ");
							buf_len -= kal_wstrlen(L", ");
						}
						else
						{
							return;
						}
						
	            	}
					if(buf_len > kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i)))
					{
	                    mmi_wcscat(g_mmi_alm_repeat_time_string, (WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i));
						buf_len -= kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i));
					}
					else
					{
						return;
					}
					
	    		}	               
 }

#endif

#ifdef __MMI_DEV_NEW_SLIM__
static WCHAR* mmi_alm_inline_get_repeat_type_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buf_len = MMI_ALM_MAX_REPEAT_TIME_STRING_LEN;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_freq_set[g_alm_cntx.CurrHiliteFreq] != ALM_FREQ_DAYS)
	{
	    return (WCHAR*)GetString(gAlmFreqList[g_alm_cntx.CurrHiliteFreq]);
	}
    else
    {
        U8 i;

		for (i = 0; i < NUM_DAYS; i++)
    	{
			if (!gAlmDaysStates[i])
				break;			
		}
		if(i == NUM_DAYS)
		{
			 g_alm_cntx.CurrHiliteFreq = 1;
			 return (WCHAR*)GetString(gAlmFreqList[g_alm_cntx.CurrHiliteFreq]);
		}

        memset(g_mmi_alm_repeat_time_string, 0, (MMI_ALM_MAX_REPEAT_TIME_STRING_LEN * sizeof(WCHAR)));
        for (i = 0; i < NUM_DAYS; i++)
    	{
#ifdef	__MMI_CALENDAR_FDOW__
			U8 j = i;
		    if(mmi_clndr_get_week_first_day())
		    {	
				j = (i+1)%7;	    						
		    }

			mmi_alm_inline_get_repeate_string(j);
			
#else	
    		if (gAlmDaysStates[i])
    		{
                if (g_mmi_alm_repeat_time_string[0] != 0)
            	{
                    /* There is already a weekday, add "," for display */
					if(buf_len > kal_wstrlen(L", "))
					{
            	        mmi_wcscat(g_mmi_alm_repeat_time_string, L", ");
						buf_len -= kal_wstrlen(L", ");
					}
					else
					{
						break;
					}
            	}
				if(buf_len > kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i)))
				{
                    mmi_wcscat(g_mmi_alm_repeat_time_string, (WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i));
					buf_len -= kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i));
				}
				else
				{
					break;
				}
    		}
#endif			
    	}

        return g_mmi_alm_repeat_time_string;
    }
}
#else
static WCHAR* mmi_alm_inline_get_repeat_type_string(void)
{
    /*----------------------------------------------------------------*/

    S32 buf_len = MMI_ALM_MAX_REPEAT_TIME_STRING_LEN;

    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_alm_freq_set[g_alm_cntx.CurrHiliteFreq] != ALM_FREQ_DAYS)
	{
	    return (WCHAR*)GetString(gAlmFreqList[g_alm_cntx.CurrHiliteFreq]);
	}
    else
    {
        U8 i;
	
		for (i = 0; i < NUM_DAYS; i++)
    	{
			if (!gAlmDaysStates[i])
				break;			
		}
		if(i == NUM_DAYS)
		{
			 g_alm_cntx.CurrHiliteFreq = 1;
			 return (WCHAR*)GetString(gAlmFreqList[g_alm_cntx.CurrHiliteFreq]);
		}

        memset(g_mmi_alm_repeat_time_string, 0, (MMI_ALM_MAX_REPEAT_TIME_STRING_LEN * sizeof(WCHAR)));

        for (i = 0; i < NUM_DAYS; i++)
    	{
#ifdef	__MMI_CALENDAR_FDOW__
		    if(mmi_clndr_get_week_first_day())
		    {
				if (gAlmDaysStates[(i+1)%7])
	    		{
	                if (g_mmi_alm_repeat_time_string[0] != 0)
	            	{
	                    /* There is already a weekday, add "," for display */
						if(buf_len > kal_wstrlen(L", "))
						{
	            	        mmi_wcscat(g_mmi_alm_repeat_time_string, L", ");
							buf_len -= kal_wstrlen(L", ");
						}
						else
						{
							break;
						}
	            	}
					if(buf_len > kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + (i+1)%7)))
					{
	                    mmi_wcscat(g_mmi_alm_repeat_time_string, (WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + (i+1)%7));
						buf_len -= kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + (i+1)%7));
					}
					else
					{
						break;
					}
	    		}				
		    }
			else
			{
				if (gAlmDaysStates[i])
	    		{
	                if (g_mmi_alm_repeat_time_string[0] != 0)
	            	{
	                    /* There is already a weekday, add "," for display */
						if(buf_len > kal_wstrlen(L", "))
						{
	            	        mmi_wcscat(g_mmi_alm_repeat_time_string, L", ");
							buf_len -= kal_wstrlen(L", ");
						}
						else
						{
							break;
						}
	            	}
					if(buf_len > kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i)))
					{
	                    mmi_wcscat(g_mmi_alm_repeat_time_string, (WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i));
						buf_len -= kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i));
					}
					else
					{
						break;
					}
	    		}
			}
#else	
    		if (gAlmDaysStates[i])
    		{
                if (g_mmi_alm_repeat_time_string[0] != 0)
            	{
                    /* There is already a weekday, add "," for display */
					if(buf_len > kal_wstrlen(L", "))
					{
            	        mmi_wcscat(g_mmi_alm_repeat_time_string, L", ");
						buf_len -= kal_wstrlen(L", ");
					}
					else
					{
						break;
					}
            	}
				if(buf_len > kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i)))
				{
                    mmi_wcscat(g_mmi_alm_repeat_time_string, (WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i));
					buf_len -= kal_wstrlen((WCHAR*)GetString(STR_GLOBAL_SUNDAY_SHORT + i));
				}
				else
				{
					break;
				}
    		}
#endif			
    	}
        return g_mmi_alm_repeat_time_string;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_inline_highlight_handler
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_alm_inline_highlight_handler(U32 inline, U32 param)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
    if (inline == MMI_ALM_INLINE_TONE_STRING)
    {
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__   
        if (g_alm_audio_option_previndex == ALM_AUDIO_OPTIONS_TONE)
#endif			
        {
            cui_inline_set_softkey_icon(g_alm_cntx.curr_gid, 
                                        CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                                        MMI_LEFT_SOFTKEY, 
                                        0);

            cui_inline_set_softkey_text(g_alm_cntx.curr_gid, 
                                        CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                                        MMI_LEFT_SOFTKEY, 
                                        STR_GLOBAL_SELECT);
			#ifdef __MMI_MAINLCD_96X64__
			 cui_inline_set_title_string(g_alm_cntx.curr_gid, get_string(STR_ID_ALM_AUDIO_OPTIONS));
			#endif
	        wgui_inline_set_lsk_function(mmi_alarm_entry_tone_selector);
	        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_alarm_entry_tone_selector, KEY_EVENT_UP);
        }
        #ifdef __MMI_ALM_FM_RADIO_SUPPORT__
        else
        {
            cui_inline_set_softkey_icon(g_alm_cntx.curr_gid, 
                                        CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                                        MMI_LEFT_SOFTKEY, 
                                        IMG_GLOBAL_OPTIONS);

            cui_inline_set_softkey_text(g_alm_cntx.curr_gid, 
                                        CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                                        MMI_LEFT_SOFTKEY, 
                                        STR_GLOBAL_OPTIONS);
            wgui_inline_set_lsk_function(mmi_alm_entry_aud_opt_fmrdo);
		    ChangeCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
            SetCenterSoftkeyFunction(mmi_alm_entry_aud_opt_fmrdo, KEY_EVENT_UP);
        }
        #endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */
    }
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */  
#ifndef __ORIGINAL_DOW__
    if (inline == MMI_ALM_INLINE_REPEAT)
	{
        cui_inline_set_softkey_text(g_alm_cntx.curr_gid, 
                                    CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_REPEAT, 
                                    MMI_LEFT_SOFTKEY, 
                                    STR_GLOBAL_SELECT);
		#ifdef __MMI_MAINLCD_96X64__
		cui_inline_set_title_string(g_alm_cntx.curr_gid, get_string(ALARM_REPEAT_STRING));
		#endif
        wgui_inline_set_lsk_function(mmi_alm_entry_repeat_type_menu);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_alm_entry_repeat_type_menu, KEY_EVENT_UP);

	}
#endif /* __ORIGINAL_DOW__ */

#ifdef __MMI_DEV_NEW_SLIM__
	if(inline == MMI_ALM_INLINE_TIME)
	{
		 SetCenterSoftkeyFunction(AlmSaveInlineEdit, KEY_EVENT_UP);
	}
#endif 


#ifdef __MMI_MAINLCD_96X64__
	if(inline == MMI_ALM_INLINE_STATUS)
	{
		cui_inline_set_title_string(g_alm_cntx.curr_gid, get_string(STR_GLOBAL_STATUS));
	}
	if(inline == MMI_ALM_INLINE_TIME)
	{
		cui_inline_set_title_string(g_alm_cntx.curr_gid, get_string(STR_GLOBAL_TIME));
	}
#ifdef __MMI_ALM_SNOOZE_SETTING__

	if(inline == MMI_ALM_INLINE_SNOOZE)
	{
		cui_inline_set_title_string(g_alm_cntx.curr_gid, get_string(ALARMS_SETTING_SNOOZE_INTERVAL));
	}
#endif
	if(inline == MMI_ALM_INLINE_ALERT_TYPE)
	{
		cui_inline_set_title_string(g_alm_cntx.curr_gid, get_string(STR_ID_PROF_ALERT_TYPE));
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_inline_select_handler
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  inline    :[IN] inline id
 *  param     :[IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_alm_inline_select_handler(U32 inline, U32 param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inline == MMI_ALM_INLINE_STATUS)
    {
        cui_inline_get_value(g_alm_cntx.curr_gid, 
                             (U16)(CUI_INLINE_ITEM_ID_BASE + inline), 
                             (void*)&g_alm_cntx.CurrHiliteState);
    }
#ifndef __MMI_DEV_NEW_SLIM__ 
    else if(inline == MMI_ALM_INLINE_TIME)
    {
    
    }
#endif
#ifdef __ORIGINAL_DOW__
    else if (inline == MMI_ALM_INLINE_REPEAT)
    {
        cui_inline_get_value(g_alm_cntx.curr_gid, 
                             (U16)(CUI_INLINE_ITEM_ID_BASE + inline), 
                             &g_alm_cntx.CurrHiliteFreq);
        
        HighlightAlmInlineRepeat((U8)g_alm_cntx.CurrHiliteFreq);
    }
#endif /* __ORIGINAL_DOW__ */

#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
    else if (inline == MMI_ALM_INLINE_TONE_SELECT)
    {
        cui_inline_get_value(g_alm_cntx.curr_gid, 
                             (U16)(CUI_INLINE_ITEM_ID_BASE + inline), 
                             &g_alm_audio_option_previndex);

        HighlightAlmInlineAudioOptions(param);
    }
#endif    
#ifdef __MMI_ALM_ALERT_TYPE__
    else if (inline == MMI_ALM_INLINE_ALERT_TYPE)
    {
        cui_inline_get_value(g_alm_cntx.curr_gid, 
                             (U16)(CUI_INLINE_ITEM_ID_BASE + inline), 
                             &g_alm_cntx.CurrHilightAlertType);
    }
#endif /* __MMI_ALM_ALERT_TYPE__ */
#ifdef __MMI_ALM_SNOOZE_SETTING__
    else if (inline == MMI_ALM_INLINE_SNOOZE)
    {
        cui_inline_get_value(g_alm_cntx.curr_gid, 
                             (U16)(CUI_INLINE_ITEM_ID_BASE + inline), 
                             &g_alm_cntx.CurrHilightSnoozeInterval);        
    }
#endif
}

#ifndef __ORIGINAL_DOW__
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_repeat_type_menu
 * DESCRIPTION
 *  Enter the menu for repeat type select 
 * PARAMETERS
 *  parent_gid      :   [IN]    group ID of parent
 *  highlight_idx   :   [IN]    current highlight one
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_alm_entry_repeat_type_menu(void)
{
#ifndef __MMI_DEV_NEW_SLIM__
    MMI_ID cui_gid;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_repeat_type_changed = MMI_FALSE;
#ifdef __MMI_DEV_NEW_SLIM__
	mmi_frm_group_create_ex(GRP_ID_ALM_EDITOR, 
        GRP_ID_ALM_REPEAT_TYPE_MENU,
        mmi_alm_repeat_type_proc, 
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
	//cui_gid = 
		cui_menu_create_and_run(
		GRP_ID_ALM_REPEAT_TYPE_MENU,
		CUI_MENU_SRC_TYPE_RESOURCE, //CUI_MENU_SRC_TYPE_APPCREATE,	 __MMI_DEV_NEW_SLIM__
		CUI_MENU_TYPE_APPSUB,
		MENU_ID_ALM_REPEAT_TYPE_MAIN,
		MMI_FALSE,
		NULL);
#else
    mmi_frm_group_create(
        GRP_ID_ALM_EDITOR, 
        GRP_ID_ALM_REPEAT_TYPE_MENU,
        mmi_alm_repeat_type_proc, 
        NULL);
    mmi_frm_group_enter(GRP_ID_ALM_REPEAT_TYPE_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create(
        GRP_ID_ALM_REPEAT_TYPE_MENU,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_APPSUB,
        MENU_ID_ALM_REPEAT_TYPE_MAIN,
        MMI_FALSE,
        NULL);
    cui_menu_run(cui_gid);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_repeat_type_custom_menu
 * DESCRIPTION
 *  Enter the custom repeat type menu 
 * PARAMETERS
 *  parent_gid      :   [IN]    group ID of parent
 *  selected_mask   :   [IN]    mask array for week days
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_alm_entry_repeat_type_custom_menu(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_alm_temp_custom_repeat_week_day, gAlmDaysStates, sizeof(U8) * NUM_DAYS);
    mmi_frm_scrn_first_enter(
        parent_gid, 
        SCR_ID_ALM_CUSTOM_REPEAT_TYPE,
        (FuncPtr)mmi_alm_entry_repeat_type_custom_menu_int, 
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_repeat_type_custom_menu_int
 * DESCRIPTION
 *  Enter custom repeat type menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_alm_entry_repeat_type_custom_menu_int(mmi_scrn_essential_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U8 *menu_items[NUM_DAYS];
    U16 alarm_states_icon[NUM_DAYS];
    U8 i;
#ifdef __MMI_DEV_NEW_SLIM__
	U8 j;
#endif
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_ALM_REPEAT_TYPE_MENU, SCR_ID_ALM_CUSTOM_REPEAT_TYPE, NULL, (FuncPtr)mmi_alm_entry_repeat_type_custom_menu_int, MMI_FRM_UNKNOW_SCRN))
	{
	    return;
	}
    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_ALM_REPEAT_TYPE_MENU, SCR_ID_ALM_CUSTOM_REPEAT_TYPE);

#ifndef __MMI_DEV_NEW_SLIM__
#ifdef	__MMI_CALENDAR_FDOW__
	if(mmi_clndr_get_week_first_day())
	{
		for (i = 0; i < NUM_DAYS; i++)
		{
			menu_items[i] = (U8*)GetString(STR_GLOBAL_SUNDAY + (i+1)%7);
	        if (g_alm_temp_custom_repeat_week_day[i] == SET_STATE)
	        {
	            alarm_states_icon[(i+7-1)%7] = CHECKBOX_ON_IMAGE_ID;
	        }
	        else
	        {
	            alarm_states_icon[(i+7-1)%7] = CHECKBOX_OFF_IMAGE_ID;
	        }
		}
	}
	else
	{
	    for (i = 0; i < NUM_DAYS; i++)
		{
			menu_items[i] = (U8*)GetString(STR_GLOBAL_SUNDAY + i);
	        if (g_alm_temp_custom_repeat_week_day[i] == SET_STATE)
	        {
	            alarm_states_icon[i] = CHECKBOX_ON_IMAGE_ID;
	        }
	        else
	        {
	            alarm_states_icon[i] = CHECKBOX_OFF_IMAGE_ID;
	        }
		}
	}
#else
	for (i = 0; i < NUM_DAYS; i++)
	{
		menu_items[i] = (U8*)GetString(STR_GLOBAL_SUNDAY + i);
		if (g_alm_temp_custom_repeat_week_day[i] == SET_STATE)
		{
			alarm_states_icon[i] = CHECKBOX_ON_IMAGE_ID;
		}
		else
		{
			alarm_states_icon[i] = CHECKBOX_OFF_IMAGE_ID;
		}
	}
#endif
#else

#ifdef	__MMI_CALENDAR_FDOW__
	for(i = 0; i < NUM_DAYS; i++)
	{
		if(mmi_clndr_get_week_first_day())
		{
			j=(i+7-1)%7;
			menu_items[i] = (U8*)GetString(STR_GLOBAL_SUNDAY + (i+1)%7);
		}
		else
		{
			j = i;
			menu_items[i] = (U8*)GetString(STR_GLOBAL_SUNDAY + i);
		}
			alarm_states_icon[j] = (g_alm_temp_custom_repeat_week_day[i] == SET_STATE ? CHECKBOX_ON_IMAGE_ID : CHECKBOX_OFF_IMAGE_ID);		        
	}
#else
	for (i = 0; i < NUM_DAYS; i++)
	{
		menu_items[i] = (U8*)GetString(STR_GLOBAL_SUNDAY + i);
		alarm_states_icon[i] = (g_alm_temp_custom_repeat_week_day[i] == SET_STATE ? CHECKBOX_ON_IMAGE_ID : CHECKBOX_OFF_IMAGE_ID);
	}
#endif
#endif
    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);

	EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);

    ShowCategory53Screen(
        STR_GLOBAL_ALARM,
        GetRootTitleIcon(ORGANIZER_ALARM_MENU),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        NUM_DAYS,
        menu_items,
        alarm_states_icon,
        0,
        0,
        0,
        gui_buffer);
    wgui_restore_list_menu_slim_style();

    SetLeftSoftkeyFunction(mmi_alm_entry_repeat_type_custom_option_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

	SetCenterSoftkeyFunction(mmi_alm_repeat_type_custom_csk_hdlr, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
   // wgui_register_tap_callback(mmi_alm_repeat_type_custom_csk_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */

}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_entry_repeat_type_custom_option_menu
 * DESCRIPTION
 *  Enter the options menu for custom repeat type menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_alm_entry_repeat_type_custom_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_DEV_NEW_SLIM__
    MMI_ID cui_gid; 
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_alm_temp_highlighted_week_day = GetHighlightedItem();
#ifdef __MMI_DEV_NEW_SLIM__
	//cui_gid = 
	cui_menu_create_and_run(
        GRP_ID_ALM_REPEAT_TYPE_MENU,
        CUI_MENU_SRC_TYPE_RESOURCE,   //CUI_MENU_SRC_TYPE_APPCREATE,   __MMI_DEV_NEW_SLIM__
        CUI_MENU_TYPE_OPTION,
        MENU_ID_ALM_REPEAT_TYPE_CUSTOM_OPTION_MENU,
        MMI_FALSE,
        NULL);
#else
    cui_gid = cui_menu_create(
        GRP_ID_ALM_REPEAT_TYPE_MENU,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_OPTION,
        MENU_ID_ALM_REPEAT_TYPE_CUSTOM_OPTION_MENU,
        MMI_FALSE,
        NULL);
    cui_menu_run(cui_gid);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_repeat_type_custom_switch_status
 * DESCRIPTION
 *  Highlight handler for custom repeat type menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_alm_repeat_type_custom_switch_status(S32 item_index)
{
/*----------------------------------------------------------------*/
#ifndef __MMI_DEV_NEW_SLIM__
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef	__MMI_CALENDAR_FDOW__
    if(mmi_clndr_get_week_first_day())	
    {
	    if (g_alm_temp_custom_repeat_week_day[(item_index+1)%7])
	    {
	        g_alm_temp_custom_repeat_week_day[(item_index+1)%7] = 0;
	    }
	    else
	    {
	        g_alm_temp_custom_repeat_week_day[(item_index+1)%7] = 1;
	    }
    }
	else
	{
	    if (g_alm_temp_custom_repeat_week_day[item_index])
	    {
	        g_alm_temp_custom_repeat_week_day[item_index] = 0;
	    }
	    else
	    {
	        g_alm_temp_custom_repeat_week_day[item_index] = 1;
	    }
	}
#else
	if (g_alm_temp_custom_repeat_week_day[item_index])
	{
		g_alm_temp_custom_repeat_week_day[item_index] = 0;
	}
	else
	{
		g_alm_temp_custom_repeat_week_day[item_index] = 1;
	}
#endif
#else
	#ifdef	__MMI_CALENDAR_FDOW__
    if(mmi_clndr_get_week_first_day())	
    {
		item_index = (item_index+1)%7;	   
    }
	    g_alm_temp_custom_repeat_week_day[item_index] = !g_alm_temp_custom_repeat_week_day[item_index];
	
	#else
		g_alm_temp_custom_repeat_week_day[item_index] = !g_alm_temp_custom_repeat_week_day[item_index];
	#endif
#endif
} 

 
/*****************************************************************************
 * FUNCTION
 *  mmi_alm_repeat_type_custom_csk_hdlr
 * DESCRIPTION
 *  Switch the status of highlighted item 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_alm_repeat_type_custom_csk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_idx = GetHighlightedItem();
    U8 *icon;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alm_repeat_type_custom_switch_status(item_idx);
#ifdef	__MMI_CALENDAR_FDOW__
    if(mmi_clndr_get_week_first_day())
    {
		icon = (U8*)GetImage(g_alm_temp_custom_repeat_week_day[(item_idx+1)%7] == 1 ? CHECKBOX_ON_IMAGE_ID : CHECKBOX_OFF_IMAGE_ID);
    }
	else
	{
        icon = (U8*)GetImage(g_alm_temp_custom_repeat_week_day[item_idx] == 1 ? CHECKBOX_ON_IMAGE_ID : CHECKBOX_OFF_IMAGE_ID);
	}
#else
    icon = (U8*)GetImage(g_alm_temp_custom_repeat_week_day[item_idx] == 1 ? CHECKBOX_ON_IMAGE_ID : CHECKBOX_OFF_IMAGE_ID);
#endif
    Category53ChangeItemIcon(
        item_idx, 
        icon);
    RedrawCategoryFunction();
} 
 

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_repeat_type_proc
 * DESCRIPTION
 *  Proc function for repeat type menu 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_alm_repeat_type_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
	{
	case EVT_ID_CUI_MENU_LIST_ENTRY:
		if (menu_evt->parent_menu_id == MENU_ID_ALM_REPEAT_TYPE_MAIN)
		{
		    mmi_alm_init_repeat_type_main_menu(menu_evt->sender_id);
            return MMI_RET_OK;
		}
        else if (menu_evt->parent_menu_id == MENU_ID_ALM_REPEAT_TYPE_CUSTOM_OPTION_MENU)
    	{
    	    mmi_alm_init_custom_options_menu(menu_evt->sender_id);
            return MMI_RET_OK;
    	}
		break;
        
    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
#ifndef __MMI_DEV_NEW_SLIM__   
        if (menu_evt->parent_menu_id == MENU_ID_ALM_REPEAT_TYPE_MAIN)
    	{
            g_alm_temp_repeat_type = menu_evt->highlighted_menu_id;
    	    if (g_alm_freq_set[menu_evt->highlighted_menu_id] != ALM_FREQ_DAYS)
        	{   
                /* Update the repeat type */
                g_alm_cntx.CurrHiliteFreq = g_alm_temp_repeat_type;
                g_alm_repeat_type_changed = MMI_TRUE;
                mmi_frm_group_close(GRP_ID_ALM_REPEAT_TYPE_MENU);
        	}
            else
            {
                mmi_alm_entry_repeat_type_custom_menu(GRP_ID_ALM_REPEAT_TYPE_MENU);
            }
            return MMI_RET_OK;
    	}
        else if (menu_evt->parent_menu_id == MENU_ID_ALM_REPEAT_TYPE_CUSTOM_OPTION_MENU)
        {
            if (menu_evt->highlighted_menu_id == ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH)
        	{
        	    mmi_alm_repeat_type_custom_switch_status(g_alm_temp_highlighted_week_day);
                cui_menu_close(menu_evt->sender_id);
                return MMI_RET_OK;
        	}
            else if (menu_evt->highlighted_menu_id == ALARM_CUSTOM_OPTIONS_DONE)
            {
                if (!mmi_alm_is_valid_cust_repeat(ALM_FREQ_DAYS, g_alm_temp_custom_repeat_week_day))
            	{
            	    /* No week day selected */
                    cui_menu_close(menu_evt->sender_id);
                    mmi_popup_display_simple((WCHAR*)GetString(STR_ID_ALM_NO_MARKED), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
            	}
                else
                {
                    /* Update the repeat type */
                    g_alm_cntx.CurrHiliteFreq = g_alm_temp_repeat_type;
                    memcpy(gAlmDaysStates, g_alm_temp_custom_repeat_week_day, sizeof(U8) * NUM_DAYS);
                    g_alm_repeat_type_changed = MMI_TRUE;
                    mmi_frm_group_close(GRP_ID_ALM_REPEAT_TYPE_MENU);   
                }
                return MMI_RET_OK;
            }
        } 
#else
		if (menu_evt->parent_menu_id == MENU_ID_ALM_REPEAT_TYPE_MAIN)
    	{
            g_alm_temp_repeat_type = menu_evt->highlighted_menu_id - MENU_ID_ALM_REPEAT_TYPE_ONCE;
    	    if (g_alm_freq_set[g_alm_temp_repeat_type] != ALM_FREQ_DAYS)
        	{   
                /* Update the repeat type */
                g_alm_cntx.CurrHiliteFreq = g_alm_temp_repeat_type;
                g_alm_repeat_type_changed = MMI_TRUE;
                mmi_frm_group_close(GRP_ID_ALM_REPEAT_TYPE_MENU);
        	}
            else
            {
                mmi_alm_entry_repeat_type_custom_menu(GRP_ID_ALM_REPEAT_TYPE_MENU);
            }
            return MMI_RET_OK;
    	}
		else if (menu_evt->parent_menu_id == MENU_ID_ALM_REPEAT_TYPE_CUSTOM_OPTION_MENU)
        {
			
			if (menu_evt->highlighted_menu_id == MENU_ID_ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH_ON ||
				menu_evt->highlighted_menu_id == MENU_ID_ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH_OFF)
	        	{
					mmi_alm_repeat_type_custom_switch_status(g_alm_temp_highlighted_week_day);
	                cui_menu_close(menu_evt->sender_id);
	                return MMI_RET_OK;
	        	}
	          else if (menu_evt->highlighted_menu_id == MENU_ID_ALARM_CUSTOM_OPTIONS_DONE)
	            {
	                if (!mmi_alm_is_valid_cust_repeat(ALM_FREQ_DAYS, g_alm_temp_custom_repeat_week_day))
	            	{
	            	    /* No week day selected */
	                    cui_menu_close(menu_evt->sender_id);
	                    mmi_popup_display_simple((WCHAR*)GetString(STR_ID_ALM_NO_MARKED), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
	            	}
	                else
	                {
	                    /* Update the repeat type */
	                    g_alm_cntx.CurrHiliteFreq = g_alm_temp_repeat_type;
	                    memcpy(gAlmDaysStates, g_alm_temp_custom_repeat_week_day, sizeof(U8) * NUM_DAYS);
	                    g_alm_repeat_type_changed = MMI_TRUE;
	                    mmi_frm_group_close(GRP_ID_ALM_REPEAT_TYPE_MENU);   
	                }
	                return MMI_RET_OK;
	            }
		}
#endif
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        return MMI_RET_OK;
        
    case EVT_ID_GROUP_DEINIT:
        if (g_alm_repeat_type_changed)
        {
            cui_inline_set_value(g_alm_cntx.curr_gid, 
                                 CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_REPEAT, 
                                 (void*)mmi_alm_inline_get_repeat_type_string());
            
            cui_inline_set_screen_attributes(g_alm_cntx.curr_gid, 
                                         CUI_INLINE_SET_ATTRIBUTE, 
                                         CUI_INLINE_SCREEN_CHANGED);
        }
        return MMI_RET_OK;
#ifndef __MMI_DEV_NEW_SLIM__        
	default:
		break;
#endif
	}
#ifndef __MMI_DEV_NEW_SLIM__
    if (cui_menu_is_menu_event(evt->evt_id))
	{
	    return MMI_RET_DONT_CARE;
	}
#endif
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_init_repeat_type_main_menu
 * DESCRIPTION
 *  Init the menu of repeat type setting main menu 
 * PARAMETERS
 *  cui_gid     :   [IN] group ID of menu CUI
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_alm_init_repeat_type_main_menu(MMI_ID cui_gid)
{
#ifndef __MMI_DEV_NEW_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_num = ALARM_FREQ_NUM; 
    U8 i;
    mmi_menu_id *menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = (mmi_menu_id*)OslMalloc(item_num * sizeof(mmi_menu_id));
    for(i = 0; i < item_num; i++)
    {
        menu_id[i]=(mmi_menu_id)i;
    }
    
    cui_menu_set_currlist_title(cui_gid, (WCHAR*) GetString(ALARM_REPEAT_STRING), (UI_image_type)GetImage(GetRootTitleIcon(ORGANIZER_ALARM_MENU)));
    
    cui_menu_set_currlist(cui_gid, item_num, menu_id);
    
    cui_menu_set_currlist_flags(cui_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    if (!mmi_frm_is_in_backward_scenario())
	{
        cui_menu_set_currlist_highlighted_id(cui_gid, g_alm_cntx.CurrHiliteFreq);
	}

    for(i = 0; i < item_num; i++)
    {
        cui_menu_set_item_string(cui_gid, i, (WCHAR*)GetString(gAlmFreqList[i]));
    }

    OslMfree(menu_id); 
#else
	
	cui_menu_set_default_title_by_id(cui_gid, ALARM_REPEAT_STRING, NULL);
	cui_menu_set_currlist_flags(cui_gid, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

	if (!mmi_frm_is_in_backward_scenario())
	{
		cui_menu_set_currlist_highlighted_id(cui_gid, g_alm_cntx.CurrHiliteFreq + MENU_ID_ALM_REPEAT_TYPE_ONCE);
	}


#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_init_repeat_type_main_menu
 * DESCRIPTION
 *  Init the menu of repeat type setting main menu 
 * PARAMETERS
 *  cui_gid     :   [IN] group ID of menu CUI
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_alm_init_custom_options_menu(MMI_ID cui_gid)
{
	S32 j = g_alm_temp_highlighted_week_day;

#ifndef __MMI_DEV_NEW_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_num = ALARM_CUSTOM_OPTIONS_TOTAL; 
    mmi_menu_id menu_id[] = {ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH, ALARM_CUSTOM_OPTIONS_DONE};
    U16 switch_string_id = STR_GLOBAL_ON;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_currlist_title(cui_gid, (WCHAR*) GetString(STR_GLOBAL_OPTIONS), (UI_image_type)GetImage(GetRootTitleIcon(ORGANIZER_ALARM_MENU)));
    
    cui_menu_set_currlist(cui_gid, item_num, menu_id);
    
    cui_menu_set_currlist_flags(cui_gid, CUI_MENU_NORMAL_LIST);

	#ifdef	__MMI_CALENDAR_FDOW__
	if(mmi_clndr_get_week_first_day())
	{
		j = (g_alm_temp_highlighted_week_day+1)%7;
	}
	#endif

    if (g_alm_temp_custom_repeat_week_day[j])
	{
        switch_string_id = STR_GLOBAL_OFF;
	}

    cui_menu_set_item_string(cui_gid, ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH, (WCHAR*)GetString(switch_string_id));    
    cui_menu_set_item_string(cui_gid, ALARM_CUSTOM_OPTIONS_DONE, (WCHAR*)GetString(STR_GLOBAL_DONE));    
#else
	cui_menu_set_default_title_by_id(cui_gid, STR_GLOBAL_OPTIONS, NULL);
#ifdef	__MMI_CALENDAR_FDOW__
	if(mmi_clndr_get_week_first_day())
	{
		j = (g_alm_temp_highlighted_week_day+1)%7;
	}
#endif
	if (g_alm_temp_custom_repeat_week_day[j])
	{
         cui_menu_set_item_hidden(cui_gid, MENU_ID_ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH_ON, MMI_TRUE);
		 cui_menu_set_item_hidden(cui_gid, MENU_ID_ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH_OFF, MMI_FALSE);
	}
	else
	{
		 cui_menu_set_item_hidden(cui_gid, MENU_ID_ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH_ON, MMI_FALSE);
		 cui_menu_set_item_hidden(cui_gid, MENU_ID_ALARM_CUSTOM_OPTIONS_WEEKDAY_SWITCH_OFF, MMI_TRUE);
	}

#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_group_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_alm_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
#ifdef __MMI_DEV_NEW_SLIM__
	mmi_frm_group_close(g_alm_cntx.curr_gid);
#else
        mmi_frm_group_close(mmi_alm_get_curr_group());
#endif
        break;
        
#ifdef __MMI_ALM_CUSTOMIZE_TONE__
	case EVT_ID_CUI_TONE_SELECTOR_CLOSE_REQUEST:
        {
            cui_tone_selector_evt_struct * evt_cui = (cui_tone_selector_evt_struct *)evt;
    		cui_tone_selector_close(evt_cui->sender_id);
        }
		break;
		
	case EVT_ID_CUI_TONE_SELECTOR_RESULT:
        {
            cui_tone_selector_evt_struct * evt_cui = (cui_tone_selector_evt_struct *)evt;
            if (evt_cui->is_default_sound)
            {
            g_alm_cntx.CurrHiliteAudioOptionValue = evt_cui->selected_tone;
        }
            else
            {
                S32 ret;                
                srv_fmgr_fileinfo_struct file_info;

                ret = cui_tone_selector_get_selected_filepath(evt_cui->sender_id, 
                                                              &file_info, 
                                                              (WCHAR *)g_alm_cntx.tone_path, 
                                                              SRV_FMGR_PATH_BUFFER_SIZE);
                if (ret < 0)
                {
                    /* Do something*/
                }        
                else
                {
                    g_alm_cntx.CurrHiliteAudioOptionValue = ALARM_TONE_FILE;
                }                
            }            
            g_alm_cntx.audio_select = MMI_TRUE;
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__		
			g_alm_prev_tone_value= g_alm_cntx.CurrHiliteAudioOptionValue;
#endif
        }
        break; 
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__        
     case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

            if (menu_evt->parent_menu_id == MENU_ID_ALM_FMRADIO_CHANNEL_LIST_OPTION)
            {
                mmi_menu_id menu_list[2] = {
                        MENU_ID_ALM_FMRADIO_OPTION_SELECT, 
                        MENU_ID_ALM_FMRADIO_OPTION_PREVIEW
                    };

                cui_menu_set_default_title_image(menu_evt->sender_id, (UI_image_type)GetImage(GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID)));
                cui_menu_set_default_title_string(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_OPTIONS));
                cui_menu_set_currlist(menu_evt->sender_id, 2, menu_list);
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_ALM_FMRADIO_OPTION_SELECT, (WCHAR*)GetString(STR_GLOBAL_SELECT));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_ALM_FMRADIO_OPTION_PREVIEW, (WCHAR*)GetString(STR_GLOBAL_PLAY));            
            }
	    else if (menu_evt->parent_menu_id == MENU_ID_ALM_AUDIO_OPT_FMRADIO)
	    {
		    cui_menu_set_default_title_image(menu_evt->sender_id, (UI_image_type)GetImage(GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID)));
	    	cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_ALM_FMRADIO_CHANNEL_LIST, MMI_FALSE);
	    }
            //cui_menu_enable_cascading_option_menu(evt->sender_id);
        }
        break;
        
    case EVT_ID_CUI_MENU_LIST_EXIT:
        {
        }
        break;
        
    case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
        }
        break;
        
    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            if (menu_evt->parent_menu_id == MENU_ID_ALM_AUDIO_OPT_FMRADIO)
            {
                if (menu_evt->highlighted_menu_id == MENU_ID_ALM_FMRADIO_CHANNEL_LIST)
                {
                    mmi_alm_entry_aud_opt_fmrdo_channel_list();
                }
                else if (menu_evt->highlighted_menu_id == MENU_ID_ALM_FMRADIO_MANUAL_INPUT)
                {
                    mmi_alm_entry_fmrdo_manual_input();
                }
            }
            /* channel list option menu */
            else if (menu_evt->parent_menu_id == MENU_ID_ALM_FMRADIO_CHANNEL_LIST_OPTION)
            {
                if (menu_evt->highlighted_menu_id == MENU_ID_ALM_FMRADIO_OPTION_SELECT)
                {
                    mmi_alm_aud_opt_fmrdo_channel_opt_select();
                }
                else if (menu_evt->highlighted_menu_id == MENU_ID_ALM_FMRADIO_OPTION_PREVIEW)
                {
                    mmi_alm_aud_opt_fmrdo_channel_opt_play();
                }
            }
        }
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
			cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            cui_menu_close(menu_evt->sender_id);
        }
        break;
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */
    //INLINE item
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        { 
	    if (g_alm_cntx.audio_select)
            {
                CHAR *temp_string;
                U32 scr_attr = cui_inline_get_screen_attributes(g_alm_cntx.curr_gid);
                if (!(scr_attr & CUI_INLINE_SCREEN_CHANGED))
                {
                    cui_inline_set_screen_attributes(g_alm_cntx.curr_gid, 
                                                 CUI_INLINE_SET_ATTRIBUTE, 
                                                 CUI_INLINE_SCREEN_CHANGED);
                }
                mmi_alm_get_tone_string(&temp_string);
                cui_inline_set_value(g_alm_cntx.curr_gid, 
                                     CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_TONE_STRING, 
                                     (void*)temp_string);

                g_alm_cntx.audio_select = MMI_FALSE;
            }         
		}
        break;
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */

    case EVT_ID_CUI_INLINE_SUBMIT:
    {
        #ifdef __ORIGINAL_DOW__
        U8 days_buffer[NUM_DAYS];
		
        cui_inline_get_value(g_alm_cntx.curr_gid, 
                             CUI_INLINE_ITEM_ID_BASE + MMI_ALM_INLINE_DOW,
                             days_buffer);

        if (!mmi_alm_is_valid_cust_repeat(g_alm_freq_set[g_alm_cntx.CurrHiliteFreq], days_buffer) 
            && g_alm_cntx.CurrHiliteState == 1)
        {
            mmi_alm_entry_disable_alm_confirm();
        }
        else
        #endif /* __ORIGINAL_DOW__ */
		{
		    // check if vaild and save; not popup confirm anymore
            EntryAlmSaveConfirmation();     
			AlmSaveInlineEdit();
        }   
        break;
    }    

    case EVT_ID_CUI_INLINE_NOTIFY:
    {
        cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
        if (inline_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
        {
            mmi_alm_inline_highlight_handler(
                inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE,
                inline_evt->param);
        }
        else if (inline_evt->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
        {
            mmi_alm_inline_select_handler(
                inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE,
                inline_evt->param);
        }
    }
    break;
            
    case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(g_alm_cntx.curr_gid);
        break;
 #ifndef __MMI_DEV_NEW_SLIM__           
    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
    {

    }
    break;

    case EVT_ID_ALERT_QUIT:
    {
        mmi_alm_alert_pop_handler((mmi_alert_result_evt_struct *)evt);
    }
    break;
#endif
    case EVT_ID_CUI_INLINE_CSK_PRESS:
	{
		cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
		if(menu_evt->parent_menu_id == (MMI_ALM_INLINE_STATUS + CUI_INLINE_ITEM_ID_BASE)|| 
           menu_evt->parent_menu_id == (MMI_ALM_INLINE_TIME + CUI_INLINE_ITEM_ID_BASE))
		{
		    AlmSaveInlineEdit();
		}
		
	    #ifdef __MMI_ALM_ALERT_TYPE__
		if(menu_evt->parent_menu_id == (MMI_ALM_INLINE_ALERT_TYPE + CUI_INLINE_ITEM_ID_BASE))
		{
		    AlmSaveInlineEdit();
		} 
	    #endif
		break;
    }
#ifndef __MMI_DEV_NEW_SLIM__	
    default:
        break;
#endif		
    }
	
	return MMI_RET_OK;
}

#ifndef __MMI_DEV_NEW_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_alert_pop_handler
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_alm_alert_pop_handler(mmi_alert_result_evt_struct *alert_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 user_tag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(alert_evt->result)
    {
        case MMI_POPUP_NORMAL_EXIT:
	    user_tag = *(U16*)alert_evt->user_tag;
	    if (user_tag == STR_GLOBAL_SAVED)
	    {
	        mmi_frm_group_close(GRP_ID_ALM_EDITOR);

            }
            break;

		case MMI_ALERT_INTERRUPT_EXIT:
			user_tag = *(U16*)alert_evt->user_tag;
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
            if (user_tag == STR_ID_ALM_FMRDO_HEADFONE_REMINDER)
            {
                mmi_alm_display_popup();

				mmi_frm_group_close(GRP_ID_ALM_EDITOR);
            }
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */   
			break;

        case MMI_ALERT_CNFM_OK:
			user_tag = *(U16*)alert_evt->user_tag;
#ifdef __MMI_ALM_FM_RADIO_SUPPORT__
            if (user_tag == STR_ID_ALM_FMRDO_HEADFONE_REMINDER)
            {
                mmi_alm_display_popup();
            }
#endif /* __MMI_ALM_FM_RADIO_SUPPORT__ */            
            break;


        case MMI_ALERT_CNFM_YES:
			user_tag = *(U16*)alert_evt->user_tag;
            if (user_tag == STR_GLOBAL_SAVE_ASK)
            {
                AlmSaveInlineEdit();
            }
            else if (user_tag == STR_ID_ALM_DISABLE_ASK)
            {
                g_alm_cntx.CurrHiliteState = 0;
                AlmSaveInlineEdit();
            }

            break;
                
        case MMI_ALERT_CNFM_NO:
			user_tag = *(U16*)alert_evt->user_tag;
            if (user_tag == STR_GLOBAL_SAVE_ASK)

            {
                mmi_frm_group_close(GRP_ID_ALM_EDITOR);
            }
            else
            {
                mmi_frm_scrn_close_active_id();
            }
            
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_curr_group
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static U16 mmi_alm_get_curr_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_alm_cntx.curr_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_set_curr_group
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_alm_set_curr_group(U16 grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_alm_cntx.curr_gid = grp_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_alarm_freq
 * DESCRIPTION
 *  get freq by freq index in freq array
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_alm_get_alarm_freq(U8 freq_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(freq_order < ALARM_FREQ_NUM);
    
    return g_alm_freq_set[freq_order];
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_alarm_freq_order
 * DESCRIPTION
 *  get index by freq value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_alm_get_order_in_alm_freq(U8 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0xFF;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(freq < ALM_FREQ_TOTAL);
    
	for (i = 0; i <  ALARM_FREQ_NUM; i++)
	{
		if (g_alm_freq_set[i] == freq)
		{
			break;
		}
	}
	
	if (i == ALARM_FREQ_NUM)
	{
		i = 0;
	}
	
    return (i >= ALARM_FREQ_NUM) ? 0 : i;
}

#ifndef __MMI_DEV_NEW_SLIM__ 

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_default_ring_id
 * DESCRIPTION
 *  get alarm frequency
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_alm_default_ring_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return ALARM_DEFAULT_RING_ID;
}


void mmi_alm_get_info(U8 index, U8 *hour, U8 *min, U8 *state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_alm_node_type *node;
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < NUM_OF_ALM);

	node = srv_alm_read(index);
	*hour = node->Hour;
	*min = node->Min;
	*state = node->State;
}

MMI_BOOL mmi_alm_get_alm_time(MYTIME *ActualTime, U8 index, MMI_BOOL snooze)
{
	return srv_alm_get_alm_time(ActualTime, index, snooze);
}

#endif

