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
 *  BootupSrvSecurity.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Security part of bootup service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "BootupSrv.h"
#include "UtilitySrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_msg_struct.h"
#include "smu_common_enums.h" /* enums of password_required_ind */
#include "sim_common_enums.h" /* enums of smu_fail_ind */
#include "app_str.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "BootupSrvGprot.h"
#include "custom_nvram_sec.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "BootupSrvIprot.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "Unicodexdcl.h"
#include "mmi_frm_utility_gprot.h"
#include "ps_public_enum.h"


#define SRV_BOOTUP_MAX_PWD_LEN 16


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    struct
    {
        srv_bootup_sim_bit_set sim_set; /* Which L4C requires the phone lock */
        MMI_BOOL is_required;
        CHAR password[SRV_BOOTUP_MAX_PWD_LEN + 1];
        S8 n_auto_trials;
    } phone_lock;
    
    struct {
        mmi_sim_enum sim;
        srv_bootup_verification_type_enum type;
        srv_bootup_verify_result_callback result_callback;
        void *user_data;
    } session;
} srv_bootup_security_cntx_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static srv_bootup_security_cntx_struct g_srv_bootup_security_cntx;


/****************************************************************************
 * Local functions
 ****************************************************************************/

static void srv_bootup_sec_send_verify_req(
                mmi_sim_enum sim,
                const CHAR *pwd,
                const CHAR *new_pwd);

#ifdef __SIM_ME_LOCK__
static void srv_bootup_sec_pwd_req_ind_handle_person(
                mmi_sim_enum sim,
                srv_bootup_sim_cntx_struct *sim_cntx,
                const mmi_smu_password_required_ind_struct *pwd_req_ind);
#endif

static void srv_bootup_sec_notify_sim_status(mmi_sim_enum sim, MMI_BOOL fatal_error);

static void srv_bootup_try_to_verify_remaining_phone_locks(
                srv_bootup_security_cntx_struct *cntx,
                const CHAR *password);

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_sec_init_for_protocol
 * DESCRIPTION
 *  Initialize security submodule to wait for protocol events.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bootup_sec_init_for_protocol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_security_cntx_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_srv_bootup_security_cntx);

    cntx->phone_lock.n_auto_trials = 0;
    cntx->phone_lock.sim_set = 0;
    cntx->phone_lock.is_required = MMI_FALSE;
    cntx->phone_lock.password[0] = '\0';
    cntx->session.result_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_sec_notify_verify_result
 * DESCRIPTION
 *  Callback client to notify the result of verification.
 *  This function checks previous verification succeeded or not. And callback
 *  if there is client waiting for the result.
 * PARAMETERS
 *  sim                 [IN] From which protocol layer
 *  new_required_type   [IN] New verification type required by protocol.
 *  n_remaining_attempts [IN] Number of remaining attempts reported by protocol
 *  sim_fatal_error     [IN] There is an non-recoverable error on SIM
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_sec_notify_verify_result(
                mmi_sim_enum sim,
                srv_bootup_verification_type_enum new_required_type,
                S32 n_remaining_attempts,
                MMI_BOOL sim_fatal_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_security_cntx_struct *cntx;
    srv_bootup_verify_result_struct result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = &(g_srv_bootup_security_cntx);

    if (cntx->session.result_callback == NULL)
    {
        return;
    }

    if (cntx->session.sim != sim)
    {
        /* Not meaningful to previous verifying */
        return;
    }
    
    result.sim = sim;
    result.type = cntx->session.type;
    result.success = MMI_FALSE;
    result.fatal_error = sim_fatal_error;
    result.n_remaining_attempts = n_remaining_attempts;

    /*
     * We still run following check even if no callback is required.
     * As the previous code can also motify other fields by the result.
     * The influence on performance is not important and ignorable.
     */
    switch (cntx->session.type)
    {
        case SRV_BOOTUP_VERI_PHONE_LOCK:
            /*
             * L4C owner:
             * SMU_FAIL_IND or SMU_PASSWORD_REQUIRED_IND(Non-phone lock)
             * will be sent only if phone lock is unlocked.
             * So if we received SMU_FAIL_IND it also implies phone
             * lock has been verified successfully
             */
        
            if (new_required_type == SRV_BOOTUP_VERI_PHONE_LOCK)
            {
                result.success = MMI_FALSE;
                
                /*
                 * Phone password verification failed. If it is our auto-trial
                 * for user's previous input, set this flag to MMI_TRUE to
                 * avoid future trial that may cause an infinite loop.
                 */
                cntx->phone_lock.is_required = MMI_TRUE;
            }
            else
            {
                result.success = MMI_TRUE;
                result.n_remaining_attempts = SRV_BOOTUP_ATTEMPT_INFINITE_NUMBER;
                result.fatal_error = MMI_FALSE;

                /*
                 * Phone lock may be also required by other layer.
                 * We remember the phone password to avoid require user again,
                 * and do auto-trial in the future.
                 * Assume our phone only has one phone password.
                 */
                cntx->phone_lock.is_required = MMI_FALSE;

                if (cntx->phone_lock.sim_set != 0)
                {
                    /*
                     * Try to verify remaining phone locks. cntx->session.sim
                     * will be modified as the L4C in verifying.
                     */
                    srv_bootup_try_to_verify_remaining_phone_locks(
                        cntx,
                        cntx->phone_lock.password);

                    /*
                     * We will callback only until all phone locks are
                     * verified.
                     */
                    return;
                }
            }
            break;

        case SRV_BOOTUP_VERI_CHV1:
            if (new_required_type == SRV_BOOTUP_VERI_CHV1)
            {
                result.success = MMI_FALSE;
            }
            else if (new_required_type == SRV_BOOTUP_VERI_UBCHV1)
            {
                result.success = MMI_FALSE;
                result.n_remaining_attempts = 0;
            }
            else
            {
                result.success = MMI_TRUE;
                result.n_remaining_attempts = 3;
            }
            break;

        case SRV_BOOTUP_VERI_UBCHV1:
            if (new_required_type == SRV_BOOTUP_VERI_UBCHV1)
            {
                result.success = MMI_FALSE;
            }
            else if (sim_fatal_error)
            {
                result.success = MMI_FALSE;
                result.n_remaining_attempts = 0;
            }
            else
            {
                result.success = MMI_TRUE;
                result.n_remaining_attempts = 10;
            }
            break;

#ifdef __SIM_ME_LOCK__
        case SRV_BOOTUP_VERI_NP:
        case SRV_BOOTUP_VERI_NSP:
        case SRV_BOOTUP_VERI_SP:
        case SRV_BOOTUP_VERI_CP:
        case SRV_BOOTUP_VERI_SIMP:
        case SRV_BOOTUP_VERI_NSSP:
        case SRV_BOOTUP_VERI_SIMCP:
        default:
            if (new_required_type == result.type)
            {
                result.success = MMI_FALSE;
            }
            else if (sim_fatal_error)
            {
                result.success = MMI_FALSE;
                result.n_remaining_attempts = 0;
            }
            else
            {
                result.success = MMI_TRUE;
                result.n_remaining_attempts = SRV_BOOTUP_MAX_PERSONALIZATION_TRIAL_NUM;
            }
            break;
#endif /* __SIM_ME_LOCK__ */
    }

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_NOTIFY_VERIFY_RESULT,
        result.sim, result.type, result.success, result.fatal_error, result.n_remaining_attempts);

    if (cntx->session.result_callback != NULL)
    {
        cntx->session.result_callback(cntx->session.user_data, &result);
        cntx->session.result_callback = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_sec_password_required_ind_hdlr
 * DESCRIPTION
 *  Listens to SMU_PASSWORD_REQUIRED_IND from L4C.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_smu_password_required_ind_struct*
 * RETURNS
 *  MMI_FALSE; means continue routing the message
 *****************************************************************************/
MMI_BOOL srv_bootup_sec_password_required_ind_hdlr(mmi_sim_enum sim, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_cntx_struct *sim_cntx;
    mmi_smu_password_required_ind_struct *pwd_req_ind;
    srv_bootup_security_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_bootup_get_sim_cntx(sim);
    cntx = &(g_srv_bootup_security_cntx);
    
    MMI_ASSERT(msg != NULL);
    pwd_req_ind = (mmi_smu_password_required_ind_struct*)msg;
    
    switch (pwd_req_ind->type)
    {
        case TYPE_NO_REQUIRED:
            cntx->phone_lock.is_required = MMI_FALSE;
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NONE;
            srv_bootup_sec_notify_verify_result(
                sim,
                SRV_BOOTUP_VERI_NONE,
                SRV_BOOTUP_ATTEMPT_INFINITE_NUMBER,
                MMI_FALSE);
            srv_bootup_sec_notify_sim_status(sim, MMI_FALSE);
            break;

        case TYPE_PHONELOCK:
            if (cntx->phone_lock.password[0] != '\0' && /* User inputted */
                !cntx->phone_lock.is_required &&        /* Phone lock passed */
                cntx->phone_lock.n_auto_trials > 0)     /* Protect from infinite trial */
            {
                /* Auto verify phone lock */
                
                /*
                 * User has inputted phone password and verified successfully.
                 * Send previous input to verify other protocol layers directly.
                 * We assume all phone password of each layer are the same.
                 */
                cntx->phone_lock.n_auto_trials--;
                srv_bootup_sec_send_verify_req(
                    sim,
                    cntx->phone_lock.password,
                    NULL);

                /*
                 * We don't callback here. We can still get the result correctly
                 * by the state after the phone lock.
                 */
            }
            else
            {
                cntx->phone_lock.sim_set |= sim;
                cntx->phone_lock.is_required = MMI_TRUE;
                
                srv_bootup_sec_notify_verify_result(
                    sim,
                    SRV_BOOTUP_VERI_PHONE_LOCK,
                    SRV_BOOTUP_ATTEMPT_INFINITE_NUMBER,
                    MMI_FALSE);
            }
            break;

        case TYPE_CHV1:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_CHV1;
            sim_cntx->n_remaining_attempts =
                srv_sim_ctrl_get_n_remaining_attempts(sim, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            srv_bootup_sec_notify_verify_result(
                sim,
                sim_cntx->verification_type,
                sim_cntx->n_remaining_attempts,
                MMI_FALSE);
            srv_bootup_sec_notify_sim_status(sim, MMI_FALSE);
            break;

        case TYPE_UBCHV1:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_UBCHV1;
            sim_cntx->n_remaining_attempts =
                srv_sim_ctrl_get_n_remaining_attempts(sim, SRV_SIM_CTRL_PWD_TYPE_UBCHV1);
            srv_bootup_sec_notify_verify_result(
                sim,
                sim_cntx->verification_type,
                sim_cntx->n_remaining_attempts,
                MMI_FALSE);
            srv_bootup_sec_notify_sim_status(sim, MMI_FALSE);
            break;

        case TYPE_SIM_CARD_BLOCKED:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NONE;
            sim_cntx->n_remaining_attempts = 0;
            srv_bootup_sec_notify_verify_result(
                sim,
                sim_cntx->verification_type,
                0,
                MMI_TRUE); /* NOTE: MMI_TRUE here */
            srv_bootup_sec_notify_sim_status(sim, MMI_TRUE);
            break;

#ifdef __SIM_ME_LOCK__
        case TYPE_NP:
        case TYPE_NSP:
        case TYPE_SP:
        case TYPE_CP:
        case TYPE_IMSI_LOCK:
        case TYPE_LINK_NS_SP:
        case TYPE_LINK_SIM_C:
        
            srv_bootup_sec_pwd_req_ind_handle_person(
                sim,
                sim_cntx,
                pwd_req_ind);
                
            break;
#endif /* __SIM_ME_LOCK__ */

        default:
            /* Ignore */
            break;
    }

    return MMI_FALSE;
}


#ifdef __SIM_ME_LOCK__
/*****************************************************************************
 * FUNCTION
 *  srv_bootup_sec_pwd_req_ind_handle_person
 * DESCRIPTION
 *  Handle personalization part of SMU_PASSWORD_REQUIRED_IND.
 * PARAMETERS
 *  sim         [IN] From which protocol layer
 *  sim_cntx    [IN] Sim context
 *  pwd_req_ind [IN] mmi_smu_password_required_ind_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_sec_pwd_req_ind_handle_person(
                mmi_sim_enum sim,
                srv_bootup_sim_cntx_struct *sim_cntx,
                const mmi_smu_password_required_ind_struct *pwd_req_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL fatal_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pwd_req_ind->type)
    {
        case TYPE_NP:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NP;
            break;
            
        case TYPE_NSP:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NSP;
            break;
            
        case TYPE_SP:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_SP;
            break;
            
        case TYPE_CP:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_CP;
            break;
            
        case TYPE_IMSI_LOCK:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_SIMP;
            break;
            
        case TYPE_LINK_NS_SP:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NSSP;
            break;
            
        case TYPE_LINK_SIM_C:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_SIMCP;
            break;
            
        default:
            MMI_ASSERT(MMI_FALSE);
            break;
    }

    sim_cntx->n_remaining_attempts = pwd_req_ind->cphs_retry_count;

    fatal_error = (MMI_BOOL)(sim_cntx->n_remaining_attempts == 0);
    if (fatal_error)
    {
        sim_cntx->verification_type = SRV_BOOTUP_VERI_NONE;
    }
    
    srv_bootup_sec_notify_verify_result(
        sim,
        sim_cntx->verification_type,
        sim_cntx->n_remaining_attempts,
        fatal_error);

    srv_bootup_sec_notify_sim_status(sim, fatal_error);
}
#endif /* __SIM_ME_LOCK__ */


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_sec_smu_fail_ind_hdlr
 * DESCRIPTION
 *  Listens to SMU_FAIL_IND from L4C.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_smu_fail_ind_struct*
 * RETURNS
 *  MMI_FALSE; means continue routing the message
 *****************************************************************************/
MMI_BOOL srv_bootup_sec_smu_fail_ind_hdlr(mmi_sim_enum sim, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_cntx_struct *sim_cntx;
    mmi_smu_fail_ind_struct *fail_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_bootup_get_sim_cntx(sim);
    
    MMI_ASSERT(msg != NULL);
    fail_ind = (mmi_smu_fail_ind_struct*)msg;

    switch (fail_ind->cause)
    {
        case SIM_ACCESS_ERROR:
        case SIM_CMD_FAIL:
        case SIM_FATAL_ERROR:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NONE;
            srv_bootup_sec_notify_verify_result(
                sim,
                sim_cntx->verification_type,
                0,
                MMI_TRUE);
            srv_bootup_sec_notify_sim_status(sim, MMI_TRUE);
            break;

        case SIM_CARD_REMOVED:
        case SIM_NO_INSERTED:
        case SIM_PLUG_OUT:
            sim_cntx->is_inserted = MMI_FALSE;
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NONE;
#ifdef __CANCEL_LOCK_POWERON__
            srv_bootup_cv_notify_sim_removed(sim);
#endif
            srv_bootup_sec_notify_verify_result(
                sim,
                sim_cntx->verification_type,
                0,
                MMI_TRUE);
            srv_bootup_sec_notify_sim_status(sim, MMI_TRUE);
            break;

        case SIM_PLUG_IN:
            sim_cntx->is_inserted = MMI_TRUE;
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NONE;
            srv_bootup_sec_notify_sim_status(sim, MMI_FALSE);
            break;

#if defined(__SIM_RECOVERY_ENHANCEMENT__)
        case SIM_RECOVERY_START:
            /* We don't change the state of insertion */
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NONE;
            srv_bootup_sec_notify_verify_result(
                sim,
                sim_cntx->verification_type,
                0,
                MMI_TRUE);
            srv_bootup_sec_notify_sim_status(sim, MMI_TRUE);
            break;

        case SIM_RECOVERY_END:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NONE;
            srv_bootup_sec_notify_sim_status(sim, MMI_FALSE);
            break;
#endif /* defined(__SIM_RECOVERY_ENHANCEMENT__) */

        case SIM_ACCESS_PROFILE_ON:
        case DUALSIM_DISCONNECTED:
            sim_cntx->verification_type = SRV_BOOTUP_VERI_NONE;
            srv_bootup_sec_notify_verify_result(
                sim,
                sim_cntx->verification_type,
                0,
                MMI_TRUE);
            srv_bootup_sec_notify_sim_status(sim, MMI_TRUE);
            break;

        case SIM_CHV_BLOCK:
            /* Will not be sent by L4 */
            break;
            
        case SIM_CMD_SUCCESS:
        default:
            /* Ignore */
            break;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_sec_notify_sim_status
 * DESCRIPTION
 *  Notify application the status change of SIM.
 * PARAMETERS
 *  sim             [IN] Which SIM.
 *  fatal_error     [IN] SIM fatal error, such as UBCHV1 blocked, removed, etc.
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_sec_notify_sim_status(mmi_sim_enum sim, MMI_BOOL fatal_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_status_changed_evt_struct status_changed_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_NOTIFY_SIM_STATUS, sim, fatal_error);

    MMI_FRM_INIT_EVENT(&status_changed_evt, EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED);
    status_changed_evt.sim = sim;
    status_changed_evt.fatal_error = fatal_error;
    MMI_FRM_CB_EMIT_POST_EVENT(&status_changed_evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_sec_send_verify_req
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
static void srv_bootup_sec_send_verify_req(
                mmi_sim_enum sim,
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
    app_strlcpy((CHAR*)verify_pin_req->pin, pwd, sizeof(verify_pin_req->pin));

    if (new_pwd != NULL)
    {
        app_strlcpy((CHAR*)verify_pin_req->new_pin, new_pwd, sizeof(verify_pin_req->new_pin));
    }
    else
    {
        verify_pin_req->new_pin[0] = '\0';
    }

    /*
     * If pin_type is TYPE_UNSPECIFIED, the result will be reported
     * from SMU_PASSWORD_REQUIRED_IND or SMU_FAIL_IND.
     */
    verify_pin_req->pin_type = TYPE_UNSPECIFIED;
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(sim),
        MSG_ID_MMI_SMU_VERIFY_PIN_REQ,
        (oslParaType*)verify_pin_req,
        NULL);
}


/****************************************************************************
 * Global functions
 ****************************************************************************/

/*****************************************************************************
 * Please refer to BootupSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_bootup_verification_is_passed(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_cntx_struct *sim_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_bootup_protocol_is_ready())
    {
        return MMI_FALSE;
    }
    
    if (srv_bootup_phone_lock_is_required())
    {
        return MMI_FALSE;
    }

    sim_cntx = srv_bootup_get_sim_cntx(sim);

    return (MMI_BOOL)(sim_cntx->verification_type == SRV_BOOTUP_VERI_NONE);
}


/*****************************************************************************
 * Please refer to BootupSrvGprot.h
 *****************************************************************************/
srv_bootup_verification_type_enum srv_bootup_get_verification_info(
                                    mmi_sim_enum sim,
                                    S32 *n_remaining_attempts)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_cntx_struct *sim_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_cntx = srv_bootup_get_sim_cntx(sim);

    if (srv_bootup_phone_lock_is_required())
    {
        if (n_remaining_attempts != NULL)
        {
            *n_remaining_attempts = SRV_BOOTUP_ATTEMPT_INFINITE_NUMBER;
        }
        
        return SRV_BOOTUP_VERI_PHONE_LOCK;
    }

    if (n_remaining_attempts != NULL)
    {
        if (sim_cntx->verification_type == SRV_BOOTUP_VERI_CHV1)
        {
            /* Always get the latest number from SIM ctrl */
            *n_remaining_attempts =
                srv_sim_ctrl_get_n_remaining_attempts(sim, SRV_SIM_CTRL_PWD_TYPE_CHV1);
        }
        else if (sim_cntx->verification_type == SRV_BOOTUP_VERI_UBCHV1)
        {
            /* Always get the latest number from SIM ctrl */
            *n_remaining_attempts =
                srv_sim_ctrl_get_n_remaining_attempts(sim, SRV_SIM_CTRL_PWD_TYPE_UBCHV1);
        }
        else /* Personalizations */
        {
            *n_remaining_attempts = sim_cntx->n_remaining_attempts;
        }
    }

    return (sim_cntx->verification_type);
}


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
MMI_BOOL srv_bootup_phone_lock_is_required(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_bootup_security_cntx.phone_lock.is_required);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_try_to_verify_remaining_phone_locks
 * DESCRIPTION
 *  Verify phone lock of remaining L4Cs by given password.
 *  It will change cntx->session.sim as the L4C currently verifying.
 * PARAMETERS
 *  cntx        [IN/OUT] Context
 *  password    [IN]     Password in ASCII
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_try_to_verify_remaining_phone_locks(
                srv_bootup_security_cntx_struct *cntx,
                const CHAR *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx->phone_lock.sim_set != 0);

    /* Find a L4C whose phone lock is required */
    for (i = 0; i < SRV_SIM_CTRL_MAX_SIM_NUM; i++)
    {
        sim = mmi_frm_index_to_sim(i);
        
        if (cntx->phone_lock.sim_set & sim)
        {
            break;
        }
    }

    cntx->phone_lock.sim_set &= ~sim;
    cntx->phone_lock.n_auto_trials--;
    cntx->session.sim = sim;
    
    srv_bootup_sec_send_verify_req(
        sim,
        password,
        NULL);
}


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
void srv_bootup_verify_phone_lock(
        const WCHAR *password,
        srv_bootup_verify_result_callback result_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_security_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(srv_bootup_phone_lock_is_required());

    cntx = &(g_srv_bootup_security_cntx);

    /*
     * We don't allow multiple session. One verification can be processed at
     * one time.
     */
    MMI_ASSERT(cntx->session.result_callback == NULL);

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_VERIFY_PHONE_LOCK, (U32)result_callback);

    cntx->phone_lock.n_auto_trials = SRV_SIM_CTRL_MAX_SIM_NUM;

    cntx->session.type = SRV_BOOTUP_VERI_PHONE_LOCK;
    cntx->session.result_callback = result_callback;
    cntx->session.user_data = user_data;

    srv_util_convert_n_wchars_to_ascii(
        cntx->phone_lock.password,
        password,
        sizeof(cntx->phone_lock.password) - 1);

    srv_bootup_try_to_verify_remaining_phone_locks(
        cntx,
        cntx->phone_lock.password);
}


/*****************************************************************************
 * Please refer to BootupSrvGprot.h
 *****************************************************************************/
void srv_bootup_verify(
        mmi_sim_enum sim,
        const WCHAR *password,
        srv_bootup_verify_result_callback result_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_security_cntx_struct *cntx;
    srv_bootup_verification_type_enum veri_type;
    CHAR pwd_s8[SRV_BOOTUP_MAX_PWD_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(password != NULL);

    cntx = &(g_srv_bootup_security_cntx);
    veri_type = srv_bootup_get_verification_info(sim, NULL);

    switch (veri_type)
    {
        case SRV_BOOTUP_VERI_CHV1:
        case SRV_BOOTUP_VERI_NP:
        case SRV_BOOTUP_VERI_NSP:
        case SRV_BOOTUP_VERI_SP:
        case SRV_BOOTUP_VERI_CP:
        case SRV_BOOTUP_VERI_SIMP:
        case SRV_BOOTUP_VERI_NSSP:
        case SRV_BOOTUP_VERI_SIMCP:
            break;

        case SRV_BOOTUP_VERI_PHONE_LOCK:
            srv_bootup_verify_phone_lock(password, result_callback, user_data);
            return;

        case SRV_BOOTUP_VERI_UBCHV1:
            /* Please call srv_bootup_verify_ubchv(). */
        default:
            /* Used wrong API to verify */
            MMI_ASSERT(MMI_FALSE);
            break;
    }
    

    /*
     * We don't allow multiple session. One verification can be processed at
     * one time.
     */
    MMI_ASSERT(cntx->session.result_callback == NULL);

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_VERIFY, sim, (U32)result_callback, veri_type);

    cntx->session.sim = sim;
    cntx->session.type = veri_type;
    cntx->session.result_callback = result_callback;
    cntx->session.user_data = user_data;

    srv_util_convert_n_wchars_to_ascii(pwd_s8, password, sizeof(pwd_s8) - 1);
    
    #ifdef __INVALID_SIM_RECOVERY__
    if(veri_type == SRV_BOOTUP_VERI_CHV1)
    {
        srv_sim_ctrl_invalid_sim_recovery_set_pin(sim, pwd_s8);
    }
    #endif
    
    srv_bootup_sec_send_verify_req(sim, pwd_s8, NULL);
}


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
void srv_bootup_verify_ubchv(
        mmi_sim_enum sim,
        const WCHAR *ubchv,
        const WCHAR *newchv,
        srv_bootup_verify_result_callback result_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_security_cntx_struct *cntx;
    srv_bootup_verification_type_enum veri_type;
    CHAR ubchv_s8[SRV_BOOTUP_MAX_PWD_LEN + 1];
    CHAR newchv_s8[SRV_BOOTUP_MAX_PWD_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ubchv != NULL && newchv != NULL);
    veri_type = srv_bootup_get_verification_info(sim, NULL);
    MMI_ASSERT(veri_type == SRV_BOOTUP_VERI_UBCHV1);
    
    cntx = &(g_srv_bootup_security_cntx);

    /*
     * We don't allow multiple session. One verification can be processed at
     * one time.
     */
    MMI_ASSERT(cntx->session.result_callback == NULL);

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_VERIFY_UBCHV, sim, (U32)result_callback);

    cntx->session.sim = sim;
    cntx->session.type = veri_type;
    cntx->session.result_callback = result_callback;
    cntx->session.user_data = user_data;

    srv_util_convert_n_wchars_to_ascii(ubchv_s8, ubchv, sizeof(ubchv_s8) - 1);
    srv_util_convert_n_wchars_to_ascii(newchv_s8, newchv, sizeof(newchv_s8) - 1);
    
    srv_bootup_sec_send_verify_req(sim, ubchv_s8, newchv_s8);
}

