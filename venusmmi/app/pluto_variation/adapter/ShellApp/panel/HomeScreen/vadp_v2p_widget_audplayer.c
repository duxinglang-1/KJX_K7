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
 * Filename:
 * ---------
 *  vadp_v2p_widget_audplayer.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Venus APP ---> v2p adaptor ---> Pluto APP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/ 
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__
/* Pluto headers: */
#include "MediaPlayerGProt.h"
#include "MediaPlayerEnumDef.h"
#include "MediaAppWidgetDef.h"
#include "AudioPlayerProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
/* Venus headers: */
#include "HomeScreen\vadp_v2p_widget_audplayer.h"
#include "vapp_hs_def.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_media_app_trc.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "vfx_datatype.h"
#include "MMIDataType.h"

#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
#include "gui_effect_oem.h"
#endif 
/*****************************************************************************
* Local Function 
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_audplayer_button_process
 * DESCRIPTION
 *  Map widget button actions to application relative functions.
 * PARAMETERS
 *  button_type     [IN]        Widget button type
 *  pen_event       [IN]        Widget pen event
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_audplayer_button_process(VappHsWidgetButtonTypeEnum button_type, VappHsWidgetPenTypeEnum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_widget_player_button_enum button = (mmi_widget_player_button_enum)0;
    mmi_widget_player_key_event_enum event = (mmi_widget_player_key_event_enum)0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_AUDPLY_BUTTON_PRECESS, button_type, pen_event);
    
    switch(button_type)
    {
        case VAPP_HS_WIDGET_BUTTON_PLAY:
        case VAPP_HS_WIDGET_BUTTON_PAUSE:
        {
            button = MMI_WIDGET_PLAYER_PLAY_PAUSE;
            break;
        }

        case VAPP_HS_WIDGET_BUTTON_STOP:
        {
            button = MMI_WIDGET_PLAYER_STOP;
            break;
        }
            
        case VAPP_HS_WIDGET_BUTTON_PREV:
        {
            button = MMI_WIDGET_PLAYER_PREV;
            break;
        }

        case VAPP_HS_WIDGET_BUTTON_NEXT:
        {
            button = MMI_WIDGET_PLAYER_NEXT;
            break;
        }
            
        default:
            ASSERT(0);
    }

    switch(pen_event)
    {
        case VAPP_HS_WIDGET_PEN_EVENT_DOWN:
        {
            event = MMI_WIDGET_PLAYER_KEY_DOWN;
            break;  
        }

          case VAPP_HS_WIDGET_PEN_EVENT_UP:
          {
              event = MMI_WIDGET_PLAYER_KEY_UP;
              break;    
          }

          case VAPP_HS_WIDGET_PEN_EVENT_CANCEL:
          {
              event = MMI_WIDGET_PLAYER_KEY_CANCELED;
              break;    
          }

          default:
            ASSERT(0);
    }

    if (button == MMI_WIDGET_PLAYER_PLAY_PAUSE && event == MMI_WIDGET_PLAYER_KEY_UP)
    {
    #if defined __MMI_MEDIA_PLAYER__
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);
        mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    #endif    
    }
#if defined __MMI_MEDIA_PLAYER__
    mmi_medply_widget_button_action(button,event);
#elif defined __MMI_AUDIO_PLAYER__
    mmi_audply_widget_button_action(button, event);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_audplayer_register_callback
 * DESCRIPTION
 *  Register callback function.
 * PARAMETERS
 *  userdata        [IN]    C++ this pointer
 *  callback        [IN]    Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_audplayer_register_callback(void* userdata, void(*callback)(void*, VfxU32, void*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __MMI_MEDIA_PLAYER__
    mmi_medply_widget_register_callbacks(userdata, (void(*)(void*, mmi_widget_player_callback_enum, void*))callback);
#elif defined __MMI_AUDIO_PLAYER__
    mmi_audply_widget_register_callback(userdata, (void(*)(void*, mmi_widget_player_callback_enum, void*))callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_audplayer_deregister_callback
 * DESCRIPTION
 *  De-register callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_audplayer_deregister_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __MMI_MEDIA_PLAYER__
    mmi_medply_widget_register_callbacks(NULL,(void(*)(void*, mmi_widget_player_callback_enum, void*))NULL);
#elif defined __MMI_AUDIO_PLAYER__
    mmi_audply_widget_register_callback(NULL, (void(*)(void*, mmi_widget_player_callback_enum, void*))NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_audioplayer_state_transform
 * DESCRIPTION
 *  Map application state to widget state
 * PARAMETERS
 *  audio_player_state      [IN]        Application state
 * RETURNS
 *  widget state            Widget state
 *****************************************************************************/
U8 vadp_v2p_audioplayer_state_transform(U8 audio_player_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __MMI_MEDIA_PLAYER__
    mmi_medply_widget_state_enum media_player_state = (mmi_medply_widget_state_enum)audio_player_state;
    switch(media_player_state)
    {
        case MEDPLY_WIDGET_STATE_IDLE:
        {
            return VAPP_WIDGET_AUDPLAYER_STATE_INIT;
        }

        case MEDPLY_WIDGET_STATE_PLAY:
        {
            return VAPP_WIDGET_AUDPLAYER_STATE_PLAY;
        }

        case MEDPLY_WIDGET_STATE_PROCESSING:
        {
            return VAPP_WIDGET_AUDPLAYER_STATE_PROCESS;
        }
        
        default:
        {
            ASSERT(0);
        }
    }
#elif defined __MMI_AUDIO_PLAYER__
    switch(audio_player_state)
    {
        case AUDPLY_AIDGET_STATE_IDLE:
        {
            return VAPP_WIDGET_AUDPLAYER_STATE_INIT;
        }
        case AUDPLY_AIDGET_STATE_PLAY:
        {
            return VAPP_WIDGET_AUDPLAYER_STATE_PLAY;
        }
        case AUDPLY_AIDGET_STATE_PROCESS:
        {
            return VAPP_WIDGET_AUDPLAYER_STATE_PROCESS;
        }
        default:
        {
            ASSERT(0);
        }
    }
#endif

    return VAPP_WIDGET_AUDPLAYER_STATE_INIT;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_audplayer_get_info
 * DESCRIPTION
 *  Get information
 * PARAMETERS
 *  info_type       [IN]        Information type
 *  result_ptr      [OUT]       Result
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_audplayer_get_info(VappHsWidgetAudplayerGetInfoEnum info_type, void* result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_AUDPLY_GET_INFO, info_type);
    
#if defined __MMI_MEDIA_PLAYER__
    switch(info_type)
    {
        case VAPP_HS_WIDGET_AUDPLAYER_INFO_STATE:
        {
            /*U8*/
            U8 state;
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_CUR_STATE, &state);
            *((U8*)result_ptr) = vadp_v2p_audioplayer_state_transform(state);
            break;
        }

        case VAPP_HS_WIDGET_AUDPLAYER_INFO_TITLE:
        {
            /*assign title string to result_ptr, max lengh MEDPLY_MAX_FILE_LEN*/
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_FILENAME, result_ptr);
            break;
        }

        case VAPP_HS_WIDGET_AUDPLAYER_INFO_DURATION:
        {
            /*U64*/
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_TOTAL_DURATION, result_ptr);
            break;
        }

        case VAPP_HS_WIDGET_AUDPLAYER_INFO_CURR_TIME:
        {
            /*U64*/
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_CUR_TIME, result_ptr);
            break;
        }

        case VAPP_HS_WIDGET_AUDPLAYER_INFO_PAUSE_DISABLE:
        {
            /* MMI_BOOL */
            MMI_BOOL temp;
            mmi_medply_widget_get_value(MMI_WIDGET_PLAYER_IS_PAUSE_DISABLED, &temp);

            *(VfxS32*)result_ptr = temp ? TRUE : FALSE;
            break;
        }
        
        default:
            ASSERT(0);
    }
#elif defined __MMI_AUDIO_PLAYER__
    switch(info_type)
    {
        case VAPP_HS_WIDGET_AUDPLAYER_INFO_STATE:
        {
            /*U8*/
            U8 state;
            mmi_audply_widget_get_value(MMI_WIDGET_PLAYER_CUR_STATE, &state);
            *((U8*)result_ptr) = vadp_v2p_audioplayer_state_transform(state);
            break;
        }

        case VAPP_HS_WIDGET_AUDPLAYER_INFO_TITLE:
        {
            /*assign title string to result_ptr, max lengh MEDPLY_MAX_FILE_LEN*/
            mmi_audply_widget_get_value(MMI_WIDGET_PLAYER_FILENAME, result_ptr);
            break;
        }

        case VAPP_HS_WIDGET_AUDPLAYER_INFO_DURATION:
        {
            /*U64*/
            mmi_audply_widget_get_value(MMI_WIDGET_PLAYER_TOTAL_DURATION, result_ptr);
            break;
        }

        case VAPP_HS_WIDGET_AUDPLAYER_INFO_CURR_TIME:
        {
            /*U64*/
            mmi_audply_widget_get_value(MMI_WIDGET_PLAYER_CUR_TIME, result_ptr);
            break;
        }

        case VAPP_HS_WIDGET_AUDPLAYER_INFO_PAUSE_DISABLE:
        {
            *(VfxS32*)result_ptr = FALSE;
            break;
        }            
        default:
            ASSERT(0);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_audplayer_is_ready
 * DESCRIPTION
 *  Check if the playlist is ready. 
 * PARAMETERS
 *  void
 * RETURNS
 *  result      ready or not      
 *****************************************************************************/
VfxU32 vadp_v2p_audplayer_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __MMI_MEDIA_PLAYER__
    result = mmi_medply_widget_is_plst_ready();
#elif defined __MMI_AUDIO_PLAYER__
    result = mmi_audply_is_ready_to_play();
#endif
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_AUDPLY_IS_READY, result);

    return (VfxU32)result;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_audplayer_launch_app
 * DESCRIPTION
 *  lauch application 
 * PARAMETERS
 *  void
 * RETURNS
 *  void   
 *****************************************************************************/
void vadp_v2p_audplayer_launch_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_VUI_ENGINE__)
    gui_screen_switch_effect_v2p_setup_widget();
#endif

#if defined __MMI_MEDIA_PLAYER__
    mmi_medply_app_pre_entry();
#elif defined __MMI_AUDIO_PLAYER__
    mmi_audply_entry_main();    
#endif
}
#endif /* __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__ */
