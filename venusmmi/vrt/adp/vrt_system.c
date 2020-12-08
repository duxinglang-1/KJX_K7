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
 *  vrt_system.c
 *
 * Project:
 * --------
 *  Venus Rendering Task
 *
 * Description:
 * ------------
 *  Provide system information for porting.
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vrt_system.h"
#include "vrt_trc.h"


#include "vrt_datatype.h"

#include "MMI_features.h"
#include "MMIDataType.h"
#include "gdi_include.h"
#include "GDI_internal.h"
#include "gdi_util.h"

#include "gui_data_types.h"
#include "gui.h"

#include "med_global.h"
#include "med_utility.h"

#include "ScreenRotationGprot.h"

#include "ProfilingEngine.h"
#include "cache_sw.h"
#include "CustDataRes.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
/* 32-byte alignment for simple memory allocator by default */
#define VRT_SYS_SIMPLE_MEM_ALLOC_ALIGNMENT 32

#define VRT_DEFAULT_FPS 30
#define VRT_FAST_FPS    40

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/

#if 0
/* under construction !*/
/* under construction !*/
#endif

static vrt_bool g_vrt_hw_ovl = VRT_TRUE;
static vrt_bool g_vrt_show_cross = VRT_FALSE;

extern void vrt_suspend(void);
extern void vrt_resume(vrt_bool is_blocking);
extern vrt_bool vrt_is_running(void);

extern void vrt_render_cache_mem_attach(void *mem_p, vrt_u32 size, vrt_u32 flag);
extern void vrt_render_cache_mem_detach(void *mem_p);

extern void vrt_render_enable_1st_frame_dithering(vrt_bool is_enable);
extern vrt_bool vrt_render_is_enable_1st_frame_dithering(void);

extern void vrt_render_wait_for_finish(void);


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vrt_log
 * DESCRIPTION
 *  This function will call in VRT task, to output vrt trace info in Catcher
 * PARAMETERS
 *  trc_class     [IN] the class type of trace
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_log(trace_class_enum trc_class, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list arg_list;
    kal_uint32 limit = 0;
    kal_uint32 msg_offset;
    const kal_char *fmt;
    
#if defined(__MTK_TARGET__)    
    kal_uint32 module_id = 0;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
          
#if defined(__MTK_TARGET__)
    /* early check if the VRT trace group is enabled */
    module_id = (kal_uint32)MOD_VRT;
    if (tst_trace_check_ps_filter_off(trc_class, &module_id, 2))
    {
        return;
    }
#endif    
    
    va_start(arg_list, trc_class);
    msg_offset = va_arg(arg_list, kal_uint32);
    /* translate to offset */
    msg_offset -= vrt_get_log_start_index();
    fmt = va_arg(arg_list, const kal_char *);
    limit = VRT_RENDER_END_OF_TRACE__enum - VRT_RENDER_DRAW_FRAME_BEGIN__enum;
    if (msg_offset < limit)
    {
        void *arg[8];
        vrt_s32 arg_count = 0;        
        vrt_s32 i;
        
        kal_uint32 msg_id = msg_offset + VRT_RENDER_DRAW_FRAME_BEGIN__enum;
        
        if (fmt != NULL)
        {
            vrt_s32 len = strlen(fmt);
            
            for (i = 0; i < len; i++)
            {
                vrt_u8 c = (vrt_u8)fmt[i];
                if (c >= 128)
                {
                    arg_count += c - 128;
                    /* next is var type */
                    i++;
                }
                else
                {
                    arg_count++;
                }
            }
            
            if (arg_count > 8)
            {
                arg_count = 8;
            }
        }
        
        for (i = 0; i < arg_count; i++)
        {
            arg[i] = va_arg(arg_list, void*);
        }
        
        switch (arg_count)
        {
            case 0:
                kal_trace(trc_class, msg_id, fmt);
                break;
                
            case 1:
                kal_trace(trc_class, msg_id, fmt, arg[0]);
                break;
                
            case 2:
                kal_trace(trc_class, msg_id, fmt, arg[0], arg[1]);
                break;

            case 3:
                kal_trace(trc_class, msg_id, fmt, arg[0], arg[1], arg[2]);
                break;

            case 4:
                kal_trace(trc_class, msg_id, fmt, arg[0], arg[1], arg[2], arg[3]);
                break;

            case 5:
                kal_trace(trc_class, msg_id, fmt, arg[0], arg[1], arg[2], arg[3], arg[4]);
                break;

            case 6:
                kal_trace(trc_class, msg_id, fmt, arg[0], arg[1], arg[2], arg[3], arg[4], arg[5]);
                break;
                
            case 7:
                kal_trace(trc_class, msg_id, fmt, arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6]);
                break;
                
            case 8:
                kal_trace(trc_class, msg_id, fmt, arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7]);
                break;
                
            default:
                break;
        }
    }
    
    va_end(arg_list);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_check_mmi_has_gdi_lock
 * DESCRIPTION
 *  This function will only call in MMI task, to check if MMI task own the
 *  GDI lock
 * PARAMETERS
 *  void
 * RETURNS
 *  return MG_TRUR if MMI task own the GDI lock, otherwise return VRT_FALSE
 *****************************************************************************/
vrt_bool vrt_sys_check_mmi_has_gdi_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (vrt_bool)((vrt_u32)gdi_mutex.tid == (vrt_u32)kal_get_current_thread_ID());
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_time
 * DESCRIPTION
 *  Get the system time in millisecond
 * PARAMETERS
 *  void
 * RETURNS
 *  the current system time
 *****************************************************************************/
vrt_msec_type vrt_sys_get_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ticks;
    kal_uint32 msec;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&ticks);
    msec = kal_ticks_to_milli_secs(ticks);
    
    return (vrt_msec_type)msec;
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_main_screen_info
 * DESCRIPTION
 *  Gets the main screen information, dimension and color format.
 * PARAMETERS
 *  dimension       [OUT]   the dimension of main screen
 *  color_format    [OUT]   main screen color format
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_sys_get_main_screen_info(vrt_size_struct *dimension, vrt_color_type_enum *color_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dimension != NULL)
    {
        dimension->width     = UI_device_width;
        dimension->height    = UI_device_height;
    }

    if (color_format != NULL)
    {
        if (GDI_MAINLCD_BIT_PER_PIXEL == 16)
        {
            *color_format = VRT_COLOR_TYPE_RGB565;
        }
        else if (GDI_MAINLCD_BIT_PER_PIXEL == 24)
        {
            *color_format = VRT_COLOR_TYPE_RGB888;
        }
        else
        {
            *color_format = VRT_COLOR_TYPE_UNKNOWN;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_text_dir
 * DESCRIPTION
 *  Get the text direction
 * PARAMETERS
 *  void
 * RETURNS
 *  The text direction
 *****************************************************************************/
vrt_text_dir_type_enum vrt_sys_get_text_dir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Keep the text direction to avoid that changed on VRT running */
    if (r2lMMIFlag) 
    {
        return MG_TEXT_DIR_TYPE_R2L;
    }
    else
    {
        return MG_TEXT_DIR_TYPE_NORMAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_res_image_lock
 * DESCRIPTION
 *  Lock a image resource by resource ID
 * PARAMETERS
 *  res_id      [IN]    resource ID to lock
 * RETURNS
 *  Pointer to image resource
 *****************************************************************************/
vrt_u8 *vrt_sys_res_image_lock(vrt_s32 res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (res_id <= 0)
    {
        return NULL;
    }
    
    return (vrt_u8 *)GetImage((U16)res_id);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_res_image_unlock
 * DESCRIPTION
 *  Unlock a image resource by resource ID
 * PARAMETERS
 *  res_id      [IN]    resource ID to unlock
 *  ptr         [IN]    pointer to image resource to unlock
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_sys_res_image_unlock(vrt_s32 res_id, vrt_u8 *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_res_shader_lock
 * DESCRIPTION
 *  Lock a shader resource by resource ID
 * PARAMETERS
 *  res_id      [IN]    resource ID to lock
 * RETURNS
 *  Pointer to shader resource
 *****************************************************************************/
vrt_u8 *vrt_sys_res_shader_lock(vrt_res_id res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (res_id <= 0)
    {
        return NULL;
    }
    
    // TODO: load shader from resource id
    //return (vrt_u8 *)GetShader((U16)res_id);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_res_shader_unlock
 * DESCRIPTION
 *  Unlock a shader resource by resource ID
 * PARAMETERS
 *  res_id      [IN]    resource ID to unlock
 *  ptr         [IN]    pointer to shader resource to unlock
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_sys_res_shader_unlock(vrt_res_id res_id, vrt_u8 *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do nothing */
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_image_get_size_from_mem
 * DESCRIPTION
 *  Return a image size with pointer to 8 bytes header image
 * PARAMETERS
 *  image_ptr   [IN]    pointer to 8 bytes header image
 * RETURNS
 *  The size of the image
 *****************************************************************************/
vrt_size_struct vrt_sys_image_get_size_from_mem(const void *image_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_s32 width = 0;
    vrt_s32 height = 0;
#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
    vrt_u8 *res_src = (vrt_u8 *)GetImageData((S8 *)image_ptr);
#else
    vrt_u8 *res_src = (vrt_u8 *)image_ptr;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_ptr == NULL)
    {
    #ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
        SetImageFlushable(image_ptr);
    #endif
        return vrt_size_make(0, 0);
    }
    
    /*width  = (vrt_s32)(( ((vrt_u32)res_src[7])        << 4) | (((vrt_u32)res_src[6] & 0xF0) >> 4));
    height = (vrt_s32)(((((vrt_u32)res_src[6]) & 0xF) << 8) |  ((vrt_u32)res_src[5]));*/
    if (GDI_SUCCEED != gdi_image_get_dimension(res_src, &width, &height))
    {
        width = 0;
        height = 0;
    }
#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
    SetImageFlushable(image_ptr);
#endif
    return vrt_size_make((vrt_s32)width, (vrt_s32)height);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_image_get_size_from_res_id
 * DESCRIPTION
 *  Return a image size of an image
 * PARAMETERS
 *  res_id    [IN]    resource id
 * RETURNS
 *  The size of the image
 *****************************************************************************/
vrt_size_struct vrt_sys_image_get_size_from_res_id(U16 res_id)
{
    U16 width = 0;
    U16 height = 0;
    mmi_res_get_image_size(res_id, &width, &height);
    return vrt_size_make((vrt_s32)width, (vrt_s32)height);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_image_get_size_from_file
 * DESCRIPTION
 *  Return a image size with filename
 * PARAMETERS
 *  filename    [IN]    file name of image
 * RETURNS
 *  The size of the image
 *****************************************************************************/
vrt_size_struct vrt_sys_image_get_size_from_file(const vrt_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_s32 width = 0;
    vrt_s32 height = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
    {
        return vrt_size_make(0, 0);
    }
    
    if (gdi_image_get_dimension_file((S8 *)filename, &width, &height) != GDI_SUCCEED) /* Jun change for VoV */
    {
        return vrt_size_make(0, 0);
    }
    
    return vrt_size_make((vrt_s32)width, (vrt_s32)height);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_image_get_info_from_file
 * DESCRIPTION
 *  Return a image info with filename
 * PARAMETERS
 *  filename    [IN]    file name of image
 *  info        [IN]    info buffer of image
 * RETURNS
 *  void
 *****************************************************************************/
vrt_bool vrt_sys_image_get_info_from_file(const vrt_wchar *filename, vrt_sys_image_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VRT_ASSERT(info != NULL);

    memset((vrt_u8*)info, 0, sizeof(vrt_sys_image_info_struct));
    
    if (filename == NULL)
    {
        info->state = VRT_SYS_IMAGE_INFO_STATE_ERROR;
        return VRT_FALSE;
    }
    
    ret = gdi_image_get_info_from_file(
        (const WCHAR *)filename, 
        &info->type,
        &info->size.width,
        &info->size.height,
        NULL);

    if (ret == GDI_SUCCEED)
    {
        info->state = VRT_SYS_IMAGE_INFO_STATE_LOADED;
        return VRT_TRUE;
    }
    else
    {
        info->state = VRT_SYS_IMAGE_INFO_STATE_ERROR;
        return VRT_FALSE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  vrt_sys_image_get_type_from_raw_data_image
 * DESCRIPTION
 *  Return gdi image format
 * PARAMETERS
 *  image_ptr   [IN]    pointer to 8 bytes header image
  *  image_format   [IN]    Vfx Image Format for non 8 byte header image
 * RETURNS
 *  The size of the image
 *****************************************************************************/
vrt_u8 vrt_sys_image_get_type_from_raw_data_image(const void *image_ptr , vrt_raw_data_image_format_enum image_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_u8 gdi_image_type = GDI_IMAGE_TYPE_INVALID;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(image_format)
    {
        case VRT_FILE_FORMAT_TYPE_AUTO:
            gdi_image_type = (vrt_u8)gdi_image_get_type_from_mem((PS8)image_ptr);
            break;
        
        case VRT_FILE_FORMAT_TYPE_BMP:
            gdi_image_type = GDI_IMAGE_TYPE_BMP;
            break;
    
        case VRT_FILE_FORMAT_TYPE_GIF:
            gdi_image_type = GDI_IMAGE_TYPE_GIF;
            break;

        case VRT_FILE_FORMAT_TYPE_PNG:
            gdi_image_type = GDI_IMAGE_TYPE_PNG;
            break;

        case VRT_FILE_FORMAT_TYPE_JPG:
            gdi_image_type = GDI_IMAGE_TYPE_JPG;
            break;

        case VRT_FILE_FORMAT_TYPE_ABM:
            gdi_image_type = GDI_IMAGE_TYPE_ABM;
            break;

        case VRT_FILE_FORMAT_TYPE_AB2:
            gdi_image_type = GDI_IMAGE_TYPE_AB2;
            break;
    }

    if(gdi_image_type == GDI_IMAGE_TYPE_INVALID)
    {
        gdi_image_type = GDI_IMAGE_TYPE_AB2;
    }

    return gdi_image_type;
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_image_get_size_from_file_raw_data
 * DESCRIPTION
 *  Return a image size with pointer to 8 bytes header image
 * PARAMETERS
 *  image_ptr   [IN]    pointer to 8 bytes header image
 * RETURNS
 *  The size of the image
 *****************************************************************************/
vrt_size_struct vrt_sys_image_get_size_from_file_raw_data(const void *image_ptr , vrt_s32 image_size, vrt_raw_data_image_format_enum image_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_s32 width = 0;
    vrt_s32 height = 0;
    vrt_u8 *res_src = (vrt_u8 *)image_ptr;
    vrt_u8 gdi_image_type;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_ptr == NULL)
    {
        return vrt_size_make(0, 0);
    }

    gdi_image_type = vrt_sys_image_get_type_from_raw_data_image(image_ptr, image_format);
    
    if (gdi_image_get_dimension_mem(gdi_image_type, res_src, image_size, &width, &height) != GDI_SUCCEED)
    {
        return vrt_size_make(0, 0);
    }

    return vrt_size_make((vrt_s32)width, (vrt_s32)height);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_layer_get_size
 * DESCRIPTION
 *  Return the size of the layer
 * PARAMETERS
 *  gdi_handle  [IN]    file name of image
 * RETURNS
 *  The size of the layer
 *****************************************************************************/
vrt_size_struct vrt_sys_layer_get_size(void *gdi_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_s32 width = 0;
    vrt_s32 height = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gdi_handle == NULL)
    {
        return vrt_size_make(0, 0);
    }
    
    width = ((gdi_layer_struct *)gdi_handle)->width;
    height = ((gdi_layer_struct *)gdi_handle)->height;

    return vrt_size_make((vrt_s32)width, (vrt_s32)height);
}



/*****************************************************************************
 * FUNCTION
 *  vrt_sys_font_measure_str
 * DESCRIPTION
 *  Caculate the size to draw the given string
 * PARAMETERS
 *  string      [IN]    the string to caculate
 * RETURNS
 *  The size to draw the string
 *****************************************************************************/
vrt_size_struct vrt_sys_font_measure_str(const vrt_font_struct *font, const vrt_wchar *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute fontAttr;
    vrt_s32 width = 0;
    vrt_s32 height = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (font == NULL || string == NULL)
    {
        return g_vrt_size_zero;
    }
    
    fontAttr.bold       = font->bold;
    fontAttr.italic     = font->italic;
    fontAttr.underline  = font->underline;
    fontAttr.size       = font->size;
    fontAttr.color      = font->color;
    fontAttr.type       = font->type;
    fontAttr.oblique    = font->oblique;
    fontAttr.smallCaps  = font->smallCaps;

    GDI_LOCK;
    SetFont(fontAttr, 0);
    Get_StringWidthHeight((U8 *)string, &width, &height);
    GDI_UNLOCK;

    if (font->border && string[0] != 0)
    {
        width += 2;
        height += 2;
    }

    return vrt_size_make((vrt_s32)width, (vrt_s32)height);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_init
 * DESCRIPTION
 *  Initialize the VRT system for porting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_sys_init(void)
{
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_sys_entry(void)
{

}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_leave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_sys_leave(void)
{
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_set_screen_rotation
 * DESCRIPTION
 *  Sets the screen rotation.
 * PARAMETERS
 *  rotation       [IN] rotation type
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_sys_set_screen_rotation(vrt_sys_screen_rotate_enum rotation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rotation >= VRT_SYS_SCREEN_ROTATE_END_OF_ENUM)
    {
        /* Do nothing */
        return;
    }

    vrt_render_wait_for_finish();

#if defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate((mmi_frm_screen_rotate_enum)rotation);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_screen_rotation
 * DESCRIPTION
 *  Gets the screen rotation value.
 * PARAMETERS
 *  void
 * RETURNS
 *  Screen rotation value.
 *****************************************************************************/
vrt_sys_screen_rotate_enum vrt_sys_get_screen_rotation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_ROTATE__)
    return (vrt_sys_screen_rotate_enum)mmi_frm_get_screen_rotate();
#else
    return VRT_SYS_SCREEN_ROTATE_0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_pre_screen_rotation
 * DESCRIPTION
 *  Gets the previous screen rotation value.
 * PARAMETERS
 *  void
 * RETURNS
 *  Screen rotation value.
 *****************************************************************************/
vrt_sys_screen_rotate_enum vrt_sys_get_pre_screen_rotation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_ROTATE__)
    return (vrt_sys_screen_rotate_enum)mmi_frm_get_real_prev_screen_rotate();
#else
    return VRT_SYS_SCREEN_ROTATE_0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_env_info
 * DESCRIPTION
 *  Gets environment info for VRT (we can use MMI compile option here)
 * PARAMETERS
 *  info_id       [IN]  info id
 * RETURNS
 *  info value
 *****************************************************************************/
void *vrt_sys_get_env_info(vrt_sys_env_info_id_enum info_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (info_id)
    {
        case VRT_SYS_ENV_INFO_ID_IS_GDI_PROFILING_ENABLED:
#ifdef __MMI_INTERACTIVE_PROFILNG__
            return (void*)mmi_frm_profiling_gdi_profile_is_enabled();
#else
            return (void*)VRT_FALSE;
#endif   
        default:
            break;
    }
    return NULL;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_enable_hw_ovl
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_canvas_enable_hw_ovl(vrt_bool is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_bool is_running;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    is_running = vrt_is_running();
    if (is_running)
    {
        vrt_suspend();
    }

    g_vrt_hw_ovl = is_enable;

    if (is_running)
    {
        vrt_resume(VRT_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_is_enable_hw_ovl
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_bool vrt_canvas_is_enable_hw_ovl(void)
{
    return g_vrt_hw_ovl;
}


/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_enable_1st_frame_dithering
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_canvas_enable_1st_frame_dithering(vrt_bool is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_bool is_running;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    is_running = vrt_is_running();
    if (is_running)
    {
        vrt_suspend();
    }

    vrt_render_enable_1st_frame_dithering(is_enable);

    if (is_running)
    {
        vrt_resume(VRT_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_is_enable_1st_frame_dithering
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_bool vrt_canvas_is_enable_1st_frame_dithering(void)
{
    return vrt_render_is_enable_1st_frame_dithering();
}


/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_enable_show_cross
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void vrt_canvas_enable_show_cross(vrt_bool is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_vrt_show_cross = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_is_enable_show_cross
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_bool vrt_canvas_is_enable_show_cross(void)
{
    return g_vrt_show_cross;
}


/*****************************************************************************
 * FUNCTION
 *  vrt_cache_mem_attach
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void vrt_cache_mem_attach(void *mem_p, vrt_u32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VRT_DEV_ASSERT(mem_p && size > 0);
    VRT_DEV_ASSERT(kal_get_current_thread_ID() != vrt_get_thread_id());

    vrt_render_cache_mem_attach(mem_p, size, VRT_CACHE_USER_POOL_FLAG_DEFAULT);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_cache_mem_attach
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void vrt_cache_mem_attach_ext(void *mem_p, vrt_u32 size, vrt_u32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VRT_DEV_ASSERT(mem_p && size > 0);
    VRT_DEV_ASSERT(kal_get_current_thread_ID() != vrt_get_thread_id());

    vrt_render_cache_mem_attach(mem_p, size, flag);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_cache_mem_detach
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void vrt_cache_mem_detach(void *mem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_bool is_running;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VRT_DEV_ASSERT(mem_p);
    VRT_DEV_ASSERT(kal_get_current_thread_ID() != vrt_get_thread_id());

    is_running = vrt_is_running();
    if (is_running)
    {
        vrt_suspend();
    }

    vrt_render_cache_mem_detach(mem_p);

    if (is_running)
    {
        vrt_resume(VRT_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_is_support_scanline_rotation
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_bool vrt_sys_is_support_scanline_rotation(void)
{
#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    return VRT_TRUE;
#else
    return VRT_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_disable_scanline_rotation
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void vrt_sys_disable_scanline_rotation(void)
{
#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    gdi_bltdb_disable();
    gdi_lcd_scanline_rotation_disable();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_enable_scanline_rotation
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void vrt_sys_enable_scanline_rotation(void)
{
#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    gdi_lcd_scanline_rotation_enable();
    gdi_bltdb_enable(GDI_BLTDB_ENABLE_ONLY_WHEN_HW_UPDATE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_scanline_rotation_angle
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_u8 vrt_sys_get_scanline_rotation_angle(void)
{
#if defined(GDI_MAINLCD_SCANLINE_ROTATION_90)
    return GDI_LAYER_ROTATE_90;
#elif defined(GDI_MAINLCD_SCANLINE_ROTATION_270)
    return GDI_LAYER_ROTATE_270;
#else
    return GDI_LAYER_ROTATE_0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_scanline_rotation_angle
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_u8 *vrt_sys_get_scanline_rotation_buffer(vrt_u32 *buffer_size)
{
#if defined(GDI_MAINLCD_SCANLINE_ROTATION)
    return (vrt_u8 *)gdi_scanline_get_buffer((U32*)buffer_size);
#else
    return NULL;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_is_using_int_stack
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_bool vrt_sys_is_using_int_stack(void)
{
/* use internal stack only for 6225 and 6253, note that VRT stack needs at least VRT_STACK_SIZE_MINIMUM bytes. */
#if defined(__MTK_TARGET__) && !defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    return VRT_TRUE;
#else
    return VRT_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_max_busy_sleep_tick_num
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_u32 vrt_sys_get_max_busy_sleep_tick_num(void)
{
#if defined(__CPU_ARM7EJ_S__) || defined(__CPU_ARM7TDMI__)
    return 3;
#else
    return 2;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_min_busy_sleep_tick_num
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_u32 vrt_sys_get_min_busy_sleep_tick_num(void)
{
#if defined(__CPU_ARM7EJ_S__) || defined(__CPU_ARM7TDMI__)
    return 2;
#else
    return 1;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_get_duration_ms
 * DESCRIPTION
 *  Convert time unit to millisecond.
 * PARAMETERS
 *  start_time          [IN]   start time tick
 *  end_time            [IN]   end time tick
 * RETURNS
 *  time in ms.
 *****************************************************************************/
vrt_u32 vrt_get_duration_ms(vrt_u32 start_time, vrt_u32 end_time)
{
#if defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_u32 result;
    kal_uint64 temp_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = drv_get_duration_tick(start_time, end_time);
    /* X ms = result x 1000/32K = (result x 125)>>12 */
    temp_value = (kal_uint64)(result*125);
    result = (vrt_u32)(temp_value>>12);
    return result;
#else
    //return kal_ticks_to_milli_secs(end_time - start_time);
    return end_time - start_time;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_get_time
 * DESCRIPTION
 *  Get current time tick.
 * PARAMETERS
 *
 * RETURNS
 *  time tick
 *****************************************************************************/
void vrt_get_time(vrt_u32 *t)
{
#if defined(__MTK_TARGET__)
    *t = drv_get_current_time();
#else
    //kal_get_time(t);
    *t = vrt_get_ms_time();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_med_alloc_temp_mem
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void *vrt_sys_med_alloc_temp_mem(vrt_u32 size, void (*callback)(void*))
{
    return med_alloc_temp_ext_mem(size, callback);
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_med_free_temp_mem
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void vrt_sys_med_free_temp_mem(void **mem_p)
{
    med_free_temp_ext_mem(mem_p);
}




/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_lcd_act_size
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_size_struct vrt_sys_get_lcd_act_size(vrt_sys_display_enum lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_size_struct act_size = {0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lcd)
    {
        case VRT_SYS_DISPLAY_MAIN_LCD:
            act_size = vrt_size_make(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
            break;

        default:
            VRT_ASSERT(0);
            break;
    }

    return act_size;
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_fps
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
vrt_u32 vrt_sys_get_fps(vrt_sys_display_enum lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_u32 fps;
    gdi_handle lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    switch (lcd)
    {
        case VRT_SYS_DISPLAY_MAIN_LCD:
             lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;
             break;
             
        default:
             VRT_ASSERT(0);
             break;
    }
    
    fps = (vrt_u32)gdi_lcd_get_refresh_rate(lcd_handle);

    /* check if support fast fps */
    if (fps < VRT_FAST_FPS)
    {
        fps = VRT_DEFAULT_FPS;
    }

    return fps;
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_normal_color_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
vrt_color_type_enum vrt_sys_get_normal_color_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_color_type_enum color_format = VRT_COLOR_TYPE_RGB565;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* internal color format */
#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24) && defined(__COSMOS_MMI__)
    #ifdef __VENUS_3D_UI_ENGINE__
        color_format = VRT_COLOR_TYPE_PARGB8888;
    #else
        color_format = VRT_COLOR_TYPE_RGB888;
    #endif    
#endif    

    return color_format;
}


/*****************************************************************************
 * FUNCTION
 *  vrt_sys_get_opaque_color_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
vrt_color_type_enum vrt_sys_get_opaque_color_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_color_type_enum color_format = VRT_COLOR_TYPE_RGB565_FULLY_OPAQUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* internal color format */
#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24) && defined(__COSMOS_MMI__)
    #ifdef __VENUS_3D_UI_ENGINE__
        color_format = VRT_COLOR_TYPE_PARGB8888;
    #else
        color_format = VRT_COLOR_TYPE_RGB888_FULLY_OPAQUE;
    #endif    
#endif    

    return color_format;
}


