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
 *  CbmSrvWlanPrefer.c
 *
 * Project:
 * --------
 *  CBM Service WLAN Prefer
 *
 * Description:
 * ------------
 *  
 *
 * Author:
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "MMI_include.h"

#ifdef __MMI_WLAN_FEATURES__

#include "kal_public_defs.h"

#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_timer_gprot.h"

#include "custom_data_account.h"
#include "DtcntSrvIprot.h"
#include "DtcntSrvGprot.h"
#include "GpioSrvGprot.h"
#include "ModeSwitchSrvGprot.h"

#include "cbm_api.h"
#include "abm_api.h"

#include "CbmSrvFeature.h"
#include "CbmSrvIntProt.h"
#include "CbmSrvWlanPrefer.h"
#include "CbmSrvGprot.h"
#include "CbmSrvIprot.h"

#include "mmi_rp_srv_cbm_def.h"

#define SRV_CBM_WLAN_AUTO_SEARCH_TIMEOUT    (1000 * 30)
#define SRV_CBM_WLAN_PREFER_DELAY_TIMEOUT   (1000 * 60 * 60)

static U32 srv_cbm_wlan_prefer_delay_timeout = SRV_CBM_WLAN_PREFER_DELAY_TIMEOUT;

static void srv_cbm_wlan_scan_callback(
                U32 job_id,
                void *user_data,
                srv_dtcnt_wlan_scan_result_struct *scan_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_timer_exist;
    MMI_BOOL auto_conn;
    kal_uint32 app_num = SRV_CBM_MAX_APP_NUM;
    U8 wlan_ap_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_SRV_CBM_WLAN_SCAN_CALLBACK,
        scan_res->result,
        scan_res->ap_list_num,
        g_cbm_srv_cxt_ptr->wlan_query_type);

    if (g_cbm_srv_cxt_ptr->wlan_query_type != SRV_CBM_WLAN_QUERY_TYPE_NONE)
    {
        return;
    }

    if (scan_res->result == SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS &&
        scan_res->ap_list_num > 0)
    {
        wlan_ap_num = srv_cbm_get_valid_wlan_ap_num(MMI_FALSE, scan_res);
    }

    if (wlan_ap_num == 0)
    {
        srv_cbm_start_wlan_auto_search_timer();
        return;
    }

    abm_get_switchable_app_id(NULL, NULL, &app_num);
    if (app_num != 0)
    {
        is_timer_exist = srv_cbm_is_wlan_prefer_timer_running();
        if (!is_timer_exist)
        {
            srv_cbm_send_wlan_query_event(SRV_CBM_WLAN_QUERY_TYPE_FOUND);
            srv_cbm_set_wlan_query_type(SRV_CBM_WLAN_QUERY_TYPE_FOUND);
            return;
        }
    }

    srv_cbm_get_wlan_prefer_setting(SRV_CBM_WLAN_QUERY_TYPE_FOUND, &auto_conn, NULL);
    if (auto_conn)
    {
        srv_cbm_send_wlan_query_event(SRV_CBM_WLAN_QUERY_TYPE_AUTO_CONN);
    }
    else
    {
        srv_cbm_start_wlan_auto_search_timer();
    }
}


static void srv_cbm_bearer_switch_notify(
                srv_cbm_app_cntx_struct *app_p,
                srv_cbm_bearer_event_type_enum type,
                srv_cbm_bearer_switch_type_enum switch_type,
                MMI_BOOL user_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_bearer_event_struct bearer_evt;
    kal_int8 retval;
    abm_app_register_info_struct register_info;
    cbm_bearer_enum bearer_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retval = abm_get_registered_app_callback_info(app_p->app_id, ABM_APP_BEARER_EVENT, &register_info);

    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_SRV_CBM_BEARER_SWITCH_NOTIFY,
        type,
        app_p->nw_acct_id,
        switch_type,
        user_result,
        retval,
        (U32)register_info.callback);

    if (retval == CBM_OK && register_info.callback)
    {
        MMI_FRM_INIT_EVENT(&bearer_evt, EVT_ID_SRV_CBM_BEARER_EVENT);

        bearer_evt.type = type;
        bearer_evt.account_id = app_p->nw_acct_id;

        if (switch_type == SRV_CBM_BEARER_SWITCH_PS_TO_WIFI)
        {
            retval = cbm_get_bearer_type(app_p->nw_acct_id, &bearer_type);
            if (retval == CBM_OK)
            {
                bearer_evt.ori_bearer_type = (srv_cbm_bearer_type_enum)bearer_type;
            }
            else
            {
                bearer_evt.ori_bearer_type = SRV_CBM_BEARER_PS;
            }
        }
        else
        {
            bearer_evt.ori_bearer_type = SRV_CBM_BEARER_WIFI;
        }

        bearer_evt.switch_type = switch_type;
        bearer_evt.user_result = user_result;

        mmi_frm_send_event(
            (mmi_event_struct*)&bearer_evt,
            (mmi_proc_func)register_info.callback,
            register_info.data);
    }
}


static void srv_cbm_proc_app_wlan_query_result(
                srv_cbm_app_cntx_struct *app_p,
                srv_cbm_wlan_query_type_enum query_type,
                U32 bearer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (app_p->app_state)
    {
        case SRV_CBM_APP_STATE_STARTUP:
        case SRV_CBM_APP_STATE_CONNECT_FAIL:
            srv_cbm_proc_app_startup(app_p, query_type, bearer_type);
            break;

        case SRV_CBM_APP_STATE_DISCONNECTED:
        case SRV_CBM_APP_STATE_SWITCH_FAIL:
            srv_cbm_proc_app_disconnected(app_p, query_type, bearer_type);
            break;

        default:
            break;
    }
}


static void srv_cbm_wlan_query_callback(U32 bearer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_wlan_query_type_enum query_type;
    S32 i;
    srv_cbm_app_cntx_struct *app_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_QUERY_CALLBACK, bearer_type);

    srv_cbm_start_wlan_auto_search_timer();

    query_type = srv_cbm_get_wlan_query_type(MMI_TRUE, SRV_CBM_WLAN_QUERY_TYPE_NONE);
    if (query_type == SRV_CBM_WLAN_QUERY_TYPE_NONE)
    {
        return;
    }

    if (query_type == SRV_CBM_WLAN_QUERY_TYPE_FOUND)
    {
        if (bearer_type == CBM_BEARER_NONE)
        {
            srv_cbm_start_wlan_prefer_timer();
            bearer_type = CBM_BEARER_PS;
        }
    }

    if (bearer_type != CBM_BEARER_TOTAL)
    {
        for (i = 0; i < ABM_MAX_APP_NUM; i++)
        {
            app_p = &g_cbm_srv_cxt_ptr->app[i];

            if (app_p->app_id != CBM_INVALID_APP_ID &&
                app_p->app_state != SRV_CBM_APP_STATE_NONE)
            {
                srv_cbm_proc_app_wlan_query_result(app_p, query_type, bearer_type);
            }
        }
    }

    query_type = srv_cbm_get_next_wlan_query_type();
    if (query_type != SRV_CBM_WLAN_QUERY_TYPE_NONE)
    {
        srv_cbm_send_wlan_query_event(query_type);
    }

    srv_cbm_set_wlan_query_type(query_type);
}


void srv_cbm_proc_app_startup(
        srv_cbm_app_cntx_struct *app_p,
        srv_cbm_wlan_query_type_enum query_type,
        U32 bearer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 app_id;
    cbm_sim_id_enum sim_id;
    U32 rel_acct_id;
    MMI_BOOL result = MMI_TRUE;
    S32 cause = CBM_OK;
    kal_int32 wlan_status;
    U32 nw_acct_id = app_p->nw_acct_id;
    srv_dtcnt_wlan_state_enum wlan_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_SRV_CBM_PROCESS_STARTUP_APP,
        app_p->nw_acct_id,
        query_type,
        bearer_type);

    /* The query "STARTUP", "RECONNECT", "DISCONNECTED", "RESWITCH" and "FOUND" are acceptable here */
    if (query_type != SRV_CBM_WLAN_QUERY_TYPE_STARTUP &&
        query_type != SRV_CBM_WLAN_QUERY_TYPE_RECONNECT &&
        query_type != SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED &&
        query_type != SRV_CBM_WLAN_QUERY_TYPE_RESWITCH &&
        query_type != SRV_CBM_WLAN_QUERY_TYPE_FOUND)
    {
        return;
    }

    switch (bearer_type)
    {
        case CBM_BEARER_NONE:
            cbm_decode_data_account_id(app_p->nw_acct_id, &sim_id, &app_id, NULL, NULL);
            rel_acct_id = cbm_encode_data_account_id(CBM_INVALID_NWK_ACCT_ID, sim_id, app_id, KAL_FALSE);
            result = MMI_FALSE;
            cause = CBM_CANCEL_ACT_BEARER;
            break;

        case CBM_BEARER_WIFI:
            wlan_state = srv_dtcnt_wlan_state();

            if (wlan_state == SRV_DTCNT_WLAN_STATE_CONNECTED)
            {
                wlan_status = abm_get_bearer_available_status(CBM_BEARER_WIFI, CBM_SIM_ID_SIM1);

                if (wlan_status != CBM_ACTIVATED)
                {
                    app_p->app_state = SRV_CBM_APP_STATE_CONNECTING;
                    return;
                }
            }
            else
            {
                app_p->app_state = SRV_CBM_APP_STATE_CONNECTING;
                return;
            }

            cbm_decode_data_account_id(app_p->nw_acct_id, NULL, &app_id, NULL, NULL);
            rel_acct_id = cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, CBM_SIM_ID_SIM1, app_id, KAL_FALSE);
            break;

        default:
            cause = (S32)srv_cbm_get_real_acct_id(app_p->nw_acct_id, &rel_acct_id, &bearer_type);
            if (cause != CBM_OK)
            {
                result = MMI_FALSE;
            }
            break;
    }

    srv_cbm_free_app_slot(app_p);

    srv_cbm_send_bearer_init_rsp(
       result,
       nw_acct_id,
       rel_acct_id,
       bearer_type,
       cause);
}


void srv_cbm_proc_app_disconnected(
        srv_cbm_app_cntx_struct *app_p,
        srv_cbm_wlan_query_type_enum query_type,
        U32 bearer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 app_id;
    cbm_sim_id_enum sim_id;
    U32 rel_acct_id;
    U32 user_result = MMI_ABM_BEARER_EVENT_ACCEPT_THIS_TIME;
    srv_cbm_bearer_switch_type_enum switch_type = SRV_CBM_BEARER_SWITCH_NONE;
    cbm_result_error_enum cause = CBM_OK;
    kal_int32 wlan_status;
    U32 nw_acct_id = app_p->nw_acct_id;
    srv_dtcnt_wlan_state_enum wlan_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_SRV_CBM_PROCESS_DISCONNECTED_APP,
        app_p->nw_acct_id,
        query_type,
        bearer_type);

    /* The query "DISCONNECTED" is acceptable here */
    if (query_type != SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED &&
        query_type != SRV_CBM_WLAN_QUERY_TYPE_RESWITCH)
    {
        return;
    }

    switch (bearer_type)
    {
        case CBM_BEARER_NONE:
            user_result = MMI_ABM_BEARER_EVENT_CANCEL;
            cbm_decode_data_account_id(app_p->nw_acct_id, &sim_id, &app_id, NULL, NULL);
            rel_acct_id = cbm_encode_data_account_id(CBM_INVALID_NWK_ACCT_ID, sim_id, app_id, KAL_FALSE);
            break;

        case CBM_BEARER_WIFI:
            wlan_state = srv_dtcnt_wlan_state();

            if (wlan_state == SRV_DTCNT_WLAN_STATE_CONNECTED)
            {
                wlan_status = abm_get_bearer_available_status(CBM_BEARER_WIFI, CBM_SIM_ID_SIM1);

                if (wlan_status != CBM_ACTIVATED)
                {
                    app_p->app_state = SRV_CBM_APP_STATE_SWITCHING;
                    return;
                }
            }
            else
            {
                app_p->app_state = SRV_CBM_APP_STATE_SWITCHING;
                return;
            }

            cbm_decode_data_account_id(app_p->nw_acct_id, NULL, &app_id, NULL, NULL);
            rel_acct_id = cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, CBM_SIM_ID_SIM1, app_id, KAL_FALSE);
            switch_type = SRV_CBM_BEARER_SWITCH_WIFI_TO_WIFI;
            break;

        default:
            cause = srv_cbm_get_real_acct_id(app_p->nw_acct_id, &rel_acct_id, NULL);
            if (cause != CBM_OK)
            {
                user_result = MMI_ABM_BEARER_EVENT_CANCEL;
            }
            else
            {
                switch_type = SRV_CBM_BEARER_SWITCH_WIFI_TO_PS;
            }
            break;
    }

    srv_cbm_bearer_switch_notify(
        app_p,
        SRV_CBM_BEARER_EVENT_SWITCH,
        switch_type,
        (user_result == MMI_ABM_BEARER_EVENT_CANCEL ? MMI_FALSE : MMI_TRUE));

    if (switch_type == SRV_CBM_BEARER_SWITCH_WIFI_TO_PS)
    {
        app_p->rel_acct_id = rel_acct_id;
        app_p->app_state = SRV_CBM_APP_STATE_NONE;
    }
    else
    {
        srv_cbm_free_app_slot(app_p);
    }

    srv_cbm_send_bearer_evt_connect_req(
        user_result,
        MMI_ABM_BEARER_EVT_SWITCH,
        nw_acct_id,
        rel_acct_id);
}


void srv_cbm_send_wlan_query_event(srv_cbm_wlan_query_type_enum query_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_wlan_query_evt_struct wlan_query_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_SEND_WLAN_QUERY_EVENT, query_type);

    srv_cbm_stop_wlan_auto_search_timer();

    MMI_FRM_INIT_EVENT(&wlan_query_evt, EVT_ID_SRV_CBM_WLAN_QUERY);
    wlan_query_evt.query_type = query_type;
    wlan_query_evt.rsp_callback = srv_cbm_wlan_query_callback;
    MMI_FRM_CB_EMIT_POST_EVENT(&wlan_query_evt);
}


void srv_cbm_set_wlan_query_type(srv_cbm_wlan_query_type_enum query_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cbm_srv_cxt_ptr->wlan_query_type = query_type;
}


srv_cbm_wlan_query_type_enum srv_cbm_get_wlan_query_type(
                                MMI_BOOL get_ori_type,
                                srv_cbm_wlan_query_type_enum new_query_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_SRV_CBM_GET_WLAN_QUERY_TYPE,
        get_ori_type,
        new_query_type,
        g_cbm_srv_cxt_ptr->wlan_query_type);

    if (get_ori_type)
    {
        return (srv_cbm_wlan_query_type_enum)g_cbm_srv_cxt_ptr->wlan_query_type;
    }
    else
    {
        if (g_cbm_srv_cxt_ptr->wlan_query_type == SRV_CBM_WLAN_QUERY_TYPE_NONE)
        {
            return new_query_type;
        }
        else
        {
            return SRV_CBM_WLAN_QUERY_TYPE_NONE;
        }
    }
}


MMI_BOOL srv_cbm_is_wlan_query_type_valid(srv_cbm_wlan_query_type_enum query_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_app_state_enum app_state = SRV_CBM_APP_STATE_NONE;
    srv_cbm_app_cntx_struct *app_p;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (query_type)
    {
        case SRV_CBM_WLAN_QUERY_TYPE_STARTUP:
            app_state = SRV_CBM_APP_STATE_STARTUP;
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED:
            app_state = SRV_CBM_APP_STATE_DISCONNECTED;
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RECONNECT:
            app_state = SRV_CBM_APP_STATE_CONNECT_FAIL;
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RESWITCH:
            app_state = SRV_CBM_APP_STATE_SWITCH_FAIL;
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_FOUND:
        case SRV_CBM_WLAN_QUERY_TYPE_AUTO_CONN:
            return MMI_TRUE;

        default:
            return MMI_FALSE;
    }

    for (i = 0; i < ABM_MAX_APP_NUM; i++)
    {
        app_p = &g_cbm_srv_cxt_ptr->app[i];

        if (app_p->app_id != CBM_INVALID_APP_ID &&
            app_p->app_state == app_state)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


srv_cbm_wlan_query_type_enum srv_cbm_get_next_wlan_query_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_cbm_app_cntx_struct *app_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < ABM_MAX_APP_NUM; i++)
    {
        app_p = &g_cbm_srv_cxt_ptr->app[i];

        if (app_p->app_id != CBM_INVALID_APP_ID &&
            app_p->app_state != SRV_CBM_APP_STATE_NONE)
        {
            switch (app_p->app_state)
            {
                case SRV_CBM_APP_STATE_STARTUP:
                    return SRV_CBM_WLAN_QUERY_TYPE_STARTUP;

                case SRV_CBM_APP_STATE_DISCONNECTED:
                    return SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED;

                case SRV_CBM_APP_STATE_CONNECT_FAIL:
                    return SRV_CBM_WLAN_QUERY_TYPE_RECONNECT;

                case SRV_CBM_APP_STATE_SWITCH_FAIL:
                    return SRV_CBM_WLAN_QUERY_TYPE_RESWITCH;

                default:
                    break;
            }
        }
    }

    return SRV_CBM_WLAN_QUERY_TYPE_NONE;
}

/***************************************************************************/

void srv_cbm_get_wlan_prefer_setting(
        srv_cbm_wlan_query_type_enum query_type,
        MMI_BOOL *auto_conn,
        MMI_BOOL *need_notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_prefer_struct info;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_dtcnt_get_wlan_prefer_setting(&info);

    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_SRV_CBM_GET_WLAN_PREFER_SETTING,
        ret,
        info.is_auto_conn,
        info.network_switch,
        query_type);

    if (!ret)
    {
        if (auto_conn)
        {
            *auto_conn = MMI_FALSE;
        }
        if (need_notify)
        {
            *need_notify = MMI_FALSE;
        }
        return;
    }

    if (auto_conn)
    {
        if (srv_cbm_get_valid_wlan_ap_num(MMI_TRUE, NULL))
        {
            *auto_conn = info.is_auto_conn;
        }
        else
        {
            *auto_conn = MMI_FALSE;
        }
    }

    switch (query_type)
    {
        case SRV_CBM_WLAN_QUERY_TYPE_STARTUP:
            if (auto_conn)
            {
                *auto_conn = MMI_FALSE;
            }
            if (need_notify)
            {
                *need_notify = MMI_TRUE;
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_RECONNECT:
            if (auto_conn)
            {
                *auto_conn = MMI_FALSE;
            }
            if (need_notify)
            {
                *need_notify = MMI_TRUE;
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_DISCONNECTED:
            if (need_notify)
            {
                *need_notify = MMI_TRUE;
            }
            break;

        case SRV_CBM_WLAN_QUERY_TYPE_FOUND:
            if (need_notify)
            {
                *need_notify = (info.network_switch == 0 ? MMI_FALSE : MMI_TRUE);
            }
            break;

        default:
            if (need_notify)
            {
                *need_notify = MMI_FALSE;
            }
            break;
    }
}


MMI_BOOL srv_cbm_get_ask_cellular_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_prefer_struct info;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_dtcnt_get_wlan_prefer_setting(&info);

    if (ret && info.cellular_switch == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void srv_cbm_set_ask_cellular_setting(MMI_BOOL ask_cellular)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_prefer_struct info;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_dtcnt_get_wlan_prefer_setting(&info);
    if (ret)
    {
        if (ask_cellular)
        {
            info.cellular_switch = 0;
        }
        else
        {
            info.cellular_switch = 1;
        }
        srv_dtcnt_set_wlan_prefer_setting(&info);
    }
}


MMI_BOOL srv_cbm_is_wlan_query_needed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_wlan_query_type_enum cur_query_type;
    srv_cbm_wlan_query_type_enum new_query_type;
    MMI_BOOL is_valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_query_type = srv_cbm_get_wlan_query_type(MMI_TRUE, SRV_CBM_WLAN_QUERY_TYPE_NONE);

    is_valid = srv_cbm_is_wlan_query_type_valid(cur_query_type);
    if (is_valid)
    {
        return MMI_TRUE;
    }

    new_query_type = srv_cbm_get_next_wlan_query_type();
    if (new_query_type != SRV_CBM_WLAN_QUERY_TYPE_NONE)
    {
        srv_cbm_send_wlan_query_event(new_query_type);
    }

    srv_cbm_set_wlan_query_type(new_query_type);
    return MMI_FALSE;
}


void srv_cbm_wlan_auto_search_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_state_enum wlan_state;
    kal_int32 wlan_status;
    kal_uint32 app_num = SRV_CBM_MAX_APP_NUM;
    MMI_BOOL is_timer_exist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_SRV_CBM_WLAN_AUTO_SEARCH_TIMEOUT_CALLBACK,
        g_cbm_srv_cxt_ptr->wlan_query_type);

    if (g_cbm_srv_cxt_ptr->wlan_query_type != SRV_CBM_WLAN_QUERY_TYPE_NONE)
    {
        return;
    }

    wlan_state = srv_dtcnt_wlan_state();
    wlan_status = abm_get_bearer_available_status(CBM_BEARER_WIFI, CBM_SIM_ID_SIM1);

    if (wlan_state == SRV_DTCNT_WLAN_STATE_CONNECTED &&
        wlan_status != CBM_ACTIVATING)
    {
        kal_uint8 app_id[SRV_CBM_MAX_APP_NUM];
        kal_uint32 acct_id[SRV_CBM_MAX_APP_NUM];

        abm_get_switchable_app_id(app_id, acct_id, &app_num);

        if (app_num > 0)
        {
            if (wlan_status == CBM_ACTIVATED)
            {
                S32 i;
                kal_int8 retval;
                abm_app_register_info_struct register_info;
                srv_cbm_bearer_event_struct bearer_evt;

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
            else
            {
                is_timer_exist = srv_cbm_is_wlan_prefer_timer_running();
                if (!is_timer_exist)
                {
                    srv_cbm_send_wlan_query_event(SRV_CBM_WLAN_QUERY_TYPE_FOUND);
                    srv_cbm_set_wlan_query_type(SRV_CBM_WLAN_QUERY_TYPE_FOUND);
                    return;
                }
            }
        }
    }

    if (wlan_state != SRV_DTCNT_WLAN_STATE_INIT ||
        srv_backlight_is_lcd_sleep() ||
    #ifdef __MMI_OP01_WIFI__
        !srv_mode_switch_is_network_service_available() ||
    #endif
        srv_mode_switch_is_switching())
    {
        srv_cbm_start_wlan_auto_search_timer();
        return;
    }

#ifndef WENKE_TEST
    srv_dtcnt_wlan_scan(srv_cbm_wlan_scan_callback, NULL);
#else
    {
        srv_dtcnt_wlan_scan_result_struct scan;
        scan.result = SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS;
        scan.ap_list_num = 1;
        srv_cbm_wlan_scan_callback(0, NULL, &scan);
    }
#endif
}


void srv_cbm_start_wlan_auto_search_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(
        SRV_CBM_WLAN_AUTO_SEARCH_TIMER,
        SRV_CBM_WLAN_AUTO_SEARCH_TIMEOUT,
        srv_cbm_wlan_auto_search_timeout);
}


void srv_cbm_stop_wlan_auto_search_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(SRV_CBM_WLAN_AUTO_SEARCH_TIMER);
}


void srv_cbm_wlan_prefer_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_SRV_CBM_WLAN_PREFER_TIMER_TIMEOUT,
        srv_cbm_wlan_prefer_delay_timeout / 1000);
}


void srv_cbm_start_wlan_prefer_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G6_CBM,
        TRC_SRV_CBM_WLAN_PREFER_TIMER_START,
        srv_cbm_wlan_prefer_delay_timeout / 1000);

    StartTimer(
        SRV_CBM_WLAN_PREFER_DELAY_TIMER,
        srv_cbm_wlan_prefer_delay_timeout,
        srv_cbm_wlan_prefer_timeout);
}


MMI_BOOL srv_cbm_is_wlan_prefer_timer_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = IsMyTimerExist(SRV_CBM_WLAN_PREFER_DELAY_TIMER);

    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_PREFER_TIMER_CHECK, ret);
    return ret;
}


void srv_cbm_set_wlan_prefer_delay_timeout(U32 sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_WLAN_PREFER_TIMER_SET, sec);

    srv_cbm_wlan_prefer_delay_timeout = sec * 1000;

    if (IsMyTimerExist(SRV_CBM_WLAN_PREFER_DELAY_TIMER))
    {
        StopTimer(SRV_CBM_WLAN_PREFER_DELAY_TIMER);
        StartTimer(
            SRV_CBM_WLAN_PREFER_DELAY_TIMER,
            srv_cbm_wlan_prefer_delay_timeout,
            srv_cbm_wlan_prefer_timeout);
    }
}


U8 srv_cbm_get_valid_wlan_ap_num(MMI_BOOL check_store_prof, srv_dtcnt_wlan_scan_result_struct *scan_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_store_prof_qry_struct acct_id_query;
    srv_dtcnt_store_prof_data_struct prof_info;
    srv_dtcnt_prof_wlan_struct *wlan_prof_p;
    srv_dtcnt_result_enum ret;
    U8 i;
    U8 valid_cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&acct_id_query, 0, sizeof(acct_id_query));

    acct_id_query.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE;
    acct_id_query.qry_info.bearer_qry_info = SRV_DTCNT_BEARER_WIFI;

    srv_dtcnt_store_qry_ids(&acct_id_query);

    if (acct_id_query.num_ids == 0)
    {
        if (check_store_prof)
        {
            return 0;
        }
        else
        {
            return scan_info_p ? scan_info_p->ap_list_num : 0;
        }
    }

    if (check_store_prof)
    {
        wlan_prof_p = (srv_dtcnt_prof_wlan_struct*)OslMalloc(sizeof(srv_dtcnt_prof_wlan_struct));

        prof_info.prof_type = SRV_DTCNT_BEARER_WIFI;
        prof_info.prof_data = wlan_prof_p;
        prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;

        for (i = 0; i < acct_id_query.num_ids; i++)
        {
            ret = srv_dtcnt_store_qry_prof(acct_id_query.ids[i], &prof_info);
            if (ret == SRV_DTCNT_RESULT_SUCCESS &&
                wlan_prof_p->ap_type != SRV_DTCNT_WLAN_AP_BLACK_LIST)
            {
                valid_cnt++;
            }
        }

        OslMfree(wlan_prof_p);
    }
    else
    {
        if (scan_info_p)
        {
            for (i = 0; i < scan_info_p->ap_list_num; i++)
            {
                if (!srv_dtcnt_wlan_in_blacklist((supc_abm_bss_info_struct*)scan_info_p->ap_list[i]))
                {
                    valid_cnt++;
                }
            }
        }
    }

    return valid_cnt;
}


MMI_BOOL srv_cbm_is_wlan_sleep(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_prefer_struct info;
    MMI_BOOL is_sleep = MMI_FALSE;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_dtcnt_get_wlan_prefer_setting(&info);
    if (ret && info.need_awake)
    {
        is_sleep = MMI_TRUE;
    }

    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_IS_WLAN_SLEEP, is_sleep);
    return is_sleep;
}

#endif /* __MMI_WLAN_FEATURES__ */

