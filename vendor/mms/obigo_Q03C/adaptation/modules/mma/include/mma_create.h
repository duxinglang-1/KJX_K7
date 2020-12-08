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
 *   mma_create.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains function prototypes, constant/macro/structure definition 
 *   for MMS creation functionality
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMA_CREATE_H
#define _MMA_CREATE_H

#include "MMI_features.h"
#include "kal_general_types.h"
#include "mma_api.h"
#include "mma_msg_struct.h"

typedef enum
{
    MMA_CREATE_ENV_STATE_ACTIVE,
    MMA_CREATE_ENV_STATE_ENTERING_USB,
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    MMA_CREATE_ENV_STATE_MEM_CARD_PLUG_OUT,
#endif
    MMA_CREATE_ENV_STATE_TERMINATING,
    MMA_CREATE_ENV_STATE_TERMINATED
} mma_create_env_state_enum;

typedef enum
{
    MMA_CREATE_STATE_STARTED,                   /* 0 */
    MMA_CREATE_STATE_MMS_INFO_VALIDATING = 1,
	    MMA_CREATE_STATE_XML_PARSING,               /* 2 */

    MMA_CREATE_STATE_CREATION_PREPROCESSING,    /* 3 */
    MMA_CREATE_STATE_CREATING,                  /* 4 */

    MMA_CREATE_STATE_UPLOADED_MMS_RENAMING, /* 5 */

    MMA_CREATE_STATE_OLD_MMS_INFO_GETTING,  /* 6 */

    MMA_CREATE_STATE_OLD_MMS_HEADER_PARSING,        /* 7 */
    MMA_CREATE_STATE_OLD_MMS_BODY_HEADER_PARSING,   /* 8 */

    MMA_CREATE_STATE_MMS_HEADER_CREATING,   /* 9 */
    MMA_CREATE_STATE_MMS_BODY_COPYING,      /* 10 */
    MMA_CREATE_STATE_MMS_SMIL_CREATING,     /* 11 */
    MMA_CREATE_STATE_MMS_BODY_CREATING,     /* 12 */
    MMA_CREATE_STATE_MMS_INFO_CREATING,     /* 13 */
    MMA_CREATE_STATE_INT_NOTIFY,            /* 14 */
    MMA_CREATE_STATE_FINISHING,             /* 15 */
    MMA_CREATE_STATE_FINISHED               /* 16 */
} mma_create_state_enum;

typedef enum
{
    MMA_CREATE_ACTION_NONE,
    MMA_CREATE_ACTION_CONTINUE,
    MMA_CREATE_ACTION_DELAYED
} mma_create_action_enum;

typedef struct
{
    /* refer to wap_mma_create_req_struct */
    kal_uint32 source;
    kal_uint32 app_id;
    kal_uint32 req_id;

    /* refer to wap_mma_create_req_struct */
    char *upload_filepath;  /* upload */

    kal_uint32 o_msg_id;    /* send / forward */
    kal_uint32 xml_size;
    kal_wchar *xml_filepath;
    kal_uint32 buffer_index;
    MSF_BOOL encode_msg;
    /* FSM context */
    kal_uint32 msg_id;
    mma_header_struct *header;
  //  mma_body_struct *body;
    SlsRootLayout root_layout;
	mma_mms_description_struct *mms_dsr;	/*replace ment of XML and used during MMS create parse process in Mma create/parse fsm : chetan*/
    MmsMsgHandle m_handle;  /* MmsMessage */
    MmsTransactionHandle t_handle;
    MmsGetHeader *o_header; /* send / forward */
    MmsBodyInfoList *o_body_header;
    kal_int32 r_handle;     /* file handle for read operation */
    kal_int32 w_handle;     /* file handle for write operation */
    kal_uint32 r_byte;      /* byte number which has been read */
    kal_uint32 w_byte;      /* byte number which has been written */

    kal_char *mo_buffer;        /* For MMSlib_setMessageBody() delayed operation */
    kal_uint32 mo_buffer_size;  /* For MMSlib_setMessageBody() delayed operation */
    MmsBodyParams *mo_param;    /* For MMSlib_setMessageBody() delayed operation */
    kal_int32 delayed_handle;   /* file handle for delayed operation */
    mma_app_mode_enum mode;
    kal_bool more;
    MmsFileType msg_filetype;
    mma_create_state_enum state;
    kal_uint32 sub_state;
    mma_result_enum input;
    mma_result_enum result;

    mma_msg_state_enum msg_state;   /* so that we don't forget to close it */
    kal_uint8 delete_state;
    kal_uint8 storage_type;
} mma_create_info_struct;

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__ 
typedef struct
{
    /* intermediate info during parsing */
    mma_mms_slide_struct *slide;    /* current slide */
    mma_mms_object_struct *object;  /* current object */

    /* parsed info */
    mma_create_info_struct *info;
    MmsAddressType addr_type;
} mma_xml_parser_info_struct;

#endif
typedef struct
{
    /* create task queue */
    mms_mma_queue_struct *mma_create_task_queue;
    /* Env State */
    mma_create_env_state_enum mma_create_env_state;
} mma_create_context_struct;

/* Function prototype */
extern kal_bool mma_create_init(void);
extern kal_bool mma_create_terminate(void);
extern void mma_create_process_int_sig(mma_signal_struct *sig);
extern kal_bool mma_create_handle_rsp(MSF_UINT16 sig, void *sig_data);
extern void mma_create_fsm_hdlr(MSF_UINT32 req_id);

extern mms_mma_queue_struct *mma_create_get_active_task(void);
extern kal_bool mma_create_send_reject_rsp(
                    kal_uint32 source,
                    kal_uint32 req_id,
                    kal_uint8 app_id,
                    kal_uint32 msg_id,
                    kal_uint32 buffer_index,
                    mma_result_enum ret);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void mma_create_memory_card_plug_out_callback(kal_uint8 plugout_card);
#endif
extern kal_bool mma_create_is_busy_on_storage(kal_uint8 card_enum);
extern void mma_create_process_mms_info(mma_create_info_struct *info);

#endif /* _MMA_CREATE_H */ 

