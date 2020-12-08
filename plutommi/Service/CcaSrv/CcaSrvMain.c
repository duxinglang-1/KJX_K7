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
 *  CentralConfigAgentMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA Main: primitive handlers / memory management / init / deinit
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
 * removed!
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
 * removed!
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




//#ifdef __CCA_SUPPORT__

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMI_include.h"

#include "string.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_public_api.h"

#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"

#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "commonscreens.h"



#ifdef __DM_LAWMO_SUPPORT__
#include "DMSrvGprot.h"
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxSrvGprot.h"
#endif


#include "CcaSrvGProt.h"
#include "CcaSrvIProt.h"
#include "CcaSrvConfig.h"
#include "CcaSrvProt.h"

#ifdef __MMI_CCA_SUPPORT__

/*----------------------------------------------------------------------------*/
/* Macro define                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
/* Job flag on every phase of job processing */
#define CCA_JOB_FLAG_ALREADY_IN_LIST                   0x0001







/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct
{
   U8 job_type;
   U8 job_size;
}srv_cca_job_size_info_struct;

/*----------------------------------------------------------------------------*/
/* Static global variable                                                     */
/*----------------------------------------------------------------------------*/
static const srv_cca_job_size_info_struct g_srv_cca_job_size_info_tbl[] = 
{
    {SRV_CCA_JOB_INVALID_SETTING_IND_REQ, sizeof(srv_cca_src_invalid_setting_ind_struct)},
    {SRV_CCA_JOB_NEW_SETTING_IND_REQ, sizeof(srv_cca_src_new_setting_ind_struct)},

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    {SRV_CCA_JOB_PROCESS_PROV_MSG_REQ, sizeof(srv_cca_process_prov_msg_req_struct)},
#endif

#ifdef __SRV_CCA_PROF_OPER__
    {SRV_CCA_JOB_GET_PROF_IND_REQ, sizeof(srv_cca_get_prof_ind_struct)},
    {SRV_CCA_JOB_UPDATE_PROF_IND_REQ, sizeof(srv_cca_update_prof_ind_struct)},
#ifdef __SRV_CCA_DM_SESSION__
    {SRV_CCA_JOB_SESSION_BEGIN_IND_REQ, sizeof(srv_cca_session_begin_ind_struct)},
    {SRV_CCA_JOB_SESSION_END_IND_REQ, sizeof(srv_cca_session_end_ind_struct)},
#endif /* __SRV_CCA_DM_SESSION__ */
#endif /* __SRV_CCA_PROF_OPER__ */
};


#ifdef __SRV_CCA_SUPPORT_AUTH__
static srv_cca_auth_struct *cca_auth_state_head;
#endif /* __SRV_CCA_SUPPORT_AUTH__ */
srv_cca_cntx_struct  g_srv_cca_cntx;
srv_cca_cntx_struct *srv_cca_cntx_p;



/*----------------------------------------------------------------------------*/
/* Static API declaration                                                     */
/*----------------------------------------------------------------------------*/


/* Protocol event init */
static void srv_cca_cntx_init(void);
static void srv_cca_prov_init(void);
static void srv_cca_pevt_cmn_init(void);
static void srv_cca_pevt_prov_init(void);

/* Others init */
static void srv_cca_init_done(void);

/* Event */
static void srv_cca_emit_recv_invalid_msg_event(srv_cca_inst_struct *inst,
    srv_cca_src_invalid_setting_ind_struct *invalid_msg_ind, MMI_BOOL is_new_msg);

static void srv_cca_emit_recv_new_msg_event(srv_cca_inst_struct *inst, 
    srv_cca_src_new_setting_ind_struct *new_msg_ind);

#ifdef __SRV_CCA_SUPPORT_AUTH__
static void srv_cca_emit_verify_pin_event(srv_cca_inst_struct *inst, srv_cca_auth_struct *auth_info, srv_cca_verify_pin_status_enum status);
#endif /* __SRV_CCA_SUPPORT_AUTH__ */

static void srv_cca_emit_pre_install_event(srv_cca_inst_struct *inst);

static void srv_cca_handle_cancel_new_msg(SRV_CCA_HANDLE h_cca);
static void srv_cca_handle_view_new_msg(SRV_CCA_HANDLE h_cca);
static void srv_cca_handle_start_install(SRV_CCA_HANDLE h_cca, void *action_data, S32 action_data_size);


static MMI_BOOL srv_cca_has_valid_config_result(srv_cca_inst_struct *inst, MMI_BOOL is_post);

/* OMA Prov Primitive handler */
static U8 srv_cca_ready_ind_hdlr(void *msg, int mod_id, void *ilm);
static U8 srv_cca_new_doc_continue_ind_hdlr(void *msg, int mod_id, void *ilm);

static U8 srv_cca_src_invalid_setting_ind_hdlr(void *msg, int mod_id, void *ilm);
static U8 srv_cca_src_new_setting_ind_hdlr(void *msg, int mod_id, void *ilm);
static U8 srv_cca_src_new_setting_rsp_hdlr(void *msg, int mod_id, void *ilm);

#ifdef __SRV_CCA_SUPPORT_AUTH__
static U8 srv_cca_src_auth_ind_hdlr(void *msg, int mod_id, void *ilm);
static U8 srv_cca_src_auth_rsp_hdlr(void *msg, int mod_id, void *ilm);
static srv_cca_auth_struct *srv_cca_alloc_auth_state(srv_cca_auth_struct *auth_state);
static srv_cca_status_enum srv_cca_set_auth_state(
                                srv_cca_auth_struct *auth_state,
                                module_type dest_mod_id,
                                srv_cca_src_auth_ind_struct *auth_ind);
static srv_cca_auth_struct *srv_cca_find_match_auth_state(srv_cca_auth_struct *auth_state);
static srv_cca_auth_struct *srv_cca_detach_auth_state(srv_cca_auth_struct *auth_state);
static void srv_cca_remove_auth_state(srv_cca_auth_struct *auth_state);
#endif /* __SRV_CCA_SUPPORT_AUTH__ */

static U8 srv_cca_src_new_doc_ind_hdlr(void *msg, int mod_id, void *ilm);
static U8 srv_cca_src_new_doc_rsp_hdlr(void *msg, int mod_id, void *ilm);

static U8 srv_cca_app_configure_ind_hdlr(void *msg);
static U8 srv_cca_app_configure_rsp_hdlr(void *msg);

static void srv_cca_send_ready_ind(U16 source_id, srv_cca_status_enum status);
#ifdef __SRV_CCA_SUPPORT_AUTH__
static void srv_cca_send_src_auth_rsp(srv_cca_auth_struct *auth_state, CHAR *pin, srv_cca_status_enum status);
#endif /* __SRV_CCA_SUPPORT_AUTH__ */
/* OMA Prov Utils */
static U8 srv_cca_update_config_result(srv_cca_inst_struct *inst, U16 config_id, srv_cca_status_enum result);
static srv_cca_status_enum srv_cca_get_msg_config_result(srv_cca_inst_struct *inst, srv_cca_status_enum config_result);

/* Job operation */
static U32 srv_cca_job_get_data_size(srv_cca_job_type_enum job_type);

/* Prov Job handler */
static void srv_cca_context_init(void);
static void srv_cca_reset_context(srv_cca_inst_struct *inst);
static void srv_cca_prov_reset_cntx(srv_cca_inst_struct *inst);
static void srv_cca_start_install(srv_cca_cntx_struct *cntx, S32 anyAppInterests);

static srv_cca_status_enum srv_cca_summit_job_to_idle_manager(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job);
static srv_cca_status_enum srv_cca_summit_job_to_provisioning_manager(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job);
static void srv_cca_job_current_provisioning_job_finished(srv_cca_cntx_struct *cntx);
static int srv_cca_is_current_new_setting_invalid(
            srv_cca_src_new_setting_ind_struct *new_setting_ind,
            srv_cca_src_invalid_setting_ind_struct *invalid_setting_ind);

static void srv_cca_provisioninger_handle_invalid_setting_ind(
                srv_cca_cntx_struct *cntx,
                module_type src_mod_id,
                srv_cca_src_invalid_setting_ind_struct *invalid_setting_ind);

static srv_cca_cmp_result_enum srv_cca_job_is_sim_prov(void *src, void *dst);











/*----------------------------------------------------------------------------*/
/* Extern API declaration                                                     */
/*----------------------------------------------------------------------------*/




/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CCA_INIT

/*****************************************************************************
 * FUNCTION
 *  srv_cca_init
 * DESCRIPTION
 *  CCA initialisation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET srv_cca_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_INIT_BEGIN);

    srv_cca_cntx_init();
    srv_cca_mem_init();
    
    srv_cca_prov_init();


#ifdef __SRV_CCA_SPA__    
    srv_cca_spa_init();
#endif 
    
#ifdef __SRV_CCA_PROF_OPER__
    srv_cca_dm_init();
#endif
    
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    srv_cca_provbox_init();
#endif 

    srv_cca_init_done();

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_INIT_END);
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_cntx_p = &g_srv_cca_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_cca_cntx_struct *srv_cca_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_cca_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_cca_inst_struct *srv_cca_get_inst(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CCA_ASSERT(cntx);
    return &(cntx->inst_tbl[0]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_cca_inst_struct *srv_cca_get_def_inst(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SRV_CCA_ASSERT(cntx);
    return &(cntx->inst_tbl[0]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_prov_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_prov_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_pevt_cmn_init();
    srv_cca_pevt_prov_init();
    srv_cca_context_init();
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_pevt_cmn_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_pevt_cmn_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_CCA_READY_IND,
        (PsIntFuncPtr) srv_cca_ready_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_NEW_DOC_CONTINUE_IND,
        (PsIntFuncPtr) srv_cca_new_doc_continue_ind_hdlr,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_pevt_prov_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_pevt_prov_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_INVALID_SETTING_IND,
        (PsIntFuncPtr) srv_cca_src_invalid_setting_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_NEW_SETTING_IND,
        (PsIntFuncPtr) srv_cca_src_new_setting_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP,
        (PsIntFuncPtr) srv_cca_src_new_setting_rsp_hdlr,
        MMI_FALSE);

#ifdef __SRV_CCA_SUPPORT_AUTH__
    /* Authentication verification */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_AUTH_IND,
        (PsIntFuncPtr) srv_cca_src_auth_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_AUTH_RSP,
        (PsIntFuncPtr) srv_cca_src_auth_rsp_hdlr,
        MMI_FALSE);
#endif /* __SRV_CCA_SUPPORT_AUTH__ */

    /* CCA new document handling */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_NEW_DOC_IND,
        (PsIntFuncPtr) srv_cca_src_new_doc_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_SRC_NEW_DOC_RSP,
        (PsIntFuncPtr) srv_cca_src_new_doc_rsp_hdlr,
        MMI_FALSE);

    /* App configuration */
    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_APP_CONFIGURE_IND,
        (PsIntFuncPtr) srv_cca_app_configure_ind_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_SRV_CCA_APP_CONFIGURE_RSP,
        (PsIntFuncPtr) srv_cca_app_configure_rsp_hdlr,
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_init_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_init_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_def_inst();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* tempe to hardcode it for no more requirment in long time from now */
    srv_cca_send_ready_ind(SRV_CCA_SOURCE_SPA, SRV_CCA_STATUS_CCA_READY);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_cca_status_enum srv_cca_set_event_proc(SRV_CCA_HANDLE h_cca, mmi_proc_func evt_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_def_inst();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    inst->evt_proc = evt_proc;
    inst->user_data = user_data;
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cca_emit_notify_event(srv_cca_inst_struct *inst, srv_cca_notify_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_evt_notify_struct  evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CCA_NOTIFY);
    evt.h_cca = (SRV_CCA_HANDLE)inst;
    evt.type = type;

    MMI_FRM_SEND_EVENT(&evt, inst->evt_proc, inst->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cca_emit_recv_invalid_msg_event(srv_cca_inst_struct *inst,
    srv_cca_src_invalid_setting_ind_struct *invalid_msg_ind, MMI_BOOL is_new_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_evt_recv_invalid_msg_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CCA_RECV_INVALID_MSG);
    evt.h_cca = (SRV_CCA_HANDLE)inst;
    evt.status = invalid_msg_ind->status;
    evt.is_new_msg = is_new_msg;

    MMI_FRM_SEND_EVENT(&evt, inst->evt_proc, inst->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cca_emit_recv_new_msg_event(srv_cca_inst_struct *inst, 
    srv_cca_src_new_setting_ind_struct *new_msg_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_evt_recv_new_msg_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CCA_RECV_NEW_MSG);
    evt.h_cca = (SRV_CCA_HANDLE)inst;
    evt.is_msg_from_box = MMI_FALSE;
    evt.sim_id = (mmi_sim_enum)new_msg_ind->sim_id;

    MMI_FRM_SEND_EVENT(&evt, inst->evt_proc, inst->user_data);
}

#ifdef __SRV_CCA_SUPPORT_AUTH__
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cca_emit_verify_pin_event(srv_cca_inst_struct *inst,
    srv_cca_auth_struct *auth_info, srv_cca_verify_pin_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_evt_verify_pin_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CCA_VERIFY_PIN);
    evt.h_cca = (SRV_CCA_HANDLE)inst;
#ifdef __MMI_PROV_MESSAGE_SUPPORT__    
    evt.is_msg_from_box = inst->msg_info_cnf == NULL ? MMI_FALSE : MMI_TRUE;
#else
    evt.is_msg_from_box = MMI_FALSE;
#endif
    evt.max_attempts = auth_info->maxAttempts;
    evt.cur_attempt = auth_info->count + 1;
    evt.status = status;

    MMI_FRM_SEND_EVENT(&evt, inst->evt_proc, inst->user_data);
}
#endif /* __SRV_CCA_SUPPORT_AUTH__ */


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cca_emit_pre_install_event(srv_cca_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_evt_pre_install_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CCA_PRE_INSTALL);
    evt.h_cca = (SRV_CCA_HANDLE)inst;
#ifdef __MMI_PROV_MESSAGE_SUPPORT__    
        evt.is_msg_from_box = inst->msg_info_cnf == NULL ? MMI_FALSE : MMI_TRUE;
#else
        evt.is_msg_from_box = MMI_FALSE;
#endif

    if (srv_cca_has_valid_config_result(inst, MMI_FALSE))
        evt.has_config_result = MMI_FALSE;
    else
        evt.has_config_result = MMI_TRUE;
    
    evt.config_num = inst->numApp;
    evt.msg_config_result = inst->msg_config_result;
    if (inst->cca_state == SRV_CCA_STATE_PROCESS_MSG)
        evt.is_msg_from_box = MMI_TRUE;
    else
        evt.is_msg_from_box = MMI_FALSE;
    memcpy(&evt.app_config_result, inst->configResult, 
        sizeof(srv_cca_app_config_result_struct) * SRV_CCA_MAX_APPS);

    MMI_FRM_SEND_EVENT(&evt, inst->evt_proc, inst->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cca_emit_post_install_event(srv_cca_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_evt_post_install_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CCA_POST_INSTALL);
    evt.h_cca = (SRV_CCA_HANDLE)inst;
    evt.config_num = inst->numApp;
    evt.msg_config_result = inst->msg_config_result;
    memcpy(&evt.app_config_result, inst->configResult, 
        sizeof(srv_cca_app_config_result_struct) * SRV_CCA_MAX_APPS);

    MMI_FRM_SEND_EVENT(&evt, inst->evt_proc, inst->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cca_emit_install_finished_event(srv_cca_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_evt_install_finished_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CCA_INSTALL_FINISHED);
    evt.h_cca = (SRV_CCA_HANDLE)inst;
    if (inst->cca_state == SRV_CCA_STATE_PROCESS_MSG)
        evt.is_msg_from_box = MMI_TRUE;
    else
        evt.is_msg_from_box = MMI_FALSE;
    MMI_FRM_SEND_EVENT(&evt, inst->evt_proc, inst->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_cca_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_cca_is_inst_busy((SRV_CCA_HANDLE)srv_cca_get_def_inst());
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_cca_is_inst_busy(SRV_CCA_HANDLE h_inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if has SIM prov job in queue */
    if (srv_cca_slist_get_node_by_data((srv_cca_slist_struct *)cntx->job_list, srv_cca_job_is_sim_prov, NULL))
    {
        MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_JOB_CENTER_HAS_NEXT_JOB_HAS_SIM_PROV);
        return MMI_TRUE;
    }
    if (inst->cca_state != SRV_CCA_STATE_IDLE)
        return MMI_TRUE;

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_cca_get_unread_msg_num(U32 *sim_num_list, U32 sim_num, mmi_sim_enum *first_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    U32 is_first = 0;
    U32 total_num = 0;
    srv_cca_cntx_struct *cntx;
    srv_cca_job_struct *job;
    srv_cca_src_new_setting_ind_struct *new_msg_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_num_list && sim_num > 0)
    {
        for (i = 0; i < sim_num; i++)
            sim_num_list[i] = 0;
    }
    cntx = srv_cca_get_cntx();
    job = cntx->job_list;

    while (job)
    {
        if (job->type == SRV_CCA_JOB_NEW_SETTING_IND_REQ)
        {
       		total_num++;
            new_msg_ind = (srv_cca_src_new_setting_ind_struct*)job->data;
    
            if (!is_first && first_sim_id)
            {
                is_first = 1;
                *first_sim_id = (mmi_sim_enum)new_msg_ind->sim_id;
            }

            /* Temp solution, if it's DEFAULT, treat it as SIM1 */
			if (new_msg_ind->sim_id == MMI_SIM_NONE)
			{
                job = job->next;
				continue;
			}

            if (sim_num_list)
            {
                for (j = 0; j < sim_num; j++)
                {
                    if (SRV_CCA_IDX2BIT(j) == new_msg_ind->sim_id)
                    {
                        sim_num_list[j]++;
                        break;
                    }
                }
            }

        }
        job = job->next;    
    }
    return total_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_has_valid_config_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *                 
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_cca_has_valid_config_result(srv_cca_inst_struct *inst, MMI_BOOL is_post)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    int i;
    srv_provbox_get_msg_info_cnf_struct *cnf_data;
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_post == MMI_TRUE) /* check if show summary report. */
        return MMI_FALSE;
    
    if (inst->msg_config_result == SRV_CCA_STATUS_SETTING_NOT_INSTALLED)
        return MMI_TRUE;

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
        
    cnf_data = (srv_provbox_get_msg_info_cnf_struct*) inst->msg_info_cnf;
    if (cnf_data == NULL)
        return MMI_TRUE;
    /*
    if (inst->msg_config_result != CCA_STATUS_SETTING_SKIPPED)
        return MMI_TRUE;
    */

    if (cnf_data->msg_config_status.config_status != SRV_PROVBOX_CONFIG_STATUS_SKIPPED)
        return MMI_FALSE;
        
    for (i = 0; i < cnf_data->msg_config_status.app_num; i++)
    {
        if (cnf_data->msg_config_status.app_config_status[i].status != SRV_PROVBOX_CONFIG_STATUS_SKIPPED)
            break;
    }
    if (i == cnf_data->msg_config_status.app_num) /* all app are skipped */
        return MMI_TRUE;

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_apply_action(SRV_CCA_HANDLE h_cca, srv_cca_action_type_enum action_type, void *action_data, S32 action_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(action_type)
    {
        case SRV_CCA_ACTION_TYPE_CANCEL_NEW_MSG:
            srv_cca_handle_cancel_new_msg(h_cca);
            break;

        case SRV_CCA_ACTION_TYPE_VIEW_NEW_MSG:
            srv_cca_handle_view_new_msg(h_cca);
            break;
            
#ifdef __SRV_CCA_SUPPORT_AUTH__
        case SRV_CCA_ACTION_TYPE_PIN_INPUT:
            srv_cca_handle_auth_input((WCHAR*)action_data);
            break;
            
        case SRV_CCA_ACTION_TYPE_PIN_ABORT:
            srv_cca_handle_auth_fail();
            break;
#endif /* __SRV_CCA_SUPPORT_AUTH__ */

        case SRV_CCA_ACTION_TYPE_START_INSTALL:
            srv_cca_handle_start_install(h_cca, action_data, action_data_size);
            break;

        case SRV_CCA_ACTION_TYPE_INSTALL_COMPLETE:
            srv_cca_configure_complete(srv_cca_get_cntx());
            break;
        
        default:
            break;
    }
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cca_handle_cancel_new_msg(SRV_CCA_HANDLE h_cca)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_CANCEL_NEW_MSG, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cca_handle_view_new_msg(SRV_CCA_HANDLE h_cca)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_VIEW_NEW_MSG, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cca_handle_start_install(SRV_CCA_HANDLE h_cca, void *action_data, S32 action_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_def_inst();
    srv_cca_act_para_start_install_struct  *act_para = (srv_cca_act_para_start_install_struct*)action_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    inst->has_selected = act_para->has_selected;
    inst->sel_cfg_num = act_para->sel_config_num;
    memcpy(&inst->sel_cfg_ids, &act_para->sel_config_ids, SRV_CCA_MAX_APPS);
    
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    srv_cca_preprocess_config_result(srv_cca_get_def_inst());
#endif 
    srv_cca_oma_new_doc_continue(srv_cca_get_cntx());
}
    
#define SRV_CCA_PROV_MSG

/*****************************************************************************
 * FUNCTION
 *  srv_cca_ready_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 *  mod_id          [IN]        
 *  ilm             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_ready_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_dispatch_ready_ind((srv_cca_ready_ind_struct*) msg);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_new_doc_continue_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_NEW_DOC_CONTINUE_IND handler
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_new_doc_continue_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx(); 
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__
    
        SRV_CCA_ASSERT(inst->specId == SRV_CCA_SPEC_OMA);
        srv_cca_oma_new_doc_continue(cntx);
       
        return MMI_RET_OK;
    
#else /* __SRV_CCA_SLIM__ */
        

    switch (inst->specId)
    {
        case SRV_CCA_SPEC_OMA:
            srv_cca_oma_new_doc_continue(cntx);
            break;

        default:
            break;
    }
    return MMI_RET_OK;

#endif /* __SRV_CCA_SLIM__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_src_invalid_setting_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_SRC_INVALID_SETTING_IND handler
 *  This can be used in all scenario, no matter support ProvBox or not.
 *
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_src_invalid_setting_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_job_struct *job;
    MMI_BOOL is_new_msg = MMI_TRUE;
    srv_cca_src_invalid_setting_ind_struct *data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    data = (srv_cca_src_invalid_setting_ind_struct*) msg;

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_SOURCE_UI_INVALID_SETTING_IND_HDLR,
        data->source_id,
        data->prov_type,
        data->sim_id,
        data->trans_id,
        data->status);

    /* Show invalid setting notification popup */
    if (inst->cca_state == SRV_CCA_STATE_IDLE || inst->cca_state == SRV_CCA_STATE_ASYNC)
    {
        srv_cca_emit_recv_invalid_msg_event(inst, data, MMI_TRUE);
        return MMI_RET_OK;
    }
    else /* PROV state */
    {
        if (cntx->curr_job && 
            mod_id == cntx->curr_job->src_mod_id &&
            srv_cca_is_current_new_setting_invalid(
                    (srv_cca_src_new_setting_ind_struct*)(cntx->curr_job->data), data))
        {
            is_new_msg = MMI_FALSE;
        }
        srv_cca_emit_recv_invalid_msg_event(inst, data, is_new_msg);
    }    

    job = srv_cca_job_create_new_job(SRV_CCA_JOB_INVALID_SETTING_IND_REQ, (module_type) mod_id, (void*)data);
    if (!job)//error in prov_msg status.
    {
        srv_cca_provisioninger_handle_invalid_setting_ind(cntx,
            (module_type) mod_id,
            (srv_cca_src_invalid_setting_ind_struct*) data);
        return MMI_RET_OK;
    }
    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_INVALID_SETTING_IND_REQ, job);

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_src_new_setting_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_SRC_NEW_SETTING_IND handler
 *  This can be used in all scenario as SIM Provisioning may first installed before
 *  save to ProvBox.
 *  1. Need to show notification via NMGR if in foreground,
 *  2. Save to job list
 *  3. If background, need to install it immediately.
 *
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_src_new_setting_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_job_struct *job;
    srv_cca_src_new_setting_ind_struct *data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_src_new_setting_ind_struct*) msg;

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_SOURCE_UI_NEW_SETTING_IND_HDLR,
        data->source_id,
        data->prov_type,
        data->sim_id,
        data->trans_id,
        data->spec_id);


    /* Add to job list */
    job = srv_cca_job_create_new_job(SRV_CCA_JOB_NEW_SETTING_IND_REQ, (module_type) mod_id, msg);
    if (!job)
    {
        srv_cca_send_src_new_setting_rsp((module_type)mod_id, data, SRV_CCA_STATUS_MEMFULL);
        
        srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_MEM_FULL);//After split
        
        return MMI_RET_OK;
    }

    /* Link to job list */
    cntx->job_list = 
        (srv_cca_job_struct*) srv_cca_slist_add_tail(
        (srv_cca_slist_struct *)cntx->job_list, (srv_cca_slist_struct *)job);


    /* If it's SIM provisioning, try to install it, else do nothing as it's triggled by end user via NMGR */
    if (data->prov_type == SRV_CCA_PROV_TYPE_SIM_PROV)
    	srv_cca_job_center_scheduler(cntx, job->type, job);

	    /* Check if can notify NMGR for friendly notification */
    if (data->prov_type == SRV_CCA_PROV_TYPE_OTA_PROV)
        srv_cca_emit_recv_new_msg_event(inst, data);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_src_new_setting_rsp_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_src_new_setting_rsp_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_dispatch_src_new_setting_rsp((srv_cca_src_new_setting_rsp_struct*) msg);
    return MMI_RET_OK;
}

#ifdef __SRV_CCA_SUPPORT_AUTH__
/*****************************************************************************
 * FUNCTION
 *  srv_cca_src_auth_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_SRC_AUTH_IND handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_src_auth_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_auth_ind_struct *data;
    srv_cca_auth_struct *authstate;
    srv_cca_auth_struct newstate;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx(); 
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_src_auth_ind_struct*) msg;

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_SOURCE_UI_AUTH_IND_HDLR,
        data->source_id,
        data->prov_type,
        data->trans_id,
        data->spec_id,
        data->max_attempts,
        data->status);

    srv_cca_set_auth_state(&newstate, (module_type)mod_id, data);
    authstate = srv_cca_find_match_auth_state(&newstate);

    /* configuration source requested to abort authentication input, no signal sent to source */
    if (!authstate)
    {
        srv_cca_emit_verify_pin_event(inst, &newstate, SRV_CCA_VERIFY_PIN_STATUS_MEM_FULL);
        srv_cca_send_src_auth_rsp(&newstate, 0, SRV_CCA_STATUS_MEMFULL);      /* should use newstate here. */
        srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEW_SETTING_RSP_FEEDBACK, 0);
        return MMI_RET_OK;
    }
    
    if (data->status == SRV_CCA_STATUS_ABORT)
    {
        srv_cca_emit_verify_pin_event(inst, authstate, SRV_CCA_VERIFY_PIN_STATUS_ABORT);
        srv_cca_remove_auth_state(authstate);
        srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEW_SETTING_RSP_FEEDBACK, 0);
        return MMI_RET_OK;
    }

    /* ,already input PIN, authentication succeeded, release auth state */
    if (authstate->count > 0 && data->status == SRV_CCA_STATUS_OK)
    {
        srv_cca_emit_verify_pin_event(inst, authstate, SRV_CCA_VERIFY_PIN_STATUS_PASS);

        srv_cca_remove_auth_state(authstate);

    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        srv_cca_provbox_handle_pin_ok();
    #endif
    
        return MMI_RET_OK;
    }

    /* no more retries, show popup, release auth state */
    if (inst->cca_state != SRV_CCA_STATE_PROCESS_MSG &&
        authstate->maxAttempts && 
        authstate->count >= authstate->maxAttempts &&
        data->status == SRV_CCA_STATUS_FAIL)
    {
        srv_cca_emit_verify_pin_event(inst, authstate, SRV_CCA_VERIFY_PIN_STATUS_FAIL); //after split

        srv_cca_send_src_auth_rsp(authstate, 0, SRV_CCA_STATUS_ABORT);
        srv_cca_remove_auth_state(authstate);

        srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEW_SETTING_RSP_FEEDBACK, 0);
        return MMI_RET_OK;
    }


    /* retry attempts */
    if (authstate->count > 0 && data->status == SRV_CCA_STATUS_FAIL)
    {
        srv_cca_emit_verify_pin_event(inst, authstate, SRV_CCA_VERIFY_PIN_STATUS_RETRY);

        return MMI_RET_OK;
    }

    srv_cca_emit_verify_pin_event(inst, authstate, SRV_CCA_VERIFY_PIN_STATUS_REQ);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_src_auth_rsp_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_src_auth_rsp_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_dispatch_src_auth_rsp((srv_cca_src_auth_rsp_struct*) msg);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_handle_auth_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_handle_auth_input(WCHAR *w_pin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_pin[SRV_CCA_MAX_PIN_CHARS + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CCA_ASSERT(cca_auth_state_head);

    cca_auth_state_head->count++;

    mmi_ucs2_to_asc((CHAR*) asc_pin, (CHAR*) w_pin);

    srv_cca_send_src_auth_rsp(cca_auth_state_head, (CHAR*) asc_pin, SRV_CCA_STATUS_OK);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_handle_auth_fail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_handle_auth_fail(void)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx(); 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cca_auth_state_head)
    {
        srv_cca_send_src_auth_rsp(cca_auth_state_head, 0, SRV_CCA_STATUS_ABORT);
        srv_cca_remove_auth_state(cca_auth_state_head);

        srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_AUTH_ABORT, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_alloc_auth_state
 * DESCRIPTION
 *  set the auth state
 * PARAMETERS
 *  auth_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static srv_cca_auth_struct *srv_cca_alloc_auth_state(srv_cca_auth_struct *auth_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_auth_struct *crtstate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (auth_state == NULL)
        return NULL;

    crtstate = srv_cca_malloc_type(srv_cca_auth_struct);
    if (!crtstate)
        return NULL;
    
#ifdef __SRV_CCA_SLIM__

    memcpy(crtstate, auth_state, sizeof(srv_cca_auth_struct));

#else /* __SRV_CCA_SLIM__ */
    
    
    crtstate->dest_mod_id = auth_state->dest_mod_id;
    crtstate->source_id = auth_state->source_id;
    crtstate->prov_type = auth_state->prov_type;
    crtstate->trans_id = auth_state->trans_id;
    crtstate->maxAttempts = auth_state->maxAttempts;

#endif /* __SRV_CCA_SLIM__ */

    crtstate->count = 0;
    crtstate->next = NULL;
    return crtstate;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_set_auth_state
 * DESCRIPTION
 *  set the auth state
 * PARAMETERS
 *  auth_state      [IN]        
 *  dest_mod_id     [IN]        
 *  auth_ind        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static srv_cca_status_enum srv_cca_set_auth_state(
                    srv_cca_auth_struct *auth_state,
                    module_type dest_mod_id,
                    srv_cca_src_auth_ind_struct *auth_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest_mod_id == MOD_NIL || auth_ind == NULL)
        return SRV_CCA_STATUS_FAIL;

    auth_state->dest_mod_id = dest_mod_id;
    auth_state->source_id = auth_ind->source_id;
    auth_state->prov_type = auth_ind->prov_type;
    auth_state->trans_id = auth_ind->trans_id;
    auth_state->maxAttempts = auth_ind->max_attempts;
    auth_state->count = 0;
    auth_state->next = NULL;
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_find_match_auth_state
 * DESCRIPTION
 *  return the auth state with matching trans_id, or create and add a new auth state struct to list
 *  the matched (or created) auth state object will be moved to first in list
 * PARAMETERS
 *  auth_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static srv_cca_auth_struct *srv_cca_find_match_auth_state(srv_cca_auth_struct *auth_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_auth_struct *crtstate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    crtstate = srv_cca_detach_auth_state(auth_state);

    if (!crtstate)
    {
        crtstate = srv_cca_alloc_auth_state(auth_state);
    }

    if (!crtstate)
        return NULL;
    crtstate->next = cca_auth_state_head;
    cca_auth_state_head = crtstate;

    return cca_auth_state_head;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_detach_auth_state
 * DESCRIPTION
 *  detach and return auth state of matched
 * PARAMETERS
 *  auth_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static srv_cca_auth_struct *srv_cca_detach_auth_state(srv_cca_auth_struct *auth_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_auth_struct *crtstate;
    srv_cca_auth_struct *prevstate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!auth_state)
        return NULL;
    crtstate = cca_auth_state_head;
    prevstate = 0;
    while (crtstate)
    {
        if (crtstate->dest_mod_id == auth_state->dest_mod_id &&
            crtstate->source_id == auth_state->source_id &&
            crtstate->prov_type == auth_state->prov_type && crtstate->trans_id == auth_state->trans_id)
        {
            if (prevstate)
                prevstate->next = crtstate->next;
            else
                cca_auth_state_head = crtstate->next;
            break;
        }
        prevstate = crtstate;
        crtstate = crtstate->next;
    }
    if (crtstate)
        crtstate->next = 0;
    return crtstate;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_remove_auth_state
 * DESCRIPTION
 *  remove and free the auth state object matching specified trans_id from list
 * PARAMETERS
 *  auth_state      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_remove_auth_state(srv_cca_auth_struct *auth_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_auth_struct *crtstate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((crtstate = srv_cca_detach_auth_state(auth_state)) != 0)
        srv_cca_mfree(crtstate);
}
#endif /* __SRV_CCA_SUPPORT_AUTH__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_src_new_doc_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_SRC_NEW_DOC_IND handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_src_new_doc_ind_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_new_doc_ind_struct *data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx(); 
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_src_new_doc_ind_struct*) msg;

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SOURCE_NEW_DOC_IND_HDLR_CS, data->source_id, data->prov_type, data->sim_id);

    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_SOURCE_NEW_DOC_IND_HDLR_DOC,
        data->spec_id,
        data->sec_type,
        data->hConfig,
        data->prov_flag);

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    /* if handle in ProvBox mode, just return */
    if (srv_cca_provbox_src_new_doc_ind_hdlr(mod_id, data))
        return MMI_RET_OK;
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

    /* if not read it from ProvBox, handle it as usual */
    SRV_CCA_ASSERT(inst->cca_state == SRV_CCA_STATE_PROV);

    if (data->hConfig == 0)
    {
        if (data->prov_type == SRV_CCA_PROV_TYPE_OTA_PROV)
        {
            /* OTA provisioning must provide the CCA document */
            srv_cca_send_src_new_doc_rsp(
                (module_type) mod_id,
                data->source_id,
                data->prov_type,
                data->sim_id,
                data->spec_id,
                inst->configResult,
                inst->numApp,
                inst->msg_config_result,
                SRV_CCA_STATUS_FAIL);

            srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_INVALID_SETTING);

            srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEW_DOC_RSP_FEEDBACK, NULL);
        }
#ifdef __SRV_CCA_SPA__        
        else if (data->prov_type == SRV_CCA_PROV_TYPE_SIM_PROV)
        {
            srv_cca_handle_src_sim_profile_status(cntx, msg, mod_id, ilm);
        }
#endif /* __SRV_CCA_SPA__ */        
        else
        {
            SRV_CCA_ASSERT(0);
            return MMI_RET_OK;
        }
        return MMI_RET_OK;
    }

    /* fill provisioning context */
    inst->prs_mod_id = (module_type) mod_id;
    inst->source_id = data->source_id;
    inst->prov_type = data->prov_type;
    inst->sim_id = data->sim_id;
    inst->specId = data->spec_id;
    inst->hConfig = data->hConfig;
    if (data->prov_type == SRV_CCA_PROV_TYPE_OTA_PROV)
    {
        if (data->sec_type == SRV_CCA_SEC_TYPE_USERNETWIN)
            inst->prov_flag |= SRV_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE;
    }
    else if (data->prov_type == SRV_CCA_PROV_TYPE_SIM_PROV)
    {
        inst->prov_flag = data->prov_flag;
    }

    inst->crtConfigIndex = 0;
    memset(inst->configResult, 0, SRV_CCA_MAX_APPS * sizeof(srv_cca_app_config_result_struct));
    inst->numApp = 0;

    if (inst->state != SRV_CCA_STATE_IDLE)
    {
        MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SOURCE_NEW_DOC_IND_HDLR_BUSY, inst->state);
        return MMI_RET_OK; 
    }

    srv_cca_start_provisioning_job(cntx);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_src_new_doc_rsp_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP handler
 * PARAMETERS
 *  msg         [IN]        
 *  mod_id      [IN]        
 *  ilm         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_src_new_doc_rsp_hdlr(void *msg, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_dispatch_src_new_doc_rsp((srv_cca_src_new_doc_rsp_struct*) msg);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_app_configure_ind_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_APP_CONFIGURE_IND handler
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_app_configure_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_dispatch_app_configure_ind((srv_cca_app_configure_ind_struct*) msg);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_app_configure_rsp_hdlr
 * DESCRIPTION
 *  MSG_ID_SRV_CCA_APP_CONFIGURE_RSP handler
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_cca_app_configure_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ret;
    U8 endKeyPressed = 0;
    srv_cca_app_configure_rsp_struct *data;
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx(); 
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_app_configure_rsp_struct*) msg;

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_APP_CONFIG_RSP_HDLR, data->sim_id, data->config_id, data->hConfig, data->status);

    /* SRV_CCA_LOG_DOC(data->hConfig); */

    if (data->status == SRV_CCA_STATUS_ENDKEY_SETTING_INSTALLED)
    {
        endKeyPressed  = 1;
        data->status = SRV_CCA_STATUS_OK;
    }
    else if (data->status == SRV_CCA_STATUS_ENDKEY_SETTING_UPDATED)
    {
        endKeyPressed  = 1;
        data->status = SRV_CCA_STATUS_SETTING_UPDATED;
    }
    else if (data->status == SRV_CCA_STATUS_ENDKEY_SETTING_SKIPPED)
    {
        endKeyPressed  = 1;
        data->status = SRV_CCA_STATUS_SETTING_SKIPPED;
    }
    else if (data->status == SRV_CCA_STATUS_ENDKEY_INVALID_SETTING)
    {
        endKeyPressed  = 1;
        data->status = SRV_CCA_STATUS_INVALID_SETTING;
    }
    switch (data->status)
    {
        case SRV_CCA_STATUS_OK:
		case SRV_CCA_STATUS_FAIL:
        case SRV_CCA_STATUS_INVALID_SETTING:
        case SRV_CCA_STATUS_SETTING_SKIPPED:
        case SRV_CCA_STATUS_SETTING_UPDATED:

            SRV_CCA_ASSERT(inst->numApp > 0 && inst->numApp <= SRV_CCA_MAX_APPS);
            if (srv_cca_oma_is_memfull_during_app_configure() && data->status != SRV_CCA_STATUS_OK)
                data->status = SRV_CCA_STATUS_SETTING_SKIPPED;

            ret = srv_cca_update_config_result(inst, data->config_id, data->status);
            SRV_CCA_ASSERT(ret != 0);

    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
            srv_cca_provbox_app_config_rsp_hdlr(inst, data);
    #endif 

            if (endKeyPressed)
            {
                 srv_cca_configure_complete(cntx);
                 break;
            }
    
            /* switch (data->config_id & 0xFF00) */
            switch (SRV_CCA_GET_SPEC(data->config_id))
            {
                case SRV_CCA_SPEC_OMA:
                    srv_cca_oma_new_doc_process_next_app(cntx);
                    break;

                default:
                    break;
            }
            break;
        /* Handle DM phone lock*/
        case SRV_CCA_STATUS_ABORT:
        case SRV_CCA_STATUS_ENDKEY_PRESSED:
        case SRV_CCA_STATUS_MEMFULL:
            if (data->status == SRV_CCA_STATUS_MEMFULL)
                srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_MEM_FULL);
            srv_cca_configure_complete(cntx);
            break;

        default:
            MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_APP_CONFIG_RSP_HDLR_DEFAULT_STATUS);
            SRV_CCA_ASSERT(0);
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_ready_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source_id       [IN]        
 *  status          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_send_ready_ind(U16 source_id, srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_ready_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = SRV_CCA_NEW_ILM_DATA(srv_cca_ready_ind_struct);

    data->source_id = source_id;
    data->status = status;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_SRC_CCA_READY_IND, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_new_doc_continue_ind
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_NEW_DOC_CONTINUE_IND
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_send_new_doc_continue_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_NEW_DOC_CONTINUE_IND);

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_NEW_DOC_CONTINUE_IND, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_src_new_setting_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP
 * PARAMETERS
 *  dest_mod_id         [IN]        
 *  new_setting_ind     [IN]        
 *  response            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_send_src_new_setting_rsp(
        module_type dest_mod_id,
        srv_cca_src_new_setting_ind_struct *new_setting_ind,
        srv_cca_status_enum response)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_new_setting_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_SEND_SOURCE_UI_NEW_SETTING_RSP,
        new_setting_ind->source_id,
        new_setting_ind->prov_type,
        new_setting_ind->trans_id,
        new_setting_ind->sim_id,
        response);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_src_new_setting_rsp_struct);
    
    data->source_id = new_setting_ind->source_id;
    data->prov_type = new_setting_ind->prov_type;
    data->sim_id = new_setting_ind->sim_id;
    data->trans_id = new_setting_ind->trans_id;
    data->response = response;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP, (oslParaType*) data, NULL);
}

#ifdef __SRV_CCA_SUPPORT_AUTH__
/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_src_auth_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_SRC_AUTH_RSP
 * PARAMETERS
 *  auth_state      [IN]        
 *  pin             [IN]        
 *  status          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_send_src_auth_rsp(srv_cca_auth_struct *auth_state, CHAR *pin, srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_auth_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = SRV_CCA_NEW_ILM_DATA(srv_cca_src_auth_rsp_struct);

    data->source_id = auth_state->source_id;
    data->prov_type = auth_state->prov_type;
    data->trans_id = auth_state->trans_id;
    data->status = status;
    kal_mem_set(data->pin, 0, SRV_CCA_MAX_PIN_CHARS + 1);
    if (pin)
        strncpy(data->pin, pin, SRV_CCA_MAX_PIN_CHARS);

    mmi_frm_send_ilm(auth_state->dest_mod_id, MSG_ID_SRV_CCA_SRC_AUTH_RSP, (oslParaType*) data, NULL);
}
#endif /* __SRV_CCA_SUPPORT_AUTH__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_src_new_doc_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_NEW_DOC_RSP
 * PARAMETERS
 *  dest_mod_id             [IN]        
 *  source_id               [IN]        
 *  prov_type               [IN]        
 *  sim_id                  [IN]        
 *  spec_id                 [IN]        
 *  config_result           [IN]        
 *  config_num              [IN]        
 *  msg_config_result       [IN]        
 *  status                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_send_src_new_doc_rsp(
        module_type dest_mod_id,
        U16 source_id,
        srv_cca_prov_type_enum prov_type,
        U16 sim_id,
        U16 spec_id,
        srv_cca_app_config_result_struct *config_result,
        S32 config_num,
        srv_cca_status_enum msg_config_result,
        srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    srv_cca_src_new_doc_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_SOURCE_NEW_DOC_RSP, source_id, prov_type, sim_id, spec_id, status);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_src_new_doc_rsp_struct);

    data->source_id = source_id;
    data->prov_type = prov_type;
    data->sim_id = sim_id;
    data->spec_id = spec_id;
    data->status = status;

    for (i = 0; i < SRV_CCA_MAX_APPS; i++)
    {
        data->app_config_result[i].config_id = config_result[i].config_id;
        data->app_config_result[i].result = config_result[i].result;
    }
    data->config_num = (U8) config_num;
    data->msg_config_result = msg_config_result;

    mmi_frm_send_ilm(dest_mod_id, MSG_ID_SRV_CCA_SRC_NEW_DOC_RSP, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_app_configure_ind
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_APP_CONFIGURE_IND
 * PARAMETERS
 *  prov_type       [IN]        
 *  prov_flag       [IN]        
 *  sim_id          [IN]        
 *  config_id       [IN]        
 *  hConfig         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_send_app_configure_ind(
        srv_cca_inst_struct *inst, 
        srv_cca_prov_type_enum prov_type,
        U32 prov_flag,
        U16 sim_id,
        U16 config_id,
        S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_configure_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_APP_CONFIG_IND, config_id, hConfig, inst->crtConfigIndex);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_app_configure_ind_struct);

    data->prov_type = prov_type;
    data->prov_flag = prov_flag;
    data->sim_id = sim_id;
    data->config_id = config_id;
    data->hConfig = hConfig;

    ((srv_cca_document_struct*) hConfig)->config_id = config_id;
    ((srv_cca_document_struct*) hConfig)->dtAcctIDAdded = 0;

    kal_mem_set(data->l1symbols, 0, SRV_CCA_TREE_MAX_CHILDS * sizeof(U16));
    kal_mem_set(data->l1symbols_count, 0, SRV_CCA_TREE_MAX_CHILDS * sizeof(U16));
    srv_cca_oma_construct_l1symbols(
        hConfig,
        SRV_CCA_TREE_MAX_CHILDS,
        &(data->num_symbols),
        data->l1symbols,
        data->l1symbols_count);

    mmi_frm_send_ilm(srv_cca_get_module_id_by_config(config_id),
                     MSG_ID_SRV_CCA_APP_CONFIGURE_IND, (oslParaType*) data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_send_cca_app_configure_rsp
 * DESCRIPTION
 *  send MSG_ID_SRV_CCA_APP_CONFIGURE_RSP
 * PARAMETERS
 *  sim_id      [IN]        
 *  conf_id     [IN]        
 *  doc_hdl     [IN]        
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_send_cca_app_configure_rsp(U16 sim_id, U16 conf_id, S32 doc_hdl, srv_cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_app_configure_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_SEND_CCA_APP_CONFIGURE_RSP, sim_id, conf_id, doc_hdl, status);

    data = SRV_CCA_NEW_ILM_DATA(srv_cca_app_configure_rsp_struct);

    data->sim_id = sim_id;
    data->config_id = conf_id;
    data->hConfig = doc_hdl;
    data->status = status;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_SRV_CCA_APP_CONFIGURE_RSP, (oslParaType*) data, NULL);
}


#define SRV_CCA_PROV_JOB

/*****************************************************************************
 * FUNCTION
 *  srv_cca_new_config_result
 * DESCRIPTION
 *  add new config result entry to context
 * PARAMETERS
 *  config_id       [IN]        
 *  result          [IN]        
 * RETURNS
 *  -1      config_id not found
 *  otherwise the index at which entry was added
 *****************************************************************************/
int srv_cca_new_config_result(srv_cca_inst_struct *inst, U16 config_id, srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_NEW_CONFIG_RESULT, config_id, result);

    for (i = 0; i < inst->numApp; i++)
    {
        if (inst->configResult[i].config_id == config_id)
        {
            if (inst->configResult[i].result == SRV_CCA_STATUS_SETTING_NOT_INSTALLED)
                inst->configResult[i].result = result;
            else
            {
                MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_NEW_CONFIG_RESULT_ERROR_EXIST);
                return -1;
            }
        }
    }

    SRV_CCA_ASSERT(inst->numApp < SRV_CCA_MAX_APPS);

    inst->configResult[inst->numApp].result = result;
    inst->configResult[inst->numApp].config_id = config_id;
    inst->numApp++;

    return inst->numApp - 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_new_config_result
 * DESCRIPTION
 *  add new config result entry to context
 * PARAMETERS
 *  config_id       [IN]        
 *  result          [IN]        
 * RETURNS
 *  -1      config_id not found
 *  otherwise the index at which entry was added
 *****************************************************************************/
int srv_cca_delete_config_result(srv_cca_inst_struct *inst, U16 config_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (inst->numApp == 0)
		return inst->numApp;

    for (i = 0; i < inst->numApp; i++)
    {
        if (inst->configResult[i].config_id == config_id)
           break;
    }
	if (i == inst->numApp)
		return inst->numApp;

	for (j = i; j < inst->numApp - 1; j++)
	{
	    inst->configResult[j].result = inst->configResult[j + 1].result;
		inst->configResult[j].config_id = inst->configResult[j + 1].config_id;
	}

    inst->numApp--;
    return inst->numApp;
}

/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_config_result
 * DESCRIPTION
 *  retrieve config result given a config_id
 * PARAMETERS
 *  config_id       [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_NOT_FOUND      config_id not found
 *  otherwise the stored config result
 *****************************************************************************/
srv_cca_status_enum srv_cca_get_config_result(srv_cca_inst_struct *inst, U16 config_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_GET_CONFIG_RESULT, config_id);

    for (i = 0; i < inst->numApp; i++)
        if (inst->configResult[i].config_id == config_id)
            return inst->configResult[i].result;

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_CONFIG_RESULT_ERROR_CONFIG_ID_NOT_FOUND);

    return SRV_CCA_STATUS_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_update_config_result
 * DESCRIPTION
 *  update the config result entry in context
 * PARAMETERS
 *  config_id       [IN]        
 *  result          [IN]        
 * RETURNS
 *  0       config_id not found
 *  1       config result updated
 *****************************************************************************/
static U8 srv_cca_update_config_result(srv_cca_inst_struct *inst, U16 config_id, srv_cca_status_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_UPDATE_CONFIG_RESULT, config_id, result);

    for (i = 0; i < inst->numApp; i++)
    {
        if (inst->configResult[i].config_id == config_id)
        {
            inst->configResult[i].result = result;

            /* one message can only be configured, skipped invalid or failed now. */
            inst->msg_config_result = srv_cca_get_msg_config_result(inst, result);
            return 1;
        }
    }

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_CONFIG_RESULT_ERROR_CONFIG_ID_NOT_FOUND);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_get_msg_config_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  config_result       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static srv_cca_status_enum srv_cca_get_msg_config_result(srv_cca_inst_struct *inst, srv_cca_status_enum config_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum ret = inst->msg_config_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (config_result)
    {
        case SRV_CCA_STATUS_FAIL:
            ret = SRV_CCA_STATUS_FAIL;
            break;
			
        case SRV_CCA_STATUS_UNSUPPORTED_SETTING:
        case SRV_CCA_STATUS_CORRUPTED_SETTING:
            ret = SRV_CCA_STATUS_INVALID_SETTING;
            break;

        case SRV_CCA_STATUS_MISSING_DATA:
            ret = SRV_CCA_STATUS_MISSING_DATA;
            break;

        case SRV_CCA_STATUS_SETTING_NOAPP:
            ret  = SRV_CCA_STATUS_SETTING_NOAPP;
            break;

        case SRV_CCA_STATUS_OK:
        case SRV_CCA_STATUS_SETTING_UPDATED:
            ret  = SRV_CCA_STATUS_OK;
            break;

        case SRV_CCA_STATUS_MEMFULL:
        case SRV_CCA_STATUS_SETTING_SKIPPED:
            if (inst->msg_config_result != SRV_CCA_STATUS_OK)
                ret  = SRV_CCA_STATUS_SETTING_SKIPPED;
            break;

        case SRV_CCA_STATUS_INVALID_SETTING:
            if (inst->msg_config_result != SRV_CCA_STATUS_OK &&
                inst->msg_config_result != SRV_CCA_STATUS_SETTING_SKIPPED)
                ret  = SRV_CCA_STATUS_INVALID_SETTING;
            break;

        default:
            ret  = SRV_CCA_STATUS_SETTING_NOT_INSTALLED;
            break;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_configure_complete
 * DESCRIPTION
 *  reset content + send indication to source
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_configure_complete(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_prov_type_enum prov_type;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_CONFIG_COMPLETE);

    prov_type = inst->prov_type;

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    if (inst->cca_state == SRV_CCA_STATE_PROCESS_MSG)
        prov_type = inst->bak_prov_type;
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

	if (inst->state != SRV_CCA_STATE_IDLE)
	{
		/* send new_doc_res to source */
		srv_cca_send_src_new_doc_rsp(
			inst->prs_mod_id,
			inst->source_id,
			prov_type,
			inst->sim_id,
			inst->specId,
			inst->configResult,
			inst->numApp,
			inst->msg_config_result,
			SRV_CCA_STATUS_OK);

		/* reset provisioning context */
		srv_cca_prov_reset_cntx(inst);
		/* if the end key is pressed on target application UIs, we also call this scheduler with this job type */
		srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEW_DOC_RSP_FEEDBACK, NULL);
		srv_cca_emit_install_finished_event(inst);
	}
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_get_data_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_type            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_cca_job_get_data_size(srv_cca_job_type_enum job_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CCA_ASSERT(job_type < 255);
    
    for (i = 0; i < sizeof(g_srv_cca_job_size_info_tbl)/sizeof(srv_cca_job_size_info_struct); i++)
    {
        if (g_srv_cca_job_size_info_tbl[i].job_type == job_type)
        {
            SRV_CCA_ASSERT(g_srv_cca_job_size_info_tbl[i].job_size < 255);
            return g_srv_cca_job_size_info_tbl[i].job_size;
        }
    }
    
    SRV_CCA_ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_create_new_job
 * DESCRIPTION
 *  create a new job
 * PARAMETERS
 *  type            [IN]        
 *  src_mod_id      [IN]        
 *  data            [IN]        
 * RETURNS
 *  new job pointer
 *****************************************************************************/
srv_cca_job_struct *srv_cca_job_create_new_job(srv_cca_job_type_enum type, module_type src_mod_id, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  data_size;
    srv_cca_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_size = srv_cca_job_get_data_size(type);
    if (!data_size)  /* Invalid job_type */
        return NULL;
    job = srv_cca_malloc_type(srv_cca_job_struct);
    if (!job)
        return NULL;

    job->next = NULL;
    job->job_id = 0; //temp solution
    job->type = type;
    job->src_mod_id = src_mod_id;
    job->flag = 0;
    job->data_size = data_size;

    SRV_CCA_ASSERT(data);
    job->data = srv_cca_malloc(job->data_size);
    if (job->data)
        kal_mem_cpy(job->data, data, job->data_size);
    else
    {
        srv_cca_mfree(job);
        job = 0;
    }
    return job;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_free_job
 * DESCRIPTION
 *  free a job
 * PARAMETERS
 *  job     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_job_free_job(srv_cca_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job == NULL)
        return;
    if (job->data != NULL)
        srv_cca_mfree(job->data);
    srv_cca_mfree(job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_is_sim_prov
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_cca_cmp_result_enum srv_cca_job_is_sim_prov(void *src, void *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_job_struct *job = (srv_cca_job_struct*)src;
    srv_cca_src_new_setting_ind_struct *new_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->type != SRV_CCA_JOB_NEW_SETTING_IND_REQ)
        return SRV_CCA_CMP_RESULT_UNEQUAL;
    new_msg = (srv_cca_src_new_setting_ind_struct*) job->data;
    if (!new_msg || new_msg->prov_type != SRV_CCA_PROV_TYPE_SIM_PROV)
        return SRV_CCA_CMP_RESULT_UNEQUAL;
    return SRV_CCA_CMP_RESULT_EQUAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_context_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_context_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_cntx_struct *cntx = srv_cca_get_cntx();
    srv_cca_inst_struct *inst  = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_reset_context(inst);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_reset_context
 * DESCRIPTION
 *  reset CCA global context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_reset_context(srv_cca_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_RESET_CONTEXT);

    srv_cca_prov_reset_cntx(inst);

#ifdef __SRV_CCA_PROF_OPER__    
    srv_cca_dm_reset_cntx(inst);
    /* temp put here as srv_cca_dm_reset_cntx() is called some more place */
#ifdef __SRV_CCA_DM_SESSION__
    inst->session_state = SRV_CCA_SESSION_STATE_IDLE;
#endif

#endif /* __SRV_CCA_PROF_OPER__ */

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    srv_cca_provbox_reset_cntx(inst);
#endif 

    inst->cca_state = SRV_CCA_STATE_IDLE;
    inst->state = SRV_CCA_STATE_IDLE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_prov_reset_cntx
 * DESCRIPTION
 *  reset provisioning context parameters
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_prov_reset_cntx(srv_cca_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_RESET_PROVISIONING_CONTEXT);

    if (inst->hConfig)
    {
        srv_cca_doc_destroy(inst->hConfig);
        inst->hConfig = 0;
    }
    inst->prs_mod_id = MOD_NIL;
    inst->sim_id = MMI_SIM_NONE;
    inst->specId = 0;
    inst->crtConfigIndex = 0;
    inst->numApp = 0;
    kal_mem_set(inst->configResult, 0, sizeof(srv_cca_app_config_result_struct) * SRV_CCA_MAX_APPS);
    inst->msg_config_result = SRV_CCA_STATUS_SETTING_NOT_INSTALLED;

    inst->state = SRV_CCA_STATE_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_start_provisioning_job
 * DESCRIPTION
 *  execute the provisioning job
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_start_provisioning_job(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 found_app;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_START_PROVISIONING_JOB, inst->state);

    SRV_CCA_ASSERT(inst->hConfig);

    /* No need to change while processing provisioning message from ProvBox */
    inst->state = SRV_CCA_STATE_PROV;
    switch (inst->specId)
    {
        case SRV_CCA_SPEC_OMA:
            found_app = srv_cca_oma_handle_new_doc(cntx, inst->hConfig);
            srv_cca_start_install(cntx, found_app);
            break;

        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_check_app_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_start_install(srv_cca_cntx_struct *cntx, S32 anyAppInterests)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!anyAppInterests)
    {
        srv_cca_emit_notify_event(inst, SRV_CCA_NOTIFY_TYPE_NO_APP_SUPPORT);
        srv_cca_configure_complete(cntx);
    }
    else
    {
        if (inst->cca_state == SRV_CCA_STATE_PROCESS_MSG || inst->prov_type == SRV_CCA_PROV_TYPE_OTA_PROV)
        {
            srv_cca_emit_pre_install_event(inst); 
        }
        else if (inst->prov_type == SRV_CCA_PROV_TYPE_SIM_PROV)
        {
            srv_cca_oma_new_doc_continue(cntx);
        }

        else
        {
            SRV_CCA_ASSERT(0);
        }

    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_center_scheduler
 * DESCRIPTION
 *  call job center to dispatch this new job to current manager in work
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_cca_status_enum srv_cca_job_center_scheduler(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum result = SRV_CCA_STATUS_OK;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_CCA_TRC_INFO,
        TRC_SRV_CCA_JOB_CENTER_SCHEDULER_CENTER_INFO,
        inst->cca_state,
#ifdef __SRV_CCA_DM_SESSION__        
        inst->session_state,
#else
        -1,
#endif
        type,
        cntx->job_list == NULL ? 0 : 1,
        srv_cca_slist_get_node_by_data((srv_cca_slist_struct *)cntx->job_list, srv_cca_job_is_sim_prov, NULL) == NULL ? 0 : 1,
        cntx->curr_job);

    switch (inst->cca_state)
    {
        case SRV_CCA_STATE_IDLE:
            result = srv_cca_summit_job_to_idle_manager(cntx, type, job);
            break;

        case SRV_CCA_STATE_PROV:
            result = srv_cca_summit_job_to_provisioning_manager(cntx, type, job);
       
     break;

#ifdef __SRV_CCA_PROF_OPER__
        case SRV_CCA_STATE_ASYNC:
            result = srv_cca_summit_job_to_async_manager(cntx, type, job);
            break;
#endif /* __SRV_CCA_PROF_OPER__ */

    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case SRV_CCA_STATE_PROCESS_MSG:
            result = srv_cca_submit_job_to_process_msg_manager(cntx, type, job);
            break;
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

        default:
            SRV_CCA_ASSERT(0);
            break;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_summit_job_to_idle_manager
 * DESCRIPTION
 *  summit job to idle manager for handling
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_cca_status_enum srv_cca_summit_job_to_idle_manager(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job)
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
        case SRV_CCA_JOB_NEXT_JOB_REQ:
        {
            srv_cca_src_new_setting_ind_struct *data;
            srv_cca_job_struct *new_job;

            /* check if no job */
            if (cntx->job_list == NULL)
                break;

            SRV_CCA_ASSERT(cntx->curr_job == NULL);

            /* if it's SIM provisioning, handle it immediately */
            new_job = (srv_cca_job_struct*)srv_cca_slist_get_node_by_data(
                        (srv_cca_slist_struct *)cntx->job_list, srv_cca_job_is_sim_prov, NULL);
            if (new_job != NULL)
            {
                cntx->job_list = (srv_cca_job_struct*)
                    srv_cca_slist_remove(
                        (srv_cca_slist_struct *)cntx->job_list, (srv_cca_slist_struct *)new_job);

                MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_JOB_IDLE_MANAGER_NEXT_JOB_FIND_SIM_PROV);

                result = srv_cca_job_center_scheduler(cntx, new_job->type, new_job);
                break;
            }
            data = (srv_cca_src_new_setting_ind_struct*)cntx->job_list->data;
            if (data && data->prov_type == SRV_CCA_PROV_TYPE_OTA_PROV)
            {
                /* In Non-PBox scenario, to check if user press NMGR new message notification so quickly that CCA is still in PROV_STATUS, 
                   NMGR may show notification when CCA is installing SIM Provisioning backgroundly, so it needs to show
                   Progress popup for some little time until CCA is idle again, then check here */
                if (SRV_CCA_CHECK_FLAG(inst->inst_flags, SRV_CCA_INST_FLAG_VIEW_IN_PROV_STATE))
                {
                    SRV_CCA_CLEAR_FLAG(inst->inst_flags, SRV_CCA_INST_FLAG_VIEW_IN_PROV_STATE);
                   
                        cntx->curr_job = job;
                        /* If job is added in list, try to remove it to avoid free twice time */
                        cntx->job_list = (srv_cca_job_struct*)srv_cca_slist_remove(
                                (srv_cca_slist_struct *)cntx->job_list, (srv_cca_slist_struct *)job);

                        inst->cca_state = SRV_CCA_STATE_PROV;
                        srv_cca_send_src_new_setting_rsp(
                                    job->src_mod_id,
                                    (srv_cca_src_new_setting_ind_struct*) job->data,
                                    SRV_CCA_STATUS_OK);
                        break;
                    }
            }


        }
            break;

#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_JOB_INVALID_SETTING_IND_REQ:
            break;
#endif /* __SRV_CCA_SLIM__ */

        case SRV_CCA_JOB_NEW_SETTING_IND_REQ:
        {

#ifdef __SRV_CCA_SPA__            
            /* first to handle the SIM provisioning in the background silently */
            if (((srv_cca_src_new_setting_ind_struct*) job->data)->prov_type == SRV_CCA_PROV_TYPE_SIM_PROV)
            {

                MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_JOB_IDLE_MANAGER_NEW_SETTING_IND_SIM_PROV);

                cntx->curr_job = job;
                /* If job is added in list, try to remove it to avoid free twice time */
                cntx->job_list = (srv_cca_job_struct*)srv_cca_slist_remove(
                        (srv_cca_slist_struct *)cntx->job_list, (srv_cca_slist_struct *)job);

                inst->cca_state = SRV_CCA_STATE_PROV;
                srv_cca_send_src_new_setting_rsp(
                    job->src_mod_id,
                    (srv_cca_src_new_setting_ind_struct*) job->data,
                    SRV_CCA_STATUS_OK);
                break;
            }
#endif /* __SRV_CCA_SPA__ */


        }
            break;

        case SRV_CCA_JOB_CANCEL_NEW_MSG:
        {
            SRV_CCA_ASSERT(!cntx->curr_job);
            cntx->curr_job = (srv_cca_job_struct*)srv_cca_slist_remove_by_index((srv_cca_slist_struct **)&cntx->job_list, 0);
            SRV_CCA_ASSERT(cntx->curr_job && cntx->curr_job->type == SRV_CCA_JOB_NEW_SETTING_IND_REQ);
                
            srv_cca_send_src_new_setting_rsp(cntx->curr_job->src_mod_id, 
                        (srv_cca_src_new_setting_ind_struct*)cntx->curr_job->data, SRV_CCA_STATUS_FAIL);
            srv_cca_job_free_job(cntx->curr_job);
            cntx->curr_job = NULL;

            srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEXT_JOB_REQ, NULL);
        }
            break;
            
        case SRV_CCA_JOB_VIEW_NEW_MSG:
        {
            SRV_CCA_ASSERT(!cntx->curr_job);
            cntx->curr_job = (srv_cca_job_struct*)srv_cca_slist_remove_by_index((srv_cca_slist_struct **)&cntx->job_list, 0);
            SRV_CCA_ASSERT(cntx->curr_job);
            
            srv_cca_send_src_new_setting_rsp(cntx->curr_job->src_mod_id, 
                (srv_cca_src_new_setting_ind_struct*)cntx->curr_job->data, SRV_CCA_STATUS_OK);

            inst->cca_state = SRV_CCA_STATE_PROV;
        }
            break;
            
        case SRV_CCA_JOB_AUTH_ABORT:
            {
                /* user press Endkey on NMGR or cancel it on idle
                   already reset new setting indication context or 
                   provisioning context, scheduler will be called while entering idle screen */
                srv_cca_job_current_provisioning_job_finished(cntx);
            }

            break;

#ifdef __SRV_CCA_PROF_OPER__
        case SRV_CCA_JOB_GET_PROF_IND_REQ:
        case SRV_CCA_JOB_UPDATE_PROF_IND_REQ:
        case SRV_CCA_JOB_SESSION_BEGIN_IND_REQ:
        case SRV_CCA_JOB_SESSION_END_IND_REQ:
            srv_cca_dm_handle_in_idle(cntx, type, job);
        break;
#endif /* __SRV_CCA_PROF_OPER__ */


    #ifdef __MMI_PROV_MESSAGE_SUPPORT__
        case SRV_CCA_JOB_PROCESS_PROV_MSG_REQ:
        case SRV_CCA_JOB_PROCESS_PROV_MSG_CNF:
            srv_cca_provbox_handle_in_idle(cntx, type, job);
            break;
    #endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

        default:
            break;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_summit_job_to_provisioning_manager
 * DESCRIPTION
 *  summit job to provisioning manager for handling
 * PARAMETERS
 *  type        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_cca_status_enum srv_cca_summit_job_to_provisioning_manager(srv_cca_cntx_struct *cntx, srv_cca_job_type_enum type, srv_cca_job_struct *job)
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
            SRV_CCA_ASSERT(0);
        }
            break;
#endif /* __SRV_CCA_SLIM__ */

        case SRV_CCA_JOB_INVALID_SETTING_IND_REQ:
        {
            /*
             *should know the relation between this invalid setting and current setting in handling 
             *if current setting in handling is invalid, we should abort it, or it just means CCA already
             receives another new setting invalid, just show the popup up message.
             */
            SRV_CCA_ASSERT(job != NULL);
            srv_cca_provisioninger_handle_invalid_setting_ind(cntx,
                job->src_mod_id,
                (srv_cca_src_invalid_setting_ind_struct*) job->data);
            srv_cca_job_free_job(job);
        }
            break;

#ifndef __SRV_CCA_SLIM__
        
        case SRV_CCA_JOB_NEW_SETTING_IND_REQ:
            break;
#endif /* __SRV_CCA_SLIM__ */

        case SRV_CCA_JOB_NEW_SETTING_RSP_FEEDBACK:
        case SRV_CCA_JOB_NEW_DOC_RSP_FEEDBACK:
        case SRV_CCA_JOB_SIM_PROFILE_STATUS_FEEDBACK:
        case SRV_CCA_JOB_AUTH_ABORT:
        {
            /* already reset provisioning context */
            srv_cca_job_current_provisioning_job_finished(cntx);
        }
            break;


        /* For SRV_CCA_JOB_VIEW_NEW_MSG:
           To temp solove NMGR not support second notify issue, allow view here, just base on the fact
           the the provisioning state should be stop in a very short async time, progressing popup can cover this case
        */
        case SRV_CCA_JOB_VIEW_NEW_MSG:
            SRV_CCA_SET_FLAG(inst->inst_flags, SRV_CCA_INST_FLAG_VIEW_IN_PROV_STATE);
            break;

#ifndef __SRV_CCA_SLIM__
        case SRV_CCA_JOB_CANCEL_NEW_MSG:
            break;
#endif /* __SRV_CCA_SLIM__ */

#ifdef __SRV_CCA_PROF_OPER__
        case SRV_CCA_JOB_GET_PROF_IND_REQ:
        case SRV_CCA_JOB_UPDATE_PROF_IND_REQ:
        case SRV_CCA_JOB_SESSION_BEGIN_IND_REQ:
        case SRV_CCA_JOB_SESSION_END_IND_REQ:
            srv_cca_dm_handle_in_prov(cntx, type, job);
            break;
#endif /* __SRV_CCA_PROF_OPER__ */

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
            SRV_CCA_ASSERT(0);
        }
            break;

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

        default:
        {
#ifndef __SRV_CCA_SLIM__
            SRV_CCA_ASSERT(0);
#endif /* __SRV_CCA_SLIM__ */

        }
            break;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_job_current_provisioning_job_finished
 * DESCRIPTION
 *  MSG_SRV_CCA_SESSION_BEGIN_IND handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_job_current_provisioning_job_finished(srv_cca_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_job_free_job(cntx->curr_job);
    cntx->curr_job = NULL;
    inst->cca_state = SRV_CCA_STATE_IDLE;

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_JOB_CURRENT_PROVISIONING_JOB_FINISHED);

    srv_cca_job_center_scheduler(cntx, SRV_CCA_JOB_NEXT_JOB_REQ, NULL);
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_is_current_new_setting_invalid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_setting_ind         [IN]        
 *  invalid_setting_ind     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int srv_cca_is_current_new_setting_invalid(
            srv_cca_src_new_setting_ind_struct *new_setting_ind,
            srv_cca_src_invalid_setting_ind_struct *invalid_setting_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!new_setting_ind || !invalid_setting_ind)
    {
        SRV_CCA_ASSERT(new_setting_ind && invalid_setting_ind);
        return 0;
    }
    if (new_setting_ind->source_id != invalid_setting_ind->source_id)
        return 0;
    if (new_setting_ind->sim_id != invalid_setting_ind->sim_id)
        return 0;
    if (new_setting_ind->prov_type != invalid_setting_ind->prov_type)
        return 0;
    if (new_setting_ind->trans_id != invalid_setting_ind->trans_id)
        return 0;
    return 1;
}

//.REVIEW
/*****************************************************************************
 * FUNCTION
 *  srv_cca_provisioninger_handle_invalid_setting_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  invalid_setting_ind     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_provisioninger_handle_invalid_setting_ind(
        srv_cca_cntx_struct *cntx,
        module_type src_mod_id,
        srv_cca_src_invalid_setting_ind_struct *invalid_setting_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_src_new_setting_ind_struct *new_setting_ind;
    srv_cca_inst_struct *inst = srv_cca_get_inst(cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!invalid_setting_ind || inst->cca_state != SRV_CCA_STATE_PROV)
    {
        //to do: not process prov_msg state
        return;
    }
	if (cntx->curr_job)
	{
		new_setting_ind = (srv_cca_src_new_setting_ind_struct*) (cntx->curr_job->data);

		if (src_mod_id == cntx->curr_job->src_mod_id &&
			srv_cca_is_current_new_setting_invalid(new_setting_ind, invalid_setting_ind))
		{
			/* the progressing screen may be showed now */

			MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_JOB_PROVISIONING_MANAGER_INVALID_SETTING_IND);

      //      srv_cca_emit_recv_invalid_msg_event(inst, invalid_setting_ind, MMI_FALSE);
			srv_cca_job_current_provisioning_job_finished(cntx);
		}
        else
        {
     //       srv_cca_emit_recv_invalid_msg_event(inst, invalid_setting_ind, MMI_TRUE);
        }
	}
	else
	{
     //   srv_cca_emit_recv_invalid_msg_event(inst, invalid_setting_ind, MMI_TRUE);

	}
}











#endif /* __CCA_SUPPORT__ */ 




