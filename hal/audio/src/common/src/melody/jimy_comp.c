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
 * jimy.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   iMelody File Format Decoder
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined( DSP_WT_SYN )
                          
#include "kal_public_api.h"

#include "l1audio.h"
#include "audio_def.h"
#include "melody_sw_syn.h"

/*
********************************************************************************
*                        Utility Functions
********************************************************************************
*/

/*
********************************************************************************
*                        Dummy Functions
********************************************************************************
*/
void JImy_Init( void )
{
}

#if defined(__BES_TS_SUPPORT__)
Media_Handle *TS_Imy_Handle;   // KH: Add for Time Stretch
#endif

/*
********************************************************************************
*                        Parameter Query and Set APIs (Time Related)
********************************************************************************
*/
int32 JImy_GetDuration( Media_Handle *handle )
{
   MIDI_Format format;
   int32 duration;
   ASSERT( handle != 0 );
   duration = MelodyComp_GetDuration(handle);
   format = MelodyComp_Format(handle);
   if(format != FORMAT_IMY)
      return 0;
   return duration;
}

Media_Status JImy_SetStartTime( Media_Handle *handle, kal_int32 msStartTime )
{
   ASSERT( handle != 0 );
   return MelodyComp_SetStartTime( handle, msStartTime );
}

Media_Status JImy_SetStopTime( Media_Handle *handle, kal_int32 msStopTime )
{
   ASSERT( handle != 0 );
   return MelodyComp_SetStopTime( handle, msStopTime );
}

kal_int32 JImy_GetCurrentTime( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   return MelodyComp_GetCurrentTime(handle);
}

#if defined(__BES_TS_SUPPORT__)
Media_Status JImy_SetTSRate( Media_Handle *handle, int32 rate)
{
   ASSERT( handle != 0 );
   return MelodyComp_SetRate(handle, rate*1000);
}
#endif

/*
********************************************************************************
*                        Parameter Query and Set APIs (Sound Properties)
********************************************************************************
*/
static void JImy_FillContentInfo( audInfoStruct *contentInfo )
{
   contentInfo->title[0]  = '\0';
   contentInfo->artist[0] = '\0';
   contentInfo->album[0]  = '\0';
   contentInfo->author[0]  = '\0';
   contentInfo->copyright[0]  = '\0';
   contentInfo->date[0]  = '\0';
   contentInfo->bitRate = 0;
   contentInfo->sampleRate = 32000;
}

Media_Status JImy_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param  )
{
   JImy_FillContentInfo(contentInfo);
   return MEDIA_SUCCESS;
}

Media_Status JImy_GetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize,
                     audInfoStruct *contentInfo, void *param )
{
   JImy_FillContentInfo(contentInfo);
   return MEDIA_SUCCESS;
}

Media_Status JImy_SetLevel( Media_Handle *handle, kal_uint8 level )
{
   ASSERT( handle != 0 );
   return MelodyComp_SetLevel( handle, level );
}

kal_uint8 JImy_GetLevel( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   return MelodyComp_GetLevel(handle);
}

/*
********************************************************************************
*                        IMY Control Fucntions
********************************************************************************
*/

Media_Handle *JImy_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_iMelody_Param **param )
{
   Media_Handle *handle;
   MIDI_Player *player;

   if( (handle = MelodyComp_ObtainHandle(false)) == 0 )
      return (Media_Handle*)0;
   handle->handler         = handler;
   handle->state           = MIDI_STATE_OPENED;
   handle->stop_flag       = false;
   handle->volume_level    = 100;
   handle->start_time      = 0;
   handle->stop_time       = 0x7FFFFFFF;   
   handle->param           = 0;
   handle->data            = 0;
   handle->appflag         = false;
   
   player = (MIDI_Player*)get_ctrl_buffer(sizeof(MIDI_Player));

   player->pitchTranspose  = 0;
   player->tempo           = 0;
   player->java_tempo      = 0;
   player->jtempo_state    = 0;
   player->jstart_time     = 0;
   player->bad_format      = false;
   player->init            = false;
   player->freaderr        = false;
   player->dpmrgwt_check   = false;
   player->format          = MELODYFORMAT_IMY;
   handle->state           = MIDI_STATE_READY;
   handle->param           = (void *)&player->param.imy;
   handle->data            = (uint32)player;
   *param                  = &player->param.imy;
   MelodyComp_Init(handle,player, false);
#if defined(__BES_TS_SUPPORT__)
   AudioPP_SetMediaFormat(MEDIA_FORMAT_IMELODY);
   TS_Imy_Handle        = handle;   //Add for Time Stretch
#endif
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_OPEN, 1, handle);
   return handle;
}

Media_Status JImy_Close( Media_Handle *handle )
{
   MIDI_Player *player;
   ASSERT( handle != 0 );
   player = (MIDI_Player *)handle->data;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_CLS, 1, handle);
#if defined(__BES_TS_SUPPORT__)
   AudioPP_SetMediaFormat(MEDIA_FORMAT_DAF);
   TS_Imy_Handle       = NULL;   // KH: Add for Time Stretch
#endif   
   if( player != (MIDI_Player*)0){
      MelodyComp_Free(handle);
      free_ctrl_buffer(player);
   }

   return MEDIA_SUCCESS;
}

Media_Status JImy_Play( Media_Handle *handle )
{
   Media_Status status;
   MIDI_Format format;
   ASSERT( handle != 0 );
   format = MelodyComp_Format(handle);
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_PLAY, 1, handle, format, handle->repeat_count);
   if(format != FORMAT_IMY)
      return MEDIA_FAIL;
   status = MelodyComp_Play(handle);
   return status;
}

Media_Status JImy_Stop( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   handle->start_time = 0;
   JImy_SetStartTime(handle, handle->start_time);
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_STOP, 1, handle, handle->start_time);
   return MelodyComp_Stop(handle);
}

Media_Status JImy_Pause( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   handle->start_time = MelodyComp_GetCurrentTime(handle);
   JImy_SetStartTime(handle, handle->start_time);
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_PAUSE, 1, handle, handle->start_time);
   return MelodyComp_Stop(handle);
}

Media_Status JImy_Resume( Media_Handle *handle )
{
   ASSERT( handle != 0 );
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_RESUME, 1, handle);
   return MelodyComp_Play(handle);
}


/* ------------------------------------------------------------------------------ */
#endif /* DSP_WT_SYN */


