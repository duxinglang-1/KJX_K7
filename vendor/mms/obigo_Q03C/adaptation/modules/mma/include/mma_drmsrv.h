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
 *   mma_drmsrv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions definitions and functions used by MMA DRMSRV submodule.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMA_DRMSRV_H
#define _MMA_DRMSRV_H

#include "MMI_features.h"
#ifdef __MMI_MMS_MMA_DRM_ENCODING__

#include "kal_general_types.h"
#include "mma_api.h"
/************************************************************
 * Constants
 ************************************************************/

/**********************************************************************
 * Type definitions
 **********************************************************************/
typedef enum
{
    MMA_DRMSRV_ENV_STATE_ACTIVE,
    MMA_DRMSRV_ENV_STATE_ENTERING_USB,
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    MMA_DRMSRV_ENV_STATE_MEM_CARD_PLUG_OUT,
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    MMA_DRMSRV_ENV_STATE_TERMINATING,
    MMA_DRMSRV_ENV_STATE_TERMINATED
} mma_drmsrv_env_state_enum;

typedef enum
{
    MMA_DRMSRV_STATE_IDLE,
    MMA_DRMSRV_STATE_GETTING_MSG_INFO,
    MMA_DRMSRV_STATE_MMS_HEADER_PARSING,
    MMA_DRMSRV_STATE_GETTING_MMS_HEADER,
    MMA_DRMSRV_STATE_GETTING_MMS_BODY_HEADER,
    MMA_DRMSRV_STATE_CHECK_MMS_OBJ_DRM_TYPE,
    MMA_DRMSRV_STATE_COPY_MMS_CONTENT,
    MMA_DRMSRV_STATE_SET_DRM_OBJ_HEADER,
    MMA_DRMSRV_STATE_ENCODING_DRM_OBJ,
    MMA_DRMSRV_STATE_FINISHING
} mma_drmsrv_state_enum;

typedef enum
{
    MMA_DRMSRV_ACTION_NONE,
    MMA_DRMSRV_ACTION_CONTINUE,
    MMA_DRMSRV_ACTION_DELAYED
} mma_drmsrv_action_enum;

typedef struct mma_drmsrv_FL_CD_obj_struct_st
{
    kal_uint32 header_startpos;
    MmsBodyInfoList *object;
    struct mma_drmsrv_FL_CD_obj_struct_st *next;
} mma_drmsrv_FL_CD_obj_struct;

typedef struct
{
    kal_uint32 req_id;              /* id of the encode request */
    kal_uint32 o_msg_id;            /* Original message id */
    kal_int32 r_handle;             /* Reading file handle */
    kal_int32 w_handle;             /* Writing file handle */
    kal_uint32 r_byte;              /* Reading bytes */
    kal_uint32 w_byte;              /* Writing bytes */
    kal_uint32 r_offset;
    kal_uint32 w_offset;
    kal_int32 delayed_handle;       /* Delayed file handle */
    kal_uint32 copy_buffer_size;
    kal_uint32 header_size;
    kal_uint32 body_size;
    kal_uint32 predict_encoded_size;
    kal_uint32 new_obj_header_size;
    kal_uint8 sub_state;
    kal_uint8 encode_obj_num;
    MmsFileType o_msg_suffix;
    mma_drmsrv_state_enum state;    /* State of MMA DRMSRV */
    mma_result_enum result;
    mma_msg_state_enum msg_state;   /* State of the message */
    char *new_msg_filepath;         /* Path of the new message */
    MmsBodyInfoList *body_header;   /* Body of the message */
    mma_header_struct *header;
    mma_drmsrv_FL_CD_obj_struct *FL_CD_obj;
    kal_uint8 *copy_buffer;
    MmsTransactionHandle t_handle;
    MmsMsgHandle m_handle;          /* MmsMessage */
    mma_result_enum input;          /* MMSif function result */
    kal_uint32 user_elements_size;
    kal_uint8 storage_type;
} mma_drmsrv_info_struct;

typedef struct
{
    mms_mma_queue_struct *task_queue;
    mma_drmsrv_env_state_enum env_state;

} mma_drmsrv_context_struct;

extern kal_bool mma_drmsrv_init(void);
extern kal_bool mma_drmsrv_terminate(void);
extern mms_mma_queue_struct *mma_drmsrv_get_active_task(void);
extern void mma_drmsrv_process_int_sig(mma_signal_struct *sig);
extern kal_bool mma_drmsrv_handle_rsp(kal_uint16 sig, void *sigData);
extern void mma_drmsrv_fsm_hdlr(kal_uint32 req_id);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void mma_drmsrv_memory_card_plug_out_callback(kal_uint8 plugout_card);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
extern kal_bool mma_drmsrv_is_busy_on_storage(kal_uint8 card_enum);

#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
#endif /* _MMA_DRMSRV_H */
