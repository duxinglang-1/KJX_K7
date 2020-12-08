/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   AvbSink.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Audio Playback Via Bluetooth SCO link Function
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#if defined( __BT_AUDIO_VIA_SCO__ ) && defined(__AUDIO_COMPONENT_SUPPORT__) && !defined(__CVSD_CODEC_SUPPORT__) 

#include "kal_public_api.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "kal_trace.h"

#include "l1audio.h"
#include "speech_def.h"
#include "audio_def.h"
#include "l1sp_trc.h"
#include "am.h"
#include "blisrc_exp.h"
#include "med_utility.h"
#include "pcmsink.h"

#include "l1audio_trace.h"
#include "l1sp_trc.h"
#include "l1audio_sph_trc.h"

#define AVB_FLUSH_MAX_TICK    (80)
#define AVB_SAMPLE_RATE       (8000)
#define AVB_CHANNEL_NUM       (1)
#define AVB_SEGMENT_NUMBER    (8)
#define AVB_SEGMENT_MASK      (0x7)
#define AVB_FRAME_SAMPLE      (160)
#define AVB_DSP_BUFFER_SIZE   (AVB_FRAME_SAMPLE*2*AVB_SEGMENT_NUMBER)
#define AVB_SRC_BUFFER_SIZE   (1024*16)

typedef enum {
  AVB_STATE_IDLE = 0,
  AVB_STATE_RUNING,
  AVB_STATE_FLUSH_TAIL,
  AVB_STATE_FLUSH_PING,
  AVB_STATE_FLUSH_PONG,
  AVB_STATE_ENDING,
} AVB_STATE;

#pragma arm section code="SECONDARY_ROCODE"

struct {
   kal_uint32       uSampleRate;
   void             *pBLISRC;
   kal_uint16       *pBuffer;
   kal_uint32       uSegment_W;
   kal_uint32       uSegment_R;
   kal_uint32       uSample_W;
   AUD_RB_INFO      PCM;
   kal_uint16       uAudID;
   AVB_STATE        uState;
   kal_bool         fSilence;
   kal_uint8        uChannelNumber;
   kal_bool         uHisrRunning;
}AVB;

static void AVB_HISR(void *data)
{
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_AVB_HISR, AVB.uState, AVB.uSegment_W, AVB.uSegment_R);
   AVB.uHisrRunning = KAL_TRUE;
   if(AVB.uState == AVB_STATE_ENDING || AVB.uState == AVB_STATE_IDLE )
   {
      return;
   }
   if( *DSP_TONE_CTRL1 != 0 || *DSP_TONE_CTRL2 != 0 ) //playing speech tone, drop one frame
   {
      if(AVB.uSegment_W > AVB.uSegment_R)
      {
         AVB.uSegment_R++;
      }
   }
   else
   {
      kal_uint16 uDSPAddr;
      kal_int32 i;
      kal_int16 *pDst, *pSrc;
      uDSPAddr = *DSP_DM_ADDR(BT_AUDIO_PLAYBACK_SD_PAGE_NUM, BT_AUDIO_PLAYBACK_SD_PTR_ADDR);
      pDst = (volatile kal_uint16 *)DSP_DM_ADDR(BT_AUDIO_PLAYBACK_SD_PAGE_NUM, uDSPAddr);
      if(AVB.uSegment_W == AVB.uSegment_R || AVB.fSilence)
      {  //fill silence
         for(i=AVB_FRAME_SAMPLE-1;i>=0;i--)
         {
            *pDst++ = 0;
         }
         if(AVB_STATE_FLUSH_PING == AVB.uState)
         {
            AVB.uState = AVB_STATE_FLUSH_PONG;
         }
         else if(AVB_STATE_FLUSH_PONG == AVB.uState)
         {
            AVB.uState = AVB_STATE_ENDING;
         }
      }
      else
      {  //fill data
         pSrc = AVB.pBuffer + (AVB.uSegment_R & AVB_SEGMENT_MASK) * AVB_FRAME_SAMPLE;
         for(i=AVB_FRAME_SAMPLE-1;i>=0;i--)
         {
            *pDst++ = *pSrc++;
         }
      }
      if(AVB.uSegment_W > AVB.uSegment_R)
      {
         AVB.uSegment_R++;
      }
   }
   L1Audio_SetEvent( AVB.uAudID, NULL );
}

static void AVB_Process(void *pData)
{
   kal_int16 *pDstBuffer;
   kal_int8 *pSrcBuffer;
   kal_uint32 uSrcByte, uDstByte, uConsumeByte;
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_AVB_PROC, AVB.uState, AVB.uSegment_W, AVB.uSegment_R);
   while(AVB.uSegment_W - AVB.uSegment_R < AVB_SEGMENT_NUMBER)
   {
      rbGetReadBuffer(&AVB.PCM, &pSrcBuffer, &uSrcByte);
      if(uSrcByte<4)
      {
         break;
      }
      uDstByte = (AVB_FRAME_SAMPLE-AVB.uSample_W)*2;
      pDstBuffer = AVB.pBuffer + (AVB.uSegment_W & AVB_SEGMENT_MASK) * AVB_FRAME_SAMPLE + AVB.uSample_W;
      uConsumeByte = BLI_Convert(AVB.pBLISRC, (kal_int16*)pSrcBuffer, &uSrcByte, pDstBuffer, &uDstByte);  
      rbReadDataDone(&AVB.PCM, uConsumeByte);
      AVB.uSample_W += uDstByte>>1;
      ASSERT(AVB.uSample_W <= AVB_FRAME_SAMPLE);
      if(AVB.uSample_W == AVB_FRAME_SAMPLE)
      {
         AVB.uSample_W = 0;
         AVB.uSegment_W++;
      }
      else
      {
         uDstByte = (AVB_FRAME_SAMPLE-AVB.uSample_W)*2;
         pDstBuffer = AVB.pBuffer + (AVB.uSegment_W & AVB_SEGMENT_MASK) * AVB_FRAME_SAMPLE + AVB.uSample_W;
         memset(pDstBuffer, 0, uDstByte);
      }
   }
   if(AVB.uState == AVB_STATE_FLUSH_TAIL)
   {
      rbGetReadBuffer(&AVB.PCM, &pSrcBuffer, &uSrcByte);
      if(uSrcByte<4)
      {
         if(AVB.uSample_W)
         {
            AVB.uSample_W = 0;
            AVB.uSegment_W++;
         }
         AVB.uState = AVB_STATE_FLUSH_PING;
      }
   }
}

void AVB_Open()
{
   kal_uint32 uWorkingBuffer;
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_AVB_OPEN, AVB.uState);
   ASSERT(AVB.uState == AVB_STATE_IDLE);
   ASSERT(AVB.uSampleRate);
   PcmSink_StartBT(PCMSINK_BT_SCO);
   mhdlHookPcmRut();
   BLI_GetMemSize(AVB.uSampleRate, AVB.uChannelNumber, AVB_SAMPLE_RATE, AVB_CHANNEL_NUM, &uWorkingBuffer);
   uWorkingBuffer = (uWorkingBuffer+3) & ~3;
   AVB.pBuffer = (kal_uint16 *)audio_alloc_mem_cacheable(uWorkingBuffer + AVB_DSP_BUFFER_SIZE + AVB_SRC_BUFFER_SIZE);                 
   ASSERT(AVB.pBuffer);
   AVB.pBLISRC = BLI_Open(AVB.uSampleRate, AVB.uChannelNumber, AVB_SAMPLE_RATE, AVB_CHANNEL_NUM, ((kal_int8*)AVB.pBuffer)+AVB_DSP_BUFFER_SIZE, audio_alloc_ext_mem_cacheable_simplified);
   ASSERT(AVB.pBLISRC);
   AVB.PCM.rb_base = ((kal_int8*)AVB.pBuffer)+AVB_DSP_BUFFER_SIZE+uWorkingBuffer;
   AVB.PCM.rb_size = AVB_SRC_BUFFER_SIZE;
   AVB.PCM.write   = 0;
   AVB.PCM.read    = 0;
   AVB.uAudID = L1Audio_GetAudioID();
   L1Audio_SetFlag( AVB.uAudID );
   L1Audio_SetEventHandler( AVB.uAudID, AVB_Process );
   AVB.uState = AVB_STATE_RUNING;
   L1Audio_HookHisrHandler( D2C_AUDIO_VIA_8KBT_ID, AVB_HISR, 0);
}

void AVB_Flush()
{
   kal_uint32 i=0;
   AVB.uHisrRunning = KAL_FALSE;
   if(AVB.uState == AVB_STATE_RUNING)
   {
      AVB.uState = AVB_STATE_FLUSH_TAIL;
   }
   while(AVB.uState != AVB_STATE_ENDING)
   {
      kal_trace( TRACE_GROUP_SCO, L1AUDIO_AVB_FLUSH, AVB.uState, AVB.uHisrRunning, i);
      kal_sleep_task(1);
      if(i>AVB_FLUSH_MAX_TICK)
      {
         //ASSERT(!AVB.uHisrRunning);
         break;
      }
      i++;
   }
}

void AVB_Close()
{
   kal_uint16 uSampleRate; 
   kal_uint8  uChannelNumber; 
   kal_trace( TRACE_GROUP_SCO, L1AUDIO_AVB_CLOSE, AVB.uState);
   PcmSink_StopBT(PCMSINK_BT_SCO);
   if(AVB.uState == AVB_STATE_IDLE)
   {
      return;
   }
   L1Audio_UnhookHisrHandler(D2C_AUDIO_VIA_8KBT_ID);
   L1Audio_ClearFlag( AVB.uAudID ); //enable sleep mode     
   L1Audio_FreeAudioID(AVB.uAudID);
   AVB.uState = AVB_STATE_IDLE;
   audio_free_mem( (void **) &AVB.pBuffer);
   BLI_Close(AVB.pBuffer, audio_free_ext_mem_simplified);
   uSampleRate = AVB.uSampleRate; 
   uChannelNumber = AVB.uChannelNumber; 
   memset(&AVB, 0, sizeof(AVB));
   AVB.uSampleRate = uSampleRate;
   AVB.uChannelNumber = uChannelNumber;
}

kal_uint32 AVB_WriteSilence(kal_uint32 uSampleCount)
{
   kal_uint32 uCopyWord=0, uOutByte=0, i, j, uOrigSrcWord, uChannelNumber, uOutWord;
   kal_uint8 *pDst;
   if(AVB.uState != AVB_STATE_RUNING)
   {
      return 0;
   }
   uOrigSrcWord = uSampleCount;
   for(i=0;i<2;i++)
   {
      kal_int16 *pBuf;
      rbGetWriteBuffer(&AVB.PCM, &pDst, &uOutByte);  
      uOutWord = uOutByte >> 1;
      if(uOutWord > uSampleCount)
      {
         uOutWord = uSampleCount;
      }
      memset( pDst, 0, uOutWord*sizeof(kal_uint16) );
      rbWriteDataDone(&AVB.PCM, uOutWord<<1);
      uCopyWord    += uOutWord;
      uSampleCount -= uOutWord;
   }
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_AVB_WRITE_ZERO, uOrigSrcWord, uCopyWord, uOrigSrcWord-uCopyWord);
   return uCopyWord;
}

kal_uint32 AVB_WriteData(kal_uint16 *pSrc16, kal_uint32 uSrcWord, kal_bool fMono2Stereo)
{
   kal_uint32 uCopyWord=0, uOutByte=0, i, j, uOrigSrcWord=0, uOutWord=0;
   kal_uint8 *pDst;
   if(AVB.uState != AVB_STATE_RUNING)
   {
      return 0;
   }
   uOrigSrcWord = uSrcWord;
   for(i=0;i<2;i++)
   {
      kal_uint16 *pDst16;
      rbGetWriteBuffer(&AVB.PCM, &pDst, &uOutByte);  
      pDst16 = (kal_uint16*)pDst;
      uOutWord = uOutByte >> 1;
      if(fMono2Stereo)
      {
         uOutWord = uOutWord >> 1;
         if(uOutWord > uSrcWord)
         {
            uOutWord = uSrcWord;
         }
         for(j=0;j<uOutWord;j++)
         {
            *pDst16++ = *pSrc16;
            *pDst16++ = *pSrc16++;
         }
         uSrcWord -= uOutWord;
         rbWriteDataDone(&AVB.PCM, uOutWord<<2);
      }
      else
      {
         if(uOutWord > uSrcWord)
         {
            uOutWord = uSrcWord;
         }
         memcpy(pDst16, pSrc16, uOutWord*sizeof(kal_uint16));
         pSrc16   += uOutWord;
         uSrcWord -= uOutWord;
         rbWriteDataDone(&AVB.PCM, uOutWord<<1);
      }
      uCopyWord += uOutWord;
   }
   kal_brief_trace( TRACE_GROUP_SCO, L1AUDIO_AVB_WRITE_DATA, uOrigSrcWord, uCopyWord, uOrigSrcWord-uCopyWord, fMono2Stereo);
   return uCopyWord;
}

void AVB_SetInfo(kal_uint16 uSampleRate, kal_uint8 uChannelNumber)
{
   AVB.uSampleRate    = uSampleRate;
   AVB.uChannelNumber = uChannelNumber;
}

#pragma arm section 

#endif// endif __BT_AUDIO_VIA_SCO__
