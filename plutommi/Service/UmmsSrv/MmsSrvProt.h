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

/*******************************************************************************
 * Filename:
 * ---------
 * MmsSrvProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_SRV_PROT_H
#define MMS_SRV_PROT_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "kal_general_types.h"

// #include "MMSMsgCommonProt.h"

/* #include "WAPProfileGProt.h" */
#include "WAPProfileSrvType.h"
#include "WAPprovisioningSrvType.h"
 
#include "mma_struct.h"
#include "MMIDataType.h"
#include "MmsSrvGprot.h"
#include "fs_type.h"
#include "UmSrvDefs.h"
#include "mma_api.h"
#include "FileMgrSrvGProt.h"
#include "MmsXMLDefSrv.h"
#include "kal_public_defs.h" 

#define SRV_MMS_MAX_PROCESS_NUM 10
#define SRV_MMS_MAX_BUFFER_SIZE 2000

#define        SRV_MMS_CONVERT_INDEX           10

#ifdef __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__
#define         SRV_MMS_STOP_CORRUPT_DWNLD       0x0B
#define         SRV_MMS_STOP_UNRECONIZED_NOTIFICATION       0x0C
#endif /* __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__ */ 

#ifdef __MMI_MMS_URI_AGENT__
#define MMI_UMMS_MMS_TO_URI     "mmsto"
#define MMI_TO_UMMS_MMS_TO_URI  "mms"
#endif /* __MMI_MMS_URI_AGENT__ */ 

#define SRV_UC_MAX_TEMP_FILE_LEN ((25 + 1) * ENCODING_LENGTH)

typedef enum
{
    SRV_MMS_BGSR_RSP_TYPE_NONE,
    SRV_MMS_BGSR_RSP_TYPE_DOWNLOAD,
    SRV_MMS_BGSR_RSP_TYPE_CANCEL_DOWNLOAD,
    SRV_MMS_BGSR_RSP_TYPE_SEND,
    SRV_MMS_BGSR_RSP_TYPE_CANCEL_SEND,
    SRV_MMS_BGSR_RSP_TYPE_TOTAL
} srv_mms_bgsr_rsp_type_enum;

/**********************************************************************
 * Structure definitions
 **********************************************************************/

/* This structure defines the single process information */
typedef struct __srv_mms_process_data_struct
{
    U32 req_id;                                 /* request ID to async requests */
    void *user_data;                            /* service will save this data and will return in callback */
    srv_mms_funcptr_type call_back;             /* Callback API which service will use to response back to caller Application */
    void *result;                               /* Pointer to struct of response that will be sent to caller Application */
    void *cntx;                                 /* Pointer to struct of context structure that will have process specific context */
    U32 app_id;                                 /* Caller Application ID */
    struct __srv_mms_process_data_struct *next; /* MAUI_02142001 */
} srv_mms_process_data_struct;

/* This structure defines the All process information */
typedef struct
{
    srv_mms_process_data_struct *mms_process_tbl /* [SRV_MMS_MAX_PROCESS_NUM] */ ;      /* MAUI_02142001  *//* Instances of various processes */
    MMI_BOOL is_srv_ready;  /* To check if service is ready or not */
} srv_mms_cntx_struct;

typedef struct
{
    FS_HANDLE fh;
    U32 xml_size;                                       /* Size of the XML file */
    U32 msg_id;
    U16 xml_filepath[MMA_MAX_INTERNAL_FILENAME_LENGTH]; /* MMA_MAX_INTERNAL_FILENAME_LENGTH, Specify file path of XML file */
    U8 mode;                                            /* mma_app_mode_enum */
    U8 sim_id;                                          /* mma_sim_id_enum */
    U8 op_type;                                         /* srv_mms_create_op_type_enum */
} srv_mms_create_cntx_struct;

typedef struct
{
    U8 mode;            /* mma_app_mode_enum, Content request mode */
    U8 creation_mode;   /* mma_creation_mode_enum, Creation mode to filter content. */
} srv_mms_get_content_cntx_struct;

/* rajbir    */
typedef struct
{
    U8 tone_id;
    U8 sim_id_for_new_msg;
    BOOL nmgr_informed;
    BOOL is_new_msg;
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    U8 tone_id_for_report;
    U8 sim_id_for_new_report;
    BOOL is_new_report;
    U8 msg_type;
    U8 from_address_type;
    U16 from_address[MMA_MAX_ADDR_LEN];
#endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
} srv_mms_new_message_cntx_struct;

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
typedef struct
{
    U32 msg_id[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
    U32 updated_msg_id[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
    U32 not_added_msg_id[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
    U32 not_added_count;
    kal_bool action_result[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
    U16 msg_number;
    mma_folder_enum msg_box_type;
    U8 curr_index;
    srv_um_mark_several_op_action_enum action_type;
    U8 msg_type[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
    kal_bool msg_read_status[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
} srv_mms_mark_several_struct;
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER    /* event parameter header */
        /* DOM-NOT_FOR_SDK-END */
    U8 folder_id;           /* MMA folder ID */
} srv_mms_post_refresh_ind;

#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__

#define   SRV_MMS_DEFAULT_NOTIFY_FOLDER_NAME             L"@mms_notify" /* should be consistent with the path defined in fs_quota.c file */
#define   SRV_MMS_FILE_NOTIFY_NAME                       L"notify_list.ntf"
#define   UMMS_NOTIFY_TIMER_DUR                     (3000)

typedef struct _mmi_umms_notification_list
{
    U32 msg_id;
    struct _mmi_umms_notification_list *next;
} srv_mms_roaming_notification_list;

typedef struct
{
    U8 default_sys_folder_path_for_notify_path[SRV_FMGR_PATH_MAX_LEN + 1];
    srv_mms_roaming_notification_list *notify_list_start;
} srv_mms_roaming_no_dowload_struct;

#endif /* __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__ */ 

typedef struct
{
    U8 result;
    U32 msg_id;
    mma_sync_msg_attribute_struct msg_info;
} srv_mms_sync_msg_info_struct;

typedef struct
{
    U8 sim_id;          /* mmi_sim_id_enum */
    U8 sim_inserted;    /* mmi_sim_id_enum */
    U8 setting_mode;    /* mmi_sim_id_enum */
    U8 sim1_can_read;
    U8 sim2_can_read;
    U8 sim1_type;       /* mmi_sim_type_enum */
    U8 sim2_type;       /* mmi_sim_type_enum */
} srv_mms_sim_status_info_ind_struct;

typedef struct
{

    U16 *src_file_name;
    U16 *virtual_file_name;
    mma_mms_object_struct *media_info;
    U16 *media_file_path;
    FS_HANDLE fh;
    U16 hilighted_attachment_index;
    U8 obj_drm_type;

} srv_mms_save_object_struct;

typedef struct
{
    MMI_BOOL is_sim1_valid;
    MMI_BOOL is_sim2_valid;
    MMI_BOOL profile_set_for_sim1;
    MMI_BOOL profile_set_for_sim2;
} srv_mms_sim_and_profile_context_struct;

typedef struct
{
    U32 msg_id;
    U32 new_msg_id;
    U16 *response_txt;
    U8 result;
    U8 quota;
    U8 sim_id;
    U8 rsp_type;
} srv_mms_bgsr_popup_data;

/************************************************************************/
/* Internal Global function                                 */
/************************************************************************/
extern void srv_mms_init(void);
extern void srv_mms_set_protocol_event_handler(void);
extern srv_mms_process_data_struct *srv_mms_get_process_slot(void);
extern srv_mms_process_data_struct *srv_mms_get_process_by_req_id(U32 req_id);
extern srv_mms_process_data_struct *srv_mms_get_process_by_app_id(U8 app_id);
extern MMI_BOOL srv_mms_is_ready(void);
extern void srv_mms_reset_process_data(srv_mms_process_data_struct *process);
extern void srv_mms_mma_get_msg_info_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_mma_get_msg_info_data_hdlr(srv_mms_process_data_struct *process, void *msg);

extern void srv_mms_get_content_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_get_msg_num_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_set_readmark_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_save_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_delete_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_get_unread_msg_list_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_get_msg_property_list_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_get_recent_evt_list_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_delete_recent_event_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_obj_ind_rsp_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_create_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_delete_all_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_entry_mark_several_screen_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_power_off_data_hdlr(srv_mms_process_data_struct *process, void *msg);

/* rajbir */
extern MMI_BOOL srv_mms_notify_event_ind(void *InMsg, int mod_src, void *ilm_p);
extern void srv_mms_new_mms_handle_notification(void *user_data);
extern void srv_mms_corrupted_mms_rsp_callback(srv_mms_result_enum result, void *msgrsp, S32 user_data);
extern void srv_mms_get_call_back_from_bgsr_for_dwnld_quota(U32 msg_id, srv_mms_bgsr_msg_info_struct *msg_info);
extern void srv_mms_set_data_hdlr(srv_mms_process_data_struct *process, void *msg);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
extern MMI_BOOL srv_mms_mark_several_list_procress(void *multi_op);
extern void srv_mms_umms_mark_several_property_rsp(srv_mms_result_enum result, void *msgrsp, void *user_data);
extern void srv_mms_mark_several_delete_rsp(srv_mms_result_enum result, void *msgrsp, void *user_data);
extern void srv_mms_mark_several_multi_move_rsp(srv_mms_result_enum result, void *msgrsp, void *user_data);
extern void srv_mms_send_multi_delete_rsp_to_um(void);

/* extern void srv_mms_set_values_for_multi_delete_to_um(srv_um_mark_several_op_rsp_struct *msg_rsp); */
extern void srv_mms_bgsr_multi_delete_msg_notify_callback(MMI_BOOL result_array[]);
extern void srv_mms_bgsr_multi_move_msg_notify_callback(MMI_BOOL result_array[]);
extern void srv_mms_handle_multi_move_rsp(wap_mma_save_rsp_struct *msg_rsp);
extern void srv_mms_set_values_for_multi_move_to_um(srv_mms_multi_op_send_rsp_struct *msg_rsp);
extern void srv_mms_set_values_for_multi_delete_to_um(srv_mms_multi_op_send_rsp_struct *msg_rsp);
extern void srv_mms_send_multi_move_rsp_to_um(void);
extern void srv_mms_send_multi_delete_rsp_to_um(void);

#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
extern void srv_mms_multi_copy_to_archive_rsp_hdlr(srv_mms_result_enum result, void *rsp_data, S32 user_data);
#endif

extern void srv_mms_get_msg_change_storage_rsp_hdlr(wap_mma_change_msg_storage_rsp_struct *msgrsp);
extern void srv_mms_get_msg_change_storage_rsp_send_to_um(void);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 

#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__

extern void srv_mms_init_notify_roaming_download_data(void);
extern void srv_mms_generate_file_path_for_notify(void);
extern void srv_mms_read_notify_struct_from_file(FS_HANDLE file_handle);
extern void srv_mms_add_to_list_from_file_for_roaming_notify(srv_mms_roaming_notification_list *inMsg);
extern void srv_mms_notification_list_delete_all(void);
extern void srv_mms_get_header_request_for_notification(U32 msg_id);
extern void srv_mms_download_request(wap_mma_get_msg_info_rsp_struct *curr_msg);
extern void srv_mms_get_next_msg_id_from_notify_list(void);
extern void srv_mms_add_to_notification_list(const srv_mms_mma_get_msg_info_rsp_struct *inMsg);
extern void srv_mms_write_data_to_notify_file(srv_mms_roaming_notification_list *notify_struct);
extern void srv_mms_start_notification_timer(void);
extern void srv_mms_notification_timer_expire(void);
extern void srv_mms_notify_download_request_in_home(void);
extern void srv_mms_write_current_notify_list_to_file(void);
extern void srv_mms_delete_msg_from_show_notification_list(wap_mma_delete_rsp_struct *inMsg);
extern void srv_mms_notification_get_header_rsp(srv_mms_result_enum result, void *msgrsp, S32 user_data);
#endif /* __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__ */ 

#if(MMI_MAX_SIM_NUM >= 2)
extern U8 srv_mms_convert_to_uc_sim_id(U8 sim_id);
extern void srv_mms_dual_sim_set_download_msg_id(U32 msg_id);
extern void srv_mms_dual_sim_set_download_time(U32 time);
extern void srv_mms_dual_sim_set_download_size(U8 size);
extern MMI_BOOL srv_mms_get_sim_status(U8 sim_id);

extern void srv_mms_set_selected_sim_id(const U8 sim_id);
extern U8 srv_mms_get_selected_sim_id(void);
extern U32 srv_mms_dual_sim_get_download_msg_id(void);
extern U8 srv_mms_convert_wap_sim_id_to_mma_sim_id(srv_wap_prof_sim_id_enum sim_id);

#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* __MMI_MMS_DUAL_SIM__ */
extern void srv_mms_dual_sim_status_info_hdlr(void *inmsg);
extern U32 srv_get_total_number_of_messages(void);
extern void srv_mms_get_number_status_icon(void);
extern void srv_mms_status_icon_unread_rsp_hdlr(srv_mms_result_enum result, void *msgrsp, void *user_data);
extern void srv_mms_fill_get_msg_num_req_struct(srv_mms_get_msg_num_req_struct *msgReq);
extern void srv_update_total_number_of_messages(const srv_mms_get_msg_num_rsp_struct *msg);
extern U32 srv_mms_get_number_of_unread_messages_in_inbox(U8 sim_id);

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
extern void srv_mms_set_buffer_for_nmgr(srv_mms_get_unread_msg_list_rsp_struct *msg_rsp);
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

extern void srv_mms_entry_new_mms_hndlr(
                const U32 msg_id,
                const kal_uint16 folder_id,
                kal_uint8 msg_media_type,
                kal_uint8 sim_id);

#if defined(__MMI_MMS_REPORT_BOX_SUPPORT__) || defined(__MMI_MMS_REPORT_STATUS_SUPPORT__)
extern void srv_mms_entry_new_report_hndlr(wap_mma_event_new_msg_struct *notify_event);
#endif 

extern void srv_mms_new_msg_info_cb(srv_mms_result_enum result, void *msgrsp, S32 user_data);
extern void srv_mms_handle_new_mms(const srv_mms_mma_get_msg_info_rsp_struct *msgRsp, const U32 msg_id);
extern void srv_mms_inform_um_about_new_msg_ind(U32 msg_id, U32 received_date, U32 Date, U8 sim_id);
extern void srv_mms_um_refresh_ind(mma_folder_enum folder_id);

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
extern void srv_mms_nmgr_get_unread_msg_number_rsp_for_nmgr(srv_mms_result_enum result, void *msgrsp, void *user_data);
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/
extern void srv_mms_nmgr_cancel_unread_msg(void);

extern void srv_mms_mma_get_msg_info_req(
                srv_mms_process_data_struct *process,
                srv_mms_mma_get_msg_info_req_struct *para);
extern MMI_BOOL srv_mms_mma_get_msg_info_rsp(void *msg);
extern void srv_mms_get_content_info_req(srv_mms_process_data_struct *process, srv_mms_get_content_req_struct *para);
extern MMI_BOOL srv_mms_get_content_rsp(void *msg);
extern void srv_mms_get_msg_num_req(srv_mms_process_data_struct *process, srv_mms_get_msg_num_req_struct *para);
extern MMI_BOOL srv_mms_get_msg_num_rsp(void *msg);
extern void srv_mms_set_readmark_req(srv_mms_process_data_struct *process, srv_mms_set_readmark_req_struct *para);
extern MMI_BOOL srv_mms_set_readmark_rsp(void *msg);
extern void srv_mms_save_req(srv_mms_process_data_struct *process, srv_mms_save_req_struct *para);
extern MMI_BOOL srv_mms_save_rsp(void *msg);
extern void srv_mms_delete_req(srv_mms_process_data_struct *process, srv_mms_delete_req_struct *para);
extern MMI_BOOL srv_mms_delete_rsp(void *msg);
extern void srv_mms_get_unread_msg_list_req(
                srv_mms_process_data_struct *process,
                srv_mms_get_unread_msg_list_req_struct *para);
extern MMI_BOOL srv_mms_get_unread_msg_list_rsp(void *msg);
extern void srv_mms_get_msg_property_list_req(
                srv_mms_process_data_struct *process,
                srv_mms_property_req_struct *para);
extern MMI_BOOL srv_mms_get_msg_property_list_rsp(void *msg);
extern void srv_mms_get_recent_evt_list_req(
                srv_mms_process_data_struct *process,
                srv_mms_recent_evt_list_req_struct *para);
extern MMI_BOOL srv_mms_get_recent_evt_list_rsp(void *msg);
extern void srv_mms_delete_recent_event_req(
                srv_mms_process_data_struct *process,
                srv_mms_delete_recent_evt_req_struct *para);
extern MMI_BOOL srv_mms_delete_recent_event_rsp(void *msg);
extern void srv_mms_send_obj_ind_req(srv_mms_process_data_struct *process, srv_mms_obj_ind_struct *para);
extern MMI_BOOL srv_mms_recv_obj_ind_rsp(void *msg);
extern void srv_mms_create_req(srv_mms_process_data_struct *process, srv_mms_create_req_struct *para);
extern MMI_BOOL srv_mms_create_rsp(void *msg);
extern void srv_mms_delete_all_req(srv_mms_process_data_struct *process, srv_mms_delete_all_ind_struct *para);
extern MMI_BOOL srv_mms_delete_all_rsp(void *msg);
extern void srv_mms_power_off_req(srv_mms_process_data_struct *process, srv_mms_power_off_req_struct *para);
extern MMI_BOOL srv_mms_power_off_rsp(void *msg);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
extern void srv_mms_entry_mark_several_req(
                srv_mms_process_data_struct *process,
                srv_mms_entry_mark_several_req_struct *para);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 
extern MMI_BOOL srv_mms_entry_mark_several_rsp(void *msg);

#ifdef __MMI_VCARD__
extern MMI_BOOL srv_mms_vcard_version_req_hdlr(void *msg);
#endif 
extern MMI_BOOL srv_mms_multi_op_req_hdlr(void *msg);
extern void srv_mms_multi_op_send_rsp(void *msg);
extern MMI_BOOL srv_mms_view_msg_ind_hdlr(void *msg);
extern MMI_BOOL srv_mms_storage_full_ind_hdlr(void *msg);
extern MMI_BOOL srv_mms_terminate_ind_hdlr(void *msg);
extern MMI_BOOL srv_mms_start_immed_retrieval_ind_hdlr(void *msg);
extern MMI_BOOL srv_mms_stop_immed_retrieval_ind_hdlr(void *msg);
extern MMI_BOOL srv_mms_um_ready_ind_hdlr(void *msg);
extern MMI_BOOL srv_mms_wap_mma_ready_ind_hdlr(void *msg);
extern MMI_BOOL srv_mms_sim_status_info_ind_hdlr(void *msg);
extern void srv_mms_um_refresh_msg_ind(srv_mms_um_refresh_ind_struct *msg);

/* memory card  */
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern MMI_BOOL srv_mms_get_msg_change_storage_rsp(void *msg);
extern MMI_BOOL srv_mms_get_memory_card_pug_in_response(void *msg);
extern MMI_BOOL srv_mms_get_memory_card_pug_out_response(void *msg);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
/* memory card  */

/* AMITESH */
extern MMI_BOOL srv_mms_get_use_details_rsp(void *msg);

/* AMITESH */
extern MMI_BOOL srv_mms_set_data_rsp(void *msg);
extern MMI_BOOL srv_mms_get_set_profile_rsp(void *inMsg);

#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif 

/* amit addeed for settings */
extern MMI_BOOL srv_mms_set_app_data_rsp(void *msg);

extern void srv_mms_read_nvram_settings(MMI_BOOL flag);

extern U32 srv_mms_get_list_info(void *req);
extern void srv_mms_send_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);

extern void srv_mms_get_active_profile_rsp_callback(
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_profile_content_struct *profile_content_p);

#ifdef WAP_SUPPORT
extern void srv_mms_set_current_profile_req_by_data(
                srv_wap_prof_profile_content_struct *profile_struct,
                U8 mma_sim_id);
#else /* WAP_SUPPORT */ 
extern void srv_mms_set_current_profile_req_by_data(nvram_profile_content_struct *profile_struct, U8 mma_sim_id);
#endif /* WAP_SUPPORT */ 

extern MMI_BOOL srv_mms_delete_folder_rsp(void *msg);
extern void srv_mms_init_use_details(void);
extern void srv_mms_set_app_data_rsp_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_recieved_set_profile_response(void *inmsg);
extern void srv_mms_get_um_msg_info_rsp_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_get_um_list_info_rsp_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_set_settings_rsp_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_fill_current_settings_for_mma(wap_mma_set_setting_req_struct *msgSet);
extern void srv_mms_update_status_icon_on_number_rsp(void);
extern S32 srv_mms_ready(void);
extern void srv_mms_delete_folder_data_hdlr(srv_mms_process_data_struct *process, void *msg);
extern void srv_mms_delete_folder_req(srv_mms_process_data_struct *process, srv_mms_delete_folder_req_struct *para);
extern void srv_mms_send_use_details_req(
                srv_mms_process_data_struct *process,
                srv_mms_get_use_details_list_req_struct *para);
extern void srv_mms_mma_set_settings_req(
                srv_mms_process_data_struct *process,
                srv_mms_mma_set_settings_req_struct *req_data);
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
extern void srv_mms_um_get_list_info_req(
                srv_mms_process_data_struct *process,
                srv_mms_get_list_info_req_struct *req_data);
extern void srv_mms_um_get_template_msg_info_req(
                srv_mms_process_data_struct *process,
                srv_mms_get_msg_info_req_struct *req_data);
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
extern void srv_mms_set_app_data_req(srv_mms_process_data_struct *process, srv_mms_set_app_data_req_struct *para);

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
extern void srv_mms_nmgr_get_unread_msg(void);
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
extern void srv_mms_free_all_sim_related_object_handler_node(U8 sim_id);
#endif 
extern void srv_mms_signature_data_init(void);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern U8 srv_mms_get_mms_prefer_storage_for_hilight(void);
#endif 

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
extern void srv_mms_vendor_create_req_hdlr(void *in_msg);
extern void srv_mms_vendor_create_rsp(srv_mms_result_enum srv_result, void *rsp_data, void *user_data);
extern void srv_mms_send_create_rsp_to_vendor(U32 msg_id, U8 result);
extern void srv_mms_vendor_send_req_hdlr(void *in_msg);
extern void srv_mms_vendor_cancel_send_req_hdlr(void *in_msg);
extern void srv_mms_vendor_delete_req_hdlr(void *in_msg);
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
extern void srv_mms_mma_insuf_mem_req_hdlr(void *in_msg);

extern void srv_mms_set_refresh_profile_flag(MMI_BOOL flag);
extern MMI_BOOL srv_mms_get_refresh_profile_flag(void);

#ifdef __MMI_FTE_SUPPORT__
extern srv_mms_sync_msg_info_struct *srv_mms_get_sync_msg_info(void);
#endif 
extern srv_mms_sync_msg_info_struct *srv_mms_get_sync_msg_info_ex(U32 msg_id);
extern void srv_mms_emit_ready_event(MMI_BOOL mms_ready);

extern U8 srv_mms_convert_mma_addr_type_to_srv_addr_type(mma_addr_type_enum type);
extern U8 srv_mms_convert_mma_addr_group_to_srv_addr_group(mma_address_group_type_enum type);
extern void srv_mms_fill_msg_num_req_struct(srv_mms_get_msg_count_struct *msgReq);
extern void srv_mms_update_folder_msg_num(const srv_mms_get_msg_count_struct *msg);

extern void srv_mms_get_content_info_req(srv_mms_process_data_struct *process, srv_mms_get_content_req_struct *para);
extern MMI_BOOL srv_mms_get_content_rsp(void *msg);
#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
extern MMI_BOOL srv_mms_copy_to_archive_rsp(void *msg);
extern void srv_mms_copy_to_archive_req(
                srv_mms_process_data_struct *process,
                srv_mms_copy_to_archive_req_struct *para);
extern void srv_mms_copy_to_archive_rsp_hdlr(srv_mms_process_data_struct *process, void *msg);
#endif
extern srv_um_addr_enum srv_mms_convert_mma_addr_type_to_um_addr_type(U8 addr_type);
extern mmi_ret srv_mms_post_refresh_cb(mmi_event_struct *para);
extern void srv_mms_free_mms_content_req(srv_mms_get_content_rsp_struct *para);
void mmi_umms_app_core_delete_mms_cb (srv_mms_result_enum result, void *rsp_data, S32 user_data);

extern void srv_mms_set_is_mms_in_use_flag(MMI_BOOL flag);
extern S32 srv_mms_deinit_lite_viewer(srv_mms_lite_viewer_handle_data *file_handle);


typedef struct
{
    U16 *text_file;     /* text media */
    U16 *img_file;      /* image media */
    U16 *audio_file;    /* audio media */
    U16 *video_file;    /* video media */
    BOOL enable;        /* signature enable or disable setting */
} srv_mms_signature_struct;

typedef struct
{
    srv_mms_signature_struct signature;     /* signature setting */
    mma_image_resizing_struct image_resize; /* image resizing enable or disable setting */
    mma_setting_struct sliding_time;        /* default min max time values */
    U32 max_mms_size;                       /* max size of mms selected in compose setting to compose */
    mma_creation_mode_enum creation_mode;   /* user selected creation mode setting */
    mma_priority_enum priority;             /* default priority to set to msg */
    mma_expiry_time_enum validity_period;   /* validity period set to msg from setting */
    mma_delivery_time_enum delivery_time;   /* delivery time set to msg from setting */
    BOOL delivery_report;                   /* delivery report enable or disable setting */
    BOOL read_report;                       /* read report enable or disable setting */
    BOOL hide_sender;                       /* hide sender enable or disable setting */
    U8 best_page_duration;                  /* best page duration enable or disable setting */
    U32 duration;                           /* default slide time */
} srv_mms_settings_info_struct;

/* Slim UI Development */

#ifdef __COSMOS_MMI_PACKAGE__
extern void srv_mms_send_mem_full(void);
#endif 

extern void srv_mms_get_lite_viewer_data_rsp_hdlr(srv_mms_process_data_struct *process, void* msg);
extern void srv_mms_get_lite_viewer_data_req(srv_mms_process_data_struct *process, srv_mms_get_lite_viewer_data_req_struct *para);
extern MMI_BOOL srv_mms_get_lite_viewer_data_rsp(void *msg);
extern void srv_mms_viewer_change_encoding(U8 *src_buffer, U32 size, U8 *dest_buffer, U16 charset);
#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_SRV_PROT_H */ 

