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
 *  CbmSrvInterface.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI CBM service interface
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

#include "mmi2abm_struct.h"
#include "abm_api.h"
#include "cbm_api.h"
#ifdef __TCPIP__
#include "mmi_rp_srv_cbm_def.h"
#endif
#include "CbmSrvFeature.h"
#include "CbmSrvGprot.h"
#include "CbmSrvIntProt.h"

#include "MMIDataType.h"
#include "cbm_consts.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_conn_app_trc.h"
#include "mmi_frm_events_gprot.h"

extern srv_cbm_context_struct g_cbm_srv_cxt;

#ifdef __TCPIP__
static U32 srv_cbm_convert_bearer_event(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 conv_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type & SRV_CBM_BEARER_EVENT_SWITCH)
    {
        conv_type |= CBM_APP_BEARER_EVT_SWITCH;
    }

    if (type & SRV_CBM_BEARER_EVENT_DISCONNECT)
    {
        conv_type |= CBM_APP_BEARER_EVT_DISCONNECT;
    }

    return conv_type;
}
#endif

/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_register_bearer_info(
                            U8 app_id,
                            U32 state,
                            U32 type,
                            mmi_proc_func callback,
                            void *user_data)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 return_val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return_val = abm_register_app_callback(
                    ABM_APP_BEARER_INFO, 
                    app_id,
                    (void*)callback,
                    user_data);

    if (return_val == CBM_OK)
    {
        return_val = cbm_register_bearer_info_by_app_id(
                        app_id,
                        MOD_MMI,
                        (kal_uint32)type,
                        (kal_uint32)state);
    }

    MMI_TRACE(MMI_CONN_TRC_INFO, TRC_SRV_CBM_BEARER_EVT_REGISTERED, app_id, callback, return_val);

    switch (return_val)
    {
        case CBM_OK:
            return SRV_CBM_OK;

        case CBM_ERROR:
            return SRV_CBM_ERROR;

        case CBM_LIMIT_RESOURCE:
            return SRV_CBM_LIMIT_RESOURCE;

        case CBM_INVALID_AP_ID:
            return SRV_CBM_INVALID_AP_ID;

        default:
            return SRV_CBM_ERROR;
    }
#else /* __TCPIP__ */
    return SRV_CBM_ERROR;
#endif /* !__TCPIP__ */
}


/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_deregister_bearer_info(U8 app_id)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 return_val = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return_val = abm_deregister_app_callback(ABM_APP_BEARER_INFO, app_id);

    if (return_val)
    {
        return_val = cbm_deregister_bearer_info_by_app_id(app_id);
    }

    MMI_TRACE(MMI_CONN_TRC_INFO, TRC_SRV_CBM_BEARER_INFO_DEREGISTERED, app_id, return_val);

    switch (return_val)
    {   
        case CBM_OK:
            return SRV_CBM_OK;

        case CBM_ERROR:
            return SRV_CBM_ERROR;

        case CBM_INVALID_AP_ID:
            return SRV_CBM_INVALID_AP_ID;

        default:
            return SRV_CBM_ERROR;
    }
#else /* __TCPIP__ */
    return SRV_CBM_ERROR;
#endif /* !__TCPIP__ */
}


/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_register_bearer_event(
                              U32 type,
                              U8 app_id,
                              mmi_proc_func callback,
                              void *user_data)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 return_val = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_CBM, TRC_SRV_CBM_REGISTER_BEARER_EVENT, app_id, type);

    /* Bearer switch is supported only */
    type = srv_cbm_convert_bearer_event(type);
    if (type == 0)
    {
        return SRV_CBM_OK; //??? SRV_CBM_ERROR
    }

    /* CBM_APP_BEARER_EVT_DISCONNECT must be registered with CBM_APP_BEARER_EVT_SWITCH toghther */
	if ((type & CBM_APP_BEARER_EVT_DISCONNECT) &&
	    !(type & CBM_APP_BEARER_EVT_SWITCH))
	{
	    return SRV_CBM_ERROR;
	}

    return_val = abm_register_app_callback(
                    ABM_APP_BEARER_EVENT,
                    app_id,
                    (void*)callback,
                    user_data);
    if (return_val == CBM_OK)
    {
        return_val = cbm_set_app_bearer_event(app_id, MOD_MMI, (kal_uint32)type);
    }

    MMI_TRACE(MMI_CONN_TRC_INFO, TRC_SRV_CBM_BEARER_EVT_REGISTERED, app_id, callback, return_val);

    switch (return_val)
    {
        case CBM_OK:
            return SRV_CBM_OK;

        case CBM_ERROR:
            return SRV_CBM_ERROR;

        case CBM_LIMIT_RESOURCE:
            return SRV_CBM_LIMIT_RESOURCE;

        default:
            return SRV_CBM_ERROR;
    }
#else /* __TCPIP__ */
    return SRV_CBM_ERROR;
#endif /* __TCPIP__ */
}


/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_deregister_bearer_event(U8 app_id)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 return_val = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return_val = abm_deregister_app_callback(ABM_APP_BEARER_EVENT, app_id);

    if (return_val == CBM_OK)
    {
        return_val = cbm_set_app_bearer_event(app_id, MOD_NIL, CBM_APP_BEARER_EVT_NONE);
    }

    MMI_TRACE(MMI_CONN_TRC_INFO, TRC_SRV_CBM_BEARER_EVT_DEREGISTERED, app_id, return_val);

    switch (return_val)
    {
        case CBM_OK:
            return SRV_CBM_OK;

        case CBM_ERROR:
            return SRV_CBM_ERROR;

        case CBM_INVALID_AP_ID:
            return SRV_CBM_INVALID_AP_ID;

        default:
            return SRV_CBM_ERROR;
    }
#else /* __TCPIP__ */
    return SRV_CBM_ERROR;
#endif /* __TCPIP__ */
}


/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_abort_app_bearer_event(U8 app_id)
{
#ifdef __TCPIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = cbm_abort_app_bearer_event((kal_uint8)app_id);
    if (ret == CBM_INVALID_AP_ID)
    {
        return SRV_CBM_INVALID_AP_ID;
    }

    return SRV_CBM_OK;
#else /* __TCPIP__ */
    return SRV_CBM_ERROR;
#endif /* __TCPIP__ */
}


/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_disallow_nwk_srv(U32 type, U8 app_id)
{
#if defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_nwk_app_struct *app_p = NULL;
    mmi_abm_nwk_srv_type_enum action_type = MMI_ABM_NWK_SRV_NONE;
    U32 bearer_type[CBM_SIM_ID_TOTAL];
    S32 i = 0;
    MMI_BOOL is_wifi_selected = MMI_FALSE;
    S32 bearer_num = srv_cbm_get_sim_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, TRC_SRV_CBM_DISALLOW_BEARER, app_id, type);

    if (app_id == CBM_INVALID_APP_ID)
    {
        return SRV_CBM_ERROR;
    }

    app_p = srv_cbm_get_app_index(app_id);
    if (!app_p)
    {
        app_p = srv_cbm_get_app_index(CBM_INVALID_APP_ID);
    }

    if (!app_p)
    {
        return SRV_CBM_ERROR;
    }

    if (!(type & (SRV_CBM_BEARER_LOCAL | SRV_CBM_BEARER_DIALUP)))
    {
        type |= SRV_CBM_BEARER_DIALUP;
    }
    else
    {
        type &= ~SRV_CBM_BEARER_LOCAL;
    }

    for (i = 0; i < CBM_SIM_ID_TOTAL; i++)
    {
        bearer_type[i] = 0;
    }

    for (i = 0; i < bearer_num; i++)
    {
        bearer_type[i] = srv_cbm_merge_bearer(
                            MMI_ABM_NWK_SRV_ACTION_DISALLOW,
                            app_p,
                            (cbm_sim_id_enum)i,
                            type);

        if (bearer_type[i] != SRV_CBM_BEARER_INVALID)
        {
            if (bearer_type[i] & SRV_CBM_BEARER_DIALUP)
            {
                action_type |= MMI_ABM_NWK_SRV_DIALUP;
            }
            if (bearer_type[i] != SRV_CBM_BEARER_DIALUP)
            {
                action_type |= MMI_ABM_NWK_SRV_LOCAL;
                if (!is_wifi_selected && (bearer_type[i] & SRV_CBM_BEARER_WIFI))
                {
                    is_wifi_selected = MMI_TRUE;
                }
            }
        }
    }

    if (is_wifi_selected)
    {
        srv_cbm_mark_common_bearer(bearer_type, SRV_CBM_BEARER_WIFI);
    }

    kal_trace(TRACE_INFO, TRC_SRV_CBM_DISALLOW_CHECK_BEARER_INFO,
        action_type, bearer_type[0], bearer_type[1], bearer_type[2], bearer_type[3]);

    if (action_type == MMI_ABM_NWK_SRV_NONE)
    {
        srv_cbm_disallow_bearer(app_p, CBM_SIM_ID_TOTAL, type, app_id);
        return SRV_CBM_OK;
    }

    /* send disallow gprs&csd activate req to abm */
    srv_cbm_send_nwk_srv_req(MMI_ABM_NWK_SRV_ACTION_DISALLOW, action_type, bearer_type);

    /*wait for response. This is blocking API */
    srv_cbm_lock();

    kal_trace(TRACE_FUNC, TRC_SRV_CBM_DISALLOW_BEARER_RESULT, g_cbm_srv_cxt_ptr->nwk_srv.result);

    if (g_cbm_srv_cxt_ptr->nwk_srv.result)
    {
        srv_cbm_disallow_bearer(app_p, CBM_SIM_ID_TOTAL, type, app_id);
        for (i = 0; i < bearer_num; i++)
        {
            g_cbm_srv_cxt_ptr->nwk_srv.disallowed_bearer[i] |= bearer_type[i];
        }
        return SRV_CBM_OK;
    }

    return SRV_CBM_ERROR;
#else /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
    return SRV_CBM_OK;
#endif /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
}


/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_allow_nwk_srv(U32 type, U8 app_id)
{
#if defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_nwk_app_struct *app_p = NULL;
    mmi_abm_nwk_srv_type_enum action_type = MMI_ABM_NWK_SRV_NONE;
    U32 bearer_type[CBM_SIM_ID_TOTAL];
    S32 i = 0;
    MMI_BOOL is_wifi_selected = MMI_FALSE;
    S32 bearer_num = srv_cbm_get_sim_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, TRC_SRV_CBM_ALLOW_BEARER, app_id, type);

    if (app_id == CBM_INVALID_APP_ID)
    {
        return SRV_CBM_ERROR;
    }

    app_p = srv_cbm_get_app_index(app_id);
    if (!app_p)
    {
        return SRV_CBM_ERROR;
    }

    if (!(type & (SRV_CBM_BEARER_LOCAL | SRV_CBM_BEARER_DIALUP)))
    {
        type |= SRV_CBM_BEARER_DIALUP;
    }
    else
    {
        type &= ~SRV_CBM_BEARER_LOCAL;
    }

    for (i = 0; i < CBM_SIM_ID_TOTAL; i++)
    {
        bearer_type[i] = 0;
    }

    for (i = 0; i < bearer_num; i++)
    {
        bearer_type[i] = srv_cbm_merge_bearer(
                            MMI_ABM_NWK_SRV_ACTION_ALLOW,
                            app_p,
                            (cbm_sim_id_enum)i,
                            type);

        if (bearer_type[i] != SRV_CBM_BEARER_INVALID)
        {
            if (bearer_type[i] & SRV_CBM_BEARER_DIALUP)
            {
                action_type |= MMI_ABM_NWK_SRV_DIALUP;
            }
            if (bearer_type[i] != SRV_CBM_BEARER_DIALUP)
            {
                action_type |= MMI_ABM_NWK_SRV_LOCAL;
                if (!is_wifi_selected && (bearer_type[i] & SRV_CBM_BEARER_WIFI))
                {
                    is_wifi_selected = MMI_TRUE;
                }
            }
        }
    }

    if (is_wifi_selected)
    {
        srv_cbm_mark_common_bearer(bearer_type, SRV_CBM_BEARER_WIFI);
    }

    kal_trace(TRACE_INFO, TRC_SRV_CBM_ALLOW_CHECK_BEARER_INFO,
        action_type, bearer_type[0], bearer_type[1], bearer_type[2], bearer_type[3]);

    if (action_type == MMI_ABM_NWK_SRV_NONE)
    {
        srv_cbm_allow_bearer(app_p, CBM_SIM_ID_TOTAL, type);
        return SRV_CBM_OK;
    }

    /* send allow gprs&csd activate req to abm */
    srv_cbm_send_nwk_srv_req(MMI_ABM_NWK_SRV_ACTION_ALLOW, action_type, bearer_type);

    /*wait for response. This is blocking API */
    srv_cbm_lock();

    kal_trace(TRACE_FUNC, TRC_SRV_CBM_ALLOW_BEARER_ACTIVATE, g_cbm_srv_cxt_ptr->nwk_srv.result);
    if (g_cbm_srv_cxt_ptr->nwk_srv.result)
    {
        srv_cbm_allow_bearer(app_p, CBM_SIM_ID_TOTAL, type);
        for (i = 0; i < bearer_num; i++)
        {
            g_cbm_srv_cxt_ptr->nwk_srv.disallowed_bearer[i] &= ~bearer_type[i];
        }
        return SRV_CBM_OK;
    }

    return SRV_CBM_ERROR;
#else /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
    return SRV_CBM_ERROR;
#endif /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
}


/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_get_nwk_srv_error_info(srv_cbm_result_error_enum error,
                                                                  MMI_STR_ID *str_id,
                                                                  mmi_event_notify_enum *popup_type)
{
#if defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error == SRV_CBM_ERROR)
    {
        if (str_id)
        {
            *str_id = STR_ID_SRV_CBM_DISALLOW_ERROR;
        }
        if (popup_type)
        {
            *popup_type = MMI_EVENT_FAILURE;
        }
    }
    else
    {
        return SRV_CBM_ERROR;
    }
    
    return SRV_CBM_OK;
#else /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
    return SRV_CBM_ERROR;
#endif /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
}


/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_set_allowed_app_nwk_srv(U32 type, kal_uint8 app_id)
{
#if defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__)
    if (abm_set_allowed_app_nwk_srv(type, app_id) == CBM_OK)
    {
        return SRV_CBM_OK;
    }
    
    return SRV_CBM_ERROR;
#else /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
    return SRV_CBM_ERROR;
#endif /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
}


/* For detail description please refer to CbmSrvGprot.h */
MMI_BOOL srv_cbm_is_nwk_srv_disallowed(U32 type)
{
#if defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CBM_SIM_ID_TOTAL; i++)
    {
        if (g_cbm_srv_cxt_ptr->nwk_srv.disallowed_bearer[i] & type)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
#else /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
    return MMI_FALSE;
#endif /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
}


srv_cbm_result_error_enum srv_cbm_disallow_nwk_srv_by_sim(cbm_sim_id_enum sim_id, U32 type, U8 app_id)
{
#if defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_nwk_app_struct *app_p = NULL;
    mmi_abm_nwk_srv_type_enum action_type = MMI_ABM_NWK_SRV_NONE;
    U32 bearer_type[CBM_SIM_ID_TOTAL];
    S32 i = 0;
    MMI_BOOL is_wifi_selected = MMI_FALSE;
    S32 bearer_num = srv_cbm_get_sim_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, TRC_SRV_CBM_DISALLOW_BEARER_BY_SIM, sim_id, type, app_id);

    if (sim_id >= bearer_num || app_id == CBM_INVALID_APP_ID)
    {
        return SRV_CBM_ERROR;
    }

    app_p = srv_cbm_get_app_index(app_id);
    if (!app_p)
    {
        app_p = srv_cbm_get_app_index(CBM_INVALID_APP_ID);
    }

    if (!app_p)
    {
        return SRV_CBM_ERROR;
    }

    if (!(type & (SRV_CBM_BEARER_LOCAL | SRV_CBM_BEARER_DIALUP)))
    {
        type |= SRV_CBM_BEARER_DIALUP;
    }
    else
    {
        type &= ~SRV_CBM_BEARER_LOCAL;
    }

    for (i = 0; i < CBM_SIM_ID_TOTAL; i++)
    {
        bearer_type[i] = 0;
    }

    bearer_type[sim_id] = srv_cbm_merge_bearer(
                            MMI_ABM_NWK_SRV_ACTION_DISALLOW,
                            app_p,
                            sim_id,
                            type);

    if (bearer_type[sim_id] != SRV_CBM_BEARER_INVALID)
    {
        if (bearer_type[sim_id] & SRV_CBM_BEARER_DIALUP)
        {
            action_type |= MMI_ABM_NWK_SRV_DIALUP;
        }
        if (bearer_type[sim_id] != SRV_CBM_BEARER_DIALUP)
        {
            action_type |= MMI_ABM_NWK_SRV_LOCAL;
            if (bearer_type[sim_id] & SRV_CBM_BEARER_WIFI)
            {
                is_wifi_selected = MMI_TRUE;
            }
        }
    }

    if (is_wifi_selected)
    {
        srv_cbm_mark_common_bearer(bearer_type, SRV_CBM_BEARER_WIFI);
    }

    kal_trace(TRACE_INFO, TRC_SRV_CBM_DISALLOW_SIM_CHECK_BEARER_INFO,
        action_type, bearer_type[0], bearer_type[1], bearer_type[2], bearer_type[3]);

    if (action_type == MMI_ABM_NWK_SRV_NONE)
    {
        srv_cbm_disallow_bearer(app_p, sim_id, type, app_id);
        return SRV_CBM_OK;
    }

    /* send disallow gprs&csd activate req to abm */
    srv_cbm_send_nwk_srv_req(MMI_ABM_NWK_SRV_ACTION_DISALLOW, action_type, bearer_type);

    /*wait for response. This is blocking API */
    srv_cbm_lock();

    kal_trace(TRACE_FUNC, TRC_SRV_CBM_DISALLOW_BEARER_RESULT, g_cbm_srv_cxt_ptr->nwk_srv.result);

    if (g_cbm_srv_cxt_ptr->nwk_srv.result)
    {
        srv_cbm_disallow_bearer(app_p, sim_id, type, app_id);
        for (i = 0; i < bearer_num; i++)
        {
            g_cbm_srv_cxt_ptr->nwk_srv.disallowed_bearer[i] |= bearer_type[i];
        }
        return SRV_CBM_OK;
    }

    return SRV_CBM_ERROR;
#else /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
    return SRV_CBM_OK;
#endif /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
}


/* For detail description please refer to CbmSrvGprot.h */
srv_cbm_result_error_enum srv_cbm_allow_nwk_srv_by_sim(cbm_sim_id_enum sim_id, U32 type, U8 app_id)
{
#if defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbm_nwk_app_struct *app_p = NULL;
    mmi_abm_nwk_srv_type_enum action_type = MMI_ABM_NWK_SRV_NONE;
    U32 bearer_type[CBM_SIM_ID_TOTAL];
    S32 i = 0;
    MMI_BOOL is_wifi_selected = MMI_FALSE;
    S32 bearer_num = srv_cbm_get_sim_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, TRC_SRV_CBM_ALLOW_BEARER_BY_SIM, sim_id, type, app_id);

    if (sim_id >= bearer_num || app_id == CBM_INVALID_APP_ID)
    {
        return SRV_CBM_ERROR;
    }

    app_p = srv_cbm_get_app_index(app_id);
    if (!app_p)
    {
        return SRV_CBM_ERROR;
    }

    if (!(type & (SRV_CBM_BEARER_LOCAL | SRV_CBM_BEARER_DIALUP)))
    {
        type |= SRV_CBM_BEARER_DIALUP;
    }
    else
    {
        type &= ~SRV_CBM_BEARER_LOCAL;
    }

    for (i = 0; i < CBM_SIM_ID_TOTAL; i++)
    {
        bearer_type[i] = 0;
    }

    bearer_type[sim_id] = srv_cbm_merge_bearer(
                            MMI_ABM_NWK_SRV_ACTION_ALLOW,
                            app_p,
                            sim_id,
                            type);

    if (bearer_type[sim_id] != SRV_CBM_BEARER_INVALID)
    {
        if (bearer_type[sim_id] & SRV_CBM_BEARER_DIALUP)
        {
            action_type |= MMI_ABM_NWK_SRV_DIALUP;
        }
        if (bearer_type[sim_id] != SRV_CBM_BEARER_DIALUP)
        {
            action_type |= MMI_ABM_NWK_SRV_LOCAL;
            if (bearer_type[sim_id] & SRV_CBM_BEARER_WIFI)
            {
                is_wifi_selected = MMI_TRUE;
            }
        }
    }

    if (is_wifi_selected)
    {
        srv_cbm_mark_common_bearer(bearer_type, SRV_CBM_BEARER_WIFI);
    }

    kal_trace(TRACE_INFO, TRC_SRV_CBM_ALLOW_SIM_CHECK_BEARER_INFO,
        action_type, bearer_type[0], bearer_type[1], bearer_type[2], bearer_type[3]);

    if (action_type == MMI_ABM_NWK_SRV_NONE)
    {
        srv_cbm_allow_bearer(app_p, sim_id, type);
        return SRV_CBM_OK;
    }

    /* send allow gprs&csd activate req to abm */
    srv_cbm_send_nwk_srv_req(MMI_ABM_NWK_SRV_ACTION_ALLOW, action_type, bearer_type);

    /*wait for response. This is blocking API */
    srv_cbm_lock();

    kal_trace(TRACE_FUNC, TRC_SRV_CBM_ALLOW_BEARER_ACTIVATE, g_cbm_srv_cxt_ptr->nwk_srv.result);
    if (g_cbm_srv_cxt_ptr->nwk_srv.result)
    {
        srv_cbm_allow_bearer(app_p, sim_id, type);
        for (i = 0; i < bearer_num; i++)
        {
            g_cbm_srv_cxt_ptr->nwk_srv.disallowed_bearer[i] &= ~bearer_type[i];
        }
        return SRV_CBM_OK;
    }

    return SRV_CBM_ERROR;
#else /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
    return SRV_CBM_ERROR;
#endif /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
}


MMI_BOOL srv_cbm_is_sim_nwk_srv_disallowed(cbm_sim_id_enum sim_id, U32 type)
{
#if defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bearer_num = srv_cbm_get_sim_num();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_id >= bearer_num)
    {
        return MMI_FALSE;
    }

    if (g_cbm_srv_cxt_ptr->nwk_srv.disallowed_bearer[sim_id] & type)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
#else /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
    return MMI_FALSE;
#endif /* defined(__CBM_DISALLOW_NWK_SRV_SUPPRT__) && defined(__TCPIP__) */
}


MMI_BOOL srv_cbm_is_wlan_used_by_app(void)
{
#if defined(__MMI_WLAN_FEATURES__) && defined(__TCPIP__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = abm_is_wifi_used();
    if (ret)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else /* defined(__MMI_WLAN_FEATURES__) && defined(__TCPIP__) */
    return MMI_FALSE;
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__TCPIP__) */
}

