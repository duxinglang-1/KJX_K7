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
 *   swje_huffman_encoder.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SWJD_HUFFMAN_DECODER_H__
#define __SWJE_HUFFMAN_ENCODER_H__

#include "kal_general_types.h"

#include "swje_structure.h"

/**
 * @brief                  Init Huffman encoder handler.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncInit(SWJE_HUFFMAN_ENCODER *huffmanEncoder);



/**
 * @brief                  Generate Huffman table.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncGenHuffTable(SWJE_HUFF_TABLE* pAllHuffTable);



/**
 * @brief                  Set Huffman table to DC.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncSetDCHuffTable(SWJE_HUFFMAN_ENCODER *huffmanEncoder, kal_uint32 compID, SWJE_HUFF_TABLE* pHuffTable);



/**
 * @brief                  Set Huffman table to AC.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncSetACHuffTable(SWJE_HUFFMAN_ENCODER *huffmanEncoder, kal_uint32 compID, SWJE_HUFF_TABLE* pHuffTable);



/**
 * @brief                  Set source canvas buffer address.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncGetHuffSrcBuffer(SWJE_HUFFMAN_ENCODER *huffmanEncoder, kal_uint8 *srcPtr);



/**
 * @brief                  Set source canvas buffer address.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncSetHuffSrcBuffer(SWJE_HUFFMAN_ENCODER *huffmanEncoder, kal_uint8 *dstWritePtr);



/**
 * @brief                  Set the output buffer address/file handler.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncSetHuffDstBuffer(SWJE_HUFFMAN_ENCODER *huffmanEncoder, SWJE_FILE *dstFile);



/**
 * @brief                  Start to do huffman encode.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncProcessDU(SWJE_HUFFMAN_ENCODER *huffmanEncoder, kal_uint32 compID);



/**
 * @brief                  Flush the remainder Huffman code.
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncFlush(SWJE_HUFFMAN_ENCODER *huffmanEncoder);



/**
 * @brief                  .
 * @param pFragProcessor   
 * @param srcStepX         
 * @return                 If the function succeeds, the return value is 0; otherwise the error code is returned.
 * @remarks
 */
kal_int32 swjeHuffEncSetLastNonzeroCoeff(SWJE_HUFFMAN_ENCODER *huffmanEncoder, kal_uint32 lastNonzeroCoeff);


#define SWJE_HUFF_ENC_SET_LAST_NONZERO_COEFF(phuffmanEncoder, lastNonzeroCoeff)\
do {                                                                           \
   phuffmanEncoder->lastNonzeroCoeff = lastNonzeroCoeff;                       \
}while(0)


kal_uint32 _swje_huff_enc_clz_uint32(kal_uint32 n);
#include "swje_const_tables.h"
//kal_int32 swjeHuffEncProcessDU(SWJE_HUFFMAN_ENCODER *huffmanEncoder, kal_uint32 compID) 
#define SWJE_HUFF_ENC_PROCESSDU(huffmanEncoder, compID, status)                                   \
do {                                                                                              \
   SWJE_HUFFMAN_COMPONENT *huffComponent = &(huffmanEncoder->huffComponent[compID]);              \
   SWJE_HUFF_TABLE* pACHuffTable = huffComponent->pACHuffTable;                                   \
   SWJE_HUFF_TABLE* pDCHuffTable = huffComponent->pDCHuffTable;                                   \
                                                                                                  \
   kal_int32 *srcPtr32;                                                                           \
   kal_int16 *srcPtr16;                                                                           \
   kal_int32 srcValue;                                                                            \
   SWJE_FILE *huffmanDstFile = huffmanEncoder->dstFile;                                           \
   register kal_uint8 *dstWritePtr = huffmanDstFile->dstWritePtr;                                 \
   register kal_int32 dstBufferLeft = huffmanDstFile->dstBufferLeft;                              \
                                                                                                  \
   kal_uint32 put_buffer = huffmanEncoder->unfinishEncodedBits;                                   \
   kal_uint32 put_bits = huffmanEncoder->unfinishEncodedSize;                                     \
   kal_uint32 srcLength = huffmanEncoder->srcLength;                                              \
                                                                                                  \
                                                                                                  \
   if(32 == srcLength)                                                                            \
   {                                                                                              \
      srcPtr32 = ((kal_int32 *)huffmanEncoder->pSrc);                                             \
      srcValue = srcPtr32[0];                                                                     \
   }                                                                                              \
   else                                                                                           \
   {                                                                                              \
      srcPtr16 = ((kal_int16 *)huffmanEncoder->pSrc);                                             \
      srcValue = (kal_int32)(srcPtr16[0]);                                                        \
   }                                                                                              \
   {                                                                                              \
      kal_int32 dc_diff;                                                                          \
      register kal_int32 size;                                                                    \
      register kal_uint32 code;                                                                   \
      kal_int32 nbits;                                                                            \
                                                                                                  \
      dc_diff = srcValue - huffComponent->lastDcVal;                                              \
      huffComponent->lastDcVal = srcValue;                                                        \
      srcValue = dc_diff;                                                                         \
                                                                                                  \
      if (dc_diff < 0)                                                                            \
      {                                                                                           \
         nbits = sizeof(kal_uint32) * 8 - _swje_huff_enc_clz_uint32(-dc_diff);                    \
         dc_diff -= 1;                                                                            \
      }                                                                                           \
      else                                                                                        \
      {                                                                                           \
         nbits = sizeof(kal_uint32) * 8 - _swje_huff_enc_clz_uint32(dc_diff);                     \
      }                                                                                           \
                                                                                                  \
      dc_diff &= _swje_huff_enc_bitmask_table[nbits];                                             \
                                                                                                  \
      size = pDCHuffTable->pHufFSize[nbits];                                                      \
      code = pDCHuffTable->pHuffCode[nbits] & _swje_huff_enc_bitmask_table[size];                 \
                                                                                                  \
      size += nbits;                                                                              \
      code = dc_diff | (code << nbits);                                                           \
                                                                                                  \
      size += put_bits;                                                                           \
      code <<= 32 - size;                                                                         \
      code |= put_buffer;                                                                         \
      while (size >= 8)                                                                           \
      {                                                                                           \
         kal_uint8 c = (code >> 24) & 0xFF;                                                       \
                                                                                                  \
         JPEG_ENC_SW_EMIT_UINT8(c, dstWritePtr, dstBufferLeft, huffmanDstFile);                   \
                                                                                                  \
         if (0xFF == c)                                                                           \
         {                                                                                        \
            code &= 0x00FFFFFF;                                                                   \
         }                                                                                        \
         else                                                                                     \
         {                                                                                        \
            code <<= 8;                                                                           \
            size -= 8;                                                                            \
         }                                                                                        \
      }                                                                                           \
      put_bits = size;                                                                            \
      put_buffer = code;                                                                          \
   }                                                                                              \
                                                                                                  \
   {                                                                                              \
      kal_int32 k = 63;                                                                           \
      kal_int16 *block16;                                                                         \
      kal_int32 *block32;                                                                         \
      kal_uint32 lastZeroCoeffNum = 0;                                                            \
                                                                                                  \
      register kal_int32 r = 0;                                                                   \
                                                                                                  \
      kal_uint8 *ac_huffman_size_tbl = pACHuffTable->pHufFSize;                                   \
      kal_uint16 *ac_huffman_code_tbl = pACHuffTable->pHuffCode;                                  \
                                                                                                  \
      {                                                                                           \
         k = huffmanEncoder->lastNonzeroCoeff;                                                    \
         lastZeroCoeffNum = 63 - k;                                                               \
      }                                                                                           \
                                                                                                  \
      if(32 == srcLength)                                                                         \
      {                                                                                           \
          block32 = &srcPtr32[1];                                                                 \
      }                                                                                           \
      else                                                                                        \
      {                                                                                           \
          block16 = &srcPtr16[1];                                                                 \
      }                                                                                           \
                                                                                                  \
      while (--k >= 0)                                                                            \
      {                                                                                           \
         register kal_int32 tmp_block;                                                            \
                                                                                                  \
         if(32 == srcLength)                                                                      \
         {                                                                                        \
            tmp_block = *block32++;                                                               \
         }                                                                                        \
         else                                                                                     \
         {                                                                                        \
            tmp_block = *block16++;                                                               \
         }                                                                                        \
                                                                                                  \
         if (!tmp_block)                                                                          \
         {                                                                                        \
            r++;                                                                                  \
         }                                                                                        \
         else                                                                                     \
         {                                                                                        \
            register kal_uint32 code;                                                             \
            register kal_int32 size;                                                              \
            register kal_int32 nbits;                                                             \
                                                                                                  \
            while (r > 15)                                                                        \
            {                                                                                     \
               code = ac_huffman_code_tbl[0xF0];                                                  \
               size = ac_huffman_size_tbl[0xF0];                                                  \
                                                                                                  \
               size += put_bits;                                                                  \
               code <<= 32 - size;                                                                \
               code |= put_buffer;                                                                \
               while (size >= 8)                                                                  \
               {                                                                                  \
                  kal_uint8 c = (code >> 24) & 0xFF;                                              \
                                                                                                  \
                  JPEG_ENC_SW_EMIT_UINT8(c, dstWritePtr, dstBufferLeft, huffmanDstFile);          \
                                                                                                  \
                  if (0xFF == c)                                                                  \
                  {                                                                               \
                     code &= 0x00FFFFFF;                                                          \
                  }                                                                               \
                  else                                                                            \
                  {                                                                               \
                     code <<= 8;                                                                  \
                     size -= 8;                                                                   \
                  }                                                                               \
               }                                                                                  \
               put_bits = size;                                                                   \
               put_buffer = code;                                                                 \
                                                                                                  \
               r -= 16;                                                                           \
            }                                                                                     \
                                                                                                  \
            if (tmp_block < 0)                                                                    \
            {                                                                                     \
               nbits = (sizeof(kal_uint32) * 8 - _swje_huff_enc_clz_uint32(-tmp_block));          \
                                                                                                  \
               tmp_block -= 1;                                                                    \
            }                                                                                     \
            else                                                                                  \
            {                                                                                     \
               nbits = (sizeof(kal_uint32) * 8 - _swje_huff_enc_clz_uint32(tmp_block));           \
            }                                                                                     \
                                                                                                  \
            code = nbits + (r << 4);                                                              \
                                                                                                  \
            r = 0;                                                                                \
                                                                                                  \
            {                                                                                     \
               kal_int32 size1 = ac_huffman_size_tbl[code];                                       \
               kal_int32 size2 = nbits;                                                           \
               kal_uint32 code1 = ac_huffman_code_tbl[code];                                      \
               kal_uint32 code2 = tmp_block & _swje_huff_enc_bitmask_table[nbits];                \
                                                                                                  \
               size = size1 + size2;                                                              \
               if (24 > size)                                                                     \
               {                                                                                  \
                  code = code2 | (code1 << size2);                                                \
                                                                                                  \
                  size += put_bits;                                                               \
                  code <<= 32 - size;                                                             \
                  code |= put_buffer;                                                             \
                  while (size >= 8)                                                               \
                  {                                                                               \
                     kal_uint8 c = (code >> 24) & 0xFF;                                           \
                                                                                                  \
                     JPEG_ENC_SW_EMIT_UINT8(c, dstWritePtr, dstBufferLeft, huffmanDstFile);       \
                                                                                                  \
                     if (0xFF == c)                                                               \
                     {                                                                            \
                        code &= 0x00FFFFFF;                                                       \
                     }                                                                            \
                     else                                                                         \
                     {                                                                            \
                        code <<= 8;                                                               \
                        size -= 8;                                                                \
                     }                                                                            \
                  }                                                                               \
                  put_bits = size;                                                                \
                  put_buffer = code;                                                              \
               }                                                                                  \
               else                                                                               \
               {                                                                                  \
                  size1 += put_bits;                                                              \
                  code1 <<= 32 - size1;                                                           \
                  code1 |= put_buffer;                                                            \
                  size1 -= 8;                                                                     \
                  while (size1 >= 0)                                                              \
                  {                                                                               \
                     kal_uint8 c = (code1 >> 24) & 0xFF;                                          \
                                                                                                  \
                     JPEG_ENC_SW_EMIT_UINT8(c, dstWritePtr, dstBufferLeft, huffmanDstFile);       \
                                                                                                  \
                     if (0xFF == c)                                                               \
                     {                                                                            \
                        JPEG_ENC_SW_EMIT_UINT8(0, dstWritePtr, dstBufferLeft, huffmanDstFile);    \
                     }                                                                            \
                     code1 <<= 8;                                                                 \
                     size1 -= 8;                                                                  \
                  }                                                                               \
                  put_bits = size1 + 8;                                                           \
                  put_buffer = code1;                                                             \
                                                                                                  \
                  size2 += put_bits;                                                              \
                  code2 <<= 32 - size2;                                                           \
                  code2 |= put_buffer;                                                            \
                  size2 -= 8;                                                                     \
                  while (size2 >= 0)                                                              \
                  {                                                                               \
                     kal_uint8 c = (code2 >> 24) & 0xFF;                                          \
                                                                                                  \
                     JPEG_ENC_SW_EMIT_UINT8(c, dstWritePtr, dstBufferLeft, huffmanDstFile);       \
                                                                                                  \
                     if (0xFF == c)                                                               \
                     {                                                                            \
                        JPEG_ENC_SW_EMIT_UINT8(0, dstWritePtr, dstBufferLeft, huffmanDstFile);    \
                     }                                                                            \
                     code2 <<= 8;                                                                 \
                     size2 -= 8;                                                                  \
                  }                                                                               \
                  put_bits = size2 + 8;                                                           \
                  put_buffer = code2;                                                             \
               }                                                                                  \
            }                                                                                     \
         }                                                                                        \
      }                                                                                           \
                                                                                                  \
      if (lastZeroCoeffNum > 0)                                                                   \
      {                                                                                           \
         kal_uint32 code = ac_huffman_code_tbl[0];                                                \
         kal_int32 size = ac_huffman_size_tbl[0];                                                 \
                                                                                                  \
         size += put_bits;                                                                        \
         code <<= 32 - size;                                                                      \
         code |= put_buffer;                                                                      \
         while (size >= 8)                                                                        \
         {                                                                                        \
            kal_uint8 c = (code >> 24) & 0xFF;                                                    \
                                                                                                  \
            JPEG_ENC_SW_EMIT_UINT8(c, dstWritePtr, dstBufferLeft, huffmanDstFile);                \
                                                                                                  \
            if (0xFF == c)                                                                        \
            {                                                                                     \
               code &= 0x00FFFFFF;                                                                \
            }                                                                                     \
            else                                                                                  \
            {                                                                                     \
               code <<= 8;                                                                        \
               size -= 8;                                                                         \
            }                                                                                     \
         }                                                                                        \
         put_bits = size;                                                                         \
         put_buffer = code;                                                                       \
      }                                                                                           \
   }                                                                                              \
                                                                                                  \
   huffmanEncoder->unfinishEncodedBits = put_buffer;                                              \
   huffmanEncoder->unfinishEncodedSize = put_bits;                                                \
                                                                                                  \
   huffmanDstFile->dstWritePtr = dstWritePtr;                                                     \
   huffmanDstFile->dstBufferLeft = dstBufferLeft;                                                 \
                                                                                                  \
   if(dstBufferLeft < 0)                                                                          \
      status = -1;                                                                                \
                                                                                                  \
   status = 0;                                                                                    \
}while(0)

kal_int32 swjeHuffEncSetHuffSrcBufferLength(SWJE_HUFFMAN_ENCODER *huffmanEncoder, kal_uint32 srcLength);

#endif

