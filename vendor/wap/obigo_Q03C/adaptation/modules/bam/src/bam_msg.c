#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_msg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions that handles external messages sent by applications.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_types.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "wap_ps_struct.h"
#include "StdC.h"       /* For STD_C and Osl Memory functions */
#include "mmi_frm_gprot.h"
#include "msf_def.h"
#include "msf_int.h"
#include "msf_lib.h"
#include "msf_core.h"
#include "msf_wid.h"
#include "msf_log.h"
#if 0
/* under construction !*/
#endif
#include "bam_cfg.h"
#include "bam_do_elem.h"
#include "bam_hist.h"
#include "bam_if.h"
#include "bam_main.h"
#include "bam_msg.h"
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#include "bam_offline.h"
#endif
#include "bam_registry.h"
#include "bam_req.h"
#include "bam_resource.h"
#include "bam_sif.h"
#include "bam_win.h"

#include "msm_env.h"
#include "widget.h"

#if 0
/* under construction !*/
/* under construction !*/
#endif
#include "brs_if.h"
#include "stk_if.h"

extern void mmi_brw_app_if_reload_req_processed(void);
extern void mmi_brw_app_if_load_url_req_processed(void);
//extern void widget_init_structure(void);
#ifdef MTK_TMP_PATCH /* TR34746, TR34686: Loading large web page and MT call comes */
/*****************************************************************************
 * FUNCTION
 *  bam_msg_get_num_of_msg_brw_task
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
int bam_msg_get_num_of_msg_brw_task(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 queue_node_number = 0;
	kal_uint32 my_index = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_get_my_task_index(&my_index);
	msg_get_ext_queue_info(task_info_g[my_index].task_ext_qid, &queue_node_number);

	return queue_node_number;
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_get_num_of_msg_brw_task
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
int bam_msg_get_max_num_of_msg_brw_task(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 max_queue_node_number = 0;
	kal_uint32 my_index = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_get_my_task_index(&my_index);
	msg_get_ext_queue_length(task_info_g[my_index].task_ext_qid, &max_queue_node_number);

	return max_queue_node_number;
}
#endif /* MTK_TMP_PATCH */

/*****************************************************************************
 * FUNCTION
 *  bam_send_ilm
 * DESCRIPTION
 *
 * PARAMETERS
 *  local_para_ptr      [?]
 *  peer_buff_ptr       [?]
 *  ilm_id              [IN]
 *  dst_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void bam_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_id)
    {
        case MOD_MMI:
            sap_id = WAP_MMI_SAP;
            break;

        default:
            /* invalid value */
            sap_id = WAP_MMI_SAP;
            break;
    }   /* switch (dst_id) */

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    ilm_ptr->src_mod_id = MOD_WAP;
    ilm_ptr->dest_mod_id = dst_id;
    ilm_ptr->sap_id = sap_id;
    msg_send_ext_queue(ilm_ptr);
    /* SEND_ILM(MOD_WAP, dst_id, sap_id, ilm_ptr); */
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_free_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  p       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_free_profile(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned i;
    wap_bam_profile_setting_t *profile = (wap_bam_profile_setting_t*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < wap_bam_setting_id_total; i++)
    {
        if (profile->str_value_table[i] != WAP_BAM_SETTING_STR_INIT_VAL)
        {
            OslMfree(profile->str_value_table[i]);
        }
    }
    OslMfree(profile);
}

/*
 * Send SAP message functions
 */


/*****************************************************************************
 * FUNCTION
 *  bam_msg_ready_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_ready_ind_struct *ready_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ready_ind = (wap_bam_ready_ind_struct*) construct_local_para(sizeof(wap_bam_ready_ind_struct), TD_RESET);

    bam_send_ilm(ready_ind, NULL, MSG_ID_WAP_BAM_READY_IND, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_1D37346418248398B302DA4B12508AC1,
                     "BAM: sent message MSG_ID_WAP_BAM_READY_IND\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_create_instance_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  error_code      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_create_instance_cnf(MSF_INT32 instance_id, MSF_INT16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_create_instance_cnf_struct *create_instance_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_instance_cnf =
        (wap_bam_create_instance_cnf_struct*) construct_local_para(
                                                sizeof(wap_bam_create_instance_cnf_struct),
                                                TD_RESET);

    create_instance_cnf->instance_id = (kal_int32) instance_id;
    create_instance_cnf->error_code = (kal_uint16) error_code;

    bam_send_ilm(create_instance_cnf, NULL, MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_A44DE870CE35D623717F274198471B6C,
                     "BAM: sent message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_delete_instance_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_delete_instance_cnf(MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_instance_cnf_struct *delete_instance_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_instance_cnf =
        (wap_bam_delete_instance_cnf_struct*) construct_local_para(
                                                sizeof(wap_bam_delete_instance_cnf_struct),
                                                TD_RESET);

    delete_instance_cnf->instance_id = (kal_int32) instance_id;

    bam_send_ilm(delete_instance_cnf, NULL, MSG_ID_WAP_BAM_DELETE_INSTANCE_CNF, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_3393BBB173E19B222DA57F1BF4A267F2,
                     "BAM: sent message MSG_ID_WAP_BAM_DELETE_INSTANCE_CNF\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_set_profile_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  request_id      [IN]
 *  error_code      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_set_profile_cnf(MSF_INT32 instance_id, MSF_UINT8 request_id, MSF_UINT16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_set_profile_cnf_struct *set_profile_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_profile_cnf =
        (wap_bam_set_profile_cnf_struct*) construct_local_para(sizeof(wap_bam_set_profile_cnf_struct), TD_RESET);

    set_profile_cnf->instance_id = (kal_int32) instance_id;
    set_profile_cnf->request_id = (kal_uint8) request_id;
    set_profile_cnf->error_code = (kal_uint16) error_code;

    bam_send_ilm(set_profile_cnf, NULL, MSG_ID_WAP_BAM_SET_PROFILE_CNF, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_1D32B7BF2B5BEA34A7EC8B0AE68FB4BA,
                     "BAM: sent message MSG_ID_WAP_BAM_SET_PROFILE_CNF\n"));
}

#if 0
#ifdef BAM_CFG_SHORTCUTS_ENABLED
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BAM_CFG_SHORTCUTS_ENABLED */
#endif


/*****************************************************************************
 * FUNCTION
 *  bam_msg_status_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  p               [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_status_ind(MSF_INT32 instance_id, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_status_ind_struct *status_ind;
    brs_status_t *brs_status = (brs_status_t*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT) || defined(MSF_CFG_FILE_UPLOAD_SUPPORT)
    if((brs_status->status !=BRS_STATUS_START_TRANSACTION) && (brs_status->status !=BRS_STATUS_END_TRANSACTION))
    {
        if(bam_main_get_received_transaction_status() == TRUE)
            return;
        else
            bam_main_set_received_transaction_status(TRUE);
    }
#endif
    status_ind = (wap_bam_status_ind_struct*) construct_local_para(sizeof(wap_bam_status_ind_struct), TD_RESET);

    status_ind->instance_id = (kal_int32) instance_id;
#if 0
/* under construction !*/
#else
    switch(brs_status->status)
    {
    case BRS_STATUS_START_TRANSACTION:
        status_ind->status = WAP_BAM_STATUS_START_TRANSACTION;
        break;
    case BRS_STATUS_END_TRANSACTION:
        status_ind->status = WAP_BAM_STATUS_END_TRANSACTION;
        break;
    default:
#if defined(BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT) || defined(MSF_CFG_FILE_UPLOAD_SUPPORT)
        status_ind->status = WAP_BAM_STATUS_TRANSACTION_STATUS;
        break;
#else
        return;
#endif
    }
#endif
    status_ind->transaction_id = (kal_int16) brs_status->transactionId;
    status_ind->upload_bytes_sent = (kal_int32) brs_status->upload_bytes_sent;
    status_ind->upload_bytes_total = (kal_int32) brs_status->upload_bytes_total;
    status_ind->document_bytes_read = (kal_int32) brs_status->document_bytes_read;
    status_ind->document_bytes_total = (kal_int32) (brs_status->document_bytes_total > 0) ? 
										brs_status->document_bytes_total : 
										bam_sif_get_current_page_size();
    status_ind->document_number_of_requested = (kal_int16) brs_status->document_number_of_requested;
    status_ind->document_number_of_downloaded = (kal_int16) brs_status->document_number_of_downloaded;
    status_ind->document_number_of_failed = (kal_int16) brs_status->document_number_of_failed;
    status_ind->resources_bytes = (kal_int32) brs_status->resources_bytes;
    status_ind->resources_number_of_requested = (kal_int16) brs_status->resources_number_of_requested;
    status_ind->resources_number_of_downloaded = (kal_int16) brs_status->resources_number_of_downloaded;
    status_ind->resources_number_of_failed = (kal_int16) brs_status->resources_number_of_failed;

    bam_send_ilm(status_ind, NULL, MSG_ID_WAP_BAM_STATUS_IND, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_C99BAF129123CDB0B7BA861F78216540,
                     "BAM: sent message MSG_ID_WAP_BAM_STATUS_IND\n"));
}

/*****************************************************************************
 * FUNCTION
 *  bam_msg_external_object_status_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  status			[IN]
 *  transaction_id  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_external_object_status_ind(MSF_INT16 status, MSF_INT16 transaction_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_status_ind_struct *status_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status_ind = (wap_bam_status_ind_struct*) construct_local_para(sizeof(wap_bam_status_ind_struct), TD_RESET);

    status_ind->instance_id = (kal_int32) bam_sif_get_brs_id();
    status_ind->status = (kal_int16) status;
    status_ind->transaction_id = (kal_int16) transaction_id;
    status_ind->upload_bytes_sent = 0;
    status_ind->upload_bytes_total = 0;
    status_ind->document_bytes_read = 0;
    status_ind->document_bytes_total = 0;
    status_ind->document_number_of_requested = 0;
    status_ind->document_number_of_downloaded = 0;
    status_ind->document_number_of_failed = 0;
    status_ind->resources_bytes = 0;
    status_ind->resources_number_of_requested = 0;
    status_ind->resources_number_of_downloaded = 0;
    status_ind->resources_number_of_failed = 0;

    bam_send_ilm(status_ind, NULL, MSG_ID_WAP_BAM_STATUS_IND, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_C99BAF129123CDB0B7BA861F78216540,
                     "BAM: sent message MSG_ID_WAP_BAM_STATUS_IND\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_error_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  error_code      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_error_ind(MSF_INT32 instance_id, MSF_INT16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_error_ind_struct *error_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifndef BAM_CFG_SEND_JAVASCRIPT_ERROR_INDICATION
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BAM_CFG_SEND_JAVASCRIPT_ERROR_INDICATION */
#endif

    error_ind = (wap_bam_error_ind_struct*) construct_local_para(sizeof(wap_bam_error_ind_struct), TD_RESET);

    error_ind->instance_id = (instance_id > 0) ? instance_id : (kal_int32) bam_sif_get_brs_id();
    error_ind->error_code = (kal_int32) error_code;

    bam_send_ilm(error_ind, NULL, MSG_ID_WAP_BAM_ERROR_IND, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_E2B681373BFC1BBBD8BDCBF5751BA040,
                     "BAM: sent message MSG_ID_WAP_BAM_ERROR_IND\n"));
}

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_msg_select_file_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  request_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_select_file_ind(MSF_INT16 instance_id, MSF_INT32 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_select_file_ind_struct *select_file_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    select_file_ind = (wap_bam_select_file_ind_struct*) construct_local_para(sizeof(wap_bam_select_file_ind_struct), TD_RESET);

    select_file_ind->instance_id = (instance_id > 0) ? instance_id : bam_sif_get_brs_id();
    select_file_ind->request_id = (kal_int32) request_id;

    bam_send_ilm(select_file_ind, NULL, MSG_ID_WAP_BAM_SELECT_FILE_IND, MOD_MMI);

	MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_26E0D38F6DB8657F4D60753980E5F573, "BAM: sent message MSG_ID_WAP_BAM_SELECT_FILE_IND\n"));

}
#endif


	
#if defined(__WAP_VDS_MODULE__) && defined(MSF_MODID_VDS)
extern void vds_terminate(void);
#endif
#if defined(__WAP_SVS_MODULE__) && defined(MSF_MODID_SVS)
extern void svs_terminate(void);
#endif
/*****************************************************************************
 * FUNCTION
 *  bam_msg_out_of_memory_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_out_of_memory_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_msg_error_ind(bam_sif_get_brs_id(), WAP_BAM_ERROR_OUT_OF_MEMORY);
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_out_of_mem_wap_reset_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_out_of_mem_wap_reset_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_msg_error_ind(bam_sif_get_brs_id(), WAP_BAM_ERROR_OUT_OF_MEM_WAP_RESET);
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_document_info_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  p               [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_document_info_ind(MSF_INT32 instance_id, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    wap_bam_document_info_ind_struct *doc_info_ind;
    brs_document_info_t *doc_info = (brs_document_info_t*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc_info_ind =
        (wap_bam_document_info_ind_struct*) construct_local_para(sizeof(wap_bam_document_info_ind_struct), TD_RESET);

    doc_info_ind->instance_id = (kal_int32) instance_id;
    doc_info_ind->document_id = (kal_int16) doc_info->documentId;
    doc_info_ind->flags = (kal_int16) doc_info->flags;
    doc_info_ind->doc_type = (kal_int16) doc_info->docType;
#if 0
/* under construction !*/
#else
    switch(doc_info->protocol)
    {
    case STK_PROTOCOL_WSP_CL:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_WSP_CL;
        break;
    case STK_PROTOCOL_WSP_CL_WTLS:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_WSP_CL_WTLS;
        break;
    case STK_PROTOCOL_WSP_CO:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_WSP_CO;
        break;
    case STK_PROTOCOL_WSP_CO_WTLS:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_WSP_CO_WTLS;
        break;
    case STK_PROTOCOL_HTTP:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_HTTP;
        break;
    case STK_PROTOCOL_HTTP_TLS:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_HTTP_TLS;
        break;
    case STK_PROTOCOL_HTTP_SSL:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_HTTP_SSL;
        break;
    case STK_PROTOCOL_CACHE:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_CACHE;
        break;
    case STK_PROTOCOL_FILE:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_FILE;
        break;
    case STK_PROTOCOL_OTHER:
    default:
        doc_info_ind->protocol = WAP_BAM_PROTOCOL_OTHER;
        break;
    }
#endif
    doc_info_ind->size = (kal_int32) doc_info->size;
    doc_info_ind->socket_id = (kal_int32) doc_info->socketId;
    doc_info_ind->security_id = (kal_int32) doc_info->securityId;
    doc_info_ind->last_modified = (kal_uint32) doc_info->lastModified;

    len = 0;

    if (doc_info->url)
    {
        len = (strlen(doc_info->url) <= WAP_BAM_MAX_URL_LEN) ? strlen(doc_info->url) : WAP_BAM_MAX_URL_LEN;
        strncpy(doc_info_ind->url, doc_info->url, len);
    }
    doc_info_ind->url[len] = '\0';

    len = 0;

    if (doc_info->title)
    {
        len = (strlen(doc_info->title) <= WAP_BAM_MAX_TITLE_LABEL_LENGTH)
            ? strlen(doc_info->title) : WAP_BAM_MAX_TITLE_LABEL_LENGTH;
        strncpy(doc_info_ind->title, doc_info->title, len);
    }
    doc_info_ind->title[len] = '\0';

    bam_send_ilm(doc_info_ind, NULL, MSG_ID_WAP_BAM_DOCUMENT_INFO_IND, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_8FC21EB39D121182E080FB926E392322,
                     "BAM: sent message MSG_ID_WAP_BAM_DOCUMENT_INFO_IND\n"));
}

/*****************************************************************************
 * FUNCTION
 *  bam_msg_notify_app_ind
 * DESCRIPTION
 *  This function is used to notify APP to something according to type.
 * PARAMETERS
 *  title       [IN]    The title string which will be updated
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_notify_app_ind(wap_bam_notify_app_enum type, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_notify_app_ind_struct *notify_app_ind;
#if 0
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    notify_app_ind =
        (wap_bam_notify_app_ind_struct*) construct_local_para(sizeof(wap_bam_notify_app_ind_struct), TD_RESET);

    switch(type)
    {
        /*
        case wap_bam_notify_app_set_title_string:
            title_length = 0;
            if (((brs_set_title_string_t*)p)->title)
            {
                title_length = (strlen(((brs_set_title_string_t*)p)->title) <= WAP_BAM_MAX_TITLE_LABEL_LENGTH)
                                ? strlen(((brs_set_title_string_t*)p)->title) : WAP_BAM_MAX_TITLE_LABEL_LENGTH;
                strncpy(notify_app_ind->title, ((brs_set_title_string_t*)p)->title, title_length);
            }
            notify_app_ind->title[title_length] = '\0';
            break;*/
            
        default:
            return;
    }

    bam_send_ilm(notify_app_ind, NULL, MSG_ID_WAP_BAM_NOTIFY_APP_IND, MOD_MMI);

  //  MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_5A87B1BC0BCA09F55A117E603F77E97A, 
   //                 "BAM: sent message MSG_ID_WAP_BAM_NOTIFY_APP_IND\n"));
}


#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
/*****************************************************************************
 * FUNCTION
 *  bam_msg_do_elements_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  p               [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_do_elements_ind(MSF_INT32 instance_id, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_do_elements_ind_struct *do_elements_ind;
    brs_do_elements_t *do_elements = (brs_do_elements_t*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (do_elements == NULL)
    {
        return;
    }

    do_elements_ind =
        (wap_bam_do_elements_ind_struct*) construct_local_para(sizeof(wap_bam_do_elements_ind_struct), TD_RESET);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_3F4CFE84FD7FA4C38376DA6E30DF182D,
                     "BAM: Send message MSG_ID_WAP_BAM_DO_ELEMENTS_IND\n"));

    do_elements_ind->instance_id = (kal_int32) instance_id;
    do_elements_ind->num_elements = (kal_int16) do_elements->numElements;
	if (do_elements_ind->num_elements > WAP_BAM_MAX_NUM_DO_ELEMENTS)
	{
		do_elements_ind->num_elements = WAP_BAM_MAX_NUM_DO_ELEMENTS;
	}

    if (do_elements_ind->num_elements > 0)
    {
        int i;
        int len;
        kal_uint16 pdu_length = 0;

        peer_buff_struct *peer_buff = construct_peer_buff(sizeof(wap_bam_do_elements_struct), 0, 0, TD_RESET);
        wap_bam_do_elements_struct *bam_do_elements =
            (wap_bam_do_elements_struct*) get_pdu_ptr(peer_buff, &pdu_length);

        bam_do_elements->num_elements = do_elements_ind->num_elements;

        for (i = 0; i < bam_do_elements->num_elements; i++)
        {
            brs_do_element_t *element = (brs_do_element_t*) & do_elements->elements[i];
            wap_bam_do_element_t *bam_element = (wap_bam_do_element_t*) & bam_do_elements->elements[bam_do_elements->num_elements-i-1];

            bam_element->element_id = element->elementId;
            bam_element->is_optional = element->isOptional;

            len = 0;

            if (element->label)
            {
                len = (strlen(element->label) <= WAP_BAM_MAX_TITLE_LABEL_LENGTH)
                    ? strlen(element->label) : WAP_BAM_MAX_TITLE_LABEL_LENGTH;
                strncpy(bam_element->label, element->label, len);

            }
            bam_element->label[len] = '\0';

            len = 0;

            if (element->eventType)
            {
                len = (strlen(element->eventType) <= WAP_BAM_MAX_TITLE_LABEL_LENGTH)
                    ? strlen(element->eventType) : WAP_BAM_MAX_TITLE_LABEL_LENGTH;
                strncpy(bam_element->event_type, element->eventType, len);
            }
            bam_element->event_type[len] = '\0';
        }

        bam_send_ilm(do_elements_ind, peer_buff, MSG_ID_WAP_BAM_DO_ELEMENTS_IND, MOD_MMI);
        return;
    }

    bam_send_ilm(do_elements_ind, NULL, MSG_ID_WAP_BAM_DO_ELEMENTS_IND, MOD_MMI);
}
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */


/*****************************************************************************
 * FUNCTION
 *  bam_msg_element_focused_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  p               [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_element_focused_ind(MSF_INT32 instance_id, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    wap_bam_element_focused_ind_struct *element_focused_ind;
    brs_element_focused_t *element_focused = (brs_element_focused_t*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__    
    if(element_focused->type == BRS_FOCUSED_ELEMENT_IMAGE_LONG_TAP)
#endif
    {

    element_focused_ind =
        (wap_bam_element_focused_ind_struct*) construct_local_para(
                                                sizeof(wap_bam_element_focused_ind_struct),
                                                TD_RESET);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_556B3B48FDAD8F7F90D6886BCB8FD6F3,
                     "BAM: Send message MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND\n"));

    element_focused_ind->instance_id = (kal_int32) instance_id;
#if 0
/* under construction !*/
#endif
#if 0
/* under construction !*/
#else
    switch(element_focused->type)
    {
    case BRS_FOCUSED_ELEMENT_NONE:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_NONE;
        break;
    case BRS_FOCUSED_ELEMENT_LINK:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_LINK;
        break;
    case BRS_FOCUSED_ELEMENT_DO:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_DO;
        break;
    case BRS_FOCUSED_ELEMENT_TEXTINPUT:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_TEXTINPUT;
        break;
    case BRS_FOCUSED_ELEMENT_SELECT:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_SELECT;
        break;
    case BRS_FOCUSED_ELEMENT_IMAGE:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_IMAGE;
        break;
    case BRS_FOCUSED_ELEMENT_IMG_NO_SAVE:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_IMAGE;
        break;
    case BRS_FOCUSED_ELEMENT_INPUT:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_INPUT;
        break;
    case BRS_FOCUSED_ELEMENT_BUTTON:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_BUTTON;
        break;
    case BRS_FOCUSED_ELEMENT_SUBMIT:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_SUBMIT;
        break;
    case BRS_FOCUSED_ELEMENT_RESET:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_RESET;
        break;
    case BRS_FOCUSED_ELEMENT_FILE_INPUT:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_FILE_INPUT;
        break;
    case BRS_FOCUSED_ELEMENT_CHKBOX_SELECTED:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_INPUT_SELECTED;
        break;
    case BRS_FOCUSED_ELEMENT_CHKBOX_UNSELECTED:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_INPUT_UNSELECTED;
        break;
    case BRS_FOCUSED_ELEMENT_AREA:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_AREA;
        break;
    case BRS_FOCUSED_ELEMENT_INPUT_IMAGE:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_SUBMIT;
        break;
    case BRS_FOCUSED_ELEMENT_RADIO_SELECTED:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_INPUT_SELECTED;
        break;
    case BRS_FOCUSED_ELEMENT_RADIO_UNSELECTED:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_INPUT_UNSELECTED;
        break;

    case BRS_FOCUSED_ELEMENT_IMAGE_LONG_TAP:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_IMAGE_LONG_TAP;
        break;
    default:
        element_focused_ind->type = WAP_BAM_FOCUSED_ELEMENT_NONE;
        break;
    }
#endif
    element_focused_ind->drm_restriction = (kal_int16) element_focused->drm_restriction;
#if 0
/* under construction !*/
#endif

    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_7B98F436FB94DE59AB33AB40C8BDAFC9,
                     "BAM: element_focused_ind->type= %d\n", element_focused_ind->type));

    len = 0;

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
#endif

    if (element_focused->title)
    {
        len = (strlen(element_focused->title) <= WAP_BAM_MAX_TITLE_LABEL_LENGTH)
            ? strlen(element_focused->title) : WAP_BAM_MAX_TITLE_LABEL_LENGTH;
        strncpy(element_focused_ind->title, element_focused->title, len);
    }
    element_focused_ind->title[len] = '\0';

    len = 0;

    if (element_focused->url)
    {
        len = (strlen(element_focused->url) <= WAP_BAM_MAX_URL_LEN)
            ? strlen(element_focused->url) : WAP_BAM_MAX_URL_LEN;
        strncpy(element_focused_ind->url, element_focused->url, len);
    }
    element_focused_ind->url[len] = '\0';

    len = 0;

    if (element_focused->object_url)
    {
        len = (strlen(element_focused->object_url) <= WAP_BAM_MAX_URL_LEN)
            ? strlen(element_focused->object_url) : WAP_BAM_MAX_URL_LEN;
        strncpy(element_focused_ind->object_url, element_focused->object_url, len);
    }
    element_focused_ind->object_url[len] = '\0';

    len = 0;

    if (element_focused->object_mime)
    {
        len = (strlen(element_focused->object_mime) <= WAP_BAM_MAX_MIME_TYPE_LEN)
            ? strlen(element_focused->object_mime) : WAP_BAM_MAX_MIME_TYPE_LEN;
        strncpy(element_focused_ind->object_mime, element_focused->object_mime, len);
    }
    element_focused_ind->object_mime[len] = '\0';

    len = 0;

    if (element_focused->object_filePath && element_focused->type != BRS_FOCUSED_ELEMENT_IMG_NO_SAVE)
    {
        len = (strlen(element_focused->object_filePath) <= WAP_BAM_MAX_FILE_PATH_LEN)
            ? strlen(element_focused->object_filePath) : WAP_BAM_MAX_FILE_PATH_LEN;
        strncpy(element_focused_ind->object_filePath, element_focused->object_filePath, len);
    }
    element_focused_ind->object_filePath[len] = '\0';

    bam_send_ilm(element_focused_ind, NULL, MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND, MOD_MMI);
    }
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_39BBF860FB673433DC4357F757DC3E49,
                     "BAM: sent message MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND\n"));
}

void bam_msg_bearer_open_ind(MSF_INT32 instance_id)
{

	wap_bam_bearer_open_ind_struct *bearer_open_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bearer_open_ind =
        (wap_bam_bearer_open_ind_struct*) construct_local_para(sizeof(wap_bam_bearer_open_ind_struct), TD_RESET);

	bearer_open_ind->instance_id=instance_id;

    bam_send_ilm(bearer_open_ind, NULL, MSG_ID_WAP_BAM_BEARER_OPEN_IND, MOD_MMI);

}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_set_sec_class_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  sec_class       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_set_sec_class_ind(MSF_INT32 instance_id, int sec_class)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_set_sec_class_ind_struct *set_sec_class_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_sec_class_ind =
        (wap_bam_set_sec_class_ind_struct*) construct_local_para(sizeof(wap_bam_set_sec_class_ind_struct), TD_RESET);

    set_sec_class_ind->instance_id = (kal_int32) instance_id;
    set_sec_class_ind->sec_class = (kal_int16) sec_class;

    bam_send_ilm(set_sec_class_ind, NULL, MSG_ID_WAP_BAM_SET_SEC_CLASS_IND, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_77FF5AAC12516665FEBE9C752883980A,
                     "BAM: sent message MSG_ID_WAP_BAM_SET_SEC_CLASS_IND\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_wait_user_action_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  enable_positive_sk      [IN]
 *  positive_label          [IN]
 *  enable_negative_sk      [IN]
 *  negative_label          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
bam_msg_wait_user_action_ind(
    MSF_BOOL enable_positive_sk,
    const char *positive_label,
    MSF_INT32 positive_label_len,
    MSF_BOOL enable_negative_sk,
    const char *negative_label,
    MSF_INT32 negative_label_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    wap_bam_wait_user_action_ind_struct *wait_user_action_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wait_user_action_ind = (wap_bam_wait_user_action_ind_struct*)
        construct_local_para(sizeof(wap_bam_wait_user_action_ind_struct), TD_RESET);

    wait_user_action_ind->instance_id = (kal_int32) bam_sif_get_brs_id();
    wait_user_action_ind->enable_positive_sk = (kal_bool) enable_positive_sk;

	if ((positive_label != NULL) && (positive_label_len > 0))
	{
		if(positive_label_len <= WAP_BAM_MAX_TITLE_LABEL_LENGTH)
		{
			len = positive_label_len;
		}
		else
		{
			len = WAP_BAM_MAX_TITLE_LABEL_LENGTH;
		}
	}
	else
	{
		len = 0;
	}

    if (len > 0)
    {
        memcpy((void*)wait_user_action_ind->positive_label, (void*)positive_label, len);
    }
    wait_user_action_ind->positive_label[len] = '\0';
	wait_user_action_ind->positive_label_len = len;

    wait_user_action_ind->enable_negative_sk = (kal_bool) enable_negative_sk;

	if ((negative_label != NULL) && (negative_label_len > 0))
	{
		if(negative_label_len <= WAP_BAM_MAX_TITLE_LABEL_LENGTH)
		{
			len = negative_label_len;
		}
		else
		{
			len = WAP_BAM_MAX_TITLE_LABEL_LENGTH;
		}
	}
	else
	{
		len = 0;
	}

    if (len > 0)
    {
        memcpy((void*)wait_user_action_ind->negative_label, (void*)negative_label, len);
    }
    wait_user_action_ind->negative_label[len] = '\0';
	wait_user_action_ind->negative_label_len = len;

    bam_send_ilm(wait_user_action_ind, NULL, MSG_ID_WAP_BAM_WAIT_USER_ACTION_IND, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_80FCE6BBDD93E12B93948924006DF762,
                     "BAM: sent message MSG_ID_WAP_BAM_WAIT_USER_ACTION_IND\n"));
}


#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
void bam_msg_wmls_create_dialogue_req(MSF_INT32 instance_id,
		                         MSF_INT32 dialup_type,
							     const char *msg,
								 const char *prompt_msg,
								 const char *lsk,
								 const char *rsk)
{
wap_bam_wmls_create_dialogue_req_struct *wmls_create_dialogue_req;
int len;

wmls_create_dialogue_req= (wap_bam_wmls_create_dialogue_req_struct*)
        construct_local_para(sizeof(wap_bam_wmls_create_dialogue_req_struct), TD_RESET);

wmls_create_dialogue_req->instance_id=instance_id;
wmls_create_dialogue_req->dialup_type=dialup_type;

//len=strlen(msg);
if ((msg != NULL) && (strlen(msg) > 0))
	{
		if((strlen(msg) <= WAP_BAM_MAX_WMLS_MSG_LENGTH))
		{
			len = strlen(msg);
		}
		else
		{
			len = WAP_BAM_MAX_WMLS_MSG_LENGTH;
		}
	}
	else
	{
		len = 0;
	}

if(len>0)
{
memcpy(wmls_create_dialogue_req->msg, msg,len);
wmls_create_dialogue_req->msg[len]= '\0';
}

//len=strlen(prompt_msg);
if ((prompt_msg != NULL) && (strlen(prompt_msg) > 0))
	{
		if((strlen(prompt_msg) <= WAP_BAM_MAX_WMLS_MSG_LENGTH))
		{
			len = strlen(prompt_msg);
		}
		else
		{
			len = WAP_BAM_MAX_WMLS_MSG_LENGTH;
		}
	}
	else
	{
		len = 0;
	}
if(len>0)
{
memcpy(wmls_create_dialogue_req->prompt_msg, prompt_msg,len);
wmls_create_dialogue_req->prompt_msg[len]= '\0';
}

if ((lsk != NULL) && (strlen(lsk) > 0))
	{
		if(strlen(lsk) <= WAP_BAM_MAX_WMLS_MSG_LENGTH)
		{
			len = strlen(lsk);
		}
		else
		{
			len = WAP_BAM_MAX_WMLS_MSG_LENGTH;
		}
	}
	else
	{
		len = 0;
	}

//len=strlen(lsk);
if(len>0)
{
memcpy(wmls_create_dialogue_req->lsk, lsk,len);
wmls_create_dialogue_req->lsk[len]= '\0';
}
if ((rsk != NULL) && (strlen(rsk) > 0))
	{
		if((strlen(rsk) <= WAP_BAM_MAX_WMLS_MSG_LENGTH))
		{
			len = strlen(rsk);
		}
		else
		{
			len = WAP_BAM_MAX_WMLS_MSG_LENGTH;
		}
	}
	else
	{
		len = 0;
	}
//len=strlen(rsk);
if(len>0)
{
memcpy(wmls_create_dialogue_req->rsk, rsk,len);
wmls_create_dialogue_req->prompt_msg[len]= '\0';
}


bam_send_ilm(wmls_create_dialogue_req, NULL, MSG_ID_WAP_BAM_WMLS_CREATE_DIALOGUE_REQ, MOD_MMI);

}
#endif


/*****************************************************************************
 * FUNCTION
 *  bam_msg_show_auth_dialog_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  request_id      [IN]
 *  auth_type       [IN]
 *  realm           [IN]
 *  username        [IN]
 *  password        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
bam_msg_show_auth_dialog_ind(
    MSF_INT32 request_id,
    MSF_INT32 auth_type,
    const char *realm,
    const char *username,
    const char *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    wap_bam_show_auth_dialog_ind_struct *show_auth_dialog_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    show_auth_dialog_ind = (wap_bam_show_auth_dialog_ind_struct*)
        construct_local_para(sizeof(wap_bam_show_auth_dialog_ind_struct), TD_RESET);

    show_auth_dialog_ind->instance_id = (kal_int32) bam_sif_get_brs_id();
    show_auth_dialog_ind->request_id = (kal_int32) request_id;
    show_auth_dialog_ind->auth_type = (kal_int32) auth_type;

    len = 0;

    if (realm)
    {
        len = (strlen(realm) <= WAP_BAM_MAX_REALM_LENGTH) ? strlen(realm) : WAP_BAM_MAX_REALM_LENGTH;
        strncpy((char*)show_auth_dialog_ind->realm, realm, len);
    }
    show_auth_dialog_ind->realm[len] = '\0';

    len = 0;

    if (username)
    {
        len = (strlen(username) <= WAP_BAM_MAX_USER_PASSWD_LENGTH) ? strlen(username) : WAP_BAM_MAX_USER_PASSWD_LENGTH;
        strncpy((char*)show_auth_dialog_ind->username, username, len);
    }
    show_auth_dialog_ind->username[len] = '\0';

    len = 0;

    if (password)
    {
        len = (strlen(password) <= WAP_BAM_MAX_USER_PASSWD_LENGTH) ? strlen(password) : WAP_BAM_MAX_USER_PASSWD_LENGTH;
        strncpy((char*)show_auth_dialog_ind->password, password, len);
    }
    show_auth_dialog_ind->password[len] = '\0';

    bam_send_ilm(show_auth_dialog_ind, NULL, MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_IND, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_E4371F1FB0F011F05064073BFB9D5FE1,
                     "BAM: sent message MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_IND\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_wtai_tel_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  request_id		[IN]
 *  operation		[IN]
 *  param			[IN]
 *  param_len		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
bam_msg_wtai_tel_ind(
    MSF_UINT16 request_id,
	MSF_UINT16	operation,
    const char *param,
	MSF_INT32 param_len)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    wap_bam_wtai_tel_ind_struct *wtai_tel_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wtai_tel_ind = (wap_bam_wtai_tel_ind_struct*)
        construct_local_para(sizeof(wap_bam_wtai_tel_ind_struct), TD_RESET);

    wtai_tel_ind->instance_id = (kal_int32) bam_sif_get_brs_id();
    wtai_tel_ind->request_id = (kal_uint16) request_id;
	wtai_tel_ind->operation = (kal_uint16) operation;

	if ((param != NULL) && (param_len > 0))
	{
		if (param_len <= WAP_BAM_MAX_PHONE_NUMBER_LENGTH)
		{
			len = param_len;
		}
		else
		{
			len = WAP_BAM_MAX_PHONE_NUMBER_LENGTH;
		}
	}
	else
	{
		len = 0;
	}

    if (len > 0)
    {
        memcpy((void*)wtai_tel_ind->param, (void*)param, len);
    }
    wtai_tel_ind->param[len] = '\0';

    bam_send_ilm(wtai_tel_ind, NULL, MSG_ID_WAP_BAM_WTAI_TEL_IND, MOD_MMI);

	MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM,
                BAM_MSG_0EDFE807FAC438D983EC55374C86CA9F, "BAM: sent message MSG_ID_WAP_BAM_WTAI_TEL_IND\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_wtai_pb_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  request_id		[IN]
 *  name			[IN]
 *  name_len		[IN]
 *  number			[IN]
 *  number_len		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
bam_msg_wtai_pb_ind(
    MSF_UINT16 request_id,
    const char *name,
    MSF_INT32 name_len,
    const char *number,
    MSF_INT32 number_len)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    wap_bam_wtai_pb_ind_struct *wtai_pb_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wtai_pb_ind = (wap_bam_wtai_pb_ind_struct*)
        construct_local_para(sizeof(wap_bam_wtai_pb_ind_struct), TD_RESET);

    wtai_pb_ind->instance_id = (kal_int32) bam_sif_get_brs_id();
    wtai_pb_ind->request_id = (kal_uint16) request_id;

	if ((name != NULL) && (name_len > 0))
	{
		if (name_len <= WAP_BAM_MAX_USER_PASSWD_LENGTH)
		{
			len = name_len;
		}
		else
		{
			len = WAP_BAM_MAX_USER_PASSWD_LENGTH;
		}
	}
	else
	{
		len = 0;
	}

    if (len > 0)
    {
        memcpy((void*)wtai_pb_ind->name, (void*)name, len);
    }
    wtai_pb_ind->name[len] = '\0';

	if ((number != NULL) && (number_len > 0))
	{
		if (number_len <= WAP_BAM_MAX_PHONE_NUMBER_LENGTH)
		{
			len = number_len;
		}
		else
		{
			len = WAP_BAM_MAX_PHONE_NUMBER_LENGTH;
		}
	}
	else
	{
		len = 0;
	}

    if (len > 0)
    {
        memcpy((void*)wtai_pb_ind->number, (void*)number, len);
    }
    wtai_pb_ind->number[len] = '\0';

    bam_send_ilm(wtai_pb_ind, NULL, MSG_ID_WAP_BAM_WTAI_PB_IND, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, 
                     BAM_MSG_2E7659846735397B393BAA7877639397, "BAM: sent message MSG_ID_WAP_BAM_WTAI_PB_IND\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_uri_request_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  request_id		[IN]
 *  scheme			[IN]
 *  scheme_len		[IN]
 *  param			[IN]
 *  param_len		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
bam_msg_uri_request_ind(
    MSF_UINT16 request_id,
    const char *scheme,
	MSF_INT32 scheme_len,
    const char *param,
	MSF_INT32 param_len)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    wap_bam_uri_request_ind_struct *uri_request_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	uri_request_ind = (wap_bam_uri_request_ind_struct*)
        construct_local_para(sizeof(wap_bam_uri_request_ind_struct), TD_RESET);

    uri_request_ind->instance_id = (kal_int32) bam_sif_get_brs_id();
    uri_request_ind->request_id = (kal_uint16) request_id;

	if ((scheme != NULL) && (scheme_len > 0))
	{
		if (scheme_len <= WAP_BAM_MAX_SCHEME_LENGTH)
		{
			len = scheme_len;
		}
		else
		{
			len = WAP_BAM_MAX_SCHEME_LENGTH;
		}
	}
	else
	{
		len = 0;
	}

    if (len > 0)
    {
        memcpy((void*)uri_request_ind->scheme, (void*)scheme, len);
    }
    uri_request_ind->scheme[len] = '\0';

	if ((param != NULL) && (param_len > 0))
	{
		if (param_len <= WAP_BAM_MAX_URL_LEN)
		{
			len = param_len;
		}
		else
		{
			len = WAP_BAM_MAX_URL_LEN;
		}
	}
	else
	{
		len = 0;
	}

    if (param && param_len > 0)
    {
        memcpy((void*)uri_request_ind->param, (void*)param, len);
    }
    uri_request_ind->param[len] = '\0';

    bam_send_ilm(uri_request_ind, NULL, MSG_ID_WAP_BAM_URI_REQUEST_IND, MOD_MMI);

	MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM,
                BAM_MSG_1375A1CB0C7B9C679E9FB444AD73C453, "BAM: sent message MSG_ID_WAP_BAM_URI_REQUEST_IND\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_get_saved_pages_list_start_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  error_code      [IN]
 *  num_items       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_get_saved_pages_list_start_cnf(MSF_UINT16 error_code, MSF_INT16 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_start_cnf_struct *get_saved_pages_list_start_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_saved_pages_list_start_cnf =
        (wap_bam_get_saved_pages_list_start_cnf_struct*)
        construct_local_para(sizeof(wap_bam_get_saved_pages_list_start_cnf_struct), TD_RESET);

    get_saved_pages_list_start_cnf->instance_id = (kal_int32) bam_main_get_instance_id();
    get_saved_pages_list_start_cnf->error_code = error_code;    
    get_saved_pages_list_start_cnf->num_items = (kal_uint32) num_items;

    bam_send_ilm(get_saved_pages_list_start_cnf, NULL, MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_CNF, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_DCC8BF68850D6C0B99D283AF74F48439,
                     "BAM: sent message MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_CNF\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_get_saved_pages_list_continue_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  error_code      [IN]
 *  start_index     [IN]
 *  num_items       [IN]
 *  p               [?]
 * RETURNS
 *  void
 *****************************************************************************/
void
bam_msg_get_saved_pages_list_continue_cnf(MSF_UINT16 error_code, MSF_UINT32 start_index, MSF_UINT32 num_items, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_continue_cnf_struct *get_saved_pages_list_continue_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_saved_pages_list_continue_cnf =
        (wap_bam_get_saved_pages_list_continue_cnf_struct*)
        construct_local_para(sizeof(wap_bam_get_saved_pages_list_continue_cnf_struct), TD_RESET);

    get_saved_pages_list_continue_cnf->instance_id = (kal_int32) bam_main_get_instance_id();
    get_saved_pages_list_continue_cnf->error_code = (kal_uint16) error_code;
    get_saved_pages_list_continue_cnf->start_index = (kal_uint32) start_index;
    get_saved_pages_list_continue_cnf->num_items = (kal_uint32) num_items;

    bam_send_ilm(get_saved_pages_list_continue_cnf, p, MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_B9B67F2C46FF544B04EA73D443887C23,
                     "BAM: sent message MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_get_resources_list_continue_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  error_code      [IN]
 *  start_index     [IN]
 *  num_res         [IN]
 *  p               [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_get_resources_list_continue_cnf(MSF_UINT16 error_code, MSF_UINT32 start_index, MSF_UINT32 num_res, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resources_list_continue_cnf_struct *get_resources_list_continue_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_resources_list_continue_cnf =
        (wap_bam_get_resources_list_continue_cnf_struct*)
        construct_local_para(sizeof(wap_bam_get_resources_list_continue_cnf_struct), TD_RESET);

    get_resources_list_continue_cnf->instance_id = (kal_int32) bam_main_get_instance_id();
    get_resources_list_continue_cnf->error_code = (kal_uint16) error_code;
    get_resources_list_continue_cnf->start_index = (kal_uint32) start_index;
    get_resources_list_continue_cnf->num_res = (kal_uint32) num_res;

    bam_send_ilm(get_resources_list_continue_cnf, p, MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_6163B461FC9E873B7DCDF0F50E015922,
                     "BAM: sent message MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF\n"));
}

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_msg_get_recent_pages_list_continue_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  error_code      [IN]
 *  start_index     [IN]
 *  num_items       [IN]
 *  p               [?]
 * RETURNS
 *  void
 *****************************************************************************/
void
bam_msg_get_recent_pages_list_continue_cnf(MSF_UINT16 error_code, MSF_UINT32 start_index, MSF_UINT32 num_items, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_continue_cnf_struct *get_recent_pages_list_continue_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_recent_pages_list_continue_cnf =
        (wap_bam_get_recent_pages_list_continue_cnf_struct*)
        construct_local_para(sizeof(wap_bam_get_recent_pages_list_continue_cnf_struct), TD_RESET);

    get_recent_pages_list_continue_cnf->instance_id = (kal_int32) bam_main_get_instance_id();
    get_recent_pages_list_continue_cnf->error_code = (kal_uint16) error_code;
    get_recent_pages_list_continue_cnf->start_index = (kal_uint32) start_index;
    get_recent_pages_list_continue_cnf->num_items = (kal_uint32) num_items;

    bam_send_ilm(get_recent_pages_list_continue_cnf, p, MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_9C22CB8C4322AA22B87F97191285357A,
                     "BAM: sent message MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF\n"));
}


/*****************************************************************************
 * FUNCTION
 *  bam_msg_recent_page_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  error_code      [IN]
 *  p               [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_recent_page_cnf(MSF_UINT32 error_code, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_recent_page_cnf_struct *recent_page_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_FC10AADD15EFCB3E13FEBDC3B540A18F,
                     "BAM: sent message MSG_ID_WAP_BAM_RECENT_PAGE_CNF\n"));

    recent_page_cnf =
        (wap_bam_recent_page_cnf_struct*) construct_local_para(sizeof(wap_bam_recent_page_cnf_struct), TD_RESET);

    recent_page_cnf->instance_id = (kal_int32) bam_main_get_instance_id();

    switch (error_code)
    {
        case BAM_HIST_ERROR_OK:
            recent_page_cnf->error_code = (kal_uint32) WAP_BAM_ERROR_OK;
            break;

        case BAM_HIST_ERROR_NOT_FOUND:
            recent_page_cnf->error_code = (kal_uint32) WAP_BAM_ERROR_RECENT_PAGES_NOT_FOUND;
            break;

        default:
            recent_page_cnf->error_code = (kal_uint32) WAP_BAM_ERROR_RECENT_PAGES_FAILED;
    }

    if (p)
    {
        int len;
        kal_uint16 pdu_length = 0;
        bam_hist_ui_item_struct *recent_page_item = (bam_hist_ui_item_struct*) p;
        peer_buff_struct *peer_buff = construct_peer_buff(sizeof(wap_bam_recent_page_struct), 0, 0, TD_RESET);
        wap_bam_recent_page_struct *recent_page = (wap_bam_recent_page_struct*) get_pdu_ptr(peer_buff, &pdu_length);

        recent_page->timestamp = recent_page_item->timestamp;
        recent_page->hits = recent_page_item->hits;
        recent_page->url_hash = recent_page_item->url_hash;

        len = 0;

        if (recent_page_item->title)
        {
            len = (strlen(recent_page_item->title) <= WAP_BAM_MAX_TITLE_LABEL_LENGTH)
                ? strlen(recent_page_item->title) : WAP_BAM_MAX_TITLE_LABEL_LENGTH;
            strncpy(recent_page->title, recent_page_item->title, len);
        }
        recent_page->title[len] = '\0';

        len = 0;

        if (recent_page_item->url)
        {
            len = (strlen(recent_page_item->url) <= WAP_BAM_MAX_URL_LEN)
                ? strlen(recent_page_item->url) : WAP_BAM_MAX_URL_LEN;
            strncpy(recent_page->url, recent_page_item->url, len);
        }
        recent_page->url[len] = '\0';

        bam_send_ilm(recent_page_cnf, peer_buff, MSG_ID_WAP_BAM_RECENT_PAGE_CNF, MOD_MMI);
        return;
    }

    bam_send_ilm(recent_page_cnf, NULL, MSG_ID_WAP_BAM_RECENT_PAGE_CNF, MOD_MMI);
}

#endif /* recent pages */
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_msg_save_page_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  error_code      [IN]
 *  p               [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_save_page_cnf(MSF_UINT32 error_code, /*void *p*/char *title, char*url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_save_page_cnf_struct *save_page_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_007028B9C95FA87666E11AB23C59B784,
                     "BAM: sent message MSG_ID_WAP_BAM_SAVE_PAGE_CNF\n"));

    save_page_cnf =
        (wap_bam_save_page_cnf_struct*) construct_local_para(sizeof(wap_bam_save_page_cnf_struct), TD_RESET);

    save_page_cnf->instance_id = (kal_int32) bam_main_get_instance_id();

    switch (error_code)
    {
        case BAM_OFFLINE_STATUS_GET_OK:
        case BAM_OFFLINE_STATUS_SAVE_OK:
        case BAM_OFFLINE_STATUS_LOAD_OK:
        case BAM_OFFLINE_STATUS_DELETE_OK:
        case BAM_OFFLINE_STATUS_DELETE_ALL_OK:
        case BAM_OFFLINE_STATUS_RENAME_OK:
            save_page_cnf->error_code = (kal_uint32) WAP_BAM_ERROR_OK;
            break;

        case BAM_OFFLINE_STATUS_SAVE_ERR_EXISTS:
        case BAM_OFFLINE_STATUS_RENAME_ERR_EXISTS:
            save_page_cnf->error_code = (kal_uint32) WAP_BAM_ERROR_SAVED_PAGES_EXISTS;
            break;

        case BAM_OFFLINE_STATUS_SAVE_ERR_PARTIAL:
            save_page_cnf->error_code = (kal_uint32) WAP_BAM_ERROR_SAVED_PAGES_PARTIAL;
            break;

        case BAM_OFFLINE_STATUS_SAVE_ERR_LIMIT:
            save_page_cnf->error_code = (kal_uint32) WAP_BAM_ERROR_SAVED_PAGES_LIMIT_EXCEEDED;
            break;

        case BAM_OFFLINE_STATUS_ERR_NOT_FOUND:
            save_page_cnf->error_code = (kal_uint32) WAP_BAM_ERROR_SAVED_PAGES_NOT_FOUND;
            break;

        case BAM_OFFLINE_STATUS_SAVE_ERR_FAILED:
        case BAM_OFFLINE_STATUS_ERR_INTERNAL:
            
        default:
            save_page_cnf->error_code = (kal_uint32) WAP_BAM_ERROR_SAVED_PAGES_FAILED;
    }

#if 0
/* under construction !*/
#endif
    {
        int len = 0;
        kal_uint16 pdu_length = 0;
#if 0
/* under construction !*/
#endif
        peer_buff_struct *peer_buff = construct_peer_buff(sizeof(wap_bam_saved_page_struct), 0, 0, TD_RESET);
        wap_bam_saved_page_struct *saved_page = (wap_bam_saved_page_struct*) get_pdu_ptr(peer_buff, &pdu_length);

        saved_page->date = /*saved_page_item->date*/0;
        saved_page->doc_size = /*saved_page_item->docSize*/0;
        saved_page->data_size = /*saved_page_item->dataSize*/0;

        len = 0;

        if (/*saved_page_item->label*/title)
        {
            len = (strlen(/*saved_page_item->label*/title) <= WAP_BAM_MAX_TITLE_LABEL_LENGTH)
                ? strlen(/*saved_page_item->label*/title) : WAP_BAM_MAX_TITLE_LABEL_LENGTH;
            strncpy(saved_page->label, /*saved_page_item->label*/title, len);
        }
        saved_page->label[len] = '\0';

        len = 0;

        if (/*saved_page_item->*/url)
        {
            len = (strlen(/*saved_page_item->*/url) <= WAP_BAM_MAX_URL_LEN)
                ? strlen(/*saved_page_item->*/url) : WAP_BAM_MAX_URL_LEN;
            strncpy(saved_page->url, /*saved_page_item->*/url, len);
        }
        saved_page->url[len] = '\0';

        bam_send_ilm(save_page_cnf, peer_buff, MSG_ID_WAP_BAM_SAVE_PAGE_CNF, MOD_MMI);
        return;
    }

    bam_send_ilm(save_page_cnf, NULL, MSG_ID_WAP_BAM_SAVE_PAGE_CNF, MOD_MMI);
}
#endif


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
#endif

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_msg_get_recent_pages_list_start_cnf
 * DESCRIPTION
 *
 * PARAMETERS
 *  error_code      [IN]
 *  num_item        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_msg_get_recent_pages_list_start_cnf(MSF_UINT16 error_code, MSF_INT16 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_start_cnf_struct *get_recent_pages_list_start_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_recent_pages_list_start_cnf =
        (wap_bam_get_recent_pages_list_start_cnf_struct*)
        construct_local_para(sizeof(wap_bam_get_recent_pages_list_start_cnf_struct), TD_RESET);

    get_recent_pages_list_start_cnf->instance_id = (kal_int32) bam_main_get_instance_id();
    get_recent_pages_list_start_cnf->error_code = (kal_uint16) error_code;
    get_recent_pages_list_start_cnf->num_item = (kal_uint32) num_item;

    bam_send_ilm(get_recent_pages_list_start_cnf, NULL, MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_CNF, MOD_MMI);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_502527D58534FF60CB8C3D4D54923734,
                     "BAM: sent message MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_CNF\n"));
}
#endif 

/*
 * SAP message handling functions
 */

void bam_msg_conn_closed_by_net_acc_id_rsp()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_conn_closed_by_net_acc_id_rsp_struct *conn_closed_by_net_acc_id_rsp;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    conn_closed_by_net_acc_id_rsp= (wap_bam_conn_closed_by_net_acc_id_rsp_struct*)
        construct_local_para(sizeof(wap_bam_conn_closed_by_net_acc_id_rsp_struct), TD_RESET);
    conn_closed_by_net_acc_id_rsp->instance_id = (kal_int32) bam_main_get_instance_id();

    bam_send_ilm(conn_closed_by_net_acc_id_rsp, NULL,MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_RSP, MOD_MMI);

	MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_3E35DCBBA68A490967E33E4C698AC532, "BAM: sent message MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_RSP\n"));



}

extern MSF_BOOL bam_main_terminating;
extern MSF_BOOL bam_app_request_to_create_brs;
extern MSF_BOOL bam_app_request_to_delete_brs;

/*****************************************************************************
 * FUNCTION
 *  bam_create_instance_req_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  src_mod_id              [IN]
 *  create_instance_req     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void
bam_create_instance_req_hdlr(module_type src_mod_id, wap_bam_create_instance_req_struct *create_instance_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif

	if (bam_app_request_to_create_brs == TRUE || bam_app_request_to_delete_brs == TRUE)
	{
		/* 
		 * Error handling: BAM will do nothing in below cases.
		 * (1) BAM receives MSG_ID_WAP_BAM_CREATE_INSTANCE_REQ more than once 
		 *     before BAM responds MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF.
		 * (2) BAM receives MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF during deleting
		 *     BRS instance.
		 */
		return;
	}
//widget_init_structure();
//    bam_app_request_to_create_brs = TRUE;
    bam_sif_set_full_screen_mode((MSF_BOOL)create_instance_req->is_full_screen);
    bam_main_create_instance();
    bam_msg_create_instance_cnf(bam_main_get_instance_id(), WAP_BAM_ERROR_OK);

    /* Notify Widget of the current category screen information, including layer
       handle used and what area to draw. */
    HDIa_widgetDeviceSetProperties(
        create_instance_req->window_position_x,
        create_instance_req->window_position_y,
        create_instance_req->window_size_width,
        create_instance_req->window_size_height,
        create_instance_req->category_lyr_a_hndl,
        create_instance_req->category_lyr_b_hndl);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  bam_handle_message
 * DESCRIPTION
 *  This function dispatch external message received.
 *  NOTE: Do not process the message directly as this function is not in the
 *  execution thread and will cause inconsistent state in scheduler.
 *  The actual process should be performed in BAMc_run().
 * PARAMETERS
 *  p               [?]
 *  ilm_ptr(?)      [IN]        Received Message
 * RETURNS
 *  1 if the message is handled, 0 if it is not handled by the module.
 *****************************************************************************/
int bam_handle_message(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 1;
    ilm_struct *ilm_ptr = (ilm_struct*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_WAP_BAM_CREATE_INSTANCE_REQ:
        {
            wap_bam_create_instance_req_struct *create_instance_req =
                (wap_bam_create_instance_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_0CCE6AECF630AB8224C3CF88523EC780,
                             "BAM: received message MSG_ID_WAP_BAM_CREATE_INSTANCE_REQ\n"));

            bam_create_instance_req_hdlr(ilm_ptr->src_mod_id, create_instance_req);
        }
            break;

        case MSG_ID_WAP_BAM_DELETE_INSTANCE_REQ:
        {
            wap_bam_delete_instance_req_struct *delete_instance_req =
                (wap_bam_delete_instance_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_D5CB47279CB32D657D9959845654011D,
                             "BAM: received message MSG_ID_WAP_BAM_DELETE_INSTANCE_REQ\n"));

            BAMif_deleteInstance(delete_instance_req->instance_id);
        }
            break;
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
#endif

        case MSG_ID_WAP_BAM_LOAD_URL_REQ:
        {
            wap_bam_load_url_req_struct *load_url_req = (wap_bam_load_url_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_792ED55E7388D3DE3E80A9DBEFACD24C,
                             "BAM: received message MSG_ID_WAP_BAM_LOAD_URL_REQ\n"));

            BAMif_loadUrl(
                MSF_MODID_BAM,
                load_url_req->instance_id,
                load_url_req->options,
                load_url_req->charset,
                load_url_req->url);
            mmi_brw_app_if_load_url_req_processed();
        }
            break;

        case MSG_ID_WAP_BAM_LOAD_DATA_REQ:
        {
            wap_bam_load_data_req_struct *load_data_req = (wap_bam_load_data_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_235065FE5F47C5D5948F14B18B281637,
                             "BAM: received message MSG_ID_WAP_BAM_LOAD_DATA_REQ\n"));

            BAMif_loadData(
                MSF_MODID_BAM,
                load_data_req->instance_id,
                load_data_req->options,
                load_data_req->charset,
                load_data_req->content_path);
        }
            break;

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
        case MSG_ID_WAP_BAM_ACTIVATE_DO_ELEMENT_REQ:
        {
            wap_bam_activate_do_element_req_struct *activate_do_element_req = (wap_bam_activate_do_element_req_struct*)
                ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_B2182C113F47B366B38574E75131AE77,
                             "BAM: received message MSG_ID_WAP_BAM_ACTIVATE_DO_ELEMENT_REQ\n"));

            BAMif_activateDoElement(
                MSF_MODID_BAM,
                activate_do_element_req->instance_id,
                activate_do_element_req->element_id);
        }
            break;
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */

        case MSG_ID_WAP_BAM_MOVE_REQ:
        {
            wap_bam_move_req_struct *move_req = (wap_bam_move_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_F055F795B96DE577E353EF30C961BC6C,
                             "BAM: received message MSG_ID_WAP_BAM_MOVE_REQ\n"));

            BAMif_move(MSF_MODID_BAM, move_req->instance_id, move_req->direction, move_req->steps);
        }
            break;

        case MSG_ID_WAP_BAM_RELOAD_REQ:
        {
            wap_bam_reload_req_struct *reload_req = (wap_bam_reload_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_FF2F891EEA8BDF7CAAE0EF79BE7F40C2,
                             "BAM: received message MSG_ID_WAP_BAM_RELOAD_REQ\n"));
            mmi_brw_app_if_reload_req_processed();

            BAMif_reload(MSF_MODID_BAM, reload_req->instance_id);
        }
            break;

        case MSG_ID_WAP_BAM_STOP_REQ:
        {
            wap_bam_stop_req_struct *stop_req = (wap_bam_stop_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_226519D29893D533895D0861CE8BCA69,
                             "BAM: received message MSG_ID_WAP_BAM_STOP_REQ\n"));

            BAMif_stop(MSF_MODID_BAM, stop_req->instance_id);
        }
            break;

        case MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ:
        {
            wap_bam_navigation_change_req_struct *navigation_change_req =
                (wap_bam_navigation_change_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_7600C77E07E1D2CF31BA088DC2BEE5AC,
                             "BAM: received message MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ\n"));

            BAMif_navigationChange(MSF_MODID_BAM, navigation_change_req->instance_id, navigation_change_req->elements);
        }
            break;

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
        case MSG_ID_WAP_BAM_SAVE_PAGE_REQ:
        {
            wap_bam_save_page_req_struct *save_page_req = (wap_bam_save_page_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_6DBA248B70067C33ED7E523D2AC41A8F,
                             "BAM: received message MSG_ID_WAP_BAM_SAVE_PAGE_REQ\n"));

            BAMif_savePage(MSF_MODID_BAM, save_page_req->instance_id, save_page_req->overwrite, save_page_req->label, save_page_req->url);
        }
            break;

        case MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ:
        {
            wap_bam_get_saved_page_req_struct *get_saved_page_req =
                (wap_bam_get_saved_page_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_68A03122B88ECC24CBF71C7FD8DFB68A,
                             "BAM: received message MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ\n"));

            BAMif_getSavedPage(MSF_MODID_BAM, get_saved_page_req->instance_id, get_saved_page_req->index);
        }
            break;

        case MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ:
        {
            wap_bam_load_saved_page_req_struct *load_saved_page_req =
                (wap_bam_load_saved_page_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_1CE0546B198337821BA02DF88A0EE6EF,
                             "BAM: received message MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ\n"));

            BAMif_loadSavedPage(MSF_MODID_BAM, load_saved_page_req->instance_id, load_saved_page_req->index);
        }
            break;

        case MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ:
        {
            wap_bam_delete_saved_page_req_struct *delete_saved_page_req =
                (wap_bam_delete_saved_page_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_29E76851240341AC9DF5AF274B8B19DF,
                             "BAM: received message MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ\n"));

            BAMif_deleteSavedPage(MSF_MODID_BAM, delete_saved_page_req->instance_id, delete_saved_page_req->index);
        }
            break;

		case MSG_ID_WAP_BAM_DELETE_N_SAVED_PAGE_REQ:
        {
            wap_bam_delete_n_saved_page_req_struct *delete_n_saved_page_req =
                (wap_bam_delete_n_saved_page_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_29E76851240341AC9DF5AF274B8B19DF,
                             "BAM: received message MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ\n"));

            BAMif_deleteNSavedPage(MSF_MODID_BAM, delete_n_saved_page_req->instance_id, delete_n_saved_page_req->index_array,delete_n_saved_page_req->count); //pareek
            OslMfree(delete_n_saved_page_req->index_array);
        }
            break;

        case MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ:
        {
            wap_bam_delete_all_saved_pages_req_struct *delete_all_saved_pages_req =
                (wap_bam_delete_all_saved_pages_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_D89A6C787B1CCC952D66EF63420F2DCC,
                             "BAM: received message MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ\n"));

            BAMif_deleteAllSavedPage(MSF_MODID_BAM, delete_all_saved_pages_req->instance_id);
        }
            break;
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
#endif
        case MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_REQ:
        {
            wap_bam_get_saved_pages_list_start_req_struct *get_saved_pages_list_start_req =
                (wap_bam_get_saved_pages_list_start_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_4C5B6F1EE85D60F672DC49B4FBFC529F,
                             "BAM: received message MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_REQ\n"));

            BAMif_getSavedPagesListStart(MSF_MODID_BAM, get_saved_pages_list_start_req->instance_id);
        }
            break;

        case MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_REQ:
        {
            wap_bam_get_saved_pages_list_continue_req_struct *get_saved_pages_list_continue_req =
                (wap_bam_get_saved_pages_list_continue_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_62F9AFF289D8255D200D813D367AD1D4,
                             "BAM: received message MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_REQ\n"));

            BAMif_getSavedPagesListContinue(
                MSF_MODID_BAM,
                get_saved_pages_list_continue_req->instance_id,
                get_saved_pages_list_continue_req->start_index);
        }
            break;

        case MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_END_REQ:
        {
            wap_bam_get_saved_pages_list_end_req_struct *get_saved_pages_list_end_req =
                (wap_bam_get_saved_pages_list_end_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_4FEBA8BAB0525A1333628AF98D2E35FA,
                             "BAM: received message MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_END_REQ\n"));

            BAMif_getSavedPagesListEnd(MSF_MODID_BAM, get_saved_pages_list_end_req->instance_id);
        }
            break;
#endif
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
#endif
        /*
         * case MSG_ID_WAP_BAM_NAVIGATE_TO_HOTSPOT_REQ:
         * {
         * wap_bam_navigate_to_hotspot_req_struct *navigate_to_hotspot_req =
         * (wap_bam_navigate_to_hotspot_req_struct *) ilm_ptr->local_para_ptr;
         *
         * MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_3E35DCBBA68A490967E33E4C698AC532, "BAM: received message MSG_ID_WAP_BAM_NAVIGATE_TO_HOTSPOT_REQ\n"));
         *
         *
         * BAMif_navigateToHotspot (MSF_MODID_BAM,
         * navigate_to_hotspot_req->instance_id,
         * navigate_to_hotspot_req->direction);
         * }
         * break;
         */
//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
        case MSG_ID_WAP_BAM_CHANGE_SETTING_VALUE_REQ:
        {
            wap_bam_change_setting_value_req_struct *change_setting_value_req =
                (wap_bam_change_setting_value_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_DBF3187E364639CFE837324D04FC710D,
                             "BAM: received message MSG_ID_WAP_BAM_CHANGE_SETTING_VALUE_REQ\n"));
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
#endif

            BAMif_changeSettingValue(
                MSF_MODID_BAM,
                change_setting_value_req->instance_id,
                change_setting_value_req->type,
                change_setting_value_req->setting_id,
                change_setting_value_req->value_i,
                (char*)change_setting_value_req->value_bv);
        }
            break;
//#endif

#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
		case MSG_ID_WAP_BAM_WMLS_CREATE_DIALOGUE_RSP:
		{
            wap_bam_wmls_create_dialogue_rsp_struct *create_dialogue_rsp =
                (wap_bam_wmls_create_dialogue_rsp_struct*) ilm_ptr->local_para_ptr;

			BAMif_wmls_create_dialogue_rsp(
                MSF_MODID_BAM,
                create_dialogue_rsp->instance_id,
                create_dialogue_rsp->dialup_type,
                create_dialogue_rsp->result,
                create_dialogue_rsp->msg);
            break;
		}
           
#endif

        case MSG_ID_WAP_BAM_SET_PROFILE_REQ:
        {
            wap_bam_set_profile_req_struct *set_profile_req =
                (wap_bam_set_profile_req_struct*) ilm_ptr->local_para_ptr;
            MSF_INT32 *int_value_table = (set_profile_req->profile) ? (MSF_INT32 *)set_profile_req->profile->int_value_table : NULL;
			
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_15F867B2192040CDBCAE82A2D85F34C5,
                             "BAM: received message MSG_ID_WAP_BAM_SET_PROFILE_REQ\n"));

			if (int_value_table)
			{
				switch (int_value_table[wap_bam_setting_id_no_mime])
				{
					case bam_setting_val_always:
						int_value_table[wap_bam_setting_id_no_mime] = bam_setting_val_always;				
					break;
					case bam_setting_val_ask:
						int_value_table[wap_bam_setting_id_no_mime] = bam_setting_val_ask;
					break;

					default:
						int_value_table[wap_bam_setting_id_no_mime] = bam_setting_val_never;
				}
			}

            BAMif_setProfile(
                MSF_MODID_BAM,
                set_profile_req->instance_id,
                set_profile_req->request_id,
                set_profile_req->setting_id,
				set_profile_req->type,
                (bam_profile_setting_struct*) set_profile_req->profile);

            bam_msg_free_profile(set_profile_req->profile);
            set_profile_req->profile = NULL;
        }
            break;
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
        case MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ:
        {
            wap_bam_get_recent_pages_list_start_req_struct *get_recent_pages_list_start_req =
                (wap_bam_get_recent_pages_list_start_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_FACD81E9F27CC3C8011550C495EC34FB,
                             "BAM: received message MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ\n"));

            BAMif_getRecentPagesListStart(
                MSF_MODID_BAM,
                get_recent_pages_list_start_req->instance_id,
                get_recent_pages_list_start_req->sort_option);
        }
            break;

        case MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ:
        {
            wap_bam_get_recent_pages_list_continue_req_struct *get_recent_pages_list_continue_req =
                (wap_bam_get_recent_pages_list_continue_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_A1F2D5B7882DFCB461704DDDCDF6B7ED,
                             "BAM: received message MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ\n"));

            BAMif_getRecentPagesListContinue(
                MSF_MODID_BAM,
                get_recent_pages_list_continue_req->instance_id,
                get_recent_pages_list_continue_req->start_index);
        }
            break;

        case MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_END_REQ:
        {
            wap_bam_get_recent_pages_list_end_req_struct *get_recent_pages_list_end_req =
                (wap_bam_get_recent_pages_list_end_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_16CD0D591EE99A928404A688FC1154EF,
                             "BAM: received message MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_END_REQ\n"));

            BAMif_getRecentPagesListEnd(MSF_MODID_BAM, get_recent_pages_list_end_req->instance_id);
        }
            break;

        case MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ:
        {
            wap_bam_get_recent_page_req_struct *get_recent_page_req =
                (wap_bam_get_recent_page_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_27AE602A1378A9FF644D107350A3DF7B,
                             "BAM: received message MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ\n"));

            BAMif_getRecentPage(MSF_MODID_BAM, get_recent_page_req->instance_id, get_recent_page_req->index);
        }
            break;

        case MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ:
        {
            wap_bam_load_recent_page_req_struct *load_recent_page_req =
                (wap_bam_load_recent_page_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_7BF590876B1564F53EA0C7F3CB38D79C,
                             "BAM: received message MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ\n"));

            BAMif_loadRecentPage(
                MSF_MODID_BAM,
                load_recent_page_req->instance_id,
                load_recent_page_req->charset,
                load_recent_page_req->index);
        }
            break;

        case MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ:
        {
            wap_bam_delete_recent_page_req_struct *delete_recent_page_req =
                (wap_bam_delete_recent_page_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_E73499B10373E6E609FAA22BCD19EC1B,
                             "BAM: received message MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ\n"));

            BAMif_deleteRecentPage(MSF_MODID_BAM, delete_recent_page_req->instance_id, delete_recent_page_req->index);
        }
            break;

		case MSG_ID_WAP_BAM_DELETE_N_RECENT_PAGE_REQ:
        {
            wap_bam_delete_n_recent_page_req_struct *delete_n_recent_page_req =
                (wap_bam_delete_n_recent_page_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_E73499B10373E6E609FAA22BCD19EC1B,
                             "BAM: received message MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ\n"));

            BAMif_deleteNRecentPage(MSF_MODID_BAM, delete_n_recent_page_req->instance_id, delete_n_recent_page_req->index_array , delete_n_recent_page_req->count );
            OslMfree(delete_n_recent_page_req->index_array);
        }
            break;

        case MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ:
        {
            wap_bam_delete_all_recent_pages_req_struct *delete_all_recent_pages_req =
                (wap_bam_delete_all_recent_pages_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_D6D6076936631F99049858E919212C6E,
                             "BAM: received message MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ\n"));

            BAMif_deleteAllRecentPage(MSF_MODID_BAM, delete_all_recent_pages_req->instance_id);
        }
            break;
#endif /*recent pages */

        case MSG_ID_WAP_BAM_REGISTER_KEYPAD_HANDLER_REQ:
        {
            wap_bam_register_keypad_handler_req_struct *register_keypad_handler_req =
                (wap_bam_register_keypad_handler_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_B0A6FBD4E8CA6C8FD6F86747547374C3,
                             "BAM: received message MSG_ID_WAP_BAM_REGISTER_KEYPAD_HANDLER_REQ\n"));

            BAMif_registerKeypadHandler(MSF_MODID_BAM, register_keypad_handler_req->instance_id);
        }
            break;
#ifdef __MMI_TOUCH_SCREEN__
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
#endif
#endif

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
#endif

        case MSG_ID_WAP_BAM_NOTIFY_SCREEN_INFO_REQ:
        {
            wap_bam_notify_screen_info_req_struct *notify_screen_info_req =
                (wap_bam_notify_screen_info_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_C460B5FB83F70589FAA434C6A57283E5,
                             "BAM: received message MSG_ID_WAP_BAM_NOTIFY_SCREEN_INFO_REQ\n"));

            BAMif_notifyScreenInfo(
                MSF_MODID_BAM,
                notify_screen_info_req->instance_id,
                notify_screen_info_req->x,
                notify_screen_info_req->y,
                notify_screen_info_req->w,
                notify_screen_info_req->h,
                notify_screen_info_req->category_lyr_a_hndl,
                notify_screen_info_req->category_lyr_b_hndl);
        }
            break;
#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
        case MSG_ID_WAP_BAM_SELECT_FILE_RSP:
        {
            wap_bam_select_file_rsp_struct *select_file_rsp = (wap_bam_select_file_rsp_struct*) ilm_ptr->local_para_ptr;

			MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_BB434F768CF5574887CD13A2B1ADD133, "BAM: received message MSG_ID_WAP_BAM_SELECT_FILE_RSP\n"));

            BAMif_selectFileRsp(MSF_MODID_BAM, select_file_rsp->instance_id, select_file_rsp->request_id, select_file_rsp->error_code, select_file_rsp->filename);
        }
            break;
#endif
/*
        case MSG_ID_WAP_BAM_WTAI_TEL_RSP:
        {
            wap_bam_wtai_tel_rsp_struct *wtai_tel_rsp = (wap_bam_wtai_tel_rsp_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_D62D08B683814E319333A1AFDACEE0A9,
                             "BAM: received message MSG_ID_WAP_BAM_WTAI_TEL_RSP\n"));

            BAMif_wtaiTelRsp(MSF_MODID_BAM, wtai_tel_rsp->request_id, wtai_tel_rsp->operation, wtai_tel_rsp->error_code);
        }
            break;

        case MSG_ID_WAP_BAM_WTAI_PB_RSP:
        {
            wap_bam_wtai_pb_rsp_struct *wtai_pb_rsp = (wap_bam_wtai_pb_rsp_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_CE8B37647F7802E29B05E8ED8011E628,
                             "BAM: received message MSG_ID_WAP_BAM_WTAI_PB_RSP\n"));

			BAMif_wtaiPbRsp(MSF_MODID_BAM, wtai_pb_rsp->request_id, wtai_pb_rsp->error_code);
        }
            break;*/

        case MSG_ID_WAP_BAM_URI_REQUEST_RSP:
        {
            wap_bam_uri_request_rsp_struct *uri_request_rsp =
                (wap_bam_uri_request_rsp_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_C5032E44435CAB90E33634D0098C10DE,
                             "BAM: received message MSG_ID_WAP_BAM_URI_REQUEST_RSP\n"));

			BAMif_uriRequestRsp(MSF_MODID_BAM, uri_request_rsp->request_id, uri_request_rsp->error_code);
        }
            break;

        case MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP:
        {
            wap_bam_wait_user_action_rsp_struct *wait_user_action_rsp =
                (wap_bam_wait_user_action_rsp_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_ADC599A2AAC66D79DC1EF8DE21148EF8,
                             "BAM: received message MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP\n"));

            BAMif_waitUserActionRsp(
                MSF_MODID_BAM,
                wait_user_action_rsp->instance_id,
                wait_user_action_rsp->press_positive_sk);
        }
            break;

        case MSG_ID_WAP_BAM_OBJECT_ACTION_REQ:
        {
            wap_bam_object_action_req_struct *object_action_req =
                (wap_bam_object_action_req_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_170C871117D5EB97C69FC0E8345D3F79,
                             "BAM: received message MSG_ID_WAP_BAM_OBJECT_ACTION_REQ\n"));

            BAMif_objectAction(MSF_MODID_BAM, object_action_req->instance_id, object_action_req->type);
        }
            break;

        case MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_RSP:
        {
            wap_bam_show_auth_dialog_rsp_struct *show_auth_dialog_rsp =
                (wap_bam_show_auth_dialog_rsp_struct*) ilm_ptr->local_para_ptr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_F9AD132F78F2E4ADC588C4389F084766,
                             "BAM: received message MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_RSP\n"));

            if (show_auth_dialog_rsp->options > 0)
            {
                BAMif_showAuthDialogRsp(
                    MSF_MODID_BAM,
                    show_auth_dialog_rsp->instance_id,
                    show_auth_dialog_rsp->request_id,
                    (MSF_UINT16) (show_auth_dialog_rsp->options - WAP_BAM_AUTH_OPTIONS_SAVE_NOTHING),
                    show_auth_dialog_rsp->username,
                    show_auth_dialog_rsp->password);
            }
            else
            {
                BAMif_showAuthDialogRsp(
                    MSF_MODID_BAM,
                    show_auth_dialog_rsp->instance_id,
                    show_auth_dialog_rsp->request_id,
                    0,
                    NULL,
                    NULL);
            }
        }
            break;

		case MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_REQ:
			{
			STKif_closeConnectionsByNetAccId(MSF_MODID_BAM, bam_get_net_acc_id());
			MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_CE8B37647F7802E29B05E8ED8011E628,
                             "BAM: received message MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_REQ\n"));
			}
			break;

		case MSG_ID_WAP_BAM_BEARER_OPEN_RSP:
			{
                wap_bam_bearer_open_response_rsp_struct *bearer_open_rsp_struct=
					(wap_bam_bearer_open_response_rsp_struct*) ilm_ptr->local_para_ptr;
				
				BAMif_BearerOpenRsp(MSF_MODID_BAM, bearer_open_rsp_struct->error_code, bearer_open_rsp_struct->instance_id);
			}
			break;


        default:
            /*
             * MSF_LOG_MSG_OFF ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_BAM, BAM_MSG_AE285F2D5B18B0CABC6B645BF0E5EAE2, "BAM: received unknown message\n"));
             */
            return FALSE;
    }   /* switch (ilm_ptr->msg_id) */

    if (ret)
    {
        /* Need to process the message received, set bam_wants_to_run to TRUE. */
        bam_wants_to_run = TRUE;
    }

    return TRUE;
}


#endif /*OBIGO_Q03C_BROWSER*/
