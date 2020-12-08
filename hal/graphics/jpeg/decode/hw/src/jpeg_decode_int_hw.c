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
 *   jpeg_decode_int_hw.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Internal implementation of HW JPEG decode interface.
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

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__)

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

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "fsal.h"
#include "rs_buffer.h"
#include "drv_comm.h"

#include "swjd_const_tables.h"
#include "jpeg_enum.h"
#include "jpeg_decode_structure.h"
#include "jpeg_parse_structure.h"
#include "jpeg_misc_api.h"
#include "jpeg_drv_api.h"
#include "jpeg_enum_int.h"

#if defined(__MTK_TARGET__)
   #include "mmu.h"
   #include "cache_sw.h"
   #include "idp_jpeg_decode.h"
   #include "img_common_enum.h"
   #include "drv_gfx_dct_control.h"
#endif


static JPEG_DECODER _jpeg_hw_decoder;


#if defined(__JPEG_DEC_PATCH_FOR_HQA00000732__)
extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time);

void jpeg_dec_hw_patch_for_HQA00000732(void)
{
   kal_uint32 start_tick = drv_get_current_time();
   kal_uint32 current_tick = drv_get_current_time();

   /// Idle for 1.5ms (32768 / 1000 * 1.5 = 49.152)
   while (drv_get_duration_tick(start_tick, current_tick) < 50)
   {
      current_tick = drv_get_current_time();
   }
}
#endif



/*
 * @brief Trigger JPEG decoder copy sysram data.
 * @remakes Asynchronous API.
 *
 */
#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)
JPEG_STATUS_ENUM jpeg_dec_copy_block(JPEG_DECODER_HANDLE handle)
{
   kal_int32 i, j;
   kal_uint32 sys_status;
   
   JPEG_FILE_INFO *fileInfo = &(handle->fileInfo);
   JPEG_FRAME_INFO *frameInfo = &(fileInfo->frameInfo);
   kal_uint32 srcMcuCount, srcResizeFactor;
   kal_uint32 hwDecodeMcuCount[2];
   kal_uint32 srcSampleFactorH[3], srcSampleFactorV[3];
   kal_uint32 srcMcuWidth[3], srcMcuSize[3];

   kal_uint8* dstBufAddr[3];
   kal_uint32 dstMcuStart[3], dstMcuWidth[3], dstMcuHeight[3], dstMcuPitch[3], dstCopyHeight;
   CHECK_ABORT_FUNC           pCheckAbort;
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   kal_bool enableDynamicSwitch[3] = {KAL_FALSE, KAL_FALSE, KAL_FALSE};
   kal_uint32 hwDecodeSysBufferTotalSize;
#endif


   // Get the check abort function
   pCheckAbort = handle->pCheckAbort;
   
   jpeg_drv_dec_get_sys_status(&sys_status);
   if (JPEG_DRV_DEC_SYS_STATUS_SW_INUSE == sys_status)
   {
#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif

      SW_DECODE_CHECK_ABORT(handle, pCheckAbort);

      srcMcuCount = jpeg_drv_dec_get_mcu_h_limit();
      hwDecodeMcuCount[0] = handle->hwDecodeMcuCount[0];
      hwDecodeMcuCount[1] = handle->hwDecodeMcuCount[1];
      
      // accumulate mcu h total count
      hwDecodeMcuCount[0] += srcMcuCount;
      if (hwDecodeMcuCount[0] == frameInfo->mcuPerRow)
      {
         hwDecodeMcuCount[0] = 0; 
         hwDecodeMcuCount[1]++;
      }
      else if (hwDecodeMcuCount[0] > frameInfo->mcuPerRow)
      {
         ASSERT(0);
      }
      
      // trigger next hw decode
      if (hwDecodeMcuCount[1] <= (frameInfo->mcuPerColumn - 1))
      {
         if ((srcMcuCount + hwDecodeMcuCount[0]) > frameInfo->mcuPerRow)
         {
            srcMcuCount = frameInfo->mcuPerRow - hwDecodeMcuCount[0];
         }
         else
         {
            srcMcuCount = handle->hwMcuPrevHLimit;
         }
   
         // update hw mcu h limit
         if (0 == handle->hwDecodeSysBufferFlag)
         {
            jpeg_drv_dec_set_sys_buffer((kal_uint32)handle->hwDecodeSysBufferAddr2[0], (kal_uint32)handle->hwDecodeSysBufferAddr2[1], (kal_uint32)handle->hwDecodeSysBufferAddr2[2]);
            jpeg_drv_dec_set_mcu_h_limit(srcMcuCount);
         }
         else
         {
            jpeg_drv_dec_set_sys_buffer((kal_uint32)handle->hwDecodeSysBufferAddr[0], (kal_uint32)handle->hwDecodeSysBufferAddr[1], (kal_uint32)handle->hwDecodeSysBufferAddr[2]);
            jpeg_drv_dec_set_mcu_h_limit(srcMcuCount);
         }
         
         // set sysram hw in use      
         jpeg_drv_dec_set_sys_status(JPEG_DRV_DEC_SYS_STATUS_HW_INUSE);

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif
      }

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
      i = frameInfo->numberOfComponents;
      if (0 == handle->hwDecodeSysBufferFlag)
      {
         while (--i >= 0)
         {
            if (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->hwDecodeSysBufferAddr[i], handle->hwDecodeSysBufferSize[i]))
            {
               if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr[i]))) &&
                   (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferSize[i])) &&
                   (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr[i]), handle->hwDecodeSysBufferSize[i])))
               {
                  dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr[i]), handle->hwDecodeSysBufferSize[i], PAGE_CACHEABLE);
                  enableDynamicSwitch[i] = KAL_TRUE;
               }
               else
               {
                  ASSERT(0);
               }
            }
         }
      }
      else
      {
         while (--i >= 0)
         {
            if (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->hwDecodeSysBufferAddr2[i], handle->hwDecodeSysBufferSize[i]))
            {
               if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr2[i]))) &&
                   (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferSize[i])) &&
                   (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr2[i]), handle->hwDecodeSysBufferSize[i])))
               {
                  dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr2[i]), handle->hwDecodeSysBufferSize[i], PAGE_CACHEABLE);
                  enableDynamicSwitch[i] = KAL_TRUE;
               }
               else
               {
                  ASSERT(0);
               }
            }
         }
      }
#endif

      // copy data to decode buffer
      srcResizeFactor = handle->hwBrzFactor;

      srcSampleFactorH[0] = frameInfo->frameComponentInfo[0].hSamplingFactor;
      srcSampleFactorH[1] = frameInfo->frameComponentInfo[1].hSamplingFactor;
      srcSampleFactorH[2] = frameInfo->frameComponentInfo[2].hSamplingFactor;

      srcSampleFactorV[0] = frameInfo->frameComponentInfo[0].vSamplingFactor;
      srcSampleFactorV[1] = frameInfo->frameComponentInfo[1].vSamplingFactor;
      srcSampleFactorV[2] = frameInfo->frameComponentInfo[2].vSamplingFactor;

      // pass to fragment processor
      {
         kal_int32                  fragStartX;
         kal_int32                  fragStartY;
         kal_int32                  fragWidth;
         kal_int32                  fragHeight;
         kal_int32                  MCUStartX;
         kal_int32                  MCUStartY;
         kal_int32                  MCUWidth;
         kal_int32                  MCUHeight;
         kal_bool                   discard;
         FRAG_PROCESSOR_STATUS_ENUM fragStatus = FRAG_PROCESSOR_STATUS_RETURN_SUCCESS;
         SWJD_FRAGMENT_PROCESSOR    *pFragProcessor = handle->pFragProcessor;
      

         // This is the temporary version for querying frag window during decoding.
         // There are still some dummy function calls wtih discard set to true.
         // But the MCU needed to bypassed equals to 0 and finally we bypassed no MCU.
         fragProcessorGetFragWindow(handle->pFragProcessor,
                                    &MCUStartX,
                                    &MCUStartY,
                                    &MCUWidth,
                                    &MCUHeight,
                                    &discard);     // KAL_TRUE if we don't need the trailing MCU data of this row

         // vertical start check
         if ((handle->hwDecodeMcuCount[1] >= MCUStartY) && (0 != MCUHeight))
         {
            // vertical end check
            if ((handle->hwDecodeMcuCount[1] + 1) >= MCUStartY)
            {
               // horizontal start check
               if (handle->hwDecodeMcuCount[0] > MCUStartX)
               {
                  ASSERT(0);
               }

               // horizontal end check
               if (0 == handle->hwDecodeSysBufferFlag)
               {
                  if ((handle->hwDecodeMcuCount[0] + handle->hwMcuHLimit) >= MCUStartX)
                  {
                     MCUStartX = MCUStartX - handle->hwDecodeMcuCount[0];
                     MCUWidth  = handle->hwMcuHLimit - MCUStartX;
                     MCUHeight = 1;
   
                     // set fragment buffer address
                     fragProcessorSetFragBuffer(handle->pFragProcessor,
                                                (kal_uint8*)handle->hwDecodeSysBufferAddr[0],
                                                (kal_uint8*)handle->hwDecodeSysBufferAddr[1],
                                                (kal_uint8*)handle->hwDecodeSysBufferAddr[2],
                                                pFragProcessor->fragBufWidth,
                                                pFragProcessor->fragBufHeight,
                                                pFragProcessor->fragBufPitch);
   
#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif
                     // Processing the fragment data by fragment processor
                     fragStatus = fragProcessorProcessData(handle->pFragProcessor,
                                                           MCUStartX,
                                                           MCUWidth,
                                                           MCUHeight);
#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif
                  }
               }
               else
               {
                  if ((handle->hwDecodeMcuCount[0] + handle->hwMcuHLimit2) >= MCUStartX)
                  {
                     MCUStartX = MCUStartX - handle->hwDecodeMcuCount[0];
                     MCUWidth  = handle->hwMcuHLimit2 - MCUStartX;
                     MCUHeight = 1;
   
                     // set fragment buffer address
                     fragProcessorSetFragBuffer(handle->pFragProcessor,
                                                (kal_uint8*)handle->hwDecodeSysBufferAddr2[0],
                                                (kal_uint8*)handle->hwDecodeSysBufferAddr2[1],
                                                (kal_uint8*)handle->hwDecodeSysBufferAddr2[2],
                                                pFragProcessor->fragBufWidth,
                                                pFragProcessor->fragBufHeight,
                                                pFragProcessor->fragBufPitch);
   
#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif
                     // Processing the fragment data by fragment processor
                     fragStatus = fragProcessorProcessData(handle->pFragProcessor,
                                                           MCUStartX,
                                                           MCUWidth,
                                                           MCUHeight);

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif
                  }
               }
            }
         }
         if (fragStatus < 0)
         {
            handle->codecState = JPEG_CODEC_STATE_ERROR;
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_GENERAL_ERROR;
            return handle->lastStatus;
         }
      }

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
      i = frameInfo->numberOfComponents;
      if (0 == handle->hwDecodeSysBufferFlag)
      {
         while (--i >= 0)
         {
            if ((KAL_TRUE == enableDynamicSwitch[i]) &&
                (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr[i]))) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferSize[i])) &&
                (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr[i]), handle->hwDecodeSysBufferSize[i])))
            {
               if(KAL_TRUE == INT_QueryIsCachedRAM(handle->hwDecodeSysBufferAddr[i], handle->hwDecodeSysBufferSize[i]))
               {
                  dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr[i]), handle->hwDecodeSysBufferSize[i], PAGE_NO_CACHE);
                  enableDynamicSwitch[i] = KAL_FALSE;
               }
               else
               {
                  ASSERT(0);
               }
            }
         }
      }
      else
      {
         while (--i >= 0)
         {
            if ((KAL_TRUE == enableDynamicSwitch[i]) &&
                (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr2[i]))) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferSize[i])) &&
                (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr2[i]), handle->hwDecodeSysBufferSize[i])))
            {
               if(KAL_TRUE == INT_QueryIsCachedRAM(handle->hwDecodeSysBufferAddr2[i], handle->hwDecodeSysBufferSize[i]))
               {
                  dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr2[i]), handle->hwDecodeSysBufferSize[i], PAGE_NO_CACHE);
                  enableDynamicSwitch[i] = KAL_FALSE;
               }
               else
               {
                  ASSERT(0);
               }
            }
         }
      }
#endif

      // update sw mcu h limit
      if (0 == handle->hwDecodeSysBufferFlag)
      {
         handle->hwMcuHLimit2 = srcMcuCount;
         handle->hwDecodeSysBufferFlag = 1;
      }
      else
      {
         handle->hwMcuHLimit = srcMcuCount;
         handle->hwDecodeSysBufferFlag = 0;
      }
   
      // update decoded mcu count
      handle->hwDecodeMcuCount[0] = hwDecodeMcuCount[0];
      handle->hwDecodeMcuCount[1] = hwDecodeMcuCount[1];
   }

   return JPEG_STATUS_OK;
}
#endif



void * jpeg_dec_hw_lock_handle(void)
{
   kal_uint32 irq_mask;
   JPEG_CODEC_STATE_ENUM* hw_decoder_state_p = &(_jpeg_hw_decoder.codecState);
   JPEG_CODEC_STATE_ENUM hw_decoder_state;

   irq_mask = SaveAndSetIRQMask();
   hw_decoder_state = *hw_decoder_state_p;
   RestoreIRQMask(irq_mask);

   if (JPEG_CODEC_STATE_FREE != hw_decoder_state)
   {
      return NULL;
   }

   irq_mask = SaveAndSetIRQMask();
   *hw_decoder_state_p = JPEG_CODEC_STATE_IDLE;
   RestoreIRQMask(irq_mask);

   return &_jpeg_hw_decoder;
}



void * jpeg_dec_hw_get_handle(void)
{
   return &_jpeg_hw_decoder;
}



/// This function will also set up the file buffer address and the file breakpoint for HW decoder.
JPEG_STATUS_ENUM jpeg_dec_hw_read_data(JPEG_DECODER_HANDLE handle)
{
   JPEG_FILE_INFO *fileInfo = &(handle->fileInfo);

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif

   if (JPEG_CODEC_TYPE_HW != handle->codecType)
   {
      handle->lastStatus = JPEG_STATUS_INVALID_OPERATION;
      ASSERT(0);
   }
   else
   {
      kal_uint8 *dataPtr = NULL;

      if (!IS_HUFFMAN_TABLE_READY(handle->tableReadyFlag) && !IS_HUFFMAN_TABLE_READY(handle->tableLoadFlag))
      {
         dataPtr = (kal_uint8*)swjd_huff_bits_table;
         
         jpeg_drv_dec_set_file_buffer(dataPtr, SWJD_HUFF_HUFF_BITS_BITS);

         SET_DC_HUFFMAN_TABLE_READY(handle->tableLoadFlag, 0);
         SET_DC_HUFFMAN_TABLE_READY(handle->tableLoadFlag, 1);
         SET_AC_HUFFMAN_TABLE_READY(handle->tableLoadFlag, 0);
         SET_AC_HUFFMAN_TABLE_READY(handle->tableLoadFlag, 1);
      }
      else
      {
         if (handle->fileIsInMemory)
         {
            dataPtr = FSAL_GetRamFilePointer(fileInfo->fileHandle);
            dataPtr += fileInfo->offsetTableMisc;
   
            /// To prevent the DMA from prefetch.
            jpeg_drv_dec_set_file_buffer(dataPtr, fileInfo->realSize + fileInfo->realOffset - fileInfo->offsetTableMisc + 16);
   
            handle->lastStatus = JPEG_STATUS_OK;
         }
         else
         {
            STFSAL *fsal = fileInfo->fileHandle;
            RS_BUFFER *rsb = &(handle->rsBuffer);
            kal_uint8 *dataPtr;
            kal_uint32 count;
            kal_uint32 dataRead;
            FSAL_Status fsalStatus;
   
            rsbGetReadPointer(rsb, (void **)&dataPtr);
            dataRead = (kal_uint32)jpeg_drv_dec_get_current_file_addr() - (kal_uint32)dataPtr;
            rsbAdjustReadPointer(rsb, dataRead);
            rsbRearrangeBuffer(rsb);
            rsbGetWritePointer(rsb, (void **)&dataPtr);
            count = rsbGetSpaceAvailable(rsb);
   
            handle->lastStatus = JPEG_STATUS_OK;
            fsalStatus = FSAL_Read(fsal, dataPtr, count);
   
            if (FSAL_OK != fsalStatus)
            {
               if (FSAL_READ_OVER_EOF == fsalStatus || FSAL_SEEK_OVER_EOF == fsalStatus)
               {
                  /// EOF encountered.
                  count = FSAL_GetLastReadCount(fsal);
                  rsbAdjustWritePointer(rsb, count);
                  rsbGetReadPointer(rsb, (void **)&dataPtr);
                  count = rsbGetDataAvailable(rsb);
   
                  if (rsbGetBufferSize(rsb) - count > 32)
                  {
                     /// To prevent the DMA from prefetch.
                     jpeg_drv_dec_set_file_buffer(dataPtr, count + 32);
                  }
                  else
                  {
                     jpeg_drv_dec_set_file_buffer(dataPtr, rsbGetBufferSize(rsb));
                  }
               }
               else
               {
                  handle->lastStatus = JPEG_STATUS_DEC_ERROR_READ_ERROR;
               }
            }
            else
            {
               /// In this case, the buffer is re-filled.
               rsbAdjustWritePointer(rsb, count);
               rsbGetReadPointer(rsb, (void **)&dataPtr);
               jpeg_drv_dec_set_file_buffer(dataPtr, rsbGetBufferSize(rsb));
            }
         }
      }
   }

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif

   return handle->lastStatus;
}



/// This function will be called by JPEG driver in JPEG encode HISR.
static kal_int32 _jpeg_dec_hw_hisr_callback(JPEG_CODEC_STATE_ENUM state)
{
   if (JPEG_CODEC_STATE_COMPLETE == _jpeg_hw_decoder.codecState)
   {
      /// In this case, IDP completes before HW JPEG decoder.
      /// It indeed may happen for some file!
      return 1;
   }
   else
   {
      if (drv_gfx_check_dct_preemption(DCT_USER_JPEG_DECODER))
      {
         state = JPEG_CODEC_STATE_ERROR;
      }

      _jpeg_hw_decoder.codecState = state;

      switch (state)
      {
      case JPEG_CODEC_STATE_EOF:
         _jpeg_hw_decoder.hwProgressiveDecodeLeft--;
   
         if (0 == _jpeg_hw_decoder.hwProgressiveDecodeLeft)
         {
            kal_uint32 decoded_mcu_count = jpeg_drv_dec_get_decoded_mcu_count();
            kal_uint32 total_mcu_count = jpeg_drv_dec_get_total_mcu_count();

            if (total_mcu_count != decoded_mcu_count)
            {
               /// Woops, something wrong. Set the state as JPEG_CODEC_STATE_ERROR for error handling.
               state = JPEG_CODEC_STATE_ERROR;
               _jpeg_hw_decoder.codecState = JPEG_CODEC_STATE_ERROR;
               _jpeg_hw_decoder.lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            }
            else
            {
               /// In this case, IDP may be still busy.
               /// We should wait for another JPEG_CODEC_STATE_COMPLETE and then invoke the callback function.
               /// Change the _jpeg_hw_encoder.codecState to be JPEG_CODEC_STATE_BUSY since IDP is still busy.
               _jpeg_hw_decoder.codecState = JPEG_CODEC_STATE_BUSY;
               return 1;
            }
         }
         else
         {
            ASSERT(JPEG_ENCODE_PROCESS_PROGRESSIVE == _jpeg_hw_decoder.fileInfo.frameInfo.encProcess);
   
            state = JPEG_CODEC_STATE_PAUSED;
            _jpeg_hw_decoder.codecState = JPEG_CODEC_STATE_PAUSED;
            _jpeg_hw_decoder.hwProgressiveDecodeLeft |= JPEG_DEC_PROG_ITERATION_COMPLETE_BIT;
         }
         break;
   
      case JPEG_CODEC_STATE_COMPLETE:
         /// IDP has stopped, now we can invoke the decode complete callback.
         break;
   
      case JPEG_CODEC_STATE_PAUSED:
         {
            kal_uint8 *dataPtr;

            if (_jpeg_hw_decoder.fileIsInMemory)
            {
               JPEG_FILE_INFO *fileInfo = &(_jpeg_hw_decoder.fileInfo);
               dataPtr = FSAL_GetRamFilePointer(fileInfo->fileHandle);
               dataPtr += fileInfo->offsetTableMisc;
            }
            else
            {
               /// Get the input buffer address.
               rsbGetReadPointer(&(_jpeg_hw_decoder.rsBuffer), (void **)&dataPtr);
            }
            _jpeg_hw_decoder.dataLeft -= ((kal_uint32)jpeg_drv_dec_get_current_file_addr() - (kal_uint32)dataPtr);

            /// If there's no data left to decode but the EOI is not encountered, this file is a corrupt one.
            if (_jpeg_hw_decoder.dataLeft <= 0)
            {
               state = JPEG_CODEC_STATE_ERROR;
               _jpeg_hw_decoder.codecState = JPEG_CODEC_STATE_ERROR;
               _jpeg_hw_decoder.lastStatus = JPEG_STATUS_DEC_ERROR_CORRUPT_FILE;
            }
         }
         break;
   
      case JPEG_CODEC_STATE_ERROR:
         break;
   
      default:
         ASSERT(0);
         return 0;
      }

      if (JPEG_CODEC_STATE_ERROR == state)
      {
         kal_uint32 decoded_mcu_count = jpeg_drv_dec_get_decoded_mcu_count();
         kal_uint32 total_mcu_count = jpeg_drv_dec_get_total_mcu_count();

         /// If the number of decoded MCUs >= 0.75 * total number of MCUs, 
         /// set the result as complete.
         if (decoded_mcu_count >= ((total_mcu_count * 3) >> 2))
         {
            state = JPEG_CODEC_STATE_COMPLETE;
         }
      }

#if (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__))
      if (_jpeg_hw_decoder.callback_function)
      {
         return _jpeg_hw_decoder.callback_function(state);
      }
#endif
   }
   return 1;
}



void jpeg_dec_hw_config_decoder(JPEG_DECODER_HANDLE handle)
{
   kal_uint32 huffTableOffset = 0;
   JPEG_FILE_INFO *fileInfo = &(handle->fileInfo);
   JPEG_FRAME_INFO *frameInfo = &(fileInfo->frameInfo);

   ASSERT(JPEG_CODEC_TYPE_HW == handle->codecType);

   /// 1. Reset JPEG decoder.
   jpeg_drv_dec_reset();

   /// 2. Set up callback function.
   jpeg_isr_set_dec_callback(_jpeg_dec_hw_hisr_callback);

   /// 3. Set up JPEG file size.
   // no huffman table -> load a default table
   if (!IS_HUFFMAN_TABLE_READY(handle->tableReadyFlag))
   {
      huffTableOffset = SWJD_HUFF_HUFF_BITS_BITS;
   }
   jpeg_drv_dec_set_file_size(fileInfo->realSize - (fileInfo->offsetTableMisc - fileInfo->realOffset) + huffTableOffset);

   /// 4. Set up JPEG decoding table address.
   jpeg_drv_dec_set_table_address(handle->hwDecodeTableAddr);

   /// 5. Set up sampling factor related attributes.
   ///    Including REG_JPEG_DEC_SAMP_FACTOR register and REG_JPEG_DEC_CTRL register.
   jpeg_drv_dec_set_sampling_factor_related(frameInfo->numberOfComponents,
                                            frameInfo->frameComponentInfo[0].hSamplingFactor, frameInfo->frameComponentInfo[0].vSamplingFactor,
                                            frameInfo->frameComponentInfo[1].hSamplingFactor, frameInfo->frameComponentInfo[1].vSamplingFactor,
                                            frameInfo->frameComponentInfo[2].hSamplingFactor, frameInfo->frameComponentInfo[2].vSamplingFactor);

   /// 6. Set up component ID.
   jpeg_drv_dec_set_component_id(frameInfo->frameComponentInfo[0].componentID,
                                 frameInfo->frameComponentInfo[1].componentID,
                                 frameInfo->frameComponentInfo[2].componentID);

   /// 7. Set up quantization table ID.
   jpeg_drv_dec_set_q_table_id(frameInfo->frameComponentInfo[0].qTableSelector,
                               frameInfo->frameComponentInfo[1].qTableSelector,
                               frameInfo->frameComponentInfo[2].qTableSelector);


   /// 8. Set up total MCU number.
   jpeg_drv_dec_set_total_mcu(frameInfo->mcuPerRow * frameInfo->mcuPerColumn);

   /// 9. Set up progressive-related register.
   if (JPEG_ENCODE_PROCESS_PROGRESSIVE == frameInfo->encProcess)
   {
      kal_int32 i = 0;
      kal_int32 StepMCU, StepDU[3];
      kal_uint32 MCURun;

      jpeg_drv_dec_set_progressive(1);
      jpeg_drv_dec_set_mcu_per_row(frameInfo->mcuPerRow);
      jpeg_drv_dec_set_prog_buffer(handle->hwProgCoefBufferAddr);

      if (handle->hwInterleaveStepMCU >= frameInfo->mcuPerRow)
      {
         // handle height boundary
         if ((frameInfo->mcuPerRow * frameInfo->mcuPerColumn) < (handle->hwInterleaveStartMCU + handle->hwInterleaveStepMCU))
        	{
        	   StepMCU = (frameInfo->mcuPerRow * frameInfo->mcuPerColumn) - handle->hwInterleaveStartMCU;
        	}
         else
        	{
        	   StepMCU = handle->hwInterleaveStepMCU;
        	}
      }
      else
      {
         // handle width boundary
         if ((handle->hwInterleaveStartMCU / frameInfo->mcuPerRow) != ((handle->hwInterleaveStartMCU + handle->hwInterleaveStepMCU - 1) / frameInfo->mcuPerRow))
        	{
        	   StepMCU = ((handle->hwInterleaveStartMCU / frameInfo->mcuPerRow + 1) * frameInfo->mcuPerRow) - handle->hwInterleaveStartMCU;
        	}
         else
        	{
        	   StepMCU = handle->hwInterleaveStepMCU;
        	}
      }

      jpeg_drv_dec_set_prog_intlv_mcu_start_end(handle->hwInterleaveStartMCU, handle->hwInterleaveStartMCU + StepMCU - 1);
      handle->hwInterleaveStartMCU += StepMCU;

      i = frameInfo->numberOfComponents;
      MCURun = StepMCU / frameInfo->mcuPerRow;
      while (--i >= 0)
      {
         StepDU[i] = (StepMCU * frameInfo->frameComponentInfo[i].hSamplingFactor * frameInfo->frameComponentInfo[i].vSamplingFactor)
                          - (MCURun * handle->hwDummyDU[i] * frameInfo->frameComponentInfo[i].vSamplingFactor);

         jpeg_drv_dec_set_prog_non_intlv_du_start_end(i, handle->hwNonInterleaveStartDU[i], handle->hwNonInterleaveStartDU[i] + StepDU[i] - 1);
         handle->hwNonInterleaveStartDU[i] += StepDU[i];
      }
   }
   else
   {
      /// Baseline JPEG.
      jpeg_drv_dec_set_progressive(0);
   }

   /// 10. Set up du number.
   {
      kal_int32 i = frameInfo->numberOfComponents;
      while (--i >= 0)
      {
         jpeg_drv_dec_set_du(i, handle->hwTotalDU[i], handle->hwDummyDU[i], handle->hwDUPerMCURow[i]);
      }
   }

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)
   {
      kal_int32 i;
      kal_uint32 brz_factor[2] = {0, 0};
      kal_uint32 src_width = frameInfo->width;
      kal_uint32 src_height = frameInfo->height;
      kal_uint32 des_width = handle->outputWnd.w;
      kal_uint32 des_height = handle->outputWnd.h;
      kal_uint32 hwMcuHLimit, hwTotalDu = 0;

      // decide brz factor
      while ((des_width <= src_width) && (brz_factor[0] < 3))
      {
         src_width >>= 1;
         brz_factor[0]++;
      }
      if (0 < brz_factor[0])
      {
         brz_factor[0]--;
      }
      while ((des_height <= src_height) && (brz_factor[1] < 3))
      {
         src_height >>= 1;
         brz_factor[1]++;
      }
      if (0 < brz_factor[1])
      {
         brz_factor[1]--;
      }
      handle->hwBrzFactor = (brz_factor[0] > brz_factor[1])?brz_factor[1]:brz_factor[0];

      // decide mcu h limit
      i = frameInfo->numberOfComponents;
      while (--i >= 0)
      {
         hwTotalDu += (frameInfo->frameComponentInfo[i].hSamplingFactor * frameInfo->frameComponentInfo[i].vSamplingFactor);
      }

      hwMcuHLimit = (((handle->hwDecodeSysBufferTotalSize - 32 * 3) >> 6) / hwTotalDu) << (handle->hwBrzFactor << 1);
      if (hwMcuHLimit <= frameInfo->mcuPerRow)
      {
         handle->hwMcuHLimit = hwMcuHLimit;
      }
      else
      {
         handle->hwMcuHLimit = frameInfo->mcuPerRow;
      }

      handle->hwMcuPrevHLimit = handle->hwMcuHLimit;
      handle->hwMcuHLimit2 = handle->hwMcuHLimit;

      // decide decode sysram pitch and buffer
      i = frameInfo->numberOfComponents;
      for (i=0; i<frameInfo->numberOfComponents; i++)
      {
         handle->hwDecodeSysPitch[i] = ((handle->hwMcuHLimit << 3) >> handle->hwBrzFactor) * frameInfo->frameComponentInfo[i].hSamplingFactor;
         handle->hwDecodeSysBufferSize[i] = ((handle->hwMcuHLimit << 6) >> (handle->hwBrzFactor << 1)) 
                                                               * frameInfo->frameComponentInfo[i].hSamplingFactor * frameInfo->frameComponentInfo[i].vSamplingFactor;
         handle->hwDecodeSysBufferSize[i] = (handle->hwDecodeSysBufferSize[i] + 31) & (~31);  // 32 byte alignment

         if (i > 0)
         {
            handle->hwDecodeSysBufferAddr[i] = handle->hwDecodeSysBufferAddr[i-1] + handle->hwDecodeSysBufferSize[i-1];
            handle->hwDecodeSysBufferAddr2[i] = handle->hwDecodeSysBufferAddr2[i-1] + handle->hwDecodeSysBufferSize[i-1];
         }
      }
  
      // reset double buffer flag
      handle->hwDecodeSysBufferFlag = 0;
  
      /// 11. Set up sysram buffer
      jpeg_drv_dec_set_sys_buffer((kal_uint32)handle->hwDecodeSysBufferAddr[0], (kal_uint32)handle->hwDecodeSysBufferAddr[1], (kal_uint32)handle->hwDecodeSysBufferAddr[2]);

      // 12. Set mcu h limit
      jpeg_drv_dec_set_mcu_h_limit(handle->hwMcuHLimit);

      // 13. Set sys pitch
      jpeg_drv_dec_set_sys_pitch(handle->hwDecodeSysPitch[0], handle->hwDecodeSysPitch[1], handle->hwDecodeSysPitch[2]);

      // 14. Set resize factor
      jpeg_drv_dec_set_resize_factor(handle->hwBrzFactor);

      // 15. Set sysram hw in use      
      jpeg_drv_dec_set_sys_status(JPEG_DRV_DEC_SYS_STATUS_HW_INUSE);
   }
#endif
}



JPEG_STATUS_ENUM jpeg_dec_hw_internal(JPEG_DECODER_HANDLE handle)
{
   JPEG_FILE_INFO *fileInfo = &(handle->fileInfo);
   JPEG_FRAME_INFO *frameInfo = &(fileInfo->frameInfo);
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   kal_bool enableDynamicSwitch[3] = {KAL_FALSE, KAL_FALSE, KAL_FALSE};
   kal_uint32 hwDecodeSysBufferTotalSize;
#endif
   
   {
      kal_uint32 crzSrcWidth = frameInfo->paddedWidth;
      kal_uint32 crzSrcHeight = frameInfo->paddedHeight;

      handle->paddedOutputWnd.x = handle->outputWnd.x;
      handle->paddedOutputWnd.y = handle->outputWnd.y;

      /// Use rounding when calculating the paddedOutputWnd.w / h.
      handle->paddedOutputWnd.w = (handle->outputWnd.w * frameInfo->paddedWidth  + (frameInfo->width  >> 1)) / frameInfo->width;
      handle->paddedOutputWnd.h = (handle->outputWnd.h * frameInfo->paddedHeight + (frameInfo->height >> 1)) / frameInfo->height;

      /// Adjust the output window according to the limitation of IDP resizer.
      /// It's very very tricky and non-sense.
      /// We just try to adjust the setting to make IDP resizer works for some aspect ratio, such as 10240 x 1.
      while (crzSrcWidth > 4095 || crzSrcHeight > 4095)
      {
         crzSrcWidth >>= 1;
         crzSrcHeight >>= 1;
      }

      if (0 == crzSrcWidth)
      {
         crzSrcWidth = 1;
      }

      if (0 == crzSrcHeight)
      {
         crzSrcHeight = 1;
      }

      /// Downscaling in x direction.
      if (handle->outputWnd.w <= frameInfo->width)
      {
         /// But CRZ must perform upscaling.
         if (handle->paddedOutputWnd.w > crzSrcWidth && crzSrcWidth < 3)
         {
            handle->paddedOutputWnd.w = crzSrcWidth;
         }

         if (handle->paddedOutputWnd.w != crzSrcWidth && 2 > handle->paddedOutputWnd.w)
         {
            handle->paddedOutputWnd.w = 2;
         }
      }

      /// Downscaling in y direction.
      if (handle->outputWnd.h <= frameInfo->height)
      {
         /// But CRZ must perform upscaling.
         if (handle->paddedOutputWnd.h > crzSrcHeight && crzSrcHeight < 3)
         {
            handle->paddedOutputWnd.h = crzSrcHeight;
         }

         if (handle->paddedOutputWnd.h != crzSrcHeight && 2 > handle->paddedOutputWnd.h)
         {
            handle->paddedOutputWnd.h = 2;
         }
      }
   }

   if (JPEG_PARSE_STATE_COMPLETE != fileInfo->parseState)
   {
      handle->lastStatus = JPEG_STATUS_DEC_ERROR_INVALID_FILE;
      return handle->lastStatus;
   }

   /// Set up progressive-related attributes.
   if (JPEG_ENCODE_PROCESS_PROGRESSIVE != frameInfo->encProcess)
   {
      handle->hwProgressiveDecodeLeft = 1;
   }
   else
   {
      kal_int32 i = 0;

      /// Now we can assign the progressive coefficient buffer according to the YUV sampling format.
      jpeg_drv_dec_calc_prog_buffer(frameInfo->numberOfComponents,
                                    frameInfo->frameComponentInfo[0].hSamplingFactor, frameInfo->frameComponentInfo[0].vSamplingFactor,
                                    frameInfo->frameComponentInfo[1].hSamplingFactor, frameInfo->frameComponentInfo[1].vSamplingFactor,
                                    frameInfo->frameComponentInfo[2].hSamplingFactor, frameInfo->frameComponentInfo[2].vSamplingFactor,
                                    handle->hwProgCoefBufferAddr[0],
                                    handle->hwProgCoefBufferSize[0],
                                    handle->hwProgCoefBufferAddr,
                                    handle->hwProgCoefBufferSize);

      /// Calculate the hwInterleaveStepMCU and hwNonInterleaveStepDU.
      {
         kal_uint32 mcus_per_run = (handle->hwProgCoefBufferSize[0] >> 6) / (frameInfo->hSamplingFactorMax * frameInfo->vSamplingFactorMax) / 2;
         kal_uint32 rows_per_run, runs_per_row;
         kal_uint32 runs_per_column;

         // decide runs per row and column
         if (mcus_per_run >= frameInfo->mcuPerRow)
        	{
        	   rows_per_run = mcus_per_run / frameInfo->mcuPerRow;
        	   runs_per_row = (frameInfo->mcuPerRow == mcus_per_run)?1:0;
        	   runs_per_column = (frameInfo->mcuPerColumn + rows_per_run - 1) / rows_per_run;

        	   handle->hwProgressiveDecodeLeft = runs_per_column;
            handle->hwInterleaveStartMCU = 0;
            handle->hwInterleaveStepMCU = rows_per_run * frameInfo->mcuPerRow;
        	}
         else
        	{
        	   rows_per_run = 0;
        	   runs_per_row = (frameInfo->mcuPerRow + mcus_per_run - 1) / mcus_per_run;
        	   runs_per_column = frameInfo->mcuPerColumn;

        	   handle->hwProgressiveDecodeLeft = runs_per_row * runs_per_column;
            handle->hwInterleaveStartMCU = 0;
            handle->hwInterleaveStepMCU = mcus_per_run;
        	}

         i = frameInfo->numberOfComponents;
         while (--i >= 0)
         {
            handle->hwNonInterleaveStartDU[i] = 0;
            handle->hwNonInterleaveStepDU[i] = handle->hwInterleaveStepMCU * 
            	   frameInfo->frameComponentInfo[i].hSamplingFactor * frameInfo->frameComponentInfo[i].vSamplingFactor;
         }
      }
   }

   /// Power on JPEG decoder.
   jpeg_drv_dec_power_on();

   /// Config JPEG HW decoder.
   jpeg_dec_hw_config_decoder(handle);

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)
   {
      kal_int32 i = 0;
      kal_int32 canvasPitch;
      kal_int32 HSampling[3], VSampling[3];
      FRAG_PROCESSOR_COLOR_ENUM canvasFormat;
   
      kal_int32 fragWidth, fragHeight;
      kal_int32 fragPitch;
   
      fragProcessorSetRotation(handle->pFragProcessor, FRAG_PROCESSOR_TRANSFORM_NO_FLIP_ROTATE_CW_0);
   
      fragWidth = ((handle->hwMcuHLimit << 3) >> handle->hwBrzFactor) * frameInfo->hSamplingFactorMax;
      fragHeight = ((1 << 3) >> handle->hwBrzFactor) * frameInfo->vSamplingFactorMax;
      fragPitch = fragWidth;

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
      i = frameInfo->numberOfComponents;
      while (--i >= 0)
      {
         if (KAL_TRUE == INT_QueryIsNonCachedRAM(handle->hwDecodeSysBufferAddr[i], handle->hwDecodeSysBufferSize[i]))
         {
            if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr[i]))) &&
                (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferSize[i])) &&
                (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr[i]), handle->hwDecodeSysBufferSize[i])))
            {
               dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr[i]), handle->hwDecodeSysBufferSize[i], PAGE_CACHEABLE);
               enableDynamicSwitch[i] = KAL_TRUE;
            }
            else
            {
               ASSERT(0);
            }
         }
      }
#endif

      fragProcessorSetFragBuffer(handle->pFragProcessor,
                                 (kal_uint8*)handle->hwDecodeSysBufferAddr[0],
                                 (kal_uint8*)handle->hwDecodeSysBufferAddr[1],
                                 (kal_uint8*)handle->hwDecodeSysBufferAddr[2],
                                 fragWidth,
                                 fragHeight,
                                 fragPitch);
   
      /// Initialize the sampling factor
      for (i = frameInfo->numberOfComponents; --i >= 0; )
      {
         HSampling[i] = frameInfo->frameComponentInfo[i].hSamplingFactor;
         VSampling[i] = frameInfo->frameComponentInfo[i].vSamplingFactor;
      }

      fragProcessorSetComponentInfo(handle->pFragProcessor,
                                    frameInfo->numberOfComponents,
                                    HSampling,
                                    VSampling);
   
      /// 2. Update MCU dimension after DCT scaling.
      handle->mcuWidthBits  = jpeg_dec_sw_get_mcu_size_bits(frameInfo->hSamplingFactorMax) - handle->hwBrzFactor;
      handle->mcuHeightBits = jpeg_dec_sw_get_mcu_size_bits(frameInfo->vSamplingFactorMax) - handle->hwBrzFactor;
   
      // Set fragment processor scale ratio
      fragProcessorSetScaleInfo(handle->pFragProcessor,
                                      handle->mcuWidthBits,
                                      handle->mcuHeightBits,
                                      frameInfo->width  >> handle->hwBrzFactor,
                                      frameInfo->height >> handle->hwBrzFactor,
                                      handle->outputWnd.w,
                                      handle->outputWnd.h);
   
      switch (handle->canvasFormat)
      {
         case JPEG_RGB_FORMAT_RGB565:
            canvasFormat = FRAG_PROCESSOR_COLOR_FORMAT_RGB565;
            canvasPitch  = handle->canvasWnd.w * 2;
            break;
   
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
      fragProcessorSetCanvasBuffer(handle->pFragProcessor,
                                   canvasFormat,
                                   handle->canvasBuffer[0],
                                   handle->canvasBuffer[1],
                                   handle->canvasBuffer[2],
                                   handle->canvasWnd.w,
                                   handle->canvasWnd.h,
                                   canvasPitch);
   
      // Set the X and Y coordinates for rendering the decoded image
      fragProcessorSetOutputOffset(handle->pFragProcessor,
                                   handle->outputWnd.x,
                                   handle->outputWnd.y);
   
      // Set target clip window for rendering the decoded image
      fragProcessorSetTargetWindow(handle->pFragProcessor,
                                   handle->targetClipWnd.x + handle->outputWnd.x,
                                   handle->targetClipWnd.y + handle->outputWnd.y,
                                   handle->targetClipWnd.w,
                                   handle->targetClipWnd.h);

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
      i = frameInfo->numberOfComponents;
      while (--i >= 0)
      {
         if ((KAL_TRUE == enableDynamicSwitch[i]) &&
             (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(handle->hwDecodeSysBufferAddr[i]))) &&
             (IS_CACHE_LINE_SIZE_ALIGNED(handle->hwDecodeSysBufferSize[i])) &&
             (is_predef_dyna_c_region((kal_uint32)(handle->hwDecodeSysBufferAddr[i]), handle->hwDecodeSysBufferSize[i])))
         {
            if(KAL_TRUE == INT_QueryIsCachedRAM(handle->hwDecodeSysBufferAddr[i], handle->hwDecodeSysBufferSize[i]))
            {
               dynamic_switch_cacheable_region((void*)&(handle->hwDecodeSysBufferAddr[i]), handle->hwDecodeSysBufferSize[i], PAGE_NO_CACHE);
               enableDynamicSwitch[i] = KAL_FALSE;
            }
            else
            {
               ASSERT(0);
            }
         }
      }
#endif
   }
#endif

   /// Read Data.
   if (JPEG_STATUS_OK != jpeg_dec_hw_read_data(handle))
   {
      return handle->lastStatus;
   }

   /// Set up IDP.
   #if defined(__MTK_TARGET__) && (!defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)) && (!defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__))
   {
      kal_uint8 *imgBuffer[3] = {NULL, NULL, NULL};
      kal_uint8 i = 0;
      kal_int32 imgFmt;
      MY_RECTANGLE outputWin[3];

      // yuv mode: support yuv420 and uyvy422 only
      if ((JPEG_YUV_FORMAT_YUV420 == handle->canvasFormat) || (JPEG_YUV_FORMAT_PACKED_UYVY422 == handle->canvasFormat))
      {
         for (i=0; i<3; i++)
         {
            if (handle->canvasBuffer[i])
            {
               if (i == 0)
               {
                  outputWin[i].x = handle->outputWnd.x *  (kal_int32)frameInfo->frameComponentInfo[i].hSamplingFactor / (kal_int32)frameInfo->hSamplingFactorMax;
                  outputWin[i].y = handle->outputWnd.y *  (kal_int32)frameInfo->frameComponentInfo[i].vSamplingFactor / (kal_int32)frameInfo->vSamplingFactorMax;
                  outputWin[i].w = handle->outputWnd.w *  (kal_uint32)frameInfo->frameComponentInfo[i].hSamplingFactor / (kal_uint32)frameInfo->hSamplingFactorMax;
                  outputWin[i].h = handle->outputWnd.h *  (kal_uint32)frameInfo->frameComponentInfo[i].vSamplingFactor / (kal_uint32)frameInfo->vSamplingFactorMax;
               }
               else if ((i == 1) || (i == 2))
               {
                  outputWin[i].x = handle->outputWnd.x *  (kal_int32)frameInfo->frameComponentInfo[i].hSamplingFactor / 2;
                  outputWin[i].y = handle->outputWnd.y *  (kal_int32)frameInfo->frameComponentInfo[i].vSamplingFactor / 2;
                  outputWin[i].w = handle->outputWnd.w *  (kal_uint32)frameInfo->frameComponentInfo[i].hSamplingFactor / 2;
                  outputWin[i].h = handle->outputWnd.h *  (kal_uint32)frameInfo->frameComponentInfo[i].vSamplingFactor / 2;
               }

               if (i==0)
               {
                  imgBuffer[i] = (kal_uint8 *)handle->canvasBuffer[i] + (outputWin[i].y * handle->canvasWnd.w + outputWin[i].x) * handle->canvasBytesPerPixel;
               }
               else
               {
                  imgBuffer[i] = (kal_uint8 *)handle->canvasBuffer[i] + (outputWin[i].y * (handle->canvasWnd.w>>1) + outputWin[i].x) * handle->canvasBytesPerPixel;
               }
            }
         }
      }
      else  // rgb mode
      {
         imgBuffer[0] = (kal_uint8 *)handle->canvasBuffer[0] + (handle->outputWnd.y * handle->canvasWnd.w + handle->outputWnd.x) * handle->canvasBytesPerPixel;
      }
      

      // yuv mode: support yuv420 and uyvy422 only
      if ((JPEG_YUV_FORMAT_YUV420 == handle->canvasFormat) || (JPEG_YUV_FORMAT_PACKED_UYVY422 == handle->canvasFormat))
      {
         imgFmt = _jpeg_get_idp_yuv_format_enum((JPEG_YUV_FORMAT_ENUM)handle->canvasFormat);
      }
      else  // rgb mode
      {
         imgFmt = _jpeg_get_idp_rgb_format_enum((JPEG_RGB_FORMAT_ENUM)handle->canvasFormat);
      }
   
      if (!idp_jpeg_decode_config(handle->idpKey,
            IDP_JPEG_DECODE_JPEG_REAL_WIDTH, frameInfo->width,
            IDP_JPEG_DECODE_JPEG_REAL_HEIGHT, frameInfo->height,
            IDP_JPEG_DECODE_JPEG_DUMMY_WIDTH, frameInfo->paddedWidth - frameInfo->width,
            IDP_JPEG_DECODE_JPEG_DUMMY_HEIGHT, frameInfo->paddedHeight - frameInfo->height,
            IDP_JPEG_DECODE_JPEG_NUMBER_OF_COMPONENT, frameInfo->numberOfComponents,
            IDP_JPEG_DECODE_JPEG_Y_H_SAMPLE_FACTOR, frameInfo->frameComponentInfo[0].hSamplingFactor,
            IDP_JPEG_DECODE_JPEG_Y_V_SAMPLE_FACTOR, frameInfo->frameComponentInfo[0].vSamplingFactor,
            IDP_JPEG_DECODE_JPEG_U_H_SAMPLE_FACTOR, frameInfo->frameComponentInfo[1].hSamplingFactor,
            IDP_JPEG_DECODE_JPEG_U_V_SAMPLE_FACTOR, frameInfo->frameComponentInfo[1].vSamplingFactor,
            IDP_JPEG_DECODE_JPEG_V_H_SAMPLE_FACTOR, frameInfo->frameComponentInfo[2].hSamplingFactor,
            IDP_JPEG_DECODE_JPEG_V_V_SAMPLE_FACTOR, frameInfo->frameComponentInfo[2].vSamplingFactor,

            IDP_JPEG_DECODE_IMAGE_BUFFER_ADDRESS, imgBuffer[0],
            IDP_JPEG_DECODE_IMAGE_UBUFFER_ADDRESS, imgBuffer[1],
            IDP_JPEG_DECODE_IMAGE_VBUFFER_ADDRESS, imgBuffer[2],
            IDP_JPEG_DECODE_IMAGE_BUFFER_SIZE, handle->canvasWnd.w * handle->canvasWnd.h * handle->canvasBytesPerPixel,

            IDP_JPEG_DECODE_DISPLAY_WIDTH, handle->paddedOutputWnd.w,
            IDP_JPEG_DECODE_DISPLAY_HEIGHT, handle->paddedOutputWnd.h,

            IDP_JPEG_DECODE_ENABLE_PITCH, 1,
            IDP_JPEG_DECODE_BG_IMAGE_WIDTH, handle->canvasWnd.w,

            IDP_JPEG_DECODE_IMAGE_CLIP_LEFT, handle->targetClipWnd.x,
            IDP_JPEG_DECODE_IMAGE_CLIP_RIGHT, handle->targetClipWnd.x + handle->targetClipWnd.w - 1,
            IDP_JPEG_DECODE_IMAGE_CLIP_TOP, handle->targetClipWnd.y,
            IDP_JPEG_DECODE_IMAGE_CLIP_BOTTOM, handle->targetClipWnd.y + handle->targetClipWnd.h - 1,

            IDP_JPEG_DECODE_IMAGE_DATA_FORMAT, imgFmt,

            IDP_JPEG_DECODE_ROT_ANGLE, IMG_ROT_ANGLE_0,

            IDP_JPEG_DECODE_JPEG_DECODE_FINISH_CB, jpeg_isr_dec_idp_complete_lisr_callback,
            IDP_JPEG_DECODE_JPEG_DECODE_FINISH_CB_PARAM, 0,

            IDP_JPEG_DECODE_INTMEM_START_ADDRESS, handle->idpIntMemoryAddr,
            IDP_JPEG_DECODE_INTMEM_SIZE, handle->idpIntMemorySize,
            IDP_JPEG_DECODE_EXTMEM_START_ADDRESS, handle->idpExtMemoryAddr,
            IDP_JPEG_DECODE_EXTMEM_SIZE, handle->idpExtMemorySize,

            0))
      {
         /// IDP error, return error.
         idp_jpeg_decode_error_code_t idp_error_code;

         idp_jpeg_decode_query(handle->idpKey, IDP_JPEG_DECODE_QUERY_ERROR_CODE, &idp_error_code, 0);

         switch (idp_error_code)
         {
         case IDP_JPEG_DECODE_ERROR_CODE_SRC_WIDTH_TOO_LARGE:
         case IDP_JPEG_DECODE_ERROR_CODE_SRC_WIDTH_TOO_SMALL:
         case IDP_JPEG_DECODE_ERROR_CODE_SRC_HEIGHT_TOO_LARGE:
         case IDP_JPEG_DECODE_ERROR_CODE_SRC_HEIGHT_TOO_SMALL:
         case IDP_JPEG_DECODE_ERROR_CODE_HW_LIMITATION:
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_SOURCE_DIMENSION_ERROR;
            break;
         case IDP_JPEG_DECODE_ERROR_CODE_TAR_WIDTH_TOO_LARGE:
         case IDP_JPEG_DECODE_ERROR_CODE_TAR_WIDTH_TOO_SMALL:
         case IDP_JPEG_DECODE_ERROR_CODE_TAR_HEIGHT_TOO_LARGE:
         case IDP_JPEG_DECODE_ERROR_CODE_TAR_HEIGHT_TOO_SMALL:
            handle->lastStatus = JPEG_STATUS_DEC_ERROR_DESTINATION_DIMENSION_ERROR;
            break;
         default:
            handle->lastStatus = JPEG_STATUS_IDP_ERROR;
         }

         return handle->lastStatus;
      }

      idp_jpeg_decode_start_all(handle->idpKey);
   }
   #endif /// __MTK_TARGET__

   /// Trigger the JPEG decoder.
   handle->codecState = JPEG_CODEC_STATE_BUSY;
   jpeg_drv_dec_start();

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif

#if defined(__DRV_GRAPHICS_HW_JPEG_DECODE_SEPARATED_FROM_MDP__)
   {
      kal_uint32 decoded_mcu_count;
      kal_uint32 total_mcu_count;
      CHECK_ABORT_FUNC           pCheckAbort;
   
      // Get the check abort function
      pCheckAbort = handle->pCheckAbort;
   
      // update codecState
      _jpeg_hw_decoder.codecState = handle->codecState;

      // update rsBuffer
      memcpy(&(_jpeg_hw_decoder.rsBuffer), &(handle->rsBuffer), sizeof(RS_BUFFER));
      _jpeg_hw_decoder.dataLeft = handle->dataLeft;
      
      // initialize decoded mcu count
      handle->hwDecodeMcuCount[0] = 0;
      handle->hwDecodeMcuCount[1] = 0;
      
      while ((JPEG_CODEC_STATE_IDLE != _jpeg_hw_decoder.codecState) 
                 && (JPEG_CODEC_STATE_COMPLETE != _jpeg_hw_decoder.codecState) 
                 && (JPEG_CODEC_STATE_ERROR != _jpeg_hw_decoder.codecState)
                 ) 
      {
         // sysram block copy
         if (JPEG_STATUS_OK != jpeg_dec_copy_block(handle))
         {
            return handle->lastStatus;
         }

         // check abort jump out
         if (JPEG_CODEC_STATE_IDLE == handle->codecState)
         {
            _jpeg_hw_decoder.codecState = handle->codecState;
         }
         else
         {
            jpeg_isr_dec_hisr();
   
            if (JPEG_CODEC_STATE_PAUSED == _jpeg_hw_decoder.codecState)
            {
               SW_DECODE_CHECK_ABORT(handle, pCheckAbort);
         
               _jpeg_hw_decoder.codecState = JPEG_CODEC_STATE_BUSY;
   
                // update rsBuffer
                memcpy(&(handle->rsBuffer), &(_jpeg_hw_decoder.rsBuffer), sizeof(RS_BUFFER));
                handle->dataLeft = _jpeg_hw_decoder.dataLeft;
          
               /// Read JPEG data.
               if (JPEG_STATUS_OK != jpeg_dec_hw_read_data(handle))
               {
                  _jpeg_hw_decoder.codecState = JPEG_CODEC_STATE_ERROR;
               }
   
               /// Trigger the JPEG decoder.
               jpeg_drv_dec_resume();
            }
            else if (JPEG_CODEC_STATE_COMPLETE == _jpeg_hw_decoder.codecState)
            {
               while (handle->hwDecodeMcuCount[1] <= (frameInfo->mcuPerColumn - 1))
               {
                  SW_DECODE_CHECK_ABORT(handle, pCheckAbort);

                  // copy the last section
                  jpeg_dec_copy_block(handle);
               }
            }
            else if (JPEG_CODEC_STATE_ERROR == _jpeg_hw_decoder.codecState)
            {
               kal_uint32 decoded_mcu_count = jpeg_drv_dec_get_decoded_mcu_count();
               kal_uint32 total_mcu_count = jpeg_drv_dec_get_total_mcu_count();
      
               /// If the number of decoded MCUs >= 0.75 * total number of MCUs, 
               /// set the result as complete.
               if (decoded_mcu_count >= ((total_mcu_count * 3) >> 2))
               {
                  _jpeg_hw_decoder.codecState = JPEG_CODEC_STATE_COMPLETE;
               }
            }
         }
      }

      // update codecState
      handle->codecState = _jpeg_hw_decoder.codecState;
      handle->lastStatus = _jpeg_hw_decoder.lastStatus;
   }
#endif

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
#endif

   return handle->lastStatus;
}

#endif /// __DRV_GRAPHICS_HW_JPEG_DECODE_SUPPORTED__



#if defined(__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__)
extern const kal_uint8 swjd_zig_zag_table_8x8_normal[64 + 8];
JPEG_STATUS_ENUM jpeg_dec_hw_hybrid_internal(JPEG_DECODER_HANDLE handle)
{
   //SWJE_FILE *dstFile = &(handle->dstFile);
   SWJD_DEQUANT_IDCT_UNIT  *pDequantIDCT= handle->pDequantIDCTUnit;
   kal_uint32  compIndex;
   kal_int32 compCount;
   kal_uint32  regAddr;
   kal_int32   vSampling, hSampling;
   kal_int32 vIndex, hIndex;
   JPEG_FRAME_INFO   *pFrameInfo;
   HuffmanDecQuantTable *pQuantTable ;
   kal_int32  tableIndex;
   kal_int8  dezigzag_quanTabl[64] = {0};
   kal_uint32 index;
   HuffmanDecoder	*pDecoder = handle->pHuffDecoder;
   JPEG_FILE_INFO *fileInfo = &(handle->fileInfo);
   JPEG_FRAME_INFO *frameInfo = &(fileInfo->frameInfo);

   
   /// 0. Power JPEG encoder
   jpeg_drv_dec_power_on();
   
   jpeg_drv_dec_reset();
   
   // Get the component count of the image
   compCount = pDequantIDCT->compCount;
   
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
#else
   /// 4. Set up sampling factor related attributes.
   ///    Including REG_JPEG_DEC_SAMP_FACTOR register and REG_JPEG_DEC_CTRL register.
   jpeg_drv_dec_set_sampling_factor_related(frameInfo->numberOfComponents,
                                            frameInfo->frameComponentInfo[0].hSamplingFactor, frameInfo->frameComponentInfo[0].vSamplingFactor,
                                            frameInfo->frameComponentInfo[1].hSamplingFactor, frameInfo->frameComponentInfo[1].vSamplingFactor,
                                            frameInfo->frameComponentInfo[2].hSamplingFactor, frameInfo->frameComponentInfo[2].vSamplingFactor);
#endif


   jpeg_drv_dec_get_dst_base(&regAddr);
   memset((kal_uint32*)regAddr, 0, (8*8*6 *1));  

   jpeg_drv_dec_get_src_base(&regAddr);
   memset((kal_uint32*)regAddr, 0, (8*8*6 * 2));

   jpeg_drv_dec_get_mciq_base(&regAddr);
   memset((kal_uint32*)regAddr, 0, (8*8*6));

   //5. Set de Quantization table
#if 0
/* under construction !*/
#else
   jpeg_drv_dec_get_mciq_base(&regAddr);
#endif
   for (compIndex = 0; compIndex < compCount; compIndex++)
   {
      vSampling = pDequantIDCT->VSampling[compIndex];
      pFrameInfo = &(handle->fileInfo.frameInfo);
      tableIndex = pFrameInfo->frameComponentInfo[compIndex].qTableSelector;
      pQuantTable = handle->pInverseQuantTable[tableIndex];
     
      for (index = 0; index < 64; index++)
      {
         dezigzag_quanTabl[pDecoder->pDeZigZag[index]] = pQuantTable->quantVal[index] & 0x0FF;
      }

      for (vIndex = vSampling; --vIndex >= 0;)
      {
         // Write quantization table in scan line order
         for(hIndex = pDequantIDCT->HSampling[compIndex]; --hIndex >= 0;)
         {
            kal_int32  tmp;
            for (index = 0; index < 64; index+=4, regAddr += 4)
            {
               tmp = (dezigzag_quanTabl[index + 0] & 0x0FF) |
                    ((dezigzag_quanTabl[index + 1] & 0x0FF) << 8) |
                    ((dezigzag_quanTabl[index + 2] & 0x0FF) << 16) |
                    ((dezigzag_quanTabl[index + 3] & 0x0FF) << 24);               
               HMJPEG_WRITE_DATA(regAddr, tmp);
            }
         }
      }
    }


   return JPEG_STATUS_OK;
}



#endif  //__DRV_GRAPHICS_HYBRID_SW_HW_JPEG_DECODE_SUPPORTED__

