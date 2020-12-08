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
 * jwav.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Wave playback using DSP 64-tone PCM channels 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined( DSP_WT_SYN )

#include "kal_public_api.h"
#include "kal_trace.h"
#include "common_def.h"
#include "l1audio.h"
#include "audio_enum.h"
#include "audio_def.h"
#include "l1sp_trc.h"
#include "media.h"
#include "am.h"
#include "wav.h"

#if defined(WAV_CODEC)


#define PCM_WAVE_VOLUME_SCALE 4580

// state definitions
// Wav state
#define JWAV_STATE_OPENED     21 
#define JWAV_STATE_READY      22
#define JWAV_STATE_PLAYING    23  
#define JWAV_STATE_ABORT      24 
#define JWAV_STATE_PAUSED     25 
#define JWAV_STATE_ENDING     26 


#define DEFAULT_WAV_VOLUME 100

#define DSP_STOP_THEN_START_TIME 4 // 4 * 18ms 

#define WAV_CHAN_OFFSET 1

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );

// data structure 
typedef struct {
   uint32            data_len;
   const kal_uint8   *data_head;
   Media_Wav_Param   Wav_Param;
   STFSAL            *pstFSAL;
   MHdl              *ihdl;
}WAV_Player;

/**** Initialization ****/ 
         
void JWav_Init(mediaControl *ctrl)
{
}

/**** Control APIs ****/
/* XWav : Control APIs */
Media_Handle  *JXWav_Open( void (*handler)( Media_Handle *handle, Media_Event event )){return (Media_Handle*)0;}
Media_Status  JXWav_Close( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status JXWav_Load(Media_Handle *handle, uint32 *requiredBufSize) {return MEDIA_SUCCESS;}
void JXWav_SetBuffer(Media_Handle *handle, int16 *buffer, uint32 buf_len){return;}
Media_Status  JXWav_Play( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status  JXWav_Stop( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status JXWav_Pause( Media_Handle *handle ){return MEDIA_SUCCESS;}
Media_Status JXWav_Resume( Media_Handle *handle ){return MEDIA_SUCCESS;}   
Media_Status  JXWav_SetLevel( Media_Handle *handle, uint8 level ){return MEDIA_SUCCESS;}                     
kal_uint8 JXWav_GetLevel( Media_Handle *handle ){return 0;}
kal_int32 JXWav_GetCurrentTime( Media_Handle *handle ){return 0;}


/* Wav : Control APIs */

void JWav_RepeatinMedTask(kal_uint32 arg1, void *arg2)
{
   Media_Handle *hdl;
   MHdl *handle;
   
   handle = (MHdl*)arg2;
   hdl =  (Media_Handle*)handle->private_data;
   
   if(hdl->repeat_count != 0)
      hdl->repeat_count--;
   handle->Stop(handle);
   handle->start_time = 0;
   handle->Play(handle);
   //kal_prompt_trace(MOD_L1SP,"[Doug]WavRepeat:%x",hdl->repeat_count);
}
void JWav_MsgHandler(MHdl *handle, Media_Event event)
{
   Media_Handle *hdl;
   hdl =  (Media_Handle*)handle->private_data;
   switch(event)
   {
      case MEDIA_DATA_REQUEST:
      case MEDIA_BUFFER_UNDERFLOW:
         L1Audio_InProcCall(handle->Process, (kal_uint32)handle, (void*)event );
         break;
      case MEDIA_END:
         if(hdl->repeat_count != 1 )
         {
            L1Audio_InProcCall(JWav_RepeatinMedTask, NULL , handle );
            break;
         }
         L1Audio_InProcCall(handle->Process, (kal_uint32)handle, (void*)event );
      case MEDIA_STOP_TIME_UP:
      case MEDIA_ERROR:
         hdl->handler(hdl,MEDIA_END);
         break;
   }
}

Media_Handle  *JWav_Open( void (*handler)( Media_Handle *handle, Media_Event event ), Media_Wav_Param **param )
{
   WAV_Player *player;
   Media_Handle *handle;
#if !defined(__AUDIO_MIXER_SUPPORT__)  
   PcmSink_TerminateSound(); 
   if( AM_IsAudioPlaybackOn() != -1 )
      return 0;
#endif
   handle = (Media_Handle*)get_ctrl_buffer(sizeof(Media_Handle));  
   handle->state = JWAV_STATE_OPENED;   
   player = (WAV_Player *)get_ctrl_buffer(sizeof(WAV_Player));
   handle->data = (uint32)player;
   
   handle->param = (void *)&(player->Wav_Param); 
   handle->handler = handler;
   handle->start_time = 0;
   handle->current_time = 0;
   handle->stop_time = 0x7FFFFFFF;   
   handle->volume_level = DEFAULT_WAV_VOLUME;
   handle->repeat_count = 1; 
   handle->appflag      = false;
   
   *param = &(player->Wav_Param);
   (*param)->wavefile = NULL;
   (*param)->filesize = 0;
   (*param)->repeats  = 1;
   (*param)->format   = -1;
   
   player->pstFSAL  = NULL;
   
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_OPEN, 4, handle);
     
   return handle;          
}   

Media_Status  JWav_Close( Media_Handle *handle )
{
   WAV_Player *player;
   MHdl *ihdl;
   ASSERT(handle!=0);
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_CLS, 4, handle);
   player = (WAV_Player *)(handle->data);   
   ihdl = player->ihdl;
   
   ihdl->Close(player->ihdl);

   if(player->pstFSAL)
      free_ctrl_buffer(player->pstFSAL);
   free_ctrl_buffer((WAV_Player*)handle->data); 
   free_ctrl_buffer(handle);
   return MEDIA_SUCCESS;
}         

Media_Status JWav_Load(Media_Handle *handle, uint32 *requiredBufSize) 
{
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   
   if(handle->state != JWAV_STATE_OPENED)
      return MEDIA_FAIL;      
      
   if((player->Wav_Param.wavefile == NULL) || (player->Wav_Param.filesize == 0)) 
      return MEDIA_FAIL;
   
   // wave file process              
   // perform the wav data check    
   *requiredBufSize = 16;
   
   player->data_head = player->Wav_Param.wavefile;
   player->data_len  = player->Wav_Param.filesize;
   
   handle->state = JWAV_STATE_READY;   
   return MEDIA_SUCCESS;             
}

void JWav_SetBuffer(Media_Handle *handle, int16 *buffer, uint32 buf_len)
{
   FSAL_Status eFSALStatus;
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data);
   player->pstFSAL = (STFSAL*)get_ctrl_buffer( sizeof(STFSAL) );
   ASSERT(player->pstFSAL!=NULL);
   
   FSAL_Direct_SetRamFileSize(player->pstFSAL, player->data_len);
   eFSALStatus = FSAL_Open(player->pstFSAL, (void*)player->data_head, FSAL_ROMFILE);
   ASSERT(eFSALStatus == FSAL_OK);

   player->ihdl = WAV_OpenRender(&JWav_MsgHandler, player->pstFSAL, 0);
   ihdl = player->ihdl;
   ihdl->private_data = handle;
}
     
Media_Status  JWav_Play( Media_Handle *handle )
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data);
   handle->repeat_count = player->Wav_Param.repeats;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_PLAY, 4, handle, 0, handle->repeat_count);
   ihdl = player->ihdl;
   return ihdl->Play(player->ihdl);
}
  
Media_Status  JWav_Stop( Media_Handle *handle )
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data);
   ihdl = player->ihdl;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_STOP, 4, handle, 0);
   return ihdl->Stop(player->ihdl);
}

Media_Status JWav_Pause( Media_Handle *handle )
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data);
   
   ihdl = player->ihdl;
   kal_brief_trace(TRACE_GROUP_MELODY_LV1, MELODY_API_PAUSE, 4, handle, 0);
   return ihdl->Pause(player->ihdl);
}

Media_Status JWav_Resume( Media_Handle *handle )
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data);
   ihdl = player->ihdl;
   return ihdl->Resume(player->ihdl);
}

Media_Status  JWav_SetStartTime( Media_Handle *handle, kal_int32 msStartTime )
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data);
   if(handle->state == JWAV_STATE_PLAYING)
      return MEDIA_FAIL;

   ihdl = player->ihdl;
   ihdl->start_time = msStartTime;
   return MEDIA_SUCCESS;
}
 
Media_Status  JWav_SetStopTime( Media_Handle *handle, kal_int32 msStopTime )
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data);
   ihdl = player->ihdl;
   ihdl->stop_time = msStopTime;
   return MEDIA_SUCCESS;
}    

kal_int32 JWav_GetCurrentTime( Media_Handle *handle )  
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   ihdl = player->ihdl;
   return ihdl->GetCurrentTime(player->ihdl);
}         

kal_int32 JWav_GetDuration( Media_Handle *handle )
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   ihdl = player->ihdl;
   return handle->repeat_count*ihdl->GetTotalDuration(player->ihdl);
}   

Media_Status  JWav_SetLevel( Media_Handle *handle, uint8 level )
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   ihdl = player->ihdl;
   if(level > 100)
      return MEDIA_FAIL;
   ihdl->SetLevel( player->ihdl, level );
   return MEDIA_SUCCESS;
}     
     
kal_uint8 JWav_GetLevel( Media_Handle *handle )
{
   MHdl *ihdl;
   WAV_Player *player = (WAV_Player *)(handle->data) ;
   ihdl = player->ihdl;
   return ihdl->GetLevel(player->ihdl);
}

#endif // #if defined(WAV_CODEC)

#else                                                                        
char dummy_jwav_c;    /* define a dummy variable to avoid warning message */
#endif


