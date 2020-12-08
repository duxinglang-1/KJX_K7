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
 * notification.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is framework notification manager module which control the behavior 
 *   of all interrupt events.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#include "NotificationGprot.h"
#include "NotificationProt.h"
#include "ProfilesSrvGprot.h"
#include "IdleNotificationManagerGprot.h"
#include "mdi_audio.h"
#include "IdleGprot.h"
#include "UcmSrvGprot.h"
#include "Resource_audio.h"
#include "Dmuigprot.h"
#include "BootupSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "custom_led_patterns.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_list.h"
#include "kal_public_api.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "custom_events_notify.h"
#include "wgui_categories_popup.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_idle_nmgr_def.h"
#include "custom_srv_prof_defs.h"
#include "string.h"
#include "gpiosrvgprot.h"
#include "UcmSrvGProt.h"
#include "mmi_rp_srv_nmgr_def.h"
#include "AlertScreen.h"

#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)
#ifdef __COSMOS_MMI_PACKAGE__
	#include "mmi_rp_vapp_ucm_def.h"
#else
	#include "mmi_rp_app_ucm_def.h"
#endif
#endif
#include "Wgui_categories_util.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "vadp_v2p_nmgr.h"
#include "vapp_screen_lock_gprot.h"
#include "vadp_p2v_uc.h"
#endif

#include "ScrLockerGprot.h"    

#if (defined(__OP01_3G__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_app_sms_def.h"
#include "SmsSrvGProt.h"
#include "MmsSrvGprot.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "UMGprot.h"
#include "browser_api.h"
#include "WAPPushSrvGProts.h"
#include "UCMGProt.h"
#ifdef __MMI_EMAIL__
#include "mmi_rp_app_email_def.h"
#endif
#ifdef __MMI_PROV_IN_UM__
#include "ProvBoxSrvGProt.h"
#endif
#endif
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "fix_size_mem.h"
#include "mdi_video.h"
#include "mdi_mtv.h"
#include "ReminderSrvGprot.h"
#include "SensorSrvGport.h"
#include "mmi_rp_srv_editor_def.h"
#include "NotificationSettingSrvGprot.h"

/***************************************************************************** 
 * <Prototype> : 
 * Target : Centrolly control notification scenario attribute, screen, sound, vibration, backlight.
 *
 * [Active scenario] :
 * Should mmi_frm_start_scenario firstly, and initialize context information, like seting priority of scenario attribute;
 * Could mmi_frm_set_scenario_info to change attributes;
 * Should mmi_frm_end_scenario to release resource;
 *
 * [Notification scenario] :
 * Should mmi_frm_start_scenario firstly, and initialize context information, like seting priority of scenario attribute;
 * Should mmi_frm_end_scenario to release resource;
 *
 *****************************************************************************/
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    mmi_scenario_id scen_id;
    U32             event_type;
    U32             flag;
} mmi_nmgr_scen_map_struct;

/*Create for text preview queue usage*/
typedef struct
{
    U32 event_type;
    U32 option;
    WCHAR  *text;
    /*below are new add for alert api*/
    MMI_ID app_id;    
    U16 image_type;
    union{
      /*resource id*/
      U16 id;
      /*image file path*/
      WCHAR *file_path;
      /*data buffer with 8 bytes header(size + format)*/
      U8 *data;
      /*raw data buffer wo 8 bytes header*/
      struct
       {    
           U8 *buff; 
           U32 size;
           U32 format;
       }raw_data;       
    }image;                  
    mmi_frm_nmgr_alert_status_bar_icon_struct status_bar_icon_para; 
    mmi_frm_nmgr_alert_app_proc_struct app_proc_para;
} mmi_nmgr_preview_info_struct;

typedef struct
{
    U8 count;
    U8 rindx;
    U8 windx;
    mmi_nmgr_preview_info_struct queue[MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM];
} mmi_nmgr_preview_queue_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_scenario_id scenario_id;
    mmi_event_notify_enum type;
    mmi_nmgr_balloon_type_enum balloon_type;
    WCHAR string[MMI_FRM_NMGR_BALLOON_TEXT_CHAR_BUF_LEN];
} mmi_nmgr_balloon_evt_struct;

typedef struct
{
	MMI_EVT_PARAM_HEADER
    mmi_scenario_id scenario_id;
    mmi_event_notify_enum type;
	mmi_frm_notification_para_struct noti;
} mmi_nmgr_preview_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_frm_nmgr_alert_struct noti;
} mmi_nmgr_alert_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    NMGR_HANDLE open_handle;
} mmi_frm_alert_cancel_evt_struct;



typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_event_notify_enum type;
} mmi_nmgr_cancel_preview_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_scenario_id noti_scen_id;
    srv_prof_tone_enum tone_id;
    mmi_noti_attr_beha_enum behavior;
    mmi_nmgr_behavior_enum action;    
    MMI_BOOL display_scrn;
    mmi_frm_nmgr_alert_snd_struct snd_info;
} mmi_nmgr_sound_play_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_scenario_id noti_scen_id;
    mmi_noti_attr_beha_enum behavior;
    mmi_nmgr_behavior_enum action;
} mmi_nmgr_vib_play_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_noti_attr_beha_enum behavior;
    mmi_nmgr_behavior_enum action;
} mmi_nmgr_bl_ctrl_evt_struct;

typedef struct
{
	mmi_scenario_id scen_id;
	U16 confirm_type;
	WCHAR *title;
} nmgr_confirm_cntx_struct;

typedef struct
{
	MMI_ID confirm_id;
	nmgr_confirm_cntx_struct *cntx;
} nmgr_confirm_queue_item_struct;

#ifdef __PLUTO_MMI_PACKAGE__
typedef struct _nmgr_alert_popup_active_item_struct
{
    MMI_BOOL popup_pressed;
    mmi_id  popup_scrn_group_id;
    mmi_frm_nmgr_alert_struct popup_info;
    struct _nmgr_alert_popup_active_item_struct* next;
} nmgr_alert_popup_active_item_struct;

typedef struct
{
    U32 list_counter;
    nmgr_alert_popup_active_item_struct *next; 
} nmgr_alert_popup_active_list_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_proc_func scrn_group_proc;    
    void *proc_user_data;
} mmi_nmgr_cb_evt_struct;

#endif

#ifdef __MMI_NSS_SUPPORT__
typedef struct
{
    MMI_ID app_id;
    U32 alert_option;
    S32 icon_id; 
} nmgr_support_nss_ncenter_setting_struct;
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_NMGR_CONFIRM_SCREEN_NUM 2
#define NMGR_ALERT_PLUTO_POPUP_RSK_ID 1
#define NMGR_ALERT_PLUTO_POPUP_LSK_ID 2

/***************************************************************************** 
 * Local variable
 *****************************************************************************/
#ifdef MOTION_SENSOR_SUPPORT
static SRV_SENSOR_HANDLE g_nmgr_sensor_handle;
#endif
#if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
static nmgr_confirm_queue_item_struct nmgr_confirm_queue[MAX_NMGR_CONFIRM_SCREEN_NUM];
#endif

#ifdef __IV_TTS__
static mmi_ret nmgr_control_proc(mmi_event_struct *evt);
mmi_nmgr_sound_play_evt_struct g_nmgr_ivtts_evt;
int ivtts_app_in_msg_notify_is_correct_type ( mmi_event_notify_enum notify_type )
{
	if 
	(      notify_type == MMI_EVENT_SMS
   		|| notify_type == MMI_EVENT_SLAVE_SMS 
   		|| notify_type == MMI_EVENT_MMS
   		|| notify_type == MMI_EVENT_SLAVE_MMS
   	)
	{
		return 1;
	}
	else
	{
		
		return 0;
	}
}
void mmi_nmgr_ivtts_save_evt ( mmi_nmgr_sound_play_evt_struct evt )
{
    g_nmgr_ivtts_evt.noti_scen_id = evt.noti_scen_id;
    g_nmgr_ivtts_evt.tone_id = evt.tone_id;
    g_nmgr_ivtts_evt.behavior = evt.behavior;
    g_nmgr_ivtts_evt.action = evt.action;
    g_nmgr_ivtts_evt.display_scrn = evt.display_scrn;
    g_nmgr_ivtts_evt.snd_info = evt.snd_info;
}
void control_sound(mmi_scenario_id noti_scen_id, srv_prof_tone_enum tone_id, mmi_noti_attr_beha_enum behavior, mmi_nmgr_behavior_enum action, MMI_BOOL display_scrn,mmi_frm_nmgr_alert_snd_struct *snd_info);

void mmi_nmgr_ivtts_paly_tone( void )
{
    yttts_player_engine_free();
    control_sound(
        g_nmgr_ivtts_evt.noti_scen_id, 
        g_nmgr_ivtts_evt.tone_id,
        g_nmgr_ivtts_evt.behavior,
        g_nmgr_ivtts_evt.action,
        g_nmgr_ivtts_evt.display_scrn,
        NULL);
}
#endif

#ifdef __MMI_NCENTER_SUPPORT__
typedef struct
{
    MMI_BOOL is_used;
    CHAR data_buf[MMI_FRM_NMGR_USER_DATA_LEN];
} nmgr_ncenter_user_data_struct;


static WCHAR text[MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM][MMI_FRM_NMGR_TEXT_PREVIEW_TEXT_BUF_LEN];
static nmgr_ncenter_user_data_struct data[MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM];

static WCHAR preview_text[MMI_FRM_NMGR_TEXT_PREVIEW_TEXT_BUF_LEN];
static __align(4) CHAR preview_data[MMI_FRM_NMGR_USER_DATA_LEN];


static mmi_nmgr_preview_info_struct active_info;
static mmi_nmgr_preview_queue_struct preview_queue;
static MMI_BOOL is_on_preview = MMI_FALSE;
static MMI_BOOL g_is_app_launched = MMI_FALSE;
#endif
#ifdef __COSMOS_MMI_PACKAGE__ 
static S32 g_balloon_icon = STATUS_ICON_INVALID_ID;
#endif
#ifdef __PLUTO_MMI_PACKAGE__
static nmgr_alert_popup_active_list_struct g_nmgr_active_popup_list = {0,0};
static nmgr_alert_popup_active_item_struct* g_active_popup = NULL;
#endif

#if defined(__MMI_NSS_SUPPORT__) && defined(__MMI_NCENTER_SUPPORT__)
#define MAXIMUM_STATUS_ICON_NUM 10
static nmgr_support_nss_ncenter_setting_struct g_nss_app_icon[MAXIMUM_STATUS_ICON_NUM];
#endif
/*popup text , button text , temp balloon, temp text preview
    pluto or cosmos popup info*/
#define NMGR_DEFER_POPUP_POOL_SIZE (MMI_DEFER_NOTIFICATION_NUM*MMI_FRM_NMGR_POPUP_TEXT_BUF_LEN*sizeof(WCHAR) + \
					   	   MMI_DEFER_NOTIFICATION_NUM*MMI_FRM_NMGR_BUTTON_TEXT_BUF_LEN*sizeof(WCHAR))

#define NMGR_CON_POPUP_POOL_SIZE (MMI_MAX_CONCURRENT_POPUP_NUM*MMI_FRM_NMGR_POPUP_TEXT_BUF_LEN*sizeof(WCHAR) + \
					   	   MMI_MAX_CONCURRENT_POPUP_NUM*MMI_FRM_NMGR_BUTTON_TEXT_BUF_LEN*sizeof(WCHAR) + \
                                                        sizeof(mmi_frm_nmgr_alert_struct)*MMI_MAX_CONCURRENT_POPUP_NUM)

#define NMGR_USER_DATA_POOL_SIZE ((MMI_MAX_CONCURRENT_POPUP_NUM+MMI_DEFER_NOTIFICATION_NUM)*MMI_FRM_NMGR_USER_DATA_LEN)

#define NMGR_MEM_POOL_SIZE (NMGR_DEFER_POPUP_POOL_SIZE + \
							NMGR_CON_POPUP_POOL_SIZE + \
							sizeof(WCHAR)*MMI_FRM_NMGR_TEXT_PREVIEW_TEXT_BUF_LEN + \
							sizeof(WCHAR)*MMI_FRM_NMGR_BALLOON_TEXT_CHAR_BUF_LEN + \
							NMGR_USER_DATA_POOL_SIZE)

static CHAR g_nmgr_mem_pool[NMGR_MEM_POOL_SIZE];

static mmi_defer_info_struct mmi_notify_defer_info_cntx;
static srv_prof_tone_enum noti_tone_id = NONE_TONE;
static srv_prof_tone_enum dtmf_id = NONE_TONE;
static U8 g_nmgr_block_tone_vib = 0;

static MMI_BOOL vib_on;
static MMI_BOOL disable_invoke_defer_event = MMI_FALSE;
static MMI_BOOL is_in_defer_process;
static MMI_BOOL only_control_scrn = MMI_FALSE;
static MMI_BOOL need_resume_bk_play = MMI_FALSE;
static void *g_timer_arg = NULL;
static MMI_BOOL g_enable_nmgr =  MMI_TRUE;
static MMI_BOOL g_is_alert_init =  MMI_FALSE;

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
const static mmi_nmgr_scen_map_struct scen_map_table[] = 
{
    {MMI_SCENARIO_ID_MISSED_CALL,       MMI_NMGR_APP_MISSED_CALL,       MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_NEW_SMS,           MMI_NMGR_APP_SMS,               MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_NEW_MMS,           MMI_NMGR_APP_MMS,               MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_NEW_EMAIL,         MMI_NMGR_APP_EMAIL,             MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_WAP_PUSH,          MMI_NMGR_APP_WAP_PUSH,          MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_CELL_BROADCAST,    MMI_NMGR_APP_CELL_BROADCAST,    MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_SIM_SMS,           MMI_NMGR_APP_SIM_SMS,           MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_MESSAGE_WAITING, MMI_NMGR_APP_MESSAGE_WAITING, MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_PROVISIOING,       MMI_NMGR_APP_PROVISIOING,       MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_CCA,               MMI_NMGR_APP_CCA,               MMI_NMGR_OPTION_USE_DEFAULT|MMI_NMGR_OPTION_CONFIRM_CANCEL|MMI_NMGR_OPTION_SELF_CANCEL_ON_EXEC},
    {MMI_SCENARIO_ID_VOBJECT,           MMI_NMGR_APP_VOBJ,              MMI_NMGR_OPTION_USE_DEFAULT|MMI_NMGR_OPTION_CONFIRM_CANCEL},
    {MMI_SCENARIO_ID_NEW_SMS_REPORT,    MMI_NMGR_APP_SMS_REPORT,        MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_NEW_MMS_REPORT,    MMI_NMGR_APP_MMS_REPORT,        MMI_NMGR_OPTION_USE_DEFAULT},
    {MMI_SCENARIO_ID_INVALID,           MMI_NMGR_APP_NULL,              MMI_NMGR_OPTION_NULL}
};
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/********************************************************************************************
 * app => scenario id    -> priority -> scenario             -|   
 *                                   -> sound                 | => (static-register <default behavior>)
 *                                   -> vibration             |
 *                                   -> backlight            -|
 *                        -> event 1 -> priority -> ...           (dynamic-register <customized behavior>)
 *                                   -> event type -> tone type
 *                                                 -> img type
 *                                                 -> timer duration
 *                        -> ......
 ********************************************************************************************/

#ifdef MMI_NOTI_MGR_UT
static MMI_BOOL show_poup;
static MMI_BOOL play_sound;
srv_prof_tone_enum   play_sound_id;
static MMI_BOOL play_vibrator;
static MMI_BOOL play_backlight;
static mmi_nmgr_behavior_enum scrn_action;
static mmi_nmgr_behavior_enum snd_action;
static mmi_nmgr_behavior_enum vib_action;
static mmi_nmgr_behavior_enum bl_action;
static mmi_scenario_id_internal scenario_end;
#endif /* MMI_NOTI_MGR_UT */

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_NOTIFY_COMM_POPUP              (1)
#define MMI_NOTIFY_BY_IDLE                 (2)
#define MMI_NOTIFY_BY_APP                  (3)
#define MMI_NOTIFY_SUBLCD                  (4)
#define MMI_NOTIFY_PREVIEW                 (5)
#define MMI_NOTIFY_BALLOON                 (6)
#define MMI_NOTIFY_ALERT                 (7)

#define MMI_NOTIFY_INVOKE_TIME             (1000)  /* next notify invoke time (ms) */
#define MMI_NOTIFY_SOUND_TIME_BOUNDARY     (10000) /* 10s */
#define MMI_NMGR_VIB_THEN_RING_DURATION    (6000)

#define MMI_INIT_SCENARIO_STRUCT(_scen_struct_p, _scen_id)  \
        do {    \
            memset((_scen_struct_p), 0, sizeof(*(_scen_struct_p)));  \
            (_scen_struct_p)->scenario_id = (_scen_id);             \
        } while(0)

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
#define SCEN_MAP_TABLE_SIZE (sizeof(scen_map_table) / sizeof(scen_map_table[0]))
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*
 * Special condition of sound
 * 1. during an outgoing call or in-call, interrupt sound should be short and subtle if it's allowed to play 
 *    Solution: app configure in mmi_events_notify_tbl, like sms, mms;
 * 2. should never stop or suspend the sound of outgoing call or in-call
 * 3. recording a sound or video, interrupt sound can't be played except incoming call
 */

static void invoke_custom_sound(mmi_scenario_id scenario_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_custom_evt_struct play_snd_evt;  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_FRM_INIT_EVENT(&play_snd_evt, EVT_ID_NMGR_PLAY_TONE);   
    play_snd_evt.scenario_id = scenario_id; 
    MMI_FRM_CB_EMIT_EVENT(&play_snd_evt);  
}

/*
 * Special condition of vibrator
 * 1. never be used in an outgoing call or in-call
 * 2. recording a sound or video never be used except for incoming call
 * 3. camera works as webcam never be used, except for incoming call
 */

static void invoke_custom_vibrator(mmi_scenario_id scenario_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* According to interrupt rule, disable vibrator in scenario of IN CALL and OUTGOING CALL */
    if (mmi_frm_get_active_scenario_id() != MMI_SCENARIO_ID_IN_CALL && mmi_frm_get_active_scenario_id() != MMI_SCENARIO_ID_UCM_OUTGOING_CALL)   
    {   
        mmi_nmgr_custom_evt_struct play_vib_evt;    
        MMI_FRM_INIT_EVENT(&play_vib_evt, EVT_ID_NMGR_PLAY_VIB);    
        play_vib_evt.scenario_id = scenario_id;    
        MMI_FRM_CB_EMIT_EVENT(&play_vib_evt);   
    }   
}

#define SOUND_PLAY_EVT   (0)
#define VIB_PLAY_EVT     (1)
#define BACKLIGHT_CTRL   (2)

#define MMI_NMGR_CONFIRM_POPUP_TEMP_STRING_BUF_LEN  (60)
/***************************************************************************** 
 * Internal Interface prototype
 *****************************************************************************/

typedef struct
{
   /*Scenario ID for compare the priority with current scenario*/
   mmi_scenario_id noti_scen_id;
   /*Event ID for checking which notification(sound, vibration..,etc) wil be displayed*/
   mmi_event_notify_enum notify_type;
   /*For display to user*/
   WCHAR *string;
   /*Fill in the scrn entey if user want to show their own scrn popup*/
   mmi_noti_scrn_func_ptr scrn_func_ptr;
   /*Scrn's param*/
   void *arg;
   /*Text Preview's param*/
   mmi_frm_notification_para_struct *notification;
   /*Fill in if the notification type is balloon*/
   mmi_nmgr_balloon_type_enum balloon_type;
   /*Alert information*/
   mmi_frm_nmgr_alert_struct *alert_info;
} notification_info_struct;
  

static void fill_notification_info(notification_info_struct *noti_info,
                           mmi_scenario_id scenario_id, 
                           mmi_event_notify_enum notify_type,
                           WCHAR *display_string,
                           mmi_noti_scrn_func_ptr scrn_func_ptr,
                           void *arg,
                           mmi_frm_notification_para_struct *notification,
                           mmi_nmgr_balloon_type_enum balloon_type,
                           mmi_frm_nmgr_alert_struct *alert_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    noti_info->noti_scen_id = scenario_id;
    noti_info->notify_type = notify_type;
    noti_info->string = display_string;
    noti_info->scrn_func_ptr = scrn_func_ptr;
    noti_info->arg = arg;
    noti_info->notification = notification;
    noti_info->balloon_type = balloon_type;
    noti_info->alert_info = alert_info;
}


static MMI_BOOL
    control_notification(
        U8 screen_type,
        notification_info_struct *noti_info
        );

KAL_ADM_ID g_mem_adm_id = 0;
static mmi_ret nmgr_alert_proc(mmi_event_struct *evt);
static void add_notify_defer_notification(
                    mmi_scenario_id scen_id, 
                    mmi_scen_attr_prio_enum scrn_priority, 
                    mmi_noti_scrn_func_ptr scrn_func_ptr, 
                    void *arg,
                    mmi_frm_nmgr_alert_struct *alert_info,
                    mmi_event_notify_enum event_type);


static void del_notify_defer_notification(  MMI_ID app_id,  
                    U16 popup_type,
                    mmi_event_notify_enum event_type, 
                    mmi_scenario_id scen_id, 
                    mmi_noti_scrn_func_ptr scrn_entry_func, 
                    void *arg,
                    MMI_BOOL is_free_user_data);
static mmi_ret invoke_notify_defer_notification(void);
static MMI_BOOL should_defer_notified_event(mmi_scen_attr_prio_enum notify_scrn_prio);
static MMI_BOOL nmgr_is_playing_vibrator(void);

#ifdef __MMI_SUBLCD__
static void emit_sublcd_noftify(mmi_scenario_id  scenario_id);
static MMI_BOOL control_sublcd(mmi_scenario_id noti_scen_id, mmi_noti_attr_beha_enum behavior);
static void mmi_sublcd_outgoing_call_entry(void);
static void mmi_sublcd_outgoing_call_exit(void);
static void mmi_sublcd_incoming_call_entry(void);
static void mmi_nmgr_sublcd_exit_incoming_call(void);
static mmi_ret mmi_sublcd_ucm_ind(mmi_event_struct *evt);
static void mmi_sublcd_ucm_incoming_call_hdlr(srv_ucm_incoming_call_ind_struct* p);
static void mmi_sublcd_ucm_release_hdlr(srv_ucm_release_ind_struct *p);
static mmi_ret mmi_nmgr_sub_lcd_scenario_hdlr(mmi_event_struct *p);
static void mmi_sulcd_alarm_exit(void);
static mmi_ret mmi_sublcd_scenario_end_hdlr(mmi_event_struct *p);
static mmi_ret mmi_sublcd_clam_open_hdlr(mmi_event_struct *evt);
#endif
#ifdef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_TOUCH_SCREEN__
extern void wgui_status_icon_bar_register_tap_proc(FuncPtr handler);
#endif
static S32 get_status_icon(U16 type);
static S32 get_image_id(U16 type);
static S32 get_image_icon_for_preivew(U16 type);

static void init_text_buffer(void);
static WCHAR* get_text_buffer(void);
static void free_text_buffer(WCHAR *p);
static void init_data_buffer(void);
static CHAR* get_data_buffer(void);
static void free_data_buffer(CHAR *p);

static void init_preiview_queue(void);
static void update_queue_index(U8 *index, U8 len);
static void write_preview_queue(mmi_nmgr_preview_info_struct *info);
static MMI_BOOL read_preview_queue(mmi_nmgr_preview_info_struct *info);
static void merge_preview_queue(U16 type, MMI_ID app_id);
static U8 get_preview_count(void);
static void preview_done_cb(status_icon_bar_info_enum info, void *arg);
//static MMI_BOOL look_up_preview_queue(mmi_nmgr_preview_info_struct *info);
static mmi_ret nmgr_preview_proc(mmi_event_struct *evt);
#endif

static void do_preview_cancel(mmi_event_notify_enum type, MMI_ID app_id, S32 icon_id);

static void remove_status_icon(S32 status_icon);
static void control_status_icon(MMI_ID app_id,U32 option, S32 icon_id);
static void nmgr_alert_popup_cancel(MMI_ID app_id, mmi_event_notify_enum event_type);
void mmi_frm_nmgr_alert_init(void);

#ifdef __COSMOS_MMI_PACKAGE__
static mmi_ret nmgr_balloon_proc(mmi_event_struct *evt);
#endif
#if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
static MMI_BOOL remove_from_nmgr_queue(MMI_ID alert_id);
static void remove_nmgr_confirm(mmi_scenario_id scen_id);
static MMI_BOOL is_notify_by_confirm_popup(mmi_scenario_id noti_scen_id);
static MMI_BOOL display_nmgr_confirm(mmi_scenario_id scen_id, mmi_event_notify_enum event_type);
static mmi_defer_item_struct *get_defer_item_id_and_cb(mmi_scenario_id scen_id, mmi_noti_scrn_func_ptr scrn_entry_func);

#endif

extern void mmi_email_cmcc_new_email_hdlr(void);
//static MMI_BOOL is_notify_by_confirm_popup(mmi_scenario_id noti_scen_id);
/***************************************************************************** 
 * External Interface
 *****************************************************************************/
void mmi_frm_nmgr_disable_notification()
{
	g_enable_nmgr = MMI_FALSE;
}

void mmi_frm_nmgr_enable_notification()
{
	g_enable_nmgr = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_compose_alert_handle
 * DESCRIPTION
 *  This function is used to compose nmgr handle for cancel alert
 *  
 * PARAMETERS
 *  app_id : application identity 
 *  event_type : event id, if you did not use event id to show notification (Ex. show icon only) then you need to use "MMI_EVENT_DEFAULT(0)" as your input 
 *  icon_id : status bar icon id, if you did not use icon id to show status bar icon (Ex. show text perview only), then you need to use "STATUS_ICON_INVALID_ID(-1)" as your input
 * RETURNS
 *  NMGR_HANDLE
 *****************************************************************************/
NMGR_HANDLE mmi_frm_nmgr_compose_alert_handle(MMI_ID app_id, mmi_event_notify_enum event_type, S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/            
    NMGR_HANDLE handle = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        icon_id = MAX_STATUS_ICONS;
    }
    /*----------------------------------------------------------------*/
    /* Handle  64 -32           32 -16    16 - 0 */
    /*              app id      event type    icon id */
    /*----------------------------------------------------------------*/  
    handle =  (((NMGR_HANDLE)app_id<<32) | ((NMGR_HANDLE)event_type<<16) | icon_id);
    
    return handle;
}

/*****************************************************************************
 * FUNCTION
 *  decompose_nmgr_handle
 * DESCRIPTION
 *  This function is used to decompose NMGR handle
 *  
 * PARAMETERS
 * NMGR HANDLE
 * RETURNS
 * app_id, event_type, icon_id
 *****************************************************************************/
static void decompose_nmgr_handle(NMGR_HANDLE handle, MMI_ID *app_id, mmi_event_notify_enum *event_type, S32 *icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *app_id = (MMI_ID)(handle>>32);
    *event_type = (mmi_event_notify_enum)((handle&0xffff0000)>>16);
    *icon_id = (S32)((handle&0x0000ffff));    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal
 * DESCRIPTION
 *  This function is used alloc temp nmgr buffer and copy src string to temp buffer 
 *  
 * PARAMETERS
 * dst str
 * src str
 * max copy len
 * RETURNS 
 *****************************************************************************/
WCHAR *mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(WCHAR *src_str, S32 max_len)
{
    if(src_str == NULL)
    {
        return NULL;
    }
    else
    {
        WCHAR *text = NULL;
        if ( mmi_ucs2strlen((const CHAR*)src_str) > max_len-1)
        {
            text = (WCHAR *)mmi_frm_nmgr_mem_malloc(sizeof(WCHAR)*(max_len));
            MMI_ASSERT(text);
            mmi_ucs2ncpy((CHAR *)text, (const CHAR *)src_str, (max_len-1));
            *(text+max_len-4) = L'.';
            *(text+max_len-3) = L'.';
            *(text+max_len-2) = L'.';
            *(text+max_len-1) = 0;
        }
        else
        {
            text = (WCHAR *)mmi_frm_nmgr_mem_malloc(sizeof(WCHAR)*(mmi_ucs2strlen((const CHAR*)src_str)+1));
            MMI_ASSERT(text);
            mmi_ucs2cpy((CHAR *)text, (const CHAR *)src_str);
        }
        return text;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_alloc_and_copy_data_to_nmgr_buff_internal
 * DESCRIPTION
 *  This function is used alloc temp nmgr buffer and copy user callback data to temp buffer 
 *  
 * PARAMETERS
 * dst str
 * src str
 * max copy len
 * RETURNS 
 *****************************************************************************/
 void*mmi_frm_alloc_and_copy_data_to_nmgr_buff_internal(void *src_buff, S32 size)
{
    if(src_buff == NULL)
    {
        return NULL;
    }
    else
    {
        void *temp = NULL;
        temp = mmi_frm_nmgr_mem_malloc(size);
        MMI_ASSERT(temp);
        memcpy(temp, src_buff, size);
        return temp;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_mem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_frm_nmgr_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((NULL == g_mem_adm_id));
    g_mem_adm_id = kal_adm_create(g_nmgr_mem_pool, NMGR_MEM_POOL_SIZE, NULL, MMI_TRUE);
    MMI_ASSERT((NULL != g_mem_adm_id));
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_mem_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void *mmi_frm_nmgr_mem_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(g_mem_adm_id, size);
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_frm_nmgr_mem_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(g_mem_adm_id, ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_alert
 * DESCRIPTION
 *  This function helps to 
 *    1. Check alert type (none or popup or status bar) from app's notification setting (NSS) 
 *    2. Set the app launch callback for user to launch app from the notification (popup or staus bar)
 *
 * PARAMETERS
 *  alert_info  : [IN] alert parameter
 * RETURNS
 *  void
 *****************************************************************************/
NMGR_HANDLE mmi_frm_nmgr_alert(    
    mmi_frm_nmgr_alert_struct *alert_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 notification_setting_value = 0;
    mmi_nmgr_alert_evt_struct evt;    
    mmi_ret ret = MMI_RET_ERR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_FW_TRC_G1_FRM, 
        TRC_MMI_FRM_NMGR_ALERT,
        alert_info->app_id,
        alert_info->scen_id,
        alert_info->event_type, 
        alert_info->ui_mask,
        alert_info->behavior_mask,
        alert_info->alert_option);
    /*Init alert mem buffer and regsiter NSS callback*/
    mmi_frm_nmgr_alert_init();
    
    if(!alert_info)
    {
        return NULL;
    }
       
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_DO_ALERT);

    /*Fill in basic alert notification information*/
    memcpy(&evt.noti, alert_info, sizeof(mmi_frm_nmgr_alert_struct));

    /*Check if input content is valid by the UI mask*/    
    /*status bar icon para*/
    if(alert_info->ui_mask & MMI_FRM_NMGR_UI_STATUS_ICON_MASK)
    {
        MMI_ASSERT(alert_info->status_bar_icon_para.icon_id >=0 );
        MMI_ASSERT(alert_info->status_bar_icon_para.icon_id < MAX_STATUS_ICONS );        
    }

    if((alert_info->status_bar_icon_para.icon_id <=0) ||
    (alert_info->status_bar_icon_para.icon_id > MAX_STATUS_ICONS ))
    {
        evt.noti.status_bar_icon_para.icon_id = STATUS_ICON_INVALID_ID;
    }
    
    /*status bar para*/
    if(alert_info->ui_mask & MMI_FRM_NMGR_UI_STATUS_BAR_MASK)
    {
        MMI_ASSERT(alert_info->status_bar_para.display_string !=NULL );        
    }
    /*popup para*/
    if(alert_info->ui_mask & MMI_FRM_NMGR_UI_POPUP_MASK)
    {
        MMI_ASSERT(alert_info->popup_para.popup_string!=NULL);
        if(alert_info->popup_para.popup_type == MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE)
        {
            MMI_ASSERT(alert_info->popup_para.popup_button_string!=NULL);    
        }
    }

    /*Check if input content is valid by the behavior mask*/   
    /*The behavior must be only one kind of notification*/
    if(alert_info->behavior_mask & MMI_FRM_NMGR_UI_POPUP_MASK &&
       alert_info->behavior_mask & MMI_FRM_NMGR_UI_STATUS_BAR_MASK )
    {
        MMI_ASSERT(0);
    }
    /*If prefix of behavior mask is PREFER_*/
    if(alert_info->behavior_mask & MMI_FRM_NMGR_BEHAVIOR_NSS_MASK)
    {
        MMI_ASSERT(alert_info->ui_mask & MMI_FRM_NMGR_UI_POPUP_MASK); 
        MMI_ASSERT(alert_info->ui_mask & MMI_FRM_NMGR_UI_STATUS_BAR_MASK); 
    }
    /*If postfix of behavior mask is POPUP*/    
    if(alert_info->behavior_mask & MMI_FRM_NMGR_UI_POPUP_MASK)
    {
        MMI_ASSERT(alert_info->ui_mask & MMI_FRM_NMGR_UI_POPUP_MASK); 
    }
    /*If postfix of behavior mask is STATUS_BAR*/
    if(alert_info->behavior_mask & MMI_FRM_NMGR_UI_STATUS_BAR_MASK)
    {
        MMI_ASSERT(alert_info->ui_mask & MMI_FRM_NMGR_UI_STATUS_BAR_MASK);  
    }
    /*If postfix of behavior mask is ICON_ONLY*/
    if(alert_info->behavior_mask == FORCE_ICON_ONLY )
    {
        MMI_ASSERT(alert_info->ui_mask & MMI_FRM_NMGR_UI_STATUS_ICON_MASK);  
    }
    /*The user data size can not exceed MMI_FRM_NMGR_USER_DATA_LEN */
    MMI_ASSERT(alert_info->app_proc_para.data_size <= MMI_FRM_NMGR_USER_DATA_LEN);
    /*If the data size is not zero, the user data can not be NULL POINTER*/
    if((alert_info->app_proc_para.data_size > 0 && alert_info->app_proc_para.user_data ==NULL) 
        ||(alert_info->app_proc_para.data_size == 0 && alert_info->app_proc_para.user_data !=NULL) )    
    {
        MMI_ASSERT(0);        
    }
       
    /*Extract the alert type from NSS*/
#ifdef __MMI_NSS_SUPPORT__
    if(alert_info->behavior_mask & MMI_FRM_NMGR_BEHAVIOR_NSS_MASK)
    {
        ret = mmi_srv_nss_get_setting(alert_info->app_id, NSS_SETTING_ALERT, &notification_setting_value);
    }
#endif/*__MMI_NSS_SUPPORT__*/
    
    /*
    * If 
    * 0. Not check NSS
    * 1. NSS not exist 
    * 2. The app setting is not configurable
    * 3. The app did not exist in NSS
    * NMGR will follow the behavior mask
    */
    if(ret == MMI_RET_ERR)
    {
        /*prefer or force popup */
        if(alert_info->behavior_mask & MMI_FRM_NMGR_UI_POPUP_MASK)
        {
            notification_setting_value = ALERT_TYPE_POPUP;
        }
        /*prefer or force text preview*/
        else if(alert_info->behavior_mask & MMI_FRM_NMGR_UI_STATUS_BAR_MASK)
        {
            notification_setting_value = ALERT_TYPE_STATUS_BAR;    
        }
        else
        {            
            notification_setting_value = ALERT_TYPE_NONE; 
        }
    }

    evt.noti.behavior_mask = notification_setting_value;     

#ifndef __MMI_NCENTER_SUPPORT__
    /*If there is no ncenter and user want to show by status bar
     */
    if(evt.noti.behavior_mask == ALERT_TYPE_STATUS_BAR 
        && alert_info->status_bar_para.status_bar_type == MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE)
    {
        evt.noti.behavior_mask = ALERT_TYPE_POPUP;
    }
#endif/*__MMI_NCENTER_SUPPORT__*/
    /*Due to the status bar or balloon will be showed in a clean screen*/
    /*So NMGR will post the display to the end of show screen, and that's */
    /*the reason why we need to store the data here*/
    if(evt.noti.behavior_mask == ALERT_TYPE_STATUS_BAR)
    {
        /*Copy Preview text to temp buffer, because we will post event to do the print*/        
        if (alert_info->status_bar_para.status_bar_type== MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE)
        {
        #ifdef __MMI_NCENTER_SUPPORT__
            /*Copy display string to temp buffer*/
            if(evt.noti.alert_option & MMI_FRM_NMGR_DISABLE_PREVIEW)
            {
                evt.noti.status_bar_para.display_string = NULL;
            }
            else
            {
                evt.noti.status_bar_para.display_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal( 
                (WCHAR *)alert_info->status_bar_para.display_string,
                MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT);
            }
            /*Copy image file path to temp buffer if needed*/
            if(evt.noti.status_bar_para.image_type == MMI_NMGR_IMG_FILE_PATH)
            {
                MMI_ASSERT(alert_info->status_bar_para.image.file_path);
                
                evt.noti.status_bar_para.image.file_path = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(
                alert_info->status_bar_para.image.file_path,
                MMI_MAX_FILE_NAME_LEN
                );
            }
            /*Copy user data to temp buffer if needed*/
            if(alert_info->app_proc_para.data_size > 0)
            {                
                evt.noti.app_proc_para.user_data = mmi_frm_alloc_and_copy_data_to_nmgr_buff_internal( 
                alert_info->app_proc_para.user_data,
                alert_info->app_proc_para.data_size
                );
            }
            /*Copy sound file path if needed*/
            if(alert_info->snd_para.sound_type == MMI_NMGR_SND_FILE_PATH)
            {
                evt.noti.snd_para.sound.file_path = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(
                    alert_info->snd_para.sound.file_path,MMI_MAX_FILE_NAME_LEN);
            }
			MMI_FRM_POST_EVENT(&evt, nmgr_alert_proc, NULL);
        #else
            return NULL;
        #endif/*__MMI_NCENTER_SUPPORT__*/
        }
        else if(alert_info->status_bar_para.status_bar_type == MMI_FRM_NMGR_ALERT_ST_BALLOON_TYPE)
        {/*Balloon*/
            /*Due to balloon cannot be launched and it doesn't have specific image*/
            /*so we don't need to store user data and image info*/
        #ifdef __COSMOS_MMI_PACKAGE__ 
            /*Copy display string to temp buffer*/
            evt.noti.status_bar_para.display_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal( 
            (WCHAR *)alert_info->status_bar_para.display_string,
            MMI_FRM_NMGR_BALLOON_TEXT_CHAR_COUNT);    
            if (MMI_EVENT_INFO_BALLOON != alert_info->event_type && srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE)
            {
                srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            }                      
			MMI_FRM_POST_EVENT(&evt, nmgr_alert_proc, NULL);
        #else
            return NULL;
        #endif/*__COSMOS_MMI_PACKAGE__*/
        }
        else
        {// currently we don't have such situation
            return NULL;
        }              
	       // MMI_FRM_POST_EVENT(&evt, nmgr_alert_proc, NULL);	   
    }    
    else if(evt.noti.behavior_mask == ALERT_TYPE_POPUP)
    {                      
        MMI_FRM_SEND_EVENT(&evt, nmgr_alert_proc, NULL);
    }
    else
    {
        MMI_FRM_SEND_EVENT(&evt, nmgr_alert_proc, NULL);
        if(alert_info->app_proc_para.scrn_group_proc!=NULL)
        {
            mmi_event_struct evt_end;            
            MMI_FRM_INIT_EVENT(&evt_end, EVT_ID_NMGR_ALERT_END);
            MMI_FRM_SEND_EVENT(&evt_end, alert_info->app_proc_para.scrn_group_proc, alert_info->app_proc_para.user_data);   
        }
    }
    return mmi_frm_nmgr_compose_alert_handle(alert_info->app_id, alert_info->event_type, alert_info->status_bar_icon_para.icon_id);
}

static void post_nmgr_alert_cancel(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID app_id = 0;
    mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
    S32 icon_id = STATUS_ICON_INVALID_ID;
    mmi_frm_alert_cancel_evt_struct *cancel_evt = (mmi_frm_alert_cancel_evt_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    /*cancel preview queue and status bar icon*/
    decompose_nmgr_handle(cancel_evt->open_handle, &app_id, &event_type, &icon_id);
    if(icon_id == 0)
    {
        icon_id = STATUS_ICON_INVALID_ID;
    }
    
    MMI_TRACE(
        MMI_FW_TRC_G1_FRM, 
        TRC_MMI_FRM_NMGR_ALERT_CANCEL,
        app_id,
        event_type,
        icon_id
        );
 
    /*cancel preview queue*/    
    do_preview_cancel(event_type, app_id, icon_id);
  
    /*cancel popup queue*/
    del_notify_defer_notification(app_id, MMI_FRM_NMGR_ALERT_POPUP_ALL_TYPE, event_type, MMI_SCENARIO_ID_GENERAL, NULL, NULL, MMI_TRUE);
    nmgr_alert_popup_cancel(app_id, event_type);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_alert_cancel
 * DESCRIPTION
 *  This function is used by posting event  to cancel defer alert and remove related status bar icon
 *  which belong to the specific appid and type
 *  
 * PARAMETERS
 *  app_id      : [IN] application identity 
 *  type          : [IN] notify event type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_alert_cancel(
        NMGR_HANDLE open_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_alert_cancel_evt_struct evt;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_CANCEL_ALERT);
    evt.open_handle = open_handle;    
	//kal_prompt_trace(MOD_MMI_FW,"[NMGR] mmi_frm_nmgr_alert_cancel:post_event");

	/* post event to cancel  */
    MMI_FRM_POST_EVENT(&evt, post_nmgr_alert_cancel, NULL);
	
}

void mmi_frm_nmgr_alert_cancel_send(
        NMGR_HANDLE open_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_alert_cancel_evt_struct evt;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_CANCEL_ALERT);
    evt.open_handle = open_handle;    
	//kal_prompt_trace(MOD_MMI_FW,"[NMGR] mmi_frm_nmgr_alert_cancel:send_event");

	/* send event to cancel  */
    MMI_FRM_SEND_EVENT(&evt, post_nmgr_alert_cancel, NULL);
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_notify
 * DESCRIPTION
 *  This function is used to send a notification by application
 *  in FTO project, nmgr will help to do text preview and add status icon
 *
 * PARAMETERS
 *  scen_id       : [IN] scenario id to determine priority
 *  type          : [IN] notify event type
 *  notification  : [IN] notification parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_notify(
    mmi_scenario_id                  scen_id, 
    mmi_event_notify_enum               type,
    mmi_frm_notification_para_struct *notification)
{               
#ifdef __MMI_NCENTER_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 preview_count = 0;
    mmi_nmgr_preview_evt_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_frm_nmgr_alert_init(); 
    preview_count = get_preview_count();
    MMI_TRACE(
        MMI_FW_TRC_G1_FRM, 
        TRC_MMI_FRM_NMGR_NOTIFY,
        scen_id,
        type, 
        (notification != NULL) ? notification->option : 0,
        preview_count);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_DO_PREVIEW);
    evt.scenario_id = scen_id;
    evt.type = type;
    evt.noti.option = (notification!= NULL) ? notification->option : 0xF000;
    
    if (notification == NULL || notification->text == NULL || notification->option & MMI_FRM_NMGR_DISABLE_PREVIEW)
    {
        evt.noti.text = NULL;
    }
    else
    {
        evt.noti.text = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal((WCHAR *)notification->text,MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT);          
    }
    MMI_FRM_POST_EVENT(&evt, nmgr_preview_proc, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_cancel
 * DESCRIPTION
 *  This function is used to cancel notifications which belong to type by application
 *  in FTO project, nmgr will help to remove status icon
 *
 * PARAMETERS
 *
 *  type          : [IN] notify event type
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_cancel(mmi_event_notify_enum type)
{
#ifdef __MMI_NCENTER_SUPPORT__      
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_cancel_preview_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_CANCEL, type);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_CANCEL_PREVIEW);
    evt.type = type;
    MMI_FRM_POST_EVENT(&evt, nmgr_preview_proc, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_balloon
 * DESCRIPTION
 *  Notify a event which will invoke a balloon in FTO project
 *
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event;
 *  type :          [IN] event type which could get config-info of the notifcation event, e.g. tone id, img id, etc;
 *  balloon_type:   [IN] Balloon type, eg. info failure
 *  string :        [IN] display string pointer;
 * RETURNS
 *  Return MMI_TRUE if the ballon is shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
void mmi_frm_nmgr_balloon(
    mmi_scenario_id scenario_id,
    mmi_event_notify_enum type,
    mmi_nmgr_balloon_type_enum balloon_type,
    const WCHAR *string)
{
#ifdef __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_balloon_evt_struct evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_BALLOON, type, balloon_type);
    MMI_FRM_INIT_EVENT(&evt, 0);
    evt.balloon_type = balloon_type;
    evt.scenario_id  = scenario_id;
    evt.type         = type;
    if (mmi_ucs2strlen((const CHAR*)string) > MMI_FRM_NMGR_BALLOON_TEXT_CHAR_COUNT - 1)
    {
        mmi_ucs2ncpy((CHAR *)evt.string, (const CHAR *)string, MMI_FRM_NMGR_BALLOON_TEXT_CHAR_COUNT);
    }
    else
    {
        mmi_ucs2cpy((CHAR *)evt.string, (const CHAR *)string);
    }
    if (MMI_EVENT_INFO_BALLOON != type && srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE)
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }
    MMI_FRM_POST_EVENT(&evt, nmgr_balloon_proc, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_popup
 * DESCRIPTION
 *  Notify a event which will invoke a popup screen, if the screen can't be displayed
 *  during current scenario, then it will be dropped and won't be displayed anymore.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event;
 *  type :          [IN] event type which could get config-info of the notifcation event, e.g. tone id, img id, etc;
 *  string :        [IN] display string pointer;
 * RETURNS
 *  Return MMI_TRUE if screen could be shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_nmgr_popup(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    notification_info_struct noti_info;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_POPUP, scenario_id, type);

    fill_notification_info(&noti_info,
                scenario_id,
                type, 
                string,
                NULL,
                NULL,
                NULL,
                MMI_NMGR_BALLOON_TYPE_TOTAL,
                NULL);
        
    return control_notification(
        MMI_NOTIFY_COMM_POPUP,
        &noti_info
        );
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_notify_by_idle
 * DESCRIPTION
 *  Notify a event which scenario priority is low, this type of notification event 
 *  is controlled by idle notification mechanism now which cover mech. of async-collect app info.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 *  type :          [IN] event type which could get config-info of the notifcation event, e.g. tone id, img id, etc;
 *  string :        [IN] display string pointer;
 * RETURNS
 *  Return MMI_TRUE if screen could be shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
#ifdef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
MMI_BOOL mmi_frm_nmgr_notify_by_idle(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string)
{
    return MMI_FALSE;
}
#else
MMI_BOOL mmi_frm_nmgr_notify_by_idle(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    notification_info_struct noti_info;		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_NOTIFY_BY_IDLE, scenario_id, type);

    fill_notification_info(&noti_info,
               scenario_id,
               type,
               string,
               NULL,
               NULL,
               NULL,
               MMI_NMGR_BALLOON_TYPE_TOTAL,
               NULL);
        
    return control_notification(
        MMI_NOTIFY_BY_IDLE,
        &noti_info
        );  
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_notify_by_app
 * DESCRIPTION
 *  Notify a event whose screen is controlled by app, this interface also support
 *  defer mechanism which means if app's screen can't be displayed during current scenario,
 *  its entry function ptr & arg ptr could be recorded, then nmgr will invoke this screen
 *  by comparing priority between active scenario and notification scenario when current scenario is ended.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 *  type :          [IN] event type which could get config-info of the notifcation event, e.g. tone id, img id, etc;
 *  screen_entry :  [IN] screen entry function pointer;
 *  arg :           [IN] argument pointer;
 * RETURNS
 *  Return MMI_TRUE if screen could be shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_nmgr_notify_by_app(mmi_scenario_id scenario_id, mmi_event_notify_enum type, mmi_noti_scrn_func_ptr screen_entry, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    notification_info_struct noti_info;			
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_NOTIFY_BY_APP, scenario_id, type);
    
    fill_notification_info(&noti_info,
               scenario_id,
               type,
               NULL,
               screen_entry,
               arg,
               NULL,
               MMI_NMGR_BALLOON_TYPE_TOTAL,
               NULL);
        
    return control_notification(
        MMI_NOTIFY_BY_APP,
        &noti_info
        );  
}


#ifdef __MMI_SUBLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_notify_sublcd
 * DESCRIPTION
 *  Notify a event to sublcd if user don't use
 *  mmi_frm_nmgr_popup
 *  mmi_frm_nmgr_notify_by_idle
 *  mmi_frm_nmgr_notify_by_app
 *  to nofity a event but he also hope NMGR help to display info on sublcd
 *
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 * RETURNS
 *  Return MMI_TRUE if sublcd screen could be shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_nmgr_notify_sublcd(mmi_scenario_id scenario_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    notification_info_struct noti_info;				
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_SUBLCD_NOTIFY, scenario_id);
        
    fill_notification_info(&noti_info,
               scenario_id,
               MMI_EVENT_DEFAULT,
               NULL,
               NULL,
               NULL,
               NULL,
               MMI_NMGR_BALLOON_TYPE_TOTAL,
               NULL);
        
    return control_notification(
        MMI_NOTIFY_SUBLCD,
        &noti_info
        );  
}
#endif /* __MMI_SUBLCD__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_cancel_deferred_scenario
 * DESCRIPTION
 *  Cancel deferred scenario with designated screen entry funcion and argument pointer.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 *  screen_entry :  [IN] screen entry function pointer;
 *  arg :           [IN] argument pointer;
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_cancel_deferred_scenario(mmi_scenario_id scen_id, mmi_noti_scrn_func_ptr scrn_entry_func, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_CANCEL_DEFER, scen_id, scrn_entry_func, arg);
    del_notify_defer_notification(0, MMI_FRM_NMGR_ALERT_POPUP_ALL_TYPE, MMI_EVENT_DEFAULT, scen_id, scrn_entry_func, arg, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_is_scenario_deferred
 * DESCRIPTION
 *  Check if scenario with designated screen entry funcion and argument pointer has been deferred.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 *  screen_entry :  [IN] screen entry function pointer;
 *  arg :           [IN] argument pointer;
 * RETURNS
 *  Return MMI_TRUE if has been deferred,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_nmgr_is_scenario_deferred(mmi_scenario_id scen_id, mmi_noti_scrn_func_ptr scrn_entry_func, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (idx = 0; idx < mmi_notify_defer_info_cntx.used; idx++)
    {
        if (mmi_notify_defer_info_cntx.data[idx].scen_id == scen_id &&
            mmi_notify_defer_info_cntx.data[idx].scrn_entry_cb == scrn_entry_func &&
            mmi_notify_defer_info_cntx.data[idx].arg == arg)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_CHECK_DEFER_SUCCESS, scen_id, scrn_entry_func, arg);
            return MMI_TRUE;
        }
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_CHECK_DEFER_FAIL, scen_id, scrn_entry_func, arg);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_block_sound_vib_stop
 * DESCRIPTION
 *  This function is used to block sound or vib stop by FW
 *  (mmi_frm_nmgr_control_end)
 * PARAMETERS
 *  noti_type  : [IN]  MMI_FRM_NMGR_SOUND or MMI_FRM_NMGR_VIB or
 *                     MMI_FRM_NMGR_VIB | MMI_FRM_NMGR_SOUND
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_block_sound_vib_stop(U8 noti_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nmgr_block_tone_vib |= noti_type;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_unblock_sound_vib_stop
 * DESCRIPTION
 *  This function is used to unblock sound or vib stop by FW
 *  (mmi_frm_nmgr_control_end)
 *
 * PARAMETERS
 *  noti_type  : [IN]  MMI_FRM_NMGR_SOUND or MMI_FRM_NMGR_VIB or
 *                     MMI_FRM_NMGR_VIB | MMI_FRM_NMGR_SOUND
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_unblock_sound_vid_stop(U8 noti_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nmgr_block_tone_vib &= ~noti_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_control_end
 * DESCRIPTION
 *  This is the ending action of nmgr containing stop sound, turn off vibrator.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_control_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_CONTROL_SND_END, noti_tone_id);
    if (!(g_nmgr_block_tone_vib & MMI_FRM_NMGR_SOUND))
    {
		StopTimer(MMI_NMGR_VIB_THEN_RING_TIMER);
        if (g_timer_arg != NULL)
        {
            mmi_mfree(g_timer_arg);
            g_timer_arg = NULL;
        }        
        if (noti_tone_id != NONE_TONE)
        {
            srv_prof_stop_tone(noti_tone_id);
            noti_tone_id = NONE_TONE;
			if (need_resume_bk_play == MMI_TRUE)
			{
				mdi_audio_resume_background_play();
				need_resume_bk_play = MMI_FALSE;
			}
	    #ifdef MOTION_SENSOR_SUPPORT
			if (g_nmgr_sensor_handle != 0)
			{

				srv_sensor_stop_listen(g_nmgr_sensor_handle);
				g_nmgr_sensor_handle = 0;
			}
		#endif
		}
        else if (dtmf_id != NONE_TONE)
        {
            srv_prof_stop_tone(dtmf_id);
            dtmf_id = NONE_TONE;
        }
    }

    if (!(g_nmgr_block_tone_vib & MMI_FRM_NMGR_VIB))
    {
        if (nmgr_is_playing_vibrator())
        {
            srv_vibrator_post_req(VIB_PATTERN_1, PLAY_STOP);
            vib_on = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_end_callback
 * DESCRIPTION
 *  This function is EVT_ID_PRE_KEY_EVT_ROUTING events call back function, when user
 *  press key (key donw event), nmgr will stop notification sound or vibrator.
 *
 * PARAMETERS
 *  evt     :[IN] key event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_frm_nmgr_control_end_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->key_type == KEY_EVENT_DOWN)
    {
        mmi_frm_nmgr_control_end();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_set_only_disp_scrn
 * DESCRIPTION
 *  This interface could control nmgr only display screen, won't play sound, vibrator
 *   and backlight.
 * PARAMETERS
 *  flag :   [IN] switch flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_set_only_disp_scrn(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    only_control_scrn = flag;
}


/* Defer callback related interface */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_get_defer_notification_count
 * DESCRIPTION
 *  Get the deferred events count.
 * PARAMETERS
 *  void
 * RETURNS
 *  Deferred events count
 *****************************************************************************/
U8 mmi_frm_nmgr_get_defer_notification_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_GET_DEFER_COUNT, mmi_notify_defer_info_cntx.used);
    return mmi_notify_defer_info_cntx.used;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_invoke_deder_event
 * DESCRIPTION
 *  Invoke defer event in nmgr defer queue, this interface is invoked by idle
 *  module (IdleEventCfg.c) when go back to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_invoke_deder_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    invoke_notify_defer_notification();
}

#ifdef __COSMOS_MMI_PACKAGE__
void mmi_frm_nmgr_status_bar_balloon_update(void)
{
    S32 x1;
    S32 y1;
    S32 x2;
    S32 y2;
    if (g_balloon_icon == STATUS_ICON_INVALID_ID)
    {
        return;
    }
    if (MMI_FALSE == wgui_status_icon_bar_is_display(WGUI_STATUS_ICON_BAR_H_BAR))
    {
        vadp_v2p_nmgr_close_balloon(MMI_NMGR_BALLOON_UNDER_STATUS_BAR);
        g_balloon_icon = STATUS_ICON_INVALID_ID;
        return;
    }

    if (MMI_TRUE == wgui_status_icon_bar_get_icon_area(g_balloon_icon, &x1, &y1, &x2, &y2))
    {
        S32 x = x1 + (x2 - x1)/2;
        S32 y = MMI_STATUS_BAR_HEIGHT;
        vadp_v2p_nmgr_upper_balloon_move(x, y);
    }
    else
    {
        vadp_v2p_nmgr_close_balloon(MMI_NMGR_BALLOON_UNDER_STATUS_BAR);
        g_balloon_icon = STATUS_ICON_INVALID_ID;
    }
}

mmi_ret close_balloon_proc(mmi_event_struct *evt)
{
	mmi_frm_nmgr_status_bar_balloon_update();
	return MMI_RET_OK;
}
mmi_ret mmi_nmgr_listen_scrn_enter(mmi_event_struct *evt)
{
	mmi_event_struct temp;
	MMI_FRM_INIT_EVENT(&temp, 0);
	MMI_FRM_POST_EVENT(&temp, close_balloon_proc, NULL);
	return MMI_RET_OK;
}
#endif

#if defined(__MMI_NSS_SUPPORT__) && defined(__MMI_NCENTER_SUPPORT__) 
/*This callback will help to sync tje status bar icon with Ncenter setting*/
static void status_bar_listen_setting_change(MMI_ID app_id, U32 change_setting, MMI_ID *alias_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U16 setting_value = 0;
    MMI_ID *temp_alias_id = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*check if change setting is ncenter*/   
    if(change_setting & NSS_MASK_NCENTER)
    {
        for(i = 0; i < MAXIMUM_STATUS_ICON_NUM; i++)
        {/*Check the app icon list*/
            if(g_nss_app_icon[i].app_id == GRP_ID_INVALID)
            {
                continue;
            }

            if(g_nss_app_icon[i].app_id == app_id)
            {
                /*show or hide the icon by the ncenter setting*/
                mmi_srv_nss_get_setting(app_id, NSS_SETTING_NCENTER, &setting_value);
                if(setting_value == SETTING_ON)
                {/*Show*/
                    control_status_icon(g_nss_app_icon[i].app_id,
                    g_nss_app_icon[i].alert_option,
                    g_nss_app_icon[i].icon_id);
                }
                else
                {/*Hide*/
                    remove_status_icon(g_nss_app_icon[i].icon_id);                    
                }                
            }
            if(alias_id!=NULL)
            {
                temp_alias_id = alias_id;
                while(*temp_alias_id!=0xffff)
                {
                    if(g_nss_app_icon[i].app_id == *temp_alias_id)
                    {
                        /*show or hide the icon by the ncenter setting*/
                        mmi_srv_nss_get_setting(*temp_alias_id, NSS_SETTING_NCENTER, &setting_value);
                        if(setting_value == SETTING_ON)
                        {/*Show*/
                            control_status_icon(g_nss_app_icon[i].app_id,
                            g_nss_app_icon[i].alert_option,
                            g_nss_app_icon[i].icon_id);
                        }
                        else
                        {/*Hide*/
                            remove_status_icon(g_nss_app_icon[i].icon_id);                    
                        }
                        break;
                    }
                    temp_alias_id++;
                }
            }
        }
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_invoke_defer_event_callback
 * DESCRIPTION
 *  Callback of invoking defer event, the driven event will be emitted when the
 *  current sceanrio is ended.
 * PARAMETERS
 *  para :   [IN] event parameter
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_frm_nmgr_invoke_defer_event_callback(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == para)
    {
        return MMI_RET_ERR;
    }

    if (mmi_frm_nmgr_get_defer_notification_count() > 0)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_INVOKE_DEFER_EVT_CB);

        StartTimer(MMI_NOTIFICATION_SERVICE_TIMER, 
            MMI_NOTIFY_INVOKE_TIME, 
            (FuncPtr)invoke_notify_defer_notification);
    }

    return MMI_RET_OK;
}

void mmi_frm_nmgr_alert_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_is_alert_init == MMI_FALSE)
    {
        mmi_frm_nmgr_mem_init();
#if defined(__MMI_NSS_SUPPORT__) && defined(__MMI_NCENTER_SUPPORT__)
        mmi_srv_nss_register_listener(NSS_MASK_NCENTER, status_bar_listen_setting_change);
#endif
        g_is_alert_init = MMI_TRUE;
    }
}


void mmi_frm_nmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_NCENTER_SUPPORT__
    init_text_buffer();
    init_data_buffer();
    init_preiview_queue();
#endif    
}


/***************************************************************************** 
 * Internal Interface
 *****************************************************************************/
__inline static void parse_attri_action(mmi_nmgr_behavior_enum attri_action, mmi_attribute_action_struct *action_struct)
{
    /* If user didn't set specific attribute action, we help set it to general action. */
    action_struct->scrn_action = (mmi_nmgr_behavior_enum)(((attri_action & MMI_BEHAVIOR_SCRN_MASK) == MMI_BEHAVIOR_SCRN_NONE) ? (MMI_BEHAVIOR_GENERAL & MMI_BEHAVIOR_SCRN_MASK) : (attri_action & MMI_BEHAVIOR_SCRN_MASK));
	action_struct->snd_action  = (mmi_nmgr_behavior_enum)(((attri_action & MMI_BEHAVIOR_SND_MASK) == MMI_BEHAVIOR_SND_NONE) ? (MMI_BEHAVIOR_GENERAL & MMI_BEHAVIOR_SND_MASK) : (attri_action & MMI_BEHAVIOR_SND_MASK));
    action_struct->vib_action  = (mmi_nmgr_behavior_enum)(((attri_action & MMI_BEHAVIOR_VIB_MASK) == MMI_BEHAVIOR_VIB_NONE) ? (MMI_BEHAVIOR_GENERAL & MMI_BEHAVIOR_VIB_MASK) : (attri_action & MMI_BEHAVIOR_VIB_MASK));
    action_struct->bl_action   = (mmi_nmgr_behavior_enum)(((attri_action & MMI_BEHAVIOR_BL_MASK) == MMI_BEHAVIOR_BL_NONE) ? (MMI_BEHAVIOR_GENERAL & MMI_BEHAVIOR_BL_MASK) : (attri_action & MMI_BEHAVIOR_BL_MASK));
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_NMGR_GET_PARSE_ARRTIBUTE_ACTION, action_struct->scrn_action, action_struct->snd_action, action_struct->vib_action, action_struct->bl_action);
}


static MMI_BOOL nmgr_is_playing_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (noti_tone_id != NONE_TONE) ? MMI_TRUE : MMI_FALSE;
}


static MMI_BOOL nmgr_is_playing_vibrator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vib_on;
}


static MMI_BOOL nmgr_is_in_defer_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_IN_DEFER_PROC, is_in_defer_process);
    return is_in_defer_process;
}


static MMI_BOOL nmgr_is_defer_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (!disable_invoke_defer_event) ? MMI_TRUE : MMI_FALSE;
}

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
static void get_event_type_by_scen_id(mmi_scenario_id scen_id, U32 *type, U32 *flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *type = MMI_NMGR_APP_NULL;
    *flag = MMI_NMGR_OPTION_USE_DEFAULT;
    for (idx = 0; idx < SCEN_MAP_TABLE_SIZE; idx++)
    {
        if (scen_id == scen_map_table[idx].scen_id)
        {
            *type = scen_map_table[idx].event_type;
            *flag = scen_map_table[idx].flag;
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_NMGR_GET_EVT_TYPE_FOR_IDLE, scen_id, *type, *flag);

            return;
        }
    }
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
static MMI_RET nmgr_confirm_proc(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_ALERT_QUIT)
	{
		mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;
		nmgr_confirm_cntx_struct *cntx     = (nmgr_confirm_cntx_struct *)alert->user_tag;
		if (alert->result == MMI_ALERT_CNFM_1 || alert->result == MMI_ALERT_CNFM_2)
		{
			if (cntx->scen_id == MMI_SCENARIO_ID_NEW_EMAIL)
			{
			#ifdef __MMI_EMAIL__
				mmi_email_cmcc_new_email_hdlr();
			#endif
			}
			else
			{
				mmi_um_entry_inbox_with_check();
			}

		}
		else if (alert->result == MMI_ALERT_CNFM_3 || alert->result == MMI_ALERT_CNFM_CANCEL)
		{

		}
		else
		{
			mmi_frm_free(cntx->title);
			mmi_frm_free(cntx);
		}
		remove_from_nmgr_queue(alert->alert_id);
	}
	return MMI_RET_OK;
}


static U32 get_unread_mms_count()
{
	U32 count = 0;
#if defined(__MMI_MMS_2__) && defined(__MMI_MMS_IN_UM__)
	srv_mms_get_msg_count_struct msg_count_req;
	S32 result;

	msg_count_req.count = 1;
	msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;
	result = srv_mms_get_msg_count(&msg_count_req);    
	if (result == SRV_MMS_RESULT_OK)
	{
		count = msg_count_req.rsp_tb[0];
	}
#endif
	return count;
}


static U32 get_unread_message_count()
{
	U32 sms_count      = 0;
	U32 mms_count      = 0;
	U32 wap_push_count = 0;
	U32 prov_count    = 0;

	sms_count = srv_sms_get_unread_sms_num();
	mms_count = get_unread_mms_count();

#if defined(__MMI_PUSH_IN_UM__) && defined(__WAP_PUSH_SUPPORT__)
	wap_push_count = srv_get_push_unread_count();
#endif
#if defined(__MMI_PROV_IN_UM__)
	prov_count = srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);
#endif
	MMI_TRACE(PLUTO_FW_TRC_NMGR, TRC_MMI_FRM_NMGR_MESSAGE_CNT, sms_count, mms_count, wap_push_count, prov_count);
	return (sms_count + mms_count + wap_push_count + prov_count);
}


static WCHAR* construct_string(mmi_scenario_id id, mmi_event_notify_enum event_type)
{
	WCHAR *str1;
	WCHAR *str2;
#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)
	U16 sim_str_id = 0;
#endif
#ifdef __MMI_EMAIL__
	if (id == MMI_SCENARIO_ID_NEW_EMAIL)
	{
		str1 = (WCHAR *)GetString(STR_EMAIL_EMN_NEW_EMAIL_ID);
	}
	else
#endif
	{
		WCHAR temp[MMI_NMGR_CONFIRM_POPUP_TEMP_STRING_BUF_LEN];
		WCHAR temp2[MMI_NMGR_CONFIRM_POPUP_TEMP_STRING_BUF_LEN];
		U32 count = get_unread_message_count();

		if (count == 0)
		{
			return NULL;
		}
#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)
		switch (event_type)
		{
		case MMI_EVENT_SIM1_MMS:
		case MMI_EVENT_SIM1_SMS:
			sim_str_id = STR_GLOBAL_SIM_1;
			break;

		case MMI_EVENT_SIM2_MMS:
		case MMI_EVENT_SIM2_SMS:
			sim_str_id = STR_GLOBAL_SIM_2;
			break;

#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3)
		case MMI_EVENT_SIM3_MMS:
		case MMI_EVENT_SIM3_SMS:
			sim_str_id = STR_GLOBAL_SIM_3;
			break;

#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4)
		case MMI_EVENT_SIM4_MMS:
		case MMI_EVENT_SIM4_SMS:
			sim_str_id = STR_GLOBAL_SIM_4;
			break;
#endif
#endif
		}
		mmi_wcscpy(temp, (WCHAR *)GetString(sim_str_id));
		mmi_wcscat(temp, L" ");
		mmi_wcscat(temp, (WCHAR *)GetString(STR_RECEIVED_SMS));
#else
		mmi_wcscpy(temp, (WCHAR *)GetString(STR_RECEIVED_SMS));
#endif
		mmi_wcscat(temp, L"\n");
		mmi_wcscat(temp, (WCHAR *)GetString(STR_UM_UNREAD_MSG_NUMBER_ID));
		mmi_wsprintf_ex(temp2, MMI_NMGR_CONFIRM_POPUP_TEMP_STRING_BUF_LEN, temp, count);
		MMI_ASSERT(mmi_wcslen(temp2) < MMI_NMGR_CONFIRM_POPUP_TEMP_STRING_BUF_LEN - ENCODING_LENGTH);
		str1 = temp2;
	}
	str2 = (WCHAR *)mmi_frm_malloc(ENCODING_LENGTH * mmi_wcslen(str1) + ENCODING_LENGTH);
	mmi_wcscpy(str2, str1);
	return str2;
}

static MMI_BOOL do_confirm_popup_notify(mmi_scenario_id scen_id, mmi_event_notify_enum event_type)
{
	MMI_TRACE(PLUTO_FW_TRC_NMGR, TRC_MMI_FRM_NMGR_DO_CONFIRM_NOTIFY, scen_id, event_type);
	remove_nmgr_confirm(scen_id);
	return display_nmgr_confirm(scen_id, event_type);
}

static MMI_BOOL nmgr_confirm_defer_cb(mmi_scenario_id scen_id, void *arg)
{
	mmi_event_notify_enum notify_type = (mmi_event_notify_enum)arg;
	do_confirm_popup_notify(scen_id, notify_type);
	return MMI_TRUE;
}

static MMI_BOOL is_nmgr_confirm_queue_full()
{
	U32 i;
	for (i = 0; i < MAX_NMGR_CONFIRM_SCREEN_NUM; i++)
	{
		if (nmgr_confirm_queue[i].confirm_id == 0)
		{
			return MMI_FALSE;
		}
	}
	return MMI_TRUE;
}

static MMI_BOOL add_to_nmgr_confirm_queue(MMI_ID alert_id, nmgr_confirm_cntx_struct *cntx)
{
	U32 i;
	for (i = 0; i < MAX_NMGR_CONFIRM_SCREEN_NUM; i++)
	{
		if (nmgr_confirm_queue[i].confirm_id == 0)
		{
			nmgr_confirm_queue[i].confirm_id = alert_id;
			nmgr_confirm_queue[i].cntx = cntx;
			return MMI_TRUE;
		}
	}
	return MMI_FALSE;
}

static MMI_BOOL remove_from_nmgr_queue(MMI_ID alert_id)
{
	U32 i;
	for (i = 0; i < MAX_NMGR_CONFIRM_SCREEN_NUM; i++)
	{
		if (nmgr_confirm_queue[i].confirm_id == alert_id)
		{
			nmgr_confirm_queue[i].confirm_id = 0;
			nmgr_confirm_queue[i].cntx = NULL;
			return MMI_TRUE;
		}
	}
	return MMI_FALSE;
}

static MMI_BOOL is_message(mmi_scenario_id noti_scen_id)
{
	if (noti_scen_id == MMI_SCENARIO_ID_NEW_SMS ||
		noti_scen_id == MMI_SCENARIO_ID_NEW_MMS ||
		noti_scen_id == MMI_SCENARIO_ID_WAP_PUSH ||
		noti_scen_id == MMI_SCENARIO_ID_SIM_SMS ||
		noti_scen_id == MMI_SCENARIO_ID_PROVISIOING)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}

static U16 get_confirm_type(mmi_scenario_id scen_id)
{
	U16 confirm_type;
	if (is_message(scen_id) == MMI_TRUE)
	{
		confirm_type = (U16)MMI_SCENARIO_ID_NEW_SMS;
	}
	else
	{
		confirm_type = (U16)scen_id;
	}
	return confirm_type;
}

static nmgr_confirm_queue_item_struct * find_item_confirm_type(U16 confirm_type)
{
	U32 i;
	for (i = 0; i < MAX_NMGR_CONFIRM_SCREEN_NUM; i++)
	{
		if (nmgr_confirm_queue[i].confirm_id != 0)
		{
			if (nmgr_confirm_queue[i].cntx->confirm_type == confirm_type)
			{
				return &nmgr_confirm_queue[i];
			}
		}
	}
	return NULL;
}

static MMI_BOOL has_deferred_message(void)
{
	mmi_scenario_id ids[] = {MMI_SCENARIO_ID_NEW_SMS, MMI_SCENARIO_ID_NEW_MMS, MMI_SCENARIO_ID_WAP_PUSH, MMI_SCENARIO_ID_PROVISIOING, MMI_SCENARIO_ID_SIM_SMS};
	U32 i;
	for (i = 0; i < sizeof(ids) /sizeof(ids[0]); i++)
	{
		if (NULL != get_defer_item_id_and_cb(ids[i], nmgr_confirm_defer_cb))
		{
			return MMI_TRUE;
		}
	}
	return MMI_FALSE;
}


MMI_RET mmi_nmgr_op01_defer_check_hdlr(mmi_event_struct *evt)
{
    mmi_nmgr_defer_check_evt_struct *p = (mmi_nmgr_defer_check_evt_struct *)evt;
    if ((p->notify_scenario_id == MMI_SCENARIO_ID_REMINDER_ALARM) &&
        (p->active_scenario_id == MMI_SCENARIO_ID_IN_CALL))
    {
        return MMI_RET_FORCE_DEFER;
    }

	if (is_notify_by_confirm_popup(p->notify_scenario_id) &&
		(p->active_scenario_id == MMI_SCENARIO_ID_IN_CALL))
	{
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0)
        {
            return MMI_RET_OK;
        }
		return MMI_RET_FORCE_DEFER;
	}
    return MMI_RET_OK;
}

MMI_RET mmi_nmgr_um_cb(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_MMI_UM_ENTRY_FOLDER)
    {
        remove_nmgr_confirm(MMI_SCENARIO_ID_NEW_SMS);
    }
    return MMI_RET_OK;
}


static void remove_nmgr_confirm(mmi_scenario_id scen_id)
{

	U16 confirm_type = get_confirm_type(scen_id);
	nmgr_confirm_queue_item_struct * item = find_item_confirm_type(confirm_type);
	if (item != NULL)
	{
		MMI_ID alert_id = item->confirm_id;
		remove_from_nmgr_queue(item->confirm_id);
		mmi_alert_dismiss(alert_id);
	}

}


static MMI_BOOL display_nmgr_confirm(mmi_scenario_id scen_id, mmi_event_notify_enum event_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_struct arg;
	WCHAR *title = construct_string(scen_id, event_type);
	nmgr_confirm_cntx_struct *cntx;
	MMI_ID alert_id;
	MMI_BOOL res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (title == NULL)
	{
		return MMI_FALSE;
	}

	cntx = (nmgr_confirm_cntx_struct *)mmi_frm_malloc(sizeof(nmgr_confirm_cntx_struct));
	cntx->scen_id = scen_id;
	cntx->title   = title;
	cntx->confirm_type = get_confirm_type(scen_id);
	mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);

	arg.callback    = nmgr_confirm_proc;
	arg.parent_id   = GRP_ID_ROOT;
	arg.user_tag    = (void *)cntx;
	arg.f_enter_history = 1;
	arg.softkey[0].str = (WCHAR* )GetString(STR_GLOBAL_VIEW);
	arg.softkey[0].img = 0;
	arg.softkey[1].str = NULL;
	arg.softkey[1].img = 0;
	arg.softkey[2].str = (WCHAR* )GetString(STR_GLOBAL_BACK);
	arg.softkey[2].img = 0;
	alert_id = mmi_confirm_display(title, event_type, &arg);
	res = add_to_nmgr_confirm_queue(alert_id, cntx);
	MMI_ASSERT(res == MMI_TRUE);

	return MMI_TRUE;
}


static MMI_BOOL is_notify_by_confirm_popup(mmi_scenario_id noti_scen_id)
{

	if (noti_scen_id == MMI_SCENARIO_ID_NEW_SMS ||
		noti_scen_id == MMI_SCENARIO_ID_NEW_MMS ||
		noti_scen_id == MMI_SCENARIO_ID_WAP_PUSH ||
		noti_scen_id == MMI_SCENARIO_ID_SIM_SMS ||
		noti_scen_id == MMI_SCENARIO_ID_PROVISIOING ||
		noti_scen_id == MMI_SCENARIO_ID_NEW_EMAIL)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}
#endif //(defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
static MMI_BOOL control_idle_screen(mmi_scenario_id noti_scen_id, mmi_event_notify_enum notify_type, mmi_scen_attr_prio_enum scrn_priority, WCHAR *string, mmi_noti_attr_beha_enum behavior)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 type = MMI_NMGR_APP_NULL;
    U32 flag = MMI_NMGR_OPTION_USE_DEFAULT;
    MMI_BOOL scrn_disp = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__OLED_BW_MMI__)||defined(CUSTOMER_NAME_TOUR)
	return scrn_disp;
#endif /* __OLED_BW_MMI__ */
#if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
    if (is_notify_by_confirm_popup(noti_scen_id))
	{
		mmi_nmgr_defer_check_evt_struct evt;
		MMI_RET force_defer = MMI_RET_OK;		
	#ifdef __DM_LAWMO_SUPPORT__ 
		if (mmi_dmui_is_phone_lock())
		{
			MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_DISBALE_NMGR_BY_DM_LOCK);
			return MMI_FALSE;
		}
	#endif
       MMI_TRACE(PLUTO_FW_TRC_NMGR, TRC_MMI_FRM_NMGR_CONFIRM_POPUP, (behavior == MMI_NOTI_SCRN_BEHA_DISPLAY) ? 0 : 1);
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_FORCE_DEFER_QUERY);
		evt.active_scenario_id = mmi_frm_get_active_scenario_id();
		evt.notify_scenario_id = noti_scen_id;		
		force_defer = MMI_FRM_CB_EMIT_EVENT(&evt);
		if (behavior == MMI_NOTI_SCRN_BEHA_DISPLAY && force_defer != MMI_RET_FORCE_DEFER)
		{
			scrn_disp = do_confirm_popup_notify(noti_scen_id, notify_type);
		}
		else
		{
			if (MMI_FALSE == is_message(noti_scen_id) || MMI_FALSE == has_deferred_message())
			{
				add_notify_defer_notification(noti_scen_id, scrn_priority, nmgr_confirm_defer_cb, (void *)notify_type, NULL, 0);
			}
		}
	}
	else
#endif
	{
		get_event_type_by_scen_id(noti_scen_id, &type, &flag);
		if (type == MMI_NMGR_APP_NULL)
		{
			MMI_ASSERT(MMI_FALSE);
			return MMI_FALSE;
		}
		if (behavior == MMI_NOTI_SCRN_BEHA_NO_DISPLAY)
		{
			flag |= MMI_NMGR_OPTION_LOWER_PRIORITY;
		}
		scrn_disp = mmi_nmgr_notify(type, flag);
	}
    return scrn_disp;
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_get_scenario_behavior_info
 * DESCRIPTION
 *  Get scenario behavior by information of notification scenario and active scenario.
 * PARAMETERS
 *  notify_scenario
 *  active_scenario
 *  behavior
 * RETURNS
 *  void
 *****************************************************************************/
static void get_scenario_behavior_info(mmi_app_scenario_struct *notify_scenario, mmi_app_scenario_struct *active_scenario, mmi_app_behavior_struct *behavior)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    behavior->scrn_behavior = 
        (notify_scenario->scrn_priority >= active_scenario->scrn_priority) ? 
        MMI_NOTI_SCRN_BEHA_DISPLAY : MMI_NOTI_SCRN_BEHA_NO_DISPLAY;
    behavior->snd_behavior = 
        (notify_scenario->snd_priority >= active_scenario->snd_priority) ? 
        MMI_NOTI_SND_BEHA_PALY : MMI_NOTI_SND_BEHA_NO_PLAY;
    behavior->vib_behavior = 
        (notify_scenario->vib_priority >= active_scenario->vib_priority) ? 
        MMI_NOTI_VIB_BEHA_USE : MMI_NOTI_VIB_BEHA_NO_USE;
    behavior->bl_behavior = 
        (notify_scenario->bl_priority >= active_scenario->bl_priority) ? 
        MMI_NOTI_BL_BEHA_PREEMPT : MMI_NOTI_BL_BEHA_NO_PREEMPT;
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_NMGR_GET_SCEN_BEHAVIOR, behavior->scrn_behavior, behavior->snd_behavior, behavior->vib_behavior, behavior->bl_behavior);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_notify_display_popup_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  struct      [IN]        
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_notify_display_popup_callback(mmi_alert_result_evt_struct *evt)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_popup_scrn_arg_struct *info = (mmi_nmgr_popup_scrn_arg_struct *)evt->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (EVT_ID_ALERT_QUIT == evt->evt_id)
     {
         switch (evt->result)
         {
             case MMI_ALERT_NORMAL_EXIT:
             {
                 //StopTimer(POPUP_TIMER);
                 GoBackHistory();
                 mmi_frm_end_scenario(info->noti_scen_id);
                 OslMfree(info);

                 break; 
             }
             case MMI_ALERT_INTERRUPT_EXIT:
	     case MMI_ALERT_NO_SHOW:
             {
                 //StopTimer(POPUP_TIMER);
                // GoBackHistory();
                 mmi_frm_end_scenario(info->noti_scen_id);
                 OslMfree(info);
                 break; 
             }    
             default:
                 break;
         }
     }
    return MMI_RET_OK;
 }


#ifdef __MMI_SUBLCD__
static MMI_BOOL control_sublcd(mmi_scenario_id noti_scen_id, mmi_noti_attr_beha_enum behavior)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (behavior == MMI_NOTI_SCRN_BEHA_NO_DISPLAY)
    {
        return MMI_FALSE;
    }
    emit_sublcd_noftify(noti_scen_id);
	return MMI_TRUE;
}
#endif /*__MMI_SUBLCD__*/

static MMI_BOOL control_popup_screen(mmi_scenario_id noti_scen_id, WCHAR *string, mmi_event_notify_enum notify_type, mmi_noti_attr_beha_enum behavior, mmi_nmgr_behavior_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_popup_scrn_arg_struct *scrn_arg;
    S32 duration;
    const mmi_events_notify_struct *event_notify_info = NULL;
    mmi_popup_property_struct  disp_popup_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (behavior == MMI_NOTI_SCRN_BEHA_NO_DISPLAY)
    {
    #ifdef MMI_NOTI_MGR_UT
        show_poup = MMI_FALSE;
        scrn_action = action;
    #endif
        return MMI_FALSE;
    }
    else
    {
        mmi_frm_start_scenario(noti_scen_id);
        scrn_arg = OslMalloc(sizeof(mmi_nmgr_popup_scrn_arg_struct));
        scrn_arg->noti_scen_id = noti_scen_id;
        scrn_arg->string = string;
        scrn_arg->notify_type = notify_type;

        // show mmi_popup_display
        event_notify_info = mmi_nmgr_get_event_notify_info(scrn_arg->notify_type, mmi_frm_get_active_scenario_id());
        duration = event_notify_info->duration;
             
        mmi_popup_property_init(&disp_popup_info); 
        disp_popup_info.msg_icon = event_notify_info->img_id;
        disp_popup_info.user_tag = scrn_arg;
        disp_popup_info.callback = (mmi_proc_func)mmi_notify_display_popup_callback;
          
        if (duration != MMI_POPUP_DURATION_INFINITE_TIME)
        {
            disp_popup_info.duration = duration;
        }  

        mmi_popup_display(scrn_arg->string, event_notify_info->event_id, &disp_popup_info);
        

    #ifdef MMI_NOTI_MGR_UT
        show_poup = MMI_TRUE;
        scrn_action = action;
    #endif
    }

    return MMI_TRUE;
}

#ifdef __PLUTO_MMI_PACKAGE__

static mmi_ret nmgr_alert_cb_func(mmi_event_struct *param)
{
    mmi_event_struct evt;
    mmi_nmgr_cb_evt_struct *p = (mmi_nmgr_cb_evt_struct *)param;
    if(p->scrn_group_proc!=NULL)
    {
        MMI_FRM_INIT_EVENT(&evt, p->evt_id);    
        MMI_FRM_SEND_EVENT(&evt, p->scrn_group_proc, p->proc_user_data);   
    }
    /*free user data*/
    if( p->proc_user_data!=NULL)
    {
        mmi_frm_nmgr_mem_free((void *) p->proc_user_data);
    }
    return MMI_RET_OK;
}


static mmi_ret nmgr_alert_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nmgr_alert_popup_active_item_struct *popup_ptr = (nmgr_alert_popup_active_item_struct *)(evt->user_data);
    nmgr_alert_popup_active_item_struct *remove_node = NULL, *prev_remove_node=NULL;
    MMI_BOOL isNeedToFree = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {        
        case EVT_ID_GROUP_DEINIT:
       { /*Launch app or cancel*/    
        if(popup_ptr->popup_scrn_group_id != GRP_ID_INVALID &&
            popup_ptr->popup_pressed != MMI_TRUE  &&
            popup_ptr->popup_info.app_proc_para.scrn_group_proc)
        {        
            mmi_event_struct evt;
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_ALERT_END);
            MMI_FRM_SEND_EVENT(&evt, popup_ptr->popup_info.app_proc_para.scrn_group_proc, popup_ptr->popup_info.app_proc_para.user_data);   
            isNeedToFree = MMI_TRUE;
        }    
        /*remove node from popup stack list*/        
        for(  remove_node = g_nmgr_active_popup_list.next; 
            remove_node!=NULL ; 
            prev_remove_node = remove_node, remove_node=remove_node->next)
            {
                if(remove_node->popup_scrn_group_id == popup_ptr->popup_scrn_group_id)
                {            
                    /*Remove the node from list*/
                    if(prev_remove_node == NULL)
                    {                        
                        g_nmgr_active_popup_list.next = remove_node->next;
                    }
                    else
                    {
                        prev_remove_node->next = remove_node->next;
                    }
                    g_nmgr_active_popup_list.list_counter--;    
                    /*free popup string temp buffer*/
                    if(remove_node->popup_info.popup_para.popup_string)
                    {
                        mmi_frm_nmgr_mem_free((void *)remove_node->popup_info.popup_para.popup_string);
                        remove_node->popup_info.popup_para.popup_string = NULL;
                    }
                    /*free popup button temp buffer*/
                    if(remove_node->popup_info.popup_para.popup_button_string)
                    {
                        mmi_frm_nmgr_mem_free((void *)remove_node->popup_info.popup_para.popup_button_string);
                        remove_node->popup_info.popup_para.popup_button_string = NULL;
                    }
                    /*free app user data*/
                    if(isNeedToFree == MMI_TRUE &&
                       remove_node->popup_info.app_proc_para.user_data!=NULL && 
                       remove_node->popup_info.app_proc_para.data_size > 0 )
                    {
                        mmi_frm_nmgr_mem_free(remove_node->popup_info.app_proc_para.user_data);
                        remove_node->popup_info.app_proc_para.user_data = NULL;
                    }
                    /*free image file path*/
                    if(remove_node->popup_info.popup_para.image_type == MMI_NMGR_IMG_FILE_PATH
                        && remove_node->popup_info.popup_para.image.file_path != NULL)
                    {
                        mmi_frm_nmgr_mem_free(remove_node->popup_info.popup_para.image.file_path);
                        remove_node->popup_info.popup_para.image.file_path = NULL;
                    }
                    mmi_frm_nmgr_mem_free(remove_node);
                                        
                }
            }   
                
        break;
      }
    default:
        break;
    }	
    return MMI_RET_OK;
}


void nmgr_alert_pluto_popup_sk_common_cb(U8 sk_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_nmgr_cb_evt_struct evt;
    U16 evt_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/          
    g_active_popup->popup_pressed = MMI_TRUE;

    /* choose the alert event */
    MMI_ASSERT((sk_id == NMGR_ALERT_PLUTO_POPUP_RSK_ID) || (sk_id == NMGR_ALERT_PLUTO_POPUP_LSK_ID));
    evt_id = (sk_id == NMGR_ALERT_PLUTO_POPUP_RSK_ID) ? EVT_ID_NMGR_ALERT_END : EVT_ID_NMGR_POPUP_APP_LAUNCH;
    MMI_FRM_INIT_EVENT(&evt, evt_id);
    evt.scrn_group_proc = g_active_popup->popup_info.app_proc_para.scrn_group_proc;    
    evt.proc_user_data = NULL;
    if(g_active_popup->popup_info.app_proc_para.data_size > 0)
    {
        evt.proc_user_data = g_active_popup->popup_info.app_proc_para.user_data;
    }
    MMI_FRM_POST_EVENT(&evt,&nmgr_alert_cb_func, NULL);   
    mmi_frm_group_close(g_active_popup->popup_scrn_group_id); 
}


/*
  * Right softkey is "cancel", we need to tell app this information and then 
  * go back to the previous screen
  */
static void nmgr_alert_pluto_popup_rsk_callback(void)
{       
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/          

    nmgr_alert_pluto_popup_sk_common_cb(NMGR_ALERT_PLUTO_POPUP_RSK_ID);
}

/*
  * Left softkey is "View", we need to tell app this information and launch app 
  */
static void nmgr_alert_pluto_popup_lsk_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nmgr_alert_pluto_popup_sk_common_cb(NMGR_ALERT_PLUTO_POPUP_LSK_ID);
}



static mmi_ret nmgr_alert_pluto_popup_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nmgr_alert_popup_active_item_struct *info = (nmgr_alert_popup_active_item_struct *)evt->user_data;
    //PU8 image_data = NULL;
    WCHAR *lsk_string = NULL;
    WCHAR *rsk_string = NULL;
	MMI_STR_ID popup_button_string_id = 0;
	MMI_STR_ID popup_string_id = 0;
   // wgui_cat_popup_icon_type_enum message_icon_type = NO_POPUP_IMAGE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_INACTIVE:
        {
            mmi_frm_end_scenario(info->popup_info.scen_id);
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {            
            mmi_frm_start_scenario(info->popup_info.scen_id);
            set_small_screen();
            ClearHighlightHandler();

            g_active_popup = info;
			popup_button_string_id = (MMI_STR_ID)info->popup_info.popup_para.popup_button_str_id;
			popup_string_id = (MMI_STR_ID)info->popup_info.popup_para.popup_str_id;

            if(info->popup_info.popup_para.popup_type == MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE)
            {
               lsk_string = (WCHAR *)GetString(STR_GLOBAL_OK);
            }
            else
            {
               lsk_string = (WCHAR *)info->popup_info.popup_para.popup_button_string;
               rsk_string = (WCHAR *)GetString(STR_GLOBAL_CANCEL);
			   if(popup_button_string_id != 0)
			   {
                  lsk_string =(WCHAR *)GetString(popup_button_string_id); 
			   }
            }
            
			if(popup_string_id != 0)
			{
			   (WCHAR *)info->popup_info.popup_para.popup_string = (WCHAR *)GetString(popup_string_id); 
			}
            switch(info->popup_info.popup_para.image_type)
            {
                case MMI_NMGR_IMG_RES_ID:
                    ShowCategory163Screen_ext(
                    lsk_string,
                    rsk_string,
                    (WCHAR *)info->popup_info.popup_para.popup_string,
                    IMAGE_BUFFER,
                    (PU8)GetImage(info->popup_info.popup_para.image.id),
                    0,
                    0,
                    NULL,
                    NULL);      
                    break;
                case MMI_NMGR_IMG_FILE_PATH:   
                    ShowCategory163Screen_ext(
                    lsk_string,
                    rsk_string,
                    (WCHAR *)info->popup_info.popup_para.popup_string,
                    IMAGE_FILE_PATH,
                    NULL,
                    0,
                    0,
                    info->popup_info.popup_para.image.file_path,
                    NULL);      
                    break;
                case MMI_NMGR_IMG_RAW_DATA_BUFF:    
                    ShowCategory163Screen_ext(
                    lsk_string,
                    rsk_string,
                    (WCHAR *)info->popup_info.popup_para.popup_string,
                    IMAGE_BUFFER_WITHOUT_HEADER,
                    info->popup_info.popup_para.image.raw_data.buff,
                    (S32)info->popup_info.popup_para.image.raw_data.size,
                    (U8)info->popup_info.popup_para.image.raw_data.format,
                    NULL,
                    NULL);       
                    break;
                case MMI_NMGR_IMG_DATA_BUFF:                    
                    ShowCategory163Screen_ext(
                    lsk_string,
                    rsk_string,
                    (WCHAR *)info->popup_info.popup_para.popup_string,
                    IMAGE_BUFFER_WITHOUT_HEADER,
                    info->popup_info.popup_para.image.data,
                    0,
                    0,
                    NULL,
                    NULL);        
                    break;
            }
        
            break;
        }
        case EVT_ID_WGUI_LSK_CLICK:
        case EVT_ID_WGUI_CSK_CLICK:
        {
            if(info->popup_info.popup_para.popup_type == MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE)    
            {
                nmgr_alert_pluto_popup_rsk_callback();           
            }
            else
            {                                        
                nmgr_alert_pluto_popup_lsk_callback();             
            }
            return MMI_RET_KEY_HANDLED;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            if(info->popup_info.popup_para.popup_type != MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE)    
            {
                nmgr_alert_pluto_popup_rsk_callback();           
            }
            return MMI_RET_KEY_HANDLED;
        }
        default:
            break;
    }   
    return MMI_RET_OK;
}
static U8 nmgr_alert_pluto_popup_scrn_exit_hdlr(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nmgr_alert_popup_active_item_struct *remove_item = (nmgr_alert_popup_active_item_struct *)arg->user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    mmi_frm_end_scenario(remove_item->popup_info.scen_id);
    return 0;
}

static void nmgr_alert_pluto_popup_scrn_entry(mmi_scrn_essential_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nmgr_alert_popup_active_item_struct *info = (nmgr_alert_popup_active_item_struct *)arg->user_data;
    PU8 image_data = NULL;
    WCHAR *lsk_string = NULL;
    WCHAR *rsk_string = NULL;
    wgui_cat_popup_icon_type_enum message_icon_type = NO_POPUP_IMAGE;
    MMI_STR_ID popup_button_string_id = 0;
	MMI_STR_ID popup_string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_start_scenario(info->popup_info.scen_id);
    if (mmi_frm_scrn_enter(arg->group_id,
                            arg->scrn_id, 
                            (FuncPtr)nmgr_alert_pluto_popup_scrn_exit_hdlr, 
                            (FuncPtr)nmgr_alert_pluto_popup_scrn_entry,
                            MMI_FRM_SMALL_SCRN))
    {
        ClearHighlightHandler();

        g_active_popup = info;
		popup_button_string_id = (MMI_STR_ID)info->popup_info.popup_para.popup_button_str_id;
		popup_string_id = (MMI_STR_ID)info->popup_info.popup_para.popup_str_id;

        if(info->popup_info.popup_para.popup_type == MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE)
        {
           lsk_string = (WCHAR *)GetString(STR_GLOBAL_OK);
        }
        else
        {
           lsk_string = (WCHAR *)info->popup_info.popup_para.popup_button_string;
           rsk_string = (WCHAR *)GetString(STR_GLOBAL_CANCEL);
		   
		   if(popup_button_string_id != 0)
		   {
           		lsk_string =(WCHAR *)GetString(popup_button_string_id); 
		   }
        }
		
		if(popup_string_id != 0)
		{
			(WCHAR *)info->popup_info.popup_para.popup_string = (WCHAR *)GetString(popup_string_id); 
		}   
		
        switch(info->popup_info.popup_para.image_type)
        {
            case MMI_NMGR_IMG_RES_ID:
                ShowCategory163Screen_ext(
                lsk_string,
                rsk_string,
                (WCHAR *)info->popup_info.popup_para.popup_string,
                IMAGE_BUFFER,
                (PU8)GetImage(info->popup_info.popup_para.image.id),
                0,
                0,
                NULL,
                NULL);      
                break;
            case MMI_NMGR_IMG_FILE_PATH:   
                ShowCategory163Screen_ext(
                lsk_string,
                rsk_string,
                (WCHAR *)info->popup_info.popup_para.popup_string,
                IMAGE_FILE_PATH,
                NULL,
                0,
                0,
                info->popup_info.popup_para.image.file_path,
                NULL);      
                break;
            case MMI_NMGR_IMG_RAW_DATA_BUFF:    
                ShowCategory163Screen_ext(
                lsk_string,
                rsk_string,
                (WCHAR *)info->popup_info.popup_para.popup_string,
                IMAGE_BUFFER_WITHOUT_HEADER,
                info->popup_info.popup_para.image.raw_data.buff,
                (S32)info->popup_info.popup_para.image.raw_data.size,
                (U8)info->popup_info.popup_para.image.raw_data.format,
                NULL,
                NULL);       
                break;
            case MMI_NMGR_IMG_DATA_BUFF:                    
                ShowCategory163Screen_ext(
                lsk_string,
                rsk_string,
                (WCHAR *)info->popup_info.popup_para.popup_string,
                IMAGE_BUFFER_WITHOUT_HEADER,
                info->popup_info.popup_para.image.data,
                0,
                0,
                NULL,
                NULL);        
                break;
        }

        if(info->popup_info.popup_para.popup_type == MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE)    
        {
        		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
         		SetCenterSoftkeyFunction(nmgr_alert_pluto_popup_rsk_callback, KEY_EVENT_UP);           
            SetLeftSoftkeyFunction(nmgr_alert_pluto_popup_rsk_callback, KEY_EVENT_UP);
        }
        else
        {                                        
        		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetRightSoftkeyFunction(nmgr_alert_pluto_popup_rsk_callback, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(nmgr_alert_pluto_popup_lsk_callback, KEY_EVENT_UP);   
            SetLeftSoftkeyFunction(nmgr_alert_pluto_popup_lsk_callback, KEY_EVENT_UP);            
        }
    }
}

static MMI_BOOL nmgr_alert_pluto_popup(void *arg)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id popup_scrn_group_id;
    nmgr_alert_popup_active_item_struct *active_popup = NULL;
    mmi_frm_nmgr_alert_struct *info = (mmi_frm_nmgr_alert_struct *)arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    /*The maximum number of stack popup is 5, if exceed, we will replace the oldest one*/
    if(g_nmgr_active_popup_list.list_counter == MMI_MAX_CONCURRENT_POPUP_NUM)    
    {//Remove the latest one
        nmgr_alert_popup_active_item_struct *remove_node = NULL;
        /*seek the oldest item*/
        for(  remove_node = g_nmgr_active_popup_list.next; 
            remove_node->next !=NULL ; 
            remove_node = remove_node->next);     
        /*remove the item*/            
        mmi_frm_group_close(remove_node->popup_scrn_group_id); 
    }

    active_popup = mmi_frm_nmgr_mem_malloc(sizeof(nmgr_alert_popup_active_item_struct));
    MMI_ASSERT(active_popup);
    /*Clear the mem*/
    memset(active_popup, 0, sizeof(nmgr_alert_popup_active_item_struct));
    /*Fill in popup info*/
    memcpy(&active_popup->popup_info, info, sizeof(mmi_frm_nmgr_alert_struct));
    /*Save the popup string*/
    active_popup->popup_info.popup_para.popup_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal( 
        (WCHAR *)info->popup_para.popup_string, 
        MMI_FRM_NMGR_POPUP_TEXT_CHAR_COUNT);
    /*Save the button string*/    
    active_popup->popup_info.popup_para.popup_button_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(        
        (WCHAR *)info->popup_para.popup_button_string, 
        MMI_FRM_NMGR_BUTTON_TEXT_CHAR_COUNT);
     /*Save the image file path*/
    if(active_popup->popup_info.popup_para.image_type == MMI_NMGR_IMG_FILE_PATH)
    {
        active_popup->popup_info.popup_para.image.file_path = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal( 
        info->popup_para.image.file_path,
        MMI_MAX_FILE_NAME_LEN
        );
    }
    /*Save the user data*/
    if(info->app_proc_para.data_size > 0)
    {                
        active_popup->popup_info.app_proc_para.user_data = mmi_frm_alloc_and_copy_data_to_nmgr_buff_internal(
        info->app_proc_para.user_data,
        info->app_proc_para.data_size
        );
    }
    /*link to list and update list counter*/
    active_popup->next = g_nmgr_active_popup_list.next;
    g_nmgr_active_popup_list.next = active_popup;
    g_nmgr_active_popup_list.list_counter++;

    /*the number of active popup is not enough*/
/*
    popup_scrn_group_id = mmi_frm_group_create_ex(GRP_ID_ROOT, 
                        GRP_ID_AUTO_GEN,
                        nmgr_alert_group_proc,
                        active_popup,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    active_popup->popup_scrn_group_id = popup_scrn_group_id;
    mmi_frm_scrn_create(popup_scrn_group_id, SCR_ID_NMGR_NOTIFY, nmgr_alert_pluto_popup_scrn_proc, active_popup);
*/

	/*the number of active popup is not enough*/
	
	  popup_scrn_group_id = mmi_frm_group_create(GRP_ID_ROOT, 
								  GRP_ID_AUTO_GEN, 
								  nmgr_alert_group_proc, 
								  active_popup);
	  
	  active_popup->popup_scrn_group_id = popup_scrn_group_id;
		  
	  mmi_frm_group_enter(popup_scrn_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	  mmi_frm_scrn_first_enter(popup_scrn_group_id, SCR_ID_NMGR_NOTIFY, (FuncPtr)nmgr_alert_pluto_popup_scrn_entry, active_popup);

    return MMI_TRUE;    
}


static MMI_BOOL nmgr_alert_pluto_popup_is_defer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_id = mmi_frm_group_get_active_id();
    nmgr_alert_popup_active_item_struct *find_node = NULL;        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    for(  find_node = g_nmgr_active_popup_list.next; 
            find_node!= NULL ; 
            find_node = find_node->next)
    {
        /*If active id is not anyone of the popup stack list*/
        /*It means we can show the popup directly, so not need to defer*/
        if(find_node->popup_scrn_group_id == active_id)
        {
            return MMI_TRUE;
        }
    }       
    return MMI_FALSE;
}

static MMI_BOOL nmgr_alert_pluto_popup_refresh(mmi_frm_nmgr_alert_struct *refresh_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_refresh = MMI_FALSE;
    nmgr_alert_popup_active_item_struct *find_node = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(  find_node = g_nmgr_active_popup_list.next; 
            find_node!= NULL ; 
            find_node = find_node->next)
    {    
         /*Check if the new node is the same as any node in popup stack list*/
        if(find_node->popup_scrn_group_id != GRP_ID_INVALID &&
            find_node->popup_info.app_id == refresh_item->app_id && 
            find_node->popup_info.event_type == refresh_item->event_type && 
            find_node->popup_info.popup_para.popup_type == refresh_item->popup_para.popup_type && 
            find_node->popup_info.app_proc_para.scrn_group_proc== refresh_item->app_proc_para.scrn_group_proc)
        {
            /*If active id is the same as current popup, we can refresh it directly*/
            MMI_ID active_id = mmi_frm_group_get_active_id();
            if(active_id == find_node->popup_scrn_group_id)
            {
                is_refresh = MMI_TRUE;
            }
            /*
         * In tranditional pluto UI, if we want to refresh popup screen, 
         * we need to close current popup scrn and then popup a new one
         */                        
            mmi_frm_group_close(find_node->popup_scrn_group_id);   
                        
            if(is_refresh)
            {
                nmgr_alert_pluto_popup(refresh_item);    
                return MMI_TRUE;
            }
            else
            {                
                return MMI_FALSE;
            }
        }      
    }    
    return MMI_FALSE;
}

static void nmgr_alert_pluto_popup_cancel(MMI_ID app_id, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nmgr_alert_popup_active_item_struct *find_node = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(  find_node = g_nmgr_active_popup_list.next; 
            find_node!= NULL ; 
            find_node = find_node->next)
    {    
         /*Check if the new node is the same as any node in popup stack list*/
        if(find_node->popup_scrn_group_id != GRP_ID_INVALID &&
            find_node->popup_info.app_id == app_id && 
            find_node->popup_info.event_type == event_type)
        {            
            mmi_frm_group_close(find_node->popup_scrn_group_id);            
        }      
    }    
    return;
}


#endif

/*****************************************************************************
 * FUNCTION
 *  nmgr_alert_general_popup
 * DESCRIPTION
 *  call general popup
 * PARAMETERS
 * RETURNS
 *  TRUE for suc to call
 *****************************************************************************/
static MMI_BOOL nmgr_alert_general_popup(mmi_scenario_id scen_id, void *arg)
{
#ifdef __COSMOS_MMI_PACKAGE__
    return vadp_v2p_nmgr_alert_popup(arg);
#endif
#ifdef __PLUTO_MMI_PACKAGE__
    return nmgr_alert_pluto_popup(arg);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  nmgr_alert_popup_refresh
 * DESCRIPTION
 *  Check if need to refresh, if needed, refresh it directly
 * PARAMETERS
 * RETURNS
 * TRUE for refreshed, FALSE for non-refresh
 *****************************************************************************/
static MMI_BOOL nmgr_alert_popup_refresh(mmi_frm_nmgr_alert_struct *refresh_item)
{
#ifdef __COSMOS_MMI_PACKAGE__
    return vadp_v2p_nmgr_alert_popup_refresh(refresh_item);
#endif
#ifdef __PLUTO_MMI_PACKAGE__
    return nmgr_alert_pluto_popup_refresh(refresh_item);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  nmgr_alert_popup_cancel
 * DESCRIPTION
 *  Cancel popup
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void nmgr_alert_popup_cancel(MMI_ID app_id, mmi_event_notify_enum event_type)
{
#ifdef __COSMOS_MMI_PACKAGE__
    vadp_v2p_nmgr_alert_popup_cancel(app_id, event_type);
#endif
#ifdef __PLUTO_MMI_PACKAGE__
    nmgr_alert_pluto_popup_cancel(app_id, event_type);
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  nmgr_alert_popup_is_defer
 * DESCRIPTION
 *  Help to check if need to defer
 *  (if active id == anyone of general popup, then defer to show notification)
 *  This behavior can help to show different popup one by one and the interval is one second
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL nmgr_alert_popup_is_defer()
{
#ifdef __COSMOS_MMI_PACKAGE__
    return vadp_v2p_nmgr_alert_popup_is_defer();
#endif
#ifdef __PLUTO_MMI_PACKAGE__
    return nmgr_alert_pluto_popup_is_defer();
#endif

}


#ifdef __MMI_NCENTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  nmgr_alert_launch_app_callback
 * DESCRIPTION
 *  Help to launch app on preview
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void nmgr_alert_launch_app_callback(void)
{

    mmi_event_struct evt;
    MMI_BOOL is_scrn_locked = MMI_FALSE;
    /*We will not hook tap when scrn locked*/    
    is_scrn_locked = mmi_scr_locker_is_locked();

    if(is_scrn_locked == MMI_FALSE && active_info.app_proc_para.scrn_group_proc)
    {
        g_is_app_launched = MMI_TRUE;
        /*unregister the hook*/
        #ifdef __MMI_TOUCH_SCREEN__
        wgui_status_icon_bar_register_tap_proc(NULL);    
        #endif
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH);
        MMI_FRM_SEND_EVENT(&evt, active_info.app_proc_para.scrn_group_proc, active_info.app_proc_para.user_data);   
    }

}

/*****************************************************************************
 * FUNCTION
 *  nmgr_alert_cancel_launch_app_callback
 * DESCRIPTION
 *  Help to cancel launch app on preview
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void nmgr_alert_cancel_launch_app_callback(void)
{
   // #ifdef __MMI_NCENTER_SUPPORT__
    mmi_event_struct evt;
    if(active_info.app_proc_para.scrn_group_proc && g_is_app_launched != MMI_TRUE)
    {
        /*Unregister the hook*/
        #ifdef __MMI_TOUCH_SCREEN__
        wgui_status_icon_bar_register_tap_proc(NULL);    
        #endif
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_ALERT_END);
        MMI_FRM_SEND_EVENT(&evt, active_info.app_proc_para.scrn_group_proc, active_info.app_proc_para.user_data);   
    }
    g_is_app_launched = MMI_FALSE;
    //#endif
}
#endif  /*__MMI_NCENTER_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  nmgr_alert_proc
 * DESCRIPTION
 *  Handle show notification or cancel event
 *
 * PARAMETERS
 *  evt       : [IN] notification event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/

static mmi_ret nmgr_alert_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_DO_ALERT)
    {
        notification_info_struct noti_info;				
        mmi_nmgr_alert_evt_struct *p = (mmi_nmgr_alert_evt_struct *)evt;
        /*Fill in the basic notification information*/
        fill_notification_info(&noti_info,
                           p->noti.scen_id, 
			                     p->noti.event_type,
			                     NULL,
			                     NULL,
			                     NULL,
			                     NULL,
			                     MMI_NMGR_BALLOON_TYPE_TOTAL,
			                     &p->noti);
           
        control_notification(
                     MMI_NOTIFY_ALERT,
                     &noti_info);  
        /*Free status bar temp buffer here */
        if (p->noti.behavior_mask == ALERT_TYPE_STATUS_BAR)
        {
            /*Free display string temp buffer*/
            if(p->noti.status_bar_para.display_string!=NULL)
            {
                mmi_frm_nmgr_mem_free((void *)p->noti.status_bar_para.display_string);
            }
            if(p->noti.status_bar_para.status_bar_type == MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE)
            {
                /*Free user data buffer*/
                if(p->noti.app_proc_para.user_data!=NULL && 
                           p->noti.app_proc_para.data_size > 0 )
                {
                    mmi_frm_nmgr_mem_free(p->noti.app_proc_para.user_data);
                    p->noti.app_proc_para.user_data = NULL;
                }
                /*Free image file path temp buffer*/            
                if(p->noti.status_bar_para.image_type == MMI_NMGR_IMG_FILE_PATH && 
                    p->noti.status_bar_para.image.file_path!=NULL)
                {
                    mmi_frm_nmgr_mem_free(p->noti.status_bar_para.image.file_path);
                    p->noti.status_bar_para.image.file_path = NULL;
                }
                if(p->noti.snd_para.sound_type == MMI_NMGR_SND_FILE_PATH &&
                    p->noti.snd_para.sound.file_path != NULL)
                {
                    mmi_frm_nmgr_mem_free(p->noti.snd_para.sound.file_path);
                    p->noti.snd_para.sound.file_path = NULL;
                }
            }            
        }
    }   
    return MMI_RET_OK;
}



static void do_preview_cancel(mmi_event_notify_enum type, MMI_ID app_id, S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_NSS_SUPPORT__
    U32 i;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_NCENTER_SUPPORT__    
    merge_preview_queue(type , app_id);
    if (is_on_preview == MMI_TRUE)
    {
        if (active_info.app_id == app_id && active_info.event_type == type)
        {
            active_info.option |= MMI_FRM_NMGR_DISABLE_STATUS_ICON;
        }
    }
#endif    
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
#if defined(__MMI_NSS_SUPPORT__) && defined(__MMI_NCENTER_SUPPORT__)
    if(app_id != 0)
    {
        for(i = 0; i < MAXIMUM_STATUS_ICON_NUM; i++)
        {
            if(g_nss_app_icon[i].app_id == app_id &&
               g_nss_app_icon[i].icon_id == icon_id )
            {
                memset(&g_nss_app_icon[i], 0, sizeof(nmgr_support_nss_ncenter_setting_struct));
                break;
            }
        }
    }
#endif
    if (!wgui_status_icon_bar_whether_icon_display(icon_id))
    {
        return;
    }

    remove_status_icon(icon_id);

}

#ifdef __MMI_NCENTER_SUPPORT__

static void control_preview(mmi_event_notify_enum type, 
            mmi_frm_notification_para_struct *notification, 
            mmi_frm_nmgr_alert_struct *alert_info,            
            MMI_BOOL is_stop_text_preview)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/          
    
    if (notification->option == 0xF000)
    {
        return;
    }
    
    if (is_stop_text_preview == MMI_TRUE ||        
        notification->text == NULL ||
        notification->option & MMI_FRM_NMGR_DISABLE_PREVIEW)
    {
         if(alert_info == NULL)
             control_status_icon(0, notification->option, get_status_icon(type));         
         else
             control_status_icon(alert_info->app_id, alert_info->alert_option, alert_info->status_bar_icon_para.icon_id);             
    }    
    else
    {
        mmi_nmgr_preview_info_struct info;
        memset(&info, 0, sizeof(mmi_nmgr_preview_info_struct));
        info.event_type = type;
        info.text       = (WCHAR *)notification->text;
        info.option     = notification->option;
        if(alert_info!=NULL)
        {
            info.app_id = alert_info->app_id;
            info.image_type = alert_info->status_bar_para.image_type;
            memcpy(&info.image, &alert_info->status_bar_para.image, sizeof(alert_info->status_bar_para.image));
            memcpy(&info.status_bar_icon_para, &alert_info->status_bar_icon_para, sizeof(alert_info->status_bar_icon_para));
            memcpy(&info.app_proc_para, &alert_info->app_proc_para, sizeof(alert_info->app_proc_para));
        }
        
        write_preview_queue(&info);
        if (is_on_preview == MMI_FALSE)
        {
            info.text = preview_text;            
            info.app_proc_para.user_data = preview_data;            
                        
            if (MMI_TRUE == read_preview_queue(&info))
            {
                S32 icon_id;

                if(info.app_id!=0)
                    icon_id = info.image.id;                
                else
                    icon_id = get_image_icon_for_preivew(info.event_type);          
                
                memcpy(&active_info, &info, sizeof(mmi_nmgr_preview_info_struct));
                srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

                if(active_info.app_proc_para.scrn_group_proc!=NULL)
                {
                    #ifdef __MMI_TOUCH_SCREEN__
                    wgui_status_icon_bar_register_tap_proc(nmgr_alert_launch_app_callback);
                    #endif
                }
                
                if(info.app_id!=0 && info.image_type != MMI_NMGR_IMG_RES_ID)
                {                    
                    switch(info.image_type)
                    {
                        case MMI_NMGR_IMG_FILE_PATH:
                            wgui_status_icon_bar_show_info_file(
                                (S8 *)info.image.file_path,
                                (WCHAR *)info.text, 
                                MMI_FRM_NMGR_TEXT_PREVIEW_LONG_DURATION, 
                                NULL, 
                                preview_done_cb);
                        break;    
                        case MMI_NMGR_IMG_DATA_BUFF:
                            wgui_status_icon_bar_show_info_ex(
                                info.image.data,
                                (WCHAR *)info.text, 
                                MMI_FRM_NMGR_TEXT_PREVIEW_LONG_DURATION, 
                                NULL, 
                                preview_done_cb);
                        break;    
                        case MMI_NMGR_IMG_RAW_DATA_BUFF:
                           wgui_status_icon_bar_show_info_mem(
                            info.image.raw_data.buff, 
                            info.image.raw_data.size, 
                            info.image.raw_data.format,
                            (WCHAR *)info.text, 
                            MMI_FRM_NMGR_TEXT_PREVIEW_LONG_DURATION, 
                            NULL, 
                            preview_done_cb);
                        break;    
                    }                        
                }
                else
                {
                    wgui_status_icon_bar_show_info(
                        icon_id,
                        (WCHAR *)info.text, 
                        MMI_FRM_NMGR_TEXT_PREVIEW_LONG_DURATION, 
                        NULL, 
                        preview_done_cb);                    
                }                
                is_on_preview = MMI_TRUE;
            }
        }
    }      
}

static mmi_ret nmgr_preview_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_DO_PREVIEW)
    {
        notification_info_struct noti_info;				
        mmi_nmgr_preview_evt_struct *p = (mmi_nmgr_preview_evt_struct *)evt;
     
        fill_notification_info(&noti_info,
            p->scenario_id, 
			p->type,
			NULL,
			NULL,
			NULL,
			&p->noti,
			MMI_NMGR_BALLOON_TYPE_TOTAL,
			NULL);
        
        control_notification(
        MMI_NOTIFY_PREVIEW,
        &noti_info
        );  
       
        if (p->noti.text != NULL)
        {
            mmi_frm_nmgr_mem_free((void *)p->noti.text);
        }
    }
    else if(evt->evt_id == EVT_ID_CANCEL_PREVIEW)
    {
        mmi_nmgr_cancel_preview_evt_struct *p = (mmi_nmgr_cancel_preview_evt_struct *)evt;
        do_preview_cancel(p->type ,  0, get_status_icon(p->type));
    }
    return MMI_RET_OK;
}


#endif

#ifdef __COSMOS_MMI_PACKAGE__
static MMI_BOOL control_balloon(
    mmi_event_notify_enum type,
    mmi_nmgr_balloon_type_enum balloon_type,
    WCHAR *string, 
    mmi_frm_nmgr_alert_struct *alert_info)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_balloon_pattern_enum pattern;
    S32 x = 0;
    S32 y = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_EVENT_INFO_BALLOON)
    {
        pattern = MMI_NMGR_BALLOON_ABOVE_TOOL_BAR;
    }
    else
    {
        S32 x1;
        S32 y1;
        S32 x2;
        S32 y2;

        S32 icon = 0;
        if(alert_info==NULL)
        {
            icon = get_status_icon(type);
        }
        else
        {
            icon = alert_info->status_bar_icon_para.icon_id;
        }
        
        if (MMI_FALSE == wgui_status_icon_bar_is_display(WGUI_STATUS_ICON_BAR_H_BAR))
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_BALLOON_NO_STATUS_BAR);
            return MMI_FALSE;
        }
        if (wgui_status_icon_bar_get_icon_area(icon, &x1, &y1, &x2, &y2) == MMI_FALSE)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_BALLOON_NO_STATUS_ICON);
            return MMI_FALSE;
        }
        g_balloon_icon = icon;
        x = x1 + (x2 - x1) / 2;
        pattern = MMI_NMGR_BALLOON_UNDER_STATUS_BAR;
        y = MMI_STATUS_BAR_HEIGHT;
    }
    vadp_v2p_nmgr_display_info_balloon(pattern, x, y, balloon_type, string);    
 
	return MMI_TRUE;
}
#endif   


static mmi_ret nmgr_balloon_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    notification_info_struct noti_info;     
    mmi_nmgr_balloon_evt_struct *b_evt = (mmi_nmgr_balloon_evt_struct *)evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_get_post_event_number() > mmi_frm_get_post_num_by_proc(nmgr_balloon_proc))
    {
        MMI_FRM_POST_EVENT(evt, nmgr_balloon_proc, NULL);
        return MMI_RET_OK;
    }

    fill_notification_info(&noti_info,
        b_evt->scenario_id,
        b_evt->type,
        (WCHAR *)b_evt->string,
        NULL,
        NULL,
        NULL,
        b_evt->balloon_type,
        NULL);
    
    control_notification(
    MMI_NOTIFY_BALLOON,
    &noti_info
    );  

    return MMI_RET_OK;

}



static MMI_BOOL control_app_screen(
                                mmi_scenario_id noti_scen_id, 
                                mmi_scen_attr_prio_enum scrn_priority, 
                                mmi_noti_attr_beha_enum behavior, 
                                mmi_noti_scrn_func_ptr scrn_func_ptr, 
                                void *arg, 
                                mmi_nmgr_behavior_enum action,
                                mmi_frm_nmgr_alert_struct *alert_info,
                                mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    
#if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
    mmi_nmgr_defer_check_evt_struct evt;
    MMI_RET force_defer = MMI_RET_OK;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_FORCE_DEFER_QUERY);
    evt.active_scenario_id = mmi_frm_get_active_scenario_id();
    evt.notify_scenario_id = noti_scen_id;
    force_defer = MMI_FRM_CB_EMIT_EVENT(&evt);
#endif
    
    if(alert_info!=NULL &&(alert_info->alert_option&MMI_FRM_NMGR_DISABLE_POPUP))
    {
        return MMI_TRUE;
    }
    /*Refresh popup message if the app id and event type are the same as the current popup*/
    if(alert_info!=NULL && nmgr_alert_popup_refresh(alert_info))
    {          
        return MMI_TRUE;
    }

    
    MMI_ASSERT(NULL != scrn_func_ptr);
    if (nmgr_alert_popup_is_defer() ||
    #if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
        force_defer == MMI_RET_FORCE_DEFER ||
    #endif
        (behavior == MMI_NOTI_SCRN_BEHA_NO_DISPLAY || 
        (mmi_frm_nmgr_get_defer_notification_count() > 0 && should_defer_notified_event(scrn_priority))) &&
        (action == MMI_BEHAVIOR_SCRN_DEFER) ||
		(behavior == MMI_NOTI_SCRN_BEHA_NO_DISPLAY) && (action == MMI_BEHAVIOR_SCRN_DEFER_FIRST))
    {/* 
      * If there're defer events, we put notified event to defer queue, 
      * when timeout we choose highest deferred event to process.
      */
        add_notify_defer_notification(noti_scen_id, scrn_priority, scrn_func_ptr, arg, alert_info, event_type);

        StartTimer(MMI_NOTIFICATION_SERVICE_TIMER, 
            MMI_NOTIFY_INVOKE_TIME, 
            (FuncPtr)invoke_notify_defer_notification);
    }
    else if (behavior == MMI_NOTI_SCRN_BEHA_DISPLAY)
    {/* App's entry funcion could decide whether display screen. */
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_NMGR_APP_SCRN, noti_scen_id, scrn_func_ptr, arg);
        result = scrn_func_ptr(noti_scen_id, arg);
    }
    else /* NO_DISPLAY && NO_DEFER */
    {/* User disable defer funcitonality in mmi_events_notify_tbl. */
    }
#ifdef MMI_NOTI_MGR_UT
    scrn_action = action;
#endif /* MMI_NOTI_MGR_UT */
    return result;
}


static srv_prof_ret nmgr_sound_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == SRV_PROF_RET_TRY_TO_RECOVER)
    {
        return SRV_PROF_RET_YES;
    }

    noti_tone_id = NONE_TONE;
	if (need_resume_bk_play == MMI_TRUE)
	{
		mdi_audio_resume_background_play();
		need_resume_bk_play = MMI_FALSE;
	}    
    return SRV_PROF_RET_SUCCESS;
}


#ifdef MOTION_SENSOR_SUPPORT
static void nmgr_motion_turnover_callback(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	srv_sensor_motion_turnover_struct *p_turnover;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    MMI_ASSERT(sensor_type == SRV_SENSOR_MOTION_TURNOVER);
    MMI_ASSERT(g_nmgr_sensor_handle > 0);
    p_turnover = (srv_sensor_motion_turnover_struct *)sensor_data;
    if(p_turnover->direction != SRV_SENSOR_MOTION_TURNOVER_DOWN)
    {
        return;
    }
	mmi_frm_nmgr_unblock_sound_vid_stop(MMI_FRM_NMGR_VIB | MMI_FRM_NMGR_SOUND);
	mmi_frm_nmgr_control_end();

}
#endif

static void control_sound(
        mmi_scenario_id noti_scen_id, 
        srv_prof_tone_enum tone_id, 
        mmi_noti_attr_beha_enum behavior, 
        mmi_nmgr_behavior_enum action, 
        MMI_BOOL display_scrn,
        mmi_frm_nmgr_alert_snd_struct *snd_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret snd_result = SRV_PROF_RET_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (behavior == MMI_NOTI_SND_BEHA_NO_PLAY)
    {
    #ifdef MMI_NOTI_MGR_UT
        play_sound = MMI_FALSE;
        snd_action = action;
        play_sound_id = tone_id;
    #endif /* MMI_NOTI_MGR_UT */
        return;
    }
    else
    {
    #ifdef MMI_NOTI_MGR_UT
        play_sound = MMI_TRUE;
        snd_action = action;
        play_sound_id = tone_id;
    #endif /* MMI_NOTI_MGR_UT */
    }

    
    if (action == MMI_BEHAVIOR_SND_CUSTOM)
    {
        invoke_custom_sound(noti_scen_id);
    }
    else
    {
        MMI_ASSERT(action == MMI_BEHAVIOR_SND_PROFILE || action == MMI_BEHAVIOR_SND_SUBTLE || action == MMI_BEHAVIOR_SND_VIB_THEN_RING);
 
        if (!srv_prof_if_can_ring())
        {
            return;
        }

		if (tone_id == SRV_PROF_TONE_NONE)
		{
			return;
		}
		if (MMI_SCENARIO_ID_REMINDER_OTHER == noti_scen_id)
		{
			mdi_audio_suspend_background_play();
			need_resume_bk_play = MMI_TRUE;
		#ifdef MOTION_SENSOR_SUPPORT
			if(srv_reminder_get_sensor_listen_state(SRV_SENSOR_MOTION_TURNOVER))
			{
				 g_nmgr_sensor_handle = srv_sensor_start_listen(
                                            SRV_SENSOR_MOTION_TURNOVER,
										    NULL,
										    nmgr_motion_turnover_callback,
										    NULL);
			}
		#endif
		}

        if (!nmgr_is_playing_sound())
        {/* If nmgr is playing sound means no sound conflict with MED module currently */
            MMI_BOOL is_video_playing = MMI_FALSE;
            MMI_BOOL is_resource_occuiped = MMI_FALSE;
        #ifdef __MMI_VIDEO_PLAY_SUPPORT__ 
            is_video_playing = (MMI_BOOL)mdi_video_is_playing();
        #endif
        
        #if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
            is_video_playing = (is_video_playing || mdi_mtv_is_playing()) ? MMI_TRUE:MMI_FALSE;
        #endif
            if((snd_info == NULL || (snd_info != NULL && snd_info->sound_type == MMI_NMGR_SND_NONE)) &&
            (!mdi_audio_is_resource_available(srv_prof_play_tone_query_mdi_play_mode(tone_id), NULL)))
                is_resource_occuiped = MMI_TRUE; 

            if ((snd_info != NULL && snd_info->sound_type == MMI_NMGR_SND_FILE_PATH) &&
                !mdi_audio_is_resource_available(MDI_AUDIO_PLAY_FILE, NULL))
                is_resource_occuiped = MMI_TRUE;                             

            if ((snd_info != NULL && (snd_info->sound_type == MMI_NMGR_SND_RAW_DATA_BUFF || 
                snd_info->sound_type == MMI_NMGR_SND_RES_ID)) &&
                !mdi_audio_is_resource_available(MDI_AUDIO_PLAY_STRING, NULL))
                is_resource_occuiped = MMI_TRUE;                                         
            
            if(is_resource_occuiped ||is_video_playing && (display_scrn == MMI_FALSE))    
            {
                snd_result = srv_prof_play_tone_with_id(tone_id, TONE_GENERAL_BEEP, SRV_PROF_RING_TYPE_ONCE, NULL);
                if (snd_result >= 0)  /* DTMF tone */
                {
                    dtmf_id = tone_id;
                }

                return;
            }
        }
        if(snd_info)
        {
            switch(snd_info->sound_type)
            {
                case MMI_NMGR_SND_NONE:
                    snd_result = srv_prof_play_tone(tone_id, nmgr_sound_callback);
                break;              
                case MMI_NMGR_SND_RES_ID:
                    {
                        U8 audio_type = 0, *audio_data = NULL;
                        U32 audio_len = 0;
                        audio_data = get_audio(snd_info->sound.tone_id, &audio_type, &audio_len);
                        snd_result = srv_prof_play_tone_with_audio_data(
                        SRV_PROF_TONE_SMS,
                        audio_data,
                        audio_type,
                        audio_len,
                        SRV_PROF_RING_TYPE_ONCE, nmgr_sound_callback);
                    }
                break;              
                case MMI_NMGR_SND_FILE_PATH:
                    {
                        if(snd_info->sound.file_path!=NULL)
                        {
                            snd_result = srv_prof_play_tone_with_filepath(
                                SRV_PROF_TONE_SMS, 
                                snd_info->sound.file_path,
                                SRV_PROF_RING_TYPE_ONCE,
                                nmgr_sound_callback);
                            mmi_frm_nmgr_mem_free((void *)snd_info->sound.file_path);               
                        }
                    }
                break;
                case MMI_NMGR_SND_RAW_DATA_BUFF:
                    snd_result = srv_prof_play_tone_with_audio_data(
                        SRV_PROF_TONE_SMS,
                        snd_info->sound.raw_data.buff,
                        snd_info->sound.raw_data.format,
                        snd_info->sound.raw_data.size,
                        SRV_PROF_RING_TYPE_ONCE, nmgr_sound_callback);
                break;
            }
        }
        else
        {
            snd_result = srv_prof_play_tone(tone_id, nmgr_sound_callback);
        }
        if (snd_result == SRV_PROF_RET_SUCCESS)
        {/* non-DTMF tone */
        	noti_tone_id = tone_id;
            dtmf_id = NONE_TONE;
        }
        else if (snd_result == SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK)
        {/* DTMF tone */
            dtmf_id = tone_id;
        }
    }
}


static void control_vibration(mmi_scenario_id noti_scen_id, mmi_noti_attr_beha_enum behavior, mmi_nmgr_behavior_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (behavior == MMI_NOTI_VIB_BEHA_NO_USE || 
		(!srv_prof_if_can_vibrate() && (action != MMI_BEHAVIOR_VIB_CUSTOM)) ||
		(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
    {
    #ifdef MMI_NOTI_MGR_UT
        if (behavior == MMI_NOTI_VIB_BEHA_NO_USE)
        {
        	play_vibrator = MMI_FALSE;
        	vib_action = action;
        }
        else
        {
            play_vibrator = MMI_TRUE;
            vib_action = action;
        }
    #endif /* MMI_NOTI_MGR_UT */
        return;
    }
    
    /* The action information is configured in mmi_events_notify_tbl of custom module.*/
    if (action == MMI_BEHAVIOR_VIB_PROFILE)
    {
	#ifndef MMI_NOTI_MGR_UT /* Disable invoking vibrator since queue-full will happen when regression test */
        srv_vibrator_post_req(VIB_PATTERN_1, PLAY_ONCE);
        vib_on = MMI_TRUE;
	#endif
    }
    else if (action == MMI_BEHAVIOR_VIB_ON)
    {
        srv_vibrator_post_req(VIB_PATTERN_1, PLAY_REPEAT);
        vib_on = MMI_TRUE;
    }
    else if (action == MMI_BEHAVIOR_VIB_CUSTOM)
    {
        invoke_custom_vibrator(noti_scen_id);
    }
    else if (action == MMI_BEHAVIOR_VIB_SMS)
    {
	#ifndef MMI_NOTI_MGR_UT
        srv_vibrator_post_req(VIB_PATTERN_3, PLAY_ONCE);
        vib_on = MMI_TRUE;
	#endif
	}
    else
    {
        MMI_ASSERT(action == MMI_BEHAVIOR_VIB_NONE);
    }

#ifdef MMI_NOTI_MGR_UT
    play_vibrator = MMI_TRUE;
    vib_action = action;
#endif /* MMI_NOTI_MGR_UT */
}


static void control_backlight(mmi_noti_attr_beha_enum behavior, mmi_nmgr_behavior_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (behavior == MMI_NOTI_BL_BEHA_NO_PREEMPT)
    {
    #ifdef MMI_NOTI_MGR_UT
        play_backlight = MMI_FALSE;
        bl_action = action;
    #endif /* MMI_NOTI_MGR_UT */
        return;
    }
    /* The action information is configured in mmi_events_notify_tbl of custom module.*/
    if (action == MMI_BEHAVIOR_BL_SHORT_ON)
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }
    else if (action == MMI_BEHAVIOR_BL_ALWAYS_ON)
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    }
    else
    {
        MMI_ASSERT(action == MMI_BEHAVIOR_BL_TWINKLE);
    }
#ifdef MMI_NOTI_MGR_UT
    play_backlight = MMI_TRUE;
    bl_action = action;
#endif /* MMI_NOTI_MGR_UT */
}


static void get_scenario_info(mmi_scenario_id scen_id, mmi_app_scenario_struct *info_struct)
{
	MMI_INIT_SCENARIO_STRUCT(info_struct, scen_id);
	mmi_frm_get_scenario_info(info_struct);
}

static void compare_scenario_and_get_behavior(mmi_scenario_id active_scen_id, mmi_scenario_id noti_scen_id, mmi_app_behavior_struct *behavior)
{
    mmi_app_scenario_struct active_scen, noti_scen;

	get_scenario_info(active_scen_id, &active_scen);
	get_scenario_info(noti_scen_id, &noti_scen);
    get_scenario_behavior_info(&noti_scen, &active_scen, behavior);
}

void mmi_nmgr_vib_then_ring_timer(void *arg)
{
    mmi_nmgr_sound_play_evt_struct *p = (mmi_nmgr_sound_play_evt_struct *)arg;
#ifdef __COSMOS_MMI_PACKAGE__
    StartTimer(MMI_NOTIFICATION_AUDIO_TIMER, MMI_NOTIFY_SOUND_TIME_BOUNDARY, mmi_frm_nmgr_control_end);
#endif    
    control_sound(
        p->noti_scen_id, 
        p->tone_id, 
        p->behavior,
        p->action, 
        p->display_scrn,
        NULL);
    mmi_mfree(arg);
    g_timer_arg = NULL;
}

static mmi_ret nmgr_control_proc(mmi_event_struct *evt)
{
	if (g_enable_nmgr == MMI_FALSE)
	{
		return MMI_RET_OK;
	}
    switch (evt->evt_id)
    {
        case SOUND_PLAY_EVT:
        {
            mmi_nmgr_sound_play_evt_struct *p = (mmi_nmgr_sound_play_evt_struct *)evt;
			srv_prof_alert_type_enum alert_type;
			srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE, (void *)&alert_type);
			StopTimer(MMI_NMGR_VIB_THEN_RING_TIMER);
			if (g_timer_arg != NULL)
			{
				mmi_mfree(g_timer_arg);
				g_timer_arg = NULL;
			}
			if ((SRV_PROF_ALERT_TYPE_VIB_THEN_RING == alert_type) && (p->action == MMI_BEHAVIOR_SND_VIB_THEN_RING))
			{
				mmi_nmgr_sound_play_evt_struct *arg = mmi_malloc(sizeof(mmi_nmgr_sound_play_evt_struct));
				g_timer_arg = arg;
				arg->noti_scen_id = p->noti_scen_id;
				arg->tone_id = p->tone_id;
				arg->behavior = p->behavior;
				arg->action = p->action;
				arg->display_scrn = p->display_scrn; 
				StartTimerEx(MMI_NMGR_VIB_THEN_RING_TIMER, MMI_NMGR_VIB_THEN_RING_DURATION, mmi_nmgr_vib_then_ring_timer, arg);
			}
			else
			{
		    #ifdef __COSMOS_MMI_PACKAGE__
			    StartTimer(MMI_NOTIFICATION_AUDIO_TIMER, MMI_NOTIFY_SOUND_TIME_BOUNDARY, mmi_frm_nmgr_control_end);
		    #endif
                control_sound(
                    p->noti_scen_id, 
                    p->tone_id,
                    p->behavior,
                    p->action,
                    p->display_scrn,
                    &p->snd_info);
			}
            break;
        }

        case VIB_PLAY_EVT:
        {
            mmi_nmgr_vib_play_evt_struct *p = (mmi_nmgr_vib_play_evt_struct *)evt;
            control_vibration(
                p->noti_scen_id,
                p->behavior,
                p->action);
            break;
        }

        case BACKLIGHT_CTRL:
        {
            mmi_nmgr_bl_ctrl_evt_struct *p = (mmi_nmgr_bl_ctrl_evt_struct *)evt;
            control_backlight(
                p->behavior,
                p->action);
            break;
        }          
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  control_notification
 * DESCRIPTION
 *  This is the main function we process notification event: 
 *  1. get notification priority info of notified scenario and current active scenario;
 *  2. compare scenario priority to decide each action of scenario attributes, e.g. screen, tone, vibrator & backlight;
 *  3. control attributes action by previous info;
 * PARAMETERS
 *  notification_type :   [IN] notification type, include popup(common, idle, app), text preview, balloon.
 *  noti_info :   [IN] notification information, help to decide the notification priority and how to display.
 * RETURNS
 *  Return MMI_TRUE if screen could be shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/

static const mmi_events_notify_struct* compare_parse_scenario_action(
        mmi_app_scenario_struct *noti_scen, 
        mmi_app_scenario_struct *active_scen,
        notification_info_struct *noti_info,
        mmi_app_behavior_struct *internal_behavior,
        mmi_attribute_action_struct *action_struct)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_id active_scen_id;
    mmi_nmgr_behavior_enum attri_action;
    const mmi_events_notify_struct *notify_event_info = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    active_scen_id = mmi_frm_get_active_scenario_id();
    get_scenario_info(noti_info->noti_scen_id, noti_scen);
    get_scenario_info(active_scen_id, active_scen);
    compare_scenario_and_get_behavior(active_scen_id, noti_info->noti_scen_id, internal_behavior);

    /* Get notify configuration information by user to decide the action of each attribute. */
    notify_event_info = mmi_nmgr_get_event_notify_info(noti_info->notify_type, active_scen_id);
    MMI_ASSERT(NULL != notify_event_info);
    attri_action = notify_event_info->behavior;
    parse_attri_action(attri_action, action_struct);

    return notify_event_info;
}


//
static MMI_BOOL
control_notification(
        U8 notification_type,
        notification_info_struct *noti_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_app_scenario_struct noti_scen, active_scen;
    mmi_app_behavior_struct internal_behavior;
    MMI_BOOL display_scrn = MMI_FALSE;
    const mmi_events_notify_struct *notify_event_info = NULL;
    mmi_attribute_action_struct action_struct;
    MMI_BOOL is_stop_tone = MMI_FALSE;
    MMI_BOOL is_stop_vib  = MMI_FALSE;
#ifdef __MMI_NCENTER_SUPPORT__
    MMI_BOOL is_stop_text_preview  = MMI_FALSE;
#endif	
    #ifdef __MMI_NSS_SUPPORT__
    U16 notification_setting_value = 0;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__ 
    if (mmi_dmui_is_phone_lock() && (notification_type == MMI_NOTIFY_COMM_POPUP))
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_DISBALE_NMGR_BY_DM_LOCK);
        return MMI_FALSE;
    }
#endif
    if (mmi_frm_has_no_scenario_been_started() == MMI_TRUE)
    {
        return MMI_FALSE;
    }
#if defined(__OLED_BW_MMI__)||defined(CUSTOMER_NAME_TOUR)
	// baiwenlin 20130903  ÆÁ±Îµ¯³ö¿ò
	return MMI_FALSE;
#endif /* __OLED_BW_MMI__ */
    if (g_enable_nmgr == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    compare_parse_scenario_action(&noti_scen, &active_scen, noti_info, &internal_behavior, &action_struct);

#ifdef __MMI_NCENTER_SUPPORT__
    if( active_scen.scrn_priority >= MMI_SCEN_SCRN_PRIO_HIGH)
    {
        is_stop_text_preview = MMI_TRUE;
    }
#endif

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
    if (notification_type == MMI_NOTIFY_BY_IDLE)
    {/* App handle screen work flow, may add extra info, like setting key, scrn handler */
        MMI_ASSERT(noti_info->scrn_func_ptr == NULL && noti_info->arg == NULL);
        /* Won't check screen behavior since this kind of screen will be displayed when goback to idle */
        display_scrn = control_idle_screen(noti_info->noti_scen_id, noti_info->notify_type, noti_scen.scrn_priority, noti_info->string, internal_behavior.scrn_behavior);
    }
    else 
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/    
    if (notification_type == MMI_NOTIFY_BY_APP)
    {/* App may not display screen for some special case */
        display_scrn = control_app_screen(
                                    noti_info->noti_scen_id, 
                                    noti_scen.scrn_priority, 
                                    internal_behavior.scrn_behavior, 
                                    noti_info->scrn_func_ptr, 
                                    noti_info->arg, 
                                    action_struct.scrn_action, 
                                    NULL,
                                    noti_info->notify_type);
    }
    else if (notification_type == MMI_NOTIFY_COMM_POPUP)
    {
        display_scrn = control_popup_screen(noti_info->noti_scen_id, noti_info->string, noti_info->notify_type, internal_behavior.scrn_behavior, action_struct.scrn_action);
    }
    else if (notification_type == MMI_NOTIFY_SUBLCD)
    {
       
    }
    else if (notification_type == MMI_NOTIFY_PREVIEW)
    {
    #ifdef __MMI_NCENTER_SUPPORT__
        control_preview(noti_info->notify_type, noti_info->notification, NULL, is_stop_text_preview);
        if (noti_info->notification->option & MMI_FRM_NMGR_DISABLE_TONE)
        {
            is_stop_tone = MMI_TRUE;
        }
        if (noti_info->notification->option & MMI_FRM_NMGR_DISABLE_VIB)
        {
            is_stop_vib = MMI_TRUE;
        }
    #endif
    }
    else if (notification_type == MMI_NOTIFY_BALLOON)
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        display_scrn = control_balloon(noti_info->notify_type, noti_info->balloon_type, noti_info->string, NULL);
    #endif
    }
    else if (notification_type == MMI_NOTIFY_ALERT)
    {
        /*Show notification by its alert type*/
        if (noti_info->alert_info->behavior_mask == ALERT_TYPE_STATUS_BAR)
        {/*Show status bar (text preview or balloon)*/
            if(noti_info->alert_info->status_bar_para.status_bar_type == MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE)
            {/*text preview*/
                #ifdef __MMI_NCENTER_SUPPORT__
                mmi_frm_notification_para_struct temp_preview;
                temp_preview.text = noti_info->alert_info->status_bar_para.display_string;
                temp_preview.option = noti_info->alert_info->alert_option;
                control_preview(noti_info->notify_type, &temp_preview, noti_info->alert_info, is_stop_text_preview);               
                #endif
            }
            
            if(noti_info->alert_info->status_bar_para.status_bar_type == MMI_FRM_NMGR_ALERT_ST_BALLOON_TYPE)   
            {/*balloon*/
                #ifdef __COSMOS_MMI_PACKAGE__
                display_scrn = control_balloon(noti_info->notify_type, MMI_NMGR_BALLOON_TYPE_INFO,
                                (WCHAR *)noti_info->alert_info->status_bar_para.display_string, noti_info->alert_info);
                #endif
            }                
        }

        if(noti_info->alert_info->behavior_mask == ALERT_TYPE_POPUP)
        { /*Show popup*/         
            mmi_noti_scrn_func_ptr popup_scrn_entry = nmgr_alert_general_popup;             
            void *popup_scrn_para = noti_info->alert_info;    
            
            display_scrn = control_app_screen(noti_info->noti_scen_id, 
                            noti_scen.scrn_priority, 
                            internal_behavior.scrn_behavior, 
                            popup_scrn_entry, 
                            popup_scrn_para, 
                            action_struct.scrn_action,
                            noti_info->alert_info,
                            noti_info->notify_type);
        }

         /*Extract option for sound and vibration usage*/
         if ( noti_info->alert_info->alert_option & MMI_FRM_NMGR_DISABLE_TONE)
         {
             is_stop_tone = MMI_TRUE;
         }
         if (noti_info->alert_info->alert_option & MMI_FRM_NMGR_DISABLE_VIB)
         {
             is_stop_vib = MMI_TRUE;
         }

        /*Extract the sound setting from NSS*/
        #ifdef __MMI_NSS_SUPPORT__
        mmi_srv_nss_get_setting(noti_info->alert_info->app_id, NSS_SETTING_SOUND, &notification_setting_value);
        if(notification_setting_value == SETTING_OFF)
        {
            is_stop_tone = MMI_TRUE;
        }
        #endif

        /*According to UE design, we will show status bar icon even the NSS is none or popup*/
        if (noti_info->alert_info->behavior_mask == ALERT_TYPE_POPUP || 
        noti_info->alert_info->behavior_mask == ALERT_TYPE_NONE)
        {            
            control_status_icon(noti_info->alert_info->app_id,
            noti_info->alert_info->alert_option, 
            noti_info->alert_info->status_bar_icon_para.icon_id
            );                        
        }        
    }
    else
    {
        MMI_ASSERT(0);
    }

#ifdef __MMI_SUBLCD__
    control_sublcd(noti_info->noti_scen_id, internal_behavior.scrn_behavior);
#endif


    if (!nmgr_is_in_defer_process() && !only_control_scrn)
    {/* These three attribute should be invoked immediately! */
        /* compare scenario again */
       
        notify_event_info = compare_parse_scenario_action(&noti_scen, &active_scen, noti_info, &internal_behavior, &action_struct);
        
        if (notification_type != MMI_NOTIFY_BALLOON)
        {
            if (is_stop_tone == MMI_FALSE)
            {
                mmi_nmgr_sound_play_evt_struct sound_event;
                MMI_FRM_INIT_EVENT(&sound_event, SOUND_PLAY_EVT);
                
                sound_event.noti_scen_id = noti_info->noti_scen_id;
                sound_event.tone_id = notify_event_info->tone_id;
                sound_event.behavior = internal_behavior.snd_behavior;
                sound_event.action = action_struct.snd_action;
                sound_event.display_scrn = display_scrn;
                if(noti_info->alert_info!=NULL)
                {
                    memcpy(&sound_event.snd_info, &noti_info->alert_info->snd_para, sizeof(mmi_frm_nmgr_alert_snd_struct));
                    if(sound_event.snd_info.sound_type == MMI_NMGR_SND_FILE_PATH)
                    {
                        sound_event.snd_info.sound.file_path = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(
                            noti_info->alert_info->snd_para.sound.file_path,MMI_MAX_FILE_NAME_LEN);
                    }
                }
	#ifdef __IV_TTS__
	mmi_nmgr_ivtts_save_evt( sound_event );
	if ( ivtts_app_in_msg_notify_is_correct_type(noti_info->notify_type) == 1)
	{
		if ( NPR_TTS_NeedReadRecvSms())
		{
			if(new_msg_recv_read())
				MMI_FRM_POST_EVENT(&sound_event, nmgr_control_proc, NULL); 
		}
		else
		{
			MMI_FRM_POST_EVENT(&sound_event, nmgr_control_proc, NULL); 
		}
	}
	else
	{
			MMI_FRM_POST_EVENT(&sound_event, nmgr_control_proc, NULL); 
	}
	#else
			MMI_FRM_POST_EVENT(&sound_event, nmgr_control_proc, NULL);                
	#endif

            }
            if (is_stop_vib == MMI_FALSE)
            {
                mmi_nmgr_vib_play_evt_struct vib_event;
                MMI_FRM_INIT_EVENT(&vib_event, VIB_PLAY_EVT);
                vib_event.noti_scen_id = noti_info->noti_scen_id;
                vib_event.behavior = internal_behavior.vib_behavior;
                vib_event.action = action_struct.vib_action;
                MMI_FRM_POST_EVENT(&vib_event, nmgr_control_proc, NULL);
                
            }
        }
        if (!(notification_type == MMI_NOTIFY_BALLOON && display_scrn == MMI_FALSE))
        {
            mmi_nmgr_bl_ctrl_evt_struct bl_event;
            MMI_FRM_INIT_EVENT(&bl_event,BACKLIGHT_CTRL);
            bl_event.action = action_struct.bl_action;
            bl_event.behavior = internal_behavior.bl_behavior;
            MMI_FRM_POST_EVENT(&bl_event, nmgr_control_proc, NULL);
        }
    }
    return display_scrn;
}


/*****************************************************************************
 * FUNCTION
 *  add_notify_defer_notification
 * DESCRIPTION
 *  internal function to add defer notification to queue
 * PARAMETERS
 *  scen_id     [IN] scenario id to identify this defer notification
 *  arg         [IN] argument
 * RETURNS
 *  void
 *****************************************************************************/
static void add_notify_defer_notification(
                    mmi_scenario_id scen_id, 
                    mmi_scen_attr_prio_enum scrn_priority, 
                    mmi_noti_scrn_func_ptr scrn_func_ptr, 
                    void *arg, 
                    mmi_frm_nmgr_alert_struct *alert_info,
                    mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 idx = mmi_notify_defer_info_cntx.used;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(scen_id > MMI_SCENARIO_ID_INVALID);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_NMGR_ADD_DEFER_EVT, scen_id, scrn_func_ptr, arg, scrn_priority);

    /*For alert : when we met the duplicate popup, remove the old one and keep the new one*/
    /*For others(original) : when we met the duplicate popup, remove the new one and keep the old one*/
    if (alert_info==NULL && mmi_frm_nmgr_is_scenario_deferred(scen_id, scrn_func_ptr, arg))
    {
        return;
    }
    
    if(alert_info!=NULL)
    {        
        /*Remove duplicate popup by the app_id and event_type*/
        del_notify_defer_notification(alert_info->app_id, alert_info->popup_para.popup_type, 
                                                        event_type, MMI_SCENARIO_ID_GENERAL,0,0, MMI_TRUE);
        idx = mmi_notify_defer_info_cntx.used;
    }

    /* make sure defer table is enough */    
    if (idx >= MMI_DEFER_NOTIFICATION_NUM)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_NMGR_DEFER_QUEUE_FULL);
        return;
    }

    if(alert_info!=NULL)
    {
        /*Store popup info to the defer queue*/     
        memcpy(&mmi_notify_defer_info_cntx.data[idx].popup_info, alert_info, sizeof(mmi_frm_nmgr_alert_struct));
        /*Save display string*/
        mmi_notify_defer_info_cntx.data[idx].popup_info.popup_para.popup_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(             
            (WCHAR *)alert_info->popup_para.popup_string,
            MMI_FRM_NMGR_POPUP_TEXT_CHAR_COUNT);
        /*Save button string*/        
        mmi_notify_defer_info_cntx.data[idx].popup_info.popup_para.popup_button_string = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(             
            (WCHAR *)alert_info->popup_para.popup_button_string,
            MMI_FRM_NMGR_BUTTON_TEXT_CHAR_COUNT); 
        /*Save image file path if needed*/
        if(mmi_notify_defer_info_cntx.data[idx].popup_info.popup_para.image_type == MMI_NMGR_IMG_FILE_PATH)
        {
            mmi_notify_defer_info_cntx.data[idx].popup_info.popup_para.image.file_path = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal( 
            alert_info->popup_para.image.file_path,
            MMI_MAX_FILE_NAME_LEN
            );
        }
        /*Save user_data if needed*/
        if(alert_info->app_proc_para.data_size > 0)
        {                
            mmi_notify_defer_info_cntx.data[idx].popup_info.app_proc_para.user_data = mmi_frm_alloc_and_copy_data_to_nmgr_buff_internal(
            alert_info->app_proc_para.user_data,
            alert_info->app_proc_para.data_size
            );
        }
        /*Redirect arg to popup_info*/
        mmi_notify_defer_info_cntx.data[idx].arg = (void *)&mmi_notify_defer_info_cntx.data[idx].popup_info;

    }
    else
    {
        memset(&mmi_notify_defer_info_cntx.data[idx].popup_info, 0, sizeof(mmi_notify_defer_info_cntx.data[idx].popup_info));
        mmi_notify_defer_info_cntx.data[idx].arg = arg;
    }
    
    mmi_notify_defer_info_cntx.data[idx].scen_id = scen_id;
    mmi_notify_defer_info_cntx.data[idx].scrn_attr_prio = scrn_priority;
    mmi_notify_defer_info_cntx.data[idx].scrn_entry_cb = scrn_func_ptr;
    mmi_notify_defer_info_cntx.used++;
}


#if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
static mmi_defer_item_struct *get_defer_item_id_and_cb(mmi_scenario_id scen_id, mmi_noti_scrn_func_ptr scrn_entry_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (idx = 0; idx < mmi_notify_defer_info_cntx.used; idx++)
    {
        if (mmi_notify_defer_info_cntx.data[idx].scen_id == scen_id &&
            mmi_notify_defer_info_cntx.data[idx].scrn_entry_cb == scrn_entry_func)
        {
            return &mmi_notify_defer_info_cntx.data[idx];
        }
    }
    return NULL;
}

#endif // (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__) 

/*****************************************************************************
 * FUNCTION
 *  del_defer_notification
 * DESCRIPTION
 *  internal function to delete defer notification in queue
 * PARAMETERS
 *  scen_id      [IN] scenario id to identify which defer notification to del
 * RETURNS
 *  void
 *****************************************************************************/
static void del_notify_defer_notification(
    MMI_ID app_id,
    U16 popup_type,
    mmi_event_notify_enum event_type,
    mmi_scenario_id scen_id, 
    mmi_noti_scrn_func_ptr scrn_entry_func, 
    void *arg,
    MMI_BOOL is_free_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, idx_to_clear, data_to_move, data_to_refine;
    MMI_BOOL is_need_to_remove = MMI_FALSE, is_alert_need_to_remove = MMI_FALSE;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(scen_id > MMI_SCENARIO_ID_INVALID);

    if(mmi_notify_defer_info_cntx.used == 0)
        return;

    for (i = 0; i < MMI_DEFER_NOTIFICATION_NUM; i++)
    {
        is_alert_need_to_remove = MMI_FALSE;
        /*Del with alert info, remove all nodes that satisfy the condition*/
        if(app_id != 0 && mmi_notify_defer_info_cntx.data[i].popup_info.app_id == app_id &&
            mmi_notify_defer_info_cntx.data[i].popup_info.event_type== event_type &&
            (mmi_notify_defer_info_cntx.data[i].popup_info.popup_para.popup_type == popup_type || 
            popup_type == MMI_FRM_NMGR_ALERT_POPUP_ALL_TYPE))
        {
            is_alert_need_to_remove = MMI_TRUE;
        }
        /*Del wo alert info, remove the first nodes that satisfy the condition*/
        if (app_id == 0 && mmi_notify_defer_info_cntx.data[i].scen_id == scen_id &&
            mmi_notify_defer_info_cntx.data[i].scrn_entry_cb == scrn_entry_func &&
            mmi_notify_defer_info_cntx.data[i].arg == arg)
        {
            is_need_to_remove = MMI_TRUE;    
        }

        if(is_need_to_remove == MMI_TRUE || is_alert_need_to_remove == MMI_TRUE)    
        {
            mmi_event_struct evt;    
            MMI_ASSERT(mmi_notify_defer_info_cntx.used > 0);
            mmi_notify_defer_info_cntx.used--;
            data_to_move = mmi_notify_defer_info_cntx.used - i;

            if(is_alert_need_to_remove)
            {
                /*If remove with alert info, we need to free the temp buffer here*/
                /*free popup string*/
                if(mmi_notify_defer_info_cntx.data[i].popup_info.popup_para.popup_string!=NULL)
                {
                    mmi_frm_nmgr_mem_free((void *)mmi_notify_defer_info_cntx.data[i].popup_info.popup_para.popup_string);               
                }
                /*free buttoon string*/
                if(mmi_notify_defer_info_cntx.data[i].popup_info.popup_para.popup_button_string!=NULL)
                {
                    mmi_frm_nmgr_mem_free((void *)mmi_notify_defer_info_cntx.data[i].popup_info.popup_para.popup_button_string);
                }               
                /*free image file path*/
                if(mmi_notify_defer_info_cntx.data[i].popup_info.popup_para.image_type == MMI_NMGR_IMG_FILE_PATH
                    && mmi_notify_defer_info_cntx.data[i].popup_info.popup_para.image.file_path != NULL)
                {
                    mmi_frm_nmgr_mem_free(mmi_notify_defer_info_cntx.data[i].popup_info.popup_para.image.file_path);
                    mmi_notify_defer_info_cntx.data[i].popup_info.popup_para.image.file_path = NULL;
                }               
                /*Cancel the deferred popup message*/
                if(mmi_notify_defer_info_cntx.data[i].popup_info.app_proc_para.scrn_group_proc && is_free_user_data)
                {        
                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_ALERT_END);
                    MMI_FRM_SEND_EVENT(
                            &evt, 
                            mmi_notify_defer_info_cntx.data[i].popup_info.app_proc_para.scrn_group_proc, 
                            mmi_notify_defer_info_cntx.data[i].popup_info.app_proc_para.user_data);   
                }
                /*free user data*/
                if(mmi_notify_defer_info_cntx.data[i].popup_info.app_proc_para.user_data!=NULL && 
                       mmi_notify_defer_info_cntx.data[i].popup_info.app_proc_para.data_size > 0 )
                {
                    mmi_frm_nmgr_mem_free(mmi_notify_defer_info_cntx.data[i].popup_info.app_proc_para.user_data);
                    mmi_notify_defer_info_cntx.data[i].popup_info.app_proc_para.user_data = NULL;
                }
            }
            /* there's data behind it */
            if (data_to_move > 0)
            {                                
                /* replace it with data behind */
                memmove(&mmi_notify_defer_info_cntx.data[i], 
                    &mmi_notify_defer_info_cntx.data[i + 1],
                    sizeof(mmi_defer_item_struct) * data_to_move);
                /* refill the arg with the appropriate parameter*/
                for(data_to_refine = 0; data_to_refine < data_to_move; data_to_refine ++)
                {
					 if(mmi_notify_defer_info_cntx.data[i+data_to_refine].arg == &mmi_notify_defer_info_cntx.data[i+data_to_refine+1].popup_info)
                    {
                        mmi_notify_defer_info_cntx.data[i+data_to_refine].arg = &mmi_notify_defer_info_cntx.data[i+data_to_refine].popup_info;
                    }
                }

                idx_to_clear = mmi_notify_defer_info_cntx.used;   /* last data should be cleared */
            }
            else
            {
                /* it's last one, just remove it */
                idx_to_clear = i;
            }

            memset(&mmi_notify_defer_info_cntx.data[idx_to_clear], 0, sizeof(mmi_defer_item_struct));
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_NMGR_DEL_DEFER_EVT_OK, scen_id, scrn_entry_func, arg);
            /*if remove with alert info, we will not stop the travse until the end of the list*/
            if(is_need_to_remove)
            break;            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_notify_defer_notification
 * DESCRIPTION
 *  Get highest priority scenario in defer queue.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_defer_item_struct *get_notify_defer_notification(mmi_scen_attr_prio_enum *scrn_prio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scen_attr_prio_enum max_scrn_prio = MMI_SCEN_PRIO_NONE;
    U8 i;
	mmi_defer_item_struct *found_item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_notify_defer_info_cntx.used; i++)
    {
        if (max_scrn_prio < mmi_notify_defer_info_cntx.data[i].scrn_attr_prio)
        {
            max_scrn_prio = mmi_notify_defer_info_cntx.data[i].scrn_attr_prio;
			found_item = &mmi_notify_defer_info_cntx.data[i];
        }
        if (max_scrn_prio == MMI_SCEN_SCRN_PRIO_HIGH)
        {/* Accelerate search speed, since only media & high notification could be deferred now. */
            break;
        }
    }
    *scrn_prio = max_scrn_prio;
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_NMGR_GET_MAX_PRIO_DEFER_EVT, mmi_notify_defer_info_cntx.data[i].scen_id, i, max_scrn_prio);
    return found_item;
}


/*****************************************************************************
 * FUNCTION
 *  should_defer_notified_event
 * DESCRIPTION
 *  If notified event's priority is not higher than the deferred events, we put it 
 *  into defered queue to make sure the same priority deferred events will be processed "sequently"
 *  and the higher priority deferred events could be processed "earlyer".
 * PARAMETERS
 *  notify_scrn_prio    [IN]    screen priority of notified event
 * RETURNS
 *  Return MMI_TRUE if should defer, otherwise return MMI_FALSE;
 *****************************************************************************/
static MMI_BOOL should_defer_notified_event(mmi_scen_attr_prio_enum notify_scrn_prio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_notify_defer_info_cntx.used; i++)
    {
        if (notify_scrn_prio <= mmi_notify_defer_info_cntx.data[i].scrn_attr_prio)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  invoke_notify_defer_notification
 * DESCRIPTION
 *  Invoke defer notification in queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret invoke_notify_defer_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_defer_item_struct *defer_item_ptr;
    mmi_scen_attr_prio_enum defer_scen_scrn_prio;
    mmi_app_scenario_struct active_scen;
    mmi_ret result = MMI_RET_ERR;
 
#if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)   
    MMI_RET force_defer = MMI_RET_OK;
    mmi_nmgr_defer_check_evt_struct evt;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!nmgr_is_defer_enable())
        return result;

    StopTimer(MMI_NOTIFICATION_SERVICE_TIMER);
    is_in_defer_process = MMI_TRUE;
    if (mmi_frm_nmgr_get_defer_notification_count() > 0)
    {
        defer_item_ptr = get_notify_defer_notification(&defer_scen_scrn_prio);
        MMI_ASSERT(NULL != defer_item_ptr);
        get_scenario_info(mmi_frm_get_active_scenario_id(), &active_scen);
    #if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_FORCE_DEFER_QUERY);
        evt.active_scenario_id = mmi_frm_get_active_scenario_id();
        evt.notify_scenario_id = defer_item_ptr->scen_id;
        force_defer = MMI_FRM_CB_EMIT_EVENT(&evt);
    #endif
        if (
            #if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
            (force_defer != MMI_RET_FORCE_DEFER) && 
            #endif
            (defer_scen_scrn_prio >= active_scen.scrn_priority))
        {
            mmi_defer_item_struct info;
            info = *defer_item_ptr;
            MMI_ASSERT(NULL != defer_item_ptr->scrn_entry_cb);
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_NMGR_INVOKE_DEFER_EVENT_SCREEN, defer_item_ptr->scen_id, defer_item_ptr->scrn_entry_cb, defer_item_ptr->arg);            
            defer_item_ptr = &info;
            
            defer_item_ptr->scrn_entry_cb(defer_item_ptr->scen_id, defer_item_ptr->arg);           
            
            del_notify_defer_notification(defer_item_ptr->popup_info.app_id, 
                defer_item_ptr->popup_info.popup_para.popup_type,
                defer_item_ptr->popup_info.event_type,
                defer_item_ptr->scen_id, 
                defer_item_ptr->scrn_entry_cb, 
                defer_item_ptr->arg, MMI_FALSE);

         #ifdef __MMI_SUBLCD__
            emit_sublcd_noftify(defer_item_ptr->scen_id);
         #endif /* __MMI_SUBLCD__ */
            invoke_custom_sound(defer_item_ptr->scen_id);

            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
            {
                invoke_custom_vibrator(defer_item_ptr->scen_id);
            }

            if (mmi_frm_nmgr_get_defer_notification_count() > 0)
            {
                StartTimer(MMI_NOTIFICATION_SERVICE_TIMER, 
                    MMI_NOTIFY_INVOKE_TIME, 
                    (FuncPtr)invoke_notify_defer_notification);
            }

            result = MMI_RET_OK;
        }
    }

    is_in_defer_process = MMI_FALSE;
    return result;
}


#ifdef __MMI_SUBLCD__

/*****************************************************************************
 * FUNCTION
 *  emit_sublcd_noftify
 * DESCRIPTION
 *  emit sub lcd event
 * PARAMETERS
 *  scenario_id   : [IN] scenario id
 * RETURNS
 *  void
 *****************************************************************************/
static void emit_sublcd_noftify(mmi_scenario_id  scenario_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_sublcd_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_SUBLCD_NOTIFY);
    evt.scenario_id = scenario_id;
    MMI_FRM_CB_EMIT_EVENT(&evt);
}


static U8 mmi_ucm_display_buf[(SRV_UCM_MAX_DISP_NAME_LEN + 1) * ENCODING_LENGTH];

static void mmi_sublcd_outgoing_call_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* display_name = NULL;
    srv_ucm_call_info_struct call_info;
#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)
    S32 buffer_char_num = 0;
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    srv_ucm_index_info_struct index_list[SRV_UCM_MAX_CALL];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get outgoing call info */
    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, index_list) != 1)
    {
        MMI_ASSERT(0);
    }

    srv_ucm_query_call_data(index_list[0], &call_info);
    display_name = (U16*)call_info.remote_info.disp_name;
    
#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)
    buffer_char_num = sizeof(mmi_ucm_display_buf) / ENCODING_LENGTH;

    memset(mmi_ucm_display_buf, 0x00, sizeof(mmi_ucm_display_buf));

    if(srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE, MMI_FALSE, NULL) > 0)
    {
       mmi_ucs2ncpy((CHAR*)mmi_ucm_display_buf, (CHAR*)GetString(STR_ID_UCM_VOICE_CALLING_SIM1), (buffer_char_num - 1));
    }    
    else if(srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM2, MMI_FALSE, NULL) > 0)
    {
       mmi_ucs2ncpy((CHAR*)mmi_ucm_display_buf,(CHAR*)GetString(STR_ID_UCM_VOICE_CALLING_SIM2), (buffer_char_num - 1));    
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if(srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM3, MMI_FALSE, NULL) > 0)
    {
       mmi_ucs2ncpy((CHAR*)mmi_ucm_display_buf,(CHAR*)GetString(STR_ID_UCM_VOICE_CALLING_SIM3), (buffer_char_num - 1));    
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if(srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM4, MMI_FALSE, NULL) > 0)
    {
       mmi_ucs2ncpy((CHAR*)mmi_ucm_display_buf,(CHAR*)GetString(STR_ID_UCM_VOICE_CALLING_SIM4), (buffer_char_num - 1));    
    }
#endif
#endif
    if (mmi_ucs2strlen((CHAR*)mmi_ucm_display_buf) < buffer_char_num)
    {    
        mmi_ucs2cat((CHAR *)mmi_ucm_display_buf, (const CHAR *)L" ");
		mmi_ucs2ncat((CHAR*)mmi_ucm_display_buf,
                    (CHAR*)display_name, 
                    (U32)(buffer_char_num - mmi_ucs2strlen((CHAR*)mmi_ucm_display_buf) - 1));
    }
    
    display_name = (U16*)mmi_ucm_display_buf;
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    ExecSubLCDCurrExitHandler();
    ShowCategory311Screen((U8*)display_name, IMG_ID_UCM_SUBLCD_CALLING, NULL);

    SetSubLCDExitHandler(mmi_sublcd_outgoing_call_exit);
}


static void mmi_sublcd_outgoing_call_exit(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SubLCDHistory.entryFuncPtr = mmi_sublcd_outgoing_call_entry;
    AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_UCM_OUTGOING_CALL_SUBLCD);

}


static void mmi_sublcd_incoming_call_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    U16* display_name = NULL;
#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)
    S32 buffer_char_num = 0;
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    srv_ucm_call_info_struct call_info;
    srv_ucm_index_info_struct index_list[SRV_UCM_MAX_CALL];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* get outgoing call info */
	if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, index_list) != 1)
	{
		MMI_ASSERT(0);
	}

	srv_ucm_query_call_data(index_list[0], &call_info);
    display_name = (U16*)call_info.remote_info.disp_name;
#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)
    buffer_char_num = sizeof(mmi_ucm_display_buf) / ENCODING_LENGTH;

    memset(mmi_ucm_display_buf, 0x00, sizeof(mmi_ucm_display_buf));
    
    if(srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE, MMI_FALSE, NULL) > 0)
    {
       mmi_ucs2ncpy((CHAR*)mmi_ucm_display_buf, (CHAR*)GetString(STR_ID_UCM_VOICE_INCOMING_SIM1), (buffer_char_num - 1));
    }
    else if(srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM2, MMI_FALSE, NULL) > 0)
    {
       mmi_ucs2ncpy((CHAR*)mmi_ucm_display_buf,(CHAR*)GetString(STR_ID_UCM_VOICE_INCOMING_SIM2), (buffer_char_num - 1));	
    }
#if (MMI_MAX_SIM_NUM >= 3)    
    else if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM3, MMI_FALSE, NULL) > 0)
    {
        mmi_ucs2ncpy((CHAR*)mmi_ucm_display_buf,(CHAR*)GetString(STR_ID_UCM_VOICE_INCOMING_SIM3), (buffer_char_num - 1));
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_SIM4, MMI_FALSE, NULL) > 0)
    {
        mmi_ucs2ncpy((CHAR*)mmi_ucm_display_buf,(CHAR*)GetString(STR_ID_UCM_VOICE_INCOMING_SIM4), (buffer_char_num - 1));
    }
#endif
#endif
    if (mmi_ucs2strlen((CHAR*)mmi_ucm_display_buf) < buffer_char_num)
    {   
        mmi_ucs2cat((CHAR *)mmi_ucm_display_buf, (const CHAR *)L" ");
        mmi_ucs2ncat((CHAR*)mmi_ucm_display_buf,
                    (CHAR*)display_name, 
                    (U32)(buffer_char_num - mmi_ucs2strlen((CHAR*)mmi_ucm_display_buf) - 1));
    }
    
    display_name = (U16*)mmi_ucm_display_buf;
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    ExecSubLCDCurrExitHandler();
    ShowCategory311Screen((U8*)display_name, IMG_ID_UCM_SUBLCD_INCOMING_CALL, NULL);

    SetSubLCDExitHandler(mmi_nmgr_sublcd_exit_incoming_call);
}


void mmi_nmgr_sublcd_exit_incoming_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    SubLCDHistory.entryFuncPtr = mmi_sublcd_incoming_call_entry;
    AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_UCM_INCOMING_CALL_SUBLCD);
}


/*****************************************************************************
* FUNCTION
*  mmi_sublcd_alarm_entry
* DESCRIPTION
*  Display sub-lcd screen when alarm expires.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_sublcd_alarm_entry(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     ExecSubLCDCurrExitHandler();
     ShowCategory304Screen(IMG_ID_ALARM_ANIMATION_INDICATION_SUBLCD, 0);
     SetSubLCDExitHandler(mmi_sulcd_alarm_exit);
}


/*****************************************************************************
* FUNCTION
*  mmi_sulcd_alarm_exit
* DESCRIPTION
*  Exit function of sub lcd alarm
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_sulcd_alarm_exit(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     SubLCDHistoryNode SubLCDHistory;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     SubLCDHistory.entryFuncPtr = mmi_sublcd_alarm_entry;
     AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_ALARM_SUBLCD_IND);

}

/*****************************************************************************
* FUNCTION
*  mmi_nmgr_sub_lcd_scenario_hdlr
* DESCRIPTION
*  sublcd scenario event handler
* PARAMETERS
*  evt          : [IN] event structure
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static mmi_ret mmi_nmgr_sub_lcd_scenario_hdlr(mmi_event_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_sublcd_evt_struct *evt = (mmi_nmgr_sublcd_evt_struct *)p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_NMGR_SUBLCD_NOTIFY);
    switch (evt->scenario_id)
    {
        case MMI_SCENARIO_ID_REMINDER_ALARM:
		case MMI_SCENARIO_ID_REMINDER_AZAAN:
        case MMI_SCENARIO_ID_REMINDER_OTHER:
            ForceSubLCDScreen(mmi_sublcd_alarm_entry);
            break;
        default:
            break;
            
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_nmgr_sub_lcd_scenario_hdlr
* DESCRIPTION
*  sublcd scenario event handler
* PARAMETERS
*  evt          : [IN] event structure
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static mmi_ret mmi_sublcd_scenario_end_hdlr(mmi_event_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_end_evt_struct *evt = (mmi_scenario_end_evt_struct *)p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SCENARIO_END);
    switch (evt->scenario_id)
    {
        case MMI_SCENARIO_ID_REMINDER_ALARM:
		case MMI_SCENARIO_ID_REMINDER_AZAAN:
        case MMI_SCENARIO_ID_REMINDER_OTHER:
            if (mmi_frm_is_in_backward_scenario())
            {
                if (GetCurrSubLCDScreenEntryFunc() == mmi_sublcd_alarm_entry)
                {
                    GoBackSubLCDHistory();
                }
			    else
                {
                    DeleteSubLCDScreen(SCR_ID_ALARM_SUBLCD_IND);
                }
            }
            
            break;
        default:
            break;
            
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_sublcd_clam_open_hdlr
* DESCRIPTION
*  sublcd scenario event handler
* PARAMETERS
*  evt          : [IN] event structure
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static mmi_ret mmi_sublcd_clam_open_hdlr(mmi_event_struct *evt)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_GPIO_CLAM_OPEN);
    if (GetCurrSubLCDScreenEntryFunc() == mmi_sublcd_alarm_entry ||
        GetCurrSubLCDScreenEntryFunc() == mmi_sublcd_incoming_call_entry ||
        GetCurrSubLCDScreenEntryFunc() == mmi_sublcd_outgoing_call_entry)
    {
        mmi_idle_sublcd_display();
    }
	return MMI_RET_OK;
}


static mmi_ret mmi_sublcd_clam_close_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_earphone_is_plug_in() && srv_ucm_is_incoming_call())
    {
        ForceSubLCDScreen(mmi_sublcd_incoming_call_entry);
    }
	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_sublcd_ucm_release_hdlr
* DESCRIPTION
*  ucm release sublcd handler
* PARAMETERS
*  evt          : [IN] ucm event data
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static void mmi_sublcd_ucm_release_hdlr(srv_ucm_release_ind_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackSubLCDHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_sublcd_ucm_incoming_call_hdlr
* DESCRIPTION
*  incoming call sublcd handler
* PARAMETERS
*  evt          : [IN] ucm event data
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static void mmi_sublcd_ucm_incoming_call_hdlr(srv_ucm_incoming_call_ind_struct* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ForceSubLCDScreen(mmi_sublcd_incoming_call_entry);
}

static void mmi_sublcd_ucm_outgoing_call_hdlr(srv_ucm_outgoing_call_ind_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ForceSubLCDScreen(mmi_sublcd_outgoing_call_entry);    
}

static void close_call_related_screen(void)
{
    if (srv_ucm_is_incoming_call() == MMI_FALSE)
    {
        if (GetCurrSubLCDScreenEntryFunc() == mmi_sublcd_incoming_call_entry)
        {
            GoBackSubLCDHistory();
        }
        else
        {
            DeleteSubLCDScreen(SCR_ID_UCM_INCOMING_CALL_SUBLCD);
        }                
    }
    if (srv_ucm_is_outgoing_call() == MMI_FALSE)
    {
        if (GetCurrSubLCDScreenEntryFunc() == mmi_sublcd_outgoing_call_entry)
        {
            GoBackSubLCDHistory();
        }
        else
        {
            DeleteSubLCDScreen(SCR_ID_UCM_OUTGOING_CALL_SUBLCD);
        }                 
    }
}

static mmi_ret mmi_sublcd_ucm_action_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_notify_evt_struct *ind = (srv_ucm_act_notify_evt_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ind->act_op)
    {
        case SRV_UCM_ACCEPT_ACT:
            close_call_related_screen();
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_sublcd_ucm_ind
* DESCRIPTION
*  sub lcd ucm event handler
* PARAMETERS
*  evt          : [IN] ucm event
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
static mmi_ret mmi_sublcd_ucm_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *) evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ind->ind_type)
    {
        case SRV_UCM_INCOMING_CALL_IND:
            mmi_sublcd_ucm_incoming_call_hdlr((srv_ucm_incoming_call_ind_struct *)ind->ptr);
            break;
            
        case SRV_UCM_RELEASE_IND:
            mmi_sublcd_ucm_release_hdlr((srv_ucm_release_ind_struct *)ind->ptr);
            break;
            
        case SRV_UCM_OUTGOING_CALL_IND:
            if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
            {
                mmi_sublcd_ucm_outgoing_call_hdlr((srv_ucm_outgoing_call_ind_struct *)ind->ptr);
            } 
            break;

        case SRV_UCM_CONNECT_IND:
            close_call_related_screen();
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_nmgr_sub_lcd_hdlr
* DESCRIPTION
*  nmgr sub lcd event handler
* PARAMETERS
*  evt          : [IN] event that sub lcd nmgr is interested in
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
mmi_ret mmi_nmgr_sub_lcd_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_GPIO_CLAM_OPEN)
    {
        mmi_sublcd_clam_open_hdlr(evt);
    }
	else if (evt->evt_id == EVT_ID_SCENARIO_END)
	{
		mmi_sublcd_scenario_end_hdlr(evt);
	}
    else if(evt->evt_id == EVT_ID_GPIO_CLAM_CLOSE)
    {
        mmi_sublcd_clam_close_hdlr(evt);
    }

    if (srv_clam_is_close() == MMI_FALSE)
    {
        return MMI_RET_OK;
    }
    switch (evt->evt_id)
    {
        case EVT_ID_NMGR_SUBLCD_NOTIFY:
            mmi_nmgr_sub_lcd_scenario_hdlr(evt);
            break;

        case EVT_ID_SRV_UCM_INDICATION:
            mmi_sublcd_ucm_ind(evt);
            break;

        case EVT_ID_SRV_UCM_ACTION_NOTIFY:
            mmi_sublcd_ucm_action_handler(evt);
            break;
        
        default:
            break;
    }
    return MMI_RET_OK;
}

#endif /* __MMI_SUBLCD__ */

static void remove_status_icon(S32 status_icon)
{
    if ((status_icon < 0) || (status_icon >= MAX_STATUS_ICONS))
    {
        return;
    }
    wgui_status_icon_bar_reset_icon_display(status_icon);
    wgui_status_icon_bar_update();
}


static void control_status_icon(
    MMI_ID app_id,
    U32 option, 
    S32 icon_id
    )
{

    if (option & MMI_FRM_NMGR_DISABLE_STATUS_ICON)
    {
        return;
    }    
    
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    if (wgui_status_icon_bar_whether_icon_display(icon_id))
    {
        return;
    }
    
#if defined(__MMI_NSS_SUPPORT__) && defined(__MMI_NCENTER_SUPPORT__)
    if(app_id != 0)
    {
        U32 i, icon_index = MAXIMUM_STATUS_ICON_NUM;
        U16 ncenter_setting;
        /*Update the status icon to table*/
        if(mmi_srv_nss_get_setting (app_id, NSS_SETTING_NCENTER, & ncenter_setting) == MMI_RET_OK)
        {
            for(i = 0; i < MAXIMUM_STATUS_ICON_NUM; i++)
            {
                if(g_nss_app_icon[i].app_id == 0)
                {
                    icon_index = i;
                }
                if(g_nss_app_icon[i].app_id == app_id
                    && g_nss_app_icon[i].icon_id == icon_id)
                {
                    icon_index = i;
                    break;
                }
            }
            MMI_ASSERT(icon_index != MAXIMUM_STATUS_ICON_NUM);
            g_nss_app_icon[icon_index].app_id = app_id;
            g_nss_app_icon[icon_index].icon_id = icon_id;
            g_nss_app_icon[icon_index].alert_option= option;                

            if(ncenter_setting != SETTING_ON)
            {
                return;
            }
        }
    }
#endif
    
    wgui_status_icon_bar_set_icon_display(icon_id);
    if (option & MMI_FRM_NMGR_ICON_BLINKING)
    {
        wgui_status_icon_bar_blink_icon(icon_id);
    }
    else if (option & MMI_FRM_NMGR_ICON_ANIMATION)
    {
        wgui_status_icon_bar_animate_icon(icon_id);
    }
    wgui_status_icon_bar_update();
}


#ifdef __MMI_NCENTER_SUPPORT__
static S32 get_status_icon(U16 type)
{
#ifdef __COSMOS_MMI_PACKAGE__
    const mmi_events_notify_struct *info  = mmi_nmgr_get_event_notify_info((mmi_event_notify_enum)type, MMI_SCENARIO_ID_GENERAL);
    return info->status_icon;
#else
    return -1;
#endif
}


static S32 get_image_id(U16 type)
{
    const mmi_events_notify_struct *info = mmi_nmgr_get_event_notify_info((mmi_event_notify_enum)type, MMI_SCENARIO_ID_GENERAL);
    return info->img_id;
}


static S32 get_image_icon_for_preivew(U16 type)
{
    S32 icon_id;
    icon_id = get_image_id(type);
    if (icon_id == IMG_NONE)
    {
        S32 status_icon = get_status_icon(type);
        icon_id = wgui_status_icon_bar_get_icon_image_id(status_icon);
    }
    return icon_id;
}

static void init_text_buffer(void)
{
    S32 i;
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        text[i][0] = 0;
    }
}

static WCHAR* get_text_buffer(void)
{
    S32 i;
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        if (text[i][0] == 0)
        {
            return &text[i][0];
        }
    }
    return NULL;
}

static void free_text_buffer(WCHAR *p)
{
    MMI_ASSERT(p >= &text[0][0] && p < &text[MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM-1][MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT-1]);
    MMI_ASSERT((U32)p % 2 == 0);
    p[0] = 0;
}

static void init_data_buffer(void)
{
    S32 i;
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        data[i].is_used = KAL_FALSE;
        memset(data[i].data_buf, 0, MMI_FRM_NMGR_USER_DATA_LEN);
    }
}

static CHAR* get_data_buffer(void)
{
    S32 i;
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        if (data[i].is_used == MMI_FALSE)
        {
            data[i].is_used = MMI_TRUE;
            return &data[i].data_buf[0];
        }
    }
    return NULL;
}

static void free_data_buffer(CHAR *p)
{
    S32 i;    
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        if (data[i].is_used == MMI_TRUE && p == &data[i].data_buf[0])
        {
            data[i].is_used = MMI_FALSE;
            memset(data[i].data_buf, 0, MMI_FRM_NMGR_USER_DATA_LEN);
            return;
        }
    }    
}



static void init_preiview_queue(void)
{
    preview_queue.count = 0;
    preview_queue.rindx = 0;
    preview_queue.windx = 0;
}

static void update_queue_index(U8 *index, U8 len)
{
    *index = (++(*index)) % len;
}

static void write_preview_queue(mmi_nmgr_preview_info_struct *info)
{
    WCHAR *text = NULL;
    CHAR *data= NULL;
    
    if (preview_queue.count == MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM)
    {
        if(preview_queue.queue[preview_queue.rindx].app_proc_para.scrn_group_proc!=NULL)
        {
            mmi_event_struct evt;    
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_ALERT_END);
            if(preview_queue.queue[preview_queue.rindx].app_proc_para.data_size > 0)
            {
                MMI_FRM_SEND_EVENT(
                    &evt, 
                    preview_queue.queue[preview_queue.rindx].app_proc_para.scrn_group_proc, 
                    preview_queue.queue[preview_queue.rindx].app_proc_para.user_data);   
            }
            else
            {
                MMI_FRM_SEND_EVENT(
                    &evt, 
                    preview_queue.queue[preview_queue.rindx].app_proc_para.scrn_group_proc, 
                    NULL);   
            }            
        }
        update_queue_index(&preview_queue.rindx, MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM);
        text = preview_queue.queue[preview_queue.windx].text;     
        data = preview_queue.queue[preview_queue.windx].app_proc_para.user_data; 
    }
    else
    {
        text = get_text_buffer();
        data =get_data_buffer(); 
        MMI_ASSERT(text);        
        MMI_ASSERT(data);        
    }
        
    memcpy(&preview_queue.queue[preview_queue.windx], info, sizeof(mmi_nmgr_preview_info_struct));

    if(info->image_type == MMI_NMGR_IMG_FILE_PATH)
    {
        preview_queue.queue[preview_queue.windx].image.file_path = mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal( 
        info->image.file_path,
        MMI_MAX_FILE_NAME_LEN
        );
    }

    if(info->app_proc_para.user_data !=NULL && info->app_proc_para.data_size > 0)
    {
        memcpy(data, info->app_proc_para.user_data , info->app_proc_para.data_size);
    }

    if (mmi_ucs2strlen((const CHAR*)info->text) > MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT - 1)
    {
        mmi_ucs2ncpy((CHAR *)text, (const CHAR *)info->text, MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT);
    }
    else
    {
        mmi_ucs2cpy((CHAR *)text, (const CHAR *)info->text);
    }
    
    preview_queue.queue[preview_queue.windx].text = text;
    preview_queue.queue[preview_queue.windx].app_proc_para.user_data = data ;

    update_queue_index(&preview_queue.windx, MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM);
    if (preview_queue.count < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM)
    {
        preview_queue.count++;
    }
}

static MMI_BOOL read_preview_queue(mmi_nmgr_preview_info_struct *info)
{
    if (preview_queue.count == 0)
    {   
        return MMI_FALSE; 
    }
    info->event_type = preview_queue.queue[preview_queue.rindx].event_type;
    info->option     = preview_queue.queue[preview_queue.rindx].option;
    info->app_id = preview_queue.queue[preview_queue.rindx].app_id;
    info->image_type = preview_queue.queue[preview_queue.rindx].image_type;    
    info->app_proc_para.scrn_group_proc = preview_queue.queue[preview_queue.rindx].app_proc_para.scrn_group_proc;
    info->app_proc_para.data_size= preview_queue.queue[preview_queue.rindx].app_proc_para.data_size;

    memcpy(&info->image, &preview_queue.queue[preview_queue.rindx].image, sizeof(info->image));
    memcpy(&info->status_bar_icon_para,&preview_queue.queue[preview_queue.rindx].status_bar_icon_para,sizeof(info->status_bar_icon_para));

    mmi_ucs2cpy((CHAR *)info->text, (const CHAR *)preview_queue.queue[preview_queue.rindx].text);
    if(info->app_proc_para.data_size > 0)
    {
        memcpy( info->app_proc_para.user_data, preview_queue.queue[preview_queue.rindx].app_proc_para.user_data, info->app_proc_para.data_size);
    }
    else
    {
        info->app_proc_para.user_data = NULL;
    }
    
    free_text_buffer(preview_queue.queue[preview_queue.rindx].text);
    free_data_buffer(preview_queue.queue[preview_queue.rindx].app_proc_para.user_data);
    preview_queue.queue[preview_queue.rindx].text = NULL;    
    preview_queue.queue[preview_queue.rindx].app_proc_para.user_data = NULL;    
    
    update_queue_index(&preview_queue.rindx, MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM);
    preview_queue.count --;
    return MMI_TRUE;
}

static U8 get_preview_count(void)
{
    return preview_queue.count;
}

static void preview_done_cb(status_icon_bar_info_enum para, void *arg)
{
    mmi_nmgr_preview_info_struct info;

    if (para == WGUI_STATUS_ICON_BAR_INFO_SHOW)
    {        
        if(active_info.app_id!=0)
        {
            control_status_icon(active_info.app_id, 
            active_info.option,             
            active_info.status_bar_icon_para.icon_id);
        }
        else
        {
            control_status_icon(active_info.app_id, 
            active_info.option,             
            get_status_icon(active_info.event_type));
        }
    }
    else if (para == WGUI_STATUS_ICON_BAR_INFO_HIDE)
    {
        MMI_BOOL ret;
        nmgr_alert_cancel_launch_app_callback();

        if(active_info.image_type == MMI_NMGR_IMG_FILE_PATH
            && active_info.image.file_path != NULL)
        {            
            mmi_frm_nmgr_mem_free(active_info.image.file_path);
            active_info.image.file_path = NULL;
        }
                  
        info.text = preview_text;           
        info.app_proc_para.user_data = preview_data;           
        ret = read_preview_queue(&info);
        if (ret == MMI_FALSE)
        {
            is_on_preview = MMI_FALSE;            
        }
        else
        {
            S32 duration;
            S32 icon_id;
            memcpy(&active_info, &info, sizeof(mmi_nmgr_preview_info_struct));
            if (get_preview_count()  == 0)
            {
                duration = MMI_FRM_NMGR_TEXT_PREVIEW_LONG_DURATION;
            }
            else
            {
                duration = MMI_FRM_NMGR_TEXT_PREVIEW_SHORT_DURATION;
            }
            if(info.app_id!=0)
                icon_id = info.image.id;                
            else    
                icon_id = get_image_icon_for_preivew(info.event_type);

            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

            if(active_info.app_id!=0 && active_info.app_proc_para.scrn_group_proc!=NULL)
            {
                #ifdef __MMI_TOUCH_SCREEN__
                wgui_status_icon_bar_register_tap_proc(nmgr_alert_launch_app_callback);
                #endif
            }
           
            if(info.app_id!=0 && info.image_type != MMI_NMGR_IMG_RES_ID)
            {
                switch(info.image_type)
                {
                    case MMI_NMGR_IMG_FILE_PATH:
                        wgui_status_icon_bar_show_info_file(
                            (S8 *)info.image.file_path,
                            (WCHAR *)info.text, 
                            MMI_FRM_NMGR_TEXT_PREVIEW_LONG_DURATION, 
                            NULL, 
                            preview_done_cb);
                    break;    
                    case MMI_NMGR_IMG_DATA_BUFF:
                        wgui_status_icon_bar_show_info_ex(
                            info.image.data,
                            (WCHAR *)info.text, 
                            MMI_FRM_NMGR_TEXT_PREVIEW_LONG_DURATION, 
                            NULL, 
                            preview_done_cb);
                    break;    
                    case MMI_NMGR_IMG_RAW_DATA_BUFF:
                        wgui_status_icon_bar_show_info_mem(
                            info.image.raw_data.buff, 
                            info.image.raw_data.size, 
                            info.image.raw_data.format,
                            (WCHAR *)info.text, 
                            MMI_FRM_NMGR_TEXT_PREVIEW_LONG_DURATION, 
                            NULL, 
                            preview_done_cb);
                    break;    
                }            
            }
            else
            {
                wgui_status_icon_bar_show_info(
                    icon_id,
                    (WCHAR *)info.text,
                    duration, 
                    NULL, 
                    preview_done_cb);                 
            }      
            
        }
    }
}

static void merge_preview_queue(U16 type, MMI_ID app_id)
{
    U8 temp;
    U8 dst;
    MMI_BOOL need_merge = MMI_FALSE;
    MMI_BOOL is_break   = MMI_FALSE;
    
    if (preview_queue.count == 0)
    {
        return;
    }
    while (preview_queue.rindx != preview_queue.windx)
    {
        if (preview_queue.queue[preview_queue.rindx].app_id == app_id &&
            preview_queue.queue[preview_queue.rindx].event_type == type)
        {
            if(preview_queue.queue[preview_queue.rindx].app_proc_para.scrn_group_proc!=NULL)
            {
                mmi_event_struct evt;    
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_ALERT_END);
                if(preview_queue.queue[preview_queue.rindx].app_proc_para.data_size > 0)
                {
                    MMI_FRM_SEND_EVENT(
                        &evt, 
                        preview_queue.queue[preview_queue.rindx].app_proc_para.scrn_group_proc, 
                        preview_queue.queue[preview_queue.rindx].app_proc_para.user_data);   
                }
                else
                {
                    MMI_FRM_SEND_EVENT(
                        &evt, 
                        preview_queue.queue[preview_queue.rindx].app_proc_para.scrn_group_proc, 
                        NULL);   
                }            
            }
            free_text_buffer(preview_queue.queue[preview_queue.rindx].text);
            free_data_buffer(preview_queue.queue[preview_queue.rindx].app_proc_para.user_data);
            preview_queue.queue[preview_queue.rindx].text = NULL;    
            preview_queue.queue[preview_queue.rindx].app_proc_para.user_data = NULL;    
            update_queue_index(&preview_queue.rindx, MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM);
            preview_queue.count--;
        }
        else
        {
            temp = (preview_queue.rindx + 1) % MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM;
            dst = temp;
            is_break = MMI_TRUE;
            break;
        }
    }

    while(is_break && temp != preview_queue.windx)
    {
        if (preview_queue.queue[temp].event_type == type &&
            preview_queue.queue[temp].app_id == app_id)
        {
            if (need_merge == MMI_FALSE)
            {
                dst = temp;
            }
            if(preview_queue.queue[temp].app_proc_para.scrn_group_proc!=NULL)
            {
                mmi_event_struct evt;    
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_ALERT_END);
                if(preview_queue.queue[temp].app_proc_para.data_size > 0)
                {
                    MMI_FRM_SEND_EVENT(
                        &evt, 
                        preview_queue.queue[temp].app_proc_para.scrn_group_proc, 
                        preview_queue.queue[temp].app_proc_para.user_data);   
                }
                else
                {
                    MMI_FRM_SEND_EVENT(
                        &evt, 
                        preview_queue.queue[temp].app_proc_para.scrn_group_proc, 
                        NULL);   
                }            
            }
            free_text_buffer(preview_queue.queue[temp].text);
            free_data_buffer(preview_queue.queue[temp].app_proc_para.user_data);
            preview_queue.queue[temp].text = NULL;
            preview_queue.queue[temp].app_proc_para.user_data = NULL;    
            update_queue_index(&temp, MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM);
            preview_queue.count--;
            need_merge = MMI_TRUE;
        }
        else
        {
            if (need_merge == MMI_TRUE)
            {
                preview_queue.queue[dst] = preview_queue.queue[temp];
                preview_queue.queue[temp].event_type = type;
                preview_queue.queue[temp].text = NULL;
                preview_queue.queue[temp].app_proc_para.user_data = NULL;
                update_queue_index(&dst, MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM);				
            }
            update_queue_index(&temp, MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM);
        }
    }
    preview_queue.windx = (preview_queue.rindx + preview_queue.count) % MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM;
}
#endif /* __COSMOS_MMI_PACKAGE__ */

//#define __FTO_NMGR_TEST__
#ifdef __FTO_NMGR_TEST__
mmi_nmgr_preview_info_struct data[] =
{
    {0,
	 0,
     L"AAAAAAAAAABBBBBBBBBBCCCCCCCCCCDDDDDDDDDDEEEEEEEEEEFFFFFFFFFF"
    },
    {1,
	 0,
     L"AAAAAAAAAABBBBBBBBBBCCCCCCCCCCDDDDDDDDDDEEEEEEEEEEFFFFFFFFFFGGGGGGGGGGG"
    }
};

mmi_nmgr_preview_info_struct merge_test_data[] =
{
	{
		0,
		0,
		L"Tian"
	},
	{
		0,
		0,
		L"Tian"
	},
	{
		1,
		0,
		L"Hua"
	},
	{
		0,
		0,
		L"Tian"
	},
	{
		0,
		0,
		L"Tian"
	},
	{
		1,
		0,
		L"Hua"
	},
	{
		0,
		0,
		L"Tian"
	}
};

void fto_nmgr_test(void)
{
    extern void vtst_nmgr(void);

    WCHAR *p;
	WCHAR *q;
    U8 i;
    U8 a;
	WCHAR *t[MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM];
    mmi_nmgr_preview_info_struct temp;
    WCHAR temp_buffer[MMI_FRM_NMGR_TEXT_PREVIEW_TEXT_BUF_LEN];
    temp.text = temp_buffer;
    init_text_buffer();
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        p = text[i];
        MMI_ASSERT(mmi_ucs2strlen((const CHAR *)p) == 0);
    }
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        p = get_text_buffer();
        MMI_ASSERT(mmi_ucs2strlen((const CHAR *)p) == 0);
        mmi_ucs2cpy((CHAR *)p, (const CHAR*)L"HelloWorld\n");
        MMI_ASSERT(p == text[i]);
		t[i] = p;
    }
	free_text_buffer(p);
	q = get_text_buffer();
    mmi_ucs2cpy((CHAR *)q, (const CHAR*)L"HelloWorld\n");
	MMI_ASSERT(p == q);
	p = get_text_buffer();
	MMI_ASSERT(p == NULL);
	for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
	{
		free_text_buffer(t[i]);
	}
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        p = text[i];
        MMI_ASSERT(mmi_ucs2strlen((const CHAR *)p) == 0);
    }

    init_preiview_queue();

    MMI_ASSERT(preview_queue.count == 0);
    MMI_ASSERT(preview_queue.windx == 0);
    MMI_ASSERT(preview_queue.rindx == 0);
    a = 0;
    update_queue_index(&a, 10);
    MMI_ASSERT(a == 1);

    a = 9;
    update_queue_index(&a, 10);
    MMI_ASSERT(a == 0); 

    MMI_ASSERT(MMI_FALSE == read_preview_queue(&temp));

    write_preview_queue(&data[0]);
    write_preview_queue(&data[1]);

	MMI_ASSERT(MMI_TRUE == read_preview_queue(&temp));
    MMI_ASSERT(temp.event_type == data[0].event_type);
    MMI_ASSERT(mmi_ucs2ncmp((const CHAR*)temp.text, (const CHAR*)data[0].text, MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT) == 0);

    MMI_ASSERT(MMI_TRUE == read_preview_queue(&temp));
    MMI_ASSERT(temp.event_type == data[1].event_type);
    MMI_ASSERT(mmi_ucs2ncmp((const CHAR*)temp.text, (const CHAR*)data[1].text, MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT) == 0);
    MMI_ASSERT(preview_queue.count == 0);
    MMI_ASSERT(preview_queue.windx == preview_queue.rindx);
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        p = text[i];
        MMI_ASSERT(mmi_ucs2strlen((const CHAR *)p) == 0);
    }
	for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
	{
		write_preview_queue(&data[1]);
	}
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        MMI_ASSERT(read_preview_queue(&temp) == MMI_TRUE);
        MMI_ASSERT(temp.event_type == data[1].event_type);
        MMI_ASSERT(mmi_ucs2ncmp((const CHAR*)temp.text, (const CHAR*)data[1].text, MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT) == 0);
    }
    MMI_ASSERT(preview_queue.count == 0);
    MMI_ASSERT(preview_queue.windx == preview_queue.rindx);
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        p = text[i];
        MMI_ASSERT(mmi_ucs2strlen((const CHAR *)p) == 0);
    }

    preview_queue.windx = preview_queue.rindx = 0;
    for (i = 0; i < sizeof(merge_test_data) / sizeof(merge_test_data[0]); i++)
    {
        write_preview_queue(&merge_test_data[i]);
    }
    merge_preview_queue(0, 0);
    MMI_ASSERT(preview_queue.count == 2);
    MMI_ASSERT(preview_queue.rindx == 2);
    MMI_ASSERT(preview_queue.windx == 4);
    a = preview_queue.count;
    for (i = 0; i < a; i++)
    {
        MMI_ASSERT(MMI_TRUE == read_preview_queue(&temp));
        MMI_ASSERT(temp.event_type == 1);
        MMI_ASSERT(mmi_ucs2cmp((const CHAR*)temp.text, (const CHAR*)L"Hua") == 0);
    }
    MMI_ASSERT(preview_queue.count == 0);
    MMI_ASSERT(preview_queue.windx == preview_queue.rindx);
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        p = text[i];
        MMI_ASSERT(mmi_ucs2strlen((const CHAR *)p) == 0);
    }

	preview_queue.windx = preview_queue.rindx = MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM - 3;

    for (i = 0; i < sizeof(merge_test_data) / sizeof(merge_test_data[0]); i++)
    {
        write_preview_queue(&merge_test_data[i]);
    }
    merge_preview_queue(0, 0);
    MMI_ASSERT(preview_queue.count == 2);
    MMI_ASSERT(preview_queue.rindx == MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM - 1);
    MMI_ASSERT(preview_queue.windx == 1);
    a = preview_queue.count;
    for (i = 0; i < a; i++)
    {
        MMI_ASSERT(MMI_TRUE == read_preview_queue(&temp));
        MMI_ASSERT(temp.event_type == 1);
        MMI_ASSERT(mmi_ucs2cmp((const CHAR*)temp.text, (const CHAR*)L"Hua") == 0);
    }
    MMI_ASSERT(preview_queue.count == 0);
    MMI_ASSERT(preview_queue.windx == preview_queue.rindx);
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        p = text[i];
        MMI_ASSERT(mmi_ucs2strlen((const CHAR *)p) == 0);
    }


    preview_queue.windx = preview_queue.rindx = 0;
    for (i = 0; i < sizeof(merge_test_data) / sizeof(merge_test_data[0]); i++)
    {
        write_preview_queue(&merge_test_data[i]);
    }
    merge_preview_queue(1, 0);
    MMI_ASSERT(preview_queue.count == 5);
    MMI_ASSERT(preview_queue.rindx == 0);
    MMI_ASSERT(preview_queue.windx == 5);
    a = preview_queue.count;
    for (i = 0; i < a; i++)
    {
        MMI_ASSERT(MMI_TRUE == read_preview_queue(&temp));
        MMI_ASSERT(temp.event_type == 0);
        MMI_ASSERT(mmi_ucs2cmp((const CHAR*)temp.text, (const CHAR*)L"Tian") == 0);
    }
    MMI_ASSERT(preview_queue.count == 0);
    MMI_ASSERT(preview_queue.windx == preview_queue.rindx);
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        p = text[i];
        MMI_ASSERT(mmi_ucs2strlen((const CHAR *)p) == 0);
    }


    preview_queue.windx = preview_queue.rindx = MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM - 3;
    for (i = 0; i < sizeof(merge_test_data) / sizeof(merge_test_data[0]); i++)
    {
        write_preview_queue(&merge_test_data[i]);
    }
    merge_preview_queue(1, 0);
    MMI_ASSERT(preview_queue.count == 5);
    MMI_ASSERT(preview_queue.rindx == MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM - 3);
    MMI_ASSERT(preview_queue.windx == 2);
    a = preview_queue.count;
    for (i = 0; i < a; i++)
    {
        MMI_ASSERT(MMI_TRUE == read_preview_queue(&temp));
        MMI_ASSERT(temp.event_type == 0);
        MMI_ASSERT(mmi_ucs2cmp((const CHAR*)temp.text, (const CHAR*)L"Tian") == 0);
    }
    MMI_ASSERT(preview_queue.count == 0);
    MMI_ASSERT(preview_queue.windx == preview_queue.rindx);
    for (i = 0; i < MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM; i++)
    {
        p = text[i];
        MMI_ASSERT(mmi_ucs2strlen((const CHAR *)p) == 0);
    }
}
#endif


#ifdef MMI_NOTI_MGR_UT
//#if 1
#include "mmi_include.h"
#include "FileMgrSrvGProt.h"
#include "mmi_frm_scenario_list.h"
#include "UCMResDef.h"
#include "phonebookResDef.h"
#include "ConnectivityResDef.h"

void mmi_frm_noti_mgr_test_case_entry(U8 index);
static void scenario_ut_default_entry(void);
static void scenario_ut_high_entry(void);
static void scenario_ut_highest_entry(void);
static void scenario_ucm_entry(void);
static void scenario_earphone_entry(void);
static void scenario_syncml_access_entry(void);
static void scenario_bt_access_entry(void);

/***************************************************************************** 
 * typedef
 *****************************************************************************/
//typedef void (*scenario_entry)(void *arg);
typedef FuncPtr scenario_entry;

typedef struct
{
    mmi_scenario_id scen_id;
    scenario_entry scen_entry;
} scenario_entry_struct;


static const scenario_entry_struct scen_entry_tbl[] = 
{
    {SCENARIO_ID_UT_DEFAULT,            scenario_ut_default_entry},
    {SCENARIO_ID_UT_HIGH_SCRN,          scenario_ut_high_entry},
    {SCENARIO_ID_UT_HIGHEST_SCRN,       scenario_ut_highest_entry},
    {SCENARIO_ID_UT_UCM_INCOMING_CALL,  scenario_ucm_entry},
    {SCENARIO_ID_UT_EARPHONE,           scenario_earphone_entry},
    {SCENARIO_ID_UT_AUTO_SYNC,          scenario_syncml_access_entry},
    {SCENARIO_ID_UT_BT_ACCESS_REQ,      scenario_bt_access_entry},
};

#define SCENARIO_ENTRY_TBL_SIZE (sizeof(scen_entry_tbl) / sizeof(scen_entry_tbl[0]))
#define SCR_BT_SET_SELECT_DRV_OPPS      (SCR_ID_NMGR_NOTIFY + 1)
#define SCR_BT_SET_SELECT_DRV_FTPC      (SCR_ID_NMGR_NOTIFY + 2)
#define SCR_BT_SET_SELECT_DRV_GET_BIPC  (SCR_ID_NMGR_NOTIFY + 3)

/***************************************************************************** 
 * Internal interface
 *****************************************************************************/
static void dummy_entry_func(void)
{
    EntryNewScreen(SCR_ID_DUMMY, NULL, dummy_entry_func, NULL);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    ShowCategoryDummyScreen();
}

static void setup_ut_context(void)
{
    show_poup = MMI_FALSE;
    play_sound = MMI_FALSE;
    play_vibrator = MMI_FALSE;
    play_backlight = MMI_FALSE;
    scrn_action = MMI_BEHAVIOR_ALL_NONE;
    snd_action = MMI_BEHAVIOR_ALL_NONE;
    vib_action = MMI_BEHAVIOR_ALL_NONE;
    bl_action = MMI_BEHAVIOR_ALL_NONE;
    scenario_end = MMI_SCENARIO_ID_END;
    //DisplayIdleScreen();
    ExecuteRootMainHistoryScreen(NULL);
    //MMI_ASSERT(!scenario_list_is_empty() && MMI_SCENARIO_ID_IDLE == mmi_frm_get_active_scenario_id());
    //mmi_frm_deinit_scenario();
    dummy_entry_func();
}

static void enter_scenario(mmi_scenario_id scen_id)
{
    S32 idx;

    for (idx = 0; idx < SCENARIO_ENTRY_TBL_SIZE; idx++)
    {
        if (scen_id == scen_entry_tbl[idx].scen_id)
        {
            scen_entry_tbl[idx].scen_entry();
            break;
        }
    }
}

#include "SyncMLDef.h"
typedef struct
{
    U16 sync_result;
    U16 string_id;
    U8  emotion_id;
} mmi_syncml_display_popup_hdlr_struct;

/* Default priority scenario entry function */
U8 scenario_ut_default_destroy_hdlr(void *arg)
{
    mmi_frm_end_scenario(SCENARIO_ID_UT_DEFAULT);

    return 1;
}

static void scenario_ut_default_entry(void)
{
    mmi_frm_start_scenario(SCENARIO_ID_UT_DEFAULT);
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, scenario_ut_default_entry, NULL);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    ShowCategory53Screen(
        STR_GLOBAL_DEFAULT,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        NULL,
        NULL,
        NULL,
        0, 0, NULL);
    mmi_frm_set_destroy_scrn_callback(GLOBAL_SCR_DUMMY, scenario_ut_default_destroy_hdlr);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* High priority scenario entry function */
U8 scenario_ut_high_destroy_hdlr(void *arg)
{
    mmi_frm_end_scenario(SCENARIO_ID_UT_HIGH_SCRN);

    return 1;
}

static void scenario_ut_high_entry(void)
{
    mmi_frm_start_scenario(SCENARIO_ID_UT_HIGH_SCRN);
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, scenario_ut_high_entry, NULL);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    ShowCategory53Screen(
        STR_GLOBAL_HIGH,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        NULL,
        NULL,
        NULL,
        0, 0, NULL);
    mmi_frm_set_destroy_scrn_callback(GLOBAL_SCR_DUMMY, scenario_ut_high_destroy_hdlr);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* Highest priority scenario entry function */
U8 scenario_ut_highest_destroy_hdlr(void *arg)
{
    mmi_frm_end_scenario(SCENARIO_ID_UT_HIGHEST_SCRN);

    return 1;
}

static void scenario_ut_highest_entry(void)
{
    mmi_frm_start_scenario(SCENARIO_ID_UT_HIGHEST_SCRN);
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, scenario_ut_highest_entry, NULL);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    ShowCategory53Screen(
        STR_GLOBAL_HTTP,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        NULL,
        NULL,
        NULL,
        0, 0, NULL);
    mmi_frm_set_destroy_scrn_callback(GLOBAL_SCR_DUMMY, scenario_ut_highest_destroy_hdlr);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/* BT access entry function */
U8 scenario_ut_bt_access_destroy_hdlr(void *arg)
{
    mmi_frm_end_scenario(SCENARIO_ID_UT_BT_ACCESS_REQ);

    return 1;
}

MMI_BOOL scenario_bt_access_scrn_entry(mmi_scenario_id scen_id, void *arg)
{
    mmi_frm_start_scenario(SCENARIO_ID_UT_BT_ACCESS_REQ);
    EntryNewScreen(SCR_BT_SET_SELECT_DRV_OPPS, NULL, scenario_bt_access_entry, NULL);
    mmi_frm_set_destroy_scrn_callback(SCR_BT_SET_SELECT_DRV_OPPS, scenario_ut_bt_access_destroy_hdlr);
	return MMI_TRUE;
}

void scenario_bt_access_scrn_entry_1(void)
{
    mmi_frm_start_scenario(SCENARIO_ID_UT_BT_ACCESS_REQ);
    EntryNewScreen(SCR_BT_SET_SELECT_DRV_FTPC, NULL, scenario_bt_access_scrn_entry_1, NULL);
    mmi_frm_set_destroy_scrn_callback(SCR_BT_SET_SELECT_DRV_FTPC, scenario_ut_bt_access_destroy_hdlr);
}

void scenario_bt_access_scrn_entry_2(void)
{
    mmi_frm_start_scenario(SCENARIO_ID_UT_BT_ACCESS_REQ);
    EntryNewScreen(SCR_BT_SET_SELECT_DRV_OPPS, NULL, scenario_bt_access_scrn_entry_2, NULL);
    mmi_frm_set_destroy_scrn_callback(SCR_BT_SET_SELECT_DRV_OPPS, scenario_ut_bt_access_destroy_hdlr);
}

void scenario_bt_access_scrn_entry_3(void)
{
    mmi_frm_start_scenario(SCENARIO_ID_UT_BT_ACCESS_REQ);
    EntryNewScreen(SCR_BT_SET_SELECT_DRV_GET_BIPC, NULL, scenario_bt_access_scrn_entry_3, NULL);
    mmi_frm_set_destroy_scrn_callback(SCR_BT_SET_SELECT_DRV_GET_BIPC, scenario_ut_bt_access_destroy_hdlr);
}

MMI_BOOL scenario_bt_access_scrn_entry_multi(mmi_scenario_id scen_id, void *arg)
{
	U16 scrn_id = *((U16 *)arg);

    switch (scrn_id)
    {
        case SCR_BT_SET_SELECT_DRV_FTPC:
        {
            scenario_bt_access_scrn_entry_1();
            OslMfree(arg);
            break;
        }
        case SCR_BT_SET_SELECT_DRV_OPPS:
        {
            scenario_bt_access_scrn_entry_2();
            OslMfree(arg);
            break;
        }
        case SCR_BT_SET_SELECT_DRV_GET_BIPC:
        {
            scenario_bt_access_scrn_entry_3();
            OslMfree(arg);
            break;
        }
        default:
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


static void scenario_bt_access_entry(void)
{
    mmi_frm_nmgr_notify_by_app(SCENARIO_ID_UT_BT_ACCESS_REQ, MMI_EVENT_INFO, scenario_bt_access_scrn_entry, NULL);
}


/* Auto sync entry function */
MMI_BOOL mmi_noti_mgr_ut_sync_defer_cb(mmi_scenario_id scen_id, void *arg)
{
    mmi_syncml_display_popup_hdlr_struct *popup_status_ptr = (mmi_syncml_display_popup_hdlr_struct *)arg;
    
    mmi_frm_nmgr_popup(
        SCENARIO_ID_UT_AUTO_SYNC,
        popup_status_ptr->emotion_id, 
        (WCHAR *)GetString(popup_status_ptr->string_id));

    OslMfree(popup_status_ptr);

    MMI_ASSERT(SCR_ID_NMGR_NOTIFY == GetActiveScreenId());

    return MMI_TRUE;
}


static void scenario_syncml_access_entry(void)
{
    mmi_syncml_display_popup_hdlr_struct *popup_status_ptr
        = OslMalloc(sizeof(mmi_syncml_display_popup_hdlr_struct));
    popup_status_ptr->emotion_id = MMI_EVENT_INFO;
    popup_status_ptr->string_id = STR_ID_SYNC_CANCELLED;
    popup_status_ptr->sync_result = SYNCML_OK;

    mmi_frm_nmgr_notify_by_app(
        SCENARIO_ID_UT_AUTO_SYNC,
        MMI_EVENT_INFO,
        mmi_noti_mgr_ut_sync_defer_cb,
        (void *)popup_status_ptr);
    MMI_ASSERT(!mmi_frm_is_scenario_started(SCENARIO_ID_UT_AUTO_SYNC));
}


/* Earphone entry function */
static void scenario_earphone_entry(void)
{
    mmi_frm_nmgr_popup(SCENARIO_ID_UT_EARPHONE, MMI_EVENT_INFO, (WCHAR *)GetString(STR_GLOBAL_EARPHONE_IN));
}


/* UCM entry function */
static U8 ucm_destroy_hdlr(void *arg)
{
    mmi_frm_end_scenario(SCENARIO_ID_UT_UCM_INCOMING_CALL);
    
    return MMI_TRUE;
}

static void scenario_ucm_entry(void)
{
    U8 *gui_buffer;

    mmi_frm_start_scenario(SCENARIO_ID_UT_UCM_INCOMING_CALL);
    EntryNewScreen(SCR_ID_UCM_INCOMING, NULL, scenario_ucm_entry, NULL);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_UCM_INCOMING);
    ShowCategory17Screen(
            0,                      /* title_id */
            STR_ID_UCM_ANSWER,      /* left_softkey */
            IMG_GLOBAL_OPTIONS,     /* left_softkey_icon */
            STR_ID_UCM_REJECT,      /* right_softkey */
            0,                      /* right_softkey_icon */
            0,                      /* NotificationStringId */ 
            (U8*)"xiaodong",        /* NameOrNumber */
            NULL,                   /* IP_Number */
            0,                      /* line icon */
            IMG_PHB_DEFAULT,        /* default_image_id */
            0,                      /* resource_id */
            (CHAR*)NULL,              /* resource_filename */
            0,                      /* resource_type */
            0,                      /* repeat_count, video/swflash only, repeat_count, 0 = infinite */
            MMI_FALSE,              /* is_visaul_update, video/swflash only, update to LCM or not */
            MMI_FALSE,              /* is_video_aud, video/swflash only, play video's audio */
            MMI_FALSE,              /* is_play_aud_when_start */
            gui_buffer); 
    mmi_frm_set_destroy_scrn_callback(SCR_ID_UCM_INCOMING, ucm_destroy_hdlr);
}

static inject_notification(mmi_scenario_id scenario_id)
{
    enter_scenario(scenario_id);
}


/***************************************************************************** 
 * Basic requirement test cases
 *****************************************************************************/
MMI_BOOL mmi_noti_mgr_ut_popup_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check behavior at ucm incoming call scenario */
    enter_scenario(SCENARIO_ID_UT_UCM_INCOMING_CALL);

    inject_notification(SCENARIO_ID_UT_EARPHONE);

    MMI_ASSERT(GetActiveScreenId() != SCR_ID_NMGR_NOTIFY && GetActiveScreenId() == SCR_ID_UCM_INCOMING);
    MMI_ASSERT(!scenario_list_find(SCENARIO_ID_UT_EARPHONE));

    GoBackHistory();
    MMI_ASSERT(NULL == scenario_list_find(SCENARIO_ID_UT_UCM_INCOMING_CALL));
    //MMI_ASSERT(scenario_list_is_empty() && !scenario_list_get_header());

    ExecuteRootMainHistoryScreen(NULL);
    /* Idle post to enter group */
	//MMI_ASSERT(!scenario_list_is_empty() && MMI_SCENARIO_ID_IDLE == mmi_frm_get_active_scenario_id());

    return MMI_TRUE;
}


MMI_BOOL mmi_noti_mgr_ut_defer_popup_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    enter_scenario(SCENARIO_ID_UT_DEFAULT);
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_DEFAULT));
    
    enter_scenario(SCENARIO_ID_UT_UCM_INCOMING_CALL);
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_UCM_INCOMING_CALL));

	inject_notification(SCENARIO_ID_UT_AUTO_SYNC);
    MMI_ASSERT(GetActiveScreenId() != SCR_ID_NMGR_NOTIFY && GetActiveScreenId() == SCR_ID_UCM_INCOMING);
    MMI_ASSERT(!mmi_frm_is_scenario_started(SCENARIO_ID_UT_AUTO_SYNC));
	disable_invoke_defer_event = MMI_TRUE;
    GoBackHistory();
    //MMI_ASSERT(0 == mmi_frm_get_post_event_number());
	disable_invoke_defer_event = MMI_FALSE;
    if (mmi_frm_event_get_switch_screen_flag())
    {
        mmi_ret rst;
        rst = invoke_notify_defer_notification();
        MMI_ASSERT(MMI_RET_OK == rst);
    }
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_AUTO_SYNC));
    MMI_ASSERT(SCR_ID_NMGR_NOTIFY == GetActiveScreenId());
    MMI_ASSERT(0 == mmi_frm_nmgr_get_defer_notification_count());

    ExecuteRootMainHistoryScreen(NULL);
    //MMI_ASSERT(!scenario_list_is_empty() && MMI_SCENARIO_ID_IDLE == mmi_frm_get_active_scenario_id());

    return MMI_TRUE;
}


MMI_BOOL mmi_noti_mgr_ut_defer_full_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    enter_scenario(SCENARIO_ID_UT_DEFAULT);
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_DEFAULT));
    
    enter_scenario(SCENARIO_ID_UT_UCM_INCOMING_CALL);
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_UCM_INCOMING_CALL));

    inject_notification(SCENARIO_ID_UT_BT_ACCESS_REQ);
    MMI_ASSERT(GetActiveScreenId() == SCR_ID_UCM_INCOMING);
    MMI_ASSERT(!mmi_frm_is_scenario_started(SCENARIO_ID_UT_BT_ACCESS_REQ));
    MMI_ASSERT(1 == mmi_frm_nmgr_get_defer_notification_count());
	disable_invoke_defer_event = MMI_TRUE;
    GoBackHistory();
    //MMI_ASSERT(0 == mmi_frm_get_post_event_number());
    disable_invoke_defer_event = MMI_FALSE;
    if (mmi_frm_event_get_switch_screen_flag())
    {
        mmi_ret rst;
        rst = invoke_notify_defer_notification();
        MMI_ASSERT(MMI_RET_OK == rst);
    }
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_BT_ACCESS_REQ));
    MMI_ASSERT(!mmi_frm_is_scenario_started(SCENARIO_ID_UT_UCM_INCOMING_CALL));
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_DEFAULT));
    MMI_ASSERT(SCR_BT_SET_SELECT_DRV_OPPS == GetActiveScreenId());
    MMI_ASSERT(0 == mmi_frm_nmgr_get_defer_notification_count());

    ExecuteRootMainHistoryScreen(NULL);
    //MMI_ASSERT(!scenario_list_is_empty() && MMI_SCENARIO_ID_IDLE == mmi_frm_get_active_scenario_id());

    return MMI_TRUE;
}


MMI_BOOL mmi_noti_mgr_ut_defer_multi_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *scrn_id;
    mmi_ret rst;
    mmi_scenario_position position_1, position_2, position_3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    enter_scenario(SCENARIO_ID_UT_UCM_INCOMING_CALL);
    /* 
     * Disable post event & invoking defer notificaion by post event, which could test defer logic in sync method,
     * otherwise, post event will eat up all control buffer!
     */
    disable_invoke_defer_event = MMI_TRUE;

    /* BT obex use one scenario id to control different screen */
    scrn_id = OslMalloc(sizeof(U16));
    *scrn_id = SCR_BT_SET_SELECT_DRV_FTPC;
    mmi_frm_nmgr_notify_by_app(SCENARIO_ID_UT_BT_ACCESS_REQ, MMI_EVENT_INFO, scenario_bt_access_scrn_entry_multi, (void *)scrn_id);
    MMI_ASSERT(!mmi_frm_is_scenario_started(SCENARIO_ID_UT_BT_ACCESS_REQ));

    scrn_id = OslMalloc(sizeof(U16));
    *scrn_id = SCR_BT_SET_SELECT_DRV_OPPS;
    mmi_frm_nmgr_notify_by_app(SCENARIO_ID_UT_BT_ACCESS_REQ, MMI_EVENT_INFO, scenario_bt_access_scrn_entry_multi, (void *)scrn_id);
    MMI_ASSERT(!mmi_frm_is_scenario_started(SCENARIO_ID_UT_BT_ACCESS_REQ));

    scrn_id = OslMalloc(sizeof(U16));
    *scrn_id = SCR_BT_SET_SELECT_DRV_GET_BIPC;
    mmi_frm_nmgr_notify_by_app(SCENARIO_ID_UT_BT_ACCESS_REQ, MMI_EVENT_INFO, scenario_bt_access_scrn_entry_multi, (void *)scrn_id);
    MMI_ASSERT(!mmi_frm_is_scenario_started(SCENARIO_ID_UT_BT_ACCESS_REQ));

    MMI_ASSERT(3 == mmi_frm_nmgr_get_defer_notification_count());
    /* Exit incoming call scenario */
	GoBackHistory();
    MMI_ASSERT(!mmi_frm_is_scenario_started(SCENARIO_ID_UT_UCM_INCOMING_CALL));

    //MMI_ASSERT(0 == mmi_frm_get_post_event_number());
	disable_invoke_defer_event = MMI_FALSE;

    rst = invoke_notify_defer_notification();
    MMI_ASSERT(MMI_RET_OK == rst);
    MMI_ASSERT(SCR_BT_SET_SELECT_DRV_FTPC == GetActiveScreenId());
    MMI_ASSERT(2 == mmi_frm_nmgr_get_defer_notification_count());
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_BT_ACCESS_REQ));
    position_1 = scenario_list_find(SCENARIO_ID_UT_BT_ACCESS_REQ);
    MMI_ASSERT(1 == position_1->scenario_info.ref_cnt);

    rst = invoke_notify_defer_notification();
    MMI_ASSERT(MMI_RET_OK == rst);
    MMI_ASSERT(SCR_BT_SET_SELECT_DRV_OPPS == GetActiveScreenId());
    MMI_ASSERT(1 == mmi_frm_nmgr_get_defer_notification_count());
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_BT_ACCESS_REQ));
    position_2 = scenario_list_find(SCENARIO_ID_UT_BT_ACCESS_REQ);
    MMI_ASSERT(position_1 == position_2);
    MMI_ASSERT(2 == position_2->scenario_info.ref_cnt);

    rst = invoke_notify_defer_notification();
    MMI_ASSERT(MMI_RET_OK == rst);
    MMI_ASSERT(SCR_BT_SET_SELECT_DRV_GET_BIPC == GetActiveScreenId());
    MMI_ASSERT(0 == mmi_frm_nmgr_get_defer_notification_count());
    MMI_ASSERT(mmi_frm_is_scenario_started(SCENARIO_ID_UT_BT_ACCESS_REQ));
    position_3 = scenario_list_find(SCENARIO_ID_UT_BT_ACCESS_REQ);
    MMI_ASSERT(position_3 == position_2);
    MMI_ASSERT(3 == position_3->scenario_info.ref_cnt);

    /*****************************************
     *      |---------------|   
     *      |    BIPC       |	Active
     *      |---------------|
     *      |    OPPS       |   Top
     *      |---------------|
     *      |    FTPC       |
     *      |---------------|   Bottom
     *****************************************/
    DeleteScreenIfPresent(SCR_BT_SET_SELECT_DRV_OPPS);
    MMI_ASSERT(2== position_3->scenario_info.ref_cnt);

    GoBackHistory();
    MMI_ASSERT(SCR_BT_SET_SELECT_DRV_FTPC == GetActiveScreenId());
    MMI_ASSERT(1== position_3->scenario_info.ref_cnt);

    GoBackHistory();
    
    MMI_ASSERT(!mmi_frm_is_scenario_started(SCENARIO_ID_UT_BT_ACCESS_REQ));
    //MMI_ASSERT(0 == mmi_frm_get_post_event_number());
    //MMI_ASSERT(scenario_list_is_empty() && !scenario_list_get_header());
    //MMI_ASSERT(!scenario_list_is_empty() && MMI_SCENARIO_ID_IDLE == mmi_frm_get_active_scenario_id());

    return MMI_TRUE;
}


#define TEST_SCENARIO_SCREEN    1
#define TEST_SCENARIO_SOUND     2
#define TEST_SCENARIO_VIBRATOR  3
#define TEST_SCENARIO_BACKLIGHT 4

typedef void (*traverse_action_func)(mmi_scenario_id active_scen_id, mmi_scenario_id notify_scen_id, U32 flag);

static void traverse_scenario_priority(mmi_scenario_id begin_id, mmi_scenario_id end_id, traverse_action_func func, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_id active_scen_id, notify_scen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (active_scen_id = begin_id; active_scen_id <= end_id; active_scen_id++)
    {
        mmi_frm_start_scenario(active_scen_id);
        MMI_ASSERT(mmi_frm_is_scenario_started(active_scen_id));
        /* Check lower & same & higher priority scenario */
        for (notify_scen_id = begin_id; notify_scen_id <= end_id; notify_scen_id++)
        {
            func(active_scen_id, notify_scen_id, flag);
        }
        mmi_frm_end_scenario(active_scen_id);
    }
}

static void check_scenario_priority(mmi_scenario_id active_scen_id, mmi_scenario_id notify_scen_id, U32 flag)
{
    mmi_frm_nmgr_popup(notify_scen_id, MMI_EVENT_INFO, NULL);

    switch (flag)
    {
        case TEST_SCENARIO_SCREEN:
        {
            if (active_scen_id >= notify_scen_id)
            {
                MMI_ASSERT(mmi_frm_is_scenario_started(notify_scen_id));
                MMI_ASSERT(SCR_ID_NMGR_NOTIFY == GetActiveScreenId());
                MMI_ASSERT(show_poup);
                GoBackHistory();
                show_poup = MMI_FALSE;
            }
            else
            {
                MMI_ASSERT(!mmi_frm_is_scenario_started(notify_scen_id));
                MMI_ASSERT(SCR_ID_NMGR_NOTIFY != GetActiveScreenId());
                MMI_ASSERT(!show_poup);
            }
			break;
        }
        case TEST_SCENARIO_SOUND:
        {
            MMI_ASSERT(mmi_frm_is_scenario_started(notify_scen_id));
            if (active_scen_id >= notify_scen_id)
            {
                MMI_ASSERT(play_sound);
                play_sound = MMI_FALSE;
            }
            else
            {
                MMI_ASSERT(!play_sound);
            }
            MMI_ASSERT(SCR_ID_NMGR_NOTIFY == GetActiveScreenId());
            GoBackHistory();
            break;
        }
        case TEST_SCENARIO_VIBRATOR:
        {
            MMI_ASSERT(mmi_frm_is_scenario_started(notify_scen_id));
            if (active_scen_id >= notify_scen_id)
            {
                MMI_ASSERT(play_vibrator);
                play_vibrator = MMI_FALSE;
            }
            else
            {
                MMI_ASSERT(!play_vibrator);
            }
            MMI_ASSERT(SCR_ID_NMGR_NOTIFY == GetActiveScreenId());
            GoBackHistory();
			break;
        }
        case TEST_SCENARIO_BACKLIGHT:
        {
            MMI_ASSERT(mmi_frm_is_scenario_started(notify_scen_id));
            if (active_scen_id >= notify_scen_id)
            {
                MMI_ASSERT(play_backlight);
                play_backlight = MMI_FALSE;
            }
            else
            {
                MMI_ASSERT(!play_backlight);
            }
            MMI_ASSERT(SCR_ID_NMGR_NOTIFY == GetActiveScreenId());
            GoBackHistory();
			break;
        }
        default:
            break;
    }
}


MMI_BOOL mmi_noti_mgr_ut_priority_behavior(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setup_ut_context();
    /* Check screen attribute priority */
    traverse_scenario_priority(SCENARIO_ID_UT_HIGHEST_SCRN, SCENARIO_ID_UT_LOW_SCRN, check_scenario_priority, TEST_SCENARIO_SCREEN);
    /* Check sound attribute priority */
    traverse_scenario_priority(SCENARIO_ID_UT_HIGHEST_SND, SCENARIO_ID_UT_LOW_SND, check_scenario_priority, TEST_SCENARIO_SOUND);
    /* Check vibrator attribute priority */
    traverse_scenario_priority(SCENARIO_ID_UT_HIGH_VIB, SCENARIO_ID_UT_MEDIUM_VIB, check_scenario_priority, TEST_SCENARIO_VIBRATOR);
    /* Check backlight attribute priority */
    traverse_scenario_priority(SCENARIO_ID_UT_HIGH_BL, SCENARIO_ID_UT_MEDIUM_BL, check_scenario_priority, TEST_SCENARIO_BACKLIGHT);

    setup_ut_context();
    return MMI_TRUE;
}


MMI_BOOL mmi_noti_mgr_ut_event_notify_tbl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_events_notify_struct *notify_info = NULL;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Configuration information: (general id is the first)
     * MMI_EVENT_UT_INFO,       MMI_SCENARIO_ID_GENERAL
     * MMI_EVENT_UT_INFO,       MMI_SCENARIO_ID_IN_CALL
     */
    notify_info = mmi_nmgr_get_event_notify_info(MMI_EVENT_UT_INFO, MMI_SCENARIO_ID_POWER_ON);
    MMI_ASSERT(notify_info && notify_info->scenario_id == MMI_SCENARIO_ID_GENERAL);
    notify_info = mmi_nmgr_get_event_notify_info(MMI_EVENT_UT_INFO, MMI_SCENARIO_ID_IN_CALL);
    MMI_ASSERT(notify_info && notify_info->scenario_id == MMI_SCENARIO_ID_IN_CALL);
    /* Configuration information: (general id is the last)
     * MMI_EVENT_UT_QUERY,      SCENARIO_ID_IN_CALL
     * MMI_EVENT_UT_QUERY,      MMI_SCENARIO_ID_POWER_ON
     * MMI_EVENT_UT_QUERY,      MMI_SCENARIO_ID_GENERAL
     */
    notify_info = mmi_nmgr_get_event_notify_info(MMI_EVENT_UT_QUERY, MMI_SCENARIO_ID_IN_CALL);
    MMI_ASSERT(notify_info && notify_info->scenario_id == MMI_SCENARIO_ID_IN_CALL);
    notify_info = mmi_nmgr_get_event_notify_info(MMI_EVENT_UT_QUERY, MMI_SCENARIO_ID_POWER_ON);
    MMI_ASSERT(notify_info && notify_info->scenario_id == MMI_SCENARIO_ID_POWER_ON);
    notify_info = mmi_nmgr_get_event_notify_info(MMI_EVENT_UT_QUERY, MMI_SCENARIO_ID_POWER_OFF);
    MMI_ASSERT(notify_info && notify_info->scenario_id == MMI_SCENARIO_ID_GENERAL);
    /* Configuration information: (general id is in middle)
     * MMI_EVENT_UT_WARNING,        SCENARIO_ID_IN_CALL
     * MMI_EVENT_UT_WARNING,        MMI_SCENARIO_ID_GENERAL
     * MMI_EVENT_UT_WARNING,        MMI_SCENARIO_ID_POWER_ON
     */
    notify_info = mmi_nmgr_get_event_notify_info(MMI_EVENT_UT_WARNING, MMI_SCENARIO_ID_IN_CALL);
    MMI_ASSERT(notify_info && notify_info->scenario_id == MMI_SCENARIO_ID_IN_CALL);
    notify_info = mmi_nmgr_get_event_notify_info(MMI_EVENT_UT_WARNING, MMI_SCENARIO_ID_POWER_ON);
    MMI_ASSERT(notify_info && notify_info->scenario_id == MMI_SCENARIO_ID_POWER_ON);
    notify_info = mmi_nmgr_get_event_notify_info(MMI_EVENT_UT_WARNING, MMI_SCENARIO_ID_POWER_OFF);
    MMI_ASSERT(notify_info && notify_info->scenario_id == MMI_SCENARIO_ID_GENERAL);

    /* If event id isn't registered in table */
    notify_info = mmi_nmgr_get_event_notify_info(MMI_EVENT_TOTAL_NUM, MMI_SCENARIO_ID_IN_CALL);
    MMI_ASSERT(notify_info && notify_info->scenario_id == MMI_SCENARIO_ID_GENERAL && notify_info->event_id == MMI_EVENT_DEFAULT);

	return MMI_TRUE;
}


static void check_attribute_action_status(mmi_scenario_id active_scen_id, mmi_scenario_id noti_scen_id, mmi_event_notify_enum event, mmi_nmgr_behavior_enum action)
{
    mmi_frm_start_scenario(active_scen_id);
    mmi_frm_nmgr_popup(noti_scen_id, event, NULL);
    MMI_ASSERT((scrn_action == (MMI_BEHAVIOR_SCRN_MASK & action)) && (snd_action == (MMI_BEHAVIOR_SND_MASK & action)));
    MMI_ASSERT((vib_action == (MMI_BEHAVIOR_VIB_MASK & action)) && (bl_action == (MMI_BEHAVIOR_BL_MASK & action)));
	GoBackHistory();
    mmi_frm_end_scenario(active_scen_id);
}

MMI_BOOL mmi_noti_mgr_ut_notify_event_atrribute_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setup_ut_context();
    /* MMI_EVENT_UT_ALARM, SCENARIO_ID_IN_CALL,    MMI_BEHAVIOR_SND_SUBTLE */
    check_attribute_action_status(
        MMI_SCENARIO_ID_IN_CALL, SCENARIO_ID_UT_DEFAULT, MMI_EVENT_UT_ALARM, 
        MMI_BEHAVIOR_SCRN_DEFAULT | MMI_BEHAVIOR_SND_SUBTLE | MMI_BEHAVIOR_VIB_DEFAULT | MMI_BEHAVIOR_BL_DEFAULT);

    /* MMI_EVENT_UT_ALARM, MMI_SCENARIO_ID_POWER_ON,   MMI_BEHAVIOR_VIB_SMS */    
    check_attribute_action_status(
        MMI_SCENARIO_ID_POWER_ON, SCENARIO_ID_UT_DEFAULT, MMI_EVENT_UT_ALARM, 
        MMI_BEHAVIOR_SCRN_DEFAULT | MMI_BEHAVIOR_SND_DEFAULT | MMI_BEHAVIOR_VIB_SMS | MMI_BEHAVIOR_BL_DEFAULT);

    /* MMI_EVENT_UT_ALARM, MMI_SCENARIO_ID_POWER_OFF,  MMI_BEHAVIOR_BL_TWINKLE */    
    check_attribute_action_status(
        MMI_SCENARIO_ID_POWER_OFF, SCENARIO_ID_UT_DEFAULT, MMI_EVENT_UT_ALARM, 
        MMI_BEHAVIOR_SCRN_DEFAULT | MMI_BEHAVIOR_SND_DEFAULT | MMI_BEHAVIOR_VIB_DEFAULT | MMI_BEHAVIOR_BL_TWINKLE);

    /* MMI_EVENT_UT_ALARM, MMI_SCENARIO_ID_LOW_BATTERY,MMI_BEHAVIOR_SCRN_NO_DEFER */
    check_attribute_action_status(
        MMI_SCENARIO_ID_LOW_BATTERY, SCENARIO_ID_UT_DEFAULT, MMI_EVENT_UT_ALARM, 
        MMI_BEHAVIOR_SCRN_NO_DEFER | MMI_BEHAVIOR_SND_DEFAULT | MMI_BEHAVIOR_VIB_DEFAULT | MMI_BEHAVIOR_BL_DEFAULT);

    /* MMI_EVENT_UT_ALARM, MMI_SCENARIO_ID_EARPHONE,   MMI_BEHAVIOR_SND_SUBTLE|MMI_BEHAVIOR_VIB_SMS */
    check_attribute_action_status(
        MMI_SCENARIO_ID_EARPHONE, SCENARIO_ID_UT_DEFAULT, MMI_EVENT_UT_ALARM, 
        MMI_BEHAVIOR_SCRN_DEFAULT | MMI_BEHAVIOR_SND_SUBTLE | MMI_BEHAVIOR_VIB_SMS | MMI_BEHAVIOR_BL_DEFAULT);

    /* MMI_EVENT_UT_ALARM, MMI_SCENARIO_ID_AUTO_SYNC,  MMI_BEHAVIOR_SND_SUBTLE|MMI_BEHAVIOR_BL_TWINKLE|MMI_BEHAVIOR_SCRN_NO_DEFER */
    check_attribute_action_status(
        MMI_SCENARIO_ID_AUTO_SYNC, SCENARIO_ID_UT_DEFAULT, MMI_EVENT_UT_ALARM, 
        MMI_BEHAVIOR_SCRN_NO_DEFER | MMI_BEHAVIOR_SND_SUBTLE | MMI_BEHAVIOR_VIB_DEFAULT | MMI_BEHAVIOR_BL_TWINKLE);

    /* MMI_EVENT_UT_ALARM, MMI_SCENARIO_ID_GENERAL,    MMI_BEHAVIOR_GENERAL */
    check_attribute_action_status(
        MMI_SCENARIO_ID_GENERAL, SCENARIO_ID_UT_DEFAULT, MMI_EVENT_UT_ALARM, 
        MMI_BEHAVIOR_SCRN_DEFAULT | MMI_BEHAVIOR_SND_DEFAULT | MMI_BEHAVIOR_VIB_DEFAULT | MMI_BEHAVIOR_BL_DEFAULT);

    //MMI_ASSERT(scenario_list_is_empty());
    setup_ut_context();
	return MMI_TRUE;
}

#ifdef MMI_NOTI_MGR_APP_DRIVE_UT
/* Test driver for other interrupt application */
#include "bluetooth_struct.h"
#include "BTMMIObexGprots.h"
#include "BTMMIBipGprot.h"
#include "BTMMIBip.h"
#include "BTMMIBipScr.h"

static void check_screen_and_scenaio(MMI_BOOL show_screen, U16 scren_id, MMI_BOOL start_scenario, mmi_scenario_id scen_id)
{
    MMI_ASSERT((show_screen) ? (scren_id == GetActiveScreenId()) : (scren_id != GetActiveScreenId()));
    MMI_ASSERT((start_scenario) ? (mmi_frm_is_scenario_started(scen_id)) : (!mmi_frm_is_scenario_started(scen_id)));
}

static void check_defer_action(mmi_scenario_id active_scen_id, U16 noti_screen_id, mmi_scenario_id noti_scen_id, MMI_BOOL could_invoke_defer)
{
    mmi_ret rst;

    disable_invoke_defer_event = MMI_TRUE;
    GoBackHistory();
    MMI_ASSERT(!mmi_frm_is_scenario_started(active_scen_id));
    //MMI_ASSERT(0 == mmi_frm_get_post_event_number());
    disable_invoke_defer_event = MMI_FALSE;
    rst = invoke_notify_defer_notification();
    
    if (could_invoke_defer)
    {
        MMI_ASSERT(MMI_RET_OK == rst);
        check_screen_and_scenaio(MMI_TRUE, noti_screen_id, MMI_TRUE, noti_scen_id);
        if (noti_scen_id == MMI_SCENARIO_ID_BT_ACCESS_REQ)
        {/* Special case: Have to reset BT status before gobackhistory to prevent BT task fatal error. */
            MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_IDLE);
        }
        GoBackHistory();
        MMI_ASSERT(!mmi_frm_is_scenario_started(noti_scen_id));
    }
    else
    {
        MMI_ASSERT(MMI_RET_ERR == rst);
        check_screen_and_scenaio(MMI_FALSE, noti_screen_id, MMI_FALSE, noti_scen_id);
    }
}

static void mmi_noti_mgr_app_it_test_defer(mmi_scenario_id active_scen_id, U16 noti_screen_id, mmi_scenario_id noti_scen_id, void(*app_entry_func)(void), MMI_BOOL need_defer, MMI_BOOL could_invoke_defer)
{
    mmi_app_behavior_struct behavior;

    enter_scenario(active_scen_id);

    compare_scenario_and_get_behavior(active_scen_id, noti_scen_id, &behavior);

    if (app_entry_func)
    {
        app_entry_func();
        if (behavior.scrn_behavior == MMI_NOTI_SCRN_BEHA_NO_DISPLAY)
        {
            check_screen_and_scenaio(MMI_FALSE, noti_screen_id, MMI_FALSE, noti_scen_id);
        }
        else
        {
            check_screen_and_scenaio(MMI_TRUE, noti_screen_id, MMI_TRUE, noti_scen_id);
			GoBackHistory();	/* Exit notify screen */
        }
    }
    if (!need_defer)
    {/* Exit active_scen_id screen */
        GoBackHistory();
    }
    else
    {/* Notify by app, notify scenario has been deferred */
        check_defer_action(active_scen_id, noti_screen_id, noti_scen_id, could_invoke_defer);
    }
}

static void mmi_noti_mgr_app_it_framework(U16 screen_id, mmi_scenario_id scenario_id, void(*app_entry_func)(void), MMI_BOOL need_defer, MMI_BOOL from_idle_scrn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setup_ut_context();
    if (!from_idle_scrn)
    {/* For msdc confirm case, must start from idle screen */
        enter_scenario(SCENARIO_ID_UT_DEFAULT);
    }
    /* Test normal case */
    app_entry_func();
    /* Screen should be shown, scenario should be started */
    check_screen_and_scenaio(MMI_TRUE, screen_id, MMI_TRUE, scenario_id);
    if (scenario_id == MMI_SCENARIO_ID_BT_ACCESS_REQ)
    {/* Special case: Have to reset BT status before gobackhistory to prevent BT task fatal error. */
        MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_IDLE);
    }
    GoBackHistory();

    /* Start high screen priority scenario */
    mmi_noti_mgr_app_it_test_defer(SCENARIO_ID_UT_HIGH_SCRN, screen_id, scenario_id, app_entry_func, need_defer, MMI_TRUE);

    /* Start highest screen priority scenario */
    mmi_noti_mgr_app_it_test_defer(SCENARIO_ID_UT_HIGHEST_SCRN, screen_id, scenario_id, app_entry_func, need_defer, MMI_TRUE);

    /* Start high, then start highest, end highest->can't invoke defer, end high->can invoke defer */
    if (need_defer)
    {
        enter_scenario(SCENARIO_ID_UT_HIGH_SCRN);
        enter_scenario(SCENARIO_ID_UT_HIGHEST_SCRN);
        app_entry_func();
        check_defer_action(SCENARIO_ID_UT_HIGHEST_SCRN, screen_id, scenario_id, MMI_FALSE);
        check_defer_action(SCENARIO_ID_UT_HIGH_SCRN, screen_id, scenario_id, MMI_TRUE);
    }

    //MMI_ASSERT(0 == mmi_frm_get_post_event_number());
    GoBackHistory();
    //MMI_ASSERT(scenario_list_is_empty());
    setup_ut_context();
}


extern void EarphoneConnectHdlr(BOOL is_in);
void mmi_noti_mgr_app_it_earphone_plug_in(void)
{
    EarphoneConnectHdlr(MMI_TRUE);  /* This is static function in GeneralDeviceInterface.c */
}
void mmi_noti_mgr_app_it_earphone_plug_out(void)
{
    EarphoneConnectHdlr(MMI_FALSE);  /* This is static function in GeneralDeviceInterface.c */
}


MMI_BOOL mmi_noti_mgr_ut_drive_earphone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_EARPHONE, mmi_noti_mgr_app_it_earphone_plug_in, MMI_FALSE, MMI_FALSE);
    mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_EARPHONE, mmi_noti_mgr_app_it_earphone_plug_out, MMI_FALSE, MMI_FALSE);

    return MMI_TRUE;
}


#include "fmt_struct.h"
#include "msdc_def.h"
extern void fmgr_main_msdc_plug_in_hdlr(void *info);
static void mmi_noti_mgr_app_it_msdc_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_mmi_msdc_ind_struct fmt_param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmt_param.type = SD_CARD;
    fmt_param.cause = 0;
    fmt_param.drv_num = 0;
    fmt_param.drv_letter[0] = 'E';
    fmgr_main_msdc_plug_in_hdlr((void *)&fmt_param);
}


static void mmi_noti_mgr_app_it_msdc_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_mmi_msdc_ind_struct fmt_param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmt_param.type = SD_CARD;
    fmt_param.cause = 0;
    fmt_param.drv_num = 1;
    fmt_param.drv_letter[0] = SRV_FMGR_CARD_DRV;
    fmgr_main_msdc_plug_in_hdlr((void *)&fmt_param);
}


MMI_BOOL mmi_noti_mgr_ut_drive_memorycard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_MSDC_PLUG, mmi_noti_mgr_app_it_msdc_popup, MMI_FALSE, MMI_FALSE);
    mmi_noti_mgr_app_it_framework(SCR_CONFIRM_SCREEN, MMI_SCENARIO_ID_MSDC_PLUG, mmi_noti_mgr_app_it_msdc_confirm, MMI_TRUE, MMI_TRUE);

	return MMI_TRUE;
}


static void mmi_noti_mgr_app_it_bt_bipr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIPI_STATE_TRANS(MMI_BIPI_STATE_CONNECTED); /* set environment info for BIP */
    mmi_bt_bipr_interrupt_request_hdlr(MMI_BIP_OPT_SCR_CONTINUE_SEND);
}


MMI_BOOL mmi_noti_mgr_ut_drive_bt_bipr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_noti_mgr_app_it_framework(SCR_BIP_NOTY_CONTINUE_SEND, MMI_SCENARIO_ID_BT_ACCESS_REQ, mmi_noti_mgr_app_it_bt_bipr, MMI_TRUE, MMI_FALSE);
    return MMI_TRUE;
}


extern void mmi_syncml_device_remoteinfo_confirm_check(void);
static void mmi_noti_mgr_app_it_syncml_remote_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_syncml_device_remoteinfo_confirm_check();
}

MMI_BOOL mmi_noti_mgr_ut_drive_syncml_remote_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_noti_mgr_app_it_framework(SCR_ID_SYNC_DEV_SYNC_CONFIRM, MMI_SCENARIO_ID_AUTO_SYNC, mmi_noti_mgr_app_it_syncml_remote_info, MMI_TRUE, MMI_FALSE);
    return MMI_TRUE;
}


#include "MMI2syncml_struct.h"
extern void mmi_syncml_report_screen_hdlr(void *param);
static void mmi_noti_mgr_app_it_syncml_report_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_finish_sync_ind_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para.result = SYNCML_LOCAL_DB_FULL;    

    mmi_syncml_report_screen_hdlr((void *)&para);
}

MMI_BOOL mmi_noti_mgr_ut_drive_syncml_report_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_AUTO_SYNC, mmi_noti_mgr_app_it_syncml_report_scrn, MMI_TRUE, MMI_FALSE);
	
    return MMI_TRUE;
}


extern void mmi_syncml_sas_notification_screen_hdlr(void);
static void mmi_noti_mgr_app_it_syncml_sas_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_syncml_sas_notification_screen_hdlr();
}

MMI_BOOL mmi_noti_mgr_ut_drive_syncml_sas_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_noti_mgr_app_it_framework(SCR_ID_SYNC_SAS_NOTIFICATION, MMI_SCENARIO_ID_AUTO_SYNC, mmi_noti_mgr_app_it_syncml_sas_scrn, MMI_TRUE, MMI_FALSE);
	
    return MMI_TRUE;
}

#ifdef SYNCML_DM_SUPPORT
#include "DMTypeDef.h"
extern void mmi_dmui_ps_status_ind_handle(void *msg);
#endif /* SYNCML_DM_SUPPORT */

static void mmi_noti_mgr_app_it_dm_status_disc_scrn(void)
{
#ifdef SYNCML_DM_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_ps_status_ind_struct ptr_ps_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_ps_ind.status = DM_PS_STATUS_DISCONNECTED;
    mmi_dmui_ps_status_ind_handle((void *)&ptr_ps_ind);
#endif /* SYNCML_DM_SUPPORT */
}

static void mmi_noti_mgr_app_it_dm_status_not_enough_mem_scrn(void)
{
#ifdef SYNCML_DM_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_ps_status_ind_struct ptr_ps_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr_ps_ind.status = DM_PS_STATUS_NOT_ENOUGH_MEMORY;
    mmi_dmui_ps_status_ind_handle((void *)&ptr_ps_ind);
#endif /* SYNCML_DM_SUPPORT */
}

MMI_BOOL mmi_noti_mgr_ut_drive_dm_status_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_DM, mmi_noti_mgr_app_it_dm_status_disc_scrn, MMI_TRUE, MMI_FALSE);
    mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_DM, mmi_noti_mgr_app_it_dm_status_not_enough_mem_scrn, MMI_TRUE, MMI_FALSE);

    return MMI_TRUE;
}

#include "BTMMIBppSpGprot.h"
#include "EbrsrvGprot.h"
#include "EbookSrc.h"
#include "EbookProt.h"

static void mmi_noti_mgr_app_it_ebr_null_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ebr_fs_op_error_handler(NULL);
}

static void mmi_noti_mgr_app_it_ebr_disc_full_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EBOOK_V2__
    mmi_ebr_book_convert_error_struct ebr_struct;
#elif
    mmi_ebr_frm_convert_error_struct ebr_struct;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_struct.fs_error = FS_DISK_FULL;
    mmi_ebr_fs_op_error_handler((void *)&ebr_struct);
}

static void mmi_noti_mgr_app_it_ebr_other_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EBOOK_V2__
    mmi_ebr_book_convert_error_struct ebr_struct;
#elif
    mmi_ebr_frm_convert_error_struct ebr_struct;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_struct.fs_error = FS_TIMEOUT;
    mmi_ebr_fs_op_error_handler((void *)&ebr_struct);
}

MMI_BOOL mmi_noti_mgr_ut_drive_ebr_fs_op_err_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ebr_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebr_flag = mmi_ebr_frm_get_send_error_msg_flag();
	mmi_ebr_frm_set_send_error_msg_flag(MMI_FALSE);
    mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_EBR_FS_OP_ERR, mmi_noti_mgr_app_it_ebr_null_scrn, MMI_FALSE, MMI_TRUE);
	mmi_ebr_frm_set_send_error_msg_flag(MMI_FALSE);
	mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_EBR_FS_OP_ERR, mmi_noti_mgr_app_it_ebr_disc_full_scrn, MMI_FALSE, MMI_TRUE);
	mmi_ebr_frm_set_send_error_msg_flag(MMI_FALSE);
	mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_EBR_FS_OP_ERR, mmi_noti_mgr_app_it_ebr_other_scrn, MMI_FALSE, MMI_TRUE);
	mmi_ebr_frm_set_send_error_msg_flag(ebr_flag);

	return MMI_TRUE;
}


#include "EmailAppResDef.h"
extern void mmi_email_emn_error_info_ind(void *inMsg);
typedef enum
{
    EMAIL_EMN_INT_ERROR = 0,
    EMAIL_EMN_INT_SUCC,
    EMAIL_EMN_INT_CONFIRM,
    EMAIL_EMN_INT_TOTAL
} email_emn_interrupt_type;
typedef struct 
{
    LOCAL_PARA_HDR
    U8 int_type;
} mmi_email_emn_show_popup_ind_struct;

static void mmi_noti_mgr_app_it_email_emn_err(void)
{
    mmi_email_emn_show_popup_ind_struct email_struct;

    email_struct.int_type = EMAIL_EMN_INT_ERROR;
    mmi_email_emn_error_info_ind((void *)&email_struct);
}

static void mmi_noti_mgr_app_it_email_emn_confirm(void)
{
    mmi_email_emn_show_popup_ind_struct email_struct;

    email_struct.int_type = EMAIL_EMN_INT_CONFIRM;
    mmi_email_emn_error_info_ind((void *)&email_struct);
}

MMI_BOOL mmi_noti_mgr_ut_drive_email_emn(void)
{
    mmi_noti_mgr_app_it_framework(SCR_ID_EMAIL_EMN_ERROR_INFO, MMI_SCENARIO_ID_EMAIL_EMN_INFO, mmi_noti_mgr_app_it_email_emn_err, MMI_TRUE, MMI_FALSE);
    mmi_noti_mgr_app_it_framework(SCR_ID_EMAIL_CONFIRM_EMN_RET, MMI_SCENARIO_ID_EMAIL_EMN_INFO, mmi_noti_mgr_app_it_email_emn_confirm, MMI_TRUE, MMI_FALSE);

	return MMI_TRUE;
}


#include "JavaAgencyProt.h"
#include "JavaAgencyDef.h"
#include "Jam_msg_handler.h"

static void mmi_noti_mgr_app_it_java_push(void)
{
    mmi_java_push_install_ind_struct *push_install_ind_ptr;

    push_install_ind_ptr = OslMalloc(sizeof(mmi_java_timealarm_push_ind_struct));
    push_install_ind_ptr->push_install_type= -1;
    push_install_ind_ptr->drm_file_path = L"NotificationProt.h";
    mmi_java_recv_push_install_ind((void *)push_install_ind_ptr);
    OslMfree(push_install_ind_ptr);
}

MMI_BOOL mmi_noti_mgr_ut_drive_java_push(void)
{
    mmi_noti_mgr_app_it_framework(SCR_JAVA_PUSH_INSTALL_CONFIRM, MMI_SCENARIO_ID_JAVA_MID_INSTALL, mmi_noti_mgr_app_it_java_push, MMI_TRUE, MMI_FALSE);

    return MMI_TRUE;
}


#include "PoweronChargerProt.h"
#include "PoweronChargerResDef.h"
extern charbat_context_struct g_charbat_context;

static void mmi_noti_mgr_app_it_batter_highest_1(void)
{
    U16 string_id = STR_LOW_BATTERY;

    BatteryIndicationPopup(string_id);
}

static void mmi_noti_mgr_app_it_batter_highest_2(void)
{
    U16 string_id = STR_INVALID_BATTERY;

    if (!mmi_gpio_is_charger_connected())
    {
        g_charbat_context.isChargerConnected = 1;
    }
    ChargingAbnormalHandler(string_id);
}

static void mmi_noti_mgr_app_it_batter_medium(void)
{
    U16 string_id = STR_CHARGER_CONNECTED;

    BatteryIndicationPopup(string_id);
}

MMI_BOOL mmi_noti_mgr_ut_drive_battery_id(void)
{
    mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_BATTERY_HIGHEST, mmi_noti_mgr_app_it_batter_highest_1, MMI_FALSE, MMI_FALSE);
    mmi_noti_mgr_app_it_framework(SCR_ABNORMAL_CHARGING, MMI_SCENARIO_ID_BATTERY_HIGHEST, mmi_noti_mgr_app_it_batter_highest_2, MMI_FALSE, MMI_FALSE);
    mmi_noti_mgr_app_it_framework(SCR_ID_NMGR_NOTIFY, MMI_SCENARIO_ID_BATTERY_MEDIUM, mmi_noti_mgr_app_it_batter_medium, MMI_FALSE, MMI_FALSE);

    return MMI_TRUE;
}

#include "vObjects.h"
MMI_BOOL mmi_noti_mgr_ut_drive_vobject(void)
{ 
    mmi_vobj_receive_ind_prompt(MMI_TRUE, MMI_VOBJ_VCARD, 0);

    return MMI_TRUE;
}

#endif /* MMI_NOTI_MGR_APP_DRIVE_UT */

MMI_BOOL mmi_nmgr_ut_medium_scen(void)
{
    mmi_frm_nmgr_notify_by_app(SCENARIO_ID_UT_DEFAULT, MMI_EVENT_FAILURE, (mmi_noti_scrn_func_ptr)scenario_ut_default_entry, NULL);

    return MMI_TRUE;
}

MMI_BOOL mmi_nmgr_ut_high_scen(void)
{
    mmi_frm_nmgr_notify_by_app(SCENARIO_ID_UT_HIGH_SCRN, MMI_EVENT_FAILURE, (mmi_noti_scrn_func_ptr)scenario_ut_high_entry, NULL);

    return MMI_TRUE;
}

MMI_BOOL mmi_nmgr_ut_highest_scen(void)
{
    mmi_frm_nmgr_notify_by_app(SCENARIO_ID_UT_HIGHEST_SCRN, MMI_EVENT_FAILURE, (mmi_noti_scrn_func_ptr)scenario_ut_highest_entry, NULL);

    return MMI_TRUE;
}

extern oslMsgqid mmi_ext_qid;
void mmi_noti_nmgr_ut_stress(void)
{
    U32 queue_node_number = 0;

    while (1)
    {
        mmi_frm_noti_mgr_test_case_entry(0);

        msg_get_ext_queue_info(mmi_ext_qid, &queue_node_number);
        if ((queue_node_number > 3) || (OslNumOfCircularQMsgs() > 3))
        {
            StartTimer(KEY_TIMER_ID0, 100, mmi_noti_nmgr_ut_stress);
            break;
        }
    }
}


/***************************************************************************** 
 * Basic requirement test cases
 *****************************************************************************/



/*****************************************************************************  
 * Function for test case driven engine
 *****************************************************************************/
typedef MMI_BOOL (*noti_mgr_test_case_fp)(void);

typedef struct
{
    S32 index;
    noti_mgr_test_case_fp test_case_func;
} _noti_mgr_test_case_struct;

static const _noti_mgr_test_case_struct noti_mgr_test_case_db[] =
{
    /* Test all cases */
    {0, NULL},
    {1, mmi_scenario_list_ut},  /* Scenario list is a basic mech. for nmgr! */
    {2, mmi_noti_mgr_ut_popup_scrn},
    {3, mmi_noti_mgr_ut_defer_popup_scrn},
    {4, mmi_noti_mgr_ut_defer_full_scrn},
    {5, mmi_noti_mgr_ut_defer_multi_time},
    {6, mmi_noti_mgr_ut_priority_behavior},
    {7, mmi_noti_mgr_ut_event_notify_tbl},
    {8, mmi_noti_mgr_ut_notify_event_atrribute_action},
#ifdef MMI_NOTI_MGR_APP_DRIVE_UT
    {9, mmi_noti_mgr_ut_drive_earphone},
    {10, mmi_noti_mgr_ut_drive_memorycard},
    {11, mmi_noti_mgr_ut_drive_bt_bipr},
    {12, mmi_noti_mgr_ut_drive_syncml_remote_info},
    {13, mmi_noti_mgr_ut_drive_syncml_report_scrn},
    {14, mmi_noti_mgr_ut_drive_syncml_sas_scrn},
    {15, mmi_noti_mgr_ut_drive_dm_status_scrn},
    {16, mmi_noti_mgr_ut_drive_ebr_fs_op_err_scrn},
    {17, mmi_noti_mgr_ut_drive_email_emn},
    {18, mmi_noti_mgr_ut_drive_java_push},
    {19, mmi_noti_mgr_ut_drive_battery_id},
    {20, mmi_noti_mgr_ut_drive_vobject},
#endif /* MMI_NOTI_MGR_APP_DRIVE_UT */
    {50, mmi_nmgr_ut_medium_scen},
    {51, mmi_nmgr_ut_high_scen},
    {52, mmi_nmgr_ut_highest_scen},
    {-1, NULL}
};


void mmi_frm_nmgr_test_case_timer_hdlr(void *arg)
{
    static U8 idx = 1;

	idx = *(U8 *)arg;
    if (noti_mgr_test_case_db[idx].index > 0 && noti_mgr_test_case_db[idx].test_case_func)
    {
        noti_mgr_test_case_db[idx].test_case_func();
        idx++;
        StartTimerEx(KEY_TIMER_ID0, 0, mmi_frm_nmgr_test_case_timer_hdlr, (void *)&idx);
    }
    else
    {
		idx = 1;
        StopTimer(KEY_TIMER_ID0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_noti_mgr_test_case_entry
 * DESCRIPTION
 * Notification manager test case entry function, could be invoked by catcher inject string
 * in mmi_proc_inject_string (events.c).
 * PARAMETERS
 *  index   [IN]    index for test case
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_frm_noti_mgr_test_case_entry(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == index)
    {
        /* Test all cases */
        mmi_frm_nmgr_test_case_timer_hdlr((void *)&i);
    }
    else if (255 == index)
    {
        mmi_noti_nmgr_ut_stress();
    }
    else
    {
        while (noti_mgr_test_case_db[i].test_case_func)
        {
			if (noti_mgr_test_case_db[i].index == index)
			{
				noti_mgr_test_case_db[i].test_case_func();
				break;
			}
			else
			{
				i++;
			}
        }
    }
}
#endif /* MMI_NOTI_MGR_UT */


