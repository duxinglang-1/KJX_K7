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
 *  drm_msg.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef DRM_MSG_H
#define DRM_MSG_H
#ifdef __DRM_SUPPORT__


#include "kal_general_types.h"
#include "drm_def.h"
#include "app_mine.h"
#include "wps_struct.h"
#include "stack_config.h"

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 mime_type;
    kal_wchar src_path[DRM_MAX_PATH_LENGTH];
    kal_bool src_need_kept;
    kal_wchar *dest_path;
    kal_uint32 dest_buffer_len_in_byte;
    kal_uint8 serial;
    drm_install_object_callback callback;
} drmt_install_object_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 result;
    kal_uint8 serial;
    applib_mime_type_struct *mime_type;
    drm_install_object_callback callback;
} drmt_install_object_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial;
    kal_wchar src_path[DRM_MAX_PATH_LENGTH];
    kal_uint8 *seed;
    kal_int32 seed_len;
    drm_message_info_struct *info;
    drm_parse_dm_callback callback;
} drmt_parse_dm_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial;
    kal_int32 result;
    drm_message_info_struct *info;
    drm_parse_dm_callback callback;
} drmt_parse_dm_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 index;
    drm_general_callback callback;
    kal_uint8 serial;
    kal_uint8 type;
    kal_wchar path[DRM_MAX_PATH_LENGTH];
} drmt_process_database_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 result;
    drm_general_callback callback;
    kal_uint8 serial;
    kal_uint8 __nouse__;
} drmt_process_database_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_wchar src_path[DRM_MAX_PATH_LENGTH];
    kal_wchar dest_path[DRM_MAX_PATH_LENGTH];
    kal_uint32 offset;
    kal_uint8 serial;
    drm_general_callback callback;
} drmt_encode_drm_message_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial;
    kal_int32 result;
    drm_general_callback callback;
} drmt_encode_drm_message_cnf_struct;

#ifdef __DRM_SUPPORT_SD_CALLBACK__
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial;
    kal_uint32 timer;
} drmt_register_sd_callback_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial;
    drm_sd_callback callback;
    void *para;
    kal_uint8 type;
} drmt_sd_expiry_ind_struct;
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */ 

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 id;
    kal_int32 result;
    drm_ro_expiry_callback callback;
} drmt_ro_expiry_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 auth_type;
    kal_uint8 realm_len;
    kal_uint8 realm[256];
} drmt_get_auth_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 username[WPS_MAX_AUTH_USERNAME_LENGTH];   /* coding in UTF8 */
    kal_uint8 password[WPS_MAX_AUTH_PASSWORD_LENGTH];   /* coding in UTF8 */
    kal_int32 user_len;
    kal_int32 pass_len;
} drmt_get_auth_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint32 current;
    kal_uint32 total;
    kal_int8 info[256 *2];  /* coding in UCS2 */
} drmt_dl_progress_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
} drmt_dl_progress_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint16 title;
    kal_uint16 image;
    kal_uint16 category;    /* drmt_get_confirm_category_enum */
    kal_int8 msg[256 *2];   /* coding in UCS2 */
} drmt_get_user_confirm_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 session_id;
    kal_uint16 result;
} drmt_get_user_confirm_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int8 msg[32 *2];    /* coding in UCS2 */
    kal_int8 type;
} drmt_alert_user_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} drmt_alert_user_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 title;
    kal_uint16 image;
    kal_int8 msg[512 *2];   /* coding in UCS2 */
} drmt_notify_info_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} drmt_notify_info_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} drmt_get_folder_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_wchar path[DRM_MAX_PATH_LENGTH];
} drmt_get_folder_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_wchar default_name[DRM_MAX_PATH_LENGTH];
} drmt_get_filename_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_wchar filename[DRM_MAX_PATH_LENGTH];
} drmt_get_filename_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 option;   /* drmt_browser_option_enum */
    kal_uint8 __nouse__;
    kal_int8 url[768 *2];
} drmt_open_url_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;   /* 0: ok , other : error */
} drmt_open_url_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} drmt_abort_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} drmt_abort_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} drmt_clean_screen_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} drmt_clean_screen_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 result;
    kal_uint8 imsi[17];
} drmt_get_imsi_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    drm_general_callback callback;
    kal_uint8 serial;
    kal_uint8 permission;
    kal_bool is_file_handle;
    kal_int32 file_handle;
    kal_wchar filepath[DRM_MAX_PATH_LENGTH];
} drmt_activate_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 result;
    drm_general_callback callback;
    kal_uint8 serial;
} drmt_activate_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint8 count_flag;
    kal_uint16 msg_len;
    drm_general_callback callback;
    kal_uint8 serial;
} drmt_get_ro_num_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 result;
    drm_general_callback callback;
    kal_uint8 serial;
} drmt_get_ro_num_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial;
    kal_uint8 type; /* drm_scan_disk_enum */
    drm_general_callback callback;
    module_type source;
    kal_wchar path[16];
} drmt_scan_disk_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 result;
    drm_general_callback callback;
    kal_uint8 serial;
} drmt_scan_disk_cnf_struct;

#endif /* __DRM_SUPPORT__ */ 
#endif /* DRM_MSG_H */ 

