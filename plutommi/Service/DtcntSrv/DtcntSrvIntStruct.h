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
 * DtcntSrvIntStruct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the internal structure header files of data account services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DTCNT_SRV_INT_STRUCT_H
#define _DTCNT_SRV_INT_STRUCT_H

#include "MMI_features.h"
#include "DtcntSrvIntEnum.h"
#include "wndrv_cnst.h"
#include "MMIDataType.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIntDef.h"
#include "DtcntSrvIprot.h"
#include "kal_general_types.h"
#include "supc_abm_msgs.h"
#include "mmi2abm_struct.h"

typedef struct
{
    srv_dtcnt_store_status_enum store_status;
    srv_dtcnt_sim_type_enum acct_update_evt_sim_id_old;
    int info_file_fp;
} srv_dtcnt_context;

typedef struct
{
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#ifdef __TCPIP_OVER_CSD__
    U8 csd_sim_acc_num;
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
    U8 gprs_sim_acc_num;
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
    U32 total_acc_num;
    U32 csd_fields;
    U32 gprs_fields;
} srv_dtcnt_store_info_st;

typedef struct
{
    U8  in_use;                             /* This block is used flag */
    U8  readonly;                           /* readonly profile */
    U8  acc_id;                             /* The account ID */
    U8  use_proxy;                          /* use proxy flag */
    U8  acc_name[(SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1) * ENCODING_LENGTH];    /* account name */
    U8  dest_name[SRV_DTCNT_PROF_MAX_APN_LEN+1];        /* gprs:apn, csd:dial number */
    U8  PrimaryAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];     /* Primary DNS IP Address (MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
    U8  SecondaryAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];   /* Secondary DNS IP Address (MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */    
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    U8 provurl_hash_val[SRV_DTCNT_PROVURL_HASH_LEN];    /* hash value of PROVURL */
    U8 node_id[SRV_DTCNT_MAX_NODE_ID_LEN+1];            /* UTF-8, 0-ended   */
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */  
    U8 napid_hash_val[SRV_DTCNT_NAPID_HASH_LEN];        /* hash value of napid */
#ifdef __TCPIP_OVER_CSD__
    srv_dtcnt_prof_csd_dial_type_enum   DialType;   /* CSD dial type */
    srv_dtcnt_prof_csd_rate_enum        DataRate;   /* CSD data rate */    
#endif /* __TCPIP_OVER_CSD__ */
    srv_dtcnt_prof_acc_type_enum acc_type;  /* Account type */
    srv_dtcnt_sim_type_enum sim_info;       /* SIM info */
    srv_dtcnt_prof_px_srv_enum px_service;  /* connection type */
    srv_dtcnt_bearer_enum bearer_type;      /* bearer type */
    srv_dtcnt_prof_auth_struct auth_info;   /* Authentation info */
    U32 fields;                             /* profile has value fields */
    U64 app_type;                           /* bit mask application type */
} srv_dtcnt_account_info_st;

typedef struct
{
    srv_dtcnt_store_info_st     ctrl_block;
    srv_dtcnt_account_info_st   acc_list[SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM];
    int default_acc_idx[SRV_DTCNT_SIM_TYPE_TOTAL-1];
    int backup_acc_idx[SRV_DTCNT_SIM_TYPE_TOTAL-1];    
    srv_dtcnt_sim_type_enum     sim_preference;
} srv_dtcnt_store_info_context;

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
typedef struct
{
    U8  in_use;                                         /* This block is used flag */
    U8  acc_id;                                         /* The account ID */
    U8  acc_name[(SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1) * ENCODING_LENGTH];    /* account name */
    U8  PrimaryAddr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];    /* Primary DNS IP Address (MAX: SRV_DTCNT_PROF_MAX_IP_ADDR_LEN) */
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    U8 provurl_hash_val[SRV_DTCNT_PROVURL_HASH_LEN];    /* hash value of PROVURL */
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */    
    U8 napid_hash_val[SRV_DTCNT_NAPID_HASH_LEN];        /* hash value of napid */
    srv_dtcnt_sim_type_enum sim_info;                   /* SIM info */
    U8 use_proxy;   /* use proxy flag */
    srv_dtcnt_prof_px_srv_enum px_service;              /* connection type */
    U8 UserName[SRV_DTCNT_PROF_MAX_USER_LEN+1];         /* User string of a Data Account (ASCII) (MAX: SRV_DTCNT_PROF_MAX_USER_LEN) */
    U8 Passwd[SRV_DTCNT_PROF_MAX_PW_LEN+1];             /* Password for a Data Account (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PW_LEN) */
    U8 HomePage[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1];     /* Homepage string (ASCII) (MAX: SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN) */
    U8 px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];         /* proxy addr string IP format */
    U8 px_authid[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1];  /* proxy auth. ID string (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN) */
    U8 px_authpw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1];  /* proxy auth. PW (ASCII) (MAX: SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN) */
    U16 px_port;                                        /* proxy port */
    U32 fields;                                         /* profile has value fields */
    U64 app_type;                                       /* bit mask application type */
} srv_dtcnt_sim_comm_account_info_st;

#ifdef __TCPIP_OVER_CSD__
typedef struct
{
    srv_dtcnt_sim_comm_account_info_st comm_header; /* common attributes */
    U8 DialNumber[SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN+1];   /* dial number */
    srv_dtcnt_prof_csd_dial_type_enum   DialType;       /* CSD dial type */
    srv_dtcnt_prof_csd_rate_enum        DataRate;       /* CSD data rate */    
} srv_dtcnt_sim_csd_account_info_st;
#endif /* __TCPIP_OVER_CSD__ */

#ifdef __MMI_GPRS_FEATURES__
typedef struct
{
    srv_dtcnt_sim_comm_account_info_st comm_header; /* common attributes */
    U8 APN[SRV_DTCNT_PROF_MAX_APN_LEN+1];               /* APN */
    srv_dtcnt_prof_gprs_auth_type_enum  AuthType;       /* GPRS Authentication Type */
} srv_dtcnt_sim_gprs_account_info_st;

#endif  /* __MMI_GPRS_FEATURES__ */
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */


#ifdef __MMI_WLAN_FEATURES__

typedef struct
{
    void *cb_func_ptr;
    void *user_data;
} srv_dtcnt_wlan_job_struct;

typedef struct srv_dtcnt_proc_job_list_st
{
    struct srv_dtcnt_proc_job_list_st *next;
    srv_dtcnt_wlan_job_struct job;
} srv_dtcnt_wlan_proc_job_list;

typedef struct srv_dtcnt_wlan_action_st
{
    struct srv_dtcnt_wlan_action_st *next;
    srv_dtcnt_wlan_action_enum action;
    srv_dtcnt_wlan_job_struct* job;
    void *data; /* connect by app profile (srv_dtcnt_wlan_conn_prof_struct) */
} srv_dtcnt_wlan_action_struct;

typedef struct srv_dtcnt_scan_job_list_st
{
    struct srv_dtcnt_scan_job_list_st *next;
    U32 scan_job_id;
    srv_dtcnt_wlan_job_struct job;
} srv_dtcnt_wlan_scan_job_list;

typedef struct
{
    U32 profile_id_count;
    U8 infra_prof_num;
    U8 adhoc_prof_num;
    MMI_BOOL start_on_switch_flight;
    srv_dtcnt_wlan_prof_priority_enum pri_criteria;
    srv_dtcnt_wlan_power_mode_enum pwr_mode; 
    MMI_BOOL init_on_bootup;
#ifdef __WAPI_SUPPORT__
    MMI_BOOL wapi_test_mode;
#endif /* __WAPI_SUPPORT__ */    
} srv_dtcnt_wlan_setting_struct;

typedef struct
{
    MMI_BOOL init_by_soc; // move to srv
    MMI_BOOL init_by_always_ask; //move to srv
    MMI_BOOL pre_connect_by_always_ask; /* the established connection is triggered by always ask flag */
    MMI_BOOL use_dhcp_of_connected; //srv             /* Whether currently connected profile use dhcp */
    srv_dtcnt_wlan_state_enum prev_state; //srv
    srv_dtcnt_wlan_state_enum state; //srv
    srv_dtcnt_wlan_scan_state_enum scan_state; //srv
    srv_dtcnt_wlan_curr_ap_info_struct  cur_ap_info;
    U8 mac_addr[WNDRV_MAC_ADDRESS_LEN]; // for init response to notify DA App, used in connection detail information
    U16 cur_ssid_len;       //// connected AP ssid length
    U8 cur_ssid[WNDRV_SSID_MAX_LEN];   // connected AP ssid
    U8 cur_bssid[WNDRV_MAC_ADDRESS_LEN];
    srv_dtcnt_wlan_action_struct *actions; //srv
    srv_dtcnt_wlan_proc_job_list *proc_job_list;
    srv_dtcnt_wlan_scan_job_list *scan_job_list;
    U32 scan_job_id;
    srv_dtcnt_wlan_job_struct *hw_reset_job;   //hw reset job
    srv_dtcnt_wlan_job_struct *set_pwr_mode_job;    // set power mode job
    srv_dtcnt_prof_wlan_struct *connected_wlan_profile;
    U8 ap_list_num;
    supc_abm_bss_info_struct ap_list[SRV_DTCNT_WLAN_MAX_AP_LIST_NUM];
} srv_dtcnt_wlan_ctx_struct;

#ifdef __MMI_OP01_WIFI__
typedef struct
{
    srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct ips[SRV_DTCNT_MAX_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM];  /* IP list query result */
    U8 num_ips;                                                                                         /* the number of queried IP list */
} srv_dtcnt_wlan_proxy_exclusive_ip_addr_list_struct;

typedef struct srv_dtcnt_bearer_init_job_list_st
{
    struct srv_dtcnt_bearer_init_job_list_st *next;
    mmi_abm_bearer_init_rsp_struct *rsp;
} srv_dtcnt_bearer_init_job_list;

typedef struct 
{
    kal_uint32 account_map[ABM_MAX_APP_NUM][2];
    U8 num_account;
}srv_dtcnt_real_account_for_app;

#endif /* __MMI_OP01_WIFI__ */

typedef MMI_BOOL(*srv_dtcnt_encode_func) (wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile, int phase);

typedef struct srv_dtcnt_auth_encode_st
{
    U32 val;
    srv_dtcnt_encode_func encode_func;
} srv_dtcnt_auth_encode_st;

#endif /* __MMI_WLAN_FEATURES__ */
#endif /* _DTCNT_SRV_INT_STRUCT_H */ 
