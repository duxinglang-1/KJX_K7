/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   AacParser.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   AAC Parser Component
 *
 * Author:
 * -------
 * -------
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(AAC_DECODE)

#include "audio_enum.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"
#include "fsal.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "l1sp_trc.h"
#include "l1audio.h"
#include "OMX_Core.h"
#include "OMX_Types.h"
#include "OMX_Index.h"
#include "AudCom.h"
#include "AudComUtil.h"
#include "AAC_codec.h"
#include "MedAdapt.h"
#include "media.h"
#include "ast.h"

#define AAC_SAMPLES_PER_FRAME 1024
#define ADTS_MAX_SIZE         6 
#define AAC_ADTS_PARSE_FRAME_THRESHOLD 100
#define AAC_CHECK_BYTE 100

const kal_int32 aacSampleRateTab[9] = {48000,44100,32000,24000,22050,16000,12000,11025,8000};
const kal_uint32 maxByterateFromIndex[9] = { 36000*8, 33076*8, 24000*8, 18000*8, 16538*8,  16000*8, 12000*8, 9000*8, 6000*8 };

Media_Status aacGetByteRate(STFSAL *pstFSAL, AAC_FrameInfo *aacInfo, kal_uint32 uOffset)
{
   kal_uint32 i, accumByte = 0;
   kal_uint8 pbuf[ADTS_MAX_SIZE];

   if(aacInfo->bIsADIF)
      return MEDIA_SUCCESS;

   for (i=0; i<AAC_ADTS_PARSE_FRAME_THRESHOLD; i++) 
   {
      kal_uint32 uReadBytes, uFrameLen;
      uReadBytes = ADTS_MAX_SIZE;

      ACU_GetBytesFromFile(pstFSAL, &uOffset, &uReadBytes, pbuf);
      if (uReadBytes == ADTS_MAX_SIZE) 
      {
         if(!((pbuf[0]==0xFF)&&((pbuf[1]&0xF6) == 0xF0)))
            break;
         uFrameLen = ((pbuf[3]&0x03)<<11) | (pbuf[4]<<3) | (pbuf[5]>>5);
         accumByte += uFrameLen;
         uOffset += uFrameLen;
      }
      else
      {
         break;
      }
   }
   
   if(i)
   {
      aacInfo->uBitRate = ((kal_uint64)accumByte * 1000000000 * 8 / aacInfo->uFrameDur) / i ;
      return MEDIA_SUCCESS;
   }
   return MEDIA_FAIL;
}


Media_Status aacCheckHeader(kal_uint8 *pBuf, AAC_FrameInfo *pInfo)
{
   kal_uint8  protection_absent = 0, no_raw_data_blocks_in_frame = 0;
   kal_uint32 uBitCnt=0;
  
   if ((pBuf[0] == 0xFF) && ((pBuf[1] & 0xF0) == 0xF0)) { /* ADTS */
      /* fixed header, syncword(12) + ID(1) */
      autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      autGetBitsFromBuf(pBuf, &uBitCnt, 5);
      
      /* layer */
      if (autGetBitsFromBuf(pBuf, &uBitCnt, 2) != 0x00) {
         return MEDIA_FAIL;
      }
      
      /* protection absent */
      protection_absent = autGetBitsFromBuf(pBuf, &uBitCnt, 1);
      
      /* profile object type */
      if ( autGetBitsFromBuf(pBuf, &uBitCnt, 2) != 0x01) {
         return MEDIA_FAIL;
      }
      
      /* sampling frequency index */
      pInfo->sr_idx = autGetBitsFromBuf(pBuf, &uBitCnt, 4);
      if (pInfo->sr_idx < 3 || pInfo->sr_idx > 11) {
         return MEDIA_UNSUPPORTED_FREQ;
      }
      pInfo->uSampleRate = aacSampleRateTab[(pInfo->sr_idx)-3];
      /* private bit */
      autGetBitsFromBuf(pBuf, &uBitCnt, 1);
      
      /* channel configuration */
      {
         kal_uint8 channel;
         channel = autGetBitsFromBuf(pBuf, &uBitCnt, 3);
         if ( channel > 0x02)
            return MEDIA_UNSUPPORTED_CHANNEL;
         if ( channel == 2 ) pInfo->bIsStereo = true;
      }
      
      /* original/copy(1), home(1) */ /* copyright bit(1), copyright start(1) */
		  autGetBitsFromBuf(pBuf, &uBitCnt, 4);

	    /* variable header */
		  autGetBitsFromBuf(pBuf, &uBitCnt, 8);
		  autGetBitsFromBuf(pBuf, &uBitCnt, 8);
		  autGetBitsFromBuf(pBuf, &uBitCnt, 8);

		  no_raw_data_blocks_in_frame = autGetBitsFromBuf(pBuf, &uBitCnt, 2);

      if (protection_absent == 0){
         if(no_raw_data_blocks_in_frame){ /* no_raw_data_blocks_in_frame */
            autGetBitsFromBuf(pBuf, &uBitCnt, 8);
            autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         }
         autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      }
      /* cache ADTS Fixed Header */
      kal_mem_cpy(pInfo->bADTSFixedHeader, pBuf, 4);
      pInfo->bADTSFixedHeader[3] &= 0xF0;
      pInfo->bIsTypeADTS = KAL_TRUE;
   }
   else if((pBuf[0] == 'A') && (pBuf[1] == 'D') && (pBuf[2] == 'I') && (pBuf[3] == 'F')) 
   { /* ADIF */
      kal_uint8 num_program_config_elements;
      kal_uint8 uBitstreamType;
      kal_uint32 uBitrate;
      autGetBitsFromBuf(pBuf, &uBitCnt, 8); /* read out 4 bytes */
      autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      if (autGetBitsFromBuf(pBuf, &uBitCnt, 1)) 
      { /* copyright_id_present */
         kal_uint32 uCount;
         for (uCount=0; uCount<9; uCount++)
            autGetBitsFromBuf(pBuf, &uBitCnt, 8);
      }
      autGetBitsFromBuf(pBuf, &uBitCnt, 2); /* origianl copy(1), home(1) */
      uBitstreamType = autGetBitsFromBuf(pBuf, &uBitCnt, 1);

      uBitrate = autGetBitsFromBuf(pBuf, &uBitCnt, 8) |
      ((uint32)autGetBitsFromBuf(pBuf, &uBitCnt, 8) << 8) |
      ((uint32)autGetBitsFromBuf(pBuf, &uBitCnt, 7) << 16);

      num_program_config_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);

      if (0 == uBitstreamType) 
      {
         autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         autGetBitsFromBuf(pBuf, &uBitCnt, 4);
      }
      {
         kal_uint32 uCount,i;
         kal_uint8  num_front_channel_elements, num_side_channel_elements
                  , num_back_channel_elements, num_lfe_channel_elements
                  , num_assoc_data_elements, num_valid_cc_elements, comment_field_bytes;
               /*--- PCE ---*/
         for (uCount = 0; uCount < num_program_config_elements + 1; uCount++)
         {
            autGetBitsFromBuf(pBuf, &uBitCnt, 4); /* element_instance_tag */
            if ( autGetBitsFromBuf(pBuf, &uBitCnt, 2) != 0x01) /* object type */
               return MEDIA_UNSUPPORTED_TYPE;

            pInfo->sr_idx = autGetBitsFromBuf(pBuf, &uBitCnt, 4); 
            if(pInfo->sr_idx < 3 || pInfo->sr_idx > 11)
               return MEDIA_UNSUPPORTED_FREQ;
            pInfo->uSampleRate = aacSampleRateTab[(pInfo->sr_idx)-3]; 
            pInfo->uBitRate = maxByterateFromIndex[(pInfo->sr_idx)-3];
            num_front_channel_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            num_side_channel_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            num_back_channel_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            num_lfe_channel_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 2);
            num_assoc_data_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 3);
            num_valid_cc_elements = autGetBitsFromBuf(pBuf, &uBitCnt, 4);

            if (autGetBitsFromBuf(pBuf, &uBitCnt, 1) == 1)
               autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            if (autGetBitsFromBuf(pBuf, &uBitCnt, 1) == 1)
               autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            if (autGetBitsFromBuf(pBuf, &uBitCnt, 1) == 1)
               autGetBitsFromBuf(pBuf, &uBitCnt, 3);
            for (i = 0; i < num_front_channel_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 5);
            for (i = 0; i < num_side_channel_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 5);
            for (i = 0; i < num_back_channel_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 5);
            for (i = 0; i < num_lfe_channel_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            for (i = 0; i < num_assoc_data_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 4);
            for (i = 0; i < num_valid_cc_elements; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 5);

            uBitCnt += 8-(uBitCnt%8); // byte alignment

            comment_field_bytes = autGetBitsFromBuf(pBuf, &uBitCnt, 8);
            for (i = 0; i < comment_field_bytes; i++)
               autGetBitsFromBuf(pBuf, &uBitCnt, 8);
         }
      }
      pInfo->bIsADIF = KAL_TRUE;
   } 
   else{
      return MEDIA_FAIL;
   }
   if(pInfo->uSampleRate){
      pInfo->uFrameDur = (kal_uint64)AAC_SAMPLES_PER_FRAME * (kal_uint64)1000000000 / pInfo->uSampleRate;
   }
   else{
      pInfo->uFrameDur = 0;
      return MEDIA_FAIL;      
   }
   return MEDIA_SUCCESS;
}


Media_Status aacSyncFrame(STFSAL *pstFSAL, kal_uint32 *fileOffset, kal_uint8 *pBuf, kal_uint32 uBufSize, void *info)
{  
   Media_Status ret;
   kal_uint32 currOffset = 0;
   AAC_FrameInfo *aacInfo = (AAC_FrameInfo *)info;
   memset(aacInfo, 0, sizeof(AAC_FrameInfo));
   while(1) 
   {
      kal_uint8  *ptr, *end;
      kal_uint32 num_bytes, uOffset;
      OMX_ERRORTYPE eResult;
      
      // check if it is out of searching range
      if ( currOffset > MAX_FRAME_CHECK_LEN)
         return MEDIA_BAD_FORMAT;
      
      num_bytes = uBufSize;
      uOffset = *fileOffset;
      eResult = ACU_GetBytesFromFile(pstFSAL, &uOffset, &num_bytes, pBuf);
      // bit-stream should be more than 512 Bytes
      if ( (OMX_ErrorNone != eResult) || (num_bytes < MIN_DATA_LEN) )
         return MEDIA_BAD_FORMAT;
      
      for ( ptr = pBuf, end = (pBuf + num_bytes - MIN_DATA_LEN); ptr < end; ptr++ ) 
      {
         ret = aacCheckHeader( ptr, aacInfo);
         if ( ret == MEDIA_SUCCESS )
         {
            *fileOffset += (uint32)(ptr - pBuf);
            return MEDIA_SUCCESS;
         }
         if ( ret != MEDIA_FAIL )
            return ret;
      }
      if(num_bytes - MIN_DATA_LEN == 0)
      {
         return MEDIA_BAD_FORMAT;
      }
      *fileOffset += num_bytes - MIN_DATA_LEN;
      currOffset  += num_bytes - MIN_DATA_LEN;
   }
}

AST_Status aacParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset, kal_uint32 *uFrameDur)
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdlptr;
   MHdl *hdl = &ihdl->mh; 
   AAC_FrameInfo aacInfo;
   kal_uint32 uCurOffset = 0;
   
   ACU_SkipID3Tag(ihdl->pstFSAL, &uCurOffset, hdl->rbInfo.rb_base);
   if(aacSyncFrame(ihdl->pstFSAL, &uCurOffset, hdl->rbInfo.rb_base, (kal_uint32)hdl->rbInfo.rb_size, &aacInfo)!=MEDIA_SUCCESS )
   {
         return AST_PARSE_FILE_HEADER_FAIL;
   }
   *uFrameDur  = aacInfo.uFrameDur;
   ihdl->frameDur = aacInfo.uFrameDur;
   *FirstFrameOffset=uCurOffset;
   return AST_SUCCESS;
}

AST_Status aacParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum)
{
   MHPB_Internal *ihdl = (MHPB_Internal *)hdlptr;
   MHdl *hdl = &ihdl->mh; 
   AST_Status ParseResult; 
   kal_uint32 FrameLength;
   kal_uint32 AccOffset;
   kal_uint32 Remains, uOffset;
   kal_int32 ByteCnt;
   kal_uint32 buf_len;
   kal_uint8  *pbHeader;
   kal_uint32 uCurPos;  
   kal_int32 I;

   if(hdl->rbInfo.rb_base == NULL)
   {
      buf_len = SEEK_TABLE_BS_BUFFER_LEN;
      pbHeader = (kal_uint8 *)audio_alloc_mem_cacheable(buf_len);
      ASSERT(pbHeader);
   }
   else
   {
      hdl->GetWriteBuffer(hdl, &pbHeader, &buf_len );
   }
  
   ParseResult=AST_SUCCESS;
   AccOffset = *CurOffset;
   
   Remains=*ParseFrameNum;
   uOffset = 0;
   ByteCnt = 0;
   FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);

   while(Remains!=0)
   {
      if(!ByteCnt)
      {
         if((ByteCnt=autGetBytesFromFileNoEnd(hdl, ihdl->pstFSAL, AccOffset, buf_len, pbHeader)) < (ADTS_MAX_SIZE+2))
         {
            ParseResult = AST_EOF;
            break;
         }
      }
      
      if(ByteCnt > AAC_CHECK_BYTE)
      {
         I = AAC_CHECK_BYTE - 7;
      }
      else
      {
         I = ByteCnt - 7;
      }
      
      while(I--)
      {
         if(I==0)
         {
            ParseResult = AST_PARSE_FRAME_FAIL;
            break;
         }
         else if(!((pbHeader[uOffset] == 0xFF)&&((pbHeader[1+uOffset] & 0xF6) == 0xF0)))
         {
            uOffset++;
         }
         else
         {
            FrameLength = ((((uint32)pbHeader[3+uOffset] & 0x3)) << 11) | (((uint32)pbHeader[4+uOffset]) << 3) | (pbHeader[5+uOffset] >> 5) ;
            uOffset += FrameLength;
            Remains --;
            if((uOffset+ 7 + AAC_CHECK_BYTE) > ByteCnt)
            {
               AccOffset+=uOffset;
               uOffset = 0;
               ByteCnt = 0;
            }
            break;
         }
      }
      if(ParseResult == AST_PARSE_FRAME_FAIL)
      {
         break;
      }
   }
   AccOffset+=uOffset;
   *CurOffset=AccOffset;
   *ParseFrameNum -= Remains;
   FSAL_Seek( ihdl->pstFSAL, uCurPos);
   if(hdl->rbInfo.rb_base == NULL)
   {
      audio_free_mem( (void **) &pbHeader);
   }
   return ParseResult;
}

kal_bool aacParSeek( AudComHdl *hdl, kal_bool bEnableAST )
{   
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   AAC_ParData *pParData = (AAC_ParData *)ihdl->pPrivateData;
   AAC_FrameInfo *pFrameInfo = &pParData->FrameInfo;
   kal_uint32 CurFrames, StartFrame;

   if(pFrameInfo->uFrameDur)
   {
      StartFrame = ((kal_uint64)pPBhdl->mh.start_time * 1000000 / pFrameInfo->uFrameDur);
      if ((kal_uint64)pPBhdl->mh.start_time * 1000000 - (StartFrame *pFrameInfo->uFrameDur)){
         StartFrame += 1;
      }
   }
   else
   {
      StartFrame = 0;
      return KAL_FALSE;
   }

   CurFrames=StartFrame;

   if(bEnableAST && pPBhdl->AudioSeekTbl && pPBhdl->AudioSeekTbl->CurrentIndex!=1)
   {
      pParData->uOffset=AST_Seek(ihdl->mhdl, pPBhdl->AudioSeekTbl, &CurFrames);
   }
   else
   {
      aacParseFrame(ihdl->mhdl, &pParData->uOffset, &CurFrames);
   }
   
   pPBhdl->mh.start_time  = (kal_uint32)((kal_uint64)CurFrames * pFrameInfo->uFrameDur / 1000000); // update start time 
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SEEK, MTKAUD_PARSER_AAC, StartFrame,CurFrames,pPBhdl->mh.start_time,pParData->uOffset,0,0);
   if (CurFrames != StartFrame)
   {
      return KAL_FALSE;
   }
   else
   {
      return KAL_TRUE;
   }
}

void aacParSeekWithResume( AudComHdl *hdl )
{   
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   AAC_ParData *pParData = (AAC_ParData *)ihdl->pPrivateData;
   AAC_FrameInfo *pFrameInfo = &pParData->FrameInfo;
   kal_uint32 uResumeFrame, uPauseFrame, uJumpFrame;

   if(pFrameInfo->uFrameDur==0)
   {
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SEEK_RESUME, MTKAUD_PARSER_AAC, 0,0,0,0,0,0);
      return;
   }

   uResumeFrame = (kal_uint64)pPBhdl->mh.start_time * 1000000 / pFrameInfo->uFrameDur;

   ACU_GetResumePoint(&pParData->ResBuf, &pParData->uOffset, &uPauseFrame);

   if(uPauseFrame<uResumeFrame)
   {
      uJumpFrame = uResumeFrame - uPauseFrame;
      aacParseFrame(ihdl->mhdl, &pParData->uOffset, &uJumpFrame);
      uPauseFrame += uJumpFrame;
   }
   ihdl->mhdl->start_time = (kal_uint32)((kal_uint64)uPauseFrame * pFrameInfo->uFrameDur / 1000000); // update start time 
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SEEK_RESUME, MTKAUD_PARSER_AAC, uResumeFrame,uPauseFrame,ihdl->mhdl->start_time,pParData->uOffset,0,0);
}


OMX_ERRORTYPE AacPar_Process_internal(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AAC_ParData *pParData = (AAC_ParData *)ihdl->pPrivateData;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS_I, MTKAUD_PARSER_AAC, ihdl->mediaStatus, ihdl->Decode_EOF,0,0,0,0);
   if(ihdl->mediaStatus != COMPONENT_STATE_PLAY || ihdl->Decode_EOF)
      return OMX_ErrorNone;

   {
      OMX_BUFFERHEADERTYPE *pBufHdr;
      pBufHdr = ACU_GetBufferHeader(hdl, 1);
      if(pBufHdr)
      {
         pBufHdr->pOutputPortPrivate = &ihdl->bsInfo;
      }
   }

   if(pParData->pstFSAL)
   {
      OMX_ERRORTYPE result;
      
      result = ACU_FileRead(hdl, pParData->pstFSAL, &pParData->uOffset);
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_AAC, pParData->uOffset,0,0,0,0,0);
      if(ihdl->isEOF)
      {
         ihdl->Decode_EOF = KAL_TRUE;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_PARSER_AAC, 0,0,0,0,0);
      }
      return result;
   }
   else
   {
      MHdl *medhdl = (MHdl *)ihdl->mhdl;  
      kal_uint8 *pBuf;
      kal_uint32 bsLen, i;
      for(i=0;i<2;i++)
      {
         medhdl->GetReadBuffer(medhdl, &pBuf, &bsLen);
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_AAC, ihdl->mhdl->eof, bsLen,pBuf,0,0,0);
         if((ihdl->mhdl->eof||bsLen) && pBuf)
         {
            ACU_PutToBuffer_Threshold(hdl, pBuf, &bsLen, 512);
            medhdl->ReadDataDone(medhdl, bsLen);
            if(ihdl->isEOF)
            {
               kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_PARSER_AAC, 0,0,0,0,0);
            }
         }
      }
   }
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE AacPar_Process(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AAC_ParData *pParData = (AAC_ParData *)ihdl->pPrivateData;
   MHdl *pMedHdl = (MHdl *)ihdl->mhdl;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_PARSER_AAC, pMedHdl->waiting, ihdl->Decode_EOF,0,0,0,0);
   if (ihdl->Decode_EOF)
   {
      return OMX_ErrorNone;
   }
   if(pParData->pstFSAL == NULL)
   {
      mhdlRefillAndUpdateVideoBuffer(pMedHdl);
      AacPar_Process_internal(hdl);
   }
   if(!pMedHdl->waiting && pMedHdl->pStrmStruct==NULL )
   {
      pMedHdl->handler( pMedHdl, MEDIA_DATA_REQUEST );
      pMedHdl->waiting = KAL_TRUE;   
   }
   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* The private member functions of AAC parser.    */
/*------------------------------------------------*/
static OMX_ERRORTYPE AacPar_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AAC_ParData *pParData = (AAC_ParData *)ihdl->pPrivateData;
   MHdl *medhdl = (MHdl *)ihdl->mhdl;
   Media_Status uResult;
   MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   kal_uint32 streaming = 0;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START, MTKAUD_PARSER_AAC, ihdl->mediaStatus,0,0,0,0);
   ASSERT(ihdl->mediaStatus != COMPONENT_STATE_PLAY);

   {
      //reset data
      ihdl->isEOF = KAL_FALSE;
      ihdl->Decode_EOF = KAL_FALSE;
      ihdl->endStatus = MEDIA_NONE;
      pParData->uOffset = 0;
      pParData->uFileSize = 0;
   }
   
   if(NULL == pParData->pstFSAL)
   {
   	  streaming = 1;
      if(!medhdl->bIsPause)
      {
         FSAL_Status eFSALStatus;
         if(medhdl->rbInfo.write==0)
         {
            return OMX_ErrorUndefined;
         }
         pParData->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
         if(pParData->pstFSAL == NULL)
            return OMX_ErrorUndefined;
         
         FSAL_Direct_SetRamFileSize(pParData->pstFSAL, medhdl->rbInfo.write);
         eFSALStatus = FSAL_Open(pParData->pstFSAL, medhdl->rbInfo.rb_base, FSAL_ROMFILE);
         ASSERT(eFSALStatus == FSAL_OK);
      }
   }
   
   if(pParData->pstFSAL)
   {
      ACU_SkipID3Tag(pParData->pstFSAL, &pParData->uOffset, pParData->pTempBuf);
      uResult = aacSyncFrame(pParData->pstFSAL, &pParData->uOffset, pParData->pTempBuf, AAC_MAX_DATA_REQUESTED, &pParData->FrameInfo);
      if(uResult != MEDIA_SUCCESS)
      {
         if(streaming)
         {
            free_ctrl_buffer(pParData->pstFSAL);
            pParData->pstFSAL = NULL;
         }
         return OMX_ErrorUndefined;
      }
   }

   if(streaming)
   {  
      if(!medhdl->bIsPause)
      {
         medhdl->rbInfo.read = pParData->uOffset;
         free_ctrl_buffer(pParData->pstFSAL);
         }
         pParData->pstFSAL = NULL;
         medhdl->bIsPause = KAL_FALSE;
   }
   else if(!pParData->FrameInfo.bIsADIF)
   {
      if(medhdl->bIsPause && pPBhdl->AudioSeekTbl==NULL)
      {
         aacParSeekWithResume(hdl);
         medhdl->bIsPause = KAL_FALSE;
      }
      else
      {
         if(!aacParSeek(hdl, KAL_TRUE))
         {
            return OMX_ErrorContentEndOfFile;
         }
      }
      FSAL_GetFileSize(pParData->pstFSAL, &pParData->uFileSize);
      if(pParData->uOffset>=pParData->uFileSize)
      {
         return OMX_ErrorContentEndOfFile;
      }

      //for resume
      ihdl->bsInfo.uFrameDur = pParData->FrameInfo.uFrameDur; 
      if(ihdl->bsInfo.uFrameDur)
      {
         ihdl->bsInfo.uCurrentFrame = (kal_uint32)((kal_uint64)pPBhdl->mh.start_time * 1000000 / ihdl->bsInfo.uFrameDur);
      }
      ihdl->bsInfo.uCurrentOffset = pParData->uOffset; 
      ihdl->bsInfo.pResBuf = &pParData->ResBuf; 
   }
   else
   {
      medhdl->start_time = 0;
   }

   ihdl->mediaStatus = COMPONENT_STATE_PLAY; 
   if(pParData->pstFSAL)
   {
      kal_uint32 I;
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START_TIME_OFFSET, MTKAUD_PARSER_AAC, medhdl->start_time, pParData->uOffset,0,0,0,0);
      for (I=0; I<AACDEC_PARSER_BUFNUM; I++) 
      {
         AacPar_Process_internal(hdl);
      }
   }
   else
   {
      ACU_SendProcessCommandl( (AudComHdlInt *)hdl );
   }
   return OMX_ErrorNone;
}


static OMX_ERRORTYPE AacPar_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AAC_ParData *pParData = (AAC_ParData *)ihdl->pPrivateData;

   switch(index)
   {
      case OMX_IndexParamMedFileHandle:
      {
         AcuParseParam *pParam = (AcuParseParam *)pStruct;
         pParData->pstFSAL = pParam->pstFSAL;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_AAC, 0, pParam->pstFSAL, 0,0,0,0,0);
         break;
      }
      case OMX_IndexParamAudioAac:
      {
         AAC_FrameInfo *pParam = (AAC_FrameInfo *)pStruct;
         pParam->uFrameDur   = pParData->FrameInfo.uFrameDur;
         pParam->bIsADIF     = pParData->FrameInfo.bIsADIF;
         pParam->uSampleRate = pParData->FrameInfo.uSampleRate;
         pParam->bIsStereo   = pParData->FrameInfo.bIsStereo;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_PARSER_AAC, 1, pParam->uFrameDur, pParam->bIsADIF,0,0,0,0);
         break;
      }
      default:
         return OMX_ErrorNotImplemented;
   }
   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* The public functions of AAC parser.            */
/*------------------------------------------------*/
OMX_U32 AacPar_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for AAC private data
   uTempSize = (sizeof(AAC_ParData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_GETMEMSIZE, MTKAUD_PARSER_AAC, uReqSizeTotal,0,0,0,0,0);
   return uReqSizeTotal;
   
}

OMX_ERRORTYPE AacPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   //OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   
   *pHandle = NULL;
   
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
      
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   ihdl->pPrivateData = (void *)pBuffer8;
   ihdl->mediaType = MEDIA_FORMAT_AAC;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start        = AacPar_Start;
   ihdl->basic.Process      = AacPar_Process;
   ihdl->basic.SetParameter = AacPar_SetParameter;
   ihdl->basic.Stop         = ACU_ParGenStop;
   ihdl->basic.Deinit       = ACU_GenDeinit;   

   ihdl->mediaStatus = COMPONENT_STATE_READY;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_INIT, MTKAUD_PARSER_AAC, ihdl->mediaStatus,0,0,0,0);
   return OMX_ErrorNone;
}

#endif
