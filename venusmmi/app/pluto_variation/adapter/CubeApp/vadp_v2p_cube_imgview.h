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
 *  vadp_v2p_cube_imgview.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VADP_V2P_CUBE_APP_IMGVIEW_H__
#define __VADP_V2P_CUBE_APP_IMGVIEW_H__

#include "MMI_Features.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/**********************************************************************
 * Structure Definitions
 **********************************************************************/
    typedef enum
    {
        VADP_V2P_CUBE_IMGVIEW_FILTER_TPYE_IMAGE = 0,

        VADP_V2P_CUBE_IMGVIEW_FILTER_TPYE_ALL
    } vadp_v2p_cube_imgview_filter_type_enum;

    typedef enum
    {
        VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_NAME = 0,
        VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_TIME,
        VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_TYPE,
        VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_SIZE,
        VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_NONE,

        VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_ALL
    } vadp_v2p_cube_imgview_sort_type_enum;

    typedef void (*vadp_v2p_cube_imgview_file_list_callback) (void *user_data, S32 file_count, S32 sort_state);
    typedef void (*vadp_v2p_cube_imgview_file_decode_callback) (void *user_data, S32 index, void *memory_addr,
                                                                S32 result, S32 mode);

/**********************************************************************
 * External Interfaces
 **********************************************************************/
    extern S32 vadp_v2p_cube_imgview_get_file_list();
    extern S32 vadp_v2p_cube_vapp_imgview_create_file_list(
                void *user_data,
                VfxU16 *path,
                vadp_v2p_cube_imgview_filter_type_enum filter_type,
                vadp_v2p_cube_imgview_sort_type_enum sort_type,
                vadp_v2p_cube_imgview_file_list_callback sort_callback);
    extern void vadp_v2p_cube_vapp_imgview_free_file_list(void);
    extern S32 vadp_v2p_cube_vapp_imgview_get_file_list_count(void);
    extern S32 vadp_v2p_cube_vapp_imgview_get_sort_state(void);
    extern PU16 vadp_v2p_cube_vapp_imgview_get_file_path(S32 index);
    extern void *vadp_v2p_cube_vapp_imgview_get_file_layer_memory(
                    S32 index,
                    S32 target_width,
                    S32 target_height,
                    S32 mode,
                    PS32 result);
    extern void vadp_v2p_cube_imgview_free_file_layer_memory(S32 index, S32 mode);
    extern void vadp_v2p_cube_get_file_layer_real_size(
                    S32 index,
                    PS32 offset_x,
                    PS32 offset_y,
                    PS32 width,
                    PS32 height,
                    S32 mode);
    extern void vadp_v2p_cube_imgview_set_small_image(S32 image_width, S32 image_height);
    extern void vadp_v2p_cube_imgview_set_large_image(S32 image_width, S32 image_height);
    extern void vadp_v2p_cube_imgview_create_cache(void);
    extern void vadp_v2p_cube_imgview_close_cache(void);
    extern void vadp_v2p_cube_imgview_register_decode_cb(
                    void *user_data,
                    vadp_v2p_cube_imgview_file_decode_callback cb);
    extern void vadp_v2p_cube_imgview_get_layer_info(gdi_handle handle, PS32 width, PS32 height);
    extern void vadp_v2p_cube_imgview_change_to_view_mode(S32 index);
    extern void vadp_v2p_cube_imgview_change_to_navigation_mode(S32 index);
    extern void vadp_v2p_cube_imgview_focus_change(S32 index, S32 mode);
    extern void vadp_v2p_cube_imgview_pause_cache(void);
    extern void vadp_v2p_cube_imgview_resume_cache(void);
    extern void vadp_v2p_cube_imgview_pause_navigation_mode_decode(void);
    extern void vadp_v2p_cube_imgview_resume_navigation_mode_decode(void);
    extern U16 vadp_v2p_cube_imgview_get_forbid_item_info(void);

#ifdef __cplusplus
}   /* extern "C" */
#endif 

#endif /* __VADP_V2P_CUBE_APP_IMGVIEW_H__ */ 

