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
 *   aac_seek.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The member function for AAC seek
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(AAC_DECODE)

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "fsal.h"
#include "l1audio.h"
#include "common_def.h"
#include "media.h"
#include "ast.h"
#include "aac_drv.h"
#include "l1sp_trc.h"

#if defined(__AUDIO_COMPONENT_SUPPORT__)
#include "MedAdapt.h"
#endif

#define AAC_CHECK_BYTE 100

#if !defined(__AAC_DECODE_SWIP__)

AST_Status aacASTParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset)
{
   MHdl *hdl = hdlptr;
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;	

   ihdl->fileOffset = 0;
   ihdl->end_status = MEDIA_NONE;	
   hdl->rbInfo.read = 0;
   hdl->rbInfo.write = 0;
   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   hdl->current_time = hdl->start_time;
  
   autSkipID3Tag( hdl, ihdl->pstFSAL, &ihdl->fileOffset, &ihdl->buf[0] );	
   
   if (aacSyncFirstFrame(ihdl)!=MEDIA_SUCCESS )
   {
      return AST_PARSE_FILE_HEADER_FAIL;
   }
   aacUpdateSR(ihdl);
   AST_SetFrameDuration(ihdl->AudioSeekTbl, ihdl->frameDur);
   
   *FirstFrameOffset=ihdl->fileOffset;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_STROFFSET, hdl->mediaType, 0, ihdl->fileOffset );
   return AST_SUCCESS;
}



AST_Status aacASTParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum)
{
   MHdl *hdl = hdlptr;
   aacMediaHdl *ihdl = (aacMediaHdl *)hdl;	
   AST_Status ParseResult; 
   kal_uint32 FrameLength;
   kal_uint32 AccOffset;
   kal_uint32 Remains, uOffset;
   kal_int32 ByteCnt;
   kal_uint32 buf_len;
   kal_uint8  *pbHeader;
   kal_uint32 uCurPos;  
   kal_int32 I;
   hdl->GetWriteBuffer(hdl, &pbHeader, &buf_len);
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
   return ParseResult;
}


kal_bool aacSeek( aacMediaHdl *ihdl, kal_bool fCacheEnable )
{   
   kal_uint32 CurFrames, CurOffset, StartFrame;

   ASSERT(ihdl->frameDur != 0); // memory corrupted
   StartFrame = (kal_uint64)ihdl->mh.start_time * 1000000 / ihdl->frameDur; // calculate start frame count
   CurFrames=StartFrame;

   if(fCacheEnable && ihdl->AudioSeekTbl && (ihdl->AudioSeekTbl->CurrentIndex!=1) )
   {
      CurOffset=AST_Seek((MHdl *)ihdl, ihdl->AudioSeekTbl, &CurFrames);
   }
   else
   {
      CurOffset=ihdl->fileOffset;
      aacASTParseFrame((MHdl *)ihdl, &CurOffset, &CurFrames);
   }

   ihdl->fileOffset = CurOffset;
   ihdl->resumeFrameOffset = CurOffset; // last frame offset aligned frame boundary
   audResumeInfo.uCurOffset = ihdl->resumeFrameOffset;
  
   if (CurFrames != StartFrame)
   {
      ihdl->mh.start_time = ihdl->mh.current_time = (kal_uint64)CurFrames * ihdl->frameDur / 1000000; // update start time
      kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_FAIL, MEDIA_FORMAT_AAC, StartFrame, ihdl->fileOffset, ihdl->mh.start_time);
      return KAL_FALSE;
   }
   else
   {
       kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SEEK_RESULT, MEDIA_FORMAT_AAC, StartFrame, ihdl->fileOffset, ihdl->mh.start_time);
       return KAL_TRUE;
   }
}
#endif //__AAC_DECODE_SWIP__


void aacMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber)
{
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
#else
   aacMediaHdl *ihdl = (aacMediaHdl *) hdl;
#endif
   AST_Status ParseResult;

   if(hdl->uGetDurProgress == 0)
      *uProgress=0;
   else
      *uProgress = hdl->uGetDurProgress;
   
   ParseResult = AST_BuildTable(hdl, ihdl->AudioSeekTbl, uProgress, ihdl->uFileSize ,fLimitFrameNumber);
   if (AST_SUCCESS == ParseResult || AST_PARSE_FRAME_BREAK == ParseResult)
   { 
      *eLastRet = MEDIA_SUCCESS;
   }
   else if (AST_EOF == ParseResult)
   {
      *uProgress=100;
      *eLastRet = MEDIA_SUCCESS;
   }
   else if (AST_PARSE_FRAME_FAIL == ParseResult )
   {
      *uProgress=100;
      *eLastRet = MEDIA_SEEK_FAIL;
   }
   else
   {
       *eLastRet = MEDIA_FAIL;
   }

   hdl->uGetDurProgress = *uProgress;
   if( 100 == hdl->uGetDurProgress )
   {
      *eLastRet = MEDIA_SUCCESS;
      hdl->start_time = 0;
#if defined(__AUDIO_COMPONENT_SUPPORT__)
      ihdl->uOffset = 0;
#else
      ihdl->fileOffset = 0;
#endif
   }
}


void aacMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize )
{
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
#else
   aacMediaHdl *ihdl = (aacMediaHdl *) hdl;
#endif

   ASSERT(((uint32)ptr & 0x03) == 0 );   /* make sure 4-byte alignment */
   ihdl->AudioSeekTbl = (AudioSeekTable *)ptr;

   if(ihdl->AudioSeekTbl->CurrentIndex==0)
   {
#if defined(__AUDIO_COMPONENT_SUPPORT__)
      AST_InitTable(ihdl->AudioSeekTbl,AAC_AST_MIN_ENTRY_SIZE,usize,aacParseFrame,aacParseFileHeader);      
#else
      AST_InitTable(ihdl->AudioSeekTbl,AAC_AST_MIN_ENTRY_SIZE,usize,aacASTParseFrame,aacASTParseFileHeader);
#endif
   }
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_SET_CACHE_TBL, hdl->mediaType );
}


kal_uint32 aacMFGetCacheDur(MHdl *hdl)
{
   kal_uint32 uDur, CurFrames;
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
#else
   aacMediaHdl *ihdl = (aacMediaHdl *) hdl;
#endif
   ASSERT(ihdl->AudioSeekTbl != 0);

   CurFrames=AST_GetIndexedFrames(ihdl->AudioSeekTbl);
   uDur = (kal_uint64)CurFrames*AST_GetFrameDuration(ihdl->AudioSeekTbl)/1000000;
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_DUR, hdl->mediaType, uDur );
   return uDur;
}

kal_uint32 aacfMFGetTotalDuration( MHdl *hdl )
{
   kal_uint32 uDur, TotalFrames;
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
#else
   aacMediaHdl *ihdl = (aacMediaHdl *) hdl;
#endif
   ASSERT(ihdl->AudioSeekTbl != 0);

   autGetFileSize(hdl, ihdl->pstFSAL, &ihdl->uFileSize);
#if defined(__TC01__) && !defined(__AUDIO_COMPONENT_SUPPORT__)
/* under construction !*/
#endif
   {
      if(1==ihdl->AudioSeekTbl->IsFail || 1==ihdl->AudioSeekTbl->IsDone)
      {
         TotalFrames=AST_GetIndexedFrames(ihdl->AudioSeekTbl);
      }
      else
      {
         TotalFrames=AST_EstimateTotalFrames(ihdl->AudioSeekTbl,ihdl->uFileSize);
      }
      if(TotalFrames==0)
      {
         return 0;
      }
      uDur = (kal_uint64)TotalFrames*AST_GetFrameDuration(ihdl->AudioSeekTbl)/1000000;
      if (uDur < ihdl->mh.current_time)
      {
         uDur = ihdl->mh.current_time;
      }
   }
#if defined(__TC01__) && !defined(__AUDIO_COMPONENT_SUPPORT__)
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
   kal_trace( TRACE_GROUP_CACHE, L1AUDIO_CACHE_GET_TOTAL_DUR, hdl->mediaType, uDur );
   return uDur;
}

#endif
