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
 *   jma_media_resource.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Use APIs in this file to manage the reource opened by Java.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* Java */
#include "jma_interface.h"
#include "jma_internal.h"

/* MDI */
#include "mdi_audio.h"
#include "mdi_include.h"

/* BT */
#include "ProfilesSrvGprot.h"
#include "BthScoPathSrvGProt.h"

#include "UcmSrvGprot.h"

/* MAUI_03156393 wenmin 20120419 begin */
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif
/* MAUI_03156393 wenmin 20120419 end */
/*************************************************************************
 * Global Definition and Declaration
 *************************************************************************/
/* Mutex */
int j2me_media_mutex_cnt = 0;
module_type j2me_media_mutex_tid = MOD_NIL;

/* param */
kal_bool jma_audio_enable = KAL_FALSE;
kal_bool jma_media_enable[JVM_NUM] = {KAL_FALSE};
kal_bool is_vm_suspend_audio = KAL_FALSE;
kal_bool is_vm_suspend_media[JVM_NUM] = {KAL_FALSE};
kal_bool is_video_suspend_audio = KAL_FALSE;
kal_bool is_med_suspend_audio = KAL_FALSE;
/* MAUI_03121973 wenmin 20120523 begin */
#if 0
#if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
/* under construction !*/
#endif
#endif
/* MAUI_03121973 wenmin 20120523 end */

/* Concurrent Resource */
#define JMA_MEDIA_DEVICE_NUM 20 
resource_mgr_mvm_struct jma_device[JMA_MEDIA_DEVICE_NUM];

/*************************************************************************
 * Function Declaration
 *************************************************************************/
#if defined(__MMI_BT_AUDIO_VIA_SCO__)
/*****************************************************************************
 * FUNCTION
 *  jma_media_player_connect_bt_via_sco
 * DESCRIPTION
 *  The handler to handle MSG_ID_JAVA_MMI_CONNECT_BT_VIA_SCO_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jma_media_player_connect_bt_via_sco(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type active_module_id = kal_get_active_module_id();
    //ilm_struct *ilm_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MEDIA_PLAYER_CONNECT_BT_VIA_SCO, active_module_id);

    if (active_module_id == MOD_MMI) 
    {
        /* The funcion must be invoked in MMI's context */
        srv_btsco_connect_audio_via_sco();
    }
    else
    {
        U8 sco_status;
        /* Check if BT is connected before sending msg. Avoid MMI queue is full */
    #ifdef __MMI_BT_AUDIO_SUPPORT__    
        sco_status = mdi_audio_bt_get_stream_status(BT_HFP);
        if (sco_status == MDI_AUDIO_BT_STATE_OPEN)
        {
            return;
        }
    #endif /* __MMI_BT_AUDIO_SUPPORT__ */    
    
        /* send message and invoke this function, make srv function invoked in MMI's context */
        java_send_msg(active_module_id, MOD_MMI, MMI_J2ME_SAP, MSG_ID_MMI_JAVA_CONNECT_BT_VIA_SCO_REQ, NULL);
    }   
}
#endif /* defined(__MMI_BT_AUDIO_VIA_SCO__) */


/*****************************************************************************
 * FUNCTION
 *  jma_media_player_is_type_supported
 * DESCRIPTION
 *  This function is to query if the type is supported
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jma_media_player_is_type_supported(java_mma_support_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_supported = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MEDIA_PLAYER_IS_TYPE_SUPPORTED, type);
    
    switch (type)
    {
        case MMA_MIDI_DECODE:
        case MMA_TONE_DECODE: 
        case MMA_WAV_DECODE:
        case MMA_IMY_DECODE:
        case MMA_AMR_DECODE:        
        case MMA_WAV_ENCODE:   
        case MMA_AMR_ENCODE: 
            is_supported = KAL_TRUE;
            break;
    #if !defined(MT6223C) && !defined(MT6223P) && !defined(MT6223P_S00)      
        case MMA_GIF_DECODE:    
            is_supported = KAL_TRUE;
            break;
    #endif        
    #ifdef DAF_DECODE        
        case MMA_DAF_DECODE:    
            is_supported = KAL_TRUE;
            break;
    #endif /* DAF_DECODE */
    #ifdef MUSICAM_DECODE        
        case MMA_MUSICAM_DECODE:    
            is_supported = KAL_TRUE;
            break;
    #endif /* MUSICAM_DECODE */
    #ifdef AAC_DECODE        
        case MMA_AAC_DECODE:   
            is_supported = KAL_TRUE;
            break;
    #endif /* AAC_DECODE */
    #ifdef M4A_DECODE        
        case MMA_M4A_DECODE:    
            is_supported = KAL_TRUE;
            break;
    #endif /* M4A_DECODE */
    #ifdef AU_DECODE        
        case MMA_AU_DECODE:    
            is_supported = KAL_TRUE;
            break;
    #endif /* AU_DECODE */
    #ifdef AMRWB_DECODE        
        case MMA_AWB_DECODE:    
            is_supported = KAL_TRUE;
            break;
    #endif /* AMRWB_DECODE */
    #ifdef WMA_DECODE        
        case MMA_WMA_DECODE:    
            is_supported = KAL_TRUE;
            break;
    #endif /* WMA_DECODE */
    #ifdef AIFF_DECODE        
        case MMA_AIFF_DECODE:    
            is_supported = KAL_TRUE;
            break;
    #endif /* AIFF_DECODE */         
    #ifdef AMRWB_ENCODE        
        case MMA_AWB_ENCODE: 
            is_supported = KAL_TRUE;
            break;
    #endif /* AMRWB_ENCODE */
    #ifdef __RM_DEC_SUPPORT__
        case MMA_RA_DECODE: 
            is_supported = KAL_TRUE;
            break;
    #endif /* __RM_DEC_SUPPORT__ */
    #ifdef SUPPORT_JSR_135_VIDEO 
    #if !defined(MT6223C) && !defined(MT6223P) && !defined(MT6223P_S00)
    #if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
        case MMA_JPEG_ENCODE: 
            is_supported = KAL_TRUE;
            break;
    #endif /* __MMI_CAMERA__ */      
    #ifdef MJPG_DECODE
        case MMA_AVI_DECODE:
            is_supported = KAL_TRUE;
            break;
    #endif /* MJPG_DECODE */ 
    #ifdef MJPG_ENCODE
        case MMA_AVI_ENCODE:     
            is_supported = KAL_TRUE;
            break;
    #endif /* MJPG_ENCODE */ 
    #ifdef __RM_DEC_SUPPORT__
        case MMA_RM_DECODE: 
            is_supported = KAL_TRUE;
            break;
    #endif /* __RM_DEC_SUPPORT__ */
    #ifdef MP4_DECODE        
        case MMA_3GP_DECODE: 
        case MMA_MP4_DECODE:
        case MMA_3GP_ENCODE:    
            is_supported = KAL_TRUE;
            break;
    #ifdef __MMI_VIDEO_STREAM__
        case MMA_VIDEO_RTSP:    
            is_supported = KAL_TRUE;
            break;
    #endif/* __MMI_VIDEO_STREAM__ */
    #ifdef __MMI_VIDEO_PDL__
        case MMA_VIDEO_PDL:    
            is_supported = KAL_TRUE;
            break;    
    #endif /* __MMI_VIDEO_PDL__ */
    #endif /* MP4_DECODE */
    #endif /* !defined(MT6223C) && !defined(MT6223P) && !defined(MT6223P_S00) */
    #endif /* SUPPORT_JSR_135_VIDEO */
        default:
            break;
    }
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, is_supported);
    return is_supported;
}


/*****************************************************************************
 * FUNCTION
 *  jma_media_player_clear_parameter
 * DESCRIPTION
 *  This function is invoked by MMI
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jma_media_player_clear_parameter(kal_bool is_init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MEDIA_PLAYER_CLEAR_PARAMETER);
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);
    
    PARAM_CS_ENTER();
    if (is_init)
    {
        for(i = 0; i < JVM_NUM; i++)
        {
            jma_media_enable[i] = KAL_TRUE;
        }
        jma_audio_enable = KAL_TRUE;
    }
    else
    {
        for(i = 0; i < JVM_NUM; i++)
        {
            jma_media_enable[i] = KAL_FALSE;
        }
        jma_audio_enable = KAL_FALSE;
    }
    PARAM_CS_LEAVE();

    is_vm_suspend_audio = KAL_FALSE;
    for(i = 0; i < JVM_NUM; i++)
    {
        is_vm_suspend_media[i] = KAL_FALSE;
    }
    is_video_suspend_audio = KAL_FALSE;
    is_med_suspend_audio = KAL_FALSE;

    /* Reset parameter */
    jma_audio_player_reset_parameter();

    for (i = 0; i < JVM_NUM; i++)
    {
        #ifdef JSR135_AUDIO_RECORDER
        jma_audio_recorder_reset_parameter(i);
        #endif
		#ifdef SUPPORT_JSR_135_VIDEO
        jma_video_player_reset_parameter(i);
		#endif
    }


    jma_reset_all_device();
}


/*****************************************************************************
 * FUNCTION
 *  jma_media_player_vm_notfy_suspend
 * DESCRIPTION
 *  This function is invoked by MMI when VM state is changed
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jma_media_player_vm_notfy_suspend(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MEDIA_PLAYER_VM_NOTIFY_SUSPEND, is_vm_suspend_media[vm_id]);
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);

    if (is_vm_suspend_media[vm_id] == KAL_TRUE)
    {
        return;
    }
    
    is_vm_suspend_media[vm_id] = KAL_TRUE;
	/* MAUI_03121973 wenmin 20120523 begin */
	#if 0
	#if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	#endif
	/* MAUI_03121973 wenmin 20120523 end */
    
    PARAM_CS_ENTER();
    jma_media_enable[vm_id] = KAL_FALSE;
    PARAM_CS_LEAVE();
    
    jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE);

#ifdef SUPPORT_MMAPI    
    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {
        if (vm_id != jma_device[i].vm_id)
        {
            /* Only suspend the player belongs to current VM */
            continue;
        }
        switch (jma_device[i].device_type)
        {        
            case JAVA_MEDIA_AUDIO_RECORDER:
            case JAVA_MEDIA_ANIMA_PLAYER_DEVICE:
                EXT_ASSERT(jma_device[i].suspend!= NULL, 0, 0, 0);
                jma_device[i].suspend(jma_device[i].vm_id, jma_device[i].handle);
                break;
        #if defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))               
            case JAVA_MEDIA_CAM_PLAYER_DEVICE:
            case JAVA_MEDIA_MPEG_PLAYER_DEVICE: 
            case JAVA_MEDIA_STREAM_PLAYER_DEVICE:
            case JAVA_MEDIA_MPEG_RECORDER_DEVICE:
            #if (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMCORDER__))    
                mdi_video_enable_mimic_task(MOD_JASYN_D2);
            #endif
                EXT_ASSERT(jma_device[i].suspend != NULL, 0, 0, 0);
                jma_device[i].suspend(jma_device[i].vm_id, jma_device[i].handle);
            #if (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMCORDER__))     
                mdi_video_disable_mimic_task();
            #endif
                break;
        #endif /* defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMERA__))                */   
            default:
                break;
        }
    }
#endif /* SUPPORT_MMAPI */    
    jma_media_player_cs_leave();

}


/*****************************************************************************
 * FUNCTION
 *  jma_media_player_vm_notfy_resume
 * DESCRIPTION
 *  This function is invoked by MMI when VM state is changed
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jma_media_player_vm_notfy_resume(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MEDIA_PLAYER_VM_NOTIFY_RESUME, is_vm_suspend_media[vm_id]);
    EXT_ASSERT((kal_get_active_module_id() == MOD_MMI &&
               is_vm_suspend_media[vm_id] == KAL_TRUE), 
               0, 0, 0);
    
    is_vm_suspend_media[vm_id] = KAL_FALSE;    

    jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE);

#ifdef SUPPORT_MMAPI     
    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {
        /* Only resume the player belongs to current VM */
        if (jma_device[i].vm_id != vm_id)
        {
            continue;
        }
        
        switch (jma_device[i].device_type)
        {
            case JAVA_MEDIA_AUDIO_RECORDER:
            case JAVA_MEDIA_ANIMA_PLAYER_DEVICE:
                EXT_ASSERT(jma_device[i].resume != NULL, 0, 0, 0);
                jma_device[i].resume(jma_device[i].vm_id, jma_device[i].handle);  
                break;
        #if defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))               
            case JAVA_MEDIA_CAM_PLAYER_DEVICE:
            case JAVA_MEDIA_MPEG_PLAYER_DEVICE: 
            case JAVA_MEDIA_STREAM_PLAYER_DEVICE:
            case JAVA_MEDIA_MPEG_RECORDER_DEVICE:  
            #if (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMCORDER__))     
                mdi_video_enable_mimic_task(MOD_JASYN_D2);
            #endif
                EXT_ASSERT(jma_device[i].resume != NULL, 0, 0, 0);
                jma_device[i].resume(jma_device[i].vm_id, jma_device[i].handle);
            #if (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMCORDER__))     
                mdi_video_disable_mimic_task(); 
            #endif
                break;
        #endif /* defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMERA__))                */     
            default:
                break;
        }
    }
#endif /* SUPPORT_MMAPI */
    
    jma_media_player_cs_leave();

    PARAM_CS_ENTER();
    jma_media_enable[vm_id] = KAL_TRUE;
    PARAM_CS_LEAVE();
}



/*****************************************************************************
 * FUNCTION
 *  jma_media_player_vm_notfy_terminate
 * DESCRIPTION
 *  This function is invoked by MMI when VM state is changed
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jma_media_player_vm_notfy_terminate(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MEDIA_PLAYER_VM_NOTIFY_TERMINATE);
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);
    
    PARAM_CS_ENTER();
    jma_media_enable[vm_id] = KAL_FALSE;
    PARAM_CS_LEAVE();

    jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE);

#ifdef SUPPORT_MMAPI     
    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {          
        if (vm_id != jma_device[i].vm_id)
        {
            /* Only close the player belongs to current terminated VM */
            continue;
        }
        
        switch (jma_device[i].device_type)
        {
            case JAVA_MEDIA_AUDIO_RECORDER:
            case JAVA_MEDIA_ANIMA_PLAYER_DEVICE:
                EXT_ASSERT(jma_device[i].close != NULL, 0, 0, 0);
                jma_device[i].close(jma_device[i].vm_id, jma_device[i].handle);
                break;      
        #if defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))               
            case JAVA_MEDIA_CAM_PLAYER_DEVICE:
            case JAVA_MEDIA_MPEG_PLAYER_DEVICE: 
            case JAVA_MEDIA_STREAM_PLAYER_DEVICE:
            case JAVA_MEDIA_MPEG_RECORDER_DEVICE: 
            #if (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMCORDER__))     
                mdi_video_enable_mimic_task(MOD_JASYN_D2);
            #endif
                EXT_ASSERT(jma_device[i].close != NULL, 0, 0, 0);
                jma_device[i].close(jma_device[i].vm_id, jma_device[i].handle);
            #if (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMCORDER__))     
                mdi_video_disable_mimic_task();
            #endif
                break;
        #endif /* defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMERA__)) */      
            default:
                break;
        }
    }
#endif /* SUPPORT_MMAPI */   
    jma_media_player_cs_leave();

    PARAM_CS_ENTER();
    jma_media_enable[vm_id] = KAL_TRUE;
    PARAM_CS_LEAVE();
    is_vm_suspend_media[vm_id] = KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_do_suspend_job
 * DESCRIPTION
 *  This function is invoked by MMI
 * PARAMETERS
 *  void       
 * RETURNS
 *  executed
 *****************************************************************************/
static kal_bool jma_audio_player_do_suspend_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_bool executed = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_DO_SUSPEND_JOB);
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);

	/* MAUI_03156393 wenmin 20120419 begin */
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif
    /* MAUI_03156393 wenmin 20120419 end */

    PARAM_CS_ENTER();
    jma_audio_enable = KAL_FALSE;
    PARAM_CS_LEAVE();    
    
    /* this api is called by MMI, so it does not need to pass vm_id */
    jma_media_player_cs_check_and_enter(KAL_TRUE);
    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {
        switch (jma_device[i].device_type)
        {
            case JAVA_MEDIA_TONE_DEVICE:
            case JAVA_MEDIA_TONESEQ_DEVICE:
            case JAVA_MEDIA_MIDI_DEVICE:
            case JAVA_MEDIA_WAV_DEVICE:
            case JAVA_MEDIA_IMY_DEVICE:
            case JAVA_MEDIA_SINGLE_DEVICE:     
                EXT_ASSERT(jma_device[i].suspend != NULL, 0, 0, 0);
                jma_mimic_module_id = MOD_JASYN_D2;
                jma_device[i].suspend(jma_device[i].vm_id, jma_device[i].handle);
                jma_mimic_module_id = MOD_NIL;
                executed = KAL_TRUE;
                break;
            default:
                break;
        }
    }

    if (executed)
    {
        /* VM should clear interrupt callback when it closes all audio */
        mdi_audio_stop_use_by_other_task();
    #ifdef J2ME_SUPPORT_BACKGROUND
        /* Update Java icon */
	    if(jam_mvm_is_vm_support_bg(0))
	    {
            jui_widget_reset_vm_bg_status_audio_icon();
	    }
    #endif
    }    

    jma_media_player_cs_leave();

    return executed;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_do_resume_job
 * DESCRIPTION
 *  This function is invoked by MMI
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void jma_audio_player_do_resume_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 vm_id = INVALID_JVM_ID;
    kal_bool executed = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_DO_RESUME_JOB);
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);

	/* MAUI_03156393 wenmin 20120419 begin */
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif
    /* MAUI_03156393 wenmin 20120419 end */

    /* The lines is for both AUDIO and VIDEO. */
    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
    /* this api is called by MMI, so it does not need to pass vm_id */
    jma_media_player_cs_check_and_enter(KAL_TRUE);
    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {            
        switch (jma_device[i].device_type)
        {
            case JAVA_MEDIA_TONE_DEVICE:
            case JAVA_MEDIA_TONESEQ_DEVICE:
            case JAVA_MEDIA_MIDI_DEVICE:
            case JAVA_MEDIA_WAV_DEVICE:
            case JAVA_MEDIA_IMY_DEVICE:
            case JAVA_MEDIA_SINGLE_DEVICE:
                EXT_ASSERT(jma_device[i].resume != NULL, 0, 0, 0);
                jma_mimic_module_id = MOD_JASYN_D2;
                jma_device[i].resume(jma_device[i].vm_id, jma_device[i].handle);
                jma_mimic_module_id = MOD_NIL;
                executed = KAL_TRUE;
                break;
            default:
                break;
        }
    }

    /* Has executed resume handler && resume successfully */
    if (executed && jma_audio_player_is_active())
    {
        /* register interrupt callback */
        mdi_audio_start_use_by_other_task(jma_audio_player_interrupt_callback, NULL);
        for (vm_id = 0; vm_id < JVM_NUM; vm_id++)
        {
            if (jma_audio_is_vm_players_active(vm_id))
            {
            #ifdef J2ME_SUPPORT_BACKGROUND
                /* Update Java icon */
			    if(jam_mvm_is_vm_support_bg(vm_id))
			    {
                    jui_widget_update_vm_bg_status_audio_icon(KAL_TRUE, vm_id);
				}
            #endif
            }
        }
    }
    jma_media_player_cs_leave();
    
    PARAM_CS_ENTER();
    jma_audio_enable = KAL_TRUE;
    PARAM_CS_LEAVE();
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_do_terminate_job
 * DESCRIPTION
 *  This function is invoked by MMI
 * PARAMETERS
 *  void       
 * RETURNS
 *  executed
 *****************************************************************************/
void jma_audio_player_do_terminate_job(jvm_state_enum src_state, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_bool executed = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_DO_TERMINATE_JOB, is_vm_suspend_audio, is_video_suspend_audio, is_med_suspend_audio);
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);

    PARAM_CS_ENTER();
    if (!is_video_suspend_audio && !is_med_suspend_audio)
    {
        jma_audio_enable = KAL_FALSE;
    }
    PARAM_CS_LEAVE();    

    jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_TRUE);
    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {
        if (vm_id != jma_device[i].vm_id)
        {
            /* Only close the player belongs to current terminated VM */
            continue;
        }
        
        switch (jma_device[i].device_type)
        {
            case JAVA_MEDIA_TONE_DEVICE:
            case JAVA_MEDIA_TONESEQ_DEVICE:
            case JAVA_MEDIA_MIDI_DEVICE:
            case JAVA_MEDIA_WAV_DEVICE:
            case JAVA_MEDIA_IMY_DEVICE:
            case JAVA_MEDIA_SINGLE_DEVICE:     
                EXT_ASSERT(jma_device[i].close!= NULL, 0, 0, 0);
                jma_mimic_module_id = MOD_JASYN_D2;
                jma_device[i].close(jma_device[i].vm_id, jma_device[i].handle);
                jma_mimic_module_id = MOD_NIL;
                executed = KAL_TRUE;
                break;
            default:
                break;
        }
    }

#ifdef __JMA_PREEMPT_PLAYER__
    /* Remove preempted players when vm terminated */
    jma_mvm_audio_player_remove_preempted_nodes(vm_id);
    
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, jma_audio_player_is_active(), jma_mvm_audio_player_get_preempted_player());
    /* Has executed close handler && With resource, clear interrupte call back and audio status icon */
    if (executed && 
        (!jma_audio_player_is_active() && jma_mvm_audio_player_get_preempted_player() == 0) &&
        !is_vm_suspend_audio && !is_video_suspend_audio && !is_med_suspend_audio)
    {
        /* Clear interrupt callback */
        mdi_audio_stop_use_by_other_task();
    }
#else
    if (executed && !is_vm_suspend_audio && !is_video_suspend_audio 
        && !is_med_suspend_audio)
    {
        /* Clear interrupt callback */
        mdi_audio_stop_use_by_other_task();
    }
#endif
    if (executed && 
        !is_vm_suspend_audio && !is_video_suspend_audio && !is_med_suspend_audio)
    {
    #ifdef J2ME_SUPPORT_BACKGROUND
        /* Update Java icon */
	    if(jam_mvm_is_vm_support_bg(vm_id))
	    {
            jui_widget_update_vm_bg_status_audio_icon(KAL_FALSE, vm_id);
	    }
    #endif
    }
    
    jma_media_player_cs_leave();

    /* To avoid other VM can not get mutex */
    PARAM_CS_ENTER();
    if (!is_video_suspend_audio && !is_med_suspend_audio)
    {
        kal_int32 _vm_id;
        jvm_state_enum vm_state;
        kal_bool is_permitted = KAL_FALSE;
        for (_vm_id = 0; _vm_id < JVM_NUM; _vm_id++)
        {
            vm_state = (jvm_state_enum)jam_mvm_get_vm_state(_vm_id);
            kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DD, 888, vm_state);
            if (vm_state == JVM_FG_RUNNING_STATE || 
                vm_state == JVM_FG_MMI_RUNNING_STATE || 
                vm_state == JVM_BG_RUNNING_STATE ||
                vm_state == JVM_SHORT_EVENT_STATE)
            {
                is_permitted = KAL_TRUE;
            }
            else if (vm_state == JVM_LONG_EVENT_STATE || 
                     vm_state == JVM_PAUSED_STATE)
            {
                is_permitted = KAL_FALSE;
                break;
            }
        }
        kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_DDD, 999, is_permitted, jma_audio_enable);
        if (is_permitted)
        {
            jma_audio_enable = KAL_TRUE;
        }
        else 
        {
            jma_audio_enable = KAL_FALSE;
        }
    }
    PARAM_CS_LEAVE();
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_vm_notify_suspend 
 * DESCRIPTION
 *  This function is invoked by MMI when VM state is changed
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_player_vm_notify_suspend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_VM_NOTIFY_SUSPEND, is_vm_suspend_audio, is_video_suspend_audio, is_med_suspend_audio);
    
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);

    if (is_vm_suspend_audio == KAL_TRUE)
    {
        return;
    }
    
    is_vm_suspend_audio = KAL_TRUE;

    if (is_med_suspend_audio || is_video_suspend_audio)
    {
        return;
    }
    
    jma_audio_player_do_suspend_job();
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_vm_notify_resume
 * DESCRIPTION
 *  This function is invoked by MMI when VM state is changed
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_player_vm_notify_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_VM_NOTIFY_RESUME, is_vm_suspend_audio, is_video_suspend_audio, is_med_suspend_audio);
    EXT_ASSERT((is_vm_suspend_audio == KAL_TRUE && 
               kal_get_active_module_id() == MOD_MMI), 
               0, 0, 0);
    
    is_vm_suspend_audio = KAL_FALSE;

    if (is_med_suspend_audio || is_video_suspend_audio)
    {
        return;
    }

    jma_audio_player_do_resume_job();
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_is_mdi_audio_usable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jma_audio_player_is_mdi_audio_usable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool mmi_in_use = KAL_FALSE;
    kal_int32 order = -1;
    kal_int32 num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_IS_MDI_AUDIO_USABLE);
    
    /* Check if MMI resource is in use now */
	if(mdi_audio_is_able_to_use_by_other_task())
	{
        mmi_in_use = KAL_FALSE;
	}
	else
	{
	    mmi_in_use = KAL_TRUE;
	}
    /* Check if Java is at first priority  */
    order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_JAVA);
    /* Check if bg play list is empty */
    num = mdi_audio_get_background_callback_register_app_num();
    kal_trace(TRACE_GROUP_8, INFO_J2ME_MMA_DDD, mmi_in_use, order, num);

    if (mmi_in_use || (num != 0 && order != 0))
    {
        return KAL_FALSE;
    }
    else 
    {
        return KAL_TRUE;
    }
}

#ifdef __JMA_PREEMPT_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  jma_vm_notify_suspend_audio_player 
 * DESCRIPTION
 *  This function is invoked when video <--> audio
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_notify_suspend_audio_player(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_VIDEO_NOTIFY_SUSPEND, is_vm_suspend_audio, is_video_suspend_audio, is_med_suspend_audio);
    
    if (is_video_suspend_audio)
    {
        return;
    }
    
    is_video_suspend_audio = KAL_TRUE;
    PARAM_CS_ENTER();
    jma_audio_enable = KAL_FALSE;
    PARAM_CS_LEAVE();  
    
    jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_TRUE);
    /* Use MMA_TYPE_DAF to cheat this API as a single player is going to play
     * and preempt all audio players. */
    ret = jma_mvm_audio_player_preempt_players(vm_id, MMA_TYPE_DAF, NULL);

    if (ret)
    {
        /* VM should clear interrupt callback when it closes all audio */
        mdi_audio_stop_use_by_other_task();
    #ifdef J2ME_SUPPORT_BACKGROUND
        /* Update Java icon */
	    if(jam_mvm_is_vm_support_bg(0))
	    {
            jui_widget_reset_vm_bg_status_audio_icon();
	    }
    #endif
    }
    
    jma_media_player_cs_leave();
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_vm_notify_resume
 * DESCRIPTION
 *  This function is invoked when video <--> audio
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jma_video_notify_resume_audio_player(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;
    kal_int32 _vm_id = INVALID_JVM_ID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_VIDEO_NOTIFY_RESUME, is_vm_suspend_audio, is_video_suspend_audio, is_med_suspend_audio);
    //ASSERT(!is_vm_suspend_audio || !is_med_suspend_audio);

    if (!is_video_suspend_audio)
    {
        return;
    }
    is_video_suspend_audio = KAL_FALSE;

    jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_TRUE);
    
    ret = jma_mvm_audio_player_resume_preempted_players(vm_id, INVALID_JAVA_PLAYER, -1, KAL_TRUE);
    /* Has executed resume && resume successfully */
    if (ret && jma_audio_player_is_active())
    {
        /* register interrupt callback */
        mdi_audio_start_use_by_other_task(jma_audio_player_interrupt_callback, NULL);
        for (_vm_id = 0; _vm_id < JVM_NUM; _vm_id++)
        {
            if (jma_audio_is_vm_players_active(_vm_id))
            {
            #ifdef J2ME_SUPPORT_BACKGROUND
                /* Update Java icon */
			    if(jam_mvm_is_vm_support_bg(vm_id))
			    {
                    jui_widget_update_vm_bg_status_audio_icon(KAL_TRUE, _vm_id);
			    }
            #endif
            }
        }
    }
    
    jma_media_player_cs_leave();

    PARAM_CS_ENTER();
    jma_audio_enable = KAL_TRUE;
    PARAM_CS_LEAVE();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_interrupt_callback
 * DESCRIPTION
 *  This function is invoked by MMI when MDI resource mastership is changed
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jma_audio_player_interrupt_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_INTERRUPT_CALLBACK, result, is_vm_suspend_audio, is_video_suspend_audio, is_med_suspend_audio);
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);

    if (result == MDI_AUDIO_TERMINATED)
    {
        is_med_suspend_audio = KAL_TRUE;

        if (is_vm_suspend_audio || is_video_suspend_audio)
        {
            return;
        }

        /* Audio resource has been suspended */
        if (jma_audio_enable == KAL_FALSE)
        {
            return;
        }
        
        jma_audio_player_do_suspend_job();
    }   
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_background_callback
 * DESCRIPTION
 *  This function is invoked by MMI when MDI resource mastership is changed
 * PARAMETERS
 *  void       
 * RETURNS
 *  int
 *****************************************************************************/
BOOL jma_audio_player_background_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = INVALID_JVM_ID;
    jvm_state_enum vm_state;
    kal_bool is_permitted = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_AUDIO_PLAYER_BACKGROUND_CALLBACK, result, is_vm_suspend_audio, is_video_suspend_audio, is_med_suspend_audio);
    
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);

    if (result == MDI_AUDIO_RESUME)
    {
        is_med_suspend_audio = KAL_FALSE;
    
        /* Always return TRUE even if VM state can not play audio */
        if (is_vm_suspend_audio)
        {   
            /* Update is_vm_suspend_audio */
            for (vm_id = 0; vm_id < JVM_NUM; vm_id++)
            {
                vm_state = (jvm_state_enum)jam_mvm_get_vm_state(vm_id);
                if (vm_state == JVM_FG_RUNNING_STATE || 
                    vm_state == JVM_FG_MMI_RUNNING_STATE || 
                    vm_state == JVM_BG_RUNNING_STATE ||
                    vm_state == JVM_SHORT_EVENT_STATE)
                {
                    is_permitted = KAL_TRUE;
                }
                else if (vm_state == JVM_LONG_EVENT_STATE || 
                         vm_state == JVM_PAUSED_STATE)
                {
                    is_permitted = KAL_FALSE;
                    break;
                }
            }
            
            if (is_permitted)
            {
                is_vm_suspend_audio = KAL_FALSE;
            }
            else
            {
                return KAL_TRUE;
            }
        }
        
        /* video/recorder/audio are mutually exclusive */
        if (is_video_suspend_audio)
        {
            return KAL_TRUE;
        }
        
        /* Audio resource has been resumed */
        if (jma_audio_enable == KAL_TRUE)
        {
            return KAL_TRUE;
        }

        jma_audio_player_do_resume_job();
    }

    return KAL_TRUE;
}

#ifdef __JMA_PREEMPT_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_vm_resume_preempted_players
 * DESCRIPTION
 *  this api is used to resume vm's preempted players when vm entry FG state from BG state
 * PARAMETERS
 *  src     [IN]        
 *  dst     [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool jma_audio_player_vm_resume_preempted_players(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_state_enum vm_state;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);
    /* When vm switch from BG to FG state, the is_video_suspend_audio should not be true */
    
    /* Always return TRUE even if VM state can not play audio */
    if (is_vm_suspend_audio)
    {   
        /* Update is_vm_suspend_audio */
        vm_state = (jvm_state_enum)jam_mvm_get_vm_state(vm_id);
        if (vm_state == JVM_FG_RUNNING_STATE || 
            vm_state == JVM_FG_MMI_RUNNING_STATE || 
            vm_state == JVM_BG_RUNNING_STATE ||
            vm_state == JVM_SHORT_EVENT_STATE)
        {
            is_vm_suspend_audio = KAL_FALSE;
        }
        else
        {
            return KAL_TRUE;
        }
    }

    if (is_video_suspend_audio || is_med_suspend_audio)
    {
        return KAL_TRUE;
    }
    
    jma_mvm_audio_resume_vm_players(vm_id);

    PARAM_CS_ENTER();
    jma_audio_enable = KAL_TRUE;
    PARAM_CS_LEAVE();

	return KAL_TRUE;
}
#endif
#ifdef SUPPORT_JSR_135_VIDEO
/*****************************************************************************
 * FUNCTION
 *  jma_media_player_exit_screen_hdlr
 * DESCRIPTION
 *  jma_media_player_exit_screen_hdlr
 * PARAMETERS
 *  src     [IN]        
 *  dst     [IN]        
 * RETURNS
 *****************************************************************************/
void jma_media_player_exit_screen_hdlr(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MEDIA_PLAYER_EXIT_SCREEN_HDLR);

    EXT_ASSERT(vm_id == jam_mvm_get_current_vm_id(), 0, 0, 0);
    
    /* Invoke at java & MMI exit screen function */    
    if (jma_audio_recorder_is_active(vm_id))
    {
        /* Do nothing */
    }
#if defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__))
    else if (jma_video_recorder_is_active(vm_id))
    {        
        EXT_ASSERT(kal_get_active_module_id() == MOD_MMI, 0, 0, 0);

        /* The same in jma_media_player_vm_notfy_suspend() */
        if (is_vm_suspend_media[vm_id] == KAL_TRUE)
        {
            return;
        }        
        is_vm_suspend_media[vm_id] = KAL_TRUE;
        
        PARAM_CS_ENTER();
        jma_media_enable[vm_id] = KAL_FALSE;
        PARAM_CS_LEAVE();
        
        jma_video_recorder_refresh_pause(vm_id);
    }
#endif /* SUPPORT_JSR_135_VIDEO && __MMI_VIDEO_RECORDER__ */    
    else
    {        
        /* Release screen memory */
        jma_media_player_vm_notfy_suspend(vm_id);
    }       
}


/*****************************************************************************
 * FUNCTION
 *  jma_media_player_entry_screen_hdlr
 * DESCRIPTION
 *  jma_media_player_entry_screen_hdlr
 * PARAMETERS
 *  src     [IN]        
 *  dst     [IN]        
 * RETURNS
 *****************************************************************************/
void jma_media_player_entry_screen_hdlr(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool in_bg_call = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MEDIA_PLAYER_ENTRY_SCREEN_HDLR);

    EXT_ASSERT(vm_id == jam_mvm_get_current_vm_id(), 0, 0, 0);
    
    /* Invoke at java & MMI entry screen function */    
    if (jma_audio_recorder_is_active(vm_id))
    {
        /* Do nothing */
    }
#if defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__))
    else if (jma_video_recorder_is_active(vm_id))
    {
   // #ifdef __MMI_BACKGROUND_CALL__    
        if (jma_media_player_is_in_background_call()) 
        {
            in_bg_call = KAL_TRUE;
        }
   // #endif /* __MMI_BACKGROUND_CALL__ */
    
        if (!in_bg_call)
        {
            /* The same in jma_media_player_vm_notfy_resume() */
            EXT_ASSERT((kal_get_active_module_id() == MOD_MMI && 
                       is_vm_suspend_media[vm_id] == KAL_TRUE), 
                       0, 0, 0);
            
            is_vm_suspend_media[vm_id] = KAL_FALSE; 
            
            jma_video_recorder_refresh_resume(vm_id);

            PARAM_CS_ENTER();
            jma_media_enable[vm_id] = KAL_TRUE;
            PARAM_CS_LEAVE();
        }
    }
#endif /* SUPPORT_JSR_135_VIDEO && __MMI_VIDEO_RECORDER__ */    
    else
    {    
    //#ifdef __MMI_BACKGROUND_CALL__    
        if (jma_media_player_is_in_background_call()) 
        {
            in_bg_call = KAL_TRUE;
        }
    //#endif /* __MMI_BACKGROUND_CALL__ */
    
        /* When end the background call, enable the video */
        if (!in_bg_call)
        {
            jma_media_player_vm_notfy_resume(vm_id);
        }
    }
        
}
#endif /* SUPPORT_JSR_135_VIDEO  */

/*****************************************************************************
 * FUNCTION
 *  jma_media_player_dependency_mutex_lock
 * DESCRIPTION
 *  This function locks media dependency mutex(es)
 * PARAMETERS
 *  none
 * RETURNS
 *  void
 *****************************************************************************/
void jma_media_player_dependency_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /************************************************************
     * MMI should lock dependency lock to sync the order with Java  
     ************************************************************/
    jui_lcd_mutex_lock();
    GDI_LOCK;
    MDI_AUDIO_LOCK;

}


/*****************************************************************************
 * FUNCTION
 *  jma_mutex_lock_no_wait
 * DESCRIPTION
 *  This function locks mutex
 * PARAMETERS
 *  none
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_mutex_lock_no_wait(kal_bool wait_gdi_lock)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /************************************************************
     * (1) For audio, Java should get MDI_LOCK only, but in order to avoid
     *     deadlock, Java MUST also get JUI_LCD and GDI_LOCK first.
     * (2) Video should also lock dependency lock to sync order with audio to avoid deadlock
     * (3) The three locks are unlocked in media_player_mutex_unlock() 
     ************************************************************/

    jui_lcd_mutex_lock();

    /* Get the 2nd lock */
    if (wait_gdi_lock)
    {
        GDI_LOCK;
    }
    else
    {        
        if (gdi_fast_mutex_lock_no_wait() == GDI_FAILED)
        {
            j2me_lcd_mutex_unlock();
            return KAL_FALSE;                
        }
    }
    
    /* Get the 3rd lock */
    if (MDI_AUDIO_LOCK_NO_WAIT == MMI_FALSE)
    {
        GDI_UNLOCK;
        /* In gdi_fast_mutex_lock(), any suspended task will sleep for one tick 
           after querying gdi_mutex.cnt. Therefore, Java also needs to sleep 
           for one tick after releasing GDI lock in order to make higher priority 
           task could get GDI_Lock successfully. */
        if (kal_get_active_module_id() != MOD_MMI && gdi_fast_mutex_get_count() == 0) 
        {
            kal_sleep_task(1);
        }
        
        j2me_lcd_mutex_unlock();
        return KAL_FALSE;  
    } 
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_media_player_dependency_mutex_unlock
 * DESCRIPTION
 *  This function unlocks dependency mutex
 * PARAMETERS
 *  none
 * RETURNS
 *  void
 *****************************************************************************/
void jma_media_player_dependency_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Unlock mutex locked at mutex_lock() */
    MDI_AUDIO_UNLOCK;
    GDI_UNLOCK;
    /* In gdi_fast_mutex_lock(), any suspended task will sleep for one tick 
       after querying gdi_mutex.cnt. Therefore, Java also needs to sleep 
       for one tick after releasing GDI lock in order to make higher priority 
       task could get GDI_Lock successfully. */
    if (kal_get_active_module_id() != MOD_MMI && gdi_fast_mutex_get_count() == 0) 
    {
        kal_sleep_task(1);
    }
    j2me_lcd_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jma_media_player_cs_check_and_enter
 * DESCRIPTION
 *  This function checks and enters audio critical section 
 * PARAMETERS
 *  is_audio_player (may rename as bg_running)
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool _jma_media_player_cs_check_and_enter(kal_int32 vm_id, kal_bool is_audio_player, kal_char *file, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type active_module_id = kal_get_active_module_id();
    kal_bool mmi_in_use = KAL_FALSE, bg_suspended = KAL_FALSE;
    kal_int32 order = -1, num = 0;
    kal_bool direct_return;
    kal_int32 vm_state;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_trace(TRACE_GROUP_8, INFO_J2ME_MMA_CS_ENTER, active_module_id, j2me_media_mutex_cnt, line, vm_id, is_audio_player);

    vm_state = jam_mvm_get_vm_state(vm_id);
    kal_trace(TRACE_GROUP_4, INFO_J2ME_MMA_D, vm_state);
    if (active_module_id != j2me_media_mutex_tid)
    {
        if (active_module_id == MOD_MMI) /* always wait */
        {
            jma_media_player_dependency_mutex_lock();
            kal_take_mutex(g_jam_media_mutex);
            j2me_media_mutex_tid = active_module_id;
        }
        else /* J2ME or Jblendia always does not wait */
        {
            if (vm_state == JVM_TERMINATE_STATE || vm_state == JVM_TERMINATING_STATE)
            {
                return KAL_FALSE;
            }
            
            if (jma_mutex_lock_no_wait(KAL_FALSE) == KAL_FALSE)
            {
                return KAL_FALSE;
            }                           

            /* Protect the parameter */
            PARAM_CS_ENTER();

            kal_trace(TRACE_GROUP_8, INFO_J2ME_MMA_DD, jma_audio_enable, jma_media_enable[vm_id]);
            if(( is_audio_player && !jma_audio_enable) ||
               (!is_audio_player && !jma_media_enable[vm_id]))
            {
                direct_return = KAL_TRUE;
            //#ifdef __MMI_BACKGROUND_CALL__    
                if ((vm_state == JVM_FG_RUNNING_STATE || vm_state == JVM_FG_MMI_RUNNING_STATE) && 
                    jma_media_player_is_in_background_call())
                {
                    direct_return = KAL_FALSE;
                }
				/* MAUI_03121973 wenmin 20120523 begin */
				#if 0
                #if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
				#endif
				/* MAUI_03121973 wenmin 20120523 end */
            //#endif /* __MMI_BACKGROUND_CALL__ */     
                /* For background running video player, to avoid it blocking other FG players to entry 
                 * synchronized block, make it take mutex here and return false at jma api.
                 */
                if ((!is_audio_player) && (vm_id != jam_mvm_get_current_vm_id()))
                {
                    direct_return = KAL_FALSE;
                }

                if (direct_return)
                {
                    PARAM_CS_LEAVE();
                    jma_media_player_dependency_mutex_unlock();
                    return KAL_FALSE;
                }
            }
            
            /* FG Running: always return true */
            if (vm_state != JVM_FG_RUNNING_STATE && vm_state != JVM_FG_MMI_RUNNING_STATE)
            {
                /* The 3rd condition: res_audio_controller has been invoked, for close_handler use */
                if (is_audio_player)
                {
                    /* Check if MMI resource is in use now */
					if(mdi_audio_is_able_to_use_by_other_task())
					{
                        mmi_in_use = KAL_FALSE;
					}
					else
					{
						mmi_in_use = KAL_TRUE;
					}
                    /* Check if someone calls suspend background play */
                    bg_suspended = mdi_audio_is_background_play_suspended();
                    /* Check if Java is at first priority  */
                    order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_JAVA);
                    /* Check if bg play list is empty */
                    num = mdi_audio_get_background_callback_register_app_num();
                    kal_trace(TRACE_GROUP_8, INFO_J2ME_MMA_DDDD, mmi_in_use, bg_suspended, order, num);

                    if (mmi_in_use || bg_suspended || (num != 0 && order != 0))
                    {
                        PARAM_CS_LEAVE();
                        jma_media_player_dependency_mutex_unlock();
                        return KAL_FALSE;
                    }
                }
            }
            
            /* Remember java can not wait in C level */
            /* In theory, the above check should return directly if java needs to wait */
            kal_take_mutex(g_jam_media_mutex);
            
            PARAM_CS_LEAVE();
            
            j2me_media_mutex_tid = active_module_id;
        }      
    }
    j2me_media_mutex_cnt++;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jma_audio_player_cs_leave
 * DESCRIPTION
 *  This function leaves audio critical section 
 * PARAMETERS
 *  
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void _jma_media_player_cs_leave(kal_char *file, kal_uint32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type active_module_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_8, INFO_J2ME_MMA_CS_LEAVE, active_module_id, j2me_media_mutex_cnt, line);
    
    EXT_ASSERT(j2me_media_mutex_tid == active_module_id, 0, 0, 0);

    j2me_media_mutex_cnt--;

    if (j2me_media_mutex_cnt == 0)
    {
        j2me_media_mutex_tid = MOD_NIL;
        kal_give_mutex(g_jam_media_mutex);
        jma_media_player_dependency_mutex_unlock();
    }    
}



/*****************************************************************************
 * FUNCTION
 *  jma_media_player_is_background_call
 * DESCRIPTION
 *  This function is to check if background call 
 * PARAMETERS
 *  is_audio_player (may rename as bg_running)
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jma_media_player_is_in_background_call(void)
{
//#ifdef __MMI_BACKGROUND_CALL__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //return mdi_audio_is_speech_mode();   

    return srv_ucm_is_any_call();
//#else /*__MMI_BACKGROUND_CALL__*/
    //return KAL_FALSE;
//#endif /*__MMI_BACKGROUND_CALL__*/
    
}



/*****************************************************************************
 * FUNCTION
 *  jma_media_player_check_critical_section
 * DESCRIPTION
 *  This function checks criticla section
 * PARAMETERS
 *       
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void jma_media_player_check_critical_section(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* Audio Playback */
    /*JMA_AUDIO_CS_ENTER(JMA_VOID);
    JMA_CS_LEAVE(JMA_VOID);*/

    /* Other */
    /*JMA_CS_ENTER(JMA_VOID);
    JMA_CS_LEAVE(JMA_VOID);*/
}


/*****************************************************************************
 * FUNCTION
 *  jma_media_player_leave_critical_section
 * DESCRIPTION
 *  This function is only for java related module, 
 *  includes J2ME, J2ME_D, JASYNC, JASYNC_D module
 * PARAMETERS
 *       
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void jma_media_player_leave_critical_section(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type active_module_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_MEDIA_PLAYER_LEAVE_CRITICAL_SECTION, active_module_id, j2me_media_mutex_tid, j2me_media_mutex_cnt);

    /* The function is for java related module now */
    EXT_ASSERT(active_module_id != MOD_MMI, 0, 0, 0);

    if (active_module_id == j2me_media_mutex_tid)
    {
        EXT_ASSERT((j2me_media_mutex_cnt != 0 && 
                   j2me_media_mutex_tid != MOD_NIL), 
                   0, 0, 0);

        j2me_media_mutex_cnt = 0;
        j2me_media_mutex_tid = MOD_NIL;
        
        kal_give_mutex(g_jam_media_mutex);
        jma_media_player_dependency_mutex_unlock();
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_reset_all_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device_type     [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void jma_reset_all_device(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_RESET_ALL_DEVICE);

    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {
        jma_device[i].device_type = JAVA_MEDIA_INVALID_DEVICE;
        jma_device[i].handle = 0;
        jma_device[i].close = NULL;
        jma_device[i].resume = NULL;
        jma_device[i].suspend = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_deregister_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device_type     [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void jma_deregister_device(int device_type, kal_int32 vm_id, int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_DEREGISTER_DEVICE, device_type, handle);

    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {
        if ((jma_device[i].device_type == device_type) && (jma_device[i].vm_id == vm_id) && (jma_device[i].handle == handle))
        {
            jma_device[i].device_type = JAVA_MEDIA_INVALID_DEVICE;
            jma_device[i].vm_id = INVALID_VM_ID;
            jma_device[i].handle = 0;
            jma_device[i].close = NULL;
            jma_device[i].resume = NULL;
            jma_device[i].suspend = NULL;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jma_register_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device_type     [IN]        
 *  handle          [IN]        
 *  suspend         [IN]        
 *  resume          [IN]        
 *  close           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void jma_register_device(
        kal_int32 device_type,
        kal_int32 vm_id,
        kal_int32 handle,
        kal_int32 (*suspend) (kal_int32 vm_id, kal_int32 handle),
        kal_int32 (*resume) (kal_int32 vm_id, kal_int32 handle),
        kal_int32 (*close) (kal_int32 vm_id, kal_int32 handle))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i, empty_entry = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    kal_trace(TRACE_GROUP_4, FUNC_J2ME_JMA_REGISTER_DEVICE, device_type, vm_id, handle);

    /* Aleady register */
    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {
        if ((jma_device[i].device_type == device_type) && (jma_device[i].vm_id == vm_id) &&(jma_device[i].handle == handle))
        {
            EXT_ASSERT(0, 0, 0, 0);
        }
    }    

    /* Find out empty entry */
    for (i = 0; i < JMA_MEDIA_DEVICE_NUM; i++)
    {
        if (jma_device[i].device_type == JAVA_MEDIA_INVALID_DEVICE)
        {
            empty_entry = i;
            break;
        }
    }

    EXT_ASSERT(empty_entry != -1, 0, 0, 0);
    
    jma_device[i].device_type = device_type;
    jma_device[i].vm_id = vm_id;
    jma_device[i].handle = handle;
    jma_device[i].suspend = suspend;
    jma_device[i].resume = resume;
    jma_device[i].close = close;
}

#if defined(SUPPORT_MMAPI) || defined(JSR135_AUDIO_ADVANCED_FEATURE)
/*****************************************************************************
 * FUNCTION
 *  jma_transfer_mdi_message_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?] 
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jma_transfer_mdi_message_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool recv = KAL_FALSE;
    kal_int32 vm_id = INVALID_JVM_ID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    vm_id = jam_mvm_get_current_vm_id();
    if (INVALID_JVM_ID == vm_id)
    {
        return KAL_FALSE;
    }
    
    /* Make sure MMAPI parameters has already been inited */
    if (jam_mvm_get_vm_state(vm_id) != JVM_TERMINATE_STATE && jam_mvm_get_vm_state(vm_id) != JVM_TERMINATING_STATE)
    {
        /* check dependency mutex first */
        do
        {
            if (jma_mutex_lock_no_wait(KAL_TRUE))
            {
                break;
            }
        } while (1);

        if (jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE))
        {
            kal_bool in_bg_call = KAL_FALSE;

       // #ifdef __MMI_BACKGROUND_CALL__    
            if (jma_media_player_is_in_background_call()) 
            {
                in_bg_call = KAL_TRUE;
            }
        //#endif /* __MMI_BACKGROUND_CALL__ */

            if (!in_bg_call)
            {
                /* dispatch message to mdi library */
                if (mdi_message_dispatcher(ilm_ptr))
                {
                    recv = KAL_TRUE;
                }
            }
            jma_media_player_cs_leave();
        }
        /* Remember to unlock the additional lock. */
        jma_media_player_dependency_mutex_unlock();
    }

    return recv;
}
/* MAUI_03121973 wenmin 20120523 begin */
#if 0
#if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
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
#ifdef SUPPORT_MMAPI     
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
/* under construction !*/
        #if defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))               
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMCORDER__))     
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
            #if (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMCORDER__))     
/* under construction !*/
            #endif
/* under construction !*/
        #endif /* defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_CAMERA__))                */     
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* SUPPORT_MMAPI */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
/* MAUI_03121973 wenmin 20120523 end */
#endif /* SUPPORT_MMAPI */
