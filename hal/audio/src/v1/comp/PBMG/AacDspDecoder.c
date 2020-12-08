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
 *   AacDecoder.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The basic functions of AAC decoder.
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
 *============================================================================
 ****************************************************************************/

#ifdef AAC_DECODE

#include "kal_trace.h"
#include "audio_def.h"
#include "speech_def.h"
#include "common_def.h"
#include "l1sp_trc.h"
#include "audio_enum.h"
#include "ddload.h"
#include "AudComUtil.h"
#include "AAC_codec.h"
#include "aac_drv.h"  
#include "am.h"
#include "aac_dec_exp.h"
#include "media.h"
#include "pcmsink.h"

extern const kal_uint8 SampleRateTable[];

#if defined(AAC_PLUS_DECODE)
#include "heaac_dec_exp.h"

#define AAC_PCM_OUT_LENGTH    2048 //4096 bytes
#define AAC_SBRBS_OUT_LENGTH  142  //284  bytes

extern const kal_int32 aacSampleRateTab[9];
#endif

extern kal_bool Is_PutPcmrutOn(void);
extern void PcmSink_Mute(kal_bool fMute, kal_uint32 uFunction);
extern void AFE_SetHardwareMute(bool mute);
extern void AFE_SetDigitalGain( kal_uint8 aud_func, kal_uint8 level );

#if defined(__AAC_DSP_DEBUG__)

#include "med_utility.h"
#include "fsal.h"

#define DEBUF_BUFFER_SIZE 0x8000
#define DEBUF_BUFFER_MASK 0x7FFF

static kal_char AAC_DEBUG_FILENAME1[30]="aac_checksum.log";
static kal_char AAC_DEBUG_FILENAME2[30]="aac_debug.log";

static struct{
   kal_wchar  filename_rec1[40];
   kal_wchar  filename_rec2[40];

   kal_uint16 pCHECKSUM_1[DEBUF_BUFFER_SIZE];
   kal_uint16 pCHECKSUM_2[DEBUF_BUFFER_SIZE];
   kal_uint16 pCHECKSUM_3[DEBUF_BUFFER_SIZE]; 
   kal_uint16 pDEBUG_01_1[DEBUF_BUFFER_SIZE];
   kal_uint16 pDEBUG_01_2[DEBUF_BUFFER_SIZE];
   kal_uint16 pDEBUG_01_3[DEBUF_BUFFER_SIZE];
   kal_uint16 pDEBUG_01_4[DEBUF_BUFFER_SIZE];
   kal_uint16 pDEBUG_02_1[DEBUF_BUFFER_SIZE];
   kal_uint16 pDEBUG_02_2[DEBUF_BUFFER_SIZE];
   //kal_uint16 pDEBUG_02_3[DEBUF_BUFFER_SIZE];
   //kal_uint16 pDEBUG_03_1[DEBUF_BUFFER_SIZE];
   //kal_uint16 pDEBUG_03_2[DEBUF_BUFFER_SIZE];
   //kal_uint16 pDEBUG_03_3[DEBUF_BUFFER_SIZE];
   //kal_uint16 pDEBUG_04_1[DEBUF_BUFFER_SIZE];
   //kal_uint16 pDEBUG_04_2[DEBUF_BUFFER_SIZE];
   //kal_uint16 pDEBUG_04_3[DEBUF_BUFFER_SIZE];
   kal_uint8  pStrBuf[256];
   kal_uint8  pFsalBuffer1[2048];
   kal_uint8  pFsalBuffer2[2048];
   kal_uint32 uRead;
   kal_uint32 uWrite;
   kal_bool   fIsRunning;
   kal_bool   fIsWaiting;
   kal_bool   fIsUnderflow;
   STFSAL     FSAL1;
   STFSAL     FSAL2;
}aacdebug;

static void aacDec_DebugCallback(kal_uint32 arg1, void* arg2)
{
   kal_uint32 i, uIndex, uWriteCnt;
   if(!aacdebug.fIsRunning)
   {
      return;
   }
   uWriteCnt = aacdebug.uWrite - aacdebug.uRead;
   for(i=0;i<uWriteCnt;i++)
   {
      uIndex = aacdebug.uRead & DEBUF_BUFFER_MASK;
      kal_sprintf((void*)aacdebug.pStrBuf, "Frame Cnt: %08d, %.4x, %.4x, %.4x\n", aacdebug.uRead, 
                                                                 (kal_int32)aacdebug.pCHECKSUM_1[uIndex], 
                                                                 (kal_int32)aacdebug.pCHECKSUM_2[uIndex],
                                                                 (kal_int32)aacdebug.pCHECKSUM_3[uIndex]);
      FSAL_Write(&aacdebug.FSAL1, aacdebug.pStrBuf, strlen((void*)aacdebug.pStrBuf));
/*
      kal_sprintf((void*)aacdebug.pStrBuf, "Frame Cnt: %08d,%.4x, %.4x, %.4x, %.4x, %.4x, %.4x, %.4x, %.4x, %.4x, %.4x, %.4x, %.4x, %.4x\n", aacdebug.uRead,
                                                                 (kal_int32)aacdebug.pDEBUG_01_1[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_01_2[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_01_3[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_01_4[uIndex], 

                                                                 (kal_int32)aacdebug.pDEBUG_02_1[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_02_2[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_02_3[uIndex],
                                                                 
                                                                 (kal_int32)aacdebug.pDEBUG_03_1[uIndex],
                                                                 (kal_int32)aacdebug.pDEBUG_03_2[uIndex],
                                                                 (kal_int32)aacdebug.pDEBUG_03_3[uIndex],
                                                                 
                                                                 (kal_int32)aacdebug.pDEBUG_04_1[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_04_2[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_04_3[uIndex]);
*/
      kal_sprintf((void*)aacdebug.pStrBuf, "Frame Cnt: %08d,%.4x, %.4x, %.4x, %.4x, %.4x, %.4x\n", aacdebug.uRead,
                                                                 (kal_int32)aacdebug.pDEBUG_01_1[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_01_2[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_01_3[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_01_4[uIndex], 

                                                                 (kal_int32)aacdebug.pDEBUG_02_1[uIndex], 
                                                                 (kal_int32)aacdebug.pDEBUG_02_2[uIndex]);

      FSAL_Write(&aacdebug.FSAL2, aacdebug.pStrBuf, strlen((void*)aacdebug.pStrBuf));
      aacdebug.uRead++;
   }
   aacdebug.fIsWaiting = KAL_FALSE;
}

static void aacDec_DebugHisr()
{
   kal_uint32 uIndex;
   ASSERT(aacdebug.uWrite - aacdebug.uRead <= DEBUF_BUFFER_SIZE );
   uIndex = aacdebug.uWrite & DEBUF_BUFFER_MASK;
   aacdebug.pCHECKSUM_1[uIndex] = *AAC_DSP_REPORT;
   aacdebug.pCHECKSUM_2[uIndex] = *AAC_Final_Checksum;
   aacdebug.pCHECKSUM_3[uIndex] = *AAC_Table_Checksum;
   aacdebug.pDEBUG_01_1[uIndex] = *AAC_DSP_AFT_READSPECTAL;
   aacdebug.pDEBUG_01_2[uIndex] = *AAC_DSP_AFT_SCALESPECTRAL;
   aacdebug.pDEBUG_01_3[uIndex] = *AAC_DSP_BEF_FFT;
   aacdebug.pDEBUG_01_4[uIndex] = *AAC_DSP_AFT_FFT;
   aacdebug.pDEBUG_02_1[uIndex] = *AAC_DSP_PreviousData;
   aacdebug.pDEBUG_02_2[uIndex] = *AAC_DSP_BEF_WIND;
   //aacdebug.pDEBUG_02_3[uIndex] = *AAC_DSP_AFT_WIND;
   //aacdebug.pDEBUG_03_1[uIndex] = *AAC_IO_CHKSUM_ENABLE;
   //aacdebug.pDEBUG_03_2[uIndex] = *AAC_IO_CHKSUM_VALUE;
   //aacdebug.pDEBUG_03_3[uIndex] = *DBG_IO_ENA_CHG_IMASK;
   //aacdebug.pDEBUG_04_1[uIndex] = *DBG_IO_CHG_IMASK_VALUE;
   //aacdebug.pDEBUG_04_2[uIndex] = *DBG_IO_CHKSUM_SET_OUTPUT_PMPTR;
   //aacdebug.pDEBUG_04_3[uIndex] = *DBG_IO_ENA_CHKSUM_ONPM;
   aacdebug.uWrite++;
   //if((aacdebug.uWrite - aacdebug.uRead) > (DEBUF_BUFFER_SIZE>>2))
   {
      if(!aacdebug.fIsWaiting)
      {
         //aacdebug.fIsWaiting = KAL_TRUE;
         //L1Audio_InProcCall(aacDec_DebugCallback, NULL, NULL);
      }
   }
}

static void aacDec_DebugStop()
{
   if(!aacdebug.fIsRunning)
   {
      return;
   }
   aacDec_DebugCallback(NULL,NULL);
   if(aacdebug.fIsUnderflow)
   {
      kal_sprintf((void*)aacdebug.pStrBuf, "Underflow Happened!\n");
      FSAL_Write(&aacdebug.FSAL1, aacdebug.pStrBuf, strlen((void*)aacdebug.pStrBuf));
      FSAL_Write(&aacdebug.FSAL2, aacdebug.pStrBuf, strlen((void*)aacdebug.pStrBuf));
   }
   aacdebug.fIsRunning = KAL_FALSE;
   FSAL_Close( &aacdebug.FSAL1 );
   FSAL_Close( &aacdebug.FSAL2 );
}

static void aacDec_DebugStart()
{
   kal_int16 drv_letter;
   memset(&aacdebug, 0, sizeof(aacdebug));
   FSAL_SetBuffer( &aacdebug.FSAL1  , 256, aacdebug.pFsalBuffer1 );   
   FSAL_SetBuffer( &aacdebug.FSAL2  , 256, aacdebug.pFsalBuffer2 );   
   drv_letter = FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE );  //SD CARD
   kal_wsprintf( aacdebug.filename_rec1, "%c:\\%s", drv_letter, &AAC_DEBUG_FILENAME1 );
   kal_wsprintf( aacdebug.filename_rec2, "%c:\\%s", drv_letter, &AAC_DEBUG_FILENAME2 );
   if( FSAL_OK != FSAL_Open( &aacdebug.FSAL1, aacdebug.filename_rec1, FSAL_WRITE ) )
   {
      ASSERT(0);
   }
   if( FSAL_OK != FSAL_Open( &aacdebug.FSAL2, aacdebug.filename_rec2, FSAL_WRITE ) )
   {
      ASSERT(0);
   }
   aacdebug.fIsRunning = KAL_TRUE;
}

#endif

/*------------------------------------------------*/
/* The private functions of AAC decoder.          */
/*------------------------------------------------*/
#if defined(AAC_PLUS_DECODE) 
static Media_Status Aac_ChkSBR(AudComHdlInt *ihdl){
	
	 AudComHdl *hdl = (AudComHdl *)ihdl;
   
   kal_uint32 uInLen=0, uOutLen=0;
   kal_int32 consumBsLen, sStatus;
   kal_uint8 *pInBuf, *pOutBuf;
   
   AACDEC_Handle *pAacDecHdl = NULL;
   
   AAC_DecData *pDecData = (AAC_DecData *)ihdl->pPrivateData;   
      
   ACU_GetReadBuffer(hdl, &pInBuf, &uInLen);   
   ACU_GetWriteBuffer(hdl, &pOutBuf, &uOutLen);
   
   //Init decoder, reuse heaac buffer
   pAacDecHdl  = (void*)AACDec_Init( pDecData->InterBuf, pDecData->SbrBSBuf);
   ASSERT(pAacDecHdl);
   
   sStatus = AACDec_DecodeFrame(pAacDecHdl, pOutBuf, pDecData->TmpBuf, (const void*)pInBuf, (int)uInLen, (const void*)pInBuf, &consumBsLen);
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_AAC_DECODE, 0 , consumBsLen, sStatus, pAacDecHdl->sbrFlag, pAacDecHdl->sampleRate, 0);
   if(pAacDecHdl->sampleRate !=pDecData->FrameInfo.uSampleRate){
   	   if(ihdl->mhdl->eof){
   	   	  pDecData->bDisableSbr = KAL_TRUE;
   	   	  mhdlException( ihdl->mhdl , MEDIA_END );
   	   	  return MEDIA_SUCCESS;
   	   }
   	   else{
   	      mhdlException( ihdl->mhdl , MEDIA_ERROR );
   	      return  MEDIA_FAIL;
   	   }
   }

   if((pAacDecHdl->sbrFlag!=1) || (pAacDecHdl->sbrFlag && pAacDecHdl->sampleRate >24000))
   {
      pDecData->bDisableSbr = KAL_TRUE;
   }
   return MEDIA_SUCCESS;
}
#endif

static OMX_ERRORTYPE AacDec_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
     AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
     AAC_DecData *pDecData = (AAC_DecData *)ihdl->pPrivateData;
	   switch(index)
	   {
	      case OMX_IndexParamAudioAac:
        {
          AacDecParam *pParam = (AacDecParam *)pStruct;
          pParam->uSamplingFreq  = pDecData->FrameInfo.uSampleRate;
          pParam->uChannelNum    = (pDecData->FrameInfo.bIsStereo)?2:1;
          kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_DECODER_AAC, 0, pParam->uSamplingFreq, pParam->uChannelNum,0,0,0,0);
          break;
        }
	      case OMX_IndexParamAudioDspAac:
        {
          AAC_FrameInfo *pParam = (AAC_FrameInfo *)pStruct;
          pDecData->FrameInfo.uFrameDur    = pParam->uFrameDur;
          pDecData->FrameInfo.bIsADIF      = pParam->bIsADIF;
          pDecData->FrameInfo.uSampleRate  = pParam->uSampleRate;
          pDecData->FrameInfo.bIsStereo    = pParam->bIsStereo;   
          kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_DECODER_AAC, 1, pParam->uFrameDur, pParam->bIsADIF,pParam->uSampleRate,pParam->bIsStereo,0,0);
          break;
        }default:
          return OMX_ErrorNotImplemented;
     }
     return OMX_ErrorNone;
}

#if defined(AAC_PLUS_DECODE)
static void aacGetData_skip1(kal_uint16 *dst, kal_uint16 *src, kal_uint32 length)
{
   kal_int32 i;
   for( i = length; i > 0; i-- )
   {
       *dst++ = *src++;
       *src++;
   }
}


static void aacGetDataFromDSP( AudComHdlInt *ihdl )
{
   volatile kal_uint16 *idmaPtr_pcm, *idmaPtr_sbrps;
   AAC_DecData *pDecData = (AAC_DecData *)ihdl->pPrivateData;
   
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_DECODER_AAC, 1,pDecData->AACSBRDec.SBRdecStart,0,0,0,0);
   
   if(pDecData->AACSBRDec.SBRdecStart)
   	  return;
   //clear tmpbuf
   memset(pDecData->TmpPcmBuf, 0, pDecData->pcm_size);
   
   pDecData->AACSBRDec.aac_pcm_pageNum     = (*AAC_OUT_DATA_PAGENUM) & 0x000F;   
   pDecData->AACSBRDec.sbr_bs_pageNum      = ((*AAC_OUT_DATA_PAGENUM) >> 4) & 0x000F;
   pDecData->AACSBRDec.channelNum          = (*AAC_DSPDEC_FOR_SBR)& 0x000F; 
   pDecData->AACSBRDec.freqIndex           = ((*AAC_DSPDEC_FOR_SBR) >> 4)& 0x000F;   
   pDecData->AACSBRDec.aac_out_pcm_addr    = (*AAC_OUT_PCM_ADDRESS) & 0x3FFF;
   pDecData->AACSBRDec.aac_out_sbr_addr    = (*AAC_OUT_SBRBS_ADDRESS)& 0x3FFF;
   
   idmaPtr_pcm   = DSP_DM_ADDR( pDecData->AACSBRDec.aac_pcm_pageNum, pDecData->AACSBRDec.aac_out_pcm_addr);
   idmaPtr_sbrps = DSP_DM_ADDR( pDecData->AACSBRDec.sbr_bs_pageNum,  pDecData->AACSBRDec.aac_out_sbr_addr);
   IDMA_ReadFromDSP( (kal_uint16 *)pDecData->TmpPcmBuf,  idmaPtr_pcm,   AAC_PCM_OUT_LENGTH);
   IDMA_ReadFromDSP( (kal_uint16 *)pDecData->SbrBSBuf, idmaPtr_sbrps, AAC_SBRBS_OUT_LENGTH);
   
   if(pDecData->AACSBRDec.channelNum ==1)
   {
   	   aacGetData_skip1(pDecData->PcmBuf, pDecData->TmpPcmBuf, AAC_PCM_OUT_LENGTH>>1);
   	   pDecData->AACSBRDec.SBRdecStart = KAL_TRUE;
   }
   else if(pDecData->AACSBRDec.channelNum ==2)
   {
   	   memcpy((OMX_U8*)pDecData->PcmBuf ,(OMX_U8*)pDecData->TmpPcmBuf ,AAC_PCM_OUT_LENGTH*2*sizeof(OMX_U8)); //bytes
       pDecData->AACSBRDec.SBRdecStart = KAL_TRUE;
   }
   else
   {  // if decode data is not avalible, fill 0
   	   memset(pDecData->PcmBuf, 0, pDecData->pcm_size);
   }
}


static void Aac_SBRDecodeTask(void *data)
{
	 AudComHdlInt *ihdl = (AudComHdlInt *)data;
	 AudComHdl *hdl = (AudComHdl *)ihdl;
	 AAC_DecData *pDecData = (AAC_DecData *)ihdl->pPrivateData;
	 
	 kal_uint32 SampleRate = 0, freelen = 0;
   OMX_U32 pcmbufsize = 0, tmpsize = 0;
   OMX_U8 *pcm_buf = NULL;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEC_OK, MTKAUD_DECODER_AAC, 0, 0, 0, 0, 0,0);

   ACU_GetWriteBuffer(hdl, &pcm_buf, &pcmbufsize);
   if(pcmbufsize==0)
       return;
   
   SampleRate = aacSampleRateTab[(pDecData->AACSBRDec.freqIndex)-3];

   HEAAC_SBRDec_DecodeFrame(pDecData->aacDecHdl, 
                            pDecData->PcmBuf, 
                            pDecData->TmpBuf, 
                            pDecData->SbrBSBuf,
                            SampleRate,
                            pDecData->AACSBRDec.channelNum );
                           
   if(pcmbufsize >= pDecData->pcm_size){
        memcpy((OMX_U8*)pcm_buf ,(OMX_U8*)pDecData->PcmBuf ,pDecData->pcm_size*sizeof(OMX_U8));
        ACU_WriteDataDone_ImmediateCallback(hdl, pDecData->pcm_size);
        kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEC_OK, MTKAUD_DECODER_AAC, 1, 0, 0, 0, 0,0);
   } 
   else{
   	    memcpy((OMX_U8*)pcm_buf ,(OMX_U8*)pDecData->PcmBuf ,pcmbufsize*sizeof(OMX_U8));
   	    ACU_WriteDataDone(hdl, pcmbufsize);   	    
   	    ACU_GetWriteBuffer(hdl, &pcm_buf, &tmpsize);
   	    if(pcm_buf){   	    	  
   	    	  if (tmpsize < pDecData->pcm_size-pcmbufsize){
   	    	     freelen = tmpsize;
   	    	     kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEC_OK, MTKAUD_DECODER_AAC, 2, 0, 0, 0, 0,0);
   	    	  }
   	    	  else 
   	    	  	 freelen = pDecData->pcm_size-pcmbufsize;
   	        
   	        memcpy((OMX_U8*)pcm_buf ,(OMX_U8*)pDecData->PcmBuf+pcmbufsize , freelen*sizeof(OMX_U8));
   	        ACU_WriteDataDone_ImmediateCallback(hdl, freelen);
   	    } //else: Buffer overflow
   }
   pDecData->AACSBRDec.SBRdecStart = KAL_FALSE;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEC_OK, MTKAUD_DECODER_AAC, 3, freelen, 0, 0, 0, 0);
}
#endif

static void aacWriteZero( AudComHdlInt *ihdl )
{
   int32 I, count, len;
   uint16 rb_w;

   rb_w = *AAC_MCU_WRITE_PTR;

   do {
      I = (int32)*AAC_DSP_READ_PTR;
   } while( I != (int32)*AAC_DSP_READ_PTR );

   I = I - (int32)rb_w - 1;
   if ( I < 0 )
      I += ihdl->dsp_rb_size;

   count = (int32)(ihdl->dsp_rb_end - rb_w);

   if (count > I)
      count = I;

   len = I;

#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260)        
       IDMA_FillToDSP((kal_uint16*)DSP_DM_ADDR(AAC_PAGE_NUM, rb_w), 0, count );
#else
       IDMA_FillToDSP((kal_uint16*)DSP_PM_ADDR(AAC_PAGE_NUM, rb_w), 0, count );
#endif

   rb_w += (uint16)count;
   if ( rb_w >= ihdl->dsp_rb_end )
      rb_w = ihdl->dsp_rb_base;
   *AAC_MCU_WRITE_PTR = rb_w;

   count = len - count;
   if ( count > 0 ) {
#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260)    
      IDMA_FillToDSP((kal_uint16*)DSP_DM_ADDR(AAC_PAGE_NUM, rb_w), 0, count );
#else   	
      IDMA_FillToDSP((kal_uint16*)DSP_PM_ADDR(AAC_PAGE_NUM, rb_w), 0, count );
#endif
      *AAC_MCU_WRITE_PTR = rb_w + (uint16)count;
   }
}

static kal_int32 aacGetDSPIncOffset( AudComHdlInt *ihdl )
{
   int32 I;
   uint16 rb_r;

   rb_r = ihdl->wDspReadIdx;

   do {
      I = (int32)*AAC_DSP_READ_PTR;
   } while( I != (int32)*AAC_DSP_READ_PTR );

   ihdl->wDspReadIdx = I;

   I = I - (int32)rb_r;
   if( I < 0 )
      I += ihdl->dsp_rb_size;

   return (I<<1);  // total data size in byte
}

static kal_int32 aacGetDSPDataCnt( AudComHdlInt *ihdl, kal_uint16 dspWriteIdx )
{
   int32 I;
   uint16 rb_w;

   if (dspWriteIdx == 0xFFFF){
      rb_w = *AAC_MCU_WRITE_PTR;
      ihdl->DSP_Write_Idx = rb_w;
   }else
      rb_w = dspWriteIdx;

   do {
      I = (int32)*AAC_DSP_READ_PTR;
   } while( I != (int32)*AAC_DSP_READ_PTR );

   I = I - (int32)rb_w - 1;
   if( I < 0 )
      I += ihdl->dsp_rb_size;

   return (ihdl->dsp_rb_size - I);  // total data size in word
}


static void AacDecHisrHandler(void *hComponent)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hComponent;
   AAC_DecData *pDecData;
   
   pDecData = (AAC_DecData *)ihdl->pPrivateData;

#if defined(_DSP_INTERSHAREMEM_EN_)    
   *DP2_AUDIO_ASP_TASK4_DM_HANDSHAKE = 0; 
#endif
 
   
#if defined(__AAC_DSP_DEBUG__)
   aacDec_DebugHisr();
#endif   
   
   // To avoid re-entry
   if( ihdl->endStatus == MEDIA_TERMINATED )
      return;
      
#if VERIFY_AVSYNC
   ut_avsync_play_hisr();
#endif      
   
   if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_IDLE ) {  // DSP in idle state
      
      if (KAL_TRUE == pDecData->bDecUnsupport){
         ihdl->data = MEDIA_DECODER_UNSUPPORT;
         // KH: Should notify EventHandler
      } else if (KAL_TRUE == pDecData->bError) {
         ihdl->data = MEDIA_ERROR;
         // KH: Should notify EventHandler
      } else if(ihdl->endStatus == MEDIA_STOP_TIME_UP){
         ihdl->isDspDecodeEOF =KAL_TRUE;
         ihdl->data = MEDIA_STOP_TIME_UP;
      }  
      else {       
         ACU_DSPEofHandler(ihdl);
         return;
      }

      mhdlException( ihdl->mhdl , (Media_Event)ihdl->data );

      kal_dev_trace( TRACE_STATE, AAC_L1AUDIO_IDLE_STATE);
      ihdl->endStatus = MEDIA_TERMINATED;
      return;
   }

   if ( ihdl->endStatus == MEDIA_END || ihdl->endStatus == MEDIA_STOP_TIME_UP || ihdl->endStatus == MEDIA_ERROR )
      return;

   /* bypass the buffer underflow warning from DSP */
   if ((*AAC_ERROR_REPORT != 0)&& (*AAC_ERROR_REPORT != 0x2222))
   {
      if (ihdl->Decode_EOF){
         ihdl->endStatus = MEDIA_END;
         if ( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
            *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
   	     kal_dev_trace( TRACE_STATE, AAC_L1AUDIO_END_STATE);
         return;
      }
      /* check if DSP reports error */
      ihdl->errorReport = *AAC_ERROR_REPORT;
      pDecData->uErrorCnt++;
      kal_dev_trace( TRACE_ERROR, AAC_L1AUDIO_ERROR_REPORT, (kal_uint32)pDecData->uCurFrame, ihdl->errorReport, pDecData->uErrorCnt);     
      
      if(pDecData->uErrorCnt >= ERROR_FRAME_THRESHOLD || pDecData->FrameInfo.bIsADIF) 
      {
         ihdl->endStatus = MEDIA_ERROR;
         *AAC_MAIN_CONTROL = DSP_AAC_STATE_STOP;
         if (*AAC_ERROR_REPORT == 0x1111)
            pDecData->bDecUnsupport = KAL_TRUE;
         else
            pDecData->bError = KAL_TRUE;
         return;
      }
   }
   else if(pDecData->uErrorCnt<ERROR_FRAME_THRESHOLD)
   {
      // if not consecutive, reset to 0
      pDecData->uErrorCnt = 0;
   }
   // update current time and file offset
   if (ihdl->wDspReadIdx != 0xFFFF){
      kal_int32 iFrameOffset;
      iFrameOffset = aacGetDSPIncOffset( ihdl );
      if (iFrameOffset){ // Don't increase current time as buffer underflow
      	 ACU_SetResumePoint(ihdl->bsInfo.pResBuf, ihdl->bsInfo.uCurrentOffset, ihdl->bsInfo.uCurrentFrame);
         ihdl->bsInfo.uCurrentOffset += iFrameOffset;
         pDecData->uCurFrame++;
         ihdl->bsInfo.uCurrentFrame  =  pDecData->uCurFrame;
         ihdl->mhdl->current_time = pDecData->uCurFrame * pDecData->FrameInfo.uFrameDur / 1000000;
      }
   }

   if ( ihdl->dsp_rb_base == 0 ) {   // DSP RingBuf initialization
      ihdl->dsp_rb_base = *AAC_FIFO_BASE;
      ihdl->dsp_rb_size = *AAC_FIFO_LENGTH;
      ihdl->dsp_rb_end = ihdl->dsp_rb_base + ihdl->dsp_rb_size;
      ihdl->wDspReadIdx = *AAC_DSP_READ_PTR;
   }

   if( ihdl->mhdl->current_time >= ihdl->mhdl->stop_time ) 
   {
      ihdl->endStatus = MEDIA_STOP_TIME_UP;
      if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
      {
         *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
      }
      kal_brief_trace( TRACE_STATE, AAC_L1AUDIO_STOP_TIME_UP_STATE);            
      return;
   }

#if defined(AAC_PLUS_DECODE) 
   if(!pDecData->bDisableSbr && !pDecData->AACSBRDec.firstHISR)
   {
      aacGetDataFromDSP(ihdl);
   }
   if(!pDecData->bDisableSbr && !pDecData->AACSBRDec.firstHISR && pDecData->AACSBRDec.SBRdecStart)
   {
      if(!ihdl->mhdl->isUnderflow)
	      L1Audio_SetEvent( ihdl->aud_id_decoder, ihdl );
   }
   pDecData->AACSBRDec.firstHISR = KAL_FALSE;
#endif //// #ifdef AAC_PLUS_DECODE

   if (!ihdl->Decode_EOF) {
   	     if(ihdl->mhdl->isUnderflow)
   	     {
   	        kal_int32  uBytesAvailable;
            uBytesAvailable = ACU_PeekDataCount((AudComHdl *)ihdl) - 1;
            if (uBytesAvailable >= 2048)
            {
               ACU_WriteDataToDSP(hComponent, (uint16*)AAC_MCU_WRITE_PTR, (uint16*)AAC_DSP_READ_PTR, AAC_PAGE_NUM);
            }
            else
            {
            	  aacWriteZero(ihdl);
            }
         }
         else
         	 ACU_WriteDataToDSP(hComponent, (uint16*)AAC_MCU_WRITE_PTR, (uint16*)AAC_DSP_READ_PTR, AAC_PAGE_NUM);                                                                        
   } else{
      kal_int32 data_Cnt;
      data_Cnt = aacGetDSPDataCnt(ihdl, ihdl->DSP_Write_Idx);
      if (ihdl->DSP_Data_Cnt >= data_Cnt)
         ihdl->DSP_Data_Cnt -= (ihdl->DSP_Data_Cnt - data_Cnt);
      else
         ihdl->DSP_Data_Cnt = 0;
      if (ihdl->DSP_Data_Cnt <= 0){
         ihdl->endStatus = MEDIA_END;
         if( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
            *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
         kal_dev_trace( TRACE_STATE, AAC_L1AUDIO_END_STATE);
      } else {
         aacWriteZero(ihdl);
      }
      return;
   }

   if (ihdl->isEOF) {
      ihdl->DSP_Data_Cnt = aacGetDSPDataCnt(ihdl, 0xFFFF);
      if (ihdl->DSP_Data_Cnt){
         ihdl->Decode_EOF = KAL_TRUE;
         aacWriteZero(ihdl);
         return;
      } else {
         ihdl->endStatus = MEDIA_END;
         if ( *AAC_MAIN_CONTROL == DSP_AAC_STATE_PLAYING )
            *AAC_MAIN_CONTROL = DSP_AAC_STATE_END;
         kal_dev_trace( TRACE_STATE, AAC_L1AUDIO_END_STATE);
      }
   }
   
      
   if( !ihdl->isEOF && !ihdl->Decode_EOF)
   {
      if(((*AAC_ERROR_REPORT == 0x2222)||(*AAC_ERROR_REPORT == 0x1111))){
      	 if( pDecData->FrameInfo.bIsADIF)
      	 {
      	 	  ihdl->endStatus = MEDIA_ERROR;
      	 	  mhdlException( ihdl->mhdl, MEDIA_ERROR );
      	 	  return; 
      	 }
      	 if(ihdl->mhdl && !ihdl->mhdl->waiting)
      	 {
            ihdl->mhdl->isUnderflow = KAL_TRUE;
            ihdl->mhdl->waiting     = KAL_TRUE;
#if defined(__AAC_DSP_DEBUG__)
            aacdebug.fIsUnderflow = KAL_TRUE;
#endif   
            mhdlException( ihdl->mhdl, MEDIA_BUFFER_UNDERFLOW );
   	        return; 
         }
      }
      
      if(ihdl->mhdl && !ihdl->mhdl->waiting)
      {
         ihdl->mhdl->waiting = KAL_TRUE;
         kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_DECODER_AAC, 0,0,0,0,0,0);
         if(ihdl->mhdl->handler)
         {
            mhdlException( ihdl->mhdl, MEDIA_DATA_REQUEST ); 
         }
      }
   }   
}

static void AacDec_OpenDevice(AudComHdlInt *ihdl)
{
   AAC_DecData *pDecData = (AAC_DecData *)ihdl->pPrivateData;    
   ihdl->endStatus = MEDIA_NONE; // Clear for streaming case
   ihdl->dsp_rb_base = 0;

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif

   // Hook Hisr Handler
   L1Audio_HookHisrHandler( DP_D2C_AAC, AacDecHisrHandler, (void *)ihdl );

   mhdlDisallowSleep_Id(ihdl->aud_id);
   
   ClearDSPAudioCommonFlag();
   // Stop DSP activity
   KT_StopAndWait();
   TONE_StopAndWait();
   
   // Hook PCM Route
   PcmRut_RegGetComponent( (AudComHdl *)ihdl );
   MH_RegPutComponent( (AudComHdl *)ihdl );
   Media_SetAudioFormat(MEDIA_FORMAT_AAC);
   Media_SetSampleRate(pDecData->FrameInfo.uSampleRate);
#if defined(AAC_PLUS_DECODE) 
   //if AAC+ don't get data from PCM Route
   if(!pDecData->bDisableSbr){
   	  PcmRut_UnregGetComponent( (AudComHdl *)ihdl );
   	  Media_SetIsAlwaysRoute(KAL_TRUE);
   	  PcmRut_Start(0);
      //Set for apm hook/unhook pcmrut usage
      Media_SetAudioFormat(MEDIA_FORMAT_AAC_PLUS); 
   }
#endif // #ifdef AAC_PLUS_DECODE

   Media_SetIsDSPDec(KAL_TRUE);
   
   APM_Hook_PcmRut();
   
   // Dual SCE
   *AAC_ALLERROR_REPORT = 0;
   *AAC_DUAL_SCE = 0;

   ASSERT(*AAC_MAIN_CONTROL == DSP_AAC_STATE_IDLE);
 
   // DSP colleague provided the following control procedure
   *AAC_MAIN_CONTROL = DSP_AAC_STATE_START;
   kal_trace( TRACE_STATE, L1AUDIO_INIT_STATE );

   {
      AAC_DecData *pDecData = (AAC_DecData *)ihdl->pPrivateData;
      
      *DSP_AUDIO_CTRL2 |= (DP_AAC_CTRL_ASP | DP_PCM_R_DIS);
      *DSP_AUDIO_FLEXI_CTRL |= (FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE);
      DSP_DynamicDownload( DDID_AAC );
      
#if defined(AAC_PLUS_DECODE) 
      if(!pDecData->bDisableSbr)
      	 AM_AudioPlaybackOn( ASP_TYPE_AAC_SBR_ARM , SampleRateTable[autGetSampleRateIdx(pDecData->FrameInfo.uSampleRate)] );
      else
#endif // #ifdef AAC_PLUS_DECODE
         AM_AudioPlaybackOn( ASP_TYPE_AAC, SampleRateTable[autGetSampleRateIdx(pDecData->FrameInfo.uSampleRate)] );
   }

   {
      kal_uint16 I;
      for ( I = 0; ; I++ ) {
         if (DSP_AAC_STATE_PLAYING == *AAC_MAIN_CONTROL || ihdl->endStatus != MEDIA_NONE){
            kal_trace( TRACE_STATE, L1AUDIO_RUNNING_STATE );
            break;
         }

         if (DSP_AAC_STATE_IDLE == *AAC_MAIN_CONTROL) {
            /* This is the case when AAC codec has started and encoutered an error,
               aacPlaybackHisr found this and set the state to STOP, then AAC codec
               set the state to IDLE. */
            break;
         }
         ASSERT_REBOOT( I < 80 );
         kal_sleep_task( 2 );
      }
   }
   
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
}

static void AacDec_CloseDevice(AudComHdlInt *ihdl)
{
   kal_uint32 I;
      
   for ( I = 0; ; I++ ) {
      if ( DSP_AAC_STATE_IDLE == *AAC_MAIN_CONTROL ) /* DSP returns to idle state */
         break;
      if ( DSP_AAC_STATE_PLAYING == *AAC_MAIN_CONTROL ) {
         *AAC_MAIN_CONTROL = DSP_AAC_STATE_STOP;  /* give ABORT command to the DSP */
         kal_trace( TRACE_STATE, L1AUDIO_STOP_STATE );
      }
      ASSERT_REBOOT( I < 80 );
      kal_sleep_task( 2 );
   }
   
   {
      AM_AudioPlaybackOff( true );
      *DSP_AUDIO_CTRL2 &= ~(DP_AAC_CTRL_ASP | DP_PCM_R_DIS);
      *DSP_AUDIO_FLEXI_CTRL &= ~( FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE );
   }
   
   // Unhook PCM Route
   if(Is_PutPcmrutOn())
      PcmRut_Stop();

   {      
#if defined(AAC_PLUS_DECODE)
      AAC_DecData *pDecData = (AAC_DecData *)ihdl->pPrivateData; 	  
      if(pDecData->bDisableSbr)
#endif   	
         PcmRut_UnregGetComponent( (AudComHdl *)ihdl );
   }      
   MH_UnregPutComponent( (AudComHdl *)ihdl );
   
#if defined(__BES_TS_SUPPORT__)
   //clear dsp decode flag when playback off
   if(AudioPP_TS_GetSpeed()!=0)
      AudioPP_TS_ClearDSPreg();
#endif

   //Clear DSP decode flag and format when close device
   Media_SetIsDSPDec(KAL_FALSE);
   Media_SetIsAlwaysRoute(KAL_FALSE);
   mhdlAllowSleep_Id( ihdl->aud_id );
   L1Audio_UnhookHisrHandler(DP_D2C_AAC);

}


/*------------------------------------------------*/
/* The private member functions of AAC decoder.   */
/*------------------------------------------------*/

static OMX_ERRORTYPE AacDec_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   AAC_DecData *pDecData = (AAC_DecData *)ihdl->pPrivateData;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START, MTKAUD_DECODER_AAC, ihdl->mediaStatus,0,0,0,0);
   PcmSink_TerminateSound();
   
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      return OMX_ErrorIncorrectStateOperation;
   }


#if VERIFY_AVSYNC
   ut_a2v_play_dsp_start();
#endif

   // Initialize memory
   ihdl->isEOF = KAL_FALSE;
   ihdl->Decode_EOF = KAL_FALSE;
   ihdl->errorReport = 0;
   ihdl->wDspReadIdx = 0xFFFF;
   ihdl->isDspDecodeEOF =KAL_FALSE;
   ihdl->isEOFSet = KAL_FALSE;
   pDecData->uCurFrame = (kal_uint64)ihdl->mhdl->start_time * 1000000 / pDecData->FrameInfo.uFrameDur; 
#if defined(AAC_PLUS_DECODE)  
   pDecData->AACSBRDec.aac_pcm_pageNum     = 0;
   pDecData->AACSBRDec.aacplus_pcm_pageNum = 0;
   pDecData->AACSBRDec.sbr_bs_pageNum      = 0;
   pDecData->AACSBRDec.channelNum          = 0; 
   pDecData->AACSBRDec.freqIndex           = 0;
   pDecData->AACSBRDec.firstHISR           =KAL_TRUE;
   pDecData->AACSBRDec.SBRdecStart         =KAL_FALSE;
#endif      
   if(ihdl->mhdl){
   	  ihdl->mhdl->isUnderflow = KAL_FALSE;
   }
   
 
#if defined(AAC_PLUS_DECODE)  
   {
   	  MHPB_Internal *pPBhdl = (MHPB_Internal *)ihdl->mhdl;
   	  if(!ihdl->mhdl->bIsPause || pPBhdl->pstFSAL)
   	  {
   	     Media_Status check = MEDIA_SUCCESS;
   	     pDecData->bDisableSbr = KAL_FALSE;
   	     //Decdoe a frame by aac SWIP to get SBR info. 
   	     check = Aac_ChkSBR(ihdl);   	  
   	     if(check == MEDIA_FAIL)
   	     {
             return OMX_ErrorMbErrorsInFrame;
         }
      }
   	  if(pDecData->bDisableSbr)
      {
         //need not init sbr decoder
      }
      else
      {
      	 pDecData->FrameInfo.uSampleRate = pDecData->FrameInfo.uSampleRate*2;
#if defined(MT6255) || defined(MT6250) || defined(MT6260)
         /* Since after HW can support 9 sampling rates, and aac+ SR is double,
            need to update SR to AVsync. 
         */
         if(!pPBhdl->pstFSAL){
         	  extern msTimes_fromV;
         	  Media_A2V_SetFreq(pDecData->FrameInfo.uSampleRate);
         	  Media_A2V_SetInterruptTime(msTimes_fromV);
         }
#endif
         // set last param as non-zero to force stereo output
         pDecData->aacDecHdl = (void*)HEAAC_SBRDec_Init( pDecData->InterBuf, pDecData->SbrBSBuf, SBR_AUTO, SBR_MODE_AUTO,1);
      }   	
   }
#endif 
   
   ACU_LoadResumeInfo(hdl);
#if defined(__AAC_DSP_DEBUG__)
   aacDec_DebugStart();
#endif
   AacDec_OpenDevice(ihdl);
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE AacDec_Stop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;

   //clear resume buffer
   ihdl->bsInfo.pResBuf = NULL;
     
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      ihdl->mediaStatus = COMPONENT_STATE_IDLE;
      ihdl->endStatus = MEDIA_TERMINATED;
   } else {
      // Avoid re-entrance
      return OMX_ErrorNone;
   }

   PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_PCMSINK);
   
   if(!Is_PutPcmrutOn()){
      AFE_SetHardwareMute(true);
   }

#if defined(__AAC_DSP_DEBUG__)
   aacDec_DebugStop();
#endif

#if VERIFY_AVSYNC
   ut_a2v_dsp_stop();
#endif
   
   AacDec_CloseDevice(ihdl);

   kal_trace( TRACE_FUNC, L1AUDIO_STOP, ihdl->mediaType );

   return OMX_ErrorNone;
}

static OMX_ERRORTYPE AacDec_Deinit(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   ACU_FlushBufferQueue(hdl);
#if defined(AAC_PLUS_DECODE)
   L1Audio_FreeAudioID( ihdl->aud_id_decoder );
#endif   
   L1Audio_FreeAudioID( ihdl->aud_id );
   
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, ihdl->mediaType );
   
   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* The public functions of AAC decoder.           */
/*------------------------------------------------*/
OMX_U32 AacDec_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;
   
   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for AAC private data
   uTempSize = (sizeof(AAC_DecData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for AACSBR decoder SWIP
#if defined(AAC_PLUS_DECODE)
{   
   OMX_S32 InterBufSize, TmpBufSize, PcmBufSize, SbrBsBufSize;
   HEAAC_SBRDec_GetMemSize( &InterBufSize, &TmpBufSize, &PcmBufSize, &SbrBsBufSize );  
   InterBufSize   = (InterBufSize + 3) & ~0x3;
   TmpBufSize     = (TmpBufSize   + 3) & ~0x3;
   PcmBufSize     = (PcmBufSize   + 3) & ~0x3;
   SbrBsBufSize   = (SbrBsBufSize + 3) & ~0x3;
   uReqSizeTotal += InterBufSize + TmpBufSize + PcmBufSize*2 + SbrBsBufSize;
}
#endif
   
   return uReqSizeTotal;
}

OMX_ERRORTYPE AacDec_Init(
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
   
   // The buffer address should be 4 bytes aligned
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
   ihdl->basic.Start        = AacDec_Start;
   ihdl->basic.Stop         = AacDec_Stop;
   ihdl->basic.SetParameter = AacDec_SetParameter;
   ihdl->basic.Deinit       = AacDec_Deinit;
   ihdl->basic.Process      = ACU_DSPDecoderProcess; 
   
   {
       //memset(pDecData, 0, sizeof(AAC_DecData));
#if defined(AAC_PLUS_DECODE)
       AAC_DecData *pDecData = (AAC_DecData *)ihdl->pPrivateData;
       {
          OMX_S32 InterBufSize, TmpBufSize, PcmBufSize, SbrBsBufSize, uDecStructSize;
          kal_uint8 *privatebuf = (kal_uint8 *)ihdl->pPrivateData;   
          HEAAC_SBRDec_GetMemSize( &InterBufSize, &TmpBufSize, &PcmBufSize, &SbrBsBufSize );                                        
                                   
          uDecStructSize = (sizeof(AAC_DecData) + 3) & ~0x3;
          InterBufSize   = (InterBufSize + 3) & ~0x3;
          TmpBufSize     = (TmpBufSize   + 3) & ~0x3;
          PcmBufSize     = (PcmBufSize   + 3) & ~0x3;
          SbrBsBufSize   = (SbrBsBufSize + 3) & ~0x3;
          
          privatebuf+=uDecStructSize;
          pDecData->InterBuf = (void *)privatebuf;
          privatebuf+=InterBufSize;
          pDecData->TmpBuf = (void *)privatebuf;
          privatebuf+=TmpBufSize;
          pDecData->PcmBuf = (void *)privatebuf;
          privatebuf+=PcmBufSize;
          pDecData->SbrBSBuf = (void *)privatebuf;
          privatebuf+=SbrBsBufSize;
          pDecData->TmpPcmBuf = (void *)privatebuf;                
          pDecData->pcm_size = PcmBufSize;        
       }
#endif 	     
   }
   // Obtain l1audio service
   // KH: should re-organize
   AFE_SetDigitalGain( L1SP_AUDIO, 100 );
   AFE_SetDigitalGain( L1SP_VOICE, 100 );
   ihdl->aud_id = L1Audio_GetAudioID();
#if defined(AAC_PLUS_DECODE) 
   ihdl->aud_id_decoder = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( ihdl->aud_id_decoder, Aac_SBRDecodeTask );
#endif   
   
   L1Audio_SetEventHandler( ihdl->aud_id, mhdlCallbackTask );
   
   return OMX_ErrorNone;
}

#endif
