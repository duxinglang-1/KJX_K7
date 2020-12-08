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
 * MelodyParser.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Melody Synthesizer Component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#if defined( DSP_WT_SYN )

#include "Melody_Component.h"

OMX_U32 MelodySyn_GetMemSize(void)
{
   OMX_U32 uTempSize, uReqSizeTotal;
   kal_uint32 InterSize, PcmSize;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for Melody Parser private data
   uTempSize = (sizeof(MEL_SynData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   MelSyn_GetBufferSize(&InterSize, &PcmSize, MELODY_SAMPLERATE, MELODY_PERIOD);
   uTempSize = (InterSize + 3) & ~0x3;
   
   uReqSizeTotal += uTempSize;
   
   return uReqSizeTotal;
   
}

static OMX_ERRORTYPE MelodySyn_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   if(ihdl->mediaStatus == COMPONENT_STATE_READY || ihdl->mediaStatus == COMPONENT_STATE_PAUSE){
      ihdl->mediaStatus = COMPONENT_STATE_PLAY;
      ihdl->isEOF = KAL_FALSE;
      return OMX_ErrorNone;
   }
   return OMX_ErrorIncorrectStateOperation;
}

static OMX_ERRORTYPE MelodySyn_Stop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_SynData *pSynData = (MEL_SynData *)ihdl->pPrivateData;
   
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY ) {
      ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
      ihdl->endStatus = MEDIA_TERMINATED;
   } else {
        ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
   }
   pSynData->reset = 1;
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE MelodySyn_Process(AudComHdl *hdl)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
   OMX_U32 bufDataSize, uReadSize;
   OMX_U8 *pWriteBuf, *pReadBuf;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_SynData *pSynData = (MEL_SynData *)ihdl->pPrivateData;
   
   //if(ihdl->mediaStatus == COMPONENT_STATE_IDLE || ihdl->mediaStatus == COMPONENT_STATE_PAUSE)
   if(ihdl->mediaStatus == COMPONENT_STATE_IDLE)
      return OMX_ErrorNone;
   
   ACU_GetWriteBuffer(hdl, &pWriteBuf, &bufDataSize);
   ACU_GetReadBuffer(hdl, &pReadBuf, &uReadSize);
   
   if(uReadSize == 0 )
      return OMX_ErrorNone;
   if (bufDataSize < MELODY_PCM_SIZE) {
      return OMX_ErrorNone;
   }else {
      pBufHdr = ihdl->OutputQ.pCurBufHdr;
   }
      
   if( MelSyn_Synthesis( pSynData->mel_hdl, (char*)pReadBuf, (char*)pWriteBuf, pSynData->reset ) != MELSYN_SUCCESS){
      if( pSynData->evthdl != (void*)0 )
      {
         if(pSynData->usage == MELODYUSAGE_SOUNDEFFECT)
            pSynData->evtcall( pSynData->evthdl, MELODY_SYNTHDONE_SOUNDEFFECT);
         else
            pSynData->evtcall( pSynData->evthdl, MELODY_SYNTHDONE_MUSICSOUND);
      }
   }
   pSynData->reset = 0;
   if(ihdl->isEOF){
      pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
   }
   else{
      pBufHdr->nFlags &= ~OMX_BUFFERFLAG_EOS;
   }
         
   ACU_ReadDataDone(hdl, uReadSize);
   //ACU_WriteDataDone_ImmediateCallback(hdl, MELODY_PCM_SIZE);
   ACU_WriteDataDone(hdl, MELODY_PCM_SIZE);
   return OMX_ErrorNone;
}

OMX_ERRORTYPE MelodySyn_Deinit(AudComHdl *hdl)
{
   ACU_FlushBufferQueue(hdl);
   //L1Audio_FreeAudioID( ihdl->aud_id );
   
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE MelodySyn_GetMetaData(AudComHdl *hdl, OMX_PTR pMetaData)
{
   
   return OMX_ErrorNotImplemented;
}

OMX_ERRORTYPE MelodySyn_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_SynData *pSynData = (MEL_SynData *)ihdl->pPrivateData;
   MelodySynthParam *pParam = (MelodySynthParam *)pStruct;
      
   switch(index){
   // OMX_IndexConfigMelodySynthesizerInit
   case OMX_IndexConfigMelodySynthesizerInit:
      pSynData->samplerate = pParam->meldata.samplerate;
      pSynData->maxtone    = pParam->meldata.maxtone;
      pSynData->finetone   = pParam->meldata.finetone;
      pSynData->period     = pParam->meldata.period;
      pSynData->tonegain   = pParam->meldata.tonegain;
      pSynData->wavtab     = pParam->meldata.wavtab;
      pSynData->evthdl     = pParam->meldata.evthdl;
      pSynData->evtcall    = pParam->meldata.evtcall;
      pSynData->usage      = pParam->meldata.usage;
      pSynData->mel_hdl = MelSyn_Init( pSynData->working, (MELSYN_SR)pSynData->samplerate, pSynData->maxtone, 
                                       pSynData->finetone, pSynData->period, pSynData->tonegain, pSynData->wavtab, 
                                       pSynData->evthdl, pSynData->evtcall, (void*)0, (void*)0 );
      if(pSynData->mel_hdl == (void*)0)
         return OMX_ErrorBadParameter;
         
      ihdl->mediaStatus = COMPONENT_STATE_READY;
      break;
   case OMX_IndexConfigMelodySetSynHandle:
      pSynData->evthdl     = pParam->meldata.evthdl;
      break;
   // Get Channel Volume
   case OMX_IndexConfigMelodyGetChannelVolume:
      pParam->data = MelSyn_GetVolume(pSynData->mel_hdl, pParam->channel);
      break;
   // Set Channel Volume   
   case OMX_IndexConfigMelodySetChannelVolume:
      if(MelSyn_SetVolume(pSynData->mel_hdl,pParam->channel, pParam->data) != MELSYN_SUCCESS)
         return OMX_ErrorBadParameter;
      break;
   // Get Channel Program
   case OMX_IndexConfigMelodyGetChannelProgram:
      pParam->data = MelSyn_GetProgram(pSynData->mel_hdl, pParam->channel);
      break;
   // Set Channel Program
   case OMX_IndexConfigMelodySetChannelProgram:
      if(MelSyn_SetProgram(pSynData->mel_hdl,pParam->channel, pParam->data) != MELSYN_SUCCESS)
         return OMX_ErrorBadParameter;
      break;
   // Get Pitch Transpose
   case OMX_IndexConfigMelodyGetPitchTranspose:
      pParam->data = MelSyn_GetPitchTranspose(pSynData->mel_hdl);
      break;
   // Set Pitch Transpose
   case OMX_IndexConfigMelodySetPitchTranspose:
      if(MelSyn_SetPitchTranspose(pSynData->mel_hdl,pParam->data)!= MELSYN_SUCCESS)
         return OMX_ErrorBadParameter;
      break;
   // Get Synthesizer Volume Level
   case OMX_IndexConfigMelodyGetLevel:
      pParam->data = MelSyn_GetLevel(pSynData->mel_hdl);
      break;
   // Set Synthesizer Volume Level
   case OMX_IndexConfigMelodySetLevel:
      if(MelSyn_SetLevel(pSynData->mel_hdl,pParam->data) != MELSYN_SUCCESS)
         return OMX_ErrorBadParameter;
      break;
   // Send Melody Message
   case OMX_IndexConfigMelodySendMessage:
      break;
   case OMX_IndexConfigMelodySetEndFlag:
        ihdl->isEOF = KAL_TRUE;
      break;
   // Bad OMX Index
   case OMX_IndexConfigMelodyClrEndFlag:
        ihdl->isEOF = KAL_FALSE;
      break;
   case OMX_IndexConfigMelodyClrIPEndFlag:
      MelSyn_ClearEnd(pSynData->mel_hdl);
      break;
   case OMX_IndexConfigMelodyRepeat:
      //pSynData->reset = true;      
      break;
   default:
      return OMX_ErrorNotImplemented;
   }

   return OMX_ErrorNone;
}

OMX_ERRORTYPE MelodySyn_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback,
   OMX_STRING      pURI
)
{
   OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   MEL_SynData *pSynData;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = MelodySyn_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   
   // Melody Synthesizer Private Data
   ihdl->pPrivateData = (void *)pBuffer8;
   pSynData = (MEL_SynData *)ihdl->pPrivateData;
   pBuffer8 += (sizeof(MEL_SynData) + 3) & ~0x3;
   pSynData->working = pBuffer8;
   pSynData->reset = 0;
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start        = MelodySyn_Start;
   ihdl->basic.Stop         = MelodySyn_Stop;
   ihdl->basic.Process      = MelodySyn_Process;
   ihdl->basic.SetParameter = MelodySyn_SetParameter;
   ihdl->basic.Deinit       = MelodySyn_Deinit;
   ihdl->basic.GetMetaData  = MelodySyn_GetMetaData;   

   ihdl->mediaStatus = COMPONENT_STATE_IDLE;
   ihdl->isEOF = KAL_FALSE;
   return OMX_ErrorNone;
}

#endif
