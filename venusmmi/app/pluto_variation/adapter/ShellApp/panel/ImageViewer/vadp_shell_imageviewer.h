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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_shell_imageviewer.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Pluto APP <---> adaptor <---> Venus APP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VADP_SEHLL_IMAGEVIEWER_H__
#define __VADP_SEHLL_IMAGEVIEWER_H__

#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_IMAGE_VIEWER__

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "MediaCacheSrvGprot.h"
#include "MMIDataType.h"

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define VAPP_SHELLIV_START_LOGGING(_symbol_)
#define VAPP_SHELLIV_STOP_LOGGING(_symbol_)
#endif


/**********************************************************************
 * Enumeration definition:
 **********************************************************************/
enum
{   
    VADP_SHELLIV_NO_SERVICE = -0x00222222,
    VADP_SHELLIV_DRM_LOCKED = -0x00333333    
};

enum
{   
    VADP_SHELLIV_FILELIST_EMPTY = -1   
};

typedef enum
{
    VADP_SHELLIV_FL_STATE_EXIT = 0,
    VADP_SHELLIV_FL_STATE_READY,
    VADP_SHELLIV_FL_STATE_REFRESHING,
    VADP_SHELLIV_FL_STATE_DELETING,
    VADP_SHELLIV_FL_STATE_DIRTY
}vadp_shell_iv_fl_state_enum;


/**********************************************************************
 * Structure Definitions:
 **********************************************************************/
typedef void(*vapp_shell_imgviewer_decode_callback)(void*, S32, S32);
typedef void(*vapp_shell_imgviewer_list_ready_callback)(void*);
typedef void(*vapp_shell_imgviewer_delete_done_callback)(void*);
typedef void(*vapp_shell_imgviewer_refreshing_filelist_callback)(void*);

/**********************************************************************
 * External Interfaces:
 **********************************************************************/
extern VfxS32 vadp_shell_imgviewer_get_focus_index(void);

extern void vadp_shell_imgviewer_set_focus_index(VfxS32 focus_index);

extern VfxU8 vadp_shell_imgviewer_get_storage();

extern void vadp_shell_imgviewer_set_storage(VfxU8 storage);

extern void vadp_shell_imgviewer_register_list_ready_callback(void* user_data, vapp_shell_imgviewer_list_ready_callback cb);

extern void vadp_shell_imgviewer_register_delete_done_callback(void* user_data, vapp_shell_imgviewer_delete_done_callback cb);

extern VfxS32 vadp_shell_imgviewer_delete_file_nonblocking(VfxU32 index, void* user_data, vapp_shell_imgviewer_delete_done_callback cb);

extern void vadp_shell_imgviewer_withdraw_file(VfxS32 index);

extern void vadp_shell_imgviewer_create_filelist(void);

extern void vadp_shell_imgviewer_free_filelist(void);
    
extern VfxBool vadp_shell_imgviewer_is_list_ready(void);

extern VfxBool vadp_shell_imgviewer_is_filepath_ready(VfxS32 index);

extern VfxU32 vadp_shell_imgviewer_get_file_count(void);

extern VfxU32 vadp_shell_imgviewer_get_folder_path(void);

extern void vadp_shell_imgviewer_cache_srv_start(void);

extern void vadp_shell_imgviewer_cache_srv_close(void);

extern void vadp_shell_imgviewer_cache_srv_pause_bgdecode(void);

extern void vadp_shell_imgviewer_cache_srv_resume_bgdecode(void);

extern S32 vadp_shell_imgviewer_cache_srv_get_lock_image_buffer(S32 index, srv_mediacache_image_source_enum source, void** buffer);

extern S32 vadp_shell_imgviewer_cache_srv_get_lock_image_buffer_nonblocking(
        void *user_data, 
        S32 index,
        vapp_shell_imgviewer_decode_callback callback, void** buffer_pp);

extern void vadp_shell_imgviewer_cache_srv_free_image_buffer(void* buffer);

extern S32 vadp_shell_imgviewer_cache_srv_get_image_info(S32 index, S32 *resized_width, S32 *resized_height);

extern void vadp_shell_imgviewer_cache_srv_register_clip_cb(void *user_data, srv_mediacache_engine_clip cb);

extern void vadp_shell_imgviewer_fit_img(
                VfxS32 dest_w, 
                VfxS32 dest_h, 
                VfxS32 source_w,
                VfxS32 source_h, 
                VfxS32* resized_offset_x, 
                VfxS32* resized_offset_y, 
                VfxS32* resized_width, 
                VfxS32* resized_height);

extern VfxBool vadp_shell_imgviewer_get_image_path_by_index(VfxS32 index, VfxWChar *buffer_ptr, VfxU32 length);

extern void vadp_shell_imgviewer_enter_kernal_app(VfxS32 index);

extern VfxBool vadp_shell_imgviewer_check_is_valid_drv(VfxU8 drv_letter);

extern void vadp_shell_imgviewer_check_filelist(void);

extern void vadp_shell_imgviewer_cache_srv_register_filelist_refresh_cb(void *user_data, vapp_shell_imgviewer_refreshing_filelist_callback cb);

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_VUI_SHELL_IMAGE_VIEWER__ */
#endif /* __VADP_SEHLL_IMAGEVIEWER_H__ */
