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
 * jsmf.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SMF playback using DSP wavetable synthesizer
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*
********************************************************************************
*                         SW Synthesizer Region
********************************************************************************
*/
#if defined( DSP_WT_SYN )
                      
#include "kal_public_api.h"
#include "string.h"
#include "fsal.h"

#include "l1audio.h"
#include "audio_def.h"
#include "melody_sw_syn.h"

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
*                         Real-Time MIDI Device Control APIs
********************************************************************************
*/
extern void MelodyComp_EvtCallback(void *hdl, int evt);
void JMidi_SetBuffer( Media_Handle *handle, int8 *buffer, uint32 buf_len )
{
   MIDI_Player *player;
   MelodyDevParam *devdata;
   MelodySynthParam *synthdata;
   SinkParam sinkParam;
   
   ASSERT( buf_len >= sizeof(MIDI_Player) );
   player = (MIDI_Player*)buffer;
   //Init Component
   MelodyComp_Init(handle,player, true);
   
   //Init Melody Synthesizer IP
   devdata   = (MelodyDevParam*)&player->devdata;

   devdata->meldata.rtmidi_ptr     = 0;
   devdata->meldata.rtmidi_count   = 0;
   devdata->meldata.rtmidi_running = false;
   devdata->meldata.rtmidi_status  = 0;
   devdata->meldata.rtmidi_wait    = false;
   devdata->meldata.evthdl         = handle;
   devdata->meldata.evtcall        = &MelodyComp_EvtCallback;
   player->ParNode.curHdl->SetParameter(player->ParNode.curHdl, OMX_IndexConfigMelodyDeviceInit, devdata);
   
   synthdata = (MelodySynthParam*)&player->synthdata;
   synthdata->meldata.tonegain   = MELODY_IMY_NOTEGAIN;
   synthdata->meldata.samplerate = MELODY_SAMPLINGRATE;
   synthdata->meldata.maxtone    = MELODY_MAX_POLYPHONY;
   synthdata->meldata.finetone   = MELODY_FINE_POLYPHONY;
   synthdata->meldata.period     = MELODY_SYNTH_PERIOD;
   synthdata->meldata.wavtab     = (unsigned char*)Wavetable;
   synthdata->meldata.evthdl     = handle;
   synthdata->meldata.evtcall    = &MelodyComp_EvtCallback;
   player->DecNode.curHdl->SetParameter(player->DecNode.curHdl, OMX_IndexConfigMelodySynthesizerInit, synthdata);
   
   //Init PCM Sink
   sinkParam.uSamplingFreq = 32000;
   sinkParam.uChannelNum   = 2;
   player->SinkNode.curHdl->SetParameter(player->SinkNode.curHdl, OMX_IndexParamMediaTekPcmSink, &sinkParam);
   
   player->init = true;
   //Init IP

   //Init Player   
   player->pitchTranspose  = 0;
   player->tempo           = 0;
   player->java_tempo      = 0;
   player->jtempo_state    = 0;
   player->jstart_time     = 0;
   player->bad_format      = false;
   player->dpmrgwt_check   = false;
   player->init            = true;
   player->freaderr        = false;
   player->format          = MELODYFORMAT_DEV;
   handle->data            = (uint32)player;
   handle->start_time      = 0;
   
   MelodyComp_Play(handle);
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Multiple Parser Framework
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#elif MULTIPLE_PASER_SINGLE_WTSYNTH
/*
********************************************************************************
*                         Real-Time MIDI Device Control APIs
********************************************************************************
*/

extern void MelodyComp_EvtCallback(void *hdl, int evt);
void JMidi_SetBuffer( Media_Handle *handle, int8 *buffer, uint32 buf_len )
{
#if defined(__AUDIO_ULTRA_SLIM__)
   return;
#else
   MIDI_Player *player;
   
   ASSERT( buf_len >= sizeof(MIDI_Player) );

   player = (MIDI_Player*)buffer;
   //Init Player   
   player->pitchTranspose  = 0;
   player->tempo           = 0;
   player->java_tempo      = 0;
   player->jtempo_state    = 0;
   player->jstart_time     = 0;
   player->bad_format      = false;
   player->dpmrgwt_check   = false;
   player->init            = true;
   player->freaderr        = false;
   player->format          = MELODYFORMAT_DEV;
   handle->data            = (uint32)player;
   handle->start_time      = 0;
   MelodyComp_Init(handle,player, true);
   MelodyComp_InitIP(handle);
   MelodyComp_Play(handle);
#endif
}

#else
#error the framework should either be SINGLE_PASER_SINGLE_WTSYNTH or MULTIPLE_PASER_SINGLE_WTSYNTH
#endif /* SINGLE_PASER_SINGLE_WTSYNTH, MULTIPLE_PASER_SINGLE_WTSYNTH */

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Common Part in Both Framework
------------------------------------------------------------------------------------------------------------
********************************************************************************
*                        Utility Functions
********************************************************************************
*/

void SMF_GetFSData(void *hdl, int evt, unsigned char* ptr, unsigned int len)
{
   MIDI_Player *player;
   MELPAR_FSREQUEST req;
   STFSAL *pstFSAL;
   
   player = (MIDI_Player*)hdl;
   pstFSAL = player->param.smf.pstFSAL;
   req = (MELPAR_FSREQUEST)evt;

   if(req == MELPAR_FSREAD){
      FSAL_Read_Bytes(pstFSAL, ptr, len);
   }else if(req == MELPAR_FSSKIP){
      FSAL_Skip_Bytes(pstFSAL, len);
   }else if(req == MELPAR_FSSEEK){
      FSAL_Seek( pstFSAL, len );
   }
   return;
}

/*
********************************************************************************
*                        Dummy Functions
********************************************************************************
*/
void JSmf_Init( void )
{
}

int32 JSmf_GetMidiDuration( const uint8 *mid)
{
   (void) mid; 
   return -1;   
}

#if defined(__BES_TS_SUPPORT__)
Media_Handle *TS_Midi_Handle;   // KH: Add for Time Stretch
#endif
/*
********************************************************************************
*                        Extened Events (Peripheral Devices)
********************************************************************************
*/

Media_Event JSmf_QueryExtEvent( Media_Handle *handle, int32 *note )
{
   //callback ³B²z
   return MEDIA_NONE;
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (Sound Properties)
********************************************************************************
*/

kal_int8 JMidi_GetChannelVolume( Media_Handle *handle, kal_int8 channel )
{
   kal_uint8 tmpvolume;
   ASSERT( handle != 0 );

   tmpvolume = MelodyComp_GetTCKChannelVolume(handle, channel);
   if(tmpvolume != 0xFF){
      return tmpvolume;
   }
   
   return (kal_int8)MelodyComp_GetChannelVolume(handle, channel);
}

void JMidi_GetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 *bank, kal_int8 *program )
{
   kal_uint8 tmpprogram;
   ASSERT( handle != 0 );
   *bank = 0;
   
   tmpprogram = MelodyComp_GetTCKChannelProgram(handle, channel);
   if(tmpprogram != 0xFF){
      *program = tmpprogram;
      return;
   }
   *program = MelodyComp_GetChannelProgram(handle, channel);
}
/*
********************************************************************************
*                        Parameter Query and Set APIs (Play Speed Related)
********************************************************************************
*/
kal_int32 JMidi_GetTempo( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   return MelodyComp_GetTempo(handle);
}

Media_Status JMidi_SetTempo( Media_Handle *handle, kal_int32 milliTempo )
{
   ASSERT( handle != 0 );
   return (Media_Status)MelodyComp_SetTempo(handle, milliTempo);
}

Media_Status JMidi_SetTSRate( Media_Handle *handle, kal_int32 Rate )
{
   ASSERT( handle != 0 );
   return MelodyComp_SetTSRate(handle, Rate);
}

kal_int32 JMidi_GetRate( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   return MelodyComp_GetRate(handle);
}

Media_Status JMidi_SetRate( Media_Handle *handle, kal_int32 milliRate )
{
   ASSERT( handle != 0 );
   return MelodyComp_SetRate(handle, milliRate);
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (Time Related)
********************************************************************************
*/
kal_int32 JSmf_GetCurrentTime( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   return MelodyComp_GetCurrentTime(handle);
}

Media_Status JSmf_SetStartTime( Media_Handle *handle, kal_int32 msStartTime )
{
   ASSERT( handle != 0 );
   return MelodyComp_SetStartTime(handle, msStartTime);
}

Media_Status JSmf_SetStopTime( Media_Handle *handle, kal_int32 msStopTime )
{
   ASSERT( handle != 0 );
   return MelodyComp_SetStopTime( handle, msStopTime );
}

int32 JSmf_GetDuration( Media_Handle *handle )
{
   MIDI_Format format;
#if defined( MIDFILE_PLAY_SUPPORT )
   STFSAL *pstFSAL;
#endif
   int32 duration;
#if defined( MIDFILE_PLAY_SUPPORT )   
   MIDI_Player *player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   pstFSAL = player->param.smf.pstFSAL;
   if(pstFSAL != NULL)
      return -1;
#endif
   duration = MelodyComp_GetDuration(handle);
   format = MelodyComp_Format(handle);
   if( (format != FORMAT_SMF) && (format != FORMAT_CMI) )
      return 0;
   return duration;
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (Sound Properties)
********************************************************************************
*/
kal_int32 JMidi_GetPitchTranspose( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   return (kal_int32)MelodyComp_GetPitchTranspose(handle)*1000;
}

Media_Status JMidi_SetPitchTranspose( Media_Handle *handle, kal_int32 milliSt )
{
   ASSERT( handle != 0 );
   return (Media_Status)MelodyComp_SetPitchTranspose( handle, milliSt/1000 );
}

kal_uint8 JMidi_GetLevel( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   return (kal_uint8)MelodyComp_GetLevel(handle);
}

Media_Status JMidi_SetLevel( Media_Handle *handle, kal_uint8 level )
{
   ASSERT( handle != 0 );
   return (Media_Status)MelodyComp_SetLevel( handle, level );
}

kal_bool JSmf_isSpMidi( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   return (kal_bool)MelodyComp_isSpMidi(handle);
}
/*
********************************************************************************
*                         Real-Time MIDI Device Control APIs
********************************************************************************
*/
Media_Status JMidi_SendLongMsg( Media_Handle *handle, const uint8 *buf, uint16 len )
{
#if !defined(__AUDIO_ULTRA_SLIM__)
   return MelodyComp_SendLongMsg(handle, buf, len);
#endif
}

Media_Status JMidi_SendShortMsg( Media_Handle *handle, kal_uint8 type, kal_uint8 data1, kal_uint8 data2 )
{
#if !defined(__AUDIO_ULTRA_SLIM__)
   return MelodyComp_SendShortMsg(handle, type, data1, data2);
#endif
}

Media_Status JMidi_SetProgram( Media_Handle *handle, kal_int8 channel, kal_int16 bank, kal_int8 program )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   ASSERT( channel >= 0 && channel <= 15 );
   if( !player->init )
      MelodyComp_InitIP(handle);
   JMidi_SendShortMsg( handle, 0xC0 + channel, program, 0 );
   MelodyComp_SetTCKChannelProgram(handle, channel, program);

   return MEDIA_SUCCESS;
}

Media_Status JMidi_SetChannelVolume( Media_Handle *handle, kal_int8 channel, kal_uint8 level )
{
   MIDI_Player *player = (MIDI_Player *)handle->data;
   ASSERT( player != (MIDI_Player *)0 );
   ASSERT( channel >= 0 && channel <= 15 );
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_COMP_SVOLUME, handle, channel, level);
   if( !player->init )
      MelodyComp_InitIP(handle);
   JMidi_SendShortMsg( handle, 0xB0 + channel, 0x07, level );
   MelodyComp_SetTCKChannelVolume(handle, channel, level);
   
   return MEDIA_SUCCESS;
}

Media_Handle *JMidi_OpenDevice( uint32 *requiredBufSize )
{
#if defined(__AUDIO_ULTRA_SLIM__)
   return 0;
#else
   Media_Handle *handle;
   if( (handle = MelodyComp_ObtainHandle(true)) == 0 )
      return 0;
   handle->state           = MIDI_STATE_OPENED;
   handle->stop_flag       = false;
   handle->volume_level    = 100;
   handle->start_time      = 0;
   handle->stop_time       = 0x7FFFFFFF;   
   handle->param           = 0;
   handle->data            = 0;
   handle->appflag         = false;
   *requiredBufSize        = sizeof(MIDI_Player);
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_OPEN, 3, handle);
   return handle;
#endif
}

Media_Status JMidi_CloseDevice( Media_Handle *handle )
{
#if defined(__AUDIO_ULTRA_SLIM__)
   return 0;
#else
   MIDI_Player *player;
   ASSERT( handle != 0 );
   player = (MIDI_Player *)handle->data;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_CLS, 3, handle);
   if( player != (MIDI_Player*)0){
      MelodyComp_Free(handle);
   }
   return MEDIA_SUCCESS;
#endif //__AUDIO_ULTRA_SLIM__
}

/*
********************************************************************************
*                         SMF State Control APIs Common Part
********************************************************************************
*/
void JSmf_SetBuffer( Media_Handle *handle, int8 *buffer, uint32 buf_len, Media_SMF_Param **param )
{
   MIDI_Player *player;
  
   ASSERT( buf_len >= sizeof(MIDI_Player) );
   player = (MIDI_Player*)buffer;
   MelodyComp_Init(handle,player, false);
   player->pitchTranspose  = 0;
   player->tempo           = 0;
   player->java_tempo      = 0;
   player->jtempo_state    = 0;
   player->jstart_time     = 0;
   player->bad_format      = false;
   player->init            = false;
   player->freaderr        = false;
   player->dpmrgwt_check   = false;
   player->format          = MELODYFORMAT_SMF;
   handle->state           = MIDI_STATE_READY;
   handle->param           = (void *)&player->param.smf;
   handle->data            = (uint32)player;
   *param                  = &player->param.smf;
   
   return;
}

Media_Handle *JSmf_Open( void (*handler)( Media_Handle *handle, Media_Event event ), uint32 *requiredBufSize )
{
   Media_Handle *handle;
   if( (handle = MelodyComp_ObtainHandle(false)) == 0 )
      return 0;
   handle->handler         = handler;
   handle->state           = MIDI_STATE_OPENED;
   handle->stop_flag       = false;
   handle->volume_level    = 100;
   handle->start_time      = 0;
   handle->stop_time       = 0x7FFFFFFF;   
   handle->param           = 0;
   handle->data            = 0;
   handle->appflag         = false;
   *requiredBufSize        = sizeof(MIDI_Player);
#if defined(__BES_TS_SUPPORT__)
   AudioPP_SetMediaFormat(MEDIA_FORMAT_SMF);
   TS_Midi_Handle = handle;   // Duplicate for Time Stretch
#endif
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_OPEN, 0, handle);
   return handle;
}

Media_Status JSmf_Close( Media_Handle *handle )
{
   MIDI_Player *player;
   ASSERT( handle != 0 );
   player = (MIDI_Player *)handle->data;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_CLS, 0, handle);
#if defined(__BES_TS_SUPPORT__)
   AudioPP_SetMediaFormat(MEDIA_FORMAT_DAF);
   TS_Midi_Handle = NULL;   // Release for Time Stretch
#endif
   if( player != (MIDI_Player*)0){
      MelodyComp_Free(handle);
   }

   return MEDIA_SUCCESS;
}

Media_Status JSmf_Play( Media_Handle *handle )
{
   Media_Status status;
   MIDI_Format format;
   ASSERT( handle != 0 );
   format = MelodyComp_Format(handle);
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_PLAY, 0, handle, format, handle->repeat_count);
   if( (format != FORMAT_SMF) && (format != FORMAT_CMI) )
      return MEDIA_FAIL;
   status = MelodyComp_Play(handle);
   return status;
}

Media_Status JSmf_Pause( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   handle->start_time = MelodyComp_GetCurrentTime(handle);
   JSmf_SetStartTime(handle, handle->start_time);
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_PAUSE, 0, handle, handle->start_time);
   return MelodyComp_Stop(handle);
}
Media_Status JSmf_Resume( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_RESUME, 0, handle);
   return MelodyComp_Play(handle);
}
Media_Status JSmf_Stop( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   handle->start_time = 0;
   JSmf_SetStartTime(handle, handle->start_time);
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_STOP, 0, handle, handle->start_time);
   return MelodyComp_Stop(handle);
}

/*
********************************************************************************
*                        Parameter Query and Set APIs (JAVA Specific)
********************************************************************************
*/
Media_Status JSmf_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize,
                  audInfoStruct *contentInfo, void *param )
{
   contentInfo->bitRate = 0;
   contentInfo->sampleRate = 32000;
   return MEDIA_SUCCESS;
}
Media_Status JSmf_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   contentInfo->bitRate    = 0;
   contentInfo->sampleRate = 32000;
   return MEDIA_SUCCESS;
}
#if defined(__J2ME__)

static const kal_int8 programList[] = {
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
   20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
   40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
   60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
   80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
  100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,
  120,121,122,123,124,125,126,127
};

static const uint8 instrumentName[128][23] = {
   "Acoustic Grand Piano  ",     // 0
   "Bright Acoustic Piano ",
   "Electric Grand Piano  ",
   "Honky-Tonk            ",
   "Electric Piano 1      ",
   "Electric Piano 2      ",
   "Harpsichord           ",
   "Clavinet              ",
   "Celesta               ",
   "Glockenspiel          ",
   "Music Box             ",     // 10
   "Vibraphone            ",
   "Marimba               ",
   "Xylophone             ",
   "Tubular Bells         ",
   "Dulcimer              ",
   "Drawbar Organ         ",
   "Percussive Organ      ",
   "Rock Organ            ",
   "Church Organ          ",
   "Reed Organ            ",     // 20
   "Accoridan             ",
   "Harmonica             ",
   "Tango Accordian       ",
   "Acoustic Guitar(nylon)",
   "Acoustic Guitar(steel)",
   "Electric Guitar(jazz) ",
   "Electric Guitar(clean)",
   "Electric Guitar(muted)",
   "Overdriven Guitar     ",
   "Distortion Guitar     ",     // 30
   "Guitar Harmonics      ",
   "Acoustic Bass         ",
   "Electric Bass(finger) ",
   "Electric Bass(pick)   ",
   "Fretless Bass         ",
   "Slap Bass 1           ",
   "Slap Bass 2           ",
   "Synth Bass 1          ",
   "Synth Bass 2          ",
   "Violin                ",     // 40
   "Viola                 ",
   "Cello                 ",
   "Contrabass            ",
   "Tremolo Strings       ",
   "Pizzicato Strings     ",
   "Orchestral Harp       ",
   "Timpani               ",
   "String Ensemble 1     ",
   "String Ensemble 2     ",
   "SynthStrings 1        ",     // 50
   "SynthStrings 2        ",
   "Choir Aahs            ",
   "Voice Oohs            ",
   "Synth Voice           ",
   "Orchestra Hit         ",
   "Trumpet               ",
   "Trombone              ",
   "Tuba                  ",
   "Muted Trumpet         ",
   "French Horn           ",     // 60
   "Brass Section         ",
   "SynthBrass 1          ",
   "SynthBrass 2          ",
   "Soprano Sax           ",
   "Alto Sax              ",
   "Tenor Sax             ",
   "Baritone Sax          ",
   "Oboe                  ",
   "English Horn          ",
   "Bassoon               ",     // 70
   "Clarinet              ",
   "Piccolo               ",
   "Flute                 ",
   "Recorder              ",
   "Pan Flute             ",
   "Blown Bottle          ",
   "Skakuhachi            ",
   "Whistle               ",
   "Ocarina               ",
   "Lead 1 (square)       ",     // 80
   "Lead 2 (sawtooth)     ",
   "Lead 3 (calliope)     ",
   "Lead 4 (chiff)        ",
   "Lead 5 (charang)      ",
   "Lead 6 (voice)        ",
   "Lead 7 (fifths)       ",
   "Lead 8 (bass+lead)    ",
   "Pad 1 (new age)       ",
   "Pad 2 (warm)          ",
   "Pad 3 (polysynth)     ",     // 90
   "Pad 4 (choir)         ",
   "Pad 5 (bowed)         ",
   "Pad 6 (metallic)      ",
   "Pad 7 (halo)          ",
   "Pad 8 (sweep)         ",
   "FX 1 (rain)           ",
   "FX 2 (soundtrack)     ",
   "FX 3 (crystal)        ",
   "FX 4 (atmosphere)     ",
   "FX 5 (brightness)     ",     // 100
   "FX 6 (goblins)        ",
   "FX 7 (echoes)         ",
   "FX 8 (sci-fi)         ",
   "Sitar                 ",
   "Banjo                 ",
   "Shamisen              ",
   "Koto                  ",
   "Kalimba               ",
   "Bagpipe               ",
   "Fiddle                ",     // 110
   "Shanai                ",
   "Tinkle Bell           ",
   "Agogo                 ",
   "Steel Drums           ",
   "Woodblock             ",
   "Taiko Drum            ",
   "Melodic Tom           ",
   "Synth Drum            ",
   "Reverse Cymbal        ",
   "Guitar Fret Noise     ",     // 120
   "Breath Noise          ",
   "Seashore              ",
   "Bird Tweet            ",
   "Telephone Ring        ",
   "Helicopter            ",
   "Applause              ",
   "Gunshot               "
};

static const uint8 percussionName[85-32][19] = {
   "Unknown           ",        /* 33 */
   "Acoustic Bass Drum",        /* 34 */
   "Bass Drum 1       ",
   "Side Stick        ",
   "Acoustic Snare    ",
   "Hand Clap         ",
   "Electric Snare    ",
   "Low Floor Tom     ",
   "Closed Hi-Hat     ",
   "High Floor Tom    ",
   "Pedal Hi-Hat      ",
   "Low Tom           ",
   "Open Hi-Hat       ",
   "Low-Mid Tom       ",
   "Hi-Mid Tom        ",
   "Crash Cymbal 1    ",
   "High Tom          ",
   "Ride Cymbal 1     ",
   "Chinese Cymbal    ",
   "Ride Bell         ",
   "Tambourine        ",
   "Splash Cymbal     ",
   "Cowbell           ",
   "Crash Cymbal 2    ",
   "Vibraslap         ",
   "Ride Cymbal 2     ",
   "Hi Bongo          ",
   "Low Bongo         ",
   "Mute Hi Conga     ",
   "Open Hi Conga     ",
   "Low Conga         ",
   "High Timbale      ",
   "Low Timbale       ",
   "High Agogo        ",
   "Low Agogo         ",
   "Cabasa            ",
   "Maracas           ",
   "Short Whistle     ",
   "Long Whistle      ",
   "Short Guiro       ",
   "Long Guiro        ",
   "Claves            ",
   "Hi Wood Block     ",
   "Low Wood Block    ",
   "Mute Cuica        ",
   "Open Cuica        ",
   "Mute Triangle     ",
   "Open Triangle     ",        /* 80 */
   "Unknown           ",        /* 81 */
   "Unknown           ",
   "Unknown           ",
   "Bell Tree         ",        /* 84 */
   "Unknown           ",        /* 85 */
};

kal_bool JMidi_isBankQuerySupported( void )
{
   return KAL_TRUE;
}

void JMidi_GetBankList( kal_bool custom, const kal_int16 **buf, kal_int16 *len)
{
   static const kal_int16 banklist[] = { 0 };
   *buf = banklist;
   *len = 1;
}

void JMidi_GetProgramList( kal_int16 bank, const kal_int8 **buf, kal_int16 *len)
{
   *buf = programList;
   if( bank == 0 )
      *len = sizeof(programList) / sizeof(int8);
   else
      *len = 0;
}

const kal_uint8 *JMidi_GetProgramName( kal_int16 bank, kal_int8 prog )
{
   static const uint8 empty_name[] = "";
   if( bank == 0 && prog >= 0 )
      return instrumentName[prog];
   else
      return empty_name;
}

const kal_uint8 *JMidi_GetKeyName( kal_int16 bank, kal_int8 prog, kal_int8 key )
{
   static const uint8 empty_name[] = "";
   if( bank == 0 && prog >= 0 && key >= 0 ) {
      if( key < 33 )
         key = 33;
      if( key > 85 )
         key = 85;
      return percussionName[key-33];
   }
   else
      return empty_name;
}

#endif 

#endif /* DSP_WT_SYN or SW_WT_SYN */
