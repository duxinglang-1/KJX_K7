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
 *  SecSetSrvPhone.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Security setting service: phone password
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "UtilitySrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "SecSetSrvGprot.h"
#include "app_str.h"
#include "MMI_common_app_trc.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "stack_config.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#include "Unicodexdcl.h"
#include "stack_common.h"
#include "string.h"
#include "mmi_frm_utility_gprot.h"
#include "ps_public_enum.h"
#include "sim_public_enum.h"


#define SRV_SECSET_TRC_GROUP MMI_COMMON_TRC_G7_SETTING


extern kal_bool smu_query_phone_lock_enabled(void);


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    SRV_SECSET_INVALID,
    SRV_SECSET_FALSE,
    SRV_SECSET_TRUE
} srv_secset_tri_state_bool_enum;

#define SRV_SECSET_TO_TRI_STATE_BOOL(b_value) ((b_value) ? SRV_SECSET_TRUE : SRV_SECSET_FALSE)

#define SRV_SECSET_TO_MMI_BOOL(t_bool_value) ((t_bool_value) == SRV_SECSET_TRUE ? MMI_TRUE : MMI_FALSE)


typedef struct
{
    MMI_BOOL target_of_enabled;
    U16 waiting_for_l4_side;
    mmi_proc_func proc;
    void *user_data;
} srv_secset_phnlock_set_enabled_session_struct;


typedef struct
{
    mmi_proc_func proc;
    void *user_data;
} srv_secset_phnlock_verify_session_struct;


typedef struct
{
    U16 waiting_for_l4_side;
    mmi_proc_func proc;
    void *user_data;
} srv_secset_phnlock_change_session_struct;


typedef struct
{
    srv_secset_tri_state_bool_enum is_enabled;
    srv_secset_phnlock_set_enabled_session_struct *set_enabled_session;
    srv_secset_phnlock_verify_session_struct *verify_session;
    srv_secset_phnlock_change_session_struct *change_session;
} srv_secset_phnlock_cntx_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static srv_secset_phnlock_cntx_struct g_srv_secset_phnlock_cntx =
{
    SRV_SECSET_INVALID,
    NULL,
    NULL,
    NULL
};


/****************************************************************************
 * Functions
 ****************************************************************************/

static MMI_BOOL srv_secset_phnlock_smu_lock_rsp_hdlr(void *msg, module_type src_mod);
static MMI_BOOL srv_secset_phnlock_change_pwd_rsp_hdlr(void *msg, module_type src_mod);
static U8 srv_secset_phnlock_verify_pin_rsp(void *msg);


/*****************************************************************************
 * Please refer to SecSecSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_secset_phone_lock_is_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_secset_phnlock_cntx.is_enabled == SRV_SECSET_INVALID)
    {
        g_srv_secset_phnlock_cntx.is_enabled =
            SRV_SECSET_TO_TRI_STATE_BOOL(smu_query_phone_lock_enabled());

        MMI_TRACE(SRV_SECSET_TRC_GROUP, TRC_SRV_SECSET_PHNLOCK_IS_ENABLED,
            g_srv_secset_phnlock_cntx.is_enabled);
    }

    return SRV_SECSET_TO_MMI_BOOL(g_srv_secset_phnlock_cntx.is_enabled);
}


/*****************************************************************************
 * Please refer to SecSecSrvGprot.h
 *****************************************************************************/
S32 srv_secset_phone_lock_set_enabled(
    MMI_BOOL enabled,
    const WCHAR *password,
    mmi_proc_func proc,
    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_secset_phnlock_set_enabled_session_struct *session;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_secset_phnlock_cntx.set_enabled_session == NULL);
    MMI_ASSERT(proc != NULL && password != NULL);

    if (srv_secset_phone_lock_is_enabled() == enabled)
    {
        return -1; /* Invalid session ID */
    }

    MMI_TRACE(SRV_SECSET_TRC_GROUP, TRC_SRV_SECSET_PHNLOCK_SET_ENABLED, enabled, (U32)proc);

    session = (srv_secset_phnlock_set_enabled_session_struct*)
        mmi_malloc(sizeof(srv_secset_phnlock_set_enabled_session_struct));
    session->target_of_enabled = enabled;
    session->proc = proc;
    session->user_data = user_data;
    g_srv_secset_phnlock_cntx.set_enabled_session = session;

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_SMU_LOCK_RSP,
        (PsIntFuncPtr)srv_secset_phnlock_smu_lock_rsp_hdlr,
        MMI_TRUE);

    /*
     * Send request to all L4Cs
     * We should not just lock one side, because the protocol activation of each side
     * depends on the phone lock of the side. We should keep the behavior of all sides
     * are the same.
     */
    session->waiting_for_l4_side = 0;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_smu_lock_req_struct *smu_lock_req;
        mmi_sim_enum sim;

        smu_lock_req = (mmi_smu_lock_req_struct*)
            OslConstructDataPtr(sizeof(mmi_smu_lock_req_struct));
        smu_lock_req->opcode = (enabled ? ENABLE : DISABLE);
        smu_lock_req->type = TYPE_PHONELOCK;
        srv_util_convert_n_wchars_to_ascii((CHAR*)smu_lock_req->passwd, password, sizeof(smu_lock_req->passwd) - 1);

        sim = srv_sim_ctrl_get_sim_by_index(i);
        session->waiting_for_l4_side |= sim;

        mmi_frm_send_ilm(
            mmi_frm_sim_to_l4c_mod(sim),
            MSG_ID_MMI_SMU_LOCK_REQ,
            (oslParaType*)smu_lock_req,
            NULL);
    }

    return 1; /* A valid session ID */
}


/*****************************************************************************
 * FUNCTION
 *  srv_secset_phnlock_smu_lock_rsp_hdlr
 * DESCRIPTION
 *  Handle the response of setting phone lock request.
 * PARAMETERS
 *  sim     [IN]
 *  msg     [IN] mmi_smu_lock_rsp_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static MMI_BOOL srv_secset_phnlock_smu_lock_rsp_hdlr(void *msg, module_type src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_secset_phnlock_set_enabled_session_struct *session;
    mmi_smu_lock_rsp_struct *smu_lock_rsp;
    srv_secset_phone_lock_set_enabled_result_evt_struct result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim(src_mod);

    if (g_srv_secset_phnlock_cntx.set_enabled_session != NULL)
    {
        session = g_srv_secset_phnlock_cntx.set_enabled_session;
        smu_lock_rsp = (mmi_smu_lock_rsp_struct*)msg;

        session->waiting_for_l4_side &= ~sim;

        if (session->waiting_for_l4_side == 0) /* All response arrived */
        {
            g_srv_secset_phnlock_cntx.set_enabled_session = NULL;

            mmi_frm_clear_protocol_event_handler(
                MSG_ID_MMI_SMU_LOCK_RSP,
                (PsIntFuncPtr)srv_secset_phnlock_smu_lock_rsp_hdlr);

            if (smu_lock_rsp->result)
            {
                g_srv_secset_phnlock_cntx.is_enabled =
                    SRV_SECSET_TO_TRI_STATE_BOOL(session->target_of_enabled);
            }

            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_SRV_SECSET_PHONE_LOCK_SET_ENABLED_RESULT);
            result_evt.success = (smu_lock_rsp->result ? MMI_TRUE : MMI_FALSE);
            result_evt.is_enabled = srv_secset_phone_lock_is_enabled();

            MMI_TRACE(SRV_SECSET_TRC_GROUP, TRC_SRV_SECSET_PHNLOCK_SET_ENABLED_RESULT,
                (U32)session->proc, result_evt.success, result_evt.is_enabled);
            
            MMI_FRM_SEND_EVENT(&result_evt, session->proc, session->user_data);
            
            mmi_mfree(session);
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to SecSecSrvGprot.h
 *****************************************************************************/
S32 srv_secset_verify_phone_password(const WCHAR *password, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_secset_phnlock_verify_session_struct *session;
    mmi_smu_verify_pin_req_struct *verify_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_secset_phnlock_cntx.verify_session == NULL);
    MMI_ASSERT(password != NULL && proc != NULL);

    MMI_TRACE(SRV_SECSET_TRC_GROUP, TRC_SRV_SECSET_VERIFY_PHNPWD, (U32)proc);

    session = (srv_secset_phnlock_verify_session_struct*)
        mmi_malloc(sizeof(srv_secset_phnlock_verify_session_struct));
    session->proc = proc;
    session->user_data = user_data;
    g_srv_secset_phnlock_cntx.verify_session = session;

    verify_req = (mmi_smu_verify_pin_req_struct*)
            OslConstructDataPtr(sizeof(mmi_smu_verify_pin_req_struct));
    verify_req->pin_type = TYPE_PHONELOCK;
    srv_util_convert_n_wchars_to_ascii((CHAR*)verify_req->pin, password, sizeof(verify_req->pin) - 1);
    verify_req->new_pin[0] = (kal_uint8)'\0';

    /* We only need to send the verify request to one side */
    mmi_frm_send_ilm(
        MOD_L4C,
        MSG_ID_MMI_SMU_VERIFY_PIN_REQ,
        (oslParaType*)verify_req,
        NULL);
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_SMU_VERIFY_PIN_RSP,
        srv_secset_phnlock_verify_pin_rsp,
        MMI_TRUE);

    return 1; /* A valid session ID */
}


/*****************************************************************************
 * FUNCTION
 *  srv_secset_phnlock_verify_pin_rsp
 * DESCRIPTION
 *  Handle the response of verify phone password request
 * PARAMETERS
 *  msg     [IN] mmi_smu_verify_pin_rsp_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static U8 srv_secset_phnlock_verify_pin_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_secset_phnlock_verify_session_struct *session;
    mmi_smu_verify_pin_rsp_struct *verify_rsp;
    srv_secset_verify_phone_password_result_evt_struct result_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    verify_rsp = (mmi_smu_verify_pin_rsp_struct*)msg;

    if (g_srv_secset_phnlock_cntx.verify_session != NULL)
    {
        session = g_srv_secset_phnlock_cntx.verify_session;
        g_srv_secset_phnlock_cntx.verify_session = NULL;
        
        mmi_frm_clear_protocol_event_handler(
            MSG_ID_MMI_SMU_VERIFY_PIN_RSP,
            srv_secset_phnlock_verify_pin_rsp);

        MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_SRV_SECSET_VERIFY_PHONE_PASSWORD_RESULT);
        result_evt.success = (verify_rsp->result ? MMI_TRUE : MMI_FALSE);
        
        MMI_TRACE(SRV_SECSET_TRC_GROUP, TRC_SRV_SECSET_VERIFY_PHNPWD_RESULT,
            (U32)session->proc, result_evt.success);
            
        MMI_FRM_SEND_EVENT(&result_evt, session->proc, session->user_data);
        
        mmi_mfree(session);
    }

    return (U8)MMI_FALSE;
}


/*****************************************************************************
 * Please refer to SecSecSrvGprot.h
 *****************************************************************************/
S32 srv_secset_change_phone_password(
    const WCHAR *old_pwd,
    const WCHAR *new_pwd,
    mmi_proc_func proc,
    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_secset_phnlock_change_session_struct *session;
    S32 i;
    mmi_sim_enum sim;
    mmi_smu_change_password_req_struct *change_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_secset_phnlock_cntx.change_session == NULL);
    MMI_ASSERT(old_pwd != NULL && new_pwd != NULL && proc != NULL);

    MMI_TRACE(SRV_SECSET_TRC_GROUP, TRC_SRV_SECSET_CHANGE_PHNPWD, (U32)proc);

    session = (srv_secset_phnlock_change_session_struct*)
        mmi_malloc(sizeof(srv_secset_phnlock_change_session_struct));
    session->proc = proc;
    session->user_data = user_data;
    g_srv_secset_phnlock_cntx.change_session = session;

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_SMU_CHANGE_PASSWORD_RSP,
        (PsIntFuncPtr)srv_secset_phnlock_change_pwd_rsp_hdlr,
        MMI_TRUE);

    session->waiting_for_l4_side = 0;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        change_req = (mmi_smu_change_password_req_struct*)
            OslConstructDataPtr(sizeof(mmi_smu_change_password_req_struct));
        change_req->type = TYPE_PHONELOCK;
        srv_util_convert_n_wchars_to_ascii((CHAR*)change_req->old, old_pwd, sizeof(change_req->old) - 1);
        srv_util_convert_n_wchars_to_ascii((CHAR*)change_req->new1, new_pwd, sizeof(change_req->new1) - 1);
        app_strlcpy((kal_char*)change_req->new2, (kal_char*)change_req->new1, sizeof(change_req->new2));

        sim = srv_sim_ctrl_get_sim_by_index(i);
        session->waiting_for_l4_side |= sim;

        mmi_frm_send_ilm(
            mmi_frm_sim_to_l4c_mod(sim),
            MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ,
            (oslParaType*)change_req,
            NULL);
    }

    return 1; /* A valid sesion ID */
}


/*****************************************************************************
 * FUNCTION
 *  srv_secset_phnlock_change_pwd_rsp_hdlr
 * DESCRIPTION
 *  Handle the response of change phone password request
 * PARAMETERS
 *  sun     [IN]
 *  msg     [IN] srv_secset_phnlock_change_session_struct*
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static MMI_BOOL srv_secset_phnlock_change_pwd_rsp_hdlr(void *msg, module_type src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    mmi_smu_change_password_rsp_struct *change_rsp;
    srv_secset_phnlock_change_session_struct *session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim(src_mod);

    if (g_srv_secset_phnlock_cntx.change_session != NULL)
    {
        change_rsp = (mmi_smu_change_password_rsp_struct*)msg;
        session = g_srv_secset_phnlock_cntx.change_session;

        session->waiting_for_l4_side &= ~sim;

        if (session->waiting_for_l4_side == 0)
        {
            srv_secset_change_phone_password_result_evt_struct result_evt;

            g_srv_secset_phnlock_cntx.change_session = NULL;

            mmi_frm_clear_protocol_event_handler(
                MSG_ID_MMI_SMU_CHANGE_PASSWORD_RSP,
                (PsIntFuncPtr)srv_secset_phnlock_change_pwd_rsp_hdlr);

            MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_SRV_SECSET_CHANGE_PHONE_PASSWORD_RESULT);
            result_evt.success = (change_rsp->result ? MMI_TRUE : MMI_FALSE);
            
            MMI_TRACE(SRV_SECSET_TRC_GROUP, TRC_SRV_SECSET_CHANGE_PHNPWD_RESULT,
                (U32)session->proc, result_evt.success);
            
            MMI_FRM_SEND_EVENT(&result_evt, session->proc, session->user_data);

            mmi_mfree(session);
        }
    }

    return MMI_FALSE;
}

