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
 *   AAC_codec.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file of AAC codec.
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

#ifndef AAC_CODEC_DOT_H
#define AAC_CODEC_DOT_H

#include "fs_type.h"
#include "fsal.h"
#include "AudComUtil.h"
#include "common_def.h"
#if defined(M4A_DECODE) || defined(PURE_AUDIO_SUPPORT) || defined(MP4_DECODE)
#include "mp4_parser.h"
#endif

#define AAC_SAMPLES_PER_FRAME 1024
#define AAC_FRAME_PCM_LENGTH 1024
#define AAC_BS_MIN_LENGTH 256

#define AACDEC_PARSER_BUFNUM   6
#define AACDEC_PARSER_BUFSIZE  2048

#define AACDEC_DECODER_BUFNUM  2
#if defined(AAC_PLUS_DECODE) 
#define AACDEC_DECODER_BUFSIZE 1024*2*2*2
#else
#define AACDEC_DECODER_BUFSIZE 1024*2*2
#endif


/*------------------------------------------------*/
/* Common Structure of AAC parser and decoder.    */
/*------------------------------------------------*/
typedef struct {
   // Basic Information
   kal_bool   bIsTypeADTS; 
   kal_bool   bIsStereo;
   kal_bool   bIsADIF;     
   kal_uint8  sr_idx;
   kal_uint8  bADTSFixedHeader[4];    
   kal_uint32 uFrameDur;
   kal_uint32 uSampleRate;
   kal_uint32 uBitRate;
} AAC_FrameInfo;


/*------------------------------------------------*/
/* Structure of AAC+ SBR SWIP decode              */
/*------------------------------------------------*/
typedef struct {
   // PCM and BS information from DSP
   kal_bool   firstHISR;
   kal_bool   SBRdecStart;
   kal_uint16 aac_pcm_pageNum;
   kal_uint16 aacplus_pcm_pageNum;
   kal_uint16 sbr_bs_pageNum;
   kal_uint16 aac_out_pcm_addr;
   kal_uint16 aac_out_sbr_addr;
   kal_uint16 freqIndex;
   kal_uint16 channelNum;
} AAC_SBRDec;


/*------------------------------------------------*/
/* Structure of AAC parser.                       */
/*------------------------------------------------*/
#define AAC_MAX_DATA_REQUESTED  1024
#define MAX_FRAME_CHECK_LEN   (2*1024)
#define MIN_DATA_LEN          8

#define AAC_MAX_ERROR_CNT  0x7FFFFFFF

typedef struct {
   // Frame Information
   AAC_FrameInfo FrameInfo;

   // File information
   kal_bool fMedSet;
   kal_bool uMedFillBuffer;

// Temp buffer
   kal_uint8 pTempBuf[AAC_MAX_DATA_REQUESTED];
   
   kal_uint32 uFileSize;
   kal_uint32 uOffset;
   
   STFSAL stFSAL;
   STFSAL *pstFSAL;

   AudResumeBuffer ResBuf;
} AAC_ParData;

/*------------------------------------------------*/
/* Structure of AAC decoder.                      */
/*------------------------------------------------*/

typedef struct {
   // Frame Information
   AAC_FrameInfo FrameInfo;
#if defined(AAC_PLUS_DECODE)     
   AAC_SBRDec    AACSBRDec;
#endif   
   void *aacDecHdl;
   void *InterBuf;
   void *TmpBuf;
   void *PcmBuf;
   void *BsBuf;
   void *SbrBuf;   
   void *SbrBSBuf;
   void *TmpPcmBuf;

   kal_uint64 uCurFrame;
    
   kal_uint32 resumeFrameOffset; 
   kal_uint32 uInterBufSize;
   kal_uint32 bsBuf_size;
   kal_uint32 bsBuf_r;
   kal_uint32 bsBuf_w;
   kal_uint32 pcm_size;
   kal_uint32 pcm_buf_r;

   kal_uint32 uDecFrameNum;

   // Flag
   kal_uint8 uErrorCnt;
   kal_bool  bDecUnsupport;
   kal_bool  bError;
   kal_bool  bUnderflow;
#if defined(AAC_PLUS_DECODE)     
   kal_bool  bDisableSbr;
#endif    
   kal_bool  isPageLock;
} AAC_DecData;

#if defined(M4A_DECODE) || defined(PURE_AUDIO_SUPPORT) || defined(MP4_DECODE)
typedef struct {
   STFSAL *pstFSAL;
   kal_uint32 uFileSize;
   kal_uint32 uOffset;

   // Seek info
   kal_uint32 uStartTime; //ms

   FS_FileLocationHint  *pst_vid_seek_hint_M4A;
   STMp4Parser *pstMp4Parser_M4A;
   STFSAL *pstFSALAudio_STSZ_M4A;
   STFSAL *pstFSALAudio_STCO_M4A;
   STFSAL *pstFSALAudio_M4A;
   kal_uint32 *pu_buffer_temp_a_M4A;
   kal_uint32 *pu_buffer_temp_stco_a_M4A;
   kal_uint32 *pu_buffer_temp_stsz_a_M4A;
   kal_uint32 *pu_buffer_STBL_cache_pool_M4A; /* STBL cache pool */
} M4A_ParData;
#endif

Media_Status aacGetByteRate(STFSAL *pstFSAL, AAC_FrameInfo *aacInfo, kal_uint32 uOffset);

#endif
