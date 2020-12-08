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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   aac_drv.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  AAC Decoder Driver (Component based)
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
 *
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

#if defined(AAC_DECODE)

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"
#include "fsal.h"
#include "mp4_parser.h"
#include "mp4_common.h"
#include "kal_trace.h"
#include "audio_enum.h"
#include "l1sp_trc.h"
#include "l1audio.h"
#include "audio_def.h"
#include "OMX_Core.h"
#include "OMX_Types.h"
#include "OMX_Index.h"
#include "AudCom.h"
#include "media.h"
#include "ast.h"
#include "AudComUtil.h"
#include "MedAdapt.h"
#include "aac_codec.h"
#include "aac_drv.h"
#include "heaac_dec_exp.h"
#include "aac_dec_exp.h"

#if defined(__ADIF_TOTAL_FRAME_ESTIMATION__)
Media_Status AAC_ADIF_CheckFrame(STFSAL *pstFSAL, kal_bool fDecodeFrame, kal_uint32 *uFrameNum, kal_uint32 *uOffset)
{
   kal_int32 uInterBufSize=0, uTmpBufSize=0, uPcmBufSize=0, uBsBufSize=0, uSbrBufSize=0, uTotalMemory=0, uRBStructSize=0, uRBSize=0;
   kal_uint32 uFileSize=0, uCurrentFrameOffset=0, uTotalFrameNum=0;
   kal_int32 I=0;
   kal_uint8 *pBuf = NULL;
   void *pTmpBuf, *pInterBuf, *pPcmBuf;
   AUD_RB_INFO *pRingBuf;
   AACDEC_Handle *pAacDecHdl = NULL;
   
   AACDec_GetMemSize(&uInterBufSize, &uTmpBufSize, &uPcmBufSize, &uBsBufSize, &uSbrBufSize);  
   uInterBufSize = (uInterBufSize   + 3) & ~0x3;
   uTmpBufSize   = (uTmpBufSize     + 3) & ~0x3;
   uPcmBufSize   = (uPcmBufSize     + 3) & ~0x3;

   uRBStructSize = (sizeof(AUD_RB_INFO) + 3) & ~0x3;
   uRBSize = AAC_ADIF_PARSER_BUFFERSIZE;
   
   uTotalMemory = uInterBufSize + uTmpBufSize + + uPcmBufSize+ uRBStructSize + uRBSize;
   pBuf = (kal_uint8 *)audio_alloc_mem_cacheable( uTotalMemory * sizeof(kal_uint8) );
   if(pBuf==NULL)
   {
      return MEDIA_FAIL;
   }
   //skip ID3 first
   ACU_SkipID3Tag(pstFSAL, uOffset, pBuf);
   
   //alloc memory
   pInterBuf = (void*)pBuf;
   pBuf += uInterBufSize;
   pTmpBuf   = (void*)pBuf;
   pBuf += uTmpBufSize;
   pPcmBuf   = (void*)pBuf;
   pBuf += uPcmBufSize;
   pRingBuf  = (AUD_RB_INFO*)pBuf;
   pBuf += uRBStructSize;
   pRingBuf->rb_base = (kal_uint8*)pBuf;
   pRingBuf->rb_size = AAC_ADIF_PARSER_BUFFERSIZE;

 
   //Init decoder
   pAacDecHdl  = (void*)AACDec_Init( pInterBuf, NULL);
   ASSERT(pAacDecHdl);

   FSAL_GetFileSize(pstFSAL, &uFileSize);
   while(I<*uFrameNum)
   {
      kal_int32 sConsumeBytes, sStatus;
      kal_uint8 *pBsBuf;
      kal_uint32 uBsReadLen;
      rbGetWriteBuffer(pRingBuf, &pBsBuf, &uBsReadLen);
      if(uBsReadLen > uFileSize-*uOffset)
      {  //EOF
         uBsReadLen = uFileSize-*uOffset;
      }

      if(uBsReadLen)
      {
         FSAL_Seek( pstFSAL, *uOffset);
         if(FSAL_Read_Bytes( pstFSAL, pBsBuf, uBsReadLen) != FSAL_OK)
         {
            break;
         }
         rbWriteDataDone(pRingBuf, uBsReadLen);
         *uOffset+=uBsReadLen;
      }

      if(fDecodeFrame)
      {
         sStatus = AACDec_DecodeFrame(pAacDecHdl,                          /* pointer to decoder handle     */
                                      pPcmBuf,                             /* pointer to PCM buffer         */
                                      pTmpBuf,                             /* pointer to temprary buffer    */
                                      pRingBuf->rb_base,                   /* pointer to bitstream buffer   */
                                      AAC_ADIF_PARSER_BUFFERSIZE ,         /* pointer to bitstream length   */
                                      pRingBuf->rb_base + pRingBuf->read,  /* bitstream buffer read pointer */
                                      &sConsumeBytes);                     /* consumed length of bitstream  */
      }
      else
      {
         sStatus = AACDec_DecodeFrameBypass(pAacDecHdl,                          /* pointer to decoder handle     */
                                            pPcmBuf,                             /* pointer to PCM buffer         */
                                            pTmpBuf,                             /* pointer to temprary buffer    */
                                            pRingBuf->rb_base,                   /* pointer to bitstream buffer   */
                                            AAC_ADIF_PARSER_BUFFERSIZE ,         /* pointer to bitstream length   */
                                            pRingBuf->rb_base + pRingBuf->read,  /* bitstream buffer read pointer */
                                            &sConsumeBytes);                     /* consumed length of bitstream  */


      }

      if(sConsumeBytes <= rbGetDataCount(pRingBuf))
      {

         rbGetReadBuffer(pRingBuf, &pBsBuf, &uBsReadLen);
         if(uBsReadLen >= sConsumeBytes)
         {
            rbReadDataDone(pRingBuf, sConsumeBytes);
         }
         else
         {
            rbReadDataDone(pRingBuf, uBsReadLen);
            rbReadDataDone(pRingBuf, sConsumeBytes-uBsReadLen);
         }
         uCurrentFrameOffset += sConsumeBytes;
         
         if(sStatus==0)
         {
            I++;
         }
         else
         {
            break;
         }
      }
      else
      {
         break;
      }
   }
   audio_free_mem( (void **) &pInterBuf );
   *uFrameNum = I;
   return MEDIA_SUCCESS;
}
#endif


Media_Format AAC_GetMediaFormat(STFSAL *pstFSAL)
{
   // under construction
   return MEDIA_FORMAT_AAC;
}

#if !defined(AAC_PLUS_DECODE)  

Media_Format AAC_GetMediaFormat_Detail_v2(kal_uint8 *pBuf, kal_uint32 uBufLen, kal_uint32 *uChannel, kal_uint32 *uSampleRate)
{
   #define AAC_TEMP_BUFFER_LEN 1024
   Media_Status uResult;
   FSAL_Status uFSALStatus;
   kal_uint32 uCurOffset;
   STFSAL *pstFSAL;
   kal_uint8 *pTempBuf;
   AAC_FrameInfo aacInfo;
   MHPB_Internal *ihdl;

   pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   FSAL_Direct_SetRamFileSize(pstFSAL, uBufLen);
   uFSALStatus = FSAL_Open(pstFSAL, pBuf, FSAL_ROMFILE);

   ihdl = (MHPB_Internal *)audio_alloc_mem( sizeof(MHPB_Internal) );
   pTempBuf = (kal_uint8 *)audio_alloc_mem( uBufLen*sizeof(kal_uint8) );

   ASSERT( FSAL_OK == uFSALStatus);
   ASSERT(ihdl);
   ASSERT(pTempBuf);

   ACU_SkipID3Tag(pstFSAL, &uCurOffset, pTempBuf);
   uResult = aacSyncFrame(pstFSAL, &uCurOffset, pTempBuf, AAC_TEMP_BUFFER_LEN, &aacInfo);
   audio_free_mem( (void **) &ihdl );  
   audio_free_mem( (void **) &pTempBuf );  
   free_ctrl_buffer(pstFSAL);
   if(uResult != MEDIA_SUCCESS)
   {
      return MEDIA_FORMAT_UNKNOWN;
   }
   else
   {
      *uChannel = (kal_uint32)aacInfo.bIsStereo+1;
      *uSampleRate = aacInfo.uSampleRate;
      return MEDIA_FORMAT_AAC;
   }
}

#else

Media_Format AAC_GetMediaFormat_Detail_v2(kal_uint8 *pBuf, kal_uint32 uBufLen, kal_uint32 *uChannel, kal_uint32 *uSampleRate)
{
   Media_Format format;
   kal_int32 InterBufSize=0, TmpBufSize=0, PcmBufSize=0, BsBufSize=0;
   kal_uint8 *pInterBuf=0, *pTmpBuf=0, *pPcmBuf=0, *pSbrBuf=0;
   kal_int32 consumBsLen = 0;
   
#if defined(AAC_PLUS_DECODE)
   HEAACDec_GetMemSize( &InterBufSize, &TmpBufSize , &PcmBufSize, &BsBufSize);
   pInterBuf = (kal_uint8 *)audio_alloc_mem_cacheable(InterBufSize);
   ASSERT(pInterBuf);
   pTmpBuf   = (kal_uint8 *)audio_alloc_mem_cacheable(TmpBufSize);  
   ASSERT(pTmpBuf);
   pPcmBuf   = (kal_uint8 *)audio_alloc_mem_cacheable(PcmBufSize);  
   ASSERT(pPcmBuf);
#else
   {
      kal_int32 SbrBufSize=0;
      
      AACDec_GetMemSize( &InterBufSize, &TmpBufSize, &PcmBufSize, &BsBufSize, &SbrBufSize); 
      pInterBuf = (kal_uint8 *)audio_alloc_mem_cacheable(InterBufSize);  
      ASSERT(pInterBuf);
      pTmpBuf   = (kal_uint8 *)audio_alloc_mem_cacheable(TmpBufSize);  
      ASSERT(pTmpBuf);
      pPcmBuf   = (kal_uint8 *)audio_alloc_mem_cacheable(PcmBufSize);  
      ASSERT(pPcmBuf);
      pSbrBuf   = (kal_uint8 *)audio_alloc_mem_cacheable(SbrBufSize);  
      ASSERT(pSbrBuf);
   }
#endif

   format = MEDIA_FORMAT_AAC;

#if defined(AAC_PLUS_DECODE)  
   {
      HEAACDEC_HANDLE *aacDecHdl;
      OMX_S32 decoder_status =0;

      aacDecHdl = (void*)HEAACDec_Init( pInterBuf, SBR_AUTO, SBR_MODE_AUTO,0);
      ASSERT(aacDecHdl);
      decoder_status = HEAACDec_DecodeFrame(aacDecHdl, (void*)pPcmBuf, (void*)pTmpBuf, (const void*)pBuf, (int)uBufLen, (const void*)pBuf, &consumBsLen);
      if(!decoder_status)
      {
         *uChannel = aacDecHdl->ChannelNum;
         *uSampleRate = aacDecHdl->SampleRate;
         if(aacDecHdl->sbrFlag)
         {
            *uSampleRate = *uSampleRate / 2;
            format = MEDIA_FORMAT_AAC_PLUS;
         }
#if defined(AAC_PLUS_PS_DECODE)
         if(aacDecHdl->psFlag)
         {
            *uChannel = *uChannel / 2;
            format = MEDIA_FORMAT_AAC_PLUS_V2;
         }
#endif
      }
   }
#else 
   {
      AACDEC_Handle *aacDecHdl;
      OMX_S32 decoder_status =0;

      aacDecHdl = (void*)AACDec_Init( pInterBuf, pSbrBuf);
      ASSERT(aacDecHdl);

      decoder_status = AACDec_DecodeFrame(aacDecHdl, (void*)pPcmBuf, (void*)pTmpBuf, (const void*)pBuf, (int)uBufLen, (const void*)pBuf, &consumBsLen);   
      if(!decoder_status)
      {
         *uChannel = aacDecHdl->channelNum;
         *uSampleRate = aacDecHdl->sampleRate;
      }
   }
#endif
   audio_free_mem( (void **) &pInterBuf);
   audio_free_mem( (void **) &pTmpBuf);
   audio_free_mem( (void **) &pPcmBuf);
   if(pSbrBuf)
   {
      audio_free_mem( (void **) &pSbrBuf);
   }
   return format;
}

#endif

kal_bool AAC_IsPPSupport(STFSAL *pstFSAL)
{
   return KAL_TRUE;
}

kal_bool AAC_IsADIF( STFSAL *pstFSAL)
{
   kal_uint8 *pBuf;
   kal_uint32 uBufLen = 1024, uCurOffset = 0;
   AAC_FrameInfo aacInfo;
   pBuf = (kal_uint8*)get_ctrl_buffer(uBufLen*sizeof(kal_uint8));
   ACU_SkipID3Tag(pstFSAL, &uCurOffset, pBuf);
   aacSyncFrame(pstFSAL, &uCurOffset, pBuf, uBufLen, &aacInfo);
   free_ctrl_buffer( pBuf );
   return aacInfo.bIsADIF;
}

Media_Status AAC_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   kal_uint8 *pBuf;
   kal_uint32 uBufLen = 1024, uCurOffset = 0, uFileSize = 0, uFirstFrameOffset;
   AAC_FrameInfo aacInfo;
   MHPB_Internal *ihdl;
   memset(contentInfo, 0, sizeof(audInfoStruct));
   ihdl = (MHPB_Internal *)audio_alloc_mem( sizeof(MHPB_Internal) );
   if(ihdl==NULL)
   {
      return MEDIA_FAIL;
   }
   {
      FSAL_GetFileSize(pstFSAL, &uFileSize);
      pBuf = (kal_uint8 *)audio_alloc_mem( uBufLen*sizeof(kal_uint8) );
      if(pBuf==NULL)
      {
         audio_free_mem( (void **) &ihdl );  
         return MEDIA_FAIL;
      }
      ACU_SkipID3Tag(pstFSAL, &uCurOffset, pBuf);
      if(MEDIA_SUCCESS != aacSyncFrame(pstFSAL, &uCurOffset, pBuf, uBufLen, &aacInfo))
      { 
         audio_free_mem( (void **) &ihdl );  
         audio_free_mem( (void **) &pBuf );  
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_DESCINFO, MEDIA_FORMAT_AAC, MEDIA_FAIL);
         return MEDIA_FAIL;
      }
      uFirstFrameOffset = uCurOffset;
      aacGetByteRate(pstFSAL, &aacInfo, uCurOffset);
   }
   contentInfo->stereo   = aacInfo.bIsStereo;
   contentInfo->bitRate  = aacInfo.uBitRate;
   contentInfo->sampleRate  = aacInfo.uSampleRate;

#if defined(__ADIF_TOTAL_FRAME_ESTIMATION__)
   if(aacInfo.bIsADIF)
   {
      Media_Status ret;
      kal_uint32 uFrameNum = AAC_ADIF_PARSE_FRAMENUM;
      kal_uint32 uOffset=0, uTotalFrameNum = 0;
      ret = AAC_ADIF_CheckFrame(pstFSAL, KAL_FALSE, &uFrameNum, &uOffset);
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_AAC_ADIF_PARSER, uFrameNum, uOffset, ret, 0, 0, 0);
      if(MEDIA_SUCCESS == ret && aacInfo.uFrameDur )
      {
         if(uFrameNum!=0 && uOffset!=0 )
         {
            if(uFrameNum < AAC_ADIF_PARSE_FRAMENUM)
            {     
               contentInfo->time    = (kal_uint64) uFrameNum * aacInfo.uFrameDur / 1000000;
               contentInfo->bitRate = (kal_uint64) uOffset * 1000000000 * 8 / (uFrameNum * aacInfo.uFrameDur);
            }
            else
            {
               uTotalFrameNum = (kal_uint64) uFrameNum * uFileSize / uOffset;
               contentInfo->time    = (kal_uint64) uTotalFrameNum * aacInfo.uFrameDur / 1000000;
               contentInfo->bitRate = (kal_uint64) uFileSize * 1000000000 * 8 / (uTotalFrameNum * aacInfo.uFrameDur);
            }
         }
      }
   }
   else
#endif
   {
      if (uCurOffset >= uFirstFrameOffset)
         uCurOffset -= uFirstFrameOffset;
      if(contentInfo->bitRate)
         contentInfo->time = (kal_uint64)uFileSize * 1000 * 8 / (kal_uint64) contentInfo->bitRate;
   }
   audio_free_mem( (void **) &ihdl );  
   audio_free_mem( (void **) &pBuf );  

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_TOTAL_DUR_META, contentInfo->time);
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_DESCINFO, MEDIA_FORMAT_AAC, MEDIA_SUCCESS);

   return MEDIA_SUCCESS;
}

#if defined(__DSCE_SUPPORT__)
static void aacMedSelectChannel(MHdl *hdl, Media_Channel channel)
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   ASSERT(channel<=MEDIA_CHANNEL_SUB);
   ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamMediaTekAACSelectChannel, &channel);
}
#endif

static kal_uint32 AAC_GetTotalDuration(STFSAL *pstFSAL)
{
   kal_uint32 uTotalDuration = 0;
   audInfoStruct *contentInfo;
   contentInfo = (audInfoStruct*)get_ctrl_buffer( sizeof(audInfoStruct) );
   memset(contentInfo, 0, sizeof(audInfoStruct));
   AAC_GetContentDescInfo( pstFSAL, contentInfo, NULL );
   uTotalDuration = contentInfo->time;
   free_ctrl_buffer( contentInfo );
   return uTotalDuration;
}


static Media_Status aacMedPlay( MHdl *hdl )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   OMX_ERRORTYPE uStatus = OMX_ErrorNone;
#if defined(__AUDIO_NOT_SUPPORTED__)
   return MEDIA_FAIL;
#endif
   PcmSink_TerminateSound();

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY, hdl->mediaType, hdl->state, hdl->GetDataCount(hdl),0,0,0,0);
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->isUnderflow = KAL_FALSE;   
   ihdl->endflag = KAL_FALSE; 
   
   {
      // Start component
      AacDecParam Dec_param;
      AAC_FrameInfo Par_prarm;
      mhdlRefillAndUpdateVideoBuffer(hdl); //call this function, if video eof, hdl->eof will be set. 
      hdl->state = COMPONENT_STATE_PLAY;

      uStatus = ihdl->ParNode.curHdl->Start(ihdl->ParNode.curHdl);
      if(OMX_ErrorContentEndOfFile == uStatus || (OMX_ErrorNone != uStatus && hdl->eof) )
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 0,MEDIA_SEEK_EOF,0,0,0,0);
         return MEDIA_SEEK_EOF;
      }
      else if(OMX_ErrorNone != uStatus)
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 1,MEDIA_FAIL,0,0,0,0);
         return MEDIA_FAIL;
      }

      if(OMX_ErrorNone != ihdl->ParNode.curHdl->SetParameter(ihdl->ParNode.curHdl, OMX_IndexParamAudioAac, &Par_prarm))
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 2,MEDIA_FAIL,0,0,0,0);
         return MEDIA_FAIL;
      }
#if AAC_DSP_COMP
      if(OMX_ErrorNone != ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamAudioDspAac, &Par_prarm))
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 3,MEDIA_FAIL,0,0,0,0);
         return MEDIA_FAIL;
      }
#endif

      if(OMX_ErrorNone != ihdl->DecNode.curHdl->Start(ihdl->DecNode.curHdl))
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 4,MEDIA_FAIL,0,0,0,0);
         return MEDIA_FAIL;
      }

      if(OMX_ErrorNone != ihdl->DecNode.curHdl->SetParameter(ihdl->DecNode.curHdl, OMX_IndexParamAudioAac, &Dec_param))
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 5,MEDIA_FAIL,0,0,0,0);
         return MEDIA_FAIL;
      }
#if AAC_DSP_COMP
//data from PCM route = stereo
      Dec_param.uChannelNum = 2;
#endif
      if( OMX_ErrorNone != AudioDrain_Start(ihdl, Dec_param.uSamplingFreq, Dec_param.uChannelNum))
      {
         if(ihdl->mh.eof)
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 6,MEDIA_SEEK_EOF,0,0,0,0);
            return MEDIA_SEEK_EOF;
         }
         else
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 7,MEDIA_FAIL,0,0,0,0);
            return MEDIA_FAIL;
         }
      }
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_SUCCESS, hdl->mediaType, hdl->state, hdl->GetDataCount(hdl),0,0,0,0);
   return MEDIA_SUCCESS;
}


extern OMX_ERRORTYPE AacPar_Process_internal(AudComHdl *hdl);
static Media_Event aacMedProcess( MHdl *hdl, Media_Event event )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PROCESS, hdl->mediaType, hdl, event, hdl->state, hdl->eof,0,0,0);
   switch(event) {
      case MEDIA_READY_TO_PLAY:
         return event;
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
         if( hdl->state == COMPONENT_STATE_PLAY ) 
         {
            Media_A2V_NOTIFY_MEDIA_END(hdl->Stop, hdl);
         }
         break;
      case MEDIA_ERROR:
      case MEDIA_DECODER_UNSUPPORT:
         hdl->Stop(hdl);
         break;
      case MEDIA_DATA_REQUEST:
      case MEDIA_BUFFER_UNDERFLOW:
      {
         kal_uint32 I;

         if(ihdl->pstFSAL)
         {
            OMX_ERRORTYPE result;
            
            for (I=0; I<AACDEC_PARSER_BUFNUM; I++)
            {
               result = AacPar_Process_internal(ihdl->ParNode.curHdl);
               if (result != OMX_ErrorNone) 
               {
                  return MEDIA_READ_ERROR;
               }
            }
         }
         else
         {
            ACU_SendProcessCommandl((AudComHdlInt *)ihdl->ParNode.curHdl);
         }
         if(!(hdl->pStrmStruct== NULL && ihdl->pstFSAL==NULL))
         {
            hdl->FinishWriteData(hdl);
         }
         if(ihdl->pstFSAL)
         {
            return MEDIA_NONE;
         }
         break;
      }
      default:
         // should never reach here
         ASSERT(0);
   }
   return event;
}

void aacMedSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize )
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   /* make sure 4-byte alignment */
   ASSERT(((uint32)ptr & 0x03) == 0 );
   ihdl->AudioSeekTbl = (AudioSeekTable *)ptr;

   if(ihdl->AudioSeekTbl->CurrentIndex==0)
   {
      AST_InitTable(ihdl->AudioSeekTbl,AAC_AST_MIN_ENTRY_SIZE,usize,aacParseFrame,aacParseFileHeader);
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_AST, hdl, ptr, usize);
}

kal_uint32 aacMedGetTotalDuration_ADIF( MHdl *hdl )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_TOTAL_DUR_NONAST, hdl->uTotalDuration, hdl, 0,0,0,0);
   return hdl->uTotalDuration;
}


static Media_Status aacMedReachValidRegion(MHdl *hdl)
{
   kal_uint32 uFirstFrameOffset, uFrameDur;
   if(AST_SUCCESS != aacParseFileHeader(hdl, &uFirstFrameOffset, &uFrameDur))
   {
      return MEDIA_FILE_INCOMPLETE;
   }
   return MEDIA_SUCCESS;
} 


static const MHPB_CompList AacDecFuncArray[2] = {
   {AacPar_GetMemSize, AacPar_Init, AACDEC_PARSER_BUFSIZE, AACDEC_PARSER_BUFNUM},
   {AacDec_GetMemSize, AacDec_Init, AACDEC_DECODER_BUFSIZE, AACDEC_DECODER_BUFNUM}
};

MHdl *AAC_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   
   if (handler == NULL) 
   {
      MHPB_CompList const *pArray[1] = {NULL};
      
      hdl = MH_Component_List_Open(handler, pstFSAL, pArray);
   } else {
      hdl = MH_Component_Open(handler, pstFSAL, &AacDecFuncArray[0], &AacDecFuncArray[1]);
   }

   hdl->mediaType = MEDIA_FORMAT_AAC;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_OPEN, hdl->mediaType, hdl, handler,0,0,0,0);
   
   hdl->Play    = aacMedPlay;
   hdl->Process = aacMedProcess;

   hdl->SetCacheTbl      = aacMedSetCacheTbl;
   hdl->BuildCache       = AudAstBuildCache;
   hdl->GetCacheDuration = AudAstGetCacheDur;
   hdl->GetTotalDuration = AudAstGetTotalDuration;
   hdl->ReachValidRegion = aacMedReachValidRegion;
#if defined(__DSCE_SUPPORT__)   
   hdl->SelectChannel    = aacMedSelectChannel;
#endif    
   if (pstFSAL) {
      kal_bool bIsADIF;
         
      bIsADIF = AAC_IsADIF(pstFSAL);
      if(bIsADIF) {
         hdl->uTotalDuration = AAC_GetTotalDuration(pstFSAL);
         hdl->GetTotalDuration = aacMedGetTotalDuration_ADIF;
      }
   }
   
   return hdl;
}

#endif //AAC_DECODE
