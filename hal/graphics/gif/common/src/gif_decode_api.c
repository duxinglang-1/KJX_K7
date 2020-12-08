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
 *   gif_decode_api.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Prototypes of decode API for GIF decoder unified interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 21 2013 sophie.chen
 * removed!
 * .
 *
 * 01 10 2013 sophie.chen
 * removed!
 * .
 *
 * 06 08 2012 sophie.chen
 * removed!
 * .
 *
 * 05 18 2012 sophie.chen
 * removed!
 * .
 *
 * 03 08 2012 sophie.chen
 * removed!
 * .
 *
 * 03 08 2012 sophie.chen
 * removed!
 * .
 *
 * 12 21 2011 sophie.chen
 * removed!
 * .
 *
 * 12 06 2011 sophie.chen
 * removed!
 * .
 *
 * 12 02 2011 sophie.chen
 * removed!
 * .
 *
 * 11 29 2011 sophie.chen
 * removed!
 * .
 *
 * 11 22 2011 sophie.chen
 * removed!
 * .
 *
 * 11 22 2011 sophie.chen
 * removed!
 * .
 *
 * 11 11 2011 sophie.chen
 * removed!
 * .
 *
 * 11 10 2011 sophie.chen
 * removed!
 * .
 *
 * 10 21 2011 sophie.chen
 * removed!
 * .
 *
 * 10 18 2011 sophie.chen
 * removed!
 * .
 *
 * 09 26 2011 sophie.chen
 * removed!
 * .
 *
 * 09 23 2011 sophie.chen
 * removed!
 * .
 *
 * 09 23 2011 sophie.chen
 * removed!
 * .
 *
 * 08 31 2011 sophie.chen
 * removed!
 * .
 *
 * 07 26 2011 sophie.chen
 * removed!
 * .
 *
 * 05 27 2011 sophie.chen
 * removed!
 * .
 *
 * 05 27 2011 sophie.chen
 * removed!
 * .
 *
 * 05 24 2011 sophie.chen
 * removed!
 * .
 *
 * 04 28 2011 sophie.chen
 * removed!
 * .
 *
 * 04 15 2011 sophie.chen
 * removed!
 * .
 *
 * 04 07 2011 rey.su
 * removed!
 * .
 *
 * 03 28 2011 rey.su
 * removed!
 * Add margin for memory fragmentation caused by HW alignment requirement.
 *
 * 03 17 2011 rey.su
 * removed!
 * Fix 6276 working memory allocation bug.
 *
 * 03 15 2011 rey.su
 * removed!
 * .
 *
 * 03 15 2011 rey.su
 * removed!
 * .
 *
 * 03 14 2011 rey.su
 * removed!
 * Fox HW decoder, if the output format is 8-bits index, adjust the palette table to avoid source key color.
 *
 * 02 25 2011 rey.su
 * removed!
 * .
 *
 * 02 21 2011 linson.du
 * removed!
 * .
 *
 * 02 21 2011 linson.du
 * removed!
 * .
 *
 * 02 21 2011 linson.du
 * removed!
 * .
 *
 * 01 07 2011 linson.du
 * removed!
 * .
 *
 * 12 24 2010 linson.du
 * removed!
 * .
 *
 * 12 23 2010 linson.du
 * removed!
 * .
 *
 * 12 23 2010 linson.du
 * removed!
 * .
 *
 * 12 18 2010 linson.du
 * removed!
 * Modify resize limitation.
 *
 * 12 14 2010 linson.du
 * removed!
 * .
 *
 * 11 24 2010 linson.du
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#if defined (__MTK_TARGET__)
#include "kal_public_api.h"
#include "stack_config.h"
#include "kal_trace.h"
#endif

#ifdef SWGIF_VC_PROJ
#include "swgif_wrapper.h"
#endif

#ifndef SWGIF_VC_PROJ
#include "fs_func.h"
#endif

#include "string.h"
#include "fsal.h"
#include "gif_decode_api.h"
#include "gif_decode_int_sw.h"
#include "gif_decode_int_sw_util.h"
#include "simple_memory_manager.h"
#include "gfx_cache_switch_behavior_enum.h"


#if defined (__GIF_DEC_6268_SERIES__)
#include "gif_drv_dec_6268_series.h"
#include "mm_intmem.h"
#endif

#if defined (__GIF_DEC_6276_SERIES__)
#include "gif_drv_dec_6276_series.h"
#include "mm_intmem.h"
#endif




#define GIF_FLAG_SOURCE_KEY_ENABLE        (1 << 0)         // enable source key
#define GIF_FLAG_DISPOSAL_ENABLE          (1 << 1)         // enable disposal method
#define GIF_FLAG_SET_WORKING_BUF          (1 << 2)         // set working buffer
#define GIF_FLAG_SET_SOURCE_FILE          (1 << 3)         // set source file
#define GIF_FLAG_SET_OUTPUT_WIND          (1 << 4)         // set output window
#define GIF_FLAG_SET_CALLBACK             (1 << 5)         // set callback function
#define GIF_FLAG_SET_CHECH_ABORT          (1 << 6)         // set check abort callback function
#define GIF_FLAG_SET_CANVAS               (1 << 7)         // set canvas information
#define GIF_FLAG_SET_CLIP_WIND            (1 << 8)         // set clip window
#define GIF_FLAG_DECODE_COMPLETE          (1 << 9)         // it means gif file has been decoded.
#define GIF_FLAG_RESIZE                   (1 << 10)        // it means gif file has to resize to fit output window.
#define GIF_FLAG_PARSE_FRAME_COUNT        (1 << 11)        // it means gif file has parse frame count
#define GIF_FLAG_PARSE_FRAME_DELAY        (1 << 12)        // it means gif file has parse delay array
#define GIF_FLAG_PARSE_DELAY_OVER_SIZE    (1 << 13)        // it means gif file has parse delay array, but default contain is not enough to save.
#define GIF_FLAG_PARSE_DIMENSION          (1 << 14)        // it means gif file has parse dimension
#define GIF_FLAG_SW_CONFIG_READY          (1 << 15)        // it means sw gif decoder is ready to decode
#define GIF_FLAG_SET_CACHE_ID             (1 << 16)        // set cache id
#define GIF_FLAG_SET_FILE_BUF             (1 << 17)        // set source file buffer for read or parse file








#define BIT_SET(data,value)   (data |= value)
#define BIT_CLR(data,value)   (data &= ~value)

#ifndef LOW_COST_SUPPORT
#define GIF_MAX_RESIZE_WIDTH           (1280)
#else
#define GIF_MAX_RESIZE_WIDTH           (640)
#endif
#define GIF_SW_DECODE_BUFFER_SIZE      (256)
#define GIF_HAL_STACK_SIZE             (0x1000 + 8)
#define GIF_HAL_TREE_SIZE              (0x4000 + 8)
#define GIF_PALETTE_MAX_SIZE           (256)
#define GIF_SW_CACHE_WORK_BUFFER_SIZE  (64) /// to calculate cache id "+7" is for alignment



/*for debug*/
//#define GIF_WORKING_MEMORY_DEBUG
//#define GIF_PARAMETER_CHECK


#ifdef GIF_WORKING_MEMORY_DEBUG
#define GIF_DEBUG_INFO_LENGHTH   2
#define GIF_DEBUG_WORKING_ITEM   4
#else
#define GIF_DEBUG_INFO_LENGHTH   0
#define GIF_DEBUG_WORKING_ITEM   0
#endif


#define GIF_DEC_FSAL_CACHE_SIZE     2048
#define GIF_DEC_READ_BUFFER_BIG     16384
#define GIF_DEC_READ_BUFFER_SAMLL   1024


#if 1
#define GIF_DEBUG_PRINTF(x)   printf(x)
#else
/* under construction !*/
#endif

kal_uint32 g_gif_delay_time = 0;

#if defined(__MTK_TARGET__)
#else
/*
   gif disosal method option, it needs a lot of memory.
   if system don't have enough memory, please turn this feature off.
*/
//#define GIF_DISPOAL_METHOD
#endif

#if defined(GIF_DISPOAL_METHOD)
#ifdef GIF_WIN32
#define GIF_ADM_HEADER_SIZE(POOL_SUM,MAX_BLOCKS) (0)
#else
#define GIF_ADM_HEADER_SIZE(POOL_SUM,MAX_BLOCKS) (sizeof(ADM_CB) + POOL_SUM * sizeof(ADM_BL) + MAX_BLOCKS * sizeof(ADM_MB_HEAD))
#endif
#define GIF_LCD_WIDTH 320           //lcd width
#define GIF_LCD_HEIGHT 480          //lcd height
#define GIF_LCD_BIT_PER_PIXEL 16    //config lcd bits per pixel
#define GIF_LCD_BUF_SIZE ((GIF_LCD_WIDTH * GIF_LCD_HEIGHT * GIF_LCD_BIT_PER_PIXEL)>>3)

// set two lcd size as default buffer size
static kal_uint32   gif_disposal_pool[(GIF_ADM_HEADER_SIZE(2,16) + (GIF_LCD_BUF_SIZE << 1) >>2) + 1];
KAL_ADM_ID   gif_disposal_pool_id;
static kal_bool gif_is_disposal_init = KAL_FALSE;


//disposal memory control "malloc" function
void* gif_adm_malloc(kal_uint32 size)
{
#ifdef GIF_WIN32
   return (void*)malloc(size);
#else
   // TODO: should use mutex to protect multi-thread using.
   kal_adm_alloc(gif_disposal_pool_id, size);
#endif
}


//disposal memory control "free" function
void gif_adm_free(void *mem_addr)
{
#ifdef GIF_WIN32
   free(mem_addr);
#else
   // TODO: should use mutex to protect multi-thread using.
   kal_adm_free(gif_disposal_pool_id, mem_addr);
#endif
}
#endif

static kal_bool gif_hw_is_in_use = KAL_FALSE;
static kal_bool gif_sw_is_in_use = KAL_FALSE;

extern kal_int32 _gif_sw_get_local_fsal(STFSAL** h);
extern void _gif_sw_set_local_fsal(STFSAL* h);
extern kal_int32 gif_sw_get_frame_delay_internal(STFSAL* fsal_handle, kal_int32 *frame_count, kal_uint32 *frame_delay_array, kal_uint32 max_delay_count, kal_uint32 check_animation_flag);
extern void _gif_sw_set_mem_ctr(void* (*gif_malloc)(kal_uint32 size), void (*gif_free)(void *mem_addr));
extern void _gif_sw_set_background_color(gif_sw_color bg_color);
extern kal_uint16 _gif_sw_get_cur_palette_size(void);
extern kal_bool _gif_sw_is_cache_hit(kal_uint32 cache_id, kal_uint32 x, kal_uint32 y);

#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
extern kal_int32 _gif_hw_set_local_fsal(STFSAL* h);
extern kal_int32 _gif_hw_get_local_fsal(STFSAL** h);
extern void gif_reset_cache(void);
extern void gif_reset_cache_entry(kal_uint32 id);

extern gif_dcb_struct gif_dcb;
extern gif_state_enum gif_state;
#endif

// get byte per pixel
kal_uint32 _gif_get_bpp_by_color_format(GIF_COLOR_FORMAT_ENUM format)
{
   switch (format)
   {
   case GIF_COLOR_FORMAT_8:
      return 1;

   case GIF_COLOR_FORMAT_16:
      return 2;

   case GIF_COLOR_FORMAT_24:
   case GIF_COLOR_FORMAT_ARGB6666:
      return 3;

   case GIF_COLOR_FORMAT_ARGB8888:
      return 4;

   case GIF_COLOR_FORMAT_CUSTOM_1:
   case GIF_COLOR_FORMAT_CUSTOM_2:
      // TODO: make sure how to handle user specific color format
      return 0;

   default:
      ASSERT(0);
   }
   return 0;
}



kal_int32 _gif_dec_check_handle(GIF_DECODER_HANDLE handle)
{
   if (!handle)
   {
      return -1;
   }

   return 0;
}



void _gif_set_delay_time(kal_uint32 delay)
{
   g_gif_delay_time = delay;
}



kal_uint32 _gif_get_delay_time(void)
{
   return g_gif_delay_time;
}



void _gif_sw_bitblt(kal_uint8 *src_ptr,
                    kal_int32 src_pitch,
                    kal_int32 src_offset_x,
                    kal_int32 src_offset_y,
                    kal_int32 src_width,
                    kal_int32 src_height,
                    kal_uint8 *dest_ptr,
                    kal_int32 dest_pitch,
                    kal_int32 dest_offset_x,
                    kal_int32 dest_offset_y,
                    gif_sw_rect_struct dest_clip,
                    kal_int32 bits_per_pixel)
{
    kal_int16 pixel_bytes;

    if (bits_per_pixel == 16)
    {
        pixel_bytes = 2;
    }
    else if (bits_per_pixel == 8)
    {
        pixel_bytes = 1;
    }
    else if (bits_per_pixel == 24)
    {
        pixel_bytes = 3;
    }
    else if (bits_per_pixel == 32)
    {
        pixel_bytes = 4;
    }
    else
    {
      pixel_bytes = 0;
        ASSERT(0);
    }

    _gif_sw_BITBLT(dest_ptr,
                   dest_pitch,
                   dest_offset_x,
                   dest_offset_y,
                   (dest_offset_x + src_width -1),
                   (dest_offset_y + src_height -1),
                   src_ptr,
                   src_pitch,
                   src_offset_x,
                   src_offset_y,
                   (src_offset_x + src_width -1),
                   (src_offset_y + src_height -1),
                   dest_clip.x1,
                   dest_clip.y1,
                   dest_clip.x2,
                   dest_clip.y2,
                   pixel_bytes);
}



GIF_STATUS_ENUM _gif_set_disposal(GIF_DECODER_HANDLE handle,
                                  kal_bool disposalEnable,
                                  void* (*userMalloc)(kal_uint32 size),
                                  void (*userFree)(void *mem_addr),
                                  kal_uint32 bgColor)
{

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif
   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_set_disposal() Enter.\n");

   handle->last_status = GIF_STATUS_OK;

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      handle->hw_config.bg_color = bgColor;
      handle->hw_config.disposal_en = disposalEnable;
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      if (disposalEnable)
      {
         if ((NULL == userMalloc) || (NULL == userFree))
         {
            handle->last_status = GIF_STATUS_INVALID_PARAMETER;
         }
         else
         {
            handle->en_disposal = KAL_TRUE;
            _gif_sw_set_mem_ctr(userMalloc, userFree);
            BIT_SET(handle->flag, GIF_FLAG_DISPOSAL_ENABLE);
            _gif_sw_set_background_color(bgColor);
         }
      }
      else
      {
          handle->en_disposal = KAL_FALSE;
          _gif_sw_set_background_color(bgColor);
      }
      break;

   default:
      ASSERT(0);
      break;
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_set_disposal() Leave.\n");
   return handle->last_status;
}



gif_color _gif_get_color(kal_int32 x, kal_int32 y, kal_uint8* canvas,
                         kal_uint32 canvas_width, kal_uint32 bytes_per_pixel,
                         GIF_COLOR_FORMAT_ENUM cf)
{
   gif_color color;
   kal_uint8* ptr = (canvas + ((x + canvas_width * y) * bytes_per_pixel) );

   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_get_color() Enter. \n");

   switch (cf)
   {
   case GIF_COLOR_FORMAT_8:
      color = (gif_color)*ptr;
      break;

   case GIF_COLOR_FORMAT_16:
      color = (gif_color)*((kal_uint16*)ptr);
      break;

   case GIF_COLOR_FORMAT_24:
   case GIF_COLOR_FORMAT_ARGB6666:
      //color = (gif_color)(((*ptr)<<16)|((*(ptr+1))<<8)|((*(ptr+2))));
      color = (gif_color)(((*(ptr+2))<<16)|((*(ptr+1))<<8)|((*(ptr))));
      break;

   case GIF_COLOR_FORMAT_ARGB8888:
      color = (gif_color)*((kal_uint32*)ptr);
      break;

   case GIF_COLOR_FORMAT_CUSTOM_1:
      {
         #if 0
/* under construction !*/
         #else
         color = 0;
         ASSERT(0);
         #endif
      }
      break;

   default:
      color = 0;
      break;
   }
   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_get_color() Leave. color = %d\n", color);
   return color;
}



kal_uint32 _gif_get_semi_crc(kal_uint8 *src, kal_uint32 size)
{
   register kal_uint32 crc, temp, i;

   crc = 0;
   for (i = 0; i < size; i++)
   {
      if (crc >> 15)
      {
         temp = 1;
      }
      else
      {
         temp = 0;
      }
      crc = (((crc << 1) & 0x0ffff) + temp) ^ (kal_uint32) * src;
      src++;
   }
   return crc;
}



kal_uint32 _gif_get_cache_id(STFSAL *pfsal, kal_uint32 *pbuffer)
{
   kal_uint32 id = 0;

   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_get_cache_id() Enter. \n");
   if (KAL_FALSE == FSAL_IsRamFile(pfsal))
   {
#ifdef GIF_WIN32
      //id = _gif_fast_semi_crc((kal_uint8 *)pfsal->hFile->_tmpfname, sizeof(pfsal->hFile->_tmpfname));
      id |= pfsal->uFileSize;
#else
      //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_get_cache_id() File in disc. \n");

      if (FS_GetFirstCluster(pfsal->hFile, &id))
      {
         kal_uint32 cur_position = 0;
         kal_uint32 old_position = 0;
         kal_int32 crc_length = 0;
         kal_uint32 file_size = 0;

         //take first frame front 64bytes to calculate crc result as cache id.

         //record original position
         FSAL_GetCurPos(pfsal, &old_position);
         FSAL_GetFileSize(pfsal, &file_size);

         //offset to first frame
         if (_gif_sw_offset_to_first_frame(pfsal))
         {
            return 0;
         }

         FSAL_GetCurPos(pfsal, &cur_position);

         crc_length = pfsal->uFileSize - cur_position;
         if (crc_length > 64)
         {
            crc_length = 64;
         }

         if (crc_length < 0)
         {
            return 0;
         }

         if (FSAL_OK != FSAL_Read_Bytes(pfsal, (kal_uint8 *)pbuffer, crc_length))
         {
            return 0;
         }

         id = _gif_get_semi_crc((kal_uint8 *)pbuffer, crc_length);
         id ^= file_size;
        }
#endif
   }
   else
   {
      //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_get_cache_id() File in ram. \n");

      id = (kal_uint32)FSAL_GetRamFilePointer(pfsal);
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_get_cache_id() Leave. cache id = %d\n", id);
   return id;
}



GIF_STATUS_ENUM _gif_set_cache_id (GIF_DECODER_HANDLE handle)
{
   kal_uint32 id = 0;

   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_set_cache_id() Enter. \n");

   id = _gif_get_cache_id(handle->fsal_handle, handle->cache_work_buffer);
   if (0 == id)
   {
      return GIF_STATUS_DEC_ERROR_INVALID_FILE;
   }

   if (handle->codec_type == GIF_DEC_TYPE_HW)
   {
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      handle->hw_config.cache_id = id;
#else
      ASSERT(0);
#endif
   }
   else
   {
      handle->cache_id = id;
   }
   BIT_SET(handle->flag, GIF_FLAG_SET_CACHE_ID);

   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_set_cache_id() Leave. \n");
   return GIF_STATUS_OK;
}



// TODO: remove this coding style in the future
gif_sw_color* g_gif_index_palette = NULL;
void _gif_sw_layer_set_palette(kal_uint8 index, gif_sw_color color)
{
   g_gif_index_palette[index] = color;
}



GIF_STATUS_ENUM gifDecIsResizeSupport(GIF_DEC_TYPE_ENUM codecType)
{
   GIF_STATUS_ENUM rtn;

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecIsResizeSupport() Enter. \n");

   switch (codecType)
   {
   case GIF_DEC_TYPE_HW:
#if defined (__GIF_DEC_6276_SERIES__)
      rtn = GIF_STATUS_OK;
#elif defined (__GIF_DEC_6268_SERIES__)
      //because there is bug in hw v3 resizer,
      rtn = GIF_STATUS_NOT_SUPPORT_RESIZING;
#else
      rtn = GIF_STATUS_NOT_SUPPORT_RESIZING;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      rtn = GIF_STATUS_OK;
      break;

   default:
      rtn = GIF_STATUS_INVALID_PARAMETER;
      break;
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecIsResizeSupport() Leave. \n");
   return rtn;
}



GIF_STATUS_ENUM gifDecGetHandle(GIF_DEC_TYPE_ENUM codecType, GIF_DECODER_HANDLE* handlePtr)
{
   GIF_DECODER_HANDLE h = NULL;
   GIF_STATUS_ENUM rtn = GIF_STATUS_OK; //return

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecGetHandle() Enter. codecType = %d\n", codecType);

   switch (codecType)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)

      #if defined(DRV_FEATURE__MM_INTMEM_IMPL_MT6276)
         /// SW workaround for MAUI_02907527: Force to use HW decoder in MM scenario.
         if (KAL_TRUE != mm_intmem_query_non_multimedia())
         {
            return GIF_STATUS_DEC_UNAVAILABLE;
         }
      #endif

      if (!gif_hw_is_in_use)
      {
         gif_hw_is_in_use = KAL_TRUE;
      }
      else
      {
         return GIF_STATUS_DEC_UNAVAILABLE;
      }
      gif_init();

      h = (GIF_DECODER_HANDLE)get_ctrl_buffer(sizeof(GIF_DECODER));
      if (h)
      {
         memset(h, 0, sizeof(GIF_DECODER));
         rtn = GIF_STATUS_OK;
         h->last_status = GIF_STATUS_OK;
         h->codec_type = GIF_DEC_TYPE_HW;
         *handlePtr = h;
      }
      else
      {
         *handlePtr = NULL;
         rtn = GIF_STATUS_DEC_UNAVAILABLE;
      }
      break;
#else
      return GIF_STATUS_DEC_UNAVAILABLE;
#endif

   case GIF_DEC_TYPE_SW:
      if (!gif_sw_is_in_use)
      {
         gif_sw_is_in_use = KAL_TRUE;
      }
      else
      {
         return GIF_STATUS_DEC_UNAVAILABLE;
      }
      h = (GIF_DECODER_HANDLE)get_ctrl_buffer(sizeof(GIF_DECODER));
      if (h)
      {
         memset(h, 0, sizeof(GIF_DECODER));
         rtn = GIF_STATUS_OK;
         h->last_status = GIF_STATUS_OK;
         h->codec_type = GIF_DEC_TYPE_SW;
         h->palette_format = GIF_COLOR_FORMAT_16; //set default value
         *handlePtr = h;
      }
      else
      {
         *handlePtr = NULL;
         rtn = GIF_STATUS_DEC_UNAVAILABLE;
      }
#if defined(GIF_DISPOAL_METHOD)
   #ifndef GIF_WIN32
      /* initialize the disposal buffer pool */
      if (KAL_FALSE == gif_is_disposal_init)
      {
         kal_uint32 chunk[2];

         chunk[0] = 0xffffffff;
         chunk[1] = 0;

         SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecGetHandle() Disposal Method memory create. \n");

         gif_disposal_pool_id = kal_adm_create(gif_disposal_pool, sizeof(gif_disposal_pool), chunk, KAL_FALSE);
         gif_is_disposal_init = KAL_TRUE;
      }
   #endif
#endif
      break;

   default:
      ASSERT(0);
      break;
   }
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecGetHandle() Leave. \n");
   return rtn;
}



GIF_STATUS_ENUM gifDecReleaseHandle(GIF_DECODER_HANDLE* handlePtr)
{
   GIF_STATUS_ENUM rtn = GIF_STATUS_OK;

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecReleaseHandle() Enter.\n");

   if (0 != _gif_dec_check_handle(*handlePtr))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }

   switch ((*handlePtr)->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      if (gif_hw_is_in_use)
      {
         gif_hw_is_in_use = KAL_FALSE;
         free_ctrl_buffer((void*)*handlePtr);
         *handlePtr = NULL;
         rtn = GIF_STATUS_OK;
      }
      else
      {
         return GIF_STATUS_INVALID_HANDLE;
      }
      break;
#else
      return GIF_STATUS_DEC_UNAVAILABLE;
#endif

   case GIF_DEC_TYPE_SW:
      if (gif_sw_is_in_use)
      {
         gif_sw_is_in_use = KAL_FALSE;
         free_ctrl_buffer((void*)*handlePtr);
         *handlePtr = NULL;
         rtn = GIF_STATUS_OK;
      }
      else
      {
         return GIF_STATUS_INVALID_HANDLE;
      }
      break;

   default:
      ASSERT(0);
      break;
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecReleaseHandle() Leave.\n");
   return rtn;
}



GIF_STATUS_ENUM gifDecQueryFileBuffer (GIF_DECODER_HANDLE handle,
                                            kal_uint32 *readBufferSizeBest,
                                            kal_uint32 *readBufferSizeMinimum,
                                            kal_uint32 *fsalCacheSizeBest,
                                            kal_uint32 *fsalCacheSizeMinimum)
{
#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecQueryFileBuffer() Enter.\n");

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      if (handle->image_file_size < GIF_DEC_READ_BUFFER_SAMLL)
      {
         *readBufferSizeBest = handle->image_file_size;
         *readBufferSizeMinimum = handle->image_file_size;
      }
      else if (handle->image_file_size < GIF_DEC_READ_BUFFER_BIG)
      {
         *readBufferSizeBest = handle->image_file_size;
         *readBufferSizeMinimum = GIF_DEC_READ_BUFFER_SAMLL;
      }
      else// big file
      {
         *readBufferSizeBest = GIF_DEC_READ_BUFFER_BIG;
         *readBufferSizeMinimum = GIF_DEC_READ_BUFFER_SAMLL;
      }

      if (KAL_TRUE == FSAL_IsRamFile(handle->fsal_handle))
      {
         *fsalCacheSizeMinimum = 0;
         *fsalCacheSizeBest = 0;
      }
      else
      {
         *fsalCacheSizeMinimum = 0;
         *fsalCacheSizeBest = GIF_DEC_FSAL_CACHE_SIZE;
      }
      break;
#else
      return GIF_STATUS_INVALID_OPERATION;
#endif

   case GIF_DEC_TYPE_SW:
      *readBufferSizeBest = 0;
      *readBufferSizeMinimum = 0;
      if (KAL_TRUE == FSAL_IsRamFile(handle->fsal_handle))
      {
         *fsalCacheSizeMinimum = 0;
         *fsalCacheSizeBest = 0;
      }
      else
      {
         *fsalCacheSizeMinimum = 0;
         *fsalCacheSizeBest = GIF_DEC_FSAL_CACHE_SIZE;
      }
      break;

   default:
      ASSERT(0);
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecQueryFileBuffer() Leave. readBufferSizeBest: %d,readBufferSizeMinimum: %d, fsalCacheSizeBest: %d,fsalCacheSizeMinimum: %d \n",
   *readBufferSizeBest, *readBufferSizeMinimum, *fsalCacheSizeBest, *fsalCacheSizeMinimum);

   return handle->last_status;
}



GIF_STATUS_ENUM gifDecSetSourceFile(GIF_DECODER_HANDLE handle, STFSAL *fp)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetSourceFile() Enter.\n");

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      handle->fsal_handle = fp;
      if (FSAL_OK != FSAL_GetFileSize(handle->fsal_handle, &handle->image_file_size))
      {
         handle->last_status = GIF_STATUS_INVALID_PARAMETER;
      }
      else
      {
         BIT_CLR(handle->flag, 0xffffffff);
         _gif_hw_set_local_fsal(handle->fsal_handle);
         BIT_SET(handle->flag, GIF_FLAG_SET_SOURCE_FILE);
      }
#else
      handle->last_status = GIF_STATUS_DEC_UNAVAILABLE;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      handle->fsal_handle = fp;
      BIT_CLR(handle->flag, 0xffffffff);
      _gif_sw_set_local_fsal(handle->fsal_handle);
      BIT_SET(handle->flag, GIF_FLAG_SET_SOURCE_FILE);
      break;

   default:
      ASSERT(0);
      break;
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetSourceFile() Leave.\n");
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecSetFileBuffer(GIF_DECODER_HANDLE handle,
                                    void *readBufferAddr,
                                    kal_uint32 readBufferSize,
                                    void *fsalCacheAddr,
                                    kal_uint32 fsalCacheSize)
{
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetSourceFile() Enter. readBufferAddr: %x,readBufferSize: %d, fsalCacheAddr: %x,fsalCacheSize: %d,\n",

   readBufferAddr, readBufferSize, fsalCacheAddr, fsalCacheSize);
#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      if ((0 == readBufferSize) || (NULL == readBufferAddr))
      {
         handle->last_status = GIF_STATUS_INVALID_PARAMETER;
         return handle->last_status;
      }
      handle->hw_config.file_buffer_adrs = (kal_uint8*)readBufferAddr;
      handle->hw_config.file_buffer_size = readBufferSize;

      if (KAL_TRUE == FSAL_IsRamFile(handle->fsal_handle))
      {
         handle->hw_config.decode_mode = GIF_DECODE_MEMORY;
      }
      else
      {
         handle->hw_config.decode_mode = GIF_DECODE_FILE;
         handle->fsalCacheAddr = (kal_uint8 *)fsalCacheAddr;
         handle->fsalCacheSize = fsalCacheSize;
         FSAL_SetBuffer(handle->fsal_handle, handle->fsalCacheSize, handle->fsalCacheAddr);
      }
      _gif_hw_set_local_fsal(handle->fsal_handle);

      handle->last_status = gifGetImageDimension(handle->fsal_handle, (kal_uint32*)&handle->imageWnd.w, (kal_uint32*)&handle->imageWnd.h);
      if (GIF_STATUS_OK == handle->last_status)
      {
         BIT_SET(handle->flag, GIF_FLAG_SET_FILE_BUF);
      }
#else
      handle->last_status = GIF_STATUS_DEC_UNAVAILABLE;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      handle->fsalCacheAddr = (kal_uint8 *)fsalCacheAddr;
      handle->fsalCacheSize = fsalCacheSize;
      FSAL_SetBuffer(handle->fsal_handle, handle->fsalCacheSize, handle->fsalCacheAddr);
      _gif_sw_set_local_fsal(handle->fsal_handle);

      handle->last_status = gifGetImageDimension(handle->fsal_handle, (kal_uint32*)&handle->imageWnd.w, (kal_uint32*)&handle->imageWnd.h);
      if (GIF_STATUS_OK == handle->last_status)
      {
         BIT_SET(handle->flag, GIF_FLAG_SET_FILE_BUF);
      }
      break;

   default:
      ASSERT(0);
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetFileBuffer() Leave.\n");
   return handle->last_status;
}



#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
GIF_STATUS_ENUM _gif_cf_to_hwcf(GIF_COLOR_FORMAT_ENUM cf, gif_out_format_enum *hwgif)
{
   switch (cf)
   {
   case GIF_COLOR_FORMAT_8:
      *hwgif = GIF_OUT_INDEX;
      break;

   case GIF_COLOR_FORMAT_16:
      *hwgif = GIF_OUT_RGB565;
      break;

   case GIF_COLOR_FORMAT_24:
      *hwgif = GIF_OUT_RGB888;
      break;

   case GIF_COLOR_FORMAT_ARGB8888:
      *hwgif = GIF_OUT_ARGB8888;
      break;

   default:
      return GIF_STATUS_INVALID_PARAMETER;  /* hardware gif decoder didn't support this color format */
   }
   return GIF_STATUS_OK;
}
#endif




GIF_STATUS_ENUM gifDecSetColorPaletteFormat(GIF_DECODER_HANDLE handle,
                                          GIF_COLOR_FORMAT_ENUM colorFormat)
{
#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   if (colorFormat >= GIF_COLOR_FORMAT_END)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }
   handle->palette_format = colorFormat;
   return GIF_STATUS_OK;
}



GIF_STATUS_ENUM gifDecSetDstRGBBufferInfo(GIF_DECODER_HANDLE handle,
                                          void * bufferAddr, kal_uint32 bufferSize,
                                          kal_uint32 width, kal_uint32 height,
                                          GIF_COLOR_FORMAT_ENUM colorFormat)
{
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetDstRGBBufferInfo() Enter. bufferAddr=%x, width=%d, height=%d\n", bufferAddr, width, height);

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   if ((!bufferAddr) || (!width) || (!height) || (colorFormat >= GIF_COLOR_FORMAT_END))
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      handle->last_status = _gif_cf_to_hwcf(colorFormat, &handle->hw_config.out_format);
      if (GIF_STATUS_OK != handle->last_status)
      {
         return handle->last_status;
      }

      if (GIF_OUT_ARGB8888 == handle->hw_config.out_format)
      {
         /* set alpha for ARGB8888 output */
         handle->hw_config.alpha_value = 255;
      }
      handle->canvasFormat = colorFormat;
      handle->canvasBytesPerPixel = _gif_get_bpp_by_color_format(colorFormat);
      handle->hw_config.output_buffer_adrs= (kal_uint8*)bufferAddr;
      handle->hw_config.output_buffer_size= width * height * handle->canvasBytesPerPixel;
      /* output buffer attributes */
      handle->hw_config.shadow_w = width;
      handle->hw_config.shadow_h = height;
      BIT_SET(handle->flag, GIF_FLAG_SET_CANVAS);
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      handle->canvasWnd.x = 0;
      handle->canvasWnd.y = 0;
      handle->canvasWnd.w = width;
      handle->canvasWnd.h = height;
      handle->canvasBuffer = bufferAddr;
      handle->canvasFormat = colorFormat;
      handle->canvasBytesPerPixel = _gif_get_bpp_by_color_format(colorFormat);
      BIT_SET(handle->flag, GIF_FLAG_SET_CANVAS);
      break;

   default:
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetDstRGBBufferInfo() Leave.\n");
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecSetDstWindow(GIF_DECODER_HANDLE handle,
                                   kal_int32 x, kal_int32 y,
                                   kal_uint32 width, kal_uint32 height)
{
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetDstWindow() Enter.  x=%d, y=%d, W=%d, H=%d\n", x, y, width, height);

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif
   if ((0 == width)||(0 == height))
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }

   if (!(handle->flag & GIF_FLAG_SET_CANVAS))
   {
      handle->last_status = GIF_STATUS_INVALID_SOURCE_FILE;
      return handle->last_status;
   }

   if (!(handle->flag & GIF_FLAG_SET_CLIP_WIND))
   {
      handle->last_status = GIF_STATUS_DEC_NO_CLIP_WINDOW;
      return handle->last_status;
   }

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
//#if defined (__GIF_DEC_6276_SERIES__)
#if defined (__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
#if defined (__GIF_DEC_6268_SERIES__)
      if ((handle->imageWnd.w != width)||(handle->imageWnd.h != height))
      {
         return GIF_STATUS_DEC_NON_SUPPORT;
      }
#endif
      handle->hw_config.dest_x = x;
      handle->hw_config.dest_y = y;
      handle->hw_config.expect_w = width;
      handle->hw_config.expect_h = height;
      BIT_SET(handle->flag, GIF_FLAG_SET_OUTPUT_WIND);

      {
         kal_int32 x_offset, y_offset;

         gif_color bg_color = 0;

         handle->hw_config.disposal_en = KAL_TRUE;

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
#endif
      }
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      {
         kal_bool b_is_resize = KAL_FALSE;

         if ((handle->imageWnd.w != width) && (handle->imageWnd.h != height))
         {
            BIT_SET(handle->flag, GIF_FLAG_RESIZE);
            b_is_resize = KAL_TRUE;
         }

         // sw resize limitaion is GIF_MAX_RESIZE_WIDTH, because of resize buffer length
         if ((width <= GIF_MAX_RESIZE_WIDTH) || (b_is_resize == KAL_FALSE))
         {
            kal_int32 x_offset, y_offset;
            gif_color bg_color = 0;

            handle->outputWnd.x = x;
            handle->outputWnd.y = y;
            handle->outputWnd.w = width;
            handle->outputWnd.h = height;
            BIT_SET(handle->flag, GIF_FLAG_SET_OUTPUT_WIND);
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
            #if defined(GIF_DISPOAL_METHOD)
/* under construction !*/
            #else
/* under construction !*/
            #endif
#endif
         }
         else
         {
            handle->last_status = GIF_STATUS_NOT_SUPPORT_RESIZING;
         }
      }
      break;

   default:
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetDstWindow() Leave.\n");
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecSetDstClipWindow(GIF_DECODER_HANDLE handle,
                                       kal_int32 x, kal_int32 y,
                                       kal_uint32 width, kal_uint32 height)

{
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetDstClipWindow() Enter. x=%d, y=%d, W=%d, H=%d\n", x, y, width, height);
#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      handle->hw_config.clip_x1 = x;
      handle->hw_config.clip_y1 = y;
      handle->hw_config.clip_x2 = x + width -1;
      handle->hw_config.clip_y2 = y + height -1;
      handle->last_status = GIF_STATUS_OK;
      BIT_SET(handle->flag, GIF_FLAG_SET_CLIP_WIND);
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      handle->clipWnd.x = x;
      handle->clipWnd.y = y;
      handle->clipWnd.w = width;
      handle->clipWnd.h = height;
      handle->last_status = GIF_STATUS_OK;
      BIT_SET(handle->flag, GIF_FLAG_SET_CLIP_WIND);
      break;

   default:
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetDstClipWindow() Leave.\n");
   return handle->last_status;
}




GIF_STATUS_ENUM gifDecSetSrcKey(GIF_DECODER_HANDLE handle, kal_bool srcKeyEnable, kal_uint32 srcKeyValue)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetSrcKey() Enter. srcKeyEnable = %d, srcKeyValue = %d\n", srcKeyEnable, srcKeyValue);
#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      if (srcKeyEnable)
      {
         BIT_SET(handle->flag, GIF_FLAG_SOURCE_KEY_ENABLE);
         handle->hw_config.color_replacing_en = KAL_TRUE;
         handle->hw_config.replaced_color = srcKeyValue;
         handle->hw_config.replace_color = srcKeyValue ^ 1;
      }
      else
      {
         BIT_CLR(handle->flag, GIF_FLAG_SOURCE_KEY_ENABLE);
         handle->hw_config.color_replacing_en = KAL_FALSE;
      }
         handle->last_status = GIF_STATUS_OK;
#else
         handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
     break;

   case GIF_DEC_TYPE_SW:
      if (srcKeyEnable)
      {
         BIT_SET(handle->flag, GIF_FLAG_SOURCE_KEY_ENABLE);
         handle->source_key = srcKeyValue;
      }
      else
      {
         BIT_CLR(handle->flag, GIF_FLAG_SOURCE_KEY_ENABLE);
      }
      handle->last_status = GIF_STATUS_OK;
      break;

   default:
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
      break;
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetSrcKey() Leave.\n");
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecQueryWorkingMemory(GIF_DECODER_HANDLE handle, kal_uint32 *intMemorySize, kal_uint32 *extMemorySize)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecQueryWorkingMemory() Enter.\n");
#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__)
      BIT_SET(handle->flag, GIF_FLAG_RESIZE);
      handle->last_status = GIF_STATUS_OK;
      *intMemorySize = 0;
      *extMemorySize = GIF_GCT_SIZE +
                       GIF_LCT_SIZE +
                       (GIF_HAL_STACK_SIZE * 2) +
                       GIF_HAL_TREE_SIZE +
                       GIF_SW_CACHE_WORK_BUFFER_SIZE +
                       256;

#elif defined(__GIF_DEC_6276_SERIES__)
      BIT_SET(handle->flag, GIF_FLAG_RESIZE);
      handle->last_status = GIF_STATUS_OK;
      *intMemorySize = 0;
      *extMemorySize = GIF_GCT_SIZE +
                       GIF_LCT_SIZE +
                       (GIF_HAL_STACK_SIZE * 2) +
                       GIF_HAL_TREE_SIZE +
                       GIF_SW_CACHE_WORK_BUFFER_SIZE +
                       256;
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      //need to resize
      if ((handle->outputWnd.w < handle->imageWnd.w) || (handle->outputWnd.h < handle->imageWnd.h))
      {
         BIT_SET(handle->flag, GIF_FLAG_RESIZE);
      #if defined(__GIF_DEC_6276_SERIES__)
         *intMemorySize = 0;
      #elif defined(__GIF_DEC_6268_SERIES__)
         *intMemorySize = 0;
      #else
         *intMemorySize = 0;
      #endif

      *extMemorySize = GIF_SW_DECODE_BUFFER_SIZE + GIF_HAL_TREE_SIZE
                        + (GIF_MAX_RESIZE_WIDTH * sizeof(signed short))
                        + (GIF_PALETTE_MAX_SIZE * sizeof(gif_color))
                        + (GIF_DEBUG_INFO_LENGHTH * GIF_DEBUG_WORKING_ITEM)
                        + GIF_SW_CACHE_WORK_BUFFER_SIZE
                      ;
      }
      else
      {
      #if defined(__GIF_DEC_6276_SERIES__)
         *intMemorySize = 0;
      #elif defined(__GIF_DEC_6268_SERIES__)
         *intMemorySize = 0;
      #else
         *intMemorySize = 0;
      #endif

         *extMemorySize = GIF_SW_DECODE_BUFFER_SIZE + GIF_HAL_TREE_SIZE + (GIF_PALETTE_MAX_SIZE * sizeof(gif_color)) +
                          (GIF_DEBUG_INFO_LENGHTH * (GIF_DEBUG_WORKING_ITEM - 1)) +
                          GIF_SW_CACHE_WORK_BUFFER_SIZE;
      }

      if (GIF_COLOR_FORMAT_8 == handle->canvasFormat)
      {
      #if defined(__GIF_DEC_6276_SERIES__)
         *intMemorySize = 0;
      #elif defined(__GIF_DEC_6268_SERIES__)
         *intMemorySize = 0;
      #else
      #endif
         *extMemorySize = *extMemorySize + (GIF_PALETTE_MAX_SIZE * sizeof(gif_color));
      }
      handle->last_status = GIF_STATUS_OK;
      break;

   default:
      ASSERT(0);
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecQueryWorkingMemory() Leave. intMemorySize = %d, extMemorySize = %d\n", *intMemorySize, *extMemorySize);
   return handle->last_status;
}



kal_int32 _gif_working_memory_dispatch(GIF_DECODER_HANDLE handle, STSMM* int_pool, STSMM* ext_pool)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_working_memory_dispatch() Enter.\n");

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__)
      if (smmGetFreeSpace(int_pool) >= (GIF_GCT_SIZE + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->hw_config.GCT_adrs = smmMalloc(int_pool, (GIF_GCT_SIZE + GIF_DEBUG_INFO_LENGHTH));
         #ifdef GIF_WORKING_MEMORY_DEBUG
         memset(handle->hw_config.GCT_adrs, 0xaa, (GIF_GCT_SIZE + GIF_DEBUG_INFO_LENGHTH);
         #endif
      }
      else if (smmGetFreeSpace(ext_pool) >= ((GIF_GCT_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.GCT_adrs = smmMalloc(ext_pool, (GIF_GCT_SIZE + GIF_DEBUG_INFO_LENGHTH));
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(int_pool) >= (GIF_LCT_SIZE + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->hw_config.LCT_adrs = smmMalloc(int_pool, (GIF_LCT_SIZE + GIF_DEBUG_INFO_LENGHTH));
         #ifdef GIF_WORKING_MEMORY_DEBUG
         memset(handle->hw_config.LCT_adrs, 0xaa, (GIF_LCT_SIZE + GIF_DEBUG_INFO_LENGHTH);
         #endif
      }
      else if (smmGetFreeSpace(ext_pool) >= ((GIF_LCT_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.LCT_adrs = smmMalloc(ext_pool, (GIF_LCT_SIZE + GIF_DEBUG_INFO_LENGHTH));
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(int_pool) >= (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->hw_config.stack1_adrs = smmMalloc(int_pool, (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH));
         handle->hw_config.stack_size = GIF_HAL_STACK_SIZE;

         #ifdef GIF_WORKING_MEMORY_DEBUG
         memset(handle->hw_config.stack1_adrs, 0xaa, (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH);
         #endif
      }
      else if (smmGetFreeSpace(ext_pool) >= ((GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.stack1_adrs = smmMalloc(ext_pool, (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH));
         handle->hw_config.stack_size = GIF_HAL_STACK_SIZE;
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(int_pool) >= (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->hw_config.stack2_adrs = smmMalloc(int_pool, (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH));
         handle->hw_config.stack_size = GIF_HAL_STACK_SIZE;
         #ifdef GIF_WORKING_MEMORY_DEBUG
         memset(handle->hw_config.stack2_adrs, 0xaa, (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH);
         #endif
      }
      else if (smmGetFreeSpace(ext_pool) >= ((GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.stack2_adrs = smmMalloc(ext_pool, (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH));
         handle->hw_config.stack_size = GIF_HAL_STACK_SIZE;
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(int_pool) >= (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->hw_config.tree_adrs = smmMalloc(int_pool, (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH));
         handle->hw_config.tree_size = GIF_HAL_TREE_SIZE;
         #ifdef GIF_WORKING_MEMORY_DEBUG
         memset(handle->hw_config.tree_adrs, 0xaa, (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH);
         #endif
      }
      else if (smmGetFreeSpace(ext_pool) >= ((GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.tree_adrs = smmMalloc(ext_pool, (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH));
         handle->hw_config.tree_size = GIF_HAL_TREE_SIZE;
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(int_pool) >= GIF_SW_CACHE_WORK_BUFFER_SIZE)
      {
         handle->cache_work_buffer = smmMalloc(int_pool, GIF_SW_CACHE_WORK_BUFFER_SIZE);
      }
      else if (smmGetFreeSpace(ext_pool) >= GIF_SW_CACHE_WORK_BUFFER_SIZE)
      {
         handle->cache_work_buffer = smmMalloc(ext_pool, GIF_SW_CACHE_WORK_BUFFER_SIZE);
      }
      else
      {
         return -1;
      }
#elif defined(__GIF_DEC_6276_SERIES__)

      if (smmGetFreeSpace(ext_pool) >= ((GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.stack1_adrs = smmMallocAligned(ext_pool, (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH), 8);
         handle->hw_config.stack_size = GIF_HAL_STACK_SIZE;
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(ext_pool) >= ((GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.stack2_adrs = smmMallocAligned(ext_pool, (GIF_HAL_STACK_SIZE + GIF_DEBUG_INFO_LENGHTH), 8);
         handle->hw_config.stack_size = GIF_HAL_STACK_SIZE;
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(ext_pool) >= ((GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.tree_adrs = smmMallocAligned(ext_pool, (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH), 8);
         handle->hw_config.tree_size = GIF_HAL_TREE_SIZE;
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(ext_pool) >= ((GIF_GCT_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.GCT_adrs = smmMallocAligned(ext_pool, (GIF_GCT_SIZE + GIF_DEBUG_INFO_LENGHTH), 8);
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(ext_pool) >= ((GIF_LCT_SIZE + GIF_DEBUG_INFO_LENGHTH)))
      {
         handle->hw_config.LCT_adrs = smmMallocAligned(ext_pool, (GIF_LCT_SIZE + GIF_DEBUG_INFO_LENGHTH), 8);
      }
      else
      {
         return -1;
      }

      if (smmGetFreeSpace(ext_pool) >= GIF_SW_CACHE_WORK_BUFFER_SIZE)
      {
         handle->cache_work_buffer = smmMallocAligned(ext_pool, GIF_SW_CACHE_WORK_BUFFER_SIZE, 8);
      }
      else
      {
         return -1;
      }
      break;
#else
      return -1;
#endif

   case GIF_DEC_TYPE_SW:
      //palette
      if (smmGetFreeSpace(int_pool) >= ((GIF_PALETTE_MAX_SIZE * sizeof(gif_color)) + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->active_palette = smmMalloc(int_pool, (GIF_PALETTE_MAX_SIZE * sizeof(gif_color)) + GIF_DEBUG_INFO_LENGHTH);
         #ifdef GIF_WORKING_MEMORY_DEBUG
         memset(handle->active_palette, 0xaa, (GIF_PALETTE_MAX_SIZE * sizeof(gif_color)) + GIF_DEBUG_INFO_LENGHTH);
         #endif
      }
      else if (smmGetFreeSpace(ext_pool) >= ((GIF_PALETTE_MAX_SIZE * sizeof(gif_color)) + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->active_palette = smmMalloc(ext_pool, ((GIF_PALETTE_MAX_SIZE * sizeof(gif_color)) + GIF_DEBUG_INFO_LENGHTH));
      }
      else
      {
         return -1;
      }

      //stack size
      if (smmGetFreeSpace(int_pool) >= (GIF_SW_DECODE_BUFFER_SIZE + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->stack = smmMalloc(int_pool, (GIF_SW_DECODE_BUFFER_SIZE + GIF_DEBUG_INFO_LENGHTH));
         #ifdef GIF_WORKING_MEMORY_DEBUG
         memset(handle->stack, 0xaa, (GIF_SW_DECODE_BUFFER_SIZE + GIF_DEBUG_INFO_LENGHTH));
         #endif
      }
      else if (smmGetFreeSpace(ext_pool) >= (GIF_SW_DECODE_BUFFER_SIZE + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->stack = smmMalloc(ext_pool, (GIF_SW_DECODE_BUFFER_SIZE + GIF_DEBUG_INFO_LENGHTH));
      }
      else
      {
         return -1;
      }

      //cache work buffer size
      if (smmGetFreeSpace(int_pool) >= GIF_SW_CACHE_WORK_BUFFER_SIZE)
      {
         handle->cache_work_buffer = smmMalloc(int_pool, GIF_SW_CACHE_WORK_BUFFER_SIZE);
      }
      else if (smmGetFreeSpace(ext_pool) >= GIF_SW_CACHE_WORK_BUFFER_SIZE)
      {
         handle->cache_work_buffer = smmMalloc(ext_pool, GIF_SW_CACHE_WORK_BUFFER_SIZE);
      }
      else
      {
         return -1;
      }

      //tree buffer size
      if (smmGetFreeSpace(int_pool) >= (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->tree_buffer = smmMalloc(int_pool, (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH));
         #ifdef GIF_WORKING_MEMORY_DEBUG
         memset(handle->tree_buffer, 0xaa, (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH));
         #endif
      }
      else if (smmGetFreeSpace(ext_pool) >= (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH))
      {
         handle->tree_buffer = smmMalloc(ext_pool, (GIF_HAL_TREE_SIZE + GIF_DEBUG_INFO_LENGHTH));
      }
      else
      {
         return -1;
      }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef GIF_WORKING_MEMORY_DEBUG
/* under construction !*/
            #endif
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

      // index palette
      if (GIF_COLOR_FORMAT_8 == handle->canvasFormat)
      {
         if (smmGetFreeSpace(int_pool) >= ((GIF_PALETTE_MAX_SIZE * sizeof(gif_color))))
         {
            handle->index_palette = smmMalloc(int_pool, (GIF_PALETTE_MAX_SIZE * sizeof(gif_color)));
            handle->index_palette_size = GIF_PALETTE_MAX_SIZE;
         }
         else if (smmGetFreeSpace(ext_pool) >= ((GIF_PALETTE_MAX_SIZE * sizeof(gif_color))))
         {
            handle->index_palette = smmMalloc(ext_pool, ((GIF_PALETTE_MAX_SIZE * sizeof(gif_color))));
            handle->index_palette_size = GIF_PALETTE_MAX_SIZE;
         }
         else
         {
            return -1;
         }
      }

   break;
      default:
      ASSERT(0);
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_working_memory_dispatch() Leave.\n");
   return 0;
}




GIF_STATUS_ENUM gifDecSetWorkingMemory(GIF_DECODER_HANDLE handle,
                                       void *intMemoryAddr,
                                       kal_uint32 intMemorySize,
                                       void *extMemoryAddr,
                                       kal_uint32 extMemorySize)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetWorkingMemory() Enter. intMemoryAddr: %x,intMemorySize: %d, extMemoryAddr: %x,extMemorySize: %d,\n",
   //intMemoryAddr, intMemorySize, extMemoryAddr, extMemorySize);

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   if (0 == smmInit(&handle->intMemorySMM, intMemoryAddr, intMemorySize))
   {
      handle->last_status = GIF_STATUS_DEC_ERROR_INVALID_BUFFER;
      return handle->last_status;
   }

   if (0 == smmInit(&handle->extMemorySMM, extMemoryAddr, extMemorySize))
   {
      handle->last_status = GIF_STATUS_DEC_ERROR_INVALID_BUFFER;
      return handle->last_status;
   }

   if (_gif_working_memory_dispatch(handle, &handle->intMemorySMM, &handle->extMemorySMM))
   {
      handle->last_status = GIF_STATUS_DEC_MEMORY_LACK;
      return handle->last_status;
   }

   BIT_SET(handle->flag, GIF_FLAG_SET_WORKING_BUF);
   handle->last_status = GIF_STATUS_OK;

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetWorkingMemory() Leave.\n");
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecSetCheckAbortFunction (GIF_DECODER_HANDLE handle, gif_check_abort fpcheckAbort)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetCheckAbortFunction() Enter.\n");

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }

   if (!fpcheckAbort)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }
#endif

   handle->check_abort_func = fpcheckAbort;
   handle->last_status = GIF_STATUS_OK;
   BIT_SET(handle->flag, GIF_FLAG_SET_CHECH_ABORT);
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetCheckAbortFunction() Leave.\n");
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecSetCallbackFunction (GIF_DECODER_HANDLE handle, void (*gif_callback)(kal_uint32 status, kal_uint32 fn))
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetCallbackFunction() Enter.\n");

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }

   if (!gif_callback)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }
#endif

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      handle->hw_config.gif_cb = gif_callback;
      BIT_SET(handle->flag, GIF_FLAG_SET_CALLBACK);
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
        handle->callback = gif_callback;
        BIT_SET(handle->flag, GIF_FLAG_SET_CALLBACK);
        break;

   default:
      ASSERT(0);
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecSetCallbackFunction() Leave.\n");
   return handle->last_status;
}





GIF_STATUS_ENUM _gif_sw_dec_start(GIF_DECODER_HANDLE handle, kal_int32 frame_number)
{
   GIF_STATUS_ENUM rtn;

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_dec_start() Enter.\n");
   if (!(handle->flag & GIF_FLAG_SW_CONFIG_READY))
   {
      if (GIF_COLOR_FORMAT_8 == handle->canvasFormat)
      {
         // TODO: prepare set index palette function
         handle->set_index_palette_func = _gif_sw_layer_set_palette;
         g_gif_index_palette = handle->index_palette;
      }
      else
      {
         handle->set_index_palette_func = NULL;
      }

      gif_sw_init(handle->stack,
                  handle->tree_buffer,
                  handle->active_palette,
                  handle->set_index_palette_func,//gif_sw_layer_set_palette_func gif_sw_layer_set_palette,
                  _gif_set_delay_time,//gif_sw_anim_set_delay_func gif_sw_anim_set_delay,
                  NULL,//gif_sw_set_update_area_func gif_sw_set_update_area,
                  handle->check_abort_func,//gif_sw_image_progress_callback_func gif_sw_image_progress_callback,
                  NULL,
                  handle->en_disposal,//kal_bool using_disposal,
                  0,//KAL_ADM_ID gif_sw_disposal_buf_adm_id,
                  _gif_sw_bitblt//gif_sw_bitblt_func gif_sw_bitblt)
                  );

      gif_sw_set_dest_buf(handle->canvasBuffer, handle->canvasWnd.w);
      gif_sw_set_dest_color_format(handle->canvasFormat, handle->canvasFormat);

      //enable source key
      if (handle->flag & GIF_FLAG_SOURCE_KEY_ENABLE)
      {
         gif_sw_set_dest_source_key(KAL_TRUE, handle->source_key);
      }
      else
      {
         gif_sw_set_dest_source_key(KAL_FALSE, 0xffffffff);
      }

      //set clipping window, default are canvas window
      if (handle->flag & GIF_FLAG_SET_CLIP_WIND)
      {
         gif_sw_set_dest_clip(handle->clipWnd.x, handle->clipWnd.y,
                              (handle->clipWnd.x + handle->clipWnd.w -1),
                              (handle->clipWnd.y + handle->clipWnd.h -1));
      }
      else
      {
         gif_sw_set_dest_clip(0, 0, (handle->canvasWnd.w - 1), (handle->canvasWnd.h - 1));
      }
      BIT_SET(handle->flag, GIF_FLAG_SW_CONFIG_READY);
   }

   //chech if it need to resize or not
   if (handle->flag & GIF_FLAG_RESIZE)
   {
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_dec_start() Resize decode start.\n");

      rtn = gif_sw_draw_resized(handle->outputWnd.x, handle->outputWnd.y,
                                handle->outputWnd.w, handle->outputWnd.h,
                                (kal_uint8 *)handle->cache_id,
                                handle->image_file_size,
                                frame_number,
                                handle->transparent_enable,
                                handle->canvasFormat,
                                handle->palette_format);
   }
   else
   {
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_dec_start() No-resize decode start.\n");

      rtn = gif_sw_draw(handle->outputWnd.x, handle->outputWnd.y,
                        (kal_uint8 *)handle->cache_id,
                        handle->image_file_size,
                        frame_number,
                        handle->transparent_enable,
                        handle->canvasFormat,
                        handle->palette_format);
   }

   if (GIF_STATUS_OK == rtn)
   {
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_dec_start() decode ok. \n");
      handle->last_status = GIF_STATUS_OK;
      handle->dec_state = GIF_DEC_STATE_COMPLETE;
      if (handle->callback)
      {
         handle->callback(GIF_DEC_STATE_COMPLETE ,frame_number);
      }
   }
   else
   {
      SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_dec_start() decode fail. status=%x \n", rtn);
      handle->last_status = rtn;//GIF_STATUS_DEC_ERROR_INVALID_FILE;
      handle->dec_state = GIF_DEC_STATE_STOP;
      if (handle->callback)
      {
         handle->callback(GIF_DEC_STATE_STOP ,frame_number);
      }
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_sw_dec_start() Leave. \n");
   return handle->last_status;
}



#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
GIF_STATUS_ENUM _gif_hw_decode_result_transfer(gif_report_status_enum result)
{
   GIF_STATUS_ENUM rtn = GIF_STATUS_OK;
   switch (result)
   {
   case GIF_DECODING:
   case GIF_FINISH_FRAME:
      if (KAL_TRUE == gif_dcb.trailer)
      {
          rtn = GIF_STATUS_OK;
      }
      break;

   case GIF_NO_FRAME:
      rtn = GIF_STATUS_NO_FRAME;
      break;

   case GIF_INVALID_FORMAT:
      rtn = GIF_STATUS_INVALID_FORMAT;
      break;

   case GIF_NOT_SUPPORT_RESIZING:
      rtn = GIF_STATUS_NOT_SUPPORT_RESIZING;
      break;

   case GIF_OUTPUT_WINDOW_NO_INTERSECTION:
      rtn = GIF_STATUS_OUTPUT_WINDOW_NO_INTERSECTION;
      break;

   default:
      ASSERT(0);
      rtn = GIF_STATUS_INVALID_PARAMETER;
      break;
   }
   return rtn;
}
#endif



#if defined(__MTK_TARGET__) && defined(__GIF_SWLA_DEBUG__)
#define GIF_SWLA_DEBUG(tag,start) SLA_CustomLogging((tag), (start));
#else
#define GIF_SWLA_DEBUG(tag,start)
#endif


GIF_STATUS_ENUM gifDecStart(GIF_DECODER_HANDLE handle, kal_int32 frameNumber)
{
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
   gif_report_status_enum hw_rtn;
#endif
   //kal_uint32 start, end;
   //start = drv_get_current_time();

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecStart() Enter. frameNumber=%d\n", frameNumber);
   GIF_SWLA_DEBUG("GIF", 1);


#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      handle->last_status = GIF_STATUS_INVALID_HANDLE;
      return GIF_DEC_STATE_STOP;
   }
#endif

   handle->last_status = _gif_set_cache_id(handle);
   if (GIF_STATUS_OK != handle->last_status)
   {
      return handle->last_status;
   }

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      if (0 == frameNumber)
      {
         kal_int32 x_offset, y_offset;
   	  
         gif_color bg_color = 0;
   	  
         x_offset = handle->hw_config.dest_x;
         y_offset = handle->hw_config.dest_y;
         if (x_offset < handle->hw_config.clip_x1)
         {
            x_offset = handle->hw_config.clip_x1;
         }
   	  
         if (y_offset < handle->hw_config.clip_y1)
         {
            y_offset = handle->hw_config.clip_y1;
         }
   	  
         //get left & top pixed of canvas as background color
         bg_color = _gif_get_color(x_offset, y_offset, handle->hw_config.output_buffer_adrs,
         handle->hw_config.shadow_w, handle->canvasBytesPerPixel, handle->canvasFormat);
         handle->hw_config.bg_color = bg_color;
      }

      if (handle->flag & GIF_FLAG_SET_FILE_BUF)
      {
         handle->hw_config.frame_number = frameNumber;
         hw_rtn = gif_decode_start(&handle->hw_config, &handle->hw_info);
         handle->last_status = _gif_hw_decode_result_transfer(hw_rtn);
      }
      else
      {
         handle->last_status = GIF_STATUS_DEC_NO_READ_BUFFER;
      }
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      handle->frame_number = frameNumber;
      if (0 == frameNumber)
      {
         kal_int32 x_offset, y_offset;
         gif_color bg_color = 0;
	  
         x_offset = handle->outputWnd.x;
         y_offset = handle->outputWnd.y;
	  
         if ( x_offset < handle->clipWnd.x)
         {
            x_offset = handle->clipWnd.x;
         }
	  
         if (y_offset < handle->clipWnd.y)
         {
            y_offset = handle->clipWnd.y;
         }
         //get left & top pixed of canvas as background color
         bg_color = _gif_get_color(x_offset, y_offset, (kal_uint8*)handle->canvasBuffer,
         handle->canvasWnd.w, handle->canvasBytesPerPixel, handle->canvasFormat);
#if defined(GIF_DISPOAL_METHOD)
         _gif_set_disposal(handle, KAL_TRUE, gif_adm_malloc, gif_adm_free, bg_color);
#else
         _gif_set_disposal(handle, KAL_FALSE, NULL, NULL, bg_color);
#endif
      }

      handle->last_status = _gif_sw_dec_start(handle, frameNumber);
      break;

   default:
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
      break;
   }

   GIF_SWLA_DEBUG("GIF", 0);

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecStart() Leave. last_status=%x\n", handle->last_status);
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecStart() Leave. last_status=%x. %d ticks\n", handle->last_status, drv_get_duration_tick(start, end));
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecResume(GIF_DECODER_HANDLE handle)
{
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
   gif_report_status_enum hw_rtn;

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecResume() Enter. \n");

   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
      hw_rtn = gif_decode_resume(&handle->hw_config, &handle->hw_info);
      handle->last_status = _gif_hw_decode_result_transfer(hw_rtn);
      break;

   case GIF_DEC_TYPE_SW:
      break;

   default:
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecResume() Leave. \n");
   return handle->last_status;
#else
   return GIF_STATUS_OK;
#endif
}



GIF_STATUS_ENUM gifDecStop(GIF_DECODER_HANDLE handle)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecStop() Enter. \n");
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      gif_decode_stop();
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      break;

   default:
      ASSERT(0);
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecStop() Leave. \n");
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecGetState(GIF_DECODER_HANDLE handle, GIF_DEC_STATE_ENUM *state)
{
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecGetState() Enter. \n");

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }

   if (!state)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }
#endif

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      if ((GIF_STATUS_COMPLETE == gif_dcb.int_status) && (GIF_STATE_PAUSE == gif_state))
      {
         *state = GIF_DEC_STATE_COMPLETE;
      }
      else
      {
         *state = (GIF_DEC_STATE_ENUM)gif_state;
      }
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      *state = handle->dec_state;
      break;

   default:
      ASSERT(0);
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecGetState() Leave. dec_state:%x\n", *state);
   return handle->last_status;
}



GIF_STATUS_ENUM gifGetImageDimension(STFSAL* pfsal, kal_uint32 *width, kal_uint32 *height)
{
   //STFSAL* pfsal_old = NULL;
   GIF_STATUS_ENUM rtn = GIF_STATUS_OK;

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifGetImageDimension() Enter. \n");

#ifdef GIF_PARAMETER_CHECK
   if (!pfsal)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }
#endif

   gif_sw_get_image_dimension_internal(pfsal, width, height);

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifGetImageDimension() Leave. width = %d, height = %d\n", *width, *height);
   return rtn;
}



GIF_STATUS_ENUM gifDecGetSrcDimension(GIF_DECODER_HANDLE handle, kal_uint16 *width, kal_uint16 *height)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecGetSrcDimension() Enter. \n");

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   if (!(handle->flag & GIF_FLAG_SET_SOURCE_FILE))
   {
      return GIF_STATUS_INVALID_SOURCE_FILE;
   }

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      *width = handle->imageWnd.w;
      *height = handle->imageWnd.h;
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      *width = handle->imageWnd.w;
      *height = handle->imageWnd.h;
      break;

   default:
      ASSERT(0);
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecGetSrcDimension() Leave. width = %d, height = %d\n", *width, *height);
   return handle->last_status;
}



GIF_STATUS_ENUM _gif_get_frame_delay_ext(STFSAL *pfsal, kal_int32 *frameCount, kal_uint32 *frameDelayArray, kal_uint32 arraySize, kal_uint32 check_animation_flag)
{
   STFSAL fsal_new = {0};
   GIF_STATUS_ENUM rtn = GIF_STATUS_OK;
   kal_bool blocal_fsal_cache = KAL_FALSE;
   kal_uint8* buf;

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_get_frame_delay_ext() Enter. \n");

   if (!pfsal)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }

   FSAL_Open_Attach(&fsal_new, pfsal);
   buf = (kal_uint8*)get_ctrl_buffer(512);
   if (buf)
   {
      FSAL_SetBuffer(&fsal_new, 512, buf);
      blocal_fsal_cache = KAL_TRUE;
   }

   /*memcpy(&fsal_new, pfsal, sizeof(STFSAL));
   if (!FSAL_IsRamFile(&fsal_new))
   {
      //file in disc and not set fsal cache buffer.
      {
         fsal_new.pbBuf = (kal_uint8*)get_ctrl_buffer(256);
         if (fsal_new.pbBuf)
         {
            fsal_new.uBufSize = 256;
            fsal_new.bBuffering = KAL_TRUE;
            blocal_fsal_cache = KAL_TRUE;
         }
      }
   }*/

   //GIF_SW_TRY
   {
      if (gif_sw_get_frame_delay_internal(&fsal_new, frameCount, frameDelayArray, arraySize, check_animation_flag))
      {
         SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_get_frame_delay_ext() GIF_STATUS_DEC_ERROR_PARSE. \n");
         rtn = GIF_STATUS_DEC_ERROR_PARSE;
      }
   }
   //GIF_SW_CATCH_BEGIN
   //{
   //   SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_get_frame_delay_ext() GIF_STATUS_DEC_ERROR_PARSE. \n");
   //   rtn = GIF_STATUS_DEC_ERROR_PARSE;
   //}
   //GIF_SW_CATCH_END


   if (blocal_fsal_cache)
   {
      free_ctrl_buffer(buf);
   }
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_get_frame_delay_ext() Leave. frameCount = %d\n", *frameCount);
   return rtn;
}



GIF_STATUS_ENUM _gif_get_frame_disposal_ext(
    STFSAL *pfsal, 
    kal_int32 *frameCount, 
    GIF_DISPOSAL_METHOD_ENUM *frameDisposalArray, 
    kal_uint32 arraySize, 
    kal_bool get_all_frame_disposal)
{
   STFSAL fsal_new = {0};
   GIF_STATUS_ENUM rtn = GIF_STATUS_OK;
   kal_bool blocal_fsal_cache = KAL_FALSE;
   kal_uint32 cache_id;
   kal_uint8* buf;
   //SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_get_frame_disposal_ext() Enter. \n");

   if (!pfsal)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }

   FSAL_Open_Attach(&fsal_new, pfsal);
   buf = (kal_uint8*)get_ctrl_buffer(512);
   if (buf)
   {
      FSAL_SetBuffer(&fsal_new, 512, buf);
      blocal_fsal_cache = KAL_TRUE;
   }

   /*
   memcpy(&fsal_new, pfsal, sizeof(STFSAL));
   if (!FSAL_IsRamFile(&fsal_new))
   {
      //file in disc and not set fsal cache buffer.
      //if (!fsal_new.bBuffering) 
      {
         fsal_new.pbBuf = (kal_uint8*)get_ctrl_buffer(512);
         if (fsal_new.pbBuf)
         {
            fsal_new.uBufSize = 512;
            fsal_new.bBuffering = KAL_TRUE;
            fsal_new.uCachedBlock = 0xFFFFFFFF; //Make sure the FSAL will read again
            blocal_fsal_cache = KAL_TRUE;
         }
      }
   }*/


   cache_id = _gif_get_cache_id(pfsal, (kal_uint32*)pfsal->pbBuf);

   //GIF_SW_TRY
   {
      kal_int32 status = 0;

      if (get_all_frame_disposal)
      {
         status = gif_sw_get_all_frame_disposal_method(&fsal_new, frameCount, frameDisposalArray, arraySize);
      }
      else
      {
         status = gif_sw_get_frame_n_disposal_method(&fsal_new, cache_id, *frameCount, frameDisposalArray);
      }

      if (GIF_SW_RET_SUCCEED != status)
      {
         SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_get_frame_disposal_ext() GIF_STATUS_DEC_ERROR_PARSE. \n");
         rtn = GIF_STATUS_DEC_ERROR_PARSE;
      }
   }
   //GIF_SW_CATCH_BEGIN
   //{
   //   SW_GIF_TRACE(MOD_MMI, "[gif] - _gif_get_frame_disposal_ext() GIF_STATUS_DEC_ERROR_PARSE. \n");
   //   rtn = GIF_STATUS_DEC_ERROR_PARSE;
   //}
   //GIF_SW_CATCH_END

   //*frameCount = frame_num;
   //set old handle back
   //_gif_sw_set_local_fsal(pfsal_old);

   if (blocal_fsal_cache)
   {
      free_ctrl_buffer(buf);
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - _gif_get_frame_disposal_ext() Leave. frameCount = %d\n", *frameCount);
   return rtn;
}



GIF_STATUS_ENUM gifCheckAnimation(STFSAL *pfsal, kal_uint32 *isAnimation)
{
   kal_int32 frame_count;
   GIF_STATUS_ENUM status;

   kal_uint32 cache_id;
   kal_int16 lcd_idx;
   kal_int32 offset;
   kal_int32 real_frame_count = 0;
   kal_uint32 cache_work_buffer[GIF_SW_CACHE_WORK_BUFFER_SIZE];
   gif_sw_image_struct *cache = NULL;
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
   gif_cache_struct* hw_driver_cache = NULL;
#endif

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifCheckAnimation() Enter.\n");
   GIF_SWLA_DEBUG("GCA", 1);

   *isAnimation = 0;
   cache_id = _gif_get_cache_id(pfsal, cache_work_buffer);

   if (gif_sw_gif_hit_cache(cache_id, 0, 0, KAL_FALSE, 0, &lcd_idx, &real_frame_count, &offset, KAL_FALSE))
   {
      //gif_is_hit_cache = 1;      
      cache = _gif_sw_get_cache_by_id(lcd_idx);

      if (cache->animation_file_check_done)
      {
         *isAnimation = cache->is_animation_file;
          GIF_SWLA_DEBUG("GCA", 0);
          return GIF_STATUS_OK;
      }
   }
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
   else
   {
      //check HW driver cache information
      kal_bool status = KAL_FALSE;
      kal_uint32 file_size; 
      FSAL_GetFileSize(pfsal, &file_size);
      status = gif_hw_get_cache_by_id(cache_id, file_size, &hw_driver_cache);
      if (hw_driver_cache->animation_file_check_done)
      {
         *isAnimation = hw_driver_cache->is_animation_file;
          GIF_SWLA_DEBUG("GCA", 0);
          return GIF_STATUS_OK;
      }
   }
#endif // #if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)


   status = _gif_get_frame_delay_ext(pfsal, &frame_count, NULL, 0, 1);
   if (GIF_STATUS_OK == status)
   {
      if (frame_count >= 2)
      {
         *isAnimation = 1;
      }
   }

   if (NULL != cache)
   {
      cache->is_animation_file = (kal_bool) (*isAnimation);
      cache->animation_file_check_done = KAL_TRUE;
   }
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
   else if (NULL !=hw_driver_cache)
   {
      hw_driver_cache->is_animation_file = *isAnimation;
      hw_driver_cache->animation_file_check_done = KAL_TRUE;
   }
#endif // #if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)


   GIF_SWLA_DEBUG("GCA", 0);
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifCheckAnimation() Leave. isAnimation:%d\n", *isAnimation);
   return status;
}


GIF_STATUS_ENUM gifGetFrameNDisposalMethod(
    GIF_DECODER_HANDLE handle,
    STFSAL *pfsal,
    kal_int32 frameIdx, 
    GIF_DISPOSAL_METHOD_ENUM *frameDisposal)
{
    GIF_STATUS_ENUM status;

#if 1
    //SW_GIF_TRACE(MOD_MMI, "[gif] - gifGetFrameNDisposalMedhod() Enter.\n");
    if ((handle) && (GIF_DEC_TYPE_HW == handle->codec_type))
    {
        kal_int32 rael_frame_count;
        GIF_DISPOSAL_METHOD_ENUM array[512] = {GIF_DISPOSAL_NO_ACTION};

        if (frameIdx > 512)
        {
            return GIF_STATUS_INVALID_OPERATION;
        }
        status = gif_sw_get_n_frames_disposal_method(pfsal, frameIdx, &rael_frame_count, array, 512);
        *frameDisposal = array[frameIdx];
        //status = GIF_STATUS_OK;
    }
    else
    {
        status = _gif_get_frame_disposal_ext(pfsal, &frameIdx, frameDisposal, 1, KAL_FALSE);
    }
    if (*frameDisposal == GIF_DISPOSAL_RSVD)
    {
      status = GIF_STATUS_NO_FRAME;
    }

    if (*frameDisposal > GIF_DISPOSAL_RSVD)
    {
       //ASSERT(0);
      *frameDisposal = GIF_DISPOSAL_NO_ACTION;
    }

    //SW_GIF_TRACE(MOD_MMI, "[gif] - gifGetFrameNDisposalMedhod() Leave.\n");
    return status;    
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}




GIF_STATUS_ENUM gifGetAllFrameDisposalMethod(
    STFSAL *pfsal, 
    kal_int32 *frameCount, 
    GIF_DISPOSAL_METHOD_ENUM *frameDisposalArray, 
    kal_uint32 arraySize)
{
    GIF_STATUS_ENUM status;
    //SW_GIF_TRACE(MOD_MMI, "[gif] - gifGetFrameDelay() Enter.\n");    
    status = _gif_get_frame_disposal_ext(pfsal, frameCount, frameDisposalArray, arraySize, KAL_TRUE);
    //SW_GIF_TRACE(MOD_MMI, "[gif] - gifGetFrameDelay() Leave.\n");
    return status;
}


GIF_STATUS_ENUM gifGetFrameDelay(STFSAL *pfsal, kal_int32 *frameCount, kal_uint32 *frameDelayArray, kal_uint32 arraySize)
{
   GIF_STATUS_ENUM status;
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifGetFrameDelay() Enter.\n");
   status = _gif_get_frame_delay_ext(pfsal, frameCount, frameDelayArray, arraySize, 0);
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifGetFrameDelay() Leave.\n");
   return status;	
}



GIF_STATUS_ENUM gifDecGetCurFrameDelayTime(GIF_DECODER_HANDLE handle, kal_uint32 *delayTime)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecGetCurFrameDelayTime() Enter. \n");

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   if (!delayTime)
   {
      handle->last_status = GIF_STATUS_INVALID_PARAMETER;
   }

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      *delayTime = handle->hw_info.delay_time * 10;
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      *delayTime = _gif_get_delay_time();
      handle->last_status = GIF_STATUS_OK;
      break;

   default:
      ASSERT(0);
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecGetCurFrameDelayTime() Leave. delayTime = %d\n", *delayTime);
   return handle->last_status;
}


GIF_STATUS_ENUM gifDecGetPalette(GIF_DECODER_HANDLE handle, gif_color **paletteAddr, kal_uint16 *paletteSize)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecGetPalette() Enter. \n");

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }

   if ((!paletteAddr) || (!paletteSize))
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }
#endif

   handle->last_status = GIF_STATUS_OK;
   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      if (GIF_OUT_INDEX == handle->hw_config.out_format)
      {
         if (handle->hw_info.LCT_flag)
         {
            *paletteAddr = handle->hw_config.LCT_adrs;
            *paletteSize = handle->hw_info.LCT_size;
         }
         else
         {
            *paletteAddr = handle->hw_config.GCT_adrs;
            *paletteSize = handle->hw_info.GCT_size;
         }

         /// Handle source key color here.
         if (KAL_TRUE == handle->hw_config.color_replacing_en)
         {
            const kal_uint32 color_0 = handle->hw_config.replaced_color;
            const kal_uint32 color_1 = handle->hw_config.replace_color;

            kal_int32 i = *paletteSize;
            gif_color *palette_ptr = *paletteAddr;

            while (--i >= 0)
            {
               if (color_0 == *palette_ptr)
               {
                  *palette_ptr = color_1;
               }
               palette_ptr++;
            }
         }
      }
      else
      {
         handle->last_status = GIF_STATUS_DEC_NON_SUPPORT;
      }
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      if (GIF_COLOR_FORMAT_8 == handle->canvasFormat)
      {
         handle->index_palette_size = _gif_sw_get_cur_palette_size();
         *paletteSize = handle->index_palette_size;
         *paletteAddr = handle->index_palette;
      }
      else
      {
         handle->last_status = GIF_STATUS_DEC_NON_SUPPORT;
      }
      break;

   default:
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
      break;
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecGetPalette() Leave. paletteSize = %d\n", *paletteSize);
   return handle->last_status;
}


GIF_STATUS_ENUM gifDecGetTransparentIndex(GIF_DECODER_HANDLE handle, kal_uint8* transparentIndex)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecGetTransparentIndex() Enter. \n");

#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }

   if (!transparentIndex)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }
#endif

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      if (handle->hw_info.transparent_flag)
      {
         *transparentIndex = handle->hw_info.transparent_index;
         handle->last_status = GIF_STATUS_OK;
      }
      else
      {
         handle->last_status = GIF_STATUS_DATA_UNAVAILABLE;
      }
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      handle->transparent_index = (kal_uint8)gif_sw_get_transparent_index();
      *transparentIndex = handle->transparent_index;
      handle->last_status = GIF_STATUS_OK;
      break;

   default:
      ASSERT(0);
      break;
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecGetTransparentIndex() Leave. transparentIndex = %d\n", *transparentIndex);
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecSetTransparentEnable (GIF_DECODER_HANDLE handle, kal_bool transparentEnable)
{
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetTransparentEnable() Enter. transparentEnable = %d\n", transparentEnable);
#ifdef GIF_PARAMETER_CHECK
   if (0 != _gif_dec_check_handle(handle))
   {
      return GIF_STATUS_INVALID_HANDLE;
   }
#endif

   handle->last_status = GIF_STATUS_OK;

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      handle->hw_config.transparent_enable = transparentEnable;
      if (handle->hw_config.transparent_enable)
      {
         handle->hw_config.trans_key_no_out_en = KAL_TRUE;
      }
      else
      {
         handle->hw_config.trans_key_no_out_en = KAL_FALSE;
      }
#else
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      handle->transparent_enable = transparentEnable;
      break;

   default:
      handle->last_status = GIF_STATUS_INVALID_OPERATION;
      break;
   }

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecSetTransparentEnable() Leave. \n");
   return handle->last_status;
}



GIF_STATUS_ENUM gifDecResetCache(GIF_DEC_TYPE_ENUM codecType)
{
   GIF_STATUS_ENUM rtn = GIF_STATUS_OK;
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecResetCache() Enter. codecType = %d\n", codecType);

   switch (codecType)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      //hw cache reset
      gif_reset_cache();
#else
      rtn = GIF_STATUS_DEC_NON_SUPPORT;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      //sw cache reset
      gif_sw_cache_reset();
      break;

   default:
      rtn = GIF_STATUS_INVALID_PARAMETER;
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecResetCache() Leave. \n");
   return rtn;
}



kal_bool gifDecIsCacheHit(STFSAL* pfsal, kal_uint32 x, kal_uint32 y, GIF_DEC_TYPE_ENUM codecType)
{
   kal_uint32 cache_id;
   kal_uint8 cache_work_buffer[GIF_SW_CACHE_WORK_BUFFER_SIZE];

   if (!pfsal)
   {
      return KAL_FALSE;
   }

   cache_id = _gif_get_cache_id(pfsal, (kal_uint32*)cache_work_buffer);
   if (!cache_id)
   {
      return KAL_FALSE;
   }

   //support sw only
   return _gif_sw_is_cache_hit(cache_id, x, y);
}



GIF_STATUS_ENUM gifDecResetCacheEntry(STFSAL* pfsal, GIF_DEC_TYPE_ENUM codecType)
{
   kal_uint32 cache_id;
   kal_uint8 cache_work_buffer[GIF_SW_CACHE_WORK_BUFFER_SIZE];

   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecResetCacheEntry() Enter. \n");

   if (!pfsal)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }

   cache_id = _gif_get_cache_id(pfsal, (kal_uint32*)cache_work_buffer);

   switch (codecType)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      gif_reset_cache_entry(cache_id);
      break;
#else
      return GIF_STATUS_DEC_NON_SUPPORT;
#endif

   case GIF_DEC_TYPE_SW:
      gif_sw_cache_reset_entry(cache_id);
      break;

   default:
      return GIF_STATUS_INVALID_PARAMETER;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecResetCacheEntry() Leave. \n");
   return GIF_STATUS_OK;
}



GIF_STATUS_ENUM gifDecGetFrameNumberDecoded(GIF_DECODER_HANDLE handle, kal_uint32* frameNumber)
{
   GIF_STATUS_ENUM rtn = GIF_STATUS_OK;
   //SW_GIF_TRACE(MOD_MMI, "[gif] - gifDecGetFrameNumberDecoded() Enter. \n");

   if (!frameNumber)
   {
      return GIF_STATUS_INVALID_PARAMETER;
   }

   switch (handle->codec_type)
   {
   case GIF_DEC_TYPE_HW:
#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
      *frameNumber = gif_dcb.cur_fn;
#else
      rtn = GIF_STATUS_DEC_NON_SUPPORT;
#endif
      break;

   case GIF_DEC_TYPE_SW:
      *frameNumber = handle->frame_number;
      break;

   default:
      rtn = GIF_STATUS_INVALID_PARAMETER;
      break;
   }

   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecGetFrameNumberDecoded() Enter. frameNumber = %d\n", *frameNumber);
   return rtn;
}



GIF_STATUS_ENUM gifDecSetDstBufferSwitchBehavior(GIF_DECODER_HANDLE handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
   handle->dst_buffer_cache_switch_behavior = behavior;
   return GIF_STATUS_OK;
}



GIF_STATUS_ENUM gifDecGetLastError(GIF_DECODER_HANDLE handle)
{
   SW_GIF_TRACE(GIF_TRACE_MOD, "[gif] - gifDecGetLastError() Enter. last_status = %x\n", handle->last_status);
   return handle->last_status;
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
GIF_STATUS_ENUM gifDecParseWholeFile(
  STFSAL* gif_fsal_handle,
  STFSAL* out_fsal_handle,
  kal_int32 *frame_count)
{
#if defined(SWGIF_VC_PROJ)
   gif_sw_parse_file(gif_fsal_handle, out_fsal_handle,frame_count);   
#else
   *frame_count = 0;
#endif //SWGIF_VC_PROJ
   return GIF_STATUS_OK;
}
