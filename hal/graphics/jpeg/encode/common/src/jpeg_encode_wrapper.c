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
 *   jpeg_encode_wrapper.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Wrapper for JPEG.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"

#include "drv_features_jpeg.h"
#include "jpeg_enum.h"
#include "jpeg_encode_api.h"
#include "jpeg_misc_api.h"
#include "jpeg_encode_wrapper.h"

#if defined(JPEG_CODEC_STANDALONE)
   #include <assert.h>
   #if !defined(ASSERT)
      #define ASSERT assert
   #endif
#else
   #include "kal_public_api.h"
#endif



JPEG_STATUS_ENUM jpeg_wrapper_open(JPEG_ENCODER_HANDLE *jpegWrapperHandle, JPEG_CODEC_TYPE_ENUM codecType)
{
   return jpegEncGetEncoder(codecType, jpegWrapperHandle);
}



JPEG_STATUS_ENUM jpeg_wrapper_start(JPEG_ENCODER_HANDLE jpegWrapperHandle, JPEG_WRAPPER *wrapperPtr)
{
   JPEG_STATUS_ENUM status = JPEG_STATUS_OK;
   kal_uint32 intMemSizeBest, extMemSizeBest;
   kal_uint32 intMemSizeMinimum, extMemSizeMinimum, extMemSizeOffset;
   kal_uint32 dstBufferSize, dstBufferSizeOffset;
   kal_uint8 *extMemoryAddr, *extMemoryTmpAddr;
   kal_uint8 *dstBufferAddr, *dstBufferTmpAddr;


   /// src mode
   status = jpegEncSetSrcMode(jpegWrapperHandle, wrapperPtr->srcMode);
   if (JPEG_STATUS_OK != status)
      return status;

   if (JPEG_ENCODE_SOURCE_YUV_BUFFER == (wrapperPtr->srcMode))
   {
      status = jpegEncSetSrcYUVFormat(jpegWrapperHandle, wrapperPtr->srcSamplingFormat);
      if (JPEG_STATUS_OK != status)
         return status;

      status = jpegEncSetYUVBuffer(jpegWrapperHandle,
                                   wrapperPtr->srcYUVBuffer[0], wrapperPtr->srcYUVBuffer[1], wrapperPtr->srcYUVBuffer[2],
                                   wrapperPtr->srcBufferSize[0], wrapperPtr->srcBufferSize[1], wrapperPtr->srcBufferSize[2]);
      if (JPEG_STATUS_OK != status)
         return status;
   }
   else if (JPEG_ENCODE_SOURCE_RGB_BUFFER == (wrapperPtr->srcMode))
   {
      status = jpegEncSetSrcRGBFormat(jpegWrapperHandle, wrapperPtr->srcRGBFormat);
      if (JPEG_STATUS_OK != status)
         return status;

      status = jpegEncSetRGBBuffer(jpegWrapperHandle, wrapperPtr->srcRGBBuffer, wrapperPtr->srcBufferSize[0]);
      if (JPEG_STATUS_OK != status)
         return status;
   }

   // maybe there is no source window
   if ((0 != wrapperPtr->srcWindow.w * wrapperPtr->srcWindow.h)
      && ((wrapperPtr->srcWidth != wrapperPtr->srcWindow.w) || (wrapperPtr->srcHeight != wrapperPtr->srcWindow.h))
      )
   {
      status = jpegEncSetSrcWindow(jpegWrapperHandle, &(wrapperPtr->srcWindow));
      if (JPEG_STATUS_OK != status)
         return status;
   }

   status = jpegEncSetSrcDimension(jpegWrapperHandle, wrapperPtr->srcWidth, wrapperPtr->srcHeight);
   if (JPEG_STATUS_OK != status)
      return status;

   status = jpegEncSetDstDimension(jpegWrapperHandle, wrapperPtr->dstWidth, wrapperPtr->dstHeight);
   if (JPEG_STATUS_OK != status)
      return status;

#if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
   dstBufferAddr = (kal_uint8*)(((kal_uint32)wrapperPtr->dstBufferAddr + 31) & (~31));
   dstBufferSize = (kal_uint32)dstBufferAddr - (kal_uint32)wrapperPtr->dstBufferAddr;
   dstBufferSize = (wrapperPtr->dstBufferSize - dstBufferSize) & (~31);
#else
   dstBufferAddr = (kal_uint8*)wrapperPtr->dstBufferAddr;
   dstBufferSize = wrapperPtr->dstBufferSize;
#endif

   status = jpegEncSetDstBuffer(jpegWrapperHandle, dstBufferAddr, dstBufferSize);
   if (JPEG_STATUS_OK != status)
      return status;

   status = jpegEncSetDirectFileOutputHandle(jpegWrapperHandle, wrapperPtr->pDstFileHandle);
   if (JPEG_STATUS_OK != status)
      return status;

   status = jpegEncSetDstFileFormat(jpegWrapperHandle, wrapperPtr->dstFileFormat);
      if (JPEG_STATUS_OK != status)
         return status;

   status = jpegEncSetDstQuality(jpegWrapperHandle, wrapperPtr->dstQuality);
   if (JPEG_STATUS_OK != status)
      return status;

   status = jpegEncSetDstSampleFormat(jpegWrapperHandle, wrapperPtr->dstSamplingFormat);
   if (JPEG_STATUS_OK != status)
      return status;

   status = jpegEncSetDstThumbnail(jpegWrapperHandle, wrapperPtr->enableThumbnail, wrapperPtr->thumbnailWidth, wrapperPtr->thumbnailHeight);
   if (JPEG_STATUS_OK != status)
      return status;
   
   status = jpegEncSetRotation(jpegWrapperHandle, wrapperPtr->rotation);
   if (JPEG_STATUS_OK != status)
      return status;

   /// Camera will always give enough working buffer
   /// jpeg_status = jpegEncQueryWorkingMemory(jpegWrapperHandle, &intMemSize, &extMemSize);
   status = jpegEncQueryWorkingMemory(jpegWrapperHandle, &intMemSizeBest, &intMemSizeMinimum, &extMemSizeBest, &extMemSizeMinimum);
   if (JPEG_STATUS_OK != status)
      return status;

   extMemoryAddr = (kal_uint8*)wrapperPtr->extMemoryAddr;
   extMemSizeMinimum = wrapperPtr->extMemorySize;
#if (defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__))
   if (extMemSizeMinimum <= wrapperPtr->extMemorySize)
   {
      extMemoryTmpAddr = (kal_uint8*)(((kal_uint32)wrapperPtr->extMemoryAddr + 31) & (~31));
      extMemSizeOffset = (kal_uint32)extMemoryTmpAddr - (kal_uint32)wrapperPtr->extMemoryAddr;
   
      extMemSizeOffset = (wrapperPtr->extMemorySize - extMemSizeOffset) & (~31);
      if (extMemSizeMinimum <= extMemSizeOffset)
      {
         extMemoryAddr = extMemoryTmpAddr;
         extMemSizeMinimum = extMemSizeOffset;
      }
   }
   else if (extMemSizeMinimum > wrapperPtr->extMemorySize)
   {
      ASSERT(0);
   }
#endif

   status = jpegEncSetWorkingMemory(jpegWrapperHandle,
                                    wrapperPtr->intMemoryAddr, wrapperPtr->intMemorySize,
                                    (kal_uint32*)extMemoryAddr, extMemSizeMinimum);
   if (JPEG_STATUS_OK != status)
      return status;

   status = jpegEncSetCallbackFunction(jpegWrapperHandle, wrapperPtr->callback_function);
   if (JPEG_STATUS_OK != status)
      return status;

   status = jpegEncStart(jpegWrapperHandle);
   return status;
}



JPEG_STATUS_ENUM jpeg_wrapper_close(JPEG_ENCODER_HANDLE jpegWrapperHandle)
{
   return jpegEncReleaseEncoder(jpegWrapperHandle);
}



JPEG_STATUS_ENUM jpeg_wrapper_get_encoder_state(JPEG_ENCODER_HANDLE jpegWrapperHandle, JPEG_CODEC_STATE_ENUM *jpegState)
{
   return jpegEncGetEncoderState(jpegWrapperHandle, jpegState);;
}



JPEG_STATUS_ENUM jpeg_wrapper_get_encoded_data(JPEG_ENCODER_HANDLE jpegWrapperHandle, kal_uint8 **encodeBufferAddr, kal_uint32 *encodeBufferSize)
{
   JPEG_STATUS_ENUM status = JPEG_STATUS_OK;
   JPEG_CODEC_STATE_ENUM jpegState;

   status = jpegEncGetEncoderState(jpegWrapperHandle, &jpegState);
   if (JPEG_STATUS_OK != status)
      return status;

   *encodeBufferAddr = NULL;
   *encodeBufferSize = 0;
   switch(jpegState)
   {
      case JPEG_CODEC_STATE_COMPLETE:
         status = jpegEncGetEncodedData(jpegWrapperHandle, encodeBufferAddr, encodeBufferSize); 
      break;   
      case JPEG_CODEC_STATE_ERROR:
         status = jpegEncGetLastError(jpegWrapperHandle);
      break;   
      case JPEG_CODEC_STATE_BUSY:
         status = JPEG_STATUS_ENC_BUSY; 
      break;   
      default:
         ASSERT(0);   
   }
   return status;

}



JPEG_STATUS_ENUM jpeg_wrapper_query_dst_buffer_size(kal_uint32 *bufferSize,
                                                    JPEG_ENCODE_QUALITTY_ENUM quality,
                                                    JPEG_YUV_FORMAT_ENUM dstFormat, kal_uint32 dstWidth, kal_uint32 dstHeight)
{
   #if defined(EXIF_SUPPORT)
      return jpegEncQueryDstBufferSize(bufferSize, JPEG_ENCODE_EVALUATION_MODE_AVERAGE, quality, dstFormat, dstWidth, dstHeight, KAL_TRUE);
   #else
      return jpegEncQueryDstBufferSize(bufferSize, JPEG_ENCODE_EVALUATION_MODE_AVERAGE, quality, dstFormat, dstWidth, dstHeight, KAL_FALSE);
   #endif
}

