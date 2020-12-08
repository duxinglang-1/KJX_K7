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
 *   jpeg_decode_int.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Internal implementation of JPEG decode interface.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fsal.h"
#include "drv_features_jpeg.h"
#include "jpeg_decode_structure.h"
#include "jpeg_enum.h"
#include "jpeg_decode_int.h"
#include "iul_x_math.h"
#include "jpeg_parse_structure.h"
#include "jpeg_misc_api.h"
#include "jpeg_mem_int.h"
#include "rs_buffer.h"
#include "jpeg_drv_api.h"
#include "swjd_huffman_decoder.h"
#include "swjd_dequant_idct_unit.h"
#include "swjd_fragment_processor.h"


#if defined(__MTK_TARGET__)
   #include "idp_mem_def.h"
   #include "mmu.h"
   #include "cache_sw.h"
   #include "idp_jpeg_decode.h"
   #include "img_common_enum.h"
   #include "drv_gfx_stack_switch_manager.h"
   #include "drv_gfx_dct_control.h"
   #include "drv_features_mmsysmisc.h"

   #define malloc get_ctrl_buffer      ///< for SW decoder.
   #define free   free_ctrl_buffer     ///< for SW decoder.
#endif

#if defined(DRV_FEATURE__MM_INTMEM_IF)
    #include "mm_intmem.h"
#endif  // defined(DRV_FEATURE__MM_INTMEM_IF)

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined(__MTK_TARGET__)
   #undef __DYNAMIC_SWITCH_CACHEABILITY__
#endif


#if defined(__MTK_TARGET__)
   #define SLEEP(n)  kal_sleep_task(n)
#else
   #define SLEEP(n)  while (0) {}
#endif



/// Check the validation of JPEG decoder handle
kal_int32 jpeg_dec_check_handle(JPEG_DECODER_HANDLE handle)
{
   if (!handle)
   {
      return -1;
   }

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__) && (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__))
   if (JPEG_CODEC_TYPE_HW == handle->codecType && handle != jpeg_dec_hw_get_handle())
   {
      return -2;
   }
#endif

   return 0;
}


kal_int32 jpeg_dec_3bpp_thumbnail(JPEG_DECODER_HANDLE handle)
{
   kal_int32 j;
   IUL_FIXED srcStepX;
   IUL_FIXED srcStepY;

   JPEG_THUMBNAIL_INFO *tnInfo = &(handle->fileInfo.thumbnailInfo);
   STFSAL *tnFile = handle->fileInfo.fileHandle;

   kal_uint8 *dstPtr;
   kal_uint8 *srcPtr;

   kal_uint32 dstPitch;
   kal_uint32 srcPitch;

   kal_int32 dstHeight;

   MY_RECTANGLE srcClipWnd;
   MY_RECTANGLE dstClipWnd;

   IUL_FIXED srcY;

   srcStepX = IUL_I_TO_X(tnInfo->tn_width) / handle->outputWnd.w;
   srcStepY = IUL_I_TO_X(tnInfo->tn_height) / handle->outputWnd.h;

   /// dstClipWnd is in output window coordinate (source image coordinate).
   dstClipWnd.x = handle->targetClipWnd.x;
   dstClipWnd.y = handle->targetClipWnd.y;
   dstClipWnd.w = handle->targetClipWnd.w;
   dstClipWnd.h = handle->targetClipWnd.h;

   srcClipWnd.x = IUL_X_TO_I(dstClipWnd.x * srcStepX);
   srcClipWnd.y = IUL_X_TO_I(dstClipWnd.y * srcStepY);
   srcClipWnd.w = IUL_X_TO_I(dstClipWnd.w * srcStepX);
   srcClipWnd.h = IUL_X_TO_I(dstClipWnd.h * srcStepY);

   /// To avoid the problem which may occur in the boundary case,
   /// we simply reduce the interpolation step to guarantee that the interpolated source coordination will not exceed the boundary.
   srcStepX = IUL_I_TO_X(tnInfo->tn_width - 1) / handle->outputWnd.w;
   srcStepY = IUL_I_TO_X(tnInfo->tn_height - 1) / handle->outputWnd.h;

   /// Now project dstClipWnd into canvas window coordinate.
   dstClipWnd.x += handle->outputWnd.x;
   dstClipWnd.y += handle->outputWnd.y;

   dstPtr = ((kal_uint8 *)handle->canvasBuffer[0]) + ((dstClipWnd.y * handle->canvasWnd.w + dstClipWnd.x) * handle->canvasBytesPerPixel);
   dstPitch = handle->canvasWnd.w * handle->canvasBytesPerPixel;

   srcPitch = tnInfo->tn_width * 3;

   srcY = 0;

   dstHeight = dstClipWnd.h;
   while(--dstHeight >= 0)
   {
      /// Seek to the start of the first scan line in the clip region in thumbnail image.
      FSAL_Seek(tnFile, tnInfo->tn_offset + ((srcY >> 16) * srcPitch) + (srcClipWnd.x * 3));

      /// Read the source image.
      if (!(handle->fileIsInMemory))
      {
         kal_uint32 data_to_read = 0;

         srcPtr = handle->fsalReadBufferAddr;

         if ((srcY >> 16) < (tnInfo->tn_height - 1))
         {
            /// Read one more scan line to avoid the issue occurs on the boundary during interpolation.
            data_to_read = 2 * srcPitch;
         }
         else
         {
            ASSERT(0);
         }

         if (handle->fsalReadBufferSize < data_to_read)
         {
            return 0;
         }

         if (FSAL_OK != FSAL_Read(tnFile, handle->fsalReadBufferAddr, data_to_read))
         {
            return 0;
         }
      }
      else
      {
         /// For memory files, we don't have to read the thumbnail data into another buffer.
         kal_uint32 curPos;

         FSAL_GetCurPos(tnFile, &curPos);
         srcPtr = FSAL_GetRamFilePointer(tnFile);
         srcPtr += curPos;
      }

      {
         kal_uint8 *srcPtrTmp0;
         kal_uint8 *srcPtrTmp1;
         kal_uint8 *dstPtrTmp;
         IUL_FIXED srcX;


         /// Bilinear interpolation.
         /// srcPtr points to the start of the source scan line (RGB888).
         srcPtrTmp0 = srcPtr;
         srcPtrTmp1 = srcPtrTmp0 + srcPitch;

         /// dstPtr points to the start of the destination scan line in destination clip window (RGB565).
         dstPtrTmp = dstPtr;
         srcX = 0;

         j = dstClipWnd.w;
         while (--j >= 0)
         {
            kal_uint32 red0, red1;
            kal_uint32 green0, green1;
            kal_uint32 blue0, blue1;

            kal_uint8 *srcPix;
            kal_uint32 weight0, weight1;

            weight1 = IUL_X_FRACTION(srcX);
            weight0 = IUL_I_TO_X(1) - weight1;

            srcPix = srcPtrTmp0 + IUL_X_TO_I_CHOP(srcX) * 3;
            red0   = IUL_X_TO_I((kal_int32)(srcPix[0] * weight0 + srcPix[3] * weight1));
            green0 = IUL_X_TO_I((kal_int32)(srcPix[1] * weight0 + srcPix[4] * weight1));
            blue0  = IUL_X_TO_I((kal_int32)(srcPix[2] * weight0 + srcPix[5] * weight1));

            srcPix = srcPtrTmp1 + IUL_X_TO_I_CHOP(srcX) * 3;
            red1   = IUL_X_TO_I((kal_int32)(srcPix[0] * weight0 + srcPix[3] * weight1));
            green1 = IUL_X_TO_I((kal_int32)(srcPix[1] * weight0 + srcPix[4] * weight1));
            blue1  = IUL_X_TO_I((kal_int32)(srcPix[2] * weight0 + srcPix[5] * weight1));

            weight1 = IUL_X_FRACTION(srcY);
            weight0 = IUL_I_TO_X(1) - weight1;

            red0   = (red0   * weight0 + red1   * weight1);
            green0 = (green0 * weight0 + green1 * weight1);
            blue0  = (blue0  * weight0 + blue1  * weight1);

            switch (handle->canvasFormat)
            {
            case JPEG_RGB_FORMAT_RGB565:
               red0   = (red0 >> 8) & 0xF800;      /// 5 bits left
               green0 = (green0 >> 13) & 0x07E0;   /// 6 bits left
               blue0  = blue0 >> (16 + 3);         /// 5 bits left

               *(kal_uint16 *)dstPtrTmp = (kal_uint16)(red0 | green0 | blue0);
               dstPtrTmp += 2;
               break;

            case JPEG_RGB_FORMAT_RGB888:
               /// RGB888: R is the highest byte. Output order is B, G, R.
               dstPtrTmp[0] = IUL_X_TO_I(blue0);
               dstPtrTmp[1] = IUL_X_TO_I(green0);
               dstPtrTmp[2] = IUL_X_TO_I(red0);
               dstPtrTmp += 3;
               break;

            case JPEG_RGB_FORMAT_BGR888:
               /// BGR888: B is the highest byte. Output order is R, G, B.
               dstPtrTmp[0] = IUL_X_TO_I(red0);
               dstPtrTmp[1] = IUL_X_TO_I(green0);
               dstPtrTmp[2] = IUL_X_TO_I(blue0);
               dstPtrTmp += 3;
               break;

            case JPEG_RGB_FORMAT_ARGB8888:
               /// ARGB8888: A is the highest byte, the followings are R then G then B.
               red0 = (IUL_X_TO_I(red0) << 16) & 0xFF0000;
               green0 = (IUL_X_TO_I(green0) << 8) & 0xFF00;
               blue0 = IUL_X_TO_I(blue0) & 0xFF;
               *(kal_uint32 *)dstPtrTmp = red0 | green0 | blue0 | 0xFF000000;
               dstPtrTmp += 4;
               break;

            default:
               return 0;
            }

            srcX += srcStepX;
         }
         srcY += srcStepY;
         dstPtr += dstPitch;
      }
   }
   return 1;
}



/// Calculate the working memory for JPEG decoder (and IDP).
void jpeg_dec_query_working_memory_internal(JPEG_DECODER_HANDLE handle)
{
   kal_uint32 ext_size = 0;
   JPEG_FRAME_INFO * const frameInfo = &(handle->fileInfo.frameInfo);

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
            jpeg_drv_dec_query_decode_table_size(&(handle->hwDecodeTableSize));

            ext_size += (handle->hwDecodeTableSize);
            ext_size += sizeof(JPEG_FILE_INFO);

            #if defined(__MTK_TARGET__) && (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__))
            {
               kal_uint32 max_width = IDP_JPEG_DECODE_MAX_DST_WIDTH;

               handle->idpIntMemorySize = 0;
               if (max_width > frameInfo->paddedWidth)
               {
                  max_width = frameInfo->paddedWidth;
               }

               // sampling format 422v needs more mdp line buffer
               if ((JPEG_YUV_FORMAT_YUV422 == frameInfo->samplingFormat) &&
                    (frameInfo->vSamplingFactorMax > frameInfo->hSamplingFactorMax))
               {
                  handle->idpExtMemorySize = IDP_MEM_CONSUME_JPEG_DECODE_CALC_YUV422V_EXTMEM(max_width);
                  ext_size += IDP_MEM_CONSUME_JPEG_DECODE_CALC_YUV422V_EXTMEM(max_width);
               }
               else
               {
                  handle->idpExtMemorySize = IDP_MEM_CONSUME_JPEG_DECODE_CALC_EXTMEM(max_width);
                  ext_size += IDP_MEM_CONSUME_JPEG_DECODE_CALC_EXTMEM(max_width);
               }

               if (ext_size)
               {
                  /// add 32 bytes for alignment adjustment.
                  ext_size += 32;
               }
            }
            #else
            {
               handle->idpIntMemorySize = 0;
               handle->idpExtMemorySize = 0;
            }
            #endif

            // internal memory query by mm interface
            handle->intMemorySizeMinimum = 0;
            handle->intMemorySizeBest = 0;

            handle->extMemorySizeMinimum = ext_size;
            handle->extMemorySizeBest = ext_size;

            #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_PROGRESSIVE__)
               /// Query progressive coefficient buffer for progressive JPEG.
               if (JPEG_ENCODE_PROCESS_PROGRESSIVE == handle->fileInfo.frameInfo.encProcess)
               {
                  JPEG_FRAME_INFO * const frameInfo = &(handle->fileInfo.frameInfo);
                  kal_uint32 min_size, best_size;

                  jpeg_drv_dec_query_prog_buffer_size(&min_size, &best_size);

                  handle->extMemorySizeMinimum += min_size + 32;
                  handle->extMemorySizeBest += best_size + 32;
               }
            #endif
      break;
   #endif /// __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__

      case JPEG_CODEC_TYPE_SW:
      {
         kal_int32   maxMCUBuffered;

         ext_size += sizeof(JPEG_FILE_INFO);
         ext_size += sizeof(HuffmanDecoder);
         ext_size += sizeof(HuffmanDecQuantTable) * 4;
         ext_size += sizeof(SWJD_DEQUANT_IDCT_UNIT);
         ext_size += sizeof(SWJD_FRAGMENT_PROCESSOR);

      #if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
         if (JPEG_ENCODE_PROCESS_PROGRESSIVE == frameInfo->encProcess)
         {
            ext_size += sizeof(HuffmanDecDCTable) * 12;
            ext_size += sizeof(HuffmanDecACTable) * 12;

            /// Query the output buffer for Huffman decoder.
            huffmanDecQueryOutputBuffer(HUFFMAN_DEC_SOURCE_PROGRESSIVE,
                                        frameInfo->duPerMCU,
                                        frameInfo->mcuPerRow,
                                        &maxMCUBuffered,
                                        &handle->huffDecOutputSize,
                                        &handle->huffDecOutputAlign);
         }
         else
      #endif
         {
            ext_size += sizeof(HuffmanDecDCTable) * 2;
            ext_size += sizeof(HuffmanDecACTable) * 2;

            /// Query the output buffer for Huffman decoder.
            huffmanDecQueryOutputBuffer(HUFFMAN_DEC_SOURCE_BASELINE,
                                        frameInfo->duPerMCU,
                                        frameInfo->mcuPerRow,
                                        &maxMCUBuffered,
                                        &handle->huffDecOutputSize,
                                        &handle->huffDecOutputAlign);
         }

         ext_size += handle->huffDecOutputSize;

         /// Query the output bufer for dequant & IDCT
         dequantIDCTQueryOutputBuffer(frameInfo->duPerMCU,
                                      maxMCUBuffered,
                                      0, //handle->dctScaleBits,
                                      &handle->dequantIDCTOutputSize,
                                      &handle->dequantIDCTOutputAlign);

         ext_size += handle->dequantIDCTOutputSize;
         ext_size += JPEG_SW_DEC_WORKING_BUFFER_MARGIN;

         handle->extMemorySizeMinimum = ext_size;
         handle->extMemorySizeBest    = ext_size;
         handle->intMemorySizeMinimum = 0;
         handle->intMemorySizeBest    = 0;

         #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
            if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == (handle->dstBufferCacheSwitchBehavior))
            {
               handle->extMemorySizeMinimum = ((handle->extMemorySizeMinimum + CPU_CACHE_LINE_SIZE_MASK) & ~CPU_CACHE_LINE_SIZE_MASK);
               handle->extMemorySizeBest    = ((handle->extMemorySizeBest    + CPU_CACHE_LINE_SIZE_MASK) & ~CPU_CACHE_LINE_SIZE_MASK);
            }
         #endif  // __DYNAMIC_SWITCH_CACHEABILITY__

         /// Remember to add some margin for the use of alignment.
      }
      break;

      default:
         ASSERT(0);
   }
}


JPEG_STATUS_ENUM jpeg_dec_set_working_memory_internal(JPEG_DECODER_HANDLE handle)
{   
   if (handle->intMemorySize)
   {
      memset(handle->intMemoryAddr, 0, handle->intMemorySize);
      if (0 == smmInit(&handle->intMemorySMM, handle->intMemoryAddr, handle->intMemorySize))
      {
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_BUFFER;
         return handle->lastStatus;
      }
   }

   if (handle->extMemorySize )
   {
      memset(handle->extMemoryAddr, 0, handle->extMemorySize);
      if (0 == smmInit(&handle->extMemorySMM, handle->extMemoryAddr, handle->extMemorySize ))
      {
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_BUFFER;
         return handle->lastStatus;
      }
   }

   /// Allocate memory from working memory.
   handle->fileInfoBackup = smmMallocAligned(&(handle->extMemorySMM), sizeof(JPEG_FILE_INFO), 4);

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
         {
#if (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__))
            {
               /// Assign memory for decoding table.
               /// Notice that the decoding table buffer must be aligned at 2K address.
               kal_uint32 dec_tbl_size, dec_tbl_alignment;

               jpeg_drv_dec_query_decode_table_info(&dec_tbl_size, &dec_tbl_alignment);
               handle->hwDecodeTableAddr = (kal_uint32 *)smmMallocAligned(&(handle->intMemorySMM), dec_tbl_size, dec_tbl_alignment);
               if (NULL == handle->hwDecodeTableAddr)
               {
                  handle->hwDecodeTableAddr = (kal_uint32 *)smmMallocAligned(&(handle->extMemorySMM), dec_tbl_size, dec_tbl_alignment);
               }
   
               handle->hwDecodeTableSize = dec_tbl_size;
            }
#endif

            handle->idpExtMemoryAddr = (kal_uint32 *)smmMallocAligned(&(handle->extMemorySMM), handle->idpExtMemorySize, 32);
            ASSERT(0 == ((kal_uint32)handle->idpIntMemoryAddr & 3));
            ASSERT(0 == ((kal_uint32)handle->idpExtMemoryAddr & 3));

            #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_PROGRESSIVE__)
               if (JPEG_ENCODE_PROCESS_PROGRESSIVE == handle->fileInfo.frameInfo.encProcess)
               {
                  handle->hwProgCoefBufferSize[0] = smmGetFreeSpaceAligned(&(handle->extMemorySMM), 4);
                  handle->hwProgCoefBufferAddr[0] = (kal_uint32 *)smmMallocAligned(&(handle->extMemorySMM), handle->hwProgCoefBufferSize[0], 4);
               }
            #endif
         }
         break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__
      case JPEG_CODEC_TYPE_SW:
      {
         /// Allocate memory for Huffman decoder.
      #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
         handle->pHuffDecoder = (HuffmanDecoder *)smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecoder), 4);
      #else
         handle->pHuffDecoder = (HuffmanDecoder *)smmMallocAligned(&(handle->intMemorySMM), sizeof(HuffmanDecoder), 4);
         if (NULL == handle->pHuffDecoder)
         {
            handle->pHuffDecoder = (HuffmanDecoder *)smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecoder), 4);
         }
      #endif  // __SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__

#if 0  // move to jpeg decode start for sharing
      #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
/* under construction !*/
      #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #endif // __SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__
#endif

         /// Allocate memory for Dequant-IDCT units.
      #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
         handle->pDequantIDCTUnit = (SWJD_DEQUANT_IDCT_UNIT *)smmMallocAligned(&(handle->extMemorySMM), sizeof(SWJD_DEQUANT_IDCT_UNIT), 4);
      #else
         handle->pDequantIDCTUnit = (SWJD_DEQUANT_IDCT_UNIT *)smmMallocAligned(&(handle->intMemorySMM), sizeof(SWJD_DEQUANT_IDCT_UNIT), 4);
         if (NULL == handle->pDequantIDCTUnit)
         {
            handle->pDequantIDCTUnit = (SWJD_DEQUANT_IDCT_UNIT *)smmMallocAligned(&(handle->extMemorySMM), sizeof(SWJD_DEQUANT_IDCT_UNIT), 4);
         }
      #endif  // __SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__

      #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
         handle->pDequantIDCTOutputBuf = smmMallocAligned(&(handle->extMemorySMM), handle->dequantIDCTOutputSize, handle->dequantIDCTOutputAlign);
      #else
         handle->pDequantIDCTOutputBuf = smmMallocAligned(&(handle->intMemorySMM), handle->dequantIDCTOutputSize, handle->dequantIDCTOutputAlign);
         if (NULL == handle->pDequantIDCTOutputBuf)
         {
            handle->pDequantIDCTOutputBuf = smmMallocAligned(&(handle->extMemorySMM), handle->dequantIDCTOutputSize, handle->dequantIDCTOutputAlign);
         }
      #endif // __SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__

         /// Allocate memory for fragment processor.
      #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
         handle->pFragProcessor = (SWJD_FRAGMENT_PROCESSOR *)smmMallocAligned(&(handle->extMemorySMM), sizeof(SWJD_FRAGMENT_PROCESSOR), 4);
      #else
         handle->pFragProcessor = (SWJD_FRAGMENT_PROCESSOR *)smmMallocAligned(&(handle->intMemorySMM), sizeof(SWJD_FRAGMENT_PROCESSOR), 4);
         if (NULL == handle->pFragProcessor)
         {
            handle->pFragProcessor = (SWJD_FRAGMENT_PROCESSOR *)smmMallocAligned(&(handle->extMemorySMM), sizeof(SWJD_FRAGMENT_PROCESSOR), 4);
         }
      #endif  // __SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__

         /// Reset the restart interval.
         handle->restartInterval = 0;
      }
      break;

      default:
         ASSERT(0);
   }

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}


void jpeg_dec_reset_internal(JPEG_DECODER_HANDLE handle)
{
   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
            handle->codecState = JPEG_CODEC_STATE_IDLE;

            #if defined(__JPEG_DEC_PATCH_FOR_HQA00000732__)
            /// SW workaround for HW bug: HQA00000732
            /// Idle for 1.5ms.
            if (JPEG_STATUS_OK != handle->lastStatus)
            {
               jpeg_dec_hw_patch_for_HQA00000732();
            }
            #endif

            jpeg_drv_dec_sw_reset();

            jpeg_drv_dec_power_off();

            #if defined(__MTK_TARGET__) && (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__))
            {
               /// Stop IDP.
               if (handle->idpKey)
               {
                  if (!idp_jpeg_decode_stop(handle->idpKey))
                  {
                     ASSERT(0);
                  }
               }
            }
            #endif
            break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__
      case JPEG_CODEC_TYPE_SW:
         switch (handle->codecState)
         {
            case JPEG_CODEC_STATE_BUSY:
            {
               /// The SW decoder is decoding; so we change the state to JPEG_CODEC_STATE_STOPPING,
               /// and wait until the state transits to JPEG_CODEC_STATE_IDLE.
               kal_uint32 time_out_counter = 0;

               handle->codecState = JPEG_CODEC_STATE_STOPPING;
               while (JPEG_CODEC_STATE_IDLE != handle->codecState && JPEG_CODEC_STATE_COMPLETE != handle->codecState)
               {
                  /// Polling for at most 500 ms for the worst case of file access.
                  SLEEP(2);
                  if (100 == time_out_counter++)
                  {
                     ASSERT(0);
                     ///handle->codecState = JPEG_CODEC_STATE_ERROR;
                     ///handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
                     ///return handle->lastStatus;
                  }
               }
            }
            break;

            case JPEG_CODEC_STATE_PAUSING:
            {
               /// The SW decoder is pausing; so we wait until the state transits to JPEG_CODEC_STATE_PAUSED.
               kal_uint32 time_out_counter = 0;

               while (handle->codecState != JPEG_CODEC_STATE_PAUSED)
               {
                  /// Polling for at most 500 ms for the worst case of file access.
                  SLEEP(2);
                  if (100 == time_out_counter++)
                  {
                     ASSERT(0);
                     ///handle->codecState = JPEG_CODEC_STATE_ERROR;
                     ///handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
                     ///return handle->lastStatus;
                  }
               }
               handle->codecState = JPEG_CODEC_STATE_IDLE;
            }
            break;

            case JPEG_CODEC_STATE_ERROR:
            case JPEG_CODEC_STATE_COMPLETE:
            case JPEG_CODEC_STATE_PAUSED:
               handle->codecState = JPEG_CODEC_STATE_IDLE;
            break;

            case JPEG_CODEC_STATE_IDLE:
               /// Nothing to do since it is in idle state.
            break;

            default:
               ASSERT(0);
         }

         // Reset Huffman decoder to default state
         huffmanDecResetDecoder(handle->pHuffDecoder);

         // Reset dequant IDCT unit to default state
         dequantIDCTResetUnit(handle->pDequantIDCTUnit);

         // Reset fragment processor to default state
         fragProcessorResetProc(handle->pFragProcessor);
         
      break;

      default:
         ASSERT(0);
         ///handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
         ///return handle->lastStatus;
   }
}


JPEG_STATUS_ENUM jpeg_dec_internal(JPEG_DECODER_HANDLE handle)
{
   JPEG_STATUS_ENUM status;
   
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   kal_bool enableDynamicSwitch = KAL_FALSE;
   kal_bool enableDynamicSwitchExt[2] = {KAL_FALSE, KAL_FALSE};
#endif

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)
   JPEG_DECODER_HANDLE hwAcceleatorHandle;

   if (JPEG_CODEC_TYPE_SW == handle->codecType)
   {
      kal_uint32 enterAcceleator = 1;
      kal_uint32 dec_sys_size, i;
      JPEG_FILE_INFO *fileInfo = &(handle->fileInfo);
      JPEG_FRAME_INFO *frameInfo = &(fileInfo->frameInfo);

      // check rotate angle
   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
      if (JPEG_DECODE_NO_FLIP_ROTATE_CW_0 != handle->rotationAngle)
      {
         enterAcceleator= 0;
      }
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

      // not support non-baseline jpeg
      if (frameInfo->encProcess != JPEG_ENCODE_PROCESS_BASELINE)
      {
         enterAcceleator= 0;
      }

      // enter accelator
      if (enterAcceleator)
      {
         #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
            if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->dstBufferCacheSwitchBehavior)
            {
               if (KAL_TRUE == INT_QueryIsCachedRAM(handle->fsalReadBufferAddr, handle->fsalReadBufferSize))
               {
                  if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->fsalReadBufferAddr))) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED(handle->fsalReadBufferSize)) &&
                      (is_predef_dyna_c_region((kal_uint32)(handle->fsalReadBufferAddr), handle->fsalReadBufferSize)))
                  {
                     dynamic_switch_cacheable_region((void*)&(handle->fsalReadBufferAddr), handle->fsalReadBufferSize, PAGE_NO_CACHE);
                     enableDynamicSwitch = KAL_TRUE;
                  }
                  else
                  {
                     enterAcceleator= 0;
                  }
               }
            }
            else
            {
               if (KAL_TRUE == INT_QueryIsCachedRAM(handle->fsalReadBufferAddr, 4))
               {
                  enterAcceleator= 0;
               }
               if (KAL_TRUE == INT_QueryIsCachedRAM(handle->extMemoryAddr, 4))
               {
                  enterAcceleator= 0;
               }
            }
         #endif

         if (enterAcceleator)
         {
            // get hw encoder      
            if (JPEG_STATUS_OK == jpeg_dec_get_decoder(JPEG_CODEC_TYPE_HW, handle->scenarioType, (JPEG_DECODER_HANDLE *)&(handle->hwAcceleratorHandle)))
            {
               handle->codecType = JPEG_CODEC_TYPE_HW;
      
               hwAcceleatorHandle = (JPEG_DECODER_HANDLE)(handle->hwAcceleratorHandle);
               memcpy(hwAcceleatorHandle, handle, sizeof(JPEG_DECODER));
            }
         }
      }
   }
#elif defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
   handle->useHybridIDCTEnhance = KAL_FALSE;
   if (JPEG_CODEC_TYPE_SW == handle->codecType)
   {
      kal_uint32 enterAcceleator = 1;
      JPEG_FILE_INFO *fileInfo = &(handle->fileInfo);
      JPEG_FRAME_INFO *frameInfo = &(fileInfo->frameInfo);

      // check rotate angle
   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
      if (JPEG_DECODE_NO_FLIP_ROTATE_CW_0 != handle->rotationAngle)
      {
         enterAcceleator= 0;
      }
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

      // not support non-baseline jpeg
      if (frameInfo->encProcess != JPEG_ENCODE_PROCESS_BASELINE)
      {
         enterAcceleator= 0;
      }

      // not support output window with offset case
      if (0 != (handle->outputWnd.x * handle->outputWnd.y))
      {
         enterAcceleator= 0;
      }

      // not support color format transform
      if (handle->canvasFormat != frameInfo->samplingFormat)
      {
         enterAcceleator= 0;
      }

      // not support resize case
      if ((frameInfo->width != handle->outputWnd.w) ||
           (frameInfo->height != handle->outputWnd.h) ||
           (handle->canvasWnd.w != handle->outputWnd.w) ||
           (handle->canvasWnd.h != handle->outputWnd.h) ||
           (handle->canvasWnd.w != (frameInfo->width)) ||
           (handle->canvasWnd.h != (frameInfo->height)))
      {
         enterAcceleator= 0;
      }

      // enter accelator
      if (enterAcceleator)
      {
         // get hw encoder      
         if (0 == handle->hwAcceleratorHandle)
         {
            if (JPEG_STATUS_OK == jpeg_dec_get_decoder(JPEG_CODEC_TYPE_HW, handle->scenarioType, (JPEG_DECODER_HANDLE *)&(handle->hwAcceleratorHandle)))
            {
               //No resize, No Rotation. case
               handle->useHybridIDCTEnhance = KAL_TRUE;
            }
         }
         else
         {
            ASSERT(0);
         }
      }
   }
#endif

   if (JPEG_CODEC_TYPE_SW == handle->codecType)
   {
      #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
         if (NULL == handle->pHuffDecOutputBuf)
         {
            handle->pHuffDecOutputBuf = smmMallocAligned(&(handle->extMemorySMM), handle->huffDecOutputSize, handle->huffDecOutputAlign);
         }
      #else
         if (NULL == handle->pHuffDecOutputBuf)
         {
            handle->pHuffDecOutputBuf = smmMallocAligned(&(handle->intMemorySMM), handle->huffDecOutputSize, handle->huffDecOutputAlign);
            if (NULL == handle->pHuffDecOutputBuf)
            {
               handle->pHuffDecOutputBuf = smmMallocAligned(&(handle->extMemorySMM), handle->huffDecOutputSize, handle->huffDecOutputAlign);
            }
         }
      #endif // __SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__
   }
#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)
   else
   {
      if (NULL == handle->hwDecodeSysBufferAddr[0])
      {
         handle->hwDecodeSysBufferTotalSize = smmGetFreeSpaceAligned(&(handle->extMemorySMM), 32);
         if (64 <= handle->hwDecodeSysBufferTotalSize)
         {
            handle->hwDecodeSysBufferTotalSize = (handle->hwDecodeSysBufferTotalSize >> 1) & (~31);
            handle->hwDecodeSysBufferAddr[0] = (kal_uint8 *)smmMallocAligned(&(handle->extMemorySMM), handle->hwDecodeSysBufferTotalSize, 32);
            if (NULL == handle->hwDecodeSysBufferAddr[0])
            {
               ASSERT(0);
            }
            handle->hwDecodeSysBufferAddr2[0] = (kal_uint8 *)smmMallocAligned(&(handle->extMemorySMM), handle->hwDecodeSysBufferTotalSize, 32);
            if (NULL == handle->hwDecodeSysBufferAddr2[0])
            {
               ASSERT(0);
            }
         }
         else
         {
            ASSERT(0);
         }
      }

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
      if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->dstBufferCacheSwitchBehavior)
      {
         if (KAL_TRUE == INT_QueryIsCachedRAM(handle->hwDecodeSysBufferAddr[0], handle->hwDecodeSysBufferTotalSize))
         {
            if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr[0]))) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferTotalSize)) &&
                (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr[0]), handle->hwDecodeSysBufferTotalSize)))
            {
               dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr[0]), handle->hwDecodeSysBufferTotalSize, PAGE_NO_CACHE);
               enableDynamicSwitchExt[0] = KAL_TRUE;
            }
            else
            {
               ASSERT(0);
            }
         }
         if (KAL_TRUE == INT_QueryIsCachedRAM(handle->hwDecodeSysBufferAddr2[0], handle->hwDecodeSysBufferTotalSize))
         {
            if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr2[0]))) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferTotalSize)) &&
                (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr2[0]), handle->hwDecodeSysBufferTotalSize)))
            {
               dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr2[0]), handle->hwDecodeSysBufferTotalSize, PAGE_NO_CACHE);
               enableDynamicSwitchExt[1] = KAL_TRUE;
            }
            else
            {
               ASSERT(0);
            }
         }
      }
      else
      {
         if (KAL_TRUE == INT_QueryIsCachedRAM(handle->hwDecodeSysBufferAddr[0], 4))
         {
            ASSERT(0);
         }
         if (KAL_TRUE == INT_QueryIsCachedRAM(handle->hwDecodeSysBufferAddr2[0], 4))
         {
            ASSERT(0);
         }
      }
#endif
   }
#endif
      
   /// Reseek file to the correct position.
   if (JPEG_STATUS_OK == jpeg_dec_post_parsing(handle))
   {
   #if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
   #endif

      switch (handle->codecType)
      {
      #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
         {
            kal_int32 i;
            JPEG_FILE_INFO *fileInfo = &(handle->fileInfo);
            JPEG_FRAME_INFO *frameInfo = &(fileInfo->frameInfo);

            for (i = frameInfo->numberOfComponents; --i >= 0; )
            {
               kal_uint32 comp_h_count = (frameInfo->hSamplingFactorMax / frameInfo->frameComponentInfo[i].hSamplingFactor) * 8;
               kal_uint32 comp_v_count = (frameInfo->vSamplingFactorMax / frameInfo->frameComponentInfo[i].vSamplingFactor) * 8;

               handle->hwDUPerMCURow[i] = frameInfo->mcuPerRow * frameInfo->frameComponentInfo[i].hSamplingFactor;
               handle->hwDummyDU[i] = (frameInfo->paddedWidth - frameInfo->width) *
                                       frameInfo->frameComponentInfo[i].hSamplingFactor /
                                       frameInfo->hSamplingFactorMax / 8;

               handle->hwTotalDU[i] = ((frameInfo->width  + comp_h_count - 1) / comp_h_count) *
                                       ((frameInfo->height + comp_v_count - 1) / comp_v_count);
            }

            status = jpeg_dec_hw_internal(handle);

            #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
               if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->dstBufferCacheSwitchBehavior)
               {
                  if ((KAL_TRUE == enableDynamicSwitch) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->fsalReadBufferAddr))) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED(handle->fsalReadBufferSize)) &&
                      (is_predef_dyna_c_region((kal_uint32)(handle->fsalReadBufferAddr), handle->fsalReadBufferSize)))
                  {
                     if(KAL_TRUE == INT_QueryIsNonCachedRAM(handle->fsalReadBufferAddr, handle->fsalReadBufferSize))
                     {
                        dynamic_switch_cacheable_region((void*)&(handle->fsalReadBufferAddr), handle->fsalReadBufferSize, PAGE_CACHEABLE);
                        enableDynamicSwitch = KAL_FALSE;
                     }
                  }
               }
            #endif

            #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
               if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == handle->dstBufferCacheSwitchBehavior)
               {
                  if ((KAL_TRUE == enableDynamicSwitchExt[0]) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr[0]))) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferTotalSize)) &&
                      (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr[0]), handle->hwDecodeSysBufferTotalSize)))
                  {
                     if(KAL_TRUE == INT_QueryIsNonCachedRAM(handle->hwDecodeSysBufferAddr[0], handle->hwDecodeSysBufferTotalSize))
                     {
                        dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr[0]), handle->hwDecodeSysBufferTotalSize, PAGE_CACHEABLE);
                        enableDynamicSwitchExt[0] = KAL_FALSE;
                     }
                  }
                  if ((KAL_TRUE == enableDynamicSwitchExt[1]) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr2[0]))) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferTotalSize)) &&
                      (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr2[0]), handle->hwDecodeSysBufferTotalSize)))
                  {
                     if(KAL_TRUE == INT_QueryIsNonCachedRAM(handle->hwDecodeSysBufferAddr2[0], handle->hwDecodeSysBufferTotalSize))
                     {
                        dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr2[0]), handle->hwDecodeSysBufferTotalSize, PAGE_CACHEABLE);
                        enableDynamicSwitchExt[1] = KAL_FALSE;
                     }
                  }
               }
            #endif
            
#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)
            // release accelerator
            if (handle->hwAcceleratorHandle)
            {
               /// After the execution of jpeg_dec_sw_internal, invoke the callback function.
               if (handle->callback_function)
               {
                  handle->callback_function(handle->codecState);
               }
            
               if (JPEG_STATUS_OK != jpeg_dec_release_decoder((JPEG_DECODER_HANDLE)handle->hwAcceleratorHandle))
               {
                  ASSERT(0);
               }
               handle->hwAcceleratorHandle = 0;
               handle->codecType = JPEG_CODEC_TYPE_SW;
            }
#endif

            #if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
            #endif

            return status;
         }
      #endif

         case JPEG_CODEC_TYPE_SW:
         {
         #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
            {
               if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == (handle->dstBufferCacheSwitchBehavior))
               {
                  kal_uint32 canvasSize = (handle->canvasWnd.w) * (handle->canvasWnd.h) * (handle->canvasBytesPerPixel);

                  if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->canvasBuffer[0]))) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED(canvasSize)) &&
                      (is_predef_dyna_c_region((kal_uint32)(handle->canvasBuffer[0]), canvasSize)))
                  {
                     if (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->canvasBuffer[0], canvasSize))
                     {
                        dynamic_switch_cacheable_region((void*)&(handle->canvasBuffer[0]), canvasSize, PAGE_CACHEABLE);
                        enableDynamicSwitch = KAL_TRUE;
                     }
                  }

                  if (JPEG_YUV_FORMAT_YUV420 == handle->canvasFormat)
                  {
                     canvasSize >>= 2;

                     if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->canvasBuffer[1]))) &&
                         (IS_CACHE_LINE_SIZE_ALIGNED(canvasSize)) &&
                         (is_predef_dyna_c_region((kal_uint32)(handle->canvasBuffer[1]), canvasSize)))
                     {
                        if (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->canvasBuffer[1], canvasSize))
                        {
                           dynamic_switch_cacheable_region((void*)&(handle->canvasBuffer[1]), canvasSize, PAGE_CACHEABLE);
                           enableDynamicSwitch = KAL_TRUE;
                        }
                     }

                     if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->canvasBuffer[2]))) &&
                         (IS_CACHE_LINE_SIZE_ALIGNED(canvasSize)) &&
                         (is_predef_dyna_c_region((kal_uint32)(handle->canvasBuffer[2]), canvasSize)))
                     {
                        if (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->canvasBuffer[2], canvasSize))
                        {
                           dynamic_switch_cacheable_region((void*)&(handle->canvasBuffer[2]), canvasSize, PAGE_CACHEABLE);
                           enableDynamicSwitch = KAL_TRUE;
                        }
                     }
                  }
               }
            }
            #endif

            if (JPEG_STATUS_OK != jpeg_dec_sw_initialize(handle))
            {
#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
               // release accelerator
               if (handle->hwAcceleratorHandle)
               {
                  if (JPEG_STATUS_OK != jpeg_dec_release_decoder((JPEG_DECODER_HANDLE)handle->hwAcceleratorHandle))
                  {
                     ASSERT(0);
                  }
                  handle->hwAcceleratorHandle = 0;
               }
#endif
               return handle->lastStatus;
            }

            handle->codecState = JPEG_CODEC_STATE_BUSY;

#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
            if (handle->hwAcceleratorHandle)
            {
               if (JPEG_STATUS_OK !=  jpeg_dec_hw_hybrid_internal(handle))
               {
                  // release accelerator
                  if (JPEG_STATUS_OK != jpeg_dec_release_decoder((JPEG_DECODER_HANDLE)handle->hwAcceleratorHandle))
                  {
                     ASSERT(0);
                  }
                  handle->hwAcceleratorHandle = 0;
                  return handle->lastStatus;
               }
            }
#endif 

            #if defined(__MTK_TARGET__)
            {
               /// try to switch stack for better performance
               kal_uint32 stack_size = JPEG_STACK_SIZE;
               void *stack_ptr = drv_gfx_stkmgr_get_stack(stack_size);

               if (stack_ptr)
               {
                  extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
                  INT_SwitchStackToRun(stack_ptr, stack_size, (kal_func_ptr)jpeg_dec_sw_internal, 1, handle);
                  drv_gfx_stkmgr_release_stack(stack_ptr);
               }
               else
               {
                  jpeg_dec_sw_internal(handle);
               }
            }
            #else
            {
               jpeg_dec_sw_internal(handle);
            }
            #endif

            #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
            {
               kal_uint32 canvasSize = (handle->canvasWnd.w) * (handle->canvasWnd.h) * (handle->canvasBytesPerPixel);

               if ((KAL_TRUE == enableDynamicSwitch) &&
                   (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->canvasBuffer[0]))) &&
                   (IS_CACHE_LINE_SIZE_ALIGNED(canvasSize)) &&
                   (is_predef_dyna_c_region((kal_uint32)(handle->canvasBuffer[0]), canvasSize)))
               {
                  if(KAL_TRUE == INT_QueryIsCachedRAM(handle->canvasBuffer[0], canvasSize))
                  {
                     dynamic_switch_cacheable_region((void*)&(handle->canvasBuffer[0]), canvasSize, PAGE_NO_CACHE);
                  }
               }

               if (JPEG_YUV_FORMAT_YUV420 == handle->canvasFormat)
               {
                  canvasSize >>= 2;

                  if ((KAL_TRUE == enableDynamicSwitch) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->canvasBuffer[1]))) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED(canvasSize)) &&
                      (is_predef_dyna_c_region((kal_uint32)(handle->canvasBuffer[1]), canvasSize)))
                  {
                     if(KAL_TRUE == INT_QueryIsCachedRAM(handle->canvasBuffer[1], canvasSize))
                     {
                        dynamic_switch_cacheable_region((void*)&(handle->canvasBuffer[1]), canvasSize, PAGE_NO_CACHE);
                     }
                  }

                  if ((KAL_TRUE == enableDynamicSwitch) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->canvasBuffer[2]))) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED(canvasSize)) &&
                      (is_predef_dyna_c_region((kal_uint32)(handle->canvasBuffer[2]), canvasSize)))
                  {
                     if(KAL_TRUE == INT_QueryIsCachedRAM(handle->canvasBuffer[2], canvasSize))
                     {
                        dynamic_switch_cacheable_region((void*)&(handle->canvasBuffer[2]), canvasSize, PAGE_NO_CACHE);
                     }
                  }
               }
            }
            #endif

            /// After the execution of jpeg_dec_sw_internal, invoke the callback function.
            if (handle->callback_function)
            {
               handle->callback_function(handle->codecState);
            }

#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
            // release accelerator
            if (handle->hwAcceleratorHandle)
            {
               if (JPEG_STATUS_OK != jpeg_dec_release_decoder((JPEG_DECODER_HANDLE)handle->hwAcceleratorHandle))
               {
                  ASSERT(0);
               }
               handle->hwAcceleratorHandle = 0;
            }
#endif
         }
         break;
         default:
            ASSERT(0);
            handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
            return handle->lastStatus;
      }

      #if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
      #endif
   }
   else
   {
#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)  
      /// handle parsing error      
      if (handle->hwAcceleratorHandle)
      {
         if (JPEG_STATUS_OK != jpeg_dec_release_decoder((JPEG_DECODER_HANDLE)handle->hwAcceleratorHandle))
         {
            ASSERT(0);
         }
         handle->hwAcceleratorHandle = 0;
      }
#endif      
   }
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpeg_dec_get_decoder(JPEG_CODEC_TYPE_ENUM codecType, JPEG_SCENARIO_TYPE_ENUM scenarioType, JPEG_DECODER_HANDLE *handlePtr)
{
   JPEG_DECODER_HANDLE handle = NULL;

   switch (codecType)
   {
      case JPEG_CODEC_TYPE_HW:
         #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         {
            handle = jpeg_dec_hw_lock_handle();

            if (NULL == handle)
            {
               /// The desired HW is already in use.
               *handlePtr = NULL;
               return JPEG_STATUS_CODEC_UNAVAILABLE;
            }

            #if defined(__MTK_TARGET__)
            {
               if (!drv_gfx_open_dct(DCT_USER_JPEG_DECODER))
               {
                  memset(handle, 0, sizeof(JPEG_DECODER));
                  return JPEG_STATUS_CODEC_UNAVAILABLE;
               }

               #if defined(MJPG_DECODE) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__))
                  #if defined(__DRV_GRAPHICS_JPEG_6256_SERIES__)
                     // must set mdp scenario before mdp is opened.
                     if (JPEG_SCENARIO_TYPE_MJPEG == scenarioType)
                     {
                        idp_jpeg_decode_mjpg_mode_enable();
                     }
                     else
                     {
                        idp_jpeg_decode_mjpg_mode_disable();
                     }
                  #endif
               #endif

// temporal solution for jpeg decoder
#if (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__))
               if (!idp_jpeg_decode_open(&handle->idpKey))
               {
                  drv_gfx_close_dct(DCT_USER_JPEG_DECODER);

                  /// The IDP is unavailable, return error.
                  memset(handle, 0, sizeof(JPEG_DECODER));
                  return JPEG_STATUS_CODEC_UNAVAILABLE;
               }
#endif
            }
            #endif
         }
         break;
         #else
         {
            *handlePtr = NULL;
            return JPEG_STATUS_CODEC_UNAVAILABLE;
         }
         #endif

      case JPEG_CODEC_TYPE_SW:
         handle = (JPEG_DECODER_HANDLE)malloc(sizeof(JPEG_DECODER));
         memset(handle, 0, sizeof(JPEG_DECODER));

         /// Check for alignment.
         if ((kal_uint32)handle & 0x3)
         {
            ASSERT(0);
         }

         /// Initialize Y2R table.
         {
            extern void iul_y2r_table_init(void);
            iul_y2r_table_init();
         }
      break;

      default:
         ASSERT(0);
         ///*handlePtr = NULL;
         ///return JPEG_STATUS_CODEC_UNAVAILABLE;
   }

   handle->codecType = codecType;
   handle->scenarioType = scenarioType;
   handle->codecState = JPEG_CODEC_STATE_IDLE;
   *handlePtr = handle;

   #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
      if (JPEG_CODEC_TYPE_HW == codecType)
      {
         jpeg_drv_init();
      }
   #endif

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpeg_dec_release_decoder(JPEG_DECODER_HANDLE handle)
{
   JPEG_STATUS_ENUM status = JPEG_STATUS_OK;

   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   #if defined(DRV_FEATURE__MM_INTMEM_IF)
   {
      mm_scen_id_t mmScenId = MM_SCEN__JPEG_DECODE;

      #if defined(MJPG_DECODE)
         #if defined(__DRV_GRAPHICS_JPEG_6256_SERIES__) || defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)
            // only separate mm internal memory mode for 56 mjpeg
            if (JPEG_SCENARIO_TYPE_MJPEG == handle->scenarioType)
            {
               mmScenId = MM_SCEN__MJPEG_DECODE;
            }
         #endif
      #endif

      if (handle->intMemoryAddr)
      {
         mm_intmem_free(mmScenId, MM_INTMEM_SEG__JPEG_DEC);
         handle->intMemoryAddr = NULL;
         handle->intMemorySize = 0;
      }
   }
   #endif  // defined(DRV_FEATURE__MM_INTMEM_IF)

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
            jpeg_drv_dec_power_off();

            #if defined(__MTK_TARGET__)
            {
#if (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__))
               /// Release the control of IDP.
               if (handle->idpKey)
               {
                  if (!idp_jpeg_decode_close(handle->idpKey))
                  {
                     ASSERT(0);
                     ///status = JPEG_STATUS_IDP_ERROR;
                  }
               }
#endif

               drv_gfx_close_dct(DCT_USER_JPEG_DECODER);
            }
            #endif
            memset(handle, 0, sizeof(JPEG_DECODER));
         break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__

      case JPEG_CODEC_TYPE_SW:
         #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
            {
               if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == (handle->dstBufferCacheSwitchBehavior))
               {
                  if ((KAL_TRUE == handle->extMemorySwitched) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->extMemoryAddr))) &&
                      (IS_CACHE_LINE_SIZE_ALIGNED(handle->extMemorySize)) &&
                      (is_predef_dyna_c_region((kal_uint32)(handle->extMemoryAddr), handle->extMemorySize)))
                  {
                     if(KAL_TRUE == INT_QueryIsCachedRAM(handle->extMemoryAddr, handle->extMemorySize))
                     {
                        dynamic_switch_cacheable_region((void*)&(handle->extMemoryAddr), handle->extMemorySize, PAGE_NO_CACHE);
                     }
                  }
               }
            }
         #endif
         free(handle);
      break;

      default:
         ASSERT(0);
   }

   return status;
}


