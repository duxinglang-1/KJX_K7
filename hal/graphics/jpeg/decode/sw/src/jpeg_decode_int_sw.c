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
 *   jpeg_decode_sw.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Internal implementation of SW JPEG decode interface.
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
#include "jpeg_decode_structure.h"
#include "swjd_huffman_decoder.h"
#include "swjd_dequant_idct_unit.h"
#include "swjd_fragment_processor.h"
#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
#include "jpeg_drv_api.h"
#include "jpeg_drv_6250_series.h"
#endif



#if defined(__JPEG_SW_PFMC_LOG_ENABLE__)

#include "GlobalConstants.h"
#include "DateTimeType.h"
#include "FileMgrType.h"
#include "fs_type.h"
#include "fmt_def.h"
#include "fs_errcode.h"
#include "FileMgrSrvGProt.h"
#include "app_datetime.h"
#define JPEG_FMC_OUTPUT_BUFFER_SIZE        128
#define JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT 128

kal_uint32 jpeg_detail_iteration = 0;
kal_uint32 JPEG_DEC_PFMC_DATAIL_LOG_ENABLE = 0;
typedef struct
{
   unsigned int huff_dec_index;
   unsigned int huff_dec_start_time;
   unsigned int huff_dec_end_time;
   unsigned int huff_dec_exet_time[JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT];
   unsigned char huff_dec_log_start[JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT];

   unsigned int huff_dec_reset_index;
   unsigned int huff_dec_reset_start_time;
   unsigned int huff_dec_reset_end_time;
   unsigned int huff_dec_reset_exet_time[JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT];
   unsigned char huff_dec_reset_log_start[JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT];

   unsigned int idct_dec_index;
   unsigned int idct_dec_start_time;
   unsigned int idct_dec_end_time;
   unsigned int idct_dec_exet_time[JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT];
   unsigned char idct_dec_log_start[JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT];


   unsigned int frag_pro_index;
   unsigned int frag_pro_start_time;
   unsigned int frag_pro_end_time;
   unsigned int frag_pro_exet_time[JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT];
   unsigned char frag_pro_log_start[JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT];

}jpeg_dec_pfmc_detail_log_t;
jpeg_dec_pfmc_detail_log_t jpeg_dec_pfmc_detail_log = {0};



void jpeg_dec_perfomance_log_detail_output(void)
{
   //Output to file
   char data_buffer[JPEG_FMC_OUTPUT_BUFFER_SIZE];
   FS_HANDLE file_handler = -1;
   static WCHAR out_path[JPEG_FMC_OUTPUT_BUFFER_SIZE];
   int index = 0;
   kal_wsprintf(out_path, "%c:\\%w_%d%w", SRV_FMGR_PUBLIC_DRV, L"JPEG_PFMC_DETAIL_LOG", jpeg_detail_iteration, L".xls");
   jpeg_detail_iteration++;
   file_handler = FS_Open(out_path, FS_CREATE_ALWAYS);

   if(file_handler < 0)
   {
       ASSERT(0);
   }

   memset(data_buffer, 0x00, JPEG_FMC_OUTPUT_BUFFER_SIZE);
   kal_sprintf(data_buffer, "\t HuffDec \t HuffReset\t IDCT \t Fragment \n");
   if((FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL) < 0))
   {
         ASSERT(0);
   }

   for (index = 0; index < JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT; index++)
   {
     memset(data_buffer, 0x00, JPEG_FMC_OUTPUT_BUFFER_SIZE);

     kal_sprintf(data_buffer, "\t%d\t%d\t%d\t%d\n"
              , jpeg_dec_pfmc_detail_log.huff_dec_exet_time[index]
              , jpeg_dec_pfmc_detail_log.huff_dec_reset_exet_time[index]
              , jpeg_dec_pfmc_detail_log.idct_dec_exet_time[index]
              , jpeg_dec_pfmc_detail_log.frag_pro_exet_time[index]);

       if((FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL) < 0))
       {
             ASSERT(0);
       }
   }

   if(FS_Close(file_handler) < 0)
   {
        ASSERT(0);
   }
}

/*------------------------------------------------------------------------------------------*/

#define JPEG_DEC_HUFFMAN_LOG_START()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     jpeg_dec_pfmc_detail_log.huff_dec_start_time = drv_get_current_time();\
     if (0 == jpeg_dec_pfmc_detail_log.huff_dec_log_start[jpeg_dec_pfmc_detail_log.huff_dec_index])\
     {\
       jpeg_dec_pfmc_detail_log.huff_dec_exet_time[jpeg_dec_pfmc_detail_log.huff_dec_index] = 0;\
       jpeg_dec_pfmc_detail_log.huff_dec_log_start[jpeg_dec_pfmc_detail_log.huff_dec_index] = 1;\
     }\
  }\
}

#define JPEG_DEC_HUFFMAN_LOG_ONE_MCU_ROW()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     if (0 == jpeg_dec_pfmc_detail_log.huff_dec_log_start[jpeg_dec_pfmc_detail_log.huff_dec_index])\
     {\
       ASSERT(0);\
     }\
     jpeg_dec_pfmc_detail_log.huff_dec_end_time = drv_get_current_time();\
     jpeg_dec_pfmc_detail_log.huff_dec_exet_time[jpeg_dec_pfmc_detail_log.huff_dec_index] += drv_get_duration_tick(jpeg_dec_pfmc_detail_log.huff_dec_start_time, jpeg_dec_pfmc_detail_log.huff_dec_end_time);\
  }\
}

#define JPEG_DEC_HUFFMAN_LOG_END()\
{ \
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
    if (0 == jpeg_dec_pfmc_detail_log.huff_dec_log_start[jpeg_dec_pfmc_detail_log.huff_dec_index])\
  {\
    ASSERT(0);\
  }\
  jpeg_dec_pfmc_detail_log.huff_dec_log_start[jpeg_dec_pfmc_detail_log.huff_dec_index] = 0;\
    jpeg_dec_pfmc_detail_log.huff_dec_index++;\
    jpeg_dec_pfmc_detail_log.huff_dec_index &= (JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT-1);\
  }\
}

/*------------------------------------------------------------------------------------------*/
#define JPEG_DEC_HUFFMAN_RESET_LOG_START()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     jpeg_dec_pfmc_detail_log.huff_dec_reset_start_time = drv_get_current_time();\
     if (0 == jpeg_dec_pfmc_detail_log.huff_dec_reset_log_start[jpeg_dec_pfmc_detail_log.huff_dec_reset_index])\
     {\
       jpeg_dec_pfmc_detail_log.huff_dec_reset_exet_time[jpeg_dec_pfmc_detail_log.huff_dec_reset_index] = 0;\
       jpeg_dec_pfmc_detail_log.huff_dec_reset_log_start[jpeg_dec_pfmc_detail_log.huff_dec_reset_index] = 1;\
     }\
  }\
}

#define JPEG_DEC_HUFFMAN_RESET_LOG_ONE_MCU_ROW()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     if (0 == jpeg_dec_pfmc_detail_log.huff_dec_reset_log_start[jpeg_dec_pfmc_detail_log.huff_dec_reset_index])\
   {\
     ASSERT(0);\
     }\
     jpeg_dec_pfmc_detail_log.huff_dec_reset_end_time = drv_get_current_time();\
     jpeg_dec_pfmc_detail_log.huff_dec_reset_exet_time[jpeg_dec_pfmc_detail_log.huff_dec_reset_index] += drv_get_duration_tick(jpeg_dec_pfmc_detail_log.huff_dec_reset_start_time, jpeg_dec_pfmc_detail_log.huff_dec_reset_end_time);\
  }\
}

#define JPEG_DEC_HUFFMAN_RESET_LOG_END()\
{ \
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
  if (0 == jpeg_dec_pfmc_detail_log.huff_dec_reset_log_start[jpeg_dec_pfmc_detail_log.huff_dec_reset_index])\
  {\
    ASSERT(0);\
  }\
  jpeg_dec_pfmc_detail_log.huff_dec_reset_log_start[jpeg_dec_pfmc_detail_log.huff_dec_reset_index] = 0;\
    jpeg_dec_pfmc_detail_log.huff_dec_reset_index++;\
    jpeg_dec_pfmc_detail_log.huff_dec_reset_index &= (JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT-1);\
  }\
}

/*------------------------------------------------------------------------------------------*/

//IDCT
#define JPEG_DEC_IDCT_LOG_START()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     jpeg_dec_pfmc_detail_log.idct_dec_start_time = drv_get_current_time();\
     if (0 == jpeg_dec_pfmc_detail_log.idct_dec_log_start[jpeg_dec_pfmc_detail_log.idct_dec_index])\
     {\
       jpeg_dec_pfmc_detail_log.idct_dec_exet_time[jpeg_dec_pfmc_detail_log.idct_dec_index] = 0;\
       jpeg_dec_pfmc_detail_log.idct_dec_log_start[jpeg_dec_pfmc_detail_log.idct_dec_index] = 1;\
     }\
  }\
}

#define JPEG_DEC_IDCT_LOG_ONE_MCU_ROW()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     if (0 == jpeg_dec_pfmc_detail_log.idct_dec_log_start[jpeg_dec_pfmc_detail_log.idct_dec_index])\
        { ASSERT(0);}\
     jpeg_dec_pfmc_detail_log.idct_dec_end_time = drv_get_current_time();\
     jpeg_dec_pfmc_detail_log.idct_dec_exet_time[jpeg_dec_pfmc_detail_log.idct_dec_index] += drv_get_duration_tick(jpeg_dec_pfmc_detail_log.idct_dec_start_time, jpeg_dec_pfmc_detail_log.idct_dec_end_time);\
  }\
}

#define JPEG_DEC_IDCT_LOG_END()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     if (0 == jpeg_dec_pfmc_detail_log.idct_dec_log_start[jpeg_dec_pfmc_detail_log.idct_dec_index])\
        { ASSERT(0);}\
   jpeg_dec_pfmc_detail_log.idct_dec_log_start[jpeg_dec_pfmc_detail_log.idct_dec_index] = 0;\
     jpeg_dec_pfmc_detail_log.idct_dec_index++;\
     jpeg_dec_pfmc_detail_log.idct_dec_index &= (JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT-1);\
  }\
}
/*------------------------------------------------------------------------------------------*/



//Frag
#define JPEG_DEC_FRAG_LOG_START()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     jpeg_dec_pfmc_detail_log.frag_pro_start_time = drv_get_current_time();\
     if (0 == jpeg_dec_pfmc_detail_log.frag_pro_log_start[jpeg_dec_pfmc_detail_log.frag_pro_index])\
     {\
       jpeg_dec_pfmc_detail_log.frag_pro_exet_time[jpeg_dec_pfmc_detail_log.frag_pro_index] = 0;\
       jpeg_dec_pfmc_detail_log.frag_pro_log_start[jpeg_dec_pfmc_detail_log.frag_pro_index] = 1;\
     }\
  }\
}

#define JPEG_DEC_FRAG_LOG_ONE_MCU_ROW()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     if (0 == jpeg_dec_pfmc_detail_log.frag_pro_log_start[jpeg_dec_pfmc_detail_log.frag_pro_index])\
    { ASSERT(0);}\
     jpeg_dec_pfmc_detail_log.frag_pro_end_time = drv_get_current_time();\
     jpeg_dec_pfmc_detail_log.frag_pro_exet_time[jpeg_dec_pfmc_detail_log.frag_pro_index] += drv_get_duration_tick(jpeg_dec_pfmc_detail_log.frag_pro_start_time, jpeg_dec_pfmc_detail_log.frag_pro_end_time);\
  }\
}

#define JPEG_DEC_FRAG_LOG_END()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
     if (0 == jpeg_dec_pfmc_detail_log.frag_pro_log_start[jpeg_dec_pfmc_detail_log.frag_pro_index])\
       { ASSERT(0);}\
   jpeg_dec_pfmc_detail_log.frag_pro_log_start[jpeg_dec_pfmc_detail_log.frag_pro_index] = 0;\
     jpeg_dec_pfmc_detail_log.frag_pro_index++;\
     jpeg_dec_pfmc_detail_log.frag_pro_index &= (JPEG_DEC_PFMC_DETAIL_LOG_ENTRY_CNT-1);\
  }\
}

#define JPEG_DEC_LOG_DETAIL_OUTPUT()\
{\
  if (JPEG_DEC_PFMC_DATAIL_LOG_ENABLE)\
  {\
    if ((0 == jpeg_dec_pfmc_detail_log.idct_dec_index))\
    {\
     jpeg_dec_perfomance_log_detail_output();\
    }\
  }\
}
#else // #if defined(__JPEG_SW_PFMC_LOG_ENABLE__)
#define JPEG_DEC_HUFFMAN_LOG_START()
#define JPEG_DEC_HUFFMAN_LOG_ONE_MCU_ROW()
#define JPEG_DEC_HUFFMAN_LOG_END()
#define JPEG_DEC_HUFFMAN_RESET_LOG_START()
#define JPEG_DEC_HUFFMAN_RESET_LOG_ONE_MCU_ROW()
#define JPEG_DEC_HUFFMAN_RESET_LOG_END()
#define JPEG_DEC_IDCT_LOG_START()
#define JPEG_DEC_IDCT_LOG_ONE_MCU_ROW()
#define JPEG_DEC_IDCT_LOG_END()
#define JPEG_DEC_FRAG_LOG_START()
#define JPEG_DEC_FRAG_LOG_ONE_MCU_ROW()
#define JPEG_DEC_FRAG_LOG_END()
#define JPEG_DEC_LOG_DETAIL_OUTPUT()
#endif //defined(__JPEG_SW_PFMC_LOG_ENABLE__)



kal_int32 jpeg_dec_sw_get_mcu_size_bits(kal_uint32 max_sampling_factor)
{
   switch (max_sampling_factor)
   {
      case 1:
         return 3;
      case 2:
         return 4;
      case 4:
         return 5;
      default:
         ASSERT(0);
   }

   return -1;
}


JPEG_STATUS_ENUM jpeg_dec_sw_initialize(JPEG_DECODER_HANDLE handle)
{
   JPEG_FRAME_INFO            *pFrameInfo;
   IUL_FIXED                  srcStepX;
   IUL_FIXED                  srcStepY;
   IUL_FIXED                  scaleX;
   IUL_FIXED                  scaleY;
   IUL_FIXED                  srcLeft;
   IUL_FIXED                  srcRight;
   IUL_FIXED                  srcTop;
   IUL_FIXED                  srcBottom;
   void                       *pOutput0;
   void                       *pOutput1;
   void                       *pOutput2;
   kal_int32                  blockSize;
   kal_uint32                 fragWidth;
   kal_uint32                 fragHeight;
   kal_uint32                 fragPitch;
   FRAG_PROCESSOR_COLOR_ENUM  canvasFormat;
   kal_int32                  canvasPitch;
   kal_int32                  compIndex;
   kal_int32                  HSampling[3];
   kal_int32                  VSampling[3];
   kal_int32                  result;

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   IUL_FIXED                  tempVal; 
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

   // Default value to make compiler happy
   srcStepX = 0;
   srcStepY = 0;
   scaleX   = 0;
   scaleY   = 0;

   /// Since we are using S15.16 fixed-point calculation inside the SW JPEG decoder,
   /// we must set some restrictions on the output dimensions.
   if ((handle->outputWnd.w >= 65536) || (handle->outputWnd.h >= 65536))
   {
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_DESTINATION_DIMENSION_ERROR;
      return handle->lastStatus;
   }

   // Get the frame info from JPEG decoder handle
   pFrameInfo = &(handle->fileInfo.frameInfo);

   /// 1. Calculate the source step and scale ratio

   /// After the DCT scaling is determined, we must calculate srcStepX, srcStepY, scaleX and scaleY.
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   switch(handle->rotationAngle)
   {
      case JPEG_DECODE_FLIP_HORIZONTAL_ONLY:
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_180:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_0:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_180:
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION
         srcStepX = IUL_I_TO_X(pFrameInfo->width  >> handle->dctScaleBits) / handle->outputWnd.w;
         srcStepY = IUL_I_TO_X(pFrameInfo->height >> handle->dctScaleBits) / handle->outputWnd.h;
         scaleX   = IUL_I_TO_X(handle->outputWnd.w) / (pFrameInfo->width  >> handle->dctScaleBits);
         scaleY   = IUL_I_TO_X(handle->outputWnd.h) / (pFrameInfo->height >> handle->dctScaleBits);
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
         break;
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_90:
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_270:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_90:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_270:
         srcStepX = IUL_I_TO_X(pFrameInfo->height >> handle->dctScaleBits) / handle->outputWnd.w;
         srcStepY = IUL_I_TO_X(pFrameInfo->width  >> handle->dctScaleBits) / handle->outputWnd.h;
         scaleX   = IUL_I_TO_X(handle->outputWnd.w) / (pFrameInfo->height >> handle->dctScaleBits);
         scaleY   = IUL_I_TO_X(handle->outputWnd.h) / (pFrameInfo->width  >> handle->dctScaleBits);
         break;
   }
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

   /// 2. Update MCU dimension after DCT scaling.
   handle->mcuWidthBits  = jpeg_dec_sw_get_mcu_size_bits(pFrameInfo->hSamplingFactorMax) - handle->dctScaleBits;
   handle->mcuHeightBits = jpeg_dec_sw_get_mcu_size_bits(pFrameInfo->vSamplingFactorMax) - handle->dctScaleBits;

   /// 3. Calculate the valid MCU window.
   
   /// To achieve better precision, we must take different operations with respect to different scaling ratios.
   if (scaleX > IUL_I_TO_X(64))
   {
      srcLeft   = IUL_I_TO_X(handle->targetClipWnd.x) / IUL_X_TO_I(scaleX);
      srcRight  = IUL_I_TO_X((handle->targetClipWnd.x + handle->targetClipWnd.w)) / IUL_X_TO_I(scaleX);
   }
   else
   {
      srcLeft   = handle->targetClipWnd.x * srcStepX;
      srcRight  = (handle->targetClipWnd.x + handle->targetClipWnd.w) * srcStepX;
   }

   if (scaleY > IUL_I_TO_X(64))
   {
      srcTop    = IUL_I_TO_X(handle->targetClipWnd.y) / IUL_X_TO_I(scaleY);
      srcBottom = IUL_I_TO_X((handle->targetClipWnd.y + handle->targetClipWnd.h)) / IUL_X_TO_I(scaleY);
   }
   else
   {
      srcTop    = handle->targetClipWnd.y * srcStepY;
      srcBottom = (handle->targetClipWnd.y + handle->targetClipWnd.h) * srcStepY;
   }

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   // Get the the source coordinate without rotation
   switch(handle->rotationAngle)
   {
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_90:
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_270:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_90:
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_270:
         tempVal = srcLeft;
         srcLeft = srcTop;
         srcTop = tempVal;

         tempVal = srcRight;
         srcRight = srcBottom;
         srcBottom = tempVal;
         break;
   }
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

   // Calculate the valid MCU window
   handle->validMcuWnd.x = IUL_X_TO_I_CHOP(srcLeft) >> handle->mcuWidthBits;
   handle->validMcuWnd.y = IUL_X_TO_I_CHOP(srcTop) >> handle->mcuHeightBits;
   handle->validMcuWnd.w = (IUL_X_TO_I_CHOP(srcRight  - 1) >> handle->mcuWidthBits)  - handle->validMcuWnd.x + 1;
   handle->validMcuWnd.h = (IUL_X_TO_I_CHOP(srcBottom - 1) >> handle->mcuHeightBits) - handle->validMcuWnd.y + 1;;
 
  /// 4. Initialize the related components
 
   /// Initialize the sampling factor
   for (compIndex = pFrameInfo->numberOfComponents; --compIndex >= 0; )
   {
      HSampling[compIndex] = pFrameInfo->frameComponentInfo[compIndex].hSamplingFactor;
      VSampling[compIndex] = pFrameInfo->frameComponentInfo[compIndex].vSamplingFactor;
   }

   // Set the frame info for calculating the max DU count
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
   if (JPEG_ENCODE_PROCESS_PROGRESSIVE == pFrameInfo->encProcess)
   {
      result = huffmanDecSetFrameInfo(handle->pHuffDecoder,
                                      HUFFMAN_DEC_SOURCE_PROGRESSIVE,
                                      pFrameInfo->width,
                                      pFrameInfo->height,
                                      handle->validMcuWnd.w,
                                      handle->validMcuWnd.h,
                                      handle->dctLod,
                                      handle->restartInterval);
   }
   else
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
   {
      result = huffmanDecSetFrameInfo(handle->pHuffDecoder,
                                      HUFFMAN_DEC_SOURCE_BASELINE,
                                      pFrameInfo->width,
                                      pFrameInfo->height,
                                      handle->validMcuWnd.w,
                                      handle->validMcuWnd.h,
                                      handle->dctLod,
                                      handle->restartInterval);
   }

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   switch(handle->rotationAngle)
   {
      case JPEG_DECODE_FLIP_HORIZONTAL_ONLY:
         result |= huffmanDecSetTransform(handle->pHuffDecoder,
                                          HUFFMAN_DEC_TRANSFORM_FLIP_HORIZONTAL_ONLY);
         break;
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_90:
         result |= huffmanDecSetTransform(handle->pHuffDecoder,
                                          HUFFMAN_DEC_TRANSFORM_FLIP_AND_ROTATE_CW_90);
         break;
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_180:
         result |= huffmanDecSetTransform(handle->pHuffDecoder,
                                          HUFFMAN_DEC_TRANSFORM_FLIP_AND_ROTATE_CW_180);
         break;
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_270:
         result |= huffmanDecSetTransform(handle->pHuffDecoder,
                                          HUFFMAN_DEC_TRANSFORM_FLIP_AND_ROTATE_CW_270);
         break;
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_0:
         result |= huffmanDecSetTransform(handle->pHuffDecoder,
                                          HUFFMAN_DEC_TRANSFORM_NO_FLIP_ROTATE_CW_0);
         break;
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_90:
         result |= huffmanDecSetTransform(handle->pHuffDecoder,
                                          HUFFMAN_DEC_TRANSFORM_NO_FLIP_ROTATE_CW_90);
         break;
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_180:
         result |= huffmanDecSetTransform(handle->pHuffDecoder,
                                          HUFFMAN_DEC_TRANSFORM_NO_FLIP_ROTATE_CW_180);
         break;
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_270:
         result |= huffmanDecSetTransform(handle->pHuffDecoder,
                                          HUFFMAN_DEC_TRANSFORM_NO_FLIP_ROTATE_CW_270);
         break;
   }
#else
	result |= huffmanDecSetTransform(handle->pHuffDecoder,
                                    HUFFMAN_DEC_TRANSFORM_NO_FLIP_ROTATE_CW_0);
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION


#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
	result |= huffmanDecSetHybridIDCTEnable(handle->pHuffDecoder, handle->useHybridIDCTEnhance);

    if (handle->useHybridIDCTEnhance)
    {
       kal_uint32 regAddr;
       jpeg_drv_dec_get_src_base(&regAddr);
       // Set the Huffman decoder output buffer as the HW hybrid output buffer address
       result |= huffmanDecSetOutputBuffer(handle->pHuffDecoder,
                       (void *)regAddr,
                       (8 * 8 * 2 * 6)); //block * short * component_num
    }
    else
#endif //#if defined(__DRV_GRAPHICS_MT6250_HYBRID_SW_HW_JPEG_ENCODE_SUPPORTED__)
    {
       // Set the Huffman decoder output buffer base address
       result |= huffmanDecSetOutputBuffer(handle->pHuffDecoder,
                       handle->pHuffDecOutputBuf,
                       handle->huffDecOutputSize);
    }


   // Sampling factor for setting output buffer of each component
   result |= huffmanDecSetComponentInfo(handle->pHuffDecoder,
                                        pFrameInfo->numberOfComponents,
                                        HSampling,
                                        VSampling);

   // Get the max MCU count can be saved in the Huffman decoder
   result |= huffmanDecGetOutputBuffer(handle->pHuffDecoder,
                                       &pOutput0,
                                       &blockSize,
                                       &handle->huffDecOutputWidth);

   // Set the valid MCU window for the IDCT processing unit
   result |= dequantIDCTSetFrameInfo(handle->pDequantIDCTUnit,
                                     handle->validMcuWnd.w,
                                     handle->validMcuWnd.h);

   result |= dequantIDCTSetCoeffBuffer(handle->pDequantIDCTUnit,
                                       pOutput0,
                                       blockSize,
                                       handle->huffDecOutputWidth);

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   switch(handle->rotationAngle)
   {
      case JPEG_DECODE_FLIP_HORIZONTAL_ONLY:
         result |= dequantIDCTSetTransform(handle->pDequantIDCTUnit,
                                           DEQUANT_IDCT_TRANSFORM_FLIP_HORIZONTAL_ONLY);
         break;
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_90:
         result |= dequantIDCTSetTransform(handle->pDequantIDCTUnit,
                                           DEQUANT_IDCT_TRANSFORM_FLIP_AND_ROTATE_CW_90);
         break;
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_180:
         result |= dequantIDCTSetTransform(handle->pDequantIDCTUnit,
                                           DEQUANT_IDCT_TRANSFORM_FLIP_AND_ROTATE_CW_180);
         break;
      case JPEG_DECODE_FLIP_AND_ROTATE_CW_270:
         result |= dequantIDCTSetTransform(handle->pDequantIDCTUnit,
                                           DEQUANT_IDCT_TRANSFORM_FLIP_AND_ROTATE_CW_270);
         break;
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_0:
         result |= dequantIDCTSetTransform(handle->pDequantIDCTUnit,
                                           DEQUANT_IDCT_TRANSFORM_NO_FLIP_ROTATE_CW_0);
         break;
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_90:
         result |= dequantIDCTSetTransform(handle->pDequantIDCTUnit,
                                           DEQUANT_IDCT_TRANSFORM_NO_FLIP_ROTATE_CW_90);
         break;
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_180:
         result |= dequantIDCTSetTransform(handle->pDequantIDCTUnit,
                                           DEQUANT_IDCT_TRANSFORM_NO_FLIP_ROTATE_CW_180);
         break;
      case JPEG_DECODE_NO_FLIP_ROTATE_CW_270:
         result |= dequantIDCTSetTransform(handle->pDequantIDCTUnit,
                                           DEQUANT_IDCT_TRANSFORM_NO_FLIP_ROTATE_CW_270);
         break;
   }
#else
	result |= dequantIDCTSetTransform(handle->pDequantIDCTUnit,
                                     DEQUANT_IDCT_TRANSFORM_NO_FLIP_ROTATE_CW_0);
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

   handle->bypassFragment = KAL_FALSE;

   // Should we do the fragment processing in spatial domain?
   if ((handle->canvasFormat == pFrameInfo->samplingFormat) &&
       (0 == handle->outputWnd.x) &&
       (handle->canvasWnd.w == handle->outputWnd.w) &&
       (0 == handle->outputWnd.y) &&
       (handle->canvasWnd.h == handle->outputWnd.h) &&
       (handle->canvasWnd.w == (pFrameInfo->width  >> handle->dctScaleBits)) &&
       (handle->canvasWnd.h == (pFrameInfo->height >> handle->dctScaleBits)))
   {
      if ((JPEG_YUV_FORMAT_YUV420 == handle->canvasFormat) &&
          (0 == (handle->canvasWnd.w % 16)) &&
          (0 == (handle->canvasWnd.h % 16)))
      {
         result |= dequantIDCTSetOutputBuffer(handle->pDequantIDCTUnit,
                                              DEQUANT_IDCT_OUTPUT_FORMAT_YUV420,
                                              handle->canvasBuffer[0],
                                              handle->canvasBuffer[1],
                                              handle->canvasBuffer[2],
                                              handle->canvasWnd.w,
                                              handle->canvasWnd.h,
                                              handle->canvasWnd.w,
                                              handle->dctScaleBits);
         handle->bypassFragment = KAL_TRUE;  // We don't need to do fragment processing
      }
      else if ((JPEG_YUV_FORMAT_YUV422 == handle->canvasFormat) && 
               (0 == (handle->canvasWnd.w % 16)))
      {
         result |= dequantIDCTSetOutputBuffer(handle->pDequantIDCTUnit,
                                              DEQUANT_IDCT_OUTPUT_FORMAT_YUV422,
                                              handle->canvasBuffer[0],
                                              handle->canvasBuffer[1],
                                              handle->canvasBuffer[2],
                                              handle->canvasWnd.w,
                                              handle->canvasWnd.h,
                                              handle->canvasWnd.w,
                                              handle->dctScaleBits);
         handle->bypassFragment = KAL_TRUE;  // We don't need to do fragment processing
      }
   }

   if (KAL_FALSE == handle->bypassFragment)
   {
      // Set pixel output buffer for the dequant & IDCT unit
      result |= dequantIDCTSetOutputBuffer(handle->pDequantIDCTUnit,
                                           DEQUANT_IDCT_OUTPUT_FORMAT_DEFAULT,
                                           handle->pDequantIDCTOutputBuf,
                                           NULL,
                                           NULL,
                                           handle->dequantIDCTOutputSize,
                                           1,
                                           handle->dequantIDCTOutputSize,
                                           handle->dctScaleBits);
   }


   // Sampling factor for setting output buffer of each component
   result |= dequantIDCTSetComponentInfo(handle->pDequantIDCTUnit,
                                         pFrameInfo->numberOfComponents,
                                         HSampling,
                                         VSampling);

   if (KAL_FALSE == handle->bypassFragment)
   {
      result |= dequantIDCTGetOutputBuffer(handle->pDequantIDCTUnit,
                                           &pOutput0,
                                           &pOutput1,
                                           &pOutput2,
                                           &fragWidth,
                                           &fragHeight,
                                           &fragPitch);

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
      switch(handle->rotationAngle)
      {
         case JPEG_DECODE_FLIP_HORIZONTAL_ONLY:
            result |= fragProcessorSetRotation(handle->pFragProcessor,
                                               FRAG_PROCESSOR_TRANSFORM_FLIP_HORIZONTAL_ONLY);
            break;
         case JPEG_DECODE_FLIP_AND_ROTATE_CW_90:
            result |= fragProcessorSetRotation(handle->pFragProcessor,
                                               FRAG_PROCESSOR_TRANSFORM_FLIP_AND_ROTATE_CW_90);
            break;
         case JPEG_DECODE_FLIP_AND_ROTATE_CW_180:
            result |= fragProcessorSetRotation(handle->pFragProcessor,
                                               FRAG_PROCESSOR_TRANSFORM_FLIP_AND_ROTATE_CW_180);
            break;
         case JPEG_DECODE_FLIP_AND_ROTATE_CW_270:
            result |= fragProcessorSetRotation(handle->pFragProcessor,
                                               FRAG_PROCESSOR_TRANSFORM_FLIP_AND_ROTATE_CW_270);
            break;
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_0:
            result |= fragProcessorSetRotation(handle->pFragProcessor,
                                               FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_0);
            break;
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_90:
            result |= fragProcessorSetRotation(handle->pFragProcessor,
                                               FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_90);
            break;
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_180:
            result |= fragProcessorSetRotation(handle->pFragProcessor,
                                               FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_180);
            break;
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_270:
            result |= fragProcessorSetRotation(handle->pFragProcessor,
                                               FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_270);
            break;
      }
   #else
	   result |= fragProcessorSetRotation(handle->pFragProcessor,
                                         FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_0);
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

      result |= fragProcessorSetFragBuffer(handle->pFragProcessor,
                                           pOutput0,
                                           pOutput1,
                                           pOutput2,
                                           fragWidth,
                                           fragHeight,
                                           fragPitch);

      result |= fragProcessorSetComponentInfo(handle->pFragProcessor,
                                              pFrameInfo->numberOfComponents,
                                              HSampling,
                                              VSampling);

      // Set fragment processor scale ratio
   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
      switch(handle->rotationAngle)
      {
         case JPEG_DECODE_FLIP_HORIZONTAL_ONLY:
         case JPEG_DECODE_FLIP_AND_ROTATE_CW_180:
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_0:
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_180:
            result |= fragProcessorSetScaleInfo(handle->pFragProcessor,
                                                handle->mcuWidthBits,
                                                handle->mcuHeightBits,
                                                pFrameInfo->width  >> handle->dctScaleBits,
                                                pFrameInfo->height >> handle->dctScaleBits,
                                                handle->outputWnd.w,
                                                handle->outputWnd.h);
            break;
         case JPEG_DECODE_FLIP_AND_ROTATE_CW_90:
         case JPEG_DECODE_FLIP_AND_ROTATE_CW_270:
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_90:
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_270:
            result |= fragProcessorSetScaleInfo(handle->pFragProcessor,
                                                handle->mcuWidthBits,
                                                handle->mcuHeightBits,
                                                pFrameInfo->height >> handle->dctScaleBits,
                                                pFrameInfo->width  >> handle->dctScaleBits,
                                                handle->outputWnd.w,
                                                handle->outputWnd.h);
            break;
      }
   #else
      result |= fragProcessorSetScaleInfo(handle->pFragProcessor,
                                          handle->mcuWidthBits,
                                          handle->mcuHeightBits,
                                          pFrameInfo->width  >> handle->dctScaleBits,
                                          pFrameInfo->height >> handle->dctScaleBits,
                                          handle->outputWnd.w,
                                          handle->outputWnd.h);
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

      switch (handle->canvasFormat)
      {
         case JPEG_RGB_FORMAT_RGB565:
            canvasFormat = FRAG_PROCESSOR_COLOR_FORMAT_RGB565;
            canvasPitch  = handle->canvasWnd.w * 2;
            break;

      #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB6666)
         case JPEG_RGB_FORMAT_ARGB6666:
            canvasFormat = FRAG_PROCESSOR_COLOR_FORMAT_ARGB6666;
            canvasPitch  = handle->canvasWnd.w * 3;
            break;
      #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB6666

      #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB8888)
         case JPEG_RGB_FORMAT_ARGB8888:
            canvasFormat = FRAG_PROCESSOR_COLOR_FORMAT_ARGB8888;
            canvasPitch  = handle->canvasWnd.w * 4;
            break;
      #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB8888

      #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_RGB888)
         case JPEG_RGB_FORMAT_RGB888:
            canvasFormat = FRAG_PROCESSOR_COLOR_FORMAT_RGB888;
            canvasPitch  = handle->canvasWnd.w * 3;
            break;
      #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_RGB888

      #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_BGR888)
         case JPEG_RGB_FORMAT_BGR888:
            canvasFormat = FRAG_PROCESSOR_COLOR_FORMAT_BGR888;
            canvasPitch  = handle->canvasWnd.w * 3;
            break;
      #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_BGR888

      #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV420)
         case JPEG_YUV_FORMAT_YUV420:
            canvasFormat = FRAG_PROCESSOR_COLOR_FORMAT_YUV420;
            canvasPitch  = handle->canvasWnd.w * 1;
            break;
      #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV420

      #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV422)
         case JPEG_YUV_FORMAT_PACKED_UYVY422:
            canvasFormat = FRAG_PROCESSOR_COLOR_FORMAT_UYVY422;
            canvasPitch  = handle->canvasWnd.w * 2;
            break;
      #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV422
         default:
            ASSERT(0);
            return JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
      }

      // Set the canvas buffer for the fragment processor
      result |= fragProcessorSetCanvasBuffer(handle->pFragProcessor,
                                             canvasFormat,
                                             handle->canvasBuffer[0],
                                             handle->canvasBuffer[1],
                                             handle->canvasBuffer[2],
                                             handle->canvasWnd.w,
                                             handle->canvasWnd.h,
                                             canvasPitch);

      // Set the X and Y coordinates for rendering the decoded image
      result |= fragProcessorSetOutputOffset(handle->pFragProcessor,
                                             handle->outputWnd.x,
                                             handle->outputWnd.y);

      // Set target clip window for rendering the decoded image
      result |= fragProcessorSetTargetWindow(handle->pFragProcessor,
                                             handle->targetClipWnd.x + handle->outputWnd.x,
                                             handle->targetClipWnd.y + handle->outputWnd.y,
                                             handle->targetClipWnd.w,
                                             handle->targetClipWnd.h);
   }

   if (0 != result )
   {
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
      return handle->lastStatus;
   }

   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpeg_dec_sw_do_huffman_for_n_mcu(
   JPEG_DECODER_HANDLE handle,
   kal_uint32 MCUWidth,
   CHECK_ABORT_FUNC pCheckAbort)
{
  kal_int32          HMCUIndex;
  HUFFMAN_DEC_STATUS_ENUM    huffStatus;
  DEQUANT_IDCT_STATUS_ENUM   idctStatus;

    for (HMCUIndex = MCUWidth; --HMCUIndex >= 0;)
    {
       SW_DECODE_CHECK_ABORT(handle, pCheckAbort);
#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)

       if (handle->useHybridIDCTEnhance)
       {
          huffStatus = huffmanDecDecodeECSDataToHW(handle->pHuffDecoder);
          if (huffStatus < 0)
          {
             handle->codecState = JPEG_CODEC_STATE_ERROR;
             handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
             return handle->lastStatus;
          }
          
          idctStatus = dequantIDCTGetHwOutputToDstBuf(handle->pDequantIDCTUnit);
          if (idctStatus < 0)
          {
             handle->codecState = JPEG_CODEC_STATE_ERROR;
             handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
             return handle->lastStatus;
          }
       }
       else
#endif  //defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
       {
          huffStatus = huffmanDecDecodeECSData(handle->pHuffDecoder);
          if (huffStatus < 0)
          {
             handle->codecState = JPEG_CODEC_STATE_ERROR;
             handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
             JPEG_DEC_HUFFMAN_LOG_END(); 
             return handle->lastStatus;
          }
       }
    }

  return JPEG_STATUS_OK;
}


DEQUANT_IDCT_STATUS_ENUM jpeg_dec_sw_do_idct_fo_n_mcu(
   JPEG_DECODER_HANDLE handle,
   kal_uint32 MCUOffset,
   kal_uint32 MCUWidth)
{
   if (KAL_FALSE == handle->useHybridIDCTEnhance)
   {
      // IDCT processing the decoded coefficients
      return dequantIDCTProcessDUData(handle->pDequantIDCTUnit, MCUOffset, MCUWidth);
   }
   else
   {
      // do nothing
      // move to huffman
      //idctStatus = hwDequantIDCTProcessDUData(handle->pDequantIDCTUnit, 0, MCUWidth);
   }

   return DEQUANT_IDCT_STATUS_RETURN_SUCCESS;
}



void jpeg_dec_dump_setting(JPEG_DECODER_HANDLE handle)
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



JPEG_STATUS_ENUM jpeg_dec_sw_internal(JPEG_DECODER_HANDLE handle)
{
   JPEG_FRAME_INFO            *pFrameInfo;
   kal_int32                  HMCUIndex;
   kal_int32                  VMCUIndex;
   kal_int32                  currentMCUX;
   kal_int32                  currentMCUY;
   kal_int32                  MCUStartX;
   kal_int32                  MCUStartY;
   kal_int32                  MCUOffset;
   kal_int32                  MCUWidth;
   kal_int32                  MCUHeight;
   kal_int32                  MCUCount;
   kal_bool                   discard;
   HUFFMAN_DEC_STATUS_ENUM    huffStatus;
   DEQUANT_IDCT_STATUS_ENUM   idctStatus;
   FRAG_PROCESSOR_STATUS_ENUM fragStatus;
   CHECK_ABORT_FUNC           pCheckAbort;
   JPEG_STATUS_ENUM           decStatus;
   // Get the check abort function
   pCheckAbort = handle->pCheckAbort;

   jpeg_dec_dump_setting(handle);

   if (KAL_TRUE == handle->bypassFragment)
   {
      // Max Huffman decoder output MCU count
      MCUWidth = handle->huffDecOutputWidth;

      // Total MCU count needed to be decoded
      MCUCount = handle->validMcuWnd.w * handle->validMcuWnd.h;

      // This is for MJPEG decoding with YUV420 or YUV422 output
      // For this condition, we will bypass fragment processing.
      do
      {
         // Check the max MCU should be decoded
         MCUWidth = MIN(MCUCount, MCUWidth);
          // Huffman decode the ECS encoded data
          JPEG_DEC_HUFFMAN_LOG_START();
          decStatus = jpeg_dec_sw_do_huffman_for_n_mcu(handle, MCUWidth, pCheckAbort);
          JPEG_DEC_HUFFMAN_LOG_ONE_MCU_ROW();
          if (JPEG_STATUS_OK != decStatus)
          {
             handle->codecState = JPEG_CODEC_STATE_ERROR;
             handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
             return handle->lastStatus;
          }
          
          JPEG_DEC_IDCT_LOG_START();
          idctStatus = jpeg_dec_sw_do_idct_fo_n_mcu(handle, 0, MCUWidth);
          JPEG_DEC_IDCT_LOG_ONE_MCU_ROW();
          if (idctStatus < 0)
          {
             handle->codecState = JPEG_CODEC_STATE_ERROR;
             handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
             return handle->lastStatus;
          }
          
          // Reset Huffman decoder output buffer
          JPEG_DEC_HUFFMAN_RESET_LOG_START();
          huffmanDecResetOutputBuffer(handle->pHuffDecoder);
          JPEG_DEC_HUFFMAN_RESET_LOG_ONE_MCU_ROW();
          
          MCUCount -= MCUWidth;
      } while(MCUCount > 0);
      JPEG_DEC_HUFFMAN_LOG_END();
      JPEG_DEC_HUFFMAN_RESET_LOG_END();
      JPEG_DEC_IDCT_LOG_END();

   }
   else
   {
      // Get frame info from file handle
      pFrameInfo = &(handle->fileInfo.frameInfo);

      // In order to get better performance we should only decode the data
      // needed by fragment processor. The is true as the source JPEG image
      // grows larger and larger. Because the more and more Huffman decoded
      // data will become garbage.
      currentMCUX = 0;
      currentMCUY = 0;
      do
      {
         // This is the temporary version for querying frag window during decoding.
         // There are still some dummy function calls wtih discard set to true.
         // But the MCU needed to bypassed equals to 0 and finally we bypassed no MCU.
         fragProcessorGetFragWindow(handle->pFragProcessor,
                                    &MCUStartX,
                                    &MCUStartY,
                                    &MCUWidth,
                                    &MCUHeight,
                                    &discard);     // KAL_TRUE if we don't need the trailing MCU data of this row

         // When fragHeight is set to 0, we have completed the decoding process.
         if (0 == MCUHeight)
         {
            break;
         }

         JPEG_DEC_HUFFMAN_LOG_START();
         /// 1. Skip invalid MCU row
         for (VMCUIndex = (MCUStartY - currentMCUY); --VMCUIndex >= 0;)
         {
            SW_DECODE_CHECK_ABORT(handle, pCheckAbort);

            huffmanDecBypassECSData(handle->pHuffDecoder, pFrameInfo->mcuPerRow - currentMCUX);

            currentMCUX = 0;
            currentMCUY++;

            // Reset Huffman decoder output buffer
            huffmanDecResetOutputBuffer(handle->pHuffDecoder);
         }

         /// 2. Handle the valid MCU rows.
         for (VMCUIndex = MCUHeight; --VMCUIndex >= 0;)
         {
            SW_DECODE_CHECK_ABORT(handle, pCheckAbort);

            /// 2.1 Skip the preceding invalid MCUs.
            if ((MCUStartX - currentMCUX) > 0)
            {
               huffmanDecBypassECSData(handle->pHuffDecoder, MCUStartX - currentMCUX);
               currentMCUX += MCUStartX - currentMCUX;
            }

            /// 2.2 Decode the valid MCUs.
            decStatus = jpeg_dec_sw_do_huffman_for_n_mcu(handle, MCUWidth, pCheckAbort);
            if (JPEG_STATUS_OK != decStatus)
            {
               handle->codecState = JPEG_CODEC_STATE_ERROR;
               handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
               return handle->lastStatus;
            }

            // Update current MCU X
            currentMCUX += MCUWidth;

            /// 2.3 Skip the trailing MCU data
            if (KAL_TRUE == discard)
            {        
               SW_DECODE_CHECK_ABORT(handle, pCheckAbort);

               huffmanDecBypassECSData(handle->pHuffDecoder, pFrameInfo->mcuPerRow - MCUStartX - MCUWidth);
               currentMCUX += pFrameInfo->mcuPerRow - MCUStartX - MCUWidth;
            }

            // Update current MCU X & Y coordinates
            if (currentMCUX >= pFrameInfo->mcuPerRow)
            {
               currentMCUX = 0;
               currentMCUY ++;
            }
         }
		 JPEG_DEC_HUFFMAN_LOG_ONE_MCU_ROW();

         // Query the MCU data buffered in the Huffman decoder
         JPEG_DEC_IDCT_LOG_START();
         huffmanDecQueryOutputData(handle->pHuffDecoder, &MCUOffset, &MCUCount);

         idctStatus = jpeg_dec_sw_do_idct_fo_n_mcu(handle, MCUOffset, MCUCount);
         if (idctStatus < 0)
         {
            JPEG_DEC_HUFFMAN_LOG_END();
            JPEG_DEC_IDCT_LOG_END();
            handle->codecState = JPEG_CODEC_STATE_ERROR;
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
            return handle->lastStatus;
         }
         JPEG_DEC_IDCT_LOG_ONE_MCU_ROW();


         // Reset Huffman decoder output buffer
         JPEG_DEC_HUFFMAN_RESET_LOG_START();
         huffmanDecResetOutputBuffer(handle->pHuffDecoder);
         JPEG_DEC_HUFFMAN_RESET_LOG_ONE_MCU_ROW();



         // Processing the fragment data by fragment processor
         JPEG_DEC_FRAG_LOG_START();
         fragStatus = fragProcessorProcessData(handle->pFragProcessor,
                                               0,
                                               MCUWidth,
                                               MCUHeight);
         JPEG_DEC_FRAG_LOG_ONE_MCU_ROW();

         if (fragStatus < 0)
         {
            handle->codecState = JPEG_CODEC_STATE_ERROR;
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
            JPEG_DEC_HUFFMAN_LOG_END();
            JPEG_DEC_HUFFMAN_RESET_LOG_END();
            JPEG_DEC_IDCT_LOG_END();
            JPEG_DEC_FRAG_LOG_END();

            return handle->lastStatus;
         }

         // Reset dequant IDCT output buffer
         dequantIDCTResetOutputBuffer(handle->pDequantIDCTUnit);
      } while(1);
      JPEG_DEC_HUFFMAN_LOG_END();
      JPEG_DEC_HUFFMAN_RESET_LOG_END();
      JPEG_DEC_IDCT_LOG_END();
      JPEG_DEC_FRAG_LOG_END();

   }
   JPEG_DEC_LOG_DETAIL_OUTPUT();
   handle->codecState = JPEG_CODEC_STATE_COMPLETE;
   return JPEG_STATUS_OK;
}
