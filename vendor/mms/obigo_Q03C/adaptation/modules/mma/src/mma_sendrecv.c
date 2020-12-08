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
 * mma_sendrecv.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_SENDRECV_C
#define _MMA_SENDRECV_C

#if defined(MMS_SUPPORT)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "wapadp.h"
#include "mmsadp.h"
#include "mma_api.h"
#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"

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
#ifdef __USB_IN_NORMAL_MODE__
#include "USBSrvGProt.h"
#endif

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

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "stk_if.h"     /* STK: WSP/HTTP Stack signals and types */
#else
#include "nts_if.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

#include "mms_cfg.h"    /* MMS: Configuration definitions */

#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_if.h"     /* MMS: Exported signal interface */

#include "mcpdu.h"      /* for MmsResponseStatus */
#include "mconfig.h"
#include "msig.h"
#include "mmem.h"

#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"

/* MMA */
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_env.h"
#include "mma_mime.h"
#include "mma_main.h"
#include "mma_setting.h"
#include "mma_sendrecv.h"
#include "mma_msgmgr.h"
#include "mma_utilities.h"
#include "mma_interface.h"
#include "mma_msg_struct.h"
#include "mma_parse.h"

#include "cbm_api.h"
#include "cbm_consts.h"

#include "custom_wap_config.h"

static mma_sendrecv_context_struct g_mma_sendrecv_cntx = {0};
static void mma_sendrecv_termiante_all_requests(void);
static void mma_sendrecv_set_flag(mma_sendrecv_flag_enum type);
static void mma_sendrecv_unset_flag(mma_sendrecv_flag_enum type);
static kal_bool mma_sendrecv_check_flag(mma_sendrecv_flag_enum type);


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_set_flag
 * DESCRIPTION
 *  Function to Set MMS flag
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_set_flag(mma_sendrecv_flag_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_sendrecv_cntx.flag |= type;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_unset_flag
 * DESCRIPTION
 *  Function to unset MMS flag
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_unset_flag(mma_sendrecv_flag_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_sendrecv_cntx.flag &= (~type);
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_check_flag
 * DESCRIPTION
 *  Function to check MMS flag
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool mma_sendrecv_check_flag(mma_sendrecv_flag_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_mma_sendrecv_cntx.flag & type) ? KAL_TRUE : KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_get_sending_msgid
 * DESCRIPTION
 *  Function to return sending msg id
 * PARAMETERS
 *  void
 * RETURNS
 *  msg_id
 *****************************************************************************/
kal_uint32 mma_sendrecv_get_sending_msgid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_sendrecv_cntx.send_req_list == NULL)
    {
        return 0;
    }

    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_SENDING))
    {
        return g_mma_sendrecv_cntx.send_req_list->msg_id;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_is_sending
 * DESCRIPTION
 *  Function to tell is sending in progress
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_sendrecv_is_sending(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_sendrecv_cntx.send_req_list == NULL)
    {
        return KAL_FALSE;
    }
    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_SENDING))
    {
        if (g_mma_sendrecv_cntx.send_req_list->msg_id == msg_id)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_is_downloading
 * DESCRIPTION
 *  check for msg is in downloading
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_sendrecv_is_downloading(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_sendrecv_cntx.recv_req_list == NULL)
    {
        return KAL_FALSE;
    }
    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING))
    {
        if (g_mma_sendrecv_cntx.recv_req_list->msg_id == msg_id)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_add_req_to_queue
 * DESCRIPTION
 *  Function to add sendrecv req into queue
 * PARAMETERS
 *  queue       [IN]        
 *  node        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MSF_BOOL mma_sendrecv_add_req_to_queue(
                    mma_sendrecv_req_info_list_struct **queue,
                    mma_sendrecv_req_info_list_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (queue == NULL || node == NULL)
    {
        return FALSE;
    }
    ASSERT(node->next == NULL);
    if (*queue == NULL)
    {
        *queue = node;
    }
    else
    {
        list_p = *queue;
        while (list_p->next != NULL)
        {
            list_p = list_p->next;
        }
        list_p->next = node;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_get_req_from_queue
 * DESCRIPTION
 *  Function to return sendrecv req from queue
 * PARAMETERS
 *  queue       [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_sendrecv_req_info_list_struct *mma_sendrecv_get_req_from_queue(
                                    mma_sendrecv_req_info_list_struct *queue,
                                    MSF_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *list_p = queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_p == NULL)
    {
        return NULL;
    }
    while (list_p)
    {
        if (list_p->msg_id == msg_id)
        {
            return list_p;
        }
        list_p = list_p->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_remove_pending_send_nodes
 * DESCRIPTION
 *  Function to delete sendrecv req from queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_sendrecv_remove_pending_send_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *send_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_sendrecv_cntx.send_req_list == NULL)
    {
        return;
    }
    send_req_info_p = g_mma_sendrecv_cntx.send_req_list;
    while (send_req_info_p->next)
    {
        /* Remove the node and change status to NORMAL */
        mma_sendrecv_req_info_list_struct *tmp_p = NULL;

        mms_mma_send_send_rsp(
            send_req_info_p->next->source,
            send_req_info_p->next->app_id,
            send_req_info_p->next->req_id,
            send_req_info_p->next->msg_id,
            MMA_RESULT_FAIL_USER_CANCEL,
            NULL);
        /* Remove the node from g_mma_sendrecv_cntx.send_req_list */
        tmp_p = send_req_info_p->next;
        send_req_info_p->next = send_req_info_p->next->next;
        MMA_FREE(tmp_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_remove_pending_download_nodes
 * DESCRIPTION
 *  Function to remove All pending download nodes execpt current download node
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_sendrecv_remove_pending_download_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_sendrecv_cntx.recv_req_list == NULL)
    {
        return;
    }
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_REMOVE_PENDING_DOWNLOAD_NODES,
                       "MMA SENDRECV Remove pending download nodes"));
    download_req_info_p = g_mma_sendrecv_cntx.recv_req_list;
    while (download_req_info_p->next)
    {
        /* Remove the node and change status to NORMAL */
        mma_sendrecv_req_info_list_struct *tmp_p = NULL;

        mms_mma_send_download_rsp(
            download_req_info_p->next->source,
            download_req_info_p->next->app_id,
            download_req_info_p->next->req_id,
            download_req_info_p->next->msg_id,
            0,
            MMA_RESULT_FAIL_USER_CANCEL,
            NULL);
        /* Remove the node from g_mma_sendrecv_cntx.send_req_list */
        tmp_p = download_req_info_p->next;
        download_req_info_p->next = download_req_info_p->next->next;
        MMA_FREE(tmp_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_remove_single_pending_send_node
 * DESCRIPTION
 *  Function to remove one pending send node execpt current send node
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_sendrecv_remove_single_pending_send_node(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *send_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_sendrecv_cntx.send_req_list == NULL)
    {
        return KAL_FALSE;
    }
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_REMOVE_SINGLE_PENDING_SEND_NODE,
                       "MMA SENDRECV Remove single pending send node"));
    send_req_info_p = g_mma_sendrecv_cntx.send_req_list;
    while (send_req_info_p->next)
    {
        if (send_req_info_p->next->msg_id == msg_id)
        {
            mma_sendrecv_req_info_list_struct *tmp_p = NULL;

            mms_mma_send_send_rsp(
                send_req_info_p->next->source,
                send_req_info_p->next->app_id,
                send_req_info_p->next->req_id,
                send_req_info_p->next->msg_id,
                MMA_RESULT_FAIL_USER_CANCEL,
                NULL);
            /* Remove the node from g_mma_sendrecv_cntx.send_req_list */
            tmp_p = send_req_info_p->next;
            MMA_FREE(tmp_p);
            return KAL_TRUE;
        }
        send_req_info_p->next = send_req_info_p->next->next;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_remove_single_pending_download_node
 * DESCRIPTION
 *  Function to remove one pending download node execpt current download node
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_sendrecv_remove_single_pending_download_node(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_sendrecv_cntx.recv_req_list == NULL)
    {
        return KAL_FALSE;
    }
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_REMOVE_SINGLE_PENDING_DOWNLOAD_NODE,
                       "MMA SENDRECV Remove single pending download node"));
    download_req_info_p = g_mma_sendrecv_cntx.recv_req_list;
    while (download_req_info_p->next)
    {
        /* Remove the node and change status to NORMAL */
        mma_sendrecv_req_info_list_struct *tmp_p = NULL;

        if (download_req_info_p->next->msg_id == msg_id)
        {
            mms_mma_send_download_rsp(
                download_req_info_p->next->source,
                download_req_info_p->next->app_id,
                download_req_info_p->next->req_id,
                download_req_info_p->next->msg_id,
                0,
                MMA_RESULT_FAIL_USER_CANCEL,
                NULL);
            /* Remove the node from g_mma_sendrecv_cntx.send_req_list */
            tmp_p = download_req_info_p->next;
            MMA_FREE(tmp_p);
            return KAL_TRUE;
        }
        download_req_info_p->next = download_req_info_p->next->next;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_process_one_send_req
 * DESCRIPTION
 *  Function to process one send request from queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_process_one_send_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *send_req_info_p = NULL;
    kal_uint16 storage_data = 0;
    kal_uint8 temp_storage = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_sendrecv_cntx.send_req_list == NULL)
    {
        return;
    }
    else
    {
        /* Pick up first node */
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_PROCESS_ONE_SEND_REQ,
                           "MMA SENDRECV process one send req"));
        send_req_info_p = g_mma_sendrecv_cntx.send_req_list;
        if (mma_msgmgr_msg_info_exist(send_req_info_p->msg_id) == FALSE)
        {
            mms_mma_send_send_rsp(
                send_req_info_p->source,
                send_req_info_p->app_id,
                send_req_info_p->req_id,
                send_req_info_p->msg_id,
                MMA_RESULT_FAIL_INVALID_MSGID,
                NULL);
        }
        else if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_SENDING) == FALSE)
        {
            mma_result_enum error_code = MMA_RESULT_OK;

        #ifdef __USB_IN_NORMAL_MODE__
            if ((srv_usb_is_in_mass_storage_mode() || mma_main_is_in_usb_mode()) && mma_is_storage_exported_to_pc())    /* Check if MMS should be disabled */
            {
                error_code = MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;
            }
        #endif /* __USB_IN_NORMAL_MODE__ */ 
            if (error_code == MMA_RESULT_OK && mma_main_is_in_terminate())
            {
                error_code = MMA_RESULT_FAIL_TERMINATING;
            }
            if (error_code != MMA_RESULT_OK)
            {
                mms_mma_send_send_rsp(
                    send_req_info_p->source,
                    send_req_info_p->app_id,
                    send_req_info_p->req_id,
                    send_req_info_p->msg_id,
                    (kal_uint8) error_code,
                    NULL);
            }
            else
            {
                temp_storage = mma_setting_get_preffered_storage();
                storage_data = mma_get_message_storage(send_req_info_p->msg_id);
                if (mma_msgmgr_is_busy())
                {
                    /* We should not trigger send request now. Because the message may be deleted. */
                    MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_PROCESS_SEND_Q_IND);
                }
                else if((send_req_info_p->is_read_report && !mma_main_is_storage_type_present((mma_msg_storage_type_enum)temp_storage))|| !mma_main_is_storage_type_present((mma_msg_storage_type_enum)storage_data))
                {
                    mms_mma_send_send_rsp(
                        send_req_info_p->source,
                        send_req_info_p->app_id,
                        send_req_info_p->req_id,
                        send_req_info_p->msg_id,
                        MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT,
                        NULL);
                }
                else
                {
                    storage_data = translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)storage_data);
                    if (send_req_info_p->is_read_report == TRUE)
                    {
                        send_req_info_p->storage_type = temp_storage;
                        storage_data = (storage_data<<8) | translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)temp_storage);
                        MMSif_sendReadReport(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(send_req_info_p->msg_id), MMS_READ_STATUS_READ, (MmsSimCardEnum)translate_mma_sim_to_mms_sim(send_req_info_p->sim_id), storage_data);
                    }
                    else
                    {
                        MMSif_sendMessage(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(send_req_info_p->msg_id), (MmsSimCardEnum)translate_mma_sim_to_mms_sim(send_req_info_p->sim_id), (kal_uint8)storage_data);
                    }
                    mma_sendrecv_set_flag(MMA_SENDRECV_IS_SENDING);
                }
                return;
            }
        }
        else
        {
            return;
        }

    }

    g_mma_sendrecv_cntx.send_req_list = g_mma_sendrecv_cntx.send_req_list->next;
    MMA_FREE(send_req_info_p);
    if (g_mma_sendrecv_cntx.send_req_list != NULL)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_PROCESS_SEND_Q_IND);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_send_req_hdlr
 * DESCRIPTION
 *  Function to process send request
 * PARAMETERS
 *  source          [IN]        
 *  send_req_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_send_req_hdlr(module_type source, wap_mma_send_req_struct *send_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *send_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(send_req_p);

    /* Step 1: Check if the MMA send recv is ready */
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_SEND_REQ_HDLR, "MMA SENDRECV send req hdlr"));
    if (g_mma_sendrecv_cntx.state != MMA_SENDRECV_STATE_STARTED)
    {
        mma_result_enum result = MMA_RESULT_FAIL_NOT_READY;

        if (g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPING)
        {
            result = MMA_RESULT_FAIL_TERMINATING;
        }

        mms_mma_send_send_rsp(
            source,
            send_req_p->app_id,
            send_req_p->req_id,
            send_req_p->msg_id,
            (kal_uint8) result,
            NULL);
    }
    else if(mma_setting_is_supended(translate_mma_sim_to_mms_sim(send_req_p->sim_id)))
    {
        mms_mma_send_send_rsp(
            source,
            send_req_p->app_id,
            send_req_p->req_id,
            send_req_p->msg_id,
            MMA_RESULT_FAIL_SUSPENDED_MODE,
            NULL);

    }
    /* Step 2: Check if the MMS message is sending queue */
    else if (mma_sendrecv_get_req_from_queue(g_mma_sendrecv_cntx.send_req_list, send_req_p->msg_id) != NULL)
    {
        mms_mma_send_send_rsp(
            source,
            send_req_p->app_id,
            send_req_p->req_id,
            send_req_p->msg_id,
            MMA_RESULT_FAIL_MSGID_IS_USING,
            NULL);
    }
    /* Step 3: Check if the info of MMS message is exist */
    else if (mma_msgmgr_msg_info_exist(send_req_p->msg_id) == FALSE)
    {
        /* We can not find the msgid */
        mms_mma_send_send_rsp(
            source,
            send_req_p->app_id,
            send_req_p->req_id,
            send_req_p->msg_id,
            MMA_RESULT_FAIL_INVALID_MSGID,
            NULL);
    }
    else
    {
        send_req_info_p = (mma_sendrecv_req_info_list_struct*) MMA_CALLOC(sizeof(mma_sendrecv_req_info_list_struct));
        if (send_req_info_p == NULL)
        {
            mms_mma_send_send_rsp(
                source,
                send_req_p->app_id,
                send_req_p->req_id,
                send_req_p->msg_id,
                MMA_RESULT_FAIL_INSUFFICIENT_MEMORY,
                NULL);
        }
        else
        {
            /* Insert one node to waiting queue */
            send_req_info_p->source = source;
            send_req_info_p->app_id = send_req_p->app_id;
            send_req_info_p->req_id = send_req_p->req_id;
            send_req_info_p->msg_id = send_req_p->msg_id;
            send_req_info_p->sim_id = send_req_p->sim_id;
            send_req_info_p->is_read_report = send_req_p->is_read_report;
            mma_sendrecv_add_req_to_queue(&g_mma_sendrecv_cntx.send_req_list, send_req_info_p);
            mma_sendrecv_process_one_send_req();
        }
    }

    MMA_FREE(send_req_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_send_rsp_hdlr
 * DESCRIPTION
 *  Function to process one send response
 * PARAMETERS
 *  msgId               [IN]        When msgid is 0, it means SEND_RR_RSP is received
 *  rrId                [IN]        
 *  send_result         [IN]        
 *  response_status     [IN]        
 *  response_txt        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_send_rsp_hdlr(
                kal_uint32 msgId,
                MmsResult send_result,
                MmsResponseStatus response_status,
                char *response_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *send_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPING || g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPED)
    {
		if (response_txt != NULL)
		{
			MMA_FREE(response_txt);
		}
		return;
    }
    send_req_info_p = g_mma_sendrecv_cntx.send_req_list;

    ASSERT(send_req_info_p);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_SEND_RSP_HDLR,
                      "Recv send rsp for msg %d. send result:%d, rsp_status:%d\n", msgId, send_result,
                      response_status));

    /* We need do special handlings to send read report */
    if (msgId != 0 && msgId != MMA_TRANSLATE_MSG_ID(send_req_info_p->msg_id))
    {
        ASSERT(0);
    }
    mma_sendrecv_unset_flag(MMA_SENDRECV_IS_SENDING);
    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_SENDING_CANCELLED) == TRUE)
    {
        mma_sendrecv_unset_flag(MMA_SENDRECV_IS_SENDING_CANCELLED);
        if (send_result == MMS_RESULT_OK)
        {
            mms_mma_send_cancel_send_rsp(
                send_req_info_p->source,
                send_req_info_p->app_id,
                send_req_info_p->req_id,
                send_req_info_p->msg_id,
                MMA_RESULT_FAIL_MSGID_IS_USING);

            mms_mma_send_send_rsp(
                send_req_info_p->source,
                send_req_info_p->app_id,
                send_req_info_p->req_id,
                send_req_info_p->msg_id,
                MMA_RESULT_OK,
                response_txt);
        }
        else
        {
            mms_mma_send_cancel_send_rsp(
                send_req_info_p->source,
                send_req_info_p->app_id,
                send_req_info_p->req_id,
                send_req_info_p->msg_id,
                MMA_RESULT_OK);

            mms_mma_send_send_rsp(
                send_req_info_p->source,
                send_req_info_p->app_id,
                send_req_info_p->req_id,
                send_req_info_p->msg_id,
                (kal_uint8) MMA_RESULT_FAIL_USER_CANCEL,
                NULL);
        }
       
    }
    else
    {
        mms_mma_send_send_rsp(
            send_req_info_p->source,
            send_req_info_p->app_id,
            send_req_info_p->req_id,
            send_req_info_p->msg_id,
            (kal_uint8) ((send_result != MMS_RESULT_OK && send_req_info_p->result == MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE) ? MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE : translate_mms_result_to_mma(send_result)),
            response_txt);
    }

    if (send_req_info_p->result == MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE)
    {
        send_req_info_p->result = MMA_RESULT_OK;
        /* There is no send request waiting for cancel send resposne. We can send enter usb mode to MOD_MMI */
        if (g_mma_sendrecv_cntx.recv_req_list == NULL ||
            g_mma_sendrecv_cntx.recv_req_list->result != MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE)
        {
            /* We need to wait MMA msgmgr module complete everything */
            MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
        }
    }

    g_mma_sendrecv_cntx.send_req_list = g_mma_sendrecv_cntx.send_req_list->next;
    
    mma_sendrecv_process_one_send_req();
    if (response_txt != NULL)
    {
        MMA_FREE(response_txt);
    }
    MMA_FREE(send_req_info_p);

}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_cancel_send_req_hdlr
 * DESCRIPTION
 *  Function to process cancel send request
 * PARAMETERS
 *  source                  [IN]        
 *  cancel_send_req_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_cancel_send_req_hdlr(module_type source, wap_mma_cancel_send_req_struct *cancel_send_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *send_req_info_p = NULL;
    MSF_INT32 connection_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cancel_send_req_p);
    send_req_info_p = g_mma_sendrecv_cntx.send_req_list;
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_CANCEL_SEND_REQ_HDLR,
                       "MMA SENDRECV cancel send req hdlr"));

    if (g_mma_sendrecv_cntx.state != MMA_SENDRECV_STATE_STARTED)
    {
        mma_result_enum result = MMA_RESULT_FAIL_NOT_READY;

        if (g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPING)
        {
            result = MMA_RESULT_FAIL_TERMINATING;
        }
        mms_mma_send_cancel_send_rsp(
            source,
            cancel_send_req_p->app_id,
            cancel_send_req_p->req_id,
            cancel_send_req_p->msg_id,
            (kal_uint8) result);
        goto exit;
    }

    if (send_req_info_p == NULL)
    {
        mms_mma_send_cancel_send_rsp(
            source,
            cancel_send_req_p->app_id,
            cancel_send_req_p->req_id,
            cancel_send_req_p->msg_id,
            MMA_RESULT_FAIL_INVALID_MSGID);
        goto exit;
    }

    if (cancel_send_req_p->msg_id != 0)
    {
        if (send_req_info_p->msg_id == cancel_send_req_p->msg_id)
        {
            connection_status = cbm_get_bearer_status(mma_setting_get_account_id(translate_mma_sim_to_mms_sim(send_req_info_p->sim_id)));
            if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_SENDING_CANCELLED) == TRUE)
            {
                mms_mma_send_cancel_send_rsp(
                    source,
                    cancel_send_req_p->app_id,
                    cancel_send_req_p->req_id,
                    cancel_send_req_p->msg_id,
                    MMA_RESULT_FAIL_MSGID_IS_USING);
                goto exit;
            }
            else if (g_mma_sendrecv_cntx.send_percent == 100 && connection_status == CBM_ACTIVATED)
            {
                MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_CANCEL_SEND_REQ_HDLR1,
                                   "MMA SENDRECV In cancel send req hdlr, send percent =100 and connection_status is CBM_ACTIVATED"));
            }
            mma_sendrecv_set_flag(MMA_SENDRECV_IS_SENDING_CANCELLED);
            MMSif_sendCancel(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(send_req_info_p->msg_id));
            goto exit;
        }
    }
    while (send_req_info_p->next != NULL)
    {
        if (send_req_info_p->next->msg_id == cancel_send_req_p->msg_id)
        {
            /* Remove the node and change status to NORMAL */
            mma_sendrecv_req_info_list_struct *tmp_p = NULL;

            mms_mma_send_cancel_send_rsp(
                source,
                cancel_send_req_p->app_id,
                cancel_send_req_p->req_id,
                cancel_send_req_p->msg_id,
                MMA_RESULT_OK);

            tmp_p = send_req_info_p->next;

            mms_mma_send_send_rsp(
                source,
                tmp_p->app_id,
                tmp_p->req_id,
                tmp_p->msg_id,
                MMA_RESULT_FAIL_USER_CANCEL,
                NULL);

            /* Remove the node from g_mma_sendrecv_cntx.send_req_list */
            send_req_info_p->next = send_req_info_p->next->next;
            MMA_FREE(tmp_p);
            goto exit;
        }
        send_req_info_p = send_req_info_p->next;
    }
    mms_mma_send_cancel_send_rsp(
        source,
        cancel_send_req_p->app_id,
        cancel_send_req_p->req_id,
        cancel_send_req_p->msg_id,
        MMA_RESULT_FAIL_INVALID_MSGID);

  exit:
    MMA_FREE(cancel_send_req_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_process_one_download_req
 * DESCRIPTION
 *  Function to process one download request from queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_process_one_download_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;
    kal_uint16 storage_data = 0;
    kal_uint8 temp_storage = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_sendrecv_cntx.recv_req_list == NULL)
    {
        return;
    }
    else
    {
        /* Pick up first node */
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_PROCESS_ONE_DOWNLOAD_REQ,
                           "MMA SENDRECV process one download req"));
        download_req_info_p = g_mma_sendrecv_cntx.recv_req_list;
        if (mma_msgmgr_msg_info_exist(download_req_info_p->msg_id) == FALSE)
        {
            mms_mma_send_download_rsp(
                download_req_info_p->source,
                download_req_info_p->app_id,
                download_req_info_p->req_id,
                download_req_info_p->msg_id,
                0,
                MMA_RESULT_FAIL_INVALID_MSGID,
                NULL);
        }
        else if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING) == FALSE)
        {
            mma_result_enum error_code = MMA_RESULT_OK;

        #ifdef __USB_IN_NORMAL_MODE__
            if ((srv_usb_is_in_mass_storage_mode() || mma_main_is_in_usb_mode()) && mma_is_storage_exported_to_pc())    /* Check if MMS should be disabled */
            {
                error_code = MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;
            }
        #endif /* __USB_IN_NORMAL_MODE__ */ 
            if (error_code == MMA_RESULT_OK)
            {
                if (mma_main_is_in_terminate() == TRUE)
                {
                    error_code = MMA_RESULT_FAIL_TERMINATING;
                }
            }
            if (error_code != MMA_RESULT_OK)
            {

                mms_mma_send_download_rsp(
                    download_req_info_p->source,
                    download_req_info_p->app_id,
                    download_req_info_p->req_id,
                    download_req_info_p->msg_id,
                    0,
                    (kal_uint8) error_code,
                    NULL);
            }
            else
            {
                if (mma_msgmgr_is_busy())
                {
                    /* We should not trigger download request now. Because the notification file for previous download request may not be deleted yet. */
                    MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_PROCESS_RECV_Q_IND);
                    return;
                }
                else
                {
                    temp_storage = mma_setting_get_preffered_storage();
                    storage_data = mma_get_message_storage(download_req_info_p->msg_id);
                    if(!(mma_main_is_storage_type_present((mma_msg_storage_type_enum)temp_storage) && mma_main_is_storage_type_present((mma_msg_storage_type_enum)storage_data)))
                    {
                        mms_mma_send_download_rsp(
                            download_req_info_p->source,
                            download_req_info_p->app_id,
                            download_req_info_p->req_id,
                            download_req_info_p->msg_id,
                            0,
                            MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT,
                            NULL);
                    }
                    else
                    {
                        if((mma_msgmgr_get_total_msg_num(MMA_MSG_STORAGE_PHONE) < MMS_NO_OF_MSG_WARNING) && (mma_msgmgr_get_total_msg_num(MMA_MSG_STORAGE_CARD1)< MMS_NO_OF_MSG_WARNING))
                        {
                            if(mma_get_mms_avaliable_file_space(NULL, MMA_MSG_STORAGE_PHONE) >= MMA_MAX_MMS_SIZE)
                            {
                                temp_storage = MMA_MSG_STORAGE_PHONE;
                            }
                        }
                        else if((storage_data != (kal_uint16)temp_storage) && (mma_msgmgr_get_total_msg_num((mma_msg_storage_type_enum)temp_storage) >= (kal_uint16)(wap_custom_get_max_mms_num() - 1)))
                        {
                            temp_storage = (kal_uint8)storage_data;
                        }
                        download_req_info_p->storage_type = temp_storage;
                        storage_data = translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)storage_data);
                        storage_data = (storage_data<<8) | translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)temp_storage);
                        MMSif_retrieveMessage(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(download_req_info_p->msg_id), (MmsSimCardEnum)translate_mma_sim_to_mms_sim(download_req_info_p->sim_id), storage_data);
                        mma_sendrecv_set_flag(MMA_SENDRECV_IS_DOWNLOADING);
                        g_mma_sendrecv_cntx.download_prv_percent = 101;
                        return;
                    }
                }
            }
        }
        else
        {
            return;
        }
    }

    g_mma_sendrecv_cntx.recv_req_list = g_mma_sendrecv_cntx.recv_req_list->next;
    MMA_FREE(download_req_info_p);
    if (g_mma_sendrecv_cntx.recv_req_list != NULL)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_SENDRECV, MMA_INT_SIG_TYPE_MSG_PROCESS_RECV_Q_IND);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_download_req_hdlr
 * DESCRIPTION
 *  Function to process download request
 * PARAMETERS
 *  source              [IN]        
 *  download_req_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_download_req_hdlr(module_type source, wap_mma_download_req_struct *download_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(download_req_p);

    /* Step 1: Check if the MMA send recv is ready */
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_DOWNLOAD_REQ_HDLR,
                       "MMA SENDRECV download req hdlr"));
    if (g_mma_sendrecv_cntx.state != MMA_SENDRECV_STATE_STARTED)
    {
        mma_result_enum result = MMA_RESULT_FAIL_NOT_READY;

        if (g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPING)
        {
            result = MMA_RESULT_FAIL_TERMINATING;
        }
        mms_mma_send_download_rsp(
            source,
            download_req_p->app_id,
            download_req_p->req_id,
            download_req_p->msg_id,
            0,
            (kal_uint8) result,
            NULL);
    }
    else if(mma_setting_is_supended(translate_mma_sim_to_mms_sim(download_req_p->sim_id)))
    {
        mms_mma_send_download_rsp(
            source,
            download_req_p->app_id,
            download_req_p->req_id,
            download_req_p->msg_id,
            0,
            MMA_RESULT_FAIL_SUSPENDED_MODE,
            NULL);

    }
    else if(mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION) == TRUE || mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION_MEM) == TRUE)
    {
         mms_mma_send_download_rsp(
            source,
            download_req_p->app_id,
            download_req_p->req_id,
            download_req_p->msg_id,
            0,
            MMA_RESULT_FAIL_BUSY,
            NULL);
    }
    /* Step 2: Check if the MMS message is in download queue */
    else if (mma_sendrecv_get_req_from_queue(g_mma_sendrecv_cntx.recv_req_list, download_req_p->msg_id) != NULL)
    {
        mms_mma_send_download_rsp(
            source,
            download_req_p->app_id,
            download_req_p->req_id,
            download_req_p->msg_id,
            0,
            MMA_RESULT_FAIL_MSGID_IS_USING,
            NULL);
    }
    /* Step 3: Check if the info of MMS message is restored */
    else if (mma_msgmgr_msg_info_exist(download_req_p->msg_id) == FALSE ||
             mma_msgmgr_is_valid_notifiction(download_req_p->msg_id) == FALSE)
    {
        /* Invalid msg id */
        mms_mma_send_download_rsp(
            source,
            download_req_p->app_id,
            download_req_p->req_id,
            download_req_p->msg_id,
            0,
            MMA_RESULT_FAIL_INVALID_MSGID,
            NULL);
    }
    else
    {
        download_req_info_p =
            (mma_sendrecv_req_info_list_struct*) MMA_CALLOC(sizeof(mma_sendrecv_req_info_list_struct));

        if (download_req_info_p == NULL)
        {
            mms_mma_send_download_rsp(
                source,
                download_req_p->app_id,
                download_req_p->req_id,
                download_req_p->msg_id,
                0,
                MMA_RESULT_FAIL_INSUFFICIENT_MEMORY,
                NULL);
        }
        else
        {
            /* Insert one node to waiting queue */
            download_req_info_p->source = source;
            download_req_info_p->app_id = download_req_p->app_id;
            download_req_info_p->req_id = download_req_p->req_id;
            download_req_info_p->msg_id = download_req_p->msg_id;
            download_req_info_p->sim_id = download_req_p->sim_id;
            mma_sendrecv_add_req_to_queue(&g_mma_sendrecv_cntx.recv_req_list, download_req_info_p);
            mma_sendrecv_process_one_download_req();
        }
    }

    MMA_FREE(download_req_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_download_rsp_hdlr
 * DESCRIPTION
 *  Function to process download response
 * PARAMETERS
 *  msgId               [IN]        When msgid is 0, it means SEND_RR_RSP is received
 *  download_result     [IN]        
 *  retrieve_txt        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_sendrecv_download_rsp_hdlr(kal_uint32 msgId, MmsResult download_result, char *retrieve_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPING || g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPED)
	{
		if (retrieve_txt != NULL)
		{
			MMA_FREE(retrieve_txt);
		}
		return;
	}
    download_req_info_p = g_mma_sendrecv_cntx.recv_req_list;

    ASSERT(download_req_info_p);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_DOWNLOAD_RSP_HDLR,
                      "MMA SENDRECV download rsp hdlr msgId=%d, download_result=%d, retrieve_txt=%s", msgId,
                      download_result, retrieve_txt));

    /* We need do special handlings to send read report */
    g_mma_sendrecv_cntx.retrieve_txt = retrieve_txt;
    if (download_result == MMS_RESULT_OK)
    {
        mma_msgmgr_add_new_message_req_hdlr(
            mma_main_encode_msg_id(download_req_info_p->storage_type, msgId),
            MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD,
            download_req_info_p->msg_id,
            (kal_uint32) download_req_info_p->sim_id);
    }
    else
    {
        mma_sendrecv_msgmgr_download_rsp_hdlr(download_result, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_msgmgr_download_rsp_hdlr
 * DESCRIPTION
 *  Function to send download reponse
 * PARAMETERS
 *  download_result     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_sendrecv_msgmgr_download_rsp_hdlr(MmsResult download_result, kal_uint32 new_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;
    char *retrieve_txt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    download_req_info_p = g_mma_sendrecv_cntx.recv_req_list;
    retrieve_txt = g_mma_sendrecv_cntx.retrieve_txt;
    ASSERT(download_req_info_p);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_MSGMGR_DOWNLOAD_RSP_HDLR,
                       "MMA SENDRECV msgmgr download rsp hdlr"));
    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING_CANCELLED) == TRUE)
    {
        if (download_result == MMS_RESULT_OK)
        {
            mms_mma_send_cancel_download_rsp(
                download_req_info_p->source,
                download_req_info_p->app_id,
                download_req_info_p->req_id,
                download_req_info_p->msg_id,
                MMA_RESULT_FAIL_MSGID_IS_USING);

            mms_mma_send_download_rsp(
                download_req_info_p->source,
                download_req_info_p->app_id,
                download_req_info_p->req_id,
                download_req_info_p->msg_id,
                new_msg_id,
                MMA_RESULT_OK,
                retrieve_txt);
        }
        else
        {
            mms_mma_send_cancel_download_rsp(
                download_req_info_p->source,
                download_req_info_p->app_id,
                download_req_info_p->req_id,
                download_req_info_p->msg_id,
                MMA_RESULT_OK);

            mms_mma_send_download_rsp(
                download_req_info_p->source,
                download_req_info_p->app_id,
                download_req_info_p->req_id,
                download_req_info_p->msg_id,
                0,
                MMA_RESULT_FAIL_USER_CANCEL,
                NULL);
        }
        mma_sendrecv_unset_flag(MMA_SENDRECV_IS_DOWNLOADING_CANCELLED);
    }
    else
    {
        mms_mma_send_download_rsp(
            download_req_info_p->source,
            download_req_info_p->app_id,
            download_req_info_p->req_id,
            download_req_info_p->msg_id,
            new_msg_id,
            (kal_uint8) ((download_result != MMS_RESULT_OK && download_req_info_p->result == MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE) ? MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE : translate_mms_result_to_mma(download_result)),
            retrieve_txt);
    }

    if (download_req_info_p->result == MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE)
    {
        download_req_info_p->result = MMA_RESULT_OK;
        /* There is no send request waiting for cancel send resposne. We can send enter usb mode to MOD_MMI */
        if (g_mma_sendrecv_cntx.send_req_list == NULL ||
            g_mma_sendrecv_cntx.send_req_list->result != MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE)
        {
            /* We need to wait MMA msgmgr module complete everything */
            MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
        }
    }

    g_mma_sendrecv_cntx.recv_req_list = g_mma_sendrecv_cntx.recv_req_list->next;
    mma_sendrecv_unset_flag(MMA_SENDRECV_IS_DOWNLOADING);

    mma_sendrecv_process_one_download_req();
    if (retrieve_txt != NULL)
    {
        MMA_FREE(retrieve_txt);
    }
    MMA_FREE(download_req_info_p);

}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_cancel_download_req_hdlr
 * DESCRIPTION
 *  Function to process cancel download request
 * PARAMETERS
 *  source                      [IN]        
 *  cancel_download_req_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_cancel_download_req_hdlr(
                module_type source,
                wap_mma_cancel_download_req_struct *cancel_download_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;
    MSF_INT32 connection_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cancel_download_req_p);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_CANCEL_DOWNLOAD_REQ_HDLR,
                       "MMA SENDRECV cancel download req hdlr"));
    if (g_mma_sendrecv_cntx.state != MMA_SENDRECV_STATE_STARTED)
    {
        mma_result_enum result = MMA_RESULT_FAIL_NOT_READY;

        if (g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPING)
        {
            result = MMA_RESULT_FAIL_TERMINATING;
        }
        mms_mma_send_cancel_download_rsp(
            source,
            cancel_download_req_p->app_id,
            cancel_download_req_p->req_id,
            cancel_download_req_p->msg_id,
            (kal_uint8) result);
        goto exit;
    }

    download_req_info_p = g_mma_sendrecv_cntx.recv_req_list;
    if (download_req_info_p == NULL)
    {
        mms_mma_send_cancel_download_rsp(
            source,
            cancel_download_req_p->app_id,
            cancel_download_req_p->req_id,
            cancel_download_req_p->msg_id,
            MMA_RESULT_FAIL_INVALID_MSGID);
        goto exit;
    }

    if (download_req_info_p->msg_id == cancel_download_req_p->msg_id)
    {
        connection_status = cbm_get_bearer_status(mma_setting_get_account_id(translate_mma_sim_to_mms_sim(download_req_info_p->sim_id)));
        if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING_CANCELLED) == TRUE)
        {
            mms_mma_send_cancel_download_rsp(
                source,
                cancel_download_req_p->app_id,
                cancel_download_req_p->req_id,
                cancel_download_req_p->msg_id,
                MMA_RESULT_FAIL_MSGID_IS_USING);
        }
        else if (g_mma_sendrecv_cntx.download_percent == 100 && connection_status == CBM_ACTIVATED)
        {
            mms_mma_send_cancel_download_rsp(
                source,
                cancel_download_req_p->app_id,
                cancel_download_req_p->req_id,
                cancel_download_req_p->msg_id,
                MMA_RESULT_FAIL);
        }
        else
        {
            mma_sendrecv_set_flag(MMA_SENDRECV_IS_DOWNLOADING_CANCELLED);
            if (mma_msgmgr_check_msg_exist(download_req_info_p->msg_id))
            {
                /* We only cancel the download request when the notification is not removed. */
                MMSif_retrieveCancel(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(download_req_info_p->msg_id));
            }
            else
            {
                mms_mma_send_cancel_download_rsp(
                    source,
                    cancel_download_req_p->app_id,
                    cancel_download_req_p->req_id,
                    cancel_download_req_p->msg_id,
                    MMA_RESULT_FAIL_INVALID_MSGID);
            }
        }
        goto exit;
    }
    while (download_req_info_p->next != NULL)
    {
        if (download_req_info_p->next->msg_id == cancel_download_req_p->msg_id)
        {
            /* Remove the node and change status to NORMAL */
            mma_sendrecv_req_info_list_struct *tmp_p = NULL;
            mms_mma_send_cancel_download_rsp(
                source,
                cancel_download_req_p->app_id,
                cancel_download_req_p->req_id,
                cancel_download_req_p->msg_id,
                MMA_RESULT_OK);

            tmp_p = download_req_info_p->next;

            mms_mma_send_download_rsp(
                source,
                tmp_p->app_id,
                tmp_p->req_id,
                tmp_p->msg_id,
                0,
                MMA_RESULT_FAIL_USER_CANCEL,
                NULL);

            /* Remove the node from g_mma_sendrecv_cntx.recv_req_list */
            download_req_info_p->next = download_req_info_p->next->next;
            MMA_FREE(tmp_p);

            goto exit;
        }
        download_req_info_p = download_req_info_p->next;
    }
    mms_mma_send_cancel_download_rsp(
        source,
        cancel_download_req_p->app_id,
        cancel_download_req_p->req_id,
        cancel_download_req_p->msg_id,
        MMA_RESULT_FAIL_INVALID_MSGID);

  exit:
    MMA_FREE(cancel_download_req_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_download_ind_res_hdlr
 * DESCRIPTION
 *  Function to process download indication
 * PARAMETERS
 *  source              [IN]        
 *  download_res_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_sendrecv_download_ind_res_hdlr(module_type source, wap_mma_download_res_struct *download_res_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_download_ind_res_hdlr,
                       "MMA SENDRECV download ind res hdlr"));
    g_mma_sendrecv_cntx.download_ind = FALSE;
    if (g_mma_sendrecv_cntx.recv_req_list)
    {
        if (g_mma_sendrecv_cntx.recv_req_list->source == source &&
            g_mma_sendrecv_cntx.recv_req_list->app_id == download_res_p->app_id &&
            g_mma_sendrecv_cntx.download_percent != 100 &&
            g_mma_sendrecv_cntx.download_percent != g_mma_sendrecv_cntx.download_prv_percent)
        {
            g_mma_sendrecv_cntx.download_prv_percent = g_mma_sendrecv_cntx.download_percent;
            g_mma_sendrecv_cntx.download_ind = TRUE;
            mms_mma_send_download_ind(
                g_mma_sendrecv_cntx.recv_req_list->source,
                g_mma_sendrecv_cntx.recv_req_list->app_id,
                g_mma_sendrecv_cntx.recv_req_list->req_id,
                g_mma_sendrecv_cntx.recv_req_list->msg_id,
                0,
                (kal_uint8) g_mma_sendrecv_cntx.download_percent,
                g_mma_sendrecv_cntx.download_progress,
                g_mma_sendrecv_cntx.recv_req_list->sim_id);
        }
    }
    MMA_FREE(download_res_p);
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_enter_usb_mode_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_sendrecv_enter_usb_mode_ind_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *send_req_info_p = NULL;
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;
    MSF_BOOL send_enter_usb_mode = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_enter_usb_mode_ind_hdlr,
                       "MMA SENDRECV enter usb mode ind hdlr"));
    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_SENDING) == TRUE)
    {
        send_req_info_p = g_mma_sendrecv_cntx.send_req_list;
        MMSif_sendCancel(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(send_req_info_p->msg_id));
        send_req_info_p->result = MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;
        send_enter_usb_mode = FALSE;
    }

    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING) == TRUE)
    {
        download_req_info_p = g_mma_sendrecv_cntx.recv_req_list;
        MMSif_retrieveCancel(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(download_req_info_p->msg_id));
        download_req_info_p->result = MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;
        send_enter_usb_mode = FALSE;
    }
    if (send_enter_usb_mode == TRUE)
    {
        /* We need to wait MMA msgmgr module complete everything */
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_is_busy
 * DESCRIPTION
 *  The function is used check if MMA SNDRCV sub-module is busy.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MSF_BOOL mma_sendrecv_is_busy(mma_msg_storage_type_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_MMA_SENDRECV_IS_BUSY,
                       "MMA SENDRECV Is MMA SendReceive busy"));
    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING) == TRUE)
    {
        if((mma_get_message_storage(g_mma_sendrecv_cntx.recv_req_list->msg_id) == storage_type)||(g_mma_sendrecv_cntx.recv_req_list->storage_type == storage_type))
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_MMA_SENDRECV_IS_BUSY1,
                               "MMA SENDRECV is busy to download msg"));
            return TRUE;
        }
    }
    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_SENDING) == TRUE)
    {
        if((mma_get_message_storage(g_mma_sendrecv_cntx.send_req_list->msg_id) == storage_type)||(g_mma_sendrecv_cntx.send_req_list->is_read_report&&g_mma_sendrecv_cntx.send_req_list->storage_type == storage_type))
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_MMA_SENDRECV_IS_BUSY2,
                               "MMA SENDRECV is busy to send msg"));
            return TRUE;
        }
    }
    if (storage_type == MMA_MSG_STORAGE_PHONE)
    {
        if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION) == TRUE)
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_MMA_SENDRECV_IS_BUSY3,
                               "MMA SENDRECV is busy to store NOTIFICATION"));
            return TRUE;
        }
    }
    else
    {
        if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION_MEM) == TRUE)
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_MMA_SENDRECV_IS_BUSY3,
                               "MMA SENDRECV is busy to store NOTIFICATION"));
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_progress_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  progressData        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_sendrecv_progress_ind_hdlr(MmsProgressStatus *progressData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_progress_ind_hdlr,
                       "MMA SENDRECV progress ind hdlr"));
    progressData->msgId = mma_main_encode_msg_id((kal_uint8)translate_mms_storage_to_mma_storage_enum((msf_mms_storage_enum)progressData->storageType), progressData->msgId);
    switch (progressData->operation)
    {
        case MMS_PROGRESS_STATUS_IMMRETRIEVE:
            switch (progressData->state)
            {
                case MMS_PROGRESS_STATUS_START:
                    mms_mma_send_start_immed_retrieval_ind(MOD_MMI, progressData->msgId, progressData->simId);
                    break;

                case MMS_PROGRESS_STATUS_COMPLETED:
                    mms_mma_send_stop_immed_retrieval_ind(
                        MOD_MMI,
                        progressData->msgId,
                        MMA_RESULT_OK,
                        progressData->simId,
                        0,  /* means OK */
                        NULL);
                    break;

                case MMS_PROGRESS_STATUS_STOP:
                    mms_mma_send_stop_immed_retrieval_ind(
                        MOD_MMI,
                        progressData->msgId,
                        MMA_RESULT_FAIL,
                        progressData->simId,
                        0,  /* means OK */
                        NULL);
                    break;
                case MMS_PROGRESS_STATUS_PROGRESS:
                    break;
            }
            break;

        case MMS_PROGRESS_STATUS_SEND:
            if (mma_sendrecv_is_sending(progressData->msgId))
            {
                kal_uint8 percent = (kal_uint8)((progressData->totalLength == 0) ? 0 :
                    ((kal_uint32) (progressData->progress * 100) / progressData->totalLength));

                mms_mma_send_send_ind(
                    g_mma_sendrecv_cntx.send_req_list->source,
                    g_mma_sendrecv_cntx.send_req_list->app_id,
                    g_mma_sendrecv_cntx.send_req_list->req_id,
                    g_mma_sendrecv_cntx.send_req_list->msg_id,
                    0,
                    (kal_uint8) ((percent >= 100) ? 99 : percent),
                    g_mma_sendrecv_cntx.send_req_list->sim_id);
                g_mma_sendrecv_cntx.send_percent = percent;
            }
            break;

        case MMS_PROGRESS_STATUS_RETRIEVE:
            if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING))
            {
                kal_uint8 percent = (kal_uint8)((progressData->totalLength == 0) ? 0 :
                    ((kal_uint32) (progressData->progress * 100) / progressData->totalLength));

                if (percent >= 100)
                {
                    percent = 100;
                }
                if (progressData->state == MMS_PROGRESS_STATUS_STOP)
                {
                    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                       MMA_SENDRECV_progress_ind_hdlr1, "MMA SENDRECV RcvPrgIndStop"));

                }
                else if (progressData->state == MMS_PROGRESS_STATUS_COMPLETED)
                {
                    mms_mma_send_download_ind(
                        g_mma_sendrecv_cntx.recv_req_list->source,
                        g_mma_sendrecv_cntx.recv_req_list->app_id,
                        g_mma_sendrecv_cntx.recv_req_list->req_id,
                        g_mma_sendrecv_cntx.recv_req_list->msg_id,
                        0,
                        (kal_uint8) percent,
                        progressData->progress,
                        g_mma_sendrecv_cntx.recv_req_list->sim_id);
                }
                else if (progressData->state == MMS_PROGRESS_STATUS_PROGRESS)
                {
                    if ((percent != g_mma_sendrecv_cntx.download_prv_percent) && g_mma_sendrecv_cntx.download_ind == FALSE)
                    {
                        g_mma_sendrecv_cntx.download_prv_percent = percent;
                        g_mma_sendrecv_cntx.download_ind = TRUE;
                        mms_mma_send_download_ind(
                            g_mma_sendrecv_cntx.recv_req_list->source,
                            g_mma_sendrecv_cntx.recv_req_list->app_id,
                            g_mma_sendrecv_cntx.recv_req_list->req_id,
                            g_mma_sendrecv_cntx.recv_req_list->msg_id,
                            0,
                            (kal_uint8) ((percent == 100) ? 99 : percent),
                            progressData->progress,
                            g_mma_sendrecv_cntx.recv_req_list->sim_id);
                    }
                }
                g_mma_sendrecv_cntx.download_percent = percent;
                g_mma_sendrecv_cntx.download_progress = progressData->progress;
            }
            break;
        default:
            break;
    }
    MMA_FREE(progressData);
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_mms_delete_ind_hdlr
 * DESCRIPTION
 *  This function is used to check the result of MMSif_deleteMessage()
 * PARAMETERS
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_mms_delete_ind_hdlr(MmsResult result, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_mms_delete_ind_hdlr,
                      "MMA SENDRECV mms delete ind hdlr %d", (int)msg_id));
    if (result != MMS_RESULT_OK)
    {
        if (mma_msgmgr_check_msg_exist(msg_id) == TRUE)
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                              MMA_SENDRECV_mms_delete_ind_hdlr1 "MMA_SENDRECV: Fail to delete rr %d, %d", (int)msg_id,
                              result));
            ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_mms_obj_ind
 * DESCRIPTION
 *  This function is used to handle notification
 * PARAMETERS
 *  source              [IN]        
 *  recv_push_info      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_mms_obj_ind(module_type source, wap_mma_mms_obj_ind_struct *recv_push_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long file_size = 0;
    int file_handle = -1;
    unsigned char *data = NULL;
    char *file_path = NULL;
    kal_wchar *file_path_ucs2 = recv_push_info->mms_filepath;
    mma_msg_storage_type_enum storage_type = MMA_MSG_STORAGE_NONE;
    kal_uint32 sim_id = 0;
    kal_bool is_deferred = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_mms_obj_ind, "MMA SENDRECV mms obj ind"));
    storage_type = (mma_msg_storage_type_enum)mma_setting_get_preffered_storage();
    sim_id = translate_mma_sim_to_mms_sim(recv_push_info->sim_id);
    if(!mma_main_is_storage_type_present(storage_type))
    {
        is_deferred = KAL_TRUE;
        storage_type = MMA_MSG_STORAGE_PHONE;
    }
    if(mma_msgmgr_get_total_msg_num(storage_type)>= (kal_uint16)(wap_custom_get_max_mms_num() - 1))
    {
        mms_mma_send_mms_obj_rsp(
            source,
            recv_push_info->app_id,
            recv_push_info->req_id,
            MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED);
        mms_mma_send_storage_full_ind(MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED);
    }
    else if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION) == FALSE && mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION_MEM) == FALSE
        && (!mma_setting_is_supended(sim_id))
        && mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING) == FALSE)
    {
        file_path = (char*)mma_ucs2_to_utf8_string((const kal_wchar*)file_path_ucs2);
        file_size = MSF_FILE_GETSIZE_EXT(file_path, MSF_MMS_STORAGE_NONE);
        data = (unsigned char*)MMA_ALLOC(file_size);
        ASSERT(data);
        file_handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MSM, file_path, MSF_FILE_SET_RDONLY, 0, MMA_MSG_STORAGE_NONE);
        
        if (file_handle >= 0)
        {
            if (MSF_FILE_READ(file_handle, data, file_size) == file_size)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_mms_obj_ind1,
                                  "MMA SENDRECV send push to MMS of size=%d", file_size));
                g_mma_sendrecv_cntx.mms_obj_data = MMA_ALLOC(sizeof(mma_sendrecv_mms_obj_info_struct));
                g_mma_sendrecv_cntx.mms_obj_data->source = source;
                g_mma_sendrecv_cntx.mms_obj_data->app_id = recv_push_info->app_id;
                g_mma_sendrecv_cntx.mms_obj_data->req_id = recv_push_info->req_id;
                if((mma_msgmgr_get_total_msg_num(MMA_MSG_STORAGE_PHONE) < MMS_NO_OF_MSG_WARNING) && (mma_msgmgr_get_total_msg_num(MMA_MSG_STORAGE_CARD1)< MMS_NO_OF_MSG_WARNING))
                {
                    if(mma_get_mms_avaliable_file_space(NULL, MMA_MSG_STORAGE_PHONE) >= MMA_MAX_MMS_SIZE )
                    {
                        storage_type = MMA_MSG_STORAGE_PHONE;
                    }
                }
                MMSif_pushNotification(MSF_MODID_MMA, data, file_size, sim_id, (kal_uint8)translate_mma_storage_to_mms_storage_enum(storage_type), is_deferred);
                MMA_FREE(data);
                if(storage_type == MMA_MSG_STORAGE_PHONE)
                {
                    mma_sendrecv_set_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION);
                }
                else
                {
                    mma_sendrecv_set_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION_MEM);
                }
            }
            else
            {
                mms_mma_send_mms_obj_rsp(
                    source,
                    recv_push_info->app_id,
                    recv_push_info->req_id,
                    MMA_RESULT_FAIL_FILE_IO);
            }
            MSF_FILE_CLOSE(file_handle);
        }
        else
        {
            mms_mma_send_mms_obj_rsp(source, recv_push_info->app_id, recv_push_info->req_id, MMA_RESULT_FAIL_FILE_IO);
        }
    }
    else if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING) == TRUE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_mms_obj_ind3,
                           "MMA SENDRECV during mms_obj_ind MMA SENDRECV IS BUSY IN DOWNLOADING"));
        mms_mma_send_mms_obj_rsp(source, recv_push_info->app_id, recv_push_info->req_id, MMA_RESULT_FAIL_BUSY);
    }
    else if (mma_setting_is_supended(sim_id))
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_mms_obj_ind2,
                           "MMA SENDRECV during mms_obj_ind MMA SENDRECV IS SUSPENDED"));
        mms_mma_send_mms_obj_rsp(
            source,
            recv_push_info->app_id,
            recv_push_info->req_id,
            MMA_RESULT_FAIL_SUSPENDED_MODE);

    }
    else
    {
        ASSERT(0);
    }
    MMA_FREE(file_path);
    MMA_FREE(recv_push_info);
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_mms_obj_rsp
 * DESCRIPTION
 *  This function is used to handle notification response
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_mms_obj_rsp(MmsResult result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum mma_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_mms_obj_rsp, "MMA SENDRECV mms obj rsp"));
	if (g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPING || g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPED)
    {
		return;
    }
    if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION) == TRUE || mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION_MEM) == TRUE)
    {
        mma_sendrecv_unset_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION);
        mma_sendrecv_unset_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION_MEM);
        mma_result = translate_mms_result_to_mma(result);
        mms_mma_send_mms_obj_rsp(
            g_mma_sendrecv_cntx.mms_obj_data->source,
            g_mma_sendrecv_cntx.mms_obj_data->app_id,
            g_mma_sendrecv_cntx.mms_obj_data->req_id,
            (kal_uint8) mma_result);
        MMA_FREE(g_mma_sendrecv_cntx.mms_obj_data);
        if (mma_result == MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED || mma_result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE || mma_result == MMA_RESULT_FAIL_ROOT_DIR_FULL)
        {
            mms_mma_send_storage_full_ind(mma_result);
        }
        else if (result == MMS_RESULT_OK_MEM_FULL)
        {
            mms_mma_send_storage_full_ind(MMA_RESULT_FAIL_INSUFFICIENT_STORAGE);
        }
    }
    else
    {
        ASSERT(0);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_handle_rsp
 * DESCRIPTION
 *  This function is used to handle response signal returned from MMS module
 * PARAMETERS
 *  sig         [IN]        
 *  sigData     [IN]        
 * RETURNS
 *  TRUE: the signal is processed by MMA_SENDRECV
 *****************************************************************************/
MSF_BOOL mma_sendrecv_handle_rsp(kal_uint16 sig, void *sigData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sig)
    {
        case MMS_SIG_DELETE_MSG_REPLY:
        {
            MmsMsgDoneReplySig *data = (MmsMsgDoneReplySig*) sigData;

            if (g_mma_sendrecv_cntx.rr_id != 0)
            {
                MMA_SIGNAL_SENDTO_IU(
                    MMA_SUBMODULE_MSG_SENDRECV,
                    MMA_INT_SIG_TYPE_MSG_MMS_DELETE_IND,
                    data->result,
                    (unsigned int)g_mma_sendrecv_cntx.rr_id);

                g_mma_sendrecv_cntx.rr_id = 0;
                return TRUE;
            }
            else
            {
                return FALSE;
            }
        }
        default:
            return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_process_int_sig
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_sendrecv_process_int_sig(mma_signal_struct *sig)
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
        case MMA_INT_SIG_TYPE_MSG_SEND_MSG:
            mma_sendrecv_send_req_hdlr((module_type) sig->i_param, (wap_mma_send_req_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_SEND_MSG_RSP:
        case MMA_INT_SIG_TYPE_MSG_SEND_RR_RSP:
            mma_sendrecv_send_rsp_hdlr(sig->u_param1, (MmsResult)sig->u_param2, (MmsResponseStatus)sig->i_param, sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_CANCEL_SEND_MSG:
            mma_sendrecv_cancel_send_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_cancel_send_req_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_RECV_MSG:
            mma_sendrecv_download_req_hdlr((module_type) sig->i_param, (wap_mma_download_req_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_RECV_MSG_RSP:
            mma_sendrecv_download_rsp_hdlr(sig->i_param, (MmsResult)sig->u_param1, sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_CANCEL_RECV_MSG:
            mma_sendrecv_cancel_download_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_cancel_download_req_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_RECV_IND_RES:
            mma_sendrecv_download_ind_res_hdlr(
                (module_type) sig->i_param,
                (wap_mma_download_res_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_PROGRESS_IND:
            mma_sendrecv_progress_ind_hdlr((MmsProgressStatus*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_PROCESS_SEND_Q_IND:
            mma_sendrecv_process_one_send_req();
            break;
        case MMA_INT_SIG_TYPE_MSG_PROCESS_RECV_Q_IND:
            mma_sendrecv_process_one_download_req();
            break;
        case MMA_INT_SIG_TYPE_MSG_MMS_DELETE_IND:
            mma_sendrecv_mms_delete_ind_hdlr((MmsResult) sig->i_param, (kal_uint32) sig->u_param1);
            break;
        case MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ:
            mma_sendrecv_enter_usb_mode_ind_hdlr();
            break;
        case MMA_INT_SIG_TYPE_MSG_TERMINATE_IND:
            mma_sendrecv_termiante_all_requests();
            break;
        case MMA_INT_SIG_TYPE_MSG_MMS_OBJ_IND:
            mma_sendrecv_mms_obj_ind((module_type) sig->i_param, (wap_mma_mms_obj_ind_struct*) sig->p_param);
            break;
        case MMA_INT_SIG_TYPE_MSG_MMS_OBJ_RES:
            mma_sendrecv_mms_obj_rsp((MmsResult) sig->i_param);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_sendrecv_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_sendrecv_cntx.state = MMA_SENDRECV_STATE_STARTED;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_termiante_all_requests
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_sendrecv_termiante_all_requests(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *send_req_info_p = NULL;
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_termiante_all_requests,
                       "MMA SENDRECV termiante all requests"));
    g_mma_sendrecv_cntx.state = MMA_SENDRECV_STATE_STOPPING;

    /* Cancel all send request */
    send_req_info_p = g_mma_sendrecv_cntx.send_req_list;

    if (send_req_info_p)
    {
        if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_SENDING))
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                   MMA_SENDRECV_termiante_all_requests1,
                                   "In mma_sendrecv_termiante_all_requests We already send mms.Don't cancel send req."));
			mma_sendrecv_unset_flag(MMA_SENDRECV_IS_SENDING);
        }
		MMA_FREE(send_req_info_p);
		g_mma_sendrecv_cntx.send_req_list = NULL;
    }

    /* Cancel all download request */
    download_req_info_p = g_mma_sendrecv_cntx.recv_req_list;

    if (download_req_info_p)
    {
        if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING))
        {
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                   MMA_SENDRECV_termiante_all_requests2,
                                   "In mma_sendrecv_termiante_all_requests We already received mms.Don't cancel retrieve req\n"));
			mma_sendrecv_unset_flag(MMA_SENDRECV_IS_DOWNLOADING);
        }
		MMA_FREE(download_req_info_p);
		g_mma_sendrecv_cntx.recv_req_list = NULL;
    }
	if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION) == TRUE || mma_sendrecv_check_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION_MEM) == TRUE)
    {
        mma_sendrecv_unset_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION);
        mma_sendrecv_unset_flag(MMA_SENDRECV_IS_STORE_NOTIFICATION_MEM);
        mms_mma_send_mms_obj_rsp(
            g_mma_sendrecv_cntx.mms_obj_data->source,
            g_mma_sendrecv_cntx.mms_obj_data->app_id,
            g_mma_sendrecv_cntx.mms_obj_data->req_id,
            (kal_uint8) MMA_RESULT_FAIL_NOT_READY);
		MMA_FREE(g_mma_sendrecv_cntx.mms_obj_data);
	}
    g_mma_sendrecv_cntx.state = MMA_SENDRECV_STATE_STOPPED;
    MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_TERMINATE_IND);
}


#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_memory_card_plug_out_callback
 * DESCRIPTION
 *  Callback function for memory card plug out
 * PARAMETERS
 *  plugout_card        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_sendrecv_memory_card_plug_out_callback(kal_uint8 plugout_card)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sendrecv_req_info_list_struct *send_req_info_p = NULL;
    mma_sendrecv_req_info_list_struct *download_req_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Cancel memory card send request */
    send_req_info_p = g_mma_sendrecv_cntx.send_req_list;

    if (send_req_info_p)
    {
        if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_SENDING) && (mma_get_message_storage(send_req_info_p->msg_id) == MMA_MSG_STORAGE_CARD1))
        {
            if (g_mma_sendrecv_cntx.send_percent != 100)
            {
                MMSif_sendCancel(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(send_req_info_p->msg_id));
            }
        }
    }

    /* Cancel download request */
    download_req_info_p = g_mma_sendrecv_cntx.recv_req_list;

    if (download_req_info_p)
    {
        if (mma_sendrecv_check_flag(MMA_SENDRECV_IS_DOWNLOADING) && (mma_get_message_storage(download_req_info_p->msg_id) == MMA_MSG_STORAGE_CARD1))
        {
            if (g_mma_sendrecv_cntx.download_percent != 100)
            {
                MMSif_retrieveCancel(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(download_req_info_p->msg_id));
            }
        }
    }
}
#endif /*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_terminate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_sendrecv_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_terminate, "MMA SENDRECV terminate"));
    if (g_mma_sendrecv_cntx.state == MMA_SENDRECV_STATE_STOPPED)
    {
        memset(&g_mma_sendrecv_cntx, 0x00, sizeof(mma_sendrecv_context_struct));
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_sendrecv_memory_execp_terminate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_sendrecv_memory_execp_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SENDRECV_terminate, "MMA SENDRECV terminate"));
    g_mma_sendrecv_cntx.state = MMA_SENDRECV_STATE_STOPPED;
    memset(&g_mma_sendrecv_cntx, 0x00, sizeof(mma_sendrecv_context_struct));

    return KAL_TRUE;
}
#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_SENDRECV_C */ 

