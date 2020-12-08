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
 * melody_common.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Melody Common Part
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
 * removed!

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#if defined( DSP_WT_SYN )

#include "melody_sw_syn.h"
#include "common_def.h"
#include "dpmgr.h"
/*
*/
/*
********************************************************************************
*                        Buffer Control Functions
********************************************************************************
*/

/*------------------------------------------------*/
/* The private member functions of callbacks.     */
/*------------------------------------------------*/
OMX_ERRORTYPE MidiEmptyBufferDone(
   AudComHdl *hdl,
   void *pFWData,
   OMX_BUFFERHEADERTYPE *pBufHdr)
{
   AcHdlNode *pHdlNode = (AcHdlNode *)pFWData;
   
   pBufHdr->nOffset = 0;
   pBufHdr->nFilledLen = 0;
   
   if (pHdlNode->prev) {
      AudComHdl *pPrevHdl = pHdlNode->prev;
      
      pPrevHdl->FillThisBuffer(pPrevHdl, pBufHdr);
      pPrevHdl->Process(pPrevHdl);
   }
   
   return OMX_ErrorNone;
}

OMX_ERRORTYPE MidiFillBufferDone(
   AudComHdl *hdl,
   void *pFWData,
   OMX_BUFFERHEADERTYPE *pBufHdr)
{
   AcHdlNode *pHdlNode = (AcHdlNode *)pFWData;
   
   if (pHdlNode->next) {
      AudComHdl *pNextHdl = pHdlNode->next;
      
      pNextHdl->EmptyThisBuffer(pNextHdl, pBufHdr);
      pNextHdl->Process(pNextHdl);
   }

   return OMX_ErrorNone;
}

OMX_ERRORTYPE MidiEventHandler(
   AudComHdl *hdl,
   void *pFWData,
   OMX_EVENTTYPE eEvent,
   OMX_U32 nData1,
   OMX_U32 nData2,
   void *pEventData)
{
   return OMX_ErrorNone;
}

AudComCallback Swsyn_Callback = {
   MidiEventHandler,
   MidiEmptyBufferDone,
   MidiFillBufferDone
};

static void DummyHisr( void *data ){}

void MelodyComp_MsgHandler(MHdl *handle, Media_Event event)
{
   Media_Handle *hdl;
   MIDI_Player *player;
   hdl =  (Media_Handle*)handle->private_data;
   player = (MIDI_Player *)hdl->data;
   if(player->format != MELODYFORMAT_DEV)
   {
      switch(event)
      {
         case MEDIA_END:
            hdl->handler(hdl,MEDIA_END);
         break;
      }
   }
}

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
*                        Utility Functions
********************************************************************************
*/
Media_Status MelodyComp_Stop( Media_Handle *handle );
void MelodyComp_ReleaseDone( Media_Handle *handle );
void MelodyComp_Repeat( Media_Handle *handle );
void MelodyComp_StopInMed(void *data, Media_Event event);
void MelodyComp_Bootup( void ){}
void MelodyComp_EvtCallback(void *hdl, int evt)
{
   MelodyDevParam *devdata;
   Media_Handle *handle = (Media_Handle*)hdl;
   MIDI_Player *player = (MIDI_Player *)handle->data;
   Media_Event event;
   
   
   switch((MELODY_EVENT_CALLBACK)evt){
   case MELODY_SYNTHDONE:
      MelodyComp_ReleaseDone(handle);
      return;
#if !defined(WT_NO_IMYEFFECTS)
   case MELODY_LED_ON:
      event = MEDIA_LED_ON;
      break;
   case MELODY_LED_OFF:
      event = MEDIA_LED_OFF; 
      break;
   case MELODY_VIBRATOR_ON:
      event = MEDIA_VIBRATOR_ON;
      break;
   case MELODY_VIBRATOR_OFF:
      event = MEDIA_VIBRATOR_OFF;
      break;
   case MELODY_BACKLIGHT_ON:
      event = MEDIA_BACKLIGHT_ON;
      break;
   case MELODY_BACKLIGHT_OFF:
      event = MEDIA_BACKLIGHT_OFF;
      break;
#endif
   case MELODY_REPEAT:
      MelodyComp_Repeat(handle);
      event = MEDIA_REPEATED;
      break;
   case MELODY_END:
      return;
   case MELODY_MSG_DONE:
   	  devdata = (MelodyDevParam*)&player->devdata;
        devdata->meldata.rtmidi_wait = KAL_FALSE;
      return;
   default:
      return;
   }
   handle->handler(handle, event);
   return;
}

Media_Handle *MelodyComp_ObtainHandle( kal_bool mid_device )
{
   Media_Handle *handle;
   handle = (Media_Handle*)get_ctrl_buffer(sizeof(Media_Handle));
   return handle;
}

void MelodyComp_ReleaseDone( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
   
   player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodySynthesisDone, parsedata );
}

void MelodyComp_Repeat( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   synthdata = (MelodySynthParam*)&player->synthdata;
   
   player->DecNode.curHdl->SetParameter( player->DecNode.curHdl, OMX_IndexConfigMelodyRepeat, synthdata );
}
Media_Status MelodyComp_SendLongMsg( Media_Handle *handle, const uint8 *buf, uint16 len )
{
   uint16 I;
   MelodyDevParam *devdata;
   MIDI_Player *player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   devdata = (MelodyDevParam*)&player->devdata;
   
   if(len == 0 || buf == 0)
      return MEDIA_FAIL;
   
   devdata->meldata.rtmidi_running = KAL_FALSE;
   devdata->meldata.rtmidi_status  = 0;
   devdata->meldata.rtmidi_ptr     = buf;
   devdata->meldata.rtmidi_count   = len;
   devdata->meldata.rtmidi_wait    = KAL_TRUE;
   if( player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodySendMessage, devdata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
   
   for( I = 0; ; I++ ) {
      if(devdata->meldata.rtmidi_wait == KAL_FALSE)
         break;
      ASSERT_REBOOT( I < 80 );
      kal_sleep_task( 1 );
   }
   return MEDIA_SUCCESS;
}

Media_Status MelodyComp_SendShortMsg( Media_Handle *handle, kal_uint8 type, kal_uint8 data1, kal_uint8 data2 )
{
   uint8 buf[3];
   MIDI_Player *player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   if((type&0xF0) == 0xC0){
      player->tckmidchannel[type&0x0F].program = data1;
   }else if((type&0xF0) == 0xB0){
      if(data1 == 0x07){
         player->tckmidchannel[type&0x0F].volume = data2;
      }
   }
   buf[0] = type;
   buf[1] = data1;
   buf[2] = data2;
   return JMidi_SendLongMsg( handle, buf, 3 );
}

/*
********************************************************************************
*                        Initialize Functions
********************************************************************************
*/
extern void SMF_GetFSData(void *hdl, int evt, unsigned char* ptr, unsigned int len);

void MelodyComp_InitIP(Media_Handle *handle)
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   const uint8 *midifile;
   MelodyParseParam *parsedata;
   MelodySynthParam *synthdata;
   SinkParam sinkParam;
   
#if defined(WTDPMGR_LOCK_IN_GETDURATION)
   if(!player->dpmrgwt_check){
//      DPMGR_Load(DPMGR_WAVETABLE);
      player->dpmrgwt_check   = KAL_TRUE;
   }
#endif
#if defined( MIDFILE_PLAY_SUPPORT )
   STFSAL *pstFSAL;
   if( player->format == MELODYFORMAT_SMF)
      pstFSAL = player->param.smf.pstFSAL;
   else
      pstFSAL = NULL;
#endif

   parsedata                  = &player->parsedata;
   synthdata = (MelodySynthParam*)&player->synthdata;
   parsedata->meldata.maxtone = MELODY_MAX_POLYPHONY;
   switch(player->format)
   {
   case MELODYFORMAT_SMF:
      handle->repeat_count         = ((Media_SMF_Param *)handle->param)->repeats;
      synthdata->meldata.tonegain  = DG_SMF_NOTE;
      break;
   case MELODYFORMAT_DEV:
   	  handle->repeat_count         = 0;
   	  synthdata->meldata.tonegain  = DG_IMY_NOTE;
      break;
   case MELODYFORMAT_IMY:
      handle->repeat_count         = ((Media_iMelody_Param *)handle->param)->repeats;
      synthdata->meldata.tonegain  = DG_IMY_NOTE;
      break;
#if defined(JTONE_SUPPORT)      
   case MELODYFORMAT_JTS:
      handle->repeat_count         = ((Media_ToneSeq_Param *)handle->param)->repeats;
      synthdata->meldata.tonegain  = DG_JTS_NOTE;
      break;
#endif
   default:
      ASSERT(KAL_FALSE);
   }
   parsedata->meldata.repeats = handle->repeat_count;
#if defined( MIDFILE_PLAY_SUPPORT )
   if( pstFSAL!=NULL ){
      FSAL_GetFileSize(pstFSAL, &player->fsize);
      parsedata->meldata.filelen  = player->fsize;
      parsedata->meldata.mode     = FS_MODE;
      parsedata->meldata.datahdl  = player;
      parsedata->meldata.getdata  = &SMF_GetFSData;
      player->fplay       = KAL_TRUE;
      
      handle->start_time  = handle->current_time = 0;
      player->jstart_time = 0;
   }else{
#endif
      player->fplay = KAL_FALSE;
      midifile = NULL;
      switch(player->format)
      {
      case MELODYFORMAT_SMF:
         midifile = player->param.smf.smffile;
         parsedata->meldata.filelen = player->param.smf.filesize;
         break;
      case MELODYFORMAT_IMY:
         midifile = player->param.imy.imyfile;
         parsedata->meldata.filelen = player->param.imy.filesize;
         break;
#if defined(JTONE_SUPPORT)          
      case MELODYFORMAT_JTS:
         midifile = player->param.jts.toneSeq;
         parsedata->meldata.filelen = player->param.jts.toneSeqLen;
         break;
#endif
      case MELODYFORMAT_DEV:
         midifile = NULL;
         parsedata->meldata.filelen = 0;
         break;
      default:
         ASSERT(KAL_FALSE);
      }
      parsedata->meldata.midifile = midifile;
      parsedata->meldata.mode     = BUFFER_MODE;
      parsedata->meldata.period   = MELODY_PERIOD;
      parsedata->meldata.datahdl  = (void*)0;
      parsedata->meldata.getdata  = (void*)0;
      parsedata->meldata.evthdl   = handle;
      parsedata->meldata.evtcall  = &MelodyComp_EvtCallback;
#if defined( MIDFILE_PLAY_SUPPORT )
   }
#endif
   if( player->ParNode.curHdl->SetParameter(player->ParNode.curHdl, OMX_IndexConfigMelodyParserInit, parsedata) != OMX_ErrorNone ){
      player->bad_format = KAL_TRUE;
   }else{
      synthdata->meldata.samplerate = MELODY_SAMPLINGRATE;
      synthdata->meldata.maxtone    = MELODY_MAX_POLYPHONY;
      synthdata->meldata.finetone   = MELODY_FINE_POLYPHONY;
      synthdata->meldata.period     = MELODY_SYNTH_PERIOD;
      synthdata->meldata.wavtab     = (unsigned char*)Wavetable;
      synthdata->meldata.evthdl     = handle;
      synthdata->meldata.evtcall    = &MelodyComp_EvtCallback;

      player->DecNode.curHdl->SetParameter(player->DecNode.curHdl, OMX_IndexConfigMelodySynthesizerInit, synthdata);
   }
   sinkParam.uSamplingFreq = 32000;
   sinkParam.uChannelNum   = 2;
   player->SinkNode.curHdl->SetParameter(player->SinkNode.curHdl, OMX_IndexParamMediaTekPcmSink, &sinkParam);
   
   player->init = KAL_TRUE;

#if defined(WTDPMGR_LOCK_IN_GETDURATION)
   if(player->dpmrgwt_check){
//      DPMGR_Unload(DPMGR_WAVETABLE);
      player->dpmrgwt_check   = KAL_FALSE;
   }
#endif
}

void MelodyComp_Init(Media_Handle *handle, MIDI_Player *player, bool isMidiDevice)
{
   kal_uint8 *wrkbuf;
   MHdl *mhhdl;
   MHPB_Internal *imhhdl;
   AudComHdlInt *pIntHdl;
   OMX_BUFFERHEADERTYPE *pBufHdr;
   kal_uint32 I, totalsize, parsize, synsize, sinksize, parnum, synnum;
   
   if(isMidiDevice)
      parsize = MelodyDev_GetMemSize();
   else
      parsize = MelodyPar_GetMemSize();
   
   synsize = MelodySyn_GetMemSize();
   sinksize = PcmRender_GetMemSize();
   parnum = MELODY_PARSE_BUFNUM;
   synnum = MELODY_SYNTH_BUFNUM;

   totalsize = parnum*MELODY_PARSE_BUFSIZE + synnum*MELODY_SYNTH_BUFSIZE
               +(parnum + synnum)*sizeof(OMX_BUFFERHEADERTYPE) + parsize + synsize + sinksize;
   
   
   player->wrkbuf = (kal_uint8*)audio_alloc_mem_cacheable( sizeof(kal_uint8)*totalsize );
   ASSERT(player->wrkbuf);
   memset(player->wrkbuf, 0, totalsize);
   wrkbuf = (kal_uint8*)player->wrkbuf;
   
   if(isMidiDevice)
      MelodyDev_Init( &player->ParNode.curHdl, wrkbuf, &player->ParNode, &Swsyn_Callback );	
   else
      MelodyPar_Init( &player->ParNode.curHdl, wrkbuf, &player->ParNode, &Swsyn_Callback );
   wrkbuf += parsize;
   
   MelodySyn_Init( &player->DecNode.curHdl, wrkbuf, &player->DecNode, &Swsyn_Callback );
   wrkbuf += synsize;
   
   PcmRender_Init(&player->SinkNode.curHdl, wrkbuf, &player->SinkNode, &Swsyn_Callback);

   wrkbuf += sinksize;
   
   player->ParNode.next  = player->DecNode.curHdl;
   player->DecNode.prev  = player->ParNode.curHdl;
   player->DecNode.next  = player->SinkNode.curHdl;
   player->SinkNode.prev = player->DecNode.curHdl;
   
   for( I = 0 ; I < parnum ; I++ ){
      pBufHdr = (OMX_BUFFERHEADERTYPE *)wrkbuf;
      wrkbuf += sizeof(OMX_BUFFERHEADERTYPE);
         
      pBufHdr->pBuffer = (OMX_U8 *)wrkbuf;
      pBufHdr->nAllocLen = MELODY_PARSE_BUFSIZE;
      wrkbuf += MELODY_PARSE_BUFSIZE;
      player->ParNode.curHdl->FillThisBuffer(player->ParNode.curHdl, pBufHdr);
   }
   
   for( I = 0 ; I < synnum ; I++ ){
      pBufHdr = (OMX_BUFFERHEADERTYPE *)wrkbuf;
      wrkbuf += sizeof(OMX_BUFFERHEADERTYPE);
         
      pBufHdr->pBuffer = (OMX_U8 *)wrkbuf;
      pBufHdr->nAllocLen = MELODY_SYNTH_BUFSIZE;
      wrkbuf += MELODY_SYNTH_BUFSIZE;
      player->DecNode.curHdl->FillThisBuffer(player->DecNode.curHdl, pBufHdr);
   }
   
   imhhdl = (MHPB_Internal *)get_ctrl_buffer( sizeof(MHPB_Internal) );
   memset(imhhdl, 0, sizeof(MHPB_Internal));
   mhhdl = (MHdl *) imhhdl;
   mhdlInitEx( mhhdl, 0, DummyHisr );
   mhhdl->handler = &MelodyComp_MsgHandler;
   mhhdl->private_data = handle; 
   
   pIntHdl = (AudComHdlInt *)player->SinkNode.curHdl;
   pIntHdl->mhdl = mhhdl;
   for( I = 0; I < MAX_MIDICHANNEL ; I++){
      player->tckmidchannel[I].program    = 0xFF;
      player->tckmidchannel[I].volume     = 0xFF;
   }
   player->pitchtrans = 0xFFFFFFFF;
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (Play Speed Related)
********************************************************************************
*/
Media_Status MelodyComp_SetTSRate( Media_Handle *handle, kal_int32 Rate )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if( Rate == 0 || player->bad_format)
      return MEDIA_FAIL;

   parsedata->data = Rate;
   if((parsedata->data > 400) || (parsedata->data< 25))
      return MEDIA_FAIL;
   if( player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodySetTsRate, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

kal_int32 MelodyComp_GetRate( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
   if(player->bad_format)
      return 0;
   player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodyGetPlayRate, parsedata );
   
   return parsedata->data*1000;
}

Media_Status MelodyComp_SetRate( Media_Handle *handle, kal_int32 milliRate )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if( milliRate < 1000 || player->bad_format)
      return MEDIA_FAIL;
   
   parsedata->data = milliRate/1000;
   if((parsedata->data > 400) || (parsedata->data< 25))
      return MEDIA_FAIL;
   if( player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodySetPlayRate, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (Sound Properties)
********************************************************************************
*/
MIDI_Format MelodyComp_Format( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodyGetFormat, parsedata );
   return (MIDI_Format)parsedata->data;
}
kal_uint8 MelodyComp_GetLevel( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   synthdata = (MelodySynthParam*)&player->synthdata;
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if(player->bad_format)
      return 0;
   player->DecNode.curHdl->SetParameter( player->DecNode.curHdl, OMX_IndexConfigMelodyGetLevel, synthdata );
   
   return (kal_uint8)synthdata->data;
}

Media_Status MelodyComp_SetLevel( Media_Handle *handle, kal_uint8 level )
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   synthdata = (MelodySynthParam*)&player->synthdata;
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if(level > 100 || player->bad_format)
      return MEDIA_FAIL;
      
   synthdata->data = level;
   if( player->DecNode.curHdl->SetParameter( player->DecNode.curHdl, OMX_IndexConfigMelodySetLevel, synthdata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
       
   return MEDIA_SUCCESS;
}

kal_int32 MelodyComp_GetPitchTranspose( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   synthdata = (MelodySynthParam*)&player->synthdata;
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   if(player->bad_format)
      return 0;
   if(player->pitchtrans != 0xFFFFFFFF)
      return player->pitchtrans;
   player->DecNode.curHdl->SetParameter( player->DecNode.curHdl, OMX_IndexConfigMelodyGetPitchTranspose, synthdata );
   
   return synthdata->data;
}

Media_Status MelodyComp_SetPitchTranspose( Media_Handle *handle, kal_int32 milliSt )
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   synthdata = (MelodySynthParam*)&player->synthdata;
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if( milliSt > 100 || milliSt < -100 || player->bad_format)
      return MEDIA_FAIL;

   player->pitchtrans = milliSt;
   synthdata->data = milliSt;
   if( player->DecNode.curHdl->SetParameter( player->DecNode.curHdl, OMX_IndexConfigMelodySetPitchTranspose, synthdata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
          
   return MEDIA_SUCCESS;
}

void MelodyComp_SetTCKChannelVolume(Media_Handle *handle, kal_uint8 channel, kal_uint8 level )
{
   MIDI_Player *player;
   player = (MIDI_Player *)handle->data;
   player->tckmidchannel[channel].volume = level;
}

kal_uint8 MelodyComp_GetTCKChannelVolume(Media_Handle *handle, kal_uint8 channel)
{
   MIDI_Player *player;
   player = (MIDI_Player *)handle->data;
   return player->tckmidchannel[channel].volume;
}

void MelodyComp_SetTCKChannelProgram(Media_Handle *handle, kal_uint8 channel, kal_uint8 program )
{
   MIDI_Player *player;
   player = (MIDI_Player *)handle->data;
   player->tckmidchannel[channel].program = program;
}

kal_uint8 MelodyComp_GetTCKChannelProgram(Media_Handle *handle, kal_uint8 channel)
{
   MIDI_Player *player;
   player = (MIDI_Player *)handle->data;
   return player->tckmidchannel[channel].program;
}

Media_Status MelodyComp_SetProgram(Media_Handle *handle, kal_uint8 channel, kal_uint8 program)
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   synthdata = (MelodySynthParam*)&player->synthdata;
   synthdata->data    = program;
   synthdata->channel = channel;
   if( player->DecNode.curHdl->SetParameter( player->DecNode.curHdl, OMX_IndexConfigMelodySetChannelProgram, synthdata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
          
   return MEDIA_SUCCESS;
}

kal_uint8 MelodyComp_GetChannelProgram(Media_Handle *handle, kal_uint8 channel)
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   if( !player->init )
      MelodyComp_InitIP(handle);

   synthdata = (MelodySynthParam*)&player->synthdata;
   synthdata->channel = channel;
   player->DecNode.curHdl->SetParameter( player->DecNode.curHdl, OMX_IndexConfigMelodyGetChannelProgram, synthdata );

   return (kal_int8)synthdata->data;
}

kal_uint8 MelodyComp_GetChannelVolume(Media_Handle *handle, kal_uint8 channel)
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );   
   if( !player->init )
      MelodyComp_InitIP(handle);

   synthdata = (MelodySynthParam*)&player->synthdata;
   
   synthdata->channel = channel;
   MelodySyn_SetParameter( player->DecNode.curHdl, OMX_IndexConfigMelodyGetChannelVolume, synthdata );
   return (kal_int8)synthdata->data;
}

kal_bool MelodyComp_isSpMidi(Media_Handle *handle)
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   if( !player->init )
      MelodyComp_InitIP(handle);
   parsedata = (MelodyParseParam*)&player->parsedata;
   
   player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodySpMidi, parsedata );
   return (kal_bool)parsedata->data;
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (Time Related)
********************************************************************************
*/
Media_Status MelodyComp_SetStartTime( Media_Handle *handle, kal_int32 msStartTime )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
   
   if(player->bad_format)
      return MEDIA_FAIL;
   player->jstart_time = msStartTime;
   handle->start_time = handle->current_time = msStartTime;  
   parsedata->data = msStartTime;
   if( player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodySetStartTime, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

Media_Status MelodyComp_SetStopTime( Media_Handle *handle, kal_int32 msStopTime )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
   if(player->bad_format)
      return MEDIA_FAIL;
   handle->stop_time = msStopTime;
   parsedata->data = msStopTime;
   if( player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodySetStopTime, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

kal_int32 MelodyComp_GetCurrentTime( Media_Handle *handle )
{
	//RESERVED;
	 MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
	 player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodyGetCurrentTime, parsedata );
   
   return parsedata->data;
}

int32 MelodyComp_GetDuration( Media_Handle *handle )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   MelodyParseParam *parsedata;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
   
   if( !player->init )
      MelodyComp_InitIP(handle);

   if(player->bad_format || player->format == MELODYFORMAT_DEV)
      return 0; 
   player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodyGetDuration, parsedata );
   if(parsedata->data > MELODY_MAX_DURATION){
        player->bad_format = KAL_TRUE;
      return 0;
   }
   return parsedata->data;
}

Media_Status MelodyComp_SetTempo( Media_Handle *handle, kal_int32 milliTempo )
{
   int32 tempo;
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
   
   if( (milliTempo == 0) )
      return MEDIA_FAIL;
   tempo = 60000000 / milliTempo;
   
   parsedata->data = tempo;
   if( player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodySetTempo, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

kal_int32 MelodyComp_GetTempo( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   if( !player->init )
      MelodyComp_InitIP(handle);
   parsedata = (MelodyParseParam*)&player->parsedata;
   
   player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodyGetTempo, parsedata );
   
   return (60000000 / parsedata->data );
}

/*
********************************************************************************
*                        Control Functions
********************************************************************************
*/
Media_Status MelodyComp_Play( Media_Handle *handle )
{
   int32 tmpduration;
   MelodySynthParam *synthdata;
   MelodyParseParam *parsedata;
   MIDI_Player *player = (MIDI_Player *)handle->data;
   
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&player->parsedata;
#if defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST) || defined(MT6268T) || defined(MT6268H)
   return MEDIA_SUCCESS;
#endif
   if(!player->dpmrgwt_check){
//      DPMGR_Load(DPMGR_WAVETABLE);
      player->dpmrgwt_check   = KAL_TRUE;
   }
   tmpduration = MelodyComp_GetDuration(handle);
#if defined(__BES_TS_SUPPORT__)
   AudioPP_TS_Activate(KAL_FALSE);
#endif
   if(player->bad_format){
      handle->state = MIDI_STATE_READY;	
      if(player->dpmrgwt_check){
//         DPMGR_Unload(DPMGR_WAVETABLE);
         player->dpmrgwt_check   = KAL_FALSE;
      }
      return MEDIA_BAD_FORMAT;
   }
   AFE_SetDigitalGain(L1SP_AUDIO, 100);
   parsedata->data = handle->start_time;
   player->ParNode.curHdl->SetParameter( player->ParNode.curHdl, OMX_IndexConfigMelodySetStartTime, parsedata);
   handle->state = MIDI_STATE_PLAYING;
   if(player->jstart_time == 0 || player->jtempo_state == 0)
      player->jstart_time = player->jtempo_state = 0;
   
   player->DecNode.curHdl->SetParameter( player->DecNode.curHdl, OMX_IndexConfigMelodyClrEndFlag, synthdata);
   player->ParNode.curHdl->Start( player->ParNode.curHdl );
   player->DecNode.curHdl->Start( player->DecNode.curHdl );
   player->SinkNode.curHdl->Start( player->SinkNode.curHdl );
   player->state = MIDI_CTRL_RUN;
   return MEDIA_SUCCESS;
}

void MelodyComp_StopInMed(void *data, Media_Event event)
{
   return;
}

Media_Status MelodyComp_Stop( Media_Handle *handle )
{
   MIDI_Player *player;
   ASSERT( handle != 0 );
   player = (MIDI_Player *)handle->data;

   player->ParNode.curHdl->Stop( player->ParNode.curHdl );
   player->DecNode.curHdl->Stop( player->DecNode.curHdl );
   player->SinkNode.curHdl->Stop( player->SinkNode.curHdl );
   ACU_FlushBufferQueue( (AudComHdl *)player->ParNode.curHdl );
   ACU_FlushBufferQueue( (AudComHdl *)player->DecNode.curHdl );
   ACU_FlushBufferQueue( (AudComHdl *)player->SinkNode.curHdl );

   while ( !ACU_IsFlushed () ) {
      kal_sleep_task(1);
   }
   player->state = MIDI_CTRL_STOP;
   if(player->dpmrgwt_check){
//      DPMGR_Unload(DPMGR_WAVETABLE);
      player->dpmrgwt_check   = KAL_FALSE;
   }
   return MEDIA_SUCCESS;
}

Media_Status MelodyComp_Free( Media_Handle *handle )
{
   AudComHdlInt *pIntHdl;
   MIDI_Player *player;
   ASSERT( handle != 0 );
   player = (MIDI_Player *)handle->data;
   
   if(player->ParNode.curHdl == (AudComHdl*)0 || player->DecNode.curHdl == (AudComHdl*)0)
      return MEDIA_FAIL;
   
   pIntHdl = (AudComHdlInt *)player->SinkNode.curHdl;
   
   if(player->state == MIDI_CTRL_RUN)
      MelodyComp_Stop(handle);
   free_ctrl_buffer(pIntHdl->mhdl);
   player->ParNode.curHdl->Deinit( player->ParNode.curHdl );
   player->DecNode.curHdl->Deinit( player->DecNode.curHdl );
   player->SinkNode.curHdl->Deinit( player->SinkNode.curHdl );
   
   if(player->wrkbuf)
      audio_free_mem( (void **) &player->wrkbuf);
   
   free_ctrl_buffer(handle);
   return MEDIA_SUCCESS;
}


/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Multiple Parser Framework
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#elif MULTIPLE_PASER_SINGLE_WTSYNTH

MIDI_CTRL_MANAGER melodyCtrl;

/*
********************************************************************************
*                        Utility Functions
********************************************************************************
*/
void MelodyComp_Bootup( void )
{
   memset(&melodyCtrl, 0, sizeof(melodyCtrl));
   melodyCtrl.current_usage = MELODYUSAGE_MUSICSOUND;
}

static void MelodyComp_DPMGR_Load( Media_Handle_MIDICTRL *ihandle )
{
   melodyCtrl.data[ihandle->usage]->dpmrgwt_count++;
   ASSERT(melodyCtrl.data[ihandle->usage]->dpmrgwt_count <= MELODY_MAXPLAYERS);
   if(melodyCtrl.data[ihandle->usage]->dpmrgwt_count == 1){
//      DPMGR_Load(DPMGR_WAVETABLE);
      melodyCtrl.data[ihandle->usage]->dpmrgwt_check = KAL_TRUE;
   }
}

static void MelodyComp_DPMGR_Unload( Media_Handle_MIDICTRL *ihandle )
{
   melodyCtrl.data[ihandle->usage]->dpmrgwt_count--;
   ASSERT(melodyCtrl.data[ihandle->usage]->dpmrgwt_count >= 0);
   if(melodyCtrl.data[ihandle->usage]->dpmrgwt_count == 0){
//      DPMGR_Unload(DPMGR_WAVETABLE);
      melodyCtrl.data[ihandle->usage]->dpmrgwt_check = KAL_FALSE;
   }
}

kal_bool MelodyComp_PlayerActivate(void)
{
   if( (melodyCtrl.hdl_state[MELODYUSAGE_MUSICSOUND] == 0) && (melodyCtrl.hdl_state[MELODYUSAGE_SOUNDEFFECT] == 0) )
      return KAL_FALSE;
   else
      return KAL_TRUE;
}

void MelodyComp_InitMelodyCtrlMgr( MELODYUSAGE_T usage )
{
   MIDI_CTRL_MANAGER_INT *ctrldata;
   ASSERT(melodyCtrl.data[usage] == (MIDI_CTRL_MANAGER_INT*)0);
   melodyCtrl.data[usage] = (MIDI_CTRL_MANAGER_INT*)audio_alloc_mem_cacheable( sizeof(kal_uint8)*sizeof(MIDI_CTRL_MANAGER_INT));
#if MELODY_ENABLE_DEBUGLOG
   kal_prompt_trace(MOD_L1SP,"DougInitMelodyCtrl:%x %x, pointer", usage, melodyCtrl.data[usage]);
#endif
   ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[usage];
   ASSERT(ctrldata);
   ctrldata->init          = KAL_FALSE;
   ctrldata->dpmrgwt_check = KAL_FALSE;
   ctrldata->playstate     = MIDI_CTRL_IDLE;
   ctrldata->run_state     = 0;
   ctrldata->parser_size   = 0;
   ctrldata->dpmrgwt_count = 0;
   ctrldata->hdl_list      = 0;
   ctrldata->mid_device    = KAL_FALSE;
   ctrldata->endingflag    = KAL_FALSE;
   ctrldata->wrkbuf        = 0;
}

void MelodyComp_DeInitMelodyCtrlMgr( MELODYUSAGE_T usage )
{
#if MELODY_ENABLE_DEBUGLOG
   kal_prompt_trace(MOD_L1SP,"DougDelMelodyCtrl:%x %x, pointer", usage, melodyCtrl.data[usage]);
#endif
   audio_free_mem( (void **) &melodyCtrl.data[usage]);
   melodyCtrl.data[usage] = (MIDI_CTRL_MANAGER_INT*)0;
}

Media_Handle *MelodyComp_ObtainHandle( kal_bool mid_device )
{
   kal_uint16 I, state_bit;
   Media_Handle_MIDICTRL *ihandle;
   MELODYUSAGE_T usage = melodyCtrl.current_usage;
   MIDI_CTRL_MANAGER_INT *ctrldata;
   
#if defined(__AUDIO_NOT_SUPPORTED__)
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_OPEN, 0x1000, -1);
   return (Media_Handle*)0;
#endif
   
#if !defined(__AUDIO_MIXER_SUPPORT__)
   PcmSink_TerminateSound();  
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif    
   if( AM_IsAudioPlaybackOn() != -1 ) {
      kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_OPEN, 0x1001, -1);
      return (Media_Handle*)0;
    }
#endif

#if defined(__DCM_WITH_COMPRESSION__)
 #if defined(__AUDIO_MIXER_SUPPORT__)
   if( (!MelodyComp_PlayerActivate()) && (AM_IsAudioPlaybackOn() != -1) && (!PcmRender_IsRunning()) )
 #else
   if( (!MelodyComp_PlayerActivate()) && (AM_IsAudioPlaybackOn() != -1) )
 #endif
    {
      kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_OPEN, 0x1002, -1);
      return (Media_Handle*)0;
    }
#endif

   if(melodyCtrl.hdl_state[usage] == 0)
      MelodyComp_InitMelodyCtrlMgr(usage);

   ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[usage];

   if( ctrldata->mid_device && mid_device ) {
      kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_OPEN, 0x1003, -1);
      return 0;
    }
      
   for( I = 0; I < MELODY_MAXPLAYERS; I++ ) {
      state_bit = 1 << I;
      if( (melodyCtrl.hdl_state[usage] & state_bit) == 0 ) {
         if ( !MelodyComp_PlayerActivate() )
            DPMGR_Load(DPMGR_WAVETABLE);
         
         melodyCtrl.hdl_state[usage] |= state_bit;

         ihandle = (Media_Handle_MIDICTRL*)get_ctrl_buffer( sizeof(Media_Handle_MIDICTRL) );
      #if MELODY_ENABLE_DEBUGLOG
         kal_prompt_trace(MOD_L1SP,"DougGetCtrlBuf:usage_%x, pointer:_%x", usage, ihandle);
      #endif
         ihandle->end_flag = 0;
         ihandle->state_bit = I;
         ihandle->next = ctrldata->hdl_list;
         ihandle->mh.index = I;
         ctrldata->hdl_list = ihandle;
         if(mid_device)
            ctrldata->mid_device = KAL_TRUE;
         ihandle->usage = usage;
         
         return (Media_Handle *)ihandle;
      }
   }
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_OPEN, 0x1004, -1);
   return (Media_Handle *)0;
}

void MelodyComp_ReleaseHandle( Media_Handle *handle )
{
   Media_Handle_MIDICTRL *hdl;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   ASSERT( melodyCtrl.hdl_state[ihandle->usage] & (1<<ihandle->state_bit) );
   if( ctrldata->hdl_list == ihandle ) {
      ctrldata->hdl_list = ihandle->next;
   }
   else {
      hdl = ctrldata->hdl_list;
      while( hdl->next != ihandle )
         hdl = hdl->next;
      hdl->next = ihandle->next;
   }
   melodyCtrl.hdl_state[ihandle->usage] &= ~(1<<ihandle->state_bit);
   
   if ( !MelodyComp_PlayerActivate() )
      DPMGR_Unload(DPMGR_WAVETABLE);
#if MELODY_ENABLE_DEBUGLOG
   kal_prompt_trace(MOD_L1SP,"DougFreeCtrlBuf:usage_%x, pointer:_%x", ihandle->usage, ihandle);
#endif
   free_ctrl_buffer( ihandle );
}

//=============================================================================================
//=============================================================================================
/*
********************************************************************************
*                        Utility Functions
********************************************************************************
*/
Media_Status MelodyComp_Stop( Media_Handle *handle );
void MelodyComp_ReleaseDone( MELODYUSAGE_T usage );
void MelodyComp_Repeat( Media_Handle *handle );
void MelodyComp_SetSynHandle( Media_Handle *handle );
void MelodyComp_StopInMed(void *data, Media_Event event);

void MelodyComp_EvtCallback(void *hdl, int evt)
{
   MelodyParseParam *parsedata;
   Media_Handle *handle = (Media_Handle*)hdl;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   Media_Handle_MIDICTRL *mhdl_ms, *mhdl_se;
   Media_Event event;
   kal_uint8 I;
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
#endif
#if MELODY_ENABLE_DEBUGLOG
   kal_prompt_trace(MOD_L1SP,"DougCallBack:%x %x %x %x",ihandle->usage, ihandle, evt, I );
#endif
   switch((MELODY_EVENT_CALLBACK)evt){
   case MELODY_SYNTHDONE_SOUNDEFFECT:
      MelodyComp_ReleaseDone(MELODYUSAGE_SOUNDEFFECT);
      return;
   case MELODY_SYNTHDONE_MUSICSOUND:
      MelodyComp_ReleaseDone(MELODYUSAGE_MUSICSOUND);
      return;
#if !defined(WT_NO_IMYEFFECTS)
   case MELODY_LED_ON:
      event = MEDIA_LED_ON;
      break;
   case MELODY_LED_OFF:
      event = MEDIA_LED_OFF; 
      break;
   case MELODY_VIBRATOR_ON:
      event = MEDIA_VIBRATOR_ON;
      break;
   case MELODY_VIBRATOR_OFF:
      event = MEDIA_VIBRATOR_OFF;
      break;
   case MELODY_BACKLIGHT_ON:
      event = MEDIA_BACKLIGHT_ON;
      break;
   case MELODY_BACKLIGHT_OFF:
      event = MEDIA_BACKLIGHT_OFF;
      break;
#endif
   case MELODY_REPEAT:
      if( melodyCtrl.data[ihandle->usage]->dpmrgwt_count > 1)
         return;
      MelodyComp_Repeat(handle);
      return;
   case MELODY_END:
      event = MEDIA_END;
      break;
   case MELODY_RELEASE:
      melodyCtrl.data[ihandle->usage]->endingflag = KAL_TRUE;
      MelodyComp_SetSynHandle(handle);
      return;
   case MELODY_RELEASEDONE:
      melodyCtrl.data[ihandle->usage]->endingflag = KAL_FALSE;
      return;
   default:
      return;
   }
   handle->handler(handle, event);
   return;
}


void MelodyComp_ReleaseDone( MELODYUSAGE_T usage )
{
   MelodyParseParam *parsedata;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[usage];
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySynthesisDone, parsedata );
}

void MelodyComp_SetSynHandle( Media_Handle *handle )
{
   MelodySynthParam *synthdata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   synthdata = (MelodySynthParam*)&ctrldata->synthdata;
   synthdata->meldata.evthdl = handle;
#if MELODY_ENABLE_DEBUGLOG
   kal_prompt_trace(MOD_L1SP, "DougSetSynHandle:%x, usage:%x", handle, ihandle->usage);
#endif
   ctrldata->DecNode.curHdl->SetParameter( ctrldata->DecNode.curHdl, OMX_IndexConfigMelodySetSynHandle, synthdata );
}

void MelodyComp_Repeat( Media_Handle *handle )
{
   MelodySynthParam *synthdata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   synthdata = (MelodySynthParam*)&ctrldata->synthdata;
   
   ctrldata->DecNode.curHdl->SetParameter( ctrldata->DecNode.curHdl, OMX_IndexConfigMelodyRepeat, synthdata );
}
extern void SMF_GetFSData(void *hdl, int evt, unsigned char* ptr, unsigned int len);

Media_Status MelodyComp_SendShortMsg( Media_Handle *handle, kal_uint8 type, kal_uint8 data1, kal_uint8 data2 )
{
#if !defined(__AUDIO_ULTRA_SLIM__)
   kal_uint8 buf[3];
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];

   if((type&0xF0) == 0xC0){
      ctrldata->tckmidchannel[type&0x0F].program = data1;
   }else if((type&0xF0) == 0xB0){
      if(data1 == 0x07){
         ctrldata->tckmidchannel[type&0x0F].volume = data2;
      }
   }
   buf[0] = type;
   buf[1] = data1;
   buf[2] = data2;
   return JMidi_SendLongMsg( handle, buf, 3 );
#endif
}

Media_Status MelodyComp_SendLongMsg( Media_Handle *handle, const uint8 *buf, uint16 len )
{
#if !defined(__AUDIO_ULTRA_SLIM__)
   kal_uint16 I;
   MelodyParseParam *parsedata;
   MIDI_Player *player = (MIDI_Player *)handle->data;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   
   if(len == 0 || buf == 0)
      return MEDIA_FAIL;
   
   parsedata->meldata.rtmidi_running = KAL_FALSE;
   parsedata->meldata.rtmidi_status  = 0;
   parsedata->meldata.rtmidi_ptr     = buf;
   parsedata->meldata.rtmidi_count   = len;
   parsedata->meldata.rtmidi_wait    = KAL_TRUE;
   if( ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySendMessage, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
   
   return MEDIA_SUCCESS;
#endif
}

/*
********************************************************************************
*                        Initialize Functions
********************************************************************************
*/
void MelodyComp_InitIP(Media_Handle *handle)
{
   MelodyParseParam *parsedata;
   kal_uint32 tmpgain;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   MIDI_Player *player = (MIDI_Player *)handle->data;
   
   if(player->format == MELODYFORMAT_DEV)
      tmpgain = DG_IMY_NOTE;
   else
      tmpgain = DG_SMF_NOTE;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_INITIP, handle, player->init, player->format, ctrldata->init, tmpgain);

   if(!player->init){
      const uint8 *midifile;
   #if defined( MIDFILE_PLAY_SUPPORT )
      STFSAL *pstFSAL;
   #endif
      parsedata = &ctrldata->parsedata;
   #if defined( MIDFILE_PLAY_SUPPORT )
      if( player->format == MELODYFORMAT_SMF)
         pstFSAL = player->param.smf.pstFSAL;
      else
         pstFSAL = NULL;
   #endif
      parsedata->meldata.maxtone = MELODY_MAX_POLYPHONY;	
      switch(player->format)
      {
      case MELODYFORMAT_SMF:
         handle->repeat_count     = ((Media_SMF_Param *)handle->param)->repeats;
         tmpgain = DG_SMF_NOTE;
         break;
      case MELODYFORMAT_DEV:
         handle->repeat_count    = 0;
         tmpgain = DG_IMY_NOTE;
         break;
      case MELODYFORMAT_IMY:
         handle->repeat_count     = ((Media_iMelody_Param *)handle->param)->repeats;
         tmpgain = DG_IMY_NOTE;
         break;
#if defined(JTONE_SUPPORT)          
      case MELODYFORMAT_JTS:
         handle->repeat_count     = ((Media_ToneSeq_Param *)handle->param)->repeats;
         tmpgain = DG_JTS_NOTE;
         break;
#endif         
      default:
         ASSERT(KAL_FALSE);
      }
      player->init = KAL_TRUE;
      parsedata->meldata.repeats = handle->repeat_count;
   #if defined( MIDFILE_PLAY_SUPPORT )
      if( pstFSAL!=NULL ){
         FSAL_GetFileSize(pstFSAL, &player->fsize);
         parsedata->meldata.filelen  = player->fsize;
         parsedata->meldata.mode     = FS_MODE;
         parsedata->meldata.datahdl  = player;
         parsedata->meldata.getdata  = &SMF_GetFSData;
         player->fplay               = KAL_TRUE;
         handle->start_time          = handle->current_time = 0;
         player->jstart_time         = 0;
      }else{
   #endif
         player->fplay = KAL_FALSE;
         midifile = NULL;
         switch(player->format)
         {
         case MELODYFORMAT_SMF:
            midifile = player->param.smf.smffile;
            parsedata->meldata.filelen = player->param.smf.filesize;
            break;
         case MELODYFORMAT_IMY:
            midifile = player->param.imy.imyfile;
            parsedata->meldata.filelen = player->param.imy.filesize;
            break;
#if defined(JTONE_SUPPORT)             
         case MELODYFORMAT_JTS:
            midifile = player->param.jts.toneSeq;
            parsedata->meldata.filelen = player->param.jts.toneSeqLen;
            break;
#endif            
         case MELODYFORMAT_DEV:
            midifile = NULL;
            parsedata->meldata.filelen = 0;
            break;
         default:
            ASSERT(KAL_FALSE);
         }
         parsedata->meldata.midifile  = midifile;
         parsedata->meldata.mode      = BUFFER_MODE;
         parsedata->meldata.period    = MELODY_PERIOD;
         parsedata->meldata.datahdl   = (void*)0;
         parsedata->meldata.getdata   = (void*)0;
         parsedata->meldata.evthdl    = handle;
         parsedata->meldata.evtcall   = &MelodyComp_EvtCallback;
         parsedata->state_bit         = ihandle->state_bit;
#if defined( MIDFILE_PLAY_SUPPORT )
      }
#endif
      if( ctrldata->ParNode.curHdl->SetParameter(ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyParserInit, parsedata) != OMX_ErrorNone ){
         player->bad_format = KAL_TRUE;
         player->init       = KAL_TRUE;
         return;
      }
   }
   if(!ctrldata->init){
      SinkParam sinkParam;
      MelodySynthParam *synthdata;
      synthdata                     = (MelodySynthParam*)&ctrldata->synthdata;
      synthdata->meldata.tonegain   = tmpgain;
      synthdata->meldata.samplerate = MELODY_SAMPLINGRATE;
      synthdata->meldata.maxtone    = MELODY_MAX_POLYPHONY;
      synthdata->meldata.finetone   = MELODY_FINE_POLYPHONY;
      synthdata->meldata.period     = MELODY_SYNTH_PERIOD;
      synthdata->meldata.wavtab     = (unsigned char*)Wavetable;
      synthdata->meldata.evthdl     = handle;
      synthdata->meldata.evtcall    = &MelodyComp_EvtCallback;
      synthdata->meldata.usage      = ihandle->usage;
      ctrldata->DecNode.curHdl->SetParameter(ctrldata->DecNode.curHdl, OMX_IndexConfigMelodySynthesizerInit, synthdata);
      
      
      sinkParam.uSamplingFreq = 32000;
      sinkParam.uChannelNum   = 2;
      ctrldata->SinkNode.curHdl->SetParameter(ctrldata->SinkNode.curHdl, OMX_IndexParamMediaTekPcmSink, &sinkParam);
      ctrldata->init = KAL_TRUE;
   }
}

static const MHPB_CompList MelodyFuncArray[2] =
{
   {MelodyPar_GetMemSize, MelodyPar_Init, MELODY_PARSE_BUFSIZE, MELODY_PARSE_BUFNUM},
   {MelodySyn_GetMemSize, MelodySyn_Init, MELODY_SYNTH_BUFSIZE, MELODY_SYNTH_BUFNUM}
};

void MelodyComp_Init(Media_Handle *handle, MIDI_Player *player, bool isMidiDevice)
{
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_INIT, handle, isMidiDevice, ctrldata->playstate);
#if MELODY_ENABLE_DEBUGLOG
   kal_prompt_trace(MOD_L1SP, "DougInit:usage_%x, state:%x, hdl_%x_%x", ihandle->usage, ihandle->state_bit, melodyCtrl.hdl_state[0], melodyCtrl.hdl_state[1]);
#endif
   if (ctrldata->playstate == MIDI_CTRL_IDLE) {   
      MHPB_CompList MelodyParFunc, MelodySynFunc, SinkFunc;
      uint32 I;
      
      // Set functions
      MelodyParFunc.GetMemSize = MelodyPar_GetMemSize;
      MelodyParFunc.Init = MelodyPar_Init;
      MelodyParFunc.OutputBufferSize = MELODY_PARSE_BUFSIZE;
      
      MelodySynFunc.GetMemSize = MelodySyn_GetMemSize;
      MelodySynFunc.Init = MelodySyn_Init;
      MelodySynFunc.OutputBufferSize = MELODY_SYNTH_BUFSIZE;
      
      SinkFunc.OutputBufferSize = 0;
      SinkFunc.OutputBufferNum = 0;
      
      MelodyParFunc.OutputBufferNum = MELODY_PARSE_BUFNUM;
      MelodySynFunc.OutputBufferNum = MELODY_SYNTH_BUFNUM;
      SinkFunc.GetMemSize = PcmRender_GetMemSize;
      SinkFunc.Init = PcmRender_Init;
   
   #if defined(__AUDIO_MIXER_SUPPORT__)    
      if(ihandle->usage == MELODYUSAGE_SOUNDEFFECT) 
      {
         MHPB_CompList const *pArray[4];
         MHPB_Internal *imhhdl;
         
         pArray[0] = &MelodyParFunc;
         pArray[1] = &MelodySynFunc;
         pArray[2] = &SinkFunc;
         pArray[3] = NULL;
         
         ctrldata->mhpb = (MHPB_Internal *)MH_Component_List_Open(MelodyComp_MsgHandler, NULL, pArray);
         ctrldata->mhpb->mh.private_data = handle;

         imhhdl = ctrldata->mhpb;      
         // Temp code for alias. should be removed later
         memcpy( &ctrldata->ParNode, &imhhdl->NodeArray[0], sizeof(AcHdlNode));
         memcpy( &ctrldata->DecNode, &imhhdl->NodeArray[1], sizeof(AcHdlNode));
         memcpy( &ctrldata->SinkNode, &imhhdl->NodeArray[2], sizeof(AcHdlNode));
      }   
      else
   #endif
      {
         MHPB_Internal *imhhdl;
         ctrldata->mhpb = (MHPB_Internal *)MH_Component_Open(MelodyComp_MsgHandler, NULL, &MelodyFuncArray[0], &MelodyFuncArray[1]);
         ctrldata->mhpb->mh.private_data = handle;
         imhhdl = ctrldata->mhpb;
         memcpy( &ctrldata->ParNode , &imhhdl->ParNode, sizeof(AcHdlNode));
         memcpy( &ctrldata->DecNode , &imhhdl->DecNode, sizeof(AcHdlNode));
         memcpy( &ctrldata->SinkNode, &imhhdl->SinkNode, sizeof(AcHdlNode));
         memcpy( &ctrldata->PPNode  , &imhhdl->APMNode, sizeof(AcHdlNode));
      }
      
      for( I = 0; I < MAX_MIDICHANNEL ; I++){
         ctrldata->tckmidchannel[I].program    = 0xFF;
         ctrldata->tckmidchannel[I].volume     = 0xFF;
      }
      ctrldata->pitchtrans = 0xFFFFFFFF;
      ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyGetParserMemSize, parsedata );
      ctrldata->parser_size = parsedata->data;
      ctrldata->playstate = MIDI_CTRL_INIT;
   }
   
   if(!isMidiDevice){
      player->wrkbuf = (kal_uint8*)audio_alloc_mem_cacheable( sizeof(kal_uint8)*ctrldata->parser_size );
      ASSERT(player->wrkbuf);
      memset(player->wrkbuf, 0, ctrldata->parser_size);
      parsedata->wrkbuf = (void*)player->wrkbuf;
      parsedata->state_bit = ihandle->state_bit;
      if( ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyPlayerInit, parsedata ) != OMX_ErrorNone)
         player->bad_format = KAL_TRUE;
   }else{
      player->wrkbuf             = 0;
      parsedata->state_bit       = ihandle->state_bit;
      parsedata->meldata.evtcall = &MelodyComp_EvtCallback;
      parsedata->meldata.evthdl  = handle;
      ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyDeviceInit, parsedata );
   }
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (Play Speed Related)
********************************************************************************
*/
Media_Status MelodyComp_SetTSRate( Media_Handle *handle, kal_int32 Rate )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   parsedata->state_bit = ihandle->state_bit;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_STSRATE, handle, Rate);
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if( Rate == 0 || player->bad_format)
      return MEDIA_FAIL;

   parsedata->data = Rate;
   if((parsedata->data > 400) || (parsedata->data< 25))
      return MEDIA_FAIL;
   if( ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySetTsRate, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

kal_int32 MelodyComp_GetRate( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   parsedata->state_bit = ihandle->state_bit;
   
   if(player->bad_format)
      return 0;
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyGetPlayRate, parsedata );
   
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_GRATE, handle, parsedata->data);
   return parsedata->data*1000;
}

Media_Status MelodyComp_SetRate( Media_Handle *handle, kal_int32 milliRate )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   parsedata->state_bit = ihandle->state_bit;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_SRATE, handle, milliRate);
      
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if( milliRate < 1000 || player->bad_format)
      return MEDIA_FAIL;
   
   parsedata->data = milliRate/1000;
   if((parsedata->data > 400) || (parsedata->data< 25))
      return MEDIA_FAIL;
   if( ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySetPlayRate, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (Sound Properties)
********************************************************************************
*/
MIDI_Format MelodyComp_Format( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];

   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;  
   parsedata->state_bit = ihandle->state_bit;

   if( !player->init )
      MelodyComp_InitIP(handle);
   
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyGetFormat, parsedata );
   return (MIDI_Format)parsedata->data;
}
kal_uint8 MelodyComp_GetLevel( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   parsedata->state_bit = ihandle->state_bit;
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if(player->bad_format)
      return 0;
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyGetParserLevel, parsedata );
   
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_GLEVEL, handle, parsedata->data);   
   return (kal_uint8)parsedata->data;
}

Media_Status MelodyComp_SetLevel( Media_Handle *handle, kal_uint8 level )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   parsedata->state_bit = ihandle->state_bit;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_SLEVEL, handle, parsedata->data);
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if(level > 100 || player->bad_format)
      return MEDIA_FAIL;
      
   parsedata->data = level;
   if( ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySetParserLevel, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
       
   return MEDIA_SUCCESS;
}

kal_int32 MelodyComp_GetPitchTranspose( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   synthdata = (MelodySynthParam*)&ctrldata->synthdata;
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   if(player->bad_format)
      return 0;
   if(ctrldata->pitchtrans != 0xFFFFFFFF)
      return ctrldata->pitchtrans;
   ctrldata->DecNode.curHdl->SetParameter( ctrldata->DecNode.curHdl, OMX_IndexConfigMelodyGetPitchTranspose, synthdata );
   
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_GPITCH, handle, synthdata->data);
   return synthdata->data;
}

Media_Status MelodyComp_SetPitchTranspose( Media_Handle *handle, kal_int32 milliSt )
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   synthdata = (MelodySynthParam*)&ctrldata->synthdata;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_SPITCH, handle, milliSt);
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   if( milliSt > 100 || milliSt < -100 || player->bad_format)
      return MEDIA_FAIL;

   ctrldata->pitchtrans = milliSt;
   synthdata->data = milliSt;
   if( ctrldata->DecNode.curHdl->SetParameter( ctrldata->DecNode.curHdl, OMX_IndexConfigMelodySetPitchTranspose, synthdata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
          
   return MEDIA_SUCCESS;
}

void MelodyComp_SetTCKChannelVolume(Media_Handle *handle, kal_uint8 channel, kal_uint8 level )
{
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   melodyCtrl.data[ihandle->usage]->tckmidchannel[channel].volume = level;
}

kal_uint8 MelodyComp_GetTCKChannelVolume(Media_Handle *handle, kal_uint8 channel)
{
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   return melodyCtrl.data[ihandle->usage]->tckmidchannel[channel].volume;
}

void MelodyComp_SetTCKChannelProgram(Media_Handle *handle, kal_uint8 channel, kal_uint8 program )
{
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   melodyCtrl.data[ihandle->usage]->tckmidchannel[channel].program = program;
}

kal_uint8 MelodyComp_GetTCKChannelProgram(Media_Handle *handle, kal_uint8 channel)
{
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   return melodyCtrl.data[ihandle->usage]->tckmidchannel[channel].program;
}

Media_Status MelodyComp_SetProgram(Media_Handle *handle, kal_uint8 channel, kal_uint8 program)
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];

   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_SPROGRAM, handle, channel, program);
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   synthdata = (MelodySynthParam*)&ctrldata->synthdata;
   synthdata->data    = program;
   synthdata->channel = channel;
   if( ctrldata->DecNode.curHdl->SetParameter( ctrldata->DecNode.curHdl, OMX_IndexConfigMelodySetChannelProgram, synthdata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
          
   return MEDIA_SUCCESS;
}

kal_uint8 MelodyComp_GetChannelProgram(Media_Handle *handle, kal_uint8 channel)
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   synthdata = (MelodySynthParam*)&ctrldata->synthdata;
   synthdata->channel = channel;
   ctrldata->DecNode.curHdl->SetParameter( ctrldata->DecNode.curHdl, OMX_IndexConfigMelodyGetChannelProgram, synthdata );

   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_GPROGRAM, handle, channel, synthdata->data);
   return (kal_int8)synthdata->data;
}

kal_uint8 MelodyComp_GetChannelVolume(Media_Handle *handle, kal_uint8 channel)
{
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );   
   if( !player->init )
      MelodyComp_InitIP(handle);
      
   synthdata = (MelodySynthParam*)&ctrldata->synthdata;
   
   synthdata->channel = channel;
   ctrldata->DecNode.curHdl->SetParameter( ctrldata->DecNode.curHdl, OMX_IndexConfigMelodyGetChannelVolume, synthdata );
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_GVOLUME, handle, channel, synthdata->data);
   return (kal_int8)synthdata->data;
}

kal_bool MelodyComp_isSpMidi(Media_Handle *handle)
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];

   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;  
   parsedata->state_bit = ihandle->state_bit;
   
   if( !player->init )
      MelodyComp_InitIP(handle);
   
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySpMidi, parsedata );
   return (kal_bool)parsedata->data;
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (Time Related)
********************************************************************************
*/
Media_Status MelodyComp_SetStartTime( Media_Handle *handle, kal_int32 msStartTime )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];

   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;  
   parsedata->state_bit = ihandle->state_bit;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_STARTTIME, handle, msStartTime);
   if(player->bad_format)
      return MEDIA_FAIL;
   
   player->jstart_time = msStartTime;
   handle->start_time = handle->current_time = msStartTime;  
   parsedata->data = msStartTime;
   if( ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySetStartTime, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

Media_Status MelodyComp_SetStopTime( Media_Handle *handle, kal_int32 msStopTime )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];

   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;  
   parsedata->state_bit = ihandle->state_bit;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_STOPTIME, handle, msStopTime);
   if(player->bad_format)
      return MEDIA_FAIL;
   
   handle->stop_time = msStopTime;
   parsedata->data = msStopTime;
   if( ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySetStopTime, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

kal_int32 MelodyComp_GetCurrentTime( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];

   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;  
   parsedata->state_bit = ihandle->state_bit;
   
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyGetCurrentTime, parsedata );

   return parsedata->data;
}

kal_int32 MelodyComp_GetDuration( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   parsedata->state_bit = ihandle->state_bit;
   
   if( !player->init )
      MelodyComp_InitIP(handle);

   if(player->bad_format || player->format == MELODYFORMAT_DEV)
      return 0; 
   
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyGetDuration, parsedata );
   if(parsedata->data > MELODY_MAX_DURATION){
        player->bad_format = KAL_TRUE;
      return 0;
   }

   return parsedata->data;
}

Media_Status MelodyComp_SetTempo( Media_Handle *handle, kal_int32 milliTempo )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   kal_int32 tempo;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   parsedata->state_bit = ihandle->state_bit;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_STEMPO, handle, milliTempo);

   if( (milliTempo == 0) )
      return MEDIA_FAIL;
   tempo = 60000000 / milliTempo;
   
   parsedata->data = tempo;
   if( ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySetTempo, parsedata ) != OMX_ErrorNone)
      return MEDIA_FAIL;
      
   return MEDIA_SUCCESS;
}

kal_int32 MelodyComp_GetTempo( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   parsedata->state_bit = ihandle->state_bit;

   if( !player->init )
      MelodyComp_InitIP(handle);
   
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyGetTempo, parsedata );

   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_GTEMPO, handle, parsedata->data);
   return (60000000 / parsedata->data );
}

/*
********************************************************************************
*                        State Control Functions
********************************************************************************
*/
uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );

Media_Status MelodyComp_Play( Media_Handle *handle )
{
   uint32 savedMask;
   MIDI_Player *player;
   MelodySynthParam *synthdata;
   MelodyParseParam *parsedata;
   kal_int32 tmpduration;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
#if MELODY_ENABLE_DEBUGLOG
   kal_prompt_trace(MOD_L1SP, "DougPlay:usage_%x, state:%x, hdl_%x_%x", ihandle->usage, ihandle->state_bit, melodyCtrl.hdl_state[0], melodyCtrl.hdl_state[1]);
#endif
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
#if defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST)
   return MEDIA_SUCCESS;
#endif
   if(!player->dpmrgwt_check){
//      MelodyComp_DPMGR_Load(ihandle);
      player->dpmrgwt_check   = KAL_TRUE;
   }
   tmpduration = MelodyComp_GetDuration(handle);
#if defined(__BES_TS_SUPPORT__)   
   AudioPP_TS_Activate(KAL_FALSE);
#endif
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_PLAY, handle, tmpduration, ihandle->state_bit,handle->start_time);
   if(player->bad_format){
      handle->state = MIDI_STATE_READY;
      if(player->dpmrgwt_check){
//         MelodyComp_DPMGR_Unload(ihandle);
         player->dpmrgwt_check   = KAL_FALSE;
      }
      kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_PLAY, 0, -1, 0, 0);      
      return MEDIA_BAD_FORMAT;
   }
   
   handle->state = MIDI_STATE_PLAYING;
   player->state = MIDI_CTRL_RUN;
   if(player->jstart_time == 0 || player->jtempo_state == 0)
      player->jstart_time = player->jtempo_state = 0;
   
   AFE_SetDigitalGain(L1SP_AUDIO, 100);
   savedMask = SaveAndSetIRQMask();
   parsedata->data = handle->start_time;
   parsedata->state_bit = ihandle->state_bit;
   player->state = MIDI_CTRL_RUN;
   ctrldata->run_state |= (1<<ihandle->state_bit);
   RestoreIRQMask(savedMask);
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodySetStartTime, parsedata);
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyPlayerStart, parsedata);
   synthdata = (MelodySynthParam*)&ctrldata->synthdata;
   ctrldata->DecNode.curHdl->SetParameter( ctrldata->DecNode.curHdl, OMX_IndexConfigMelodyClrIPEndFlag, synthdata);
   
   if(ctrldata->playstate == MIDI_CTRL_INIT){
      ctrldata->DecNode.curHdl->SetParameter( ctrldata->DecNode.curHdl, OMX_IndexConfigMelodyClrEndFlag, synthdata);
      ctrldata->ParNode.curHdl->Start( ctrldata->ParNode.curHdl );
      ctrldata->DecNode.curHdl->Start( ctrldata->DecNode.curHdl );
   #if defined(__AUDIO_MIXER_SUPPORT__)
      if(ihandle->usage == MELODYUSAGE_SOUNDEFFECT)
      {
         ctrldata->SinkNode.curHdl->Start( ctrldata->SinkNode.curHdl );
      }
      else
   #endif
      {
         AudioDrain_Start(ctrldata->mhpb, 32000, 2);
      }
      ctrldata->playstate = MIDI_CTRL_RUN;
   }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_PLAYEND, handle, ctrldata->playstate);
   return MEDIA_SUCCESS;
}

Media_Status MelodyComp_Stop( Media_Handle *handle )
{
   uint32 savedMask;
   uint16 I;
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   kal_bool forcestopflag;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   ASSERT( handle != 0 );
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_STOP, handle, ihandle->state_bit);
#if MELODY_ENABLE_DEBUGLOG
   kal_prompt_trace(MOD_L1SP, "DougStop:usage_%x, state:%x, hdl_%x_%x", ihandle->usage, ihandle->state_bit, melodyCtrl.hdl_state[0], melodyCtrl.hdl_state[1]);
#endif
   forcestopflag = KAL_FALSE;
   player = (MIDI_Player *)handle->data;
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   parsedata->state_bit = ihandle->state_bit;
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyGetParserState, parsedata);
   if(parsedata->data == MELPAR_DATA_RUN)
      forcestopflag = KAL_TRUE;
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyPlayerStop, parsedata);
   savedMask = SaveAndSetIRQMask();
   player->state = MIDI_CTRL_STOP;
   ctrldata->run_state &= ~(1<<ihandle->state_bit);
   RestoreIRQMask(savedMask);
   //tmp sol to not blocking MED
   for(I = 0; I <7; I++){
      ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyGetParserState, parsedata);
      if(parsedata->data == MELPAR_DATA_IDLE)
         break;
      kal_sleep_task(1);
   }
   savedMask = SaveAndSetIRQMask();
   if(ctrldata->playstate == MIDI_CTRL_RUN && !ctrldata->run_state){
      RestoreIRQMask(savedMask);
      ctrldata->ParNode.curHdl->Stop( ctrldata->ParNode.curHdl );
      ctrldata->DecNode.curHdl->Stop( ctrldata->DecNode.curHdl );
   #if defined(__AUDIO_MIXER_SUPPORT__)
      if(ihandle->usage == MELODYUSAGE_SOUNDEFFECT)
      {
         if(forcestopflag)
            ctrldata->SinkNode.curHdl->SetParameter(ctrldata->SinkNode.curHdl, OMX_IndexParamMediaTekRenderAbortStop, NULL);
         ctrldata->SinkNode.curHdl->Stop( ctrldata->SinkNode.curHdl );
      }
      else
   #endif
      {
         AudioDrain_Stop(ctrldata->mhpb);
      }

      ACU_FlushBufferQueue( (AudComHdl *)ctrldata->ParNode.curHdl );
      ACU_FlushBufferQueue( (AudComHdl *)ctrldata->DecNode.curHdl );
      ACU_FlushBufferQueue( (AudComHdl *)ctrldata->SinkNode.curHdl );
      while ( !ACU_IsFlushed () ) {
         kal_sleep_task(1);
      }
      ctrldata->playstate = MIDI_CTRL_INIT;
      savedMask = SaveAndSetIRQMask();
   }
   RestoreIRQMask(savedMask);
   if(player->dpmrgwt_check){
//      MelodyComp_DPMGR_Unload(ihandle);
      player->dpmrgwt_check   = KAL_FALSE;
   }
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_STOP, handle, ctrldata->playstate);
   return MEDIA_SUCCESS;
}

Media_Status MelodyComp_Free( Media_Handle *handle )
{
   MIDI_Player *player;
   MelodyParseParam *parsedata;
   Media_Handle_MIDICTRL *ihandle = (Media_Handle_MIDICTRL *)handle;
   MELODYUSAGE_T usage = ihandle->usage;
   MIDI_CTRL_MANAGER_INT *ctrldata = (MIDI_CTRL_MANAGER_INT*)melodyCtrl.data[ihandle->usage];
   
   ASSERT( handle != 0 );
   player = (MIDI_Player *)handle->data;
   parsedata = (MelodyParseParam*)&ctrldata->parsedata;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_FREE, handle, ihandle->state_bit, melodyCtrl.hdl_state[ihandle->usage], player->state);
#if MELODY_ENABLE_DEBUGLOG
   kal_prompt_trace(MOD_L1SP, "DougFree:usage_%x, state:%x, hdl_%x_%x", ihandle->usage, ihandle->state_bit, melodyCtrl.hdl_state[0], melodyCtrl.hdl_state[1]);
#endif
   if(player->state == MIDI_CTRL_RUN)
      MelodyComp_Stop(handle);
   parsedata->state_bit = ihandle->state_bit;
   ctrldata->ParNode.curHdl->SetParameter( ctrldata->ParNode.curHdl, OMX_IndexConfigMelodyPlayerFree, parsedata);
   if(player->wrkbuf)
      audio_free_mem( (void **) &player->wrkbuf);
   MelodyComp_ReleaseHandle(handle);
   if(player->format == MELODYFORMAT_DEV)
      ctrldata->mid_device = KAL_FALSE;

   if(!melodyCtrl.hdl_state[usage]){
      ctrldata->mhpb->mh.Close( &ctrldata->mhpb->mh );
      
      ctrldata->playstate = MIDI_CTRL_IDLE;
      ctrldata->init = KAL_FALSE;
      MelodyComp_DeInitMelodyCtrlMgr(usage);
   }
   
   return MEDIA_SUCCESS;
}

void MelodyComp_SetUsage(kal_bool soundeffect)   //true: sound effect, false: music sound
{
   if(soundeffect)
      melodyCtrl.current_usage = MELODYUSAGE_SOUNDEFFECT;
   else
      melodyCtrl.current_usage = MELODYUSAGE_MUSICSOUND;
}

static kal_bool melodytemp = KAL_FALSE;

kal_bool MelodyCompSwitch()
{
#if 1
   if(melodytemp == KAL_FALSE)
      melodytemp = KAL_TRUE;
   else
      melodytemp = KAL_FALSE;
#endif
   return melodytemp;
}

#else
#error the framework should either be SINGLE_PASER_SINGLE_WTSYNTH or MULTIPLE_PASER_SINGLE_WTSYNTH
#endif /* SINGLE_PASER_SINGLE_WTSYNTH, MULTIPLE_PASER_SINGLE_WTSYNTH */


#endif  /* DSP_WT_SYN */
