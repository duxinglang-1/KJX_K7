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
 * DLAgentSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef DOWNLOAD_AGENT_SRV_PROT_H
#define DOWNLOAD_AGENT_SRV_PROT_H
//#ifdef __COSMOS_MMI_PACKAGE__
#ifndef _FILE_MGR_H_
#include "FileMgr.h"
#endif

#ifndef DOWNLOAD_AGENT_DEF_H
#include "DLAgentSrvDef.h"
#endif

#ifndef DOWNLOAD_AGENT_GPROT_H
#include "DLAgentSrvGProt.h"
#endif
#include "DLAgentSrvIProt.h"
#include "DLAgentSrvWPS.h"

#ifdef __DRM_SUPPORT__
#include "drm_def.h"  
#endif /* __DRM_SUPPORT__ */

#include "FileMgrType.h"
#include "wgui_categories_util.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    SRV_DA_APP_LAUNCH_DOWNLOADING_LIST,
    SRV_DA_APP_LAUNCH_COMPLETED_LIST,
    SRV_DA_APP_LAUNCH_NEW_DOWNLOAD,
    SRV_DA_APP_LAUNCH_NEW_OMA_DOWNLOAD,
    SRV_DA_APP_LAUNCH_SELECT_STORAGE, /* No use for venus */
    SRV_DA_APP_LAUNCH_PROGRESSING,
    SRV_DA_APP_CLOSE_PROGRESSING,
    SRV_DA_APP_LAUNCH_POPUP,
    SRV_DA_APP_LAUNCH_AUTH_SCREEN,
    SRV_DA_APP_UPDATE_DOWNLOAD,
    SRV_DA_APP_UPDATE_NCENTER,
    SRV_DA_APP_LAUNCH_SHOW_CONFIRM,
    SRV_DA_APP_LAUNCH_DISPLAY_JOB_DETAIL,
    SRV_DA_APP_NEW_DOWNLOAD_OVERWRITE,
    SRV_DA_APP_LAUNCH_SHOW_POPUP,

    SRV_DA_APP_LAUNCH_END
    
} srv_da_app_launch_type_enum;


typedef enum
{
    SRV_DA_DRIVE_PHONE = 1,
    SRV_DA_DRIVE_MEMORY_CARD,

    SRV_DA_DRIVE_END
    
} srv_da_drive_type_enum;



typedef enum
{
	SRV_DA_GLOBAL_NOT_SUPPORTED = 1,
	SRV_DA_GLOBAL_UNSUPPORTED_FORMAT,
	SRV_DA_RIGHTS_DID_NOT_ARRIVE_ON_TIME,
	SRV_DA_JAVA_JOB_EXIST,
	SRV_DA_GLOBAL_NOT_ENOUGH_MEMORY,
	SRV_DA_GLOBAL_INSERT_MEMORY_CARD,
	SRV_DA_INSERT_MEMORY_CARD,
	SRV_DA_INSERT_MEM_CARD,
	SRV_DA_GLOBAL_DRM_INVALID_FORMAT,
	SRV_DA_JOB_EXIST,
	SRV_DA_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL,
	SRV_DA_PROMPT_EXCEED_MAX_DL,
	SRV_DA_AHTUENTICATION_FAILED,
	SRV_DA_OMA_ERROR_SEND_REPORT_FAIL,
	SRV_DA_GLOBAL_SAVED,
	SRV_DA_SAVED_TO_CARD,
	SRV_DA_GLOBAL_SAVED_TO_PHONE,
	SRV_DA_UNABLE_TO_SAVE_FILE,
	SRV_DA_GLOBAL_INSUFFICIENT_MEMORY,
	SRV_DA_ERROR_RESUME_FAIL,
	SRV_DA_ERROR_CONNECT_CLOSED,
	SRV_DA_OMA_ERROR_SEND_REPORT_CANCEL,
	SRV_DA_PROMPT_DL_COMPLETE,
	SRV_DA_GLOBAL_DONE,
	SRV_DA_GLOBAL_CANCELLING,
	SRV_DA_PLEASE_WAIT,
	SRV_DA_PROCESSING,
	SRV_DA_DRM_PROCESSING,
	SRV_DA_GLOBAL_SAVING,
	SRV_DA_GLOBAL_MOVING,
	SRV_DA_NEW_PUSH,
	SRV_DLA_FAILED_TO_DOWNLOAD,
	SRV_DLA_IS_FAILED_TO_DOWNLOAD,

	SRV_DA_STRING_END

} srv_da_string_enum;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum
{
	SRV_DA_CBM_APP_ID_NONE,
	SRV_DA_CBM_APP_ID1,
	SRV_DA_CBM_APP_ID2,
	SRV_DA_CBM_APP_ID_END
}srv_da_cbm_app_id_enum;
typedef enum
{
    SRV_DA_LIST_TYPE_DOWNLOADED = 1,
    SRV_DA_LIST_TYPE_COMPLETED,

    SRV_DA_LIST_TYPE_END
    
} srv_da_list_type_enum;

/********************************************* START OF EVENT STRUCTURES ***************************************************/

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U16 screen_id;
    U16 title_string_id;
    U16 title_icon_id;
    U16 message_id;
    MMI_BOOL cancel_rsk;
    void *arg;
    void (*cancel_callback)(void *arg, MMI_BOOL is_deleted);
} srv_da_show_progressing_event_struct;

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    MMI_BOOL show;
    U16      type;
    void     *arg;
} srv_da_update_ncenter_event_struct;

typedef struct
{
  MMI_EVT_PARAM_HEADER  
  S32      error_code;
  void     *arg;
} srv_da_push_process_event_struct;

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct *job;
    srv_da_popup_message_struct *msg;
	U16 *filepath;
} srv_da_popup_for_job_msg_event_struct;

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct *job;
	srv_da_popup_type_enum type;
	S32 cause;
	U16 error_str_id;
	MMI_BOOL terminate_job;
} srv_da_popup_error_for_job_struct;

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct *job;
	srv_da_popup_type_enum type;
	S32 cause;
	U16 error_str_id;
	MMI_BOOL free_string_after_popup;
	void *info;
} srv_da_popup_message_for_job_struct;

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    UI_string_ID_type string_id;
    srv_da_popup_type_enum type;
	S32 cause;
} srv_da_popup_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    void *instance;
} srv_da_set_active_select_storage_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct* job;
    MMI_BOOL check_complete;
    U16      list_type;
} srv_da_display_job_list_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct  *job;
    U32                str_id;
} srv_da_display_job_detail_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U16 screen_id;
} srv_da_progressing_close_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U16 error_code;
    mmi_proc_func callback;
} srv_da_popup_for_error_code_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U16 title_string_id;
    U16 title_icon_id;
    U16 lsk_string_id;
    U16 rsk_string_id;
    void *arg;   
    void (*fill_msg_string)(void *arg, U16 *buffer, U32 buffer_len);
    void (*lsk_hdlr)(void *arg, U16 *filepath);
    void (*rsk_hdlr)(void *arg);
    void (*delete_hdlr)(void *arg);
    MMI_BOOL set_instance;
    MMI_BOOL show_cancel_ask;
    U16  arg_size;
} srv_da_show_choice_screen_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct *job;
    U16 instance_id;
} srv_da_set_active_download_confirm_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U32 job;
    U16 status;
    MMI_BOOL is_error;
} srv_da_wps_http_response_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U32 arg;
} srv_da_confirm_oma_download_event_struct;

typedef struct 
{
    MMI_EVT_PARAM_HEADER
} srv_da_usb_available_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U32 arg;
    srv_da_storage_parameter_struct *para;
    srv_da_action_enum job_type;
} srv_da_display_select_storage_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U32 arg;
    U16 status;
} srv_da_oma_handle_http_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    U32 arg;
    srv_da_auth_callback_type  auth_callback;
} srv_da_show_user_auth_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_push_item_struct *item;
    srv_da_setting_struct *setting;
} srv_da_push_process_item_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct* job;
} srv_da_update_job_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct *job;
#ifdef __DRM_SUPPORT__
    drm_method_enum drm_method;
#endif
} srv_da_drm_save_as_event_struct;



typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct *job;
    srv_da_action_enum action;
    S32 result;
    const U16 *new_filepath;
    const applib_mime_type_struct *new_mime_type;
#ifdef __DRM_SUPPORT__
    const srv_da_drm_result_info_struct *info;
#endif /* __DRM_SUPPORT__ */
} srv_da_update_content_by_drm_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct *job;
} srv_da_click_job_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct* job;
    U16 string_id;
} srv_da_curr_job_aborted_event_struct;


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    srv_da_job_struct* job;
	MMI_BOOL is_in_job_screen;
	S32 index;
} srv_da_remove_scr_event_struct;

typedef struct /* UNUSED */
{
    MMI_EVT_PARAM_HEADER
    srv_da_scr_storage_callback_type callback;
    const srv_da_storage_parameter_struct* parameter;
    U32 arg;
    U16 title_icon_id;
    MMI_BOOL set_instance;
} srv_da_select_storage_event_struct;

typedef struct
{
    U16 type;
    U16 title;
    U16 str1;
    U16 str2;
    U16 str3;
    
    void (*func1)(void *arg);
    void (*func2)(void *arg);
    void (*func3)(void *arg);

    void *para;
} srv_da_confirm_struct;

/********************************************* END OF EVENT STRUCTURES *****************************************************/
extern void *srv_da_adp_mem_allocate(U32 size);
extern void srv_srv_da_adp_mem_free(void *ptr);
#ifdef __CERTMAN_SUPPORT__
extern void srv_da_adp_certman_install_file(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action_type,
    PU16 filename,
    PS8 download_url,
    PS8 mime_type_str_string);
#endif
#ifdef __J2ME__
extern void srv_da_adp_java_receive_da_file (S32 session_id, S32 mime_type, S32 mime_subtype, S32 action, PU16 file_path, PS8 url, PS8 mime_type_string);
extern void srv_da_adp_java_setting(
        S32	session_id,
        S32	mime_type,
        S32	mime_subtype,
        S32 action,
        U32	filesize,
        PS8	url,
        PS8	mime_type_string,
        U32	content_len,
        PS8	content,
        srv_da_setting_struct *setting);
#endif
extern void srv_da_adp_usb_app_unavailable_popup(void);
extern void srv_da_adp_init (void);
/* TODO: to remove error here we need to remove this header inclusion from prots.h and need to add in mmisrc.c */
extern S32 srv_da_get_job_index(const srv_da_job_struct *job);
extern S32 srv_da_get_curr_job_count (void);
//extern srv_da_job_struct *srv_da_get_list_job(void);
extern MMI_BOOL srv_da_free_job (srv_da_job_struct *job);
extern void srv_da_job_dispatch (srv_da_job_struct *job);
#ifndef MMI_DA_PLUTO_SLIM
extern void srv_da_job_on_play_selected(srv_da_job_struct *job);
#endif
//extern const srv_da_type_handler_struct* srv_da_get_default_mime_type_handler(void);
extern const U16* srv_da_job_get_filepath (const srv_da_job_struct *job);
#ifndef MMI_DA_PLUTO_SLIM
extern srv_da_job_struct* srv_da_get_nth_job(S32 index);
#endif
extern void srv_da_adp_popup_error_for_job(srv_da_job_struct *job, srv_da_popup_type_enum type, S32 cause, U16 error_str_id, MMI_BOOL terminate_job);
extern void srv_da_adp_popup_for_job(
    srv_da_job_struct *job,
    srv_da_popup_type_enum type,
    U16 message_str,
    MMI_BOOL free_string_after_popup,
	void *info);
#ifndef MMI_DA_PLUTO_SLIM
extern srv_da_job_struct* srv_da_get_nth_job_in_completed_list(S32 index);
extern srv_da_job_struct* srv_da_get_nth_job_in_downloading_list(S32 index);
#endif
extern void srv_da_abort_all_downloading_jobs (void);
extern srv_da_job_struct* srv_da_get_first_job (void);
extern MMI_BOOL srv_da_dispatch_http_job(srv_da_job_struct *job);
extern MMI_BOOL srv_da_reset_job_list_updated (void);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
extern MMI_BOOL srv_da_job_match_need_complete_notify_func(const srv_da_job_struct* job, U32 criteria);
#endif
extern MMI_BOOL srv_da_reset_job_list_updated (void);
extern S8* srv_da_job_get_infoURL (srv_da_job_struct *job);
extern MMI_BOOL srv_da_job_is_status_desc_available (const srv_da_job_struct *job);
extern void srv_da_job_get_status_desc (const srv_da_job_struct *job, U16 **string_buffer, U32 buffer_len, U16 num_of_item, U32 *num_of_filled);
extern MMI_BOOL srv_da_job_is_object_description_available (srv_da_job_struct *job);
extern void srv_da_job_change_filepath_to_download (srv_da_job_struct *job, U16 *filepath);
extern U32 srv_da_remove_all_completed(void);
#ifndef MMI_DA_PLUTO_SLIM
extern void srv_da_delete_extra_completed (void);
#endif
//extern void srv_da_curr_job_do_abort(srv_da_job_struct *job);
extern void srv_da_stop_selected_job (srv_da_job_struct *job, S32 prev_state, MMI_BOOL pauseOnly, srv_da_abort_callback_type end_callback);
extern void srv_da_suspend_all_job(srv_da_error_enum cause);
//extern srv_da_job_struct* srv_da_get_curr_job_in_setuping_state (void);
//extern MMI_BOOL srv_da_job_cancel(srv_da_job_struct* job);
extern void srv_da_send_download_info_ind(void);
extern void srv_da_discard_pending_popup(srv_da_job_struct *job);
extern srv_da_job_filestamp_enum srv_da_job_check_filestamp(srv_da_job_struct* job, U16* error_reason_id);
#ifndef MMI_DA_PLUTO_SLIM
extern void srv_da_report_to_app(srv_da_job_struct *job, const srv_da_item_progress_struct *info);    //slim
#endif
extern void srv_da_job_make_filestamp(srv_da_job_struct* job);
extern void  srv_da_job_get_name (const srv_da_job_struct *job, U16 *buffer, U16 len);
extern S32 srv_da_job_can_resume (const srv_da_job_struct *job);
//extern MMI_BOOL srv_da_util_is_supported_by_fmgr(const WCHAR *filepath);
extern void srv_da_adp_popup(U32 string_id, S32 cause, srv_da_popup_type_enum type);
extern MMI_BOOL srv_da_free_job_and_remove_screens (srv_da_job_struct *job);
extern srv_da_acceptance_enum srv_da_http_filename_done(
    U32 criteria, U16* filepath, MMI_BOOL canback, MMI_BOOL canpopup, void *instance);
extern void srv_da_http_get_setting(const srv_da_job_struct* job, srv_da_setting_struct *setting_data);
#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT

//extern void srv_da_http_dl_get_setting(const srv_da_job_struct* job, srv_da_setting_struct *setting_data);
#endif
extern void srv_da_oma_open_nextURL(srv_da_job_struct *job);
extern srv_da_acceptance_enum srv_da_oma_filename_done(
    U32 criteria, U16* filepath, MMI_BOOL canback, MMI_BOOL canpopup, void *instance);
extern srv_da_acceptance_enum srv_da_push_filename_done(
    U32 criteria, U16* filepath, MMI_BOOL canback, MMI_BOOL canpopup, void *instance);

extern MMI_BOOL srv_da_oma_popup_and_send_report(srv_da_job_struct *job, S32 error, MMI_BOOL end_job, MMI_BOOL bpopup);
extern srv_da_job_struct* srv_da_oma_get_current_job (void);
extern void srv_da_oma_set_current_job (srv_da_job_struct *job);
extern void srv_da_oma_select_storage(srv_da_job_struct *job);
extern void srv_da_oma_confirm_fill_msg_string(void *arg, U16 *buffer, U32 buffer_len);
extern void srv_da_oma_cancel_download(void *arg, MMI_BOOL is_deleted);
extern void srv_da_oma_session_created_callback(MMI_BOOL success, U32 arg);
extern void srv_da_oma_http_response_callback(
                U32 arg,
                U8 result,
                U16 status,
                S8 *header,
                S8 *content_type,
                U32 content_len,
                const wps_http_rsp_struct *rsp);
extern void srv_da_oma_session_dl_progress_callback(U32 arg, U8 status, U32 curr_size, S32 cause);
extern void srv_da_oma_show_screen_for_http_response(void *arg);


extern void srv_da_push_process_item(srv_da_push_item_struct *item, srv_da_setting_struct *setting);
extern void srv_da_push_free_item(srv_da_push_item_struct *item);
extern MMI_BOOL srv_da_push_is_item_in_list(srv_da_push_item_list_struct *list, srv_da_push_item_struct *item);
extern srv_da_push_item_list_struct* srv_da_get_top_processing_list_item (void);
extern srv_da_push_item_struct* srv_da_push_get_item_by_id(srv_da_push_item_list_struct *list, U16 unique_id);
extern void srv_da_push_prepend_to_list(srv_da_push_item_list_struct *list, srv_da_push_item_struct *item);
extern srv_da_push_item_list_struct* srv_da_get_top_dispatch_item (void);
extern srv_da_push_item_struct* srv_da_get_item_in_notifying (void);
extern void srv_da_push_remove_from_list(srv_da_push_item_list_struct *list, srv_da_push_item_struct *item);
extern srv_da_push_item_list_struct* srv_da_get_item_to_be_confirm (void);
extern U32 srv_da_get_item_to_be_confirm_num (void);
extern void srv_da_set_item_in_notifying (srv_da_push_item_struct *item_in_notifying);
extern srv_da_push_item_struct* srv_da_push_get_head_item(srv_da_push_item_list_struct *list);
extern void srv_da_util_get_available_size (U16 *buffer, U16 drv);
extern void srv_da_push_select_storage(srv_da_push_item_struct *item, srv_da_setting_struct *setting);
//extern UI_string_ID_type srv_da_search_mime_type_string(const applib_mime_type_struct * type);


//extern void mmi_da_entry_new_push_ind(void);
//extern U8 mmi_da_launch_ring_buffer_check(void);

extern void srv_da_vre_decide_default_filename (void* download_detail, U16 *temp_filename, U16 *ext);
//extern MMI_BOOL srv_da_job_on_use_file_selected(srv_da_job_struct *job);
extern void srv_da_resume_all_jobs (void);
#ifndef MMI_DA_PLUTO_SLIM
extern void srv_da_make_complete_filepath (U16 *filepath, void *arg, U16 *filename, U16 *ext, U16 drive, U16 size);
#endif
extern U32 srv_da_vre_get_download_size (void *arg);
extern U32 srv_da_push_get_download_size (void *arg);

extern void srv_da_push_get_filename (void* arg, U16 *temp_filename, U16 *ext);
extern srv_da_push_item_struct* srv_da_push_get_top_screen_stack_item(void);
extern void srv_da_push_remove_item_processed(srv_da_push_item_struct *item);

extern void srv_da_push_confirm_fill_msg_string (void *arg, U16 *buffer, U32 buffer_len);
extern void srv_da_push_confirm_start_to_download_callback(void *arg, U16 *filepath);
extern void srv_da_push_confirm_cancel_callback(void *arg);
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
extern MMI_BOOL srv_da_job_has_popupinfo_func(const srv_da_job_struct* job, U32 criteria);
#endif

extern U32 srv_da_mre_get_download_size (void *arg);
extern void srv_da_mre_decide_default_filename (void* arg, U16 *temp_filename, U16 *ext);

extern MMI_BOOL srv_da_is_notified (const srv_da_job_struct* job, U32 state);
#ifndef MMI_DA_PLUTO_SLIM
extern void srv_da_set_notified_completed (void);
extern void srv_da_set_notified_failed (void);
#endif
extern void srv_da_set_need_notify (srv_da_job_struct* job);
extern S32 srv_da_get_job_highlight_index(void);
extern MMI_BOOL srv_da_job_list_updated(void);
extern S32 srv_da_get_job_list_num(void);
extern void srv_da_job_set_list_updated(MMI_BOOL flag);
extern void srv_da_set_job_highlight_index(S32 index);
extern void srv_da_set_curr_job(srv_da_job_struct* para);
extern void srv_da_set_popup_triggerr(MMI_BOOL flag);
extern srv_da_job_struct* srv_da_get_curr_job(void);
extern MMI_BOOL srv_da_get_popup_triggere(void);
extern void srv_da_oma_set_storage_selection(MMI_BOOL new_value);



//#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* DOWNLOAD_AGENT_SRV_PROT_H */
