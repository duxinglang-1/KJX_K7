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
 *  MediaCacheSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MEDIALIB Cache Srv header file for extern call
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MEDIACACHE_SRV_GPROT_H_
#define _MEDIACACHE_SRV_GPROT_H_
#if defined(__MMI_SRV_MEDIACACHE__)
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "custom_events_notify.h"
#include "FileMgrSrvGProt.h"
#include "mediacachesrvmem.h"
#include "mmi_frm_events_gprot.h"

#ifndef srv_handle
/*service handle*/
typedef S32* srv_handle;  /*will add laters*/
#endif

#define SRV_MEDIACACHE_META_SLICE_SIZE  (340 * 1024)

//#define __SRV_MEDIACACHE_CHECK_DIMENSION__
#define __SRV_MEDIACACHE_PUT_HIGH_PRIORITY__
#if defined(__SQLITE3_SUPPORT__) && (defined(__MMI_IMAGE_VIEWER_EX_DB__) || defined(__MMI_FTO_GALLERY__))
#ifndef __SRV_MEDIACACHE_DB_SUPPORT__
#define __SRV_MEDIACACHE_DB_SUPPORT__
#endif
#endif

#if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
#define __MMI_MEDIA_CACHE_YUV_THUMB__
#endif

//#ifndef WIN32
//#define __MM_DEBUG_MEASURE_SRVMC__
//#endif
//#define __SRV_MEDIACACHE_DEBUG_MEASURE__

#if defined(__MM_DEBUG_MEASURE_SRVMC__)
    #ifndef __SRV_MEDIACACHE_DEBUG_MEASURE__
    #define __SRV_MEDIACACHE_DEBUG_MEASURE__
    #endif
    #include "SST_sla.h"
    #ifndef _SST_SLA_
    extern void SLA_CustomLogging(kal_char *customJob, kal_int32 saAction); 
    #endif

    #define SRV_MEDIACACHE_START_MEASURE(_symbol_) \
    SLA_CustomLogging(##_symbol_##, 1)
    #define SRV_MEDIACACHE_STOP_MEASURE(_symbol_) \
    SLA_CustomLogging(##_symbol_##, 0)
    #define SRV_MEDIACACHE_MEAS_DEC(_symbol_) U32 _symbol_ = 0
    #define SRV_MEDIACACHE_MEAS_START(_symbol_) kal_get_time(&##_symbol_)
    #define SRV_MEDIACACHE_MEAS_STOP(_symbol_)  \
        {                                       \
        U32 _symbol_##temp = 0;                 \
        kal_get_time(&##_symbol_##temp);        \
        _symbol_ = _symbol_##temp - _symbol_;   \
        }
#else
    #define SRV_MEDIACACHE_START_MEASURE(_symbol_)
    #define SRV_MEDIACACHE_STOP_MEASURE(_symbol_)
    #define SRV_MEDIACACHE_MEAS_DEC(_symbol_)
    #define SRV_MEDIACACHE_MEAS_START(_symbol_)
    #define SRV_MEDIACACHE_MEAS_STOP(_symbol_)
#endif 


/*The enum of cache type*/
typedef enum
{
    SRV_MEDIACACHE_CACHE_TYPE_UNUSED = 0,    /*service mode internal use only*/
    SRV_MEDIACACHE_CACHE_TYPE_LARGE,          /*the cache is for large image*/
    SRV_MEDIACACHE_CACHE_TYPE_L1,            /*the cache is for level 1 image, LCD size for store clear image*/
    SRV_MEDIACACHE_CACHE_TYPE_L2,            /*the cache is for level 2 image, 1/4 LCD size for cache prev/next n image*/
    SRV_MEDIACACHE_CACHE_TYPE_END
} srv_mediacache_cache_type_enum;

typedef enum srv_mediacache_schedule_policy
{
    SRV_MEDIACACHE_CACHE_METHOD_DEFAULT = 0, /*buffer large first then L1 then L2*/ /*ping pang check*/
    SRV_MEDIACACHE_CACHE_METHOD_M1,          /*not support yet*/                    /* right direction check */
    SRV_MEDIACACHE_CACHE_METHOD_END
} srv_mediacache_schedule_policy;

/*The enum of error code*/
typedef enum
{
    SRV_MEDIACACHE_OK = 0,                   /*0 Get image OK*/
    SRV_MEDIACACHE_OK_FROM_DB,               /*1 Get from database*/
    SRV_MEDIACACHE_OK_LARGE,                 /*2 return for srv_mediacache_can_draw_curr*/
    SRV_MEDIACACHE_OK_L1,                    /*3 return for srv_mediacache_can_draw_curr*/
    SRV_MEDIACACHE_OK_L2,                    /*4 return for srv_mediacache_can_draw_curr*/
    SRV_MEDIACACHE_ERR_DECODING = -188000,   /*-188000 The image is decoding*/
    SRV_MEDIACACHE_ERR_UNKNOW,               /*-187999 errors not classed*/
    SRV_MEDIACACHE_ERR_BUF_ALREDY_IN_CACHE,  /*-187998 Add same cache*/
    SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE,     /*-187997 Not enough cache*/
    SRV_MEDIACACHE_ERR_USER_CANCEL_DECODE,   /*-187996 The picture decode is canceled by APP*/
    SRV_MEDIACACHE_ERR_NOT_SUPPORT,          /*-187995 The image not surpport*/
    SRV_MEDIACACHE_ERR_SOURCE_AREA,          /*-187994 source area set error*/
    SRV_MEDIACACHE_ERR_NOT_READY,            /*-187993 The image not ready at selected source*/
    SRV_MEDIACACHE_ERR_CACHE_NOT_READY = SRV_MEDIACACHE_ERR_NOT_READY,/*not use SRV_MEDIACACHE_ERR_CACHE_NOT_READY will remove*/
    SRV_MEDIACACHE_ERR_BUFFER_NOT_FOUND,     /*-187992 want remove or unlock not exist buffer*/
    SRV_MEDIACACHE_ERR_IES_PREVIEW_FAIL,     /*-187991 IES create preview fail*/
    SRV_MEDIACACHE_ERR_IES_RENDER_FAIL,      /*-187990 IES render fail*/
    SRV_MEDIACACHE_ERR_IES_ANIM_RUN_FAIL,    /*-187989 IES animation run fail*/
    SRV_MEDIACACHE_ERR_IES_ANIM_END_FAIL,    /*-187988 IES animation end fail*/
    SRV_MEDIACACHE_ERR_IES_SET_PAN_FAIL,     /*-187987 IES set pan fail*/
    SRV_MEDIACACHE_ERR_IES_FORCE_RENDER_FAIL,/*-187986 IES force render fail*/
    SRV_MEDIACACHE_ERR_IES_IMAGE_CREATE_FAIL,
    SRV_MEDIACACHE_ERR_IES_META_CREATE_FAIL,
    SRV_MEDIACACHE_ERR_IES_PREVIEW_GET_SIZE_FAIL,
    SRV_MEDIACACHE_ERR_IES_PREVIEW_GET_RECT_FAIL,
    SRV_MEDIACACHE_ERR_IES_NO_PREVIEW_HANDLE,
    
    SRV_MEDIACACHE_ERR_END
} srv_mediacache_err_enum;


/*The enum of error group*/
typedef enum
{
    SRV_MEDIACACHE_ERR_GROUP_OK = 0,        /* no error */
    SRV_MEDIACACHE_ERR_GROUP_MEDIACACHE,    /* error from media cache */
    SRV_MEDIACACHE_ERR_GROUP_GDI,           /* error from GDI */
    SRV_MEDIACACHE_ERR_GROUP_IES,           /* error from Scalado */
    SRV_MEDIACACHE_ERR_GROUP_FS,            /* error from file system */
    SRV_MEDIACACHE_ERR_GROUP_APP,           /* error from APP */
    SRV_MEDIACACHE_ERR_GROUP_END
} srv_mediacache_err_group_enum;

/*The enum of is cancel predecode*/
typedef enum
{
    SRV_MEDIACACHE_PRE_DECODE_CANCEL_THIS = 0,  /* cancel this decode */
    SRV_MEDIACACHE_PRE_DECODE_CONTINUE,         /* continue to decode */
    SRV_MEDIACACHE_PRE_DECODE_END
} srv_mediacache_pre_decode_enum;


/*The enum the image source*/
typedef enum
{
    SRV_MEDIACACHE_IMAGE_SOURCE_CACHE = 0,                      /* get image from cache */
    SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE,             /* get image from cache, if don't have, get from database */
    SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE,  /* get image from cache, if don't have, get from database, if do not have, get it from decode now */
    SRV_MEDIACACHE_IMAGE_SOURCE_END
} srv_mediacache_image_source_enum;


/*The enum the mediacache events*/
typedef enum
{
    SRV_MEDIACACHE_EVENTS_GET_FILENAME_ERR = 0, /* get file name error event */
} srv_mediacache_events_enum;


/*The enum the mediacache events*/
typedef struct
{
    S32 file_index;         /* file index */
    S32 error_code;         /* error code */
} srv_mediacache_evt_get_filename_err_struct;



/*****************************************************************************
* <GROUP  CallBackFunctions>
*
* FUNCTION
*    srv_mediacache_data_cb
* DESCRIPTION
*  get image data callback handler, called when get image finished.
* PARAMETERS
*  err_group :      [IN]  the group of error.
*  err_code  :      [IN]  the error code.
*  user_data :      [IN]  user data.
* RETURNS
*  None.
*****************************************************************************/
typedef void (*srv_mediacache_data_cb)(S32 err_group,S32 err_code, void *user_data);


/*****************************************************************************
* <GROUP  CallBackFunctions>
*
* FUNCTION
*    srv_mediacache_events_cb
* DESCRIPTION
*  service events callback handler, called when events happen.
* PARAMETERS
*  index    :      [IN]  the index of list.
*  buffer   :      [IN]  buffer for app store filepath to.
*  length   :      [IN]  the buffer length.
* RETURNS
*  0 OK.
*  other error code
*****************************************************************************/
typedef S32 (*srv_mediacache_events_cb)(srv_mediacache_events_enum evt, void* param, void *user_data);


/*****************************************************************************
* <GROUP  CallBackFunctions>
*
* FUNCTION
*    srv_mediacache_get_filename_cb
* DESCRIPTION
*  when service need get file will call this.
* PARAMETERS
*  index    :      [IN]  the index of list.
*  buffer   :      [IN]  buffer for app store filepath to.
*  length   :      [IN]  the buffer length.
* RETURNS
*  0 OK.
*  other error code
*****************************************************************************/
typedef S32 (*srv_mediacache_get_filename_cb)(S32 index, WCHAR *buffer, U32 length, void *user_data);


/*****************************************************************************
* <GROUP  CallBackFunctions>
*
* FUNCTION
*    srv_mediacache_pre_decode_enum
* DESCRIPTION
*  before decode will call this and user can cancel the decode by return cancel.
* PARAMETERS
*  filename :     [IN]  the file will be decoded.
* RETURNS
*  SRV_MEDIACACHE_PRE_DECODE_CANCEL_THIS  decode will continue
*  SRV_MEDIACACHE_PRE_DECODE_CONTINUE     means user will cancel the decode process of this one (change to Continue or cancel)
*****************************************************************************/
typedef srv_mediacache_pre_decode_enum (*srv_mediacache_pre_decode_cb)(const WCHAR* filepath, void *user_data);

/*Structure of a rectangle*/
typedef struct
{
    S32 x;                  /* offset x */
    S32 y;                  /* offset y */
    S32 width;              /* rect width */
    S32 height;             /* rect height */
} srv_mediacache_rect_struct;/*check if can change to GDI rect*/

#ifdef __SCALADO_SUPPORT__
/* enums of scalado image rotations */
typedef enum srv_mediacache_rotation_step
{
    SRV_MEDIACACHE_ROTATION_0,      /* rotate 0 angle */
    SRV_MEDIACACHE_ROTATION_90,     /* rotate 90 angle */
    SRV_MEDIACACHE_ROTATION_180,    /* rotate 180 angle */
    SRV_MEDIACACHE_ROTATION_270     /* rotate 270 angle */
}srv_mediacache_rotation_step;

/* enums of scalado actions */
typedef enum srv_mediacache_anim_hint
{
    SRV_MEDIACACHE_ANIM_HINT_NEUTRAL = 0,   /* just render image */
    SRV_MEDIACACHE_ANIM_HINT_RUNNING,       /* render animation */
    SRV_MEDIACACHE_ANIM_HINT_ROTATION,      /* render rotation */
    SRV_MEDIACACHE_ANIM_HINT_PAN,           /* render move */
    SRV_MEDIACACHE_ANIM_HINT_FORCE_FLUSH,   /* force to render immediately */
    SRV_MEDIACACHE_ANIM_HINT_END
} srv_mediacache_anim_hint;
#endif

/*Structure of service get image to layer*/
typedef struct
{
    srv_mediacache_rect_struct    dst;        /*area of destination*/
    srv_mediacache_rect_struct    src;        /*source area*/
    gdi_handle                  dst_layer;          /* dest layer */
    srv_mediacache_data_cb        callback;         /* get image callback */
    srv_mediacache_image_source_enum      source;   /* you hope the image decode from ? */
    void                        *user_data;         /* user data */
#ifdef __SCALADO_SUPPORT__
    srv_mediacache_anim_hint anim_hint;             /* hint for speed-quality trade-off */
    float zoom_target;                              /* target zoom rate */
    float anim_progress;                            /* hope curr zoom rate */
    srv_mediacache_rotation_step rotation_step;     /* rotate angle */
    S32 delta_x;                                    /* move delta x, for pen move */
    S32 delta_y;                                    /* move delta x, for pen move */
#endif
} srv_mediacache_img_to_layer_struct;


/*Structure of service get cache cell*/
typedef struct
{
    U32    decode_ticks;                            /* image decode times */
    U32    db_search_ticks;                         /* search time from DB */
    MMI_BOOL    is_from_db;                         /* from DB or not */
} srv_mediacache_cell_info_struct;


/*Structure of service get image data to buffer*/
typedef struct
{
    void                    *buffer;    /*pointer of buffer app want srv fill to*/
    U32                     length;     /*buffer length*/    
    S32                     width;      /*width for raw*/
    S32                     height;     /*height for raw*/
    srv_mediacache_image_source_enum      source;   /* you hope the image decode from ? */
    srv_mediacache_data_cb    callback;             /* get image callback */
    void                    *user_data;             /* user data */
} srv_mediacache_img_to_buffer_struct;


/*Structure of service get image buffer address and lock it*/
typedef struct
{
    void                    *buffer;    /*pointer of buffer srv will fill this*/
    U32                     length;     /*buffer length srv will fill this*/    
    srv_mediacache_image_source_enum  source;   /* you hope the image decode from ? */
    srv_mediacache_data_cb    callback;         /* get image callback */
    void                    *user_data;         /* user data */
} srv_mediacache_lock_img_buffer_addr_struct;


/*Structure of service get image infomation*/
typedef struct
{
    S32                    org_width;           /* original image width */
    S32                    org_height;          /* original image height */
    S32                    resized_width;       /* image width in buffer */
    S32                    resized_height;      /* image height in buffer */
    MMI_BOOL               is_cached;           /* cell can draw or not */
} srv_mediacache_get_img_info_struct;


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_create
 * DESCRIPTION
 *  service create function.
 * PARAMETERS
 *  run_buf     :  [IN]  the buffer for srv run
 *  length      :  [IN]  the length of buffer.
 * RETURNS
 *  srv_handle the service handle.
 *****************************************************************************/
extern srv_handle srv_mediacache_create(void *run_buf, U32 length);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_work_mode_to_filelist
 * DESCRIPTION
 *  config the service work mode to filelist, so when you pass list to service it will help you decode.
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  filelist    :  [IN]  file list handle.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_work_mode_to_filelist(srv_handle handle, SRV_FMGR_FILELIST_HANDLE filelist);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_work_mode_to_filename
 * DESCRIPTION
 *  config the service work mode to filename, so service will only help you decode one image.
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  filename    :  [IN]  image file name with path.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_work_mode_to_filename(srv_handle handle, const WCHAR *filename);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_level2_size
 * DESCRIPTION
 *  config level 2 image width and height so service will only decode the image to this size and clip it.
 * PARAMETERS
 *  handle          :  [IN]  srv handle.
 *  img_width       :  [IN]  buffer width.
 *  img_height      :  [IN]  buffer height.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_level2_size(srv_handle handle, U32 img_width, U32 img_height);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_work_mode_to_prefetch_func
 * DESCRIPTION
 *  config service to prefetch function mode so before each decode service will call your function to get filename and decode it.
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  num_all     :  [IN]  the number of images.
 *  callback    :  [IN]  get filename callback.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_work_mode_to_prefetch_func(srv_handle handle, S32 num_all, srv_mediacache_get_filename_cb callback);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_work_mode_to_prefetch_func
 * DESCRIPTION
 *  config service to prefetch function mode so before each decode service will call your function to get filename and decode it.
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  num_all     :  [IN]  the number of images.
 *  id_array_p  :  [IN]  id array and must not form stack, service will use it at service life cycle.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_work_mode_to_id_array(srv_handle handle, S32 num_all, U16 *id_array_p);


/*****************************************************************************
* <GROUP  CallBackFunctions>
*
* FUNCTION
*    srv_mediacache_engine_clip
* DESCRIPTION
*  get image clip callback handler, called let user set image clip to image.
* PARAMETERS
*  handle       :      [IN]     srv handle.
*  layer_w      :      [OUT]    layer width.
*  layer_h      :      [OUT]    layer height.
*  img_org      :      [IN]     image info.
*  img_resized  :      [OUT]    image size wants to decode.
*  user_data    :      [IN]     user data.
* RETURNS
*  None.
*****************************************************************************/
typedef void (*srv_mediacache_engine_clip)(U32* handle, S32 *layer_w, S32 *layer_h, srv_mediacache_rect_struct *img_org, srv_mediacache_rect_struct *img_resized, void *user_data);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_destory
 * DESCRIPTION
 *  service destory function.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_destroy(srv_handle handle);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_remove_add
 * DESCRIPTION
 *  add cache to service function.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  type    :  [IN]  buffer type.
 *  buffer  :  [IN]  the buffer pointer.
 *  length  :  [IN]  the buffer length.
 * RETURNS
 *  None.
 *****************************************************************************/
extern S32 srv_mediacache_add_cache(srv_handle handle, srv_mediacache_cache_type_enum type, void *buffer, U32 length);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_remove_cache
 * DESCRIPTION
 *  remove cache from service.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  buffer  :  [IN]  the buffer pointer.
 *  length  :  [IN]  the buffer length.
 * RETURNS
 *  SRV_MEDIACACHE_OK: remove ok.
 *****************************************************************************/
extern S32 srv_mediacache_remove_cache(srv_handle handle, void *buffer);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_start
 * DESCRIPTION
 *  start the service.
 * PARAMETERS
 *  handle          :  [IN]  srv handle.
 *  start_index     :  [IN]  the index start cache.
 * RETURNS
 *  SRV_MEDIACACHE_OK: start ok.
 *****************************************************************************/
extern S32 srv_mediacache_start(srv_handle handle, S32 start_index); /*return error not assert when no cache*/


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_pause_decode
 * DESCRIPTION
 *  pause the service.
 * PARAMETERS
 *  handle    :  [IN]  service handle.
 * RETURNS
 *  SRV_MEDIACACHE_OK: start ok.
 *****************************************************************************/
extern S32 srv_mediacache_pause_decode(srv_handle handle);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_resume_decode
 * DESCRIPTION
 *  resume the service.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  start_flist_index    :  [IN]  current file index set to service.
 * RETURNS
 *  SRV_MEDIACACHE_OK: start ok.
 *****************************************************************************/
extern S32 srv_mediacache_resume_decode(srv_handle handle);


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_stop
 * DESCRIPTION
 *  stop the service.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_stop(srv_handle handle);


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_get_img_to_buffer
 * DESCRIPTION
 *  get an area of the image to buffer with resize
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  index   :  [IN]  the index of image want to get
 *  buf     :  [IN]  setting of source area and destination area
 * RETURNS
 *  SRV_MEDIACACHE_OK: Action OK.
 *  SRV_MEDIACACHE_ERR_DECODING: the file is not at cache.
 *****************************************************************************/
extern S32 srv_mediacache_get_img_to_buffer(srv_handle handle, U32 index, srv_mediacache_img_to_buffer_struct *buf);


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_get_img_to_buffer
 * DESCRIPTION
 *  get an area of the image to buffer with resize
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  index   :  [IN]  the index of image want to get
 *  buf     :  [IN]  setting of source area and destination area
 * RETURNS
 *  SRV_MEDIACACHE_OK: Action OK.
 *  SRV_MEDIACACHE_ERR_DECODING: the file is not at cache.
 *****************************************************************************/
extern S32 srv_mediacache_lock_img_buffer_addr(
                            srv_handle handle, 
                            U32 index, 
                            srv_mediacache_lock_img_buffer_addr_struct *buf);


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_get_img_to_buffer
 * DESCRIPTION
 *  unlock a buffer
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  buffer  :  [IN]  the buffer of image for unlock
 * RETURNS
 *  SRV_MEDIACACHE_OK: Action OK.
 *****************************************************************************/
extern S32 srv_mediacache_unlock_img_buffer(srv_handle handle, void *buffer);


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_get_curr_file_index
 * DESCRIPTION
 *  get current file index.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 * RETURNS
 *  current index of file.
 *****************************************************************************/
extern S32 srv_mediacache_get_curr_index(srv_handle handle);


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_get_last_err
 * DESCRIPTION
 *  get service last error code and group.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  err_group: [OUT] error group.
 *  err_code:  [OUT] error code.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_get_last_err(srv_handle handle,S32 *err_group, S32 *err_code);


/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_can_draw_curr
 * DESCRIPTION
 *  Check if current file can draw.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 * RETURNS
 *  MMI_IVSRV_ERR_CACHE_NOT_READY:    Can't draw.
 *  SRV_MEDIACACHE_OK_LARGE:    Can get from large cache.
 *  SRV_MEDIACACHE_OK_L1:       Can get from L1 cache.
 *  SRV_MEDIACACHE_OK_L2:       Can get from L2 cache.
 *****************************************************************************/
extern srv_mediacache_err_enum srv_mediacache_can_draw_curr(srv_handle handle);
    
    
/*****************************************************************************
 * FUNCTION
 *    SRV_MEDIACACHE_retry_decode_curr
 * DESCRIPTION
 *  srv will call this before decode each file
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  callback    :  [IN]  pre decode callback.
 *  user_data   :  [IN]  user data will bring back at callback.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_register_pre_decode_cb(srv_handle handle, srv_mediacache_pre_decode_cb callback, void *user_data);

/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_get_img_to_layer
 * DESCRIPTION
 *  get image and resizer to a layer
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  index   :  [IN]  
 *  area    :  [IN]  
 * RETURNS
 *  SRV_MEDIACACHE_OK: get to layer OK.
 *  SRV_MEDIACACHE_ERR_DECODING: the one we try to get is decoding.
 *****************************************************************************/
extern S32 srv_mediacache_get_img_to_layer(srv_handle handle, U32 index, srv_mediacache_img_to_layer_struct *area);

/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_get_err_string
 * DESCRIPTION
 *  get error string
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  err_group   :  [IN]  error group
 *  err_code    :  [IN]  error code
 *  popup_type  :  [IN]  popup error type
 * RETURNS
 *  SRV_MEDIACACHE_OK: Action OK.
 *****************************************************************************/
extern MMI_ID_TYPE srv_mediacache_get_err_string(srv_handle handle, S32 err_group,S32 err_code, mmi_event_notify_enum* popup_type);

/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_goto_index
 * DESCRIPTION
 *  let service decode from this index
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  index   :  [IN]  the index
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_goto_index(srv_handle handle, S32 index);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_get_image_info
 * DESCRIPTION
 *  get image infomation
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  index       :  [IN]  index
 *  img_info    :  [IN]  image info
 * RETURNS
 *  SRV_MEDIACACHE_OK: Action OK.
 *  SRV_MEDIACACHE_ERR_NOT_READY: the index is not decoded
 *****************************************************************************/
extern S32 srv_mediacache_get_image_info(srv_handle handle, S32 index, srv_mediacache_get_img_info_struct* img_info);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_cell_can_draw_by_index
 * DESCRIPTION
 *  check the index of image if decode done.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  index   :  [IN]  index.
 * RETURNS
 *  SRV_MEDIACACHE_OK_LARGE: can draw from large.
 *  SRV_MEDIACACHE_OK_L1: can draw from level 1 cache.
 *  SRV_MEDIACACHE_OK_L2: can draw from level 2 cache.
 *  SRV_MEDIACACHE_ERR_NOT_READY: not decode ready
 *****************************************************************************/
extern srv_mediacache_err_enum srv_mediacache_cell_can_draw_by_index(srv_handle handle, S32 index);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_database_store_group
 * DESCRIPTION
 *  config the group of cache should store to database.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  group   :  [IN]  set the cache group you want store to database
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_database_store_group(srv_handle handle, U32 group);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_color_format
 * DESCRIPTION
 *  set the color format service should use to decode image.
 * PARAMETERS
 *  handle          :  [IN]  srv handle.
 *  color_format    :  [IN]  the color format let service use
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_color_format(srv_handle handle, U8 color_format);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_db
 * DESCRIPTION
 *  service database config function.
 * PARAMETERS
 *  handle  :  [IN]  srv handle.
 *  buffer  :  [IN]  buffer for database use.
 *  length  :  [IN]  buffer length.
 *  path    :  [IN]  file path.
 *  name    :  [IN]  database name of cache.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_db(srv_handle handle, void* buffer, U32 length, WCHAR *path, WCHAR *name);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_register_events_cb
 * DESCRIPTION
 *  register events callback of service, when the event happen the function will be called.
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  callback    :  [IN]  the callback function will called when event happen.
 *  user_data   :  [IN]  bring back at callback
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_register_events_cb(srv_handle handle,srv_mediacache_events_cb callback,void *user_data);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_blocking_get_first
 * DESCRIPTION
 *  Let service blocking search first image at database, no any impact to other things.
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  is_enable   :  [IN]  is this should enable
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_blocking_get_first(srv_handle handle, MMI_BOOL is_enable);


/*****************************************************************************
 * FUNCTION
 *    srv_mediacache_config_image_decode_and_get_source
 * DESCRIPTION
 *  let user to config, if he want to use scalado to decode first.
 * PARAMETERS
 *  handle      :  [IN]  srv handle.
 *  is_from_scalado_first   :  [IN]  is this scalado decode first
 *  working_buffer  :   [IN]  optional. If NULL, will use MED for IES working buffer. 
 *  buf_size        :   [IN]  optional. please use SRV_MEDIACACHE_IES_WORKING_BUF_SIZE_WITH_META or SRV_MEDIACACHE_IES_WORKING_BUF_SIZE
 * RETURNS
 *  None.
 *****************************************************************************/
extern void srv_mediacache_config_image_decode_and_get_source(srv_handle handle, MMI_BOOL is_from_ies_first, U8 *working_buffer, U32 buf_size);

extern S32 srv_mediacache_preview_get_current_size(srv_handle handle, S32 *width, S32 *height);
extern S32 srv_mediacache_preview_get_current_rect(srv_handle handle, S32 *pLeft, S32 * pTop, S32 *pWidth, S32*pHeight);

extern void srv_mediacache_config_database_store_cache_type(srv_handle handle, srv_mediacache_cache_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_set_qulity_high
 * DESCRIPTION
 *  set the qulity to high use LRZ resizer. After resize APIs are called, 
 *  restore to default quality automatically.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mediacache_set_qulity_high(void);


/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_set_qulity_low
 * DESCRIPTION
 *  set the qulity to fast, in case too slow. After resize APIs are called, 
 *  restore to default quality automatically.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mediacache_set_qulity_low(void);

extern void srv_mediacache_register_engine_clip_function(srv_mediacache_engine_clip clip_funcion, void *user_data);
extern void srv_mediacache_disable_level2_clip_head(srv_handle handle);
extern void srv_mediacache_enable_clear_bg(MMI_BOOL enable, gdi_color color);
extern void srv_mediacache_ex_define_db_io_buffer_length(U32 length);
extern void srv_mediacache_get_max_decoded_dimension(srv_handle handle, U32 index, S32 *width, S32 *height);
extern S32 srv_mediacache_switch_next(srv_handle handle);
extern S32 srv_mediacache_switch_prev(srv_handle handle);
extern S32 srv_mediacache_get_curr_img_to_layer(srv_handle handle, srv_mediacache_img_to_layer_struct *area);
extern S32 srv_mediacache_get_next_img_to_layer(srv_handle handle, srv_mediacache_img_to_layer_struct *area);
extern S32 srv_mediacache_get_prev_img_to_layer(srv_handle handle, srv_mediacache_img_to_layer_struct *area);
extern S32 srv_mediacache_get_cell_info(srv_handle handle, U32 index, U8 group, srv_mediacache_cell_info_struct* cell_info);
extern void srv_mediacache_config_database(srv_handle handle, void* buffer, U32 length, WCHAR *path);
extern void srv_mediacache_config_schedule_policy(srv_handle handle, srv_mediacache_schedule_policy policy);
extern void srv_mediacache_config_alignment(srv_handle handle, MMI_BOOL use_cache_align);

/*****************************************************************************
 * FUNCTION
 *  srv_mediacache_get_ivd_handle
 * DESCRIPTION
 *  retrieve configured IVD(MediaCacheDaemon) instance.
 *  note the life cycle of IVD is the same as this media cache handle
 * PARAMETERS
 *  handle handle to MediaCache service
 * RETURNS
 *  ivd_db_handle_struct* or NULL
 *****************************************************************************/
extern void* srv_mediacache_get_ivd_handle(srv_handle handle);

#endif /* __MMI_SRV_MEDIACACHE__ */
#endif /* _MEDIACACHE_CACHE_SRV_GPROT_H_ */ 



