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
 *   jpeg_parse_int.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Structure definition of JPEG parser.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "jpeg_parse_int.h"
#include "exif_dec_parser.h"

static JPEG_STATUS_ENUM _parse_marker_segment_SOFi(JPEG_FILE_INFO *pParser,
                                                   kal_uint32     curMarker,
                                                   kal_uint32     markerLength,
                                                   STFSAL         *pSource)
{
   JPEG_FRAME_INFO            *pFrameInfo;
   JPEG_FRAME_COMPONENT_INFO  *pCompInfo;
   kal_int32                  compCount;
   kal_uint8                  tempValue;
   kal_int32                  compIndex;
   kal_int32                  HSampling[3];
   kal_int32                  VSampling[3];
   kal_int32                  maxFactor;

   pFrameInfo = &(pParser->frameInfo);

   pFrameInfo->frameHeaderType   = curMarker;
   pFrameInfo->frameHeaderLength = markerLength;

   switch (pFrameInfo->frameHeaderType)
   {
   case JPEG_MARKER_SOF(0):
      pFrameInfo->encProcess = JPEG_ENCODE_PROCESS_BASELINE;
      break;
   case JPEG_MARKER_SOF(2):
      pFrameInfo->encProcess = JPEG_ENCODE_PROCESS_PROGRESSIVE;
      break;
   default:
      // Unsupported frame format
      pFrameInfo->encProcess  = JPEG_ENCODE_PROCESS_UNSUPPORTED;

      // Record error status
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
      return pParser->parseStatus;
   }

   // Set the SOF ready flag for further checking
   pParser->mandatoryMarkerCheck |= JPEG_MANDATORY_MARKER_SOF_BIT;

   /// Read the sample precision: P.
   if (FSAL_OK != FSAL_Read_Bytes(pSource, (void*)&(pFrameInfo->samplePrecision), 1))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
      return pParser->parseStatus;
   }

   /// Read the image height: Y.
   if (FSAL_OK != FSAL_Read_UINT16(pSource, &(pFrameInfo->height)))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
      return pParser->parseStatus;
   }

   /// Read the image width: X.
   if (FSAL_OK != FSAL_Read_UINT16(pSource, &(pFrameInfo->width)))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
      return pParser->parseStatus;
   }

   /// Read the number of image component in frame: Nf.
   if (FSAL_OK != FSAL_Read_Bytes(pSource, (void*)&(pFrameInfo->numberOfComponents), 1))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
      return pParser->parseStatus;
   }

   // Check if the frame related info is error
   if ((pFrameInfo->width  <= 0) ||
       (pFrameInfo->height <= 0) ||
       (pFrameInfo->numberOfComponents <= 0))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
      return pParser->parseStatus;
   }

   markerLength -= 6;
   if (markerLength != (pFrameInfo->numberOfComponents * 3))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
      return pParser->parseStatus;
   }

   /// Read the component information.
   compCount  = pFrameInfo->numberOfComponents;
   if ((1 != compCount) && (3 != compCount))
   {
      /// We only handle JPEG image with one or three color components.
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
      return pParser->parseStatus;
   }

   /// For each component...
   compIndex = 0;
   pCompInfo = pFrameInfo->frameComponentInfo;
   while (--compCount >= 0)
   {
      /// Read the component identifier: Ci.
      if (FSAL_OK != FSAL_Read_Bytes(pSource, (void*)&(pCompInfo->componentID), 1))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }

      /// Read the sampling factor: Hi & Vi.
      if (FSAL_OK != FSAL_Read_Bytes(pSource, (void*)&tempValue, 1))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }

      pCompInfo->hSamplingFactor = ((tempValue >> 4) & 0x0F);
      pCompInfo->vSamplingFactor = (tempValue & 0x0F);

      if ((0 == pCompInfo->hSamplingFactor) || (0 == pCompInfo->vSamplingFactor))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
         return pParser->parseStatus;
      }

      /// Read the quantization table destination selector: Tqi.
      if (FSAL_OK != FSAL_Read_Bytes(pSource, (void*)&(pCompInfo->qTableSelector), 1))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }

      HSampling[compIndex] = pCompInfo->hSamplingFactor;
      VSampling[compIndex] = pCompInfo->vSamplingFactor;
      compIndex++;

      pCompInfo++;
   }

   switch (pFrameInfo->numberOfComponents)
   {
   case 1:
      pFrameInfo->duPerMCU    = 1;
      pFrameInfo->samplingFormat = JPEG_YUV_FORMAT_GRAYLEVEL;

      /// Some gray image will set the sampling factor as 2:2 or 4:4,
      /// which will make the calculation of mcuRow error.
      /// Thus we force the sampling factor of gray level image as 1:1.
      pFrameInfo->frameComponentInfo[0].hSamplingFactor = 1;
      pFrameInfo->frameComponentInfo[0].vSamplingFactor = 1;
      pFrameInfo->hSamplingFactorMax = 1;
      pFrameInfo->vSamplingFactorMax = 1;
      break;
   case 3:
      {

         /// Check for the component ID
         if ((0x52 == pFrameInfo->frameComponentInfo[0].componentID) &&
             (0x47 == pFrameInfo->frameComponentInfo[1].componentID) &&
             (0x42 == pFrameInfo->frameComponentInfo[2].componentID))
         {
            /// 0x52 -> 'R', 0x47 -> 'G', 0x42 -> 'B'
            /// This file is RGB compressed, we do not support it!
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
            return pParser->parseStatus;
         }

         /// Using the sum of Hy & Vy as the color format index.
         /// "00" : YUV 4:4:4 (Hy=1, Vy=1), (sum=2) - 2 = 0
         /// "01" : YUV 4:2:2 (Hy=2, Vy=1), (sum=3) - 2 = 1
         /// "10" : YUV 4:2:0 (Hy=2, Vy=2), (sum=4) - 2 = 2
         /// "11" : YUV 4:1:1 (Hy=4, Vy=1), (sum=5) - 2 = 3

         pFrameInfo->duPerMCU = HSampling[0] * VSampling[0] +
                                HSampling[1] * VSampling[1] +
                                HSampling[2] * VSampling[2];
 
         if (10 < pFrameInfo->duPerMCU)
         {
            pFrameInfo->samplingFormat = JPEG_YUV_FORMAT_UNSUPPORTED;
            pFrameInfo->hSamplingFactorMax = 1;
            pFrameInfo->vSamplingFactorMax = 1;

            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
            return pParser->parseStatus;
         }

         if (1 != (VSampling[1] * VSampling[2] * HSampling[1] * HSampling[2]))
         {
            maxFactor = HSampling[0];
            if (maxFactor < HSampling[1])
            {
               maxFactor = HSampling[1];
            }
            if (maxFactor < HSampling[2])
            {
               maxFactor = HSampling[2];
            }
            pFrameInfo->hSamplingFactorMax = maxFactor;

            maxFactor = VSampling[0];
            if (maxFactor < VSampling[1])
            {
               maxFactor = VSampling[1];
            }
            if (maxFactor < VSampling[2])
            {
               maxFactor = VSampling[2];
            }
            pFrameInfo->vSamplingFactorMax = maxFactor;

            pFrameInfo->samplingFormat = JPEG_YUV_FORMAT_NON_STANDARD;
         }
         else
         {
            pFrameInfo->hSamplingFactorMax = HSampling[0];
            pFrameInfo->vSamplingFactorMax = VSampling[0];

            switch (HSampling[0] + VSampling[0] - 2)
            {
            case 0:
               pFrameInfo->samplingFormat = JPEG_YUV_FORMAT_YUV444;
               break;
            case 1:
               pFrameInfo->samplingFormat = JPEG_YUV_FORMAT_YUV422;
               break;
            case 2:
               pFrameInfo->samplingFormat = JPEG_YUV_FORMAT_YUV420;
               break;
            case 3:
               pFrameInfo->samplingFormat = JPEG_YUV_FORMAT_YUV411;
               break;
            default:   
               pFrameInfo->samplingFormat = JPEG_YUV_FORMAT_UNSUPPORTED;
               pFrameInfo->hSamplingFactorMax = 1;
               pFrameInfo->vSamplingFactorMax = 1;

               pParser->parseState  = JPEG_PARSE_STATE_ERROR;
               pParser->parseStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
            }
         }
      }
      break;
   default:
      pFrameInfo->samplingFormat = JPEG_YUV_FORMAT_UNSUPPORTED;

      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
      break;
   }

   return pParser->parseStatus;
}


static JPEG_STATUS_ENUM _parse_marker_segment_dqt(JPEG_FILE_INFO  *pParser,
                                                  kal_uint32      curMarker,
                                                  kal_uint32      markerLength,
                                                  STFSAL          *pSource)
{
   // Set DQT ready for further checking
   pParser->mandatoryMarkerCheck |= JPEG_MANDATORY_MARKER_DQT_BIT;

   if (FSAL_OK != FSAL_Skip_Bytes(pSource, markerLength))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
   }

   return pParser->parseStatus;
}


static JPEG_STATUS_ENUM _parse_marker_segment_dht(JPEG_FILE_INFO  *pParser,
                                                  kal_uint32      curMarker,
                                                  kal_uint32      markerLength,
                                                  STFSAL          *pSource)
{
   // For MJPEG video clips, we may not have DHT table.
   //pParser->mandatoryMarkerCheck |= JPEG_MANDATORY_MARKER_DHT_BIT;

   if (FSAL_OK != FSAL_Skip_Bytes(pSource, markerLength))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
   }

   return pParser->parseStatus;
}


static JPEG_STATUS_ENUM _my_skip_data(JPEG_FILE_INFO  *pParser,
                                      STFSAL          *pSource,
                                      kal_uint32      length)
{
   if (FSAL_OK != FSAL_Skip_Bytes(pSource, length))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
      return pParser->parseStatus;
   }
   else
   {
      pParser->segmentConsumed += length;
      return JPEG_STATUS_OK;
   }
}


/// This is the parser for APP0 marker segment
static JPEG_STATUS_ENUM _parse_marker_segment_app0(JPEG_FILE_INFO *pParser,
                                                   kal_uint32     curMarker,
                                                   kal_uint32     markerLength,
                                                   STFSAL         *pSource)
{
   JPEG_THUMBNAIL_INFO  *pThumbnailInfo;
   kal_uint8            identifier[5];
   kal_uint8            extensionCode;

   pThumbnailInfo = &(pParser->thumbnailInfo);

   pThumbnailInfo->tn_width  = 0;
   pThumbnailInfo->tn_height = 0;
   
   if (FSAL_OK != FSAL_Read_Bytes(pSource, identifier, 5))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
      return pParser->parseStatus;
   }

   pParser->segmentConsumed += 5;

   if (0 == strcmp((void *)identifier, "JFIF\0"))
   {
      /// Parse JFIF format.
      if (JPEG_STATUS_OK != _my_skip_data(pParser, pSource, 7))
      {
         return pParser->parseStatus;
      }

      /// Read the thumbnail width.
      if (FSAL_OK != FSAL_Read_Bytes(pSource, (kal_uint8*)&(pThumbnailInfo->tn_width), 1))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }
      pParser->segmentConsumed += 1;

      /// Read the thumbnail height.
      if (FSAL_OK != FSAL_Read_Bytes(pSource, (kal_uint8*)&(pThumbnailInfo->tn_height), 1))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }
      pParser->segmentConsumed += 1;

      if (FSAL_OK != FSAL_GetCurPos(pSource, &(pThumbnailInfo->tn_offset)))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }

      /// The thumbnail in JFIF file must be in uncompressed format.
      pThumbnailInfo->tn_data_length = 3 * pThumbnailInfo->tn_width * pThumbnailInfo->tn_height;

      if (pThumbnailInfo->tn_data_length)
      {
         pThumbnailInfo->tn_type = JPEG_THUMBNAIL_TYPE_3BPP;
      }
      else
      {
         pThumbnailInfo->tn_type = JPEG_THUMBNAIL_TYPE_NONE;
      }

      if (JPEG_STATUS_OK != _my_skip_data(pParser, pSource, pParser->segmentLength - pParser->segmentConsumed))
      {
         return pParser->parseStatus;
      }
   }
   else if (0 == strcmp((void *)identifier, "JFXX\0"))
   {
      /// Parse JFXX format.

      /// Read the extension code.
      if (FSAL_OK != FSAL_Read_Bytes(pSource, &extensionCode, 1))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }
      pParser->segmentConsumed += 1;

      switch (extensionCode)
      {
      case 0x10:  /// JPEG compressed thumbnail image.
         if (FSAL_OK != FSAL_GetCurPos(pSource, &(pThumbnailInfo->tn_offset)))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }
         pThumbnailInfo->tn_type = JPEG_THUMBNAIL_TYPE_JPEG;
         pThumbnailInfo->tn_data_length = pParser->segmentLength - pParser->segmentConsumed;

         if (JPEG_STATUS_OK != _my_skip_data(pParser, pSource, pParser->segmentLength - pParser->segmentConsumed))
         {
            return pParser->parseStatus;
         }
         break;
      case 0x13:  /// Uncompressed thumbnail.
         /// Read the thumbnail width.
         if (FSAL_OK != FSAL_Read_Bytes(pSource, (kal_uint8 *)&(pThumbnailInfo->tn_width), 1))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }
         pParser->segmentConsumed += 1;

         /// Read the thumbnail height.
         if (FSAL_OK != FSAL_Read_Bytes(pSource, (kal_uint8 *)&(pThumbnailInfo->tn_height), 1))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }
         pParser->segmentConsumed += 1;

         if (FSAL_OK != FSAL_GetCurPos(pSource, &(pThumbnailInfo->tn_offset)))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }

         pThumbnailInfo->tn_data_length = 3 * pThumbnailInfo->tn_width * pThumbnailInfo->tn_height;

         if (pThumbnailInfo->tn_data_length)
         {
            pThumbnailInfo->tn_type = JPEG_THUMBNAIL_TYPE_3BPP;
         }
         else
         {
            pThumbnailInfo->tn_type = JPEG_THUMBNAIL_TYPE_NONE;
         }

         if (JPEG_STATUS_OK != _my_skip_data(pParser, pSource, pParser->segmentLength - pParser->segmentConsumed))
         {
            return pParser->parseStatus;
         }
         break;

      default:
         if (JPEG_STATUS_OK != _my_skip_data(pParser, pSource, pParser->segmentLength - pParser->segmentConsumed))
         {
            return pParser->parseStatus;
         }
         break;
      }
   }
   else
   {
      if (!_my_skip_data(pParser, pSource, pParser->segmentLength - pParser->segmentConsumed))
      {
         return pParser->parseStatus;
      }
   }

   return JPEG_STATUS_OK;
}


static JPEG_STATUS_ENUM _parse_marker_segment_app9(JPEG_FILE_INFO *pParser,
                                                   kal_uint32      curMarker,
                                                   kal_uint32      markerLength,
                                                   STFSAL          *pSource)
{
   JPEG_THUMBNAIL_INFO  *qviInfo;
   kal_uint8            identifier[5];
   
   qviInfo = &(pParser->qviInfo);

   if (FSAL_OK != FSAL_Read_Bytes(pSource, identifier, 4))
   {
      pParser->parseState  = JPEG_PARSE_STATE_ERROR;
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
      return pParser->parseStatus;
   }

   pParser->segmentConsumed += 4;

   if (0 == strcmp((void *)identifier, "MTK\0"))
   {
      if (FSAL_OK != FSAL_Read_Bytes(pSource, identifier, 4))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }

      pParser->segmentConsumed += 4;

      if (0 == strcmp((void *)identifier, "QVI\0"))
      {
         if (FSAL_OK != FSAL_Read_Bytes(pSource, identifier, 2))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }
         
         qviInfo->tn_width = ((kal_uint32)identifier[0] << 8) | identifier[1];
         pParser->segmentConsumed += 2;

         if (FSAL_OK != FSAL_Read_Bytes(pSource, identifier, 2))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }

         qviInfo->tn_height = ((kal_uint32)identifier[0] << 8) | identifier[1];
         pParser->segmentConsumed += 2;

         if (FSAL_OK != FSAL_Read_Bytes(pSource, identifier, 4))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }
         
         qviInfo->tn_offset = ((kal_uint32)identifier[0] << 24) | ((kal_uint32)identifier[1] << 16) | ((kal_uint32)identifier[2] << 8) | identifier[3];
         pParser->segmentConsumed += 4;

         if (FSAL_OK != FSAL_Read_Bytes(pSource, identifier, 4))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }

         qviInfo->tn_data_length = ((kal_uint32)identifier[0] << 24) | ((kal_uint32)identifier[1] << 16) | ((kal_uint32)identifier[2] << 8) | identifier[3];
         pParser->segmentConsumed += 4;

         qviInfo->tn_type = JPEG_THUMBNAIL_TYPE_JPEG;
      }
   }

   return JPEG_STATUS_OK;    
}


static JPEG_STATUS_ENUM _parse_cur_marker_segment(JPEG_FILE_INFO *pParser,
                                                  kal_int32       curMarker,
                                                  kal_uint32      markerLength,
                                                  STFSAL          *pSource)
{
   kal_uint32                 position;
   kal_int8                  compCount;
   kal_uint8                  identifier;
   kal_int32                  compIndex;
   JPEG_FRAME_COMPONENT_INFO  *pCompInfo;
   JPEG_THUMBNAIL_INFO        *pThumbnail;
   kal_int32                  app1Result;
   kal_uint32                 compression;

   switch (curMarker)
   {
   case JPEG_MARKER_SOF0:
   case JPEG_MARKER_SOF2:
   case JPEG_MARKER_SOF1:
   case JPEG_MARKER_SOF3:
   case JPEG_MARKER_SOF5:
   case JPEG_MARKER_SOF6:
   case JPEG_MARKER_SOF7:
   case JPEG_MARKER_SOF9:
   case JPEG_MARKER_SOF10:
   case JPEG_MARKER_SOF11:
   case JPEG_MARKER_SOF13:
   case JPEG_MARKER_SOF14:
   case JPEG_MARKER_SOF15:
      return _parse_marker_segment_SOFi(pParser,
                                        curMarker,
                                        markerLength,
                                        pSource);
   case JPEG_MARKER_SOS:
      /// If the SOS is encountered, the parse process completes.
      if (FSAL_OK != FSAL_Read_Bytes(pSource, (kal_uint8*)&compCount, 1))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
      }
      else
      {
         markerLength -= 1;

         if ((((kal_uint8)compCount) != pParser->frameInfo.numberOfComponents) ||
             (markerLength != (compCount * 2 + 3)))
         {
            pParser->parseState = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
         }
         else
         {
            pCompInfo = pParser->frameInfo.frameComponentInfo;
            while (--compCount >= 0)
            {
               FSAL_Read_Bytes(pSource, &identifier, 1);
              
               for (compIndex = (pParser->frameInfo.numberOfComponents - 1); compIndex >= 0; compIndex--)
               {
                  if (identifier == pCompInfo[compIndex].componentID)
                  {
                     break;
                  }
               }

               if (compIndex < 0)
               {
                  pParser->parseState  = JPEG_PARSE_STATE_ERROR;
                  pParser->parseStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
                  return pParser->parseStatus;
               }

               // Skip Huffman table selection byte
               FSAL_Skip_Bytes(pSource, 1);
            }

            // Skip spectral strat, end and precision bytes
            FSAL_Skip_Bytes(pSource, 3);

            /// Record the position of the first ECS.
            if (FSAL_OK != FSAL_GetCurPos(pSource, &(pParser->offsetECS0)))
            {
               pParser->parseState  = JPEG_PARSE_STATE_ERROR;
               pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            }
            else
            {
               pParser->parseState  = JPEG_PARSE_STATE_COMPLETE;
            }
         }
      }
      break;
   case JPEG_MARKER_EOI:
      pParser->parseState = JPEG_PARSE_STATE_COMPLETE;
      break;
   case JPEG_MARKER_DRI:
   case JPEG_MARKER_DQT:
   case JPEG_MARKER_DHT:
      if (0 == pParser->offsetTableMisc)
      {
         /// Record the position where the first decoding table appears.
         if (FSAL_OK != FSAL_GetCurPos(pSource, &position))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus; 
         }
         else
         {
            pParser->offsetTableMisc = position - 4;
         }
      }

      switch (curMarker)
      {
         case JPEG_MARKER_DQT:
            return _parse_marker_segment_dqt(pParser,
                                             curMarker,
                                             markerLength,
                                             pSource);
         case JPEG_MARKER_DHT:
            return _parse_marker_segment_dht(pParser,
                                             curMarker,
                                             markerLength,
                                             pSource);
      }
      break;
   case JPEG_MARKER_APP(0):
   case JPEG_MARKER_APP(1):
   case JPEG_MARKER_APP(2):
   case JPEG_MARKER_APP(9):
   {
      if (FSAL_OK != FSAL_GetCurPos(pSource, &position))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }

      // Avoid parsing APP related markers for GDI scenario
      switch (curMarker)
      {
      case JPEG_MARKER_APP(0):
         // Get the thumbnail structure of the image
         pThumbnail = &(pParser->thumbnailInfo);
      
         if ((JPEG_THUMBNAIL_TYPE_NONE == pThumbnail->tn_type) && (0 == pParser->offsetAPPn[0]))
         {
            pParser->offsetAPPn[0] = position - 4;

            /// Retrieve the thumbnail information.
            if (JPEG_STATUS_OK != _parse_marker_segment_app0(pParser,
                                                             curMarker,
                                                             markerLength,
                                                             pSource))
            {
               pParser->parseState  = JPEG_PARSE_STATE_ERROR;
               pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
               return pParser->parseStatus;
            }
         }
         else
         {
            /// Skip this APP0 marker segment since the thumbnail information already exists.
            _my_skip_data(pParser, pSource, markerLength);
         }
         break;
      case JPEG_MARKER_APP(1):
         if ((pParser->app1Info == NULL) || (0 != pParser->offsetAPPn[1]))
         {
            /// No app1Info available or the APP1 is already parsed.
            if (0 == pParser->offsetAPPn[1])
            {
               pParser->offsetAPPn[1] = position - 4;
            }
            _my_skip_data(pParser, pSource, markerLength);
         }
         else
         {
            /// Parse APP1 for the first time.
            pParser->offsetAPPn[1] = position - 4;

            app1ParserInit(pParser->app1Info, pSource, pParser->offsetAPPn[1]);

            app1Result = app1ParserStart(pParser->app1Info);

            if (0 == app1Result)
            {
               pParser->parseState  = JPEG_PARSE_STATE_ERROR;
               pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
               return JPEG_STATUS_OK;
            }
            else if (-1 == app1Result)
            {
               pParser->offsetAPPn[1] = 0;
            }
            else
            {
               pThumbnail = &(pParser->thumbnailInfo);

               /// Check the thumbnail information.
               if (JPEG_THUMBNAIL_TYPE_NONE == pThumbnail->tn_type)
               {
                  pThumbnail->tn_data_length = app1ParserQueryThumbnailInfo(pParser->app1Info,
                                                                            &(pThumbnail->tn_width),
                                                                            &(pThumbnail->tn_height),
                                                                            &compression,
                                                                            &(pThumbnail->tn_offset));
                  if (0 == pThumbnail->tn_data_length)
                  {
                     pThumbnail->tn_type = JPEG_THUMBNAIL_TYPE_NONE;
                  }
                  else
                  {
                     switch (compression)
                     {
                     case 1:
                        pThumbnail->tn_type = JPEG_THUMBNAIL_TYPE_3BPP;
                        break;
                     case 6:
                        pThumbnail->tn_type = JPEG_THUMBNAIL_TYPE_JPEG;
                        break;
                     default:
                        pThumbnail->tn_type = JPEG_THUMBNAIL_TYPE_NONE;
                        break;
                     }
                  }
               }
            }
         }
         break;
      case JPEG_MARKER_APP(2):
         if (0 == pParser->offsetAPPn[2])
         {
            pParser->offsetAPPn[2] = position - 4;
         }
         /// Skip this APP2 marker segment since the thumbnail information already exists.
         _my_skip_data(pParser, pSource, markerLength);
         break;
      case JPEG_MARKER_APP(9):
         if ((JPEG_THUMBNAIL_TYPE_NONE == pParser->qviInfo.tn_type) && (0 == pParser->offsetAPPn[8]))
         {
            pParser->offsetAPPn[8] = position - 4;

            /// Retrieve the app9 information.
            if (JPEG_STATUS_OK != _parse_marker_segment_app9(pParser,
                                                             curMarker,
                                                             markerLength,
                                                             pSource))
            {
               pParser->parseState  = JPEG_PARSE_STATE_ERROR;
               pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
               return pParser->parseStatus;
            }
         }
         else
         {
            /// Skip this APP9 marker segment since information already exists.
            _my_skip_data(pParser, pSource, markerLength);
         }
         break;

      }
   } break;

   default:
      /// For unsupported marker segment, just skip them.
      if (FSAL_OK != FSAL_Skip_Bytes(pSource, markerLength))
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }
      else
      {
         pParser->segmentConsumed = pParser->segmentLength;
      }
      break;
   }

   return JPEG_STATUS_OK;
}


JPEG_STATUS_ENUM jpeg_parser_parse_reset_internal(JPEG_FILE_INFO  *pParser,
                                                  STFSAL           *pSource,
                                                  kal_uint32       fileSize,
                                                  void             *pAPP1Buffer,
                                                  kal_uint32       bufferSize)
{
   ASSERT(NULL != pParser);
   ASSERT(NULL != pSource);

   if (bufferSize < sizeof(EXIF_APP1_INFO))
   {
      /// The buffer is not large enough, we will skip EXIF processing...
      pAPP1Buffer = NULL;
   }

   memset(pParser, 0, sizeof(JPEG_FILE_INFO));

   pParser->fileHandle = pSource;
   pParser->realSize   = fileSize;
   FSAL_GetCurPos(pSource, &(pParser->realOffset));

   if (NULL != pAPP1Buffer)
   {
      memset(pAPP1Buffer, 0, sizeof(EXIF_APP1_INFO));
   }

   pParser->app1Info  = (EXIF_APP1_INFO*)pAPP1Buffer;

   return JPEG_STATUS_OK;
}


JPEG_STATUS_ENUM jpeg_parser_parse_start_internal(JPEG_FILE_INFO  *pParser,
                                                  kal_bool        forceImmediateSOI)
{
   STFSAL            *pSource;
   kal_uint8         *pMarker;
   JPEG_FRAME_INFO   *pFrameInfo;
   kal_uint32        samplingFactorMax;
   kal_uint32        log2_mcu_width = 3;
   kal_uint32        log2_mcu_height = 3;

   pSource = pParser->fileHandle;
   if (NULL == pSource)
   {
      pParser->parseStatus = JPEG_STATUS_DEC_ERROR_INVALID_FILE;
      return pParser->parseStatus;
   }

   if (JPEG_PARSE_STATE_STOP == pParser->parseState)
   {
      /// The first time the function is called.
      pParser->parseState  = JPEG_PARSE_STATE_WAITING_FOR_SOI;
      pParser->parseStatus = JPEG_STATUS_OK;
   }

   pMarker = &(pParser->segmentMarker[0]);

   /// Look for the SOI marker.
   while (JPEG_PARSE_STATE_WAITING_FOR_SOI == pParser->parseState)
   {
      if (FSAL_OK == FSAL_Peek_Bytes(pSource, (void*)pMarker, 2))
      {
         if ((JPEG_MARKER_START_CODE != pMarker[0]) || (JPEG_MARKER_SOI != pMarker[1]))
         {
            if (0 != forceImmediateSOI)
            {
               pParser->parseState  = JPEG_PARSE_STATE_ERROR;
               pParser->parseStatus = JPEG_STATUS_DEC_ERROR_INVALID_FILE;
               return pParser->parseStatus;
            }

            if (FSAL_OK != FSAL_Skip_Bytes(pSource, 1))
            {
               pParser->parseState = JPEG_PARSE_STATE_ERROR;
               pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
               return pParser->parseStatus;
            }
         }
         else
         {
            /// Found SOI, skip the SOI marker which is already read.
            if (FSAL_OK != FSAL_Skip_Bytes(pSource, 2))
            {
               pParser->parseState  = JPEG_PARSE_STATE_ERROR;
               pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
               return pParser->parseStatus;
            }
            else
            {
               pParser->parseState = JPEG_PARSE_STATE_WAITING_FOR_MARKER;
            }
         }
      }
      else
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
         return pParser->parseStatus;
      }
   }

   /// Main loop to deal with file content.
   while ((pParser->parseState != JPEG_PARSE_STATE_COMPLETE) &&
          (pParser->parseState != JPEG_PARSE_STATE_ERROR))
   {
      pMarker[0] = JPEG_MARKER_START_CODE;
      pMarker[1] = JPEG_MARKER_START_CODE;
      
      // Added JPEG_MARKER_SKIP_CODE for mis-parsing 0xFF00
      while ((JPEG_MARKER_START_CODE != pMarker[0]) ||
             (JPEG_MARKER_START_CODE == pMarker[1]) ||
             (JPEG_MARKER_SKIP_CODE  == pMarker[1]))
      {
         if (FSAL_OK == FSAL_Peek_Bytes(pSource, (void*)pMarker, 2))
         {
            if ((JPEG_MARKER_START_CODE == pMarker[0]) &&
                (JPEG_MARKER_START_CODE != pMarker[1] ||
                 JPEG_MARKER_SKIP_CODE  == pMarker[1]))
            {
               /// A maker is detected, skip two bytes since these two bytes are peeked in advance.
               if (FSAL_OK != FSAL_Skip_Bytes(pSource, 2))
               {
                  pParser->parseState  = JPEG_PARSE_STATE_ERROR;
                  pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
                  return pParser->parseStatus;
               }
            }
            else
            {
               /// No marker is detected, skip one byte.
               if (FSAL_OK != FSAL_Skip_Bytes(pSource, 1))
               {
                  pParser->parseState = JPEG_PARSE_STATE_ERROR;
                  pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
                  return pParser->parseStatus;
               }
            }
         }
         else
         {
            pParser->parseState = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }
      }

      /// Found a marker, try to get the length.
      if ((pMarker[1] != JPEG_MARKER_SOI) &&
          (pMarker[1] != JPEG_MARKER_EOI) &&
          (pMarker[1] != JPEG_MARKER_TEM) && 
          (pMarker[1] >  JPEG_MARKER_RST(7) ||
           pMarker[1] <  JPEG_MARKER_RST(0)))
      {
         /// Read the 2-bytes length.
         if (FSAL_OK != FSAL_Read_UINT16(pSource, &(pParser->segmentLength)))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
            return pParser->parseStatus;
         }
         else
         {
            pParser->segmentConsumed = 2;
         }

         // Boundary check for the correctness of the marker length.
         if ((pParser->segmentLength < 2) || (pParser->segmentLength > 65535))
         {
            pParser->parseState  = JPEG_PARSE_STATE_ERROR;
            pParser->parseStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            return pParser->parseStatus;
         }
      }
      else
      {
         pParser->segmentConsumed = 0;
         pParser->segmentLength    = 0;
         continue;
      }

      if (JPEG_STATUS_OK != _parse_cur_marker_segment(pParser, pMarker[1], pParser->segmentLength - 2, pSource))
      {
         break;
      }
   }

   /// Check for the existence of mandatory markers.
   if (JPEG_PARSE_STATE_COMPLETE == pParser->parseState)
   {
      if (JPEG_MANDATORY_MARKER_CHECK != pParser->mandatoryMarkerCheck)
      {
         pParser->parseState  = JPEG_PARSE_STATE_ERROR;
         pParser->parseStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
         return pParser->parseStatus;
      }
   
      pFrameInfo = &(pParser->frameInfo);

      /// Utilize paddedWidth and paddedHeight to distinguish the first time parsing.
      if ((0 == pFrameInfo->paddedWidth) && (0 == pFrameInfo->paddedHeight))
      {
         /// Since the sampling factor must be exponential of 2,
         /// we use shift instead of divide to accelerate calculating.
         samplingFactorMax = pFrameInfo->hSamplingFactorMax >> 1;
         while (samplingFactorMax)
         {
            log2_mcu_width++;
            samplingFactorMax >>= 1;
         }

         samplingFactorMax = pFrameInfo->vSamplingFactorMax >> 1;
         while (samplingFactorMax)
         {
            log2_mcu_height++;
            samplingFactorMax >>= 1;
         }

         pFrameInfo->mcuPerRow     = (pFrameInfo->width + (1 << log2_mcu_width) - 1) >> log2_mcu_width;
         pFrameInfo->paddedWidth   = pFrameInfo->mcuPerRow << log2_mcu_width;
         pFrameInfo->widthInBlocks = (pFrameInfo->width + 7) / 8;

         pFrameInfo->mcuPerColumn  = (pFrameInfo->height + (1 << log2_mcu_height) - 1) >> log2_mcu_height;
         pFrameInfo->paddedHeight  = pFrameInfo->mcuPerColumn << log2_mcu_height;

      }
   }

   return pParser->parseStatus;
}


JPEG_STATUS_ENUM jpeg_parser_get_encode_process(JPEG_FILE_INFO             *pParser,
                                                JPEG_ENCODE_PROCESS_ENUM   *pProcess)
{
   *pProcess = pParser->frameInfo.encProcess;

   return JPEG_STATUS_OK;
}


JPEG_STATUS_ENUM jpeg_parser_get_source_dimension(JPEG_FILE_INFO  *pParser,
                                                  kal_int32       *pWidth,
                                                  kal_int32       *pHeight)
{
   *pWidth  = pParser->frameInfo.width;
   *pHeight = pParser->frameInfo.height;

   return JPEG_STATUS_OK;
}


JPEG_STATUS_ENUM jpeg_parser_get_image_dimension(JPEG_FILE_INFO   *pParser,
                                                 kal_int32        *pWidth,
                                                 kal_int32        *pHeight)
{
   kal_uint32 orientation;
   kal_uint32 exif_width, exif_height;

   // add resolution check to aviod exif data inconsistence
   if (app1ParserExtractIFDTagData(pParser->app1Info, JPEG_APP1_IFD_TYPE_EXIF, EXIF_TAG_ID_PIXEL_X_DIMENSION, &exif_width, 4) <= 0)
   {
      exif_width = 0;
   }
   if (app1ParserExtractIFDTagData(pParser->app1Info, JPEG_APP1_IFD_TYPE_EXIF, EXIF_TAG_ID_PIXEL_Y_DIMENSION, &exif_height, 4) <= 0)
   {
      exif_height = 0;
   }
   if ((exif_width == pParser->frameInfo.width) && (exif_height == pParser->frameInfo.height))
   {
      if (app1ParserExtractIFDTagData(pParser->app1Info, JPEG_APP1_IFD_TYPE_IFD0, TIFF_TAG_ID_ORIENTATION, &orientation, 4) <= 0)
      {
         orientation = JPEG_DECODE_NO_FLIP_ROTATE_CW_0;
      }
   }
   else
   {
      orientation = JPEG_DECODE_NO_FLIP_ROTATE_CW_0;
   }

   switch(orientation)
   {
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_270:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_270:
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_90:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_90:
         *pWidth  = pParser->frameInfo.height;
         *pHeight = pParser->frameInfo.width;
         break;
      default:
         *pWidth  = pParser->frameInfo.width;
         *pHeight = pParser->frameInfo.height;
         break;
   }

   return JPEG_STATUS_OK;
}


JPEG_STATUS_ENUM jpeg_parser_get_thumbnail_info(JPEG_FILE_INFO             *pParser,
                                                JPEG_THUMBNAIL_TYPE_ENUM   *pTNType,
                                                kal_int32                  *pOffset,
                                                kal_int32                  *pSize,
                                                kal_int32                  *pWidth,
                                                kal_int32                  *pHeight)
{
   JPEG_THUMBNAIL_INFO *pThumbnail;

   pThumbnail = &(pParser->thumbnailInfo);

   *pTNType = pThumbnail->tn_type;
   *pOffset = pThumbnail->tn_offset;
   *pSize   = pThumbnail->tn_data_length;
   *pWidth  = pThumbnail->tn_width;
   *pHeight = pThumbnail->tn_height;

   return JPEG_STATUS_OK;
}


JPEG_STATUS_ENUM jpeg_parser_get_quick_view_info(JPEG_FILE_INFO            *pParser,
                                                 JPEG_THUMBNAIL_TYPE_ENUM  *pTNType,
                                                 kal_int32                 *pOffset,
                                                 kal_int32                 *pSize,
                                                 kal_int32                 *pWidth,
                                                 kal_int32                 *pHeight)
{
   JPEG_THUMBNAIL_INFO *pQVIInfo;

   pQVIInfo = &(pParser->qviInfo);

   *pTNType = pQVIInfo->tn_type;
   *pOffset = pQVIInfo->tn_offset;
   *pSize   = pQVIInfo->tn_data_length;
   *pWidth  = pQVIInfo->tn_width;
   *pHeight = pQVIInfo->tn_height;

   return JPEG_STATUS_OK;
}


JPEG_STATUS_ENUM jpeg_parser_get_image_description(JPEG_FILE_INFO   *pParser,
                                                 kal_uint8        *pImageDescription)
{
   kal_int32 byteSize; 
   EXIF_APP1_INFO *app1Info = pParser->app1Info;

   byteSize = app1ParserExtractIFDTagData(app1Info,
                                   JPEG_APP1_IFD_TYPE_IFD0,
                                   TIFF_TAG_ID_IMAGE_DESCRIPTION,
                                   (kal_uint32*)pImageDescription,
                                   10);
   if (byteSize <= 0)
   {
      pImageDescription = NULL;
   }
   else
   {
      if (TIFF_HEADER_BIG_ENDIAN == app1Info->byteOrder)
      {
         kal_int8 i, j;
         kal_uint8 tmp;
   
         i = byteSize;
         j = 0;
         while((--i >= 0) && (i > j))
         {
            tmp = pImageDescription[i];
            pImageDescription[i] = pImageDescription[j];
            pImageDescription[j] = tmp;
            j++;
         }
      }
   }

   return JPEG_STATUS_OK;
}

