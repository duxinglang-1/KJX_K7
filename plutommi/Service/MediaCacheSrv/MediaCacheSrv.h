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
 *  MediaCacheSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ImageViewer Ex Srv header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MEDIACACHE_SRV_H_
#define _MEDIACACHE_SRV_H_
#include "MMI_features.h"
#if defined(__MMI_SRV_MEDIACACHE__)
#include "gdi_const.h"
#include "gdi_include.h"
#include "lcd_sw_inc.h"
#include "MMIDataType.h"
#include "MediaCacheSrvGprot.h"
#include "gdi_datatype.h"
#include "FileMgrSrvGProt.h"
#include "kal_general_types.h"

#if defined(__SQLITE3_SUPPORT__)
#include "sqlite3.h"
#include "sqlite3ex.h"
#include "MediaCacheDaemonGprot.h"
#endif

#ifdef __SCALADO_SUPPORT__
#include "ImgEdtSrvGprot.h"
#endif

/*************************************************
*
*  IVSRV Configure part
*
*************************************************/

#define SRV_MEDIACACHE_INSTANCE_NUM           (3)     /* service instance number */
#define SRV_MEDIACACHE_LARGE_IMG_RATE         (3)     /* W_LI = W_L1 x 3, H_LI = H_L1 x 3 */
#define SRV_MEDIACACHE_LEVEL2_IMG_DIV         (2)      
#define SRV_MEDIACACHE_CACHE_NUM              (25)    /* number of cache handles */
#define SRV_MEDIACACHE_DB_IMG_EXPIRE_DAYS     (60)    /* days that record will exist at db */
#define SRV_MEDIACACHE_GDI_WIDTH_LIMITATION   (2048)

#define SRV_MEDIACACHE_LARGE_COLOR_FORMAT     (GDI_COLOR_FORMAT_MAINLCD)
#define SRV_MEDIACACHE_LEVEL1_COLOR_FORMAT    (GDI_COLOR_FORMAT_MAINLCD)
#define SRV_MEDIACACHE_LEVEL2_COLOR_FORMAT    (GDI_COLOR_FORMAT_MAINLCD)
#define SRV_MEDIACACHE_DIRECT_DECODE_L1_SIZE  (1200*900) /*if image dimension less the it will decode L1 directly*/

/*************************************************
*
*  IVSRV DEFINED DATA
*
*************************************************/
#define SRV_MEDIACACHE_LARGE_IMG_RATE_POW2       (SRV_MEDIACACHE_LARGE_IMG_RATE * SRV_MEDIACACHE_LARGE_IMG_RATE)      /* LI = L1 x 9 */
#define SRV_MEDIACACHE_LEVEL2_IMG_DIV_POW2       (SRV_MEDIACACHE_LEVEL2_IMG_DIV * SRV_MEDIACACHE_LEVEL2_IMG_DIV)      /* L2 = L1 / 4 */
#define SRV_MEDIACACHE_RESUME_TIME_GAP_NORMAL    (1)
#define SRV_MEDIACACHE_SAVE2DB_TIME_GAP_NORMAL   (100)
#define SRV_MEDIACACHE_DECODE_TIME_GAP_NORMAL    (1)
#define SRV_MEDIACACHE_DECODE_TIME_GAP_SHORT     (1)
#define SRV_MEDIACACHE_DECODE_SCALE              (1000)
#define SRV_MEDIACACHE_DECODE_MAX_SCALE          (2046 * 4)
#define SRV_MEDIACACHE_MIN_IMG_SIZE_W            (40)
#define SRV_MEDIACACHE_MIN_IMG_SIZE_H            (40)
#define SRV_MEDIACACHE_BYTES_PER_PIXEL           (GDI_MAINLCD_BIT_PER_PIXEL / 8)
#define SRV_MEDIACACHE_DUMMY_FILE_IDX            (-1)
#define SRV_MEDIACACHE_DB_GET_IMG_START_ERR      (-1)
#define SRV_MEDIACACHE_DECODE_MAX_W_H            (LCD_WIDTH * LCD_HEIGHT / 4)
#define SRV_MEDIACACHE_LCD_BUF_LENGTH            (LCD_WIDTH * LCD_HEIGHT * SRV_MEDIACACHE_BYTES_PER_PIXEL)
#define SRV_MEDIACACHE_ONE_SMALL_BUF_LENGTH      (SRV_MEDIACACHE_LCD_BUF_LENGTH/4)
#define SRV_MEDIACACHE_BUF_ADD_TIMES_MAX         (50)
#define SRV_MEDIACACHE_DB_QUERY_BLOCK_SIZE       (5)
#define SRV_MEDIACACHE_KEY_CODE_SIZE             (20)
#define SRV_MEDIACACHE_KEY_CODE_ROUND            (20)

/*************************************************
*
*  IVSRV ASSERT INFO
*
*************************************************/
#define CACHE_TYPE_ERR      (0)
#define CACHE_METHOD_ERR    (0)
#define SRV_MEDIACACHE_CONFIG_WORK_MODE_ERR    (0)

/*************************************************
*
*  IVSRV context structure
*
*************************************************/
typedef enum
{
    SRV_MEDIACACHE_STATE_UNINITED = 0,
    SRV_MEDIACACHE_STATE_INITED,
    SRV_MEDIACACHE_STATE_RUNNING,
    SRV_MEDIACACHE_STATE_PAUSED,
    SRV_MEDIACACHE_STATE_END
} srv_mediacache_state_enum;

typedef enum
{
    SRV_MEDIACACHE_INTERNAL_ERR_SEARCHING_SAME_ONE = -17000,
    SRV_MEDIACACHE_INTERNAL_ERR_END
} srv_mediacache_internal_err_code_enum;


typedef enum
{
    SRV_MEDIACACHE_CACHE_STATE_EMPTY = 0,
    SRV_MEDIACACHE_CACHE_STATE_RESIZE_FROM_L1,
    SRV_MEDIACACHE_CACHE_STATE_RESIZE_FROM_L2,
    SRV_MEDIACACHE_CACHE_STATE_DECODING,
    SRV_MEDIACACHE_CACHE_STATE_DECODE_OK,
    SRV_MEDIACACHE_CACHE_STATE_DECODE_ERR,
    SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_NEED_CHECK,
    SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_SKIP,
    SRV_MEDIACACHE_CACHE_STATE_DECODE_DB_OK,
    SRV_MEDIACACHE_CACHE_STATE_END
} srv_mediacache_cache_state_enum;

typedef enum
{
    SRV_MEDIACACHE_RESIZE_QULITY_DEFAULT = 0,
    SRV_MEDIACACHE_RESIZE_QULITY_HIGH,
    SRV_MEDIACACHE_RESIZE_QULITY_FAST,      // low qulity but fast
    SRV_MEDIACACHE_RESIZE_QULITY_END
} srv_mediacache_resize_qulity_enum;

/*The enum of is cancel predecode*/
typedef enum
{
    SRV_MEDIACACHE_DATA_FORMAT_JPEG = 0,
    SRV_MEDIACACHE_DATA_FORMAT_BITMAP,
    SRV_MEDIACACHE_DATA_FORMAT_END
} srv_mediacache_data_format_enum;


typedef enum
{
    SRV_MEDIACACHE_WORKMODE_FILENAME,
    SRV_MEDIACACHE_WORKMODE_FILELIST,
    SRV_MEDIACACHE_WORKMODE_IDARRAY,
    SRV_MEDIACACHE_WORKMODE_END
} srv_mediacache_work_mode_enum;


typedef enum
{   
    SRV_MEDIACACHE_META_STATE_IDLE = 0,
    SRV_MEDIACACHE_META_STATE_GETTING_FROM_DB = 0x10,
    SRV_MEDIACACHE_META_STATE_GETTING_FROM_IES = 0x11,

    SRV_MEDIACACHE_META_STATE_FINISHED = 0x20,
    SRV_MEDIACACHE_META_STATE_FINISHED_BUT_ERROR = 0x21,
    
    SRV_MEDIACACHE_META_STATE_END
} srv_mediacache_meta_state_enum;

typedef struct srv_mediacache_cell
{
    struct srv_mediacache_cell *prev;       /* previous cell */
    struct srv_mediacache_cell *next;       /* next cell */
    U8  *buffer;                            /* image content buffer */
    S32 file_index;                         /* cell index */
    S32 image_width;                        /* image width in buffer */
    S32 image_height;                       /* image height in buffer */
    S32 org_image_width;                    /* original image width */
    S32 org_image_height;                   /* original image height */
    S32 err_code;                           /* error code if has */
    U16 image_type;                         /* JPG? BMP ? */
    U8  err_group;                          /* error group if has */
    U8  type;                               /* cell is from L1? L2? large? */
    U8  state;                              /* decoding? emptr? decode error? */
    U8  state_4_db;                         /* need save to DB? */
    MMI_BOOL  is_lock;                      /* the cell image content buffer is used by app ?*/
    MMI_BOOL  is_saved;                     /* is saved to DB or not */
#ifdef __SRV_MEDIACACHE_DEBUG_MEASURE__
    U32 decode_ticks;                       /* cell decode time */
    U32 db_ticks;                           /* data base decode time */
#endif

#ifdef __MMI_MEDIA_CACHE_YUV_THUMB__
    gdi_color_format buffer_format;         /* cell buffer format can be different from cache format */ 
#endif

#ifdef __SCALADO_SUPPORT__
    srv_ies_image_handle ies_image_handle;      /* handle for draw image */
    srv_ies_preview_handle ies_preview_handle;  /* handle for zoom and move */
    gdi_handle ies_preview_gdi_layer;           /* you decode cell using to this layer, for speed scalado */
    srv_ies_job_handle ies_meta_job_handle;     /* ies meta job handle */
    srv_ies_meta_handle ies_meta_handle;                            /* handle of meta */
    //PU8 ies_meta_buffer;                            /* meta buffer */
    //S32 ies_meta_buffer_size;                       /* meta buffer size */    
    MMI_BOOL is_ies_meta_saved;                     /* meta saved to DB or not*/
    S32 ies_meta_state;                             /* meta state*/
#endif
} srv_mediacache_cell_struct;


typedef struct
{
    srv_mediacache_cell_struct *curr_p;             /* currently not used */
    srv_mediacache_data_cb           app_data_cb;
    gdi_handle                  image_hdl_decoding;
    U32                         total_length;
    U32                         buf_length;
    U32                         small_buf_length;
    gdi_handle                  layer;
} srv_mediacache_filename_struct;


typedef struct
{
    S32 count;
    U16 *idarray_p;
} srv_mediacache_idarray_struct;


typedef struct
{
    srv_mediacache_cell_struct *level1_cache_block_p;
    srv_mediacache_cell_struct *level2_cache_block_p;
    srv_mediacache_cell_struct *large_img_cacheblock_p;
    S32 file_count;
    U8 num_level1_next;
    U8 num_level1_prev;
    U8 num_level2_prev;
    U8 num_level2_next;
    U8 num_level1_used;
    U8 num_level2_used;
    MMI_BOOL    has_large;
} srv_mediacache_filelist_struct;

typedef struct
{
    S32     level1_width;                               /* L1 cache width */
    S32     level1_height;                              /* L1 cache height */
    gdi_color_format level1_cf;                         /* color format */
    
    S32     level2_width;                               /* L2 cache width */
    S32     level2_height;                              /* L2 cache height */
    gdi_color_format level2_cf;                         /* color format */
    void    *run_buf;  /*run buffer will store srv cntx*/
    U32     run_buf_length; /*use xxx * num to get run buffer length*/

    void    *db_buf;  /*has macro defination of min and recommend*/
    U32     db_buf_length;
    gdi_color  bg_color;     /*back color for decode transparent image*/
    gdi_color_format  large_cf;        /*large buffer color format */
    
    
    SRV_FMGR_FILELIST_HANDLE flist_handle;              /* filelist handle */
    CHAR      filename[SRV_FMGR_PATH_BUFFER_SIZE];        /* filename */
    srv_mediacache_data_format_enum   data_format;      /* data format */ /* currently not used */
} srv_mediacache_config_struct;


typedef void (*srv_mediacache_decode_nb_cb)(GDI_RESULT result,gdi_handle handle);


/*****************************************************************************
* <GROUP  CallBackFunctions>
*
* FUNCTION
*    srv_mediacache_decode_get_filename_by_index
* DESCRIPTION
*  get image data callback handler, called when get image finished.
* PARAMETERS
*  err_group :      [IN]  the group of error.
*  err_code  :      [IN]  the error code.
*  user_data :      [IN]  user data.
* RETURNS
*  None.
*****************************************************************************/
typedef void (*srv_mediacache_nb_decode_callback)(S32 result, srv_mediacache_err_group_enum group, void *user_data);


/*****************************************************************************
* <GROUP  CallBackFunctions>
*
* FUNCTION
*    srv_mediacache_decode_get_filename_by_index
* DESCRIPTION
*  get image data callback handler, called when get image finished.
* PARAMETERS
*  err_group :      [IN]  the group of error.
*  err_code  :      [IN]  the error code.
*  user_data :      [IN]  user data.
* RETURNS
*  None.
*****************************************************************************/
typedef MMI_BOOL (*srv_mediacache_nb_decode)(U32 *handle, srv_mediacache_cell_struct *cell_p, srv_mediacache_nb_decode_callback done_callback, void *user_data);


/*****************************************************************************
* <GROUP  CallBackFunctions>
*
* FUNCTION
*    srv_mediacache_decode_get_filename_by_index
* DESCRIPTION
*  get image data callback handler, called when get image finished.
* PARAMETERS
*  err_group :      [IN]  the group of error.
*  err_code  :      [IN]  the error code.
*  user_data :      [IN]  user data.
* RETURNS
*  None.
*****************************************************************************/
typedef GDI_RESULT (*srv_mediacache_blocking_decode)(srv_mediacache_cell_struct *cell_p);


/*****************************************************************************
* <GROUP  CallBackFunctions>
*
* FUNCTION
*    srv_mediacache_decode_get_filename_by_index
* DESCRIPTION
*  get image data callback handler, called when get image finished.
* PARAMETERS
*  err_group :      [IN]  the group of error.
*  err_code  :      [IN]  the error code.
*  user_data :      [IN]  user data.
* RETURNS
*  None.
*****************************************************************************/
typedef MMI_BOOL (*srv_mediacache_nb_decode_cancel)(U32 handle);

typedef struct
{
    srv_mediacache_get_filename_cb        get_file_name;            /* get file name funciton */
    srv_mediacache_blocking_decode        decode_cell_blocking;     /* blocking decode cell function */
    srv_mediacache_nb_decode              decode_cell;              /* none blocking decode cell function */
    srv_mediacache_nb_decode_cancel       cancel_decode_cell;       /* cancel none blocking decode cell function */
    srv_mediacache_nb_decode              search_cell;              /* search cell function */ /*currently not use*/
    srv_mediacache_nb_decode_cancel       cancel_search_cell;       /* cancel search cell function */ /*currently not use*/
    
    srv_mediacache_engine_clip            set_clip;                 /* set clip function */
    U32*                                  user_data;                /* user data */
} srv_mediacache_eng_callbacks_struct;

typedef struct
{
    void *buffer;                                                   /* cell image content buffer */
    U32  length;                                                    /* cell image content length */
} srv_mediacache_buffers_struct;

typedef struct
{
    PU8 buffer;
    S32 buffer_size;
    MMI_BOOL is_used;
} srv_mediacache_meta_struct;

typedef struct
{
    srv_handle  medialib_mark;                          /* magic number, as condition of valid or not */
    U32  medialib_mark_buf_length;                      /* running buffer length */
    srv_mediacache_config_struct config;                /* settings for you config */
    U8* cache_block_start;                              /* cache block start addr */
    U8* cache_block_current;                            /* current cache block addr */
    U8* cache_block_end;                                /* cache block end addr */
    S32 canvas_height;                                  /* currently not use */
    S32 last_err_grp;                                   /* last error group */
    S32 last_err_code;                                  /* last error code */
    U32 large_buffer_size;                              /* large buffer size */
    U32 level1_buffer_size;                             /* L1 buffer size */
    U32 level2_buffer_size;                             /* L2 buffer size */
    U32 userdef_db_io_buffer_length;                    /* The buffer length you save to db */ /* curently not use */
    gdi_handle layer;                                   /* gdi nb decode handle */
    srv_mediacache_cell_struct *large_p;                /* large cell ptr */
    srv_mediacache_cell_struct *level1_curr_p;          /* level1 curr cell ptr */
    srv_mediacache_cell_struct *level2_curr_p;          /* level2 curr cell ptr */
    srv_mediacache_cell_struct *level1_first_p;         /* level1 frist cell ptr */
    srv_mediacache_cell_struct *level2_first_p;         /* level2 first cell ptr */
    srv_mediacache_cell_struct *level1_free_p;          /* level1 free cell ptr */
    srv_mediacache_cell_struct *level2_free_p;          /* level2 free cell ptr */
    srv_mediacache_cell_struct *locked_cell_p;          /* locked cell ptr */
    srv_mediacache_data_cb    app_data_cb;              /* nb decode cell callback */
    S32                     cb_file_idx;                /* callback file index */
    void                    *user_data;                 /* user data */
    srv_mediacache_pre_decode_cb      pre_decode_cb;    /* pre decode callback */
#if defined(__SQLITE3_SUPPORT__)
    ivd_db_handle_struct    db_handle;                  /* db handle */
    MMI_BOOL is_db_start_ok;                            /* is db started */
    MMI_BOOL is_clear_done;                             /* is all cell saved to db */
#endif
    U8          db_store_cache_group;                   /* you hope save L1 or L2 cache to db */
    U32         db_failed_query_count;                  /* db fails how many times */
    U8          state;                                  /* media cache state */
    U8          color_format;                           /* gdi decode layer color format */
    U8          bytes_per_pixel;                        /* bytes per pixel */
    MMI_BOOL    is_srv_clear_bg;                        /* need srv to clear the bg before draw */
    MMI_BOOL    is_srv_first_start;                     /* is cache first started */
    MMI_BOOL    is_can_saving;                          /* can save to db or not */ /*currently not use*/
    MMI_BOOL    is_waiting_resume;                      /* is waiting resume */
    MMI_BOOL    is_blocking_get_first;                  /* is blocking get first */
    MMI_BOOL    is_align_cache;                         /* MMI_TRUE will align cell buffer ptr and size to 32 bytes */
    U8          backup_state;                           /* if resume with delay, will record the dest state */
    gdi_color   bg_color;                               /* image draw layer background color */
    U32         start_ticks;                            /* time check */
    U32         end_ticks;                              /* time check */
    U8 decode_method;                                   /* how to find next cell */
    srv_mediacache_err_enum last_source;                /* the last image is from L1, L2 or large */
    srv_mediacache_cell_struct  *decoding_p;            /* decoding cell ptr */
    srv_mediacache_cell_struct  *searching_p;           /* the cell your search in db */
    gdi_handle                      image_hdl_decoding; /* gdi nb decode handle */
#ifdef __SCALADO_SUPPORT__
    srv_ies_job_handle ies_decoding_handle;                    /* ies decoding handle */
    srv_ies_app_session_handle ies_app_session;         /* ies job handle */
#endif
    srv_mediacache_resize_qulity_enum          qulity;  /* resize qty */
    MMI_BOOL    prev_first;                             /* is search prev first */
    srv_mediacache_work_mode_enum work_mode;
    union
    {
        srv_mediacache_filelist_struct  filelist;
        srv_mediacache_filename_struct  filename;
        srv_mediacache_idarray_struct   idarray;
    } mode_cntx;
    srv_mediacache_eng_callbacks_struct engine;         /* decode engine */
    srv_mediacache_events_cb        events_callback;    /* if happend some event, will callback */
    srv_mediacache_evt_get_filename_err_struct events_getfilename_err;  /* get file name but error */
    void *                          events_callback_user_data;          /* user data */
    srv_mediacache_buffers_struct   buffers[SRV_MEDIACACHE_BUF_ADD_TIMES_MAX];      /* cell content buffer */
    MMI_BOOL is_schedule_timer_started;                 /* is schedule timer started */
    U32         db_save_count;                          /* how many count you have saved to db */
    U32         db_save_decode_count;                   /* if decode ok, remerber this */
    MMI_BOOL    db_save_is_timer_start;                 /* start timer to save image content to db */
    gdi_handle  large_image_dec_hdlr;                   /* gdi decode handle for large */ /* only used for trace */
    MMI_BOOL is_using_ies;                          /* using scalado to decode */
    MMI_BOOL is_using_meta;                             /* using meta or not */
    MMI_BOOL is_meta_using_db;                          /* using db to save and read meta */
    MMI_BOOL is_put_meta_urgent;                        /* put meta in high priority */
    PS8 ies_render_buffer;                              /* use this buffer, to avoid IES writing ,but mmi get buffer */
    srv_mediacache_cell_struct *ies_meta_p;          /* pointer of meta cell creating */
    PS8 ies_app_working_buf;                         /* pointer to APP-provided IES working buffer. If NULL, use MED */
    U32 ies_app_working_buf_size;                    /* size of APP-provided IES working buffer */
} srv_mediacache_cntx_struct;


typedef struct
{
    SRV_FMGR_FILELIST_HANDLE    flist_handle;       /* used for file list mode */
    S32                     file_count;             /* file count */
    gdi_handle              image_hdl_decoding;     /* same with context decode handle */
    S32                     width;                  /* L2 size width */
    S32                     height;                 /* L2 size height */
    MMI_BOOL                is_to_buffer;           /* is clip head or not */
    MMI_BOOL                is_lock_level2_only;    /* only lock l2 or not */
    MMI_BOOL                is_use_gdi;
} srv_mediacache_engine_cntx_struct;


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_remove_cache
 * DESCRIPTION
 *  remove a cache from IVSRV
 * PARAMETERS
 *  *buffer   [IN]  buffer pointer
 * RETURNS
 *  error code
 *****************************************************************************/
typedef MMI_BOOL (*srv_mediacache_cache_finish_check_func)(srv_mediacache_cell_struct* cell_p, void *user_data);

extern U32 srv_mediacache_cache_get_img_size_by_type(U8 cahce_type);

extern MMI_BOOL srv_mediacache_cache_cell_finished(srv_mediacache_cell_struct *cell);

extern void srv_mediacache_cache_reset_cell(srv_mediacache_cell_struct *cell, MMI_BOOL include_buffer);

extern void srv_mediacache_decode_schedule(void);

extern srv_mediacache_pre_decode_enum srv_mediacache_decode_default_pre_cb(const WCHAR *filename, void *user_data);

extern void srv_mediacache_cache_fill_cell_by_img(S32 img_width, S32 img_height,srv_mediacache_cell_struct *cache_cell);

#if defined(__SRV_MEDIACACHE_DB_SUPPORT__)
static MMI_BOOL srv_mediacache_db_cancel_get_img(ivd_db_handle_struct *db_handle);
#endif

static void srv_mediacache_cache_fill_index_to_link(srv_mediacache_cell_struct *curr_p, S32 curr_index, S32 file_count);

static void srv_mediacache_cache_index_print_dbgtrace(void);
static void srv_mediacache_save_to_db_schedule(void);
static void srv_mediacache_save_to_db_callback(S32 err, void *user_data);
static void srv_mediacache_resume_decode_with_delay(srv_mediacache_cntx_struct* handle);
static S32 srv_mediacache_get_img_to_layer_internal(srv_handle handle, U32 index, srv_mediacache_img_to_layer_struct *area, MMI_BOOL is_blocking);

#endif /* __MMI_SRV_MEDIACACHE__ */
#endif /* _MEDIACACHE_SRV_H_ */ 

