/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_cube_imgview.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Cube Image View Adaptation Layer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VADP_CUBE_APP_IMGVIEW_H__
#define __VADP_CUBE_APP_IMGVIEW_H__

#include "MMI_Features.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    typedef void(*vapp_cube_imgview_decode_callback)(void*, S32, S32);
    typedef void (*vadp_cube_imgview_sort_callback) (void *user_data, S32 file_count, S32 sort_state);
    typedef void (*vadp_cube_imgview_file_decode_callback) (void *user_data, S32 index, void *memory_addr, S32 result,
        S32 mode);

    typedef enum
    {
        VADP_CUBE_IMGVIEW_FILE_DECODE_OVER,
            VADP_CUBE_IMGVIEW_FILE_DECODE_ERROR,
            VADP_CUBE_IMGVIEW_FILE_DECODE_DOING,
            
            VADP_CUBE_IMGVIEW_FILE_DECODE_ALL
    } vadp_cube_imgview_file_decode_result_enum;
    
    typedef enum
    {
        VADP_CUBE_IMGVIEW_SORT_STATE_IDLE = 0,
            VADP_CUBE_IMGVIEW_SORT_STATE_DOING,
            VADP_CUBE_IMGVIEW_SORT_STATE_OVER,
            VADP_CUBE_IMGVIEW_SORT_STATE_INVALID,
            
            VADP_CUBE_IMGVIEW_SORT_STATE_ALL
    } vadp_cube_imgview_sort_state_enum;
    
    typedef enum
    {
        VADP_CUBE_IMGVIEW_MEMORY_SOURCE_UNKNOWN = 0,
            VADP_CUBE_IMGVIEW_MEMORY_SOURCE_APP_MEM,
            VADP_CUBE_IMGVIEW_MEMORY_SOURCE_SCRN_MEM,
            VADP_CUBE_IMGVIEW_MEMORY_SOURCE_GDI_MEM,
            
            VADP_CUBE_IMGVIEW_MEMORY_SOURCE_ALL
    } vadp_cube_imgview_memory_source_enum;
    
    typedef enum
    {
        VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_IDLE,
            VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_WAITING_FOR_DECODE,
            VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODING,
            VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER,
            VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_OVER_BUT_BLUR,
            VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_DECODE_ERROR,
            VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_LOCKING,

            VADP_CUBE_IMGVIEW_CACHE_LAYER_STATE_ALL
    } vadp_cube_imgview_cache_layer_state_enum;
    
    typedef enum
    {
        VADP_CUBE_IMGVIEW_MODE_UNKNOWN = 0,
            VADP_CUBE_IMGVIEW_MODE_NAVIGATION,
            VADP_CUBE_IMGVIEW_MODE_VIEW,
            VADP_CUBE_IMGVIEW_MODE_TURN_TO_BACK,
            VADP_CUBE_IMGVIEW_MODE_TURN_TO_FRONT,
            VADP_CUBE_IMGVIEW_MODE_TURN_TO_BLUR,
            
            VADP_CUBE_IMGVIEW_MODE_ALL
    } vadp_cube_imgview_mode_enum;

    typedef enum
    {
        VADP_CUBE_IMGVIEW_CACHE_STATE_IDLE,
        VADP_CUBE_IMGVIEW_CACHE_STATE_RUNNING,
        VADP_CUBE_IMGVIEW_CACHE_STATE_PAUSE,
        VADP_CUBE_IMGVIEW_CACHE_STATE_CLOSED,
        VADP_CUBE_IMGVIEW_CACHE_STATE_ALL
    } vadp_cube_imgview_cache_state_enum;

    #define VADP_CUBE_IMGVIEW_BUF_COUNT (3)

    typedef struct  
    {
        void *buf_ptr[VADP_CUBE_IMGVIEW_BUF_COUNT];
        MMI_BOOL is_used[VADP_CUBE_IMGVIEW_BUF_COUNT];
        S32 file_index[VADP_CUBE_IMGVIEW_BUF_COUNT];

        void *back_buffer;

        S16 curr_index;
    } vadp_cube_imgview_view_buffer_struct;

    typedef struct
    {
        srv_handle cache_handle;
        vadp_cube_imgview_cache_state_enum cache_state;
        void *cache_run_buffer;
        S32 cache_run_buffer_size;
        void *cache_db_buffer;
        S32 cache_db_buffer_size;
        void *cache_navigation_buffer;
        S32 cache_navigation_buffer_size;
        void *cache_view_buffer;
        S32 cache_view_buffer_size;
        S32 cache_total_memory_size;

        void *menu_ptr;
        vapp_cube_imgview_decode_callback decode_cb;
        
        void *menu_ptr2;
        vapp_cube_imgview_decode_callback decode_cb2;

        S32 navigation_image_width;
        S32 navigation_image_height;
        
        fmgr_filelist_handle fl;
        U16 file_path[(SRV_FMGR_PATH_MAX_LEN+1)];
        S8 curr_drv;
        void *user_data;
        vadp_cube_imgview_sort_callback sort_callback;
        vadp_cube_imgview_sort_state_enum sort_state;

        vadp_cube_imgview_view_buffer_struct view_buffer;
    } vadp_cube_imgview_cntx_struct;

    typedef enum
    {   
        VADP_CUBE_IMGVIEW_ERROR_NO_SERVICE = -222222,
            VADP_CUBE_IMGVIEW_ERROR_IMAGE_LOCKING,

            VADP_CUBE_IMGVIEW_ERROR_FILE_CRASH,
    } vadp_cube_imgview_error_enum;

/**********************************************************************
 * Structure Definitions
 **********************************************************************/
    typedef enum
    {
        VADP_CUBE_IMGVIEW_FILTER_TPYE_IMAGE = 0,

        VADP_CUBE_IMGVIEW_FILTER_TPYE_ALL
    } vadp_cube_imgview_filter_type_enum;

    typedef enum
    {
        VADP_CUBE_IMGVIEW_SORT_TYPE_BY_NAME = 0,
        VADP_CUBE_IMGVIEW_SORT_TYPE_BY_TIME,
        VADP_CUBE_IMGVIEW_SORT_TYPE_BY_TYPE,
        VADP_CUBE_IMGVIEW_SORT_TYPE_BY_SIZE,
        VADP_CUBE_IMGVIEW_SORT_TYPE_BY_NONE,

        VADP_CUBE_IMGVIEW_SORT_TYPE_BY_ALL
    } vadp_cube_imgview_sort_type_enum;

    typedef void (*vadp_cube_imgview_file_list_callback) (void *user_data, S32 file_count, S32 sort_state);
    typedef void (*vadp_cube_imgview_file_decode_callback) (void *user_data, S32 index, void *memory_addr,
                                                                S32 result, S32 mode);

/**********************************************************************
 * External Interfaces
 **********************************************************************/

    extern void vadp_cube_imgview_malloc_cache_buffer(void);
    extern void vadp_cube_imgview_free_cache_buffer(void);
    extern void vadp_cube_imgview_set_l2_image_info(S32 width, S32 height);
    extern void vadp_cube_imgview_create_cache(void);
    extern void vadp_cube_imgview_pause_cache(void);
    extern void vadp_cube_imgview_resume_cache(void);
    extern void vadp_cube_imgview_close_cache(void);
    extern S32 vadp_cube_imgview_get_lock_image_buffer(S32 index, srv_mediacache_image_source_enum source, S32 width, S32 height, void** buffer);
    extern void vadp_cube_imgview_decode_callback(S32 err_group,S32 err_code, void *user_data);
    extern S32 vadp_cube_imgview_get_lock_image_buffer_nonblocking(void *user_data, S32 index, void(*callback)(void*, S32, S32), void** buffer_pp);
    extern void vadp_cube_imgview_free_image_buffer(S32 index, void* buffer);
    extern void vadp_cube_imgview_pause_decode(void);
    extern void vadp_cube_imgview_resume_decode(void);
    extern void vadp_cube_imgview_free_file_list(void);
    extern S32 vadp_cube_imgview_get_file_list_count(void);
    extern S32 vadp_cube_imgview_get_file_list();
    extern S32 vadp_cube_imgview_create_file_list(
        void *user_data,
        PU16 path,
        vadp_cube_imgview_filter_type_enum filter_type,
        vadp_cube_imgview_sort_type_enum sort_type,
                                      vadp_cube_imgview_sort_callback sort_callback);
    extern U16 vadp_cube_imgview_get_forbid_item_info(void);
    extern void vadp_cube_imgview_change_to_view_mode(S32 index);
    extern void vadp_cube_imgview_change_to_navigation_mode(S32 index);
    
    extern void vadp_cube_imgview_get_buffer(S32 size, void **buffer);
    extern void vadp_cube_imgview_free_buffer(void **buffer);
    extern void vadp_cube_imgview_register_clip_callback(srv_mediacache_engine_clip cb, void *user_data);
    extern void vadp_cube_imgview_fit_view_cell(S32 dest_w, S32 dest_h, S32 source_w, S32 source_h, PS32 x, PS32 y, PS32 w, PS32 h);
    extern S32 vadp_cube_imgview_get_image_info(S32 index, PS32 org_width, PS32 ori_height, PS32 resize_width, PS32 resize_height);
    extern S32 vadp_cube_imgview_get_image_buffer(S32 index, S32 dest_width, S32 dest_height, PS32 dest_resize_w, PS32 dest_resized_h, void **buffer, PS32 source);
    extern void vadp_cube_imgview_view_mode_free_image_buffer(S32 index, void *buffer);
    extern S32 vadp_cube_imgview_get_image_buffer_nonblocking(void *menu_ptr, S32 index, S32 dest_width, S32 dest_height, PS32 dest_resize_w, PS32 dest_resized_h, void **buffer, PS32 source, void(*callback)(void*, S32, S32));
    extern void vadp_cube_imgview_focus_change(S32 index);

#ifdef __cplusplus
}   /* extern "C" */
#endif 

#endif /* __VADP_CUBE_APP_IMGVIEW_H__ */ 

