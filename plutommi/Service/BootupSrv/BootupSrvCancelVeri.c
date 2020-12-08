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
 *  BootupSrvCancelVeri.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Module to cancel verification during booting
 *
 *  If SIM verification is required, we may cancel it and treat as no SIM
 *  inserted.
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

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_utility_gprot.h"
#include "l4c_common_enum.h"
#include "BootupSrvIprot.h"
#include "BootupSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_frm_gprot.h"
#include "mmi_msg_struct.h"
#include "BootupSrv.h"


#ifdef __CANCEL_LOCK_POWERON__

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_sim_enum sim;
    srv_bootup_verification_type_enum type;
    S32 init_module_index;
    srv_bootup_cancel_verification_callback result_callback;
    void *user_data;
} srv_bootup_cancel_veri_session_struct;


/****************************************************************************
 * Global variables
 ****************************************************************************/

static const l4c_cancel_lock_poweron_type_enum g_srv_bootup_cv_init_module[] =
{
    TYPE_PHB_SMS_PARAM_ONLY_INIT,
    TYPE_PHB_NORMAL_INIT,
    TYPE_SMS_NORMAL_INIT
};

static const S32 g_srv_bootup_cv_init_module_size =
    sizeof(g_srv_bootup_cv_init_module) / sizeof(g_srv_bootup_cv_init_module[0]);

static srv_bootup_cancel_veri_session_struct *g_srv_bootup_cv_processing = NULL;

static U8 g_srv_bootup_cv_is_cancelled; /* Bit set of SIM */


/****************************************************************************
 * Functions
 ****************************************************************************/

static U8 srv_bootup_cv_cancel_lock_rsp_hdlr(
                void *msg,
                S32 src_mod);

static void srv_bootup_cv_complete(
                srv_bootup_cancel_veri_session_struct *session,
                MMI_BOOL success);

static mmi_ret srv_bootup_cv_invoke_callback(mmi_event_struct *evt);

#endif /* __CANCEL_LOCK_POWERON__ */

/*****************************************************************************
 * FUNCTION
 *  srv_boootup_cv_init
 * DESCRIPTION
 *  Initialize cancel-verification module.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE  : If in initializing.
 *  MMI_FALSE : If completed
 *****************************************************************************/
void srv_boootup_cv_init(void)
{
#ifdef __CANCEL_LOCK_POWERON__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_bootup_cv_is_cancelled = 0;
#endif
}


#ifdef __CANCEL_LOCK_POWERON__

/*****************************************************************************
 * FUNCTION
 *  srv_bootup_cv_init_next_module
 * DESCRIPTION
 *  Initialize next module indicated by cntx->cancel.init_module_index.
 * PARAMETERS
 *  session        [IN] Session
 * RETURN VALUES
 *  MMI_TRUE  : If in initializing.
 *  MMI_FALSE : If completed
 *****************************************************************************/
static MMI_BOOL srv_bootup_cv_init_next_module(
                    srv_bootup_cancel_veri_session_struct *session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (session->init_module_index < g_srv_bootup_cv_init_module_size)
    {
        mmi_eq_cancel_lock_poweron_req_struct *req;

        /* Send to primitive to init PHB/SMS after the user cancels the lock. */
        req = OslConstructDataPtr(sizeof(mmi_eq_cancel_lock_poweron_req_struct));
        req->type = g_srv_bootup_cv_init_module[session->init_module_index];
        
        mmi_frm_send_ilm(
            mmi_frm_sim_to_l4c_mod(session->sim),
            MSG_ID_MMI_EQ_CANCEL_LOCK_POWERON_REQ,
            (oslParaType*)req,
            NULL);
    
        session->init_module_index++;

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_cv_cancel_lock_rsp_hdlr
 * DESCRIPTION
 *  Handler for MSG_ID_MMI_EQ_CANCEL_LOCK_POWERON_RSP.
 * PARAMETERS
 *  sim     [IN] From which protocol layer
 *  msg     [IN] mmi_eq_cancel_lock_poweron_rsp_struct
 * RETURNS
 *  MMI_FALSE
 *****************************************************************************/
static U8 srv_bootup_cv_cancel_lock_rsp_hdlr(
                void *msg,
                S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;
    srv_bootup_cancel_veri_session_struct *session;
    mmi_eq_cancel_lock_poweron_rsp_struct *rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim(src_mod);
    rsp = (mmi_eq_cancel_lock_poweron_rsp_struct*)msg;
    
    session = g_srv_bootup_cv_processing;
    MMI_ASSERT(sim == session->sim);

    if (rsp->result)
    {
        if (srv_bootup_cv_init_next_module(session))
        {
            /* Initialize the module */
        }
        else
        {
            srv_bootup_cv_complete(session, MMI_TRUE);
        }
    }
    else
    {
        srv_bootup_cv_complete(session, MMI_FALSE);
    }

    return (U8)MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bootup_cv_complete
 * DESCRIPTION
 *  Notify client that cancelling is completed.
 * PARAMETERS
 *  session     [IN] Session
 *  success     [IN] Success or not
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bootup_cv_complete(
                srv_bootup_cancel_veri_session_struct *session,
                MMI_BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_cancel_verification_result_struct result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_clear_protocol_event_handler(
        MSG_ID_MMI_EQ_CANCEL_LOCK_POWERON_RSP,
        (PsIntFuncPtr)srv_bootup_cv_cancel_lock_rsp_hdlr);

    result.sim = session->sim;
    result.type = session->type;
    result.success = success;

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_CANCEL_VERI_CALLBACK,
        result.sim, session->type, success, (U32)session->result_callback);

    MMI_ASSERT(g_srv_bootup_cv_processing == session);
    g_srv_bootup_cv_processing = NULL;

    /*
     * The SIM may be already removed before we finish the init.
     * We should not use srv_bootup_sim_is_inserted() here, because the
     * function was only updated by SIM_STATUS_UPDATE_IND before we decide
     * mode.
     */
    if (success && srv_sim_ctrl_is_inserted(session->sim))
    {
        g_srv_bootup_cv_is_cancelled |= session->sim;
    }

    MMI_ASSERT(session->result_callback != NULL);
    session->result_callback(session->user_data, &result);
    session->result_callback = NULL;

    OslMfree(session);
}


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
void srv_bootup_cancel_verification(
        mmi_sim_enum sim,
        srv_bootup_cancel_verification_callback result_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_cancel_veri_session_struct *session;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We can not cancel again if the SIM verification has been cancelled */
    MMI_ASSERT(!srv_bootup_veri_is_cancelled(sim));
    /* Only some verification types can be cancelled */
    MMI_ASSERT(srv_bootup_veri_can_be_cancelled(sim));
    /* We can accept only one cancelling session */
    MMI_ASSERT(g_srv_bootup_cv_processing == NULL);

    session = (srv_bootup_cancel_veri_session_struct*)
        OslMalloc(sizeof(srv_bootup_cancel_veri_session_struct));

    g_srv_bootup_cv_processing = session;

    session->sim = sim;
    session->type = srv_bootup_get_verification_info(sim, NULL);
    session->init_module_index = 0;
    session->result_callback = result_callback;
    session->user_data = user_data;

    MMI_TRACE(SRV_BOOTUP_TRC_GROUP, TRC_SRV_BOOTUP_CANCEL_VERIFICATION,
        sim, (U32)result_callback, session->type);

    if (srv_bootup_is_booting())
    {
        mmi_frm_set_protocol_event_handler(
            MSG_ID_MMI_EQ_CANCEL_LOCK_POWERON_RSP,
            (PsIntFuncPtr)srv_bootup_cv_cancel_lock_rsp_hdlr,
            MMI_FALSE);

        srv_bootup_cv_init_next_module(session);
    }
    else
    {
        mmi_event_struct post_call_evt;
        
        MMI_FRM_INIT_EVENT(&post_call_evt, 0);
        MMI_FRM_POST_EVENT(&post_call_evt, srv_bootup_cv_invoke_callback, session);
    }
}


static mmi_ret srv_bootup_cv_invoke_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_cancel_veri_session_struct *session;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    session = (srv_bootup_cancel_veri_session_struct*)(evt->user_data);

    srv_bootup_cv_complete(session, MMI_TRUE);
    
    return MMI_RET_OK;
}


void srv_bootup_cv_notify_sim_removed(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_bootup_cv_is_cancelled &= ~sim;
}

#endif /* __CANCEL_LOCK_POWERON__ */


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
MMI_BOOL srv_bootup_veri_can_be_cancelled(mmi_sim_enum sim)
{
#ifdef __CANCEL_LOCK_POWERON__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_verification_type_enum veri_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    veri_type = srv_bootup_get_verification_info(sim, NULL);

    if (veri_type != SRV_BOOTUP_VERI_NONE &&
        veri_type != SRV_BOOTUP_VERI_PHONE_LOCK)
    {
        return MMI_TRUE;
    }
#endif /* __CANCEL_LOCK_POWERON__ */

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to BootupSrvIprot.h
 *****************************************************************************/
MMI_BOOL srv_bootup_veri_is_cancelled(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CANCEL_LOCK_POWERON__
    return ((g_srv_bootup_cv_is_cancelled & sim) != 0);
#else
    return MMI_FALSE;
#endif
}


