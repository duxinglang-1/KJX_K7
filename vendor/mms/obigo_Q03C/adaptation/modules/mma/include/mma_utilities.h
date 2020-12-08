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
 *   mma_utilities.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file 
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _MMA_UTILITIES_H
#define _MMA_UTILITIES_H

#include "mma_def.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" 
#include "mma_api.h"
#include "mms_api.h"
#include "UmSrvDefs.h"


/************************************************************
 * Constants
 ************************************************************/
#define MMA_MAX_BUF_SIZE 1024   /* Must be divied by sizeof(MSF_UINT32 or kal_uint32) */
#define MMS_SYS_FOLDER "/mms_sys/"

#define MMS_SUFFIX_CHKSUM 'c'
#define MMS_MIN_CHECKSUM_FILE_SIZE 12

/**********************************************************************
 * Enum definitions
 **********************************************************************/
typedef enum
{
    MMA_ACTION_NONE = 0,         /* !< Start enum */
    MMA_ACTION_GET_MSG_INFO,               /* !< Get msg info */
    MMA_ACTION_DELETE_MSG,    /* !< Delete msg */
    MMA_ACTION_SAVE_MSG,    /* !< Save msg */
	/* below this have there own queue so not used */
    MMA_ACTION_CREATE_MSG,    /* !< Create msg */
    MMA_ACTION_DRMSRV_PROCESS,    /* !< Drmsrv process */
    MMA_ACTION_PARSE_MSG,    /* !< Parse msg */
	MMA_ACTION_MSGMGR_MSG_OPER,

    MMA_ACTION_TOTAL         /* !< end of enum */
} mma_queue_action_type_enum;


/**********************************************************************
 * Type definitions
 **********************************************************************/
typedef struct
{
    kal_uint32 task_id;
    kal_uint8 app_id;
    kal_uint8 req_id;
} mms_mma_generic_reply_result_struct;

extern void mms_mma_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id);
extern mma_result_enum mma_insert_node_to_queue(
                        mms_mma_queue_struct **queue_list,
                        kal_uint32 first_id,
                        kal_uint32 second_id,
                        void *data,
						mma_queue_action_type_enum action_type);
extern mms_mma_queue_struct *mma_remove_node_from_queue(
                                mms_mma_queue_struct **queue_list,
                                kal_uint32 first_id,
                                kal_uint32 second_id);
extern mms_mma_queue_struct *mma_get_node_from_queue(
                                mms_mma_queue_struct *queue_list,
                                kal_uint32 first_id,
                                kal_uint32 second_id);
extern kal_uint32 mma_count_node_in_queue(mms_mma_queue_struct *queue_list);
extern void mma_handle_wrapper_queue_next_call_based_on_action_type(void);

extern kal_uint64 mma_get_mms_avaliable_file_space(kal_uint32 *usedBytes, kal_uint8 storage);
extern srv_um_msg_box_enum mma_cvt_mma_folder_to_um_folder(mma_folder_enum folder_id);
extern mma_folder_enum mma_cvt_um_folder_to_mma_folder(kal_int32 folder);
extern kal_int32 mma_cvt_mma_folder_to_mms_folder(mma_folder_enum folder);
extern void *mma_mem_alloc(kal_uint32 size, kal_bool clear);
extern void *mma_mem_alloc_ext(kal_uint32 size, void*);
extern void mma_mem_free(void *ptr);
extern void mma_mem_free_ext(void *ptr, void*);

extern char *MMAlib_getMessageInfoPath(kal_uint32 msg_id);
extern char *MMAlib_getMessagePath(MSF_UINT8 mod_id, kal_uint32 msg_id);

extern char *mma_get_utf8_string(kal_uint8 modid, int string_id);
extern int mma_is_busy(kal_uint8 card_enum);
extern kal_bool mma_check_fs_is_busy(void);
extern kal_bool mma_um_is_restricted_type(mms_content_class_enum class, kal_int32 fh, const char *filename, const char* mime);
extern char *mma_um_ucs2_to_utf8_string(const kal_wchar *ucs2_str);

extern mma_result_enum mma_update_checksum_file(mma_msg_info_list_struct* checksumdata);
extern int mms_task_is_init(void);
extern int mms_task_is_ready(void);
extern kal_uint32 translate_mms_sim_to_mma_sim(kal_uint32 sim_id);
extern kal_uint32 translate_mma_sim_to_mms_sim(kal_uint32 sim_id);
extern void mma_reset_last_tick(void);
extern void mma_check_and_sleep(void);
extern msf_mms_storage_enum translate_mma_storage_to_mms_storage_enum(mma_msg_storage_type_enum storage);
extern mma_msg_storage_type_enum translate_mms_storage_to_mma_storage_enum(msf_mms_storage_enum storage);
extern kal_wchar *mms_get_file_extension(kal_wchar *file_path);
extern kal_uint8 translate_mms_rr_status_to_mma_status(kal_uint16 status);
extern kal_uint8 translate_mms_dr_status_to_mma_status(kal_uint16 status);
#endif /* _MMA_UTILITIES_H */ 

