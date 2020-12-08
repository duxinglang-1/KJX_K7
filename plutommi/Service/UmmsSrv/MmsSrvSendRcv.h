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
 *  MMSSrvSendRcv.h
 * 
 * Project:
 * --------
 *  MAUI
 * 
 * Description:
 * ------------
 *  This file contains declaration of APIs defined in MMSSendRcvSrv.c and definitions of 
 *  structures and unions used in MMSSendRcvSrv.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMSSRVSENDRECV_H
#define MMSSRVSENDRECV_H

#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "kal_general_types.h"
// #include "MmsSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__

#define   SRV_MMS_DEFAULT_FOLDER_NAME_SIM1        L"@mmsobject1"        /* should be consistent with the path defined in fs_quota.c file */
#define   SRV_MMS_DEFAULT_FOLDER_NAME_SIM2        L"@mmsobject2"        /* should be consistent with the path defined in fs_quota.c file */
#define   SRV_MMS_DEFAULT_OBJ_IND_FOLDER              L"@mmsobject"     /* should be consistent with the path defined in fs_quota.c file */

#define   SRV_MMS_FILE_EXT                         L".mms"
#define   SRV_MMS_SEARCH_FILE_EXT                  L"*.mms"
#define   MMI_UMMS_TIMER_VALUE                      (30000)

#define   SRV_MMS_DRIVE_NAME_LENGTH                5
#define   SRV_MMS_DEFAULT_SYS_DRIVE                SRV_FMGR_SYSTEM_DRV
#define   SRV_MMS_DEFAULT_PUBLIC_DRIVE             SRV_FMGR_PUBLIC_DRV
#define   UMMS_CONVERT_INDEX                10

#define   SRV_MMS_SHOW_FULL_POPUP_COUNT 60
#define    SRV_MMS_MAX_NUM_FULL_POPUP   48
#define    SRV_MMS_OBJ_FILE_PATH_LEN    35      /* Do not define this length more than 35 */
#define    SRV_MMS_OBJ_FILE_NAME_LEN    15      /* Do not define this length more than 15 */

#define SRV_MMS_PREFIX_SIM1 L"1"
#define SRV_MMS_PREFIX_SIM2 L"2"
#define SRV_MMS_PREFIX_SIM3 L"3"
#define SRV_MMS_PREFIX_SIM4 L"4"

typedef enum
{
    SRV_MMS_OBJ_STATE_NORMAL,
    SRV_MMS_OBJ_STATE_BUSY,
    SRV_MMS_OBJ_STATE_MAX
} srv_mms_obj_state;

typedef enum
{
    SRV_MMS_DRV_SYS,
    SRV_MMS_DRV_PUBLIC,
    SRV_MMS_DRV_MAX
} srv_mms_drv_type;

typedef enum
{
    SRV_MMS_FILE_TYPE_NOTIFICATION,
    SRV_MMS_FILE_TYPE_DELIVERY_REPORT,
    SRV_MMS_FILE_TYPE_READ_REPORT,
    SRV_MMS_FILE_TYPE_NORMAL_MMS,
    SRV_MMS_FILE_TYPE_MAX
} srv_mms_file_type;

typedef struct _srv_mms_notification_list
{
    U8 file_name[(UMMS_CONVERT_INDEX *ENCODING_LENGTH + 1) *ENCODING_LENGTH];
    srv_mms_file_type file_type;
    U8 sim_id;
    struct _srv_mms_notification_list *next;
    U16 filename_int;
} srv_mms_notification_list;

typedef struct
{
    U16 next_push;
    U8 count;
} srv_mms_push_struct;
typedef struct _srv_mms_notification_struct
{
    //U32 sys_file_count;       /* For File Name generation in System Drive */
    //U32 public_file_count;    /* For File Name generation in Public Drive */
    U8 sim_id;
    U8 in_process_sim_id;
    srv_mms_file_type file_type;
    srv_mms_obj_state state;
    U16 filename_int;
    U16 in_process_filename_int;
    srv_mms_push_struct sim_push;
    U8 default_sys_folder_path[(SRV_MMS_OBJ_FILE_PATH_LEN + 1) *ENCODING_LENGTH];
    U8 default_public_folder_path[(SRV_MMS_OBJ_FILE_PATH_LEN + 1) *ENCODING_LENGTH];
    /* U8 current_file_path[((SRV_FMGR_PATH_MAX_LEN+1) + 1) *ENCODING_LENGTH]; */
    U8 unique_file_name[(SRV_MMS_OBJ_FILE_NAME_LEN + 1) *ENCODING_LENGTH];

} srv_mms_notification_struct;

#endif /* __MMI_MMS_MMA_MMS_OBJECT_IND__ */ 

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
/* extern void srv_mms_object_indication_rsp_callback(srv_mms_result_enum srv_result, void *rsp_data, S32 user_data); */
extern void srv_mms_handle_mms_file(
                S32 session_id,
                S32 mime_type,
                S32 mime_subtype,
                S32 action_type,
                PU16 filename,
                PS8 download_url,
                PS8 mime_type_str_string);
extern void srv_mms_save_mms_to_drv(PU16 filename, int drv_type);
extern void srv_mms_generate_file_path(int drv_type, U8 sim_id);
extern void srv_mms_generate_unique_file_name(int drv_type);
extern void srv_mms_save_object_rsp(void *info);
extern void srv_mms_enqueue_in_object_list(void);
extern void srv_mms_free_object_handler_node(void);

extern void srv_mms_handle_obj_timer_expiry(void);
extern void srv_mms_read_noti_file_frm_sys_drv(U8 sim_id);
extern void srv_mms_get_file_name_and_add_to_list(U8 filename[], U8 sim_id);
extern U8 srv_mms_get_int_file_name(U8 filename[]);
extern srv_mms_file_type srv_mms_get_file_type(U8 filename[]);
extern void mmi_update_sim_push_info(U8 sim_id);

#endif /* __MMI_MMS_MMA_MMS_OBJECT_IND__ */ 

#ifndef __MMI_MMS_BGSR_SUPPORT__
extern umms_state_enum srv_mms_get_intermediate_state_by_old_msg_id(U32 msg_id);
extern void srv_mms_check_sending_state_of_all_and_update_state(void);
extern kal_bool srv_mms_check_if_more_mms_is_in_send_state(void);
extern void srv_mms_free_download_list_msg_id(U32 msg_id);
extern void umms_add_to_download_msg_hndlr_list(
                const U32 msg_id,
                const U32 req_id,
                const umms_state_enum current_state,
                const umms_state_enum intermediate_state);
extern void srv_mms_add_to_new_msg_list(U32 msg_id);
extern void srv_mms_free_new_msg_handler_list(U32 msg_id);
extern MMI_BOOL srv_mms_is_in_download_list(U32 msg_id);
extern void umms_add_to_send_msg_hndlr_list(
                const U32 msg_id,
                const U32 req_id,
                const umms_state_enum current_state,
                const umms_state_enum intermediate_state,
                const mma_folder_enum folder_id);
extern void srv_mms_update_intermediate_send_cancel_req(const U32 msg_id, const U32 req_id);
extern void srv_mms_update_intermediate_send_req(
                const U32 msg_id,
                const U32 req_id,
                const umms_state_enum intermediate_state);
extern void srv_mms_update_send_hdnlr_with_new_msg_id(
                const U32 msg_id,
                const U32 req_id,
                const umms_state_enum intermediate_state);
extern U32 srv_mms_get_old_msg_id_from_send_handler(U32 req_id);
extern void srv_mms_update_retry_send_req(
                const U32 msg_id,
                const U32 req_id,
                const U32 new_req_id,
                const umms_state_enum intermediate_state);
extern umms_state_enum srv_mms_get_intermediate_state_of_msg_from_send_list(const U32 msg_id);
extern umms_state_enum srv_mms_get_state_of_msg_from_send_list(const U32 msg_id);
extern umms_state_enum srv_mms_get_state_of_msg_from_download_list(const U32 msg_id, const U32 req_id);
extern umms_state_enum srv_mms_get_intermediate_state_from_downl_list(const U32 msg_id);
extern void srv_mms_update_send_msg_handler(
                const umms_state_enum updated_state,
                const U32 msg_id,
                const mmi_enum_retry_send_verion_enum retry_send_version,
                const U32 retry_version_count);
extern mmi_enum_retry_send_verion_enum srv_mms_get_send_version_number(const U32 msg_id);
extern U32 srv_mms_get_send_version_count(U32 msg_id);
extern void srv_mms_update_download_msg_hndlr(const U32 msg_id, const U32 req_id, const umms_state_enum updated_state);
extern umms_state_enum srv_mms_get_current_state_of_download(U32 msg_id);
extern void srv_mms_update_download_msg_hndlr_with_percent_val(
                const U32 msg_id,
                const U32 req_id,
                const U32 percent_val);
extern U32 srv_mms_get_percent_val_from_download_list(U32 msg_id);
extern void srv_mms_free_req_node(const U32 msg_id, const U32 req_id);
extern void mmi_uc_cancel_download_mms_by_end_key(void);
extern kal_bool srv_mms_get_send_and_save_state(const U32 msg_id);
extern mma_folder_enum srv_mms_get_folder_id_from_send_list(const U32 msg_id);
extern kal_bool srv_mms_change_version_number_of_mms(const U8 *xml_file_path);
extern void srv_mms_free_send_handler_node(const U32 msg_id, const U32 req_id);
extern void srv_mms_free_send_node_with_msg_id(U32 msg_id);
extern void srv_mms_free_download_handler_node(const U32 msg_id, const U32 req_id);
extern void srv_mms_update_more_flag_for_send(const U32 req_id, const kal_bool is_more);
extern U32 srv_mms_get_highlight_index_from_send_hndlr_node(const U32 msg_id);
extern kal_bool srv_mms_get_more_flag_from_send_list(const U32 req_id);
extern void srv_mms_update_xml_file_path_in_send_msg_hndlr(const U32 req_id, const U8 *xml_file_path);
extern U8 *srv_mms_get_xml_file_path_from_send_msg_hndlr(const U32 msg_id);
extern void srv_mms_de_init_send_handler_list(void);
extern void srv_mms_de_init_dwnld_handler_list(void);
extern void srv_mms_de_init_new_msg_handler_list(void);
extern void srv_mms_reset_all_except_new_msg_node_frm_req_hndlr(void);
extern void srv_mms_check_new_mms_list_and_show_new_mms_pop_up(void);
extern void srv_mms_entry_send_rr_confirmation(void);
extern void srv_mms_send_read_report_for_delete_mms(void);
extern void srv_mms_check_sending_state(const U32 msg_id, const mma_folder_enum folder_id);
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 
extern void srv_mms_inform_um_about_new_msg_ind(U32 msg_id, U32 received_date, U32 Date, U8 sim_id);

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
extern void srv_mms_init_object_ind_data(void);
extern void srv_mms_send_object_indication(void);
extern srv_mms_notification_list *srv_mms_obj_ind_get_node_to_process(void);
extern void srv_mms_obj_ind_set_in_process_sim_id(U8 sim_id);
extern U8 srv_mms_obj_ind_get_in_process_filename_int(void);
extern void srv_mms_obj_ind_set_in_process_filename_int(U16 in_process_filename_int);
extern MMI_BOOL srv_mms_obj_ind_delete_node_and_file(U16 filename_int, U8 sim_id);
extern U8 srv_mms_obj_ind_get_in_process_sim_id(void);
extern void srv_mms_init_object_ind_sim_data(U8 sim_id);
extern void srv_mms_init_push_info(U8 sim_id);
extern void srv_mms_set_object_indication_state_as_busy(void);
extern void srv_mms_unset_object_indication_state(void);
extern void srv_mms_get_obj_file_path(U8 *complete_file_path, srv_mms_notification_list *node);
extern void srv_mms_check_and_send_object_req(void);
extern void srv_mms_start_object_indication_timer(void);
extern void srv_mms_stop_object_indication_timer(void);
extern U16 srv_mms_get_full_ind_counter(void);
extern MMI_BOOL srv_mms_get_obj_ind_flag(void);
extern void srv_mms_set_obj_ind_flag(MMI_BOOL flag);
#endif /* __MMI_MMS_MMA_MMS_OBJECT_IND__ */ 

#endif /* __MMI_MMS_2__ */ 
#endif /* MMSSRVSENDRECV_H */ /* UMMSAPPSENDRECV_H */

