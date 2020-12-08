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
*  ProvBoxMsgHdlr.c  
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file processes all primitives.
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"

#include "mmi_rp_srv_provbox_def.h"
#include "ProvBoxSrvConfig.h"
#include "ProvBoxSrvProt.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                  */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_PROV_IN_UM__
static void srv_provbox_um_init_msg_reg(void);
#endif

static void srv_provbox_continue_process_job_hdlr(void *local_param, int mod_id, void *ilm);

static void srv_provbox_save_msg_req_hdlr(void *local_param, int mod_id, void *ilm);

static void srv_provbox_get_msg_data_req_hdlr(void *local_param, int mod_id, void *ilm);

//static void srv_provbox_get_msg_num_req_hdlr(void *local_param, int mod_id, void *ilm);

//static void srv_provbox_get_sort_info_req_hdlr(void *local_param, int mod_id, void *ilm);

//static void srv_provbox_get_list_info_by_id_req_hdlr(void *local_param, int mod_id, void *ilm);

//static void srv_provbox_get_list_info_by_index_req_hdlr(void *local_param, int mod_id, void *ilm);

//static void srv_provbox_multi_op_req_hdlr(void *local_param, int mod_id, void *ilm);

//static void srv_provbox_delete_msg_req_hdlr(void *local_param, int mod_id, void *ilm);

//static void srv_provbox_delete_all_msg_req_hdlr(void *local_param, int mod_id, void *ilm);

static void srv_provbox_set_msg_flag_req_hdlr(void *local_param, int mod_id, void *ilm);

static void srv_provbox_get_msg_info_req_hdlr(void *local_param, int mod_id, void *ilm);

static void srv_provbox_update_msg_info_req_hdlr(void *local_param, int mod_id, void *ilm);

static void srv_provbox_send_primtive(oslModuleType dest_mod_id, oslMsgType msg_id, oslParaType *local_para);

/*----------------------------------------------------------------------------*/
/* Extern Function Declaration                                                */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 *
 *       Split of Provbox End
 *
 ****************************************************************************/
#ifdef __MMI_PROV_IN_UM__
static void srv_provbox_um_init_msg_reg(void)
{
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_GET_MSG_NUM_REQ,
        (PsIntFuncPtr) srv_provbox_msg_handle_um_get_msg_num_req,
        MMI_TRUE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_GET_MSG_LIST_REQ,
        (PsIntFuncPtr) srv_provbox_msg_handle_um_get_list_req,
        MMI_TRUE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_GET_MSG_INFO_REQ,
        (PsIntFuncPtr) srv_provbox_msg_handle_um_get_msg_info_req,
        MMI_TRUE);
        
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_TRAVERSE_MSG_REQ,
        (PsIntFuncPtr) srv_provbox_msg_handle_um_traverse_msg_req,
        MMI_TRUE);
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */

    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_DELETE_FOLDER_REQ,
        (PsIntFuncPtr) srv_provbox_msg_handle_um_delete_folder_req,
        MMI_TRUE);
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ,
        (PsIntFuncPtr) srv_provbox_msg_handle_um_multi_op_req,
        MMI_TRUE);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 
}
#endif


/*****************************************************************************
 * FUNCTION
 *    srv_provbox_event_hdlr_init
 * DESCRIPTION
 *    
 * PARAMETERS
 *    void
 * RETURNS
 *    void
 *****************************************************************************/
void srv_provbox_event_hdlr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Primitive for internal usage */
    SetProtocolEventHandler(
        (PsFuncPtr) srv_provbox_continue_process_job_hdlr,
        MSG_ID_MMI_PROVBOX_CONTINUE_PROCESS_JOB_IND);

    /* Primitive for message provider */
    SetProtocolEventHandler((PsFuncPtr) srv_provbox_save_msg_req_hdlr, MSG_ID_MMI_PROVBOX_SAVE_MSG_REQ);

    SetProtocolEventHandler((PsFuncPtr) srv_provbox_get_msg_data_req_hdlr, MSG_ID_MMI_PROVBOX_GET_MSG_DATA_REQ);

    /* Primitive for message shower */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* Primitive for message reader */
    SetProtocolEventHandler((PsFuncPtr) srv_provbox_set_msg_flag_req_hdlr, MSG_ID_MMI_PROVBOX_SET_MSG_FLAG_REQ);

    SetProtocolEventHandler((PsFuncPtr) srv_provbox_get_msg_info_req_hdlr, MSG_ID_MMI_PROVBOX_GET_MSG_INFO_REQ);

    SetProtocolEventHandler((PsFuncPtr) srv_provbox_update_msg_info_req_hdlr, MSG_ID_MMI_PROVBOX_UPDATE_MSG_INFO_REQ);

#ifdef __MMI_PROV_IN_UM__
    srv_provbox_um_init_msg_reg();
#endif
}

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_module_type_by_source_id
 * DESCRIPTION
 *    
 * PARAMETERS
 *    src_id        [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
oslModuleType srv_provbox_get_module_type_by_source_id(srv_provbox_source_id_enum src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    oslModuleType mod_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (src_id)
    {
        case SRV_PROVBOX_SOURCE_ID_TEST:
            mod_id = MOD_MMI;
            break;

        case SRV_PROVBOX_SOURCE_ID_WAP:
            mod_id = MOD_MMI;
            break;

        case SRV_PROVBOX_SOURCE_ID_DM:
            mod_id = MOD_DM;
            break;

        case SRV_PROVBOX_SOURCE_ID_SPA:
            mod_id = MOD_MMI;
            break;

            /* For message consumer */
        case SRV_PROVBOX_SOURCE_ID_PROVBOXUI:
            mod_id = MOD_MMI;
            break;

        case SRV_PROVBOX_SOURCE_ID_CCA:
            mod_id = MOD_MMI;
            break;

        default:
            mod_id = MOD_NIL;
            break;
    }
    return mod_id;
}

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_send_continue_process_job_ind
 * DESCRIPTION
 *    
 * PARAMETERS
 *    dest_mod_id     [IN]        
 *    trans_id        [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
void srv_provbox_send_continue_process_job_ind(int dest_mod_id, U32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_continue_process_job_ind_struct *ind_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_data =
        (srv_provbox_continue_process_job_ind_struct*)
        OslConstructDataPtr(sizeof(srv_provbox_continue_process_job_ind_struct));

    ind_data->trans_id = trans_id;

    srv_provbox_send_primtive(
        (oslModuleType) dest_mod_id,
        MSG_ID_MMI_PROVBOX_CONTINUE_PROCESS_JOB_IND,
        (oslParaType*) ind_data);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_PROV_IN_UM__
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_send_list_info_changed_ind
 * DESCRIPTION
 *    
 * PARAMETERS
 *    dest_mod_id     [IN]        
 *    cmn_info        [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
void srv_provbox_send_list_info_changed_ind(int dest_mod_id, srv_provbox_msg_cmn_info_struct *cmn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_list_info_changed_ind_struct *ind_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_data =
        (srv_provbox_list_info_changed_ind_struct*)
        OslConstructDataPtr(sizeof(srv_provbox_list_info_changed_ind_struct));

    if (cmn_info != NULL)
        memcpy(&ind_data->cmn_info, cmn_info, sizeof(srv_provbox_msg_cmn_info_struct));

    srv_provbox_send_primtive(
        (oslModuleType) dest_mod_id,
        MSG_ID_MMI_PROVBOX_LIST_INFO_CHANGED_IND,
        (oslParaType*) ind_data);
}

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_send_save_msg_available_ind
 * DESCRIPTION
 *    
 * PARAMETERS
 *    dest_mod_id     [IN]        
 *    trans_id        [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
void srv_provbox_send_save_msg_available_ind(int dest_mod_id, U32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_save_msg_available_ind_struct *ind_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_data =
        (srv_provbox_save_msg_available_ind_struct*)
        OslConstructDataPtr(sizeof(srv_provbox_save_msg_available_ind_struct));

    ind_data->trans_id = trans_id;

    srv_provbox_send_primtive(
        (oslModuleType) dest_mod_id,
        MSG_ID_MMI_PROVBOX_SAVE_MSG_AVAILABLE_IND,
        (oslParaType*) ind_data);
}

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_send_save_msg_cnf
 * DESCRIPTION
 *    
 * PARAMETERS
 *    dest_mod_id     [IN]        
 *    req_data        [IN]        
 *    msg_id            [IN]        
 *    result            [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
void srv_provbox_send_save_msg_cnf(
        int dest_mod_id,
        srv_provbox_save_msg_req_struct *req_data,
        U32 msg_id,
        srv_provbox_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_save_msg_cnf_struct *cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data = (srv_provbox_save_msg_cnf_struct*) OslConstructDataPtr(sizeof(srv_provbox_save_msg_cnf_struct));

    cnf_data->trans_id = req_data->trans_id;
    cnf_data->msg_id = req_data->cmn_info.msg_id;
    cnf_data->src_id = req_data->cmn_info.src_id;
    cnf_data->sim_id = req_data->cmn_info.sim_id;
    cnf_data->msg_type = req_data->cmn_info.msg_type;
    cnf_data->app_data = req_data->msg_data.app_data;
    cnf_data->prov_data = req_data->msg_data.prov_data;
    cnf_data->prov_file = req_data->msg_data.prov_file;
    cnf_data->result = result;

    req_data->msg_data.app_data = NULL;
    req_data->msg_data.prov_data = NULL;
    req_data->msg_data.prov_file = NULL;
    srv_provbox_send_primtive((oslModuleType) dest_mod_id, MSG_ID_MMI_PROVBOX_SAVE_MSG_CNF, (oslParaType*) cnf_data);
}

void srv_provbox_send_get_msg_data_cnf(
        int dest_mod_id,
        srv_provbox_get_msg_data_req_struct *req_data,
        U8 sim_id, /*  Gemini_Plus */
        void *app_data,
        S16 app_data_size,
        U16 *filename,
        srv_provbox_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_get_msg_data_cnf_struct *cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data = (srv_provbox_get_msg_data_cnf_struct*) OslConstructDataPtr(sizeof(srv_provbox_get_msg_data_cnf_struct));

    cnf_data->trans_id = req_data->trans_id;
    cnf_data->msg_id = req_data->msg_id;
    cnf_data->src_id = req_data->src_id;
    cnf_data->sim_id = sim_id;
    cnf_data->app_data = app_data;
    cnf_data->app_data_size = app_data_size;
    cnf_data->result = result;

    /* filename can be NULL, and OslConstructDataPtr always to reset the memory. */
    if (filename != NULL)
        srv_provbox_ucs2_copy((CHAR*) cnf_data->filename, SRV_PROVBOX_PATH_MAX_BUFF_SIZE, (const CHAR*)filename);

    srv_provbox_send_primtive(
        (oslModuleType) dest_mod_id,
        MSG_ID_MMI_PROVBOX_GET_MSG_DATA_CNF,
        (oslParaType*) cnf_data);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_send_set_msg_flag_cnf
 * DESCRIPTION
 *    
 * PARAMETERS
 *    dest_mod_id     [IN]        
 *    req_data        [IN]        
 *    result            [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
void srv_provbox_send_set_msg_flag_cnf(
        int dest_mod_id,
        srv_provbox_set_msg_flag_req_struct *req_data,
        srv_provbox_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_set_msg_flag_cnf_struct *cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data = (srv_provbox_set_msg_flag_cnf_struct*) OslConstructDataPtr(sizeof(srv_provbox_set_msg_flag_cnf_struct));

    cnf_data->trans_id = req_data->trans_id;
    cnf_data->msg_id = req_data->msg_id;
    cnf_data->op = req_data->op;
    cnf_data->msg_flag = req_data->msg_flag;
    cnf_data->result = result;

    srv_provbox_send_primtive(
        (oslModuleType) dest_mod_id,
        MSG_ID_MMI_PROVBOX_SET_MSG_FLAG_CNF,
        (oslParaType*) cnf_data);
}

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_send_get_msg_info_cnf
 * DESCRIPTION
 *    
 * PARAMETERS
 *    dest_mod_id             [IN]        
 *    req_data                [IN]        
 *    cmn_info                [IN]        
 *    pin_status                [IN]        
 *    msg_config_status        [IN]        
 *    result                    [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
void srv_provbox_send_get_msg_info_cnf(
        int dest_mod_id,
        srv_provbox_get_msg_info_req_struct *req_data,
        srv_provbox_msg_cmn_info_struct *cmn_info,
        srv_provbox_msg_pin_status_enum pin_status,
        srv_provbox_msg_config_status_struct *msg_config_status,
        srv_provbox_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_get_msg_info_cnf_struct *cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data = (srv_provbox_get_msg_info_cnf_struct*) OslConstructDataPtr(sizeof(srv_provbox_get_msg_info_cnf_struct));

    cnf_data->trans_id = req_data->trans_id;
    if (cmn_info != NULL)
        memcpy(&cnf_data->cmn_info, cmn_info, sizeof(srv_provbox_msg_cmn_info_struct));
    else
        cnf_data->cmn_info.msg_id = req_data->msg_id;

    cnf_data->pin_status = pin_status;

    if (msg_config_status != NULL)
        srv_provbox_msg_copy_msg_config_status(msg_config_status, &cnf_data->msg_config_status);

    cnf_data->result = result;

    srv_provbox_send_primtive(
        (oslModuleType) dest_mod_id,
        MSG_ID_MMI_PROVBOX_GET_MSG_INFO_CNF,
        (oslParaType*) cnf_data);
}

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_send_update_msg_info_cnf
 * DESCRIPTION
 *    
 * PARAMETERS
 *    dest_mod_id     [IN]        
 *    req_data        [IN]        
 *    result            [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
void srv_provbox_send_update_msg_info_cnf(
        int dest_mod_id,
        srv_provbox_update_msg_info_req_struct *req_data,
        srv_provbox_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_update_msg_info_cnf_struct *cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_data =
        (srv_provbox_update_msg_info_cnf_struct*) OslConstructDataPtr(sizeof(srv_provbox_update_msg_info_cnf_struct));

    cnf_data->trans_id = req_data->trans_id;
    cnf_data->msg_id = req_data->msg_id;
    cnf_data->src_id = req_data->src_id;
    cnf_data->result = result;

    srv_provbox_send_primtive(
        (oslModuleType) dest_mod_id,
        MSG_ID_MMI_PROVBOX_UPDATE_MSG_INFO_CNF,
        (oslParaType*) cnf_data);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_continue_process_job_hdlr
 * DESCRIPTION
 *    
 * PARAMETERS
 *    local_param     [IN]        
 *    mod_id            [IN]        
 *    ilm             [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
static void srv_provbox_continue_process_job_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_job_process_current_job(srv_provbox_cntx_get_cntx());
}

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_save_msg_req_hdlr
 * DESCRIPTION
 *    
 * PARAMETERS
 *    local_param     [IN]        
 *    mod_id            [IN]        
 *    ilm             [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
static void srv_provbox_save_msg_req_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_job_submit_new_job(
                srv_provbox_cntx_get_cntx(),
                SRV_PROVBOX_JOB_TYPE_SAVE_MSG,
                SRV_PROVBOX_JOB_SUB_TYPE_NONE,
                mod_id,
                0,
                local_param,
                MMI_TRUE);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_send_save_msg_cnf(
            mod_id,
            (srv_provbox_save_msg_req_struct*) local_param,
            SRV_PROVBOX_INVALID_MSG_ID,
            result);
    }
}

/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_msg_data_req_hdlr
 * DESCRIPTION
 *    
 * PARAMETERS
 *    local_param     [IN]        
 *    mod_id            [IN]        
 *    ilm             [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
static void srv_provbox_get_msg_data_req_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_job_submit_new_job(
                srv_provbox_cntx_get_cntx(),
                SRV_PROVBOX_JOB_TYPE_GET_MSG_DATA,
                SRV_PROVBOX_JOB_SUB_TYPE_NONE,
                mod_id,
                0,
                local_param,
                MMI_TRUE);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_send_get_msg_data_cnf(
            mod_id,
            (srv_provbox_get_msg_data_req_struct*) local_param,
            MMI_SIM1,
            NULL,
            -1,
            NULL,
            result);
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 * srv_provbox_set_msg_flag_req_hdlr
 * DESCRIPTION
 *    
 * PARAMETERS
 * local_param     [IN]        
 * mod_id       [IN]        
 * ilm          [IN]        
 * RETURNS
 * void
 *****************************************************************************/
static void srv_provbox_set_msg_flag_req_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_job_submit_new_job(
                 srv_provbox_cntx_get_cntx(),
                 SRV_PROVBOX_JOB_TYPE_SET_MSG_FLAG,
                 SRV_PROVBOX_JOB_SUB_TYPE_NONE,
                 mod_id,
                 0,
                 local_param,
                 MMI_TRUE);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_send_set_msg_flag_cnf(mod_id, (srv_provbox_set_msg_flag_req_struct*) local_param, result);
    }
    
}
    
/*****************************************************************************
 * FUNCTION
 *    srv_provbox_get_msg_info_req_hdlr
 * DESCRIPTION
 *    
 * PARAMETERS
 *    local_param     [IN]        
 *    mod_id            [IN]        
 *    ilm             [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
static void srv_provbox_get_msg_info_req_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_job_submit_new_job(
                 srv_provbox_cntx_get_cntx(),
                 SRV_PROVBOX_JOB_TYPE_GET_MSG_INFO,
                 SRV_PROVBOX_JOB_SUB_TYPE_NONE,
                 mod_id,
                 0,
                 local_param,
                 MMI_TRUE);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_send_get_msg_info_cnf(
            mod_id,
            (srv_provbox_get_msg_info_req_struct*) local_param,
            NULL,
            SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED,
            NULL,
            result);
    }
}
    
/*****************************************************************************
 * FUNCTION
 *    srv_provbox_update_msg_info_req_hdlr
 * DESCRIPTION
 *    
 * PARAMETERS
 *    local_param     [IN]        
 *    mod_id            [IN]        
 *    ilm             [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
static void srv_provbox_update_msg_info_req_hdlr(void *local_param, int mod_id, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_job_submit_new_job(
                 srv_provbox_cntx_get_cntx(),
                 SRV_PROVBOX_JOB_TYPE_UPDATE_MSG_INFO,
                 SRV_PROVBOX_JOB_SUB_TYPE_NONE,
                 mod_id,
                 0,
                 local_param,
                 MMI_TRUE);
     if (result != SRV_PROVBOX_RESULT_OK)
     {
         srv_provbox_send_update_msg_info_cnf(mod_id, (srv_provbox_update_msg_info_req_struct*) local_param, result);
     }
}
    
/*----------------------------------------------------------------------------*/
/* Event sender                                                               */
/*----------------------------------------------------------------------------*/
    
/*****************************************************************************
 * FUNCTION
 *    srv_provbox_send_primtive
 * DESCRIPTION
 *    
 * PARAMETERS
 *    dest_mod_id     [IN]        
 *    msg_id            [IN]        
 *    local_para        [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
static void srv_provbox_send_primtive(oslModuleType dest_mod_id, oslMsgType msg_id, oslParaType *local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    MYQUEUE ilm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm.oslSrcId = MOD_MMI;
    ilm.oslDestId = dest_mod_id;
    ilm.oslMsgId = msg_id;
    ilm.oslDataPtr = local_para;
    ilm.oslPeerBuffPtr = NULL;

    OslMsgSendExtQueue(&ilm);
}


/*****************************************************************************
 * FUNCTION
 *    srv_provbox_update_msg_info_req_hdlr
 * DESCRIPTION
 *    
 * PARAMETERS
 *    local_param     [IN]        
 *    mod_id            [IN]        
 *    ilm             [IN]        
 * RETURNS
 *    void
 *****************************************************************************/
void srv_provbox_send_um_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_ready_ind_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_um_ready_ind_struct*) OslConstructDataPtr(sizeof(srv_um_ready_ind_struct));

    data->result = KAL_TRUE;
    data->msg_type = SRV_UM_MSG_PROV;

    mmi_frm_send_ilm(MOD_MMI, 
        MSG_ID_MMI_UM_READY_IND,
        (oslParaType*) data, 0);
}


void srv_provbox_new_msg_update_app_hdlr(srv_provbox_msg_cmn_info_struct *cmn_info)
{
#ifdef __MMI_PROV_IN_UM__
    srv_provbox_send_um_refresh_ind(SRV_UM_REFRESH_NEW_INCOMING_MSG, cmn_info->msg_id, (void*)&cmn_info->sender_addr);
#endif
    srv_provbox_event_send_new_msg_ind(cmn_info);
}

#define SRV_PROVBOX_EVENT_HDLR

void srv_provbox_event_send_update_msg_status_ind(srv_provbox_notify_type_enum type)
{
    srv_provbox_evt_notify_struct evt = {0};
    

#ifndef __COSMOS_MMI__
    SRV_PROVBOX_INIT_EVENT_HEAD(evt, SRV_PROVBOX_EVT_TYPE_BOX_FULL_IND);
#else
    MMI_FRM_INIT_EVENT(&(evt), EVT_ID_SRV_PROVBOX_EVT_IND);
#endif
    
  //  kal_prompt_trace(MOD_MMI, "[ProvBoxSrv] srv_provbox_event_send_update_msg_status type = %d", type);

    evt.type     = type;
    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


void srv_provbox_event_send_new_msg_ind(srv_provbox_msg_cmn_info_struct *cmn_info)
{
    srv_provbox_evt_new_msg_ind_struct evt = {0};
    
    SRV_PROVBOX_INIT_EVENT_HEAD(evt, SRV_PROVBOX_EVT_TYPE_NEW_MSG_IND);
    
    memcpy((void*)&evt.cmn_info, (const void*)cmn_info, sizeof(srv_provbox_msg_cmn_info_struct));
    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

#ifdef __MMI_PROV_IN_UM__
void srv_provbox_event_send_set_msg_info_ind(
         srv_um_msg_info_struct *um_msg_info, 
         srv_provbox_msg_cmn_info_struct* msg_info)
{
    srv_provbox_evt_msg_info_struct evt = {0};


    SRV_PROVBOX_INIT_EVENT_HEAD(evt, SRV_PROVBOX_EVT_TYPE_SET_MSG_INFO_IND);

    evt.msg_info    = msg_info;
    evt.um_msg_info = um_msg_info;

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


void srv_provbox_event_send_set_sort_info_ind(
         srv_um_list_idx_data_union *list_data, 
         srv_provbox_msg_cmn_info_struct* msg_info,
         const S16 msg_size,
         U8 list_idx_type)
{
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    srv_provbox_evt_sort_info_struct evt = {0};
    

    SRV_PROVBOX_INIT_EVENT_HEAD(evt, SRV_PROVBOX_EVT_TYPE_SET_SORT_INFO_IND);

    evt.list_idx_type = list_idx_type;
    evt.msg_size      = msg_size;
    evt.msg_info      = msg_info;
    evt.list_data     = list_data;

    MMI_FRM_CB_EMIT_EVENT(&evt);
#endif
}


S32 srv_provbox_evnet_send_set_traverse_process_msg_deatil_ind(
         srv_provbox_msg_cmn_info_struct *info, 
         S16 msg_size,
         U32 um_user_data,
         srv_um_detail_field_enum um_detail_field,
         srv_um_traverse_func um_traverse_callback)
{
    srv_provbox_evt_msg_detail_struct evt = {0};
    
 
    SRV_PROVBOX_INIT_EVENT_HEAD(evt, SRV_PROVBOX_EVT_TYPE_SET_MSG_DETAIL_IND);

    evt.um_detail_field = um_detail_field;
    evt.msg_size        = msg_size;
    evt.um_user_data    = um_user_data;
    evt.info            = info;
    evt.um_traverse_callback = um_traverse_callback;

    MMI_FRM_CB_EMIT_EVENT(&evt);
    
    return evt.traverse_ret;
}

#define PROVBOX_SPLIT

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_handle_um_get_msg_num_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_provbox_msg_handle_um_get_msg_num_req(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_num_req_struct *data = (srv_um_get_msg_num_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Handle DM phone lock*/
    if (data->msg_type == SRV_UM_MSG_PROV)
    {
        srv_provbox_handle_um_get_msg_num_req(data);
        return 1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_send_um_get_msg_num_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_num_data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_msg_send_um_get_msg_num_rsp(srv_um_get_msg_num_rsp_struct *msg_num_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_num_rsp_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_um_get_msg_num_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_get_msg_num_rsp_struct));

    data->msg_type = msg_num_rsp->msg_type;
    data->result   = msg_num_rsp->result;

    data->inbox_unread_msg_number = msg_num_rsp->inbox_unread_msg_number;
    data->inbox_read_msg_number   = msg_num_rsp->inbox_read_msg_number;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    data->archive_msg_number      = msg_num_rsp->archive_msg_number;
#endif

    data->sent_msg_number         = msg_num_rsp->sent_msg_number;
    data->unsent_msg_number       = msg_num_rsp->unsent_msg_number;
    data->draft_msg_number        = msg_num_rsp->draft_msg_number;
    data->predefined_template_msg_number  = msg_num_rsp->predefined_template_msg_number;
    data->userdefined_template_msg_number = msg_num_rsp->userdefined_template_msg_number;
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    data->sim_msg_number                  = msg_num_rsp->sim_msg_number ;
#endif
#ifdef __MMI_UM_REPORT_BOX__
    data->report_msg_number               = msg_num_rsp->report_msg_number;
#endif

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_NUM_RSP, (oslParaType*) data, 0);
}

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_handle_um_get_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_provbox_msg_handle_um_get_list_req(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_list_req_struct *data = (srv_um_get_msg_list_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->msg_type == SRV_UM_MSG_PROV)
    {
        srv_provbox_handle_um_get_list_req(data);
        return 1;
    }
    return 0;
}

void srv_provbox_msg_send_um_get_list_rsp(srv_provbox_um_get_msg_list_rsp_struct *rsp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_list_rsp_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_um_get_msg_list_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_get_msg_list_rsp_struct));
    
    data->app_id = rsp_data->app_id;
    data->more   = rsp_data->more;
    data->msg_box_type = rsp_data->msg_box_type;
    data->msg_number   = rsp_data->msg_number;
    data->msg_type     = rsp_data->msg_type;
    data->result       = rsp_data->result;
    data->start_entry  = rsp_data->start_entry;
    
    memcpy(data->list_info, rsp_data->list_info, rsp_data->msg_number * sizeof(srv_um_msg_list_struct));
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    memcpy(data->list_idx_data, rsp_data->list_idx_data, rsp_data->msg_number * sizeof(srv_um_list_idx_data_union));
#endif
    
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_LIST_RSP, (oslParaType*) data, 0);
}

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_handle_um_get_msg_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_provbox_msg_handle_um_get_msg_info_req(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_req_struct *data = (srv_um_get_msg_info_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->msg_type == SRV_UM_MSG_PROV)
    {
        srv_provbox_handle_um_get_msg_info_req(data);
        return 1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_send_um_get_msg_info_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_send_um_get_msg_info_rsp(srv_um_get_msg_info_rsp_struct *rsp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_rsp_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_um_get_msg_info_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_get_msg_info_rsp_struct));
    
    if (rsp_data->msg_number > SRV_UM_MAX_GET_MSG_INFO_NUMBER)
    {
        rsp_data->msg_number = SRV_UM_MAX_GET_MSG_INFO_NUMBER;
    }
    
    data->app_id       = rsp_data->app_id;
    data->msg_type     = SRV_UM_MSG_PROV;
    data->msg_number   = rsp_data->msg_number;
    data->msg_box_type = rsp_data->msg_box_type;

    memcpy(data->result,   rsp_data->result,   sizeof(kal_bool) * rsp_data->msg_number);
    memcpy(data->msg_info, rsp_data->msg_info, rsp_data->msg_number * sizeof(srv_um_msg_info_struct));
    memcpy(data->msg_id,   rsp_data->msg_id,   rsp_data->msg_number * sizeof(U32));

    mmi_frm_send_ilm(MOD_MMI, 
        MSG_ID_MMI_UM_GET_MSG_INFO_RSP,
        (oslParaType*) data, 0);
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_handle_um_traverse_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_provbox_msg_handle_um_traverse_msg_req(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_traverse_msg_req_struct *data = (srv_um_traverse_msg_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->msg_type == SRV_UM_MSG_PROV)
    {
        srv_provbox_handle_um_traverse_msg_req(data);
        return 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provboxui_send_um_traverse_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_send_um_traverse_msg_rsp(srv_um_traverse_msg_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_traverse_msg_rsp_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (mmi_um_traverse_msg_rsp_struct*) OslConstructDataPtr(sizeof(mmi_um_traverse_msg_rsp_struct));

    data->app_id     = rsp->app_id;
    data->msg_type   = SRV_UM_MSG_PROV;
    data->result     = rsp->result;
    data->more       = rsp->more;
    data->msg_number = rsp->msg_number;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_UM_TRAVERSE_MSG_RSP, (oslParaType*) data, 0);
}
#endif /* __MMI_UM_CONVERSATION_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  srv_provboxui_msg_handle_um_delete_folder_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_provbox_msg_handle_um_delete_folder_req(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_req_struct *data = (srv_um_delete_folder_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->msg_type == SRV_UM_MSG_PROV)
    {
        srv_provbox_handle_um_delete_folder_req(data);
        return 1;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_provboxui_send_um_delete_folder_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_send_um_delete_folder_rsp(srv_provbox_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_rsp_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_um_delete_folder_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_delete_folder_rsp_struct));

    data->msg_type = SRV_UM_MSG_PROV;

    if (result == SRV_PROVBOX_RESULT_OK)
    {
        data->result = KAL_TRUE;
    }
    else
    {
        data->result = KAL_FALSE;
    }

    mmi_frm_send_ilm(MOD_MMI, 
        MSG_ID_MMI_UM_DELETE_FOLDER_RSP,
        (oslParaType*) data, 0);
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_handle_um_multi_op_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]
 *  src_mod         [IN]        
 *  peer_buf        [IN]
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_provbox_msg_handle_um_multi_op_req(void *msg, int src_mod, void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_mark_several_op_req_struct *data = (srv_um_mark_several_op_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->msg_type == SRV_UM_MSG_PROV)
    {
        srv_provbox_handle_um_multi_op_req(data);
        return 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provboxui_send_um_multi_op_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_send_um_multi_op_rsp(srv_um_mark_several_op_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_mark_several_op_rsp_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_um_mark_several_op_rsp_struct*) OslConstructDataPtr(sizeof(srv_um_mark_several_op_rsp_struct));

    data->msg_type     = rsp->msg_type;
    data->msg_box_type = rsp->msg_box_type;
    data->action_type  = rsp->action_type;
    data->msg_number   = rsp->msg_number;
    
    memcpy((void *)data->msg_id, (const void *)rsp->msg_id, sizeof(U32) * SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);
    memcpy((void *)data->action_result, (const void *)rsp->action_result, sizeof(kal_bool) * SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);

    mmi_frm_send_ilm(MOD_MMI, 
        MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP,
        (oslParaType*) data, 0);
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


void srv_provbox_send_um_refresh_ind(srv_um_refresh_enum type, U32 msg_id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *data = NULL;
    srv_provbox_addr_struct *addr   = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_um_refresh_ind_struct*) OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

    data->msg_type     = SRV_UM_MSG_PROV;
    data->msg_id       = msg_id;
    data->refresh_type = type;
    data->msg_box_type = SRV_UM_MSG_BOX_INBOX;
    
    if (NULL != user_data)
    {
        addr = (srv_provbox_addr_struct *)user_data;
        data->addr_type = srv_provbox_addr_type_pbox2um(addr->addr_type);
        memcpy((void*)data->address, (const void*)addr->addr, (SRV_UM_MAX_ADDR_LEN + 1) * sizeof(WCHAR));
        data->address[SRV_UM_MAX_ADDR_LEN] = 0;
    }

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) data, 0);
}

#ifdef __COSMOS_MMI__
void srv_provbox_event_send_set_msg_state_ready_ind(
         srv_provbox_callback_func um_callback,
         srv_provbox_result_enum set_result,
         void *user_data)
{
    srv_provbox_evt_msg_msg_ready_struct evt = {0};
    
    SRV_PROVBOX_INIT_EVENT_HEAD(evt, SRV_PROVBOX_EVT_TYPE_SET_MSG_STATE_READY_IND);

    evt.um_set_ready_callback = um_callback;
    evt.set_ready_result      = set_result;
    evt.user_data             = user_data;
    
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}
#endif /* __COSMOS_MMI__ */

#endif /* __MMI_PROV_IN_UM__ */
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

