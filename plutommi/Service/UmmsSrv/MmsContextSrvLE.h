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
 *  MmsContextSrvLE.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Typical SLIM Data Container
 *
 *
 * Author: Amitesh Srivastava
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMS_CONTEXT_SRV_H__
#define __MMS_CONTEXT_SRV_H__
#include "MMI_features.h"

#if defined (__MMI_MMS_2__ ) && defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)

#include "mma_struct.h"
#include "mma_api.h"
#include "MMIDataType.h"
#include "MmsSrvGprot.h"

/* Macro Definitions */

#define SRV_MMS_MAX_TEMP_FILE_LEN ((25 + 1) * ENCODING_LENGTH)
#define SRV_MMS_UC_FOLDER_NAME "@UC"
#define SRV_MMS_UC_TEXT_FILENAME "T"
#define SRV_MMS_UC_TEXT_FILEEXT "txt"
#define SRV_MMS_UC_IMAGE_FILENAME "I"
#define SRV_MMS_UC_IMAGE_FILEEXT "jpg"

#define MMI_MMS_TXT_BUF_UCS2_SIZE (4096)

/* Max length of subject UC supports, to compatable with UM subject. */
#define SRV_MMS_UC_MAX_SUBJECT_LEN SRV_UM_MAX_SUBJECT_LEN

#ifdef __MMI_MMS_2__
/* Max Email length UC supports. */
#define SRV_MMS_MAX_EMAIL_LEN (MMI_EMAIL_MAX_ADDR_LEN)
#else /* __MMI_MMS_2__ */ 
/* Max Email length UC supports, compatable with UM. */
#define SRV_MMS_MAX_EMAIL_LEN SRV_UM_MAX_ADDR_LEN
#endif /* __MMI_MMS_2__ */ 

#define SRV_MMS_MAX_PHONE_NUMBER_LEN MMI_PHB_NUMBER_LENGTH

/* Max number of slides UC supports. */
#define SRV_MMS_UC_MAX_MMS_SLIDE_NUM (mma_get_max_slide_no())

/* MAx length of subject array to use. */
#define SRV_MMS_UC_MAX_SUBJECT_ARRAY_LEN 60

#define SRV_MMS_UC_MAX_CHAR_NUM_IN_ONE_SLIDE (GUI_INPUT_BOX_MAX_LENGTH)

/* Max char/text buffer size UC supports on single slide. */
#define SRV_MMS_UC_TEXT_BUFFER_SIZE (SRV_MMS_UC_MAX_CHAR_NUM_IN_ONE_SLIDE * ENCODING_LENGTH + ENCODING_LENGTH)
/* Max UTF8 char/text buffer size UC supports on single slide. */
#define SRV_MMS_UC_UTF8_TEXT_BUFFER_SIZE (SRV_MMS_UC_TEXT_BUFFER_SIZE * ENCODING_LENGTH + ENCODING_LENGTH)

/* Default Bg color (0x00FFFFFF). */
#define SRV_MMS_UC_DEFAULT_BG_COLOR (mma_get_default_smil_bg_color())
/* Default Fg color (0x00000000). */
#define SRV_MMS_UC_DEFAULT_FG_COLOR (mma_get_default_smil_fg_color())

#ifdef APP_STORAGE_IN_SYS_DRV
/* UC folder drive to use. To sync with mms and all app as they need to use system drive space. */
#define SRV_MMS_UC_FOLDER_DRV SRV_FMGR_SYSTEM_DRV
#else /* APP_STORAGE_IN_SYS_DRV */ 
/* UC folder drive to use. */
#define SRV_MMS_UC_FOLDER_DRV SRV_FMGR_PUBLIC_DRV
#endif /* APP_STORAGE_IN_SYS_DRV */ 
/* UC generated names for text file with its complete path. */
#define SRV_MMS_MAKE_TEXT_FILE_PATH(x, d, i)               \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s%03d\\%s%03d.%s",\
      SRV_MMS_UC_FOLDER_DRV, SRV_MMS_UC_FOLDER_NAME, i, SRV_MMS_UC_TEXT_FILENAME, d, SRV_MMS_UC_TEXT_FILEEXT );
/* UC temp folder path. */
#define SRV_MMS_UC_MAKE_FOLDER_PATH(x, i)           \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\%s%03d",    \
      SRV_MMS_UC_FOLDER_DRV, SRV_MMS_UC_FOLDER_NAME, i);

/* Enums */
typedef enum
{
    MMS_EDITOR_ACTION_NONE,
    MMS_EDITOR_ACTION_EDIT_SUBJECT,     /* editor launched for subject */
    MMS_EDITOR_ACTION_EDIT_CONTENT,     /* editor launched for editing content */
    MMS_EDITOR_ACTION_EDIT_RECIPIENT    /* editor launched for editing recipient */
} mms_current_fseditor_operation;

typedef enum
{
    MMI_MMS_DONE_STATE_ADD_NUMBER,
    MMI_MMS_DONE_STATE_ADD_EMAIL,
    MMI_MMS_DONE_STATE_EDIT_NUMBER,
    MMI_MMS_DONE_STATE_EDIT_EMAIL,
    MMI_MMS_DONE_STATE_TOTAL_NUM
} mmi_mms_done_state_enum;

typedef enum
{
    SRV_MMS_GET_CONTENT_REQ,
    SRV_MMS_CREATE_REQ,
    SRV_MMS_DELETE_REQ,
    SRV_MMS_SAVE_REQ
} srv_mms_req_enum;

typedef enum
{
    SRV_MMS_MSG_TYPE_DEFAULT,       /* Default type. */
    // SRV_MMS_MSG_TYPE_SMS_PREFER, /* Default mode SMS. Try to change to SMS if content say can be SMS. */
    SRV_MMS_MSG_TYPE_MMS_PREFER,    /* Default mode MMS. */
    // SRV_MMS_MSG_TYPE_SMS_ONLY,   /* Only SMS mode support. Msg will not change to MMS. */
    SRV_MMS_MSG_TYPE_MMS_ONLY,      /* Only MMS mode support. Can not be changed to SMS. */
    SRV_MMS_MSG_TYPE_TOTAL_NUM      /* Max number of type modes UC supports. */
} srv_mms_msg_type_enum;

typedef enum
{
    SRV_MMS_STATE_WRITE_NEW_MSG,    /* Writing new msg state. */
    SRV_MMS_STATE_EDIT_EXISTED_MSG, /* Edit existing msg state. */
    SRV_MMS_STATE_FORWARD,          /* Forward existing msg state. Only for inbox and sent box msgs. */
    SRV_MMS_STATE_SEND,             /* Send existing msg state. Only for outbox and draft box msgs. */
    SRV_MMS_STATE_REPLY,            /* Reply existing msg state. */
    SRV_MMS_STATE_REPLY_ALL,        /* Reply all existing msg state. */
    SRV_MMS_STATE_TOTAL_NUM         /* Max number of msg states in UC. */
} srv_mms_state_enum;

typedef enum
{
    SRV_MMS_ACTION_IDLE,                                /* Uc action idle. No action. Default type. value 0 */
    SRV_MMS_ACTION_SEND,                                /* Uc action send. value 1 */
    SRV_MMS_ACTION_SEND_AND_SAVE,                       /* Uc action send and save. value 2 */
    SRV_MMS_ACTION_SAVE,                                /* Uc action save. value 3 */
    SRV_MMS_ACTION_DELETE,                              /* Uc action delete. value 4 */
    SRV_MMS_ACTION_PREVIEW,                             /* Uc action preview. value 5 */
    SRV_MMS_ACTION_SAVE_IN_BACKGROUND,                  /* Uc action save in background. value 6 */
    SRV_MMS_ACTION_SAVE_AS_TEMPLATE,                    /* Uc action save as template. value 7 */
    SRV_MMS_ACTION_SEND_IN_BACKGROUND,                  /* Uc action send in background. value 8 */
    SRV_MMS_ACTION_DELETE_IN_BACKGROUND,                /* Uc action delete in background. value 9 */
    SRV_MMS_ACTION_SAVE_IN_BACKGROUND_WHEN_BATTERY_LOW, /* Uc action save in background when battery low. value 10 */
    SRV_MMS_ACTION_TOTAL_NUM                            /* Max action. value 11 */
} srv_mms_action_type_enum;

typedef enum
{
    SRV_MMS_UC_INFO_TYPE_SMS,           /* Info type SMS. */
    SRV_MMS_UC_INFO_TYPE_MMS,           /* Info type MMS. */
    SRV_MMS_UC_INFO_TYPE_NORMAL_MMS = SRV_MMS_UC_INFO_TYPE_MMS, /* Info type MMS. for backward conpatiblity. */
    SRV_MMS_UC_INFO_TYPE_POSTCARD_MMS,  /* Info type Postcard. */
    SRV_MMS_UC_INFO_TYPE_EMAIL,         /* Info type EMAIL. */
    SRV_MMS_UC_INFO_TYPE_SMS_TEMPLATE,  /* Info type SMS Template. */
    SRV_MMS_UC_INFO_TYPE_MMS_TEMPLATE,  /* Info type MMS Template. */
    SRV_MMS_UC_INFO_TYPE_VCARD,         /* Info type VCARD. */
    SRV_MMS_UC_INFO_TYPE_VCALENDER,     /* Info type VCALENDER. */
    SRV_MMS_UC_INFO_TYPE_LEMEI_MMS,
    SRV_MMS_UC_INFO_TYPE_TOTAL_NUM      /* Max number of msg info UC supports. */
} srv_mms_uc_info_type_enum;

typedef enum
{
    SRV_MMS_UC_NO_ERROR,
    SRV_MMS_UC_INVALID_HANDLE_ERROR,
    SRV_MMS_UC_MESSAGE_SIZE_EXCEED_ERROR,
    SRV_MMS_UC_TOTAL_ERROR
} srv_mms_uc_error_type_enum;

/* Structures */
typedef struct
{
    mma_folder_enum folder_id;
    U8 is_preview;
    U8 set_read_mark;
    U8 uc_mode;
    U8 action;
    U8 open_mode;
    MMI_BOOL is_already_viewed;
    MMI_BOOL data_ready;
    U32 msg_id;
    mma_sync_msg_attribute_struct *msg_info;
    mma_mms_header_struct *header_info;
    srv_mms_bgsr_msg_info_struct *bgsr_msg_info;
} srv_mms_base_data_struct;

typedef struct
{
    srv_mms_viewer_xml_msg_struct *msg_cntx;
    PU8 slide_txt_buffer;   /* final buffer with UCS2 encoding */
    PU8 src_buffer;         /* buffer with source encoding */
    PU8 inputbox_buffer;
    U32 ptxtbuffersize;

} srv_mms_app_dtmgr_viewer_cateory_info_data;

typedef struct
{
    /* U16 *xml_file_path; */
    srv_mms_app_dtmgr_viewer_cateory_info_data *cat_info;
    srv_mms_viewer_use_details_list *list_head;
    U16 shown_slide_num;
} srv_mms_app_dtmgr_viewer_info_data;

typedef struct
{
    U8 addr[(SRV_MMS_UC_MAX_EMAIL_LEN + 1) *ENCODING_LENGTH];  /* local buffer for address */
    U8 total_address_num;   /* total addresses to+cc+bcc */
    U8 best_page_duration;
    mma_creation_mode_enum creation_mode;
    mma_mms_address_group_type_enum curr_addr_type;
    srv_mms_req_enum msg_req_type;
    srv_mms_msg_type_enum msg_type;
    srv_mms_state_enum msg_state;
    srv_mms_mode_change_status_enum msg_edit_mode;
    srv_mms_action_type_enum current_action;
    U16 *fseditor_buffer;   /* temp buffer needed to launch fs_editor */
    U32 total_msg_size;     /* header+body size */
    U32 msg_body_size;      /* body_size */
    U32 msg_size_without_text_buffer;
    U32 max_mms_size;
    U32 existed_msg_id;
    U32 signature_in_last_slide;
    U32 current_slide_num;
    U8 *temp_file_path;

} srv_mms_msg_struct;
typedef struct
{
    U8 *file_path;
    mma_insert_type_enum highlighted_object_type;   /* which media is to be inserted */
    srv_mms_msg_struct srv_msg;
    mmi_mms_done_state_enum recipient_state;        /* when launch editor for recipient then new recipient or edit recipient */
    U32 total_slide_num;
    mma_image_resizing_struct image_resize;
} srv_mms_uc_main_struct;

/* Functions */

extern mma_mms_description_struct *srv_mms_container_get_content(void);

extern void srv_mms_container_reset_context(void);

extern mma_result_enum srv_mms_container_set_message_id(U32 msg_id); /* its return value is mma_result_enum */

extern U8 srv_mms_container_get_folder(void);

extern S32 srv_mms_container_prepare_context(srv_mms_xml_parse_req_struct *req);

extern U32 srv_mms_container_get_message_id(void);

extern void srv_mms_container_set_is_preview(MMI_BOOL is_preview);

extern MMI_BOOL srv_mms_container_get_is_preview(void);

extern mma_sync_msg_attribute_struct *srv_mms_get_msg_info(void);

extern S32 srv_mms_conatiner_set_bgsr_info(void);

extern srv_mms_bgsr_msg_info_struct *srv_mms_container_get_bgsr_info(void);

extern MMI_BOOL srv_mms_container_get_is_viewed(void);

extern MMI_BOOL srv_mms_get_data_ready(void);

extern void srv_mms_container_set_is_viewed(MMI_BOOL is_viewed);

extern mma_mms_header_struct *srv_mms_container_get_header(void);

extern void *srv_mms_get_mms_info_data(void);

extern void srv_mms_container_change_struct_for_mma(void);


extern void srv_mms_create_mms_rsp(srv_mms_result_enum result, void *rsp_data, S32 user_data);

extern mma_mms_slide_struct *srv_mms_insert_slide(void);

extern void srv_mms_delete_addr(mma_mms_addr_list_struct *addr);

extern void srv_mms_entry_delete_slide(void);

extern MMI_BOOL srv_mms_delete_object_of_slide(mma_mms_slide_struct *slide);

extern MMI_BOOL srv_mms_reset_layout_if_needed(void);

extern MMI_BOOL srv_mms_delete_slide(mma_mms_slide_struct *slide);

extern void srv_mms_update_text_object_path(mma_mms_slide_struct *slide);

extern U16 *srv_mms_get_file_name(U16 *filePath);

extern MMI_BOOL srv_mms_delete_object_from_list(mma_mms_object_struct *object);

extern MMI_BOOL srv_mms_make_image_file_path(U8 *srv_mms_image_path);

extern MMI_BOOL srv_mms_is_valid_image(U16 *file_path);

extern MMI_BOOL srv_mms_update_filepath_with_string(S8 *srv_mms_new_path);

extern mma_mms_object_struct *srv_mms_check_duplicate_object(U16 *filePath);

extern U16 *srv_mms_get_file_extension(U16 *filePath);

extern MMI_BOOL srv_mms_insert_object_to_slide(
                    mma_mms_object_struct *object,
                    mma_mms_slide_struct *slide,
                    mma_insert_type_enum object_type,
                    U16 char_len);

extern mma_insert_check_struct srv_mms_select_object_response_from_fm_to_insert(PU16 filePath, S32 is_short);

extern mma_insert_check_struct srv_mms_post_handler_select_object_from_fm_to_insert(
                                mma_insert_type_enum mms_type,
                                U8 *srv_mms_image_path,
                                PU16 filePath);

extern void srv_mms_image_object_verification_process(U8 *mmi_uc_image_path, PU16 file_path);

extern void srv_mms_image_object_from_fm_resize_process_before_resolution_verification_to_insert(U16 *file_path);

extern void srv_mms_select_object_from_fm_to_insert(PU16 filePath, S32 is_short);

extern void srv_mms_select_object_from_fm_to_insert_warning_mode_check(PU16 filePath, S32 is_short);

extern mma_mms_object_struct *srv_mms_insert_object(S8 *filePath, mma_insert_type_enum object_type);

extern srv_mms_uc_error_type_enum srv_mms_hanlde_text_buffer_of_current_slide(S32 char_len);

extern S32 srv_mms_save_buffer_to_file(U8 *file_path, U8 *buffer, U16 char_num);

extern BOOL srv_mms_uc_is_phone_number_valid(S8 *strNumber);

extern BOOL srv_mms_uc_is_email_addr_valid(U8 *addr);

extern S32 srv_mms_uc_check_uc_folder(void);

extern mma_insert_check_struct srv_mms_get_mms_setting(void);

extern void srv_mms_update_msg_size(void);

extern void srv_mms_container_dummy_initializer(void);

extern mma_mms_sender_visibility_enum srv_mms_convert_mms_vis_to_mma_vis(BOOL visibility);

extern mma_mms_delivery_report_enum srv_mms_convert_mms_dr_to_mma_dr(BOOL delivery_report);

extern mma_mms_read_reply_enum srv_mms_convert_mms_rr_to_mma_rr(BOOL read_report);

extern void srv_mms_insert_object_to_attachment(
                mma_mms_object_struct *object,
                mma_mms_attachment_info_struct *attachment);

extern MMI_BOOL srv_mms_check_if_exceed_MMS_size_limitation(
                    U32 instance,
                    U32 size,
                    MMI_BOOL *fail_in_restricted_size_check);

extern void srv_mms_initialize_header_for_special_mms(void);
extern mma_mms_addr_list_struct *srv_mms_get_address_from_index(
                                    U16 index,
                                    mma_mms_address_group_type_enum address_group);
extern void srv_mms_delete_all_slide_text_file(void);

extern void srv_mms_container_invert_layput(void);

extern void srv_mms_set_open_mode(U8 open_mode);

extern S32 srv_mms_container_set_bgsr_info(void);

extern void srv_mms_composer_sd_plug_out_hdlr(void);

#if defined(__MMI_FTE_SUPPORT__)
extern void srv_mms_set_is_preview_from_cui(MMI_BOOL flag);
extern MMI_BOOL srv_mms_get_is_preview_from_cui(void);
#endif

#endif /* defined (__MMI_MMS_2__ ) && defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__) */ 
#endif /* __MMS_CONTEXT_SRV_H__ */ 

