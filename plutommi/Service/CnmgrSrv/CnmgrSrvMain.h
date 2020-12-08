/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  CnmgrSrvMain.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This is the internal header file of connection management service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CNMGR_SRV_MAIN_H
#define CNMGR_SRV_MAIN_H

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"

#include "CnmgrSrvGprot.h"
#include "CnmgrSrvIprot.h"

#include "cbm_consts.h"
#include "ps_public_enum.h"

#include "CnmgrSrvFeature.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/* Maximum number of backup bearers */
#if (SRV_CNMGR_MAX_BEARER_NUM >= 1)
#define SRV_CNMGR_MAX_BACKUP_BEARER_NUM     ((SRV_CNMGR_MAX_BEARER_NUM + 1) / 2)
#else
#define SRV_CNMGR_MAX_BACKUP_BEARER_NUM     (1)
#endif /* SRV_CNMGR_MAX_BEARER_NUM >= 1 */

/* Maximum number of supported dial-up contexts */
#if (MAX_EXT_PDP_CONTEXT >= 1)
#define SRV_CNMGR_MAX_DIALUP_NUM            (MAX_EXT_PDP_CONTEXT)
#else
#define SRV_CNMGR_MAX_DIALUP_NUM            (1)
#endif /* MAX_EXT_PDP_CONTEXT >= 1 */

/* The trace group of CNMGR service */
#define SRV_CNMGR_TRC_GROUP                 MMI_CONN_TRC_INFO

/* Maximum request id */
#define SRV_CNMGR_MAX_REQ_ID                (2147483646)

/* Maximum number of supported bearer types (srv_cnmgr_bearer_type_enum: CSD, GPRS, SIM_PS, WIFI) */
#define SRV_CNMGR_MAX_SUPPORT_BEARER_TYPE   (4)

/* Maximum number of supported request */
#define SRV_CNMGR_MAX_CONNECT_DATA_REQ      (SRV_CNMGR_MAX_SUPPORT_APP_NUM * SRV_CNMGR_SIM_TOTAL * SRV_CNMGR_MAX_SUPPORT_BEARER_TYPE)

/* One second */
#define SRV_CNMGR_INTERNAL_TIMER_INTERVAL   (1000)

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
/* Maximum number of supported request */
#define SRV_CNMGR_MAX_SUPPORT_SCRI_REQ      (5)

/* Change app state */
#define SRV_CNMGR_ENTER_STATE(_STATE_, _NEW_STATE_)   \
    do {                                                                    \
        (_STATE_) = (_NEW_STATE_);                                      \
        MMI_TRACE(SRV_CNMGR_TRC_GROUP, SRV_CNMGR_ENTER_STATE_MSG, (_NEW_STATE_), (__LINE__));    \
    } while(0);

/* Maximum bearer status check interval */
#define SRV_CNMGR_MAX_BEARER_STATUS_CHECK_TIME  (5)
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */

#ifdef __USB_TETHERING__
#define SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM   (2)
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* Internal bearer state */
typedef enum
{
    SRV_CNMGR_BEARER_STATE_ACTIVE,
    SRV_CNMGR_BEARER_STATE_DEACTIVE
} srv_cnmgr_bearer_state_enum;

/* CNMGR SIM id */
typedef enum
{
    SRV_CNMGR_SIM_ID_1 = 0,
    SRV_CNMGR_SIM_ID_2,
    SRV_CNMGR_SIM_ID_3,
    SRV_CNMGR_SIM_ID_4,
    SRV_CNMGR_SIM_ID_TOTAL
} srv_cnmgr_sim_id_enum;

/* CNMGR NVRAM data type */
typedef enum
{
    SRV_CNMGR_NVRAM_DATA_LOCAL_CSD = 1,
    SRV_CNMGR_NVRAM_DATA_LOCAL_GPRS,
    SRV_CNMGR_NVRAM_DATA_LOCAL_TOTAL,
    SRV_CNMGR_NVRAM_DATA_DIALUP,
    SRV_CNMGR_NVRAM_DATA_WIFI,
    SRV_CNMGR_NVRAM_DATA_TOTAL
} srv_cnmgr_nvram_data_enum;

#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
/* CNMGR SCRI state */
typedef enum
{
    SRV_CNMGR_SCRI_STATE_IDLE = 0,
    SRV_CNMGR_SCRI_STATE_WAITING,
    SRV_CNMGR_SCRI_STATE_MONITORING,
    SRV_CNMGR_SCRI_STATE_GETTING_PCH_STATUS,
    SRV_CNMGR_SCRI_STATE_ENDING_PS_DATA_SESSION,
    SRV_CNMGR_SCRI_STATE_TOTAL
} srv_cnmgr_scri_state_enum;

/* This structure is used to record the period of time for sending SCRI */
typedef struct
{
    U32 id;
    U32 interval;
} srv_cnmgr_scri_req_struct;
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */

#ifdef __MMI_CBM_CONNECTION_MANAGER__
/* This structure is used for bearer data notify request */
typedef struct
{
    U32                                 interval;
    srv_cnmgr_notify_cb_funcptr_type    cb_func;
    void                                *user_data;
    MMI_BOOL                            is_used;
} srv_cnmgr_bearer_data_notify_struct;

/* This structure is used for disconnecting all connection request */
typedef struct
{
    srv_cnmgr_cb_funcptr_type   cb_func;
    void                        *user_data;
} srv_cnmgr_disc_all_req_struct;

/* This structure is used for disconnecting connection request */
typedef struct
{
    U32                         profile_id;
    srv_cnmgr_cb_funcptr_type   cb_func;
    void                        *user_data;
    U8                          connect_type;
    U8                          real_acct;
} srv_cnmgr_disc_req_struct;
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */

/* This structure is used for gettting connection data request */
typedef struct
{
    srv_cnmgr_connect_data_query_struct     query;
    srv_cnmgr_connect_data_cb_funcptr_type  cb_func;
    void                                    *user_data;
    MMI_BOOL                                is_used;
} srv_cnmgr_get_connect_data_req_struct;

/* This structure is used for connection data reset request */
typedef struct
{
    srv_cnmgr_reset_data_req_struct         req;
    srv_cnmgr_reset_data_cb_funcptr_type    cb_func;
    void                                    *user_data;
} srv_cnmgr_reset_data_req_detail_struct;

/* This structure is used for connection data notify request */
typedef struct
{
    U32                                             interval;
    srv_cnmgr_connect_data_notify_cb_funcptr_type   cb_func;
    void                                            *user_data;
    MMI_BOOL                                        is_used;
} srv_cnmgr_connect_data_notify_req_struct;

/* This strucutre is used identify bearer */
typedef struct
{
    U32                         profile_id;
    srv_cnmgr_bearer_type_enum  bearer_type;
    cbm_sim_id_enum             sim_id;
} srv_cnmgr_tcpip_active_temp_data_struct;

/* This structure is used to calculate and record connection data */
typedef struct
{
    U32 last_session_gprs_profile_id_order[SRV_CNMGR_MAX_BEARER_NUM];
    U32 last_session_profile_id_order[SRV_CNMGR_MAX_BEARER_NUM];
    U32 last_session_context_id_order[SRV_CNMGR_MAX_DIALUP_NUM];
    U32 gprs_last_session_profile_id;
    U32 last_session_context_id;
    U32 last_session_profile_id;
#ifdef __TCPIP_OVER_CSD__
    U32 csd_last_session_profile_id;
    srv_cnmgr_connect_data_detail_struct    local_csd_data;
#endif
    srv_cnmgr_connect_data_detail_struct    local_gprs_data;
    srv_cnmgr_connect_data_detail_struct    local_total_data;
    srv_cnmgr_connect_data_detail_struct    dialup_data;
    U8  tcpip_active_bearer_num;
    U8  tcpip_gprs_active_bearer_num;
} srv_cnmgr_history_connect_data_struct;

/* This structure is used to calculate and record connection data */
typedef struct
{
    srv_cnmgr_history_connect_data_struct   history_connect_data[SRV_CNMGR_SIM_TOTAL]; 
    srv_cnmgr_tcpip_active_temp_data_struct tcpip_active_temp_data[SRV_CNMGR_MAX_BEARER_NUM];
#ifdef __MMI_WLAN_FEATURES__
    srv_cnmgr_connect_data_detail_struct    local_wifi_data;
    U32 wifi_last_session_profile_id;
#endif
    U8  dialup_active_bearer_num;
    U8  tcpip_active_bearer_num;
} srv_cnmgr_history_connect_data_context_struct;

/* This structure is used to calculate connection data at runtime */
typedef struct
{
#ifdef __TCPIP_OVER_CSD__
    srv_cnmgr_connect_data_detail_struct    local_csd_data[SRV_CNMGR_SIM_TOTAL];
#endif
    srv_cnmgr_connect_data_detail_struct    local_gprs_data[SRV_CNMGR_SIM_TOTAL];
    srv_cnmgr_connect_data_detail_struct    local_total_data[SRV_CNMGR_SIM_TOTAL];
    srv_cnmgr_connect_data_detail_struct    dialup_data[SRV_CNMGR_SIM_TOTAL];
#ifdef __MMI_WLAN_FEATURES__
    srv_cnmgr_connect_data_detail_struct    local_wifi_data;
#endif
} srv_cnmgr_runtime_connect_data_context_struct;

/* Detailed bearer data */
typedef struct
{
    U64 send_data_size;
    U64 recv_data_size;
    U64 all_data_size;
    U64 down_speed;
    U64 up_speed;
    U64 curr_send_data_size;
    U64 curr_recv_data_size;
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    U32 update_time;
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    U64      last_recv_for_nwinfo;
    U64      last_send_for_nwinfo;
    MMI_BOOL up_flag;
    MMI_BOOL down_flag;
#endif /* __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
} srv_cnmgr_bearer_detail_struct;

/* Bearer context structure */
typedef struct
{
    U64                             connect_time;
    U32                             profile_id;
    U8                              sim_id;         /* cbm_sim_id_enum */
    U8                              dialup_type;    /* l4c_dialup_bearer_enum */
    MMI_BOOL                        disconnecting;
    MMI_BOOL                        valid;
    MMI_BOOL                        need_acc;
    MMI_BOOL                        need_update;
    MMI_BOOL                        not_display;
    srv_cnmgr_connect_type_enum     connect_type;
    srv_cnmgr_bearer_status_enum    bearer_status;
    srv_cnmgr_bearer_type_enum      bearer_type;
    srv_cnmgr_bearer_detail_struct  detail;
} srv_cnmgr_bearer_context_struct;

#ifdef __USB_TETHERING__
typedef struct
{
    U8                              profile_id;
    srv_cnmgr_bearer_status_enum    bearer_status;
    MMI_BOOL                        valid;
} srv_cnmgr_real_bearer_struct;

typedef struct
{
    U64                             connect_time;
    U64                             send_data_size;
    U64                             recv_data_size;
    U64                             all_data_size;
    U64                             down_speed;
    U64                             up_speed;
    U8                              profile_id;
    U8                              sim_id;         /* cbm_sim_id_enum */
    U8                              dialup_type;    /* l4c_dialup_bearer_enum */
    U8                              count;
    srv_cnmgr_connect_type_enum     connect_type;
    srv_cnmgr_bearer_status_enum    bearer_status;
    srv_cnmgr_bearer_type_enum      bearer_type;
    srv_cnmgr_real_bearer_struct    real_bearer[SRV_CNMGR_MAX_CONCURRENT_ACCT_NUM];
} srv_cnmgr_merged_bearer_data_struct;
#endif /* __USB_TETHERING__ */

/* CNMGR Service context structure */
typedef struct
{
#ifdef __MMI_CBM_CONNECTION_MANAGER__
    srv_cnmgr_bearer_data_notify_struct         bearer_data_notify[SRV_CNMGR_MAX_SUPPORT_APP_NUM];
    srv_cnmgr_disc_all_req_struct               disc_all_req;
    srv_cnmgr_disc_req_struct                   disc_req;
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */
#ifdef __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__
    srv_cnmgr_get_connect_data_req_struct       get_connect_data_req_list[SRV_CNMGR_MAX_CONNECT_DATA_REQ];
    srv_cnmgr_reset_data_req_detail_struct      reset_data_req;
    srv_cnmgr_connect_data_notify_req_struct    connect_data_notify_list[SRV_CNMGR_MAX_SUPPORT_APP_NUM];
#endif /* __MMI_CNMGR_BEARER_DETAIL_INFO_SUPPRT__ */
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    srv_cnmgr_scri_req_struct                   scri_req_list[SRV_CNMGR_SCRI_CHECK_TIMER_TOTAL][SRV_CNMGR_MAX_SUPPORT_SCRI_REQ];
    U32                                         scri_check_interval[SRV_CNMGR_SCRI_CHECK_TIMER_TOTAL];
    U8                                          scri_state;
    U8                                          scri_retry_num;
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
    U32                                         nvram_count;
    U32                                         bearer_data_update_interval;
    U32                                         get_bearer_info_wait_count;
    U8                                          get_bearer_info_rsp_num;
#ifdef __USB_TETHERING__
    U8                                          user_tethering_acct;
#endif
    cbm_sim_id_enum                             bearer_info_req_sim_id;
#ifdef __MMI_CBM_CONNECTION_MANAGER__
    MMI_BOOL                                    disc_all_flag;
    MMI_BOOL                                    disc_flag;
    MMI_BOOL                                    backup_list_flag;
#endif /* __MMI_CBM_CONNECTION_MANAGER__ */
    MMI_BOOL                                    timer_start;
#ifdef __MMI_3G_SWITCH__
    cbm_sim_id_enum                             cur_3g_sim;
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    MMI_BOOL                                    send_for_nwinfo;  
#endif /* __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__ */
} srv_cnmgr_context_struct;

#endif /* CNMGR_SRV_MAIN_H */
