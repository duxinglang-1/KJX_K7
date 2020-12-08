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
 *   mma_create.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions which are used to create MMS message.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#ifndef _MMA_CREATE_C
#define _MMA_CREATE_C

#if defined(MMS_SUPPORT)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "mma_api.h"
#include "stack_ltlcom.h"

#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"

#include "wapadp.h"
#include "mmsadp.h"

/* APPLIB */
#include "app_str.h"
#include "app_mine.h"
#include "app_datetime.h"

/* CUSTOM */
#include "custom_wap_config.h"

/* PLUTOMMI */
#include "MMI_features.h"
#include "UmSrvStruct.h"        /* For mma_interface.h */
#include "Sim_common_enums.h"   /* is_test_sim */
#include "sim_public_api.h"   /* is_test_sim */

/* MSF */
#include "msf_def.h"
#include "msf_core.h"   /* MSF: System core call */
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_wid.h"    /* MSF: Display property */
#include "msf_chrs.h"   /* MSF: character API */

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#include "mmsl_if.h"
#include "mltypes.h"    /* MMS LIB TYPES */
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
#include "mma_mime.h"
#include "mma_msg_struct.h"
#include "mma_create.h"
#include "mma_parse.h"
#include "mma_utilities.h"
#include "mma_interface.h"
#include "mma_xml.h"
#include "mma_msgmgr.h"
#include "mma_main.h"
#include "mma_setting.h"
/***************************************************************************** 
* Define
*****************************************************************************/
/* We can think to increase the value from 1 to some other max no. Need more expriment */
/* Incase of value greater then 1 need to do handling at deleting node also. */
#define MMA_MAX_CREATE_TASK_NUM 1
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local static Variable
*****************************************************************************/
static mma_create_context_struct g_mma_create_context = {0, };

#ifdef __GEMINI__
  sim_interface_enum l4c_gemini_get_switched_sim_id(sim_interface_enum simId);        
#endif /* __GEMINI__ */ 

/***************************************************************************** 
* Local Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mma_create_init
 * DESCRIPTION
 *  Create sub-module init
 * PARAMETERS
 *  void
 * RETURNS
 *  MSF_BOOL
 *****************************************************************************/
kal_bool mma_create_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_create_context.mma_create_task_queue = NULL;
    g_mma_create_context.mma_create_env_state = MMA_CREATE_ENV_STATE_ACTIVE;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_terminate
 * DESCRIPTION
 *  Create sub-module termination
 * PARAMETERS
 *  void
 * RETURNS
 *  MSF_BOOL
 *****************************************************************************/
kal_bool mma_create_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_create_context.mma_create_task_queue = NULL;
    g_mma_create_context.mma_create_env_state = MMA_CREATE_ENV_STATE_TERMINATED;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_get_active_task
 * DESCRIPTION
 *  Get current create request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mms_mma_queue_struct *mma_create_get_active_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mma_create_context.mma_create_task_queue;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_get_task_by_req
 * DESCRIPTION
 *  Get task by request ID
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  mms_mma_queue_struct
 *****************************************************************************/
static mms_mma_queue_struct *mma_create_get_task_by_req(kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_get_node_from_queue(g_mma_create_context.mma_create_task_queue, req_id, 0);
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_process_parsed_info
 * DESCRIPTION
 *  Reset the layout information.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 Decimal value.(?)
 *****************************************************************************/
void mma_create_process_parsed_info(mma_create_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mma_mms_slide_struct *slide;
	kal_bool image = KAL_FALSE, text = KAL_FALSE;
    int region_no = 0;
 
	/* update layout: check 1 or 2 regions */
	if(info->mms_dsr->body)
    {
		slide = info->mms_dsr->body->slides;
    while (slide)
        {
        image = KAL_FALSE;
	    text = KAL_FALSE;
        if ((slide->img.object != NULL && !slide->img.object->is_invallid) || (slide->vid.object != NULL && !slide->vid.object->is_invallid))
            {
                image = KAL_TRUE;
            }
        if (slide->txt.object != NULL && !slide->txt.object->is_invallid)
            {
                text = KAL_TRUE;
        }

        if (image && text)
        {
            region_no = 2;
        }
        slide = slide->next;
    }

    if (region_no < 2)
    {
        info->mms_dsr->body->layout = MMA_LAYOUT_NONE;
    }
    else
    {
        ASSERT(info->mms_dsr->body->layout != MMA_LAYOUT_NONE);
    }

    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_create_is_busy_on_storage
 * DESCRIPTION
 *  Callback function for memory card plug out
 * PARAMETERS
 *  storage type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

kal_bool mma_create_is_busy_on_storage(kal_uint8 card_enum)
{

    mms_mma_queue_struct *curr = g_mma_create_context.mma_create_task_queue;

    if (curr != NULL)
    {
        mma_create_info_struct *info =
                    (mma_create_info_struct*) g_mma_create_context.mma_create_task_queue->data;
        if (info != NULL && info->storage_type == card_enum)
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_IS_BUSY_ON_STORAGE, "(mma_create.c): mma_create_is_busy_on_storage():%d", card_enum));
            return KAL_TRUE;
        }       
    }

    return KAL_FALSE;
}


#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_create_memory_card_plug_out_callback
 * DESCRIPTION
 *  Callback function for memory card plug out
 * PARAMETERS
 *  plugout_card        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void mma_create_memory_card_plug_out_callback(kal_uint8 plugout_card)
{
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_CARD_PLUG_OUT_CALLBACK, "(mma_create.c): mma_create_memory_card_plug_out_callback()"));

    if (mma_create_is_busy_on_storage(plugout_card))
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_CHANGE_STATE_TO_CARD_PLUG_OUT, "(mma_create.c): MMA_CREATE_CHANGE_STATE_TO_CARD_PLUG_OUT"));
        g_mma_create_context.mma_create_env_state = MMA_CREATE_ENV_STATE_MEM_CARD_PLUG_OUT;
    }
}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mma_create_free_info
 * DESCRIPTION
 *  Free create info
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_free_info(mma_create_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info != NULL)
    {
        MMA_FREE(info->upload_filepath);
        MMA_FREE(info->xml_filepath);
        if (info->header != NULL)
        {
            MMSlib_freeMmsSetHeader(MSF_MODID_MMA, info->header->header.s_header);
			freeMmsContentType(MSF_MODID_MMA, info->header->header.s_header->contentType);
            MMA_FREE(info->header->header.s_header);
            MMA_FREE(info->header);
        }
	   if(info->mms_dsr)
        {
#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
			if (info->mode == MMA_MODE_VENDOR_XML)
			(void)mma_mms_free_mms_descriptor(MSF_MODID_MMA, info->mms_dsr);				
			else if(info->mode != MMA_MODE_RAW && info->mms_dsr->body)
            {
				mma_mms_object_struct *objs = info->mms_dsr->body->objects;
				while(objs)
            {
					if(objs->mime_str)
            {
						MSF_MEM_FREE(MSF_MODID_MMA,objs->mime_str);
						objs->mime_str = NULL;
					}
					objs =objs->next;
            }
			
			}
		
#else
	      if(info->mode != MMA_MODE_RAW && info->mms_dsr->body)
			{
				mma_mms_object_struct *objs = info->mms_dsr->body->objects;
				while(objs)
				{
					if(objs->mime_str)
            {
						MSF_MEM_FREE(MSF_MODID_MMA,objs->mime_str);
						objs->mime_str = NULL;
					}
					objs =objs->next;
            }

		}
#endif	/* __MMI_MMS_VENDOR_APP_SUPPORT__ */       
        }
        if (info->o_header != NULL)
        {
            MMSlib_freeMmsGetHeader(MSF_MODID_MMA, info->o_header);
            MMA_FREE(info->o_header);
        }
        if (info->o_body_header != NULL)
        {
            /* ToDo: put some log here. */
            info->o_body_header = NULL;
        }
        if (info->t_handle)
        {
            (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
        }
        if (info->m_handle)
        {
            (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
        }
        if (info->r_handle >= 0)
        {
            MSF_FILE_CLOSE(info->r_handle);
        }
        if (info->mo_buffer != NULL)
        {
            MMA_FREE(info->mo_buffer);
        }
        if (info->mo_param != NULL)
        {
            mma_free_body_params(&info->mo_param);
        }

        MMA_FREE(info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_delete_task
 * DESCRIPTION
 *  Delete specified create task
 * PARAMETERS
 *  req             [IN]         
 *  req_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_delete_task(mms_mma_queue_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_create_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req != NULL);
	ASSERT((info = (mma_create_info_struct*) req->data) != NULL);

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_DELETE_TASK_IND_FUNCTION,
                      "(mma_create.c): mma_create_delete_task(req %d, env state %d)\n", info->req_id,
                      g_mma_create_context.mma_create_env_state));

    info->delete_state++;
    if (info->m_handle)
    {
        (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
    }
    if (info->t_handle)
    {
        (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
    }

    if ((req = mma_remove_node_from_queue(&g_mma_create_context.mma_create_task_queue, info->req_id, 0)) != NULL)
    {
        mma_create_free_info(info);
        MMA_FREE(req);
    }

    if (g_mma_create_context.mma_create_env_state == MMA_CREATE_ENV_STATE_ENTERING_USB)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
    }
    else if (g_mma_create_context.mma_create_env_state == MMA_CREATE_ENV_STATE_TERMINATING)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_delete_task_hdlr
 * DESCRIPTION
 *  Delete specified create task
 * PARAMETERS
 *  req_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_delete_task_hdlr(MSF_UINT32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *req = NULL;
    mma_create_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((req = mma_create_get_task_by_req(req_id)) == NULL)
    {
        return;
    }
    ASSERT((info = (mma_create_info_struct*) req->data) != NULL);

    if (info->delete_state > 0)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_DELETE_TASK_HDLR_FUNCTION,
                          "(mma_create.c): Duplicate mma_create_delete_task_hdlr(req %d, del state %d, env state %d)\n",
                          req_id, info->delete_state, g_mma_create_context.mma_create_env_state));
    }
    else
    {
        mma_create_delete_task(req);
    }
}

#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_init_mms
 * DESCRIPTION
 *  Initialize MMS the to-be-created MMS content
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_mms_init_mms(mma_create_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfSize size = mma_get_screen_size();



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(info->mms_dsr);
    info->header = (mma_header_struct*) MMA_CALLOC(sizeof(mma_header_struct));
    info->header->header.s_header = (MmsSetHeader*) MMA_CALLOC(sizeof(MmsSetHeader));
    info->header->header.s_header->contentType = (MmsContentType*) MMA_CALLOC(sizeof(MmsContentType));

     info->header->header.s_header->fromType = MMS_FROM_INSERT_ADDRESS;
    /* set date here before setting other time-related fields */
    info->header->header.s_header->date = MSF_TIME_GET_SECURE_CLOCK();
    info->header->s_version = mma_get_mms_version_from_em();

    info->mms_dsr->body = (mma_mms_description_body_struct*) MMA_CALLOC(sizeof(mma_mms_description_body_struct));
    /* Set the layout */
    info->root_layout.bgColor = MMA_CFG_SMIL_BG_COLOR;
    info->root_layout.cx.type = SLS_ABS;
    info->root_layout.cx.value = size.width;
    info->root_layout.cy.type = SLS_ABS;
    info->root_layout.cy.value = size.height;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mma_create_handle_rsp
 * DESCRIPTION
 *  handle response from other module
 * PARAMETERS
 *  sig             [IN]        
 *  sig_data        [IN]        
 * RETURNS
 *  TRUE: the response belongs to create FSM; FALSE: the response doesn't belong to create FSM
 *****************************************************************************/
kal_bool mma_create_handle_rsp(MSF_UINT16 sig, void *sig_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sig)
    {
        case MMS_SIG_CREATE_MSG_REPLY:
        {
            MmsMsgReplySig *data = (MmsMsgReplySig*) sig_data;

            if (g_mma_create_context.mma_create_task_queue != NULL)
            {
                mma_create_info_struct *info =
                    (mma_create_info_struct*) g_mma_create_context.mma_create_task_queue->data;
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_HANDLE_SIG_CREATE_MSG_REPLY,
                                  "(mma_create.c) MMS_SIG_CREATE_MSG_REPLY: req = %d, msg = %d, result = %d\n",
                                  info->req_id, info->msg_id, data->result));
                info->input = translate_mms_result_to_mma(data->result);
                if (info->input == MMA_RESULT_OK)
                {
                    if (info->storage_type == MMA_MSG_STORAGE_PHONE)
                    {
                        info->msg_id = data->msgId;
                    }
                    else
                    {
                        info->msg_id = mma_main_encode_msg_id(info->storage_type, data->msgId);
                    }
                }
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
        }

        case MMS_SIG_MSG_DONE_REPLY:
        {
            MmsMsgReplySig *data = (MmsMsgReplySig*) sig_data;

            if (g_mma_create_context.mma_create_task_queue != NULL)
            {
                mma_create_info_struct *info =
                    (mma_create_info_struct*) g_mma_create_context.mma_create_task_queue->data;
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_HANDLE_SIG_MSG_DONE_REPLY,
                                  "(mma_create.c) MMS_SIG_MSG_DONE_REPLY: req = %d, msg = %d, result = %d\n",
                                  info->req_id, info->msg_id, data->result));
                info->input = translate_mms_result_to_mma(data->result);
                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
        }

        case MSF_SIG_FILE_NOTIFY:
        {
            msf_file_notify_t *data = (msf_file_notify_t*) sig_data;

            if (g_mma_create_context.mma_create_task_queue != NULL)
            {
                mma_create_info_struct *info =
                    (mma_create_info_struct*) g_mma_create_context.mma_create_task_queue->data;
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_HANDLE_SIG_FILE_NOTIFY,
                                  "(mma_create.c) MSF_SIG_FILE_NOTIFY %d - %d", data->fileHandle,
                                  info->delayed_handle));
                if (data->fileHandle == info->delayed_handle)
                {
                    info->delayed_handle = -1;
                    return KAL_TRUE;
                }
                else
                {
                    return KAL_FALSE;
                }
            }
            else
            {
                return KAL_FALSE;
            }
        }

        default:
            return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_send_reject_rsp
 * DESCRIPTION
 *  mms_mma_create_rsp wrapper for response
 * PARAMETERS
 *  source              [IN]        
 *  req_id              [IN]        
 *  app_id              [IN]        
 *  msg_id              [IN]        
 *  buffer_index        [IN]        
 *  ret                 [IN]        
 * RETURNS
 *  TRUE: more XML content to be sent; FALSE: all XML content were read
 *****************************************************************************/
kal_bool mma_create_send_reject_rsp(
            kal_uint32 source,
            kal_uint32 req_id,
            kal_uint8 app_id,
            kal_uint32 msg_id,
            kal_uint32 buffer_index,
            mma_result_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_create_rsp_struct *rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wap_mma_create_rsp_struct*) MMA_CALLOC(sizeof(wap_mma_create_rsp_struct));
    rsp->app_id = app_id;
    rsp->result = ret;
    rsp->req_id = req_id;
    rsp->msg_id = msg_id;
    rsp->buffer_index = buffer_index;
    /*
     * only for Q05
     * if (rsp->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE && 
     * mma_msgmgr_get_total_msg_num() < wap_custom_get_max_mms_num())
     * {
     * rsp->min_fs_space_required = wap_custom_get_max_mms_msg_size() / MMA_1_KB_IN_BYTE;
     * }
     */
    mms_mma_send_create_rsp((module_type)source, rsp);
    MMA_FREE(rsp);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_send_rsp(MSF_UINT32 req_id, mma_result_enum result, MSF_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMA_SIGNAL_SENDTO_IUU(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_INT_CREATE_RSP, result, req_id, msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_encode_subject
 * DESCRIPTION
 *  Encode subject
 *  1. Apply application encoding setting
 *  2. Adjust string for IOT
 * PARAMETERS
 *  subject     [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_mms_encode_subject(MmsEncodedText *subject)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Adjust UTF8 subject */
    if ((NULL != subject->text) && (strlen(subject->text) > 0))
    {
        switch (MMA_CFG_SUBJECT_CHARSET)    /* Obey charset setting, so convert... */
        {
            case MMS_US_ASCII:
            {
                char *ascii_subject = NULL;
                long ascii_len = 0, utf8_len = 0;

                utf8_len = strlen(subject->text);
                if (0 != msf_charset_utf8_to_ascii(subject->text, &utf8_len, NULL, &ascii_len)) /* Get ASCII size */
                {
                    break;  /* skip */
                }

                ascii_subject = (char*)MMA_CALLOC(ascii_len + 1);
                if (0 != msf_charset_utf8_to_ascii(subject->text, &utf8_len, ascii_subject, &ascii_len))
                {
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_MMS_ENCODE_SUBJECT_CHARSET_ASCII_FAIL,
                                      "(%s) (%d) Subject conversion failed!\n", __FILE__, __LINE__));
                }
                else
                {
                    *(ascii_subject + ascii_len) = '\0';
                    MMA_FREE(subject->text);
                    subject->text = ascii_subject;
                    subject->charset = MMS_US_ASCII;
                }
                break;
            }

            case MMS_UTF8:
            {
                ASSERT(subject->charset == MMS_UTF8);

                /* When text is of only ascii characters, set charset from utf-8 to us-ascii */
                subject->charset = mma_is_ascii_string(subject->text) ? MMS_US_ASCII : MMS_UTF8;
                break;
            }

            default:
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA, MMA_CREATE_MMS_ENCODE_SUBJECT_CHARSET_UNSUPPORTED,
                                  "(%s) (%d) unsupported subject charset\n", __FILE__, __LINE__));
                ASSERT(0);
        }

        if (subject->charset == MMS_US_ASCII)
        {
            /* IOT: Use Text-string encoding.
               Should convert CRLF to space (RFC822: no CRLF for E-mail subject) 
               or it would cause confusion with Value-length Charset Text-string encoding */
            int i = 0, j = 0, ascii_len = 0;
            char *new_subject_p = msf_cmmn_strdup(MSF_MODID_MMA, subject->text);

            ascii_len = strlen(subject->text);
            while (i < ascii_len + 1)
            {
                if (*(new_subject_p + i) == 0xD && *(new_subject_p + i + 1) == 0xA)
                {
                    *(subject->text + j) = 0x20;
                    i++;
                }
                else if(*(new_subject_p + i) == 0xA)
                {
                    /* This is done with reference to CR MAUI_01205530
                    Now the category screen 5 will give only 0X0A for enter
                    Earlier it used to give "0X0D 0X0A" for enter*/
                    *(subject->text + j) = 0x20;
                }
                else
                {
                    *(subject->text + j) = *(new_subject_p + i);
                }
                i++;
                j++;
            }
            MMA_FREE(new_subject_p);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_create_smil
 * DESCRIPTION
 *  Create mms by specified information
 * PARAMETERS
 *  body        [IN]         
 *  buffer      [IN]        
 *  size        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static mma_result_enum mma_create_mms_create_smil(mma_create_info_struct *info, char **buffer, unsigned int *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *smil_buffer = NULL;
    mma_mms_slide_struct *curr;
    mma_result_enum ret = MMA_RESULT_OK;
   // mma_sls_region_list *region_list_node = body->regions;

    SlsRegion text_region;
    SlsRegion image_region;
    SlsCreateSmilHandle handle = NULL;

    SlsMediaObject *text_object;
    SlsMediaObject *image_object;
    SlsMediaObject *audio_object;
    SlsMediaObject *video_object;
    SlsMediaObject *ref_item_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mma_mms_description_body_struct *body = info->mms_dsr->body;
    *buffer = NULL;
    *size = 0;

    /* Set regions */
    text_region.position.cx.type = SLS_REL;
    text_region.position.cy.type = SLS_REL;
    text_region.size.cx.type = SLS_REL;
    text_region.size.cy.type = SLS_REL;
    text_region.fit = MMA_REGION_FIT_SCROLL;

    image_region.position.cx.type = SLS_REL;
    image_region.position.cy.type = SLS_REL;
    image_region.size.cx.type = SLS_REL;
    image_region.size.cy.type = SLS_REL;
    image_region.fit = MMA_REGION_FIT_MEET;
		/*body region are not inserted : so just translate the fit in body for image and text*/
   
           
    text_region.fit = (mma_region_fit_enum)body->text_fit;
            
            
    image_region.fit = (mma_region_fit_enum)body->image_fit;


    if (body->layout == MMA_LAYOUT_TEXT_AT_LEFT || body->layout == MMA_LAYOUT_IMAGE_AT_LEFT)    /* Landscape */
    {
        text_region.position.cy.value = 0;
        text_region.size.cy.value = 100;
        image_region.position.cy.value = 0;
        image_region.size.cy.value = 100;

        if (body->layout == MMA_LAYOUT_TEXT_AT_LEFT)
        {
            /* Text at left, image at right */
            text_region.position.cx.value = 0;
            text_region.size.cx.value = 50;
            image_region.position.cx.value = 50;
            image_region.size.cx.value = 50;
        }
        else if (body->layout == MMA_LAYOUT_IMAGE_AT_LEFT)
        {
            /* Image at left, text at right */
            text_region.position.cx.value = 50;
            text_region.size.cx.value = 50;
            image_region.position.cx.value = 0;
            image_region.size.cx.value = 50;
        }
    }
    else    /* Portrait */
    {
        text_region.position.cx.value = 0;
        text_region.size.cx.value = 100;
        image_region.position.cx.value = 0;
        image_region.size.cx.value = 100;

        if (body->layout == MMA_LAYOUT_TEXT_ON_TOP)
        {
            /* Text on top, image at the bottom */
            text_region.position.cy.value = 0;
            text_region.size.cy.value = 50;
            image_region.position.cy.value = 50;
            image_region.size.cy.value = 50;
        }
        else if (body->layout == MMA_LAYOUT_IMAGE_ON_TOP)
        {
            /* Image on top, text at the bottom */
            text_region.position.cy.value = 50;
            text_region.size.cy.value = 50;
            image_region.position.cy.value = 0;
            image_region.size.cy.value = 50;
        }
        else
        {
            /* Only one text or image region is displayed on each slide */
            text_region.position.cy.value = 0;
            text_region.size.cy.value = 100;
            image_region.position.cy.value = 0;
            image_region.size.cy.value = 100;
        }
    }

    /* Create the SMIL presentation */
    if (MMA_RESULT_OK != mma_smil_createSmil(MSF_MODID_MMA, &handle, &info->root_layout))
    {
        return MMA_RESULT_FAIL;
    }
    else if (MMA_RESULT_OK != mma_smil_createRegion(MSF_MODID_MMA, &handle, &image_region, MMA_CFG_IMAGE_REGION_NAME))
    {
        (void)mma_smil_cancelCreateSmil(MSF_MODID_MMA, &handle);
        return MMA_RESULT_FAIL;
    }
    else if (MMA_RESULT_OK != mma_smil_createRegion(MSF_MODID_MMA, &handle, &text_region, MMA_CFG_TEXT_REGION_NAME))
    {
        (void)mma_smil_cancelCreateSmil(MSF_MODID_MMA, &handle);
        return MMA_RESULT_FAIL;
    }

    /* Get the first slide */
    curr = body->slides;

    /* Go through all slides */
    while (NULL != curr && ret != MMA_RESULT_FAIL)
    {
        /* Text */
        text_object = mma_create_sls_object_from_mma_slide_object(SLS_OBJECT_TYPE_TEXT, curr);

        /* Image */
        image_object = mma_create_sls_object_from_mma_slide_object(SLS_OBJECT_TYPE_IMAGE, curr);

        /* Audio */
        audio_object = mma_create_sls_object_from_mma_slide_object(SLS_OBJECT_TYPE_AUDIO, curr);

        /* Video */
        video_object = mma_create_sls_object_from_mma_slide_object(SLS_OBJECT_TYPE_VIDEO, curr);

        /* Ref */
        ref_item_list = NULL;
        ref_item_list = mma_create_sls_object_list_from_mma_slide_object(SLS_OBJECT_TYPE_REF, curr);
		/*set the slide duration to MS */
		//curr->duration = curr->duration * MMA_1_SEC_IN_MSEC;
        /* Create the slide */
        if (MMA_RESULT_OK != mma_smil_createSlide(
                                MSF_MODID_MMA,
                                &handle,
                                (MSF_UINT32) curr->duration * MMA_1_SEC_IN_MSEC,
                                text_object,
                                image_object,
                                video_object,
                                audio_object,
                                ref_item_list))
        {
            (void)mma_smil_cancelCreateSmil(MSF_MODID_MMA, &handle);
            ret = MMA_RESULT_FAIL;
        }

        /* Free Text object */
        if (text_object != NULL)
        {
            mma_free_sls_media_object(&text_object);
        }
        /* Free Image object */
        if (image_object != NULL)
        {
            mma_free_sls_media_object(&image_object);
        }
        /* Free Audio object */
        if (audio_object != NULL)
        {
            mma_free_sls_media_object(&audio_object);
        }
        /* Free Video object */
        if (video_object != NULL)
        {
            mma_free_sls_media_object(&video_object);
        }
        /* Free Ref object */
        if (ref_item_list != NULL)
        {
        	mma_free_sls_media_object_list(&ref_item_list);
        }
        curr = curr->next;
    }

    if (ret != MMA_RESULT_FAIL)
    {
        if (MMA_RESULT_OK != mma_smil_generateSmil(MSF_MODID_MMA, &handle, (char **)&smil_buffer))
        {
            (void)mma_smil_cancelCreateSmil(MSF_MODID_MMA, &handle);
            ret = MMA_RESULT_FAIL;
        }
    }

    if (ret == MMA_RESULT_OK)
    {
        *buffer = smil_buffer;
        *size = strlen(smil_buffer);
    }
    return ret;
}   /* createSmil */


/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_replace_fta_subject
 * DESCRIPTION
 *  Replace the short-code text with FTA specified subject text
 * PARAMETERS
 *  subject     [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_mms_replace_fta_subject(MmsEncodedText *subject)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msf_cmmn_strcmp_nc(subject->text, "fta_sutf8") == 0)
    {
        const unsigned char mms_fta_sutf8[] = 
        {
            0x53, 0x68, 0xC3, 0xB5, 0x72, 0x74, 0x20, 0x54, 0xC3, 0xA9, 0x78, 0x74, 0x20, 0x2D, 0x20, 0xC2,
            0xA5, 0xC3, 0xBC, 0xC3, 0xAB, 0xC3, 0xA4, 0xC3, 0xBF, 0x00
        };

        MMA_FREE(subject->text);
        subject->text = msf_cmmn_strdup(MSF_MODID_MMA, (const char*)mms_fta_sutf8);
        /* subject->size = strlen(subject->text); */
        subject->charset = MMS_UTF8;
    }
    else if (msf_cmmn_strcmp_nc(subject->text, "fta_utf8_13") == 0)
    {
        const unsigned char mms_fta_utf8[] = 
        {
/*            0x46, 0x72, 0x65, 0x6E, 0x63, 0x68, 0x20, 0xC3, 0xAA, 0x20, 0x68, 0x61, 0x73, 0x20, 0x61, 0x20,
            0x72, 0x6F, 0x6F, 0x66, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x2E,
            0x20, 0x47, 0x65, 0x72, 0x6D, 0x61, 0x6E, 0x20, 0xC3, 0xBC, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20,
            0x75, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x77, 0x6F, 0x20, 0x64, 0x6F, 0x74, 0x73, 0x2E,
            0x20, 0x50, 0x6F, 0x6C, 0x69, 0x73, 0x68, 0x20, 0xC5, 0x82, 0x20, 0x69, 0x73, 0x20, 0x61, 0x6E,
            0x20, 0x6C, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x2F, 0x20, 0x61, 0x63, 0x72, 0x6F,
            0x73, 0x73, 0x2E, 0x00*/
			/* New text in 1.3 */
				0x46, 0x72, 0x65, 0x6E, 0x63, 0x68, 0x20, 0xC3, 0xAA, 0x20, 0x68, 0x61, 0x73, 0x20, 0x61, 0x20,
			0x72, 0x6F, 0x6F, 0x66, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x2E, 
			0x20, 0x47, 0x65, 0x72, 0x6D, 0x61, 0x6E, 0x20, 0xC3, 0xBC, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 
			0x75, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x77, 0x6F, 0x20, 0x64, 0x6F, 0x74, 0x73, 0x2E,
			0x20, 0x50, 0x6F, 0x72, 0x74, 0x75, 0x67, 0x75, 0x65, 0x73, 0x65, 0x20, 0xC3, 0xA3, 0x20, 0x69, 
			0x73, 0x20, 0x61, 0x6E, 0x20, 0x61, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x7E, 0x20, 
			0x28, 0x74, 0x69, 0x6C, 0x64, 0x65, 0x29, 0x20, 0x61, 0x62, 0x6F, 0x76, 0x65, 0x2E, 0x00
        };

        MMA_FREE(subject->text);
        subject->text = msf_cmmn_strdup(MSF_MODID_MMA, (const char*)mms_fta_utf8);
        /* subject->size = strlen(subject->text); */
        subject->charset = MMS_UTF8;
    }
    else if (msf_cmmn_strcmp_nc(subject->text, "fta_utf8_12") == 0)
    {
        const unsigned char mms_fta_utf8[] = 
        {
            0x46, 0x72, 0x65, 0x6E, 0x63, 0x68, 0x20, 0xC3, 0xAA, 0x20, 0x68, 0x61, 0x73, 0x20, 0x61, 0x20,
            0x72, 0x6F, 0x6F, 0x66, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x2E,
            0x20, 0x47, 0x65, 0x72, 0x6D, 0x61, 0x6E, 0x20, 0xC3, 0xBC, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20,
            0x75, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x77, 0x6F, 0x20, 0x64, 0x6F, 0x74, 0x73, 0x2E,
            0x20, 0x50, 0x6F, 0x6C, 0x69, 0x73, 0x68, 0x20, 0xC5, 0x82, 0x20, 0x69, 0x73, 0x20, 0x61, 0x6E,
            0x20, 0x6C, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x2F, 0x20, 0x61, 0x63, 0x72, 0x6F,
            0x73, 0x73, 0x2E, 0x00
        };

        MMA_FREE(subject->text);
        subject->text = msf_cmmn_strdup(MSF_MODID_MMA, (const char*)mms_fta_utf8);
        /* subject->size = strlen(subject->text); */
        subject->charset = MMS_UTF8;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_replace_fta_text
 * DESCRIPTION
 *  Replace the short-code text with FTA specified text
 * PARAMETERS
 *  obj         [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_mms_replace_fta_text(mma_mms_object_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, obj->file_path, MSF_FILE_SET_RDONLY, 0, MMA_MSG_STORAGE_PHONE);
    char *buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fh < 0)
    {
        return;
    }

    if (obj->is_virtual_file)
    {
        if (MSF_FILE_SEEK(fh, obj->offset, MSF_FILE_SEEK_SET) < 0)
        {
            MSF_FILE_CLOSE(fh);
            return;
        }
    }

    buffer = (char*)MMA_CALLOC(obj->size + 1);
    MSF_FILE_READ(fh, buffer, obj->size);
    MSF_FILE_CLOSE(fh);

    if (msf_cmmn_strcmp_nc(buffer, "fta_sutf8") == 0)
    {
        const unsigned char mms_fta_sutf8[] = 
        {
            0x53, 0x68, 0xC3, 0xB5, 0x72, 0x74, 0x20, 0x52, 0xC3, 0xA9, 0x78, 0x74, 0x20, 0x2D, 0x20, 0xC2,
            0xA5, 0xC3, 0xBC, 0xC3, 0xAB, 0xC3, 0xA4, 0xC3, 0xBF, 0x00
        };

        if ((fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, obj->file_path, MSF_FILE_SET_WRONLY, 0, MMA_MSG_STORAGE_PHONE)) >= 0)   /* overwrite */
        {
            MSF_FILE_WRITE(fh, (void*)mms_fta_sutf8, strlen((char*)mms_fta_sutf8) + 1);
            MSF_FILE_CLOSE(fh);
            obj->charset = MMS_UTF8;
            obj->size = strlen((char*)mms_fta_sutf8);
        }
    }
    else if (msf_cmmn_strcmp_nc(buffer, "fta_utf8_13") == 0)
    {
        const unsigned char mms_fta_utf[] = 
        {
/*            0x46, 0x72, 0x65, 0x6E, 0x63, 0x68, 0x20, 0xC3, 0xAA, 0x20, 0x68, 0x61, 0x73, 0x20, 0x61, 0x20,
            0x72, 0x6F, 0x6F, 0x66, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x2E,
            0x20, 0x47, 0x65, 0x72, 0x6D, 0x61, 0x6E, 0x20, 0xC3, 0xBC, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20,
            0x75, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x77, 0x6F, 0x20, 0x64, 0x6F, 0x74, 0x73, 0x2E,
            0x20, 0x50, 0x6F, 0x6C, 0x69, 0x73, 0x68, 0x20, 0xC5, 0x82, 0x20, 0x69, 0x73, 0x20, 0x61, 0x6E,
            0x20, 0x6C, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x2F, 0x20, 0x61, 0x63, 0x72, 0x6F,
            0x73, 0x73, 0x2E, 0x00 */
			/* New text in 1.3 */
				0x46, 0x72, 0x65, 0x6E, 0x63, 0x68, 0x20, 0xC3, 0xAA, 0x20, 0x68, 0x61, 0x73, 0x20, 0x61, 0x20,
			0x72, 0x6F, 0x6F, 0x66, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x2E, 
			0x20, 0x47, 0x65, 0x72, 0x6D, 0x61, 0x6E, 0x20, 0xC3, 0xBC, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 
			0x75, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x77, 0x6F, 0x20, 0x64, 0x6F, 0x74, 0x73, 0x2E,
			0x20, 0x50, 0x6F, 0x72, 0x74, 0x75, 0x67, 0x75, 0x65, 0x73, 0x65, 0x20, 0xC3, 0xA3, 0x20, 0x69, 
			0x73, 0x20, 0x61, 0x6E, 0x20, 0x61, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x7E, 0x20, 
			0x28, 0x74, 0x69, 0x6C, 0x64, 0x65, 0x29, 0x20, 0x61, 0x62, 0x6F, 0x76, 0x65, 0x2E, 0x00
        };

        if ((fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, obj->file_path, MSF_FILE_SET_WRONLY, 0, MMA_MSG_STORAGE_PHONE)) >= 0)   /* overwrite */
        {
            MSF_FILE_WRITE(fh, (void*)mms_fta_utf, strlen((char*)mms_fta_utf) + 1);
            MSF_FILE_CLOSE(fh);
            obj->charset = MMS_UTF8;
            obj->size = strlen((char*)mms_fta_utf);
        }
    }
    else if (msf_cmmn_strcmp_nc(buffer, "fta_utf8_12") == 0)
    {
        const unsigned char mms_fta_utf[] = 
        {
            0x46, 0x72, 0x65, 0x6E, 0x63, 0x68, 0x20, 0xC3, 0xAA, 0x20, 0x68, 0x61, 0x73, 0x20, 0x61, 0x20,
            0x72, 0x6F, 0x6F, 0x66, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x2E,
            0x20, 0x47, 0x65, 0x72, 0x6D, 0x61, 0x6E, 0x20, 0xC3, 0xBC, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20,
            0x75, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x77, 0x6F, 0x20, 0x64, 0x6F, 0x74, 0x73, 0x2E,
            0x20, 0x50, 0x6F, 0x6C, 0x69, 0x73, 0x68, 0x20, 0xC5, 0x82, 0x20, 0x69, 0x73, 0x20, 0x61, 0x6E,
            0x20, 0x6C, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x61, 0x20, 0x2F, 0x20, 0x61, 0x63, 0x72, 0x6F,
            0x73, 0x73, 0x2E, 0x00 
        };

        if ((fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, obj->file_path, MSF_FILE_SET_WRONLY, 0, MMA_MSG_STORAGE_PHONE)) >= 0)   /* overwrite */
        {
            MSF_FILE_WRITE(fh, (void*)mms_fta_utf, strlen((char*)mms_fta_utf) + 1);
            MSF_FILE_CLOSE(fh);
            obj->charset = MMS_UTF8;
            obj->size = strlen((char*)mms_fta_utf);
        }
    }
    else if (msf_cmmn_strcmp_nc(buffer, "fta_usascii") == 0)
    {
        const unsigned char mms_fta_usascii[] = 
        {
            0x54,
            0x68, 0x65, 0x20, 0x71, 0x75, 0x69, 0x63, 0x6B, 0x20, 0x62, 0x72, 0x6F, 0x77, 0x6E, 0x20, 0x66,
            0x6F, 0x78, 0x20, 0x6A, 0x75, 0x6D, 0x70, 0x65, 0x64, 0x20, 0x6F, 0x76, 0x65, 0x72, 0x20, 0x74,
            0x68, 0x65, 0x20, 0x6C, 0x61, 0x7A, 0x79, 0x20, 0x64, 0x6F, 0x67, 0x20, 0x31, 0x32, 0x33, 0x34,
            0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2F, 0x21, 0x28, 0x29, 0x0D, 0x0A, 0x00
        };

        if ((fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, obj->file_path, MSF_FILE_SET_WRONLY, 0, MMA_MSG_STORAGE_PHONE)) >= 0)   /* overwrite */
        {
            MSF_FILE_WRITE(fh, (void*)mms_fta_usascii, strlen((char*)mms_fta_usascii) + 1);
            MSF_FILE_CLOSE(fh);
            obj->charset = MMS_US_ASCII;
            obj->size = strlen((char*)mms_fta_usascii);
        }
    }
    MMA_FREE(buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_mms_validate_mms_info
 * DESCRIPTION
 *  Initialize MMS the to-be-created MMS content
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_mms_validate_mms_info(mma_create_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mma_mms_object_struct *obj = NULL;
    MsfSize size = mma_get_screen_size();

/* #ifdef __MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM__
    extern char g_mms_owner_number[MMA_MAX_ADDR_LEN];
  #endif */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*chetan*/
    //info->header = (mma_header_struct*) MMA_CALLOC(sizeof(mma_header_struct));
    //info->header->header.s_header = (MmsSetHeader*) MMA_CALLOC(sizeof(MmsSetHeader));
	ASSERT(info->mms_dsr->header);
	ASSERT(info->mms_dsr->header->header);

    info->header = (mma_header_struct*) MMA_CALLOC(sizeof(mma_header_struct));
    info->header->header.s_header = (MmsSetHeader*) MMA_CALLOC(sizeof(MmsSetHeader));
    info->header->header.s_header->contentType = (MmsContentType*) MMA_CALLOC(sizeof(MmsContentType));


        info->header->header.s_header->fromType = MMS_FROM_INSERT_ADDRESS;
    /* set date here before setting other time-related fields */
    info->header->header.s_header->date = MSF_TIME_GET_SECURE_CLOCK();
    info->header->s_version = mma_get_mms_version_from_em();

	/*copy MMS header from app  to MmsSetHeader */
	(void)mma_copy_app_to_mms_header(info->mms_dsr->header->header, info->header);

	if(info->mode != MMA_MODE_FORWARD && info->mode != MMA_MODE_SEND && info->mode != MMA_MODE_HEADER)
	{
    ASSERT(info->mms_dsr->body);
		//ASSERT(info->mms_dsr->body->slide_no == mma_get_mms_slide_count(info->mms_dsr->body));
    //ASSERT(info->mms_dsr->body->obj_no = mma_get_total_item_count(info->mms_dsr->body));
	}
	if(info->mode != MMA_MODE_RAW && info->mms_dsr->body)
	{
    obj = info->mms_dsr->body->objects;
    while (obj && obj->drm_type == MMA_DRM_NONE)
      {		
	/*chetan : convert UCS2 to UTF8 string names to ascii*/
		//obj->file_name = mma_ucs2_to_utf8_string(obj->file_name);
		//obj->file_path = mma_ucs2_to_utf8_string(obj->file_path);
		obj->mime_str = msf_cmmn_strdup(MSF_MODID_MMA, mma_get_mime_type_from_filename_and_type(obj->file_name, MIME_TYPE_NONE));
		obj = obj->next;
   	  }
	}
 	mma_create_process_mms_info(info);
    /* Set the layout */
	if(info->mms_dsr->body->bgColor != MMA_CFG_SMIL_BG_COLOR )
	{
		info->root_layout.bgColor = info->mms_dsr->body->bgColor;	
	}
	else
	{
                info->root_layout.bgColor = MMA_CFG_SMIL_BG_COLOR;
	}
    info->root_layout.cx.type = SLS_ABS;
    info->root_layout.cx.value = size.width;
    info->root_layout.cy.type = SLS_ABS;
    info->root_layout.cy.value = size.height;

}


/*****************************************************************************
 * FUNCTION
 *  mma_create_fsm
 * DESCRIPTION
 *  Create mms by specified information
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mma_create_action_enum mma_create_fsm(mma_create_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsSetHeader *s_header = NULL;
    mma_create_action_enum action = MMA_CREATE_ACTION_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(info != NULL);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_FSM_FUNCTION_ENTER,
                      "(mma_create.c) State:%d - SubS:%d: req = %d, msg = %d, input = %d\n", info->state,
                      info->sub_state, info->req_id, info->msg_id, info->input));
    if (info->input != MMA_RESULT_OK && info->state != MMA_CREATE_STATE_FINISHED)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_FSM_ERROR_CHANGE_STATE_FINISHING,
                           "(mma_create.c) state -> MMA_CREATE_STATE_FINISHING\n"));
        info->state = MMA_CREATE_STATE_FINISHING;
    }

    mma_check_and_sleep();

    switch (info->state)
    {
        case MMA_CREATE_STATE_STARTED:
        {

            if (info->mode == MMA_MODE_UPLOAD)
            {
                info->input = MMA_RESULT_OK;
                info->state = MMA_CREATE_STATE_CREATING;
                action = MMA_CREATE_ACTION_CONTINUE;
                break;
            }
#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
			if(info->mode == MMA_MODE_VENDOR_XML)
			{
			
				info->input = MMA_RESULT_OK;
				/*info->mode  = MMA_MODE_EDIT;*/
                info->state = MMA_CREATE_STATE_XML_PARSING;
                action = MMA_CREATE_ACTION_CONTINUE;
				break;
				
			}
				
#endif	/* __MMI_MMS_VENDOR_APP_SUPPORT__ */

        }
            /* fall-through */
        case MMA_CREATE_STATE_MMS_INFO_VALIDATING:
        {
            mma_create_mms_validate_mms_info(info);

			info->state = MMA_CREATE_STATE_CREATION_PREPROCESSING;
            info->input = MMA_RESULT_OK;
            action = MMA_CREATE_ACTION_CONTINUE;
            break;
        }

#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
        case MMA_CREATE_STATE_XML_PARSING:
        {
            mma_create_mms_init_mms(info);
            if (mma_xml_parse_mms_description_file(info) == MMA_RESULT_OK)
            {
                info->state = MMA_CREATE_STATE_CREATION_PREPROCESSING;
                info->input = MMA_RESULT_OK;
                action = MMA_CREATE_ACTION_DELAYED;
                MMA_SIGNAL_SENDTO_U(MMA_SUBMODULE_MSG_CREATE, MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND, info->req_id);
            }
            else
            {
                info->input = MMA_RESULT_FAIL_PARSE;
                info->state = MMA_CREATE_STATE_FINISHING;
                action = MMA_CREATE_ACTION_CONTINUE;
            }
            break;
        }
#endif

        case MMA_CREATE_STATE_CREATION_PREPROCESSING:
        {
            mma_mms_object_struct *obj = NULL;
            (void)mma_create_process_parsed_info(info);
		   if(info->mms_dsr->body)
		   {
            obj = info->mms_dsr->body->objects;
            while (obj)
            {

                /* need to rename like in case of chinese name or non ascii name */
                if (mma_is_ascii_string(obj->file_name) == KAL_FALSE)
                {
					ASSERT(0);/*application must not give non ascii names is because MMA can't
							  free the application memory and convert to ascii names */
                }
                obj = obj->next;
            }
		   }
            info->state = MMA_CREATE_STATE_CREATING;
            info->input = MMA_RESULT_OK;
            action = MMA_CREATE_ACTION_CONTINUE;
            break;
        }

        case MMA_CREATE_STATE_CREATING:
        {
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if ((info->mode == MMA_MODE_EDIT || 
                info->mode == MMA_MODE_POSTCARD) &&
                info->o_msg_id != 0)
            {
                MMSif_createMessage(MSF_MODID_MMA, info->msg_filetype, (kal_uint8)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type), TRUE);
            }
            else
#endif
            {
                MMSif_createMessage(MSF_MODID_MMA, info->msg_filetype, (kal_uint8)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type), FALSE);
            }
            switch (info->mode)
            {
                case MMA_MODE_UPLOAD:
                    info->state = MMA_CREATE_STATE_UPLOADED_MMS_RENAMING;
                    break;
                case MMA_MODE_SEND:
                case MMA_MODE_FORWARD:
                    info->state = MMA_CREATE_STATE_OLD_MMS_INFO_GETTING;
                    break;
                default:
                    info->state = MMA_CREATE_STATE_MMS_HEADER_CREATING;
                    break;
            }
            action = MMA_CREATE_ACTION_DELAYED;
            break;
        }

        case MMA_CREATE_STATE_UPLOADED_MMS_RENAMING:
        {
            char *path = (char*)MMSlib_getMessageFullPath(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(info->msg_id), info->msg_filetype);

            MSF_FILE_REMOVE_EXT(path, (msf_mms_storage_enum)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type));

            if (MSF_FILE_RENAME_EXT(info->upload_filepath, path, 
                (msf_mms_storage_enum)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type)) < 0)
            {

                if (MSF_FILE_MOVE_EXT1(info->upload_filepath, MSF_MMS_STORAGE_NONE, path, 
                    (msf_mms_storage_enum)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type)) < 0)
                {
                    MMA_FREE(path);
                    info->input = MMA_RESULT_FAIL;
                    info->state = MMA_CREATE_STATE_FINISHING;
                    action = MMA_CREATE_ACTION_CONTINUE;
                    break;
                }
                else
                {
                    /* File Move Succeed Remove the src file*/
             		MSF_FILE_REMOVE_EXT(info->upload_filepath, MSF_MMS_STORAGE_NONE);
                }
            }
            MMA_FREE(path);
            info->input = MMA_RESULT_OK;
            info->state = MMA_CREATE_STATE_MMS_INFO_CREATING;
            action = MMA_CREATE_ACTION_CONTINUE;
            break;
        }

        case MMA_CREATE_STATE_OLD_MMS_INFO_GETTING:
        {
            /* used only to know the Suffix. Get it from MSGMGR */
            kal_uint8 suffix = 	mma_msgmgr_get_msg_suffix(info->o_msg_id);
            if((suffix == MMS_SUFFIX_TEMPLATE) || (suffix == MMS_SUFFIX_SEND_REQ) || (suffix == MMS_SUFFIX_MSG))
            {
                info->input = MMA_RESULT_OK;
            }
            else
            {
                info->input = MMA_RESULT_FAIL_INVALID_MSGID;
            }
            info->state = MMA_CREATE_STATE_OLD_MMS_BODY_HEADER_PARSING;
            info->sub_state = 0;
            action = MMA_CREATE_ACTION_CONTINUE;
            break;
        }

        case MMA_CREATE_STATE_OLD_MMS_BODY_HEADER_PARSING:
        {
            switch (info->sub_state)
            {
                case 0:
                {
                    if ((info->input = translate_mms_result_to_mma(MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle))) != MMA_RESULT_OK)
                    {
                        info->state = MMA_CREATE_STATE_FINISHING;
                        //info->input = translate_mms_result_to_mma(info->input);
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }
                    else if ((info->input = translate_mms_result_to_mma(MMSlib_messageOpen(MSF_MODID_MMA, 
                             MMA_TRANSLATE_MSG_ID(info->o_msg_id),
                             (MmsFileType)mma_msgmgr_get_msg_suffix(info->o_msg_id),
                             &info->m_handle,
                             (kal_uint8)mma_get_mms_type_message_storage(info->o_msg_id)))) != MMA_RESULT_OK)
                    {
                        (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                        info->state = MMA_CREATE_STATE_FINISHING;
                        //info->input = translate_mms_result_to_mma(info->input);                        
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }
                    /*else if (info->header == NULL)
                    {
                        info->state = MMA_PARSE_STATE_MMS_HEADER_PARSING;
                    }*/
                    info->o_header = (MmsGetHeader*) MMA_CALLOC(sizeof(MmsGetHeader));
                    ASSERT(info->o_header != NULL);
                    info->sub_state = 1;
                }
                case 1:
                {
                    info->input = translate_mms_result_to_mma(MMSlib_getMessageHeaderExt(
                                    MSF_MODID_MMA,
                                    info->o_header,
                                    &info->m_handle,
                                    &info->t_handle,
                                    BODY_HEADERS));
                    if (MMA_RESULT_OK != info->input)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_GET_MESSAGE_BODY_HEADER_ERROR,
                                          "(mma_create.c) MMSlib_getBodyHeader() %d\n", info->input));
                        if (info->input == MMA_RESULT_DELAYED)
                        {
                            MmsTransaction *t = (MmsTransaction*) info->t_handle;

                            info->delayed_handle = t->fileHandle;
                            info->input = MMA_RESULT_OK;
                            action = MMA_CREATE_ACTION_DELAYED;
                        }
                        else
                        {
                            (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
                            (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                            //info->input = translate_mms_result_to_mma(info->input);
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                        }
                        break;
                    }
                    (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
                    (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                    MMA_SIGNAL_SENDTO_U(
                        MMA_SUBMODULE_MSG_CREATE,
                        MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND,
                        info->req_id);
                    info->o_body_header = &(info->o_header->bodyInfoList);
                    info->state = MMA_CREATE_STATE_MMS_HEADER_CREATING;
                    action = MMA_CREATE_ACTION_DELAYED;
                    info->sub_state = 0;
                    break;
                }
            }
            break;
        }

        case MMA_CREATE_STATE_MMS_HEADER_CREATING:
        {
            ASSERT(info->msg_id != 0 && info->header != NULL && info->header->header.s_header != NULL &&
                   info->header->header.s_header->contentType != NULL);
            s_header = info->header->header.s_header;

            /* Here, sub_state is used to handle delayed file I/O */
            switch (info->sub_state)
            {
                case 0:
                {
                    /* Set body_no, contentType, subject */
                    if (info->mode == MMA_MODE_SEND || info->mode == MMA_MODE_FORWARD)
                    {
                        info->header->body_no = info->o_body_header->numOfEntries;
                        copyContentType(MSF_MODID_MMA, s_header->contentType, info->o_header->bodyInfoList.contentType);
                    }
                    else if (info->mode == MMA_MODE_RAW)
                    {
                        info->header->body_no = mma_get_total_item_count(info->mms_dsr->body);
                        if (mma_get_presentation_from_params(s_header->contentType->params) != NULL)
                        {
                            s_header->contentType->knownValue = MMS_VND_WAP_MULTIPART_RELATED;
                        }
                        else    /* Mixed: multipart.mixed */
                        {
                            s_header->contentType->knownValue = MMS_VND_WAP_MULTIPART_MIXED;
                        }
                    }
                    else if (info->mode == MMA_MODE_POSTCARD)
                    {
                        info->header->body_no = mma_get_total_item_count(info->mms_dsr->body);
#ifdef __MMI_MMS_POSTCARD_WITH_OUT_SMIL__
                        s_header->contentType->knownValue = MMS_VND_WAP_MULTIPART_MIXED;
#else
                        s_header->contentType->knownValue = MMS_VND_WAP_MULTIPART_RELATED;
#endif
                    }
                    else if(info->mode == MMA_MODE_MIXED)
                    {
                        // This is Done for fault tolerance
                        info->header->body_no = mma_get_total_item_count(info->mms_dsr->body);
                        s_header->contentType->knownValue = MMS_VND_WAP_MULTIPART_MIXED;
                    }
                    else
                    {
                        info->header->body_no = mma_get_total_item_count(info->mms_dsr->body);
                        if (info->mms_dsr->body->slide_no > 0)   /* SMIL: multipart.related */
                        {
                            info->header->body_no++;    /* Add SMIL presentation part */
                            s_header->contentType->knownValue = MMS_VND_WAP_MULTIPART_RELATED;
                            mma_add_param_string(
                                &s_header->contentType->params,
                                MMS_START_REL,
                                NULL,
                                MMA_CFG_SMIL_CONTENT_ID);
                            mma_add_param_string(
                                &s_header->contentType->params,
                                MMS_TYPE_REL,
                                NULL,
                                MMS_MEDIA_TYPE_STRING_SMIL);
                        }
                        else    /* Mixed: multipart.mixed */
                        {
                            s_header->contentType->knownValue = MMS_VND_WAP_MULTIPART_MIXED;
                        }
                    }

                #ifdef __GEMINI__
                    if (is_test_sim(l4c_gemini_get_switched_sim_id(SIM1)))
                #else 
                    if (is_test_sim())
                #endif 
                    {
                        mma_create_mms_replace_fta_subject(&s_header->subject);
                    }
                    mma_create_mms_encode_subject(&s_header->subject);  /* adjust subject string */

                    if ((info->input = translate_mms_result_to_mma(MMSlib_messageOpen(
                                        MSF_MODID_MMA,
                                        MMA_TRANSLATE_MSG_ID(info->msg_id),
                                        info->msg_filetype,
                                        &info->m_handle,
                                        (kal_uint8)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type)))) != MMA_RESULT_OK)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_GET_MESSAGE_OPEN_ERROR,
                                          "(mma_create.c) MMSlib_messageOpen() %d\n", info->input));
                        //info->input = translate_mms_result_to_mma(info->input);
                        info->state = MMA_CREATE_STATE_FINISHING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }
                    else if ((info->input = translate_mms_result_to_mma(MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle))) != MMS_RESULT_OK)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_GET_MESSAGE_TRANSACTION_ERROR,
                                          "(mma_create.c) MMSlib_transactionOpen() %d\n", info->input));
                        //info->input = translate_mms_result_to_mma(info->input);
                        info->state = MMA_CREATE_STATE_FINISHING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }

                    info->sub_state = 1;
                }
                    /* fall through */

                case 1:
                {
                    /* write msg header; may re-enter... */
                    info->input = translate_mms_result_to_mma(MMSlib_setMessageHeader(
                                    MSF_MODID_MMA,
                                    info->header->body_no,
                                    s_header,
                                    info->header->s_version,
                                    &info->m_handle,
                                    &info->t_handle));
                    if (MMA_RESULT_OK != info->input)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_SET_MESSAGE_HEADER_ERROR,
                                          "(mma_create.c) MMSlib_setMessageHeader() %d\n", info->input));
                        if (info->input == MMA_RESULT_DELAYED)
                        {
                            MmsTransaction *t = (MmsTransaction*) info->t_handle;

                            info->delayed_handle = t->fileHandle;
                            info->input = MMA_RESULT_OK;
                            action = MMA_CREATE_ACTION_DELAYED;
                        }
                        else
                        {
                           //info->input = translate_mms_result_to_mma(info->input);
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                        }
                        break;
                    }
                    (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                    info->sub_state = 2;
                }

                    /* fall through */
                case 2:
                {
                    if (info->mode == MMA_MODE_SEND || info->mode == MMA_MODE_FORWARD)
                    {
                        info->input = MMA_RESULT_OK;
                        info->state = MMA_CREATE_STATE_MMS_BODY_COPYING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                    }
                    else if (info->mode == MMA_MODE_RAW ||
                             s_header->contentType->knownValue == MMS_VND_WAP_MULTIPART_MIXED)
                    {
                        info->mms_dsr->body->curr_object = info->mms_dsr->body->objects;
                        info->input = MMA_RESULT_OK;
                        info->state = MMA_CREATE_STATE_MMS_BODY_CREATING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                    }
                    else
                    {
                        info->input = MMA_RESULT_OK;
                        info->state = MMA_CREATE_STATE_MMS_SMIL_CREATING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                    }
                    info->sub_state = 0;
                }
            }
            break;
        }

        case MMA_CREATE_STATE_MMS_BODY_COPYING:
        {
            long fs_result = 0;

            switch (info->sub_state)
            {
                case 0:
                {
                    char *r_path = NULL;

                    ASSERT(info->r_handle == -1 && info->w_handle == -1);
                    r_path = (char*)MMAlib_getMessagePath(MSF_MODID_MMA, info->o_msg_id);

                    info->r_handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, r_path, MSF_FILE_SET_RDONLY, 0, mma_get_message_storage(info->o_msg_id));
                    MMA_FREE(r_path);
                    if (info->r_handle < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_READ_FILE_OPEN_ERROR,
                                          "(mma_create.c) info->r_handle %d < 0\n", info->r_handle));
                        info->input = translate_fs_result_to_mma(info->r_handle);
                        info->state = MMA_CREATE_STATE_FINISHING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }

                    info->w_handle = ((MmsMessage*) (info->m_handle))->fileHandle;
                    if (info->w_handle < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_WRITE_FILE_OPEN_ERROR,
                                          "(mma_create.c) info->w_handle %d < 0\n", info->w_handle));
                        info->input = translate_fs_result_to_mma(info->w_handle);
                        info->state = MMA_CREATE_STATE_FINISHING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }

                    info->sub_state = 1;
                    /* fall through */
                }

                case 1:
                {
                    /* Copy SMIL or Multipart/Mixed message content: skip the nEntries field because it's already added by 
                       MMSlib_setMessageHeader(). */
                    if (info->header->body_no > 0)
                    {
                        kal_uint8 skip_bytes = mma_get_uintvar_length_bytes(info->header->body_no);

                        info->r_byte = info->o_body_header->size - skip_bytes;
                        if ((fs_result = MSF_FILE_SEEK(
                                            info->r_handle,
                                            info->o_body_header->startPos + skip_bytes,
                                            MSF_FILE_SEEK_SET)) < 0)
                        {
                            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                              MMA_CREATE_FILE_SEEK_FS_RESULT,
                                              "(mma_create.c %d) MSF_FILE_SEEK() %d < 0\n", __LINE__, fs_result));
                            info->input = translate_fs_result_to_mma(fs_result);
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                            break;
                        }
                    }
                    else    /* Text/Plain Message, just copy */
                    {
                        info->r_byte = info->o_body_header->size;
                        if ((fs_result = MSF_FILE_SEEK(info->r_handle, info->o_body_header->startPos, MSF_FILE_SEEK_SET)) < 0)
                        {
                            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                              MMA_CREATE_FILE_SEEK_FS_RESULT,
                                              "(mma_create.c %d) MSF_FILE_SEEK() %d < 0\n", __LINE__, fs_result));
                            info->input = translate_fs_result_to_mma(fs_result);
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                            break;
                        }
                    }

                    if ((fs_result = MSF_FILE_SEEK(info->w_handle, 0, MSF_FILE_SEEK_END)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_FILE_SEEK_FS_RESULT,
                                          "(mma_create.c %d) MSF_FILE_SEEK() %d < 0\n", __LINE__, fs_result));
                        info->input = translate_fs_result_to_mma(fs_result);
                        info->state = MMA_CREATE_STATE_FINISHING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }

                    info->w_byte = info->r_byte;
                    info->sub_state = 2;
                }

                    /* fall through */
                case 2:
                {
                    info->mo_buffer_size = (info->r_byte < MMS_MAX_CHUNK_SIZE) ? info->r_byte : MMS_MAX_CHUNK_SIZE;
                    info->mo_buffer = (char*)MMA_CALLOC(info->mo_buffer_size);
                    if ((fs_result = MSF_FILE_READ(info->r_handle, info->mo_buffer, info->mo_buffer_size)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_MMS_BODY_COPYING_READ_ERROR,
                                          "(mma_create.c): MMA_CREATE_STATE_MMS_BODY_COPYING read error %d",
                                          fs_result));
                        if ((info->input = translate_fs_result_to_mma(fs_result)) == MMA_RESULT_DELAYED)
                        {
                            MSF_FILE_SELECT(info->r_handle, MSF_FILE_EVENT_READ);
                            info->delayed_handle = info->r_handle;
                            MMA_FREE(info->mo_buffer);
                            info->input = MMA_RESULT_OK;
                            action = MMA_CREATE_ACTION_DELAYED;
                        }
                        else
                        {
                            MMA_FREE(info->mo_buffer);
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                        }
                        break;
                    }

                    info->mo_buffer_size = fs_result;
                    info->r_byte -= info->mo_buffer_size;
                    info->sub_state = 3;
                    /* fall through */
                }

                case 3:
                {
                    if ((fs_result = MSF_FILE_WRITE(info->w_handle, info->mo_buffer, info->mo_buffer_size)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_MMS_BODY_COPYING_WRITE_ERROR,
                                          "(mma_create.c) MMA_CREATE_STATE_MMS_BODY_COPYING write error %d",
                                          fs_result));
                        if ((info->input = translate_fs_result_to_mma(fs_result)) == MMA_RESULT_DELAYED)
                        {
                            MSF_FILE_SELECT(info->w_handle, MSF_FILE_EVENT_WRITE);
                            info->delayed_handle = info->w_handle;
                            info->input = MMA_RESULT_OK;
                            action = MMA_CREATE_ACTION_DELAYED;
                        }
                        else
                        {
                            MMA_FREE(info->mo_buffer);
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                        }
                        break;
                    }
                    else if(fs_result < info->mo_buffer_size)
                    {
                        /* Fail to write complete buffer*/ 
                        char* temp_buffer = NULL;
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_MMS_BODY_COPYING_WRITE_ERROR,
                                          "(mma_create.c) MMA_CREATE_STATE_MMS_BODY_COPYING write error %d",
                                          fs_result));

                        info->mo_buffer_size -= fs_result;

                        temp_buffer = (char*)MMA_CALLOC(info->mo_buffer_size);

                        memcpy(temp_buffer, (char*)(info->mo_buffer + fs_result), info->mo_buffer_size);

                        MMA_FREE(info->mo_buffer);

                        info->mo_buffer = temp_buffer;

                        info->w_byte -= fs_result;
                        action = MMA_CREATE_ACTION_DELAYED;                

                        MMA_SIGNAL_SENDTO_U(
                            MMA_SUBMODULE_MSG_CREATE,
                            MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND,
                            info->req_id);

                        break;
                    }
                    info->w_byte -= info->mo_buffer_size;
                    if (info->r_byte == 0 && info->w_byte == 0) /* Copy done! */
                    {
                        if (info->o_body_header != NULL)
                        {
                            info->o_body_header = NULL;
                        }
						if (info->o_header != NULL)
						{
                            /* To Reduce memory usages. */
							MMSlib_freeMmsGetHeader(MSF_MODID_MMA, info->o_header);
							MMA_FREE(info->o_header);
							info->o_header = NULL;
						}

                        MMA_FREE(info->mo_buffer);
                        MSF_FILE_CLOSE(info->r_handle);
                        info->r_handle = -1;
                        info->w_handle = -1;
                        info->input = MMA_RESULT_OK;
                        info->state = MMA_CREATE_STATE_MMS_INFO_CREATING;
                        info->sub_state = 0;
                        action = MMA_CREATE_ACTION_CONTINUE;
                    }
                    else
                    {
                        /* We don't finish all I/O at one time, but divide as several rounds... */
                        MMA_SIGNAL_SENDTO_U(
                            MMA_SUBMODULE_MSG_CREATE,
                            MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND,
                            info->req_id);
                        MMA_FREE(info->mo_buffer);
                        info->sub_state = 2;    /* read next portion */
                        action = MMA_CREATE_ACTION_DELAYED;
                    }
                    break;
                }
            }
            break;
        }

        case MMA_CREATE_STATE_MMS_SMIL_CREATING:
        {
            switch (info->sub_state)
            {
                case 0:
                {
                    if ((info->input = mma_create_mms_create_smil(
                                        info,
                                        (char **)&info->mo_buffer,
                                        &info->mo_buffer_size)) != MMA_RESULT_OK)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_MMS_SMIL_CREATING_ERROR,
                                          "(mma_create.c) mma_create_mms_create_smil %d\n", info->input));
                        info->state = MMA_CREATE_STATE_FINISHING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }
                    else if ((info->mo_param = mma_create_body_params(MMS_VALUE_AS_STRING, (char*)MMS_MEDIA_TYPE_STRING_SMIL, (char*)MMA_CFG_SMIL_FILE_NAME, (char*)MMA_CFG_SMIL_CONTENT_ID, (char*)MMA_CFG_SMIL_FILE_NAME, MMS_UTF8)) == NULL)     /* Create body params */
                    {
                        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                           MMA_CREATE_MMS_SMIL_CREATING_BODY_PARAM_ERROR,
                                           "(mma_create.c) mma_create_body_params failed\n"));
                        MMA_FREE(info->mo_buffer);
                        info->input = MMA_RESULT_FAIL;
                        info->state = MMA_CREATE_STATE_FINISHING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }
                    else if ((info->input = translate_mms_result_to_mma(MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle))) != MMA_RESULT_OK)   /* Write message */
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_MMS_SMIL_CREATING_BODY_PARAM_TRANSACTION_ERROR,
                                          "(mma_create.c) MMSlib_transactionOpen %d\n", info->input));
                        MMA_FREE(info->mo_buffer);
                        mma_free_body_params(&info->mo_param);
                        //info->input = translate_mms_result_to_mma(info->input);
                        info->state = MMA_CREATE_STATE_FINISHING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }
                    info->sub_state = 1;
                }
                    /* fall-through */

                case 1:
                {
                    if ((info->input = translate_mms_result_to_mma(MMSlib_setMessageBody(
                                        MSF_MODID_MMA,
                                        info->mo_param,
                                        (unsigned char*)info->mo_buffer,
                                        info->mo_buffer_size,
                                        &info->m_handle,
                                        &info->t_handle))) != MMA_RESULT_OK)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_SET_MSG_BODY_ERROR,
                                          "(mma_create.c) MMSlib_setMessageBody %d\n", info->input));
                        if (info->input == MMA_RESULT_DELAYED)
                        {
                            MmsTransaction *t = (MmsTransaction*) info->t_handle;

                            info->delayed_handle = t->fileHandle;
                            info->input = MMA_RESULT_OK;
                            action = MMA_CREATE_ACTION_DELAYED;
                        }
                        else
                        {
                            MMA_FREE(info->mo_buffer);
                            mma_free_body_params(&info->mo_param);
                            //info->input = translate_mms_result_to_mma(info->input);
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                        }
                        break;
                    }

                    MMA_FREE(info->mo_buffer);
                    mma_free_body_params(&info->mo_param);
                    if ((info->input = translate_mms_result_to_mma(MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle))) != MMA_RESULT_OK)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                          MMA_CREATE_MSG_BODY_TRANSACTION_CLOSE_ERROR,
                                          "(mma_create.c) MMSlib_transactionClose %d\n", info->input));
                        //info->input = translate_mms_result_to_mma(info->input);
                        info->state = MMA_CREATE_STATE_FINISHING;
                        action = MMA_CREATE_ACTION_CONTINUE;
                        break;
                    }

                    info->mms_dsr->body->curr_object = info->mms_dsr->body->objects;
                    info->input = MMA_RESULT_OK;
                    info->state = MMA_CREATE_STATE_MMS_BODY_CREATING;
                    info->sub_state = 0;
                    action = MMA_CREATE_ACTION_CONTINUE;
                }
            }
            break;
        }

        case MMA_CREATE_STATE_MMS_BODY_CREATING:
        {
            long fs_result = 0;

            if (info->mms_dsr->body->curr_object == NULL)
            {
                info->state = MMA_CREATE_STATE_MMS_INFO_CREATING;
                info->input = MMA_RESULT_OK;
                action = MMA_CREATE_ACTION_CONTINUE;
                break;
            }
            else if (info->mms_dsr->body->curr_object->size == 0 || info->mms_dsr->body->curr_object->is_invallid)
            {
                info->mms_dsr->body->curr_object = info->mms_dsr->body->curr_object->next;
                MMA_SIGNAL_SENDTO_U(MMA_SUBMODULE_MSG_CREATE, MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND, info->req_id);
                action = MMA_CREATE_ACTION_DELAYED;
                break;
            }
            else
            {
                switch (info->sub_state)
                {
                    case 0:
                    {
                        char *cnt_id = NULL, *cnt_loc = NULL;
                        MmsKnownMediaType type = (MmsKnownMediaType)mma_get_mmsKnownMediaType_from_mime_type(info->mms_dsr->body->curr_object->mime_str);
                        
                        /* For DRM we will pass the string. Same as SE(k890i) */
                        
                        if (type == MMS_TYPE_APP_VND_OMA_DRM_MESSAGE ||
                            type == MMS_TYPE_APP_VND_OMA_DRM_CONTENT ||
                            type == MMS_TYPE_APP_VND_OMA_DRM_R_XML ||
                            type == MMS_TYPE_APP_VND_OMA_DRM_R_WBXML)
                        {
                            type = MMS_VALUE_AS_STRING;
                        }
       

                        /* For FTA test only */
                    #ifdef __GEMINI__
                        if (is_test_sim(l4c_gemini_get_switched_sim_id(SIM1)) &&
                            mma_get_mime_group_from_mime_type(info->mms_dsr->body->curr_object->mime_str) == MIME_TYPE_TEXT)
                    #else /* __GEMINI__ */ 
                        if (is_test_sim() &&
                            mma_get_mime_group_from_mime_type(info->mms_dsr->body->curr_object->mime_str) == MIME_TYPE_TEXT)
                    #endif /* __GEMINI__ */ 
                        {
                            mma_create_mms_replace_fta_text(info->mms_dsr->body->curr_object);
                        }

                        if (info->mode == MMA_MODE_RAW)
                        {
                            cnt_id = info->mms_dsr->body->curr_object->content_id;
                            cnt_loc = info->mms_dsr->body->curr_object->content_location;
                        }
                        else
                        {
                            cnt_id = cnt_loc = info->mms_dsr->body->curr_object->file_name;
                        }

                        /* Create body params: MMS service would do MmsKnownMediaType conversion, just provide mime type here */
                        if (NULL ==
                            (info->mo_param = mma_create_body_params(
                                                type,
                                                info->mms_dsr->body->curr_object->mime_str,
                                                info->mms_dsr->body->curr_object->file_name,
                                                cnt_id,
                                                cnt_loc,
                                                (MmsCharset)info->mms_dsr->body->curr_object->charset)))
                        {
                            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                               MMA_CREATE_MMS_SMIL_CREATING_BODY_PARAM_ERROR,
                                               "(mma_create.c) mma_create_body_params failed\n"));
                            info->input = MMA_RESULT_FAIL;
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                            break;
                        }
                        else if ((info->input = translate_mms_result_to_mma(MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle))) != MMA_RESULT_OK)       /* Write message */
                        {
                            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                              MMA_CREATE_MMS_SMIL_CREATING_BODY_PARAM_TRANSACTION_ERROR,
                                              "(mma_create.c) MMSlib_transactionOpen %d\n", info->input));
                            mma_free_body_params(&info->mo_param);
                            //info->input = translate_mms_result_to_mma(info->input);
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                            break;
                        }

                        ASSERT(info->r_handle == -1 && info->r_byte == 0);
                        if ((info->r_handle = mma_msf_file_open_in_blocking_mode(
                                                MSF_MODID_MMA,
                                                info->mms_dsr->body->curr_object->file_path,
                                                MSF_FILE_SET_RDONLY,
                                                0, MMA_MSG_STORAGE_PHONE)) < 0)
                        {
                            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                              MMA_CREATE_BODY_OBJECT_FILE_OPEN_ERROR,
                                              "(mma_create.c) MSF_FILE_OPEN %d\n", info->r_handle));
                            mma_free_body_params(&info->mo_param);
                            info->input = translate_fs_result_to_mma(info->r_handle);
                            info->state = MMA_CREATE_STATE_FINISHING;
                            action = MMA_CREATE_ACTION_CONTINUE;
                            break;
                        }

                        if (info->mms_dsr->body->curr_object->is_virtual_file == KAL_TRUE)
                        {
                            long fs_result = 0;

                            if ((fs_result = MSF_FILE_SEEK(
                                                info->r_handle,
                                                info->mms_dsr->body->curr_object->offset,
                                                MSF_FILE_SEEK_SET)) < 0)
                            {
                                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                                  MMA_CREATE_BODY_OBJECT_FILE_SEEK_ERROR,
                                                  "(mma_create.c) MSF_FILE_SEEK %d\n", fs_result));
                                mma_free_body_params(&info->mo_param);
                                info->input = translate_fs_result_to_mma(fs_result);
                                info->state = MMA_CREATE_STATE_FINISHING;
                                action = MMA_CREATE_ACTION_CONTINUE;
                                break;
                            }
                        }
                        info->sub_state = 1;
                    }
                        /* fall through */

                    case 1:
                    {
                        /* write body entry header; write header only; may re-enter... */
                        if ((info->input = translate_mms_result_to_mma(MMSlib_setMessageBody(MSF_MODID_MMA, info->mo_param, NULL, info->mms_dsr->body->curr_object->size, &info->m_handle, &info->t_handle))) != MMS_RESULT_OK)    /* only finish state 1~2 (wrtie header) */
                        {
                            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                              MMA_CREATE_SET_MSG_BODY_ERROR,
                                              "(mma_create.c) MMSlib_setMessageBody %d\n", info->input));
                            if (info->input == MMA_RESULT_DELAYED)
                            {
                                MmsTransaction *t = (MmsTransaction*) info->t_handle;

                                info->delayed_handle = t->fileHandle;
                                info->input = MMA_RESULT_OK;
                                action = MMA_CREATE_ACTION_DELAYED;
                            }
                            else
                            {
                                mma_free_body_params(&info->mo_param);
                                //info->input = translate_mms_result_to_mma(info->input);
                                info->state = MMA_CREATE_STATE_FINISHING;
                                action = MMA_CREATE_ACTION_CONTINUE;
                            }
                            break;
                        }
                        mma_free_body_params(&info->mo_param);
                        info->sub_state = 2;
                    }

                        /* fall through */
                    case 2:
                    {
                        /* read body data; may re-enter... */
                        info->mo_buffer_size =
                            ((info->mms_dsr->body->curr_object->size - info->r_byte) >
                             MMS_MAX_CHUNK_SIZE) ? MMS_MAX_CHUNK_SIZE : (info->mms_dsr->body->curr_object->size -
                                                                         info->r_byte);
                        if (info->mo_buffer_size > 0)
                        {
                            info->mo_buffer = (char*)MMA_CALLOC(info->mo_buffer_size);
                            if ((fs_result = MSF_FILE_READ(info->r_handle, info->mo_buffer, info->mo_buffer_size)) < 0)
                            {
                                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                                  MMA_CREATE_MO_BUFFER_FILE_READ_ERROR,
                                                  "(mma_create.c) MSF_FILE_READ %d\n", fs_result));
                                if ((info->input = translate_fs_result_to_mma(fs_result)) == MMA_RESULT_DELAYED)
                                {
                                    MSF_FILE_SELECT(info->r_handle, MSF_FILE_EVENT_READ);
                                    info->delayed_handle = info->r_handle;
                                    MMA_FREE(info->mo_buffer);
                                    info->input = MMA_RESULT_OK;
                                    action = MMA_CREATE_ACTION_DELAYED;
                                }
                                else
                                {
                                    MMA_FREE(info->mo_buffer);
                                    info->state = MMA_CREATE_STATE_FINISHING;
                                    action = MMA_CREATE_ACTION_CONTINUE;
                                }
                                break;
                            }
                            else
                            {
                                info->mo_buffer_size = fs_result;
                                info->r_byte += info->mo_buffer_size;
                            }

                            ASSERT(((MmsTransaction*) info->t_handle)->state == 3);
                            /* Manually set value for MMSlib_setMessageBody() state 3, a little bit dirty... */
                            ((MmsTransaction*) info->t_handle)->bufferPos = info->mo_buffer;
                            ((MmsTransaction*) info->t_handle)->bytesLeft = info->mo_buffer_size;
                            ((MmsTransaction*) info->t_handle)->filePos = -1;
                        }
                        info->sub_state = 3;
                    }
                        /* fall through */

                    case 3:
                    {
                        MmsBodyParams dummy;

                        /* write body data; write media buffer; may re-enter... */
                        ASSERT(info->mo_param == NULL);
                        if ((info->input = translate_mms_result_to_mma(MMSlib_setMessageBody(
                                            MSF_MODID_MMA,
                                            &dummy,
                                            (unsigned char*)info->mo_buffer,
                                            info->mo_buffer_size,
                                            &info->m_handle,
                                            &info->t_handle))) != MMA_RESULT_OK)
                        {
                            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                              MMA_CREATE_SET_MSG_BODY_ERROR,
                                              "(mma_create.c) MMSlib_setMessageBody %d\n", info->input));
                            if (info->input == MMA_RESULT_DELAYED)
                            {
                                MmsTransaction *t = (MmsTransaction*) info->t_handle;

                                info->delayed_handle = t->fileHandle;
                                info->input = MMA_RESULT_OK;
                                action = MMA_CREATE_ACTION_DELAYED;
                            }
                            else
                            {
                                MMA_FREE(info->mo_buffer);
                                //info->input = translate_mms_result_to_mma(info->input);
                                info->state = MMA_CREATE_STATE_FINISHING;
                                action = MMA_CREATE_ACTION_CONTINUE;
                            }
                            break;
                        }

                        MMA_FREE(info->mo_buffer);
                        /* proceed to next object */
                        if (info->r_byte >= info->mms_dsr->body->curr_object->size)
                        {
                            if ((info->input = translate_mms_result_to_mma(MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle))) != MMA_RESULT_OK)
                            {
                                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                                  MMA_CREATE_MSG_BODY_TRANSACTION_CLOSE_ERROR,
                                                  "(mma_create.c) MMSlib_transactionClose %d\n", info->input));
                                //info->input = translate_mms_result_to_mma(info->input);
                                info->state = MMA_CREATE_STATE_FINISHING;
                                action = MMA_CREATE_ACTION_CONTINUE;
                                break;
                            }

                            MSF_FILE_CLOSE(info->r_handle);
                            info->r_handle = -1;
                            info->r_byte = 0;
                            info->sub_state = 0;
                            info->mms_dsr->body->curr_object = info->mms_dsr->body->curr_object->next;
                            MMA_SIGNAL_SENDTO_U(
                                MMA_SUBMODULE_MSG_CREATE,
                                MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND,
                                info->req_id);
                            action = MMA_CREATE_ACTION_DELAYED;
                            break;
                        }
                        else    /* we need next read + write for this object... */
                        {
                            MMA_SIGNAL_SENDTO_U(
                                MMA_SUBMODULE_MSG_CREATE,
                                MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND,
                                info->req_id);
                            info->sub_state = 2;
                            action = MMA_CREATE_ACTION_DELAYED;
                            break;
                        }
                    }
                }
            }
            break;
        }

        case MMA_CREATE_STATE_MMS_INFO_CREATING:
        {
            if ((info->input = translate_mms_result_to_mma(MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle))) != MMA_RESULT_OK)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_MMS_INFO_CREATING_MSG_CLOSE_ERROR,
                                  "(mma_create.c) MMSlib_messageClose %d\n", info->input));
                //info->input = translate_mms_result_to_mma(info->input);
                info->state = MMA_CREATE_STATE_FINISHING;
                action = MMA_CREATE_ACTION_CONTINUE;
                break;
            }
            MMSif_createMessageDone(MSF_MODID_MMA, 
                                    MMA_TRANSLATE_MSG_ID(info->msg_id),
                                    info->msg_filetype,
                                    (kal_uint8)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type));
            info->state = MMA_CREATE_STATE_FINISHING /* MMA_CREATE_STATE_INT_NOTIFY */ ;
            action = MMA_CREATE_ACTION_DELAYED;
            break;
        }

        case MMA_CREATE_STATE_INT_NOTIFY:
        {
            MMA_SIGNAL_SENDTO_U(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_CREATE_NEW_MMS_REQ, info->msg_id);
            info->state = MMA_CREATE_STATE_FINISHING;
            action = MMA_CREATE_ACTION_DELAYED;
            break;
        }

        case MMA_CREATE_STATE_FINISHING:
        {
            info->result = info->input;
            action = MMA_CREATE_ACTION_CONTINUE;
            info->state = MMA_CREATE_STATE_FINISHED;
            break;
        }

        case MMA_CREATE_STATE_FINISHED:
        {
            switch (info->result)
            {
                case MMA_RESULT_OK: /* return successful signal */
                    /* fall-through */
                default:            /* return failed signal */
                    if ((info->result != MMA_RESULT_OK)&& (info->msg_id != 0))
                    {
                        MMAif_deleteMessage(MMA_SUBMODULE_MSG_CREATE, info->msg_id);
                    }
                    (void)mma_create_send_rsp(info->req_id, info->result, info->msg_id);
                    mma_create_delete_task_hdlr(info->req_id);

                    break;
            }
            action = MMA_CREATE_ACTION_NONE;
            break;
        }
    }

    return action;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_fsm_hdlr
 * DESCRIPTION
 *  Create task handler for every state switching
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_create_fsm_hdlr(MSF_UINT32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *req = mma_create_get_task_by_req(req_id);
    mma_create_info_struct *info = NULL;
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_create_context.mma_create_env_state == MMA_CREATE_ENV_STATE_ACTIVE)
    {
        ASSERT(req != NULL && req->data != NULL);
        info = (mma_create_info_struct*) req->data;
        while (mma_create_fsm(info) == MMA_CREATE_ACTION_CONTINUE);
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    else if (g_mma_create_context.mma_create_env_state == MMA_CREATE_ENV_STATE_MEM_CARD_PLUG_OUT)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_FAILED_CARD_PLUG_OUT, "(mma_create.c): MMA_CREATE_FAILED_CARD_PLUG_OUT"));
        ASSERT(req != NULL && req->data != NULL);
        info = (mma_create_info_struct*) req->data;

        mma_create_send_rsp(req->first_id, MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT, 0);      
        
            mma_create_delete_task_hdlr(req->first_id);
        
        g_mma_create_context.mma_create_env_state = MMA_CREATE_ENV_STATE_ACTIVE;

    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_ENV_STATE_NOT_ACTIVE,
                          "(mma_create.c) env state %d\n", g_mma_create_context.mma_create_env_state));
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  encode_msg          [IN]        
 *  create_req_p        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_create_req_hdlr(kal_bool encode_msg, mma_msgmgr_create_info_struct *create_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_create_info_struct *info = NULL;
    mma_msg_storage_type_enum preferred_storage = MMA_MSG_STORAGE_NONE;
    kal_uint16 phone_msg_count = 0;
    kal_uint16 card_msg_count = 0;
    kal_bool is_edit_msg = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMSlib_fldrMgrGetNumberOfMessages(MSF_MMS_STORAGE_PHONE, &phone_msg_count);
    MMSlib_fldrMgrGetNumberOfMessages(MSF_MMS_STORAGE_MEM_CARD_1, &card_msg_count);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if ((create_req_p->mode == MMA_MODE_EDIT || 
        create_req_p->mode == MMA_MODE_POSTCARD) &&
        create_req_p->o_msg_id != 0)
    {
        /*This mean editing the old message so storage will be old message storage*/
        preferred_storage = mma_get_message_storage(create_req_p->o_msg_id);
        is_edit_msg = KAL_TRUE;

    }
    else if(create_req_p->mode == MMA_MODE_TEMPLATE  ||
        create_req_p->app_id == MMA_APP_ID_TEMPLATE ||
        (create_req_p->app_id == MMA_APP_ID_JSR &&
        create_req_p->mode == MMA_MODE_RAW))
    {
        /*Template will always be created on Phone*/
        preferred_storage = MMA_MSG_STORAGE_PHONE;
    }
    else
#endif
    {
        preferred_storage = (mma_msg_storage_type_enum)mma_setting_get_preffered_storage();

    }

    ASSERT(create_req_p != NULL);

    if (mma_main_is_in_usb_mode())
    {
        mma_create_send_rsp(create_req_p->req_id, MMA_RESULT_FAIL_IN_USB_MODE, 0);
    }
    else if (mma_main_is_in_terminate())
    {
        mma_create_send_rsp(create_req_p->req_id, MMA_RESULT_FAIL_TERMINATING, 0);
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    else if (!mma_main_is_storage_type_present(preferred_storage))           
    {
        /* This will happen only when preferred storage is Card and Card is not present */
        /*For Phone memory as preferred storage control will never come here */
 
        if (phone_msg_count >= (kal_uint16) (wap_custom_get_max_mms_num() - 1))
        {
            /*On phone max. msg has  reached so cannot use phone and card 
            has to plug-in for completing the operation*/
            mma_create_send_rsp(create_req_p->req_id, MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_INSERT_CARD, 0);

        }
        else
        {
            /*On phone max. msg has not reached so can use phone*/
            mma_create_send_rsp(create_req_p->req_id, MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_USE_PHONE, 0);
        }   
    }
    else if ((!is_edit_msg && preferred_storage == MMA_MSG_STORAGE_PHONE && 
             phone_msg_count >= (kal_uint16)(wap_custom_get_max_mms_num() - 1)))
    {
        if ((create_req_p->mode == MMA_MODE_TEMPLATE  ||
            create_req_p->app_id == MMA_APP_ID_TEMPLATE ||
            (create_req_p->app_id == MMA_APP_ID_JSR &&
            create_req_p->mode == MMA_MODE_RAW)) ||
            (!mma_main_is_storage_type_present(MMA_MSG_STORAGE_CARD1) ||
             card_msg_count >= (kal_uint16)(wap_custom_get_max_mms_num_on_card())))
        {
            mma_create_send_rsp(create_req_p->req_id, MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED, 0);

        }
        else
        {
            mma_create_send_rsp(create_req_p->req_id, MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_PHONE_MEMORY, 0);
        }
        
    }
    else if (!is_edit_msg && preferred_storage == MMA_MSG_STORAGE_CARD1 && 
             card_msg_count >= (kal_uint16)(wap_custom_get_max_mms_num_on_card()))
    {
        if (phone_msg_count  >= (kal_uint16)(wap_custom_get_max_mms_num() - 1))
        {
            mma_create_send_rsp(create_req_p->req_id, MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED, 0);

        }
        else
        {
            mma_create_send_rsp(create_req_p->req_id, MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_MEM_CARD, 0);
        }

    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    else
    {
        if (create_req_p->mode == MMA_MODE_TEMPLATE)
        {
            if (create_req_p->o_msg_id > 0)
            {
                create_req_p->mode = MMA_MODE_FORWARD;
            }
            else
            {
                create_req_p->mode = MMA_MODE_EDIT;
            }
        }

        info = MMA_CALLOC(sizeof(mma_create_info_struct));
        info->req_id = create_req_p->req_id;
        info->mode = create_req_p->mode;
        info->state = MMA_CREATE_STATE_STARTED;
        info->msg_id = 0;
        info->app_id = create_req_p->app_id;
        info->encode_msg = encode_msg;
        info->msg_filetype = create_req_p->msg_filetype;
        /* Set File handles to invalid*/
        info->r_handle = -1;
        info->w_handle = -1;
        info->delayed_handle = -1;
        info->storage_type = preferred_storage;

        info->o_msg_id = create_req_p->o_msg_id;
        

        if (info->mode == MMA_MODE_UPLOAD)
        {
            info->upload_filepath = MMA_CALLOC(strlen(create_req_p->upload_filepath) + 1);
            strcpy(info->upload_filepath, create_req_p->upload_filepath);
        }
#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
        else if( info->mode == MMA_MODE_VENDOR_XML)
        {
            info->xml_filepath = MMA_CALLOC(app_ucs2_strlen((kal_int8*) create_req_p->xml_filepath) * ENCODING_LENGTH + 2);
            app_ucs2_strcpy((kal_int8*) info->xml_filepath, (kal_int8*) create_req_p->xml_filepath);
			info->mms_dsr = (mma_mms_description_struct*)MMA_CALLOC(sizeof(mma_mms_description_struct));
		}
	#endif 
		else
        {
            /*info->xml_filepath = MMA_CALLOC(app_ucs2_strlen((kal_int8*) create_req_p->xml_filepath) * ENCODING_LENGTH + 2);
            app_ucs2_strcpy((kal_int8*) info->xml_filepath, (kal_int8*) create_req_p->xml_filepath);*/
			ASSERT(create_req_p->mms_dsr);
			info->mms_dsr =  create_req_p->mms_dsr;
        }

        if (g_mma_create_context.mma_create_task_queue == NULL || encode_msg == FALSE)
        {
            if (mma_insert_node_to_queue(&(g_mma_create_context.mma_create_task_queue), create_req_p->req_id, 0, info, MMA_ACTION_CREATE_MSG)
                != MMA_RESULT_OK)
            {
                ASSERT(0);
            }
        }
        else
        {
            mms_mma_queue_struct *tmp = g_mma_create_context.mma_create_task_queue;
            mms_mma_queue_struct *tmp2 = NULL;
            mms_mma_queue_struct *new_node = MMA_CALLOC(sizeof(mms_mma_queue_struct));
            mma_create_info_struct *info_tmp = (mma_create_info_struct*) tmp->data;

            new_node->first_id = create_req_p->req_id;
            new_node->second_id = 0;
            new_node->data = info;
            new_node->next = NULL;

            if (info_tmp->state == MMA_CREATE_STATE_STARTED && info_tmp->encode_msg == FALSE)
            {
                g_mma_create_context.mma_create_task_queue = new_node;
                g_mma_create_context.mma_create_task_queue->next = tmp;
            }
            else
            {
                while (tmp->next != NULL)
                {
                    tmp2 = tmp->next;
                    info_tmp = (mma_create_info_struct*) tmp2->data;
                    if (info_tmp->encode_msg == FALSE)
                    {
                        new_node->next = tmp2;
                        tmp->next = new_node;
                        break;
                    }
                    tmp = tmp->next;
                }
                if (new_node->next == NULL)
                {
                    mma_insert_node_to_queue(
                        &(g_mma_create_context.mma_create_task_queue),
                        create_req_p->req_id,
                        0,
                        info,
						MMA_ACTION_CREATE_MSG);
                    MMA_FREE(new_node);
                }
            }
        }

        if (g_mma_create_context.mma_create_task_queue->first_id == info->req_id)       /* One active task at a time */
        {
            mma_reset_last_tick();
            mma_create_fsm_hdlr(info->req_id);
        }
        else
        {
            /* TODO: Priority of internal create request is higher than external request */
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_NOT_THE_ACTIVE_TASK, "(mma_create.c): Request %d queued", info->req_id));
        }
    }
    MMA_FREE(create_req_p->upload_filepath);
    MMA_FREE(create_req_p->xml_filepath);
    MMA_FREE(create_req_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_process_int_sig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mma_create_process_int_sig(mma_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_create_info_struct *info = NULL;

    if (sig == NULL)
    {
        return;
    }
    switch (sig->type)
    {
        case MMA_INT_SIG_TYPE_MSG_INT_CREATE_REQ:
            mma_create_req_hdlr((kal_bool) sig->i_param, (mma_msgmgr_create_info_struct*) sig->p_param);
            break;

        case MMA_INT_SIG_TYPE_MSG_CREATE_CONTINUE_IND:
            mma_create_fsm_hdlr(sig->u_param1);
            break;
        case MMA_INT_SIG_TYPE_MSG_CREATE_NEXT_IND:
        {
            if (g_mma_create_context.mma_create_task_queue != NULL)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_MSG_CREATE_NEXT_IND, "(mma_create.c): Queued request %d start",
                             g_mma_create_context.mma_create_task_queue->first_id));
                mma_create_fsm_hdlr(g_mma_create_context.mma_create_task_queue->first_id);
            }
            break;
        }
        case MMA_INT_SIG_TYPE_MSG_CREATE_NEW_MMS_RSP:
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_SIG_NEW_MMS_CREATE_RSP_DETAIL,
                              "MMA_INT_SIG_TYPE_MSG_CREATE_NEW_MMS_RSP(msg = %d, result = %d)\n", sig->u_param1,
                              sig->i_param));
            if (g_mma_create_context.mma_create_task_queue &&
                g_mma_create_context.mma_create_env_state == MMA_CREATE_ENV_STATE_ACTIVE)
            {
                info = (mma_create_info_struct*) g_mma_create_context.mma_create_task_queue->data;
                if (sig->u_param1 == info->msg_id)
                {
                    info->input = (mma_result_enum)sig->i_param;
                    mma_create_fsm_hdlr(info->req_id);
                }
            }
            else
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_ENV_STATE_NOT_ACTIVE,
                                  "(mma_create.c) env state %d\n", g_mma_create_context.mma_create_env_state));
            }
            break;

        case MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ:
        {
            mms_mma_queue_struct *curr = g_mma_create_context.mma_create_task_queue;

            g_mma_create_context.mma_create_env_state = MMA_CREATE_ENV_STATE_ENTERING_USB;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_MSG_ENTER_USB_MODE,
                              "(mma_create.c): MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ %d\n", sig->type));
            if (curr != NULL)
            {
                (void)mma_create_send_rsp(curr->first_id, MMA_RESULT_FAIL_IN_USB_MODE, 0);      /* ashok need to check 0 or msg_id */
                mma_create_delete_task_hdlr(curr->first_id);
            }
            else
            {
                g_mma_create_context.mma_create_env_state = MMA_CREATE_ENV_STATE_ACTIVE;
                MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
            }
            break;
        }

        case MMA_INT_SIG_TYPE_MSG_TERMINATE_IND:
        {
            mms_mma_queue_struct *curr = g_mma_create_context.mma_create_task_queue;

            g_mma_create_context.mma_create_env_state = MMA_CREATE_ENV_STATE_TERMINATING;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CREATE_MSG_ENTER_TERMINATE_MODE,
                              "(mma_create.c): MMA_INT_SIG_TYPE_MSG_TERMINATE_IND %d\n", sig->type));
            if (curr != NULL)
            {
                mma_create_send_rsp(curr->first_id, MMA_RESULT_FAIL_TERMINATING, 0);
                mma_create_delete_task_hdlr(curr->first_id);
            }
            else
            {
                MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
            }
            break;
        }

        default:
            break;
    }
}





/*****************************************************************************
 * FUNCTION
 *  mma_create_process_mms_info
 * DESCRIPTION
 *  Associate object id after parsing xml file
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 Decimal value.(?)
 *****************************************************************************/
void mma_create_process_mms_info(mma_create_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *object = NULL,  *next = NULL;
    const char *mime = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   if(info->mms_dsr->body)
   {
	object = info->mms_dsr->body->objects;
    while (object)
    {
        next = object->next;
        /* size */
        if (MSF_FILE_GETSIZE_EXT(object->file_path, MSF_MMS_STORAGE_NONE) > 0)
        {
			object->is_invallid = KAL_FALSE;
            /* type & mime type */
        #ifdef __DRM_SUPPORT__
            switch (object->drm_type)
            {
                case MMA_DRM_NONE:
                    object->drm_process_type = MMA_DRM_NO_PROTECTION;
                    if (object->mime_str == NULL)
                    {
                        mime = mma_get_mime_type_from_filename_and_mime_string(object->file_name, NULL);
                    }
                    break;
                case MMA_DRM_FL_CD:
                    object->drm_process_type = MMA_DRM_PROCESS_FORWARD_LOCK_CD;
                    mime = MMA_MEDIA_TYPE_STRING_DRM1;
                    break;
                case MMA_DRM_SD:
                case MMA_DRM_SD_NO_RIGHT:
                    object->drm_process_type = MMA_DRM_PROCESS_SEPERATE_DELIVERY;
                    mime = MMA_MEDIA_TYPE_STRING_DRM2;
                    break;
            }
        #else /* __DRM_SUPPORT__ */ 
            object->drm_process_type = MMA_DRM_NO_PROTECTION;
            mime = mma_get_mime_type_from_filename_and_mime_string(object->file_name, NULL);
        #endif /* __DRM_SUPPORT__ */ 
            if (object->mime_str == NULL && info->mode != MMA_MODE_RAW)
            {
                object->mime_str = msf_cmmn_strdup(MSF_MODID_MMA, mime);
            }

            /* Charset */
            if (mma_get_mime_group_from_mime_type(object->mime_str) == MIME_TYPE_TEXT && object->size > 0)
            {
                if (object->is_virtual_file == FALSE)
                {
                    object->charset = (mma_is_ascii_file(object->file_path)) ? MMS_US_ASCII : MMS_UTF8;
                }
                else
                {
                    char *v_file_name = NULL;   /* vitual file name */
                    int fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, object->file_path, MSF_FILE_SET_RDONLY, 0, MMA_MSG_STORAGE_PHONE);

                    v_file_name = (char*)MMA_CALLOC(MMA_MAX_VIRTUAL_FILE_PATH_SIZE);
                    ASSERT(v_file_name != NULL);
                    if (MSF_FILE_GEN_VIRTUAL_FILENAME
                        (MSF_MODID_MMA, fh, v_file_name, MMA_MAX_VIRTUAL_FILE_PATH_SIZE, object->offset,
                         object->size) == MSF_FILE_OK)
                    {
                        object->charset = (mma_is_ascii_file(v_file_name)) ? MMS_US_ASCII : MMS_UTF8;
                    }
                    MMA_FREE(v_file_name);
                    MSF_FILE_CLOSE(fh);
                }
            }
           
        }
        else
        {
          /*  mma_remove_object_in_slide(info->mms_dsr->body->slides, object);
            if (prev == NULL)
            {
                info->mms_dsr->body->objects = object->next;
            }
            else
            {
                prev->next = object->next;
            }
            if (info->mms_dsr->body->curr_object == object)
            {
                info->mms_dsr->body->curr_object = info->mms_dsr->body->objects;
            }
            mma_mms_free_object(MSF_MODID_MMA, &object);*/
			//ASSERT(0);
			object->is_invallid = KAL_TRUE;
        }
        object = next;
    }
}
}
#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_CREATE_C */ 

