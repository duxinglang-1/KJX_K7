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
 *   mma_drmsrv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions of MMA DRMSRV submodule.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMA_DRMSRV_C
#define _MMA_DRMSRV_C
#if defined(MMS_SUPPORT)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_wap_config.h"

#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "wapadp.h"
#include "mmsadp.h"

/* APPLIB */
#include "app_str.h"
#include "app_mine.h"

/* PlutoMMI */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "StdC.h"
#include "mmi_frm_gprot.h"
//#include "UMGProt.h"
#include "UmSrvGprot.h"
#include "wgui_categories_util.h"
#include "PhoneBookGprot.h"

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
#include "msf_errc.h"
#include "msf_chrs.h"   /* MSF: character API */

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
#include "mltypes.h"
#include "mlfetch.h"
#include "mmsl_if.h"

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
#include "mma_interface.h"
#include "mma_utilities.h"
#include "mma_msgmgr.h"
#include "mma_sendrecv.h"
#include "mma_msg_struct.h"
#include "mma_event.h"

#ifdef __MMI_MMS_MMA_DRM_ENCODING__
#include "mma_drmsrv.h"
#include "drm_gprot.h"
#include "drm_def.h"
#include "drm_errcode.h"


static mma_drmsrv_context_struct g_mma_drmsrv_cntx = {0};
#define MMA_DRMSRV_SLEEP_TIME 10
#define MMA_DRMSRV_SLEEP_TIME_START_AT_COUNT 20
/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_get_state_string
 * DESCRIPTION
 *  For logging use
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  string
 *****************************************************************************/
static const char *mma_drmsrv_get_state_string(mma_drmsrv_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
        case MMA_DRMSRV_STATE_IDLE:
            return "MMA_DRMSRV_STATE_IDLE";
        case MMA_DRMSRV_STATE_GETTING_MSG_INFO:
            return "MMA_DRMSRV_STATE_GETTING_MSG_INFO";
        case MMA_DRMSRV_STATE_MMS_HEADER_PARSING:
            return "MMA_DRMSRV_STATE_OPENING_MMS";
        case MMA_DRMSRV_STATE_GETTING_MMS_BODY_HEADER:
            return "MMA_DRMSRV_STATE_GETTING_MMS_SKELETON";
        case MMA_DRMSRV_STATE_CHECK_MMS_OBJ_DRM_TYPE:
            return "MMA_DRMSRV_STATE_CHECK_MMS_OBJ_DRM_TYPE";
        case MMA_DRMSRV_STATE_COPY_MMS_CONTENT:
            return "MMA_DRMSRV_STATE_COPY_MMS_CONTENT";
        case MMA_DRMSRV_STATE_SET_DRM_OBJ_HEADER:
            return "MMA_DRMSRV_STATE_SET_DRM_OBJ_HEADER";
        case MMA_DRMSRV_STATE_ENCODING_DRM_OBJ:
            return "MMA_DRMSRV_STATE_ENCODING_DRM_OBJ";
        case MMA_DRMSRV_STATE_FINISHING:
            return "MMA_DRMSRV_STATE_FINISHING";
        default:
            return "NULL";
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_init
 * DESCRIPTION
 *  DRMSRV sub-module init
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_drmsrv_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_drmsrv_cntx.env_state = MMA_DRMSRV_ENV_STATE_ACTIVE;
    g_mma_drmsrv_cntx.task_queue = NULL;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_terminate
 * DESCRIPTION
 *  DRMSRV sub-module termination
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_drmsrv_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_drmsrv_cntx.task_queue = NULL;
    g_mma_drmsrv_cntx.env_state = MMA_DRMSRV_ENV_STATE_TERMINATED;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_get_active_task
 * DESCRIPTION
 *  Get current encode request
 * PARAMETERS
 *  void
 * RETURNS
 *  mms_mma_queue_struct*   [OUT]
 *****************************************************************************/
mms_mma_queue_struct *mma_drmsrv_get_active_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mma_drmsrv_cntx.task_queue;
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_get_task_by_req
 * DESCRIPTION
 *  Get task by request ID
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  mms_mma_queue_struct
 *****************************************************************************/
static mms_mma_queue_struct *mma_drmsrv_get_task_by_req(kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_get_node_from_queue(g_mma_drmsrv_cntx.task_queue, req_id, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_free_info
 * DESCRIPTION
 *  Free encode task info
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_drmsrv_free_info(mma_drmsrv_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_drmsrv_FL_CD_obj_struct *obj_tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMA_FREE(info->new_msg_filepath);
    MMA_FREE(info->copy_buffer);
    if (info->header != NULL)
    {
		switch (info->o_msg_suffix)
		{
			case MMS_SUFFIX_TEMPLATE:
			case MMS_SUFFIX_SEND_REQ:
			case MMS_SUFFIX_MSG:
				{
					MMSlib_freeMmsGetHeader(MSF_MODID_MMA, info->header->header.g_header);
					MMA_FREE(info->header->header.g_header);
				}
				break;
			case MMS_SUFFIX_IMMEDIATE:
			case MMS_SUFFIX_NOTIFICATION:
				{
					MMSlib_freeMmsNotification(MSF_MODID_MMA, info->header->header.notif);
					MMA_FREE(info->header->header.notif);
				}
				break;
		}        
        MMA_FREE(info->header);
    }
    if (info->body_header != NULL)
    {
        info->body_header = NULL;   /* MMSif_freeMmsBodyInfoList(MSF_MODID_MMA, info->body_header); */
    }
    while (info->FL_CD_obj != NULL)
    {
        obj_tmp = info->FL_CD_obj;
        info->FL_CD_obj = info->FL_CD_obj->next;
        MMA_FREE(obj_tmp);
    }
    if (info->r_handle >= 0)
    {
        MSF_FILE_CLOSE(info->r_handle);
    }
            
    if (info->w_handle >= 0)
    {
        MSF_FILE_CLOSE(info->w_handle);
    }

    MMA_FREE(info);
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_delete_task
 * DESCRIPTION
 *  Delete specified encode task
 * PARAMETERS
 *  req     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_drmsrv_delete_task(mms_mma_queue_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_drmsrv_info_struct *info = NULL;
    kal_bool encode_next = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req != NULL);
    ASSERT((info = (mma_drmsrv_info_struct*) req->data) != NULL);

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_DELETE_TASK,
                 "(mma_drmsrv.c): mma_drmsrv_delete_task(req %d, del state %d, env state %d)\n", info->req_id,
                 info->sub_state, g_mma_drmsrv_cntx.env_state));

    info->sub_state++;

    if (info->m_handle)
    {
        (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
    }
    if (info->t_handle)
    {
        (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
    }
    /* fall-through */

    encode_next = (kal_bool)(info->req_id == g_mma_drmsrv_cntx.task_queue->first_id);     /* Proceed to next request if the deleted is currently active */
    if ((req = mma_remove_node_from_queue(&g_mma_drmsrv_cntx.task_queue, info->req_id, 0)) != NULL)
    {
        mma_drmsrv_free_info(info);
        MMA_FREE(req);
    }

    if (g_mma_drmsrv_cntx.env_state == MMA_DRMSRV_ENV_STATE_ENTERING_USB)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_DRMSRV, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
    }
    else if (g_mma_drmsrv_cntx.env_state == MMA_DRMSRV_ENV_STATE_TERMINATING)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_DRMSRV, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
    }
    else if (g_mma_drmsrv_cntx.env_state == MMA_DRMSRV_ENV_STATE_ACTIVE && encode_next &&
             g_mma_drmsrv_cntx.task_queue != NULL)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_DRMSRV, MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_NEXT_IND);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_delete_task_hdlr
 * DESCRIPTION
 *  Delete specified encode task, and procceed to next task if needed
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_drmsrv_delete_task_hdlr(kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *req = NULL;
    mma_drmsrv_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((req = mma_drmsrv_get_task_by_req(req_id)) == NULL)
    {
        return;
    }
    ASSERT((info = (mma_drmsrv_info_struct*) req->data) != NULL);

    if (info->sub_state > 0)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_DELETE_TASK_HDLR,
                     "(mma_drmsrv.c): Duplicate mma_drmsrv_delete_task_hdlr(req %d, del state %d, env state %d)\n",
                     req_id, info->sub_state, g_mma_drmsrv_cntx.env_state));
    }
    else
    {
        mma_drmsrv_delete_task(req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_handle_rsp
 * DESCRIPTION
 *  handle response from other module
 * PARAMETERS
 *  sig         [IN]        
 *  sigData     [IN]        
 * RETURNS
 *  TRUE: the response belongs to drmsrv FSM; FALSE: the response doesn't belong to drmsrv FSM
 *****************************************************************************/
kal_bool mma_drmsrv_handle_rsp(kal_uint16 sig, void *sigData)
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
            msf_file_notify_t *data = (msf_file_notify_t*) sigData;

            if (g_mma_drmsrv_cntx.task_queue != NULL)
            {
                mma_drmsrv_info_struct *info = (mma_drmsrv_info_struct*) g_mma_drmsrv_cntx.task_queue->data;

                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_HANDLE_FILE_NOTIFY_RSP, 
                    "(mma_drmsrv.c) MSF_SIG_FILE_NOTIFY %d - %d", data->fileHandle, info->delayed_handle));
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
 *  mma_drmsrv_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id          [IN]        
 *  msg_id          [IN]        
 *  result          [IN]        
 *  msg_encoded     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_drmsrv_send_rsp(kal_uint32 req_id, kal_uint32 msg_id, mma_result_enum result, MSF_BOOL msg_encoded)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMA_SIGNAL_SENDTO_IUUU(
        MMA_SUBMODULE_MSG_MGR,
        MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_RSP,
        msg_encoded,
        req_id,
        msg_id,
        result);
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_encode_obj_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serial      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_drmsrv_encode_obj_done(kal_uint8 serial, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_drm_encode_done_ind_struct *encode_done_ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    encode_done_ind_p =
        (wap_mma_drm_encode_done_ind_struct*) construct_local_para(
                                                sizeof(wap_mma_drm_encode_done_ind_struct),
                                                TD_CTRL | TD_RESET);
    encode_done_ind_p->result = result;

    mms_mma_send_ilm(encode_done_ind_p, NULL, MSG_ID_WAP_MMA_DRM_ENCODE_DONE_IND, MOD_MMS);
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_handle_drm_encode_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_drmsrv_handle_drm_encode_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_drmsrv_info_struct *info = (mma_drmsrv_info_struct*) g_mma_drmsrv_cntx.task_queue->data;
    mma_drmsrv_FL_CD_obj_struct *tmp = info->FL_CD_obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        info->result = MMA_RESULT_OK;
        info->encode_obj_num++;
    }
    else
    {
        info->result = MMA_RESULT_OK;
        info->state = MMA_DRMSRV_STATE_COPY_MMS_CONTENT;
        if (info->w_handle < 0)
        {
            info->w_handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, info->new_msg_filepath, MSF_FILE_SET_WRONLY, 0, (mma_msg_storage_type_enum)info->storage_type);
        }
        if (info->w_handle < 0)
        {
            info->result = translate_fs_result_to_mma(info->w_handle);
            info->state = MMA_DRMSRV_STATE_FINISHING;
        }
        else
        {
            info->r_offset = info->FL_CD_obj->header_startpos;
            info->w_offset = info->w_offset - info->predict_encoded_size - info->new_obj_header_size;
            if (info->FL_CD_obj->next != NULL)
            {
                info->r_byte = info->FL_CD_obj->next->header_startpos - info->r_offset;
            }
            else
            {
                info->r_byte = info->header_size + info->body_size - info->r_offset;
            }
            info->w_byte = info->r_byte;
            tmp = info->FL_CD_obj;
            info->FL_CD_obj = info->FL_CD_obj->next;
            MMA_FREE(tmp);
			/* ashok, encoding fail, free the current drm node and go for next drm encoding */
			MMSlib_freeMmsBodyInfoNode(MSF_MODID_MMA, info->header->header.g_header);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_fsm
 * DESCRIPTION
 *  Encode MMS FL/CD object
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  mma_drmsrv_action_enum
 *****************************************************************************/
static mma_drmsrv_action_enum mma_drmsrv_fsm(mma_drmsrv_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_drmsrv_action_enum action = MMA_DRMSRV_ACTION_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(info != NULL);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM, "(mma_drmsrv.c) %s: req = %d, msg = %d, input = %d\n",
                 mma_drmsrv_get_state_string(info->state), info->req_id, info->o_msg_id, info->result));

    if (info->result != MMA_RESULT_OK && info->state != MMA_DRMSRV_STATE_FINISHING)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_ERROR, "(mma_drmsrv.c) state -> MMA_DRMSRV_STATE_FINISHING\n"));
        info->state = MMA_DRMSRV_STATE_FINISHING;
    }

    mma_check_and_sleep();

    switch (info->state)
    {
        case MMA_DRMSRV_STATE_IDLE:
        {
            /* only check for the suffix. Get it from msgmgr */
            info->o_msg_suffix = (MmsFileType)mma_msgmgr_get_msg_suffix(info->o_msg_id);
            info->result = MMA_RESULT_OK;
            info->state = MMA_DRMSRV_STATE_GETTING_MSG_INFO;
            action = MMA_DRMSRV_ACTION_CONTINUE;
            break;
        }

        case MMA_DRMSRV_STATE_GETTING_MSG_INFO:
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_STATE_GET_MSG_INFO, "(mma_drmsrv.c) o_msg_suffix %c\n", info->o_msg_suffix));

            if (info->o_msg_suffix != MMS_SUFFIX_READREPORT && info->o_msg_suffix != MMS_SUFFIX_DELIVERYREPORT)
            {
                if ((MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle)) != MMS_RESULT_OK)
                {
                    info->state = MMA_DRMSRV_STATE_FINISHING;
                }
                else if ((MMSlib_messageOpen
                          (MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(info->o_msg_id), info->o_msg_suffix,
                           &info->m_handle, (kal_uint8)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type))) != MMS_RESULT_OK)
                {
                    (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                    info->state = MMA_DRMSRV_STATE_FINISHING;
                }
                else if (info->header == NULL)
                {
                    info->state = MMA_DRMSRV_STATE_MMS_HEADER_PARSING;
                }
            }
            else
            {
                info->state = MMA_DRMSRV_STATE_FINISHING;
            }
            info->sub_state = 0;
            action = MMA_DRMSRV_ACTION_CONTINUE;
            break;

        }

        case MMA_DRMSRV_STATE_MMS_HEADER_PARSING:
        {
            switch (info->sub_state)    /* Here, sub_state is used to handle delayed file I/O */
            {
                case 0:
                {
                    ASSERT(info->header == NULL);
                    info->header = (mma_header_struct*) MMA_CALLOC(sizeof(mma_header_struct));
                    info->sub_state = 1;
                    switch (info->o_msg_suffix)
                    {
                        case MMS_SUFFIX_TEMPLATE:
                        case MMS_SUFFIX_SEND_REQ:
                        case MMS_SUFFIX_MSG:
                        {
                            info->header->header.g_header = (MmsGetHeader*) MMA_CALLOC(sizeof(MmsGetHeader));
                            ASSERT(info->header->header.g_header != NULL);
                            break;
                        }
                        default:
                            /*Place assert here to check only actaul MMS should come for DRM encoding*/
                            ASSERT(0);
                            break;
                    }
                    action = MMA_DRMSRV_ACTION_CONTINUE;
                }
                case 1:
                {
                    switch (info->o_msg_suffix)
                    {
                        case MMS_SUFFIX_TEMPLATE:
                        case MMS_SUFFIX_SEND_REQ:
                        case MMS_SUFFIX_MSG:
                        {
                            kal_int32 ret = MMA_RESULT_OK;

                            if ((ret = MMSlib_getMessageHeaderExt(
                                        MSF_MODID_MMA,
                                        info->header->header.g_header,
                                        &info->m_handle,
                                        &info->t_handle,
                                        MESSAGE_HEADERS)) == MMS_RESULT_DELAYED)
                            {
                                MmsTransaction *t = (MmsTransaction*) info->t_handle;

                                info->delayed_handle = t->fileHandle;
                                action = MMA_DRMSRV_ACTION_DELAYED;
                            }
                            else if (ret != MMS_RESULT_OK)
                            {
                                (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
                                (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                                info->state = MMA_DRMSRV_STATE_FINISHING;
                                action = MMA_DRMSRV_ACTION_CONTINUE;
                            }
                            else
                            {
                                (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
                                (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                                info->state = MMA_DRMSRV_STATE_GETTING_MMS_BODY_HEADER;
                                MMA_SIGNAL_SENDTO_U(
                                    MMA_SUBMODULE_MSG_DRMSRV,
                                    MMA_INT_SIG_TYPE_MSG_DRMSRV_CONTINUE_IND,
                                    info->req_id);
                                action = MMA_DRMSRV_ACTION_DELAYED;
								info->sub_state = 0;
                            }
                            break;
                        }
                     default:
                        ASSERT(0);
                    }
                }
            }
            break;
        }

        case MMA_DRMSRV_STATE_GETTING_MMS_HEADER:
        {
            ASSERT(info->body_header == NULL);
            info->state = MMA_DRMSRV_STATE_GETTING_MMS_BODY_HEADER;
            action = MMA_DRMSRV_ACTION_CONTINUE;
            break;
        }

        case MMA_DRMSRV_STATE_GETTING_MMS_BODY_HEADER:
        {
            switch (info->sub_state)    /* Here, sub_state is used to handle delayed file I/O */
            {
                case 0:
                {
                    ASSERT(info->body_header == NULL);

                    if ((MMSlib_transactionOpen(MSF_MODID_MMA, &info->t_handle)) != MMS_RESULT_OK)
                    {
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                    }
                    else if ((MMSlib_messageOpen
                              (MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(info->o_msg_id), info->o_msg_suffix,
                               &info->m_handle, (kal_uint8)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type))) != MMS_RESULT_OK)
                    {
                        (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                    }
                    else
                    {
                        info->sub_state = 1;
                        info->delayed_handle = -1;
                    }
                    action = MMA_DRMSRV_ACTION_CONTINUE;
                    break;
                }
                case 1:
                {
                    if ((info->input = translate_mms_result_to_mma(MMSlib_getMessageHeaderExt(
                                        MSF_MODID_MMA,
                                        info->header->header.g_header,
                                        &info->m_handle,
                                        &info->t_handle,
                                        BODY_HEADERS))) == MMA_RESULT_DELAYED)
                    {
                        MmsTransaction *t = (MmsTransaction*) info->t_handle;

                        info->delayed_handle = t->fileHandle;
                        action = MMA_DRMSRV_ACTION_DELAYED;
                    }
                    else if (info->input != MMS_RESULT_OK)
                    {
                        (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
                        (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                    }
                    else
                    {
                        info->body_header = &(info->header->header.g_header->bodyInfoList);
                        info->user_elements_size = mma_get_user_element_size(info->header, info->body_header);
                        (void)MMSlib_messageClose(MSF_MODID_MMA, &info->m_handle);
                        (void)MMSlib_transactionClose(MSF_MODID_MMA, &info->t_handle);
                        info->state = MMA_DRMSRV_STATE_CHECK_MMS_OBJ_DRM_TYPE;
                        info->sub_state = 0;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                        {
                            char *str = mma_get_app_id_from_params(info->body_header->contentType->params);

                            if (str != NULL && str != '\0')
                            {
                                /* We don't encode JSR message. */
                                info->state = MMA_DRMSRV_STATE_FINISHING;
                                info->result = MMA_RESULT_OK;
                                action = MMA_DRMSRV_ACTION_CONTINUE;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        }

        case MMA_DRMSRV_STATE_CHECK_MMS_OBJ_DRM_TYPE:
        {
            const char *mime_from_type = NULL;
            kal_bool is_FL_CD_msg = KAL_FALSE;
            MmsBodyInfoList *curr = NULL;
            MmsBodyInfoList *prev = NULL;
            kal_uint8 skip_bytes = 0;
			
            info->body_size = info->body_header->size;
            info->header_size = info->body_header->startPos;
            skip_bytes = mma_get_uintvar_length_bytes(info->body_header->numOfEntries);
            curr = info->body_header;
            while (curr != NULL)
            {
                mime_from_type = mma_get_mime_type_from_mmsContentType(curr->contentType);
                if(mime_from_type != NULL)
                {
                    if (msf_cmmn_strcmp_nc(mime_from_type, MMA_MEDIA_TYPE_STRING_DRM1) == 0)
                    {
                        mma_drmsrv_FL_CD_obj_struct *encode_obj =
                            (mma_drmsrv_FL_CD_obj_struct*) MMA_CALLOC(sizeof(mma_drmsrv_FL_CD_obj_struct));
                        encode_obj->object = curr;
                        if (prev != NULL)
                        {
                            if (prev->startPos == info->header_size)
                            {
                                encode_obj->header_startpos = info->header_size + skip_bytes;
                            }
                            else
                            {
                                encode_obj->header_startpos = prev->startPos + prev->size;
                            }
                        }
                        else
                        {
                            encode_obj->header_startpos = info->header_size + skip_bytes;
                        }

                        if (info->FL_CD_obj == NULL)
                        {
                            info->FL_CD_obj = encode_obj;
                        }
                        else
                        {
                            mma_drmsrv_FL_CD_obj_struct *tmp = info->FL_CD_obj;

                            while (tmp->next != NULL)
                            {
                                tmp = tmp->next;
                            }
                            tmp->next = encode_obj;
                        }
                        is_FL_CD_msg = KAL_TRUE;
                    }
                    mime_from_type = NULL;
                }
                prev = curr;
                curr = curr->next;
            }
            /* maximum chunk of memory is allocated here. Check for the parse process */
            if(mma_msgmgr_check_parsing_status())
            {
                /* Parsing is going on, check for memory */
                if(MSF_MEM_GET_AVAILABLE_FREE_MEMORY() < MMA_PARSING_DRM_ENCODING_REQD_FREE_MEMORY)
                {
                    /* not enough memory, delay the encoding procedure*/
                    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, 
                        MMA_DRMSRV_PARSE_NOT_ENOUGH_MEMORY, "(mma_drmsrv.c): Due to parse not enough memory"));
                    info->state = MMA_DRMSRV_STATE_FINISHING;
                    info->result = MMA_RESULT_FAIL_SUSPENDED_MODE;
                    action = MMA_DRMSRV_ACTION_CONTINUE;
                    break;
                }
            }
            if (is_FL_CD_msg)
            {
                char *r_path = NULL;
				kal_uint32 num_of_node_to_free = 0;

                r_path = (char*)MMAlib_getMessagePath(MSF_MODID_MMA, info->o_msg_id);
                info->r_handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, r_path, MSF_FILE_SET_RDONLY, 0, (mma_msg_storage_type_enum)info->storage_type);
                MMA_FREE(r_path);
                if (info->r_handle < 0)
                {
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_STATE_CHECK_MMS_OBJ_DRM_TYPE_READ_HANDLE, 
                        "(mma_drmsrv.c) info->r_handle %d < 0\n", info->r_handle));
                    info->result = translate_fs_result_to_mma(info->r_handle);
                    info->state = MMA_DRMSRV_STATE_FINISHING;
                    action = MMA_DRMSRV_ACTION_CONTINUE;
                    break;
                }

                info->w_handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, info->new_msg_filepath, MSF_FILE_SET_RDWR, 0, (mma_msg_storage_type_enum)info->storage_type);
                if (info->w_handle < 0)
                {
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_STATE_CHECK_MMS_OBJ_DRM_TYPE_WRITE_HANDLE,
                        "(mma_drmsrv.c) info->w_handle %d < 0\n", info->w_handle));
                    info->result = translate_fs_result_to_mma(info->w_handle);
                    info->state = MMA_DRMSRV_STATE_FINISHING;
                    action = MMA_DRMSRV_ACTION_CONTINUE;
                    break;
                }
                info->state = MMA_DRMSRV_STATE_COPY_MMS_CONTENT;
                info->sub_state = 0;
                info->r_byte = info->FL_CD_obj->header_startpos;
                info->w_byte = info->r_byte;
                info->r_offset = 0;
                info->w_offset = 0;
				/* ashok need to free the node from start to till first DRM FL node */
				/* ashok number contain the node number in the list */
				for(num_of_node_to_free = (info->FL_CD_obj->object->number - 1); num_of_node_to_free > 0; num_of_node_to_free--)
				{
					/* To free Top Node except the MMS Header. */
					MMSlib_freeMmsBodyInfoNode(MSF_MODID_MMA, info->header->header.g_header);
				}			

            }
            else
            {
                info->state = MMA_DRMSRV_STATE_FINISHING;
                info->result = MMA_RESULT_OK;
            }
            action = MMA_DRMSRV_ACTION_CONTINUE;
            break;
        }

        case MMA_DRMSRV_STATE_COPY_MMS_CONTENT:
        {
            long fs_result = 0;

            switch (info->sub_state)
            {
                case 0:
                {
                    if ((fs_result = MSF_FILE_SEEK(info->r_handle, info->r_offset, MSF_FILE_SEEK_SET)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_STATE_COPY_MMS_CONTENT_READ, "(mma_drmsrv.c %d) MSF_FILE_SEEK() %d < 0\n",
                                     __LINE__, fs_result));
                        info->result = translate_fs_result_to_mma(fs_result);
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                        break;
                    }

                    if ((fs_result = MSF_FILE_SEEK(info->w_handle, info->w_offset, MSF_FILE_SEEK_SET)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_STATE_COPY_MMS_CONTENT_WRITE, "(mma_drmsrv.c %d) MSF_FILE_SEEK() %d < 0\n",
                                     __LINE__, fs_result));
                        info->result = translate_fs_result_to_mma(fs_result);
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                        break;
                    }
                    info->r_offset += info->r_byte;
                    info->w_offset += info->w_byte;
                    info->sub_state = 1;
                    /* fall through */
                }

                case 1: /* read file */
                {
                    info->copy_buffer_size = (info->r_byte < MMS_MAX_CHUNK_SIZE) ? info->r_byte : MMS_MAX_CHUNK_SIZE;
					if (info->copy_buffer)
					{
						MMA_FREE (info->copy_buffer);
                        info->copy_buffer = NULL;
					}
                    info->copy_buffer = MMA_CALLOC(info->copy_buffer_size);
					if(!info->copy_buffer)
					{
						info->result = MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;
						info->state = MMA_DRMSRV_STATE_FINISHING;
						info->sub_state = 0;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
						break;
					}
                    if ((fs_result = MSF_FILE_READ(info->r_handle, info->copy_buffer, info->copy_buffer_size)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_STATE_COPY_MMS_CONTENT_READ_ERROR, 
                                     "(mma_drmsrv.c): MMA_DRMSRV_STATE_COPY_MMS_CONTENT read error %d", fs_result));
                        if ((info->result = translate_fs_result_to_mma(fs_result)) == MMA_RESULT_DELAYED)
                        {
                            MSF_FILE_SELECT(info->r_handle, MSF_FILE_EVENT_READ);
                            info->delayed_handle = info->r_handle;
                            MMA_FREE(info->copy_buffer);
                            info->result = MMA_RESULT_OK;
                            action = MMA_DRMSRV_ACTION_DELAYED;
                        }
                        else
                        {
                            MMA_FREE(info->copy_buffer);
                            info->state = MMA_DRMSRV_STATE_FINISHING;
                            action = MMA_DRMSRV_ACTION_CONTINUE;
                        }
                        break;
                    }
				    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_STATE_COPY_MMS_CONTENT_READ_STATUS, 
                                     "(mma_drmsrv.c): MMA_DRMSRV_STATE_COPY_MMS_CONTENT read from file:%d, buffer: %d", fs_result, info->copy_buffer_size));
                    
					info->copy_buffer_size = fs_result;
                    info->r_byte -= info->copy_buffer_size;
                    info->sub_state = 2;
                    /* fall through */
                }

                case 2: /* write file */
                {
                    if ((fs_result = MSF_FILE_WRITE(info->w_handle, info->copy_buffer, info->copy_buffer_size)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_STATE_COPY_MMS_CONTENT_WRITE_ERROR, 
                                     "(mma_drmsrv.c) MMA_DRMSRV_STATE_COPY_MMS_CONTENT write error %d", fs_result));
                        if ((info->result = translate_fs_result_to_mma(fs_result)) == MMA_RESULT_DELAYED)
                        {
                            MSF_FILE_SELECT(info->w_handle, MSF_FILE_EVENT_WRITE);
                            info->delayed_handle = info->w_handle;
                            info->result = MMA_RESULT_OK;
                            action = MMA_DRMSRV_ACTION_DELAYED;
                        }
                        else
                        {
                            MMA_FREE(info->copy_buffer);
                            info->state = MMA_DRMSRV_STATE_FINISHING;
                            action = MMA_DRMSRV_ACTION_CONTINUE;
                        }
                        break;
                    }
					MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_STATE_COPY_MMS_CONTENT_WRITE_STATUS, 
                                     "(mma_drmsrv.c) MMA_DRMSRV_STATE_COPY_MMS_CONTENT write in file:%d, buffer: %d", fs_result, info->copy_buffer_size));
                    if(info->copy_buffer_size != fs_result)
					{
						/* some error in write operation */
                        MMA_FREE(info->copy_buffer);
                        info->result = MMA_RESULT_FAIL_FILE_IO;
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                        info->sub_state = 0;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
						break;
					}
					info->w_byte -= fs_result;
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_STATE_COPY_MMS_CONTENT_STATUS, 
                                     "(mma_drmsrv.c) COPY_MMS_CONTENT_STATUS r_byte:%d w_byte:%d", info->r_byte, info->w_byte));
                    if (info->r_byte == 0 && info->w_byte == 0)
                    {
                        MMA_FREE(info->copy_buffer);
                        info->result = MMA_RESULT_OK;
                        if (info->FL_CD_obj != NULL)
                        {
                            info->state = MMA_DRMSRV_STATE_SET_DRM_OBJ_HEADER;
                        }
                        else
                        {
                            info->state = MMA_DRMSRV_STATE_FINISHING;
                        }
                        info->sub_state = 0;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                    }
                    else
                    {
                        /* We don't finish all I/O at one time, but divide as several rounds... */
                        MMA_SIGNAL_SENDTO_U(
                            MMA_SUBMODULE_MSG_DRMSRV,
                            MMA_INT_SIG_TYPE_MSG_DRMSRV_CONTINUE_IND,
                            info->req_id);
                        MMA_FREE(info->copy_buffer);
                        info->sub_state = 1;    /* read next portion */
                        action = MMA_DRMSRV_ACTION_DELAYED;
                    }
                    break;
                }
            }
            break;
        }

        case MMA_DRMSRV_STATE_SET_DRM_OBJ_HEADER:
        {
            long fs_result = 0;
			
			
            switch (info->sub_state)
            {
                case 0:
                {
                    if ((fs_result = MSF_FILE_SEEK(info->r_handle, info->r_offset, MSF_FILE_SEEK_SET)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_STATE_SET_DRM_OBJ_HEADER_FS_READ_ERROR, 
                            "(mma_drmsrv.c %d) MSF_FILE_SEEK() %d < 0\n",
                                     __LINE__, fs_result));
                        info->result = translate_fs_result_to_mma(fs_result);
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                        break;
                    }

                    if ((fs_result = MSF_FILE_SEEK(info->w_handle, info->w_offset, MSF_FILE_SEEK_SET)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_STATE_SET_DRM_OBJ_HEADER_FS_WRITE_ERROR,
                            "(mma_drmsrv.c %d) MSF_FILE_SEEK() %d < 0\n",
                                     __LINE__, fs_result));
                        info->result = translate_fs_result_to_mma(fs_result);
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                        break;
                    }
                    info->sub_state = 1;
                    /* fall through */
                }

                case 1: /* prepare object header */
                {
                    char *filepath = NULL;
                    char *vFileName = NULL;
                    unsigned char *externalFileName = NULL; /* translated UCS2 vitual file name */
                    kal_int32 handle = -1;
                    kal_uint8 o_body_len_bytes, new_body_len_bytes;
                    kal_int32 predict_encoded_size;
                    unsigned char *size_buf = NULL;
                    kal_char *o_header_buf = NULL;
                    kal_uint32 o_header_size = info->FL_CD_obj->object->startPos - info->FL_CD_obj->header_startpos;
                    kal_uint32 i, j;
                    char *replace_str = NULL;
                    kal_bool string_drm = KAL_FALSE;

                    o_header_buf = MMA_CALLOC(o_header_size);
                    if ((fs_result = MSF_FILE_READ(info->r_handle, o_header_buf, o_header_size)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_STATE_SET_DRM_OBJ_HEADER_READ_ERROR, 
                                     "(mma_drmsrv.c): MMA_DRMSRV_STATE_SET_DRM_OBJ_HEADER read error %d", fs_result));
                        if ((info->result = translate_fs_result_to_mma(fs_result)) == MMA_RESULT_DELAYED)
                        {
                            MSF_FILE_SELECT(info->r_handle, MSF_FILE_EVENT_READ);
                            info->delayed_handle = info->r_handle;
                            MMA_FREE(o_header_buf);
                            info->result = MMA_RESULT_OK;
                            action = MMA_DRMSRV_ACTION_DELAYED;
                        }
                        else
                        {
                            MMA_FREE(o_header_buf);
                            info->state = MMA_DRMSRV_STATE_FINISHING;
                            action = MMA_DRMSRV_ACTION_CONTINUE;
                        }
                        break;
                    }

                    filepath = (char*)MMAlib_getMessagePath(MSF_MODID_MMA, info->o_msg_id);
                    if ((handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, filepath, MSF_FILE_SET_RDONLY, 0, (mma_msg_storage_type_enum)info->storage_type)) >= 0)
                    {
                        vFileName = MMA_CALLOC(MMA_MAX_VIRTUAL_FILE_PATH_SIZE);
                        ASSERT(vFileName != NULL);
                        if ((fs_result = MSF_FILE_GEN_VIRTUAL_FILENAME(
                                            MSF_MODID_MMA,
                                            handle,
                                            vFileName,
                                            MMA_MAX_VIRTUAL_FILE_PATH_SIZE,
                                            info->FL_CD_obj->object->startPos,
                                            info->FL_CD_obj->object->size)) == HDI_FILE_OK)
                        {
                            externalFileName = (kal_uint8*) MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, vFileName,translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type) );
                            predict_encoded_size =
                                (kal_uint32) DRM_predict_encoded_size((kal_wchar*) externalFileName);
                            MMA_FREE(externalFileName);
                            MMA_FREE(filepath);
                            MMA_FREE(vFileName);
                            MSF_FILE_CLOSE(handle);

                            if (predict_encoded_size < 0)
                            {
                                mma_drmsrv_FL_CD_obj_struct *tmp = info->FL_CD_obj;

                                if (info->FL_CD_obj->next != NULL)
                                {
                                   info->r_byte = info->FL_CD_obj->next->header_startpos - info->r_offset;
                                }
                                else
                                {
                                   info->r_byte = info->header_size + info->body_size - info->r_offset;
                                }
                                info->w_byte = info->r_byte;

                                info->FL_CD_obj = info->FL_CD_obj->next;
                                MMA_FREE(tmp);
                                
                                info->result = MMA_RESULT_OK;
                                info->state = MMA_DRMSRV_STATE_COPY_MMS_CONTENT;
                                info->sub_state = 0;
                                action = MMA_DRMSRV_ACTION_CONTINUE;
                                MMA_FREE(o_header_buf);
                                break;
                            }
                            info->predict_encoded_size = predict_encoded_size;
                        }
                        else
                        {
                            info->result = translate_fs_result_to_mma(fs_result);
                            info->state = MMA_DRMSRV_STATE_FINISHING;
                            action = MMA_DRMSRV_ACTION_CONTINUE;
                            MMA_FREE(o_header_buf);
                            MMA_FREE(filepath);
                            MMA_FREE(vFileName);
                            MSF_FILE_CLOSE(handle);
                            break;
                        }
                    }
                    else
                    {
                        info->result = translate_fs_result_to_mma(handle);
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                        MMA_FREE(o_header_buf);
                        MMA_FREE(filepath);
                        break;
                    }

                    o_body_len_bytes = mma_get_uintvar_length_bytes(info->FL_CD_obj->object->size);
                    new_body_len_bytes = mma_get_uintvar_length_bytes(info->predict_encoded_size);
                    size_buf = MMA_CALLOC(new_body_len_bytes);
                    mma_convert_size_to_uintvar(info->predict_encoded_size, size_buf);

                    info->copy_buffer_size = o_header_size - o_body_len_bytes + new_body_len_bytes;
					if (info->copy_buffer != NULL)
					{
						MMA_FREE(info->copy_buffer);		// Ashok to check this
					}
                    info->copy_buffer = MMA_CALLOC(info->copy_buffer_size + 1);
                    for (i = 0; i < o_header_size && i < info->copy_buffer_size; i++)
                    {
                        info->copy_buffer[i] = o_header_buf[i];
                        if (o_header_buf[i] < 0x80)
                        {
                            break;
                        }
                    }
                    i++;

                    for (j = 0; j < new_body_len_bytes && (j + i) < info->copy_buffer_size; j++)
                    {
                        info->copy_buffer[j + i] = size_buf[j];
                    }
                    j += i;

                    for (i = i + o_body_len_bytes; i < o_header_size && j < info->copy_buffer_size; i++, j++)
                    {
                        info->copy_buffer[j] = o_header_buf[i];
                    }

                    /* replace content type MMS_MEDIA_TYPE_STRING_DRM1 with MMS_MEDIA_TYPE_STRING_DRM2 */
                    for (i = 0; i < info->copy_buffer_size; i++)
                    {
                        if (info->copy_buffer[i] == 'a')
                        {
                            replace_str = strstr((char *)(info->copy_buffer + i), MMA_MEDIA_TYPE_STRING_DRM1);
                            if (replace_str != NULL)
                            {
                                strncpy(replace_str, MMA_MEDIA_TYPE_STRING_DRM2, sizeof(MMA_MEDIA_TYPE_STRING_DRM1));
                                string_drm = KAL_TRUE;
                                break;
                            }
                        }
                    }
                    if(!string_drm)
                    {
                        /* Body header does not include string, it include enum */
                        /* Enum Position is (TAG + BODY_SIZE_BYTE +1) */
                        for (i = 0; i < info->copy_buffer_size; i++)
                        {
                            if (info->copy_buffer[i] < 0x80)
                            {
                                /* check the TAG */
                                break;
                            }
                        }
                        /* ENUM Position */
                        i = i + new_body_len_bytes + 1;
                        if (info->copy_buffer[i] == 0xC8)
                        {
                            /* C8 == MMA_MEDIA_TYPE_STRING_DRM1 & C9 == MMA_MEDIA_TYPE_STRING_DRM2 */
                            info->copy_buffer[i] = 0xC9;
                        }
                    }
                    
                    MMA_FREE(size_buf);
                    MMA_FREE(o_header_buf);
                    info->r_offset = info->FL_CD_obj->object->startPos + info->FL_CD_obj->object->size;
                    info->w_offset = info->w_offset + info->copy_buffer_size + info->predict_encoded_size;
                    info->new_obj_header_size = info->copy_buffer_size;
                    info->sub_state = 2;
                    /* fall through */
                }

                case 2: /* write object header and encode FL/CD object */
                {
                    char *vFileName = NULL;
                    unsigned char *externalSrcFileName = NULL;
                    kal_wchar *dest_filepath = NULL;
                    kal_int32 result;
                    kal_uint8 serial = 0;
                    long srcLen, dstLen;
                    
                    if ((fs_result = MSF_FILE_WRITE(info->w_handle, info->copy_buffer, info->copy_buffer_size)) < 0)
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_STATE_SET_DRM_OBJ_HEADER_WRITE_ERROR, 
                                     "(mma_drmsrv.c) MMA_DRMSRV_STATE_SET_DRM_OBJ_HEADER write error %d", fs_result));
                        if ((info->result = translate_fs_result_to_mma(fs_result)) == MMA_RESULT_DELAYED)
                        {
                            MSF_FILE_SELECT(info->w_handle, MSF_FILE_EVENT_WRITE);
                            info->delayed_handle = info->w_handle;
                            info->result = MMA_RESULT_OK;
                            action = MMA_DRMSRV_ACTION_DELAYED;
                        }
                        else
                        {
                            MMA_FREE(info->copy_buffer);
                            info->state = MMA_DRMSRV_STATE_FINISHING;
                            action = MMA_DRMSRV_ACTION_CONTINUE;
                        }
                        break;
                    }
                    MMA_FREE(info->copy_buffer);

                    vFileName = MMA_CALLOC(MMA_MAX_VIRTUAL_FILE_PATH_SIZE);
                    ASSERT(vFileName != NULL);
                    if ((fs_result = MSF_FILE_GEN_VIRTUAL_FILENAME(
                                        MSF_MODID_MMA,
                                        info->r_handle,
                                        vFileName,
                                        MMA_MAX_VIRTUAL_FILE_PATH_SIZE,
                                        info->FL_CD_obj->object->startPos,
                                        info->FL_CD_obj->object->size)) == HDI_FILE_OK)
                    {
                        externalSrcFileName = (kal_uint8*) MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, vFileName, translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)info->storage_type));
                        MMA_FREE(vFileName);
                    }
                    else
                    {
                        info->result = translate_fs_result_to_mma(fs_result);
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                        MMA_FREE(vFileName);
                        break;
                    }

                    srcLen = strlen(info->new_msg_filepath);
                    dstLen = (MMA_MAX_INTERNAL_FILENAME_LENGTH - 1) * sizeof(kal_wchar);
                    dest_filepath = MMA_CALLOC(MMA_MAX_INTERNAL_FILENAME_LENGTH * 2);
                    msf_charset_utf8_to_ucs2le(
                        (const char*)info->new_msg_filepath,
                        &srcLen,
                        (char*)dest_filepath,
                        &dstLen);
                    MSF_FILE_CLOSE(info->w_handle);
                    info->w_handle = -1;
                    result = DRM_encode_drm_message(
                                (kal_wchar*) externalSrcFileName,
                                (kal_wchar*) dest_filepath,
                                (info->w_offset - info->predict_encoded_size),
                                &serial,
                                (drm_general_callback) mma_drmsrv_encode_obj_done);
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_DRM_ENCODE_DRM_MESSAGE_API_RESULT, "MMA DRMSRV call DRM_encode_drm_message() result %d, serial %d", result, serial));

                    if (result == DRM_PROC_ENCRYPT_BUSY)
                    {
                        result = MMA_RESULT_OK;
                    }
                    
                    MMA_FREE(externalSrcFileName);
                    MMA_FREE(dest_filepath);

                    if (result < 0)
                    {
                        info->result = MMA_RESULT_FAIL;
                        info->state = MMA_DRMSRV_STATE_FINISHING;
                        action = MMA_DRMSRV_ACTION_CONTINUE;
                        break;
                    }

                    info->result = MMA_RESULT_OK;
                    info->state = MMA_DRMSRV_STATE_ENCODING_DRM_OBJ;
                    info->sub_state = 0;
                    action = MMA_DRMSRV_ACTION_DELAYED;
                    break;
                }
            }
            break;
        }
        
        case MMA_DRMSRV_STATE_ENCODING_DRM_OBJ:
        {
            mma_drmsrv_FL_CD_obj_struct *tmp = info->FL_CD_obj;

            info->w_handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, info->new_msg_filepath, MSF_FILE_SET_RDWR, 0, (mma_msg_storage_type_enum)info->storage_type);
            if (info->w_handle < 0)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_STATE_ENCODING_DRM_OBJ,
                    "(mma_drmsrv.c) info->w_handle %d < 0\n", info->w_handle));
                info->result = translate_fs_result_to_mma(info->w_handle);
                info->state = MMA_DRMSRV_STATE_FINISHING;
                action = MMA_DRMSRV_ACTION_CONTINUE;
                break;
            }

            if (info->FL_CD_obj->next == NULL)
            {
                info->FL_CD_obj = NULL;
                MMA_FREE(tmp);
                if (info->r_offset == (info->header_size + info->body_size))
                {
                    info->result = MMA_RESULT_OK;
                    info->state = MMA_DRMSRV_STATE_FINISHING;
                    action = MMA_DRMSRV_ACTION_CONTINUE;
                    break;
                }
                else
                {
                    info->r_byte = info->header_size + info->body_size - info->r_offset;
                    info->w_byte = info->r_byte;
                    info->result = MMA_RESULT_OK;
                    info->state = MMA_DRMSRV_STATE_COPY_MMS_CONTENT;
                    action = MMA_DRMSRV_ACTION_CONTINUE;
                    break;
                }
            }
            else
            {
                if (info->FL_CD_obj->object->next == info->FL_CD_obj->next->object)
                {
                    /* case of consecutive drm object */
					info->FL_CD_obj = info->FL_CD_obj->next;
					/* ashok, free the current drm node */
					MMSlib_freeMmsBodyInfoNode(MSF_MODID_MMA, info->header->header.g_header);
                    MMA_FREE(tmp);
                    info->state = MMA_DRMSRV_STATE_SET_DRM_OBJ_HEADER;
                    info->result = MMA_RESULT_OK;
                    action = MMA_DRMSRV_ACTION_CONTINUE;
                    break;
                }
                else
                {
					kal_uint32 num_of_nodes_to_free = info->FL_CD_obj->next->object->number - info->FL_CD_obj->object->number;
					info->FL_CD_obj = info->FL_CD_obj->next;
                    MMA_FREE(tmp);
                    info->r_byte = info->FL_CD_obj->header_startpos - info->r_offset;
                    info->w_byte = info->r_byte;
                    info->result = MMA_RESULT_OK;
                    info->state = MMA_DRMSRV_STATE_COPY_MMS_CONTENT;
					for(; num_of_nodes_to_free > 0; num_of_nodes_to_free--)
					{
						/* To free Top Node except the MMS Header. */
						MMSlib_freeMmsBodyInfoNode(MSF_MODID_MMA, info->header->header.g_header);
					}
                    action = MMA_DRMSRV_ACTION_CONTINUE;
                    break;
                }
            }
        }

        case MMA_DRMSRV_STATE_FINISHING:
        {

            if (info->result == MMA_RESULT_OK)
            {
                MSF_FILE_SETSIZE(info->w_handle, info->w_offset);
            }

            if (info->r_handle >= 0)
            {
                MSF_FILE_CLOSE(info->r_handle);
                info->r_handle = -1;
            }

            if (info->w_handle >= 0)
            {
                MSF_FILE_CLOSE(info->w_handle);
                info->w_handle = -1;
            }

            if (info->result == MMA_RESULT_OK && info->encode_obj_num > 0)
            {
                mma_drmsrv_send_rsp(info->req_id, info->o_msg_id, info->result, TRUE);
            }
            else
            {
                mma_drmsrv_send_rsp(info->req_id, info->o_msg_id, info->result, FALSE);
            }

            info->sub_state = 0;
            mma_drmsrv_delete_task_hdlr(info->req_id);
            break;
        }
    }

    return action;
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_fsm_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_drmsrv_fsm_hdlr(kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *req = NULL;
    mma_drmsrv_info_struct *info = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((req = mma_drmsrv_get_task_by_req(req_id)) == NULL)
    {
        return;
    }
    if (g_mma_drmsrv_cntx.env_state == MMA_DRMSRV_ENV_STATE_ACTIVE)
    {
        ASSERT(req->data != NULL);
        info = (mma_drmsrv_info_struct*) req->data;
        while (mma_drmsrv_fsm(info) == MMA_DRMSRV_ACTION_CONTINUE);
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    else if (g_mma_drmsrv_cntx.env_state == MMA_DRMSRV_ENV_STATE_MEM_CARD_PLUG_OUT)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FAILED_CARD_PLUG_OUT, "(mma_drmsrv.c) MMA_DRMSRV_FAILED_CARD_PLUG_OUT"));

        ASSERT(req != NULL && req->data != NULL);
        info = (mma_drmsrv_info_struct*) req->data;
        mma_drmsrv_send_rsp(req->first_id, info->o_msg_id, MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT, 0);
        mma_drmsrv_delete_task_hdlr(req->first_id);
        g_mma_drmsrv_cntx.env_state = MMA_DRMSRV_ENV_STATE_ACTIVE;

    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_FSM_HDLR, "(mma_drmsrv.c) state %d\n", g_mma_drmsrv_cntx.env_state));
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_encode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_drmsrv_encode_req_hdlr(kal_uint32 req_id, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_drmsrv_info_struct *encode_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_ENCODE_REQ_HDLR, "DRMSRV receive DRM_ENCODE_REQ: msg_id %d, req_id %d", msg_id,
                 req_id));

    if (mma_msgmgr_msg_info_exist(msg_id) == FALSE)   /* invalid msg id */
    {
        mma_drmsrv_send_rsp(req_id, msg_id, MMA_RESULT_FAIL_INVALID_MSGID, 0);
    }
    else if (mma_main_is_in_usb_mode())
    {
        mma_drmsrv_send_rsp(req_id, msg_id, MMA_RESULT_FAIL_IN_USB_MODE, 0);
    }
    else if (mma_main_is_in_terminate())
    {
        mma_drmsrv_send_rsp(req_id, msg_id, MMA_RESULT_FAIL_TERMINATING, 0);
    }
    /* need to check for the space */
    else
    {
        if(mma_msgmgr_check_parsing_status())
        {
            /* Parsing is going on, check for memory */
            if(MSF_MEM_GET_AVAILABLE_FREE_MEMORY() < MMA_PARSING_DRM_ENCODING_REQD_FREE_MEMORY)
            {
                /* not enough memory, delay the encoding procedure*/
                MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, 
                            MMA_DRMSRV_PARSE_NOT_ENOUGH_MEMORY, "(mma_drmsrv.c): Due to parse not enough memory"));
                mma_drmsrv_send_rsp(req_id, msg_id, MMA_RESULT_FAIL_SUSPENDED_MODE, 0);
                return;
            }
        }
        {
            kal_char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH] = {0};
		    char *temp_path = NULL;
            char *temp_path_utf8 = NULL;
		    int file_path_len = 0;
            kal_uint8 mms_storage_type = mma_get_mms_type_message_storage(msg_id);
		    mma_msgmgr_get_encode_filepath(msg_id, file_path);
            temp_path = (char *)MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, file_path, (msf_mms_storage_enum)mms_storage_type);
		    memset(file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
            temp_path_utf8 = mma_ucs2_to_utf8_string((const kal_wchar *) temp_path);
		    strcpy(file_path, temp_path_utf8);
            MMA_FREE(temp_path);
            MMA_FREE(temp_path_utf8);
            if (MSF_FILE_GETSIZE_EXT(file_path, (msf_mms_storage_enum)mms_storage_type) < 0) /* invalid new msg filepath */
            {
                mma_drmsrv_send_rsp(req_id, msg_id, MMA_RESULT_FAIL_INVALID_PARAMETER, 0);
                return;
            }
            file_path_len = strlen(file_path);
            encode_req = (mma_drmsrv_info_struct*) MMA_CALLOC(sizeof(mma_drmsrv_info_struct));
            encode_req->req_id = req_id;
            encode_req->o_msg_id = msg_id;
            encode_req->new_msg_filepath = MMA_CALLOC(file_path_len + 1);
            strncpy(encode_req->new_msg_filepath, file_path, file_path_len);
            encode_req->r_handle = -1;
            encode_req->r_byte = 0;
            encode_req->w_handle = -1;
            encode_req->w_byte = 0;
            encode_req->delayed_handle = -1;
            encode_req->state = MMA_DRMSRV_STATE_IDLE;
            encode_req->result = MMA_RESULT_OK;
            encode_req->msg_state = MMA_MSG_STATE_NULL;
            encode_req->body_header = NULL;
            encode_req->FL_CD_obj = NULL;
            encode_req->storage_type = mma_get_message_storage(msg_id);


            if (mma_insert_node_to_queue(&(g_mma_drmsrv_cntx.task_queue), encode_req->req_id, 0, encode_req, MMA_ACTION_DRMSRV_PROCESS) !=
                MMA_RESULT_OK)
            {
                ASSERT(0);
            }

            if (g_mma_drmsrv_cntx.task_queue->first_id == encode_req->req_id)       /* One active task at a time */
            {
                mma_reset_last_tick();
                mma_drmsrv_fsm_hdlr(encode_req->req_id);
            }
            else
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_ENCODE_REQ_HDLR_NO_ACTIVE_TASK, "(mma_drmsrv.c): Request %d for msg %d queued",
                             encode_req->req_id, encode_req->o_msg_id));
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_process_int_sig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mma_drmsrv_process_int_sig(mma_signal_struct *sig)
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
        case MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_REQ:
        {
            mma_drmsrv_encode_req_hdlr(sig->u_param1, sig->u_param2);
            break;
        }

        case MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_DONE:
        {
            wap_mma_drm_encode_done_ind_struct *encode_done_ind = sig->p_param;
            mma_reset_last_tick();

            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_MSG_DRM_ENCODE_DONE,
                         "MMA DRMSRV recv MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_DONE: ret = %d", encode_done_ind->result));
            if (g_mma_drmsrv_cntx.task_queue != NULL)
            {
                mma_drmsrv_info_struct *info = NULL;

                mma_drmsrv_handle_drm_encode_result(encode_done_ind->result);
                info = (mma_drmsrv_info_struct*) g_mma_drmsrv_cntx.task_queue->data;
                mma_drmsrv_fsm_hdlr(info->req_id);
            }
			MMA_FREE(encode_done_ind);
            break;
        }

        case MMA_INT_SIG_TYPE_MSG_DRMSRV_CONTINUE_IND:
        {
            mma_drmsrv_fsm_hdlr(sig->u_param1);
            break;
        }

        case MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ:
        {
            mms_mma_queue_struct *curr = g_mma_drmsrv_cntx.task_queue;

            g_mma_drmsrv_cntx.env_state = MMA_DRMSRV_ENV_STATE_ENTERING_USB;
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_MSG_ENTER_USB_REQ,  "DRMSRV recv MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ"));
            if (curr != NULL)
            {
                mma_drmsrv_info_struct *info = (mma_drmsrv_info_struct*) curr->data;

                mma_drmsrv_send_rsp(info->req_id, info->o_msg_id, MMA_RESULT_FAIL_IN_USB_MODE, 0);
                mma_drmsrv_delete_task_hdlr(curr->first_id);
            }
            else
            {
                g_mma_drmsrv_cntx.env_state = MMA_DRMSRV_ENV_STATE_ACTIVE;
                MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
            }
            break;
        }

        case MMA_INT_SIG_TYPE_MSG_TERMINATE_IND:
        {
            mms_mma_queue_struct *curr = g_mma_drmsrv_cntx.task_queue;

            g_mma_drmsrv_cntx.env_state = MMA_DRMSRV_ENV_STATE_TERMINATING;
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_MSG_TERMINATE_IND, "DRMSRV recv MMA_INT_SIG_TYPE_MSG_TERMINATE_IND"));
            if (curr != NULL)
            {
                mma_drmsrv_info_struct *info = (mma_drmsrv_info_struct*) curr->data;

                mma_drmsrv_send_rsp(info->req_id, info->o_msg_id, MMA_RESULT_FAIL_TERMINATING, 0);
                mma_drmsrv_delete_task_hdlr(curr->first_id);
            }
            else
            {
                MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
            }
            break;
        }

        case MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_NEXT_IND:
        {
            if (g_mma_drmsrv_cntx.task_queue != NULL)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_MSG_DRM_ENCODE_NEXT_IND, "(mma_drmsrv.c): Queued request %d start", g_mma_drmsrv_cntx.task_queue->first_id));
                mma_drmsrv_fsm_hdlr(g_mma_drmsrv_cntx.task_queue->first_id);
            }
            break;
        }

        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_is_busy_on_storage
 * DESCRIPTION
 *  Will check, if busy on storage
 * PARAMETERS
 *  card_enum        [IN]        
 * RETURNS
 *  bool
 *****************************************************************************/

kal_bool mma_drmsrv_is_busy_on_storage(kal_uint8 card_enum)
{
    mms_mma_queue_struct *curr = g_mma_drmsrv_cntx.task_queue;

    while (curr != NULL)
    {
        mma_drmsrv_info_struct *info =
                    (mma_drmsrv_info_struct*) curr->data;
        if (info != NULL && info->storage_type == card_enum)
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_IS_BUSY_ON_STORAGE, "(mma_drmsrv.c) mma_drmsrv_is_busy_on_storage(): %d", card_enum));

            return KAL_TRUE;
        }
        curr = curr->next;
    }

    return KAL_FALSE;
}

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_drmsrv_memory_card_plug_out_callback
 * DESCRIPTION
 *  Callback function for memory card plug out
 * PARAMETERS
 *  plugout_card        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_drmsrv_memory_card_plug_out_callback(kal_uint8 plugout_card)
{
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_CARD_PLUG_OUT_CALLBACK, "(mma_drmsrv.c) mma_drmsrv_memory_card_plug_out_callback()"));
    if (mma_drmsrv_is_busy_on_storage(plugout_card))
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_DRMSRV_CHANGE_STATE_TO_CARD_PLUG_OUT, "(mma_drmsrv.c) MMA_DRMSRV_CHANGE_STATE_TO_CARD_PLUG_OUT"));
        g_mma_drmsrv_cntx.env_state = MMA_DRMSRV_ENV_STATE_MEM_CARD_PLUG_OUT;
    }
}
#endif /*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/


#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
#endif /* MMS_SUPPORT */
#endif /* _MMA_DRMSRV_C */
