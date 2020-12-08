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
 *  gdi_image_9slice.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
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

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "gdi_internal.h"
#include "gdi_image_9slice.h"
#include "gd_include.h"
#include "med_utility.h"

#include "kal_general_types.h"
#include "kal_release.h"
#include "string.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "med_smalloc.h"
#include "MMIDataType.h"

#include "gdi_datatype.h"
#include "gdi_const.h"
#include "gdi_primitive.h"
#include "gdi_include.h"
#include "gdi_image.h"
#include "gdi_util.h"
#include "gdi_mutex.h"
#include "gdi_layer.h"
#include "gdi_image_alpha_bmp_v2_internal.h"
#include "gdi_linear_transform.h"
#include "g2d_common_api.h"


#if defined(GDI_9SLICE_USING_DITHERING)
#include "iul_spatial_dithering.h"
#include "iul_sd_macros.h"

kal_bool g_9slice_using_dither = KAL_TRUE;
#endif

#if defined(__GFX_SLIM_COLOR_FORMAT__) // specially for very low cost project(ex.6250D) which will remove LT(HW/SW) support [or can use other conditions like __G2D_SUPPORT__ == FALSE && !6256]  
    #define GDI_9SLICE_FOR_LOW_COST_SLIM_PROJECT 
#endif

#if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
    #define GDI_9SLICE_USING_DYNAMIC_SWITCH
#endif    


#if defined(GDI_9SLICE_USING_DYNAMIC_SWITCH)
    #include "mmu.h"
    #include "cache_sw.h"
#endif

static kal_uint32 debug_9slice = 0;

#define GDI_9SLICE_HEADER_SIZE  20



#if defined(__MTK_TARGET__) && defined(__VENUS_SWLA_DBG_ON__)
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

/***************************************************************************** 
 * Extern functions
 *****************************************************************************/
extern gdi_result gdi_2d_linear_transfrom(float *matrix,gdi_handle src_layer_handle,
                                          kal_int32 src_rect_x,kal_int32 src_rect_y,kal_int32 src_rect_w,kal_int32 src_rect_h,
                                          kal_int32 dst_rect_x,kal_int32 dst_rect_y,kal_int32 dst_rect_w,kal_int32 dst_rect_h,
                                          GDI_LT_SRC_KEY_EDGE_FILTER_ENUM edge_filter_mode,kal_uint32 edge_filter_color,GDI_LT_SAMPLE_MODE_ENUM sample_mode,kal_uint32 flag);

extern gdi_result gdi_2d_linear_transfrom_for_9slice(float *matrix,
                                                     kal_int32 src_rect_x,kal_int32 src_rect_y,kal_int32 src_rect_w,kal_int32 src_rect_h,
                                                     kal_int32 dst_rect_x,kal_int32 dst_rect_y,kal_int32 dst_rect_w,kal_int32 dst_rect_h, 
                                                     kal_uint32 flag);

extern void gdi_2d_LT_get_g2dhandle(G2D_HANDLE_STRUCT** g2d_LT_handle, gdi_lcd_layer_struct *layer_info, MMI_BOOL *force_to_sw);

extern void gdi_2d_LT_nb_release_g2d_handle(void);

extern void gdi_2d_LT_nb_release_g2d_handle(void);

extern void gdi_2d_LT_nb_wait_for_previous_finish(void);

extern void gdi_2d_LT_wait_for_current_finish(void);

extern void gdi_2d_LT_nb_init_state(void (*non_blocking_callback)(void *param),void *param);

extern void gdi_2d_LT_all_setting(G2D_HANDLE_STRUCT* g2d_LT_handle,gdi_layer_struct *src_layer,gdi_lcd_layer_struct *layer_info,
                                  GDI_LT_SRC_KEY_EDGE_FILTER_ENUM edge_filter_mode,kal_uint32 edge_filter_color,GDI_LT_SAMPLE_MODE_ENUM sample_mode,kal_uint32 flag);

extern void gdi_2d_LT_reset_src_buffer(gdi_handle src_layer_handle);

extern void gdi_img_buf_copy_same_format(gdi_img_buf_struct *dst_buf, const gdi_img_buf_struct *src_buf,S32 width,S32 height);


extern void gdi_2d_LT_nb_release_event(void) ;
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
gdi_image_9slice_cntx_struct gdi_image_9slice_cntx;
U8* gdi_image_9slice_temp_layer_buffer = NULL;
static S32 gdi_image_9slice_temp_layer_buf_size = 5000*(GDI_LCD_WIDTH/320.0)*(GDI_LCD_HEIGHT/480.0);

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

//dither
#if defined(GDI_9SLICE_USING_DITHERING) 
static void gdi_image_9slice_dither_buf(gdi_img_buf_struct *dst_buf, gdi_img_buf_struct *act_buf, S32 width, S32 height)
{
    if ((dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888 || dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888) &&
        (act_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_ARGB8888 || act_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888))
    {
        S32 i, j;
        U8 *dst_ptr     = dst_buf->ptr;
        S32 dst_pitch   = dst_buf->pitch_bytes;
        IUL_SD_INITIALIZE();

        for (j = height; j > 0; j--)
        {
            U8 *dst_line_ptr = dst_ptr;
            
            for (i = width; i > 0; i = i - 1)
            {
                int noise;                                                  

                do 
                {
                   int out0, out1, out2;                                       
                   if (--sd_noise_bit < 0)                                     
                   {                                                           
                      sd_noise_bit = 8;                                       
                      IUL_RNG_MWC_GENERATE(sd_noise);  
                      sd_noise >>= 4;
                   } 
                   
                   noise = sd_noise & 0x7;      
                   sd_noise >>= 3;                                            
                   out0 = (signed)(dst_line_ptr[0]) - noise;                               
                   out0 = IUL_SD_SATURATE_ZERO(out0);                         
                   out1 = (signed)(dst_line_ptr[1]) - (noise >> 1);                               
                   out1 = IUL_SD_SATURATE_ZERO(out1);                         
                   out2 = (signed)(dst_line_ptr[2]) - noise;                               
                   out2 = IUL_SD_SATURATE_ZERO(out2);                         
                   (dst_line_ptr)[0] = out0;                                          
                   (dst_line_ptr)[1] = out1;                                          
                   (dst_line_ptr)[2] = out2;                                          
                } while (0);
                
                dst_line_ptr += 4;
            }
            dst_ptr += dst_pitch;            
        }

    }
    else if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_RGB888 &&
             act_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_RGB565)
    {
        S32 i, j;
        U8 *dst_ptr     = dst_buf->ptr;
        U8 *act_ptr     = act_buf->ptr;
        IUL_SD_INITIALIZE();

        for (j = height; j > 0; j--)
        {
            U8 *dst_line_ptr = dst_ptr;
            U16 *act_line_ptr = (U16 *)act_ptr;
            
            for (i = width; i > 0; i = i - 1)
            {
                int noise;    

                do 
                {
                   int out0, out1, out2;                                       
                   if (--sd_noise_bit < 0)                                     
                   {                                                           
                      sd_noise_bit = 8;                                       
                      IUL_RNG_MWC_GENERATE(sd_noise);                          
                   sd_noise >>= 4;
                   } 
                   
                   noise = sd_noise & 0x7;      
                   sd_noise >>= 3;                                            
                   out0 = (signed)(dst_line_ptr[0]) - noise;                               
                   out0 = IUL_SD_SATURATE_ZERO(out0);                         
                   out1 = (signed)(dst_line_ptr[1]) - (noise >> 1);                               
                   out1 = IUL_SD_SATURATE_ZERO(out1);                         
                   out2 = (signed)(dst_line_ptr[2]) - noise;                               
                   out2 = IUL_SD_SATURATE_ZERO(out2);                         
                   *(act_line_ptr) = ((out2 >> 3) << 11) | ((out1 >> 2) << 5) | (out0 >> 3); 
                } while (0);

                dst_line_ptr += 3;
                act_line_ptr += 1;
            }
            dst_ptr += dst_buf->pitch_bytes;
            act_ptr += act_buf->pitch_bytes;
        }
    }
    else if (dst_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB8888 &&
             act_buf->color_format == GDI_IMG_BUF_COLOR_FORMAT_PARGB6666)
    {
        S32 i, j;
        U8 *dst_ptr     = dst_buf->ptr;
        U8 *act_ptr     = act_buf->ptr;
        U32 out_color;
        IUL_SD_INITIALIZE();

        for (j = height; j > 0; j--)
        {
            U8 *dst_line_ptr = dst_ptr;
            U8 *act_line_ptr = (U8 *)act_ptr;
            
            for (i = width; i > 0; i = i - 1)
            {
                int noise;                                                  
        
                do 
                {
                   int out0, out1, out2;                                       
                   if (--sd_noise_bit < 0)                                     
                   {                                                           
                      sd_noise_bit = 8;                                       
                      IUL_RNG_MWC_GENERATE(sd_noise);  
                      sd_noise >>= 4;
                   }

                   noise = sd_noise & 0x7;      
                   sd_noise >>= 3;                                            
                   out0 = (signed)(dst_line_ptr[0]) - noise;                               
                   out0 = IUL_SD_SATURATE_ZERO(out0);                         
                   out1 = (signed)(dst_line_ptr[1]) - (noise >> 1);                               
                   out1 = IUL_SD_SATURATE_ZERO(out1);                         
                   out2 = (signed)(dst_line_ptr[2]) - noise;                               
                   out2 = IUL_SD_SATURATE_ZERO(out2);                         
                   out_color = ((dst_line_ptr[3] >> 2) << 18) | ((out2 >> 2) << 12) | ((out1 >> 2) << 6) | (out0 >> 2);
                   GDI_MEM_PUT_24(act_line_ptr, out_color);
                } while (0);
                
                dst_line_ptr += 4;
                act_line_ptr += 3;
            }
            dst_ptr += dst_buf->pitch_bytes;
            act_ptr += act_buf->pitch_bytes;
        }

    }

}

#endif

MMI_RET gdi_image_9slice_handle_scrn_enter_proc(mmi_event_struct *evt)
{
    gdi_image_9slice_temp_layer_buffer = (U8*)gdi_alloc_ext_mem_framebuffer(gdi_image_9slice_temp_layer_buf_size); 
    return MMI_RET_OK;
}

void gdi_image_9slice_handle_scrn_exit_proc()
{
    if(gdi_image_9slice_temp_layer_buffer != NULL)
    {
        gdi_free_ext_mem((void**)&gdi_image_9slice_temp_layer_buffer);
        gdi_image_9slice_temp_layer_buffer = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_dynamic_switch_to_cachable
 * DESCRIPTION
 *  Switch memory buffer from non-cacheable to cacheable
 * PARAMETERS
 *  do_switch         [OUT]      switch successful or not
 *  layer             [IN]       buffer pointer (layer->buf) to be switched
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_9slice_dynamic_switch_to_cachable(kal_bool* do_switch,gdi_layer_struct* layer)
{
#if defined(GDI_9SLICE_USING_DYNAMIC_SWITCH)    
    if(layer != NULL)
    {
        if((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(layer->buf_ptr))) && 
           (IS_CACHE_LINE_SIZE_ALIGNED(layer->layer_size)) &&
           (is_predef_dyna_c_region((kal_uint32)layer->buf_ptr, layer->layer_size))) 
        {
            if(KAL_TRUE == INT_QueryIsNonCachedRAM((kal_uint32)layer->buf_ptr, layer->layer_size))
            {
                layer->buf_ptr = (U8 *)phys_to_virt((void *)layer->buf_ptr);
                *do_switch = KAL_TRUE;
            }
        }
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_dynamic_switch_to_noncachable
 * DESCRIPTION
 *  Switch memory buffer from cacheable to non-cacheable
 * PARAMETERS
 *  do_switch         [IN]       switch successful or not
 *  layer             [IN]       buffer pointer (layer->buf) to be switched
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_9slice_dynamic_switch_to_noncachable(kal_bool* do_switch, gdi_layer_struct* layer)
{
#if defined(GDI_9SLICE_USING_DYNAMIC_SWITCH)    
    if(!(*do_switch))
        return;
    
    if(layer != NULL)
    {
        if(KAL_TRUE == INT_QueryIsCachedRAM((kal_uint32)layer->buf_ptr, layer->layer_size))
        {
            clean_and_invalidate_dcache((kal_uint32)layer->buf_ptr, layer->layer_size);
            layer->buf_ptr = (U8 *)virt_to_phys((void *)layer->buf_ptr);     
        }
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_get_dither
 * DESCRIPTION
 *  Get the dither of 9 slice
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool gdi_image_9slice_get_dither(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_9SLICE_USING_DITHERING)
    return g_9slice_using_dither;
#else
    return KAL_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_set_dither
 * DESCRIPTION
 *  Set the dither of 9 slice
 * PARAMETERS
 *  using_dither    [IN] 9slice using dither or not.
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_9slice_set_dither(kal_bool using_dither)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(GDI_9SLICE_USING_DITHERING)
    g_9slice_using_dither = using_dither;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_parse_header
 * DESCRIPTION
 *  parse 9slice 20byte header
 * PARAMETERS
 *  data_ptr        [IN]        data pointer
 *  data_size       [IN]        data size
 *  img_ptr         [OUT]       return img pointer
 *  img_size        [OUT]       return img size
 *  img_type        [OUT]       return img type
 *  margin_left     [OUT]       return left margin
 *  margin_top      [OUT]       return top margin
 *  margin_right    [OUT]       return right margin
 *  margin_bottom   [OUT]       return bottom margin
 *  is_fully_opaque [OUT]       return img is fully opaque
 *  do_dithering    [OUT]       return try to do ditheirng or not
 *  img_from_file   [IN]        img is from file
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_parse_header( 
                    U8  *data_ptr, 
                    U32 data_size,
                    U8  **img_ptr, 
                    S32 *img_size,
                    U32 *img_type,
                    S32 *margin_left,
                    S32 *margin_top,
                    S32 *margin_right,
                    S32 *margin_bottom,
                    gdi_image_9slice_fill_mode_enum *fill_mode,
                    kal_bool *img_fully_opaque,
                    kal_bool *do_dithering,
                    kal_bool img_from_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool fully_opaque = KAL_FALSE;
    U16* abm_data_16_ptr = NULL;
    gdi_image_ab2_info_struct header;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_size < GDI_9SLICE_HEADER_SIZE)
    {
        return GDI_FAILED;
    }

    *img_ptr = data_ptr + GDI_9SLICE_HEADER_SIZE;
    *img_size = data_size - GDI_9SLICE_HEADER_SIZE;
        
    *img_type = data_ptr[0];
    if (fill_mode != NULL)
    {
        if (data_ptr[1] == 1)
        {
            *fill_mode = GDI_IMAGE_9SLICE_FILL_MODE_STRETCH;
        }
        else if (data_ptr[1] == 0)
        {
            *fill_mode = GDI_IMAGE_9SLICE_FILL_MODE_REPEAT;
        }
        else
        {
            ASSERT(0);
        }
    }

    if (do_dithering != NULL)
    {
        if (data_ptr[2] == 0)
        {
            *do_dithering = KAL_TRUE;
        }
        else if (data_ptr[2] == 1)
        {
            *do_dithering = KAL_FALSE;
        }
        else
        {
            *do_dithering = KAL_FALSE;
        }
    }
    
    data_ptr += 4;

    if ((margin_left != NULL) && (margin_top != NULL) && (margin_right != NULL) && (margin_bottom != NULL))
    {
        *margin_left    = (S32)(data_ptr[0]) | (S32)((S32)data_ptr[1] << 8) | (S32)((S32)data_ptr[2] << 16) | (S32)((S32)data_ptr[3] << 24);
        data_ptr += 4;
        *margin_top     = (S32)(data_ptr[0]) | (S32)((S32)data_ptr[1] << 8) | (S32)((S32)data_ptr[2] << 16) | (S32)((S32)data_ptr[3] << 24);
        data_ptr += 4;
        *margin_right   = (S32)(data_ptr[0]) | (S32)((S32)data_ptr[1] << 8) | (S32)((S32)data_ptr[2] << 16) | (S32)((S32)data_ptr[3] << 24);
        data_ptr += 4;
        *margin_bottom  = (S32)(data_ptr[0]) | (S32)((S32)data_ptr[1] << 8) | (S32)((S32)data_ptr[2] << 16) | (S32)((S32)data_ptr[3] << 24);
        data_ptr += 4;

        if((*margin_left < 0) || 
           (*margin_top < 0) || 
           (*margin_right < 0) || 
           (*margin_bottom < 0))
        {
            return GDI_FAILED;
        }
    }
    else
    {
        data_ptr += 16;
    }

    GDI_ASSERT(data_ptr == *img_ptr);
    
    if ((*img_type == GDI_IMAGE_TYPE_INVALID) ||
        (*img_type >= GDI_IMAGE_TYPE_SUM))
    {
        return GDI_FAILED;
    }

    /*********************************************************/
    /* Determine whether 9slice image is fully opaque or not */
    /* Currently only support for ABM, AB2 image.            */
    /*********************************************************/

    if (*img_type == GDI_IMAGE_TYPE_ABM)
    {
        /* 
         * parse ABM header 
         */

        if (!((U32)data_ptr & 0x1))
        {
            abm_data_16_ptr = (U16*)data_ptr;
            if (abm_data_16_ptr[0] & 0x8000 && img_from_file == KAL_FALSE)
            {
                fully_opaque = KAL_TRUE;
            }
        }

    }
    else if (*img_type == GDI_IMAGE_TYPE_AB2)
    {
        /* 
         * parse AB2 header 
         */
        gdi_image_ab2_read_header(&header, data_ptr);
        if (header.pixel_format == GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE ||
            header.pixel_format == GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE)
        {
            fully_opaque = KAL_TRUE;
        }
    }
    else
    {
        // Default not fully opaque
    }

    if (img_fully_opaque)
    {
        *img_fully_opaque = fully_opaque;
    }
 
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_bitblt
 * DESCRIPTION
 *  If src_layer is null, decode a part of image to dest region.
 *  If src_layer is not null, copy data from src_layer to dest region.
 * PARAMETERS
 *  src_layer       [IN]       source layer
 *  img_ptr         [IN]       img data pointer
 *  img_size        [IN]       img data size
 *  img_type        [IN]       img type
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_bitblt(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    gdi_rect_struct dest_area, src_area;
    gdi_img_buf_struct dst_buf, src_buf;
    gdi_layer_struct *img_layer;

#if defined(GDI_9SLICE_USING_DITHERING)
    gdi_img_buf_struct act_buf = {0};
    gdi_handle dither_layer = GDI_NULL_HANDLE;
    kal_bool do_dither = gdi_image_9slice_cntx.do_dithering;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    do
    {
        img_layer = (gdi_layer_struct*)gdi_image_9slice_cntx.src_layer;
        
        /* prepare dst_buf */
        /* dst_buf is active layer if dither on act layer or not to dither */
        dest_area.x1 = dx;
        dest_area.y1 = dy;
        dest_area.x2 = dx + dw - 1;
        dest_area.y2 = dy + dh - 1;
        ret = gdi_img_buf_prepare_img_buf_struct(
                &dst_buf,
                &dest_area,
                gdi_act_layer->buf_ptr,
                (S32)gdi_act_layer->width,
                (S32)gdi_act_layer->bits_per_pixel >> 3,
                (U32)gdi_act_layer->vcf,
                (S32)gdi_act_layer->clipx1,
                (S32)gdi_act_layer->clipy1,
                (S32)gdi_act_layer->clipx2,
                (S32)gdi_act_layer->clipy2);
        if (ret == GDI_FAILED)  // null clip
        {
            ret = GDI_SUCCEED;
            break;
        }

    #if defined(GDI_9SLICE_USING_DITHERING)
        /* create dither_layer if needed */
        if (do_dither &&
            (gdi_act_layer->cf == GDI_COLOR_FORMAT_16 || gdi_act_layer->cf == GDI_COLOR_FORMAT_PARGB6666))
        {
            if (gdi_act_layer->cf == GDI_COLOR_FORMAT_16)
        {
            /* create RGB888 layer */
            gdi_image_create_temp_layer(&dither_layer, 
                        GDI_COLOR_FORMAT_24, 
                        0, 
                        0, 
                        dw, 
                        dh);
            }
            else /* gdi_act_layer is PARGB6666*/
            {
                /* create PARGB8888 layer */
                gdi_image_create_temp_layer(&dither_layer,
                        GDI_COLOR_FORMAT_32_PARGB,
                        0,
                        0,
                        dw,
                        dh);
            }

            if (dither_layer == GDI_NULL_HANDLE)
            {
                /* if create dither_layer fail, then not to do dither. */
                do_dither = KAL_FALSE;
            }
            else
            {
                /* bitblt to dither_layer, then dither from dither_layer to active layer */
                /* dst_buf is dither_layer, act_buf is gdi_act_layer */
                gdi_rect_struct dst_rect;
                gdi_layer_struct *dither_layer_struct = (gdi_layer_struct *)dither_layer;

                /* rename dst_buf(active layer) to act_buf */
                memcpy(&act_buf, &dst_buf, sizeof(gdi_img_buf_struct));

                /* copy active layer content to dither_layer if need alpha blending */
                if (gdi_image_9slice_cntx.do_alpha_blending)
                {
                    gdi_handle act_layer = (gdi_handle)gdi_act_layer;
                     
                    gdi_layer_push_and_set_active(dither_layer);
                    gdi_bitblt_sw(
                        act_layer, 
                        dest_area.x1, 
                        dest_area.y1, 
                        dest_area.x2, 
                        dest_area.y2, 
                        0, 
                        0);
                    gdi_layer_pop_and_restore_active();
                }

                /* set dither layer as dst_buf */
                dst_rect.x1 = 0;
                dst_rect.y1 = 0;
                dst_rect.x2 = dest_area.x2 - dest_area.x1;
                dst_rect.y2 = dest_area.y2 - dest_area.y1;
                ret = gdi_img_buf_prepare_img_buf_struct(
                        &dst_buf,
                        &dst_rect,
                        dither_layer_struct->buf_ptr,
                        (S32)dither_layer_struct->width,
                        (S32)dither_layer_struct->bits_per_pixel >> 3,
                        (U32)dither_layer_struct->vcf,
                        (S32)dither_layer_struct->clipx1,
                        (S32)dither_layer_struct->clipy1,
                        (S32)dither_layer_struct->clipx2,
                        (S32)dither_layer_struct->clipy2);
                if (ret == GDI_FAILED)  // null clip
                {
                    ret = GDI_SUCCEED;
                    break;
                }
            }
        }
        
    #endif  /* GDI_9SLICE_USING_DITHERING */

        /* parepare src_buf */
        src_area.x1 = sx - (dx - dest_area.x1);
        src_area.y1 = sy - (dy - dest_area.y1);
        src_area.x2 = 0;  // don't care
        src_area.y2 = 0;  // don't care
        ret = gdi_img_buf_prepare_img_buf_struct(
                &src_buf,
                &src_area,
                img_layer->buf_ptr,
                (S32)img_layer->width,
                (S32)img_layer->bits_per_pixel >> 3,
                (U32)img_layer->vcf,
                -1, -1, -1, -1);

        /* bitblt from src_buf to dst_buf */
        if (gdi_image_9slice_cntx.do_alpha_blending)
        {
            gdi_img_buf_blending(
                &dst_buf, 
                &src_buf,
                dest_area.x2 - dest_area.x1 + 1,
                dest_area.y2 - dest_area.y1 + 1);
        }
        else
        {
            /* copy from src_layer */
            gdi_img_buf_copy(
                &dst_buf, 
                &src_buf,
                dest_area.x2 - dest_area.x1 + 1,
                dest_area.y2 - dest_area.y1 + 1);
        }

        /* dither */
    #if defined(GDI_9SLICE_USING_DITHERING)
        if (do_dither)
        {
            if (dither_layer == GDI_NULL_HANDLE)
            {
                /* dither on dst_buf */
                gdi_image_9slice_dither_buf(&dst_buf, &dst_buf, 
                    dest_area.x2 - dest_area.x1 + 1, dest_area.y2 - dest_area.y1 + 1);
            }
            else
            {
                /* dither from dst_buf to act_buf */
                gdi_image_9slice_dither_buf(&dst_buf, &act_buf, 
                    dest_area.x2 - dest_area.x1 + 1, dest_area.y2 - dest_area.y1 + 1);
            }
        }
    #endif
        
        break;
    }while(0);

#if defined(GDI_9SLICE_USING_DITHERING)
    /* free dither layer */
    if (dither_layer != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(dither_layer);
    }
#endif

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_stretch_with_alpha_blending
 * DESCRIPTION
 *  stretch with alpha blending
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 *  sw              [IN]       source w
 *  sh              [IN]       source h
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_stretch_with_alpha_blending(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    gdi_handle temp_layer_handle = GDI_NULL_HANDLE;
#if defined(GDI_9SLICE_USING_DITHERING)
    gdi_img_buf_struct dst_buf, act_buf;
    gdi_rect_struct act_area;
#endif
    gdi_handle dither_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        ret = gdi_image_create_temp_layer(
                &temp_layer_handle, 
                GDI_COLOR_FORMAT_32_PARGB, 
                0, 
                0, 
                sw, 
                sh);
        if ((ret != GDI_SUCCEED) || (temp_layer_handle == GDI_NULL_HANDLE))
        {
            break;
        }

        if (gdi_image_9slice_cntx.src_layer == GDI_NULL_HANDLE)
        {
            gdi_layer_push_and_set_active(temp_layer_handle);
            ret = gdi_image_draw_mem(-(sx), -(sy), gdi_image_9slice_cntx.img_ptr, (U8)gdi_image_9slice_cntx.img_type, gdi_image_9slice_cntx.img_size);
            gdi_layer_pop_and_restore_active();
            if (ret != GDI_SUCCEED)
            {
                break;
            }
        }
        else
        {
            gdi_layer_struct *src_layer_ptr = (gdi_layer_struct*)gdi_image_9slice_cntx.src_layer;
            gdi_layer_struct *temp_layer_ptr = (gdi_layer_struct*)temp_layer_handle;
            gdi_img_buf_struct dst_buf, src_buf;
            gdi_rect_struct dest_area, src_area;

            dest_area.x1 = 0;
            dest_area.y1 = 0;
            dest_area.x2 = 0;  // don't care
            dest_area.y2 = 0;  // don't care
            ret = gdi_img_buf_prepare_img_buf_struct(
                    &dst_buf,
                    &dest_area,
                    temp_layer_ptr->buf_ptr,
                    (S32)temp_layer_ptr->width,
                    (S32)temp_layer_ptr->bits_per_pixel >> 3,
                    (U32)temp_layer_ptr->vcf,
                    -1, -1, -1, -1);

            src_area.x1 = sx;
            src_area.y1 = sy;
            src_area.x2 = sx + sw - 1;
            src_area.y2 = sy + sh - 1;
            ret = gdi_img_buf_prepare_img_buf_struct(
                    &src_buf,
                    &src_area,
                    src_layer_ptr->buf_ptr,
                    (S32)src_layer_ptr->width,
                    (S32)src_layer_ptr->bits_per_pixel >> 3,
                    (U32)src_layer_ptr->vcf,
                    -1, -1, -1, -1);

            /* copy from src_layer */
            gdi_img_buf_copy(
                &dst_buf, 
                &src_buf,
                sw,
                sh);
        }

        #if defined(GDI_9SLICE_USING_DITHERING)
        if (gdi_image_9slice_cntx.do_dithering)
        {
            act_area.x1 = dx;
            act_area.y1 = dy;
            act_area.x2 = dx + dw - 1;
            act_area.y2 = dy + dh - 1;
          
            gdi_img_buf_prepare_img_buf_struct(
                &act_buf, 
                &act_area,
                gdi_act_layer->buf_ptr, 
                (S32)gdi_act_layer->width, 
                (S32)gdi_act_layer->bits_per_pixel >> 3,
                (U32)gdi_act_layer->vcf,
                (S32)gdi_act_layer->clipx1,
                (S32)gdi_act_layer->clipy1,
                (S32)gdi_act_layer->clipx2,
                (S32)gdi_act_layer->clipy2);
            
            if (gdi_act_layer->cf == GDI_COLOR_FORMAT_16 || gdi_act_layer->cf == GDI_COLOR_FORMAT_PARGB6666)
            {
                gdi_result result;
                gdi_layer_struct *dither_layer_struct;
                gdi_handle act_layer;
                //due to resizer limit, create PARGB layer
                if (gdi_act_layer->cf == GDI_COLOR_FORMAT_16)
                {
                result = gdi_image_create_temp_layer(&dither_layer, 
                        GDI_COLOR_FORMAT_24, 
                        0, 
                        0, 
                        act_area.x2 - act_area.x1 + 1, 
                        act_area.y2 - act_area.y1 + 1);
                }
                else
                {
                    result = gdi_image_create_temp_layer(&dither_layer,
                            GDI_COLOR_FORMAT_32_PARGB,
                            0,
                            0,
                            act_area.x2 - act_area.x1 + 1,
                            act_area.y2 - act_area.y1 +1);
                }

                if (dither_layer != GDI_NULL_HANDLE && result == GDI_SUCCEED)
                {
                    if (gdi_image_9slice_cntx.do_alpha_blending)
                    {
                        gdi_rect_struct bitblt_area;
                        bitblt_area.x1 = act_area.x1;
                        bitblt_area.y1 = act_area.y1;
                        bitblt_area.x2 = act_area.x2;
                        bitblt_area.y2 = act_area.y2;
                        if (act_area.x1 < 0)
                        {
                            bitblt_area.x1 = 0;
                        }
                        if (act_area.y1 < 0)
                        {
                            bitblt_area.y1 = 0;
                        }
                        
                        gdi_layer_get_active(&act_layer);
                        gdi_layer_push_and_set_active(dither_layer);
                        //gdi_layer_clear(GDI_COLOR_TRANSPARENT);
                        gdi_bitblt_sw(act_layer, bitblt_area.x1, bitblt_area.y1, bitblt_area.x2, bitblt_area.y2, 
                            bitblt_area.x1 - act_area.x1, bitblt_area.y1 - act_area.y1);
                        gdi_layer_pop_and_restore_active();
                    }
                    
                    dither_layer_struct = (gdi_layer_struct *)dither_layer;
                    dst_buf.pitch_bytes = dither_layer_struct->width * dither_layer_struct->bits_per_pixel >> 3;
                    dst_buf.color_format = gdi_img_buf_trans_color_format(dither_layer_struct->vcf);
                    dst_buf.ptr = dither_layer_struct->buf_ptr;
                    //dst_buf.ptr += ((bitblt_area.y1 * dither_layer_struct->width ) + bitblt_area.x1) * (dither_layer_struct->bits_per_pixel >> 3);
                    
                    gdi_layer_push_and_set_active(dither_layer);
                    gdi_push_and_set_alpha_blending_source_layer(dither_layer);
                    /* Resize and blending */
                    ret = gdi_image_resize_and_blending_ex(
                            temp_layer_handle, 
                            dx - act_area.x1,
                            dy - act_area.y1, 
                            dw, 
                            dh,
                            (MMI_BOOL)gdi_image_9slice_cntx.force_alpha_blending);
                    gdi_layer_pop_and_restore_active();
                    gdi_pop_and_restore_alpha_blending_source_layer();
                    
                    if (ret != GDI_SUCCEED)
                    {
                        break;
                    }
                }
            }
            if ((gdi_act_layer->cf != GDI_COLOR_FORMAT_16 && gdi_act_layer->cf != GDI_COLOR_FORMAT_PARGB6666)
                || dither_layer == GDI_NULL_HANDLE) 
            {
                /* Resize and blending */
                ret = gdi_image_resize_and_blending_ex(
                        temp_layer_handle, 
                        dx,
                        dy, 
                        dw, 
                        dh,
                        (MMI_BOOL)gdi_image_9slice_cntx.force_alpha_blending);
                if (ret != GDI_SUCCEED)
                {
                    break;
                }
                
            }

            //dither        
            if (gdi_act_layer->cf != GDI_COLOR_FORMAT_16 && gdi_act_layer->cf != GDI_COLOR_FORMAT_PARGB6666)
            {
                gdi_image_9slice_dither_buf(&act_buf, &act_buf, 
                    act_area.x2 - act_area.x1 + 1, 
                    act_area.y2 - act_area.y1 + 1);
            }
            else if (dither_layer != GDI_NULL_HANDLE)
            {
                gdi_image_9slice_dither_buf(&dst_buf, &act_buf, 
                    act_area.x2 - act_area.x1 + 1, 
                    act_area.y2 - act_area.y1 + 1);
            }
        }
        else
		#endif
        {
            /* Resize and blending */
            ret = gdi_image_resize_and_blending_ex(
                    temp_layer_handle, 
                    dx,
                    dy, 
                    dw, 
                    dh,
                    (MMI_BOOL)gdi_image_9slice_cntx.force_alpha_blending);
            if (ret != GDI_SUCCEED)
            {
                break;
            }
        }
    }while(0);

    //dither
    if (dither_layer != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(dither_layer);
    }

    if (temp_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(temp_layer_handle);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_stretch_without_alpha_blending
 * DESCRIPTION
 *  stretch without alpha blending
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 *  sw              [IN]       source w
 *  sh              [IN]       source h
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_stretch_without_alpha_blending(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    gdi_handle temp_layer_handle = GDI_NULL_HANDLE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        ret = gdi_image_create_temp_layer(
                &temp_layer_handle, 
                gdi_act_layer->cf, 
                0, 
                0, 
                sw, 
                sh);
        if (temp_layer_handle == GDI_NULL_HANDLE)
        {
            break;
        }

        ret = gdi_image_draw_mem(-(sx), -(sy), gdi_image_9slice_cntx.img_ptr, (U8)gdi_image_9slice_cntx.img_type, gdi_image_9slice_cntx.img_size);
        if (ret != GDI_SUCCEED)
        {
            break;
        }

        /* Resize */
        ret = gdi_bitblt_resized_with_resizer(
                temp_layer_handle,
                0,
                0,
                sw - 1,
                sh - 1,
                dx,
                dy,
                dx + dw - 1,
                dy + dh - 1,
                GDI_RESIZER_SW_QUALITY_MEDIUM);
        if (ret != GDI_SUCCEED)
        {
            break;
        }
    }while(0);

    if (temp_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(temp_layer_handle);
    }
    return ret;
    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_src_color
 * DESCRIPTION
 *  fill dest region with the color of (sx, sy) on src_layer.
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_fill_with_src_color(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy)
{
    gdi_result ret = GDI_SUCCEED;
    U32 cA, cR, cG, cB;
    gdi_color src_color = 0;
    gdi_rect_struct dest_area;
    gdi_img_buf_struct dst_buf;

    do
    {
        /* Get the point color */
        if (gdi_image_9slice_cntx.src_layer != GDI_NULL_HANDLE)
        {
            gdi_layer_push_and_set_active(gdi_image_9slice_cntx.src_layer);
            src_color = gdi_act_get_pixel(sx, sy);
            gdi_act_color_to_rgb(&cA, &cR, &cG, &cB, src_color);
            gdi_layer_pop_and_restore_active();
        }
        else
        {
            gdi_handle temp_layer;

            // If no temp layer, create a 1x1 layer to get the src color.
            ret = gdi_image_create_temp_layer(
                    &temp_layer,
                    GDI_COLOR_FORMAT_32_PARGB,
                    0,
                    0,
                    1,
                    1);
            if ((ret != GDI_SUCCEED) || (temp_layer == GDI_NULL_HANDLE))
            {
                break;
            }
            gdi_layer_push_and_set_active(temp_layer);
            ret = gdi_image_draw_mem(-(sx), -(sy), gdi_image_9slice_cntx.img_ptr, (U8)gdi_image_9slice_cntx.img_type, gdi_image_9slice_cntx.img_size);
            if (ret < GDI_SUCCEED)
            {
                break;
            }
            src_color = gdi_act_get_pixel(0, 0);
            gdi_act_color_to_rgb(&cA, &cR, &cG, &cB, src_color);
            gdi_layer_pop_and_restore_active();

            gdi_image_free_temp_layer(temp_layer);
        }

        dest_area.x1 = dx;
        dest_area.y1 = dy;
        dest_area.x2 = dx + dw - 1;
        dest_area.y2 = dy + dh - 1;
        ret = gdi_img_buf_prepare_img_buf_struct(
                &dst_buf,
                &dest_area,
                gdi_act_layer->buf_ptr,
                (S32)gdi_act_layer->width,
                (S32)gdi_act_layer->bits_per_pixel >> 3,
                (U32)gdi_act_layer->vcf,
                (S32)gdi_act_layer->clipx1,
                (S32)gdi_act_layer->clipy1,
                (S32)gdi_act_layer->clipx2,
                (S32)gdi_act_layer->clipy2);
        if (ret == GDI_FAILED)  // null clip
        {
            ret = GDI_SUCCEED;
            break;
        }
        
        if (gdi_image_9slice_cntx.do_alpha_blending && (cA != 255))
        {
            gdi_img_buf_blending_color(
                &dst_buf, 
                src_color,
                dest_area.x2 - dest_area.x1 + 1,
                dest_area.y2 - dest_area.y1 + 1);
            break;
        }
        else
        {
            src_color = gdi_act_color_from_rgb(cA, cR, cG, cB);
            gdi_img_buf_fill_color(
                &dst_buf, 
                src_color,
                dest_area.x2 - dest_area.x1 + 1,
                dest_area.y2 - dest_area.y1 + 1);
            break;
        }
    } while(0);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_src_horizontal_line
 * DESCRIPTION
 *  fill dest region with source area which dimension is (dw X 1).
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_fill_with_src_horizontal_line(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    gdi_handle temp_layer = GDI_NULL_HANDLE;
    U8 temp_layer_cf = ((gdi_layer_struct*)gdi_image_9slice_cntx.src_layer)->cf;
    #if defined(GDI_9SLICE_USING_DITHERING)
    U8 line_buf_cf;
    #endif
	gdi_rect_struct dest_clip;
    U8 *line_buf = NULL;
    U32 line_buf_len = 0;
    kal_bool line_buf_with_alpha = KAL_FALSE;
    kal_bool line_buf_resize = KAL_TRUE;
    gdi_layer_struct *src_struct = NULL;

    #if defined(GDI_9SLICE_USING_DITHERING)
    gdi_img_buf_struct act_buf = {0};
    gdi_rect_struct act_area;
    kal_bool do_dither = gdi_image_9slice_cntx.do_dithering;
    gdi_handle dither_layer = GDI_NULL_HANDLE, line_x3_layer = GDI_NULL_HANDLE;
    #define GDI_9SLICE_DITHER_ROW_NUM 10
    #endif
    
    gdi_layer_push_clip();
    
    do
    {
        /* reset clip to the interaction of (dx, dy, dx2, dy2) and current clip */
        dest_clip.x1 = dx;
        dest_clip.y1 = dy;
        dest_clip.x2 = dx + dw - 1;
        dest_clip.y2 = dy + dh - 1;
        GDI_CLIP_RECT_TEST(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2, break);
        gdi_layer_set_clip(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2);

        if (dw == sw)   // if no resize, clip coordinate first.
        {
            line_buf_resize = KAL_FALSE;
            
            sx -= (dx - dest_clip.x1);
            dx = dest_clip.x1;
            dy = dest_clip.y1;
            dw = dest_clip.x2 - dest_clip.x1 + 1;
            dh = dest_clip.y2 - dest_clip.y1 + 1;

            sw = dw;
        }
        
        
        /* prepare the line buffer */
        if ((gdi_image_9slice_cntx.src_layer != GDI_NULL_HANDLE) &&
            (line_buf_resize == KAL_FALSE))
        {
            src_struct = (gdi_layer_struct*)gdi_image_9slice_cntx.src_layer;

            line_buf = src_struct->buf_ptr;
            line_buf += (((sy * src_struct->width) + sx) * (src_struct->bits_per_pixel >> 3));
            line_buf_len = sw * src_struct->bits_per_pixel >> 3;
#if defined(GDI_9SLICE_USING_DITHERING)
			line_buf_cf = ((gdi_layer_struct*)gdi_image_9slice_cntx.src_layer)->cf;
#endif

        }
        else
        {
            if (gdi_image_9slice_cntx.do_alpha_blending)
            {
                temp_layer_cf = GDI_COLOR_FORMAT_32_PARGB;
            }
            else
            {
                temp_layer_cf = gdi_act_layer->cf;
            }
            // If no temp layer, create a sw*1 layer to get the src color.            
            ret = gdi_image_create_temp_layer(
                    &temp_layer,
                    temp_layer_cf,
                    0,
                    0,
                    sw,
                    1);
            if ((ret != GDI_SUCCEED) || (temp_layer == GDI_NULL_HANDLE))
            {
                break;
            }
            gdi_layer_push_and_set_active(temp_layer);
            ret = gdi_image_draw_mem(-(sx), -(sy), gdi_image_9slice_cntx.img_ptr, (U8)gdi_image_9slice_cntx.img_type, gdi_image_9slice_cntx.img_size);
            gdi_layer_pop_and_restore_active();
            if (ret < GDI_SUCCEED)
            {
                break;
            }

            if (line_buf_resize == KAL_TRUE) // if resize, resize and clip src to another buffer
            {
                gdi_handle temp_layer2;
                ret = gdi_image_create_temp_layer(
                        &temp_layer2,
                        temp_layer_cf,
                        0,
                        0,
                        dest_clip.x2 - dest_clip.x1 + 1,    // width after clipping
                        1);
                if ((ret != GDI_SUCCEED) || (temp_layer2 == GDI_NULL_HANDLE))
                {
                    break;
                }
                gdi_layer_push_and_set_active(temp_layer2);
                ret = gdi_bitblt_resized_with_resizer(
                        temp_layer, 
                        0,
                        0,
                        sw - 1,
                        0,
                        dx - dest_clip.x1,
                        0,
                        dx - dest_clip.x1 + dw - 1,
                        0,
                        GDI_RESIZER_SW_QUALITY_MEDIUM);
                gdi_layer_pop_and_restore_active();

                // use temp_layer2 as temp_layer
                gdi_image_free_temp_layer(temp_layer);
                temp_layer = temp_layer2;
            }

            line_buf = ((gdi_layer_struct*)temp_layer)->buf_ptr;
            line_buf_len = ((gdi_layer_struct*)temp_layer)->layer_size;

#if defined(GDI_9SLICE_USING_DITHERING)
            line_buf_cf = temp_layer_cf;

#endif
        }
        
        /* already resize the line buffer, so now we can modify dx,dy,dw,dh */
        dx = dest_clip.x1;
        dy = dest_clip.y1;
        dw = dest_clip.x2 - dest_clip.x1 + 1;
        dh = dest_clip.y2 - dest_clip.y1 + 1;

        #if defined(GDI_9SLICE_USING_DITHERING)
        act_area.x1 = dx;
        act_area.y1 = dy;
        act_area.x2 = dx + dw - 1;
        act_area.y2 = dy + dh - 1;
      
        gdi_img_buf_prepare_img_buf_struct(
            &act_buf, 
            &act_area,
            gdi_act_layer->buf_ptr, 
            (S32)gdi_act_layer->width, 
            (S32)gdi_act_layer->bits_per_pixel >> 3,
            (U32)gdi_act_layer->vcf,
            (S32)gdi_act_layer->clipx1,
            (S32)gdi_act_layer->clipy1,
            (S32)gdi_act_layer->clipx2,
            (S32)gdi_act_layer->clipy2);
        #endif

        // check all alpha is 255
        line_buf_with_alpha = KAL_FALSE;
        if (gdi_image_9slice_cntx.do_alpha_blending)
        {
            U8 *temp_ptr = line_buf;
            S32 i = 0;

            for (i = 0 ; i < dw ; i++)
            {
                if ((*temp_ptr) != 255)
                {
                    line_buf_with_alpha = KAL_TRUE;
                    break;
                }
                temp_ptr += 4;
            }
        }

        #if defined(GDI_9SLICE_USING_DITHERING)
        /* create dither line buf */
        if (do_dither)
        {
            /* create dither line buf */
            gdi_image_create_temp_layer(
                &line_x3_layer,
                temp_layer_cf,
                0,
                0,
                dw,
                GDI_9SLICE_DITHER_ROW_NUM);
            dither_layer = line_x3_layer;

            if ((dither_layer == GDI_NULL_HANDLE))
            {
                /* can't do dither */
                do_dither = KAL_FALSE;
            }

            if (do_dither && (temp_layer_cf == GDI_COLOR_FORMAT_16 || temp_layer_cf == GDI_COLOR_FORMAT_PARGB6666))
            {
                if (temp_layer_cf == GDI_COLOR_FORMAT_16)
            {
                gdi_image_create_temp_layer(
                    &dither_layer,
                    GDI_COLOR_FORMAT_24,
                    0,
                    0,
                    dw,
                    GDI_9SLICE_DITHER_ROW_NUM);
                }
                else /* PARGB6666 */
                {
                    gdi_image_create_temp_layer(
                        &dither_layer,
                        GDI_COLOR_FORMAT_32_PARGB,
                        0,
                        0,
                        dw,
                        GDI_9SLICE_DITHER_ROW_NUM);
                        
                }
                    
                if ((dither_layer == GDI_NULL_HANDLE))
                {
                    /* can't do dither */
                    do_dither = KAL_FALSE;
                }
            }
        }

        /* copy dither layer to act layer */
        if (do_dither)
        {
            S32 i = 0;
            gdi_layer_struct* dither_layer_str = (gdi_layer_struct*)dither_layer;
            gdi_img_buf_struct dither_buf;
            U8 *line_buf_temp = line_buf;
            gdi_layer_struct* line_x3_str = (gdi_layer_struct*)line_x3_layer;
            gdi_img_buf_struct line_x3_buf;
            gdi_img_buf_struct line_buf_struct;

            line_x3_buf.color_format = gdi_img_buf_trans_color_format(line_x3_str->cf);
            line_x3_buf.pitch_bytes = line_x3_str->width * line_x3_str->bits_per_pixel >> 3;
            line_x3_buf.ptr = line_x3_str->buf_ptr;

            dither_buf.ptr = dither_layer_str->buf_ptr;
            dither_buf.color_format = gdi_img_buf_trans_color_format(dither_layer_str->cf);
            dither_buf.pitch_bytes = dither_layer_str->width * dither_layer_str->bits_per_pixel >> 3;

            line_buf_struct.ptr = line_buf_temp;
            line_buf_struct.pitch_bytes = line_buf_len;
            line_buf_struct.color_format = gdi_img_buf_trans_color_format(line_buf_cf);
            
            /* repeat line buffer * GDI_9SLICE_DITHER_LINE_NUM to dither layer */
            for(i = 0 ; i < GDI_9SLICE_DITHER_ROW_NUM; i++)
            {
                gdi_img_buf_copy(
                    &dither_buf, 
                    &line_buf_struct,
                    dw,
                    1);
                /* jump line */
                dither_buf.ptr += dither_buf.pitch_bytes;
            }
            
            /* restore dither_buf.ptr*/
            dither_buf.ptr = dither_layer_str->buf_ptr;

            /* run dithering */
            if (dither_layer == line_x3_layer)
            {
                /* dither on dither_buf */
                gdi_image_9slice_dither_buf(
                    &dither_buf, &dither_buf, dw, GDI_9SLICE_DITHER_ROW_NUM);
            }
            else
            {
                /* dither from dst_buf to line_x3_layer */
                gdi_image_9slice_dither_buf(
                    &dither_buf, &line_x3_buf, dw, GDI_9SLICE_DITHER_ROW_NUM);
            }

            /* copy line_x3_layer to act_layer */
            if (gdi_image_9slice_cntx.do_alpha_blending)
            {
                U32 blend_height = GDI_9SLICE_DITHER_ROW_NUM;
                    
                for (i = 0 ; i < dh ; i += GDI_9SLICE_DITHER_ROW_NUM)
                {
                    ASSERT(blend_height == GDI_9SLICE_DITHER_ROW_NUM);
                    if ((dh - i) < GDI_9SLICE_DITHER_ROW_NUM)
                    {
                        blend_height = (dh - i);
                    }
                    gdi_img_buf_blending(&act_buf, &line_x3_buf, dw, blend_height);
                    act_buf.ptr += act_buf.pitch_bytes * blend_height;   // jump GDI_9SLICE_DITHER_LINE_NUM pixel width

                }
            } 
            else
            {
                U32 copy_height = GDI_9SLICE_DITHER_ROW_NUM;

                for (i = 0 ; i < dh ; i += GDI_9SLICE_DITHER_ROW_NUM)
                {
                    ASSERT(copy_height == GDI_9SLICE_DITHER_ROW_NUM);
                    if ((dh - i) < GDI_9SLICE_DITHER_ROW_NUM)
                    {
                        copy_height = (dh - i);
                    }
                    gdi_bitblt_sw(line_x3_layer, 0, 0, dw - 1, copy_height - 1, dx, dy + i);

                }
            }
            
            break;
        }
        #endif
            
        if ((gdi_image_9slice_cntx.do_alpha_blending && line_buf_with_alpha) ||
            (temp_layer_cf != gdi_act_layer->cf))
        {
            // line buf is PARGB
            // TODO: src cf != act cf?, currently temp solution in gdi_image_9slice_do_alpha_blending
            U8 *act_ptr, *src_ptr;

            gdi_handle src_layer_handle = GDI_NULL_HANDLE;
            gdi_layer_struct *src_layer = NULL;
            
            gdi_get_alpha_blending_source_layer(&src_layer_handle);
            src_layer = (gdi_layer_struct*)src_layer_handle;

            act_ptr = gdi_act_layer->buf_ptr + (((dy * gdi_act_layer->width) + dx) * (gdi_act_layer->bits_per_pixel >> 3));
            src_ptr = src_layer->buf_ptr + 
                      ((((dy + gdi_act_layer->offset_y - src_layer->offset_y) * src_layer->width) + 
                      (dx + gdi_act_layer->offset_x - src_layer->offset_x)) * 
                      (src_layer->bits_per_pixel >> 3));
            
            if (gdi_act_layer->cf == GDI_COLOR_FORMAT_16)
            {
                gdi_image_blending_32_to_16(
                    line_buf,
                    0,  //pitch is 0, always use the same line buf to alpha blending
                    act_ptr,
                    (gdi_act_layer->width * gdi_act_layer->bits_per_pixel) >> 3,
                    src_ptr,
                    (src_layer->width * src_layer->bits_per_pixel) >> 3,
                    dw,
                    dh);
            }
            #if !defined(GDI_SLIM_COLOR_FORMAT)
            else if (gdi_act_layer->cf == GDI_COLOR_FORMAT_24)
            {
                gdi_image_blending_32_to_24(
                    line_buf,
                    0,  //pitch is 0
                    act_ptr,
                    (gdi_act_layer->width * gdi_act_layer->bits_per_pixel) >> 3,
                    src_ptr,
                    (src_layer->width * src_layer->bits_per_pixel) >> 3,
                    dw,
                    dh);
            }
            #endif
            
            else if (gdi_act_layer->cf == GDI_COLOR_FORMAT_32)
            {
                gdi_image_blending_32_to_32(
                    line_buf,
                    0,  //pitch is 0
                    act_ptr,
                    (gdi_act_layer->width * gdi_act_layer->bits_per_pixel) >> 3,
                    src_ptr,
                    (src_layer->width * src_layer->bits_per_pixel) >> 3,
                    dw,
                    dh);
                gdi_util_convert_PARGB8888_to_ARGB8888_buf(
                    gdi_act_layer->buf_ptr,
                    gdi_act_layer->width, 
                    dx, 
                    dy, 
                    dw, 
                    dh);
            }
            else if (gdi_act_layer->cf == GDI_COLOR_FORMAT_32_PARGB)
            {
                gdi_image_blending_32_to_32(
                    line_buf,
                    0,  //pitch is 0
                    act_ptr,
                    (gdi_act_layer->width * gdi_act_layer->bits_per_pixel) >> 3,
                    src_ptr,
                    (src_layer->width * src_layer->bits_per_pixel) >> 3,
                    dw,
                    dh);
            }
#ifdef GDI_LAYER_PARGB6666_SUPPORT            
            else if (gdi_act_layer->cf == GDI_COLOR_FORMAT_PARGB6666)
            {
                gdi_image_blending_PARGB8888_to_PARGB6666(
                    line_buf,
                    0,  //pitch is 0
                    act_ptr,
                    (gdi_act_layer->width * gdi_act_layer->bits_per_pixel) >> 3,
                    src_ptr,
                    (src_layer->width * src_layer->bits_per_pixel) >> 3,
                    dw,
                    dh);            
                
            }
#endif            
            else
            {
                ret = GDI_FAILED;
                break;
            }
            break;
        }
        else
        {
            /* no alpha blending, copy line buf to active layer */
            U8 *act_ptr;
            U32 act_line_jump = gdi_act_layer->width * gdi_act_layer->bits_per_pixel >> 3;
            S32 i = 0;
            
            act_ptr = gdi_act_layer->buf_ptr + 
                      (((dy * gdi_act_layer->width) + dx) * 
                        (gdi_act_layer->bits_per_pixel >> 3));
            
            for (i = dest_clip.y2 ; i >= dy  ; i--)
            {
                memcpy(act_ptr, line_buf, line_buf_len);
                act_ptr += act_line_jump;
            }
        }
    } while(0);

    gdi_layer_pop_clip();

    //dither
    #if defined(GDI_9SLICE_USING_DITHERING)
    if (dither_layer != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(dither_layer);
    }

    if ((line_x3_layer != dither_layer) && (line_x3_layer != GDI_NULL_HANDLE))
    {
        gdi_image_free_temp_layer(line_x3_layer);
    }   
    #endif
    
    if (temp_layer != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(temp_layer);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_src_vertical_line
 * DESCRIPTION
 *  fill dest region with source area which dimension is (1 X dh).
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_fill_with_src_vertical_line(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sh)
{
    gdi_result ret = GDI_SUCCEED;
    gdi_rect_struct dest_area;
    gdi_handle temp_layer = GDI_NULL_HANDLE;
    U8 temp_layer_cf = ((gdi_layer_struct*)gdi_image_9slice_cntx.src_layer)->cf;
    U8 *line_buf = NULL;
    U32 line_buf_pitch = 0;
    gd_color_to_rgb_func line_buf_get_color_func;
    gd_get_buf_pixel_func line_buf_get_pixel_func;
    U32 cA, cR, cG, cB;
    kal_bool line_buf_resize = KAL_TRUE;
    gdi_img_buf_struct dst_buf;
    
#if defined(GDI_9SLICE_USING_DITHERING)
    kal_bool do_alpha_blending = gdi_image_9slice_cntx.do_alpha_blending;
    kal_bool do_dither = gdi_image_9slice_cntx.do_dithering;
    gdi_handle dither_layer = GDI_NULL_HANDLE, line_x3_layer = GDI_NULL_HANDLE;
#define GDI_9SLICE_DITHER_LINE_NUM 10
    gdi_layer_struct* dither_layer_str = NULL;
    gdi_layer_struct* line_x3_str = NULL;
#endif
    
    do
    {
        /* reset clip to the interaction of (dx, dy, dx2, dy2) and current clip */
        dest_area.x1 = dx;
        dest_area.y1 = dy;
        dest_area.x2 = dx + dw - 1;
        dest_area.y2 = dy + dh - 1;
        GDI_CLIP_RECT_TEST(dest_area.x1, dest_area.y1, dest_area.x2, dest_area.y2, break);

        if (dh == sh)   // if no resize, clip coordinate first.
        {
            line_buf_resize = KAL_FALSE;
            
            sy -= (dy - dest_area.y1);
            dx = dest_area.x1;
            dy = dest_area.y1;
            dw = dest_area.x2 - dest_area.x1 + 1;
            dh = dest_area.y2 - dest_area.y1 + 1;
        }
        

        /* prepare the line buffer */
        if ( line_buf_resize == KAL_FALSE)
        {
            gdi_layer_struct *src_struct = (gdi_layer_struct*)gdi_image_9slice_cntx.src_layer;

            line_buf = src_struct->buf_ptr;
            line_buf += (((sy * src_struct->width) + sx) * (src_struct->bits_per_pixel >> 3));
            line_buf_pitch = src_struct->width * src_struct->bits_per_pixel >> 3;
            line_buf_get_color_func = gd_color_to_rgb[src_struct->cf];
            line_buf_get_pixel_func = gd_get_buf_pixel[src_struct->cf];
        }
        else
        {
            /* create line buffer */
            ret = gdi_image_create_temp_layer(
                    &temp_layer,
                    temp_layer_cf,
                    0,
                    0,
                    1,
                        dest_area.y2 - dest_area.y1 + 1);   // height after clipping
            if (temp_layer == GDI_NULL_HANDLE)
                {
                    break;
                }
            
            gdi_layer_push_and_set_active(temp_layer);
            /* resize src content to line buffer */
                ret = gdi_bitblt_resized_with_resizer(
                    gdi_image_9slice_cntx.src_layer, 
                    sx,  //src
                    sy,
                    sx,
                    sy + sh - 1,
                    0,  //dst
                        dy - dest_area.y1,
                        0,
                        dy - dest_area.y1 + dh - 1,
                        GDI_RESIZER_SW_QUALITY_MEDIUM);
                gdi_layer_pop_and_restore_active();

            line_buf = ((gdi_layer_struct*)temp_layer)->buf_ptr;
            line_buf_pitch = ((gdi_layer_struct*)temp_layer)->bits_per_pixel >> 3;
            line_buf_get_color_func = gd_color_to_rgb[((gdi_layer_struct*)temp_layer)->cf];
            line_buf_get_pixel_func = gd_get_buf_pixel[((gdi_layer_struct*)temp_layer)->cf];
        }

        /* already resize the line buffer, so now we can modify dx,dy,dw,dh */
        dx = dest_area.x1;
        dy = dest_area.y1;
        dw = dest_area.x2 - dest_area.x1 + 1;
        dh = dest_area.y2 - dest_area.y1 + 1;

        dst_buf.pitch_bytes = gdi_act_layer->width * gdi_act_layer->bits_per_pixel >> 3;
        dst_buf.color_format = gdi_img_buf_trans_color_format(gdi_act_layer->vcf);
        dst_buf.ptr = gdi_act_layer->buf_ptr;
        dst_buf.ptr += ((dy * gdi_act_layer->width ) + dx) * (gdi_act_layer->bits_per_pixel >> 3);

        #if defined(GDI_9SLICE_USING_DITHERING)
        /* create dither line buf */
        if (do_dither)
        {
            /* create dither line buf */
            gdi_image_create_temp_layer(
                &line_x3_layer,
                temp_layer_cf,
                0,
                0,
                GDI_9SLICE_DITHER_LINE_NUM,    
                dh);
            dither_layer = line_x3_layer;

            if ((dither_layer == GDI_NULL_HANDLE))
            {
                /* can't do dither */
                do_dither = KAL_FALSE;
            }

            if (do_dither && (temp_layer_cf == GDI_COLOR_FORMAT_16 || temp_layer_cf == GDI_COLOR_FORMAT_PARGB6666))
            {
                if (temp_layer_cf == GDI_COLOR_FORMAT_16)
            {
                gdi_image_create_temp_layer(
                    &dither_layer,
                        GDI_COLOR_FORMAT_24, 
                        0, 
                        0, 
                    GDI_9SLICE_DITHER_LINE_NUM,    
                    dh);
                }
                else
                {
                    gdi_image_create_temp_layer(
                        &dither_layer,
                        GDI_COLOR_FORMAT_32_PARGB,
                        0,
                        0,
                        GDI_9SLICE_DITHER_LINE_NUM,
                        dh);
                }

                if ((dither_layer == GDI_NULL_HANDLE))
                {
                    /* can't do dither */
                    do_dither = KAL_FALSE;
                }
            }
        }

        /* copy dither layer to act layer */
        if (do_dither)
        {
            S32 i = 0;

            gdi_img_buf_struct dither_buf;
            gdi_color temp_color_line, temp_color_act;
            U8 *line_buf_temp = line_buf;
            gdi_img_buf_struct line_x3_buf;
            dither_layer_str = (gdi_layer_struct*)dither_layer;
            line_x3_str = (gdi_layer_struct*)line_x3_layer;


            #if defined(GDI_9SLICE_USING_DYNAMIC_SWITCH)
        
            line_x3_str->buf_ptr = (U8 *)phys_to_virt((void *)line_x3_str->buf_ptr);

            if (line_x3_str != dither_layer_str)
            {
                dither_layer_str->buf_ptr = (U8 *)phys_to_virt((void *)dither_layer_str->buf_ptr);            
            }
            #endif

            line_x3_buf.color_format = gdi_img_buf_trans_color_format(line_x3_str->vcf);
            line_x3_buf.pitch_bytes = GDI_9SLICE_DITHER_LINE_NUM * line_x3_str->bits_per_pixel >> 3;
            line_x3_buf.ptr = line_x3_str->buf_ptr;

            dither_buf.ptr = dither_layer_str->buf_ptr;
            dither_buf.color_format = gdi_img_buf_trans_color_format(dither_layer_str->vcf);
            dither_buf.pitch_bytes = GDI_9SLICE_DITHER_LINE_NUM * dither_layer_str->bits_per_pixel >> 3;

            /* repeat line buffer * GDI_9SLICE_DITHER_LINE_NUM to dither layer */
            if (temp_layer_cf == dither_layer_str->cf)
            {
                /* cf of line buf and dither_buf are both 16 or 32 */
                for(i = 0 ; i <= (dh - 1) ; i++)
                {
                    temp_color_line = line_buf_get_pixel_func(line_buf_temp, 4, 0, 0);
                    gdi_img_buf_fill_color(
                        &dither_buf, 
                        temp_color_line,
                        GDI_9SLICE_DITHER_LINE_NUM,
                        1);
                    /* jump line */
                    line_buf_temp += line_buf_pitch;
                    dither_buf.ptr += dither_buf.pitch_bytes;
                }
            }
            else
                            {
                /* line buf 16 && dither_buf 24 */
                ASSERT((temp_layer_cf == GDI_COLOR_FORMAT_16) || (temp_layer_cf == GDI_COLOR_FORMAT_PARGB6666));
                ASSERT((dither_layer_str->cf == GDI_COLOR_FORMAT_24) || (dither_layer_str->cf == GDI_COLOR_FORMAT_32_PARGB));
                if (temp_layer_cf == GDI_COLOR_FORMAT_16)
                {
                for(i = 0 ; i <= (dh - 1) ; i++)
                {
                    temp_color_line = line_buf_get_pixel_func(line_buf_temp, 4, 0, 0);
                        /* RGB565 to RGB888 */
                    temp_color_act =  ((temp_color_line >> 11) << 19)|(((temp_color_line << 5) >> 10) << 10)|((temp_color_line << 11) >> 8);
                    gdi_img_buf_fill_color(
                        &dither_buf, 
                        temp_color_act,
                        GDI_9SLICE_DITHER_LINE_NUM,
                        1);
                    /* jump line */
                    line_buf_temp += line_buf_pitch;
                    dither_buf.ptr += dither_buf.pitch_bytes;
                            }
                    }
                else /* temp_layer_cf is GDI_COLOR_FORMAT_PARGB6666 */
                {
                    for(i = 0 ; i <= (dh - 1) ; i++)
                    {
                        temp_color_line = line_buf_get_pixel_func(line_buf_temp, 4, 0, 0);
                        temp_color_act =  GDI_PARGB8888_FROM_PARGB6666(temp_color_line);
                        gdi_img_buf_fill_color(
                            &dither_buf, 
                            temp_color_act,
                            GDI_9SLICE_DITHER_LINE_NUM,
                            1);
                        /* jump line */
                        line_buf_temp += line_buf_pitch;
                        dither_buf.ptr += dither_buf.pitch_bytes;
                    }                    
                }
            }
            /* restore dither_buf.ptr*/
            dither_buf.ptr = dither_layer_str->buf_ptr;
                    
            /* run dithering */
            if (dither_layer == line_x3_layer)
            {
                /* dither on dither_buf */
                gdi_image_9slice_dither_buf(&dither_buf, &dither_buf, GDI_9SLICE_DITHER_LINE_NUM, dh);
            }
            else
            {
                /* dither from dst_buf to line_x3_layer */
                gdi_image_9slice_dither_buf(&dither_buf, &line_x3_buf, GDI_9SLICE_DITHER_LINE_NUM, dh);
            }

            /* check line buf with alpha or not */
            if (do_alpha_blending)
            {
                U8 *temp_ptr = line_buf;

                do_alpha_blending = KAL_FALSE;
                for (i = 0 ; i < dh ; i++)
                {
                    if ((*temp_ptr) != 255)
                    {
                        do_alpha_blending = KAL_TRUE;
                        break;
                    }
                    temp_ptr += 4;
                }
            }

            /* copy line_x3_layer to act_layer */
            if (do_alpha_blending)
            {
                U32 jump_byte = GDI_9SLICE_DITHER_LINE_NUM * (gdi_act_layer->bits_per_pixel >> 3);
                U32 blend_width = GDI_9SLICE_DITHER_LINE_NUM;
            
                for (i = 0 ; i < dw ; i += GDI_9SLICE_DITHER_LINE_NUM)
                {
                    ASSERT(blend_width == GDI_9SLICE_DITHER_LINE_NUM);
                    if ((dw - i) < GDI_9SLICE_DITHER_LINE_NUM)
                    {
                        blend_width = (dw - i);
                    }
                    gdi_img_buf_blending(&dst_buf, &line_x3_buf, blend_width, dh);
                    dst_buf.ptr += jump_byte;   // jump GDI_9SLICE_DITHER_LINE_NUM pixel width
                }
            }
            else
            {
                for (i = 0 ; i < dw ; i += GDI_9SLICE_DITHER_LINE_NUM)
                {
                    // bitblt to active layer
                    gdi_bitblt_sw(line_x3_layer, 0, 0, GDI_9SLICE_DITHER_LINE_NUM - 1, dh - 1, dx + i, dy);
                }
            }
            break;
        }
        #endif
        if (gdi_image_9slice_cntx.do_alpha_blending)
        {
            S32 i = 0;
            
            /* need alpha blending */
            for (i = dest_area.y1 ; i <= dest_area.y2 ; i++)
            {
                gdi_img_buf_blending_color(
                    &dst_buf, 
                    (gdi_color)*(U32*)(line_buf),
                    dest_area.x2 - dest_area.x1 + 1,
                    1);

                /* jump line */
                line_buf += line_buf_pitch;
                dst_buf.ptr += dst_buf.pitch_bytes;
            }
        }
        else
        {
            S32 i = 0;
            gdi_color temp_color_line, temp_color_act;
            
            /* no alpha blending, copy color to active layer */
            for (i = dest_area.y1 ; i <= dest_area.y2 ; i++)
            {
                temp_color_line = line_buf_get_pixel_func(line_buf, 4, 0, 0);
                line_buf_get_color_func(&cA, &cR, &cG, &cB, temp_color_line);
                temp_color_act = gdi_act_color_from_rgb(cA, cR, cG, cB);

                gdi_img_buf_fill_color(
                    &dst_buf, 
                    temp_color_act,
                    dest_area.x2 - dest_area.x1 + 1,
                    1);

                /* jump line */
                line_buf += line_buf_pitch;
                dst_buf.ptr += dst_buf.pitch_bytes;
            }
        }
    } while(0);

#if (defined(GDI_9SLICE_USING_DYNAMIC_SWITCH) && defined(GDI_9SLICE_USING_DITHERING))
        if ((dither_layer_str != NULL) && INT_QueryIsCachedRAM(dither_layer_str->buf_ptr, 0))
        {
            dither_layer_str->buf_ptr = (U8 *)virt_to_phys((void *)(dither_layer_str->buf_ptr));
        }

        if ((line_x3_str != NULL) && (line_x3_str != dither_layer_str) && INT_QueryIsCachedRAM(line_x3_str->buf_ptr, 0))
        {
            line_x3_str->buf_ptr = (U8 *)virt_to_phys((void *)(line_x3_str->buf_ptr));
        }
#endif    

    if (temp_layer != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(temp_layer);
    }

#if defined(GDI_9SLICE_USING_DITHERING)
    if (dither_layer != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(dither_layer);
    }

    if ((line_x3_layer != dither_layer) && (line_x3_layer != GDI_NULL_HANDLE))
    {
        gdi_image_free_temp_layer(line_x3_layer);
    }
#endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_stretch_mode
 * DESCRIPTION
 *  copy source data to dest.
 *  If dest region larger than source region, stretch source patten to fill dest region.
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 *  sw              [IN]       source w
 *  sh              [IN]       source h
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_fill_with_stretch_mode(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    gdi_handle dither_layer = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        if (gdi_image_9slice_cntx.do_alpha_blending)
        {
            ret = gdi_image_9slice_stretch_with_alpha_blending(dx, dy, dw, dh, sx, sy, sw, sh);
            break;
        }
        else if (gdi_image_9slice_cntx.src_layer == GDI_NULL_HANDLE)
        {
            ret = gdi_image_9slice_stretch_without_alpha_blending(dx, dy, dw, dh, sx, sy, sw, sh);
            break;
        }
        else
        {
        #if defined(GDI_9SLICE_USING_DITHERING)
            gdi_img_buf_struct dst_buf, act_buf;
            if (gdi_image_9slice_cntx.do_dithering)
            {
                gdi_rect_struct act_area;
                
                act_area.x1 = dx;
                act_area.y1 = dy;
                act_area.x2 = dx + dw - 1;
                act_area.y2 = dy + dh - 1;
              
                gdi_img_buf_prepare_img_buf_struct(
                    &act_buf, 
                    &act_area,
                    gdi_act_layer->buf_ptr, 
                    (S32)gdi_act_layer->width, 
                    (S32)gdi_act_layer->bits_per_pixel >> 3,
                    (U32)gdi_act_layer->vcf,
                    (S32)gdi_act_layer->clipx1,
                    (S32)gdi_act_layer->clipy1,
                    (S32)gdi_act_layer->clipx2,
                    (S32)gdi_act_layer->clipy2);

                if (gdi_act_layer->cf == GDI_COLOR_FORMAT_16 || gdi_act_layer->cf == GDI_COLOR_FORMAT_PARGB6666)
                {
                    gdi_result result;
                    gdi_layer_struct *dither_layer_struct;
                    //gdi_handle act_layer;
                    if (gdi_act_layer->cf == GDI_COLOR_FORMAT_16)
                    {
                    result = gdi_image_create_temp_layer(&dither_layer, 
                                GDI_COLOR_FORMAT_24, 
                                0, 
                                0, 
                                act_area.x2 - act_area.x1 + 1, 
                                act_area.y2 - act_area.y1 + 1);
                    }
                    else
                    {
                        result = gdi_image_create_temp_layer(&dither_layer,
                                    GDI_COLOR_FORMAT_32_PARGB,
                                    0,
                                    0,
                                    act_area.x2 - act_area.x1 + 1,
                                    act_area.y2 - act_area.y1 + 1);
                    }

                    if (dither_layer != GDI_NULL_HANDLE && result == GDI_SUCCEED)
                    {
                        dither_layer_struct = (gdi_layer_struct *)dither_layer;
                        dst_buf.pitch_bytes = dither_layer_struct->width * dither_layer_struct->bits_per_pixel >> 3;
                        dst_buf.color_format = gdi_img_buf_trans_color_format(dither_layer_struct->vcf);
                        dst_buf.ptr = dither_layer_struct->buf_ptr;
                        //dst_buf.ptr += ((dest_area.y1 * gdi_act_layer->width ) + dest_area.x1) * (gdi_act_layer->bits_per_pixel >> 3);
                        
                        gdi_layer_push_and_set_active(dither_layer);
                        ret = gdi_bitblt_resized_with_resizer(
                                gdi_image_9slice_cntx.src_layer, 
                                sx,
                                sy,
                                sx + sw - 1,
                                sy + sh - 1,
                                dx - act_area.x1,
                                dy - act_area.y1,
                                (dx - act_area.x1) + dw - 1,
                                (dy - act_area.y1) + dh - 1,
                                GDI_RESIZER_SW_QUALITY_MEDIUM);
                        gdi_layer_pop_and_restore_active();
                        
                        if (ret != GDI_SUCCEED)
                        {
                            break;
                        }
                        
                    }
                    
                }
                if ((gdi_act_layer->cf != GDI_COLOR_FORMAT_16 && gdi_act_layer->cf != GDI_COLOR_FORMAT_PARGB6666)
                    || dither_layer == GDI_NULL_HANDLE)
                {
                    ret = gdi_bitblt_resized_with_resizer(
                            gdi_image_9slice_cntx.src_layer, 
                            sx,
                            sy,
                            sx + sw - 1,
                            sy + sh - 1,
                            dx,
                            dy,
                            dx + dw - 1,
                            dy + dh - 1,
                            GDI_RESIZER_SW_QUALITY_MEDIUM);
                }

                //dither        
                if (gdi_act_layer->cf != GDI_COLOR_FORMAT_16 && gdi_act_layer->cf != GDI_COLOR_FORMAT_PARGB6666)
                {
                    gdi_image_9slice_dither_buf(&act_buf, &act_buf, 
                        act_area.x2 - act_area.x1 + 1, act_area.y2 - act_area.y1 + 1);
                }
                else if (dither_layer != GDI_NULL_HANDLE)
                {
                    gdi_image_9slice_dither_buf(&dst_buf, &act_buf, 
                        act_area.x2 - act_area.x1 + 1, act_area.y2 - act_area.y1 + 1);
                }
            }
            else
        #endif
            {
                ret = gdi_bitblt_resized_with_resizer(
                        gdi_image_9slice_cntx.src_layer, 
                        sx,
                        sy,
                        sx + sw - 1,
                        sy + sh - 1,
                        dx,
                        dy,
                        dx + dw - 1,
                        dy + dh - 1,
                        GDI_RESIZER_SW_QUALITY_MEDIUM);
            }

            break;
        }
    }while(0);
    
    //dither
    if (dither_layer != GDI_NULL_HANDLE)
    {
        gdi_image_free_temp_layer(dither_layer);
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_repeat_mode
 * DESCRIPTION
 *  copy source data to dest.
 *  If dest region larger than source region, repeat source patten to fill dest region.
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 *  sw              [IN]       source w
 *  sh              [IN]       source h
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_fill_with_repeat_mode(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    S32 tmp_x = dx;
    S32 tmp_y = dy;
    S32 total_w = dw;
    S32 total_h = dh;
    S32 clip_x = 0;
    S32 clip_y = 0;
    S32 clip_w = 0;
    S32 clip_h = 0;
    gdi_layer_struct* src_layer = NULL;
    gdi_rect_struct dst_area;
    kal_bool do_switch = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
        //SLA_CustomLogging("NSR", SA_start);
#endif

    src_layer = (gdi_layer_struct*)gdi_image_9slice_cntx.src_layer;

    // Swith layer buffer from non-cacheable to cacheable
    #if defined(GDI_9SLICE_USING_DYNAMIC_SWITCH)
    gdi_image_9slice_dynamic_switch_to_cachable(&do_switch,src_layer);
    #endif

    gdi_layer_push_clip();
    /* reset clip to the interaction of (dx, dy, dx2, dy2) and current clip */
    do{
        dst_area.x1 = dx;
        dst_area.y1 = dy;
        dst_area.x2 = dx + dw - 1;
        dst_area.y2 = dy + dh - 1;
        
        if(dst_area.x1 >= 0 && dst_area.y1 >= 0)
        {
            GDI_CLIP_RECT_TEST(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2, break);
            gdi_layer_set_clip(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2);

            clip_x = (dst_area.x1-dx)/sw *sw + dx;
            clip_y = (dst_area.y1-dy)/sh *sh + dy;
        }
        else
        {
            clip_x = dst_area.x1;
            clip_y = dst_area.y1;
            GDI_CLIP_RECT_TEST(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2, break);
            gdi_layer_set_clip(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2);
        }

        clip_w = ((dst_area.x2 - clip_x)/sw+1) *sw ;
        clip_h = ((dst_area.y2 - clip_y)/sh+1) *sh ;
        
    }while(0);

    tmp_y = clip_y;
    total_h = clip_h;
    while(total_h > 0)
    {
        S32 tmp_h = sh;

        if (total_h < tmp_h)
        {
            tmp_h = total_h;
        }
        tmp_x = clip_x; 
        total_w = clip_w;

        while(total_w > 0)
        {
            S32 tmp_w = sw;
            if (total_w < tmp_w)
            {
                tmp_w = total_w;
            }
            ret = gdi_image_9slice_bitblt(
                    tmp_x,
                    tmp_y,
                    tmp_w,
                    tmp_h,
                    sx,
                    sy);

            if (ret <= GDI_FAILED)
            {
                break;
            }
            tmp_x += sw;
            total_w -= sw;
        }

        if (ret <= GDI_FAILED)
        {
            break;
        }
        tmp_y += sh;
        total_h -= sh;
    }
    gdi_layer_pop_clip();

    // Swith layer buffer from cacheable to non-cacheable
    #if defined(GDI_9SLICE_USING_DYNAMIC_SWITCH)
    gdi_image_9slice_dynamic_switch_to_noncachable(&do_switch,src_layer);
    #endif

#ifdef __MAUI_SOFTWARE_LA__
        //SLA_CustomLogging("NSR", SA_stop);
#endif    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_linear_transform
 * DESCRIPTION
 *  fill dest region with the color in source region on src_layer by using linear transform
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 *  sw              [IN]       source w
 *  sh              [IN]       source h
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_fill_with_linear_transform(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    gdi_result ret = GDI_SUCCEED;
    
    gdi_lt_matrix_struct transform; 
    kal_uint32 linear_transform_flag = 0;

    if(gdi_image_9slice_cntx.src_layer == GDI_NULL_HANDLE)
    {
        GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_9SLICE_SOURCE_INFO);    
        return GDI_FAILED;
    }

    /* linear transform flag set-up */
    /* ps. here we only set this, because other config is already set in advane */
    linear_transform_flag |= GDI_LT_FLAG_NON_BLOCKING;

    transform.m[0] = (float)dw/sw;
    transform.m[1] = 0.0f;
    transform.m[2] = dx; 
    transform.m[3] = 0.0f;
    transform.m[4] = (float)dh/sh;   
    transform.m[5] = dy; 
    transform.m[6] = 0.0f;
    transform.m[7] = 0.0f;
    transform.m[8] = 1.0f;

    ret = gdi_2d_linear_transfrom_for_9slice(
            transform.m,
            sx,
            sy,
            sw,
            sh,
            dx,
            dy,
            dw,
            dh,
            linear_transform_flag);
    
    return ret;
}

#if !defined(GDI_9SLICE_FOR_LOW_COST_SLIM_PROJECT)
/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_LT_by_given_layer
 * DESCRIPTION
 *  fill dest region with the color in source region on src_layer by giving a layer
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 *  sw              [IN]       source w
 *  sh              [IN]       source h
 *  linear_transform_flag [IN] 
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_fill_with_LT_by_given_layer(
                    gdi_handle src_layer,
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_handle original_src_layer = gdi_image_9slice_cntx.src_layer;
    
    gdi_image_9slice_cntx.src_layer = src_layer;

    ret = gdi_image_9slice_fill_with_linear_transform(dx,dy,dw,dh,sx,sy,sw,sh);

    gdi_image_9slice_cntx.src_layer = original_src_layer;
    
    return ret;
}

static GDI_RESULT gdi_image_9slice_fill_with_LT_by_given_layer_tmp(
                    gdi_handle src_layer,
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_handle original_src_layer = gdi_image_9slice_cntx.src_layer;

    gdi_lt_matrix_struct transform; 
    GDI_LT_SRC_KEY_EDGE_FILTER_ENUM edge_filter = GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE;
    kal_uint32 edge_filter_color = GDI_COLOR_WHITE;
    GDI_LT_SAMPLE_MODE_ENUM mode = GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE;
    kal_uint32 linear_transform_flag = 0;
    
    gdi_image_9slice_cntx.src_layer = src_layer;


    if(gdi_image_9slice_cntx.src_layer == GDI_NULL_HANDLE)
    {
        GDI_TRACE(GDI_TRC_DECODE,GDI_TRC_9SLICE_SOURCE_INFO);    
        return GDI_FAILED;
    }

    /* linear transform flag set-up */
    linear_transform_flag |= GDI_LT_FLAG_NON_BLOCKING;
    linear_transform_flag |= GDI_LT_FLAG_SOURCE_KEY_DISABLE;

    //if(gdi_image_9slice_cntx.do_dithering)
    //{   
    //    linear_transform_flag |= GDI_LT_FLAG_USE_FIXED_PATTERN_DITHER; 
    //}

    /* do direct output or alpha blending */
    if( gdi_image_9slice_cntx.do_alpha_blending == KAL_FALSE ||
        ((gdi_act_layer->cf == GDI_COLOR_FORMAT_32_PARGB || gdi_act_layer->cf == GDI_COLOR_FORMAT_32 || gdi_act_layer->cf == GDI_COLOR_FORMAT_PARGB6666) && 
         (gdi_image_9slice_cntx.do_alpha_blending == KAL_TRUE) &&
         (gdi_image_9slice_cntx.force_alpha_blending == KAL_FALSE))
       )
    {   
        linear_transform_flag |= GDI_LT_FLAG_USE_DIRECT_OUTPUT; 
    }

    transform.m[0] = (float)dw/sw;
    transform.m[1] = 0.0f;
    transform.m[2] = dx; 
    transform.m[3] = 0.0f;
    transform.m[4] = (float)dh/sh;   
    transform.m[5] = dy; 
    transform.m[6] = 0.0f;
    transform.m[7] = 0.0f;
    transform.m[8] = 1.0f;

    ret = gdi_2d_linear_transfrom(
            transform.m,
            gdi_image_9slice_cntx.src_layer,
            sx,
            sy,
            sw,
            sh,
            dx,
            dy,
            dw,
            dh,
            edge_filter,
            edge_filter_color,
            mode,
            linear_transform_flag);

    gdi_image_9slice_cntx.src_layer = original_src_layer;
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_repeat_mode_without_blending
 * DESCRIPTION
 *  copy source data to dest.
 *  If dest region larger than source region, repeat source patten to fill dest region.
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 *  sw              [IN]       source w
 *  sh              [IN]       source h
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_9slice_fill_with_repeat_mode_without_blending(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_rect_struct dst_area;
    kal_bool boundary_aligned = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(gdi_act_layer->cf == ((gdi_layer_struct*)gdi_image_9slice_cntx.src_layer)->cf);
    
    do
    { 
        gdi_layer_push_clip();
        
        /* reset clip to the interaction of (dx, dy, dx2, dy2) and current clip */
        dst_area.x1 = dx;
        dst_area.y1 = dy;
        dst_area.x2 = dx + dw - 1;
        dst_area.y2 = dy + dh - 1;

        /* check if boundary alinged */
        if(dst_area.x1 >= 0 && dst_area.y1 >= 0)
        {
            GDI_CLIP_RECT_TEST(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2, break);
            gdi_layer_set_clip(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2);

            if( ((dst_area.x1-dx)%sw) == 0 && ((dst_area.y1-dy)%sh) == 0 )
            {
                boundary_aligned = KAL_TRUE;
            }
        }
        else
        {
            // boundary_aligned = KAL_FALSE; //for sure is false
            GDI_CLIP_RECT_TEST(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2, break);
            gdi_layer_set_clip(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2);
            dst_area.x1 = dx;
            dst_area.y1 = dy;
        }
        
        if(boundary_aligned == KAL_TRUE)
        {
            gdi_layer_struct *src_layer = (gdi_layer_struct*)gdi_image_9slice_cntx.src_layer;
            gdi_img_buf_struct dst_buf, src_buf, orig_src_buf;
            gdi_rect_struct src_area;
            S32 dst_buf_bpp = (S32)gdi_act_layer->bits_per_pixel >> 3; //buffer byte per pixel
            S32 curr_x = dst_area.x1;
            S32 curr_y = dst_area.y1;
            S32 dest_x = dst_area.x2+1;
            S32 dest_y = dst_area.y2+1;
            S32 dest_w = dst_area.x2 - dst_area.x1 +1;
            S32 dest_h = dst_area.y2 - dst_area.y1 +1;
            S32 tmp_w = sw;
            S32 tmp_h = sh; 
            U8* dst_ptr = NULL;
            kal_bool do_switch = KAL_FALSE;

            #if defined(GDI_9SLICE_USING_DYNAMIC_SWITCH)
            gdi_image_9slice_dynamic_switch_to_cachable(&do_switch,gdi_act_layer);
            #endif

            ret = gdi_img_buf_prepare_img_buf_struct(
                    &dst_buf,
                    &dst_area,
                    gdi_act_layer->buf_ptr,
                    (S32)gdi_act_layer->width,
                    dst_buf_bpp,
                    (U32)gdi_act_layer->vcf,
                    -1, -1, -1, -1);

            src_area.x1 = sx;
            src_area.y1 = sy;
            src_area.x2 = sx+sw-1;  
            src_area.y2 = sy+sh-1;  
            ret = gdi_img_buf_prepare_img_buf_struct(
                    &orig_src_buf,
                    &src_area,
                    src_layer->buf_ptr,
                    (S32)src_layer->width,
                    (S32)src_layer->bits_per_pixel >> 3,
                    (U32)src_layer->vcf,
                    -1, -1, -1, -1);

            src_buf.ptr = dst_buf.ptr;
            src_buf.color_format = dst_buf.color_format;
            src_buf.pitch_bytes = dst_buf.pitch_bytes;
            
            dst_ptr = gdi_act_layer->buf_ptr;

            /* start repeat */
            if( dest_w < sw )
            {
                tmp_w = dest_w;
            }

            if( dest_h < sh )
            {
                tmp_h = dest_h;
            }

            /* fill first block */
            gdi_img_buf_copy_same_format(&dst_buf, &orig_src_buf, tmp_w, tmp_h); //gdi_bitblt(gdi_image_9slice_cntx.src_layer,sx,sy,sx+sw-1,sy+sh-1,curr_x,curr_y);
            curr_x += tmp_w;
            dst_buf.ptr = dst_ptr + curr_y*dst_buf.pitch_bytes + curr_x*dst_buf_bpp;
            
            /* fill first row */
            while((curr_x+tmp_w) < dest_x)
            {
                gdi_img_buf_copy_same_format(&dst_buf, &src_buf, tmp_w, tmp_h); //gdi_bitblt((gdi_handle)gdi_act_layer,dst_area.x1,dst_area.y1,curr_x-1,curr_y+tmp_h-1,curr_x,curr_y);
                curr_x += tmp_w;
                tmp_w <<= 1;  //actually tmp_x = dx
                dst_buf.ptr = dst_ptr + (curr_y)*dst_buf.pitch_bytes + curr_x*dst_buf_bpp;
            }
            
            tmp_w = dest_x - curr_x;
            if(tmp_w)
            {
                gdi_img_buf_copy_same_format(&dst_buf, &src_buf, tmp_w, tmp_h);//gdi_bitblt((gdi_handle)gdi_act_layer,dst_area.x1,dst_area.y1,dst_area.x1+tmp_w-1,curr_y+tmp_h-1,curr_x,curr_y);
            }

            tmp_w = dest_w;
            curr_x = dst_area.x1;
            curr_y += tmp_h;
            dst_buf.ptr = dst_ptr + curr_y*dst_buf.pitch_bytes + curr_x*dst_buf_bpp;
           
            /* fill rest rows */
            while((curr_y+tmp_h) < dest_y)
            {
                gdi_img_buf_copy_same_format(&dst_buf, &src_buf, tmp_w, tmp_h);//gdi_bitblt((gdi_handle)gdi_act_layer,dst_area.x1,dst_area.y1,curr_x-1,curr_y-1,dst_area.x1,curr_y);
                curr_y += tmp_h;
                tmp_h <<= 1;  //actually tmp_x = dx
                dst_buf.ptr = dst_ptr + curr_y*dst_buf.pitch_bytes + curr_x*dst_buf_bpp;
            }
            
            tmp_h = dest_y - curr_y;
            if(tmp_h)
            {
                gdi_img_buf_copy_same_format(&dst_buf, &src_buf, tmp_w, tmp_h);//gdi_bitblt((gdi_handle)gdi_act_layer,dst_area.x1,dst_area.y1,curr_x-1,dst_area.y1+tmp_h-1,dst_area.x1,curr_y);
                dst_buf.ptr = dst_ptr + curr_y*dst_buf.pitch_bytes + curr_x*dst_buf_bpp;
            }

            #if defined(GDI_9SLICE_USING_DYNAMIC_SWITCH)
            gdi_image_9slice_dynamic_switch_to_noncachable(&do_switch,gdi_act_layer);
            #endif
        }
        else
        {
            gdi_image_9slice_fill_with_repeat_mode(dx,dy,dw,dh,sx,sy,sw,sh);
        }

         gdi_layer_reset_clip(); 
         gdi_layer_pop_clip();

    }while(0);
            
    
    return ret;  
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_repeat_mode_with_blending
 * DESCRIPTION
 *  copy source data to dest.
 *  If dest region larger than source region, repeat source patten to fill dest region.
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 *  sw              [IN]       source w
 *  sh              [IN]       source h
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_9slice_fill_with_repeat_mode_with_blending(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    gdi_handle blend_layer = GDI_NULL_HANDLE;
    U8 blend_layer_cf = ((gdi_layer_struct*)gdi_image_9slice_cntx.src_layer)->cf;
    int blend_layer_width = 0;
    int blend_layer_height = 0;
    S32 tmp_x = dx;
    S32 tmp_y = dy;
    S32 total_w = dw;
    S32 total_h = dh;
    S32 clip_x = 0;
    S32 clip_y = 0;
    S32 clip_w = 0;
    S32 clip_h = 0;
    U8 width_block = 0;
    U8 height_block = 0;
    gdi_rect_struct dst_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    
    /* reset clip to the interaction of (dx, dy, dx2, dy2) and current clip */
    do{
        dst_area.x1 = dx;
        dst_area.y1 = dy;
        dst_area.x2 = dx + dw - 1;
        dst_area.y2 = dy + dh - 1;
        
        if(dst_area.x1 >= 0 && dst_area.y1 >= 0)
        {
            GDI_CLIP_RECT_TEST(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2, break);
            gdi_layer_set_clip(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2);

            clip_x = (dst_area.x1-dx)/sw *sw + dx;
            clip_y = (dst_area.y1-dy)/sh *sh + dy;
        }
        else
        {
            clip_x = dst_area.x1;
            clip_y = dst_area.y1;
            GDI_CLIP_RECT_TEST(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2, break);
            gdi_layer_set_clip(dst_area.x1, dst_area.y1, dst_area.x2, dst_area.y2);
        }

        clip_w = ((dst_area.x2 - clip_x)/sw+1) *sw; 
        clip_h = ((dst_area.y2 - clip_y)/sh+1) *sh; 
    }while(0);

    blend_layer_width = clip_w;
    blend_layer_height = clip_h;
    width_block = blend_layer_width/sw;
    height_block = blend_layer_height/sh;
     
    do{
        ret = gdi_image_create_temp_layer(
                &blend_layer,
                blend_layer_cf,
                0,
                0,
                blend_layer_width,
                blend_layer_height);

        if(ret == GDI_SUCCEED)
            break;

        if(sw > sh)
        {
            if(height_block == 1)
                break;
            height_block >>= 1;
            blend_layer_height = height_block*sh;
        }
        else
        {
            if(width_block == 1)
                break;
            width_block >>= 1;
            blend_layer_width = width_block*sw;
        }
    }while(blend_layer == GDI_NULL_HANDLE);

    if(blend_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(blend_layer);
        ret = gdi_image_9slice_fill_with_repeat_mode_without_blending(
                    0,
                    0,
                    blend_layer_width,
                    blend_layer_height,
                    sx,
                    sy,
                    sw,
                    sh);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        gdi_layer_pop_clip();
        ret = gdi_image_9slice_fill_with_repeat_mode(dx,dy,dw,dh,sx,sy,sw,sh);
        return ret;
    }

    gdi_2d_LT_reset_src_buffer(blend_layer);

    tmp_y = clip_y;
    total_h = clip_h;
    while(total_h > 0)
    {
        S32 tmp_h = blend_layer_height;

        if (total_h < tmp_h)
        {
            tmp_h = total_h;
        }
        tmp_x = clip_x; 
        total_w = clip_w;

        while(total_w > 0)
        {
            S32 tmp_w = blend_layer_width;
            if (total_w < tmp_w)
            {
                tmp_w = total_w;
            }
            
            /* block-wise alpha blending */
            ret = gdi_image_9slice_fill_with_LT_by_given_layer(
                    blend_layer,
                    tmp_x,
                    tmp_y,
                    tmp_w,
                    tmp_h,
                    0,
                    0,
                    tmp_w,
                    tmp_h);

            if (ret <= GDI_FAILED)
            {
                break;
            }
            tmp_x += blend_layer_width;
            total_w -= blend_layer_width;
        }

        if (ret <= GDI_FAILED)
        {
            break;
        }
        tmp_y += blend_layer_height;
        total_h -= blend_layer_height;
    }

    gdi_2d_LT_reset_src_buffer(gdi_image_9slice_cntx.src_layer);
    
    gdi_layer_pop_clip();

    if(blend_layer != GDI_NULL_HANDLE)
        gdi_image_free_temp_layer(blend_layer); 

    return ret;
}

GDI_RESULT gdi_image_9slice_LT_pre_setting()
{
    /* get linear transform g2dhandle and presetting */    
    gdi_layer_struct *src_layer = (gdi_layer_struct*)gdi_image_9slice_cntx.src_layer;
    gdi_lcd_layer_struct *layer_info = &gdi_layer_info[src_layer->id];
    static G2D_HANDLE_STRUCT* g2d_LT_handle= NULL;
    kal_bool force_to_sw = MMI_FALSE;
    kal_uint32 linear_transform_flag = 0;

    /* linear transform flag set-up */
    {
        linear_transform_flag |= GDI_LT_FLAG_NON_BLOCKING;
        linear_transform_flag |= GDI_LT_FLAG_SOURCE_KEY_DISABLE;

        if(gdi_image_9slice_cntx.do_dithering)
        {   
            linear_transform_flag |= GDI_LT_FLAG_USE_FIXED_PATTERN_DITHER; 
        }
    }
    
    gdi_2d_LT_nb_wait_for_previous_finish();
    gdi_2d_LT_nb_init_state(NULL, NULL);

    gdi_2d_LT_get_g2dhandle(&g2d_LT_handle,layer_info,&force_to_sw);
    
    gdi_2d_LT_all_setting(
        g2d_LT_handle,
        src_layer,
        layer_info,
        GDI_LT_SRC_KEY_EDGE_FILTER_DULPLICATE,
        GDI_COLOR_WHITE,
        GDI_LT_SAMPLE_MODE_BILINEAR_WITH_EDGE_FILTER_DULPLICATE,
        linear_transform_flag);
    
    gdi_2d_LT_nb_release_event();
    return GDI_SUCCEED;
}

void gdi_image_9slice_LT_post_setting()
{
    gdi_2d_LT_wait_for_current_finish();
    gdi_2d_LT_nb_release_g2d_handle();
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_repeat_mode_LT
 * DESCRIPTION
 *  fill dest region with the color in source region on src_layer and fill in with repeat mode
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_9slice_fill_with_repeat_mode_LT(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    GDI_RESULT ret = GDI_SUCCEED;
    
    if(gdi_image_9slice_cntx.do_alpha_blending)
    {
        gdi_image_9slice_fill_with_repeat_mode_with_blending(dx,dy,dw,dh,sx,sy,sw,sh);
    }
    else
    {
        gdi_image_9slice_fill_with_repeat_mode_without_blending(dx,dy,dw,dh,sx,sy,sw,sh);
    }

    return ret;
}
#endif



kal_bool g_9slice_debug_rect = KAL_FALSE;
kal_bool g_print_9slice_str_01 = KAL_FALSE;
kal_bool g_print_9slice_str_02 = KAL_FALSE;
kal_bool g_print_9slice_str_03 = KAL_FALSE;
/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_fill_with_stretch_mode
 * DESCRIPTION
 *  fill destination area by source data
 * PARAMETERS
 *  dx              [IN]       dest x
 *  dy              [IN]       dest y
 *  dw              [IN]       dest w
 *  dh              [IN]       dest h
 *  sx              [IN]       source x
 *  sy              [IN]       source y
 *  sw              [IN]       source w
 *  sh              [IN]       source h
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_fill_dest_area(
                    S32 dx,
                    S32 dy,
                    S32 dw,
                    S32 dh,
                    S32 sx,
                    S32 sy,
                    S32 sw,
                    S32 sh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    gdi_rect_struct dest_clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((sw == 0) || (sh == 0))
    {
        return GDI_SUCCEED;
    }

    gdi_layer_push_clip();
    do
    {
        /* reset clip to the interaction of (dx, dy, dx2, dy2) and current clip */
        dest_clip.x1 = dx;
        dest_clip.y1 = dy;
        dest_clip.x2 = dx + dw - 1;
        dest_clip.y2 = dy + dh - 1;
        GDI_CLIP_RECT_TEST(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2, break);
        gdi_layer_set_clip(dest_clip.x1, dest_clip.y1, dest_clip.x2, dest_clip.y2);
        
        if ((sw == 1) && (sh == 1))
        {
            #if defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
                /* Optimize when alpha is zero */ 
                if((gdi_image_9slice_cntx.src_layer != GDI_NULL_HANDLE) && 
                   (gdi_image_9slice_cntx.do_alpha_blending == KAL_TRUE && gdi_image_9slice_cntx.force_alpha_blending == KAL_TRUE))
                {
                    gdi_color src_color = 0;
                    U32 cA, cR, cG, cB;
                    gdi_layer_push_and_set_active(gdi_image_9slice_cntx.src_layer);
                    src_color = gdi_act_get_pixel(sx, sy);
                    gdi_act_color_to_rgb(&cA, &cR, &cG, &cB, src_color);
                    gdi_layer_pop_and_restore_active();
                    if(cA == 0)
                    {
                        break;
                    }
                }
                ret = gdi_image_9slice_fill_with_linear_transform(dx, dy, dw, dh, sx, sy,1,1);
            #else
            ret = gdi_image_9slice_fill_with_src_color(dx, dy, dw, dh, sx, sy);
            #endif
            break;
        }

        if ((sw == dw) && (sh == dh))
        {
            #if defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
                    ret = gdi_image_9slice_fill_with_linear_transform(dx, dy, dw, dh, sx, sy, dw, dh);
            #else
            ret = gdi_image_9slice_bitblt(dx, dy, dw, dh, sx, sy);
            #endif
            break;
        }
        else if (sh == 1 && 
            (gdi_image_9slice_cntx.fill_mode == GDI_IMAGE_9SLICE_FILL_MODE_STRETCH ||
            (gdi_image_9slice_cntx.fill_mode == GDI_IMAGE_9SLICE_FILL_MODE_REPEAT && sw == dw)))
        {
            #if defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
                ret = gdi_image_9slice_fill_with_linear_transform(dx, dy, dw, dh, sx, sy, sw, 1);
            #else
            ret = gdi_image_9slice_fill_with_src_horizontal_line(dx, dy, dw, dh, sx, sy, sw);
            #endif
            break;
        }
        else if (sw == 1 &&
            (gdi_image_9slice_cntx.fill_mode == GDI_IMAGE_9SLICE_FILL_MODE_STRETCH ||
            (gdi_image_9slice_cntx.fill_mode == GDI_IMAGE_9SLICE_FILL_MODE_REPEAT && sh == dh)))
        {
            #if defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
                ret = gdi_image_9slice_fill_with_linear_transform(dx, dy, dw, dh, sx, sy, 1, sh);
            #else
            ret = gdi_image_9slice_fill_with_src_vertical_line(dx, dy, dw, dh, sx, sy, sh);
            #endif
            break;
        }

        if (gdi_image_9slice_cntx.fill_mode == GDI_IMAGE_9SLICE_FILL_MODE_STRETCH)
        {
            #if defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
                ret = gdi_image_9slice_fill_with_linear_transform(dx, dy, dw, dh, sx, sy, sw, sh);
            #else
            ret = gdi_image_9slice_fill_with_stretch_mode(dx, dy, dw, dh, sx, sy, sw, sh);
            #endif
            break;
        }
        else if (gdi_image_9slice_cntx.fill_mode == GDI_IMAGE_9SLICE_FILL_MODE_REPEAT)
        {
            #if defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
                ret = gdi_image_9slice_fill_with_repeat_mode_LT(dx, dy, dw, dh, sx, sy, sw, sh);
            #else
            ret = gdi_image_9slice_fill_with_repeat_mode(dx, dy, dw, dh, sx, sy, sw, sh);
            #endif
            break;
        }
        else
        {
            GDI_ASSERT(0);
        }
    }while(0);
    
    gdi_layer_pop_clip();
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_upscale_init
 * DESCRIPTION
 *  init 9slice image data strcture
 * PARAMETERS
 *  src_layer           [IN]       source layer
 *  img_ptr             [IN]       img data pointer
 *  img_size            [IN]       img data size
 *  img_type            [IN]       img type
 *  img_w               [IN]       image dimension width
 *  img_h               [IN]       image dimension height
 *  do_alpha_blending   [IN]       alpha blending or not
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_upscale_init(
                    gdi_handle src_layer,
                    U8 *img_ptr,
                    U32 img_size,
                    U32 img_type,
                    S32 img_w,
                    S32 img_h,
                    kal_bool do_alpha_blending,
                    gdi_image_9slice_fill_mode_enum fill_mode,
                    kal_bool do_dither)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_9slice_cntx.src_layer = src_layer;
    gdi_image_9slice_cntx.img_ptr = img_ptr;
    gdi_image_9slice_cntx.img_size = img_size;
    gdi_image_9slice_cntx.img_type = img_type;
    gdi_image_9slice_cntx.img_w = img_w;
    gdi_image_9slice_cntx.img_h = img_h;
    gdi_image_9slice_cntx.do_alpha_blending = do_alpha_blending;
    gdi_image_9slice_cntx.fill_mode = fill_mode;
    gdi_image_9slice_cntx.do_dithering = do_dither;

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_upscale
 * DESCRIPTION
 *  upscale 9slice image
 *  If temp_layer is null, decode to dest region.
 *  If temp_layer is not null, copy data from temp_layer to active layer.
 * PARAMETERS
 *  temp_layer          [IN]       temp layer
 *  img_ptr             [IN]       img data pointer
 *  img_size            [IN]       img data size
 *  img_type            [IN]       img type
 *  img_w               [IN]       image dimension width
 *  img_h               [IN]       image dimension height
 *  margin_left         [IN]       left margin
 *  margin_top          [IN]       top margin
 *  margin_right        [IN]       right margin
 *  margin_bottom       [IN]       bottom margin
 *  dest_x              [IN]       dest x
 *  dest_y              [IN]       dest y
 *  dest_w              [IN]       dest w
 *  dest_h              [IN]       dest h
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_9slice_upscale(
                    S32 margin_left,
                    S32 margin_top,
                    S32 margin_right,
                    S32 margin_bottom,
                    S32 dest_x,
                    S32 dest_y,
                    S32 dest_w,
                    S32 dest_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;
    S32 img_mid_w = gdi_image_9slice_cntx.img_w - margin_left - margin_right;
    S32 img_mid_h = gdi_image_9slice_cntx.img_h - margin_top - margin_bottom;
    S32 dest_mid_w = dest_w - margin_left - margin_right;
    S32 dest_mid_h = dest_h - margin_top - margin_bottom;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GDI_TRACE(GDI_TRC_DECODE, GDI_TRC_9SLICE_MARGIN_INFO, gdi_image_9slice_cntx.img_w, gdi_image_9slice_cntx.img_h,
                             margin_left, margin_top, margin_right, margin_bottom, dest_w, dest_h);
    
    /* GDI_ASSERT((img_mid_w >= 0) && (img_mid_h >= 0)); */
    if (img_mid_w < 0 || img_mid_h < 0)
    {
        GDI_TRACE(TRACE_GROUP_1, GDI_TRC_9SLICE_MARGIN_ERROR_1,
                  margin_left, margin_top, margin_right, margin_bottom,
                  img_mid_w, img_mid_h);
        return GDI_FAILED;
    }

    /* GDI_ASSERT((dest_w >= margin_left + margin_right) && (dest_h >= margin_top + margin_bottom)); */
    if (dest_w < (margin_left + margin_right) || dest_h < (margin_top + margin_bottom))
    {
        GDI_TRACE(TRACE_GROUP_1, GDI_TRC_9SLICE_MARGIN_ERROR_2,
                  margin_left, margin_top, margin_right, margin_bottom,
                  dest_w, dest_h);
        return GDI_FAILED;
    }

    #if defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
    gdi_image_9slice_LT_pre_setting();
    #endif

    do
    {
        /* draw left-top corner. */
        ret = gdi_image_9slice_fill_dest_area(
                dest_x,
                dest_y,
                margin_left,
                margin_top,
                0,
                0,
                margin_left,
                margin_top);
        if (ret <= GDI_FAILED)
        {
            break;
        }
        if (debug_9slice==1){
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\D_01_left_top.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\D_01_left_top.bmp");
            #endif
        }
        
        /* draw right-top corner. */
        ret = gdi_image_9slice_fill_dest_area(
                dest_x + (dest_w - margin_right),
                dest_y,
                margin_right,
                margin_top,
                gdi_image_9slice_cntx.img_w - margin_right,
                0,
                margin_right,
                margin_top);
        if (ret <= GDI_FAILED)
        {
            break;
        }
        if (debug_9slice==1){
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\D_02_right_top.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\D_02_right_top.bmp");
            #endif
        }
        
        /* draw left-bottom corner. */
        ret = gdi_image_9slice_fill_dest_area(
                dest_x,
                dest_y + (dest_h - margin_bottom),
                margin_left,
                margin_bottom,
                0,
                gdi_image_9slice_cntx.img_h - margin_bottom,
                margin_left,
                margin_bottom);
        if (ret <= GDI_FAILED)
        {
            break;
        }
        if (debug_9slice==1){
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\D_03_left_bottom.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\D_03_left_bottom.bmp");
            #endif
        }
        
        /* draw right-bottom corner. */
        ret = gdi_image_9slice_fill_dest_area(
                dest_x + (dest_w - margin_right),
                dest_y + (dest_h - margin_bottom),
                margin_right,
                margin_bottom,
                gdi_image_9slice_cntx.img_w - margin_right,
                gdi_image_9slice_cntx.img_h - margin_bottom,
                margin_right,
                margin_bottom);
        if (ret <= GDI_FAILED)
        {
            break;
        }
        if (debug_9slice==1){
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\D_04_right_bottom.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\D_04_right_bottom.bmp");
            #endif
        }
        
        /* draw top margin */
        ret = gdi_image_9slice_fill_dest_area(
                dest_x + margin_left,
                dest_y,
                dest_mid_w,
                margin_top,
                margin_left,
                0,
                img_mid_w,
                margin_top);
        if (ret <= GDI_FAILED)
        {
            break;
        }
        if (debug_9slice==1){
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\D_05_top.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\D_05_top.bmp");
            #endif
        }
        
        /* draw bottom margin */
        ret = gdi_image_9slice_fill_dest_area(
                dest_x + margin_left,
                dest_y + (dest_h - margin_bottom),
                dest_mid_w,
                margin_bottom,
                margin_left,
                gdi_image_9slice_cntx.img_h - margin_bottom,
                img_mid_w,
                margin_bottom);
        if (ret <= GDI_FAILED)
        {
            break;
        }
        if (debug_9slice==1){
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\D_06_bottom.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\D_06_bottom.bmp");
            #endif
        }
        
        /* draw left margin */
        ret = gdi_image_9slice_fill_dest_area(
                dest_x,
                dest_y + margin_top,
                margin_left,
                dest_mid_h,
                0,
                margin_top,
                margin_left,
                img_mid_h);
        if (ret <= GDI_FAILED)
        {
            break;
        }
        if (debug_9slice==1){
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\D_07_left.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\D_07_left.bmp");
            #endif
        }
        
        /* draw right margin */
        ret = gdi_image_9slice_fill_dest_area(
                dest_x + (dest_w - margin_right),
                dest_y + margin_top,
                margin_right,
                dest_mid_h,
                gdi_image_9slice_cntx.img_w - margin_right,
                margin_top,
                margin_right,
                img_mid_h);
        if (ret <= GDI_FAILED)
        {
            break;
        }
        if (debug_9slice==1){
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\D_08_right.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\D_08_right.bmp");
            #endif
        }
        
        /* draw middle area */
        ret = gdi_image_9slice_fill_dest_area(
                dest_x + margin_left,
                dest_y + margin_top,
                dest_mid_w,
                dest_mid_h,
                margin_left,
                margin_top,
                img_mid_w,
                img_mid_h);
        if (ret <= GDI_FAILED)
        {
            break;
        }
        if (debug_9slice==1){
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\D_09_middle.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\D_09_middle.bmp");
            #endif
        }
    }while(0);

    #if defined(GDI_9SLICE_USING_LINEAR_TRANSFORM)
    gdi_image_9slice_LT_post_setting();
    #endif

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_is_able_to_downscale
 * DESCRIPTION
 *  return does the decoder of the img_type support downsclale
 * PARAMETERS
 *  img_type            [IN]       img type
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static kal_bool gdi_image_9slice_is_able_to_downscale(U32 img_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(img_type)
    {
        case GDI_IMAGE_TYPE_DEVICE_BITMAP:
        case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
        case GDI_IMAGE_TYPE_DEVICE_BMP_FILE:
        case GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET:
            return KAL_FALSE;

        default:
            return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_do_alpha_blending
 * DESCRIPTION
 *  return will the decoder do alpha blending
 * PARAMETERS
 *  img_type            [IN]       img type
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static kal_bool gdi_image_9slice_do_alpha_blending(U32 img_type, kal_bool img_fully_opaque)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle src_layer_handle;
    kal_bool ret = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_get_alpha_blending_source_layer(&src_layer_handle);
    switch(img_type)
    {
        case GDI_IMAGE_TYPE_AB2:
        case GDI_IMAGE_TYPE_AB2_FILE:
        case GDI_IMAGE_TYPE_AB2_SEQUENCE:
        case GDI_IMAGE_TYPE_AB2_FILE_OFFSET:
        case GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_ABM:
        case GDI_IMAGE_TYPE_ABM_FILE:
        case GDI_IMAGE_TYPE_ABM_SEQUENCE:
        case GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_ABM_FILE_OFFSET:
        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_PNG_FILE:
        case GDI_IMAGE_TYPE_PNG_SEQUENCE:
        case GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
            if ((src_layer_handle == GDI_NULL_HANDLE || img_fully_opaque == KAL_TRUE) /*||
                (gdi_act_layer->cf == GDI_COLOR_FORMAT_32) || 
                (gdi_act_layer->cf == GDI_COLOR_FORMAT_32_PARGB)*/)
            {
                ret = KAL_FALSE;
            }
            else
            {
                ret = KAL_TRUE;
            }
            break;
            
        default:
            ret = KAL_FALSE;
            break;
    }
    return ret;
}


static gdi_result gdi_image_9slice_copy_alpha_blending_layer_to_active(
            		S32 x,
            		S32 y,
            		S32 w,
            		S32 h)
{
    gdi_result ret = GDI_SUCCEED;
	gdi_img_buf_struct dst_buf, src_buf;
    gdi_rect_struct dest_area, src_area;
    gdi_handle ab_handle;
    gdi_layer_struct *ab_struct;

    gdi_get_alpha_blending_source_layer(&ab_handle);
    ab_struct = (gdi_layer_struct*)ab_handle;
    
    do
    {
        /* if alpha blending source layer == act layer, return directly */
        if (ab_struct == gdi_act_layer)
        {
            ret = GDI_SUCCEED;
            break;
        }

        dest_area.x1 = x;
        dest_area.y1 = y;
        dest_area.x2 = x + w - 1;
        dest_area.y2 = y + h - 1;
        ret = gdi_img_buf_prepare_img_buf_struct(
                &dst_buf,
                &dest_area,
                gdi_act_layer->buf_ptr,
                (S32)gdi_act_layer->width,
                (S32)gdi_act_layer->bits_per_pixel >> 3,
                (U32)gdi_act_layer->vcf,
                (S32)gdi_act_layer->clipx1,
                (S32)gdi_act_layer->clipy1,
                (S32)gdi_act_layer->clipx2,
                (S32)gdi_act_layer->clipy2);
        if (ret == GDI_FAILED)  // null clip
        {
            ret = GDI_SUCCEED;
            break;
        }

        src_area.x1 = dest_area.x1 + gdi_act_layer->offset_x - ab_struct->offset_x;
        src_area.y1 = dest_area.y1 + gdi_act_layer->offset_y - ab_struct->offset_y;
        src_area.x2 = 0;  // don't care
        src_area.y2 = 0;  // don't care
        ret = gdi_img_buf_prepare_img_buf_struct(
                &src_buf,
                &src_area,
                ab_struct->buf_ptr,
                (S32)ab_struct->width,
                (S32)ab_struct->bits_per_pixel >> 3,
                (U32)ab_struct->vcf,
                -1, -1, -1, -1);

        gdi_img_buf_copy(
            &dst_buf, 
            &src_buf,
            dest_area.x2 - dest_area.x1 + 1,
            dest_area.y2 - dest_area.y1 + 1);
    } while(0);

    return ret;
	
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_draw_mem
 * DESCRIPTION
 *  draw 9slice image
 * PARAMETERS
 *  flag            [IN]        flag
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 *  from_file       [IN]        img from file
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_9slice_draw_mem(
            U32 flag, 
            U32 frame_pos, 
            S32 x, 
            S32 y, 
            S32 w, 
            S32 h, 
            U8 *data_ptr,
            U32 img_size,
            kal_bool img_from_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *real_img_ptr = NULL;
    S32 real_img_size = 0;
    U32 real_img_type = GDI_IMAGE_TYPE_INVALID;
    S32 real_img_w, real_img_h;
    S32 margin_left, margin_top, margin_right, margin_bottom;
    gdi_image_9slice_fill_mode_enum fill_mode;
    U8 *temp_layer_buf = NULL;
    S32 temp_layer_buf_size = 0;
    gdi_color_format temp_layer_cf = GDI_COLOR_FORMAT_END;
    gdi_handle temp_layer = GDI_NULL_HANDLE;
    gdi_handle alpha_blend_src_layer = GDI_NULL_HANDLE;
    kal_bool do_dither = KAL_FALSE;
    kal_bool do_dither_from_txt = KAL_FALSE;
    gdi_result ret = GDI_SUCCEED;
    kal_bool img_fully_opaque = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("G9S", SA_start);
#endif  
    
    GDI_ENTER_CRITICAL_SECTION(gdi_image_9slice_draw_mem)

    do
    {
        /* parse 9slice 20byte header */
        ret = gdi_image_9slice_parse_header(
                data_ptr,
                img_size,
                &real_img_ptr,
                &real_img_size,
                &real_img_type,
                &margin_left,
                &margin_top,
                &margin_right,
                &margin_bottom,
                &fill_mode,
                &img_fully_opaque,
                &do_dither_from_txt,
                img_from_file);
        if (ret <= GDI_FAILED)
        {
            break;
        }

        // do dithering or not
#if defined(GDI_9SLICE_USING_DITHERING) 
        if (g_9slice_using_dither &&
                fill_mode != GDI_IMAGE_9SLICE_FILL_MODE_REPEAT &&
                (gdi_act_layer->cf == GDI_COLOR_FORMAT_16 || 
                gdi_act_layer->cf == GDI_COLOR_FORMAT_PARGB6666 ||
                gdi_act_layer->cf == GDI_COLOR_FORMAT_32 ||
                gdi_act_layer->cf == GDI_COLOR_FORMAT_32_PARGB))
        {
            do_dither = KAL_TRUE;
        }
#endif

        if (do_dither == KAL_TRUE && do_dither_from_txt == KAL_TRUE)
        {
            do_dither = KAL_TRUE;
        }
        else
        {
            do_dither = KAL_FALSE;
        }

        /* Force to do alpha blending if need to do dithering */
        if (do_dither == KAL_TRUE)
        {
            img_fully_opaque = KAL_FALSE;
        }

        /* get real image dimension */
        ret = gdi_image_get_dimension_mem(
                (U8)real_img_type,
                real_img_ptr,
                real_img_size,
                &real_img_w, 
                &real_img_h);
        if (ret <= GDI_FAILED)
        {
            break;
        }

        if ((w == 0) && (h == 0))
        {
            w = real_img_w;
            h = real_img_h;
        }
        else if ((w == 0) || (h == 0))
        {
            /* if only one side equals to 0, return success directly */
            ret = GDI_SUCCEED;
            break;
        }

        /* In the following conditions, draw original image directly */
        if (((w == real_img_w) && (h == real_img_h)) ||     /* 1. no resize */
            (((w < (margin_left + margin_right)) || (h < (margin_top + margin_bottom))) &&      /* 2. down-scale and the decoder support to down-scale */
             (gdi_image_9slice_is_able_to_downscale(real_img_type))))
        {
            if( (real_img_type == GDI_IMAGE_TYPE_ABM) && (gdi_image_9slice_cntx.force_alpha_blending == KAL_TRUE)) /* if it's abm and need to do alpha blending */
            {
                ret = gdi_image_create_temp_layer(
                        &temp_layer,
                        GDI_COLOR_FORMAT_32_PARGB,
                        0,
                        0,
                        real_img_w,
                        real_img_h);
                if(temp_layer == GDI_NULL_HANDLE)
                {
                    GDI_TRACE(GDI_TRC_CODEC_I,GDI_TRC_9SLICE_SOURCE_INFO);
                    break;
                }

                gdi_layer_push_and_set_active(temp_layer);
                ret = gdi_image_draw_mem(0, 0, real_img_ptr, (U8)real_img_type, real_img_size);
                gdi_layer_pop_and_restore_active();
                
                #if defined(GDI_9SLICE_FOR_LOW_COST_SLIM_PROJECT)
                    ret = GDI_IMAGE_ERR_INVALID_IMAGE_SIZE;
                #else
                ret = gdi_image_9slice_fill_with_LT_by_given_layer_tmp(
                        temp_layer,
                        x,
                        y,
                        w,
                        h,
                        0,
                        0,
                        real_img_w,
                        real_img_h);
                #endif

                if(temp_layer != GDI_NULL_HANDLE)
                {
  	                gdi_image_free_temp_layer(temp_layer);
  	                temp_layer = GDI_NULL_HANDLE;
                }
                break;
            }
            else
            {
                U32 temp_flag = 0;
                GDI_TRACE(GDI_TRC_DECODE, GDI_TRC_9SLICE_DRAW_ORIGINAL, /*[GDI][9slice]: Dest_W:%d Dest_H:%d Img_W:%d Img_H:%d L:%d T:%d R:%d B:%d*/
                                      w, h, real_img_w, real_img_h, margin_left, margin_top, margin_right, margin_bottom);                
                if((real_img_type == GDI_IMAGE_TYPE_AB2) && (gdi_image_9slice_cntx.force_alpha_blending == KAL_TRUE)) 
                {
                    temp_flag = flag;
                    flag |= GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND;
                    gdi_image_codec_set_flag(flag);
                }
                ret = gdi_image_draw_resized_mem(x, y, w, h, real_img_ptr, (U8)real_img_type, real_img_size);
                if((real_img_type == GDI_IMAGE_TYPE_AB2) && (gdi_image_9slice_cntx.force_alpha_blending == KAL_TRUE)) 
                {
                    flag = temp_flag;
                    gdi_image_codec_set_flag(flag);
                }
                break;
            }
        }

        /* DLT would assign ABM(v2) 9slice image with all margin are 0, decode it directly */
        /* else return error */
        if ((margin_left == 0) && (margin_top == 0) && (margin_right == 0) && (margin_bottom == 0) &&
            (real_img_w != 1) && (real_img_h != 1) &&
            (fill_mode == GDI_IMAGE_9SLICE_FILL_MODE_STRETCH))
        {
            if (/*(real_img_type == GDI_IMAGE_TYPE_ABM) ||*/ (real_img_type == GDI_IMAGE_TYPE_AB2))
            {
                if (debug_9slice==1)
                {
                    gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\aaa01.bmp");
                }
                ret = gdi_image_draw_resized_mem(x, y, w, h, real_img_ptr, (U8)real_img_type, real_img_size);
                if (debug_9slice==1)
                {
                    gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\aaa02.bmp");
                }
                break;
            }
            else if (real_img_type != GDI_IMAGE_TYPE_ABM)
            /* else */ // currently ABM can't up-scale when blend2layers, it's a bug
            {
                ret = GDI_IMAGE_ERR_9SLICE_MARGIN_ZERO;
                break;
            }
        }

        /* decide tmp layer color format */

        if (gdi_image_9slice_do_alpha_blending(real_img_type, img_fully_opaque))   /* If alpha blending, use PARGB32 color format */
        {
            temp_layer_cf = GDI_COLOR_FORMAT_32_PARGB;
        }
        else
        {
            temp_layer_cf = gdi_act_layer->cf;
        }
        
        /* alloc temp layer buffer */
        temp_layer_buf_size = gdi_sizeof_pixels(temp_layer_cf, real_img_w, real_img_h);
        if((temp_layer_buf_size < gdi_image_9slice_temp_layer_buf_size) && (gdi_image_9slice_temp_layer_buffer!=NULL)) 
        {
            temp_layer_buf = gdi_image_9slice_temp_layer_buffer;
        }
        else
        {
            temp_layer_buf = (U8*)gdi_alloc_ext_mem_framebuffer(temp_layer_buf_size);
        }
        /* If buffer is enough, create an image-size temp layer, draw image on it. */
        if (temp_layer_buf != NULL)
        {
            kal_bool source_key_enable;
            gdi_color source_key_value;

            /* if alpha blending source layer != act layer, copy data to act layer, 
               and alpha blending with act layer */
            gdi_get_alpha_blending_source_layer(&alpha_blend_src_layer);
 
           if (gdi_image_9slice_do_alpha_blending(real_img_type, img_fully_opaque) &&
               (alpha_blend_src_layer != (gdi_handle)gdi_act_layer))
            {            
                if (flag & GDI_IMAGE_CODEC_FLAG_BLEND_2_LAYERS)
                {
                    /* if blend2layers, blend first, then delete the flag. */
                    /* blend 2 layers */
                    gdi_layer_blend_2_layers(
                        alpha_blend_src_layer, 
                        x, 
                        y, 
                        x + w - 1, 
                        y + h - 1);
                }
                else
                {
                    /* copy alpha blending source layer data to active layer */
        			/* because we only do alpha blending with active layer in 9slice upscale. */
        			gdi_image_9slice_copy_alpha_blending_layer_to_active(x, y, w, h);
                }
                /* set act layer as srouce layer */
                gdi_push_and_set_alpha_blending_source_layer((gdi_handle)gdi_act_layer);
            }

            /* unflag blend2layers */
            flag |= gdi_image_codec_get_flag();
            flag &= (~GDI_IMAGE_CODEC_FLAG_BLEND_2_LAYERS);
            gdi_image_codec_set_flag(flag);

            /* create temp layer */
            gdi_layer_get_source_key((BOOL*)&source_key_enable, &source_key_value);
            gdi_layer_create_cf_using_outside_memory(
                temp_layer_cf,
                0,0,
                real_img_w,
                real_img_h,
                &temp_layer,
                temp_layer_buf,
                temp_layer_buf_size);
            
            gdi_layer_push_and_set_active(temp_layer);
            if(temp_layer_cf != GDI_COLOR_FORMAT_32_PARGB)
            {
            gdi_layer_clear(source_key_value);
            }
            gdi_push_and_set_alpha_blending_source_layer(GDI_NULL_HANDLE);
            gdi_layer_set_source_key((BOOL)KAL_FALSE, source_key_value);

            /* decode image to temp_layer_buf */
            {
                U32 temp_flag = flag;
                flag |= gdi_image_codec_get_flag();
                flag &= (~GDI_IMAGE_CODEC_FLAG_FORCE_AB2_ALPHA_BLEND);
                gdi_image_codec_set_flag(flag);
            
                ret = gdi_image_draw_mem(0, 0, real_img_ptr, (U8)real_img_type, real_img_size);

                flag = temp_flag;
                gdi_image_codec_set_flag(flag);
            }
            
            if (debug_9slice==1)
            {
                #ifdef __MTK_TARGET__
                gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\9slice_image_layer.bmp");
                #else
                gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\9slice_image_layer.bmp");
                #endif
            }

            gdi_pop_and_restore_alpha_blending_source_layer();
            gdi_layer_pop_and_restore_active();

            if (ret <= GDI_FAILED)
            {
                break;
            }
        }
        else
        {
            //GDI_ASSERT(0);
            ret = GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
            break;
        }

        /* If down-scale and the decoder can't decode directly, 
           decode to temp layer and user resizer. */
        /* currently only PBM not support down-scale */
        if (((w < real_img_w) || (h < real_img_h)) &&
            (gdi_image_9slice_is_able_to_downscale(real_img_type) == KAL_FALSE))
        {
            if ((temp_layer_buf == NULL) || (temp_layer == GDI_NULL_HANDLE))
            {
                ret = GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
                break;
            }
 
            if (gdi_image_9slice_do_alpha_blending(real_img_type, img_fully_opaque))
            {
                // TODO: down-scale and blending
                //ret = GDI_IMAGE_ERR_INVALID_IMAGE_SIZE;
                #if defined(GDI_9SLICE_FOR_LOW_COST_SLIM_PROJECT)
                    ret = GDI_IMAGE_ERR_INVALID_IMAGE_SIZE;
                #else
                ret = gdi_image_9slice_fill_with_LT_by_given_layer_tmp(
                        temp_layer,
                        x,
                        y,
                        w,
                        h,
                        0,
                        0,
                        real_img_w,
                        real_img_h);             
                #endif
                
                break;
            }
            
            ret = gdi_bitblt_resized(
                    temp_layer, 
                    0,
                    0,
                    real_img_w - 1,
                    real_img_h - 1,
                    x,
                    y,
                    x + w - 1,
                    y + h - 1);
            
            break;
        }


        
        /* up-scale */
        gdi_image_9slice_upscale_init(
            temp_layer,
            real_img_ptr,
            real_img_size,
            real_img_type,
            real_img_w,
            real_img_h,
            gdi_image_9slice_do_alpha_blending(real_img_type, img_fully_opaque),
            fill_mode,
            do_dither);

        ret = gdi_image_9slice_upscale(
                margin_left,
                margin_top,
                margin_right,
                margin_bottom,
                x,
                y,
                w,
                h);

        if (ret <= GDI_FAILED)
        {
            break;
        }
    }while(0);
    
    if ((temp_layer_buf != NULL) &&
        gdi_image_9slice_do_alpha_blending(real_img_type, img_fully_opaque) &&
        (alpha_blend_src_layer != (gdi_handle)gdi_act_layer))
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }

    /* free memory */
    if (temp_layer_buf && (temp_layer_buf != gdi_image_9slice_temp_layer_buffer))
    {
        gdi_free_ext_mem((void**)&temp_layer_buf);
    }

    /* free decode layer */
    if (temp_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_free(temp_layer);
    }

    GDI_EXIT_CRITICAL_SECTION(gdi_image_9slice_draw_mem)

#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("G9S", SA_stop);
#endif  

        
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_draw_file
 * DESCRIPTION
 *  draw 9slice image
 * PARAMETERS
 *  flag            [IN]        flag
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_9slice_draw_file(
            U32 flag, 
            U32 frame_pos, 
            S32 x, 
            S32 y, 
            S32 w, 
            S32 h, 
            U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *readbuf = NULL;
    U32 readbuf_size = 0, read_len = 0;
    FS_HANDLE file_handle;
    gdi_result ret = GDI_SUCCEED;
    U32 flag_t = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_9slice_draw_file)
    do
    {
        /* open file */
        file_handle = FS_Open((U16*)file_name, FS_READ_ONLY | FS_OPEN_NO_DIR);
        if (file_handle < 0)
        {
            ret = GDI_IMAGE_ERR_OPEN_FILE_FAILED;
            break;
        }

        /* get file size */
        if ((FS_GetFileSize(file_handle, &readbuf_size) < 0))
        {
            ret =  GDI_IMAGE_ERR_INVALID_FILE;
            break;
        }
        
        /* alloc read buffer */
        readbuf = (U8*)gdi_alloc_ext_mem_framebuffer(readbuf_size);
        if (readbuf == NULL)
        {
            ret = GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
            break;
        }

        /* read whole file into the file buffer once */
        if (FS_Read(
                file_handle, 
                readbuf, 
                readbuf_size, 
                &read_len) < 0)
        {
            ret = GDI_IMAGE_ERR_INVALID_FILE;
            break;
        }

        flag &= ~GDI_IMAGE_CODEC_FLAG_IS_FILE;

        flag_t = gdi_image_codec_get_flag();
        if (flag_t & GDI_IMAGE_CODEC_FLAG_IS_FILE)
        {
            flag_t &= ~GDI_IMAGE_CODEC_FLAG_IS_FILE;
            gdi_image_codec_set_flag(flag_t);
            flag_t = 1;
        }
        else
        {
            flag_t = 0;
        }
        /* draw 9slice from memory */
        ret = gdi_image_9slice_draw_mem(
                flag, 
                frame_pos, 
                x, 
                y, 
                w, 
                h, 
                readbuf, 
                readbuf_size,
                KAL_TRUE);
 
        if (flag_t == 1)
        {
            flag_t = gdi_image_codec_get_flag();
            flag_t |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
            gdi_image_codec_set_flag(flag_t);
        }
        flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;

        if (ret <= GDI_FAILED)
        {
            break;
        }
    }while(0);

    /* close file */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
    }
    
    /* free memory */
    if (readbuf)
    {
        gdi_free_ext_mem((void**)&readbuf);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_9slice_draw_file)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_draw_handler
 * DESCRIPTION
 *  draw 9slice image to gdi_act_layer
 * PARAMETERS
 *  flag            [IN]        flag
 *  frame_pos       [IN]        which frame to draw
 *  x               [IN]        draw position x
 *  y               [IN]        draw position y
 *  w               [IN]        draw width
 *  h               [IN]        draw height
 *  data_ptr        [IN]        image pointer
 *  img_size        [IN]        image fize
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_9slice_draw_handler(
            U32 flag, 
            U32 frame_pos, 
            S32 x, 
            S32 y, 
            S32 w, 
            S32 h, 
            U8 *data_ptr, 
            U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    flag |= gdi_image_codec_get_flag();    
    
    if (flag & GDI_IMAGE_CODEC_FLAG_FORCE_9SLICE_ALPHA_BLEND)
    {
        gdi_image_9slice_cntx.force_alpha_blending = KAL_TRUE;
    }
    else
    {
        gdi_image_9slice_cntx.force_alpha_blending = KAL_FALSE;
    }
    
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        ret = gdi_image_9slice_draw_file(
                flag, 
                frame_pos, 
                x, 
                y, 
                w, 
                h, 
                data_ptr);
    }
    else
    {
        gdi_handle src_layer;
        gdi_get_alpha_blending_source_layer(&src_layer);
        
        if (debug_9slice==1)
        {
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\9slice_act_01_before.bmp");
            gdi_layer_save_bmp_file(src_layer, (CHAR *)L"E:\\9slice_src_01_before.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\9slice_act_01_before.bmp");
            gdi_layer_save_bmp_file(src_layer, (CHAR *)L"D:\\9slice_src_01_before.bmp");
            #endif
        }
        ret = gdi_image_9slice_draw_mem(
                flag, 
                frame_pos, 
                x, 
                y, 
                w, 
                h, 
                data_ptr,
                img_size,
                KAL_FALSE);
 
        if (debug_9slice==1)
        {
            #ifdef __MTK_TARGET__
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"E:\\9slice_act_02_after.bmp");
            gdi_layer_save_bmp_file(src_layer, (CHAR *)L"E:\\9slice_src_02_after.bmp");
            #else
            gdi_layer_save_bmp_file((gdi_handle)gdi_act_layer, (CHAR *)L"D:\\9slice_act_02_after.bmp");
            gdi_layer_save_bmp_file(src_layer, (CHAR *)L"D:\\9slice_src_02_after.bmp");
            #endif
        }

    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_get_dimension_mem
 * DESCRIPTION
 *  get dimension of the 9slice image
 * PARAMETERS
 *  flag           [IN]     flag
 *  data_ptr       [IN]     image pointer
 *  img_size       [IN]     image fize
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_9slice_get_dimension_mem(
            U32 flag, 
            U8 *data_ptr, 
            U32 img_size, 
            S32 *width, 
            S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *real_img_ptr = NULL;
    S32 real_img_size = 0;
    U32 real_img_type = GDI_IMAGE_TYPE_INVALID;
    gdi_result ret = GDI_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_9slice_get_dimension_mem)
    
    /* parse 9slice 20byte header */
    ret = gdi_image_9slice_parse_header(
            data_ptr,
            img_size,
            &real_img_ptr,
            &real_img_size,
            &real_img_type,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            NULL,
            KAL_FALSE);

    if (ret <= GDI_FAILED)
    {
        GDI_RETURN(ret);
    }

    /* get real image dimension */
    ret = gdi_image_get_dimension_mem(
            (U8)real_img_type,
            real_img_ptr,
            real_img_size,
            width, 
            height);
    
    GDI_EXIT_CRITICAL_SECTION(gdi_image_9slice_get_dimension_mem)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_get_dimension_file
 * DESCRIPTION
 *  get dimension of the 9slice image
 * PARAMETERS
 *  flag           [IN]     flag
 *  data_ptr       [IN]     image pointer
 *  img_size       [IN]     image fize
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_9slice_get_dimension_file(
            U32 flag, 
            U8 *file_name,
            S32 *width, 
            S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE  file_handle;
    U32        read_len;
    U8         buf[GDI_9SLICE_HEADER_SIZE];
    gdi_result ret = GDI_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_9slice_get_dimension_file)

    do
    {
        /* open file */
        file_handle = FS_Open((U16*)file_name, FS_READ_ONLY | FS_OPEN_NO_DIR);
        
        if (file_handle < 0)
        {
            ret = GDI_IMAGE_ERR_OPEN_FILE_FAILED;
            break;
        }

        /* read 4 bytes for width and height from the file */
        if (FS_Read(file_handle, buf, GDI_9SLICE_HEADER_SIZE, &read_len) != FS_NO_ERROR)
        {
            ret = GDI_IMAGE_ERR_INVALID_FILE;
            break;
        }

        /* call get dimension from memory */
        ret = gdi_image_9slice_get_dimension_mem(
                flag, 
                buf, 
                GDI_9SLICE_HEADER_SIZE, 
                width, 
                height);
    }while(0);
    
    /* close file */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_9slice_get_dimension_file)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_9slice_get_dimension_handler
 * DESCRIPTION
 *  get dimension of the 9slice image
 * PARAMETERS
 *  flag           [IN]     flag
 *  data_ptr       [IN]     image pointer
 *  img_size       [IN]     image fize
 *  width          [OUT]    image width
 *  height         [OUT]    image height
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_9slice_get_dimension_handler(
            U32 flag, 
            U8 *data_ptr, 
            U32 img_size, 
            S32 *width, 
            S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        ret = gdi_image_9slice_get_dimension_file(
                flag, 
                data_ptr,
                width, 
                height);
    }
    else
    {
        ret = gdi_image_9slice_get_dimension_mem(
                flag, 
                data_ptr, 
                img_size, 
                width, 
                height);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_9slice_file
 * DESCRIPTION
 *  is 9slice image file
 * PARAMETERS
 *  file_name           [IN]     file name
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_is_9slice_file(U8 *file_name)
{
	return GDI_FAILED;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

