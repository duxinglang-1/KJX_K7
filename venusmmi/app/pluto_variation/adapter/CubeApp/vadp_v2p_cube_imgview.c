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
 *  vadp_v2p_cube_imgview.c
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

#include "MMI_features.h"

#ifdef __MMI_VUI_3D_CUBE_APP_IMGVIEW__

#include "ui_core\base\vfx_datatype.h"
#include "FileMgrGProt.h"
#include "ImageViewerGprot.h"

#include "MediaCacheSrvGprot.h"
#include "cubeApp\vapp_cube_imgview_config.h"
#include "CubeAppImgview.h"
#include "vadp_v2p_cube_imgview.h"


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_get_file_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 vadp_v2p_cube_imgview_get_file_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_cube_imgview_get_file_list();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_imgview_create_file_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data           [?]         
 *  path                [?]         
 *  filter_type         [IN]        
 *  sort_type           [IN]        
 *  sort_callback       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_v2p_cube_vapp_imgview_create_file_list(
        void *user_data,
        VfxU16 *path,
        vadp_v2p_cube_imgview_filter_type_enum filter_type,
        vadp_v2p_cube_imgview_sort_type_enum sort_type,
        vadp_v2p_cube_imgview_file_list_callback sort_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tmp_path[FMGR_MAX_PATH_LEN];
    FMGR_FILTER filter;
    U16 sort_type_internal;
    S32 file_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filter_type == VADP_V2P_CUBE_IMGVIEW_FILTER_TPYE_IMAGE)
    {
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);

        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ANM);
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_EMS);
    }

    switch (sort_type)
    {
        case VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_NAME:
            sort_type_internal = FS_SORT_NAME;
            break;

        case VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_TIME:
            sort_type_internal = FS_SORT_TIME;
            break;

        case VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_TYPE:
            sort_type_internal = FS_SORT_TYPE;
            break;

        case VADP_V2P_CUBE_IMGVIEW_SORT_TYPE_BY_SIZE:
            sort_type_internal = FS_SORT_TYPE;
            break;

        default:
            sort_type_internal = FS_NO_SORT;
            break;
    }

    if (path == NULL)
    {
        mmi_imgview_get_storage_file_path((PS8) tmp_path);
    }

    return mmi_cube_imgview_create_file_list(user_data, tmp_path, filter, sort_type_internal, sort_callback);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_imgview_free_file_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_vapp_imgview_free_file_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_free_file_list();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_imgview_get_file_list_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_v2p_cube_vapp_imgview_get_file_list_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_cube_imgview_get_file_count();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_imgview_get_sort_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 vadp_v2p_cube_vapp_imgview_get_sort_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_cube_imgview_get_sort_state();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_imgview_get_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
PU16 vadp_v2p_cube_vapp_imgview_get_file_path(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_cube_imgview_get_file_path(index);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_imgview_get_file_layer_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  width       [IN]        
 *  height      [IN]        
 *  mode        [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *vadp_v2p_cube_vapp_imgview_get_file_layer_memory(S32 index, S32 width, S32 height, S32 mode, PS32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_cube_imgview_get_file_layer_memory(index, width, height, mode, result);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_free_file_layer_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_free_file_layer_memory(S32 index, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_free_file_layer_memory(index, mode);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_get_file_layer_real_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index           [IN]        
 *  offset_x        [IN]        
 *  offset_y        [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  mode            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_get_file_layer_real_size(S32 index, PS32 offset_x, PS32 offset_y, PS32 width, PS32 height, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_get_file_layer_real_size(index, offset_x, offset_y, width, height, mode);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_set_small_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_width         [IN]        
 *  image_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_set_small_image(S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_set_small_image(image_width, image_height);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_set_large_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_width         [IN]        
 *  image_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_set_large_image(S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_set_large_image(image_width, image_height);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_create_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_create_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_create_cache();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_close_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_close_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_close_cache();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_register_decode_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]         
 *  cb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_register_decode_cb(void *user_data, vadp_v2p_cube_imgview_file_decode_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_register_decode_cb(user_data, cb);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_get_layer_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_get_layer_info(gdi_handle handle, PS32 width, PS32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_get_layer_info(handle, width, height);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_change_to_view_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_change_to_view_mode(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_change_to_view_mode(index);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_change_to_navigation_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_change_to_navigation_mode(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_change_to_navigation_mode(index);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_focus_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_focus_change(S32 index, S32 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_focus_change(index, mode);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_pause_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_pause_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_pause_cache();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_resume_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_resume_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_resume_cache();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_pause_navigation_mode_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_pause_navigation_mode_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_pause_navigation_mode_decode();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_resume_navigation_mode_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_imgview_resume_navigation_mode_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cube_imgview_resume_navigation_mode_decode();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_imgview_get_forbid_item_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 vadp_v2p_cube_imgview_get_forbid_item_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_cube_imgview_get_forbid_item_info();
}
#endif /* __MMI_VUI_3D_CUBE_APP_IMGVIEW__ */ 

