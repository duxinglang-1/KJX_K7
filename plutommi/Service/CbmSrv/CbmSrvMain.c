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
 *  CBM service main procedures
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

#ifdef __DM_LAWMO_SUPPORT__
#include "mmiapi_dm_struct.h"
#include "dmuigprot.h"
#endif
#include "mmi2abm_struct.h"
#include "CbmSrvFeature.h"
#include "CbmSrvGprot.h"
#include "CbmSrvIntProt.h"
#include "CbmSrvWlanPrefer.h"
#include "cbm_api.h"

#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_release.h"
#include "kal_trace.h"
#include "mmi_conn_app_trc.h"
#include "MMI_conn_app_trc.h"
#include "string.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"

#include "DtcntSrvIprot.h"
#include "DtcntSrvGprot.h"
#include "ModeSwitchSrvGprot.h"

#ifdef CBM_UT_TEST
#include "tst_def.h"
#endif

srv_cbm_context_struct g_cbm_srv_cxt;
srv_cbm_context_struct *const g_cbm_srv_cxt_ptr = &g_cbm_srv_cxt;

#ifdef CBM_UT_TEST
static U8 srv_cbm_process_tst_inject_str(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tst_inject_string_struct *tst_p = (tst_inject_string_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_TST_INJECT_STRING, tst_p->index);

    if (!strcmp((CHAR*)tst_p->string, "set timeout"))
    {
        srv_cbm_set_wlan_prefer_delay_timeout(tst_p->index);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif /* CBM_UT_TEST */

#ifdef __CBM_DISALLOW_NWK_SRV_SUPPRT__

/*****************************************************************************
 * FUNCTION
 *  always_ask_register_app_chain_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
BOOL srv_cbm_create_sem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cbm_srv_cxt_ptr->nwk_srv.wait_event = kal_create_event_group("cbm_wait_events");

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbm_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cbm_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 retrieved_events;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_retrieve_eg_events(g_cbm_srv_cxt_ptr->nwk_srv.wait_event, 
        CBM_NWK_DISALLOW_EVENT, KAL_OR_CONSUME, 
        &retrieved_events, KAL_SUSPEND);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbm_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cbm_unlock(kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, TRC_SRV_CBM_ALLOW_SET_EVENT_RESULT, result);
    g_cbm_srv_cxt_ptr->nwk_srv.result = result;
    
    kal_set_eg_events(g_cbm_srv_cxt_ptr->nwk_srv.wait_event, 
                      CBM_NWK_DISALLOW_EVENT, KAL_OR);
    return;
}

#endif /* __CBM_DISALLOW_NWK_SRV_SUPPRT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cbm_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_cbm_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_cbm_srv_cxt, 0, sizeof(g_cbm_srv_cxt));

#ifdef __CBM_DISALLOW_NWK_SRV_SUPPRT__
    srv_cbm_create_sem();
#endif /* __CBM_DISALLOW_NWK_SRV_SUPPRT__ */

    SetProtocolEventHandler(srv_cbm_app_bearer_info_ind_hdlr, MSG_ID_APP_CBM_BEARER_INFO_IND);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_ABM_BEARER_INFO_IND,
        (PsIntFuncPtr)srv_cbm_bearer_info_ind_hdlr,
        MMI_TRUE);

    SetProtocolEventHandler(srv_cbm_bearer_event_notify_ind_hdlr, MSG_ID_APP_CBM_BEARER_EVENT_NOTIFY_IND);

    SetProtocolEventHandler(srv_cbm_bearer_init_ind_hdlr, MSG_ID_MMI_ABM_BEARER_INIT_IND);
    SetProtocolEventHandler(srv_cbm_bearer_deinit_ind_hdlr, MSG_ID_MMI_ABM_BEARER_DEINIT_IND);
    SetProtocolEventHandler(srv_cbm_bearer_connect_result_ind_hdlr, MSG_ID_MMI_ABM_BEARER_CONNECT_RESULT_IND);

#ifdef __PS_PDP_SWITCH_SUPPORT__
    SetProtocolEventHandler(srv_cbm_bearer_disconnect_cnf_hdlr, MSG_ID_MMI_ABM_BEARER_DISCONNECT_CNF);
    SetProtocolEventHandler(srv_cbm_bearer_status_ind_hdlr, MSG_ID_MMI_ABM_BEARER_STATUS_IND);
#endif /* __PS_PDP_SWITCH_SUPPORT__ */

#ifdef __MMI_WLAN_FEATURES__
    srv_cbm_start_wlan_auto_search_timer();
#endif

#ifdef CBM_UT_TEST
    mmi_frm_set_protocol_event_handler(
        MSG_ID_TST_INJECT_STRING,
        (PsIntFuncPtr)srv_cbm_process_tst_inject_str,
        MMI_TRUE);
#endif /* CBM_UT_TEST */

    return MMI_RET_OK;
}


#ifdef __CBM_DISALLOW_NWK_SRV_SUPPRT__

srv_cbm_nwk_app_struct *srv_cbm_get_app_index(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_nwk_app_struct *app_p = g_cbm_srv_cxt_ptr->nwk_srv.app_list;
    S32 i = 0;
    S32 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CBM_MAX_APP_NUM; i++)
    {
        if (app_id == CBM_INVALID_APP_ID)
        {
            if (!app_p[i].is_valid)
            {
                app_p[i].app_id = CBM_INVALID_APP_ID;
                for (j = 0; j < CBM_SIM_ID_TOTAL; j++)
                {
                    app_p[i].disallowed_bearer[j] = SRV_CBM_BEARER_INVALID;
                }
                return &app_p[i];
            }
        }
        else
        {
            if (app_p[i].is_valid && app_p[i].app_id == app_id)
            {
                return &app_p[i];
            }
        }
    }

    //MMI_ASSERT(0);
    return NULL;
}


U32 srv_cbm_merge_bearer(
        mmi_abm_nwk_srv_action_enum action,
        srv_cbm_nwk_app_struct *app_p,
        cbm_sim_id_enum sim_id,
        U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_nwk_app_struct *ptr = NULL;
    U32 bearer = SRV_CBM_BEARER_INVALID;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (action)
    {
        case MMI_ABM_NWK_SRV_ACTION_DISALLOW:
            bearer = type & (type ^ g_cbm_srv_cxt_ptr->nwk_srv.disallowed_bearer[sim_id]);
            break;

        case MMI_ABM_NWK_SRV_ACTION_ALLOW:
            bearer = type & g_cbm_srv_cxt_ptr->nwk_srv.disallowed_bearer[sim_id];

            for (i = 0; i < SRV_CBM_MAX_APP_NUM; i++)
            {
                ptr = &g_cbm_srv_cxt_ptr->nwk_srv.app_list[i];
                if (ptr != app_p && ptr->is_valid)
                {
                    bearer &= ~ptr->disallowed_bearer[sim_id];

                    if ((bearer & SRV_CBM_BEARER_WIFI) &&
                        (ptr->disallowed_bearer[0] & SRV_CBM_BEARER_WIFI))
                    {
                        bearer &= ~SRV_CBM_BEARER_WIFI;
                    }
                }
            }
            break;

        default:
            break;
    }

    return bearer;
}


void srv_cbm_disallow_bearer(srv_cbm_nwk_app_struct *app_p, cbm_sim_id_enum sim_id, U32 type, U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 num = srv_cbm_get_sim_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id < CBM_SIM_ID_TOTAL)
    {
        app_p->disallowed_bearer[sim_id] |= type;
        if (type & SRV_CBM_BEARER_WIFI)
        {
            srv_cbm_mark_common_bearer(app_p->disallowed_bearer, SRV_CBM_BEARER_WIFI);
        }
    }
    else
    {
        for (i = 0; i < num; i++)
        {
            app_p->disallowed_bearer[i] |= type;
        }
    }

    if (!app_p->is_valid)
    {
        app_p->is_valid = MMI_TRUE;
        app_p->app_id = app_id;
    }
}


void srv_cbm_allow_bearer(srv_cbm_nwk_app_struct *app_p, cbm_sim_id_enum sim_id, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 num = srv_cbm_get_sim_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id < CBM_SIM_ID_TOTAL)
    {
        app_p->disallowed_bearer[sim_id] &= ~type;
        if (type & SRV_CBM_BEARER_WIFI)
        {
            srv_cbm_unmark_common_bearer(app_p->disallowed_bearer, SRV_CBM_BEARER_WIFI);
        }
    }
    else
    {
        for (i = 0; i < num; i++)
        {
            app_p->disallowed_bearer[i] &= ~type;
        }
    }

    for (i = 0; i < num; i++)
    {
        if (app_p->disallowed_bearer[i] != SRV_CBM_BEARER_INVALID)
        {
            break;
        }
    }

    if (i == num)
    {
        app_p->is_valid = MMI_FALSE;
        app_p->app_id = CBM_INVALID_APP_ID;
    }
}


S32 srv_cbm_get_sim_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
#ifdef GEMINI_PLUS
    return GEMINI_PLUS;
#else /* GEMINI_PLUS */
    return 2;
#endif /* GEMINI_PLUS */
#else /* __GEMINI__ */
    return 1;
#endif /* __GEMINI__ */
}


void srv_cbm_mark_common_bearer(U32 bearer_type[], U32 common_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 num = srv_cbm_get_sim_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num; i++)
    {
        bearer_type[i] |= common_type;
    }
}


void srv_cbm_unmark_common_bearer(U32 bearer_type[], U32 common_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 num = srv_cbm_get_sim_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num; i++)
    {
        bearer_type[i] &= ~common_type;
    }
}

#endif /* __CBM_DISALLOW_NWK_SRV_SUPPRT__ */


srv_cbm_app_cntx_struct *srv_cbm_get_app_slot(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_app_cntx_struct *app_p = g_cbm_srv_cxt_ptr->app;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CBM_MAX_APP_NUM; i++)
    {
        if (app_p[i].app_id == app_id)
        {
            if (app_id == CBM_INVALID_APP_ID)
            {
                app_p[i].nw_acct_id = CBM_INVALID_NWK_ACCT_ID;
                app_p[i].rel_acct_id = CBM_INVALID_NWK_ACCT_ID;
            }
            MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_GET_APP_SLOT_SUCC, app_id, i);
            return &app_p[i];
        }
    }

    MMI_ASSERT(app_id != CBM_INVALID_APP_ID);
    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_GET_APP_SLOT_FAIL, app_id);
    return NULL;
}


void srv_cbm_free_app_slot(srv_cbm_app_cntx_struct *app_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_FREE_APP_SLOT, app_p->app_id, app_p->nw_acct_id);
    memset(app_p, 0, sizeof(srv_cbm_app_cntx_struct));
}


cbm_result_error_enum srv_cbm_get_real_acct_id(U32 nw_acct_id, U32 *rel_acct_id, U32 *bearer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 app_id;
    cbm_sim_id_enum sim_id;
    kal_uint32 ori_acct_id;
    cbm_result_error_enum cbm_errcode = CBM_OK;
    srv_dtcnt_result_enum da_ret;
    kal_int8 ret;
    cbm_bearer_enum ori_bearer_type = CBM_BEARER_NONE;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbm_decode_data_account_id((kal_uint32)nw_acct_id, &sim_id, &app_id, NULL, &ori_acct_id);

    switch (ori_acct_id)
    {
        case CBM_DEFAULT_ACCT_ID:
            da_ret = srv_dtcnt_get_auto_acc_id(nw_acct_id, &ori_acct_id);
            if (da_ret == SRV_DTCNT_RESULT_SUCCESS &&
                cbm_get_original_account(ori_acct_id) != CBM_DEFAULT_ACCT_ID)
            {
                ori_acct_id = cbm_set_app_id(ori_acct_id, CBM_INVALID_APP_ID);
            }
            else
            {
                ori_acct_id = CBM_INVALID_NWK_ACCT_ID;
                cbm_errcode = CBM_INVALID_ACCT_ID;
            }
            break;

        default:
            break;
    }

    if (cbm_errcode == CBM_OK)
    {
        ret = cbm_get_bearer_type(ori_acct_id, &ori_bearer_type);
        if (ret != CBM_OK ||
            ori_bearer_type == CBM_BEARER_NONE
        #ifndef __MMI_OP01_WIFI__
            || (ori_bearer_type != CBM_BEARER_WIFI &&
                !srv_mode_switch_is_network_service_available())
        #endif /* __MMI_OP01_WIFI__ */
            )
        {
            cbm_errcode = CBM_INVALID_ACCT_ID;
        }

    #ifdef __PS_PDP_SWITCH_SUPPORT__
        if (cbm_errcode == CBM_OK)
        {
            srv_cbm_app_cntx_struct *mms_app_p =
                srv_cbm_get_mms_app_slot(SRV_CBM_APP_STATE_MMS_STARTUP);

            if (!mms_app_p)
            {
                mms_app_p = srv_cbm_get_mms_app_slot(SRV_CBM_APP_STATE_MMS_PENDING);
            }

            if (mms_app_p)
            {
                if (sim_id != cbm_get_sim_id(mms_app_p->nw_acct_id))
                {
                    cbm_errcode = CBM_BEARER_FAIL;
                }
            }
        }
    #endif /* __PS_PDP_SWITCH_SUPPORT__ */
    }

    if (rel_acct_id)
    {
        *rel_acct_id = cbm_encode_data_account_id(ori_acct_id, sim_id, app_id, KAL_FALSE);
    }
    if (bearer_type)
    {
        *bearer_type = ori_bearer_type;
    }

    return cbm_errcode;
}


srv_cbm_result_error_enum srv_cbm_get_real_account(U32 nw_acct_id, U32 *rel_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_app_cntx_struct *app_p = g_cbm_srv_cxt_ptr->app;
    S32 i = 0;
    kal_int8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CBM_MAX_APP_NUM; i++)
    {
        if (app_p[i].nw_acct_id == nw_acct_id)
        {
            break;
        }
    }

    if (i < SRV_CBM_MAX_APP_NUM)
    {
        if (app_p[i].rel_acct_id != CBM_INVALID_NWK_ACCT_ID)
        {
            *rel_acct_id = app_p[i].rel_acct_id;
            return SRV_CBM_OK;
        }
    }

    ret = cbm_get_real_account(nw_acct_id, rel_acct_id);
    if (ret == CBM_OK)
    {
        return SRV_CBM_OK;
    }
    else
    {
        return SRV_CBM_ERROR;
    }
}

#ifdef __PS_PDP_SWITCH_SUPPORT__

static cbm_sim_id_enum srv_cbm_get_active_sim_id(cbm_sim_id_enum mms_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_bearer_status_query_struct query_info;
    cbm_sim_id_enum i;
    kal_int32 ps_status;
    kal_bool is_ps_detached;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query_info, 0, sizeof(cbm_bearer_status_query_struct));
    query_info.by_sim_id = KAL_TRUE;
    query_info.by_bearer = KAL_TRUE;
    query_info.bearer = CBM_BEARER_PS;

    for (i = CBM_SIM_ID_SIM1; i < CBM_SIM_ID_TOTAL; i++)
    {
        if (i != mms_sim_id)
        {
            query_info.sim = i;
            ps_status = cbm_get_bearer_status_ext(&query_info);
            if (ps_status != CBM_DEACTIVATED)
            {
                break;
            }
            else
            {
                is_ps_detached = abm_is_bearer_detached(CBM_BEARER_PS, i);
                if (!is_ps_detached)
                {
                    break;
                }
            }
        }
    }

    return i;
}


srv_cbm_app_cntx_struct *srv_cbm_get_mms_app_slot(srv_cbm_app_state_enum app_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_app_cntx_struct *app_p = g_cbm_srv_cxt_ptr->app;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CBM_MAX_APP_NUM; i++)
    {
        if (app_p[i].app_id != CBM_INVALID_APP_ID &&
            app_p[i].app_state == app_state)
        {
            return &app_p[i];
        }
    }

    return NULL;
}


S32 srv_cbm_activate_mms_pre_proc(cbm_sim_id_enum mms_sim_id, cbm_result_error_enum *cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mode_switch_is_network_service_available() ||
        srv_mode_switch_is_switching())
    {
        *cause = CBM_BEARER_FAIL;
        return CBM_ERROR;
    }

    *cause = CBM_OK;

    sim_id = srv_cbm_get_active_sim_id(mms_sim_id);
    if (sim_id < CBM_SIM_ID_TOTAL)
    {
        srv_cbm_send_bearer_disconnect_req(sim_id, CBM_BEARER_PS);
        return CBM_WOULDBLOCK;
    }
    else
    {
        return CBM_OK;
    }
}


void srv_cbm_proc_pending_app(srv_cbm_app_state_enum app_state, S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_app_cntx_struct *app_p = g_cbm_srv_cxt_ptr->app;
    S32 i = 0;
    U32 nw_acct_id;
    U32 rel_acct_id = CBM_INVALID_NWK_ACCT_ID;
    U32 bearer_type = CBM_BEARER_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CBM_MAX_APP_NUM; i++)
    {
        app_p = &g_cbm_srv_cxt_ptr->app[i];

        if (app_p->app_id != CBM_INVALID_APP_ID &&
            app_p->app_state == app_state)
        {
            nw_acct_id = app_p->nw_acct_id;
            srv_cbm_free_app_slot(app_p);

            if (cause == CBM_OK)
            {
                cause = srv_cbm_get_real_acct_id(nw_acct_id, &rel_acct_id, &bearer_type);
            }

            if (cause == CBM_OK)
            {
                srv_cbm_send_bearer_init_rsp(MMI_TRUE, nw_acct_id, rel_acct_id, bearer_type, cause);
            }
            else
            {
                srv_cbm_send_bearer_init_rsp(MMI_FALSE, nw_acct_id, rel_acct_id, bearer_type, cause);
            }
        }
    }
}

#endif /* __PS_PDP_SWITCH_SUPPORT__ */

