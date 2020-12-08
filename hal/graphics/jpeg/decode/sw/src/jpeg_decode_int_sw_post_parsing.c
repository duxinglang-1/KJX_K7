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
 *   jpeg_decode_int_sw_post_parsing.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Internal implementation of SW JPEG decode interface: post parsing.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "string.h"
#include "kal_general_types.h"
#include "fsal.h"
#include "jpeg_marker.h"
#include "jpeg_enum.h"
#include "jpeg_decode_structure.h"
#include "jpeg_parse_structure.h"
#include "swjd_huffman_decoder.h"
#include "swje_const_tables.h"

#define JPEG_DEC_CHECK_ABORT()                                                   \
do {                                                                             \
   if (pCheckAbort)                                                              \
   {                                                                             \
      if (!pCheckAbort())                                                        \
      {                                                                          \
         isAborted = KAL_TRUE;                                                   \
         break;                                                                  \
      }                                                                          \
   }                                                                             \
} while(0)


#define JPEG_DEC_SKIP_BYTES(pSrcBuf, count)                                      \
{                                                                                \
   pSrcBuf  += (count);                                                          \
   dataLeft -= (count);                                                          \
}


#define JPEG_DEC_READ_UINT8(pSrcBuf, value)                                      \
{                                                                                \
   value      = pSrcBuf[0];                                                      \
   pSrcBuf  += 1;                                                                \
   dataLeft -= 1;                                                                \
}


#define JPEG_DEC_READ_UINT16(pSrcBuf, value)                                     \
{                                                                                \
   value      = (pSrcBuf[0] << 8) |                                              \
                (pSrcBuf[1] << 0);                                               \
   pSrcBuf  += 2;                                                                \
   dataLeft -= 2;                                                                \
}


#define JPEG_DEC_GET_CUR_POS(currentPos)                                         \
{                                                                                \
   if (KAL_FALSE == FSAL_IsRamFile(pSource))                                     \
   {                                                                             \
      if (FSAL_OK != FSAL_GetCurPos(pSource, &currentPos))                       \
      {                                                                          \
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;                  \
         return handle->lastStatus;                                              \
      }                                                                          \
                                                                                 \
      currentPos -= dataLeft;                                                    \
   }                                                                             \
   else                                                                          \
   {                                                                             \
      currentPos = handle->fileInfo.offsetTableMisc + (pSrcBuf - pBufBase);      \
   }                                                                             \
}


#define JPEG_DEC_FILL_BUFFER(pSource,                                            \
                             pBufBase,                                           \
                             bufSize,                                            \
                             dataLeft)                                           \
{                                                                                \
   kal_uint32  currentPos;                                                       \
   kal_int32   readCount;                                                        \
   FSAL_Status FSALStatus;                                                       \
                                                                                 \
   if (KAL_FALSE == FSAL_IsRamFile(pSource))                                     \
   {                                                                             \
      if (FSAL_OK != FSAL_GetCurPos(pSource, &currentPos))                       \
      {                                                                          \
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;                  \
         return handle->lastStatus;                                              \
      }                                                                          \
      currentPos -= dataLeft;                                                    \
                                                                                 \
      if (FSAL_OK != FSAL_Seek(pSource, currentPos))                             \
      {                                                                          \
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;                  \
         return handle->lastStatus;                                              \
      }                                                                          \
                                                                                 \
      if (JPEG_ENCODE_PROCESS_BASELINE == pFrameInfo->encProcess)                \
      {                                                                          \
         /* Only read 1024 bytes for reducing parsing time */                    \
         readCount = 1024;                                                       \
      }                                                                          \
      else                                                                       \
      {                                                                          \
         readCount = bufSize;                                                    \
      }                                                                          \
                                                                                 \
      FSALStatus = FSAL_Read_Bytes(pSource, pBufBase, readCount);                \
      if ((FSAL_OK != FSALStatus) && (FSAL_READ_OVER_EOF != FSALStatus))         \
      {                                                                          \
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;                  \
         return handle->lastStatus;                                              \
      }                                                                          \
                                                                                 \
      pSrcBuf = pBufBase;                                                        \
      dataLeft = FSAL_GetLastReadCount(pSource);                                 \
   }                                                                             \
                                                                                 \
   if (dataLeft < 0)                                                             \
   {                                                                             \
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;                   \
      return handle->lastStatus;                                                 \
   }                                                                             \
   else if (0 == dataLeft)                                                       \
   {                                                                             \
   	  /* Fake EOR for breaking the parsing loop */                               \
      pBufBase[0] = 0xFF;                                                        \
      pBufBase[1] = 0xD9;                                                        \
      dataLeft = 2;                                                              \
   }                                                                             \
}


static JPEG_STATUS_ENUM _jpeg_dec_post_parsing_dqt(JPEG_DECODER_HANDLE        handle,
                                                   kal_uint8                  *pSrcBuf,
                                                   kal_int32                  dataLeft,
                                                   JPEG_ENCODE_PROCESS_ENUM   frameType)
{
   kal_uint8               PqTq;
   HuffmanDecQuantTable    *pTable;

   ASSERT(handle->lastStatus == JPEG_STATUS_OK);

   while (dataLeft > 0)
   {
      // Read PqTq value
      JPEG_DEC_READ_UINT8(pSrcBuf, PqTq);

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
      if (JPEG_ENCODE_PROCESS_PROGRESSIVE == frameType)
      {
         /// Check Pq. For progressive JPEG file, the Pq should be in [0, 1]
         if ((PqTq >> 4) > 1)
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            return handle->lastStatus;
         }

         PqTq &= 0x0F;  // Masked out Pq
      }
      else
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
      if (JPEG_ENCODE_PROCESS_BASELINE == frameType)
      {
         /// Check Pq. For baseline JPEG file, the Pq must be equal to 0.
         if (0 != (PqTq >> 4))
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            return handle->lastStatus;
         }
      }
      else
      {
         ASSERT(0);
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
         return handle->lastStatus;
      }

      // Check if we already have the specified DQT table
      if (IS_QUANTIZATION_TABLE_READY(handle->tableReadyFlag, PqTq))
      {
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
         return handle->lastStatus;
      }

      /// Check Tq and assign the destination dequantization table to install.
      /// For baseline and progressive JPEG images, the Tq should be in [0, 3]
      if (PqTq > 3)
      {
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
         return handle->lastStatus;
      }

      if (JPEG_CODEC_TYPE_SW == handle->codecType)
      {
         if (!IS_QUANTIZATION_TABLE_READY(handle->tableReadyFlag, PqTq))
         {
            if (NULL == handle->pInverseQuantTable[PqTq])
            {
            #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
               handle->pInverseQuantTable[PqTq] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecQuantTable), 4);
            #else
               handle->pInverseQuantTable[PqTq] = smmMallocAligned(&(handle->intMemorySMM), sizeof(HuffmanDecQuantTable), 4);
               if (NULL == handle->pInverseQuantTable[PqTq])
               {
                  handle->pInverseQuantTable[PqTq] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecQuantTable), 4);
               }
            #endif  // __SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__
            }
         }

         pTable = handle->pInverseQuantTable[PqTq];
         ASSERT(pTable != NULL);

         huffmanDecConstructQuantTable(pSrcBuf, pTable);
      }
      SET_QUANTIZATION_TABLE_READY(handle->tableReadyFlag, PqTq);

      JPEG_DEC_SKIP_BYTES(pSrcBuf, 64);

      if (dataLeft < 0)
      {
         /// If the number of data left is is less than 0,
         /// there must be something wrong.
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
         return handle->lastStatus;
      }
   }

   return JPEG_STATUS_OK;
}


static JPEG_STATUS_ENUM _jpeg_dec_post_parsing_dht(JPEG_DECODER_HANDLE        handle,
                                                   kal_uint8                  *pSrcBuf,
                                                   kal_int32                  dataLeft,
                                                   JPEG_ENCODE_PROCESS_ENUM   frameType)
{
   kal_uint8               TcThVal;
   kal_bool                isDCTable;
   kal_int32               tableIndex;
   void                    *pHuffTable;
   kal_int32               index;
   kal_int32               count;
   kal_uint8               *pHuffBits;
   kal_uint8               *pHuffVal;
   HUFFMAN_DEC_STATUS_ENUM status;

   ASSERT(handle->lastStatus == JPEG_STATUS_OK);

   while (dataLeft > 0)
   {
      // Read the TcTh value
      JPEG_DEC_READ_UINT8(pSrcBuf, TcThVal);

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
      if (JPEG_ENCODE_PROCESS_PROGRESSIVE == frameType)
      {
         /// For progressive JPEG images, the Th must be in [0, 3]
         if ((TcThVal & 0x0F) > 3)
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            return handle->lastStatus;
         }
      }
      else
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
      if (JPEG_ENCODE_PROCESS_BASELINE == frameType)
      {
         /// For baseline JPEG images, the Th must be in [0, 1].
         if ((TcThVal & 0x0F) > 1)
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            return handle->lastStatus;
         }
      }
      else
      {
         ASSERT(0);
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
         return handle->lastStatus;
      }

      pHuffTable = NULL;
      tableIndex = TcThVal & 0x0F;

      /// Check Tc and assign the destination Huffman table to install.
      switch (TcThVal >> 4)
      {
         case 0:
            if (JPEG_ENCODE_PROCESS_BASELINE == frameType)
            {
               // Check if we already have the specified DC DHT table
               if (IS_DC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex))
               {
                  handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
                  return handle->lastStatus;
               }
            }

            SET_DC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex);

            if (JPEG_CODEC_TYPE_SW == handle->codecType)
            {
               if ((NULL == handle->pHuffDCTable[tableIndex]) || (JPEG_ENCODE_PROCESS_PROGRESSIVE == frameType))
               {
               #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
                  handle->pHuffDCTable[tableIndex] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecDCTable), 4);
               #else
                  handle->pHuffDCTable[tableIndex] = smmMallocAligned(&(handle->intMemorySMM), sizeof(HuffmanDecDCTable), 4);
                  if (NULL == handle->pHuffDCTable[tableIndex])
                  {
                     handle->pHuffDCTable[tableIndex] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecDCTable), 4);
                  }
               #endif
               }

               pHuffTable = handle->pHuffDCTable[tableIndex];
               ASSERT(NULL != pHuffTable);               
            }
            // Set DC table flag to true
            isDCTable = KAL_TRUE;
            break;
         case 1:
            if (JPEG_ENCODE_PROCESS_BASELINE == frameType)
            {
               // Check if we already have the specified AC DHT table
               if (IS_AC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex))
               {
                  handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
                  return handle->lastStatus;
               }
            }

            SET_AC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex);

            if (JPEG_CODEC_TYPE_SW == handle->codecType)
            {
               if ((NULL == handle->pHuffACTable[tableIndex]) || (JPEG_ENCODE_PROCESS_PROGRESSIVE == frameType))
               {
                  // Allocate memory for Huffman AC table
               #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
                  handle->pHuffACTable[tableIndex] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecACTable), 4);
               #else
                  handle->pHuffACTable[tableIndex] = smmMallocAligned(&(handle->intMemorySMM), sizeof(HuffmanDecACTable), 4);
                  if (NULL == handle->pHuffACTable[tableIndex])
                  {
                     handle->pHuffACTable[tableIndex] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecACTable), 4);
                  }
               #endif
               }

               pHuffTable = handle->pHuffACTable[tableIndex];
               ASSERT(NULL != pHuffTable);
            }
            // Set DC table flag to false
            isDCTable = KAL_FALSE;
            break;
         default:
            ASSERT(0);
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            return handle->lastStatus;
      }

      /// Point the Li array.
      pHuffBits = pSrcBuf;

      /// Calculate the total number of Huffman codes.
      index = 16;
      count = 0;
      while (--index >= 0)
      {
         count += pHuffBits[index];
      }

      JPEG_DEC_SKIP_BYTES(pSrcBuf, 16);

      if ((count > 256) || (count > dataLeft))
      {
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
         return handle->lastStatus;
      }

      if (JPEG_CODEC_TYPE_SW == handle->codecType)
      {
         pHuffVal = pSrcBuf;

         if (KAL_TRUE == isDCTable)
         {
            // Construct the DC huffman table for decoding DC coefficients
            status = huffmanDecConstructDCTable(pHuffBits, pHuffVal, pHuffTable);
         }
         else
         {
            // Construct the AC huffman table for decoding AC coefficients
            status = huffmanDecConstructACTable(pHuffBits, pHuffVal, pHuffTable);
         }

         if (status < 0)
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            return handle->lastStatus;
         }
      }

      JPEG_DEC_SKIP_BYTES(pSrcBuf, count);

      if (dataLeft < 0)
      {
         /// If the number of data left is is less than the number 
         /// of Huffman codes, there must be something wrong.
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
         return handle->lastStatus;
      }
   }

   return JPEG_STATUS_OK;
}


static JPEG_STATUS_ENUM _jpeg_dec_set_source_buffer(JPEG_DECODER_HANDLE handle,
                                                    kal_int32           scanCount,
                                                    kal_uint32          *pScanPos)
{
   STFSAL         *pSource;
   kal_uint32     fileSize;
   kal_uint8      *pSrcBuf;
   kal_int32      bufSize;
   HuffmanDecoder *pDecoder;
   kal_int32      scanIndex;

   pSource = handle->fileInfo.fileHandle;
   ASSERT(NULL != pSource);

   if (KAL_TRUE == FSAL_IsRamFile(pSource))
   {
      pSrcBuf = FSAL_GetRamFilePointer(pSource);
      bufSize = 0;
   }
   else
   {
      pSrcBuf = handle->fsalReadBufferAddr;
      bufSize = handle->fsalReadBufferSize;

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
      // Average the buffer size for each scan
      bufSize = (bufSize / scanCount);
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
   }

   pDecoder = handle->pHuffDecoder;
   ASSERT(NULL != pDecoder);

   scanIndex = 0;
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
   do
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
	{
	   if (KAL_TRUE == FSAL_IsRamFile(pSource))
	   {
	   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
	      if ((scanIndex + 1) < scanCount)
         {
            bufSize = pScanPos[scanIndex + 1] - pScanPos[scanIndex];
         }
         else
      #endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
         {
            // Get the real file size
            FSAL_GetFileSize(pSource, &(fileSize));

            bufSize = fileSize - pScanPos[scanIndex];
         }
	   
         huffmanDecSetSourceFile(pDecoder,
                                 scanIndex,
                                 pSource,
                                 pScanPos[scanIndex],
                                 pSrcBuf + pScanPos[scanIndex],
                                 bufSize);
      }
	   else
	   {
	      huffmanDecSetSourceFile(pDecoder,
                                 scanIndex,
                                 pSource,
                                 pScanPos[scanIndex],
                                 pSrcBuf,
                                 bufSize);
     #if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
         pSrcBuf += bufSize;
     #endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
     }
     
      scanIndex++;
   }

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
   while(scanIndex < scanCount);
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE

   return JPEG_STATUS_OK;
}


JPEG_STATUS_ENUM jpeg_dec_post_parsing(JPEG_DECODER_HANDLE handle)
{
   JPEG_FRAME_INFO            *pFrameInfo;
   kal_bool                   isAborted;
   CHECK_ABORT_FUNC           pCheckAbort;
   STFSAL                     *pSource;
   kal_uint32                 fileSize;
   kal_uint8                  *pBufBase;
   kal_uint8                  *pSrcBuf;
   kal_int32                  bufSize;
   kal_int32                  dataLeft;
   kal_uint32                 marker;
   kal_uint16                 markerLength;
   HuffmanDecoder             *pHuffDecoder;
   kal_uint8                  tempVal;
   kal_int32                  loopIndex;
   kal_uint32                 compIndex;
   kal_uint8                  compCount;
   kal_uint8                  curCompID;
   kal_int32                  compInfo[3];
   kal_int32                  tableIndex;
   kal_uint8                  huffTable[3];
   HuffmanDecDCTable          *pDCTable;
   HuffmanDecACTable          *pACTable;
   kal_int32                  scanIndex;
   kal_uint8                  spectralStart;
   kal_uint8                  spectralEnd;
   kal_int32                  precisionLow;
   kal_int32                  precisionHigh;
   kal_uint32                 scanPos[15];
   kal_uint32                 currentPos;
   kal_uint32                 compReady;

#if 0 //defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
/* under construction !*/
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE


   handle->tableReadyFlag = 0;
   handle->tableLoadFlag  = 0;

   pFrameInfo = &(handle->fileInfo.frameInfo);

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   switch(handle->rotationAngle)
   {
      case JPEG_DECODE_FLIP_HORIZONTAL_ONLY:
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_180:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_0:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_180:
#endif  // defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
         dequantIDCTQueryScaleShift(pFrameInfo->width,
                                    pFrameInfo->height,
                                    handle->outputWnd.w,
                                    handle->outputWnd.h,
                                    &handle->dctScaleBits,
                                    &handle->dctLod);
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
         break;
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_90:
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_270:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_90:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_270:
         dequantIDCTQueryScaleShift(pFrameInfo->height,
                                    pFrameInfo->width,
                                    handle->outputWnd.w,
                                    handle->outputWnd.h,
                                    &handle->dctScaleBits,
                                    &handle->dctLod);
         break;
   }
#endif  // defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)

   pSource = handle->fileInfo.fileHandle;

   // Check if the source image is in the RAM?
   if (KAL_FALSE == FSAL_IsRamFile(pSource))
   {
      // Set the image file offset to table start offset.
      if (FSAL_OK != FSAL_Seek(pSource, handle->fileInfo.offsetTableMisc))
      {
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return handle->lastStatus;
      }

      pBufBase = handle->fsalReadBufferAddr;
      pSrcBuf  = NULL;
      bufSize  = handle->fsalReadBufferSize;
      dataLeft = 0;
   }
   else
   {
      pBufBase = FSAL_GetRamFilePointer(pSource) + handle->fileInfo.offsetTableMisc;
      pSrcBuf  = pBufBase;

      // Get the real file size
      FSAL_GetFileSize(pSource, &(fileSize));

      bufSize  = fileSize - handle->fileInfo.offsetTableMisc;
      dataLeft = bufSize;
   }

   isAborted    = KAL_FALSE;
   compReady    = 0;
   markerLength = 0;
   pCheckAbort  = handle->pCheckAbort;

   while (KAL_FALSE == isAborted)
   {
      JPEG_DEC_CHECK_ABORT();

      if (dataLeft <= 0)
      {
         JPEG_DEC_FILL_BUFFER(pSource,
                              pBufBase,
                              bufSize,
                              dataLeft);
      }

      while ((JPEG_MARKER_START_CODE != pSrcBuf[0]) ||
             (JPEG_MARKER_START_CODE == pSrcBuf[1]) ||
             (JPEG_MARKER_SKIP_CODE  == pSrcBuf[1]))
      {
         if (dataLeft <= 2)
         {
            JPEG_DEC_FILL_BUFFER(pSource,
                                 pBufBase,
                                 bufSize,
                                 dataLeft);
         }

         if ((JPEG_MARKER_START_CODE == pSrcBuf[0]) &&
             (JPEG_MARKER_START_CODE != pSrcBuf[1]))
         {
            if (JPEG_MARKER_SKIP_CODE == pSrcBuf[1])
            {
               // Skip dummy bytes
               JPEG_DEC_SKIP_BYTES(pSrcBuf, 2);
            }
            else
            {
               /// A maker is detected
               break;
            }
         }
         else
         {
            /// No marker is detected, skip one byte.
            JPEG_DEC_SKIP_BYTES(pSrcBuf, 1);
         }
      }

      marker = pSrcBuf[1];

      /// Found a marker, try to get the length.
      if (JPEG_MARKER_EOI != marker)
      {
         if (dataLeft < 4)
         {
            JPEG_DEC_FILL_BUFFER(pSource,
                                 pBufBase,
                                 bufSize,
                                 dataLeft);
         }        

         JPEG_DEC_SKIP_BYTES(pSrcBuf, 2);

         JPEG_DEC_READ_UINT16(pSrcBuf, markerLength);

         // Assure we have read enough data in the buffers
         if (dataLeft < (markerLength - 2))
         {
            JPEG_DEC_FILL_BUFFER(pSource,
                                 pBufBase,
                                 bufSize,
                                 dataLeft);
         }
      }

      // Parse the JPEG image file according to the baseline or progressive images:
      // 1. For baseline image, the parsing is stopped when the scan is found
      // 2. For progressive image, the parsing is stopped when the following:
      //    2-1. The EOI marker is encountered
      //    2-2. More than 12 scans are found
      switch (marker)
      {
         case JPEG_MARKER_SOS:
            JPEG_DEC_READ_UINT8(pSrcBuf, compCount);

            if ((markerLength != (compCount * 2 + 6)) ||
                (compCount > JPEG_MAX_COMPONENT_COUNT))
            {
               handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
               return handle->lastStatus;
            }

         #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
            if (JPEG_CODEC_TYPE_HW == handle->codecType)
            {
               for (loopIndex = 0; loopIndex < compCount; loopIndex++)
               {
                  // Current component selector
                  JPEG_DEC_READ_UINT8(pSrcBuf, curCompID);

                  for (compIndex = 0; compIndex < pFrameInfo->numberOfComponents; compIndex++)
                  {
                     if (curCompID == pFrameInfo->frameComponentInfo[compIndex].componentID)
                     {
                        // We have found the component with the specified ID
                        compInfo[loopIndex] = compIndex;
                        break;
                     }
                  }

                  ASSERT(compIndex < pFrameInfo->numberOfComponents);

                  tableIndex = pFrameInfo->frameComponentInfo[compIndex].qTableSelector;

                  if (!IS_QUANTIZATION_TABLE_READY(handle->tableReadyFlag, tableIndex))
                  {
                     handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
                     return handle->lastStatus;
                  }

                  // Read Huffman table selector
                  JPEG_DEC_READ_UINT8(pSrcBuf, tempVal);

                  // Get DC Huffman table index for this component.
                  tableIndex = tempVal >> 0x04;

                  // If we have no DC table, try using default Huffman DC table.
                  if (!IS_DC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex))
                  {
                  #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
                     // load table when read file buffer ..
                  #else
                     handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
                     return handle->lastStatus;
                  #endif
                  }

                  // We don't need to check the existence of AC Huffman table for
                  // the first scan of progressive JPEG images
                  if (JPEG_ENCODE_PROCESS_BASELINE == pFrameInfo->encProcess)
                  {
                     // Get AC Huffman table index for this component.
                     tableIndex = tempVal & 0x0F;

                     // If we have no AC table, try using default Huffman AC table.
                     if (!IS_AC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex))
                     {
                     #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
                        // load table when read file buffer ..
                     #else
                        handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
                        return handle->lastStatus;
                     #endif
                     }
                  }
               }
            
               // Set the file offset to table start address.
               if (FSAL_OK != FSAL_Seek(pSource, handle->fileInfo.offsetTableMisc))
               {
                  handle->lastStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
                  return handle->lastStatus;
               }

               if (!(handle->fileIsInMemory))
               {
                  rsbInit(&(handle->rsBuffer), handle->fsalReadBufferAddr, handle->fsalReadBufferSize, RSB_LITTLE_ENDIAN, RSB_OP_SEQUENTIAL_BUFFER);
               }

               handle->dataLeft = handle->fileInfo.realSize - (handle->fileInfo.offsetTableMisc - handle->fileInfo.realOffset);
               // add additional 64 byte and 4 byte alignment for hw limitation
               handle->dataLeft = (handle->dataLeft + 64 + 0x3) & (~0x3);

               handle->lastStatus = JPEG_STATUS_OK;
               return handle->lastStatus;
            }
            else
         #endif  // __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__
            {
               pHuffDecoder = handle->pHuffDecoder;
               ASSERT(NULL != pHuffDecoder);

               for (loopIndex = 0; loopIndex < compCount; loopIndex++)
               {
                  // Current component selector
                  JPEG_DEC_READ_UINT8(pSrcBuf, curCompID);

                  for (compIndex = 0; compIndex < pFrameInfo->numberOfComponents; compIndex++)
                  {
                     if (curCompID == pFrameInfo->frameComponentInfo[compIndex].componentID)
                     {
                        compInfo[loopIndex] = compIndex;
                        break;
                     }
                  }
                  ASSERT(compIndex < pFrameInfo->numberOfComponents);

                  tableIndex = pFrameInfo->frameComponentInfo[compIndex].qTableSelector;

                  // Treat the source image as a corrupted image
                  // if the quantization table is not ready.
                  if (!IS_QUANTIZATION_TABLE_READY(handle->tableReadyFlag, tableIndex))
                  {
                     handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
                     return handle->lastStatus;
                  }

                  ASSERT(NULL != handle->pInverseQuantTable[tableIndex]);

                  huffmanDecSetQuantTable(pHuffDecoder,
                                          compIndex,
                                          handle->pInverseQuantTable[tableIndex]);


                  // Read Huffman table selector
                  JPEG_DEC_READ_UINT8(pSrcBuf, tempVal);
                  huffTable[loopIndex] = tempVal;
               }
            }

            // Fetch the spectral start value of this scan
            JPEG_DEC_READ_UINT8(pSrcBuf, spectralStart);

            // Fetch the spectral end value of this scan
            JPEG_DEC_READ_UINT8(pSrcBuf, spectralEnd);

            // Fetch precision low and high of this scan
            JPEG_DEC_READ_UINT8(pSrcBuf, tempVal);

            // Get the precision low and high of this scan.
            precisionLow  = tempVal &  0x0F;
            precisionHigh = tempVal >> 0x04;

            if ((JPEG_ENCODE_PROCESS_BASELINE == pFrameInfo->encProcess) ||
                ((0 == handle->dctLod) && (spectralEnd == handle->dctLod)) ||
                ((0 != handle->dctLod) && (spectralStart <= handle->dctLod)) ||
                ((0 != handle->dctLod) && (0 == precisionHigh)))
            {
               // Currently, we can only support max 15 scans.
               huffmanDecAddScanInfo(pHuffDecoder, &scanIndex);
               ASSERT(scanIndex < 15);

               // Set spectral info for the scan
               huffmanDecSetSepctral(pHuffDecoder, scanIndex, spectralStart, spectralEnd);

               huffmanDecSetPrecision(pHuffDecoder, scanIndex, precisionLow, precisionHigh);

               // Get ECS data start position
               JPEG_DEC_GET_CUR_POS(currentPos);

               // Record the scan position
               scanPos[scanIndex] = currentPos;

               for (loopIndex = 0; loopIndex < compCount; loopIndex++)
               {
                  huffmanDecAddComponentInfo(pHuffDecoder,
                                             scanIndex,
                                             compInfo[loopIndex]);
                  


                  // If we have no DC table, try using default Huffman DC table.
                  if ((0 == spectralStart) && (0 == scanIndex))
                  {
                     // The scan may be one of the following two types:
                     // 1. The first scan data of baseline JPEG image.
                     // 2. The DC first scan of progressive JPEG image.
                     
                     // Get DC Huffman table index for this component.
                     tableIndex = huffTable[loopIndex] >> 0x04;

                     if (!IS_DC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex))
                     {
                        if (NULL == handle->pHuffDCTable[tableIndex])
                        {
                           // Allocate memory for Huffman DC table
                        #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
                           handle->pHuffDCTable[tableIndex] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecDCTable), 4);
                        #else
                           handle->pHuffDCTable[tableIndex] = smmMallocAligned(&(handle->intMemorySMM), sizeof(HuffmanDecDCTable), 4);
                           if (NULL == handle->pHuffDCTable[tableIndex])
                           {
                              handle->pHuffDCTable[tableIndex] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecDCTable), 4);
                           }
                        #endif
                        }
                        ASSERT(NULL != handle->pHuffDCTable[tableIndex]);

                        if (0 == loopIndex)
                        {
                           // The first component is the luminance component
                           huffmanDecConstructDCTable((kal_uint8*)&swje_dc_luminance_bits_table[1],
                                                      (kal_uint8*)swje_dc_luminance_val_table,
                                                      handle->pHuffDCTable[tableIndex]);
                        }
                        else
                        {
                           // The other components are the chrominance components
                           huffmanDecConstructDCTable((kal_uint8*)&swje_dc_chrominance_bits_table[1],
                                                      (kal_uint8*)swje_dc_chrominance_val_table,
                                                      handle->pHuffDCTable[tableIndex]);
                        }

                        SET_DC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex);
                     }
                     pDCTable = handle->pHuffDCTable[tableIndex];
                  }
                  else
                  {
                     // The DC refine scan
                     pDCTable = NULL;
                  }

                  if (0 < spectralEnd)
                  {
                     // Get AC Huffman table index for this component.
                     tableIndex = huffTable[loopIndex] & 0x0F;

                     // If we have no AC table, try using default Huffman AC table.
                     if (!IS_AC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex))
                     {
                        if (NULL == handle->pHuffACTable[tableIndex])
                        {
                           // Allocate memory for Huffman AC table
                        #if !defined(__SW_JPEG_DEC_V2_USING_INTERNAL_MEMORY__)
                           handle->pHuffACTable[tableIndex] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecACTable), 4);
                        #else
                           handle->pHuffACTable[tableIndex] = smmMallocAligned(&(handle->intMemorySMM), sizeof(HuffmanDecACTable), 4);
                           if (NULL == handle->pHuffACTable[tableIndex])
                           {
                              handle->pHuffACTable[tableIndex] = smmMallocAligned(&(handle->extMemorySMM), sizeof(HuffmanDecACTable), 4);
                           }
                        #endif
                        }
                        ASSERT(NULL != handle->pHuffACTable[tableIndex]);

                        if (0 == loopIndex)
                        {
                           huffmanDecConstructACTable((kal_uint8*)&swje_ac_luminance_bits_table[1],
                                                      (kal_uint8*)swje_ac_luminance_val_table,
                                                      handle->pHuffACTable[tableIndex]);
                        }
                        else
                        {
                           huffmanDecConstructACTable((kal_uint8*)&swje_ac_chrominance_bits_table[1],
                                                      (kal_uint8*)swje_ac_chrominance_val_table,
                                                      handle->pHuffACTable[tableIndex]);
                        }
            
                        SET_AC_HUFFMAN_TABLE_READY(handle->tableReadyFlag, tableIndex);
                     }
                     pACTable = handle->pHuffACTable[tableIndex];
                  }
                  else
                  {
                     pACTable = NULL;
                  }

                  huffmanDecSetHuffmanTable(pHuffDecoder,
                                            scanIndex,
                                            compInfo[loopIndex],
                                            pDCTable,
                                            pACTable);

                  // Check if we have the coefficients with the specified precision
                  //if ((spectralEnd >= handle->dctLod) && (0 == precisionLow))
                  if (((spectralEnd >= handle->dctLod) && (0 == precisionLow)) || 
                      ((JPEG_ENCODE_PROCESS_PROGRESSIVE == pFrameInfo->encProcess) && (spectralEnd >= handle->dctLod)))
                  {
                     compReady |= (1 << compInfo[loopIndex]);
                  }
               }
            }

            if (compReady == ((1 << pFrameInfo->numberOfComponents) - 1))
            {
               // The scan needed is collected by post parsing, we may start decoding after setting the buffers.
               _jpeg_dec_set_source_buffer(handle,
                                           scanIndex + 1,
                                           scanPos);
               return handle->lastStatus;
            }
         #if 0 //defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE

         break;
         case JPEG_MARKER_DHT:
            /// Parse the DHT and install the decode Huffman table.
            if (JPEG_STATUS_OK != _jpeg_dec_post_parsing_dht(handle,
                                                                pSrcBuf,
                                                                markerLength - 2,
                                                                pFrameInfo->encProcess))
            {
               return handle->lastStatus;
            }
            JPEG_DEC_SKIP_BYTES(pSrcBuf, markerLength - 2);
         break;
         case JPEG_MARKER_DQT:
            /// Parse the DHT and install the decode Huffman table.
            if (JPEG_STATUS_OK != _jpeg_dec_post_parsing_dqt(handle,
                                                             pSrcBuf,
                                                             markerLength - 2,
                                                             pFrameInfo->encProcess))
            {
               return handle->lastStatus;
            }
            JPEG_DEC_SKIP_BYTES(pSrcBuf, markerLength - 2);
         break;
         case JPEG_MARKER_DRI:
            if (markerLength != 4)
            {
               handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
               return handle->lastStatus;
            }

            JPEG_DEC_READ_UINT16(pSrcBuf, handle->restartInterval);
         break;
         case JPEG_MARKER_EOI:
            // Set the source buffer for decoding.
            if (compReady == ((1 << pFrameInfo->numberOfComponents) - 1))
            {
               _jpeg_dec_set_source_buffer(handle,
                                           scanIndex + 1,
                                           scanPos);
            }
            else
            {
               handle->lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            }
            return handle->lastStatus;
         case JPEG_MARKER_COM:   
         case JPEG_MARKER_SOF0:
         case JPEG_MARKER_SOF1:
         case JPEG_MARKER_SOF2:
         case JPEG_MARKER_SOF3:
         case JPEG_MARKER_DAC:
         default:
            /// Any other marker may appear???
            JPEG_DEC_SKIP_BYTES(pSrcBuf, markerLength - 2);
         break;
      }
   }

   // When the post parsing is aborted, we need to 
   // notify the IDLE state to the upper layer.
   if ((KAL_TRUE == isAborted) && handle->callback_function)
   {
      handle->codecState = JPEG_CODEC_STATE_IDLE;
      handle->lastStatus = JPEG_STATUS_OK;
         
      handle->callback_function(handle->codecState);
   }

   return JPEG_STATUS_DEC_ERROR_PARSE_INCOMPLETE;
}
