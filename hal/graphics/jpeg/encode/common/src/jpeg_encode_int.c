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
 *   jpeg_encode_int.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"

#include "string.h"

#include "drv_features_jpeg.h"
#include "jpeg_enum.h"
#include "jpeg_enum_int.h"
#include "jpeg_drv_api.h"
#include "jpeg_mem_int.h"
#include "jpeg_encode_structure.h"
#include "jpeg_encode_int.h"

#include "swje_structure.h"
#include "swje_const_tables.h"

#include "iul_x_math.h"

#include "simple_memory_manager.h"

#if defined(JPEG_CODEC_STANDALONE)
   #include <assert.h>
   #if !defined(ASSERT)
      #define ASSERT assert
   #endif
#else
   #include "kal_public_api.h"
   #include "idp_mem_def.h"
   #include "cache_sw.h"
#endif


#if defined(__MTK_TARGET__)
   #include "idp_core.h"
   #include "idp_jpeg_encode.h"
   #include "idp_camera_capture_to_jpeg.h"
   #include "drv_gfx_dct_control.h"

   #include "mm_intmem.h"

   #define malloc get_ctrl_buffer      ///< for SW encoder.
   #define free   free_ctrl_buffer     ///< for SW encoder.

   #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
      static kal_bool _hw_jpeg_encoder_in_use = KAL_FALSE;
      static kal_mutexid jpeg_encoder_state_mutex = NULL;
   #endif
#endif

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
   #include "drv_gfx_dynamic_switch.h"
#endif



static void _jpeg_enc_update_quick_view_image_info(kal_uint8 *qvimg_info_ptr, JPEG_QUICK_VIEW_IMAGE_INFO *qvimg_info)
{
    *qvimg_info_ptr++ = 'Q';
    *qvimg_info_ptr++ = 'V';
    *qvimg_info_ptr++ = 'I';
    *qvimg_info_ptr++ = 0x00;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_width >> 8) & 0xFF;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_width & 0xFF);
    *qvimg_info_ptr++ = (qvimg_info->qvimg_height >> 8) & 0xFF;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_height & 0xFF);
    *qvimg_info_ptr++ = (qvimg_info->qvimg_offset >> 24) & 0xFF;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_offset >> 16) & 0xFF;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_offset >> 8) & 0xFF;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_offset) & 0xFF;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_size >> 24) & 0xFF;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_size >> 16) & 0xFF;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_size >> 8) & 0xFF;
    *qvimg_info_ptr++ = (qvimg_info->qvimg_size) & 0xFF;
}


void jpeg_enc_update_app_nine_content(JPEG_APP_NINE_INFO_TYPE_ENUM app_nine_info_type, kal_uint8 *app_nine_ptr, void *app_nine_info)
{
    if (NULL == app_nine_info)
    {
        ASSERT(0);
    }

    /// Write APP9 marker and length.
    *app_nine_ptr++ = 0xFF;
    *app_nine_ptr++ = 0xE9;
    *app_nine_ptr++ = (APP_NINE_LENGTH >> 8);
    *app_nine_ptr++ = (APP_NINE_LENGTH & 0xff);
    *app_nine_ptr++ = 'M';
    *app_nine_ptr++ = 'T';
    *app_nine_ptr++ = 'K';
    *app_nine_ptr++ = 0x00;

    switch (app_nine_info_type)
    {
        case JPEG_APP_NINE_QUICK_VIEW_IMAGE_INFO:
            _jpeg_enc_update_quick_view_image_info(app_nine_ptr, (JPEG_QUICK_VIEW_IMAGE_INFO *)app_nine_info);
            break;

        case JPEG_APP_NINE_HINT_INFO:
            break;

        case JPEG_APP_NINE_NONE:
            break;

        default:
            break;
    }
}


kal_int32 jpeg_enc_check_handle(JPEG_ENCODER_HANDLE handle)
{
   if (!handle)
   {
      return -1;
   }

   #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__) && (!defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__))
      if (JPEG_CODEC_TYPE_HW == handle->codecType)
      {
         JPEG_ENCODER *hwHandle;

         jpeg_enc_hw_return_cur_handle(&hwHandle);
         if(handle != hwHandle)
         {
            return -2;
         }
      }
   #endif
   return 0;
}



kal_uint32 jpeg_enc_jfxx_write_header_3bpp_tn(kal_uint8 *jpegFilePtr, kal_uint32 tnWidth, kal_uint32 tnHeight, void **tnPtr)
{
   kal_uint32 jfxx_header_length = tnWidth * tnHeight * 3 + 10;
   kal_uint8 *ptr = (kal_uint8 *)jpegFilePtr;

   if (tnWidth > 255 || tnHeight > 255 || jfxx_header_length > JPEG_THUMBNAIL_3BPP_MAX_SIZE)
   {
      ASSERT(0);
   }

   /// Write SOI header.
   ///*ptr++ = 0xFF;
   ///*ptr++ = 0xD8;

   /// Write APP0 header.
   *ptr++ = 0xFF;
   *ptr++ = 0xE0;

   /// 10 bytes...
   *ptr++ = (jfxx_header_length >> 8) & 0xFF;
   *ptr++ =  jfxx_header_length & 0xFF;

   *ptr++ = 'J';
   *ptr++ = 'F';
   *ptr++ = 'X';
   *ptr++ = 'X';
   *ptr++ = 0;
   *ptr++ = 0x13; /// Extension code
   *ptr++ = tnWidth;
   *ptr++ = tnHeight;

   *tnPtr = (void *)ptr;

   return (jfxx_header_length + 2);
}



void jpeg_enc_jfxx_get_total_size(JPEG_ENCODER_HANDLE handle, kal_uint32* size)
{
   *size = 10;
}



#define SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE  4
JPEG_STATUS_ENUM jpeg_enc_query_working_memory(JPEG_ENCODER_HANDLE handle)
{
   kal_uint32 extRequiredSize = 0;
   kal_uint32 intRequiredSize = 0;
   kal_uint32 extAdditionalSize = 0;

   #if defined(EXIF_SUPPORT)
      if(JPEG_FILE_FORMAT_EXIF == handle->dstFileFormat)
      {
         extRequiredSize += (JPEG_SW_ENC_EXIF_EXT_MAX_MEM_SIZE + 3) & 0xFFFFFFFC;
      }
   #endif

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__))
         case JPEG_CODEC_TYPE_HW:
         {
            kal_uint32 int_size = 0;
            kal_uint32 ext_size = 0;
            kal_uint32 srcWidthPadded = (handle->srcWidth + 15) & (~15);

            jpeg_drv_enc_query_required_memory(&int_size, &ext_size);
            intRequiredSize += int_size;
            extRequiredSize += ext_size;

            #if defined(__MTK_TARGET__)
            {
               /// Query memory needed by IDP.
               switch (handle->srcMode)
               {
                  case JPEG_ENCODE_SOURCE_ISP:
                     /// In this case, the memory required by IDP is controlled outside JPEG
                  break;

                  case JPEG_ENCODE_SOURCE_RGB_BUFFER:
                     handle->idpIntMemorySize = 0;
                     handle->idpExtMemorySize = IDP_MEM_CONSUME_JPEG_ENCODE_CALC_EXTMEM(srcWidthPadded);
                     intRequiredSize += 0;
                     extRequiredSize += IDP_MEM_CONSUME_JPEG_ENCODE_CALC_EXTMEM(srcWidthPadded);
                  break;

                  case JPEG_ENCODE_SOURCE_YUV_BUFFER:
                     if (JPEG_YUV_FORMAT_YUV420 == handle->srcSamplingFormat)
                     {
                        handle->idpIntMemorySize = 0;
                        handle->idpExtMemorySize = IDP_MEM_CONSUME_JPEG_ENCODE_CALC_YUV420_EXTMEM(srcWidthPadded);
                        intRequiredSize += 0;
                        extRequiredSize += IDP_MEM_CONSUME_JPEG_ENCODE_CALC_YUV420_EXTMEM(srcWidthPadded);
                     }
                     else
                     {
                        handle->idpIntMemorySize = 0;
                        handle->idpExtMemorySize = IDP_MEM_CONSUME_JPEG_ENCODE_CALC_EXTMEM(srcWidthPadded);
                        intRequiredSize += 0;
                        extRequiredSize += IDP_MEM_CONSUME_JPEG_ENCODE_CALC_EXTMEM(srcWidthPadded);
                     }
                  break;

                  default:
                     ASSERT(0);
                  break;
               }
            }
            #else
            {
               handle->idpIntMemorySize = 0;
               handle->idpExtMemorySize = 0;
            }
            #endif /// __MTK_TARGET__

            handle->intMemorySizeMinimum = intRequiredSize;
            handle->extMemorySizeMinimum = extRequiredSize;
            handle->intMemorySizeBest = intRequiredSize;
            handle->extMemorySizeBest = extRequiredSize + extAdditionalSize;
         }
         break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #if defined(__SW_JPEG_ENCODER_SUPPORT__)
         case JPEG_CODEC_TYPE_SW:
         {
            JPEG_ENCODE_INFO * const mainEncodeInfo = &(handle->mainEncodeInfo);
            JPEG_GENGERAL_ENCODE_INFO* const gengralEncodeInfo = &(handle->gengralEncodeInfo);
            kal_bool onlySupportMCURowBase = KAL_FALSE;

            #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
               intRequiredSize += (sizeof(SWJE_FRAGMENT_PROCESSOR) + 3) & 0xFFFFFFFC;
               intRequiredSize += ((sizeof(SWJE_FDCT_QUANT_UNIT) * 3) + 3) & 0xFFFFFFFC;
               intRequiredSize += (sizeof(SWJE_HUFFMAN_ENCODER) + 3) & 0xFFFFFFFC;
            #else
               extRequiredSize += (sizeof(SWJE_FRAGMENT_PROCESSOR) + 3) & 0xFFFFFFFC;
               extRequiredSize += ((sizeof(SWJE_FDCT_QUANT_UNIT) * 3) + 3) & 0xFFFFFFFC;
               extRequiredSize += (sizeof(SWJE_HUFFMAN_ENCODER) + 3) & 0xFFFFFFFC;
            #endif

            #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
               /// For huffman table
               intRequiredSize += ((SWJE_HUFF_DC_BITS_BITS + 3) & 0xFFFFFFFC) * 2;
               intRequiredSize += ((SWJE_HUFF_DC_VAL_BITS + 3) & 0xFFFFFFFC) * 2;
               intRequiredSize += ((SWJE_HUFF_DC_TRANSLATION_BITS * 2 + 3) & 0xFFFFFFFC) * 2;
               intRequiredSize += ((SWJE_HUFF_DC_TRANSLATION_BITS + 3) & 0xFFFFFFFC) * 2;

               intRequiredSize += ((SWJE_HUFF_AC_BITS_BITS + 3) & 0xFFFFFFFC) * 2;
               intRequiredSize += ((SWJE_HUFF_AC_VAL_BITS + 3) & 0xFFFFFFFC) * 2;
               intRequiredSize += ((SWJE_HUFF_AC_TRANSLATION_BITS * 2 + 3) & 0xFFFFFFFC) * 2;
               intRequiredSize += ((SWJE_HUFF_AC_TRANSLATION_BITS + 3) & 0xFFFFFFFC) * 2;
            #endif

            #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
               /// Quantity table(handle->pQuantTables) => 2 tables, 128 * 2. 1 for luminance, and the other for chrominance.
               intRequiredSize += 128 + 128 + 256 + 256;
               /// Z-Zag table
               intRequiredSize += 64* 4;
               /// handle->pWorkingBuffer
               /// Temp buffer for store FDCT, Quantize table and Huffman
               intRequiredSize += (64 * 4) + (64 * 4);
            #else
               /// Quantity table(handle->pQuantTables) => 2 tables, 128 * 2. 1 for luminance, and the other for chrominance.
               extRequiredSize += 128 + 128 + 256 + 256;
               /// handle->pWorkingBuffer
               /// Temp buffer for store FDCT, Quantize table and Huffman
               extRequiredSize += (64 * 4) + (64 * 4);
            #endif


            /// RGB-> YUV working buufer for color translation
            if(JPEG_ENCODE_SOURCE_RGB_BUFFER == handle->srcMode)
            {
               kal_int32 i = gengralEncodeInfo->numComponent;
               kal_uint32 minMemorySize = 0;
               kal_uint32 dstTotalMcuPerRow;

               #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER) || defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                  kal_uint32 bpp = 0;
               #endif

               while (--i >= 0)
               {
                  minMemorySize += (((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6);
               }

               #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER) || defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                  switch(handle->srcRGBFormat)
                  {
                     case JPEG_RGB_FORMAT_RGB565:
                        bpp = 2;
                     break;
                     case JPEG_RGB_FORMAT_RGB888:
                     case JPEG_RGB_FORMAT_BGR888:
                        bpp = 3;
                     break;
                     default:
                        ASSERT(0);
                     break;
                  }
               #endif

               #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER)
               {
                  if(!(((0x00010000 == (mainEncodeInfo->srcStepX)) && (0x00010000 == (mainEncodeInfo->srcStepY)))))
                  {
                     minMemorySize += (((gengralEncodeInfo->hSamplingFactorMax) * (gengralEncodeInfo->vSamplingFactorMax)) << 6) * bpp;

                     #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                        if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                        {
                           onlySupportMCURowBase = KAL_TRUE;
                        }
                     #endif
                  }

                  #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                     if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                     {
                        minMemorySize += (((
                                         ((gengralEncodeInfo->hSamplingFactorMax * IUL_X_TO_I_CARRY(mainEncodeInfo->srcStepX)) + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE) *
                                         ((gengralEncodeInfo->vSamplingFactorMax * IUL_X_TO_I_CARRY(mainEncodeInfo->srcStepY)) + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE)
                                         ) << 6) * bpp + 3) & 0xFFFFFFFC;
                     }
                  #endif

                  dstTotalMcuPerRow = ((mainEncodeInfo->dstWidth) + (gengralEncodeInfo->hSamplingFactorMax << 3) - 1) /
                                       (gengralEncodeInfo->hSamplingFactorMax << 3);

                  extAdditionalSize = (dstTotalMcuPerRow * minMemorySize + 3) & 0xFFFFFFFC;
               }
               #else
                  ASSERT((0x00010000 == (mainEncodeInfo->srcStepX)) && (0x00010000 == (mainEncodeInfo->srcStepY)));

                  #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                     if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                     {
                        minMemorySize += (((
                                         (gengralEncodeInfo->hSamplingFactorMax + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE) *
                                         (gengralEncodeInfo->vSamplingFactorMax + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE)
                                         ) << 6) * bpp + 3) & 0xFFFFFFFC;
                     }
                  #endif

                  dstTotalMcuPerRow = ((mainEncodeInfo->dstWidth) + (gengralEncodeInfo->hSamplingFactorMax << 3) - 1) /
                                       (gengralEncodeInfo->hSamplingFactorMax << 3);

                  extAdditionalSize = (dstTotalMcuPerRow * minMemorySize + 3) & 0xFFFFFFFC;
               #endif

               extRequiredSize += minMemorySize;
            }
            else
            {
               {
                  kal_uint32 minMemorySize = 0;
                  kal_uint32 dstTotalMcuPerRow;

                  #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                     if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                     {
                        kal_int32 i = gengralEncodeInfo->numComponent;

                        while (--i >= 0)
                        {
                           minMemorySize += (((
                                            ((gengralEncodeInfo->hSamplingFactor[i] * IUL_X_TO_I_CARRY(mainEncodeInfo->srcStepX)) + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE) *
                                            ((gengralEncodeInfo->vSamplingFactor[i] * IUL_X_TO_I_CARRY(mainEncodeInfo->srcStepY)) + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE)
                                            ) << 6) + 3) & 0xFFFFFFFC;
                        }
                     }
                  #endif

                  #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER)
                     /// due to (handle->dstWidth == handle->srcWidth) and (handle->dstHeight == handle->srcHeight), We only need to consider dst
                     if(!(((0x00010000 == (mainEncodeInfo->srcStepX)) && (0x00010000 == (mainEncodeInfo->srcStepY)))))
                     {
                        kal_int32 i = gengralEncodeInfo->numComponent;

                        while (--i >= 0)
                        {
                           minMemorySize += ((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6 ;
                        }

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                           {
                              onlySupportMCURowBase = KAL_TRUE;
                           }
                        #endif
                     }
                  #endif
                  #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY)
                     #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER)
                        else
                     #endif
                     if (JPEG_YUV_FORMAT_PACKED_UYVY422 == handle->srcSamplingFormat)
                     {
                        kal_int32 i = gengralEncodeInfo->numComponent;

                        while (--i >= 0)
                        {
                           extRequiredSize += (((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6);
                        }
                     }
                  #endif
                  #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER) || defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY)
                     else
                  #endif
                  {
                     if (!((0 == ((mainEncodeInfo->dstWidth) % (mainEncodeInfo->dstMcuWidth))) && (0 == ((mainEncodeInfo->dstHeight) % (mainEncodeInfo->dstMcuHeight)))))
                     {
                        kal_int32 i = gengralEncodeInfo->numComponent;
                        kal_uint32 padMem = 0;

                        while (--i >= 0)
                        {
                           padMem += ((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6 ;
                        }

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                           {
                              minMemorySize += padMem;
                           }
                           else
                        #endif
                        {
                           extRequiredSize += padMem;
                        }
                     }
                  }

                  extRequiredSize += minMemorySize;
                  dstTotalMcuPerRow = ((mainEncodeInfo->dstWidth) + (gengralEncodeInfo->hSamplingFactorMax << 3) - 1) /
                                      (gengralEncodeInfo->hSamplingFactorMax << 3);

                  extAdditionalSize = (dstTotalMcuPerRow * minMemorySize + 3) & 0xFFFFFFFC;

               }
            }

            handle->intMemorySizeMinimum = intRequiredSize;
            handle->intMemorySizeBest = intRequiredSize;

            #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
            
               extRequiredSize += (intRequiredSize + 0x1F) & (~0x1F);
            
            #endif

            #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)
               extRequiredSize = (extRequiredSize + CPU_CACHE_LINE_SIZE_MASK) & (~CPU_CACHE_LINE_SIZE_MASK);
               extAdditionalSize = (extAdditionalSize + CPU_CACHE_LINE_SIZE_MASK) & (~CPU_CACHE_LINE_SIZE_MASK);
            #endif

            /// YUV resize + Rotate will only support MCU-row base
            if(KAL_FALSE == onlySupportMCURowBase)
            {
               handle->extMemorySizeMinimum = extRequiredSize;
            }
            else
            {
               handle->extMemorySizeMinimum = extRequiredSize + extAdditionalSize;
            }
            handle->extMemorySizeBest = extRequiredSize + extAdditionalSize;
         }
         break;
      #endif
      default:
         ASSERT(0);
      break;
   }
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpeg_enc_set_working_memory(JPEG_ENCODER_HANDLE handle)
{
   kal_uint8 *intMemPtr = (kal_uint8 *)handle->intMemoryAddr;
   kal_uint8 *extMemPtr = (kal_uint8 *)handle->extMemoryAddr;
   kal_uint32 intSize = handle->intMemorySize;
   kal_uint32 extSize = handle->extMemorySize;

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
         {
            #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
               if (INT_QueryIsCachedRAM((kal_uint32)extMemPtr, extSize))
               {
                  ASSERT(0);
               }
               if (INT_QueryIsCachedRAM((kal_uint32)intMemPtr, intSize))
               {
                  ASSERT(0);
               }
            #endif /// __DYNAMIC_SWITCH_CACHEABILITY__

            #if defined(EXIF_SUPPORT)
               if(JPEG_FILE_FORMAT_EXIF & handle->dstFileFormat)
               {
                  handle->exifWorkingBuffer = extMemPtr;
                  extMemPtr += (JPEG_SW_ENC_EXIF_EXT_MAX_MEM_SIZE + 3) & 0xFFFFFFFC;
               }
            #endif

            ASSERT(0 == ((kal_uint32)intMemPtr & 3));
            ASSERT(0 == ((kal_uint32)extMemPtr & 3));

            handle->idpIntMemoryAddr = (kal_uint32 *)intMemPtr;
            handle->idpExtMemoryAddr = (kal_uint32 *)extMemPtr;
         }
         break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #if defined(__SW_JPEG_ENCODER_SUPPORT__)
         case JPEG_CODEC_TYPE_SW:
         {
            JPEG_ENCODE_INFO * const mainEncodeInfo = &(handle->mainEncodeInfo);
            JPEG_GENGERAL_ENCODE_INFO* const gengralEncodeInfo = &(handle->gengralEncodeInfo);
            kal_uint32 step = 1;

            if ((0 != intSize) && (NULL != intMemPtr))
            {
               memset(intMemPtr, 0, intSize);
               if (0 == smmInit(&handle->intMemorySMM, intMemPtr, intSize))
               {
                  handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_BUFFER;
                  return handle->lastStatus;
               }

               #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
               {
                  /// handle->pWorkingBuffer
                  /// Temp buffer for store FDCT, Quantize table and Huffman
                  handle->pWorkingBuffer = (kal_uint8 *)smmMallocAligned(&(handle->intMemorySMM), ((64 * 4) + (64 * 4)), 4);

                  /// Allocate memory for Quant-FDCT units.
                  handle->QuantTables[0].pIntQuantTable = (kal_int16 *)smmMallocAligned(&(handle->intMemorySMM), (128), 4);
                  handle->QuantTables[0].pFixedQuantTable = (kal_int32 *)smmMallocAligned(&(handle->intMemorySMM), (256), 4);
                  handle->QuantTables[1].pIntQuantTable = (kal_int16 *)smmMallocAligned(&(handle->intMemorySMM), (128), 4);
                  handle->QuantTables[1].pFixedQuantTable = (kal_int32 *)smmMallocAligned(&(handle->intMemorySMM), (256), 4);

                  handle->zZagTable =  (kal_uint32 *)smmMallocAligned(&(handle->intMemorySMM), (64 * 4), 4);

                  /// move to stack (jpeg_enc_sw_internal())
                  /// Allocate memory for fragment processor.
                  handle->pFragProcessor = (SWJE_FRAGMENT_PROCESSOR *)smmMallocAligned(&(handle->intMemorySMM), sizeof(SWJE_FRAGMENT_PROCESSOR), 4);
                  handle->pFDCTQuantUnits = (SWJE_FDCT_QUANT_UNIT *)smmMallocAligned(&(handle->intMemorySMM), sizeof(SWJE_FDCT_QUANT_UNIT) * 3, 4);
                  /// Allocate memory for Huffman encoder.
                  handle->pHuffEncoder = (SWJE_HUFFMAN_ENCODER *)smmMallocAligned(&(handle->intMemorySMM), sizeof(SWJE_HUFFMAN_ENCODER), 4);

                  {
                     SWJE_HUFF_TABLE* pHuffTable = &(handle->huffTables[0]);

                     pHuffTable->pBits = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_DC_BITS_BITS);
                     pHuffTable->pHuffValue = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_DC_VAL_BITS);
                     pHuffTable->pHuffCode = (kal_uint16 *)smmMallocAligned(&(handle->intMemorySMM), SWJE_HUFF_DC_TRANSLATION_BITS * 2, 4);
                     pHuffTable->pHufFSize = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_DC_TRANSLATION_BITS);
                     pHuffTable++;

                     pHuffTable->pBits = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_DC_BITS_BITS);
                     pHuffTable->pHuffValue = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_DC_VAL_BITS);
                     pHuffTable->pHuffCode = (kal_uint16 *)smmMallocAligned(&(handle->intMemorySMM), SWJE_HUFF_DC_TRANSLATION_BITS * 2, 4);
                     pHuffTable->pHufFSize = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_DC_TRANSLATION_BITS);
                     pHuffTable++;

                     pHuffTable->pBits = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_AC_BITS_BITS);
                     pHuffTable->pHuffValue = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_AC_VAL_BITS);
                     pHuffTable->pHuffCode = (kal_uint16 *)smmMallocAligned(&(handle->intMemorySMM), SWJE_HUFF_AC_TRANSLATION_BITS * 2, 4);
                     pHuffTable->pHufFSize = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_AC_TRANSLATION_BITS);
                     pHuffTable++;

                     pHuffTable->pBits = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_AC_BITS_BITS);
                     pHuffTable->pHuffValue = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_AC_VAL_BITS);
                     pHuffTable->pHuffCode = (kal_uint16 *)smmMallocAligned(&(handle->intMemorySMM), SWJE_HUFF_AC_TRANSLATION_BITS * 2, 4);
                     pHuffTable->pHufFSize = (kal_uint8 *)smmMalloc(&(handle->intMemorySMM), SWJE_HUFF_AC_TRANSLATION_BITS);
                  }
               }
               #endif
            }

            if ((0 != extSize) && (NULL != extMemPtr))
            {
               #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
                  handle->extMemoryEnableDynamicSwitch = drv_gfx_dynamic_switch_cacheable(&(handle->extMemoryAddr), extSize, KAL_TRUE);
                  extMemPtr = (kal_uint8 *)handle->extMemoryAddr;
               #endif
               {
                  memset(extMemPtr, 0, extSize);
                  if (0 == smmInit(&handle->extMemorySMM, extMemPtr, extSize))
                  {
                     handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_BUFFER;
                     return handle->lastStatus;
                  }

                  #if defined(EXIF_SUPPORT)
                     if(JPEG_FILE_FORMAT_EXIF & handle->dstFileFormat)
                     {
                        handle->exifWorkingBuffer = (kal_uint8 *)smmMallocAligned(&(handle->extMemorySMM), JPEG_SW_ENC_EXIF_EXT_MAX_MEM_SIZE, 4);
                     }
                  #endif

                  #ifndef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
                     ///handle->pWorkingBuffer
                     /// Temp buffer for store FDCT, Quantize table and Huffman
                     handle->pWorkingBuffer = (kal_uint8 *)smmMallocAligned(&(handle->extMemorySMM), ((64 * 4) + (64 * 4)), 4);

                     /// Allocate memory for Quant-FDCT units.
                     handle->QuantTables[0].pIntQuantTable = (kal_int16 *)smmMallocAligned(&(handle->extMemorySMM), (128), 4);
                     handle->QuantTables[0].pFixedQuantTable = (kal_int32 *)smmMallocAligned(&(handle->extMemorySMM), (256), 4);
                     handle->QuantTables[1].pIntQuantTable = (kal_int16 *)smmMallocAligned(&(handle->extMemorySMM), (128), 4);
                     handle->QuantTables[1].pFixedQuantTable = (kal_int32 *)smmMallocAligned(&(handle->extMemorySMM), (256), 4);

                     /// Allocate memory for fragment processor.
                     handle->pFragProcessor = (SWJE_FRAGMENT_PROCESSOR *)smmMallocAligned(&(handle->extMemorySMM), sizeof(SWJE_FRAGMENT_PROCESSOR), 4);
                     handle->pFDCTQuantUnits = (SWJE_FDCT_QUANT_UNIT *)smmMallocAligned(&(handle->extMemorySMM), sizeof(SWJE_FDCT_QUANT_UNIT) * 3, 4);
                     /// Allocate memory for Huffman encoder.
                     handle->pHuffEncoder = (SWJE_HUFFMAN_ENCODER *)smmMallocAligned(&(handle->extMemorySMM), sizeof(SWJE_HUFFMAN_ENCODER), 4);
                  #endif

                  /// RGB-> YUV working buufer for color translation
                  if(JPEG_ENCODE_SOURCE_RGB_BUFFER == handle->srcMode)
                  {
                     kal_uint32 minMemorySize = 0;
                     kal_uint32 leftMemorySize = smmGetFreeSpace(&(handle->extMemorySMM));
                     kal_int32 i;
                     #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                        kal_uint32 minRotateMemorySize = 0;
                     #endif
                     #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER) || defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                        kal_uint32 bpp = 0;
                        
                        switch(handle->srcRGBFormat)
                        {
                           case JPEG_RGB_FORMAT_RGB565:
                              bpp = 2;
                           break;
                           case JPEG_RGB_FORMAT_RGB888:
                           case JPEG_RGB_FORMAT_BGR888:
                              bpp = 3;
                           break;
                           default:
                              ASSERT(0);
                           ///break;
                        }
                     #endif

                     #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER)
                        i = gengralEncodeInfo->numComponent;
                        while (--i >= 0)
                        {
                           minMemorySize += ((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6;
                        }

                        if(!(((0x00010000 == (mainEncodeInfo->srcStepX)) && (0x00010000 == (mainEncodeInfo->srcStepY)))))
                        {
                           minMemorySize += (((gengralEncodeInfo->hSamplingFactorMax) * (gengralEncodeInfo->vSamplingFactorMax)) << 6) * bpp;
                        }

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                           {
                              JPEG_ENCODE_INFO* const mainEncodeInfo = &(handle->mainEncodeInfo);

                              minRotateMemorySize = (((
                                               ((gengralEncodeInfo->hSamplingFactorMax * IUL_X_TO_I_CARRY(mainEncodeInfo->srcStepX)) + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE) *
                                               ((gengralEncodeInfo->vSamplingFactorMax * IUL_X_TO_I_CARRY(mainEncodeInfo->srcStepY)) + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE)
                                               ) << 6) * bpp + 3) & 0xFFFFFFFC;
                              minMemorySize += minRotateMemorySize;
                           }
                        #endif

                        step = leftMemorySize / minMemorySize ;
                        ASSERT(step > 0);

                        i = gengralEncodeInfo->numComponent;
                        while (--i >= 0)
                        {
                           handle->YUVWorkingBuffer[i] = (void *)smmMallocAligned(&(handle->extMemorySMM), (((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6) * step, 4);
                        }

                        if(!(((0x00010000 == (mainEncodeInfo->srcStepX)) && (0x00010000 == (mainEncodeInfo->srcStepY)))))
                        {
                           handle->RGBWorkingBuffer = (void *)smmMallocAligned(&(handle->extMemorySMM), (((gengralEncodeInfo->hSamplingFactorMax) * (gengralEncodeInfo->vSamplingFactorMax)) << 6) * bpp * step, 4);
                        }

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                           {
                              handle->RGBRotateWorkingBuffer = (void *)smmMallocAligned(&(handle->extMemorySMM), minRotateMemorySize * step, 4);
                           }
                        #endif
                     #else
                        i = gengralEncodeInfo->numComponent;
                        while (--i >= 0)
                        {
                           minMemorySize += ((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6;
                        }

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                           {
                              minMemorySize += (((gengralEncodeInfo->hSamplingFactorMax + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE) * (gengralEncodeInfo->vSamplingFactorMax + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE)) << 6) * bpp;
                           }
                        #endif

                        step = leftMemorySize / minMemorySize ;
                        ASSERT(step > 0);

                        i = gengralEncodeInfo->numComponent;
                        while (--i >= 0)
                        {
                           handle->YUVWorkingBuffer[i] = (void *)smmMallocAligned(&(handle->extMemorySMM), (((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6) * step, 4);
                        }

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                           {
                              handle->RGBRotateWorkingBuffer = (void *)smmMallocAligned(&(handle->extMemorySMM), (((gengralEncodeInfo->hSamplingFactorMax + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE) * (gengralEncodeInfo->vSamplingFactorMax + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE)) << 6) * bpp * step, 4);
                           }
                        #endif

                     #endif
                  }
                  else
                  {
                     {
                        kal_uint32 leftMemorySize = smmGetFreeSpace(&(handle->extMemorySMM));
                        kal_int32 i;

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT) || defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER)
                           kal_uint32 minMemorySize = 0;
                        #endif

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           kal_uint32 minRotateMemorySize[3] = {0, 0, 0};
                        #endif
                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                           {
                              i = gengralEncodeInfo->numComponent;

                              while (--i >= 0)
                              {
                                 minRotateMemorySize[i] = (((
                                                          ((gengralEncodeInfo->hSamplingFactor[i] * IUL_X_TO_I_CARRY(mainEncodeInfo->srcStepX)) + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE) *
                                                          ((gengralEncodeInfo->vSamplingFactor[i] * IUL_X_TO_I_CARRY(mainEncodeInfo->srcStepY)) + SW_JPEG_ENC_V2_ROTATE_EXTERNAL_MEMORY_LINE)
                                                          ) << 6) + 3) & 0xFFFFFFFC;
                                 minMemorySize += minRotateMemorySize[i];
                              }
                           }
                        #endif

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER)
                        if(!(((0x00010000 == (mainEncodeInfo->srcStepX)) && (0x00010000 == (mainEncodeInfo->srcStepY)))))
                        {
                            i = gengralEncodeInfo->numComponent;
                            while (--i >= 0)
                            {
                               minMemorySize += ((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6 ;
                            }

                            step = leftMemorySize / minMemorySize ;
                            ASSERT(step > 0);

                            i = gengralEncodeInfo->numComponent;
                            while (--i >= 0)
                            {
                               handle->YUVWorkingBuffer[i] = (void *)smmMallocAligned(&(handle->extMemorySMM), (((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6) * step, 4);
                            }
                        }
                        #endif
                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY)
                           #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER)
                              else
                           #endif
                           if (JPEG_YUV_FORMAT_PACKED_UYVY422 == handle->srcSamplingFormat)
                           {
                              i = gengralEncodeInfo->numComponent;
                              while (--i >= 0)
                              {
                                 handle->YUVWorkingBuffer[i] = (void *)smmMallocAligned(&(handle->extMemorySMM), (((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6), 4);
                              }
                           }
                        #endif
                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER) || defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY)
                           else
                        #endif
                        if(!((0 == ((mainEncodeInfo->dstWidth) % (mainEncodeInfo->dstMcuWidth))) && (0 == ((mainEncodeInfo->dstHeight) % (mainEncodeInfo->dstMcuHeight)))))
                        {
                            #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                               if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                               {
                                   step = leftMemorySize / minMemorySize;
                                   ASSERT(step > 0);
                               }
                               else
                            #endif
                            {
                                i = gengralEncodeInfo->numComponent;
                                while (--i >= 0)
                                {
                                   handle->YUVWorkingBuffer[i] = (void *)smmMallocAligned(&(handle->extMemorySMM), (((gengralEncodeInfo->hSamplingFactor[i]) * (gengralEncodeInfo->vSamplingFactor[i])) << 6), 4);
                                }
                            }
                        }
                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           else
                           {
                               if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                               {
                                  step = leftMemorySize / minMemorySize ;
                                  ASSERT(step > 0);
                               }
                           }
                        #endif

                        #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                           if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                           {
                              i = gengralEncodeInfo->numComponent;
                              while (--i >= 0)
                              {
                                 kal_uint32 rotateSize = minRotateMemorySize[i] * step;
                                 handle->YUVRotateWorkingBuffer[i] = (void *)smmMallocAligned(&(handle->extMemorySMM), rotateSize, 4);
                                 handle->YUVRotateWorkingBufferSize[i] = rotateSize;
                              }
                           }
                        #endif
                     }
                  }
               }
            }

            handle->workingBufferMcuNum = step;
         }
         break;
      #endif
      default:
         ASSERT(0);
      break;
   }
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpeg_enc_get_encoder(JPEG_CODEC_TYPE_ENUM codecType, JPEG_ENCODER_HANDLE *handlePtr)
{
   JPEG_ENCODER_HANDLE handle = NULL;

   switch (codecType)
   {
      case JPEG_CODEC_TYPE_HW:
         #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
         {
            #if defined(__MTK_TARGET__)
               if (NULL == jpeg_encoder_state_mutex)
               {
                  jpeg_encoder_state_mutex = kal_create_mutex("JPEG Encoder State");
                  ASSERT(jpeg_encoder_state_mutex != NULL);
               }
            #endif

            jpeg_enc_hw_get_handle(handlePtr);
            handle = *handlePtr;

            #if defined(__MTK_TARGET__)
               if (!drv_gfx_open_dct(DCT_USER_JPEG_ENCODER))
               {
                  return JPEG_STATUS_CODEC_UNAVAILABLE;
               }
               if (KAL_TRUE != INT_QueryExceptionStatus())
               {
                  kal_take_mutex(jpeg_encoder_state_mutex);
                  if (KAL_TRUE == _hw_jpeg_encoder_in_use)
                  {
                     /// The desired encoder is already in use
                     *handlePtr = NULL;
                     kal_give_mutex(jpeg_encoder_state_mutex);

                     return JPEG_STATUS_CODEC_UNAVAILABLE;
                  }
                  _hw_jpeg_encoder_in_use = KAL_TRUE;
                  kal_give_mutex(jpeg_encoder_state_mutex);
               }
               else
               {
                  if (KAL_TRUE == _hw_jpeg_encoder_in_use)
                  {
                     handlePtr = NULL;
                     return JPEG_STATUS_CODEC_UNAVAILABLE;
                  }
                  _hw_jpeg_encoder_in_use = KAL_TRUE;
               }
            #else
               if (KAL_TRUE == _hw_jpeg_encoder_in_use)
               {
                  handlePtr = NULL;
                  return JPEG_STATUS_CODEC_UNAVAILABLE;
               }
               _hw_jpeg_encoder_in_use = KAL_TRUE;
            #endif
         }
         #else
            return JPEG_STATUS_ENC_ERROR_NOT_UNSUPPORT_HW;
         #endif /// __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      break;
      case JPEG_CODEC_TYPE_SW:
         #if defined(__SW_JPEG_ENCODER_SUPPORT__)
            ///sizeof(JPEG_ENCODER) = 520 bytes
            handle = (JPEG_ENCODER_HANDLE)malloc(sizeof(JPEG_ENCODER));
            *handlePtr = handle;
         #else
            return JPEG_STATUS_ENC_ERROR_NOT_UNSUPPORT_SW;
         #endif
      break;
      default:
         ASSERT(0);
   }

   memset(handle, 0, sizeof(JPEG_ENCODER));
   handle->codecType = codecType;
   handle->codecState = JPEG_CODEC_STATE_IDLE;

   #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
      if (JPEG_CODEC_TYPE_HW == codecType)
      {
         jpeg_drv_init();
      }
   #endif /// __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;

}



JPEG_STATUS_ENUM jpeg_enc_release_encoder(JPEG_ENCODER_HANDLE handle)
{
   JPEG_STATUS_ENUM status = JPEG_STATUS_OK;

   if (0 != jpeg_enc_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
         {
            jpeg_drv_enc_power_off();

            #if defined(__MTK_TARGET__)

               #if (!defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__))
                  /// Release the control of IDP
                  if (handle->idpKey)
                  {
                     if (!handle->idp_close_func(handle->idpKey))
                     {
                        ASSERT(0);
                        ///status = JPEG_STATUS_IDP_ERROR;
                     }
                  }
               #endif

               if (!drv_gfx_close_dct(DCT_USER_JPEG_ENCODER))
               {
                  ASSERT(0);
               }

               if (KAL_TRUE != INT_QueryExceptionStatus())
               {
                  kal_take_mutex(jpeg_encoder_state_mutex);
                  _hw_jpeg_encoder_in_use = KAL_FALSE;
                  kal_give_mutex(jpeg_encoder_state_mutex);
               }
               else
               {
                  _hw_jpeg_encoder_in_use = KAL_FALSE;
               }
            #else
               _hw_jpeg_encoder_in_use = KAL_FALSE;
            #endif
         }
         break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_ENCODE_SUPPORTED__
      #if defined(__SW_JPEG_ENCODER_SUPPORT__)
         case JPEG_CODEC_TYPE_SW:
            #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
               if (KAL_TRUE == handle->intMemoryAllocateEnable)
               {
                  #if defined(__MTK_TARGET__)
                     mm_intmem_free(MM_SCEN__JPEG_ENCODE, MM_INTMEM_SEG__JPEG_ENC);
                  #endif
               }
            #endif
            free(handle);
         break;
      #endif
      default:
         ASSERT(0);
   }
   return status;
}




/*

kal_int32 jpeg_enc_thumbnail_calc_resolution(JPEG_ENCODER_HANDLE handle, kal_uint32* width, kal_uint32* height)
{
    kal_uint32 ratio;
    kal_uint32 invertRatio;
    kal_uint32 thumbnailWidth, thumbnailHeight;
    kal_uint32 srcWidth = handle->srcWidth;
    kal_uint32 srcHeight = handle->srcHeight;

    ratio = IUL_I_TO_X(srcWidth) / (srcHeight);

    if (IUL_X_TO_I_CHOP(ratio) >= 1)
    {
        /// Primary image's width is larger than height.
        invertRatio = IUL_I_TO_X(srcHeight) / srcWidth;

        thumbnailWidth = 160;
        thumbnailHeight = IUL_X_TO_I(thumbnailWidth * invertRatio);

        if (thumbnailHeight > 120)
        {
            thumbnailHeight = 120;
            thumbnailWidth = IUL_X_TO_I(thumbnailHeight * ratio);
        }
    }
    else
    {
        // Primary image's height is larger than width.
        thumbnailHeight = 160;
        thumbnailWidth = IUL_X_TO_I(thumbnailHeight * ratio);

        if (thumbnailWidth > 120)
        {
            invertRatio = IUL_I_TO_X(srcHeight) / srcWidth;

            thumbnailWidth = 120;
            thumbnailHeight = IUL_X_TO_I(thumbnailWidth * invertRatio);
        }
    }

    /// Thumbnail width/height can not be odd for YUV420 and YUV422.
    if(JPEG_ENCODE_SOURCE_YUV_BUFFER == (handle->srcMode))
    {
       if(JPEG_YUV_FORMAT_YUV420 == handle->dstSamplingFormat)
       {
          thumbnailHeight = thumbnailHeight & 0xFFFFFFFE;
       }
       thumbnailWidth = thumbnailWidth & 0xFFFFFFFE;
    }

    /// 1.If the thumbnail's width/height is larger than primary image's width/height, we don't have to encode thumbnail.
    if((thumbnailWidth >= srcWidth) || (thumbnailHeight >= srcHeight))
    {
       *width = 0;
       *height = 0;

       return -1;
    }
    else
    {
       *width = thumbnailWidth;
       *height = thumbnailHeight;

       return 0;
    }
}
*/

