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
 *   jma_audio_recorder.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines native JMA audio recorder APIs
 *
 * Author:
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * @(#)jma_audio_recorder.c   1.00 05/11/30
 *
 * Copyright (c) 2003 Institute for Information Industry.  All rights reserved.
 */

/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "MMI_features.h"

#include "jma_interface.h"
#include "jam_internal.h"
#include "jma_internal.h"
#include "j2me_trace.h"


#include "Unicodexdcl.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "FileManagerGProt.h"
#include "FileMgrSrvGProt.h"

/*************************************************************************
 * Global Definition and Declaration
 *************************************************************************/
stack_timer_struct java_media_timer;
#ifdef JSR135_AUDIO_RECORDER
/* Amr Recorder */
audio_recorder_struct audio_recorder[JVM_NUM];

#ifdef __MTK_TARGET__
extern kal_uint32 Media_GetRecordedTime(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_timer_expired
 * DESCRIPTION
 *  This function handles if audio recorder timer is expired
 * PARAMETERS
 *  mma_type            [IN]        
 *  java_recorder       [IN]        
 *  int reocrder(?)
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_recorder_timer_expired(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 record_size = 0;
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */  
    FS_HANDLE file_handle;
    kal_int32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_RECORDER_TIMER_EXPIRED, vm_id, audio_recorder[vm_id].id, audio_recorder[vm_id].state);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    if (audio_recorder[vm_id].state != JAVA_MEDIA_STATE_RECORDING)
    {
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    EXT_ASSERT(audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING, 0, 0, 0);

    /* Get file size */
    file_handle = FS_Open(audio_recorder[vm_id].filename, FS_READ_ONLY | FS_OPEN_SHARED);
    if (file_handle <= 0)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, file_handle);
        JMA_CS_LEAVE(JMA_VOID);
    }
    result = FS_GetFileSize(file_handle, &record_size);
    result = FS_Close(file_handle);
	if(1 == result)
	{
	    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, record_size+1);
	}
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, record_size);

    /* Reach record size limit */
    if (record_size >= audio_recorder[vm_id].record_size_limit)
    {
        /* State will be changed */
        jma_mvm_audio_recorder_commit(vm_id, audio_recorder[vm_id].id);        

        jvm_post_mma_event(MMA_EVENT_RECORD_STOPPED, 
            audio_recorder[vm_id].id, audio_recorder[vm_id].current_time);
    }
    else /* re-start timer */
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
        stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_AUDIO_RECORDER + vm_id, ticks);
    }
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_file_record_finish_ind_handler
 * DESCRIPTION
 *  This function handles audio files eom.
 * PARAMETERS
 *  mma_type        [IN]        
 *  ilm_ptr         [?]         
 * RETURNS
 *  kal_bool result
 *****************************************************************************/
void jma_audio_recorder_record_result_hdlr(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = jam_mvm_get_current_vm_id();;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_RECORDER_RECORD_RESULT_HDLR, vm_id, audio_recorder[vm_id].state, result);

    if (INVALID_JVM_ID == vm_id)
    {
        //ASSERT(0);
        return;
    }
    
    /* when stop record, a callback with MDI_AUDIO_TEMINATED will be called */
    JMA_CS_ENTER(vm_id, JMA_VOID);

    if (result == MDI_AUDIO_DISC_FULL)
    {
    #ifdef __MTK_TARGET__
        audio_recorder[vm_id].current_time = (long)Media_GetRecordedTime();
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_recorder[vm_id].current_time);
    #endif

        /* Restore audio recorder's state */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_READY);
        audio_recorder[vm_id].state = JAVA_MEDIA_STATE_READY;
        
        jvm_post_mma_event(MMA_EVENT_RECORD_STOPPED, audio_recorder[vm_id].id,
            (kal_int64) audio_recorder[vm_id].current_time);
    }
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_finalize
 * DESCRIPTION
 *  This function handles wav recorder close
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  int result
 *****************************************************************************/
void jma_audio_recorder_finalize(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_NULL);
    audio_recorder[vm_id].state = JAVA_MEDIA_STATE_NULL;
    jma_audio_recorder_reset_parameter(vm_id);
}

/*****************************************************************************
 * FUNCTION
 *  jma_wav_recorder_suspend_hdlr
 * DESCRIPTION
 *  This function handles wav recorder suspend
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  int result
 *****************************************************************************/
kal_int32 jma_audio_recorder_suspend_hdlr(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    java_media_state_enum original_state;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_RECORDER_SUSPEND_HDLR,
        vm_id, java_recorder, audio_recorder[vm_id].state);

    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    original_state = audio_recorder[vm_id].state;
    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        /* State will be changed to READY */
        jma_mvm_audio_recorder_reset(vm_id, java_recorder);        
    }

    /* Resume to original state */
    audio_recorder[vm_id].state = original_state;
    
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_wav_recorder_close_hdlr
 * DESCRIPTION
 *  This function handles wav recorder close
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  int result
 *****************************************************************************/
kal_int32 jma_audio_recorder_close_hdlr(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_RECORDER_CLOSE_HDLR,
        vm_id, java_recorder, audio_recorder[vm_id].state);

    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL); 
    }

    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        if (!is_vm_suspend_media[vm_id])
        {
            /* State will be changed to READY */
            jma_mvm_audio_recorder_reset(vm_id, java_recorder);
        }
        
        jvm_post_mma_event(MMA_EVENT_RECORD_ERROR,
           audio_recorder[vm_id].id, (kal_int64) MMA_ERR_MMI_INTERRUPT);
    }
    
    jma_deregister_device(JAVA_MEDIA_AUDIO_RECORDER, vm_id, java_recorder);
    jma_audio_recorder_finalize(vm_id);        

    JMA_CS_LEAVE(RESOUCE_NO_ERROR); 
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_resume_hdlr
 * DESCRIPTION
 *  This function handles wav recorder forec resume
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  int result
 *****************************************************************************/
kal_int32 jma_audio_recorder_resume_hdlr(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_RECORDER_RESUME_HDLR,
        vm_id, java_recorder, audio_recorder[vm_id].state);

    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_READY);
        audio_recorder[vm_id].state = JAVA_MEDIA_STATE_READY;

        jvm_post_mma_event(MMA_EVENT_RECORD_ERROR,
            audio_recorder[vm_id].id,
            (kal_int64) MMA_ERR_MMI_INTERRUPT);
    }
    
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_reset_parameter
 * DESCRIPTION
 *  This function resets parameters
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_recorder_reset_parameter(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_RECORDER_RESET_PARAMETER, vm_id, audio_recorder[vm_id].state);

    audio_recorder[vm_id].state = JAVA_MEDIA_STATE_NULL;
    audio_recorder[vm_id].format = MED_TYPE_NONE;
    mmi_ucs2cpy((PS8) audio_recorder[vm_id].filename, "");
    audio_recorder[vm_id].record_timer = &java_media_timer;
    audio_recorder[vm_id].id = INVALID_JPLAYER_ID;
    audio_recorder[vm_id].current_time = 0; 
    audio_recorder[vm_id].record_size_limit = -1;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_reset
 * DESCRIPTION
 *  The function erases recorded content
 * PARAMETERS
 *  mma_type            [IN]        
 *  java_recorder       [IN]  
 * RETURNS
 *  int - 0
 *****************************************************************************/
kal_bool jma_mvm_audio_recorder_reset(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result ret;
    kal_int32 file_handle;
    kal_int32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RECORDER_RESET, vm_id, java_recorder, audio_recorder[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);  
    /* find free player */
    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }   

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
            audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_READY);
            audio_recorder[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
            audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_READY);
            audio_recorder[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
    {
        if (audio_recorder[vm_id].record_size_limit != -1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);
        }
    }
    
    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {  
    #ifdef __MTK_TARGET__
        audio_recorder[vm_id].current_time = (long)Media_GetRecordedTime();
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_recorder[vm_id].current_time);
    #endif            
        ret = mdi_audio_stop_record();

        /* Delete the recorded file */
        file_handle = FS_Open((kal_wchar *) audio_recorder[vm_id].filename, FS_READ_ONLY);
        if (file_handle > 0) /* Check if file exist */
        {
            result = FS_Close(file_handle); /* need to close file before delete */
            result = FS_Delete((kal_wchar *) audio_recorder[vm_id].filename);
            if (result != FS_NO_ERROR)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
                JMA_CS_LEAVE(KAL_FALSE);
            }
        }

        /* Handle result */
        if (ret == MDI_AUDIO_SUCCESS)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_READY);
            audio_recorder[vm_id].state = JAVA_MEDIA_STATE_READY;
            JMA_CS_LEAVE(KAL_TRUE);
        }
        else
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ret);
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }

    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_commit
 * DESCRIPTION
 *  The function erases recorded content
 * PARAMETERS
 *  mma_type            [IN]        
 *  java_recorder       [IN]  
 * RETURNS
 *  int - 0
 *****************************************************************************/
kal_bool jma_mvm_audio_recorder_commit(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result ret;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RECORDER_COMMIT, vm_id, java_recorder, audio_recorder[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE); 
    /* find free player */
    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }   

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
    {
        if (audio_recorder[vm_id].record_size_limit != -1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);
        }
    }
    
    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {  
    #ifdef __MTK_TARGET__
        audio_recorder[vm_id].current_time = (long)Media_GetRecordedTime();
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_recorder[vm_id].current_time);
    #endif
        ret = mdi_audio_stop_record();

        /* Handle result */
        if (ret == MDI_AUDIO_SUCCESS)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_READY);
            audio_recorder[vm_id].state = JAVA_MEDIA_STATE_READY;
            JMA_CS_LEAVE(KAL_TRUE);
        }
        else
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ret);
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }

    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_open
 * DESCRIPTION
 *  This function allocate audio recorder context and open file for recording
 * PARAMETERS
 *  mma_type            [IN]        
 *  java_recorder       [IN]        
 *  filename            [?]         
 *  mode                [IN]        
 * RETURNS
 *  int - 0
 *****************************************************************************/
kal_bool jma_mvm_audio_recorder_open(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 audio_state = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RECORDER_OPEN, vm_id, java_recorder);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    /* find free player */
    if (audio_recorder[vm_id].id != INVALID_JPLAYER_ID)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }    

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    /* Audio player, audio recorder, video player, camera, video recorder are multual exclusive */
    audio_state = jma_mvm_audio_player_state(vm_id);
#ifdef SUPPORT_JSR_135_VIDEO
    if (jma_video_player_is_active(vm_id) || JMA_AUDIO_ACTIVE == audio_state)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
#else
    if (JMA_AUDIO_ACTIVE == audio_state)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
#endif

#ifdef __JMA_PREEMPT_PLAYER__ /*this will not happen if VM instance is 1*/
    if (JMA_AUDIO_NON_ACTIVE == audio_state)
    {
        jma_video_notify_suspend_audio_player(vm_id);
    }
#endif
    
    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_NULL)
    {       
        /* Succeed to acquire resource */
        jma_register_device(
            JAVA_MEDIA_AUDIO_RECORDER, 
            vm_id,
            java_recorder,
            &jma_audio_recorder_suspend_hdlr,
            &jma_audio_recorder_resume_hdlr, 
            &jma_audio_recorder_close_hdlr);

        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_READY);
        audio_recorder[vm_id].state = JAVA_MEDIA_STATE_READY;
        audio_recorder[vm_id].id = java_recorder;
        
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
    JMA_CS_LEAVE(KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_close
 * DESCRIPTION
 *  This function deallocate audio recorder context
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_recorder       [IN]        
 * RETURNS
 *  kal_bool - true
 *****************************************************************************/
kal_bool jma_mvm_audio_recorder_close(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RECORDER_CLOSE, vm_id, java_recorder, audio_recorder[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    jma_deregister_device(JAVA_MEDIA_AUDIO_RECORDER, vm_id, java_recorder);

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        jma_audio_recorder_finalize(vm_id); 
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        jma_audio_recorder_finalize(vm_id); 
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        /* State will be changed to READY */
        jma_audio_recorder_reset(java_recorder);
    }   
  
    jma_audio_recorder_finalize(vm_id); 
    
#ifdef __JMA_PREEMPT_PLAYER__
    /* Resume preempted audio players if exist */
    jma_video_notify_resume_audio_player(vm_id);
#endif
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_mvm_audio_recorder_clear_jmadata
 * DESCRIPTION
 *  This function only be invoked at Long event to close player.
 * PARAMETERS
 *  vm_id           [IN]         
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_audio_recorder_clear_jmadata(kal_int32 vm_id, kal_int32 java_recorder)
{
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_RECORDER_CLEAR_JMADATA, vm_id, java_recorder);
    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        return;
    }

    jma_deregister_device(JAVA_MEDIA_AUDIO_RECORDER, vm_id, java_recorder);
    jma_audio_recorder_finalize(vm_id);
}

/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_start_record
 * DESCRIPTION
 *  This function submit Record request to media task.
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_recorder       [IN]        
 * RETURNS
 *  int - 0
 *****************************************************************************/
kal_bool jma_mvm_audio_recorder_start_record(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result ret = MDI_AUDIO_FAIL;
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RECORDER_START_RECORD, vm_id, java_recorder, audio_recorder[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (mmi_ucs2strlen((PS8) audio_recorder[vm_id].filename) == 0)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        ret = mdi_audio_start_record(audio_recorder[vm_id].filename, audio_recorder[vm_id].format, 0,
            jma_audio_recorder_record_result_hdlr, NULL);                
    }
    else if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        ret = mdi_audio_resume(jma_audio_recorder_record_result_hdlr, NULL);
    }

    /* Handle result */
    if (ret == MDI_AUDIO_SUCCESS)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_RECORDING);
        audio_recorder[vm_id].state = JAVA_MEDIA_STATE_RECORDING;

        if (audio_recorder[vm_id].record_size_limit != -1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
            stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_AUDIO_RECORDER + vm_id, ticks);
        }
        
        JMA_CS_LEAVE(KAL_TRUE);
    }
    else
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ret);
        JMA_CS_LEAVE(KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_stop_record
 * DESCRIPTION
 *  This function submit stop request to media task.
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_recorder       [IN]        
 * RETURNS
 *  int - 0
 *****************************************************************************/
kal_bool jma_mvm_audio_recorder_pause_record(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result ret;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RECORDER_PAUSE_RECORD, vm_id, java_recorder, audio_recorder[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
            audio_recorder[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
            audio_recorder[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */

    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
    {
        ret = mdi_audio_pause(jma_audio_recorder_record_result_hdlr, NULL);

        if (ret == MDI_AUDIO_SUCCESS)
        {
            if (audio_recorder[vm_id].record_size_limit != -1)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
                stack_stop_timer(&java_media_timer);
            }
            
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, audio_recorder[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
            audio_recorder[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
            
        #ifdef __MTK_TARGET__
            audio_recorder[vm_id].current_time = (long)Media_GetRecordedTime();
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_recorder[vm_id].current_time);
        #endif
        }
        else
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ret);
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }

    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_set_record_location
 * DESCRIPTION
 *  The function sets record location
 * PARAMETERS
 *  mma_type          [IN]        
 *  java_recorder       [IN]
 *  path          [?] 
 * RETURNS
 *  int - 0
 *****************************************************************************/
kal_bool jma_mvm_audio_recorder_set_record_location(kal_int32 vm_id, kal_int32 java_recorder, kal_char *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 file_handle;
    kal_int32 result, length;
    kal_wchar *ext_name;
    kal_char *file_name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RECORDER_SET_RECORD_LOCATION, vm_id, java_recorder, audio_recorder[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    mmi_ucs2ncpy((PS8) audio_recorder[vm_id].filename, (PS8) path, J2ME_PATH_BUFFER_SIZE);
    
    length = mmi_ucs2strlen((S8*) audio_recorder[vm_id].filename);
    if (length < 4)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }

    /* Drive name can not equal to SYSTEM DRIVE */
    if ((int)audio_recorder[vm_id].filename[0] == SRV_FMGR_SYSTEM_DRV)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    /* assign format */
    ext_name = &audio_recorder[vm_id].filename[length - 4];
    if (kal_wstrcmp(ext_name, L".amr") == 0 || kal_wstrcmp(ext_name, L".AMR") == 0)
    {
        audio_recorder[vm_id].format = MED_TYPE_AMR;
    }
    else if (kal_wstrcmp(ext_name, L".wav") == 0 || kal_wstrcmp(ext_name, L".WAV") == 0)
    {
        audio_recorder[vm_id].format = MED_TYPE_WAV;
    }
#if defined (AMRWB_ENCODE)   
    else if (kal_wstrcmp(ext_name, L".awb") == 0 || kal_wstrcmp(ext_name, L".AWB") == 0)
    {
        audio_recorder[vm_id].format = MED_TYPE_AMR_WB;
    }
#endif
#if defined (__VORBIS_ENCODE__)   
        else if (kal_wstrcmp(ext_name, L".ogg") == 0 || kal_wstrcmp(ext_name, L".OGG") == 0)
        {
            audio_recorder[vm_id].format = MED_TYPE_VORBIS;
        }
#endif
    else
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_recorder[vm_id].format);
    /* Check if valid file path and delete the file */
    result = FS_GetDevStatus(audio_recorder[vm_id].filename[0], FS_MOUNT_STATE_ENUM);
    if (result == FS_NO_ERROR) 
    {
        /* Check if valid file name */
        file_name = kal_dchar_strrchr((S8*) audio_recorder[vm_id].filename, '\\');

        if (file_name)
        {
            file_name += 2;
            if (!srv_fmgr_path_is_filename_valid((const WCHAR*)file_name))
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                JMA_CS_LEAVE(KAL_FALSE);
            }
            /* File name can not start with space: FS API restriction */
            if (*file_name == ' ' && *(file_name + 1) == 0)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
                JMA_CS_LEAVE(KAL_FALSE);
            }
        }
        else /* Do not contain '\\' */
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_FALSE);
        }        

        /* Check if dir exist or if valid dir */
        *((kal_int16*)file_name) = 0;
        file_handle = FS_Open(audio_recorder[vm_id].filename, FS_OPEN_DIR | FS_READ_ONLY);            
        if (file_handle > 0)
        {
           FS_Close(file_handle);
        }
        else
        {
           kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
           JMA_CS_LEAVE(KAL_FALSE);
        }
 
        /* Copy again to repair audio_recorder.filename */
        mmi_ucs2ncpy((PS8) audio_recorder[vm_id].filename, (PS8) path, J2ME_PATH_BUFFER_SIZE);
        
        /* Check if file exist */
        file_handle = FS_Open(audio_recorder[vm_id].filename, FS_READ_ONLY);
        if (file_handle > 0) 
        {
            result = FS_Close(file_handle); /* need to close file before delete */
            result = FS_Delete(audio_recorder[vm_id].filename);
            if (result != FS_NO_ERROR)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
                JMA_CS_LEAVE(KAL_FALSE);
            }
        }

        JMA_CS_LEAVE(KAL_TRUE);
    }
    else
    {
       kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
       kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);
       JMA_CS_LEAVE(KAL_FALSE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_set_record_size_limit
 * DESCRIPTION
 *  This function set the size limit of recorded data
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_recorder       [IN]        
 *  limit_size          [IN]        
 * RETURNS
 *  int - limit_size set
 *****************************************************************************/
kal_int32 jma_mvm_audio_recorder_set_record_size_limit(kal_int32 vm_id, kal_int32 java_recorder, kal_int32 limit_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RECORDER_SET_RECORD_SIZE_LIMIT, vm_id, java_recorder, audio_recorder[vm_id].state, limit_size);
    JMA_CS_ENTER(vm_id, 0);

    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    /* Save parameter */
    audio_recorder[vm_id].record_size_limit = limit_size;

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(limit_size);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {   
        JMA_CS_LEAVE(limit_size);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    /* start timer */
    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
    {
        if(audio_recorder[vm_id].record_size_limit != -1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
            stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_AUDIO_RECORDER + vm_id, ticks);
        }
    }
    JMA_CS_LEAVE(limit_size);
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_get_record_time
 * DESCRIPTION
 *  This function invoke AudioGetRecordTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_recorder     [IN]        
 * RETURNS
 *  long - current_time
 *****************************************************************************/
kal_uint64 jma_mvm_audio_recorder_get_record_time(kal_int32 vm_id, kal_int32 java_recorder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_AUDIO_RECORDER_GET_RECORD_TIME, vm_id, java_recorder, audio_recorder[vm_id].state); 
    JMA_CS_ENTER(vm_id, 0);

    if (audio_recorder[vm_id].id != java_recorder)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, audio_recorder[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(audio_recorder[vm_id].current_time);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(audio_recorder[vm_id].current_time);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    if (audio_recorder[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        audio_recorder[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
    #ifdef __MTK_TARGET__
        audio_recorder[vm_id].current_time = (kal_uint64)Media_GetRecordedTime();
    #endif
    }
 
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, audio_recorder[vm_id].current_time);
    JMA_CS_LEAVE(audio_recorder[vm_id].current_time);
}
#else
kal_bool jma_mvm_audio_recorder_open(kal_int32 vm_id, kal_int32 java_recorder){return KAL_FALSE;}
kal_bool jma_mvm_audio_recorder_close(kal_int32 vm_id, kal_int32 java_recorder){return KAL_FALSE;}
void jma_mvm_audio_recorder_clear_jmadata(kal_int32 vm_id, kal_int32 java_recorder){}
kal_bool jma_mvm_audio_recorder_start_record(kal_int32 vm_id, kal_int32 java_recorder){return KAL_FALSE;}
kal_bool jma_mvm_audio_recorder_pause_record(kal_int32 vm_id, kal_int32 java_recorder){return KAL_FALSE;}
kal_bool jma_mvm_audio_recorder_commit(kal_int32 vm_id, kal_int32 java_recorder){return KAL_FALSE;}
kal_bool jma_mvm_audio_recorder_reset(kal_int32 vm_id, kal_int32 java_recorder){return KAL_FALSE;}
kal_bool jma_mvm_audio_recorder_set_record_location(kal_int32 vm_id, kal_int32 java_recorder, kal_char *path){return KAL_FALSE;}
kal_int32 jma_mvm_audio_recorder_set_record_size_limit(kal_int32 vm_id, kal_int32 java_recorder, kal_int32 limit_size){return 0;}
kal_uint64 jma_mvm_audio_recorder_get_record_time(kal_int32 vm_id, kal_int32 java_recorder){return 0;}


#endif

/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_is_active
 * DESCRIPTION
 *  This function return if any recorder is active
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool - true or false
 *****************************************************************************/
kal_bool jma_audio_recorder_is_active(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JSR135_AUDIO_RECORDER
    if (vm_id != INVALID_JVM_ID &&
        audio_recorder[vm_id].id != INVALID_JPLAYER_ID)
    {
        return KAL_TRUE;
    }
    
    return KAL_FALSE;
#else /* SUPPORT_MMAPI */ 
    return KAL_FALSE;
#endif /* SUPPORT_MMAPI */ 
}

/*****************************************************************************
 * FUNCTION
 *  jma_audio_recorder_is_really_active()
 * DESCRIPTION
 *  This function check if any audio device is really active.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool - true or false
 *****************************************************************************/
kal_bool jma_audio_recorder_is_really_active(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(KAL_TRUE == jma_media_enable[vm_id] )
	{
	    if(jma_audio_recorder_is_active(vm_id))
	    {
            return KAL_TRUE;
	    }
		else
		{
			return KAL_FALSE;
		}
	}
	else
	{
	    return KAL_FALSE;
	}
    
}

