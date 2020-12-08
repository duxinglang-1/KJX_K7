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
*  CentralConfigAgentDm.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
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
*
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


//#ifdef __CCA_SUPPORT__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMI_include.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_public_api.h"

#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"



#include "CcaSrvGprot.h"
#include "CcaSrvConfig.h"
#include "CcaSrvProt.h"


#ifdef __MMI_CCA_SUPPORT__

#ifdef __SRV_CCA_PROF_OPER__

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
/* DM Get/Update Operation */
static void srv_cca_get_prof_ind_hdlr(void *msg, int mod_id, void *ilm);
static void srv_cca_app_get_prof_ind_hdlr(void *msg);
static void srv_cca_app_get_prof_rsp_hdlr(void *msg);

static void srv_cca_update_prof_ind_hdlr(void *msg, int mod_id, void *ilm);
static void srv_cca_app_update_prof_ind_hdlr(void *msg);
static void srv_cca_app_update_prof_rsp_hdlr(void *msg);

static void srv_cca_send_cca_app_get_prof_ind(U16 sim_id, U16 app_id, S32 prof_id);
static void srv_cca_send_cca_get_prof_rsp(
                module_type dest_mod_id,
                U16 sim_id,
                U16 app_id,
                S32 prof_id,
                S32 hConfig,
                srv_cca_status_enum result);

static void srv_cca_send_cca_app_update_prof_ind(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig);
static void srv_cca_send_cca_update_prof_rsp(
                module_type dest_mod_id,
                U16 sim_id,
                U16 app_id,
                S32 prof_id,
                S32 hConfig,
                srv_cca_status_enum result);

/* DM Job handler */
static void srv_cca_start_async_job(srv_cca_inst_struct *inst);
static srv_cca_status_enum srv_cca_job_set_to_async_context(srv_cca_inst_struct *inst, srv_cca_job_type_enum type, srv_cca_job_struct *job);

#ifdef __SRV_CCA_DM_SESSION__
/* DM Session Operation */
static void srv_cca_session_begin_ind_hdlr(void *msg, int mod_id, void *ilm);
static void srv_cca_manager_handle_session_begin_ind(
                srv_cca_inst_struct *inst,
                module_type src_mod_id,
                srv_cca_session_begin_ind_struct *session_begin_ind,
                srv_cca_status_enum result);
static void srv_cca_send_session_begin_rsp(
                module_type dest_mod_id,
                srv_cca_session_begin_ind_struct *session_begin_ind,
                srv_cca_status_enum result);

static void srv_cca_session_end_ind_hdlr(void *msg, int mod_id, void *ilm);
static void srv_cca_manager_handle_session_end_ind(
                srv_cca_cntx_struct *cntx,
                module_type src_mod_id,
                srv_cca_session_end_ind_struct *session_end_ind,
                srv_cca_status_enum result);
static void srv_cca_send_session_end_rsp(
                module_type dest_mod_id,
                srv_cca_session_end_ind_struct *session_end_ind,
                srv_cca_status_enum result);
#endif /* __SRV_CCA_DM_SESSION__ */

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/




/*****************************************************************************
 * FUNCTION
 *  srv_cca_pevt_dm_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dm_init(void)
{
    /* DM get operation */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_GET_PROF_IND,
        (PsIntFuncPtr) srv_cca_get_prof_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_APP_GET_PROF_IND,
        (PsIntFuncPtr) srv_cca_app_get_prof_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_APP_GET_PROF_RSP,
        (PsIntFuncPtr) srv_cca_app_get_prof_rsp_hdlr,
        MMI_FALSE);

    /* DM update operation */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_UPDATE_PROF_IND,
        (PsIntFuncPtr) srv_cca_update_prof_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_APP_UPDATE_PROF_IND,
        (PsIntFuncPtr) srv_cca_app_update_prof_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP,
        (PsIntFuncPtr) srv_cca_app_update_prof_rsp_hdlr,
        MMI_FALSE);

#ifdef __SRV_CCA_DM_SESSION__

    /* DM session operation */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SESSION_BEGIN_IND,
        (PsIntFuncPtr) srv_cca_session_begin_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SESSION_END_IND,
        (PsIntFuncPtr) srv_cca_session_end_ind_hdlr,
        MMI_FALSE);
#endif /* __SRV_CCA_DM_SESSION__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_prof_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_GET_PROF_IND handler
 * PARAMETERS
 *  msg     [IN]        
 *  mod_id          [IN]        
 *  ilm             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_get_prof_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_job_struct *job;
    srv_cca_get_prof_ind_struct *data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_get_prof_ind_struct*) msg;

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_GET_PROF_IND_HDLR, data->sim_id, data->app_id, data->prof_id);

    job = srv_cca_job_create_new_job(SRV_CCA_JOB_GET_PROF_IND_REQ, (module_type) mod_id, msg);
    if (!job)
    {
        srv_cca_send_cca_get_prof_rsp(
            (module_type) mod_id,
            data->sim_id,
            data->app_id,
            data->prof_id,
            0,
            SRV_CCA_STATUS_MEMFULL);
        return;
    }
    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_GET_PROF_IND_REQ, job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_app_get_prof_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_APP_GET_PROF_IND handler
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_app_get_prof_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_dispatch_profile_operations(SRV_CCA_OPER_GET, ((srv_cca_app_get_prof_ind_struct*) msg)->app_id, msg);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_app_get_prof_rsp_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_APP_GET_PROF_RSP handler
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_app_get_prof_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_get_prof_rsp_struct *data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_app_get_prof_rsp_struct*) msg;

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_APP_GET_PROF_RSP_HDLR_CCA_STATE, inst->state, inst->oper);
    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_APP_GET_PROF_RSP_HDLR_DATA_INFO,
        data->sim_id,
        data->app_id,
        data->prof_id,
        data->hConfig,
        data->result);

    SRV_CCA_ASSERT(inst->state == SRV_CCA_STATE_ASYNC);
    SRV_CCA_ASSERT(inst->oper == SRV_CCA_OPER_GET);
    SRV_CCA_ASSERT(inst->src_mod_id != MOD_NIL);

    srv_cca_send_cca_get_prof_rsp(
        inst->src_mod_id,
        data->sim_id,
        data->app_id,
        data->prof_id,
        data->hConfig,
        data->result);

    /* reset async context */
    srv_cca_dm_reset_cntx(inst);

    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_APP_GET_PROF_RSP_FEEDBACK, NULL);
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_update_prof_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_UPDATE_PROF_IND handler
 * PARAMETERS
 *  msg     [IN]        
 *  mod_id          [IN]        
 *  ilm             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_update_prof_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_job_struct *job;
    srv_cca_update_prof_ind_struct *data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_update_prof_ind_struct*) msg;

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_UPDATE_PROF_IND_HDLR, data->sim_id, data->app_id, data->prof_id, data->hConfig);

    job = srv_cca_job_create_new_job(SRV_CCA_JOB_UPDATE_PROF_IND_REQ, (module_type) mod_id, msg);
    if (!job)
    {
        srv_cca_send_cca_update_prof_rsp(
            (module_type) mod_id,
            data->sim_id,
            data->app_id,
            data->prof_id,
            data->hConfig,
            SRV_CCA_STATUS_MEMFULL);
        return;
    }
    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_UPDATE_PROF_IND_REQ, job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_app_update_prof_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_APP_UPDATE_PROF_IND handler
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_app_update_prof_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_update_prof_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_app_update_prof_ind_struct*) msg;
    SRV_CCA_ASSERT(data->hConfig);
    srv_cca_dispatch_profile_operations(SRV_CCA_OPER_UPDATE, data->app_id, msg);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_app_update_prof_rsp_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP handler
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_app_update_prof_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_update_prof_rsp_struct *data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_app_update_prof_rsp_struct*) msg;

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_APP_UPDATE_PROF_RSP_HDLR_CCA_STATE, inst->state, inst->oper);
    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_APP_UPDATE_PROF_RSP_HDLR_DATA_INFO,
        data->sim_id,
        data->app_id,
        data->prof_id,
        data->hConfig,
        data->result);

    SRV_CCA_ASSERT(inst->state == SRV_CCA_STATE_ASYNC);
    SRV_CCA_ASSERT(inst->oper == SRV_CCA_OPER_UPDATE);
    SRV_CCA_ASSERT(inst->src_mod_id != MOD_NIL);

    srv_cca_send_cca_update_prof_rsp(
        inst->src_mod_id,
        data->sim_id,
        data->app_id,
        data->prof_id,
        data->hConfig,
        data->result);

    /* reset async context */
    srv_cca_dm_reset_cntx(inst);

    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_APP_UPDATE_PROF_RSP_FEEDBACK, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_cca_app_get_prof_ind
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_APP_GET_PROF_IND
 * PARAMETERS
 *  sim_id      [IN]        
 *  app_id      [IN]        
 *  prof_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_cca_app_get_prof_ind(U16 sim_id, U16 app_id, S32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_get_prof_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_CCA_APP_GET_PROF_IND, sim_id, app_id, prof_id);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_app_get_prof_ind_struct);

    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;

    mmi_frm_send_ilm(srv_cca_get_module_id_by_app(app_id), MSG_ID_SRV_CCA_APP_GET_PROF_IND, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_cca_app_get_prof_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_APP_GET_PROF_RSP
 * PARAMETERS
 *  sim_id      [IN]        
 *  app_id      [IN]        
 *  prof_id     [IN]        
 *  hConfig     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_send_cca_app_get_prof_rsp(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_get_prof_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_CCA_APP_GET_PROF_RSP, app_id, prof_id, hConfig, result);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_app_get_prof_rsp_struct);

    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;
    data->result = result;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_APP_GET_PROF_RSP, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_cca_get_prof_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_GET_PROF_RSP
 * PARAMETERS
 *  dest_mod_id     [IN]        
 *  sim_id          [IN]        
 *  app_id          [IN]        
 *  prof_id         [IN]        
 *  hConfig         [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_cca_get_prof_rsp(
        module_type dest_mod_id,
        U16 sim_id,
        U16 app_id,
        S32 prof_id,
        S32 hConfig,
        srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_get_prof_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_CCA_GET_PROF_RSP, dest_mod_id, sim_id, app_id, prof_id, hConfig, result);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_get_prof_rsp_struct);

    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;
    data->result = result;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_CCA_GET_PROF_RSP, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_cca_app_update_prof_ind
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_APP_UPDATE_PROF_IND
 * PARAMETERS
 *  sim_id      [IN]        
 *  app_id      [IN]        
 *  prof_id     [IN]        
 *  hConfig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_cca_app_update_prof_ind(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_update_prof_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_CCA_APP_UPDATE_PROF_IND, app_id, prof_id, hConfig);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_app_update_prof_ind_struct);

    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;

    mmi_frm_send_ilm(srv_cca_get_module_id_by_app(app_id), MSG_ID_SRV_CCA_APP_UPDATE_PROF_IND, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_cca_app_update_prof_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP
 * PARAMETERS
 *  sim_id      [IN]        
 *  app_id      [IN]        
 *  prof_id     [IN]        
 *  hConfig     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_send_cca_app_update_prof_rsp(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_update_prof_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_CCA_APP_UPDATE_PROF_RSP, app_id, prof_id, hConfig, result);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_app_update_prof_rsp_struct);

    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;
    data->result = result;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_cca_update_prof_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_UPDATE_PROF_RSP
 * PARAMETERS
 *  dest_mod_id     [IN]        
 *  sim_id          [IN]        
 *  app_id          [IN]        
 *  prof_id         [IN]        
 *  hConfig         [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_cca_update_prof_rsp(
        module_type dest_mod_id,
        U16 sim_id,
        U16 app_id,
        S32 prof_id,
        S32 hConfig,
        srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_update_prof_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_CCA_UPDATE_PROF_RSP, dest_mod_id, app_id, prof_id, hConfig, result);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_update_prof_rsp_struct);

    data->sim_id = sim_id;
    data->app_id = app_id;
    data->prof_id = prof_id;
    data->hConfig = hConfig;
    data->result = result;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_CCA_UPDATE_PROF_RSP, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dm_reset_cntx
 * DESCRIPTION
 *  reset asynchronous event context parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dm_reset_cntx(srv_cca_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_RESET_ASYNC_CONTEXT);

    if (!inst)
        return;
    
    inst->src_mod_id = MOD_NIL;
    inst->sim_id = MMI_SIM_NONE;
    inst->appId = 0;
    inst->profId = 0;
    inst->asynchConfig = 0; /* do not free this document as it'll be used & freed by caller module */
    inst->oper = SRV_CCA_OPER_NULL;
    inst->state = SRV_CCA_STATE_IDLE;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_start_async_job
 * DESCRIPTION
 *  execute the asynchronous job (eg, get/update profile)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_start_async_job(srv_cca_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_START_ASYNC_JOB,
        inst->src_mod_id,
        inst->state,
        inst->oper);

    SRV_CCA_ASSERT(inst->oper != SRV_CCA_OPER_NULL);

    inst->state = SRV_CCA_STATE_ASYNC;
    switch (inst->oper)
    {
        case SRV_CCA_OPER_GET:
            srv_cca_send_cca_app_get_prof_ind(inst->sim_id, inst->appId, inst->profId);
            break;

        case SRV_CCA_OPER_UPDATE:
            srv_cca_send_cca_app_update_prof_ind(
                inst->sim_id,
                inst->appId,
                inst->profId,
                inst->asynchConfig);
            break;

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_summit_job_to_async_manager
 * DESCRIPTION
 *  summit job to async manager for handling
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_cca_status_enum srv_cca_summit_job_to_async_manager(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum result = SRV_CCA_STATUS_OK;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
#ifndef __SRV_CCA_SLIM__
        
        case SRV_CCA_JOB_NEXT_JOB_REQ:
        {
            SRV_CCA_ASSERT(!"Next job in async");
        }
            break;

        case SRV_CCA_JOB_INVALID_SETTING_IND_REQ:
            break;

        case SRV_CCA_JOB_NEW_SETTING_IND_REQ:
            break;
#endif /* __SRV_CCA_SLIM__ */

        case SRV_CCA_JOB_GET_PROF_IND_REQ:
        case SRV_CCA_JOB_UPDATE_PROF_IND_REQ:
        {
            cntx->curr_job = job;
            srv_cca_job_set_to_async_context(inst, type, job);
            srv_cca_start_async_job(inst);

        }
            break;

#ifdef __SRV_CCA_DM_SESSION__
        case SRV_CCA_JOB_SESSION_BEGIN_IND_REQ:
        {
            SRV_CCA_ASSERT(!"session begin in async");  /* already in session */
        }
            break;

        case SRV_CCA_JOB_SESSION_END_IND_REQ:
        {
            /* it should be at least one session operation is handled */
            srv_cca_manager_handle_session_end_ind(cntx,
                job->src_mod_id,
                (srv_cca_session_end_ind_struct*) job->data,
                SRV_CCA_STATUS_OK);
            srv_cca_job_free_job(job);
        }
            break;
#endif /* __SRV_CCA_DM_SESSION__ */

#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_JOB_NEW_SETTING_RSP_FEEDBACK:
        case SRV_CCA_JOB_NEW_DOC_RSP_FEEDBACK:
        case SRV_CCA_JOB_SIM_PROFILE_STATUS_FEEDBACK:
        {
            SRV_CCA_ASSERT(!"Prov feedback in async");
        }
            break;
#endif /* __SRV_CCA_SLIM__ */

        case SRV_CCA_JOB_APP_GET_PROF_RSP_FEEDBACK:
        case SRV_CCA_JOB_APP_UPDATE_PROF_RSP_FEEDBACK:
        {
            srv_cca_job_free_job(cntx->curr_job);
            cntx->curr_job = NULL;

#ifdef __SRV_CCA_DM_SESSION__

            /* If current DM operation is not a session operation, so it's finished now, please do next job. */
            if (inst->session_state == SRV_CCA_SESSION_STATE_NO_SESSION)
            {
                inst->cca_state = SRV_CCA_STATE_IDLE;
                inst->session_state = SRV_CCA_SESSION_STATE_IDLE;
                srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEXT_JOB_REQ, NULL);
            }
        
#else  /* __SRV_CCA_DM_SESSION__ */
            
            inst->cca_state = SRV_CCA_STATE_IDLE;
            srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEXT_JOB_REQ, NULL);

#endif /* __SRV_CCA_DM_SESSION__ */
         }

            break;

    #ifdef __MMI_PROV_MESSAGE_SUPPORT__

        case SRV_CCA_JOB_PROCESS_PROV_MSG_REQ:
        {
            cntx->job_list = 
                (srv_cca_job_struct*) srv_cca_slist_add_tail(
                (srv_cca_slist_struct *)cntx->job_list, (srv_cca_slist_struct *)job);
        }
            break;

        case SRV_CCA_JOB_PROCESS_PROV_MSG_CNF:
        {
            SRV_CCA_ASSERT(!"Read MSG done in Sync");
        }
        break;
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 


        default:
#ifndef __SRV_CCA_SLIM__
            SRV_CCA_ASSERT(!"Unknown job type");
#endif /* __SRV_CCA_SLIM__ */

            break;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dm_handle_in_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void srv_cca_dm_handle_in_idle(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {
    case SRV_CCA_JOB_GET_PROF_IND_REQ:
    case SRV_CCA_JOB_UPDATE_PROF_IND_REQ:
    {
#ifdef __SRV_CCA_DM_SESSION__            
        if (inst->session_state == SRV_CCA_SESSION_STATE_BEGIN)
            inst->session_state = SRV_CCA_SESSION_STATE_IN_SESSION;
        else
            inst->session_state = SRV_CCA_SESSION_STATE_NO_SESSION;
#endif /* __SRV_CCA_DM_SESSION__ */
        
        inst->cca_state = SRV_CCA_STATE_ASYNC;
        cntx->curr_job = job;
        srv_cca_job_set_to_async_context(inst, type, job);
        srv_cca_start_async_job(inst);
    }
        break;
        
#ifdef __SRV_CCA_DM_SESSION__
    case SRV_CCA_JOB_SESSION_BEGIN_IND_REQ:
    {
        /*
         * only need to set the session state, we will not change the CCA state from idle to async
         * until the first async operation indication is received according to DM module's recommend,
         * because DM may do nothing correlative with CCA.
         */
         srv_cca_manager_handle_session_begin_ind(
                        inst,
                        job->src_mod_id,
                        (srv_cca_session_begin_ind_struct*) job->data,
                        SRV_CCA_STATUS_OK);
         srv_cca_job_free_job(job);
     }
         break;
        
     case SRV_CCA_JOB_SESSION_END_IND_REQ:
     {
         /* must received SISSION_BEGIN_IND before */
         srv_cca_manager_handle_session_end_ind(cntx, 
                        job->src_mod_id,
                        (srv_cca_session_end_ind_struct*) job->data,
                        SRV_CCA_STATUS_OK);
         srv_cca_job_free_job(job);
     }
     break;
     
#endif /* __SRV_CCA_DM_SESSION__ */

    default:
        break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dm_handle_in_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void srv_cca_dm_handle_in_prov(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {
    case SRV_CCA_JOB_GET_PROF_IND_REQ:
        {
            srv_cca_get_prof_ind_struct *data;
                
            data = (srv_cca_get_prof_ind_struct*) job->data;
            srv_cca_send_cca_get_prof_rsp(
                    job->src_mod_id,
                    data->sim_id,
                    data->app_id,
                    data->prof_id,
                    0,
                    SRV_CCA_STATUS_CCA_BUSY);
            srv_cca_job_free_job(job);
        }
        break;
            
    case SRV_CCA_JOB_UPDATE_PROF_IND_REQ:
        {
            srv_cca_update_prof_ind_struct *data;
                
            data = (srv_cca_update_prof_ind_struct*) job->data;
            srv_cca_send_cca_update_prof_rsp(
                    job->src_mod_id,
                    data->sim_id,
                    data->app_id,
                    data->prof_id,
                    data->hConfig,
                    SRV_CCA_STATUS_CCA_BUSY);
            srv_cca_job_free_job(job);
        }
        break;
            
#ifdef __SRV_CCA_DM_SESSION__
    case SRV_CCA_JOB_SESSION_BEGIN_IND_REQ:
        {
            srv_cca_manager_handle_session_begin_ind(
                    inst,
                    job->src_mod_id,
                    (srv_cca_session_begin_ind_struct*) job->data,
                    SRV_CCA_STATUS_OK);
            srv_cca_job_free_job(job);
        }
        break;
            
    case SRV_CCA_JOB_SESSION_END_IND_REQ:
        {
            srv_cca_manager_handle_session_end_ind(cntx, 
                    job->src_mod_id,
                    (srv_cca_session_end_ind_struct*) job->data,
                    SRV_CCA_STATUS_OK);
            srv_cca_job_free_job(job);
        }
        break;
#endif /* __SRV_CCA_DM_SESSION__ */

    default:
        break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dm_handle_in_process_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void srv_cca_dm_handle_in_process_msg(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {
        case SRV_CCA_JOB_GET_PROF_IND_REQ:
        {
            srv_cca_get_prof_ind_struct *data;

            data = (srv_cca_get_prof_ind_struct*) job->data;
            srv_cca_send_cca_get_prof_rsp(
                        job->src_mod_id,
                        data->sim_id,
                        data->app_id,
                        data->prof_id,
                        0,
                        SRV_CCA_STATUS_CCA_BUSY);
            srv_cca_job_free_job(job);
        }
        break;
        
        case SRV_CCA_JOB_UPDATE_PROF_IND_REQ:
        {
            srv_cca_update_prof_ind_struct *data;
        
            data = (srv_cca_update_prof_ind_struct*) job->data;
            srv_cca_send_cca_update_prof_rsp(
                        job->src_mod_id,
                        data->sim_id,
                        data->app_id,
                        data->prof_id,
                        data->hConfig,
                        SRV_CCA_STATUS_CCA_BUSY);
                    srv_cca_job_free_job(job);
        }
        break;
        
#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_JOB_APP_GET_PROF_RSP_FEEDBACK:
        case SRV_CCA_JOB_APP_UPDATE_PROF_RSP_FEEDBACK:
        {
            SRV_CCA_ASSERT(!"DM op feedback in prov");
        }
        break;
#endif /* __SRV_CCA_SLIM__ */
        
#ifdef __SRV_CCA_DM_SESSION__
        case SRV_CCA_JOB_SESSION_BEGIN_IND_REQ:
        {
            srv_cca_manager_handle_session_begin_ind(
                        inst,
                        job->src_mod_id,
                        (srv_cca_session_begin_ind_struct*) job->data,
                        SRV_CCA_STATUS_OK);
            srv_cca_job_free_job(job);
        }
        break;
        
        case SRV_CCA_JOB_SESSION_END_IND_REQ:
        {
            srv_cca_manager_handle_session_end_ind(cntx,
                        job->src_mod_id,
                        (srv_cca_session_end_ind_struct*) job->data,
                        SRV_CCA_STATUS_OK);
            srv_cca_job_free_job(job);
        }
        break;
        
#endif /* __SRV_CCA_DM_SESSION__ */

        default:
            SRV_CCA_ASSERT(!"Wrong DM in Msg");
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_set_to_async_context
 * DESCRIPTION
 *  fill job to async context for handling
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_cca_status_enum srv_cca_job_set_to_async_context(srv_cca_inst_struct *inst, srv_cca_job_type_enum type, srv_cca_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == SRV_CCA_JOB_GET_PROF_IND_REQ)
    {
        srv_cca_get_prof_ind_struct *ind;

        ind = (srv_cca_get_prof_ind_struct*) job->data;
        inst->src_mod_id = job->src_mod_id;
        inst->sim_id = ind->sim_id;
        inst->appId = ind->app_id;
        inst->profId = ind->prof_id;
        inst->oper = SRV_CCA_OPER_GET;
    }
    else if (type == SRV_CCA_JOB_UPDATE_PROF_IND_REQ)
    {
        srv_cca_update_prof_ind_struct *ind;

        ind = (srv_cca_update_prof_ind_struct*) job->data;
        inst->src_mod_id = job->src_mod_id;
        inst->sim_id = ind->sim_id;
        inst->appId = ind->app_id;
        inst->profId = ind->prof_id;
        inst->asynchConfig = ind->hConfig;
        inst->oper = SRV_CCA_OPER_UPDATE;
    }
    else
    {
        SRV_CCA_ASSERT(0);
    }

    return SRV_CCA_STATUS_OK;
}


#ifdef __SRV_CCA_DM_SESSION__
/*****************************************************************************
 * FUNCTION
 *  srv_cca_session_begin_ind_hdlr
 * DESCRIPTION
 *  MSG_SRV_CCA_SESSION_BEGIN_IND handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_session_begin_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_job_struct *job;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_cca_job_create_new_job(SRV_CCA_JOB_SESSION_BEGIN_IND_REQ, (module_type) mod_id, msg);
    if (!job)
    {
        srv_cca_manager_handle_session_begin_ind(
            inst, 
            (module_type) mod_id,
            (srv_cca_session_begin_ind_struct*) msg,
            SRV_CCA_STATUS_MEMFULL);
        return;
    }

    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_SESSION_BEGIN_IND_REQ, job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_manager_handle_session_begin_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  session_begin_ind       [IN]        
 *  result                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_manager_handle_session_begin_ind(
                srv_cca_inst_struct *inst,
                module_type src_mod_id,
                srv_cca_session_begin_ind_struct *session_begin_ind,
                srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->cca_state == SRV_CCA_STATE_ASYNC)
        return;

    SRV_CCA_ASSERT(inst->cca_state != SRV_CCA_STATE_ASYNC &&
               inst->session_state == SRV_CCA_SESSION_STATE_IDLE);

    inst->session_state = SRV_CCA_SESSION_STATE_BEGIN;
    srv_cca_send_session_begin_rsp(src_mod_id, session_begin_ind, result);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_session_begin_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_SESSION_BEGIN_RSP
 * PARAMETERS
 *  dest_mod_id             [IN]        
 *  session_begin_ind       [IN]        
 *  result                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_session_begin_rsp(
                module_type dest_mod_id,
                srv_cca_session_begin_ind_struct *session_begin_ind,
                srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_session_begin_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = SRV_CCA_NEW_ILM_DATA(srv_cca_session_begin_rsp_struct);

    data->source_id = session_begin_ind->source_id;
    data->sim_id = session_begin_ind->sim_id;
    data->session_id = session_begin_ind->session_id;
    data->session_type = session_begin_ind->session_type;
    data->result = result;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_CCA_SESSION_BEGIN_RSP, (oslParaType*) data, NULL);
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_session_end_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_SESSION_END_IND handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_session_end_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_job_struct *job;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_cca_job_create_new_job(SRV_CCA_JOB_SESSION_END_IND_REQ, (module_type) mod_id, msg);
    if (!job)
    {
        srv_cca_manager_handle_session_end_ind(cntx,
            (module_type) mod_id,
            (srv_cca_session_end_ind_struct*) msg,
            SRV_CCA_STATUS_MEMFULL);
        return;
    }
    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_SESSION_END_IND_REQ, job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_manager_handle_session_end_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  session_end_ind     [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_manager_handle_session_end_ind(
                srv_cca_cntx_struct *cntx,
                module_type src_mod_id,
                srv_cca_session_end_ind_struct *session_end_ind,
                srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CCA_ASSERT(inst->cca_state != SRV_CCA_STATE_ASYNC &&
               inst->session_state == SRV_CCA_SESSION_STATE_BEGIN ||
               inst->cca_state == SRV_CCA_STATE_ASYNC &&
               inst->session_state == SRV_CCA_SESSION_STATE_IN_SESSION);

    inst->session_state = SRV_CCA_SESSION_STATE_IDLE;
    srv_cca_send_session_end_rsp(src_mod_id, session_end_ind, result);
    if (inst->cca_state == SRV_CCA_STATE_ASYNC)
    {
        inst->cca_state = SRV_CCA_STATE_IDLE;
        srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEXT_JOB_REQ, NULL);
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_session_end_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_SESSION_END_RSP
 * PARAMETERS
 *  dest_mod_id         [IN]        
 *  session_end_ind     [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_session_end_rsp(
                module_type dest_mod_id,
                srv_cca_session_end_ind_struct *session_end_ind,
                srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_session_end_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = SRV_CCA_NEW_ILM_DATA(srv_cca_session_end_rsp_struct);

    data->source_id = session_end_ind->source_id;
    data->sim_id = session_end_ind->sim_id;
    data->session_id = session_end_ind->session_id;
    data->session_type = session_end_ind->session_type;
    data->result = result;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_CCA_SESSION_END_RSP, (oslParaType*) data, NULL);
}

#endif /* __SRV_CCA_DM_SESSION__ */










#endif /* __SRV_CCA_PROF_OPER__ */
#endif /* __CCA_SUPPORT__ */




