/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   jpeg_encode_int_hw.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_jpeg.h"

#if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)

#if defined(__DRV_GRAPHICS_JPEG_6268_SERIES__)
   #include "jpeg_drv_6268_series.h"
#elif defined(__DRV_GRAPHICS_JPEG_6236_SERIES__)
   #include "jpeg_drv_6236_series.h"
#elif defined(__DRV_GRAPHICS_JPEG_6276_SERIES__)
   #include "jpeg_drv_6276_series.h"
#elif defined(__DRV_GRAPHICS_JPEG_6256_SERIES__)
   #include "jpeg_drv_6256_series.h"
#elif defined(__DRV_GRAPHICS_JPEG_6255_SERIES__)
   #include "jpeg_drv_6255_series.h"
#elif defined(__DRV_GRAPHICS_JPEG_6250_SERIES__)
   #include "jpeg_drv_6250_series.h"
#else
   #error "Unsupported hw jpeg driver series"
#endif

#if defined(JPEG_CODEC_STANDALONE)

#else
   #include "kal_public_api.h"
#endif

#include "kal_general_types.h"
#include "string.h"

#include "swje_structure.h"
#include "jpeg_enum.h"
#include "jpeg_encode_structure.h"
#include "jpeg_encode_api.h"
#include "jpeg_misc_api.h"
#include "jpeg_encode_int.h"
#include "jpeg_mem_int.h"
#include "jpeg_marker.h"
#include "jpeg_drv_api.h"
#include "jpeg_enum_int.h"

#if defined(EXIF_SUPPORT)
   #include "exif_enc_enum.h"
   #include "exif_enc_structure.h"
   #include "exif_enc_api.h"
   #include "exif_enc_wrapper.h"
#endif  /// End of #if defined(EXIF_SUPPORT)


#if defined(__MTK_TARGET__)
   #include "idp_jpeg_encode.h"
   #include "img_common_enum.h"
   #define SLEEP(n)  kal_sleep_task(n)
#else
   #define SLEEP(n)  while (0) {}
#endif



static JPEG_ENCODER _jpeg_hw_encoder;


/// This function will be called by JPEG driver in JPEG encode HISR.
#if (!defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__))
static kal_int32 _jpeg_enc_hw_hisr_callback(JPEG_CODEC_STATE_ENUM state)
{
   SWJE_FILE *dstFile = &(_jpeg_hw_encoder.dstFile);

   _jpeg_hw_encoder.codecState = state;

   dstFile->dstFileSize += (kal_uint32)((kal_uint32)jpeg_drv_enc_get_current_dma_addr() -
                           (kal_uint32)dstFile->dstBufferAddr);

   /// We cannot close IDP in HISR since it uses semaphore...
   switch (state)
   {
      case JPEG_CODEC_STATE_COMPLETE:
         /// Leave the state as what it is.
         break;

      case JPEG_CODEC_STATE_PAUSED:
         /// We do not support HW encoder stall function currently.
         state = JPEG_CODEC_STATE_ERROR;
         _jpeg_hw_encoder.codecState = JPEG_CODEC_STATE_ERROR;
         _jpeg_hw_encoder.lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
         dstFile->dstFileSize = 0;
         break;

      case JPEG_CODEC_STATE_ABORT:
         ASSERT(0);
         break;

      default:
         ASSERT(0);
      return 0;
   }

   if (_jpeg_hw_encoder.callback_function)
   {
      return _jpeg_hw_encoder.callback_function(state);
   }
   else
   {
      return 1;
   }
}
#endif



#if defined(__JPEG_ENC_PATCH_FOR_HQA00000392__)
void jpeg_enc_patch_for_HQA00000392(kal_uint8 *jpeg_buffer_head, kal_uint8 *jpeg_buffer_tail)
{
   register kal_uint8 *current_byte = jpeg_buffer_head;

   /// Looking for SOI...
   while (1)
   {
      if (current_byte > jpeg_buffer_tail)
      {
         ASSERT(0);
      }

      /// Looking for the 0xFF pattern.
      while (JPEG_MARKER_START_CODE != *current_byte)
      {
         current_byte++;
      }

      /// Looking for the JPEG marker code.
      while (JPEG_MARKER_START_CODE == *current_byte)
      {
         current_byte++;
      }

      if (JPEG_MARKER_SOI == *current_byte)
      {
         current_byte++;
         break;
      }
   }

   /// Looking for SOS...
   while (1)
   {
      kal_uint32 length;

      if (current_byte > jpeg_buffer_tail)
      {
         ASSERT(0);
      }

      /// Looking for the 0xFF pattern.
      while (JPEG_MARKER_START_CODE != *current_byte)
      {
         current_byte++;
      }

      /// Looking for the JPEG marker code.
      while (JPEG_MARKER_START_CODE == *current_byte)
      {
         current_byte++;
      }

      if (JPEG_MARKER_SOS != *current_byte)
      {
         length = *(current_byte + 1);
         length <<= 8;
         length |= *(current_byte + 2);
         current_byte += (length + 1);
      }
      else
      {
         break;
      }
   }

   /// Found SOS, looking for Se
   {
      kal_uint32 Ns;

      current_byte += 3;         /// Skip Ls
      Ns = *current_byte;        /// Read Ns
      current_byte += 1;
      current_byte += (Ns * 2);  /// Skip the Csj, Tdj and Taj
      current_byte += 1;         /// Skip the Ss

      if (0x3F != *current_byte)
      {
         *current_byte = 0x3F;
      }
   }
}
#endif



#if defined(EXIF_SUPPORT)
static kal_uint32 _jpeg_enc_align_for_app(kal_uint8 *app_length_ptr, kal_uint8 *dst_buffer_addr, kal_uint32 dst_buffer_used, kal_uint32 alignment_val)
{
   kal_uint32 app_length;
   kal_uint32 app_aligned_length;
   kal_uint8 *alignment_temp_ptr;
    
   app_length = ((*app_length_ptr) << 8) | *(app_length_ptr + 1);
   app_aligned_length = alignment_val - (dst_buffer_used % alignment_val);
   app_length += app_aligned_length;

   *app_length_ptr = (app_length >> 8) & 0xFF;
   *(app_length_ptr + 1) = (app_length) & 0xFF;

   alignment_temp_ptr = (kal_uint8 *)((kal_uint32)dst_buffer_addr + dst_buffer_used);

   memset(alignment_temp_ptr, 0, app_aligned_length);

   return app_aligned_length;
}
#endif



void jpeg_enc_hw_get_handle(JPEG_ENCODER_HANDLE *handle)
{
   *handle = &_jpeg_hw_encoder;
}


void jpeg_enc_hw_return_cur_handle(JPEG_ENCODER **handle)
{
   *handle = &_jpeg_hw_encoder;
}


kal_bool idp_jpeg_encode_open_wrapper(kal_uint32 *key)
{
#if defined(__MTK_TARGET__) && (!defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__))
   /// Notice: idp_jpeg_encode_open is a macro.
   return idp_jpeg_encode_open(key);
#else
	 return KAL_TRUE;
#endif
}



/// Config the idp jpeg encode path (encode from RGB/YUV buffer).
kal_bool idp_jpeg_encode_config_wrapper(void *encHandle)
{
   JPEG_ENCODER_HANDLE handle = (JPEG_ENCODER_HANDLE)encHandle;
   kal_bool idp_config_result = KAL_TRUE;
   JPEG_ENCODE_INFO* const mainEncodeInfo = &(handle->mainEncodeInfo);
#if 0
/* under construction !*/
#endif

#if defined(__MTK_TARGET__) && (!defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__))

   kal_uint32 src_color_format = 0;
   kal_uint8 *src_buffer_addr[3] = {NULL, NULL, NULL};
   kal_uint8 src_clip_enable = 0;

   if ((0 != handle->srcWindow.w * handle->srcWindow.h)
      && ((handle->srcWidth != handle->srcWindow.w) || (handle->srcHeight != handle->srcWindow.h))
      )
   {
      src_clip_enable = 1;
   }

   if (JPEG_ENCODE_SOURCE_RGB_BUFFER == handle->srcMode)
   {
      src_color_format = _jpeg_get_idp_rgb_format_enum(handle->srcRGBFormat);
      src_buffer_addr[0] = (kal_uint8 *)handle->srcRGBBuffer;
   }
   else if (JPEG_ENCODE_SOURCE_YUV_BUFFER == handle->srcMode)
   {
      src_color_format = _jpeg_get_idp_yuv_format_enum(handle->srcSamplingFormat);
      src_buffer_addr[0] = (kal_uint8 *)handle->srcYUVBuffer[0];
      src_buffer_addr[1] = (kal_uint8 *)handle->srcYUVBuffer[1];
      src_buffer_addr[2] = (kal_uint8 *)handle->srcYUVBuffer[2];
   }
   else
   {
      ASSERT(0);
   }

   idp_config_result &= idp_jpeg_encode_config(handle->idpKey,
                              IDP_JPEG_ENCODE_INTMEM_START_ADDRESS, handle->idpIntMemoryAddr,
                              IDP_JPEG_ENCODE_INTMEM_SIZE, handle->idpIntMemorySize,
                              IDP_JPEG_ENCODE_EXTMEM_START_ADDRESS, handle->idpExtMemoryAddr,
                              IDP_JPEG_ENCODE_EXTMEM_SIZE, handle->idpExtMemorySize,

                              IDP_JPEG_ENCODE_COLOR_FMT, src_color_format,
                              IDP_JPEG_ENCODE_IMAGE_BUFFER_ADDRESS, src_buffer_addr[0],
                              IDP_JPEG_ENCODE_IMAGE_UBUFFER_ADDRESS, src_buffer_addr[1],
                              IDP_JPEG_ENCODE_IMAGE_VBUFFER_ADDRESS, src_buffer_addr[2],

                              IDP_JPEG_ENCODE_IMAGE_WIDTH, handle->srcWidth,
                              IDP_JPEG_ENCODE_IMAGE_HEIGHT, handle->srcHeight,

                              IDP_JPEG_ENCODE_ENABLE_JPEG_ENCODE, 1,
                              IDP_JPEG_ENCODE_TARGET_WIDTH, mainEncodeInfo->dstWidth,
                              IDP_JPEG_ENCODE_TARGET_HEIGHT, mainEncodeInfo->dstHeight,

                              IDP_JPEG_ENCODE_JPEG_YUV_MODE, _jpeg_get_idp_yuv_format_enum(handle->dstSamplingFormat),

                              IDP_JPEG_ENCODE_ENABLE_THUMBNAIL, 0,
                              IDP_JPEG_ENCODE_ENABLE_OVERLAY, 0,

                              IDP_JPEG_ENCODE_JPEG_ENCODE_CB, 0,
                              IDP_JPEG_ENCODE_JPEG_ENCODE_CB_PARAM, 0,

                              IDP_JPEG_ENCODE_ENABLE_SOURCE_CLIP, src_clip_enable,
                              IDP_JPEG_ENCODE_SOURCE_CLIP_LEFT, handle->srcWindow.x,
                              IDP_JPEG_ENCODE_SOURCE_CLIP_RIGHT, handle->srcWindow.x + handle->srcWindow.w - 1,
                              IDP_JPEG_ENCODE_SOURCE_CLIP_TOP, handle->srcWindow.y,
                              IDP_JPEG_ENCODE_SOURCE_CLIP_BOTTOM, handle->srcWindow.y + handle->srcWindow.h - 1,

                              0);

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
#endif

/*
   /// All overlay API has been removed.
   if (handle->ovlBufferAddr)
   {
      /// Config for overlay.
      idp_config_result &= idp_jpeg_encode_config(handle->idpKey,
                                 IDP_JPEG_ENCODE_ENABLE_OVERLAY, 1,
                                 IDP_JPEG_ENCODE_OVERLAY_PALETTE_MODE, handle->ovlBufferPaletteDepth,
                                 IDP_JPEG_ENCODE_OVERLAY_FRAME_SOURCE_KEY, handle->ovlSourceKey,
                                 IDP_JPEG_ENCODE_OVERLAY_FRAME_WIDTH, handle->ovlBufferWidth,
                                 IDP_JPEG_ENCODE_OVERLAY_FRAME_HEIGHT, handle->ovlBufferHeight,
                                 IDP_JPEG_ENCODE_OVERLAY_FRAME_BUFFER_ADDRESS, handle->ovlBufferAddr,
                                 0);
   }
*/
   if (!idp_config_result)
   {
      /// IDP error, return error.
      idp_jpeg_encode_error_code_t idp_error_code;

      idp_jpeg_encode_query(handle->idpKey, IDP_JPEG_ENCODE_QUERY_ERROR_CODE, &idp_error_code, 0);

      switch (idp_error_code)
      {
      case IDP_JPEG_ENCODE_ERROR_CODE_NOT_ENOUGH_WORKING_MEM:
         handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
         break;
      default:
         handle->lastStatus = JPEG_STATUS_IDP_ERROR;
      }

      if (!idp_jpeg_encode_close(handle->idpKey))
      {
         ASSERT(0);
      }
      handle->idpKey = 0;

      return KAL_FALSE;
   }
#endif /// __MTK_TARGET__

   return KAL_TRUE;
}



/// In the camera capture to JPEG path, the IDP is controlled outside JPEG,
/// thus we provide dummy functions for the use of IDP control function pointers.
kal_bool idp_dummy_open(kal_uint32 *key)
{
   *key = 1;
   return KAL_TRUE;
}



kal_bool idp_dummy_others(kal_uint32 key)
{
   return KAL_TRUE;
}



kal_bool idp_dummy_config(void *handle)
{
   return KAL_TRUE;
}



JPEG_STATUS_ENUM jpeg_enc_hw_internal(JPEG_ENCODER_HANDLE handle)
{
   SWJE_FILE *dstFile = &(handle->dstFile);
   JPEG_ENCODE_INFO* const mainEncodeInfo = &(handle->mainEncodeInfo);

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif
   
   /// Set destination buffer address for 8-bytes alignment.
   if (0 != ((kal_uint32)dstFile->dstBufferAddr & 7))
   {
      dstFile->dstBufferSize -= (8 - ((kal_uint32)dstFile->dstBufferAddr & 7));
      dstFile->dstBufferLeft -= (8 - ((kal_uint32)dstFile->dstBufferAddr & 7));
      dstFile->dstBufferAddr = (void *)(((kal_uint32)dstFile->dstBufferAddr + 7) & 0xFFFFFFF8);
      dstFile->dstWritePtr = (kal_uint8 *)dstFile->dstBufferAddr;
   }

#if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)
   handle->curEncodeInfo = &(handle->mainEncodeInfo);
   if (JPEG_STATUS_OK != jpeg_enc_sw_init_gereral(handle))
   {
      handle->codecState = JPEG_CODEC_STATE_ERROR;
      return handle->lastStatus;
   }
#else
   if((KAL_TRUE == handle->enableThumbnail) 
      #if defined(EXIF_SUPPORT)
         || (JPEG_FILE_FORMAT_EXIF & handle->dstFileFormat) 
      #endif
   )
#endif
   {
     *((kal_uint8 *)(dstFile->dstBufferAddr)) = 0xFF;
      *((kal_uint8 *)(dstFile->dstBufferAddr) + 1) = 0xD8;
      dstFile->dstBufferLeft -= 2;
      dstFile->dstWritePtr += 2;
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
#endif

   #if defined(EXIF_SUPPORT)
      if (JPEG_FILE_FORMAT_EXIF & handle->dstFileFormat)
      {
         EXIF_DATA *exif_data;
         kal_uint8 *app_length_ptr = NULL;
         kal_uint32 exif_data_size = 0, tmp_size = 0;

         /// Create exif data structure and convert legacy IFD to exif v2.
         exifCreateDataStructure(&exif_data, (void *)handle->exifWorkingBuffer, JPEG_SW_ENC_EXIF_EXT_MAX_MEM_SIZE);
         exifWrapperConvertAllLegacyIFD(exif_data);

         /// Config exif v2 encoder settings.
         exifSetDstBuffer(exif_data, (kal_uint8 *)dstFile->dstBufferAddr + (dstFile->dstBufferSize - dstFile->dstBufferLeft), 10240);
         exif_data->byte_order = EXIF_BYTE_ORDER_LITTLE_ENDIAN;
         exif_data->thumbnail_size = 0;

         /// Store app length pointer for alignment.
         app_length_ptr = (kal_uint8 *)((kal_uint32)dstFile->dstBufferAddr + dstFile->dstBufferSize - dstFile->dstBufferLeft + 2);

         /// Start exif v2 encoder.
         exifSaveEncodedData(exif_data);

         tmp_size = exifGetTotalEncodedDataLength(exif_data);
         dstFile->dstBufferLeft -= tmp_size;
         exif_data_size += tmp_size;
         
         /// Alignment for current app.
         tmp_size = _jpeg_enc_align_for_app(app_length_ptr, (kal_uint8 *)dstFile->dstBufferAddr, dstFile->dstBufferSize - dstFile->dstBufferLeft, 8);
         dstFile->dstBufferLeft -= tmp_size;
         exif_data_size += tmp_size;

         dstFile->dstBufferLeft -= exif_data_size;
         dstFile->dstWritePtr += exif_data_size;

         /// Release exif data structure.
         exifReleaseDataStructure(exif_data);
      }
   #else
      /// Disable EXIF if the EXIF_SUPPORT option is not enabled.
      if (JPEG_FILE_FORMAT_EXIF & handle->dstFileFormat)
      {
         handle->dstFileFormat &= (~JPEG_FILE_FORMAT_EXIF);
      }
   #endif

   /// Config HW JPEG encoder...
   #if defined(__MTK_TARGET__)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__) || defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
      {
         /// write frame header
         if (JPEG_STATUS_OK != jpeg_enc_sw_write_frame_header(handle))
         {
            handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
            return handle->lastStatus;
         }
      
         /// write scan header
         if (JPEG_STATUS_OK != jpeg_enc_sw_write_scan_header(handle))
         {
            handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
            return handle->lastStatus;
         }
      }
      #else
      {
         if (handle->idpKey)
         {
            ASSERT(0);
         }
   
         if (!handle->idp_open_func(&handle->idpKey))
         {
            /*
            /// Leave this operation to jpegEncReleaseEncoder.
            if (!drv_gfx_close_dct(DCT_USER_JPEG_ENCODER))
            {
               ASSERT(0);
            }
            */
   
            /// The IDP is unavailable, return error.
            handle->lastStatus = JPEG_STATUS_ENC_ERROR_IDP_UNAVAILABLE;
            handle->idpKey = 0;
            return handle->lastStatus;
         }
      }
      #endif
   }
   #endif

   /// 0. Power JPEG encoder
   jpeg_drv_enc_power_on();

   jpeg_drv_enc_reset();

   /// 1. Set up callback function
#if (!defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__))
   jpeg_isr_set_enc_callback(_jpeg_enc_hw_hisr_callback);
#endif
   jpeg_isr_set_enc_check_abort(handle->check_abort_func);

   /// 2. Set up destination file buffer information
   if (0 == handle->stallOffset ||
       handle->stallOffset > (dstFile->dstBufferLeft))
   {
      handle->stallOffset = dstFile->dstBufferLeft;
   }
   jpeg_drv_enc_set_dst_buffer_info(dstFile->dstWritePtr, handle->stallOffset);

   /// 3. Set up destination file format (pure JPEG or JFIF)
   jpeg_drv_enc_set_file_format(handle->dstFileFormat);

   /// 4. Set up the output quality
   switch (handle->dstQuality)
   {
      case JPEG_ENCODE_QUALITY_EXCELLENT:
         jpeg_drv_enc_set_quality(JPEG_DRV_ENC_QUALITY_EXCELLENT);
      break;
      case JPEG_ENCODE_QUALITY_GOOD:
         jpeg_drv_enc_set_quality(JPEG_DRV_ENC_QUALITY_GOOD);
      break;
      case JPEG_ENCODE_QUALITY_FAIR:
         jpeg_drv_enc_set_quality(JPEG_DRV_ENC_QUALITY_FAIR);
      break;
      case JPEG_ENCODE_QUALITY_LOW:
         jpeg_drv_enc_set_quality(JPEG_DRV_ENC_QUALITY_LOW);
      break;
      case JPEG_ENCODE_QUALITY_POOR:
         jpeg_drv_enc_set_quality(JPEG_DRV_ENC_QUALITY_POOR);
      break;
      default:
         ASSERT(0);
      break;
   }

   #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)
      ASSERT(mainEncodeInfo->dstWidth == handle->srcWidth);
      ASSERT(mainEncodeInfo->dstHeight == handle->srcHeight);
   #endif

   /// 5. Set up the output YUV sampling format
   jpeg_drv_enc_set_sample_format_related(mainEncodeInfo->dstWidth, mainEncodeInfo->dstHeight, handle->dstSamplingFormat);

   /// 6. Config image data path (if necessary) and trigger JPEG encoder
   #if defined(__MTK_TARGET__)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__) || defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
         jpeg_drv_enc_set_src_addr((kal_uint32)handle->srcYUVBuffer[0], (kal_uint32)handle->srcYUVBuffer[1], 
                                                        (kal_uint32)handle->srcYUVBuffer[2], handle->srcSamplingFormat);
      #else
         if (!handle->idp_config_func(handle))
         {
            return handle->lastStatus;
         }
   
         #if defined(DRV_IDP_6238_SERIES)
            /// Special control sequence for MT6238 series.
            handle->idp_start_output_func(handle->idpKey);
         #endif
      #endif

      /// Trigger the JPEG encoder...
      handle->codecState = JPEG_CODEC_STATE_BUSY;
      jpeg_drv_enc_start();

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif

      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__) || defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
      {
          kal_uint32 jpeg_enc_irq_status;
          kal_uint32 jpeg_enc_check_abort = 0;
          kal_uint32 abortCheckInterval = 0xFF;
          SWJE_FILE *dstFile = &(handle->dstFile);
       
          // busy waiting
          jpeg_drv_enc_get_irq_status(&jpeg_enc_irq_status);
          
          while (0 == jpeg_enc_irq_status)
          {
             /// Check abort function
             abortCheckInterval--;
             if (0 == abortCheckInterval)
             {
                jpeg_enc_check_abort = 1;
                break;
             }
             SLEEP(1);
             jpeg_drv_enc_get_irq_status(&jpeg_enc_irq_status);
          }
       
#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif

          jpeg_drv_enc_get_irq_status(&jpeg_enc_irq_status);
       
          /// clear up the interrupt status register
          jpeg_drv_enc_clear_irq_status();

          dstFile->dstFileSize += (kal_uint32)((kal_uint32)jpeg_drv_enc_get_current_dma_addr() -
                                  (kal_uint32)dstFile->dstBufferAddr);
          dstFile->dstBufferLeft -= dstFile->dstFileSize;

          /// update codec state       
          if (jpeg_enc_check_abort)
          {
             if (handle->check_abort_func)
             {
                if (!(handle->check_abort_func()))
                {
                   handle->codecState = JPEG_CODEC_STATE_ABORT;
                   handle->lastStatus = JPEG_STATUS_ENC_ABORT;
                }
             }
          }
          else
          {
             if (jpeg_enc_irq_status & JPEG_DRV_ENC_INT_STATUS_DONE)
             {
                handle->codecState = JPEG_CODEC_STATE_COMPLETE;
                handle->lastStatus = JPEG_STATUS_OK;
             }
             else if (jpeg_enc_irq_status & JPEG_DRV_ENC_INT_STATUS_BIT_FULL)
             {
                handle->codecState = JPEG_CODEC_STATE_ERROR;
                handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
             }
             else
             {
                ASSERT(0);
             }
          }

          /// check callback function
          if (handle->callback_function)
          {
             handle->callback_function(handle->codecState);
          }
      }
      #else
         handle->idp_start_all_func(handle->idpKey);
         handle->lastStatus = JPEG_STATUS_OK;
      #endif
   }
   #else
      handle->lastStatus = JPEG_STATUS_OK;
   #endif /// __MTK_TARGET__

#if defined(__JPEG_ENC_PATCH_FOR_HQA00011180__)
   {
      kal_uint32 byteOffset = 0;
      kal_uint8* tmp;

      // fix last loss 0xD9 byte hw error      
      jpeg_drv_enc_get_byte_offset(&byteOffset);
      tmp = (kal_uint8*)((kal_uint32)dstFile->dstBufferAddr + dstFile->dstFileSize - byteOffset - 2);

      *tmp = 0xFF;
      *(tmp + 1) = 0xD9;
   }
#endif

   return handle->lastStatus;
}

#endif /// __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
