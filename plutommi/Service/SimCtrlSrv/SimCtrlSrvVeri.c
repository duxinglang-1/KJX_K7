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
 *  SimCtrlSrvVeri.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SIM verification service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "SimCtrlSrv.h"
#include "BootupSrvGprot.h"
#include "UtilitySrvGprot.h"
#include "ps_public_enum.h"
#include "app_str.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "SimCtrlSrvGprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "ps_public_struct.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_mem_gprot.h"
#include "Unicodexdcl.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "mmi_msg_struct.h"
#include "stack_common.h"
#include "string.h"
#include "mmi_frm_utility_gprot.h"


/*****************************************************************************
 * Constant
 *****************************************************************************/

#define SRV_SIM_CTRL_MAX_PWD_LEN 16


/*****************************************************************************
 * Init
 *****************************************************************************/

static MMI_BOOL srv_sim_ctrl_verify_pin_rsp_hdlr(void *msg, S32 src_mod);
#ifdef __SRV_SIM_CTRL_SYNC__
static MMI_BOOL srv_sim_ctrl_check_pin_status_rsp_hdlr(void *msg, S32 src_mod);
#endif 
static MMI_BOOL srv_sim_ctrl_smu_lock_rsp_hdlr(void *msg, S32 src_mod);
static MMI_BOOL srv_sim_ctrl_change_password_hdlr(void *msg, S32 src_mod);
static MMI_BOOL srv_sim_ctrl_verify_pin_result_ind_hdlr(void *msg, S32 src_mod);


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_veri_init
 * DESCRIPTION
 *  SIM verification init
 * PARAMETERS
 *  evt     [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret srv_sim_ctrl_veri_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_VERIFY_PIN_RSP, (PsIntFuncPtr)srv_sim_ctrl_verify_pin_rsp_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_LOCK_RSP, (PsIntFuncPtr)srv_sim_ctrl_smu_lock_rsp_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_CHANGE_PASSWORD_RSP, (PsIntFuncPtr)srv_sim_ctrl_change_password_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_VERIFY_PIN_RESULT_IND, (PsIntFuncPtr)srv_sim_ctrl_verify_pin_result_ind_hdlr, MMI_TRUE);
	#ifdef __SRV_SIM_CTRL_SYNC__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_CHECK_PIN_STATUS_RSP, (PsIntFuncPtr)srv_sim_ctrl_check_pin_status_rsp_hdlr, MMI_TRUE);
	#endif
    return MMI_RET_OK;
}



/*****************************************************************************
 * [CHV info]
 *
 *
 *****************************************************************************/

/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
S32 srv_sim_ctrl_get_n_remaining_attempts(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum pwd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    S32 n_remaining_attempts  = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pwd_type)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
            n_remaining_attempts = sim_cntx->n_remaining_attempts.chv1;
            break;
            
        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
            n_remaining_attempts = sim_cntx->n_remaining_attempts.chv2;
            break;
            
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV1:
            n_remaining_attempts = sim_cntx->n_remaining_attempts.ubchv1;
            break;
            
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV2:
            n_remaining_attempts = sim_cntx->n_remaining_attempts.ubchv2;
            break;

        default:
            MMI_ASSERT(MMI_FALSE);
            break;
    }

    return n_remaining_attempts;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_update_chv_info
 * DESCRIPTION
 *  Update the CHV information of SIM.
 * PARAMETERS
 *  chv_info    [IN] The information from L4C
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sim_ctrl_update_chv_info(mmi_sim_enum sim, const sim_chv_info_struct *chv_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    
    sim_cntx->n_remaining_attempts.chv1 = chv_info->chv1_count;
    sim_cntx->n_remaining_attempts.chv2 = chv_info->chv2_count;
    sim_cntx->n_remaining_attempts.ubchv1 = chv_info->ubchv1_count;
    sim_cntx->n_remaining_attempts.ubchv2 = chv_info->ubchv2_count;
    sim_cntx->chv_status.chv1_enabled = ((chv_info->is_chv1_enabled != 0)? MMI_TRUE : MMI_FALSE);
    sim_cntx->chv_status.chv1_verified = ((chv_info->is_chv1_verified != 0)? MMI_TRUE : MMI_FALSE);
    sim_cntx->chv_status.chv2_enabled = ((chv_info->is_chv2_enabled != 0)? MMI_TRUE : MMI_FALSE);
    sim_cntx->chv_status.chv2_verified = ((chv_info->is_chv2_verified != 0)? MMI_TRUE : MMI_FALSE);

    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_REMAINING_ATTEMPTS,
        sim, sim_cntx->n_remaining_attempts.chv1, sim_cntx->n_remaining_attempts.chv2,
        sim_cntx->n_remaining_attempts.ubchv1, sim_cntx->n_remaining_attempts.ubchv2);

    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_CHV_INFO,
        sim_cntx->chv_status.chv1_enabled, sim_cntx->chv_status.chv1_verified,
        sim_cntx->chv_status.chv2_enabled, sim_cntx->chv_status.chv2_verified);
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_pwd_is_enabled(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum pwd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    MMI_BOOL enabled;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    enabled = MMI_FALSE;

    switch (pwd_type)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
            enabled = sim_cntx->chv_status.chv1_enabled;
            break;

        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
            enabled = sim_cntx->chv_status.chv2_enabled;
            break;

        default:
            MMI_ASSERT(MMI_FALSE);
            break;
    }

    return enabled;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_pwd_is_verified(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum pwd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    MMI_BOOL verified;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    verified = MMI_FALSE;

    switch (pwd_type)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
            verified = sim_cntx->chv_status.chv1_verified;
            break;

        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
            verified = sim_cntx->chv_status.chv2_verified;
            break;

        default:
            MMI_ASSERT(MMI_FALSE);
            break;
    }

    return verified;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_pwd_is_blocked(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum pwd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    MMI_BOOL blocked;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    blocked = MMI_FALSE;

    switch (pwd_type)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
            blocked =
                ((sim_cntx->n_remaining_attempts.chv1 == 0) ||
                (sim_cntx->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)? MMI_TRUE : MMI_FALSE);
            break;

        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
            blocked = ((sim_cntx->n_remaining_attempts.chv2 == 0)? MMI_TRUE : MMI_FALSE);
            break;

        case SRV_SIM_CTRL_PWD_TYPE_UBCHV1:
            blocked =
                ((sim_cntx->n_remaining_attempts.ubchv1 == 0) ||
                (sim_cntx->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED)? MMI_TRUE : MMI_FALSE);
            break;

        case SRV_SIM_CTRL_PWD_TYPE_UBCHV2:
            blocked = ((sim_cntx->n_remaining_attempts.ubchv2 == 0)? MMI_TRUE : MMI_FALSE);
            break;

        default:
            MMI_ASSERT(MMI_FALSE);
            break;
    }

    return blocked;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_is_in_verifying(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sim_cntx_struct *sim_cntx; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    switch (sim_cntx->unavailable_cause)
    {
        case SRV_SIM_CTRL_UA_CAUSE_INITIALIZING:
        case SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED:
        case SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED:
        case SRV_SIM_CTRL_UA_CAUSE_PERSON_REQUIRED:
            return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sim_ctrl_any_verifying_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);

        if (srv_sim_ctrl_is_in_verifying(sim))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}



/*****************************************************************************
 * [Verification]
 *
 *
 *****************************************************************************/

#define SRV_SIM_CTRL_VERIFY

/*****************************************************************************
 * Typedef
 *****************************************************************************/
 
typedef struct
{
    mmi_sim_enum sim;
    srv_sim_ctrl_pwd_type_enum pwd_type;
    mmi_proc_func result_proc;
    void *user_data;
} srv_sim_ctrl_verify_session_struct;


/*****************************************************************************
 * Global variables
 *****************************************************************************/

static srv_sim_ctrl_verify_session_struct *g_sim_ctrl_verify_session = NULL;


/*****************************************************************************
 * Functions
 *****************************************************************************/

void srv_sim_ctrl_send_verify_req(
                mmi_sim_enum sim,
                srv_sim_ctrl_pwd_type_enum pwd_type,
                const CHAR *pwd,
                const CHAR *new_pwd);


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_get_fail_cause
 * DESCRIPTION
 *  Get fail cause by MMI's operation type & L4's response.
 * PARAMETERS
 *  sim         [IN] Which SIM
 *  pwd_type    [IN] Password type of operation
 *  success     [IN] Succeed or not
 *  l4_res      [IN] Response value from L4
 * RETURNS
 *  srv_sim_ctrl_fail_cause_enum
 *****************************************************************************/
static srv_sim_ctrl_fail_cause_enum srv_sim_ctrl_get_fail_cause(
    mmi_sim_enum sim,
    srv_sim_ctrl_pwd_type_enum pwd_type,
    MMI_BOOL success,
    smu_security_type_enum l4_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_fail_cause_enum cause;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cause = SRV_SIM_CTRL_FAIL_CAUSE_NONE;
    
    switch (l4_res)
    {
        case TYPE_NO_REQUIRED:
            break;

        case TYPE_CHV1:
        case TYPE_CHV1_BLOCKED:
            if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
            {
                cause = SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD;
            }
            break;

        case TYPE_CHV2:
        case TYPE_CHV2_BLOCKED:
            if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV2)
            {
                cause = SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD;
            }
            break;
            
        case TYPE_UBCHV1:
            if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 ||
                pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
            {
                cause = SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD;
            }
            break;
            
        case TYPE_UBCHV2:
            if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV2 ||
                pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2)
            {
                cause = SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD;
            }
            break;

        case TYPE_SIM_CARD_BLOCKED:
            if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
            {
                cause = SRV_SIM_CTRL_FAIL_CAUSE_OPERATION_BLOCKED;
            }
            else if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
            {
                cause = SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD;
            }
            break;

        case TYPE_UBCHV2_BLOCKED:
            if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV2)
            {
                cause = SRV_SIM_CTRL_FAIL_CAUSE_OPERATION_BLOCKED;
            }
            else if (pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2)
            {
                cause = SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD;
            }
            break;

        case TYPE_UNSPECIFIED:
            cause = SRV_SIM_CTRL_FAIL_CAUSE_TEMP_FAIL;
            break;
            
        case TYPE_UNEXPECTED_ERROR:
            cause = SRV_SIM_CTRL_FAIL_CAUSE_SIM_ERROR;
            break;
    }

    return cause;
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
S32 srv_sim_ctrl_verify(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum pwd_type,
        const WCHAR *pwd,
        mmi_proc_func result_proc,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_verify_session_struct *session;
    CHAR pwd_in_char[SRV_SIM_CTRL_MAX_PWD_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_sim_ctrl_verify_session == NULL);
    MMI_ASSERT(result_proc != NULL && pwd != NULL);
    MMI_ASSERT(
        pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 ||
        pwd_type == SRV_SIM_CTRL_PWD_TYPE_CHV2);

    MMI_TRACE(
        SRV_SIM_CTRL_TRC_GROUP,
        TRC_SRV_SIM_CTRL_VERIFY,
        sim,
        pwd_type,
        (U32)result_proc);

    session = (srv_sim_ctrl_verify_session_struct*)
        mmi_malloc(sizeof(srv_sim_ctrl_verify_session_struct));
    g_sim_ctrl_verify_session = session;

    session->sim = sim;
    session->pwd_type = pwd_type;
    session->result_proc = result_proc;
    session->user_data = user_data;

    srv_util_convert_n_wchars_to_ascii(pwd_in_char, pwd, sizeof(pwd_in_char) - 1);

    srv_sim_ctrl_send_verify_req(sim, pwd_type, pwd_in_char, NULL);

    return 1; /* A valid session ID */
}


/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
S32 srv_sim_ctrl_verify_ubchv(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum pwd_type,
        const WCHAR *ubchv,
        const WCHAR *new_chv,
        mmi_proc_func result_proc,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_verify_session_struct *session;
    CHAR ubchv_in_char[SRV_SIM_CTRL_MAX_PWD_LEN + 1];
    CHAR new_chv_in_char[SRV_SIM_CTRL_MAX_PWD_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(g_sim_ctrl_verify_session == NULL);
    MMI_ASSERT(result_proc != NULL && ubchv != NULL && new_chv != NULL);
    MMI_ASSERT(pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1 ||
        pwd_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2);

    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_VERIFY,
        sim, pwd_type, (U32)result_proc);

    session = (srv_sim_ctrl_verify_session_struct*)
        mmi_malloc(sizeof(srv_sim_ctrl_verify_session_struct));
    g_sim_ctrl_verify_session = session;

    session->sim = sim;
    session->pwd_type = pwd_type;
    session->result_proc = result_proc;
    session->user_data = user_data;

    srv_util_convert_n_wchars_to_ascii(ubchv_in_char, ubchv, sizeof(ubchv_in_char) - 1);
    srv_util_convert_n_wchars_to_ascii(new_chv_in_char, new_chv, sizeof(new_chv_in_char) - 1);

    srv_sim_ctrl_send_verify_req(sim, pwd_type, ubchv_in_char, new_chv_in_char);

    return 1; /* A valid session ID */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_send_verify_req
 * DESCRIPTION
 *  Send VERIFY_PIN_REQ
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  pwd     [IN] Password
 *  new_pwd [IN] New password if required. If it is to verify UBCHV1, this
 *               field should be the new CHV1. If not required, this parameter
 *               can be NULL.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sim_ctrl_send_verify_req(
                mmi_sim_enum sim,
                srv_sim_ctrl_pwd_type_enum pwd_type,
                const CHAR *pwd,
                const CHAR *new_pwd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_verify_pin_req_struct *verify_pin_req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    verify_pin_req = OslConstructDataPtr(sizeof(mmi_smu_verify_pin_req_struct));

    MMI_ASSERT(pwd != NULL);
    MMI_ASSERT(!srv_bootup_is_booting()); /* Can not be used during booting */
    
    app_strlcpy((CHAR*)verify_pin_req->pin, pwd, sizeof(verify_pin_req->pin));

    if (new_pwd != NULL)
    {
        app_strlcpy((CHAR*)verify_pin_req->new_pin, new_pwd, sizeof(verify_pin_req->new_pin));
    }
    else
    {
        verify_pin_req->new_pin[0] = '\0';
    }

	/* map pwd type to pin type:
            
    SRV_SIM_CTRL_PWD_TYPE_CHV1		1	==>	TYPE_CHV1	2
    SRV_SIM_CTRL_PWD_TYPE_CHV2		2	==>	TYPE_CHV2	3
    SRV_SIM_CTRL_PWD_TYPE_UBCHV1	3	==>	TYPE_UBCHV1	4
    SRV_SIM_CTRL_PWD_TYPE_UBCHV2	4	==>	TYPE_UBCHV1	5	
	*/
	MMI_ASSERT(pwd_type < SRV_SIM_CTRL_PWD_TYPE_END_OF_ENUM);
            
    verify_pin_req->pin_type = TYPE_PHONELOCK + pwd_type;
            
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(sim),
        MSG_ID_MMI_SMU_VERIFY_PIN_REQ,
        (oslParaType*)verify_pin_req,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_verify_pin_rsp_hdlr
 * DESCRIPTION
 *  Handler of VERIFY_PIN_RSP.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_smu_verify_pin_rsp_struct
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static MMI_BOOL srv_sim_ctrl_verify_pin_rsp_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_verify_pin_rsp_struct *verify_pin_rsp = (mmi_smu_verify_pin_rsp_struct*)msg;
    mmi_sim_enum sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    
    srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    MMI_BOOL is_available_before = sim_cntx->is_available;
    srv_sim_ctrl_ua_cause_enum unavailable_cause_before = sim_cntx->unavailable_cause;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sim_ctrl_is_type_of_valid_chv_info(verify_pin_rsp->next_type))
    {
        srv_sim_ctrl_update_chv_info(sim, &verify_pin_rsp->chv_info);
    }
    
    switch (verify_pin_rsp->next_type)
    {
        case TYPE_NO_REQUIRED:
            // TODO: Not a good solution to determine CHV1 unblock. Need to ask
            // TODO: L4C to modify the response so that we can know which verifying is passed
            /*
             * We may receive TYPE_NO_REQUIRED because of verifying phone lock,
             * but CHV1 is still blocked.
             */
            if ((sim_cntx->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED ||
                 sim_cntx->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED) &&
                srv_sim_ctrl_get_n_remaining_attempts(sim, SRV_SIM_CTRL_PWD_TYPE_CHV1) > 0)
            {
                /* CHV1 unblocked by UBCHV1 */
                srv_sim_ctrl_set_sim_available(sim_cntx, MMI_TRUE, SRV_SIM_CTRL_UA_CAUSE_NONE);
            }
            break;

        case TYPE_UBCHV1:
            if (srv_sim_ctrl_get_n_remaining_attempts(sim, SRV_SIM_CTRL_PWD_TYPE_CHV1) == 0)
            {
            	srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED);
            }
            break;
        
        case TYPE_CHV1_BLOCKED:
			srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED);
            break;

        case TYPE_SIM_CARD_BLOCKED:
			srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED);
            break;

        default:
            /* Ignore */
            break;
    }


    /* Check callback */
    if (g_sim_ctrl_verify_session != NULL &&
        g_sim_ctrl_verify_session->sim == sim)
    {
        srv_sim_ctrl_verify_session_struct *session;
        srv_sim_ctrl_verify_result_evt_struct result_evt;

        session = g_sim_ctrl_verify_session;
        g_sim_ctrl_verify_session = NULL;

        MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_SRV_SIM_CTRL_VERIFY_RESULT);
        result_evt.sim = session->sim;
        result_evt.type = session->pwd_type;
        result_evt.success = ((verify_pin_rsp->result != 0)? MMI_TRUE : MMI_FALSE);
        result_evt.fail_cause = srv_sim_ctrl_get_fail_cause(
                                    sim,
                                    result_evt.type,
                                    result_evt.success,
                                    (smu_security_type_enum)verify_pin_rsp->next_type);
        result_evt.n_remaining_attempts = srv_sim_ctrl_get_n_remaining_attempts(sim, session->pwd_type);

        MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_VERIFY_RESULT,
            sim, (U32)session->result_proc, result_evt.type, result_evt.success);
        
        MMI_FRM_SEND_EVENT(&result_evt, session->result_proc, session->user_data);
        
        mmi_mfree(session);
    }
    else
    {
        /* Ignore, it may be requested by other application */
    }

    /* Emit change events */
    srv_sim_ctrl_emit_change_events(
        sim,
        sim_cntx,
        is_available_before,
        unavailable_cause_before,
        MMI_FALSE,
        MMI_FALSE);
        

    return MMI_FALSE;
}


/*****************************************************************************
 * [Synchronization Functions]
 *
 *
 *****************************************************************************/

#ifdef __SRV_SIM_CTRL_SYNC__
#define SRV_SIM_CTRL_SYNC
/*****************************************************************************
 * Context
 *****************************************************************************/

typedef struct srv_sim_ctrl_sync_session_struct_s
{
    S32 id;
    mmi_sim_enum sim;
    mmi_proc_func completed_proc;
    void *user_data;
    struct srv_sim_ctrl_sync_session_struct_s *next;
} srv_sim_ctrl_sync_session_struct;


typedef struct
{
    S32 next_session_id;
    srv_sim_ctrl_sync_session_struct *session[SRV_SIM_CTRL_MAX_SIM_NUM];
} srv_sim_ctrl_sync_cntx_struct;


static srv_sim_ctrl_sync_cntx_struct g_srv_sim_ctrl_sync_cntx =
{
    0,
    NULL
};


/*****************************************************************************
 * Functions
 *****************************************************************************/

/*****************************************************************************
 * Please refer to SimCtrlSrvGprot.h
 *****************************************************************************/
S32 srv_sim_ctrl_sync(mmi_sim_enum sim, mmi_proc_func completed_proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_sync_session_struct *new_session;
    srv_sim_ctrl_sync_session_struct *tail_session;
    S32 sim_index;
    MMI_BOOL send_request;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mmi_frm_sim_to_index(sim);

    /* Send new request if no request for the same SIM in queue */
    send_request = (g_srv_sim_ctrl_sync_cntx.session[sim_index] == NULL);
    
    new_session = (srv_sim_ctrl_sync_session_struct*)mmi_malloc(
                sizeof(srv_sim_ctrl_sync_session_struct));
    new_session->id = g_srv_sim_ctrl_sync_cntx.next_session_id;
    new_session->sim = sim;
    new_session->completed_proc = completed_proc;
    new_session->user_data = user_data;
    new_session->next = NULL;

    g_srv_sim_ctrl_sync_cntx.next_session_id++;
    if (g_srv_sim_ctrl_sync_cntx.next_session_id > 0xffffff0)
    {
        g_srv_sim_ctrl_sync_cntx.next_session_id = 0;
    }

    /* Find the last session */
    tail_session = g_srv_sim_ctrl_sync_cntx.session[sim_index];
    while (tail_session != NULL && tail_session->next != NULL)
    {
        tail_session = tail_session->next;
    }

    /*
     * Append new session to the tail, so that the callbacks can be called
     * in the order of request.
     */
    if (tail_session == NULL)
    {
        g_srv_sim_ctrl_sync_cntx.session[sim_index] = new_session;
    }
    else
    {
        tail_session->next = new_session;
    }

    if (send_request)
    {
        mmi_frm_send_ilm(
            mmi_frm_sim_to_l4c_mod(sim),
            MSG_ID_MMI_SMU_CHECK_PIN_STATUS_REQ,
            NULL,
            NULL);
    }

    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_SYNC,
        sim, (U32)completed_proc, new_session->id, send_request);
    
    /* The response will be dispatched to srv_sim_ctrl_check_pin_status_rsp_hdlr() */

    return (new_session->id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_check_pin_status_rsp_hdlr
 * DESCRIPTION
 *  Handler of CHECK_PIN_STATUS_RSP
 *  Update CHV status and callback for srv_sim_ctrl_sync
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_smu_check_pin_status_rsp_struct
 * RETURNS
 *  MMI_FALSE; continue message routing
 *****************************************************************************/
static MMI_BOOL srv_sim_ctrl_check_pin_status_rsp_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_sim_ctrl_sync_session_struct *session;
    S32 sim_index;
    srv_sim_ctrl_sync_completed_evt_struct completed_evt;
    mmi_smu_check_pin_status_rsp_struct *status_rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    status_rsp = (mmi_smu_check_pin_status_rsp_struct*)msg;
    sim_index = mmi_frm_sim_to_index(sim);

    srv_sim_ctrl_update_chv_info(sim, &(status_rsp->chv_info));

    if (g_srv_sim_ctrl_sync_cntx.session[sim_index] != NULL)
    {
        MMI_FRM_INIT_EVENT(&completed_evt, EVT_ID_SRV_SIM_CTRL_SYNC_COMPLETED);
        completed_evt.sim = sim;
    
        for (session = g_srv_sim_ctrl_sync_cntx.session[sim_index];
             session != NULL;
             session = session->next)
        {
            MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_SYNC_CALLBACK,
                 sim, session->id, (U32)session->completed_proc);
        
            if (session->completed_proc != NULL)
            {
                completed_evt.session_id = session->id;
                MMI_FRM_SEND_EVENT(&completed_evt, session->completed_proc, session->user_data);
            }
        
            mmi_mfree(session);
        }

        g_srv_sim_ctrl_sync_cntx.session[sim_index] = NULL;
    }

    return MMI_FALSE;
}
#endif



/*****************************************************************************
 * [Set CHV enabled]
 *
 *
 *****************************************************************************/

#define SRV_SIM_CTRL_SET_ENABLED


typedef struct
{
    mmi_sim_enum sim;
    srv_sim_ctrl_pwd_type_enum type;
    mmi_proc_func proc;
    void *user_data;
} srv_sim_ctrl_set_enabled_session_struct;


srv_sim_ctrl_set_enabled_session_struct *g_srv_sim_ctrl_set_enabled_session = NULL;


/*****************************************************************************
 * Functions
 *****************************************************************************/

/*****************************************************************************
 * Please refer to SrvSimCtrlGprot.h
 *****************************************************************************/
S32 srv_sim_ctrl_set_enabled(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum type,
        const WCHAR *password,
        MMI_BOOL enabled,
        mmi_proc_func proc,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_set_enabled_session_struct *session;
    mmi_smu_lock_req_struct *smu_lock_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_sim_ctrl_set_enabled_session == NULL);
    MMI_ASSERT(type == SRV_SIM_CTRL_PWD_TYPE_CHV1 || type == SRV_SIM_CTRL_PWD_TYPE_CHV2);
    MMI_ASSERT(proc != NULL);

    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_SET_ENABLED,
        sim, type, enabled, (U32)proc);

    if (srv_sim_ctrl_pwd_is_enabled(sim, type) == enabled)
    {
        return -1; /* Invalid session */
    }

    session = (srv_sim_ctrl_set_enabled_session_struct*)
        mmi_malloc(sizeof(srv_sim_ctrl_set_enabled_session_struct));
    session->sim = sim;
    session->type = type;
    session->proc = proc;
    session->user_data = user_data;
    g_srv_sim_ctrl_set_enabled_session = session;

    /* Send request to L4C */
    smu_lock_req = (mmi_smu_lock_req_struct*)
        OslConstructDataPtr(sizeof(mmi_smu_lock_req_struct));
    smu_lock_req->opcode = (enabled ? ENABLE : DISABLE);
    smu_lock_req->type =
        (type == SRV_SIM_CTRL_PWD_TYPE_CHV1 ? TYPE_CHV1 : TYPE_CHV2);
    srv_util_convert_n_wchars_to_ascii((CHAR*)smu_lock_req->passwd, password, sizeof(smu_lock_req->passwd) - 1);

#ifdef __INVALID_SIM_RECOVERY__
    if (type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
    {
        srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
        memcpy(sim_cntx->temp_chv1, smu_lock_req->passwd, SRV_SIM_CTRL_MAX_CHV_LEN);
    }
#endif /* __INVALID_SIM_RECOVERY__ */

    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(sim),
        MSG_ID_MMI_SMU_LOCK_REQ,
        (oslParaType*)smu_lock_req,
        NULL);

    return 1; /* A valid session ID */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_smu_lock_rsp_hdlr
 * DESCRIPTION
 *  Response handler of SMU_LOCK_RSP.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_smu_lock_rsp_struct*
 * RETURNS
 *  Always MMI_FALSE, means continue event routing
 *****************************************************************************/
static MMI_BOOL srv_sim_ctrl_smu_lock_rsp_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    mmi_smu_lock_rsp_struct *smu_lock_rsp;
    MMI_BOOL is_available_before;
    srv_sim_ctrl_ua_cause_enum unavailable_cause_before;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    smu_lock_rsp = (mmi_smu_lock_rsp_struct*)msg;

    is_available_before = sim_cntx->is_available;
    unavailable_cause_before = sim_cntx->unavailable_cause;

    if (srv_sim_ctrl_is_type_of_valid_chv_info(smu_lock_rsp->cause))
    {
        srv_sim_ctrl_update_chv_info(sim, &(smu_lock_rsp->chv_info));
    }

    if (!smu_lock_rsp->result) /* Failed to verify */
    {
        switch (smu_lock_rsp->cause)
        {
            case TYPE_UBCHV1:
            case TYPE_CHV1_BLOCKED:
				srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED);
                break;

            case TYPE_SIM_CARD_BLOCKED:
				srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED);
                break;
                
            default:
                /* Ignore */
                break;
        }
    }
#ifdef __INVALID_SIM_RECOVERY__
    else if (smu_lock_rsp->cause == TYPE_NO_REQUIRED)
    {
        srv_sim_ctrl_invalid_sim_recovery_set_pin(sim, sim_cntx->temp_chv1);
    }
#endif /* __INVALID_SIM_RECOVERY__ */


    /* Callback for setting result */
    if (g_srv_sim_ctrl_set_enabled_session != NULL &&
        g_srv_sim_ctrl_set_enabled_session->sim == sim)
    {
        srv_sim_ctrl_set_enabled_session_struct *session;
        srv_sim_ctrl_set_enabled_result_evt_struct result_evt;

        session = g_srv_sim_ctrl_set_enabled_session;
        g_srv_sim_ctrl_set_enabled_session = NULL;
        
        MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_SRV_SIM_CTRL_SET_ENABLED_RESULT);
        result_evt.sim = sim;
        result_evt.type = session->type;
        result_evt.success = (smu_lock_rsp->result != 0) ? MMI_TRUE : MMI_FALSE;
        result_evt.fail_cause = srv_sim_ctrl_get_fail_cause(
                                    sim,
                                    result_evt.type,
                                    result_evt.success,
                                    (smu_security_type_enum)smu_lock_rsp->cause);
        if (session->type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
        {
            result_evt.is_enabled = sim_cntx->chv_status.chv1_enabled;
        }
        else
        {
            result_evt.is_enabled = sim_cntx->chv_status.chv2_enabled;
        }
        
        MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_SET_ENABLED_RESULT,
            sim, (U32)session->proc, result_evt.type, result_evt.success, result_evt.fail_cause);
        
        MMI_FRM_SEND_EVENT(&result_evt, session->proc, session->user_data);

        mmi_mfree(session);
    }

    srv_sim_ctrl_emit_change_events(
        sim,
        sim_cntx,
        is_available_before,
        unavailable_cause_before,
        MMI_FALSE,
        MMI_FALSE);

    return MMI_FALSE;
}



/*****************************************************************************
 * [Change password]
 *
 *
 *****************************************************************************/

#define SRV_SIM_CTRL_CHANGE_PASSWORD


/*****************************************************************************
 * Context
 *****************************************************************************/

typedef struct
{
    mmi_sim_enum sim;
    srv_sim_ctrl_pwd_type_enum type;
    mmi_proc_func proc;
    void *user_data;
} srv_sim_ctrl_chpwd_session_struct;


static srv_sim_ctrl_chpwd_session_struct *g_srv_sim_ctrl_chpwd_session = NULL;


/*****************************************************************************
 * Please refer to SrvSimCtrlGprot.h
 *****************************************************************************/
S32 srv_sim_ctrl_change_password(
        mmi_sim_enum sim,
        srv_sim_ctrl_pwd_type_enum type,
        const WCHAR *old_pwd,
        const WCHAR *new_pwd,
        mmi_proc_func proc,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_chpwd_session_struct *session;
    mmi_smu_change_password_req_struct *change_req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_sim_ctrl_chpwd_session == NULL);
    MMI_ASSERT(type == SRV_SIM_CTRL_PWD_TYPE_CHV1 || type == SRV_SIM_CTRL_PWD_TYPE_CHV2);
    MMI_ASSERT(proc != NULL);

    session = (srv_sim_ctrl_chpwd_session_struct*)mmi_malloc(sizeof(srv_sim_ctrl_chpwd_session_struct));
    session->sim = sim;
    session->type = type;
    session->proc = proc;
    session->user_data = user_data;
    g_srv_sim_ctrl_chpwd_session = session;

    MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_CHANGE_PASSWORD, sim, type, (U32)proc);

    /* Send request to L4C */
    change_req = (mmi_smu_change_password_req_struct*)
        OslConstructDataPtr(sizeof(mmi_smu_change_password_req_struct));
    change_req->type = (type == SRV_SIM_CTRL_PWD_TYPE_CHV1 ? TYPE_CHV1 : TYPE_CHV2);
    srv_util_convert_n_wchars_to_ascii((CHAR*)change_req->old, old_pwd, sizeof(change_req->old) - 1);
    srv_util_convert_n_wchars_to_ascii((CHAR*)change_req->new1, new_pwd, sizeof(change_req->new1) - 1);
    app_strlcpy((kal_char*)change_req->new2, (kal_char*)change_req->new1, sizeof(change_req->new2));

#ifdef __INVALID_SIM_RECOVERY__
    if (type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
    {
        srv_sim_ctrl_sim_cntx_struct *sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
        memcpy(sim_cntx->temp_chv1, change_req->new1, SRV_SIM_CTRL_MAX_CHV_LEN);
    }
#endif /* __INVALID_SIM_RECOVERY__ */

    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(sim),
        MSG_ID_MMI_SMU_CHANGE_PASSWORD_REQ,
        (oslParaType*)change_req,
        NULL);

    return 1; /* A valid session ID */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_change_password_hdlr
 * DESCRIPTION
 *  Eavesdrop SMU_CHANGE_PASSWORD_RSPs to update SIM status.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_smu_change_password_rsp_struct*
 * RETURNS
 *  Always MMI_FALSE, means continue event routing
 *****************************************************************************/
static MMI_BOOL srv_sim_ctrl_change_password_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    mmi_smu_change_password_rsp_struct *change_pwd_rsp;
    MMI_BOOL is_available_before;
    srv_sim_ctrl_ua_cause_enum unavailable_cause_before;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);
    change_pwd_rsp = (mmi_smu_change_password_rsp_struct*)msg;

    is_available_before = sim_cntx->is_available;
    unavailable_cause_before = sim_cntx->unavailable_cause;

    if (srv_sim_ctrl_is_type_of_valid_chv_info(change_pwd_rsp->cause))
    {
        srv_sim_ctrl_update_chv_info(sim, &(change_pwd_rsp->chv_info));
    }

    if (!change_pwd_rsp->result)
    {
        switch (change_pwd_rsp->cause)
        {
            case TYPE_UBCHV1:
            case TYPE_CHV1_BLOCKED:
				srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED);
                break;
                
            case TYPE_SIM_CARD_BLOCKED:
				srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED);
                break;
                
            default:
                /* Ignore */
                break;
        }
    }
#ifdef __INVALID_SIM_RECOVERY__
    else if (change_pwd_rsp->cause == TYPE_NO_REQUIRED)
    {
        srv_sim_ctrl_invalid_sim_recovery_set_pin(sim, sim_cntx->temp_chv1);
    }
#endif /* __INVALID_SIM_RECOVERY__ */

    if (g_srv_sim_ctrl_chpwd_session != NULL &&
        g_srv_sim_ctrl_chpwd_session->sim == sim)
    {
        srv_sim_ctrl_change_password_result_evt_struct result_evt;
        srv_sim_ctrl_chpwd_session_struct *session;

        session = g_srv_sim_ctrl_chpwd_session;
        g_srv_sim_ctrl_chpwd_session = NULL;
        
        MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_SRV_SIM_CTRL_CHANGE_PASSWORD_RESULT);
        result_evt.sim = sim;
        result_evt.type = session->type;
        result_evt.success = (change_pwd_rsp->result != 0) ? MMI_TRUE : MMI_FALSE;
        result_evt.fail_cause = srv_sim_ctrl_get_fail_cause(
                                    sim,
                                    result_evt.type,
                                    result_evt.success,
                                    (smu_security_type_enum)change_pwd_rsp->cause);
                                    
        MMI_TRACE(SRV_SIM_CTRL_TRC_GROUP, TRC_SRV_SIM_CTRL_CHANGE_PASSWORD_RESULT,
            sim, (U32)session->proc, result_evt.type, result_evt.success, result_evt.fail_cause);
        
        MMI_FRM_SEND_EVENT(&result_evt, session->proc, session->user_data);

        mmi_mfree(session);
    }

    srv_sim_ctrl_emit_change_events(
        sim,
        sim_cntx,
        is_available_before,
        unavailable_cause_before,
        MMI_FALSE,
        MMI_FALSE);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sim_ctrl_verify_pin_result_ind_hdlr
 * DESCRIPTION
 *  Eavesdrop SMU_VERIFY_PIN_RESULT_INDs to update SIM status.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_smu_verify_pin_result_ind_struct*
 * RETURNS
 *  Always MMI_FALSE, means continue event routing
 *****************************************************************************/
static MMI_BOOL srv_sim_ctrl_verify_pin_result_ind_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    mmi_smu_verify_pin_result_ind_struct *result_ind;
    srv_sim_ctrl_sim_cntx_struct *sim_cntx;
    MMI_BOOL is_available_before;
    srv_sim_ctrl_ua_cause_enum unavailable_cause_before;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    result_ind = (mmi_smu_verify_pin_result_ind_struct*)msg;
    sim_cntx = srv_sim_ctrl_get_sim_cntx(sim);

    if (srv_sim_ctrl_is_type_of_valid_chv_info(result_ind->next_type))
    {
        srv_sim_ctrl_update_chv_info(sim, &(result_ind->chv_info));
    }

    is_available_before = sim_cntx->is_available;
    unavailable_cause_before = sim_cntx->unavailable_cause;

    switch (result_ind->next_type)
    {
        case TYPE_NO_REQUIRED:
            if (sim_cntx->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED ||		 /* CHV1 verified */
                (sim_cntx->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED &&		/* CHV1 unblocked by UBCHV1 */
                srv_sim_ctrl_get_n_remaining_attempts(sim, SRV_SIM_CTRL_PWD_TYPE_CHV1) > 0)
               )
            {
				srv_sim_ctrl_set_sim_available(sim_cntx, MMI_TRUE, SRV_SIM_CTRL_UA_CAUSE_NONE);
            }
            break;
            
#ifdef __GSMCDMA_DUALSIM__
        case TYPE_CHV1:
			srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED);
            break;
#endif /* __GSMCDMA_DUALSIM__ */
            
        case TYPE_UBCHV1:
			srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED);
            break;

        case TYPE_SIM_CARD_BLOCKED:
			srv_sim_ctrl_set_sim_available(sim_cntx, MMI_FALSE, SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED);
            break;
            
        default:
            break;
    }

    if (!srv_bootup_is_booting())
    {
        srv_sim_ctrl_emit_change_events(
            sim,
            sim_cntx,
            is_available_before,
            unavailable_cause_before,
            MMI_FALSE,
            MMI_FALSE);
    }
    else
    {
        /* If during booting, the change event will be emitted until entering idle */
    }

    return MMI_FALSE;
}

