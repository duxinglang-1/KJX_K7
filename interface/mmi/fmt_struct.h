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
 *   fmt_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : fmt_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */

#ifndef _FMT_STRUCT_H
#define _FMT_STRUCT_H

#include "kal_general_types.h"
#include "fs_type.h"

/* Note: this should be sync with FMGR_MAX_FILE_LEN */
#define FMT_MAX_FILE_LEN  41

/* Enum and Struct */

/* Structure for Primitive */

/* for MSG_ID_MMI_FMT_COPY_REQ */
typedef struct {
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   action;
    kal_uint8   *src_file;
    kal_uint8   dest_file[(260+1)<<1];
    
    void        *recursive_buffer;  /* for FS usage : recursive_buffer*/
    kal_uint32  recur_buffer_size;      /* for FS usage : buffer size of recursive_buf */
    void        *callback;          /* function handler of delete response msg */
} mmi_fmt_copy_req_strcut;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8   drive;
    kal_uint32  level;
    void        *callback;          /* function handler of response msg */
    kal_uint32  user_data;
} mmi_fmt_format_req_strcut;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8   drive;
    void        *callback;          /* function handler of response msg */
    kal_uint32  user_data;
} mmi_fmt_check_drive_req_strcut;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  type;
    void        *filter;            /* address of filter mask */
    kal_uint8   *path;
    void        *callback;          /* function handler of delete response msg */
    void        *check_callback;    /* function handler of check delete filter */    
    void        *recursive_buffer;  /* for FS usage : recursive_buffer*/
    kal_int32   recur_buffer_size;  /* for FS usage : buffer size of recursive_buf */
} mmi_fmt_delete_req_strcut;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8   index;
    kal_uint32  mode;
} mmi_fmt_unmount_req_strcut;

typedef struct {
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_int32   result;
    void        *callback; /* function handler of response msg */
    kal_uint32  data;
    kal_wchar   *path;
    kal_uint32  user_data;
} mmi_fmt_copy_rsp_strcut, mmi_fmt_format_rsp_strcut, 
  mmi_fmt_check_drive_rsp_strcut, mmi_fmt_unmount_rsp_strcut,
  mmi_fmt_delete_rsp_strcut;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool present;
    kal_uint32 type;
} mmi_fmt_get_msdc_status_rsp_strcut;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 drv_num; 
    kal_uint8 drv_letter[32];   /* no of drives in one device */
    kal_uint32 type;
    kal_int32 cause;
} fmt_mmi_msdc_ind_struct;

typedef fmt_mmi_msdc_ind_struct fmt_mmi_card_plug_in_ind_struct;
typedef fmt_mmi_msdc_ind_struct fmt_mmi_card_plug_out_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 serial;
    kal_uint32 new_path_len;
    kal_uint32 type;
    kal_wchar file_path[261];
    kal_wchar *new_path;
} fmt_process_drm_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} fmt_fota_init_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
} fmt_fota_init_rsp_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint32 length;
    void*      pkg_buffer;
} fmt_fota_write_data_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
} fmt_fota_write_data_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} fmt_fota_finalize_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
} fmt_fota_finalize_rsp_struct;

#if defined(__FS_SORT_SUPPORT__) && defined(PLUTO_MMI)
typedef struct {
    kal_uint8   ref_count;
    kal_uint16  msg_len;

    kal_uint32  user_data;
    kal_uint32  user_seq;
    
    void        *buffer;
    kal_uint32  buffer_size;

    void        *compare_func;
   
    kal_uint32  Flag;
    
    kal_uint8   filter_count;
    kal_uint8   ArrayMask;
    kal_uint8   AttrMask;
    kal_uint8   cache_count;
    
    FS_Pattern_Struct *filter_array;                /* pointer to peer data */

    kal_uint8   folder_path[FS_MAX_PATH + 10];      /* path\*.* */

    kal_uint16  search_filename[FMT_MAX_FILE_LEN+1];
    kal_int32   cache_start_index;
    kal_int32   total_count;

} mmi_fmt_load_dir_req_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    
    kal_uint32 user_data;
    kal_uint32 user_seq;
    
    kal_int32  result;
    kal_uint32 handle;
    kal_int32  total_count;

} mmi_fmt_load_dir_rsp_struct;

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;

    kal_uint32 user_data;
    kal_uint32 user_seq;

    kal_int32  result;
    kal_uint32 handle;
    kal_int32  total_count;
    kal_int32  progress_count;

    kal_int32  search_index;
    kal_int32  cache_start_index;   /* this is used for sync loading, 
                                       fmt will prepare file_cache in sorting buffer */
    kal_int32  cache_count;         /* same as above */
    
} mmi_fmt_load_dir_progress_ind_struct;

typedef struct {
    kal_uint16      filename[FMT_MAX_FILE_LEN+1];
    FS_DOSDirEntry  direntry;
} mmi_fmt_cache_struct;
#endif

typedef struct {
    kal_uint8  ref_count;
    kal_uint16 msg_len;
       
    kal_uint8  op_type;
    kal_int32  result;
    
} mmi_fmt_op_abort_processing_ind_struct;


#if defined(PLUTO_MMI)

#define FMT_ADV_MSG_HEADER    \
    kal_uint8   ref_count;    \
    kal_uint16  msg_len;      \
    kal_uint32  adv_mark;     \
    kal_uint32  req_seq;

typedef struct {
    FMT_ADV_MSG_HEADER
} fmt_adv_base_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    kal_uint32  user_data;

    kal_uint32  flag;               /* FS_MOVE_COPY or FS_MOVE_KILL */
    void        *callback_ptr;      /* function handler of delete response msg */
    void        *buffer;            /* for FS usage : recursive_buffer*/
    kal_uint32  buffer_size;        /* for FS usage : buffer size of recursive_buf */

    WCHAR       *src_path;          /* pointer to peer data */
    WCHAR       dest_path[260];
} fmt_adv_copy_req_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    kal_uint32  user_data;
    
    kal_int32   result;
    
    kal_uint32  flag;               /* FS_MOVE_COPY or FS_MOVE_KILL */

    void        *callback_ptr;      /* function handler of response msg */

    WCHAR       *src_path;          /* pointer to peer data */
    WCHAR       dest_path[260];
} fmt_adv_copy_rsp_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    kal_uint32  user_data;
    
    kal_uint16  flag;               /* see fmt_delete_enum */
    kal_uint16  filter_count;       /* see fmt_delete_enum */
    void        *callback_ptr;      /* function handler of delete response msg */
    void        *buffer;            /* for FS usage : recursive_buffer*/
    kal_int32   buffer_size;        /* for FS usage : buffer size of recursive_buf */

    FS_Pattern_Struct   *filter_array; /* pointer to peer data */
    WCHAR       path[260];
} fmt_adv_delete_req_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    kal_uint32  user_data;
    
    kal_int32   result;
    
    kal_uint16  flag;               /* FS_MOVE_COPY or FS_MOVE_KILL */
    void        *callback_ptr;      /* function handler of response msg */

    WCHAR       path[260];
} fmt_adv_delete_rsp_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    kal_uint32  user_data;
    void        *callback_ptr;      /* function handler of response msg */
    
    WCHAR       path[260];
} fmt_adv_create_folder_req_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    kal_uint32  user_data;
    void        *callback_ptr;      /* function handler of response msg */
    
    kal_int32   result;

    WCHAR       path[260];
} fmt_adv_create_folder_rsp_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    kal_uint32  user_data;
    void        *callback_ptr;      /* function handler of response msg */
    
    WCHAR       path[260];
} fmt_adv_get_folder_size_req_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    kal_uint32  user_data;
    void        *callback_ptr;      /* function handler of response msg */
    
    kal_uint64  size;

    WCHAR       path[260];
} fmt_adv_get_folder_size_ind_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    kal_uint32  user_data;
    void        *callback_ptr;      /* function handler of response msg */
    
    kal_int32   result;

    kal_uint64  size;

    WCHAR       path[260];
} fmt_adv_get_folder_size_rsp_struct;

typedef struct {
    FMT_ADV_MSG_HEADER

    kal_uint32  user_data;
    
    kal_uint8   filter_count;
    kal_uint8   ArrayMask;
    kal_uint8   AttrMask;
    kal_uint8   cache_count;

    kal_uint32  Flag;
    
    kal_int32   load_index;
    kal_int32   total_count;
    
    kal_uint32  work_buffer_size;
    void        *work_buffer;
    kal_uint32  sort_buffer_size;
    void        *sort_buffer;

    SortingCompareFunc sort_compare_func;

    WCHAR       *search_filename;           /* pointer to peer data */
    FS_Pattern_Struct *filter_array;        /* pointer to peer data */

    WCHAR       folderpath[260 + 5];        /* path + "*.*" */

} fmt_adv_load_folder_req_struct;

typedef struct {
    WCHAR sfn[13];  /* 8.3 name */
} fmt_adv_load_folder_cache_item_struct;

typedef struct {
    FMT_ADV_MSG_HEADER
    
    kal_uint32 user_data;
    
    kal_int32  result;      /* 0 if succeed, < 0 if FS error */
    kal_int32  total_count; /* total file count */
    kal_uint32 sort_handle; /* sort handle
                             * if not NULL, this handle is used for FS_XFindState to retrieve file info
                             * if NULL, means there are too many files, can not sort, cache is returned */

    kal_int32  found_index; /* -1 if not found */

    /* cache is only used when sort_handle is NULL */
    kal_int32  cache_start_index;
    kal_int32  cache_count;

    kal_int32  total_folder_count; /* total folder count */

} fmt_adv_load_folder_rsp_struct;

/* progress_ind is only sent when sort is available */
typedef struct {
    FMT_ADV_MSG_HEADER

    kal_uint32 user_data;

    kal_uint32 sort_handle; 
    
    kal_int32  total_count;
    kal_int32  complete_count;
    
    kal_int32  cache_start_index;
    kal_int32  cache_count;
    
} fmt_adv_load_folder_progress_ind_struct;

#endif /* PLUTO_MMI */


#endif /*#ifdef _FMT_STRUCT_H */

