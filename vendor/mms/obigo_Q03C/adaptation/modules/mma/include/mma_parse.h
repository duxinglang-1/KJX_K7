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
 *   mma_parse.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains function prototypes, constant/macro/structure definition 
 *   for MMS parsing functionality
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMA_PARSE_H
#define _MMA_PARSE_H

#include "MMI_features.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" 
#include "mma_def.h"
#include "mmsadp.h"
#include "mma_api.h"
#include "mma_struct.h"

typedef enum
{
    MMA_PARSE_ENV_STATE_ACTIVE,
    MMA_PARSE_ENV_STATE_ENTERING_USB,
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    MMA_PARSE_ENV_STATE_MEM_CARD_PLUG_OUT,
#endif
    MMA_PARSE_ENV_STATE_WAITING_SLS_TO_TERMINATE,
    MMA_PARSE_ENV_STATE_TERMINATING,
    MMA_PARSE_ENV_STATE_TERMINATED
} mma_parse_env_state_enum;

typedef enum
{
    MMA_PARSE_STATE_STARTED,
    MMA_PARSE_STATE_ASM_MEM_REQUEST,
	MMA_PARSE_STATE_PREPARE_SMIL_PRSE_INFO,
    MMA_PARSE_STATE_MMS_INFO_GETTING,
    MMA_PARSE_STATE_MMS_HEADER_PARSING,
    MMA_PARSE_STATE_MMS_OPENING,
    MMA_PARSE_STATE_MMS_BODY_HEADER_PARSING,
    MMA_PARSE_STATE_MMS_BODY_HEADER_PARSED,
    MMA_PARSE_STATE_MMS_BODY_HEADER_PROCESSING_LOOP,
    MMA_PARSE_STATE_SLS_ACTIVATING,
    MMA_PARSE_STATE_SMIL_OPENING,
    MMA_PARSE_STATE_SLIDE_CONTENT_PARSING,
    MMA_PARSE_STATE_SLIDE_CONTENT_DONE,
    MMA_PARSE_STATE_SLS_DEACTIVATING,
    MMA_PARSE_STATE_SLS_DEACTIVATED,
    MMA_PARSE_STATE_SMIL_ADDING,
    MMA_PARSE_STATE_SMIL_PARSING,
    MMA_PARSE_STATE_SETTLE_ATTACHMENT,
    MMA_PARSE_STATE_GENERATE_SLIDE_INFO,
	MMA_PARSE_STATE_SMIL_PARSING_DONE,
	MMA_PARSE_STATE_APP_MMS_HEADER_CREATING,/* MMA_PARSE_STATE_XML_CREATING*/
    MMA_PARSE_STATE_FINISHING,
    MMA_PARSE_STATE_FINISHED
} mma_parse_state_enum;


typedef enum
{
    MMA_PARSE_ACTION_NONE,
    MMA_PARSE_ACTION_CONTINUE,
    MMA_PARSE_ACTION_DELAYED
} mma_parse_action_enum;

typedef struct
{
    /* refer to wap_mma_get_content_req_struct */
    kal_uint32 source;
    kal_uint32 app_id;
    kal_uint32 req_id;

    kal_uint32 msg_id;
    MmsFileType suffix;
    mma_app_mode_enum mode;
	mma_msg_type_enum msg_type;
    mma_creation_mode_enum creation_mode;
    kal_uint32 msg_size;
    kal_uint32 header_size;
    kal_uint32 body_size;
    kal_uint32 user_elements_size;
    kal_uint32 xml_size;
    kal_wchar *xml_filepath;
   // kal_uint32 buffer_index;
	MmsContentType *content_type;

    /* FSM context */
    mma_header_struct *header;
    MmsBodyInfoList *body_header;
    //mma_body_struct *body;
	mma_mms_description_struct *mms_dsr;
	SlsRootLayout root_layout;
    //mma_sls_region_list *regions;   
    MmsTransactionHandle t_handle;
    MmsMsgHandle m_handle;  /* MmsMessage */

    mma_parse_state_enum state;
    mma_result_enum input;      /* MMSif function result */
    mma_result_enum result;     /* final result */
    kal_int32 delayed_handle;   /* file handle for delayed operation */
    kal_uint8 sub_state;
    kal_uint8 delete_state;

    MmsBodyInfoList *curr;  /* current processing body_header entry */
    kal_uint8 *parse_buf;
    kal_int32 w_handle;
    kal_uint32 parse_buf_size;
    kal_uint32 parse_buf_offset;
    kal_uint32 current_xml_obj;
    kal_uint32 current_slide_num;
    kal_uint8 ref_attach_count;
    kal_uint8 content_truncate_info;
    kal_uint8 storage_type;   /*Can be removed */
    mma_mms_object_struct *text_obj;
	mma_mms_object_struct *thmubnail_txt_obj;
    mms_msg_body_object_info_struct *thumbnail;
#ifdef __MMI_MMS_POSTCARD__
    kal_uint8 *postcard_subject;
    kal_uint8 *postcard_recipient;
#endif
	/*smil parsing context*/
	InstanceData ctx;
} mma_parse_info_struct;

typedef struct
{
 
    /* Parse task queue */
    mms_mma_queue_struct *mma_parse_task_queue;
#ifdef __MMI_MMS_USE_ASM__
    wap_mma_get_content_rsp_struct* rsp_data;
#endif
	   /* Env State */
    mma_parse_env_state_enum mma_parse_env_state;
} mma_parse_context_struct;

/* Function prototype */
extern kal_bool mma_parse_init(void);
extern kal_bool mma_parse_terminate(void);
extern void mma_parse_process_int_sig(mma_signal_struct *sig);
extern void mms_mma_get_content_req_hdlr(module_type source, wap_mma_get_content_req_struct *p);
extern kal_bool mma_parse_handle_rsp(MSF_UINT16 sig, void *sig_data);
extern void mma_parse_fsm_hdlr(MSF_UINT32 req_id);
extern mms_mma_queue_struct *mma_parse_get_active_task(void);
extern mms_mma_queue_struct *mma_parse_get_task_by_msg(kal_uint32 msg_id);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void mma_parse_memory_card_plug_out_callback(kal_uint8 plugout_card);
#endif
extern kal_bool mma_parse_is_busy_on_storage(kal_uint8 card_enum);
extern void mma_parse_check_and_correct_filename(mma_mms_object_struct *obj);
extern void mma_parse_send_direct_rsp(MSF_UINT32 source, MSF_UINT32 req_id, MSF_UINT8 app_id, 
							   MSF_UINT32 msg_id, mma_app_mode_enum mode, /*MSF_UINT32 buffer_index,*/ mma_result_enum ret);

#endif /* _MMA_PARSE_H */ 

