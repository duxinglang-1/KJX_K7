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
 *   jma_audio_player.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines native JMA audio player APIs
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
 *============================================================================
 ****************************************************************************/
/**
 * @(#)jma_audio_player.c  1.00 05/11/30
 *
 * Copyright (c) 2003 Institute for Information Industry.  All rights reserved.
 */

/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "MMI_features.h"

#include "jma_interface.h"
#include "jam_internal.h"
#include "jam_msg_handler.h"
#include "jma_internal.h"
#include "jvm_internal.h"

#include "j2me_trace.h"

/* local includes */
#include "aud_defs.h"
#include "med_api.h"

#include "Unicodexdcl.h"
#include "aud_id3_parser.h"
#include "drm_def.h"

#include "FileMgrGProt.h"

#include "j2me_custom_option.h"
#include "meta_tag_api.h"
#include "app_str.h"
/*************************************************************************
 * Global Definition and Declaration
 *************************************************************************/

/* Java layer tone event */
#define SILENCE         (-1)
#define VERSION         (-2)
#define TEMPO           (-3)
#define RESOLUTION      (-4)
#define BLOCK_START     (-5)
#define BLOCK_END       (-6)
#define PLAY_BLOCK      (-7)
#define SET_VOLUME      (-8)
#define TONE_REPEAT     (-9)

/* Native layer constant definiton */
#define MAX_TONESEQ_BLOCK_NUM             (128)

typedef enum
{
    VERSION_ERROR = 6,
    TEMPO_ERROR = 5,
    RESOLUTION_ERROR = 8,
    NOTE_ERROR = 4,
    BLOCK_BEGIN_ERROR = 7,
    BLOCK_NESTED_ERROR = 3,
    BLOCK_END_ERROR = 1,
    REPEAT_TIME_ERROR = 9,
    REPEAT_SILENCE_ERROR = 11,
    VOLUME_ERROR = 10,
    PLAY_BLOCK_ERROR = 2,
    SEMANTIC_ERROR = 12,
    MEMORY_NOTAVAILABLE_ERROR = 13,
    TONESEQ_STACK_OVERFLOW = 14
} java_error_enum;

static kal_int32 single_tone_player_id = INVALID_JPLAYER_ID - 1; 
module_type jma_mimic_module_id = MOD_NIL; 
#define JMA_MOD_ID ((jma_mimic_module_id == MOD_NIL)?kal_get_active_module_id(): jma_mimic_module_id)

typedef struct mma_toneseq_block_info_struct_t
{
    kal_int32 block_len;
    kal_int32 block_seq_offset;
} mma_toneseq_block_info_struct;

/* Block information array */
mma_toneseq_block_info_struct toneseq_block_info[MAX_TONESEQ_BLOCK_NUM];

/* Block operation stack */
kal_int32 mma_toneseq_block_stack[MAX_TONESEQ_BLOCK_NUM];
kal_int32 mma_toneseq_block_stack_index = 0;
kal_uint32 g_aud_id = 0;
#ifdef __JMA_PREEMPT_PLAYER__
mma_player_list preemption_players = {NULL, 0};
#endif

audio_player_struct mma_audio_player[JAVA_NO_OF_PLAYER];

kal_char ext_name[MMA_NO_OF_AUDIO_TYPE][5] = {"mid", "", "wav", "imy", "amr", "mp3", "mp2", "aac", "au", "awb", "wma", "m4a", "aiff"};


/*************************************************************************
 * Function Declaration
 *************************************************************************/
#ifdef __RICH_AUDIO_PROFILE__
extern kal_bool daf_seek(audio_input_stream_struct *input_stream, kal_uint32 *offset);
#endif
typedef kal_int32(*mma_player_key) (mma_player_node *node, kal_int32 key1, kal_int32 key2);
typedef void (*mma_player_insert) (mma_player_list *player_list, mma_player_node *node);

static kal_bool jma_audio_player_parse_data(kal_int32 mma_type, kal_char *aud_ptr, kal_int32 count, mma_player_struct *player);
#ifdef __JMA_PREEMPT_PLAYER__
static audio_player_struct *jma_audio_locate_handle(kal_int32 handle);
#endif

static void jma_audio_player_get_concurrent_count(kal_uint32 *count);
static void jma_audio_player_reset(audio_player_struct *audio_player);

#ifdef __JMA_PREEMPT_PLAYER__
/* =====================================  mvm  =========================================*/
static kal_int8 jma_mvm_audio_player_get_preemption_type(kal_int32 vm_id, kal_int32 mma_type, kal_char *filename);
static void jma_mvm_audio_player_locate_resource(kal_int32 mma_type, kal_int32 *native_player);
static audio_player_struct *jma_mvm_audio_locate_player(kal_int32 vm_id, kal_int32 java_player);
static kal_int32 jma_mvm_audio_pick_replace_player_candidate(kal_int32 vm_id, kal_int32 mma_type);
static kal_bool jma_mvm_audio_player_preempt_multiple_players(void);
static kal_bool jma_mvm_audio_player_preempt_player(audio_player_struct *preempted_player);
static kal_int8 jma_mvm_audio_player_get_resume_type(kal_int32 mma_type, kal_bool is_single_over);
static kal_bool jma_mvm_audio_player_resume_preempted_player(audio_player_struct *audio_player);
static kal_bool jma_mvm_audio_player_resume_multiple_players(kal_int32 vm_id, kal_int32 jplayer);
static void jma_mvm_audio_player_remove_preempted_node(kal_int32 vm_id, kal_int32 java_player);
/* =====================================================================================*/
#endif
/*****************************************************************************
 * FUNCTION
 *  jma_audio_jplayer_to_nplayer
 * DESCRIPTION
 *  This function is translation from java player id to native player id
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        (JL)
 * RETURNS
 *  int - native_player (AL)
 *****************************************************************************/
static kal_int32 jma_audio_jplayer_to_nplayer(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 native_player = INVALID_NPLAYER_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JAVA_NO_OF_PLAYER; i++)
    {
        if (mma_audio_player[i].vm_id == vm_id &&
            mma_audio_player[i].id == java_player)
        {
            native_player = i;
            break;
        }
    }

    return native_player;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_handle_to_player
 * DESCRIPTION
 *  This function is translation from handle to native player id and mma_type
 * PARAMETERS
 *  handle              [IN]        
 *  mma_type            [OUT] 
 *  native_player       [OUT]  
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 jma_audio_handle_to_nplayer(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 native_player = INVALID_NPLAYER_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JAVA_NO_OF_PLAYER; i++)
    {
        if (mma_audio_player[i].handle == handle)
        {
            native_player = i;
            break;
        }
    }

    return native_player;

}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_message_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?] 
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_player_message_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_event_callback_struct *p = (mma_event_callback_struct*) ilm_ptr->local_para_ptr;
    kal_int32 native_player = INVALID_JPLAYER_ID;
    kal_int32 vm_id = INVALID_JVM_ID;
    audio_player_struct *audio_player = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    native_player = jma_audio_handle_to_nplayer(p->handle);
    if (INVALID_JPLAYER_ID != native_player)
    {
        audio_player = &mma_audio_player[native_player];
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_audio_locate_handle(p->handle);
    }
    #endif

    if (!audio_player)
    {
        return;
    }
    
    vm_id = audio_player->vm_id;
    
    /* check dependency mutex first */
    do
    {
        if (jma_mutex_lock_no_wait(KAL_FALSE))
        {
            break;
        }
        kal_sleep_task(2);
    } while (1);

    if (jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_TRUE))
    {
        kal_bool in_bg_call = KAL_FALSE;

   // #ifdef __MMI_BACKGROUND_CALL__    
        if (jma_media_player_is_in_background_call()) 
        {
            in_bg_call = KAL_TRUE;
        }
   // #endif /* __MMI_BACKGROUND_CALL__ */
    
        if (!in_bg_call)
        {
            jma_audio_event_callback_handler(vm_id,
                p->handle, p->event, p->aud_id, p->seq_id);
        }
        jma_media_player_cs_leave();
    }

    /* Remember to unlock the additional lock. */
    jma_media_player_dependency_mutex_unlock();
}

/*****************************************************************************
 * FUNCTION
 *  jma_audio_eom_handler
 * DESCRIPTION
 *  This function handles eom situation.
 * PARAMETERS
 *  mma_type        [IN]        
 *  player          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_audio_eom_handler(kal_int32 mma_type, audio_player_struct *player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = player->vm_id;
    java_mma_type_enum evt_type;
    kal_int32 ms;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_EOM_HANDLER, mma_type, player->handle, player->stoptime);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, player->vm_id, player->id);
    
    if (JAVA_MEDIA_STATE_PLAYING == player->state)
    {
        /* Keep current time when player stopped */
        player->current_time = media_mma_aud_get_current_time(JMA_MOD_ID, player->handle, (kal_uint8) mma_type);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, player->current_time);
    }

    /* check if MediaEnd is triggered by stopTime */
    if ((player->stoptime >= 0) && (player->stoptime <= player->current_time)) 
    {
        ms = media_mma_aud_set_stop_time(JMA_MOD_ID, player->handle, (kal_uint8) mma_type, 0x7fffffff);
        ms = media_mma_aud_set_start_time(JMA_MOD_ID, player->handle, (kal_uint8) mma_type, (kal_int32) player->current_time);
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, player->state, JAVA_MEDIA_STATE_STOPPED_PAUSED);
        player->state = JAVA_MEDIA_STATE_STOPPED_PAUSED;
        /* clear stop time */
        player->stoptime = -1;
        evt_type = MMA_EVENT_STOPPED_AT_TIME;
    }
    else
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, player->state, JAVA_MEDIA_STATE_READY);
        player->state = JAVA_MEDIA_STATE_READY;
        evt_type = MMA_EVENT_END_OF_MEDIA;
        ms = media_mma_aud_set_start_time(JMA_MOD_ID, player->handle, (kal_uint8) mma_type, (kal_int32) 0);
		if(1 == ms)
		{
			kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 666);
		}
    }
#ifdef __DRM_SUPPORT__    
    /* stop consume drm right */
    if (JAVA_DRM_STATE_CONSUMING == player->drm_state)
    {    
        jam_drm_stop_consume(player->drm_id);
        player->drm_state = JAVA_DRM_STATE_NULL;
        player->drm_id = -1;
    }
#endif

    if (MMA_EVENT_END_OF_MEDIA == evt_type)
    {
        player->play_finish_time = player->current_time;
        /* If java is suspended when MediaEnd, set current time as 0 to
           ensure to set correct start time when Java is resumed. */
        player->current_time = 0;
        
        /* is_single_over = (JAVA_MEDIA_SINGLE_DEVICE == player->device_type) ? KAL_TRUE : KAL_FALSE;
        jma_mvm_audio_player_preempt_player(player);
        jma_mvm_audio_player_resume_preempted_players(vm_id, jplayer, mma_type, is_single_over); */
        
        /* Post event after handing every thing */
        jvm_post_mma_event(evt_type, player->id, (kal_int64) player->play_finish_time);
    }
    else
    {
        /* Post event after handing every thing */
        jvm_post_mma_event(evt_type, player->id, (kal_int64) player->current_time);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_event_callback_handler
 * DESCRIPTION
 *  This function is call back function of event handler, to make sure the handling are
 *  executed under J2me context.
 * PARAMETERS
 *  mma_type        [IN]        
 *  h               [?]         
 *  e               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_event_callback_handler(kal_int32 vm_id, kal_int32 handle, kal_int32 event, kal_int32 aud_id, kal_int32 seq_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 mma_type;
    audio_player_struct *audio_player = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_CALLBACK_HANDLER, vm_id, handle, event, aud_id, seq_id);

    JMA_AUDIO_CS_ENTER(vm_id, JMA_VOID);

    EXT_ASSERT(handle != NULL, 0, 0, 0);
    native_player = jma_audio_handle_to_nplayer(handle);

    if (native_player != INVALID_NPLAYER_ID)
    {
        audio_player = &mma_audio_player[native_player]; 
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        mma_type = audio_player->player.media_type;
        /* Ignore the out-of-date message */
        if (audio_player->aud_id != aud_id ||
            audio_player->sequence_id != seq_id)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, 
                audio_player->aud_id, audio_player->sequence_id);
            JMA_CS_LEAVE(JMA_VOID);
        }

        if(event == MED_RES_END_OF_FILE) /* 5 */
        {
            if (audio_player->device_type == JAVA_MEDIA_TONE_DEVICE)
            {                
                media_mma_aud_close(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
                jma_deregister_device(JAVA_MEDIA_TONE_DEVICE, audio_player->vm_id, audio_player->id);                
                audio_player->state = JAVA_MEDIA_STATE_NULL;
                audio_player->vm_id = INVALID_JVM_ID;
                audio_player->id = INVALID_JPLAYER_ID;
                audio_player->handle = NULL;
                audio_player->device_type = JAVA_MEDIA_INVALID_DEVICE;
                audio_player->stoptime = -1;

                /* Clear Callback function */
                jma_audio_player_clear_callback(vm_id);
                
                JMA_CS_LEAVE(JMA_VOID);
            }

            jma_audio_eom_handler(mma_type, audio_player);
            JMA_CS_LEAVE(JMA_VOID);
        }
        else if (event == MED_RES_BUFFER_INSUFFICIENT) /* 17 */
        {
            EXT_ASSERT(audio_player->player.progressive_dl == KAL_TRUE, 0, 0, 0);

            /* MED may send EOM message when java player is at PAUSED state */
            if (audio_player->state == JAVA_MEDIA_STATE_PAUSED)
            {
                audio_player->state = JAVA_MEDIA_STATE_STOPPED_PAUSED;
                JMA_CS_LEAVE();
            }

            /* change as buffering state directly */
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_BUFFERING);
            audio_player->state = JAVA_MEDIA_STATE_BUFFERING;
            jma_audio_player_cache_buffering_cyclic();
            JMA_CS_LEAVE();
        }
        else if (event == MED_RES_AUD_DUR_UPDATED)
        {
            JMA_CS_LEAVE(JMA_VOID);
        }
        else  /* error case: MED_RES_ERROR: 9 or other */
        {
            media_mma_aud_stop(JMA_MOD_ID, handle, (kal_uint8) mma_type);
            audio_player->sequence_id ++;
                
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_READY);
            audio_player->state = JAVA_MEDIA_STATE_READY;
            
        #ifdef __DRM_SUPPORT__    
            /* stop consume drm right */
            if (audio_player->drm_state == JAVA_DRM_STATE_CONSUMING)
            {    
                jam_drm_stop_consume(audio_player->drm_id);
                audio_player->drm_state = JAVA_DRM_STATE_NULL;
                audio_player->drm_id = -1;
            }
        #endif

            jvm_post_mma_event(MMA_EVENT_ERROR, audio_player->id, MMA_ERR_AUDIO_ERROR);
            
            JMA_CS_LEAVE(JMA_VOID);           
        }
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_audio_locate_handle(handle);
        if (NULL == audio_player)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(JMA_VOID);
        }
        
        /* Ignore the out-of-date message */
        if (audio_player->aud_id != aud_id || audio_player->sequence_id != seq_id)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, audio_player->aud_id, audio_player->sequence_id);
            JMA_CS_LEAVE(JMA_VOID);
        }

        if(event == MED_RES_END_OF_FILE) /* 5 */
        {
            audio_player->is_eom = KAL_TRUE;
        }
        else if (event == MED_RES_AUD_DUR_UPDATED)
        {
            JMA_CS_LEAVE(JMA_VOID);
        }
        else /* error case: MED_RES_ERROR: 9 or other */
        {
            audio_player->state = JAVA_MEDIA_STATE_READY;
        }
    }
    #endif
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  audio_handle_key
 * DESCRIPTION
 *  This function is for preempted player.
 * PARAMETERS
 *  player      [?]         
 *  handle      [IN]    
 *  fake_param  [IN]: not used
 * RETURNS
 *  kal_int32 return_value
 *****************************************************************************/
static kal_int32 audio_handle_key(mma_player_node *player, kal_int32 handle, kal_int32 fake_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle && ((audio_player_struct*) player)->handle == handle)
    {
        return (0);
    }
    else
    {
        return (-1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  midi_jplayer_key
 * DESCRIPTION
 *  This function is for midi.
 * PARAMETERS
 *  player      [?]         
 *  jplayer     [IN]        
 * RETURNS
 *  kal_int32 return_value
 *****************************************************************************/
static kal_int32 audio_jplayer_double_key(mma_player_node *player, kal_int32 vm_id, kal_int32 jplayer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((audio_player_struct*) player)->vm_id == vm_id &&
        ((audio_player_struct*) player)->id == jplayer)
    {
        return (0);
    }
    else
    {
        return (-1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  midi_jplayer_key
 * DESCRIPTION
 *  This function is for midi.
 * PARAMETERS
 *  player      [?]         
 *  jplayer     [IN]        
 * RETURNS
 *  kal_int32 return_value
 *****************************************************************************/
static kal_int32 audio_jplayer_key(mma_player_node *player, kal_int32 vm_id, kal_int32 fake_java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((audio_player_struct*) player)->vm_id == vm_id)
    {
        return (0);
    }
    else
    {
        return (-1);
    }
}

#ifdef __JMA_PREEMPT_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  audio_player_inserthead_func
 * DESCRIPTION
 *  This function is for preempted players.
 * PARAMETERS
 *  player_list     [?]     
 *  node            [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void audio_player_inserthead_func(mma_player_list *player_list, mma_player_node *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_player_node *cur_node = player_list->head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Already on list */
    if (node->flag_on_list)
    {
        return;
    }

    node->next = node->prev = NULL;
    node->flag_on_list = KAL_TRUE;

    if (cur_node == NULL)
    {
        /* empty list case */
        player_list->head = node;
        player_list->player_count++;
        return;
    }

    node->next = cur_node;
    cur_node->prev = node;
    player_list->head = node;
    player_list->player_count++;
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_player_insert
 * DESCRIPTION
 *  This function is for midi.
 * PARAMETERS
 *  player_list     [?]         
 *  node            [?]         
 *  insert_func     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* In future, it should be moved to mmalib.c to support other media type */
static void dynamic_player_insert(mma_player_list *player_list, mma_player_node *node, mma_player_insert insert_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DYNPLAYER_CS_ENTER();
    (*insert_func) (player_list, node);
    DYNPLAYER_CS_LEAVE();
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_player_delete
 * DESCRIPTION
 *  This function is for midi.
 * PARAMETERS
 *  player_list     [?]     
 *  node            [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_player_delete(mma_player_list *player_list, mma_player_node *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DYNPLAYER_CS_ENTER();
    /* Node not on list */
    if (node->flag_on_list == KAL_FALSE)
    {
        DYNPLAYER_CS_LEAVE();
        return;
    }
    if (player_list->head == node)
    {
        player_list->head = node->next;
    }

    if (node->prev)
    {
        node->prev->next = node->next;
    }

    if (node->next)
    {
        node->next->prev = node->prev;
    }

    node->next = node->prev = NULL;

    player_list->player_count--;
    node->flag_on_list = KAL_FALSE;
    
    DYNPLAYER_CS_LEAVE();
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_player_search
 * DESCRIPTION
 *  This function is for midi.
 * PARAMETERS
 *  player_list     [?]         
 *  key_func        [IN]        
 *  key             [IN]        
 *  mma_player_key ley_func(?)
 * RETURNS
 *  mma_player_node*  player_node
 *****************************************************************************/
static mma_player_node *dynamic_player_search(mma_player_list *player_list, mma_player_key key_func, kal_int32 key1, kal_int32 key2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_player_node *cur_node = player_list->head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DYNPLAYER_CS_ENTER();
    while (cur_node)
    {
        /* 0 means eqaul */
        if ((*key_func) (cur_node, key1, key2) == 0)
        {
            break;
        }
        cur_node = cur_node->next;
    }

    DYNPLAYER_CS_LEAVE();
    return cur_node;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jma_midi_player_init
 * DESCRIPTION
 *  This function is to initialize player information
 * PARAMETERS
 *  player      [?]     
 *  Media_Handle *handle (AL)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_midi_player_init(audio_player_struct *player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    player->next_node.next = player->next_node.prev = NULL;
    player->next_node.flag_on_list = KAL_FALSE;
    player->state = JAVA_MEDIA_STATE_NULL;
    player->vm_id = INVALID_JVM_ID;
    player->id = INVALID_JPLAYER_ID;
    player->handle = NULL;
    player->is_midi_device = KAL_FALSE;    /* Default is not midi device */
    player->is_eom = KAL_FALSE;
    player->duration = 0;
    player->current_time = 0;
    player->pitch = 0;  /* Default value */
    player->channel = 0; 
    player->program = 0; 
    player->bank = 0; 
    player->stoptime = -1;
    player->is_setpitch = KAL_FALSE;
    player->volume = DEFAULT_AUDIO_VOLUME;
    player->rate = 100000;  /* Default value */
    player->is_setrate = KAL_FALSE;
    player->is_setprogram = KAL_FALSE;
    player->tempo = 120000;  /* No Default value: defined in midi file */
    player->is_settempo = KAL_FALSE;
    player->aud_id = 0;
    player->sequence_id = 0;
    player->drm_state = JAVA_DRM_STATE_NULL;
    player->drm_id = -1;
    player->channel_volume_sets = 0;
    memset((kal_uint8 *)&(player->player), 0, sizeof(mma_player_struct));
    memset((kal_uint8 *)&(player->channel_volume), 0, MAX_MIDI_CHANNEL * sizeof(kal_uint8));
}

#ifdef __JMA_PREEMPT_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  jma_audio_locate_handle
 * DESCRIPTION
 *  This function is to position a player in linked list by media handle.
 * PARAMETERS
 *  handle          [?]     (AL)
 *  java_player     [?]     
 * RETURNS
 *  audio_player_struct* null_audio_player if not found else the ponter to the audio_player
 *****************************************************************************/
static audio_player_struct *jma_audio_locate_handle(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fake_param = -1;
    
    audio_player_struct *player =
        (audio_player_struct*) dynamic_player_search(&preemption_players, audio_handle_key, (kal_int32) handle, fake_param);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return player;
}


/*****************************************************************************
 * FUNCTION
 *  jma_midi_locate_player
 * DESCRIPTION
 *  This function is to position a player in linked list by java_player.
 * PARAMETERS
 *  java_player     [IN]        (JL)
 * RETURNS
 *  audio_player_struct* null_preempted_player if not found else the ponter to the preemption_players
 *****************************************************************************/
static audio_player_struct *jma_mvm_audio_locate_player(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (INVALID_JAVA_PLAYER == java_player)
    {
        return (audio_player_struct*) dynamic_player_search(&preemption_players, audio_jplayer_key, vm_id, java_player);
    }
    else 
    {
        return (audio_player_struct*) dynamic_player_search(&preemption_players, audio_jplayer_double_key, vm_id, java_player);
    }
}
#endif


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  jma_audio_handle_to_player
 * DESCRIPTION
 *  This function is translation from handle to native player id and mma_type
 * PARAMETERS
 *  handle              [IN]        
 *  mma_type            [OUT] 
 *  native_player       [OUT]  
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 jma_audio_drm_id_to_nplayer(kal_int32 drm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 native_player = INVALID_NPLAYER_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JAVA_NO_OF_PLAYER; i++)
    {
        if (mma_audio_player[i].drm_id == drm_id)
        {
            native_player = i;
            break;
        }
    }
    
    return native_player;
}


/*****************************************************************************
 * FUNCTION
 *  audio_drm_key
 * DESCRIPTION
 *  This function is for preempted player.
 * PARAMETERS
 *  player      [?]         
 *  handle      [IN]    
 *  fake_param  [IN]: not used
 * RETURNS
 *  kal_int32 return_value
 *****************************************************************************/
static kal_int32 audio_drm_key(mma_player_node *player, kal_int32 drm_id, kal_int32 fake_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((audio_player_struct*) player)->drm_id == drm_id)
    {
        return (0);
    }
    else
    {
        return (-1);
    }
}

#ifdef __JMA_PREEMPT_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  jma_audio_locate_drm_id
 * DESCRIPTION
 *  This function is to position a player in linked list by drm_id.
 * PARAMETERS
 *  drm_id          [IN]     (AL)
 * RETURNS
 *  audio_player_struct* null_audio_player if not found else the ponter to the audio_player
 *****************************************************************************/
static audio_player_struct *jma_audio_locate_drm_id(kal_int32 drm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fake_param = -1;
    
    audio_player_struct *player =
        (audio_player_struct*) dynamic_player_search(&preemption_players, audio_drm_key, drm_id, fake_param);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return player;
}
#endif /*__JMA_PREEMPT_PLAYER__*/
#endif

#ifdef __JMA_PREEMPT_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_insert_preemption_list
 * DESCRIPTION
 *  This function is used to insert a preempted player to head of preemption list
 * PARAMETERS
 *  inserted_player     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_audio_player_insert_preemption_list(audio_player_struct *inserted_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_player_insert(&preemption_players, (mma_player_node*) inserted_player, audio_player_inserthead_func);
    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jma_audio_free_player_data
 * DESCRIPTION
 *  Finalize
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_audio_free_player_data(audio_player_struct *audio_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_FREE_PLAYER_DATA, audio_player->player.file_path, audio_player->player.data);
    if (audio_player->player.file_path != NULL)
    {
        jvm_free(audio_player->player.file_path);
        audio_player->player.file_path = NULL;
    }

    if (audio_player->player.data != NULL)
    {
        jvm_free(audio_player->player.data);
        audio_player->player.data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_midi_init_device_resource
 * DESCRIPTION
 *  This function is used to init midi device with midi control info
 * PARAMETERS
 *  midi_player     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_midi_init_device_resource(audio_player_struct *midi_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ms = 1;
    kal_int32 mma_type = MMA_TYPE_MIDI;
    #if defined(SUPPORT_MMAPI) || defined(JSR135_AUDIO_ADVANCED_FEATURE)
    kal_int32 channel;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MIDI_INIT_DEVICE_RESOURCE);
    
#if defined(SUPPORT_MMAPI) || defined(JSR135_AUDIO_ADVANCED_FEATURE)

    /* set again if the player has ever set it.
       because when play finish or pause, midi_player is closed,
       Original pitch, rate, tempo are also cleared */
    /* Don't clear the flag */
    if (midi_player->is_setpitch == KAL_TRUE)
    {
        ms = media_mma_aud_set_pitch(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, midi_player->pitch);
    }

    if (midi_player->is_setrate == KAL_TRUE)
    {
        ms = media_mma_aud_set_rate(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, midi_player->rate);
    }

    if (midi_player->is_settempo == KAL_TRUE)
    {
        ms = media_mma_aud_set_tempo(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, midi_player->tempo);
    }
    if (midi_player->is_setprogram == KAL_TRUE)
    {
        ms = media_mma_aud_set_program(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, 
                                        (kal_uint8) midi_player->channel, (kal_uint8) midi_player->bank, (kal_uint8) midi_player->program);
    }

    if (midi_player->channel_volume_sets != 0)
    {
        for (channel = 0; channel < MAX_MIDI_CHANNEL; channel++)
        {
            if (midi_player->channel_volume_sets & (kal_uint16)(1<<channel))
            {
                media_mma_aud_set_channel_volume(
                    JMA_MOD_ID, 
                    midi_player->handle, 
                    (kal_uint8) mma_type, 
                    (kal_uint8)channel, 
                    (kal_uint8)midi_player->channel_volume[channel]);
            }
        }
    }
        
#endif /* SUPPORT_MMAPI */ 

    if (!midi_player->is_midi_device)
    {
        /* Don't clear the flag */
        if (midi_player->stoptime != -1)
        {
            ms = media_mma_aud_set_stop_time(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, midi_player->stoptime);
        }
        
        ms = media_mma_aud_set_start_time(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, midi_player->current_time);
    }
    
    ms = media_mma_aud_set_volume(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, midi_player->volume);
	if(1 == ms)
	{
		kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 666);
	}
}


/*****************************************************************************
 * FUNCTION
 *  jma_midi_init_device_resource
 * DESCRIPTION
 *  This function is used to init midi device with midi control info
 * PARAMETERS
 *  midi_player     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_audio_init_device_resource(audio_player_struct *audio_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mma_type = audio_player->player.media_type;
    kal_int32 result = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_INIT_DEVICE_RESOURCE);

    if (mma_type == MMA_TYPE_TONE)
    {
        media_mma_aud_set_data(
            JMA_MOD_ID, 
            (kal_int32) audio_player->handle,
            (kal_uint8) mma_type,
            &audio_player->player);
           
        if (audio_player->is_setpitch)
        {
            media_mma_aud_set_pitch(
                JMA_MOD_ID, 
                audio_player->handle, 
                (kal_uint8) mma_type, 
                audio_player->pitch);
        }
    }

    /* set play speed again to resume to the correct rate */
    if (audio_player->play_speed != MDI_AUDIO_SPEED_NORMAL)
    {
        /* midi file, tone sequence */
        if (mma_type == MMA_TYPE_TONE)
        {
            media_mma_aud_set_rate(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type, audio_player->play_speed * 1000);
        }
    #if defined(__BES_TS_SUPPORT__)
        else 
        {
            media_stretch_set_speed(JMA_MOD_ID, audio_player->play_speed);
        }
    #endif
    }

    /* init some parameters */
    result = media_mma_aud_set_volume(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type, audio_player->volume);
    result = media_mma_aud_set_start_time(JMA_MOD_ID, 
                audio_player->handle,
                (kal_uint8) mma_type,
                audio_player->current_time);
	if(MED_RES_FAIL == result)
	{
	    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 225);
	}
    
    if (audio_player->stoptime != -1)
    {
        result = media_mma_aud_set_stop_time(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type, (kal_int32) audio_player->stoptime);
		if(MED_RES_FAIL == result)
	    {
	        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 226);
	    }
    }
        
}

#ifdef __JMA_PREEMPT_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  jma_mvm_audio_player_copy_info
 * DESCRIPTION
 *  This is used to copy the player data from src to dest player
 * PARAMETERS
 *  src_player      [IN]     
 *  dest_player     [OUT]
 * RETURNS
 *  kal_true or kal_false
 *****************************************************************************/
static kal_bool jma_mvm_audio_player_copy_info(audio_player_struct *src_player, audio_player_struct* dest_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char * aud_ptr = NULL;
    kal_int32 count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    jma_audio_player_reset(dest_player);
    memcpy((void *) dest_player, (const void *) src_player, sizeof(audio_player_struct) - sizeof(mma_player_struct));
    
    if (src_player->player.file_path != NULL)
    {
        /* Copy FileName from KNI Layer */
        aud_ptr = jvm_malloc(MAX_MEDIA_FILE_NAME * 2);
        if (NULL == aud_ptr)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            return KAL_FALSE;
        }
        mmi_ucs2cpy((CHAR *)aud_ptr, (const CHAR *)src_player->player.file_path);                
        dest_player->player.file_path = (kal_wchar *) aud_ptr;
    }
    else if (src_player->player.data != NULL)
    {
        count = src_player->player.size;
        /* Copy Data from KNI Layer */
        aud_ptr = jvm_malloc(count);
        if (aud_ptr == NULL)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            return KAL_FALSE;
        }
        memcpy(aud_ptr, src_player->player.data, count); 
        dest_player->player.data = (kal_uint8*) aud_ptr;
        dest_player->player.size = count;
    }

    dest_player->player.repeats = src_player->player.repeats;
    dest_player->player.handler = src_player->player.handler;
    dest_player->player.media_type = src_player->player.media_type;  
    dest_player->player.progressive_dl = src_player->player.progressive_dl;

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jma_mvm_audio_preempted_player_finalize
 * DESCRIPTION
 *  Finalize
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_mvm_audio_preempted_player_finalize(audio_player_struct *audio_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = audio_player->vm_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PREEMPTED_PLAYER_FINALIZE, audio_player->vm_id, audio_player->id);
    
    jma_audio_free_player_data(audio_player);
    
    dynamic_player_delete(&preemption_players, (mma_player_node*) audio_player);
    /* deallocate the memory occupied by this player */
    jvm_free(audio_player); 
    audio_player = NULL;
    
    jma_audio_player_clear_callback(vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_remove_preempted_nodes
 * DESCRIPTION
 *  remove the nodes belongs to the vm_id in the preemption list due to vm terminated
 * PARAMETERS
 *  vm_id           [IN]
 * RETURNS
 *  
 *****************************************************************************/
void jma_mvm_audio_player_remove_preempted_nodes(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 count = 0;
    audio_player_struct *audio_player;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_REMOVE_PREEMPTED_NODES, vm_id);
    JMA_AUDIO_CS_ENTER(vm_id, JMA_VOID);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, 11111, preemption_players.player_count);
    while (count <= preemption_players.player_count)
    {
        audio_player = NULL;
        audio_player = jma_mvm_audio_locate_player(vm_id, INVALID_JAVA_PLAYER);
        if (audio_player != NULL)
        {
            jma_mvm_audio_preempted_player_finalize(audio_player);
        }
        count++;
    } 

    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_remove_preempted_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id           [IN]
 * RETURNS
 *  
 *****************************************************************************/
static void jma_mvm_audio_player_remove_preempted_node(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audio_player_struct *audio_player;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_REMOVE_PREEMPTED_NODE, vm_id, java_player);
    JMA_AUDIO_CS_ENTER(vm_id, JMA_VOID);
    
    audio_player = jma_mvm_audio_locate_player(vm_id, java_player);

    if (audio_player != NULL)
    {
        jma_mvm_audio_preempted_player_finalize(audio_player);
    }
    
    JMA_CS_LEAVE(JMA_VOID);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_state
 * DESCRIPTION
 *  This api is used to judge whehter there is player belongs to vm_id active or not 
 * PARAMETERS
 *  vm_id           [IN]
 * RETURNS
 *  JMA_AUDIO_ACTIVE:           vm_id's player is actived
 *  JMA_AUDIO_NON_ACTIVE:       non of vm_id's player actived
 *  JMA_AUDIO_ALL_NON_ACTIVE:   non of java audio player actived
 *****************************************************************************/
jma_audio_state jma_mvm_audio_player_state(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_all_empty = KAL_TRUE;
    kal_int32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_STATE, vm_id);
    
    for (i = 0; i < JAVA_NO_OF_PLAYER; i++)
    {
        if (mma_audio_player[i].id != INVALID_JPLAYER_ID)
        {
            is_all_empty = KAL_FALSE;
            if (mma_audio_player[i].vm_id == vm_id)
            {
                return JMA_AUDIO_ACTIVE;
            }
        }
    }
    if (is_all_empty)
    {
        return JMA_AUDIO_ALL_NON_ACTIVE;
    }
    else 
    {
        return JMA_AUDIO_NON_ACTIVE;
    }

}

#ifdef __JMA_PREEMPT_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  jma_audio_pick_replace_player_candidate
 * DESCRIPTION
 *  This api is used to pick the player to be preempted
 * PARAMETERS
 *  vm_id           [IN]
 *  mma_type        [IN]
 * RETURNS
 *  native_player
 *****************************************************************************/
static kal_int32 jma_mvm_audio_pick_replace_player_candidate(kal_int32 vm_id, kal_int32 mma_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 start = -1;
    kal_int32 end = -1;
    kal_int32 i = 0;
    //kal_int32 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PICK_REPLACE_PLAYER_CANDIDATE, vm_id, mma_type);
    
    if (MMA_TYPE_IMY == mma_type)
    {
        start = end = JAVA_AUDIO_IMY;
    }
    else if (MMA_TYPE_TONE == mma_type)
    {
        start = JAVA_AUDIO_TONE_1;
        end = JAVA_AUDIO_TONE_3;
    }
    else if (MMA_TYPE_WAV == mma_type)
    {
        start = JAVA_AUDIO_WAV_1;
        end = JAVA_AUDIO_WAV_4;
    }
    else if (MMA_TYPE_MIDI == mma_type)
    {
        start = JAVA_AUDIO_MIDI_1;
        end = JAVA_AUDIO_MIDI_4;
    }

    for (i = start; i <= end; i++)
    {
        /* Find not used resource one
         * or find other vm's player which is not at playing state
         * otherwise, find other vm's player
         */
        if (INVALID_NPLAYER_ID == mma_audio_player[i].id)
        {
            native_player = i;
            break;
        }
        else if (mma_audio_player[i].vm_id != vm_id &&
                 JAVA_MEDIA_STATE_PLAYING != mma_audio_player[i].state)
        {
            native_player = i;
        }
        /*else if (mma_audio_player[i].vm_id == vm_id &&
                 JAVA_MEDIA_STATE_PLAYING != mma_audio_player[i].state)
        {
            if (INVALID_NPLAYER_ID == native_player)
            {
                native_player = i;
            }
            else if(mma_audio_player[native_player].vm_id == vm_id ||
                 JAVA_MEDIA_STATE_PLAYING == mma_audio_player[native_player].state)
            {
                native_player = i;
            }
        } */
        else if (mma_audio_player[i].vm_id != vm_id &&
                 INVALID_NPLAYER_ID == native_player)
        {
            native_player = i;
        }
        /*else if (mma_audio_player[i].vm_id == vm_id &&
                 INVALID_NPLAYER_ID == native_player)
        {
            native_player = i;
        } */
    }
    
    return native_player;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_locate_resource
 * DESCRIPTION
 *  This api is used to get preemption type if try to play the vm_id's player
 * PARAMETERS
 *  vm_id           [IN]
 *  mma_type        [IN]
 * RETURNS
 *  
 *****************************************************************************/
static kal_int8 jma_mvm_audio_player_get_preemption_type(kal_int32 vm_id, kal_int32 mma_type, kal_char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    jma_audio_preemption_type preemption_type = JMA_AUDIO_PREEMPT_NONE;
    jma_audio_state state = JMA_AUDIO_NON_ACTIVE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_GET_PREEMPTION_TYPE, vm_id, mma_type, filename);
    
    if (mma_audio_player[JAVA_AUDIO_SINGLE].id != INVALID_JPLAYER_ID)
    {
        if (mma_audio_player[JAVA_AUDIO_SINGLE].vm_id != vm_id)
        {
            preemption_type = JMA_AUDIO_PREEMPT_SINGLE_PLAYER;
        }
        else
        {
            preemption_type = JMA_AUDIO_PREEMPT_NOT_RERMITED;
        }
        
        return preemption_type;
    }
    
    if (filename != NULL || jma_audio_player_is_single_player(mma_type))
    {
        state = jma_mvm_audio_player_state(vm_id);
        if ( state == JMA_AUDIO_NON_ACTIVE)
        {
            preemption_type = JMA_AUDIO_PREEMPT_MULTI_PLAYER;
        }
        else if (state == JMA_AUDIO_ACTIVE)
        {
            preemption_type = JMA_AUDIO_PREEMPT_NOT_RERMITED;
        }
        else if (state == JMA_AUDIO_ALL_NON_ACTIVE)
        {
            preemption_type = JMA_AUDIO_PREEMPT_NONE;
        }
    }
    else
    {
        jma_mvm_audio_player_locate_resource(mma_type, &native_player);
        if (native_player == INVALID_NPLAYER_ID)
        {
            preemption_type = JMA_AUDIO_PREEMPT_PLAYER;
        }
        else
        {
            preemption_type = JMA_AUDIO_PREEMPT_NONE;
        }
    }

    return preemption_type;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_preempt_player
 * DESCRIPTION
 *  This is used to suspend the specific player and insert it into preempion list
 * PARAMETERS
 *  native_player           [IN]
 * RETURNS
 *  kal_true or kal_false
 *****************************************************************************/
static kal_bool jma_mvm_audio_player_preempt_player(audio_player_struct *preempted_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audio_player_struct *audio_player = NULL;
    kal_bool ret = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_PREEMPT_PLAYER, preempted_player->vm_id, preempted_player->id);
    
    if (preempted_player->id == INVALID_NPLAYER_ID)
    {
        return KAL_TRUE;
    }
    
    audio_player = jvm_malloc(sizeof(audio_player_struct));
    if (audio_player == NULL)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        return KAL_FALSE;
    }
    
    if (NULL != preempted_player->handle && 
        RESOUCE_NO_ERROR != jma_audio_suspend_hdlr(preempted_player->vm_id, preempted_player->id))
    {
        jvm_free(audio_player);
        audio_player = NULL;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        return KAL_FALSE;
    }
    jma_deregister_device(preempted_player->device_type, preempted_player->vm_id, preempted_player->id);
    jma_audio_player_clear_callback(preempted_player->vm_id);

    if (preempted_player->device_type == JAVA_MEDIA_TONE_DEVICE)
    {
        jvm_free(audio_player);
        audio_player = NULL;
        return KAL_TRUE;
    }
    else 
    {
        ret = jma_mvm_audio_player_copy_info(preempted_player, audio_player);
        if (!ret)
        {
            jvm_free(audio_player);
            audio_player = NULL;
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            return KAL_FALSE;
        }
        
        jma_audio_free_player_data(preempted_player);
        jma_audio_player_reset(preempted_player);
    
        jma_audio_player_insert_preemption_list(audio_player);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_preempt_multiple_players
 * DESCRIPTION
 *  This is used to preempt the non-single players
 * PARAMETERS
 *  native_player           [IN]
 * RETURNS
 *  kal_true or kal_false
 *****************************************************************************/
static kal_bool jma_mvm_audio_player_preempt_multiple_players(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;
    kal_bool ret = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_PREEMPT_MULTIPLE_PLAYERS);
    
    for (i = 0; i < JAVA_AUDIO_SINGLE; i++)
    {
        if (mma_audio_player[i].id != INVALID_NPLAYER_ID)
        {
            ret = jma_mvm_audio_player_preempt_player(&mma_audio_player[i]);
            if (!ret)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                return KAL_FALSE;
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_preempt_players
 * DESCRIPTION
 *  This is used to preempt players according to the preemption type when try to
 *  the vm_id's player.
 * PARAMETERS
 *  vm_id           [IN]
 *  mma_type        [IN]
 *  filename        [IN]
 * RETURNS
 *  kal_true or kal_false
 *****************************************************************************/
kal_bool jma_mvm_audio_player_preempt_players(kal_int32 vm_id, kal_int32 mma_type, kal_char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    jma_audio_preemption_type preemption_type = JMA_AUDIO_PREEMPT_NONE;
    kal_bool ret = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_PREEMPT_PLAYERS, vm_id, mma_type, filename);

    preemption_type = (jma_audio_preemption_type)jma_mvm_audio_player_get_preemption_type(vm_id, mma_type, filename);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, preemption_type);
    if (JMA_AUDIO_PREEMPT_MULTI_PLAYER == preemption_type)
    {
        ret = jma_mvm_audio_player_preempt_multiple_players();
    }
    else if (JMA_AUDIO_PREEMPT_SINGLE_PLAYER == preemption_type)
    {
        ret = jma_mvm_audio_player_preempt_player(&mma_audio_player[JAVA_AUDIO_SINGLE]);
    }
    else if (JMA_AUDIO_PREEMPT_PLAYER == preemption_type)
    {
        native_player = jma_mvm_audio_pick_replace_player_candidate(vm_id, mma_type);
        if (native_player != INVALID_NPLAYER_ID)
        {
            ret = jma_mvm_audio_player_preempt_player(&mma_audio_player[native_player]);
        }
        else
        {
            /* there is an not used resource */
            return KAL_TRUE;
        }
    }
    else if (JMA_AUDIO_PREEMPT_NOT_RERMITED == preemption_type)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        return KAL_FALSE;
    }
    else if (JMA_AUDIO_PREEMPT_NONE == preemption_type)
    {
        return KAL_TRUE;
    }
    
    return ret;
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_is_need_resume
 * DESCRIPTION
 *  This is used to judge when the mma_type player stopped, whether there are 
 *  preempted players need to be resumed
 * PARAMETERS
 *  mma_type    [IN]
 *  file_name   [IN]
 * RETURNS
 *  JMA_AUDIO_RESUME_NONE:          no player needs to be resumed
 *  JMA_AUDIO_RESUME_SINGLE_PLAYER: single player needs to be resumed
 *  JMA_AUDIO_RESUME_MULTI_PLAYER:  non-single players needs to be resumed
 *****************************************************************************/
static kal_int8 jma_mvm_audio_player_get_resume_type(kal_int32 mma_type, kal_bool is_single_over)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audio_player_struct *player = (audio_player_struct*) preemption_players.head;
    jma_audio_resume_type resume_type = JMA_AUDIO_RESUME_NONE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_GET_RESUME_TYPE, mma_type, is_single_over);
    /* Non of preempted player exist */
    if (!player)
    {
        return JMA_AUDIO_RESUME_NONE;
    }
    /* If the current player is single, resume type depends on the first node's device type;
     * Otherwise, it depends on whether there is still exitst multiple player && the first node's device type.
     */
    if (is_single_over)
    {
        if (JAVA_MEDIA_SINGLE_DEVICE == player->device_type)
        {
            resume_type = JMA_AUDIO_RESUME_SINGLE_PLAYER;         
        }
        else 
        {
            resume_type = JMA_AUDIO_RESUME_MULTI_PLAYER;
        }
    }
    else
    {
        if (jma_audio_player_is_active())
        {
            if (JAVA_MEDIA_SINGLE_DEVICE == player->device_type)
            {
                resume_type = JMA_AUDIO_RESUME_NONE;         
            }
            else 
            {
                resume_type = JMA_AUDIO_RESUME_MULTI_PLAYER;
            }
        }
        else
        {
            if (JAVA_MEDIA_SINGLE_DEVICE == player->device_type)
            {
                resume_type = JMA_AUDIO_RESUME_SINGLE_PLAYER;
            }
            else 
            {
                resume_type = JMA_AUDIO_RESUME_MULTI_PLAYER;
            }
        }
    }
    
    return resume_type;
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_preempt_player
 * DESCRIPTION
 *  This is used to resume the specific player and remove it from preemption list
 * PARAMETERS
 *  audio_player           [IN]
 * RETURNS
 *  kal_true or kal_false
 *****************************************************************************/
static kal_bool jma_mvm_audio_player_resume_preempted_player(audio_player_struct *audio_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_bool ret = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_RESUME_PREEMPTED_PLAYER, audio_player->vm_id, audio_player->id);
    if (NULL == audio_player)
    {
        return KAL_FALSE;
    }
    
    if (JAVA_MEDIA_SINGLE_DEVICE == audio_player->device_type)
    {
        native_player = JAVA_AUDIO_SINGLE;
        if (INVALID_NPLAYER_ID != mma_audio_player[JAVA_AUDIO_SINGLE].id)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            return KAL_FALSE;
        }
    }
    else
    {
        jma_mvm_audio_player_locate_resource(audio_player->player.media_type, &native_player);
        if (INVALID_NPLAYER_ID == native_player)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            return KAL_FALSE;
        }
    }
    ret = jma_mvm_audio_player_copy_info(audio_player, &mma_audio_player[native_player]);
    if (!ret)
    {
        return KAL_FALSE;
    }

    memset((kal_uint8 *)&(mma_audio_player[native_player].next_node), 0, sizeof(mma_player_node));
    jma_mvm_audio_player_remove_preempted_node(audio_player->vm_id, audio_player->id);

    /* If resume fail, the registed device would be deregistered */
    jma_register_device(
        mma_audio_player[native_player].device_type,
        mma_audio_player[native_player].vm_id,
        mma_audio_player[native_player].id, 
        &jma_audio_suspend_hdlr, 
        &jma_audio_resume_hdlr, 
        &jma_audio_close_hdlr);
    if (RESOUCE_NO_ERROR != jma_audio_resume_hdlr(mma_audio_player[native_player].vm_id, mma_audio_player[native_player].id))
    {
        jma_audio_free_player_data(&mma_audio_player[native_player]);
        return KAL_FALSE;
    }
    jma_audio_player_register_callback(mma_audio_player[native_player].vm_id);
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_resume_multiple_players
 * DESCRIPTION
 *  This is used to resume the preempted non-single players
 * PARAMETERS
 *
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool jma_mvm_audio_player_resume_multiple_players(kal_int32 vm_id, kal_int32 jplayer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audio_player_struct *player = (audio_player_struct*) preemption_players.head;
    audio_player_struct *next_player = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_RESUME_MULTIPLE_PLAYERS, vm_id, jplayer);
    
    while (player && (player->device_type != JAVA_MEDIA_SINGLE_DEVICE))
    {
        next_player = (audio_player_struct*) player->next_node.next;
        if ((vm_id != player->vm_id) && (jplayer != player->id))
        {
            jma_mvm_audio_player_resume_preempted_player(player);
        }
        player = next_player;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_resume_preempted_players
 * DESCRIPTION
 *  This is used to resume preempted players when the mma_type player release resource
 * PARAMETERS
 *
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool jma_mvm_audio_player_resume_preempted_players(kal_int32 vm_id, kal_int32 jplayer, kal_int32 mma_type, kal_bool is_single_over)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jma_audio_resume_type resume_type = JMA_AUDIO_RESUME_NONE;
    kal_bool ret = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_RESUME_PREEMPTED_PLAYERS, vm_id, jplayer, mma_type, is_single_over);
    
    resume_type = (jma_audio_resume_type)jma_mvm_audio_player_get_resume_type(mma_type, is_single_over);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, resume_type);
    
    if (JMA_AUDIO_RESUME_SINGLE_PLAYER == resume_type)
    {
        audio_player_struct *player = (audio_player_struct*) preemption_players.head;
        if (player && (vm_id != player->vm_id) && (jplayer != player->id))
        {
            ret = jma_mvm_audio_player_resume_preempted_player(player);
        }
        else
        {
            ret = KAL_TRUE;
        }
    }
    else if (JMA_AUDIO_RESUME_MULTI_PLAYER == resume_type)
    {
        ret = jma_mvm_audio_player_resume_multiple_players(vm_id, jplayer);
    }
    else if (JMA_AUDIO_RESUME_NONE == resume_type)
    {
        ret = KAL_TRUE;
    }

    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_resume_hdlr
 * DESCRIPTION
 *  This is audio resume handler invoked when vm_id entry FG from BG state
 * PARAMETERS
 *  vm_id        [IN]        
 * RETURNS
 *  kal_true or kal_false
 *****************************************************************************/
kal_bool jma_mvm_audio_resume_vm_players(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audio_player_struct *audio_player = (audio_player_struct*) preemption_players.head;
    audio_player_struct *next_player = NULL;
    jma_audio_state state = JMA_AUDIO_NON_ACTIVE;
    kal_bool is_single_resumed = KAL_FALSE;
    kal_bool is_multi_resumed = KAL_FALSE;
    kal_bool ret = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RESUME_VM_PLAYERS, vm_id);
    
    JMA_AUDIO_CS_ENTER(vm_id, KAL_FALSE);

    /* Non of preempted player exist */
    if (!audio_player)
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }

    state = jma_mvm_audio_player_state(vm_id);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, state);
    if (JMA_AUDIO_ACTIVE == state)
    {
        if (INVALID_NPLAYER_ID != mma_audio_player[JAVA_AUDIO_SINGLE].id)
        {
            EXT_ASSERT(vm_id == mma_audio_player[JAVA_AUDIO_SINGLE].vm_id, 0, 0, 0);
            // Do not need to resume as the vm_id's single player is alive
            JMA_CS_LEAVE(KAL_TRUE);
        }
        else //multi players
        {
            while (audio_player)
            {
                next_player = (audio_player_struct*) audio_player->next_node.next;
                if (audio_player->vm_id == vm_id && audio_player->device_type != JAVA_MEDIA_SINGLE_DEVICE)
                {
                    ret = jma_mvm_audio_player_preempt_players(audio_player->vm_id, audio_player->player.media_type, (kal_char *)audio_player->player.file_path);
                    if (ret)
                    {
                        jma_mvm_audio_player_resume_preempted_player(audio_player);
                    }
                }
                audio_player = next_player;
            }
        }
    }
    else if (JMA_AUDIO_NON_ACTIVE == state ||
             JMA_AUDIO_ALL_NON_ACTIVE == state)
    {
        EXT_ASSERT(vm_id != mma_audio_player[JAVA_AUDIO_SINGLE].vm_id, 0, 0, 0);
        while (audio_player)
        {
            next_player = (audio_player_struct*) audio_player->next_node.next;
            if (audio_player->vm_id == vm_id)
            {
                if (is_single_resumed)
                {
                    JMA_CS_LEAVE(KAL_TRUE);
                }
                    
                if (JAVA_MEDIA_SINGLE_DEVICE == audio_player->device_type)
                {
                    if (!is_multi_resumed)
                    {
                        jma_mvm_audio_player_preempt_players(audio_player->vm_id, audio_player->player.media_type, (kal_char *)audio_player->player.file_path);
                        ret = jma_mvm_audio_player_resume_preempted_player(audio_player);
                        is_single_resumed = (is_single_resumed || ret) ? KAL_TRUE : KAL_FALSE;
                    }
                }
                else
                {
                    jma_mvm_audio_player_preempt_players(audio_player->vm_id, audio_player->player.media_type, (kal_char *)audio_player->player.file_path);
                    ret = jma_mvm_audio_player_resume_preempted_player(audio_player);
                    is_multi_resumed = (is_multi_resumed || ret) ? KAL_TRUE : KAL_FALSE;
                }
            }
            audio_player = next_player;
        }
    }

    JMA_CS_LEAVE(KAL_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  jma_mvm_audio_player_get_preempted_player
 * DESCRIPTION
 *  Get the number of preempted players
 * PARAMETERS
 *  mma_type        [IN]
 *  native_player   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 jma_mvm_audio_player_get_preempted_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return preemption_players.player_count;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_locate_resource
 * DESCRIPTION
 *  Look up native player of the mma_type
 * PARAMETERS
 *  mma_type        [IN]
 *  native_player   [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_mvm_audio_player_locate_resource(kal_int32 mma_type, kal_int32 *native_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_uint32 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_LOCATE_RESOURCE, mma_type, MMA_MAX_NUM);
    
    *native_player = INVALID_NPLAYER_ID;
    
    jma_audio_player_get_concurrent_count(&count);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, 666, count);
    if (count >= MMA_MAX_NUM)
    {
        return;
    }
    
    if (mma_type == MMA_TYPE_IMY)
    {
        if (mma_audio_player[JAVA_AUDIO_IMY].id == INVALID_JPLAYER_ID)
        {
            *native_player = JAVA_AUDIO_IMY;
        }                
    }
    else if (mma_type == MMA_TYPE_TONE)
    {
        for (i = JAVA_AUDIO_TONE_1; i <= JAVA_AUDIO_TONE_3; i++)
        {
            if (mma_audio_player[i].id == INVALID_JPLAYER_ID)
            {
                *native_player = i;
                break;
            }
        }
    }
    else if (mma_type == MMA_TYPE_WAV)
    {
        for (i = JAVA_AUDIO_WAV_1; i <= JAVA_AUDIO_WAV_4; i++)
        {
            if (mma_audio_player[i].id == INVALID_JPLAYER_ID)
            {
                *native_player = i;
                break;
            }
        } 
    }
    else if (mma_type == MMA_TYPE_MIDI)
    {
        for (i = JAVA_AUDIO_MIDI_1; i <= JAVA_AUDIO_MIDI_4; i++)
        {
            if (mma_audio_player[i].id == INVALID_JPLAYER_ID)
            {
                *native_player = i;
                break;
            }
        } 
    }

    return;
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_midi_is_sp_midi
 * DESCRIPTION
 *  This function submit AudioGetDuration request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  long - duration
 *****************************************************************************/
kal_bool jma_mvm_midi_is_sp_midi(kal_int32 vm_id, kal_int32 java_player, kal_char *data, kal_int32 count, kal_wchar *filename)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle;
    kal_int32 result;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_bool is_spmidi;
    mma_player_struct player;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MIDI_IS_SP_MIDI, vm_id, java_player);

    JMA_AUDIO_CS_ENTER(vm_id, KAL_FALSE);

#ifdef __MED_MMA_EXTRA_CTRL__    
    /* Audio player, audio recorder, video player, camera, video recorder are multual exclusive */
#ifdef SUPPORT_JSR_135_VIDEO
    if (jma_audio_recorder_is_active(vm_id) || jma_video_player_is_active(vm_id))
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
#else
    if (jma_audio_recorder_is_active(vm_id))
    {
	    JMA_CS_LEAVE(KAL_FALSE);
    }
#endif
    /* single player */
    if (filename != NULL)
    {
        if (jma_audio_player_is_active())
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }
    else /* Multiple player */
    {        
        /* Check if single player is closed */
        if (mma_audio_player[JAVA_AUDIO_SINGLE].id != INVALID_JPLAYER_ID)
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }

    jma_mvm_audio_player_locate_resource(MMA_TYPE_MIDI, &native_player);
    if (INVALID_NPLAYER_ID == native_player)
    {
        /* if more than 4 midi player activated, return directly */
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    memset((kal_uint8 *) &player, 0, sizeof(mma_player_struct));
    player.handler = (med_handler) &jma_audio_event_hdlr;
    player.media_type = MMA_TYPE_MIDI; 
    player.repeats = 1;    

    /* Do not copy data */
    if (filename == NULL)
    {
        if(!jma_audio_player_parse_data(MMA_TYPE_MIDI, data, count, &player))
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }
    else
    {
        player.file_path = filename;
    } 
    
    handle = media_mma_aud_open(JMA_MOD_ID, &player, &result);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, handle);

    if (handle == NULL)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        if (player.data != NULL)
        {
            jvm_free(player.data);
            player.data = NULL;
        }
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    /* Get duration by handle */
    is_spmidi = (kal_bool)media_mma_aud_is_sp_midi(handle, MMA_TYPE_MIDI);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, is_spmidi);
    
    media_mma_aud_close(JMA_MOD_ID, handle, MMA_TYPE_MIDI);
    handle = NULL;
    if (player.data != NULL)
    {
        jvm_free(player.data);
        player.data = NULL;
    }
    JMA_CS_LEAVE(is_spmidi);
#else /* #ifdef __MED_MMA_EXTRA_CTRL__ */

    JMA_CS_LEAVE(KAL_FALSE);
#endif /* #ifdef __MED_MMA_EXTRA_CTRL__ */
}


/*****************************************************************************
 * FUNCTION
 *  jma_toneseq_push
 * DESCRIPTION
 *  This function is event handler of midi playback, and this handler is executed under
 *  context of media task.
 * PARAMETERS
 *  block_id        [IN]        
 * RETURNS
 *  int - result.
 *****************************************************************************/
static kal_int32 jma_toneseq_push(kal_int32 block_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stack overflow */
    if (mma_toneseq_block_stack_index >= MAX_TONESEQ_BLOCK_NUM)
    {
        return (-1);
    }

    mma_toneseq_block_stack[mma_toneseq_block_stack_index++] = block_id;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  jma_toneseq_pop
 * DESCRIPTION
 *  This function is event handler of midi playback, and this handler is executed under
 *  context of media task.
 * PARAMETERS
 *  block_id        [?]     
 * RETURNS
 *  int - result.
 *****************************************************************************/
static kal_int32 jma_toneseq_pop(kal_int32 *block_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stack empty */
    if (mma_toneseq_block_stack_index == 0)
    {
        return (-1);
    }

    *block_id = mma_toneseq_block_stack[--mma_toneseq_block_stack_index];
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  jma_transform_tone_seq
 * DESCRIPTION
 *  This function is translation from java tone sequence to native l1audio proprietary format.
 * PARAMETERS
 *  native_player           [IN]        
 *  seq                     [?]         
 *  len                     [IN]        
 *  play_toneseq_len        [?]         
 * RETURNS
 *  java_error_enum
 *****************************************************************************/
static kal_int32 jma_transform_tone_seq(audio_player_struct *audio_player, kal_int8 *seq, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 startseq = 2, note_index = 0, tone_seq_len = 0;
    kal_int32 tempo = 120;
    kal_int32 resolution = 64;
    kal_int32 frac = 1;
    kal_int32 note;
    kal_bool inblk = KAL_FALSE;
    kal_int32 found = 0, thisblen = 0;
    kal_int32 tmp = 0;
    kal_int32 mul = 1;
    kal_int32 duration;
    kal_uint8 *tone_seq = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Clean toneseq parser internal structures */
    kal_mem_set(toneseq_block_info, 0, sizeof(mma_toneseq_block_info_struct) * MAX_TONESEQ_BLOCK_NUM);
    kal_mem_set(mma_toneseq_block_stack, 0, sizeof(int) * MAX_TONESEQ_BLOCK_NUM);
    mma_toneseq_block_stack_index = 0;

    /* VERSION */
    if (seq[0] != VERSION || seq[1] != 1)
    {
        return VERSION_ERROR;
    }

    /* TEMPO */
    if (seq[startseq] == TEMPO)
    {
        if (seq[startseq + 1] < 5)
        {
            return TEMPO_ERROR;
        }
        tempo = (seq[startseq + 1] & 0x7f) << 2;
        startseq += 2;
    }

    /* RESOLUTION */
    if (seq[startseq] == RESOLUTION)
    {
        if (seq[startseq + 1] <= 0)
        {
            return RESOLUTION_ERROR;
        }
        resolution = seq[startseq + 1];
        startseq += 2;
    }

    frac = tempo * resolution;

    /* parse block_definition and sequence_event */
    for (note_index = startseq; note_index < len; note_index += 2)
    {
        note = seq[note_index];

        /* note out of bound */
        if (note < TONE_REPEAT || ((note >= 0 || note == SILENCE) && seq[note_index + 1] <= 0))
        {
            return NOTE_ERROR;
        }

        switch (note)
        {
                /* BLOCK_START */
            case BLOCK_START:
                /* Block start */
                if (!inblk)
                {
                    if (seq[note_index + 1] < 0 || seq[note_index + 1] > 127)
                    {
                        return BLOCK_BEGIN_ERROR;
                    }

                    /* Block number */
                    found = seq[note_index + 1];
                    inblk = KAL_TRUE;

                    /* Save block begining offset */
                    toneseq_block_info[found].block_seq_offset = note_index;

                    thisblen = 0;
                    continue;
                }
                else
                {
                    return BLOCK_NESTED_ERROR;
                }
                //break;

                /* BLOCK_END */
            case BLOCK_END:
                /* already in block */
                if (inblk)
                {
                    /* match block number */
                    if (seq[note_index + 1] == found)
                    {
                        inblk = KAL_FALSE;
                        /* Save block length */
                        toneseq_block_info[found].block_len = thisblen;

                    }
                    else
                    {
                        return BLOCK_END_ERROR;
                    }
                    continue;
                }
                else
                {
                    return BLOCK_END_ERROR;
                }
                //break;

                /* REPEAT */
            case TONE_REPEAT:
                /* times to repeat */
                if (seq[note_index + 1] < 2)
                {
                    return REPEAT_TIME_ERROR;
                }

                note = seq[note_index + 2];
                if (!(note == SILENCE || note >= 0))
                {
                    return REPEAT_SILENCE_ERROR;
                }
                break;

                /* SET_VOLUME */
            case SET_VOLUME:
                /* volume out of bound */
                if (seq[note_index + 1] < 0 || seq[note_index + 1] > 100)
                {
                    return VOLUME_ERROR;
                }

                /* volume event use 1 byte */
                
                if (inblk)
                {
                    thisblen += 1;
                }
                else
                {
                    tone_seq_len += 1;
                }
                break;

                /* PLAY_BLOCK */
            case PLAY_BLOCK:
                tmp = toneseq_block_info[seq[note_index + 1]].block_len;

                if (tmp == 0)
                {
                    return PLAY_BLOCK_ERROR;
                }

                /* already in block */
                if (inblk)
                {
                    thisblen += tmp;
                }
                else
                {
                    tone_seq_len += tmp;
                }
                break;

                /* should not exist VERSION,TEMPO,RESOLUTION */
            case VERSION:
            case TEMPO:
            case RESOLUTION:
                return SEMANTIC_ERROR;
                //break;

                /* SILENCE or normal tone */
            default:
                /* in block - tone event use 3 bytes note, duration1, duration2 */
                if (inblk)
                {
                    thisblen += 3;
                }
                else
                {
                    tone_seq_len += 3;
                }
                break;
        }
    }

    /* if still in block, return error */
    if (inblk)
    {
        return BLOCK_END_ERROR;
    }

    tone_seq = (kal_uint8*) jvm_malloc(tone_seq_len);

    if (tone_seq == NULL)
    {
        return MEMORY_NOTAVAILABLE_ERROR;
    }           

    audio_player->player.data = tone_seq;
    audio_player->player.size = (kal_int32) tone_seq_len;

    tone_seq_len = 0;

    /* skip VERSION */
    note_index = startseq;

    /* Process every element in sequence */
    while (note_index < len)
    {
        note = seq[note_index];
        switch (note)
        {
                /* BLOCK_START */
            case BLOCK_START:   /* blk definition, start */
                do
                {
                    note_index += 2;
                } while (seq[note_index] != BLOCK_END);
                break;

                /* PLAY_BLOCK */
            case PLAY_BLOCK:    /* play_blk */
                /* Push next note index into stack */
                if (jma_toneseq_push(note_index + 2) != 0)
                {
                    jvm_free(audio_player->player.data);
                    audio_player->player.data = NULL;
                    return TONESEQ_STACK_OVERFLOW;
                }

                note_index = toneseq_block_info[seq[note_index + 1]].block_seq_offset + 2;
                continue;

                /* BLOCK_START */
            case BLOCK_END: /* end playing blk */
                /* get next note index before enter block */
                if (jma_toneseq_pop(&tmp) == 0)
                {
                    note_index = tmp;
                }
                continue;

                /* SET_VOLUME */
            case SET_VOLUME:
                /* volume value */
                tone_seq[tone_seq_len++] = (seq[note_index + 1] | 0x80);

                break;

                /* REPEAT */
            case TONE_REPEAT:
                /* 2 <= sequence[i+1] <= 127 */
                mul = seq[note_index + 1];
                break;

                /* SILENCE */
            case SILENCE:
                tone_seq[tone_seq_len++] = 0;
                /* dur as milliseconds */
                /* duration * 60 * 1000 * 4 / (resolution * tempo) */
                duration = (seq[note_index + 1] & 0x7f) * mul * 240000 / frac;
                tone_seq[tone_seq_len++] = duration % 256;
                tone_seq[tone_seq_len++] = duration / 256;
                break;

                /* regular tone */
            default:
                tone_seq[tone_seq_len++] = seq[note_index];
                /* dur as milliseconds */
                /* duration * 60 * 1000 * 4 / (resolution * tempo) */
                duration = (seq[note_index + 1] & 0x7f) * mul * 240000 / frac;
                tone_seq[tone_seq_len++] = duration % 256;
                tone_seq[tone_seq_len++] = duration / 256;

                mul = 1;
        }

        note_index += 2;
    }

    /* parse toneseq without error */
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_finalize
 * DESCRIPTION
 *  Finalize
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_audio_player_finalize(audio_player_struct *audio_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Handle cache file */
    if (audio_player->player.progressive_dl == KAL_TRUE)
    {
        /* Close cache file */
        if (audio_player->cache_handle != NULL)
        {
            result = FS_Close(audio_player->cache_handle);
            audio_player->cache_handle = NULL;
        }
        /* Delete cache file */
        result = FS_Delete((kal_wchar *) audio_player->player.file_path);
        if (result != FS_NO_ERROR)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
        }
    }
    
    jma_audio_free_player_data(audio_player);
    
#ifdef __DRM_SUPPORT__    
    /* stop consume drm right */
    if (audio_player->drm_state == JAVA_DRM_STATE_CONSUMING ||
        audio_player->drm_state == JAVA_DRM_STATE_PAUSED)
    {    
        jam_drm_stop_consume(audio_player->drm_id);            
    }
#endif    

    audio_player->state = JAVA_MEDIA_STATE_NULL;
    audio_player->vm_id = INVALID_JVM_ID;
    audio_player->id = INVALID_JPLAYER_ID;
    audio_player->handle = NULL;
    audio_player->stoptime = -1;
    audio_player->drm_state = JAVA_DRM_STATE_NULL;
    audio_player->drm_id = -1;
    /* For tone player */
    audio_player->device_type = JAVA_MEDIA_INVALID_DEVICE;
    audio_player->play_speed = MDI_AUDIO_SPEED_NORMAL;    
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_suspend_hdlr
 * DESCRIPTION
 *  This function is audio suspend handler invoked when suspendAll executes
 * PARAMETERS
 *  vm_id           [IN]
 *  jplayer         [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_audio_suspend_hdlr(kal_int32 vm_id, kal_int32 jplayer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player = NULL;
    kal_int32 mma_type;
    kal_int32 ms = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_SUSPEND_HDLR, vm_id, jplayer);

    JMA_AUDIO_CS_ENTER(vm_id, RESOUCE_FAIL);
    native_player = jma_audio_jplayer_to_nplayer(vm_id, jplayer);

    if (native_player != INVALID_NPLAYER_ID)
    {
        audio_player = &mma_audio_player[native_player];
        mma_type = audio_player->player.media_type;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        if (audio_player->handle == NULL)
        {
            JMA_CS_LEAVE(RESOUCE_FAIL);
        }

        if (audio_player->is_midi_device)
        {
            ms = media_mma_aud_close_device(JMA_MOD_ID, audio_player->handle, MMA_TYPE_MIDI);
            audio_player->handle = NULL;
            JMA_CS_LEAVE(RESOUCE_NO_ERROR);
        }
        
        if (audio_player->state == JAVA_MEDIA_STATE_BUFFERING ||
            audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);
        }
        
        if (audio_player->state == JAVA_MEDIA_STATE_PLAYING || 
            audio_player->state == JAVA_MEDIA_STATE_PAUSED ||
            audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
        {
            audio_player->current_time = media_mma_aud_get_current_time(JMA_MOD_ID, audio_player->handle, audio_player->player.media_type);
            ms = media_mma_aud_stop(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
            audio_player->sequence_id ++;
            ms = media_mma_aud_close(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
            audio_player->handle = NULL;
        }
        else if (audio_player->state == JAVA_MEDIA_STATE_READY ||
                 audio_player->state == JAVA_MEDIA_STATE_STOPPED_PAUSED ||
                 audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
        {
            ms = media_mma_aud_close(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
            audio_player->handle = NULL;
        }

		if(1 == ms)
		{
		    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 443);
		}
    #ifdef __DRM_SUPPORT__
        /* pause consume drm right */
        if (audio_player->drm_state == JAVA_DRM_STATE_CONSUMING)
        {    
            jam_drm_pause_consume(audio_player->drm_id);
            audio_player->drm_state = JAVA_DRM_STATE_PAUSED;
        }
    #endif

        /* Reset audio play speed */
    #if defined(__BES_TS_SUPPORT__)
        if (mma_type != MMA_TYPE_MIDI && mma_type != MMA_TYPE_TONE)
        {
            if (audio_player->play_speed != MDI_AUDIO_SPEED_NORMAL)
            {
                media_stretch_close(JMA_MOD_ID);
            }
        }
    #endif
    }
    
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_resume_hdlr
 * DESCRIPTION
 *  This function is audio resume handler invoked when resumeAudio executes
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_audio_resume_hdlr(kal_int32 vm_id, kal_int32 jplayer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player = NULL;
    kal_int32 result;
    kal_int32 mma_type;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_RESUME_HDLR, vm_id, jplayer);

    JMA_AUDIO_CS_ENTER(vm_id, RESOUCE_FAIL);
    native_player = jma_audio_jplayer_to_nplayer(vm_id, jplayer);

    if (native_player != INVALID_NPLAYER_ID)
    {
        audio_player = &mma_audio_player[native_player];
        mma_type = audio_player->player.media_type;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        /* audio player has been resumed */
        if (audio_player->handle != NULL)
        {
            JMA_CS_LEAVE(RESOUCE_NO_ERROR);
        }
        
        if (audio_player->is_midi_device)
        {
            audio_player->handle = media_mma_aud_open_device(JMA_MOD_ID, MMA_TYPE_MIDI);
        }
        else
        {
            audio_player->handle = media_mma_aud_open(JMA_MOD_ID, &audio_player->player, (kal_int32*) &result);
        }
        audio_player->aud_id = g_aud_id ++;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, audio_player->handle, audio_player->aud_id);

        if (audio_player->handle == NULL)
        {   
            if (audio_player->player.data != NULL)
            {
                jvm_free(audio_player->player.data);
                audio_player->player.data = NULL;
            }
            jma_deregister_device(audio_player->device_type, audio_player->vm_id, jplayer);

            audio_player->state = JAVA_MEDIA_STATE_NULL;
            audio_player->vm_id = INVALID_JVM_ID;
            audio_player->id = INVALID_JPLAYER_ID;
            audio_player->handle = NULL;
            audio_player->device_type = JAVA_MEDIA_INVALID_DEVICE;
            audio_player->stoptime = -1;
            audio_player->aud_id = 0;
            audio_player->sequence_id = 0;
            
            JMA_CS_LEAVE(RESOUCE_FAIL);
        }

        jam_set_aud_volume_level(jam_get_aud_volume_level());
    #if defined(__MMI_BT_AUDIO_VIA_SCO__)
        jma_media_player_connect_bt_via_sco(NULL);
    #endif    
        /* http streaming: finish downloading  */
        if (audio_player->player.progressive_dl == KAL_TRUE &&
            audio_player->cache_handle == NULL)
        {
            result = media_mma_aud_pdl_write_data_ind(JMA_MOD_ID, audio_player->handle, audio_player->player.media_type, KAL_TRUE);
        }

        if (MMA_TYPE_MIDI == mma_type)
        {
            jma_midi_init_device_resource(audio_player);
            if (audio_player->is_midi_device)
            {
                JMA_CS_LEAVE(RESOUCE_NO_ERROR);
            }
        }
        else
        {
            jma_audio_init_device_resource(audio_player);
        }
        
        /* if player received eom event from med when it is preempted */
        if (audio_player->is_eom)
        {
            audio_player->is_eom = KAL_FALSE;
            jma_audio_eom_handler(mma_type, audio_player);
            JMA_CS_LEAVE(RESOUCE_NO_ERROR);
        }
        
        if (audio_player->state == JAVA_MEDIA_STATE_PLAYING ||
            audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
        {
            audio_player->state = JAVA_MEDIA_STATE_READY;
            jma_mvm_audio_player_play(audio_player->vm_id, audio_player->player.media_type, audio_player->id);
        }
        else if (audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
        {
            audio_player->state = JAVA_MEDIA_STATE_PAUSED;
            jma_mvm_audio_player_play(audio_player->vm_id, audio_player->player.media_type, audio_player->id);
        }
        else if (audio_player->state == JAVA_MEDIA_STATE_PAUSED)
        {
            audio_player->state = JAVA_MEDIA_STATE_STOPPED_PAUSED;
        }
    }
    
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_wav_close_hdlr
 * DESCRIPTION
 *  This function is wav close handler invoked when finalizeResoueceMgr executes
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  resource_error_code
 *****************************************************************************/
kal_int32 jma_audio_close_hdlr(kal_int32 vm_id, kal_int32 jplayer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 mma_type;
    audio_player_struct *audio_player = NULL;
    kal_int32 ms;
    #ifdef __JMA_PREEMPT_PLAYER__
    kal_bool is_single_over = KAL_FALSE;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_CLOSE_HDLR, vm_id, jplayer);        
    JMA_AUDIO_CS_ENTER(vm_id, RESOUCE_FAIL);
    native_player = jma_audio_jplayer_to_nplayer(vm_id, jplayer);

    if (native_player != INVALID_NPLAYER_ID)
    {
        audio_player = &mma_audio_player[native_player];  
        mma_type = audio_player->player.media_type;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        
        /* With resource */
        if (!is_vm_suspend_audio && !is_video_suspend_audio && !is_med_suspend_audio)
        {
            /* Stop timer */
            if (audio_player->player.progressive_dl == KAL_TRUE)
            {
                if (audio_player->state == JAVA_MEDIA_STATE_BUFFERING ||
                    audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
                {
                    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
                    stack_stop_timer(&java_media_timer);
                } 
            }
            
            if (NULL != audio_player->handle && !audio_player->is_midi_device)
            {
                if (audio_player->state == JAVA_MEDIA_STATE_PLAYING || 
                    audio_player->state == JAVA_MEDIA_STATE_PAUSED ||
                    audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
                {
                    ms = media_mma_aud_stop(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
					if(1 == ms)
					{
					    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 125);
					}
                    audio_player->sequence_id ++;
                    ms = media_mma_aud_close(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
					if(1 == ms)
					{
					    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 124);
					}
                    audio_player->handle = NULL;
                }
                else if (audio_player->state == JAVA_MEDIA_STATE_READY ||
                         audio_player->state == JAVA_MEDIA_STATE_STOPPED_PAUSED ||
                         audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
                {
                    ms = media_mma_aud_close(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
					if(1 == ms)
					{
					    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 126);
					}
                    audio_player->handle = NULL;
                }
            }
            else if (NULL != audio_player->handle && audio_player->is_midi_device)
            {
                ms = media_mma_aud_close_device(JMA_MOD_ID, audio_player->handle, MMA_TYPE_MIDI);
				if(1 == ms)
					{
					    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 127);
					}
                audio_player->handle = NULL;
            }

            /* Reset audio play speed */
        #if defined(__BES_TS_SUPPORT__)
            if (mma_type != MMA_TYPE_MIDI && mma_type != MMA_TYPE_TONE)
            {
                if (audio_player->play_speed != MDI_AUDIO_SPEED_NORMAL)
                {
                    media_stretch_close(JMA_MOD_ID);
                }
            }
        #endif

            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, 0);
        }

        
        jma_deregister_device(audio_player->device_type, audio_player->vm_id, jplayer);
        jma_audio_player_finalize(audio_player);
        #ifdef __JMA_PREEMPT_PLAYER__
        is_single_over = (JAVA_MEDIA_SINGLE_DEVICE == audio_player->device_type) ? KAL_TRUE : KAL_FALSE;
        if (!is_vm_suspend_audio && !is_video_suspend_audio && !is_med_suspend_audio)
        {
            /* Resume preempted player */
            jma_mvm_audio_player_resume_preempted_players(vm_id, jplayer, mma_type, is_single_over);
        }
        #endif
    }
    
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);    
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_event_hdlr
 * DESCRIPTION
 *  This function is invoked by MED
 *  context of media task.
 * PARAMETERS
 *  handle      [?]         
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_event_hdlr(kal_int32 handle, med_result_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player = NULL;
    kal_uint32 aud_id, seq_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_EVENT_HANDLER, handle, event);

    native_player = jma_audio_handle_to_nplayer(handle);

    if (native_player != INVALID_NPLAYER_ID)
    {
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        /* find out aud_id and seq_id now */
        aud_id = audio_player->aud_id;
        seq_id = audio_player->sequence_id;
    }   
    #ifdef __JMA_PREEMPT_PLAYER__
    else /* if not found, find preempted player */
    {
        audio_player = jma_audio_locate_handle(handle);
        if (audio_player == NULL)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            return;
        }
        
        /* find out aud_id and seq_id now */
        aud_id = audio_player->aud_id;
        seq_id = audio_player->sequence_id;
    }
    #endif

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, aud_id, seq_id);
    /* Send current sequence number */    
    jam_send_mma_event_callback(handle, event, aud_id, seq_id);
}

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_drm_callback_handler
 * DESCRIPTION
 *  This function is callback handler for drm expired
 * PARAMETERS
 *  handle      [?]         
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_player_drm_callback_handler(kal_int32 result, kal_int32 drm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 mma_type = INVALID_MMA_TYPE;
    audio_player_struct *audio_player = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_DRM_CALLBACK_HANDLER, result, drm_id);
    
    native_player = jma_audio_drm_id_to_nplayer(drm_id);

    if (native_player != INVALID_NPLAYER_ID)
    {
        audio_player = &mma_audio_player[native_player];
    
        jam_drm_stop_consume(audio_player->drm_id);
        audio_player->drm_state = JAVA_DRM_STATE_EXPIRED;
        audio_player->drm_id = -1;
    
        /* If fail, resource is occupied by MMI, do nothing */
        JMA_AUDIO_CS_ENTER(audio_player->vm_id, JMA_VOID);

        jma_mvm_audio_player_close(audio_player->vm_id, mma_type, audio_player->id); 

        JMA_CS_LEAVE(JMA_VOID);
    }
    else
    {
    #ifdef __JMA_PREEMPT_PLAYER__
        audio_player = jma_audio_locate_drm_id(drm_id);
        if (NULL == audio_player)
        {
            return;
        }
        jam_drm_stop_consume(audio_player->drm_id);
        audio_player->drm_state = JAVA_DRM_STATE_EXPIRED;
        audio_player->drm_id = -1;
        jma_mvm_audio_player_remove_preempted_node(audio_player->vm_id, audio_player->id);
    #else
        return;
    #endif
    }

    jvm_post_mma_event(MMA_EVENT_ERROR, audio_player->id, MMA_ERR_DRM_RIGHT_EXPIRED);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_open
 * DESCRIPTION
 *  This function allocate a audio player context in AL and submit AudioOpen request to
 *  media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  data            [?]         
 *  count           [IN]        
 * RETURNS
 *  kal_bool - successful or not
 *****************************************************************************/
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
#if defined(__RICH_AUDIO_PROFILE__)   
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
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_reset_parameter
 * DESCRIPTION
 *  This function reset the specific player's parameter
 * PARAMETERS
 *  audio_player        [IN]   
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_audio_player_reset(audio_player_struct *audio_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((kal_uint8 *)&(audio_player->next_node), 0, sizeof(mma_player_node));
    memset((kal_uint8 *)&(audio_player->player), 0, sizeof(mma_player_struct));
    audio_player->vm_id = INVALID_JVM_ID;
    audio_player->id = INVALID_JPLAYER_ID; 
    audio_player->aud_id = 0;
    audio_player->sequence_id = 0;
    audio_player->device_type = JAVA_MEDIA_INVALID_DEVICE;
    audio_player->cache_handle = NULL;
    audio_player->pitch = -1;
    audio_player->rate = -1;
    audio_player->tempo = -1;
    audio_player->channel = -1;
    audio_player->program = -1;
    audio_player->bank = -1;
    audio_player->handle = NULL;
    audio_player->stoptime = -1;
    audio_player->duration = -1;
    audio_player->current_time = 0;
    audio_player->play_finish_time = 0;
    audio_player->play_speed = MDI_AUDIO_SPEED_NORMAL;
    audio_player->support_time_stretch = KAL_FALSE;
    audio_player->is_midi_device = KAL_FALSE;
    audio_player->is_eom = KAL_FALSE;
    audio_player->state = JAVA_MEDIA_STATE_NULL;
    audio_player->volume = DEFAULT_AUDIO_VOLUME;
    audio_player->drm_id = -1;
    audio_player->drm_state = JAVA_DRM_STATE_NULL;
    audio_player->is_setpitch = KAL_FALSE;
    audio_player->is_setrate = KAL_FALSE;
    audio_player->is_settempo = KAL_FALSE;
    audio_player->is_setprogram = KAL_FALSE;
        
    audio_player->channel_volume_sets = 0;
    memset((kal_uint8 *)&(audio_player->channel_volume), 0, MAX_MIDI_CHANNEL * sizeof(kal_uint8));
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_reset_parameter
 * DESCRIPTION
 *  This function reset all player's parameter
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_player_reset_parameter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    audio_player_struct *audio_player;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_RESET_PARAMETER);

    /* For midi player */
    #ifdef __JMA_PREEMPT_PLAYER__
    preemption_players.head = NULL;
    preemption_players.player_count = 0;
    #endif
    jma_mimic_module_id = MOD_NIL;
    
    /* remember add in jma_midi_player_init() */
    for (i = 0; i < JAVA_NO_OF_PLAYER; i++)
    {
        audio_player = &mma_audio_player[i];
        jma_audio_player_reset(audio_player);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_parse_data
 * DESCRIPTION
 *  This function parse mp3, aac data 
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  filename        [?]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool jma_audio_player_parse_data(kal_int32 mma_type, kal_char *data, kal_int32 count, mma_player_struct *player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 real_count = count;
    kal_char *real_data = data;
    kal_char *aud_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Copy Data from KNI Layer */
    aud_ptr = jvm_malloc(real_count);
    if (aud_ptr == NULL)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        return KAL_FALSE;
    }
    memcpy(aud_ptr, real_data, real_count); 
    player->size = real_count;
    player->data = (kal_uint8*) aud_ptr;
                    
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_open
 * DESCRIPTION
 *  This function opens audio 
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  filename        [?]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mvm_audio_player_open(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 count, kal_char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 duration = -1;
    kal_int32 result;
    audio_player_struct *audio_player;
    kal_char *aud_ptr = NULL;
    #ifdef __JMA_PREEMPT_PLAYER__
    kal_bool is_single_over = KAL_FALSE;
    #endif
    
#ifdef __DRM_SUPPORT__    
    kal_bool is_permitted;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_OPEN, vm_id, mma_type, java_player, data, count, filename);

    JMA_AUDIO_CS_ENTER(vm_id, KAL_FALSE);
    /* Either data player or file name player: except tone-seq, midi device */
    if (mma_type != MMA_TYPE_TONE && mma_type != MMA_TYPE_MIDI)
    {
        EXT_ASSERT((data != NULL && filename == NULL) || (data == NULL && filename != NULL), 0, 0, 0);
    }

    /* Audio player, audio recorder, video player, camera, video recorder are multual exclusive */
#ifdef SUPPORT_JSR_135_VIDEO
		if (jma_audio_recorder_is_active(vm_id) || jma_video_player_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#else
		if (jma_audio_recorder_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#endif
  
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    if (KAL_TRUE)
    {
    #ifdef __DRM_SUPPORT__
        /* Check drm right */
        if (filename != NULL)
        {
            /* Check drm right */
            if (jam_drm_is_drm_file((kal_wchar*)filename))
            {
                is_permitted = jam_drm_check_right(
                                (kal_wchar*)filename, 
                                DRM_PERMISSION_PLAY);
                if (!is_permitted)
                {
                    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                    JMA_CS_LEAVE(KAL_FALSE);
                }
            }
        }
    #endif /* __DRM_SUPPORT__ */  
    #ifdef __JMA_PREEMPT_PLAYER__
        if (vm_id == jam_mvm_get_current_vm_id())
        {
            if (!jma_mvm_audio_player_preempt_players(vm_id, mma_type, filename))
                JMA_CS_LEAVE(KAL_TRUE); // return true to avoid through exception
            
        }
    #endif
        
        /* single player */
        if (filename != NULL || jma_audio_player_is_single_player(mma_type))
        {
            if (jma_audio_player_is_active())
            {
                JMA_CS_LEAVE(KAL_FALSE);
            }
            native_player = JAVA_AUDIO_SINGLE;
            mma_audio_player[native_player].device_type = JAVA_MEDIA_SINGLE_DEVICE;
        }
        else /* Multiple player */
        {
            EXT_ASSERT(MMA_TYPE_MIDI == mma_type || MMA_TYPE_IMY == mma_type || MMA_TYPE_TONE == mma_type || MMA_TYPE_WAV == mma_type, 0, 0, 0);
            /* Check if single player is closed */
            if (INVALID_JPLAYER_ID != mma_audio_player[JAVA_AUDIO_SINGLE].id)
            {
                JMA_CS_LEAVE(KAL_FALSE);
            }

            jma_mvm_audio_player_locate_resource(mma_type, &native_player);
            if (INVALID_NPLAYER_ID == native_player)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, native_player);
                JMA_CS_LEAVE(KAL_FALSE);
            }
            
            if (MMA_TYPE_IMY == mma_type)
            {
                mma_audio_player[native_player].device_type = JAVA_MEDIA_IMY_DEVICE;
            }
            else if (MMA_TYPE_TONE == mma_type)
            {
                mma_audio_player[native_player].device_type = JAVA_MEDIA_TONESEQ_DEVICE;
            }
            else if (MMA_TYPE_WAV == mma_type)
            {
                mma_audio_player[native_player].device_type = JAVA_MEDIA_WAV_DEVICE;
            }
            else if (MMA_TYPE_MIDI == mma_type)
            {
                mma_audio_player[native_player].device_type = JAVA_MEDIA_MIDI_DEVICE;
            }            
        }       

        /* For speed up: avoid array access */    
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        
        if (audio_player->state == JAVA_MEDIA_STATE_NULL)
        {
            if (MMA_TYPE_MIDI == mma_type)
            {
                jma_midi_player_init(audio_player);
                if (NULL == data && NULL == filename)
                {
                    audio_player->is_midi_device = KAL_TRUE;
                }
            }
            memset((kal_uint8 *)&(audio_player->player), 0, sizeof(mma_player_struct));
            audio_player->player.handler = (med_handler) &jma_audio_event_hdlr;
            audio_player->player.media_type = mma_type; 
            audio_player->player.repeats = 1;

            /* Tone player uses setSequence to set data && midi device use set short or long event to set data */
            if (mma_type != MMA_TYPE_TONE && !audio_player->is_midi_device)
            {
                if (filename == NULL)
                {
                    if(!jma_audio_player_parse_data(mma_type, data, count, &(audio_player->player)))
                    {
                        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                        JMA_CS_LEAVE(KAL_FALSE);
                    }
                }
                else
                {
                    /* Copy FileName from KNI Layer */
                    aud_ptr = jvm_malloc(MAX_MEDIA_FILE_NAME * 2);
                    if (aud_ptr == NULL)
                    {
                        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                        JMA_CS_LEAVE(KAL_FALSE);
                    }
                    mmi_ucs2cpy(aud_ptr, filename);                
                    audio_player->player.file_path = (kal_wchar *) aud_ptr;
                    
                } 
            }
            
            if (audio_player->is_midi_device)
            {
                /* MIDI Control should create handle first */
                audio_player->handle = media_mma_aud_open_device(JMA_MOD_ID, (kal_uint8) mma_type);
            }
            else 
            {
                audio_player->player.output_path = MDI_DEVICE_SPEAKER2;
                audio_player->handle = media_mma_aud_open(JMA_MOD_ID, &(audio_player->player), &result);
            }
            audio_player->aud_id = g_aud_id ++;
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDD, audio_player->handle, audio_player->aud_id, result);

            if (audio_player->handle == NULL)
            {
                if (audio_player->player.file_path != NULL)
                {
                    jvm_free(audio_player->player.file_path);
                    audio_player->player.file_path = NULL;
                }

                if (audio_player->player.data != NULL)
                {
                    jvm_free(audio_player->player.data);
                    audio_player->player.data = NULL;
                }
#ifdef __JMA_PREEMPT_PLAYER__               
                is_single_over = (JAVA_MEDIA_SINGLE_DEVICE == audio_player->device_type) ? KAL_TRUE : KAL_FALSE;

                /* Resume preempted player */
                jma_mvm_audio_player_resume_preempted_players(INVALID_JVM_ID, INVALID_JAVA_PLAYER, mma_type, is_single_over);
#endif                
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                JMA_CS_LEAVE(KAL_FALSE);
            }
            
            /* MED would set mute when play dummy audio for pure video */
            jam_set_aud_volume_level(jam_get_aud_volume_level()); 
            EXT_ASSERT(audio_player->device_type != JAVA_MEDIA_INVALID_DEVICE, 0, 0, 0);

            /* Succeed to acquire resource */
            jma_register_device(
                audio_player->device_type,
                vm_id,
                java_player, 
                &jma_audio_suspend_hdlr, 
                &jma_audio_resume_hdlr, 
                &jma_audio_close_hdlr);         

            /* Register Callback function only when Java "REALLY" occupy resources */
            /* As long as Java releases resources, it should deregister right away */
            jma_audio_player_register_callback(vm_id);

            /* Connect BT when open successfully */
        #if defined(__MMI_BT_AUDIO_VIA_SCO__)
            jma_media_player_connect_bt_via_sco(NULL);
        #endif
            /* Tone: Not yet setSequence(), duration == 0 */
            if (mma_type != MMA_TYPE_TONE && !audio_player->is_midi_device)
            {
                duration = media_mma_aud_get_duration(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, duration);
                if (duration == 0)
                {
                    duration = -1;
                }
            }
            else
            {
                duration = 0;
            }
        #if defined(__BES_TS_SUPPORT__)
            if (mma_type != MMA_TYPE_MIDI && mma_type != MMA_TYPE_TONE)
            {
                if (audio_player->player.file_path == NULL)
                {
                    result = media_stretch_check_stream_format(
                                JMA_MOD_ID, 
                                audio_player->player.data, 
                                audio_player->player.size, 
                                (kal_uint16) media_mma_aud_get_med_data_type((kal_uint8) mma_type));
                }
                else
                {
                    result = media_stretch_check_file_format(JMA_MOD_ID, audio_player->player.file_path);
                }
                audio_player->support_time_stretch = (result == MED_RES_OK) ? KAL_TRUE : KAL_FALSE;
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_player->support_time_stretch);
            }
        #endif   
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_READY);
            audio_player->duration = duration;
            audio_player->current_time = 0;
            audio_player->play_finish_time = 0;
            audio_player->state = JAVA_MEDIA_STATE_READY;
            audio_player->vm_id = vm_id;
            audio_player->id = java_player;
            audio_player->stoptime = -1;
            audio_player->volume = DEFAULT_AUDIO_VOLUME;
            audio_player->sequence_id = 0;
            audio_player->play_speed = MDI_AUDIO_SPEED_NORMAL;
        }
    }
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_play_internal
 * DESCRIPTION
 *  This function submit AudioPlay request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  kal_bool - successful or not
 *****************************************************************************/
static kal_bool jma_audio_player_play_internal(audio_player_struct *audio_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = 1;
    kal_bool ret = KAL_FALSE;
    int ticks = kal_milli_secs_to_ticks(200); /* 200 ms */
#ifdef __DRM_SUPPORT__    
    kal_int32 drm_id;
    kal_int32 drm_result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (audio_player->state == JAVA_MEDIA_STATE_READY ||
        audio_player->state == JAVA_MEDIA_STATE_STOPPED_PAUSED ||
        audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
    {
        result = media_mma_aud_set_volume(JMA_MOD_ID, 
                audio_player->handle,
                audio_player->player.media_type,
                audio_player->volume);

        result = media_mma_aud_play(JMA_MOD_ID, audio_player->handle, audio_player->player.media_type);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_player->sequence_id);
    }
    else if (audio_player->state == JAVA_MEDIA_STATE_PAUSED ||
             audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
    {
        result = media_mma_aud_resume(JMA_MOD_ID, audio_player->handle, audio_player->player.media_type);
    }
    
    if (result == MED_RES_OK)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, audio_player->vm_id, audio_player->state, JAVA_MEDIA_STATE_PLAYING);
        audio_player->state = JAVA_MEDIA_STATE_PLAYING;
    #ifdef __DRM_SUPPORT__
        /* consume drm right */
        if (audio_player->drm_state == JAVA_DRM_STATE_PERMITTED)
        {
            drm_id = jam_drm_start_consume(
                        audio_player->player.file_path, 
                        DRM_PERMISSION_PLAY, 
                        jma_audio_player_drm_callback_handler);
            if (drm_id >= 0)
            {
                audio_player->drm_id = drm_id;
                audio_player->drm_state = JAVA_DRM_STATE_CONSUMING;
            }
            else
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                JMA_CS_LEAVE(KAL_FALSE);
            }
        }  
        else if (audio_player->drm_state == JAVA_DRM_STATE_PAUSED)
        {    
            drm_result = jam_drm_resume_consume(audio_player->drm_id);
            if (drm_result == J2ME_NO_ERROR)
            {
                audio_player->drm_state = JAVA_DRM_STATE_CONSUMING;
            }
            else
            {
                jma_audio_player_close(audio_player->player.media_type, audio_player->id);
                jvm_post_mma_event(MMA_EVENT_ERROR, audio_player->id, MMA_ERR_DRM_RIGHT_EXPIRED);
                JMA_CS_LEAVE(KAL_FALSE);
            }
        }
    #endif 
        ret = KAL_TRUE;
    }
    else if (result == MED_RES_END_OF_FILE)
    {
        jma_audio_eom_handler(audio_player->player.media_type, audio_player);
        ret = KAL_TRUE;
    }
    else if (result == MED_RES_BUFFER_INSUFFICIENT)
    {
        /* change as buffering state directly */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, audio_player->vm_id, audio_player->state, JAVA_MEDIA_STATE_BUFFERING);
        audio_player->state = JAVA_MEDIA_STATE_BUFFERING;

        /* To avoid forever loop, do not call jma_audio_player_cache_buffering_cyclic() */
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
        stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_AUDIO_PDL_PLAYER, ticks); 

        ret = KAL_TRUE;
    }

    return ret;    
}

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_play
 * DESCRIPTION
 *  This function submit AudioPlay request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  kal_bool - successful or not
 *****************************************************************************/
kal_bool jma_mvm_audio_player_play(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_uint32 dl_percentage = 0;
    kal_int32 result = 1;
    audio_player_struct *audio_player;
    kal_bool ret = KAL_FALSE;
    
#ifdef __DRM_SUPPORT__    
    kal_bool is_permitted;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_PLAY, vm_id, mma_type, java_player);

    JMA_AUDIO_CS_ENTER(vm_id, KAL_FALSE); 
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

#ifdef __JMA_PREEMPT_PLAYER__
    if (INVALID_NPLAYER_ID == native_player)
    {
        /* For mvm, if player not locate at preemption list, return kal_true to avoid exception */
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
        if (audio_player == NULL)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_TRUE);
        }
        
        /* If there are empty resource, the preempted player can be resumed when vm at bg/short event state */
        if (JMA_AUDIO_PREEMPT_NONE != jma_mvm_audio_player_get_preemption_type(vm_id, mma_type, (kal_char *)audio_player->player.file_path) &&
            vm_id != jam_mvm_get_current_vm_id())
        {
            /* Transit the state to ensure play it when resumed */
            if (JAVA_MEDIA_STATE_READY == audio_player->state ||
                JAVA_MEDIA_STATE_PAUSED == audio_player->state ||
                JAVA_MEDIA_STATE_STOPPED_PAUSED == audio_player->state)
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_PLAYING);
                audio_player->state = JAVA_MEDIA_STATE_PLAYING;
            }
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, audio_player->vm_id, audio_player->id);
            JMA_CS_LEAVE(KAL_TRUE);
        }

        ret = jma_mvm_audio_player_preempt_players(vm_id, mma_type, (kal_char *)audio_player->player.file_path);
        if (ret)
        {
            jma_mvm_audio_player_resume_preempted_player(audio_player);
        }
        native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    }
#endif
    if (native_player != INVALID_NPLAYER_ID)
    {
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);

        /* Audio is playing or has already prepared for playing. */
        if (audio_player->state == JAVA_MEDIA_STATE_PLAYING ||
            audio_player->state == JAVA_MEDIA_STATE_BUFFERING ||
            audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
        {
            JMA_CS_LEAVE(KAL_TRUE);
        }

        /* For Tone player which calls p.start(), but not calls setSequence() */
        if (MMA_TYPE_TONE == mma_type && NULL == audio_player->player.data)
        {
            jma_audio_eom_handler(mma_type, audio_player);
            JMA_CS_LEAVE(KAL_TRUE);
        }
        /* midi device should call set short or long event to play */
        if (MMA_TYPE_MIDI == mma_type && audio_player->is_midi_device)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_TRUE);
        }
        
        if (0 == audio_player->stoptime)
        {
            if (JAVA_MEDIA_STATE_PAUSED == audio_player->state)
            {
                result = media_mma_aud_stop(MOD_J2ME, audio_player->handle, (kal_uint8) mma_type);
                audio_player->sequence_id ++;             
            }

			if(1 == result)
			{
				kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 357);
			}
            /* In the function, state will change to STOPPED_PAUSED */
            jma_audio_eom_handler(mma_type, audio_player);
            JMA_CS_LEAVE(KAL_TRUE);
        }

        /* Reset play finish time for the play of this time */
        audio_player->play_finish_time = 0;  
        
    #ifdef __DRM_SUPPORT__
        /* Check drm right */
        if (audio_player->player.file_path != NULL &&
            audio_player->player.progressive_dl == KAL_FALSE &&
            audio_player->drm_state == JAVA_DRM_STATE_NULL)
        {
            /* Check drm right */
            if (jam_drm_is_drm_file(audio_player->player.file_path))
            {
                is_permitted = jam_drm_check_right(
                                audio_player->player.file_path, 
                                DRM_PERMISSION_PLAY);
                if (is_permitted)
                {
                    audio_player->drm_state = JAVA_DRM_STATE_PERMITTED;
                }
                else
                {
                    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                    JMA_CS_LEAVE(KAL_FALSE);
                }
            }
            else
            {
                audio_player->drm_state = JAVA_DRM_STATE_NORMAL_FILE;
            }
        }                  
    #endif 
        if (!audio_player->player.progressive_dl)
        {
            ret = jma_audio_player_play_internal(audio_player);
        }
        else
        {
            media_mma_aud_pdl_get_buf_percent(JMA_MOD_ID, audio_player->handle, 5, &dl_percentage);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, dl_percentage);
            if (dl_percentage == 100)
            {
                ret = jma_audio_player_play_internal(audio_player);
            }
            else
            {
                if (audio_player->state == JAVA_MEDIA_STATE_READY ||
                    audio_player->state == JAVA_MEDIA_STATE_STOPPED_PAUSED)
                {
                    /* change as buffering state directly */
                    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_BUFFERING);
                    audio_player->state = JAVA_MEDIA_STATE_BUFFERING;
                }
                else if (audio_player->state == JAVA_MEDIA_STATE_PAUSED)
                {
                    /* change as buffering state directly */
                    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_PAUSED_BUFFERING);
                    audio_player->state = JAVA_MEDIA_STATE_PAUSED_BUFFERING;
                }
                ret = jma_audio_player_cache_buffering_cyclic();
            }
        }
    }

    JMA_CS_LEAVE(ret);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_pause
 * DESCRIPTION
 *  This function submit AudioPause request to media task.
 *  @TODO: pause midi player rather than stop it
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jma_mvm_audio_player_pause(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 media_time;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 ms = 0;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_PAUSE, vm_id, mma_type, java_player);
    JMA_AUDIO_CS_ENTER(vm_id, KAL_FALSE); 

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];  
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        if (audio_player->handle == NULL)
        {
            JMA_CS_LEAVE(KAL_TRUE);
        }
   // #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            if (audio_player->state == JAVA_MEDIA_STATE_PLAYING ||
                audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_PAUSED);
                audio_player->state = JAVA_MEDIA_STATE_PAUSED;    
            }
            else if (audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_STOPPED_PAUSED);
                audio_player->state = JAVA_MEDIA_STATE_STOPPED_PAUSED;
            }

            JMA_CS_LEAVE(KAL_TRUE);
        }
   // #endif /* __MMI_BACKGROUND_CALL__ */
    
        if (audio_player->state == JAVA_MEDIA_STATE_PLAYING)
        {
            ms = media_mma_aud_pause(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);

            if (ms == MED_RES_OK)
            {
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_PAUSED);
                audio_player->state = JAVA_MEDIA_STATE_PAUSED;
                /* Keep current time when player stopped */
                media_time = media_mma_aud_get_current_time(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, media_time);
                audio_player->current_time = media_time;

            #ifdef __DRM_SUPPORT__
                /* pause consume drm right */
                if (audio_player->drm_state == JAVA_DRM_STATE_CONSUMING)
                {    
                    jam_drm_pause_consume(audio_player->drm_id);
                    audio_player->drm_state = JAVA_DRM_STATE_PAUSED;
                }
            #endif  
            }
            else
            {
                if (mma_type == MMA_TYPE_AAC)
                {
                    /* ADIF type AAC can't be paused, only ADTS type can be paused */
                    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_PLAYING);
                    audio_player->state = JAVA_MEDIA_STATE_PLAYING;
                    JMA_CS_LEAVE(KAL_TRUE);
                }
                else
                {
                    /* Pause fail: Already MediaEnd */
                    audio_player->sequence_id ++;
                    jma_audio_eom_handler(mma_type, audio_player);
                }
            }
        }
        else if (audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);        

            /* To ensure call PLAY instead of RESUME when play next time */
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_STOPPED_PAUSED);
            audio_player->state = JAVA_MEDIA_STATE_STOPPED_PAUSED;
        }
        else if (audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);
            
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_PAUSED);
            audio_player->state = JAVA_MEDIA_STATE_PAUSED;
        }
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
        if (NULL == audio_player)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_TRUE);
        }
        /* For mvm, if player preempted, then it would response to pause */
        if (audio_player->state == JAVA_MEDIA_STATE_PLAYING ||
            audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_PAUSED);
            audio_player->state = JAVA_MEDIA_STATE_PAUSED;
        }
        else if (audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_STOPPED_PAUSED);
            audio_player->state = JAVA_MEDIA_STATE_STOPPED_PAUSED;
        }
        
    }
    #else
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
    #endif
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_close
 * DESCRIPTION
 *  This function submit AudioClose request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_audio_player_close(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle = NULL;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 ms;
    audio_player_struct *audio_player;
    #ifdef __JMA_PREEMPT_PLAYER__
    kal_bool is_single_over = KAL_FALSE;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_CLOSE, vm_id, mma_type, java_player);

    JMA_AUDIO_CS_ENTER(vm_id, JMA_VOID); 
    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);

        jma_deregister_device(audio_player->device_type, vm_id, audio_player->id);
        
    //#ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            jma_audio_player_finalize(audio_player);
            JMA_CS_LEAVE(JMA_VOID);
        }
    //#endif /* __MMI_BACKGROUND_CALL__ */
    
        /* Stop timer */
        if (audio_player->player.progressive_dl == KAL_TRUE)
        {
            if (audio_player->state == JAVA_MEDIA_STATE_BUFFERING ||
                audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
                stack_stop_timer(&java_media_timer);
            } 
        }

        if (audio_player->handle != NULL && !audio_player->is_midi_device)
        {
            handle = audio_player->handle;
            if (audio_player->state == JAVA_MEDIA_STATE_PLAYING ||
                audio_player->state == JAVA_MEDIA_STATE_PAUSED ||
                audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
            {
                ms = media_mma_aud_stop(JMA_MOD_ID, handle, (kal_uint8) mma_type);
                audio_player->sequence_id ++;
                ms = media_mma_aud_close(JMA_MOD_ID, handle, (kal_uint8) mma_type);
                handle = NULL;
            }
            else if (audio_player->state == JAVA_MEDIA_STATE_READY ||
                     audio_player->state == JAVA_MEDIA_STATE_STOPPED_PAUSED ||
                     audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
            {
                ms = media_mma_aud_close(JMA_MOD_ID, handle, (kal_uint8) mma_type);
                handle = NULL;
            }
        }
        else if (audio_player->handle != NULL && audio_player->is_midi_device)
        {
            ms = media_mma_aud_close_device(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
			if(1 == ms)
			{
				kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 776);
			}
            audio_player->handle = NULL;
        }

        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_NULL);

        /* Reset audio play speed */
    #if defined(__BES_TS_SUPPORT__)
        if (mma_type != MMA_TYPE_MIDI && mma_type != MMA_TYPE_TONE)
        {
            if (audio_player->play_speed != MDI_AUDIO_SPEED_NORMAL)
            {
                media_stretch_close(JMA_MOD_ID);
            }
        }
    #endif
    

        jma_audio_player_finalize(audio_player);
        /* Clear callback only when all player is closed */
        jma_audio_player_clear_callback(vm_id);
#ifdef __JMA_PREEMPT_PLAYER__
        /* Resume preempted player */
        is_single_over = (JAVA_MEDIA_SINGLE_DEVICE == audio_player->device_type) ? KAL_TRUE : KAL_FALSE;
        jma_mvm_audio_player_resume_preempted_players(INVALID_JVM_ID, INVALID_JAVA_PLAYER, mma_type, is_single_over);
#endif
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        /* for mvm, if player locate at preemption list, remove it */
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
        if (audio_player)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, audio_player->vm_id, audio_player->id);
            jma_mvm_audio_player_remove_preempted_node(vm_id, java_player);   
        }
    }
    #endif
    
    JMA_CS_LEAVE(JMA_VOID); 
}

void jma_mvm_audio_player_clear_jmadata(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;

    native_player = jma_audio_jplayer_to_nplayer(mma_type, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];
        sprintf(_kvmLogStr,"[JMA] jma_audio_player_clearJMAData clear audio_player %d\n", audio_player);
        Kprintf();
        jma_deregister_device(audio_player->device_type, vm_id, audio_player->id);
        jma_audio_player_finalize(audio_player);
    }
}

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_play_tone
 * DESCRIPTION
 *  This function is play a single tone by specified note, duration and volume.
 * PARAMETERS
 *  note            [IN]        
 *  duration        [IN]        
 *  vol             [IN]        
 * RETURNS
 *  0: unsuccessful / 1: successful
 *****************************************************************************/
kal_bool jma_mvm_audio_player_play_tone(kal_int32 vm_id, kal_int32 note, kal_int32 duration, kal_int32 vol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ms = 1;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;
    kal_uint8 *tone_seq = NULL;
    kal_bool ret = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERPLAYTONE, vm_id, note, duration, vol);

    JMA_AUDIO_CS_ENTER(vm_id, KAL_FALSE); 

    if ((note < 0) || (note > 127) || (duration < 100) || (duration > 32767) || (vol < 0) || (vol > 100))
    {
        /* invalid parameter */
        JMA_CS_LEAVE(KAL_FALSE);
    }

    /* Audio player, audio recorder, video player, camera, video recorder are multual exclusive */
#ifdef SUPPORT_JSR_135_VIDEO
		if (jma_audio_recorder_is_active(vm_id) || jma_video_player_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#else
		if (jma_audio_recorder_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#endif

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    /* if (vm_id == jam_mvm_get_current_vm_id())
    {
        if (!jma_mvm_audio_player_preempt_players(vm_id, MMA_TYPE_TONE, NULL))
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }
    } */
    /* Check if single player is closed */
    if (mma_audio_player[JAVA_AUDIO_SINGLE].id != INVALID_JPLAYER_ID)
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
    jma_mvm_audio_player_locate_resource(MMA_TYPE_TONE, &native_player);

    if (native_player != INVALID_NPLAYER_ID)
    {
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
    }
    else
    {
        JMA_CS_LEAVE(KAL_TRUE); 
    }

    if (audio_player->state == JAVA_MEDIA_STATE_NULL)
    {
        memset((kal_uint8 *) &(audio_player->player), 0, sizeof(mma_player_struct));
        audio_player->player.handler = (med_handler) &jma_audio_event_hdlr;
        audio_player->player.media_type = MMA_TYPE_TONE;
        audio_player->player.output_path = MDI_DEVICE_SPEAKER2;
        audio_player->handle = media_mma_aud_open(JMA_MOD_ID, &audio_player->player, (kal_int32*) &ms);
        audio_player->aud_id = g_aud_id ++;        
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDD, audio_player->handle, audio_player->aud_id, ms);

        if (audio_player->handle == NULL)
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }

        /* MED would set mute when play dummy audio for pure video */
        jam_set_aud_volume_level(jam_get_aud_volume_level()); 
        
        jma_register_device(
            JAVA_MEDIA_TONE_DEVICE,
            vm_id,
            single_tone_player_id, /* self-create java_player id */
            &jma_audio_suspend_hdlr, 
            &jma_audio_resume_hdlr, 
            &jma_audio_close_hdlr);

        /* Register Callback function */
        jma_audio_player_register_callback(vm_id);
    #if defined(__MMI_BT_AUDIO_VIA_SCO__)
        jma_media_player_connect_bt_via_sco(NULL);
    #endif          
        audio_player->state = JAVA_MEDIA_STATE_READY;
        audio_player->vm_id = vm_id;
        audio_player->id = single_tone_player_id; 
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, single_tone_player_id);
        single_tone_player_id --;
        if (single_tone_player_id <= 0x8FFFFFFF)/* min of integer */
        {
            single_tone_player_id = INVALID_JPLAYER_ID - 1; /* Can not start from 0 */
        }
        audio_player->device_type = JAVA_MEDIA_TONE_DEVICE;

        tone_seq = jvm_malloc(4); /* Four bytes */
        if (tone_seq == NULL)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_FALSE);
        }
        tone_seq[0] = vol | 0x80;   /* Put volume before not duration */
        tone_seq[1] = note & 0x7f;
        tone_seq[2] = duration % 256;
        tone_seq[3] = duration / 256;

        audio_player->player.data = tone_seq;
        audio_player->player.size = (kal_int32) 4;
        audio_player->player.repeats = 1;
        audio_player->volume = vol;

        ms = media_mma_aud_set_data(JMA_MOD_ID, 
                (kal_int32) audio_player->handle,
                MMA_TYPE_TONE,
                &audio_player->player);

        ms = media_mma_aud_set_volume(JMA_MOD_ID, audio_player->handle, MMA_TYPE_TONE, audio_player->volume);

        ms = media_mma_aud_play(JMA_MOD_ID, audio_player->handle, MMA_TYPE_TONE);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_player->sequence_id);

        if (ms == MED_RES_OK)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, audio_player->state, JAVA_MEDIA_STATE_PLAYING);
            audio_player->state = JAVA_MEDIA_STATE_PLAYING;
            ret = KAL_TRUE;
        }
        else
        {
            /* failed to play single tone */
            media_mma_aud_close(JMA_MOD_ID, audio_player->handle, MMA_TYPE_TONE);
            if (audio_player->player.data != NULL)
            {
                jvm_free(audio_player->player.data);
                audio_player->player.data = NULL;
            }
            jma_deregister_device(JAVA_MEDIA_TONE_DEVICE, audio_player->vm_id, audio_player->id);
            audio_player->state = JAVA_MEDIA_STATE_NULL;
            audio_player->vm_id = INVALID_JVM_ID;
            audio_player->id = INVALID_JPLAYER_ID;
            audio_player->handle = NULL;
            audio_player->device_type = JAVA_MEDIA_INVALID_DEVICE;
            audio_player->volume = DEFAULT_AUDIO_VOLUME;

            /* Clear Callback function */
            jma_audio_player_clear_callback(vm_id);
            
            //jma_mvm_audio_player_resume_preempted_players(INVALID_JVM_ID, INVALID_JAVA_PLAYER, MMA_TYPE_TONE, KAL_FALSE);
            
            ret = KAL_FALSE;
        }
        
        JMA_CS_LEAVE(ret);
    }

    JMA_CS_LEAVE(KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_set_sequence
 * DESCRIPTION
 *  This function submit SetData request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  seq             [?]         
 *  len             [IN]        
 * RETURNS
 *  0 if no error
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_set_sequence(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int8 *seq, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;
    kal_bool is_preempted = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_SET_SEQ, vm_id, mma_type, java_player);

    JMA_AUDIO_CS_ENTER(vm_id, -1); 

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        is_preempted = KAL_TRUE;
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
    }
    #endif
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
    
    if (audio_player && MMA_TYPE_TONE == mma_type)
    {
        /* Avoid call setSequence many times */
        if (audio_player->player.data != NULL)
        {
            jvm_free(audio_player->player.data);
            audio_player->player.data = NULL;
        }

        kal_trace(TRACE_GROUP_1, INFO_J2ME_MMA_DDDD, seq[0], seq[1], seq[2], seq[3]);

        ret = jma_transform_tone_seq(audio_player, seq, len);
        if (ret != 0)
        {
            JMA_CS_LEAVE(ret);
        }

        audio_player->player.repeats = 1;
        audio_player->player.file_path = NULL;
        
    //#ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            JMA_CS_LEAVE(0);
        }
   // #endif /* __MMI_BACKGROUND_CALL__ */

        if (!is_preempted)
        {
            media_mma_aud_set_data(
                JMA_MOD_ID,  
                (kal_int32) audio_player->handle,
                (kal_uint8) mma_type,
                &audio_player->player);
        }
    }
    
    JMA_CS_LEAVE(0);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_set_media_time
 * DESCRIPTION
 *  This function submit AudioSetStartTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  now             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int64 jma_mvm_audio_player_set_media_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int64 now)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 duration;
    audio_player_struct *audio_player;
    kal_int32 ms = 1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_SET_MEDIA_TIME, vm_id, mma_type, java_player, (kal_uint32)now);

    JMA_AUDIO_CS_ENTER(vm_id, -1); 

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)
    {
        /* In low cost project, MIDI file does not support seek */
    #ifdef MIDFILE_PLAY_SUPPORT    
        if (mma_type == MMA_TYPE_MIDI)
        {
            JMA_CS_LEAVE(-1);
        }
    #endif /* MIDFILE_PLAY_SUPPORT */  
    
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);     
        
   // #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            /* seek time should be bound in duration */
            if (audio_player->duration != -1 && 
                now > audio_player->duration)
            {
                now = audio_player->duration;            
            }
            
            /* Save to current time */
            audio_player->current_time = now;
        
            JMA_CS_LEAVE(now);        
        }
    //#endif /* __MMI_BACKGROUND_CALL__ */

        if (audio_player->is_midi_device) /* midi device */
        {
            JMA_CS_LEAVE(0);
        }
        
        /* BUFFERING, PAUSED_BUFFERING state is for pdl player */
        /* Do not change the original state: playing */
        if (audio_player->state == JAVA_MEDIA_STATE_PLAYING)
        {
            ms = media_mma_aud_stop(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
            audio_player->sequence_id ++; 
        }
        else if (audio_player->state == JAVA_MEDIA_STATE_PAUSED)
        {
            ms = media_mma_aud_stop(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
            audio_player->sequence_id ++;
            audio_player->state = JAVA_MEDIA_STATE_STOPPED_PAUSED;
        }
        else if (audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer); 
        }
        else if (audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING)
        {
            ms = media_mma_aud_stop(JMA_MOD_ID, audio_player->handle, mma_type);
            audio_player->sequence_id ++;
            audio_player->state = JAVA_MEDIA_STATE_BUFFERING;
            
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer); 
        }
    
        /* PDL or duration is not available */
        if (audio_player->player.progressive_dl == KAL_TRUE ||
            audio_player->duration == -1)
        {
            /* Get Duration when download finish */
            duration = media_mma_aud_get_duration(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, duration);
            if (duration == 0)
            {
                duration = -1;
            }
            audio_player->duration = duration; 
        }         
    
        /* seek time should be bound in duration */
        if (audio_player->duration != -1 && 
            now > audio_player->duration)
        {
            now = audio_player->duration;            
        }
        
        /* Save to current time */
        audio_player->current_time = now;
        
        ms = media_mma_aud_set_start_time(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type, (kal_int32) now);

        /* Resume to original state */
        if (audio_player->player.progressive_dl)
        {
            if (audio_player->state == JAVA_MEDIA_STATE_PLAYING)
            {
                /* Change state to BUFFEREING to do play action. */
                kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_BUFFERING);
                audio_player->state = JAVA_MEDIA_STATE_BUFFERING;
                jma_audio_player_cache_buffering_cyclic();
            }
            /* PAUSED_BUFFERING state has been changed to BUFFERING */
            else if (audio_player->state == JAVA_MEDIA_STATE_BUFFERING)
            {
                jma_audio_player_cache_buffering_cyclic();
            }
        }
        else /* Not progressive download case */
        {
            if (audio_player->state == JAVA_MEDIA_STATE_PLAYING)
            {
                ms = media_mma_aud_play(JMA_MOD_ID, audio_player->handle, mma_type);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_player->sequence_id);

                if (ms == MED_RES_OK)
                {
                    JMA_CS_LEAVE(now);
                }
                else if (ms == MED_RES_END_OF_FILE)
                {
                    jma_audio_eom_handler(mma_type, audio_player);
                    JMA_CS_LEAVE(now);
                }
                else
                {
                    JMA_CS_LEAVE(-1);
                }
            }
        }
       
        JMA_CS_LEAVE(now);
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
        if (audio_player)
        {
            if (audio_player->is_midi_device) /* midi device */
            {
                JMA_CS_LEAVE(0);
            }
            
            /* seek time should be bound in duration */
            if (audio_player->duration != -1 && now > audio_player->duration)
            {
                now = audio_player->duration;            
            }
            audio_player->current_time = now;
            JMA_CS_LEAVE(now);
        }
    }
    #endif
    
    JMA_CS_LEAVE(-1);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_media_time
 * DESCRIPTION
 *  This function submit AudioGetMediaTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  long - current_time
 *****************************************************************************/
kal_int64 jma_mvm_audio_player_get_media_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 current_time = 0;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_GET_MEDIA_TIME, vm_id, mma_type, java_player);

    JMA_AUDIO_CS_ENTER(vm_id, -1); 
    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)
    {
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        
    //#ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            JMA_CS_LEAVE(audio_player->current_time);
        }
    //#endif /* __MMI_BACKGROUND_CALL__ */

        if (audio_player->is_midi_device) /* midi device */
        {
            JMA_CS_LEAVE(0);
        }
        
        /* If not at Playing state, return kept-value */
        if (audio_player->state == JAVA_MEDIA_STATE_PLAYING)
        {
            //ASSERT(audio_player->handle != 0);
            if (audio_player->handle == 0) 
            {
                JMA_CS_LEAVE(0);
            }
            current_time = media_mma_aud_get_current_time(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
            audio_player->current_time = current_time;
        }
        else if (audio_player->play_finish_time != 0) /* for play finish */
        {
            current_time = audio_player->play_finish_time;
        }
        else 
        {
            current_time = audio_player->current_time;
        }
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
        if (audio_player)
        {
            if (audio_player->is_midi_device) /* midi device */
            {
                JMA_CS_LEAVE(0);
            }
            current_time = audio_player->current_time;
        }
        else
        {
            JMA_CS_LEAVE(-1);
        }
    }
    #endif

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)current_time);

    JMA_CS_LEAVE(current_time);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_duration_by_data
 * DESCRIPTION
 *  This function submit AudioGetDuration request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  data            [?]         
 *  count           [IN]        
 * RETURNS
 *  long - duration
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_get_duration_by_content(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 count, kal_char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 duration = 0;
    kal_int32 handle;
    kal_int32 result;
    mma_player_struct player;
#ifdef __DRM_SUPPORT__    
    kal_bool is_permitted;
#endif     
    kal_bool is_single_over = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_GET_DURATION_BY_CONTENT, vm_id, mma_type, java_player);

    JMA_AUDIO_CS_ENTER(vm_id, 0); 
    /* Audio player, audio recorder, video player, camera, video recorder are multual exclusive */
#ifdef SUPPORT_JSR_135_VIDEO
		if (jma_audio_recorder_is_active(vm_id) || jma_video_player_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#else
		if (jma_audio_recorder_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#endif
  
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(0);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

#ifdef __DRM_SUPPORT__     
    /* Check drm right */
    if (filename != NULL && jam_drm_is_drm_file((kal_wchar*)filename))
    {
        is_permitted = jam_drm_check_right(
                        (kal_wchar*)filename, 
                        DRM_PERMISSION_PLAY);
        if (!is_permitted)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }                          
#endif /* __DRM_SUPPORT__ */
#ifdef __JMA_PREEMPT_PLAYER__
    if (vm_id == jam_mvm_get_current_vm_id())
    {
        if (!jma_mvm_audio_player_preempt_players(vm_id, mma_type, filename))
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }
#endif
    /* single player */
    if (filename != NULL || jma_audio_player_is_single_player(mma_type))
    {
        if (jma_audio_player_is_active())
        {
            JMA_CS_LEAVE(0);
        }
        is_single_over = KAL_TRUE;
    }
    else /* Multiple player */
    {        
        /* Check if single player is closed */
        if (mma_audio_player[JAVA_AUDIO_SINGLE].id != INVALID_JPLAYER_ID)
        {
            JMA_CS_LEAVE(0);
        }
    }

    memset((kal_uint8 *) &player, 0, sizeof(mma_player_struct));
    player.handler = (med_handler) &jma_audio_event_hdlr;
    player.media_type = mma_type; 
    player.repeats = 1;    

    /* Do not copy data */
    if (filename == NULL)
    {
        if(!jma_audio_player_parse_data(mma_type, data, count, &player))
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(0);
        }
    }
    else
    { 
        player.file_path = (kal_wchar *) filename;
    } 
  
    handle = media_mma_aud_open(JMA_MOD_ID, &player, &result);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, handle);

    if (handle == NULL)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        if (player.data != NULL)
        {
            jvm_free(player.data);
            player.data = NULL;
        }
        #ifdef __JMA_PREEMPT_PLAYER__
        jma_mvm_audio_player_resume_preempted_players(INVALID_JVM_ID, INVALID_JAVA_PLAYER, mma_type, is_single_over);
        #endif
        JMA_CS_LEAVE(0);
    }
    
    /* Get duration by handle */
    duration = media_mma_aud_get_duration(JMA_MOD_ID, handle, (kal_uint8) mma_type);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, duration);
    if (duration == 0)
    {
        duration = -1;
    }
    
    media_mma_aud_close(JMA_MOD_ID, handle, (kal_uint8) mma_type);
    handle = NULL;
    if (player.data != NULL)
    {
        jvm_free(player.data);
        player.data = NULL;
    }
#ifdef __JMA_PREEMPT_PLAYER__
    jma_mvm_audio_player_resume_preempted_players(INVALID_JVM_ID, INVALID_JAVA_PLAYER, mma_type, is_single_over);
#endif
    JMA_CS_LEAVE(duration);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_duration
 * DESCRIPTION
 *  This function submit AudioGetDuration request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  long - duration
 *****************************************************************************/
kal_int64 jma_mvm_audio_player_get_duration(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int64 duration = 0;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_GET_DURATION, vm_id, mma_type, java_player);
    JMA_AUDIO_CS_ENTER(vm_id, -1); 
        
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(-1);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);

        if (audio_player->is_midi_device) /* midi device */
        {
            JMA_CS_LEAVE(0);
        }
        /* function call base */
        duration = (S64) media_mma_aud_get_duration(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type);
        if (duration == 0)
        {
            duration = -1;
        }
        audio_player->duration = (kal_int32) duration;
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
        if (audio_player)
        {
            duration = audio_player->duration;
        }
        else
        {
            JMA_CS_LEAVE(-1);
        }
    }
    #else
    JMA_CS_LEAVE(-1);
    #endif
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)duration);

    JMA_CS_LEAVE(duration);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_set_volume
 * DESCRIPTION
 *  This function submit AudioSetVolume request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  vol             [IN]        
 * RETURNS
 *  iVolume set
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_set_volume(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 vol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 ms = 1;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_SET_VOLUME, vm_id, mma_type, java_player, vol);

    JMA_AUDIO_CS_ENTER(vm_id, 0); 
    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        audio_player->volume = vol;
        
   // #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            JMA_CS_LEAVE(vol);
        }
   // #endif /* __MMI_BACKGROUND_CALL__ */
    
        ms = media_mma_aud_set_volume(JMA_MOD_ID, 
                audio_player->handle,
                (kal_uint8) mma_type,
                audio_player->volume);

        if (ms == MED_RES_OK)
        {
            JMA_CS_LEAVE(vol);
        }
        else
        {
            JMA_CS_LEAVE(0);
        }

    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
        if (audio_player)
        {
            audio_player->volume = vol;
        }
    }
    #endif

    JMA_CS_LEAVE(0);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_info
 * DESCRIPTION
 *  This function submit get AudioInfo request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  audio_info      [OUT] the memory is allocated/de-allocated at kni level       
 * RETURNS
 *  true if success
 *****************************************************************************/
kal_bool jma_mvm_audio_player_get_info(kal_int32 vm_id, kal_int32 mma_type, kal_wchar* file_path, kal_uint8* data, kal_uint32 data_len, audInfoStruct *audio_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ms = 1;
#ifdef __DRM_SUPPORT__    
    kal_bool is_permitted;
#endif 

#if defined(__META_DATA_PARSE_API__)
    kal_uint8 ret = 0;
    kal_uint8* meta_parser_buf = NULL;
    meta_tag_music_info_struct* music_info_p = NULL;
    kal_uint32 meta_parser_hdlr = 0;
    meta_tag_txt_frame_struct *ptr;
    kal_uint32 len, ucs2_size;
#endif /* __META_DATA_PARSE_API__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_GET_INFO, vm_id, mma_type);

    JMA_AUDIO_CS_ENTER(vm_id, KAL_FALSE); 
    /* Audio player, audio recorder, video player, camera, video recorder are multual exclusive */
#ifdef SUPPORT_JSR_135_VIDEO
		if (jma_audio_recorder_is_active(vm_id) || jma_video_player_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#else
		if (jma_audio_recorder_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#endif
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

#ifdef __DRM_SUPPORT__     
    /* Check drm right */
    if (file_path != NULL && jam_drm_is_drm_file((kal_wchar*)file_path))
    {
        is_permitted = jam_drm_check_right(
                        (kal_wchar*)file_path, 
                        DRM_PERMISSION_PLAY);
        if (!is_permitted)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }                          
#endif /* __DRM_SUPPORT__ */

    /* single player */
    if (file_path != NULL || jma_audio_player_is_single_player(mma_type))
    {
        if (jma_audio_player_is_active())
        {
            #ifdef __JMA_PREEMPT_PLAYER__
            if (vm_id == jam_mvm_get_current_vm_id())
            {
                if (!jma_mvm_audio_player_preempt_players(vm_id, mma_type, (kal_char *)file_path))
                    JMA_CS_LEAVE(KAL_FALSE); // return true to avoid through exception
            
            }
            else
            {
                JMA_CS_LEAVE(KAL_FALSE);
            }
            #else
            JMA_CS_LEAVE(KAL_FALSE);
            #endif
        }
        
    }
    else /* Multiple player */
    {        
        /* Check if single player is closed */
        if (mma_audio_player[JAVA_AUDIO_SINGLE].id != INVALID_JPLAYER_ID)
        {
            #ifdef __JMA_PREEMPT_PLAYER__
            if (vm_id == jam_mvm_get_current_vm_id())
            {
                if (!jma_mvm_audio_player_preempt_players(vm_id, mma_type, (kal_char *)file_path))
                    JMA_CS_LEAVE(KAL_FALSE); // return true to avoid through exception
            
            }
            else
            {
                JMA_CS_LEAVE(KAL_FALSE);
            }
            #else
            JMA_CS_LEAVE(KAL_FALSE);
            #endif
        }
    }

#if defined(__META_DATA_PARSE_API__)
    if (file_path != NULL)
    {
        meta_parser_buf = jvm_malloc(META_TAG_PARSE_MIN_SIZE);
        if (meta_parser_buf == NULL)
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }

        ret = meta_parser_create(meta_parser_buf, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);        
        if (ret != META_TAG_ERR_NONE)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, ret, __LINE__);
            jvm_free(meta_parser_buf);
            meta_parser_buf = NULL;
            kal_wsprintf(audio_info->title, "unknown");  
            JMA_CS_LEAVE(KAL_TRUE);
        }
        
        ret = meta_parse_file(meta_parser_hdlr, (kal_uint16*)file_path);
        if (ret != META_TAG_ERR_NONE)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, ret, __LINE__);
            meta_parser_release(meta_parser_hdlr);
            jvm_free(meta_parser_buf);
            meta_parser_buf = NULL;
            kal_wsprintf(audio_info->title, "unknown");  
            JMA_CS_LEAVE(KAL_TRUE);
        }

        ret = meta_get_music_info(meta_parser_hdlr, &music_info_p);
        if (ret != META_TAG_ERR_NONE)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, ret, __LINE__);
            meta_parser_release(meta_parser_hdlr);
            jvm_free(meta_parser_buf);    
            meta_parser_buf = NULL;
            kal_wsprintf(audio_info->title, "unknown");            
            JMA_CS_LEAVE(KAL_TRUE);
        }
        /* Title */
        ptr = &(music_info_p->txt_frame[META_TAG_FRAME_TITLE]);
        ucs2_size = ptr->data_size >> 1;
        len = (ucs2_size < MAX_DESCRIPTION) ? ucs2_size : MAX_DESCRIPTION;
        app_ucs2_strncpy((kal_int8 *)audio_info->title, (kal_int8 *)ptr->data, len);
        audio_info->title[len] = 0;
        /* Artist */
        ptr = &(music_info_p->txt_frame[META_TAG_FRAME_ARTIST]);
        ucs2_size = ptr->data_size >> 1;
        len = (ucs2_size < MAX_DESCRIPTION) ? ucs2_size : MAX_DESCRIPTION;
        app_ucs2_strncpy((kal_int8 *)audio_info->artist, (kal_int8 *)ptr->data, len);
        audio_info->artist[len] = 0;
        /* Author */
        ptr = &(music_info_p->txt_frame[META_TAG_FRAME_AUTHOR]);
        ucs2_size = ptr->data_size >> 1;
        len = (ucs2_size < MAX_DESCRIPTION) ? ucs2_size : MAX_DESCRIPTION;
        app_ucs2_strncpy((kal_int8 *)audio_info->author, (kal_int8 *)ptr->data, len);
        audio_info->author[len] = 0;
        /* Copyright */
        ptr = &(music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT]);
        ucs2_size = ptr->data_size >> 1;
        len = (ucs2_size < MAX_DESCRIPTION) ? ucs2_size : MAX_DESCRIPTION;
        app_ucs2_strncpy((kal_int8 *)audio_info->copyright, (kal_int8 *)ptr->data, len);
        audio_info->copyright[len] = 0;
        /* Album */
        ptr = &(music_info_p->txt_frame[META_TAG_FRAME_ALBUM]);
        ucs2_size = ptr->data_size >> 1;
        len = (ucs2_size < MAX_DESCRIPTION) ? ucs2_size : MAX_DESCRIPTION;
        app_ucs2_strncpy((kal_int8 *)audio_info->album, (kal_int8 *)ptr->data, len);
        audio_info->album[len] = 0;
        
        if (music_info_p->year >= 0)
        {
            app_ucs2_itoa(music_info_p->year, (kal_int8*)audio_info->date, 10);
        }

        meta_parser_release(meta_parser_hdlr);
        jvm_free(meta_parser_buf);        
    }
    else    
#endif /* __META_DATA_PARSE_API__ */
    {
        ms = media_mma_aud_get_audio_info(
                JMA_MOD_ID, 
                0,
                file_path, 
                (kal_uint8) mma_type, 
                data, 
                data_len, 
                audio_info);
    }   

    if(1 == ms)
    {
    	kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 543);
    }
            
    /* handle All NULL String case */
    if (mmi_ucs2strlen((S8 *) audio_info->title) == 0 && 
        mmi_ucs2strlen((S8 *) audio_info->copyright) == 0 &&
        mmi_ucs2strlen((S8 *) audio_info->date) == 0 && 
        mmi_ucs2strlen((S8 *) audio_info->artist) == 0)
    {  
        kal_wsprintf(audio_info->title, "unknown");
    }
    
    JMA_CS_LEAVE(KAL_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_set_stop_time
 * DESCRIPTION
 *  This function submit AudioSetStopTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  stime           [IN]        
 * RETURNS
 *  long - stop time set
 *****************************************************************************/
kal_int64 jma_mvm_audio_player_set_stop_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int64 stime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ms;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_SET_STOP_TIME, vm_id, mma_type, java_player, (kal_uint32)stime);
    JMA_AUDIO_CS_ENTER(vm_id, 0); 

    /* make sure not overflow: int */
    if (stime < 0)
    {
        stime = 0;
    }
    else if (stime > 0x7fffffff)	
    {
        stime = 0x7fffffff;
    }
    
    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, native_player, audio_player->state);
        audio_player->stoptime = stime;
        
  //  #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            JMA_CS_LEAVE(stime);
        }
  //  #endif /* __MMI_BACKGROUND_CALL__ */
    
        ms = media_mma_aud_set_stop_time(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type, (kal_int32) stime);
        if (ms == MED_RES_OK)
        {
            JMA_CS_LEAVE(stime);
        }
        else
        {
            JMA_CS_LEAVE(0);
        }

    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
        
        if (audio_player)
        {
            audio_player->stoptime = stime;
            
            JMA_CS_LEAVE(stime);
        }
    }
    #endif
    
    JMA_CS_LEAVE(0);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_is_active
 * DESCRIPTION
 *  This function check if any audio device is active.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool - true or false
 *****************************************************************************/
/* RecordControl */
kal_bool jma_audio_player_is_active()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JAVA_NO_OF_PLAYER; i++)
    {
        if (mma_audio_player[i].id != INVALID_JPLAYER_ID)
        {
            return KAL_TRUE;
        }
    }
    
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_is_alie
 * DESCRIPTION
 *  This function check if any java audio player acquire audio resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool - true or false
 *****************************************************************************/
/* RecordControl */
kal_bool jma_audio_player_is_alive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JAVA_NO_OF_PLAYER; i++)
    {
        if (mma_audio_player[i].handle != NULL)
        {
            return KAL_TRUE;
        }
    }
    
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_is_active
 * DESCRIPTION
 *  This function check if any audio device is active.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool - true or false
 *****************************************************************************/
/* RecordControl */
kal_bool jma_audio_is_vm_players_active(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JAVA_NO_OF_PLAYER; i++)
    {
        if (mma_audio_player[i].id != INVALID_JPLAYER_ID &&
            mma_audio_player[i].vm_id == vm_id)
        {
            return KAL_TRUE;
        }
    }
    
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_is_playing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jma_audio_player_is_playing(
            kal_int8 *fmgr_path, 
            kal_int8 is_folder, 
            kal_bool is_delete_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 fmgr_path_length = (kal_uint32)mmi_ucs2strlen((kal_char *)fmgr_path);
    audio_player_struct *player_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!jma_audio_enable)
    {
        return KAL_FALSE;
    }

    player_p = &mma_audio_player[JAVA_AUDIO_SINGLE];
    if (player_p->id == INVALID_JPLAYER_ID)
    {
        return KAL_FALSE;
    }

    if(is_folder)
    {
        if(mmi_ucs2ncmp((kal_char *)player_p->player.file_path, (kal_char *)fmgr_path, fmgr_path_length) == 0)
        {
            return KAL_TRUE;
        }
    }
    else
    {
        if (mmi_ucs2cmp((kal_char *)player_p->player.file_path, (kal_char *)fmgr_path) == 0)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_is_really_active()
 * DESCRIPTION
 *  This function check if any audio device is really active.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool - true or false
 *****************************************************************************/
kal_bool jma_audio_player_is_really_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jma_audio_enable && jma_audio_player_is_active())
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_concurrent_count
 * DESCRIPTION
 *  Get the concurrent playing players' count.
 * PARAMETERS
 *  count [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
/* RecordControl */
static void jma_audio_player_get_concurrent_count(kal_uint32 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_GET_CONCURRENT_COUNT);
    *count = 0;
    for (i = 0; i < JAVA_NO_OF_PLAYER; i++)
    {
        if (mma_audio_player[i].id != INVALID_JPLAYER_ID)
        {
            (*count)++;
        }
    }
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, *count, MMA_MAX_NUM);
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_is_single_player
 * DESCRIPTION
 *  This function opens audio 
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  filename        [?]         
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_audio_player_is_single_player(kal_int32 mma_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mma_type)
    {
        case MMA_TYPE_MIDI:
        case MMA_TYPE_TONE:
        case MMA_TYPE_WAV:
        case MMA_TYPE_IMY:
            return KAL_FALSE;
            //break;
        default:
            break;
    }
    return KAL_TRUE;
   
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_register_callback
 * DESCRIPTION
 *  This function register handler
 * PARAMETERS
 *       
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void jma_audio_player_register_callback(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_REGISTER_CALLBACK);
    
    if (jam_mvm_get_vm_state(vm_id) != JVM_FG_RUNNING_STATE ||
        jam_mvm_get_vm_state(vm_id) != JVM_FG_MMI_RUNNING_STATE)
    {
        /* register callback function */
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_JAVA, jma_audio_player_background_callback, NULL);
    }
    /* Register interrupt callback function */
    mdi_audio_start_use_by_other_task(jma_audio_player_interrupt_callback, NULL);
#ifdef J2ME_SUPPORT_BACKGROUND    
    /* Update Java icon */
    if(jam_mvm_is_vm_support_bg(vm_id))
    {
        jui_widget_update_vm_bg_status_audio_icon(KAL_TRUE, vm_id);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_clear_callback
 * DESCRIPTION
 *  This function clears callback handler
 * PARAMETERS
 *       
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void jma_audio_player_clear_callback(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_CLEAR_CALLBACK);

    /* Clear callback only when all vm_id's player is closed */
    if (!jma_audio_player_is_active())
    {
        /* Clear interrupt callback */
        mdi_audio_stop_use_by_other_task();
    }
    if (!jma_audio_is_vm_players_active(vm_id))
    {
    #ifdef J2ME_SUPPORT_BACKGROUND
        /* Update Java icon */
	    if(jam_mvm_is_vm_support_bg(vm_id))
	    {
            jui_widget_update_vm_bg_status_audio_icon(KAL_FALSE, vm_id);
	    }
    #endif
    }
}


#if defined(SUPPORT_MMAPI) || defined(JSR135_AUDIO_BASIC_FEATURE)

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_cache_buffering_cyclic
 * DESCRIPTION
 *  This function is buffering cyclic handler 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jma_audio_player_cache_buffering_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 dl_percentage = 0;
    int ticks = kal_milli_secs_to_ticks(200); /* 200 ms */
    kal_bool ret = KAL_TRUE;
    audio_player_struct *audio_player;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_CACHE_BUFFERING_CYCLIC, mma_audio_player[JAVA_AUDIO_SINGLE].state);

    audio_player = &mma_audio_player[JAVA_AUDIO_SINGLE];     

    JMA_AUDIO_CS_ENTER(audio_player->vm_id, KAL_FALSE);  
    
    media_mma_aud_pdl_get_buf_percent(JMA_MOD_ID, audio_player->handle, 5, &dl_percentage);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, dl_percentage);

    /* Buffer is enough, play directly */
    if (dl_percentage == 100)
    {
        ret = jma_audio_player_play_internal(audio_player);
        if (ret == KAL_FALSE)
        {
            jma_audio_player_close(audio_player->player.media_type, audio_player->id);
        }
    }
    else
    {
        /* Start a timer to ask download percentage */
        EXT_ASSERT(audio_player->state == JAVA_MEDIA_STATE_BUFFERING ||
               audio_player->state == JAVA_MEDIA_STATE_PAUSED_BUFFERING, 0, 0, 0);

        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
        stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_AUDIO_PDL_PLAYER, ticks); 
    }      
    JMA_CS_LEAVE(ret);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_cache_open
 * DESCRIPTION
 *  This function opens file
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  data            [?]   
 *  count           [IN]
 * RETURNS
 *  kal_bool - true or false
 *****************************************************************************/
kal_bool jma_mvm_audio_player_cache_open(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audio_player_struct *audio_player;
    kal_int32 result;
    kal_uint32 written;
    kal_uint32 size;
    kal_wchar *aud_ptr = NULL;
    kal_wchar tmp_wstr[10];
    U8 buf[(5 + 1) * ENCODING_LENGTH];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_CACHE_OPEN, vm_id, mma_type, java_player);
    JMA_AUDIO_CS_ENTER(vm_id, KAL_FALSE); 

    /* Audio player, audio recorder, video player, camera, video recorder are multual exclusive */
#ifdef SUPPORT_JSR_135_VIDEO
		if (jma_audio_recorder_is_active(vm_id) || jma_video_player_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#else
		if (jma_audio_recorder_is_active(vm_id))
		{
			JMA_CS_LEAVE(KAL_FALSE);
		}
#endif

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    aud_ptr = jvm_malloc(MAX_MEDIA_FILE_NAME * 2);
    if (aud_ptr == NULL)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
#ifdef __JMA_PREEMPT_PLAYER__
    /* FG vm needs to preempt BG vm's players */
    if (vm_id == jam_mvm_get_current_vm_id())
    {
        if (!jma_mvm_audio_player_preempt_players(vm_id, mma_type, (kal_char *)aud_ptr))
            JMA_CS_LEAVE(KAL_TRUE); // to avoid through exception, so return true
    }
#endif
    if (jma_audio_player_is_active())
    {
        if (NULL != aud_ptr)
        {
            jvm_free(aud_ptr);
            aud_ptr = NULL;
        }
        JMA_CS_LEAVE(KAL_FALSE);
    }

    audio_player = &mma_audio_player[JAVA_AUDIO_SINGLE];
    audio_player->device_type = JAVA_MEDIA_SINGLE_DEVICE;
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, JAVA_AUDIO_SINGLE, audio_player->state);
    
    if (audio_player->state == JAVA_MEDIA_STATE_NULL)
    {
        jma_video_player_get_hidden_folder(aud_ptr);
        jma_video_player_encode_file_path_with_num(aud_ptr, vm_id, (kal_char *)buf, 10);
        memset(buf, 0x00, sizeof(buf));
        jma_video_player_encode_file_path_with_num(aud_ptr, java_player, (kal_char *)buf, 10);
        mmi_ucs2cat((PS8) aud_ptr, (PS8) L"cache.");
        mmi_asc_to_ucs2((S8 *) tmp_wstr, (S8 *) ext_name[mma_type]);
        mmi_ucs2cat((PS8) aud_ptr, (S8 *) tmp_wstr);
        
        /* Open cache file and write the first data package */
        audio_player->cache_handle = FS_Open(aud_ptr, FS_READ_WRITE | FS_OPEN_SHARED | FS_CREATE_ALWAYS);
        if (audio_player->cache_handle <= 0)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_player->cache_handle);
            JMA_CS_LEAVE(KAL_FALSE);
        }

        result = FS_Write(audio_player->cache_handle, (char*) data, count, &written);
        if (result != FS_NO_ERROR)
        {            
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
            /* Close cache file */
            result = FS_Close(audio_player->cache_handle);
            audio_player->cache_handle = NULL;
            /* Delete cache file */
            result = FS_Delete(aud_ptr);
            if (result != FS_NO_ERROR)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
            }
            JMA_CS_LEAVE(KAL_FALSE);
        }
        result = FS_GetFileSize(audio_player->cache_handle, &size);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDD, count, written, size);

        memset((kal_uint8 *) &audio_player->player, 0, sizeof(mma_player_struct));
        audio_player->player.handler = (med_handler) &jma_audio_event_hdlr;
        audio_player->player.file_path = aud_ptr;
        audio_player->player.media_type = mma_type;
        audio_player->player.repeats = 1;
        audio_player->player.progressive_dl = KAL_TRUE; 
        audio_player->player.output_path = MDI_DEVICE_SPEAKER2;
        
        audio_player->handle = media_mma_aud_open(JMA_MOD_ID, &(audio_player->player), &result);
        audio_player->aud_id = g_aud_id ++;        
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, audio_player->handle, audio_player->aud_id);
        if (audio_player->handle == NULL)
        {
            /* Close cache file */
            result = FS_Close(audio_player->cache_handle);
            audio_player->cache_handle = NULL;
            /* Delete cache file */
            result = FS_Delete((kal_wchar *) aud_ptr);
            if (result != FS_NO_ERROR)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
            }
            JMA_CS_LEAVE(KAL_FALSE);
        }

        /* MED would set mute when play dummy audio for pure video */
        jam_set_aud_volume_level(jam_get_aud_volume_level());
        
        /* Succeed to acquire resource */
        jma_register_device(
            audio_player->device_type,
            vm_id,
            java_player, 
            &jma_audio_suspend_hdlr, 
            &jma_audio_resume_hdlr, 
            &jma_audio_close_hdlr);

        /* Register Callback function */
        jma_audio_player_register_callback(vm_id);
    #if defined(__MMI_BT_AUDIO_VIA_SCO__)
        jma_media_player_connect_bt_via_sco(NULL);
    #endif    
    #if defined(__BES_TS_SUPPORT__)
        result = media_stretch_check_file_format(JMA_MOD_ID, audio_player->player.file_path);
        audio_player->support_time_stretch = (result == MED_RES_OK) ? KAL_TRUE : KAL_FALSE;
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_player->support_time_stretch);
    #endif 
            
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_player->state, JAVA_MEDIA_STATE_READY);
        
        audio_player->duration = -1;
        audio_player->current_time = 0;
        audio_player->play_finish_time = 0;
        audio_player->state = JAVA_MEDIA_STATE_READY;
        audio_player->vm_id = vm_id;
        audio_player->id = java_player;
        audio_player->stoptime = -1;
        audio_player->volume = DEFAULT_AUDIO_VOLUME;
        audio_player->sequence_id = 0;

    }

    JMA_CS_LEAVE(KAL_TRUE);
}



/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_cache_write
 * DESCRIPTION
 *  This function writes file
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  data            [?]   
 *  count           [IN]
 * RETURNS
 *  int - true or false
 *****************************************************************************/
kal_bool jma_mvm_audio_player_cache_write(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 written;
    audio_player_struct *audio_player;
    kal_uint32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_CACHE_WRITE, vm_id, mma_type, java_player);

    if (mma_audio_player[JAVA_AUDIO_SINGLE].id != java_player)
    {
        return KAL_FALSE;
    }

    /* Cache Write does not access media resource */
    
    audio_player = &mma_audio_player[JAVA_AUDIO_SINGLE];
    #ifdef __JMA_PREEMPT_PLAYER__
    if (vm_id != audio_player->vm_id || java_player != audio_player->id)
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
    }
    #endif
    if (!audio_player)
    {
        return KAL_FALSE;
    }
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, JAVA_AUDIO_SINGLE, audio_player->state);

    if (audio_player->cache_handle == NULL)
    {
        return KAL_FALSE;
    }
    
    result = FS_Write(audio_player->cache_handle, (char*) data, count, &written);
    if (result != FS_NO_ERROR)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
        return KAL_FALSE;
    }
    result = FS_GetFileSize(audio_player->cache_handle, &size);

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, count, size);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_cache_close
 * DESCRIPTION
 *  This function closes cache file, not closes player
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  kal_bool - true or false
 *****************************************************************************/
kal_bool jma_mvm_audio_player_cache_close(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 size;
    audio_player_struct *audio_player;
    kal_int32 ms;
    kal_bool is_preempted = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_CACHE_CLOSE, vm_id, mma_type, java_player);

    if (mma_audio_player[JAVA_AUDIO_SINGLE].id != java_player)
    {
        return KAL_FALSE;
    }

    audio_player = &mma_audio_player[JAVA_AUDIO_SINGLE];
    #ifdef __JMA_PREEMPT_PLAYER__
    if (vm_id != audio_player->vm_id || java_player != audio_player->id)
    {
        is_preempted = KAL_TRUE;
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
    }
    #endif
    if (!audio_player)
    {
        return KAL_FALSE;
    }
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_NPLAYER_STATE, JAVA_AUDIO_SINGLE, audio_player->state);

    if (audio_player->cache_handle == NULL)
    {
        return KAL_FALSE;
    }

    /* The part does not access media resource */
    result = FS_GetFileSize(audio_player->cache_handle, &size);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, size);
    /* close cache file */
    result = FS_Close(audio_player->cache_handle);
    if (result == FS_NO_ERROR)
    {
        audio_player->cache_handle = NULL;
    }
    else
    {
        return KAL_FALSE;
    }    
    
    /* for preempted player, it would notify med when resumed */
    if (is_preempted)
    {
        return KAL_TRUE;
    }
    /* The part will access media resource */
    JMA_AUDIO_CS_ENTER(vm_id, KAL_TRUE); /* pretend cache_close successfully */
        
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    /* Call MED update function */
    ms = media_mma_aud_pdl_write_data_ind(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type, KAL_TRUE);
    
    if (ms == MED_RES_OK)
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    else
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
}

#if defined (JSR135_AUDIO_ADVANCED_FEATURE) && defined(__MED_MMA_EXTRA_CTRL__)
/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_set_pitch
 * DESCRIPTION
 *  This function submit MidiSetPitch request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  mst             [IN]        
 * RETURNS
 *  int - pitch set
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_set_pitch(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 mst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 ms = 1;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERSETPITCH, vm_id, mma_type, mst);

    JMA_AUDIO_CS_ENTER(vm_id, 0); 
    /* Set to valid range */
    if (mma_type == MMA_TYPE_TONE)  /* -100 <= valid range <= 100 */
    {
        if (mst > 100000)
        {
            mst = 100000;
        }
        else if (mst < -100000)
        {
            mst = -100000;
        }
        mst /= 1000; /* L1audio API unit: semitone for TONE, milli-semitone for MIDI */
    }
    else if (mma_type == MMA_TYPE_MIDI)
    {
        if (mst > 64000)
        {
            mst = 64000;
        }
        else if (mst < -64000)
        {
            mst = -64000;
        }
    }

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];        

        audio_player->is_setpitch = KAL_TRUE;
        audio_player->pitch = mst; 
        
   // #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            JMA_CS_LEAVE(mst);
        }
   // #endif /* __MMI_BACKGROUND_CALL__ */
    
        ms = media_mma_aud_set_pitch(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type, mst);
        mst = media_mma_aud_get_pitch(audio_player->handle, (kal_uint8) mma_type);

        if (mma_type == MMA_TYPE_TONE)
        {
            mst *= 1000;
        }
        if (ms == MED_RES_OK)
        {
            JMA_CS_LEAVE(mst);
        }
        else
        {
            JMA_CS_LEAVE(0);
        }
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);

        if (audio_player)
        {
            audio_player->is_setpitch = KAL_TRUE;
            audio_player->pitch = mst; 

            JMA_CS_LEAVE(mst);
        }
    }
    #endif
 
    JMA_CS_LEAVE(0);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_pitch
 * DESCRIPTION
 *  This function submit MidiGetPitch request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  int - pitch get
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_get_pitch(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mst = 0;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERGETPITCH, vm_id, mma_type, mst);
    JMA_AUDIO_CS_ENTER(vm_id, 0); 
    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];
        
   // #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            JMA_CS_LEAVE(audio_player->pitch);
        }
  //  #endif /* __MMI_BACKGROUND_CALL__ */
    
        /* function call base */
        mst = media_mma_aud_get_pitch(audio_player->handle, (kal_uint8) mma_type);
        if (mma_type == MMA_TYPE_TONE)
        {
            mst *= 1000;
        }
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, mst);
        JMA_CS_LEAVE(mst);
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
      
        if (audio_player)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_player->pitch);
            JMA_CS_LEAVE(audio_player->pitch);
        }
    }
    #endif

    JMA_CS_LEAVE(0);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_set_rate
 * DESCRIPTION
 *  This function submit MidiSetRate request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  milliRate       [IN]        
 * RETURNS
 *  int - rate set
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_set_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 milliRate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ms = 1;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;
    
#if defined(__BES_TS_SUPPORT__)
    kal_int32 play_speed[MDI_AUDIO_MAX_SPEED_NUM] = {
        MDI_AUDIO_SPEED_SLOW2,  /* 50 */
        MDI_AUDIO_SPEED_SLOW1,  /* 80 */
        MDI_AUDIO_SPEED_NORMAL, /* 100 */
        MDI_AUDIO_SPEED_FAST1,  /* 125 */
        MDI_AUDIO_SPEED_FAST2}; /* 160 */
    kal_int32 i, choose_speed = 0, diff, min_diff;
#endif    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_SET_RATE, vm_id, mma_type, java_player, milliRate);
    JMA_AUDIO_CS_ENTER(vm_id, 0); 
    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    
    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];

        /* midi, tone */
        if (mma_type == MMA_TYPE_MIDI || mma_type == MMA_TYPE_TONE)
        {
            /* Set bound */
            if (milliRate < 10000) 
            {
                milliRate = 10000;
            } 
            else if (milliRate > 1000000) 
            {
                milliRate = 1000000;
            }
            
      //  #ifdef __MMI_BACKGROUND_CALL__
            if (jma_media_player_is_in_background_call())
            {
                audio_player->play_speed = milliRate / 1000;
                JMA_CS_LEAVE(milliRate);
            }
      //  #endif /* __MMI_BACKGROUND_CALL__ */
        
            ms = media_mma_aud_set_rate(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type, milliRate);
            milliRate = media_mma_aud_get_rate(audio_player->handle, (kal_uint8) mma_type);
            audio_player->is_setrate = KAL_TRUE;
            audio_player->rate = milliRate;
            audio_player->play_speed = milliRate / 1000;
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, milliRate);
            JMA_CS_LEAVE(milliRate);
        }
        
    #if defined(__BES_TS_SUPPORT__)
        /* Other audio type */
        if (audio_player->support_time_stretch)
        {
            /* Change unit */
            milliRate /= 1000;

            /* Find the closest play speed */
            min_diff = 0x7fffffff;
            for (i=0; i < MDI_AUDIO_MAX_SPEED_NUM; i++)
            {
                diff = play_speed[i] - milliRate;
                diff = (diff > 0) ? diff : -diff;
                if (diff < min_diff)
                {
                    min_diff = diff;
                    choose_speed = play_speed[i];
                }
            }              
            
      //  #ifdef __MMI_BACKGROUND_CALL__
            if (jma_media_player_is_in_background_call())
            {
                audio_player->play_speed = choose_speed;
                JMA_CS_LEAVE(audio_player->play_speed * 1000);
            }
      //  #endif /* __MMI_BACKGROUND_CALL__ */
        
            /* If set speed as NORMAL, we need to close stretch */
            if (choose_speed != MDI_AUDIO_SPEED_NORMAL)
            {
                ms = media_stretch_set_speed(JMA_MOD_ID, (kal_uint16) choose_speed);
            }
            else
            {
                ms = media_stretch_close(JMA_MOD_ID);
            }
            
            if (ms == MED_RES_OK)
            {
                /* Update parameter */
                audio_player->play_speed = choose_speed;
            }

        }
    #endif    
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_player->play_speed * 1000);
        JMA_CS_LEAVE(audio_player->play_speed * 1000);       
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);

        if (audio_player == NULL)
        {
            /* player with id java_player is not found */
            JMA_CS_LEAVE(0);
        }
        if (MMA_TYPE_MIDI == mma_type || MMA_TYPE_TONE == mma_type)
        {
            /* Set bound */
            if (milliRate < 10000) 
            {
                milliRate = 10000;
            } 
            else if (milliRate > 1000000) 
            {
                milliRate = 1000000;
            }
        
            audio_player->is_setrate = KAL_TRUE;
            audio_player->rate = milliRate;
            audio_player->play_speed = milliRate / 1000;
            
            JMA_CS_LEAVE(milliRate);
        }
        
    #if defined(__BES_TS_SUPPORT__)
        /* Other audio type */
        if (audio_player->support_time_stretch)
        {
            /* Change unit */
            milliRate /= 1000;
            
            /* Find the closest play speed */
            min_diff = 0x7fffffff;
            for (i=0; i < MDI_AUDIO_MAX_SPEED_NUM; i++)
            {
                diff = play_speed[i] - milliRate;
                diff = (diff > 0) ? diff : -diff;
                if (diff < min_diff)
                {
                    min_diff = diff;
                    choose_speed = play_speed[i];
                }
            }              
            
            audio_player->play_speed = choose_speed;
            JMA_CS_LEAVE(audio_player->play_speed * 1000);            
        }
    #endif    
    }
    #else
    JMA_CS_LEAVE(0);
    #endif
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_rate
 * DESCRIPTION
 *  This function submit MidiGetRate request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  int - rate get
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_get_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 milliRate = 0;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_GET_RATE, vm_id, mma_type, java_player);
    JMA_AUDIO_CS_ENTER(vm_id, 0);

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);

    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player]; 


  //  #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            if (MMA_TYPE_MIDI == mma_type &&
                JAVA_MEDIA_SINGLE_DEVICE != audio_player->device_type)
            {
                milliRate = audio_player->rate;
            }
            else
            {
                milliRate = audio_player->play_speed * 1000; 
            }
            JMA_CS_LEAVE(milliRate);
        }
  //  #endif /* __MMI_BACKGROUND_CALL__ */
    
        if (MMA_TYPE_MIDI == mma_type &&
            JAVA_MEDIA_SINGLE_DEVICE != audio_player->device_type)
        {
            milliRate = media_mma_aud_get_rate(audio_player->handle, (kal_uint8) mma_type);
        }
        else
        {
            milliRate = audio_player->play_speed * 1000; 
        }
        
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, milliRate);
        JMA_CS_LEAVE(milliRate);
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
      
        if (audio_player == NULL)
        {
            /* player with id java_player is not found */
            JMA_CS_LEAVE(100000);
        }

        if (MMA_TYPE_MIDI == mma_type &&
            JAVA_MEDIA_SINGLE_DEVICE != audio_player->device_type)
        {
            milliRate = audio_player->rate;
        }
        else
        {
            milliRate = audio_player->play_speed * 1000; 
        }
        
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, milliRate);

        JMA_CS_LEAVE(milliRate);
    }
    #else
    JMA_CS_LEAVE(milliRate);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_max_rate
 * DESCRIPTION
 *  This function gets min play speed, unit: millirate 
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  stime           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_get_max_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 max_rate = 0;
    kal_int32 min_rate = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_GET_MAX_RATE, vm_id, mma_type, java_player);

    media_mma_aud_get_rate_range(mma_type, &max_rate, &min_rate);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, max_rate);
    
    return max_rate;
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_min_rate
 * DESCRIPTION
 *  This function gets min play speed, unit: millirate 
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  stime           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_get_min_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 max_rate = 0;
    kal_int32 min_rate = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_GET_MIN_RATE, vm_id, mma_type, java_player);

    media_mma_aud_get_rate_range(mma_type, &max_rate, &min_rate);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, min_rate);
    
    return min_rate;     
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_set_tempo
 * DESCRIPTION
 *  This function submit MidiSetTempo request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        Int milliRate
 *  milliTempo      [IN]        
 * RETURNS
 *  int - tempo set
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_set_tempo(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 milliTempo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ms = 1;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERSETTEMPO, vm_id, mma_type, milliTempo);
    JMA_AUDIO_CS_ENTER(vm_id, 0);

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    
    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player];       
        
   // #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            audio_player->tempo = milliTempo;
            JMA_CS_LEAVE(milliTempo);
        }
  //  #endif /* __MMI_BACKGROUND_CALL__ */
    
        ms = media_mma_aud_set_tempo(JMA_MOD_ID, audio_player->handle, (kal_uint8) mma_type, milliTempo);
        milliTempo = media_mma_aud_get_tempo(audio_player->handle, (kal_uint8) mma_type);

        if (ms == MED_RES_OK)
        {
            /* Keep the value */
            audio_player->tempo = milliTempo;
            JMA_CS_LEAVE(milliTempo);
        }
        else
        {
            JMA_CS_LEAVE(120000);
        }
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);

        if (audio_player == NULL)
        {
            /* player with id java_player is not found */
            JMA_CS_LEAVE(0);
        }

        audio_player->is_settempo = KAL_TRUE;

        audio_player->tempo = milliTempo;

        JMA_CS_LEAVE(milliTempo);

    }   
    #else
    JMA_CS_LEAVE(0);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_tempo
 * DESCRIPTION
 *  This function submit MidiGetTempo request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  int - tempo get
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_get_tempo(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 milliTempo = 120000;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *audio_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERGETTEMPO, vm_id, mma_type);
    JMA_AUDIO_CS_ENTER(vm_id, 0);

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    
    if (native_player != INVALID_NPLAYER_ID)    
    {
        audio_player = &mma_audio_player[native_player]; 
        
  //  #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            JMA_CS_LEAVE(audio_player->tempo);
        }
  //  #endif /* __MMI_BACKGROUND_CALL__ */
    
        /* function call base */
        milliTempo = media_mma_aud_get_tempo(audio_player->handle, (kal_uint8) mma_type);

        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, milliTempo);
        JMA_CS_LEAVE(milliTempo);
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        audio_player = jma_mvm_audio_locate_player(vm_id, java_player);
      
        if (audio_player == NULL)
        {
            /* player with id java_player is not found */
            milliTempo = 120000;
        }
        else
        {
            milliTempo = audio_player->tempo;
        }
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, milliTempo);

        JMA_CS_LEAVE(milliTempo);
    }
    #else
    JMA_CS_LEAVE(0);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_smf_tempo
 * DESCRIPTION
 *  This function submit MidiSetTempo request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  data            [?]         
 *  count           [IN]        
 * RETURNS
 *  int - tempo set
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_get_smf_tempo(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 milliTempo = 120000;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERGETSMFTEMPO, vm_id, mma_type);
    JMA_AUDIO_CS_ENTER(vm_id, 0);
        
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(120000);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    
    if (INVALID_NPLAYER_ID != native_player)
    {
        midi_player = &mma_audio_player[native_player];
        if (midi_player->handle)
        {
            milliTempo = media_mma_aud_get_tempo(midi_player->handle, (kal_uint8) mma_type);
        }
        else
        {
            milliTempo = midi_player->tempo;
        }
        
    }
    else
    {
        kal_int32 handle;
        med_result_enum result;
        
        /* Audio player, audio recorder, video player, camera, video recorder are multual exclusive */
#ifdef SUPPORT_JSR_135_VIDEO
			if (jma_audio_recorder_is_active(vm_id) || jma_video_player_is_active(vm_id))
			{
				JMA_CS_LEAVE(KAL_FALSE);
			}
#else
			if (jma_audio_recorder_is_active(vm_id))
			{
				JMA_CS_LEAVE(KAL_FALSE);
			}
#endif
        
        if (mma_audio_player[JAVA_AUDIO_SINGLE].id != INVALID_JPLAYER_ID)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, mma_audio_player[JAVA_AUDIO_SINGLE].id);
            JMA_CS_LEAVE(120000);
        }

#ifdef __JMA_PREEMPT_PLAYER__
        midi_player = jma_mvm_audio_locate_player(vm_id, java_player);
#endif
        if (midi_player)
        {
            /* for preempted player, return its tempo */
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, midi_player->tempo);
            JMA_CS_LEAVE(midi_player->tempo);
        }
        
        jma_mvm_audio_player_locate_resource(mma_type, &native_player);
        if (INVALID_NPLAYER_ID == native_player)
        {
            /* if active midi player's count > 4, then return directly */
            JMA_CS_LEAVE(120000);
        }
        
        memset((kal_uint8 *) &(midi_player->player), 0, sizeof(mma_player_struct));
        midi_player->player.handler = (med_handler) &jma_audio_event_hdlr;
        midi_player->player.media_type = MMA_TYPE_MIDI;
        midi_player->player.data = (kal_uint8*) data;
        midi_player->player.size = count;
        midi_player->player.file_path = NULL;
        midi_player->player.repeats = 1;
 
        handle = media_mma_aud_open(JMA_MOD_ID, &(midi_player->player), (kal_int32*) &result);

        if (handle)
        {
            midi_player->handle = handle;
            milliTempo = media_mma_aud_get_tempo(handle, (kal_uint8) mma_type);
            media_mma_aud_close(JMA_MOD_ID, handle, (kal_uint8) mma_type);
            handle = NULL;
        }
        else
        {
            sprintf(_kvmLogStr, "mma_MidiGetSMFTempo() open failed %d", (int)handle);
            Kputs(_kvmLogStr);
        }
    }

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, milliTempo);
    JMA_CS_LEAVE(milliTempo);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_send_long_message
 * DESCRIPTION
 *  This function submit MidiSendLongMsg request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  data            [?]         
 *  offset          [IN]        
 *  length          [IN]        
 * RETURNS
 *  int - length of msg
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_send_long_message(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 offset, kal_int32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 result = 1;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERLONGMSG, vm_id, mma_type, offset, length);
    JMA_AUDIO_CS_ENTER(vm_id, -1);

  //  #ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            JMA_CS_LEAVE(-1);
        }
  //  #endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    
    if (INVALID_NPLAYER_ID != native_player)
    {
        midi_player = &mma_audio_player[native_player];
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            JMA_CS_LEAVE(-1);
        }
        
        result = media_mma_aud_send_long_msg(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, (unsigned char*)data, (kal_uint16) length);

        if (MED_RES_OK == result)
        {
            JMA_CS_LEAVE(length);
        }
    }

    JMA_CS_LEAVE(-1);
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_send_short_message
 * DESCRIPTION
 *  This function submit MidiSendShortMsg request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  type            [IN]        
 *  data1           [IN]        
 *  data2           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_audio_player_send_short_message(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 type, kal_int32 data1, kal_int32 data2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    kal_int32 ms = 1;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERSHORTMSG, vm_id, mma_type, type, data1, data2);
    JMA_AUDIO_CS_ENTER(vm_id, JMA_VOID);
    
//#ifdef __MMI_BACKGROUND_CALL__
        if (jma_media_player_is_in_background_call())
        {
            JMA_CS_LEAVE(JMA_VOID);
        }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    
    if (native_player != INVALID_NPLAYER_ID)    
    {
        midi_player = &mma_audio_player[native_player];
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            JMA_CS_LEAVE(JMA_VOID);
        }
            
        ms = media_mma_aud_send_short_msg(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, (kal_uint8)type, (kal_uint8)data1, (kal_uint8)data2);
		if(1 == ms)
		{
		    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 666);
		}
    }

    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_channel_volume
 * DESCRIPTION
 *  This function submit MidiGetChannelVolume request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  channel         [IN]        
 * RETURNS
 *  int - volume
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_get_channel_volume(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 volume = -1;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERGETCHANNELVOLUME, vm_id, mma_type, channel);
    JMA_AUDIO_CS_ENTER(vm_id, -1);

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(-1);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
        
    if (native_player != INVALID_NPLAYER_ID)    
    {
        midi_player = &mma_audio_player[native_player];
        if ((NULL == midi_player->handle)  || (!midi_player->is_midi_device))
        {
            /* player with id java_player is not found or handle is NULL */
            JMA_CS_LEAVE(-1);
        }
    
        volume = media_mma_aud_get_channel_volume(midi_player->handle, (kal_uint8) mma_type, (kal_uint8) channel);
        if (volume < 0)
        {
            JMA_CS_LEAVE(-1);
        }

        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, volume);
    
        JMA_CS_LEAVE(volume);
    }
    
    /* player with id java_player is not found or handle is NULL */
    JMA_CS_LEAVE(-1);
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_set_channel_volume
 * DESCRIPTION
 *  This function submit MidiGetChannelVolume request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  channel         [IN]        
 * RETURNS
 *  int - volume
 *****************************************************************************/
void jma_mvm_audio_player_set_channel_volume(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel, kal_int32 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_SET_CHANNEL_VOLUME, vm_id, mma_type, channel, volume);
    JMA_AUDIO_CS_ENTER(vm_id, JMA_VOID);
    
    if ( channel < 0 || channel >= MAX_MIDI_CHANNEL)
    {
        JMA_CS_LEAVE(JMA_VOID);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(JMA_VOID);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    if (native_player != INVALID_NPLAYER_ID)    
    {
        midi_player = &mma_audio_player[native_player];
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            /* player with id java_player is not found or handle is NULL */
            JMA_CS_LEAVE(JMA_VOID);
        }
        
        midi_player->channel_volume[channel] = volume;
        midi_player->channel_volume_sets |= (1<<channel);

        media_mma_aud_set_channel_volume(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, (kal_uint8)channel, (kal_uint8)volume);
    
    }
    
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_bank_list_size
 * DESCRIPTION
 *  This function submit MidiGetBankList request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  custom          [IN]        
 * RETURNS
 *  int - volume
 *****************************************************************************/
kal_int16 jma_mvm_audio_player_get_bank_list_size(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_bool custom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 *banklist;
    kal_int16 len = 0;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERGETBANKLIST, vm_id, mma_type);
    JMA_AUDIO_CS_ENTER(vm_id, 0);

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(0);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    if (INVALID_NPLAYER_ID != native_player)
    {
        midi_player = &mma_audio_player[native_player];
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            /* player with id java_player is not found or handle is NULL */
            JMA_CS_LEAVE(0);
        }
        media_mma_aud_get_bank_list(midi_player->handle, (kal_uint8) mma_type, custom, (const kal_int16 **)&banklist, (kal_int16*) & len);

        JMA_CS_LEAVE(len);
    }
    
    /* player with id java_player is not found or handle is NULL */
    JMA_CS_LEAVE(0);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_custom_bank_list
 * DESCRIPTION
 *  This function submit MidiGetBankList request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  custom          [IN]        
 *  len             [?]         
 *  kal_bool(?)
 * RETURNS
 *  kal_int16* - bank_list
 *****************************************************************************/
/* exact the same as mma_MidiGetBankList */
kal_int16 *jma_mvm_audio_player_get_custom_bank_list(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_bool custom, kal_int16 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 *banklist = NULL;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERGETCUSTOMBANKLIST, vm_id, mma_type);
    JMA_AUDIO_CS_ENTER(vm_id, NULL);

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(banklist);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    if (INVALID_NPLAYER_ID != native_player)
    {
        midi_player = &mma_audio_player[native_player];
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            /* player with id java_player is not found or handle is NULL */
            JMA_CS_LEAVE(NULL);
        }
    
        media_mma_aud_get_bank_list(midi_player->handle, (kal_uint8) mma_type, custom, (const kal_int16 **)&banklist, len);

        JMA_CS_LEAVE(banklist);
    }
    
    /* player with id java_player is not found or handle is NULL*/
    JMA_CS_LEAVE(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_key_name
 * DESCRIPTION
 *  This function submit MidiGetKeyName request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  bank            [IN]        
 *  prog            [IN]        
 *  key             [IN]        
 *  len             [?]         
 * RETURNS
 *  kal_uint8 *name
 *****************************************************************************/
kal_uint8 *jma_mvm_audio_player_get_key_name(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 bank, kal_int32 prog, kal_int32 key, kal_int32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 *name = NULL;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_PLAYER_GET_KEY_NAME, vm_id, mma_type, bank, prog, key);
    JMA_AUDIO_CS_ENTER(vm_id, NULL);

    *len = 0;
 
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(NULL);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    if (INVALID_NPLAYER_ID != native_player)
    {
        midi_player = &mma_audio_player[native_player];
        
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            /* player with id java_player is not found or handle is NULL */
            JMA_CS_LEAVE(NULL);
        }
    
        name = (const kal_uint8 *) media_mma_aud_get_key_name(midi_player->handle, (kal_uint8) mma_type, (kal_int16) bank, (kal_int8) prog, (kal_int8) key);

        if (strcmp((char*)name, "") == 0)
        {
            *len = -1;
            JMA_CS_LEAVE(NULL);
        }
        else if (strncmp((char*)name, "Unknown", 6) == 0)
        {
            *len = 0;
            JMA_CS_LEAVE(NULL);
        }
    
        *len = strlen((char*)name);

        JMA_CS_LEAVE((kal_uint8 *)name);
    }
    
    /* player with id java_player is not found or handle is NULL */
    JMA_CS_LEAVE(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_program
 * DESCRIPTION
 *  This function submit MidiGetProgram request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  channel         [IN]        
 *  bank            [?]         
 *  program         [?]         
 * RETURNS
 *  int - 0 for successful, -1 for unsuccessful
 *****************************************************************************/
kal_int32 jma_mvm_audio_player_get_program(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel, kal_int16 *bank, kal_int8 *program)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERGETPROGRAM, vm_id, mma_type);
    JMA_AUDIO_CS_ENTER(vm_id, -1);
 
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(-1);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    if (INVALID_NPLAYER_ID != native_player)
    {
        midi_player = &mma_audio_player[native_player];
        
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            /* player with id java_player is not found or handle is NULL */
            JMA_CS_LEAVE(-1);
        }
    
        media_mma_aud_get_program(midi_player->handle, (kal_uint8) mma_type, (kal_uint8) channel, bank, program);
        JMA_CS_LEAVE(0);
    }

    /* player with id java_player is not found or handle is NULL */
    JMA_CS_LEAVE(-1);
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_set_program
 * DESCRIPTION
 *  This function submit MidiGetProgram request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  channel         [IN]        
 *  bank            [?]         
 *  program         [?]         
 * RETURNS
 *  int - 0 for successful, -1 for unsuccessful
 *****************************************************************************/
void jma_mvm_audio_player_set_program(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel, kal_int32 bank, kal_int32 program)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERSETPROGRAM, vm_id, mma_type);
    JMA_AUDIO_CS_ENTER(vm_id, JMA_VOID);
 
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(JMA_VOID);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    if (INVALID_NPLAYER_ID != native_player)
    {
        midi_player = &mma_audio_player[native_player];
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            /* player with id java_player is not found or handle is NULL */
            JMA_CS_LEAVE(JMA_VOID);
        }
    
        media_mma_aud_set_program(JMA_MOD_ID, midi_player->handle, (kal_uint8) mma_type, (kal_uint8) channel, (kal_uint8) bank, (kal_uint8) program);
        
    }
    #ifdef __JMA_PREEMPT_PLAYER__
    else
    {
        midi_player = jma_mvm_audio_locate_player(vm_id, java_player);
        if (NULL == midi_player)
        {
            JMA_CS_LEAVE(JMA_VOID);
        }
    }
    #else
    JMA_CS_LEAVE(JMA_VOID);
    #endif

    midi_player->is_setprogram = KAL_TRUE;
    midi_player->channel = channel;
    midi_player->program = program;
    midi_player->bank = bank;
    
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_program_list
 * DESCRIPTION
 *  This function submit MidiGetProgramList request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  bank            [IN]        
 *  len             [?]         
 * RETURNS
 *  int - 0 for successful, -1 for unsuccessful
 *****************************************************************************/
kal_int8 *jma_mvm_audio_player_get_program_list(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 bank, kal_int16 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 *program_list = NULL;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERGETPROGRAMLIST, vm_id, mma_type, bank);
    JMA_AUDIO_CS_ENTER(vm_id, NULL);
 
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(NULL);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */
    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    if (INVALID_NPLAYER_ID != native_player)
    {
        midi_player = &mma_audio_player[native_player];
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            /* player with id java_player is not found or handle is NULL */
            JMA_CS_LEAVE(NULL);
        }
        
        *len = 1;
    
        media_mma_aud_get_program_list(midi_player->handle, (kal_uint8) mma_type, (kal_int16) bank, (const kal_int8 **)&program_list, len);
        JMA_CS_LEAVE(program_list);
    }

    /* player with id java_player is not found or handle is NULL */
    JMA_CS_LEAVE(NULL);
    
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_get_program_name
 * DESCRIPTION
 *  This function submit MidiGetProgramName request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 *  bank            [IN]        
 *  prog            [IN]        
 *  len             [?]         
 * RETURNS
 *  kal_uint8 *name
 *****************************************************************************/
kal_uint8 *jma_mvm_audio_player_get_program_name(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 bank, kal_int32 prog, kal_int32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 *name = NULL;
    kal_int32 native_player = INVALID_NPLAYER_ID;
    audio_player_struct *midi_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIOPLAYERGETPROGRAMNAME, vm_id, mma_type, bank, prog);
    JMA_AUDIO_CS_ENTER(vm_id, NULL);

    *len = 0;
  
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(NULL);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */
    native_player = jma_audio_jplayer_to_nplayer(vm_id, java_player);
    if (INVALID_NPLAYER_ID != native_player)
    {
        midi_player = &mma_audio_player[native_player];
        if ((NULL == midi_player->handle) || (!midi_player->is_midi_device))
        {
            /* player with id java_player is not found or handle is NULL */
            JMA_CS_LEAVE(NULL);
        }
        name = (const kal_uint8 *) media_mma_aud_get_program_name(midi_player->handle, (kal_uint8) mma_type, (kal_int16) bank, (kal_int8) prog);

        if (name)
        {
            *len = strlen((char*)name);
        }
        JMA_CS_LEAVE((kal_uint8 *)name);
    }
    
    /* player with id java_player is not found or handle is NULL */
    JMA_CS_LEAVE(NULL);
}
#else /* #ifdef __MED_MMA_EXTRA_CTRL__ */
kal_int32 jma_mvm_audio_player_set_pitch(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 mst){}
kal_int32 jma_mvm_audio_player_get_pitch(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_set_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 milliRate){}
kal_int32 jma_mvm_audio_player_get_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_get_max_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_get_min_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_set_tempo(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 milliTempo){}
kal_int32 jma_mvm_audio_player_get_tempo(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_get_smf_tempo(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 count){}
kal_int32 jma_mvm_audio_player_send_long_message(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 offset, kal_int32 length){}
void jma_mvm_audio_player_send_short_message(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 type, kal_int32 data1, kal_int32 data2){}
kal_int32 jma_mvm_audio_player_get_channel_volume(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel){}
void jma_mvm_audio_player_set_channel_volume(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel, kal_int32 volume){}
kal_int16 jma_mvm_audio_player_get_bank_list_size(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_bool custom){}
kal_int16 *jma_mvm_audio_player_get_custom_bank_list(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_bool custom, kal_int16 *len){}
kal_uint8 *jma_mvm_audio_player_get_key_name(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 bank, kal_int32 prog, kal_int32 key, kal_int32 *len){}
kal_int32 jma_mvm_audio_player_get_program(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel, kal_int16 *bank, kal_int8 *program){}
void jma_mvm_audio_player_set_program(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel, kal_int32 bank, kal_int32 program){}
kal_int8 *jma_mvm_audio_player_get_program_list(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 bank, kal_int16 *len){}
kal_uint8 *jma_mvm_audio_player_get_program_name(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 bank, kal_int32 prog, kal_int32 *len){}
#endif /* #ifdef __MED_MMA_EXTRA_CTRL__ */
#else
kal_bool jma_mvm_audio_player_cache_open(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 count){}
kal_bool jma_mvm_audio_player_cache_write(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 count){}
kal_bool jma_mvm_audio_player_cache_close(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_set_pitch(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 mst){}
kal_int32 jma_mvm_audio_player_get_pitch(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_set_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 milliRate){}
kal_int32 jma_mvm_audio_player_get_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_get_max_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_get_min_rate(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_set_tempo(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 milliTempo){}
kal_int32 jma_mvm_audio_player_get_tempo(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_int32 jma_mvm_audio_player_get_smf_tempo(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 count){}
kal_int32 jma_mvm_audio_player_send_long_message(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *data, kal_int32 offset, kal_int32 length){}
void jma_mvm_audio_player_send_short_message(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 type, kal_int32 data1, kal_int32 data2){}
kal_int32 jma_mvm_audio_player_get_channel_volume(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel){}
void jma_mvm_audio_player_set_channel_volume(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel, kal_int32 volume){}
kal_int16 jma_mvm_audio_player_get_bank_list_size(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_bool custom){}
kal_int16 *jma_mvm_audio_player_get_custom_bank_list(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_bool custom, kal_int16 *len){}
kal_uint8 *jma_mvm_audio_player_get_key_name(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 bank, kal_int32 prog, kal_int32 key, kal_int32 *len){}
kal_int32 jma_mvm_audio_player_get_program(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel, kal_int16 *bank, kal_int8 *program){}
void jma_mvm_audio_player_set_program(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 channel, kal_int32 bank, kal_int32 program){}
kal_int8 *jma_mvm_audio_player_get_program_list(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 bank, kal_int16 *len){}
kal_uint8 *jma_mvm_audio_player_get_program_name(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 bank, kal_int32 prog, kal_int32 *len){}
#endif /* SUPPORT_MMAPI */ 
