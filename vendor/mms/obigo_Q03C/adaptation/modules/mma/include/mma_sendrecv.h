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
 * mma_sendrecv.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions definitions and functions used by MMA sendrecv submodule.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_SENDRECV_H
#define _MMA_SENDRECV_H
    
#include "MMI_features.h"
#include "kal_public_defs.h" 
#include "kal_general_types.h"
#include "mma_api.h"

typedef enum
{
    MMA_SENDRECV_STATE_STOPPED,
    MMA_SENDRECV_STATE_STARTED,
    MMA_SENDRECV_STATE_STOPPING
} mma_sendrecv_state_enum;

typedef enum
{
    MMA_SENDRECV_IS_SENDING = 0x01,
    MMA_SENDRECV_IS_DOWNLOADING = 0x02,
    MMA_SENDRECV_IS_SENDING_CANCELLED = 0x04,
    MMA_SENDRECV_IS_DOWNLOADING_CANCELLED = 0x08,
    MMA_SENDRECV_IS_STORE_NOTIFICATION = 0x10,
    MMA_SENDRECV_IS_STORE_NOTIFICATION_MEM = 0x20
} mma_sendrecv_flag_enum;

typedef struct mma_sendrecv_req_info_list_st
{
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint32 result;  /* For error code in USB mode */
    struct mma_sendrecv_req_info_list_st *next;
    module_type source;
    kal_bool is_read_report;
    kal_uint8 app_id;
    kal_uint8 sim_id;
    kal_uint8 storage_type;
} mma_sendrecv_req_info_list_struct;

typedef struct mma_sendrecv_mms_obj_info_st
{
    kal_uint32 req_id;
    module_type source;
    kal_uint8 app_id;
} mma_sendrecv_mms_obj_info_struct;

typedef struct
{
    kal_uint32 download_progress;
    kal_uint32 state;
    MSF_UINT32 rr_id;   /* read report id */
    kal_char *retrieve_txt;
    mma_sendrecv_req_info_list_struct *send_req_list;
    mma_sendrecv_req_info_list_struct *recv_req_list;
    mma_sendrecv_mms_obj_info_struct *mms_obj_data;
    kal_uint8 download_percent;
    kal_uint8 send_percent;
    kal_uint8 download_prv_percent;
    kal_uint8 download_ind;
    kal_uint8 flag;
} mma_sendrecv_context_struct;

extern void mma_sendrecv_process_int_sig(mma_signal_struct *sig);
extern kal_bool mma_sendrecv_init(void);
extern kal_bool mma_sendrecv_terminate(void);
extern mma_sendrecv_context_struct *mma_sendrecv_get_cntx(void);
extern mma_sendrecv_req_info_list_struct *mma_sendrecv_get_recv_req_list(void);
extern mma_sendrecv_req_info_list_struct *mma_sendrecv_get_send_req_list(void);
extern mma_sendrecv_req_info_list_struct *mma_sendrecv_get_req_from_queue(
                                            mma_sendrecv_req_info_list_struct *queue,
                                            MSF_UINT32 msg_id);
extern MSF_BOOL mma_sendrecv_is_busy(mma_msg_storage_type_enum storage_type);
extern void mma_sendrecv_download_rsp_hdlr(kal_uint32 msgId, MmsResult download_result, char *retrieve_txt);
extern void mma_sendrecv_msgmgr_download_rsp_hdlr(MmsResult download_result, kal_uint32 new_msg_id);
extern kal_uint32 mma_sendrecv_get_sending_msgid(void);
extern kal_bool mma_sendrecv_is_sending(kal_uint32 msg_id);
extern kal_bool mma_sendrecv_is_downloading(kal_uint32 msg_id);
extern void mma_sendrecv_remove_pending_send_nodes(void);
extern void mma_sendrecv_remove_pending_download_nodes(void);
extern kal_bool mma_sendrecv_remove_single_pending_send_node(kal_uint32 msg_id);
extern kal_bool mma_sendrecv_remove_single_pending_download_node(kal_uint32 msg_id);
extern MSF_BOOL mma_sendrecv_handle_rsp(MSF_UINT16 sig, void *sigData);
extern kal_bool mma_sendrecv_memory_execp_terminate(void);
extern void mma_sendrecv_resume_mms_service(kal_uint8 sim_id);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void mma_sendrecv_memory_card_plug_out_callback(kal_uint8 plugout_card);
#endif
#endif /* _MMA_SENDRECV_H */ 

