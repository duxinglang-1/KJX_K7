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
 *  aac_drv.h
 *
 * Project:
 * --------
 *  Maui_sw
 *
 * Description:
 * ------------
 *  AAC Decoder (including SBR decoding) Driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __AAC_DRV_H
#define __AAC_DRV_H

#include "fs_type.h"                         
#include "fsal.h"
#include "mp4_parser.h"

#include "l1audio.h" 
#include "ast.h"
#include "common_def.h"


#if defined(M4A_DECODE)
#define __M4A_FILE_DIRECT_PLAYBACK_SUPPORT__
#endif

#if defined(AAC_PLUS_PS_DECODE) && !defined(LOW_COST_SUPPORT)
#define __ADIF_TOTAL_FRAME_ESTIMATION__  1
#endif

#if !defined(__AUDIO_COMPONENT_SUPPORT__) //prevent build warning
#define MAX_FRAME_CHECK_LEN              2048
#endif

#define ADTS_MAX_SIZE                    6
#define AAC_SAMPLES_PER_FRAME            1024
#define AAC_MAX_SUPPORT_ID_ARRAYS        2
#define AAC_MIN_FRAME_LEN                8
#define AAC_ADTS_PARSE_FRAME_THRESHOLD   100
#define AAC_ADIF_PARSER_BUFFERSIZE       4096
#define AAC_ADIF_PARSE_FRAMENUM          10 //100 
#define AAC_ADTS_PARSE_FRAME_NUM         100
#define AAC_MAX_DATA_REQUESTED           1024
#define ERROR_FRAME_THRESHOLD            0xFFFFFFFF
#define AACPS_PREBUFFER_NUM              4
#define AACPS_PREBUFFER_MASK             0x3
#define VID_DEC_SEEK_HINT_SIZE           2047

extern struct {
   kal_uint32 uCurOffset;
   kal_uint32 uResumeFrameOffset;
} audResumeInfo;

typedef struct {
   kal_uint8    uSbrValid[AACPS_PREBUFFER_NUM];
   kal_uint8    *pPCM2DSP[AACPS_PREBUFFER_NUM];
   kal_uint8    *pSBR2DSP[AACPS_PREBUFFER_NUM];
   void         *pAacDecHdl;
   void         *pInterBuf;
   void         *pTmpBuf;
   void         *pBsBuf;
   void         *pSbrBuf;
   kal_uint32   uSbrBufSize;
   kal_uint32   uBsBufSize;
   kal_uint32   uPreBuffer_R;
   kal_uint32   uPreBuffer_W;
} AacMcuDecode;

typedef struct aacVar{
   kal_bool     bError;
   kal_bool     bDecUnsupport;
   kal_bool     bIsTypeADTS;
   kal_bool     bIsTypeADIF;
   kal_bool     sbrPresentFlag;
   kal_bool     PSPresentFlag;
   kal_bool     sbrParseError;
   kal_bool     stereo;
   kal_uint32   rawDataBlockOffset;
   kal_uint32   bitRate;
   kal_uint32   errorCnt;   // for garbage data
   kal_uint32   framecount;
   kal_uint8    bADTSFixedHeader[4];
   kal_uint8    bHeaderTmp[4];
   kal_uint16   errorReport;
   kal_uint8    sr_idx;
   kal_bool     bIsDSCE;
   kal_bool     bChanSbrFlag[AAC_MAX_SUPPORT_ID_ARRAYS];
   kal_uint8    sbr_chanidx;
   kal_uint8    SCEnum;
   kal_uint8    channelNum;
   Media_Channel channelOutput;
} aacInternal;

typedef struct mh_internal {
   MHdl             mh;
   aacInternal      aac;
   STFSAL           *pstFSAL;
   kal_uint64       uCurFrame;
   kal_uint64       frameDur; // in ms * 10E-6
   kal_uint8        buf[AAC_MAX_DATA_REQUESTED];
   kal_bool         isStreaming;
   kal_bool         isM4AOpened;
   kal_bool         isM4A;
   kal_uint32       fileOffset;
   kal_uint32       resumeFrameOffset;
   kal_uint32       uFileSize;
   kal_uint32       uID3V2Size;
   Media_Event      end_status;
   AudioSeekTable  *AudioSeekTbl;

   // for M4A played back
   FS_FileLocationHint  *pst_vid_seek_hint_M4A;
   STMp4Parser *pstMp4Parser_M4A;
   STFSAL *pstFSALAudio_STSZ_M4A;
   STFSAL *pstFSALAudio_STCO_M4A;
   STFSAL *pstFSALAudio_M4A;
   kal_uint32 *pu_buffer_temp_a_M4A;
   kal_uint32 *pu_buffer_temp_stco_a_M4A;
   kal_uint32 *pu_buffer_temp_stsz_a_M4A;
   kal_uint32 *pu_buffer_STBL_cache_pool_M4A; /* STBL cache pool */
   kal_int32  AAC_DSP_Data_Cnt;
   kal_uint32 uEOF_TimeOutCnt;
   kal_uint16 AAC_DSP_Write_Idx;
   kal_uint16 wDspReadIdx;
   kal_bool   AAC_Decode_EOF;
   kal_bool   fDecoderError;
   kal_bool   fEnableARMDecoder;
   AacMcuDecode     *pAacMcuDec;
   kal_uint16       aud_id_decoder; //for MCU decoder
} aacMediaHdl;

void aacPlusSearchSBR(aacMediaHdl *ihdl);
kal_bool aacSeek( aacMediaHdl *ihdl, kal_bool fCacheEnable );
AST_Status aacASTParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset);
AST_Status aacASTParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);
void aacUpdateSR( aacMediaHdl *ihdl );
Media_Status aacSyncFirstFrame( aacMediaHdl *ihdl );
Media_Status aacSyncFrame(STFSAL *pstFSAL, kal_uint32 *fileOffset, kal_uint8 *pBuf, kal_uint32 uBufSize, void *info);
AST_Status aacParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset, kal_uint32 *uFrameDur);
AST_Status aacParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);
void aacMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize );
void aacMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber);
kal_uint32 aacfMFGetTotalDuration( MHdl *hdl );
kal_uint32 aacMFGetCacheDur(MHdl *hdl);
Media_Status allocWorkingMemM4A(MHdl *hdl);
void freeWorkingMemM4A(MHdl *hdl);
kal_bool openM4aFile( MHdl *hdl, kal_bool fPreporcess );

/* -------------------------------------------------------------------------- */
/* Common part of component and non-component DSP decode def.                 */
/* -------------------------------------------------------------------------- */
#define AAC_STATE_PLAY   1
#define AAC_STATE_PAUSE  2
#define AAC_STATE_IDLE   3

#define DSP_AAC_STATE_IDLE     0
#define DSP_AAC_STATE_START    6
#define DSP_AAC_STATE_PLAYING  2
#define DSP_AAC_STATE_STOP    10
#define DSP_AAC_STATE_END     14

#define AAC_PLUS_INIT                    0x13

#if defined(MT6251)
#define AAC_PAGE_NUM  1
#elif defined(MT6256) || defined(MT6255)
#define AAC_PAGE_NUM  6
#elif defined(MT6250) || defined(MT6260)
#define AAC_PAGE_NUM  5
#else
#define AAC_PAGE_NUM  2
#endif

#endif
