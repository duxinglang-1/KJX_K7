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
 * mma_interface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions which are used to configure MMS service.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMA_INTERFACE_C
#define _MMA_INTERFACE_C

#if defined(MMS_SUPPORT)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "wapadp.h"
#include "mmsadp.h"
#include "app_str.h"
#include "conversions.h"
#include "FileMgrSrvGProt.h"
#include "fmt_struct.h"       /* For handling MSG_ID_MMI_FMT_FORMAT_REQ */


/* FS */
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
/* Plutommi */
#include "MMI_features.h"
#include "UmSrvStruct.h"
#include "UmSrvDefs.h"
/* MSF */
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */
#include "msf_core.h"   /* MSF: System core call */
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_cmmn.h"   /* MSF: MSF common functions, e.g. string handling */
#include "msf_pipe.h"   /* MSF: Pipe handling */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_chrs.h"
#include "msm.h"

/* STK */
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "stk_if.h"     /* STK: WSP/HTTP Stack signals and types */
#else
#include "nts_if.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

/* MMS */
#include "mms_cfg.h"    /* MMS: Configuration definitions */
#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_if.h"     /* MMS: Exported signal interface */
#include "mmsl_if.h"
#include "mconfig.h"
#include "msig.h"
#include "mmem.h"
#include "fldmgr.h"
#include "mms_aApp.h"
/* SLS */
#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"
/* MMA */
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_env.h"
#include "mma_utilities.h"
#include "mma_msgmgr.h"
#include "mma_interface.h"
#include "mma_main.h"
#ifdef __MMI_VCARD__
#include "MmsSrvGprot.h"
#endif  // __MMI_VCARD__

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern mms_mma_queue_struct *g_mma_wrapper_queue;

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_set_mms_setting_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dst_id      [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_set_mms_setting_rsp(module_type dst_id, kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_setting_rsp_struct *set_mms_setting_rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_mms_setting_rsp_p =
        (wap_mma_set_setting_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_set_setting_rsp_struct),
                                            TD_CTRL | TD_RESET);

    set_mms_setting_rsp_p->app_id = app_id;
    set_mms_setting_rsp_p->req_id = req_id;
    set_mms_setting_rsp_p->result = result;
    mms_mma_send_ilm(set_mms_setting_rsp_p, NULL, MSG_ID_WAP_MMA_SET_SETTING_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_setting_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  get_setting_rsp_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_setting_rsp(module_type source, wap_mma_get_setting_rsp_struct *get_setting_rsp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_setting_rsp_struct *get_setting_rsp_local_parm_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_setting_rsp_local_parm_p =
        (wap_mma_get_setting_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_get_setting_rsp_struct),
                                            TD_CTRL | TD_RESET);

    get_setting_rsp_local_parm_p->app_id = get_setting_rsp_p->app_id;
    get_setting_rsp_local_parm_p->req_id = get_setting_rsp_p->req_id;
    get_setting_rsp_local_parm_p->result = get_setting_rsp_p->result;
    if (get_setting_rsp_p->result == MMA_RESULT_OK)
    {
        get_setting_rsp_local_parm_p->mms_version = get_setting_rsp_p->mms_version;
        get_setting_rsp_local_parm_p->creation_mode = get_setting_rsp_p->creation_mode;
        get_setting_rsp_local_parm_p->priority = get_setting_rsp_p->priority;
        get_setting_rsp_local_parm_p->validity_period = get_setting_rsp_p->validity_period;
        get_setting_rsp_local_parm_p->delivery_time = get_setting_rsp_p->delivery_time;
        get_setting_rsp_local_parm_p->delivery_report = get_setting_rsp_p->delivery_report;
        get_setting_rsp_local_parm_p->read_report = get_setting_rsp_p->read_report;
        get_setting_rsp_local_parm_p->max_mms_size = get_setting_rsp_p->max_mms_size;
        get_setting_rsp_local_parm_p->image_resize = get_setting_rsp_p->image_resize;
        get_setting_rsp_local_parm_p->signature = get_setting_rsp_p->signature;
        get_setting_rsp_local_parm_p->sliding_time = get_setting_rsp_p->sliding_time;
        get_setting_rsp_local_parm_p->layout = get_setting_rsp_p->layout;
        get_setting_rsp_local_parm_p->add_as_drm = get_setting_rsp_p->add_as_drm;
        get_setting_rsp_local_parm_p->max_no_pages = get_setting_rsp_p->max_no_pages;
        get_setting_rsp_local_parm_p->best_page_duration = get_setting_rsp_p->best_page_duration;
        get_setting_rsp_local_parm_p->reply_charging = get_setting_rsp_p->reply_charging;
        get_setting_rsp_local_parm_p->request_type = get_setting_rsp_p->request_type;
        get_setting_rsp_local_parm_p->deadline_for_reply = get_setting_rsp_p->deadline_for_reply;
        get_setting_rsp_local_parm_p->hide_sender = get_setting_rsp_p->hide_sender;
        get_setting_rsp_local_parm_p->size = get_setting_rsp_p->size;
        get_setting_rsp_local_parm_p->retrieval_setting.advertisement_filter =
            get_setting_rsp_p->retrieval_setting.advertisement_filter;
        get_setting_rsp_local_parm_p->retrieval_setting.home_network =
            get_setting_rsp_p->retrieval_setting.home_network;
        get_setting_rsp_local_parm_p->retrieval_setting.roaming = get_setting_rsp_p->retrieval_setting.roaming;
        get_setting_rsp_local_parm_p->retrieval_setting.anonymous_filter =
            get_setting_rsp_p->retrieval_setting.anonymous_filter;
        get_setting_rsp_local_parm_p->retrieval_setting.delivery_report =
            get_setting_rsp_p->retrieval_setting.delivery_report;
    }
    mms_mma_send_ilm(get_setting_rsp_local_parm_p, NULL, MSG_ID_WAP_MMA_GET_SETTING_RSP, source);
}

#ifdef __MMI_MMS_USE_ASM__
/*****************************************************************************
 * FUNCTION
 *  MMAif_getAsmMemory
 * DESCRIPTION
 *  This function is used to send the primitive for requesting ASM memory
 * PARAMETERS
 *  req_id                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getAsmMemory(kal_uint32 req_id)
{
    mmi_mms_get_asm_pool_req_struct *req = NULL;

    req =
    (mmi_mms_get_asm_pool_req_struct*) construct_local_para(
                                        sizeof(mmi_mms_get_asm_pool_req_struct),
                                        TD_CTRL | TD_RESET);

    req->req_id = req_id;



    mms_mma_send_ilm(req, NULL, MSG_ID_MMI_MMS_GET_ASM_MEM_PTR_REQ, MOD_MMI);
}

/*****************************************************************************
 * FUNCTION
 *  MMAif_getAsmMemory
 * DESCRIPTION
 *  This function is used to send the primitive for freeing ASM memory
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_freeAsmMemory()
{
    mms_mma_send_ilm(NULL, NULL, MSG_ID_MMI_MMS_FREE_ASM_MEM_PTR_REQ, MOD_MMI);
}

/*****************************************************************************
 * FUNCTION
 *  MMAif_senddeinitasmMem
 * DESCRIPTION
 *  This function is used for notifying that ASM memory is released
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_senddeinitasmMem()
{
   mmi_mms_get_deinit_asm_pool_rsp_struct   *deinit_asm_pool_rsp_struct = NULL;

    deinit_asm_pool_rsp_struct =
    (mmi_mms_get_deinit_asm_pool_rsp_struct*) construct_local_para(
                                        sizeof(mmi_mms_get_deinit_asm_pool_rsp_struct),
                                        TD_CTRL | TD_RESET);

    deinit_asm_pool_rsp_struct->result = MMA_RESULT_OK;


    mms_mma_send_ilm(deinit_asm_pool_rsp_struct, NULL, MSG_ID_MMI_MMS_GET_DEINIT_SERVICE_ASM_RSP, MOD_MMI);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_asmMemRsp
 * DESCRIPTION
 *  This function is used for handling GET_ASM_POOL_RSP
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_asmMemRsp(void *get_asm_pool_rsp_struct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_get_asm_pool_rsp_struct *get_asm_pool_rsp_struct_p = NULL;
	mmi_mms_get_asm_pool_rsp_struct *get_asm_pool_rsp_struct_temp_p = (mmi_mms_get_asm_pool_rsp_struct *)get_asm_pool_rsp_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_asm_pool_rsp_struct_temp_p);

    get_asm_pool_rsp_struct_p =
        (mmi_mms_get_asm_pool_rsp_struct*) MMA_CALLOC(sizeof(mmi_mms_get_asm_pool_rsp_struct));

    memcpy(
        (char*)get_asm_pool_rsp_struct_p,
        (char*)get_asm_pool_rsp_struct_temp_p,
        sizeof(mmi_mms_get_asm_pool_rsp_struct));

    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_PARSE,
        MMA_INT_SIG_TYPE_MSG_GET_ASM_POOL_RSP,
        0,
        get_asm_pool_rsp_struct_p);

   
}

/*****************************************************************************
 * FUNCTION
 *  MMAif_deinitasmMem
 * DESCRIPTION
 *  This function is used for handling DEINIT_ASM_POOL_REQ from application
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_deinitasmMem(void * deinit_asm_req_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_get_deinit_asm_pool_req_struct *deinit_asm_req_struct_p = NULL;
	mmi_mms_get_deinit_asm_pool_req_struct *deinit_asm_req_struct_temp_p = (mmi_mms_get_deinit_asm_pool_req_struct *)deinit_asm_req_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(deinit_asm_req_struct_temp_p);

    deinit_asm_req_struct_p =
        (mmi_mms_get_deinit_asm_pool_req_struct*) MMA_CALLOC(sizeof(mmi_mms_get_deinit_asm_pool_req_struct));

    memcpy(
        (char*)deinit_asm_req_struct_p,
        (char*)deinit_asm_req_struct_temp_p,
        sizeof(mmi_mms_get_deinit_asm_pool_req_struct));

    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_PARSE,
        MMA_INT_SIG_TYPE_MSG_DEINIT_ASM_POOL_REQ,
        0,
        deinit_asm_req_struct_p);
    
}
#endif /* __MMI_MMS_USE_ASM__*/
#ifdef __MMI_VCARD__
/*****************************************************************************
 * FUNCTION
 *  MMAif_isvcardrestricted
 * DESCRIPTION
 *  This function is used to send MSG_ID_MMI_UMMS_GET_VCARD_VERSION_REQ
 * PARAMETERS
 *  source                  [IN]        
 *  get_setting_rsp_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_isvcardrestricted(char *filepath, kal_uint32 size, kal_uint32 offset, kal_uint8 storage)
{
    srv_mms_get_vcard_version_req_struct *get_vcard_version_local_param_p = NULL;
    char *filename_ucs2 = NULL;

    get_vcard_version_local_param_p =
    (srv_mms_get_vcard_version_req_struct*) construct_local_para(
                                        sizeof(srv_mms_get_vcard_version_req_struct),
                                        TD_CTRL | TD_RESET);

    filename_ucs2 = (char*)MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, filepath, storage);    
    
    
    memcpy(get_vcard_version_local_param_p->filepath , filename_ucs2, app_ucs2_strlen((kal_int8*)filename_ucs2) * ENCODING_LENGTH);
    get_vcard_version_local_param_p->size = size;
    get_vcard_version_local_param_p->offset = offset;

    mms_mma_send_ilm(get_vcard_version_local_param_p, NULL, MSG_ID_MMI_UMMS_GET_VCARD_VERSION_REQ, MOD_MMI);
    MMA_FREE(filename_ucs2);

}

/*****************************************************************************
 * FUNCTION
 *  MMAif_isvcardrestrictedrsp
 * DESCRIPTION
 *  This function is used to handle  MSG_ID_MMI_UMMS_GET_VCARD_VERSION_RSP
 * PARAMETERS
 *  source                  [IN]        
 *  get_setting_rsp_p       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_isvcardrestrictedrsp(srv_mms_get_vcard_version_rsp_struct  *mms_mma_vcard_version_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_vcard_version_rsp_struct *mms_mma_vcard_version_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mms_mma_vcard_version_p);

    mms_mma_vcard_version_input_p =
        (srv_mms_get_vcard_version_rsp_struct*) MMA_CALLOC(sizeof(srv_mms_get_vcard_version_rsp_struct));
    memcpy(
        (char*)mms_mma_vcard_version_input_p,
        (char*)mms_mma_vcard_version_p,
        sizeof(srv_mms_get_vcard_version_rsp_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_PARSE,
        MMA_INT_SIG_TYPE_MSG_VCARD_VERSION_RSP,
        0,
        mms_mma_vcard_version_input_p);
}
#endif // __MMI_VCARD__
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_mem_status_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dst_id          [IN]        
 *  app_id          [IN]        
 *  req_id          [IN]        
 *  result          [IN]        
 *  used_size       [IN]        
 *  free_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_mem_status_rsp(
        module_type dst_id,
        kal_uint8 app_id,
        kal_uint32 req_id,
        mma_result_enum result,
        kal_uint32 used_size,
        kal_uint64 free_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_mem_status_rsp_struct *get_mem_status_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_mem_status_rsp =
        (wap_mma_get_mem_status_rsp_struct*) construct_local_para(
                                                sizeof(wap_mma_get_mem_status_rsp_struct),
                                                TD_CTRL | TD_RESET);

    get_mem_status_rsp->app_id = app_id;
    get_mem_status_rsp->req_id = req_id;
    get_mem_status_rsp->result = result;
    get_mem_status_rsp->used_size = used_size;
    get_mem_status_rsp->free_size = free_size;
    mms_mma_send_ilm(get_mem_status_rsp, NULL, MSG_ID_WAP_MMA_GET_MEM_STATUS_RSP, dst_id);
}


#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_set_app_data_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dst_id      [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_set_app_data_rsp(
        module_type dst_id,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint32 msg_id,
        mma_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_app_data_rsp_struct *set_app_data_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_app_data_rsp =
        (wap_mma_set_app_data_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_set_app_data_rsp_struct),
                                            TD_CTRL | TD_RESET);

    set_app_data_rsp->app_id = app_id;
    set_app_data_rsp->req_id = req_id;
    set_app_data_rsp->msg_id = msg_id;
    set_app_data_rsp->result = result;
    mms_mma_send_ilm(set_app_data_rsp, NULL, MSG_ID_WAP_MMA_SET_APP_DATA_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_set_readmark_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dst_id      [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_set_readmark_rsp(module_type dst_id, kal_uint32 app_id, kal_uint32 req_id, mma_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_readmark_rsp_struct *set_readmark_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_readmark_rsp =
        (wap_mma_set_readmark_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_set_readmark_rsp_struct),
                                            TD_CTRL | TD_RESET);

    set_readmark_rsp->app_id = app_id;
    set_readmark_rsp->req_id = req_id;
    set_readmark_rsp->result = result;
    mms_mma_send_ilm(set_readmark_rsp, NULL, MSG_ID_WAP_MMA_SET_READMARK_RSP, dst_id);
}

#endif  /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_um_get_msg_num_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                              [IN]        
 *  app_id                              [IN]        
 *  result                              [IN]        
 *  msg_type                            [IN]        
 *  inbox_unread_msg_number             [IN]        
 *  inbox_read_msg_number               [IN]        
 *  unsent_msg_number                   [IN]        
 *  sent_msg_number                     [IN]        
 *  draft_msg_number                    [IN]        
 *  predefined_template_msg_number      [IN]        
 *  userdefined_template_msg_number     [IN]        
 *  archive_msg_number                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_um_get_msg_num_rsp(
        module_type source,
        kal_uint32 app_id,
        kal_bool result,
        /* KAL_TRUE means OK; KAL_FALSE means failed */ kal_uint16 msg_type,
        /* srv_um_msg_enum */ kal_uint16 inbox_unread_msg_number,
        kal_uint16 inbox_read_msg_number,
        kal_uint16 unsent_msg_number,
        kal_uint16 sent_msg_number,
        kal_uint16 draft_msg_number,
        kal_uint16 predefined_template_msg_number,
        kal_uint16 userdefined_template_msg_number,
        kal_uint16 archive_msg_number,
        kal_uint16 report_msg_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_num_rsp_struct *get_msg_num_rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_msg_num_rsp_p =
        (srv_um_get_msg_num_rsp_struct*) construct_local_para(
                                            sizeof(srv_um_get_msg_num_rsp_struct),
                                            TD_CTRL | TD_RESET);

    get_msg_num_rsp_p->app_id = app_id;
    get_msg_num_rsp_p->result = result;
    get_msg_num_rsp_p->msg_type = (srv_um_msg_enum)msg_type;
    if (msg_type != SRV_UM_MSG_MMS)
    {
        ASSERT(0);
    }
    get_msg_num_rsp_p->inbox_read_msg_number = inbox_read_msg_number;
    get_msg_num_rsp_p->inbox_unread_msg_number = inbox_unread_msg_number;
    get_msg_num_rsp_p->unsent_msg_number = unsent_msg_number;
    get_msg_num_rsp_p->sent_msg_number = sent_msg_number;
    get_msg_num_rsp_p->userdefined_template_msg_number = userdefined_template_msg_number;
    get_msg_num_rsp_p->draft_msg_number = draft_msg_number;
    get_msg_num_rsp_p->predefined_template_msg_number = predefined_template_msg_number;
#if defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)
    get_msg_num_rsp_p->archive_msg_number = archive_msg_number;
#endif
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    get_msg_num_rsp_p->report_msg_number = report_msg_number;
#endif
    mms_mma_send_ilm(get_msg_num_rsp_p, NULL, MSG_ID_MMI_UM_GET_MSG_NUM_RSP, source);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_um_get_list_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source              [IN]        
 *  app_id              [IN]        
 *  result              [IN]        
 *  msg_type            [IN]        
 *  msg_box_type        [IN]        
 *  start_entry         [IN]        
 *  msg_number          [IN]        
 *  list_info           [IN]         
 *  more                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_um_get_list_rsp(
        module_type source,
        kal_uint32 app_id,
        /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */ kal_bool result,
        /* KAL_TRUE means OK; KAL_FALSE means failed */ kal_uint32 msg_type,
        /* srv_um_msg_enum */ kal_uint32 msg_box_type,
        /* Type of message box srv_um_msg_box_enum */ kal_uint16 start_entry,
        kal_uint16 msg_number,
        /* Number of messages in this response primitive */ void *list_info,
        /* srv_um_msg_list_struct list_info[SRV_UM_MAX_GET_MSG_LIST_NUMBER] */ kal_bool more, /* If there are more msgs besides this response primitive */
        void* list_idx_data, kal_uint16 list_idx_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_list_rsp_struct *get_list_rsp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_rsp_p =
        (srv_um_get_msg_list_rsp_struct*) construct_local_para(sizeof(srv_um_get_msg_list_rsp_struct), TD_CTRL | TD_RESET);

    get_list_rsp_p->app_id = app_id;
    get_list_rsp_p->result = result;
    get_list_rsp_p->msg_type = (srv_um_msg_enum)msg_type;
    get_list_rsp_p->msg_box_type = (srv_um_msg_box_enum)msg_box_type;
    get_list_rsp_p->start_entry = start_entry;
    get_list_rsp_p->msg_number = msg_number;
    if (list_info != NULL)
    {
        memcpy(
            (char*)(get_list_rsp_p->list_info),
            (char*)list_info,
            sizeof(srv_um_msg_list_struct) * SRV_UM_MAX_GET_MSG_LIST_NUMBER);
    }
    get_list_rsp_p->more = more;
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    if(list_idx_data != NULL)
    {
        memcpy(
            (char*)(get_list_rsp_p->list_idx_data),
            (char*)list_idx_data,
            sizeof(srv_um_list_idx_data_union) * SRV_UM_MAX_GET_MSG_LIST_NUMBER);
    }
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
    mms_mma_send_ilm(get_list_rsp_p, NULL, MSG_ID_MMI_UM_GET_MSG_LIST_RSP, source);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_um_get_msg_info_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source              [IN]        
 *  app_id              [IN]        
 *  result              [IN]        
 *  msg_type            [IN]        
 *  msg_box_type        [IN]        
 *  start_entry         [IN]        
 *  msg_number          [IN]        
 *  msg_info            [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_um_get_msg_info_rsp(
        module_type source,
        kal_uint32 app_id,
        kal_bool *result,
        kal_uint32 *msg_id,
        kal_uint32 msg_type,
        kal_uint32 msg_box_type,
        kal_uint16 msg_number,
        void *msg_info )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_rsp_struct *get_msg_info_rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_msg_info_rsp_p =
        (srv_um_get_msg_info_rsp_struct*) construct_local_para(
                                        sizeof(srv_um_get_msg_info_rsp_struct),
                                        TD_CTRL | TD_RESET);
    if (result != NULL)
    {
        memcpy((char*)get_msg_info_rsp_p->result, (char*)result, sizeof(kal_bool) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);
    }
    get_msg_info_rsp_p->app_id = (kal_uint8)app_id;
    get_msg_info_rsp_p->msg_type = (srv_um_msg_enum) SRV_UM_MSG_MMS;
    get_msg_info_rsp_p->msg_box_type = (srv_um_msg_box_enum)msg_box_type;
    get_msg_info_rsp_p->msg_number = msg_number;

	if (msg_id != NULL)
    {
        memcpy((char*)get_msg_info_rsp_p->msg_id, (char*)msg_id, sizeof(kal_uint32) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);
    }
    
    if (msg_info != NULL)
    {
        memcpy(
            (char*)(get_msg_info_rsp_p->msg_info),
            (char*)msg_info,
            sizeof(srv_um_msg_info_struct) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);
    }
    mms_mma_send_ilm(get_msg_info_rsp_p, NULL, MSG_ID_MMI_UM_GET_MSG_INFO_RSP, source);
}


#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_msg_num_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                              [IN]        
 *  app_id                              [IN]        
 *  result                              [IN]        
 *  msg_type                            [IN]        
 *  inbox_unread_msg_number             [IN]        
 *  inbox_read_msg_number               [IN]        
 *  unsent_msg_number                   [IN]        
 *  sent_msg_number                     [IN]        
 *  draft_msg_number                    [IN]        
 *  predefined_template_msg_number      [IN]        
 *  userdefined_template_msg_number     [IN]        
 *  archive_msg_number                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_msg_num_rsp(
        module_type source,
        kal_uint32 app_id,
		kal_uint32 req_id,
        kal_bool result,
        wap_mma_get_msg_num_rsp_struct get_msg_num_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_num_rsp_struct *get_msg_num_rsp_p;
	kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_msg_num_rsp_p =
        (wap_mma_get_msg_num_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_get_msg_num_rsp_struct),
                                            TD_CTRL | TD_RESET);

    get_msg_num_rsp_p->app_id = app_id;
    get_msg_num_rsp_p->result = result;
	get_msg_num_rsp_p->req_id = req_id;
	for(i = 0; i < MMA_MAX_MSG_NUM_QUERY_NUM; i++)
	{
		get_msg_num_rsp_p->rsp_tb[i] = get_msg_num_rsp.rsp_tb[i];
	}
    mms_mma_send_ilm(get_msg_num_rsp_p, NULL, MSG_ID_WAP_MMA_GET_MSG_NUM_RSP, source);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_msg_info_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                                  [IN]        
 *  app_id                                  [IN]        
 *  result                                  [IN]        
 *  req_id                                  [IN]        
 *  msg_id                                  [IN]        
 *  from_address_type                       [IN]        
 *  from_address                            [IN]        
 *  subject                                 [IN]        
 *  msg_type                                [IN]        
 *  msg_class                               [IN]        
 *  priority                                [IN]        
 *  msg_status                              [IN]        
 *  msg_size                                [IN]        
 *  user_elements_size                      [IN]        
 *  received_date                           [IN]        
 *  expiry_date                             [IN]        
 *  date                                    [IN]        
 *  need_read_report                        [IN]        
 *  is_read                                 [IN]        
 *  is_forward_lock                         [IN]        
 *  is_drm                                  [IN]        
 *  is_follow_phone_mms_content_class       [IN]        
 *  has_attachment                          [IN]        
 *  app_data                                [IN]        
 *  java_app_id                             [IN]        
 *  java_reply_app_id                       [IN]        
 *  msg_media_type                          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_msg_info_rsp(
        module_type source,
        kal_uint8 app_id,
        /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */ kal_uint8 result,
        /* mma_result_enum */ kal_uint32 req_id,
        kal_uint32 msg_id,
        kal_uint8 from_address_type,
        kal_wchar *from_address,
        kal_wchar *subject,
        kal_uint8 msg_type,
        kal_uint8 priority, /* mma_priority_enum */ 
        kal_uint32 msg_size,
        kal_uint32 user_elements_size,
        kal_uint32 received_date,
        kal_uint32 expiry_date,
        kal_uint32 date,
        kal_bool need_read_report,
        kal_bool is_read,
        kal_bool is_forward_lock,
        /* When MMS contain any DRM forward-lock or combine-delivery object, the value is KAL_TRUE. Because sepertae-delivery DRM object can be forwarded. */ kal_bool is_drm,
        /* When MMS contain any DRM object, the value is KAL_TRUE */ kal_bool is_follow_phone_mms_content_class,
        kal_bool has_attachment,
        kal_uint8 *app_data,
        /* kal_uint8   app_data[MMA_MAX_APP_DATA_LENGTH] */ kal_uint8 *java_app_id,
        /* For JSR205  Encoded by ASCII, length is 100 */ kal_uint8 *java_reply_app_id,
        /* For JSR205  Encoded by ASCII, , length is 100 */ 
        kal_uint8 msg_media_type, /* mma_media_msg_enum */
        kal_uint8 msg_storage, /* mms storage type */
        kal_uint8 msg_sim_id,
        kal_uint8 msg_class)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_info_rsp_struct *get_msg_info_rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_msg_info_rsp_p =
        (wap_mma_get_msg_info_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_get_msg_info_rsp_struct),
                                            TD_CTRL | TD_RESET);

    get_msg_info_rsp_p->app_id = app_id;
    get_msg_info_rsp_p->req_id = req_id;
    get_msg_info_rsp_p->result = result;
    get_msg_info_rsp_p->msg_id = msg_id;
    get_msg_info_rsp_p->date = date;
    get_msg_info_rsp_p->priority = priority;
    get_msg_info_rsp_p->received_date = received_date;
    get_msg_info_rsp_p->expiry_date = expiry_date;
    get_msg_info_rsp_p->msg_type = msg_type;
    //get_msg_info_rsp_p->msg_status = 0;
    get_msg_info_rsp_p->msg_size = msg_size;
    get_msg_info_rsp_p->user_elements_size = user_elements_size;
    get_msg_info_rsp_p->isDRM = is_drm;
    get_msg_info_rsp_p->isFollowPhoneMMSContentClass = is_follow_phone_mms_content_class;
    get_msg_info_rsp_p->isForwardlock = is_forward_lock;
    get_msg_info_rsp_p->isRead = is_read;
    get_msg_info_rsp_p->hasAttachment = has_attachment;
    get_msg_info_rsp_p->need_read_report = need_read_report;
    get_msg_info_rsp_p->msg_media_type = msg_media_type;
    get_msg_info_rsp_p->storage_type = msg_storage;
    get_msg_info_rsp_p->sim_id = msg_sim_id;
    get_msg_info_rsp_p->msg_class = msg_class;
    /*if(app_data != NULL)
    {
        get_msg_info_rsp_p->sim_id = app_data[MMA_MSGMGR_MSG_SIMID_POS];
        get_msg_info_rsp_p->msg_class = app_data[MMA_MSGMGR_MSG_CLASS_POS];
    }
    else
    {
        get_msg_info_rsp_p->sim_id = MMA_SIM_ID_SIM1;
    }*/
    get_msg_info_rsp_p->from_address_type = from_address_type;
    if (from_address != NULL)
    {
        app_ucs2_strncpy(
            (kal_int8*) get_msg_info_rsp_p->from_address,
            (const kal_int8*)from_address,
            MMA_MAX_ADDR_LEN - 1);
    }
    if (subject != NULL)
    {
        app_ucs2_strncpy((kal_int8*) get_msg_info_rsp_p->subject, (const kal_int8*)subject, MMA_MAX_SUBJECT_LEN - 1);
    }
    if (app_data != NULL)
    {
        memcpy((char*)get_msg_info_rsp_p->app_data, (char*)app_data, sizeof(get_msg_info_rsp_p->app_data));
    }
    if (java_app_id != NULL)
    {
        strncpy((char*)get_msg_info_rsp_p->java_app_id, (char*)java_app_id, sizeof(get_msg_info_rsp_p->java_app_id));
    }
    if (java_reply_app_id != NULL)
    {
        strncpy(
            (char*)get_msg_info_rsp_p->java_reply_app_id,
            (char*)java_reply_app_id,
            sizeof(get_msg_info_rsp_p->java_reply_app_id));
    }
    mms_mma_send_ilm(get_msg_info_rsp_p, NULL, MSG_ID_WAP_MMA_GET_MSG_INFO_RSP, source);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_msg_list_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source          [IN]        
 *  app_id          [IN]        
 *  result          [IN]        
 *  req_id          [IN]        
 *  no_of_msg       [IN]        
 *  msg_id          [IN]         
 *  more            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_msg_list_rsp(
        module_type source,
        kal_uint8 app_id,
        /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */ kal_uint8 result,
        /* mma_result_enum */ kal_uint32 req_id,
        kal_uint32 no_of_msg,
        kal_uint32 *msg_id,
        /* msg_id[400], The array can store 399 msg_ids. The value of last item is 0. For emaple, if msg_id[10] is 0, it means there are 9 valid msg_ids from msg_id[0] ~ msg_id[9] */ kal_bool more /* If no_of_msg is more than 399, the more flag will be KAL_TRUE */ )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_list_rsp_struct *get_msg_list_rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_msg_list_rsp_p =
        (wap_mma_get_msg_list_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_get_msg_list_rsp_struct),
                                            TD_CTRL | TD_RESET);

    get_msg_list_rsp_p->app_id = app_id;
    get_msg_list_rsp_p->result = result;
    get_msg_list_rsp_p->req_id = req_id;
    get_msg_list_rsp_p->more = more;
    get_msg_list_rsp_p->no_of_msg = no_of_msg;

    if (msg_id != NULL)
    {
        int index = 0;

        while (msg_id[index] != 0 && index < (sizeof(get_msg_list_rsp_p->msg_id) / 4))
        {
            get_msg_list_rsp_p->msg_id[index] = msg_id[index];

            index++;
        }
    }
    mms_mma_send_ilm(get_msg_list_rsp_p, NULL, MSG_ID_WAP_MMA_GET_MSG_LIST_RSP, source);
}
#endif /* MMA_JSR_PST_MMS_OPERATON_SUPPORT */

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_delete_msg_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source      [IN]        
 *  app_id      [IN]        
 *  result      [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_delete_msg_rsp(
        module_type source,
        kal_uint8 app_id,
        kal_uint32 *result,
        kal_uint32 req_id,
        kal_uint32 *msg_id,
		kal_uint32 num_of_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_rsp_struct *get_msg_list_rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_msg_list_rsp_p = (wap_mma_delete_rsp_struct*) construct_local_para(sizeof(wap_mma_delete_rsp_struct), TD_CTRL | TD_RESET);

    get_msg_list_rsp_p->app_id = app_id;
    get_msg_list_rsp_p->req_id = req_id;
	get_msg_list_rsp_p->no_of_msg = num_of_msg;
    if (msg_id != NULL)
    {
        memcpy((char*)get_msg_list_rsp_p->msg_id, (char*)msg_id, sizeof(kal_uint32) * num_of_msg);
    }

    if (result != NULL)
    {
        memcpy((char*)get_msg_list_rsp_p->result, (char*)result, sizeof(kal_uint32) * num_of_msg);
    }

    mms_mma_send_ilm(get_msg_list_rsp_p, NULL, MSG_ID_WAP_MMA_DELETE_RSP, source);
}

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_save_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source      [IN]        
 *  app_id      [IN]        
 *  result      [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_save_rsp(module_type source, kal_uint8 app_id, kal_uint32 *result, kal_uint32 req_id, kal_uint32 *msg_id, kal_uint32 num_of_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_mma_save_rsp_struct *save_rsp_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	save_rsp_p = (wap_mma_save_rsp_struct*) construct_local_para(sizeof(wap_mma_save_rsp_struct), TD_CTRL | TD_RESET);

    save_rsp_p->app_id = app_id;
    save_rsp_p->req_id = req_id;
	save_rsp_p->no_of_msg = num_of_msg;
    
	if (msg_id != NULL)
    {
        memcpy((char*)save_rsp_p->msg_id, (char*)msg_id, sizeof(kal_uint32) * num_of_msg);
    }

    if (result != NULL)
    {
        memcpy((char*)save_rsp_p->result, (char*)result, sizeof(kal_uint32) * num_of_msg);
    }

    mms_mma_send_ilm(save_rsp_p, NULL, MSG_ID_WAP_MMA_SAVE_RSP, source);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_delete_folder_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source          [IN]        
 *  app_id          [IN]        
 *  msg_type        [IN]        
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_delete_folder_rsp(module_type source, kal_uint32 app_id, kal_uint32 msg_type, kal_bool result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_rsp_struct *delete_folder_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_folder_rsp =
        (srv_um_delete_folder_rsp_struct*) construct_local_para(
                                            sizeof(srv_um_delete_folder_rsp_struct),
                                            TD_CTRL | TD_RESET);

    delete_folder_rsp->app_id = app_id;
    delete_folder_rsp->msg_type = (srv_um_msg_enum)msg_type;
    delete_folder_rsp->result = result;

    mms_mma_send_ilm(delete_folder_rsp, NULL, MSG_ID_MMI_UM_DELETE_FOLDER_RSP, source);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_set_profile_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dst_id      [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_set_profile_rsp(module_type dst_id, kal_uint8 app_id, kal_uint32 req_id, mma_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_profile_rsp_struct *set_mms_profile_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_mms_profile_rsp =
        (wap_mma_set_profile_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_set_profile_rsp_struct),
                                            TD_CTRL | TD_RESET);

    set_mms_profile_rsp->app_id = app_id;
    set_mms_profile_rsp->req_id = req_id;
    set_mms_profile_rsp->result = result;
    mms_mma_send_ilm(set_mms_profile_rsp, NULL, MSG_ID_WAP_MMA_SET_PROFILE_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_send_ind
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dest_id     [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 *  retry       [IN]        
 *  percent     [IN]        
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_send_ind(
        module_type dest_id,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint32 msg_id,
        kal_uint8 retry,
        kal_uint8 percent,
        kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_ind_struct *send_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_ind = (wap_mma_send_ind_struct*) construct_local_para(sizeof(wap_mma_send_ind_struct), TD_CTRL | TD_RESET);
    send_ind->app_id = app_id;
    send_ind->req_id = req_id;
    send_ind->msg_id = msg_id;
    send_ind->retry = retry;
    send_ind->percent = percent;
    send_ind->sim_id = sim_id;

    mms_mma_send_ilm(send_ind, NULL, MSG_ID_WAP_MMA_SEND_IND, dest_id);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest                [IN]        
 *  app_id              [IN]        
 *  req_id              [IN]        
 *  msg_id              [IN]        
 *  rr_id               [IN]        
 *  result              [IN]        
 *  response_text       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_send_rsp(
        module_type dest,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint32 msg_id,
        kal_uint8 result,
        char *response_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_rsp_struct *send_rsp_p = NULL;
    kal_wchar *response_text_ucs2_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_rsp_p = (wap_mma_send_rsp_struct*) construct_local_para(sizeof(wap_mma_send_rsp_struct), TD_CTRL | TD_RESET);

    send_rsp_p->app_id = app_id;
    send_rsp_p->req_id = req_id;
    send_rsp_p->msg_id = msg_id;
    send_rsp_p->result = result;
    if (response_text != NULL)
    {
        long srcLen = 0;
        long len = strlen(response_text) + 1;

        srcLen = strlen(response_text);
        if (len < MMA_MAX_RESPONSE_TEXT_LENGTH)
        {
            len = MMA_MAX_RESPONSE_TEXT_LENGTH;
        }
        len = len * 2;
        response_text_ucs2_p = (kal_wchar*) MMA_CALLOC(len);
        ASSERT(response_text_ucs2_p);
        msf_charset_utf8_to_ucs2le((const char*)response_text, &srcLen, (char*)response_text_ucs2_p, &len);
        memcpy(send_rsp_p->response_text, response_text_ucs2_p, MMA_MAX_RESPONSE_TEXT_LENGTH);
        MMA_FREE(response_text_ucs2_p);
    }
    mms_mma_send_ilm(send_rsp_p, NULL, MSG_ID_WAP_MMA_SEND_RSP, dest);

}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_download_ind
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dest_id             [IN]        
 *  app_id              [IN]        
 *  req_id              [IN]        
 *  msg_id              [IN]        
 *  retry               [IN]        
 *  percent             [IN]        
 *  bytes_received      [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_download_ind(
        module_type dest_id,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint32 msg_id,
        kal_uint8 retry,
        kal_uint8 percent,
        kal_uint32 bytes_received,
        kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_ind_struct *download_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    download_ind =
        (wap_mma_download_ind_struct*) construct_local_para(sizeof(wap_mma_download_ind_struct), TD_CTRL | TD_RESET);
    download_ind->app_id = app_id;
    download_ind->req_id = req_id;
    download_ind->msg_id = msg_id;
    download_ind->retry = retry;
    download_ind->percent = percent;
    download_ind->bytes_received = bytes_received;
    download_ind->sim_id = sim_id;

    mms_mma_send_ilm(download_ind, NULL, MSG_ID_WAP_MMA_DOWNLOAD_IND, dest_id);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_download_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest                [IN]        
 *  app_id              [IN]        
 *  req_id              [IN]        
 *  msg_id              [IN]        
 *  result              [IN]        
 *  response_text       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_download_rsp(
        module_type dest,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint32 msg_id,
        kal_uint32 new_msg_id,
        kal_uint8 result,
        char *response_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_rsp_struct *download_rsp_p = NULL;
    kal_wchar *response_text_ucs2_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    download_rsp_p =
        (wap_mma_download_rsp_struct*) construct_local_para(sizeof(wap_mma_download_rsp_struct), TD_CTRL | TD_RESET);

    download_rsp_p->app_id = app_id;
    download_rsp_p->req_id = req_id;
    download_rsp_p->msg_id = msg_id;
    download_rsp_p->new_msg_id = new_msg_id;
    download_rsp_p->result = result;
    if (response_text != NULL)
    {
        long srcLen = 0;
        long len = strlen(response_text) + 1;

        srcLen = strlen(response_text);
        if (len < MMA_MAX_RESPONSE_TEXT_LENGTH)
        {
            len = MMA_MAX_RESPONSE_TEXT_LENGTH;
        }
        len = len * 2;
        response_text_ucs2_p = (kal_wchar*) MMA_CALLOC(len);
        ASSERT(response_text_ucs2_p);
        msf_charset_utf8_to_ucs2le((const char*)response_text, &srcLen, (char*)response_text_ucs2_p, &len);
        memcpy(download_rsp_p->response_text, response_text_ucs2_p, MMA_MAX_RESPONSE_TEXT_LENGTH);
        MMA_FREE(response_text_ucs2_p);
    }
    mms_mma_send_ilm(download_rsp_p, NULL, MSG_ID_WAP_MMA_DOWNLOAD_RSP, dest);

}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_start_immed_retrieval_ind
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dest_id     [IN]        
 *  msg_id      [IN]        
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_start_immed_retrieval_ind(module_type dest_id, kal_uint32 msg_id, kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_start_immed_retrieval_ind_struct *start_immed_retrieval_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_immed_retrieval_ind =
        (wap_mma_start_immed_retrieval_ind_struct*)
        construct_local_para(sizeof(wap_mma_start_immed_retrieval_ind_struct), TD_CTRL | TD_RESET);
    start_immed_retrieval_ind->msg_id = msg_id;
    start_immed_retrieval_ind->sim_id = sim_id;
    mms_mma_send_ilm(start_immed_retrieval_ind, NULL, MSG_ID_WAP_MMA_START_IMMED_RETRIEVAL_IND, dest_id);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_stop_immed_retrieval_ind
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dest_id             [IN]        
 *  msg_id              [IN]        
 *  result              [IN]        
 *  sim_id              [IN]        
 *  error_cause         [IN]        
 *  response_text       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_stop_immed_retrieval_ind(
        module_type dest_id,
        kal_uint32 msg_id,
        kal_uint8 result,
        kal_uint8 sim_id,
        /* mma_result_enum */ kal_uint32 error_cause,
        kal_wchar *response_text /* Encoded by UCS2, max length is MMA_MAX_RESPONSE_TEXT_LENGTH */ )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_stop_immed_retrieval_ind_struct *stop_immed_retrieval_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stop_immed_retrieval_ind =
        (wap_mma_stop_immed_retrieval_ind_struct*)
        construct_local_para(sizeof(wap_mma_stop_immed_retrieval_ind_struct), TD_CTRL | TD_RESET);
    stop_immed_retrieval_ind->msg_id = msg_id;
    stop_immed_retrieval_ind->result = result;
    stop_immed_retrieval_ind->sim_id = sim_id;
    stop_immed_retrieval_ind->error_cause = error_cause;
    if (response_text != NULL)
    {
        app_ucs2_strncpy(
            (kal_int8*) stop_immed_retrieval_ind->response_text,
            (const kal_int8*)response_text,
            MMA_MAX_RESPONSE_TEXT_LENGTH - 1);
    }
    mms_mma_send_ilm(stop_immed_retrieval_ind, NULL, MSG_ID_WAP_MMA_STOP_IMMED_RETRIEVAL_IND, dest_id);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_um_ready_ind
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dest_id     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_um_ready_ind(module_type dest_id, kal_bool result)
{
#if defined(__MMI_MMS_IN_UM__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_ready_ind_struct *ready_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ready_ind = (srv_um_ready_ind_struct*) construct_local_para(sizeof(srv_um_ready_ind_struct), TD_CTRL | TD_RESET);

    ready_ind->result = result;
    ready_ind->msg_type = SRV_UM_MSG_MMS;
    mms_mma_send_ilm(ready_ind, NULL, MSG_ID_MMI_UM_READY_IND, dest_id);
#endif /* defined(__MMI_MMS_IN_UM__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_um_refresh_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_id         [IN]        
 *  folder_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_um_refresh_ind(module_type dest_id, mma_folder_enum folder_id)
{
#if defined(__MMI_MMS_IN_UM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *um_refresh_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    um_refresh_ind =
        (srv_um_refresh_ind_struct*) construct_local_para(
                                        (kal_uint16) sizeof(srv_um_refresh_ind_struct),
                                        TD_CTRL | TD_RESET);
    um_refresh_ind->msg_type = SRV_UM_MSG_MMS;
    um_refresh_ind->msg_box_type = (srv_um_msg_box_enum)mma_cvt_mma_folder_to_um_folder(folder_id);
    um_refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;

    mms_mma_send_ilm(um_refresh_ind, NULL, MSG_ID_MMI_UM_REFRESH_IND, dest_id);
#endif /* defined(__MMI_MMS_IN_UM__) */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_um_highlight_decide_by_um_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest_id         [IN]        
 *  folder_id       [IN]        
 *  msg_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_um_highlight_decide_by_um_ind(module_type dest_id, mma_folder_enum folder_id, kal_uint32 msg_index)
{
#if defined(__MMI_MMS_IN_UM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_highlight_decided_by_UM_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req =
        (srv_um_highlight_decided_by_UM_struct*) construct_local_para(
                                                    sizeof(srv_um_highlight_decided_by_UM_struct),
                                                    TD_CTRL | TD_RESET);
    req->msg_type = SRV_UM_MSG_MMS;
    req->msg_box_type = (srv_um_msg_box_enum)folder_id;
    req->msg_id = msg_index;
    mms_mma_send_ilm(req, NULL, MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND, dest_id);
#endif /* defined(__MMI_MMS_IN_UM__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_cancel_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_cancel_send_rsp(
        module_type dest,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint32 msg_id,
        kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *cancel_send_rsp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cancel_send_rsp_p = (wap_mma_rsp_struct*) construct_local_para(sizeof(wap_mma_rsp_struct), TD_CTRL | TD_RESET);

    cancel_send_rsp_p->app_id = app_id;
    cancel_send_rsp_p->req_id = req_id;
    cancel_send_rsp_p->msg_id = msg_id;
    cancel_send_rsp_p->result = result;

    mms_mma_send_ilm(cancel_send_rsp_p, NULL, MSG_ID_WAP_MMA_CANCEL_SEND_RSP, dest);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_content_rsp
 * DESCRIPTION
 *  this function will be called to return get content response value.
 * PARAMETERS
 *  dst_id          [IN]        
 *  para            [IN]         
 *  xml_content     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_content_rsp(module_type dst_id, wap_mma_get_content_rsp_struct *para, kal_uint8 *xml_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_rsp_struct *rsp = NULL;
    //peer_buff_struct *peer_buff_ptr = NULL;
    //kal_uint8 *peer_pdu = NULL;
   // kal_uint16 peer_pdu_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wap_mma_get_content_rsp_struct*)
        construct_local_para((kal_uint16) sizeof(wap_mma_get_content_rsp_struct), TD_CTRL | TD_RESET);
    rsp->app_id = para->app_id;
    rsp->req_id = para->req_id;
    rsp->result = para->result;
    rsp->msg_id = para->msg_id;
    rsp->mms_header_size = para->mms_header_size;
    rsp->mms_body_size = para->mms_body_size;
    //rsp->xml_size = para->xml_size;
    rsp->content_truncate_info = para->content_truncate_info;
    rsp->content_info = para->content_info;
    /*if (para->xml_filepath != NULL)
    {
        app_ucs2_strncpy(
            (kal_int8*) & rsp->xml_filepath,
            (const kal_int8*)para->xml_filepath,
            MMA_MAX_INTERNAL_FILENAME_LENGTH - 1);
    }
    rsp->buffer_index = para->buffer_index;
    rsp->buffer_size = para->buffer_size;
    rsp->more = para->more;

    if (para->buffer_size > 0 && xml_content != NULL)
    {
        peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(para->buffer_size, 0, 0, TD_CTRL);
        peer_pdu = (MSF_UINT8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
        if (peer_pdu)
        {
            memcpy((kal_uint8*) peer_pdu, (kal_uint8*) xml_content, para->buffer_size);
        }
    }*/

    mms_mma_send_ilm(rsp, NULL, MSG_ID_WAP_MMA_GET_CONTENT_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_create_rsp
 * DESCRIPTION
 *  this function will be called to return create response value.
 * PARAMETERS
 *  dst_id      [IN]        
 *  para        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_create_rsp(module_type dst_id, wap_mma_create_rsp_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp =
        (wap_mma_create_rsp_struct*) construct_local_para(
                                        (kal_uint16) sizeof(wap_mma_create_rsp_struct),
                                        TD_CTRL | TD_RESET);
    rsp->app_id = para->app_id;
    rsp->req_id = para->req_id;
    rsp->result = para->result;
    rsp->msg_id = para->msg_id;
    rsp->buffer_index = para->buffer_index;
    rsp->min_fs_space_required = para->min_fs_space_required;
    rsp->storage = mma_get_message_storage(para->msg_id);

    mms_mma_send_ilm(rsp, NULL, MSG_ID_WAP_MMA_CREATE_RSP, dst_id);
}
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_msg_attr_and_thumbnail_info_rsp
 * DESCRIPTION
 *  This function is used to send the msg read, valid status to the application
 * PARAMETERS
 *  source      	[IN]        
 *  app_id      	[IN]        
 *  result      	[IN]        
 *  req_id      	[IN]        
 * msg_attr_and_tbn_rsp		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_msg_attr_and_thumbnail_info_rsp(
        module_type source,
        kal_uint8 app_id,
        kal_uint8 result,
        kal_uint32 req_id,
        kal_uint32 msg_id,
        wap_mma_get_mms_thumbnail_and_attr_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_mms_thumbnail_and_attr_info_rsp_struct *msg_attr_and_tbn_rsp;



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_attr_and_tbn_rsp = (wap_mma_get_mms_thumbnail_and_attr_info_rsp_struct*) construct_local_para(sizeof(wap_mma_get_mms_thumbnail_and_attr_info_rsp_struct), TD_CTRL | TD_RESET);

    msg_attr_and_tbn_rsp->app_id = app_id;
    msg_attr_and_tbn_rsp->req_id = req_id;
    msg_attr_and_tbn_rsp->result = result;
    msg_attr_and_tbn_rsp->msg_id = msg_id;

    if (msg_info != NULL)
    {
			msg_attr_and_tbn_rsp->attr_tbm_info.timestamp = msg_info->timestamp;
			msg_attr_and_tbn_rsp->attr_tbm_info.msg_type = msg_info->msg_type;
			msg_attr_and_tbn_rsp->attr_tbm_info.storage_type = msg_info->storage_type;
			msg_attr_and_tbn_rsp->attr_tbm_info.msg_size = msg_info->msg_size;
			msg_attr_and_tbn_rsp->attr_tbm_info.msg_sim_id = msg_info->msg_sim_id;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.msg_download_size = msg_info->body_header_data.msg_download_size;

			if(app_ucs2_strlen((const kal_int8*)msg_info->body_header_data.subject)  > 0)
				{
					app_ucs2_strncpy(
					(kal_int8*) msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.subject,
					(const kal_int8*)msg_info->body_header_data.subject,
					MMA_MAX_SUBJECT_LEN - 1);
				}
				/* Copying image thumbnail info*/
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info.body_type = msg_info->body_header_data.thumbnail_info.body_type;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info.body_size = msg_info->body_header_data.thumbnail_info.body_size;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info.body_offset = msg_info->body_header_data.thumbnail_info.body_offset;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info.body_name_len = msg_info->body_header_data.thumbnail_info.body_name_len;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info.is_drm = msg_info->body_header_data.thumbnail_info.is_drm;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info.txt_encoding_scheme = msg_info->body_header_data.thumbnail_info.txt_encoding_scheme;
			if(msg_info->body_header_data.thumbnail_info.body_name_len > 0)
				{
					app_ucs2_strncpy(
					(kal_int8*) msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info.body_name,
					(const kal_int8*)msg_info->body_header_data.thumbnail_info.body_name,
					MMS_MAX_OBJECT_FILE_NAME_LEN - 1);
				}
			/* Copying text thumbnail info*/
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_type = msg_info->body_header_data.thumbnail_info_txt.body_type;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_size = msg_info->body_header_data.thumbnail_info_txt.body_size;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_offset = msg_info->body_header_data.thumbnail_info_txt.body_offset;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_name_len = msg_info->body_header_data.thumbnail_info_txt.body_name_len;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.is_drm = msg_info->body_header_data.thumbnail_info_txt.is_drm;
			msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.txt_encoding_scheme = msg_info->body_header_data.thumbnail_info_txt.txt_encoding_scheme;
			if(msg_info->body_header_data.thumbnail_info_txt.body_name_len > 0)
				{
					app_ucs2_strncpy(
					(kal_int8*) msg_attr_and_tbn_rsp->attr_tbm_info.body_header_data.thumbnail_info_txt.body_name,
					(const kal_int8*)msg_info->body_header_data.thumbnail_info_txt.body_name,
					MMS_MAX_OBJECT_FILE_NAME_LEN - 1);
				}

    }

    mms_mma_send_ilm(msg_attr_and_tbn_rsp, NULL, MSG_ID_WAP_MMA_GET_MSG_ATTR_AND_THUMBNAIL_RSP, source);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_cancel_download_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_cancel_download_rsp(
        module_type dest,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint32 msg_id,
        kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rsp_struct *cancel_download_rsp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cancel_download_rsp_p = (wap_mma_rsp_struct*) construct_local_para(sizeof(wap_mma_rsp_struct), TD_CTRL | TD_RESET);

    cancel_download_rsp_p->app_id = app_id;
    cancel_download_rsp_p->req_id = req_id;
    cancel_download_rsp_p->msg_id = msg_id;
    cancel_download_rsp_p->result = result;

    mms_mma_send_ilm(cancel_download_rsp_p, NULL, MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP, dest);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_enter_usb_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_enter_usb_rsp(module_type dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_mma_send_ilm(NULL, NULL, MSG_ID_MMS_ENTER_USB_MODE_RSP, dest);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_exit_usb_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_exit_usb_rsp(module_type dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_mma_send_ilm(NULL, NULL, MSG_ID_MMS_EXIT_USB_MODE_RSP, dest);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_storage_full_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_no_fs_space          [IN]        
 *  is_max_num_reached      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_storage_full_ind(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_storage_full_ind_struct *storage_full_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage_full_ind =
        (wap_mma_storage_full_ind_struct*) construct_local_para(
                                            sizeof(wap_mma_storage_full_ind_struct),
                                            TD_CTRL | TD_RESET);

    storage_full_ind->result = result;
    storage_full_ind->min_fs_space_required = 0;
    mms_mma_send_ilm(storage_full_ind, NULL, MSG_ID_WAP_MMA_STORAGE_FULL_IND, MOD_MMI);
}


#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_msg_is_valid_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest                        [IN]        
 *  app_id                      [IN]        
 *  req_id                      [IN]        
 *  result                      [IN]        
 *  msg_validity_list           [IN]         
 *  box_list                    [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_msg_is_valid_rsp(
        module_type dest,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint8 result,
        kal_uint8 *msg_validity_list,
        kal_uint16 *box_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_msg_is_valid_rsp_struct *msg_is_valid_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_is_valid_rsp =
        (wap_mma_msg_is_valid_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_msg_is_valid_rsp_struct),
                                            TD_CTRL | TD_RESET);

    msg_is_valid_rsp->app_id = app_id;
    msg_is_valid_rsp->req_id = req_id;
    msg_is_valid_rsp->result = result;
    if (msg_validity_list)
    {
        memcpy(msg_is_valid_rsp->msg_validity_list, msg_validity_list, MMA_MAX_MSG_ARRAY_NUM);
    }
    if (box_list)
    {
        memcpy((char*)(msg_is_valid_rsp->box), (char*)box_list, MMA_MAX_MSG_ARRAY_NUM * 2);
    }
    mms_mma_send_ilm(msg_is_valid_rsp, NULL, MSG_ID_WAP_MMA_MSG_IS_VALID_RSP, dest);
}

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_notify_event_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [IN]        
 *  app_id          [IN]        
 *  event_id        [IN]        
 *  event_info      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_notify_event_ind(module_type dest, kal_uint8 app_id, kal_uint16 event_id, void *event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_notify_event_ind_struct *notify_event_ind = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    MSF_UINT8 *peer_pdu = NULL;
    MSF_UINT16 peer_pdu_len = 0;
    MSF_UINT16 event_struct_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_INTERFACE_SEND_NOTIFY_EVENT_IND, "MMA: notify event ind (event %d, app_id %d)", event_id, app_id));

    if (event_id == MMA_EVENT_NEW_MSG)
    {
        event_struct_size = sizeof(wap_mma_event_new_msg_struct);
    }
    else if (event_id == MMA_EVENT_DELETE_MSG)
    {
        event_struct_size = sizeof(wap_mma_event_delete_msg_struct);
    }
    else if (event_id == MMA_EVENT_SAVE_MSG)
    {
        event_struct_size = sizeof(wap_mma_event_save_msg_struct);
    }
    else if (event_id == MMA_EVENT_DELETE_FOLDER)
    {
        event_struct_size = sizeof(wap_mma_event_delete_folder_struct);
    }
    else if (event_id == MMA_EVENT_UM_DELETE_FOLDER_DONE)
    {
        event_struct_size = 0;
    }

    notify_event_ind =
        (wap_mma_notify_event_ind_struct*) construct_local_para(
                                            sizeof(wap_mma_notify_event_ind_struct),
                                            TD_CTRL | TD_RESET);
    notify_event_ind->app_id = app_id;
    notify_event_ind->event_id = event_id;

    if (event_struct_size > 0)
    {
        peer_buff_ptr = (peer_buff_struct*) construct_peer_buff(event_struct_size, 0, 0, TD_CTRL);
        peer_pdu = (MSF_UINT8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
        if (peer_pdu)
        {
            memset(peer_pdu, 0x00, event_struct_size);
            memcpy((void*)peer_pdu, (void*)event_info, event_struct_size);
        }
    }
    mms_mma_send_ilm(notify_event_ind, peer_buff_ptr, MSG_ID_WAP_MMA_NOTIFY_EVENT_IND, dest);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_mms_obj_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_mms_obj_rsp(module_type dest, kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_mms_obj_res_struct *mms_obj_rsp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_obj_rsp_p =
        (wap_mma_mms_obj_res_struct*) construct_local_para(sizeof(wap_mma_mms_obj_res_struct), TD_CTRL | TD_RESET);

    mms_obj_rsp_p->app_id = app_id;
    mms_obj_rsp_p->req_id = req_id;
    mms_obj_rsp_p->result = result;
    mms_mma_send_ilm(mms_obj_rsp_p, NULL, MSG_ID_WAP_MMA_MMS_OBJ_RES, dest);

}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_unread_msg_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest                        [IN]        
 *  app_id                      [IN]        
 *  req_id                      [IN]        
 *  result                      [IN]        
 *  more                        [IN]        
 *  total_num_of_unread_msg     [IN]        
 *  num_of_unread_msg           [IN]        
 *  unread_msg_list             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_unread_msg_list_rsp(
        module_type dest,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint8 result,
        kal_uint8 more,
        kal_uint32 total_num_of_unread_msg,
        kal_uint32 num_of_unread_msg,
        void *unread_msg_list /* mma_unread_msg_list_struct unread_msg_list[MMA_MAX_UNREAD_MSG_NUM] */ )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_unread_msg_list_rsp_struct *get_unread_msg_list_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_unread_msg_list_rsp =
        (wap_mma_get_unread_msg_list_rsp_struct*) construct_local_para(
                                                    sizeof(wap_mma_get_unread_msg_list_rsp_struct),
                                                    TD_CTRL | TD_RESET);

    get_unread_msg_list_rsp->app_id = app_id;
    get_unread_msg_list_rsp->req_id = req_id;
    get_unread_msg_list_rsp->result = result;
    get_unread_msg_list_rsp->more = more;
    get_unread_msg_list_rsp->total_num_of_unread_msg = total_num_of_unread_msg;
    get_unread_msg_list_rsp->num_of_unread_msg = num_of_unread_msg;
#if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    if (unread_msg_list != NULL)
    {
        memcpy(
            (char*)(get_unread_msg_list_rsp->unread_msg_list),
            (char*)unread_msg_list,
            sizeof(mma_unread_msg_list_struct) * MMA_MAX_UNREAD_MSG_NUM);
    }
#endif
    mms_mma_send_ilm(get_unread_msg_list_rsp, NULL, MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_RSP, dest);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_recent_evt_list_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest                    [IN]        
 *  app_id                  [IN]        
 *  req_id                  [IN]        
 *  result                  [IN]        
 *  more                    [IN]        
 *  total_num_of_evt        [IN]        
 *  num_of_evt              [IN]        
 *  event_list              [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_recent_evt_list_rsp(
        module_type dest,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint8 result,
        kal_uint8 more,
        kal_uint32 total_num_of_evt,
        kal_uint32 num_of_evt,
        void *event_list /* mma_recent_evt_list_struct event_list[MMA_MAX_EVT_NUM] */ )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_recent_evt_list_rsp_struct *get_recent_evt_list_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_recent_evt_list_rsp =
        (wap_mma_get_recent_evt_list_rsp_struct*) construct_local_para(
                                                    sizeof(wap_mma_get_recent_evt_list_rsp_struct),
                                                    TD_CTRL | TD_RESET);

    get_recent_evt_list_rsp->app_id = app_id;
    get_recent_evt_list_rsp->req_id = req_id;
    get_recent_evt_list_rsp->result = result;
    get_recent_evt_list_rsp->more = more;
    get_recent_evt_list_rsp->total_num_of_evt = total_num_of_evt;
    get_recent_evt_list_rsp->num_of_evt = num_of_evt;
    if (event_list != NULL)
    {
        memcpy(
            (char*)(get_recent_evt_list_rsp->event_list),
            (char*)event_list,
            sizeof(mma_recent_evt_list_struct) * MMA_MAX_EVT_NUM);
    }

    mms_mma_send_ilm(get_recent_evt_list_rsp, NULL, MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_RSP, dest);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_delete_recent_evt_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_delete_recent_evt_rsp(
        module_type dest,
        kal_uint8 app_id,
        kal_uint32 req_id,
        kal_uint8 result,
        kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_recent_evt_rsp_struct *delete_recent_evt_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_recent_evt_rsp =
        (wap_mma_delete_recent_evt_rsp_struct*) construct_local_para(
                                                    sizeof(wap_mma_delete_recent_evt_rsp_struct),
                                                    TD_CTRL | TD_RESET);

    delete_recent_evt_rsp->app_id = app_id;
    delete_recent_evt_rsp->req_id = req_id;
    delete_recent_evt_rsp->result = result;
    delete_recent_evt_rsp->msg_id = msg_id;

    mms_mma_send_ilm(delete_recent_evt_rsp, NULL, MSG_ID_WAP_MMA_DELETE_RECENT_EVT_RSP, dest);
}
#endif /*#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */


void mms_mma_send_insufficient_memory_ind()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mms_mma_send_ilm(NULL, NULL, MSG_ID_WAP_MMA_INSUFFICIENT_MEMORY_IND, MOD_MMI);
}
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_get_msg_property_rsp
 * DESCRIPTION
 *  This function is used to send the msg read, valid status to the application
 * PARAMETERS
 *  source      	[IN]        
 *  app_id      	[IN]        
 *  result      	[IN]        
 *  req_id      	[IN]        
 *  no_of_msg   	[IN]        
 * msg_property		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_get_msg_property_rsp(
        module_type source,
        kal_uint8 app_id,
        kal_uint8 result,
        kal_uint32 req_id,
        kal_uint32 num_of_msg,
        mma_msg_property_struct *msg_property)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_property_rsp_struct *get_msg_property_rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_msg_property_rsp_p = (wap_mma_get_msg_property_rsp_struct*) construct_local_para(sizeof(wap_mma_get_msg_property_rsp_struct), TD_CTRL | TD_RESET);

    get_msg_property_rsp_p->app_id = app_id;
    get_msg_property_rsp_p->req_id = req_id;
    get_msg_property_rsp_p->result = result;
    get_msg_property_rsp_p->num_of_msg = num_of_msg;

    if (msg_property != NULL)
    {
        memcpy(get_msg_property_rsp_p->msg_property, msg_property, sizeof(mma_msg_property_struct) * MMA_MAX_MSG_ARRAY_NUM);
    }

    mms_mma_send_ilm(get_msg_property_rsp_p, NULL, MSG_ID_WAP_MMA_GET_MSG_PROPERTY_RSP, source);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_mark_rr_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dst_id      [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_mark_rr_rsp(module_type dst_id, kal_uint32 app_id, kal_uint32 req_id, mma_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rr_mark_rsp_struct *mark_rr_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mark_rr_rsp =
        (wap_mma_rr_mark_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_rr_mark_rsp_struct),
                                            TD_CTRL | TD_RESET);

    mark_rr_rsp->app_id = app_id;
    mark_rr_rsp->req_id = req_id;
    mark_rr_rsp->result = result;
    mms_mma_send_ilm(mark_rr_rsp, NULL, MSG_ID_WAP_MMA_RR_MARK_RSP, dst_id);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_chg_mms_storage_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dst_id      [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_chg_mms_storage_rsp(module_type dst_id, kal_uint32 app_id, kal_uint32 req_id, kal_uint32 msg_id, kal_uint32 action_type, mma_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_change_msg_storage_rsp_struct *chg_msg_storage_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chg_msg_storage_rsp =
        (wap_mma_change_msg_storage_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_change_msg_storage_rsp_struct),
                                            TD_CTRL | TD_RESET);

    chg_msg_storage_rsp->app_id = app_id;
    chg_msg_storage_rsp->req_id = req_id;
    chg_msg_storage_rsp->msg_id = msg_id;
    chg_msg_storage_rsp->action_type = action_type;
    chg_msg_storage_rsp->result = result;
    mms_mma_send_ilm(chg_msg_storage_rsp, NULL, MSG_ID_WAP_MMA_CHG_MSG_STORAGE_RSP, dst_id);
}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  MMAif_enterUSBMode
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_enterUSBMode()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Sub-module enter USB order: PARSE->CREATE->SENDRECV->MSGMGR */
    MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MAIN, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
    MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_DRMSRV, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
#else
    MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_exitUSBMode
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_exitUSBMode()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MAIN, MMA_INT_SIG_TYPE_MSG_EXIT_USB_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_getUmMsgList
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source              [IN]        
 *  get_list_req        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getUmMsgList(module_type source, srv_um_get_msg_list_req_struct *get_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_list_req_struct *get_um_list_input_p = NULL;

    ASSERT(get_list_req);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_um_list_input_p = (srv_um_get_msg_list_req_struct*) MMA_CALLOC(sizeof(srv_um_get_msg_list_req_struct));
    memcpy((char*)get_um_list_input_p, (char*)get_list_req, sizeof(srv_um_get_msg_list_req_struct));
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_UM_GET_LIST_REQ, source, get_um_list_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_getUmMsgNum
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  get_um_msg_num_req      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getUmMsgNum(module_type source, srv_um_get_msg_num_req_struct *get_um_msg_num_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_num_req_struct *get_um_msg_num_input_p = NULL;

    ASSERT(get_um_msg_num_req);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_um_msg_num_input_p = (srv_um_get_msg_num_req_struct*) MMA_CALLOC(sizeof(srv_um_get_msg_num_req_struct));
    memcpy((char*)get_um_msg_num_input_p, (char*)get_um_msg_num_req, sizeof(srv_um_get_msg_num_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_UM_GET_MSG_NUM_REQ,
        source,
        get_um_msg_num_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_getUmMsgInfo
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  get_um_msg_info_req     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getUmMsgInfo(module_type source, srv_um_get_msg_info_req_struct *get_um_msg_info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_req_struct *get_um_msg_info_input_p = NULL;

    ASSERT(get_um_msg_info_req);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_um_msg_info_input_p = (srv_um_get_msg_info_req_struct*) MMA_CALLOC(sizeof(srv_um_get_msg_info_req_struct));
    memcpy((char*)get_um_msg_info_input_p, (char*)get_um_msg_info_req, sizeof(srv_um_get_msg_info_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_UM_GET_MSG_INFO_REQ,
        source,
        get_um_msg_info_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_sendMessage
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  mms_mma_send_req_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_sendMessage(module_type source, wap_mma_send_req_struct *mms_mma_send_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_req_struct *mms_mma_send_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mms_mma_send_req_p);

    mms_mma_send_req_input_p = (wap_mma_send_req_struct*) MMA_CALLOC(sizeof(wap_mma_send_req_struct));
    ASSERT(mms_mma_send_req_input_p);
    memcpy((char*)mms_mma_send_req_input_p, (char*)mms_mma_send_req_p, sizeof(wap_mma_send_req_struct));
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_SEND_MSG, source, mms_mma_send_req_input_p);

}


/*****************************************************************************
 * FUNCTION
 *  MMAif_cancelSendMessage
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                          [IN]        
 *  mms_mma_cancel_send_req_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_cancelSendMessage(module_type source, wap_mma_cancel_send_req_struct *mms_mma_cancel_send_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cancel_send_req_struct *mms_mma_cancel_send_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mms_mma_cancel_send_req_p);

    mms_mma_cancel_send_req_input_p =
        (wap_mma_cancel_send_req_struct*) MMA_CALLOC(sizeof(wap_mma_cancel_send_req_struct));
    ASSERT(mms_mma_cancel_send_req_input_p);
    memcpy(
        (char*)mms_mma_cancel_send_req_input_p,
        (char*)mms_mma_cancel_send_req_p,
        sizeof(wap_mma_cancel_send_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_SENDRECV,
        MMA_INT_SIG_TYPE_MSG_CANCEL_SEND_MSG,
        source,
        mms_mma_cancel_send_req_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_downloadMessage
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                      [IN]        
 *  mms_mma_download_req_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_downloadMessage(module_type source, wap_mma_download_req_struct *mms_mma_download_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_req_struct *mms_mma_download_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mms_mma_download_req_p);

    mms_mma_download_req_input_p = (wap_mma_download_req_struct*) MMA_CALLOC(sizeof(wap_mma_download_req_struct));
    ASSERT(mms_mma_download_req_input_p);
    memcpy((char*)mms_mma_download_req_input_p, (char*)mms_mma_download_req_p, sizeof(wap_mma_download_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_SENDRECV,
        MMA_INT_SIG_TYPE_MSG_RECV_MSG,
        source,
        mms_mma_download_req_input_p);

}


/*****************************************************************************
 * FUNCTION
 *  MMAif_cancelDownloadMessage
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                              [IN]        
 *  mms_mma_cancel_download_req_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_cancelDownloadMessage(module_type source, wap_mma_cancel_download_req_struct *mms_mma_cancel_download_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cancel_download_req_struct *mms_mma_cancel_download_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mms_mma_cancel_download_req_p);

    mms_mma_cancel_download_req_input_p =
        (wap_mma_cancel_download_req_struct*) MMA_CALLOC(sizeof(wap_mma_cancel_download_req_struct));
    ASSERT(mms_mma_cancel_download_req_input_p);
    memcpy(
        (char*)mms_mma_cancel_download_req_input_p,
        (char*)mms_mma_cancel_download_req_p,
        sizeof(wap_mma_cancel_download_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_SENDRECV,
        MMA_INT_SIG_TYPE_MSG_CANCEL_RECV_MSG,
        source,
        mms_mma_cancel_download_req_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_downloadRes
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                          [IN]        
 *  mms_mma_download_ind_res_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_downloadRes(module_type source, wap_mma_download_res_struct *mms_mma_download_ind_res_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_download_res_struct *mms_mma_download_ind_res_input_p = NULL;

    ASSERT(mms_mma_download_ind_res_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_mma_download_ind_res_input_p = (wap_mma_download_res_struct*) MMA_CALLOC(sizeof(wap_mma_download_res_struct));
    ASSERT(mms_mma_download_ind_res_input_p);
    memcpy(
        (char*)mms_mma_download_ind_res_input_p,
        (char*)mms_mma_download_ind_res_p,
        sizeof(wap_mma_download_res_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_SENDRECV,
        MMA_INT_SIG_TYPE_MSG_RECV_IND_RES,
        source,
        mms_mma_download_ind_res_input_p);

}


/*****************************************************************************
 * FUNCTION
 *  MMAif_setSetting
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                          [IN]        
 *  mms_mma_set_mms_setting_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_setSetting(module_type source, wap_mma_set_setting_req_struct *mms_mma_set_mms_setting_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_setting_req_struct *mms_mma_set_mms_setting_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mms_mma_set_mms_setting_p);

    mms_mma_set_mms_setting_input_p =
        (wap_mma_set_setting_req_struct*) MMA_CALLOC(sizeof(wap_mma_set_setting_req_struct));
    memcpy(
        (char*)mms_mma_set_mms_setting_input_p,
        (char*)mms_mma_set_mms_setting_p,
        sizeof(wap_mma_set_setting_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_SETTING,
        MMA_INT_SIG_TYPE_MSG_SET_SETTING_REQ,
        source,
        mms_mma_set_mms_setting_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_getSetting
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source              [IN]        
 *  get_setting_req     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getSetting(module_type source, wap_mma_get_setting_req_struct *get_setting_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_setting_req_struct *mms_mma_get_mms_setting_input_p = NULL;

    ASSERT(get_setting_req);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_mma_get_mms_setting_input_p =
        (wap_mma_get_setting_req_struct*) MMA_CALLOC(sizeof(wap_mma_get_setting_req_struct));
    memcpy((char*)mms_mma_get_mms_setting_input_p, (char*)get_setting_req, sizeof(wap_mma_get_setting_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_SETTING,
        MMA_INT_SIG_TYPE_MSG_GET_SETTING_REQ,
        source,
        mms_mma_get_mms_setting_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_setProfile
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source          [IN]        
 *  profile_req     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_setProfile(module_type source, wap_mma_set_profile_req_struct *profile_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_profile_req_struct *mms_mma_set_mms_profile_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(profile_req);

    mms_mma_set_mms_profile_input_p =
        (wap_mma_set_profile_req_struct*) MMA_CALLOC(sizeof(wap_mma_set_profile_req_struct));
    memcpy((char*)mms_mma_set_mms_profile_input_p, (char*)profile_req, sizeof(wap_mma_set_profile_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_SETTING,
        MMA_INT_SIG_TYPE_MSG_SET_PROFILE_REQ,
        source,
        mms_mma_set_mms_profile_input_p);
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  MMAif_SetAppData
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source              [IN]        
 *  set_appdata_req     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_SetAppData(module_type source, wap_mma_set_app_data_req_struct *set_appdata_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_app_data_req_struct *set_appdata_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(set_appdata_req);
    set_appdata_req_input_p = (wap_mma_set_app_data_req_struct*) MMA_CALLOC(sizeof(wap_mma_set_app_data_req_struct));
    ASSERT(set_appdata_req_input_p);
    memcpy((char*)set_appdata_req_input_p, (char*)set_appdata_req, sizeof(wap_mma_set_app_data_req_struct));
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_SET_APPDATA_REQ, source, set_appdata_req_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_SetReadmark
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  set_readmark_req        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_SetReadmark(module_type source, wap_mma_set_readmark_req_struct *set_readmark_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_readmark_req_struct *set_readmark_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(set_readmark_req);

    set_readmark_req_input_p = (wap_mma_set_readmark_req_struct*) MMA_CALLOC(sizeof(wap_mma_set_readmark_req_struct));
    ASSERT(set_readmark_req_input_p);
    memcpy((char*)set_readmark_req_input_p, (char*)set_readmark_req, sizeof(wap_mma_set_readmark_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_SET_READMARK_REQ,
        source,
        set_readmark_req_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_ValidateMsg
 * DESCRIPTION
 *  This function is used to check if the message is still valid
 * PARAMETERS
 *  source                  [IN]        
 *  msg_is_valid_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_ValidateMsg(module_type source, wap_mma_msg_is_valid_req_struct *msg_is_valid_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_msg_is_valid_req_struct *msg_is_valid_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg_is_valid_req);

    msg_is_valid_req_input_p = (wap_mma_msg_is_valid_req_struct*) MMA_CALLOC(sizeof(wap_mma_msg_is_valid_req_struct));
    ASSERT(msg_is_valid_req_input_p);
    memcpy((char*)msg_is_valid_req_input_p, (char*)msg_is_valid_req, sizeof(wap_mma_msg_is_valid_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_VALIDATE_MSG_REQ,
        source,
        msg_is_valid_req_input_p);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  MMAif_sendProgressInd
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  progressData        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_sendProgressInd(void *progressData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsProgressStatus *progress_status_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(progressData);
    progress_status_p = (MmsProgressStatus*) MMA_CALLOC(sizeof(MmsProgressStatus));
    memcpy(progress_status_p, progressData, sizeof(MmsProgressStatus));
    MMA_SIGNAL_SENDTO_P(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_PROGRESS_IND, progress_status_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_deleteFolder
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  delete_folder_req       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_deleteFolder(module_type source, srv_um_delete_folder_req_struct *delete_folder_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_req_struct *delete_folder_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(delete_folder_req);

    delete_folder_req_input_p = (srv_um_delete_folder_req_struct*) MMA_CALLOC(sizeof(srv_um_delete_folder_req_struct));
    memcpy(delete_folder_req_input_p, delete_folder_req, sizeof(srv_um_delete_folder_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_UM_DELETE_FOLDER_REQ,
        source,
        delete_folder_req_input_p);
}


#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  MMAif_deleteMsg
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source          [IN]        
 *  delete_req      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_deleteMsg(module_type source, wap_mma_delete_req_struct *delete_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_req_struct *delete_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(delete_req);

    delete_req_input_p = (wap_mma_delete_req_struct*) MMA_CALLOC(sizeof(wap_mma_delete_req_struct));
    memcpy(delete_req_input_p, delete_req, sizeof(wap_mma_delete_req_struct));
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_DELETE_REQ, source, delete_req_input_p);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  MMAif_getMemStatus
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  get_mem_status_req      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getMemStatus(module_type source, wap_mma_get_mem_status_req_struct *get_mem_status_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_mem_status_req_struct *get_mem_status_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_mem_status_req);
    get_mem_status_req_input_p =
        (wap_mma_get_mem_status_req_struct*) MMA_CALLOC(sizeof(wap_mma_get_mem_status_req_struct));
    ASSERT(get_mem_status_req_input_p);
    memcpy((char*)get_mem_status_req_input_p, (char*)get_mem_status_req, sizeof(wap_mma_get_mem_status_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MAIN,
        MMA_INT_SIG_TYPE_MSG_GET_MEM_STATUS_REQ,
        source,
        get_mem_status_req_input_p);
}

#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
/*****************************************************************************
 * FUNCTION
 *  MMAif_getMsgInfo
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  get_msg_info_req        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getMsgInfo(module_type source, wap_mma_get_msg_info_req_struct *get_msg_info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_info_req_struct *get_msg_info_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_msg_info_req);

    get_msg_info_req_input_p = (wap_mma_get_msg_info_req_struct*) MMA_CALLOC(sizeof(wap_mma_get_msg_info_req_struct));
    ASSERT(get_msg_info_req_input_p);
    memcpy((char*)get_msg_info_req_input_p, (char*)get_msg_info_req, sizeof(wap_mma_get_msg_info_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_GET_MSG_INFO_REQ,
        source,
        get_msg_info_req_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_getMsgList
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source              [IN]        
 *  get_list_req        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getMsgList(module_type source, wap_mma_get_msg_list_req_struct *get_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_list_req_struct *get_list_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_list_req);

    get_list_req_input_p = (wap_mma_get_msg_list_req_struct*) MMA_CALLOC(sizeof(wap_mma_get_msg_list_req_struct));
    ASSERT(get_list_req_input_p);
    memcpy((char*)get_list_req_input_p, (char*)get_list_req, sizeof(wap_mma_get_msg_list_req_struct));
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_GET_MSG_LIST_REQ, source, get_list_req_input_p);
}
#endif /* MMA_JSR_PST_MMS_OPERATON_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  MMAif_saveMsg
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source          [IN]        
 *  save_req        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_saveMsg(module_type source, wap_mma_save_req_struct *save_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_save_req_struct *save_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(save_req);

    save_req_input_p = (wap_mma_save_req_struct*) MMA_CALLOC(sizeof(wap_mma_save_req_struct));
    ASSERT(save_req_input_p);
    memcpy((char*)save_req_input_p, (char*)save_req, sizeof(wap_mma_save_req_struct));
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_SAVE_REQ, source, save_req_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_parseMsg
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source          [IN]        
 *  parse_req       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_parseMsg(module_type source, wap_mma_get_content_req_struct *parse_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_req_struct *parse_input_p = NULL;

    ASSERT(parse_req);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parse_input_p = (wap_mma_get_content_req_struct*) MMA_CALLOC(sizeof(wap_mma_get_content_req_struct));
    ASSERT(parse_input_p);
    memcpy((char*)parse_input_p, (char*)parse_req, sizeof(wap_mma_get_content_req_struct));
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_PARSE_REQ, source, parse_input_p);
#else
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_PARSE_REQ, source, parse_input_p);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_createMsg
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source              [IN]        
 *  create_req          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_createMsg(module_type source, wap_mma_create_req_struct *create_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_req_struct *create_input_p = NULL;

    ASSERT(create_req);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    create_input_p = (wap_mma_create_req_struct*) MMA_CALLOC(sizeof(wap_mma_create_req_struct));
    ASSERT(create_input_p);
    memcpy((char*)create_input_p, (char*)create_req, sizeof(wap_mma_create_req_struct));
    /* MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_CREATE, MMA_INT_SIG_TYPE_MSG_CREATE_REQ, source, create_input_p); */
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_CREATE_REQ, source, create_input_p);
}

/*****************************************************************************
 * FUNCTION
 *  MMAif_freeContentMem
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source              [IN]        
 *  create_req          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_freeContentMem(module_type source, wap_mma_free_content_info_struct *free_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_free_content_info_struct *free_input_p = NULL;

    ASSERT(free_req);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_input_p = (wap_mma_free_content_info_struct*) MMA_CALLOC(sizeof(wap_mma_free_content_info_struct));
    ASSERT(free_input_p);
    memcpy((char*)free_input_p, (char*)free_req, sizeof(wap_mma_free_content_info_struct));
    /* MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_CREATE, MMA_INT_SIG_TYPE_MSG_CREATE_REQ, source, create_input_p); */
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_FREE_MMS_CONTENT_INFO, source, free_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_recvObjInd
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source          [IN]        
 *  obj_ind_req     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_recvObjInd(module_type source, wap_mma_mms_obj_ind_struct *obj_ind_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_mms_obj_ind_struct *mms_obj_ind_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(obj_ind_req);

    if (obj_ind_req->msg_type == MMA_MSG_TYPE_NOTIFICATION ||
        obj_ind_req->msg_type == MMA_MSG_TYPE_READ_REPORT || obj_ind_req->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT)
    {
        mms_obj_ind_input_p = (wap_mma_mms_obj_ind_struct*) MMA_CALLOC(sizeof(wap_mma_mms_obj_ind_struct));
        ASSERT(mms_obj_ind_input_p);
        memcpy((char*)mms_obj_ind_input_p, (char*)obj_ind_req, sizeof(wap_mma_mms_obj_ind_struct));
        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_MMS_OBJ_IND, source, mms_obj_ind_input_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_deleteMessage
 * DESCRIPTION
 *  This function is MMSif_deleteMessage() wrapper
 * PARAMETERS
 *  source      [IN]        
 *  msgId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_deleteMessage(mma_submodule_enum source, MSF_UINT32 msgId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_busy = (kal_bool)(g_mma_wrapper_queue != NULL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_insert_node_to_queue(&g_mma_wrapper_queue, source, msgId, NULL, MMA_ACTION_DELETE_MSG);
    if (is_busy == KAL_FALSE)
    {
        MMSif_deleteMessage(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(msgId), (MmsFileType)mma_msgmgr_get_msg_suffix(msgId), (MSF_UINT8) mma_get_mms_type_message_storage(msgId));
    }
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  MMAlib_getMessageFullPathExt
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  msg_id          [IN]        
 *  dest            [IN]         
 *  dest_len        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool MMAlib_getMessageFullPathExt(MSF_UINT32 msg_id, char *dest, kal_uint32 dest_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_get_msg_file_name(msg_id, (kal_wchar*) dest, dest_len);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  MMAlib_getMessagePath
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
char *MMAlib_getMessagePath(MSF_UINT8 mod_id, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;
    kal_uint8 storage_type;
    /* take the location from the parameter msg_info->location */
    char *filepath_p = (char*)MSF_MEM_CALLOC(mod_id, 1, strlen("c:\\@mms\\mms_sys\\xxxxxxxx.s") + 2); /* To reduce size of ram MMA_MAX_INTERNAL_FILENAME_LENGTH); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    storage_type = mma_get_message_storage(msg_id);
    if(msg_info != NULL)
    {
        if (filepath_p != NULL)
        {
        
            if (storage_type == MMA_MSG_STORAGE_PHONE)
            {
                sprintf(filepath_p, "%s%x.%c", MMS_PDU_FOLDER, (unsigned int)msg_id, msg_info->suffix);
            }
            else if(storage_type == MMA_MSG_STORAGE_CARD1)
            {
                sprintf(filepath_p, "%s%x.%c", MMS_PDU_FOLDER, (unsigned int)(MMA_TRANSLATE_MSG_ID(msg_id)), msg_info->suffix);
            }
            else
            {
                /* Presently put assert to find erroneous condition*/
             //   ASSERT(0);
            }
        }
    }
    return filepath_p;
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  MMAif_getUnreadMsgList
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                      [IN]        
 *  get_unread_msg_list_req     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getUnreadMsgList(module_type source, wap_mma_get_unread_msg_list_req_struct *get_unread_msg_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_unread_msg_list_req_struct *get_unread_msg_list_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_unread_msg_list_req);
    get_unread_msg_list_input_p = MMA_CALLOC(sizeof(wap_mma_get_unread_msg_list_req_struct));
    ASSERT(get_unread_msg_list_input_p);
    memcpy(
        (char*)get_unread_msg_list_input_p,
        (char*)get_unread_msg_list_req,
        sizeof(wap_mma_get_unread_msg_list_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_GET_UNREAD_MSG_LIST_REQ,
        source,
        get_unread_msg_list_input_p);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
/*****************************************************************************
 * FUNCTION
 *  MMAif_getRecentEvtList
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                      [IN]        
 *  get_recent_evt_list_req     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getRecentEvtList(module_type source, wap_mma_get_recent_evt_list_req_struct *get_recent_evt_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_recent_evt_list_req_struct *get_recent_evt_list_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_recent_evt_list_req);
    get_recent_evt_list_input_p = MMA_CALLOC(sizeof(wap_mma_get_recent_evt_list_req_struct));
    ASSERT(get_recent_evt_list_input_p);
    memcpy(
        (char*)get_recent_evt_list_input_p,
        (char*)get_recent_evt_list_req,
        sizeof(wap_mma_get_recent_evt_list_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_GET_RECENT_EVT_LIST_REQ,
        source,
        get_recent_evt_list_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_deleteRecentEvt
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                      [IN]        
 *  delete_recent_evt_req       [?]         
 *  del_recent_evt_req(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_deleteRecentEvt(module_type source, wap_mma_delete_recent_evt_req_struct *delete_recent_evt_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_delete_recent_evt_req_struct *delete_recent_evt_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(delete_recent_evt_req);
    delete_recent_evt_input_p = MMA_CALLOC(sizeof(wap_mma_delete_recent_evt_req_struct));
    ASSERT(delete_recent_evt_input_p);
    memcpy(
        (char*)delete_recent_evt_input_p,
        (char*)delete_recent_evt_req,
        sizeof(wap_mma_delete_recent_evt_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_DELETE_RECENT_EVT_REQ,
        source,
        delete_recent_evt_input_p);
}
#endif  /*#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */


#ifdef __MMI_MMS_MMA_DRM_ENCODING__
/*****************************************************************************
 * FUNCTION
 *  MMAif_drmEncodeDone
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                      [IN]        
 *  encode_done_p               [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_drmEncodeDone(module_type source, wap_mma_drm_encode_done_ind_struct *encode_done_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_drm_encode_done_ind_struct *encode_done_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(encode_done_p);
    encode_done_input_p = MMA_CALLOC(sizeof(wap_mma_drm_encode_done_ind_struct));
    ASSERT(encode_done_input_p);
    memcpy((char*)encode_done_input_p, (char*)encode_done_p, sizeof(wap_mma_drm_encode_done_ind_struct));
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_DRMSRV, MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_DONE, source, encode_done_input_p);
}
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  MMAif_getMsgProperty
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  get_msg_property_p      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getMsgProperty(module_type source, wap_mma_get_msg_property_req_struct *get_msg_property_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_property_req_struct *get_msg_property_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_msg_property_p);
    get_msg_property_input_p = MMA_CALLOC(sizeof(wap_mma_get_msg_property_req_struct));
    ASSERT(get_msg_property_input_p);
    memcpy((char*)get_msg_property_input_p, (char*)get_msg_property_p, sizeof(wap_mma_get_msg_property_req_struct));
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_GET_MSG_PROPERTY_REQ, source, get_msg_property_input_p);
}

/*****************************************************************************
 * FUNCTION
 *  MMAif_getMsgProperty
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  get_msg_property_p      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getMsgAttrTMBReq(module_type source, wap_mma_get_mms_thumbnail_and_attr_info_req_struct *get_msg_attr_tmb_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_mms_thumbnail_and_attr_info_req_struct *get_msg_attr_tmb_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_msg_attr_tmb_p);
    get_msg_attr_tmb_input_p = MMA_CALLOC(sizeof(wap_mma_get_mms_thumbnail_and_attr_info_req_struct));
    ASSERT(get_msg_attr_tmb_input_p);
    memcpy((char*)get_msg_attr_tmb_input_p, (char*)get_msg_attr_tmb_p, sizeof(wap_mma_get_mms_thumbnail_and_attr_info_req_struct));
    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_GET_ATTR_AND_THUMBNAIL_REQ, source, get_msg_attr_tmb_input_p);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__ 
/*****************************************************************************
 * FUNCTION
 *  MMAif_SendFmtFormatInd
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  req      [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_SendFmtFormatInd(void *req)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_format_req_strcut *p = (mmi_fmt_format_req_strcut*) req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMS_IN_LARGE_STORAGE	
	if (p->drive == SRV_FMGR_PUBLIC_DRV)
    { 
        /*For phone drive, it will be public drive In case of large storage phone 
        and system drive in case of small storage phone*/
        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_FMT_FORMAT_IND, MMA_MSG_STORAGE_PHONE, NULL);
    }
	else
#endif
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (p->drive == SRV_FMGR_CARD_DRV)
    {
        /*For Memory card*/
        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_FMT_FORMAT_IND, MMA_MSG_STORAGE_CARD1, NULL);
    }
    else
#endif   /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
    {
        /*Not of our intereset, just send the response*/
        mma_main_exit_terminate_mode();
        mma_send_fmt_format_rsp(MMA_MSG_STORAGE_NONE);
    }
}
#endif /* __MMI_FMGR_HIDE_FORMAT_DRIVE__ */

/*****************************************************************************
 * FUNCTION
 *  MMAif_handle_target_dat_ind
 * DESCRIPTION
 *  This function is used to set target data
 * PARAMETERS
 *  source                      [IN]        
 *  target_data_ind_p               [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_handle_target_dat_ind(module_type source, mms_target_data_ind_struct *target_data_ind_p, peer_buff_struct *peer_buffer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *peer_pdu = NULL;
    kal_uint16 peer_pdu_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch(target_data_ind_p->data_type)
	{
	case MMS_TARGET_DATA_ROAMING_STATUS:
		{
			mms_target_data_roaming_status_struct *target_data_roaming_status_p = NULL;
			target_data_roaming_status_p = MMA_CALLOC(sizeof(mms_target_data_roaming_status_struct));

			peer_pdu = (MSF_UINT8*) get_pdu_ptr(peer_buffer_p, &peer_pdu_len);
			memcpy((char*)target_data_roaming_status_p, (char*)peer_pdu, sizeof(mms_target_data_roaming_status_struct));
		    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_SETTING, MMA_INT_SIG_TYPE_MSG_SET_ROAMING_STATUS, source, target_data_roaming_status_p);		
		}
		break;

	case MMS_TARGET_DATA_OWNER_NUMBER:
		break;

	case MMS_TARGET_DATA_PLMN_NUMBER:
		break;

    case MMS_TARGET_DATA_MMS_VERSION:
		{
		    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_SETTING, MMA_INT_SIG_TYPE_MSG_SET_MMSC_VERSION, source, NULL);
		}
		break;

	case MMS_TARGET_DATA_USER_AGENT:
		{
		    MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_SETTING, MMA_INT_SIG_TYPE_MSG_SET_USER_AGENT, source, NULL);
		}
		break;

	default:
		break;
	}

}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  MMAlib_getMessageInfoPath
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
char *MMAlib_getMessageInfoPath(kal_uint32 msg_id)  /* For MMA internal use */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *filepath_p = (char*)MMA_CALLOC(MMA_MAX_INTERNAL_FILENAME_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filepath_p != NULL)
    {
        sprintf(filepath_p, "%s%x.i", MMS_INFO_FOLDER, msg_id);
    }
    return filepath_p;
}


/*****************************************************************************
 * FUNCTION
 *  test_mma_set_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void test_mma_set_profile()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_wchar *a = L"http://192.168.71.130:80/vikas=123";

    wap_mma_set_profile_req_struct mms_mma_set_profile = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_mma_set_profile.app_id = 5;
    mms_mma_set_profile.req_id = 7;
    mms_mma_set_profile.connection_type = MMA_CONN_TYPE_HTTP_DIRECT;
    mms_mma_set_profile.data_account = 10;
    memcpy(mms_mma_set_profile.homepage_url, a, kal_wstrlen(a) * 2);

    mms_mma_set_profile.proxy_addr[0] = 0;
    mms_mma_set_profile.proxy_addr[1] = 0;
    mms_mma_set_profile.proxy_addr[2] = 0;
    mms_mma_set_profile.proxy_addr[3] = 0;
    mms_mma_set_profile.proxy_port = 80;

    MMAif_setProfile(MOD_MMI, &mms_mma_set_profile);

}


/*****************************************************************************
 * FUNCTION
 *  test_mma_set_mms_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void test_mma_set_mms_settings()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    wap_mma_set_setting_req_struct mms_setting_req = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_setting_req.mms_version = 0x11;
    mms_setting_req.retrieval_setting.anonymous_filter = KAL_TRUE;
    mms_setting_req.retrieval_setting.advertisement_filter = KAL_TRUE;
    mms_setting_req.retrieval_setting.delivery_report = KAL_TRUE;
    mms_setting_req.retrieval_setting.home_network = MMA_RETRIEVAL_MODE_DEFERRED;
    mms_setting_req.retrieval_setting.roaming = MMA_RETRIEVAL_MODE_AS_HOME;

    MMAif_setSetting(MOD_MMI, &mms_setting_req);
}
#endif	/* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
/*****************************************************************************
 * FUNCTION
 *  MMAif_getUmmsMsgNum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_getUmmsMsgNum(module_type source, wap_mma_get_msg_num_req_struct * get_msg_num_req)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_num_req_struct *get_msg_num_input_p = NULL;

    ASSERT(get_msg_num_req);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_msg_num_input_p = (wap_mma_get_msg_num_req_struct*) MMA_CALLOC(sizeof(wap_mma_get_msg_num_req_struct));
    memcpy((char*)get_msg_num_input_p, (char*)get_msg_num_req, sizeof(wap_mma_get_msg_num_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_GET_MSG_NUM_REQ,
        source,
        get_msg_num_input_p);
}
#endif /* MMA_JSR_PST_MMS_OPERATON_SUPPORT */

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  MMAif_markRRStatus
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  mark_rr_req        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_markRRStatus(module_type source, wap_mma_rr_mark_req_struct *mark_rr_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_rr_mark_req_struct *mark_rr_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mark_rr_req);

    mark_rr_req_input_p = (wap_mma_rr_mark_req_struct*) MMA_CALLOC(sizeof(wap_mma_rr_mark_req_struct));
    ASSERT(mark_rr_req_input_p);
    memcpy((char*)mark_rr_req_input_p, (char*)mark_rr_req, sizeof(wap_mma_rr_mark_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_RR_MARK_REQ,
        source,
        mark_rr_req_input_p);
}
#endif	/* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__ 
/*****************************************************************************
 * FUNCTION
 *  mms_send_fmt_format_rsp
 * DESCRIPTION
 *  This function is used to send FMT format response
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_send_fmt_format_rsp(kal_uint8 drive_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_format_rsp_strcut *rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_fmt_format_rsp_strcut*) construct_local_para((kal_uint16) sizeof(mmi_fmt_format_rsp_strcut), TD_RESET);

    rsp->result = FS_NO_ERROR;
    if((drive_enum == MMA_MSG_STORAGE_PHONE) || (drive_enum == MMA_MSG_STORAGE_CARD1))
    {
        kal_uint8 storage = translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)drive_enum);  
        /* After format the Phone, mms storage folder does not exist. Create/Uplaod will not work */
        MMSlib_createFolder(storage);
    }
    mms_mma_send_ilm(rsp, NULL, MSG_ID_MMI_FMT_FORMAT_RSP, MOD_FMT);
}
#endif	/* __MMI_FMGR_HIDE_FORMAT_DRIVE__ */

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  MMAif_chgMsgStorage
 * DESCRIPTION
 *  This function is used to to handle card plug-out indication
 * PARAMETERS
 *  card_info                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_chgMsgStorage(module_type source, wap_mma_change_msg_storage_req_struct *chg_msg_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_change_msg_storage_req_struct *chg_msg_storage_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(chg_msg_storage);

    chg_msg_storage_p = (wap_mma_change_msg_storage_req_struct*) MMA_CALLOC(sizeof(wap_mma_change_msg_storage_req_struct));
    ASSERT(chg_msg_storage_p);
    memcpy((char*)chg_msg_storage_p, (char*)chg_msg_storage, sizeof(wap_mma_change_msg_storage_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_CHG_STORAGE_REQ,
        source,
        chg_msg_storage_p);
}


/*****************************************************************************
 * FUNCTION
 *  MMAif_handleMemCardPlugInReq
 * DESCRIPTION
 *  This function is used to to handle card plug-in indication
 * PARAMETERS
 *  card_info                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_handleMemCardPlugInReq(mms_mem_card_plug_in_out_struct *card_info)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mem_card_plug_in_out_struct *card_info_p = NULL;

    ASSERT(card_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    card_info_p = (mms_mem_card_plug_in_out_struct*) MMA_CALLOC(sizeof(mms_mem_card_plug_in_out_struct));
    memcpy((char*)card_info_p, (char*)card_info, sizeof(mms_mem_card_plug_in_out_struct));
    /*Rahul:Temp code */
    card_info_p->drv_list[0] = MMA_MSG_STORAGE_CARD1;
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MAIN,
        MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND,
        MOD_MMI,
        card_info_p);

}

/*****************************************************************************
 * FUNCTION
 *  MMAif_handleMemCardPlugOutReq
 * DESCRIPTION
 *  This function is used to to handle card plug-out indication
 * PARAMETERS
 *  card_info                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_handleMemCardPlugOutReq(mms_mem_card_plug_in_out_struct *card_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mem_card_plug_in_out_struct *card_info_p = NULL;

    ASSERT(card_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    card_info_p = (mms_mem_card_plug_in_out_struct*) MMA_CALLOC(sizeof(mms_mem_card_plug_in_out_struct));
    memcpy((char*)card_info_p, (char*)card_info, sizeof(mms_mem_card_plug_in_out_struct));
    /*Rahul:Temp code */
    card_info_p->drv_list[0] = MMA_MSG_STORAGE_CARD1;
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MAIN,
        MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_IND,
        MOD_MMI,
        card_info_p);

}

/*****************************************************************************
 * FUNCTION
 *  MMAif_MemCradPlugOutRes
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                          [IN]        
 *  mms_mem_card_plug_in_out_res_struct      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_MemCradPlugOutRes(mma_result_enum result, mma_msg_storage_type_enum  card_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mem_card_plug_in_out_res_struct *rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp =
        (mms_mem_card_plug_in_out_res_struct*) construct_local_para(
                                        (kal_uint16) sizeof(mms_mem_card_plug_in_out_res_struct),
                                        TD_CTRL | TD_RESET);
    rsp->result = result;
    rsp->drv_enum = card_enum;

    mms_mma_send_ilm(rsp, NULL, MSG_ID_MMI_MMS_CARD_PLUG_OUT_RES, MOD_MMI);

}

/*****************************************************************************
 * FUNCTION
 *  MMAif_MemCradPlugInRes
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                          [IN]        
 *  mms_mem_card_plug_in_out_res_struct      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_MemCradPlugInRes(mma_result_enum result, mma_msg_storage_type_enum  card_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mem_card_plug_in_out_res_struct *rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp =
        (mms_mem_card_plug_in_out_res_struct*) construct_local_para(
                                        (kal_uint16) sizeof(mms_mem_card_plug_in_out_res_struct),
                                        TD_CTRL | TD_RESET);
    rsp->result = result;
    rsp->drv_enum = card_enum;

    mms_mma_send_ilm(rsp, NULL, MSG_ID_MMI_MMS_CARD_PLUG_IN_RES, MOD_MMI);

}


#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */


#ifdef __MMI_MMS_CONVERSATION_BOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  MMAif_UMtraverseMmsList
 * DESCRIPTION
 *  This function is used to check if the message is still valid
 * PARAMETERS
 *  source                  [IN]        
 *  msg_is_valid_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_UMtraverseMmsList(module_type source, srv_um_traverse_msg_req_struct *um_traverse_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_traverse_msg_req_struct *um_traverse_list_req_input_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(um_traverse_list_req);

    um_traverse_list_req_input_p = (srv_um_traverse_msg_req_struct*) MMA_CALLOC(sizeof(srv_um_traverse_msg_req_struct));
    ASSERT(um_traverse_list_req_input_p);
    memcpy((char*)um_traverse_list_req_input_p, (char*)um_traverse_list_req, sizeof(srv_um_traverse_msg_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_UM_TRAVERSE_MSG_REQ,
        source,
        um_traverse_list_req_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_um_get_conv_list_rsp
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  dst_id      [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_um_get_conv_list_rsp(module_type dst_id, kal_uint32 app_id, kal_bool result, kal_uint16 msg_number, kal_bool more)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_traverse_msg_rsp_struct *traverse_msg_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    traverse_msg_rsp =
        (srv_um_traverse_msg_rsp_struct*) construct_local_para(
                                            sizeof(srv_um_traverse_msg_rsp_struct),
                                            TD_CTRL | TD_RESET);

    traverse_msg_rsp->app_id = app_id;
    traverse_msg_rsp->msg_type = (srv_um_msg_enum) SRV_UM_MSG_MMS;
    traverse_msg_rsp->result = result;
    traverse_msg_rsp->msg_number = msg_number;
    traverse_msg_rsp->more = more;
    mms_mma_send_ilm(traverse_msg_rsp, NULL, MSG_ID_MMI_UM_TRAVERSE_MSG_RSP, dst_id);
}
#endif  /* __MMI_MMS_CONVERSATION_BOX_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  MMAif_SyncDeleteMsg
 * DESCRIPTION
 *  This function is used to delete a mms in sync behavior
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_SyncDeleteMsg(mms_sync_delete_msg_ind_struct *sync_delete_ind)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_sync_delete_msg_ind_struct *sync_delete_msg_ind_input_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sync_delete_msg_ind_input_p = (mms_sync_delete_msg_ind_struct*) MMA_CALLOC(sizeof(mms_sync_delete_msg_ind_struct));
    ASSERT(sync_delete_ind);
    memcpy((char*)sync_delete_msg_ind_input_p, (char*)sync_delete_ind, sizeof(mms_sync_delete_msg_ind_struct));
    MMA_SIGNAL_SENDTO_P(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_SYNC_DELETE_MSG_IND,
        sync_delete_msg_ind_input_p);
}


#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  MMAif_CopyMsgToArchive
 * DESCRIPTION
 *  This function is used to make another copy of mms msg to Archive folder
 * PARAMETERS
 *  copy_msg_archive_req      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_CopyMsgToArchive(module_type source, wap_mma_cpy_msg_to_archive_folder_req_struct *copy_msg_archive_req)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cpy_msg_to_archive_folder_req_struct *copy_msg_archive_req_input_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_msg_archive_req_input_p = (wap_mma_cpy_msg_to_archive_folder_req_struct*) MMA_CALLOC(sizeof(wap_mma_cpy_msg_to_archive_folder_req_struct));
    ASSERT(copy_msg_archive_req);
    memcpy((char*)copy_msg_archive_req_input_p, (char*)copy_msg_archive_req, sizeof(wap_mma_cpy_msg_to_archive_folder_req_struct));
    MMA_SIGNAL_SENDTO_IP(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_CPY_TO_ARCHIVE_REQ,
        source,
        copy_msg_archive_req_input_p);
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_copy_msg_to_archive_rsp
 * DESCRIPTION
 *  This function is used to send the response of the Copy to Archive operation
 * PARAMETERS
 *  dst_id      [IN]        
 *  app_id      [IN]        
 *  req_id      [IN]
 *  msg_id      [IN]
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_copy_msg_to_archive_rsp(module_type dst_id, kal_uint32 app_id, kal_uint32 req_id, kal_uint32 msg_id, mma_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_cpy_msg_to_archive_folder_rsp_struct *copy_msg_to_archive_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_msg_to_archive_rsp =
        (wap_mma_cpy_msg_to_archive_folder_rsp_struct*) construct_local_para(
                                            sizeof(wap_mma_cpy_msg_to_archive_folder_rsp_struct),
                                            TD_CTRL | TD_RESET);

    copy_msg_to_archive_rsp->app_id = app_id;
    copy_msg_to_archive_rsp->req_id = req_id;
    copy_msg_to_archive_rsp->msg_id = msg_id;
    copy_msg_to_archive_rsp->result = result;
    mms_mma_send_ilm(copy_msg_to_archive_rsp, NULL, MSG_ID_MMI_MMS_CPY_TO_ARCHIVE_RSP, dst_id);
}
#endif  /* __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__ */


#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  MMAif_mmsCheckTemplateRsp
 * DESCRIPTION
 *  This function is used to get the check default template rsp from application
 * PARAMETERS
 *  ready_rsp      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MMAif_mmsCheckTemplateRsp(wap_mma_check_template_rsp_struct *template_rsp)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_check_template_rsp_struct *template_rsp_input_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    template_rsp_input_p = (wap_mma_check_template_rsp_struct*) MMA_CALLOC(sizeof(wap_mma_check_template_rsp_struct));
    ASSERT(template_rsp);
    memcpy((char*)template_rsp_input_p, (char*)template_rsp, sizeof(wap_mma_check_template_rsp_struct));
    MMA_SIGNAL_SENDTO_P(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_DEF_TMPLT_GEN_DONE_IND,
        template_rsp_input_p);
}
#endif  /* __COSMOS_MMI_PACKAGE__ */
#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_INTERFACE_C */ 

