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
*  ProvBoxMain.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file implements intializations and all job handling. 
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "gui_data_types.h"
#include "fs_type.h"
#include "Unicodexdcl.h"
#include "fs_func.h"
#include "stdlib.h"
#include "fs_errcode.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "mmi_inet_app_trc.h"
#include "kal_public_api.h"
#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h"
#include "stack_config.h"

#include "Custom_ProvBox.h"
#include "ProvBoxSrvConfig.h"
#include "ProvBoxSrvProt.h"
#include "ProvBoxSrvGProt.h"
#include "ProvBoxSrvIProt.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
  
#define SRV_PROVBOX_FILE_FIND_ALL_NAME_PATTERN          L"*.ck"

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

typedef struct
{
    KAL_ADM_ID adm_id;
    U32 max_alloc_size;
    U32 total_left_size;
    U8 pool[SRV_PROVBOX_MEM_POOL_SIZE]; /* 4-bytes aligned */
} srv_provbox_mem_cntx_struct;

typedef struct
{
    srv_provbox_job_type_enum job_type;
    srv_provbox_job_sub_type_enum sub_type;
    S32 int_value;
}srv_provbox_init_job_info_struct;

typedef srv_provbox_result_enum (*SRV_PROVBOX_JOB_HDLR)(srv_provbox_cntx_struct *cntx, srv_provbox_job_struct *job);

typedef struct
{
 //   srv_provbox_job_type_enum  job_type;   /* Remark it as it can be array index */
    SRV_PROVBOX_JOB_HDLR hdlr;
}srv_provbox_job_hdlr_item_struct;




/*----------------------------------------------------------------------------*/
/* Static function declaration                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------Memory------------------------------------------------*/

static void srv_provbox_mem_init(void);

static void *srv_provbox_mem_malloc(U32 size);

static void srv_provbox_mem_free(void *p);

static srv_provbox_result_enum srv_provbox_mem_try_reclaim_memory(srv_provbox_cntx_struct *cntx, MMI_BOOL format_all);

static srv_provbox_result_enum srv_provbox_format_msg_list_section(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_box_type_enum box_type,
                                MMI_BOOL format_all);

static void srv_provbox_mem_send_mem_full_event(srv_provbox_cntx_struct *cntx);

static srv_provbox_cntx_struct *srv_provbox_cntx_init(void);

static S32 srv_provbox_cntx_get_hfile_by_file_id(srv_provbox_cntx_struct *cntx, srv_provbox_file_id_enum file_id);

static srv_provbox_job_struct *srv_provbox_job_create_new_job(
                                srv_provbox_job_type_enum job_type,
                                srv_provbox_job_sub_type_enum sub_type,
                                int src_mod,
                                S32 int_value,
                                void *req_data,
                                void *cnf_data,
                                MMI_BOOL hold_ctrl_buff);

static void srv_provbox_job_free_job(srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_append_new_job(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_type_enum job_type,
                                srv_provbox_job_sub_type_enum sub_type,
                                int src_mod,
                                S32 int_value,
                                void *req_data,
                                MMI_BOOL hold_ctrl_buff);

static void srv_provbox_handle_mem_full(srv_provbox_cntx_struct *cntx, srv_provbox_job_struct *job);

static void srv_provbox_handle_disk_full(srv_provbox_cntx_struct *cntx, srv_provbox_job_struct *job);

static void srv_provbox_handle_save_msg_fail(srv_provbox_cntx_struct *cntx, srv_provbox_job_struct *job);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void srv_provbox_job_submit_all_init_job(srv_provbox_cntx_struct *cntx);

static srv_provbox_result_enum srv_provbox_job_async_process_job(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_process_current_job_done(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_msg_list_struct *srv_provbox_cntx_get_msg_list_by_msg_id(
                                        srv_provbox_cntx_struct *cntx,
                                        U32 msg_id,
                                        U32 *index);

static void srv_provbox_cntx_get_init_next_msg_id(srv_provbox_cntx_struct *cntx);

static srv_provbox_result_enum srv_provbox_job_init_check_version_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_init_load_check_data_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_init_record_list_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_init_msg_list_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_init_check_msg_list_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_check_restore_factory(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_delete_sim_message(srv_provbox_cntx_struct *cntx);

static srv_provbox_result_enum srv_provbox_job_check_delete_all(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_delete_all_invalid_msg(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_delete_invalid_msg(
                                srv_provbox_cntx_struct *cntx,
                                U32 msg_id,
                                U16 *filename);

static srv_provbox_result_enum srv_provbox_force_delete_msg_by_id(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_box_type_enum box_type,
                                U32 msg_id);
/*
static MMI_BOOL srv_provbox_job_check_defrag_file(srv_provbox_cntx_struct *cntx);


static srv_provbox_result_enum srv_provbox_job_defrag_file_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);
*/

static srv_provbox_result_enum srv_provbox_job_save_ext_msg_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_show_ext_msg_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_save_msg_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_accept_new_msg(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_save_msg_req_struct *req_data);

static srv_provbox_result_enum srv_provbox_job_get_msg_data_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);
/*
static srv_provbox_result_enum srv_provbox_job_get_msg_num_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_get_msg_sort_info_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);


static srv_provbox_result_enum srv_provbox_job_get_msg_list_info_by_id_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_get_msg_list_info_by_index_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);


static srv_provbox_result_enum srv_provbox_job_multi_op_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_delete_msg_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_delete_all_msg_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);
*/

static srv_provbox_result_enum srv_provbox_job_save_and_show_ext_msg(srv_provbox_cntx_struct *cntx, MMI_BOOL try_save);

static MMI_BOOL srv_provbox_job_is_all_box_cleaned(srv_provbox_cntx_struct *cntx);

static srv_provbox_result_enum srv_provbox_job_set_msg_flag_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_get_msg_info_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static srv_provbox_result_enum srv_provbox_job_update_msg_info_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job);

static void srv_provbox_send_srv_ready_event(srv_provbox_cntx_struct *cntx);


#if defined(__MMI_UM_CONVERSATION_BOX__)&& defined(__MMI_PROV_IN_UM__)
static void srv_provbox_um_traverse_get_msg_info_by_index(srv_um_traverse_msg_req_struct *data);

static void srv_provbox_um_traverse_get_msg_info_by_ids(srv_um_traverse_msg_req_struct *data);

static void srv_provbox_um_traverse_msg_info_hdlr(
                U32 hdlr_msg_num, 
                MMI_BOOL is_more_msg, 
                S16 *msg_size_list,
                srv_provbox_msg_cmn_info_struct *msg_cmn_info,
                srv_um_traverse_msg_req_struct *data);
                
static MMI_BOOL srv_provbox_um_traverse_unexception_hdlr(srv_um_traverse_msg_req_struct *data);

#endif /* __MMI_UM_CONVERSATION_BOX__ && __MMI_PROV_IN_UM__ */

static void srv_provbox_get_msg_info_by_ids(srv_provbox_msg_info_struct *msg_info);



/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

static srv_provbox_mem_cntx_struct g_provbox_mem_cntx;

static srv_provbox_cntx_struct *g_provbox_cntx_p;

static const srv_provbox_init_job_info_struct g_srv_provbox_init_job_info_tbl[] = 
{   
    /* Version & Data check */
    {SRV_PROVBOX_JOB_TYPE_INIT_CHECK_VERSION,   SRV_PROVBOX_JOB_SUB_TYPE_CHECK_FOLDER,      0},
    {SRV_PROVBOX_JOB_TYPE_INIT_LOAD_CHECK_DATA, SRV_PROVBOX_JOB_SUB_TYPE_CHECK_RESTORE,     0},

    /* Load record data to record list */
    {SRV_PROVBOX_JOB_TYPE_INIT_RECORD_LIST,     SRV_PROVBOX_JOB_SUB_TYPE_NONE, (S32) SRV_PROVBOX_FILE_ID_IMSG_INFO_DATA},
    {SRV_PROVBOX_JOB_TYPE_INIT_RECORD_LIST,     SRV_PROVBOX_JOB_SUB_TYPE_NONE, (S32) SRV_PROVBOX_FILE_ID_IMSG_APP_DATA},
    
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    {SRV_PROVBOX_JOB_TYPE_INIT_RECORD_LIST,     SRV_PROVBOX_JOB_SUB_TYPE_NONE, (S32) SRV_PROVBOX_FILE_ID_AMSG_INFO_DATA},
    {SRV_PROVBOX_JOB_TYPE_INIT_RECORD_LIST,     SRV_PROVBOX_JOB_SUB_TYPE_NONE, (S32) SRV_PROVBOX_FILE_ID_AMSG_APP_DATA},
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    {SRV_PROVBOX_JOB_TYPE_INIT_RECORD_LIST,     SRV_PROVBOX_JOB_SUB_TYPE_NONE, (S32) SRV_PROVBOX_FILE_ID_EMSG_INFO_DATA},
    {SRV_PROVBOX_JOB_TYPE_INIT_RECORD_LIST,     SRV_PROVBOX_JOB_SUB_TYPE_NONE, (S32) SRV_PROVBOX_FILE_ID_EMSG_APP_DATA},

    /* Create message list */
    {SRV_PROVBOX_JOB_TYPE_INIT_MSG_LIST,        SRV_PROVBOX_JOB_SUB_TYPE_NONE, (S32) SRV_PROVBOX_BOX_TYPE_INBOX},
    
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    {SRV_PROVBOX_JOB_TYPE_INIT_MSG_LIST,        SRV_PROVBOX_JOB_SUB_TYPE_NONE, (S32) SRV_PROVBOX_BOX_TYPE_ARCHIVE},
#endif

    {SRV_PROVBOX_JOB_TYPE_INIT_MSG_LIST,        SRV_PROVBOX_JOB_SUB_TYPE_NONE, (S32) SRV_PROVBOX_BOX_TYPE_EXTRA},

    /* Check message list */
    {SRV_PROVBOX_JOB_TYPE_INIT_CHECK_MSG_LIST,  SRV_PROVBOX_JOB_SUB_TYPE_NONE, 0},

    /* Show new message */
    {SRV_PROVBOX_JOB_TYPE_SHOW_EXT_MSG,         SRV_PROVBOX_JOB_SUB_TYPE_NONE, SRV_PROVBOX_SHOW_EXT_MSG_STATUS_INIT}
};

static const srv_provbox_job_hdlr_item_struct  g_srv_provbox_job_hdlr_tbl[] = 
{
   {/* SRV_PROVBOX_JOB_TYPE_INIT_CHECK_VERSION, */          srv_provbox_job_init_check_version_hdlr},
   {/* SRV_PROVBOX_JOB_TYPE_INIT_LOAD_CHECK_DATA, */        srv_provbox_job_init_load_check_data_hdlr},
   {/* SRV_PROVBOX_JOB_TYPE_INIT_RECORD_LIST,*/             srv_provbox_job_init_record_list_hdlr},
   {/* SRV_PROVBOX_JOB_TYPE_INIT_MSG_LIST, */               srv_provbox_job_init_msg_list_hdlr},
   {/* SRV_PROVBOX_JOB_TYPE_INIT_CHECK_MSG_LIST, */         srv_provbox_job_init_check_msg_list_hdlr},
    
   {/* SRV_PROVBOX_JOB_TYPE_SHOW_EXT_MSG,  */               srv_provbox_job_show_ext_msg_hdlr},
   {/* SRV_PROVBOX_JOB_TYPE_SAVE_EXT_MSG, */                srv_provbox_job_save_ext_msg_hdlr},
   
   {/* SRV_PROVBOX_JOB_TYPE_SAVE_MSG, */                    srv_provbox_job_save_msg_hdlr},
    
   {/* SRV_PROVBOX_JOB_TYPE_GET_MSG_DATA, */                srv_provbox_job_get_msg_data_hdlr},
   {/* SRV_PROVBOX_JOB_TYPE_SET_MSG_FLAG, */                srv_provbox_job_set_msg_flag_hdlr},
   {/* SRV_PROVBOX_JOB_TYPE_GET_MSG_INFO, */                srv_provbox_job_get_msg_info_hdlr},
   {/* SRV_PROVBOX_JOB_TYPE_UPDATE_MSG_INFO, */             srv_provbox_job_update_msg_info_hdlr}

};



/*----------------------------------------------------------------------------*/
/* Functions defines                                                          */
/*----------------------------------------------------------------------------*/

/************************* Split end *************************/

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_PROVBOX_INIT);

    srv_provbox_enable_log(MMI_TRUE);

    srv_provbox_mem_init();

    cntx = srv_provbox_cntx_init();

    srv_provbox_event_hdlr_init();

    srv_provbox_job_submit_all_init_job(cntx);
}

/*----------------------------------------------------------------------------*/
/* Memory                                                                     */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_app_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_provbox_app_alloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = srv_provbox_mem_malloc(size);
    if (p != NULL)
        return p;

    /* try to free some memory */
    srv_provbox_mem_try_reclaim_memory(srv_provbox_cntx_get_cntx(), MMI_FALSE);
    p = srv_provbox_mem_malloc(size);
    if (p == NULL)
    {
        srv_provbox_mem_send_mem_full_event(srv_provbox_cntx_get_cntx());
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_APP_ALLOC);
    }
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_app_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_app_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_mem_free(p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_free_app_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_free_app_data(void *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_app_free(app_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_mem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_provbox_mem_cntx.adm_id = kal_adm_create(
                                    (void*)g_provbox_mem_cntx.pool,
                                    (kal_uint32) SRV_PROVBOX_MEM_POOL_SIZE,
                                    NULL,
                                    KAL_FALSE);

    MMI_ASSERT(g_provbox_mem_cntx.adm_id);

    g_provbox_mem_cntx.max_alloc_size = (U32) kal_adm_get_max_alloc_size(g_provbox_mem_cntx.adm_id);
    g_provbox_mem_cntx.total_left_size = (U32) kal_adm_get_total_left_size(g_provbox_mem_cntx.adm_id);

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_MEM_INIT,
        g_provbox_mem_cntx.max_alloc_size,
        g_provbox_mem_cntx.total_left_size);

#ifdef __SRV_PROVBOX_LOG_MEM__

    SRV_PROVBOX_LOG(("[ProvBox]\n\n------------srv_provbox_mem_init --------------\n\n"));

    SRV_PROVBOX_LOG(("[ProvBox]srv_provbox_mem_init:(max_alloc=%d,total_left=%d)\n",
                     g_provbox_mem_cntx.max_alloc_size, g_provbox_mem_cntx.total_left_size));

#endif /* __SRV_PROVBOX_LOG_MEM__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_mem_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *srv_provbox_mem_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size == 0)
        return NULL;

    p = kal_adm_alloc(g_provbox_mem_cntx.adm_id, (kal_uint32) size);

    g_provbox_mem_cntx.max_alloc_size = (U32) kal_adm_get_max_alloc_size(g_provbox_mem_cntx.adm_id);
    g_provbox_mem_cntx.total_left_size = (U32) kal_adm_get_total_left_size(g_provbox_mem_cntx.adm_id);

    if (p == NULL)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_MEM_MALLOC,
            size,
            g_provbox_mem_cntx.max_alloc_size,
            g_provbox_mem_cntx.total_left_size);
        return NULL;
    }

#ifdef __SRV_PROVBOX_LOG_MEM__

    SRV_PROVBOX_LOG(("[ProvBox]srv_provbox_mem_malloc:(p=%x, size=%d, max=%d, left=%d)\n",
                     p, size, g_provbox_mem_cntx.max_alloc_size, g_provbox_mem_cntx.total_left_size));
#endif /* __SRV_PROVBOX_LOG_MEM__ */ 

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_mem_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PROVBOX_LOG_MEM__
    U32 size;
    U32 old_left_size = (U32) kal_adm_get_total_left_size(g_provbox_mem_cntx.adm_id);
#endif /* __SRV_PROVBOX_LOG_MEM__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL)
        return;

    kal_adm_free(g_provbox_mem_cntx.adm_id, p);
    g_provbox_mem_cntx.max_alloc_size = (U32) kal_adm_get_max_alloc_size(g_provbox_mem_cntx.adm_id);
    g_provbox_mem_cntx.total_left_size = (U32) kal_adm_get_total_left_size(g_provbox_mem_cntx.adm_id);

#ifdef __SRV_PROVBOX_LOG_MEM__

    size = g_provbox_mem_cntx.total_left_size - old_left_size;

    SRV_PROVBOX_LOG(("[ProvBox]srv_provbox_mem_free:(p=%x, size=%d, max=%d, left=%d, old_left=%d)\n",
                     p, size, g_provbox_mem_cntx.max_alloc_size, g_provbox_mem_cntx.total_left_size, old_left_size));

#endif /* __SRV_PROVBOX_LOG_MEM__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_mem_try_reclaim_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx            [IN]        
 *  format_all      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_mem_try_reclaim_memory(srv_provbox_cntx_struct *cntx, MMI_BOOL format_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
        return SRV_PROVBOX_RESULT_OK;

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_MEM_TRY_RECLAIM_MEMORY, format_all);

    srv_provbox_format_msg_list_section(cntx, SRV_PROVBOX_BOX_TYPE_INBOX, format_all);

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    srv_provbox_format_msg_list_section(cntx, SRV_PROVBOX_BOX_TYPE_ARCHIVE, format_all);
#endif

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_format_msg_list_section
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx            [IN]        
 *  box_type        [IN]        
 *  format_all      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_format_msg_list_section(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_box_type_enum box_type,
                                MMI_BOOL format_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;
    srv_provbox_msg_list_struct *msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, box_type, &msg_num);
    return srv_provbox_msg_format_msg_list_section(msg_list, 0, msg_num, format_all);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_mem_send_mem_full_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_mem_send_mem_full_event(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PROVBOX_SET_FLAG(cntx->flag, SRV_PROVBOX_FLAG_MEM_FULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_mem_send_disk_full_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_mem_send_disk_full_event(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PROVBOX_SET_FLAG(cntx->flag, SRV_PROVBOX_FLAG_DISK_FULL);
}

/*----------------------------------------------------------------------------*/
/* Context                                                                    */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_cntx_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_cntx_struct *srv_provbox_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_provbox_cntx_p == NULL);

    g_provbox_cntx_p = SRV_PROVBOX_ALLOC_TYPE(srv_provbox_cntx_struct);
    MMI_ASSERT(g_provbox_cntx_p != NULL);

    if (g_provbox_cntx_p == NULL)
        return NULL;

    memset(g_provbox_cntx_p, 0x0, sizeof(srv_provbox_cntx_struct));

    g_provbox_cntx_p->imsg_list = srv_provbox_msg_create_list(
                                    SRV_PROVBOX_BOX_TYPE_INBOX,
                                    SRV_PROVBOX_MSG_SORT_TYPE_TIMESTAMP,
                                    SRV_PROVBOX_DEF_MSG_NODE_TYPE,
                                    SRV_PROVBOX_MSG_LIST_INIT_SIZE);

    MMI_ASSERT(g_provbox_cntx_p->imsg_list != NULL);

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    g_provbox_cntx_p->amsg_list = srv_provbox_msg_create_list(
                                    SRV_PROVBOX_BOX_TYPE_ARCHIVE,
                                    SRV_PROVBOX_MSG_SORT_TYPE_TIMESTAMP,
                                    SRV_PROVBOX_DEF_MSG_NODE_TYPE,
                                    SRV_PROVBOX_MSG_LIST_INIT_SIZE);

    MMI_ASSERT(g_provbox_cntx_p->amsg_list != NULL);

#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */ 

    g_provbox_cntx_p->emsg_list = srv_provbox_msg_create_list(
                                    SRV_PROVBOX_BOX_TYPE_EXTRA,
                                    SRV_PROVBOX_MSG_SORT_TYPE_MSG_ID,
                                    SRV_PROVBOX_DEF_MSG_NODE_TYPE,
                                    SRV_PROVBOX_MSG_LIST_INIT_SIZE);

    MMI_ASSERT(g_provbox_cntx_p->emsg_list != NULL);
    return g_provbox_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_cntx_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_cntx_struct *srv_provbox_cntx_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_provbox_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_cntx_get_next_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_provbox_cntx_get_next_msg_id(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->max_msg_id++;
    if (cntx->max_msg_id == SRV_PROVBOX_INVALID_MSG_ID)
        cntx->max_msg_id++;

    /* save the new message id to file. */
    srv_provbox_save_max_msg_id(cntx);
    return cntx->max_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_cntx_get_next_trans_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_provbox_cntx_get_next_trans_id(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->max_trans_id++;
    return cntx->max_trans_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_cntx_get_msg_list_by_box_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx            [IN]        
 *  box_type        [IN]        
 *  msg_num         [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_msg_list_struct *srv_provbox_cntx_get_msg_list_by_box_type(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_box_type_enum box_type,
                                U32 *msg_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_list_struct *msg_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx != NULL);

    switch (box_type)
    {
        case SRV_PROVBOX_BOX_TYPE_INBOX:
            msg_list = cntx->imsg_list;
            break;

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_PROVBOX_BOX_TYPE_ARCHIVE:
            msg_list = cntx->amsg_list;
            break;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_BOX_TYPE_EXTRA:
            msg_list = cntx->emsg_list;
            break;

        /* Should not add ASSERT here as it can be archive
         * to support SRV_PROVBOX_BOX_TYPE_ALL and SRV_PROVBOX_BOX_TYPE_WHOLE_ALL
         */
        default:
       //    msg_list = NULL;
       //    MMI_ASSERT(!"Wrong box_type");
            break;
    }
    if (msg_num)
    {
        if (msg_list == NULL)
            *msg_num = 0;
        else
            *msg_num = srv_provbox_msg_get_msg_num(msg_list, MMI_SIM_ALL);
    }
    return msg_list;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_cntx_get_hfile_by_file_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  file_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_provbox_cntx_get_hfile_by_file_id(srv_provbox_cntx_struct *cntx, srv_provbox_file_id_enum file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_handle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (file_id)
    {
        case SRV_PROVBOX_FILE_ID_IMSG_INFO_DATA:
            if (cntx->imsg_list)
                file_handle = cntx->imsg_list->info_fh;
            break;

        case SRV_PROVBOX_FILE_ID_IMSG_APP_DATA:
            if (cntx->imsg_list)
                file_handle = cntx->imsg_list->app_fh;
            break;

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_PROVBOX_FILE_ID_AMSG_INFO_DATA:
            if (cntx->amsg_list)
                file_handle = cntx->amsg_list->info_fh;
            break;

        case SRV_PROVBOX_FILE_ID_AMSG_APP_DATA:
            if (cntx->amsg_list)
                file_handle = cntx->amsg_list->app_fh;
            break;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_FILE_ID_EMSG_INFO_DATA:
            if (cntx->emsg_list)
                file_handle = cntx->emsg_list->info_fh;
            break;

        case SRV_PROVBOX_FILE_ID_EMSG_APP_DATA:
            if (cntx->emsg_list)
                file_handle = cntx->emsg_list->app_fh;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    return file_handle;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_cntx_get_msg_list_by_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  msg_id      [IN]        
 *  index       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_msg_list_struct *srv_provbox_cntx_get_msg_list_by_msg_id(
                                        srv_provbox_cntx_struct *cntx,
                                        U32 msg_id,
                                        U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 list_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_PROVBOX_RESULT_OK == srv_provbox_msg_get_list_index_by_msg_id(cntx->imsg_list, msg_id, &list_index))
    {
        if (index)
            *index = list_index;
        return cntx->imsg_list;
    }

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    if (SRV_PROVBOX_RESULT_OK == srv_provbox_msg_get_list_index_by_msg_id(cntx->amsg_list, msg_id, &list_index))
    {
        if (index)
            *index = list_index;
        return cntx->amsg_list;
    }
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    if (SRV_PROVBOX_RESULT_OK == srv_provbox_msg_get_list_index_by_msg_id(cntx->emsg_list, msg_id, &list_index))
    {
        if (index)
            *index = list_index;
        return cntx->emsg_list;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_cntx_get_init_next_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_cntx_get_init_next_msg_id(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 max_id;
    U32 msg_num;
    U32 max_imsg_id = 0;
    U32 max_amsg_id = 0;
    srv_provbox_msg_list_struct *msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_EXTRA, &msg_num);
    max_id = srv_provbox_msg_get_max_msg_id(msg_list);
    if (max_id > 0)
    {
        /* the last message id is always assigned to extra message, so first to check extra message list */
        cntx->max_msg_id = SRV_PROVBOX_GET_MAX_VALUE(cntx->max_msg_id, max_id);
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_CNTX_GET_INIT_NEXT_MSG_ID, cntx->max_msg_id);
        return;
    }

    /* if no extra message, then to check inbox message and archive message list */
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_INBOX, NULL);
    max_imsg_id = srv_provbox_msg_get_max_msg_id(msg_list);

    /* split: judge if there is new message, just check inbox list if there is new message.
       if inbox list have unread messages, so the max imsg id is the new msg id. */
    if (srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL))
    {
        cntx->new_msg_id = max_imsg_id;
    }

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_ARCHIVE, NULL);
    max_amsg_id = srv_provbox_msg_get_max_msg_id(msg_list);
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    max_id = SRV_PROVBOX_GET_MAX_VALUE(max_imsg_id, max_amsg_id);

    cntx->max_msg_id = SRV_PROVBOX_GET_MAX_VALUE(cntx->max_msg_id, max_id);

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_CNTX_GET_INIT_NEXT_MSG_ID, cntx->max_msg_id);
}

/*----------------------------------------------------------------------------*/
/* Job                                                                        */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_create_new_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job_type            [IN]        
 *  sub_type            [IN]        
 *  src_mod             [IN]        
 *  int_value           [IN]        
 *  req_data            [IN]        
 *  cnf_data            [IN]        
 *  hold_ctrl_buff      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_job_struct *srv_provbox_job_create_new_job(
                                srv_provbox_job_type_enum job_type,
                                srv_provbox_job_sub_type_enum sub_type,
                                int src_mod,
                                S32 int_value,
                                void *req_data,
                                void *cnf_data,
                                MMI_BOOL hold_ctrl_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_job_struct *new_job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_job = SRV_PROVBOX_ALLOC_TYPE(srv_provbox_job_struct);
    if (new_job == NULL)
        return NULL;

    new_job->next = NULL;
    new_job->src_mod = src_mod;
    new_job->job_type = job_type;
    new_job->sub_type = sub_type;
    new_job->job_state = SRV_PROVBOX_JOB_STATE_PENDING;
    new_job->flag = 0;
    if (hold_ctrl_buff != MMI_FALSE)
    {
        SRV_PROVBOX_SET_FLAG(new_job->flag, SRV_PROVBOX_JOB_FLAG_HOLD_CTRL_BUFF);
        OslHoldDataPtr(req_data);
    }
    new_job->int_value = int_value;
    new_job->req_data = req_data;
    new_job->cnf_data = cnf_data;

    return new_job;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_free_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_job_free_job(srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job == NULL)
        return;

    if (!SRV_PROVBOX_CHECK_FLAG(job->flag, SRV_PROVBOX_JOB_FLAG_HOLD_CTRL_BUFF))
        SRV_PROVBOX_FREE(job->req_data);
    else
        OslFreeDataPtr(job->req_data);

    SRV_PROVBOX_FREE(job->cnf_data);
    SRV_PROVBOX_FREE(job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_append_new_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx                [IN]        
 *  job_type            [IN]        
 *  sub_type            [IN]        
 *  src_mod             [IN]        
 *  int_value           [IN]        
 *  req_data            [IN]        
 *  hold_ctrl_buff      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_append_new_job(
                            srv_provbox_cntx_struct *cntx,
                            srv_provbox_job_type_enum job_type,
                            srv_provbox_job_sub_type_enum sub_type,
                            int src_mod,
                            S32 int_value,
                            void *req_data,
                            MMI_BOOL hold_ctrl_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_job_struct *new_job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_job = srv_provbox_job_create_new_job(job_type, sub_type, src_mod, int_value, req_data, NULL, hold_ctrl_buff);
    if (new_job == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;

    cntx->job_list = (srv_provbox_job_struct*) srv_provbox_slist_add_tail(
                                                (srv_provbox_slist_struct*) cntx->job_list,
                                                (srv_provbox_slist_struct*) new_job);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_submit_new_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx                [IN]        
 *  job_type            [IN]        
 *  sub_type            [IN]        
 *  src_mod             [IN]        
 *  int_value           [IN]        
 *  req_data            [IN]        
 *  hold_ctrl_buff      [IN]        
 * RETURNS
 *  return the result of add job to job list. only ok or memory full now.
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_job_submit_new_job(
                            srv_provbox_cntx_struct *cntx,
                            srv_provbox_job_type_enum job_type,
                            srv_provbox_job_sub_type_enum sub_type,
                            int src_mod,
                            S32 int_value,
                            void *req_data,
                            MMI_BOOL hold_ctrl_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum append_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_JOB_SUBMIT_NEW_JOB,
        job_type,
        src_mod,
        int_value,
        &req_data,
        hold_ctrl_buff);

    append_result = srv_provbox_job_append_new_job(cntx, job_type, sub_type, src_mod, int_value, req_data, hold_ctrl_buff);
    if (append_result != SRV_PROVBOX_RESULT_OK)
    {
        if (append_result == SRV_PROVBOX_RESULT_MEM_FULL)
        {
            srv_provbox_handle_mem_full(cntx, NULL); /* reclaim memory here */
            append_result = srv_provbox_job_append_new_job(cntx, job_type, sub_type, src_mod, int_value, req_data, hold_ctrl_buff);
        }
        return append_result;
    }

    srv_provbox_job_process_current_job(cntx);
    return SRV_PROVBOX_RESULT_OK;
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
#endif //0


/*----------------------------------------------------------------------------*/
/* Static Functions Defines                                                   */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_handle_mem_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_handle_mem_full(srv_provbox_cntx_struct *cntx, srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
        return;
    if (!SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_MEM_FULL))
        return;

    if (job != NULL)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_HANDLE_MEM_FULL,
            cntx->cur_job->job_type,
            cntx->cur_job->sub_type,
            cntx->cur_job->job_state,
            cntx->cur_job->int_value);
    }
    SRV_PPOVBOX_CLEAR_FLAG(cntx->flag, SRV_PROVBOX_FLAG_MEM_FULL);
    //srv_provbox_send_provboxui_popup_notify_ind(MMI_PROVBOXUI_NOTIFY_TYPE_MEM_FULL);
    srv_provbox_event_send_update_msg_status_ind(SRV_PROVBOX_NOTIFY_TYPE_MEM_FULL);
    
    /* can reclaim all memory forcely. */
    srv_provbox_mem_try_reclaim_memory(cntx, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_handle_disk_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_handle_disk_full(srv_provbox_cntx_struct *cntx, srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
        return;

    if (!SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_DISK_FULL))
        return;

    if (job != NULL)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_HANDLE_DISK_FULL,
            cntx->cur_job->job_type,
            cntx->cur_job->sub_type,
            cntx->cur_job->job_state,
            cntx->cur_job->int_value);
    }
    SRV_PPOVBOX_CLEAR_FLAG(cntx->flag, SRV_PROVBOX_FLAG_DISK_FULL);
    //srv_provbox_send_provboxui_popup_notify_ind(MMI_PROVBOXUI_NOTIFY_TYPE_DISK_FULL);
    srv_provbox_event_send_update_msg_status_ind(SRV_PROVBOX_NOTIFY_TYPE_DISK_FULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_handle_save_msg_fail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_handle_save_msg_fail(srv_provbox_cntx_struct *cntx, srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_SAVE_SIM_MSG_FAIL);
    if (!ret)
        return;

    if (job != NULL)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_SAVE_MSG_FAIL,
            cntx->cur_job->job_type,
            cntx->cur_job->sub_type,
            cntx->cur_job->job_state,
            cntx->cur_job->int_value);
    }
    
    srv_provbox_send_save_msg_available_ind(MOD_MMI, srv_provbox_cntx_get_next_trans_id(cntx));
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
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_submit_all_init_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_job_submit_all_init_job(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_SUBMIT_ALL_INIT_JOB);

    for (i = 0; i < sizeof(g_srv_provbox_init_job_info_tbl)/sizeof(srv_provbox_init_job_info_struct); i ++)
    {
        srv_provbox_job_append_new_job(cntx, 
            g_srv_provbox_init_job_info_tbl[i].job_type,
            g_srv_provbox_init_job_info_tbl[i].sub_type, MOD_MMI,
            g_srv_provbox_init_job_info_tbl[i].int_value, NULL, MMI_FALSE);
    }

    MMI_ASSERT(!SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_MEM_FULL));

    srv_provbox_job_async_process_job(cntx, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_async_process_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_async_process_job(srv_provbox_cntx_struct *cntx, srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->job_list != NULL)
    {
        /* show memory size */
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_JOB_ASYNC_PROCESS_JOB_DONE,
            g_provbox_mem_cntx.max_alloc_size,
            g_provbox_mem_cntx.total_left_size,
            srv_provbox_slist_get_length((srv_provbox_slist_struct*) cntx->job_list));
        srv_provbox_send_continue_process_job_ind(MOD_MMI, srv_provbox_cntx_get_next_trans_id(cntx));
        return SRV_PROVBOX_RESULT_OK;
    }

    /* if empty, check if need to defrag any file */
    /*
     * if (MMI_FALSE != srv_provbox_job_check_defrag_file(cntx))
     * {
     * MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_ASYNC_PROCESS_JOB_DEFRAG_FILE);
     * srv_provbox_send_continue_process_job_ind(MOD_MMI, srv_provbox_cntx_get_next_trans_id(cntx));
     * return SRV_PROVBOX_RESULT_OK;
     * }
     */
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_process_current_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_job_process_current_job(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_NOT_FOUND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->job_list == NULL)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_PROCESS_CURRENT_JOB_NO_JOB);

        return SRV_PROVBOX_RESULT_OK;
    }
    cntx->cur_job = cntx->job_list;

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_JOB_PROCESS_CURRENT_JOB_BEGIN,
        cntx->cur_job->job_type,
        cntx->cur_job->sub_type,
        cntx->cur_job->job_state,
        cntx->cur_job->int_value);


    MMI_ASSERT(cntx->cur_job->job_type < sizeof(g_srv_provbox_job_hdlr_tbl) / sizeof(srv_provbox_job_hdlr_item_struct));

    result = (g_srv_provbox_job_hdlr_tbl[cntx->cur_job->job_type].hdlr)(cntx, cntx->cur_job);


    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_JOB_PROCESS_CURRENT_JOB_RESULT,
        cntx->cur_job->job_type,
        cntx->cur_job->sub_type,
        cntx->cur_job->job_state,
        cntx->cur_job->int_value,
        result);

    /* send continue process job ind */
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
        srv_provbox_job_async_process_job(cntx, cntx->cur_job);
    else if (result == SRV_PROVBOX_RESULT_OK)
        srv_provbox_job_process_current_job_done(cntx, cntx->cur_job);
    else    /* any error */
        srv_provbox_job_process_current_job_done(cntx, cntx->cur_job);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_process_current_job_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_process_current_job_done(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL || cntx->job_list == NULL)
        return SRV_PROVBOX_RESULT_OK;

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_PROCESS_CURRENT_JOB_DONE, job->job_type);

    /* handle memory/disk full */
    switch (job->job_type)
    {
        case SRV_PROVBOX_JOB_TYPE_INIT_CHECK_VERSION:
        case SRV_PROVBOX_JOB_TYPE_INIT_LOAD_CHECK_DATA:
        case SRV_PROVBOX_JOB_TYPE_INIT_RECORD_LIST:
        case SRV_PROVBOX_JOB_TYPE_INIT_MSG_LIST:
        case SRV_PROVBOX_JOB_TYPE_INIT_CHECK_MSG_LIST:
            MMI_ASSERT(!SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_MEM_FULL));
            break;

        default:
            /* Except initial process, the process must check whether disk 
               or memery is full after handling other job*/
            /* How to check if disk or memory is full? Progress will check the flag
               of g_provbox_cntx */
            /* In current design, only set memery full flag on initial process of target */
            /* when write file system, provboxsrv will set disk full flag*/
            srv_provbox_handle_disk_full(cntx, job);
            srv_provbox_handle_mem_full(cntx, job);
            break;

    }

    cntx->job_list = (srv_provbox_job_struct*)srv_provbox_slist_delete(
                                                (srv_provbox_slist_struct*) cntx->job_list,
                                                (srv_provbox_slist_struct*)cntx->cur_job,
                                                (SRV_PROVBOX_SLIST_FREE_NODE_FUNC) srv_provbox_job_free_job);

    cntx->cur_job = NULL;
    srv_provbox_job_async_process_job(cntx, NULL); /* the job is free. */

#ifdef __SRV_PROVBOX_LOG_MEM__

    SRV_PROVBOX_LOG(("\n[ProvBox]srv_provbox_job_process_current_job_done:(max=%d, left=%d)---------\n\n",
                     g_provbox_mem_cntx.max_alloc_size, g_provbox_mem_cntx.total_left_size));

#endif /* __SRV_PROVBOX_LOG_MEM__ */ 

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_init_check_version_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_init_check_version_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_del_num = 0;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->sub_type == SRV_PROVBOX_JOB_SUB_TYPE_CHECK_FOLDER)
    {
        result = srv_provbox_check_folder(SRV_PROVBOX_FILE_MAX_DEL_FILE_NUM, &total_del_num);
        if (result == SRV_PROVBOX_RESULT_CONTINUE)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_JOB_INIT_CHECK_VERSION_HDLR_CHECK_FOLDER_CONTINUE,
                total_del_num);
            job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
            return SRV_PROVBOX_RESULT_CONTINUE;
        }
        job->sub_type = SRV_PROVBOX_JOB_SUB_TYPE_CHECK_VERSION;
        job->job_state = SRV_PROVBOX_JOB_STATE_PENDING;
    }
    if (job->sub_type == SRV_PROVBOX_JOB_SUB_TYPE_CHECK_VERSION)
    {
        result = srv_provbox_check_version(cntx);
        if (result == SRV_PROVBOX_RESULT_OK)
        {
            MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_INIT_CHECK_VERSION_HDLR_VERSION_OK);
            return SRV_PROVBOX_RESULT_OK;
        }
        job->sub_type = SRV_PROVBOX_JOB_SUB_TYPE_RESET_PROVBOX;
        job->job_state = SRV_PROVBOX_JOB_STATE_PENDING;
    }

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_INIT_CHECK_VERSION_HDLR_VERSION_NOT_MATCH);
    if (job->sub_type == SRV_PROVBOX_JOB_SUB_TYPE_RESET_PROVBOX)
    {
        result = srv_provbox_reset_provbox(cntx, SRV_PROVBOX_FILE_MAX_DEL_FILE_NUM - total_del_num, &total_del_num);
        if (result == SRV_PROVBOX_RESULT_CONTINUE)
        {
            job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
            return SRV_PROVBOX_RESULT_CONTINUE;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_init_load_check_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_init_load_check_data_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* first to check if need to restore factory. */
    if (job->sub_type == SRV_PROVBOX_JOB_SUB_TYPE_CHECK_RESTORE)
    {
        result = srv_provbox_job_check_restore_factory(cntx, job);
        if (result != SRV_PROVBOX_RESULT_FILE_NOT_FOUND)
        {
            /* OK, ERROR or continue,
               need to restore factory, so no need to check delete all now. */
            return result;
        }
        /* if not need to restore factory, try to check next task: check delete all. */
        job->sub_type = SRV_PROVBOX_JOB_SUB_TYPE_CHECK_DELETE_ALL;
        job->job_state = SRV_PROVBOX_JOB_STATE_PENDING;
    }

    /* then to check if need to delete all message in some box. */
    if (job->sub_type == SRV_PROVBOX_JOB_SUB_TYPE_CHECK_DELETE_ALL)
    {
        result = srv_provbox_job_check_delete_all(cntx, job);
        if (result == SRV_PROVBOX_RESULT_FILE_NOT_FOUND)
            return SRV_PROVBOX_RESULT_OK;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_init_record_list_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_init_record_list_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hfile;
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hfile = srv_provbox_cntx_get_hfile_by_file_id(cntx, (srv_provbox_file_id_enum)job->int_value);

    result = srv_provbox_file_init_record_list(hfile, SRV_PROVBOX_FILE_MAX_OP_RECORD_HEAD_NUM);
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
    {
        job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
        MMI_ASSERT(!SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_MEM_FULL));
        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_init_msg_list_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_init_msg_list_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_msg_list_struct *msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, (srv_provbox_box_type_enum) job->int_value, NULL);
    if (msg_list == NULL)
    {
#ifndef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        /* only archive is missed if not support archive */
        MMI_ASSERT(job->int_value == SRV_PROVBOX_BOX_TYPE_ARCHIVE);
#endif
        return SRV_PROVBOX_RESULT_OK;
    }

    /*
     * if (job->job_state == SRV_PROVBOX_JOB_STATE_PENDING)
     * msg_list->cursor = 0;
     */

    result = srv_provbox_msg_init_multi_msg_node(msg_list, SRV_PROVBOX_FILE_MAX_OP_RECORD_NUM);
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
    {
        job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
        MMI_ASSERT(!SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_MEM_FULL));
        return SRV_PROVBOX_RESULT_CONTINUE;
    }

    /* any other result */
    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_JOB_INIT_MSG_LSIT_HDLR,
        msg_list->box_type,
        srv_provbox_dpary_get_num(msg_list->msg_ah),
        result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_init_check_msg_list_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_init_check_msg_list_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Should delete all SIM provisioning message if not support */
    result = srv_provbox_job_delete_all_invalid_msg(cntx, job);
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
    {
        job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    /* not need to asynchronous handling, because the sim message is not so many at most scenario. */
    srv_provbox_job_delete_sim_message(cntx);

    /* All message lists are initialized, so it's time to get the last message id. */
    srv_provbox_cntx_get_init_next_msg_id(cntx);

    //srv_provbox_send_provboxui_ready_ind(MMI_PROVBOXUI_APP_ID_PROVBOX);
    srv_provbox_send_srv_ready_event(cntx);
    
    /* Check server status on memory, disk, message number. if memory is full, disk full or 
       message number is max. server should notify provbox app or UM app to update status icon
       or popup notify screen */
    srv_provbox_sent_box_full_event(cntx);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_delete_sim_message
 * DESCRIPTION
 *  if not support sim message, try to delete it, just to handle issues found when upgrading.
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_delete_sim_message(srv_provbox_cntx_struct *cntx)
{
#ifndef __MMSICP_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_msg_type_enum msg_type_list[] = {SRV_PROVBOX_MSG_TYPE_SIM_MMSICP};
    srv_provbox_box_type_enum box_type_list[] = 
    {
        SRV_PROVBOX_BOX_TYPE_INBOX,
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        SRV_PROVBOX_BOX_TYPE_ARCHIVE,
#endif
        SRV_PROVBOX_BOX_TYPE_EXTRA
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(box_type_list) / sizeof(srv_provbox_box_type_enum); i++)
    {
        msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, box_type_list[i], NULL);
        if (msg_list == NULL)
            continue;
        srv_provbox_msg_force_delete_sim_msg(
            msg_list,
            (srv_provbox_msg_type_enum*) msg_type_list,
            sizeof(msg_type_list) / sizeof(srv_provbox_msg_type_enum));
    }

#endif /* __MMSICP_SUPPORT__ */ 

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_check_restore_factory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_check_restore_factory(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_del_num = 0;
    srv_provbox_result_enum result;
    srv_provbox_check_info_struct check_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->job_state == SRV_PROVBOX_JOB_STATE_PENDING)
    {
        result = srv_provbox_file_read_check_file(NULL, SRV_PROVBOX_CHECK_TYPE_RESTORE_FACTORY, 
                            SRV_PROVBOX_INVALID_MSG_ID, &check_info);
        if (result == SRV_PROVBOX_RESULT_FILE_NOT_FOUND)    /* check if not exist */
            return result;

        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_CHECK_RESTORE_FACTORY, result);
    }
    result = srv_provbox_reset_provbox(cntx, SRV_PROVBOX_FILE_MAX_DEL_FILE_NUM, &total_del_num);
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
    {
        job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    result = srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_RESTORE_FACTORY, SRV_PROVBOX_INVALID_MSG_ID);
    if (result == SRV_PROVBOX_RESULT_FILE_NOT_FOUND)
        result = SRV_PROVBOX_RESULT_OK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_check_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_check_delete_all(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_del_num = 0;
    srv_provbox_result_enum result;
    srv_provbox_check_info_struct check_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->job_state == SRV_PROVBOX_JOB_STATE_PENDING)
    {
        result = srv_provbox_file_read_check_file(NULL, SRV_PROVBOX_CHECK_TYPE_DELETE_ALL, SRV_PROVBOX_INVALID_MSG_ID, &check_info);
        if (result == SRV_PROVBOX_RESULT_FILE_NOT_FOUND)    /* check if not exist */
            return result;

        job->int_value = check_info.box_type;   /* if not ok, it's unknown type. */

        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_CHECK_DELETE_ALL, check_info.box_type, result);
    }
    
    /* if exist and read ok */
    if (job->int_value == SRV_PROVBOX_BOX_TYPE_INBOX || 
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__        
        job->int_value == SRV_PROVBOX_BOX_TYPE_ARCHIVE || 
#endif        
        job->int_value == SRV_PROVBOX_BOX_TYPE_EXTRA) 
    {
        result = srv_provbox_clean_folder_by_box_type(
                    (srv_provbox_box_type_enum) job->int_value,
                    SRV_PROVBOX_FILE_MAX_DEL_FILE_NUM,
                    &total_del_num);
        if (result == SRV_PROVBOX_RESULT_CONTINUE)
        {
            job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
            return SRV_PROVBOX_RESULT_CONTINUE;
        }
    }
    else
    {
        /* check if exist but read fail unluckily, so cannot know which box should be delete all. */
        result = srv_provbox_reset_provbox(cntx, SRV_PROVBOX_FILE_MAX_DEL_FILE_NUM, &total_del_num);
        if (result == SRV_PROVBOX_RESULT_CONTINUE)
        {
            job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
            return SRV_PROVBOX_RESULT_CONTINUE;
        }
    }
    result = srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_DELETE_ALL, SRV_PROVBOX_INVALID_MSG_ID);
    if (result == SRV_PROVBOX_RESULT_FILE_NOT_FOUND)
        result = SRV_PROVBOX_RESULT_OK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_delete_all_invalid_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_delete_all_invalid_msg(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fd;
    int ret;
    U32 msg_id;
    S32 path_len;
    S32 total_del_num = 0;
    const CHAR *tmp_dir;
    FS_DOSDirEntry FileInfo;
    U16 path[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];
    U16 filename[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];
    CHAR asc_name[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp_dir = srv_provbox_get_dir_by_id(SRV_PROVBOX_DIR_ID_TEMP);
    mmi_asc_to_ucs2((CHAR*) path, (CHAR*) tmp_dir);
    path_len = mmi_ucs2strlen((const CHAR*)path);
    if (path_len >= 1 && 0 != mmi_ucs2cmp((const CHAR*)(path + path_len - 1), (const CHAR*)L"\\"))
    {
        mmi_ucs2cat((CHAR*) path, (const CHAR*)L"\\");
        path_len++;
    }
    mmi_ucs2cat((CHAR*) path, (const CHAR*)SRV_PROVBOX_FILE_FIND_ALL_NAME_PATTERN);

    fd = FS_FindFirst((const WCHAR*)path, 0, 0, &FileInfo, (WCHAR*) filename, SRV_PROVBOX_PATH_MAX_BUFF_SIZE);
    if (fd < 0)
        return SRV_PROVBOX_RESULT_OK;
    do
    {
        path[path_len] = '\0';
        mmi_ucs2_to_asc((CHAR*) asc_name, (CHAR*) filename);
        msg_id = atoi((const char*)asc_name);
        mmi_ucs2cat((CHAR*) path, (const CHAR*)filename);
        srv_provbox_job_delete_invalid_msg(cntx, msg_id, path);
        total_del_num++;
        if (total_del_num * 2 >= SRV_PROVBOX_FILE_MAX_OP_RECORD_NUM)    /* commonly to delete two records here. */
        {
            MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_DELETE_ALL_INVALID_MSG_CONTINUE);
            return SRV_PROVBOX_RESULT_CONTINUE;
        }
        ret = FS_FindNext(fd, &FileInfo, (WCHAR*) filename, SRV_PROVBOX_PATH_MAX_BUFF_SIZE);
    }
    while (ret == FS_NO_ERROR);

    FS_FindClose(fd);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_delete_invalid_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx            [IN]        
 *  msg_id          [IN]        
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_delete_invalid_msg(
                                srv_provbox_cntx_struct *cntx,
                                U32 msg_id,
                                U16 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_check_info_struct check_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id == SRV_PROVBOX_INVALID_MSG_ID)
    {
        FS_Delete((const WCHAR*)filename);
        return SRV_PROVBOX_RESULT_OK;
    }
    result = srv_provbox_file_read_check_file(filename, SRV_PROVBOX_CHECK_TYPE_UNKNOWN, msg_id, &check_info);
    if (result == SRV_PROVBOX_RESULT_FILE_NOT_FOUND)    /* check if not exist */
        return result;

    /* check if exist and read ok */
    if (result == SRV_PROVBOX_RESULT_OK &&
        (check_info.box_type == SRV_PROVBOX_BOX_TYPE_INBOX ||
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
         check_info.box_type == SRV_PROVBOX_BOX_TYPE_ARCHIVE ||
#endif
         check_info.box_type == SRV_PROVBOX_BOX_TYPE_EXTRA))
    {
        result = srv_provbox_force_delete_msg_by_id(cntx, (srv_provbox_box_type_enum) check_info.box_type, msg_id);
    }
    else    /* check if exist but read fail unluckily, try delete message only by message id */
    {
        result = srv_provbox_force_delete_msg_by_id(cntx, SRV_PROVBOX_BOX_TYPE_EXTRA, msg_id);

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__        
        if (result == SRV_PROVBOX_RESULT_NOT_FOUND)
        {
            result = srv_provbox_force_delete_msg_by_id(cntx, SRV_PROVBOX_BOX_TYPE_ARCHIVE, msg_id);
        }
#endif  /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        if (result == SRV_PROVBOX_RESULT_NOT_FOUND)
        {
            result = srv_provbox_force_delete_msg_by_id(cntx, SRV_PROVBOX_BOX_TYPE_INBOX, msg_id);
        }
    }
    /* can try to delete it again when next time to power on. */
    if (result == SRV_PROVBOX_RESULT_NOT_FOUND || result == SRV_PROVBOX_RESULT_OK)
        FS_Delete((const WCHAR*)filename);

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_DELETE_INVALID_MSG, check_info.box_type, msg_id, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_force_delete_msg_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx            [IN]        
 *  box_type        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_force_delete_msg_by_id(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_box_type_enum box_type,
                                U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_msg_list_struct *msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
        return SRV_PROVBOX_RESULT_OK;
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, box_type, NULL);
    if (msg_list == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;
    return srv_provbox_msg_force_delete_msg_by_id(msg_list, msg_id);
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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_save_ext_msg_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_save_ext_msg_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 msg_num;
    U32 cur_save_num = 0;
    MMI_BOOL any_fail = MMI_FALSE;
    srv_provbox_result_enum result;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_msg_node_struct *msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_EXTRA, &msg_num);
    if (msg_num == 0)
    {
        /* no extra message now, it seems the disk may be avaliable now, try to save sim message again. */
        if (!SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_DISK_FULL))
            srv_provbox_handle_save_msg_fail(cntx, job);
        return SRV_PROVBOX_RESULT_OK;
    }

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_SAVE_EXT_MSG_HDLR, msg_num);
    /* try to save all extra message according to the received ord,
       does not care async saving because extra message is not so many. */

    if (job->job_state == SRV_PROVBOX_JOB_STATE_PENDING)
        job->int_value = msg_num;

    for (i = 0; i < (U32) job->int_value; i++)
    {
        srv_provbox_msg_get_msg_node_by_index(msg_list, job->int_value - 1 - i, &msg_node);
        result = srv_provbox_msg_save_ext_msg_by_index(msg_list, job->int_value - 1 - i);
        if (result != SRV_PROVBOX_RESULT_OK)
            any_fail = MMI_TRUE;

        cur_save_num++;
        if (cur_save_num * 3 >= SRV_PROVBOX_FILE_MAX_OP_RECORD_NUM)
        {
            job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
            job->int_value -= i + 1;    /* new message number not saved. */
            return SRV_PROVBOX_RESULT_CONTINUE;
        }
    }

    /* the memory may be ok to receive new SIM provisioning message. */
    if (!any_fail && !SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_DISK_FULL))
        srv_provbox_handle_save_msg_fail(cntx, job);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_show_ext_msg_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_show_ext_msg_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 new_index;
    U32 imsg_num;
    U32 emsg_num;
    U32 move_num = 0;
    srv_provbox_result_enum result2;
    srv_provbox_msg_list_struct *imsg_list;
    srv_provbox_msg_list_struct *emsg_list;
    srv_provbox_msg_base_info_struct *base_info;
    srv_provbox_msg_cmn_info_struct cmn_info;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imsg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_INBOX, &imsg_num);
    if (imsg_num >= SRV_PROVBOX_MAX_INBOX_MSG_NUM)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_SHOW_EXT_MSG_HDLR_INBOX_FULL, imsg_num);
        return SRV_PROVBOX_RESULT_OK;
    }
    emsg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_EXTRA, &emsg_num);
    if (emsg_num == 0)
        return SRV_PROVBOX_RESULT_OK;

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_SHOW_EXT_MSG_HDLR_SHOW, emsg_num);

    for (i = 0; i < emsg_num; i++)
    {
        if (move_num >= SRV_PROVBOX_MAX_INBOX_MSG_NUM - imsg_num)
            break;

        if (move_num * 2 >= SRV_PROVBOX_FILE_MAX_OP_RECORD_NUM) /* slight effort to move files in the same driver. */
        {
            job->job_state = SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE;
            result = SRV_PROVBOX_RESULT_CONTINUE;
            break;
        }

        /* Should move the last extra message to inbox, because the extra messages are sort by message id, more fronter more larger. */
        result = srv_provbox_msg_move_to_box_by_index(emsg_list, imsg_list, emsg_num - 1 - i, &new_index);

        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_JOB_SHOW_EXT_MSG_HDLR_MOVE_TO_BOX,
            emsg_num - 1 - i,
            new_index,
            result);

        if (result != SRV_PROVBOX_RESULT_OK)    /*  may be SRV_PROVBOX_RESULT_NOT_SAVED */
        {
            /*  if app_data of this message is not found or the prov_data is not found, try to delete it, or it shall block all other 
               extra message to be shown.
               Temp solution: can be delete here because stop now, so don't affect the index of the message to move next time. */
            if (result == SRV_PROVBOX_RESULT_NOT_FOUND || result == SRV_PROVBOX_RESULT_FILE_NOT_FOUND)
            {
                result2 = srv_provbox_msg_get_msg_node_by_index(
                            emsg_list,
                            emsg_num - 1 - i,
                            (srv_provbox_msg_node_struct **) & base_info);
                if (result2 == SRV_PROVBOX_RESULT_OK)
                    srv_provbox_msg_force_delete_msg_by_id(emsg_list, base_info->msg_id);
            }
            break;
        }

        result2 = srv_provbox_msg_get_msg_node_by_index(imsg_list, new_index, (srv_provbox_msg_node_struct **) & base_info);
        if (result2 == SRV_PROVBOX_RESULT_OK)
        {
            result2 = srv_provbox_msg_get_list_info_by_index(
                        imsg_list,
                        SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info)),
                        new_index,
                        NULL,
                        &cmn_info,
                        NULL);
            if (result2 == SRV_PROVBOX_RESULT_OK)
            {
                srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();
                cntx->new_msg_id = cmn_info.msg_id;
                srv_provbox_new_msg_update_app_hdlr(&cmn_info);
            }
        }
        move_num++;
    }

    /* only send this when receive new message, do not send it when power on, 
       ProvBoxUI shall check if inbox is full when power on by extra_num. */
    if (job->int_value != SRV_PROVBOX_SHOW_EXT_MSG_STATUS_INIT)
    {
        if (move_num >= SRV_PROVBOX_MAX_INBOX_MSG_NUM - imsg_num)
        {
            //srv_provbox_send_provboxui_popup_notify_ind(MMI_PROVBOXUI_NOTIFY_TYPE_INBOX_FULL);
            srv_provbox_event_send_update_msg_status_ind(SRV_PROVBOX_NOTIFY_TYPE_INBOX_FULL);
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_save_msg_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_save_msg_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_save_msg_req_struct *req_data;
    srv_provbox_save_data_type_enum save_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PROVBOX_LOG(("\n[ProvBox]srv_provbox_job_save_msg_hdlr: receive new message! --------\n\n"));
    req_data = (srv_provbox_save_msg_req_struct*) job->req_data;

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_JOB_SAVE_MSG_HDLR_NEW_MSG_BASE_INFO,
        req_data->cmn_info.msg_id,
        req_data->cmn_info.timestamp,
        req_data->cmn_info.install_time,
        req_data->cmn_info.src_id,
        req_data->cmn_info.sim_id,
        req_data->cmn_info.msg_type,
        req_data->cmn_info.read_status,
        req_data->cmn_info.sender_addr.addr_type);

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_JOB_SAVE_MSG_HDLR_NEW_MSG_DATA_INFO,
        req_data->trans_id,
        req_data->msg_data.app_data_size,
        req_data->msg_data.prov_data_type,
        req_data->msg_data.prov_data_size);

    /* check if can accept this new message. */
    result = srv_provbox_job_accept_new_msg(cntx, req_data);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_SAVE_MSG_HDLR_NOT_ACCEPT, result);

        if (req_data->msg_data.prov_data_type == SRV_PROVBOX_SAVE_DATA_TYPE_FILE)
            FS_Delete((const WCHAR*)req_data->msg_data.prov_file);
        
        srv_provbox_send_save_msg_cnf(job->src_mod, req_data, SRV_PROVBOX_INVALID_MSG_ID, result);
    
        return SRV_PROVBOX_RESULT_OK;
    }

    req_data->cmn_info.msg_id = srv_provbox_cntx_get_next_msg_id(cntx);
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_EXTRA, NULL);

    /* Try to save new message to file or memory */
    result = srv_provbox_msg_save_msg(msg_list, req_data, &save_type);

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_SAVE_MSG_HDLR_SAVE_RESULT, result);

    /* may save it to memory, so try to delete the download file again. */
    if (save_type == SRV_PROVBOX_SAVE_DATA_TYPE_RAW_DATA &&
        req_data->msg_data.prov_data_type == SRV_PROVBOX_SAVE_DATA_TYPE_FILE)
    {
        FS_Delete((const WCHAR*)req_data->msg_data.prov_file);
    }
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        if (MMI_FALSE != srv_provbox_msg_is_sim_message(req_data->cmn_info.msg_type))
        {
            SRV_PROVBOX_SET_FLAG(cntx->flag, SRV_PROVBOX_FLAG_SAVE_SIM_MSG_FAIL);
        }
        else if (SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_SAVE_SIM_MSG_FAIL))
        {
            SRV_PPOVBOX_CLEAR_FLAG(cntx->flag, SRV_PROVBOX_FLAG_SAVE_SIM_MSG_FAIL);
        }

        srv_provbox_send_save_msg_cnf(job->src_mod, req_data, SRV_PROVBOX_INVALID_MSG_ID, result);
        return result;
    }

    srv_provbox_send_save_msg_cnf(job->src_mod, req_data, req_data->cmn_info.msg_id, SRV_PROVBOX_RESULT_OK);
    /* may other applications delete some files one disk, the disk is available now, so try to save extra message again.
       it may no memory so no need to try to save other extra messages again if save it to memory,
       while a choice to save others if save it to file ok. */
    srv_provbox_job_save_and_show_ext_msg(cntx, save_type == SRV_PROVBOX_SAVE_DATA_TYPE_FILE ? MMI_TRUE : MMI_FALSE);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_accept_new_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx            [IN]        
 *  req_data        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_accept_new_msg(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_save_msg_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 imsg_num;
    U32 emsg_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_PROVBOX_MAX_INBOX_MSG_NUM == SRV_PROVBOX_UNLIMITED_NUM)
        return SRV_PROVBOX_RESULT_OK;

    if (MMI_FALSE != srv_provbox_msg_is_sim_message(req_data->cmn_info.msg_type))
        return SRV_PROVBOX_RESULT_OK;

    /* the jobs of saving & showing extra message are appended to the job list, may be the inbox is cleared,
       but the extra messags are still not move to the inbox, so, we need to calculate the max extra number here. */
    srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_INBOX, &imsg_num);
    srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_EXTRA, &emsg_num);
    if (imsg_num + emsg_num < SRV_PROVBOX_MAX_INBOX_MSG_NUM + SRV_PROVBOX_MAX_CMN_EXT_MSG_NUM)
        return SRV_PROVBOX_RESULT_OK;

    return SRV_PROVBOX_RESULT_BOX_FULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_get_msg_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_get_msg_data_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    void *app_data;
    S16 app_data_size;
    U8 sim_id;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_get_msg_data_req_struct *req_data;
    U16 filename[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1] = {0};
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_data = (srv_provbox_get_msg_data_req_struct*) job->req_data;

    msg_list = srv_provbox_cntx_get_msg_list_by_msg_id(cntx, req_data->msg_id, &index);
    if (msg_list == NULL)
    {
        srv_provbox_send_get_msg_data_cnf(
            job->src_mod,
            job->req_data,
            MMI_SIM1,
            NULL,
            -1,
            NULL,
            SRV_PROVBOX_RESULT_NOT_FOUND);
        return SRV_PROVBOX_RESULT_OK;
    }
    result = srv_provbox_msg_get_msg_data_by_index(
                msg_list,
                index,
                &sim_id,
                (void **)&app_data,
                &app_data_size,
                (U16*) filename,
                SRV_PROVBOX_PATH_MAX_BUFF_SIZE);

    /* The receiver shall free the app_data memory. */
    srv_provbox_msg_get_sim_id_by_index(msg_list, index, &sim_id);

    if (result == SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_send_get_msg_data_cnf(
            job->src_mod,
            job->req_data,
            sim_id,
            app_data,
            app_data_size,
            filename,
            result);
    }
    else
    {
        srv_provbox_send_get_msg_data_cnf(job->src_mod, job->req_data, MMI_SIM1, NULL, -1, NULL, result);
    }
    return result;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
 *  srv_provbox_job_save_and_show_ext_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx            [IN]        
 *  try_save        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_save_and_show_ext_msg(srv_provbox_cntx_struct *cntx, MMI_BOOL try_save)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_EXTRA, &msg_num);

    /* also can check if any not saved */
    if (msg_num == 0)
        return SRV_PROVBOX_RESULT_OK;

    if (try_save)
    {
        srv_provbox_job_append_new_job(
            cntx,
            SRV_PROVBOX_JOB_TYPE_SAVE_EXT_MSG,
            SRV_PROVBOX_JOB_SUB_TYPE_NONE,
            MOD_MMI,
            0,
            NULL,
            MMI_FALSE);
    }

    srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_INBOX, &msg_num);
    if (msg_num < SRV_PROVBOX_MAX_INBOX_MSG_NUM)
        srv_provbox_job_append_new_job(
            cntx,
            SRV_PROVBOX_JOB_TYPE_SHOW_EXT_MSG,
            SRV_PROVBOX_JOB_SUB_TYPE_NONE,
            MOD_MMI,
            SRV_PROVBOX_SHOW_EXT_MSG_STATUS_DELETE,
            NULL,
            MMI_FALSE);
    
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_is_all_box_cleaned
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_provbox_job_is_all_box_cleaned(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_INBOX, &msg_num);
    if (msg_num > 0)
        return MMI_FALSE;

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_ARCHIVE, &msg_num);
    if (msg_num > 0)
        return MMI_FALSE;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_EXTRA, &msg_num);
    if (msg_num > 0)
        return MMI_FALSE;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_set_msg_flag_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_set_msg_flag_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_set_msg_flag_req_struct *req_data;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_data = (srv_provbox_set_msg_flag_req_struct*) job->req_data;

    msg_list = srv_provbox_cntx_get_msg_list_by_msg_id(cntx, req_data->msg_id, &index);
    if (msg_list == NULL)
    {
        srv_provbox_send_set_msg_flag_cnf(job->src_mod, req_data, SRV_PROVBOX_RESULT_NOT_FOUND);
        return SRV_PROVBOX_RESULT_OK;
    }
    result = srv_provbox_msg_set_msg_flag(msg_list, req_data->msg_id, req_data->op, req_data->msg_flag);
    
    srv_provbox_send_set_msg_flag_cnf(job->src_mod, req_data, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_get_msg_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_get_msg_info_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    srv_provbox_result_enum result;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_get_msg_info_req_struct *req_data;
    srv_provbox_get_msg_info_cnf_struct cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_data = (srv_provbox_get_msg_info_req_struct*) job->req_data;

    msg_list = srv_provbox_cntx_get_msg_list_by_msg_id(cntx, req_data->msg_id, &index);
    if (msg_list == NULL)
    {
        srv_provbox_send_get_msg_info_cnf(job->src_mod, req_data, NULL, 
            SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED, NULL, SRV_PROVBOX_RESULT_NOT_FOUND);
        return SRV_PROVBOX_RESULT_OK;
    }
    result = srv_provbox_msg_get_read_info_by_index(
                msg_list,
                index,
                &cnf_data.cmn_info,
                &cnf_data.pin_status,
                &cnf_data.msg_config_status);

    if (result != SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_send_get_msg_info_cnf(job->src_mod, req_data, NULL, 
            SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED, NULL, SRV_PROVBOX_RESULT_NOT_FOUND);
    }
    else
    {
        srv_provbox_send_get_msg_info_cnf(
            job->src_mod,
            req_data,
            &cnf_data.cmn_info,
            cnf_data.pin_status,
            &cnf_data.msg_config_status,
            result);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_job_update_msg_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  job         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_job_update_msg_info_hdlr(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    srv_provbox_result_enum result;
    //U8 sim_id;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_update_msg_info_req_struct *req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_data = (srv_provbox_update_msg_info_req_struct*) job->req_data;

    msg_list = srv_provbox_cntx_get_msg_list_by_msg_id(cntx, req_data->msg_id, &index);
    if (msg_list == NULL)
    {
        srv_provbox_send_update_msg_info_cnf(job->src_mod, req_data, SRV_PROVBOX_RESULT_NOT_FOUND);
        return SRV_PROVBOX_RESULT_OK;
    }

    result = srv_provbox_msg_update_read_info_by_index(
                msg_list,
                index,
                req_data->info_mask,
                req_data->install_time,
                req_data->read_status,
                req_data->pin_status,
                &req_data->msg_config_status);

    srv_provbox_send_update_msg_info_cnf(job->src_mod, req_data, result);
        
    if (result == SRV_PROVBOX_RESULT_OK)
    {
        /* to do send list info changed */
    #ifdef __MMI_PROV_IN_UM__
        srv_provbox_send_um_refresh_ind(SRV_UM_REFRESH_MSG_STATUS_CHANGED, req_data->msg_id, NULL);
    #endif
    }

    return result;
}


/*********************************** provide message status end ************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_handle_save_msg_again
 * DESCRIPTION
 *  If saving message is fail, program will sent save_msg_available provimitive 
 *  message to save message again
 *  
 * PARAMETERS
 *  srv_provbox_cntx_struct*        [IN]        
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void srv_provbox_handle_save_msg_again(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_SAVE_SIM_MSG_FAIL);
    
    if (!ret)
        return;
   srv_provbox_send_save_msg_available_ind(MOD_MMI, srv_provbox_cntx_get_next_trans_id(cntx));
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_send_srv_ready_event
 * DESCRIPTION
 *  This function is to set provboxsrv ready flag and sent ready message to um
 *  
 * PARAMETERS
 *  srv_provbox_cntx_struct*        [IN]        
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void srv_provbox_send_srv_ready_event(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PROVBOX_SET_FLAG(cntx->flag, SRV_PROVBOX_FLAG_SRV_STATUS_READY);
    
#ifdef __MMI_PROV_IN_UM__
    srv_provbox_send_um_ready_ind();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_main_send_state_notify
 *
 * DESCRIPTION
 *  when power on target, server should send notify to APP or UM. Notify server
 *  state. if memory full, disk full of message number is full, app or um should
 *  update states icon and popup screen.
 *
 * PARAMETERS
 *  hary            [IN/OUT]
 *  index           [IN]
 *  free_elm        [IN]
 *
 * RETURNS
 *  MMI_TRUE:  success
 *  MMI_FALSE: fail
 *****************************************************************************/
void srv_provbox_sent_box_full_event(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_notify_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check inbox, disk or memory is full */
    if (srv_provbox_is_full())
    {
        type = SRV_PROVBOX_NOTIFY_TYPE_INBOX_FULL;
    }
    else if (SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_DISK_FULL))
    {
        type = SRV_PROVBOX_NOTIFY_TYPE_DISK_FULL;
    }
    else if (SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_MEM_FULL))
    {
        type = SRV_PROVBOX_NOTIFY_TYPE_MEM_FULL;
    }
    else
    {
        type = SRV_PROVBOX_NOTIFY_TYPE_NO_FULL;
    }
    
    srv_provbox_event_send_update_msg_status_ind(type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_stat_unread_msg_num_by_sim_id
 * DESCRIPTION
 *  This function is to get the statistics of unread message number
 *  
 * PARAMETERS
 *  srv_provbox_box_msg_stat_struct *        [OUT]
 *  srv_provbox_box_type_enum                [IN]
 *  U8                                       [IN]
 *         
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 srv_provbox_msg_stat_unread_msg_num_by_sim_id(
               srv_provbox_box_msg_stat_struct *msg_stat, 
               srv_provbox_box_type_enum box_type, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 unread_msg_num = 0;
    srv_provbox_sim_msg_stat_struct *expect_sim_msg_stat = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (box_type)
    {
        case SRV_PROVBOX_BOX_TYPE_INBOX:
        {
            expect_sim_msg_stat = &msg_stat->imsg_stat;
            break;
        }

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__        
        case SRV_PROVBOX_BOX_TYPE_ARCHIVE:
        {
            expect_sim_msg_stat = &msg_stat->amsg_stat;
            break;
        }
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        default:
            MMI_ASSERT(0);        
    }
    
    for (i = 0; sim_id != 0; i++)
    {
        if (SRV_PROVBOX_GET_VAILD_SIM_ID(sim_id, i) > 0)
        {
            unread_msg_num += expect_sim_msg_stat->sim_unread_num[i];
            SRV_PROVBOX_RESET_BIT_VALUE(sim_id, i);
        }
    }
    
    return unread_msg_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  U32         [IN]        
 *     
 * RETURNS
 *  srv_provbox_msg_read_status_enum
 *****************************************************************************/
srv_provbox_msg_read_status_enum srv_provbox_get_msg_status(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 next_msg_id;
    U32 msg_size;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;
    srv_provbox_cntx_struct *cntx_data = srv_provbox_cntx_get_cntx();
    srv_provbox_msg_cmn_info_struct msg_data = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (NULL == cntx_data)
        return SRV_PROVBOX_MSG_READ_STATUS_NONE;
        
    result = srv_provbox_msg_get_list_index_by_id_and_box(
                 cntx_data, SRV_PROVBOX_BOX_TYPE_ALL, msg_id, &msg_list, &index);
                 
    if (SRV_PROVBOX_RESULT_OK != result)
        return SRV_PROVBOX_MSG_READ_STATUS_NONE;
        
    result = srv_provbox_msg_get_list_info_by_id(
                 msg_list,
                 SRV_PROVBOX_SIM_ID_DUAL_SIM,
                 msg_id,
                 (S16*)&msg_size,
                 &msg_data,
                 &next_msg_id);
        
    if (SRV_PROVBOX_RESULT_OK != result)
        return SRV_PROVBOX_MSG_READ_STATUS_NONE;
        
    return msg_data.read_status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_set_msg_status
 * DESCRIPTION
 *  The function is to set message status and send um refresh promitive message
 *  
 * PARAMETERS
 *  U32                               [IN]        
 *  srv_provbox_msg_read_status_enum  [IN]
 *
 * RETURNS
 *  srv_provbox_result_enum
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_set_msg_status(U32 msg_id, srv_provbox_msg_read_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    srv_provbox_msg_list_struct *msg_list    = NULL;
    srv_provbox_msg_cmn_info_struct cmn_info = {0};
    srv_provbox_result_enum result           = SRV_PROVBOX_RESULT_OK;
    srv_provbox_cntx_struct *cntx_data       = srv_provbox_cntx_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_provbox_cntx_get_msg_list_by_msg_id(cntx_data, msg_id, &index);

    if (msg_list == NULL)
    {
        return SRV_PROVBOX_RESULT_NOT_FOUND;
    }

    srv_provbox_msg_get_list_info_by_index(msg_list, 0, index, NULL, &cmn_info, NULL);
    
    if (cmn_info.read_status == status)
    {
        return SRV_PROVBOX_RESULT_OK;
    }

    result = srv_provbox_msg_update_read_info_by_index(
                msg_list, index,
                SRV_PROVBOX_MSG_INFO_MASK_READ_STATUS,
                0, status, SRV_PROVBOX_MSG_PIN_STATUS_NOT_VERIFIED, 0);

    if (SRV_PROVBOX_RESULT_OK == result)
    {
    #ifdef __MMI_PROV_IN_UM__
        srv_provbox_send_um_refresh_ind(SRV_UM_REFRESH_MSG_CONTENT_CHANGED, msg_id, NULL);
    #endif
        srv_provbox_event_send_update_msg_status_ind(SRV_PROVBOX_NOTIFY_TYPE_UPDATE_MSG_STATE);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_is_ready
 * DESCRIPTION
 *  The function is to check if provbox service is ready
 *  
 * PARAMETERS
 *  Void
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_provbox_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)SRV_PROVBOX_CHECK_FLAG(cntx->flag, SRV_PROVBOX_FLAG_SRV_STATUS_READY);;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_msg_num
 * DESCRIPTION
 *  The function is to get the number of message
 *  
 * PARAMETERS
 *  srv_provbox_box_type_enum [IN]
 *
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_provbox_get_msg_num(srv_provbox_box_type_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if init */
    if (cntx == NULL)
        return 0;

    srv_provbox_cntx_get_msg_list_by_box_type(cntx, box_type, &msg_num);
    return msg_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_total_msg_num 
 * DESCRIPTION
 *  Provide the number of provisioning message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_provbox_get_total_msg_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_new_msg_id
 * DESCRIPTION
 *  The function is to get the number of new message
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_provbox_get_new_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return cntx->new_msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_unread_msg_num
 * DESCRIPTION
 *  The function is to get the number of unread message
 *  
 * PARAMETERS
 *  srv_provbox_box_type_enum [IN]
 *  U8                        [IN]
 *
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_provbox_get_unread_msg_num(srv_provbox_box_type_enum box_type, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();
    srv_provbox_result_enum result;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_box_msg_stat_struct msg_stat = {0};
    U32 unread_msg_num = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if init */
    if (cntx == NULL)
        return 0;

    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, box_type, NULL);
    result = srv_provbox_msg_get_msg_num_stat(msg_list, box_type, sim_id, &msg_stat);
    
    if (SRV_PROVBOX_RESULT_OK != result)
    {
        return 0;
    }
    
    unread_msg_num = srv_provbox_msg_stat_unread_msg_num_by_sim_id(&msg_stat, box_type, sim_id);
    
    return unread_msg_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_is_full
 * DESCRIPTION
 *  The function is to check if the provbox service is full
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_provbox_is_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_num = srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX);
    
    if (msg_num >= SRV_PROVBOX_MAX_INBOX_MSG_NUM)
        result = MMI_TRUE;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_msg_sim_id
 * DESCRIPTION
 *  The function is to the sim id of message
 *  
 * PARAMETERS
 *  U32          [IN]
 *
 * RETURNS
 *  mmi_sim_enum
 *****************************************************************************/
mmi_sim_enum srv_provbox_get_msg_sim_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 list_idx = 0;
    U8 sim_id = 0;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_PROVBOX_INVALID_MSG_ID == msg_id)
    {
        return MMI_SIM_NONE;
    }
    
    srv_provbox_msg_get_list_index_by_id_and_box(cntx, 
        SRV_PROVBOX_BOX_TYPE_INBOX,
        msg_id,
        &msg_list,
        &list_idx);
    
    srv_provbox_msg_get_sim_id_by_index(msg_list, list_idx, &sim_id);
    
    return (mmi_sim_enum) sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_msg_id_by_idx
 * DESCRIPTION
 *  The function is to get message id by message index
 *  
 * PARAMETERS
 *  U32                       [IN]
 *  srv_provbox_box_type_enum [IN]
 *  U32 *                     [OUT]
 *
 * RETURNS
 *  srv_provbox_result_enum
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_get_msg_id_by_idx(U32 msg_idx, srv_provbox_box_type_enum box_type, U32 *msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum     result;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_msg_cmn_info_struct cmn_info;
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, box_type, NULL);
    
    result = srv_provbox_msg_get_list_info_by_index(msg_list, MMI_SIM_ALL, msg_idx, NULL, &cmn_info, NULL);

    if (msg_id)
        *msg_id = cmn_info.msg_id;

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_list_info
 * DESCRIPTION
 *  The function is to get message list info
 *  
 * PARAMETERS
 *  srv_provbox_list_info_struct* [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_get_list_info(srv_provbox_list_info_struct *list_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num = 0;
    U32 msg_list_index;
    U32 msg_next_index = 0;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_result_enum result;
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, list_info->box_type, NULL);
    
    msg_list_index = list_info->start_idx;

    do {
#ifdef __MMI_UM_FILTER_BY_SIM_SUPPORT__
        /* First to check SIM id and skip those message not match to the specific SIM id */
        mmi_sim_enum sim_id;
        srv_provbox_msg_base_info_struct *base_info;

        srv_provbox_dpary_get_elm_by_index(msg_list->msg_ah, msg_list_index, (void **)&base_info);
        if (!base_info)
        {
            result = SRV_PROVBOX_RESULT_NOT_FOUND;
            break;
        }
        sim_id = SRV_PROVBOX_SIM_IDX_TO_ID(SRV_PROVBOX_MSG_GET_SIM_ID(base_info));

        if (!SRV_PROVBOX_CHECK_FLAG(list_info->sim_id, sim_id))
        {
            msg_list_index++;
            continue;
        }

#endif /* __MMI_UM_FILTER_BY_SIM_SUPPORT__ */

        result = srv_provbox_msg_get_list_info_by_index(msg_list, 
                     list_info->sim_id, 
                     msg_list_index, 
                     &list_info->msg_size_list[msg_num], 
                     &list_info->cmn_info[msg_num], 
                     &msg_next_index);
                     
        if (result != SRV_PROVBOX_RESULT_OK)
            break;

        msg_num++;
        msg_list_index++;
    } while(msg_num < SRV_PROVBOX_MAX_GET_LIST_INFO_NUM && msg_num < list_info->msg_num);

    list_info->hdlr_msg_num = msg_num;

    /*
    if (msg_num < SRV_PROVBOX_MAX_GET_LIST_INFO_NUM)
        msg_next_index = SRV_PROVBOX_INVALID_NEXT_INDEX;
    */
    list_info->next_start_idx = msg_next_index;

    list_info->result = result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_msg_info_by_ids
 * DESCRIPTION
 *  The function is to get message information by message indexs
 *  
 * PARAMETERS
 *  srv_provbox_msg_info_struct* [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_get_msg_info_by_ids(srv_provbox_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 msg_id;
    U32 start_index;
    U32 next_start_msg_id;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK; 
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info->rsp_msg_num = 0;

    MMI_ASSERT(msg_info->req_msg_num <= SRV_PROVBOX_MAX_GET_LIST_INFO_NUM);

    next_start_msg_id = 0;
    
    for (i = 0; i < SRV_PROVBOX_FILE_MAX_OP_RECORD_NUM; i++)
    {
        if (msg_info->rsp_msg_num >= msg_info->req_msg_num)
            break;
            
        msg_list = srv_provbox_cntx_get_msg_list_by_msg_id(cntx, msg_info->msg_id[0], &start_index);
 
        msg_id = msg_info->msg_id[msg_info->rsp_msg_num];
        
        result = srv_provbox_msg_get_list_info_by_id(
                    msg_list,
                    msg_info->sim_id,
                    msg_id,
                    &msg_info->msg_size_list[msg_info->rsp_msg_num],
                    &msg_info->cmn_info[msg_info->rsp_msg_num],
                    &next_start_msg_id);

        msg_info->op_result[msg_info->rsp_msg_num] = result;
        /*
         * if (result != SRV_PROVBOX_RESULT_OK)
         * break;
         */
        msg_info->rsp_msg_num++;
        
        /*
        if (next_start_msg_id == SRV_PROVBOX_INVALID_MSG_ID)
            break;
        */
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_get_properties
 * DESCRIPTION
 *  The function is to get message properties
 *  
 * PARAMETERS
 *  srv_provbox_msg_properties_struct* [IN]
 *
 * RETURNS
 *  srv_provbox_result_enum
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_get_properties(srv_provbox_msg_properties_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_idx = 0;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_result_enum result;
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == data)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    msg_list = srv_provbox_cntx_get_msg_list_by_msg_id(cntx, data->msg_id, &msg_idx);
    
    result = srv_provbox_msg_get_list_info_by_id(msg_list, 
                 MMI_SIM_ALL, data->msg_id, 
                 &data->msg_size, &data->cmn_info, NULL);
    
    data->result = result;
 
    //srv_provbox_set_msg_status(data->msg_id, SRV_PROVBOX_MSG_READ_STATUS_READ);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete
 * DESCRIPTION
 *  The function is to delete message
 *  
 * PARAMETERS
 *  U32 [IN]
 *
 * RETURNS
 *  srv_provbox_result_enum
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_delete(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();
    srv_provbox_msg_list_struct *msg_list;
    //srv_provbox_delete_msg_req_struct *req_data;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_provbox_cntx_get_msg_list_by_msg_id(cntx, msg_id, &index);
    
    if (msg_list == NULL)
    {
        return SRV_PROVBOX_RESULT_OK;
    }

    result = srv_provbox_msg_delete_msg_by_index(msg_list, index);
    
    if (MMI_FALSE != srv_provbox_job_is_all_box_cleaned(cntx))
    {
        /* all box are clean now, so no need to save & show extra message, 
            but please to check if save any message fail before. */
        srv_provbox_handle_save_msg_again(cntx);
        //return SRV_PROVBOX_RESULT_OK;
    }
    
    if (result == SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_job_save_and_show_ext_msg(cntx, MMI_TRUE);
        srv_provbox_job_async_process_job(cntx, NULL);
        
        /* notify app or um about server state */
        /* a problem: delete a message when inbox is full and extra box have some msg
           on this case, server will send two notify. first notify is notify message is
           no full, secoud notify is notify message is full */
        srv_provbox_sent_box_full_event(cntx);

    #ifdef __MMI_PROV_IN_UM__
        srv_provbox_send_um_refresh_ind(SRV_UM_REFRESH_MSG_DELETED, msg_id, NULL);
    #endif
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_delete_all
 * DESCRIPTION
 *  The function is to delete all message
 *  
 * PARAMETERS
 *  srv_provbox_msg_delete_all_struct* [IN]
 *
 * RETURNS
 *  srv_provbox_result_enum
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_delete_all(srv_provbox_msg_delete_all_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_num;
    srv_provbox_msg_list_struct *msg_list;
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();
    srv_provbox_box_type_enum pbox_box_type;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;
    srv_provbox_check_info_struct check_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    pbox_box_type = data->box_type;
    
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, pbox_box_type, NULL);
    
    if (msg_list == NULL)
    {
        return SRV_PROVBOX_RESULT_OK;
    }
        
    if (data->del_all_type == SRV_PROVBOX_DEL_ALL_MSG_MODE_UNDEFINED)
    {
        msg_num = srv_provbox_msg_get_msg_num(msg_list, MMI_SIM_ALL);
        if (msg_num == 0)
        {
            return SRV_PROVBOX_RESULT_OK;
        }
       srv_provbox_file_set_check_info(
            &check_info,
            SRV_PROVBOX_CHECK_TYPE_DELETE_ALL,
            (U8) msg_list->box_type,
            SRV_PROVBOX_INVALID_MSG_ID,
            0,
            0,
            0,
            0);
        srv_provbox_file_write_check_file(&check_info);      /* may fail due to disk full, try it later. */
    }

    result = srv_provbox_msg_delete_all_msg(msg_list, &data->del_all_type, data->sim_id);

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_JOB_DELETE_ALL_MSG_HDLR, result);

    if (result == SRV_PROVBOX_RESULT_CONTINUE)
    {
        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    /* delete the check file even fail. */
    srv_provbox_file_delete_check_file(SRV_PROVBOX_CHECK_TYPE_DELETE_ALL, SRV_PROVBOX_INVALID_MSG_ID);

    /* check memory if there is provisioning message,
       check if there is provisioning message not showed in extern box,
       if some messages are saved in memory, append new save extern message job node to job list.
       if there is message in extra box, append new job node showed new message to job list.
       */
    srv_provbox_job_save_and_show_ext_msg(cntx, MMI_TRUE);

    /* async process job, send primitive message to provboxsrv */
    srv_provbox_job_async_process_job(cntx, NULL);

    /* send to provboxapp and um app to notify box state which is full or not. */
    srv_provbox_sent_box_full_event(cntx);
    
    /* send um to notify provbox srv state, indicate um to refresh UI */
#ifdef __MMI_PROV_IN_UM__
    srv_provbox_send_um_refresh_ind(SRV_UM_REFRESH_MSG_DELETED, 0, NULL);
#endif

    /* check if all box is cleaned. if clean, send request to provisiongsrv to get new message */
    if (MMI_FALSE != srv_provbox_job_is_all_box_cleaned(cntx))
    {
        /* all box are clean now, so no need to save & show extra message, 
         but please to check if save any message fail before. */
        srv_provbox_handle_save_msg_again(cntx);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_msg_multi_op_hdlr
 * DESCRIPTION
 *  The function is to do multi operation
 *  
 * PARAMETERS
 *  srv_provbox_msg_multi_op_struct* [IN]
 *
 * RETURNS
 *  srv_provbox_result_enum
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_msg_multi_op_hdlr(srv_provbox_msg_multi_op_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 multi_op_msg_num = 0;
    srv_provbox_msg_list_struct *msg_list;
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    srv_provbox_msg_list_struct *new_msg_list = NULL;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */
    srv_provbox_cntx_struct *cntx = srv_provbox_cntx_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, data->box_type, NULL);

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    if (SRV_PROVBOX_MSG_OP_MOVE_TO_ARCHIVE == data->op)
    {
        new_msg_list = srv_provbox_cntx_get_msg_list_by_box_type(cntx, SRV_PROVBOX_BOX_TYPE_ARCHIVE, NULL);
    }
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    for (i = 0; i < SRV_PROVBOX_FILE_MAX_OP_RECORD_NUM; i++)
    {
        if (multi_op_msg_num >= data->msg_num)
            break;

        if (data->op == SRV_PROVBOX_MSG_OP_DELETE)
        {
            data->op_result[multi_op_msg_num] = srv_provbox_msg_delete_msg_by_id(msg_list, data->msg_id[multi_op_msg_num]);
        }
        
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        else if (data->op == SRV_PROVBOX_MSG_OP_MOVE_TO_ARCHIVE)
        {
            data->op_result[multi_op_msg_num] = srv_provbox_msg_move_to_box_by_id(
                                                        msg_list,
                                                        new_msg_list,
                                                        data->msg_id[multi_op_msg_num],
                                                        NULL);
        }
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        multi_op_msg_num++;
    }
    /* if any more messages need to handle */
    if (multi_op_msg_num < data->msg_num)
    {
        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    
    //data->result = SRV_PROVBOX_RESULT_NOT_FOUND;

    srv_provbox_job_save_and_show_ext_msg(cntx, MMI_TRUE);
    srv_provbox_job_async_process_job(cntx, NULL);
    srv_provbox_sent_box_full_event(cntx);

    /* send um to notify provbox srv state, indicate um to refresh UI */
#ifdef __MMI_PROV_IN_UM__
    srv_provbox_send_um_refresh_ind(SRV_UM_REFRESH_MSG_DELETED, 0, NULL);
#endif

    return SRV_PROVBOX_RESULT_OK;
}


#ifdef __MMI_PROV_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  srv_provbox_handle_um_get_msg_num_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_handle_um_get_msg_num_req(srv_um_get_msg_num_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = MMI_SIM1;
    srv_um_get_msg_num_rsp_struct msg_num_rsp = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2) /* Due to UM part add this option */
    sim_id = srv_provbox_sim_um2pbox(data->sim_id);
#endif
    
    if (data->msg_type != SRV_UM_MSG_PROV)
    {
        msg_num_rsp.msg_type = SRV_UM_MSG_PROV;
        msg_num_rsp.result   = MMI_FALSE;
    }
    else
    {
        msg_num_rsp.msg_type = data->msg_type;
    
        msg_num_rsp.inbox_unread_msg_number = srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, sim_id);
        msg_num_rsp.inbox_read_msg_number   = srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX) - msg_num_rsp.inbox_unread_msg_number;

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    #ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        msg_num_rsp.archive_msg_number      = srv_provbox_get_msg_num(SRV_PROVBOX_BOX_TYPE_ARCHIVE);
    #else
        msg_num_rsp.archive_msg_number      = 0;
    #endif
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/* under construction !*/
    #endif
    #ifdef __MMI_UM_REPORT_BOX__
/* under construction !*/
    #endif
#endif//0    

        msg_num_rsp.result   = MMI_TRUE;            /* MMI_TRUE means OK; KAL_FALSE means failed */
    }

    srv_provbox_msg_send_um_get_msg_num_rsp(&msg_num_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_handle_um_get_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_handle_um_get_list_req(srv_um_get_msg_list_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_provbox_list_info_struct list_info = {0};
    srv_provbox_um_get_msg_list_rsp_struct msg_list_rsp = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list_rsp.app_id       = data->app_id;
    msg_list_rsp.result       = KAL_TRUE;
    msg_list_rsp.msg_type     = SRV_UM_MSG_PROV;
    msg_list_rsp.start_entry  = data->start_entry;
    msg_list_rsp.msg_box_type = data->msg_box_type;
    list_info.box_type         = srv_provbox_box_type_um2pbox(data->msg_box_type);

    /* incorrect state or msg type */
    if (data->msg_type != SRV_UM_MSG_PROV || SRV_PROVBOX_BOX_TYPE_UNKNOWN == list_info.box_type) // mmi_dmui_is_phone_lock
    {
        srv_provbox_msg_send_um_get_list_rsp(&msg_list_rsp);
        return;
    }

    /* get list info from server */
#if (MMI_MAX_SIM_NUM >= 2) /* Due to UM part add this option */
    list_info.sim_id    = srv_provbox_sim_um2pbox(data->sim_id);
#else
    list_info.sim_id = MMI_SIM1;
#endif

    list_info.start_idx = data->start_entry;
    list_info.msg_num   = SRV_PROVBOX_MAX_GET_SORT_INFO_NUM;

    /* read msg list info from server */
    srv_provbox_get_list_info(&list_info);
    
    /* fill msg_list_rsp_struct and send response to um */
    msg_list_rsp.more       = list_info.next_start_idx > 0 ? KAL_TRUE : KAL_FALSE;
    msg_list_rsp.msg_number = list_info.hdlr_msg_num;
    
    for (i = 0; i < msg_list_rsp.msg_number; i++)
    {
        msg_list_rsp.list_info[i].timestamp = list_info.cmn_info[i].timestamp;
        msg_list_rsp.list_info[i].msg_id    = list_info.cmn_info[i].msg_id;
    #if (MMI_MAX_SIM_NUM >= 2)
        msg_list_rsp.list_info[i].sim_id    = srv_provbox_sim_pbox2um((mmi_sim_enum)list_info.cmn_info[i].sim_id);
    #endif
    
    #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
        /* fill sort union struct to sort list */
        srv_provbox_event_send_set_sort_info_ind(
            &msg_list_rsp.list_idx_data[i], 
            &list_info.cmn_info[i],
            list_info.msg_size_list[i], 
            data->list_idx_type);
    #endif
    }
    
    srv_provbox_msg_send_um_get_list_rsp(&msg_list_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_handle_um_get_msg_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_handle_um_get_msg_info_req(srv_um_get_msg_info_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_provbox_msg_info_struct msg_info        = {0};
    srv_um_get_msg_info_rsp_struct msg_info_rsp = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info_rsp.app_id       = data->app_id;
    msg_info_rsp.msg_type     = data->msg_type;
    msg_info_rsp.msg_box_type = data->msg_box_type;
    msg_info.box_type         = srv_provbox_box_type_um2pbox(data->msg_box_type);

    if (SRV_UM_MSG_PROV != data->msg_type || SRV_PROVBOX_BOX_TYPE_UNKNOWN == msg_info.box_type)
    {
        srv_provbox_send_um_get_msg_info_rsp(&msg_info_rsp);
        return;
    }

    msg_info.sim_id      = MMI_SIM_ALL;
    msg_info.req_msg_num = data->msg_number;

    if (msg_info.req_msg_num > SRV_PROVBOX_MAX_GET_LIST_INFO_NUM )
    {
        msg_info.req_msg_num  = SRV_PROVBOX_MAX_GET_LIST_INFO_NUM;
    }

    for (i = 0; i < msg_info.req_msg_num; i++)
    {
        msg_info.op_result[i] = SRV_PROVBOX_RESULT_FAIL;
    }
    memcpy((void *)msg_info.msg_id, (const void*)data->msg_id, sizeof(U32)*msg_info.req_msg_num);

    srv_provbox_get_msg_info_by_ids(&msg_info);

    for (i = 0; i < msg_info.rsp_msg_num; i++)
    {
        msg_info_rsp.msg_id[i] = msg_info.msg_id[i];
        msg_info_rsp.result[i] = (SRV_PROVBOX_RESULT_OK == msg_info.op_result[i] ?  KAL_TRUE : KAL_FALSE);
        srv_provbox_event_send_set_msg_info_ind(&msg_info_rsp.msg_info[i], &msg_info.cmn_info[i]);
    }
   
    msg_info_rsp.msg_number   = msg_info.rsp_msg_num;
    
    srv_provbox_send_um_get_msg_info_rsp(&msg_info_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_handle_um_delete_folder_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_handle_um_delete_folder_req(srv_um_delete_folder_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  bit_idx = 0;
    srv_provbox_box_type_enum pbox_box_type = SRV_PROVBOX_BOX_TYPE_UNKNOWN;
	srv_provbox_box_type_enum delete_box_type = SRV_PROVBOX_BOX_TYPE_UNKNOWN;
    srv_provbox_result_enum   result = SRV_PROVBOX_RESULT_FAIL;
    srv_provbox_msg_delete_all_struct delete_all_data = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Handle DM phone lock*/ //mmi_dmui_is_phone_lock
    pbox_box_type = srv_provbox_box_type_um2pbox(data->msg_box_type);
    
    if (SRV_PROVBOX_BOX_TYPE_UNKNOWN == pbox_box_type)
    {
        srv_provbox_send_um_delete_folder_rsp(SRV_PROVBOX_RESULT_OK);
        return;
    }

    do {
        if (SRV_PROVBOX_RESULT_CONTINUE != result)
        {
            if (delete_box_type != pbox_box_type & (0X01 << bit_idx))
            {
               bit_idx++;
               continue;
            }
        
            pbox_box_type &= ~(0X01 << bit_idx);
            bit_idx++;
        }
        
        delete_all_data.box_type     = delete_box_type;
        delete_all_data.del_all_type = SRV_PROVBOX_DEL_ALL_MSG_MODE_UNDEFINED;
        delete_all_data.sim_id = srv_provbox_sim_um2pbox(data->sim_id);
        
        result = srv_provbox_msg_delete_all(&delete_all_data);
    } while(pbox_box_type || SRV_PROVBOX_RESULT_CONTINUE == result);

    srv_provbox_send_um_delete_folder_rsp(result);
}


#ifdef __MMI_UM_CONVERSATION_BOX__
/*****************************************************************************
 * FUNCTION
 *  srv_provboxui_handle_um_traverse_msg_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_handle_um_traverse_msg_req(mmi_um_traverse_msg_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->start_entry >= 0)
    {
       srv_provbox_um_traverse_get_msg_info_by_index(data);
    }
    else if (-1 == data->start_entry)
    {
        srv_provbox_um_traverse_get_msg_info_by_ids(data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_um_traverse_get_msg_info_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_um_traverse_msg_req_struct*        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_um_traverse_get_msg_info_by_index(srv_um_traverse_msg_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_more_msg = MMI_FALSE;
    srv_provbox_list_info_struct msg_list_info  = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_provbox_um_traverse_unexception_hdlr(data))
    {
        return;
    }

    msg_list_info.box_type  = srv_provbox_box_type_um2pbox(data->msg_box_type);
    msg_list_info.msg_num   = SRV_PROVBOX_MAX_GET_LIST_INFO_NUM;
    msg_list_info.start_idx = data->start_entry;
    msg_list_info.sim_id    = MMI_SIM_ALL;
    
    /* get msg_list_info from provboxsrv */
    srv_provbox_get_list_info(&msg_list_info);
    
    if (msg_list_info.next_start_idx == MMI_PROVBOX_INVALID_NEXT_INDEX)
    {
        msg_list_info.msg_num = msg_list_info.hdlr_msg_num;
    }
    else
    {
        is_more_msg = MMI_TRUE;
        msg_list_info.msg_num = msg_list_info.next_start_idx - msg_list_info.start_idx;
    }
    
    srv_provbox_um_traverse_msg_info_hdlr(
        msg_list_info.msg_num, is_more_msg,
        msg_list_info.msg_size_list,
        msg_list_info.cmn_info, data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_um_traverse_get_msg_info_by_ids
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_um_traverse_msg_req_struct*        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_um_traverse_get_msg_info_by_ids(srv_um_traverse_msg_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_more_msg = MMI_FALSE;
    srv_provbox_msg_info_struct msg_info = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info.sim_id      = MMI_SIM_ALL;
    msg_info.box_type    = srv_provbox_box_type_um2pbox(data->msg_box_type);
    msg_info.req_msg_num = data->msg_number;
    
    /* when um request msg number is more than max get list info num, provbox should make the request
       message number just to be max number. Because the large number be handle in a ansync process, 
       mmi task always run get list info of provbox and message queue will full. */
    if (data->msg_number > SRV_PROVBOX_MAX_GET_LIST_INFO_NUM)
    {
        msg_info.req_msg_num = SRV_PROVBOX_MAX_GET_LIST_INFO_NUM;
        is_more_msg          = MMI_TRUE;
    }
    
    memcpy((void *)msg_info.msg_id, (const void*)data->msg_id, sizeof(U32) * msg_info.req_msg_num);
    
    srv_provbox_get_msg_info_by_ids(&msg_info);
    
    srv_provbox_um_traverse_msg_info_hdlr(
        msg_info.rsp_msg_num, is_more_msg,
        msg_info.msg_size_list,
        msg_info.cmn_info, data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_um_traverse_msg_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_um_traverse_msg_req_struct*        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_um_traverse_msg_info_hdlr(
                U32 hdlr_msg_num, 
                MMI_BOOL is_more_msg, 
                S16 *msg_size_list,
                srv_provbox_msg_cmn_info_struct *msg_cmn_info,
                srv_um_traverse_msg_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 traverse_ret;
    U32 traverse_num;
    mmi_um_traverse_msg_rsp_struct traverse_msg_rsp = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    traverse_num = 0;

    for (i = 0; i < hdlr_msg_num; i++)
    {
        /* traverse message info to um by traverse callback fucntion */
        traverse_ret = srv_provbox_evnet_send_set_traverse_process_msg_deatil_ind(
                           &msg_cmn_info[i], 
                           msg_size_list[i],
                           data->user_data,
                           data->field,
                           data->traverse_func);

        if (traverse_ret == SRV_UM_RESULT_BUFFER_FULL)
        {
            traverse_msg_rsp.result     = MMI_TRUE;
            traverse_msg_rsp.more       = MMI_TRUE;
            traverse_msg_rsp.msg_number = traverse_num;
            
            srv_provbox_send_um_traverse_msg_rsp(&traverse_msg_rsp);
            return;
        }
        else if (traverse_ret == SRV_UM_RESULT_CANCELLLED)
        {
            traverse_msg_rsp.result     = MMI_FALSE;
            traverse_msg_rsp.more       = MMI_FALSE;
            traverse_msg_rsp.msg_number = traverse_num;
            
            srv_provbox_send_um_traverse_msg_rsp(&traverse_msg_rsp);
            return;
        }
        else if (traverse_ret != SRV_UM_RESULT_OK)
        {
            MMI_ASSERT(0);
        }

        traverse_num++;
    }

    traverse_msg_rsp.more       = is_more_msg;
    traverse_msg_rsp.result     = MMI_TRUE;
    traverse_msg_rsp.msg_number = traverse_num;
    
    srv_provbox_send_um_traverse_msg_rsp(&traverse_msg_rsp);
}



/*****************************************************************************
 * FUNCTION
 *  srv_provbox_um_traverse_unexception_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_um_traverse_msg_req_struct*        [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_provbox_um_traverse_unexception_hdlr(srv_um_traverse_msg_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_traverse_msg_rsp_struct traverse_msg_rsp = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    traverse_msg_rsp.app_id   = data->app_id;
    traverse_msg_rsp.msg_type = data->msg_type;
    
    if (SRV_UM_MSG_BOX_INBOX != data->msg_box_type)//mmi_dmui_is_phone_lock())
    {
        traverse_msg_rsp.result = MMI_TRUE;
        srv_provbox_send_um_traverse_msg_rsp(&traverse_msg_rsp);
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}

#endif /* __MMI_UM_CONVERSATION_BOX__ */


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_provboxui_handle_um_multi_op_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_handle_um_multi_op_req(srv_um_mark_several_op_req_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_provbox_result_enum multi_op_result;
    srv_um_mark_several_op_rsp_struct multi_op_rsp  = {0};
    srv_provbox_msg_multi_op_struct multi_op_info;
	memset(&multi_op_info, 0x00, sizeof(srv_provbox_msg_multi_op_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    multi_op_rsp.msg_type     = data->msg_type;
    multi_op_rsp.app_id       = data->app_id;
    multi_op_rsp.msg_box_type = data->msg_box_type;
    multi_op_rsp.action_type  = data->action_type;
    multi_op_rsp.msg_number   = data->msg_number;
    memcpy(multi_op_rsp.msg_id, data->msg_id, sizeof(kal_uint32) * SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);
        
    /* Handle DM phone lock*/ //mmi_dmui_is_phone_lock

    /* initial multi op info */
    multi_op_info.op       = srv_provbox_op_type_um2pbox(data->action_type);
    multi_op_info.box_type = srv_provbox_box_type_um2pbox(data->msg_box_type);
    
    if (SRV_PROVBOX_MSG_OP_NONE == multi_op_info.op || 
        SRV_PROVBOX_BOX_TYPE_UNKNOWN == multi_op_info.box_type)
    {
        srv_provbox_send_um_multi_op_rsp(&multi_op_rsp);
    }

    multi_op_info.msg_num  = data->msg_number;
    memcpy((void*)multi_op_info.msg_id, (const void*)data->msg_id, sizeof(U32)*data->msg_number);

    do {
        /* do multi op handler */
        multi_op_result = srv_provbox_msg_multi_op_hdlr(&multi_op_info);
    } while (SRV_PROVBOX_RESULT_CONTINUE == multi_op_result);
    
    for (i = 0; i < data->msg_number; i++)
    {
        multi_op_rsp.action_result[i] = (MMI_BOOL)(SRV_PROVBOX_RESULT_OK == multi_op_info.op_result[i]);
    }

    srv_provbox_send_um_multi_op_rsp(&multi_op_rsp);
}

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_main_um_set_msg_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  U32                              [IN]
 *  srv_provbox_msg_read_status_enum [IN]
 *  srv_provbox_callback_func        [IN]
 *
 * RETURNS
 *  srv_provbox_result_enum
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_main_um_set_msg_state(
                            U32 msg_id, 
                            srv_provbox_msg_read_status_enum status,
                            srv_provbox_callback_func callback_func,
                            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI__
    
    result = srv_provbox_set_msg_status(msg_id, status);
    
    srv_provbox_event_send_set_msg_state_ready_ind(callback_func, result, user_data);
#endif

    return result;
}

#endif /* __MMI_PROV_IN_UM__ */

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

