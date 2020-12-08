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
 * melody_sw_syn.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Software MIDI Synthesizer Definitions
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
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MELODY_SW_SYN_H
#define MELODY_SW_SYN_H


#include "media.h"
#include "l1audio_def.h"
#include "Melody_Component.h"

#define RTMIDI_BUFSIZE       384
#define RTMIDI_INPUTSIZE     256
#define MAX_MIDICHANNEL      16
#define MELODY_MAX_DURATION  108000000

#define MELODY_SAMPLINGRATE     SR_32K
#define MELODY_MAX_POLYPHONY    64
#define MELODY_FINE_POLYPHONY   8
#define MELODY_SYNTH_PERIOD     18
#define MELODY_SMF_NOTEGAIN     96
#define MELODY_IMY_NOTEGAIN    512
#define MELODY_TONE_NOTEGAIN   2048

#define MIDI_STATE_OPENED        1
#define MIDI_STATE_READY         2
#define MIDI_STATE_PLAYING       3
#define MIDI_STATE_PAUSED        4
#define MIDI_STATE_ABORT         5
#define MIDI_STATE_ENDING        6
#define MIDI_STATE_RTMIDI_OPENED 7 
#define MIDI_STATE_RTMIDI_ONLY   8

#define MIDI_CTRL_IDLE               0
#define MIDI_CTRL_INIT               1
#define MIDI_CTRL_RUN                2
#define MIDI_CTRL_STOP               3

#define MELODY_DEV_INST      0xFF
#define MELODY_DEV_FILELEN   0xFFFF

typedef enum{
   MELODYFORMAT_SMF = 0,
   MELODYFORMAT_IMY,
   MELODYFORMAT_JTS,
   MELODYFORMAT_DEV
}MELODYFORMAT_T;



typedef struct {
   kal_uint8   program;
   kal_uint8   volume;
}TCKMIDI_CHANNEL_T;

#if SINGLE_PASER_SINGLE_WTSYNTH
typedef struct {
union {
   Media_SMF_Param     smf;
   Media_iMelody_Param imy;
   Media_ToneSeq_Param jts;
}param;
      kal_bool           init;
      kal_bool           fplay;
      kal_bool           bad_format;
      kal_bool           freaderr;
      kal_bool           dpmrgwt_check;
      kal_int32          pitchTranspose;
      kal_int32          tempo;
      kal_int32          jstart_time;
      kal_int32          java_tempo;
      kal_int32          jtempo_state;
      kal_int32          state;
      MELODYFORMAT_T     format;
      MelodyParseParam   parsedata;
      MelodySynthParam   synthdata;
      MelodyDevParam     devdata;
      AcHdlNode          ParNode;
      AcHdlNode          DecNode;
      AcHdlNode          SinkNode;
      AcHdlNode          PPNode;
      void*              wrkbuf;
      TCKMIDI_CHANNEL_T  tckmidchannel[MAX_MIDICHANNEL];
      kal_int32          pitchtrans;
   #if defined(MIDFILE_PLAY_SUPPORT)
      kal_int32          fsize;
   #endif
   } MIDI_Player;

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Multiple Parser Framework
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#elif MULTIPLE_PASER_SINGLE_WTSYNTH
   
   typedef struct {
   union {
      Media_SMF_Param     smf;
      Media_iMelody_Param imy;
      Media_ToneSeq_Param jts;
   }param;
      kal_bool          init;
      kal_bool          fplay;
      kal_bool          bad_format;
      kal_bool          freaderr;
      kal_bool          dpmrgwt_check;
      kal_int32         pitchTranspose;
      kal_int32         tempo;
      kal_int32         jstart_time;
      kal_int32         java_tempo;
      kal_int32         jtempo_state;
      kal_int32         state;
      MELODYFORMAT_T    format;
      void*             wrkbuf;
   #if defined(MIDFILE_PLAY_SUPPORT)
      int               fsize;
   #endif
   } MIDI_Player;
   
   typedef struct media_handle_midictrl {
      Media_Handle     mh;      /* this should be the first line in this structure */
      kal_uint16       state_bit;
      kal_uint16       hdlstate;
      kal_uint16       end_flag;
      MELODYUSAGE_T     usage;
      struct media_handle_midictrl *next;
   } Media_Handle_MIDICTRL;
   
   typedef struct {
   	  kal_bool                init;
      kal_bool                dpmrgwt_check;
      kal_bool                mid_device;
      kal_bool                endingflag;
      kal_uint16              playstate;
      kal_uint16              run_state;
      kal_uint16              parser_size;
      kal_int32               pitchtrans;
      kal_int8                dpmrgwt_count;
      MelodyParseParam        parsedata;
      MelodySynthParam        synthdata;
      AcHdlNode               ParNode;
      AcHdlNode               DecNode;
      AcHdlNode               SinkNode;
      AcHdlNode               PPNode;
      MHPB_Internal           *mhpb;
      TCKMIDI_CHANNEL_T       tckmidchannel[MAX_MIDICHANNEL];
      Media_Handle_MIDICTRL   *hdl_list;
      void                    *wrkbuf;
   }MIDI_CTRL_MANAGER_INT;
   
   typedef struct {
      kal_uint16              hdl_state[2];   // sound effect
      MELODYUSAGE_T           current_usage;
      MIDI_CTRL_MANAGER_INT   *data[2];
   }MIDI_CTRL_MANAGER;

   extern MIDI_CTRL_MANAGER melodyCtl;
   
#else
#error the framework should either be SINGLE_PASER_SINGLE_WTSYNTH or MULTIPLE_PASER_SINGLE_WTSYNTH
#endif /* SINGLE_PASER_SINGLE_WTSYNTH, MULTIPLE_PASER_SINGLE_WTSYNTH */

extern const unsigned char Wavetable[];

extern void AFE_SetDigitalGain( kal_uint8 aud_func, kal_uint8 level );

extern OMX_U32 MelodyDev_GetMemSize( void );
extern OMX_U32 MelodyPar_GetMemSize( void );
extern OMX_ERRORTYPE MelodyDev_Init(AudComHdl **pHandle, void *pBuffer, void *pFWData, AudComCallback *pCallback);
extern OMX_ERRORTYPE MelodyPar_Init(AudComHdl **pHandle, void *pBuffer, void *pFWData, AudComCallback *pCallback);
extern OMX_U32 MelodySyn_GetMemSize( void );
extern OMX_ERRORTYPE MelodySyn_Init(AudComHdl **pHandle, void *pBuffer, void *pFWData, AudComCallback *pCallback);
extern OMX_ERRORTYPE MelodySyn_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct);
extern void MelodyComp_InitIP(Media_Handle *handle);
extern void MelodyComp_Init(Media_Handle *handle, MIDI_Player *player, bool isMidiDevice);
extern Media_Status MelodyComp_Free( Media_Handle *handle );
extern Media_Status MelodyComp_Play( Media_Handle *handle );
extern Media_Status MelodyComp_Stop( Media_Handle *handle );
extern MIDI_Format MelodyComp_Format( Media_Handle *handle );
extern kal_int32 MelodyComp_GetPitchTranspose( Media_Handle *handle );
extern kal_int32 MelodyComp_GetRate( Media_Handle *handle );
extern kal_uint8 MelodyComp_GetLevel( Media_Handle *handle );
extern int32 MelodyComp_GetDuration( Media_Handle *handle );
extern kal_int32 MelodyComp_GetCurrentTime( Media_Handle *handle );
extern Media_Status MelodyComp_SetPitchTranspose( Media_Handle *handle, kal_int32 milliSt );
extern Media_Status MelodyComp_SetLevel( Media_Handle *handle, kal_uint8 level );
extern Media_Status MelodyComp_SetProgram(Media_Handle *handle, kal_uint8 channel, kal_uint8 program);
extern Media_Status MelodyComp_SetRate( Media_Handle *handle, kal_int32 milliRate );
extern Media_Status MelodyComp_SetStartTime( Media_Handle *handle, kal_int32 msStartTime );
extern Media_Status MelodyComp_SetStopTime( Media_Handle *handle, kal_int32 msStopTime );
extern Media_Status MelodyComp_SetTSRate( Media_Handle *handle, kal_int32 Rate );
extern Media_Handle *MelodyComp_ObtainHandle( kal_bool mid_device );

extern void MelodyComp_SetTCKChannelVolume(Media_Handle *handle, kal_uint8 channel, kal_uint8 level );
extern kal_uint8 MelodyComp_GetTCKChannelVolume(Media_Handle *handle, kal_uint8 channel);
extern void MelodyComp_SetTCKChannelProgram(Media_Handle *handle, kal_uint8 channel, kal_uint8 program );
extern kal_uint8 MelodyComp_GetTCKChannelProgram(Media_Handle *handle, kal_uint8 channel);
extern kal_uint8 MelodyComp_GetChannelProgram(Media_Handle *handle, kal_uint8 channel);
extern kal_uint8 MelodyComp_GetChannelVolume(Media_Handle *handle, kal_uint8 channel);
extern kal_int32 MelodyComp_GetTempo( Media_Handle *handle );
extern Media_Status MelodyComp_SetTempo( Media_Handle *handle, kal_int32 milliTempo );
extern kal_bool MelodyComp_isSpMidi(Media_Handle *handle);
extern Media_Status MelodyComp_SendShortMsg( Media_Handle *handle, kal_uint8 type, kal_uint8 data1, kal_uint8 data2 );
extern Media_Status MelodyComp_SendLongMsg( Media_Handle *handle, const uint8 *buf, uint16 len );


#endif  /* MELODY_SW_SYN_H */
