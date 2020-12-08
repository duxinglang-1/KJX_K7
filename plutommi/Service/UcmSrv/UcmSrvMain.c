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
 *  UcmSrvMain.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "CommonScreens.h"
#include "CallLogSrvGprot.h"
#ifdef __MMI_CM_BLACK_LIST__
#include "CallSetSrvGprot.h"
#endif /* __MMI_CM_BLACK_LIST__ */
#ifdef __MMI_AUTO_ANSWER_MACHINE__
#include "AnswerMachineGprot.h"
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */
#include "UcmSrvGprot.h"
#include "UcmSrvIntProt.h"
#include "UcmSrvProt.h"
#include "mmi_rp_srv_ucm_def.h"
#ifdef __MMI_UCM_REJECT_BY_SMS__
#include "SmsSrvGprot.h"
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
#include "App_datetime.h"
#include "Rmmi_common_enum.h"
#include "GlobalResDef.h"
#include "BthScoPathSrvGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "custom_events_notify.h"
#if defined(__KJX_FUN__)
#include "Kjx_prin.h"
#include "TimerEvents.h"
#endif

srv_ucm_cntx_struct g_ucm_srv_cntx;
srv_ucm_cntx_struct *g_ucm_srv_p = &g_ucm_srv_cntx;

/***************************************************************************** 
* External Function
*****************************************************************************/
extern U8 applib_dt_sec_2_mytime(U32 utc_sec, applib_time_struct *result);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_init
 * DESCRIPTION
 *  Initialize UCM service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ucm_init_context();
    srv_ucm_init_protocol_handler();
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_init_context
 * DESCRIPTION
 *  Initialize UCM service context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_init_context()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //memset(&g_ucm_srv_p->call_list, 0, sizeof(srv_ucm_call_list_struct));
    for (i = 0; i < SRV_UCM_MAX_GROUP; i++)
    {
        srv_ucm_reset_group_entry(i);
    }
    
    //memset(&g_ucm_srv_p->call_misc, 0, sizeof(srv_ucm_call_misc_struct));
    srv_ucm_reset_index_list();

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_AUTO_ANSWER_MACHINE__
/* under construction !*/
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */
/* under construction !*/
#ifdef __MMI_UCM_REJECT_BY_SMS__
/* under construction !*/
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
#endif

    //g_ucm_srv_p->act_result_callback = NULL;

    for (i = 0; i < SRV_UCM_TOTAL_CALL_TYPE; i++)
    {
        /* Init call service action callback table, 1 entry for 1 call type */
        g_ucm_srv_p->call_srv_act_cb[i].call_type = (srv_ucm_call_type_enum )(1 << i);
        //g_ucm_srv_p->call_srv_act_cb[i].act_callback = NULL;

        /* Init call service query callback table, 1 entry for 1 call type */
        g_ucm_srv_p->call_srv_query_cb[i].call_type = (srv_ucm_call_type_enum)(1 << i);
        //g_ucm_srv_p->call_srv_query_cb[i].query_callback = NULL;

        /* Init call service permt callback table, call type can be bitwise, reset all entry first */
        g_ucm_srv_p->call_srv_prmt_cb[i].call_type = SRV_UCM_INVALID_CALL_TYPE;
        //g_ucm_srv_p->call_srv_prmt_cb[i].prmt_callback = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_init_protocol_handler
 * DESCRIPTION
 *  Initialize UCM protocol handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_init_protocol_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetProtocolEventHandler(srv_ucm_at_req_ind, MSG_ID_MMI_UCM_AT_REQ_IND);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_log_call_history
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  group_index     [IN]            Group index
 *  call_index      [IN]            Call index
 *  is_connect      [IN]            Call connect or not
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_log_call_history(S32 group_index, S32 call_index, MMI_BOOL is_connect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    srv_clog_log_call_req_struct clog_data;
    U8 clog_num[(SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_clog_init_para(SRV_CLOG_PARA_LOG_CALL_REQ, &clog_data);
    clog_data.cate = SRV_CLOG_CATE_CALL;
    mmi_asc_to_ucs2((CHAR *)clog_num, (CHAR *)g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].remote_info.num_uri);
    clog_data.cid = (WCHAR*)clog_num;
    clog_data.name = (WCHAR*)g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].remote_info.log_name;

    applib_dt_get_rtc_time(&time);
    clog_data.timestamp = applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&time, MMI_FALSE));

    clog_data.phb_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].remote_info.phb_id;
    if (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_origin == SRV_UCM_INT_MO_ORIGIN)
    {
        /* Dialed */
        clog_data.log_type = SRV_CLOG_CLT_DIALED;
    }
    else if (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_origin == SRV_UCM_INT_MT_ORIGIN)
    {
        if (is_connect == MMI_TRUE)
        {
            /* Received */
            clog_data.log_type = SRV_CLOG_CLT_RECVED;
        }
        else
        {
            /* Missed */
            clog_data.log_type = SRV_CLOG_CLT_MISSED;
        }
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if (g_ucm_srv_p->call_list.group_info[group_index].call_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
    {
        clog_data.sim_id = MMI_SIM2;
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (g_ucm_srv_p->call_list.group_info[group_index].call_type == SRV_UCM_VIDEO_CALL_TYPE_SIM2)
        {
            clog_data.sub_type = SRV_CLOG_CALL_TYPE_VIDEO;
        }
        else
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        {
            clog_data.sub_type = SRV_CLOG_CALL_TYPE_VOICE;
        }
    }
    else
#if (MMI_MAX_SIM_NUM >= 3)
    if (g_ucm_srv_p->call_list.group_info[group_index].call_type & SRV_UCM_SIM3_CALL_TYPE_ALL)
    {
        clog_data.sim_id = MMI_SIM3;
        clog_data.sub_type = SRV_CLOG_CALL_TYPE_VOICE;
    }
    else
#if (MMI_MAX_SIM_NUM == 4)
    if (g_ucm_srv_p->call_list.group_info[group_index].call_type & SRV_UCM_SIM4_CALL_TYPE_ALL)
    {
        clog_data.sim_id = MMI_SIM4;
        clog_data.sub_type = SRV_CLOG_CALL_TYPE_VOICE;
    }
    else
#endif  /* (MMI_MAX_SIM_NUM == 4) */
#endif  /* (MMI_MAX_SIM_NUM >= 3) */
#endif  /* (MMI_MAX_SIM_NUM >= 2) */
#ifdef __MMI_VOIP__
    if (g_ucm_srv_p->call_list.group_info[group_index].call_type == SRV_UCM_VOIP_CALL_TYPE)
    {
        clog_data.sub_type = SRV_CLOG_CALL_TYPE_VOIP;
    }
    else
#endif /* __MMI_VOIP__ */
    {
        clog_data.sim_id = MMI_SIM1;
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (g_ucm_srv_p->call_list.group_info[group_index].call_type & SRV_UCM_VIDEO_CALL_TYPE)
        {
            clog_data.sub_type = SRV_CLOG_CALL_TYPE_VIDEO;
        }
        else
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        {
            clog_data.sub_type = SRV_CLOG_CALL_TYPE_VOICE;
        }
    }

    srv_clog_log_call(0,
        0,
        (const srv_clog_log_call_req_struct *)&clog_data,
        &g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].clog_id,
        NULL);
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_set_log_identity_info
 * DESCRIPTION
 *  Set call log identity info when Log call duration
 * PARAMETERS
 *  group_info      [IN]           srv_ucm_group_entry_struct
 *  idt             [IN]           srv_clog_log_identity_struct
 *  call_index      [IN]           U32
 *  is_connect      [IN]           S32
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ucm_set_log_identity_info(const srv_ucm_group_entry_struct *group_info, srv_clog_log_identity_struct *idt, U32 call_index, S32 is_connect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    idt->cate = SRV_CLOG_CATE_CALL;
    if (group_info->call_info[call_index].call_origin == SRV_UCM_INT_MO_ORIGIN)
    {
       /* Dialed */ 
       idt->log_type = SRV_CLOG_CLT_DIALED;
    }
    else if (group_info->call_info[call_index].call_origin == SRV_UCM_INT_MT_ORIGIN)
    {
        if (is_connect == MMI_TRUE)
        {
            /* Received */
            idt->log_type = SRV_CLOG_CLT_RECVED;
        }
        else
        {
            /* Missed */
            idt->log_type = SRV_CLOG_CLT_MISSED;
        }
    }
    
#if (MMI_MAX_SIM_NUM >= 2)
    if (group_info->call_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
    {
        idt->sim_id = MMI_SIM2;
        idt->sub_type = SRV_CLOG_CALL_TYPE_VOICE;
    }
    else
#if (MMI_MAX_SIM_NUM >= 3)
    if (group_info->call_type & SRV_UCM_SIM3_CALL_TYPE_ALL)
    {
        idt->sim_id = MMI_SIM3;
        idt->sub_type = SRV_CLOG_CALL_TYPE_VOICE;
    }
    else
#if (MMI_MAX_SIM_NUM == 4)
    if (group_info->call_type & SRV_UCM_SIM4_CALL_TYPE_ALL)
    {
        idt->sim_id = MMI_SIM4;
        idt->sub_type = SRV_CLOG_CALL_TYPE_VOICE;
    }
    else 
#endif  /* (MMI_MAX_SIM_NUM == 4) */
#endif  /* (MMI_MAX_SIM_NUM >= 3) */
#endif  /* (MMI_MAX_SIM_NUM >= 2) */
#ifdef __MMI_VOIP__
    if (group_info->call_type == SRV_UCM_VOIP_CALL_TYPE)
    {
        idt->sub_type = SRV_CLOG_CALL_TYPE_VOIP;
    }
    else
#endif /* __MMI_VOIP__ */
    {
        idt->sim_id = MMI_SIM1;
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (group_info->call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
        {
            idt->sub_type = SRV_CLOG_CALL_TYPE_VIDEO;
        }
        else
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        {
            idt->sub_type = SRV_CLOG_CALL_TYPE_VOICE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_log_call_duration
 * DESCRIPTION
 *  Log call duration
 * PARAMETERS
 *  group_index      [IN]           Group index
 *  call_index       [IN]           Call index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_log_call_duration(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_log_duration_req_struct clog_duration;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&clog_duration, 0, sizeof(srv_clog_log_duration_req_struct));

    srv_ucm_set_log_identity_info(&g_ucm_srv_p->call_list.group_info[group_index], 
        (srv_clog_log_identity_struct*)&clog_duration, call_index, MMI_TRUE);

    clog_duration.log_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].clog_id;
    clog_duration.duration = g_ucm_srv_p->call_end.call_duration;

    srv_clog_log_duration(0, 0, (const srv_clog_log_duration_req_struct *)&clog_duration, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_call_scenario_control
 * DESCRIPTION
 *  Call scenario control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_call_scenario_control()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_SCENARIO_CONTROL);

    /* Incoming call scenario */
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_UCM_INCOMING_CALL))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_UCM_INCOMING_CALL);
        }
    }
    else
    {
        mmi_frm_end_scenario(MMI_SCENARIO_ID_UCM_INCOMING_CALL);
    }

    /* Outgoing call scenario */
    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_UCM_OUTGOING_CALL))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_UCM_OUTGOING_CALL);
        }
    }
    else
    {
        mmi_frm_end_scenario(MMI_SCENARIO_ID_UCM_OUTGOING_CALL);
    }

    /* In call scenario */
    if ((srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) &&
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) &&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) > 0))
    {
        if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_IN_CALL);
        }
    }
    else
    {
        mmi_frm_end_scenario(MMI_SCENARIO_ID_IN_CALL);
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_dial_action
 * DESCRIPTION
 *  Implement of SRV_UCM_DIAL_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_dial_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    S32 free_group = g_ucm_srv_p->call_list.num_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    g_ucm_srv_p->call_list.group_info[free_group].group_id = SRV_UCM_INVALID_ID;
    g_ucm_srv_p->call_list.group_info[free_group].call_info[0].call_id = SRV_UCM_INVALID_ID;
    g_ucm_srv_p->call_list.group_info[free_group].call_type = g_ucm_srv_p->dial_info.dial_type;
    g_ucm_srv_p->call_list.group_info[free_group].call_state = SRV_UCM_OUTGOING_STATE;
    memcpy(&g_ucm_srv_p->call_list.group_info[free_group].call_info[0].remote_info.num_uri, &g_ucm_srv_p->dial_info.num_uri, SRV_UCM_MAX_NUM_URI_LEN);
    g_ucm_srv_p->call_list.group_info[free_group].call_info[0].call_origin = SRV_UCM_INT_MO_ORIGIN;
    g_ucm_srv_p->call_list.group_info[free_group].call_info[0].module_id = g_ucm_srv_p->dial_info.module_id;
    memcpy(&g_ucm_srv_p->call_list.group_info[free_group].call_info[0].at_info, &g_ucm_srv_p->call_misc.at_info, sizeof(srv_ucm_int_at_info_struct));
    g_ucm_srv_p->call_list.group_info[free_group].call_info[0].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[free_group].call_info[0].act_type = SRV_UCM_DIAL_ACT;
    g_ucm_srv_p->call_list.group_info[free_group].num_call++;
    g_ucm_srv_p->call_list.num_group++;

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[free_group].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[free_group].group_id;
    srv_ucm_int_act_request(SRV_UCM_INT_DIAL_ACT, &action_id, NULL, &g_ucm_srv_p->dial_info);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_dial_act_rsp
 * DESCRIPTION
 *  Handler for dial action response.
 * PARAMETERS
 *  rsp_struct      [IN]            Action response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_dial_act_rsp(void *rsp_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0;
    srv_ucm_act_rsp_struct rsp;
    srv_ucm_outgoing_call_ind_struct outgoing_call_ind;
    srv_ucm_int_dial_act_rsp_struct *int_rsp = (srv_ucm_int_dial_act_rsp_struct*)rsp_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_ucm_srv_p->dial_info.is_wait_dial = MMI_FALSE;

    memset(&rsp, 0, sizeof(srv_ucm_act_rsp_struct));

    if ((int_rsp->result_info.result == SRV_UCM_RESULT_OK) &&
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))
    {
        if (srv_ucm_at_check())
        {
            if (g_ucm_srv_p->call_misc.no_rcode_count == 0)
            {
                if (g_ucm_srv_p->dial_info.dial_type & SRV_UCM_VOICE_CALL_TYPE_ALL)
                {
                    srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_OK, SRV_UCM_INVALID_ID, &g_ucm_srv_p->call_misc.at_info);
                }
                else if (g_ucm_srv_p->dial_info.dial_type & SRV_UCM_DATA_CALL_TYPE_ALL)
                {
                    srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_CONNECT, SRV_UCM_INVALID_ID, &g_ucm_srv_p->call_misc.at_info);
                }
                else
                {
                    MMI_ASSERT(0);
                }
                memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
                g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            }
            else
            {
                g_ucm_srv_p->call_misc.no_rcode_count--;
            }
        }

        /* Update invalid id entry */
        srv_ucm_sync_call_list(int_rsp->call_list);

        memcpy(&g_ucm_srv_p->mo_mt_display, &int_rsp->display_info, sizeof(srv_ucm_display_info_struct));

        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_COMP_PROCESS_STATE);
        
        /* Dial is always the second action of a compound action */
        MMI_ASSERT(srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list) == 0);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        /* Only one outgoing call exists */
        if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == 1)
        {
            /* Do not suspend Alarm or background play for csd outgoing call */
            if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) == 0)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_SUSPEND_BACKGROUND_PLAY);
                mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM);
            }
        }

        /* Outgoing call indication */
        memset(&outgoing_call_ind, 0, sizeof(srv_ucm_outgoing_call_ind_struct));
        memcpy(&outgoing_call_ind.display_info, &int_rsp->display_info, sizeof(srv_ucm_display_info_struct));
        memcpy(&outgoing_call_ind.remote_info, &int_rsp->remote_info, sizeof(srv_ucm_remote_info_struct));
        memcpy(&outgoing_call_ind.uid_info, &int_rsp->uid_info, sizeof(srv_ucm_id_info_struct));
        outgoing_call_ind.module_id = g_ucm_srv_p->dial_info.module_id;
        srv_ucm_send_indication(SRV_UCM_OUTGOING_CALL_IND, (void *)&outgoing_call_ind);
        
        /* Action notify */
        rsp.result_info.result = SRV_UCM_RESULT_OK;
    }
    else
    {
        if ((int_rsp->result_info.result == SRV_UCM_RESULT_OK) &&
            (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
        {
            rsp.result_info.result = SRV_UCM_RESULT_UCM_BUSY;
            mmi_ucs2ncpy((CHAR *)rsp.result_info.error_msg, (CHAR *)GetString(srv_ucm_query_error_message(rsp.result_info.result)), SRV_UCM_MAX_ERR_MSG_LEN);

            /* Auto reject the outgoing call when collision with incoming call */
            srv_ucm_int_act_request(SRV_UCM_INT_AUTO_REJECT_ACT, &(int_rsp->uid_info), NULL, NULL);
            srv_ucm_int_act_request(SRV_UCM_INT_FORCE_RELEASE_ACT, &(int_rsp->uid_info), NULL, NULL);
        }

        /* no matter what the no_rcode_count is, send back the result code because the action terminated */
        if (srv_ucm_at_check())
        {
            srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_NO_CARRIER, SRV_UCM_INVALID_ID, &g_ucm_srv_p->call_misc.at_info);
            memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
            g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            g_ucm_srv_p->call_misc.no_rcode_count = 0;
        }
        
        /* clear invalid id entry */
        srv_ucm_sync_call_list(int_rsp->call_list);

        if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
        {
            /* Call service does not have this call yet, so cannot rely on call list of call service */
            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;

            if (g_ucm_srv_p->call_list.group_info[group_index].call_info[0].proc_state == SRV_UCM_DO_PROCESS_STATE)
            {
                g_ucm_srv_p->call_list.group_info[group_index].num_call--;
                g_ucm_srv_p->call_list.num_group--;
                srv_ucm_reset_group_entry(group_index);
                srv_ucm_call_status_change_callback();
            }
        }
        
        srv_ucm_set_process_state(-1, -1, SRV_UCM_WAIT_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        if ((int_rsp->result_info.result == SRV_UCM_RESULT_UNSPECIFIED_ERROR) && (int_rsp->result_info.error_msg == NULL))
        {
            /* Special handling for SS, result is ok, but no outoging call indication */
            rsp.result_info.result = SRV_UCM_RESULT_OK;
        }
        else if (int_rsp->result_info.result != SRV_UCM_RESULT_OK)
        {
            memcpy(&rsp.result_info, &int_rsp->result_info, sizeof(srv_ucm_result_info_struct));
        }
    }

    /* Action notify */
    srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_DIAL_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

    /* Compound action notify */
    if (g_ucm_srv_p->call_misc.curr_action != SRV_UCM_DIAL_ACT)
    {
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, g_ucm_srv_p->call_misc.curr_action, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);
    }

    /* Action response callback */
    srv_ucm_send_act_response(g_ucm_srv_p->call_misc.curr_action, (void *)&rsp);

    memset(&g_ucm_srv_p->dial_info, 0, sizeof(srv_ucm_dial_info_struct));
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_accept_action
 * DESCRIPTION
 *  Implement of SRV_UCM_ACCEPT_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_accept_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    S32 group_index = 0, call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;

    /* Add call info to call table */
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].act_type = SRV_UCM_ACCEPT_ACT;

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
    srv_ucm_int_act_request(SRV_UCM_INT_ACCEPT_ACT, &action_id, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_accept_act_rsp
 * DESCRIPTION
 *  Handler for accept action response
 * PARAMETERS
 *  rsp_struct      [IN]            Action response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_accept_act_rsp(void *rsp_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0;
    srv_ucm_act_rsp_struct rsp;
    srv_ucm_int_act_rsp_struct *int_rsp = (srv_ucm_int_act_rsp_struct*)rsp_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&rsp, 0, sizeof(srv_ucm_act_rsp_struct));

    if (int_rsp->result_info.result == SRV_UCM_RESULT_OK)
    {
        /* received call log */        
        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;

        kal_get_time(&g_ucm_srv_p->call_list.group_info[group_index].call_info[0].start_tick_time);
        DTGetRTCTime(&g_ucm_srv_p->call_list.group_info[group_index].call_info[0].start_time); 
        
        /* Don't log the call for SAT */
        if ((g_ucm_srv_p->call_list.group_info[group_index].call_info[0].module_id != SRV_UCM_MODULE_ORIGIN_SAT) &&
            (int_rsp->no_counter == MMI_FALSE))
        {
            srv_ucm_log_call_history(group_index, 0, MMI_TRUE);
        }

        if (srv_ucm_at_check())
        {
            if (g_ucm_srv_p->call_misc.no_rcode_count == 0)
            {
                srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_OK, (U8)g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id, &g_ucm_srv_p->call_misc.at_info);
                memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
                g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            }
            else
            {
                g_ucm_srv_p->call_misc.no_rcode_count--;
            }
        }

        srv_ucm_sync_call_list(int_rsp->call_list);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_COMP_PROCESS_STATE);

        /* Accept is always the second action of a compound action */
        MMI_ASSERT(srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list) == 0);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        /* Action notify */
        rsp.result_info.result = SRV_UCM_RESULT_OK;
        if (int_rsp->no_counter == MMI_TRUE)
        {
            g_ucm_srv_p->call_misc.is_count_stopped = MMI_TRUE;
        }
        else
        {
            g_ucm_srv_p->call_misc.is_count_stopped = MMI_FALSE;
        }
        rsp.no_counter = int_rsp->no_counter;
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_ACCEPT_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

        /* Compound action notify */
        if (g_ucm_srv_p->call_misc.curr_action != SRV_UCM_ACCEPT_ACT)
        {
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, g_ucm_srv_p->call_misc.curr_action, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);
        }

        /* Action response callback */
        srv_ucm_send_act_response(g_ucm_srv_p->call_misc.curr_action, (void *)&rsp);

    #ifdef __MMI_AUTO_ANSWER_MACHINE__
        if (srv_ucm_autoam_get_state() == SRV_UCM_AUTOAM_STATE_READY)
        {
            StartTimer(UCM_AUTO_ANSWER_MACHINE_TIMER, 1, srv_ucm_autoam_start);
        }
        else
        {
            srv_ucm_autoam_reset_cntx();
        }
    #endif /* __MMI_AUTO_ANSWER_MACHINE__ */    
    }
    else
    {
        /* No matter what the no_rcode_count is, send back the result code because the action terminated */
        if (srv_ucm_at_check())
        {
            srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_ERROR, SRV_UCM_INVALID_ID, &g_ucm_srv_p->call_misc.at_info);
            memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
            g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            g_ucm_srv_p->call_misc.no_rcode_count = 0;
        }

        srv_ucm_sync_call_list(int_rsp->call_list);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_WAIT_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        /* Action notify */
        memcpy(&rsp.result_info, &int_rsp->result_info, sizeof(srv_ucm_result_info_struct));
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_ACCEPT_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

        /* Compound action notify */
        if (g_ucm_srv_p->call_misc.curr_action != SRV_UCM_ACCEPT_ACT)
        {
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, g_ucm_srv_p->call_misc.curr_action, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);
        }
        
        /* Action response callback */
        srv_ucm_send_act_response(g_ucm_srv_p->call_misc.curr_action, (void *)&rsp);

    #ifdef __MMI_AUTO_ANSWER_MACHINE__
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_START_FAIL);
        srv_ucm_autoam_reset_cntx();
    #endif /* __MMI_AUTO_ANSWER_MACHINE__ */

    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_hold_action
 * DESCRIPTION
 *  Implement of SRV_UCM_HOLD_ACT
 * PARAMETERS
 *  group_index      [IN]            group index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_hold_action(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    S32 call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
    {
        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_HOLD_ACT;
    }

    /* AT doesn' need to know there is Hold action */
    if ((g_ucm_srv_p->dial_info.is_wait_dial == MMI_TRUE) &&
        (srv_ucm_at_check()))
    {
        g_ucm_srv_p->call_misc.no_rcode_count++;
    }

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    srv_ucm_int_act_request(SRV_UCM_INT_HOLD_ACT, &action_id, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_retrieve_action
 * DESCRIPTION
 *  Implement of SRV_UCM_RETRIEVE_ACT
 * PARAMETERS
 *  group_index      [IN]            group index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_retrieve_action(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    S32 call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
    {
        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_RETRIEVE_ACT;
    }

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    srv_ucm_int_act_request(SRV_UCM_INT_RETRIEVE_ACT, &action_id, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_conference_action
 * DESCRIPTION
 *  Implement of SRV_UCM_CONFERENCE_ACT
 * PARAMETERS
 *  active_group_index       [IN]            active group index
 *  held_group_index         [IN]            held group index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_conference_action(S32 active_group_index, S32 held_group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    srv_ucm_id_info_struct other_id;
    S32 call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[active_group_index].num_call; call_index++)
    {
        g_ucm_srv_p->call_list.group_info[active_group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
        g_ucm_srv_p->call_list.group_info[active_group_index].call_info[call_index].act_type = SRV_UCM_CONFERENCE_ACT;
    }
    for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[held_group_index].num_call; call_index++)
    {
        g_ucm_srv_p->call_list.group_info[held_group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
        g_ucm_srv_p->call_list.group_info[held_group_index].call_info[call_index].act_type = SRV_UCM_CONFERENCE_ACT;
    }

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    memset(&other_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[active_group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[active_group_index].group_id;
    other_id.call_type = g_ucm_srv_p->call_list.group_info[held_group_index].call_type;
    other_id.group_id = g_ucm_srv_p->call_list.group_info[held_group_index].group_id;
    srv_ucm_int_act_request(SRV_UCM_INT_CONFERENCE_ACT, &action_id, &other_id, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_split_action
 * DESCRIPTION
 *  Implement of SRV_UCM_SPLIT_ACT
 * PARAMETERS
 *  group_index       [IN]            group index
 *  call_index        [IN]            call index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_split_action(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (index = 0; index < g_ucm_srv_p->call_list.group_info[group_index].num_call; index++)
    {
        g_ucm_srv_p->call_list.group_info[group_index].call_info[index].proc_state = SRV_UCM_DO_PROCESS_STATE;
        g_ucm_srv_p->call_list.group_info[group_index].call_info[index].act_type = SRV_UCM_SPLIT_ACT;
    }

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
    srv_ucm_int_act_request(SRV_UCM_INT_SPLIT_ACT, &action_id, NULL, NULL);
}

#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_deflect_action
 * DESCRIPTION
 *  Implement of SRV_UCM_DEFLECT_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_deflect_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    S32 group_index = 0, call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;

    /* Add call info to call table */
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].act_type = SRV_UCM_DEFLECT_ACT;

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
    srv_ucm_int_act_request(SRV_UCM_INT_DEFLECT_ACT, &action_id, NULL, &g_ucm_srv_p->dial_info);
}
#endif /* __MMI_UCM_DEFLECT__ */

#ifdef __MMI_UCM_TRANSFER__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_transfer_action
 * DESCRIPTION
 *  Implement of SRV_UCM_TRANSFER_ACT
 * PARAMETERS
 *  group_index       [IN]            group index
 *  call_index        [IN]            call index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_transfer_action(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].act_type = SRV_UCM_TRANSFER_ACT;

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
    srv_ucm_int_act_request(SRV_UCM_INT_TRANSFER_ACT, &action_id, NULL, &g_ucm_srv_p->dial_info);
}
#endif /* __MMI_UCM_TRANSFER__ */

#ifdef __MMI_UCM_ECT__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_ect_action
 * DESCRIPTION
 *  Implement of SRV_UCM_ECT_ACT
 * PARAMETERS
 *  first_group_index      [IN]            first group index
 *  second_group_index     [IN]            second group index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_ect_action(S32 first_group_index, S32 second_group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    srv_ucm_id_info_struct other_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    g_ucm_srv_p->call_list.group_info[first_group_index].call_info[0].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[first_group_index].call_info[0].act_type = SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT;
    g_ucm_srv_p->call_list.group_info[second_group_index].call_info[0].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[second_group_index].call_info[0].act_type = SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT;

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    memset(&other_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[first_group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[first_group_index].group_id;
    other_id.call_type = g_ucm_srv_p->call_list.group_info[second_group_index].call_type;
    other_id.group_id = g_ucm_srv_p->call_list.group_info[second_group_index].group_id;
    srv_ucm_int_act_request(SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT, &action_id, &other_id, NULL);
}
#endif /* __MMI_UCM_ECT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_act_rsp
 * DESCRIPTION
 *  Handler for action response
 * PARAMETERS
 *  rsp_struct      [IN]            Action response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_act_rsp(srv_ucm_int_act_opcode_enum int_op_code, void *rsp_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0;
    srv_ucm_id_info_struct action_id;
    srv_ucm_act_rsp_struct rsp;
    srv_ucm_int_act_rsp_struct *int_rsp = (srv_ucm_int_act_rsp_struct*)rsp_struct;
    srv_ucm_act_opcode_enum op_code = srv_ucm_query_act_op(int_op_code);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&rsp, 0, sizeof(srv_ucm_act_rsp_struct));

    if (int_rsp->result_info.result == SRV_UCM_RESULT_OK)
    {
        if (srv_ucm_at_check())
        {
            if (g_ucm_srv_p->call_misc.no_rcode_count == 0)
            {
                srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_OK, (U8)g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id, &g_ucm_srv_p->call_misc.at_info);
                memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
                g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            }
            else
            {
                g_ucm_srv_p->call_misc.no_rcode_count--;
            }
        }

        srv_ucm_sync_call_list(int_rsp->call_list);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_COMP_PROCESS_STATE);
 
        if (srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list) != 0)
        {
            /* Action notify for the first action in compound action */
            rsp.result_info.result = SRV_UCM_RESULT_OK;
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

            /* Continue to perform waiting action */
            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
            call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
            srv_ucm_set_process_state(group_index, -1, SRV_UCM_WAIT_PROCESS_STATE, SRV_UCM_DO_PROCESS_STATE);
            action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
            action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
            action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
            srv_ucm_int_act_request(srv_ucm_query_int_act_op(g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type),
                &action_id,
                NULL,
                NULL);
        }
        else if (g_ucm_srv_p->dial_info.is_wait_dial == MMI_TRUE)
        {
            /* Action notify for the first action in compound action */
            rsp.result_info.result = SRV_UCM_RESULT_OK;
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

            /* Perform dial action */
            srv_ucm_dial_action();
        }
        else
        {
            /* No waiting action, set action state to IDLE */
            srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

            /* Action notify */
            rsp.result_info.result = SRV_UCM_RESULT_OK;
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

            /* Compound action notify */
            if (g_ucm_srv_p->call_misc.curr_action != op_code)
            {
                srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, g_ucm_srv_p->call_misc.curr_action, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);        
            }

            /* Action response callback */
            srv_ucm_send_act_response(g_ucm_srv_p->call_misc.curr_action, (void *)&rsp);
        }
    }
    else
    {
        /* No matter what the no_rcode_count is, send back the result code because the action terminated */
        if (srv_ucm_at_check())
        {
            srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_ERROR, SRV_UCM_INVALID_ID, &g_ucm_srv_p->call_misc.at_info);
            memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
            g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            g_ucm_srv_p->call_misc.no_rcode_count = 0;
        }

        srv_ucm_sync_call_list(int_rsp->call_list);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_WAIT_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        /* Action notify */
        memcpy(&rsp.result_info, &int_rsp->result_info, sizeof(srv_ucm_result_info_struct));
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

        /* Compound action notify */
        if (g_ucm_srv_p->call_misc.curr_action != op_code)
        {
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, g_ucm_srv_p->call_misc.curr_action, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);        
        }

        /* Action response callback */
        srv_ucm_send_act_response(g_ucm_srv_p->call_misc.curr_action, (void *)&rsp);

        /* First action failed, no need to perform second DIAL_ACT */
        if (g_ucm_srv_p->dial_info.is_wait_dial == MMI_TRUE)
        {
            g_ucm_srv_p->dial_info.is_wait_dial = MMI_FALSE;
            srv_ucm_call_status_change_callback();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_swap_action
 * DESCRIPTION
 *  Implement of SRV_UCM_SWAP_ACT
 * PARAMETERS
 *  active_group_index      [IN]            active group index
 *  held_group_index         [IN]            held group index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_swap_action(S32 active_group_index, S32 held_group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    srv_ucm_id_info_struct other_id;
    S32 call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_ucm_srv_p->call_list.group_info[active_group_index].call_type & g_ucm_srv_p->call_list.group_info[held_group_index].call_type)
    {
        /* Same call type, add call info to call table */
        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[active_group_index].num_call; call_index++)
        {
            g_ucm_srv_p->call_list.group_info[active_group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
            g_ucm_srv_p->call_list.group_info[active_group_index].call_info[call_index].act_type = SRV_UCM_SWAP_ACT;
        }
        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[held_group_index].num_call; call_index++)
        {
            g_ucm_srv_p->call_list.group_info[held_group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
            g_ucm_srv_p->call_list.group_info[held_group_index].call_info[call_index].act_type = SRV_UCM_SWAP_ACT;
        }

        /* Send request to call service */
        memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
        memset(&other_id, 0, sizeof(srv_ucm_id_info_struct));
        action_id.call_type = g_ucm_srv_p->call_list.group_info[active_group_index].call_type;
        action_id.group_id = g_ucm_srv_p->call_list.group_info[active_group_index].group_id;
        other_id.call_type = g_ucm_srv_p->call_list.group_info[held_group_index].call_type;
        other_id.group_id = g_ucm_srv_p->call_list.group_info[held_group_index].group_id;
        srv_ucm_int_act_request(SRV_UCM_INT_SWAP_ACT, &action_id, &other_id, NULL);
    }
    else
    {
        /* Different call type, add call info to call table */
        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[active_group_index].num_call; call_index++)
        {
            g_ucm_srv_p->call_list.group_info[active_group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
            g_ucm_srv_p->call_list.group_info[active_group_index].call_info[call_index].act_type = SRV_UCM_HOLD_ACT;
        }

        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[held_group_index].num_call; call_index++)
        {
            g_ucm_srv_p->call_list.group_info[held_group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
            g_ucm_srv_p->call_list.group_info[held_group_index].call_info[call_index].act_type = SRV_UCM_RETRIEVE_ACT;
        }

        /* AT doesn't need to know there is HOLD action */
        if (srv_ucm_at_check())
        {
            g_ucm_srv_p->call_misc.no_rcode_count++;
        }

        /* Send request to call service */
        memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
        action_id.call_type = g_ucm_srv_p->call_list.group_info[active_group_index].call_type;
        action_id.group_id = g_ucm_srv_p->call_list.group_info[active_group_index].group_id;
        srv_ucm_int_act_request(SRV_UCM_INT_HOLD_ACT, &action_id, NULL, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_swap_act_rsp
 * DESCRIPTION
 *  Handler for swap response
 * PARAMETERS
 *  rsp_struct      [IN]            Action response structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_swap_act_rsp(void *rsp_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0;
    srv_ucm_act_rsp_struct rsp;
    srv_ucm_int_act_rsp_struct *int_rsp = (srv_ucm_int_act_rsp_struct*)rsp_struct;
    srv_ucm_single_group_act_req_struct single_group_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&rsp, 0, sizeof(srv_ucm_act_rsp_struct));

    if (int_rsp->result_info.result == SRV_UCM_RESULT_OK)
    {
        if (srv_ucm_at_check())
        {
            if (g_ucm_srv_p->call_misc.no_rcode_count == 0)
            {
                srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_OK, (U8)g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id, &g_ucm_srv_p->call_misc.at_info);
                memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
                g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            }
            else
            {
                g_ucm_srv_p->call_misc.no_rcode_count--;
            }
        }

        srv_ucm_sync_call_list(int_rsp->call_list);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_COMP_PROCESS_STATE);

        /* Swap is always the second action of a compound action */
        MMI_ASSERT(srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list) == 0);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        /* Action notify */
        rsp.result_info.result = SRV_UCM_RESULT_OK;

        /* Action notify for HOLD_ACT end */
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_HOLD_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

        /* Action notify for RETRIEVE_ACT start */
        srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
        memset(&single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
        single_group_req.call_type = g_ucm_srv_p->call_list.group_info[g_ucm_srv_p->call_misc.index_list[0].group_index].call_type;
        single_group_req.action_group = g_ucm_srv_p->call_list.group_info[g_ucm_srv_p->call_misc.index_list[0].group_index].group_id;
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_RETRIEVE_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, (void *)&single_group_req);

        /* Action notify for RETRIEVE_ACT end */
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_RETRIEVE_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

        /* Action notify for SWAP_ACT end */
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_SWAP_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

        /* Action response callback */
        srv_ucm_send_act_response(g_ucm_srv_p->call_misc.curr_action, (void *)&rsp);
    }
    else
    {
        /* No matter what the no_rcode_count is, send back the result code because the action terminated */
        if (srv_ucm_at_check())
        {
            srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_ERROR, SRV_UCM_INVALID_ID, &g_ucm_srv_p->call_misc.at_info);
            memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
            g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            g_ucm_srv_p->call_misc.no_rcode_count = 0;
        }

        srv_ucm_sync_call_list(int_rsp->call_list);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_WAIT_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        memcpy(&rsp.result_info, &int_rsp->result_info, sizeof(srv_ucm_result_info_struct));

        /* Action notify for HOLD_ACT end */
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_HOLD_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

        /* Action notify for SWAP_ACT end */
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_SWAP_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

        /* Action response callback */
        srv_ucm_send_act_response(g_ucm_srv_p->call_misc.curr_action, (void *)&rsp);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_single_action
 * DESCRIPTION
 *  Implement of SRV_UCM_END_SINGLE_ACT
 * PARAMETERS
 *  group_index       [IN]            group index
 *  call_index        [IN]            call index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_single_action(S32 group_index, S32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_SINGLE_ACT;

    /* Send request to call service */
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
    srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_conference_action
 * DESCRIPTION
 *  Implement of SRV_UCM_END_CONFERENCE_ACT
 * PARAMETERS
 *  group_index      [IN]            group index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_conference_action(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    S32 call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
    {
        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_CONFERENCE_ACT;
    }

    /* Send request to call service */
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    srv_ucm_int_act_request(SRV_UCM_INT_END_CONFERENCE_ACT, &action_id, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_all_action
 * DESCRIPTION
 *  Implement of SRV_UCM_END_ALL_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_all_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0, total_num = 0, i = 0;
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_ALL_ACT;
        }
    }

    /* Send request to call service */
    srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    srv_ucm_int_act_request(SRV_UCM_INT_END_ALL_ACT, &action_id, NULL, NULL);

    /* Same call types, the state should be DO_PROCESS_STATE */
    total_num = srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);    
    for (i = 1; i < total_num; i++)
    {
        group_index = g_ucm_srv_p->call_misc.index_list[i].group_index;
        call_index = g_ucm_srv_p->call_misc.index_list[i].call_index;

        if (g_ucm_srv_p->call_list.group_info[group_index].call_type == action_id.call_type)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
        }
    }

    /* AT doesn't need to know there are END_ALL actions, should revise to more general design in the future */
    if ((g_ucm_srv_p->dial_info.is_wait_dial == MMI_TRUE) &&
        (srv_ucm_at_check()))
    {
        for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
        {
           if (g_ucm_srv_p->call_list.group_info[group_index].call_type & SRV_UCM_SIM1_CALL_TYPE_ALL)
           {
               g_ucm_srv_p->call_misc.no_rcode_count++;
               break;
           }
        }

        for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
        {
           if (g_ucm_srv_p->call_list.group_info[group_index].call_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
           {
               g_ucm_srv_p->call_misc.no_rcode_count++;
               break;
           }
        }

        for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
        {
           if (g_ucm_srv_p->call_list.group_info[group_index].call_type & SRV_UCM_VOIP_CALL_TYPE)
           {
               g_ucm_srv_p->call_misc.no_rcode_count++;
               break;
           }
        }
    }
}

#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_all_action
 * DESCRIPTION
 *  Implement of SRV_UCM_END_ALL_ACTIVE_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_all_active_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0, i = 0;
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        if (g_ucm_srv_p->call_list.group_info[group_index].call_state == SRV_UCM_ACTIVE_STATE)
        {
            for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
            {
                if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
                {
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_SINGLE_ACT;
                }
                else if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                {
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_CONFERENCE_ACT;
                }
            }
        }
    }

    /* Send request to call service */
    srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
    if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
    }
    else
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_CONFERENCE_ACT, &action_id, NULL, NULL);

        /* Same group, the state should be DO_PROCESS_STATE */
        for (i = 1; i < g_ucm_srv_p->call_list.group_info[group_index].num_call; i++)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[i].proc_state = SRV_UCM_DO_PROCESS_STATE;
        }
    }
}
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__ */

#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_all_held_action
 * DESCRIPTION
 *  Implement of SRV_UCM_END_ALL_HELD_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_all_held_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0, i = 0;
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        if (g_ucm_srv_p->call_list.group_info[group_index].call_state == SRV_UCM_HOLD_STATE)
        {
            for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
            {
                if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
                {
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_SINGLE_ACT;
                }
                else if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                {
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_CONFERENCE_ACT;
                }
            }
        }
    }

    /* Send request to call service */
    srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
    if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
    }
    else
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_CONFERENCE_ACT, &action_id, NULL, NULL);

        /* Same group, the state should be DO_PROCESS_STATE */
        for (i = 1; i < g_ucm_srv_p->call_list.group_info[group_index].num_call; i++)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[i].proc_state = SRV_UCM_DO_PROCESS_STATE;
        }
    }
}
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_all_processing_action
 * DESCRIPTION
 *  Implement of SRV_UCM_END_ALL_PROCESSING_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_all_processing_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0, total_num = 0, i = 0;
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* AT command is terminated, send error code to RMMI */
    if (srv_ucm_at_check())
    {
        srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_ERROR, SRV_UCM_INVALID_ID, &g_ucm_srv_p->call_misc.at_info);
        memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
        g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
        g_ucm_srv_p->call_misc.no_rcode_count = 0;
    }

    g_ucm_srv_p->call_misc.end_processing_count = 0;
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    g_ucm_srv_p->dial_info.is_wait_dial = MMI_FALSE;
    g_ucm_srv_p->call_misc.is_dtmf_start = MMI_FALSE;
    StopTimer(UCM_SEND_DTMF_TIMER);

    /* Action start notify */
    srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, SRV_UCM_END_ALL_PROCESSING_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, NULL);

    /* End all calls in DO_STATE */
    total_num = srv_ucm_get_process_state(SRV_UCM_DO_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    for (i = 0; i < total_num; i++)
    {
        group_index = g_ucm_srv_p->call_misc.index_list[i].group_index;
        call_index = g_ucm_srv_p->call_misc.index_list[i].call_index;

        memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
        action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
        action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
        action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;

        if ((g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type == SRV_UCM_END_SINGLE_ACT) || 
            (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type == SRV_UCM_END_CONFERENCE_ACT) || 
            (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type == SRV_UCM_END_ALL_ACT))
        {
            g_ucm_srv_p->call_misc.end_processing_count++;
            srv_ucm_int_act_request(SRV_UCM_INT_FORCE_RELEASE_ACT, &action_id, NULL, NULL);
        }
        else
        {
            g_ucm_srv_p->call_misc.end_processing_count++;
            srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
            srv_ucm_int_act_request(SRV_UCM_INT_FORCE_RELEASE_ACT, &action_id, NULL, NULL);
        }
    }

    /* End all calls in COMPLETE_STATE */
    total_num = srv_ucm_get_process_state(SRV_UCM_COMP_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    for (i = 0; i < total_num; i++)
    {
        group_index = g_ucm_srv_p->call_misc.index_list[i].group_index;
        call_index = g_ucm_srv_p->call_misc.index_list[i].call_index;

        memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
        action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
        action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
        action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;

        g_ucm_srv_p->call_misc.end_processing_count++;
        srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
        srv_ucm_int_act_request(SRV_UCM_INT_FORCE_RELEASE_ACT, &action_id, NULL, NULL);
    }

    /* End all calls in WAIT_STATE */
    total_num = srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    for (i = 0; i < total_num; i++)
    {
        group_index = g_ucm_srv_p->call_misc.index_list[i].group_index;
        call_index = g_ucm_srv_p->call_misc.index_list[i].call_index;

        memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
        action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
        action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
        action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;

        g_ucm_srv_p->call_misc.end_processing_count++;
        srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
        srv_ucm_int_act_request(SRV_UCM_INT_FORCE_RELEASE_ACT, &action_id, NULL, NULL);
    }

    /* End all calls during disconnecting by remote */
    total_num = srv_ucm_query_disconnecting_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
    for (i = 0; i < total_num; i++)
    {
        group_index = g_ucm_srv_p->call_misc.index_list[i].group_index;
        call_index = g_ucm_srv_p->call_misc.index_list[i].call_index;

        if (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state == SRV_UCM_IDLE_PROCESS_STATE)
        {
            memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
            action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
            action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
            action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;

            g_ucm_srv_p->call_misc.end_processing_count++;
            srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
            srv_ucm_int_act_request(SRV_UCM_INT_FORCE_RELEASE_ACT, &action_id, NULL, NULL);
        }
    }
}

#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_all_and_accept_action
 * DESCRIPTION
 *  Implement of SRV_UCM_END_ALL_AND_ACCEPT_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_all_and_accept_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0, i = 0;
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_SINGLE_ACT;
        }
        else if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_CONFERENCE_ACT;
        }
    }

    /* Send request to call service */
    srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;

    if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
    }
    else
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_CONFERENCE_ACT, &action_id, NULL, NULL);

        /* Same group, the state should be DO_PROCESS_STATE */
        for (i = 1; i < g_ucm_srv_p->call_list.group_info[group_index].num_call; i++)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[i].proc_state = SRV_UCM_DO_PROCESS_STATE;
        }
    }

    /* Add accept action info to call table */
    srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].act_type = SRV_UCM_ACCEPT_ACT;
}
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__ */

#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_all_active_and_retrieve_action
 * DESCRIPTION
 *  Implement of SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT
 * PARAMETERS
 *  held_group_index      [IN]         held group index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_all_active_and_retrieve_action(S32 held_group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0, i = 0;
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        if (g_ucm_srv_p->call_list.group_info[group_index].call_state == SRV_UCM_ACTIVE_STATE)
        {
            for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
            {
                if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
                {
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_SINGLE_ACT;
                }
                else if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                {
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_CONFERENCE_ACT;
                }
            }
        }
    }

    /* Send request to call service */
    srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;

    if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
    }
    else
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_CONFERENCE_ACT, &action_id, NULL, NULL);

        /* Same group, the state should be DO_PROCESS_STATE */
        for (i = 1; i < g_ucm_srv_p->call_list.group_info[group_index].num_call; i++)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[i].proc_state = SRV_UCM_DO_PROCESS_STATE;
        }
    }

    /* Add retrieve action info to call table */
    g_ucm_srv_p->call_list.group_info[held_group_index].call_info[0].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[held_group_index].call_info[0].act_type = SRV_UCM_RETRIEVE_ACT;

    /* AT doesn't need to know there is END_ALL_ACTIVE action */
    if (srv_ucm_at_check())
    {
        g_ucm_srv_p->call_misc.no_rcode_count++;
    }
}
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_all_active_and_accept_action
 * DESCRIPTION
 *  Implement of SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_all_active_and_accept_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0, i = 0;
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        if (g_ucm_srv_p->call_list.group_info[group_index].call_state == SRV_UCM_ACTIVE_STATE)
        {
            for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
            {
                if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
                {
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_SINGLE_ACT;
                }
                else if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                {
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
                    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_CONFERENCE_ACT;
                }
            }
        }
    }

    /* Send request to call service */
    srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;

    if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_SINGLE_ACT, &action_id, NULL, NULL);
    }
    else
    {
        srv_ucm_int_act_request(SRV_UCM_INT_END_CONFERENCE_ACT, &action_id, NULL, NULL);

        /* Same group, the state should be DO_PROCESS_STATE */
        for (i = 1; i < g_ucm_srv_p->call_list.group_info[group_index].num_call; i++)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[i].proc_state = SRV_UCM_DO_PROCESS_STATE;
        }
    }

    /* Add accept action info to call table */
    srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;

    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].act_type = SRV_UCM_ACCEPT_ACT;

    /* AT doesn't need to know there is END_ALL_ACTIVE action */
    if (srv_ucm_at_check())
    {
        g_ucm_srv_p->call_misc.no_rcode_count++;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_hold_and_accept_action
 * DESCRIPTION
 *  Implement of SRV_UCM_HOLD_AND_ACCEPT_ACT
 * PARAMETERS
 *  group_index      [IN]            group index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_hold_and_accept_action(S32 group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 call_index = 0;
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
    {
        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_HOLD_ACT;
    }

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    srv_ucm_int_act_request(SRV_UCM_INT_HOLD_ACT, &action_id, NULL, NULL);

    /* Add accept action info to call table */
    srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;

    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].act_type = SRV_UCM_ACCEPT_ACT;

    /* AT doesn't need to know there is HOLD action */
    if (srv_ucm_at_check())
    {
        g_ucm_srv_p->call_misc.no_rcode_count++;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_all_action_with_call_type
 * DESCRIPTION
 *  End all specified call types
 * PARAMETERS
 *  call_type      [IN]            Call type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_all_action_with_call_type(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0, total_num = 0, call_type_grp_num = 0, i = 0;
    srv_ucm_id_info_struct action_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Add call info to call table */
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        if (g_ucm_srv_p->call_list.group_info[group_index].call_type & call_type)
        {
            for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
            {
                g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_WAIT_PROCESS_STATE;
                g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type = SRV_UCM_END_ALL_ACT;
            }
        }
    }

    /* Send request to call service */
    srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    srv_ucm_int_act_request(SRV_UCM_INT_END_ALL_ACT, &action_id, NULL, NULL);

    /* Same call types, the state should be DO_PROCESS_STATE */
    total_num = srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);    
    for (i = 1; i < total_num; i++)
    {
        group_index = g_ucm_srv_p->call_misc.index_list[i].group_index;
        call_index = g_ucm_srv_p->call_misc.index_list[i].call_index;

        if (g_ucm_srv_p->call_list.group_info[group_index].call_type == action_id.call_type)
        {
            g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
        }
    }

    /* AT doesn't need to know there are extra END_ALL actions */
    if (srv_ucm_at_check())
    {
        if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM1_CALL_TYPE_ALL, NULL) > 0) &&
            (call_type & (SRV_UCM_SIM1_CALL_TYPE_ALL)))
        {
            call_type_grp_num++;
        }

    #if (MMI_MAX_SIM_NUM >= 2)
        if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM2_CALL_TYPE_ALL, NULL) > 0) &&
            (call_type & (SRV_UCM_SIM2_CALL_TYPE_ALL)))
        {
            call_type_grp_num++;
        }
    #endif /* MMI_MAX_SIM_NUM >= 2 */

    #if (MMI_MAX_SIM_NUM >= 3)
        if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM3_CALL_TYPE_ALL, NULL) > 0) &&
            (call_type & (SRV_UCM_SIM3_CALL_TYPE_ALL)))
        {
            call_type_grp_num++;
        }
    #endif /* MMI_MAX_SIM_NUM >= 3 */

    #if (MMI_MAX_SIM_NUM >= 4)
        if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM4_CALL_TYPE_ALL, NULL) > 0) &&
            (call_type & (SRV_UCM_SIM4_CALL_TYPE_ALL)))
        {
            call_type_grp_num++;
        }
    #endif /* MMI_MAX_SIM_NUM >= 4 */

        if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VOIP_CALL_TYPE, NULL) > 0) &&
            (call_type & (SRV_UCM_VOIP_CALL_TYPE)))
        {
            call_type_grp_num++;
        }

        /* If more than 1 group of calls, AT needs to wait for all "END_ALL actiones" to be finished */
        if (call_type_grp_num > 1)
        {
           g_ucm_srv_p->call_misc.no_rcode_count = call_type_grp_num - 1;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_end_act_rsp
 * DESCRIPTION
 *  Handler for end action response
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_end_act_rsp(srv_ucm_int_act_opcode_enum int_op_code, void *rsp_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0, total_num = 0, i = 0;
    srv_ucm_id_info_struct action_id;
    srv_ucm_act_rsp_struct rsp;
    srv_ucm_int_act_rsp_struct *int_rsp = (srv_ucm_int_act_rsp_struct*)rsp_struct;
    srv_ucm_act_opcode_enum op_code = srv_ucm_query_act_op(int_op_code);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&rsp, 0, sizeof(srv_ucm_act_rsp_struct));

    if (int_rsp->result_info.result == SRV_UCM_RESULT_OK)
    {
        if (srv_ucm_at_check())
        {
            if (g_ucm_srv_p->call_misc.no_rcode_count == 0)
            {
                srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_OK, SRV_UCM_INVALID_ID, &g_ucm_srv_p->call_misc.at_info);
                memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
                g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            }
            else
            {
                g_ucm_srv_p->call_misc.no_rcode_count--;
            }
        }
        
        srv_ucm_sync_call_list(int_rsp->call_list);
        
        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_COMP_PROCESS_STATE);

        total_num = srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list);

        if (total_num > 0)
        {
            if ((total_num == 1) &&
                (g_ucm_srv_p->call_misc.curr_action != SRV_UCM_END_ALL_ACT) &&
                (g_ucm_srv_p->call_misc.curr_action != SRV_UCM_END_ALL_ACTIVE_ACT) &&
            #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
                (g_ucm_srv_p->call_misc.curr_action != SRV_UCM_END_ALL_HELD_ACT) &&
            #endif
                (g_ucm_srv_p->call_misc.curr_action != SRV_UCM_END_ALL_PROCESSING_ACT))
            {
                /* Action notify for the first end action in compound action */
                rsp.result_info.result = SRV_UCM_RESULT_OK;
                srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, srv_ucm_query_end_act_op(g_ucm_srv_p->call_misc.curr_action), SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);
                g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;
            }
            else
            {
                /* There is still end action ongoing */
                g_ucm_srv_p->call_misc.is_pending_end_act = MMI_TRUE;
            }
        
            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
            call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
            srv_ucm_set_process_state(group_index, -1, SRV_UCM_WAIT_PROCESS_STATE, SRV_UCM_DO_PROCESS_STATE);
            action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
            action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
            action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
            srv_ucm_int_act_request(srv_ucm_query_int_act_op(g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type), 
                &action_id,
                NULL,
                &g_ucm_srv_p->dial_info);

            /* Same call type, and the action is SRV_UCM_END_ALL_ACT, the state should be DO_PROCESS_STATE */
            if (total_num > 1)
            {
                for (i = 1; i < total_num; i++)
                {
                    group_index = g_ucm_srv_p->call_misc.index_list[i].group_index;
                    call_index = g_ucm_srv_p->call_misc.index_list[i].call_index;

                    if (g_ucm_srv_p->call_list.group_info[group_index].call_type == action_id.call_type && 
                        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type == SRV_UCM_END_ALL_ACT)
                    {
                        g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
                    }
                }
            }
        }
        else if (g_ucm_srv_p->dial_info.is_wait_dial == MMI_TRUE)
        {
            /* Action notify for the first action in compound action */
            rsp.result_info.result = SRV_UCM_RESULT_OK;
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, srv_ucm_query_end_act_op(g_ucm_srv_p->call_misc.curr_action), SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

            /* Perform dial action */
            srv_ucm_dial_action();
        }
        else
        {
            /* No waiting action, set action state to IDLE */
            srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

            /* Action notify */
            rsp.result_info.result = SRV_UCM_RESULT_OK;
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);

            /* Action response callback */
            srv_ucm_send_act_response(op_code, (void *)&rsp);
        }
    }
    else
    {
        /* no matter what the no_rcode_count is, send back the result code because the action terminated */
        if (srv_ucm_at_check())
        {
            srv_ucm_at_general_req(g_ucm_srv_p->call_misc.curr_module, RMMI_UCM_RCODE_ERROR, SRV_UCM_INVALID_ID, &g_ucm_srv_p->call_misc.at_info);
            memset(&g_ucm_srv_p->call_misc.at_info, 0, sizeof(srv_ucm_int_at_info_struct));
            g_ucm_srv_p->call_misc.curr_module = SRV_UCM_MODULE_ORIGIN_COMMON;
            g_ucm_srv_p->call_misc.no_rcode_count = 0;
        }

        srv_ucm_sync_call_list(int_rsp->call_list);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_WAIT_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        /* Action notify */
        memcpy(&rsp.result_info, &int_rsp->result_info, sizeof(srv_ucm_result_info_struct));
        srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, op_code, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);
        
        /* Compound action notify */
        if (g_ucm_srv_p->call_misc.curr_action != op_code)
        {
            srv_ucm_send_act_notify(g_ucm_srv_p->call_misc.curr_action, g_ucm_srv_p->call_misc.curr_action, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);        
        }

        /* Action response callback */        
        srv_ucm_send_act_response(op_code, (void *)&rsp);

        g_ucm_srv_p->call_misc.is_pending_end_act = MMI_FALSE;

        if (g_ucm_srv_p->dial_info.is_wait_dial == MMI_TRUE)
        {
            g_ucm_srv_p->dial_info.is_wait_dial = MMI_FALSE;
            srv_ucm_call_status_change_callback();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_start_dtmf_action
 * DESCRIPTION
 *  Implement of SRV_UCM_START_DTMF_ACT
 * PARAMETERS
 *  digit      [IN]            dtmf digit
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_start_dtmf_action(U16 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum call_type;
    srv_ucm_dtmf_struct int_start_dtmf_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((srv_ucm_query_call_count((srv_ucm_call_state_enum)(SRV_UCM_ACTIVE_STATE | SRV_UCM_OUTGOING_STATE | SRV_UCM_INCOMING_STATE),
        SRV_UCM_CALL_TYPE_NO_DATA_CSD, g_ucm_srv_p->call_misc.index_list) == 0) ||
        g_ucm_srv_p->call_misc.is_speech == MMI_FALSE)
    {
        /* Currently only for active call, outgoing call, incoming call, network may open speech */
        return;
    }

    call_type = g_ucm_srv_p->call_list.group_info[g_ucm_srv_p->call_misc.index_list[0].group_index].call_type;
    memset(&int_start_dtmf_req, 0, sizeof(srv_ucm_dtmf_struct));
    int_start_dtmf_req.digit = digit;

    /* Send action start notify */
    srv_ucm_send_act_notify(SRV_UCM_START_DTMF_ACT, SRV_UCM_START_DTMF_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, &int_start_dtmf_req);

    /* Send action request to call service */
    srv_ucm_int_query_call_srv_act_callback(call_type)(call_type, SRV_UCM_INT_START_DTMF_ACT, (void *)&int_start_dtmf_req, NULL, NULL);

    g_ucm_srv_p->call_misc.is_dtmf_start = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_stop_dtmf_action
 * DESCRIPTION
 *  Implement of SRV_UCM_STOP_DTMF_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_stop_dtmf_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum call_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(g_ucm_srv_p->call_misc.is_dtmf_start == MMI_TRUE);

    if ((srv_ucm_query_call_count((srv_ucm_call_state_enum)(SRV_UCM_ACTIVE_STATE | SRV_UCM_OUTGOING_STATE | SRV_UCM_INCOMING_STATE),
        SRV_UCM_CALL_TYPE_NO_DATA_CSD, g_ucm_srv_p->call_misc.index_list) == 0) ||
        g_ucm_srv_p->call_misc.is_speech == MMI_FALSE)
    {
        /* Currently only for active call, outgoing call, incoming call, network may open speech */
        return;
    }

    call_type = g_ucm_srv_p->call_list.group_info[g_ucm_srv_p->call_misc.index_list[0].group_index].call_type;

    /* Send action start notify */
    srv_ucm_send_act_notify(SRV_UCM_STOP_DTMF_ACT,
        SRV_UCM_STOP_DTMF_ACT,
        SRV_UCM_ACT_NOTIFY_TYPE_START,
        NULL);

    /* Send action request to call service */
    srv_ucm_int_query_call_srv_act_callback(call_type)(call_type, SRV_UCM_INT_STOP_DTMF_ACT, NULL, NULL, NULL);

    g_ucm_srv_p->call_misc.is_dtmf_start = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_send_dtmf_digits_action
 * DESCRIPTION
 *  Implement of SRV_UCM_SEND_DTMF_DIGITS_ACT
 * PARAMETERS
 *  dtmf_string      [IN]            dtmf_digits
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_send_dtmf_digits_action(srv_ucm_dtmf_digits_struct *dtmf_digits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index_list[SRV_UCM_MAX_GROUP];
    S32 call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_ucm_srv_p->call_misc.is_dtmf_start = MMI_TRUE;
    g_ucm_srv_p->call_misc.dtmf_digits_index = 0;
    memcpy(&g_ucm_srv_p->call_misc.dtmf_digits, dtmf_digits, sizeof(srv_ucm_dtmf_digits_struct));    

    if (srv_ucm_query_group_count((srv_ucm_call_state_enum)(SRV_UCM_OUTGOING_STATE | SRV_UCM_ACTIVE_STATE),
            SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, (S32 *)&group_index_list) > 0)
    {
        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index_list[0]].num_call; call_index++)
        {
            g_ucm_srv_p->call_list.group_info[group_index_list[0]].call_info[call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;
            g_ucm_srv_p->call_list.group_info[group_index_list[0]].call_info[call_index].act_type = SRV_UCM_SEND_DTMF_DIGITS_ACT;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

    srv_ucm_start_dtmf_action(g_ucm_srv_p->call_misc.dtmf_digits.dtmf_digits[g_ucm_srv_p->call_misc.dtmf_digits_index].digit);
    g_ucm_srv_p->call_misc.dtmf_digits_index++;

    StartTimer(UCM_SEND_DTMF_TIMER, 1000, srv_ucm_send_dtmf_digits);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_send_dtmf_digits
 * DESCRIPTION
 *  Implement of SRV_UCM_SEND_DTMF_DIGITS_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_send_dtmf_digits(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_rsp_struct act_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ucm_stop_dtmf_action();

    if ((g_ucm_srv_p->call_misc.dtmf_digits_index < g_ucm_srv_p->call_misc.dtmf_digits.length) &&
        (srv_ucm_query_call_count((srv_ucm_call_state_enum)(SRV_UCM_ACTIVE_STATE | SRV_UCM_OUTGOING_STATE | SRV_UCM_INCOMING_STATE), SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) > 0) &&
        (g_ucm_srv_p->call_misc.is_speech == MMI_TRUE))
    {
        srv_ucm_start_dtmf_action(g_ucm_srv_p->call_misc.dtmf_digits.dtmf_digits[g_ucm_srv_p->call_misc.dtmf_digits_index].digit);
        g_ucm_srv_p->call_misc.dtmf_digits_index++;
        StartTimer(UCM_SEND_DTMF_TIMER, 1000, srv_ucm_send_dtmf_digits);
        return;
    }

    memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));

    if ((srv_ucm_query_call_count((srv_ucm_call_state_enum)(SRV_UCM_ACTIVE_STATE | SRV_UCM_OUTGOING_STATE | SRV_UCM_INCOMING_STATE), SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) == 0) &&
        (g_ucm_srv_p->call_misc.is_speech == MMI_TRUE))
    {
        act_rsp.result_info.result = SRV_UCM_RESULT_NO_ACTIVE_CALL;
    }
    else
    {
        act_rsp.result_info.result = SRV_UCM_RESULT_OK;
    }

    srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

    /* Send action end notify */
    srv_ucm_send_act_notify(SRV_UCM_SEND_DTMF_DIGITS_ACT,
        SRV_UCM_SEND_DTMF_DIGITS_ACT,
        SRV_UCM_ACT_NOTIFY_TYPE_END,
        &act_rsp);

    /* Action response callback */
    srv_ucm_send_act_response(g_ucm_srv_p->call_misc.curr_action, (void *)&act_rsp);

    g_ucm_srv_p->call_misc.is_dtmf_start = MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_stop_dtmf_digits
 * DESCRIPTION
 *  Implement to stop SRV_UCM_SEND_DTMF_DIGITS_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_stop_dtmf_digits()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_rsp_struct act_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    StopTimer(UCM_SEND_DTMF_TIMER);

    srv_ucm_stop_dtmf_action();

    memset(&act_rsp, 0, sizeof(srv_ucm_act_rsp_struct));
    act_rsp.result_info.result = SRV_UCM_RESULT_USER_ABORT;

    /* Send action end notify */
    srv_ucm_send_act_notify(SRV_UCM_SEND_DTMF_DIGITS_ACT,
        SRV_UCM_SEND_DTMF_DIGITS_ACT,
        SRV_UCM_ACT_NOTIFY_TYPE_END,
        &act_rsp);

    /* Action response callback */
    srv_ucm_send_act_response(g_ucm_srv_p->call_misc.curr_action, (void *)&act_rsp);

    g_ucm_srv_p->call_misc.is_dtmf_start = MMI_FALSE;
}


#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_vt_fallto_voice_action
 * DESCRIPTION
 *  Implement of SRV_UCM_VT_FALLTO_VOICE_ACT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_vt_fallto_voice_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct action_id;
    S32 group_index = 0, call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;

    /* Add call info to call table */
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].proc_state = SRV_UCM_DO_PROCESS_STATE;
    g_ucm_srv_p->call_list.group_info[group_index].call_info[0].act_type = SRV_UCM_VT_FALLTO_VOICE_ACT;

    /* Send request to call service */
    memset(&action_id, 0, sizeof(srv_ucm_id_info_struct));
    action_id.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    action_id.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    action_id.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
    srv_ucm_int_act_request(SRV_UCM_INT_VT_FALLTO_VOICE_ACT, &action_id, NULL, NULL);
}
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_sync_call_list
 * DESCRIPTION
 *  This function is used to sync the call list with call services
 * PARAMETERS
 *  call_list      [IN]            Call list
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_sync_call_list(void *call_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, m = 0;
    srv_ucm_index_info_struct index;
    srv_ucm_index_info_struct index_iist;
    srv_ucm_call_entry_struct *conf_call = NULL;
    srv_ucm_int_call_list_struct *ind = (srv_ucm_int_call_list_struct*)call_list;
    S32 conf_call_index = 0;
    U8 conf_call_count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    conf_call = OslMalloc(sizeof(srv_ucm_call_entry_struct) * SRV_UCM_MAX_CALL_IN_GROUP);
    memset(conf_call, 0, sizeof(srv_ucm_call_entry_struct) * SRV_UCM_MAX_CALL_IN_GROUP);
    
    i = 0;
    while (i < g_ucm_srv_p->call_list.num_group)
    {
        j = 0;
        while (j < g_ucm_srv_p->call_list.group_info[i].num_call)
        {
            for (m = 0; m < ind->total_num; m++)
            {
                /* Replace invalid id to valid id for outgoing call */
                if ((g_ucm_srv_p->call_list.group_info[i].call_type == ind->call_info[m].uid_info.call_type) && 
                    (g_ucm_srv_p->call_list.group_info[i].call_state == SRV_UCM_OUTGOING_STATE) && 
                    (ind->call_info[m].call_state == SRV_UCM_OUTGOING_STATE))
                {
                    g_ucm_srv_p->call_list.group_info[i].group_id = ind->call_info[m].uid_info.group_id;
                    g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id = ind->call_info[m].uid_info.call_id;
                    memcpy(&g_ucm_srv_p->call_list.group_info[i].call_info[j].remote_info, &ind->call_info[m].remote_info, sizeof(srv_ucm_remote_info_struct));
                    break;
                }

                if ((g_ucm_srv_p->call_list.group_info[i].call_type & ind->call_type) && 
                    (g_ucm_srv_p->call_list.group_info[i].group_id == ind->call_info[m].uid_info.group_id) && 
                    (g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id == ind->call_info[m].uid_info.call_id))
                {
                    /* Update the entry in ucm call list */
                    if (g_ucm_srv_p->call_list.group_info[i].call_type != ind->call_info[m].uid_info.call_type)
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_SYNC_CALL_LIST_DATA_TO_VOICE);
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_SYNC_CALL_LIST_DATA_TO_VOICE_CALL_TYPE, g_ucm_srv_p->call_list.group_info[i].call_type, ind->call_info[m].uid_info.call_type);                        
                    }

                    g_ucm_srv_p->call_list.group_info[i].call_type = ind->call_info[m].uid_info.call_type; /* Emergency data call to emergency voice call */
                    g_ucm_srv_p->call_list.group_info[i].call_state = ind->call_info[m].call_state;
                    memcpy(&g_ucm_srv_p->call_list.group_info[i].call_info[j].remote_info, &ind->call_info[m].remote_info, sizeof(srv_ucm_remote_info_struct));
                    break;
                }
            }
            if ((m == ind->total_num) && (g_ucm_srv_p->call_list.group_info[i].call_type & ind->call_type))
            {
                /* Delete the entry in ucm call list */
                g_ucm_srv_p->call_list.group_info[i].num_call--;
                if (g_ucm_srv_p->call_list.group_info[i].num_call == 0) /* Delete from group entry */
                {
                    g_ucm_srv_p->call_list.num_group--;
                    /* Store the call entry for conference or split action, because most of the information should not change */
                    if ((g_ucm_srv_p->call_misc.curr_action == SRV_UCM_CONFERENCE_ACT) || (g_ucm_srv_p->call_misc.curr_action == SRV_UCM_SPLIT_ACT))
                    {
                        memcpy(&conf_call[conf_call_count], &g_ucm_srv_p->call_list.group_info[i].call_info[0], sizeof(srv_ucm_call_entry_struct));
                        conf_call_count++;
                    }
                    for (m = i; m < g_ucm_srv_p->call_list.num_group; m++)
                    {
                        memcpy(&g_ucm_srv_p->call_list.group_info[m], &g_ucm_srv_p->call_list.group_info[m + 1], sizeof(srv_ucm_group_entry_struct));
                    }
                    srv_ucm_reset_group_entry(m);
                    if (m != i) /* Enter for loop to move group list */
                    {
                        i--;
                    }
                    break;
                }
                else /* Delete from call entry */
                {
                    /* Store the actual time for conference or split action, because the group id will change */
                    if ((g_ucm_srv_p->call_misc.curr_action == SRV_UCM_CONFERENCE_ACT) || (g_ucm_srv_p->call_misc.curr_action == SRV_UCM_SPLIT_ACT))
                    {
                        memcpy(&conf_call[conf_call_count], &g_ucm_srv_p->call_list.group_info[i].call_info[j], sizeof(srv_ucm_call_entry_struct));
                        conf_call_count++;
                    }
                    for (m = j; m < g_ucm_srv_p->call_list.group_info[i].num_call; m++)
                    {
                        memcpy(&g_ucm_srv_p->call_list.group_info[i].call_info[m], &g_ucm_srv_p->call_list.group_info[i].call_info[m + 1], sizeof(srv_ucm_call_entry_struct));
                    }
                    srv_ucm_reset_call_entry(i, m);
                    if (m != j) /* Enter for loop to move call list */
                    {
                        j--;
                    }
                }
            }
            j++;
        }
        i++;
    }

    MMI_ASSERT(conf_call_count <= SRV_UCM_MAX_CALL_IN_GROUP);
    
    for (m = 0; m < ind->total_num; m++)
    {
        memset(&index_iist, -1, sizeof(srv_ucm_index_info_struct));
        srv_ucm_search_call_list(ind->call_info[m], &index_iist);
        if ((index_iist.group_index != -1) && (index_iist.call_index == -1)) /* Add to call entry */
        {
            i = index_iist.group_index;
            j = g_ucm_srv_p->call_list.group_info[index_iist.group_index].num_call;
            if (g_ucm_srv_p->call_list.group_info[i].num_call < SRV_UCM_MAX_CALL_IN_GROUP)
            {
                if ((g_ucm_srv_p->call_misc.curr_action == SRV_UCM_CONFERENCE_ACT) || (g_ucm_srv_p->call_misc.curr_action == SRV_UCM_SPLIT_ACT))
                {
                    conf_call_index = srv_ucm_query_call_index_by_call_id(conf_call, conf_call_count, ind->call_info[m].uid_info.call_id);
                    if (conf_call_index >= 0)
                    {
                        memcpy(&g_ucm_srv_p->call_list.group_info[i].call_info[j], &conf_call[conf_call_index], sizeof(srv_ucm_call_entry_struct));
                    }
                }
                g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id = ind->call_info[m].uid_info.call_id;
                memcpy(&g_ucm_srv_p->call_list.group_info[i].call_info[j].remote_info, &ind->call_info[m].remote_info, sizeof(srv_ucm_remote_info_struct));
                if (g_ucm_srv_p->call_list.group_info[i].call_state == SRV_UCM_OUTGOING_STATE)
                {
                    g_ucm_srv_p->call_list.group_info[i].call_info[j].call_origin = SRV_UCM_INT_MO_ORIGIN;
                }
                else if (g_ucm_srv_p->call_list.group_info[i].call_state == SRV_UCM_INCOMING_STATE)
                {
                    g_ucm_srv_p->call_list.group_info[i].call_info[j].call_origin = SRV_UCM_INT_MT_ORIGIN;
                }
                g_ucm_srv_p->call_list.group_info[i].num_call++;
            }
            else
            {
                MMI_ASSERT(0); /* No empty call entry to add */
            }
        }
        else if ((index_iist.group_index == -1) && (index_iist.call_index == -1)) /* Add to group entry */
        {
            i = g_ucm_srv_p->call_list.num_group;
            if (g_ucm_srv_p->call_list.num_group < SRV_UCM_MAX_GROUP)
            {
                if ((g_ucm_srv_p->call_misc.curr_action == SRV_UCM_CONFERENCE_ACT) || (g_ucm_srv_p->call_misc.curr_action == SRV_UCM_SPLIT_ACT))
                {
                    conf_call_index = srv_ucm_query_call_index_by_call_id(conf_call, conf_call_count, ind->call_info[m].uid_info.call_id);
                    if (conf_call_index >= 0)
                    {
                        memcpy(&g_ucm_srv_p->call_list.group_info[i].call_info[0], &conf_call[conf_call_index], sizeof(srv_ucm_call_entry_struct));
                    }
                }
                g_ucm_srv_p->call_list.group_info[i].group_id = ind->call_info[m].uid_info.group_id;
                g_ucm_srv_p->call_list.group_info[i].call_type = ind->call_info[m].uid_info.call_type;
                g_ucm_srv_p->call_list.group_info[i].call_state = ind->call_info[m].call_state;
                g_ucm_srv_p->call_list.group_info[i].call_info[0].call_id = ind->call_info[m].uid_info.call_id;
                memcpy(&g_ucm_srv_p->call_list.group_info[i].call_info[0].remote_info, &ind->call_info[m].remote_info, sizeof(srv_ucm_remote_info_struct));
                if (g_ucm_srv_p->call_list.group_info[i].call_state == SRV_UCM_OUTGOING_STATE)
                {
                    g_ucm_srv_p->call_list.group_info[i].call_info[0].call_origin = SRV_UCM_INT_MO_ORIGIN;
                }
                else if (g_ucm_srv_p->call_list.group_info[i].call_state == SRV_UCM_INCOMING_STATE)
                {
                    g_ucm_srv_p->call_list.group_info[i].call_info[0].call_origin = SRV_UCM_INT_MT_ORIGIN;
                }
                g_ucm_srv_p->call_list.group_info[i].num_call++;
                g_ucm_srv_p->call_list.num_group++;
            }
            else
            {
                MMI_ASSERT(0); /* No empty group entry to add */
            }
        }
    }

    /* For debug purpose */
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_SYNC_CALL_LIST_TOTAL_GROUP, g_ucm_srv_p->call_list.num_group);    
    for (i = 0; i < g_ucm_srv_p->call_list.num_group; i++)
    {
        for (j = 0; j < g_ucm_srv_p->call_list.group_info[i].num_call; j++)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL,
                TRC_SRV_UCM_SYNC_CALL_LIST_CALL_INFO,
                i, 
                g_ucm_srv_p->call_list.group_info[i].group_id ,
                g_ucm_srv_p->call_list.group_info[i].num_call,
                g_ucm_srv_p->call_list.group_info[i].call_type,
                g_ucm_srv_p->call_list.group_info[i].call_state, 
                g_ucm_srv_p->call_list.group_info[i].call_info[j].call_id);
        }
    }

#ifdef __BT_SUPPORT__
    if (g_ucm_srv_p->call_misc.is_delay_ciev == MMI_FALSE)
    {
        srv_ucm_sync_call_state_to_headset();
    }
    else
    {
        g_ucm_srv_p->call_misc.is_delay_ciev = MMI_FALSE;
    }
#endif /* __BT_SUPPORT__ */

    if ((g_ucm_srv_p->call_misc.is_delay_ring == MMI_TRUE) &&
        ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1) &&
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE_ALL), g_ucm_srv_p->call_misc.index_list) == 1)))
    {
        index.group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
        index.call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;

        srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT, RMMI_UCM_RCODE_RING,
            (U8)g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id,
            &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info);
    #if (MMI_MAX_SIM_NUM >= 2)
        srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM2, RMMI_UCM_RCODE_RING,
            (U8)g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id,
            &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info);
    #if (MMI_MAX_SIM_NUM >= 3)
        srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM3, RMMI_UCM_RCODE_RING,
            (U8)g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id,
            &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info);
    #if (MMI_MAX_SIM_NUM == 4)
        srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM4, RMMI_UCM_RCODE_RING,
            (U8)g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id,
            &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info);
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        g_ucm_srv_p->call_misc.is_delay_ring = MMI_FALSE;
    }

    /* Normally the start time should be determined at accept_rsp and conn_ind.
       However, for race condition cases, MT call becomes active before accept_rsp, for example, another call release.
       the start time of such active call cases are determined here. */
    srv_ucm_validate_start_time();

    srv_ucm_call_status_change_callback();

    OslMfree(conf_call);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_validate_start_time
 * DESCRIPTION
 *  Validate start time of calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_validate_start_time()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 group_index = 0;
    U32 call_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
    {
        if (g_ucm_srv_p->call_list.group_info[group_index].call_state == SRV_UCM_ACTIVE_STATE)
        {
            for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
            {
                if (!mmi_dt_is_valid(&g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].start_time))
                {
                    kal_get_time(&g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].start_tick_time);
                    DTGetRTCTime(&g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].start_time);   

                    /* do not log call history for SAT call */
                    if (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].module_id != SRV_UCM_MODULE_ORIGIN_SAT)
                    {
                        srv_ucm_log_call_history(group_index, call_index, MMI_TRUE);
                    }
                }
            }
        }
    }
}
#if defined(__GGT_TASK__)
#if defined(__OLED_BW_MMI__)
extern void mmi_set_sos_status(U8 s);
extern U8 mmi_get_sos_status(void);
extern void mmi_set_sos_call_alert(U8 s);
extern U8 mmi_get_sos_call_alert(void);
extern void mmi_idle_start_remake_sos_call(void);
#endif /* __OLED_BW_MMI__ */
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_alert_ind
 * DESCRIPTION
 *  Alert indication handler
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_alert_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_alert_ind_struct *int_alert_ind = (srv_ucm_int_alert_ind_struct*)ind_struct;
    srv_ucm_alert_ind_struct alert_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Alert indication */
    memset(&alert_ind, 0, sizeof(srv_ucm_alert_ind_struct));
    memcpy(&alert_ind.uid_info, &int_alert_ind->uid_info, sizeof(srv_ucm_id_info_struct));
    alert_ind.local_gen = int_alert_ind->local_gen;
    srv_ucm_send_indication(SRV_UCM_ALERT_IND, (void *)&alert_ind);

    if (int_alert_ind->uid_info.call_type & (SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE_ALL))
    {
    #ifdef __BT_SUPPORT__
        srv_ucm_bt_handfree_ciev_req(MMI_SIM1, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_ALERT);
    #if (MMI_MAX_SIM_NUM >= 2)
        srv_ucm_bt_handfree_ciev_req(MMI_SIM2, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_ALERT);
    #if (MMI_MAX_SIM_NUM >= 3)
        srv_ucm_bt_handfree_ciev_req(MMI_SIM3, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_ALERT);
    #if (MMI_MAX_SIM_NUM == 4)
        srv_ucm_bt_handfree_ciev_req(MMI_SIM4, RMMI_CIND_CALLSETUP, RMMI_CIND_CSUP_ALERT);
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    #endif /* __BT_SUPPORT__ */
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_connect_ind
 * DESCRIPTION
 *  Handler for outgoing call connect indication
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_connect_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0;
    srv_ucm_index_info_struct index;
    srv_ucm_int_connect_ind_struct *int_connect_ind = (srv_ucm_int_connect_ind_struct*)ind_struct;
    srv_ucm_connect_ind_struct connect_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    /* dialed call log */
    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) != 1)
    {
        MMI_ASSERT(0);
    }
	
#if defined(__GGT_TASK__)
#if defined(__OLED_BW_MMI__)
	if(mmi_get_sos_status() == 1)
	{
		mmi_set_sos_call_alert(1);
	}
#endif /* __OLED_BW_MMI__ */
#endif

    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    kal_get_time(&g_ucm_srv_p->call_list.group_info[group_index].call_info[0].start_tick_time);
    DTGetRTCTime(&g_ucm_srv_p->call_list.group_info[group_index].call_info[0].start_time);

    /* do not log call history for SAT call */
    if ((g_ucm_srv_p->call_list.group_info[group_index].call_info[0].module_id != SRV_UCM_MODULE_ORIGIN_SAT) &&
        (int_connect_ind->no_counter == MMI_FALSE))
    {
        srv_ucm_log_call_history(group_index, 0, MMI_TRUE);
    }

    srv_ucm_sync_call_list(int_connect_ind->call_list);

    memset(&index, 0, sizeof(srv_ucm_index_info_struct));

    if (srv_ucm_query_index_by_id(&int_connect_ind->uid_info, &index) == MMI_FALSE)
    {
        MMI_ASSERT(0);
    }

    if (int_connect_ind->no_counter == MMI_TRUE)
    {
        g_ucm_srv_p->call_misc.is_count_stopped = MMI_TRUE;
    }

    /* Connect indication */
    memset(&connect_ind, 0, sizeof(srv_ucm_connect_ind_struct));
    connect_ind.module_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[0].module_id;
    memcpy(&connect_ind.remote_info, &g_ucm_srv_p->call_list.group_info[group_index].call_info[0].remote_info, sizeof(srv_ucm_remote_info_struct));
    memcpy(&connect_ind.uid_info, &int_connect_ind->uid_info, sizeof(srv_ucm_id_info_struct));
    connect_ind.no_counter = int_connect_ind->no_counter;
    srv_ucm_send_indication(SRV_UCM_CONNECT_IND, (void *)&connect_ind);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_notify_ind
 * DESCRIPTION
 *  Handler for notify indication
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_notify_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_notify_ind_struct *int_notify_ind = (srv_ucm_int_notify_ind_struct*)ind_struct;
    srv_ucm_notify_ind_struct notify_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Notify indication */
    memset(&notify_ind, 0, sizeof(srv_ucm_notify_ind_struct));
    notify_ind.call_type = int_notify_ind->call_type;
    notify_ind.image_id = int_notify_ind->image_id;
    notify_ind.tone_id = int_notify_ind->tone_id;
    mmi_ucs2ncpy((CHAR *)notify_ind.disp_msg, (CHAR *)int_notify_ind->disp_msg, SRV_UCM_MAX_DISP_MSG_LEN);
    srv_ucm_send_indication(SRV_UCM_NOTIFY_IND, (void *)&notify_ind);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_session_ind
 * DESCRIPTION
 *  Session control
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_session_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_session_ind_struct *int_session_ind = (srv_ucm_int_session_ind_struct*)ind_struct;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (int_session_ind->session_switch == MMI_TRUE) /* turn on session */
    {
        if (mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_NONE)
        {
            /* session is occupied, cannot turn on directly */
            if (mdi_audio_speech_get_app_id() != int_session_ind->session_type)
            {
                if (g_ucm_srv_p->call_misc.is_speech == MMI_TRUE)
                {
                    /* turn off speech before session off */
                #ifdef __MMI_VOIP__
                    if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_VOIP)
                    {
                        mmi_voip_ucm_suspend_rtp();
                    }
                    else
                #endif /* __MMI_VOIP__ */
                    {
                        mdi_audio_speech_codec_stop();
                    }
                }
                mdi_audio_speech_session_stop(mdi_audio_speech_get_app_id());
                mdi_audio_speech_session_start((MDI_AUDIO_SPEECH_APP_ID_ENUM)int_session_ind->session_type);
            }
        }
        else /* session is not occupied, turn on directly */
        {
            mdi_audio_speech_session_start((MDI_AUDIO_SPEECH_APP_ID_ENUM)int_session_ind->session_type);
        }
    }
    else /* turn off session */
    {
        if (mdi_audio_speech_get_app_id() == int_session_ind->session_type)
        {
            /* speech should turn off before session off */
            MMI_ASSERT(g_ucm_srv_p->call_misc.is_speech == MMI_FALSE);

            mdi_audio_speech_session_stop((MDI_AUDIO_SPEECH_APP_ID_ENUM)int_session_ind->session_type);
            
            /* resume background play when there is no call/only csd call and speech is off */
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
            {
                mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_speech_ind
 * DESCRIPTION
 *  Speech control
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_speech_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_speech_ind_struct *int_speech_ind = (srv_ucm_int_speech_ind_struct*)ind_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((int_speech_ind->call_type & SRV_UCM_VOICE_CALL_TYPE_ALL) ||
    #ifdef __MMI_VIDEO_TELEPHONY__
        (int_speech_ind->call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL) ||
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        MMI_FALSE)
    {
        if ((int_speech_ind->local_switch == MMI_TRUE) || (int_speech_ind->remote_switch == MMI_TRUE)) /* speech on */
        {
            if (mdi_audio_speech_get_app_id() != int_speech_ind->session_type)
            {
                if (mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_NONE)
                {
                    /* stop codec / encode / decode, stop other session and start the session */
                #ifdef __MMI_VOIP__
                    if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_VOIP)
                    {
                        mmi_voip_ucm_suspend_rtp();
                    }
                    else
                #endif /* __MMI_VOIP__ */
                    {
                        mdi_audio_speech_codec_stop();
                    }
                    mdi_audio_speech_session_stop(mdi_audio_speech_get_app_id());                    
                }
                mdi_audio_speech_session_start((MDI_AUDIO_SPEECH_APP_ID_ENUM)int_speech_ind->session_type);
            }
            mdi_audio_speech_codec_start();
            g_ucm_srv_p->call_misc.is_speech = MMI_TRUE;
        }
        else /* speech off */
        {
            if (mdi_audio_speech_get_app_id() == int_speech_ind->session_type)
            {
                mdi_audio_speech_codec_stop();
                g_ucm_srv_p->call_misc.is_speech = MMI_FALSE;
            }
        }
    }
#ifdef __MMI_VOIP__
    else if (int_speech_ind->call_type & SRV_UCM_VOIP_CALL_TYPE)
    {
        /* speech off for UCM */
        if (((int_speech_ind->local_switch == MMI_FALSE) && (int_speech_ind->remote_switch == MMI_FALSE))||
            ((int_speech_ind->local_switch == MMI_TRUE) && (int_speech_ind->remote_switch == MMI_FALSE)))
        {
            if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_VOIP)
            {
                g_ucm_srv_p->call_misc.is_speech = MMI_FALSE;
            }
        }
        /* speech on for UCM */
        else
        {
            if (mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_VOIP)
            {
                if (mdi_audio_speech_get_app_id() != MDI_AUDIO_SPEECH_APP_ID_NONE)
                {
                    /* stop codec / encode / decode, stop other session and start the session */
                    mdi_audio_speech_codec_stop();
                    g_ucm_srv_p->call_misc.is_speech = MMI_FALSE;
                    mdi_audio_speech_session_stop(mdi_audio_speech_get_app_id());
                }
                mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_VOIP);
            }
            if (g_ucm_srv_p->call_misc.is_speech == MMI_FALSE)
            {
                g_ucm_srv_p->call_misc.is_speech = MMI_TRUE;
            }
        }
    }
#endif /* __MMI_VOIP__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_ring_ind
 * DESCRIPTION
 *  Handler for incoming call
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_ring_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0, call_index = 0;
    MMI_BOOL dial_act_ongoing = MMI_FALSE;
    srv_ucm_index_info_struct index;
    srv_ucm_int_ring_ind_struct *int_ring_ind = (srv_ucm_int_ring_ind_struct*)ind_struct;
    srv_ucm_incoming_call_ind_struct incoming_call_ind;
    U16 ucs2_number[SRV_UCM_MAX_NUM_URI_LEN + 1];
#if defined(__MMI_CM_BLACK_LIST__) && defined(__MMI_CM_BLACK_LIST_EXT__) 
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* defined(__MMI_CM_BLACK_LIST__) && defined(__MMI_CM_BLACK_LIST_EXT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ucs2_number, 0, (SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((CHAR *) ucs2_number, (CHAR *) int_ring_ind->remote_info.num_uri);

    /* Any DIAL_ACT ongoing? */
    if (srv_ucm_get_process_state(SRV_UCM_DO_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list) > 0)
    {
        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
        call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
        if (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type == SRV_UCM_DIAL_ACT)
        {
            dial_act_ongoing = MMI_TRUE;
        }
    }

#if defined(__MMI_CM_BLACK_LIST__) && defined(__MMI_CM_BLACK_LIST_EXT__) 
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = srv_ucm_query_blacklist_call_type(int_ring_ind->uid_info.call_type);
#endif /* defined(__MMI_CM_BLACK_LIST__) && defined(__MMI_CM_BLACK_LIST_EXT__) */

    /* When AT is disconnecting call, it cannot be interrupted by incoming call */
    if ((g_ucm_srv_p->call_misc.curr_module == SRV_UCM_MODULE_ORIGIN_COMMON) &&
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) &&
        !((srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) != 0) && (dial_act_ongoing == MMI_FALSE)) &&
        (g_ucm_srv_p->call_list.num_group < SRV_UCM_MAX_GROUP) &&
        !((g_ucm_srv_p->call_list.num_group == SRV_UCM_MAX_GROUP - 1) && (srv_ucm_query_curr_action() == SRV_UCM_SPLIT_ACT)) &&
    #ifdef __MMI_CM_BLACK_LIST__
    #ifdef __MMI_CM_BLACK_LIST_EXT__
        (srv_callset_blacklist_is_blocked_number((U8)mmi_ucs2strlen((CHAR *)ucs2_number), ucs2_number, &adv_param) == MMI_FALSE) &&
    #else /* __MMI_CM_BLACK_LIST_EXT__ */
        (srv_callset_blacklist_is_blocked_number((U8)mmi_ucs2strlen((CHAR *)ucs2_number), ucs2_number, NULL) == MMI_FALSE) &&
    #endif /* __MMI_CM_BLACK_LIST_EXT__  */
    #endif /* __MMI_CM_BLACK_LIST__ */
        MMI_TRUE)
    {
        /* Suspend background play for single MT call except for CSD MT call */
        if (((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0) ||
            ((srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 1) &&
            (dial_act_ongoing == MMI_TRUE))) &&
            !(int_ring_ind->uid_info.call_type & SRV_UCM_CSD_CALL_TYPE_ALL))
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_SUSPEND_BACKGROUND_PLAY);
            mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM);
        }

        srv_ucm_sync_call_list(int_ring_ind->call_list);

        memset(&index, 0, sizeof(srv_ucm_index_info_struct));
        
        if (srv_ucm_query_index_by_id(&int_ring_ind->uid_info, &index) == MMI_FALSE)
        {
            MMI_ASSERT(0);
        }
        memcpy(&g_ucm_srv_p->mo_mt_display, &int_ring_ind->display_info, sizeof(srv_ucm_display_info_struct));
        memcpy(&g_ucm_srv_p->call_misc.at_info, &int_ring_ind->at_info, sizeof(srv_ucm_int_at_info_struct));
        memcpy(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info, &int_ring_ind->at_info, sizeof(srv_ucm_int_at_info_struct));
        kal_get_time(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_tick_time);

    #ifdef __MMI_AUTO_ANSWER_MACHINE__
        if (mmi_autoam_check_switch_on() == MMI_TRUE)
        {
            StartTimer(UCM_AUTO_ANSWER_MACHINE_TIMER, mmi_autoam_get_pickup_duration() * 1000, srv_ucm_autoam_timeout_hdlr);
        }
    #endif /* __MMI_AUTO_ANSWER_MACHINE__ */

        /* Reset wait dial flag to prevent MO & MT collision */
        if (g_ucm_srv_p->dial_info.is_wait_dial == MMI_TRUE)
        {
            g_ucm_srv_p->dial_info.is_wait_dial = MMI_FALSE;
            srv_ucm_call_status_change_callback();
        }
        
        /* Abort the ongoing auto redial action */
        srv_ucm_auto_redial_abort();

        /* Incoming call indication */
        memset(&incoming_call_ind, 0, sizeof(srv_ucm_incoming_call_ind_struct));
        memcpy(&incoming_call_ind.display_info, &g_ucm_srv_p->mo_mt_display, sizeof(srv_ucm_display_info_struct));
        memcpy(&incoming_call_ind.remote_info, &int_ring_ind->remote_info, sizeof(srv_ucm_remote_info_struct));
        memcpy(&incoming_call_ind.uid_info, &int_ring_ind->uid_info, sizeof(srv_ucm_id_info_struct));
        incoming_call_ind.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
        srv_ucm_send_indication(SRV_UCM_INCOMING_CALL_IND, &incoming_call_ind);

        /* Notfify AT */
        if ((int_ring_ind->uid_info.call_type & (SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_DATA_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE_ALL)) &&
            (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1)) 
        {
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT, RMMI_UCM_RCODE_RING, (U8)int_ring_ind->uid_info.call_id, &g_ucm_srv_p->call_misc.at_info);
        #if (MMI_MAX_SIM_NUM >= 2)
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM2, RMMI_UCM_RCODE_RING, (U8)int_ring_ind->uid_info.call_id, &g_ucm_srv_p->call_misc.at_info);
        #if (MMI_MAX_SIM_NUM >= 3)
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM3, RMMI_UCM_RCODE_RING, (U8)int_ring_ind->uid_info.call_id, &g_ucm_srv_p->call_misc.at_info);
        #if (MMI_MAX_SIM_NUM == 4)
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM4, RMMI_UCM_RCODE_RING, (U8)int_ring_ind->uid_info.call_id, &g_ucm_srv_p->call_misc.at_info);
        #endif /* (MMI_MAX_SIM_NUM == 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
        }
        else if ((int_ring_ind->uid_info.call_type & (SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_DATA_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE_ALL)) &&
                 (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 1))
        {
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT, RMMI_UCM_RCODE_CCWA, (U8)int_ring_ind->uid_info.call_id, &g_ucm_srv_p->call_misc.at_info);
        #if (MMI_MAX_SIM_NUM >= 2)
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM2, RMMI_UCM_RCODE_CCWA, (U8)int_ring_ind->uid_info.call_id, &g_ucm_srv_p->call_misc.at_info);
        #if (MMI_MAX_SIM_NUM >= 3)
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM3, RMMI_UCM_RCODE_CCWA, (U8)int_ring_ind->uid_info.call_id, &g_ucm_srv_p->call_misc.at_info);
        #if (MMI_MAX_SIM_NUM == 4)
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM4, RMMI_UCM_RCODE_CCWA, (U8)int_ring_ind->uid_info.call_id, &g_ucm_srv_p->call_misc.at_info);
        #endif /* (MMI_MAX_SIM_NUM == 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
        }
    }
    else /* the auto reject call is not in the call list */
    {
        /* Auto reject */
        srv_ucm_int_act_request(SRV_UCM_INT_AUTO_REJECT_ACT, &(int_ring_ind->uid_info), NULL, NULL);
        srv_ucm_int_act_request(SRV_UCM_INT_FORCE_RELEASE_ACT, &(int_ring_ind->uid_info), NULL, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_disconnecting_ind
 * DESCRIPTION
 *  Handler for call disconnecting indication
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_disconnecting_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_disconnecting_ind_struct *int_disc_ind = (srv_ucm_int_disconnecting_ind_struct*)ind_struct;
    srv_ucm_disconnecting_ind_struct disc_ind;
    srv_ucm_index_info_struct index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ucm_sync_call_list(int_disc_ind->call_list);

    /* Update to call table */
    srv_ucm_query_index_by_id(&int_disc_ind->uid_info, &index);
    g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].is_disconnecting = MMI_TRUE;

    /* Call disconnecting indication */
    memset(&disc_ind, 0, sizeof(srv_ucm_disconnecting_ind_struct));
    memcpy(&disc_ind.uid_info, &int_disc_ind->uid_info, sizeof(srv_ucm_id_info_struct));
    srv_ucm_send_indication(SRV_UCM_DISCONNECTING_IND, &disc_ind);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_release_ind
 * DESCRIPTION
 *  Handler for call release indication
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_release_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_index_info_struct index;
    srv_ucm_int_at_info_struct *at_info_ptr = NULL;
    srv_ucm_int_release_ind_struct *int_release_ind = (srv_ucm_int_release_ind_struct*)ind_struct;
    srv_ucm_release_ind_struct release_ind;
    srv_ucm_act_rsp_struct rsp;
#ifdef __MMI_UCM_REJECT_BY_SMS__
    MMI_BOOL rej_by_sms = MMI_FALSE;
    srv_sms_event_api_send_msg_struct msg_data;
#endif /* __MMI_UCM_REJECT_BY_SMS__*/
    U32 end_tick_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ucm_query_index_by_id(&int_release_ind->uid_info, &index) == MMI_FALSE)
    {
        MMI_ASSERT(0);
    }

    if (mmi_dt_is_valid(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time))
    {
        if (g_ucm_srv_p->call_misc.is_count_stopped == MMI_TRUE)
        {
            /* do not log call history for SAT call */
            if (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[0].module_id != SRV_UCM_MODULE_ORIGIN_SAT)
            {
                srv_ucm_log_call_history(index.group_index, 0, MMI_TRUE);
            }
            g_ucm_srv_p->call_end.call_duration = 0;
            g_ucm_srv_p->call_misc.is_count_stopped = MMI_FALSE;
        }
        else
        {
            kal_get_time(&end_tick_time);
            g_ucm_srv_p->call_end.call_duration = kal_ticks_to_secs(end_tick_time - g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_tick_time);
        }

        /* do not log call duration for SAT call */
        if (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id != SRV_UCM_MODULE_ORIGIN_SAT)
        {
            srv_ucm_log_call_duration(index.group_index, index.call_index);
        }
    }
    else
    {
        g_ucm_srv_p->call_end.call_duration = 0;

        /* do not log call history for SAT call */
        if (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id != SRV_UCM_MODULE_ORIGIN_SAT)
        {
            if (g_ucm_srv_p->call_list.group_info[index.group_index].call_state == SRV_UCM_OUTGOING_STATE)
            {
                kal_get_time(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_tick_time);
                DTGetRTCTime(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time);
                srv_ucm_log_call_history(index.group_index, index.call_index, MMI_FALSE);
            }
            else if (g_ucm_srv_p->call_list.group_info[index.group_index].call_state == SRV_UCM_INCOMING_STATE)
            {
                if (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].proc_state != SRV_UCM_IDLE_PROCESS_STATE)
                {
                    /* User takes any action, should be received call, not missed call */
                    DTGetRTCTime(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time);
                    srv_ucm_log_call_history(index.group_index, index.call_index, MMI_TRUE);
                }
                else
                {
                    /* Remote drops the incoming call */
                    srv_ucm_log_call_history(index.group_index, index.call_index, MMI_FALSE);

                    /* Log the duration of how long the MT rings */
                    kal_get_time(&end_tick_time);
                    g_ucm_srv_p->call_end.call_duration = kal_ticks_to_secs(end_tick_time - g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_tick_time);
                    srv_ucm_log_call_duration(index.group_index, index.call_index);
                    g_ucm_srv_p->call_end.call_duration = 0;
                }
            }
            else
            {
                MMI_ASSERT(0); /* should either outgoing call or incoming call */
            }
        }
    }

    if (srv_ucm_at_check())
    {
        g_ucm_srv_p->call_misc.is_delay_ciev = MMI_TRUE;
    }
    else if ((g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id == SRV_UCM_MODULE_ORIGIN_AT) ||
        #if (MMI_MAX_SIM_NUM >= 2)
            (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM2) ||
        #if (MMI_MAX_SIM_NUM >= 3)
            (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM3) ||
        #if (MMI_MAX_SIM_NUM == 4)
            (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM4) ||
        #endif /* (MMI_MAX_SIM_NUM == 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
            MMI_FALSE)
    {
        at_info_ptr = OslMalloc(sizeof(srv_ucm_int_at_info_struct));
        memset(at_info_ptr, 0, sizeof(srv_ucm_int_at_info_struct));
        memcpy(at_info_ptr, &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info, sizeof(srv_ucm_int_at_info_struct));
        srv_ucm_at_general_req(
            g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id, 
            RMMI_UCM_RCODE_NO_CARRIER, 
            (U8)g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id, 
            at_info_ptr);
        OslMfree(at_info_ptr);
    }

    mmi_ucs2ncpy((CHAR *)g_ucm_srv_p->call_end.disp_msg, (CHAR *)int_release_ind->disp_msg, SRV_UCM_MAX_ERR_MSG_LEN);
    g_ucm_srv_p->call_end.image_id = int_release_ind->image_id;
    g_ucm_srv_p->call_end.tone_id = int_release_ind->tone_id;

#ifdef __MMI_UCM_REJECT_BY_SMS__
    if (g_ucm_srv_p->rej_by_sms.uid_info.group_id == g_ucm_srv_p->call_list.group_info[index.group_index].group_id &&
        g_ucm_srv_p->rej_by_sms.uid_info.call_id == g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id &&
        g_ucm_srv_p->rej_by_sms.uid_info.call_type == g_ucm_srv_p->call_list.group_info[index.group_index].call_type)
    {
        /* This is the rejected call */
        rej_by_sms = MMI_TRUE;
    }
#endif /* __MMI_UCM_REJECT_BY_SMS__ */

    /* Call release information collection before removed from call table */
    memset(&release_ind, 0, sizeof(srv_ucm_release_ind_struct));
    memcpy(&release_ind.uid_info, &int_release_ind->uid_info, sizeof(srv_ucm_id_info_struct));
    memcpy(&release_ind.remote_info, &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].remote_info, sizeof(srv_ucm_remote_info_struct));
    release_ind.module_id = g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id;
    release_ind.previous_state = g_ucm_srv_p->call_list.group_info[index.group_index].call_state;
    mmi_ucs2ncpy((CHAR *)release_ind.call_end_msg, (CHAR *)int_release_ind->disp_msg, SRV_UCM_MAX_ERR_MSG_LEN);
    release_ind.call_end_image_id = int_release_ind->image_id;
    release_ind.call_end_tone_id = int_release_ind->tone_id;
    release_ind.call_end_error_cause = int_release_ind->error_cause;
    memcpy(&release_ind.start_time, &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time, sizeof(MYTIME));
    applib_dt_sec_2_mytime(g_ucm_srv_p->call_end.call_duration, &release_ind.call_duration);

    srv_ucm_sync_call_list(int_release_ind->call_list);

    /* Call release indication */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        memset(&release_ind.post_action, 0, sizeof(srv_ucm_post_action_struct));
    }
    else
    {
        release_ind.post_action.action = int_release_ind->post_action.action;
        release_ind.post_action.is_ip_dial = int_release_ind->post_action.is_ip_dial;
        release_ind.post_action.phb_data = int_release_ind->post_action.phb_data;
    }
    srv_ucm_send_indication(SRV_UCM_RELEASE_IND, &release_ind);

    /* End all processing action is done or not */
    if (g_ucm_srv_p->call_misc.curr_action == SRV_UCM_END_ALL_PROCESSING_ACT)
    {
        g_ucm_srv_p->call_misc.end_processing_count --;
        
        if (g_ucm_srv_p->call_misc.end_processing_count == 0)
        {
            /* Action notify */
            memset(&rsp, 0, sizeof(srv_ucm_act_rsp_struct));
            rsp.result_info.result = SRV_UCM_RESULT_OK;
            srv_ucm_send_act_notify( g_ucm_srv_p->call_misc.curr_action, SRV_UCM_END_ALL_PROCESSING_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);
        
            /* Action response callback */
            srv_ucm_send_act_response(SRV_UCM_END_ALL_PROCESSING_ACT, (void *)&rsp);    
        }
    }

    if ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE_ALL), g_ucm_srv_p->call_misc.index_list) == 1) &&
        ((srv_ucm_query_curr_action() != SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT) && (srv_ucm_query_curr_action() != SRV_UCM_HOLD_AND_ACCEPT_ACT)))
    {
        if (srv_ucm_query_curr_action() == SRV_UCM_NO_ACT)
        {
            index.group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
            index.call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;

            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT, RMMI_UCM_RCODE_RING,
                (U8)g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id,
                &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info);
        #if (MMI_MAX_SIM_NUM >= 2)
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM2, RMMI_UCM_RCODE_RING,
                (U8)g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id,
                &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info);
        #if (MMI_MAX_SIM_NUM >= 3)
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM3, RMMI_UCM_RCODE_RING,
                (U8)g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id,
                &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info);
        #if (MMI_MAX_SIM_NUM == 4)
            srv_ucm_at_general_req(SRV_UCM_MODULE_ORIGIN_AT_SIM4, RMMI_UCM_RCODE_RING,
                (U8)g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id,
                &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].at_info);
        #endif /* (MMI_MAX_SIM_NUM == 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
        }
        else
        {
            g_ucm_srv_p->call_misc.is_delay_ring = MMI_TRUE;
        }
    }

#ifdef __MMI_UCM_REJECT_BY_SMS__
    if (rej_by_sms == MMI_TRUE)
    {
        /* Send SMS */
        memset(&msg_data, 0, sizeof(srv_sms_event_api_send_msg_struct));
        memcpy(&msg_data.number, &g_ucm_srv_p->rej_by_sms.dest_num, SRV_SMS_MAX_ADDR_LEN);
        msg_data.content_buff = (U16 *)g_ucm_srv_p->rej_by_sms.message;
        msg_data.content_buff_size = ((mmi_ucs2strlen((CHAR *)g_ucm_srv_p->rej_by_sms.message) + 1) * ENCODING_LENGTH);

        if (g_ucm_srv_p->rej_by_sms.sim_id == MMI_SIM1)
        {
            msg_data.sim_id = SRV_SMS_SIM_1;
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        else if (g_ucm_srv_p->rej_by_sms.sim_id == MMI_SIM2)
        {
            msg_data.sim_id = SRV_SMS_SIM_2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if (g_ucm_srv_p->rej_by_sms.sim_id == MMI_SIM3)
        {
            msg_data.sim_id = SRV_SMS_SIM_3;
        }
    #if (MMI_MAX_SIM_NUM == 4)
        else if (g_ucm_srv_p->rej_by_sms.sim_id == MMI_SIM4)
        {
            msg_data.sim_id = SRV_SMS_SIM_4;
        }
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        else
        {
            MMI_ASSERT(0);
        }

        srv_sms_event_api_send_msg(&msg_data);

        if (g_ucm_srv_p->rej_by_sms.message != NULL)
        {
            OslMfree(g_ucm_srv_p->rej_by_sms.message);
            g_ucm_srv_p->rej_by_sms.message = NULL;
        }
        memset(&g_ucm_srv_p->rej_by_sms, 0, sizeof(srv_ucm_rej_by_sms_struct));

    }
#endif /* __MMI_UCM_REJECT_BY_SMS__ */

#ifdef __MMI_AUTO_ANSWER_MACHINE__
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_AUTO_ANSWER_MACHINE_CALL_TYPE, NULL) == 0)
    {
        StopTimer(UCM_AUTO_ANSWER_MACHINE_TIMER);
    }

    if (srv_ucm_autoam_get_state() == SRV_UCM_AUTOAM_STATE_START)
    {
        srv_ucm_index_info_struct index;
        
        if (srv_ucm_query_index_by_id(&g_ucm_srv_p->autoam.uid_info, &index) == MMI_FALSE)
        {
            StartTimer(UCM_AUTO_ANSWER_MACHINE_END_TIMER, 1, mmi_autoam_end_answer_incoming);
            srv_ucm_autoam_reset_cntx();
        }
    }
    else if (srv_ucm_autoam_get_state() == SRV_UCM_AUTOAM_STATE_READY)
    {
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_AUTO_ANSWER_MACHINE_CALL_TYPE, NULL) == 0)
        {
            srv_ucm_autoam_reset_cntx();
        }
    }
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */

#if defined(__KJX_OLED_64_48_UI__)	//xb add 2016-09-06	通话结束更新屏幕显示
	{
		extern U32 kjx_call_time;
		extern U8 kjx_call_display[SRV_UCM_MAX_NUM_URI_LEN + 1];
		extern UI_string_type kjx_scrolling_show[512];

		kjx_call_time = 0;
		memset(kjx_call_display, 0, sizeof(kjx_call_display));
		memset(kjx_scrolling_show, 0, sizeof(kjx_scrolling_show));
	}
#endif/*__KJX_OLED_64_48_UI__*/


#if defined(__KJX_RFID_PLAY_CONTINUE_AGAIN__)	//xb add 2016-08-24	通话结束后恢复前面被中断的RFID播放
	{
		extern U8 kjx_audio_status;
		extern BOOL kjx_rfid_is_in_play(void);
		extern void kjx_rfid_continue_play_audio(void);

	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("kjx_audio_status:%d", kjx_audio_status);
	#endif	
		if(kjx_rfid_is_in_play() && (kjx_audio_status == 3))
		{
			StartTimer(KJX_TIMER_ID_PLAY_AUDIO, 5000, kjx_rfid_continue_play_audio);//xb add 2017-07-21 延迟几秒以备通话结束后的处理
		}
	}
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_release_ind_post_callback
 * DESCRIPTION
 *  Remaining jobs after sending release indication by post event
 * PARAMETERS
 *  ind          [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_release_ind_post_callback(srv_ucm_ind_evt_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind->ind_type == SRV_UCM_RELEASE_IND)
    {
       if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
       {
            /* resume background play when there is no call/only csd call and speech is off */
            if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_NONE)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_RESUME_BACKGROUND_PLAY);
                mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_auto_redial_ind
 * DESCRIPTION
 *  Handler for auto redial indication
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_auto_redial_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_auto_redial_ind_struct *int_redial_ind = (srv_ucm_int_auto_redial_ind_struct*)ind_struct;
    srv_ucm_auto_redial_ind_struct redial_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&g_ucm_srv_p->auto_redial, int_redial_ind, sizeof(srv_ucm_int_auto_redial_ind_struct));

    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) &&
        (g_ucm_srv_p->dial_info.is_wait_dial == MMI_FALSE))
    {
        /* Auto redial indication */
        memset(&redial_ind, 0, sizeof(srv_ucm_auto_redial_ind_struct));
        mmi_ucs2ncpy((CHAR *)&redial_ind.display_msg,(CHAR *)&g_ucm_srv_p->auto_redial.display_msg, SRV_UCM_MAX_AUTO_REDIAL_MSG_LEN);
        memcpy(&redial_ind.num_uri, &g_ucm_srv_p->auto_redial.num_uri, SRV_UCM_MAX_NUM_URI_LEN);
        redial_ind.attempt = int_redial_ind->attempt;
        redial_ind.time = int_redial_ind->time;
        redial_ind.abort_hdlr = srv_ucm_auto_redial_abort;
        srv_ucm_send_indication(SRV_UCM_AUTO_REDIAL_IND, &redial_ind);

        /* Start auto redial timer */
        StartTimer(UCM_AUTO_REDIAL_TIMER, g_ucm_srv_p->auto_redial.time * UI_POPUP_NOTIFYDURATION_TIME, srv_ucm_auto_redial_timeout_handler);
    }
    else
    {
        /* Abort the ongoing auto redial action */
        srv_ucm_auto_redial_abort();
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_auto_redial_abort
 * DESCRIPTION
 *  Abort ongoing auto redial action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_auto_redial_abort()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_ucm_srv_p->auto_redial.abort_hdlr)
    {
        /* Auto redial cancel indication */
        srv_ucm_send_indication(SRV_UCM_AUTO_REDIAL_CANCEL_IND, NULL);

        StopTimer(UCM_AUTO_REDIAL_TIMER);
        g_ucm_srv_p->auto_redial.abort_hdlr();
        memset(&g_ucm_srv_p->auto_redial, 0, sizeof(srv_ucm_int_auto_redial_ind_struct));
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_auto_redial_timeout_handler
 * DESCRIPTION
 *  Auto redial timeout function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_auto_redial_timeout_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str_len = 0, num_len = 0;
    srv_ucm_dial_act_req_struct dial_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
        str_len = strlen((CHAR *)g_ucm_srv_p->auto_redial.num_uri);
        num_len = (SRV_UCM_MAX_NUM_URI_LEN > str_len) ? (str_len) : (SRV_UCM_MAX_NUM_URI_LEN);

        /* Prepare for the redial data */
        memset(&dial_req, 0, sizeof(srv_ucm_dial_act_req_struct));
        dial_req.call_type = g_ucm_srv_p->auto_redial.call_type;
        dial_req.is_ip_dial = g_ucm_srv_p->auto_redial.is_ip_dial;
        dial_req.phb_data = g_ucm_srv_p->auto_redial.phb_data;
        dial_req.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
        mmi_asc_n_to_ucs2((CHAR *)&dial_req.num_uri, (CHAR *)g_ucm_srv_p->auto_redial.num_uri, num_len);

        memset(&g_ucm_srv_p->auto_redial, 0, sizeof(srv_ucm_int_auto_redial_ind_struct));

        /* Perform dial action */
        srv_ucm_act_request(SRV_UCM_DIAL_ACT, &dial_req, NULL, NULL);
    }
    else
    {
        if (g_ucm_srv_p->auto_redial.abort_hdlr)
        {
            g_ucm_srv_p->auto_redial.abort_hdlr();
            memset(&g_ucm_srv_p->auto_redial, 0, sizeof(srv_ucm_int_auto_redial_ind_struct));            
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_call_cost_ind
 * DESCRIPTION
 *  Call cost indication
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_call_cost_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_call_cost_ind_struct *int_cost_ind = (srv_ucm_int_call_cost_ind_struct*)ind_struct;
    srv_ucm_call_cost_ind_struct cost_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Call cost indication */
    memset(&cost_ind, 0, sizeof(srv_ucm_call_cost_ind_struct));
    memcpy(&cost_ind.uid_info, &int_cost_ind->uid_info, sizeof(srv_ucm_id_info_struct));
    memset(g_ucm_srv_p->call_misc.call_cost_symbol, 0, 4 * ENCODING_LENGTH * sizeof(U8));
    mmi_ucs2cpy((CHAR *) g_ucm_srv_p->call_misc.call_cost_symbol, (CHAR *) int_cost_ind->currency_symbol);
    cost_ind.currency_symbol = g_ucm_srv_p->call_misc.call_cost_symbol;
    cost_ind.cost_unit = int_cost_ind->cost_unit;
    cost_ind.total_cost_unit = int_cost_ind->total_cost_unit;
    cost_ind.price_per_unit = int_cost_ind->price_per_unit;
    cost_ind.warning = int_cost_ind->warning;
    srv_ucm_send_indication(SRV_UCM_CALL_COST_IND, &cost_ind);
}

#ifdef __MMI_VOIP__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_start_processing_ind
 * DESCRIPTION
 *  Call service starts to perform its proprietary action
 * PARAMETERS
 *  ind_struct       [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_start_processing_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_start_processing_ind_struct *int_start_ind = (srv_ucm_int_start_processing_ind_struct*)ind_struct;
    srv_ucm_start_processing_ind_struct start_ind;
    srv_ucm_index_info_struct index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    memset(&index, 0, sizeof(srv_ucm_index_info_struct));
    if (srv_ucm_query_index_by_id(&int_start_ind->uid_info, &index) == MMI_FALSE)
    {
        MMI_ASSERT(0);
    }
    
    g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].proc_state = SRV_UCM_DO_PROCESS_STATE;

    /* Start processing indication */
    mmi_ucs2ncpy((CHAR *)start_ind.content, (CHAR *)int_start_ind->content, SRV_UCM_MAX_DISP_MSG_LEN);
    srv_ucm_send_indication(SRV_UCM_START_PROCESSING_IND, &start_ind);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_stop_processing_ind
 * DESCRIPTION
 *  Call service stops to perform its proprietary action
 * PARAMETERS
 *  ind_struct      [IN]            Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_stop_processing_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_stop_processing_ind_struct *int_stop_ind = (srv_ucm_int_stop_processing_ind_struct*)ind_struct;
    srv_ucm_stop_processing_ind_struct stop_ind;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

    /* Stop processing indication */
    memset(&stop_ind, 0, sizeof(srv_ucm_stop_processing_ind_struct));
    mmi_ucs2ncpy((CHAR *)stop_ind.disp_msg, (CHAR *)int_stop_ind->disp_msg, SRV_UCM_MAX_DISP_MSG_LEN);
    stop_ind.image_id = int_stop_ind->image_id;
    stop_ind.tone_id = int_stop_ind->tone_id;
    srv_ucm_send_indication(SRV_UCM_STOP_PROCESSING_IND, &stop_ind);
}
#endif /* __MMI_VOIP__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_replace_ind
 * DESCRIPTION
 *  replace indication
 * PARAMETERS
 *  ind_struct      [IN]        Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_replace_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_replace_ind_struct *int_replace_ind = (srv_ucm_int_replace_ind_struct*)ind_struct;
    srv_ucm_index_info_struct index;
#ifdef __MMI_VOIP__
    U32 end_tick_time;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_ucm_query_index_by_id(&int_replace_ind->old_uid_info, &index) == FALSE)
    {
        ASSERT(0);
    }

#ifdef __MMI_VOIP__
    if (int_replace_ind->log_call_now == MMI_TRUE)
    {
        if (mmi_dt_is_valid(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time))
        {
            kal_get_time(&end_tick_time);
            g_ucm_srv_p->call_end.call_duration = kal_ticks_to_secs(end_tick_time - g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_tick_time);

            /* Do not log call duration for SAT call */
            if (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id != SRV_UCM_MODULE_ORIGIN_SAT)
            {
                /* write call log for the old call */
                srv_ucm_log_call_duration(index.group_index, index.call_index);
            }
        }
        else
        {
            g_ucm_srv_p->call_end.call_duration = 0;

            /* Do not log call history for SAT call */
            if (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id != SRV_UCM_MODULE_ORIGIN_SAT)
            {
                if (g_ucm_srv_p->call_list.group_info[index.group_index].call_state == SRV_UCM_OUTGOING_STATE)
                {
                    kal_get_time(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_tick_time);
                    DTGetRTCTime(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time);
                    srv_ucm_log_call_history(index.group_index, index.call_index, MMI_FALSE);
                }
                else if (g_ucm_srv_p->call_list.group_info[index.group_index].call_state == SRV_UCM_INCOMING_STATE)
                {
                    srv_ucm_log_call_history(index.group_index, index.call_index, MMI_FALSE);
                }
                else
                {
                    MMI_ASSERT(0); /* should either outgoing call or incoming call */
                }
            }
        }
    }
#endif /* __MMI_VOIP__ */

    /* update the uid */
    g_ucm_srv_p->call_list.group_info[index.group_index].group_id = int_replace_ind->new_uid_info.group_id;
    g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_id = int_replace_ind->new_uid_info.call_id;

    /* update the remote info */
    memcpy(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].remote_info, &int_replace_ind->remote_info, sizeof(srv_ucm_remote_info_struct));

    if (g_ucm_srv_p->call_list.group_info[index.group_index].call_state == SRV_UCM_ACTIVE_STATE ||
        g_ucm_srv_p->call_list.group_info[index.group_index].call_state == SRV_UCM_HOLD_STATE)
    {
        /* update mo/mt origin */
        g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].call_origin = int_replace_ind->call_origin;

        /* reset start time */
        if (int_replace_ind->reset_duration == MMI_TRUE)
        {
            kal_get_time(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_tick_time);
            DTGetRTCTime(&g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].start_time);
        }

    #ifdef __MMI_VOIP__
        /* write call log for the new call */
        if (int_replace_ind->log_call_now == MMI_TRUE)
        {
            /* do not log call history for SAT call */
            if (g_ucm_srv_p->call_list.group_info[index.group_index].call_info[index.call_index].module_id != SRV_UCM_MODULE_ORIGIN_SAT)
            {
                srv_ucm_log_call_history(index.group_index, 0, MMI_TRUE);
            }
        }
    #endif /* __MMI_VOIP__ */
    }

    /* Refresh indication */
    srv_ucm_send_indication(SRV_UCM_REFRESH_IND, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_cancel_query_ind
 * DESCRIPTION
 *  Call service sends indication to cancel query confirm
 * PARAMETERS
 *  call_type      [IN]         Call type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_cancel_query_ind(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_ucm_srv_p->int_cnf.call_type & call_type)
    {
        srv_ucm_send_indication(SRV_UCM_QUERY_CANCEL_IND, NULL);
        memset(&g_ucm_srv_p->int_cnf, 0, sizeof(srv_ucm_int_cnf_struct));
    }
    else
    {
        /* Current query confirm is not initiated by this call service */
        return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_dial_ind
 * DESCRIPTION
 *  Outgoing call initiated by protocol, only for data call
 * PARAMETERS
 *  ind_struct      [IN]         Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_dial_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0;
    srv_ucm_int_dial_ind_struct *int_dial_ind = (srv_ucm_int_dial_ind_struct*)ind_struct;
    srv_ucm_outgoing_call_ind_struct outgoing_call_ind;
    srv_ucm_act_rsp_struct rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Only for csd call */

    memset(&rsp, 0, sizeof(srv_ucm_act_rsp_struct));

    if ((int_dial_ind->result_info.result == SRV_UCM_RESULT_OK) &&
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))
    {
        srv_ucm_sync_call_list(int_dial_ind->call_list);
        
        memcpy(&g_ucm_srv_p->mo_mt_display, &int_dial_ind->display_info, sizeof(srv_ucm_display_info_struct));

        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_COMP_PROCESS_STATE);
        
        /* Dial is always the second action of a compound action */
        MMI_ASSERT(srv_ucm_get_process_state(SRV_UCM_WAIT_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list) == 0);

        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        /* Only one outgoing call exists */
        if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == 1)
        {
            /* Do not suspend Alarm or background play for csd outgoing call */
            if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) == 0)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_SUSPEND_BACKGROUND_PLAY);
                mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM);
            }
        }

        /* Abort the ongoing auto redial action */
        srv_ucm_auto_redial_abort();

        /* Outgoing call indication */
        memset(&outgoing_call_ind, 0, sizeof(srv_ucm_outgoing_call_ind_struct));
        memcpy(&outgoing_call_ind.display_info, &int_dial_ind->display_info, sizeof(srv_ucm_display_info_struct));
        memcpy(&outgoing_call_ind.remote_info, &int_dial_ind->remote_info, sizeof(srv_ucm_remote_info_struct));
        memcpy(&outgoing_call_ind.uid_info, &int_dial_ind->uid_info, sizeof(srv_ucm_id_info_struct));
        outgoing_call_ind.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
        srv_ucm_send_indication(SRV_UCM_OUTGOING_CALL_IND, (void *)&outgoing_call_ind);

        /* Action notify */
        rsp.result_info.result = SRV_UCM_RESULT_OK;
        srv_ucm_send_act_notify(SRV_UCM_DIAL_ACT, SRV_UCM_DIAL_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);
    }
    else /* The outgoing call is not allowed now, auto reject it */
    {
        if ((int_dial_ind->result_info.result == SRV_UCM_RESULT_OK) &&
            (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
        {
            rsp.result_info.result = SRV_UCM_RESULT_UCM_BUSY;
            mmi_ucs2ncpy((CHAR *)rsp.result_info.error_msg, (CHAR *)GetString(srv_ucm_query_error_message(rsp.result_info.result)), SRV_UCM_MAX_ERR_MSG_LEN);

            /* Auto reject the outgoing call when collision with incoming call */
            srv_ucm_int_act_request(SRV_UCM_INT_AUTO_REJECT_ACT, &(int_dial_ind->uid_info), NULL, NULL);
            srv_ucm_int_act_request(SRV_UCM_INT_FORCE_RELEASE_ACT, &(int_dial_ind->uid_info), NULL, NULL);
        }

        /* clear invalid id entry */
        srv_ucm_sync_call_list(int_dial_ind->call_list);

        if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
        {
            /* Call service does not have this call yet, so cannot rely on call list of call service */
            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;

            if (g_ucm_srv_p->call_list.group_info[group_index].call_info[0].proc_state == SRV_UCM_WAIT_PROCESS_STATE)
            {
                g_ucm_srv_p->call_list.group_info[group_index].num_call--;
                g_ucm_srv_p->call_list.num_group--;
                srv_ucm_reset_group_entry(group_index);
                srv_ucm_call_status_change_callback();
            }
        }
        
        srv_ucm_set_process_state(-1, -1, SRV_UCM_WAIT_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_DO_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);
        srv_ucm_set_process_state(-1, -1, SRV_UCM_COMP_PROCESS_STATE, SRV_UCM_IDLE_PROCESS_STATE);

        /* Action notify */
        if (int_dial_ind->result_info.result != SRV_UCM_RESULT_OK)
        {
            memcpy(&rsp.result_info, &int_dial_ind->result_info, sizeof(srv_ucm_result_info_struct));
        }
        srv_ucm_send_act_notify(SRV_UCM_DIAL_ACT, SRV_UCM_DIAL_ACT, SRV_UCM_ACT_NOTIFY_TYPE_END, (void *)&rsp);
    }

    g_ucm_srv_p->call_misc.curr_action = SRV_UCM_NO_ACT;

}

#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_start_count_ind
 * DESCRIPTION
 *  Call service sends indication to start counting of call duration
 * PARAMETERS
 *  ind_struct      [IN]         Indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_start_count_ind(void *ind_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Reset the call start time */
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) != 1)
    {
        MMI_ASSERT(0);
    }
    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
    kal_get_time(&g_ucm_srv_p->call_list.group_info[group_index].call_info[0].start_tick_time);
    DTGetRTCTime(&g_ucm_srv_p->call_list.group_info[group_index].call_info[0].start_time);

    /* do not log call history for SAT call */
    if (g_ucm_srv_p->call_list.group_info[group_index].call_info[0].module_id != SRV_UCM_MODULE_ORIGIN_SAT)
    {
        srv_ucm_log_call_history(group_index, 0, MMI_TRUE);
    }
    g_ucm_srv_p->call_misc.is_count_stopped = MMI_FALSE;

    srv_ucm_send_indication(SRV_UCM_START_COUNT_IND, NULL);
    return;
}
#endif /* __MMI_VIDEO_TELEPHONY__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_cnf_ind
 * DESCRIPTION
 *  Handler for query confirm indication
 * PARAMETERS
 *  call_type:       [IN]        Call type
 *  ind_struct       [IN]        Indication structure
 *  callback:        [IN]        Confirm callback function provided by call srv
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_query_cnf_ind(srv_ucm_call_type_enum call_type, void *ind_struct, srv_ucm_int_cnf_callback_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_cnf_ind_struct *int_query_cnf_ind = (srv_ucm_int_query_cnf_ind_struct*)ind_struct;
    srv_ucm_int_query_cnf_struct int_query_cnf;
    srv_ucm_query_cnf_ind_struct query_cnf_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&int_query_cnf, 0, sizeof(srv_ucm_int_query_cnf_struct));

    if (srv_ucm_is_pending_action() == MMI_FALSE)
    {
        if (((srv_ucm_is_emergency_call() == MMI_TRUE) && (int_query_cnf_ind->disp_condition & SRV_UCM_DISP_ECC)) ||
            (srv_ucm_is_emergency_call() == MMI_FALSE))
        {
            if (((srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) && 
                (int_query_cnf_ind->disp_condition & SRV_UCM_DISP_OUTGOING)) ||
                (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))
            {
                if (((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) && 
                    (int_query_cnf_ind->disp_condition & SRV_UCM_DISP_INCOMING)) ||
                    (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))
                {
                    /* Send query confirm indication */
                    memset(&query_cnf_ind, 0, sizeof(srv_ucm_query_cnf_ind_struct));
                    g_ucm_srv_p->int_cnf.call_type = call_type;
                    g_ucm_srv_p->int_cnf.cnf_callback = callback;
                    mmi_ucs2ncpy((CHAR *)query_cnf_ind.content, (CHAR *)int_query_cnf_ind->content, SRV_UCM_MAX_DISP_MSG_LEN);
                    srv_ucm_send_cnf_indication(SRV_UCM_QUERY_CNF_IND, &query_cnf_ind, srv_ucm_query_cnf);
                    return;
                }
            }
        }
    }

    /* Can't process confirm now, send confirm to call service */
    int_query_cnf.result = SRV_UCM_QUERY_CNF_ABORT;
    callback(call_type, SRV_UCM_INT_QUERY_CNF, &int_query_cnf);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_cnf
 * DESCRIPTION
 *  Callback function for query confirm
 * PARAMETERS
 *  cnf_op_code:     [IN]        Confirm op-code
 *  cnf_data:        [IN]        Confirm structure
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_query_cnf(srv_ucm_cnf_opcode_enum cnf_op_code, void *cnf_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_query_cnf_struct *query_cnf = (srv_ucm_query_cnf_struct*)cnf_data;
    srv_ucm_int_query_cnf_struct int_query_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Send confirm to call service */
    memset(&int_query_cnf, 0, sizeof(srv_ucm_int_query_cnf_struct));
    int_query_cnf.result = query_cnf->result_info;
    g_ucm_srv_p->int_cnf.cnf_callback(g_ucm_srv_p->int_cnf.call_type, SRV_UCM_INT_QUERY_CNF, &int_query_cnf);

    memset(&g_ucm_srv_p->int_cnf, 0, sizeof(srv_ucm_int_cnf_struct));
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_dial_cnf_ind
 * DESCRIPTION
 *  Approve for outgoing call initiated by protocol, only for csd call or data call
 * PARAMETERS
 *  call_type:       [IN]        Call type
 *  ind_struct       [IN]        Indication structure
 *  callback:        [IN]        Confirm callback function provided by call srv
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_dial_cnf_ind(srv_ucm_call_type_enum call_type, void *ind_struct, srv_ucm_int_cnf_callback_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_dial_act_req_struct dial_req;
    srv_ucm_int_dial_cnf_ind_struct *int_dial_cnf_ind = (srv_ucm_int_dial_cnf_ind_struct*)ind_struct;
    srv_ucm_int_dial_cnf_struct int_dial_cnf;
    S32 free_group = g_ucm_srv_p->call_list.num_group;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&int_dial_cnf, 0, sizeof(srv_ucm_int_dial_cnf_struct));

    /* Only for csd call */
    if ((call_type & SRV_UCM_CSD_CALL_TYPE_ALL) &&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) &&
        (g_ucm_srv_p->call_misc.curr_action == SRV_UCM_NO_ACT))
    {
        g_ucm_srv_p->call_misc.curr_action = SRV_UCM_DIAL_ACT;

        /* Add call info to call table */
        g_ucm_srv_p->call_list.group_info[free_group].group_id = SRV_UCM_INVALID_ID;
        g_ucm_srv_p->call_list.group_info[free_group].call_info[0].call_id = SRV_UCM_INVALID_ID;
        g_ucm_srv_p->call_list.group_info[free_group].call_type = call_type;
        g_ucm_srv_p->call_list.group_info[free_group].call_state = SRV_UCM_OUTGOING_STATE;
        memcpy(&g_ucm_srv_p->call_list.group_info[free_group].call_info[0].remote_info.num_uri, int_dial_cnf_ind->num_uri, SRV_UCM_MAX_NUM_URI_LEN);
        g_ucm_srv_p->call_list.group_info[free_group].call_info[0].call_origin = SRV_UCM_INT_MO_ORIGIN;
        g_ucm_srv_p->call_list.group_info[free_group].call_info[0].proc_state = SRV_UCM_DO_PROCESS_STATE;
        g_ucm_srv_p->call_list.group_info[free_group].call_info[0].act_type = SRV_UCM_DIAL_ACT;
        g_ucm_srv_p->call_list.group_info[free_group].num_call++;
        g_ucm_srv_p->call_list.num_group++;

        /* Send action start notify */
        memset(&dial_req, 0, sizeof(srv_ucm_dial_act_req_struct));
        dial_req.call_type = call_type;
        memcpy(&dial_req.num_uri, int_dial_cnf_ind->num_uri, SRV_UCM_MAX_NUM_URI_LEN);
        srv_ucm_send_act_notify(SRV_UCM_DIAL_ACT, SRV_UCM_DIAL_ACT, SRV_UCM_ACT_NOTIFY_TYPE_START, (void *)&dial_req);

        int_dial_cnf.result = MMI_TRUE;
    }
    else /* The outgoing call is not allowed now, don't approve it */
    {
        int_dial_cnf.result = MMI_FALSE;
    }

    /* Send confirm to call service */
    callback(call_type, SRV_UCM_INT_DIAL_CNF, &int_dial_cnf);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_call_present_cnf_ind
 * DESCRIPTION
 *  Approve for incoming call
 * PARAMETERS
 *  call_type:       [IN]        Call type
 *  ind_struct       [IN]        Indication structure
 *  callback:        [IN]        Confirm callback function provided by call srv
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_call_present_cnf_ind(srv_ucm_call_type_enum call_type, void *ind_struct, srv_ucm_int_cnf_callback_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ucs2_number[SRV_UCM_MAX_NUM_URI_LEN + 1];
    S32 group_index = 0, call_index = 0;
    MMI_BOOL dial_act_ongoing = MMI_FALSE;
    srv_ucm_int_call_present_cnf_ind_struct *int_mt_cnf_ind = (srv_ucm_int_call_present_cnf_ind_struct*)ind_struct;
    srv_ucm_int_call_present_cnf_struct int_mt_cnf;
#if defined(__MMI_CM_BLACK_LIST__) && defined(__MMI_CM_BLACK_LIST_EXT__) 
    srv_callset_blacklist_adv_param_struct adv_param;
#endif /* defined(__MMI_CM_BLACK_LIST__) && defined(__MMI_CM_BLACK_LIST_EXT__) */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(ucs2_number, 0, (SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((CHAR *) ucs2_number, (CHAR *) int_mt_cnf_ind->num_uri);
    memcpy(&int_mt_cnf.uid_info, &int_mt_cnf_ind->uid_info, sizeof(srv_ucm_id_info_struct));

    /* Any DIAL_ACT ongoing? */
    if (srv_ucm_get_process_state(SRV_UCM_DO_PROCESS_STATE, g_ucm_srv_p->call_misc.index_list) > 0)
    {
        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
        call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
        if (g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].act_type == SRV_UCM_DIAL_ACT)
        {
            dial_act_ongoing = MMI_TRUE;
        }
    }

#if defined(__MMI_CM_BLACK_LIST__) && defined(__MMI_CM_BLACK_LIST_EXT__) 
    srv_callset_blacklist_init_advanced_param(&adv_param);
    adv_param.call_type = srv_ucm_query_blacklist_call_type(int_mt_cnf_ind->uid_info.call_type);
#endif /* defined(__MMI_CM_BLACK_LIST__) && defined(__MMI_CM_BLACK_LIST_EXT__) */

    /* When AT is disconnecting call, it cannot be interrupted by incoming call */
    if ((g_ucm_srv_p->call_misc.curr_module == SRV_UCM_MODULE_ORIGIN_COMMON) &&
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) &&
        !((srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) != 0) && (dial_act_ongoing == MMI_FALSE)) &&
        (g_ucm_srv_p->call_list.num_group < SRV_UCM_MAX_GROUP) &&
        !((g_ucm_srv_p->call_list.num_group == SRV_UCM_MAX_GROUP - 1) && (srv_ucm_query_curr_action() == SRV_UCM_SPLIT_ACT)) &&
#ifdef __MMI_CM_BLACK_LIST__
    #ifdef __MMI_CM_BLACK_LIST_EXT__
        (srv_callset_blacklist_is_blocked_number((U8)mmi_ucs2strlen((CHAR *)ucs2_number), ucs2_number, &adv_param) == MMI_FALSE) &&
    #else /* __MMI_CM_BLACK_LIST_EXT__ */
        (srv_callset_blacklist_is_blocked_number((U8)mmi_ucs2strlen((CHAR *)ucs2_number), ucs2_number, NULL) == MMI_FALSE) &&
    #endif /* __MMI_CM_BLACK_LIST_EXT__  */
#endif /* __MMI_CM_BLACK_LIST__ */
        MMI_TRUE)
    {
        int_mt_cnf.result = MMI_TRUE;
    }
    else /* The outgoing call is not allowed now, don't approve it */
    {
        int_mt_cnf.result = MMI_FALSE;
    }

    /* Send confirm to call service */
    callback(call_type, SRV_UCM_INT_CALL_PRESENT_CNF, &int_mt_cnf);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_call_status_change_callback
 * DESCRIPTION
 *  Execute call status change callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_call_status_change_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_status_change_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Emit post event */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_STATUS_CHANGE);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);

    srv_ucm_call_scenario_control();
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_intercept
 * DESCRIPTION
 *  The function to intercept the outgoing call
 * PARAMETERS
 *  call_type:         [IN]        Call type, can be bitwise
 *  number:          [IN]        Number, SRV_UCM_MAX_NUM_URI_LEN
 :  module_id:        [IN]        Module id, who initiates the outoging call
 * RETURNS
 *  MMI_TRUE means the outgoing call is intercepted, MMI_FALSE means not
 *****************************************************************************/
MMI_BOOL srv_ucm_intercept(srv_ucm_call_type_enum call_type, U16 *number, srv_ucm_module_origin_enum module_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_intercept_query_evt_struct evt;
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (number == NULL)
    {
        return MMI_FALSE;
    }

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_INTERCEPT_QUERY);
    evt.call_type = call_type;
    mmi_ucs2_n_to_asc((CHAR *)&evt.num_uri, (CHAR *)number, SRV_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
    evt.module_id = module_id;
    result = MMI_FRM_CB_EMIT_EVENT(&evt);

    return (result == SRV_UCM_INTERCEPT_QUERY_RESULT_YES)? MMI_TRUE : MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_reject_by_sms
 * DESCRIPTION
 *  The function to reject the MT call and send SMS
 * PARAMETERS
 *  mt_call_uid:     [IN]        MT call id
 *  ucs2_content:    [IN]        SMS content
 *  sim_id:          [IN]        Send by which SIM
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_ucm_reject_by_sms(srv_ucm_single_call_act_req_struct mt_call_uid, CHAR* ucs2_content, mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM_REJECT_BY_SMS__
    S32 i;
    MMI_BOOL valid_sim = MMI_FALSE;
    mmi_sim_enum sim;
    srv_ucm_index_info_struct index;
    srv_ucm_single_call_act_req_struct single_call_req;
#endif /* __MMI_UCM_REJECT_BY_SMS__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MMI_UCM_REJECT_BY_SMS__
    return MMI_FALSE;
#else /* __MMI_UCM_REJECT_BY_SMS__ */
    if (srv_ucm_query_reject_by_sms_permit(mt_call_uid) == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
    {
        if (sim_id == sim)
        {
            valid_sim = MMI_TRUE;
            break;
        }
    }

    if (valid_sim == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    
    if (g_ucm_srv_p->rej_by_sms.message != NULL)
    {
        OslMfree(g_ucm_srv_p->rej_by_sms.message);
        g_ucm_srv_p->rej_by_sms.message = NULL;
    }

    /* SMS content */    
    g_ucm_srv_p->rej_by_sms.message = OslMalloc((mmi_ucs2strlen((CHAR *)ucs2_content) + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR *)g_ucm_srv_p->rej_by_sms.message, (CHAR *)ucs2_content);

    /* Call id */
    memcpy(&g_ucm_srv_p->rej_by_sms.uid_info, &mt_call_uid.action_uid, sizeof(srv_ucm_id_info_struct));

    /* Destination number */
    srv_ucm_query_index_by_id(&mt_call_uid.action_uid, &index);
    memset(&g_ucm_srv_p->rej_by_sms.dest_num, 0, (SRV_SMS_MAX_ADDR_LEN + 1));
    memcpy(&g_ucm_srv_p->rej_by_sms.dest_num, 
        &g_ucm_srv_p->call_list.group_info[index.group_index].call_info[0].remote_info.num_uri, 
        SRV_SMS_MAX_ADDR_LEN);

    /* Use which SIM to send */
    g_ucm_srv_p->rej_by_sms.sim_id = sim_id;

    /* End the incoming call */
    memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
    single_call_req.action_uid.call_type = g_ucm_srv_p->call_list.group_info[index.group_index].call_type;
    single_call_req.action_uid.group_id = g_ucm_srv_p->call_list.group_info[index.group_index].group_id;
    single_call_req.action_uid.call_id = g_ucm_srv_p->call_list.group_info[index.group_index].call_info[0].call_id;
    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, (void *)&single_call_req, NULL, NULL);

    return MMI_TRUE;
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_short_string_crss
 * DESCRIPTION
 *  This function is to intercept outgoing call, if the number is short string crss
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  SRV_UCM_INTERCEPT_QUERY_RESULT_YES means the number is short string crss; 
 *  SRV_UCM_INTERCEPT_QUERY_RESULT_NO means the number is not short string crss.
 *****************************************************************************/
mmi_ret srv_ucm_short_string_crss(mmi_event_struct* para)
{
#ifdef __MMI_UCM_SHORT_STIRNG_CRSS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_intercept_query_evt_struct *evt = NULL;
    PU8 num_buf = NULL;
    srv_ucm_single_call_act_req_struct single_call_req;
    srv_ucm_single_group_act_req_struct single_group_req;
    srv_ucm_multiple_group_act_req_struct multiple_group_req;
    srv_ucm_hold_and_accept_act_req_struct hold_and_accept_req;
    srv_ucm_cd_or_ct_act_req_struct cd_or_ct_req;
    srv_ucm_ect_act_req_struct ect_req;
    srv_ucm_notify_ind_struct notify_ind;
    srv_ucm_short_string_crss_evt_struct post_evt;
    S32 group_index = 0, call_index = 0, call_id = 0;
    pBOOL valid_crss = MMI_FALSE;
    void *act_req_data = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_SHORT_STRING_CRSS);

    evt = (srv_ucm_intercept_query_evt_struct *)para;
    num_buf = evt->num_uri;

    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) ||
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_AT) || 
    #if (MMI_MAX_SIM_NUM >= 2)
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM2) ||
    #if (MMI_MAX_SIM_NUM >= 3)
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM3) ||
    #if (MMI_MAX_SIM_NUM == 4)
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_AT_SIM4) ||
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        (evt->module_id == SRV_UCM_MODULE_ORIGIN_SAT))
    {
        return SRV_UCM_INTERCEPT_QUERY_RESULT_NO;
    }

    MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_UCM_SHORT_STRING_CRSS);

    /* The second digit must be NULL, *, or 0~9 */
    if ((*(num_buf + 1) == 0) || (*(num_buf + 1) == '*') || ((*(num_buf + 1) >= '0') && (*(num_buf + 1) <= '9')))
    {
        valid_crss = MMI_TRUE;
    }

    if (valid_crss == MMI_TRUE)
    {
        switch (*num_buf)
        {
            case '0':
                if ('\0' == *(num_buf + 1))
                {
                    /* 0 send */
                    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) != 0)
                    {
                        /* Incoming call exists, reject the incoming call or waiting call */
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_0_REJECT_INCOMING_OR_WAITING);
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                        call_index = g_ucm_srv_p->call_misc.index_list[0].call_index;
                        memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
                        single_call_req.action_uid.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                        single_call_req.action_uid.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                        single_call_req.action_uid.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
                        act_req_data = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                        memcpy(act_req_data, &single_call_req, sizeof(srv_ucm_single_call_act_req_struct));

                        /* Send post event to perform the action */
                        post_evt.act_op = SRV_UCM_END_SINGLE_ACT;
                        post_evt.act_data = act_req_data;
                        mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                        return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                    }
                    else
                    {
                        /* No incoming call, drop the held call */
                        for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
                        {
                            if (g_ucm_srv_p->call_list.group_info[group_index].call_state == SRV_UCM_HOLD_STATE)
                            {
                                if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                                {
                                    /* Drop the held conference */
                                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_0_HANGUP_ALL_HELD);
                                    memset(&single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
                                    single_group_req.action_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                                    single_group_req.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                                    act_req_data = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                                    memcpy(act_req_data, &single_group_req, sizeof(srv_ucm_single_group_act_req_struct));

                                    /* Send post event to perform the action */
                                    post_evt.act_op = SRV_UCM_END_CONFERENCE_ACT;
                                    post_evt.act_data = act_req_data;
                                    mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                                    return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                                }
                                else if (g_ucm_srv_p->call_list.group_info[group_index].num_call == 1)
                                {
                                    /* Drop the single held call */
                                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_0_HANGUP_SINGLE_HELD);
                                    memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
                                    single_call_req.action_uid.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                                    single_call_req.action_uid.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                                    single_call_req.action_uid.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id;
                                    act_req_data = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                                    memcpy(act_req_data, &single_call_req, sizeof(srv_ucm_single_call_act_req_struct));

                                    /* Send post event to perform the action */
                                    post_evt.act_op = SRV_UCM_END_SINGLE_ACT;
                                    post_evt.act_data = act_req_data;
                                    mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                                    return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                                }
                            }
                        }
                    }
                    valid_crss = MMI_TRUE;
                    break;
                }
                valid_crss = MMI_FALSE;
                break;
                
            case '1':
                if ('\0' == *(num_buf + 1))
                {
                    /* 1 send */
                    if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                        ((srv_ucm_query_call_count((srv_ucm_call_state_enum)(SRV_UCM_OUTGOING_STATE | SRV_UCM_INCOMING_STATE | SRV_UCM_HOLD_STATE), SRV_UCM_CALL_TYPE_ALL, NULL) == 0)))
                    {
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                        if (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1)
                        {
                            /* Drop the active conference */
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_1_END_CONF_ACTIVE);
                            memset(&single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
                            single_group_req.action_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            single_group_req.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            act_req_data = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                            memcpy(act_req_data, &single_group_req, sizeof(srv_ucm_single_group_act_req_struct));
                            
                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_END_CONFERENCE_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                        else
                        {
                            /* Drop the single active call */
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_1_END_SINGLE_ACTIVE);
                            memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
                            single_call_req.action_uid.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            single_call_req.action_uid.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            single_call_req.action_uid.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id;
                            act_req_data = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                            memcpy(act_req_data, &single_call_req, sizeof(srv_ucm_single_call_act_req_struct));

                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_END_SINGLE_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                    }
                    else if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
 
                        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1)
                        {
                            valid_crss = MMI_TRUE;
                            break;
                        }
                        else
                        {
                            memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
                            single_call_req.action_uid.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            single_call_req.action_uid.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            single_call_req.action_uid.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id;
                            act_req_data = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                            memcpy(act_req_data, &single_call_req, sizeof(srv_ucm_single_call_act_req_struct));

                            if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) != 0)
                            {
                                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_1_END_ACTIVE_AND_ACCEPT);

                                /* Send post event to perform the action */
                                post_evt.act_op = SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT;
                                post_evt.act_data = act_req_data;
                                mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                                return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                            }
                            else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) != 0)
                            {
                                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_1_ACCEPT);

                                /* Send post event to perform the action */
                                post_evt.act_op = SRV_UCM_ACCEPT_ACT;
                                post_evt.act_data = act_req_data;
                                mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                                return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                            }
                        }
                    }
                    else if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
                    {
                        valid_crss = MMI_TRUE;
                        break;
                    }
                    else
                    {
                        if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) &&
                            (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0))
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_1_END_ACTIVE_AND_RETRIEVE);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            memset(&single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
                            single_group_req.action_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            single_group_req.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            act_req_data = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                            memcpy(act_req_data, &single_group_req, sizeof(srv_ucm_single_group_act_req_struct));

                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);
 
                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_1_RETRIEVE);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            memset(&single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
                            single_group_req.action_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            single_group_req.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            act_req_data = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                            memcpy(act_req_data, &single_group_req, sizeof(srv_ucm_single_group_act_req_struct));

                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_RETRIEVE_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                        else
                        {
                            valid_crss = MMI_TRUE;
                            break;
                        }
                    }
                }
                else if ('\0' == *(num_buf + 2))
                {
                    /* 1x send */
                    call_id = (S32) atoi((void*)(num_buf + 1));

                    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
                    {
                        valid_crss = MMI_TRUE;
                        break;
                    }

                    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
                    {
                        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
                        {
                            if ((g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id == call_id) &&
                                (g_ucm_srv_p->call_list.group_info[group_index].call_state == SRV_UCM_ACTIVE_STATE))
                            {
                                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_1X_HANGUP_ACTIVE, group_index, call_index, call_id);
                                memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
                                single_call_req.action_uid.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                                single_call_req.action_uid.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                                single_call_req.action_uid.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
                                act_req_data = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                                memcpy(act_req_data, &single_call_req, sizeof(srv_ucm_single_call_act_req_struct));

                                /* Send post event to perform the action */
                                post_evt.act_op = SRV_UCM_END_SINGLE_ACT;
                                post_evt.act_data = act_req_data;
                                mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                                return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                            }
                        }
                    }
                    valid_crss = MMI_TRUE;
                    break;
                }
                valid_crss = MMI_FALSE;
                break;
    
            case '2':
                if ('\0' == *(num_buf + 1))
                {
                    /* 2 send */
                    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                            (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_2_SWAP);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            memset(&multiple_group_req, 0, sizeof(srv_ucm_multiple_group_act_req_struct));
                            multiple_group_req.active_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            multiple_group_req.active_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            multiple_group_req.other_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            multiple_group_req.other_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;     
                            act_req_data = OslMalloc(sizeof(srv_ucm_multiple_group_act_req_struct));
                            memcpy(act_req_data, &multiple_group_req, sizeof(srv_ucm_multiple_group_act_req_struct));

                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_SWAP_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                        else if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                            (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_2_HOLD_ACTIVE_AND_ACCEPT);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            memset(&hold_and_accept_req, 0, sizeof(srv_ucm_hold_and_accept_act_req_struct));
                            hold_and_accept_req.active_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            hold_and_accept_req.active_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            hold_and_accept_req.mt_call_uid.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            hold_and_accept_req.mt_call_uid.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            hold_and_accept_req.mt_call_uid.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id;
                            act_req_data = OslMalloc(sizeof(srv_ucm_hold_and_accept_act_req_struct));
                            memcpy(act_req_data, &hold_and_accept_req, sizeof(srv_ucm_hold_and_accept_act_req_struct));

                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_HOLD_AND_ACCEPT_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                        else
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_2_ACCEPT);
                            srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
                            single_call_req.action_uid.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            single_call_req.action_uid.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            single_call_req.action_uid.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
                            act_req_data = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                            memcpy(act_req_data, &single_call_req, sizeof(srv_ucm_single_call_act_req_struct));

                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_ACCEPT_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                    }
                    else if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
                    {
                        valid_crss = MMI_TRUE;
                        break;
                    }
                    else
                    {
                        /* No outgoing call or incoming call */
                        if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                            (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_2_SWAP);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            memset(&multiple_group_req, 0, sizeof(srv_ucm_multiple_group_act_req_struct));
                            multiple_group_req.active_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            multiple_group_req.active_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            multiple_group_req.other_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            multiple_group_req.other_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;     
                            act_req_data = OslMalloc(sizeof(srv_ucm_multiple_group_act_req_struct));
                            memcpy(act_req_data, &multiple_group_req, sizeof(srv_ucm_multiple_group_act_req_struct));

                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_SWAP_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                        else if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                            (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_2_HOLD_ACTIVE);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            memset(&single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
                            single_group_req.action_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            single_group_req.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            act_req_data = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                            memcpy(act_req_data, &single_group_req, sizeof(srv_ucm_single_group_act_req_struct));

                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_HOLD_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                        else if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0) &&
                            (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0))
                        {
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_2_RETRIEVE_HELD);
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            memset(&single_group_req, 0, sizeof(srv_ucm_single_group_act_req_struct));
                            single_group_req.action_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                            single_group_req.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            act_req_data = OslMalloc(sizeof(srv_ucm_single_group_act_req_struct));
                            memcpy(act_req_data, &single_group_req, sizeof(srv_ucm_single_group_act_req_struct));

                            /* Send post event to perform the action */
                            post_evt.act_op = SRV_UCM_RETRIEVE_ACT;
                            post_evt.act_data = act_req_data;
                            mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                            return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                        }
                    }
                }
                else if ('\0' == *(num_buf + 2))
                {
                    /* 2x send */
                    call_id = (S8) atoi((void*)(num_buf + 1));

                    if ((call_id == 0) ||
                        (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) ||
                        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
                    {
                        valid_crss = MMI_TRUE;
                        break;
                    }

                    for (group_index = 0; group_index < g_ucm_srv_p->call_list.num_group; group_index++)
                    {
                        for (call_index = 0; call_index < g_ucm_srv_p->call_list.group_info[group_index].num_call; call_index++)
                        {
                            /* check if it is active call, only active call can be splited */
                            if ((g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id == call_id) &&
                                (g_ucm_srv_p->call_list.group_info[group_index].call_state == SRV_UCM_ACTIVE_STATE) &&
                                (g_ucm_srv_p->call_list.group_info[group_index].num_call > 1))
                            {
                                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_2X_SPLIT, group_index, call_index, call_id);
                                memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
                                single_call_req.action_uid.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                                single_call_req.action_uid.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                                single_call_req.action_uid.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[call_index].call_id;
                                act_req_data = OslMalloc(sizeof(srv_ucm_single_call_act_req_struct));
                                memcpy(act_req_data, &single_call_req, sizeof(srv_ucm_single_call_act_req_struct));

                                /* Send post event to perform the action */
                                post_evt.act_op = SRV_UCM_SPLIT_ACT;
                                post_evt.act_data = act_req_data;
                                mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                                return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                            }
                        }
                    }
                    valid_crss = MMI_TRUE;
                    break;
                }
                valid_crss = MMI_FALSE;
                break;
                
            case '3':
                if ('\0' == *(num_buf + 1))
                {
                    /* 3 send */
                    if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0) &&
                        (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_3_CONF);
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                        memset(&multiple_group_req, 0, sizeof(srv_ucm_multiple_group_act_req_struct));
                        multiple_group_req.active_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                        multiple_group_req.active_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                        srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list);
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                        multiple_group_req.other_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                        multiple_group_req.other_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;     
                        act_req_data = OslMalloc(sizeof(srv_ucm_multiple_group_act_req_struct));
                        memcpy(act_req_data, &multiple_group_req, sizeof(srv_ucm_multiple_group_act_req_struct));

                        /* Send post event to perform the action */
                        post_evt.act_op = SRV_UCM_CONFERENCE_ACT;
                        post_evt.act_data = act_req_data;
                        mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                        return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
                    }
                    valid_crss = MMI_TRUE;
                    break;
                }
                valid_crss = MMI_FALSE;
                break;
                
            case '4':
                if ('*' == *(num_buf + 1))
                {
                    /* 4* send */
                #ifdef __MMI_UCM_DEFLECT__
                    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_4_DEFLECT);
                    
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                        memset(&cd_or_ct_req, 0, sizeof(srv_ucm_cd_or_ct_act_req_struct));
                        cd_or_ct_req.action_uid.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                        cd_or_ct_req.action_uid.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                        cd_or_ct_req.action_uid.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id;
                        mmi_asc_n_to_ucs2((CHAR *)cd_or_ct_req.num_uri, (CHAR *)(num_buf + 2), SRV_UCM_MAX_NUM_URI_LEN);
                        act_req_data = OslMalloc(sizeof(srv_ucm_cd_or_ct_act_req_struct));
                        memcpy(act_req_data, &cd_or_ct_req, sizeof(srv_ucm_cd_or_ct_act_req_struct));

                        /* Send post event to perform the action */
                        post_evt.act_op = SRV_UCM_DEFLECT_ACT;
                        post_evt.act_data = act_req_data;
                        mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                        return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;    
                    }
                #endif /* __MMI_UCM_DEFLECT__ */
                    valid_crss = FALSE;
                    break;
                }
                else if ('\0' == *(num_buf + 1))
                {
                    /* 4 send */
                #ifdef __MMI_UCM_ECT__
                    if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
                    {
                        group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                        memset(&ect_req, 0, sizeof(srv_ucm_ect_act_req_struct));
                        ect_req.first_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                        ect_req.first_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                        
                        if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            ect_req.second_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            ect_req.second_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                        }
                        else if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VOICE_CALL_TYPE_ALL, g_ucm_srv_p->call_misc.index_list) > 0)
                        {
                            group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;
                            ect_req.second_call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
                            ect_req.second_group = g_ucm_srv_p->call_list.group_info[group_index].group_id;
                        }

                        act_req_data = OslMalloc(sizeof(srv_ucm_ect_act_req_struct));
                        memcpy(act_req_data, &ect_req, sizeof(srv_ucm_ect_act_req_struct));
                        
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_4_ECT);

                        /* Send post event to perform the action */
                        post_evt.act_op = SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT;
                        post_evt.act_data = act_req_data;
                        mmi_frm_post_event((mmi_event_struct *)&post_evt, srv_ucm_short_string_crss_act_req, NULL);

                        return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;   
                    }
                #endif /* __MMI_UCM_ECT__ */
                    valid_crss = MMI_TRUE;
                    break;
                }
                valid_crss = MMI_FALSE;
                break;
                
            case '5':
                if ('\0' == *(num_buf + 1))
                {
                    /* 5 send */
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_OP_5_CCBS);
                    /* Not support now */
                    valid_crss = MMI_TRUE;
                    break;
                }
                valid_crss = MMI_FALSE;
                break;

            default:
                valid_crss = MMI_FALSE;
                break;
        }
    }

    if (valid_crss == MMI_TRUE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_IS_CRSS_INVALID_ACTION);
        memset(&notify_ind, 0, sizeof(srv_ucm_notify_ind_struct));
        notify_ind.image_id = mmi_get_event_based_image(MMI_EVENT_FAILURE);
        mmi_ucs2ncpy((CHAR *)notify_ind.disp_msg, (CHAR *)GetString(STR_GLOBAL_UNFINISHED), SRV_UCM_MAX_DISP_MSG_LEN);
        srv_ucm_send_indication(SRV_UCM_NOTIFY_IND, (void *)&notify_ind);
        return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
    }
#endif /* __MMI_UCM_SHORT_STIRNG_CRSS__ */

    return SRV_UCM_INTERCEPT_QUERY_RESULT_NO;
}

#ifdef __MMI_UCM_SHORT_STIRNG_CRSS__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_short_string_crss_act_req
 * DESCRIPTION
 *  This function is to perform the decided CRSS action
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_ucm_short_string_crss_act_req(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_short_string_crss_evt_struct *evt = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_ucm_short_string_crss_evt_struct *)para;
    srv_ucm_act_request(evt->act_op, evt->act_data, NULL, NULL);
    OslMfree(evt->act_data);

    return MMI_RET_OK;
}
#endif /* __MMI_UCM_SHORT_STIRNG_CRSS__ */

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_shutdown_proc
 * DESCRIPTION
 *  This function is to perform the actions when MS is going to shutdown
 * PARAMETERS
 *  para:     [IN] Event structure passed by callback manager
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_ucm_shutdown_proc(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Turn off speech */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_GSM)
        {
            mdi_audio_speech_codec_stop();
            mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_GSM);
        }
        else if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_WCDMA)
        {
            mdi_audio_speech_codec_stop();
            mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_WCDMA);
        }
    #ifdef __MMI_VIDEO_TELEPHONY__
        else if (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_3G324M)
        {
            mdi_audio_speech_codec_stop();
            mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_3G324M);
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }

    /* End all calls */
    srv_ucm_act_request(SRV_UCM_END_ALL_ACT, NULL, NULL, NULL);

    return MMI_RET_OK;
}


#ifdef __MMI_AUTO_ANSWER_MACHINE__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_autoam_set_state
 * DESCRIPTION
 *  set state of auto answer machine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_autoam_set_state(srv_ucm_autoam_state state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_SET_STATE, state);
    
    g_ucm_srv_p->autoam.state = state;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_autoam_get_state
 * DESCRIPTION
 *  get state of auto answer machine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_autoam_state srv_ucm_autoam_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_GET_STATE, g_ucm_srv_p->autoam.state);
    
    return g_ucm_srv_p->autoam.state;
}
    
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_autoam_set_call_id
 * DESCRIPTION
 *  set call id of auto answer machine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_autoam_set_call_id(srv_ucm_id_info_struct* uid_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_SET_CALL_ID, uid_info->call_type, uid_info->group_id, uid_info->call_id);
    
    memcpy(&g_ucm_srv_p->autoam.uid_info, uid_info, sizeof(srv_ucm_id_info_struct));
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_autoam_reset_call_id
 * DESCRIPTION
 *  reset call id of auto answer machine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_autoam_reset_call_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_RESET_CALL_ID);
    
    memset(&g_ucm_srv_p->autoam.uid_info, 0, sizeof(srv_ucm_id_info_struct));
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_autoam_reset_cntx
 * DESCRIPTION
 *  reset auto answer machine context of UCM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_autoam_reset_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_RESET_CNTX);
    
    srv_ucm_autoam_set_state(SRV_UCM_AUTOAM_STATE_IDLE);
    srv_ucm_autoam_reset_call_id();
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_autoam_start
 * DESCRIPTION
 *  Start auto answer machine 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_autoam_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_index_info_struct index;
    S32 group_index = srv_ucm_query_group_index_by_call_state(SRV_UCM_ACTIVE_STATE);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/                        
    if (srv_ucm_query_index_by_id(&g_ucm_srv_p->autoam.uid_info, &index) == MMI_TRUE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_START);
        
        srv_ucm_autoam_set_state(SRV_UCM_AUTOAM_STATE_START);
        mmi_autoam_start_answer_incoming((U8*)g_ucm_srv_p->call_list.group_info[group_index].call_info[0].remote_info.num_uri, 
                                         (U8*)g_ucm_srv_p->call_list.group_info[group_index].call_info[0].remote_info.disp_name,
                                         (void (*)(mmi_autoam_callback_enum ))srv_ucm_autoam_callback);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_START_FAIL);
        srv_ucm_autoam_reset_cntx();
    }
}
    
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_autoam_timeout_hdlr
 * DESCRIPTION
 *  timeout handler for auto answer machine timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_autoam_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_id_info_struct uid_info;
    U32 call_count = srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_AUTO_ANSWER_MACHINE_CALL_TYPE, NULL);
    U32 total_call_count = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_AUTO_ANSWER_MACHINE_CALL_TYPE, NULL);
    srv_ucm_single_call_act_req_struct single_call_req;
    S32 group_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_TIMEOUT_HDLR);

    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_AUTO_ANSWER_MACHINE_CALL_TYPE, g_ucm_srv_p->call_misc.index_list) != 1)
    {
        /* Do nothing */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_TIMEOUT_HDLR_IGNORE);
        return;
    }

    group_index = g_ucm_srv_p->call_misc.index_list[0].group_index;    
    uid_info.call_type = g_ucm_srv_p->call_list.group_info[group_index].call_type;
    uid_info.group_id = g_ucm_srv_p->call_list.group_info[group_index].group_id;
    uid_info.call_id = g_ucm_srv_p->call_list.group_info[group_index].call_info[0].call_id;

    memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
    memcpy(&single_call_req.action_uid, &uid_info, sizeof(srv_ucm_id_info_struct)); 

    if ((call_count != 0) &&
        (call_count == total_call_count) &&
        (srv_ucm_accept_act_permit(&single_call_req) == SRV_UCM_RESULT_OK))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_TIMEOUT_HDLR_OK);

        srv_ucm_autoam_set_state(SRV_UCM_AUTOAM_STATE_READY);
        srv_ucm_autoam_set_call_id(&uid_info);
        srv_ucm_act_request(SRV_UCM_ACCEPT_ACT, &single_call_req, NULL, NULL);
    }
    else
    {
        /* Do nothing */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_TIMEOUT_HDLR_IGNORE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_autoam_callback
 * DESCRIPTION
 *  callback function for auto answer machine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ucm_autoam_callback(U32 res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_autoam_callback_enum result = res;
    srv_ucm_single_call_act_req_struct single_call_req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_CALLBACK, res);
    
    switch (result)
    {
        case MMI_AUTOAM_CALLBACK_NONE:
        {
            srv_ucm_autoam_reset_cntx();
        }
        break;

        case MMI_AUTOAM_CALLBACK_END:
        {
            srv_ucm_index_info_struct index;

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, 
                TRC_SRV_UCM_AUTOAM_CALLBACK_CALL_UID, 
                g_ucm_srv_p->autoam.uid_info.call_type, 
                g_ucm_srv_p->autoam.uid_info.group_id, 
                g_ucm_srv_p->autoam.uid_info.call_id);

            memset(&single_call_req, 0, sizeof(srv_ucm_single_call_act_req_struct));
            memcpy(&single_call_req.action_uid, &g_ucm_srv_p->autoam.uid_info, sizeof(srv_ucm_id_info_struct)); 

            /* Permit */
            if (srv_ucm_end_single_act_permit(&single_call_req) == SRV_UCM_RESULT_OK)
            {
                /* Perform the end single action */
                srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &single_call_req, NULL, NULL);
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_AUTOAM_CALLBACK_CALL_NOT_FOUND);
            }

            srv_ucm_autoam_reset_cntx();
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

    return;
}
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_at_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_ucm_at_check(void)
{
    if ((g_ucm_srv_p->call_misc.curr_module == SRV_UCM_MODULE_ORIGIN_AT) ||
    #if (MMI_MAX_SIM_NUM >= 2)
        (g_ucm_srv_p->call_misc.curr_module == SRV_UCM_MODULE_ORIGIN_AT_SIM2) ||
    #if (MMI_MAX_SIM_NUM >= 3)
        (g_ucm_srv_p->call_misc.curr_module == SRV_UCM_MODULE_ORIGIN_AT_SIM3) ||
    #if (MMI_MAX_SIM_NUM == 4)
        (g_ucm_srv_p->call_misc.curr_module == SRV_UCM_MODULE_ORIGIN_AT_SIM4) ||
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        MMI_FALSE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


