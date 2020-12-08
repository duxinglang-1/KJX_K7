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
 * DtcntSrvProv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file provides the data account provisioning content handling services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TCPIP__
#include "MMI_features.h"
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
#include "conversions.h"
#include "app_str.h"
#include <ctype.h> 
//#if defined (SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__)
#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
#include "cbfunc.h"
#ifndef OMADM
#include "bftype.h"
#else
#include "toolset_types.h"
#endif
#endif

#include "DtcntSrvProv.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "DtcntSrvIntStruct.h"
#include "DtcntSrvIprot.h"
#include "DtcntSrvGprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "kal_public_api.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "DtcntSrvDb.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "DtcntSrvIntEnum.h"
#include "DtcntSrvIntDef.h"
#include "stdio.h"
#include "stdlib.h"
#include "custom_data_account.h"
#include "gui_data_types.h"
#include "kal_release.h"
#include "CcaSrvGprot.h"
#include "app_url.h"

#ifndef __SRV_DTCNT_OTA_PROF_PORT_PRIORITY__
#define __SRV_DTCNT_OTA_PROF_PORT_PRIORITY__
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#define SRV_DTCNT_UCS2_UTF8     (0)
#define SRV_DTCNT_UTF8_UCS2     (1)
#define DTCNT_OTAP_NS_BOOTSTRAP     CCA_NS_OMA_BOOTSTRAP
#define DTCNT_OTA_NAPDEF            CCA_NS_OMA_NAPDEF
#define DTCNT_OTA_NAPAUTHINFO       CCA_NS_OMA_NAPAUTHINFO
#define DTCNT_OTA_PROXY             CCA_NS_OMA_PROXY
#define DTCNT_OTA_PORT              CCA_NS_OMA_PORT
#define DTCNT_OTA_PROXY_AUTHINFO    CCA_NS_OMA_APPAUTH

/***************************************************************************** 
* Local Variable
*****************************************************************************/
srv_dtcnt_ota_ctx_struct g_srv_dtcnt_ota_ctx = {0};

#ifdef SYNCML_DM_SUPPORT
static srv_dtcnt_dm_ctx_struct g_srv_dtcnt_dm_cntx;
#endif /* SYNCML_DM_SUPPORT */


#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
static srv_dtcnt_ota_sim_acc_ctx_struct g_srv_dtcnt_ota_sim_acc_ctx;
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

MMI_BOOL g_srv_dtcnt_ota_ongoing = MMI_FALSE;

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern srv_dtcnt_store_info_context g_srv_dtcnt_store_ctx;
extern srv_dtcnt_context g_srv_dtcnt_context;
extern MMI_BOOL g_srv_dtcnt_store_sync_done;


/***************************************************************************** 
* Local Function
*****************************************************************************/
static void srv_dtcnt_ota_charset_convert(CHAR *scr, CHAR *des, U8 len, U8 covertype);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
static MMI_BOOL srv_dtcnt_ota_hash_value_is_empty(U8* hash_value, U16 length);
#endif
static MMI_BOOL srv_dtcnt_ota_hash_value_is_equal(U8* hash_value1, U8* hash_value2, U16 length);
static MMI_BOOL srv_dtcnt_ota_has_target_profile(cca_iterator_struct *param_list);
static srv_dtcnt_ota_item_struct *srv_dtcnt_ota_new_item(void);
static void srv_dtcnt_ota_terminate(void);
//static MMI_BOOL srv_dtcnt_ota_has_any_valid_profile(void);
static MMI_BOOL srv_dtcnt_ota_has_next_valid_profile(srv_dtcnt_ota_item_struct *iter);
static MMI_BOOL srv_dtcnt_ota_util_is_password_valid(CHAR *password);
static void srv_dtcnt_ota_get_next_profile_data(void);
static void srv_dtcnt_ota_remove_redundant(void);
static U8 srv_dtcnt_ota_get_profiles_num(void);
static void srv_dtcnt_ota_proc_profile(void);
static cca_status_enum srv_dtcnt_ota_proc_cca_param_bootstrap(const cca_core_data_struct *param, srv_dtcnt_ota_ctx_struct *cntx);
static cca_status_enum srv_dtcnt_ota_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data);
static cca_status_enum srv_dtcnt_ota_proc_cca_param(const cca_core_data_struct *param, srv_dtcnt_ota_item_struct *prof);
static U8 srv_dtcnt_ota_find_empty_profile(void);
static void srv_dtcnt_ota_install_start(void);
static void srv_dtcnt_ota_cca_rsp_handler(void);
static void srv_dtcnt_ota_post_install_res_evt(srv_dtcnt_prov_install_res_ind_evt_struct *evt, U8 result, srv_dtcnt_prof_acc_type_enum prof_type);
static void srv_dtcnt_ota_install_common_item_new(srv_dtcnt_prof_common_header_struct *item, U32 *out_fields, U8 update);
static MMI_BOOL srv_dtcnt_ota_is_an_valid_account(srv_dtcnt_ota_item_struct *item);
static cca_status_enum srv_dtcnt_ota_proc_cca_proxy_node(cca_iterator_struct *iter_datalist);
static cca_status_enum srv_dtcnt_ota_proc_cca_port_node(U8 dm_update, cca_iterator_struct *iter_datalist);
static cca_status_enum srv_dtcnt_ota_proc_cca_proxy_auth_node(U8 dm_update, cca_iterator_struct *iter_datalist);
static srv_dtcnt_ota_proxy_item_struct *srv_dtcnt_ota_new_proxy_item(void);
//static void srv_dtcnt_ota_convert_cca_proxy_ip_str(U8 *parm_element_p, U8 *proxy_ip_p);
//static S32 srv_dtcnt_prov_check_ip(U8 *ip);
static void srv_dtcnt_ota_proc_cca_proxy_params(cca_core_data_struct *data);
static CHAR *srv_dtcnt_ota_utf8_strltrim(CHAR *string);
static void srv_dtcnt_ota_proc_cca_port_n_srv_params(U8 dm_update, S32 service_parm, CHAR *portnbr_parm);
static srv_dtcnt_ota_item_struct *srv_dtcnt_ota_dup_item(srv_dtcnt_ota_item_struct *item);
static void srv_dtcnt_ota_proxy_info_copy(srv_dtcnt_ota_item_struct *dest, srv_dtcnt_ota_proxy_item_struct *src);
static void srv_dtcnt_ota_update_proxy_to_acc_info(void);
static void srv_dtcnt_ota_install(void);
static void srv_dtcnt_ota_replace(U8 acc_id);
static void srv_dtcnt_ota_skip(void);
static U8 srv_dtcnt_ota_abort_install(void *dummy);
static void srv_dtcnt_ota_install_notify(MMI_BOOL replace_flag);
static void srv_dtcnt_ota_proc_cca_port_helper(U16 *port_out, CHAR *portnbr_parm, S32 default_portnbr_parm);
static void srv_dtcnt_ota_done_notify(void);
srv_dtcnt_sim_type_enum srv_dtcnt_convert_mmi_sim_to_srv_sim(U8 sim_id);


#ifdef __TCPIP_OVER_CSD__
static void srv_dtcnt_ota_install_csd_item(void);
#ifdef SYNCML_DM_SUPPORT
static void srv_dtcnt_ota_gen_csd_prof_for_cca(void);
#endif /* SYNCML_DM_SUPPORT */
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
static void srv_dtcnt_ota_install_sim_csd_item(void);
#endif /* SYNCML_DM_SUPPORT */
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
static void srv_dtcnt_ota_update_csd_item(void);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
#endif /* __TCPIP_OVER_CSD__ */


#ifdef __MMI_GPRS_FEATURES__
static void srv_dtcnt_ota_install_gprs_item(void);
#ifdef SYNCML_DM_SUPPORT
static void srv_dtcnt_ota_gen_gprs_prof_for_cca(void);
#endif /* SYNCML_DM_SUPPORT */
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
static void srv_dtcnt_ota_install_sim_gprs_item(void);
#endif /* SYNCML_DM_SUPPORT */
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
static void srv_dtcnt_ota_update_gprs_item(void);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
#endif /* __MMI_GPRS_FEATURES__ */


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
static MMI_BOOL srv_dtcnt_ota_is_a_matched_account(U8* provurl_hash,
                                                   U8* napid_hash,
                                                   U32 factory_acct_updatable,
                                                   CHAR* acct_name, S32 acct_name_length,
                                                   U8* matched_index);
static MMI_BOOL srv_dtcnt_ota_is_valid_but_discard(U8* provurl_hash,
                                                  U8* napid_hash,
                                                  U32 factory_acct_updatable,
                                                  CHAR* acct_name, S32 acct_name_length);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
static void srv_dtcnt_ota_install_sim_profile(void);
static void srv_dtcnt_ota_install_sim_common_item_new(srv_dtcnt_sim_comm_account_info_st *item);
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

#ifdef SYNCML_DM_SUPPORT
static cca_status_enum srv_dtcnt_ota_dm_acc_check(U16 AppId, U32 ProfId, srv_dtcnt_bearer_enum *bearer);
static void srv_dtcnt_ota_gen_prof_for_cca(srv_dtcnt_bearer_enum bearer);
static void srv_dtcnt_ota_dm_retrieve_rsp(void);
static void srv_dtcnt_ota_get_prof_from_cca(srv_dtcnt_bearer_enum bearer, S32 hconfig);
static void srv_dtcnt_ota_proc_dm_doc(srv_dtcnt_bearer_enum bearer, S32 hconfig);
static void srv_dtcnt_ota_dm_update_rsp(void);
static cca_status_enum srv_dtcnt_ota_proc_dm_nodes(S32 doc_hdl, S32 node_hdl, U16 symbol, cca_iterator_struct *param_list, void *user_data);
static void srv_dtcnt_ota_dm_save_prof(srv_dtcnt_bearer_enum bearer);
static void srv_dtcnt_ota_dm_proc_cca_proxy_params(cca_core_data_struct *data);
static cca_status_enum srv_dtcnt_ota_dm_proc_cca_proxy_node(cca_iterator_struct *iter_datalist);
static cca_oma_values_enum srv_dtcnt_ota_convert_conn_type(srv_dtcnt_prof_px_srv_enum px_service);
#endif /* SYNCML_DM_SUPPORT */

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);


#define EXTERNAL_APIs

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_send_cca_app_configure_rsp
 * DESCRIPTION
 *  This function sends the response message back to CCA for the result of 
 *  configuration. Once application sends this primitive, no further access
 *  to the configuration document should be made.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  status          [IN]            Configuration result
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_send_cca_app_configure_rsp(U16 conf_id, S32 doc_hdl, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_rsp_struct *data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_SEND_CCA_SEND_RSP, status);

    /* Allocate memory. It will assert on error. */
    data = OslAllocDataPtr(mmi_cca_app_configure_rsp_struct);

    data->config_id = conf_id;
    data->hConfig   = doc_hdl;
    data->status    = status;

    /* Send the response message. */
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (oslParaType *)data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_is_cca_target
 * DESCRIPTION
 *  This function examines whether the configuration document has any settings
 *  relevant to data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  data_list       [IN]            Level one node IDs and application IDs
 * RETURNS
 *  Return CCA_STATUS_OK if the document is relevant to VoIP data account; 
 *  otherwise, return CCA_STATUS_NOT_FOUND.
 *****************************************************************************/
cca_status_enum srv_dtcnt_ota_is_cca_target(U16 conf_id, S32 doc_hdl, cca_iterator_struct *data_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_iterator_struct *node_list, *param_list;
    S32 num_nodes, num_params;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check whether PX_SIP nodes are presented in the document. */
    status = mmi_cca_doc_get_nodes(doc_hdl, CCA_NS_OMA_NAPDEF, &node_list, &num_nodes);
    if (status == CCA_STATUS_NOT_FOUND) 
    {
        return CCA_STATUS_NOT_FOUND;
    }

    /* Check whether there are NAPDEF nodes that have a BEARER parameter with
       the value of WLAN. */
    while (mmi_cca_iterator_next(node_list) != NULL)
    {
        /* Extract all parameters and their values in the current node. */
        status = mmi_cca_doc_get_nodedata(node_list, &param_list, &num_params);
        if (status != CCA_STATUS_OK) 
        {
            continue;   /* No need to release param iterator here */
        }
        
        /* Whether there is a CSD/GPRS bearer in the NAPDEF node */
        if (srv_dtcnt_ota_has_target_profile(param_list) == MMI_TRUE)
        {
            /* Release memory and return OK */    
            mmi_cca_iterator_release(node_list);
            mmi_cca_iterator_release(param_list);
            return CCA_STATUS_OK;
        }

        /* Release memory for the current node. */
        mmi_cca_iterator_release(param_list);
    }
    
    /* Release memory and return NOT_FOUND */
    mmi_cca_iterator_release(node_list);
    
    return CCA_STATUS_NOT_FOUND;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to VoIP
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_ota_proc_cca_doc(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the VoIP settings for each profile. All 
     * characteristics are included such that unsupported fields can also be
     * found out.
     */
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP, DTCNT_OTAP_NS_BOOTSTRAP, 0XFFFF, /* Line added for Bootstrap feature */
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, DTCNT_OTA_NAPDEF, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_NAPDEF, CCA_NS_OMA_NAPAUTHINFO, DTCNT_OTA_NAPAUTHINFO, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, DTCNT_OTA_PROXY, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PORT, DTCNT_OTA_PORT, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, CCA_NS_OMA_PXAUTHINFO, DTCNT_OTA_PROXY_AUTHINFO, 0xFFFF
    };

    //cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_PROC_CCA_DOC);

    /* Whether any other OTA provisioning process is still running. */
    if (g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items != NULL)
    {
        MMI_ASSERT(0);  /* Guaranteed by CCA that this should not happen */
    }

    memset(&g_srv_dtcnt_ota_ctx, 0, sizeof(g_srv_dtcnt_ota_ctx));
    g_srv_dtcnt_ota_ctx.conf_id = newConfigDoc->config_id;
    g_srv_dtcnt_ota_ctx.doc_hdl = newConfigDoc->hConfig;
    
    g_srv_dtcnt_ota_ctx.sim_id = (U8)(newConfigDoc->sim_id);
    g_srv_dtcnt_ota_ctx.prov_type = newConfigDoc->prov_type;
    g_srv_dtcnt_ota_ctx.prov_flag = newConfigDoc->prov_flag;
    /* Extract data account settings from CCA configuration document, and store 
       settings in the temporary storage. */
    mmi_cca_doc_process(
            newConfigDoc->hConfig, 
            proc_tbl,
            sizeof(proc_tbl) / sizeof(U16),
            NULL, 
            srv_dtcnt_ota_proc_cca_nodes, 
            &g_srv_dtcnt_ota_ctx);

    /* processing profiles */
    srv_dtcnt_ota_proc_profile();
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_event_callback
 * DESCRIPTION
 *  The callback function after post event is done
 *  Including action response, action notify and confirm indication
 * PARAMETERS
 *  result_evt:        [IN]        result structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_dtcnt_ota_event_callback(mmi_post_result_event_struct *result_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_EVENT_CALLBACK, result_evt->user_data);
    if (result_evt->user_data != NULL)
    {
/*
        if (notify_addr_mem_p)
        {
            OslMfree(notify_addr_mem_p);
            notify_addr_mem_p = NULL;
        }
*/
        OslMfree(result_evt->user_data);
        result_evt->user_data = NULL;
    }

    return MMI_RET_OK;
}

void srv_dtcnt_ota_ind_callback(srv_dtcnt_prov_cnf_enum cnf, U8 replace_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_IND_CALLBACK, cnf, replace_id);
    switch (cnf)
    {
        case SRV_DTCNT_PROV_CNF_INSTALL:
            srv_dtcnt_ota_install();
            srv_dtcnt_ota_cca_rsp_handler();
            break;
        case SRV_DTCNT_PROV_CNF_REPLACE:
            srv_dtcnt_ota_replace(replace_id);
			srv_dtcnt_ota_cca_rsp_handler();
            break;
        case SRV_DTCNT_PROV_CNF_SKIP:
            srv_dtcnt_ota_skip();
            srv_dtcnt_ota_cca_rsp_handler();
            break;
        case SRV_DTCNT_PROV_CNF_ABORT:
            srv_dtcnt_ota_abort_install(NULL);
            break;
        default:
            break;
    }
}

#ifdef SYNCML_DM_SUPPORT
/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_dm_set_check
* DESCRIPTION
*  save gprs profile info rsp
* PARAMETERS
*  info: save result
* RETURNS
*****************************************************************************/
#ifndef OMADM
bf_bool srv_dtcnt_ota_dm_set_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_dtcnt_db_store_status_check();
}
#else
IBOOL srv_dtcnt_ota_dm_set_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_dtcnt_db_store_status_check();
}

#endif
/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_dm_retrieve_ind
* DESCRIPTION
*  DM -> CCA -> APP; Get Profile Indicate
* PARAMETERS
*  Info: Profile info
* RETURNS
* 
*****************************************************************************/
void srv_dtcnt_ota_dm_retrieve_ind(U16 appid, S32 profid)
{
#ifdef SYNCML_DM_SUPPORT
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_dtcnt_bearer_enum bearer;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_DM_RECEIVE_IND, profid);

	g_srv_dtcnt_dm_cntx.app_id = appid;
	g_srv_dtcnt_dm_cntx.prof_id = profid;

	g_srv_dtcnt_dm_cntx.check_status = srv_dtcnt_ota_dm_acc_check(appid, profid, &bearer);

	if(g_srv_dtcnt_dm_cntx.check_status == CCA_STATUS_OK)
	{
		srv_dtcnt_ota_gen_prof_for_cca(bearer);
	}
	else
	{
		srv_dtcnt_ota_dm_retrieve_rsp();
	}
#else
	return;
#endif /* SYNCML_DM_SUPPORT */
}

/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_dm_update_ind
* DESCRIPTION
*  DM -> CCA -> APP; Update Profile Indicate
* PARAMETERS
*  info: Profile info
* RETURNS
*****************************************************************************/
void srv_dtcnt_ota_dm_update_ind(U16 appid, S32 profid, S32 hconfig)
{
#ifdef SYNCML_DM_SUPPORT
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_dtcnt_bearer_enum bearer;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_DM_UPDATE_IND, profid);

	g_srv_dtcnt_dm_cntx.app_id = appid;
	g_srv_dtcnt_dm_cntx.prof_id = profid;
	g_srv_dtcnt_dm_cntx.hconfig = hconfig;
	
	if(g_srv_dtcnt_dm_cntx.hconfig == 0)
	{
		ASSERT(0);
		g_srv_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		srv_dtcnt_ota_dm_update_rsp();
		return;
	}

	g_srv_dtcnt_dm_cntx.check_status = srv_dtcnt_ota_dm_acc_check(g_srv_dtcnt_dm_cntx.app_id, g_srv_dtcnt_dm_cntx.prof_id, &bearer);

	if(g_srv_dtcnt_dm_cntx.check_status == CCA_STATUS_OK)
	{
		srv_dtcnt_ota_get_prof_from_cca(bearer, g_srv_dtcnt_dm_cntx.hconfig);
	}
	else
	{
		srv_dtcnt_ota_dm_update_rsp();
	}
#else
	return;
#endif /* SYNCML_DM_SUPPORT */
}
#endif /* SYNCML_DM_SUPPORT */


#define STATIC_APIs

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_charset_convert
 * DESCRIPTION
 *  This function shows information about a incoming profile. And ask users
 *  whether they want to install the profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_dtcnt_ota_charset_convert(CHAR *scr, CHAR *des, U8 len, U8 covertype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(covertype)
    {
    case SRV_DTCNT_UCS2_UTF8:
        mmi_chset_convert(
            MMI_CHSET_UCS2,
            MMI_CHSET_UTF8,
            (CHAR *)scr,
            (CHAR *)des,
            len);
    	break;

    case SRV_DTCNT_UTF8_UCS2:
        mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (CHAR *)scr,
            (CHAR *)des,
            len);
        break;
    default:
        break;
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_hash_value_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash_value
 *  length
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ 
MMI_BOOL srv_dtcnt_ota_hash_value_is_empty(U8* hash_value, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < length; i++)
    {
        if(hash_value[i])
        {
            return MMI_FALSE;
        } 
    }
    return MMI_TRUE;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_hash_value_is_equal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hash_value
 *  length
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_dtcnt_ota_hash_value_is_equal(U8* hash_value1, U8* hash_value2, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < length; i++)
    {
        if(hash_value1[i] != hash_value2[i])
        {
            return MMI_FALSE;
        } 
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_has_target_profile
 * DESCRIPTION
 *  This function checks whether there is a new WLAN profile in the document.
 *  The input data list contains the parameters and their values of a NAPDEF
 *  node. Care should be take that the input iterator is reset after calling
 *  the function.
 * PARAMETERS
 *  param_list       [IN]           Parameter list for a NAPDEF node
 * RETURNS
 *  If there is a new WLAN profile, return TRUE. Otherwise, return FALSE.
 *****************************************************************************/
MMI_BOOL srv_dtcnt_ota_has_target_profile(cca_iterator_struct *param_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *bearer;
    S32 num_bearers;
    cca_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /* Extract the value of the parameter BEARER. */
    status = mmi_cca_doc_get_nodedata_ints(param_list, CCA_NS_OMA_BEARER, &bearer, &num_bearers);
    mmi_cca_iterator_restart(param_list);

    if (status != CCA_STATUS_OK) 
    {
        return MMI_FALSE;
    }

    /* Whether there is a WLAN bearer. */ 
    while (--num_bearers >= 0)
    {
        if (bearer[num_bearers] == CCA_NS_VAL_GSM_CSD || bearer[num_bearers] == CCA_NS_VAL_GSM_GPRS) 
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_new_item
 * DESCRIPTION
 *  This function allocates and initializes the control block of voip OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
static srv_dtcnt_ota_item_struct *srv_dtcnt_ota_new_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_ota_item_struct *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate the control block. Must be successful. */
    p = (srv_dtcnt_ota_item_struct *)OslMalloc(sizeof(srv_dtcnt_ota_item_struct));


    /* Clear the entire structure. */
    memset(p, 0, sizeof(srv_dtcnt_ota_item_struct));

    p->valid = TRUE;
    
    return p;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_terminate
 * DESCRIPTION
 *  The function frees memory of the control block, and clears the global ptr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_ota_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_ota_item_struct *iter, *temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_srv_dtcnt_ota_ongoing = MMI_FALSE;
    
    /* Nothing to do. Return. */
    if (g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items == NULL) 
    {
        return;
    }

    iter = g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items;
    
    /* Free all profiles. */
    while(iter)
    {
        temp = iter;
        iter = iter->next;
        OslMfree(temp);
        temp = NULL;
    }

    /* Free proxy info. */
    if (g_srv_dtcnt_ota_ctx.curr_proxy_item)
    {
        OslMfree(g_srv_dtcnt_ota_ctx.curr_proxy_item);
    }
    
    /* Free the control block. */
    memset(&g_srv_dtcnt_ota_ctx, 0, sizeof(g_srv_dtcnt_ota_ctx));
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
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_has_next_valid_profile
 * DESCRIPTION
 *  This function checks if there is any valid profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_dtcnt_ota_has_next_valid_profile(srv_dtcnt_ota_item_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    /* Nothing to do. Return. */
    if (iter == NULL)
    {
        return MMI_FALSE;
    }
    
    while(iter)
    {
        if(iter->valid)
        {
            return MMI_TRUE;
        }
        iter = iter->next;
    }
    
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_util_is_password_valid
 * DESCRIPTION
 *  Check if the password is all ASCII
 * PARAMETERS
 *  username        [IN]        String to be check, UCS2 encoded
 * RETURNS
 *  TRUE if username is valid; otherwise, FALSE
 *****************************************************************************/
MMI_BOOL srv_dtcnt_ota_util_is_password_valid(CHAR *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(password == NULL)
    {
        return MMI_FALSE;
    }
    else
    {
        while (!((*password == 0) && (*(password + 1) == 0)))
        {
            if (password[0] < 0x20 || password[0] > 0x7E || password[1] != 0)
            {
                return MMI_FALSE;
            }
            password += 2;
        }
        return MMI_TRUE;
    }   
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_get_next_profile_data
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to VoIP
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_ota_get_next_profile_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_srv_dtcnt_ota_ctx.current_item)
    {
        g_srv_dtcnt_ota_ctx.current_item = g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items;    
    }
    else
    {
        g_srv_dtcnt_ota_ctx.current_item = g_srv_dtcnt_ota_ctx.current_item->next;
    }

    /* Proceed to next valid profile. */
    while(g_srv_dtcnt_ota_ctx.current_item != NULL)
    {
        if(g_srv_dtcnt_ota_ctx.current_item->valid == TRUE)
        {
            break;
        }
        g_srv_dtcnt_ota_ctx.current_item = g_srv_dtcnt_ota_ctx.current_item->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_remove_redundant
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_dtcnt_ota_remove_redundant(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_ota_item_struct *p = NULL;
    srv_dtcnt_ota_item_struct *q = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items)
    {
        return;
    }
    p = g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items;
    while (p && !srv_dtcnt_ota_is_an_valid_account(p))
    {
        p = p->next;
        OslMfree(g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items);
        g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items = p;
    }

    if (!g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items)
    {
        return;
    }

    q = g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items, p = q->next;
    while (p)
    {
        if (!srv_dtcnt_ota_is_an_valid_account(p))
        {
            q->next = p->next;
            OslMfree(p);
        }
        else
        {
            q = p;
        }
        p = q->next;
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_get_profiles_num
 * DESCRIPTION
 *  This function examines whether the configuration document has any settings
 *  relevant to data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 *  data_list       [IN]            Level one node IDs and application IDs
 * RETURNS
 *  Return CCA_STATUS_OK if the document is relevant to VoIP data account; 
 *  otherwise, return CCA_STATUS_NOT_FOUND.
 *****************************************************************************/
static U8 srv_dtcnt_ota_get_profiles_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 prof_num = 0;
    srv_dtcnt_ota_item_struct *iter, *temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Nothing to do. Return. */
    if (g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items == NULL) 
    {
        return 0;
    }

    iter = g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items;
    
    /* get num of profiles. */
    while(iter)
    {
        temp = iter;
        if(temp->valid)
        {
            prof_num++;
        }
        iter = iter->next;
    }

    return prof_num;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_param_bootstrap
 * DESCRIPTION
 *  This function processes the parameter of BOOTSTRAP node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  cntx            [IN/OUT]        The Email OTAP control block
 * RETURNS
 *  status response to cca
 *****************************************************************************/
static cca_status_enum srv_dtcnt_ota_proc_cca_param_bootstrap(const cca_core_data_struct *param, srv_dtcnt_ota_ctx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    U16 i;
    U16 provurl_exist = MMI_FALSE;
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Dispatching according to the parameter symbol 
     */
    switch (param->id)
    {
        case CCA_NS_OMA_NAME:
            /* ignored */
            break;
    #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        case CCA_NS_OMA_PROVURL:
            if(param->values.s[0])
            {
                provurl_exist = MMI_FALSE;
                if(strlen((CHAR*)param->values.s[0]) > 0)
                {
                    for(i = 0; i < SRV_DTCNT_PROVURL_HASH_LEN; i++)
                    {
                        if(cntx->provurl_hash_val[i])
                        {
                            provurl_exist = MMI_TRUE;
                            break;
                        }
                    }
                    if(!provurl_exist)
                    {
                        mmi_cca_generate_hash_value((CHAR*)param->values.s[0],  
                                                    (U8*)cntx->provurl_hash_val,
                                                    SRV_DTCNT_PROVURL_HASH_LEN); 
                    }
                }
            }
            break;
    #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
        default:
            /* All other parameters are skipped. And the status is OK. */
            break;
    }
    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_find_empty_profile
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  profile slot index < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM : empty slot id
 *  profile slot index = SRV_DTCNT_PROF_MAX_ACCOUNT_NUM : no empty slot
 *****************************************************************************/
U8 srv_dtcnt_ota_find_empty_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_dtcnt_sim_type_enum sim_info; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_info = srv_dtcnt_convert_mmi_sim_to_srv_sim(g_srv_dtcnt_ota_ctx.sim_id);
    /* Find an empty profile. */
    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (!g_srv_dtcnt_store_ctx.acc_list[i].in_use && 
            srv_dtcnt_get_account_num(sim_info)<SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM)
        {       
            return i;
        }
    }
    return SRV_DTCNT_PROF_MAX_ACCOUNT_NUM;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_otap_install_start
 * DESCRIPTION
 *  This function sends the processing wlan ota profile information to APP.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_ota_install_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* notify DA APP for installation */
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INSTALL_START);
    if (srv_dtcnt_ota_find_empty_profile() == SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
    {
        srv_dtcnt_ota_install_notify(MMI_TRUE);
    }
    else
    {
        srv_dtcnt_ota_install_notify(MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_is_an_valid_account
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_dtcnt_ota_is_an_valid_account(srv_dtcnt_ota_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(item->name) == 0) 
    {
        /* return MMI_FALSE; */
    }
    if (strlen(item->address)  == 0) 
    {
        return MMI_FALSE;
    }
    if (!(item->bearer == DATA_ACCOUNT_BEARER_CSD || item->bearer == DATA_ACCOUNT_BEARER_GPRS))
    {
        return MMI_FALSE;
    }
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (srv_dtcnt_ota_is_valid_but_discard(
                                    g_srv_dtcnt_ota_ctx.provurl_hash_val,
                                    item->napid_hash_val,
                                    g_srv_dtcnt_ota_ctx.prov_flag & MMI_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE,
                                    item->name, 
                                    mmi_ucs2strlen((CHAR*)item->name)))
    {
        return MMI_FALSE;
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    return MMI_TRUE;
}

void srv_dtcnt_ota_install_notify(MMI_BOOL replace_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prov_ind_evt_struct evt;
    srv_dtcnt_prov_csd_gprs_ind_struct *tmp_ind;
    U8 bearer = g_srv_dtcnt_ota_ctx.current_item->bearer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INSTALL_NOTIFY, replace_flag);
    if(!g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items)
    {
        return;
    }

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_PROV_IND);
    
    /* construct prov wlan ind for DA APP */
    tmp_ind = OslMalloc(sizeof(srv_dtcnt_prov_csd_gprs_ind_struct));
    tmp_ind->AccountName = (U8 *)g_srv_dtcnt_ota_ctx.current_item->name;

#ifdef __TCPIP_OVER_CSD__
    if(bearer == DATA_ACCOUNT_BEARER_CSD)
    {
/*
        S8* tempBufCSD = notify_addr_mem_p = OslMalloc((SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1) * ENCODING_LENGTH);        
        memset(tempBufCSD, 0, (SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1) * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(tempBufCSD, (CHAR *) g_srv_dtcnt_ota_ctx.current_item->address, strlen(g_srv_dtcnt_ota_ctx.current_item->address));
        tmp_ind->Address = (U8 *)tempBufCSD;
*/
        tmp_ind->Address = (U8 *)g_srv_dtcnt_ota_ctx.current_item->address;
        goto send_event;
    }
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
    if(bearer == DATA_ACCOUNT_BEARER_GPRS)
    {
/*
        S8* tempBufAPN = notify_addr_mem_p = OslMalloc((SRV_DTCNT_PROF_MAX_APN_LEN + 1) * ENCODING_LENGTH);
        memset(tempBufAPN, 0, (SRV_DTCNT_PROF_MAX_APN_LEN + 1) * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(tempBufAPN, (CHAR *) g_srv_dtcnt_ota_ctx.current_item->address, strlen(g_srv_dtcnt_ota_ctx.current_item->address));
        tmp_ind->Address = (U8 *)tempBufAPN;
*/
        tmp_ind->Address = (U8 *)g_srv_dtcnt_ota_ctx.current_item->address;
    }
#endif /* __MMI_GPRS_FEATURES__ */
#ifdef __TCPIP_OVER_CSD__
send_event:
#endif
    evt.prof_data = tmp_ind;    
    evt.sim_info = srv_dtcnt_convert_mmi_sim_to_srv_sim(g_srv_dtcnt_ota_ctx.sim_id);
    
    /* construct event struct */
    if (g_srv_dtcnt_ota_ctx.current_item->bearer == DATA_ACCOUNT_BEARER_CSD)
        evt.prov_ind = SRV_DTCNT_PROV_IND_CSD;
    else
        evt.prov_ind = SRV_DTCNT_PROV_IND_GPRS;
    
    evt.cur_prof_idx = (g_srv_dtcnt_ota_ctx.index_profile+1);
    evt.num_profs = g_srv_dtcnt_ota_ctx.num_profiles;


    evt.prov_type = (replace_flag)? SRV_DTCNT_PROV_TYPE_REPLACE : SRV_DTCNT_PROV_TYPE_ADD;

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    {
        if (srv_dtcnt_ota_is_a_matched_account(g_srv_dtcnt_ota_ctx.provurl_hash_val, 
                                              g_srv_dtcnt_ota_ctx.current_item->napid_hash_val, 
                                              g_srv_dtcnt_ota_ctx.prov_flag & MMI_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE, 
                                              g_srv_dtcnt_ota_ctx.current_item->name, 
                                              mmi_ucs2strlen(g_srv_dtcnt_ota_ctx.current_item->name),
                                              &g_srv_dtcnt_ota_ctx.matched_index))
        {
            if(g_srv_dtcnt_store_ctx.acc_list[g_srv_dtcnt_ota_ctx.matched_index-1].sim_info == srv_dtcnt_convert_mmi_sim_to_srv_sim(g_srv_dtcnt_ota_ctx.sim_id))
            {
            evt.prov_type = SRV_DTCNT_PROV_TYPE_UPDATE;
        }
            else
            {
                g_srv_dtcnt_ota_ctx.matched_index = 0;
            } 
        }
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    evt.cnf_callback = srv_dtcnt_ota_ind_callback;
    MMI_FRM_CB_EMIT_POST_EVENT_EX((mmi_event_struct *)&evt, srv_dtcnt_ota_event_callback, (void *)evt.prof_data);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_cca_rsp_handler
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to VoIP
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_dtcnt_ota_cca_rsp_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_RSP_TO_CCA);

    if (g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items == NULL) 
    {
        return;
    }

/* The profile updated at least 1 */
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if(g_srv_dtcnt_ota_ctx.num_updated)
    {
        g_srv_dtcnt_ota_ctx.cur_status = 1;
    }
#endif
/* The profile installed at least 1 */
    if(g_srv_dtcnt_ota_ctx.num_installed && g_srv_dtcnt_ota_ctx.cur_status != 1)
    {
        g_srv_dtcnt_ota_ctx.cur_status = 2;
    }


    /* If there is no more profile to be installed. */
    if ((!g_srv_dtcnt_ota_ctx.current_item->next) || 
        (!srv_dtcnt_ota_has_next_valid_profile(g_srv_dtcnt_ota_ctx.current_item->next))) 
    {
        /* Send a response back to CCA and free memory. */
        if(g_srv_dtcnt_ota_ctx.num_installed)
        {
        #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            if (g_srv_dtcnt_ota_ctx.num_updated)
            {
                srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_SETTING_UPDATED);
            }
            else
        #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
            {
                srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_OK);
            }

            /* notify DA APP */
            srv_dtcnt_ota_done_notify();
        }
        else
        {
            srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_SETTING_SKIPPED);
        }
        srv_dtcnt_ota_terminate();

        return;
    }
    else
    {
        g_srv_dtcnt_ota_ctx.index_profile ++;
        srv_dtcnt_ota_get_next_profile_data();
        srv_dtcnt_ota_install_start();
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_post_install_res_evt
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_dtcnt_ota_post_install_res_evt(srv_dtcnt_prov_install_res_ind_evt_struct *evt, U8 result, srv_dtcnt_prof_acc_type_enum prof_type)
{
    MMI_FRM_INIT_EVENT(evt, EVT_ID_SRV_DTCNT_PROV_INSTALL_RES_IND);
    mmi_ucs2ncpy((char *)evt->name, (char *) g_srv_dtcnt_ota_ctx.current_item->name, SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1);
    evt->prof_idx = (g_srv_dtcnt_ota_ctx.index_profile+1);
    evt->num_profs = g_srv_dtcnt_ota_ctx.num_profiles;
    evt->acct_id = g_srv_dtcnt_ota_ctx.installed_acct_id;
    evt->sim_info = srv_dtcnt_convert_mmi_sim_to_srv_sim(g_srv_dtcnt_ota_ctx.sim_id);
    if (g_srv_dtcnt_ota_ctx.current_item->bearer == DATA_ACCOUNT_BEARER_CSD)
    {
        evt->prov_ind = SRV_DTCNT_PROV_IND_CSD;
    }
    else
    {
        evt->prov_ind = SRV_DTCNT_PROV_IND_GPRS;
    }
    evt->prof_type = prof_type;
    evt->install_result = result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_install
 * DESCRIPTION
 *  This function handles the install command from APP.
 * PARAMETERS
 *  void
 * RETURNS
 *  ret < 0 : install failed
 *  ret > 0 : the installed profile id
 *****************************************************************************/
void srv_dtcnt_ota_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INSTALL);    
    ASSERT(g_srv_dtcnt_ota_ctx.current_item);
    
#ifdef __TCPIP_OVER_CSD__    
    if(g_srv_dtcnt_ota_ctx.current_item->bearer == DATA_ACCOUNT_BEARER_CSD)
    {
        #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        if (g_srv_dtcnt_ota_ctx.matched_index)
        {
            srv_dtcnt_ota_update_csd_item();
        }
        else
        {        
            /* Find an empty profile. */
			i = srv_dtcnt_ota_find_empty_profile();
			MMI_ASSERT(i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM);
			srv_dtcnt_ota_install_csd_item();
        }
        #else /* !__MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

        /* Find an empty profile. */
		i = srv_dtcnt_ota_find_empty_profile();
		MMI_ASSERT(i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM);
        srv_dtcnt_ota_install_csd_item();
        #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

		return;
    }
#endif /* __TCPIP_OVER_CSD__ */

#ifdef __MMI_GPRS_FEATURES__
    if(g_srv_dtcnt_ota_ctx.current_item->bearer == DATA_ACCOUNT_BEARER_GPRS)
    {
        #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        if (g_srv_dtcnt_ota_ctx.matched_index)
        {
            srv_dtcnt_ota_update_gprs_item();
        }
        else
        {
            /* Find an empty profile. */
			i = srv_dtcnt_ota_find_empty_profile();
			MMI_ASSERT(i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM);
        	srv_dtcnt_ota_install_gprs_item();
        }
        #else /* !__MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

        /* Find an empty profile. */
		i = srv_dtcnt_ota_find_empty_profile();
		MMI_ASSERT(i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM);        
		srv_dtcnt_ota_install_gprs_item();
        #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

		return;
    }
#endif /* __MMI_GPRS_FEATURES__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_replace
 * DESCRIPTION
 *  This function handles the install command from APP.
 * PARAMETERS
 *  replace_idx :   [IN]    replace idx of profie name list
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_ota_replace(U8 acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_REPLACE, acc_id);    
    
    ASSERT(g_srv_dtcnt_ota_ctx.current_item);
    
    for (i=0; i<SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].acc_id == acc_id)
        {
            if (g_srv_dtcnt_store_ctx.acc_list[i].readonly)
            {
                srv_dtcnt_prov_install_res_ind_evt_struct evt;
                srv_dtcnt_ota_post_install_res_evt(&evt, 0, SRV_DTCNT_PROF_TYPE_OTA_CONF);
                MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
                return;
            }
            
            g_srv_dtcnt_context.acct_update_evt_sim_id_old = g_srv_dtcnt_store_ctx.acc_list[i].sim_info;
            g_srv_dtcnt_store_ctx.acc_list[i].in_use = 0;
            g_srv_dtcnt_ota_ctx.replace_acct_index = i+1;
            if (g_srv_dtcnt_store_sync_done)
            {
                srv_dtcnt_db_store_send_abm_acc_info(SRV_DTCNT_DB_TRANS_DELETE, i, 0);               
            }            
            g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num--;
            break;
        }
    }
    ASSERT(i != SRV_DTCNT_PROF_MAX_ACCOUNT_NUM);

#ifdef __TCPIP_OVER_CSD__    
    if(g_srv_dtcnt_ota_ctx.current_item->bearer == DATA_ACCOUNT_BEARER_CSD)
    {
        srv_dtcnt_ota_install_csd_item();
		g_srv_dtcnt_store_ctx.acc_list[i].in_use = 1;
        g_srv_dtcnt_ota_ctx.replace_acct_index = 0;
		return;
    }
#endif /* __TCPIP_OVER_CSD__ */

#ifdef __MMI_GPRS_FEATURES__
    if(g_srv_dtcnt_ota_ctx.current_item->bearer == DATA_ACCOUNT_BEARER_GPRS)
    {
        srv_dtcnt_ota_install_gprs_item();
		g_srv_dtcnt_store_ctx.acc_list[i].in_use = 1;
        g_srv_dtcnt_ota_ctx.replace_acct_index = 0;
		return;
    }
#endif /* __MMI_GPRS_FEATURES__ */
}

static void srv_dtcnt_ota_skip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_SKIP);

	#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
	g_srv_dtcnt_ota_ctx.matched_index = 0;
	#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    if(g_srv_dtcnt_ota_ctx.cur_status != 1 && g_srv_dtcnt_ota_ctx.cur_status != 2)
    {
        g_srv_dtcnt_ota_ctx.cur_status = 3;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_abort_install
 * DESCRIPTION
 *  This function should be called to exit the data account ota application. It is 
 *  registered as a delete screen callback such that it can be called when END
 *  key is pressed to return to idle screen.
 * PARAMETERS
 *  dummy           [IN]            Dummy parameter. Always be zero.
 * RETURNS
 *  When END key is pressed to return to idle screen, return TRUE to stop 
 *  delete other nodes in history stack. Here, always return FALSE.
 *****************************************************************************/
static U8 srv_dtcnt_ota_abort_install(void *dummy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_ABORT);
    /* Terminated. Send a response back to CCA and free memory. */
    switch (g_srv_dtcnt_ota_ctx.cur_status)
    {
        case 0:
        case 5:
            srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_ENDKEY_PRESSED);
            break;
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        case 1:
            srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_ENDKEY_SETTING_UPDATED);
            break;
#endif
        case 2:
           srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_ENDKEY_SETTING_INSTALLED);
           break;
        case 3:
           srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_ENDKEY_SETTING_SKIPPED);
           break;
        case 4:
          srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_ENDKEY_INVALID_SETTING);
          break;
    }
    
    srv_dtcnt_ota_terminate();    
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to VoIP
 *  data account.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_dtcnt_ota_proc_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*
     * Mapping table used to extract the VoIP settings for each profile. All 
     * characteristics are included such that unsupported fields can also be
     * found out.
     */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    srv_dtcnt_ota_remove_redundant();
    /* If there is no correct VoIP profile, send a INVALID_SETTING response message back to CCA. */
    if (srv_dtcnt_ota_get_profiles_num() == 0) 
    {        
        /* Now, terminate the OTAP OTA provisioning application. */
        g_srv_dtcnt_ota_ctx.cur_status = 4;
        srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_INVALID_SETTING);
        srv_dtcnt_ota_terminate();
        return;
    }
#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock())
    {
        srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_ABORT);
        srv_dtcnt_ota_terminate();
        return;
    }
#endif

    switch(g_srv_dtcnt_context.store_status)
    {
        case SRV_DTCNT_STORE_STATUS_NONE:
        case SRV_DTCNT_STORE_STATUS_CLOSED:
        case SRV_DTCNT_STORE_STATUS_CORRUPT:
        case SRV_DTCNT_STORE_STATUS_FS_ERROR:
        /* Now, terminate the OTAP OTA provisioning application. */
        g_srv_dtcnt_ota_ctx.cur_status = 4;
        srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_INVALID_SETTING);
        srv_dtcnt_ota_terminate();
        return;
    }

    /* has prov accounts to install */
    g_srv_dtcnt_ota_ongoing = MMI_TRUE;

    if (g_srv_dtcnt_ota_ctx.curr_proxy_item)
    {
        srv_dtcnt_ota_update_proxy_to_acc_info();
        OslMfree(g_srv_dtcnt_ota_ctx.curr_proxy_item);
        g_srv_dtcnt_ota_ctx.curr_proxy_item = NULL;
    }

    g_srv_dtcnt_ota_ctx.num_profiles = srv_dtcnt_ota_get_profiles_num();

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_RROC_PROFILE, g_srv_dtcnt_ota_ctx.num_profiles);
    /* Ready to install profiles. */
    srv_dtcnt_ota_get_next_profile_data();

    if (g_srv_dtcnt_ota_ctx.prov_type == MMI_CCA_PROV_TYPE_OTA_PROV)
    {
        /* Start the OTA provisioning application to interact with user. */
        srv_dtcnt_ota_install_start();
    }
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
    else if (g_srv_dtcnt_ota_ctx.prov_type == MMI_CCA_PROV_TYPE_SIM_PROV)
    {
    #ifdef __TCPIP_OVER_CSD__
        g_srv_dtcnt_ota_sim_acc_ctx.csd_num = 0;
    #endif /* __TCPIP_OVER_CSD__ */
    #ifdef __MMI_GPRS_FEATURES__
        g_srv_dtcnt_ota_sim_acc_ctx.gprs_num = 0;
    #endif /* __MMI_GPRS_FEATURES__ */
    
        srv_dtcnt_ota_install_sim_profile();
    }
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_new_proxy_item
 * DESCRIPTION
 *  This function allocates and initializes the control block of voip OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
static srv_dtcnt_ota_proxy_item_struct *srv_dtcnt_ota_new_proxy_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_ota_proxy_item_struct *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate the control block. Must be successful. */
    p = (srv_dtcnt_ota_proxy_item_struct *)OslMalloc(sizeof(srv_dtcnt_ota_proxy_item_struct));


    /* Clear the entire structure. */
    memset(p, 0, sizeof(srv_dtcnt_ota_proxy_item_struct));
    p->proxy_flag = p->port_flag = MMI_FALSE;    
    return p;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_param
 * DESCRIPTION
 *  This function processes the parameter of PX-SIP node.
 * PARAMETERS
 *  param           [IN]            A parameter with its values
 *  cntx            [IN/OUT]        The VoIP OTAP control block
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_ota_proc_cca_param(const cca_core_data_struct *param, srv_dtcnt_ota_item_struct *prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 password[64];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (param->id)
    {
    case CCA_NS_NODEID:

        /* Whether the value is presented and the type is legal. */
        if (param->size <= 0 || param->type != CCA_DT_STR) 
        {
            return CCA_STATUS_FAIL;
        }
        
        /* Whether the string's raw length is legal. */
        if (strlen(param->values.s[0]) > SRV_DTCNT_MAX_NODE_ID_LEN) 
        {
            return CCA_STATUS_FAIL;
        }
        
        /* Extract the node id. Store it as UTF-8 string. */
        /*strcpy((S8 *)prof->node_id, param->values.s[0]);*/
        strcpy((CHAR *)prof->node_id, param->values.s[0]);

        break;
        
    case CCA_NS_OMA_NAPID:
        if(param->values.s[0])
        {
            if(strlen((CHAR *)param->values.s[0]) > 0)
            {
                mmi_cca_generate_hash_value((CHAR*)param->values.s[0], 
                                            (U8*)prof->napid_hash_val, 
                                            SRV_DTCNT_NAPID_HASH_LEN);
            }
        }
        break;

    case CCA_NS_OMA_NAME: /* PRS_STR_ISP_NAME */
        if(param->values.s[0])
        {
            /* convert utf8 to ucs2 */
            srv_dtcnt_ota_charset_convert((CHAR *)param->values.s[0], 
                (CHAR *)prof->name,
                ((SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH),
                SRV_DTCNT_UTF8_UCS2); 
            prof->name[SRV_DTCNT_PROF_MAX_ACC_NAME_LEN * ENCODING_LENGTH] = 0;
            prof->name[SRV_DTCNT_PROF_MAX_ACC_NAME_LEN * ENCODING_LENGTH - 1] = 0;            
        }               
        break;
        
    case CCA_NS_OMA_AUTHTYPE: /* PRS_STR_PPP_AUTHTYPE */
        if(param->values.i[0] == CCA_NS_VAL_PAP)
        {
            prof->AuthType = 0;
        }
        else if(param->values.i[0] == CCA_NS_VAL_CHAP)
        {
            prof->AuthType = 1;
        }
        else if(param->values.i[0] == CCA_NS_VAL_MD5)
        {
            prof->AuthType = 1;
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_ERROR_AUTHTYPE);
            prof->AuthType = 0;
        }
        break;
    case CCA_NS_OMA_AUTHNAME: /* PRS_STR_PPP_AUTHNAME */
        if(param->values.s[0])
        {
            kal_mem_set(prof->UserName, 0, SRV_DTCNT_PROF_MAX_USER_LEN+1);
            strncpy((CHAR *)prof->UserName, (const CHAR *)param->values.s[0], SRV_DTCNT_PROF_MAX_USER_LEN);
        }
        break;
    case CCA_NS_OMA_AUTHSECRET: /* PRS_STR_PPP_AUTHPW */
        if(param->values.s[0])
        {
            kal_mem_set(prof->Passwd, 0, SRV_DTCNT_PROF_MAX_PW_LEN+1);
            strncpy((CHAR *)prof->Passwd, (const CHAR *)param->values.s[0], SRV_DTCNT_PROF_MAX_PW_LEN);
            mmi_asc_to_ucs2((CHAR*)password, (CHAR *)prof->Passwd);
			if (!srv_dtcnt_ota_util_is_password_valid((CHAR *)password))
			{
                prof->Passwd[0] = 0;
				prof->Passwd[1] = 0;
			}
        }
        break;
    case CCA_NS_OMA_CALLTYPE: /* PRS_STR_CSD_CALLTYPE */
        switch(param->values.i[0])
        {
        case CCA_NS_VAL_ANALOG_MODEM:
            prof->DialType = SRV_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE;
            break;
        case CCA_NS_VAL_V120:
        case CCA_NS_VAL_V110:
        case CCA_NS_VAL_X31:
        case CCA_NS_VAL_BIT_TRANSPARENT:
        case CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE:
            prof->DialType = SRV_DTCNT_PROF_CSD_DIAL_TYPE_ISDN;
            break;
        default:
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_ERROR_CALLTYPE);
            //return CCA_STATUS_FAIL;
            break;
        }
        break;
    case CCA_NS_OMA_LINKSPEED: /* PRS_STR_CSD_CALLSPEED */
        if(param->values.i[0] == DATA_RATE_2400)
        {
            prof->DataRate = SRV_DTCNT_PROF_CSD_RATE_TWO_FOUR;
        }
        else if(param->values.i[0] == DATA_RATE_4800)
        {
            prof->DataRate = SRV_DTCNT_PROF_CSD_RATE_FOUR_EIGHT;
        }
        else if(param->values.i[0] == DATA_RATE_9600)
        {
            prof->DataRate = SRV_DTCNT_PROF_CSD_RATE_NINE_SIX;
        }
        else if(param->values.i[0] == DATA_RATE_14400)
        {
            prof->DataRate = SRV_DTCNT_PROF_CSD_RATE_FOURTEEN_FOUR;
        }
        else 
        {
            prof->DataRate = SRV_DTCNT_PROF_CSD_RATE_AUTO;
        }
        break;
    case CCA_NS_OMA_NAP_ADDRESS: /* PRS_STR_CSD_DAILSTRING */
        if(param->values.s[0])
        {
        #if (defined __CSD_NT__) || (defined __CSD_T__) || (defined __MMI_GPRS_FEATURES__)
        #if (defined __CSD_NT__) || (defined __CSD_T__)
            U8 i;
            
            if(prof->bearer == DATA_ACCOUNT_BEARER_CSD)
            {
                strncpy((CHAR *)prof->address, (CHAR *)param->values.s[0], SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN);/* +1 is reserved for "+" */
                if (prof->address[0] == '+')
                {
                    prof->address[SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1] = 0;
                }
                else
                {
                    prof->address[SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN] = 0;
                }
                i = 0;
                while(prof->address[i])
                {
                    if(prof->address[i] != 0x2b && (prof->address[i] < 0x30 || prof->address[i] > 0x39))
                    {
                        return CCA_STATUS_FAIL;
                    }
                    i++;
                }
                break;
            }
        #endif
        #ifdef __MMI_GPRS_FEATURES__
            if(prof->bearer == DATA_ACCOUNT_BEARER_GPRS)
            {
                kal_mem_set(prof->address, 0, SRV_DTCNT_PROF_MAX_APN_LEN+1);
                strncpy((CHAR *)prof->address, (CHAR *)param->values.s[0], SRV_DTCNT_PROF_MAX_APN_LEN);
                break;
            }
        #endif /* __MMI_GPRS_FEATURES__ */
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_ERROR_ADDR);
                return CCA_STATUS_FAIL;
            }
        #endif
        }
        break;
    case CCA_NS_OMA_DNS_ADDR:
        if(param->values.s[0])
        {
            U32 dns[4];
            sscanf((char *)param->values.s[0], "%u.%u.%u.%u",&dns[0],&dns[1],&dns[2],&dns[3]);
            if(dns[0] > 255 || dns[1] > 255 || dns[2] > 255 ||dns[3] > 255)
            {
                prof->DnsAddress[0] = 0;
                prof->DnsAddress[1] = 0;
                prof->DnsAddress[2] = 0;
                prof->DnsAddress[3] = 0;
            }
            else
            {
                prof->DnsAddress[0] = (U8)dns[0];
                prof->DnsAddress[1] = (U8)dns[1];
                prof->DnsAddress[2] = (U8)dns[2];
                prof->DnsAddress[3] = (U8)dns[3];
            }
        }
        break;
    case CCA_NS_OMA_BEARER: /* PRS_STR_CSD_DAILSTRING */
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_BEARER_TYPE,param->values.i[0]);
        if(param->values.i[0] == CCA_NS_VAL_GSM_CSD)
        {
            prof->bearer = DATA_ACCOUNT_BEARER_CSD;
        }
        else if(param->values.i[0] == CCA_NS_VAL_GSM_GPRS)
        {
            prof->bearer = DATA_ACCOUNT_BEARER_GPRS;
        }
        else
        {
            return CCA_STATUS_FAIL;
        }
        break;
    default:
        break;
    }

    return CCA_STATUS_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_prov_check_ip
 * DESCRIPTION
 *  Function to validate the IP
 * PARAMETERS
 *  ip      [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
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
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_convert_cca_proxy_ip_str
 * DESCRIPTION
 *  This converts an IP string into an array
 * PARAMETERS
 *  parm_element_p      [IN]        
 *  proxy_ip_p          [IN]        
 * RETURNS
 *  U8               [OUT]
 *****************************************************************************/
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
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_utf8_strltrim
 * DESCRIPTION
 *  Trim white spaces from utf8 string.
 * PARAMETERS
 *  string      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
CHAR *srv_dtcnt_ota_utf8_strltrim(CHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(string);

    while ((0 != string[i]) && (' ' == string[i]))
    {
        i++;
    }
    strcpy((CHAR*) string, (CHAR*) (string + i));

    return string;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_proxy_node
 * DESCRIPTION
 *  Handles proxy tag from CCA doc.
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
static cca_status_enum srv_dtcnt_ota_proc_cca_proxy_node(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;
    S32 px_addrtype = -1;
    cca_status_enum result = CCA_STATUS_OK;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_dtcnt_ota_ctx.curr_proxy_item->port_flag = MMI_FALSE;
    g_srv_dtcnt_ota_ctx.curr_proxy_item->proxy_flag = MMI_FALSE;

    status = mmi_cca_doc_get_nodedata_int_first(iter_datalist, CCA_NS_OMA_PXADDRTYPE, &px_addrtype);

    if (status == CCA_STATUS_NOT_FOUND)
    {
        px_addrtype = CCA_NS_VAL_IPV4;
    }
    else if (px_addrtype != CCA_NS_VAL_IPV4 && px_addrtype != CCA_NS_VAL_ALPHA)
    {
        if (px_addrtype == CCA_NS_VAL__INVALID || px_addrtype == CCA_NS_VAL__EMPTY)
        {
            px_addrtype = CCA_NS_VAL_IPV4;
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_PROXY_ADDRTYPE, px_addrtype);
            return CCA_STATUS_INVALID_SETTING;
        }
    }

    g_srv_dtcnt_ota_ctx.curr_proxy_item->proxy_flag = MMI_TRUE;
    g_srv_dtcnt_ota_ctx.curr_proxy_item->px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
    g_srv_dtcnt_ota_ctx.curr_proxy_item->px_port = 80;

    mmi_cca_iterator_restart(iter_datalist);

    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
    	if(data!=NULL)
    	{
            srv_dtcnt_ota_proc_cca_proxy_params(data);
    	}
    }

    if(applib_url_is_valid_ext((char*)g_srv_dtcnt_ota_ctx.curr_proxy_item->px_addr, KAL_TRUE, KAL_FALSE) < 0)
    {
        g_srv_dtcnt_ota_ctx.curr_proxy_item->proxy_flag = MMI_FALSE;
        memset(g_srv_dtcnt_ota_ctx.curr_proxy_item->px_addr, 0, SRV_DTCNT_PROF_MAX_PX_ADDR_LEN);       
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
cca_status_enum srv_dtcnt_ota_proc_cca_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *param;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    switch (symbol)
    {
    case DTCNT_OTAP_NS_BOOTSTRAP:
        
        status = CCA_STATUS_OK;             /* Initialize the status variable   */
        /* store the hash value of PROVURL */
        while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
        {   
            if(status == CCA_STATUS_OK)
            {
                status = srv_dtcnt_ota_proc_cca_param_bootstrap(param, &g_srv_dtcnt_ota_ctx);

            }
        }
        return CCA_STATUS_OK;
        
    case DTCNT_OTA_NAPDEF:
        
        status = CCA_STATUS_OK;             /* Initialize the status variable   */

        /* Processing the first setting now. */
        /* Prepare a storage for the new profile. */
        if(!g_srv_dtcnt_ota_ctx.active_item)
        {
            g_srv_dtcnt_ota_ctx.active_item = srv_dtcnt_ota_new_item();
            g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items = g_srv_dtcnt_ota_ctx.active_item;
        }
        else
        {
            g_srv_dtcnt_ota_ctx.active_item->next = srv_dtcnt_ota_new_item();
            g_srv_dtcnt_ota_ctx.active_item = g_srv_dtcnt_ota_ctx.active_item->next;
        }
        
        /* Init control block and save the ID/handle for the response msg. */

        if (!g_srv_dtcnt_ota_ctx.active_item)
        {
            MMI_ASSERT(0);
            return CCA_STATUS_FAIL;
        }
    
        while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
        {   
            if(status == CCA_STATUS_OK)
            {
                status = srv_dtcnt_ota_proc_cca_param(param, g_srv_dtcnt_ota_ctx.active_item);
                if(status == CCA_STATUS_FAIL)
                {
                    g_srv_dtcnt_ota_ctx.active_item->valid = FALSE;
                }
            }
        }
        return CCA_STATUS_OK;
    
    case DTCNT_OTA_NAPAUTHINFO:
        status = CCA_STATUS_OK;             /* Initialize the status variable   */
        
        /* Must be processed after a napdef, active_item cannot be NULL */
        if (!g_srv_dtcnt_ota_ctx.active_item)
        {
            return CCA_STATUS_FAIL;
        }

        while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
        {   
            if(status == CCA_STATUS_OK)
            {
                status = srv_dtcnt_ota_proc_cca_param(param, g_srv_dtcnt_ota_ctx.active_item);
                if(status == CCA_STATUS_FAIL)
                {
                    g_srv_dtcnt_ota_ctx.active_item->valid = FALSE;
                }
            }
        }
        return CCA_STATUS_OK;

    case DTCNT_OTA_PROXY:
        /* Processing the first proxy setting now. */
        if(!g_srv_dtcnt_ota_ctx.active_item)
        {
            MMI_ASSERT(0);
            return CCA_STATUS_FAIL;
        }
        /* first proxy item */
        else if (!g_srv_dtcnt_ota_ctx.curr_proxy_item)
        {
            g_srv_dtcnt_ota_ctx.curr_proxy_item = srv_dtcnt_ota_new_proxy_item();
            if (!g_srv_dtcnt_ota_ctx.curr_proxy_item)
            {
                MMI_ASSERT(0);
                return CCA_STATUS_FAIL;
            }
        }
        else /* a proxy item already exists */
        {
            srv_dtcnt_ota_update_proxy_to_acc_info();
            kal_mem_set(g_srv_dtcnt_ota_ctx.curr_proxy_item, 0, sizeof(srv_dtcnt_ota_proxy_item_struct));
        }

        status = srv_dtcnt_ota_proc_cca_proxy_node(param_list);
        break;

    case DTCNT_OTA_PORT:
        status = srv_dtcnt_ota_proc_cca_port_node(0, param_list);
        break;

    case DTCNT_OTA_PROXY_AUTHINFO:
        status = srv_dtcnt_ota_proc_cca_proxy_auth_node(0 ,param_list);
        break;
        
    default:
        return CCA_STATUS_OK;
    }
    return status;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_proxy_params
 * DESCRIPTION
 *  Based on the namespace identifier, it fill the proxy list.
 * PARAMETERS
 *  proxy_content       [IN]        
 *  data                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_ota_proc_cca_proxy_params(cca_core_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U32 len_ucs2 = 0;
    //U8  tmp_px_name[SRV_DTCNT_PROF_MAX_PX_NAME_LEN+1];
    //U8  tmp_px_addr[SRV_DTCNT_PROF_MAX_PX_ADDR_LEN+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_TO_NAPID:
        {
            U32 i;
            U8 nap_id_num = (data->size > 3)? 3:data->size;
            U8 *hash_val_dest = NULL;
            
            for (i=0; i<nap_id_num; i++)
            {
                if(data->values.s[i])
                {
                    if(strlen((CHAR *)data->values.s[i]) > 0)
                    {
                        switch(i)
                        {
                            case 0:
                                hash_val_dest = g_srv_dtcnt_ota_ctx.curr_proxy_item->napid_hash_val1;
                                break;
                            case 1:
                                hash_val_dest = g_srv_dtcnt_ota_ctx.curr_proxy_item->napid_hash_val2;
                                break;
                            case 2:
                                hash_val_dest = g_srv_dtcnt_ota_ctx.curr_proxy_item->napid_hash_val3;                                
                                break;
                            default:
                                ASSERT(0);
                        }
                        mmi_cca_generate_hash_value((CHAR*)data->values.s[i], hash_val_dest, SRV_DTCNT_NAPID_HASH_LEN);
                    }
                }
            }
        }
        break;
        #if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        case CCA_NS_OMA_PXADDR:
            if (data->values.s[0])
            {
                //strncpy((CHAR*) tmp_px_addr, (CHAR*) data->values.s[0], SRV_DTCNT_PROF_MAX_PX_ADDR_LEN);               
                //srv_dtcnt_ota_convert_cca_proxy_ip_str(tmp_px_addr, g_srv_dtcnt_ota_ctx.curr_proxy_item->px_addr);
                strncpy((CHAR*) g_srv_dtcnt_ota_ctx.curr_proxy_item->px_addr, (CHAR*) data->values.s[0], SRV_DTCNT_PROF_MAX_PX_ADDR_LEN); 
            }
            break;

        case CCA_NS_OMA_STARTPAGE:
            if (data->values.s[0])
            {
                strncpy(
                    (CHAR*) g_srv_dtcnt_ota_ctx.curr_proxy_item->px_startpage,
                    (CHAR*) data->values.s[0],
                    SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);
            }
            break;

        case CCA_NS_OMA_PXAUTH_ID:
            if (data->values.s[0])
            {
                strncpy(
                    (CHAR*) g_srv_dtcnt_ota_ctx.curr_proxy_item->px_authid,
                    (CHAR*) data->values.s[0],
                    SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN);
            }
            break;

        case CCA_NS_OMA_PXAUTH_PW:
            if (data->values.s[0])
            {
                strncpy(
                    (CHAR*) g_srv_dtcnt_ota_ctx.curr_proxy_item->px_authpw,
                    (CHAR*) data->values.s[0],
                    SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN);
            }
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_port_node
 * DESCRIPTION
 *  Handles proxy tag from CCA doc.
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
static cca_status_enum srv_dtcnt_ota_proc_cca_port_node(U8 dm_update, cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum result = CCA_STATUS_OK;
    //cca_status_enum status;
    S32 service_parm = 0;
    CHAR *portnbr_parm = NULL;
    U8 *temp_porxy_flag, *temp_port_flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_PROXY_PORT_OTA_FLAG, g_srv_dtcnt_ota_ctx.curr_proxy_item->proxy_flag);
    temp_porxy_flag = &(g_srv_dtcnt_ota_ctx.curr_proxy_item->proxy_flag);
    temp_port_flag  = &(g_srv_dtcnt_ota_ctx.curr_proxy_item->port_flag);

#ifdef SYNCML_DM_SUPPORT
    if (dm_update)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_PROXY_PORT_DM_FLAG, g_srv_dtcnt_dm_cntx.proxy_flag);
        temp_porxy_flag = &(g_srv_dtcnt_dm_cntx.proxy_flag);
        temp_port_flag  = &(g_srv_dtcnt_dm_cntx.port_flag);
    }
#endif /* SYNCML_DM_SUPPORT */

    if (*temp_porxy_flag == MMI_TRUE)
    {
        mmi_cca_doc_get_nodedata_int_first(iter_datalist, CCA_NS_OMA_SERVICE, &service_parm);
        if ((service_parm != CCA_NS_VAL_CO_SEC_WTA || service_parm != CCA_NS_VAL_CL_SEC_WTA) &&
            (*temp_port_flag == MMI_FALSE))
        {
            mmi_cca_doc_get_nodedata_str_first(iter_datalist, CCA_NS_OMA_PORTNBR, &portnbr_parm);
            srv_dtcnt_ota_proc_cca_port_n_srv_params(dm_update, service_parm, portnbr_parm);
            *temp_port_flag = MMI_TRUE;
        }
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_port_n_srv_params
 * DESCRIPTION
 *  it fills the service / port parameter for the proxy.
 * PARAMETERS
 *  proxy_content       [IN]        
 *  service_parm        [IN]        
 *  portnbr_parm        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_ota_proc_cca_port_n_srv_params(U8 dm_update, S32 service_parm, CHAR *portnbr_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 port_number = 0;
    srv_dtcnt_prof_px_srv_enum *tmp_px_srv;
    U16 *tmp_px_port;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * CL-WAP            9200  WAP
     * CO-WSP            9201  WAP
     * CL-SEC-WSP        9202  WAP + Security ON
     * CO-SEC-WSP        9203  WAP + Security ON
     * CO-SEC-WTA        not supported
     * CL-SEC-WTA        not supported
     * OTA-HTTP-TO       80    HTTP
     * OTA-HTTP-TLS-TO   443   HTTP + Security ON
     * OTA-HTTP-PO       80    HTTP
     * OTA-HTTP-TLS-PO   443   HTTP + Security ON
     * 
     * all others --> HTTP
     * 
     */

    tmp_px_srv = &(g_srv_dtcnt_ota_ctx.curr_proxy_item->px_service);
    tmp_px_port  = &(g_srv_dtcnt_ota_ctx.curr_proxy_item->px_port);

#ifdef SYNCML_DM_SUPPORT
    if (dm_update)
    {
        tmp_px_srv = &(g_srv_dtcnt_dm_cntx.dm_item_cntx.px_service);
        tmp_px_port  = &(g_srv_dtcnt_dm_cntx.dm_item_cntx.px_port);
    }
#endif /* SYNCML_DM_SUPPORT */

#ifdef __SRV_DTCNT_OTA_PROF_PORT_PRIORITY__
    if (portnbr_parm)
    {
        port_number = atoi(portnbr_parm);
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_PROXY_PORT_AND_SERVICE, service_parm, port_number);

    /* First priority is of port number */
    switch (port_number)
    {
        case 9200:
        case 9201:
            *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
            *tmp_px_port = 9201;
            break;

        case 9202:
        case 9203:
            *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP;
            *tmp_px_port = 9203;
            break;
    #ifdef WAP2
        case 80:
        case 8080:
        case 443:
            *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_HTTP;
            *tmp_px_port = port_number;
            break;
    #endif /* WAP2 */ 
        default:
            /* If standard port numbers did not match, change port number according to service. */
        {
            switch (service_parm)
            {

                case CCA_NS_VAL_CL_WSP:
                case CCA_NS_VAL_CO_WSP:
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
                    *tmp_px_port = 9201;
                    break;

                case CCA_NS_VAL_CL_SEC_WSP:
                case CCA_NS_VAL_CO_SEC_WSP:
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP;
                    *tmp_px_port = 9203;
                    break;
            #ifdef WAP2
                case CCA_NS_VAL_OTA_HTTP_TLS_TO:
                case CCA_NS_VAL_OTA_HTTP_TLS_PO:
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_HTTP;
                    srv_dtcnt_ota_proc_cca_port_helper(tmp_px_port, portnbr_parm, 443);
                    break;

                case CCA_NS_VAL_OTA_HTTP_TO:
                case CCA_NS_VAL_OTA_HTTP_PO:
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_HTTP;
                    srv_dtcnt_ota_proc_cca_port_helper(tmp_px_port, portnbr_parm, 80);
                    break;
            #endif /* WAP2 */ 
            #ifdef WAP2
                default:
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_HTTP;
                    srv_dtcnt_ota_proc_cca_port_helper(tmp_px_port, portnbr_parm, 80);
            #else /* WAP2 */ 
                default:
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
                    *tmp_px_port = 9201;
            #endif /* WAP2 */ 
            }
        }
            break;
    }

#else /* __SRV_DTCNT_OTA_PROF_PORT_PRIORITY__ */ 
 
    /* Service has higher priority. */
    switch (service_parm)
    {
        case CCA_NS_VAL_CL_WSP:
        case CCA_NS_VAL_CO_WSP:
            *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
            *tmp_px_port = 9201;
            break;

        case CCA_NS_VAL_CL_SEC_WSP:
        case CCA_NS_VAL_CO_SEC_WSP:
            *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP;
            *tmp_px_port = 9203;
            break;
    #ifdef WAP2
        case CCA_NS_VAL_OTA_HTTP_TLS_TO:
        case CCA_NS_VAL_OTA_HTTP_TLS_PO:
            *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_HTTP;
            srv_dtcnt_ota_proc_cca_port_helper(tmp_px_port, portnbr_parm, 443);
            break;

        case CCA_NS_VAL_OTA_HTTP_TO:
        case CCA_NS_VAL_OTA_HTTP_PO:
            *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_HTTP;
            srv_dtcnt_ota_proc_cca_port_helper(tmp_px_port, portnbr_parm, 80);
            break;
    #endif /* WAP2 */ 
        default:
            if (portnbr_parm != NULL && portnbr_parm[0] != '\0')
            {
                port_number = atoi(portnbr_parm);
                if (port_number == 9200 || port_number == 9201)
                {
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
                    *tmp_px_port = 9201;
                }
                else if (port_number == 9202 || port_number == 9203)
                {
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP;
                    *tmp_px_port = 9201;
                }
                else
                {
                #ifdef WAP2
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_HTTP;
                    srv_dtcnt_ota_proc_cca_port_helper(tmp_px_port, portnbr_parm, 80);
                #else 
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
                    *tmp_px_port = 9201;                
                #endif 
                }
            }
            else
            {
                #ifdef WAP2
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_HTTP;
                    srv_dtcnt_ota_proc_cca_port_helper(tmp_px_port, portnbr_parm, 80);
                #else 
                    *tmp_px_srv = SRV_DTCNT_PROF_PX_SRV_CO_WSP;
                    *tmp_px_port = 9201;
                #endif 
            }
    }
#endif /* __SRV_DTCNT_OTA_PROF_PORT_PRIORITY__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_port_helper
 * DESCRIPTION
 *  It fills the prot parameter for the proxy.
 * PARAMETERS
 *  proxy_content               [IN]        
 *  portnbr_parm                [IN]        
 *  default_portnbr_parm        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_ota_proc_cca_port_helper(U16 *port_out, CHAR *portnbr_parm, S32 default_portnbr_parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 port_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (portnbr_parm == NULL)
    {
        *port_out = (U16)default_portnbr_parm;
        return;
    }

    srv_dtcnt_ota_utf8_strltrim(portnbr_parm);

    if (strcmp(portnbr_parm, "") == 0)
    {
        *port_out = (U16)default_portnbr_parm;
    }
    else if (!(isdigit(portnbr_parm[0])))
    {
        *port_out = (U16)default_portnbr_parm;
    }
    else
    {
        port_number = atoi(portnbr_parm);
        if (port_number <= 0 || port_number > 65535)
        {
            *port_out = (U16)default_portnbr_parm;
        }
        else
        {
            *port_out = (U16)port_number;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_cca_proxy_auth_node
 * DESCRIPTION
 *  Handles proxy tag from CCA doc.
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
static cca_status_enum srv_dtcnt_ota_proc_cca_proxy_auth_node(U8 dm_update, cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;
    cca_status_enum result = CCA_STATUS_OK;
    U8 *temp_porxy_flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_PROXY_AUTHINFO_OTA_FLAG, g_srv_dtcnt_ota_ctx.curr_proxy_item->proxy_flag);

    temp_porxy_flag = &(g_srv_dtcnt_ota_ctx.curr_proxy_item->proxy_flag);

#ifdef SYNCML_DM_SUPPORT
    if (dm_update)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_PROXY_AUTHINFO_DM_FLAG, g_srv_dtcnt_dm_cntx.proxy_flag);
        temp_porxy_flag = &(g_srv_dtcnt_dm_cntx.proxy_flag);
    }
#endif /* SYNCML_DM_SUPPORT */


    if (*temp_porxy_flag == MMI_TRUE)
    {
        while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
        {
			if(data!=NULL)
			{
                srv_dtcnt_ota_proc_cca_proxy_params(data);
            }
        }
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_install_common_item_new
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_dtcnt_ota_install_common_item_new(srv_dtcnt_prof_common_header_struct *item, U32 *out_fields, U8 update)
{
    //U32 i,sum;
    /* sim info */
    switch (g_srv_dtcnt_ota_ctx.sim_id)
    {
        case MMI_SIM_NONE:
        case MMI_SIM1:
            item->sim_info = SRV_DTCNT_SIM_TYPE_1;
            break;
        case MMI_SIM2:
            item->sim_info = SRV_DTCNT_SIM_TYPE_2;
            break;
        case MMI_SIM3:
            item->sim_info = SRV_DTCNT_SIM_TYPE_3;
            break;
        case MMI_SIM4:
            item->sim_info = SRV_DTCNT_SIM_TYPE_4;
            break;
        default:
            MMI_ASSERT(0);
    }
    *out_fields |= SRV_DTCNT_PROF_FIELD_SIM_TYPE;

    /* account name */
    item->AccountName = (U8 *)g_srv_dtcnt_ota_ctx.current_item->name;
    *out_fields |= SRV_DTCNT_PROF_FIELD_NAME;

    /* auth_info */
    strcpy((CHAR *) item->Auth_info.UserName, (CHAR *) g_srv_dtcnt_ota_ctx.current_item->UserName);
    strcpy((CHAR *) item->Auth_info.Passwd, (CHAR *) g_srv_dtcnt_ota_ctx.current_item->Passwd);
    *out_fields |= SRV_DTCNT_PROF_FIELD_AUTH_USER_INFO;

    if (!update)
    {
        /* profile hash values */
        memcpy(item->napid_hash_val, g_srv_dtcnt_ota_ctx.current_item->napid_hash_val, SRV_DTCNT_NAPID_HASH_LEN);
        memcpy(item->provurl_hash_val, g_srv_dtcnt_ota_ctx.provurl_hash_val, SRV_DTCNT_PROVURL_HASH_LEN);
        *out_fields |= SRV_DTCNT_PROF_FIELD_HASH_VAL;

        /* account type */
        item->acct_type = SRV_DTCNT_PROF_TYPE_OTA_CONF;
        *out_fields |= SRV_DTCNT_PROF_FIELD_ACC_TYPE;
    }

    /* primary dns */
    memcpy(item->PrimaryAddr, g_srv_dtcnt_ota_ctx.current_item->DnsAddress, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    *out_fields |= SRV_DTCNT_PROF_FIELD_INET_PRI_DNS;

    item->px_port = g_srv_dtcnt_ota_ctx.current_item->px_port;
    *out_fields |= SRV_DTCNT_PROF_FIELD_PX_PORT;
    item->px_service = g_srv_dtcnt_ota_ctx.current_item->px_service;
    *out_fields |= SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE;

    memcpy(item->HomePage, g_srv_dtcnt_ota_ctx.current_item->px_startpage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);
    *out_fields |= SRV_DTCNT_PROF_FIELD_HOME;
    
    memcpy(item->px_addr, g_srv_dtcnt_ota_ctx.current_item->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1);
    *out_fields |= SRV_DTCNT_PROF_FIELD_PX_ADDR;
    item->use_proxy = 0;
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
    item->px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN] = 0;
    if(strlen((CHAR*)item->px_addr) != 0)
    {
        item->use_proxy = 1;
        *out_fields |= SRV_DTCNT_PROF_FIELD_USE_PX;
    }

    memcpy(item->px_authid, g_srv_dtcnt_ota_ctx.current_item->px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
    *out_fields |= SRV_DTCNT_PROF_FIELD_PX_AUTH_ID;

    memcpy(item->px_authpw, g_srv_dtcnt_ota_ctx.current_item->px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
    *out_fields |= SRV_DTCNT_PROF_FIELD_PX_AUTH_PW;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_dup_item
 * DESCRIPTION
 *  This function allocates and initializes the control block of voip OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
static srv_dtcnt_ota_item_struct *srv_dtcnt_ota_dup_item(srv_dtcnt_ota_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_ota_item_struct *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate the control block. Must be successful. */
    p = (srv_dtcnt_ota_item_struct *)OslMalloc(sizeof(srv_dtcnt_ota_item_struct));
    if (p == NULL)
    {
        return NULL;
    }

    /* Copy the entire structure. */
    memcpy(p, item, sizeof(srv_dtcnt_ota_item_struct));
    p->next = NULL;
    
    kal_mem_set(p->px_addr, 0, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1);
    kal_mem_set(p->px_authid, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
    kal_mem_set(p->px_authpw, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
    kal_mem_set(p->px_startpage, 0, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);        
    p->px_service = SRV_DTCNT_PROF_PX_SRV_NONE;
    p->px_port = 0;

    p->valid = TRUE;    
    return p;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proxy_info_copy
 * DESCRIPTION
 *  This function allocates and initializes the control block of voip OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
static void srv_dtcnt_ota_proxy_info_copy(srv_dtcnt_ota_item_struct *dest, srv_dtcnt_ota_proxy_item_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dest && src);
    kal_mem_cpy(dest->px_addr, src->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1);
    kal_mem_cpy(dest->px_authid, src->px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
    kal_mem_cpy(dest->px_authpw, src->px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
    kal_mem_cpy(dest->px_startpage, src->px_startpage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);        
    dest->px_service = src->px_service;
    dest->px_port = src->px_port;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_update_proxy_to_acc_info
 * DESCRIPTION
 *  This function allocates and initializes the control block of voip OTA
 *  provisioning application.
 * PARAMETERS
 *  conf_id         [IN]            CCA configuration ID
 *  doc_hdl         [IN]            Configuration document handle
 * RETURNS
 *  On success, return the address of control block. On error, return NULL.
 *****************************************************************************/
static void srv_dtcnt_ota_update_proxy_to_acc_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, imax;
    PU8 nap_id_hash[3] = {0,};
    srv_dtcnt_ota_item_struct *p = NULL;
    srv_dtcnt_ota_item_struct *q = NULL;
    U8 null_hash[SRV_DTCNT_NAPID_HASH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_dtcnt_ota_ctx.curr_proxy_item && g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items);

    memset(null_hash, 0, sizeof(U8)*SRV_DTCNT_NAPID_HASH_LEN);
    if (memcmp(null_hash, g_srv_dtcnt_ota_ctx.curr_proxy_item->napid_hash_val1, sizeof(U8)*SRV_DTCNT_NAPID_HASH_LEN))
    {
        nap_id_hash[i++] = g_srv_dtcnt_ota_ctx.curr_proxy_item->napid_hash_val1;
    }
    if (memcmp(null_hash, g_srv_dtcnt_ota_ctx.curr_proxy_item->napid_hash_val2, sizeof(U8)*SRV_DTCNT_NAPID_HASH_LEN))
    {
        nap_id_hash[i++] = g_srv_dtcnt_ota_ctx.curr_proxy_item->napid_hash_val2;
    }
    if (memcmp(null_hash, g_srv_dtcnt_ota_ctx.curr_proxy_item->napid_hash_val3, sizeof(U8)*SRV_DTCNT_NAPID_HASH_LEN))
    {
        nap_id_hash[i++] = g_srv_dtcnt_ota_ctx.curr_proxy_item->napid_hash_val3;
    }
    imax = i;
    
    for (i=0; (imax>0 && i<imax); i++)
    {
        p = g_srv_dtcnt_ota_ctx.g_dtcnt_ota_items;
        while (p)
        {
            if (srv_dtcnt_ota_hash_value_is_equal(p->napid_hash_val, nap_id_hash[i], SRV_DTCNT_NAPID_HASH_LEN))
            {
                /* already a proxy using the same account */
                if (p->px_addr[0])
                {
                    q = srv_dtcnt_ota_dup_item(p);
                    if (!q)
                    {
                        /* memory full case, ignore */
                        break;
                    }
                    srv_dtcnt_ota_proxy_info_copy(q, g_srv_dtcnt_ota_ctx.curr_proxy_item);
                    q->next = p->next;
                    p->next = q;

                    if (g_srv_dtcnt_ota_ctx.active_item && g_srv_dtcnt_ota_ctx.active_item == p)
                    {
                        g_srv_dtcnt_ota_ctx.active_item = p->next;                        
                    }
					break;
                }
                else
                {
                    srv_dtcnt_ota_proxy_info_copy(p, g_srv_dtcnt_ota_ctx.curr_proxy_item);
                    p = p->next;
                }
            }
            else
            {
                p = p->next;
            }
        }
    }
    
}

void srv_dtcnt_ota_done_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prov_done_ind_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_WLAN_OTAP_DONE);
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_PROV_DONE_IND);    

    /* construct event struct */
    evt.prov_ind = SRV_DTCNT_PROV_IND_CSD;
    evt.prof_data = NULL;
    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
}


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_is_a_matched_account
 * DESCRIPTION
 *  Find the installation mode of an account given
 * PARAMETERS
 *  matched_index   [out]   start from 0
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_dtcnt_ota_is_a_matched_account(U8* provurl_hash,
                                            U8* napid_hash,
                                            U32 factory_acct_updatable,
                                            CHAR* acct_name, S32 acct_name_length,
                                            U8* matched_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U16 number_may_updatable = 0;
    U8 indexes_maybe_matched[SRV_DTCNT_PROF_MAX_ACCOUNT_NUM];
    U16 max_pri, priority;
    MMI_BOOL is_empty;
    MMI_BOOL find = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_dtcnt_ota_hash_value_is_empty(provurl_hash, SRV_DTCNT_PROVURL_HASH_LEN))
    {/* empty provurl */
        return MMI_FALSE;
    }
    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use)
        {
            if (srv_dtcnt_ota_hash_value_is_equal(provurl_hash, 
                                                   g_srv_dtcnt_store_ctx.acc_list[i].provurl_hash_val, 
                                                   SRV_DTCNT_PROVURL_HASH_LEN))
            {/* provurl matched */
                if (srv_dtcnt_ota_hash_value_is_empty(g_srv_dtcnt_store_ctx.acc_list[i].napid_hash_val, 
                                                            SRV_DTCNT_NAPID_HASH_LEN))
                {
                    if (mmi_ucs2strlen((CHAR*)g_srv_dtcnt_store_ctx.acc_list[i].acc_name) > 0 && acct_name_length > 0)
                    {
                        if (mmi_ucs2cmp((char *)g_srv_dtcnt_store_ctx.acc_list[i].acc_name, (CHAR*)acct_name) == 0)
                        {/* empty napid, but account name matched */

                            if( g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == g_srv_dtcnt_ota_ctx.current_item->bearer)
                            {
                            indexes_maybe_matched[number_may_updatable] = i+1;
                            number_may_updatable++;
                            find = MMI_TRUE;
                            continue;

                            }
                        }
                    }
                }
                else if (srv_dtcnt_ota_hash_value_is_equal(napid_hash, 
                                                       g_srv_dtcnt_store_ctx.acc_list[i].napid_hash_val, 
                                                       SRV_DTCNT_NAPID_HASH_LEN))
                {/* napid matched, and both not empty */
                    if( g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == g_srv_dtcnt_ota_ctx.current_item->bearer)
                    {
                    indexes_maybe_matched[number_may_updatable] = i+1;
                    number_may_updatable++;
                    find = MMI_TRUE;
                    continue;

                    }

                }
            }
        }
    }
    /* updatable_account_number >= 0 */
    for (max_pri = 0, i = 0; i < number_may_updatable; i++)
    {
        is_empty = srv_dtcnt_ota_hash_value_is_empty(
                        g_srv_dtcnt_store_ctx.acc_list[indexes_maybe_matched[i]].napid_hash_val, 
                        SRV_DTCNT_NAPID_HASH_LEN);
        if (!is_empty)
        {
            priority = 2;
        }
        else /* is_empty */
        {
            priority = 1;
        }
        
        if (priority > max_pri)
        {
            *matched_index = indexes_maybe_matched[i];
            max_pri = priority;
        }
    }
    return find;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_is_valid_but_discard
 * DESCRIPTION
 *  Find the installation mode of an account given
 * PARAMETERS
 *  matched_index   [out]   start from 0
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_dtcnt_ota_is_valid_but_discard(U8* provurl_hash,
                                                  U8* napid_hash,
                                                  U32 factory_acct_updatable,
                                                  CHAR* acct_name, S32 acct_name_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_dtcnt_prof_acc_type_enum acct_type;
    MMI_BOOL is_pre_conf;
    U8 DataAccountName[(SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) *ENCODING_LENGTH];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_dtcnt_ota_hash_value_is_empty(provurl_hash, SRV_DTCNT_PROVURL_HASH_LEN))
    {/* empty provurl */
        return MMI_FALSE;
    }
    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        srv_dtcnt_account_info_st *info = &( g_srv_dtcnt_store_ctx.acc_list[i]);

        acct_type = info->acc_type;
        is_pre_conf = (acct_type == SRV_DTCNT_PROF_TYPE_FACTORY_CONF) ? MMI_TRUE : MMI_FALSE;
        if (srv_dtcnt_ota_hash_value_is_equal(provurl_hash, 
                                               info->provurl_hash_val, 
                                               SRV_DTCNT_PROVURL_HASH_LEN))
        {/* provurl matched */
            if (srv_dtcnt_ota_hash_value_is_empty(info->napid_hash_val, 
                                                        SRV_DTCNT_NAPID_HASH_LEN))
            {
                if (mmi_ucs2strlen((CHAR*)info->acc_name) > 0 && acct_name_length > 0)
                {
                    mmi_ucs2ncpy((CHAR*)DataAccountName, (CHAR*)info->acc_name, SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1);
                    if (mmi_ucs2cmp((CHAR*)DataAccountName, (CHAR*)acct_name) == 0)
                    {/* empty napid, but account name matched */
                        if (is_pre_conf && !factory_acct_updatable)
                        {
                            return MMI_TRUE;
                        }
                        continue;
                    }
                }
            }
            else if (srv_dtcnt_ota_hash_value_is_equal(napid_hash, 
                                                   info->napid_hash_val, 
                                                   SRV_DTCNT_NAPID_HASH_LEN))
            {/* napid matched, and both not empty */
                if (is_pre_conf && !factory_acct_updatable)
                {
                    return MMI_TRUE;
                }
                continue;
            }
        }
    }
    return MMI_FALSE;
}


#ifdef __TCPIP_OVER_CSD__
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_update_csd_item
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_dtcnt_ota_update_csd_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_data_struct prof = {0, };    
    srv_dtcnt_prof_csd_struct new_csd_item = {0,};
    srv_dtcnt_result_enum ret;
    srv_dtcnt_prov_install_res_ind_evt_struct evt;
    g_srv_dtcnt_ota_ctx.installed_acct_id = g_srv_dtcnt_store_ctx.acc_list[g_srv_dtcnt_ota_ctx.matched_index - 1].acc_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_UPDATE_CSD);

    srv_dtcnt_ota_install_common_item_new(&(new_csd_item.prof_common_header), &(prof.prof_fields), 1);    
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_USE_PX;
	if (mmi_ucs2strlen((const char *)new_csd_item.prof_common_header.AccountName) == 0)
	{
	    prof.prof_fields &= ~SRV_DTCNT_PROF_FIELD_NAME;
	}
    
    new_csd_item.DialNumber = (U8*)g_srv_dtcnt_ota_ctx.current_item->address;
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM;    
    new_csd_item.DialType = (srv_dtcnt_prof_csd_dial_type_enum)g_srv_dtcnt_ota_ctx.current_item->DialType;
    new_csd_item.DataRate = (srv_dtcnt_prof_csd_rate_enum)g_srv_dtcnt_ota_ctx.current_item->DataRate;
    prof.prof_fields |= (SRV_DTCNT_PROF_FIELD_DATA_RATE|SRV_DTCNT_PROF_FIELD_DIAL_TYPE);

    new_csd_item.prof_common_header.read_only = g_srv_dtcnt_store_ctx.acc_list[g_srv_dtcnt_ota_ctx.matched_index-1].readonly;
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_READONLY;
    g_srv_dtcnt_ota_ctx.matched_index = 0;

    prof.prof_type = SRV_DTCNT_BEARER_CSD;
    prof.prof_data = &(new_csd_item);
    ret = srv_dtcnt_store_update_prof(g_srv_dtcnt_ota_ctx.installed_acct_id, &prof);
    
    if (ret == SRV_DTCNT_RESULT_SUCCESS)
    {
        /* Install successfully. Update counter. */
        g_srv_dtcnt_ota_ctx.num_installed++;
        g_srv_dtcnt_ota_ctx.num_updated++;
        srv_dtcnt_ota_post_install_res_evt(&evt, 1, SRV_DTCNT_PROF_TYPE_OTA_CONF);
        mmi_cca_oma_add_dataacctid(g_srv_dtcnt_ota_ctx.doc_hdl, (CHAR *)g_srv_dtcnt_ota_ctx.current_item->node_id, g_srv_dtcnt_ota_ctx.installed_acct_id);
    }
    else
    {
        srv_dtcnt_ota_post_install_res_evt(&evt, 0, SRV_DTCNT_PROF_TYPE_OTA_CONF);
    }

    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
}
#endif  /* __TCPIP_OVER_CSD__ */

#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_update_gprs_item
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_dtcnt_ota_update_gprs_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_data_struct prof = {0,};
    srv_dtcnt_prof_gprs_struct new_gprs_item = {0,};
    srv_dtcnt_result_enum ret;
    srv_dtcnt_prov_install_res_ind_evt_struct evt;
    g_srv_dtcnt_ota_ctx.installed_acct_id = g_srv_dtcnt_store_ctx.acc_list[g_srv_dtcnt_ota_ctx.matched_index-1].acc_id;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_UPDATE_GPRS);

    srv_dtcnt_ota_install_common_item_new(&new_gprs_item.prof_common_header, &prof.prof_fields, 1);
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_USE_PX;
	if (mmi_ucs2strlen((const char *)new_gprs_item.prof_common_header.AccountName) == 0)
	{
	    prof.prof_fields &= ~SRV_DTCNT_PROF_FIELD_NAME;
	}
    
    new_gprs_item.APN = (U8*)g_srv_dtcnt_ota_ctx.current_item->address;
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM;

    new_gprs_item.prof_common_header.Auth_info.AuthType = 
        (g_srv_dtcnt_ota_ctx.current_item->AuthType)? SRV_DTCNT_PROF_GPRS_AUTH_TYPE_SECURE : SRV_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL;
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_AUTH_TYPE;
    
    new_gprs_item.prof_common_header.read_only = g_srv_dtcnt_store_ctx.acc_list[g_srv_dtcnt_ota_ctx.matched_index-1].readonly;
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_READONLY;
    g_srv_dtcnt_ota_ctx.matched_index = 0;    
    
    prof.prof_type = SRV_DTCNT_BEARER_GPRS;
    prof.prof_data = &(new_gprs_item);
    
    ret = srv_dtcnt_store_update_prof(g_srv_dtcnt_ota_ctx.installed_acct_id, &prof);

    if (ret == SRV_DTCNT_RESULT_SUCCESS)
    {
        /* Install successfully. Update counter. */
        g_srv_dtcnt_ota_ctx.num_installed++;
        g_srv_dtcnt_ota_ctx.num_updated++;
        srv_dtcnt_ota_post_install_res_evt(&evt, 1, SRV_DTCNT_PROF_TYPE_OTA_CONF);
        mmi_cca_oma_add_dataacctid(g_srv_dtcnt_ota_ctx.doc_hdl, (CHAR *)g_srv_dtcnt_ota_ctx.current_item->node_id, g_srv_dtcnt_ota_ctx.installed_acct_id);
    }
    else
    {
        srv_dtcnt_ota_post_install_res_evt(&evt, 0, SRV_DTCNT_PROF_TYPE_OTA_CONF);
    }

    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);   
}
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */


#ifdef __TCPIP_OVER_CSD__
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_install_csd_item
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_dtcnt_ota_install_csd_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_data_struct prof;
    srv_dtcnt_prof_csd_struct new_csd_item = {0,};
    srv_dtcnt_result_enum ret;
    srv_dtcnt_prov_install_res_ind_evt_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_CSD);

    srv_dtcnt_ota_install_common_item_new(&(new_csd_item.prof_common_header), &(prof.prof_fields), 0);
    
    new_csd_item.DialNumber = (U8*)g_srv_dtcnt_ota_ctx.current_item->address;
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM;    
    new_csd_item.DialType = (g_srv_dtcnt_ota_ctx.current_item->DialType)? SRV_DTCNT_PROF_CSD_DIAL_TYPE_ISDN : SRV_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE;
    new_csd_item.DataRate = (srv_dtcnt_prof_csd_rate_enum)g_srv_dtcnt_ota_ctx.current_item->DataRate;
    prof.prof_fields |= (SRV_DTCNT_PROF_FIELD_DATA_RATE|SRV_DTCNT_PROF_FIELD_DIAL_TYPE);

    prof.prof_type = SRV_DTCNT_BEARER_CSD;
    prof.prof_data = &(new_csd_item);
    ret = srv_dtcnt_store_add_prof(&prof, &g_srv_dtcnt_ota_ctx.installed_acct_id);
    
    if (ret == SRV_DTCNT_RESULT_SUCCESS)
    {
        /* Install successfully. Update counter. */
        g_srv_dtcnt_ota_ctx.num_installed++;
        srv_dtcnt_ota_post_install_res_evt(&evt, 1, SRV_DTCNT_PROF_TYPE_OTA_CONF);
        mmi_cca_oma_add_dataacctid(g_srv_dtcnt_ota_ctx.doc_hdl, (CHAR*)g_srv_dtcnt_ota_ctx.current_item->node_id, g_srv_dtcnt_ota_ctx.installed_acct_id);
    }
    else
    {
        srv_dtcnt_ota_post_install_res_evt(&evt, 0, SRV_DTCNT_PROF_TYPE_OTA_CONF);
    }

    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
}

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_install_SIM_csd_item
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_dtcnt_ota_install_sim_csd_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_sim_csd_account_info_st prof = {0,};
    srv_dtcnt_result_enum ret;
    srv_dtcnt_prov_install_res_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_SIM_CSD);

    srv_dtcnt_ota_install_sim_common_item_new(&(prof.comm_header)); 
    strcpy((CHAR *) prof.DialNumber, (CHAR *) g_srv_dtcnt_ota_ctx.current_item->address);
    prof.DialType = (srv_dtcnt_prof_csd_dial_type_enum)g_srv_dtcnt_ota_ctx.current_item->DialType;
    prof.DataRate = (srv_dtcnt_prof_csd_rate_enum)g_srv_dtcnt_ota_ctx.current_item->DataRate;
    prof.comm_header.fields |= (SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM |
                                SRV_DTCNT_PROF_FIELD_DIAL_TYPE |
                                SRV_DTCNT_PROF_FIELD_DATA_RATE);
 
    ret = srv_dtcnt_db_store_add_sim_prof((void *)&prof, SRV_DTCNT_BEARER_CSD, &g_srv_dtcnt_ota_ctx.installed_acct_id);    
    if (ret == SRV_DTCNT_RESULT_SUCCESS)
    {
        srv_dtcnt_ota_post_install_res_evt(&evt, 1, SRV_DTCNT_PROF_TYPE_SIM_PROF);        
        MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);

        /* Install successfully. */
        mmi_cca_oma_add_dataacctid(g_srv_dtcnt_ota_ctx.doc_hdl, (CHAR *)g_srv_dtcnt_ota_ctx.current_item->node_id, g_srv_dtcnt_ota_ctx.installed_acct_id);
    }
}
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
#ifdef SYNCML_DM_SUPPORT
/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_gen_csd_prof_for_cca
* DESCRIPTION
*  Get CSD Profile Info by id
* PARAMETERS
* 
* RETURNS
*****************************************************************************/
static void srv_dtcnt_ota_gen_csd_prof_for_cca(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 hConfig = 0, hRoot = 0, hNode = 0, hProxy = 0;
    U8 temp_uft8_buff[17];
    U8 temp_utf8_name_buff[SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1] = {0,}; 
    U8 temp_proxy_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];
    srv_dtcnt_account_info_st *acc_info = NULL;
    CHAR proxy_port_str[6] = {0,};
    srv_dtcnt_prof_common_header_struct *data;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_DM_GEN_CSD_PROF, g_srv_dtcnt_dm_cntx.selected_id);
		
	hRoot = mmi_cca_doc_new_rootnode();
	if (!hRoot)
	{
        goto send_fail_rsp;
	}
	
	hNode = mmi_cca_doc_new_node_and_attach(DTCNT_OTA_NAPDEF, hRoot);
	if (!hNode)
	{
        goto send_fail_rsp;
	}
	
    acc_info = srv_dtcnt_db_store_get_acc_info(g_srv_dtcnt_dm_cntx.selected_id);
    MMI_ASSERT(acc_info && acc_info->bearer_type == SRV_DTCNT_BEARER_CSD);

    /* Gen NAPDEF information */
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_NODEID, (CHAR *) SRV_DTCNT_DM_CSD_NODE_ID);

    srv_dtcnt_ota_charset_convert((CHAR *)acc_info->acc_name, 
                                  (CHAR *)temp_utf8_name_buff, 
                                  (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1),
                                  SRV_DTCNT_UCS2_UTF8);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAME, (CHAR *) temp_utf8_name_buff);
	mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_BEARER, CCA_NS_VAL_GSM_CSD);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAP_ADDRESS, (CHAR *) acc_info->dest_name);
    memset((CHAR *) temp_uft8_buff, 0, 17);
    sprintf(
        (char *)temp_uft8_buff,
        "%u.%u.%u.%u",
        acc_info->PrimaryAddr[0],
        acc_info->PrimaryAddr[1],
        acc_info->PrimaryAddr[2],
        acc_info->PrimaryAddr[3]);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_DNS_ADDR, (CHAR *) temp_uft8_buff);

	if(acc_info->DialType == SRV_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE)
	{
		mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_CALLTYPE, CCA_NS_VAL_ANALOG_MODEM);
	}
	else
	{
		mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_CALLTYPE, CCA_NS_VAL_BIT_TRANSPARENT);
	}	
	mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_LINKSPEED, acc_info->DataRate);
	hNode = mmi_cca_doc_new_node_and_attach(DTCNT_OTA_NAPAUTHINFO, hNode);	
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_AUTHNAME, (CHAR *) acc_info->auth_info.UserName);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_AUTHSECRET, (CHAR *) acc_info->auth_info.Passwd);

    /* Gen Proxy information */
    hProxy = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, hRoot);
    if (!hProxy)
    {
        goto send_fail_rsp;
    }

    data = OslMalloc(sizeof(srv_dtcnt_prof_common_header_struct));
    kal_mem_set(data, 0, sizeof(srv_dtcnt_prof_common_header_struct));
    if (srv_dtcnt_db_store_load_prof(acc_info, data) == SRV_DTCNT_RESULT_SUCCESS)
    {
        data->px_service = acc_info->px_service;
    }
    else
    {
        OslMfree(data);
        goto send_fail_rsp;
    }

    mmi_cca_doc_add_nodedata_int(hProxy, CCA_NS_DATAACCTID, (S32)g_srv_dtcnt_dm_cntx.selected_id);
    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_NODEID, (CHAR *)SRV_DTCNT_DM_PROXY_NODE_ID);
    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_PROXY_ID, (CHAR *)SRV_DTCNT_DM_PROXY_NODE_ID);
    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_NAME, (CHAR *) temp_utf8_name_buff);

    switch (g_srv_dtcnt_dm_cntx.prof_id)
    {
        case DM_SETTING_TYPE_DATA_ACCOUNT_CSD:
            mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_STARTPAGE, (CHAR *)data->HomePage);
            break;
            
        default:
            break;
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
    #endif
    memset((U8 *) temp_proxy_addr, 0, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1);
    memcpy(temp_proxy_addr, data->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
    
    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_PXADDR, (CHAR*)temp_proxy_addr);
    
    hNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, hProxy);
    mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PXAUTH_ID, (CHAR*) data->px_authid);
    mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PXAUTH_PW, (CHAR*) data->px_authpw);

    hNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, hProxy);
    sprintf(proxy_port_str, "%d", data->px_port);
    mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PORTNBR, proxy_port_str);    
    mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_SERVICE, srv_dtcnt_ota_convert_conn_type(data->px_service));
    
    OslMfree(data);		
	hConfig = mmi_cca_doc_new(hRoot);
	if(hConfig)
	{
    	g_srv_dtcnt_dm_cntx.hconfig = hConfig;
    	g_srv_dtcnt_dm_cntx.check_status = CCA_STATUS_OK;
    	srv_dtcnt_ota_dm_retrieve_rsp();
        return;
	}	

send_fail_rsp:
    if (hRoot)
	{
		mmi_cca_docroot_release(hRoot);
    }
	g_srv_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
	srv_dtcnt_ota_dm_retrieve_rsp();
	return;        

}

#endif /* SYNCML_DM_SUPPORT */
#endif /* __TCPIP_OVER_CSD__ */

#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_install_gprs_item
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_dtcnt_ota_install_gprs_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_data_struct prof;
    srv_dtcnt_prof_gprs_struct new_gprs_item = {0,};
    srv_dtcnt_result_enum ret;
    srv_dtcnt_prov_install_res_ind_evt_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_GPRS);

    srv_dtcnt_ota_install_common_item_new(&new_gprs_item.prof_common_header, &prof.prof_fields, 0);
    new_gprs_item.APN = (U8*)g_srv_dtcnt_ota_ctx.current_item->address;
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM;

    new_gprs_item.prof_common_header.Auth_info.AuthType = 
        (g_srv_dtcnt_ota_ctx.current_item->AuthType)? SRV_DTCNT_PROF_GPRS_AUTH_TYPE_SECURE : SRV_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL;
    prof.prof_fields |= SRV_DTCNT_PROF_FIELD_AUTH_TYPE;
    
    prof.prof_type = SRV_DTCNT_BEARER_GPRS;
    prof.prof_data = &(new_gprs_item);
    ret = srv_dtcnt_store_add_prof(&prof, &g_srv_dtcnt_ota_ctx.installed_acct_id);    
    if (ret == SRV_DTCNT_RESULT_SUCCESS)
    {
        /* Install successfully. Update counter. */
        g_srv_dtcnt_ota_ctx.num_installed++;
        srv_dtcnt_ota_post_install_res_evt(&evt, 1, SRV_DTCNT_PROF_TYPE_OTA_CONF);
        mmi_cca_oma_add_dataacctid(g_srv_dtcnt_ota_ctx.doc_hdl, (CHAR *)g_srv_dtcnt_ota_ctx.current_item->node_id, g_srv_dtcnt_ota_ctx.installed_acct_id);
    }
    else
    {
        srv_dtcnt_ota_post_install_res_evt(&evt, 0, SRV_DTCNT_PROF_TYPE_OTA_CONF);
    }

    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt); 
}

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_install_sim_gprs_item
 * DESCRIPTION
 *  This function finds and remembers an empty profile. If there is no empty
 *  profile, entry replacement process.
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_dtcnt_ota_install_sim_gprs_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_sim_gprs_account_info_st prof = {0,};
    srv_dtcnt_result_enum ret;
    srv_dtcnt_prov_install_res_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_SIM_GPRS);

    srv_dtcnt_ota_install_sim_common_item_new(&(prof.comm_header)); 
    strcpy((CHAR *) prof.APN, (CHAR *) g_srv_dtcnt_ota_ctx.current_item->address);
    prof.AuthType = (srv_dtcnt_prof_gprs_auth_type_enum)g_srv_dtcnt_ota_ctx.current_item->AuthType;
    prof.comm_header.fields |= (SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM | SRV_DTCNT_PROF_FIELD_AUTH_TYPE);
 
    ret = srv_dtcnt_db_store_add_sim_prof((void *)&prof, SRV_DTCNT_BEARER_GPRS, &g_srv_dtcnt_ota_ctx.installed_acct_id);    
    if (ret == SRV_DTCNT_RESULT_SUCCESS)
    {
        srv_dtcnt_ota_post_install_res_evt(&evt, 1, SRV_DTCNT_PROF_TYPE_SIM_PROF);
        MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
        
        /* Install successfully. */
        mmi_cca_oma_add_dataacctid(g_srv_dtcnt_ota_ctx.doc_hdl, (CHAR *)g_srv_dtcnt_ota_ctx.current_item->node_id, g_srv_dtcnt_ota_ctx.installed_acct_id);
    }
}


#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
#ifdef SYNCML_DM_SUPPORT
/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_gen_gprs_prof_for_cca
* DESCRIPTION
*  Get GPRS Profile Info by ID
* PARAMETERS
* 
* RETURNS
*****************************************************************************/
static void srv_dtcnt_ota_gen_gprs_prof_for_cca(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 hConfig = 0, hRoot = 0, hNode = 0, hProxy = 0;
    U8 temp_uft8_buff[17];
    U8 temp_utf8_name_buff[SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1] = {0,}; 
    U8 temp_proxy_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];
    srv_dtcnt_account_info_st *acc_info = NULL;
    CHAR proxy_port_str[6] = {0,};
    srv_dtcnt_prof_common_header_struct *data;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_DM_GEN_GPRS_PROF, g_srv_dtcnt_dm_cntx.selected_id);
		
	hRoot = mmi_cca_doc_new_rootnode();
	if (!hRoot)
	{
        goto send_fail_rsp;
	}
	
	hNode = mmi_cca_doc_new_node_and_attach(DTCNT_OTA_NAPDEF, hRoot);
	if (!hNode)
	{
        goto send_fail_rsp;
	}
    acc_info = srv_dtcnt_db_store_get_acc_info(g_srv_dtcnt_dm_cntx.selected_id);
    MMI_ASSERT(acc_info && acc_info->bearer_type == SRV_DTCNT_BEARER_GPRS);

    /* Gen NAPDEF information */
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_NODEID, (CHAR *) SRV_DTCNT_DM_GPRS_NODE_ID);

    srv_dtcnt_ota_charset_convert((CHAR *)acc_info->acc_name, 
                              (CHAR *)temp_utf8_name_buff, 
                              (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1),
                              SRV_DTCNT_UCS2_UTF8);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAME, (CHAR *) temp_utf8_name_buff);

	mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_BEARER, CCA_NS_VAL_GSM_GPRS);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_NAP_ADDRESS, (CHAR *) acc_info->dest_name);
    memset((CHAR *) temp_uft8_buff, 0, 17);
    sprintf(
        (char *)temp_uft8_buff,
        "%u.%u.%u.%u",
        acc_info->PrimaryAddr[0],
        acc_info->PrimaryAddr[1],
        acc_info->PrimaryAddr[2],
        acc_info->PrimaryAddr[3]);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_DNS_ADDR, (CHAR *) temp_uft8_buff);
	hNode = mmi_cca_doc_new_node_and_attach(DTCNT_OTA_NAPAUTHINFO, hNode);	
    if (acc_info->auth_info.AuthType == SRV_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL)
    {
		mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_AUTHTYPE, CCA_NS_VAL_CHAP);
    }
    else
    {
		mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_AUTHTYPE, CCA_NS_VAL_PAP);
    }
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_AUTHNAME, (CHAR *) acc_info->auth_info.UserName);
	mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_AUTHSECRET, (CHAR *) acc_info->auth_info.Passwd);

    /* Gen Proxy information */
    hProxy = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PROXY, hRoot);
    if (!hProxy)
    {
        goto send_fail_rsp;
    }

    data = OslMalloc(sizeof(srv_dtcnt_prof_common_header_struct));
    kal_mem_set(data, 0, sizeof(srv_dtcnt_prof_common_header_struct));
    if (srv_dtcnt_db_store_load_prof(acc_info, data) == SRV_DTCNT_RESULT_SUCCESS)
    {
        data->px_service = acc_info->px_service;
    }
    else
    {
        OslMfree(data);
        goto send_fail_rsp;
    }

    mmi_cca_doc_add_nodedata_int(hProxy, CCA_NS_DATAACCTID, (S32)g_srv_dtcnt_dm_cntx.selected_id);
    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_NODEID, (CHAR *)SRV_DTCNT_DM_PROXY_NODE_ID);
    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_PROXY_ID, (CHAR *)SRV_DTCNT_DM_PROXY_NODE_ID);
    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_NAME, (CHAR *) temp_utf8_name_buff);
    switch (g_srv_dtcnt_dm_cntx.prof_id)
    {
        case DM_SETTING_TYPE_DATA_ACCOUNT_HTTP:
        case DM_SETTING_TYPE_DATA_ACCOUNT_WAP:
        case DM_SETTING_TYPE_MMS:
            mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_STARTPAGE, (CHAR *)data->HomePage);
            break;

        default:
            break;
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
    #endif
    memset((U8 *) temp_proxy_addr, 0, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1);
    memcpy(temp_proxy_addr, data->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
    
    mmi_cca_doc_add_nodedata_str(hProxy, CCA_NS_OMA_PXADDR, (CHAR*)temp_proxy_addr);
    
    hNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PXAUTHINFO, hProxy);
    mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PXAUTH_ID, (CHAR*) data->px_authid);
    mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PXAUTH_PW, (CHAR*) data->px_authpw);

    hNode = mmi_cca_doc_new_node_and_attach(CCA_NS_OMA_PORT, hProxy);
    sprintf(proxy_port_str, "%d", data->px_port);
    mmi_cca_doc_add_nodedata_str(hNode, CCA_NS_OMA_PORTNBR, proxy_port_str);    
    mmi_cca_doc_add_nodedata_int(hNode, CCA_NS_OMA_SERVICE, srv_dtcnt_ota_convert_conn_type(data->px_service));
    
    OslMfree(data);			
	hConfig = mmi_cca_doc_new(hRoot);
	if(hConfig)
	{
    	g_srv_dtcnt_dm_cntx.hconfig = hConfig;
    	g_srv_dtcnt_dm_cntx.check_status = CCA_STATUS_OK;
    	srv_dtcnt_ota_dm_retrieve_rsp();
        return;
	}

send_fail_rsp:
	if (hRoot)
	{
			mmi_cca_docroot_release(hRoot);
	}
	g_srv_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
	srv_dtcnt_ota_dm_retrieve_rsp();
	return;		
}

#endif /* SYNCML_DM_SUPPORT */
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_install_sim_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_dtcnt_ota_install_sim_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_sim_type_enum sim_id = SRV_DTCNT_SIM_TYPE_1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_srv_dtcnt_ota_ctx.index_profile = 0;
    
    while(g_srv_dtcnt_ota_ctx.current_item)
    {
        U8 temp_num[2] = {0,};
        CHAR *name = NULL; 

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, 
            SRV_DTCNT_OTA_INSTALL_SIM_PROF, 
            g_srv_dtcnt_ota_ctx.current_item->bearer, 
            #ifdef __TCPIP_OVER_CSD__
            g_srv_dtcnt_ota_sim_acc_ctx.csd_num,
            #else
            0,
            #endif /* __TCPIP_OVER_CSD__ */
            #ifdef __MMI_GPRS_FEATURES__
            g_srv_dtcnt_ota_sim_acc_ctx.gprs_num);
            #else
            0);
            #endif /* __MMI_GPRS_FEATURES__ */

        name = g_srv_dtcnt_ota_ctx.current_item->name;
        mmi_ucs2cpy(name, (CHAR*)DTCNT_STRING_SIM);

        switch (g_srv_dtcnt_ota_ctx.sim_id)
        {
            case MMI_SIM_NONE:
            case MMI_SIM1:
                sim_id = SRV_DTCNT_SIM_TYPE_1;
                break;
            case MMI_SIM2:
                sim_id = SRV_DTCNT_SIM_TYPE_2;
                break;
            case MMI_SIM3:
                sim_id = SRV_DTCNT_SIM_TYPE_3;
                break;
            case MMI_SIM4:
                sim_id = SRV_DTCNT_SIM_TYPE_4;
                break;
            default:
                MMI_ASSERT(0);
        }
        sprintf((CHAR*)temp_num, "%d", sim_id);    
        mmi_ucs2cat(name, (CHAR*)temp_num);
        mmi_ucs2cat(name, (CHAR*)L" ");

#ifdef __TCPIP_OVER_CSD__
        /* csd account and also have empty slot */
        if (g_srv_dtcnt_ota_ctx.current_item->bearer == DATA_ACCOUNT_BEARER_CSD && 
            g_srv_dtcnt_ota_sim_acc_ctx.csd_num < MAX_CSD_SIM_PROV_NUM)
        {
            mmi_ucs2cat(name, (CHAR*)DTCNT_STRING_CSD);
            sprintf((CHAR*)temp_num, "%d", (g_srv_dtcnt_ota_sim_acc_ctx.csd_num + 1));
            mmi_ucs2cat(name, (CHAR*)temp_num);
            srv_dtcnt_ota_install_sim_csd_item();
            g_srv_dtcnt_ota_sim_acc_ctx.csd_num++;
        }
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
        /* gprs account and also have empty slot */
        if (g_srv_dtcnt_ota_ctx.current_item->bearer == DATA_ACCOUNT_BEARER_GPRS &&
                 g_srv_dtcnt_ota_sim_acc_ctx.gprs_num < MAX_GPRS_SIM_PROV_NUM)
        {
            mmi_ucs2cat(name, (CHAR*)DTCNT_STRING_GPRS);
            sprintf((CHAR*)temp_num, "%d", (g_srv_dtcnt_ota_sim_acc_ctx.gprs_num + 1));
            mmi_ucs2cat(name, (CHAR*)temp_num);
            srv_dtcnt_ota_install_sim_gprs_item();
            g_srv_dtcnt_ota_sim_acc_ctx.gprs_num++;
        }
#endif /* __MMI_GPRS_FEATURES__ */

        /* process next SIM profile */
        g_srv_dtcnt_ota_ctx.index_profile++;
        srv_dtcnt_ota_get_next_profile_data();        
    }

    /* Now, terminate the OTAP OTA provisioning application. */
    srv_dtcnt_send_cca_app_configure_rsp(g_srv_dtcnt_ota_ctx.conf_id, g_srv_dtcnt_ota_ctx.doc_hdl, CCA_STATUS_OK);
    srv_dtcnt_ota_terminate();
    return;

}
static void srv_dtcnt_ota_install_sim_common_item_new(srv_dtcnt_sim_comm_account_info_st *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    srv_dtcnt_ota_item_struct *cur_item = g_srv_dtcnt_ota_ctx.current_item;
    U32 i, sum;
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/

    mmi_ucs2ncpy((CHAR *) item->acc_name, (CHAR *)cur_item->name, (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1));    
    strcpy((CHAR *) item->UserName, (CHAR *) cur_item->UserName);
    strcpy((CHAR *) item->Passwd, (CHAR *) cur_item->Passwd);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    memcpy(item->provurl_hash_val, g_srv_dtcnt_ota_ctx.provurl_hash_val, SRV_DTCNT_PROVURL_HASH_LEN);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */    
    memcpy(item->napid_hash_val, cur_item->napid_hash_val, SRV_DTCNT_NAPID_HASH_LEN);
    memcpy(item->PrimaryAddr, cur_item->DnsAddress, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);

    switch (g_srv_dtcnt_ota_ctx.sim_id)
    {
        case MMI_SIM_NONE:
        case MMI_SIM1:
            item->sim_info = SRV_DTCNT_SIM_TYPE_1;
            break;
        case MMI_SIM2:
            item->sim_info = SRV_DTCNT_SIM_TYPE_2;
            break;
        case MMI_SIM3:
            item->sim_info = SRV_DTCNT_SIM_TYPE_3;
            break;
        case MMI_SIM4:
            item->sim_info = SRV_DTCNT_SIM_TYPE_4;
            break;
        default:
            MMI_ASSERT(0);
    }

    item->fields |= (SRV_DTCNT_PROF_FIELD_NAME | 
                     SRV_DTCNT_PROF_FIELD_SIM_TYPE | 
                     SRV_DTCNT_PROF_FIELD_INET_PRI_DNS | 
                     SRV_DTCNT_PROF_FIELD_HASH_VAL|
                     SRV_DTCNT_PROF_FIELD_AUTH_USER_INFO);

    item->px_port = cur_item->px_port;
    item->fields |= SRV_DTCNT_PROF_FIELD_PX_PORT;
    item->px_service = cur_item->px_service;
    item->fields |= SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE;

    memcpy(item->HomePage, cur_item->px_startpage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);
    item->fields |= SRV_DTCNT_PROF_FIELD_HOME;
    
    memcpy(item->px_addr, cur_item->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
    item->fields |= SRV_DTCNT_PROF_FIELD_PX_ADDR;

    item->use_proxy = 0;
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
    item->px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN] = 0;
    if(strlen(item->px_addr) != 0)
    {
        item->use_proxy = 1;
        item->fields |= SRV_DTCNT_PROF_FIELD_USE_PX;
    }

    memcpy(item->px_authid, cur_item->px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
    item->fields |= SRV_DTCNT_PROF_FIELD_PX_AUTH_ID;

    memcpy(item->px_authpw, cur_item->px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
    item->fields |= SRV_DTCNT_PROF_FIELD_PX_AUTH_PW;

    item->app_type |= DTCNT_APPTYPE_MMS;
    item->fields |= SRV_DTCNT_PROF_FIELD_APP_TYPE;
}
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

#ifdef SYNCML_DM_SUPPORT
/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_dm_acc_check
* DESCRIPTION
*  check ProfID & AppId is Valid
* PARAMETERS
*  AppID: app id
*  ProfId: Profile Id
*  bearer: CSD, GPRS, WIFI
* RETURNS
*  Return CCA_STATUS_OK if the document is relevant to VoIP data account; 
*  otherwise, return CCA_STATUS_NOT_FOUND.
*****************************************************************************/
static cca_status_enum srv_dtcnt_ota_dm_acc_check(U16 app_id, U32 prof_id, srv_dtcnt_bearer_enum *bearer)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_qry_struct qry = {0,};
    int i;
    const srv_dtcnt_account_info_st *acc_info = NULL;
    
    //U8 decoded_acc_id;
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(app_id != CCA_APP_DTACCT)
	{
		return CCA_STATUS_FAIL;
	}

    //decoded_acc_id = srv_dtcnt_extract_specified_acc_id(prof_id, SRV_DTCNT_ACCOUNT_PRIMARY);

    qry.qry_info.filters = (SRV_DTCNT_STORE_QRY_TYPE_APP_TYPE | SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE);
    *bearer = qry.qry_info.bearer_qry_info = SRV_DTCNT_BEARER_GPRS;    
    qry.qry_info.app_type = (DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_BRW_HTTP);        

    switch(prof_id)
    {
        case DM_SETTING_TYPE_DATA_ACCOUNT_HTTP:
        case DM_SETTING_TYPE_DATA_ACCOUNT_WAP:
            break;

        case DM_SETTING_TYPE_DATA_ACCOUNT_CSD:
            *bearer = qry.qry_info.bearer_qry_info = SRV_DTCNT_BEARER_CSD;
            break;
            
        case DM_SETTING_TYPE_MMS:
            qry.qry_info.app_type = DTCNT_APPTYPE_MMS;

            break;

#if defined(__OP01__) || defined(__OP02__)
        case DM_SETTING_TYPE_DM_DA:
            qry.qry_info.app_type = DTCNT_APPTYPE_DM;
            break;
#endif

        default:
            ASSERT(0);
    }    

    srv_dtcnt_db_store_ids_qry(&qry);

    if (qry.num_ids)
    {
        U8  dest_name[SRV_DTCNT_PROF_MAX_APN_LEN+1];
        
        if (prof_id == DM_SETTING_TYPE_DATA_ACCOUNT_HTTP)
        {
            for (i = 0; i<qry.num_ids; i++)
            {
                acc_info = srv_dtcnt_db_store_get_acc_info((U8)qry.ids[i]);
                if (acc_info)
                {
                #ifdef __OP01__
                    if ((acc_info->app_type & DTCNT_APPTYPE_BRW_HTTP) && 
                        (acc_info->app_type & DTCNT_APPTYPE_EMAIL))
                #else                
                    kal_mem_cpy(dest_name, acc_info->dest_name, SRV_DTCNT_PROF_MAX_APN_LEN+1);
                    if (strstr(app_strtolower((char *)dest_name), "net"))
                #endif
                    {
                        g_srv_dtcnt_dm_cntx.selected_id = (U8)qry.ids[i];
                        goto found;
                    }
                }
            }
            goto not_found;
        }
        else if (prof_id == DM_SETTING_TYPE_DATA_ACCOUNT_WAP)
        {
            for (i = 0; i<qry.num_ids; i++)
            {
                acc_info = srv_dtcnt_db_store_get_acc_info((U8)qry.ids[i]);
                if (acc_info)
                {
                #ifdef __OP01__
                    if ((acc_info->app_type & DTCNT_APPTYPE_BRW_HTTP) && 
                        !(acc_info->app_type & DTCNT_APPTYPE_EMAIL))
                #else                
                    kal_mem_cpy(dest_name, acc_info->dest_name, SRV_DTCNT_PROF_MAX_APN_LEN+1);
                    if (strstr(app_strtolower((char *)dest_name), "wap"))
                #endif
                    {
                        g_srv_dtcnt_dm_cntx.selected_id = (U8)qry.ids[i];
                        goto found;
                    }
                }
            }
            goto not_found;
        }
        else
        {
            g_srv_dtcnt_dm_cntx.selected_id = (U8)qry.ids[0];
        }
found:        
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_DM_ACC_CHECK, prof_id, g_srv_dtcnt_dm_cntx.selected_id);        
        return CCA_STATUS_OK;
    }

not_found:
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_DM_ACC_CHECK, prof_id, -1);
    return CCA_STATUS_NOT_FOUND;

}

/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_gen_prof_for_cca
* DESCRIPTION
*  Get Profile info by ProfID
* PARAMETERS
*  bearer : CSD, GPRS, WIFI
* RETURNS
*****************************************************************************/
static void srv_dtcnt_ota_gen_prof_for_cca(srv_dtcnt_bearer_enum bearer)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_DM_GEN_PROF, bearer);

	switch(bearer)
    {
#ifdef __TCPIP_OVER_CSD__
	case SRV_DTCNT_BEARER_CSD:
		 srv_dtcnt_ota_gen_csd_prof_for_cca();
	     break;
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
	case SRV_DTCNT_BEARER_GPRS:
		 srv_dtcnt_ota_gen_gprs_prof_for_cca();
		 break;
#endif

#ifdef __MMI_WLAN_FEATURES__
	case SRV_DTCNT_BEARER_WIFI:
		break;
#endif
	default:
		ASSERT(0);
		break;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_get_prof_from_cca
* DESCRIPTION
*  Get profile info by cca hconfig
* PARAMETERS
*  bearer: csd, gprs, wifi
*  hConfig: cca doc handle
* RETURNS
*  Return CCA_STATUS_OK if the document is relevant to VoIP data account; 
*  otherwise, return CCA_STATUS_NOT_FOUND.
*****************************************************************************/
static void srv_dtcnt_ota_get_prof_from_cca(srv_dtcnt_bearer_enum bearer, s32 hconfig)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_DM_GET_PROF, bearer);

	switch(bearer)
    {
	case SRV_DTCNT_BEARER_CSD:
	case SRV_DTCNT_BEARER_GPRS:
		srv_dtcnt_ota_proc_dm_doc(bearer, hconfig);	
		break;
		
#ifdef __MMI_WLAN_FEATURES__
	case SRV_DTCNT_BEARER_WIFI:
        return;
#endif
	default:
		ASSERT(0);
		break;
    }
}

/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_dm_retrieve_rsp
* DESCRIPTION
*  Get Profile rsp
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
static void srv_dtcnt_ota_dm_retrieve_rsp(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_cca_app_get_prof_rsp_struct *myMsgPtr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = OslAllocDataPtr(mmi_cca_app_get_prof_rsp_struct);
	myMsgPtr->app_id = g_srv_dtcnt_dm_cntx.app_id;
    myMsgPtr->prof_id = g_srv_dtcnt_dm_cntx.selected_id;
	
	if(g_srv_dtcnt_dm_cntx.check_status == CCA_STATUS_OK)
	{
		myMsgPtr->result  = CCA_STATUS_OK;
		myMsgPtr->hConfig = g_srv_dtcnt_dm_cntx.hconfig;
	}
	else
	{
		myMsgPtr->result  = CCA_STATUS_FAIL;
		myMsgPtr->hConfig = 0;
	}

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_GET_PROF_RSP, (oslParaType *)myMsgPtr, NULL);
}

/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_dm_update_rsp
* DESCRIPTION
*  update profile rsp
* PARAMETERS

* RETURNS
*****************************************************************************/
static void srv_dtcnt_ota_dm_update_rsp()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_cca_update_prof_rsp_struct *myMsgPtr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = OslAllocDataPtr(mmi_cca_update_prof_rsp_struct);
	myMsgPtr->app_id = g_srv_dtcnt_dm_cntx.app_id;
    myMsgPtr->prof_id = g_srv_dtcnt_dm_cntx.prof_id;
	
	if(g_srv_dtcnt_dm_cntx.check_status == CCA_STATUS_OK)
	{
		myMsgPtr->result  = CCA_STATUS_OK;
		myMsgPtr->hConfig = g_srv_dtcnt_dm_cntx.hconfig;
	}
	else
	{
		myMsgPtr->result  = CCA_STATUS_FAIL;
		myMsgPtr->hConfig = 0;
	}

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP, (oslParaType *)myMsgPtr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_proc_dm_nodes
 * DESCRIPTION
 *  The node callback function used when processing a CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]            Configuration document handle
 *  node_hdl        [IN]            The node handle
 *  symbol          [IN]            The converted node symbol
 *  param_list      [IN]            List of parameters in the node
 *  user_data       [IN]            User data         
 * RETURNS
 *  On success, return OK; otherwise, return FAIL.
 *****************************************************************************/
static cca_status_enum srv_dtcnt_ota_proc_dm_nodes(
                    S32 doc_hdl, 
                    S32 node_hdl, 
                    U16 symbol, 
                    cca_iterator_struct *param_list, 
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *param;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    switch (symbol)
    {
    case DTCNT_OTA_NAPDEF:
        
        status = CCA_STATUS_OK;             /* Initialize the status variable   */

        while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
        {   
            if(status == CCA_STATUS_OK)
            {
                status = srv_dtcnt_ota_proc_cca_param(param, &g_srv_dtcnt_dm_cntx.dm_item_cntx);
				g_srv_dtcnt_dm_cntx.check_status = status;
            }
        }
        return CCA_STATUS_OK;
    
    case DTCNT_OTA_NAPAUTHINFO:

        status = CCA_STATUS_OK;             /* Initialize the status variable   */
        
        while (mmi_cca_doc_nodedata_next(param_list, &param) == CCA_STATUS_OK && status == CCA_STATUS_OK)
        {   
            if(status == CCA_STATUS_OK)
            {
                status = srv_dtcnt_ota_proc_cca_param(param, &g_srv_dtcnt_dm_cntx.dm_item_cntx);
                g_srv_dtcnt_dm_cntx.check_status = status;
            }
        }
        return CCA_STATUS_OK;

    case DTCNT_OTA_PROXY:
        status = srv_dtcnt_ota_dm_proc_cca_proxy_node(param_list);
        break;

    case DTCNT_OTA_PORT:
        status = srv_dtcnt_ota_proc_cca_port_node(1, param_list);
        break;

    case DTCNT_OTA_PROXY_AUTHINFO:
        status = srv_dtcnt_ota_proc_cca_proxy_auth_node(1, param_list);
        break;       
        
    default:
        return CCA_STATUS_OK;
    }
    return status;
}

/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_proc_dm_doc
* DESCRIPTION
*  get gsm profile info 
* PARAMETERS
*  bearer: csd, gprs, wifi
*  hConfig: cca doc handle
* RETURNS
*****************************************************************************/
static void srv_dtcnt_ota_proc_dm_doc(srv_dtcnt_bearer_enum bearer, S32 hconfig)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cca_status_enum status;

    /*
     * Mapping table used to extract the VoIP settings for each profile. All 
     * characteristics are included such that unsupported fields can also be
     * found out.
     */
    const U16 proc_tbl[] = 
    {
        CCA_NS_TRIGNODE, DTCNT_OTA_NAPDEF, DTCNT_OTA_NAPDEF, 0xFFFF,
        CCA_NS_TRIGNODE, DTCNT_OTA_NAPDEF, DTCNT_OTA_NAPAUTHINFO, DTCNT_OTA_NAPAUTHINFO, 0xFFFF,
        CCA_NS_TRIGNODE, DTCNT_OTA_PROXY, DTCNT_OTA_PROXY, 0xFFFF,
        CCA_NS_TRIGNODE, DTCNT_OTA_PROXY, DTCNT_OTA_PORT, DTCNT_OTA_PORT, 0xFFFF,
        CCA_NS_TRIGNODE, DTCNT_OTA_PROXY, DTCNT_OTA_PROXY_AUTHINFO, DTCNT_OTA_PROXY_AUTHINFO, 0xFFFF        
    };

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_PROC_DM_DOC);
	/* Extract data account settings from CCA configuration document, and store 
       settings in the temporary storage. */
    status = mmi_cca_doc_process(
                hconfig, 
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL, 
                srv_dtcnt_ota_proc_dm_nodes, 
                &g_srv_dtcnt_ota_ctx);

	if(status == CCA_STATUS_OK)
	{
		srv_dtcnt_ota_dm_save_prof(bearer);
	}
	else
	{
		g_srv_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
		srv_dtcnt_ota_dm_update_rsp();
	}
}

/*****************************************************************************
* FUNCTION
*  srv_dtcnt_ota_dm_save_prof
* DESCRIPTION
*  save profile info to l4c
* PARAMETERS
*  bearer: csd. gprs
* RETURNS
*****************************************************************************/
static void srv_dtcnt_ota_dm_save_prof(srv_dtcnt_bearer_enum bearer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_data_struct prof_info = {0,};
    srv_dtcnt_prof_gprs_struct *gprs_prof_p = NULL;
    srv_dtcnt_prof_csd_struct *csd_prof_p = NULL;
    srv_dtcnt_ota_item_struct *dm_item = &(g_srv_dtcnt_dm_cntx.dm_item_cntx);    
    srv_dtcnt_account_info_st *acc_info = NULL;
    srv_dtcnt_prof_common_header_struct *comm_header = NULL;
    srv_dtcnt_result_enum ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_DM_SAVE_PROF, bearer, g_srv_dtcnt_dm_cntx.selected_id);
    acc_info = srv_dtcnt_db_store_get_acc_info(g_srv_dtcnt_dm_cntx.selected_id);
    if (!acc_info)
    {
        goto fail_rsp;
    }

    prof_info.prof_type = bearer;
    /* fill in bearer dependent attributes */
#ifdef __TCPIP_OVER_CSD__
    if(bearer == SRV_DTCNT_BEARER_CSD)
    {
        csd_prof_p = OslMalloc(sizeof(srv_dtcnt_prof_csd_struct));
        prof_info.prof_data = csd_prof_p;
        csd_prof_p->DialNumber = (U8 *)dm_item->address;
        csd_prof_p->DialType = (srv_dtcnt_prof_csd_dial_type_enum)dm_item->DialType;
        csd_prof_p->DataRate = (srv_dtcnt_prof_csd_rate_enum)dm_item->DataRate;
        prof_info.prof_fields |= (SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM | SRV_DTCNT_PROF_FIELD_DIAL_TYPE | SRV_DTCNT_PROF_FIELD_DATA_RATE);
        comm_header = &(csd_prof_p->prof_common_header);
    }
#endif /* __TCPIP_OVER_CSD__ */    
#ifdef __MMI_GPRS_FEATURES__
    if(bearer == SRV_DTCNT_BEARER_GPRS)
    {
        gprs_prof_p = OslMalloc(sizeof(srv_dtcnt_prof_gprs_struct));
        prof_info.prof_data = gprs_prof_p;
        gprs_prof_p->APN = (U8 *)dm_item->address;
        gprs_prof_p->prof_common_header.Auth_info.AuthType = (srv_dtcnt_prof_gprs_auth_type_enum)dm_item->AuthType;
        prof_info.prof_fields |= (SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM | SRV_DTCNT_PROF_FIELD_AUTH_TYPE);
        comm_header = &(gprs_prof_p->prof_common_header);
    }
#endif /* __MMI_GPRS_FEATURES__ */

    if (!comm_header)
    {
        if (gprs_prof_p)
            OslMfree(gprs_prof_p);
        if (csd_prof_p)
            OslMfree(csd_prof_p);            
        goto fail_rsp;
    }

    /* fill in general attributes */    
    if (mmi_ucs2cmp((CHAR*)acc_info->acc_name, dm_item->name))
    {
        comm_header->AccountName = (PU8)dm_item->name;
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        memset(comm_header->provurl_hash_val, 0, SRV_DTCNT_PROVURL_HASH_LEN);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
        memcpy(comm_header->napid_hash_val, dm_item->napid_hash_val, SRV_DTCNT_NAPID_HASH_LEN);
        prof_info.prof_fields |= (SRV_DTCNT_PROF_FIELD_NAME | SRV_DTCNT_PROF_FIELD_HASH_VAL);
    }
    
    strcpy((char *) comm_header->Auth_info.UserName, (CHAR *) dm_item->UserName);
    strcpy((char *) comm_header->Auth_info.Passwd, (CHAR *) dm_item->Passwd);
    prof_info.prof_fields |= SRV_DTCNT_PROF_FIELD_AUTH_USER_INFO;

    if (acc_info->acc_type == SRV_DTCNT_PROF_TYPE_USER_CONF)
    {
        comm_header->acct_type = SRV_DTCNT_PROF_TYPE_OTA_CONF;
        prof_info.prof_fields |= SRV_DTCNT_PROF_FIELD_ACC_TYPE;
    }

    memcpy(comm_header->PrimaryAddr, dm_item->DnsAddress, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    prof_info.prof_fields |= SRV_DTCNT_PROF_FIELD_INET_PRI_DNS;

    comm_header->read_only = 1;
    prof_info.prof_fields |= SRV_DTCNT_PROF_FIELD_READONLY;

    /* copy proxy information */
    if (g_srv_dtcnt_dm_cntx.proxy_flag)
    {
        memcpy(comm_header->px_addr, dm_item->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1);
        memcpy(comm_header->px_authid, dm_item->px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
        memcpy(comm_header->px_authpw, dm_item->px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
        comm_header->px_port = dm_item->px_port;
        comm_header->px_service = dm_item->px_service;
        comm_header->use_proxy = 1;
        prof_info.prof_fields |= (SRV_DTCNT_PROF_FIELD_PX_ADDR|
                                  SRV_DTCNT_PROF_FIELD_PX_PORT|  
                                  SRV_DTCNT_PROF_FIELD_PX_AUTH |
                                  SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE |
                                  SRV_DTCNT_PROF_FIELD_USE_PX);
    }
    if (strlen((char *)dm_item->px_startpage))
    {
        memcpy(comm_header->HomePage, dm_item->px_startpage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
        prof_info.prof_fields |= SRV_DTCNT_PROF_FIELD_HOME;
    }
    ret = srv_dtcnt_store_update_prof((U32)g_srv_dtcnt_dm_cntx.selected_id, &prof_info);
    if (gprs_prof_p)
        OslMfree(gprs_prof_p);
    if (csd_prof_p)
        OslMfree(csd_prof_p);
    
	if(ret == SRV_DTCNT_RESULT_SUCCESS)
	{
		g_srv_dtcnt_dm_cntx.check_status = CCA_STATUS_OK; 
	}
	else
	{
fail_rsp:
		g_srv_dtcnt_dm_cntx.check_status = CCA_STATUS_FAIL;
	}
    srv_dtcnt_ota_dm_update_rsp();
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_convert_conn_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conn_type           [IN]        
 *  port_parm           [IN]        
 *  newConfigDoc(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
cca_oma_values_enum srv_dtcnt_ota_convert_conn_type(srv_dtcnt_prof_px_srv_enum px_service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (px_service)
    {            
        case SRV_DTCNT_PROF_PX_SRV_CL_WSP:
            return CCA_NS_VAL_CL_WSP;

        case SRV_DTCNT_PROF_PX_SRV_CO_WSP:
            return CCA_NS_VAL_CO_WSP;

        case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP:
            return CCA_NS_VAL_CL_SEC_WSP;
                
        case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP:
            return CCA_NS_VAL_CO_SEC_WSP;
            
        case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WTA:
            return CCA_NS_VAL_CL_SEC_WTA;
            
        case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WTA:
            return CCA_NS_VAL_CO_SEC_WTA;

        case SRV_DTCNT_PROF_PX_SRV_HTTP:
            return CCA_NS_VAL_OTA_HTTP_TO;

        case SRV_DTCNT_PROF_PX_SRV_HTTP_TLS:
            return CCA_NS_VAL_OTA_HTTP_TLS_TO;
            
        case SRV_DTCNT_PROF_PX_SRV_STARTTLS:
            return CCA_NS_VAL_STARTTLS;
            
        default:
            MMI_ASSERT(0);
            return CCA_NS_VAL_OTA_HTTP_TO;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_dm_proc_cca_proxy_node
 * DESCRIPTION
 *  Handles proxy tag from CCA doc.
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  cca_status_enum
 *****************************************************************************/
static cca_status_enum srv_dtcnt_ota_dm_proc_cca_proxy_node(cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_core_data_struct *data = NULL;
    S32 px_addrtype = -1;
    cca_status_enum result = CCA_STATUS_OK;
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_dtcnt_dm_cntx.port_flag = MMI_FALSE;
    g_srv_dtcnt_dm_cntx.proxy_flag = MMI_FALSE;

    status = mmi_cca_doc_get_nodedata_int_first(iter_datalist, CCA_NS_OMA_PXADDRTYPE, &px_addrtype);
    if (status == CCA_STATUS_NOT_FOUND)
    {
        px_addrtype = CCA_NS_VAL_IPV4;
    }
    else if (px_addrtype != CCA_NS_VAL_IPV4 && px_addrtype != CCA_NS_VAL_ALPHA)
    {
        if (px_addrtype == CCA_NS_VAL__INVALID || px_addrtype == CCA_NS_VAL__EMPTY)
        {
            px_addrtype = CCA_NS_VAL_IPV4;
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_OTA_INTALL_PROXY_ADDRTYPE, px_addrtype);
            return CCA_STATUS_INVALID_SETTING;
        }
    }
    g_srv_dtcnt_dm_cntx.proxy_flag = MMI_TRUE;
    g_srv_dtcnt_dm_cntx.dm_item_cntx.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
    g_srv_dtcnt_dm_cntx.dm_item_cntx.px_port = 80;

    mmi_cca_iterator_restart(iter_datalist);
    while (mmi_cca_doc_nodedata_next(iter_datalist, &data) != CCA_STATUS_ENDLIST)
    {
    	if(data!=NULL)
    	{
            srv_dtcnt_ota_dm_proc_cca_proxy_params(data);
    	}
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_ota_dm_proc_cca_proxy_params
 * DESCRIPTION
 *  Based on the namespace identifier, it fill the proxy list.
 * PARAMETERS
 *  proxy_content       [IN]        
 *  data                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_ota_dm_proc_cca_proxy_params(cca_core_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len_ucs2 = 0;
    U8  tmp_px_name[SRV_DTCNT_PROF_MAX_PX_NAME_LEN+1];
    U8  tmp_px_addr[SRV_DTCNT_PROF_MAX_PX_ADDR_LEN+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (data->id)
    {
        case CCA_NS_OMA_PROXY_ID:
            break;
            
        case CCA_NS_OMA_NAME:
            break;

        case CCA_NS_OMA_PXADDR:
            if (data->values.s[0])
            {
                //strncpy((CHAR*) tmp_px_addr, (CHAR*) data->values.s[0], SRV_DTCNT_PROF_MAX_PX_ADDR_LEN);               
                //srv_dtcnt_ota_convert_cca_proxy_ip_str(tmp_px_addr, g_srv_dtcnt_dm_cntx.dm_item_cntx.px_addr);
                strncpy((CHAR*) g_srv_dtcnt_dm_cntx.dm_item_cntx.px_addr, (CHAR*) data->values.s[0], SRV_DTCNT_PROF_MAX_PX_ADDR_LEN); 
            }
            break;

        case CCA_NS_OMA_STARTPAGE:
            if (data->values.s[0])
            {
                kal_mem_set(g_srv_dtcnt_dm_cntx.dm_item_cntx.px_startpage, 0, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);
                strncpy(
                    (CHAR*) g_srv_dtcnt_dm_cntx.dm_item_cntx.px_startpage,
                    (CHAR*) data->values.s[0],
                    SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);
            }
            break;

        case CCA_NS_OMA_PXAUTH_ID:
            if (data->values.s[0])
            {
                kal_mem_set(g_srv_dtcnt_dm_cntx.dm_item_cntx.px_authid, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
                strncpy(
                    (CHAR*) g_srv_dtcnt_dm_cntx.dm_item_cntx.px_authid,
                    (CHAR*) data->values.s[0],
                    SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN);
            }
            break;

        case CCA_NS_OMA_PXAUTH_PW:
            if (data->values.s[0])
            {
                kal_mem_set(g_srv_dtcnt_dm_cntx.dm_item_cntx.px_authpw, 0, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
                strncpy(
                    (CHAR*) g_srv_dtcnt_dm_cntx.dm_item_cntx.px_authpw,
                    (CHAR*) data->values.s[0],
                    SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN);
            }
            break;
    }
}

#endif /* SYNCML_DM_SUPPORT */
srv_dtcnt_sim_type_enum srv_dtcnt_convert_mmi_sim_to_srv_sim(U8 sim_id)
{
    switch(sim_id)
    {
        case MMI_SIM1:
            return SRV_DTCNT_SIM_TYPE_1;
        case MMI_SIM2:
            return SRV_DTCNT_SIM_TYPE_2;
        case MMI_SIM3:
            return SRV_DTCNT_SIM_TYPE_3;
        case MMI_SIM4:
            return SRV_DTCNT_SIM_TYPE_4;
        default:
            MMI_ASSERT(0);

    }
    return SRV_DTCNT_SIM_TYPE_NONE;
}

#endif /* __CCA_SUPPORT__ */
#endif /* __TCPIP__ */
