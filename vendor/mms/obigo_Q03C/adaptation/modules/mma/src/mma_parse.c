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
 * mma_parse.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions which are used to parse MMS message.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMA_PARSE_C
#define _MMA_PARSE_C
#if defined(MMS_SUPPORT)
#include <stdio.h>

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"

#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "mmsadp.h"
#include "custom_wap_config.h"

/* APPLIB */
#include "app_str.h"
#include "app_mine.h"
#include "app_datetime.h"

/* PLUTOMMI */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "WguiCategoryGprot.h"
//#include "UMGProt.h"        /* For mma_interface.h */
#include "UmSrvGprot.h"
#include "UcSrvGprot.h"

/* MSF */
#include "msf_def.h"
#include "msf_core.h"   /* MSF: System core call */
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_chrs.h"   /* MSF: character API */
#include "msm.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#include "mmsl_if.h"
#include "mltypes.h"
#include "mutils.h"

/* SLS */
#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"

/* MMA */
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_env.h"
#include "mma_main.h"
#include "mma_mime.h"
#include "mma_msg_struct.h"
#include "mma_parse.h"
#include "mma_create.h"
#include "mma_utilities.h"
#include "mma_interface.h"
#include "mma_xml.h"
#include "mma_msgmgr.h"

#include "app_oppostcard.h"
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "UcAppGprot.h"
#endif
#include "Conversions.h"

#ifdef __MMI_VCARD__
#include "MmsSrvGprot.h"
#include "vcard_lib.h"
#endif // __MMI_VCARD__
#include "FileMgrSrvGProt.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define MMA_MAX_PARSE_TASK_NUM 5
#define MMA_PARSE_SLEEP_TIME 10
#define MMA_PARSE_SLEEP_TIME_START_AT_COUNT 20
#define MMA_PARSE_RSP_BUFFER_SIZE 2000

#define MMA_PARSE_ALLOC(s)            MSF_MEM_ALLOC(mma_parse_mod_id, s)
#define MMA_PARSE_CALLOC(s)           MSF_MEM_CALLOC(mma_parse_mod_id, 1, s)
#define MMA_PARSE_FREE(p)             MSF_MEM_FREE(mma_parse_mod_id, p)
//#define MMA_CHARSET_CHECK_BOM_SIZE 100

MSF_UINT8 mma_parse_mod_id = MSF_MODID_MMA;
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local static Variable
*****************************************************************************/
static mma_parse_context_struct g_mma_parse_context = {0, };

/***************************************************************************** 
* Local Function
*****************************************************************************/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
static void mma_parse_store_body_object_info(mma_mms_object_struct *obj, kal_uint32 msg_id, mma_media_msg_enum media_type);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mma_parse_init
 * DESCRIPTION
 *  Parse sub-module init
 * PARAMETERS
 *  void
 * RETURNS
 *  MSF_BOOL
 *****************************************************************************/
kal_bool mma_parse_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_parse_context.mma_parse_task_queue = NULL;
    g_mma_parse_context.mma_parse_env_state = MMA_PARSE_ENV_STATE_ACTIVE;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_parse_terminate
 * DESCRIPTION
 *  Parse sub-module termination
 * PARAMETERS
 *  void
 * RETURNS
 *  MSF_BOOL
 *****************************************************************************/
kal_bool mma_parse_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_parse_context.mma_parse_task_queue = NULL;
    g_mma_parse_context.mma_parse_env_state = MMA_PARSE_ENV_STATE_TERMINATED;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_parse_get_active_task
 * DESCRIPTION
 *  Get current create request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mms_mma_queue_struct *mma_parse_get_active_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mma_parse_context.mma_parse_task_queue;
}


/*****************************************************************************
 * FUNCTION
 *  mma_parse_get_task_by_app
 * DESCRIPTION
 *  Get task by application ID
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  mms_mma_queue_struct
 *****************************************************************************/
static mms_mma_queue_struct *mma_parse_get_task_by_app(kal_uint32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mms_mma_queue_struct *task = g_mma_parse_context.mma_parse_task_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMA_MAX_PARSE_TASK_NUM && task != NULL; i++, task = task->next)
    {
        mma_parse_info_struct *info = (mma_parse_info_struct*) task->data;

        if (info->app_id == app_id)
        {
            return task;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_parse_get_task_by_msg
 * DESCRIPTION
 *  Get task by message ID
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  mms_mma_queue_struct
 *****************************************************************************/
mms_mma_queue_struct *mma_parse_get_task_by_msg(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mms_mma_queue_struct *task = g_mma_parse_context.mma_parse_task_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMA_MAX_PARSE_TASK_NUM && task != NULL; i++, task = task->next)
    {
        mma_parse_info_struct *info = (mma_parse_info_struct*) task->data;

        if (info->msg_id == msg_id)
        {
            return task;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_parse_get_task_by_req
 * DESCRIPTION
 *  Get task by request ID
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  mms_mma_queue_struct
 *****************************************************************************/
static mms_mma_queue_struct *mma_parse_get_task_by_req(kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_get_node_from_queue(g_mma_parse_context.mma_parse_task_queue, req_id, 0);
}

static void mma_parse_fill_address_info(mms_msg_addr_info_struct *addr_info_struct, char* address, kal_uint8 addr_type, kal_uint8 addr_group)
{
    long srcLen = 0;
    long dstLen = 0;

	srcLen = strlen(address);
    dstLen = (MMS_MAX_ADDR_DATA_LEN - 1) * sizeof(kal_wchar);
    addr_info_struct->addr_len = (kal_uint8)srcLen;
	addr_info_struct->addr_type = addr_type;
    addr_info_struct->addr_group = addr_group;
	
    msf_charset_utf8_to_ucs2le(address, 
							   &srcLen,
							   (char*)addr_info_struct->address, 
							   &dstLen);
}
/*****************************************************************************
 * FUNCTION
 *  mma_parse_free_info
 * DESCRIPTION
 *  Free parse info
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_parse_free_info(mma_parse_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info != NULL)
    {
        MMA_PARSE_FREE(info->xml_filepath);
        if (info->w_handle >= 0)
        {
            MSF_FILE_CLOSE(info->w_handle);
        }
        switch (info->suffix)
        {
            case MMS_SUFFIX_TEMPLATE:
            case MMS_SUFFIX_SEND_REQ:
            case MMS_SUFFIX_MSG:
                if (info->header != NULL)
                {
                    MMSlib_freeMmsGetHeader(mma_parse_mod_id, info->header->header.g_header);
                    MMA_PARSE_FREE(info->header->header.g_header);
                }
              if(info->mms_dsr /* && info->mode == MMA_MODE_INT_PARSE*/)
                    {
				  (void)mma_mms_free_mms_descriptor(mma_parse_mod_id, info->mms_dsr);
				
                }
                break;
            case MMS_SUFFIX_IMMEDIATE:
            case MMS_SUFFIX_NOTIFICATION:
                if (info->header != NULL && info->header->header.notif != NULL)
                {
                    MMSlib_freeMmsNotification(mma_parse_mod_id, info->header->header.notif);
                    MMA_PARSE_FREE(info->header->header.notif);
                }
				if(info->mms_dsr /* && info->mode == MMA_MODE_INT_PARSE*/)
                    {
				  (void)mma_mms_free_mms_descriptor(mma_parse_mod_id, info->mms_dsr);
				
                }         
                break;
            case MMS_SUFFIX_READREPORT:
            case MMS_SUFFIX_DELIVERYREPORT:
                if (info->header != NULL && info->header->header.report != NULL)
                {
                    MMA_PARSE_FREE(info->header->header.report->subject);
                    MMA_PARSE_FREE(info->header->header.report->address);
					//MMA_PARSE_FREE(info->header->header.report->serverMsgId);
                    MMA_PARSE_FREE(info->header->header.report);
                }
                break;
        }
		freeMmsContentType(mma_parse_mod_id, info->content_type);
		MMA_PARSE_FREE(info->content_type);
        MMA_PARSE_FREE(info->header);
        MMA_FREE(info);
    }
}

#ifdef __MMI_MMS_USE_ASM__ // sandeep
/*This should be defined in some .h file*/
//extern void reset_mms_asm_mem();
#endif

/*****************************************************************************
 * FUNCTION
 *  mma_parse_delete_task
 * DESCRIPTION
 *  Delete specified parse task
 * PARAMETERS
 *  req             [IN]         
 *  node(?)         [IN]        
 *  proceed(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_parse_delete_task(mms_mma_queue_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_parse_info_struct *info = NULL;
    kal_bool is_parse_next = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req != NULL);
	ASSERT((info = (mma_parse_info_struct*) req->data) != NULL);

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_DELETE_TASK_DETAIL,
                      "(mma_parse.c): mma_parse_delete_task(req %d, del state %d, env state %d)\n", info->req_id,
                      info->delete_state, g_mma_parse_context.mma_parse_env_state));
    info->delete_state++;
    if (info->m_handle)
    {
        (void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
    }
    if (info->t_handle)
    {
        (void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
    }

    is_parse_next = (kal_bool) (info->req_id == g_mma_parse_context.mma_parse_task_queue->first_id);       /* Proceed to next request if the deleted is currently active */
    if ((req = mma_remove_node_from_queue(&g_mma_parse_context.mma_parse_task_queue, info->req_id, 0)) != NULL)
    {
#ifdef __MMI_MMS_USE_ASM__
        mma_result_enum result = info->input;
#endif
        mma_parse_free_info(info);
        MMA_FREE(req);
#ifdef __MMI_MMS_USE_ASM__
		if (mma_parse_mod_id == MSF_MODID_ASM) // Sandeep
        {
			mma_parse_mod_id = MSF_MODID_MMA;
			ASMc_kill();
            MSF_RESET_MMS_APP_MEM_POOL(); // Send ASM free request from here
			MMAif_freeAsmMemory();
            if (result == MMA_RESULT_FAIL_USER_CANCEL)
            {
                MMAif_senddeinitasmMem();
            }
        }

#endif /* __MMI_MMS_USE_ASM__*/

        /* Empty MMA folder */
    }

    if (g_mma_parse_context.mma_parse_env_state == MMA_PARSE_ENV_STATE_ENTERING_USB)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
    }
    else if (g_mma_parse_context.mma_parse_env_state == MMA_PARSE_ENV_STATE_TERMINATING)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
    }
    else if (g_mma_parse_context.mma_parse_env_state == MMA_PARSE_ENV_STATE_ACTIVE && is_parse_next &&
             g_mma_parse_context.mma_parse_task_queue)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_PARSE_NEXT_IND);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_parse_delete_task_hdlr
 * DESCRIPTION
 *  Delete specified parse task, and procceed to next task if needed
 * PARAMETERS
 *  req_id          [IN]        
 *  node(?)         [IN]        
 *  proceed(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool mma_parse_delete_task_hdlr(MSF_UINT32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *req = NULL;
    mma_parse_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((req = mma_parse_get_task_by_req(req_id)) == NULL)
    {
        return KAL_TRUE;
    }
    ASSERT((info = (mma_parse_info_struct*) req->data) != NULL);

    if (info->delete_state > 0)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_DUPLICATE_DELETE_TASK,
                          "(mma_parse.c): Duplicate mma_parse_delete_task_hdlr(req %d, del state %d, env state %d)\n",
                          req_id, info->delete_state, g_mma_parse_context.mma_parse_env_state));
    }
    else
    {
            mma_parse_delete_task(req);
            
        }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_parse_handle_rsp
 * DESCRIPTION
 *  handle response from other module
 * PARAMETERS
 *  sig             [IN]        
 *  sig_data        [IN]         
 * RETURNS
 *  TRUE: the response belongs to parse FSM; FALSE: the response doesn't belong to parse FSM
 *****************************************************************************/
kal_bool mma_parse_handle_rsp(MSF_UINT16 sig, void *sig_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sig)
    {
        case MSF_SIG_FILE_NOTIFY:
        {
            mma_parse_info_struct *info = NULL;
            msf_file_notify_t *notify = (msf_file_notify_t*) sig_data;
            mms_mma_queue_struct *entry = mma_parse_get_active_task();
            
            if (entry != NULL)
            {
                info = (mma_parse_info_struct*) entry->data;
            }

            if (info != NULL && notify->fileHandle == info->delayed_handle)
            {
                return KAL_TRUE;
            }
            else
            {
				/*Check if SLS is waiting for File notify*/
				/*	if ( SLS_checkStateWaiting_ext())
					{
						gmms_HDIc_fileNotify(MSF_MODID_SLS, notify->fileHandle, notify->eventType);
					}*/
					
                return KAL_FALSE;
					
                
            }
        }


        default:
            return KAL_FALSE;
    }
}
#ifdef __MMI_MMS_USE_ASM__
static wap_mma_get_content_rsp_struct* mma_parse_fill_slim_ext_rsp(MSF_UINT32 req_id, mma_result_enum ret)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_rsp_struct *rsp = NULL;
    mms_mma_queue_struct *req = NULL;
    mma_parse_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((req = mma_parse_get_task_by_req(req_id)) != NULL);
    ASSERT((info = (mma_parse_info_struct*) req->data) != NULL);

    /*for rsp struct use MMA memory*/
    rsp = (wap_mma_get_content_rsp_struct*) MMA_CALLOC(sizeof(wap_mma_get_content_rsp_struct));
    ASSERT(rsp != NULL);
    rsp->app_id = info->app_id;
    rsp->result = ret;
    rsp->req_id = req->first_id;
    rsp->msg_id = info->msg_id;
    rsp->content_truncate_info = info->content_truncate_info;
    if (ret == MMA_RESULT_OK)
    {

#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
        if (info->suffix == MMS_SUFFIX_TEMPLATE || info->suffix == MMS_SUFFIX_SEND_REQ ||
            info->suffix == MMS_SUFFIX_MSG)
        {
            if (info->header && info->header->header.g_header && info->header->header.g_header->subject.text)
            {
                rsp->mms_header_size = strlen(info->header->header.g_header->subject.text); /* MMA_MODE_HEADER return 0 */
            }
            rsp->mms_body_size = info->user_elements_size - rsp->mms_header_size;   /* MMA_MODE_HEADER return 0 */
        }
        else
        {
            rsp->mms_header_size = info->header_size;   /* MMA_MODE_HEADER return 0 */
            rsp->mms_body_size = info->body_size;       /* MMA_MODE_HEADER return 0 */
        }
#else /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
        rsp->mms_header_size = info->header_size;   /* MMA_MODE_HEADER return 0 */
        rsp->mms_body_size = info->body_size;       /* MMA_MODE_HEADER return 0 */
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
      //  rsp->xml_size = info->xml_size;

        /* isFollowPhoneMMSContentClass: Only valid for EDIT, FORWARD, SEND mode */
        rsp->isFollowPhoneMMSContentClass = mma_is_follow_content_class(info->mms_dsr->body);
       /* if (info->xml_filepath != NULL)
        {
            app_ucs2_strncpy(
                (kal_int8*) & rsp->xml_filepath,
                (kal_int8*) info->xml_filepath,
                MMA_MAX_INTERNAL_FILENAME_LENGTH - 1);
        }*/
		rsp->content_info = info->mms_dsr;
			/*logging information before sending get_content_rsp*/
#ifdef MMS_CONTENT_DUMP_DATA 
			(void)mma_trace_mms_content_info(info->mms_dsr);
#endif	/* MMS_CONTENT_DUMP_DATA */
		(void)mma_update_object_list(mma_parse_mod_id, info->mms_dsr->body, info->storage_type);
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
        mma_msgmgr_reset_parsing_status(info->msg_id);
#endif

    }
    else
    {
      //  rsp->more = FALSE;
    #ifdef __MMI_MMS_MMA_DRM_ENCODING__
        mma_msgmgr_reset_parsing_status(info->msg_id);
    #endif

        mms_mma_send_get_content_rsp((module_type)info->source, rsp, NULL);
    }


    return rsp;

}
#else

/*****************************************************************************
 * FUNCTION
 *  mma_parse_send_ext_rsp
 * DESCRIPTION
 *  mms_mma_get_content_rsp wrapper for successful response with XML content
 * PARAMETERS
 *  req_id          [IN]        
 *  ret             [IN]        
 * RETURNS
 *  TRUE: more XML content to be sent; FALSE: all XML content were read
 *****************************************************************************/
static kal_bool mma_parse_send_ext_rsp(MSF_UINT32 req_id, mma_result_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool del_flg = KAL_TRUE;
    wap_mma_get_content_rsp_struct *rsp = NULL;
    mms_mma_queue_struct *req = NULL;
    mma_parse_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((req = mma_parse_get_task_by_req(req_id)) != NULL);
    ASSERT((info = (mma_parse_info_struct*) req->data) != NULL);


    rsp = (wap_mma_get_content_rsp_struct*) MMA_PARSE_CALLOC(sizeof(wap_mma_get_content_rsp_struct));
    ASSERT(rsp != NULL);
    rsp->app_id = info->app_id;
    rsp->result = ret;
    rsp->req_id = req->first_id;
    rsp->msg_id = info->msg_id;
    //rsp->buffer_index = info->buffer_index;
    rsp->content_truncate_info = info->content_truncate_info;
    if (ret == MMA_RESULT_OK)
    {
       /* int fh = 0;
        kal_char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

        MMA_GET_MMS_XML_FILEPATH(file_path, 0);
        fh = mma_msf_file_open_in_blocking_mode(mma_parse_mod_id, file_path, MSF_FILE_SET_RDONLY, 0, info->storage_type);
        if (fh >= 0)
        {
            char *buffer = NULL;
            long byte_read = 0;

            buffer = (char*)MMA_PARSE_CALLOC(2000);
            ASSERT(buffer != NULL);
			
			memset(buffer, 0, 2000);
			
            MSF_FILE_SEEK(fh, 2000 * info->buffer_index, HDI_FILE_SEEK_SET);
            byte_read = MSF_FILE_READ(fh, buffer, 2000);
            more = (2000 * info->buffer_index + byte_read < info->xml_size);*/
        #ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
            if (info->suffix == MMS_SUFFIX_TEMPLATE || info->suffix == MMS_SUFFIX_SEND_REQ ||
                info->suffix == MMS_SUFFIX_MSG)
            {
                if (info->header && info->header->header.g_header && info->header->header.g_header->subject.text)
                {
                    rsp->mms_header_size = strlen(info->header->header.g_header->subject.text); /* MMA_MODE_HEADER return 0 */
                }
                rsp->mms_body_size = info->user_elements_size - rsp->mms_header_size;   /* MMA_MODE_HEADER return 0 */
            }
            else
            {
                rsp->mms_header_size = info->header_size;   /* MMA_MODE_HEADER return 0 */
                rsp->mms_body_size = info->body_size;       /* MMA_MODE_HEADER return 0 */
            }
        #else /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
            rsp->mms_header_size = info->header_size;   /* MMA_MODE_HEADER return 0 */
            rsp->mms_body_size = info->body_size;       /* MMA_MODE_HEADER return 0 */
        #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
            //rsp->xml_size = info->xml_size;

            /* isFollowPhoneMMSContentClass: Only valid for EDIT, FORWARD, SEND mode */
            rsp->isFollowPhoneMMSContentClass = mma_is_follow_content_class(info->mms_dsr->body);
			/*logging information before sending get_content_rsp*/
#ifdef MMS_CONTENT_DUMP_DATA 
			(void)mma_trace_mms_content_info(info->mms_dsr);
#endif	/* MMS_CONTENT_DUMP_DATA */
			(void)mma_update_object_list(mma_parse_mod_id, info->mms_dsr->body, info->storage_type);
			rsp->content_info = info->mms_dsr;
           /* if (info->xml_filepath != NULL)
            {
                app_ucs2_strncpy(
                    (kal_int8*) & rsp->xml_filepath,
                    (kal_int8*) info->xml_filepath,
                    MMA_MAX_INTERNAL_FILENAME_LENGTH - 1);
            }*/
            //rsp->buffer_size = MMA_PARSE_RSP_BUFFER_SIZE;
            //rsp->more = more;
			
			#ifdef __MMI_MMS_MMA_DRM_ENCODING__
			mma_msgmgr_reset_parsing_status(info->msg_id);
			#endif
			mms_mma_send_get_content_rsp(info->source, rsp, NULL);
           // MMA_PARSE_FREE(buffer);
         //   MSF_FILE_CLOSE(fh);
        

		}
    else
    {
        del_flg = KAL_FALSE;
    #ifdef __MMI_MMS_MMA_DRM_ENCODING__
        mma_msgmgr_reset_parsing_status(info->msg_id);
    #endif
        mms_mma_send_get_content_rsp(info->source, rsp, NULL);
    }

    MMA_PARSE_FREE(rsp);
    return del_flg;
}

#endif /* __MMI_MMS_USE_ASM__*/

/*****************************************************************************
 * FUNCTION
 *  mma_parse_update_address_objects_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mma_parse_update_address_objects_list(mma_parse_info_struct *info, void* postcard_recipients)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 num_of_recipient = 0;
    kal_uint8 num_of_objects = 0;
    mmsAddrObjectInfo *data_context = NULL;
#ifdef __MMS_OBJECT_INFO_SUPPORT__
    mma_object_struct *objects = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    data_context = (mmsAddrObjectInfo*) MMA_CALLOC(sizeof(mmsAddrObjectInfo));
#ifdef __MMS_OBJECT_INFO_SUPPORT__ 
    /* Fill the objects File name */
    objects = info->mms_dsr->body->objects;
    while(objects != NULL)
    {
        if(objects->file_name != NULL)
        {
            long srcLen = 0, dstLen = 0;
			srcLen = strlen(objects->file_name);
			dstLen = (MMS_MAX_OBJECT_FILE_NAME_LEN - 1) * sizeof(kal_wchar);
			msf_charset_utf8_to_ucs2le(objects->file_name, 
									 &srcLen,
									 (char*)data_context->object_data[num_of_objects].file_name, 
									 &dstLen);
			data_context->object_data[num_of_objects].file_name_len = srcLen;
            num_of_objects++;
            if(num_of_objects == MMS_MAX_OBJECT_COUNT)
            {
                break;
            }
        }
        objects = objects->next;
    }
#endif
    /* Set Number of objects*/
    data_context->total_object = num_of_objects;

#ifdef __MMI_MMS_POSTCARD__
    if (info->msg_type == MMA_MSG_TYPE_POSTCARD)
    {

        srv_postcard_recipient_struct *recipients =(srv_postcard_recipient_struct*) postcard_recipients;
        while (recipients!= NULL)
        {
			kal_uint32 srcLen = 0;
			kal_uint32 dstLen = 0;

			srcLen = app_ucs2_strlen((const kal_int8*) recipients->address.postcard_name);
			dstLen = (MMS_MAX_ADDR_DATA_LEN - 1) * sizeof(kal_wchar);

			if (dstLen < srcLen)
			{
				srcLen = dstLen;
			}

			data_context->addr_data[num_of_recipient].addr_len = (kal_uint8)srcLen;
			data_context->addr_data[num_of_recipient].addr_type = MMA_ADDR_TYPE_PHONE_NUMBER;
			data_context->addr_data[num_of_recipient].addr_group = MMA_ADDRESS_GROUP_TYPE_TO;

			app_ucs2_strncpy((kal_int8*) data_context->addr_data[num_of_recipient].address,
						(const kal_int8*)recipients->address.postcard_name,
						dstLen);

            recipients = recipients->next;

            num_of_recipient++;
            if(num_of_recipient == MMS_MAX_ADDR_COUNT)
            {
                break;
            }
        }
    }
    else
#endif
    if((info->header != NULL) && (info->header->header.g_header != NULL))
    {
        /* Get number of recipient */
        MmsAddressList *addr_list = NULL;
        /*TO address*/
        addr_list = info->header->header.g_header->to;
        while(addr_list != NULL)                                        
		{
			if(addr_list->current.addrType != MMS_UNSUPPORTED)
            {
                mma_parse_fill_address_info(&data_context->addr_data[num_of_recipient], addr_list->current.address, 
                    (kal_uint8)translate_mms_address_type_to_mma(addr_list->current.addrType), MMA_ADDRESS_GROUP_TYPE_TO);
                
                num_of_recipient++;
                if(num_of_recipient == MMS_MAX_ADDR_COUNT)
                {
                    break;
                }
            }
            addr_list = addr_list->next;
		}
        /* CC address*/
        if(num_of_recipient < MMS_MAX_ADDR_COUNT)
        {
            addr_list = info->header->header.g_header->cc;
            while(addr_list != NULL)                                        
		    {
			    if(addr_list->current.addrType != MMS_UNSUPPORTED)
                {
                    mma_parse_fill_address_info(&data_context->addr_data[num_of_recipient], addr_list->current.address, 
                         (kal_uint8)translate_mms_address_type_to_mma(addr_list->current.addrType), MMA_ADDRESS_GROUP_TYPE_CC);
                    num_of_recipient++;
                    if(num_of_recipient == MMS_MAX_ADDR_COUNT)
                    {
                        break;
                    }
                }
                addr_list = addr_list->next;
		    }
        }
        /* BCC address*/
        if(num_of_recipient < MMS_MAX_ADDR_COUNT)
        {
            addr_list = info->header->header.g_header->bcc;
            while(addr_list != NULL)                                        
		    {
			    if(addr_list->current.addrType != MMS_UNSUPPORTED)
                {
                     mma_parse_fill_address_info(&data_context->addr_data[num_of_recipient], addr_list->current.address, 
                         (kal_uint8)translate_mms_address_type_to_mma(addr_list->current.addrType), MMA_ADDRESS_GROUP_TYPE_BCC);
                    num_of_recipient++;
                    if(num_of_recipient == MMS_MAX_ADDR_COUNT)
                    {
                        break;
                    }
                }
                addr_list = addr_list->next;
		    }
        }
    }

    /* send a signal to self to make this process as non-blocking */
    data_context->total_address = num_of_recipient;
    
    if((num_of_recipient > 0) || (num_of_objects > 0))
    {
        /* Check to free the memory in calling Signal function */
        MMA_SIGNAL_SENDTO_IUP( MMA_SUBMODULE_MSG_MGR,
                MMA_INT_SIG_TYPE_MSG_UPDATE_ADDR_OBLECTS_INFO,
                0, info->msg_id, data_context);
    }
    else
    {
        /* No need to create a empty file */
        MMA_FREE(data_context);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mma_parse_send_int_rsp
 * DESCRIPTION
 *  wap_send_mms_mma_get_content_rsp wrapper for successful response with XML content
 * PARAMETERS
 *  req_id          [IN]        
 *  ret             [IN]        
 *  entry(?)        [IN]        
 * RETURNS
 *  TRUE: more XML content to be sent; FALSE: all XML content were read(?)
 *****************************************************************************/
static void mma_parse_send_int_rsp(MSF_UINT32 req_id, mma_result_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *req = NULL;
    mma_parse_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((req = mma_parse_get_task_by_req(req_id)) != NULL);
    ASSERT((info = (mma_parse_info_struct*) req->data) != NULL);
    if (ret == MMA_RESULT_OK)
    {
        mms_msg_info_struct *rsp = NULL;
        mms_msg_info_large_data_struct *data = NULL;
        mms_msg_info_property_struct *property = NULL;

        rsp = (mms_msg_info_struct*) MMA_CALLOC(sizeof(mms_msg_info_struct));
        ASSERT(rsp != NULL);

        data =
            (mms_msg_info_large_data_struct*)
            MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
        ASSERT(data != NULL);

        property = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        ASSERT(property != NULL);

        property->msg_size = info->header_size + info->body_size;
        property->user_elements_size = property->msg_size;
        switch (info->suffix)
        {
            case MMS_SUFFIX_TEMPLATE:
            case MMS_SUFFIX_SEND_REQ:
            case MMS_SUFFIX_MSG:
                /* App ID, Reply App ID */
                {
                    char *str = NULL;

                    if ((str = mma_get_app_id_from_params(info->content_type->params)) !=
                        NULL)
                    {
                        strcpy((char*)data->java_app_id, str);
                    }
                    if ((str = mma_get_reply_app_id_from_params(info->content_type->
                                                          params)) != NULL)
                    {
                        strcpy((char*)data->java_reply_app_id, str);
                    }
                }

                /* is_follow_phone_mms_content_class */
                if (mma_is_follow_content_class(info->mms_dsr->body) == TRUE)
                {
                    property->is_follow_phone_mms_content_class = KAL_TRUE;
                }

                /*From Address */
			    if (info->header->header.g_header->from.address != NULL  && 
                    info->header->header.g_header->from.addrType != MMS_UNSUPPORTED)
			    {
				    long srcLen = 0, dstLen = 0;
				    srcLen = strlen(info->header->header.g_header->from.address);
				    dstLen = (MMA_MAX_ADDR_LEN - 1) * sizeof(kal_wchar);
				    data->from_address_type = translate_mms_address_type_to_mma(info->header->header.g_header->from.addrType);
				    msf_charset_utf8_to_ucs2le(info->header->header.g_header->from.address, 
										     &srcLen,
										     (char*)data->from_address, 
										     &dstLen);
			    }
#ifdef __MMI_MMS_POSTCARD__
                if (info->msg_type != MMA_MSG_TYPE_POSTCARD)                
#endif              
                {
			        /* Get number of recipient */
                    property->num_of_recipient = mma_get_recipient_num(info->header->header.g_header);
            
                    /*One TO/CC/BCC address*/
                    if (property->num_of_recipient > 0)
                    {
                        if (info->header->header.g_header->to != NULL  &&
                            info->header->header.g_header->to->current.addrType != MMS_UNSUPPORTED)                        
			            {
				            long srcLen = 0, dstLen = 0;
				            srcLen = strlen(info->header->header.g_header->to->current.address);
				            dstLen = (MMA_MAX_ADDR_LEN - 1) * sizeof(kal_wchar);
				            data->address_type = translate_mms_address_type_to_mma(info->header->header.g_header->to->current.addrType);
				            msf_charset_utf8_to_ucs2le(info->header->header.g_header->to->current.address, 
										             &srcLen,
										             (char*)data->address, 
										             &dstLen);
			            }
                        else if (info->header->header.g_header->cc != NULL  &&
                            info->header->header.g_header->cc->current.addrType != MMS_UNSUPPORTED)
			            {
				            long srcLen = 0, dstLen = 0;
				            srcLen = strlen(info->header->header.g_header->cc->current.address);
				            dstLen = (MMA_MAX_ADDR_LEN - 1) * sizeof(kal_wchar);
				            data->address_type = translate_mms_address_type_to_mma(info->header->header.g_header->cc->current.addrType);
				            msf_charset_utf8_to_ucs2le(info->header->header.g_header->cc->current.address, 
										             &srcLen,
										             (char*)data->address, 
										             &dstLen);
			            }
                        else if (info->header->header.g_header->bcc != NULL  &&
                            info->header->header.g_header->bcc->current.addrType != MMS_UNSUPPORTED)
			            {
				            long srcLen = 0, dstLen = 0;
				            srcLen = strlen(info->header->header.g_header->bcc->current.address);
				            dstLen = (MMA_MAX_ADDR_LEN - 1) * sizeof(kal_wchar);
				            data->address_type = translate_mms_address_type_to_mma(info->header->header.g_header->bcc->current.addrType);
				            msf_charset_utf8_to_ucs2le(info->header->header.g_header->bcc->current.address, 
										             &srcLen,
										             (char*)data->address, 
										             &dstLen);
			            }
                    }


                    /* Subject */
                    if (info->header->header.g_header->subject.text != NULL)
                    {
                        long srcLen = 0, dstLen = 0;
				        srcLen = strlen(info->header->header.g_header->subject.text);
				        dstLen = (MMS_MAX_SUBJECT_LEN - 1) * sizeof(kal_wchar);
				        msf_charset_utf8_to_ucs2le(info->header->header.g_header->subject.text, 
										         &srcLen,
										         (char*)data->subject, 
										         &dstLen);
                    }
                }

            
			    property->user_elements_size = info->user_elements_size;
                property->msg_class = translate_mms_class_to_mma(info->header->header.g_header->msgClass.classIdentifier);
                property->priority = translate_mms_priority_to_mma(info->header->header.g_header->priority);
                property->compose_date = info->header->header.g_header->date;
                property->expiry_date = info->header->header.g_header->expiryTime;
            #ifdef __MMI_MMS_POSTCARD__
                if (info->msg_type != MMA_MSG_TYPE_POSTCARD)
            #endif
                {
                    if(info->header->header.g_header->readReply == MMS_READ_REPLY_YES)
                    {
                        property->need_read_report = KAL_TRUE;
                    }
       
                    if(info->header->header.g_header->deliveryReport == MMS_DELIVERY_REPORT_YES)
                    {
                        property->need_delivery_report = KAL_TRUE;
                    }
                }
        
                property->has_attachment = (info->mms_dsr->body->attachment != NULL);
                property->is_forward_lock = info->header->header.g_header->forwardLock;
                property->is_drm = mma_is_drm_message(info->mms_dsr->body);
                property->msg_media_type = mma_get_message_media_type(info->mms_dsr->body);
                break;

            case MMS_SUFFIX_IMMEDIATE:
            case MMS_SUFFIX_NOTIFICATION:

				if (info->header->header.notif->from.address != NULL &&                   
                    info->header->header.notif->from.addrType != MMS_UNSUPPORTED)
				{
					long srcLen = 0, dstLen = 0;
					srcLen = strlen(info->header->header.notif->from.address);
					dstLen = (MMA_MAX_ADDR_LEN - 1) * sizeof(kal_wchar);
					data->from_address_type = translate_mms_address_type_to_mma(info->header->header.notif->from.addrType);
					msf_charset_utf8_to_ucs2le(info->header->header.notif->from.address, 
											 &srcLen,
											 (char *)data->from_address, 
											 &dstLen);
				}
                property->msg_class = translate_mms_class_to_mma(info->header->header.notif->msgClass.classIdentifier);
                property->priority = translate_mms_priority_to_mma(info->header->header.notif->priority);
                property->expiry_date = info->header->header.notif->expiryTime;
                break;
        }

        if (data->java_app_id != NULL && *data->java_app_id != '\0')
        {
            property->msg_type = MMA_MSG_TYPE_JAVA;
        }
        else if(info->msg_type == MMA_MSG_TYPE_POSTCARD)
        {
            property->msg_type = MMA_MSG_TYPE_POSTCARD;
		}
        else
        {
            property->msg_type = (MSF_UINT8) translate_mms_msg_type_to_mma(info->suffix);
        }
        


        /* HS 3.1 Macro*/
#if (defined (__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
        if ((info->header->header.g_header->subject.text == NULL) && 
            (property->msg_type != MMA_MSG_TYPE_JAVA  && property->msg_type != MMA_MSG_TYPE_POSTCARD)&& 
            (info->suffix == MMS_SUFFIX_MSG))
        {
            if (info->text_obj != NULL)
            {
                int fh = 0;
                
                if ((fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, info->text_obj->file_path, MSF_FILE_SET_RDONLY, 0, info->storage_type)) >= 0)
			    {
				    if (MSF_FILE_SEEK(fh, info->text_obj->offset, MSF_FILE_SEEK_SET) == info->text_obj->offset)
				    {
					    kal_int32 bytes_read = 0;
                        if (info->text_obj->size < MMA_MAX_SUBJECT_LEN)
                        {
                            bytes_read = info->text_obj->size;
                        }
                        else
                        {
                            bytes_read = MMA_MAX_SUBJECT_LEN - 1;
                        }
					    bytes_read = MSF_FILE_READ(fh, data->java_app_id, bytes_read);
				    }
                }
                MSF_FILE_CLOSE(fh);
            }  
        }
        if(info->mms_dsr->body->objects != NULL)
        {
            mma_mms_object_struct *curr_obj = info->mms_dsr->body->objects;
            property->object_count = 0;
            
            while (curr_obj)
            {
                property->object_count++;
                curr_obj = curr_obj->next;
            }
        }
#endif /* (__MMI_OP11_HOMESCREEN_0301__) || (__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __MMI_MMS_POSTCARD__
        if (info->msg_type == MMA_MSG_TYPE_POSTCARD && info->text_obj != NULL)
        {
            mma_mms_object_struct *object = info->text_obj;
            if (object->is_virtual_file)
		    {
			
			    char *filepath = NULL;
			    char *virtuelFileName = NULL;
			    MSF_INT32 file_handle = 0;
			    long fs_result = 0;
         
			    filepath = (char*)MMAlib_getMessagePath(mma_parse_mod_id, info->msg_id);
			    if ((file_handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, 
										    filepath, MSF_FILE_SET_RDONLY, 0, info->storage_type)) >= 0)
			    {
				    virtuelFileName = MMA_CALLOC(MMA_MAX_VIRTUAL_FILE_PATH_SIZE);
				    ASSERT(virtuelFileName != NULL);
				    if ((fs_result = MSF_FILE_GEN_VIRTUAL_FILENAME(MSF_MODID_MMA, file_handle, virtuelFileName, 
							    MMA_MAX_VIRTUAL_FILE_PATH_SIZE, object->offset, object->size)) == MSF_FILE_OK)
				    {   
					    kal_uint8 *externalFilePath = NULL;
					    srv_postcard_recipient_struct *recipients = NULL;
					    kal_char *greeting_text = NULL;						
					    applib_oppostcard_mem_func_struct postcard_mem_func = {0};
					    postcard_mem_func.alloc_fn = mma_mem_alloc_ext;
					    postcard_mem_func.free_fn = mma_mem_free_ext;

					    externalFilePath = (kal_uint8*) MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, virtuelFileName, (kal_uint8)translate_mma_storage_to_mms_storage_enum(info->storage_type));
       				    
					    if (applib_oppostcard_decode_text_content(&postcard_mem_func , (const kal_wchar*)externalFilePath, 
									    &greeting_text, (void**)&recipients) == TRUE )
					    {													
						    //Convert to utf8 from ucs2 before passing to msg_mgr
						    kal_int32 greeting_text_len = 0;
						    kal_int32 recipient_name_len = 0;
						    kal_char *utf8_text = NULL;
						    kal_char *utf8_name = NULL;
                            kal_int32 utf8_len = 0;
						    kal_uint8 dstLen = 0;
						    if(greeting_text != NULL)
						    {
                                utf8_len = mma_unicode_to_utf8_len((kal_wchar*)greeting_text);
                                utf8_text = MMA_CALLOC(utf8_len + 1);
							    ASSERT(utf8_text != NULL);

							    greeting_text_len = chset_convert(CHSET_UCS2, CHSET_UTF8, greeting_text, utf8_text, utf8_len);
#if (defined (__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
                                strcpy((char*)data->java_app_id, utf8_text);
#endif

                    
                                dstLen = (MMS_MAX_SUBJECT_LEN - 1) * sizeof(kal_wchar);

								app_ucs2_strncpy((kal_int8*)data->subject,
												(const kal_int8*)greeting_text,
												dstLen);


                                MMA_FREE(utf8_text);

                            }
						    

						    if(recipients != NULL)
						    {                                                                                         
                                dstLen = (MMA_MAX_ADDR_LEN - 1) * sizeof(kal_wchar);

                                data->address_type = MMA_ADDR_TYPE_PHONE_NUMBER; /*MSG_MNGR is passing the recipient for postcard as PHONE_NUMBER*/


								app_ucs2_strncpy((kal_int8*)data->address,
												(const kal_int8*)recipients->address.postcard_name,
												dstLen);

                                mma_parse_update_address_objects_list(info, recipients);  
								
                            }						    
					    }                        
					    MMA_FREE(externalFilePath);
					    applib_oppostcard_free_memory(&postcard_mem_func, greeting_text, recipients);
               
				    }                            
				    MMA_FREE(virtuelFileName);
				    MSF_FILE_CLOSE(file_handle);
			    }
			    MMA_FREE(filepath);
		    }
		    else 
		    {
			    ASSERT(0);
		    }

        }
        else
#endif  /* __MMI_MMS_POSTCARD__*/
        if(info->suffix == MMS_SUFFIX_SEND_REQ || info->suffix == MMS_SUFFIX_MSG)
        {
            
            mma_parse_update_address_objects_list(info, NULL);
            
        }
		/* Storing first slide text object info for thumbnail*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
		if(info->thmubnail_txt_obj)
		{
			*((kal_uint32*)(data->app_data + MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_SIZE_POS * sizeof(MSF_UINT8))) = (kal_uint32)info->thmubnail_txt_obj->size;
			*((kal_uint32*)(data->app_data + MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_OFFSET_POS * sizeof(MSF_UINT8))) = (kal_uint32)info->thmubnail_txt_obj->offset;
			*((kal_uint16*)(data->app_data + MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_CHARSET_POS * sizeof(MSF_UINT8))) = (kal_uint16)info->thmubnail_txt_obj->charset;
			*((kal_uint8*)(data->app_data + MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_DRM_INFO_POS * sizeof(MSF_UINT8))) = ((kal_uint8)info->thmubnail_txt_obj->drm_process_type != MMA_DRM_NO_PROTECTION ? 1 : 0);
		}
 #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */   
		/* Storing first slide text object info for thumbnail*/
        rsp->large_data = data;
        rsp->property = property;
        MMA_SIGNAL_SENDTO_IUP(
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_PARSER_GET_BASIC_MSG_INFO_REPLY,
            ret,
            info->msg_id,
            rsp);
    }
    else
    {
        MMA_SIGNAL_SENDTO_IUP(
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_PARSER_GET_BASIC_MSG_INFO_REPLY,
            ret,
            info->msg_id,
            NULL);
    }
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_SEND_PARSER_GET_BASIC_MSG_INFO_REPLY_RSP,
                      "(mma_parse.c) mma_parse_send_int_rsp: ret %d, msg %d\n", ret, info->msg_id));
}

#ifndef __MMI_MMS_USE_ASM__
/*****************************************************************************
 * FUNCTION
 *  mma_parse_send_rsp
 * DESCRIPTION
 *  wap_send_mms_mma_get_content_rsp wrapper for successful response with XML content
 * PARAMETERS
 *  req_id          [IN]        
 *  ret             [IN]        
 *  entry(?)        [IN]        
 * RETURNS
 *  TRUE: more XML content to be sent; FALSE: all XML content were read
 *****************************************************************************/
static kal_bool mma_parse_send_rsp(MSF_UINT32 req_id, mma_result_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *req = NULL;
    mma_parse_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((req = mma_parse_get_task_by_req(req_id)) != NULL);
    ASSERT((info = (mma_parse_info_struct*) req->data) != NULL);
    if (info->mode == MMA_MODE_INT_PARSE)
    {
        mma_parse_send_int_rsp(req_id, ret);
        return KAL_FALSE;
    }
    else
    {
        return mma_parse_send_ext_rsp(req_id, ret);
		  
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mma_parse_send_direct_rsp
 * DESCRIPTION
 *  wap_send_mms_mma_parse_rsp wrapper for response
 * PARAMETERS
 *  source              [IN]        
 *  req_id              [IN]        
 *  app_id              [IN]        
 *  msg_id              [IN]        
 *  mode                [IN]        
 *  buffer_index        [IN]        
 *  ret                 [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_parse_send_direct_rsp(
                MSF_UINT32 source,
                MSF_UINT32 req_id,
                MSF_UINT8 app_id,
                MSF_UINT32 msg_id,
                mma_app_mode_enum mode,
               /* MSF_UINT32 buffer_index,*/
                mma_result_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_SEND_DIRECT_RSP,
                      "(mma_parse.c): mma_parse_send_reject_rsp: req = %d, ret=%d\n", req_id, ret));
    if (mode == MMA_MODE_INT_PARSE)
    {
        MMA_SIGNAL_SENDTO_IUP(
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_PARSER_GET_BASIC_MSG_INFO_REPLY,
            ret,
            msg_id,
            NULL);
    }
    else
    {
        wap_mma_get_content_rsp_struct *rsp = NULL;

        rsp = (wap_mma_get_content_rsp_struct*) MMA_CALLOC(sizeof(wap_mma_get_content_rsp_struct));
        rsp->app_id = app_id;
        rsp->req_id = req_id;
        rsp->result = ret;
        rsp->msg_id = msg_id;
       /* rsp->buffer_index = buffer_index;*/
        //rsp->more = FALSE;
    #ifdef __MMI_MMS_MMA_DRM_ENCODING__
        mma_msgmgr_reset_parsing_status(msg_id);
    #endif
        mms_mma_send_get_content_rsp((module_type)source, rsp, NULL);
        MMA_FREE(rsp);
    }
}



#ifdef __MMI_MMS_USE_ASM__
/* this should be defined in some .h file*/
extern void set_mms_asm_mem(void *mem, MSF_UINT32 size);
#endif

/*****************************************************************************
 * FUNCTION
 *  mma_parse_fsm
 * DESCRIPTION
 *  Get mms content by specified information
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mma_parse_action_enum mma_parse_fsm(mma_parse_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_parse_action_enum action = MMA_PARSE_ACTION_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(info != NULL);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_FSM_DETAIL,
                      "(mma_parse.c) State:%d: req = %d, msg = %d, input = %d\n", info->state, info->req_id,
                      info->msg_id, info->input));

    if (info->input != MMA_RESULT_OK && info->state != MMA_PARSE_STATE_FINISHED)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_CHANGE_STATE_TO_FINISHING,
                           "(mma_parse.c) state -> MMA_PARSE_STATE_FINISHING\n"));
        info->state = MMA_PARSE_STATE_FINISHING;
    }

    mma_check_and_sleep();

    switch (info->state)
    {
        case MMA_PARSE_STATE_STARTED:
        {
            /*Safe Check only*/
            if (!mma_main_is_storage_type_present((mma_msg_storage_type_enum)info->storage_type))
            {
                info->input = MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT;
                info->state = MMA_PARSE_STATE_FINISHING;
                action = MMA_PARSE_ACTION_CONTINUE;

            }
#ifdef __MMI_MMS_USE_ASM__
            else if (info->mode == MMA_MODE_VIEW || info->mode == MMA_MODE_EDIT/*|| info->mode == MMA_MODE_HEADER || info->mode == MMA_MODE_SEND*/)
            {
                MMAif_getAsmMemory(info->req_id);
                info->state = MMA_PARSE_STATE_ASM_MEM_REQUEST;
                action = MMA_PARSE_ACTION_DELAYED;
                
            }
#endif /*__MMI_MMS_USE_ASM__*/
            else
            {
                action = MMA_PARSE_ACTION_CONTINUE;
                info->state = MMA_PARSE_STATE_PREPARE_SMIL_PRSE_INFO;
            }
            break;
        }
#ifdef __MMI_MMS_USE_ASM__            
        case MMA_PARSE_STATE_ASM_MEM_REQUEST:
        {
            
            //set_mms_asm_mem (asm_mem, 100 * 1024);
            //mma_parse_mod_id = MSF_UINT8_SET_MSB(MSF_MODID_MMA);
			mma_parse_mod_id = MSF_MODID_ASM;
            info->state = MMA_PARSE_STATE_PREPARE_SMIL_PRSE_INFO;
        }
#endif /* __MMI_MMS_USE_ASM__*/
            /* fall through */
        case MMA_PARSE_STATE_PREPARE_SMIL_PRSE_INFO:
        {
            info->suffix = 	(MmsFileType) mma_msgmgr_get_msg_suffix(info->msg_id);
			if((info->suffix == MMS_SUFFIX_TEMPLATE || info->suffix == MMS_SUFFIX_SEND_REQ || info->suffix == MMS_SUFFIX_MSG) && (info->mode != MMA_MODE_REPLY && info->mode != MMA_MODE_REPLY_ALL && info->mode != MMA_MODE_HEADER) )
			{
			  memset(&info->ctx, 0, sizeof(InstanceData));
			  info->ctx.parList=MMA_CALLOC(sizeof(SmilPar)*MAX_NO_OF_SLIDES);
		      info->ctx.elementStack=MMA_CALLOC(sizeof(int)*MAX_ELEM_DEPTH);
			  memset(info->ctx.parList, 0, sizeof(SmilPar)*MAX_NO_OF_SLIDES);
		      memset(info->ctx.elementStack, 0, sizeof(int)*MAX_ELEM_DEPTH);
			  info->ctx.memId = mma_parse_mod_id;
			}
              info->state = MMA_PARSE_STATE_MMS_INFO_GETTING;
        }
			 /* fall through */
        case MMA_PARSE_STATE_MMS_INFO_GETTING:
        {
			info->msg_type  = mma_msgmgr_parse_mode_msg_type(info->mode, info->msg_id);
			/* why to use the MMAif_getMessageInfo API. Only need the following information */
            info->input = MMA_RESULT_OK;
        //    info->suffix = 	mma_msgmgr_get_msg_suffix(info->msg_id);
            switch (info->suffix)
            {
                case MMS_SUFFIX_IMMEDIATE:
                case MMS_SUFFIX_NOTIFICATION:
                case MMS_SUFFIX_READREPORT:
                case MMS_SUFFIX_DELIVERYREPORT:
                    {
                        char *msg_file_path = NULL;
                        kal_int32 temp_header_size = 0;
                        msg_file_path = MMAlib_getMessagePath(mma_parse_mod_id, info->msg_id);
                        ASSERT(msg_file_path);
                        if ((temp_header_size = MSF_FILE_GETSIZE_EXT(msg_file_path, (msf_mms_storage_enum)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type))) <= 0)
                        {
                            MMA_PARSE_FREE(msg_file_path);
                            info->input = MMA_RESULT_FAIL_FILE_EMPTY;
                        }
                        else
                        {
                            info->header_size = temp_header_size;
                        }
                        MMA_PARSE_FREE(msg_file_path);
                    }
                    info->body_size = 0;
                    break;
                  default:
                      break;
            }
            info->state = MMA_PARSE_STATE_MMS_OPENING;
            action = MMA_PARSE_ACTION_CONTINUE;
            break;
        }

        case MMA_PARSE_STATE_MMS_OPENING:
        {
            if (info->suffix != MMS_SUFFIX_READREPORT && info->suffix != MMS_SUFFIX_DELIVERYREPORT)
            {
                if ((info->input = translate_mms_result_to_mma(MMSlib_transactionOpen(mma_parse_mod_id, &info->t_handle))) != MMS_RESULT_OK)
                {
                    info->input = translate_mms_result_to_mma((MmsResult)info->input);
                    info->state = MMA_PARSE_STATE_FINISHING;
                }
                else if ((info->input = translate_mms_result_to_mma( MMSlib_messageOpen(mma_parse_mod_id, 
                                                           MMA_TRANSLATE_MSG_ID(info->msg_id),
                                                           info->suffix,
                                                           &info->m_handle, 
                                                           (kal_uint8)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type)))) != MMS_RESULT_OK)
                {
                    (void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
					info->input = translate_mms_result_to_mma((MmsResult)info->input);
                    info->state = MMA_PARSE_STATE_FINISHING;
                }
                else if (info->header == NULL)
                {
                    info->state = MMA_PARSE_STATE_MMS_HEADER_PARSING;
                }
            }
            else
            {
                info->state = MMA_PARSE_STATE_MMS_HEADER_PARSING;
            }
            info->sub_state = 0;
            action = MMA_PARSE_ACTION_CONTINUE;
            break;
        }
        case MMA_PARSE_STATE_MMS_HEADER_PARSING:
        {
            switch (info->sub_state)    /* Here, sub_state is used to handle delayed file I/O */
            {
                case 0:
                {
                    ASSERT(info->header == NULL);
                    info->header = (mma_header_struct*) MMA_PARSE_CALLOC(sizeof(mma_header_struct));
                    info->sub_state = 1;
                    switch (info->suffix)
                    {
                        case MMS_SUFFIX_TEMPLATE:
                        case MMS_SUFFIX_SEND_REQ:
                        case MMS_SUFFIX_MSG:
                        {
                            info->header->header.g_header = (MmsGetHeader*) MMA_PARSE_CALLOC(sizeof(MmsGetHeader));
                            ASSERT(info->header->header.g_header != NULL);
                            break;
                        }

                        case MMS_SUFFIX_IMMEDIATE:
                        case MMS_SUFFIX_NOTIFICATION:
                        {
                            info->header->header.notif = (MmsNotification*) MMA_PARSE_CALLOC(sizeof(MmsNotification));
                            ASSERT(info->header->header.notif != NULL);
                            break;
                        }
                    }
                    action = MMA_PARSE_ACTION_CONTINUE;
                }
                case 1:
                {
                    switch (info->suffix)
                    {
                        case MMS_SUFFIX_TEMPLATE:
                        case MMS_SUFFIX_SEND_REQ:
                        case MMS_SUFFIX_MSG:
                        {
                            if ((info->input = translate_mms_result_to_mma(MMSlib_getMessageHeaderExt(mma_parse_mod_id,
                                                                        (MmsGetHeader*)info->header->header.g_header,
                                                                        &info->m_handle,
                                                                        &info->t_handle,
                                                                        MESSAGE_HEADERS))) == MMA_RESULT_DELAYED)
                            {
                                    MmsTransaction *t = (MmsTransaction*) info->t_handle;

                                    info->delayed_handle = t->fileHandle;
								    info->input = MMA_RESULT_OK;
                                    action = MMA_PARSE_ACTION_DELAYED;
                             }
                             else if (info->input != MMS_RESULT_OK)
                             {
                                 (void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
                                 (void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
						  	     info->input = translate_mms_result_to_mma((MmsResult)info->input);
                                 info->state = MMA_PARSE_STATE_FINISHING;
                                 action = MMA_PARSE_ACTION_CONTINUE;
                             }
                             else
                             {
                                 (void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
                                 (void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
                            
                                 if (info->mode == MMA_MODE_INT_PARSE)
                                 {
                                     // For internal parsing, we no need to write in XML 
                                      info->state = MMA_PARSE_STATE_MMS_BODY_HEADER_PARSING;
                                 }
                                 else
                                 {
                                      info->state = MMA_PARSE_STATE_APP_MMS_HEADER_CREATING;
                                 }

                                 /* Done the removal of unuseful addresses. */
                                 mma_update_address_list(mma_parse_mod_id, (MmsGetHeader*)info->header->header.g_header);

                                 if (info->header->header.g_header->subject.text != NULL)
                                 {
                                     mma_update_subject_text(mma_parse_mod_id, &info->header->header.g_header->subject);
                                 }
                                /* if (info->mode != MMA_MODE_HEADER && info->mode != MMA_MODE_VIEW &&
                                    info->mode != MMA_MODE_INT_PARSE)*/
                                {
                                    mma_remove_invalid_address(mma_parse_mod_id, info->header->header.g_header, info->mode) ;
                                }

                                MMA_SIGNAL_SENDTO_U(
                                    MMA_SUBMODULE_MSG_PARSE,
                                    MMA_INT_SIG_TYPE_MSG_PARSE_CONTINUE_IND,
                                    info->req_id);
								info->sub_state = 0;
                                action = MMA_PARSE_ACTION_DELAYED;
                            }
                            break;
                        }
                        case MMS_SUFFIX_IMMEDIATE:
                        case MMS_SUFFIX_NOTIFICATION:
                        {
                            if ((info->input = translate_mms_result_to_mma(MMSlib_getNotification(
                                                mma_parse_mod_id,
                                                info->header->header.notif,
                                                &info->m_handle,
                                                &info->t_handle))) == MMA_RESULT_DELAYED)
                            {
                                MmsTransaction *t = (MmsTransaction*) info->t_handle;

                                info->delayed_handle = t->fileHandle;
								info->input = MMA_RESULT_OK;
                                action = MMA_PARSE_ACTION_DELAYED;
                            }
                            else if (info->input != MMS_RESULT_OK)
                            {
                                (void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
                                (void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
								info->input = translate_mms_result_to_mma((MmsResult)info->input);
                                info->state = MMA_PARSE_STATE_FINISHING;
                                action = MMA_PARSE_ACTION_CONTINUE;
                            }
                            else
                            {
                                info->state = MMA_PARSE_STATE_APP_MMS_HEADER_CREATING;
                                (void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
                                (void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
								info->input = translate_mms_result_to_mma((MmsResult)info->input);
                                MMA_SIGNAL_SENDTO_U(
                                    MMA_SUBMODULE_MSG_PARSE,
                                    MMA_INT_SIG_TYPE_MSG_PARSE_CONTINUE_IND,
                                    info->req_id);
								info->sub_state = 0;
                                action = MMA_PARSE_ACTION_DELAYED;
                            }
                            break;
                        }
                        case MMS_SUFFIX_READREPORT:
                        case MMS_SUFFIX_DELIVERYREPORT:
                        {
							ASSERT(0);
                        }
                    }
                }
            }
            break;
        }

        case MMA_PARSE_STATE_MMS_BODY_HEADER_PARSING:
        {
            switch (info->sub_state)    /* Here, sub_state is used to handle delayed file I/O */
            {
                case 0:
                {
                    ASSERT(info->body_header == NULL);

                    if ((info->input = translate_mms_result_to_mma(MMSlib_transactionOpen(mma_parse_mod_id, &info->t_handle))) != MMS_RESULT_OK)
                    {
						info->input = translate_mms_result_to_mma((MmsResult)info->input);
                        info->state = MMA_PARSE_STATE_FINISHING;
                        action = MMA_PARSE_ACTION_CONTINUE;
                        break;
                    }
                    else if ((info->input = translate_mms_result_to_mma(MMSlib_messageOpen(mma_parse_mod_id,
                                                               MMA_TRANSLATE_MSG_ID(info->msg_id),
                                                               info->suffix,
                                                               &info->m_handle,
                                                               (kal_uint8)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type)))) != MMS_RESULT_OK)
                    {
                        (void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
						info->input = translate_mms_result_to_mma((MmsResult)info->input);
                        info->state = MMA_PARSE_STATE_FINISHING;
                        action = MMA_PARSE_ACTION_CONTINUE;
                        break;
                    }
                    else
                    {
						info->input = translate_mms_result_to_mma((MmsResult)info->input);
                        info->sub_state = 1;
                        info->delayed_handle = -1;
                    }
                    action = MMA_PARSE_ACTION_CONTINUE;
                }
                case 1:
                {
                    if ((info->input = translate_mms_result_to_mma(MMSlib_getMessageHeaderExt(
                                        mma_parse_mod_id,
                                        (MmsGetHeader*)info->header->header.g_header,
                                        &info->m_handle,
                                        &info->t_handle,
                                        BODY_HEADERS))) == MMA_RESULT_DELAYED)
                    {
                        MmsTransaction *t = (MmsTransaction*) info->t_handle;

                        info->delayed_handle = t->fileHandle;
						info->input = MMA_RESULT_OK;
                        action = MMA_PARSE_ACTION_DELAYED;
                    }
                    else if (info->input != MMS_RESULT_OK)
                    {
                        (void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
                        (void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
						info->input = translate_mms_result_to_mma((MmsResult)info->input);
                        info->state = MMA_PARSE_STATE_FINISHING;
                        action = MMA_PARSE_ACTION_CONTINUE;
                    }
                    else
                    {
						info->input = translate_mms_result_to_mma((MmsResult)info->input);
                        info->body_header = (MmsBodyInfoList*)&(info->header->header.g_header->bodyInfoList);
                        info->user_elements_size = mma_get_user_element_size(info->header, info->body_header);
                        //(void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
                        (void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
                        info->state = MMA_PARSE_STATE_MMS_BODY_HEADER_PARSED;
                        info->sub_state = 0;
                        action = MMA_PARSE_ACTION_CONTINUE;
                    }
                    break;
                }
            }
            break;
        }

        case MMA_PARSE_STATE_MMS_BODY_HEADER_PARSED:
        {
            info->body_size = info->body_header->size;
            info->header_size = info->body_header->startPos;
            info->header->multipart_type = mma_get_multipart_type(info->body_header);
            info->header->body_no = info->body_header->numOfEntries;
			info->content_type = (MmsContentType*) MMA_PARSE_CALLOC(sizeof(MmsContentType));
			copyContentType(mma_parse_mod_id, info->content_type, info->header->header.g_header->bodyInfoList.contentType);
            if (info->mode == MMA_MODE_REPLY || info->mode == MMA_MODE_REPLY_ALL)
            {
                info->input = MMA_RESULT_OK;
                info->state = MMA_PARSE_STATE_FINISHING;
                info->sub_state = 0;
                action = MMA_PARSE_ACTION_CONTINUE;
                if (info->body_header != NULL)
                {
                    info->body_header = NULL;
                }
            }
            else
            {
                ASSERT(info->mms_dsr->body == NULL);
                info->mms_dsr->body = (mma_mms_description_body_struct*) MMA_PARSE_CALLOC(sizeof(mma_mms_description_body_struct));
				info->mms_dsr->body->text_fit = MMA_REGION_FIT_SCROLL;
				info->mms_dsr->body->image_fit = MMA_REGION_FIT_MEET;
				info->mms_dsr->body->obj_no = 0;/*info->body_header->numOfEntries : body header entries differ the actual no of objects*/
                info->root_layout.bgColor = SLS_COLOR_NOT_USED;
                ASSERT(info->mms_dsr->body != NULL);
                info->curr = info->body_header;

                info->input = MMA_RESULT_OK;
                info->state = MMA_PARSE_STATE_MMS_BODY_HEADER_PROCESSING_LOOP;
                action = MMA_PARSE_ACTION_CONTINUE;
            }
            break;
        }

        case MMA_PARSE_STATE_MMS_BODY_HEADER_PROCESSING_LOOP:
        {
            /* process multipart entry ; may re-enter... */
				static char *param = NULL;
			static int smil_count =0, no = 0, size = 0; 
            if (info->curr)
            {
                const char *mime = mma_get_mime_type_from_mmsContentType(info->curr->contentType);
                const char *multipart_prefix = "application/vnd.wap.multipart.";
                int len = strlen(multipart_prefix);
				MmsBodyInfoList *temp_node = info->curr->next;

                /* Do not handle SMIL and nodes which has sub-nodes in order to make a simple list */
                if ( mime != NULL && info->curr->numOfEntries == 0 && msf_cmmn_strncmp_nc(mime, multipart_prefix, len) != 0 &&
                    info->curr->size > 0 &&
                    (msf_cmmn_strcmp_nc(mime, MMS_MEDIA_TYPE_STRING_SMIL) != 0 || info->mode == MMA_MODE_RAW))
                {                    
					if (info->mms_dsr->body->objects == NULL)
                    {
                        info->mms_dsr->body->objects = mma_create_object_from_mo(mma_parse_mod_id, info->mode, info->msg_id, info->suffix, info->curr);
                        info->mms_dsr->body->curr_object = info->mms_dsr->body->objects;
                    }
                    else
                    {
                        info->mms_dsr->body->curr_object->next = mma_create_object_from_mo(mma_parse_mod_id, info->mode, info->msg_id, info->suffix, info->curr);
						info->mms_dsr->body->curr_object->next->prev = info->mms_dsr->body->curr_object;
                        info->mms_dsr->body->curr_object = info->mms_dsr->body->curr_object->next;
                    }
					info->mms_dsr->body->obj_no++;
/* for postcard */
#ifdef __MMI_MMS_POSTCARD__
					if(info->mode == MMA_MODE_INT_PARSE && info->msg_type == MMA_MSG_TYPE_POSTCARD &&
					   mma_get_mime_group_from_mime_type(info->mms_dsr->body->curr_object->mime_str) == MIME_TYPE_TEXT)
					{
						//Only Text object content is to be parsed during internal parsing						
                        info->text_obj = info->mms_dsr->body->curr_object;                      
					}
#endif 
/* for postcard */					

                    /* MMS service doesn't return correct info */
                    if (info->header->header.g_header->forwardLock == FALSE &&
                        info->mms_dsr->body->curr_object->drm_process_type == MMA_DRM_PROCESS_FORWARD_LOCK_CD)
                    {
                        info->header->header.g_header->forwardLock = TRUE;
                    }
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
                    if (info->mode == MMA_MODE_INT_PARSE)
                    {
                        char *filepath = NULL;
                        char *vFileName = NULL;
                        MSF_INT32 handle = 0;
                        mma_drm_method_enum drm_method;
    
                        filepath = (char*)MMAlib_getMessagePath(mma_parse_mod_id, info->msg_id);
                        if ((handle = mma_msf_file_open_in_blocking_mode(mma_parse_mod_id, filepath, MSF_FILE_SET_RDONLY, 0, info->storage_type)) >= 0)
                        {
                            vFileName = MMA_PARSE_CALLOC(MMA_MAX_VIRTUAL_FILE_PATH_SIZE);
                            ASSERT(vFileName != NULL);
                            if (MSF_FILE_GEN_VIRTUAL_FILENAME(mma_parse_mod_id, handle, vFileName, MMA_MAX_VIRTUAL_FILE_PATH_SIZE, info->curr->startPos, info->curr->size) == MSF_FILE_OK)
                            {                            
                                drm_method = mma_drm_get_method_type(-1, vFileName, (kal_uint8)translate_mma_storage_to_mms_storage_enum(info->storage_type));
                                if (drm_method == MMA_DRM_METHOD_FORWARD_LOCK ||
                                    drm_method == MMA_DRM_METHOD_COMBINED_DELIVERY)
                                {
                                    info->header->header.g_header->forwardLock = TRUE;
                                }
                            }                            
                            MMA_PARSE_FREE(vFileName);
                            MSF_FILE_CLOSE(handle);
                        }
                        MMA_PARSE_FREE(filepath);
                    }
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
                }
				else
				{
					if (msf_cmmn_strncmp_nc(mime, multipart_prefix, len) == 0)
					{	
						MmsAllParams  *params = info->curr->contentType->params;

						while(params)
						{		
							if(params->param == MMS_START_REL)
							{
								param = msf_cmmn_strdup(mma_parse_mod_id, (const char*)params->value.string);
							}
							params = params->next;
						}
					}
					else if (msf_cmmn_strcmp_nc(mime, MMS_MEDIA_TYPE_STRING_SMIL) == 0 && mma_is_presentation_part(param, info->curr->entryHeader))
					{
						 info->ctx.smilBodyPartNumber = (int)info->curr->number;
                         info->ctx.smilSize = info->curr->size;	
						 smil_count++;
						 if(smil_count == 1)
						 {
							no = (int)info->curr->number;
							size = 	info->curr->size;	
						 }
						 						 
					}
					else
					{
						smil_count++;
						
						 if(smil_count == 1)
						 {
							no = (int)info->curr->number;
							size = 	info->curr->size;	
						 }
						
					}
					
					
					
				}
				if(info->curr->number !=0 && msf_cmmn_strncmp_nc(mime, multipart_prefix, len) != 0)
				{
					/* To free Top Node except the MMS Header. */
					MMSlib_freeMmsBodyInfoNode(mma_parse_mod_id, (MmsGetHeader*)info->header->header.g_header);
				}
				info->curr = temp_node;
#ifdef __MMI_VCARD__
                if (info->mode == MMA_MODE_INT_PARSE && info->mms_dsr->body->curr_object != NULL && strstr(mma_get_mms_vcard_type(), info->mms_dsr->body->curr_object->mime_str))
                {
                   	char *filepath = NULL;                         
					filepath = (char*)MMAlib_getMessagePath(mma_parse_mod_id, info->msg_id);
                    MMAif_isvcardrestricted(filepath, info->mms_dsr->body->curr_object->size, info->mms_dsr->body->curr_object->offset, (kal_uint8)translate_mma_storage_to_mms_storage_enum(info->storage_type));

                    action = MMA_PARSE_ACTION_DELAYED;
                    MMA_PARSE_FREE(filepath);
                    break;
                }
#endif // __MMI_VCARD__
				if(temp_node != NULL)
                {
                    MMA_SIGNAL_SENDTO_U(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_PARSE_CONTINUE_IND, info->req_id);
                    info->input = MMA_RESULT_OK;
                    action = MMA_PARSE_ACTION_DELAYED;
                    break;
                }
            }

            /* finish all multipart processing */
			if (!info->ctx.smilBodyPartNumber)
			{
					
					if(smil_count == 1 && size <= SLS_MAX_SMIL_BUFFER_SIZE)
					{
					
					info->ctx.smilBodyPartNumber = no;
		            info->ctx.smilSize = size;	

					}

					else
					{					
				
					info->header->multipart_type = MMA_MULTIPART_MIXED;
					(void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);	
			      
					}

		 }
		else if(info->ctx.smilSize > SLS_MAX_SMIL_BUFFER_SIZE)
		{
				info->header->multipart_type = MMA_MULTIPART_MIXED;
				(void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);	
		}

			MSF_MEM_FREE(mma_parse_mod_id, param);
			param = NULL;
			no = 0;
			size = 0;
			smil_count = 0;
            /*HS 3.1 Macro*/
            if (info->mode == MMA_MODE_RAW)
            {
                info->input = MMA_RESULT_OK;
                info->state = MMA_PARSE_STATE_FINISHING;
                info->sub_state = 0;
                action = MMA_PARSE_ACTION_CONTINUE;
            }
            else if (info->header->multipart_type == MMA_UNSUPPORTED)
            {
                MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_MULTIPART_TYPE_IS_UNSUPPORTED,
                                   "(mma_parse.c) multipart_type == MMA_UNSUPPORTED\n"));
                info->input = MMA_RESULT_FAIL_UNSUPPORT_CONTENT;
                info->state = MMA_PARSE_STATE_FINISHING;
                action = MMA_PARSE_ACTION_CONTINUE;
            }
            else if (info->header->multipart_type == MMA_PLAIN_TEXT || info->header->multipart_type == MMA_MULTIPART_MIXED)     /* Mixed MMS */
            {
                if (info->mode == MMA_MODE_FORWARD || info->mode == MMA_MODE_SEND)
                {
                    info->state =	MMA_PARSE_STATE_FINISHING;
                    info->sub_state = 0;
                }
                else
                {
                    info->state = MMA_PARSE_STATE_SMIL_ADDING;
                }
                info->input = MMA_RESULT_OK;
                action = MMA_PARSE_ACTION_CONTINUE;
            }
            else    /* SMIL MMS */
            {

                info->input = MMA_RESULT_OK;
                info->state = MMA_PARSE_STATE_SMIL_PARSING;
                action = MMA_PARSE_ACTION_CONTINUE;
            }

            if (info->body_header != NULL)
            {
				MMSlib_freeMmsBodyInfoList(mma_parse_mod_id, (MmsGetHeader*)info->header->header.g_header);
                info->body_header = NULL;
            }
            break;
        }


		 case MMA_PARSE_STATE_SMIL_PARSING:
			{
			 switch (info->sub_state)    /* Here, sub_state is used to handle delayed file I/O */
			{
                case 0:
                {			 
					if ((info->input = translate_mms_result_to_mma(MMSlib_transactionOpen(mma_parse_mod_id, &info->t_handle))) != MMS_RESULT_OK)
					{
						info->input = translate_mms_result_to_mma((MmsResult)info->input);
						info->state = MMA_PARSE_STATE_FINISHING;
						(void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
						action = MMA_PARSE_ACTION_CONTINUE;
            break;
        }
					info->ctx.smilData = MSF_MEM_ALLOC(mma_parse_mod_id, info->ctx.smilSize + 1);
					ASSERT(info->ctx.smilData != NULL);
				    info->ctx.smilData[info->ctx.smilSize] = 0;
					info->input = translate_mms_result_to_mma((MmsResult)info->input);
                    info->sub_state = 1;			/*fall down get smil part from the PDU*/
                    info->delayed_handle = -1;
				}	

				case 1:		
        {
						if ((info->input = translate_mms_result_to_mma(MMSlib_getBodyPart(mma_parse_mod_id, 
											(MSF_UINT32)info->ctx.smilBodyPartNumber, 
											info->ctx.smilData, &info->ctx.smilSize, 
											&info->m_handle, 
											&info->t_handle))) == MMA_RESULT_DELAYED)
						{					
							MmsTransaction *t = (MmsTransaction*) info->t_handle;
							info->delayed_handle = t->fileHandle;
							info->input = MMA_RESULT_OK;
            action = MMA_PARSE_ACTION_DELAYED;
            break;
        }
						else if(info->input != MMS_RESULT_OK)
						{						
								(void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
								(void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);
								MMA_PARSE_FREE(info->ctx.smilData);
								info->input = translate_mms_result_to_mma((MmsResult)info->input);
								info->sub_state = 0;
								info->state = MMA_PARSE_STATE_SMIL_ADDING;					/* Smil reading error MMA will add smil from its own */
			                    info->header->multipart_type = MMA_MULTIPART_MIXED;
								action = MMA_PARSE_ACTION_CONTINUE;
						 break;						
						}

						else
        {
								(void)MMSlib_messageClose(mma_parse_mod_id, &info->m_handle);
								(void)MMSlib_transactionClose(mma_parse_mod_id, &info->t_handle);	
								info->sub_state = 2;		/* fall down parse smil */
							}
				 }
			 
			case 2:	
            {
				if (mma_parse_sml(&info->ctx) != MMA_RESULT_OK)
					{
						 //chetan ,put some logs here
						 info->state = MMA_PARSE_STATE_SMIL_ADDING;					/* error in smil parsing  MMA will add smil from its own */
						 info->header->multipart_type = MMA_MULTIPART_MIXED;
            }
            else
            {
																				
						  if ((info->mms_dsr->body->slide_no = mma_get_no_of_slides(info->ctx)) == 0 || info->mms_dsr->body->slide_no > MAX_NO_OF_SLIDES)
							{
								 info->header->multipart_type = MMA_MULTIPART_MIXED;
								 info->state = MMA_PARSE_STATE_SMIL_ADDING;	
								//chetan ,put some logs here
							}
						  else
						  {
						  info->state = MMA_PARSE_STATE_GENERATE_SLIDE_INFO;		/* Smil parsing done successfully : Now identify the attachments */
						  MMA_SIGNAL_SENDTO_U(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_PARSE_CONTINUE_IND, info->req_id);
						  info->input = MMA_RESULT_OK;
						  info->sub_state = 0;
                          action = MMA_PARSE_ACTION_DELAYED;
						  break;
						  }
					}
				info->sub_state = 0;
				action = MMA_PARSE_ACTION_CONTINUE;
		   }				
			 
            }
            break;
        }


		 case MMA_PARSE_STATE_GENERATE_SLIDE_INFO:
        {
                  
				 unsigned int i = 0;
				 SmilMediaObject *mediaObj;
				 mma_mms_slide_struct *slide = NULL;
				 mma_mms_slide_struct *dest = NULL;
			
				 /*Set default root layout back ground color*/
				 if (info->root_layout.bgColor == SLS_COLOR_NOT_USED)
            {
					    info->mms_dsr->body->bgColor = MMA_CFG_SMIL_BG_COLOR;
                        }
				 else 
                {
						info->mms_dsr->body->bgColor = info->root_layout.bgColor;
                }
                    

				 for (i = 0; i < info->mms_dsr->body->slide_no; i++)
                    {
						/*
						if(i >= MAX_NO_OF_SLIDES)
                        {
						//chetan ,put some logs here
						 info->header->multipart_type = MMA_MULTIPART_MIXED;
						 info->state = MMA_PARSE_STATE_SMIL_ADDING;	
    		 			 action = MMA_CREATE_ACTION_CONTINUE;
                            break;
                        }

							*/
					mma_mms_object_struct *obj = info->mms_dsr->body->objects;
					
					mediaObj = info->ctx.parList[i].mobj;
			
					slide = (mma_mms_slide_struct*) MSF_MEM_CALLOC(mma_parse_mod_id, 1, sizeof(mma_mms_slide_struct));

					slide->duration = info->ctx.parList[i].dur;
					slide->slide_num = (i+1);
					if(slide->duration > MMA_MAX_SLIDE_TIMING)
                        {
						  slide->duration = MMA_MAX_SLIDE_TIMING;
                        }                        

					while (mediaObj)
                {
						while(obj){


							if(mma_is_slide_object(mediaObj, obj))
									{
										mma_generate_slide_info(slide, mediaObj, obj, info->mms_dsr->body, &info->ctx);
                            break;
                    }
						

							obj = obj->next;
                }
							obj = info->mms_dsr->body->objects;
						mediaObj = mediaObj->next;
            }

					if(info->mms_dsr->body->slides == NULL)
            {
							dest = info->mms_dsr->body->slides = slide;		
						/*information of first slide for message manager*/
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
							if(info->mode == MMA_MODE_INT_PARSE)
                {
								if (slide->img.object)
                    {
									mma_parse_store_body_object_info(slide->img.object, info->msg_id, MMA_MEDIA_MSG_PHOTO);                            
            }
								else if (slide->vid.object)
                        {
									mma_parse_store_body_object_info(slide->vid.object, info->msg_id, MMA_MEDIA_MSG_VIDEO);
									
								}                    
								 if (slide->txt.object)
                        {
									info->thmubnail_txt_obj = slide->txt.object;								
									
								}

                        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#if defined (__MMI_OP11_HOMESCREEN_0301__) || defined (__MMI_OP11_HOMESCREEN_0302__)
						   if(info->msg_type != MMA_MSG_TYPE_POSTCARD) 
						   {
							if (slide->txt.object)
								{
									info->text_obj = slide->txt.object;								
                    }
                }
#endif

            }
            else
            {
							while(dest->next)
            {
									dest = dest->next;
            }
							dest->next = slide;
							dest->next->prev = dest;
							dest = dest->next;
							dest->next = NULL;
						}
					if (info->mms_dsr->body->layout == MMA_LAYOUT_NONE)
            {
							 info->mms_dsr->body->layout = mma_get_slide_layout(slide);
						}
            }

				 
				 info->state = MMA_PARSE_STATE_SETTLE_ATTACHMENT;		/* Smil parsing done successfully : Now identify the attachments */
				 MMA_SIGNAL_SENDTO_U(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_PARSE_CONTINUE_IND, info->req_id);
				 info->input = MMA_RESULT_OK;
                 action = MMA_PARSE_ACTION_DELAYED;	

				

            break;
        }


		 case MMA_PARSE_STATE_SETTLE_ATTACHMENT:
        {
           /*
			generating  attachment information

		   		   */
			mma_mms_object_struct *obj = info->mms_dsr->body->objects;
			info->ref_attach_count = 0;
			while(obj)
        {
						if(obj->is_attachment == KAL_TRUE)
        {
								mma_populate_unref_item_list(mma_parse_mod_id, info->mms_dsr->body, obj, info->mode, &info->ref_attach_count, &info->content_truncate_info);
							}
					   obj = obj->next;
				}      
            if (info->header->multipart_type == MMA_MULTIPART_MIXED && info->mms_dsr->body->slide_no != 0 && info->mms_dsr->body->slides)
            {
                if (info->mms_dsr->body->slides != NULL)
                {
                    mma_mms_free_slide_list(mma_parse_mod_id, &info->mms_dsr->body->slides);
                    info->mms_dsr->body->slides = NULL;
                    info->mms_dsr->body->curr_slide = NULL;
                    info->mms_dsr->body->slide_no = 0;
                }
                info->state = MMA_PARSE_STATE_SMIL_ADDING;                
            }
            else if (info->header->multipart_type == MMA_MULTIPART_MIXED || info->mms_dsr->body->slide_no == 0)
            {
                info->state = MMA_PARSE_STATE_SMIL_ADDING;
            }
            else
            {
                info->state = MMA_PARSE_STATE_FINISHING;
                info->sub_state = 0;
            }
			mma_parse_free_smil_ctx(&info->ctx);		
            info->input = MMA_RESULT_OK;
            action = MMA_PARSE_ACTION_CONTINUE;															/* every thing,slide and unref items are identified : Create XML */
			
            break;
        }


        case MMA_PARSE_STATE_SMIL_ADDING:
        {
            mma_parse_free_smil_ctx(&info->ctx);
          
		    if (info->mms_dsr->body->slide_no != 0 && info->mms_dsr->body->slides)
            {
                if (info->mms_dsr->body->slides != NULL)
                {
                    mma_mms_free_slide_list(mma_parse_mod_id, &info->mms_dsr->body->slides);
                    info->mms_dsr->body->slides = NULL;
                    info->mms_dsr->body->curr_slide = NULL;
                    info->mms_dsr->body->slide_no = 0;
                }
			}
			if(info->mms_dsr->body->attachment)
			{
				mma_mms_free_unref_list(mma_parse_mod_id, &info->mms_dsr->body->attachment);
			}


            ASSERT(info->header != NULL && info->header->header.g_header != NULL && info->mms_dsr->body != NULL);
			info->ref_attach_count = 0;
            info->mms_dsr->body->layout = MMA_LAYOUT_NONE;
            info->mms_dsr->body->attachment = NULL;
            info->root_layout.cx.value = 0;
            info->root_layout.cy.value = 0;

				/*assin body default BG color*/

			info->mms_dsr->body->bgColor = MMA_CFG_SMIL_BG_COLOR;


            if (info->mms_dsr->body->objects != NULL)
            {
                mma_mms_object_struct *obj = info->mms_dsr->body->objects;

                while (obj)
                {
                    mma_mms_slide_struct *slide = NULL;
                    applib_mime_type_enum app_lib_mime_type_value = MIME_TYPE_NONE;

                    if (obj->drm_process_type == MMA_DRM_NO_PROTECTION)
                    {
                        app_lib_mime_type_value = mma_get_mime_group_from_mime_type(obj->mime_str);
                    }
                    else
                    {
                    #ifdef __DRM_SUPPORT__
                        app_lib_mime_type_value = mma_get_mime_group_from_mime_type(obj->drm_mime_type);        /* check the real type of the DRM object */
                    #else 
                        app_lib_mime_type_value = MIME_TYPE_UNKNOWN;
                    #endif 
                    }

					/* HS 3.1 Macro*/
#if defined (__MMI_OP11_HOMESCREEN_0301__) || defined (__MMI_OP11_HOMESCREEN_0302__)
					/*first object on slide is text*/
					if (info->mms_dsr->body->slide_no == 0 && app_lib_mime_type_value == MIME_TYPE_TEXT)
					{
						info->text_obj = obj;
					}
#endif /* (__MMI_OP11_HOMESCREEN_0301__) || (__MMI_OP11_HOMESCREEN_0302__) */

                    /* Ashok: Add the code for the bodyobject */
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
                    if(info->mms_dsr->body->slide_no == 0 && info->mode == MMA_MODE_INT_PARSE)
                    {
                        if(app_lib_mime_type_value == MIME_TYPE_IMAGE)
                        {
                            mma_parse_store_body_object_info(obj, info->msg_id, MMA_MEDIA_MSG_PHOTO);
                        }
                        else if(app_lib_mime_type_value == MIME_TYPE_VIDEO)
                        {
                            mma_parse_store_body_object_info(obj, info->msg_id, MMA_MEDIA_MSG_VIDEO);
                        }
                        if(app_lib_mime_type_value == MIME_TYPE_TEXT)
                        {
							info->thmubnail_txt_obj = obj;								
                        }
                    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
                    if (app_lib_mime_type_value == MIME_TYPE_TEXT || app_lib_mime_type_value == MIME_TYPE_IMAGE ||
#ifdef __MMI_MMS_VIDEO_FEATURE__
                        app_lib_mime_type_value == MIME_TYPE_VIDEO || 
#endif
                        app_lib_mime_type_value == MIME_TYPE_AUDIO)
                    {
                        if (info->mode != MMA_MODE_EDIT || info->mms_dsr->body->slide_no < wap_custom_get_max_mms_slide())
                        {
#ifdef __MMI_MMS_POSTCARD_WITH_OUT_SMIL__
							/*For Postcard we will add only one slide*/
							if(info->msg_type != MMA_MSG_TYPE_POSTCARD || info->mms_dsr->body->slide_no == 0)
							{
#ifdef  __MMI_OP01_MMS_ADD_SLIDE_TIME_FOR_MIXED_MMS_SUPPORT__
                                if(info->mode == MMA_MODE_EDIT)
                                {
                                    slide = mma_insert_slide(mma_parse_mod_id, info->mms_dsr->body, mma_get_setting_slide_timing());
                                }
                                else
#endif   /*  __MMI_OP01_MMS_ADD_SLIDE_TIME_FOR_MIXED_MMS_SUPPORT__ */
                                {
                                    slide = mma_insert_slide(mma_parse_mod_id, info->mms_dsr->body, 0);
                                }
							}
							else if(info->msg_type == MMA_MSG_TYPE_POSTCARD)

							{
								slide = info->mms_dsr->body->slides;
							}
#else
#ifdef  __MMI_OP01_MMS_ADD_SLIDE_TIME_FOR_MIXED_MMS_SUPPORT__
							if(info->mode == MMA_MODE_EDIT)
                            {
                                
                                slide = mma_insert_slide(mma_parse_mod_id, info->mms_dsr->body, mma_get_setting_slide_timing());
                            }
                            else
#endif  /*  __MMI_OP01_MMS_ADD_SLIDE_TIME_FOR_MIXED_MMS_SUPPORT__ */
                            {
                                slide = mma_insert_slide(mma_parse_mod_id, info->mms_dsr->body, 0);
                            }
#endif
                            obj->is_attachment = KAL_FALSE;
                            (void)mma_insert_slide_obj(mma_parse_mod_id, app_lib_mime_type_value, slide, obj);
                        }
                        else
                       {
                            info->content_truncate_info |= MMA_TRUNCATED_SLIDE;
                            obj->is_mixed_obj = KAL_TRUE;  /* too many objects, cannot be used for SMIL editor */

                       }
                    }
                    else
                    {
                        obj->is_attachment = KAL_TRUE;
						if(info->mode == MMA_MODE_EDIT)
        {
								if(info->ref_attach_count >= wap_custom_get_max_mms_attachment())
            {
									info->content_truncate_info |= MMA_TRUNCATED_ATTACHMENT;
									obj = obj->next;
									continue;				
            }
            else
            {
									info->ref_attach_count++;
                    }
                    }
                        (void)mma_insert_unref_item_to_tail(mma_parse_mod_id, info->mms_dsr->body, obj);
                    }
                    obj = obj->next;
                }
                    }

            if (info->mms_dsr->body->slide_no == 0)  /* Add empty slide */
                        {
                (void)mma_insert_slide(mma_parse_mod_id, info->mms_dsr->body, 0);
							}
			mma_assign_slide_index(info->mms_dsr->body);
                                info->state = MMA_PARSE_STATE_FINISHING;
            info->sub_state = 0;
            info->input = MMA_RESULT_OK;
                                action = MMA_PARSE_ACTION_CONTINUE;
                            break;
                        }

        /*case MMA_PARSE_STATE_XML_CREATING: */ /*no need to have the state */
        case MMA_PARSE_STATE_APP_MMS_HEADER_CREATING:
                {
			info->mms_dsr->header = (mma_mms_description_header_struct*)MMA_PARSE_CALLOC(sizeof(mma_mms_description_header_struct));
			ASSERT(info->mms_dsr->header);
			info->mms_dsr->header->header = (mma_mms_header_struct*)MMA_PARSE_CALLOC(sizeof(mma_mms_header_struct));
 			ASSERT(info->mms_dsr->header->header);
            /* copy the header to the appliaction header */ 

                        switch(info->suffix)
                        {
                            case MMS_SUFFIX_SEND_REQ:
                            case MMS_SUFFIX_MSG:
                            case MMS_SUFFIX_TEMPLATE:
                            {
								(void)mma_copy_mms_to_app_header(mma_parse_mod_id, info->header, info->mms_dsr->header->header, info->mode, info->suffix, info->msg_type, info->msg_id);
                                if (info->mode != MMA_MODE_REPLY && info->mode != MMA_MODE_REPLY_ALL && info->mode != MMA_MODE_HEADER)
                                {
                                   // info->sub_state = MMA_PARSE_SUB_STATE_CREATE_XML_LAYOUT;
                                   info->state = MMA_PARSE_STATE_MMS_BODY_HEADER_PARSING;
                                   info->sub_state = 0;
                                }
                                else
                                {
                          info->state = MMA_PARSE_STATE_FINISHING;
                                }
                                if (info->header != NULL)
                                {
                                    MMSlib_freeMmsGetHeader(mma_parse_mod_id, info->header->header.g_header);                                
                                }
                                break;
                            }
                            case MMS_SUFFIX_IMMEDIATE:
                            case MMS_SUFFIX_NOTIFICATION:
								{
									mma_copy_mms_to_app_header(mma_parse_mod_id, info->header, info->mms_dsr->header->header, info->mode, info->suffix, info->msg_type, info->msg_id);
									info->state = MMA_PARSE_STATE_FINISHING;
									break;
								}
                            case MMS_SUFFIX_DELIVERYREPORT:
                            case MMS_SUFFIX_READREPORT:
								{
									mma_copy_mms_to_app_header(mma_parse_mod_id, info->header, info->mms_dsr->header->header, info->mode, info->suffix, info->msg_type, info->msg_id);
									info->state = MMA_PARSE_STATE_FINISHING;
									break;
								
								}
                            default:
								ASSERT(0);//info->sub_state = MMA_PARSE_SUB_STATE_WRITE_XML_END;
                            break;
                        }
                        info->input = MMA_RESULT_OK;
                        action = MMA_PARSE_ACTION_DELAYED;
                        MMA_SIGNAL_SENDTO_U(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_PARSE_CONTINUE_IND, info->req_id);
                        break;
                    }
        case MMA_PARSE_STATE_FINISHING:
        {
            info->result = info->input;
            info->state = MMA_PARSE_STATE_FINISHED;
            action = MMA_PARSE_ACTION_CONTINUE;
            break;
        }

        case MMA_PARSE_STATE_FINISHED:
        {
            if (info->w_handle >= 0)
            {
                kal_char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
                memset(file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
                MMA_GET_MMS_XML_FILEPATH(file_path, 0);            
                MSF_FILE_CLOSE(info->w_handle);
                info->w_handle = -1;
                MMA_PARSE_FREE(info->xml_filepath);
                info->xml_filepath = (kal_wchar *)MSF_FILE_GET_EXTERNAL_FILENAME_EXT(mma_parse_mod_id, file_path, translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type) /*Always system "c:\*/);
                info->xml_size = MSF_FILE_GETSIZE_EXT(file_path, translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type) /*always system "c:\"*/);
            }
            switch (info->result)
            {
                case MMA_RESULT_OK:
                  //  ASSERT(info->buffer_index == 0);
                    /* fall-through */
                default:
                    /* may need more than 1 rsp */
#ifdef  __MMI_MMS_USE_ASM__
                    if (info->mode == MMA_MODE_INT_PARSE)
                     {
                         mma_parse_send_int_rsp(info->req_id, info->result);
						 mma_parse_delete_task_hdlr(info->req_id);
                      
                     }
                      else

/*                    if (mma_parse_mod_id == MSF_MODID_ASM)*/
                    {
                        /*Copy rsp data*/
                        kal_uint8 source = info->source;
                        g_mma_parse_context.rsp_data = mma_parse_fill_slim_ext_rsp(info->req_id, info->result);
						if(info->result != MMA_RESULT_OK)
						{
							mma_parse_delete_task_hdlr(info->req_id);
						}
						else 
						{
                            mms_mma_send_get_content_rsp((module_type)source, g_mma_parse_context.rsp_data, NULL);
						}
                            /*Now send the rsp saved in globalcontext*/
                            
                            MMA_FREE(g_mma_parse_context.rsp_data);
                            g_mma_parse_context.rsp_data = NULL;
                     
                        

                        /*delete the context*/

                    }
#else
                    if (mma_parse_send_rsp(info->req_id, info->result) == FALSE)
                    {
                        mma_parse_delete_task_hdlr(info->req_id);
                    }
#endif /* __MMI_MMS_USE_ASM__ */
                    break;
            }
            action = MMA_PARSE_ACTION_NONE;
            break;
        }

    }

    return action;
}


/*****************************************************************************
 * FUNCTION
 *  mma_parse_fsm_hdlr
 * DESCRIPTION
 *  Parsing task handler for every state switching
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_parse_fsm_hdlr(MSF_UINT32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *req = mma_parse_get_task_by_req(req_id);
    mma_parse_info_struct *info = NULL;
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_parse_context.mma_parse_env_state == MMA_PARSE_ENV_STATE_ACTIVE)
    {
        ASSERT(req != NULL && req->data != NULL);
        info = (mma_parse_info_struct*) req->data;
        while (mma_parse_fsm(info) == MMA_PARSE_ACTION_CONTINUE);
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    else if (g_mma_parse_context.mma_parse_env_state == MMA_PARSE_ENV_STATE_MEM_CARD_PLUG_OUT)
    {
        mms_mma_queue_struct *curr = g_mma_parse_context.mma_parse_task_queue;
        
        ASSERT(curr != NULL && curr->data != NULL);

        while (curr != NULL)
        {
            info = (mma_parse_info_struct*) curr->data;
    
            if (!mma_main_is_storage_type_present((mma_msg_storage_type_enum)info->storage_type))
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_REQ_FAILED_CARD_PLUG_OUT,"(mma_main.c)MMA_PARSE_REQ_FAILED_CARD_PLUG_OUT: %d", info->app_id));               
#ifdef  __MMI_MMS_USE_ASM__
                if (info->mode == MMA_MODE_INT_PARSE)
                {
                    mma_parse_send_int_rsp(info->req_id, MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT);
					mma_parse_delete_task_hdlr(info->req_id);

                }
                else
                /*                    if (mma_parse_mod_id == MSF_MODID_ASM)*/
                {
                    /*Copy rsp data*/
                  //  kal_uint8 source = info->source;
                    g_mma_parse_context.rsp_data = mma_parse_fill_slim_ext_rsp(info->req_id, MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT);
                    mma_parse_delete_task_hdlr(info->req_id);
                    
                        /*no nees to send  the rsp as the the errored result fill slim would automatically send the rsp*/
                      //  mms_mma_send_get_content_rsp(source, g_mma_parse_context.rsp_data, NULL);
                        MMA_FREE(g_mma_parse_context.rsp_data);
                        g_mma_parse_context.rsp_data = NULL;
                    
                }
#else
                (void)mma_parse_send_rsp(curr->first_id, MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT);      
                mma_parse_delete_task_hdlr(curr->first_id);
#endif /* __MMI_MMS_USE_ASM__ */
            }

            curr = curr->next;
        }

        req = mma_parse_get_task_by_req(req_id);
        
        if (req != NULL)
        {
            /* Current message is on phone*/
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_RESUME_REMAINING_PARSE_REQ, "(mma_parse.c)MMA_PARSE_RESUME_REMAINING_PARSE_REQ : %d",info->app_id));
            MMA_SIGNAL_SENDTO_U(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND, info->req_id);
        }

        g_mma_parse_context.mma_parse_env_state = MMA_PARSE_ENV_STATE_ACTIVE;

    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_FSM_HDLR_STATE_NOT_ACTIVE,
                          "(mma_parse.c) env state %d\n", g_mma_parse_context.mma_parse_env_state));
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_get_content_req_hdlr
 * DESCRIPTION
 *  Entry handler for MMS parsing request
 * PARAMETERS
 *  source      [IN]        
 *  p           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_get_content_req_hdlr(module_type source, wap_mma_get_content_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_parse_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(p != NULL);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_GET_CONTENT_REQ_HDLR_DETAIL,
                      "mms_mma_get_content_req_hdlr(%d, %d, %d, %d)\n", p->app_id, p->req_id, p->msg_id, p->mode));
    if (p->mode == MMA_MODE_ABORT)
    {
        if (mma_main_is_in_usb_mode() || mma_main_is_in_terminate())
        {
            /* Do nothing */
        }
        else
        {
            mma_parse_delete_task_hdlr(p->req_id);
            mma_parse_send_direct_rsp(
                source,
                p->req_id,
                p->app_id,
                p->msg_id,
                (mma_app_mode_enum)p->mode,
              /*  p->buffer_index,*/
                MMA_RESULT_ABORTED);
        }
		MMA_FREE(p);
        return;
    }

    if (mma_main_is_in_usb_mode())
    {
        mma_parse_send_direct_rsp(
            source,
            p->req_id,
            p->app_id,
            p->msg_id,
            (mma_app_mode_enum)p->mode,
           /* p->buffer_index,*/
            MMA_RESULT_FAIL_IN_USB_MODE);
    }
    else if (mma_main_is_in_terminate())
    {
        mma_parse_send_direct_rsp(
            source,
            p->req_id,
            p->app_id,
            p->msg_id,
            (mma_app_mode_enum)p->mode,
        /*    p->buffer_index,*/
            MMA_RESULT_FAIL_TERMINATING);
    }
    else if (mma_parse_get_task_by_req(p->req_id) != NULL)      /* request for next XML content */
    {/*
        info = (mma_parse_info_struct*) req->data;

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if ((!mma_main_is_storage_type_present(info->storage_type)))
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_REQ_FAILED_CARD_PLUG_OUT,"(mma_main.c)MMA_PARSE_REQ_FAILED_CARD_PLUG_OUT: %d", info->app_id));
#ifdef  __MMI_MMS_USE_ASM__
                if (info->mode == MMA_MODE_INT_PARSE)
                {
                    mma_parse_send_int_rsp(info->req_id, info->result);
					mma_parse_delete_task_hdlr(info->req_id);

                }
                else
                
                {
                   
                    kal_uint8 source = info->source;
                    g_mma_parse_context.rsp_data = mma_parse_fill_slim_ext_rsp(info->req_id, info->result);
                    if (mma_parse_delete_task_hdlr(info->req_id))
                    {
                       
                        mms_mma_send_get_content_rsp(source, g_mma_parse_context.rsp_data, NULL);
                        MMA_FREE(g_mma_parse_context.rsp_data);
                        g_mma_parse_context.rsp_data = NULL;
                    }
                }
#else
            (void)mma_parse_send_rsp(req->first_id, MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT);      
            mma_parse_delete_task_hdlr(req->first_id);
#endif 
            g_mma_parse_context.mma_parse_env_state = MMA_PARSE_ENV_STATE_ACTIVE;
        }
        else
#endif*/
#ifndef __MMI_MMS_USE_ASM__
  /*      if (info != NULL && p->buffer_index == info->buffer_index + 1) 
        {
            info->buffer_index++;
            if (mma_parse_send_rsp(req->first_id, MMA_RESULT_OK) == FALSE)
            {
                mma_parse_delete_task_hdlr(req->first_id);
            }
        }
        else*/
#endif
        {
            ASSERT(0);
        }
    }
    else if (mma_count_node_in_queue(g_mma_parse_context.mma_parse_task_queue) < MMA_MAX_PARSE_TASK_NUM)        /* add new parsing task */
    {
        mms_mma_queue_struct *old_task = NULL;

        info = (mma_parse_info_struct*) MMA_CALLOC(sizeof(mma_parse_info_struct));
        info->source = source;
        info->app_id = p->app_id;
        info->req_id = p->req_id;
        info->msg_id = p->msg_id;
        info->mode = (mma_app_mode_enum) p->mode;
        info->creation_mode = (mma_creation_mode_enum)p->creation_mode;
        //info->buffer_index = p->buffer_index;
        //info->header = NULL;
        info->body_header = NULL;
        //info->body = NULL;
        info->state = MMA_PARSE_STATE_STARTED;
        info->sub_state = 0;
        info->input = MMA_RESULT_OK;
        info->result = MMA_RESULT_OK;
        info->w_handle = -1;
        info->delayed_handle = -1;
        info->storage_type = mma_get_message_storage(info->msg_id);
		info->mms_dsr = (mma_mms_description_struct*)MMA_CALLOC(sizeof(mma_mms_description_struct));
		ASSERT(info->mms_dsr);

        if ((old_task = mma_parse_get_task_by_app(info->app_id)) != NULL)
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_GET_TASK_BY_APP_NOT_NULL,
                              "(mma_parse.c): Duplicate request by AP %d.", info->app_id));
            mma_parse_delete_task_hdlr(old_task->first_id);
        }
        if (mma_insert_node_to_queue(&g_mma_parse_context.mma_parse_task_queue, info->req_id, 0, info, MMA_ACTION_PARSE_MSG) != MMA_RESULT_OK)
        {
            ASSERT(0);
        }

        if (g_mma_parse_context.mma_parse_task_queue->first_id == info->req_id) /* One active task at a time */
        {
            mma_reset_last_tick();
            mma_parse_fsm_hdlr(p->req_id);
        }
        else
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_NOT_PARSE_TASK,
                              "(mma_parse.c): Request %d queued", info->req_id));
        }
    }
    else
    {
        ASSERT(0);  /* too many undigested tasks, check why */
    }
    MMA_FREE(p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_parse_process_int_sig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mma_parse_process_int_sig(mma_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sig == NULL)
    {
        return;
    }
    switch (sig->type)
    {
        case MMA_INT_SIG_TYPE_MSG_PARSE_REQ:
            mms_mma_get_content_req_hdlr((module_type) sig->i_param, (wap_mma_get_content_req_struct*) sig->p_param);
            break;

        case MMA_INT_SIG_TYPE_MSG_PARSER_GET_BASIC_MSG_INFO:
        {
            wap_mma_get_content_req_struct *req =
                (wap_mma_get_content_req_struct*) MMA_CALLOC(sizeof(wap_mma_get_content_req_struct));
            req->app_id = 0xFF;
            req->req_id = mma_get_request_id();
            req->msg_id = sig->u_param1;
            req->mode = MMA_MODE_INT_PARSE;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_GET_SIG_PARSER_BASIC_MSG_INFO,
                              "MMA_INT_SIG_TYPE_MSG_PARSER_GET_BASIC_MSG_INFO: req %d, msg %d\n", req->req_id,
                              req->msg_id));

            mms_mma_get_content_req_hdlr((module_type)sig->i_param, req);
            break;
        }

        case MMA_INT_SIG_TYPE_MSG_PARSE_CONTINUE_IND:
			if (g_mma_parse_context.mma_parse_task_queue != NULL && g_mma_parse_context.mma_parse_task_queue->first_id == sig->u_param1)
			{
                mma_parse_fsm_hdlr(sig->u_param1);
            }
			else
			{
				MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_SIG_MSG_PARSE_CONTINUE_IND,
								  "MMA_INT_SIG_TYPE_MSG_PARSE_CONTINUE_IND: req_id %d", sig->u_param1));
			}
            break;

        case MMA_INT_SIG_TYPE_MSG_PARSE_NEXT_IND:
            if (g_mma_parse_context.mma_parse_task_queue != NULL)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_SIG_MSG_PARSE_NEXT_IND,
                                  "(mma_parse.c): Queued request %d start",
                                  g_mma_parse_context.mma_parse_task_queue->first_id));
                mma_parse_fsm_hdlr(g_mma_parse_context.mma_parse_task_queue->first_id);
            }
            break;

		case MMA_INT_SIG_TYPE_FREE_MMS_CONTENT_INFO:
            if (g_mma_parse_context.mma_parse_task_queue != NULL)
            {
				(void)mma_parse_delete_task_hdlr(((wap_mma_free_content_info_struct*) sig->p_param)->req_id);
            }
			MMA_FREE(sig->p_param);
            break;

        case MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ:
        {
            mms_mma_queue_struct *curr = g_mma_parse_context.mma_parse_task_queue;

            g_mma_parse_context.mma_parse_env_state = MMA_PARSE_ENV_STATE_ENTERING_USB;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_SIG_MSG_ENTER_USB_REQ_IND,
                              "(mma_parse.c): MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ %d\n", sig->type));
            if (curr != NULL)
            {
#ifdef  __MMI_MMS_USE_ASM__
                mma_parse_info_struct *info = (mma_parse_info_struct*) curr->data;

                if (info->mode == MMA_MODE_INT_PARSE)
                {
                    mma_parse_send_int_rsp(info->req_id, MMA_RESULT_FAIL_IN_USB_MODE);
					mma_parse_delete_task_hdlr(info->req_id);

                }
                else
                /*                    if (mma_parse_mod_id == MSF_MODID_ASM)*/
                {
                    /*Copy rsp data*/
                    //kal_uint8 source = info->source;
                    info->result = MMA_RESULT_FAIL_IN_USB_MODE;
                    g_mma_parse_context.rsp_data = mma_parse_fill_slim_ext_rsp(info->req_id, info->result);
                    mma_parse_delete_task_hdlr(info->req_id);
                    
                        /*Now send the rsp saved in globalcontext*/
                      // mms_mma_send_get_content_rsp(source, g_mma_parse_context.rsp_data, NULL);
                        MMA_FREE(g_mma_parse_context.rsp_data);
                        g_mma_parse_context.rsp_data = NULL;
                    

                }
#else
                (void)mma_parse_send_rsp(curr->first_id, MMA_RESULT_FAIL_IN_USB_MODE);
                mma_parse_delete_task_hdlr(curr->first_id);
#endif /* __MMI_MMS_USE_ASM__ */
               
            }
            else
            {
                g_mma_parse_context.mma_parse_env_state = MMA_PARSE_ENV_STATE_ACTIVE;
                MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_CREATE, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
            }
            break;
        }

        case MMA_INT_SIG_TYPE_MSG_TERMINATE_IND:
        {
            mms_mma_queue_struct *curr = g_mma_parse_context.mma_parse_task_queue;

            g_mma_parse_context.mma_parse_env_state = MMA_PARSE_ENV_STATE_TERMINATING;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_SIG_MSG_TERMINATE_REQ_IND,
                              "(mma_parse.c): MMA_INT_SIG_TYPE_MSG_TERMINATE_IND %d\n", sig->type));
            if (curr != NULL)
            {
#ifdef  __MMI_MMS_USE_ASM__
                mma_parse_info_struct *info = (mma_parse_info_struct*) curr->data;

                if (info->mode == MMA_MODE_INT_PARSE)
                {
                    mma_parse_send_int_rsp(info->req_id, MMA_RESULT_FAIL_TERMINATING);
					mma_parse_delete_task_hdlr(info->req_id);

                }
                else
                /*                    if (mma_parse_mod_id == MSF_MODID_ASM)*/
                {
                    /*Copy rsp data*/
                    //kal_uint8 source = info->source;
                    info->result = MMA_RESULT_FAIL_TERMINATING;
                    g_mma_parse_context.rsp_data = mma_parse_fill_slim_ext_rsp(info->req_id, info->result);
                    mma_parse_delete_task_hdlr(info->req_id);
                    
                        /*Now send the rsp saved in globalcontext*/
                        //mms_mma_send_get_content_rsp(source, g_mma_parse_context.rsp_data, NULL);
                        MMA_FREE(g_mma_parse_context.rsp_data);
                        g_mma_parse_context.rsp_data = NULL;

                }
#else
                (void)mma_parse_send_rsp(curr->first_id, MMA_RESULT_FAIL_TERMINATING);
                mma_parse_delete_task_hdlr(curr->first_id);
#endif /* __MMI_MMS_USE_ASM__ */

            }
            else
            {
                MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_CREATE, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
            }
            break;
        }
#ifdef __MMI_VCARD__
        case MMA_INT_SIG_TYPE_MSG_VCARD_VERSION_RSP:
        {
           mms_mma_queue_struct *entry = mma_parse_get_active_task();
           /*Reset the last tick*/
           mma_reset_last_tick();
            if (entry != NULL)
            {
                mma_parse_info_struct *info = (mma_parse_info_struct*) entry->data;
                srv_mms_get_vcard_version_rsp_struct *msgVcardVersion = (srv_mms_get_vcard_version_rsp_struct*)sig->p_param;
                if(msgVcardVersion->result == MMA_RESULT_OK)
                {	
		    if (msgVcardVersion->vcard_ver == VCARD_VERSION_2_1)
                    {
						info->mms_dsr->body->curr_object->is_restricted = TRUE;
		    }
		    else 
		    {
						info->mms_dsr->body->curr_object->is_restricted = FALSE;
		    }
                }
                else
                {
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_SIG_MSG_VCARD_VERSION_RSP,
                        "(mma_parse.c): MMA_INT_SIG_TYPE_MSG_VCARD_VERSION_RSP %d", msgVcardVersion->result));

                }
                mma_parse_fsm_hdlr(entry->first_id);
                info->input = MMA_RESULT_OK;
            }
            else
            {
                ASSERT(0);
            }
			break;

        }
#endif // __MMI_VCARD__

        
#ifdef __MMI_MMS_USE_ASM__
        case MMA_INT_SIG_TYPE_MSG_GET_ASM_POOL_RSP:
        {

            mms_mma_queue_struct *entry = mma_parse_get_active_task();

            mmi_mms_get_asm_pool_rsp_struct *get_asm_pool_rsp_struct = (mmi_mms_get_asm_pool_rsp_struct*)sig->p_param;

            if (entry != NULL && entry->first_id == get_asm_pool_rsp_struct->req_id)
            {

                if (get_asm_pool_rsp_struct->result == KAL_TRUE)
                {
                    MSF_SET_MMS_APP_MEM_POOL (get_asm_pool_rsp_struct->asm_pool_ptr, MMA_ASM_MEM_POOL_SIZE); // sandeep
					MSF_MODULE_START(MSF_MODID_MMA, MSF_MODID_ASM, NULL, NULL, NULL); // Sandeep
                }
                else
                {            
                    mma_parse_info_struct *info = (mma_parse_info_struct*) entry->data;
                    info->input = MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;
                }
                mma_parse_fsm_hdlr(entry->first_id);

            }
            else
            {
                /*Request is already deleted so just free the ASM memory*/
                MMAif_freeAsmMemory();
            }
			MMA_FREE(sig->p_param);
            break;

        }
        case MMA_INT_SIG_TYPE_MSG_DEINIT_ASM_POOL_REQ:
        {

            mms_mma_queue_struct *entry = mma_parse_get_active_task();
            mmi_mms_get_deinit_asm_pool_req_struct *deinit_asm_pool_req_struct = (mmi_mms_get_deinit_asm_pool_req_struct*)sig->p_param;

            if (entry != NULL  && deinit_asm_pool_req_struct->req_id == entry->first_id)
            {
                mma_parse_info_struct *info = (mma_parse_info_struct*) entry->data;

                info->input = MMA_RESULT_FAIL_USER_CANCEL;
                mma_parse_fsm_hdlr(entry->first_id);
            }
            else
            {
                /* we have already deinit */
                /*put log here*/
                MMAif_senddeinitasmMem();
            }
            break;

        }
#endif /* __MMI_MMS_USE_ASM__ */

        default:
            break;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mma_parse_is_busy_on_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  storage        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

kal_bool mma_parse_is_busy_on_storage(kal_uint8 card_enum)
{
    mms_mma_queue_struct *curr = g_mma_parse_context.mma_parse_task_queue;

    while (curr != NULL)
    {
        mma_parse_info_struct *info = curr->data;

        if (info != NULL && info->storage_type == card_enum)
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_IS_BUSY_ON_STORAGE,"(mma_parse.c): mma_parse_is_busy_on_storage():%d", card_enum));
            return KAL_TRUE;            
        }

        curr = curr->next;
    }
    return KAL_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  mma_parse_check_and_correct_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_parse_check_and_correct_filename(mma_mms_object_struct *obj)
{
	char *ext = NULL;
	applib_mime_type_struct *entry = NULL;
	if (mma_is_ascii_string(obj->file_name) == KAL_FALSE)
    {
        /* Check when convert to ucs2 we are able to extract ext, if not then replace no-ascii chars to underscore*/
        kal_uint16 destlen = 0;
        char* temp_name = NULL;
        char* ext = NULL;
        destlen = (strlen(obj->file_name) + 1) * ENCODING_LENGTH;

        temp_name = (char*)MMA_PARSE_CALLOC(destlen);

        memset(temp_name, 0, destlen);

        /*Use same API as used by application */
        mmi_chset_utf8_to_ucs2_string((kal_uint8*)temp_name, destlen, (kal_uint8*)obj->file_name);         
        ext = (S8*)srv_fmgr_path_get_extension_ptr((WCHAR*)temp_name);

        if (ext == NULL)
        {
            char *ch = obj->file_name;
            while (*ch != '\0')
            {
                if (*ch & 0x80)
                {
                    *ch = '_';  /* use '_' to replace non-ASCII char */
                }
                ch += 1;
            }
        }
        MMA_PARSE_FREE(temp_name);
    }

	 if (msf_cmmn_strcmp_nc(obj->mime_str, MMA_MEDIA_TYPE_STRING_DRM1) == 0 ||
           msf_cmmn_strcmp_nc(obj->mime_str, MMA_MEDIA_TYPE_STRING_DRM2) == 0 ||
		   msf_cmmn_strcmp_nc(obj->mime_str, MMA_UNKNOWN_MIME_STR) == 0)
	 {
		 //Dont change for DRM
     }
	 else
	 {
		ext = strrchr(obj->file_name, '.');
		if (ext == NULL)
		{            
			entry = applib_mime_type_look_up((kal_char*) obj->mime_str, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
			if (entry != NULL && entry->file_ext != NULL && strlen(entry->file_ext) > 0)
			{
				char *temp_name = (char*)MMA_PARSE_CALLOC(strlen(obj->file_name) + 1 + strlen(entry->file_ext) + 1);
				sprintf(temp_name, "%s.%s", obj->file_name, entry->file_ext);
				MMA_PARSE_FREE(obj->file_name);
				obj->file_name = temp_name;
			}
        
		}
		else
		{
        
			entry = applib_mime_type_look_up(NULL, ext+1, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
			if (entry == NULL)
			{
				/*Change the extension to correct name*/
				entry = applib_mime_type_look_up((kal_char*) obj->mime_str, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
				if (entry != NULL && entry->file_ext != NULL && strlen(entry->file_ext) > 0)
				{
					char *temp_name ;
					*ext = '\0';
					temp_name = (char*)MMA_PARSE_CALLOC(strlen(obj->file_name) + 1 + strlen(entry->file_ext) + 1);
					sprintf(temp_name, "%s.%s", obj->file_name, entry->file_ext);
					MMA_PARSE_FREE(obj->file_name);
					obj->file_name = temp_name;
				}
			}
		}
	 }
}

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_parse_memory_card_plug_out_callback
 * DESCRIPTION
 *  Callback function for memory card plug out
 * PARAMETERS
 *  plugout_card        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_parse_memory_card_plug_out_callback(kal_uint8 plugout_card)
{
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_CARD_PLUG_OUT_CALLBACK, "(mma_parse.c)mma_parse_memory_card_plug_out_callback()"));

   if (mma_parse_is_busy_on_storage(plugout_card))
   {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_PARSE_CHANGE_STATE_TO_CARD_PLUG_OUT, "(mma_parse.c)MMA_PARSE_CHANGE_STATE_TO_CARD_PLUG_OUT"));
        g_mma_parse_context.mma_parse_env_state = MMA_PARSE_ENV_STATE_MEM_CARD_PLUG_OUT;
   }  
    
}
#endif /*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_parse_store_body_object_info
 * DESCRIPTION
 *  Store the body info in a file for faster access
 * PARAMETERS
 *  obj        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_parse_store_body_object_info(mma_mms_object_struct *obj, kal_uint32 msg_id, mma_media_msg_enum media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long file_name_len = 0, dstLen = 0;
    long srcLen = 0;
    mmsBodyObjectInfo *thumbnail = (mmsBodyObjectInfo*)MMA_CALLOC(sizeof(mmsBodyObjectInfo));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Right now, it's only for thumbnail. Can increase it with all the objects data, if required */
    thumbnail->total_object = 1;
    thumbnail->body_data[0].body_size = obj->size;
    thumbnail->body_data[0].body_offset = obj->offset;
    thumbnail->body_data[0].body_type = (kal_uint8)media_type;
    if(obj->file_name)
    {
        file_name_len = (kal_uint16)strlen(obj->file_name);
    }
    if(obj->drm_process_type != MMA_DRM_NO_PROTECTION)
    {
        thumbnail->body_data[0].is_drm = 1;
    }
    else
    {
        thumbnail->body_data[0].is_drm = 0;
    }
    //dstLen = (MMS_MAX_OBJECT_FILE_NAME_LEN - 1) * sizeof(kal_wchar);
    dstLen = (MMS_MAX_OBJECT_FILE_NAME_LEN - 1);
    srcLen = file_name_len;
    /* Must include the file extension */
    if(srcLen > dstLen)
    {
        long file_ext_len = 0;
        char *ext = NULL;
        thumbnail->body_data[0].body_name_len = (kal_uint16)dstLen;
        ext = strrchr(obj->file_name, '.');
        if (ext != NULL)
        {
            file_ext_len = (kal_uint16)strlen(ext);
        }
        srcLen = file_name_len - file_ext_len;
        dstLen = (dstLen - file_ext_len)*sizeof(kal_wchar);
        msf_charset_utf8_to_ucs2le(obj->file_name, 
                 &srcLen,
                 (char *)thumbnail->body_data[0].body_name, 
                 &dstLen);
        if(file_ext_len > 0)
        {
            /* add the extension of the file */
            long src_offset = file_name_len - file_ext_len;
            long dst_offset = (MMS_MAX_OBJECT_FILE_NAME_LEN - 1 - file_ext_len);
            srcLen = file_ext_len;
            dstLen = file_ext_len * sizeof(kal_wchar);
            msf_charset_utf8_to_ucs2le((obj->file_name + src_offset), 
                 &srcLen,
                 (char *)(thumbnail->body_data[0].body_name + dst_offset), 
                 &dstLen);
        }
    }
    else
    {
        thumbnail->body_data[0].body_name_len = (kal_uint16)file_name_len;
        dstLen = (MMS_MAX_OBJECT_FILE_NAME_LEN - 1) * sizeof(kal_wchar);
        msf_charset_utf8_to_ucs2le(obj->file_name, 
                 &srcLen,
                 (char *)thumbnail->body_data[0].body_name, 
                 &dstLen);
    }
    /* Send the RSP to MSGMGR for the data update & free the memory */                            
    /* Check to free the memory in calling Signal function */
    MMA_SIGNAL_SENDTO_IUP( MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_UPDATE_MMS_THUMBNAIL_INFO,
            0, msg_id, thumbnail);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_PARSE_C */ 

