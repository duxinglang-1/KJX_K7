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
 * mma_env.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains MMA core functions, like MMAc_start, MMAc_wantsToRun.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMA_ENV_C
#define _MMA_ENV_C

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

#include "mmi_platform.h"
#include "FileManagerGProt.h"
#include "fmt_struct.h"       /* For handling MSG_ID_MMI_FMT_FORMAT_REQ */



/* WAPADP */
#include "mmsadp.h"

/* APPLIB */
#include "app_mine.h"

/* Plutommi */
#include "MMI_features.h"
#include "MMIDataType.h"
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
#include "msf_errc.h"
/* STK */
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "stk_if.h"     /* STK: WSP/HTTP Stack signals and types */
#else
#include "nts_if.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/


/* MMS */
#include "mms_cfg.h"    /* MMS: Configuration definitions */
#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_if.h"
#include "mconfig.h"
#include "msig.h"
#include "mmem.h"
#include "mmsl_if.h"
#include "fldmgr.h"
/* SLS */
#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"

/* MMA */
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_env.h"
#include "mma_interface.h"
#include "mma_main.h"
#include "mma_msg_struct.h"
#include "mma_parse.h"
#include "mma_create.h"
#include "mma_msgmgr.h"
#include "mma_sendrecv.h"
#include "mma_setting.h"
#include "mma_utilities.h"
#include "mma_mime.h"
#include "mma_drmsrv.h"
#ifdef __MMI_VCARD__
#include "MmsSrvGprot.h"
#endif // __MMI_VCARD__

/***************************************************************************** 
* Define
*****************************************************************************/
#define MMA_VERSION   "UNI1-0.1"
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local static Variable
*****************************************************************************/
static mma_env_context_struct mma_env_context = {0, };
static mtk_jmpbuf mma_jmpbuf;  /* Buffer for longjmp */

/* Both are using in multiple files. */
mma_signal_struct *g_mms_mma_int_sig_queue_list_p = NULL;
mms_mma_queue_struct *g_mma_wrapper_queue = NULL;

kal_mutexid mma_ctrl_mutex = NULL;

/***************************************************************************** 
* Local Function
*****************************************************************************/

char *g_mms_mma_accept_header = NULL;
char g_mms_owner_number[MMA_MAX_ADDR_LEN] = {0};


/*****************************************************************************
 * FUNCTION
 *  mma_get_int_sig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig_list_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_signal_struct *mma_get_int_sig(mma_signal_struct **sig_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_signal_struct *next_sig_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sig_list_p == NULL || *sig_list_p == NULL)
    {
        return NULL;
    }

    next_sig_p = *sig_list_p;
    *sig_list_p = (*sig_list_p)->next;
    next_sig_p->next = NULL;
    return next_sig_p;
}


/*****************************************************************************
 * FUNCTION
 *  mma_send_int_sig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig_list        [IN]        
 *  dst             [IN]        
 *  type            [IN]        
 *  i_param         [IN]        
 *  u_param1        [IN]        
 *  u_param2        [IN]        
 *  u_param3        [IN]        
 *  p_param         [?]
 * RETURNS
 *  void
 *****************************************************************************/
MSF_BOOL mma_send_int_sig(
            mma_signal_struct **sig_list,
            int dst,
            int type,
            /* mma_submodule_enum */ long i_param,
            unsigned long u_param1,
            unsigned long u_param2,
            unsigned long u_param3,
            void *p_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_signal_struct *new_node_p = NULL;
    mma_signal_struct *list_tmp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_node_p = (mma_signal_struct*) MMA_CALLOC(sizeof(mma_signal_struct));
    ASSERT(sig_list);
    ASSERT(new_node_p);

    new_node_p->dst = dst;
    new_node_p->i_param = i_param;
    new_node_p->p_param = p_param;
    new_node_p->u_param1 = u_param1;
    new_node_p->u_param2 = u_param2;
    new_node_p->u_param3 = u_param3;
    new_node_p->type = type;

    if (*sig_list == NULL)
    {
        *sig_list = new_node_p;
        return TRUE;
    }

    list_tmp_p = *sig_list;
    while (list_tmp_p->next != NULL)
    {
        list_tmp_p = (mma_signal_struct*) list_tmp_p->next;
    }
    list_tmp_p->next = (mma_signal_struct*) new_node_p;
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_ENV_SEND_INT_SIGNAL_DETAIL,
                      "SndSig,%d,%d,%d,%d", (int)dst, (int)type, (int)i_param, (int)u_param1));
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_delete_int_sig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_delete_int_sig(mma_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMA_FREE(sig);
}


/*****************************************************************************
 * FUNCTION
 *  mma_exception_handler
 * DESCRIPTION
 *  This function is used to handle memory exceptions and to emergency stop the MMA service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_exception_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_env_context.mma_inside_run)
    {
        longjmp(mma_jmpbuf, 1);
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA,
                          MMA_ENV_MMA_EXCEPTION_HANDLER_MSG, "%s(%d): Insufficient memory!\n", __FILE__,
                          __LINE__));
		ASSERT(0);
    }   /* if */
}       /* mma_exception_handler */


/*****************************************************************************
 * FUNCTION
 *  mma_msg_hdlr
 * DESCRIPTION
 *  This function is used to handle ilm signal passed to MMA
 * CALLS
 *  
 * PARAMETERS
 *  p       [IN]     
 * RETURNS
 *  
 *****************************************************************************/
int mma_msg_hdlr(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_BOOL is_our_primitive = TRUE;
    ilm_struct *ilm_ptr = (ilm_struct*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mma_env_context.last_ilm.msg_id == 0)
	{
		memcpy(&(mma_env_context.last_ilm), ilm_ptr, sizeof(ilm_struct));
	}
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MMS_ENTER_USB_MODE_REQ:
        {
            MMAif_enterUSBMode();
            break;
        }
        case MSG_ID_MMS_EXIT_USB_MODE_REQ:
        {
            MMAif_exitUSBMode();
            break;
        }
        case MSG_ID_MMI_UM_GET_MSG_NUM_REQ:
        {
            srv_um_get_msg_num_req_struct *msg_num_req = (srv_um_get_msg_num_req_struct*) ilm_ptr->local_para_ptr;

            if (msg_num_req != NULL && msg_num_req->msg_type == SRV_UM_MSG_MMS)
            {
                MMAif_getUmMsgNum(ilm_ptr->src_mod_id, (srv_um_get_msg_num_req_struct*) ilm_ptr->local_para_ptr);
            }
            else
            {
                is_our_primitive = FALSE;
            }
            break;
        }
        case MSG_ID_MMI_UM_GET_MSG_LIST_REQ:
        {
            srv_um_get_msg_list_req_struct *get_list_req = (srv_um_get_msg_list_req_struct*) ilm_ptr->local_para_ptr;

            if (get_list_req != NULL && get_list_req->msg_type == SRV_UM_MSG_MMS)
            {
                MMAif_getUmMsgList(ilm_ptr->src_mod_id, (srv_um_get_msg_list_req_struct*) ilm_ptr->local_para_ptr);
            }
            else
            {
                is_our_primitive = FALSE;
            }
            break;
        }
        case MSG_ID_MMI_UM_DELETE_FOLDER_REQ:
        {
            srv_um_delete_folder_req_struct *delete_folder_req =
                (srv_um_delete_folder_req_struct*) ilm_ptr->local_para_ptr;

            if (delete_folder_req != NULL && delete_folder_req->msg_type == SRV_UM_MSG_MMS)
            {
                MMAif_deleteFolder(ilm_ptr->src_mod_id, delete_folder_req);
            }
            else
            {
                is_our_primitive = FALSE;
            }
            break;
        }
        case MSG_ID_WAP_MMA_SAVE_REQ:
        {
            MMAif_saveMsg(ilm_ptr->src_mod_id, (wap_mma_save_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WAP_MMA_GET_SETTING_REQ:
        {
            MMAif_getSetting(ilm_ptr->src_mod_id, (wap_mma_get_setting_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WAP_MMA_SET_SETTING_REQ:
        {
            MMAif_setSetting(ilm_ptr->src_mod_id, (wap_mma_set_setting_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_GET_MEM_STATUS_REQ:
        {
            MMAif_getMemStatus(ilm_ptr->src_mod_id, (wap_mma_get_mem_status_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_SET_PROFILE_REQ:
        {
            MMAif_setProfile(ilm_ptr->src_mod_id, (wap_mma_set_profile_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_GET_CONTENT_REQ:
        {
            MMAif_parseMsg(ilm_ptr->src_mod_id, (wap_mma_get_content_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_CREATE_REQ:
        {
            MMAif_createMsg(ilm_ptr->src_mod_id, (wap_mma_create_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_FREE_MMS_CONTENT:
        {
            MMAif_freeContentMem(ilm_ptr->src_mod_id, (wap_mma_free_content_info_struct*) ilm_ptr->local_para_ptr);
            break;
        }

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MSG_ID_WAP_MMA_DELETE_REQ:
        {
            MMAif_deleteMsg(ilm_ptr->src_mod_id, (wap_mma_delete_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
        case MSG_ID_WAP_MMA_SEND_REQ:
        {
            MMAif_sendMessage(ilm_ptr->src_mod_id, (wap_mma_send_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_CANCEL_SEND_REQ:
        {
            MMAif_cancelSendMessage(ilm_ptr->src_mod_id, (wap_mma_cancel_send_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_DOWNLOAD_REQ:
        {
            MMAif_downloadMessage(ilm_ptr->src_mod_id, (wap_mma_download_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_REQ:
        {
            MMAif_cancelDownloadMessage(
                ilm_ptr->src_mod_id,
                (wap_mma_cancel_download_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_DOWNLOAD_RES:
        {
            MMAif_downloadRes(ilm_ptr->src_mod_id, (wap_mma_download_res_struct*) ilm_ptr->local_para_ptr);
            break;
        }

#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
        case MSG_ID_WAP_MMA_GET_MSG_INFO_REQ:
        {
            MMAif_getMsgInfo(ilm_ptr->src_mod_id, (wap_mma_get_msg_info_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_WAP_MMA_GET_MSG_LIST_REQ:
        {
            MMAif_getMsgList(ilm_ptr->src_mod_id, (wap_mma_get_msg_list_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
		case MSG_ID_WAP_MMA_GET_MSG_NUM_REQ:
        {
            MMAif_getUmmsMsgNum(ilm_ptr->src_mod_id, (wap_mma_get_msg_num_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
#endif /* MMA_JSR_PST_MMS_OPERATON_SUPPORT */

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MSG_ID_WAP_MMA_SET_APP_DATA_REQ:
        {
            MMAif_SetAppData(ilm_ptr->src_mod_id, (wap_mma_set_app_data_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WAP_MMA_SET_READMARK_REQ:
        {
            MMAif_SetReadmark(ilm_ptr->src_mod_id, (wap_mma_set_readmark_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WAP_MMA_MSG_IS_VALID_REQ:
        {
            MMAif_ValidateMsg(ilm_ptr->src_mod_id, (wap_mma_msg_is_valid_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
        case MSG_ID_WAP_MMA_MMS_OBJ_IND:
        {
            MMAif_recvObjInd(ilm_ptr->src_mod_id, (wap_mma_mms_obj_ind_struct*) ilm_ptr->local_para_ptr);
            break;
        }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MSG_ID_WAP_MMA_GET_UNREAD_MSG_LIST_REQ:
        {
            MMAif_getUnreadMsgList(
                ilm_ptr->src_mod_id,
                (wap_mma_get_unread_msg_list_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
        case MSG_ID_WAP_MMA_GET_RECENT_EVT_LIST_REQ:
        {
            MMAif_getRecentEvtList(
                ilm_ptr->src_mod_id,
                (wap_mma_get_recent_evt_list_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WAP_MMA_DELETE_RECENT_EVT_REQ:
        {
            MMAif_deleteRecentEvt(
                ilm_ptr->src_mod_id,
                (wap_mma_delete_recent_evt_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
#endif
        #ifdef __MMI_MMS_MMA_DRM_ENCODING__
		case MSG_ID_WAP_MMA_DRM_ENCODE_DONE_IND:
        {
            MMAif_drmEncodeDone(ilm_ptr->src_mod_id, (wap_mma_drm_encode_done_ind_struct*) ilm_ptr->local_para_ptr);
            break;
        }
		#endif
		case MSG_ID_MMS_TARGET_DATA_IND:
        {
            MMAif_handle_target_dat_ind(ilm_ptr->src_mod_id, (mms_target_data_ind_struct*) ilm_ptr->local_para_ptr, (peer_buff_struct*) ilm_ptr->peer_buff_ptr);
            break;
        }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MSG_ID_WAP_MMA_GET_MSG_PROPERTY_REQ:
        {
            MMAif_getMsgProperty(ilm_ptr->src_mod_id, (wap_mma_get_msg_property_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WAP_MMA_GET_MSG_ATTR_AND_THUMBNAIL_REQ:
        {
            MMAif_getMsgAttrTMBReq(ilm_ptr->src_mod_id, (wap_mma_get_mms_thumbnail_and_attr_info_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#ifdef __MMI_VCARD__
		case MSG_ID_MMI_UMMS_GET_VCARD_VERSION_RSP:
		{
			extern void MMAif_isvcardrestrictedrsp(srv_mms_get_vcard_version_rsp_struct  *mms_mma_vcard_version_p);
			MMAif_isvcardrestrictedrsp((srv_mms_get_vcard_version_rsp_struct*) ilm_ptr->local_para_ptr);
			break;
		}
#endif  // __MMI_VCARD__
        case MSG_ID_MMI_UM_GET_MSG_INFO_REQ:
        {
            srv_um_get_msg_info_req_struct *get_msg_info_req =
                (srv_um_get_msg_info_req_struct*) ilm_ptr->local_para_ptr;

            if (get_msg_info_req != NULL && get_msg_info_req->msg_type == SRV_UM_MSG_MMS)
            {
                MMAif_getUmMsgInfo(ilm_ptr->src_mod_id, (srv_um_get_msg_info_req_struct*) ilm_ptr->local_para_ptr);
            }
            else
            {
                is_our_primitive = FALSE;
            }
            break;
        }

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MSG_ID_WAP_MMA_RR_MARK_REQ:
        {
            MMAif_markRRStatus(ilm_ptr->src_mod_id, (wap_mma_rr_mark_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        case MSG_ID_MMI_MMS_CARD_PLUG_IN_IND:
            {
                mms_mem_card_plug_in_out_struct  *card_info = (mms_mem_card_plug_in_out_struct*) 
                                                                    ilm_ptr->local_para_ptr;

                if (card_info != NULL)
                {
                    MMAif_handleMemCardPlugInReq(card_info);
                }


                break;
            }

        case MSG_ID_MMI_MMS_CARD_PLUG_OUT_IND:
            {
                mms_mem_card_plug_in_out_struct  *card_info = (mms_mem_card_plug_in_out_struct*) 
                                                    ilm_ptr->local_para_ptr;

                if (card_info != NULL)
                {
                    MMAif_handleMemCardPlugOutReq(card_info);
                }


                break;
            }
        case MSG_ID_WAP_MMA_CHG_MSG_STORAGE_REQ:
        {
            MMAif_chgMsgStorage(ilm_ptr->src_mod_id, (wap_mma_change_msg_storage_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__ 

             case MSG_ID_MMI_FMT_FORMAT_REQ:
             {
                MMAif_SendFmtFormatInd(ilm_ptr->local_para_ptr);
                break;
             }
#endif /* __MMI_FMGR_HIDE_FORMAT_DRIVE__ */

#ifdef __MMI_MMS_USE_ASM__

        case MSG_ID_MMI_MMS_GET_ASM_MEM_PTR_RSP:
        {
            MMAif_asmMemRsp((void*)ilm_ptr->local_para_ptr);
            break;
        }

        case MSG_ID_MMI_MMS_GET_DEINIT_SERVICE_ASM_REQ:
        {
            MMAif_deinitasmMem((void*)ilm_ptr->local_para_ptr);
            break;
        }
#endif  /* __MMI_MMS_USE_ASM__*/
#ifdef __MMI_MMS_CONVERSATION_BOX_SUPPORT__
         case MSG_ID_MMI_UM_TRAVERSE_MSG_REQ:
         {
            MMAif_UMtraverseMmsList(ilm_ptr->src_mod_id, (srv_um_traverse_msg_req_struct*)ilm_ptr->local_para_ptr);
            break;
         }
#endif  /* __MMI_MMS_CONVERSATION_BOX_SUPPORT__ */
         case MSG_ID_MMI_MMS_SYNC_DELETE_IND:
         {
             MMAif_SyncDeleteMsg((mms_sync_delete_msg_ind_struct*) ilm_ptr->local_para_ptr);
             break;
         }
     #ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
         case MSG_ID_MMI_MMS_CPY_TO_ARCHIVE_REQ:
         {
             MMAif_CopyMsgToArchive(ilm_ptr->src_mod_id, (wap_mma_cpy_msg_to_archive_folder_req_struct*) ilm_ptr->local_para_ptr);
             break;
         }
    #endif   /* __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__ */
#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
         case MSG_ID_WAP_MMA_DEF_TMPLT_GEN_DONE_IND:
         {
             MMAif_mmsCheckTemplateRsp((wap_mma_check_template_rsp_struct*) ilm_ptr->local_para_ptr);
             break;
         }
    #endif  /* __COSMOS_MMI_PACKAGE__ */
        default:
            is_our_primitive = FALSE;
            break;
    }

	if (mma_env_context.last_ilm.msg_id == ilm_ptr->msg_id)
	{
		mma_env_context.last_ilm.msg_id = (msg_type)0;
	}

    return is_our_primitive;
}


/*****************************************************************************
 * FUNCTION
 *  mmaMsfHandleExtSignal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig             [IN]        
 *  sig_data        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmaMsfHandleExtSignal(MSF_UINT16 sig, void *sig_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sig)
    {

        case MSF_SIG_MODULE_TERMINATE:
        {
            mms_mma_send_um_ready_ind(MOD_MMI, KAL_FALSE);
            /* Sub-module termination order: MAIN&&PARSE->CREATE->SENDRECV->MSGMGR */
            mma_main_enter_terminate_mode();

			if (mma_env_context.last_ilm.msg_id != 0)
			{
			   mma_msg_hdlr (&(mma_env_context.last_ilm));
			   free_ilm(&(mma_env_context.last_ilm));
			   mma_env_context.is_terminate_pending = KAL_TRUE;
			}
			else
			{
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
	            MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_DRMSRV, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
#else
		        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
			}
            mms_mma_send_ilm(NULL, NULL, MSG_ID_WAP_MMA_TERMINATE_IND, MOD_MMI);
            break;
        }

        case MSF_SIG_MODULE_STATUS: /* handle SLS status */
        {
            msf_module_status_t *st = (msf_module_status_t*) sig_data;

            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA,
                              MMA_ENV_GET_SIG_MODULE_STATUS,
                              "MMA: received signal MSF_SIG_MODULE_STATUS (%d, %d)\n", st->modId, st->status));

            /* handle the received module status */
       /*     if (st->modId == MSF_MODID_SLS)
            {
            if (mma_parse_handle_rsp(MSF_SIG_MODULE_STATUS, (void*)st) == TRUE)
            {
                mms_mma_queue_struct *task = mma_parse_get_active_task();

                mma_parse_fsm_hdlr(task->first_id);
            }
            }*/
			MMA_FREE(st->modVersion);
            break;
        }

        case MSF_SIG_FILE_NOTIFY:
        {
            msf_file_notify_t *notify = sig_data;

            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_ENV_GET_SIG_FILE_NOTIFY,
                              "MMA receive MSF_SIG_FILE_NOTIFY (fh %d, event %d)\n", notify->fileHandle,
                              notify->eventType));
            if (mma_create_handle_rsp(MSF_SIG_FILE_NOTIFY, notify) == TRUE)
            {
                mms_mma_queue_struct *task = mma_create_get_active_task();

                mma_create_fsm_hdlr(task->first_id);
            }
            else if (mma_parse_handle_rsp(MSF_SIG_FILE_NOTIFY, notify) == TRUE)
            {
                mms_mma_queue_struct *task = mma_parse_get_active_task();

                mma_parse_fsm_hdlr(task->first_id);
            }
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
            else if (mma_drmsrv_handle_rsp(MSF_SIG_FILE_NOTIFY, notify) == TRUE)
            {
                mms_mma_queue_struct *task = mma_drmsrv_get_active_task();
                MMA_SIGNAL_SENDTO_U(MMA_SUBMODULE_MSG_DRMSRV, MMA_INT_SIG_TYPE_MSG_DRMSRV_CONTINUE_IND, task->first_id);
            }
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
            break;
        }

        default:
            /* Received unsupported signal! */
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,
                              MMA_ENV_GET_SIG_UNHANDLED_SIGNAL,
                              "%s(%d): Received unhandled signal %d from MSM\n", __FILE__, __LINE__, sig));
            break;
    }
    MMA_FREE(sig_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmaMMSHandleExtSignal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig             [IN]        
 *  sig_data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmaMMSHandleExtSignal(MSF_UINT16 sig, void *sig_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sig)
    {
        case MMS_SIG_DELIVERY_REPORT:
        case MMS_SIG_READ_REPORT_IND:
        case MMS_SIG_NOTIFICATION:
        {
			mma_msgmgr_handle_rsp(sig, sig_data);
            break;
        }
        case MMS_SIG_CREATE_MSG_REPLY:
        case MMS_SIG_MSG_DONE_REPLY:
        {
            if (mma_create_handle_rsp(sig, sig_data) == TRUE)
            {
                mms_mma_queue_struct *task = mma_create_get_active_task();

                mma_create_fsm_hdlr(task->first_id);
            }
            break;
        }

        case MMS_SIG_SEND_MSG_REPLY:    /* No msgid info */
        {

            char *statusString;
            MmsResultSig *sendReply = (MmsResultSig*) sig_data;

            if (sendReply->responseText != NULL)
            {
                statusString =  msf_cmmn_strndup(
                                MSF_MODID_MMA,
                                sendReply->responseText,
                                (int)strlen(sendReply->responseText) + 1);
            }
            else
            {
                statusString = NULL;
            }

            (void)MMA_SIGNAL_SENDTO_IUUP(
                    MMA_SUBMODULE_MSG_SENDRECV,
                    MMA_INT_SIG_TYPE_MSG_SEND_MSG_RSP,
                    sendReply->responseStatus,
                    0,  /* invalid msg id */
                    sendReply->result,
                    statusString);

            break;
        }
        case MMS_SIG_SEND_RR_REPLY:
        {
            char *statusString = NULL;
            MmsRRReplySig *RRReply = (MmsRRReplySig*) sig_data;

            if (RRReply->responseText != NULL)
            {
                statusString = msf_cmmn_strndup(
                                MSF_MODID_MMA,
                                RRReply->responseText,
                                (int)strlen(RRReply->responseText) + 1);
            }
            else
            {
                statusString = NULL;
            }

            MMA_SIGNAL_SENDTO_IUUP(
                MMA_SUBMODULE_MSG_SENDRECV,
                MMA_INT_SIG_TYPE_MSG_SEND_RR_RSP,
                0,  /* status text */
                RRReply->msgId,
                RRReply->result,
                statusString);
            break;
        }
        case MMS_SIG_RETRIEVE_MSG_REPLY:    /* No msgid info */
        {
            char *statusString;
            MmsRetrieveMsgReply *retrieveReply = (MmsRetrieveMsgReply*) sig_data;

            if (retrieveReply->retrieveText != NULL)
            {
                statusString = msf_cmmn_strndup(
                                MSF_MODID_MMA,
                                retrieveReply->retrieveText,
                                (int)(strlen(retrieveReply->retrieveText) + 1));
            }
            else
            {
                statusString = NULL;
            }
            MMA_SIGNAL_SENDTO_IUP(
                MMA_SUBMODULE_MSG_SENDRECV,
                MMA_INT_SIG_TYPE_MSG_RECV_MSG_RSP,
                retrieveReply->msgId,
                retrieveReply->result,
                statusString);
            break;
        }
        case MMS_SIG_DELETE_MSG_REPLY:
        {
            mms_mma_queue_struct *req = NULL;
            MmsMsgDoneReplySig *delete_rsp = (MmsMsgDoneReplySig*) sig_data;
            kal_uint32 mma_msg_id = 0;
            kal_bool is_handled = KAL_TRUE;

			mma_msg_id = mma_main_encode_msg_id((kal_uint8)translate_mms_storage_to_mma_storage_enum((msf_mms_storage_enum)delete_rsp->storageType), 
                             delete_rsp->msgId);

            if (g_mma_wrapper_queue)  // Sandeep: In case an Immediate notification is deleted, g_mma_wrapper_queue will be NULL
            {
                if (g_mma_wrapper_queue->first_id == MMA_SUBMODULE_MSG_MGR)
                {
                    if (mma_msgmgr_handle_rsp(MMS_SIG_DELETE_MSG_REPLY, sig_data) == TRUE)
                    {
                        /* Need to do nothing */
                    }
                    else
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_ENV_SIG_DELETE_MSG_REPLY_NOT_COLLECTED_BY_MSGMGR,
                                          "MMS_SIG_DELETE_MSG_REPLY msg %d not collected by Msg_mgr module\n",
                                          mma_msg_id));
                        is_handled = KAL_FALSE;
                    }
                }
                else if (g_mma_wrapper_queue->first_id == MMA_SUBMODULE_MSG_SENDRECV)
                {
                    if (mma_sendrecv_handle_rsp(MMS_SIG_DELETE_MSG_REPLY, sig_data) == TRUE)
                    {
                        /* Need to do nothing */
                    }
                    else
                    {
                        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_ENV_SIG_DELETE_MSG_REPLY_NOT_COLLECTED_BY_SENDRECV,
                                          "MMS_SIG_DELETE_MSG_REPLY msg %d not collected by SEND_RECV module\n",
                                          g_mma_wrapper_queue->second_id));
                    }
                }

                /* Skip for Create and SendRcv uses these. */

                /* Proceed to next */
                if(is_handled)
                {
                    if ((req = mma_remove_node_from_queue(
                                &g_mma_wrapper_queue,
                                g_mma_wrapper_queue->first_id,
                                mma_msg_id/*g_mma_wrapper_queue->second_id*/)) != NULL)
                    {
                        MMA_FREE(req);
                    }
                    if (g_mma_wrapper_queue)
                    {
				        mma_handle_wrapper_queue_next_call_based_on_action_type();
                    }
                }
            }
            break;
        }
        case MMS_SIG_MOV_MSG_REPLY:
        {
            MmsMsgReplySig *response = (MmsMsgReplySig*) sig_data;

            if (response->result != MMS_RESULT_OK)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                  MMA_ENV_SIG_MOV_MSG_REPLY_FAIL, "Fail to mov msg,%d\n", response->result));
            }
            MMA_SIGNAL_SENDTO_IU(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_MMS_MOVE_IND, response->result, response->msgId);
            break;
        }
        case MMS_SIG_PROGRESS_STATUS_REPLY:
        {
			if (sig_data != NULL)
			{
				MMAif_sendProgressInd(sig_data);
			}
            break;
		}
        case MMS_SIG_GET_FLDR_REPLY:
        {
            if (sig_data != NULL)
            {
                mma_msgmgr_handle_rsp(MMS_SIG_GET_FLDR_REPLY, (void*)sig_data);
                MMA_FREE(((MmsListOfProperties*)sig_data)->msgPropertyList)
            }
            break;
        }
        case MMS_SIG_PUSH_NOTIFICATION_REPLY:
        {
            PushNotificationReplySig *pushNotificationReply = (PushNotificationReplySig*) sig_data;

            MMA_SIGNAL_SENDTO_I(
                MMA_SUBMODULE_MSG_SENDRECV,
                MMA_INT_SIG_TYPE_MSG_MMS_OBJ_RES,
                pushNotificationReply->result);
            break;
        }
    }
    MMA_FREE(sig_data);
        }





/*****************************************************************************
 * FUNCTION
 *  mmaReceiveExtSignal
 * DESCRIPTION
 *  This function is used to handles the incoming external signals
 * PARAMETERS
 *  module          [IN]        
 *  sig             [IN]        
 *  sig_data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmaReceiveExtSignal(MSF_UINT8 module, MSF_UINT16 sig, void *sig_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The following signals are handled */
    switch (module)
    {
        case MSF_MODID_MSM:
            mmaMsfHandleExtSignal(sig, sig_data);
            break;
        case MSF_MODID_MMS:
            mmaMMSHandleExtSignal(sig, sig_data);
            break;
/*
        case MSF_MODID_SLS:
            mmaSlsSignalHandler(sig, sig_data);
            break;*/
        default:
            MMA_FREE(sig_data);
            break;
    }
}   /* mmaReceiveExtSignal */


/*****************************************************************************
 * FUNCTION
 *  mma_int_signal_process
 * DESCRIPTION
 *  This function is used to handles the incoming external signals
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_int_signal_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_signal_struct *int_sig_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_sig_p = g_mms_mma_int_sig_queue_list_p;
    if (int_sig_p != NULL)
    {
       
       
        if (mma_env_context.mma_submodule_info_p[int_sig_p->dst] != NULL)
        {
            mma_env_context.mma_submodule_info_p[int_sig_p->dst]->int_sig_process_func(int_sig_p);
        }

        if (mma_env_context.mma_submodule_info_p[0] == NULL)
        {
            /* It means MMA is already terminated */
            return;
        }
		g_mms_mma_int_sig_queue_list_p = g_mms_mma_int_sig_queue_list_p->next;
        MMA_FREE(int_sig_p);
    }
}   /* mmaReceiveExtSignal */


/*****************************************************************************
 * FUNCTION
 *  MMAc_kill
 * DESCRIPTION
 *  This function is used to kill MMA task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMAc_kill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_env_context.is_mma_activated = KAL_FALSE;
    for (i = 0; i < MMA_SUBMODULE_TOTAL; i++)
    {
        if (mma_env_context.mma_submodule_info_p[i] != NULL)
        {
            if (mma_env_context.mma_submodule_info_p[i]->terminate_func() == FALSE)
            {
			
            }
            mma_env_context.mma_submodule_info_p[i] = NULL;
        }
    }
    g_mma_wrapper_queue = NULL;
    g_mms_mma_int_sig_queue_list_p = NULL;
    g_mms_mma_accept_header = NULL;
    memset(g_mms_owner_number, 0x00, MMA_MAX_ADDR_LEN);

    mma_mime_clean_context();
    MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_MMA);
    MSF_FILE_CLOSE_ALL(MSF_MODID_MMA);  /* Only if the module use files. */
    MSF_MEM_FREE_ALL(MSF_MODID_MMA);
    MSF_MODULE_IS_TERMINATED(MSF_MODID_MMA);
    MSF_KILL_TASK(MSF_MODID_MMA);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA,
                       MMA_ENV_KILL_MMAC_TERMINATED, "MMA terminated By MMAc_kill."));
}


/*****************************************************************************
 * FUNCTION
 *  MMAc_run
 * DESCRIPTION
 *  Perform an execution 'tick' for the MMA task.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMAc_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_env_context.mma_inside_run = KAL_TRUE;
    if (setjmp(mma_jmpbuf) == 0)
    {
        if (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_MMA) > 0)
        {
            /*
             * Well, We collect all external signals to avoid buffer explosion.
             * * This on the other hand may cause an ever groving internal queue.
             * * But, with no directives available, this is the way we do it.
             */
            while (MSF_SIGNAL_RETRIEVE(MSF_MODID_MMA, mmaReceiveExtSignal))
            {
                /* Empty while, all is done in the condition */
            };
        }   /* if */

        if (mma_env_context.is_mma_activated == KAL_FALSE)
        {
            mma_env_context.is_mma_activated = KAL_TRUE;
            for (i = 0; i < MMA_SUBMODULE_TOTAL; i++)
            {
                if (mma_env_context.mma_submodule_info_p[i] != NULL)
                {
                    if (mma_env_context.mma_submodule_info_p[i]->state == MMA_SUBMODULE_STATE_INITING)
                    {
                        if (mma_env_context.mma_submodule_info_p[i]->init_func() == TRUE)
                        {
                            mma_env_context.mma_submodule_info_p[i]->state = MMA_SUBMODULE_STATE_READY;
                        }
                    }
                    if (mma_env_context.mma_submodule_info_p[i]->state != MMA_SUBMODULE_STATE_READY)
                    {
                        mma_env_context.is_mma_activated = KAL_FALSE;
                    }
                }
            }
            if (mma_env_context.is_mma_activated == KAL_TRUE)
            {
                MSF_MODULE_IS_ACTIVE(MSF_MODID_MMA);
                MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MAIN, MMA_INT_SIG_TYPE_MSG_SEND_READY_IND_REQ);
            }
        }
        mma_int_signal_process();   /* Process one signal and return. */
		if (mma_env_context.is_terminate_pending == TRUE && g_mms_mma_int_sig_queue_list_p == NULL) // sandeep 
		{
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
			MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_DRMSRV, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
#else
		    MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
			mma_env_context.is_terminate_pending = KAL_FALSE;
		}
        if (mma_env_context.mma_submodule_info_p[0] == NULL)
        {
            /* It means MMA is already terminated */
            return;
        }
/*
        if (mma_env_context.is_mma_activated == FALSE && g_mms_mma_int_sig_queue_list_p == NULL)
        {
            MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_NOTIFY);
        }
*/
    }
    else
    {
        ASSERT(0);
    }   /* if */

    mma_env_context.mma_inside_run = KAL_FALSE;
}

void mma_handle_mem_exhaust_callback(void)
{
    mms_mma_send_insufficient_memory_ind();

}
/*
 * Prepares the MMA client for running.
 *
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  MMAc_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MMAc_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_env_context.mma_inside_run = KAL_FALSE;

    g_mma_wrapper_queue = NULL;
    g_mms_mma_int_sig_queue_list_p = NULL;

    memset(mma_jmpbuf, 0, sizeof(mtk_jmpbuf));
    mma_mime_clean_context();

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_MMA,
                       MMA_ENV_START_MMAC_START, "MMA_start(void)\n"));

    /* Initialize the memory allocator. Needed in most other functions. */
    MSF_MEM_INIT(MSF_MODID_MMA, mma_exception_handler);

    /* Register the signal queue */
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_MMA);

    if (mma_ctrl_mutex == NULL)
    {
        mma_ctrl_mutex = kal_create_mutex("mma_mutex");
    }

    /* Configure sub-module's handle functions */
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_MAIN] =
        (mma_submodule_info_struct*) MMA_CALLOC(sizeof(mma_submodule_info_struct));
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_MAIN]->init_func = mma_main_init;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_MAIN]->terminate_func = mma_main_terminate;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_MAIN]->int_sig_process_func = mma_main_process_int_sig;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_MGR] =
        (mma_submodule_info_struct*) MMA_CALLOC(sizeof(mma_submodule_info_struct));
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_MGR]->init_func = mma_msgmgr_init;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_MGR]->terminate_func = mma_msgmgr_terminate;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_MGR]->int_sig_process_func = mma_msgmgr_process_int_sig;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_SENDRECV] =
        (mma_submodule_info_struct*) MMA_CALLOC(sizeof(mma_submodule_info_struct));
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_SENDRECV]->init_func = mma_sendrecv_init;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_SENDRECV]->terminate_func = mma_sendrecv_terminate;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_SENDRECV]->int_sig_process_func =
        mma_sendrecv_process_int_sig;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_SETTING] =
        (mma_submodule_info_struct*) MMA_CALLOC(sizeof(mma_submodule_info_struct));
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_SETTING]->init_func = mma_setting_init;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_SETTING]->terminate_func = mma_setting_terminate;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_SETTING]->int_sig_process_func =
        mma_setting_process_int_sig;    

    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_PARSE] =
        (mma_submodule_info_struct*) MMA_CALLOC(sizeof(mma_submodule_info_struct));
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_PARSE]->init_func = mma_parse_init;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_PARSE]->terminate_func = mma_parse_terminate;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_PARSE]->int_sig_process_func = mma_parse_process_int_sig;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_CREATE] =
        (mma_submodule_info_struct*) MMA_CALLOC(sizeof(mma_submodule_info_struct));
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_CREATE]->init_func = mma_create_init;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_CREATE]->terminate_func = mma_create_terminate;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_CREATE]->int_sig_process_func = mma_create_process_int_sig;
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_DRMSRV] = MMA_CALLOC(sizeof(mma_submodule_info_struct));
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_DRMSRV]->init_func = mma_drmsrv_init;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_DRMSRV]->terminate_func = mma_drmsrv_terminate;
    mma_env_context.mma_submodule_info_p[MMA_SUBMODULE_MSG_DRMSRV]->int_sig_process_func = mma_drmsrv_process_int_sig;
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
    for (i = 0; i < MMA_SUBMODULE_TOTAL; i++)
    {
        if (mma_env_context.mma_submodule_info_p[i] != NULL)
        {
            if (mma_env_context.mma_submodule_info_p[i]->init_func() != TRUE)
            {
                mma_env_context.mma_submodule_info_p[i]->state = MMA_SUBMODULE_STATE_INITING;
            }
            else
            {
                mma_env_context.mma_submodule_info_p[i]->state = MMA_SUBMODULE_STATE_READY;
            }
        }
    }

    /* Registrate the module into MSF */
    MSF_MODULE_IS_CREATED(MSF_MODID_MMA, (char*)MMA_VERSION);
    MSF_MODULE_START(MSF_MODID_MMA, MSF_MODID_MMS, NULL, NULL, NULL);

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
    MSF_REGISTER_ERROR_DISPLAY_FUNCTION(mma_handle_mem_exhaust_callback);
#endif
}   /* MMSc_start */


/*****************************************************************************
 * FUNCTION
 *  MMAc_wantsToRun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int MMAc_wantsToRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_MMA) > 0 || g_mms_mma_int_sig_queue_list_p != NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_ready
 * DESCRIPTION
 *  This function is used to check if MMA module is activated.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
kal_bool mma_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mma_env_context.is_mma_activated;
}

#ifdef __MMI_MMS_USE_ASM__
/*****************************************************************************
 * FUNCTION
 *  asmMsfHandleExtSignal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig             [IN]        
 *  sig_data        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void asmMsfHandleExtSignal(MSF_UINT16 sig, void *sig_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sig)
    {
        case MSF_SIG_MODULE_TERMINATE:
        {
            ASMc_kill();
			break;
        }

        case MSF_SIG_MODULE_STATUS: /* handle SLS status */
        {
            break;
        }

        case MSF_SIG_FILE_NOTIFY:
        {
            msf_file_notify_t *notify = sig_data;

			if (mma_parse_handle_rsp(MSF_SIG_FILE_NOTIFY, notify) == TRUE)
            {
                mms_mma_queue_struct *task = mma_parse_get_active_task();

                mma_parse_fsm_hdlr(task->first_id);
            }
            break;
        }

        default:
            break;
    }
    MSF_MEM_FREE( MSF_MODID_ASM, sig_data);
}
/*****************************************************************************
 * FUNCTION
 *  asmReceiveExtSignal
 * DESCRIPTION
 *  This function is used to handles the incoming external signals
 * PARAMETERS
 *  module          [IN]        
 *  sig             [IN]        
 *  sig_data        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void asmReceiveExtSignal(MSF_UINT8 module, MSF_UINT16 sig, void *sig_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The following signals are handled */
    switch (module)
    {
        case MSF_MODID_MSM:
            asmMsfHandleExtSignal(sig, sig_data);
            break;
        case MSF_MODID_MMS:
            ASSERT (0);
            break;
/*
        case MSF_MODID_SLS:
            ASSERT (0);
            break;*/
        default:
            MMA_FREE(sig_data);
            break;
	}
}   /* mmaReceiveExtSignal */

/*****************************************************************************
 * FUNCTION
 *  MMAc_kill
 * DESCRIPTION
 *  This function is used to kill MMA task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ASMc_kill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_ASM);
    MSF_FILE_CLOSE_ALL(MSF_MODID_ASM);  /* Only if the module use files. */
    MSF_MEM_FREE_ALL(MSF_MODID_ASM);
    MSF_MODULE_IS_TERMINATED(MSF_MODID_ASM);
    MSF_KILL_TASK(MSF_MODID_ASM);
}


/*****************************************************************************
 * FUNCTION
 *  MMAc_run
 * DESCRIPTION
 *  Perform an execution 'tick' for the MMA task.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ASMc_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_ASM) > 0)
    {
        /*
         * Well, We collect all external signals to avoid buffer explosion.
         * * This on the other hand may cause an ever groving internal queue.
         * * But, with no directives available, this is the way we do it.
         */
        while (MSF_SIGNAL_RETRIEVE(MSF_MODID_ASM, asmReceiveExtSignal))
        {
            /* Empty while, all is done in the condition */
        };
    }   /* if */
}

static void asm_exception_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(0);
}       /* mma_exception_handler */


/*****************************************************************************
 * FUNCTION
 *  MMAc_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ASMc_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Initialize the memory allocator. Needed in most other functions. */
    MSF_MEM_INIT(MSF_MODID_ASM, asm_exception_handler);

    /* Register the signal queue */
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_ASM);

    /* Register conversion and destruction functions */
//    MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_MMA, asmConvert, asmDestruct);

    /* Registrate the module into MSF */
    MSF_MODULE_IS_CREATED(MSF_MODID_ASM, (char*)MMA_VERSION);
	MSF_MODULE_IS_ACTIVE((MSF_UINT8)MSF_MODID_ASM);
}   /* MMSc_start */


/*****************************************************************************
 * FUNCTION
 *  MMAc_wantsToRun
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int ASMc_wantsToRun(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_SIGNAL_QUEUE_LENGTH(MSF_MODID_ASM) > 0);
}
#endif /* __MMI_MMS_USE_ASM__ */


#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_ENV_C */ 

