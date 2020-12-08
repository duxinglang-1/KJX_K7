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
 *  UCMProt.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM app internal header file
 *
 * Author:
 * -------
 * -------
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef UCM_PROT_H
#define UCM_PROT_H

/* Include files---------------------------------------------------------------------------- */

#include "MMI_features.h"
#if defined(__MMI_UCM_AUTO_ANSWER_NOTIFICATION__)
#include "mdi_datatype.h"
#endif /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */

#ifdef __MMI_VIDEO_TELEPHONY__
#include "App_datetime.h" /* time related */
#endif /*__MMI_VIDEO_TELEPHONY__*/

#include "UcmCoreProt.h"
#include "UcmSrvGprot.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "wgui_categories_list.h"
#include "custom_mmi_default_value.h"
#include "UCMGProt.h"
#include "app_datetime.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "AlertScreen.h"
#include "SensorSrvGport.h"

/* Define----------------------------------------------------------------------------------- */
#define MMI_UCM_VIB_THEN_RING_DURATION          6000 /* move from profile module */
#define MMI_UCM_DTMF_LEN                        (40)
#define MMI_UCM_END_TEXT_LEN                    (50)

/* call cost display for category */
#define MMI_UCM_CALL_COST_UNIT_DIGITS                   (2)       
#define MMI_UCM_CALL_COST_COST_DIGITS                   (10)  
#define MMI_UCM_CALL_TYPE_WO_INCALL_SCR    (SRV_UCM_CSD_CALL_TYPE_ALL)

/* typedef enum----------------------------------------------------------------------------- */

typedef enum
{
    MMI_UCM_NONE = 0,
    MMI_UCM_RING_TONE,
    MMI_UCM_WAITING_TONE,
    MMI_UCM_INCOMING_TONE_TOTAL
} mmi_ucm_incoming_tone_enum;

#ifdef __MMI_VIDEO_TELEPHONY__

#define MMI_UCM_VT_POPUP_TIME_OUT               (UI_POPUP_NOTIFYDURATION_TIME_2000)
#define MMI_UCM_VT_DEFAULT_EV                   (MMI_VT_EV_0) 
#define MMI_UCM_VT_DEFAULT_VOLUME               (MMI_VT_VOL_3) 
#define MMI_UCM_VT_DEFAULT_ZOOM                 (0)
#define MMI_UCM_VT_START_CAMERA_QUERY_TIMEOUT   (2000)
#define MMI_UCM_VT_DTMF_LEN                     (40)

typedef enum
{
    MMI_UCM_VT_ANSWER_MODE_PROMPT,
    MMI_UCM_VT_ANSWER_MODE_START_CAMERA,
    MMI_UCM_VT_ANSWER_MODE_STOP_CAMERA,
    MMI_UCM_VT_ANSWER_MODE_END_OF_ENUM
} mmi_ucm_vt_answer_mode_enum;

typedef enum
{
    MMI_UCM_VT_DIAL_MODE_START_CAMERA,
    MMI_UCM_VT_DIAL_MODE_STOP_CAMERA,
    MMI_UCM_VT_DIAL_MODE_END_OF_ENUM
} mmi_ucm_vt_dial_mode_enum;
typedef enum
{
    MMI_UCM_VT_AUTO_REDIAL_MODE_MANUAL, 
    MMI_UCM_VT_AUTO_REDIAL_MODE_ON,
    MMI_UCM_VT_AUTO_REDIAL_MODE_OFF,
    MMI_UCM_VT_AUTO_REDIAL_MODE_END_OF_ENUM
} mmi_ucm_vt_auto_redial_mode_enum;

typedef enum
{
    MMI_UCM_VT_AUDIO_OPTION_MIC_OFF,
    MMI_UCM_VT_AUDIO_OPTION_SPEAKER_OFF,
    MMI_UCM_VT_AUDIO_OPTION_TOTAL_NUM
} mmi_ucm_vt_audio_option_enum;

typedef enum
{
    MMI_UCM_VT_INCALL_SCREEN_MODE_NONE,
    MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL,
    MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY,
    MMI_UCM_VT_INCALL_SCREEN_MODE_END_OF_ENUM
} mmi_ucm_vt_incall_screen_mode_enum;

typedef enum
{
    MMI_UCM_VT_INCALL_PIC_STATUS_BUILT_IN,
    MMI_UCM_VT_INCALL_PIC_STATUS_FILE,
    MMI_UCM_VT_INCALL_PIC_STATUS_END_OF_ENUM
} mmi_ucm_vt_incall_pic_status_enum;

typedef enum
{
    MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER = 0,    /* Pic is for lcoal user to instead of its video */
    MMI_UCM_VT_INCALL_PIC_TYPE_REMOTE_USER,       /* Pic is for remote user to instead of its video*/ 
    MMI_UCM_VT_INCALL_PIC_TYPE_END_OF_ENUM
}mmi_ucm_vt_incall_pic_type_enum;

/* typedef struture------------------------------------------------------------------------- */

typedef enum
{
    MMI_VT_EV_N4 = 0,
    MMI_VT_EV_N3,
    MMI_VT_EV_N2,
    MMI_VT_EV_N1,
    MMI_VT_EV_0,
    MMI_VT_EV_P1,
    MMI_VT_EV_P2,
    MMI_VT_EV_P3,    
    MMI_VT_EV_P4,
    MMI_VT_EV_TOTAL
} mmi_vt_ev_enum;

typedef enum
{
    MMI_VT_VOL_0 = 0,
    MMI_VT_VOL_1,
    MMI_VT_VOL_2,
    MMI_VT_VOL_3,
    MMI_VT_VOL_4,
    MMI_VT_VOL_5,
    MMI_VT_VOL_6,    
    MMI_VT_VOL_TOTAL
} mmi_vt_vol_enum;

typedef enum
{
    /* TODO: can add more if needed */
    MMI_VT_ZOOM_10X = 0,
    MMI_VT_ZOOM_15X,
    MMI_VT_ZOOM_20X,
    MMI_VT_ZOOM_25X,
    MMI_VT_ZOOM_30X,
    MMI_VT_ZOOM_35X,
    MMI_VT_ZOOM_40X,
    MMI_VT_ZOOM_TOTAL
} mmi_vt_zoom_enum;

typedef enum
{
    MMI_VT_NIGHT_MODE_OFF,
    MMI_VT_NIGHT_MODE_ON,
    MMI_VT_NIGHT_MODE_ENUM
} mmi_vt_night_mode;

typedef struct
{
    U16 curr_hilite_index;
    MMI_BOOL is_camera_on;
    MMI_BOOL is_main_camera; 
    MMI_BOOL is_mic_on;
    MMI_BOOL is_speaker_on;
    MMI_BOOL is_image_switch;
    MMI_BOOL is_small_region_hide;
    MMI_BOOL is_mirror;
    MMI_BOOL is_hand_free;
    mmi_vt_night_mode night_mode;
    mmi_vt_ev_enum ev;
    mmi_vt_vol_enum volume;
    U16 zoom_step;
    mmi_ucm_vt_incall_screen_mode_enum mode;
} mmi_ucm_vt_incall_screen_struct;

/* [UCM3.0] can change to U16 */
typedef struct
{
    U16 dial_pad_buffer[SRV_UCM_MAX_NUM_URI_LEN + 1];
} mmi_ucm_vt_dial_info_struct;

typedef struct
{
    U16  incall_image_file_path[MMI_UCM_VT_INCALL_PIC_TYPE_END_OF_ENUM][NVRAM_EF_VT_SETTING_SIZE / ENCODING_LENGTH]; /* UCS2 with NULL terminator */
    U16 curr_hilite_index;
    mmi_ucm_vt_answer_mode_enum answer_mode;
    mmi_ucm_vt_dial_mode_enum dial_mode;
    mmi_ucm_vt_auto_redial_mode_enum auto_redial_mode;
    U8 audio_opt[MMI_UCM_VT_AUDIO_OPTION_TOTAL_NUM]; /* used for category */
    MMI_BOOL is_mic_off;
    MMI_BOOL is_speaker_off;
}mmi_ucm_vt_setting_struct;

typedef struct
{
    mmi_ucm_vt_incall_screen_struct incall_screen;
    mmi_ucm_vt_dial_info_struct mo_info;
    mmi_ucm_vt_setting_struct setting;
} mmi_ucm_vt_cntx_struct;

#endif /* __MMI_VIDEO_TELEPHONY__ */

typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    U16 currency_symbol[(MMI_UCM_CALL_COST_UNIT_DIGITS + 1)]; /* Currency symbol, ex: TWD, USD */
    U16 total_cost_unit[(MMI_UCM_CALL_COST_COST_DIGITS + 1)]; /* Total unit spent */
} mmi_ucm_call_cost_cntx_struct;

typedef struct
{
    /* [UCM3.0] can change to U16 */
    U16 dial_pad_buffer[SRV_UCM_MAX_NUM_URI_LEN + 1];
    srv_ucm_module_origin_enum module_id;
    srv_ucm_call_type_enum dial_type;
    srv_ucm_call_type_enum highlight_dial_type;
#if (MMI_MAX_SIM_NUM >= 3)
    S32 dial_type_count;
#endif /* (MMI_MAX_SIM_NUM >= 3) */
    /* [UCM3.0] naming this as remote_info */
    srv_ucm_remote_info_struct dial_num;  
    MMI_BOOL is_ip_dial;
    mmi_ucm_after_make_call_callback callback;
    void* callback_para;
    void *phb_data; /* Bypass phonebook data for call service to query caller info */
} mmi_ucm_dial_info_struct;

typedef struct
{
    MMI_ID scrn_id;
    srv_ucm_cnf_callback_func_ptr conf_ind_cb;
    U16 *content;
} mmi_ucm_display_cnf_struct;

typedef struct
{
    S32 hilite_tab;
    S32 hilite_index;
    srv_ucm_index_info_struct index_list[SRV_UCM_MAX_CALL]; /* Only used by ucm app */
    srv_ucm_call_type_enum sendkeys_makecall_dial_type;
    mmi_ucm_incoming_tone_enum play_tone; /* Current playing tone */
    MMI_BOOL is_dtmf;
    MMI_BOOL is_ringtone_suppress;
    MMI_BOOL is_dtmf_start;
    MMI_BOOL get_alert_ind;
} mmi_ucm_call_misc_struct;

typedef struct
{
    srv_ucm_display_info_struct mo_mt_display;
    srv_ucm_res_type_enum res_type; /* for stop incoming...etc */
    U16 line_icon; 
    U16 num_type_icon; /* Number type icon image id or 0 for none */
}mmi_ucm_full_display_info_struct;

typedef struct
{
    mmi_ucm_call_misc_struct call_misc;
    mmi_ucm_dial_info_struct mo_info;
    mmi_ucm_full_display_info_struct full_mo_mt_display; /* Information for MO and MT call screen */
    mmi_ucm_display_cnf_struct cnf_scr; /* For VT confirm */
    mmi_ucm_call_cost_cntx_struct call_cost;
    srv_ucm_auto_redial_ind_struct auto_redial;
#ifdef __MMI_VIDEO_TELEPHONY__
    mmi_ucm_vt_cntx_struct vt_cntx;
#endif /*__MMI_VIDEO_TELEPHONY__*/
    U16 call_end_tone_id;
    U32 bt_srvHd;
#ifdef __MMI_BT_SUPPORT__
    S32 bt_audio_id;
#endif /* __MMI_BT_SUPPORT__ */
} mmi_ucm_cntx_struct;

#ifdef __IP_NUMBER__
typedef struct
{
	S16 group_id;
	U16 g_ip_num[SRV_UCM_MAX_IP_NUMBER_LEN + 1];
} mmi_ucm_ip_dial_struct;
#endif /*__IP_NUMBER__*/

extern mmi_ucm_cntx_struct *g_ucm_p;
extern void mmi_ucm_auto_quick_end(void);

/* ==================================================================================== */
/* ============= VT Core related====================================================== */
/* ==================================================================================== */ 
#ifdef __MMI_VIDEO_TELEPHONY__ 
extern void mmi_ucm_vt_init(void);
extern void mmi_ucm_vt_init_setting(void);
extern void mmi_ucm_vt_init_incall_setting(void);
extern mmi_ucm_vt_answer_mode_enum mmi_ucm_vt_get_answer_mode(void);
extern void mmi_ucm_vt_set_answer_mode(mmi_ucm_vt_answer_mode_enum status);
extern mmi_ucm_vt_dial_mode_enum mmi_ucm_vt_get_dial_mode(void);
extern void mmi_ucm_vt_set_dial_mode(mmi_ucm_vt_dial_mode_enum status);
extern MMI_BOOL mmi_ucm_vt_get_camera_status(void);
extern void mmi_ucm_vt_set_camera_status(MMI_BOOL status);
extern void mmi_ucm_vt_set_main_camera_status(MMI_BOOL status);
extern MMI_BOOL mmi_ucm_vt_get_main_camera_status(void);
extern MMI_BOOL mmi_ucm_vt_get_mic_status(void);
extern void mmi_ucm_vt_set_mic_status(MMI_BOOL status);
extern MMI_BOOL mmi_ucm_vt_get_speaker_status(void);
extern void mmi_ucm_vt_set_speaker_status(MMI_BOOL status);
extern MMI_BOOL mmi_ucm_vt_get_pic_switch_status(void);
extern void mmi_ucm_vt_set_pic_switch_status(MMI_BOOL status);
extern MMI_BOOL mmi_ucm_vt_get_hide_small_pic_status(void);
extern void mmi_ucm_vt_set_hide_small_pic_status(MMI_BOOL status);
extern U16* mmi_ucm_vt_get_file_name(U16* file_path);
extern void mmi_ucm_vt_set_incall_pic(U16* file_path, mmi_ucm_vt_incall_pic_type_enum pic_type);
extern mmi_ucm_vt_incall_pic_status_enum mmi_ucm_vt_get_incall_pic(U16* default_pic_id, CHAR** file_unicode_str_ptr, mmi_ucm_vt_incall_pic_type_enum pic_type);
extern mmi_ucm_vt_incall_screen_mode_enum mmi_ucm_vt_get_incall_screen_mode(void);
extern void mmi_ucm_vt_set_incall_screen_mode(mmi_ucm_vt_incall_screen_mode_enum mode);
#endif /*__MMI_VIDEO_TELEPHONY__*/

/* ==================================================================================== */
/* =============Initialization========================================================= */
/* ==================================================================================== */
extern void mmi_ucm_init_context(void);

/* ==================================================================================== */
/* =============UI Tone related======================================================== */
/* ==================================================================================== */
extern void mmi_ucm_play_incoming_tone(void);
extern void mmi_ucm_stop_incoming_tone(void);
extern void mmi_ucm_play_ringtone(void);
extern void mmi_ucm_stop_ringtone(void);
extern void mmi_ucm_play_tone_after_vibration(void);
extern void mmi_ucm_suppress_incoming_tone(void);

/* ==================================================================================== */
/* =============UI ind/act/cnf ind hdlr================================================ */
/* ==================================================================================== */
 
extern mmi_ret mmi_ucm_act_callback(mmi_event_struct *event);
extern void mmi_ucm_exec_dial_cb(srv_ucm_result_info_struct *dial_result_info);
extern void mmi_ucm_exec_dial_cb_by_result(srv_ucm_result_enum result);

#endif /* UCM_PROT_H */ 

