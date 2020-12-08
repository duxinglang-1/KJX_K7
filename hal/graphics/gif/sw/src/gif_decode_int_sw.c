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
 *  gif_decode_int_sw.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Gif related.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/****************************************************************************
* Include
*****************************************************************************/
#ifndef GIF_WIN32
#include "lcd_sw_rnd.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "fsal.h"
#include "wchar.h"
#include "setjmp.h"
#include "string.h"

/* for switch stack */
#include "drv_gfx_stack_switch_manager.h"
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
#endif

#include "gif_decode_int_sw.h"
#include "gif_decode_int_sw_util.h"
#include "gif_parse.h"


#if defined(__MTK_TARGET__)
#pragma Otime
#endif /* defined(__MTK_TARGET__) */

/* The cacheable pragma can be be removed after MAUI set all buffer default cacheable */
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "CACHEDZI",  rwdata = "CACHEDRW"
#endif

/****************************************************************************
* Global Variable
*****************************************************************************/
/* destination layer information */
kal_uint8 *g_gif_sw_dest_buf_ptr;
kal_uint16 g_gif_sw_dest_buf_width;
//kal_uint8 g_gif_sw_dest_vcf;
//kal_uint8 g_gif_sw_dest_cf;
kal_int32 g_gif_sw_dest_clipx1;
kal_int32 g_gif_sw_dest_clipy1;
kal_int32 g_gif_sw_dest_clipx2;
kal_int32 g_gif_sw_dest_clipy2;

/* function pointer to set the update area when non-blocking decodeing(gdc_progress_blt_callback()) */
gif_sw_set_update_area_func g_gif_sw_set_update_area;
gif_sw_put_pixel_func g_gif_sw_act_put_pixel;   /* put pixel function */

/****************************************************************************
* Static Declaration
*****************************************************************************/
KAL_ADM_ID   g_gif_sw_disposal_pool_id;
kal_bool     g_gif_sw_using_disposal;

kal_int16    *g_gif_sw_stack;            /* gif decoder buffer */
kal_int32    *g_gif_sw_tree_buffer;      /* gif decoder buffer */
gif_sw_color *g_gif_sw_local_palette;
kal_uint16   g_gif_sw_transparent_index; /* the color index of transparent color */
kal_uint16   g_gif_sw_palette_size;      /* size of palette */

gif_sw_image_struct  g_gif_sw_cache[GIF_SW_CACHE_COUNT]; /* gif cache buffer */
//gif_sw_image_struct  *pcurrent_match_gif_sw_cache = NULL;
kal_int16            g_gif_sw_cache_last_index = 0;      /* last access element in cache */

kal_bool     g_gif_sw_dest_source_key_enable;
kal_uint32   g_gif_sw_dest_source_key;

//kal_int16    *g_gif_sw_resizer_buffer;               /* resizer buffer */
//kal_int32    g_gif_sw_resizer_buffer_elements_cnt;   /* number of elements in resizer buf */

gif_sw_bitblt_func            g_gif_sw_bitblt;
gif_sw_layer_set_palette_func g_gif_sw_layer_set_palette;     /* function to set gdi_layer_palette */
gif_sw_anim_set_delay_func    g_gif_sw_anim_set_delay;  /* set gdi animation delay time */

/* function used when non-blocking  */
/* it will abort non-blocking if other gdi function is called */
/* or update decode area */
gif_sw_image_progress_callback_func g_gif_sw_image_progress_callback;
//static gif_sw_get_cache_key_from_file_func g_gif_sw_get_cache_key_from_file;


gif_sw_color *g_gif_sw_current_palette;                      /* pointer point to current palette */
kal_bool     g_gif_sw_decoder_is_bypass_color = KAL_FALSE;   /* use bypass color or not */
gif_sw_color g_gif_sw_decoder_bypass_color;                  /* which color to pass */
gif_sw_color g_gif_sw_background_color;


gif_sw_color_from_rgb_func   g_gif_sw_act_color_from_rgb;    /* transform rgb to color value */
gif_sw_get_pixel_func        g_gif_sw_act_get_pixel;         /* get pixel from destination buffer */


STFSAL* pfsal_handle;






void* (*g_gif_malloc)(kal_uint32 size);
void  (*g_gif_free)(void *mem_addr);

void _gif_sw_set_mem_ctr(void* (*gif_malloc)(kal_uint32 size), void (*gif_free)(void *mem_addr))
{
   g_gif_malloc = gif_malloc;
   g_gif_free = gif_free;
}

kal_int32 _gif_sw_set_local_fsal(STFSAL* h)
{
   pfsal_handle = h;
   return 0;
}


kal_int32 _gif_sw_get_local_fsal(STFSAL** h)
{
   *h = pfsal_handle;
   return 0;
}


kal_uint16 _gif_sw_get_cur_palette_size(void)
{
   return g_gif_sw_palette_size;
}


#include "gif_decode_int_sw_codec.h"
#define GET_U8()         _gif_fsal_get_u8(pfsal_handle)
#define GET_U16()        _gif_fsal_get_u16(pfsal_handle)

#define FLUSH(count)     FSAL_Skip_Bytes(pfsal_handle, count)
#define SEEK(offset)     FSAL_Seek(pfsal_handle, offset)
#define TELL()           _gif_fsal_tell(pfsal_handle)
#define IS_EOF()         _gif_fsal_is_eof(pfsal_handle)


#define GET_FILE_U8(file_handle, val)         _gifv2_fsal_get_u8(file_handle, (val))
#define GET_FILE_U16(file_handle, val)        _gifv2_fsal_get_u16(file_handle, (val))
#define GET_FILE_U24(file_handle, val)        _gifv2_fsal_get_u24(file_handle, (val))
#define FILE_FLUSH(file_handle,count)         _gifv2_fsal_flush(file_handle, count)
#define FILE_SEEK(file_handle, offset)        _gifv2_fsal_seek(file_handle, offset)
#define FILE_TELL(file_handle, val)                _gifv2_fsal_tell(file_handle, (val))
#define FILE_IS_EOF(file_handle, val)         _gifv2_fsal_is_eof(file_handle, (val))
#define FILE_GET_SIZE(file_handle, val)        _gifv2_fsal_get_size(file_handle, (val))

/*****************************************************************************
 * FUNCTION
 *  gif_sw_init
 * DESCRIPTION
 *  initialize sw gif decoder
 * PARAMETERS
 *  gif_sw_stack                    [IN]    pointer of gif stack buffer
 *  gif_sw_tree_buffer              [IN]    pointer of decoder tables buffer
 *  gif_sw_local_palette            [IN]    pointer of local palette buffer
 *  gif_sw_bytestream_buffer        [IN]    pointer of bytestream buffer
 *  gif_sw_bytestream_buffer_size   [IN]    size of bytestream buffer
 *  resizebuf                       [IN]    pointer of resizer buffer
 *  resizebuf_size                  [IN]    number of elements in resizer buffer
 *  gif_sw_layer_set_palette        [IN]    function to set gdi_layer_palette element
 *  gif_sw_anim_set_delay           [IN]    funciton to set gdi_anim_delay_time
 *  gif_sw_set_update_area          [IN]    function to set gdi_image_update_area_x1,y1,x2,y2
 *  gif_sw_image_progress_callback  [IN]    gdi_image_progress_callback, it will abort decoding if timeout or force abort
 *  gif_sw_get_cache_key_from_file  [IN]    function to get cache key from file
 *  using_disposal                  [IN]    support "restore to background" disposal method if true
 *  gif_sw_disposal_buf_adm_id      [IN]    gif disposal buffer adm id
 *  gif_sw_bitblt                   [IN]    function to bitblt the layer content
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
kal_int32 gif_sw_init(
            kal_int16 *gif_sw_stack,
            kal_int32 *gif_sw_tree_buffer,
            gif_sw_color *gif_sw_local_palette,
            gif_sw_layer_set_palette_func gif_sw_layer_set_palette,
            gif_sw_anim_set_delay_func gif_sw_anim_set_delay,
            gif_sw_set_update_area_func gif_sw_set_update_area,
            gif_sw_image_progress_callback_func gif_sw_image_progress_callback,
            gif_sw_get_cache_key_from_file_func gif_sw_get_cache_key_from_file,
            kal_bool using_disposal,
            KAL_ADM_ID gif_sw_disposal_buf_adm_id,
            gif_sw_bitblt_func gif_sw_bitblt)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   //gif_sw_fs_initialize();

   g_gif_sw_stack = gif_sw_stack;
   g_gif_sw_tree_buffer = gif_sw_tree_buffer;

   g_gif_sw_local_palette = gif_sw_local_palette;

   //g_gif_sw_bytestream_buffer = gif_sw_bytestream_buffer;
   //g_gif_sw_bytestream_buffer_size = gif_sw_bytestream_buffer_size;

   g_gif_sw_layer_set_palette = gif_sw_layer_set_palette;
   g_gif_sw_anim_set_delay = gif_sw_anim_set_delay;
   g_gif_sw_set_update_area = gif_sw_set_update_area;
   g_gif_sw_image_progress_callback = gif_sw_image_progress_callback;
   //g_gif_sw_get_cache_key_from_file = gif_sw_get_cache_key_from_file;

   //g_gif_sw_resizer_buffer = resizebuf;
   //g_gif_sw_resizer_buffer_elements_cnt = resizebuf_elements_cnt;

   g_gif_sw_using_disposal = using_disposal;

   if (g_gif_sw_using_disposal)
   {
      g_gif_sw_disposal_pool_id = gif_sw_disposal_buf_adm_id;
      g_gif_sw_bitblt = gif_sw_bitblt;
   }
   return GIF_SW_RET_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_set_dest_buf
 * DESCRIPTION
 *  set destinatio buffer to sw gif decoder
 * PARAMETERS
 *  gif_sw_dest_buf_ptr  [IN]    destination buffer pointer
 *  gif_sw_dest_buf_width[IN]    width of the destination buffer dimension
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED
 *****************************************************************************/
kal_int32 gif_sw_set_dest_buf(
            kal_uint8 *gif_sw_dest_buf_ptr,
            kal_uint16 gif_sw_dest_buf_width)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   g_gif_sw_dest_buf_ptr = gif_sw_dest_buf_ptr;
   g_gif_sw_dest_buf_width = gif_sw_dest_buf_width;
   return GIF_SW_RET_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_set_dest_color_format
 * DESCRIPTION
 *  set color format of destination buffer to sw gif decoder
 * PARAMETERS
 *  gif_sw_dest_cf  [IN]    destination buffer color format
 *  gif_sw_dest_vcf [IN]    destination buffer virtual color format
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED
 *****************************************************************************/
kal_int32 gif_sw_set_dest_color_format(
            kal_uint8 gif_sw_dest_cf,
            kal_uint8 gif_sw_dest_vcf)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   //g_gif_sw_dest_cf = gif_sw_dest_cf;
   //g_gif_sw_dest_vcf = gif_sw_dest_vcf;

   g_gif_sw_act_color_from_rgb = gif_sw_color_from_rgb_array[gif_sw_dest_cf];
   g_gif_sw_act_get_pixel = gif_sw_get_pixel_array[gif_sw_dest_cf];
   g_gif_sw_act_put_pixel = gif_sw_put_pixel_array[gif_sw_dest_cf];

   return GIF_SW_RET_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_set_dest_source_key
 * DESCRIPTION
 *  set source key of destination buffer to sw gif decoder
 * PARAMETERS
 *  gif_sw_dest_source_key_enable  [IN]    enable destination buffer source key or not
 *  gif_sw_dest_source_key         [IN]    source key of destination buffer
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED
 *****************************************************************************/
kal_int32 gif_sw_set_dest_source_key(
            kal_bool gif_sw_dest_source_key_enable,
            kal_uint32 gif_sw_dest_source_key)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   g_gif_sw_dest_source_key_enable = gif_sw_dest_source_key_enable;
   g_gif_sw_dest_source_key = gif_sw_dest_source_key;
   return GIF_SW_RET_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_set_dest_clip
 * DESCRIPTION
 *  set clip region of destination buffer to sw gif decoder
 * PARAMETERS
 *  gif_sw_dest_clipx1  [IN]    x1 of clip region
 *  gif_sw_dest_clipy1  [IN]    y1 of clip region
 *  gif_sw_dest_clipx2  [IN]    x2 of clip region
 *  gif_sw_dest_clipy2  [IN]    y2 of clip region
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED
 *****************************************************************************/
kal_int32 gif_sw_set_dest_clip(
            kal_int16 gif_sw_dest_clipx1,
            kal_int16 gif_sw_dest_clipy1,
            kal_int16 gif_sw_dest_clipx2,
            kal_int16 gif_sw_dest_clipy2)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   g_gif_sw_dest_clipx1 = gif_sw_dest_clipx1;
   g_gif_sw_dest_clipx2 = gif_sw_dest_clipx2;
   g_gif_sw_dest_clipy1 = gif_sw_dest_clipy1;
   g_gif_sw_dest_clipy2 = gif_sw_dest_clipy2;
   return GIF_SW_RET_SUCCEED;
}


kal_int32 _gif_sw_offset_to_first_frame(STFSAL* pfsal)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32 palette_count = 0;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   FSAL_Seek(pfsal, 0);
   //6 (header) + 4(diemension) = 10Bytes
   if (FSAL_OK != FSAL_Skip_Bytes(pfsal, 10))
   {
      return GIF_SW_RET_FAILED;
   }

   /*
    * read the global color palette
    */
   if (FSAL_OK != FSAL_Read_Bytes(pfsal, (kal_uint8*)&palette_count,1))
   {
      return GIF_SW_RET_FAILED;
   }

   //skip two bytes
   if (FSAL_OK != FSAL_Skip_Bytes(pfsal, 2))
   {
      return GIF_SW_RET_FAILED;
   }

   //check if gif is with glopbal color palette
   if (palette_count & 0x80)
   {
      palette_count = 1 << ((palette_count & 0x7) + 1);

      //skip global color palette
        if (FSAL_OK != FSAL_Skip_Bytes(pfsal, palette_count * 3))
      {
         return GIF_SW_RET_FAILED;
      }
   }

   return GIF_SW_RET_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_image_dimension_internal
 * DESCRIPTION
 *  get dimension of gif image
 * PARAMETERS
 *  pfsal          [IN]        pointer to fsal handle of file
 *  width        [OUT]       return width of gif image
 *  height       [OUT]       return height of gif image
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
kal_int32 gif_sw_get_image_dimension_internal(STFSAL* pfsal, kal_uint32 *width, kal_uint32 *height)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_uint32 header;
   kal_uint32 outputtemp = 0;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   FSAL_Seek(pfsal, 0);

   //read header
   if (FSAL_OK != FSAL_Read_Bytes(pfsal, (kal_uint8*)&outputtemp,3))
   {
      return GIF_SW_RET_FAILED;
   }
   header = outputtemp;
   //reset temp parameter
   outputtemp = 0;

   //check this header is GIF or not
   if (header != 0x464947)
   {
      *width = 0;
      *height = 0;
      return GIF_SW_RET_FAILED;
   }

   //skip three non-useful bytes.
   FSAL_Skip_Bytes(pfsal, 3);

   //read the GIF dimension
   //get width
   if (FSAL_OK != FSAL_Read_Bytes(pfsal, (kal_uint8*)&outputtemp,2))
   {
      return GIF_SW_RET_FAILED;
   }
   *width = outputtemp;
   outputtemp = 0;

   //get height
   if (FSAL_OK != FSAL_Read_Bytes(pfsal, (kal_uint8*)&outputtemp,2))
   {
      return GIF_SW_RET_FAILED;
   }
   *height = outputtemp;

   return GIF_SW_RET_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_dimension_mem
 * DESCRIPTION
 *  get dimension of bmp in memory
 * PARAMETERS
 *  src     [IN]    bmp source in memory
 *  width   [OUT]   return width of bmp
 *  height  [OUT]   return height of bmp
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
kal_int32 gif_sw_get_dimension_mem(
            kal_uint8 *src,
            kal_int32 *width,
            kal_int32 *height)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32  ret;
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   GIF_SW_TRY
   {
       //ret = gif_sw_get_dimension_mem_internal(src, 14, width, height);
       ret = _gif_sw_get_dimension_internal(src, 14, width, height);
   }
   GIF_SW_CATCH_BEGIN
   {
       ret = GIF_SW_RET_FAILED;
   }
   GIF_SW_CATCH_END
   return ret;
}



/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_frame_delay_internal
 * DESCRIPTION
 *  get frame delay of each frame of an gif
 * PARAMETERS
 *  frame_count         [OUT]   number of frames in image
 *  frame_delay_array   [OUT]   delay time of each frame
 *  max_frame_count     [IN]    the size of frame_delay_array
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
kal_int32 gif_sw_get_frame_delay_internal(STFSAL* fsal_handle,
                                          kal_int32 *frame_count,
                                          kal_uint32 *frame_delay_array,
                                          kal_uint32 max_delay_count,
                                          kal_uint32 check_animation_flag)
{
   kal_bool file_end = KAL_FALSE;
   kal_uint8 gif_done, temp;
   kal_uint32 palette_count;
   kal_uint16 img_w,img_h;
   kal_uint32 file_sz, cur_pos, org_pos;
   

   *frame_count = 0;
   if (check_animation_flag)
   {
      /// if check_animation_flag is set, we should not output frame delay value.
      max_delay_count = 0;
   }

   /// Read GIF signature
   /// Read GIF signature if need
   {
     kal_uint32 header = 0;
     if ((GIF_FSAL_OK != FILE_GET_SIZE(fsal_handle, &file_sz))||
         (GIF_FSAL_OK != FILE_TELL(fsal_handle, &org_pos))||
         (GIF_FSAL_OK != FILE_SEEK(fsal_handle, 0)) ||
         (GIF_FSAL_OK != GET_FILE_U24(fsal_handle, &header))||
         (header != 0x464947))  /* 'GIF' */
     {
       return GIF_SW_RET_FAILED;
     }
   }

   /// skip dimension value
   if ((GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 3)) ||
       (GIF_FSAL_OK != GET_FILE_U16(fsal_handle, &img_w)) || 
       (GIF_FSAL_OK != GET_FILE_U16(fsal_handle, &img_h)))
   {
     return GIF_SW_RET_FAILED;
   }

   if ((img_w < 0) || (img_h < 0) || (img_w >= 10240) || (img_h >= 10240))
   {
      //SW_GIF_TRACE(MOD_MMI, "[gif] - gif_sw_get_frame_delay_internal() Wrong Img Size.\n");
      return GIF_SW_RET_FAILED;
   }

   /// Read the global color palette
   if ((GIF_FSAL_OK != GET_FILE_U8(fsal_handle, ((kal_uint8*)&palette_count)))||
        (GIF_FSAL_OK != FILE_FLUSH(fsal_handle,2)))
   {
     return GIF_SW_RET_FAILED;
   }

   if (palette_count & 0x80)
   {
      palette_count = 1 << ((palette_count & 0x7) + 1);
      if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, palette_count * 3))
      {
         return GIF_SW_RET_FAILED;
      }
   }

   /// start decoding
   gif_done = 0;
   temp = 0;

   do
   {
      if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, (&temp)))
      {
        return GIF_SW_RET_FAILED;
      }

      switch (temp)
      {
      case '!':   /* Process the GIF extension block */
         if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, (&temp)))
         {
            return GIF_SW_RET_FAILED;
         }
         if (temp == 0xf9)
         {
            kal_uint8 byte_1, byte_2 ;
            kal_uint32 a;

            if ((GIF_FSAL_OK != FILE_FLUSH(fsal_handle,2))||
                (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, (&byte_1))) || 
                (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, (&byte_2))))
            {
               return GIF_SW_RET_FAILED;
            }
            a = (((kal_uint32) (byte_2 << 8)) | (kal_uint32) (byte_1)) * 10; // delay time
            if (*frame_count < max_delay_count)
            {
               frame_delay_array[*frame_count] = a;
            }
            if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 2))
            {
               return GIF_SW_RET_FAILED;
            }
         }
         else
         {
            kal_uint8 offset;
            while (1)
            {
               if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, (&offset)))
               {
                 return GIF_SW_RET_FAILED;
               }
               if (offset == 0)
               {
                  break;
               }
               if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, offset))
               {
                 return GIF_SW_RET_FAILED;
               }
            }
         }
         break;

      case ',':
         {
            kal_uint8 a, len;
            if ((GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 4 * 2)) || // x,y,w,h;
                 (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, (&a))))
            {
              return GIF_SW_RET_FAILED;
            }
            if ((a & 0x80) != 0)  // retreive the LCT
            {
               kal_uint32 bpp;

               bpp = (a & 0x07) + 1;
               bpp = (1 << bpp) * 3; // palette bytes
               if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, bpp))
               {
                 return GIF_SW_RET_FAILED;
               }
            }
            if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 1)) // min code;
            {
              return GIF_SW_RET_FAILED;
            }

            while (1) // skip data blocks
            {
               if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, (&len)))
               {
                  return GIF_SW_RET_FAILED;
               }

               if(len == 0)
               {
                  break;
               }
               if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, len))
               {
                 return GIF_SW_RET_FAILED;
               }
            }

            (*frame_count)++;

            if (check_animation_flag && (*frame_count > 1))
            {
               return GIF_SW_RET_SUCCEED;
            }
         }
         break;

      case ';':
         gif_done = 1;
         break;

      default:
         break;
      }

      //if (GIF_FSAL_OK != FILE_IS_EOF(fsal_handle, (&file_end)))
      //{
      //  return GIF_SW_RET_SUCCEED;
      //}
      if (GIF_FSAL_OK != FILE_TELL(fsal_handle, &cur_pos))
      {
         return GIF_SW_RET_FAILED;
      }
   }
   while (!gif_done && (file_sz > cur_pos));

   if ((*frame_count) == 0)
   {
      return GIF_SW_RET_FAILED;
   }

   return GIF_SW_RET_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  gif_sw_parse_file
 * DESCRIPTION
 *  Parse the whole GIF File, and output information to a file. This function is VC project only
 * PARAMETERS
 *  fsal_handle           [IN]  Gif file
 *  out_fsal_handle     [IN]  parser output file
 *  frame_count         [OUT]   number of frames in image
 * RETURNS
 *****************************************************************************/
kal_uint32 gif_sw_parse_file(
  STFSAL* gif_fsal_handle,
  STFSAL* out_fsal_handle,
  kal_int32 *frame_count)
{
#if defined(SWGIF_VC_PROJ)
   kal_uint8 gif_done, tag, file_end;
   kal_uint8 palette_count, bg_color_index;
   kal_uint16 img_w,img_h;
   kal_uint8 temp[1024];
   kal_uint8 marker;

   *frame_count = 0;

   /// Read GIF signature
   {
     kal_uint32 header = 0;
     if ((GIF_FSAL_OK != GET_FILE_U24(gif_fsal_handle, &header)) ||
         (header != 0x464947)) /* 'GIF' */
     {
         sprintf(temp, "%s", "[Parse Gif] -- Header: Invalid signature\n");
         FSAL_Write(out_fsal_handle, temp, strlen(temp));
         return GIF_SW_RET_FAILED;
     }
   }
   sprintf(temp, "%s", "[Parse Gif] -- Header: signature & Version: 6 bytes\n");
   FSAL_Write(out_fsal_handle, temp, strlen(temp));

   /// skip dimension value
   sprintf(temp, "%s", "[Parse Gif] -- Logical Screen Descriptor: 6 bytes\n");
   FSAL_Write(out_fsal_handle, temp, strlen(temp));
   if ((GIF_FSAL_OK != FILE_FLUSH(gif_fsal_handle, 3)) ||
       (GIF_FSAL_OK != GET_FILE_U16(gif_fsal_handle, &img_w)) || 
       (GIF_FSAL_OK != GET_FILE_U16(gif_fsal_handle, &img_h)))
   {
     return GIF_SW_RET_FAILED;
   }
   if (img_w < 0 || img_h < 0 || img_w >= 10240 || img_h >= 10240)
   {
      //SW_GIF_TRACE(MOD_MMI, "[gif] - gif_sw_get_frame_delay_internal() Wrong Img Size.\n");
      return GIF_SW_RET_FAILED;
   }

   /// Read the global color palette
   GET_FILE_U8(gif_fsal_handle, &palette_count);
   GET_FILE_U8(gif_fsal_handle, &bg_color_index); 
   sprintf(temp, "%s %d %s", "[Parse Gif] -- BG Color Index = :", bg_color_index, "\n");
   FSAL_Write(out_fsal_handle, temp, strlen(temp));

   FILE_FLUSH(gif_fsal_handle, 1);
   if (palette_count & 0x80)
   {
      kal_uint32 index, c;
      palette_count = 1 << ((palette_count & 0x7) + 1);
      sprintf(temp, "%s %d %s", "[Parse Gif] -- GCT:", palette_count, "entries\n");
      FSAL_Write(out_fsal_handle, temp, strlen(temp));
      //FILE_FLUSH(gif_fsal_handle,palette_count * 3);
      for (index = 0; index < palette_count; index++)
      {
          kal_uint8 R, G, B;
          GET_FILE_U8(gif_fsal_handle, &R);
          GET_FILE_U8(gif_fsal_handle, &G);
          GET_FILE_U8(gif_fsal_handle, &B);
          c = 0;
          c = (R<<16) | (G<<8) | B;
          sprintf(temp,"%s%3d%s%x\n","[Parse Gif] -- GlobalColorTable[", index, "]= 0x", c);
          FSAL_Write(out_fsal_handle, temp, strlen(temp));
      }
   }
   sprintf(temp,"%s","\n\n");
   FSAL_Write(out_fsal_handle, temp, strlen(temp));

   /// start decoding
   gif_done = 0;

   do
   {
      GET_FILE_U8(gif_fsal_handle, &tag);
      switch (tag)
      {
         case '!':  //0x21  // Optional: Process the GIF extension block
         {
            GET_FILE_U8(gif_fsal_handle, &marker);
            if (marker == 0xf9) // Optional: Graphic control label
            {
               kal_uint8 byte_1, byte_2 ;
               kal_uint8 disposal = 0;
               kal_uint32 a;
               kal_uint32 transparent_index = 0;
               kal_uint32 disposal_pos;

               sprintf(temp,"%s", "[Parse Gif] -- Craphic Extention Block: 8 bytes\n");
               FSAL_Write(out_fsal_handle, temp, strlen(temp));
               FILE_FLUSH(gif_fsal_handle,1); //Block Size //Disposal Method....
               GET_FILE_U8(gif_fsal_handle, &disposal);
               FILE_TELL(gif_fsal_handle, &disposal_pos);
               disposal = (kal_uint32)((disposal >> 2) & 0x03);
               GET_FILE_U8(gif_fsal_handle, &byte_1);
               GET_FILE_U8(gif_fsal_handle, &byte_2);
               GET_FILE_U8(gif_fsal_handle, &transparent_index);
               FILE_FLUSH(gif_fsal_handle, 1); //Block Terminator
               sprintf(temp,"%s%d%s%d%s%d\n", "[Parse Gif] -- Disposal = ", disposal,", disposal_pos= ",disposal_pos, ", TransparentColorIndex = ", transparent_index);
               FSAL_Write(out_fsal_handle, temp, strlen(temp));
            }
            else
            {
               //Comment extention(0xFE), Plain Text extention(0x1),  Application extention(0xFF)
               kal_uint8 offset, size;
               size = 0;
               while (1)
               {
                  GET_FILE_U8(gif_fsal_handle, &offset);
                  size += offset;
                  if (offset == 0) //Block Terminator
                  {
                     sprintf(temp,"%s %d %s","[Parse Gif] -- Field: 0x21, but unkown block, size=",size, "\n");
                     FSAL_Write(out_fsal_handle, temp, strlen(temp));
                     break;
                  }
                  FILE_FLUSH(gif_fsal_handle, offset);
               }
            }
            break;
         }

         case ',': //0x2C//Image Descriptor
         {
            kal_uint8 a,len;
            kal_uint32 cur_pos, size;

            FILE_TELL(gif_fsal_handle, &cur_pos);
            sprintf(temp,"%s%d\n", "[Parse Gif] -- Image Descriptor: 9 bytes. CurPos= ", cur_pos);
            FSAL_Write(out_fsal_handle, temp, strlen(temp));

            FILE_FLUSH(gif_fsal_handle,4 * 2); // x,y,w,h;
            GET_FILE_U8(gif_fsal_handle, &a);
            if ((a & 0x80) != 0)  // retreive the LCT
            {
               kal_uint32 palette_count, index, c;
               palette_count = (a & 0x07) + 1;
               palette_count = (1 << palette_count) ; // palette entry count
               sprintf(temp,"%s %3d %s", "[Parse Gif] -- LCT:", palette_count, "\n");
               FSAL_Write(out_fsal_handle, temp, strlen(temp));
               //FILE_FLUSH(gif_fsal_handle,bpp);
               for (index = 0; index < palette_count; index++)
               {
                  kal_uint8 R, G, B;
                  GET_FILE_U8(gif_fsal_handle, &R);
                  GET_FILE_U8(gif_fsal_handle, &G);
                  GET_FILE_U8(gif_fsal_handle, &B);
                  c = 0;
                  c = (R<<16) | (G<<8) | B;
                  sprintf(temp,"%s%d%s%x\n","[Parse Gif] -- LocalColorTable[", index, "]= 0x", c);
                  FSAL_Write(out_fsal_handle, temp, strlen(temp));
               }
            }
            FILE_FLUSH(gif_fsal_handle, 1); // min code;

            size = 0;
            while (1) // skip data blocks
            {
               GET_FILE_U8(gif_fsal_handle, &len);
               size += len;
               if(len == 0) //Block Terminator
               {
                  FILE_TELL(gif_fsal_handle, &cur_pos);
                  sprintf(temp,"%s %d %s %d %s%d\n\n", "[Parse Gif] -- ", *frame_count, "th Frame Block: ", size, "bytes. CurPos = ", cur_pos);
                  FSAL_Write(out_fsal_handle, temp, strlen(temp));
                  break;
               }
               {
                  sprintf(temp,"%s %d\n", "[Parse Gif] -- DataBlockSize =", len);
                  FSAL_Write(out_fsal_handle, temp, strlen(temp));
               }
               FILE_FLUSH(gif_fsal_handle,len);
            }
            (*frame_count)++;
            break;
         }

         case ';': //0x3B //Tailer
         {
            sprintf(temp,"%s","[Parse Gif] -- Tailer\n");
            FSAL_Write(out_fsal_handle, temp, strlen(temp));
            gif_done = 1;
            break;
         }
         case '\n': //0x3B //Tailer
         {
            sprintf(temp,"%s","[Parse Gif] -- End of file\n");
            FSAL_Write(out_fsal_handle, temp, strlen(temp));
            break;
         }

         default:
         {
            sprintf(temp,"%s %x\n", "[Parse Gif] -- unKnown pattern:", (tag&0xFF));
            FSAL_Write(out_fsal_handle, temp, strlen(temp));
            break;
         }
      } //switch
      FILE_IS_EOF(gif_fsal_handle, &file_end);
   } while (!gif_done && !file_end);
#endif //SWGIF_VC_PROJ
   return GIF_SW_RET_SUCCEED;
}



/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_n_frames_disposal_method:
 * DESCRIPTION
 *   travase from the file begining to get frame delay of each frame of an gif
 * PARAMETERS
 *  frame_count         [OUT]   number of frames in image
 *  frame_delay_array   [OUT]   delay time of each frame
 *  max_frame_count     [IN]    the size of frame_delay_array
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
kal_int32 gif_sw_get_n_frames_disposal_method( 
    STFSAL* fsal_handle,
    kal_int32 desired_n_frames, //input
    kal_int32 *rael_frame_count, //output
    GIF_DISPOSAL_METHOD_ENUM *frame_disposal_method,
    kal_uint32 array_size)
{
   kal_bool file_end = KAL_FALSE;
   kal_int8 gif_done;
   kal_uint32 palette_count;
   kal_uint16 img_w,img_h;
   kal_int32 frame_num = 0;
   kal_uint8 tag;   
   kal_uint32 ext_block_exist = 0;
   kal_int32 status = GIF_SW_RET_SUCCEED;
   kal_uint32 cur_pos, org_pos;
   kal_uint32 file_sz;


   /// Read GIF signature if need
   {
     kal_uint32 header = 0;
     if ((GIF_FSAL_OK != FILE_GET_SIZE(fsal_handle, &file_sz))||
         (GIF_FSAL_OK != FILE_TELL(fsal_handle, &org_pos))||
         (GIF_FSAL_OK != FILE_SEEK(fsal_handle, 0)) ||
         (GIF_FSAL_OK != GET_FILE_U24(fsal_handle, &header))||
         (header != 0x464947))  /* 'GIF' */
     {
       goto _error_handling;
     }
   }

   {     
      /// skip dimension value
      if ((GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 3)) ||
          (GIF_FSAL_OK != GET_FILE_U16(fsal_handle, &img_w)) || 
          (GIF_FSAL_OK != GET_FILE_U16(fsal_handle, &img_h)))
      {
        goto _error_handling;;
      }
      if ((img_w < 0) || (img_h < 0) || (img_w >= 10240) || (img_h >= 10240))
      {
         goto _error_handling;;
      }
      
      /// Read the global color palette
      if ((GIF_FSAL_OK != GET_FILE_U8(fsal_handle, ((kal_uint8*)&palette_count)))||
          (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 2)))
      {
         goto _error_handling;;
      }
      if (palette_count & 0x80)
      {
         palette_count = 1 << ((palette_count & 0x7) + 1);
         if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, palette_count * 3))
         {
            goto _error_handling;;
         }
      }
   }

   /// start decoding
   gif_done = 0;

   do
   {
      if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &tag))
      {
         goto _error_handling;
      }
      switch (tag)
      {
         case '!':  //0x21  // Optional: Process the GIF extension block
         {
            kal_uint8 maker;  
            if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &maker))
            {
               goto _error_handling;;
            }
            if (maker == 0xf9) // Optional: Graphic control label
            {
               kal_uint8 byte_1;

               ext_block_exist = 1;
               if ((GIF_FSAL_OK != FILE_FLUSH(fsal_handle,1))|| //Flush Block Size
                   (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &byte_1)))
               {
                  goto _error_handling;
               }
               
               frame_disposal_method[frame_num] = (GIF_DISPOSAL_METHOD_ENUM) (byte_1 & 0x1C)>>2;
               if (frame_disposal_method[frame_num] > GIF_DISPOSAL_RSVD)
               {
                  frame_disposal_method[frame_num] = GIF_DISPOSAL_NO_ACTION;                 
               }

               if (frame_num == desired_n_frames)
               {
                  goto _return;
               }
               if (frame_num == array_size) //array size is too small.
               {
                  status = GIF_SW_RET_PARA_ERROR;
                  goto _return;;
               }
               if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 4)) //array size is too small.
               {
                  goto _error_handling;
               }
            }
            else
            {
               kal_uint8 offset;
               while (1)
               {
                  if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &offset))
                  {
                     goto _error_handling;
                  }
                  if (offset == 0)
                  {
                     break;
                  }
                  if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, offset))
                  {
                     goto _error_handling;
                  }
               }
            }
            break;
         }

         case ',': //0x2C//Image Descriptor
         {
            kal_uint8 a,len;

            if ((GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 4*2))||// x,y,w,h;
                (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &a)))
            {
               goto _error_handling;;
            }

            if ((a & 0x80) != 0)       // retreive the LCT
            {
               kal_uint32 bpp;

               bpp = (a & 0x07) + 1;
               bpp = (1 << bpp) * 3;   // palette bytes
               if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, bpp))
               {
                 goto _error_handling;
               }
            }
            if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 1)) // min code;
            {
               goto _error_handling;
            }

            while (1)                  // skip data blocks
            {
               if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &len))
               {
                 goto _error_handling;
               }
               if(len == 0)            //Block Terminator
               {
                  if (0 == ext_block_exist)
                  {
                     // For this next frame, graphics extention block is not exited. Set to default value.
                     frame_disposal_method[frame_num] = GIF_DISPOSAL_NOT_DISPOSAL;
                  }
                  break;
               }
               if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, len)) // min code;
               {
                 goto _error_handling;
               }
            }

            frame_num++;
            ext_block_exist = 0;
            if (frame_num == desired_n_frames)
            {
               goto _return;
            }
            if ((frame_num == array_size)) //array size is too small.
            {
               status = GIF_SW_RET_PARA_ERROR;
               goto _return;;
            }
            break;
         }

         case '\0':
            break;

         case ';':  //Tailer
            gif_done = 1;
            break;

         default:
            break;
      }//switch
      //if (GIF_FSAL_OK != FILE_IS_EOF(fsal_handle, &file_end))
      //{
      //  goto _error_handling;
      //}      
      if (GIF_FSAL_OK != FILE_TELL(fsal_handle, &cur_pos))
      {
         goto _error_handling;
      }
   } while (!gif_done && (file_sz > cur_pos));

   if (frame_num == 0)
   {
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_get_n_frames_disposal_method() Invalid File frame_num = 0.\n");
      return GIF_SW_RET_FAILED;
   }

_error_handling:
   *frame_disposal_method = GIF_DISPOSAL_RSVD;
   status = GIF_SW_RET_FAILED;
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_get_n_frames_disposal_method() Invalid File.\n");

_return:
   *rael_frame_count = frame_num;
   FILE_SEEK(fsal_handle, org_pos);
   return status;
}



kal_int32 gif_sw_get_frame_n_disposal_method( 
    STFSAL* fsal_handle,
    kal_uint32 cache_id,
    kal_int32 frame_index,
    GIF_DISPOSAL_METHOD_ENUM *frame_disposal_method)
{
   kal_int8 gif_done;
   kal_int32 palette_count;
   kal_uint16 img_w,img_h;
   kal_int32 frame_num = 0;
   kal_uint8 tag;

   kal_int16 lcd_idx;
   kal_int8 gif_is_hit_cache = 0;

   gif_sw_image_struct *cache = NULL;
   kal_int32 real_frame_count = 0;
   kal_int32 offset;

   
   // try to hit the cache and initialize the cache item
   /* If the frame_counter < frame_number, gif will decode from frame_counter to frame_number. */
   if (gif_sw_gif_hit_cache(cache_id, 0, 0, KAL_FALSE, frame_index, &lcd_idx, &real_frame_count, &offset, KAL_FALSE))
   {
      //gif_is_hit_cache = 1;      
      cache = &g_gif_sw_cache[lcd_idx];
      if ((cache->final_frame_index+1) >= frame_index)
      {
         if (MAX_GIF_FRAME_SUM < frame_index)
         {
            *frame_disposal_method = (GIF_DISPOSAL_METHOD_ENUM) cache->frame_disposal_method[MAX_GIF_FRAME_SUM];
         }
         else         
         {
            *frame_disposal_method = (GIF_DISPOSAL_METHOD_ENUM) cache->frame_disposal_method[frame_index];         
         }
         //printf("gif_sw_get_frame_n_disposal_method(): Get from cache struct.\n");
         SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_get_frame_n_disposal_method() Check0. disposal_method = %d. \n", (*frame_disposal_method));
         if (*frame_disposal_method > GIF_DISPOSAL_RSVD)
         {
            *frame_disposal_method = GIF_DISPOSAL_NO_ACTION;
            //ASSERT(0);
         }

         return GIF_SW_RET_SUCCEED;
      }
      else
      {      
         //TODO: travase from the last_read_position      
         //SEEK(cache->cache[cache->final_frame_index]);
         //Parse
         //SW_GIF_TRACE(MOD_MMI, "[gif] - gif_sw_get_frame_n_disposal_method() Check1. frame_index = %d, cache->final_frame_index=%d \n", frame_index, cache->final_frame_index);        
      }
   }


   {
      GIF_DISPOSAL_METHOD_ENUM disposal_method_array[64];

      //printf("gif_sw_get_frame_n_disposal_method(): Travase the file\n");
      if (GIF_SW_RET_SUCCEED != gif_sw_get_n_frames_disposal_method(fsal_handle, frame_index, &real_frame_count, disposal_method_array, 64)) 
      {      
         SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_get_frame_n_disposal_method() FAIL. fsal_handle=%d, frame_index = %d, real_frame_count=%d \n", fsal_handle, frame_index , real_frame_count);
         return GIF_SW_RET_FAILED;
      }
      //SW_GIF_TRACE(MOD_MMI, "[gif] - gif_sw_get_frame_n_disposal_method() FAIL. fsal_handle=%d, frame_index = %d, cache->final_frame_index=%d, real_frame_count=%d \n", fsal_handle, frame_index ,cache->final_frame_index, real_frame_count);
  
      *frame_disposal_method = disposal_method_array[frame_index];
      //if (*frame_disposal_method > GIF_DISPOSAL_RSVD)
      //{
      //   ASSERT(0);
      //}

      return GIF_SW_RET_SUCCEED;
   }
}


kal_int32 gif_sw_get_all_frame_disposal_method( 
    STFSAL* fsal_handle,
    kal_int32 *rael_frame_count,
    GIF_DISPOSAL_METHOD_ENUM *frame_disposal_method,
    kal_uint32 max_delay_count)
{
    return gif_sw_get_n_frames_disposal_method(fsal_handle, 0xFFFF, rael_frame_count, frame_disposal_method, max_delay_count);
}



kal_int32 gif_sw_get_next_frame_disposal_method( 
    STFSAL* fsal_handle,
    GIF_DISPOSAL_METHOD_ENUM *frame_disposal_method)
{
   kal_uint8 gif_done, file_end;
   kal_uint32 palette_count;
   kal_uint8 tag;
   kal_uint32 cur_pos, org_pos;
   kal_uint32 file_sz;

   //kal_uint32 start, end;
   //start = drv_get_current_time();
   
   if ((GIF_FSAL_OK != FILE_GET_SIZE(fsal_handle, &file_sz)) || 
       (GIF_FSAL_OK != FILE_TELL(fsal_handle, &org_pos)))
   {
      return GIF_SW_RET_FAILED;
   }
   
   /// start decoding
   gif_done = 0;
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gif_sw_get_next_frame_disposal_method() Enter.\n");
   *frame_disposal_method = GIF_DISPOSAL_NO_ACTION;
   do
   {
      if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &tag))
      {
         return GIF_SW_RET_FAILED;
      }
      switch (tag)
      {
         case '!':   //0x21  // Optional: Process the GIF extension block
         {
            kal_uint8 maker;
            if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &maker))
            {
               return GIF_SW_RET_FAILED;
            }
            if (maker == 0xf9)
            {
               kal_uint8 byte_1;

               if ((GIF_FSAL_OK != FILE_FLUSH(fsal_handle,1))|| //Flush Block Size
                   (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &byte_1)))
               {
                 return GIF_SW_RET_FAILED;
               }
               *frame_disposal_method = (GIF_DISPOSAL_METHOD_ENUM)((byte_1 & 0x1C)>>2);
               if (*frame_disposal_method > GIF_DISPOSAL_RSVD)
               {
                  //printf("CurrentPos=%d\n", _gif_fsal_tell(fsal_handle));
                  //ASSERT(0);
                  *frame_disposal_method = GIF_DISPOSAL_NO_ACTION;
               }
               if (GIF_FSAL_OK != FILE_SEEK(fsal_handle, org_pos))
               {
                  return GIF_SW_RET_FAILED;
               }
               return GIF_SW_RET_SUCCEED;
               //FILE_FLUSH(fsal_handle,4);
            }
            else
            {
               kal_uint8 offset;
               while (1)
               {
                  if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &offset))
                  {
                     return GIF_SW_RET_FAILED;
                  }
                  if (offset == 0)
                  {
                     break;
                  }
                  if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle,offset))
                  {
                    return GIF_SW_RET_FAILED;
                  }
               }
            }
            break;
         }

         case ',':
         {
            kal_uint8 a, len;

            if ((GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 4 * 2)) ||  // x,y,w,h;
                (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &a)))
            {
               return GIF_SW_RET_FAILED;
            }
            if ((a & 0x80) != 0)  // retreive the LCT
            {
               kal_uint32 bpp;
               bpp = (a & 0x07) + 1;
               bpp = (1 << bpp) * 3; // palette bytes
               if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle,bpp))
               {
                 return GIF_SW_RET_FAILED;
               }
            }
            if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle, 1)) // min code;
            {
              return GIF_SW_RET_FAILED;
            }

            while (1) // skip data blocks
            {
               if (GIF_FSAL_OK != GET_FILE_U8(fsal_handle, &len))
               {
                 return GIF_SW_RET_FAILED;
               }

               if(len == 0)
               {
                  // For this next frame, graphics extention block is not exited. Set to default value.
                  *frame_disposal_method = GIF_DISPOSAL_NOT_DISPOSAL;
                  if (GIF_FSAL_OK != FILE_SEEK(fsal_handle, org_pos))
                  {
                     return GIF_SW_RET_FAILED;
                  }
                  return GIF_SW_RET_SUCCEED;
               }
               if (GIF_FSAL_OK != FILE_FLUSH(fsal_handle,len))
               {
                 return GIF_SW_RET_FAILED;
               }
            }
            //break;
         }
         
         case '\0':
            break;

         case ';': //Tailer
            gif_done = 1;
            break;

         default:
            break;
      }//switch

      if (GIF_FSAL_OK != FILE_TELL(fsal_handle, &cur_pos))
      {
         return GIF_SW_RET_FAILED;
      }
   } while (!gif_done && (file_sz > cur_pos));

   *frame_disposal_method = GIF_DISPOSAL_RSVD;
   if (GIF_FSAL_OK != FILE_SEEK(fsal_handle, org_pos))
   {
     return GIF_SW_RET_FAILED;
   }
   //end = drv_get_current_time();   
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gif_sw_get_next_frame_disposal_method() End. %d ticks \n", drv_get_duration_tick(start, end));
   return GIF_SW_RET_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_draw_resized_stub
 * DESCRIPTION
 *  draw resized gif image in memory
 * PARAMETERS
 *  ox              [IN]    position to draw
 *  oy              [IN]    position to draw
 *  resized_width   [IN]    width to draw
 *  resized_height  [IN]    height to draw
 *  src             [IN]    pointer to source image
 *  size            [IN]    source image size
 *  frame_number    [IN]    which frame in gif file to draw
 *  transparent_enable  [IN]    if true, the transparent color won't be drawn
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
static kal_int32 gif_sw_draw_resized_stub(
            kal_int32 ox,
            kal_int32 oy,
            kal_int32 resized_width,
            kal_int32 resized_height,
            kal_uint8 *src,
            kal_uint32 size,
            kal_uint16 frame_number,
            kal_bool transparent_enable,
            GIF_COLOR_FORMAT_ENUM output_format,
            GIF_COLOR_FORMAT_ENUM palette_format)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32  ret;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   GIF_SWLA_DEBUG("GIF", 1);
   GIF_SW_TRY
   {
      ret = _gif_sw_draw_internal(
               ox,
               oy,
               KAL_TRUE,
               resized_width,
               resized_height,    /* resize */
               src,
               size,              /* source */
               (kal_uint32) src,  /* cache id use source address */
               frame_number,
               KAL_TRUE,          /* use disposal method */
               transparent_enable,/* transparent enable */
               output_format,
               palette_format);
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_draw_resized_stub(): ret:%x.\n", ret);
   }
   GIF_SW_CATCH_BEGIN
   {
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_draw_resized_stub(): GIF_SW_RET_FAILED.\n");
      ret = GIF_SW_GET_CATCH_STATUS;//GIF_SW_RET_FAILED;
   }
   GIF_SW_CATCH_END
   GIF_SWLA_DEBUG("GIF", 0);
   return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_draw_stub
 * DESCRIPTION
 *  draw gif image in memory
 * PARAMETERS
 *  ox                  [IN]    position to draw
 *  oy                  [IN]    position to draw
 *  src                 [IN]    pointer to source image
 *  size                [IN]    source image size
 *  frame_number        [IN]    which frame in gif file to draw
 *  transparent_enable  [IN]    if true, the transparent color won't be drawn
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
static kal_int32 gif_sw_draw_stub(
            kal_int32 ox,
            kal_int32 oy,
            kal_uint8 *src,
            kal_uint32 size,
            kal_uint16 frame_number,
            kal_bool transparent_enable,
            GIF_COLOR_FORMAT_ENUM output_format,
            GIF_COLOR_FORMAT_ENUM palette_format)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32  ret;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   GIF_SWLA_DEBUG("GIF", 1);
   GIF_SW_TRY
   {
      ret = _gif_sw_draw_internal(
               ox,
               oy,
               KAL_FALSE,         /*is_resized */
               0,
               0,                 /* not resize */
               src,
               size,              /* source */
               (kal_uint32) src,  /* cache id use source address */
               frame_number,
               KAL_TRUE,          /* don't use disposal method */
               transparent_enable,/* transparent enable */
               output_format,
               palette_format);
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_draw_stub(): ret:%x.\n", ret);
   }
   GIF_SW_CATCH_BEGIN
   {
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gif_sw_draw_stub(): GIF_SW_RET_FAILED.\n");
      ret = GIF_SW_GET_CATCH_STATUS;//GIF_SW_RET_FAILED;
   }
   GIF_SW_CATCH_END
   GIF_SWLA_DEBUG("GIF", 0);
   return ret;
}



/*****************************************************************************
 * FUNCTION
 *  gif_sw_draw_resized
 * DESCRIPTION
 *  switch stack and draw resized gif image in memory
 * PARAMETERS
 *  ox              [IN]    position to draw
 *  oy              [IN]    position to draw
 *  resized_width   [IN]    width to draw
 *  resized_height  [IN]    height to draw
 *  src             [IN]    pointer to source image
 *  size            [IN]    source image size
 *  frame_number    [IN]    which frame in gif file to draw
 *  transparent_enable  [IN]    if true, the transparent color won't be drawn
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
GIF_STATUS_ENUM gif_sw_draw_resized(
            kal_int32 ox,
            kal_int32 oy,
            kal_int32 resized_width,
            kal_int32 resized_height,
            kal_uint8 *src,
            kal_uint32 size,
            kal_uint16 frame_number,
            kal_bool transparent_enable,
            GIF_COLOR_FORMAT_ENUM output_format,
            GIF_COLOR_FORMAT_ENUM palette_format)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32 ret;
   GIF_STATUS_ENUM gif_status = GIF_STATUS_OK;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

#if defined(__MTK_TARGET__)
   void *stk_ptr;  /* for switch stack */

   /* sw gif use bytestream to read file, so we don't need to check is source if file of drm file */
   stk_ptr = drv_gfx_stkmgr_get_stack(GIF_STACK_SIZE);

   if (stk_ptr)
   {
      ret = INT_SwitchStackToRun(
              stk_ptr,
              GIF_STACK_SIZE,
              (kal_func_ptr)gif_sw_draw_resized_stub,
              9,
              ox,
              oy,
              resized_width,
              resized_height,
              src,
              size,
              frame_number,
              transparent_enable,
              output_format,
              palette_format);
      drv_gfx_stkmgr_release_stack(stk_ptr);
   }
   else
#endif
   {
      ret = gif_sw_draw_resized_stub(
              ox,
              oy,
              resized_width,
              resized_height,
              src,
              size,
              frame_number,
              transparent_enable,
              output_format,
              palette_format);
   }

   {
      if (ret != 0)
      {
        if (ret < 0)
        {
           gif_status =  ret;  
        }		
        else
        {
           gif_status = GIF_STATUS_INVALID_SOURCE_FILE;
        }		
      }
   }

   return gif_status;
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_draw
 * DESCRIPTION
 *  switch stack and draw gif image in memory
 * PARAMETERS
 *  ox                  [IN]    position to draw
 *  oy                  [IN]    position to draw
 *  src                 [IN]    pointer to source image
 *  size                [IN]    source image size
 *  frame_number        [IN]    which frame in gif file to draw
 *  transparent_enable  [IN]    if true, the transparent color won't be drawn
 * RETURNS
 *  kal_int32, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
GIF_STATUS_ENUM gif_sw_draw(
            kal_int32 ox,
            kal_int32 oy,
            kal_uint8 *src,
            kal_uint32 size,
            kal_uint16 frame_number,
            kal_bool transparent_enable,
            GIF_COLOR_FORMAT_ENUM output_format,
            GIF_COLOR_FORMAT_ENUM palette_format)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_int32 ret;
   GIF_STATUS_ENUM  gif_status = GIF_STATUS_OK;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)

   void *stk_ptr;  /* for switch stack */

   /* sw gif use bytestream to read file, so we don't need to check is source if file of drm file */
   stk_ptr = drv_gfx_stkmgr_get_stack(GIF_STACK_SIZE);

   if (stk_ptr != NULL)
   {
      ret = INT_SwitchStackToRun(
              stk_ptr,
              GIF_STACK_SIZE,
              (kal_func_ptr)gif_sw_draw_stub,
              8,
              ox,
              oy,
              src,
              size,
              frame_number,
              transparent_enable,
              output_format,
              palette_format);
      drv_gfx_stkmgr_release_stack(stk_ptr);
   }
   else
#endif
   {
      ret = gif_sw_draw_stub(
              ox,
              oy,
              src,
              size,
              frame_number,
              transparent_enable,
              output_format,
              palette_format);
   }
   {
      if (ret != 0)
      {
        if (ret < 0)
        {
           gif_status =  ret;  
        }		
        else
        {
           gif_status = GIF_STATUS_INVALID_SOURCE_FILE;
        }		
      }
   }

   return gif_status;
}


gif_sw_image_struct* 
_gif_sw_get_cache_by_id(kal_uint32 cache_idx)
{
   return &g_gif_sw_cache[cache_idx];
}

/*****************************************************************************
 * FUNCTION
 *  gif_sw_cache_clear_disposal_bg_buf
 * DESCRIPTION
 *  free the disposal background buffer of one cache
 * PARAMETERS
 *  cache_idx   [IN]    cache index
 * RETURNS
 *  void
 *****************************************************************************/
static void gif_sw_cache_clear_disposal_bg_buf(kal_uint32 cache_idx)
{
   if (g_gif_sw_using_disposal && g_gif_sw_cache[cache_idx].disposal_bg_buf)
   {

      if(g_gif_sw_cache[cache_idx].disposal_bg_buf)
      {
         g_gif_free(g_gif_sw_cache[cache_idx].disposal_bg_buf);
      }
      g_gif_sw_cache[cache_idx].disposal_bg_buf = NULL;
      g_gif_sw_cache[cache_idx].disposal_bg_buf_size = 0;
   }
}


/*
 * Start of internal RAM
 */
#if defined(__MTK_TARGET__)
#pragma arm section code = "INTERNCODE"
#endif


/*****************************************************************************
 * FUNCTION
 *  gif_sw_gif_hit_cache
 * DESCRIPTION
 *  see if the frame is already in gif cache
 * PARAMETERS
 *  cache_id            [IN]    which cache_id to hit
 *  x                   [IN]    image position
 *  y                   [IN]    image position
 *  frame_number        [IN]    which frame in gif file to draw
 *  cache_index         [OUT]   return the hit cache id if hit
 *  frame_counter       [OUT]   the max frame index that is less than frame_number and able to draw succeefully in the gif animation
 *  offset              [OUT]   the byte offset of this frame in the gif image
 *  update              [IN]    if true, clear all attributes in the cache if not hit
 * RETURNS
 *  kal_bool, return GIF_SW_RET_SUCCEED if succeed
 *****************************************************************************/
kal_bool gif_sw_gif_hit_cache(
            kal_uint32 cache_id,
            kal_int32 x,
            kal_int32 y,
            kal_bool compare_xy,
            kal_uint16 frame_number,
            kal_int16 *cache_index,
            kal_int32 *frame_counter,
            kal_int32 *offset,
            kal_bool update)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_bool ishit = KAL_FALSE;
   *cache_index = g_gif_sw_cache_last_index;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   /* search the cache index */
   {
       kal_int32 i;
       for (i = 0; i < GIF_SW_CACHE_COUNT; i++)
       {
          if (g_gif_sw_cache[i].cache[0] == cache_id)
          {
             if (compare_xy)
             {
                if(g_gif_sw_cache[i].x == (kal_int16)x && g_gif_sw_cache[i].y == (kal_int16)y)
                {
                   ishit = KAL_TRUE;
                   break;
                }
             }
             else
             {
                ishit = KAL_TRUE;
                break;
             }             
          }
       }

       /* can't find it from cache */
       if (!ishit)
       {
          (*cache_index)++;
          (*cache_index) %= GIF_SW_CACHE_COUNT;

          // save the offset to cache_last_index[]
          if(update)
          {
             g_gif_sw_cache_last_index= *cache_index;
          }
       }
       else
       {
          (*cache_index) = i;
       }
   }

   // /////////////////////////////////////////////////////////
   // try to hit the cache data
   if (ishit)
   {
      kal_int32 i = (frame_number >= MAX_GIF_FRAME_SUM) ? MAX_GIF_FRAME_SUM - 1 : frame_number;

      if ((frame_number >= MAX_GIF_FRAME_SUM) && (frame_number >= g_gif_sw_cache[*cache_index].latest_frame) &&(g_gif_sw_cache[*cache_index].latest_frame))
      {
         i = MAX_GIF_FRAME_SUM;
      }

      *frame_counter = 0;
      for (; i > 0; i--)
      {
         if (g_gif_sw_cache[*cache_index].cache[i])
         {
            if (i < MAX_GIF_FRAME_SUM && (frame_number < g_gif_sw_cache[*cache_index].latest_frame || !g_gif_sw_cache[*cache_index].latest_frame))
            {
               *frame_counter = i;
            }
            else
            {
               *frame_counter = g_gif_sw_cache[*cache_index].latest_frame;
            }
            break;
         }
      }
      if (i > 0)
      {
         *offset = g_gif_sw_cache[*cache_index].cache[i];
      }
      else
      {
         *offset = 0;
      }

      return KAL_TRUE;
   }
   else if (update)
   {
      //Clear all attributes in the cache if not hit

      gif_sw_cache_clear_disposal_bg_buf((kal_uint32)*cache_index);
      memset(&g_gif_sw_cache[*cache_index] , 0, sizeof(g_gif_sw_cache[*cache_index]));
      g_gif_sw_cache[*cache_index].cache[0] = cache_id;
      g_gif_sw_cache[*cache_index].x = (kal_int16)x;
      g_gif_sw_cache[*cache_index].y = (kal_int16)y;


      *frame_counter = 0;
      *offset = 0;

      return KAL_FALSE;
   }
   return KAL_FALSE;

}

#if defined(__MTK_TARGET__)
#pragma arm section code
#endif


/*****************************************************************************
 * FUNCTION
 *  gif_sw_cache_reset
 * DESCRIPTION
 *  reset the gif cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_cache_reset(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_uint32 i;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   for (i = 0; i < GIF_SW_CACHE_COUNT; i++)
   {
      g_gif_sw_cache[i].cache[0] = 0;
      g_gif_sw_cache[i].animation_file_check_done = KAL_FALSE;
      g_gif_sw_cache[i].is_animation_file = KAL_FALSE;
      gif_sw_cache_clear_disposal_bg_buf(i);
   }
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_cache_reset_entry
 * DESCRIPTION
 *  reset one entry in gif cache
 * PARAMETERS
 *  cache_id       [IN]     cache id of the cache to reset
 * RETURNS
 *  void
 *****************************************************************************/
void gif_sw_cache_reset_entry(kal_uint32 cache_id)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_uint32 i;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   for (i = 0; i < GIF_SW_CACHE_COUNT; i++)
   {
      if(g_gif_sw_cache[i].cache[0] == cache_id)
      {
         g_gif_sw_cache[i].cache[0] = 0;
         g_gif_sw_cache[i].animation_file_check_done = KAL_FALSE;
         g_gif_sw_cache[i].is_animation_file = KAL_FALSE;
         gif_sw_cache_clear_disposal_bg_buf(i);
         break;
      }
   }
}


/*****************************************************************************
 * FUNCTION
 *  gif_sw_get_transparent_index
 * DESCRIPTION
 *  get the index of transparent color in palette
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint16, return transparent color index
 *****************************************************************************/
kal_uint16 gif_sw_get_transparent_index(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   return g_gif_sw_transparent_index;
}


void _gif_sw_set_background_color(gif_sw_color bg_color)
{
   g_gif_sw_background_color = bg_color;
}

kal_bool _gif_sw_is_cache_hit(kal_uint32 cache_id, kal_uint32 x, kal_uint32 y)
{
   kal_int32 i;
   for (i = 0; i < GIF_SW_CACHE_COUNT; i++)
   {
      if (g_gif_sw_cache[i].cache[0] == cache_id)
      {
         if(g_gif_sw_cache[i].x == (kal_int16)x && g_gif_sw_cache[i].y == (kal_int16)y)
         {
             return KAL_TRUE;
         }
      }
   }
  return KAL_FALSE;
}

