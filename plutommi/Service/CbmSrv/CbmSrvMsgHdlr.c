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
 *  CbmSrvMain.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM service main procedures
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#include "MMI_features.h"

#include "CommonScreens.h"
#include "SettingGProts.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "ProtocolEvents.h"

#ifdef __MMI_WLAN_FEATURES__
#include "wndrv_cnst.h"
#include "wndrv_supc_types.h"
#include "supc_abm_msgs.h"
#include "supc_mmi_msgs.h"
#endif /* __MMI_WLAN_FEATURES__ */

#include "DtcntSrvIprot.h"
#include "DtcntSrvGprot.h"
#include "CbmSrvWlanPrefer.h"

#include "mmi2abm_struct.h"
#include "CbmSrvFeature.h"
#include "CbmSrvIntProt.h"
#include "CbmSrvGprot.h"
#include "CbmSrvIprot.h"
#include "cbm_api.h"
#include "abm_api.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "app2cbm_struct.h"
#include "cbm_consts.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_conn_app_trc.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "ModeSwitchSrvGprot.h"

#ifdef __MMI_TETHERING_WIFI__
#include "TetheringSrvGprot.h"
#endif

#if defined(__CBM_BEARER_SWITCH__) && defined(__MMI_WLAN_FEATURES__)
static void srv_cbm_send_bearer_evt_cnf(void *, MMI_BOOL);
#endif

extern srv_cbm_context_struct g_cbm_srv_cxt;


#ifdef __CBM_DISALLOW_NWK_SRV_SUPPRT__

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_send_nwk_srv_req
 * DESCRIPTION
 *  send network service request to ABM
 * PARAMETERS
 *  action  [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cbm_send_nwk_srv_req(
        mmi_abm_nwk_srv_action_enum action,
        mmi_abm_nwk_srv_type_enum type,
        U32 bearer_type[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_nwk_srv_req_struct *req = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_cbm_nwk_srv_cnf_hdlr, MSG_ID_MMI_ABM_NWK_SRV_CNF);

    req = OslAllocDataPtr(mmi_abm_nwk_srv_req_struct);

    req->action = action;
    req->type = type;
    for (i = 0; i < CBM_SIM_ID_TOTAL; i++)
    {
        req->bearer[i] = bearer_type[i];
    }

    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_NWK_SRV_REQ, (oslParaType*)req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbm_nwk_srv_cnf_hdlr
 * DESCRIPTION
 *  handle network service confirm from ABM
 * PARAMETERS
 *  action  [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cbm_nwk_srv_cnf_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_abm_nwk_srv_cnf_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_ABM_NWK_SRV_CNF);
    //rsp = (mmi_abm_nwk_srv_cnf_struct*) info;
}

#endif /* __CBM_DISALLOW_NWK_SRV_SUPPRT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_app_bearer_info_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mes_info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cbm_app_bearer_info_ind_hdlr(void *info) 
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_cbm_bearer_info_ind_struct *bearer_info;
    kal_int8 return_val = 0;
    abm_app_register_info_struct register_info;
    kal_uint8 app_id; 
    srv_cbm_bearer_info_struct post_evt;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer_info = (app_cbm_bearer_info_ind_struct*)info;
	app_id = cbm_get_app_id(bearer_info->account_id);
    
    if (app_id != CBM_INVALID_APP_ID)
    {           
        return_val = abm_get_registered_app_callback_info(
                                   app_id, ABM_APP_BEARER_INFO, &register_info);
       
        if (return_val == CBM_OK && register_info.callback != NULL)
	    {
		    MMI_TRACE(MMI_CONN_TRC_INFO, TRC_SRV_CBM_BEARER_INFO, 
		        0, bearer_info->account_id, bearer_info->state, bearer_info->bearer);
		    /* Send post event to perform the action */
            MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_CBM_BEARER_INFO);
		    post_evt.account_id = bearer_info->account_id;
		    post_evt.state = (srv_cbm_bearer_state_enum)bearer_info->state;
		    post_evt.type = (srv_cbm_bearer_type_enum)bearer_info->bearer;
		    post_evt.error = (srv_cbm_result_error_enum)bearer_info->error;
		    post_evt.error_cause = bearer_info->error_cause;
            
            mmi_frm_post_event((mmi_event_struct *)&post_evt, (mmi_proc_func)register_info.callback, 
                                register_info.data);
	    }
    }

    MMI_TRACE(MMI_CONN_TRC_INFO, TRC_SRV_CBM_BEARER_INFO, 
		        1, bearer_info->account_id, bearer_info->state, bearer_info->bearer);
    return;
#endif /* __TCPIP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbm_bearer_info_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mes_info
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_cbm_bearer_info_ind_hdlr(void *info)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_info_ind_struct *bearer_info = (mmi_abm_bearer_info_ind_struct *)info;
    srv_cbm_bearer_info_struct post_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* this is total bearer status event. Need to broadcast it */
    MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_CBM_BEARER_INFO);
    
    post_evt.account_id = bearer_info->profile_id;

    if (bearer_info->status == CBM_ACTIVATING)
    {
        post_evt.state = SRV_CBM_ACTIVATING;
    }
    else if (bearer_info->status == CBM_ACTIVATED)
    {
        post_evt.state = SRV_CBM_ACTIVATED;
    }
    else if (bearer_info->status == CBM_DEACTIVATING)
    {
        post_evt.state = SRV_CBM_DEACTIVATING;
    }
    else
    {
        post_evt.state = SRV_CBM_DEACTIVATED;
    }
    
    if (bearer_info->bearer_type & CBM_CSD)
    {
        post_evt.type = SRV_CBM_BEARER_CSD;
    }
    else if (bearer_info->bearer_type & CBM_PS)
    {
        post_evt.type = SRV_CBM_BEARER_PS;
    }
    else if (bearer_info->bearer_type & CBM_WIFI)
    {
        post_evt.type = SRV_CBM_BEARER_WIFI;
    }
    else 
    {
        return MMI_FALSE;
    }
    MMI_FRM_CB_EMIT_POST_EVENT(&post_evt);
#endif 	/*__TCPIP__ */

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbm_bearer_event_notify_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mes_info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cbm_bearer_event_notify_ind_hdlr(void *info)
{
#if defined(__CBM_BEARER_SWITCH__) && defined(__MMI_WLAN_FEATURES__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_cbm_bearer_event_notify_ind_struct *evt_info;
    kal_int8 return_val = 0;
    abm_app_register_info_struct register_info;
    kal_uint8 app_id;
    srv_cbm_bearer_event_struct post_evt;
    cbm_bearer_enum bearer = CBM_BEARER_NONE;
    srv_cbm_result_error_enum error;
    MMI_BOOL need_switch = MMI_TRUE;
    srv_cbm_wlan_query_type_enum query_type;
    srv_cbm_app_cntx_struct *app_p;
    kal_int32 wlan_status;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt_info = (app_cbm_bearer_event_notify_ind_struct*)info;
    app_id = cbm_get_app_id(evt_info->account_id);

    if (app_id != CBM_INVALID_APP_ID)
    {
        return_val = abm_get_registered_app_callback_info(
                        app_id,
                        ABM_APP_BEARER_EVENT,
                        &register_info);

        if (return_val == CBM_OK && register_info.callback != NULL)
	    {
            MMI_TRACE(
                MMI_CONN_TRC_INFO,
                TRC_SRV_CBM_BEARER_EVT_INFO,
    		    0,
    		    evt_info->account_id,
    		    evt_info->event,
    		    SRV_CBM_BEARER_WIFI);

            if (evt_info->event & CBM_APP_BEARER_EVT_DISCONNECT)
            {
    		    /* Send post event to perform the action */
    		    //cbm_get_bearer_type(evt_info->account_id, &bearer);

                MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_CBM_BEARER_EVENT);

    		    post_evt.account_id = evt_info->account_id;
    		    post_evt.type = SRV_CBM_BEARER_EVENT_DISCONNECT;
    		    post_evt.ori_bearer_type = SRV_CBM_BEARER_WIFI;
    		    error = (srv_cbm_result_error_enum)mmi_frm_send_event(
                            (mmi_event_struct*)&post_evt,
    		                (mmi_proc_func)register_info.callback,
    		                register_info.data);
    		    if (error != SRV_CBM_OK)
    		    {
    		        /* return reject result to ABM */
                    srv_cbm_send_bearer_evt_cnf(info, MMI_FALSE);
                    need_switch = MMI_FALSE;
    		    }
            }

            if (need_switch && (evt_info->event & CBM_APP_BEARER_EVT_SWITCH))
            {
                /* Set the app info */
                app_p = srv_cbm_get_app_slot(app_id);
                if (!app_p)
                {
                    app_p = srv_cbm_get_app_slot(CBM_INVALID_APP_ID);
                    app_p->app_id = app_id;
                }
                else
                {
                    MMI_TRACE(
                        MMI_CONN_TRC_G6_CBM,
                        TRC_SRV_CBM_APP_ID_SAME,
                        app_p->nw_acct_id,
                        app_p->rel_acct_id,
                        app_p->app_state);
                }

                /* Record the account id */
                app_p->nw_acct_id = evt_info->account_id;
                app_p->app_state = SRV_CBM_APP_STATE_DISCONNECTED;

                wlan_status = abm_get_bearer_available_status(CBM_WIFI, CBM_SIM_ID_SIM1);
                if (wlan_status != CBM_ACTIVATED)
                {
                    /* WLAN is in other status, send event to CBM App to connect the WLAN */
                    query_type = srv_cbm_get_wlan_query_type(MMI_FALSE, SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED);
                    if (query_type != SRV_CBM_WLAN_QUERY_TYPE_NONE)
                    {
                        srv_cbm_send_wlan_query_event(query_type);
                        srv_cbm_set_wlan_query_type(query_type);
                    }
                }

		        /* return accept result to ABM */
                srv_cbm_send_bearer_evt_cnf(info, MMI_TRUE);

                if (wlan_status == CBM_ACTIVATED)
                {
                    srv_cbm_proc_app_disconnected(app_p, SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED, CBM_BEARER_WIFI);
                }
            }
	    }
    }

    MMI_TRACE(
        MMI_CONN_TRC_INFO,
        TRC_SRV_CBM_BEARER_EVT_INFO,
		1,
		evt_info->account_id,
		evt_info->event,
		bearer);
#endif /* defined(__CBM_BEARER_SWITCH__) && defined(__MMI_WLAN_FEATURES__) */
}


#if defined(__CBM_BEARER_SWITCH__) && defined(__MMI_WLAN_FEATURES__)

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_send_bearer_evt_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mes_info  [IN]
 *  result    [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cbm_send_bearer_evt_cnf(void *info, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_cbm_bearer_event_notify_ind_struct *ind;
    app_cbm_bearer_event_notify_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (app_cbm_bearer_event_notify_ind_struct*)info;

    rsp = OslAllocDataPtr(app_cbm_bearer_event_notify_rsp_struct);
    rsp->result = (kal_bool)result;
    rsp->event = ind->event;
    rsp->account_id = ind->account_id;
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_APP_CBM_BEARER_EVENT_NOTIFY_RSP, (oslParaType*)rsp, NULL);
}

#endif /* defined(__CBM_BEARER_SWITCH__) && defined(__MMI_WLAN_FEATURES__) */


/*****************************************************************************
 * FUNCTION
 *  srv_cbm_wifi_connect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mes_info  [IN]
 *  result    [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_cbm_wifi_connect_ind_hdlr(mmi_event_struct *evt)
{
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

    return MMI_RET_OK;
}


void srv_cbm_bearer_init_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_init_ind_struct *ind_p;
    U32 rel_acct_id = CBM_INVALID_NWK_ACCT_ID;
    U32 bearer_type = CBM_BEARER_NONE;
    cbm_result_error_enum cause = CBM_OK;
    kal_uint8 app_id;
    cbm_sim_id_enum sim_id;
    kal_uint32 ori_acct_id;
    kal_int8 retval;
    cbm_app_info_struct app_info;
#ifdef __MMI_WLAN_FEATURES__
    kal_int32 wlan_status;
    srv_cbm_wlan_query_type_enum query_type;
    srv_dtcnt_wlan_state_enum wlan_state;
#endif /* __MMI_WLAN_FEATURES__ */
#if defined(__MMI_WLAN_FEATURES__) || defined(__PS_PDP_SWITCH_SUPPORT__)
    srv_cbm_app_cntx_struct *app_p = NULL;
#endif
#ifdef __PS_PDP_SWITCH_SUPPORT__
    srv_cbm_app_cntx_struct *mms_app_p = NULL;
    S32 mms_ret;
    cbm_sim_id_enum i;
    kal_int32 status;
    mmi_event_struct evt;
#endif /* __PS_PDP_SWITCH_SUPPORT__ */

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (mmi_abm_bearer_init_ind_struct*)info;

    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_BEARER_INIT_IND, ind_p->account_id);

    /* Decode the account id */
    cbm_decode_data_account_id(ind_p->account_id, &sim_id, &app_id, NULL, &ori_acct_id);

    /* If in flight mode, reject this activation directly */
    if (
    #ifdef __MMI_OP01_WIFI__
        !srv_mode_switch_is_network_service_available() ||
    #endif
        srv_mode_switch_is_switching())
    {
        cause = CBM_BEARER_FAIL;

        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_IN_FLIGHT_MODE, ind_p->account_id);
        goto EXIT_HANDLE;
    }

    retval = abm_get_registered_app_name(app_id, &app_info);
    if (retval != CBM_OK)
    {
        cause = srv_cbm_get_real_acct_id((U32)ind_p->account_id, &rel_acct_id, &bearer_type);

        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_GET_REGISTERED_APP_INFO_FAIL, app_id, retval, rel_acct_id);
        goto EXIT_HANDLE;
    }

#ifdef __PS_PDP_SWITCH_SUPPORT__
    if (app_info.app_type & DTCNT_APPTYPE_MMS)
    {
        mms_app_p = srv_cbm_get_mms_app_slot(SRV_CBM_APP_STATE_MMS_STARTUP);
        if (mms_app_p)
        {
            if (sim_id == cbm_get_sim_id(mms_app_p->nw_acct_id))
            {
                app_p = srv_cbm_get_app_slot(app_id);
                MMI_ASSERT(!app_p);
                app_p = srv_cbm_get_app_slot(CBM_INVALID_APP_ID);
                app_p->app_id = app_id;
                app_p->nw_acct_id = ind_p->account_id;
                app_p->app_state = SRV_CBM_APP_STATE_MMS_PENDING;
                return;
            }

            cause = CBM_BEARER_FAIL;
            goto EXIT_HANDLE;
        }

        for (i = CBM_SIM_ID_SIM1; i < CBM_SIM_ID_TOTAL; i++)
        {
            if (i != sim_id)
            {
                status = abm_get_bearer_status_by_app_type(DTCNT_APPTYPE_MMS, CBM_PS, i);
                status &= ~CBM_DEACTIVATED;
                if (status != 0 && status != CBM_DEACTIVATING)
                {
                    cause = CBM_BEARER_FAIL;
                    goto EXIT_HANDLE;
                }
            }
        }

        mms_ret = srv_cbm_activate_mms_pre_proc(sim_id, &cause);
        if (mms_ret == CBM_WOULDBLOCK)
        {
            app_p = srv_cbm_get_app_slot(app_id);
            MMI_ASSERT(!app_p);
            app_p = srv_cbm_get_app_slot(CBM_INVALID_APP_ID);
            app_p->app_id = app_id;
            app_p->nw_acct_id = ind_p->account_id;
            app_p->app_state = SRV_CBM_APP_STATE_MMS_STARTUP;

            MMI_TRACE(
                MMI_CONN_TRC_G6_CBM,
                TRC_SRV_CBM_BEARER_UNAVAILABLE,
                EVT_ID_SRV_CBM_BEARER_UNAVAILABLE);

            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CBM_BEARER_UNAVAILABLE);
            MMI_FRM_CB_EMIT_POST_EVENT(&evt);

            g_cbm_srv_cxt_ptr->notify_bearer_available = MMI_TRUE;
            return;
        }

        if (cause == CBM_OK)
        {
            cause = srv_cbm_get_real_acct_id((U32)ind_p->account_id, &rel_acct_id, &bearer_type);
        }
        goto EXIT_HANDLE;
    }
#endif /* __PS_PDP_SWITCH_SUPPORT__ */

#ifdef __MMI_WLAN_FEATURES__

    /* If App does not support WLAN, send the response directly */
    if (app_info.app_type &
        (DTCNT_APPTYPE_SKIP_WIFI |
         DTCNT_APPTYPE_SPECIFIC_PROFILE |
         DTCNT_APPTYPE_MMS |
         DTCNT_APPTYPE_DM |
         DTCNT_APPTYPE_TETHERING |
         DTCNT_APPTYPE_WIFI_TETHERING|
         DTCNT_APPTYPE_USB_TETHERING |
         DTCNT_APPTYPE_NO_SCR))
    {
        MMI_ASSERT(ori_acct_id != CBM_WIFI_ACCT_ID);

        if (app_info.app_type & DTCNT_APPTYPE_NO_SCR)
        {
            wlan_state = srv_dtcnt_wlan_state();
            wlan_status = abm_get_bearer_available_status(CBM_BEARER_WIFI, CBM_SIM_ID_SIM1);

            if (wlan_state == SRV_DTCNT_WLAN_STATE_CONNECTED &&
                wlan_status == CBM_ACTIVATED)
            {
                bearer_type = CBM_BEARER_WIFI;
                rel_acct_id = cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, CBM_SIM_ID_SIM1, app_id, KAL_FALSE);

                MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_ACTIVATED, rel_acct_id);
                goto EXIT_HANDLE;
            }
        }

        cause = srv_cbm_get_real_acct_id((U32)ind_p->account_id, &rel_acct_id, &bearer_type);

        MMI_TRACE(
            MMI_CONN_TRC_G6_CBM,
            TRC_SRV_CBM_APP_NOT_SUPPORT_WLAN,
            app_info.app_str_id,
            app_info.app_icon_id,
            (U32)app_info.app_type,
            rel_acct_id);
        goto EXIT_HANDLE;
    }

    /* Check if the bearer is selected already (for the WLAN -> PS case) */
    app_p = srv_cbm_get_app_slot(app_id);
    if (app_p && app_p->rel_acct_id != CBM_INVALID_NWK_ACCT_ID)
    {
        if (cbm_get_original_account(app_p->rel_acct_id) != CBM_WIFI_ACCT_ID)
        {
            cause = srv_cbm_get_real_acct_id(app_p->rel_acct_id, &rel_acct_id, &bearer_type);
        }
        else
        {
            cause = srv_cbm_get_real_acct_id((U32)ind_p->account_id, &rel_acct_id, &bearer_type);
        }

        srv_cbm_free_app_slot(app_p);

        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_APP_ACCT_HAD_SELECTED, rel_acct_id);
        goto EXIT_HANDLE;
    }

    /* Check the WLAN state */
    wlan_state = srv_dtcnt_wlan_state();

    /* If the WLAN is turned off or the WIFI_HS is not turned off, send the response directly */
    if (wlan_state == SRV_DTCNT_WLAN_STATE_NULL ||
        wlan_state == SRV_DTCNT_WLAN_STATE_TOTAL
    #ifdef __MMI_TETHERING_WIFI__
        || srv_tethering_is_off(SRV_TETHERING_TYPE_WIFI_HS) == MMI_FALSE
    #endif
        )
    {
        if (srv_cbm_is_wlan_sleep())
        {
            cause = CBM_CANCEL_ACT_BEARER;
        }
        else
        {
            cause = srv_cbm_get_real_acct_id((U32)ind_p->account_id, &rel_acct_id, &bearer_type);
        }

        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_TURN_OFF, wlan_state, rel_acct_id);
        goto EXIT_HANDLE;
    }

    /* Start to query the WLAN status */
    wlan_status = abm_get_bearer_available_status(CBM_BEARER_WIFI, CBM_SIM_ID_SIM1);

    /* If the WLAN is available, send the response directly */
    if (wlan_state == SRV_DTCNT_WLAN_STATE_CONNECTED &&
        wlan_status == CBM_ACTIVATED)
    {
        bearer_type = CBM_BEARER_WIFI;
        rel_acct_id = cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, CBM_SIM_ID_SIM1, app_id, KAL_FALSE);

        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_ACTIVATED, rel_acct_id);
        goto EXIT_HANDLE;
    }

    /* Set the app info */
    //app_p = srv_cbm_get_app_slot(app_id);
    if (!app_p)
    {
        app_p = srv_cbm_get_app_slot(CBM_INVALID_APP_ID);
        app_p->app_id = app_id;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_APP_ID_SAME, app_p->nw_acct_id, app_p->rel_acct_id, app_p->app_state);
    }

    /* Record the account id */
    app_p->nw_acct_id = ind_p->account_id;
    app_p->app_state = SRV_CBM_APP_STATE_STARTUP;

    /* If the WLAN is activating, we should wait its result */
    if (wlan_state == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
        wlan_status == CBM_ACTIVATING)
    {
        rel_acct_id = cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, CBM_SIM_ID_SIM1, app_id, KAL_FALSE);
        app_p->app_state = SRV_CBM_APP_STATE_CONNECTING;

        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_ACTIVATING, rel_acct_id);
        return;
    }

    /* WLAN is in other status, send event to CBM App to connect the WLAN */
    query_type = srv_cbm_get_wlan_query_type(MMI_FALSE, SRV_CBM_WLAN_QUERY_TYPE_STARTUP);
    if (query_type != SRV_CBM_WLAN_QUERY_TYPE_NONE)
    {
        srv_cbm_send_wlan_query_event(query_type);
        srv_cbm_set_wlan_query_type(query_type);
    }
    else
    {
        srv_cbm_send_wlan_query_event(SRV_CBM_WLAN_QUERY_TYPE_REQUERY);
    }
    return;

#else /* __MMI_WLAN_FEATURES__ */

    cause = srv_cbm_get_real_acct_id((U32)ind_p->account_id, &rel_acct_id, &bearer_type);

#endif /* __MMI_WLAN_FEATURES__ */

EXIT_HANDLE:
#ifdef __MMI_WLAN_FEATURES__
    app_p = srv_cbm_get_app_slot(app_id);
    if (app_p)
    {
        srv_cbm_free_app_slot(app_p);
    }
#endif /* __MMI_WLAN_FEATURES__ */

    if (cause == CBM_OK)
    {
    #ifdef __PS_PDP_SWITCH_SUPPORT__
        if (bearer_type != CBM_BEARER_WIFI && mms_app_p)
        {
            app_p = srv_cbm_get_app_slot(CBM_INVALID_APP_ID);
            app_p->app_id = app_id;
            app_p->nw_acct_id = ind_p->account_id;
            app_p->app_state = SRV_CBM_APP_STATE_PENDING_STARTUP;
        }
        else
    #endif /* __PS_PDP_SWITCH_SUPPORT__ */
        {
            srv_cbm_send_bearer_init_rsp(MMI_TRUE, ind_p->account_id, rel_acct_id, bearer_type, cause);
        }
    }
    else
    {
        srv_cbm_send_bearer_init_rsp(MMI_FALSE, ind_p->account_id, rel_acct_id, bearer_type, cause);
    }
}


void srv_cbm_send_bearer_init_rsp(MMI_BOOL result, U32 ori_acct_id, U32 rel_acct_id, U32 bearer_type, S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_init_rsp_struct *rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_p = OslAllocDataPtr(mmi_abm_bearer_init_rsp_struct);
    rsp_p->ori_acct_id = (kal_uint32)ori_acct_id;
    rsp_p->rel_acct_id = cbm_set_app_id((kal_uint32)rel_acct_id, CBM_INVALID_APP_ID);
    rsp_p->result = (kal_bool)result;
    rsp_p->bearer_type = (cbm_bearer_enum)bearer_type;
    rsp_p->cause = (kal_int32)cause;
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_BEARER_INIT_RSP, (oslParaType*)rsp_p, NULL);
}


void srv_cbm_bearer_connect_result_ind_hdlr(void *info)
{
#ifdef __MMI_WLAN_FEATURES__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_connect_result_ind_struct *ind_p;
    srv_cbm_app_cntx_struct *app_p;
    S32 i;
    MMI_BOOL conn_fail = MMI_FALSE;
    srv_cbm_wlan_query_type_enum query_type;
    srv_cbm_wlan_query_type_enum new_query_type = SRV_CBM_WLAN_QUERY_TYPE_NONE;
    srv_dtcnt_wlan_state_enum wlan_state;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (mmi_abm_bearer_connect_result_ind_struct*)info;

    if (ind_p->bearer_type != CBM_BEARER_WIFI)
    {
        return;
    }

    query_type = srv_cbm_get_wlan_query_type(MMI_TRUE, SRV_CBM_WLAN_QUERY_TYPE_NONE);
    if (query_type == SRV_CBM_WLAN_QUERY_TYPE_STARTUP ||
        query_type == SRV_CBM_WLAN_QUERY_TYPE_RECONNECT ||
        query_type == SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED ||
        query_type == SRV_CBM_WLAN_QUERY_TYPE_RESWITCH ||
        query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_QUERY_RUNNING, query_type);
        return;
    }

    wlan_state = srv_dtcnt_wlan_state();
    if (wlan_state == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
        wlan_state == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_IN_OTHER_STATE, wlan_state);
        return;
    }

    if (ind_p->result)
    {
        kal_uint8 app_id[SRV_CBM_MAX_APP_NUM];
        kal_uint32 acct_id[SRV_CBM_MAX_APP_NUM];
        kal_uint32 app_num = SRV_CBM_MAX_APP_NUM;
        //MMI_BOOL is_timer_exist;
        kal_int8 retval;
        abm_app_register_info_struct register_info;
        srv_cbm_bearer_event_struct bearer_evt;

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

        abm_get_switchable_app_id(app_id, acct_id, &app_num);

        for (i = 0; i < app_num; i++)
        {
            retval = abm_get_registered_app_callback_info(app_id[i], ABM_APP_BEARER_EVENT, &register_info);

            MMI_TRACE(
                MMI_CONN_TRC_G6_CBM,
                TRC_SRV_CBM_BEARER_SWITCH_NOTIFY,
                SRV_CBM_BEARER_EVENT_SWITCH,
                acct_id[i],
                SRV_CBM_BEARER_SWITCH_PS_TO_WIFI,
                MMI_TRUE,
                retval,
                (U32)register_info.callback);

            if (retval == CBM_OK && register_info.callback)
            {
                MMI_FRM_INIT_EVENT(&bearer_evt, EVT_ID_SRV_CBM_BEARER_EVENT);

                bearer_evt.type = SRV_CBM_BEARER_EVENT_SWITCH;
                bearer_evt.account_id = acct_id[i];
                cbm_get_bearer_type(acct_id[i], (cbm_bearer_enum*)&bearer_evt.ori_bearer_type);
                bearer_evt.switch_type = SRV_CBM_BEARER_SWITCH_PS_TO_WIFI;
                bearer_evt.user_result = MMI_TRUE;

                mmi_frm_send_event(
                    (mmi_event_struct*)&bearer_evt,
                    (mmi_proc_func)register_info.callback,
                    register_info.data);
            }
        }
    }

    for (i = 0; i < ABM_MAX_APP_NUM; i++)
    {
        app_p = &g_cbm_srv_cxt_ptr->app[i];

        if (app_p->app_id != CBM_INVALID_APP_ID &&
            (app_p->app_state == SRV_CBM_APP_STATE_CONNECTING ||
             app_p->app_state == SRV_CBM_APP_STATE_SWITCHING))
        {
            if (ind_p->result)
            {
                if (app_p->app_state == SRV_CBM_APP_STATE_CONNECTING)
                {
                    srv_cbm_proc_app_startup(app_p, SRV_CBM_WLAN_QUERY_TYPE_STARTUP, CBM_BEARER_WIFI);
                }
                else
                {
                    srv_cbm_proc_app_disconnected(app_p, SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED, CBM_BEARER_WIFI);
                }
            }
            else
            {
                if (app_p->app_state == SRV_CBM_APP_STATE_CONNECTING)
                {
                    app_p->app_state = SRV_CBM_APP_STATE_CONNECT_FAIL;
                    new_query_type = SRV_CBM_WLAN_QUERY_TYPE_RECONNECT;
                }
                else
                {
                    app_p->app_state = SRV_CBM_APP_STATE_SWITCH_FAIL;
                    new_query_type = SRV_CBM_WLAN_QUERY_TYPE_RESWITCH;
                }
                conn_fail = MMI_TRUE;
            }
        }
    }

    if (conn_fail)
    {
        query_type = srv_cbm_get_wlan_query_type(MMI_FALSE, new_query_type);

        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_CONNECT_FAIL, query_type);

        if (query_type != SRV_CBM_WLAN_QUERY_TYPE_NONE)
        {
            srv_cbm_send_wlan_query_event(query_type);
            srv_cbm_set_wlan_query_type(query_type);
        }
    }
#endif /* __MMI_WLAN_FEATURES__ */
}


void srv_cbm_bearer_deinit_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_deinit_ind_struct *ind_p;
    kal_uint8 app_id;
    srv_cbm_app_cntx_struct *app_p;
#if 0
/* under construction !*/
/* under construction !*/
#endif

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (mmi_abm_bearer_deinit_ind_struct*)info;

    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_BEARER_DEINIT_IND, ind_p->account_id);

#ifdef __MMI_WLAN_FEATURES__
    if (ind_p->cause == MMI_ABM_DEINIT_CAUSE_WLAN_POWER_SAVE)
    {
        mmi_event_struct wlan_unused_evt;

        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_IS_UNUSED, EVT_ID_SRV_CBM_WLAN_UNUSED);

        MMI_FRM_INIT_EVENT(&wlan_unused_evt, EVT_ID_SRV_CBM_WLAN_UNUSED);
        MMI_FRM_CB_EMIT_POST_EVENT(&wlan_unused_evt);
        return;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    app_id = cbm_get_app_id(ind_p->account_id);
    app_p = srv_cbm_get_app_slot(app_id);
    if (!app_p)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_APP_NOT_RECORDED, app_id);
        return;
    }

    if (app_p->nw_acct_id != ind_p->account_id)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_ACCT_NOT_MATCHED, app_p->nw_acct_id, ind_p->account_id);
    }

#ifdef __PS_PDP_SWITCH_SUPPORT__
    if (app_p->app_state == SRV_CBM_APP_STATE_MMS_STARTUP)
    {
        srv_cbm_app_cntx_struct *mms_app_p;

        mms_app_p = srv_cbm_get_mms_app_slot(SRV_CBM_APP_STATE_MMS_PENDING);
        if (mms_app_p)
        {
            mms_app_p->app_state = SRV_CBM_APP_STATE_MMS_STARTUP;
        }
        else
        {
            srv_cbm_proc_pending_app(SRV_CBM_APP_STATE_PENDING_STARTUP, CBM_OK);
        }
    }
#endif /* __PS_PDP_SWITCH_SUPPORT__ */

    srv_cbm_free_app_slot(app_p);

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
#endif
}


void srv_cbm_send_bearer_deinit_rsp(U32 nw_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_deinit_rsp_struct *rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_p = OslAllocDataPtr(mmi_abm_bearer_deinit_rsp_struct);
    rsp_p->account_id = nw_acct_id;
    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_BEARER_DEINIT_RSP, (oslParaType*)rsp_p, NULL);
}


void srv_cbm_send_bearer_evt_connect_req(U32 user_result, U32 event, U32 ori_acct_id, U32 sel_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_event_connect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmi_abm_bearer_event_connect_req_struct*)
          OslConstructDataPtr(sizeof(mmi_abm_bearer_event_connect_req_struct));
	req->user_result = (mmi_abm_bearer_event_result_enum)user_result;
	req->event = (mmi_abm_bearer_event_enum)event;
	req->ori_acct_id = (kal_uint32)ori_acct_id;
	req->sel_acct_id = cbm_set_app_id((kal_uint32)sel_acct_id, CBM_INVALID_APP_ID);
    mmi_frm_send_ilm(
        MOD_ABM,
        MSG_ID_MMI_ABM_BEARER_EVENT_CONNECT_REQ,
        (oslParaType*)req,
        NULL);
}

#ifdef __PS_PDP_SWITCH_SUPPORT__

void srv_cbm_send_bearer_disconnect_req(cbm_sim_id_enum sim_id, U32 bearer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_disconnect_req_struct *disc_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    disc_req = OslAllocDataPtr(mmi_abm_bearer_disconnect_req_struct);

    disc_req->bearer = bearer;
    disc_req->sim_id = sim_id;

    mmi_frm_send_ilm(MOD_ABM, MSG_ID_MMI_ABM_BEARER_DISCONNECT_REQ, (oslParaType*)disc_req, NULL);
}


void srv_cbm_bearer_disconnect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_disconnect_cnf_struct *disc_cnf;
    srv_cbm_app_cntx_struct *app_p;
    cbm_result_error_enum cause = CBM_OK;
    U32 ori_acct_id;
    U32 rel_acct_id;
    U32 bearer_type;
    S32 ret;
    S32 err_cause = CBM_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_p = srv_cbm_get_mms_app_slot(SRV_CBM_APP_STATE_MMS_STARTUP);
    if (!app_p)
    {
        app_p = srv_cbm_get_mms_app_slot(SRV_CBM_APP_STATE_MMS_PENDING);
        if (app_p)
        {
            app_p->app_state = SRV_CBM_APP_STATE_MMS_STARTUP;
        }
        else
        {
            srv_cbm_proc_pending_app(SRV_CBM_APP_STATE_PENDING_STARTUP, CBM_OK);
            return;
        }
    }

    disc_cnf = (mmi_abm_bearer_disconnect_cnf_struct*)msg;

    if (disc_cnf->result == KAL_TRUE)
    {
        ret = srv_cbm_activate_mms_pre_proc(
                cbm_get_sim_id(app_p->nw_acct_id),
                &cause);
        if (ret == CBM_WOULDBLOCK)
        {
            return;
        }
    }
    else
    {
        cause = CBM_BEARER_FAIL;
        err_cause = CBM_BEARER_FAIL;
    }

    ori_acct_id = app_p->nw_acct_id;
    srv_cbm_free_app_slot(app_p);

    if (cause == CBM_OK)
    {
        cause = srv_cbm_get_real_acct_id(ori_acct_id, &rel_acct_id, &bearer_type);
    }

    if (cause == CBM_OK)
    {
        srv_cbm_send_bearer_init_rsp(MMI_TRUE, ori_acct_id, rel_acct_id, bearer_type, cause);
    }
    else
    {
        srv_cbm_send_bearer_init_rsp(MMI_FALSE, ori_acct_id, rel_acct_id, bearer_type, cause);
    }

    srv_cbm_proc_pending_app(SRV_CBM_APP_STATE_MMS_PENDING, err_cause);
    srv_cbm_proc_pending_app(SRV_CBM_APP_STATE_PENDING_STARTUP, err_cause);
}


void srv_cbm_bearer_status_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_status_ind_struct *ind_p = (mmi_abm_bearer_status_ind_struct*)msg;
    kal_int32 status;
    cbm_sim_id_enum i;
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind_p->bearer & CBM_BEARER_PS)
    {
        status = abm_get_bearer_status_by_app_type(DTCNT_APPTYPE_MMS, CBM_PS, CBM_SIM_ID_TOTAL);

        MMI_TRACE(
            MMI_CONN_TRC_G6_CBM,
            TRC_SRV_CBM_BEARER_STATUS_IND,
            g_cbm_srv_cxt_ptr->notify_bearer_available,
            status);

        if (g_cbm_srv_cxt_ptr->notify_bearer_available &&
            status == CBM_DEACTIVATED)
        {
            for (i = CBM_SIM_ID_SIM1; i < CBM_SIM_ID_TOTAL; i++)
            {
                ret = abm_is_bearer_detached(CBM_PS, i);
                if (!ret)
                {
                    break;
                }
            }

            MMI_TRACE(
                MMI_CONN_TRC_G6_CBM,
                TRC_SRV_CBM_BEARER_STATUS_CHECK,
                i,
                EVT_ID_SRV_CBM_BEARER_AVAILABLE);

            if (i == CBM_SIM_ID_TOTAL)
            {
                mmi_event_struct evt;

                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CBM_BEARER_AVAILABLE);
                MMI_FRM_CB_EMIT_POST_EVENT(&evt);
            }

            g_cbm_srv_cxt_ptr->notify_bearer_available = MMI_FALSE;
        }
    }
}

#endif /* __PS_PDP_SWITCH_SUPPORT__ */

