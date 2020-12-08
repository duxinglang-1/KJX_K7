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
 * DtcntSrvWlan.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intended to provide the WLAN profile services.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TCPIP__
#include "DtcntSrv.h"
#include "dataaccountdef.h"
#include "mmi2abm_struct.h"
#include "supc_mmi_msgs.h"

#include "MMI_features.h"
#include "DtcntSrvIntStruct.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "DtcntSrvIprot.h"
#include "supc_abm_msgs.h"
#include "DtcntSrvGprot.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "DtcntSrvIntEnum.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "wndrv_supc_types.h"
#include "DtcntSrvIntDef.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "cbm_consts.h"
#include "wndrv_cnst.h"
#include "Unicodexdcl.h"
#include "DtcntSrvDb.h"
#include "DtcntSrvWlan.h"
#include "dtcnt_struct.h"
#include "CharBatSrvGprot.h"
#include "GpioSrvGprot.h"
#include "CbmSrvIprot.h"

#ifdef __MMI_WLAN_FEATURES__
#include "custom_data_account.h"
#include "wifi_common_config.h"
#include "ShutdownSrvGprot.h"
#include "wndrv_api.h"
#include "ModeSwitchSrvGprot.h"
#include "NetSetSrvGprot.h"
#ifdef __MMI_TETHERING_WIFI__
#include "TetheringSrvGprot.h"
#endif /* __MMI_TETHERING_WIFI__ */

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void srv_dtcnt_wlan_free_action(srv_dtcnt_wlan_action_struct **handle, srv_dtcnt_wlan_action_struct *action_to_remove);
static MMI_BOOL srv_dtcnt_wlan_do_action(void);
static MMI_BOOL srv_dtcnt_wlan_encode_profile(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile);
static void srv_dtcnt_wlan_wifi_init_req(void);
static void srv_dtcnt_wlan_wifi_deinit_req(void);
static MMI_BOOL srv_dtcnt_wlan_connect_req(void *data);
static void srv_dtcnt_wlan_ap_list_req(void);
static MMI_BOOL srv_dtcnt_wlan_encode_eap_profile(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile);
static MMI_BOOL srv_dtcnt_wlan_eap_tls_profile_encoder(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile, int phase);
static MMI_BOOL srv_dtcnt_wlan_user_info_profile_encoder(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile, int phase);
static MMI_BOOL srv_dtcnt_wlan_eap_peap_profile_encoder(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile, int phase);
static MMI_BOOL srv_dtcnt_wlan_eap_ttls_profile_encoder(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile, int phase);
#if 0
#ifndef __CERTMAN_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __CERTMAN_SUPPORT__ */
#endif
static void srv_dtcnt_wlan_post_state_event(mmi_rp_srv_dtcnt_event_enum event_id);
static srv_dtcnt_prof_wlan_struct *srv_dtcnt_wlan_find_profile(U32 profile_id);
static void srv_dtcnt_wlan_post_bearer_status_event(srv_dtcnt_wlan_status_enum status);
static void srv_dtcnt_wlan_disconnect_req(void);
static void srv_dtcnt_wlan_ipaddr_change_req(MMI_BOOL use_dhcp, srv_dtcnt_wlan_ipaddr_update_struct *ipaddr_info);
static S32 srv_dtcnt_wlan_callback_handler(mmi_event_struct* param);
static void srv_dtcnt_wlan_shutdown_req(void);
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_OP01_WIFI__))
static void srv_dtcnt_wlan_search_ap_open_ind_callback(srv_dtcnt_wlan_search_ap_open_rsp_enum rsp);
#endif
#ifdef __MMI_OP01_WIFI__
static void srv_dtcnt_wlan_ap_list_query_ind_callback(U32 ap_num);
static void srv_dtcnt_wlan_logout_callback(srv_dtcnt_wlan_logout_rsp_enum rsp);

#endif /* __MMI_OP01_WIFI__ */

#define DTCNT_SRV_ILM_MEMSET(local_para_ptr)    do {                              \
    memset((kal_uint8*)(local_para_ptr) + sizeof(local_para_struct), 0, \
           (local_para_ptr)->msg_len - sizeof(local_para_struct));      \
} while(0)

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern void pbkdf2_sha1(
                const char *passphrase,
                const char *ssid,
                kal_uint16 ssid_len,
                int iterations,
                kal_uint8 *buf,
                kal_uint16 buflen);
extern kal_bool wndrv_chip_isOK(void);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
srv_dtcnt_wlan_ctx_struct g_srv_dtcnt_wlan_ctx;
srv_dtcnt_wlan_setting_struct g_srv_dtcnt_wlan_setting_ctx;
srv_dtcnt_prof_wlan_struct g_srv_dtcnt_wlan_prof_list[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];
srv_dtcnt_prof_wlan_struct *g_srv_dtcnt_wlan_prof_list_p[SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM];
srv_dtcnt_wlan_prefer_struct g_srv_dtcnt_wlan_prefer_ctx;
srv_dtcnt_prof_wlan_struct g_srv_dtcnt_wlan_connecting_prof;


#ifdef __MMI_TETHERING_WIFI__
srv_dtcnt_init_callback_context_struct g_init_callback;
#endif
#ifdef __MMI_OP01_WIFI__
srv_dtcnt_wlan_proxy_exclusive_ip_addr_list_struct g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list;
static MMI_BOOL g_need_login_flag = MMI_FALSE;
U8 last_ssid[WNDRV_SSID_MAX_LEN];
U16 last_ssid_len;
#endif /* __MMI_OP01_WIFI__ */

/* Authentication */
static srv_dtcnt_auth_encode_st g_srv_dtcnt_wlan_auth_tbl[] = 
{
#ifdef WLAN_EAP_TLS_SUPPORT
    {WLAN_EAP_TLS, srv_dtcnt_wlan_eap_tls_profile_encoder},
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    {WLAN_EAP_MD5, srv_dtcnt_wlan_user_info_profile_encoder},
#endif 
#ifdef WLAN_EAP_PEAP_SUPPORT
    {WLAN_EAP_PEAP, srv_dtcnt_wlan_eap_peap_profile_encoder},
#endif 
#ifdef WLAN_EAP_TTLS_SUPPORT
    {WLAN_EAP_TTLS, srv_dtcnt_wlan_eap_ttls_profile_encoder},
#endif 
#ifdef WLAN_EAP_SIM_SUPPORT
    {WLAN_EAP_SIM, srv_dtcnt_wlan_user_info_profile_encoder},
#endif 
#ifdef WLAN_EAP_FAST_SUPPORT
    {0, NULL},
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    {WLAN_EAP_MSCHAV2, srv_dtcnt_wlan_user_info_profile_encoder},
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    {WLAN_EAP_GTC, srv_dtcnt_wlan_user_info_profile_encoder},
#endif 
#ifdef WLAN_PAP_SUPPORT
    {WLAN_PAP, srv_dtcnt_wlan_user_info_profile_encoder},
#endif 
#ifdef WLAN_CHAP_SUPPORT
    {WLAN_CHAP, srv_dtcnt_wlan_user_info_profile_encoder},
#endif 
#ifdef WLAN_MSCHAP_SUPPORT
    {WLAN_MSCHAP, srv_dtcnt_wlan_user_info_profile_encoder},
#endif 
#ifdef WLAN_MSCHAP2_SUPPORT
    {WLAN_MSCHAPV2, srv_dtcnt_wlan_user_info_profile_encoder},
#endif 
#ifdef WLAN_EAP_AKA_SUPPORT
    {WLAN_EAP_AKA, srv_dtcnt_wlan_user_info_profile_encoder},
#endif 
    {0, NULL}
};

U8 g_srv_dtcnt_wlan_eap_types[] = 
{
#ifdef WLAN_EAP_TLS_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_TLS,
#endif 
#ifdef WLAN_EAP_PEAP_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_PEAP,
#endif 
#ifdef WLAN_EAP_TTLS_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_TTLS,
#endif 
#ifdef WLAN_EAP_SIM_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_SIM,
#endif 
#ifdef WLAN_EAP_FAST_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_FAST,
#endif 
#ifdef WLAN_EAP_AKA_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_AKA,
#endif 
    SRV_DTCNT_WLAN_AUTH_TYPE_END
};

#ifdef WLAN_EAP_PEAP_SUPPORT
U8 g_srv_dtcnt_wlan_eap_peap_types[] = 
{
/*
#ifdef WLAN_EAP_SIM_SUPPORT
    WLAN_AUTH_TYPE_EAP_SIM,
#endif 
*/
#ifdef WLAN_EAP_TLS_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_TLS,
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_MSCHAP2,
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_GTC,
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_MD5,
#endif 
    SRV_DTCNT_WLAN_AUTH_TYPE_END
};
#endif /* WLAN_EAP_PEAP_SUPPORT */ 

#ifdef WLAN_EAP_TTLS_SUPPORT
U8 g_srv_dtcnt_wlan_eap_ttls_types[] = 
{
#ifdef WLAN_EAP_SIM_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_SIM,
#endif 
#ifdef WLAN_EAP_TLS_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_TLS,
#endif 
#ifdef WLAN_EAP_MSCHAP2_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_MSCHAP2,
#endif 
#ifdef WLAN_MSCHAP2_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_MSCHAP2,
#endif 
#ifdef WLAN_EAP_GTC_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_GTC,
#endif 
#ifdef WLAN_EAP_MD5_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_MD5,
#endif 
#ifdef WLAN_PAP_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_PAP,
#endif 
#ifdef WLAN_CHAP_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_CHAP,
#endif 
#ifdef WLAN_MSCHAP_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_MSCHAP,
#endif 
#ifdef WLAN_EAP_AKA_SUPPORT
    SRV_DTCNT_WLAN_AUTH_TYPE_EAP_AKA,
#endif 
    SRV_DTCNT_WLAN_AUTH_TYPE_END
};
#endif /* WLAN_EAP_TTLS_SUPPORT */ 



#define WLAN_STATIC_APIs

static MMI_BOOL srv_dtcnt_scan_job_exist(U32 scan_job_id)
{
    srv_dtcnt_wlan_scan_job_list *cur_job = g_srv_dtcnt_wlan_ctx.scan_job_list;
    while(cur_job)
    {
        if(cur_job->scan_job_id == scan_job_id)
        {
            return MMI_TRUE;
        }
        cur_job = cur_job->next;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_free_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle                  [IN]        
 *  action_to_remove        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_dtcnt_wlan_free_action(srv_dtcnt_wlan_action_struct **handle, srv_dtcnt_wlan_action_struct *action_to_remove)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_action_struct *temp_action = *handle;
    srv_dtcnt_wlan_action_struct *prev_action = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action_to_remove == NULL)
    {
        return;
    }

    while (temp_action != action_to_remove)
    {
        prev_action = temp_action;
        temp_action = temp_action->next;
        ASSERT(temp_action != NULL);
    }

    if(prev_action)
    {
        prev_action->next = temp_action->next;
    }
    else
    {
        ASSERT(action_to_remove == *handle);
        
        *handle = action_to_remove->next;
    }

    if (action_to_remove->job)
    {
        OslMfree(action_to_remove->job);
    }    
    
    if (action_to_remove->data)
    {
        OslMfree(action_to_remove->data);
    }

    OslMfree(action_to_remove);
    action_to_remove = NULL;
    
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_find_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]         
 *  action      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_dtcnt_wlan_action_struct *srv_dtcnt_wlan_find_action(srv_dtcnt_wlan_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_action_struct *temp_action = g_srv_dtcnt_wlan_ctx.actions;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp_action == NULL)
    {
        return NULL;
    }

    do
    {
        if (temp_action->action == action)
        {
            return temp_action;
        }
        temp_action = temp_action->next;
    }
    while (temp_action != NULL);
    return NULL;    /* Not found */
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_delete_action
 * DESCRIPTION
 *  remove action from action queue
 * PARAMETERS
 *  action      [IN]        
 *  opt         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_delete_action(srv_dtcnt_wlan_action_enum action, srv_dtcnt_wlan_action_del_opt_enum opt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_action_struct *temp_action = srv_dtcnt_wlan_find_action(action);
    srv_dtcnt_wlan_action_struct **handle = &g_srv_dtcnt_wlan_ctx.actions;
    srv_dtcnt_wlan_req_res_enum res = SRV_DTCNT_WLAN_REQ_RES_DONE;
    srv_dtcnt_wlan_cb_func_ptr  callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DELETE_ACTION, opt, action);

    if (temp_action == NULL)
    {
        return;
    }

    switch (opt)
    {
        case SRV_DTCNT_WLAN_ACTION_DEL_OPT_NONE:
            goto free_action;
        case SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED:
            res = SRV_DTCNT_WLAN_REQ_RES_TERMINATED;
            break;
        case SRV_DTCNT_WLAN_ACTION_DEL_OPT_DUPLICATED:
            res = SRV_DTCNT_WLAN_REQ_RES_DUPLICATED;
            break;
        default:
            MMI_ASSERT(0);
    }

    /* notify application */
    switch (action)
    {
        case SRV_DTCNT_WLAN_ACTION_INIT:
            if (temp_action->job && temp_action->job->cb_func_ptr)
            {
                callback = (srv_dtcnt_wlan_cb_func_ptr)temp_action->job->cb_func_ptr;
                callback(temp_action->job->user_data, res);
            }
            srv_dtcnt_wlan_post_init_res_event(res);
            break;
            
        case SRV_DTCNT_WLAN_ACTION_DEINIT:
            if (temp_action->job && temp_action->job->cb_func_ptr)
            {
                callback = (srv_dtcnt_wlan_cb_func_ptr)temp_action->job->cb_func_ptr;
                callback(temp_action->job->user_data, res);
            }
            srv_dtcnt_wlan_post_deinit_res_event(res);
            break;

        case SRV_DTCNT_WLAN_ACTION_DISCONNECT:
            srv_dtcnt_wlan_post_disc_res_event(res);
            break;

        case SRV_DTCNT_WLAN_ACTION_CONNECT:
            {
                srv_dtcnt_wlan_conn_res_struct *conn_res;

                conn_res = OslMalloc(sizeof(srv_dtcnt_wlan_conn_res_struct));
                kal_mem_set(conn_res, 0, sizeof(srv_dtcnt_wlan_conn_res_struct));
                conn_res->result = (res == SRV_DTCNT_WLAN_REQ_RES_TERMINATED)? SRV_DTCNT_RESULT_TERMINATED : SRV_DTCNT_RESULT_ABORTED;

                if (temp_action->job && temp_action->job->cb_func_ptr)
                {
                    callback = (srv_dtcnt_wlan_cb_func_ptr)temp_action->job->cb_func_ptr;
                    callback(temp_action->job->user_data, res);
                }
                srv_dtcnt_wlan_post_conn_res_event(conn_res, EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND);
                OslMfree(conn_res);                
                break;
            }
        /* should only have one scan action in queue at one time, implies can't found or free directly */
        case SRV_DTCNT_WLAN_ACTION_SCAN:
            break;
        default:
            MMI_ASSERT(0);
    }

free_action:    
    srv_dtcnt_wlan_free_action(handle, temp_action);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_do_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_do_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_action_struct *todo = g_srv_dtcnt_wlan_ctx.actions;
    MMI_BOOL action_done = MMI_FALSE;
    srv_dtcnt_wlan_cb_func_ptr  callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (todo == NULL)
    {
        return action_done;   /* Nothing to do */
    }
    
    while (todo && !action_done)
    {
        switch (todo->action)
        {
            case SRV_DTCNT_WLAN_ACTION_INIT:
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DO_ACTION_INIT);
                if (g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_NULL)
                {
                    srv_dtcnt_wlan_wifi_init_req();
                    action_done = MMI_TRUE;
                }
                else
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DO_ACTION_NOT_DONE, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);
                    if (todo->job && todo->job->cb_func_ptr)
                    {
                        callback = (srv_dtcnt_wlan_cb_func_ptr)todo->job->cb_func_ptr;
                        callback(todo->job->user_data, SRV_DTCNT_WLAN_REQ_RES_FAILED);
                    }
                    srv_dtcnt_wlan_post_init_res_event(SRV_DTCNT_WLAN_REQ_RES_FAILED);                    
                }
                break;
                
            case SRV_DTCNT_WLAN_ACTION_DEINIT:
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DO_ACTION_DEINIT);
                if (g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_INIT)
                {
                    srv_dtcnt_wlan_wifi_deinit_req();
                    action_done = MMI_TRUE;
                }
                else
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DO_ACTION_NOT_DONE, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);
                    if (todo->job && todo->job->cb_func_ptr)
                    {
                        callback = (srv_dtcnt_wlan_cb_func_ptr)todo->job->cb_func_ptr;
                        callback(todo->job->user_data, SRV_DTCNT_WLAN_REQ_RES_FAILED);
                    }
                    srv_dtcnt_wlan_post_deinit_res_event(SRV_DTCNT_WLAN_REQ_RES_FAILED);
                }
                break;
                
            case SRV_DTCNT_WLAN_ACTION_CONNECT:
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DO_ACTION_CONNECT);
                if (g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_INIT)
                {
                    action_done = srv_dtcnt_wlan_connect_req(todo->data);
                }

                if (!action_done)
                {
                    srv_dtcnt_wlan_conn_res_struct *conn_res;
                    
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DO_ACTION_NOT_DONE, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);

                    conn_res = OslMalloc(sizeof(srv_dtcnt_wlan_conn_res_struct));
                    kal_mem_set(conn_res, 0, sizeof(srv_dtcnt_wlan_conn_res_struct));
                    conn_res->result = SRV_DTCNT_RESULT_FAILED;

                    if (todo->job && todo->job->cb_func_ptr)
                    {
                        srv_dtcnt_wlan_conn_res_cb_func_ptr conn_res_callback = (srv_dtcnt_wlan_conn_res_cb_func_ptr)todo->job->cb_func_ptr;
                        conn_res_callback(todo->job->user_data, conn_res);
                    }
                    srv_dtcnt_wlan_post_conn_res_event(conn_res, EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND);
                    OslMfree(conn_res);                    
                }
                break;
                
            case SRV_DTCNT_WLAN_ACTION_DISCONNECT:
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DO_ACTION_DISCONNECT);
            #ifdef __WPS_SUPPORT__
                if (g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_CONNECTED ||
                    g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT)
            #else
                if (g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_CONNECTED)
            #endif
                {
                    srv_dtcnt_wlan_disconnect_req();
                    action_done = MMI_TRUE;
                }
                else
                {   
                    /* this disconnect action is initialized by App */
                    if (todo->job)
                    {
                        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DO_ACTION_NOT_DONE, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);
                        srv_dtcnt_wlan_post_disc_res_event(SRV_DTCNT_WLAN_REQ_RES_FAILED);
                    }
                }
                break;
                
            case SRV_DTCNT_WLAN_ACTION_SCAN:
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DO_ACTION_SCAN);
                srv_dtcnt_wlan_ap_list_req();
                action_done = MMI_TRUE;
                break;
                
            default:
                ASSERT(0);
        }

        /* SCAN has own job list, otherwise can add proc job directly */
        if (todo->action != SRV_DTCNT_WLAN_ACTION_SCAN)
        {
            /* do action successfully and need callback service --> queue processing job for callback notify */
            if (action_done && todo->job)
            {
                srv_dtcnt_wlan_append_proc_job(todo->job);
            }
        }
        srv_dtcnt_wlan_free_action(&g_srv_dtcnt_wlan_ctx.actions, todo);
        todo = g_srv_dtcnt_wlan_ctx.actions;
    }
    return action_done;
}

void srv_dtcnt_wlan_post_conn_prof_event(srv_dtcnt_wlan_conn_prof_ind_struct *res)
{
    srv_dtcnt_wlan_conn_prof_evt_struct evt;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONN_PROF, res->prof_num, res->conn_type);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_CONN_PROF);
    kal_mem_cpy(&(evt.res), res, sizeof(srv_dtcnt_wlan_conn_prof_ind_struct));    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_post_scan_res_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_post_scan_res_event(srv_dtcnt_wlan_scan_result_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_scan_res_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_SCAN_RESULT);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_SCAN_RES_IND);    
    kal_mem_cpy(&(evt.scan_res), res, sizeof(srv_dtcnt_wlan_scan_result_struct));
    MMI_FRM_CB_EMIT_EVENT(&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_post_conn_res_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_post_conn_res_event(srv_dtcnt_wlan_conn_res_struct *res, mmi_rp_srv_dtcnt_event_enum evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_conn_res_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt_id != EVT_ID_SRV_DTCNT_WLAN_CONN_IND &&
        evt_id != EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_CONN_RESULT);
    MMI_FRM_INIT_EVENT(&evt, evt_id);
    kal_mem_cpy(&(evt.conn_result), res, sizeof(srv_dtcnt_wlan_conn_res_struct));    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_post_state_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_post_state_event(mmi_rp_srv_dtcnt_event_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* shared same event structure */
    srv_dtcnt_wlan_active_evt_struct evt;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event_id)
    {
        case EVT_ID_SRV_DTCNT_WLAN_ACTIVE:
        case EVT_ID_SRV_DTCNT_WLAN_INACTIVE:
        case EVT_ID_SRV_DTCNT_WLAN_CONNECTED:
        case EVT_ID_SRV_DTCNT_WLAN_SCAN:
        case EVT_ID_SRV_DTCNT_WLAN_CONNECT:
        case EVT_ID_SRV_DTCNT_WLAN_DISC_IND:
            break;
        default:
            return;
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_STATE_EVENT, event_id);
    MMI_FRM_INIT_EVENT(&evt, event_id);    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_post_bearer_status_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_post_bearer_status_event(srv_dtcnt_wlan_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* shared same event structure */
    srv_dtcnt_wlan_bearer_status_evt_struct evt;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_BEARER_STATUS);    

    evt.status = status;
    if (status == SRV_DTCNT_WLAN_STATUS_ACTIVE ||
        status == SRV_DTCNT_WLAN_STATUS_CONNECTED)
    {
        status |= WLAN_MAC_ADDRESS_INVALID(g_srv_dtcnt_wlan_ctx.mac_addr)? SRV_DTCNT_WLAN_STATUS_INVALID_MAC : 0;
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_WLAN_BEARER_STATUS_EVENT, status);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}
MMI_BOOL srv_dtcnt_convert_hex_to_str(U8* outStr, U8* inStr, U32 length)
{
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length % 2 != 0)
    {
        return MMI_FALSE;
    }

    memset(outStr, 0, length / 2 + 1);

    for (i = 0, j = 0; i < length; i++)
    {
        j = (i - i % 2) / 2;
        if (inStr[i] >= '0' && inStr[i] <= '9')
        {
            outStr[j] += (inStr[i] - '0') << 4 * ((i + 1) % 2);
        }
        else if (inStr[i] >= 'A' && inStr[i] <= 'F')
        {
            outStr[j] += (inStr[i] - 'A' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else if (inStr[i] >= 'a' && inStr[i] <= 'f')
        {
            outStr[j] += (inStr[i] - 'a' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_encode_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_encode_profile(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U32 length = 0;
    //int i = 0;
    memset(prof, 0, sizeof(wifi_data_account_profile_struct));

    prof->ssid_len = profile->ssid_len;
    memcpy(prof->ssid, profile->ssid, profile->ssid_len);
    switch (profile->network_type)
    {

        case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
            prof->network_type = WNDRV_SUPC_NETWORK_IBSS;
            prof->channel_number = profile->channel;
            break;
        case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
            prof->network_type = WNDRV_SUPC_NETWORK_INFRASTRUCTURE;
            break;
        default:
          ASSERT(0);
    }

    prof->priority = profile->priority;
    prof->profile_id = profile->profile_id;
    profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_TOTAL;

    switch (profile->auth_mode)
    {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
            prof->key_mgmt = WPA_KEY_MGMT_NONE;
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
            break;
            
        case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
            prof->proto = WPA_PROTO_RSN;
            prof->key_mgmt = WPA_KEY_MGMT_NONE;
            prof->auth_alg = WPA_AUTH_ALG_SHARED;
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
            break;
            
        case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X:
            prof->key_mgmt = WPA_KEY_MGMT_IEEE8021X_NO_WPA;
            prof->auth_alg = WPA_AUTH_ALG_OPEN;
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
            if (srv_dtcnt_wlan_encode_eap_profile(prof, profile) == KAL_FALSE)
            {
                return KAL_FALSE;
            }
            break;

        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
            // prof->proto = WPA_PROTO_WPA;
            prof->proto = WPA_PROTO_WPA | WPA_PROTO_RSN; // MAUI_03327492
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP;
            break;

        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
            prof->proto = WPA_PROTO_RSN;
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_AES;  
            break;
            
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK:
            prof->proto = WPA_PROTO_WPA | WPA_PROTO_RSN;
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP_AES;
            break;
            
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:
            // prof->proto = WPA_PROTO_WPA;
            prof->proto = WPA_PROTO_WPA | WPA_PROTO_RSN; // MAUI_03327492
            prof->key_mgmt = WPA_KEY_MGMT_IEEE8021X;
            prof->auth_alg = WPA_AUTH_ALG_OPEN;
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP;
            if (srv_dtcnt_wlan_encode_eap_profile(prof, profile) == KAL_FALSE)
            {
                return KAL_FALSE;
            }
            break;
            
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:
            prof->proto = WPA_PROTO_RSN;
            prof->key_mgmt = WPA_KEY_MGMT_IEEE8021X;
            prof->auth_alg = WPA_AUTH_ALG_OPEN;
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_AES;          
            if (srv_dtcnt_wlan_encode_eap_profile(prof, profile) == KAL_FALSE)
            {            
                return KAL_FALSE;
            }
            break;

        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX:
            prof->proto = WPA_PROTO_WPA | WPA_PROTO_RSN;
            prof->key_mgmt = WPA_KEY_MGMT_IEEE8021X;
            prof->auth_alg = WPA_AUTH_ALG_OPEN;
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP_AES;           
            if (srv_dtcnt_wlan_encode_eap_profile(prof, profile) == KAL_FALSE)
            {
                return KAL_FALSE;
            }
            break;            
    #ifdef __WAPI_SUPPORT__
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
            prof->proto = WPA_PROTO_WAPI;
            prof->pairwise = WAPI_CIPHER_SMS4;
            prof->group = WAPI_CIPHER_SMS4;
            prof->key_mgmt = WAPI_KEY_MGMT_PSK;
            prof->psk_p = KAL_TRUE;
            strcpy((char*)prof->psk, (const char*)profile->wapi_psk_str);
            prof->psk_type = profile->wapi_psk_format;
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI;
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
            prof->proto = WPA_PROTO_WAPI;
            prof->pairwise = WAPI_CIPHER_SMS4;
            prof->group = WAPI_CIPHER_SMS4;
            prof->key_mgmt = WAPI_KEY_MGMT_WAI;
	        prof->wapi_as_cert = profile->wapi_ase_id;
            prof->client_cert = profile->wapi_client_id;
            strcpy((char*)prof->private_key_passwd, (const char*)profile->wapi_private_key_passwd_str);
		    prof->private_key_passwd_len = strlen((const char*)profile->wapi_private_key_passwd_str);
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI;
            break;
    #endif
    }

    if(profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK
        || profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK
        || profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK)
            {
            prof->psk_p = KAL_TRUE;
            /* prof->auth_alg = WPA_AUTH_ALG_OPEN; */
            if(prof->network_type == WNDRV_SUPC_NETWORK_IBSS)
                {
                prof->key_mgmt = WPA_KEY_MGMT_WPA_NONE;
                }
                else
                {
                prof->key_mgmt = WPA_KEY_MGMT_PSK;
            }
#if 0        
/* under construction !*/
/* under construction !*/
            #endif
	            /* For OTA provisioning. Directly specify the 256-bits PSK, without any passphrase. */
            length = strlen((const char*)profile->passphrase);
            if(length == 64)
            {
                srv_dtcnt_convert_hex_to_str( prof->psk, profile->passphrase, 64);
            }
            else if(length >= 8 && length <= 63)
            {
                #ifdef __MTK_TARGET__
                    pbkdf2_sha1(
                        (const char*)profile->passphrase,
                        (const char*)prof->ssid,
                        prof->ssid_len,
                        4096,
                        prof->psk,
                        32);
                #else /* __MTK_TARGET__ */ 
                    strcpy((char*)prof->psk, (const char*)profile->passphrase);
                #endif /* __MTK_TARGET__ */

            }
            else if(length == 0)
            {
                memcpy(prof->psk, profile->psk, 32);
            }
            else
            {
                ASSERT(0);
            }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    }

    switch (profile->encrypt_mode)
    {
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE:
            prof->pairwise = WPA_CIPHER_NONE;
            prof->group = WPA_CIPHER_NONE;
            break;
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP:
            switch (profile->wep_key_len)
            {
                case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64:
                    prof->group = WPA_CIPHER_WEP40;
                    prof->pairwise = WPA_CIPHER_WEP40;
                    break;
                case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128:
                    prof->group = WPA_CIPHER_WEP104;
                    prof->pairwise = WPA_CIPHER_WEP104;
                    break;
                default:    /* Invalid key len */
                    prof->pairwise = WPA_CIPHER_NONE;
                    prof->group = WPA_CIPHER_NONE;
                    break;
            }
            break;
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP:
            prof->pairwise = WPA_CIPHER_TKIP | WPA_CIPHER_CCMP;
            prof->group = WPA_CIPHER_TKIP | WPA_CIPHER_CCMP;
            break;
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_AES:
            prof->pairwise = WPA_CIPHER_TKIP | WPA_CIPHER_CCMP;
            prof->group = WPA_CIPHER_TKIP | WPA_CIPHER_CCMP;
            break;
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP_AES:
            prof->pairwise = WPA_CIPHER_TKIP | WPA_CIPHER_CCMP;
            prof->group = WPA_CIPHER_TKIP | WPA_CIPHER_CCMP;
            break;
    }

    /* WEP key information */
    if (profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WEP || profile->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP)
    {
        U8 i;

        prof->wep_info_p = KAL_TRUE;
        prof->wep_keys.wep_tx_keyidx = profile->wep_key_index;

        for (i = 0; i < SRV_DTCNT_MAX_WEP_KEY_NUM; i++)
        {
            switch (profile->wep_key_len)
            {
                case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64:
                    prof->wep_keys.wep_key_len[i] = 5;
                    if (profile->wep_key_format == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX)
                    {
                        if (srv_dtcnt_hex_to_string(prof->wep_keys.wep_key[i], profile->wep_key, 10) == MMI_FALSE)
                        {
                            prof->wep_keys.wep_key_len[i] = 0;
                        }
                    }
                    else
                    {
                        memcpy(&prof->wep_keys.wep_key[i], profile->wep_key, 5);
                    }
                    break;
                case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128:
                    prof->wep_keys.wep_key_len[i] = 13;
                    if (profile->wep_key_format == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX)
                    {
                        if (srv_dtcnt_hex_to_string(prof->wep_keys.wep_key[i], profile->wep_key, 26) == MMI_FALSE)
                        {
                            prof->wep_keys.wep_key_len[i] = 0;
                        }
                    }
                    else
                    {
                        memcpy(prof->wep_keys.wep_key[i], profile->wep_key, 13);
                    }
                    break;
                default:
                    prof->wep_keys.wep_key_len[i] = 0;
                    break;
            }
        }
    }
    /* To try open mode also where in shared mode */
    if (profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WEP)
    {
        prof->auth_alg |= WPA_AUTH_ALG_OPEN;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_encode_eap_profile
 * DESCRIPTION
 *  WLAN eap profile settings encode
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_encode_eap_profile(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    prof->eap = profile->eap_auth_type;
    
    for (i = 0; i < (sizeof(g_srv_dtcnt_wlan_eap_types) - 1); i++)
    {
        if (profile->eap_auth_type & (g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_types[i]].val))
        {
            if (g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_types[i]].encode_func != NULL)
            {
                if(g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_types[i]].encode_func(prof, profile, 1) == MMI_FALSE)
                {
                    return MMI_FALSE;
                }
            }
        }
    }
    return MMI_TRUE;
}
#if 0
#ifndef __CERTMAN_SUPPORT__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_eap_tls_profile_encoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_eap_tls_profile_encoder(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile, int phase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(phase == 1)
    {
        prof->ca_cert = profile->root_ca_id;
        if(profile->eap_auth_type & (g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_types[0]].val))
        {
            prof->client_cert = profile->client_ca_id;
        }
        else
        {
            prof->client_cert = 0;
        }        

        if (prof->private_key_passwd_len == 0)
        {
            len = strlen((char*)profile->private_key_passwd);
            if (len > 0)
            {
                prof->private_key_passwd_len = len;
                memcpy(prof->private_key_passwd, profile->private_key_passwd, prof->private_key_passwd_len);
            }
            else
            {
                prof->private_key_passwd_len = 0;
            }
        }
    }
    else if(phase == 2)
    {
        prof->ca_cert2 = profile->root_ca_id;
        prof->client_cert2 = profile->client_ca_id;
        if (prof->private_key2_passwd_len == 0)
        {
            len = strlen((char*)profile->private_key_passwd);
            if (len > 0)
            {
                prof->private_key2_passwd_len = len;
                memcpy(prof->private_key2_passwd, profile->private_key_passwd, prof->private_key2_passwd_len);
            }
            else
            {
                prof->private_key2_passwd_len = 0;
            }
        }
    }

    if (prof->identity_len == 0)
    {
        len = strlen((char*)profile->username);
        if (len > 0)
        {
            prof->identity_len = len;
            memcpy(prof->identity, profile->username, prof->identity_len);
        }
        else
        {
            prof->identity_len = 0;
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_user_info_profile_encoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_user_info_profile_encoder(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile, int phase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (prof->identity_len == 0)
    {
        len = strlen((char*)profile->username);
        if (len > 0)
        {
            prof->identity_len = len;
            memcpy(prof->identity, profile->username, prof->identity_len);
        }
        else
        {
            prof->identity_len = 0;
        }
    }

    if (prof->password_len == 0)
    {
        len = strlen((char*)profile->password);
        if (len > 0)
        {
            prof->password_len = len;
            memcpy(prof->password, profile->password, prof->password_len);
        }
        else
        {
            prof->password_len = 0;
        }
    }
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_eap_peap_profile_encoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_eap_peap_profile_encoder(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile, int phase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof->ca_cert = profile->root_ca_id;
    prof->phase1 = (profile->peap_version | SUPC_PHASE1_LABLEL_0 | SUPC_PHASE1_OUTER_SUCCESS_0);
    prof->phase2 |= profile->eap_peap_auth_type;
    
    for (i = 0; i < (sizeof(g_srv_dtcnt_wlan_eap_peap_types) - 1); i++)
    {
        if (profile->eap_peap_auth_type & (g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_peap_types[i]].val))
        {
            if (g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_peap_types[i]].encode_func != NULL)
            {
                if(g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_peap_types[i]].encode_func(prof, profile, 2) == MMI_FALSE)
                {
                    return MMI_FALSE;
                }
            }
        }
    }

    if (prof->identity_len == 0)
    {
        len = strlen((char*)profile->username);
        if (len > 0)
        {
            prof->identity_len = len;
            memcpy(prof->identity, profile->username, prof->identity_len);
        }
        else
        {
            prof->identity_len = 0;
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_eap_ttls_profile_encoder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prof        [?]     
 *  profile     [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_eap_ttls_profile_encoder(wifi_data_account_profile_struct *prof, srv_dtcnt_prof_wlan_struct *profile, int phase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prof->ca_cert = profile->root_ca_id;
    prof->phase2 |= profile->eap_ttls_auth_type;

    for (i = 0; i < (sizeof(g_srv_dtcnt_wlan_eap_ttls_types) - 1); i++)
    {
        if (profile->eap_ttls_auth_type & (g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_ttls_types[i]].val))
        {
            if (g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_ttls_types[i]].encode_func != NULL)
            {
                if(g_srv_dtcnt_wlan_auth_tbl[g_srv_dtcnt_wlan_eap_ttls_types[i]].encode_func(prof, profile, 2) == MMI_FALSE)
                {
                    return MMI_FALSE;
                }
            }
        }
    }

    if (prof->identity_len == 0)
    {
        len = strlen((char*)profile->username);
        if (len > 0)
        {
            prof->identity_len = len;
            memcpy(prof->identity, profile->username, prof->identity_len);
        }
        else
        {
            prof->identity_len = 0;
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  srv_dtcnt_wlan_callback_handler
* DESCRIPTION
*  function to handle the service callback
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
S32 srv_dtcnt_wlan_callback_handler(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    switch (param->evt_id)
    {
    case EVT_ID_SRV_SHUTDOWN_DEINIT:
        srv_dtcnt_wlan_shutdown_req();
        break;
        
    default:
        break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_shutdown_req
 * DESCRIPTION
 *  shutdown wifi the module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_shutdown_req(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SHUTDOWN_REQ, g_srv_dtcnt_wlan_ctx.state);
    if (g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_NULL)
    {
        return;
    }
    mmi_frm_send_ilm(MOD_WNDRV, MSG_ID_WNDRV_MMI_POWEROFF_REQ, NULL, NULL);
#endif /* __MTK_TARGET__ */
}

U8 srv_dtcnt_wlan_auto_connect_num()
{
   int i = 0;
   U8  auto_conn_num = 0;
   
   for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
   {
       if( g_srv_dtcnt_wlan_prof_list_p[i] != NULL &&
        g_srv_dtcnt_wlan_prof_list_p[i]->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA &&
        (g_srv_dtcnt_wlan_prof_list_p[i]->ap_type == SRV_DTCNT_WLAN_AP_USER_DEFINE || g_srv_dtcnt_wlan_prof_list_p[i]->ap_type == SRV_DTCNT_WLAN_AP_DEFAULT) )
       {
           ++auto_conn_num;
       }
   }
   MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_AUTO_CONN_NUM, auto_conn_num);
   return auto_conn_num;
}

#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_OP01_WIFI__))
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_search_ap_open_ind_callback
 * DESCRIPTION
 *  Data account WLAN search AP list opening indication callback
 * PARAMETERS
 *  rsp     :   [IN]    Selection response from DA APP
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_search_ap_open_ind_callback(srv_dtcnt_wlan_search_ap_open_rsp_enum rsp)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_abm_wifi_activate_req_rej_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SEARCH_AP_OPEN_IND_CALLBACK, rsp);
    
    switch (rsp)
    {
        case SRV_DTCNT_WLAN_SEARCH_AP_OPEN_CONNECT:
            return;
        case SRV_DTCNT_WLAN_SEARCH_AP_OPEN_CANCEL:
            p = OslAllocDataPtr(mmi_abm_wifi_activate_req_rej_struct);
            p->cause = WLAN_NOT_AVAILABLE;
            mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_REJ, (oslParaType *)p, NULL);
            return;
        case SRV_DTCNT_WLAN_SEARCH_AP_OPEN_CLOSE_IND:
            p = OslAllocDataPtr(mmi_abm_wifi_activate_req_rej_struct);
            p->cause = WLAN_NOT_AVAILABLE;
            mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_REJ, (oslParaType *)p, NULL); 
            mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_DEACTIVATE_REQ_REJ, NULL, NULL);
            
            return;
        default:
            MMI_ASSERT(0);
    }
}
#endif

#ifdef __MMI_OP01_WIFI__
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_ap_list_query_ind_callback
 * DESCRIPTION
 *  Data account WLAN AP list query indication callback
 * PARAMETERS
 *  ap_num  :   [IN]    AP number
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_ap_list_query_ind_callback(U32 ap_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_wifi_ap_list_query_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_AP_LIST_QUERY_IND_CALLBACK, ap_num);

    if (ap_num == 0)
    {
        srv_dtcnt_wlan_change_bearer_to_cellular_network_evt_struct change_bearer_to_cellular_network_evt;
        
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_CHANGE_BEARER_TO_CELLULAR_NETWORK);
        MMI_FRM_INIT_EVENT(&change_bearer_to_cellular_network_evt, EVT_ID_SRV_DTCNT_WLAN_CHANGE_BEARER_TO_CELLULAR_NETWORK);    
        MMI_FRM_CB_EMIT_POST_EVENT(&change_bearer_to_cellular_network_evt);
    }
    
    p = OslAllocDataPtr(mmi_abm_wifi_ap_list_query_rsp_struct);
    p->ap_num = ap_num;
    
    //mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_AP_LIST_QUERY_RSP, (oslParaType *)p, NULL);
}
void srv_dtcnt_wlan_logout_callback(srv_dtcnt_wlan_logout_rsp_enum rsp)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_LOGOUT_CALLBACK, rsp); 
    switch(rsp)
    {
        case SRV_DTCNT_WLAN_LOGOUT_SUCC:
        case SRV_DTCNT_WLAN_LOGOUT_FAIL:        
            srv_dtcnt_wlan_disconnect();
            break;
        default:
            break;
    }
}
void srv_dtcnt_wlan_portal_login_start_cnf_hdlr(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_PORTAL_LOGIN_START_CNF);
}
void srv_dtcnt_wlan_portal_login_stop_cnf_hdlr(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_PORTAL_LOGIN_STOP_CNF);
}
void srv_dtcnt_wlan_portal_logout_cnf_hdlr(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_PORTAL_LOGOUT_CNF);
}


#endif /* __MMI_OP01_WIFI__ */

#define WLAN_SEND_ILM
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_wifi_init_req
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_wifi_init_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_INIT_WAIT)
    {
        return;
    }
    SetProtocolEventHandler(srv_dtcnt_wlan_wifi_init_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_INIT_CNF);
    g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_INIT_WAIT;

    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_INIT_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_wifi_deinit_req
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_wifi_deinit_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_DEINIT_WAIT)
    {
        return;
    }
    SetProtocolEventHandler(srv_dtcnt_wlan_wifi_deinit_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_DEINIT_CNF);
    g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_DEINIT_WAIT;

    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_DEINIT_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_ap_list_req
 * DESCRIPTION
 *  send request to query ap list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_ap_list_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_dtcnt_wlan_ap_list_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_AP_LIST_CNF);
    g_srv_dtcnt_wlan_ctx.scan_state = SRV_DTCNT_WLAN_SCAN_STATE_WAITING;    
    g_srv_dtcnt_wlan_ctx.ap_list_num = 0;
    srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_SCAN);
        
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_AP_LIST_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_connect_req
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_connect_req(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_abm_wifi_connect_req_struct *p;
    srv_dtcnt_wlan_conn_prof_ind_struct res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&res, 0, sizeof(srv_dtcnt_wlan_conn_prof_ind_struct));
    if (data == NULL)
    {
        U8 i, j, profile_num;
        U8 total_num = g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num + g_srv_dtcnt_wlan_setting_ctx.infra_prof_num;

        for (i = 0, profile_num = 0; i < total_num;)
        {
            p = OslAllocDataPtr(mmi_abm_wifi_connect_req_struct);

            for (j = 0; (i < total_num) && (j < 2); i++)
            {
                memset(&p->profile_header_ptr[j], 0, sizeof(wifi_data_account_profile_struct));

                if(g_srv_dtcnt_wlan_prof_list_p[i]->network_type != SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
                {
                    continue;
                }

                if(g_srv_dtcnt_wlan_prof_list_p[i]->ap_type !=  SRV_DTCNT_WLAN_AP_USER_DEFINE &&
                    g_srv_dtcnt_wlan_prof_list_p[i]->ap_type != SRV_DTCNT_WLAN_AP_DEFAULT)
                {
                    continue;
                }
                
                if (srv_dtcnt_wlan_encode_profile(&p->profile_header_ptr[j], g_srv_dtcnt_wlan_prof_list_p[i]) == KAL_FALSE)
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONN_NULL_ENCODE_FAIL, i);
                    continue;
                }
                res.prof_id[res.prof_num] = g_srv_dtcnt_wlan_prof_list_p[i]->profile_id;
                ++res.prof_num;
                j++;
            }

            profile_num += j;

            if(profile_num > 0)
            {                
                p->selection_mode = AP_AUTOMATIC_SELECT;
                p->num_of_profile = j;
                p->more_flag = (i < total_num) ? 1 : 0;
                p->connect_type = ALL_PROFILE_ENABLE; /* enable connect */
                p->handover_timer_value = WLAN_HANDOVER_TIMEOUT;
                mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_CONNECT_REQ, (oslParaType *)p, NULL);
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONN_NULL_PROF, total_num, profile_num, i, j);
                OslFreeDataPtr(p);
                return MMI_FALSE;
            }
        }

        if (profile_num > 0)
        {
            srv_dtcnt_wlan_post_conn_prof_event(&res);
            
            SetProtocolEventHandler(srv_dtcnt_wlan_connect_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
            g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_CONNECT_WAIT;
            srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_CONNECT);
            return MMI_TRUE;
        }
        else
        {
            /* If we failed on generating profiles, set the state to be initialized */
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONN_NULL_GEN_PROF_FAIL);
    		g_srv_dtcnt_wlan_ctx.prev_state = g_srv_dtcnt_wlan_ctx.state;
            if(g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight == MMI_FALSE)
            {
                g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight = MMI_TRUE;
                if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
                    NVRAM_MAX_WLAN_SETTING_SIZE)
                {
                    ASSERT(0);
                }
            }
            if(g_srv_dtcnt_wlan_setting_ctx.init_on_bootup == MMI_FALSE)
            {
                g_srv_dtcnt_wlan_setting_ctx.init_on_bootup = MMI_TRUE;
                if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
                    NVRAM_MAX_WLAN_SETTING_SIZE)
                {
                    ASSERT(0);
                }
            
            }

            return MMI_FALSE;
        }
    }
    else /* specified a profile to connect */
    {
        srv_dtcnt_wlan_conn_prof_struct *ap_prof = (srv_dtcnt_wlan_conn_prof_struct*) data;
        srv_dtcnt_prof_wlan_struct * temp_prof = *(ap_prof->prof_data);
        memcpy(&g_srv_dtcnt_wlan_connecting_prof, temp_prof, sizeof(srv_dtcnt_prof_wlan_struct));
        
        if (!ap_prof->num_prof || ap_prof->num_prof > 1)
        {
            /* not support multiple specified profile connection now */
            g_srv_dtcnt_wlan_ctx.prev_state = g_srv_dtcnt_wlan_ctx.state;
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONN_ACTION_NUM_PROFS, ap_prof->num_prof);
            return MMI_FALSE;
        }

        p = OslAllocDataPtr(mmi_abm_wifi_connect_req_struct);
        if (srv_dtcnt_wlan_encode_profile(&p->profile_header_ptr[0], *(ap_prof->prof_data)) == KAL_FALSE)
        {            
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONN_ACTION_NOT_DONE, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);
            g_srv_dtcnt_wlan_ctx.prev_state = g_srv_dtcnt_wlan_ctx.state;
            OslFreeDataPtr(p);
            return MMI_FALSE;
        }

        p->num_of_profile = 1;
        p->selection_mode = AP_AUTOMATIC_SELECT;
        p->more_flag = 0;
        p->connect_type = ap_prof->connect_type;
        p->handover_timer_value = WLAN_HANDOVER_TIMEOUT;
#ifdef __WAPI_SUPPORT__        
        if(temp_prof->wapi_ase_id != 0
            || temp_prof->wapi_client_id != 0
            || temp_prof->wapi_psk_format != 0
            || strlen((const char *)temp_prof->wapi_psk_str) != 0
            || strlen((const char *)temp_prof->wapi_private_key_passwd_str) != 0)
        {
            p->handover_timer_value = WLAN_HANDOVER_TIMEOUT_WAPI;
        }
#endif
        if(ap_prof->connect_type== START_WPS_PIN || ap_prof->connect_type==START_WPS_PBC)
        {
        	p->handover_timer_value = WLAN_HANDOVER_TIMEOUT_WPS;
        } 
        
        mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_CONNECT_REQ, (oslParaType *)p, NULL);

        res.prof_num = 1;
        res.prof_id[0] = temp_prof->profile_id;
        res.conn_type = ap_prof->connect_type;
        srv_dtcnt_wlan_post_conn_prof_event(&res);
        
        SetProtocolEventHandler(srv_dtcnt_wlan_connect_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
        g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_CONNECT_WAIT;
        srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_CONNECT);
        return MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_disconnect_req
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_disconnect_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __WPS_SUPPORT__
    srv_dtcnt_wlan_conn_res_struct *conn_res;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT)
    {
        return;
    }

    ASSERT(g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_INIT || 
           g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
           g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_CONNECTED);

    if(g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT)
    {
        ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
        
    #ifdef __WPS_SUPPORT__
        conn_res = OslMalloc(sizeof(srv_dtcnt_wlan_conn_res_struct));
        kal_mem_set(conn_res, 0, sizeof(srv_dtcnt_wlan_conn_res_struct));
        conn_res->result = SRV_DTCNT_RESULT_FAILED;
        conn_res->cancel_by_discon = MMI_TRUE;
        /* To notify DA App by callback */
        if (g_srv_dtcnt_wlan_ctx.proc_job_list)
        {
            srv_dtcnt_wlan_proc_job_list *cur_p = g_srv_dtcnt_wlan_ctx.proc_job_list;
            srv_dtcnt_wlan_conn_res_cb_func_ptr callback = (srv_dtcnt_wlan_conn_res_cb_func_ptr)cur_p->job.cb_func_ptr;
            callback(cur_p->job.user_data, conn_res);
            g_srv_dtcnt_wlan_ctx.proc_job_list = NULL;
            OslMfree(cur_p);
        }
        /* send event to notify applicaitons and DA App */        
        srv_dtcnt_wlan_post_conn_res_event(conn_res, EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND);
        OslMfree(conn_res);
    #endif
    }
    
    SetProtocolEventHandler(srv_dtcnt_wlan_disconnect_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_DISCONNECT_CNF);
    g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT;

    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_DISCONNECT_REQ, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_set_ps_mode_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_set_ps_mode_req(srv_dtcnt_wlan_power_mode_enum pwr_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_wifi_set_ps_mode_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_dtcnt_wlan_set_ps_mode_cnf_hdlr, MSG_ID_MMI_ABM_WIFI_SET_PS_MODE_CNF);

    p = OslAllocDataPtr(mmi_abm_wifi_set_ps_mode_req_struct);
    switch (pwr_mode)
    {
        case SRV_DTCNT_WLAN_WLAN_POWER_MODE_CAM:
            p->ps_mode = WNDRV_POWER_MODE_CAM;
            break;
        case SRV_DTCNT_WLAN_WLAN_POWER_MODE_FAST_PS:
            p->ps_mode = WNDRV_POWER_MODE_FAST_PS;
            break;
        case SRV_DTCNT_WLAN_WLAN_POWER_MODE_MAX_PS:
            p->ps_mode = WNDRV_POWER_MODE_MAX_PS;
            break;
        case SRV_DTCNT_WLAN_WLAN_POWER_MODE_CTIA:
            p->ps_mode = WNDRV_POWER_MODE_CTIA;
            break;
        default:
            MMI_ASSERT(0);
    }
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_SET_PS_MODE_REQ, (oslParaType *)p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_find_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ssid            [?]         
 *  ssid_len        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_dtcnt_prof_wlan_struct *srv_dtcnt_wlan_find_profile(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, total_num = (g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num + g_srv_dtcnt_wlan_setting_ctx.infra_prof_num);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(profile_id == 0) /* temp profile */
    {
        return NULL;
    }
    for (i = 0; i < total_num; i++)
    {
        if (g_srv_dtcnt_wlan_prof_list_p[i]->profile_id == profile_id)
        {
            return g_srv_dtcnt_wlan_prof_list_p[i];
        }
    }
    return NULL;

}

void srv_dtcnt_net_satus_ind_hdlr(void * info)
{
    mmi_abm_net_status_ind_struct * ind = NULL;
    srv_dtcnt_net_status_ind_evt_struct evt;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_NET_STATUS_IND);
    ind = (mmi_abm_net_status_ind_struct *)info;
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_NET_STATUS_IND); 
    evt.status = ind->status;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    
    if(ind->status == 0 || g_srv_dtcnt_wlan_ctx.state != SRV_DTCNT_WLAN_STATE_CONNECTED)
    {
        return;
    }

    #ifdef __MMI_OP01_WIFI__
    g_need_login_flag = MMI_FALSE;
    #endif
    if (g_srv_dtcnt_wlan_ctx.connected_wlan_profile)
    {
        srv_dtcnt_wlan_ipaddr_change_req(MMI_FALSE, NULL);
    }
    else
    {
        srv_dtcnt_wlan_ipaddr_change_qry_evt_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_QRY);
        evt.ipaddr_change_cb = (srv_dtcnt_ipaddr_change_qry_cb_func_ptr)srv_dtcnt_wlan_ipaddr_change_req;
        MMI_FRM_CB_EMIT_EVENT(&evt);        
    }    
    
}




#define WLAN_EXTERN_APIs

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_context_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_context_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, num_profs = 0;
    int error;
    MMI_BOOL error_flag = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&g_srv_dtcnt_wlan_prefer_ctx, 0, sizeof(srv_dtcnt_wlan_prefer_struct));
    ReadRecord(NVRAM_EF_CMCC_WIFI_SETTING_LID, 1, &g_srv_dtcnt_wlan_prefer_ctx, NVRAM_MAX_CMCC_WIFI_SETTING_SIZE, (S16 *)&error);
    
    kal_mem_set(&g_srv_dtcnt_wlan_ctx, 0, sizeof(srv_dtcnt_wlan_ctx_struct));

    ReadRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, (S16 *)&error);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONTEXT_READ_FROM_NVRAM, 
        sizeof(srv_dtcnt_wlan_setting_struct), g_srv_dtcnt_wlan_setting_ctx.infra_prof_num, g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num,
        g_srv_dtcnt_wlan_setting_ctx.profile_id_count, g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight, g_srv_dtcnt_wlan_setting_ctx.pwr_mode);
    if (g_srv_dtcnt_wlan_setting_ctx.profile_id_count == 0)
    {
        /* implies all wlan profile ID should larger than smart default account */
        g_srv_dtcnt_wlan_setting_ctx.profile_id_count = (CBM_DEFAULT_ACCT_ID + 1);
    }
        
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
    {
        ReadRecord(NVRAM_EF_WLAN_PROFILE_LID, (U8) (i + 1), &g_srv_dtcnt_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, (S16 *)&error);

        // MAUI_03344227 error handle       
        if(g_srv_dtcnt_wlan_prof_list[i].priority > 0)
        {
            for(j = 0; j < i; j++)
            {
                if(g_srv_dtcnt_wlan_prof_list[i].priority == g_srv_dtcnt_wlan_prof_list[j].priority)
                {
                    error_flag = MMI_TRUE;
                    break;
                }
            }
        }
        if(error_flag)
        {
            break;
        }
        
        if (g_srv_dtcnt_wlan_prof_list[i].priority > 0 && g_srv_dtcnt_wlan_prof_list[i].ssid_len)
        {
            g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_prof_list[i].priority - 1] = &g_srv_dtcnt_wlan_prof_list[i];
            num_profs++;
        }
        else
        {
            kal_mem_set(&g_srv_dtcnt_wlan_prof_list[i], 0, sizeof(srv_dtcnt_prof_wlan_struct));
        }
    }

    // MAUI_03344227 error handle  
    if(error_flag)
    {    
        num_profs = 0;
        for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
        {   
            memset(&g_srv_dtcnt_wlan_prof_list[i], 0, sizeof(srv_dtcnt_prof_wlan_struct));
            WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, (U8) (i + 1), &g_srv_dtcnt_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, (S16 *)&error);
        }            
        memset(&g_srv_dtcnt_wlan_setting_ctx, 0, sizeof(srv_dtcnt_wlan_setting_struct));
        WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, (S16 *)&error);
        if (g_srv_dtcnt_wlan_setting_ctx.profile_id_count == 0)
        {
            /* implies all wlan profile ID should larger than smart default account */
            g_srv_dtcnt_wlan_setting_ctx.profile_id_count = (CBM_DEFAULT_ACCT_ID + 1);
        }
    }

    for (i = num_profs; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
    {
        g_srv_dtcnt_wlan_prof_list_p[i] = NULL;
    }
#ifdef __MMI_OP01_WIFI__
    if(num_profs == 0)
    {
        srv_dtcnt_prof_wlan_struct cmcc_profile;
        U32 out_acc_id;

        memset(&cmcc_profile, 0, sizeof(srv_dtcnt_prof_wlan_struct));
        strncpy((CHAR*)cmcc_profile.ssid, "CMCC", 4);
        cmcc_profile.priority = 1;
        cmcc_profile.ssid_len = 4;
        cmcc_profile.use_dhcp = MMI_TRUE;
        cmcc_profile.network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
        cmcc_profile.auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
        cmcc_profile.ap_type = SRV_DTCNT_WLAN_AP_DEFAULT;
        mmi_wcscpy((WCHAR *)cmcc_profile.ProfName, L"CMCC");
        srv_dtcnt_db_store_add_wlan_prof(&cmcc_profile, SRV_DTCNT_WLAN_PROF_FIELD_ALL, &out_acc_id);
        
        memset(&cmcc_profile, 0, sizeof(srv_dtcnt_prof_wlan_struct));
        strncpy((CHAR*)cmcc_profile.ssid, "CMCC-EDU", 8);
        cmcc_profile.priority = 2;
        cmcc_profile.ssid_len = 8;
        cmcc_profile.use_dhcp = MMI_TRUE;
        cmcc_profile.network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
        cmcc_profile.auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
        cmcc_profile.ap_type = SRV_DTCNT_WLAN_AP_DEFAULT;
        mmi_wcscpy((WCHAR *)cmcc_profile.ProfName, L"CMCC-EDU");
        srv_dtcnt_db_store_add_wlan_prof(&cmcc_profile, SRV_DTCNT_WLAN_PROF_FIELD_ALL, &out_acc_id);
    }

#endif

#ifdef __MMI_OP01_WIFI__
    kal_mem_set(&g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list,
                0,
                sizeof(srv_dtcnt_wlan_proxy_exclusive_ip_addr_list_struct));

    for (i = 0; i < SRV_DTCNT_MAX_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM; i++)
    {
        ReadRecord(NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_LID,
                   (U8) (i + 1),
                   &g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i],
                   NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE,
                   (S16 *)&error);
        
        if ( strlen((const char *)g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i].ip_addr)==0 )
        {
            break;
        }
        else
        {
            kal_wap_trace(MOD_MMI_CONN_APP,MMI_CONN_TRC_G6_DTCNT,"[DA SRV WLAN]read URL: %s",g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.ips[i].ip_addr);    
            g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips++;
        }
    }
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM,
              g_srv_dtcnt_wlan_proxy_exclusive_ip_addr_list.num_ips);
#endif /* __MMI_OP01_WIFI__ */
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONTEXT_INIT, num_profs);      
    SetProtocolEventHandler(srv_dtcnt_wlan_wifi_activate_req_ind_hdlr, MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_IND);
    SetProtocolEventHandler(srv_dtcnt_wlan_wifi_deactivate_req_ind_hdlr, MSG_ID_MMI_ABM_WIFI_DEACTIVATE_REQ_IND);
    SetProtocolEventHandler(srv_dtcnt_wlan_atcmd_req_hdlr, MSG_ID_SRV_DTCNT_WLAN_ATCMD_REQ);
    //SetProtocolEventHandler(srv_dtcnt_wlan_wifi_ap_list_query_ind_hdlr, MSG_ID_MMI_ABM_WIFI_AP_LIST_QUERY_IND);
    SetProtocolEventHandler(srv_dtcnt_net_satus_ind_hdlr, MSG_ID_MMI_ABM_NET_STATUS_IND);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SHUTDOWN_DEINIT, srv_dtcnt_wlan_callback_handler, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_add_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  action      [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_add_action(srv_dtcnt_wlan_action_enum action, void *data, srv_dtcnt_wlan_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_action_struct *prev_action;
    srv_dtcnt_wlan_action_struct *temp_action;
    srv_dtcnt_wlan_action_struct **handle = &g_srv_dtcnt_wlan_ctx.actions;    
#ifdef __WPS_SUPPORT__
    srv_dtcnt_wlan_scan_res_ind_evt_struct evt;
#endif /* __WPS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_ADD_ACTION, action, job, g_srv_dtcnt_wlan_ctx.state);
    switch (action)
    {
        case SRV_DTCNT_WLAN_ACTION_INIT:
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DEINIT) != NULL)
            {
                srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_DEINIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
                if (job)
                {
                    srv_dtcnt_wlan_cb_func_ptr callback = (srv_dtcnt_wlan_cb_func_ptr)job->cb_func_ptr; 
                    callback(job->user_data, SRV_DTCNT_WLAN_REQ_RES_TERMINATED);
                }
                srv_dtcnt_wlan_post_init_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);
                return;
            }
            break;

        case SRV_DTCNT_WLAN_ACTION_DISCONNECT:
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_CONNECT) != NULL)
            {
                srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_CONNECT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
                srv_dtcnt_wlan_post_disc_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);
                return;
            }
            break;

        case SRV_DTCNT_WLAN_ACTION_DEINIT:
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_INIT) != NULL)
            {
                srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_INIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
                if (job)
                {
                    srv_dtcnt_wlan_cb_func_ptr callback = (srv_dtcnt_wlan_cb_func_ptr)job->cb_func_ptr; 
                    callback(job->user_data, SRV_DTCNT_WLAN_REQ_RES_TERMINATED);
                }
                srv_dtcnt_wlan_post_deinit_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);
                return;
            }
            break;

        case SRV_DTCNT_WLAN_ACTION_SCAN:
        case SRV_DTCNT_WLAN_ACTION_CONNECT:
            break;
        default:
            MMI_ASSERT(0);
    }

    /* Avoid duplicate actions */
    srv_dtcnt_wlan_delete_action(action, SRV_DTCNT_WLAN_ACTION_DEL_OPT_DUPLICATED);

    temp_action = (srv_dtcnt_wlan_action_struct*)OslMalloc(sizeof(srv_dtcnt_wlan_action_struct));
    temp_action->action = action;
    temp_action->data = data;
    if (job)
    {
        temp_action->job = (srv_dtcnt_wlan_job_struct*)OslMalloc(sizeof(srv_dtcnt_wlan_job_struct));
        kal_mem_cpy(temp_action->job, job, sizeof(srv_dtcnt_wlan_job_struct));
    }
    else
    {
        temp_action->job = NULL;
    }
    temp_action->next = NULL;
    
    if (*handle == NULL)
    {
        *handle = temp_action;
    }
    else
    {
        prev_action = *handle;
        while (prev_action->next != NULL)
        {
            prev_action = prev_action->next;
        }
        prev_action->next = temp_action;
    }

    /* Execute next action if we are not in waiting state. */
    switch (g_srv_dtcnt_wlan_ctx.state)
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
        case SRV_DTCNT_WLAN_STATE_INIT:
        case SRV_DTCNT_WLAN_STATE_CONNECTED:
            if(g_srv_dtcnt_wlan_ctx.scan_state == SRV_DTCNT_WLAN_SCAN_STATE_NULL)
            {
                srv_dtcnt_wlan_do_action();
            }
            break;
    #ifdef __WPS_SUPPORT__
        /* WPS cancel connection mechanism: Don't wait connect cnf and then send disconnect req directly */
        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
            if (action == SRV_DTCNT_WLAN_ACTION_DISCONNECT)
            {
                if( g_srv_dtcnt_wlan_ctx.actions->action == SRV_DTCNT_WLAN_ACTION_SCAN )
            {
                    srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_SCAN, SRV_DTCNT_WLAN_ACTION_DEL_OPT_NONE); 
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_SCAN_RESULT);
                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_SCAN_RES_IND);    
                    evt.scan_res.result = SRV_DTCNT_WLAN_SCAN_RESULT_DELETE;
                    MMI_FRM_CB_EMIT_POST_EVENT(&evt);                    
                }
                srv_dtcnt_wlan_do_action();
            }
            break;
    #endif
    }
    return;
}


srv_dtcnt_wlan_state_enum srv_dtcnt_wlan_prev_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_dtcnt_wlan_ctx.prev_state;
}

srv_dtcnt_wlan_scan_state_enum srv_dtcnt_wlan_scan_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_dtcnt_wlan_ctx.scan_state;
}

U32 srv_dtcnt_wlan_new_scan_job(srv_dtcnt_wlan_scan_res_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_scan_job_list *new_scan_job;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_NEW_SCAN_JOB, callback, g_srv_dtcnt_wlan_ctx.scan_state, g_srv_dtcnt_wlan_ctx.state);
    if (srv_dtcnt_wlan_scan_state() == SRV_DTCNT_WLAN_SCAN_STATE_ABORTING)
    {
        g_srv_dtcnt_wlan_ctx.scan_state = SRV_DTCNT_WLAN_SCAN_STATE_WAITING;
    }

    g_srv_dtcnt_wlan_ctx.scan_job_id++;
    if (callback)
    {
        /* First scan job request */
        if(g_srv_dtcnt_wlan_ctx.scan_job_list == NULL)
        {        
            /* prepare new scan job */
            new_scan_job = (srv_dtcnt_wlan_scan_job_list*)OslMalloc(sizeof(srv_dtcnt_wlan_scan_job_list));
            new_scan_job->job.cb_func_ptr = (void *)callback;
            new_scan_job->job.user_data = user_data;
            new_scan_job->next = NULL;
            new_scan_job->scan_job_id = g_srv_dtcnt_wlan_ctx.scan_job_id;
            g_srv_dtcnt_wlan_ctx.scan_job_list = new_scan_job;
        }
        else
        {
            srv_dtcnt_wlan_scan_job_list *scan_list_p = g_srv_dtcnt_wlan_ctx.scan_job_list;
            srv_dtcnt_wlan_scan_job_list *scan_list_tmp = NULL;

            while(scan_list_p)
            {
                scan_list_tmp = scan_list_p;
                scan_list_p = scan_list_p->next;
            }
            scan_list_p = (srv_dtcnt_wlan_scan_job_list*)OslMalloc(sizeof(srv_dtcnt_wlan_scan_job_list));
            scan_list_p->job.cb_func_ptr = (void *)callback;
            scan_list_p->job.user_data = user_data;
            scan_list_p->next = NULL;
            scan_list_p->scan_job_id = g_srv_dtcnt_wlan_ctx.scan_job_id;

            scan_list_tmp->next = scan_list_p;
        }
    }
    
    if (srv_dtcnt_wlan_scan_state() == SRV_DTCNT_WLAN_SCAN_STATE_NULL)
    {
        /* add scan command to action list */
        /* directly connect command || original inactive state */
        if ((srv_dtcnt_wlan_prev_state() == SRV_DTCNT_WLAN_STATE_NULL && srv_dtcnt_wlan_state() != SRV_DTCNT_WLAN_STATE_CONNECT_WAIT) ||
            srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_NULL ||
            srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DEINIT_WAIT)
        {
            srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_INIT, NULL, NULL);
            srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_SCAN, NULL, NULL);
        }
        else
        {
            if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DEINIT) != NULL)
            {
                srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_DEINIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
            }
            srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_SCAN, NULL, NULL);
        }
    }
    return g_srv_dtcnt_wlan_ctx.scan_job_id;
}

void srv_dtcnt_wlan_abort_scan_job(srv_dtcnt_wlan_scan_state_enum scan_state, U32 job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_scan_job_list *scan_list_cur = g_srv_dtcnt_wlan_ctx.scan_job_list;
    srv_dtcnt_wlan_scan_job_list *scan_list_prev = NULL;
    srv_dtcnt_wlan_scan_res_cb_func_ptr cb;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_ABORT_SCAN_JOB, job_id, scan_state);
    /* search scan list by job id */
    while (scan_list_cur)
    {
        /* matched found */
        if (scan_list_cur->scan_job_id == job_id)
        {
            /* first scan job */
            if (!scan_list_prev)
            {
                g_srv_dtcnt_wlan_ctx.scan_job_list = scan_list_cur->next;
            }
            else
            {
                scan_list_prev->next = scan_list_cur->next;
            }
            scan_list_cur->next = NULL;
            break;
        }
        else
        {
            scan_list_prev = scan_list_cur;
            scan_list_cur = scan_list_cur->next;
        }
    }

    /* found matched scan job */
    if (scan_list_cur)
    {       
        srv_dtcnt_wlan_scan_result_struct scan_res;
        
        /* cancel the latest scan job */
        if (!g_srv_dtcnt_wlan_ctx.scan_job_list)
        {
            /* reset commands in action list */
            if (srv_dtcnt_wlan_prev_state() == SRV_DTCNT_WLAN_STATE_NULL)
            {
                srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_DEINIT, NULL, NULL);
            }
            
            /* change state to aborting */
            if (scan_state == SRV_DTCNT_WLAN_SCAN_STATE_WAITING)
            {
                g_srv_dtcnt_wlan_ctx.scan_state = SRV_DTCNT_WLAN_SCAN_STATE_ABORTING;
            }
            else /* (not start yet) SRV_DTCNT_WLAN_SCAN_STATE_NULL */
            {
                srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_SCAN, SRV_DTCNT_WLAN_ACTION_DEL_OPT_NONE);
            }
        }

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_ABORT_SCAN_JOB_FOUND, g_srv_dtcnt_wlan_ctx.scan_state);

        /* release and feedback the aborted job */
        kal_mem_set(&scan_res, 0, sizeof(srv_dtcnt_wlan_scan_result_struct));
        scan_res.result = SRV_DTCNT_WLAN_SCAN_RESULT_ABORTED;
        scan_res.scan_job_id = scan_list_cur->scan_job_id;
        cb = (srv_dtcnt_wlan_scan_res_cb_func_ptr)scan_list_cur->job.cb_func_ptr;
            
        cb(scan_res.scan_job_id, scan_list_cur->job.user_data, &scan_res);
        OslMfree(scan_list_cur);
        
        /* post aborted event */
        srv_dtcnt_wlan_post_scan_res_event(&scan_res);
    }
    else
    {
        srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_SCAN, SRV_DTCNT_WLAN_ACTION_DEL_OPT_NONE);        
    }
}

void srv_dtcnt_wlan_clear_scan_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_scan_job_list *scan_list_cur = g_srv_dtcnt_wlan_ctx.scan_job_list;
    srv_dtcnt_wlan_scan_res_cb_func_ptr cb;
    srv_dtcnt_wlan_scan_result_struct scan_res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CLEAR_SCAN_ACTION);

    switch (g_srv_dtcnt_wlan_ctx.scan_state)
    {
        /* NULL --> delete action */
        case SRV_DTCNT_WLAN_SCAN_STATE_NULL:
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_SCAN, SRV_DTCNT_WLAN_ACTION_DEL_OPT_NONE);
            break;
        /* Waiting --> abort all */
        case SRV_DTCNT_WLAN_SCAN_STATE_WAITING:
            g_srv_dtcnt_wlan_ctx.scan_state = 
            SRV_DTCNT_WLAN_SCAN_STATE_ABORTING;
            break;
        /* aborting --> ignore */
        case SRV_DTCNT_WLAN_SCAN_STATE_ABORTING:
            return;
            
        default:
            ASSERT(0);
            break;
    }
    
    kal_mem_set(&scan_res, 0, sizeof(srv_dtcnt_wlan_scan_result_struct));
    scan_res.result = SRV_DTCNT_WLAN_SCAN_RESULT_ABORTED;
    
    /* clear scan job list */
    while (scan_list_cur)
    {
        g_srv_dtcnt_wlan_ctx.scan_job_list = scan_list_cur->next;

        /* release and feedback the aborted job */
        scan_res.scan_job_id = scan_list_cur->scan_job_id;
        cb = (srv_dtcnt_wlan_scan_res_cb_func_ptr)scan_list_cur->job.cb_func_ptr;            
        cb(scan_res.scan_job_id, scan_list_cur->job.user_data, &scan_res);
        OslMfree(scan_list_cur);

        scan_list_cur = g_srv_dtcnt_wlan_ctx.scan_job_list;
    }    
    
    /* post aborted event */
    srv_dtcnt_wlan_post_scan_res_event(&scan_res);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_post_init_res_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_post_init_res_event(srv_dtcnt_wlan_req_res_enum res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_init_res_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_INIT_RESULT);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND);    
    evt.res = res;
    kal_mem_cpy(evt.mac_addr, g_srv_dtcnt_wlan_ctx.mac_addr, WNDRV_MAC_ADDRESS_LEN);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_post_deinit_res_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_post_deinit_res_event(srv_dtcnt_wlan_req_res_enum res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_deinit_res_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_DEINIT_RESULT);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND);
    evt.res = res;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_post_disc_res_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_post_disc_res_event(srv_dtcnt_wlan_req_res_enum res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_disc_res_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_DISC_RESULT);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_DISC_RES_IND);    
    evt.res = res;    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_append_proc_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  action      [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_append_proc_job(srv_dtcnt_wlan_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_proc_job_list *proc_list = OslMalloc(sizeof(srv_dtcnt_wlan_proc_job_list));
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    proc_list->next = NULL;
    kal_mem_cpy(&(proc_list->job), job, sizeof(srv_dtcnt_wlan_job_struct));
    
    if (!g_srv_dtcnt_wlan_ctx.proc_job_list)
    {
        g_srv_dtcnt_wlan_ctx.proc_job_list = proc_list;
    }
    else
    {
        srv_dtcnt_wlan_proc_job_list *cur, *next;
        cur = g_srv_dtcnt_wlan_ctx.proc_job_list;
        next = g_srv_dtcnt_wlan_ctx.proc_job_list->next;
        while (next)
        {
            cur = next;
            next = cur->next;
        }
        cur->next = proc_list;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_eap_types
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [?]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_dtcnt_wlan_eap_types (U8 idx)
{
    return g_srv_dtcnt_wlan_eap_types[idx];
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_eap_peap_types
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [?]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_dtcnt_wlan_eap_peap_types (U8 idx)
{
    return g_srv_dtcnt_wlan_eap_peap_types[idx];
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_eap_ttls_types
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [?]
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_dtcnt_wlan_eap_ttls_types (U8 idx)
{
    return g_srv_dtcnt_wlan_eap_ttls_types[idx];
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_auto_pw_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_auto_pw_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef AUTO_POWER_ON
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_AUTO_PW_ON);
    
#ifdef __MMI_TETHERING_WIFI__
    if ( (g_srv_dtcnt_wlan_setting_ctx.init_on_bootup == MMI_TRUE || g_srv_dtcnt_wlan_prefer_ctx.need_awake == MMI_TRUE) && 
        #ifdef __MMI_OP01_WIFI__ 
        srv_mode_switch_is_network_service_available() && 
        #endif 
        srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS))
#else
    if ((g_srv_dtcnt_wlan_setting_ctx.init_on_bootup == MMI_TRUE || g_srv_dtcnt_wlan_prefer_ctx.need_awake == MMI_TRUE) 
        #ifdef __MMI_OP01_WIFI__
        && srv_mode_switch_is_network_service_available() 
        #endif
        )
#endif /* __MMI_TETHERING_WIFI__ */
    {
        if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
        {
            return;
        }

        #ifdef __MMI_OP01_WIFI__
        if ( (srv_dtcnt_wlan_auto_connect_num() != 0) && (g_srv_dtcnt_wlan_prefer_ctx.is_auto_conn)  )
        #else
        if (srv_dtcnt_wlan_auto_connect_num() != 0 )
        #endif
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_AUTO_PW_ON_DB_CONN);
            if (srv_dtcnt_wlan_connect_by_db_prof(NULL, NULL) != SRV_DTCNT_RESULT_PROCESSING)
            {
                MMI_ASSERT(0);
            }
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_AUTO_PW_ON_INIT);
            srv_dtcnt_wlan_init(NULL, NULL);
        }
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_hw_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_hw_reset(MMI_BOOL on_off_flag, srv_dtcnt_wlan_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (on_off_flag)
    {
#ifdef __MMI_TETHERING_WIFI__
    if (g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight == MMI_TRUE && 
        srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS))
#else
    if (g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight == MMI_TRUE)
#endif /* __MMI_TETHERING_WIFI__ */
        {
            if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
            {
                return;
            }

            if(g_srv_dtcnt_wlan_ctx.state != SRV_DTCNT_WLAN_STATE_NULL &&
                g_srv_dtcnt_wlan_ctx.state != SRV_DTCNT_WLAN_STATE_DEINIT_WAIT )
            {
                goto callback_done;
            }

	        #ifdef __MMI_OP01_WIFI__
            if ( (srv_dtcnt_wlan_auto_connect_num() != 0) && (g_srv_dtcnt_wlan_prefer_ctx.is_auto_conn) )
	        #else
	        if (srv_dtcnt_wlan_auto_connect_num() != 0 )
	        #endif
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_HW_RESET_ON_CONNECT);
                srv_dtcnt_wlan_connect_by_db_prof(NULL, NULL);
                if (g_srv_dtcnt_wlan_ctx.state > SRV_DTCNT_WLAN_STATE_DEINIT_WAIT)
                {
                    goto callback_done;
                }
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_HW_RESET_ON_INIT);
                if (srv_dtcnt_wlan_init(NULL, NULL) == SRV_DTCNT_RESULT_SUCCESS)
                {
                    goto callback_done;
                }
            }
            goto create_reset_job;
        }
    }
    else    /* hw_reset_off */
    {
        g_srv_dtcnt_wlan_prefer_ctx.need_awake = MMI_FALSE;
        if(g_srv_dtcnt_wlan_ctx.state != SRV_DTCNT_WLAN_STATE_NULL)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_HW_RESET_OFF_DEINIT);
            if (srv_dtcnt_wlan_deinit(NULL, NULL) == SRV_DTCNT_RESULT_SUCCESS)
            {
                goto callback_done;
            }
            goto create_reset_job;
        }
        if(g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_NULL)
        {
            srv_dtcnt_wlan_delete_action(SRV_DTCNT_WLAN_ACTION_INIT, SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED);
        }
    }

callback_done:    
    if(callback != NULL)
    {
        callback(user_data, SRV_DTCNT_WLAN_REQ_RES_DONE);
    }
    return;
    
create_reset_job:
    ASSERT(g_srv_dtcnt_wlan_ctx.hw_reset_job == NULL);
    if(callback != NULL)
    {
        g_srv_dtcnt_wlan_ctx.hw_reset_job = OslMalloc(sizeof(srv_dtcnt_wlan_job_struct));
        g_srv_dtcnt_wlan_ctx.hw_reset_job->cb_func_ptr = (void *)callback;
        g_srv_dtcnt_wlan_ctx.hw_reset_job->user_data = user_data;
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_save_profiles
 * DESCRIPTION
 *  This function save each profiles and update global context information
 * PARAMETERS
 *  i           :   [IN]    index of g_srv_dtcnt_wlan_prof_list
 *  replace     :   [IN]    replace flag
 *  old_network :   [IN]    network type of the replaced one
 *  dst_prof    :   [IN]    target profile buffer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_save_profiles(U8 i, U8 replace, srv_dtcnt_wlan_network_type_enum old_network, srv_dtcnt_prof_wlan_struct *dst_prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 j, k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SAVE_PROFILES, i, replace, old_network);
    /* replace profile */
    if(replace)
    {
        /* changed ap profile network_type */
        if(dst_prof->network_type != old_network)
        {
            /* adhoc -> Infrastructure*/
            if(dst_prof->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
            {
                for(j = (g_srv_dtcnt_wlan_prof_list[i].priority - 1); j > g_srv_dtcnt_wlan_setting_ctx.infra_prof_num; j--)
                {
                    g_srv_dtcnt_wlan_prof_list_p[j] = g_srv_dtcnt_wlan_prof_list_p[j - 1];
                    g_srv_dtcnt_wlan_prof_list_p[j]->priority++;
                }
                g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_setting_ctx.infra_prof_num] = &g_srv_dtcnt_wlan_prof_list[i];
                
                kal_mem_cpy(
                    g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_setting_ctx.infra_prof_num],
                    dst_prof, 
                    sizeof(srv_dtcnt_prof_wlan_struct));
                g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_setting_ctx.infra_prof_num]->priority = ++g_srv_dtcnt_wlan_setting_ctx.infra_prof_num;
                g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num--;
            }
            else /* Infrastructure -> adhoc */
            {
                for(j = (g_srv_dtcnt_wlan_prof_list[i].priority - 1); j < g_srv_dtcnt_wlan_setting_ctx.infra_prof_num - 1; j++)
                {
                    g_srv_dtcnt_wlan_prof_list_p[j] = g_srv_dtcnt_wlan_prof_list_p[j + 1];
                    g_srv_dtcnt_wlan_prof_list_p[j]->priority--;
                }
                g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_setting_ctx.infra_prof_num - 1] = &g_srv_dtcnt_wlan_prof_list[i];
                    
                kal_mem_cpy(
                    g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_setting_ctx.infra_prof_num - 1], 
                    dst_prof, 
                    sizeof(srv_dtcnt_prof_wlan_struct));
                g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_setting_ctx.infra_prof_num - 1]->priority = g_srv_dtcnt_wlan_setting_ctx.infra_prof_num;
                g_srv_dtcnt_wlan_setting_ctx.infra_prof_num--;
                g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num++;
            }
        }
        else /* same network type */
        {
            dst_prof->priority = g_srv_dtcnt_wlan_prof_list[i].priority;
            memcpy(&g_srv_dtcnt_wlan_prof_list[i], dst_prof, sizeof(srv_dtcnt_prof_wlan_struct));
        }
    }
    else /* new profile */
    {
        if (old_network == SRV_DTCNT_WLAN_NETWORK_TYPE_TOTAL)
        {
            k = i;
        }
        else
        {
            /* Find an empty slot index first */
            for (k = 0; k < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; k++)
            {
                if (g_srv_dtcnt_wlan_prof_list[k].ssid_len == 0)
                {
                    break;
                }
            }
        }

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SAVE_PROFILES_VALUES, g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num, g_srv_dtcnt_wlan_setting_ctx.infra_prof_num, g_srv_dtcnt_wlan_setting_ctx.profile_id_count);
        
        if(dst_prof->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
        {
            if(g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num == 0)
            {
                kal_mem_cpy(
                    &g_srv_dtcnt_wlan_prof_list[k], 
                    dst_prof, 
                    sizeof(srv_dtcnt_prof_wlan_struct));
                g_srv_dtcnt_wlan_prof_list[k].priority = ++g_srv_dtcnt_wlan_setting_ctx.infra_prof_num;
                g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_prof_list[k].priority - 1] = &g_srv_dtcnt_wlan_prof_list[k];
            }
            else /* adhon_prof_num > 0 */
            {
                j = g_srv_dtcnt_wlan_setting_ctx.infra_prof_num + g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num;
                for(; j > g_srv_dtcnt_wlan_setting_ctx.infra_prof_num; j--)
                {
                    g_srv_dtcnt_wlan_prof_list_p[j] = g_srv_dtcnt_wlan_prof_list_p[j-1];
                    g_srv_dtcnt_wlan_prof_list_p[j]->priority++;
                }                    
                kal_mem_cpy(
                    &g_srv_dtcnt_wlan_prof_list[k],
                    dst_prof, 
                    sizeof(srv_dtcnt_prof_wlan_struct));
                g_srv_dtcnt_wlan_prof_list[k].priority = g_srv_dtcnt_wlan_setting_ctx.infra_prof_num + 1;                
                g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_setting_ctx.infra_prof_num] = &g_srv_dtcnt_wlan_prof_list[k];
                g_srv_dtcnt_wlan_setting_ctx.infra_prof_num++;
            }            
            g_srv_dtcnt_wlan_prof_list[k].profile_id = ++g_srv_dtcnt_wlan_setting_ctx.profile_id_count;
        }
        else /* WLAN_NETWORK_TYPE_ADHOC */
        {
            g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num++;        
            kal_mem_cpy(
                &g_srv_dtcnt_wlan_prof_list[k],
                dst_prof,
                sizeof(srv_dtcnt_prof_wlan_struct));
            g_srv_dtcnt_wlan_prof_list[k].priority = g_srv_dtcnt_wlan_setting_ctx.infra_prof_num + g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num;;
            g_srv_dtcnt_wlan_prof_list[k].profile_id = ++g_srv_dtcnt_wlan_setting_ctx.profile_id_count;
            g_srv_dtcnt_wlan_prof_list_p[g_srv_dtcnt_wlan_prof_list[k].priority - 1] = &g_srv_dtcnt_wlan_prof_list[k];
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_is_invalid_ip_addr
 * DESCRIPTION
 *  Check if IP address is invalid
 * PARAMETERS
 *  ip_addr
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_dtcnt_wlan_is_invalid_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct *ip_addr)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ip_addr->ip_addr[0] == 0 &&
        ip_addr->ip_addr[1] == 0 &&
        ip_addr->ip_addr[2] == 0 &&
        ip_addr->ip_addr[3] == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


#define WLAN_ILM_HDLR

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_wifi_init_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_wifi_init_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 size = 0;
    mmi_abm_wifi_init_cnf_struct *cnf;
    srv_dtcnt_wlan_cb_func_ptr callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_INIT_CNF_HDLR, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);

    cnf = (mmi_abm_wifi_init_cnf_struct*) info;

    if(srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DEINIT) == NULL)
    {
    g_srv_dtcnt_wlan_prefer_ctx.need_awake = MMI_FALSE;
    
    size = WriteRecord(
            NVRAM_EF_CMCC_WIFI_SETTING_LID, 
            1, 
            (void*)&g_srv_dtcnt_wlan_prefer_ctx, 
            NVRAM_MAX_CMCC_WIFI_SETTING_SIZE, 
            (S16 *)&error);

    if(size < NVRAM_MAX_CMCC_WIFI_SETTING_SIZE)
    {
        MMI_ASSERT(0);
    }
    }
    
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_INIT_CNF);
    SetProtocolEventHandler(srv_dtcnt_wlan_curr_ap_info_ind_hdlr, MSG_ID_SUPC_MMI_WIFI_CURR_AP_INFO_IND);
    SetProtocolEventHandler(srv_dtcnt_wlan_connect_ind_hdlr, MSG_ID_MMI_ABM_WIFI_CONNECT_IND);
    SetProtocolEventHandler(srv_dtcnt_wlan_ipaddr_update_ind_hdlr, MSG_ID_MMI_ABM_IPADDR_UPDATE_IND);
#ifdef __WPS_SUPPORT__
    SetProtocolEventHandler(srv_dtcnt_wlan_wps_info_ind_hdlr, MSG_ID_MMI_ABM_WIFI_WPS_INFO_IND);
#endif

    g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_INIT;
    memcpy(g_srv_dtcnt_wlan_ctx.mac_addr, cnf->mac_addr, WNDRV_MAC_ADDRESS_LEN);

    /* To notify DA App by callback list */
    while(g_srv_dtcnt_wlan_ctx.proc_job_list)
    {
        srv_dtcnt_wlan_proc_job_list *cur_p = g_srv_dtcnt_wlan_ctx.proc_job_list;
        callback = (srv_dtcnt_wlan_cb_func_ptr)cur_p->job.cb_func_ptr;
        callback(cur_p->job.user_data, SRV_DTCNT_WLAN_REQ_RES_DONE);
        g_srv_dtcnt_wlan_ctx.proc_job_list = cur_p->next;
        OslMfree(cur_p);
    }

    /* check HW reset job exist */
    if (g_srv_dtcnt_wlan_ctx.hw_reset_job)
    {
        callback = (srv_dtcnt_wlan_cb_func_ptr)g_srv_dtcnt_wlan_ctx.hw_reset_job->cb_func_ptr;
        callback(g_srv_dtcnt_wlan_ctx.hw_reset_job->user_data, SRV_DTCNT_WLAN_REQ_RES_DONE);
        OslMfree(g_srv_dtcnt_wlan_ctx.hw_reset_job);
        g_srv_dtcnt_wlan_ctx.hw_reset_job = NULL;
    }

    /* post events to DA App and applications */
    srv_dtcnt_wlan_post_init_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);
    srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_ACTIVE);
    srv_dtcnt_wlan_post_bearer_status_event(SRV_DTCNT_WLAN_STATUS_ACTIVE);

    if(g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight == MMI_FALSE)
    {
        g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight = MMI_TRUE;
        //g_srv_dtcnt_wlan_setting_ctx.init_on_bootup = MMI_TRUE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
    {
            ASSERT(0);
        }
    }
    if(g_srv_dtcnt_wlan_setting_ctx.init_on_bootup == MMI_FALSE)
    {
        g_srv_dtcnt_wlan_setting_ctx.init_on_bootup = MMI_TRUE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }

    }    
        
    /* To check remain actions in queue */
    if (srv_dtcnt_wlan_do_action() == MMI_TRUE)
    {
        return;
    }

    /* If nothing to do then we can update the prev state */
    g_srv_dtcnt_wlan_ctx.prev_state = SRV_DTCNT_WLAN_STATE_INIT;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_wifi_deinit_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_wifi_deinit_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    //mmi_abm_wifi_init_cnf_struct *cnf;
    srv_dtcnt_wlan_cb_func_ptr callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DEINIT_CNF_HDLR, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);

    //cnf = (mmi_abm_wifi_init_cnf_struct*) info;
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DEINIT_CNF);
    ClearProtocolEventHandler(MSG_ID_SUPC_MMI_WIFI_CURR_AP_INFO_IND);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_CONNECT_IND);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_IPADDR_UPDATE_IND);
#ifdef __WPS_SUPPORT__
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_WPS_INFO_IND);
#endif
    g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_NULL;

    memset(g_srv_dtcnt_wlan_ctx.mac_addr, 0, WNDRV_MAC_ADDRESS_LEN);

    /* To notify DA App by callback list */
    while(g_srv_dtcnt_wlan_ctx.proc_job_list)
    {
        srv_dtcnt_wlan_proc_job_list *cur_p = g_srv_dtcnt_wlan_ctx.proc_job_list;
        callback = (srv_dtcnt_wlan_cb_func_ptr)cur_p->job.cb_func_ptr;        
        callback(cur_p->job.user_data, SRV_DTCNT_WLAN_REQ_RES_DONE);
        g_srv_dtcnt_wlan_ctx.proc_job_list = cur_p->next;
        OslMfree(cur_p);
    }

    /* post events to DA App and applications */
    if(g_srv_dtcnt_wlan_prefer_ctx.need_awake != MMI_TRUE)
    {
    srv_dtcnt_wlan_post_deinit_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);
    }
    srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_INACTIVE);
    srv_dtcnt_wlan_post_bearer_status_event(SRV_DTCNT_WLAN_STATUS_INACTIVE);

    /* To check remain actions in queue */
    if (srv_dtcnt_wlan_do_action() == MMI_TRUE)
    {
        return;
    }

    /* If nothing to do then we can update the prev state */
    g_srv_dtcnt_wlan_ctx.prev_state = SRV_DTCNT_WLAN_STATE_NULL;

    if(g_srv_dtcnt_wlan_setting_ctx.init_on_bootup == MMI_TRUE)
    {
        g_srv_dtcnt_wlan_setting_ctx.init_on_bootup = MMI_FALSE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }

    }

    /* check HW reset job exist */
    if(!g_srv_dtcnt_wlan_ctx.hw_reset_job)
    {
        g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight = MMI_FALSE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
    }
    else
    {
        callback = (srv_dtcnt_wlan_cb_func_ptr)g_srv_dtcnt_wlan_ctx.hw_reset_job->cb_func_ptr;
        callback(g_srv_dtcnt_wlan_ctx.hw_reset_job->user_data, SRV_DTCNT_WLAN_REQ_RES_DONE);
        OslMfree(g_srv_dtcnt_wlan_ctx.hw_reset_job);
        g_srv_dtcnt_wlan_ctx.hw_reset_job = NULL;
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_connect_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_connect_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_abm_wifi_connect_cnf_struct *cnf;
    srv_dtcnt_wlan_conn_res_struct *conn_res;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONNECT_CNF_HDLR, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);

    cnf = (mmi_abm_wifi_connect_cnf_struct*) info;

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
    SetProtocolEventHandler(srv_dtcnt_wlan_disconnect_ind_hdlr, MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND);
    SetProtocolEventHandler(srv_dtcnt_wlan_ipaddr_conflict_ind_hdlr, MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND);

    /* Prepare connect result */
    conn_res = OslMalloc(sizeof(srv_dtcnt_wlan_conn_res_struct));
    kal_mem_set(conn_res, 0, sizeof(srv_dtcnt_wlan_conn_res_struct));
    
    if (cnf->result == KAL_TRUE)
    {
        g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_CONNECTED;       
        g_srv_dtcnt_wlan_ctx.connected_wlan_profile = srv_dtcnt_wlan_find_profile(cnf->profile_id);

        conn_res->result = SRV_DTCNT_RESULT_SUCCESS;
        conn_res->cause = (supc_abm_cause_enum)cnf->cause;
        conn_res->channel_number = cnf->channel_number;
        conn_res->rssi = cnf->rssi;
        if (g_srv_dtcnt_wlan_ctx.connected_wlan_profile)
        {

        #ifdef __MMI_OP01_WIFI__
            if( (!strcmp("CMCC",(const char *)g_srv_dtcnt_wlan_ctx.connected_wlan_profile->ssid)||!strcmp("CMCC-EDU", (const char *)g_srv_dtcnt_wlan_ctx.connected_wlan_profile->ssid)) 
                && g_srv_dtcnt_wlan_ctx.connected_wlan_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN
                && g_srv_dtcnt_wlan_prefer_ctx.auto_portal_switch == 0)
            {
                g_need_login_flag = MMI_TRUE;
            }
            else
            {
                g_need_login_flag = MMI_FALSE;
            }
        #endif
            conn_res->profile_id = cnf->profile_id;
        }
        else
        {
        #ifdef __MMI_OP01_WIFI__
            if(g_srv_dtcnt_wlan_prefer_ctx.auto_portal_switch == 0 &&
            cnf->auth_type == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
            (!strcmp("CMCC",(const char *)cnf->ssid)||!strcmp("CMCC-EDU",(const char *)cnf->ssid)) )
            {
                g_need_login_flag = MMI_TRUE;
            }
            else
            {
                g_need_login_flag = MMI_FALSE;
            }            
        #endif
            conn_res->profile_id = 0;
        }
        g_srv_dtcnt_wlan_ctx.cur_ssid_len = conn_res->ssid_len = cnf->ssid_len;
        memcpy(conn_res->ssid, cnf->ssid, cnf->ssid_len);
        memset(g_srv_dtcnt_wlan_ctx.cur_ssid, 0, WNDRV_SSID_MAX_LEN);
        memcpy(g_srv_dtcnt_wlan_ctx.cur_ssid, cnf->ssid, cnf->ssid_len);
        memcpy(g_srv_dtcnt_wlan_ctx.cur_bssid, cnf->bssid, WNDRV_MAC_ADDRESS_LEN);
        memcpy(conn_res->bssid, cnf->bssid, WNDRV_MAC_ADDRESS_LEN);
    }
    else /* conntect failed case */
    {
        g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_INIT;
        conn_res->result = SRV_DTCNT_RESULT_FAILED;
        conn_res->cause = (supc_abm_cause_enum)cnf->cause;
    }

    conn_res->auth_type = cnf->auth_type;
    conn_res->eap_peap_auth_type = cnf->eap_peap_auth_type;
    conn_res->eap_ttls_auth_type = cnf->eap_ttls_auth_type;
    conn_res->conn_type = cnf->conn_type;
    conn_res->encry_mode = cnf->encry_mode;
    memcpy(conn_res->passphase, cnf->passphase, cnf->passphase_len);
    conn_res->passphase_len = cnf->passphase_len;

    /* To notify DA App by callback */
    if (g_srv_dtcnt_wlan_ctx.proc_job_list)
    {
        srv_dtcnt_wlan_proc_job_list *cur_p = g_srv_dtcnt_wlan_ctx.proc_job_list;
        srv_dtcnt_wlan_conn_res_cb_func_ptr callback = (srv_dtcnt_wlan_conn_res_cb_func_ptr)cur_p->job.cb_func_ptr;
        if( callback != NULL )
        {
            callback(cur_p->job.user_data, conn_res);
        }
        g_srv_dtcnt_wlan_ctx.proc_job_list = NULL;
        OslMfree(cur_p);
    }
    /* send event to notify applicaitons and DA App */        
    srv_dtcnt_wlan_post_conn_res_event(conn_res, EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND);
    OslMfree(conn_res);

    /* notify bearer status to applications */
    if (cnf->result == KAL_TRUE)
    {
    #ifdef __MMI_OP01_WIFI__
        memcpy(last_ssid, cnf->ssid, cnf->ssid_len);
        last_ssid_len = cnf->ssid_len;
    #endif
        srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_CONNECTED);
        srv_dtcnt_wlan_post_bearer_status_event(SRV_DTCNT_WLAN_STATUS_CONNECTED);
        
        /* set IP address info to ABM */
        if (g_srv_dtcnt_wlan_ctx.connected_wlan_profile)
        {
            srv_dtcnt_wlan_ipaddr_change_req(MMI_FALSE, NULL);
        }
        else
        {
            srv_dtcnt_wlan_ipaddr_change_qry_evt_struct evt;
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_QRY);
            evt.ipaddr_change_cb = (srv_dtcnt_ipaddr_change_qry_cb_func_ptr)srv_dtcnt_wlan_ipaddr_change_req;    
            MMI_FRM_CB_EMIT_EVENT(&evt);        
        }
    }
    else
    {
    #ifdef __MMI_OP01_WIFI__
        memset(last_ssid, 0, WNDRV_SSID_MAX_LEN);
        last_ssid_len = 0;
    #endif
        srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_ACTIVE);
        srv_dtcnt_wlan_post_bearer_status_event(SRV_DTCNT_WLAN_STATUS_ACTIVE);
    }
    if (srv_dtcnt_wlan_do_action() == MMI_TRUE)
    {
        return;
    }

    /* If nothing to do then we can update the prev state */
    g_srv_dtcnt_wlan_ctx.prev_state = g_srv_dtcnt_wlan_ctx.state;
    if(g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight == MMI_FALSE)
    {
        g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight = MMI_TRUE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_connect_ind_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_connect_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_wifi_connect_ind_struct *ind;
    srv_dtcnt_wlan_conn_res_struct *conn_res;   
#ifdef __MMI_OP01_WIFI__
    srv_dtcnt_wlan_switch_same_ssid_evt_struct switch_ind_evt;
#endif /* __MMI_OP01_WIFI__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CONNECT_IND_HDLR, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);

    if(SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT == g_srv_dtcnt_wlan_ctx.state)
    {
        return;
    }

    ind = (mmi_abm_wifi_connect_ind_struct*) info;

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_CONNECT_CNF);
    SetProtocolEventHandler(srv_dtcnt_wlan_ipaddr_conflict_ind_hdlr, MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND);
    SetProtocolEventHandler(srv_dtcnt_wlan_disconnect_ind_hdlr, MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND);

    /* Prepare connect result */
    conn_res = OslMalloc(sizeof(srv_dtcnt_wlan_conn_res_struct));
    kal_mem_set(conn_res, 0, sizeof(srv_dtcnt_wlan_conn_res_struct));
    
    g_srv_dtcnt_wlan_ctx.prev_state = g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_CONNECTED;    
    g_srv_dtcnt_wlan_ctx.connected_wlan_profile = srv_dtcnt_wlan_find_profile(ind->profile_id);
    conn_res->result = SRV_DTCNT_RESULT_SUCCESS;
    conn_res->channel_number = ind->channel_number;
    conn_res->rssi = ind->rssi;
    if (g_srv_dtcnt_wlan_ctx.connected_wlan_profile)
    {
        #ifdef __MMI_OP01_WIFI__
        if( (!strncmp("CMCC", (const char *)g_srv_dtcnt_wlan_ctx.connected_wlan_profile->ssid, g_srv_dtcnt_wlan_ctx.connected_wlan_profile->ssid_len)
            ||!strncmp("CMCC-EDU", (const char *)g_srv_dtcnt_wlan_ctx.connected_wlan_profile->ssid, g_srv_dtcnt_wlan_ctx.connected_wlan_profile->ssid_len)) 
            && g_srv_dtcnt_wlan_ctx.connected_wlan_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN
            && g_srv_dtcnt_wlan_prefer_ctx.auto_portal_switch == 0)
        {
            g_need_login_flag = MMI_TRUE;
        }
        else
        {
            g_need_login_flag = MMI_FALSE;
        }

        if((last_ssid_len==ind->ssid_len) && strncmp((const char *)last_ssid, (const char *)ind->ssid, ind->ssid_len) == 0)
        {
            g_need_login_flag = MMI_FALSE;
        }
        conn_res->need_login = g_need_login_flag;
        #endif

        conn_res->profile_id = ind->profile_id;
    }
    else
    {
        #ifdef __MMI_OP01_WIFI__
        if(g_srv_dtcnt_wlan_prefer_ctx.auto_portal_switch == 0
            && (!strncmp("CMCC",(const char *)ind->ssid,ind->ssid_len)||!strncmp("CMCC-EDU",(const char *)ind->ssid,ind->ssid_len)))
        {
            g_need_login_flag = MMI_TRUE;
        }
        else
        {
            g_need_login_flag = MMI_FALSE;
        } 
        conn_res->need_login = g_need_login_flag;
        #endif

        conn_res->profile_id = 0;
    }

    g_srv_dtcnt_wlan_ctx.cur_ssid_len = conn_res->ssid_len = ind->ssid_len;
    memcpy(conn_res->ssid, ind->ssid, ind->ssid_len);
    memset(g_srv_dtcnt_wlan_ctx.cur_ssid, 0, WNDRV_SSID_MAX_LEN);
    memcpy(g_srv_dtcnt_wlan_ctx.cur_ssid, ind->ssid, ind->ssid_len);
    memcpy(g_srv_dtcnt_wlan_ctx.cur_bssid, ind->bssid, WNDRV_MAC_ADDRESS_LEN);
    memcpy(conn_res->bssid, ind->bssid, WNDRV_MAC_ADDRESS_LEN);

    /* send event to notify applicaitons and DA App */
    srv_dtcnt_wlan_post_conn_res_event(conn_res, EVT_ID_SRV_DTCNT_WLAN_CONN_IND);
    OslMfree(conn_res);

    srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_CONNECTED);
    srv_dtcnt_wlan_post_bearer_status_event(SRV_DTCNT_WLAN_STATUS_CONNECTED);

    #ifdef __MMI_OP01_WIFI__
    if( (last_ssid_len==ind->ssid_len) && strncmp((const char *)last_ssid, (const char *)ind->ssid, ind->ssid_len) == 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SAME_SSID);
        MMI_FRM_INIT_EVENT(&switch_ind_evt, EVT_ID_SRV_DTCNT_WLAN_SWITCH_SAME_SSID_IND);
        MMI_FRM_CB_EMIT_POST_EVENT(&switch_ind_evt);         
        //return;
    }
    #endif

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
/* under construction !*/
/* under construction !*/
#endif    
}

void srv_dtcnt_wlan_ipaddr_change_cnf_hdlr()
{
    srv_dtcnt_wlan_ipaddr_change_cnf_evt_struct evt;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_IPADDR_CHANGE_CNF_HDLR);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_CNF);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);  
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_ipaddr_change_req
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_ipaddr_change_req(MMI_BOOL use_dhcp, srv_dtcnt_wlan_ipaddr_update_struct *ipaddr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_ipaddr_change_req_struct *p;
    srv_dtcnt_prof_wlan_struct *profile = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_IPADDR_CHANGE_REQ, use_dhcp, g_srv_dtcnt_wlan_ctx.state);
    if (g_srv_dtcnt_wlan_ctx.state != SRV_DTCNT_WLAN_STATE_CONNECTED)
    {
        return;
    }

    p = OslAllocDataPtr(mmi_abm_ipaddr_change_req_struct);
    DTCNT_SRV_ILM_MEMSET(p);

    if (g_srv_dtcnt_wlan_ctx.connected_wlan_profile != NULL)
    {
        profile = g_srv_dtcnt_wlan_ctx.connected_wlan_profile;
        p->use_dhcp = g_srv_dtcnt_wlan_ctx.connected_wlan_profile->use_dhcp;
    }
    else 
    {
        p->use_dhcp = use_dhcp;
        if (!use_dhcp)
        {
            MMI_ASSERT(ipaddr_info);
        }
    }

    if (p->use_dhcp)
    {
        goto send_change_req;
    }

    /* don't use dhcp, update the request info */
    if (profile)
    {
        memcpy(p->ip_addr, profile->ip_addr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        memcpy(p->netmask, profile->netmask, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        memcpy(p->gateway, profile->gateway, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        if(profile->dns1[0] == 0 && profile->dns1[1] == 0 && profile->dns1[2] == 0 && profile->dns1[3] == 0)
        {
            memcpy(p->pri_dns_addr, profile->dns2, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        }
        else
        {
            memcpy(p->pri_dns_addr, profile->dns1, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        }    
        memcpy(p->sec_dns_addr, profile->dns2, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }
    else
    {
        memcpy(p->ip_addr, ipaddr_info->ip_addr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        memcpy(p->netmask, ipaddr_info->netmask, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        memcpy(p->gateway, ipaddr_info->gateway, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        if(ipaddr_info->dns1[0] == 0 && ipaddr_info->dns1[1] == 0 && ipaddr_info->dns1[2] == 0 && ipaddr_info->dns1[3] == 0)
        {
            memcpy(p->pri_dns_addr, ipaddr_info->dns2, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        }
        else
        {
            memcpy(p->pri_dns_addr, ipaddr_info->dns1, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        }    
        memcpy(p->sec_dns_addr, ipaddr_info->dns2, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }
send_change_req:
    #ifdef __MMI_OP01_WIFI__
    SetProtocolEventHandler(srv_dtcnt_wlan_ipaddr_change_cnf_hdlr,MSG_ID_MMI_ABM_IPADDR_CHANGE_CNF);
    if(g_need_login_flag == MMI_TRUE)
    {
        p->need_portal_verify = MMI_TRUE;
    }
    else
    {
        p->need_portal_verify = MMI_FALSE;
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_WLAN_NEED_PORTAL_VERIFY,p->need_portal_verify);
    #endif
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_IPADDR_CHANGE_REQ, (oslParaType *)p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_curr_ap_info_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_curr_ap_info_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    supc_mmi_wifi_curr_ap_info_ind_struct *ind;
    srv_dtcnt_wlan_curr_ap_info_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CURR_AP_INFO_HDLR, g_srv_dtcnt_wlan_ctx.state);
    ind = (supc_mmi_wifi_curr_ap_info_ind_struct*) info;

    g_srv_dtcnt_wlan_ctx.cur_ap_info.rssi = (S32) ind->rssi;
    g_srv_dtcnt_wlan_ctx.cur_ap_info.current_data_rate = ind->current_data_rate;
    g_srv_dtcnt_wlan_ctx.cur_ap_info.ht_current_data_rate = ind->ht_current_data_rate;

    /* notify Applications */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_CURR_AP_INFO);
    kal_mem_cpy(&(evt.curr_ap_info), &(g_srv_dtcnt_wlan_ctx.cur_ap_info), sizeof(srv_dtcnt_wlan_curr_ap_info_struct));
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);    
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_ipaddr_update_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_ipaddr_update_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_ipaddr_update_ind_struct *ind;
    srv_dtcnt_wlan_ipaddr_update_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (mmi_abm_ipaddr_update_ind_struct*) info;

    /* notify Applications */
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_IPADDR_UPDATE_IND_HDLR);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_IPADDR_UPDATE);
    memcpy(evt.new_ipaddr.ip_addr, ind->ip_addr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(evt.new_ipaddr.netmask, ind->netmask, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(evt.new_ipaddr.gateway, ind->gateway, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(evt.new_ipaddr.dns1, ind->pri_dns_addr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy(evt.new_ipaddr.dns2, ind->sec_dns_addr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_ipaddr_conflict_ind_hdlr
 * DESCRIPTION
 *  send request to query wps state
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_ipaddr_conflict_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_ipaddr_conflict_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* notify Applications */
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_IPADDR_CONFLICT_IND_HDLR);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_IPADDR_CONFLICT_IND);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_disconnect_ind_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_disconnect_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DISCONNECT_IND_HDLR, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DISCONNECT_CNF);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND);

    g_srv_dtcnt_wlan_ctx.prev_state = g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_INIT;    
    g_srv_dtcnt_wlan_ctx.connected_wlan_profile = NULL;
    g_srv_dtcnt_wlan_ctx.cur_ssid_len = 0;
    memset(g_srv_dtcnt_wlan_ctx.cur_ssid, 0, WNDRV_SSID_MAX_LEN);
    memset(g_srv_dtcnt_wlan_ctx.cur_bssid, 0, WNDRV_MAC_ADDRESS_LEN);
    memset(&(g_srv_dtcnt_wlan_ctx.cur_ap_info), 0, sizeof(srv_dtcnt_wlan_curr_ap_info_struct));

    #ifdef __MMI_OP01_WIFI__
    memset(last_ssid, 0, WNDRV_SSID_MAX_LEN);
    last_ssid_len = 0;
    #endif
    if(g_srv_dtcnt_wlan_ctx.proc_job_list)
    {
        srv_dtcnt_wlan_proc_job_list *cur_p = g_srv_dtcnt_wlan_ctx.proc_job_list;
        if(cur_p->job.cb_func_ptr == NULL)
        {
            g_srv_dtcnt_wlan_ctx.proc_job_list = NULL;
            OslMfree(cur_p);
        }
    }
    srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_DISC_IND);
    srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_ACTIVE);
    srv_dtcnt_wlan_post_bearer_status_event(SRV_DTCNT_WLAN_STATUS_ACTIVE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_disconnect_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_disconnect_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_DISCONNECT_CNF_HDLR, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DISCONNECT_CNF);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_DISCONNECT_IND);
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_IPADDR_CONFLICT_IND);

    g_srv_dtcnt_wlan_ctx.state = SRV_DTCNT_WLAN_STATE_INIT;    
    g_srv_dtcnt_wlan_ctx.connected_wlan_profile = NULL;
    g_srv_dtcnt_wlan_ctx.cur_ssid_len = 0;
    memset(g_srv_dtcnt_wlan_ctx.cur_ssid, 0, WNDRV_SSID_MAX_LEN);
    memset(g_srv_dtcnt_wlan_ctx.cur_bssid, 0, WNDRV_MAC_ADDRESS_LEN);
    memset(&(g_srv_dtcnt_wlan_ctx.cur_ap_info), 0, sizeof(srv_dtcnt_wlan_curr_ap_info_struct));

    if(g_srv_dtcnt_wlan_ctx.proc_job_list)
    {
        srv_dtcnt_wlan_proc_job_list *cur_p = g_srv_dtcnt_wlan_ctx.proc_job_list;
        g_srv_dtcnt_wlan_ctx.proc_job_list = NULL;
        OslMfree(cur_p);
        srv_dtcnt_wlan_post_disc_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);
    }
    else
    {
        srv_dtcnt_wlan_post_disc_res_event(SRV_DTCNT_WLAN_REQ_RES_ADD_BY_SRV);
    }

    srv_dtcnt_wlan_post_state_event(EVT_ID_SRV_DTCNT_WLAN_ACTIVE);
    srv_dtcnt_wlan_post_bearer_status_event(SRV_DTCNT_WLAN_STATUS_ACTIVE);

    #ifdef __MMI_OP01_WIFI__
    memset(last_ssid, 0, WNDRV_SSID_MAX_LEN);
    last_ssid_len = 0;
    #endif

    
    if (srv_dtcnt_wlan_do_action() == MMI_TRUE)
    {
        return;
    }

    /* If nothing to do then we can update the prev state */
    g_srv_dtcnt_wlan_ctx.prev_state = g_srv_dtcnt_wlan_ctx.state;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_wifi_activate_req_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_wifi_activate_req_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_wifi_activate_req_rej_struct *p;
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_OP01_WIFI__))
    srv_dtcnt_wlan_search_ap_open_ind_evt_struct search_ap_open_ind_evt;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not allowed when flight mode switching is in progress */
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_WIFI_ACTIVATE_REQ_IND);

    if(srv_dtcnt_wlan_check_chip_status() == MMI_FALSE)
    {
        return;
    }

#ifdef __MMI_TETHERING_WIFI__
    if (g_srv_dtcnt_wlan_ctx.hw_reset_job ||!srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS))
#else
    if (g_srv_dtcnt_wlan_ctx.hw_reset_job)
#endif /* __MMI_TETHERING_WIFI__ */

    {
        p = OslAllocDataPtr(mmi_abm_wifi_activate_req_rej_struct);
        p->cause = WLAN_NOT_AVAILABLE;
        
        mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_ACTIVATE_REQ_REJ, (oslParaType *)p, NULL);
        return;
    }
    else if (g_srv_dtcnt_wlan_ctx.state == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT)
    {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        return;
    }

#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_OP01_WIFI__))
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_SEARCH_AP_OPEN_IND);
    MMI_FRM_INIT_EVENT(&search_ap_open_ind_evt, EVT_ID_SRV_DTCNT_WLAN_SEARCH_AP_OPEN_IND);    
    search_ap_open_ind_evt.rsp_callback = srv_dtcnt_wlan_search_ap_open_ind_callback;
    MMI_FRM_CB_EMIT_POST_EVENT(&search_ap_open_ind_evt);
#else
    srv_dtcnt_wlan_connect_by_db_prof(NULL, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_wifi_deactivate_req_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_wifi_deactivate_req_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_OP01_WIFI__))
    srv_dtcnt_wlan_search_ap_close_ind_evt_struct search_ap_close_ind_evt;
    #ifdef __MMI_OP01_WIFI__
    srv_dtcnt_wlan_logout_evt_struct logout_ind_evt;
    #endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Not allowed when flight mode switching is in progress */
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_OP01_WIFI__))
#ifdef __MMI_TETHERING_WIFI__
    if (g_srv_dtcnt_wlan_ctx.hw_reset_job ||!srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS))
#else
    if (g_srv_dtcnt_wlan_ctx.hw_reset_job)
#endif /* __MMI_TETHERING_WIFI__ */
#else
#ifdef __MMI_TETHERING_WIFI__
    if (g_srv_dtcnt_wlan_ctx.hw_reset_job || !srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS) ||
        (!g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num && !g_srv_dtcnt_wlan_setting_ctx.infra_prof_num))
#else
    if (g_srv_dtcnt_wlan_ctx.hw_reset_job ||
        (!g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num && !g_srv_dtcnt_wlan_setting_ctx.infra_prof_num))
#endif /* __MMI_TETHERING_WIFI__ */
#endif
    {
        mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_DEACTIVATE_REQ_REJ, NULL, NULL);
        return;
    }
    
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_OP01_WIFI__))
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_SEARCH_AP_CLOSE_IND);
    MMI_FRM_INIT_EVENT(&search_ap_close_ind_evt, EVT_ID_SRV_DTCNT_WLAN_SEARCH_AP_CLOSE_IND);
    MMI_FRM_CB_EMIT_POST_EVENT(&search_ap_close_ind_evt);
#endif

#ifdef __MMI_OP01_WIFI__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_LOGOUT_IND);
    MMI_FRM_INIT_EVENT(&logout_ind_evt, EVT_ID_SRV_DTCNT_WLAN_LOGOUT_IND);
    logout_ind_evt.rsp_callback = srv_dtcnt_wlan_logout_callback;
    MMI_FRM_CB_EMIT_POST_EVENT(&logout_ind_evt); 
#else
    srv_dtcnt_wlan_disconnect();
#endif
}




/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_ap_list_cnf_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_ap_list_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 i, ap_list_num;
    mmi_abm_wifi_ap_list_cnf_struct *cnf;
    U32 check_scan_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_LIST_CNF_HDLR, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);

    cnf = (mmi_abm_wifi_ap_list_cnf_struct*) info;

    if (cnf->result == KAL_TRUE)
    {
        /* scan success */
        if (g_srv_dtcnt_wlan_ctx.scan_state != SRV_DTCNT_WLAN_SCAN_STATE_NULL)
        {
            ap_list_num = g_srv_dtcnt_wlan_ctx.ap_list_num;

            for (i = 0; i < cnf->num && ap_list_num < SRV_DTCNT_WLAN_MAX_AP_LIST_NUM; i++)
            {
                if (cnf->ap_list[i].ssid_len == 0 || cnf->ap_list[i].ssid[0] == 0)
                {
                    continue;   /* Discard hidden AP */
                }
            #ifdef __WAPI_SUPPORT__
                if (MMI_TRUE == g_srv_dtcnt_wlan_setting_ctx.wapi_test_mode && 
                    (KAL_TRUE == cnf->ap_list[i].rsn_ie_info_p || KAL_TRUE == cnf->ap_list[i].wpa_ie_info_p ||
                    (cnf->ap_list[i].privacy > 0 && KAL_FALSE == cnf->ap_list[i].wapi_ie_info_p)))
                {
                    continue;   /* Discard hidden AP */
                }                
            #endif
                
            #ifdef WIFI_AUTH_PSK_ONLY
                if(cnf->ap_list[i].rsn_ie_info_p == MMI_TRUE 
                    && (cnf->ap_list[i].rsn_ie_info.key_mgmt == WPA_KEY_MGMT_IEEE8021X
                    || cnf->ap_list[i].rsn_ie_info.key_mgmt == WPA_KEY_MGMT_IEEE8021X_NO_WPA
                    || cnf->ap_list[i].rsn_ie_info.key_mgmt == WAPI_KEY_MGMT_WAI))
                {
                    continue;
                }
                if(cnf->ap_list[i].wpa_ie_info_p == MMI_TRUE
                    && (cnf->ap_list[i].wpa_ie_info.key_mgmt == WPA_KEY_MGMT_IEEE8021X
                    || cnf->ap_list[i].wpa_ie_info.key_mgmt == WPA_KEY_MGMT_IEEE8021X_NO_WPA
                    || cnf->ap_list[i].wpa_ie_info.key_mgmt == WAPI_KEY_MGMT_WAI))
                {
                    continue;
                }
                #ifdef __WAPI_SUPPORT__
                if(cnf->ap_list[i].wapi_ie_info_p == MMI_TRUE
                    && (cnf->ap_list[i].wpa_ie_info.key_mgmt == WPA_KEY_MGMT_IEEE8021X
                    || cnf->ap_list[i].wpa_ie_info.key_mgmt == WPA_KEY_MGMT_IEEE8021X_NO_WPA
                    || cnf->ap_list[i].wpa_ie_info.key_mgmt == WAPI_KEY_MGMT_WAI) )
                {
                    continue;
                }
                #endif
            #endif
                
                memcpy(&g_srv_dtcnt_wlan_ctx.ap_list[ap_list_num++], &cnf->ap_list[i], sizeof(supc_abm_bss_info_struct));
            }
            g_srv_dtcnt_wlan_ctx.ap_list_num = ap_list_num;

            if (cnf->more_flag != 0)
            {
                return;
            }
        }
    }
    
    /* received all ap list confirm messages */
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_AP_LIST_CNF);
    if (g_srv_dtcnt_wlan_ctx.scan_state == SRV_DTCNT_WLAN_SCAN_STATE_ABORTING)
    {
        MMI_ASSERT(!g_srv_dtcnt_wlan_ctx.scan_job_list);
    }
    else    /* SRV_DTCNT_WLAN_SCAN_STATE_WAITING */
    {
        srv_dtcnt_wlan_scan_result_struct scan_res;
        kal_mem_set(&scan_res, 0, sizeof(srv_dtcnt_wlan_scan_result_struct));
        if (cnf->result == KAL_TRUE)
        {
            scan_res.result = SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS;
            scan_res.ap_list_num = g_srv_dtcnt_wlan_ctx.ap_list_num;
            for (ap_list_num = 0; ap_list_num < g_srv_dtcnt_wlan_ctx.ap_list_num ; ap_list_num++)
            {
                scan_res.ap_list[ap_list_num] = &(g_srv_dtcnt_wlan_ctx.ap_list[ap_list_num]);
            }
        }
        else
        {
            scan_res.result = SRV_DTCNT_WLAN_SCAN_RESULT_FAILED;
        }

        while (g_srv_dtcnt_wlan_ctx.scan_job_list)
        {
            /* release and feedback the scan job */
            srv_dtcnt_wlan_scan_job_list *cur_job = g_srv_dtcnt_wlan_ctx.scan_job_list;
            srv_dtcnt_wlan_scan_res_cb_func_ptr callback = (srv_dtcnt_wlan_scan_res_cb_func_ptr)cur_job->job.cb_func_ptr;
            scan_res.scan_job_id = cur_job->scan_job_id;
            check_scan_id = cur_job->scan_job_id;
            callback(scan_res.scan_job_id, cur_job->job.user_data, &scan_res);
            if(g_srv_dtcnt_wlan_ctx.scan_job_list != NULL)
            {
                if(srv_dtcnt_scan_job_exist(check_scan_id))
                {
            g_srv_dtcnt_wlan_ctx.scan_job_list = cur_job->next;
            OslMfree(cur_job);           
        }
            }
           
        }

        /* post scan result event */
        srv_dtcnt_wlan_post_scan_res_event(&scan_res);

    }
    
    g_srv_dtcnt_wlan_ctx.scan_state = SRV_DTCNT_WLAN_SCAN_STATE_NULL;    
    if (cnf->result == KAL_FALSE)
    {
        return;
    }
    
    if (srv_dtcnt_wlan_do_action() == MMI_TRUE)
    {
        return;
    }

    /* If nothing to do then we can remove the progress screen and update the prev state */
    g_srv_dtcnt_wlan_ctx.prev_state = g_srv_dtcnt_wlan_ctx.state;
    if(g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight == MMI_FALSE)
    {
        g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight = MMI_TRUE;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_atcmd_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_atcmd_req_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_atcmd_req_struct *req = (srv_dtcnt_wlan_atcmd_req_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    //MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_LIST_CNF_HDLR, g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state);
    /*
    kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G6_DTCNT, 
        "[DA SRV] srv_dtcnt_wlan_atcmd_req_hdlr, [AT-CMD] Opcode:%d, Len:%d, SSID: %s",
        req->opcode, req->cmd_length, req->cmd_buf);
    */

    switch (req->opcode)
    {
        case SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_ADD_PROF:
        {
            srv_dtcnt_prof_wlan_struct profile;
            U32 acc_id;
            
            /* prepare default wlan profile */
            srv_dtcnt_wlan_init_profile(&profile);

            /* copy the SSID to name and SSID */
            
            if (req->cmd_length > SRV_DTCNT_PROF_MAX_SSID_LEN)
            {
                profile.ssid_len = SRV_DTCNT_PROF_MAX_SSID_LEN;
            }
            else
            {
                profile.ssid_len = (U8)req->cmd_length;
            }
            mmi_asc_n_to_ucs2((S8 *)profile.ProfName, (S8 *)req->cmd_buf, profile.ssid_len);
            memcpy(profile.ssid, req->cmd_buf, profile.ssid_len);
            
            /* find free slot to add wlan profile */
            srv_dtcnt_db_store_add_wlan_prof(&profile, SRV_DTCNT_WLAN_PROF_FIELD_ALL, &acc_id);
            
            return;
        }
        case SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_CONN_PROF:
        {
            int i;
            srv_dtcnt_wlan_conn_prof_struct prof;
            
            /* search the ap profile by SSID */
            for (i=0; i<SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
            {
                if (!strcmp((char *)g_srv_dtcnt_wlan_prof_list_p[i]->ssid, (char *)req->cmd_buf))
                {
                    prof.num_prof = 1;
                    prof.prof_data = &(g_srv_dtcnt_wlan_prof_list_p[i]);

                    #ifdef __MTK_TARGET__    
                    /* disable power saving and roaming */
                    disable_PS_mode(MOD_MMI);
                    #endif /* __MTK_TARGET */
                    
                    /* connect the specified AP */
                    srv_dtcnt_wlan_connect_by_app_prof(&prof, NULL, NULL);                    
                    break;
                }
            }
            return;
        }
        case SRV_DTCNT_WLAN_WLAN_ATCMD_OPCODE_DEL_PROF:
        {
            int i;

            /* search the ap profile by SSID */
            for (i=0; i<SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
            {
                if (!strcmp((char *)g_srv_dtcnt_wlan_prof_list_p[i]->ssid, (char *)req->cmd_buf))
                {                        
                    /* delete the specified AP */
                    srv_dtcnt_db_store_del_wlan_profile(g_srv_dtcnt_wlan_prof_list_p[i]->profile_id);
                    break;
                }
            }
            return;
        }
        
        default:
            ASSERT(0);
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_set_ps_mode_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_set_ps_mode_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    mmi_abm_wifi_set_ps_mode_cnf_struct *cnf;
    srv_dtcnt_wlan_cb_func_ptr callback;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    cnf = (mmi_abm_wifi_set_ps_mode_cnf_struct*) info;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_SET_PS_MODE_CNF_HDLR,
        g_srv_dtcnt_wlan_ctx.prev_state, g_srv_dtcnt_wlan_ctx.state, cnf->ps_mode, cnf->status);

    ClearProtocolEventHandler(MSG_ID_MMI_ABM_WIFI_SET_PS_MODE_CNF);

    /* check set power mode job exist */
    if (g_srv_dtcnt_wlan_ctx.set_pwr_mode_job)
    {
        callback = (srv_dtcnt_wlan_cb_func_ptr)g_srv_dtcnt_wlan_ctx.set_pwr_mode_job->cb_func_ptr;
        if (cnf->status == KAL_TRUE)
        {
            callback(g_srv_dtcnt_wlan_ctx.set_pwr_mode_job->user_data, SRV_DTCNT_WLAN_REQ_RES_DONE);
        }
        else
        {
            callback(g_srv_dtcnt_wlan_ctx.set_pwr_mode_job->user_data, SRV_DTCNT_WLAN_REQ_RES_FAILED);
        }
        OslMfree(g_srv_dtcnt_wlan_ctx.set_pwr_mode_job);
        g_srv_dtcnt_wlan_ctx.set_pwr_mode_job = NULL;
    }

    if(cnf->status == KAL_TRUE)
    {
        g_srv_dtcnt_wlan_setting_ctx.pwr_mode = (srv_dtcnt_wlan_power_mode_enum)cnf->ps_mode;
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
    }    
}

srv_dtcnt_prof_wlan_struct * srv_dtcnt_wlan_get_connecting_prof(void)
{
    return &g_srv_dtcnt_wlan_connecting_prof;
}



/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_wifi_ap_list_query_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_wifi_ap_list_query_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP01_WIFI__
    srv_dtcnt_wlan_ap_list_query_ind_evt_struct ap_list_query_ind_evt;
#else
    mmi_abm_wifi_ap_list_query_rsp_struct *p;
#endif /* __MMI_OP01_WIFI__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_WIFI_AP_LIST_QUERY_IND_HDLR);

#ifdef __MMI_OP01_WIFI__
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_AP_LIST_QUERY_IND);
    
    MMI_FRM_INIT_EVENT(&ap_list_query_ind_evt, EVT_ID_SRV_DTCNT_WLAN_AP_LIST_QUERY_IND);
    ap_list_query_ind_evt.rsp_callback = srv_dtcnt_wlan_ap_list_query_ind_callback;
    MMI_FRM_CB_EMIT_POST_EVENT(&ap_list_query_ind_evt);
#else
    p = OslAllocDataPtr(mmi_abm_wifi_ap_list_query_rsp_struct);
    p->ap_num = 0;

    //mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_WIFI_AP_LIST_QUERY_RSP, (oslParaType *)p, NULL);
#endif /* __MMI_OP01_WIFI__ */
}

#ifdef __WPS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_wps_info_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_wlan_wps_info_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_wifi_wps_info_ind_struct *ind;
    srv_dtcnt_wlan_wps_info_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_WPS_INFO_HDLR, g_srv_dtcnt_wlan_ctx.state);
    ind = (mmi_abm_wifi_wps_info_ind_struct*) info;

    /* notify Applications */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_WPS_INFO);
    evt.num = ind->num;
    kal_mem_cpy(&(evt.info), &(ind->info), sizeof(wifi_wps_ui_info_struct)*2);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);    
}
#endif
#ifdef __MMI_TETHERING_WIFI__
srv_dtcnt_result_enum srv_dtcnt_wlan_init_stop_tethering(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data)
{
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        srv_dtcnt_wlan_job_struct new_wlan_job;        
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_INIT_REQ, srv_dtcnt_wlan_prev_state(), srv_dtcnt_wlan_state());
        switch (srv_dtcnt_wlan_state())
        {
            case SRV_DTCNT_WLAN_STATE_NULL:
            case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
                if (callback)
                {
                    new_wlan_job.cb_func_ptr = (void *)callback;
                    new_wlan_job.user_data = user_data;
                    srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_INIT, NULL, &new_wlan_job);
                }
                else
                {
                    srv_dtcnt_wlan_add_action(SRV_DTCNT_WLAN_ACTION_INIT, NULL, NULL);
                }
                return SRV_DTCNT_RESULT_PROCESSING;   
            case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
            case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
            case SRV_DTCNT_WLAN_STATE_INIT:
            case SRV_DTCNT_WLAN_STATE_CONNECTED:
                if (callback)
                {
                    callback(user_data, SRV_DTCNT_WLAN_REQ_RES_DONE);
                }
                srv_dtcnt_wlan_post_init_res_event(SRV_DTCNT_WLAN_REQ_RES_DONE);
                return SRV_DTCNT_RESULT_SUCCESS;    
            case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
                if (callback)
                {
                    new_wlan_job.cb_func_ptr = (void *)callback;
                    new_wlan_job.user_data = user_data;
                    srv_dtcnt_wlan_append_proc_job(&new_wlan_job);
                }
                return SRV_DTCNT_RESULT_PROCESSING;   
            default:
                return SRV_DTCNT_RESULT_FAILED;
        }
}
void srv_dtcnt_wlan_stop_wifi_tethering_callback_func(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{
		MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_INIT_STOP_TETHERING, result);
    if(result == MMI_TRUE)
    {
        srv_dtcnt_wlan_init_stop_tethering(g_init_callback.callback, g_init_callback.user_data);
    }
    else
    {
        if(g_init_callback.callback != NULL)
        {
    		g_init_callback.callback(g_init_callback.user_data, SRV_DTCNT_WLAN_REQ_RES_FAILED);
        }
				srv_dtcnt_wlan_post_init_res_event(SRV_DTCNT_WLAN_REQ_RES_FAILED);
    }
}
#endif

MMI_BOOL srv_dtcnt_wlan_check_chip_status(void)
{
    if (!wndrv_chip_isOK())
    {
        srv_dtcnt_wifi_chip_invalid_evt_struct evt;
    
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WIFI_CHIP_INVALID);    
        MMI_FRM_CB_EMIT_EVENT(&evt);
        return MMI_FALSE;
    }

    return MMI_TRUE;

}

MMI_BOOL srv_dtcnt_wlan_need_init_check(void)
{
    #ifdef __MMI_TETHERING_WIFI__
    if (g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight == MMI_TRUE && 
        srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS))
    #else
    if (g_srv_dtcnt_wlan_setting_ctx.start_on_switch_flight == MMI_TRUE)
    #endif /* __MMI_TETHERING_WIFI__ */
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
MMI_BOOL srv_dtcnt_wlan_need_sleep()
{
    MMI_BOOL ret;

    ret = srv_cbm_is_wlan_used_by_app();
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_NEED_SLEEP_CHECK, 
        srv_dtcnt_wlan_state(),
        g_srv_dtcnt_wlan_prefer_ctx.sleep_mode,
        srv_charbat_is_charger_connect(), ret);

    if(ret == MMI_TRUE)
    {
        return MMI_FALSE;
    }

    if(srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_NULL 
        || srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DEINIT_WAIT )
    {
        return MMI_FALSE;
    }
    
    if(srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DEINIT) != NULL)
    {
        return MMI_FALSE;
    }
    
    if(g_srv_dtcnt_wlan_prefer_ctx.sleep_mode == SRV_DTCNT_WLAN_SLEEP_MODE_CHARGEIN_NEVER_SLEEP
        && srv_charbat_is_charger_connect() == MMI_FALSE)
    {
        return MMI_TRUE;
    }

    if(g_srv_dtcnt_wlan_prefer_ctx.sleep_mode == SRV_DTCNT_WLAN_SLEEP_MODE_LCD_OFF_SLEEP)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

MMI_BOOL srv_dtcnt_wlan_need_awake()
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_NEED_AWAKE_CHECK,
        g_srv_dtcnt_wlan_prefer_ctx.need_awake);

    if(g_srv_dtcnt_wlan_prefer_ctx.need_awake == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


void srv_dtcnt_wlan_post_sleep_evt()
{
    srv_dtcnt_wlan_sleep_evt_struct evt;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_POST_SLEEP_EVT);
    
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_SLEEP);    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


MMI_RET srv_dtcnt_wlan_lcd_sleep_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size = 0;
    S16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_LCD_SLEEP_HDLR, evt->evt_id);
    switch (evt->evt_id)
    {
        case EVT_ID_GPIO_LCD_SLEEP_IN:
            if(srv_dtcnt_wlan_need_sleep() == MMI_TRUE)
            {
                srv_dtcnt_wlan_post_sleep_evt();
                g_srv_dtcnt_wlan_prefer_ctx.need_awake = MMI_TRUE;
						    size = WriteRecord(
						                NVRAM_EF_CMCC_WIFI_SETTING_LID, 
						                1, 
						                (void*)&g_srv_dtcnt_wlan_prefer_ctx, 
						                NVRAM_MAX_CMCC_WIFI_SETTING_SIZE, 
						                (S16 *)&error);
						
						    if(size < NVRAM_MAX_CMCC_WIFI_SETTING_SIZE)
						    {
						        MMI_ASSERT(0);
						    }                
            }
            break;
            
        case EVT_ID_GPIO_LCD_SLEEP_OUT:
            if(srv_dtcnt_wlan_need_awake() == MMI_TRUE)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_AWAKE_WIFI);
                
                if(srv_dtcnt_wlan_check_chip_status() == MMI_TRUE)
                {
                    if(srv_dtcnt_wlan_state() != SRV_DTCNT_WLAN_STATE_NULL 
                        && srv_dtcnt_wlan_state() != SRV_DTCNT_WLAN_STATE_DEINIT_WAIT )
                    {
                        g_srv_dtcnt_wlan_prefer_ctx.need_awake = MMI_FALSE;
                    }                	
                    srv_dtcnt_wlan_init(NULL, NULL);
                }
                else
                {
                    g_srv_dtcnt_wlan_prefer_ctx.need_awake = MMI_FALSE;
								    size = WriteRecord(
								                NVRAM_EF_CMCC_WIFI_SETTING_LID, 
								                1, 
								                (void*)&g_srv_dtcnt_wlan_prefer_ctx, 
								                NVRAM_MAX_CMCC_WIFI_SETTING_SIZE, 
								                (S16 *)&error);
								
								    if(size < NVRAM_MAX_CMCC_WIFI_SETTING_SIZE)
								    {
								        MMI_ASSERT(0);
								    }               
                }
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

MMI_RET srv_dtcnt_wlan_charbat_notify_evt_hdlr(mmi_event_struct *param)
{
    S32 size = 0;
    S16 error = 0;
    srv_charbat_evt_notify_struct *evt = (srv_charbat_evt_notify_struct *)param;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CHARBAT_NOTIFY_HDLR);
    switch( evt->evt_id )
    {
        case EVT_ID_SRV_CHARBAT_NOTIFY:
            if(evt->status == PMIC_CHARGER_OUT || evt->status == PMIC_USB_CHARGER_OUT)
            {
                if(srv_backlight_is_lcd_sleep() == MMI_TRUE 
                    && srv_dtcnt_wlan_need_sleep() == MMI_TRUE )
                {
                    srv_dtcnt_wlan_post_sleep_evt();
                    g_srv_dtcnt_wlan_prefer_ctx.need_awake = MMI_TRUE;
								    size = WriteRecord(
								                NVRAM_EF_CMCC_WIFI_SETTING_LID, 
								                1, 
								                (void*)&g_srv_dtcnt_wlan_prefer_ctx, 
								                NVRAM_MAX_CMCC_WIFI_SETTING_SIZE, 
								                (S16 *)&error);
								
								    if(size < NVRAM_MAX_CMCC_WIFI_SETTING_SIZE)
								    {
								        MMI_ASSERT(0);
								    }                    
                }
            }
            break;
            
        default:
            break;
            
    }
    return MMI_RET_OK;
}


MMI_RET srv_dtcnt_wlan_cbm_notification_evt_hdlr(mmi_event_struct *param)
{
    S32 size = 0;
    S16 error = 0;
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_CBM_NOTIFICATION_EVT_HDL);
    
    if(srv_backlight_is_lcd_sleep() == MMI_TRUE 
      && srv_dtcnt_wlan_need_sleep() == MMI_TRUE)
    {
        srv_dtcnt_wlan_post_sleep_evt();
        g_srv_dtcnt_wlan_prefer_ctx.need_awake = MMI_TRUE;
		    size = WriteRecord(
		                NVRAM_EF_CMCC_WIFI_SETTING_LID, 
		                1, 
		                (void*)&g_srv_dtcnt_wlan_prefer_ctx, 
		                NVRAM_MAX_CMCC_WIFI_SETTING_SIZE, 
		                (S16 *)&error);
		
		    if(size < NVRAM_MAX_CMCC_WIFI_SETTING_SIZE)
		    {
		        MMI_ASSERT(0);
		    }
    }

    return MMI_RET_OK;

}



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
/* under construction !*/
#endif

#endif /* __MMI_WLAN_FEATURES__ */ 
#endif /* __TCPIP__ */
