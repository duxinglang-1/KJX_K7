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
 *   Melody Parser Component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined( DSP_WT_SYN )
#include "Melody_Component.h"

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Common Part in Both Framework
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
typedef struct{
   uint8  type;
   uint8  ch;
   uint8  data1;
   uint8  data2;
}RT_MidiEvent;

const static int8 chantype[] = {
   0, 0, 0, 0, 0, 0, 0, 0,    /* 0x00 through 0x70 */
   2, 2, 2, 2, 1, 1, 2, 0     /* 0x80 through 0xf0 */
};

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Single Parser Framework
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#if SINGLE_PASER_SINGLE_WTSYNTH
/*
********************************************************************************
*                        File Parser Component
********************************************************************************
*/

void TimeTransform(MEL_ParData *pParData, int flag)
{
   uint32 hipart, lowpart;
   if(flag){
      hipart = (pParData->current_time&0xFFFF0000)>>8;
      lowpart = (pParData->current_time&0xFFFF);
      hipart = ((hipart*10000)/(pParData->playrate*pParData->tsrate));
      lowpart = ((lowpart*10000)/(pParData->playrate*pParData->tsrate));
      pParData->current_time_int = ((hipart<<8) + lowpart);
   }else{
      hipart = (pParData->current_time_int&0xFFFF0000)>>8;
      lowpart = (pParData->current_time_int&0xFFFF);
      hipart = ((hipart*pParData->playrate*pParData->tsrate)/10000);
      lowpart = ((lowpart*pParData->playrate*pParData->tsrate)/10000);
      pParData->current_time = ((hipart<<8) + lowpart);
   }
}
OMX_U32 MelodyPar_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;
   kal_int32 InterSize, OutSize;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for Melody Parser private data
   uTempSize = (sizeof(MEL_ParData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   MelPar_GetBufferSize(&InterSize, &OutSize);
   uTempSize = (InterSize + 3) & ~0x3;
   
   uReqSizeTotal += uTempSize;
   
   return uReqSizeTotal;
}

OMX_ERRORTYPE MelodyPar_Deinit(AudComHdl *hdl)
{
   ACU_FlushBufferQueue(hdl);
   
   return OMX_ErrorNone;
}


static OMX_ERRORTYPE MelodyPar_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_ParData *pParData = (MEL_ParData *)ihdl->pPrivateData;

   if(ihdl->mediaStatus == COMPONENT_STATE_READY || ihdl->mediaStatus == COMPONENT_STATE_PAUSE){
      if( MelPar_Seek(pParData->mel_hdl,pParData->start_time) == MELPAR_SUCCESS){
         pParData->current_time = pParData->start_time;
         TimeTransform(pParData, 1);
      }
      ihdl->mediaStatus = COMPONENT_STATE_PLAY;
#if defined(MELODY_POP_WRKRND)
      pParData->silencecnt   = MELODY_SILENCECNT;
#endif
      ACU_SendProcessCommandl( (AudComHdlInt *)hdl );
      pParData->releasedone = KAL_FALSE;
      return OMX_ErrorNone;
   }
   return OMX_ErrorIncorrectStateOperation;
}

static OMX_ERRORTYPE MelodyPar_Process(AudComHdl *hdl)
{
   kal_int32 evtlen;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   OMX_U32 bufDataSize;
   OMX_U8 *pBuf;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_ParData *pParData = (MEL_ParData *)ihdl->pPrivateData;
   
   if(ihdl->mediaStatus == COMPONENT_STATE_IDLE)
      return OMX_ErrorNone;
   
   ACU_GetWriteBuffer(hdl, &pBuf, &bufDataSize);
   
   if (bufDataSize == 0) {
      return OMX_ErrorNone;
   }else {
      pBufHdr = ihdl->OutputQ.pCurBufHdr;
   }
   
   if( (pBufHdr->nFlags&OMX_BUFFERFLAG_EOS) && (ihdl->mediaStatus != COMPONENT_STATE_PLAY))
      return OMX_ErrorNone;
   
   if(ihdl->mediaStatus == COMPONENT_STATE_PAUSE ){
      ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
      ACU_SetEOS(hdl);
      return OMX_ErrorNone;
   }   
#if defined(MELODY_POP_WRKRND)
   if( pParData->silencecnt){
   	  OMX_U16 *ptr16 = (OMX_U16*)pBuf;
   	  *ptr16 = 0;
      pParData->silencecnt--;
      ACU_WriteDataDone_ImmediateCallback(hdl, 2);
      return OMX_ErrorNone;
   }
#endif   
   if( MelPar_Parse( pParData->mel_hdl, pParData->period, (kal_int32*)&pParData->delta_ms, (char*)pBuf, &evtlen ) != MELPAR_SUCCESS ){
   #if defined(MELODY_NOSOUND_WRKRND)
      if(pParData->releasedone && pParData->silenceend == 0){
   #else
      if(pParData->releasedone){
   #endif
         if( pParData->repeats == 1 ){
            ACU_SetEOS(hdl);
         //pParData->evtcall( pParData->evthdl, MELODY_END );
            ihdl->mediaStatus = COMPONENT_STATE_READY;
         }else{
            if(pParData->repeats != 0)
               pParData->repeats--;
            MelPar_Seek( pParData->mel_hdl, 0 );
            pParData->evtcall( pParData->evthdl, MELODY_REPEAT );
            pBufHdr->nFlags &= ~OMX_BUFFERFLAG_EOS;
            pParData->current_time = 0;
            pParData->current_time_int = 0;
            pParData->releasedone = KAL_FALSE;
         }
      }      
   #if defined(MELODY_NOSOUND_WRKRND)
      if( pParData->silenceend)
         pParData->silenceend--;
   #endif
   }else{
      pBufHdr->nFlags &= ~OMX_BUFFERFLAG_EOS;
         pParData->current_time_int += MELODY_PERIOD;
         TimeTransform(pParData, 0);
         if(pParData->current_time > pParData->duration)
            pParData->current_time = pParData->duration;
   }
   if(pParData->current_time >= pParData->stop_time){
      pParData->current_time = pParData->stop_time;
      ACU_SetEOS(hdl);
      ihdl->mediaStatus = COMPONENT_STATE_READY;
   }
   ACU_WriteDataDone_ImmediateCallback(hdl, evtlen);

   return OMX_ErrorNone;
}


static OMX_ERRORTYPE MelodyPar_GetMetaData(AudComHdl *hdl, OMX_PTR pMetaData)
{
   return OMX_ErrorNotImplemented;
}

static OMX_ERRORTYPE MelodyPar_Stop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_ParData *pParData = (MEL_ParData *)ihdl->pPrivateData;
   
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
      ihdl->endStatus = MEDIA_TERMINATED;
   } else {
      ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
   }

   pParData->releasedone = KAL_FALSE;
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE MelodyPar_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_ParData *pParData = (MEL_ParData *)ihdl->pPrivateData;
   MelodyParseParam *pParam = (MelodyParseParam *)pStruct;
   
   switch(index){
   // Init Melody Parser
   case OMX_IndexConfigMelodyParserInit:
      pParData->filelen  = pParam->meldata.filelen;
      pParData->mode     = pParam->meldata.mode;
      pParData->maxtone  = pParam->meldata.maxtone;
      pParData->datahdl  = pParam->meldata.datahdl;
      pParData->getdata  = pParam->meldata.getdata;
      pParData->repeats  = pParam->meldata.repeats;
      pParData->period   = pParam->meldata.period;
      pParData->midifile = pParam->meldata.midifile;
      pParData->evthdl   = pParam->meldata.evthdl;
      pParData->evtcall  = pParam->meldata.evtcall;
      pParData->mel_hdl = MelPar_Init( pParData->working, (void*)pParData->midifile, pParData->filelen, pParData->mode,
                       DEFAULT_TONE_INST, pParData->maxtone, (void*)pParData->datahdl, 
                       pParData->getdata, (void*)0 ,(void*)0 );
      if( pParData->mel_hdl == (void*)0 )
         return OMX_ErrorBadParameter;
      pParData->duration = MelPar_GetDuration(pParData->mel_hdl);
      ihdl->mediaStatus = COMPONENT_STATE_READY;
      break;
   // Get Melody Tempo
   case OMX_IndexConfigMelodyGetTempo:
      pParam->data = MelPar_GetTempo(pParData->mel_hdl);
      break;
   // Set Melody Tempo
   case OMX_IndexConfigMelodySetTempo:
      if(MelPar_SetTempo(pParData->mel_hdl,pParam->data) != MELPAR_SUCCESS)
         return OMX_ErrorBadParameter;
      break;
   // Get Parser parse rate
   case OMX_IndexConfigMelodyGetPlayRate:
      pParam->data = MelPar_GetPlayRate(pParData->mel_hdl);
      break;
   // Set Parser parse rate
   case OMX_IndexConfigMelodySetPlayRate:
      if(MelPar_SetPlayRate(pParData->mel_hdl,pParam->data) != MELPAR_SUCCESS)
         return OMX_ErrorBadParameter;
      pParData->playrate = pParam->data;
      TimeTransform(pParData, 1);
      break;
   // Get Melody Time Stretch Rate
   case OMX_IndexConfigMelodyGetTsRate:
      pParam->data = MelPar_GetTsRate(pParData->mel_hdl);
      break;
   // Set Melody Time Stretch Rate
   case OMX_IndexConfigMelodySetTsRate:
      if(MelPar_SetTsRate(pParData->mel_hdl,pParam->data) != MELPAR_SUCCESS)
         return OMX_ErrorBadParameter;
      pParData->tsrate = pParam->data;
      TimeTransform(pParData, 1);   
      break;
   // Check if the Melody contains SP-MIDI Message
   case OMX_IndexConfigMelodySpMidi:
      pParam->data = MelPar_isSpMidi(pParData->mel_hdl);
      break;
   // Get Current Parsed-time
   case OMX_IndexConfigMelodyGetParsedTime:
      pParam->data = MelPar_GetParsedTime(pParData->mel_hdl);
      break;
   // Get Melody Duration
   case OMX_IndexConfigMelodyGetDuration:
      pParam->data = MelPar_GetDuration(pParData->mel_hdl);
      break;
   // Seek to desired time
   case OMX_IndexConfigMelodySetStartTime:
      pParData->start_time = pParam->data;
      break;
   // Set Stop time
   case OMX_IndexConfigMelodySetStopTime:
      pParData->stop_time = pParam->data;
      break;
   // Get current time, temp solution
   case OMX_IndexConfigMelodyGetCurrentTime:
        if(pParData->current_time < pParData->start_time)
           pParam->data = pParData->start_time;
        else
           pParam->data = pParData->current_time;
        break;
   case OMX_IndexConfigMelodySynthesisDone:
      pParData->releasedone = KAL_TRUE;
      break;
   case OMX_IndexConfigMelodyGetFormat:
      pParam->data = MelPar_QueryFormat(pParData->mel_hdl);
   // Bad OMX Index
   default:
      return OMX_ErrorNotImplemented;
   }

   return OMX_ErrorNone;
}

OMX_ERRORTYPE MelodyPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   MEL_ParData *pParData;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = MelodyPar_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   
   // Melody Parser Private Data
   ihdl->pPrivateData = (void *)pBuffer8;
   pParData = (MEL_ParData *)ihdl->pPrivateData;
   pBuffer8 += (sizeof(MEL_ParData) + 3) & ~0x3;
   pParData->working = pBuffer8;
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start        = MelodyPar_Start;
   ihdl->basic.Stop         = MelodyPar_Stop;
   ihdl->basic.Deinit       = MelodyPar_Deinit;
   ihdl->basic.Process      = MelodyPar_Process;
   ihdl->basic.SetParameter = MelodyPar_SetParameter;
   ihdl->basic.GetMetaData  = MelodyPar_GetMetaData;

   ihdl->mediaStatus = COMPONENT_STATE_IDLE;
   pParData->current_time = 0;
   pParData->current_time_int = 0;
   pParData->stop_time = 0xFFFFFFFF;
   pParData->releasedone  = KAL_FALSE;
   pParData->playrate     = 100;
   pParData->tsrate       = 100;
#if defined(MELODY_POP_WRKRND)
   pParData->silencecnt   = MELODY_SILENCECNT;
#endif
#if defined(MELODY_NOSOUND_WRKRND)
   pParData->silenceend   = MELODY_SILENCE_END;
#endif
   return OMX_ErrorNone;
}

/*
********************************************************************************
*                        MIDI Device Component
********************************************************************************
*/

static int8 TransformChannelMessage( MEL_DevData *data, int8 status, int8 *c1, int8 *c2 )
{
   int8 type = MELDOY_RTMSG_NONE;
   int8 ch = (int8)(status & 0xf);

   switch ( status & 0xf0 ) {
   case 0x80:
      type = MELODY_RTMSG_NOTEOFF;
      break;
   case 0x90:
      type = (int8)(( *c2 == 0 )? MELODY_RTMSG_NOTEOFF : MELODY_RTMSG_NOTEON);            
      break;     
   case 0xb0:     /* Controller message */
      switch( *c1 ) {
      case 0x00:
         type = MELODY_RTMSG_TONE_BANK_HI;
         break;
      case 0x20:
         type = MELODY_RTMSG_TONE_BANK_LO;
         break;
      case 0x01:
         type = MELODY_RTMSG_MODULATION_WHEEL;
         break;
      case 0x07:
         type = MELODY_RTMSG_VOLUME;
         break;
      case 0x0A:
         type = MELODY_RTMSG_PAN;
         break;
      case 0x0B:
         type = MELODY_RTMSG_EXPRESSION;
         break;
      case 0x40:
         type = MELODY_RTMSG_SUSTAIN;
         break;

      case 98:    data->nrpn=KAL_TRUE;  data->rpn_lsb[ch] = *c2;    break;
      case 99:    data->nrpn=KAL_TRUE;  data->rpn_msb[ch] = *c2;    break;
      case 100:   data->nrpn=KAL_FALSE; data->rpn_lsb[ch] = *c2;    break;
      case 101:   data->nrpn=KAL_FALSE; data->rpn_msb[ch] = *c2;    break;

      case 0x06:     /* RPN */
         if( data->nrpn )
            break;
         switch( ( (int16)data->rpn_msb[ch] << 7 ) | (int16)data->rpn_lsb[ch] ) {
         case 0x0000: /* Pitch bend sensitivity */
            type = MELODY_RTMSG_PITCH_SENS;
            break;
         case 0x3FFF: /* RPN reset */
            /* reset pitch bend sensitivity to 2 */
            type = MELODY_RTMSG_PITCH_SENS;
            *c2 = 2;
            break;
         }
         break;
      }
      break;
   case 0xc0:
      type = MELODY_RTMSG_PROGRAM;
      break;
   case 0xa0:
      type = MELODY_RTMSG_KEY_PRESSURE;
      break;
   case 0xe0:
      type = MELODY_RTMSG_PITCH_WHEEL;
      break;
   case 0xd0:
      type = MELODY_RTMSG_CHANNEL_PRESSURE;
      break;
   }
   return type;
}

static int8 rtmidiGet( MEL_DevData *data )
{
   if( data->rtmidi_count == 0 )
      return 0;
   data->rtmidi_count--;
   return *data->rtmidi_ptr++;
}

static void rtmidiError( MEL_DevData *data )
{
   data->rtmidi_count = 0;
}

static int32 rtmidiReadVarNum( MEL_DevData *data )
{
   int32 value;
   int16 c;

   c = rtmidiGet( data );
   if( !(c & 0x80) )    return c;
   value = c & 0x7F;
   c = rtmidiGet( data );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) )    return value;
   c = rtmidiGet( data );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) )    return value;
   c = rtmidiGet( data );
   value = (value << 7) + (c & 0x7f);
   return value;
}

static void rtmidi_msg_read( MEL_DevData *data )
{
   OMX_U32 count = rtmidiReadVarNum( data );

   if( count > data->rtmidi_count )
      data->rtmidi_count = 0;
   else {
      data->rtmidi_count -= count;
      data->rtmidi_ptr += count;
   }
}

static void ReadRTMidiEvent( MEL_DevData *data, RT_MidiEvent *nt )
{
   int16 c;
   int needed;

   nt->type = MELDOY_RTMSG_NONE;

   c = rtmidiGet( data );

   if( c == 0xFF ) {                /* meta event */
      rtmidiGet( data );                  /* meta event should be ignored in RT MIDI mode */
      rtmidi_msg_read( data );
   }
   else if( c == 0xF0 ) {           /* start of system exclusive */
      rtmidi_msg_read( data );
      //SysExEvent( player, player->msgbuff );
   }
   else if( c == 0xF7 ) {           /* sysex continuation or arbitrary stuff */
      rtmidi_msg_read( data );
   }
   else {
      if( (c & 0x80) == 0 ) {       /* running status? */
         if( data->rtmidi_status == 0 ) {
            rtmidiError( data );
            return;
         }
         data->rtmidi_running = KAL_TRUE;
      }
      else {
         data->rtmidi_status = (uint8)c;
         data->rtmidi_running = KAL_FALSE;
      }

      needed = chantype[ (data->rtmidi_status>>4) & 0xf ];

      if( needed ) {                /* ie. is it a channel message? */
         nt->data1 = ( data->rtmidi_running )? c : rtmidiGet( data );
         nt->data2 = ( needed > 1 )? rtmidiGet( data ):0;
         nt->ch    = data->rtmidi_status & 0x0F;
         nt->type  = TransformChannelMessage( data, data->rtmidi_status, (int8 *)&(nt->data1), (int8 *)&(nt->data2) );
      }
   }
}

OMX_U32 MelodyDev_GetRTmidi(MEL_DevData *data, OMX_U8 *pBuf)
{
   OMX_U32 evtcount;
   OMX_U8 *ptr8;
   OMX_U16 *ptr16;
   RT_MidiEvent nt;
   
   nt.type = nt.ch = nt.data1 = nt.data2 = 0;
   evtcount = 0;
   ptr8 = (OMX_U8*)pBuf;
   ptr8 += 2;
   
   while( data->rtmidi_count > 0 ) {          /* For real-time MIDI playback */
      if( data->rtmidi_count == 1 ) {
         data->rtmidi_count = 0;
         break;
      }
      else {
         ReadRTMidiEvent( data, &nt );
         if(nt.type != MELDOY_RTMSG_NONE){
            evtcount++;
            *ptr8++ = nt.type;
            *ptr8++ = nt.ch;
            *ptr8++ = nt.data1;
            *ptr8++ = nt.data2;
         }
         if(evtcount == MELDOY_RTEVT_COUNT)
            break;
      }
   }
   ptr16 = (OMX_U16*)pBuf;
   *ptr16 = evtcount*4;
   return (evtcount*4)+2;
}

OMX_U32 MelodyDev_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for Melody Parser private data
   uTempSize = (sizeof(MEL_DevData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   return uReqSizeTotal;
}

OMX_ERRORTYPE MelodyDev_Deinit(AudComHdl *hdl)
{
   ACU_FlushBufferQueue(hdl);
   //L1Audio_FreeAudioID( ihdl->aud_id );
   
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE MelodyDev_Start(AudComHdl *hdl)
{
    AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
    
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
   ACU_SendProcessCommandl( (AudComHdlInt *)hdl );
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE MelodyDev_Process(AudComHdl *hdl)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
   OMX_U32 bufDataSize, evtcnt;
   OMX_U8 *pBuf;
   OMX_U16 *ptr16;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_DevData *pDevData = (MEL_DevData *)ihdl->pPrivateData;
   
   ACU_GetWriteBuffer(hdl, &pBuf, &bufDataSize);
   
   if (bufDataSize == 0) {
      return OMX_ErrorNone;
   }else {
      pBufHdr = ihdl->OutputQ.pCurBufHdr;
   }
   
   if(pBufHdr->nFlags&OMX_BUFFERFLAG_EOS)
      return OMX_ErrorNone;
      
   if(ihdl->mediaStatus == COMPONENT_STATE_PAUSE){
      pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
      ACU_SendCommand(ihdl, 0, OMX_EventBufferFlag, 1, pBufHdr->nFlags, pBufHdr);
      return OMX_ErrorNone;
   }
   
   if(pDevData->rtmidi_count == 0){
      ptr16 = (OMX_U16*)pBuf;
      *ptr16 = 0;
        ACU_WriteDataDone_ImmediateCallback(hdl, 2);
      return OMX_ErrorNone;
   }else{
      evtcnt = MelodyDev_GetRTmidi(pDevData, pBuf);
      if(evtcnt == 0){
         ptr16 = (OMX_U16*)pBuf;
         *ptr16 = 0;
         ACU_WriteDataDone_ImmediateCallback(hdl, 2);
      }else{
         ACU_WriteDataDone_ImmediateCallback(hdl, evtcnt);
      }
      if(pDevData->rtmidi_count == 0)
         pDevData->evtcall( pDevData->evthdl, MELODY_MSG_DONE );
   }

   return OMX_ErrorNone;   
}

static OMX_ERRORTYPE MelodyDev_GetMetaData(AudComHdl *hdl, OMX_PTR pMetaData)
{
   return OMX_ErrorNotImplemented;
}

static OMX_ERRORTYPE MelodyDev_Stop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
      ihdl->endStatus = MEDIA_TERMINATED;
   } else {
      ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
   }
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE MelodyDev_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_DevData *pDevData = (MEL_DevData *)ihdl->pPrivateData;
   MelodyDevParam *pParam = (MelodyDevParam *)pStruct;
   
   switch(index){
   // Send Real-time MIDI Message
   case OMX_IndexConfigMelodySendMessage:
      pDevData->rtmidi_running = pParam->meldata.rtmidi_running;
      pDevData->rtmidi_status  = pParam->meldata.rtmidi_status;
      pDevData->rtmidi_ptr     = pParam->meldata.rtmidi_ptr;
      pDevData->rtmidi_count   = pParam->meldata.rtmidi_count;
      break;
   case OMX_IndexConfigMelodyDeviceInit:
      pDevData->rtmidi_running = pParam->meldata.rtmidi_running;
      pDevData->rtmidi_status  = pParam->meldata.rtmidi_status;
      pDevData->rtmidi_ptr     = pParam->meldata.rtmidi_ptr;
      pDevData->rtmidi_count   = pParam->meldata.rtmidi_count;
      pDevData->evthdl         = pParam->meldata.evthdl;
      pDevData->evtcall        = pParam->meldata.evtcall;
      break;
   // Bad OMX Index
   default:
      return OMX_ErrorNotImplemented;
   }
   return OMX_ErrorNone;
}

OMX_ERRORTYPE MelodyDev_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   MEL_DevData *pDevData;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = MelodyPar_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   
   // Melody Parser Private Data
   ihdl->pPrivateData = (void *)pBuffer8;
   pDevData = (MEL_DevData *)ihdl->pPrivateData;
   pBuffer8 += (sizeof(MEL_DevData) + 3) & ~0x3;
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start        = MelodyDev_Start;
   ihdl->basic.Stop         = MelodyDev_Stop;
   ihdl->basic.Deinit       = MelodyDev_Deinit;
   ihdl->basic.Process      = MelodyDev_Process;
   ihdl->basic.SetParameter = MelodyDev_SetParameter;
   ihdl->basic.GetMetaData  = MelodyDev_GetMetaData;

   // Obtain l1audio service
   //ihdl->aud_id = L1Audio_GetAudioID();
   //L1Audio_SetEventHandler( ihdl->aud_id, MelodyParCallbackTask );
   ihdl->mediaStatus = COMPONENT_STATE_IDLE;
   pDevData->rtmidi_running = KAL_FALSE;
   pDevData->rtmidi_status  = 0;
   pDevData->rtmidi_ptr     = 0;
   pDevData->rtmidi_count   = 0;

   return OMX_ErrorNone;
}
/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Multiple Parser Framework
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#elif MULTIPLE_PASER_SINGLE_WTSYNTH

void MelodyPar_GetChannel(void *hdl, unsigned char *chid, unsigned char per)
{
#if defined(__AUDIO_ULTRA_SLIM__)
   return;
#else
   kal_uint8 I;
   MEL_ParDataInt *pParDataInt;
   MEL_ParData *pParData;
   pParDataInt = (MEL_ParDataInt*)hdl;
   pParData    = (MEL_ParData *)pParDataInt->parent;
   for( I = 0 ; I < MELODY_MAX_SYNTHCHANNEL ; I++ ){
      if(!pParData->synthchannel[I].used){
         pParData->synthchannel[I].used = KAL_TRUE;
         pParData->synthchannel[I].hdl  = pParDataInt;
         *chid = I;
         if(per){
            pParData->synthchannel[I].per = KAL_TRUE;
            pParData->rtEvent.evtbuf[pParData->rtEvent.write&(MELODY_MAX_RTEVT-1)] = I;
            pParData->rtEvent.write++;
         }
         break;
      }
   }
#endif
}

void MelodyPar_ReleaseChannel(MEL_ParDataInt *pParDataInt)
{
#if defined(__AUDIO_ULTRA_SLIM__)
   return;
#else
   kal_uint8 I;
   MEL_ParData *pParData;
   
   pParData = (MEL_ParData*)pParDataInt->parent;
   for( I = 0; I < MELODY_MAX_SYNTHCHANNEL ; I++ ){
      if(pParData->synthchannel[I].hdl == pParDataInt){
         pParData->rtEvent.evtbuf[pParData->rtEvent.write&(MELODY_MAX_RTEVT-1)] = 0x10+I;
         pParData->rtEvent.write++;
         if(pParData->synthchannel[I].per){
            pParData->rtEvent.evtbuf[pParData->rtEvent.write&(MELODY_MAX_RTEVT-1)] = -(I+1);
            pParData->rtEvent.write++;
            pParData->synthchannel[I].per = KAL_FALSE;
         }
         pParData->synthchannel[I].hdl = 0;
         pParData->synthchannel[I].used = KAL_FALSE;
      }
   }
#endif
}

void MelodyPar_PutRtMelodyEnd(MEL_ParData *pParData)
{
   pParData->rtEvent.evtbuf[pParData->rtEvent.write&(MELODY_MAX_RTEVT-1)] = 0x20;
   pParData->rtEvent.write++;
}

void MelodyPar_ReleasePer9(MEL_ParData *pParData)
{
#if defined(__AUDIO_ULTRA_SLIM__)
   return;
#else
   int8 I;
   for (I = 0; I<MELODY_MAX_SYNTHCHANNEL; I++){
      pParData->rtEvent.evtbuf[pParData->rtEvent.write&(MELODY_MAX_RTEVT-1)] = -(I+1);
      pParData->rtEvent.write++;
   }
#endif
}

/*
********************************************************************************
*                        MIDI Device Component
********************************************************************************
*/
#if !defined(__AUDIO_ULTRA_SLIM__)

static int8 TransformChannelMessage( MEL_ParData *pParData, int8 status, int8 *c1, int8 *c2 )
{
   int8 type = MELDOY_RTMSG_NONE;
   int8 ch = (int8)(status & 0xf);

   switch ( status & 0xf0 ) {
   case 0x80:
      type = MELODY_RTMSG_NOTEOFF;
      break;
   case 0x90:
      type = (int8)(( *c2 == 0 )? MELODY_RTMSG_NOTEOFF : MELODY_RTMSG_NOTEON);            
      break;     
   case 0xb0:     /* Controller message */
      switch( *c1 ) {
      case 0x00:
         type = MELODY_RTMSG_TONE_BANK_HI;
         break;
      case 0x20:
         type = MELODY_RTMSG_TONE_BANK_LO;
         break;
      case 0x01:
         type = MELODY_RTMSG_MODULATION_WHEEL;
         break;
      case 0x07:
         type = MELODY_RTMSG_VOLUME;
         break;
      case 0x0A:
         type = MELODY_RTMSG_PAN;
         break;
      case 0x0B:
         type = MELODY_RTMSG_EXPRESSION;
         break;
      case 0x40:
         type = MELODY_RTMSG_SUSTAIN;
         break;

      case 98:    pParData->nrpn=KAL_TRUE;  pParData->rpn_lsb[ch] = *c2;    break;
      case 99:    pParData->nrpn=KAL_TRUE;  pParData->rpn_msb[ch] = *c2;    break;
      case 100:   pParData->nrpn=KAL_FALSE; pParData->rpn_lsb[ch] = *c2;    break;
      case 101:   pParData->nrpn=KAL_FALSE; pParData->rpn_msb[ch] = *c2;    break;

      case 0x06:     /* RPN */
         if( pParData->nrpn )
            break;
         switch( ( (int16)pParData->rpn_msb[ch] << 7 ) | (int16)pParData->rpn_lsb[ch] ) {
         case 0x0000: /* Pitch bend sensitivity */
            type = MELODY_RTMSG_PITCH_SENS;
            break;
         case 0x3FFF: /* RPN reset */
            /* reset pitch bend sensitivity to 2 */
            type = MELODY_RTMSG_PITCH_SENS;
            *c2 = 2;
            break;
         }
         break;
      }
      break;
   case 0xc0:
      type = MELODY_RTMSG_PROGRAM;
      break;
   case 0xa0:
      type = MELODY_RTMSG_KEY_PRESSURE;
      break;
   case 0xe0:
      type = MELODY_RTMSG_PITCH_WHEEL;
      break;
   case 0xd0:
      type = MELODY_RTMSG_CHANNEL_PRESSURE;
      break;
   }
   return type;
}

static int8 rtmidiGet( MEL_ParDevMsgQueue *msgqueue )
{
   if( msgqueue->rtmidi_count == 0 )
      return 0;
   msgqueue->rtmidi_count--;
   return *msgqueue->rtmidi_ptr++;
}

static void rtmidiError( MEL_ParDevMsgQueue *msgqueue )
{
   msgqueue->rtmidi_count = 0;
}

static int32 rtmidiReadVarNum( MEL_ParDevMsgQueue *msgqueue )
{
   int32 value;
   int16 c;

   c = rtmidiGet( msgqueue );
   if( !(c & 0x80) )    return c;
   value = c & 0x7F;
   c = rtmidiGet( msgqueue );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) )    return value;
   c = rtmidiGet( msgqueue );
   value = (value << 7) + (c & 0x7f);
   if( !(c & 0x80) )    return value;
   c = rtmidiGet( msgqueue );
   value = (value << 7) + (c & 0x7f);
   return value;
}

static void rtmidi_msg_read( MEL_ParDevMsgQueue *msgqueue )
{
   OMX_U32 count = rtmidiReadVarNum( msgqueue );

   if( count > msgqueue->rtmidi_count )
      msgqueue->rtmidi_count = 0;
   else {
      msgqueue->rtmidi_count -= count;
      msgqueue->rtmidi_ptr += count;
   }
}

static void ReadRTMidiEvent( MEL_ParData *pParData, MEL_ParDevMsgQueue *msgqueue, RT_MidiEvent *nt )
{
   int16 c;
   int needed;
   nt->type = MELDOY_RTMSG_NONE;

   c = rtmidiGet( msgqueue );

   if( c == 0xFF ) {                /* meta event */
      rtmidiGet( msgqueue );                  /* meta event should be ignored in RT MIDI mode */
      rtmidi_msg_read( msgqueue );
   }
   else if( c == 0xF0 ) {           /* start of system exclusive */
      rtmidi_msg_read( msgqueue );
      //SysExEvent( player, player->msgbuff );
   }
   else if( c == 0xF7 ) {           /* sysex continuation or arbitrary stuff */
      rtmidi_msg_read( msgqueue );
   }
   else {
      if( (c & 0x80) == 0 ) {       /* running status? */
         if( msgqueue->rtmidi_status == 0 ) {
            rtmidiError( msgqueue );
            return;
         }
         msgqueue->rtmidi_running = KAL_TRUE;
      }
      else {
         msgqueue->rtmidi_status = (uint8)c;
         msgqueue->rtmidi_running = KAL_FALSE;
      }

      needed = chantype[ (msgqueue->rtmidi_status>>4) & 0xf ];

      if( needed ) {                /* ie. is it a channel message? */
         nt->data1 = ( msgqueue->rtmidi_running )? c : rtmidiGet( msgqueue );
         nt->data2 = ( needed > 1 )? rtmidiGet( msgqueue ):0;
         nt->ch    = msgqueue->rtmidi_status & 0x0F;
         nt->type  = TransformChannelMessage( pParData, msgqueue->rtmidi_status, (int8 *)&(nt->data1), (int8 *)&(nt->data2) );
      }
   }
}

void MelodyDev_GetChannel(MEL_ParDataInt *pParDataInt, kal_uint8* chid, kal_uint8 channel)
{
   kal_uint8 synthch;
   synthch = 0xFE;
   if(channel == 9)
      MelodyPar_GetChannel(pParDataInt, &synthch, 1);
   else
      MelodyPar_GetChannel(pParDataInt, &synthch, 0);
   *chid = synthch;
}

OMX_U32 MelodyDev_GetRTmidi(MEL_ParDataInt *pParDataInt, OMX_U8 *pBuf)
{
   kal_uint32 evtcount;
   kal_uint8 *ptr8;
   kal_uint16 *ptr16, block_num;
   RT_MidiEvent nt;
   MEL_ParDevMsgQueue *msgqueue;
   MEL_ParData *pParData = (MEL_ParData*)pParDataInt->parent;
   
   evtcount = 0;
   ptr8 = (kal_uint8*)pBuf;
   ptr8 += 2;
   
   for(block_num = 0; block_num < MAX_DEVMSG_NUM; block_num++)
   {
      if(pParData->devqueue[block_num].rtmidi_wait == KAL_TRUE)
      {
         msgqueue = (MEL_ParDevMsgQueue*)&pParData->devqueue[block_num];
         nt.type = nt.ch = nt.data1 = nt.data2 = 0;
         while( msgqueue->rtmidi_count > 0 ) 
         {          /* For real-time MIDI playback */
            if( msgqueue->rtmidi_count == 1 ) 
            {
               msgqueue->rtmidi_count = 0;
         break;
      }
            else 
            {
               ReadRTMidiEvent( pParData, msgqueue, &nt );
               if(evtcount >= MELDOY_RTEVT_COUNT)
                  break;
               if(nt.type != MELDOY_RTMSG_NONE)
               {
            if(pParData->devchannel[nt.ch] == 0xFE)
               MelodyDev_GetChannel(pParDataInt, &pParData->devchannel[nt.ch], nt.ch);
                  if(pParData->devchannel[nt.ch]!= 0xFE)
                  {
               evtcount++;
               *ptr8++ = nt.type;
               //*ptr8++ = nt.ch;
               *ptr8++ = pParData->devchannel[nt.ch];
               *ptr8++ = nt.data1;
               if(nt.type == MELODY_RTMSG_NOTEON || nt.type == MELODY_RTMSG_NOTEOFF)
                  *ptr8++ = (nt.data2*pParData->rtmidi_vol)/100;
               else
                  *ptr8++ = nt.data2;
            }
         }
            }
         }
         if(msgqueue->rtmidi_buf)
         {
            audio_free_mem( (void **) &msgqueue->rtmidi_buf);
            msgqueue->rtmidi_buf = NULL;
         }
         msgqueue->rtmidi_wait = KAL_FALSE;
      }
   }
   ptr16 = (OMX_U16*)pBuf;
   *ptr16 = evtcount*4;
   return (evtcount*4)+2;
}

#endif //__AUDIO_ULTRA_SLIM__
void TimeTransform(MEL_ParDataInt *pParDataInt, int flag)
{
   uint32 hipart, lowpart;
   if(flag){
      hipart = (pParDataInt->current_time&0xFFFF0000)>>8;
      lowpart = (pParDataInt->current_time&0xFFFF);
      hipart = ((hipart*10000)/(pParDataInt->playrate*pParDataInt->tsrate));
      lowpart = ((lowpart*10000)/(pParDataInt->playrate*pParDataInt->tsrate));
      pParDataInt->current_time_int = ((hipart<<8) + lowpart);
   }else{
      hipart = (pParDataInt->current_time_int&0xFFFF0000)>>8;
      lowpart = (pParDataInt->current_time_int&0xFFFF);
      hipart = ((hipart*pParDataInt->playrate*pParDataInt->tsrate)/10000);
      lowpart = ((lowpart*pParDataInt->playrate*pParDataInt->tsrate)/10000);
      pParDataInt->current_time = ((hipart<<8) + lowpart);
   }
}

static OMX_ERRORTYPE MelodyPar_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_ParData *pParData = (MEL_ParData *)ihdl->pPrivateData;
   if(ihdl->mediaStatus == COMPONENT_STATE_READY || ihdl->mediaStatus == COMPONENT_STATE_PAUSE){
      ihdl->mediaStatus = COMPONENT_STATE_PLAY;
      pParData->rtEvent.read = 0;
      pParData->rtEvent.write = 0;
      MelodyPar_ReleasePer9(pParData);
      pParData->releasedone = KAL_FALSE;
      pParData->silenceend   = MELODY_SILENCE_END;
      ACU_SendProcessCommandl( (AudComHdlInt *)hdl );
      return OMX_ErrorNone;
   }
   return OMX_ErrorIncorrectStateOperation;
}

static OMX_ERRORTYPE MelodyPar_Stop(AudComHdl *hdl)
{
   kal_uint8 I;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_ParData *pParData = (MEL_ParData *)ihdl->pPrivateData;
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
      ihdl->endStatus = MEDIA_TERMINATED;
   } else {
      ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
   }
   for ( I = 0; I<MELODY_MAXPLAYERS; I++){
      MEL_ParDataInt *pParDataInt = (MEL_ParDataInt*)&pParData->ParDataList[I];
      pParDataInt->status = MELPAR_DATA_IDLE;
      if(pParDataInt->format == FORMAT_SMF || pParDataInt->format == FORMAT_CMI)
         MelodyPar_ReleaseChannel(pParDataInt);
   }
   pParData->releasedone = KAL_FALSE;
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE MelodyPar_GetMetaData(AudComHdl *hdl, OMX_PTR pMetaData)
{
   return OMX_ErrorNotImplemented;
}

OMX_U32 MelodyPar_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for Melody Parser private data
   uTempSize = (sizeof(MEL_ParData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   uTempSize = (MELODY_PARSE_BUFSIZE + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   uTempSize = (MELODY_PLAYER_BUFSIZE + 3) & ~0x3;
   uReqSizeTotal += uTempSize;

   return uReqSizeTotal;
}

static OMX_ERRORTYPE MelodyPar_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_ParData *pParData = (MEL_ParData *)ihdl->pPrivateData;
   MelodyParseParam *pParam = (MelodyParseParam *)pStruct;
   MEL_ParDataInt *pParDataInt;
   pParDataInt = (MEL_ParDataInt*)&pParData->ParDataList[pParam->state_bit];
   
   switch(index){
   // Init Melody Parser
   case OMX_IndexConfigMelodyParserInit:
      pParData->period         = pParam->meldata.period;
      pParDataInt->datahdl     = pParam->meldata.datahdl;
      pParDataInt->getdata     = pParam->meldata.getdata;
      pParDataInt->evthdl      = pParam->meldata.evthdl;
      pParDataInt->evtcall     = pParam->meldata.evtcall;
   #if defined(__AUDIO_ULTRA_SLIM__)
      pParDataInt->channel_hdl = 0;
   #else
      pParDataInt->channel_hdl = pParDataInt;
   #endif
      pParDataInt->getchannel  = &MelodyPar_GetChannel;
      pParDataInt->filelen     = pParam->meldata.filelen;
      pParDataInt->mode        = pParam->meldata.mode;
      pParDataInt->maxtone     = pParam->meldata.maxtone;
      pParDataInt->repeats     = pParam->meldata.repeats;
      pParDataInt->midifile    = pParam->meldata.midifile;
      pParDataInt->stopflag    = KAL_FALSE;
      pParDataInt->mel_hdl     = MelPar_Init( pParDataInt->wrkbuf, (void*)pParDataInt->midifile, pParDataInt->filelen, pParDataInt->mode,
                       DEFAULT_TONE_INST, pParDataInt->maxtone, (void*)pParDataInt->datahdl, 
                       pParDataInt->getdata, pParDataInt->channel_hdl ,&MelodyPar_GetChannel );
      if( pParDataInt->mel_hdl == (void*)0 )
         return OMX_ErrorBadParameter;
      pParDataInt->format = MelPar_QueryFormat(pParDataInt->mel_hdl);
      pParDataInt->duration = MelPar_GetDuration(pParDataInt->mel_hdl);
      ihdl->mediaStatus = COMPONENT_STATE_READY;
      break;
 #if !defined(__AUDIO_ULTRA_SLIM__)
   case OMX_IndexConfigMelodyDeviceInit:
   {
      kal_uint8 I;
      pParDataInt->status           = MELPAR_DATA_IDLE;
      pParDataInt->format           = FORMAT_DEV;
      pParDataInt->current_time     = 0;
      pParDataInt->current_time_int = 0;
      pParDataInt->stop_time        = 0xFFFFFFFF;
      pParDataInt->playrate         = 100;
      pParDataInt->tsrate           = 100;
      pParDataInt->evthdl           = pParam->meldata.evthdl;
      pParDataInt->evtcall          = pParam->meldata.evtcall;
      pParData->rtmidi_vol          = 100;
      pParDataInt->parent           = pParData;
      for(I = 0; I< 16 ; I++)
      {
         pParData->devchannel[I] = 0xFE;
      }
      for(I = 0; I< MAX_DEVMSG_NUM; I++)
      {
         pParData->devqueue[I].rtmidi_count        = 0;
         pParData->devqueue[I].rtmidi_running      = KAL_FALSE;
         pParData->devqueue[I].rtmidi_status       = 0;
         pParData->devqueue[I].rtmidi_wait         = KAL_FALSE;
         pParData->devqueue[I].rtmidi_buf          = NULL;
      }
      ihdl->mediaStatus = COMPONENT_STATE_READY;
      break;
   }
  #endif
   case OMX_IndexConfigMelodyPlayerInit:
      pParDataInt->status           = MELPAR_DATA_IDLE;
      pParDataInt->wrkbuf           = pParam->wrkbuf;
      pParDataInt->current_time     = 0;
      pParDataInt->current_time_int = 0;
      pParDataInt->stop_time        = 0xFFFFFFFF;
      pParDataInt->playrate         = 100;
      pParDataInt->tsrate           = 100;
      pParDataInt->parent           = pParData;
#if defined(MELODY_POP_WRKRND)
      pParDataInt->silencecnt       = MELODY_SILENCECNT;
#endif
      break;
   case OMX_IndexConfigMelodyPlayerFree:
      pParDataInt->status           = MELPAR_DATA_FREE;
      MelodyPar_ReleaseChannel(pParDataInt);
      pParDataInt->wrkbuf           = 0;
      break;
   case OMX_IndexConfigMelodyGetParserMemSize:
   {
      kal_int32 tmpInterSize, tmpOutSize;
      MelPar_GetBufferSize(&tmpInterSize, &tmpOutSize);
      pParam->data = (kal_uint32)tmpInterSize;
   }
      break;   
   case OMX_IndexConfigMelodyPlayerStart:
      if(pParDataInt->status == MELPAR_DATA_IDLE){
         pParDataInt->status = MELPAR_DATA_START;
         pParDataInt->stopflag = false;
         pParData->runstate |= (1<<pParam->state_bit);
         //pParData->releasedone = true;
      }
      break;
   case OMX_IndexConfigMelodyPlayerStop:
      if(pParDataInt->status != MELPAR_DATA_IDLE)
           pParDataInt->stopflag = KAL_TRUE;
      break;
   case OMX_IndexConfigMelodyGetParserState:
      pParam->data = pParDataInt->status;
        break;     
   // Get Melody Tempo
   case OMX_IndexConfigMelodyGetTempo:
      if(pParDataInt->format != FORMAT_DEV){
         pParam->data = MelPar_GetTempo(pParDataInt->mel_hdl);
         break;
      }
   // Set Melody Tempo
   case OMX_IndexConfigMelodySetTempo:
      if(pParDataInt->format != FORMAT_DEV){
         if(MelPar_SetTempo(pParDataInt->mel_hdl,pParam->data) != MELPAR_SUCCESS)
            return OMX_ErrorBadParameter;
      }
      break;
   // Get Parser parse rate
   case OMX_IndexConfigMelodyGetPlayRate:
      if(pParDataInt->format != FORMAT_DEV)
         pParam->data = MelPar_GetPlayRate(pParDataInt->mel_hdl);
      break;
   // Set Parser parse rate
   case OMX_IndexConfigMelodySetPlayRate:
      if(pParDataInt->format != FORMAT_DEV){
         if(MelPar_SetPlayRate(pParDataInt->mel_hdl,pParam->data) != MELPAR_SUCCESS)
            return OMX_ErrorBadParameter;
         pParDataInt->playrate = pParam->data;
         TimeTransform(pParDataInt, 1);
      }
      break;
   // Get Melody Time Stretch Rate
   case OMX_IndexConfigMelodyGetTsRate:
      if(pParDataInt->format != FORMAT_DEV)
         pParam->data = MelPar_GetTsRate(pParDataInt->mel_hdl);
      break;
   // Set Melody Time Stretch Rate
   case OMX_IndexConfigMelodySetTsRate:
      if(pParDataInt->format != FORMAT_DEV){
         if(MelPar_SetTsRate(pParDataInt->mel_hdl,pParam->data) != MELPAR_SUCCESS)
            return OMX_ErrorBadParameter;
         pParDataInt->tsrate = pParam->data;
         TimeTransform(pParDataInt, 1);
      }
      break;
   // Check if the Melody contains SP-MIDI Message
   case OMX_IndexConfigMelodySpMidi:
   	  if(pParDataInt->format != FORMAT_DEV)
         pParam->data = MelPar_isSpMidi(pParDataInt->mel_hdl);
      break;
   // Get Current Parsed-time
   case OMX_IndexConfigMelodyGetParsedTime:
   	  if(pParDataInt->format != FORMAT_DEV)
         pParam->data = MelPar_GetParsedTime(pParDataInt->mel_hdl);
      break;
   // Get Melody Duration
   case OMX_IndexConfigMelodyGetDuration:
      pParam->data = pParDataInt->duration;
      break;
   // Seek to desired time
   case OMX_IndexConfigMelodySetStartTime:
      pParDataInt->start_time = pParam->data;
      //pParData->current_time = pParam->data;
      break;
   // Set Stop time
   case OMX_IndexConfigMelodySetStopTime:
      pParDataInt->stop_time = pParam->data;
      break;
   // Get current time, temp solution
   case OMX_IndexConfigMelodyGetCurrentTime:
        if(pParDataInt->current_time < pParDataInt->start_time)
           pParam->data = pParDataInt->start_time;
        else
           pParam->data = pParDataInt->current_time;
        break;
   case OMX_IndexConfigMelodySynthesisDone:
      pParData->releasedone = KAL_TRUE;
      break;
   case OMX_IndexConfigMelodyGetFormat:
      if(pParDataInt->format != FORMAT_DEV)
         pParam->data = MelPar_QueryFormat(pParDataInt->mel_hdl);
      break;
  #if !defined(__AUDIO_ULTRA_SLIM__)
   case OMX_IndexConfigMelodySendMessage:
   {
      kal_uint16 block_num, block_len;
      for( block_num = 0; block_num < MAX_DEVMSG_NUM; block_num++)
      {
         if(pParData->devqueue[block_num].rtmidi_wait == KAL_FALSE)
         {
            pParData->devqueue[block_num].rtmidi_buf     = (kal_uint8*)audio_alloc_mem_cacheable( sizeof(kal_uint8)*pParam->meldata.rtmidi_count );
            if(!pParData->devqueue[block_num].rtmidi_buf)
               break;
            pParData->devqueue[block_num].rtmidi_running = pParam->meldata.rtmidi_running;
            pParData->devqueue[block_num].rtmidi_status  = pParam->meldata.rtmidi_status;
            pParData->devqueue[block_num].rtmidi_count   = pParam->meldata.rtmidi_count;
            memcpy((kal_uint8*)pParData->devqueue[block_num].rtmidi_buf, (kal_uint8*)pParam->meldata.rtmidi_ptr, pParam->meldata.rtmidi_count*sizeof(kal_uint8));
            pParData->devqueue[block_num].rtmidi_ptr     = pParData->devqueue[block_num].rtmidi_buf;
            pParData->devqueue[block_num].rtmidi_wait    = pParam->meldata.rtmidi_wait;
            break;
         }
      }
   }
   break;
  #endif      
   case OMX_IndexConfigMelodySetParserLevel:
      if(pParDataInt->format != FORMAT_DEV)
         MelPar_SetVolumeLevel(pParDataInt->mel_hdl, pParam->data);
      else
         pParData->rtmidi_vol = pParam->data;
      break;
   default:
      return OMX_ErrorNotImplemented;
   }
   return OMX_ErrorNone;
}

void MelodyPar_RtEvt( MEL_ParData *pParData )
{
   kal_int8 ch;
   kal_int8 *ptr8 = (kal_int8*)pParData->parseroutput + pParData->totallen;
   while(pParData->rtEvent.read < pParData->rtEvent.write){
      ch = pParData->rtEvent.evtbuf[pParData->rtEvent.read&(MELODY_MAX_RTEVT-1)];
      pParData->rtEvent.read++;
      if(ch >= 0){
         if(ch & 0x10){
            *ptr8++ = MELODY_RTMSG_ALL_SOUNDS_OFF;
            *ptr8++ = ch&0x0F;
         }else if(ch&0x20){
            *ptr8++ = MELODY_RTMSG_END;
            *ptr8++ = 0;
         }
         else{
            *ptr8++ = MELODY_RTMSG_SET_PER;
            *ptr8++ = ch;
         }
      }else{
         *ptr8++ = MELODY_RTMSG_RELEASE_PER;
         *ptr8++ = -(ch+1);
      }
      *ptr8++ = 0;
      *ptr8++ = 0;
      pParData->totallen += 4;
   }
}

kal_bool MelodyPar_ParseEvt( MEL_ParData *pParData )
{
   kal_uint8 I;
   kal_int8 *ptr8;
   kal_int16 *ptr16;
   kal_uint32 evtlen;
   MEL_ParDataInt *pParDataInt;
   kal_bool ending = KAL_TRUE;
   pParData->totallen = 2;
   MelodyPar_RtEvt(pParData);
#if defined(__AUDIO_ULTRA_SLIM__)
   for( I = 0 ; I< MELODY_MAXPLAYERS; I++){
      pParDataInt = (MEL_ParDataInt*)&pParData->ParDataList[I];
      if(pParDataInt->stopflag == KAL_TRUE && pParDataInt->status != MELPAR_DATA_RELEASE){
         pParDataInt->status = MELPAR_DATA_IDLE;
         pParDataInt->stopflag = false;
      }
      switch(pParDataInt->status){
      case MELPAR_DATA_FREE:
      case MELPAR_DATA_IDLE:
         break;
      case MELPAR_DATA_START:
         if( MelPar_Seek(pParDataInt->mel_hdl,pParDataInt->start_time) == MELPAR_SUCCESS){
            pParDataInt->current_time = pParDataInt->start_time;
            TimeTransform(pParDataInt, 1);
            pParDataInt->status = MELPAR_DATA_RUN;
            ending = false;
         }
         break;
      case MELPAR_DATA_RUN:
         if( MelPar_Parse( pParDataInt->mel_hdl, pParData->period, (kal_int32*)&pParDataInt->delta_ms, (char*)pParData->playeroutput, (kal_int32*)&evtlen ) != MELPAR_SUCCESS )
         {
            if( pParDataInt->repeats == 1 )
            {
               if((pParData->runstate & ~(1<<I)) != 0)
               {
                  pParDataInt->status = MELPAR_DATA_EOF;
                  pParDataInt->evtcall( pParDataInt->evthdl, MELODY_END);
               }else
               {
                  pParDataInt->status = MELPAR_DATA_RELEASE;
                  pParDataInt->evtcall( pParDataInt->evthdl, MELODY_RELEASE);
                  MelodyPar_PutRtMelodyEnd(pParData);
               #if defined(MELODY_NOSOUND_WRKRND)
                  pParData->silenceend   = MELODY_SILENCE_END;
               #endif
               }
            }else{
               ending = false;
               MelodyPar_PutRtMelodyEnd(pParData);
               MelodyPar_RtEvt(pParData);
               if(pParDataInt->repeats != 0)
                  pParDataInt->repeats--;
               MelPar_Seek( pParDataInt->mel_hdl, 0 );
               pParDataInt->evtcall( pParDataInt->evthdl, MELODY_REPEAT );
               pParDataInt->current_time = 0;
               pParDataInt->current_time_int = 0;
            }
         }else
         {
            ending = false;
            MelodyPar_RtEvt(pParData);
            if(pParData->totallen + evtlen < MELODY_PARSE_BUFSIZE)
            {
               ptr8 = (kal_int8*)pParData->parseroutput + pParData->totallen;
               memcpy(ptr8,&pParData->playeroutput[2], evtlen-2);
               pParData->totallen += (evtlen - 2);
            }
            pParDataInt->current_time_int += MELODY_PERIOD;
            TimeTransform(pParDataInt, 0);
            if(pParDataInt->current_time > pParDataInt->duration)
               pParDataInt->current_time = pParDataInt->duration;
            if(pParDataInt->current_time >= pParDataInt->stop_time)
            {
               pParDataInt->current_time = pParDataInt->stop_time;
               pParDataInt->status = MELPAR_DATA_EOF;
               pParDataInt->evtcall( pParDataInt->evthdl, MELODY_END);
            }
         }
         break;
      case MELPAR_DATA_STOP:
         pParDataInt->status = MELPAR_DATA_IDLE;
         break;
      case MELPAR_DATA_EOF:
         pParDataInt->status = MELPAR_DATA_IDLE;
         ending = false;
         break;
      case MELPAR_DATA_RELEASE:
      #if defined(MELODY_NOSOUND_WRKRND)
        if((pParData->releasedone && pParData->silenceend == 0) || pParDataInt->stopflag){
      #else
        if(pParData->releasedone || pParDataInt->stopflag){
      #endif
            pParDataInt->evtcall( pParDataInt->evthdl, MELODY_RELEASEDONE );
            if(!pParDataInt->stopflag)
               pParDataInt->evtcall( pParDataInt->evthdl, MELODY_END );

            pParDataInt->stopflag = false;
            pParDataInt->status = MELPAR_DATA_IDLE;
         }
         break;
      default:
         break;
      }
   }
#else
   for( I = 0 ; I< MELODY_MAXPLAYERS; I++){
      pParDataInt = (MEL_ParDataInt*)&pParData->ParDataList[I];
      if(pParDataInt->stopflag == KAL_TRUE && pParDataInt->status != MELPAR_DATA_RELEASE){
         pParDataInt->status = MELPAR_DATA_IDLE;
         if(pParDataInt->format != FORMAT_IMY && pParDataInt->format != FORMAT_JTS)
            MelodyPar_ReleaseChannel(pParDataInt);
         pParData->runstate &= ~(1<<I);
         pParDataInt->stopflag = false;
      }
      switch(pParDataInt->status){
      case MELPAR_DATA_FREE:
      case MELPAR_DATA_IDLE:
         break;
      case MELPAR_DATA_START:
         if(pParDataInt->format == FORMAT_DEV){
            pParDataInt->status = MELPAR_DATA_RUN;
            ending = false;
            break;
         }
         if(pParDataInt->format == FORMAT_SMF || pParDataInt->format == FORMAT_CMI)
            MelPar_ResetSynthChannel(pParDataInt->mel_hdl);
         if( MelPar_Seek(pParDataInt->mel_hdl,pParDataInt->start_time) == MELPAR_SUCCESS){
            pParDataInt->current_time = pParDataInt->start_time;
            TimeTransform(pParDataInt, 1);
            pParDataInt->status = MELPAR_DATA_RUN;
            ending = false;
            pParData->runstate |= (1<<I);
         }
         break;
      case MELPAR_DATA_RUN:
         if( pParDataInt->format != FORMAT_DEV){
            if( MelPar_Parse( pParDataInt->mel_hdl, pParData->period, (kal_int32*)&pParDataInt->delta_ms, (char*)pParData->playeroutput, (kal_int32*)&evtlen ) != MELPAR_SUCCESS ){
               if( pParDataInt->repeats == 1 ){
                  if((pParData->runstate & ~(1<<I)) != 0){
                     pParDataInt->status = MELPAR_DATA_EOF;
                     pParDataInt->evtcall( pParDataInt->evthdl, MELODY_END);
                     pParData->runstate &= ~(1<<I);
                  }else{
                     pParDataInt->status = MELPAR_DATA_RELEASE;
                     pParDataInt->evtcall( pParDataInt->evthdl, MELODY_RELEASE);
                     MelodyPar_PutRtMelodyEnd(pParData);
                  #if defined(MELODY_NOSOUND_WRKRND)
                     pParData->silenceend   = MELODY_SILENCE_END;
                  #endif
                  }
               }else{
                  ending = false;
                  MelodyPar_PutRtMelodyEnd(pParData);
                  MelodyPar_RtEvt(pParData);
                  if(pParDataInt->repeats != 0)
                     pParDataInt->repeats--;
                  MelPar_Seek( pParDataInt->mel_hdl, 0 );
                  pParDataInt->evtcall( pParDataInt->evthdl, MELODY_REPEAT );
                  pParDataInt->current_time = 0;
                  pParDataInt->current_time_int = 0;
               }
            }else{
               ending = false;
               MelodyPar_RtEvt(pParData);
               if(pParData->totallen + evtlen < MELODY_PARSE_BUFSIZE){
                  ptr8 = (kal_int8*)pParData->parseroutput + pParData->totallen;
                  memcpy(ptr8,&pParData->playeroutput[2], evtlen-2);
                  pParData->totallen += (evtlen - 2);
               }
               pParDataInt->current_time_int += MELODY_PERIOD;
               TimeTransform(pParDataInt, 0);
               if(pParDataInt->current_time > pParDataInt->duration)
                  pParDataInt->current_time = pParDataInt->duration;
               if(pParDataInt->current_time >= pParDataInt->stop_time){
                  pParDataInt->current_time = pParDataInt->stop_time;
                  pParDataInt->status = MELPAR_DATA_EOF;
                  pParDataInt->evtcall( pParDataInt->evthdl, MELODY_END);
               }
            }
         }else{
            ending = false;
            evtlen = MelodyDev_GetRTmidi(pParDataInt, (kal_uint8*)pParData->playeroutput);
            MelodyPar_RtEvt(pParData);
            if(pParData->totallen + evtlen < MELODY_PARSE_BUFSIZE){
               ptr8 = (kal_int8*)pParData->parseroutput + pParData->totallen;
               memcpy(ptr8,&pParData->playeroutput[2], evtlen-2);
               pParData->totallen += (evtlen - 2);
            }
         }
         break;
      case MELPAR_DATA_STOP:
         pParDataInt->status = MELPAR_DATA_IDLE;
         break;
      case MELPAR_DATA_EOF:
         if(pParDataInt->format == FORMAT_SMF || pParDataInt->format == FORMAT_DEV || pParDataInt->format == FORMAT_CMI){
            MelodyPar_ReleaseChannel(pParDataInt);
            MelodyPar_RtEvt(pParData);
         }
         pParDataInt->status = MELPAR_DATA_IDLE;
         ending = false;
         break;
      case MELPAR_DATA_RELEASE:
        if((pParData->runstate & ~(1<<I)) != 0){
           pParDataInt->status = MELPAR_DATA_EOF;
           pParDataInt->evtcall( pParDataInt->evthdl, MELODY_END);
           pParData->runstate &= ~(1<<I);
        }
      #if defined(MELODY_NOSOUND_WRKRND)
        else if((pParData->releasedone && pParData->silenceend == 0) || pParDataInt->stopflag){
      #else
        else if(pParData->releasedone || pParDataInt->stopflag){
      #endif
            pParDataInt->evtcall( pParDataInt->evthdl, MELODY_RELEASEDONE );
            if(!pParDataInt->stopflag)
               pParDataInt->evtcall( pParDataInt->evthdl, MELODY_END );

               pParDataInt->stopflag = false;
            pParDataInt->status = MELPAR_DATA_IDLE;
            if(pParDataInt->format == FORMAT_SMF || pParDataInt->format == FORMAT_DEV || pParDataInt->format == FORMAT_CMI){
               MelodyPar_ReleaseChannel(pParDataInt);
               MelodyPar_RtEvt(pParData);
            }
            pParData->runstate &= ~(1<<I);
         }
         break;
      default:
         break;
      }
   }
#endif //__AUDIO_ULTRA_SLIM__
   ptr16 = (kal_int16*)pParData->parseroutput;
   *ptr16 = pParData->totallen -2;
   return ending; 
}

static OMX_ERRORTYPE MelodyPar_Process(AudComHdl *hdl)
{
   OMX_BUFFERHEADERTYPE *pBufHdr;
   OMX_U32 bufDataSize;
   OMX_U8 *pBuf;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MEL_ParData *pParData = (MEL_ParData *)ihdl->pPrivateData;
   
   if(ihdl->mediaStatus == COMPONENT_STATE_IDLE)
      return OMX_ErrorNone;
   
   ACU_GetWriteBuffer(hdl, &pBuf, &bufDataSize);
   
   if (bufDataSize == 0) {
      return OMX_ErrorNone;
   }else {
      pBufHdr = ihdl->OutputQ.pCurBufHdr;
   }
   
   if( (pBufHdr->nFlags&OMX_BUFFERFLAG_EOS) && (ihdl->mediaStatus != COMPONENT_STATE_PLAY))
      return OMX_ErrorNone;
   
   if(ihdl->mediaStatus == COMPONENT_STATE_PAUSE ){
      ihdl->mediaStatus = COMPONENT_STATE_PAUSE;
      ACU_SetEOS(hdl);
      return OMX_ErrorNone;
   }   
#if defined(MELODY_POP_WRKRND)
   if( pParDataInt->silencecnt){
        OMX_U16 *ptr16 = (OMX_U16*)pBuf;
        *ptr16 = 0;
      pParDataInt->silencecnt--;
      ACU_WriteDataDone_ImmediateCallback(hdl, 2);
      return OMX_ErrorNone;
   }
#endif   
   if( MelodyPar_ParseEvt( pParData ) ){
   #if defined(MELODY_NOSOUND_WRKRND)
      if( pParData->silenceend)
         pParData->silenceend--;
   #endif
   }else{
      pBufHdr->nFlags &= ~OMX_BUFFERFLAG_EOS;
      pParData->releasedone = false;
   }
   if(pParData->totallen!=0)
      memcpy(pBuf,pParData->parseroutput,pParData->totallen);
   ACU_WriteDataDone_ImmediateCallback(hdl, pParData->totallen);

   return OMX_ErrorNone;
}

OMX_ERRORTYPE MelodyPar_Deinit(AudComHdl *hdl)
{
   ACU_FlushBufferQueue(hdl);
   //L1Audio_FreeAudioID( ihdl->aud_id );
   
   return OMX_ErrorNone;
}

OMX_ERRORTYPE MelodyPar_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_int8 *pBuffer8;
   kal_uint8 I;
   MEL_ParData *pParData;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = MelodyPar_GetMemSize();
   memset(pBuffer, 0, uBufSize);

   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_int8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   
   // Melody Parser Private Data
   ihdl->pPrivateData = (void *)pBuffer8;
   pParData = (MEL_ParData *)ihdl->pPrivateData;
   
   pBuffer8 += (sizeof(MEL_ParData) + 3) & ~0x3;   
   pParData->parseroutput = pBuffer8;
   
   pBuffer8 += (MELODY_PARSE_BUFSIZE + 3) & ~0x3;   
   pParData->playeroutput = pBuffer8;
             
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start        = MelodyPar_Start;
   ihdl->basic.Stop         = MelodyPar_Stop;
   ihdl->basic.Deinit       = MelodyPar_Deinit;
   ihdl->basic.Process      = MelodyPar_Process;
   ihdl->basic.SetParameter = MelodyPar_SetParameter;
   ihdl->basic.GetMetaData  = MelodyPar_GetMetaData;

   ihdl->mediaStatus = COMPONENT_STATE_IDLE;
   pParData->releasedone  = false;
#if !defined(__AUDIO_ULTRA_SLIM__)
   for (I = 0; I< MELODY_MAX_SYNTHCHANNEL ; I++){
      pParData->synthchannel[I].used = false;
      pParData->synthchannel[I].per  = false;
      pParData->synthchannel[I].hdl  = 0;
   }
#endif
   for(I = 0; I < MELODY_MAXPLAYERS; I++){
      pParData->ParDataList[I].wrkbuf   = 0;
      pParData->ParDataList[I].format   = (MIDI_Format)0;
      pParData->ParDataList[I].status   = MELPAR_DATA_FREE;
      pParData->ParDataList[I].stopflag = false;
   }
   pParData->runstate = 0;
   MelodyPar_ReleasePer9(pParData);
#if defined(MELODY_NOSOUND_WRKRND)
   pParData->silenceend   = MELODY_SILENCE_END;
#endif
   return OMX_ErrorNone;
}

#else
#error the framework should either be SINGLE_PASER_SINGLE_WTSYNTH or MULTIPLE_PASER_SINGLE_WTSYNTH
#endif /* SINGLE_PASER_SINGLE_WTSYNTH, MULTIPLE_PASER_SINGLE_WTSYNTH */



#endif  /* DSP_WT_SYN */
