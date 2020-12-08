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

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_v2p_cube.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines venus to plutommi adaption layer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_3D_CUBE_APP__

#include "mmi_include.h"
#include "ctype.h" 
#include "kal_release.h"
#include "MMIDataType.h"
#include "mmi_include.h"
#include "kal_trace.h"
#include "SettingProfile.h"
#include "fileMgrGProt.h"
#include "Fs_type.h"
#include "med_api.h"
#include "med_smalloc.h"
#include "gdi_include.h"
#include "gdi_layer.h"

#include "CubeAppGprot.h"
#include "CubeAppProt.h"
#include "CubeApp\vadp_p2v_cube.h"
#include "CubeApp\vadp_v2p_cube.h"

/* Venus MMI headers: */
#include "ui_core\base\vfx_datatype.h"
#include "ui_core\base\vfx_base.h"
#include "trc\vadp_app_trc.h"

/**********************************************************************
 * Constant Definitions:
 **********************************************************************/
#define MMI_CUBE_VAPP_SCRN_BUF_SIZE    (LCD_WIDTH * LCD_HEIGHT * 2)

/**********************************************************************
 * Structure Definitions:
 **********************************************************************/
typedef struct
{
    S32 x;
    S32 y;
} vadp_v2p_cube_pos_struct;

typedef struct
{
#ifdef __MMI_VUI_3D_CUBE_FREE_MODE__
    vadp_v2p_cube_pos_struct     pos;
#else /* !__MMI_VUI_3D_CUBE_FREE_MODE__ */

    S8 is_get_screenshot;
#ifndef __MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__
    S8 need_scr_effect_transition;
#endif /* !__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__ */

#endif /* __MMI_VUI_3D_CUBE_FREE_MODE__ */

    U8 prev_layer_idx;
    U8 *layer_buffer[MMI_CUBE_APP_NUM];    
} vadp_v2p_cube_context_struct;

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static vadp_v2p_cube_context_struct g_vadp_v2p_cube_cntx = 
{
#ifdef __MMI_VUI_3D_CUBE_FREE_MODE__
    {0, 0},
#else /* __MMI_VUI_3D_CUBE_FREE_MODE__ */
    0,
#ifndef __MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__
    0,
#endif
#endif /* __MMI_VUI_3D_CUBE_FREE_MODE__ */
    255,
    {NULL, NULL, NULL, NULL}
};

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_set_screen_effect_transition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_vapp_set_screen_effect_transition(VfxS8 enable)
{
#if !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
        g_vadp_v2p_cube_cntx.need_scr_effect_transition = 1;
    else
        g_vadp_v2p_cube_cntx.need_scr_effect_transition = 0;
    return;
#endif /* !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_get_screen_effect_transition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxS8
 *****************************************************************************/
VfxS8 vadp_v2p_cube_vapp_get_screen_effect_transition(void)
{
#if !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxS8)g_vadp_v2p_cube_cntx.need_scr_effect_transition;
#else /* !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) */
    return 0;
#endif /* !(!defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)) */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_set_down_pos
 * DESCRIPTION
 *  save current down position
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_vapp_set_down_pos(VfxS32 x, VfxS32 y)
{
#ifdef __MMI_VUI_3D_CUBE_FREE_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_v2p_cube_cntx.pos.x = (kal_int32)x;
    g_vadp_v2p_cube_cntx.pos.y = (kal_int32)y;
    return;
#endif /* __MMI_VUI_3D_CUBE_FREE_MODE__ */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_get_down_pos
 * DESCRIPTION
 * get current active layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_vapp_get_down_pos(VfxS32 *x, VfxS32 *y)
{
#ifdef __MMI_VUI_3D_CUBE_FREE_MODE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x)
    {
        *x = (VfxS32)g_vadp_v2p_cube_cntx.pos.x;
    }
    if (y)
    {
        *y = (VfxS32)g_vadp_v2p_cube_cntx.pos.y;
    }
    return;
#endif /* __MMI_VUI_3D_CUBE_FREE_MODE__ */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_save_cur_layer_to_buffer
 * DESCRIPTION
 *  Save current active layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_vapp_save_cur_layer_to_buffer(VfxU8 cur_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *layer_buf_ptr;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cube_app_get_img_prefetch_mode())
    {
        return;
    }
#ifndef __MMI_VUI_3D_CUBE_FREE_MODE__
    if (g_vadp_v2p_cube_cntx.is_get_screenshot == 0)
        g_vadp_v2p_cube_cntx.is_get_screenshot = 1;

    if (g_vadp_v2p_cube_cntx.is_get_screenshot && 
        g_vadp_v2p_cube_cntx.layer_buffer[cur_idx] != 0)
    {
        /* under capturing screenshot and the same one has been captured at past */
        return;
    }
#endif /* !__MMI_VUI_3D_CUBE_FREE_MODE__ */

    MMI_VS_CUBE_START_LOGGING("CB1");

    // Check if the screen has been cached, 
    // the cached screen will be released after the page transition is finish
    if (g_vadp_v2p_cube_cntx.layer_buffer[cur_idx] != 0)
    {
        // free gdi buffer 
        media_free_ext_buffer(stack_int_get_active_module_id(), 
                              (void **)&g_vadp_v2p_cube_cntx.layer_buffer[cur_idx]);   
        g_vadp_v2p_cube_cntx.layer_buffer[cur_idx] = NULL;
        g_vadp_v2p_cube_cntx.prev_layer_idx = 255;
    }
    
    // save current layer index
    if (g_vadp_v2p_cube_cntx.prev_layer_idx == 255)
    {
        g_vadp_v2p_cube_cntx.prev_layer_idx = cur_idx;
    }
    
    // create buffer 
    media_get_ext_buffer(
        stack_int_get_active_module_id(),
        (void **)&g_vadp_v2p_cube_cntx.layer_buffer[cur_idx], 
        MMI_CUBE_VAPP_SCRN_BUF_SIZE);
    
    gdi_layer_get_buffer_ptr(&layer_buf_ptr);
    
    /* replace GDI_COLOR_TRANSPARENT source key */
    gdi_layer_get_dimension(&width, &height);
    
    gdi_act_replace_src_key(
                layer_buf_ptr,
                width,
                0,
                0,
                0,
                0,
                width - 1,
                height - 1,
                GDI_COLOR_TRANSPARENT,
                width,
                height);

    memcpy(g_vadp_v2p_cube_cntx.layer_buffer[cur_idx],
           layer_buf_ptr, MMI_CUBE_VAPP_SCRN_BUF_SIZE);
   
    MMI_VS_CUBE_STOP_LOGGING("CB1");
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_save_cur_layer_buf_to_file
 * DESCRIPTION
 *  get current layer from the file
 * PARAMETERS
 *  scr_idx   [IN]    screen index
 * RETURNS
 *  >=0 : success
 *  < 0 : error
 *****************************************************************************/
VfxS8 vadp_v2p_cube_vapp_save_cur_layer_buf_to_file(VfxU8 scr_idx)
{
#if defined(__MMI_VUI_3D_CUBE_FREE_MODE__)
    PU8 buf_ptr = NULL;
    S8 acs_filename[32];
    S8 ucs2_filename[64];
    S8 acs_image_name[32];
    S8 ucs2_image_name[32 * ENCODING_LENGTH];
    FS_HANDLE file_handle;
    S32 fs_ret;
    U32 written;

    if (g_vadp_v2p_cube_cntx.layer_buffer[scr_idx] == NULL)
    {
        // No need to save it
        return 1;
    }

    if (vadp_v2p_cube_vapp_create_app_dir(MMI_FALSE) >= 0)
    {
        MMI_VS_CUBE_START_LOGGING("CB1");
        
        sprintf(acs_image_name, "scr%d.txt", scr_idx+1);
        mmi_asc_to_ucs2(ucs2_image_name, acs_image_name);
         
        memset(ucs2_filename, 0, sizeof(ucs2_filename));
        memset(acs_filename, 0, sizeof(acs_filename));
        sprintf(acs_filename, "%c:\\@Cube\\", (S8)MMI_PRIVATE_DRV);
           
        mmi_asc_to_ucs2(ucs2_filename, acs_filename);
        mmi_ucs2cat(ucs2_filename, ucs2_image_name);
    
        fs_ret = FS_NO_ERROR;
    
        file_handle = FS_Open((kal_uint16*) ucs2_filename, FS_READ_WRITE | FS_CREATE);
        if (file_handle >= FS_NO_ERROR)
        {       
     
            fs_ret = FS_Write(
                file_handle,
                g_vadp_v2p_cube_cntx.layer_buffer[scr_idx],
                MMI_CUBE_VAPP_SCRN_BUF_SIZE,
                &written);

            FS_Close(file_handle);

            VFX_LOG(VFX_INFO, VAPP_CUBE_SAVE_FILE, 1, 0, scr_idx, written);
            
            if (written < MMI_CUBE_VAPP_SCRN_BUF_SIZE)
            {
                VFX_LOG(VFX_ERROR, VAPP_CUBE_SAVE_FILE_FAIL, 1, 0, scr_idx);
                FS_Delete((kal_uint16*)ucs2_filename);
            }
        } 
    
        if (fs_ret == FS_DISK_FULL || file_handle < FS_NO_ERROR)
        {
        
            if (vadp_v2p_cube_vapp_create_app_dir(MMI_TRUE) >= 0)
            {
                memset(acs_filename, 0, sizeof(acs_filename));
                sprintf(acs_filename, "%c:\\Cube\\", (S8)MMI_PUBLIC_DRV);
                mmi_asc_to_ucs2(ucs2_filename, acs_filename);
                mmi_ucs2cat(ucs2_filename, ucs2_image_name);
                
                file_handle = FS_Open((kal_uint16*) ucs2_filename, FS_READ_WRITE | FS_CREATE);
                if (file_handle >= FS_NO_ERROR)
                {
                    fs_ret = FS_Write(
                    file_handle,
                    g_vadp_v2p_cube_cntx.layer_buffer[scr_idx],
                    MMI_CUBE_VAPP_SCRN_BUF_SIZE,
                    &written);

                    VFX_LOG(VFX_INFO, VAPP_CUBE_SAVE_FILE, 2, 1, scr_idx, written);
            
                    if (written < MMI_CUBE_VAPP_SCRN_BUF_SIZE)
                    {
                        VFX_LOG(VFX_ERROR, VAPP_CUBE_SAVE_FILE_FAIL, 2, 1, scr_idx);
                        FS_Delete((kal_uint16*)ucs2_filename);
                    }
                    
                    FS_Close(file_handle);
                }
            }
       
        }

        if (fs_ret != FS_NO_ERROR || file_handle < FS_NO_ERROR)
        {
            MMI_VS_CUBE_STOP_LOGGING("CB1");
            VFX_LOG(VFX_ERROR, VAPP_CUBE_SAVE_FILE_FAIL, 3, 1, scr_idx);
            return - 1;
        }
        
        MMI_VS_CUBE_STOP_LOGGING("CB1");
    }
    else
    {
        return -1;
    }
    
    return 1;
#elif defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) /* !__MMI_VUI_3D_CUBE_FREE_MODE__ */
    S8 acs_filename[32];
    S8 ucs2_filename[64];
    S8 acs_image_name[32];
    S8 ucs2_image_name[32 * ENCODING_LENGTH];
    GDI_RESULT gdi_ret;
    gdi_handle layer;
    U8 *buff_ptr;

    buff_ptr = g_vadp_v2p_cube_cntx.layer_buffer[g_vadp_v2p_cube_cntx.prev_layer_idx];
    if (buff_ptr == NULL)
    {
        // No need to save it
        return 1;
    }

    if (vadp_v2p_cube_vapp_create_app_dir(MMI_FALSE) >= 0)
    {
        // generate file name
        MMI_VS_CUBE_START_LOGGING("CB1");
        sprintf(acs_image_name, "scr%d.jpg", g_vadp_v2p_cube_cntx.prev_layer_idx+1);
        mmi_asc_to_ucs2(ucs2_image_name, acs_image_name);
 
        memset(ucs2_filename, 0, sizeof(ucs2_filename));
        memset(acs_filename, 0, sizeof(acs_filename));
        sprintf(acs_filename, "%c:\\@Cube\\", (S8)MMI_PRIVATE_DRV);
        mmi_asc_to_ucs2(ucs2_filename, acs_filename);
        mmi_ucs2cat(ucs2_filename, ucs2_image_name);

         // create layer
        gdi_ret = gdi_layer_create_using_outside_memory(
                      0,
                      0,
                      LCD_WIDTH,
                      LCD_HEIGHT,
                      &layer,
                      (PU8) buff_ptr,
                      MMI_CUBE_VAPP_SCRN_BUF_SIZE);
         
        ASSERT (gdi_ret != GDI_FAILED);

        gdi_ret = gdi_image_encode_layer_to_jpeg(layer, (S8*)ucs2_filename);
        VFX_LOG(VFX_INFO, VAPP_CUBE_ENCODE_FILE, 1, 0, gdi_ret);
        
        if (gdi_ret == GDI_IMAGE_ENCODER_ERR_DISK_FULL)
        {
            if (vadp_v2p_cube_vapp_create_app_dir(MMI_TRUE) >= 0)
            {
                memset(acs_filename, 0, sizeof(acs_filename));
                sprintf(acs_filename, "%c:\\Cube\\", (S8)MMI_PUBLIC_DRV);
                
                mmi_asc_to_ucs2(ucs2_filename, acs_filename);
                mmi_ucs2cat(ucs2_filename, ucs2_image_name);
                gdi_ret = gdi_image_encode_layer_to_jpeg(layer, (S8*)ucs2_filename);
                VFX_LOG(VFX_INFO, VAPP_CUBE_ENCODE_FILE, 1, 1, gdi_ret);
            }
        }

        MMI_VS_CUBE_STOP_LOGGING("CB1");
    
        if (gdi_ret != GDI_SUCCEED)
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
    return 1;
#else /* !__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__ */
    return 1;
#endif /* __MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__ */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_get_layer_buf_from_file
 * DESCRIPTION
 *  get layer from file
 * PARAMETERS
 *  scr_idx     [IN]    screen index
 *  handle      [OUT]   layer handle
 * RETURNS
 *  >=0 : success
 *  <0  : error
 *****************************************************************************/
VfxU8 *vadp_v2p_cube_vapp_get_layer_buf_from_file(VfxU8 scr_idx, VfxS32 *width, VfxS32 *height)
{
#ifdef __MMI_VUI_3D_CUBE_FREE_MODE__
    PU8 buf_ptr;
    S8 acs_filename[32];
    S8 ucs2_filename[64];
    S8 acs_image_name[32];
    S8 ucs2_image_name[32 * ENCODING_LENGTH];
    FS_HANDLE file_handle;
    S32 fs_ret;
    U32 readlen;

    MMI_VS_CUBE_START_LOGGING("CB1");
    
    if (g_vadp_v2p_cube_cntx.layer_buffer[scr_idx] == NULL)
    {
        // create buffer 
        media_get_ext_buffer(
        stack_int_get_active_module_id(),
        (void **)&buf_ptr, MMI_CUBE_VAPP_SCRN_BUF_SIZE);

        if (buf_ptr)
        {
            memset(buf_ptr, 0, MMI_CUBE_VAPP_SCRN_BUF_SIZE);

            // Read file into buffer
            sprintf(acs_image_name, "scr%d.txt", scr_idx+1);
            mmi_asc_to_ucs2(ucs2_image_name, acs_image_name);
    
        
            memset(ucs2_filename, 0, sizeof(ucs2_filename));
            memset(acs_filename, 0, sizeof(acs_filename));
            if (vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed(scr_idx, 0, MMI_FALSE) > 0)
            {
                sprintf(acs_filename, "%c:\\@Cube\\", (S8)MMI_PRIVATE_DRV);
            }
            else
            {
                sprintf(acs_filename, "%c:\\Cube\\", (S8)MMI_PUBLIC_DRV);
            }
           
            mmi_asc_to_ucs2(ucs2_filename, acs_filename);
            mmi_ucs2cat(ucs2_filename, ucs2_image_name);
    
            fs_ret = FS_NO_ERROR;
    
            file_handle = FS_Open((kal_uint16*) ucs2_filename, FS_READ_ONLY);
            if (file_handle >= FS_NO_ERROR)
            {
                fs_ret = FS_Read(
                    file_handle,
                    buf_ptr,
                    MMI_CUBE_VAPP_SCRN_BUF_SIZE,
                    &readlen);
                FS_Close(file_handle);
            }
            
            if (file_handle < FS_NO_ERROR || fs_ret < FS_NO_ERROR)
            {
                MMI_VS_CUBE_STOP_LOGGING("CB1");
                if (buf_ptr)
                {
                    media_free_ext_buffer(stack_int_get_active_module_id(), (void **)&buf_ptr);   
                }
                VFX_LOG(VFX_INFO, VAPP_CUBE_GET_BUF_FROM_FILE, 1, scr_idx, 0);
                return NULL;
            }
            
            g_vadp_v2p_cube_cntx.layer_buffer[scr_idx] = buf_ptr;
 
            // create layer
            if (width)
            {
                *width = LCD_WIDTH;
            }
            if (height)
            {
                *height = LCD_HEIGHT;
            }

            VFX_LOG(VFX_INFO, VAPP_CUBE_GET_BUF_FROM_FILE, 2, scr_idx, readlen);
            
            MMI_VS_CUBE_STOP_LOGGING("CB1");
            return (VfxU8 *)g_vadp_v2p_cube_cntx.layer_buffer[scr_idx];
        }
    }
    else
    {
        MMI_VS_CUBE_STOP_LOGGING("CB1");
        if (width)
        {
            *width = LCD_WIDTH;
        }
        if (height)
        {
            *height = LCD_HEIGHT;
        }
        return (VfxU8 *)g_vadp_v2p_cube_cntx.layer_buffer[scr_idx];
    }
    
    return NULL;
    
#else /* __MMI_VUI_3D_CUBE_FREE_MODE__ */
    return NULL;
#endif /* !__MMI_VUI_3D_CUBE_FREE_MODE__ */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_is_in_transition
 * DESCRIPTION
 *  cube is under animation transition
 * PARAMETERS
 *  void
 * RETURNS
 *  > 0 : running
 *  0   : not running
 *****************************************************************************/
VfxS8 vadp_v2p_cube_vapp_is_in_transition(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_VUI_3D_CUBE_FREE_MODE__
    VFX_LOG(VFX_INFO, VAPP_CBUE_IS_IN_TRANSITION, 
            g_vadp_v2p_cube_cntx.is_get_screenshot);
    return (VfxS8)g_vadp_v2p_cube_cntx.is_get_screenshot;
#else /* !__MMI_VUI_3D_CUBE_FREE_MODE__ */
    return 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_save_cur_layer
 * DESCRIPTION
 *  save current cube app layer 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_vapp_save_cur_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_vadp_v2p_cube_cntx.prev_layer_idx < MMI_CUBE_APP_NUM) && 
        (g_vadp_v2p_cube_cntx.prev_layer_idx >= 0) &&
        (vadp_v2p_cube_vapp_save_cur_layer_buf_to_file(
         g_vadp_v2p_cube_cntx.prev_layer_idx) < 0))
    {
        VFX_LOG(VFX_ERROR, VAPP_CUBE_SAVE_LAYER_TO_BUF, 1, 0);
    }

    VFX_LOG(VFX_INFO, VAPP_CUBE_SAVE_LAYER_TO_BUF, 2, 1);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_free_layer
 * DESCRIPTION
 *  free all cube app layer resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_cube_vapp_free_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_cube_app_get_img_prefetch_mode())
    {
        return;
    }
    
#ifndef __MMI_VUI_3D_CUBE_FREE_MODE__
    g_vadp_v2p_cube_cntx.is_get_screenshot = 0;
#endif /* __MMI_VUI_3D_CUBE_FREE_MODE__ */

    g_vadp_v2p_cube_cntx.prev_layer_idx = 255;
     
    for (i = 0; i < MMI_CUBE_APP_NUM; i++)
    {
        if (g_vadp_v2p_cube_cntx.layer_buffer[i] != 0)
        {
            // free gdi buffer
            media_free_ext_buffer(stack_int_get_active_module_id(), 
                                 (void **)&g_vadp_v2p_cube_cntx.layer_buffer[i]);   
            g_vadp_v2p_cube_cntx.layer_buffer[i] = NULL;
        }
    }
    
    VFX_LOG(VFX_INFO, VAPP_CUBE_FREE_RES);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_get_cube_layer_handle
 * DESCRIPTION
 *  get cube layer handler
 * PARAMETERS
 *  cube_layer     [OUT]   cube layer handle
 *  cube_layer_idx [IN] layer handle index
 * RETURNS
 *  >= 0 : success
 *  < 0  : error
 *****************************************************************************/
VfxU8 *vadp_v2p_cube_vapp_get_cube_layer_buf(VfxU32 cube_layer_idx,
                                             VfxS32 *width, VfxS32 *height)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)
    if (width)
    {
        *width = LCD_WIDTH;
    }
    if (height)
    {
        *height = LCD_HEIGHT;
    }
    g_vadp_v2p_cube_cntx.is_get_screenshot = 0;

    return g_vadp_v2p_cube_cntx.layer_buffer[cube_layer_idx];
#else /* !defined(__MMI_VUI_3D_CUBE_FREE_MODE__) */
    return NULL;
#endif /* defined(__MMI_VUI_3D_CUBE_FREE_MODE__) */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_save_cur_scr_snapshot
 * DESCRIPTION
 *  This function is used to get current screen snapshot
 * PARAMETERS
 *  cur_idx     [IN]    current screen index
 * RETURNS
 *  >= 0 : success
 *  <0 : fail
 *****************************************************************************/
VfxS8 vadp_v2p_cube_vapp_save_cur_scr_snapshot(VfxU8 cur_idx)
{
#if defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 acs_filename[32];
    S8 ucs2_filename[64];
    S8 acs_image_name[32];
    S8 ucs2_image_name[32 * ENCODING_LENGTH];
    gdi_handle handle;
    GDI_RESULT gdi_ret;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_VS_CUBE_START_LOGGING("CB1");
    sprintf(acs_image_name, "scr%d.jpg", cur_idx+1);
    mmi_asc_to_ucs2(ucs2_image_name, acs_image_name);
  
    memset(ucs2_filename, 0, sizeof(ucs2_filename));
    memset(acs_filename, 0, sizeof(acs_filename));
    sprintf(acs_filename, "%c:\\@Cube\\", (S8)MMI_PRIVATE_DRV);
    
    mmi_asc_to_ucs2(ucs2_filename, acs_filename);
    mmi_ucs2cat(ucs2_filename, ucs2_image_name);
    
    gdi_layer_get_active(&handle);
   
    gdi_ret = gdi_image_encode_layer_to_jpeg(handle, (S8*)ucs2_filename);

    if (gdi_ret == GDI_IMAGE_ENCODER_ERR_DISK_FULL)
    {
        if (vadp_v2p_cube_vapp_create_app_dir(MMI_TRUE) >= 0)
        {
            memset(acs_filename, 0, sizeof(acs_filename));
            sprintf(acs_filename, "%c:\\Cube\\", (S8)MMI_PUBLIC_DRV);
            
            mmi_asc_to_ucs2(ucs2_filename, acs_filename);
            mmi_ucs2cat(ucs2_filename, ucs2_image_name);
            
            gdi_ret = gdi_image_encode_layer_to_jpeg(handle, (S8*)ucs2_filename);
        }
    }
    
    MMI_VS_CUBE_STOP_LOGGING("CB1");
    
    if (gdi_ret != GDI_SUCCEED)
    {
        return -1;
    }
    
    return 0;
#else /* __MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__ */
    return -1;
#endif /* !__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__ */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed
 * DESCRIPTION
 *  check if current screen snapshot file is existed
 * PARAMETERS
 *  cur_idx     [IN]    current screen index
 *  encoded     [IN]    in encoded file format or not
 *  public_drv  [IN]    public driver or not
 * RETURNS
 *  > 0 : success
 *  <= 0 : fail
 *****************************************************************************/
VfxS8 vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed(VfxU8 cur_idx, VfxU8 encoded, VfxU8 public_drv)
{
#if defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) || defined(__MMI_VUI_3D_CUBE_FREE_MODE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 acs_filename[32];
    S8 ucs2_filename[64];
    S8 acs_image_name[32];
    S8 ucs2_image_name[32 * ENCODING_LENGTH];
    FS_HANDLE file_handle;
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (encoded)
        sprintf(acs_image_name, "scr%d.jpg", cur_idx+1);
    else
        sprintf(acs_image_name, "scr%d.txt", cur_idx+1);
    
    //sprintf(acs_image_name, "scr%d.PBM", cur_idx+1);
    mmi_asc_to_ucs2(ucs2_image_name, acs_image_name);

    memset(acs_filename, 0, sizeof(acs_filename));
    memset(ucs2_filename, 0, sizeof(ucs2_filename));
    if (public_drv)
    {
        sprintf(acs_filename, "%c:\\Cube\\", (S8)MMI_PUBLIC_DRV);
    }
    else
    {
        sprintf(acs_filename, "%c:\\@Cube\\", (S8)MMI_PRIVATE_DRV);
    }

    mmi_asc_to_ucs2(ucs2_filename, acs_filename);
    mmi_ucs2cat(ucs2_filename, ucs2_image_name);

    fs_ret = FS_NO_ERROR;

    file_handle = FS_Open((kal_uint16*) ucs2_filename, FS_READ_ONLY);

    /* no file is existed */
    if (file_handle < FS_NO_ERROR)
    {
        
        VFX_LOG(VFX_INFO, VAPP_CUBE_IS_FILE_EXISTED, 1, cur_idx, 0);
        return 0;
    }

    VFX_LOG(VFX_INFO, VAPP_CUBE_IS_FILE_EXISTED, 2, cur_idx, 1);
    FS_Close(file_handle);
    return 1;
#else /* defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) || defined(__MMI_VUI_3D_CUBE_FREE_MODE__) */
    return 0;
#endif /* !(defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) || defined(__MMI_VUI_3D_CUBE_FREE_MODE__)) */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_get_cur_active_drv
 * DESCRIPTION
 *  This function is used to get current active driver
 * PARAMETERS
 *  void
 * RETURNS
 *  active driver.
 *****************************************************************************/
VfxS8 vadp_v2p_cube_vapp_get_cur_active_drv(VfxU8 public_drv)
{
#ifdef __MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (public_drv)
    {
        return (VfxS8)MMI_PUBLIC_DRV;
    }
    else
    {
        return (VfxS8)MMI_PRIVATE_DRV;
    }
#else /* __MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__ */
    return -1;
#endif /* !__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__ */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_cube_vapp_create_app_dir
 * DESCRIPTION
 *  This function create cube application's directory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_cube_vapp_create_app_dir(VfxU8 public_drv)
{
#if defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) || defined(__MMI_VUI_3D_CUBE_FREE_MODE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR WCHARDirname[32];
    S32 attribute;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (public_drv)
    {
        kal_wsprintf(WCHARDirname, "%c:\\Cube\\", (S8)MMI_PUBLIC_DRV);
    }
    else
    {
        kal_wsprintf(WCHARDirname, "%c:\\@Cube\\", (S8)MMI_PRIVATE_DRV);
    }
    attribute = FS_GetAttributes(WCHARDirname);
    if (attribute < 0)
    {
        /* this directory doesn't exist. Create this directory */
        if (FS_CreateDir(WCHARDirname) != FS_NO_ERROR)
        {
            /* Failed to initialize */
            return -1;
        }
    }

    return 0;
#else /* defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) || defined(__MMI_VUI_3D_CUBE_FREE_MODE__) */
    return -1;
#endif /* !(defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) || defined(__MMI_VUI_3D_CUBE_FREE_MODE__)) */
}

#endif /* __MMI_VUI_3D_CUBE_APP__ */

