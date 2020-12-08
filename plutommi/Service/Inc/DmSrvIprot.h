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
 *  DmSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service internal prototype header.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __DM_SRV_IPROT_H__
#define __DM_SRV_IPROT_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "MMIDataType.h"
#include "DMTypeDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "CcaSrvGprot.h"

/****************************************************************************
 * Define
 ****************************************************************************/
#define SRV_DM_TIME_SESSION_SUSPEND                     (5*60*1000)
#define SRV_DM_TIME_NOTIFICATION_INFO_DISPLAY_DUR       (4*1000)
#define SRV_DM_TIME_NOTIFICATION_CNF_USER_INTERACTION   (5*60*1000)
#define SRV_DM_TIME_ALERT_DEFAULT_MINDT                 (4*1000)
#define SRV_DM_TIME_ALERT_DEFAULT_MAXDT                 (5*60*1000)
#define SRV_DM_TIME_DL_AUTO_RESUME                      (5*60*1000)
#define SRV_DM_TIME_USER_INTERACTION_DEFER              (30*1000)

#ifdef __OP01__
#define STR_ID_DM_SESSION_NOTIFICATION_INFO STR_ID_DM_SESSION_NOTIFICATION_INFO_CMCC
#define STR_ID_DM_SESSION_NOTIFICATION_USER_INTERACTION STR_ID_DM_SESSION_NOTIFICATION_USER_INTERACTION_CMCC
#elif defined(__OP02__)
#define STR_ID_DM_SESSION_NOTIFICATION_INFO STR_ID_DM_SESSION_NOTIFICATION_INFO_CU
#define STR_ID_DM_SESSION_NOTIFICATION_USER_INTERACTION STR_ID_DM_SESSION_NOTIFICATION_USER_INTERACTION_CU
#else
#define STR_ID_DM_SESSION_NOTIFICATION_INFO             0
#define STR_ID_DM_SESSION_NOTIFICATION_USER_INTERACTION 0
#endif
/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef enum
{
    SRV_DM_APP_ADP_EVT_DISPLAY_NOTIFICATION,
    SRV_DM_APP_ADP_EVT_DISPLAY_ALERT,
    SRV_DM_APP_ADP_EVT_SESSION_ABORT,
    SRV_DM_APP_ADP_EVT_SESSION_FINISH,
    SRV_DM_APP_ADP_EVT_DISPLAY_ENDING_MSG,
    SRV_DM_APP_ADP_EVT_DL_START,
    SRV_DM_APP_ADP_EVT_DL_PROGRESS,
    SRV_DM_APP_ADP_EVT_DL_FINISH,
    SRV_DM_APP_ADP_EVT_FOTA_DISPLAY_UPDATE,
    SRV_DM_APP_ADP_EVT_FOTA_UPDATE_RESULT,
    SRV_DM_APP_ADP_EVT_OTAP_INSTALL_PROF,
    SRV_DM_APP_ADP_EVT_DISPLAY_NMGR_POPUP,
    SRV_DM_APP_ADP_EVT_TOTAL
} srv_dm_app_adp_evt_enum;

typedef enum
{
    SRV_DM_APP_ADP_SESSION_ENDING_MSG_NONE,
    SRV_DM_APP_ADP_SESSION_ENDING_MSG_TIMEOUT,
    SRV_DM_APP_ADP_SESSION_ENDING_MSG_SESSION_FAIL,
    SRV_DM_APP_ADP_SESSION_ENDING_MSG_NO_MEM,
    SRV_DM_APP_ADP_SESSION_ENDING_MSG_TOTAL
} srv_dm_app_adp_session_ending_msg_enum;

typedef enum
{
    SRV_DM_APP_ADP_DL_FINISH,
    SRV_DM_APP_ADP_DL_CANCEL,
    SRV_DM_APP_ADP_DL_NO_MEM,
    SRV_DM_APP_ADP_DL_NW_UNAVAIL,
    SRV_DM_APP_ADP_DL_END
} srv_dm_app_adp_dl_finish_cause_enum;

typedef enum
{
    SRV_DM_FOTA_UPDATE_DEFER_TIME_1_HOUR,
    SRV_DM_FOTA_UPDATE_DEFER_TIME_2_HOUR,
    SRV_DM_FOTA_UPDATE_DEFER_TIME_4_HOUR,
    SRV_DM_FOTA_UPDATE_DEFER_TIME_24_HOUR,
    SRV_DM_FOTA_UPDATE_DEFER_TIME_TOTAL
} srv_dm_fota_update_defer_time_enum;

typedef struct
{
    srv_dm_app_adp_evt_enum evt_id;
    void *arg;
} srv_dm_app_adp_evt_struct;

typedef void(*srv_dm_app_adp_cb)(srv_dm_app_adp_evt_struct *evt);

/* SRV_DM_APP_ADP_EVT_DISPLAY_NOTIFICATION */
typedef struct
{
    dm_ui_mode_enum ui_mode;
} srv_dm_app_adp_evt_display_notification_struct;

/* SRV_DM_APP_ADP_EVT_DISPLAY_ALERT */
typedef struct
{
    dm_alert_struct *alert;
} srv_dm_app_adp_evt_display_alert_struct;

/* SRV_DM_APP_ADP_EVT_DISPLAY_ENDING_MSG */
typedef struct
{
    srv_dm_app_adp_session_ending_msg_enum ending_msg;
} srv_dm_app_adp_evt_display_ending_msg_struct;

/* SRV_DM_APP_ADP_EVT_DL_START */
typedef struct
{
    MMI_BOOL is_resume;
    MMI_BOOL auto_resume;
} srv_dm_app_adp_evt_dl_start_struct;

/* SRV_DM_APP_ADP_EVT_DL_PROGRESS */
typedef struct
{
    U32 acc_size;
    U32 total_size;
} srv_dm_app_adp_evt_dl_progress_struct;

/* SRV_DM_APP_ADP_EVT_DL_FINISH */
typedef struct
{
    srv_dm_app_adp_dl_finish_cause_enum cause;
} srv_dm_app_adp_evt_dl_finish_struct;

/* SRV_DM_APP_ADP_EVT_FOTA_UPDATE_RESULT */
typedef struct
{
    MMI_BOOL result;
} srv_dm_app_adp_evt_fota_update_result_struct;

/* SRV_DM_APP_ADP_EVT_FOTA_DISPLAY_UPDATE */
typedef struct
{
    dm_ui_mode_enum ui_mode;
} srv_dm_app_adp_evt_fota_display_update_struct;

/* SRV_DM_APP_ADP_EVT_DISPLAY_NMGR_POPUP */
typedef struct
{
    mmi_scenario_id scenario_id;
    mmi_event_notify_enum type;
    WCHAR* string;
} srv_dm_app_adp_evt_display_nmgr_popup_struct;

typedef struct
{
    srv_dm_app_adp_cb app_adp_cb;
} srv_dm_app_adp_cntx;


/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern void srv_dm_app_adp_reg_cb(srv_dm_app_adp_cb cb);
extern void srv_dm_app_adp_send_evt(srv_dm_app_adp_evt_enum evt_id, void *arg);
extern void srv_dm_dl_start_app_rsp(dm_ui_interaction_enum result);
extern U32 srv_dm_dl_get_curr_percent(void);
extern void srv_dm_dl_progress_app_rsp(dm_dl_status_enum status);
extern void srv_dm_fota_update_app_rsp(dm_ui_interaction_enum result, U32 defer_time);
extern MMI_BOOL srv_dm_session_alert_get_option_val(U32 mask, void *val);
extern WCHAR* srv_dm_session_alert_get_display_str_ptr(void);
extern void srv_dm_session_notification_app_rsp(dm_ui_interaction_enum result);
extern void srv_dm_session_alert_app_rsp(dm_alert_rsp_struct *alert_rsp);
extern U8* srv_dm_otap_get_curr_prof_server_id(void);
extern U8* srv_dm_otap_get_curr_prof_server_addr(void);
extern U8 srv_dm_otap_get_curr_prof_iter(void);
extern S32 srv_dm_otap_get_curr_valid_prof_num(void);
extern U8 srv_dm_otap_get_valid_prof_num(void);
extern MMI_BOOL srv_dm_otap_check_curr_prof_is_to_udpate(void);
extern void srv_dm_otap_install_prof_app_rsp(srv_cca_status_enum status);

#endif /* __DM_SRV_IPROT_H__ */
