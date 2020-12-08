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
 *  vadp_mediawall.h
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
 *      Pluto APP ---> p2v adaptor ---> Venus APP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VADP_V2P_MEDIAWALL_H__
#define __VADP_V2P_MEDIAWALL_H__

#include "MMI_features.h"
#ifdef __MMI_VUI_MEDIAWALL__

#include "vfx_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "MediaCacheSrvGprot.h"
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "kal_general_types.h"


//#define __MMI_VUI_MEDIAWALL_LITE_DISPLAY__

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__) && defined(__MAUI_SOFTWARE_LA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define VAPP_MEDIAWALL_START_LOGGING(_symbol_)
#define VAPP_MEDIAWALL_STOP_LOGGING(_symbol_)
#endif
/**********************************************************************
 * Enumeration definition:
 **********************************************************************/
typedef enum
{
    VADP_MEDIAWALL_PORTRAIT, 
    VADP_MEDIAWALL_LANDSCAPE  
} vadp_mediawall_direct_enum;

enum
{   
    VADP_MEDIAWALL_NO_SERVICE = -0x00222222,
    VADP_MEDIAWALL_DRM_LOCKED = -0x00333333    
};

/**********************************************************************
 * Structure Definitions:
 **********************************************************************/
typedef struct
{
    S32 cell_width;
    S32 cell_height;
    S32 cellnum_per_row;
    S32 cellcount;
    S32 highlight_idx;
    S32 cell_inner_x;
    S32 cell_inner_y;
    S32 is_lsk_on;
    U16 title_string_id;
} vadp_mediawall_init_struct;


typedef struct
{
    S32 info_type;                          /* Type of this item DRV or FILE */
    U32 drv_ratio;                          /* When it's a DRV item, the ratio of this drv */
    PU8 file_icon_ptr;                      /* Default image pointer */
    S8  file_name[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN+1)*2]; /* Only filename not full path */
    MMI_BOOL is_show_thumb;                 /* If show this image as a thumb image */       
} vapp_mediawall_fmgr_file_data_struct;


typedef struct
{
    S32 display_index;
    S32 highlight_index;
    S32 current_view_count;
} vadp_mediawall_view_info_struct;


typedef struct
{
    void* app_mem_buf_p;
    S32 app_mem_buf_size;
    void* med_mem_buf_p;
    S32 med_mem_buf_size;
} vadp_mediawall_memory_struct;

typedef void (*vapp_get_file_info_callback)(S32 item_idx, BOOL is_hilighted, vapp_mediawall_fmgr_file_data_struct *file_info);
typedef S32 (*vapp_get_file_path_callback)(S32 item_idx, S8 *file_path, S32 file_path_size);
typedef void (*vapp_mediawall_memory_release_callback)(void);
typedef void (*vapp_mediawall_memory_allocate_callback)(vadp_mediawall_memory_struct* mem_info);
typedef void(*vapp_mediawall_decode_callback)(void*, S32, S32);
/**********************************************************************
 * External Interfaces:
 **********************************************************************/
extern void vapp_mediawall_cat(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 num_of_items,
        S32 highlighted_item,
        S32 display_index,
        S8 *folder_path,
        U32 folder_path_length,        
        vapp_get_file_info_callback get_fileinfo_cb,
        vapp_get_file_path_callback get_filepath_cb,
        U8 *history_buffer);

extern void vapp_mediawall_vcat_get_view_info(vadp_mediawall_view_info_struct *view_info);

extern MMI_BOOL vapp_mediawall_set_softkey(U16 type, U16 str_id, U16 icon_id);

extern void vadp_mediawall_set_highlight(VfxS32 value);

extern void vadp_mediawall_lsk_up(void);

extern void vadp_mediawall_rsk_up(void);

extern MMI_BOOL vadp_mediawall_srv_get_filename(VfxS32 index, void *buffer, VfxU32 length);

extern S32 vadp_mediawall_srv_get_lock_image_buffer(S32 index, srv_mediacache_image_source_enum source, void** buffer);

extern S32 vadp_mediawall_srv_get_lock_image_buffer_nonblocking(
        void *user_data, 
        S32 index,
        vapp_mediawall_decode_callback callback, void** buffer_pp);

extern void vadp_mediawall_srv_free_image_buffer(S32 index, void* buffer);

extern void vadp_mediawall_srv_pause_bgdecode(void);

extern void vadp_mediawall_srv_resume_bgdecode(void);

extern void vapp_mediawall_set_direction(vadp_mediawall_direct_enum direction);

extern void vapp_mediawall_set_memory_notify_cb(
    vapp_mediawall_memory_allocate_callback allocate_callback, 
    vapp_mediawall_memory_release_callback release_callack);

extern void vapp_mediawall_set_memory(vadp_mediawall_memory_struct memory_info);

extern vadp_mediawall_direct_enum vapp_mediawall_get_direction(void);

extern void vadp_mediawall_check_is_mediachange(void);
#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_VUI_MEDIAWALL__ */
#endif /* __VADP_V2P_MEDIAWALL_H__ */
