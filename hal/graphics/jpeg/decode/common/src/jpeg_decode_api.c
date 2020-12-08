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
 *   jpeg_decode.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Code body of JPEG codec unified interface (decode).
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
#include "jpeg_enum.h"
#include "jpeg_decode_structure.h"
#include "jpeg_decode_int.h"
#include "exif_dec_structure.h"
#include "jpeg_mem_int.h"
#include "jpeg_parse_int.h"
#include "jpeg_misc_api.h"
#include "simple_memory_manager.h"
#include "swjd_huffman_decoder.h"
#include "swjd_dequant_idct_unit.h"
#include "swjd_fragment_processor.h"
#include "iul_x_math.h"
#include "gfx_cache_switch_behavior_enum.h"
#include "exif_dec_parser.h"

#if defined(__MTK_TARGET__)
   #include "mmu.h"
   #include "cache_sw.h"
   #include "idp_jpeg_decode.h"
   #include "img_common_enum.h"
   #include "drv_gfx_stack_switch_manager.h"

   #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
      #include "jpeg_drv_api.h"
   #endif
#else
   #include "stdlib.h"
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




#if defined(__JPEG_SW_PFMC_LOG_ENABLE__)
#include "GlobalConstants.h"
#include "DateTimeType.h"
#include "FileMgrType.h"
#include "fs_type.h"
#include "fmt_def.h"
#include "fs_errcode.h"
#include "FileMgrSrvGProt.h"
#include "app_datetime.h"

kal_bool JPEG_DEC_PFMC_LOG_FORCE_OUTPUT = 0;
kal_uint32 JPEG_DEC_PFMC_LOG_ENABLE = 0;
#define JPEG_DEC_PFMC_LOG_ENTRY_CNT 128
typedef struct
{
   unsigned int decode_index;
   unsigned int decode_start_time;
   unsigned int decode_end_time;
   unsigned int decode_exet_time[JPEG_DEC_PFMC_LOG_ENTRY_CNT];

}jpeg_dec_pfmc_log_t;
jpeg_dec_pfmc_log_t jpeg_dec_pfmc_log = {0};


#define JPEG_MAX_BUFFER  	128
kal_uint32 jpeg_iteration = 0;
#define JPEG_FILE_NAME_EXT	 L".xls"

void jpeg_dec_perfomance_log_output(void)
{
   //Output to file
   char data_buffer[JPEG_MAX_BUFFER];
   FS_HANDLE file_handler = -1;
   static WCHAR out_path[JPEG_MAX_BUFFER];
   int index = 0;
   kal_wsprintf(out_path, "%c:\\%w_%d%w", SRV_FMGR_PUBLIC_DRV, L"JPEG_PFMC_LOG", jpeg_iteration, JPEG_FILE_NAME_EXT);
   jpeg_iteration++;
   
   file_handler = FS_Open(out_path, FS_CREATE_ALWAYS);

   if(file_handler < 0)
   {
      ASSERT(0);
   }
   
   memset(data_buffer, 0x00, JPEG_MAX_BUFFER);
   kal_sprintf(data_buffer, "\tJPEG Decode Time (ms)\t\n");
   if((FS_Write(file_handler, data_buffer, strlen(data_buffer), NULL) < 0))
   {
         ASSERT(0);
   }
   
   for (index = 0; index < JPEG_DEC_PFMC_LOG_ENTRY_CNT; index++)   
   {
	   memset(data_buffer, 0x00, JPEG_MAX_BUFFER);

	   kal_sprintf(data_buffer, "\t%d\n", jpeg_dec_pfmc_log.decode_exet_time[index]);
	   
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

#define JPEG_DEC_DECODE_LOG_START()\
{\
  if (JPEG_DEC_PFMC_LOG_ENABLE)\
  {\
     jpeg_dec_pfmc_log.decode_start_time = drv_get_current_time();\
  }\
}
#define JPEG_DEC_DECODE_LOG_END()\
{\
  if (JPEG_DEC_PFMC_LOG_ENABLE)\
  {\
     jpeg_dec_pfmc_log.decode_end_time = drv_get_current_time();\
     jpeg_dec_pfmc_log.decode_exet_time[jpeg_dec_pfmc_log.decode_index] = drv_get_duration_tick(jpeg_dec_pfmc_log.decode_start_time, jpeg_dec_pfmc_log.decode_end_time);\
     jpeg_dec_pfmc_log.decode_index++;\
	  if ((JPEG_DEC_PFMC_LOG_ENTRY_CNT == jpeg_dec_pfmc_log.decode_index) || (JPEG_DEC_PFMC_LOG_FORCE_OUTPUT))\
	  {\
		 jpeg_dec_perfomance_log_output();\
	  }\
     jpeg_dec_pfmc_log.decode_index &= (JPEG_DEC_PFMC_LOG_ENTRY_CNT-1);\
  }\
}
#else
#define JPEG_DEC_DECODE_LOG_START()
#define JPEG_DEC_DECODE_LOG_END()
#endif


JPEG_STATUS_ENUM jpegDecGetDecoderExt(JPEG_CODEC_TYPE_ENUM codecType, JPEG_SCENARIO_TYPE_ENUM scenarioType, JPEG_DECODER_HANDLE *handlePtr)
{
   JPEG_STATUS_ENUM status = JPEG_STATUS_OK;

   if (NULL == handlePtr)
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   status = jpeg_dec_get_decoder(codecType, scenarioType, handlePtr); 

   return status;
}



JPEG_STATUS_ENUM jpegDecGetDecoder(JPEG_CODEC_TYPE_ENUM codecType, JPEG_DECODER_HANDLE *handlePtr)
{
#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__) || defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
   if (JPEG_CODEC_TYPE_HW == codecType)
   {
      *handlePtr = NULL;
      return JPEG_STATUS_CODEC_UNAVAILABLE;
   }
#endif

   // backward compatible with jpeg scenario
   return jpegDecGetDecoderExt(codecType, JPEG_SCENARIO_TYPE_JPEG, handlePtr);
}



JPEG_STATUS_ENUM jpegDecReleaseDecoder(JPEG_DECODER_HANDLE handle)
{
   JPEG_STATUS_ENUM status = JPEG_STATUS_OK;

   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   status = jpeg_dec_release_decoder(handle);

   return status;
}



/* Set functions for JPEG decoder */
JPEG_STATUS_ENUM jpegDecSetSourceFile(JPEG_DECODER_HANDLE handle, STFSAL *fp,
                                      void *readBufferAddr, kal_int32 readBufferSize,
                                      void *fsalCacheAddr, kal_int32 fsalCacheSize)
{
   JPEG_FILE_INFO *fileInfo;

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   kal_uint32     orientation;
   kal_uint32     exif_width, exif_height;
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

   ASSERT(0 == ((kal_uint32)readBufferAddr & 3));
   ASSERT(0 == ((kal_uint32)fsalCacheAddr & 3));


   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   /// Check input parameters.
   if (!fp)
   {
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_FILE;
      return handle->lastStatus;
   }

   #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
      #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
         if (JPEG_CODEC_TYPE_HW == handle->codecType)
         {
            if (readBufferAddr)
            {
               if (INT_QueryIsCachedRAM((kal_uint32)readBufferAddr, (kal_uint32)readBufferSize))
               {
                  ASSERT(0);
               }
            }

            if (fsalCacheAddr)
            {
               if (INT_QueryIsCachedRAM((kal_uint32)fsalCacheAddr, (kal_uint32)fsalCacheSize))
               {
                  ASSERT(0);
               }
            }
         }
      #endif /// __DYNAMIC_SWITCH_CACHEABILITY__
   #endif

   fileInfo = &(handle->fileInfo);

   memset(fileInfo, 0, sizeof(JPEG_FILE_INFO));

   fileInfo->fileHandle = fp;

   if (FSAL_OK != FSAL_GetFileSize(fp, &(fileInfo->realSize)))
   {
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_FILE;
      return handle->lastStatus;
   }

   if (FSAL_OK != FSAL_GetCurPos(fp, &(handle->imageOffsetInFile)))
   {
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_FILE;
      return handle->lastStatus;
   }

   #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_ALWAYS_READ_FILE__)
      /// For some chips, there is alignment requirement over than 4 bytes.
      /// We force to use read buffer to achieve this requirement.
      if (1)
   #else
      if (!FSAL_IsRamFile(fp))
   #endif
   {
      handle->fileIsInMemory = 0;
   }
   else
   {
      handle->fileIsInMemory = 1;

      #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
            /// If the source image resides in d-cacheable memory, we must treat it as a real file.
            /// Namely, we cannot directly set the source buffer to HW decoder due to the data inconsistency issue.
            /// We must read the data into file buffer, and set the file buffer to HW decoder.
            if (INT_QueryIsCachedRAM((kal_uint32)fp->pbFile, (kal_uint32)fp->uRamFileSize) &&
                JPEG_CODEC_TYPE_HW == handle->codecType)
            {
               handle->fileIsInMemory = 0;
            }
         #endif /// __DYNAMIC_SWITCH_CACHEABILITY__
      #endif
   }

   {
      ASSERT(readBufferAddr);

      #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         if (JPEG_CODEC_TYPE_HW == handle->codecType)
         {
            if (readBufferSize < JPEG_HW_DEC_MIN_FILE_BUFFER_SIZE)
            {
               handle->lastStatus = JPEG_STATUS_DEC_ERROR_INSUFFICIENT_MEMORY;
               return handle->lastStatus;
            }
         }
         else
      #endif
      {
         /// At least 10 KB for file read buffer.
         if (readBufferSize < JPEG_SW_DEC_MIN_FILE_BUFFER_SIZE)
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_INSUFFICIENT_MEMORY;
            return handle->lastStatus;
         }
      }

      if (fsalCacheAddr && fsalCacheSize)
      {
         /// Set up the fsal cache buffer.
         handle->fsalCacheAddr = (kal_uint8 *)fsalCacheAddr;
         handle->fsalCacheSize = fsalCacheSize;
         FSAL_SetBuffer(fp, handle->fsalCacheSize, handle->fsalCacheAddr);
      }

      /// Set up the file read buffer. 32-bytes alignment for address.
      /// Why 32-bytes alignment? Because 32-bytes alignment is fine for 4, 8, 16 and 32 alignments.
      /// It can avoid most mistake between different hardware requirement.
      handle->fsalReadBufferAddr = (kal_uint8 *)(((kal_uint32)readBufferAddr + 31) & 0xFFFFFFE0);
      handle->fsalReadBufferSize = (readBufferSize - sizeof(EXIF_APP1_INFO) - 16 - 32) & 0xFFFFFFE0;

      handle->app1InfoBuffer = (EXIF_APP1_INFO *)(((kal_uint32)handle->fsalReadBufferAddr + handle->fsalReadBufferSize + 15) & 0xFFFFFFF0);
   }

   jpeg_parser_parse_reset_internal(fileInfo,
                                    fp,
                                    fileInfo->realSize,
                                    (kal_uint32 *)handle->app1InfoBuffer,
                                    sizeof(EXIF_APP1_INFO));

   jpeg_parser_parse_start_internal(fileInfo, KAL_FALSE);

   if (JPEG_PARSE_STATE_COMPLETE != fileInfo->parseState)
   {
      handle->lastStatus = fileInfo->parseStatus;
   }
   else
   {
      JPEG_ENCODE_PROCESS_ENUM enc_proc;

      jpeg_parser_get_encode_process(fileInfo, &enc_proc);

      /// Currently, the SW decoder only supports baseline and progressive JPEG.
   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
      if ((JPEG_CODEC_TYPE_SW == handle->codecType) &&
          (JPEG_ENCODE_PROCESS_BASELINE != enc_proc) &&
          (JPEG_ENCODE_PROCESS_PROGRESSIVE != enc_proc))
   #else
      if ((JPEG_CODEC_TYPE_SW == handle->codecType) &&
          (JPEG_ENCODE_PROCESS_BASELINE != enc_proc))
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE
      {
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
      }

   #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__) && (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_PROGRESSIVE__))
      else if ((JPEG_CODEC_TYPE_HW == handle->codecType) &&
               (JPEG_ENCODE_PROCESS_BASELINE != enc_proc))
      {
         handle->lastStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
      }
   #endif

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)
      if (JPEG_ENCODE_PROCESS_PROGRESSIVE == enc_proc)
      {
         if ((fileInfo->frameInfo.width * fileInfo->frameInfo.height) > 
             (JPEG_DEC_MAX_PROG_IMAGE_WIDTH * JPEG_DEC_MAX_PROG_IMAGE_HEIGHT))
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
            return handle->lastStatus;
         }
      }
   #endif  // defined(SW_JPEG_DECODER_SUPPORT_WITH_PROGRESSIVE)

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
      // add resolution check to aviod exif data inconsistence
      if (app1ParserExtractIFDTagData(handle->app1InfoBuffer, JPEG_APP1_IFD_TYPE_EXIF, EXIF_TAG_ID_PIXEL_X_DIMENSION, &exif_width, 4) <= 0)
      {
         exif_width = 0;
      }
      if (app1ParserExtractIFDTagData(handle->app1InfoBuffer, JPEG_APP1_IFD_TYPE_EXIF, EXIF_TAG_ID_PIXEL_Y_DIMENSION, &exif_height, 4) <= 0)
      {
         exif_height = 0;
      }
      if ((exif_width == fileInfo->frameInfo.width) && (exif_height == fileInfo->frameInfo.height))
      {
         if (app1ParserExtractIFDTagData(handle->app1InfoBuffer, JPEG_APP1_IFD_TYPE_IFD0, TIFF_TAG_ID_ORIENTATION, &orientation, 4) <= 0)
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
         case JPEG_DECODE_FLIP_HORIZONTAL_ONLY:
            handle->rotationAngle = JPEG_DECODE_FLIP_HORIZONTAL_ONLY;
            break;
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_180:
            handle->rotationAngle = JPEG_DECODE_NO_FLIP_ROTATE_CW_180;
            break;
         case JPEG_DECODE_FLIP_AND_ROTATE_CW_180:
            handle->rotationAngle = JPEG_DECODE_FLIP_AND_ROTATE_CW_180;
            break;
         case JPEG_DECODE_FLIP_AND_ROTATE_CW_270:
            handle->rotationAngle = JPEG_DECODE_FLIP_AND_ROTATE_CW_270;
            break;
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_270:
            handle->rotationAngle = JPEG_DECODE_NO_FLIP_ROTATE_CW_90;
            break;
         case JPEG_DECODE_FLIP_AND_ROTATE_CW_90:
            handle->rotationAngle = JPEG_DECODE_FLIP_AND_ROTATE_CW_90;
            break;
         case JPEG_DECODE_NO_FLIP_ROTATE_CW_90:
            handle->rotationAngle = JPEG_DECODE_NO_FLIP_ROTATE_CW_270;
            break;
         default:
            handle->rotationAngle = JPEG_DECODE_NO_FLIP_ROTATE_CW_0;
            break;
      }
   #else
      handle->rotationAngle = JPEG_DECODE_NO_FLIP_ROTATE_CW_0;
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

   }

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecSetRGBCanvas(JPEG_DECODER_HANDLE handle, void *buffer, kal_uint32 width, kal_uint32 height, JPEG_RGB_FORMAT_ENUM format)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   if (!buffer || !width || !height)
   {
      handle->lastStatus = JPEG_STATUS_INVALID_PARAMETER;
      return handle->lastStatus;
   }

   switch (format)
   {
      case JPEG_RGB_FORMAT_GRAYLEVEL:
         handle->canvasBytesPerPixel = 1;
         break;
      case JPEG_RGB_FORMAT_RGB565:
         handle->canvasBytesPerPixel = 2;
         break;

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_RGB888)
      case JPEG_RGB_FORMAT_RGB888:
         handle->canvasBytesPerPixel = 3;
         break;
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_RGB888

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_BGR888)
      case JPEG_RGB_FORMAT_BGR888:
         handle->canvasBytesPerPixel = 3;
         break;
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_BGR888

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB6666)
      case JPEG_RGB_FORMAT_ARGB6666:
         handle->canvasBytesPerPixel = 3;
         break;
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB6666

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB8888)
      case JPEG_RGB_FORMAT_ARGB8888:
         handle->canvasBytesPerPixel = 4;
         break;
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_ARGB8888

      default:
         ASSERT(0);
         handle->lastStatus = JPEG_STATUS_INVALID_PARAMETER;
         return handle->lastStatus;
   }

   handle->canvasWnd.x = 0;
   handle->canvasWnd.y = 0;
   handle->canvasWnd.w = width;
   handle->canvasWnd.h = height;

   handle->canvasBuffer[0] = buffer;
   handle->canvasFormat = format;

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   if (JPEG_CODEC_TYPE_HW == handle->codecType)
   {
      if (INT_QueryIsCachedRAM((kal_uint32)buffer, width * height * handle->canvasBytesPerPixel))
      {
         ASSERT(0);
      }
   }
#endif

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}


JPEG_STATUS_ENUM jpegDecSetYUVCanvas(JPEG_DECODER_HANDLE    handle,
                                     void                   *buffer0,
                                     void                   *buffer1,
                                     void                   *buffer2,
                                     kal_uint32             width,
                                     kal_uint32             height,
                                     JPEG_YUV_FORMAT_ENUM   format)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   if (!buffer0 || !width || !height)
   {
      handle->lastStatus = JPEG_STATUS_INVALID_PARAMETER;
      return handle->lastStatus;
   }

   switch(format)
   {
   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV420)
      case JPEG_YUV_FORMAT_YUV420:
         if (width & 0x01)
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_WIDTH;
            return JPEG_STATUS_DEC_ERROR_INVALID_WIDTH;
         }
         else if (height & 0x01)
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_HEIGHT;
            return JPEG_STATUS_DEC_ERROR_INVALID_HEIGHT;
         }

      #if !defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_YUV420__)
         if (JPEG_CODEC_TYPE_HW == handle->codecType)
         {
            handle->lastStatus = JPEG_STATUS_INVALID_PARAMETER;
            return JPEG_STATUS_INVALID_PARAMETER;
         }
      #endif  // __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_YUV420__

         handle->canvasBytesPerPixel = 1;
         break;
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV420

   #if defined(SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV422)
      case JPEG_YUV_FORMAT_PACKED_UYVY422:
         if (width & 0x01)
         {
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_WIDTH;
            return JPEG_STATUS_DEC_ERROR_INVALID_WIDTH;
         }

      #if !defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_PACKED_UYVY422__)
         if (JPEG_CODEC_TYPE_HW == handle->codecType)
         {
            handle->lastStatus = JPEG_STATUS_INVALID_PARAMETER;
            return JPEG_STATUS_DEC_ERROR_INVALID_WIDTH;
         }
      #endif  // __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_SRC_PACKED_UYVY422__

         handle->canvasBytesPerPixel = 2;
         break;
   #endif  // SW_JPEG_DECODER_SUPPORT_WITH_DST_YUV422

      default:
         ASSERT(0);
         handle->lastStatus = JPEG_STATUS_INVALID_PARAMETER;
         return handle->lastStatus;
   }

   handle->canvasWnd.x = 0;
   handle->canvasWnd.y = 0;
   handle->canvasWnd.w = width;
   handle->canvasWnd.h = height;

   handle->canvasBuffer[0] = buffer0;
   handle->canvasBuffer[1] = buffer1;
   handle->canvasBuffer[2] = buffer2;

   handle->canvasFormat = format;

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   if (JPEG_CODEC_TYPE_HW == handle->codecType)
   {
      if (handle->canvasBuffer[0])
      {
         if (INT_QueryIsCachedRAM((kal_uint32)handle->canvasBuffer[0], width * height * handle->canvasBytesPerPixel))
         {
            ASSERT(0);
         }
      }

      if (format == JPEG_YUV_FORMAT_YUV420)
      {
         if (handle->canvasBuffer[1])
         {
            if (INT_QueryIsCachedRAM((kal_uint32)handle->canvasBuffer[1], (width * height * handle->canvasBytesPerPixel) >> 1))
            {
               ASSERT(0);
            }
         }
         if (handle->canvasBuffer[2])
         {
            if (INT_QueryIsCachedRAM((kal_uint32)handle->canvasBuffer[2], (width * height * handle->canvasBytesPerPixel) >> 1))
            {
               ASSERT(0);
            }
         }
      }
   }
#endif

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecSetOutputWindow(JPEG_DECODER_HANDLE handle,
                                        kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->outputWndIsSet = 1;
   handle->outputWnd.x = x;
   handle->outputWnd.y = y;
   handle->outputWnd.w = w;
   handle->outputWnd.h = h;

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecSetClipWindow(JPEG_DECODER_HANDLE handle,
                                      kal_int32 x, kal_int32 y, kal_uint32 w, kal_uint32 h)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->clipWndIsSet = 1;
   handle->clipWnd.x = x;
   handle->clipWnd.y = y;
   handle->clipWnd.w = w;
   handle->clipWnd.h = h;

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



/// Call this function to get the working memory for JPEG decoding.
/// The memory requirement is actually calculated right after the JPEG file is parsed.
JPEG_STATUS_ENUM jpegDecQueryWorkingMemory(JPEG_DECODER_HANDLE handle,
                                           kal_uint32 *intMemorySizeBest, kal_uint32 *intMemorySizeMinimum,
                                           kal_uint32 *extMemorySizeBest, kal_uint32 *extMemorySizeMinimum)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   jpeg_dec_query_working_memory_internal(handle);

   *intMemorySizeBest = handle->intMemorySizeBest;
   *intMemorySizeMinimum = handle->intMemorySizeMinimum;

   *extMemorySizeBest = handle->extMemorySizeBest;
   *extMemorySizeMinimum = handle->extMemorySizeMinimum;

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecQueryFileBuffer(JPEG_DECODER_HANDLE handle,
                                        kal_uint32 *readBufferSizeBest, kal_uint32 *readBufferSizeMinimum,
                                        kal_uint32 *fsalCacheSizeBest, kal_uint32 *fsalCacheSizeMinimum)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   if (handle->codecType == JPEG_CODEC_TYPE_HW)
   {
      *readBufferSizeMinimum = JPEG_HW_DEC_MIN_FILE_BUFFER_SIZE;
      *readBufferSizeBest    = JPEG_HW_DEC_MAX_FILE_BUFFER_SIZE;
   }
   else
   {
      *readBufferSizeMinimum = JPEG_SW_DEC_MIN_FILE_BUFFER_SIZE;
      *readBufferSizeBest    = JPEG_SW_DEC_MAX_FILE_BUFFER_SIZE;
   }

   *fsalCacheSizeMinimum = 0;
   *fsalCacheSizeBest = JPEG_DEC_FSAL_CACHE_SIZE;

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



/// Set up the JPEG decode working memory.
JPEG_STATUS_ENUM jpegDecSetWorkingMemory(JPEG_DECODER_HANDLE handle,
                                         kal_uint32 *intMemory, kal_uint32 intSize,
                                         kal_uint32 *extMemory, kal_uint32 extSize)
{
#if defined(DRV_FEATURE__MM_INTMEM_IF)
   kal_uint32     intMemAddr;
   kal_uint32     intMemSize;
   mm_scen_id_t mmScenId = MM_SCEN__JPEG_DECODE;
#endif  // DRV_FEATURE__MM_INTMEM_IF

   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   /// Check the memory size.
#if defined(DRV_FEATURE__MM_INTMEM_IF)
   if ((intSize < handle->intMemorySizeMinimum) || (extSize < handle->extMemorySizeMinimum))
#else
   if (extSize < handle->extMemorySizeMinimum)
#endif
   {
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_INSUFFICIENT_MEMORY;
      return handle->lastStatus;
   }

   handle->intMemoryAddr = intMemory;
   handle->intMemorySize = intSize;

#if defined(DRV_FEATURE__MM_INTMEM_IF)
   #if defined(MJPG_DECODE) 
      #if defined(__DRV_GRAPHICS_JPEG_6256_SERIES__) || defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)
         // only separate mm internal memory mode for 56 mjpeg
         if (JPEG_SCENARIO_TYPE_MJPEG == handle->scenarioType)
         {
            mmScenId = MM_SCEN__MJPEG_DECODE;
         }
      #endif
   #endif
   if (KAL_TRUE == mm_intmem_get(mmScenId, MM_INTMEM_SEG__JPEG_DEC, &intMemAddr, &intMemSize))
   {
      handle->intMemoryAddr = (kal_uint32 *)intMemAddr;
      handle->intMemorySize = intMemSize;
   }
   else
   {
      handle->intMemoryAddr = (kal_uint32 *)NULL;
      handle->intMemorySize = 0;
   }
#endif  // defined(DRV_FEATURE__MM_INTMEM_IF)

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   if (handle->codecType == JPEG_CODEC_TYPE_SW)
   {
      handle->extMemorySwitched = KAL_FALSE;

      if(GFX_CACHE_SWITCH_BEHAVIOR_TRY_SWITCH == (handle->dstBufferCacheSwitchBehavior))
      {
         if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(extMemory))) &&
             (IS_CACHE_LINE_SIZE_ALIGNED(extSize)) &&
             (is_predef_dyna_c_region((kal_uint32)(extMemory), extSize)))
         {
            if (KAL_TRUE == INT_QueryIsNonCachedRAM(extMemory, extSize))
            {
               dynamic_switch_cacheable_region((void*)&(extMemory), extSize, PAGE_CACHEABLE);
               handle->extMemorySwitched = KAL_TRUE;
            }
         }
      }
   }
#endif  // __DYNAMIC_SWITCH_CACHEABILITY__

   handle->extMemoryAddr = extMemory;
   handle->extMemorySize = extSize;

   return jpeg_dec_set_working_memory_internal(handle);
}



JPEG_STATUS_ENUM jpegDecSetCallbackFunction(JPEG_DECODER_HANDLE handle,
                                            kal_int32 (*callback_function)(JPEG_CODEC_STATE_ENUM state))
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->callback_function = callback_function;
   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



/// Call this function to get the JPEG dimension.
JPEG_STATUS_ENUM jpegDecGetImageDimension(JPEG_DECODER_HANDLE handle, kal_uint16 *width, kal_uint16 *height)
{
   JPEG_FILE_INFO *fileInfo;

   ASSERT(width);
   ASSERT(height);

   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   if ((!width) || (!height))
   {
      handle->lastStatus = JPEG_STATUS_INVALID_PARAMETER;
      return handle->lastStatus;
   }

   fileInfo = &(handle->fileInfo);

   if (JPEG_PARSE_STATE_COMPLETE != fileInfo->parseState)
   {
      *width = 0;
      *height = 0;
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_PARSE_INCOMPLETE;
      return handle->lastStatus;
   }

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   if ((JPEG_DECODE_FLIP_HORIZONTAL_ONLY   == handle->rotationAngle) ||
       (JPEG_DECODE_FLIP_AND_ROTATE_CW_180 == handle->rotationAngle) ||
       (JPEG_DECODE_NO_FLIP_ROTATE_CW_0    == handle->rotationAngle) ||
       (JPEG_DECODE_NO_FLIP_ROTATE_CW_180  == handle->rotationAngle))
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION
   {
      *width  = fileInfo->frameInfo.width;
      *height = fileInfo->frameInfo.height;
   }
#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   else
   {
      *width  = fileInfo->frameInfo.height;
      *height = fileInfo->frameInfo.width;
   }
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecSetDecodeMode(JPEG_DECODER_HANDLE handle, JPEG_DECODE_MODE_ENUM mode)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }
   handle->decodeMode = mode;

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}


JPEG_STATUS_ENUM jpegDecResume(JPEG_DECODER_HANDLE handle)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
            if (JPEG_DEC_PROG_ITERATION_COMPLETE_BIT & handle->hwProgressiveDecodeLeft)
            {
               handle->hwProgressiveDecodeLeft &= ~JPEG_DEC_PROG_ITERATION_COMPLETE_BIT;

               jpeg_dec_hw_config_decoder(handle);

               /// Read image data.
               if (JPEG_STATUS_OK != jpeg_dec_hw_read_data(handle))
               {
                  return handle->lastStatus;
               }

               /// Trigger the JPEG decoder.
               handle->codecState = JPEG_CODEC_STATE_BUSY;
               jpeg_drv_dec_start();
            }
            else
            {
               handle->codecState = JPEG_CODEC_STATE_BUSY;

               /// Read JPEG data.
               if (JPEG_STATUS_OK != jpeg_dec_hw_read_data(handle))
               {
                  return handle->lastStatus;
               }

               /// Trigger the JPEG decoder.
               jpeg_drv_dec_resume();
            }
            break;
      #endif /// __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__

      case JPEG_CODEC_TYPE_SW:
      {
         /// Currently, SW decoder does not support pause / resume function.
         handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
         return handle->lastStatus;
      }

      default:
         ASSERT(0);
         ///handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
         ///return handle->lastStatus;
   }

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecReset(JPEG_DECODER_HANDLE handle)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   jpeg_dec_reset_internal(handle);

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

   handle->lastStatus = JPEG_STATUS_OK;
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecGetDecoderState(JPEG_DECODER_HANDLE handle, JPEG_CODEC_STATE_ENUM *state)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   *state = handle->codecState;
   return JPEG_STATUS_OK;
}



JPEG_STATUS_ENUM jpegDecGetLastError(JPEG_DECODER_HANDLE handle)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   return handle->lastStatus;
}


/*
JPEG_STATUS_ENUM jpegDecGetThumbnailInfo(JPEG_DECODER_HANDLE handle, JPEG_THUMBNAIL_TYPE_ENUM *type, kal_uint32 *width, kal_uint32 *height, kal_uint32 *offset, kal_uint32 *size)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->lastStatus = jpegParserGetThumbnailInfo(&(handle->fileInfo), type, width, height, offset, size);
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecGetThumbnailData(JPEG_DECODER_HANDLE handle, kal_uint8 *dstBuffer, kal_uint32 *dstBufferSize)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->lastStatus = jpegParserGetThumbnailData(&(handle->fileInfo), dstBuffer, dstBufferSize);
   return handle->lastStatus;
}
*/


JPEG_STATUS_ENUM jpegDecSetCheckAbortFunction(JPEG_DECODER_HANDLE handle,
                                              CHECK_ABORT_FUNC    pCheckAbort)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   switch (handle->codecType)
   {
      #if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)
         case JPEG_CODEC_TYPE_HW:
            handle->pCheckAbort = NULL;
            handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
         break;
      #endif
      case JPEG_CODEC_TYPE_SW:
         handle->pCheckAbort = pCheckAbort;
      break;
      default:
         handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
   }

   return handle->lastStatus;
}


JPEG_STATUS_ENUM jpegDecSetRotation(JPEG_DECODER_HANDLE           handle,
                                    JPEG_DECODE_ROTATE_ANGLE_ENUM angle)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   if ((JPEG_DECODE_FLIP_HORIZONTAL_ONLY   != angle) &&
       (JPEG_DECODE_FLIP_AND_ROTATE_CW_90  != angle) &&
       (JPEG_DECODE_FLIP_AND_ROTATE_CW_180 != angle) &&
       (JPEG_DECODE_FLIP_AND_ROTATE_CW_270 != angle) &&
       (JPEG_DECODE_NO_FLIP_ROTATE_CW_0    != angle) &&
       (JPEG_DECODE_NO_FLIP_ROTATE_CW_90   != angle) &&
       (JPEG_DECODE_NO_FLIP_ROTATE_CW_180  != angle) &&
       (JPEG_DECODE_NO_FLIP_ROTATE_CW_270  != angle))
   {
      handle->lastStatus = JPEG_STATUS_INVALID_PARAMETER;
      return handle->lastStatus;
   }

   handle->rotationAngle = angle;
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecStart(JPEG_DECODER_HANDLE handle)
{
   JPEG_FILE_INFO *fileInfo = &(handle->fileInfo);
   JPEG_THUMBNAIL_INFO *tnInfo = &(fileInfo->thumbnailInfo);
   JPEG_THUMBNAIL_INFO *qviInfo = &(fileInfo->qviInfo);

   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   if (JPEG_CODEC_STATE_IDLE != handle->codecState ||
       JPEG_STATUS_OK != handle->lastStatus)
   {
      handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
      return handle->lastStatus;
   }

   if (!handle->outputWndIsSet)
   {
      handle->lastStatus = JPEG_STATUS_INVALID_PARAMETER;
      return handle->lastStatus;
   }

   if (!handle->clipWndIsSet)
   {
      memcpy(&(handle->clipWnd), &(handle->canvasWnd), sizeof(MY_RECTANGLE));
   }

   /// Check the output region intersection.
   {
      MY_RECTANGLE intersectRect;
      kal_int32 intersected = _jpeg_rect_get_intersection(&(handle->outputWnd), &(handle->clipWnd), &intersectRect);

      if (intersected)
      {
         intersected = _jpeg_rect_get_intersection(&(handle->canvasWnd), &intersectRect, &intersectRect);
      }

      if (!intersected)
      {
         /// The output window and clip window are not intersected, nothing to do.
         if (handle->callback_function)
         {
            handle->codecState = JPEG_CODEC_STATE_COMPLETE;
            handle->callback_function(JPEG_CODEC_STATE_COMPLETE);
         }
         handle->lastStatus = JPEG_STATUS_OK;
         return handle->lastStatus;
      }

      /// Align the intersection window with the output window coordinate.
      _jpeg_rect_align_coordinate(&(handle->outputWnd), &intersectRect, &(handle->targetClipWnd));
   }


   JPEG_DEC_DECODE_LOG_START();

   switch (handle->decodeMode)
   {
      case JPEG_DECODE_MODE_AUTO:
         if ((JPEG_THUMBNAIL_TYPE_NONE != tnInfo->tn_type) ||
             (JPEG_THUMBNAIL_TYPE_NONE != qviInfo->tn_type))
         {
            if ((handle->outputWnd.w <= tnInfo->tn_width) &&
                (handle->outputWnd.h <= tnInfo->tn_height))
            {
               handle->decodingSource = JPEG_DECODE_MODE_THUMBNAIL;
            }
            else
            {
               if ((handle->outputWnd.w <= qviInfo->tn_width) &&
                   (handle->outputWnd.h <= qviInfo->tn_height))
               {
                  handle->decodingSource = JPEG_DECODE_MODE_QUICK_VIEW_IMAGE;
               }
               else
               {
                  handle->decodingSource = JPEG_DECODE_MODE_MAIN_IMAGE;
               }
            }
         }
         else
         {
            handle->decodingSource = JPEG_DECODE_MODE_MAIN_IMAGE;
         }
         break;

      case JPEG_DECODE_MODE_MAIN_IMAGE:
         handle->decodingSource = JPEG_DECODE_MODE_MAIN_IMAGE;
         break;

      case JPEG_DECODE_MODE_THUMBNAIL:
         if (JPEG_THUMBNAIL_TYPE_NONE != tnInfo->tn_type)
         {
            handle->decodingSource = JPEG_DECODE_MODE_THUMBNAIL;
         }
         else
         {
            handle->decodingSource = JPEG_DECODE_MODE_MAIN_IMAGE;
         }
         break;

      case JPEG_DECODE_MODE_QUICK_VIEW_IMAGE:
         if (JPEG_THUMBNAIL_TYPE_NONE != qviInfo->tn_type)
         {
            handle->decodingSource = JPEG_DECODE_MODE_QUICK_VIEW_IMAGE;
         }
         else
         {
            handle->decodingSource = JPEG_DECODE_MODE_MAIN_IMAGE;
         }
         break;

      default:
         ASSERT(0);
         ///handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
         ///return handle->lastStatus;
   }

#if defined(SW_JPEG_DECODER_SUPPORT_WITH_ROTATION)
   if ((JPEG_CODEC_TYPE_HW == handle->codecType) &&
       (handle->rotationAngle != JPEG_DECODE_NO_FLIP_ROTATE_CW_0))
   {
      handle->codecState = JPEG_CODEC_STATE_ERROR;
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_UNSUPPORTED_FORMAT;
      return handle->lastStatus;
   }
#endif  // SW_JPEG_DECODER_SUPPORT_WITH_ROTATION

   /// Decode thumbnail and quick view image by the same JPEG decoding process.
   if ((JPEG_DECODE_MODE_THUMBNAIL == handle->decodingSource) ||
       (JPEG_DECODE_MODE_QUICK_VIEW_IMAGE == handle->decodingSource))
   {
      /// We want to use the same JPEG decode process for thumbnail and quick view image.
      /// When we decide to decode quick view image, we assign qviInfo to tnInfo in order
      /// to avoid too much code change.
      if (JPEG_DECODE_MODE_QUICK_VIEW_IMAGE == handle->decodingSource)
      {
         tnInfo = qviInfo;
      }

      switch (tnInfo->tn_type)
      {
         case JPEG_THUMBNAIL_TYPE_3BPP:
            /// Decode RGB888 thumbnail image.
            if (jpeg_dec_3bpp_thumbnail(handle))
            {           
               /// Thumbnail decoding completed.
               handle->codecState = JPEG_CODEC_STATE_COMPLETE;
               if (handle->callback_function)
               {
                  handle->callback_function(handle->codecState);
               }

               handle->lastStatus = JPEG_STATUS_OK;
               return handle->lastStatus;
            }
            else
            {
               /// Reset the JPEG decoder for decoding main image
               jpeg_dec_reset_internal(handle);

               /// Thumbnail decoding failed, try to decode main image.
               handle->decodingSource = JPEG_DECODE_MODE_MAIN_IMAGE;
            }
            break;

         case JPEG_THUMBNAIL_TYPE_JPEG:
            /// Decode the thumbnail JPEG.
            if (FSAL_OK == FSAL_Seek(fileInfo->fileHandle, tnInfo->tn_offset))
            {
               kal_int32 (*original_callback_function)(JPEG_CODEC_STATE_ENUM) = NULL;

               /// backup the fileInfo of main image.
               memcpy(handle->fileInfoBackup, fileInfo, sizeof(JPEG_FILE_INFO));

               /// backup the original callback function.
               original_callback_function = handle->callback_function;

               // Reset the JPEG parser before parsing
               jpeg_parser_parse_reset_internal(fileInfo,
                                                fileInfo->fileHandle,
                                                tnInfo->tn_data_length,
                                                NULL,
                                                0);

               /// SOI must exist at the beginning of the thumbnail image.
               jpeg_parser_parse_start_internal(fileInfo, KAL_TRUE);
			         if (JPEG_PARSE_STATE_COMPLETE != fileInfo->parseState)
               {
                   handle->codecState = JPEG_CODEC_STATE_ERROR; 
               }

#if (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORT_WITH_PROGRESSIVE__))
               if (JPEG_ENCODE_PROCESS_BASELINE != fileInfo->frameInfo.encProcess)
               {
                  /// Restore the callback function.
                  handle->callback_function = original_callback_function;
   
                  /// Restore the fileInfo.
                  memcpy(fileInfo, handle->fileInfoBackup, sizeof(JPEG_FILE_INFO));

                  /// Thumbnail decoding failed, try to decode main image.
                  handle->decodingSource = JPEG_DECODE_MODE_MAIN_IMAGE;
               }
               else
#endif
               {
                  if (JPEG_PARSE_STATE_COMPLETE == fileInfo->parseState)
                  {
                     /// Set the new callback function as NULL.
                     /// For thumbnail JPEG decoding, we simply use polling instead.
                     handle->callback_function = NULL;
   
                     if (JPEG_STATUS_OK == jpeg_dec_internal(handle))
                     {
                        kal_uint32 time_out_counter = 0;
                        kal_uint32 stop = 0;
   
                        while (0 == stop)
                        {
                           switch (handle->codecState)
                           {
                              case JPEG_CODEC_STATE_PAUSED:
                                 handle->codecState = JPEG_CODEC_STATE_BUSY;
   
                                 time_out_counter = 0;
                                 if (JPEG_STATUS_OK != jpegDecResume(handle))
                                 {
                                    handle->codecState = JPEG_CODEC_STATE_ERROR;
                                    stop = 1;
                                 }
                                 break;
   
                              case JPEG_CODEC_STATE_IDLE:
                              case JPEG_CODEC_STATE_ERROR:
                              case JPEG_CODEC_STATE_COMPLETE:
                                 stop = 1;
                                 break;
   
                              default:
                                 SLEEP(2);
                                 if (25 == time_out_counter++)
                                 {
                                    handle->codecState = JPEG_CODEC_STATE_ERROR;
                                    stop = 1;
                                 }
                           }
                        }
                     }
                     else
                     {
                        handle->codecState = JPEG_CODEC_STATE_ERROR;
                     }
                  }
                  else
                  {
                      handle->codecState = JPEG_CODEC_STATE_ERROR;
                  }
               }

               /// Restore the callback function.
               handle->callback_function = original_callback_function;

               /// Restore the fileInfo.
               memcpy(fileInfo, handle->fileInfoBackup, sizeof(JPEG_FILE_INFO));

               if ((JPEG_CODEC_STATE_COMPLETE == handle->codecState) ||
                   (JPEG_CODEC_STATE_IDLE     == handle->codecState))
               {
                  /// Thumbnail decoding completed.
                  if (handle->callback_function)
                  {
                     handle->callback_function(handle->codecState);
                  }
                  handle->lastStatus = JPEG_STATUS_OK;
                  JPEG_DEC_DECODE_LOG_END();
                  return handle->lastStatus;
               }
               else
               {
                  switch (handle->lastStatus)
                  {
                     case JPEG_STATUS_DEC_ERROR_SOURCE_DIMENSION_ERROR:
                     case JPEG_STATUS_DEC_ERROR_DESTINATION_DIMENSION_ERROR:
                     case JPEG_STATUS_IDP_ERROR:
                        // idp error doesn't need to be reset.
                        break;
                     default:
                        jpeg_dec_reset_internal(handle);
                        break;
                  }
                  handle->lastStatus = JPEG_STATUS_OK;
   
                  /// Thumbnail decoding failed, try to decode main image.
                  handle->decodingSource = JPEG_DECODE_MODE_MAIN_IMAGE;
               }
            }
            break;

         default:
            ASSERT(0);
      }
   }

   /// For SW decoder, if the decoding of a JPEG compressed thumbnail failed,
   /// the main JPEG FILE must be parsed again in order to re-install the decoding tables.

   if (JPEG_DECODE_MODE_MAIN_IMAGE == handle->decodingSource)
   {
      /// We don't have to invoke the callback function since
      /// the callback function will be called via the specified
      /// SW or HW decoders.

      jpeg_dec_internal(handle);
   }
   else
   {
      ASSERT(0);
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
   }

   JPEG_DEC_DECODE_LOG_END();
   return handle->lastStatus;
}



JPEG_STATUS_ENUM jpegDecSetDstBufferSwitchBehavior(JPEG_DECODER_HANDLE handle,
                                                 GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
       handle->dstBufferCacheSwitchBehavior = behavior;
   #endif

    return JPEG_STATUS_OK;
}



/*
JPEG_STATUS_ENUM jpegDecGetEncodeProcess(JPEG_DECODER_HANDLE handle, JPEG_ENCODE_PROCESS_ENUM *process)
{
   if (0 != jpeg_dec_check_handle(handle))
   {
      return JPEG_STATUS_INVALID_HANDLE;
   }

   handle->lastStatus = jpegParserGetEncodeProcess(&(handle->fileInfo), process);
   return handle->lastStatus;
}
*/

