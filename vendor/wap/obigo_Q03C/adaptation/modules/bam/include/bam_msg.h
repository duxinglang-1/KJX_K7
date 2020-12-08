#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_msg.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains function prototypes for external messages handling
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _bam_msg_h

#define _bam_msg_h

#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "bam_cfg.h"
#include "bam_struct.h"

#ifdef MTK_TMP_PATCH /* TR34746, TR34686: Loading large web page and MT call comes */
extern int bam_msg_get_num_of_msg_brw_task(void);
extern int bam_msg_get_max_num_of_msg_brw_task(void);
#endif /* MTK_TMP_PATCH */

extern int bam_handle_message(void *p);

extern void bam_msg_free_profile(void *p);

extern void bam_msg_ready_ind(void);

extern void bam_msg_create_instance_cnf(MSF_INT32 instance_id, MSF_INT16 error_code);

extern void bam_msg_delete_instance_cnf(MSF_INT32 instance_id);

extern void bam_msg_set_profile_cnf(MSF_INT32 instance_id, MSF_UINT8 request_id, MSF_UINT16 error_code);

#ifdef BAM_CFG_SHORTCUTS_ENABLED

extern void
bam_msg_change_setting_value_ind(
    MSF_INT32 instance_id,
    MSF_BOOL int_type,
    MSF_INT32 setting_id,
    MSF_INT32 value_i,
    const MSF_UINT8 *value_bv,
    MSF_INT32 value_bv_len);

#endif /* BAM_CFG_SHORTCUTS_ENABLED */

extern void bam_msg_status_ind(MSF_INT32 instance_id, void *p);

extern void bam_msg_external_object_status_ind(MSF_INT16 status, MSF_INT16 transaction_id);

extern void bam_msg_error_ind(MSF_INT32 instance_id, MSF_INT16 error_code);

extern void bam_msg_select_file_ind(MSF_INT16 instance_id, MSF_INT32 request_id);

extern void bam_msg_out_of_memory_ind(void);

extern void bam_msg_out_of_mem_wap_reset_ind(void);

extern void bam_msg_document_info_ind(MSF_INT32 instance_id, void *p);

extern void bam_msg_notify_app_ind(wap_bam_notify_app_enum type, void *p);

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
extern void bam_msg_do_elements_ind(MSF_INT32 instance_id, void *p);
#endif

extern void bam_msg_element_focused_ind(MSF_INT32 instance_id, void *p);

extern void bam_msg_set_sec_class_ind(MSF_INT32 instance_id, int sec_class);

extern void bam_msg_conn_closed_by_net_acc_id_rsp(void);

extern void
bam_msg_wait_user_action_ind(
    MSF_BOOL enable_positive_sk,
    const char *positive_label,
    MSF_INT32 positive_label_len,
    MSF_BOOL enable_negative_sk,
    const char *negative_label,
    MSF_INT32 negative_label_len);

extern void
bam_msg_show_auth_dialog_ind(
    MSF_INT32 request_id,
    MSF_INT32 auth_type,
    const char *realm,
    const char *username,
    const char *password);

extern void
bam_msg_wtai_tel_ind(
    MSF_UINT16 request_id,
	MSF_UINT16	operation,
    const char *param,
	MSF_INT32 param_len);

extern void
bam_msg_wtai_pb_ind(
    MSF_UINT16 request_id,
    const char *name,
    MSF_INT32 name_len,
    const char *number,
    MSF_INT32 number_len);

extern void
bam_msg_uri_request_ind(
    MSF_UINT16 request_id,
    const char *scheme,
	MSF_INT32 scheme_len,
    const char *param,
	MSF_INT32 param_len);

extern void bam_msg_get_saved_pages_list_start_cnf(MSF_UINT16 error_code, MSF_INT16 num_items);

extern void
bam_msg_get_saved_pages_list_continue_cnf(MSF_UINT16 error_code, MSF_UINT32 start_index, MSF_UINT32 num_items, void *p);

extern void bam_msg_get_resources_list_start_cnf(MSF_UINT16 error_code, MSF_INT16 num_res);

extern void
bam_msg_get_resources_list_continue_cnf(MSF_UINT16 error_code, MSF_UINT32 start_index, MSF_UINT32 num_res, void *p);
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
extern void bam_msg_get_recent_pages_list_start_cnf(MSF_UINT16 error_code, MSF_INT16 num_item);

extern void
bam_msg_get_recent_pages_list_continue_cnf(
    MSF_UINT16 error_code,
    MSF_UINT32 start_index,
    MSF_UINT32 num_items,
    void *p);

extern void bam_msg_recent_page_cnf(MSF_UINT32 error_code, void *p);

extern void bam_msg_save_page_cnf(MSF_UINT32 error_code, /*void *p*/char *title, char*url);
#endif /*recent pages */
extern void bam_msg_get_resource_cnf(MSF_UINT32 error_code, void *p);

extern void bam_msg_bearer_open_ind(MSF_INT32 instance_id);

#endif /* _bam_msg_h */


#endif /*OBIGO_Q03C_BROWSER*/
