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
 *  SimCtrlSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  The implementation of SIM control service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "mmi_msg_struct.h"
#include "UtilitySrvGprot.h"
#include "BootupSrvGprot.h"
#include "SimCtrlSrv.h"
#include "SimAccessSrvGprot.h"      /* srv_sim_read_binary */
#include "ps_public_enum.h"
#include "app_str.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "SimCtrlSrvGprot.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "string.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_common.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_utility_gprot.h"

/****************************************************************************
 * Global variables
 ****************************************************************************/

static srv_sim_ctrl_sim_cntx_struct g_srv_sim_ctrl_sim_cntx[SRV_SIM_CTRL_MAX_SIM_NUM];
static U8 g_srv_sim_ctrl_maybe_inserted = MMI_SIM_ALL;

/****************************************************************************
 * Local functions
 ****************************************************************************/

static MMI_BOOL srv_sim_ctrl_cphs_mmi_info_ind_hdlr(void *msg, S32 src_mod);
static MMI_BOOL srv_sim_ctrl_get_imsi_rsp_hdlr(void *msg, S32 src_mod);
static MMI_BOOL srv_sim_ctrl_startup_info_hdlr(void *msg, S32 src_mod);
#if (MMI_MAX_SIM_NUM >= 2)
static U8 srv_sim_ctrl_sim_status_update_ind_hdlr(void *msg);
#endif

#ifdef __R7_EHPLMN__
static void srv_sim_ctrl_ehplmn_file_info_rsp_hdlr(srv_sim_cb_struct* cb_data);
static void srv_sim_ctrl_ehplmn_read_sim_rsp_hdlr(srv_sim_cb_struct* cb_data);
#endif

static void srv_sim_ctrl_emit_imsi_and_hplmn(
                mmi_sim_enum sim,
                srv_sim_ctrl_sim_cntx_struct *sim_cntx,
                MMI_BOOL post);

#ifdef __INVALID_SIM_RECOVERY__
static void srv_sim_ctrl_invalid_sim_recovery_connect(mmi_sim_enum sim);
static void srv_sim_ctrl_invalid_sim_recovery_disconnect(mmi_sim_enum sim);
static void srv_sim_ctrl_set_gsmcdma_dualsim_mode_rsp_hdlr(void *msg, S32 src_mod);
#endif /* __INVALID_SIM_RECOVERY__ */
/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_emit_event
 * DESCRIPTION
 *  Emit event according to the post parameter.
 * PARAMETERS
 *  evt     [IN] mmi_event_struct*
 *  post    [IN] Post emit. MMI_FALSE to send directly
 * RETURNS
 *  The return value of proc
 *****************************************************************************/
static mmi_ret srv_sim_ctrl_emit_event(
                    void *evt,
                    MMI_BOOL post)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = MMI_RET_OK;

    if (post)
    {
        MMI_FRM_CB_EMIT_POST_EVENT(evt);
    }
    else
    {
        ret = MMI_FRM_CB_EMIT_EVENT(evt);
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_reset_sim_data
 * DESCRIPTION
 *  Reset the data of SIM
 * PARAMETERS
 *  sim_cntx    [IN] Context of the SIM
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_reset_sim_data(srv_sim_ctrl_sim_cntx_struct *sim_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx->home_plmn_priority = SRV_SIM_CTRL_HPLMN_PRI_NONE;
    sim_cntx->home_plmn_length = 0;
    sim_cntx->is_usim = MMI_FALSE;
    sim_cntx->imsi[0] = '\0';
    sim_cntx->home_plmn[0] = '\0';
    sim_cntx->mnc_len_in_ef_ad = 0;
#ifdef __R7_EHPLMN__
    sim_cntx->ehplmn.is_valid = MMI_FALSE;
    sim_cntx->ehplmn.num = 0;
#endif
    memset(&(sim_cntx->n_remaining_attempts), 0, sizeof(sim_cntx->n_remaining_attempts));
    memset(&(sim_cntx->chv_status), 0, sizeof(sim_cntx->chv_status));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_init
 * DESCRIPTION
 *  Initialize SIM control service.
 * PARAMETERS
 *  evt     [IN] srv_bootup_early_init_evt_struct*
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_sim_ctrl_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Initialize context */
    for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
    {
        sim_cntx = &(g_srv_sim_ctrl_sim_cntx[i]);
        sim_cntx->is_initializing = MMI_TRUE;
        if (g_srv_sim_ctrl_maybe_inserted & sim)
        {
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_INITIALIZING;
        }
        else
        {
            /*
             * unavailable_cause was set to SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED,
             * we should not change it.
             */
        }
    }

    /* Set protocol event handlers */
    srv_sim_ctrl_adp_init(evt);
    srv_sim_ctrl_veri_init(evt);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_CPHS_MMI_INFO_IND, (PsIntFuncPtr)srv_sim_ctrl_cphs_mmi_info_ind_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_GET_IMSI_RSP, (PsIntFuncPtr)srv_sim_ctrl_get_imsi_rsp_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_STARTUP_INFO_IND, (PsIntFuncPtr)srv_sim_ctrl_startup_info_hdlr, MMI_TRUE);
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_SIM_STATUS_UPDATE_IND, (PsIntFuncPtr)srv_sim_ctrl_sim_status_update_ind_hdlr, MMI_TRUE);
#endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_sim_cntx
 * DESCRIPTION
 *  Get the context of the specified SIM.
 * PARAMETERS
 *  sim     [IN] Requied SIM 
 * RETURNS
 *  The context.
 *****************************************************************************/
srv_sim_ctrl_sim_cntx_struct *srv_sim_ctrl_get_sim_cntx(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (&g_srv_sim_ctrl_sim_cntx[mmi_frm_sim_to_index(sim)]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_emit_refreshed_event
 * DESCRIPTION
 *  Emit SIM refreshed event.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_emit_refreshed_event(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_refreshed_evt_struct refreshed_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_EMIT_REFRESHED_EVENT, sim);
    
    MMI_FRM_INIT_EVENT(&refreshed_evt, EVT_ID_SRV_SIM_CTRL_REFRESHED);
    refreshed_evt.sim = sim;
    MMI_FRM_CB_EMIT_POST_EVENT(&refreshed_evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_emit_change_events
 * DESCRIPTION
 *  Emit availability changed event.
 *  This function will check the change and decide whether the event can be
 *  emitted.
 * PARAMETERS
 *  sim                         [IN] From which protocol layer
 *  is_available_before         [IN]
 *  unavailable_cause_before    [IN]
 *  is_available_now            [IN]
 *  unavailable_cause           [IN]
 *  force_to_emit               [IN] Always emit events without check
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sim_ctrl_emit_change_events(
        mmi_sim_enum sim,
        srv_sim_ctrl_sim_cntx_struct *sim_cntx,
        MMI_BOOL is_available_before,
        srv_sim_ctrl_ua_cause_enum unavailable_cause_before,
        MMI_BOOL force_to_emit,
        MMI_BOOL post)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct availability_changed_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __INVALID_SIM_RECOVERY__
        if (srv_sim_ctrl_invalid_sim_recovery_get_status(sim) == MMI_TRUE &&
            sim_cntx->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED)
        {
            srv_sim_ctrl_send_verify_req(
                sim,
                SRV_SIM_CTRL_PWD_TYPE_CHV1,
                sim_cntx->chv1,
                NULL);
            return;
        }
#endif /* __INVALID_SIM_RECOVERY__ */
    
    if ((force_to_emit) ||
        (is_available_before != sim_cntx->is_available ||
         unavailable_cause_before != sim_cntx->unavailable_cause))
    {
        MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_EMIT_CHANGE_EVENTS,
            sim, force_to_emit, unavailable_cause_before, sim_cntx->unavailable_cause);
    
        /*
         * Emit availability changed event.
         * Available or unavailable event will be emitted after being aware of
         * this event.
         */
        MMI_FRM_INIT_EVENT(&availability_changed_evt, EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED);
        availability_changed_evt.sim = sim;
        availability_changed_evt.is_available_before = is_available_before;
        availability_changed_evt.unavailable_cause_before = unavailable_cause_before;
        availability_changed_evt.is_available_now = sim_cntx->is_available;
        availability_changed_evt.unavailable_cause = sim_cntx->unavailable_cause;
        srv_sim_ctrl_emit_event(&availability_changed_evt, post);

        if (sim_cntx->is_available && (force_to_emit || !is_available_before))
        {
            srv_sim_ctrl_available_evt_struct available_evt;

            /* Emit available event */
            MMI_FRM_INIT_EVENT(&available_evt, EVT_ID_SRV_SIM_CTRL_AVAILABLE);
            available_evt.sim = sim;
            available_evt.ua_cause_before = unavailable_cause_before;
            srv_sim_ctrl_emit_event(&available_evt, post);
        }

        if (!sim_cntx->is_available && (force_to_emit || is_available_before))
        {
            srv_sim_ctrl_unavailable_evt_struct unavailable_evt;

            /* Emit unavailable event */
            MMI_FRM_INIT_EVENT(&unavailable_evt, EVT_ID_SRV_SIM_CTRL_UNAVAILABLE);
            unavailable_evt.sim = sim;
            srv_sim_ctrl_emit_event(&unavailable_evt, post);
        }

        if (!srv_sim_ctrl_any_sim_is_available() &&
            (force_to_emit || is_available_before))
        {
            srv_sim_ctrl_no_sim_available_evt_struct no_sim_available_evt;

            /* Emit no_sim_available event */
            MMI_FRM_INIT_EVENT(&no_sim_available_evt, EVT_ID_SRV_SIM_CTRL_NO_SIM_AVAILABLE);
            srv_sim_ctrl_emit_event(&no_sim_available_evt, post);
        }
    }
}

void srv_sim_ctrl_set_sim_available(srv_sim_ctrl_sim_cntx_struct *sim_cntx, MMI_BOOL avai, srv_sim_ctrl_ua_cause_enum ua_cause)
{
    sim_cntx->is_available = avai;
    sim_cntx->unavailable_cause =  ua_cause;
}
/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_update_availability_by_type
 * DESCRIPTION
 *  Update SIM availability by lower-layer SIM indications.
 * PARAMETERS
 *  sim         [IN] Which SIM
 *  sim_cntx    [IN] SIM context
 *  type        [IN] Type of indication
 *  cphs_retry_count [IN] cphs_retry_count from PASSWORD_REQUIRED_IND
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_update_availability_by_type(
                mmi_sim_enum sim,
                srv_sim_ctrl_sim_cntx_struct *sim_cntx,
                U8 type,
                U8 cphs_retry_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case TYPE_NO_REQUIRED:
            sim_cntx->is_initializing = MMI_FALSE;
            srv_sim_ctrl_set_sim_available(sim_cntx, MMI_TRUE, SRV_SIM_CTRL_UA_CAUSE_NONE);
            if (sim_cntx->is_refreshing)
            {
                sim_cntx->is_refreshing = MMI_FALSE;
                srv_sim_ctrl_emit_refreshed_event(sim);
            }
            
            break;

        case TYPE_CHV1:
			srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED);
            break;

        case TYPE_UBCHV1:
			srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED);
            break;

        case TYPE_SIM_CARD_BLOCKED:
			srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED);
            break;
            
        case TYPE_NP:
        case TYPE_NSP:
        case TYPE_SP:
        case TYPE_CP:
        case TYPE_IMSI_LOCK:
        case TYPE_LINK_NS_SP:
        case TYPE_LINK_SIM_C:
            if (cphs_retry_count > 0)
            {
            	srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_PERSON_REQUIRED);
            }
            else
            {
            	srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_PERSON_BLOCKED);
            }
            break;
            
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_is_cause_of_invalid_chv_info
 * DESCRIPTION
 *  Whether the chv_info is valid by the security type
 * PARAMETERS
 *  type       [IN] smu_security_type_enum
 * RETURNS
 *  MMI_TRUE if the chv_info is valid
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_is_type_of_valid_chv_info(kal_uint16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((type != TYPE_UNSPECIFIED && type != TYPE_UNEXPECTED_ERROR)? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_emit_event_detection
 * DESCRIPTION
 *  Emit EVENT_DETECTED event.
 * PARAMETERS
 *  sim         [IN] SIM
 *  sim_cntx    [IN] Context
 *  type        [IN] Detection type
 *  post        [IN] Emit postly
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_emit_event_detection(
                mmi_sim_enum sim,
                srv_sim_ctrl_sim_cntx_struct *sim_cntx,
                srv_sim_ctrl_event_detection_enum type,
                MMI_BOOL post)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct detected_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_EVENT_DETECTED,
        sim, type, sim_cntx->change_check);
    
    MMI_FRM_INIT_EVENT(&detected_evt, EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED);
    detected_evt.sim = sim;
    detected_evt.type = type;
    detected_evt.change_check = sim_cntx->change_check;
    srv_sim_ctrl_emit_event(&detected_evt, post);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_update_change_check
 * DESCRIPTION
 *  Update change info of SIM.
 * PARAMETERS
 *  sim_cntx            [IN/OUT] SIM context
 *  sim_state_value     [IN]     smu_sim_status_enum
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_update_change_check(
                srv_sim_ctrl_sim_cntx_struct *sim_cntx,
                S32 sim_state_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_state_value)
    {
        case SMU_SIM_NOT_READY:
            sim_cntx->change_check = SRV_SIM_CTRL_CHANGE_CHECK_INVALID;
            break;

        case SMU_SIM_NO_IMSI:
            sim_cntx->change_check = SRV_SIM_CTRL_CHANGE_CHECK_UNKNOWN;
            break;

        case SMU_SIM_REPLACED:
            sim_cntx->change_check = SRV_SIM_CTRL_CHANGE_CHECK_CHANGED;
            break;
            
        case SMU_SIM_NOT_REPLACED:
            sim_cntx->change_check = SRV_SIM_CTRL_CHANGE_CHECK_THE_SAME;
            break;

        default:
            sim_cntx->change_check = SRV_SIM_CTRL_CHANGE_CHECK_INVALID;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_password_required_ind_hdlr
 * DESCRIPTION
 *  The handler of MMI_SMU_PASSWORD_REQUIRED_IND.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_smu_password_required_ind_struct*
 * RETURNS
 *  Always MMI_FALSE, means continue event routing
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_password_required_ind_hdlr(mmi_sim_enum sim, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    mmi_smu_password_required_ind_struct *pwd_req_ind;
    MMI_BOOL is_available_before;
    srv_sim_ctrl_ua_cause_enum unavailable_cause_before;
    MMI_BOOL is_initializing_before;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    pwd_req_ind = (mmi_smu_password_required_ind_struct*)msg;

    if (srv_sim_ctrl_is_type_of_valid_chv_info(pwd_req_ind->type))
    {
        srv_sim_ctrl_update_chv_info(sim, &(pwd_req_ind->chv_info));
    }

    is_available_before = sim_cntx->is_available;
    unavailable_cause_before = sim_cntx->unavailable_cause;
    is_initializing_before = sim_cntx->is_initializing;
    /*
     * If PASSWORD_REQUIRED_IND is reported not after SMU_FAIL_IND
     * this flag can force app to take it as initializing and
     * use bootup service to verify the SIM via PASSWORD_REQUIRED_INDs
     * If type == NO_REQUIRED, this flag will be reset in
     * srv_sim_ctrl_update_availability_by_type()
     */
    sim_cntx->is_initializing = MMI_TRUE;

    srv_sim_ctrl_update_availability_by_type(
        sim,
        sim_cntx,
        pwd_req_ind->type,
        pwd_req_ind->cphs_retry_count);

    if (sim_cntx->is_available)
    {
        srv_sim_ctrl_update_change_check(sim_cntx, pwd_req_ind->is_sim_change);
        
        /*
         * GET_IMSI_RSP is usually faster than CPHS_MMI_INFO_IND, we may make the
         * ready time of IMSI earlier.
         */
        srv_sim_ctrl_force_to_update_imsi(sim);
    }

    /*
     * This message may come many times during booting. To avoid emitting unnecessary
     * event frequently, we check booting state here and postpone the emitting until
     * before idle step. There will only be an event emitted before entering idle.
     */
    if (!srv_bootup_is_booting())
    {
        srv_sim_ctrl_emit_change_events(
            sim,
            sim_cntx,
            is_available_before,
            unavailable_cause_before,
            MMI_FALSE,
            MMI_TRUE);

        if (is_initializing_before && !sim_cntx->is_initializing)
        {
            /*
             * Emit after available event. Because change_check may be meaningful only 
             * if app is informed that SIM is available
             */
            srv_sim_ctrl_emit_event_detection(
                sim,
                sim_cntx,
                SRV_SIM_CTRL_EVENT_DET_REINIT_VERIFIED,
                MMI_TRUE);
                
            /*
             * SIM intializing completed. IMSI_CHANGED & HOME_PLMN_CHANGED were not
             * emitted during SIM initializing.
             */
            srv_sim_ctrl_emit_imsi_and_hplmn(sim, sim_cntx, MMI_TRUE);
        }
    }
    else
    {
        /* If during booting, the change event will be emitted until entering idle */
    }
    
    return MMI_FALSE; /* Continue event routing */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_smu_fail_ind_hdlr
 * DESCRIPTION
 *  The handler of MMI_SMU_FAIL_IND.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_smu_fail_ind_struct*
 * RETURNS
 *  Always MMI_FALSE, means continue event routing
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_smu_fail_ind_hdlr(mmi_sim_enum sim, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_smu_fail_ind_struct *fail_ind = (mmi_smu_fail_ind_struct*)msg;
	
    srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    MMI_BOOL is_available_before = sim_cntx->is_available;
    srv_sim_ctrl_ua_cause_enum unavailable_cause_before = sim_cntx->unavailable_cause;

    MMI_BOOL emit_detection_event = MMI_TRUE;
    srv_sim_ctrl_event_detection_enum detection_type = SRV_SIM_CTRL_EVENT_DET_REINIT_VERIFIED;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fail_ind->cause == SIM_REFRESH)
    {
        sim_cntx->is_refreshing = MMI_TRUE;
        /*
         * Once refreshing completed, it will be reported by
         * MMI_SMU_PASSWORD_REQUIRED_IND(NO_REQUIRED).
         */
        return MMI_FALSE;
    }

    sim_cntx->is_initializing = MMI_FALSE;
	sim_cntx->is_available = MMI_FALSE;
    sim_cntx->is_refreshing = MMI_FALSE;
    
    switch (fail_ind->cause)
    {
        case SIM_CARD_REMOVED:
        case SIM_NO_INSERTED:
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
        case SIM_PLUG_OUT:
#endif
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED;
            sim_cntx->change_check = SRV_SIM_CTRL_CHANGE_CHECK_INVALID;
            srv_sim_ctrl_reset_sim_data(sim_cntx);
            detection_type = SRV_SIM_CTRL_EVENT_DET_REMOVED;
            g_srv_sim_ctrl_maybe_inserted &= ~sim;
            break;

#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
        case SIM_PLUG_IN:
            /*
             * is_initializing will be reset to false only if received another
             * SMU_FAIL_IND or PASSWORD_REQUIRED_IND(NO_REQUIRED)
             */
            sim_cntx->is_initializing = MMI_TRUE;
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_INITIALIZING;
            sim_cntx->change_check = SRV_SIM_CTRL_CHANGE_CHECK_UNKNOWN;
            detection_type = SRV_SIM_CTRL_EVENT_DET_INSERTED;
            g_srv_sim_ctrl_maybe_inserted |= sim;
            break;

        case SIM_RECOVERY_START:
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_RECOVERY;
            srv_sim_ctrl_reset_sim_data(sim_cntx);
            detection_type = SRV_SIM_CTRL_EVENT_DET_RECOVERY_START;
            g_srv_sim_ctrl_maybe_inserted &= ~sim;
            break;

        case SIM_RECOVERY_END:
            /*
             * is_initializing will be reset to false only if received another
             * SMU_FAIL_IND or PASSWORD_REQUIRED_IND(NO_REQUIRED)
             */
            sim_cntx->is_initializing = MMI_TRUE;
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_INITIALIZING;
            detection_type = SRV_SIM_CTRL_EVENT_DET_RECOVERY_END;
            g_srv_sim_ctrl_maybe_inserted |= sim;
            break;
#endif

        #ifdef __VSIM__
        /* Virtual sim for factory test feature */
        case SIM_VSIM_ON:
            sim_cntx->is_initializing = MMI_TRUE;
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_INITIALIZING;
            sim_cntx->change_check = SRV_SIM_CTRL_CHANGE_CHECK_UNKNOWN;
            detection_type = SRV_SIM_CTRL_EVENT_DET_VSIM_ON;
            g_srv_sim_ctrl_maybe_inserted |= sim;
            break;

        case SIM_VSIM_OFF:
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED;
            sim_cntx->change_check = SRV_SIM_CTRL_CHANGE_CHECK_INVALID;
            srv_sim_ctrl_reset_sim_data(sim_cntx);
            detection_type = SRV_SIM_CTRL_EVENT_DET_VSIM_OFF;
            g_srv_sim_ctrl_maybe_inserted &= ~sim;
            break;
        #endif // __VSIM__
        case SIM_CMD_FAIL:
        case SIM_ACCESS_ERROR:
        case SIM_FATAL_ERROR:
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR;
            emit_detection_event = MMI_FALSE;
            break;

#ifdef __MMI_SIMAP_SUPPORT__
        case SIM_ACCESS_PROFILE_ON:
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE;
            detection_type = SRV_SIM_CTRL_EVENT_DET_BT_ACCESS_ON;
            break;

        case SIM_ACCESS_PROFILE_OFF:
            sim_cntx->is_initializing = MMI_TRUE;
            /* Availability will be updated when received PASSWORD_REQUIRED_IND */
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_INITIALIZING;
            /* We don't reset change check here */
            /* IMSI or Home PLMN will not refresh during BT access on */
            detection_type = SRV_SIM_CTRL_EVENT_DET_BT_ACCESS_OFF;
            break;
#endif

#ifdef __GSMCDMA_DUALSIM__
        case DUALSIM_DISCONNECTED:
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_DISCONNECTED;
            detection_type = SRV_SIM_CTRL_EVENT_DET_DISCONNECTED;
        #ifdef __INVALID_SIM_RECOVERY__
            if (sim_cntx->is_recovering_invalid_sim == MMI_TRUE)
            {
                srv_sim_ctrl_invalid_sim_recovery_connect(sim);
            }
        #endif /* __INVALID_SIM_RECOVERY__ */
            break;
            
        case DUALSIM_CONNECTED:
            sim_cntx->is_initializing = MMI_TRUE;
            /* Availability will be updated when received PASSWORD_REQUIRED_IND */
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_INITIALIZING;
            /* We don't reset change check here */
            /* IMSI or Home PLMN will not refresh during G+C disconneced */
            detection_type = SRV_SIM_CTRL_EVENT_DET_CONNECTED;
            break;
#endif /* __GSMCDMA_DUALSIM__ */

        case SIM_CHV_BLOCK:
            /* Will not be sent by L4 */

        default:
            sim_cntx->is_available = is_available_before;
            emit_detection_event = MMI_FALSE;
			
            break;
    }

    /*
     * This message may come many times during booting. To avoid emitting unnecessary
     * event frequently, we check booting state here and postpone the emitting until
     * before idle step. There will only be an event emitted before entering idle.
     */
    if (!srv_bootup_is_booting())
    {
        /* SIM hot-swap is enabled only after bootup completed*/
        /* Should be emitted before availability event, as they are low-level event */
        if (emit_detection_event)
        {
            srv_sim_ctrl_emit_event_detection(
                sim,
                sim_cntx,
                detection_type,
                MMI_TRUE);
        }
    
        srv_sim_ctrl_emit_change_events(
            sim,
            sim_cntx,
            is_available_before,
            unavailable_cause_before,
            MMI_FALSE,
            MMI_TRUE);
    }
    #ifdef __VSIM__
    else
    {
        /* If during booting, the events will be emitted before entering idle */

        /* But, for VSIM, as detection_type is not stored in SIMCtrlSrv,
           this event should be emitted immediately */
        if (emit_detection_event == MMI_TRUE &&
            (detection_type == SRV_SIM_CTRL_EVENT_DET_VSIM_ON ||
             detection_type == SRV_SIM_CTRL_EVENT_DET_VSIM_OFF))
        {
            srv_sim_ctrl_emit_event_detection(
                sim,
                sim_cntx,
                detection_type,
                MMI_TRUE);
        }
    }
    #endif // __VSIM

    return MMI_FALSE;
}


/* mmi_smu_sim_status_update_ind_struct is not available on single SIM project */
#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_sim_status_update_ind_hdlr
 * DESCRIPTION
 *  Get insertion information of SIM as earlier as possible.
 *  mmi_smu_sim_status_update_ind_struct may come before or after early-init
 *  so we should handle the racing case carefully.
 * PARAMETERS
 *  msg     [IN] mmi_smu_sim_status_update_ind_struct*
 * RETURNS
 *  MMI_FALSE to continue routing
 *****************************************************************************/
static U8 srv_sim_ctrl_sim_status_update_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_sim_status_update_ind_struct *sim_status_update_ind;
    S32 i;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_status_update_ind = (mmi_smu_sim_status_update_ind_struct*)msg;

    for (i = 0, sim = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim <<= 1)
    {
        srv_sim_ctrl_sim_cntx_struct *sim_cntx = &g_srv_sim_ctrl_sim_cntx[i];
        
        if ((sim_status_update_ind->sim_inserted_status & sim) == 0)
        {
            /* We can make sure the SIM is not inserted here */
            g_srv_sim_ctrl_maybe_inserted &= ~sim;
            sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED;
        }
    }

    return (U8)MMI_FALSE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_notify_home_plmn_updated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim         [IN] From which protocol layer
 *  sim_cntx    [IN] SIM context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_notify_home_plmn_updated(
                mmi_sim_enum sim,
                srv_sim_ctrl_sim_cntx_struct *sim_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_HPLMN_UPDATE, sim, sim_cntx->home_plmn);

    if (!srv_bootup_is_booting() && !sim_cntx->is_initializing)
    {
        srv_sim_ctrl_home_plmn_changed_evt_struct hplmn_evt;
    
        MMI_FRM_INIT_EVENT(&hplmn_evt, EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED);
        hplmn_evt.sim = sim;
        MMI_FRM_CB_EMIT_EVENT(&hplmn_evt);
    }
    else
    {
        /* Will emit before idle */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_notify_imsi_updated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim         [IN] From which protocol layer
 *  sim_cntx    [IN] SIM context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_notify_imsi_updated(
                mmi_sim_enum sim,
                srv_sim_ctrl_sim_cntx_struct *sim_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_bootup_is_booting() && !sim_cntx->is_initializing)
    {
        srv_sim_ctrl_imsi_changed_evt_struct imsi_evt;
    
        MMI_FRM_INIT_EVENT(&imsi_evt, EVT_ID_SRV_SIM_CTRL_IMSI_CHANGED);
        imsi_evt.sim = sim;
        MMI_FRM_CB_EMIT_EVENT(&imsi_evt);
    }
    else
    {
        /* Will emit before idle */
    }
}

#if defined(__ENS__) || defined(__R7_EHPLMN__)
/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_convert_plmn_bcd_to_str
 * DESCRIPTION
 *  Convert PLMN BCD data to string
 * PARAMETERS
 *  bcd     [IN] BCD data, shall be 3 bytes exactly
 *  out_str [OUT] Output string
 * RETURNS
 *  Result is valid
 *****************************************************************************/
static MMI_BOOL srv_sim_ctrl_convert_plmn_bcd_to_str(const U8 bcd[3], CHAR *out_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL is_valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*      out_str       bcd[0] bcd[1] bcd[2] */
    /* MCC(1~3)/MNC(4~6):   21     63     54   */
    
    out_str[0] = '0' + (bcd[0] & 0x0f);
    out_str[1] = '0' + ((bcd[0] >> 4) & 0x0f);
    out_str[2] = '0' + (bcd[1] & 0x0f);
    out_str[3] = '0' + (bcd[2] & 0x0f);
    out_str[4] = '0' + ((bcd[2] >> 4) & 0x0f);
    
    if ((bcd[1] & 0xf0) == 0xf0)
    {
        out_str[5] = '\0';
    }
    else
    {
        out_str[5] = '0' + ((bcd[1] >> 4) & 0x0f);
        out_str[6] = '\0';
    }

    is_valid = MMI_TRUE;
    for (i = 0; i < SRV_MAX_PLMN_LEN && out_str[i] != '\0'; i++)
    {
        if (!('0' <= out_str[i] && out_str[i] <= '9'))
        {
            is_valid = MMI_FALSE;
        }
    }

    return is_valid;
}
#endif //defined(__ENS__) || defined(__R7_EHPLMN__)

#ifdef __ENS__
/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_update_home_plmn
 * DESCRIPTION
 *  Update Home PLMN by BCD data.
 * PARAMETERS
 *  sim         [IN] Which SIM
 *  plmn_bcd    [IN] PLMN BCD data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sim_ctrl_update_home_plmn(mmi_sim_enum sim, const U8 plmn_bcd[3])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    CHAR home_plmn[SRV_MAX_PLMN_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    if (sim_cntx->home_plmn_priority <= SRV_SIM_CTRL_HPLMN_PRI_ENS &&
        srv_sim_ctrl_convert_plmn_bcd_to_str(plmn_bcd, home_plmn))
    {
        app_strlcpy(sim_cntx->home_plmn, home_plmn, sizeof(sim_cntx->home_plmn));
        sim_cntx->home_plmn_length = strlen(sim_cntx->home_plmn);
        srv_sim_ctrl_notify_home_plmn_updated(sim, sim_cntx);
    }
}
#endif /* __ENS__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_cphs_mmi_info_ind_hdlr
 * DESCRIPTION
 *  The handler of MMI_CPHS_MMI_INFO_IND.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_cphs_mmi_info_ind_struct*
 * RETURNS
 *  Always MMI_FALSE, means continue event routing
 *****************************************************************************/
static MMI_BOOL srv_sim_ctrl_cphs_mmi_info_ind_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    mmi_cphs_mmi_info_ind_struct *cphs_info_ind;
    MMI_BOOL imsi_changed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    cphs_info_ind = (mmi_cphs_mmi_info_ind_struct*)msg;
#ifdef __INVALID_SIM_RECOVERY__
    if (srv_sim_ctrl_invalid_sim_recovery_get_status(sim) == MMI_TRUE)
    {
        MMI_BOOL is_available_before = sim_cntx->is_available;
        MMI_BOOL unavailable_cause_before = sim_cntx->unavailable_cause;
        sim_cntx->is_available = MMI_TRUE;
        sim_cntx->unavailable_cause = SRV_SIM_CTRL_UA_CAUSE_NONE;

        srv_sim_ctrl_emit_change_events(
            sim,
            sim_cntx,
            is_available_before,
            unavailable_cause_before,
            MMI_FALSE,
            MMI_FALSE);
        
        sim_cntx->is_recovering_invalid_sim = MMI_FALSE;
    }
#endif /* __INVALID_SIM_RECOVERY__ */

    /* IMSI */
    imsi_changed = MMI_FALSE;
    if (strncmp(sim_cntx->imsi, (kal_char*)cphs_info_ind->imsi, SRV_MAX_IMSI_LEN) != 0)
    {
        memcpy(sim_cntx->imsi, cphs_info_ind->imsi, sizeof(sim_cntx->imsi));
        sim_cntx->imsi[SRV_MAX_IMSI_LEN] = '\0';
        imsi_changed = MMI_TRUE;
    }

    /* Home PLMN */
    //  Enhanced Network Selection for smart card based applications as well the
    // acting HPLMN feature
#ifdef __ENS__
    if (cphs_info_ind->is_valid_ef_acting_hplmn &&
        cphs_info_ind->ef_acting_hplmn[0] != 0xFF &&
        sim_cntx->home_plmn_priority <= SRV_SIM_CTRL_HPLMN_PRI_ENS)
    {
        sim_cntx->home_plmn_priority = SRV_SIM_CTRL_HPLMN_PRI_ENS;
        srv_sim_ctrl_convert_plmn_bcd_to_str(
            cphs_info_ind->ef_acting_hplmn,
            sim_cntx->home_plmn);
    }
#endif

#ifdef __R7_EHPLMN__
    // 3GPP Rel7 ehplmn feature, some eplmns can be read from sim if support.
    // currently number of eplmh is 4 saved the morden.
    /* 23.122 Equivalent home PLMN */
    sim_cntx->ehplmn.is_valid = (cphs_info_ind->is_valid_ef_ehplmn ? MMI_TRUE : MMI_FALSE);
    sim_cntx->ehplmn.num = (sim_cntx->ehplmn.is_valid ? cphs_info_ind->num_of_ehplmn : 0);
    if (sim_cntx->ehplmn.is_valid && sim_cntx->ehplmn.num > 0)
    {
        S32 i;
        S32 n_valid_plmn;

        if (sim_cntx->ehplmn.num > SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM)
        {
            sim_cntx->ehplmn.num = SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM;
        }

        n_valid_plmn = 0;
        for (i = 0; i < sim_cntx->ehplmn.num; i++)
        {
            if (srv_sim_ctrl_convert_plmn_bcd_to_str(
                    &(cphs_info_ind->ef_ehplmn[i * 3]),
                    sim_cntx->ehplmn.plmn[n_valid_plmn]))
            {
                n_valid_plmn++;
            }
        }

        if (n_valid_plmn > 0 &&
            sim_cntx->home_plmn_priority <= SRV_SIM_CTRL_HPLMN_PRI_EHPLMN)
        {
            sim_cntx->home_plmn_priority = SRV_SIM_CTRL_HPLMN_PRI_EHPLMN;
            app_strlcpy(sim_cntx->home_plmn, sim_cntx->ehplmn.plmn[0], sizeof(sim_cntx->home_plmn));
        }
    }
#endif

    /* IMSI & EF_AD */
    if (sim_cntx->home_plmn_priority <= SRV_SIM_CTRL_HPLMN_PRI_IMSI)
    {
        sim_cntx->home_plmn_priority = SRV_SIM_CTRL_HPLMN_PRI_IMSI;
        memcpy(sim_cntx->home_plmn, &(sim_cntx->imsi[1]), sizeof(sim_cntx->home_plmn));
        sim_cntx->home_plmn[SRV_MAX_PLMN_LEN] = '\0';

        /* If MNC is 3 digits, EF_AD will always be present and this value will be 3 */
        if (cphs_info_ind->digits_of_mnc == 3)
        {
            sim_cntx->home_plmn_length = 6;
            sim_cntx->home_plmn[6] = '\0';
        }
        else /* cphs_info_ind->digits_of_mnc == 0 or 2 */
        {
            /* It must be 5 digits only */
            sim_cntx->home_plmn_length = 5;
            sim_cntx->home_plmn[5] = '\0';
        }

        sim_cntx->mnc_len_in_ef_ad = cphs_info_ind->digits_of_mnc;
    }

    if (imsi_changed)
    {
        srv_sim_ctrl_notify_imsi_updated(sim, sim_cntx);
    }

    srv_sim_ctrl_notify_home_plmn_updated(sim, sim_cntx);

    return MMI_FALSE;
}


#ifdef __R7_EHPLMN__
/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_ehplmn_refresh
 * DESCRIPTION
 *  Refresh EHPLMN of the SIM. Callback from SIM refresh
 * PARAMETERS
 *  sim     [IN] Which SIM
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sim_ctrl_ehplmn_refresh(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sim_get_file_info(
        FILE_U_EHPLMN_IDX,
        NULL,
        sim,
        srv_sim_ctrl_ehplmn_file_info_rsp_hdlr,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_ehplmn_file_info_rsp_hdlr
 * DESCRIPTION
 *  Handler of the file info of EHPLMN, to read data after info got
 * PARAMETERS
 *  cb_data     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_ehplmn_file_info_rsp_hdlr(srv_sim_cb_struct* cb_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_file_info_struct *file_info;
    U16 read_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_info = (srv_sim_file_info_struct*)cb_data->data;
    
    if (cb_data->result &&
        file_info->file_size > 0)
    {
        if (file_info->file_size > SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM * 3)
        {
            read_len = SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM * 3;
        }
        else
        {
            read_len = file_info->file_size;
        }

        srv_sim_read_binary(
            FILE_U_EHPLMN_IDX,
            NULL,
            0,
            read_len,
            cb_data->sim_id,
            srv_sim_ctrl_ehplmn_read_sim_rsp_hdlr,
            NULL);
    }
    else
    {

    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_ehplmn_read_sim_rsp_hdlr
 * DESCRIPTION
 *  Handler of the data of EHPLMN, update home PLMN and emit HOME_PLMN_CHANGED
 * PARAMETERS
 *  cb_data     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_ehplmn_read_sim_rsp_hdlr(srv_sim_cb_struct* cb_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_sim_data_struct *record;
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_data->result)
    {
        sim_cntx = srv_sim_ctrl_get_sim_cntx(cb_data->sim_id);
        record = (srv_sim_data_struct*)cb_data->data;

        sim_cntx->ehplmn.num = (record->length / 3);
        if (sim_cntx->ehplmn.num > SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM)
        {
            sim_cntx->ehplmn.num = SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM;
        }
        
        for (i = 0; i < sim_cntx->ehplmn.num; i++)
        {
            srv_sim_ctrl_convert_plmn_bcd_to_str(
                &(record->data[i * 3]),
                sim_cntx->ehplmn.plmn[i]);
        }

        if (sim_cntx->home_plmn_priority <= SRV_SIM_CTRL_HPLMN_PRI_EHPLMN)
        {
            app_strlcpy(sim_cntx->home_plmn, sim_cntx->ehplmn.plmn[0], sizeof(sim_cntx->home_plmn));
            srv_sim_ctrl_notify_home_plmn_updated(cb_data->sim_id, sim_cntx);
        }
    }
}
#endif /* __R7_EHPLMN__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_imsi_rsp_hdlr
 * DESCRIPTION
 *  Handler for SMU_GET_IMSI_RSP.
 *  Update IMSI and home PLMN.
 * PARAMETERS
 *  sim     [IN] Which SIM
 *  msg     [IN] mmi_smu_get_imsi_rsp_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static MMI_BOOL srv_sim_ctrl_get_imsi_rsp_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    mmi_smu_get_imsi_rsp_struct *imsi_rsp;
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    imsi_rsp = (mmi_smu_get_imsi_rsp_struct*)msg;
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    /*
     * For SIM refresh, IMSI may already be updated by CPHS_MMI_INFO_IND,
     * check first to avoid duplicated works.
     */
    if (imsi_rsp->result &&
        imsi_rsp->imsi[0] != '\0' &&
        strncmp(sim_cntx->imsi, (kal_char*)imsi_rsp->imsi, SRV_MAX_IMSI_LEN) != 0)
    {
        /* First time got IMSI or IMSI changed */
        memcpy(sim_cntx->imsi, imsi_rsp->imsi, sizeof(sim_cntx->imsi));
        sim_cntx->imsi[SRV_MAX_IMSI_LEN] = '\0';

        srv_sim_ctrl_notify_imsi_updated(sim, sim_cntx);
        
        if (sim_cntx->home_plmn_priority <= SRV_SIM_CTRL_HPLMN_PRI_IMSI &&
            sim_cntx->home_plmn_length > 0) /* Emit only if CPHS_MMI_INFO arrived */
        {
            sim_cntx->home_plmn_priority = SRV_SIM_CTRL_HPLMN_PRI_IMSI;
            memcpy(sim_cntx->home_plmn, &(sim_cntx->imsi[1]), sizeof(sim_cntx->home_plmn));
            sim_cntx->home_plmn[sim_cntx->home_plmn_length] = '\0';
            
            srv_sim_ctrl_notify_home_plmn_updated(sim, sim_cntx);
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_startup_info_hdlr
 * DESCRIPTION
 *  Handler for SMU_STARTUP_INFO.
 *  Get USIM information.
 * PARAMETERS
 *  sim     [IN] Which SIM
 *  msg     [IN] mmi_smu_startup_info_ind_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static MMI_BOOL srv_sim_ctrl_startup_info_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    mmi_smu_startup_info_ind_struct *info = (mmi_smu_startup_info_ind_struct*)msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sim_type == KAL_TRUE  -> USIM */
    sim_cntx->is_usim = (info->sim_type ? MMI_TRUE : MMI_FALSE);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_force_to_update_imsi
 * DESCRIPTION
 *  Read IMSI from SIM to update IMSI and home PLMN.
 * PARAMETERS
 *  sim     [IN] SIM
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sim_ctrl_force_to_update_imsi(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(sim),
        MSG_ID_MMI_SMU_GET_IMSI_REQ,
        NULL,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_emit_sim_events
 * DESCRIPTION
 *  Emit SIM events before entering idle screen.
 *  During booting SIM control will not emit any availability event, but
 *  postpone until before entering idle.
 * PARAMETERS
 *  evt     [IN] srv_sim_ctrl_availability_changed_evt_struct
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_sim_ctrl_emit_sim_events(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    U32 i;
    srv_sim_ctrl_event_detection_enum detect_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SIM_CTRL_MAX_SIM_NUM; i++)
    {
        sim = mmi_frm_index_to_sim(i);
        sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

        // Emit bootup sim detection status
        detect_type = srv_sim_ctrl_is_inserted(sim) ?
                      SRV_SIM_CTRL_EVENT_DET_BOOTUP_WITH_SIM :
                      SRV_SIM_CTRL_EVENT_DET_BOOTUP_WITHOUT_SIM,
        srv_sim_ctrl_emit_event_detection(
            sim,
            sim_cntx,
            detect_type,
            MMI_TRUE);
        /*
         * Emit availability changed event because we have blocked them
         * during booting.
         */
        srv_sim_ctrl_emit_change_events(
            sim,
            sim_cntx,
            MMI_FALSE,
            SRV_SIM_CTRL_UA_CAUSE_INITIALIZING,
            MMI_TRUE,
            MMI_FALSE);

        srv_sim_ctrl_emit_imsi_and_hplmn(
            sim,
            sim_cntx,
            MMI_FALSE);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_emit_imsi_and_hplmn
 * DESCRIPTION
 *  Emit IMSI_CHANGED & HOME_PLMN_CHANGED if they are available
 * PARAMETERS
 *  sim         [IN] SIM
 *  sim_cntx    [IN] SIM context
 *  post        [IN] Postly emit
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sim_ctrl_emit_imsi_and_hplmn(
                mmi_sim_enum sim,
                srv_sim_ctrl_sim_cntx_struct *sim_cntx,
                MMI_BOOL post)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_cntx->imsi[0] != '\0')
    {
        srv_sim_ctrl_imsi_changed_evt_struct imsi_evt;
    
        MMI_FRM_INIT_EVENT(&imsi_evt, EVT_ID_SRV_SIM_CTRL_IMSI_CHANGED);
        imsi_evt.sim = sim;
        srv_sim_ctrl_emit_event(&imsi_evt, post);
    }

    if (sim_cntx->home_plmn[0] != '\0')
    {
        srv_sim_ctrl_home_plmn_changed_evt_struct hplmn_evt;
    
        MMI_FRM_INIT_EVENT(&hplmn_evt, EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED);
        hplmn_evt.sim = sim;
        srv_sim_ctrl_emit_event(&hplmn_evt, post);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_is_initializing
 * DESCRIPTION
 *  SIM is initializing. A SIM may be in initializing if during booting,
 *  or newly-inserted.
 * PARAMETERS
 *  sim     [IN] SIM
 * RETURNS
 *  MMI_TRUE if the SIM is in initializing.
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_is_initializing(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    return sim_cntx->is_initializing;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_is_available(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    return sim_cntx->is_available;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
srv_sim_ctrl_ua_cause_enum srv_sim_ctrl_get_unavailable_cause(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    return sim_cntx->unavailable_cause;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_get_imsi(mmi_sim_enum sim, CHAR *out_imsi_buffer, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    MMI_ASSERT(buffer_size > SRV_MAX_IMSI_LEN);

    if (sim_cntx->imsi[0] != '\0')
    {
        app_strlcpy(out_imsi_buffer, sim_cntx->imsi, buffer_size);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_get_home_plmn(mmi_sim_enum sim, CHAR *out_plmn_buffer, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    MMI_ASSERT(buffer_size > SRV_MAX_PLMN_LEN);

    out_plmn_buffer[0] = '\0';

    if (srv_sim_ctrl_is_available(sim))
    {
        if (sim_cntx->home_plmn[0] != '\0')
        {
            app_strlcpy(out_plmn_buffer, sim_cntx->home_plmn, buffer_size);
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
S32 srv_sim_ctrl_get_mnc_len_in_ef_ad(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    return sim_cntx->mnc_len_in_ef_ad;
}


#ifdef __R7_EHPLMN__
/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_get_eh_plmn(mmi_sim_enum sim, srv_sim_ctrl_plmn_list_struct *out_plmn_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(out_plmn_list != NULL);
    
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    if (sim_cntx->ehplmn.is_valid)
    {
        out_plmn_list->num = sim_cntx->ehplmn.num;
        for (i = 0; i < sim_cntx->ehplmn.num; i++)
        {
            out_plmn_list->plmn[i] = sim_cntx->ehplmn.plmn[i];
        }
        if (i < SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM)
        {
            out_plmn_list->plmn[i] = NULL;
        }
    }
    else
    {
        out_plmn_list->num = 0;
        out_plmn_list->plmn[0] = NULL;
    }

    return (sim_cntx->ehplmn.is_valid);
}
#endif /* __R7_EHPLMN__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_home_plmn_for_network
 * DESCRIPTION
 *  Get the home PLMN required by network application, such as roaming
 * PARAMETERS
 *  sim                 [IN]  Which SIM
 *  out_plmn_buffer     [OUT] PLMN buffer to be filled in, it shall at least
 *                            (SRV_MAX_PLMN_LEN + 1) bytes.
 *  buffer_size         [IN]  Byte size of out_plmn_buffer.
 *                            It shall >= (SRV_MAX_PLMN_LEN + 1.)
 * RETURNS
 *  MMI_TRUE if return value is valid
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_get_home_plmn_for_network(
            mmi_sim_enum sim,
            CHAR *out_plmn_buffer,
            U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    MMI_ASSERT(buffer_size > SRV_MAX_PLMN_LEN);

    out_plmn_buffer[0] = '\0';

    if (srv_sim_ctrl_is_available(sim))
    {
        if ((sim_cntx->home_plmn_priority == SRV_SIM_CTRL_HPLMN_PRI_NONE ||
             sim_cntx->home_plmn_priority == SRV_SIM_CTRL_HPLMN_PRI_IMSI ) &&
            sim_cntx->imsi[0] != '\0')
        {
            app_strlcpy(out_plmn_buffer, sim_cntx->imsi + 1, buffer_size);
            return MMI_TRUE;
        }
        else if (sim_cntx->home_plmn[0] != '\0')
        {
            app_strlcpy(out_plmn_buffer, sim_cntx->home_plmn, buffer_size);
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
srv_sim_ctrl_change_check_enum srv_sim_ctrl_get_change_check(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    return sim_cntx->change_check;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
U32 srv_sim_ctrl_get_one_available_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SIM_CTRL_MAX_SIM_NUM; i++)
    {
        if (srv_sim_ctrl_is_available(mmi_frm_index_to_sim(i)))
        {
            return (U32)mmi_frm_index_to_sim(i);
        }
    }

    return 0;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
S32 srv_sim_ctrl_get_num_of_inserted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 count;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    for (i = 0; i < SRV_SIM_CTRL_MAX_SIM_NUM; i++)
    {
        sim = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_inserted(sim))
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_is_usim(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    return sim_cntx->is_usim;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
srv_sim_ctrl_op_enum srv_sim_ctrl_get_op(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    CHAR hplmn[SRV_MAX_PLMN_LEN + 1];
    U32 plmn_num;
    srv_sim_ctrl_op_enum operator;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_sim_ctrl_get_home_plmn(sim, hplmn, SRV_MAX_PLMN_LEN + 1))
    {
        plmn_num = atoi(hplmn);
        switch (plmn_num)
        {
            case 46000:
            case 46002:
            case 46007:
            {
                operator = SRV_SIM_CTRL_OP_CMCC;
                break;
            }

            case 46001:
            case 46006:
            {
                operator = SRV_SIM_CTRL_OP_CU;
                break;
            }

            default:
                operator = SRV_SIM_CTRL_OP_UNKNOWN;
        }
    }
    else
    {
        operator = SRV_SIM_CTRL_OP_UNKNOWN;
    }

    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_GET_OP, operator);

    return operator;
}


#ifdef __INVALID_SIM_RECOVERY__
#include "mmi_msg_struct.h"
static void srv_sim_ctrl_invalid_sim_recovery_set_status(mmi_sim_enum sim, MMI_BOOL is_recovering)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx->is_recovering_invalid_sim = is_recovering;
}


MMI_BOOL srv_sim_ctrl_invalid_sim_recovery_get_status(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sim_cntx->is_recovering_invalid_sim;
}


void srv_sim_ctrl_invalid_sim_recovery_set_pin(mmi_sim_enum sim, const CHAR *pwd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(sim_cntx->chv1, pwd, SRV_SIM_CTRL_MAX_CHV_LEN);
}


staitc void srv_sim_ctrl_invalid_sim_recovery_disconnect(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_set_gsmcdma_dualsim_mode_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = OslConstructDataPtr(sizeof(mmi_sim_set_gsmcdma_dualsim_mode_req_struct));
    req->op = GSMCDMA_DUALSIM_DISCONNECT;
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(sim),
        MSG_ID_MMI_SIM_SET_GSMCDMA_DUALSIM_MODE_REQ,
        (oslParaType*)req,
        NULL);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_SIM_SET_GSMCDMA_DUALSIM_MODE_RSP,
        srv_sim_ctrl_set_gsmcdma_dualsim_mode_rsp_hdlr,
        MMI_FALSE);
}


static void srv_sim_ctrl_invalid_sim_recovery_connect(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_set_gsmcdma_dualsim_mode_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = OslConstructDataPtr(sizeof(mmi_sim_set_gsmcdma_dualsim_mode_req_struct));
    req->op = GSMCDMA_DUALSIM_CONNECT;
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(sim),
        MSG_ID_MMI_SIM_SET_GSMCDMA_DUALSIM_MODE_REQ,
        (oslParaType*)req,
        NULL);
}


void srv_sim_ctrl_invalid_sim_recovery_start(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_invalid_sim_recovery_set_status(sim, MMI_TRUE);
    srv_sim_ctrl_invalid_sim_recovery_disconnect(sim);
}


static void srv_sim_ctrl_set_gsmcdma_dualsim_mode_rsp_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_set_gsmcdma_dualsim_mode_rsp_struct *rsp =
        (mmi_sim_set_gsmcdma_dualsim_mode_rsp_struct*)msg;
    mmi_sim_enum sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result != DUALSIM_CMD_SUCCESS)
    {
        // recovery fail
        srv_sim_ctrl_invalid_sim_recovery_set_status(sim, MMI_FALSE);
        mmi_frm_clear_protocol_event_handler(
            MSG_ID_MMI_SIM_SET_GSMCDMA_DUALSIM_MODE_RSP,
            srv_sim_ctrl_set_gsmcdma_dualsim_mode_rsp_hdlr);
    }
    else if (rsp->op == GSMCDMA_DUALSIM_CONNECT)
    {
        mmi_frm_clear_protocol_event_handler(
            MSG_ID_MMI_SIM_SET_GSMCDMA_DUALSIM_MODE_RSP,
            srv_sim_ctrl_set_gsmcdma_dualsim_mode_rsp_hdlr);
    }
}

#endif /* __INVALID_SIM_RECOVERY__ */
