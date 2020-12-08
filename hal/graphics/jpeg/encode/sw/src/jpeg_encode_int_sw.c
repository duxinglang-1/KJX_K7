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
 *   jpeg_encode_int_sw.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_jpeg.h"

#if defined(__SW_JPEG_ENCODER_SUPPORT__)

#include "kal_general_types.h"

#include "fsal.h"
#include "iul_x_math.h"

#include "string.h"

#include "jpeg_enum.h"
#include "jpeg_encode_structure.h"
#include "jpeg_marker.h"
#include "jpeg_encode_int.h"
#include "jpeg_mem_int.h"

#include "swje_structure.h"
#include "swje_const_tables.h"
#include "swje_fragment_processor.h"
#include "swje_fdct_quant_unit.h"
#include "swje_huffman_encoder.h"

#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
   #include "jpeg_drv_api.h"
   #include "jpeg_drv_6250_series.h"
#endif

#if defined(EXIF_SUPPORT)
   #include "exif_enc_enum.h"
   #include "exif_enc_structure.h"
   #include "exif_enc_tag.h"
   #include "exif_enc_api.h"
   #include "exif_enc_wrapper.h"
   #include "exif.h"
#endif  /// End of #if defined(EXIF_SUPPORT)

#if defined(JPEG_CODEC_STANDALONE)
   #include <assert.h>
   #if !defined(ASSERT)
      #define ASSERT assert
   #endif
#else
   #include "kal_public_api.h"
#endif


//#define __JPEG_MCU_BASED_DCT__


///#if defined(__MTK_TARGET__) && !defined(__SW_JPEG_CODEC_USING_CACHEABLE_MEMORY__)
///   #pragma arm section rwdata = "INTSRAM_RW", zidata = "INTSRAM_ZI"
///      static JPEG_ENCODER _jpeg_sw_encoder = {0};
///   #pragma arm section rwdata , zidata
///
///   void jpeg_enc_sw_get_handle(JPEG_ENCODER_HANDLE *handle)
///   {
///      *handle = &_jpeg_sw_encoder;
///   }
///#endif

//#define __JPEG_SWLA_DEBUG__
#if defined(__MTK_TARGET__) && defined(__JPEG_SWLA_DEBUG__)
#define JPEG_SWLA_LOG(tag,start) SLA_CustomLogging((tag), (start));
#else
#define JPEG_SWLA_LOG(tag,start)
#endif

//#define __JPEG_TIMER_DEBUG__
#if defined(__MTK_TARGET__) && defined(__JPEG_TIMER_DEBUG__)
#define MAX_ENCODE_CNT  100
kal_uint32 u4EncodeCount = 0;
kal_uint32 u4EncodeStartTime, u4EncodeTime[MAX_ENCODE_CNT];
#endif

static void _jpeg_enc_sw_emit_uint8(kal_uint8 c, SWJE_FILE *handleDstFile)
{
   if((handleDstFile->dstBufferLeft) > 0)
   {
      *(handleDstFile->dstWritePtr)++ = c;
      (handleDstFile->dstBufferLeft)--;
   }
   else
   {
      if(NULL != (handleDstFile->pDstFileHandle))
      {
          if(SWJE_ERROR_STATUS_WRITE_TO_FILE_ERROR != (handleDstFile->dstBufferLeft))
          {
             if (FSAL_OK != FSAL_Direct_Write((handleDstFile->pDstFileHandle), (handleDstFile->dstBufferAddr), (handleDstFile->dstBufferSize)))
             {
                handleDstFile->dstBufferLeft = SWJE_ERROR_STATUS_WRITE_TO_FILE_ERROR;
             }
             else
             {
                *((kal_uint8 *)handleDstFile->dstBufferAddr) = c;
                handleDstFile->dstWritePtr = ((kal_uint8 *)handleDstFile->dstBufferAddr) + 1;
                handleDstFile->dstBufferLeft = handleDstFile->dstBufferSize - 1;
             }
          }
      }
      else
      {
         handleDstFile->dstBufferLeft = SWJE_ERROR_STATUS_WRITE_TO_MEMORY_ERROR;
      }
   }
}



static void _jpeg_enc_sw_emit_uint16(kal_uint16 c, SWJE_FILE *handleDstFile)
{
   _jpeg_enc_sw_emit_uint8((kal_uint8)((c >> 8) & 0xFF), handleDstFile);
   _jpeg_enc_sw_emit_uint8((kal_uint8)(c & 0xFF), handleDstFile);
}



/// Emit a marker code
#define JPEG_ENC_SW_EMIT_MARKER(mark, dstWritePtr, dstBufferLeft, handleDstFile)      \
do                                                                                     \
  {                                                                                    \
     JPEG_ENC_SW_EMIT_UINT8(0xFF, dstWritePtr, dstBufferLeft, handleDstFile);          \
     JPEG_ENC_SW_EMIT_UINT8(mark, dstWritePtr, dstBufferLeft, handleDstFile);          \
} while (0)



static void _jpeg_enc_sw_emit_marker(kal_uint8 mark, SWJE_FILE *handleDstFile)
{
   _jpeg_enc_sw_emit_uint8(0xFF, handleDstFile);
   _jpeg_enc_sw_emit_uint8(mark, handleDstFile);
}



/// Emit a DQT
static void _jpeg_enc_sw_emit_dqt(kal_uint8 quantTableID, SWJE_FILE *handleDstFile, JPEG_ENCODER_HANDLE handle)
{
   register kal_int16 *quantTable = handle->QuantTables[quantTableID].pIntQuantTable;
   register kal_int32 i = 64;

   _jpeg_enc_sw_emit_marker(JPEG_MARKER_DQT, handleDstFile);

   _jpeg_enc_sw_emit_uint16((64 + 1 + 2), handleDstFile);

   _jpeg_enc_sw_emit_uint8(quantTableID, handleDstFile);

   while (--i >= 0)
   {
      _jpeg_enc_sw_emit_uint8((kal_uint8)((*quantTable) & 0xFF), handleDstFile);
      quantTable++;
   }
}

/// Emit a DHT
static void _jpeg_enc_sw_emit_dht(SWJE_HUFF_TABLE *huffTable, SWJE_FILE *handleDstFile)
{
   kal_uint32 length = 0;
   kal_uint32 i;

   _jpeg_enc_sw_emit_marker(JPEG_MARKER_DHT, handleDstFile);

   i = 17;
   while(--i > 0)
   {
      length += huffTable->pBits[i];
   }
   _jpeg_enc_sw_emit_uint16((kal_uint16)(length + 2 + 1 + 16), handleDstFile);

   _jpeg_enc_sw_emit_uint8((kal_uint8)(((huffTable->type) << 4) | (huffTable->huffTableID)), handleDstFile);

   for (i = 1; i <= 16; i++)
   {
      _jpeg_enc_sw_emit_uint8(huffTable->pBits[i], handleDstFile);
   }

   for (i = 0; i < length; i++)
   {
      _jpeg_enc_sw_emit_uint8(huffTable->pHuffValue[i], handleDstFile);
   }
}



/// Only when NULL != (handleDstFile->pDstFileHandle)
static void _jpeg_enc_sw_flush_to_file(SWJE_FILE *handleDstFile)
{
   if((handleDstFile->dstWritePtr) != (handleDstFile->dstBufferAddr))
   {
       kal_uint32 size = ((handleDstFile->dstBufferSize) - (handleDstFile->dstBufferLeft));

       if (FSAL_OK != FSAL_Direct_Write((handleDstFile->pDstFileHandle), (handleDstFile->dstBufferAddr), size))
       {
          handleDstFile->dstBufferLeft = SWJE_ERROR_STATUS_WRITE_TO_FILE_ERROR;
       }
       else
       {
          handleDstFile->dstWritePtr = handleDstFile->dstBufferAddr;
          handleDstFile->dstBufferLeft = handleDstFile->dstBufferSize;
       }
   }
}



static JPEG_STATUS_ENUM _jpeg_enc_sw_write_file_header(JPEG_ENCODER_HANDLE handle)
{
   SWJE_FILE *handleDstFile = &(handle->dstFile);

   /// SOI
   _jpeg_enc_sw_emit_marker(JPEG_MARKER_SOI, handleDstFile);

   if((handleDstFile->dstBufferLeft) < 0)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
      return handle->lastStatus;
   }
   return JPEG_STATUS_OK;
}



static JPEG_STATUS_ENUM _jpeg_enc_sw_write_file_trailer(JPEG_ENCODER_HANDLE handle)
{
   SWJE_FILE *handleDstFile = &(handle->dstFile);

   /// EOI
   _jpeg_enc_sw_emit_marker(JPEG_MARKER_EOI, handleDstFile);

   if((handleDstFile->dstBufferLeft) < 0)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
      return handle->lastStatus;
   }
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpeg_enc_sw_write_frame_header(JPEG_ENCODER_HANDLE handle)
{
   SWJE_FILE *handleDstFile = &(handle->dstFile);
   JPEG_GENGERAL_ENCODE_INFO* const gengralEncodeInfo = &(handle->gengralEncodeInfo);
   JPEG_ENCODE_INFO* const curEncodeInfo = handle->curEncodeInfo;
   SWJE_FDCT_QUANT_UNIT * const pFDCTQuant = handle->pFDCTQuantUnits;

   kal_uint32 i;

   /// DQT
   /// We have 2 tables, one for luminance,the other for chrominance
   _jpeg_enc_sw_emit_dqt(0, handleDstFile, handle);
   _jpeg_enc_sw_emit_dqt(1, handleDstFile, handle);

   /// SOF
   _jpeg_enc_sw_emit_marker(JPEG_MARKER_SOF0, handleDstFile);
   _jpeg_enc_sw_emit_uint16(((kal_uint16)(3 * (gengralEncodeInfo->numComponent) + 2 + 5 + 1)), handleDstFile);   /// Length
   _jpeg_enc_sw_emit_uint8(8, handleDstFile);                                                                    /// data precision
   _jpeg_enc_sw_emit_uint16((kal_uint16)(curEncodeInfo->dstHeight), handleDstFile);
   _jpeg_enc_sw_emit_uint16((kal_uint16)(curEncodeInfo->dstWidth), handleDstFile);
   _jpeg_enc_sw_emit_uint8(((kal_uint8)gengralEncodeInfo->numComponent), handleDstFile);

   for (i = 0; i < (gengralEncodeInfo->numComponent); i++)
   {
      _jpeg_enc_sw_emit_uint8((kal_uint8)(i + 1), handleDstFile);                                                /// Component ID
      _jpeg_enc_sw_emit_uint8((kal_uint8)(((gengralEncodeInfo->hSamplingFactor[i] << 4) | gengralEncodeInfo->vSamplingFactor[i]) & 0xFF ),   /// Sample factor
                             handleDstFile);
      _jpeg_enc_sw_emit_uint8((kal_uint8)(pFDCTQuant[i].quantTableItems.quantTableID), handleDstFile);           /// Quant ID
   }

   if((handleDstFile->dstBufferLeft) < 0)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
      return handle->lastStatus;
   }
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpeg_enc_sw_write_scan_header(JPEG_ENCODER_HANDLE handle)
{
   SWJE_FILE *handleDstFile = &(handle->dstFile);
   SWJE_HUFFMAN_ENCODER * const pHuffEncoder = handle->pHuffEncoder;
   kal_uint32 numComponent = handle->gengralEncodeInfo.numComponent;

   kal_uint32 length = 2 * numComponent + 2 + 1 + 3;
   kal_uint32 i;

   /// DRI
   _jpeg_enc_sw_emit_marker(JPEG_MARKER_DRI, handleDstFile);
   _jpeg_enc_sw_emit_uint16((kal_uint16)(4), handleDstFile);
   /// We add a trick for JPEG_ENCODE_DRI_NUMBER_0. So this need another setting
   if(JPEG_ENCODE_DRI_NUMBER_0 != handle->driNum)
   {
      _jpeg_enc_sw_emit_uint16((kal_uint16)(handle->driNum), handleDstFile);
   }
   else
   {
      ///handle->driNum = 0
      _jpeg_enc_sw_emit_uint16(0, handleDstFile);
   }

   /// DHT
   _jpeg_enc_sw_emit_dht(&(handle->huffTables[0]), handleDstFile);   /// Luminance DC Huffman table
   _jpeg_enc_sw_emit_dht(&(handle->huffTables[1]), handleDstFile);   /// Luminance AC Huffman table
   _jpeg_enc_sw_emit_dht(&(handle->huffTables[2]), handleDstFile);   /// Chrominance DC Huffman table
   _jpeg_enc_sw_emit_dht(&(handle->huffTables[3]), handleDstFile);   /// Chrominance AC Huffman table

   /// SOS
   _jpeg_enc_sw_emit_marker(JPEG_MARKER_SOS, handleDstFile);

   _jpeg_enc_sw_emit_uint16((kal_uint16)length, handleDstFile);
   _jpeg_enc_sw_emit_uint8((kal_uint8)numComponent, handleDstFile);

   for (i = 0; i < numComponent; i++)
   {
      SWJE_HUFFMAN_COMPONENT *huffComponent = &(pHuffEncoder->huffComponent[i]);

      _jpeg_enc_sw_emit_uint8((kal_uint8)(i + 1), handleDstFile);   /// component id
      _jpeg_enc_sw_emit_uint8((kal_uint8)(((huffComponent->pDCHuffTable->huffTableID) << 4) | (huffComponent->pACHuffTable->huffTableID)),
                             handleDstFile);
   }

   _jpeg_enc_sw_emit_uint8(0, handleDstFile);                       /// Spectral selection start
   _jpeg_enc_sw_emit_uint8(64 - 1, handleDstFile);                  /// Spectral selection end
   _jpeg_enc_sw_emit_uint8(0, handleDstFile);                       ///Successive approximation

   if((handleDstFile->dstBufferLeft) < 0)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
      return handle->lastStatus;
   }
   return JPEG_STATUS_OK;
}



static JPEG_STATUS_ENUM _jpeg_enc_sw_emit_rst(JPEG_ENCODER_HANDLE handle)
{
   SWJE_FILE *handleDstFile = &(handle->dstFile);
   register kal_uint8 *dstWritePtr = handleDstFile->dstWritePtr;
   register kal_int32 dstBufferLeft = handleDstFile->dstBufferLeft;

   /// RST
   JPEG_ENC_SW_EMIT_MARKER((kal_uint8)(JPEG_MARKER_RST0 + (handle->curRstNum)), dstWritePtr, dstBufferLeft, handleDstFile);
   handle->curRstNum++;
   handle->curRstNum %= 8;

   handleDstFile->dstWritePtr = dstWritePtr;
   handleDstFile->dstBufferLeft = dstBufferLeft;

   if(dstBufferLeft < 0)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
      return handle->lastStatus;
   }
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpeg_enc_sw_init_gereral(JPEG_ENCODER_HANDLE handle)
{
   #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)
      if (JPEG_CODEC_TYPE_SW != handle->codecType)
      {
         /// Quality
         handle->driNum = JPEG_ENCODE_DRI_NUMBER_0;
   
         switch(handle->dstQuality)
         {
            case JPEG_ENCODE_QUALITY_POOR:
               handle->dstQualityDevider = 0;
            break;
            case JPEG_ENCODE_QUALITY_LOW:
               handle->dstQualityDevider = 0;
            break;
            case JPEG_ENCODE_QUALITY_FAIR:
               handle->dstQualityDevider = 1;
            break;
            case JPEG_ENCODE_QUALITY_GOOD:
               handle->dstQualityDevider = 2;
            break;
            case JPEG_ENCODE_QUALITY_EXCELLENT:
               handle->dstQualityDevider = 3;
            break;
         }
      }
      else
   #endif
   {
      handle->driNum = JPEG_ENCODE_DRI_NUMBER;

      /// Quality
      switch(handle->dstQuality)
      {
         case JPEG_ENCODE_QUALITY_POOR:
            handle->dstQualityDevider = 4;
         break;
         case JPEG_ENCODE_QUALITY_LOW:
            handle->dstQualityDevider = 3;
         break;
         case JPEG_ENCODE_QUALITY_FAIR:
            handle->dstQualityDevider = 2;
         break;
         case JPEG_ENCODE_QUALITY_GOOD:
            handle->dstQualityDevider = 1;
         break;
         case JPEG_ENCODE_QUALITY_EXCELLENT:
            handle->dstQualityDevider = 0;
         break;
      }
   }

   /// Initialize the Quant-FDCT processor.
   {
      SWJE_FDCT_QUANT_UNIT * const pFDCTQuant = handle->pFDCTQuantUnits;
      
      #if defined(__DRV_GRAPHICS_HW_JPEG_ENCODE_SEPARATED_FROM_MDP__)
            if (JPEG_CODEC_TYPE_SW != handle->codecType)
            {
               swjeFDCTQuantGenStdQuantTable(&(handle->QuantTables[0]), 0, SWJE_QUANT_TABLE_LUMINANCE_1, handle->dstQualityDevider,
                                             KAL_FALSE, 0);
               swjeFDCTQuantGenStdQuantTable(&(handle->QuantTables[1]), 1, SWJE_QUANT_TABLE_CHROMINANCE_1, handle->dstQualityDevider,
                                             KAL_FALSE, 0);
            }
            else
      #endif
      {
         #ifdef __SW_JPEG_ENC_V2_USING_INTERNAL_MEMORY__
            memcpy(handle->zZagTable, &swje_z_zag_table[0], 64 * 4);
         #else
            handle->zZagTable = (kal_uint32 *)&swje_z_zag_table[0];
         #endif

         swjeFDCTQuantSetZZagTable(&(pFDCTQuant[0]), (handle->zZagTable));
         swjeFDCTQuantSetZZagTable(&(pFDCTQuant[1]), (handle->zZagTable));
         swjeFDCTQuantSetZZagTable(&(pFDCTQuant[2]), (handle->zZagTable));
                  
         #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_DYNAMIC_QUALITY_ADJUSTMENT)
            swjeFDCTQuantGenNonStdQuantTable(&(handle->QuantTables[0]), 0, SWJE_QUANT_TABLE_LUMINANCE_1, handle->dstQualityDevider,
                                             handle->enableDynamicQuantAdjustment, handle->quantScaleFactor);
            swjeFDCTQuantGenNonStdQuantTable(&(handle->QuantTables[1]), 1, SWJE_QUANT_TABLE_CHROMINANCE_1, handle->dstQualityDevider,
                                             handle->enableDynamicQuantAdjustment, handle->quantScaleFactor);                                
         #else
            swjeFDCTQuantGenNonStdQuantTable(&(handle->QuantTables[0]), 0, SWJE_QUANT_TABLE_LUMINANCE_1, handle->dstQualityDevider,
                                             KAL_FALSE, 0);
            swjeFDCTQuantGenNonStdQuantTable(&(handle->QuantTables[1]), 1, SWJE_QUANT_TABLE_CHROMINANCE_1, handle->dstQualityDevider,
                                             KAL_FALSE, 0);
         #endif
      }     

      swjeFDCTQuantSetQuantTable(&(pFDCTQuant[0]), &(handle->QuantTables[0]));      
      swjeFDCTQuantSetQuantTable(&(pFDCTQuant[1]), &(handle->QuantTables[1]));
      swjeFDCTQuantSetQuantTable(&(pFDCTQuant[2]), &(handle->QuantTables[1]));

      /// Use the same working buffer. Due to we won't encode 3 component DU at the same time
      swjeFDCTQuantSetFDCTDstBuffer(&(pFDCTQuant[0]), handle->pWorkingBuffer);
      swjeFDCTQuantSetFDCTDstBuffer(&(pFDCTQuant[1]), handle->pWorkingBuffer);
      swjeFDCTQuantSetFDCTDstBuffer(&(pFDCTQuant[2]), handle->pWorkingBuffer);

      swjeFDCTQuantSetQuantDstBuffer(&(pFDCTQuant[0]), (handle->pWorkingBuffer + (64 * 4)));
      swjeFDCTQuantSetQuantDstBuffer(&(pFDCTQuant[1]), (handle->pWorkingBuffer + (64 * 4)));
      swjeFDCTQuantSetQuantDstBuffer(&(pFDCTQuant[2]), (handle->pWorkingBuffer + (64 * 4)));
   }

   /// Initialize the Huffman encoder
   {
      SWJE_HUFFMAN_ENCODER * const pHuffEncoder = handle->pHuffEncoder;

      swjeHuffEncGenHuffTable(&(handle->huffTables[0]));

      swjeHuffEncSetDCHuffTable(pHuffEncoder, 0, &(handle->huffTables[SWJE_HUFF_TABLE_COMPONENT_TYPE_DC_LUMINANCE]));
      swjeHuffEncSetDCHuffTable(pHuffEncoder, 1, &(handle->huffTables[SWJE_HUFF_TABLE_COMPONENT_TYPE_DC_CHROMINANCE]));
      swjeHuffEncSetDCHuffTable(pHuffEncoder, 2, &(handle->huffTables[SWJE_HUFF_TABLE_COMPONENT_TYPE_DC_CHROMINANCE]));

      swjeHuffEncSetACHuffTable(pHuffEncoder, 0, &(handle->huffTables[SWJE_HUFF_TABLE_COMPONENT_TYPE_AC_LUMINANCE]));
      swjeHuffEncSetACHuffTable(pHuffEncoder, 1, &(handle->huffTables[SWJE_HUFF_TABLE_COMPONENT_TYPE_AC_CHROMINANCE]));
      swjeHuffEncSetACHuffTable(pHuffEncoder, 2, &(handle->huffTables[SWJE_HUFF_TABLE_COMPONENT_TYPE_AC_CHROMINANCE]));

      swjeHuffEncSetHuffSrcBuffer(pHuffEncoder, (handle->pWorkingBuffer + (64 * 4)));

      /// Sync the write pointer of handle with the write pointer of handle
      swjeHuffEncSetHuffDstBuffer(pHuffEncoder, &(handle->dstFile));
   }

   return JPEG_STATUS_OK;
}



#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
#if defined(__JPEG_MCU_BASED_DCT__)
kal_int32 jpeg_drv_enc_dctquant_start(JPEG_ENCODER_HANDLE handle)
{
   SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit;

   kal_uint32 srcHwFdctQuantBuffer;
   kal_uint32 hwIrqStatus;
   kal_uint32 hwLastNonzPos[6];

   kal_uint8 *srcBuffer8;
   kal_uint8 *dstBuffer8;
   kal_uint32 *srcBufferU32;
   kal_uint32 *dstBufferU32;

   kal_int32 i, j;
   kal_uint32 reg = 0;

   kal_int32 compID;
   kal_int32 duWidth, duHeight, duCount;
   kal_int32 duX, duY;
   kal_uint8 *inputBuffer;
   kal_uint32 inputBufferPitch;
   kal_uint32 inputBufferPitchU32;
   kal_uint32 lastCoeff, lastCoeffNum;

   kal_uint8 *fdctQuantInputBuffer[3];
   kal_uint8 *fragOutputBuffer[3];
   kal_uint32 fragOutputPitch[3];
   kal_uint32 fdctQuantSrcWidth[3];
   kal_uint32 hSamplingFactor[3];
   kal_uint32 vSamplingFactor[3];
   
   SWJE_FDCT_QUANT_UNIT * const pFDCTQuant = handle->pFDCTQuantUnits;
   SWJE_FRAGMENT_PROCESSOR * const pFragProcessor = handle->pFragProcessor;
   JPEG_GENGERAL_ENCODE_INFO* const gengralEncodeInfo = &(handle->gengralEncodeInfo);
   JPEG_ENCODE_INFO* const mainEncodeInfo = &(handle->mainEncodeInfo);

   kal_int32 numComp= gengralEncodeInfo->numComponent;

   JPEG_SWLA_LOG("JMC",1);
   compID = 3;
   while(--compID >= 0)
   {
      hSamplingFactor[compID] = gengralEncodeInfo->hSamplingFactor[compID];
      vSamplingFactor[compID] = gengralEncodeInfo->vSamplingFactor[compID];
   }

   swjeFragProcGetDstYUVBuffer(pFragProcessor, &fragOutputBuffer[0], &fragOutputPitch[0]);

   /// Quantize + FDCT + Huffman
   fdctQuantSrcWidth[0] = fragOutputPitch[0];
   fdctQuantSrcWidth[1] = fragOutputPitch[1];
   fdctQuantSrcWidth[2] = fragOutputPitch[2];
         
   /// Quantize + FDCT + Huffman
   fdctQuantInputBuffer[0] = fragOutputBuffer[0];
   fdctQuantInputBuffer[1] = fragOutputBuffer[1];
   fdctQuantInputBuffer[2] = fragOutputBuffer[2];

   jpeg_drv_enc_get_src_base(&srcHwFdctQuantBuffer);

   dstBufferU32 = (kal_uint32*)srcHwFdctQuantBuffer;
   dstBuffer8 = (kal_uint8*)srcHwFdctQuantBuffer;


   /// We need this MCU. Thus we have to perform quant-FDCT for the encoded coefficients.
   for (compID = 0; compID < numComp; compID++)
   {
      inputBuffer = fdctQuantInputBuffer[compID];
      inputBufferPitch = fdctQuantSrcWidth[compID];
      inputBufferPitchU32 = fdctQuantSrcWidth[compID] >> 2;

      duHeight = vSamplingFactor[compID];
      duY = 0;
      while (--duHeight >= 0)
      {
         duWidth = hSamplingFactor[compID];
         duX = 0;
         while (--duWidth >= 0)
         {
            // 5. copy source buffer for hw dct accelerator
            srcBufferU32 = (kal_uint32*)(inputBuffer + ((duY * inputBufferPitch + duX) << 3));
            srcBuffer8 = inputBuffer + ((duY * inputBufferPitch + duX) << 3);

            i = 8;
            while (--i >= 0)
            {
               dstBufferU32[0] = srcBufferU32[0];
               dstBufferU32[1] = srcBufferU32[1];
               srcBufferU32 += inputBufferPitchU32;
               dstBufferU32 += 2;
            }
            duX++;
         }
         duY++;
      }
   }

   JPEG_SWLA_LOG("JMC",0);
   JPEG_SWLA_LOG("DCT",1);
   // 6. start dct accelerator
   jpeg_drv_enc_start();

   // 7. wait for hw finished
   jpeg_drv_enc_get_irq_status(&hwIrqStatus);
   while(hwIrqStatus) 
   {
      jpeg_drv_enc_get_irq_status(&hwIrqStatus);
   }

   lastCoeffNum = 0;
   jpeg_drv_enc_get_last_pos(hwLastNonzPos);
   for (compID = 0; compID < numComp; compID++)
   {
      pFDCTQuantUnit = (SWJE_FDCT_QUANT_UNIT *)(&(pFDCTQuant[compID]));

      duCount = 0;
      duHeight = vSamplingFactor[compID];
      while (--duHeight >= 0)
      {
         duWidth = hSamplingFactor[compID];
         while (--duWidth >= 0)
         {
            lastCoeff = hwLastNonzPos[lastCoeffNum];
            // 8. get last non-zero coefficient
            pFDCTQuantUnit->lastNonzeroCoeff = pFDCTQuantUnit->lastNonzeroCoeff & (~(0xFF << (duCount << 3)));
            if (0xFF != lastCoeff)
            {
               pFDCTQuantUnit->lastNonzeroCoeff = pFDCTQuantUnit->lastNonzeroCoeff | ((lastCoeff & 0xFF) << (duCount << 3));
            }

            duCount++;
            lastCoeffNum++;
         }
      }
   }
   JPEG_SWLA_LOG("DCT",0);
   
   return 0;
}

#else  // __JPEG_MCU_BASED_DCT__
kal_int32 jpeg_drv_enc_dctquant_start(void *FDCTQuantPtr, kal_int32 compID, kal_uint32 duCount)
{
   SWJE_FDCT_QUANT_UNIT *pFDCTQuantUnit = (SWJE_FDCT_QUANT_UNIT *)FDCTQuantPtr;

   kal_uint8 *srcFdctQuantBuffer;
   kal_uint32 srcFdctQuantPitch;
   kal_uint32 srcHwFdctQuantBuffer;
   kal_uint32 hwIrqStatus;
   kal_uint32 hwLastNonzPos[6];

   kal_uint8 *srcBuffer8;
   kal_uint8 *dstBuffer8;
   kal_uint32 *srcBufferU32;
   kal_uint32 *dstBufferU32;

   kal_int32 i;

   swjeFDCTQuantGetSrcBuffer(pFDCTQuantUnit, &srcFdctQuantBuffer, &srcFdctQuantPitch);
   jpeg_drv_enc_get_src_base(&srcHwFdctQuantBuffer);

   // 5. copy source buffer for hw dct accelerator
   srcBuffer8 = srcFdctQuantBuffer;
   dstBufferU32 = (kal_uint32*)srcHwFdctQuantBuffer;
   for(i = 0; i < 8; i++)
   {
      //memcpy(dstBuffer8, srcBuffer8, 8);
      dstBufferU32[0] = (srcBuffer8[3] << 24) | (srcBuffer8[2] << 16) | (srcBuffer8[1] << 8) | (srcBuffer8[0]);
      dstBufferU32[1] = (srcBuffer8[7] << 24) | (srcBuffer8[6] << 16) | (srcBuffer8[5] << 8) | (srcBuffer8[4]);
      srcBuffer8 += srcFdctQuantPitch;
      dstBufferU32 += 2;
   }

   // 6. config du format
   REG_HMJPEG_FORMAT = 0x00333330 | compID;

   // 7. start dct accelerator
   jpeg_drv_enc_start();

   // 8. wait for hw finished
   jpeg_drv_enc_get_irq_status(&hwIrqStatus);
   while(hwIrqStatus) 
   {
      jpeg_drv_enc_get_irq_status(&hwIrqStatus);
   }

   // 9. get last non-zero coefficient
   jpeg_drv_enc_get_last_pos(hwLastNonzPos);
   {
      kal_uint32 lastCoeff = hwLastNonzPos[0];

      pFDCTQuantUnit->lastNonzeroCoeff = pFDCTQuantUnit->lastNonzeroCoeff & (~(0xFF << (duCount << 3)));
      if (0xFF != lastCoeff)
      {
         pFDCTQuantUnit->lastNonzeroCoeff = pFDCTQuantUnit->lastNonzeroCoeff | ((lastCoeff & 0xFF) << (duCount << 3));
      }
   }
   
   return 0;
}
#endif  // __JPEG_MCU_BASED_DCT__
#endif  // __DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__



static JPEG_STATUS_ENUM _jpeg_enc_sw_init_encoder(JPEG_ENCODER_HANDLE handle)
{
   JPEG_ENCODE_INFO * const curEncodeInfo = handle->curEncodeInfo;
   JPEG_GENGERAL_ENCODE_INFO* const gengralEncodeInfo = &(handle->gengralEncodeInfo);
   kal_int32 srcStepX = curEncodeInfo->srcStepX;
   kal_int32 srcStepY = curEncodeInfo->srcStepY;
   kal_uint32 srcWidth = handle->srcWidth;
   kal_uint32 dstWidth = curEncodeInfo->dstWidth;
   kal_uint32 dstHeight = curEncodeInfo->dstHeight;
   kal_uint32 dstMcuWidth = curEncodeInfo->dstMcuWidth;
   kal_uint32 dstMcuHeight = curEncodeInfo->dstMcuHeight;
   kal_uint32 dstTotalMcuPerRow, dstTotalMcuPerColumn;

   /// Some variable
   dstTotalMcuPerRow = (dstWidth + (gengralEncodeInfo->hSamplingFactorMax << 3) - 1) /
                                   (gengralEncodeInfo->hSamplingFactorMax << 3);
   dstTotalMcuPerColumn = (dstHeight + (gengralEncodeInfo->vSamplingFactorMax << 3) - 1) /
                                       (gengralEncodeInfo->vSamplingFactorMax << 3);

   handle->curRstNum = 0;
   handle->workingBufferActualMcuNum = 1;
   /// Initialize the fragment processor
   {
      SWJE_FRAGMENT_PROCESSOR * const pFragProcessor = handle->pFragProcessor;

      swjeFragProcSetSrcStep(pFragProcessor, srcStepX, srcStepY);
      swjeFragProcSetDstStep(pFragProcessor, curEncodeInfo->dstStepX, curEncodeInfo->dstStepY);

      switch(handle->srcMode)
      {
         case JPEG_ENCODE_SOURCE_RGB_BUFFER:
         {
            kal_int32 workingBufferActualMcuNum = MIN((handle->workingBufferMcuNum), (kal_int32)dstTotalMcuPerRow);

            swjeFragProcSetSrcRGBBuffer(pFragProcessor, handle->srcRGBBuffer, srcWidth, handle->srcHeight, handle->srcRGBFormat);
            swjeFragProcSetDstYUVBuffer(pFragProcessor, handle->YUVWorkingBuffer[0], handle->YUVWorkingBuffer[1], handle->YUVWorkingBuffer[2],
                                        dstMcuWidth * workingBufferActualMcuNum, dstMcuHeight, handle->dstSamplingFormat);

            #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_RGB_RESIZER)
               if(!((0x00010000 == (srcStepX)) && (0x00010000 == (srcStepY))))
               {
                  swjeFragProcSetDstResizeRGBBuffer(pFragProcessor, handle->RGBWorkingBuffer);
               }
            #endif

            #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
               if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
               {
                  swjeFragProcSetDstRotateRGBBuffer(pFragProcessor, handle->RGBRotateWorkingBuffer);
                  swjeFragProcSetSrcResizeRGBBuffer(pFragProcessor, handle->RGBRotateWorkingBuffer);
               }
               else
            #endif
            {
               swjeFragProcSetSrcResizeSize(pFragProcessor, srcWidth, handle->srcHeight);
               swjeFragProcSetSrcResizeRGBBuffer(pFragProcessor, handle->srcRGBBuffer);
            }

            handle->workingBufferActualMcuNum = workingBufferActualMcuNum;
         }
         break;
         case JPEG_ENCODE_SOURCE_YUV_BUFFER:
         {
            kal_int32 workingBufferActualMcuNum = MIN((handle->workingBufferMcuNum), (kal_int32)dstTotalMcuPerRow);

            handle->workingBufferActualMcuNum = workingBufferActualMcuNum;

            swjeFragProcSetSrcYUVBuffer(pFragProcessor, handle->srcYUVBuffer[0], handle->srcYUVBuffer[1], handle->srcYUVBuffer[2],
                                        srcWidth, handle->srcHeight, handle->srcSamplingFormat);

            #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
               if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
               {
                  swjeFragProcSetDstRotateYUVBuffer(pFragProcessor,
                                                    handle->YUVRotateWorkingBuffer[0], handle->YUVRotateWorkingBuffer[1], handle->YUVRotateWorkingBuffer[2],
                                                    handle->YUVRotateWorkingBufferSize[0], handle->YUVRotateWorkingBufferSize[1], handle->YUVRotateWorkingBufferSize[2]);
                  swjeFragProcSetSrcResizeYUVBuffer(pFragProcessor, handle->YUVRotateWorkingBuffer[0], handle->YUVRotateWorkingBuffer[1], handle->YUVRotateWorkingBuffer[2]);
               }
               else
            #endif
            {
               swjeFragProcSetSrcResizeYUVBuffer(pFragProcessor, handle->srcYUVBuffer[0], handle->srcYUVBuffer[1], handle->srcYUVBuffer[2]);
            }

            swjeFragProcSetSrcResizeSize(pFragProcessor, srcWidth, handle->srcHeight);

            #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_YUV_RESIZER)
               if(!((0x00010000 == (srcStepX)) && (0x00010000 == (srcStepY))))
               {
                  swjeFragProcSetDstYUVBuffer(pFragProcessor, handle->YUVWorkingBuffer[0], handle->YUVWorkingBuffer[1], handle->YUVWorkingBuffer[2],
                                              dstMcuWidth * workingBufferActualMcuNum, dstMcuHeight, handle->dstSamplingFormat);
               }
               else
            #endif
            {
               /// due to (handle->dstWidth == handle->srcWidth) and (handle->dstHeight == handle->srcHeight)
               #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_SRC_UYVY)
                  if((0 == (dstWidth % dstMcuWidth)) && (0 == (dstHeight % dstMcuHeight)) && (handle->srcSamplingFormat != JPEG_YUV_FORMAT_PACKED_UYVY422))
               #else
                  if((0 == (dstWidth % dstMcuWidth)) && (0 == (dstHeight % dstMcuHeight)))
               #endif
               {
                  swjeFragProcSetDstYUVBuffer(pFragProcessor, handle->srcYUVBuffer[0], handle->srcYUVBuffer[1], handle->srcYUVBuffer[2],
                                              dstWidth, dstHeight, handle->dstSamplingFormat);
               }
               else
               {
                  #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
                     if(JPEG_ENCODE_ROTATE_ANGLE_000 != (handle->rotation))
                     {
                        swjeFragProcSetDstYUVBuffer(pFragProcessor, handle->YUVRotateWorkingBuffer[0], handle->YUVRotateWorkingBuffer[1], handle->YUVRotateWorkingBuffer[2],
                                                    dstMcuWidth * workingBufferActualMcuNum, dstMcuHeight, handle->dstSamplingFormat);
                     }
                     else
                  #endif
                  {
                     handle->workingBufferActualMcuNum = 1;
                     swjeFragProcSetDstYUVBuffer(pFragProcessor, handle->YUVWorkingBuffer[0], handle->YUVWorkingBuffer[1], handle->YUVWorkingBuffer[2],
                                                 dstMcuWidth, dstMcuHeight, handle->dstSamplingFormat);
                  }
               }
            }
         }
         break;
         default:
            ASSERT(0);
         break;
      }

      swjeFragProcSetRotation(pFragProcessor, handle->rotation);
      swjeFragProcSetOutputImageSize(pFragProcessor, dstWidth, dstHeight);
      swjeFragProcSetPadding(pFragProcessor, dstMcuWidth, dstMcuHeight);
      if(0 > swjeFragProcDecideFunc(pFragProcessor))
      {
         handle->lastStatus = JPEG_STATUS_ENC_ERROR_UNSUPPORTED_FORMAT;
         return JPEG_STATUS_ENC_ERROR_UNSUPPORTED_FORMAT;
      }
   }

   /// Initialize the Quant-FDCT processor.
   {
     SWJE_HUFFMAN_ENCODER * const pHuffEncoder = handle->pHuffEncoder;

      #if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
        /// If DCT HW is in use
        if(handle->hwAcceleratorHandle)
        {
           kal_uint32 length, dst_addr;

           // 1. set jpeg encode power on
           jpeg_drv_enc_power_on();

           // 2. set jpeg encode quality
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

           // 3. set huffman source buffer           
           jpeg_drv_enc_get_dst_base(&dst_addr);
           swjeHuffEncSetHuffSrcBuffer(pHuffEncoder, (kal_uint8 *)dst_addr);

           // 4. set huffman source buffer length
           jpeg_drv_enc_get_dct_dst_length(&length);
           swjeHuffEncSetHuffSrcBufferLength(pHuffEncoder, length);

         #if defined(__JPEG_MCU_BASED_DCT__)
            // 5. config du format
            jpeg_drv_enc_set_sample_format_related(dstWidth, dstHeight, handle->dstSamplingFormat);
         #endif
        }
        else
      #endif
        {
           swjeHuffEncSetHuffSrcBufferLength(pHuffEncoder, 32);
        }
         

   }

   /// Initialize the Huffman decoders
   {
      SWJE_HUFFMAN_ENCODER * const pHuffEncoder = handle->pHuffEncoder;

      swjeHuffEncInit(pHuffEncoder);
   }

   curEncodeInfo->dstTotalMcuPerRow = dstTotalMcuPerRow;
   curEncodeInfo->dstTotalMcuPerColumn = dstTotalMcuPerColumn;

   return JPEG_STATUS_OK;
}



#if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
   extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);
#endif
#if defined(__JPEG_MCU_BASED_DCT__)
static JPEG_STATUS_ENUM _jpeg_enc_sw_process_encoder(JPEG_ENCODER_HANDLE handle)
{
   JPEG_ENCODE_INFO * const curEncodeInfo = handle->curEncodeInfo;
   JPEG_GENGERAL_ENCODE_INFO* const gengralEncodeInfo = &(handle->gengralEncodeInfo);
   SWJE_FRAGMENT_PROCESSOR * const pFragProcessor = handle->pFragProcessor;
   SWJE_FDCT_QUANT_UNIT * const pFDCTQuant = handle->pFDCTQuantUnits;
   SWJE_HUFFMAN_ENCODER * const pHuffEncoder = handle->pHuffEncoder;
   SWJE_FILE *dstFile = &(handle->dstFile);

   kal_int32 (* const check_abort_func)(void) = handle->check_abort_func;
   kal_int32 numComp= gengralEncodeInfo->numComponent;
   kal_uint32 dstTotalMcuPerRow = curEncodeInfo->dstTotalMcuPerRow;
   kal_uint32 dstTotalMcuPerColumn = curEncodeInfo->dstTotalMcuPerColumn;
   kal_uint32 restartInterval = handle->driNum;
   kal_uint32 abortCheckInterval = JPEG_ENCODE_ABORT_NUMBER;
   kal_int32 dstMcuWidth = curEncodeInfo->dstMcuWidth;
   kal_int32 dstMcuHeight = curEncodeInfo->dstMcuHeight;
   register kal_int32 srcMcuWidth = curEncodeInfo->srcMcuWidth;
   register kal_int32 srcMcuHeight = curEncodeInfo->srcMcuHeight;
   kal_int32 workingBufferActualMcuNum =  handle->workingBufferActualMcuNum;
   kal_int32 workingBufferActualMcuWidth = srcMcuWidth * workingBufferActualMcuNum;

   kal_uint8 *fragOutputBuffer[3];
   kal_uint32 fragOutputPitch[3];
   kal_uint8 *fdctQuantInputBuffer[3];
   kal_uint32 fdctQuantSrcWidth[3];
   kal_uint32 hSamplingFactor[3];
   kal_uint32 vSamplingFactor[3];

   kal_int32 srcActualMcuWidth;
   kal_int32 mcuFragProcessorProcess;
   kal_int32 dstCurrentMcuRow, dstCurrentMcuColumn;
   kal_uint32 srcClipX, srcClipY;
   kal_int32 compID;
   kal_uint32 resizeWidth;

   kal_uint8 *startReadPtr = NULL , *curReadPtr = NULL; /// *endReadPtr,
   kal_uint32 rowPixels = 0;
   kal_uint32 dst_addr;

   /// Store some variables
   compID = 3;
   while(--compID >= 0)
   {
      hSamplingFactor[compID] = gengralEncodeInfo->hSamplingFactor[compID];
      vSamplingFactor[compID] = gengralEncodeInfo->vSamplingFactor[compID];
   }


   /// check read/write buffer pointer
   {

      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
         if((NULL == (dstFile->pDstFileHandle)) && (JPEG_ENCODE_ROTATE_ANGLE_000 == (handle->rotation)))
      #else
         if(NULL == (dstFile->pDstFileHandle))
      #endif
      {
         switch (handle->srcMode)
         {
            case JPEG_ENCODE_SOURCE_YUV_BUFFER:
                #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
                   if(KAL_TRUE == (handle->enableSrcDynamicSwitch))
                   {
                      startReadPtr = (kal_uint8 *)query_opposite_switchable_cacheaddr_ram((kal_uint32)handle->srcYUVBuffer[0]);
                   }
                   else
                   {
                      startReadPtr = handle->srcYUVBuffer[0];
                   }
                #else
                   startReadPtr = handle->srcYUVBuffer[0];
                #endif
                /// endReadPtr = startReadPtr + (handle->srcWidth) * (handle->srcHeight);
                rowPixels = (handle->srcWidth);
            break;
            case JPEG_ENCODE_SOURCE_RGB_BUFFER:
            {
               ///kal_uint32 bpp;
               ///
               ///switch(handle->srcRGBFormat)
               ///{
               ///   case JPEG_RGB_FORMAT_RGB565:
               ///      bpp = 2;
               ///   break;
               ///   case JPEG_RGB_FORMAT_RGB888:
               ///   case JPEG_RGB_FORMAT_BGR888:
               ///      bpp = 3;
               ///   break;
               ///   default:
               ///      ASSERT(0);
               ///   break;
               ///}
               #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
                   if(KAL_TRUE == (handle->enableSrcDynamicSwitch))
                   {
                      startReadPtr = (kal_uint8 *)query_opposite_switchable_cacheaddr_ram((kal_uint32)handle->srcRGBBuffer);
                   }
                   else
                   {
                      startReadPtr = handle->srcRGBBuffer;
                   }
               #else
                  startReadPtr = handle->srcRGBBuffer;
               #endif
               /// endReadPtr = startReadPtr + (handle->srcWidth) * (handle->srcHeight) * bpp;
               rowPixels = (handle->srcWidth);
            }
            break;
            default:
               ASSERT(0);
         }


         if(((kal_uint32)(dstFile->dstBufferAddr)) < ((kal_uint32)startReadPtr))
         {
            /// only check this condition
         }
         else if(((kal_uint32)(dstFile->dstBufferAddr)) == ((kal_uint32)startReadPtr))
         {
            handle->lastStatus = JPEG_STATUS_ENC_ERROR_DST_BUFFER_OVERWRITE_SRC_BUFFER;
            return handle->lastStatus;
         }
         else
         {
            rowPixels = 0;
         }
      }
   }

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

#if defined(__JPEG_TIMER_DEBUG__)
   u4EncodeStartTime = drv_get_current_time();
#endif

   srcClipY = 0;
   dstCurrentMcuColumn = dstTotalMcuPerColumn;
   while (--dstCurrentMcuColumn >= 0)
   {
      srcClipX = 0;
      dstCurrentMcuRow = dstTotalMcuPerRow;
      srcActualMcuWidth = workingBufferActualMcuWidth;
      resizeWidth = dstMcuWidth * workingBufferActualMcuNum;

      while (dstCurrentMcuRow > 0)
      {
         /// Fragment Process
         /// For RGB Buffer : RGB -> YUV and padding
         /// For YUV Buffer : Resize + Padding
         if(workingBufferActualMcuNum <= dstCurrentMcuRow)
         {
            mcuFragProcessorProcess = workingBufferActualMcuNum;
         }
         else
         {
            srcActualMcuWidth = srcMcuWidth * dstCurrentMcuRow;
            mcuFragProcessorProcess = dstCurrentMcuRow;
            resizeWidth = dstMcuWidth * dstCurrentMcuRow;
         }

         swjeFragProcSetDstExpectResizeSize(pFragProcessor, resizeWidth, dstMcuHeight);
         swjeFragProcSetSrcClipWindow(pFragProcessor,
                                      srcClipX,
                                      srcClipY,
                                      IUL_X_TO_I_CARRY(srcActualMcuWidth),
                                      IUL_X_TO_I_CARRY(srcMcuHeight));
         JPEG_SWLA_LOG("FRG",1);
         swjeFragProcProcessFragment(pFragProcessor);
         JPEG_SWLA_LOG("FRG",0);

         swjeFragProcGetDstYUVBuffer(pFragProcessor, &fragOutputBuffer[0], &fragOutputPitch[0]);

         /// Quantize + FDCT + Huffman
         fdctQuantSrcWidth[0] = fragOutputPitch[0];
         fdctQuantSrcWidth[1] = fragOutputPitch[1];
         fdctQuantSrcWidth[2] = fragOutputPitch[2];
         
         while(--mcuFragProcessorProcess >=0)
         {
            /// Quantize + FDCT + Huffman
            fdctQuantInputBuffer[0] = fragOutputBuffer[0];
            fdctQuantInputBuffer[1] = fragOutputBuffer[1];
            fdctQuantInputBuffer[2] = fragOutputBuffer[2];

         #if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
            if (handle->hwAcceleratorHandle)
            {
               jpeg_drv_enc_dctquant_start(handle);

               // 3. set huffman source buffer           
               jpeg_drv_enc_get_dst_base(&dst_addr);
               swjeHuffEncSetHuffSrcBuffer(pHuffEncoder, (kal_uint8 *)dst_addr);
            }
         #endif

            JPEG_SWLA_LOG("HUF",1);
            /// We need this MCU. Thus we have to perform quant-FDCT for the encoded coefficients.
            for (compID = 0; compID < numComp; compID++)
            {
               kal_int32 duCount = 0;
               kal_int32 duHeight = vSamplingFactor[compID];

               while (--duHeight >= 0)
               {
                  kal_int32 duWidth = hSamplingFactor[compID];
                  kal_uint8 *inputBuffer = fdctQuantInputBuffer[compID];

                  while (--duWidth >= 0)
                  {
                  #if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
                     if (0 == handle->hwAcceleratorHandle)
                  #endif
                     {
                        /// Quantize + FDCT
                        SWJE_FDCT_QUANT_SET_SRC_BUFFER((&pFDCTQuant[compID]), inputBuffer, (fdctQuantSrcWidth[compID]));
                        //swjeFDCTQuantSetSrcBuffer(&(pFDCTQuant[compID]), inputBuffer, fdctQuantSrcWidth[compID]);
                        inputBuffer += 8;

                        swjeFDCTQuantProcessDU(&(pFDCTQuant[compID]), compID, duCount);
                     }

                     {
                        kal_uint32 lastNonzeroCoeff;
                        SWJE_FDCT_WUANT_GET_LAST_NONZERO_COEFF((pFDCTQuant[compID]), duCount, lastNonzeroCoeff);
                        SWJE_HUFF_ENC_SET_LAST_NONZERO_COEFF(pHuffEncoder, lastNonzeroCoeff);

                        //swjeFDCTQuantGetLastNonzeroCoeff(&(pFDCTQuant[compID]), duCount, &lastNonzeroCoeff);
                        //swjeHuffEncSetLastNonzeroCoeff(pHuffEncoder, lastNonzeroCoeff);
                     }
                     duCount++;
                     
                     /// Huffman
                     {
                        //kal_uint32 status = 0;
                        //SWJE_HUFF_ENC_PROCESSDU(pHuffEncoder, compID, status);

                        //if (status < 0)
                        if (swjeHuffEncProcessDU(pHuffEncoder, compID) < 0)
                        {
                           handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
                           JPEG_SWLA_LOG("HUF",0);
                           return handle->lastStatus;
                        }
                     }

                     // 3. set huffman source buffer           
                  #if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
                     if (handle->hwAcceleratorHandle)
                     {
                        dst_addr = dst_addr + 128;
                        swjeHuffEncSetHuffSrcBuffer(pHuffEncoder, (kal_uint8 *)dst_addr);
                     }
                  #endif
                  }
                  /// Quantize + FDCT
                  fdctQuantInputBuffer[compID] += fdctQuantSrcWidth[compID] * 8;
               }
            }
            JPEG_SWLA_LOG("HUF",0);

            /// Check DRI
            restartInterval--;
            if (0 == restartInterval)
            {
               /// Huffman: Flush the remainder Huffman code
               if (swjeHuffEncFlush(pHuffEncoder) < 0)
               {
                  handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
                  return handle->lastStatus;
               }

               restartInterval = handle->driNum;
               swjeHuffEncInit(pHuffEncoder);

               /// Write RST Marker
               if (JPEG_STATUS_OK != _jpeg_enc_sw_emit_rst(handle))
               {
                  handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
                  return handle->lastStatus;
               }
            }

            /// Check abort function
            abortCheckInterval--;
            if (0 == abortCheckInterval)
            {
               if (check_abort_func)
               {
                  if (!check_abort_func())
                  {
                     handle->codecState = JPEG_CODEC_STATE_ABORT;
                     handle->lastStatus = JPEG_STATUS_ENC_ABORT;
                     return handle->lastStatus;
                  }
               }

               abortCheckInterval = JPEG_ENCODE_ABORT_NUMBER;
            }

            /// Quantize + FDCT + Huffman
            fragOutputBuffer[0] += 8 * hSamplingFactor[0];
            fragOutputBuffer[1] += 8 * hSamplingFactor[1];
            fragOutputBuffer[2] += 8 * hSamplingFactor[2];
         }
         dstCurrentMcuRow -= workingBufferActualMcuNum;
         srcClipX += srcActualMcuWidth;
      }
      srcClipY += srcMcuHeight;

      /// check read/write buffer pointer
      {
         /// rowPixels = 0 has 3 kinds of meanings
         /// 1. direct file output
         /// 2. rotation is not 0
         /// 3. source and destination do not use memory overlap
         if(0 != rowPixels)
         {
             curReadPtr = startReadPtr + (IUL_X_TO_I_CHOP(srcClipY) * rowPixels);

             if(((kal_uint32)(dstFile->dstWritePtr)) > ((kal_uint32)curReadPtr))
             {
                handle->lastStatus = JPEG_STATUS_ENC_ERROR_DST_BUFFER_OVERWRITE_SRC_BUFFER;
                return handle->lastStatus;
             }
         }
      }
   }

#if defined(__JPEG_TIMER_DEBUG__)
   u4EncodeTime[u4EncodeCount] = drv_get_duration_ms(u4EncodeStartTime);
   if (MAX_ENCODE_CNT > (u4EncodeCount + 1))
   {
      u4EncodeCount = u4EncodeCount + 1;
   }
   else
   {
      u4EncodeCount = 0;
   }
#endif
            
   /// We should write all huffman results to dst buffer
   /// Huffman: Flush the remainder Huffman code
   if (swjeHuffEncFlush(pHuffEncoder) < 0)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
      return handle->lastStatus;
   }

   return JPEG_STATUS_OK;
}

#else  // __JPEG_MCU_BASED_DCT__
static JPEG_STATUS_ENUM _jpeg_enc_sw_process_encoder(JPEG_ENCODER_HANDLE handle)
{
   JPEG_ENCODE_INFO * const curEncodeInfo = handle->curEncodeInfo;
   JPEG_GENGERAL_ENCODE_INFO* const gengralEncodeInfo = &(handle->gengralEncodeInfo);
   SWJE_FRAGMENT_PROCESSOR * const pFragProcessor = handle->pFragProcessor;
   SWJE_FDCT_QUANT_UNIT * const pFDCTQuant = handle->pFDCTQuantUnits;
   SWJE_HUFFMAN_ENCODER * const pHuffEncoder = handle->pHuffEncoder;
   SWJE_FILE *dstFile = &(handle->dstFile);

   kal_int32 (* const check_abort_func)(void) = handle->check_abort_func;
   kal_int32 numComp= gengralEncodeInfo->numComponent;
   kal_uint32 dstTotalMcuPerRow = curEncodeInfo->dstTotalMcuPerRow;
   kal_uint32 dstTotalMcuPerColumn = curEncodeInfo->dstTotalMcuPerColumn;
   kal_uint32 restartInterval = handle->driNum;
   kal_uint32 abortCheckInterval = JPEG_ENCODE_ABORT_NUMBER;
   kal_int32 dstMcuWidth = curEncodeInfo->dstMcuWidth;
   kal_int32 dstMcuHeight = curEncodeInfo->dstMcuHeight;
   register kal_int32 srcMcuWidth = curEncodeInfo->srcMcuWidth;
   register kal_int32 srcMcuHeight = curEncodeInfo->srcMcuHeight;
   kal_int32 workingBufferActualMcuNum =  handle->workingBufferActualMcuNum;
   kal_int32 workingBufferActualMcuWidth = srcMcuWidth * workingBufferActualMcuNum;

   kal_uint8 *fragOutputBuffer[3];
   kal_uint32 fragOutputPitch[3];
   kal_uint8 *fdctQuantInputBuffer[3];
   kal_uint32 fdctQuantSrcWidth[3];
   kal_uint32 hSamplingFactor[3];
   kal_uint32 vSamplingFactor[3];

   kal_int32 srcActualMcuWidth;
   kal_int32 mcuFragProcessorProcess;
   kal_int32 dstCurrentMcuRow, dstCurrentMcuColumn;
   kal_uint32 srcClipX, srcClipY;
   kal_int32 compID;
   kal_uint32 resizeWidth;

   kal_uint8 *startReadPtr = NULL , *curReadPtr = NULL; /// *endReadPtr,
   kal_uint32 rowPixels = 0;

   /// Store some variables
   compID = 3;
   while(--compID >= 0)
   {
      hSamplingFactor[compID] = gengralEncodeInfo->hSamplingFactor[compID];
      vSamplingFactor[compID] = gengralEncodeInfo->vSamplingFactor[compID];
   }


   /// check read/write buffer pointer
   {

      #if defined(SW_JPEG_ENCODER_SUPPORT_WITH_ROTATOR_SUPPORT)
         if((NULL == (dstFile->pDstFileHandle)) && (JPEG_ENCODE_ROTATE_ANGLE_000 == (handle->rotation)))
      #else
         if(NULL == (dstFile->pDstFileHandle))
      #endif
      {
         switch (handle->srcMode)
         {
            case JPEG_ENCODE_SOURCE_YUV_BUFFER:
                #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
                   if(KAL_TRUE == (handle->enableSrcDynamicSwitch))
                   {
                      startReadPtr = (kal_uint8 *)query_opposite_switchable_cacheaddr_ram((kal_uint32)handle->srcYUVBuffer[0]);
                   }
                   else
                   {
                      startReadPtr = handle->srcYUVBuffer[0];
                   }
                #else
                   startReadPtr = handle->srcYUVBuffer[0];
                #endif
                /// endReadPtr = startReadPtr + (handle->srcWidth) * (handle->srcHeight);
                rowPixels = (handle->srcWidth);
            break;
            case JPEG_ENCODE_SOURCE_RGB_BUFFER:
            {
               ///kal_uint32 bpp;
               ///
               ///switch(handle->srcRGBFormat)
               ///{
               ///   case JPEG_RGB_FORMAT_RGB565:
               ///      bpp = 2;
               ///   break;
               ///   case JPEG_RGB_FORMAT_RGB888:
               ///   case JPEG_RGB_FORMAT_BGR888:
               ///      bpp = 3;
               ///   break;
               ///   default:
               ///      ASSERT(0);
               ///   break;
               ///}
               #if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
                   if(KAL_TRUE == (handle->enableSrcDynamicSwitch))
                   {
                      startReadPtr = (kal_uint8 *)query_opposite_switchable_cacheaddr_ram((kal_uint32)handle->srcRGBBuffer);
                   }
                   else
                   {
                      startReadPtr = handle->srcRGBBuffer;
                   }
               #else
                  startReadPtr = handle->srcRGBBuffer;
               #endif
               /// endReadPtr = startReadPtr + (handle->srcWidth) * (handle->srcHeight) * bpp;
               rowPixels = (handle->srcWidth);
            }
            break;
            default:
               ASSERT(0);
         }


         if(((kal_uint32)(dstFile->dstBufferAddr)) < ((kal_uint32)startReadPtr))
         {
            /// only check this condition
         }
         else if(((kal_uint32)(dstFile->dstBufferAddr)) == ((kal_uint32)startReadPtr))
         {
            handle->lastStatus = JPEG_STATUS_ENC_ERROR_DST_BUFFER_OVERWRITE_SRC_BUFFER;
            return handle->lastStatus;
         }
         else
         {
            rowPixels = 0;
         }
      }
   }

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

#if defined(__JPEG_TIMER_DEBUG__)
   u4EncodeStartTime = drv_get_current_time();
#endif

   srcClipY = 0;
   dstCurrentMcuColumn = dstTotalMcuPerColumn;
   while (--dstCurrentMcuColumn >= 0)
   {
      srcClipX = 0;
      dstCurrentMcuRow = dstTotalMcuPerRow;
      srcActualMcuWidth = workingBufferActualMcuWidth;
      resizeWidth = dstMcuWidth * workingBufferActualMcuNum;

      while (dstCurrentMcuRow > 0)
      {
         /// Fragment Process
         /// For RGB Buffer : RGB -> YUV and padding
         /// For YUV Buffer : Resize + Padding
         if(workingBufferActualMcuNum <= dstCurrentMcuRow)
         {
            mcuFragProcessorProcess = workingBufferActualMcuNum;
         }
         else
         {
            srcActualMcuWidth = srcMcuWidth * dstCurrentMcuRow;
            mcuFragProcessorProcess = dstCurrentMcuRow;
            resizeWidth = dstMcuWidth * dstCurrentMcuRow;
         }

         swjeFragProcSetDstExpectResizeSize(pFragProcessor, resizeWidth, dstMcuHeight);
         swjeFragProcSetSrcClipWindow(pFragProcessor,
                                      srcClipX,
                                      srcClipY,
                                      IUL_X_TO_I_CARRY(srcActualMcuWidth),
                                      IUL_X_TO_I_CARRY(srcMcuHeight));
         JPEG_SWLA_LOG("FRG",1);
         swjeFragProcProcessFragment(pFragProcessor);
         JPEG_SWLA_LOG("FRG",0);

         swjeFragProcGetDstYUVBuffer(pFragProcessor, &fragOutputBuffer[0], &fragOutputPitch[0]);

         /// Quantize + FDCT + Huffman
         fdctQuantSrcWidth[0] = fragOutputPitch[0];
         fdctQuantSrcWidth[1] = fragOutputPitch[1];
         fdctQuantSrcWidth[2] = fragOutputPitch[2];
         
         while(--mcuFragProcessorProcess >=0)
         {
            /// Quantize + FDCT + Huffman
            fdctQuantInputBuffer[0] = fragOutputBuffer[0];
            fdctQuantInputBuffer[1] = fragOutputBuffer[1];
            fdctQuantInputBuffer[2] = fragOutputBuffer[2];

            /// We need this MCU. Thus we have to perform quant-FDCT for the encoded coefficients.
            for (compID = 0; compID < numComp; compID++)
            {
               kal_int32 duHeight = vSamplingFactor[compID];

               while (--duHeight >= 0)
               {
                  kal_int32 duWidth = hSamplingFactor[compID];
                  kal_uint8 *inputBuffer = fdctQuantInputBuffer[compID];

                  while (--duWidth >= 0)
                  {
                     kal_int32 duCount = 0;

                     /// Quantize + FDCT
                     SWJE_FDCT_QUANT_SET_SRC_BUFFER((&pFDCTQuant[compID]),inputBuffer, (fdctQuantSrcWidth[compID]));
                     //swjeFDCTQuantSetSrcBuffer(&(pFDCTQuant[compID]), inputBuffer, fdctQuantSrcWidth[compID]);
                     inputBuffer += 8;

                     JPEG_SWLA_LOG("DCT",1);
                     /// HW or SW
                  #if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
                     if (handle->hwAcceleratorHandle)
                     {
                        jpeg_drv_enc_dctquant_start(&(pFDCTQuant[compID]), compID, duCount);
                     }
                     else
                  #endif
                     {
                        swjeFDCTQuantProcessDU(&(pFDCTQuant[compID]), compID, duCount);
                     }
                     JPEG_SWLA_LOG("DCT",0);
                     
                     {
                        kal_uint32 lastNonzeroCoeff;
                        SWJE_FDCT_WUANT_GET_LAST_NONZERO_COEFF((pFDCTQuant[compID]), duCount, lastNonzeroCoeff);
                        SWJE_HUFF_ENC_SET_LAST_NONZERO_COEFF(pHuffEncoder, lastNonzeroCoeff);

                        //swjeFDCTQuantGetLastNonzeroCoeff(&(pFDCTQuant[compID]), duCount, &lastNonzeroCoeff);
                        //swjeHuffEncSetLastNonzeroCoeff(pHuffEncoder, lastNonzeroCoeff);
                     }
                     duCount++;
                     
                     /// Huffman
                     JPEG_SWLA_LOG("HUF",1);
                     {
                        //kal_uint32 status = 0;
                        //SWJE_HUFF_ENC_PROCESSDU(pHuffEncoder, compID, status);

                        //if (status < 0)
                        if (swjeHuffEncProcessDU(pHuffEncoder, compID) < 0)
                        {
                           handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
                           JPEG_SWLA_LOG("HUF",0);
                           return handle->lastStatus;
                        }
                     }
                     JPEG_SWLA_LOG("HUF",0);
                  }
                  /// Quantize + FDCT
                  fdctQuantInputBuffer[compID] += fdctQuantSrcWidth[compID] * 8;
               }
            }

            /// Check DRI
            restartInterval--;
            if (0 == restartInterval)
            {
               /// Huffman: Flush the remainder Huffman code
               if (swjeHuffEncFlush(pHuffEncoder) < 0)
               {
                  handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
                  return handle->lastStatus;
               }

               restartInterval = handle->driNum;
               swjeHuffEncInit(pHuffEncoder);

               /// Write RST Marker
               if (JPEG_STATUS_OK != _jpeg_enc_sw_emit_rst(handle))
               {
                  handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
                  return handle->lastStatus;
               }
            }

            /// Check abort function
            abortCheckInterval--;
            if (0 == abortCheckInterval)
            {
               if (check_abort_func)
               {
                  if (!check_abort_func())
                  {
                     handle->codecState = JPEG_CODEC_STATE_ABORT;
                     handle->lastStatus = JPEG_STATUS_ENC_ABORT;
                     return handle->lastStatus;
                  }
               }

               abortCheckInterval = JPEG_ENCODE_ABORT_NUMBER;
            }

            /// Quantize + FDCT + Huffman
            fragOutputBuffer[0] += 8 * hSamplingFactor[0];
            fragOutputBuffer[1] += 8 * hSamplingFactor[1];
            fragOutputBuffer[2] += 8 * hSamplingFactor[2];
         }
         dstCurrentMcuRow -= workingBufferActualMcuNum;
         srcClipX += srcActualMcuWidth;
      }
      srcClipY += srcMcuHeight;

      /// check read/write buffer pointer
      {
         /// rowPixels = 0 has 3 kinds of meanings
         /// 1. direct file output
         /// 2. rotation is not 0
         /// 3. source and destination do not use memory overlap
         if(0 != rowPixels)
         {
             curReadPtr = startReadPtr + (IUL_X_TO_I_CHOP(srcClipY) * rowPixels);

             if(((kal_uint32)(dstFile->dstWritePtr)) > ((kal_uint32)curReadPtr))
             {
                handle->lastStatus = JPEG_STATUS_ENC_ERROR_DST_BUFFER_OVERWRITE_SRC_BUFFER;
                return handle->lastStatus;
             }
         }
      }
   }

#if defined(__JPEG_TIMER_DEBUG__)
   u4EncodeTime[u4EncodeCount] = drv_get_duration_ms(u4EncodeStartTime);
   if (MAX_ENCODE_CNT > (u4EncodeCount + 1))
   {
      u4EncodeCount = u4EncodeCount + 1;
   }
   else
   {
      u4EncodeCount = 0;
   }
#endif
            
   /// We should write all huffman results to dst buffer
   /// Huffman: Flush the remainder Huffman code
   if (swjeHuffEncFlush(pHuffEncoder) < 0)
   {
      handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
      return handle->lastStatus;
   }

   return JPEG_STATUS_OK;
}

#endif  // __JPEG_MCU_BASED_DCT__



#if defined(EXIF_SUPPORT)
static JPEG_STATUS_ENUM _jpeg_enc_sw_get_offset(JPEG_ENCODER_HANDLE handle, kal_uint32* offset)
{
   SWJE_FILE *handleDstFile = &(handle->dstFile);

   if(NULL != (handleDstFile->pDstFileHandle))
   {
      _jpeg_enc_sw_flush_to_file(handleDstFile);
      if((handleDstFile->dstBufferLeft) < 0)
      {
         handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
         return handle->lastStatus;
      }
      if(FSAL_OK != FSAL_Direct_GetCurPos(handleDstFile->pDstFileHandle, offset))
      {
         ASSERT(0);
      }
   }
   else
   {
      *offset = handleDstFile->dstBufferSize - handleDstFile->dstBufferLeft;
   }

   return JPEG_STATUS_OK;
}



static JPEG_STATUS_ENUM _jpeg_enc_sw_set_offset(JPEG_ENCODER_HANDLE handle, kal_uint32 offset)
{
   SWJE_FILE *handleDstFile = &(handle->dstFile);

   if(NULL != (handleDstFile->pDstFileHandle))
   {
      _jpeg_enc_sw_flush_to_file(handleDstFile);
      if((handleDstFile->dstBufferLeft) < 0)
      {
         handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
         return handle->lastStatus;
      }
      if(FSAL_OK != FSAL_Seek(handleDstFile->pDstFileHandle, offset))
      {
         handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
         return handle->lastStatus;
      }
   }
   else
   {
      handleDstFile->dstWritePtr = (kal_uint8 *)(handleDstFile->dstBufferAddr) + offset;
      handleDstFile->dstBufferLeft = handleDstFile->dstBufferSize - offset;
   }

   return JPEG_STATUS_OK;
}



static JPEG_STATUS_ENUM _jpeg_enc_sw_process_app1(JPEG_ENCODER_HANDLE handle)
{
      kal_uint32 app1Size = 0;
      kal_uint32 app1StartPos;
      kal_uint32 dstThumbnailOffset;

      EXIF_DATA *exif_data;
      EXIF_ENTRY exif_entry;

      #if defined(JPEG_CODEC_STANDALONE)
         /// Test. Initial exif structure. Has to remove when check-in.
         //// exif_get_cam_para_struct();
      #endif

      /// Create exif data structure and convert legacy IFD to exif v2.
      exifCreateDataStructure(&exif_data, (void *)handle->exifWorkingBuffer, JPEG_SW_ENC_EXIF_EXT_MAX_MEM_SIZE);
      exifWrapperConvertAllLegacyIFD(exif_data);

      /// Get exif data total size.
      app1Size = exifGetTotalEncodedDataLength(exif_data);

      if(KAL_TRUE == handle->enableThumbnail)
      {
         /// Add JPEG thumbnail offset information
         exifGetEntry(exif_data, EXIF_IFD_1, EXIF_TAG_JPEG_INTERCHANGE_FORMAT, &exif_entry);
         *((unsigned int *)exif_entry.entry_data_addr) = app1Size - 10;
         exifAddEntry(exif_data, EXIF_IFD_1, &exif_entry);
      }

      if (JPEG_STATUS_OK != _jpeg_enc_sw_get_offset(handle, &app1StartPos))
      {
         exifReleaseDataStructure(exif_data);
         ///handle->codecState = JPEG_CODEC_STATE_ERROR;
         return handle->lastStatus;
      }

      if (JPEG_STATUS_OK != _jpeg_enc_sw_set_offset(handle, app1StartPos + app1Size))
      {
         exifReleaseDataStructure(exif_data);
         ///handle->codecState = JPEG_CODEC_STATE_ERROR;
         return handle->lastStatus;
      }

      dstThumbnailOffset = app1StartPos + app1Size;

      if (JPEG_STATUS_OK != _jpeg_enc_sw_set_offset(handle, app1StartPos))
      {
         exifReleaseDataStructure(exif_data);
         ///handle->codecState = JPEG_CODEC_STATE_ERROR;
         return handle->lastStatus;
      }

      /// Insert APP1/EXIF
      {
         SWJE_FILE *handleDstFile = &(handle->dstFile);
         kal_uint8 *dstWritePtr = handleDstFile->dstWritePtr;
         kal_int32 dstBufferLeft = handleDstFile->dstBufferLeft;
         kal_int32 exif_buffer_used = 0;

         if (NULL != (handleDstFile->pDstFileHandle))
         {
             _jpeg_enc_sw_flush_to_file(handleDstFile);
             if((handleDstFile->dstBufferLeft) < 0)
             {
                handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
                return handle->lastStatus;
             }
         }

         /// Config exif v2 encoder settings.
         exifSetDstBuffer(exif_data, dstWritePtr, dstBufferLeft);
         exif_data->byte_order = EXIF_BYTE_ORDER_LITTLE_ENDIAN;
         exif_data->thumbnail_size = 0;

         /// Start exif v2 encoder.
         exifSaveEncodedData(exif_data);

         exif_buffer_used += (unsigned int)exif_data->dst_buffer_ptr - (unsigned int)exif_data->dst_buffer_start_addr;

         /// Release exif data structure.
         exifReleaseDataStructure(exif_data);

         dstWritePtr += exif_buffer_used;
         dstBufferLeft -= exif_buffer_used;

         ASSERT(exif_buffer_used <= (kal_int32)(handleDstFile->dstBufferSize));

         handleDstFile->dstWritePtr = dstWritePtr;
         handleDstFile->dstBufferLeft = dstBufferLeft;

         if (dstBufferLeft < 0)
         {
            handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
            return handle->lastStatus;
         }

         if (NULL != (handleDstFile->pDstFileHandle))
         {
             _jpeg_enc_sw_flush_to_file(handleDstFile);
             if((handleDstFile->dstBufferLeft) < 0)
             {
                handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
                return handle->lastStatus;
             }
         }
      }

      if (JPEG_STATUS_OK != _jpeg_enc_sw_set_offset(handle, dstThumbnailOffset))
      {
         ///handle->codecState = JPEG_CODEC_STATE_ERROR;
         return handle->lastStatus;
      }

   return handle->lastStatus;
}

#endif  /// End of #if defined(EXIF_SUPPORT)



void jpeg_enc_dump_setting(JPEG_ENCODER_HANDLE handle)
{
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
#endif
}


JPEG_STATUS_ENUM jpeg_enc_sw_internal(JPEG_ENCODER_HANDLE handle)
{
   SWJE_FILE* handleDstFile = &(handle->dstFile);

   handle->codecState = JPEG_CODEC_STATE_BUSY;

   if (JPEG_STATUS_OK != jpeg_enc_sw_init_gereral(handle))
   {
      handle->codecState = JPEG_CODEC_STATE_ERROR;
      return handle->lastStatus;
   }

   /// write file header
   if (JPEG_STATUS_OK != _jpeg_enc_sw_write_file_header(handle))
   {
      handle->codecState = JPEG_CODEC_STATE_ERROR;
      return handle->lastStatus;
   }

   #if defined(EXIF_SUPPORT)
      /// EXIF
      if((JPEG_FILE_FORMAT_EXIF == (handle->dstFileFormat)) || (KAL_TRUE == handle->enableThumbnail))
      {
         if (JPEG_STATUS_OK != _jpeg_enc_sw_process_app1(handle))
         {
            handle->codecState = JPEG_CODEC_STATE_ERROR;
            return handle->lastStatus;
         }
      }
   #endif

   /// Encode main image
   handle->curEncodeInfo = &(handle->mainEncodeInfo);
   if (JPEG_STATUS_OK != _jpeg_enc_sw_init_encoder(handle))
   {
      handle->codecState = JPEG_CODEC_STATE_ERROR;
      return handle->lastStatus;
   }

  jpeg_enc_dump_setting(handle);

   if (JPEG_STATUS_OK != _jpeg_enc_sw_process_encoder(handle))
   {
      handle->codecState = JPEG_CODEC_STATE_ERROR;
      return handle->lastStatus;
   }

   /// write frame trailer
   if (JPEG_STATUS_OK != _jpeg_enc_sw_write_file_trailer(handle))
   {
      handle->codecState = JPEG_CODEC_STATE_ERROR;
      return handle->lastStatus;
   }

   /// Flush to file/memory
   if(NULL != (handleDstFile->pDstFileHandle))
   {
      _jpeg_enc_sw_flush_to_file(handleDstFile);
      if((handleDstFile->dstBufferLeft) < 0)
      {
         handle->codecState = JPEG_CODEC_STATE_ERROR;
         handle->lastStatus = JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY;
         return handle->lastStatus;
      }
   }

   handle->codecState = JPEG_CODEC_STATE_COMPLETE;
   ///handle->lastStatus = JPEG_STATUS_OK;

   return handle->lastStatus;
}


/*
#define _jpeg_enc_sw_emit_dht(huffID, dstWritePtr, dstBufferLeft, handleDstFile, pHandle)                                                       \
do                                                                                                                                              \
  {                                                                                                                                             \
     SWJE_HUFF_TABLE *huffTable;                                                                                                                \
     kal_uint32 length = 0;                                                                                                                     \
     kal_uint32 j;                                                                                                                              \
     huffTable = &(pHandle->huffTables[huffID]);                                                                                                \
     JPEG_ENC_SW_EMIT_MARKER(JPEG_MARKER_DHT, dstWritePtr, dstBufferLeft, handleDstFile);                                                      \
     j = 17;                                                                                                                                    \
     while(--j > 0)                                                                                                                             \
     {                                                                                                                                          \
        length += huffTable->pBits[j];                                                                                                          \
     }                                                                                                                                          \
     JPEG_ENC_SW_EMIT_UINT16((kal_uint16)(length + 2 + 1 + 16), dstWritePtr, dstBufferLeft, handleDstFile);                                     \
     JPEG_ENC_SW_EMIT_UINT8((kal_uint8)(((huffTable->type) << 4) | (huffTable->huffTableID)), dstWritePtr, dstBufferLeft, handleDstFile);       \
     for (j = 1; j <= 16; j++)                                                                                                                  \
     {                                                                                                                                          \
        JPEG_ENC_SW_EMIT_UINT8(huffTable->pBits[j], dstWritePtr, dstBufferLeft, handleDstFile);                                                 \
     }                                                                                                                                          \
     for (j = 0; j < length; j++)                                                                                                               \
     {                                                                                                                                          \
        JPEG_ENC_SW_EMIT_UINT8(huffTable->pHuffValue[j], dstWritePtr, dstBufferLeft, handleDstFile);                                            \
     }                                                                                                                                          \
} while (0)

#define _jpeg_enc_sw_emit_dqt(quantTableID, dstWritePtr, dstBufferLeft, handleDstFile, pHandle)                                                 \
do                                                                                                                                              \
  {                                                                                                                                             \
     register kal_int16 *quantTable = pHandle->QuantTables[quantTableID].pIntQuantTable;                                                        \
     register kal_int32 i = 64;                                                                                                                 \
     JPEG_ENC_SW_EMIT_MARKER(JPEG_MARKER_DQT, dstWritePtr, dstBufferLeft, handleDstFile);                                                      \
     JPEG_ENC_SW_EMIT_UINT16((64 + 1 + 2), dstWritePtr, dstBufferLeft, handleDstFile);                                                          \
     JPEG_ENC_SW_EMIT_UINT8(quantTableID, dstWritePtr, dstBufferLeft, handleDstFile);                                                           \
     while (--i >= 0)                                                                                                                           \
     {                                                                                                                                          \
        JPEG_ENC_SW_EMIT_UINT8((kal_uint8)((*quantTable) & 0xFF), dstWritePtr, dstBufferLeft, handleDstFile);                                   \
        quantTable++;                                                                                                                           \
     }                                                                                                                                          \
} while (0)


#define _jpeg_enc_sw_emit_dht(huffID, dstWritePtr, dstBufferLeft, handleDstFile, pHandle)                                                       \
do                                                                                                                                              \
  {                                                                                                                                             \
     SWJE_HUFF_TABLE *huffTable;                                                                                                                \
     kal_uint32 length = 0;                                                                                                                     \
     kal_uint32 j;                                                                                                                              \
     huffTable = &(pHandle->huffTables[huffID]);                                                                                                \
     JPEG_ENC_SW_EMIT_MARKER(JPEG_MARKER_DHT, dstWritePtr, dstBufferLeft, handleDstFile);                                                      \
     j = 17;                                                                                                                                    \
     while(--j > 0)                                                                                                                             \
     {                                                                                                                                          \
        length += huffTable->pBits[j];                                                                                                          \
     }                                                                                                                                          \
     JPEG_ENC_SW_EMIT_UINT16((kal_uint16)(length + 2 + 1 + 16), dstWritePtr, dstBufferLeft, handleDstFile);                                     \
     JPEG_ENC_SW_EMIT_UINT8((kal_uint8)(((huffTable->type) << 4) | (huffTable->huffTableID)), dstWritePtr, dstBufferLeft, handleDstFile);       \
     for (j = 1; j <= 16; j++)                                                                                                                  \
     {                                                                                                                                          \
        JPEG_ENC_SW_EMIT_UINT8(huffTable->pBits[j], dstWritePtr, dstBufferLeft, handleDstFile);                                                 \
     }                                                                                                                                          \
     for (j = 0; j < length; j++)                                                                                                               \
     {                                                                                                                                          \
        JPEG_ENC_SW_EMIT_UINT8(huffTable->pHuffValue[j], dstWritePtr, dstBufferLeft, handleDstFile);                                            \
     }                                                                                                                                          \
} while (0)

*/

#endif
