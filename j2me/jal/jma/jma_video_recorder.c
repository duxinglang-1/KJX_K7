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
 *   jma_video_recorder.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines native JMA video recorder APIs
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * @(#)jma_video_recorder.c   1.00 05/12/07
 *
 * Copyright (c) 2005 MediaTek Inc. All rights reserved.
 */

/*************************************************************************
 * Include Header Files
 *************************************************************************/
#include "jma_interface.h"
#include "jma_internal.h"
#include "FileMgrGProt.h"

/*************************************************************************
 * bluetooth headers
 *************************************************************************/
#ifdef __MMI_BT_SUPPORT__
#include "BTMMIObexGprots.h"
#endif


/*****************************************************************************
 * Global Definition and Declaration
*****************************************************************************/

#if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMCORDER__) || defined(__MMI_VIDEO_RECORDER__))

/*****************************************************************************
 * Global Definition and Declaration
*****************************************************************************/

kal_bool video_record_need_merge[JVM_NUM] = {KAL_FALSE};

/*****************************************************************************
 * private functions
*****************************************************************************/
void jma_video_recorder_save_file(kal_int32 vm_id);
void jma_video_recorder_record_result_hdlr(MDI_RESULT result, void* user_data);
void jma_video_recorder_save_result_hdlr(MDI_RESULT result, void* user_data);
kal_bool jma_video_recorder_refresh(kal_int32 vm_id, kal_int32 java_player);
static kal_bool jma_video_recorder_stop_record(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player);

/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_timer_expired
 * DESCRIPTION
 *  This function handles video recorder timer expired
 * PARAMETERS
 *  mma_type            [IN]        
 *  java_player       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_recorder_timer_expired(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 record_size;
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_TIMER_EXPIRED, vm_id, video_player[vm_id].id, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    if (video_player[vm_id].state != JAVA_MEDIA_STATE_RECORDING)
    {
        kal_print("Video Record FAIL: state is not right!");
        JMA_CS_LEAVE(JMA_VOID);
    }
    
    EXT_ASSERT(video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING, 0, 0, 0);

    record_size = mdi_video_rec_get_record_file_size();

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, record_size);

    /* Reach record size limit */
    if (record_size >= video_player[vm_id].record_size_limit)
    {
        /* State will be changed */
        jma_video_recorder_stop_record(vm_id, MMA_TYPE_MPEG, video_player[vm_id].id);        

        jvm_post_mma_event(MMA_EVENT_RECORD_STOPPED, 
            video_player[vm_id].id, video_player[vm_id].current_time);
    }
    else /* re-start timer */
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
        stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_VIDEO_RECORDER + vm_id, ticks);
    }
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_finalizes
 * DESCRIPTION
 *  This function handles video recorder suspend
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  int result
 *****************************************************************************/
void jma_video_recorder_finalize(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (video_player[vm_id].is_double_buffer)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
        jui_widget_stop_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_FALSE;
    }
  
    jma_video_player_reset_parameter(vm_id);
    
    video_record_need_merge[vm_id] = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_suspend_hdlr
 * DESCRIPTION
 *  This function handles video recorder suspend
 * PARAMETERS
 *  hdlr        [IN]        
 * RETURNS
 *  int result
 *****************************************************************************/
kal_int32 jma_video_recorder_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    java_media_state_enum original_state;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_SUSPEND_HDLR, vm_id, java_player, video_player[vm_id].state); 
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    original_state = video_player[vm_id].state;
    
    /* Avoid data abort: But Cannot change state */
    if (original_state == JAVA_MEDIA_STATE_RECORDING ||
        original_state == JAVA_MEDIA_STATE_PAUSED ||
        original_state == JAVA_MEDIA_STATE_STOPPED_PAUSED)
    {        
        /* State will be changed to READY */
        jma_mvm_video_recorder_reset(vm_id, MMA_TYPE_MPEG, java_player);
    }
    else if (original_state == JAVA_MEDIA_STATE_PLAYING)
    {
        jma_mvm_video_recorder_stop_preview(vm_id, MMA_TYPE_MPEG, java_player);
    }   

    /* Camera power off */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        mdi_video_rec_stop_save();
        mdi_video_rec_power_off();
    }
    
    /* Backlight control */
    jvm_force_backlight_on(KAL_FALSE);
#ifdef __MMI_BT_SUPPORT__
    mmi_bt_enable_receiving();
#endif    
    /* Resume to original state */
    video_player[vm_id].state = original_state;

    /* Stop double buffer when suspend video */
    if (video_player[vm_id].is_double_buffer)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
        jui_widget_stop_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_FALSE;
    }
    
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_resume_hdlr
 * DESCRIPTION
 *  This function handles video recorder timer expired
 * PARAMETERS
 *  native_recorder     [IN]        
 * RETURNS
 *  int - result
 *****************************************************************************/
kal_int32 jma_video_recorder_resume_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    kal_bool ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_RESUME_HDLR, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    if (!video_player[vm_id].is_double_buffer)
    {
        /* Start double buffer when resume video */
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
        jui_widget_start_double_buffer();
        video_player[vm_id].is_double_buffer = KAL_TRUE;    
    }
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        /* Backlight control */
        jvm_force_backlight_on(KAL_TRUE);
        mdi_video_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
        /* camera HW power on */
        result = mdi_video_rec_power_on(JAVA_APP_ID_MED);
		if (result != MDI_RES_VDOREC_SUCCEED)
		{
			video_player[vm_id].state = JAVA_MEDIA_STATE_NULL;
		    jvm_force_backlight_on(KAL_FALSE);

            JMA_CS_LEAVE(KAL_FALSE);
		}
    #ifdef __MMI_BT_SUPPORT__
        mmi_bt_disable_receiving();
    #endif
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        /* Backlight control */
        jvm_force_backlight_on(KAL_TRUE);
        mdi_video_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
        result = mdi_video_rec_power_on(JAVA_APP_ID_MED);
		if (result != MDI_RES_VDOREC_SUCCEED)
		{
			video_player[vm_id].state = JAVA_MEDIA_STATE_NULL;
		    jvm_force_backlight_on(KAL_FALSE);
            JMA_CS_LEAVE(KAL_FALSE);
		}
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        ret = jma_mvm_video_recorder_start_preview(vm_id, MMA_TYPE_MPEG, java_player);

        if (ret == KAL_FALSE)
        {
            result = mdi_camera_power_off();

            if (video_player[vm_id].is_double_buffer)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STOP_DOUBLE_BUFFER);
                jui_widget_stop_double_buffer();
                video_player[vm_id].is_double_buffer = KAL_FALSE;
            }
            jma_video_player_reset_parameter(vm_id);

            jma_deregister_device(JAVA_MEDIA_MPEG_RECORDER_DEVICE, vm_id, java_player);
            /* Backlight control */
            jvm_force_backlight_on(KAL_FALSE);        
        }
    #ifdef __MMI_BT_SUPPORT__
        mmi_bt_disable_receiving();
    #endif
    }
    else
    {
        jvm_post_mma_event(
            MMA_EVENT_RECORD_ERROR,
            java_player,
            (kal_int64) MMA_ERR_MMI_INTERRUPT);

        /* Backlight control */
        jvm_force_backlight_on(KAL_TRUE);
        mdi_video_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
        /* camera HW power on */
        result = mdi_video_rec_power_on(JAVA_APP_ID_MED);
		if (result != MDI_RES_VDOREC_SUCCEED)
		{
		    jvm_force_backlight_on(KAL_FALSE);
			video_player[vm_id].state = JAVA_MEDIA_STATE_NULL;
            JMA_CS_LEAVE(KAL_FALSE);
		}
        
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
    }  
   
    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_close_hdlr
 * DESCRIPTION
 *  This function handles video recorder timer expired
 * PARAMETERS
 *  native_recorder     [IN]        
 * RETURNS
 *  int result
 *****************************************************************************/
kal_int32 jma_video_recorder_close_hdlr(kal_int32 vm_id, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_CLOSE_HDLR, vm_id, java_player, video_player[vm_id].state);

    JMA_CS_ENTER(vm_id, RESOUCE_FAIL);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(RESOUCE_FAIL);
    }

    if (!is_vm_suspend_media[vm_id])
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
            video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED ||
            video_player[vm_id].state == JAVA_MEDIA_STATE_STOPPED_PAUSED)
        {        
            /* State will be changed to READY */
            jma_mvm_video_recorder_reset(vm_id, MMA_TYPE_MPEG, java_player);
        }

        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            jma_mvm_video_recorder_stop_preview(vm_id, MMA_TYPE_MPEG, java_player);
        }   
        
        /* Camera power off */
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
        {
            mdi_video_rec_stop_save();
            mdi_video_rec_power_off();
        } 
        
        /* Backlight control */
        jvm_force_backlight_on(KAL_FALSE);
    #ifdef __MMI_BT_SUPPORT__
        mmi_bt_enable_receiving();
    #endif
    } 
    
    jma_deregister_device(video_player[vm_id].device_type, vm_id, java_player);
    jma_video_recorder_finalize(vm_id);    

    JMA_CS_LEAVE(RESOUCE_NO_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_save_file
 * DESCRIPTION
 *  / mmi_vdorec_entry_saving_screen
 *  enter save screen
 * PARAMETERS
 *  native_recorder     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_recorder_save_file(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_SAVE_FILE, vm_id, video_player[vm_id].id, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, JMA_VOID);

    /* if unsaved file exist, merge them */
    if (mdi_video_rec_has_unsaved_file((S8 *)video_player[vm_id].filename))
    {
        video_record_need_merge[vm_id] = KAL_TRUE;
        result = mdi_video_rec_save_file((S8 *)video_player[vm_id].filename, jma_video_recorder_save_result_hdlr,NULL);
        /* if error occurs, delete file */
        if (result != MDI_RES_VDOREC_SUCCEED) 
        {
            mdi_video_rec_delete_unsaved_file((S8 *)video_player[vm_id].filename);
        }
    }
    
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_record_result_hdlr
 * DESCRIPTION
 *  The function is invoked when record size limit is reached or error occurs, 
 *  such as disk full,....
 * PARAMETERS
 *  result      [IN]        
 *  a(?)        [IN]        Current state
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_recorder_record_result_hdlr(MDI_RESULT result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 recorder;
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_RECORD_RESULT_HDLR, vm_id, video_player[vm_id].id, video_player[vm_id].state, result);

    if (INVALID_JVM_ID == vm_id)
    {
        ASSERT(0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_VM_NOT_FG_RUNNING);
        return;
    }

    JMA_CS_ENTER(vm_id, JMA_VOID);
    
    /* get record time */
    mdi_video_rec_get_cur_record_time(&video_player[vm_id].current_time);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);
     
    /* free layers */
    jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
    jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
    if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(preview_layer_handle);
        preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        
        jma_video_free_preveiw_layer_buffer(vm_id);
    }  

    /* MED recorder stopped, JAL has not saved file yet */
    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_STOPPED_PAUSED);
    video_player[vm_id].state = JAVA_MEDIA_STATE_STOPPED_PAUSED;
        
    if (result == MDI_RES_VDOREC_DISK_FULL)
    {
        jma_mvm_video_recorder_commit(vm_id, MMA_TYPE_MPEG, video_player[vm_id].id);
        jvm_post_mma_event(MMA_EVENT_RECORD_STOPPED, 
            video_player[vm_id].id, video_player[vm_id].current_time);
    }
    else /* Error case */
    {
        recorder = video_player[vm_id].id;
        jma_mvm_video_recorder_close(vm_id, MMA_TYPE_MPEG, recorder);
        jvm_post_mma_event(MMA_EVENT_RECORD_ERROR, recorder, (kal_int64) MMA_ERR_RECORD_FAIL);
    }  
    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_save_result_hdlr
 * DESCRIPTION
 *  / jma_mpeg_recorder_save_result_hdlr_callback
 *  callback function when save is done
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_recorder_save_result_hdlr(MDI_RESULT result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 recorder;
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_SAVE_RESULT_HDLR, vm_id, video_player[vm_id].id, video_player[vm_id].state, result);

    if (INVALID_JVM_ID == vm_id)
    {
        ASSERT(0);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_VM_NOT_FG_RUNNING);
        return;
    }

    JMA_CS_ENTER(vm_id, JMA_VOID);
    /* Reset parameter */
    video_record_need_merge[vm_id] = KAL_FALSE;
    
    /* if error occurs, delete file */
    if (result != MDI_RES_VDOREC_SUCCEED) 
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        recorder = video_player[vm_id].id;
        jma_mvm_video_recorder_close(vm_id, MMA_TYPE_MPEG, recorder);
        jvm_post_mma_event(MMA_EVENT_RECORD_ERROR, recorder, (kal_int64) MMA_ERR_RECORD_FAIL);
    }

    JMA_CS_LEAVE(JMA_VOID);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_open
 * DESCRIPTION
 *  This function allocate mpeg recorder context and open file for recording
 * PARAMETERS
 *  mma_type            [IN]        
 *  java_player       [IN]        
 *  filename            [?]         
 *  mode                [IN]        
 * RETURNS
 *  int - 0
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_open(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    kal_int8 audio_state = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_OPEN, vm_id, java_player);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
    if (video_player[vm_id].id != INVALID_JPLAYER_ID)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */        
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    
    /* Check if Bluetooth is in use now */
#ifdef __MMI_BT_SUPPORT__    
    if (mmi_bt_is_receiving())
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, -1);
        JMA_CS_LEAVE(KAL_FALSE);
    }
#endif

    audio_state = jma_mvm_audio_player_state(vm_id);
    if (jma_audio_recorder_is_active(vm_id) || JMA_AUDIO_ACTIVE == audio_state)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }

#ifdef __JMA_PREEMPT_PLAYER__ /*this will not happen if VM instance is 1*/
    if (JMA_AUDIO_NON_ACTIVE == audio_state)
    {
        jma_video_notify_suspend_audio_player(vm_id);
    }
#endif
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
    {
        /* Backlight control */
        jvm_force_backlight_on(KAL_TRUE);
        
        mdi_video_set_camera_id(MDI_VIDEO_MAIN_SENSOR);
        
        /* camera HW power on */
        result = mdi_video_rec_power_on(JAVA_APP_ID_MED);
        if (result == MDI_RES_VDOREC_SUCCEED)
        {
#ifdef __MMI_BT_SUPPORT__
            mmi_bt_disable_receiving();
#endif
            
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            if (mdi_video_rec_has_unsaved_file((S8 *)video_player[vm_id].filename) == TRUE)
            {
                /* residue temp files exist, cleaning needed! */
                mdi_video_rec_delete_unsaved_file((S8 *)video_player[vm_id].filename);
            }
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
            video_player[vm_id].id = java_player;
            video_player[vm_id].current_time = 0;
            video_player[vm_id].device_type = JAVA_MEDIA_MPEG_RECORDER_DEVICE;
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_START_DOUBLE_BUFFER);
            jui_widget_start_double_buffer();
            video_player[vm_id].is_double_buffer = KAL_TRUE;
            video_player[vm_id].scr_mem_max_size = JMA_VDOPLY_LAYER_BUFFER_SIZE;
            jma_register_device(
                JAVA_MEDIA_MPEG_RECORDER_DEVICE, 
                vm_id,
                java_player,
                &jma_video_recorder_suspend_hdlr, 
                &jma_video_recorder_resume_hdlr, 
                &jma_video_recorder_close_hdlr);
            JMA_CS_LEAVE(KAL_TRUE);
        }
        else
        {           
            /* Backlight control */
            jvm_force_backlight_on(KAL_FALSE);
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }
 
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_close
 * DESCRIPTION
 *  If the function is called before commit(), it will erase recording material.
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_player       [IN]        
 * RETURNS
 *  kal_bool - true
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_close(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_CLOSE, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        jma_deregister_device(JAVA_MEDIA_MPEG_RECORDER_DEVICE, vm_id, java_player);
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_NULL);

        jma_video_recorder_finalize(vm_id); 
        
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_STOPPED_PAUSED)
    {
        /* State will be changed to READY */
        jma_mvm_video_recorder_reset(vm_id, mma_type, java_player);
    }

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        jma_mvm_video_recorder_stop_preview(vm_id, mma_type, java_player);
    }

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        mdi_video_rec_stop_save();
        /* Camera power off */
        mdi_video_rec_power_off();
    }
    
    /* Backlight control */
    jvm_force_backlight_on(KAL_FALSE);

#ifdef __MMI_BT_SUPPORT__
    mmi_bt_enable_receiving();
#endif
    
    jma_deregister_device(JAVA_MEDIA_MPEG_RECORDER_DEVICE, vm_id, java_player);
    kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_NULL);

    jma_video_recorder_finalize(vm_id);    

#ifdef __JMA_PREEMPT_PLAYER__
    /* Resume preempted audio players if exist */
    jma_video_notify_resume_audio_player(vm_id);
#endif
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_mvm_video_recorder_clear_jmadata
 * DESCRIPTION
 *  This function only be invoked at Long event to close player.
 * PARAMETERS
 *  vm_id           [IN]         
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jma_mvm_video_recorder_clear_jmadata(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_CLEAR_JMADATA, vm_id, mma_type, java_player);
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        return;
    }

    jma_deregister_device(JAVA_MEDIA_MPEG_RECORDER_DEVICE, vm_id, java_player);
    jma_video_recorder_finalize(vm_id);
}

/*****************************************************************************
 * FUNCTION
 *  jma_mpeg_recorder_start_preview
 * DESCRIPTION
 *  () / mmi_vdorec_start_preview()
 *  Start preview
 * PARAMETERS
 *  native_recorder     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_start_preview(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_setting_struct video_preview_data;
    MDI_RESULT result;
    kal_bool ret;
    kal_bool visible;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_START_PREVIEW, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

	if (video_player[vm_id].state == JAVA_MEDIA_STATE_NULL)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_TRUE);
    }
    
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        JMA_CS_LEAVE(KAL_TRUE);
    }

    memset(&video_preview_data,0,sizeof(mdi_video_setting_struct));
    mdi_video_rec_load_default_setting(&video_preview_data);

    /* To avoid disk writing speed is so slow that record error happens */
#ifdef MJPG_ENCODE
    video_preview_data.video_qty = MDI_VIDEO_REC_QTY_LOW;
#endif
    video_preview_data.video_size =MDI_VIDEO_VIDEO_SIZE_QCIF;
    video_preview_data.preview_rotate = J2ME_PREVIEW_MAINLCD_ROTATE; //MDI_CAMERA_PREVIEW_ROTATE_0;
#if defined(HORIZONTAL_CAMERA) && !defined(__MDI_VIDEO_HW_ROTATOR_BY_IDP__)
    video_preview_data.lcm_rotate = MDI_CAMERA_LCM_ROTATE_270;
#else 
    video_preview_data.lcm_rotate = MDI_CAMERA_LCM_ROTATE_0;
#endif

#ifdef MJPG_ENCODE
    video_preview_data.video_format = MDI_VIDEO_VIDEO_FORMAT_MJPEG;
#endif
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, video_preview_data.video_format);

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY)
    {
        
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);
        if (ret == KAL_FALSE)
        {
            JMA_CS_LEAVE(KAL_FALSE);
        }
        visible = jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);
        
        mdi_video_rec_enable_partial_display();       
        result = mdi_video_rec_preview_start(
                    preview_layer_handle,
                    blt_layer_flag,
                    preview_layer_flag,
                    visible,
                    &video_preview_data);
        
        if (result == MDI_RES_VDOREC_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PLAYING);
            video_player[vm_id].state = JAVA_MEDIA_STATE_PLAYING;
            JMA_CS_LEAVE(KAL_TRUE);
        }
        else
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, result);

            /* free layers */
            jui_widget_set_hardware_layer(GDI_NULL_HANDLE, NULL, NULL);
            jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
            if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
            {
                gdi_layer_free(preview_layer_handle);
                preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
                
                jma_video_free_preveiw_layer_buffer(vm_id);
            }
            
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }
    
    JMA_CS_LEAVE(KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_stop_preview
 * DESCRIPTION
 *  function to be called to stop preview
 * PARAMETERS
 *  void
 *  native_player(?)        [IN]        Play ID
 *  int mma_type(?)
 * RETURNS
 *  Bool.
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_stop_preview(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_STOP_PREVIEW, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    /* If vm_id not FG running, just switch the state */
    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
        
        JMA_CS_LEAVE(KAL_TRUE);
    }
#ifdef __MMI_BACKGROUND_CALL__
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
#endif
#endif /* __MMI_BACKGROUND_CALL__ */ 

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        result = mdi_video_rec_preview_stop();
		if(1 == result)
		{
			kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 666);
		}

        /* free layers */
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
            
            jma_video_free_preveiw_layer_buffer(vm_id);
        }
       
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
    }   
    
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_start_record
 * DESCRIPTION
 *  This function submit Record request to media task.
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_player       [IN]        
 * RETURNS
 *  int - 0
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_start_record(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_START_RECORD, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    /* Spec says ignore. */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
    {
        JMA_CS_LEAVE(KAL_TRUE);
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

    if (mmi_ucs2strlen((PS8) video_player[vm_id].filename) == 0)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        result = mdi_video_rec_record_start(
                    (S8*) video_player[vm_id].filename,
                    jma_video_recorder_record_result_hdlr,
                    NULL);
    }
    else if (video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        result = mdi_video_rec_record_resume();
    }
    else
    {
        kal_print("Video Record FAIL: state is not right!");
        jma_mvm_video_recorder_close(vm_id, mma_type, java_player);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (result == MDI_RES_VDOREC_SUCCEED)
    {
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_RECORDING);
        video_player[vm_id].state = JAVA_MEDIA_STATE_RECORDING;

        if (video_player[vm_id].record_size_limit != -1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
            stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_VIDEO_RECORDER + vm_id, ticks);
        }
        JMA_CS_LEAVE(KAL_TRUE);
    }
    else
    {
        jma_mvm_video_recorder_close(vm_id, mma_type, java_player);
        jvm_post_mma_event(MMA_EVENT_RECORD_ERROR, java_player, (kal_int64) MMA_ERR_RECORD_FAIL);
        JMA_CS_LEAVE(KAL_FALSE);
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_pause_record
 * DESCRIPTION
 *  This function submit stop request to media task.
 * PARAMETERS
 *  mma_type            [IN]        
 *  java_player       [IN]        
 *  int recorder(?)
 * RETURNS
 *  int - 0
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_pause_record(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_PAUSE_RECORD, vm_id, java_player, video_player[vm_id].state); 
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
        }
    
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;
        }
    
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
    {
        result = mdi_video_rec_record_pause(KAL_FALSE);
        if (result == MDI_RES_VDOREC_SUCCEED)
        {
            if (video_player[vm_id].record_size_limit != -1)
            {
                kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
                stack_stop_timer(&java_media_timer);
            }
            
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_PAUSED);
            video_player[vm_id].state = JAVA_MEDIA_STATE_PAUSED;            
            /* get record time */
            mdi_video_rec_get_cur_record_time(&video_player[vm_id].current_time);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);

        }
        else
        {
            jma_mvm_video_recorder_close(vm_id, mma_type, java_player);
            JMA_CS_LEAVE(KAL_FALSE);
        }
    }
    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_stop_record
 * DESCRIPTION
 *  This function deallocate mpeg recorder context
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_player       [IN]        
 * RETURNS
 *  kal_bool - true
 *****************************************************************************/
static kal_bool jma_video_recorder_stop_record(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_STOP_RECORD, vm_id, java_player, video_player[vm_id].state);  
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    /* Stop timer */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
    {
        if (video_player[vm_id].record_size_limit != -1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_STOP_TIMER);
            stack_stop_timer(&java_media_timer);
        }
    }

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        result = mdi_video_rec_record_stop();      
		if(1 == result)
		{
			kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 445);
		}
        
        /* get record time */
        mdi_video_rec_get_cur_record_time(&video_player[vm_id].current_time);
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);

        /* free layers */
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        jui_widget_mvm_refresh_screen(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, vm_id);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
            
            jma_video_free_preveiw_layer_buffer(vm_id);
        }

        /* MED recorder stopped, JAL has not saved file yet */
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_STOPPED_PAUSED);
        video_player[vm_id].state = JAVA_MEDIA_STATE_STOPPED_PAUSED;
    }

    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_close
 * DESCRIPTION
 *  This function deallocate mpeg recorder context
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_player       [IN]        
 * RETURNS
 *  kal_bool - true
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_commit(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_COMMIT, vm_id, java_player, video_player[vm_id].state); 
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
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

    /* State is wrong */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_READY ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING)
    {
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        /* State will be changed */
        jma_video_recorder_stop_record(vm_id, mma_type, java_player);
    }

    /* MED recorder has stopped, JAL has not saved file yet */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_STOPPED_PAUSED)
    {
        /* save file */
        jma_video_recorder_save_file(vm_id);
        
        /* After commit(), setRecordLocation needs to be called again */
        mmi_ucs2cpy((S8*) video_player[vm_id].filename, "");

        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
    }

    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_reset
 * DESCRIPTION
 *  This function deallocate mpeg recorder context
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_player       [IN]        
 * RETURNS
 *  kal_bool - true
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_reset(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_RESET, vm_id, java_player, video_player[vm_id].state);  
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
            video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
        {
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
    
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {
        if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
            video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
        {
            /* State will be changed */
            jma_video_recorder_stop_record(vm_id, mma_type, java_player);
            kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
            video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
        }
    
        JMA_CS_LEAVE(KAL_TRUE);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        /* State will be changed */
        jma_video_recorder_stop_record(vm_id, mma_type, java_player);
    }

    /* MED recorder has stopped, JAL has not saved file yet */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_STOPPED_PAUSED)
    {
        /* delete file */
        if (mdi_video_rec_has_unsaved_file((S8 *)video_player[vm_id].filename) == TRUE)
        {
            mdi_video_rec_delete_unsaved_file((S8 *)video_player[vm_id].filename);
        }
        
        /* Clear */
        video_record_need_merge[vm_id] = KAL_FALSE;
        
        /* After reset(), setRecordLocation needs to be called again */
        mmi_ucs2cpy((S8*) video_player[vm_id].filename, "");
        
        kal_trace(TRACE_GROUP_4, J2ME_MMA_STATE_TRANSITION, vm_id, video_player[vm_id].state, JAVA_MEDIA_STATE_READY);
        video_player[vm_id].state = JAVA_MEDIA_STATE_READY;
    }

    JMA_CS_LEAVE(KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_refresh_pause
 * DESCRIPTION
 *  The function does not change state, MUST be pair with 
 *  jma_video_recorder_refresh_resume.
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  x                   [IN]        
 *  y                  [IN]        
 * RETURNS
 *  set display width and height.(?)
 *****************************************************************************/
void jma_video_recorder_refresh_pause(kal_int32 vm_id)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_REFRESH_PAUSE, vm_id, video_player[vm_id].id, video_player[vm_id].state);

    jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE);
    
    /* ignore at NULL, READY state */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        ms = mdi_video_rec_update_blt_pause();
        
        if (ms != MDI_RES_VDOREC_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            jma_mvm_video_recorder_close(vm_id, MMA_TYPE_MPEG, video_player[vm_id].id);
            jma_media_player_cs_leave();
            return;
        }

        /* Release memory */
        jui_widget_set_hardware_layer(GDI_NULL_HANDLE, 0, NULL);
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(preview_layer_handle);
            preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
            
            jma_video_free_preveiw_layer_buffer(vm_id);
        }
    }
    jma_media_player_cs_leave();
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_refresh_resume
 * DESCRIPTION
 *  The function is used to resume video recorder to new location/size
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  x                   [IN]        
 *  y                  [IN]        
 * RETURNS
 *  set display width and height.(?)
 *****************************************************************************/
void jma_video_recorder_refresh_resume(kal_int32 vm_id)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;
    MDI_RESULT ms;
    kal_bool visible;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_REFRESH_RESUME, vm_id, video_player[vm_id].id, video_player[vm_id].state);

    jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE);
    
    /* ignore at NULL, READY state */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {      
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);        
		if(1 == ret)
		{
			kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, 666);
		}

        visible = jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);
                
        ms = mdi_video_rec_update_blt_resume(
                preview_layer_handle,
                blt_layer_flag,
                preview_layer_flag,
                visible);
        if (ms != MDI_RES_VDOREC_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            jma_mvm_video_recorder_close(vm_id, MMA_TYPE_MPEG, video_player[vm_id].id);
        }
    }

    jma_media_player_cs_leave();
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_refresh
 * DESCRIPTION
 *  The function is used to refresh video recorder to new location/size
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  x                   [IN]        
 *  y                  [IN]        
 * RETURNS
 *  set display width and height.(?)
 *****************************************************************************/
kal_bool jma_video_recorder_refresh(kal_int32 vm_id, kal_int32 java_player)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;
    MDI_RESULT ms;
    kal_bool visible;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_VIDEO_RECORDER_REFRESH, vm_id, java_player, video_player[vm_id].state);

    /* ignore at NULL, READY state */
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_PLAYING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING ||
        video_player[vm_id].state == JAVA_MEDIA_STATE_PAUSED)
    {
        ms = mdi_video_rec_update_blt_pause();
        
        if (ms != MDI_RES_VDOREC_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            jma_mvm_video_recorder_close(vm_id, MMA_TYPE_MPEG, java_player);
            return KAL_FALSE;
        }
        if (preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            /* to enable blt rect been set successfully */
            gdi_layer_set_hw_update_layer(preview_layer_handle,KAL_FALSE);
        }
        jma_video_player_refine_display_info(vm_id);
        ret = jma_video_player_process_layer(vm_id);        
        if (!ret)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            return KAL_FALSE;
        }

        visible = jma_video_player_update_blt_flag(vm_id, JMA_BLT_DEPEND);
        
        ms = mdi_video_rec_update_blt_resume(
                preview_layer_handle,
                blt_layer_flag,
                preview_layer_flag,
                visible);
        if (ms != MDI_RES_VDOREC_SUCCEED)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, ms);
            jma_mvm_video_recorder_close(vm_id, MMA_TYPE_MPEG, java_player);
            return KAL_FALSE;
        }
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_player_set_display_location
 * DESCRIPTION
 *  function to be called to set display width and height
 * PARAMETERS
 *  mma_type                [IN]        
 *  java_player             [IN]        
 *  x                   [IN]        
 *  y                  [IN]        
 * RETURNS
 *  set display width and height.(?)
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_set_record_location(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 file_handle;
    kal_int32 result;
    kal_char *file_name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_SET_RECORD_LOCATION, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(KAL_FALSE);
    }

    mmi_ucs2ncpy((PS8) video_player[vm_id].filename, path, J2ME_PATH_BUFFER_SIZE);

    /* Drive name can not equal to SYSTEM DRIVE */
    if ((int)video_player[vm_id].filename[0] == SRV_FMGR_SYSTEM_DRV)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
        JMA_CS_LEAVE(KAL_FALSE);
    }
    
    result = FS_GetDevStatus(video_player[vm_id].filename[0] ,FS_MOUNT_STATE_ENUM);
    if (result == FS_NO_ERROR) 
    {
        /* Check if valid file name */
        file_name = kal_dchar_strrchr((S8*) video_player[vm_id].filename, '\\');

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
        else /* Do not file '\\' */
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_MARKER_FAIL);
            JMA_CS_LEAVE(KAL_FALSE);
        }   

        /* Check if dir exist or if valid dir */
        *((kal_int16*)file_name) = 0;
        file_handle = FS_Open(video_player[vm_id].filename, FS_OPEN_DIR | FS_READ_ONLY);            
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
        mmi_ucs2ncpy((PS8) video_player[vm_id].filename, (PS8) path, J2ME_PATH_BUFFER_SIZE);
        
        file_handle = FS_Open(video_player[vm_id].filename, FS_READ_ONLY);
        if (file_handle > 0) /* Check if file exist */
        {
            result = FS_Close(file_handle); /* need to close file before delete */
            result = FS_Delete(video_player[vm_id].filename);
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
 *  jma_video_recorder_set_record_size_limit
 * DESCRIPTION
 *  This function set the size limit of recorded data
 * PARAMETERS
 *  mma_type            [IN]        Int recorder
 *  java_player       [IN]        
 *  limit_size          [IN]        
 * RETURNS
 *  int - limit_size set
 *****************************************************************************/
kal_int32 jma_mvm_video_recorder_set_record_size_limit(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_int32 limit_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ticks = kal_milli_secs_to_ticks(200); /* 200 ms */   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_SET_RECORD_SIZE_LIMIT, vm_id, java_player, video_player[vm_id].state, limit_size);
    JMA_CS_ENTER(vm_id, KAL_FALSE);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    /* Save parameter */
    video_player[vm_id].record_size_limit = limit_size;

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
    if (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING)
    {
        if(video_player[vm_id].record_size_limit != -1)
        {
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_STACK_START_TIMER);
            stack_start_timer(&java_media_timer, JAVA_MEDIA_TIMER_VIDEO_RECORDER + vm_id, ticks);
        }
    }
    JMA_CS_LEAVE(limit_size);
}

/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_record_merged
 * DESCRIPTION
 *  This function handles video recorder merged
 * PARAMETERS
 *  mma_type            [IN]        
 *  java_player       [IN]        
 * RETURNS
 *  bool result
 *****************************************************************************/
kal_bool jma_mvm_video_recorder_record_merged(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((video_record_need_merge[vm_id]))
	{
    return KAL_FALSE;
	}
	else
	{
		return KAL_TRUE;
	}

}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_get_record_time
 * DESCRIPTION
 *  This function invoke VideoGetRecordTime request to media task.
 * PARAMETERS
 *  mma_type        [IN]        
 *  java_player     [IN]        
 * RETURNS
 *  long - current_time
 *****************************************************************************/
kal_uint64 jma_mvm_video_recorder_get_record_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_GET_RECORD_TIME, vm_id, java_player, video_player[vm_id].state);
    JMA_CS_ENTER(vm_id, 0);

    if (video_player[vm_id].id != java_player)
    {
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_RESOURCE_ERROR, video_player[vm_id].id);
        JMA_CS_LEAVE(0);
    }

    if (vm_id != jam_mvm_get_current_vm_id())
    {
        JMA_CS_LEAVE(video_player[vm_id].current_time);
    }
//#ifdef __MMI_BACKGROUND_CALL__
    if (jma_media_player_is_in_background_call())
    {   
        JMA_CS_LEAVE(video_player[vm_id].current_time);
    }
//#endif /* __MMI_BACKGROUND_CALL__ */ 

    if ((vm_id == jam_mvm_get_current_vm_id()) && (video_player[vm_id].state == JAVA_MEDIA_STATE_RECORDING))
    {
        /* Should call after Start_Record(), or DataAbort()*/
        mdi_video_rec_get_cur_record_time(&(video_player[vm_id].current_time));  
    }

    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, (kal_uint32)video_player[vm_id].current_time);
    
    JMA_CS_LEAVE(video_player[vm_id].current_time);
}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_is_active
 * DESCRIPTION
 *  This function checks if video recorder is active
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool result
 *****************************************************************************/
kal_bool jma_video_recorder_is_active(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (INVALID_JVM_ID != vm_id &&
        video_player[vm_id].device_type == JAVA_MEDIA_MPEG_RECORDER_DEVICE)
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
 *  jma_video_recorder_get_record_size
 * DESCRIPTION
 *  This function get the record video size, width & height
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool result
 *****************************************************************************/
void jma_video_recorder_get_default_record_size(U16 video_size, kal_int32 *width, kal_int32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (video_size)
    {
        case MDI_VIDEO_VIDEO_SIZE_QCIF:
            *width = 176;
            *height = 144;
            break;
        default:
            EXT_ASSERT(0, 0, 0, 0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jma_video_recorder_get_record_size
 * DESCRIPTION
 *  This function adjust the width and height to maintain the default ratio
 * PARAMETERS
 *  width [IN/OUT] : the original width set by MIDlet vs. adjusted one
 *  height [IN/OUT] : the original height set by MIDlet vs. adjusted one 
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_recorder_adjust_record_size(kal_int32 *width, kal_int32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 rec_width = 0;
    kal_int32 rec_height = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MVM_VIDEO_RECORDER_ADJUST_RECORD_SIZE, *width, *height);
    
    jma_video_recorder_get_default_record_size(MDI_VIDEO_VIDEO_SIZE_QCIF, &rec_width, &rec_height);
    
    if ((*height) * rec_width > (*width) * rec_height)
    {
        *height =  (*width) * rec_height/ rec_width;
    }
    else
    {
        *width = (*height) * rec_width / rec_height;
    }
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDDD, *width, *height, rec_width, rec_height);

}

#else /* defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_RECORDER__) */ 
kal_bool jma_mvm_video_recorder_open(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_video_recorder_close(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
void jma_mvm_video_recorder_clear_jmadata(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){}
kal_bool jma_mvm_video_recorder_start_preview(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_video_recorder_stop_preview(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_video_recorder_start_record(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_video_recorder_pause_record(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_video_recorder_commit(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_video_recorder_reset(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return KAL_FALSE;}
kal_bool jma_mvm_video_recorder_set_record_location(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player, kal_char *path){return KAL_FALSE;}
kal_bool jma_video_recorder_is_active(kal_int32 vm_id){return KAL_FALSE;}
kal_int32 jma_mvm_video_recorder_set_record_size_limit(kal_int32 vm_id, kal_int32 mma_type, kal_int32 file, kal_int32 limit){return 0;}
kal_bool jma_mvm_video_recorder_record_merged(kal_int32 vm_id, kal_int32 mma_type, kal_int32 recorder){return KAL_FALSE;}
kal_uint64 jma_mvm_video_recorder_get_record_time(kal_int32 vm_id, kal_int32 mma_type, kal_int32 java_player){return 0;}
void jma_video_recorder_get_default_record_size(U16 video_size, kal_int32 * width, kal_int32 * height){}
void jma_video_recorder_adjust_record_size(kal_int32 * width, kal_int32 * height){}
#endif /* defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_RECORDER__) */ 

