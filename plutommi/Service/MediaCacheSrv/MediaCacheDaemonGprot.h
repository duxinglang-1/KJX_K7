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
 *  _MediaCacheDaemonGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ImageViewer Ex daemon head file
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#ifndef __MEDIACACHE_DAEMON_GPROT_H_
#define __MEDIACACHE_DAEMON_GPROT_H_
#include "MMI_features.h"
#if defined(__SQLITE3_SUPPORT__)
#include "MMIDataType.h"
#include "sqlite3.h"
#include "sqlite3ex.h"
#include "app_ltlcom.h"

#define IVD_FILE_MAX_PATH_LEN           (260 * 2)
#define IVD_DB_TEMP_BUF_LEN             (32 * 1024)
#define IVD_DATABASE_VER_4_DB           (25)


typedef struct
{
    S32 err_code;
    S32 err_group;
    S32 image_width;
    S32 image_height;
    S32 org_image_width;
    S32 org_image_height;

    MMI_BOOL with_meta;
    S32 meta_ret;
} ivd_db_imageinfo_struct;

typedef struct
{
    S32 err_code;
    S32 err_group;
    U8* meta_buffer;
    U32 meta_buffer_size;
} ivd_db_metainfo_struct;

typedef void (*ivd_req_callback)(S32 err, void *user_data);
typedef void (*ivd_req_callback_with_info)(S32 err, ivd_db_imageinfo_struct *image_info, void *user_data);
typedef void (*ivd_meta_req_callback_with_info)(S32 err, ivd_db_metainfo_struct *image_info, void *user_data);

typedef enum
{
    MMI_IVD_IO_BUF_STATE_IDLE = 0,
    MMI_IVD_IO_BUF_STATE_PUT,
    MMI_IVD_IO_BUF_STATE_GET,
    MMI_IVD_IO_BUF_STATE_END
} mmi_ivd_io_buf_state_enum;


typedef enum
{
    MMI_IVD_OK = 0,
    MMI_IVD_ERR_PUT_SKIP = -1000,
    MMI_IVD_ERR_GET_SKIP,
    MMI_IVD_ERR_UNKNOW,
    MMI_IVD_ERR_EMPTY,
    MMI_IVD_ERR_END
} mmi_ivd_error_enum;


typedef enum
{
    MMI_IVD_REMOVE_IMG_TYPE_BEFORE_DATE = 0,
    MMI_IVD_REMOVE_IMG_TYPE_NAME,
    MMI_IVD_REMOVE_IMG_TYPE_VIDEO,
    MMI_IVD_REMOVE_IMG_TYPE_END
} mmi_ivd_remove_img_type_enum;


typedef struct
{
    U8  *i_buffer;
    U32 i_length;
    U8  *o_buffer;
    U32 o_length;
    S32 req_seq_id;
    S32 i_seq_id;
    S32 ret_seq_id;
    U8  state;
    U8  i_state;
    U32 max_length;
    
    U8* meta_buffer;
    U32 meta_length;
    U8 meta_state;
} ivd_db_cache_buffer_struct;


typedef struct
{
    U8  *buffer;
    U32 length;
} ivd_db_buffer_struct;


typedef struct
{
    ivd_req_callback_with_info callback;
    S32 image_width;
    S32 image_height;
    S32 org_image_width;
    S32 org_image_height;
    U32 file_date;
    U32 file_time;
    U32 file_size;
    U32 file_CRC;
    S32 seq_id;
    CHAR  path[IVD_FILE_MAX_PATH_LEN];
    U32 ticks;
} ivd_db_img_get_struct;


typedef struct
{
    sqlite3 *db;
    sqlite3_instance db_instance;
    ivd_db_cache_buffer_struct  io_buf;
    ivd_db_buffer_struct        db_buffer;
    ivd_db_img_get_struct       img_get_req;
    U8*      buffer;
    U32      length;
    S32      error_code;
    S32      image_err_group;
    S32      image_err_code;
    U32      ticks;
    S32 image_width;
    S32 image_height;
    S32 org_image_width;
    S32 org_image_height;
    U8       color_format;
    U8       bytes_per_pixel;
    MMI_BOOL is_msg_sent;
    MMI_BOOL is_remove_msg_sent;
    MMI_BOOL is_db_inited;
    MMI_BOOL is_db_stopping;
    MMI_BOOL is_mark;
    MMI_BOOL is_get_cancel_put;

    S32 meta_ret;

    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    char db_cache_folder[IVD_FILE_MAX_PATH_LEN];    /* DB temp folder path */
    unsigned char *db_temp_buf;                     /* Buffer that replaces o_buf in io_buf */
    sqlite3_stmt *query_stmt;                       /* Cache for query statement */
    #endif
} ivd_db_handle_struct;


typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback callback;
    CHAR  path[IVD_FILE_MAX_PATH_LEN];
} ivd_db_start_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
} ivd_db_stop_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback callback;
    void *user_data;
    S32 image_width;
    S32 image_height;
    S32 org_image_width;
    S32 org_image_height;
    U8  *buffer;
    CHAR  path[IVD_FILE_MAX_PATH_LEN];
    U32 sys_date;
    U32 sys_time;
    U32 file_date;
    U32 file_time;
    U32 file_size;
    U32 file_CRC;
    S32 err_group;
    S32 err_code;
    S32 seq_id;
    S32 file_idx;
    gdi_color_format color_format;
    MMI_BOOL blocking;
} ivd_db_put_img_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    void *user_data;
    U32 ticks;
    U32 req_id;
    U8* buffer;

    MMI_BOOL with_meta;
    S32 meta_ret;
} ivd_db_get_img_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct    *db_handle;
    ivd_req_callback        callback;
    U32                     date;
    void *user_data;
    CHAR                    path[IVD_FILE_MAX_PATH_LEN];
    U8                      remove_type;
} ivd_db_remove_img_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback callback;
    S32 error_code;
    void *user_data;
} ivd_db_start_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback callback;
    S32 error_code;
    void *user_data;
} ivd_db_put_img_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback_with_info callback;
    S32 error_code;
    S32 image_err_code;
    S32 image_err_group;
    S32 image_org_width;
    S32 image_org_height;
    S32 image_width;
    S32 image_height;
    S32 req_id;
    void *user_data;
    U32 ticks;

    MMI_BOOL with_meta;
    U32 meta_ret;
} ivd_db_get_img_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct    *db_handle;
    ivd_req_callback        callback;
    S32                     error_code;
    void *user_data;
} ivd_db_remove_img_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback callback;
    S32 image_width;
    S32 image_height;
    S32 org_image_width;
    S32 org_image_height;
    U8  *buffer;
    U32 length4get;
    CHAR *path;
    U32 file_date;
    U32 file_time;
    U32 file_size;
    U32 file_CRC;
    S32 err_group;
    S32 err_code;
    S32 file_idx;
    gdi_color_format color_format;
    MMI_BOOL with_meta;
    S32 meta_ret;
} ivd_db_img_info_struct;


/* can you think meta is cache of image in scalado *//* can you think meta is cache of image in scalado */
#ifdef __SCALADO_SUPPORT__ 

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_meta_req_callback_with_info callback;
    void *user_data;
    S32 err_group;
    S32 err_code;
    U32 ticks;
} ivd_db_get_meta_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback        callback;
    void *user_data;
    S32 err_group;
    S32 err_code;
    U32 ticks;
} ivd_db_get_meta_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback callback;
    S32 seq_id;
    CHAR  path[IVD_FILE_MAX_PATH_LEN];
    S32 length;
    S32 err_group;
    S32 err_code;
    void *user_data;
    U32 sys_date;
    U32 sys_time;
} ivd_db_put_meta_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback callback;
    CHAR  *path;
    S32 error_code;
    void *user_data;
} ivd_db_put_meta_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ivd_db_handle_struct *db_handle;
    ivd_req_callback callback;
    CHAR  path[IVD_FILE_MAX_PATH_LEN];
    U8 *buffer;
    S32 buf_size;
    S32 err_group;
    S32 err_code;
} ivd_db_meta_info_struct;

#endif

extern S32 ivd_ivsrv_db_start(ivd_db_handle_struct *db_handle, const WCHAR *path, ivd_req_callback callback, const WCHAR *db_name);
extern void ivd_ivsrv_db_start_rsp_hdler(void *msg);
extern void ivd_ivsrv_db_put_img_rsp_hdler(void *msg);
extern void ivd_ivsrv_db_get_img_rsp_hdler(void *msg);
extern S32 ivd_ivsrv_db_stop(ivd_db_handle_struct *db_handle);
extern MMI_BOOL ivd_ivsrv_db_cancel_get(ivd_db_handle_struct *db_handle);
extern MMI_BOOL ivd_ivsrv_db_cancel_put(ivd_db_handle_struct *db_handle);
extern void ivd_ivsrv_db_put_img(ivd_db_img_info_struct *img_info, ivd_req_callback callback, void *user_data);
extern void ivd_ivsrv_db_put_img_blocking(ivd_db_img_info_struct *img_info);
extern S32 ivd_ivsrv_db_get_img(ivd_db_img_info_struct *img_info, ivd_req_callback_with_info callback);
extern S32 ivd_ivsrv_db_get_img_blocking(ivd_db_img_info_struct *img_info, U8* buffer, U32 length);
extern void ivd_ivsrv_db_remove_img_rsp_hdler(void *msg);
extern void ivd_ivsrv_db_remove_img_before_date(ivd_db_handle_struct *db_handle, U32 date, ivd_req_callback callback);
extern void ivd_ivsrv_db_remove_img_by_name(ivd_db_handle_struct *db_handle, CHAR *path, ivd_req_callback callback);
extern void ivd_ivsrv_db_enable_get_cancel_put(ivd_db_handle_struct *db_handle,MMI_BOOL enable);

#ifdef __SCALADO_SUPPORT__
extern void ivd_ivsrv_db_put_meta_rsp_hdler(void *msg);
extern void ivd_ivsrv_db_get_meta_rsp_hdler(void *msg);
extern MMI_BOOL ivd_ivsrv_db_get_meta_blocking(ivd_db_meta_info_struct *meta_info, ivd_req_callback_with_info callback, PS8 *o_buffer, PS32 o_buffer_size);
extern MMI_BOOL ivd_ivsrv_db_get_meta(ivd_db_meta_info_struct *meta_info, ivd_req_callback_with_info callback);
extern void ivd_ivsrv_db_put_meta(ivd_db_meta_info_struct *meta_info, ivd_req_callback callback, void* user_data);
#endif

#ifdef __COSMOS_MMI_PACKAGE__

#define IVD_DB_VIDEO_RESULT_BASE_HDR U32   type_id;\
                                     U32   msg_size;\
                                     mmi_ivd_error_enum result_code;

typedef struct ivd_db_video_result_base
{
    IVD_DB_VIDEO_RESULT_BASE_HDR
} ivd_db_video_result_base;

typedef struct ivd_db_video_result_bookmark
{
    IVD_DB_VIDEO_RESULT_BASE_HDR
    U32 bookmark_sec;
} ivd_db_video_result_bookmark;

typedef struct ivd_db_video_result_has_info
{
    IVD_DB_VIDEO_RESULT_BASE_HDR
    MMI_BOOL has_video_info;
} ivd_db_video_result_has_info;

// used to store query result
// in a blocking query. 
// IVD directly writes to this struct.
typedef struct ivd_db_video_result_info
{
    IVD_DB_VIDEO_RESULT_BASE_HDR
    U32 duration_sec;       // duration of video
    U32 bookmark_sec;       // bookmark (last viewed position) of video
    S32 thumb_width;        // video thumbnail width (pixel)
    S32 thumb_height;       // video thumbnail height (pixel)
    U8* thumb_buf_ptr;      // pointer to output thumbnail buffer
    U32 thumb_buf_len;      // length of thumbnail buffer
} ivd_db_video_result_info;

// used to store query result of last play info
// in a blocking query. 
// IVD directly writes to this struct.
typedef struct ivd_db_video_result_last_play_info
{
    IVD_DB_VIDEO_RESULT_BASE_HDR
    U32 duration_sec;       // duration of video
    U32 bookmark_sec;       // bookmark (last viewed position) of video
    S32 thumb_width;        // video thumbnail width (pixel)
    S32 thumb_height;       // video thumbnail height (pixel)
    U8* thumb_buf_ptr;      // pointer to output thumbnail buffer
    U32 thumb_buf_len;      // length of thumbnail buffer
    WCHAR file_name[IVD_FILE_MAX_PATH_LEN + 1];
} ivd_db_video_result_last_play_info;

// used to store query result of video collection info
typedef struct ivd_db_video_result_collection_info
{
    IVD_DB_VIDEO_RESULT_BASE_HDR
    U32 video_count;        // number of videos scanned
    S32 thumb_width;        // video thumbnail width (pixel)
    S32 thumb_height;       // video thumbnail height (pixel)
    U8* thumb_buf_ptr;      // pointer to output thumbnail buffer
    U32 thumb_buf_len;      // length of thumbnail buffer
} ivd_db_video_result_collection_info;

extern void ivd_ivsrv_db_get_video_info_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, ivd_db_video_result_info *query_result);
extern void ivd_ivsrv_db_put_video_info_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, ivd_db_video_result_info *video_info);
extern void ivd_ivsrv_db_update_video_bookmark_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, U32 bookmark_sec);
extern void ivd_ivsrv_db_get_video_bookmark_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, U32 *bookmark_sec);
extern void ivd_ivsrv_db_get_most_recent_play_video_blocking(ivd_db_handle_struct *db_handle, ivd_db_video_result_last_play_info *query_result);
extern void ivd_ivsrv_db_has_video_info_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, ivd_db_video_result_has_info *query_result);
extern void ivd_ivsrv_db_update_video_total_duration_blocking(ivd_db_handle_struct *db_handle, WCHAR *path, U32 bookmark_sec);
extern void ivd_ivsrv_db_remove_video_info_by_name(ivd_db_handle_struct *db_handle, const WCHAR *path, ivd_req_callback callback, void *userdata);

// set useEarlyCancel to MMI_TRUE causes ivd_iv_db_get_img_by_filename
// to abort current image if new images are requested.
extern void ivd_ivsrv_db_config_early_cancel(MMI_BOOL useEarlyCancel);

#endif /* __COSMOS_MMI_PACKAGE__ */

#endif /* defined(__SQLITE3_SUPPORT__) */
#endif /* __MEDIACACHE_DAEMON_GPROT_H_ */ 


