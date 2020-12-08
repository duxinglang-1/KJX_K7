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
 *  MotSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile theater service head file
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MOT_SERVICE_GPROT_H__
#define __MOT_SERVICE_GPROT_H__

#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_rp_file_type_def.h"
#include "MMI_features.h"
#include "mmi_frm_events_gprot.h"

#ifdef __MMI_MOT_SUPPORT__

#if defined(__SQLITE3_SUPPORT__)
    #define __SRV_MOT_SQLITE_VERSION__
#endif

#if !defined(__SRV_MOT_SQLITE_VERSION__)
    #if defined(__FS_SORT_SUPPORT__)
        #define __SRV_MOT_FS_SORT__ // only do FS SORT when not using SQLITE.
    #endif
#endif


#ifdef __KMV_SUPPORT__
    #define __SRV_MOT_KMV_SUPPORT__
#endif

/**********************************************************************/

#ifdef __SRV_MOT_KMV_SUPPORT__
    #define SRV_MOT_THUMBNAIL_SIZE  (20*1024)
    #define SRV_MOT_MAX_RECORD_NUMBER   (100)
#else
    #define SRV_MOT_THUMBNAIL_SIZE  (5*1024)
    #define SRV_MOT_MAX_RECORD_NUMBER   (200)
#endif

#define SRV_MOT_MAX_RECENT_PLAYLIST_NUMBER (10)

#ifdef __SRV_MOT_FS_SORT__
#define SRV_MOT_FS_SORT_MAX_SORT              (300)
#define SRV_MOT_FS_SORT_WORKING_BUFFER_SIZE   FS_SORT_WORKING_BUFFER_SIZE_FOR_FILES(SRV_MOT_FS_SORT_MAX_SORT)
#define SRV_MOT_FS_SORT_SORTING_BUFFER_SIZE   FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(SRV_MOT_FS_SORT_MAX_SORT)
#else
#define SRV_MOT_FS_SORT_WORKING_BUFFER_SIZE   (0)
#define SRV_MOT_FS_SORT_SORTING_BUFFER_SIZE   (0)
#endif


#define SRV_MOT_FILE_NAME_LEN   (255)
#define SRV_MOT_FOLDER_LEN      (16)    // 11, but align to 16
                            /* X:\\Movie\\ + file name len */
#define SRV_MOT_FILE_PATH_LEN   (255)

#define SRV_MOT_TITLE_LEN       (20)
#define SRV_MOT_DATETIME_LEN    (20)
#define SRV_MOT_ARTIST_LEN      (20)
#define SRV_MOT_CATEGORY_LEN    (20)
#define SRV_MOT_DESCRIPT_LEN    (256)


#define SRV_MOT_FOLDER_NAME     L":\\Movie\\"

typedef struct srv_mot_content_info_struct srv_mot_content_info_struct;


#ifdef __SRV_MOT_SQLITE_VERSION__
    #define SRV_MOT_SQL_BUF_SIZE   (128*1024)

    #ifdef __SRV_MOT_KMV_SUPPORT__
        #define SRV_MOT_TOTAL_MEM_SIZE (25*1024 + SRV_MOT_SQL_BUF_SIZE + sizeof(srv_mot_content_info_struct))
    #else
        #define SRV_MOT_TOTAL_MEM_SIZE (5*1024 + SRV_MOT_SQL_BUF_SIZE + sizeof(srv_mot_content_info_struct))
    #endif
#else
    // srv_mot_db_meta_t is almost the same with srv_mot_content_info_struct
    // so we use srv_mot_content_info_struct instead.

    #ifdef __SRV_MOT_KMV_SUPPORT__
        #define SRV_MOT_TOTAL_MEM_SIZE (25*1024 + sizeof(srv_mot_content_info_struct) + SRV_MOT_FS_SORT_WORKING_BUFFER_SIZE + SRV_MOT_FS_SORT_SORTING_BUFFER_SIZE)
    #else
        #define SRV_MOT_TOTAL_MEM_SIZE (5*1024 + sizeof(srv_mot_content_info_struct) + SRV_MOT_FS_SORT_WORKING_BUFFER_SIZE + SRV_MOT_FS_SORT_SORTING_BUFFER_SIZE)
    #endif
#endif

/*service handle*/
//#ifndef srv_mot_h
typedef kal_uint32 srv_mot_h;
//#endif


/* return value */
typedef enum
{
    SRV_MOT_S_OK            =    0,      // OK
    SRV_MOT_S_ASYNC         =    1,      // async call
    SRV_MOT_S_FALSE         =    2,      // conditional success
    SRV_MOT_S_FINISH        =    3,      // job finish
    SRV_MOT_S_EMPTY         =    4,      // success but empty with output
    SRV_MOT_S_LIMIT         =    5,      // OK, but return by some limitation

    SRV_MOT_E_FAIL          = -100,
    SRV_MOT_E_OUT_OF_MEMORY = -101,
    SRV_MOT_E_WRONG_STATE   = -102,
    SRV_MOT_E_NO_MORE_DATA  = -103,
    SRV_MOT_E_INVALID_PARAM = -104,
    SRV_MOT_E_ABORTED       = -105,
    SRV_MOT_E_IO_ERROR      = -106,

    SRV_MOT_E_DB_OPEN_FAIL              = -200,
    SRV_MOT_E_DB_FREESPACE_NOT_ENOUGH   = -201,
    SRV_MOT_E_DB_IO_ERROR               = -202,

    SRV_MOT_RET_END         = 1000     /* end of enum */
}srv_mot_ret_enum;

/* callback event */
typedef enum
{
    SRV_MOT_CB_EVT_OPEN,
    SRV_MOT_CB_EVT_UPDATED,
    SRV_MOT_CB_EVT_TOTAL
}srv_mot_cb_evt_enum;

typedef enum
{
    SRV_MOT_THUMB_NONE,
    SRV_MOT_THUMB_JPG,
    SRV_MOT_THUMB_PNG
} srv_mot_thumb_type_enum;

/* category type */
typedef enum
{
    SRV_MOT_CAT_ACTION_ADVENTURE    = 0,
    SRV_MOT_CAT_ROMANCE_ETHICS      = 1,
    SRV_MOT_CAT_COMEDY_HUMOR        = 2,
    SRV_MOT_CAT_TV_DRAMA            = 3,
    SRV_MOT_CAT_ANIMATION_SCIFI     = 4,
    SRV_MOT_CAT_THRILLER_MYSTERY    = 5,
    SRV_MOT_CAT_MUSIC_PERFORMANCE   = 6,
    SRV_MOT_CAT_DOCUMENTARY         = 7,
    SRV_MOT_CAT_OTHERS              = 8,

    //SRV_MOT_CAT_FAVORITE    =50,
    SRV_MOT_CAT_RECENT_PLAY =51,
    SRV_MOT_CAT_ALL         =99

}srv_mot_cat_enum;

#define SRV_MOT_CAT_SYSTEM_DEFINE_NUM (SRV_MOT_CAT_OTHERS - SRV_MOT_CAT_ACTION_ADVENTURE + 1)

/* drive type */
typedef enum
{
    SRV_MOT_DRIVE_PHONE     = 0,
    SRV_MOT_DRIVE_CARD      = 1,
}srv_mot_drive_enum;

/* drive type */
typedef enum
{
    SRV_MOT_SORT_DIR_ASC     = 0,
    SRV_MOT_SORT_DIR_DESC    = 1,
}srv_mot_sort_dir_enum;

/* default string type */
typedef enum
{
    SRV_MOT_DEFAULT_STR_MOVIE_NAME  = 0,
    SRV_MOT_DEFAULT_STR_DURATION    = 1,
    SRV_MOT_DEFAULT_STR_YEAR        = 2,
    SRV_MOT_DEFAULT_STR_STARRING    = 3,
    SRV_MOT_DEFAULT_STR_PLOT        = 4
}srv_mot_default_str_enum;

/* mot list info structure */
typedef struct
{
    U32 content_id;
    WCHAR filename[SRV_MOT_FILE_NAME_LEN + 1];  /* filename */
    U64 duration;                                           /* duration in ms. */
}srv_mot_list_info_struct;

/* mot content info structure */
struct srv_mot_content_info_struct
{
    WCHAR filename[SRV_MOT_FILE_NAME_LEN + 1];      /* filename */
    U64 duration;                                   /* duration in ms. */
    WCHAR title[SRV_MOT_TITLE_LEN + 1];             /* movie name */
    WCHAR datetime[SRV_MOT_DATETIME_LEN + 1];       /* movie made or publish datatime */
    WCHAR artist[SRV_MOT_ARTIST_LEN + 1];           /* artist */
    WCHAR descript[SRV_MOT_DESCRIPT_LEN + 1];       /* descript */
    U8 thumbnail_buf[SRV_MOT_THUMBNAIL_SIZE];       /* PNG bitstream */
    U32 thumbnail_size;                             /* thumbnail size */
    srv_mot_cat_enum category;                      /* category enum */
};

/* mot content path structure */
typedef struct
{
    WCHAR filepath[SRV_MOT_FILE_PATH_LEN + 1];  /* filename */
}srv_mot_file_path_struct;

/* mot service create structure */
typedef struct
{
    S32 (*callback)(void* user_data, srv_mot_cb_evt_enum cb_event, srv_mot_ret_enum result, U32 param);
    void* user_data;
    U16 app_id;     // app id for MED memory allocate.
}srv_mot_create_struct;

/* mot service open structure */
typedef struct
{
    U8 drive_letter;
}srv_mot_open_struct;


/*****************************************************************************
 * FUNCTION
 *  srv_mot_update_memory_check
 * DESCRIPTION
 *  check if the memory is enough for update
 * PARAMETERS
 *  srv_mot_h           [IN]      service handle
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
srv_mot_ret_enum srv_mot_update_memory_check(srv_mot_h handle);


/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_content_number
 * DESCRIPTION
 *  get video number of particular category.
 * PARAMETERS
 *  srv_mot_h           [IN]      service handle
 *  srv_mot_cat_enum    [IN]      category
 *  U32*                [OUT]     number
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_content_number(srv_mot_h handle, srv_mot_cat_enum category, U32 *number);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_list_info_start
 * DESCRIPTION
 *  get list info of selected index
 * PARAMETERS
 *  srv_mot_h           [IN]      service handle
 *  srv_mot_cat_enum    [IN]      category
 *  U32                 [IN]      start index
 *  srv_mot_sort_dir_enum   [IN]  sorting order, ASC or DESC.
 *  srv_mot_list_info_struct* [OUT]      list info
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_list_info_start(srv_mot_h handle, srv_mot_cat_enum category,
                                                    U32 start_idx, srv_mot_sort_dir_enum dir, srv_mot_list_info_struct* list_info);


/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_list_info_next
 * DESCRIPTION
 *  get next list info, must called after srv_mot_get_list_info_start().
 * PARAMETERS
 *  srv_mot_h           [IN]      service handle
 *  srv_mot_list_info_struct* [OUT]      list info
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_list_info_next(srv_mot_h handle, srv_mot_list_info_struct* list_info);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_content_info
 * DESCRIPTION
 *  get selected content details.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 *  srv_mot_content_info_struct*    [OUT]     content info
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_content_info(srv_mot_h handle, U32 content_id,
                                                    srv_mot_content_info_struct* content_info);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_content_path
 * DESCRIPTION
 *  get selected item file path.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 *  srv_mot_file_path_struct*       [OUT]     list path
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_content_path(srv_mot_h handle, U32 content_id,
                                                    srv_mot_file_path_struct* path);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_category_string_id
 * DESCRIPTION
 *  get category string id.
 * PARAMETERS
 *  srv_mot_cat_enum    [IN]      category
 *  MMI_ID_TYPE*        [OUT]     str_id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_category_string_id(srv_mot_cat_enum category,
                                                    MMI_ID_TYPE* str_id);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_default_string_id
 * DESCRIPTION
 *  get service default string id.
 * PARAMETERS
 *  srv_mot_h                   [IN]      service handle
 *  srv_mot_default_str_enum    [IN]      type
 *  MMI_ID_TYPE*                [OUT]     str_id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_default_string_id(srv_mot_default_str_enum type,
                                                    MMI_ID_TYPE* str_id);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_get_error_string_id
 * DESCRIPTION
 *  get service error string id.
 * PARAMETERS
 *  srv_mot_ret_enum    [IN]      error
 *  MMI_ID_TYPE*        [OUT]     str_id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_error_string_id(srv_mot_h handle, srv_mot_ret_enum error,
                                                    MMI_ID_TYPE* str_id);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_add_recent_playlist
 * DESCRIPTION
 *  add content to recent play list.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_add_recent_playlist(srv_mot_h handle, U32 content_id, U64 time);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_delete_recent_playlist
 * DESCRIPTION
 *  remove content from recent play list.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_delete_recent_playlist(srv_mot_h handle, U32 content_id);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_delete_recent_playlist
 * DESCRIPTION
 *  remove content from recent play list.
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 *  U32                             [IN]      content id
 *  U64*                            [OUT]     last play time
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_get_recent_playtime(srv_mot_h handle, U32 content_id, U64* time);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_update
 * DESCRIPTION
 *  scan and update mot database
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_update(srv_mot_h handle);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_stop_updating
 * DESCRIPTION
 *  stop mot database updating
 * PARAMETERS
 *  srv_mot_h                       [IN]      service handle
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_stop_updating(srv_mot_h handle);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_open
 * DESCRIPTION
 *  open mot folder and related DB.
 * PARAMETERS
 *  srv_mot_h               [IN]    service handle
 *  srv_mot_open_struct     [IN]    open_param
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_open(srv_mot_h handle, srv_mot_open_struct* open_param);

/*****************************************************************************
 * FUNCTION
 *  srv_mot_close
 * DESCRIPTION
 *  close mot DB.
 * PARAMETERS
 *  srv_mot_h  [IN]      service handle
 * RETURNS
 *  return srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_close(srv_mot_h handle);

/*****************************************************************************
 * FUNCTION
 *  srv_list_create
 * DESCRIPTION
 *  create list service, get memory from caller
 * PARAMETERS
 *  srv_mot_create_struct  [IN]      see srv_mot_create_struct
 * RETURNS
 *  return service handle
 *****************************************************************************/
extern srv_mot_h srv_mot_create(srv_mot_create_struct* create_param);


/*****************************************************************************
 * FUNCTION
 *  srv_mot_destroy
 * DESCRIPTION
 *  destory mot service
 * PARAMETERS
 *  srv_mot_hdr :         [IN]   service handle
 * RETURNS
 *  return  srv_mot_ret_enum
 *****************************************************************************/
extern srv_mot_ret_enum srv_mot_destroy(srv_mot_h handle);


extern void srv_mot_main(ilm_struct* ilm);

#endif /* __MMI_MOT_SUPPORT__ */
#endif  /* __MOT_SERVICE_GPROT_H__ */

