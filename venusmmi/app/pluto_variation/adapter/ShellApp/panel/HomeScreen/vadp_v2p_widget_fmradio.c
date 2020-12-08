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
 *  vadp_v2p_fmradio.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/ 
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__

#include "FMRadioDef.h"
#include "FMRadioProt.h"
#include "mdi_audio.h"
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
#include "gui_effect_oem.h"
#endif 
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "vapp_hs_def.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_media_app_trc.h"
#include "GpioSrvGprot.h"
#include "mdi_datatype.h"
#include "kal_public_api.h"
#include "vfx_datatype.h"
#include "Unicodexdcl.h"

void vadp_v2p_fmr_get_state(U8* result_ptr);
MMI_BOOL vadp_v2p_fmr_is_searching(void);
/*****************************************************************************
* Local Function 
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_fmr_button_process
 * DESCRIPTION
 *  Map widget button actions to application relative functions.
 * PARAMETERS
 *  button_type     [IN]        Widget button type
 *  pen_event       [IN]        Widget pen event
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_fmr_button_process(VappHsWidgetButtonTypeEnum button_type, VappHsWidgetPenTypeEnum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_FMR_BUTTON_PRECESS, button_type, pen_event);
    
    switch(button_type)
    {
        case VAPP_HS_WIDGET_BUTTON_PLAY:
            if (VAPP_HS_WIDGET_PEN_EVENT_UP)
            {
                /* FM Radio need to be initialized before playing first time */
            #if defined(__MMI_FM_RADIO_BIND_EARPHONE__)
                if (!srv_earphone_is_plug_in())
                {
                    mmi_fmrdo_plug_in_earphone_msg();
                    return;
                }
            #endif
                if (mmi_fmrdo_need_init())
                {
                    mmi_fmrdo_init_nvram();
                }
                /* Power on FM and if on main screen update it */
                mmi_fmrdo_power_on(TRUE);
                mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued, NULL);
                mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_FMR);
            }
            break;

        case VAPP_HS_WIDGET_BUTTON_STOP:
            if (VAPP_HS_WIDGET_PEN_EVENT_UP)
            {
                /* Power off FM and if on main screen update it */
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_FMR);
                mmi_fmrdo_power_on(FALSE);
            }
            break;

        case VAPP_HS_WIDGET_BUTTON_PREV:
            if (VAPP_HS_WIDGET_PEN_EVENT_UP)
            {
                U8 state;
                vadp_v2p_fmr_get_state(&state);
                if (state == VAPP_WIDGET_FMR_STATE_INIT ||
                    state == VAPP_WIDGET_FMR_STATE_PLAY_NO_LIST)
                {
                    mmi_fmrdo_init_ch_list_msg();
                    return;
                }
                /* Go to previous channel: play channel previous to current channel,
                   if only 1 channel present then return,
                   If no current channel then play last available channel  */
                mmi_fmrdo_main_goto_previous_channel();
            }
            break;

        case VAPP_HS_WIDGET_BUTTON_NEXT:
            if (VAPP_HS_WIDGET_PEN_EVENT_UP)
            {
                U8 state;
                vadp_v2p_fmr_get_state(&state);
                if (state == VAPP_WIDGET_FMR_STATE_INIT ||
                    state == VAPP_WIDGET_FMR_STATE_PLAY_NO_LIST)
                {
                    mmi_fmrdo_init_ch_list_msg();
                    return;
                }
                /* Go to next channel: play channel next to current channel,
                   if only 1 channel present then return,
                   If no current channel then play first available channel  */
                mmi_fmrdo_main_goto_next_channel();
            }
            break;
            
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_fmr_register_callback
 * DESCRIPTION
 *  Register callback function.
 * PARAMETERS
 *  userdata        [IN]    C++ this pointer
 *  callback        [IN]    Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_fmr_register_callback(void* userdata, void(*callback)(void*, VfxU32))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* callback is called when FM stops due to any interrupt (FM may resume later)
        and if background handler is cleared for FM (callback called with FM in stopped state). */
    mmi_fmrdo_set_preempted_callback(userdata, (void(*)(void*, U32))callback);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_fmr_deregister_callback
 * DESCRIPTION
 *  De-register callback function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_fmr_deregister_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* callback is called when FM stops due to any interrupt (FM may resume later)
        and if background handler is cleared for FM (callback called with FM in stopped state). */
    mmi_fmrdo_set_preempted_callback(NULL, (void(*)(void*, U32))NULL);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_fmr_get_state
 * DESCRIPTION
 *  Map application state to widget state
 * PARAMETERS
 *  result_ptr      [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_fmr_get_state(U8* result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;
    S16 channel_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_get_cur_channel_idx(&channel_idx);
    mmi_fmrdo_get_cur_state(&state);
    
    if (vadp_v2p_fmr_is_searching())
    {   
        *result_ptr = VAPP_WIDGET_FMR_STATE_SEARCHING;
    }
    else if ((mmi_fmrdo_get_channel_count() <= 0) && !mmi_fmrdo_is_power_on())
    {
        *result_ptr = VAPP_WIDGET_FMR_STATE_INIT;
    }
    else if(mmi_fmrdo_is_power_on() && (mmi_fmrdo_get_channel_count() <= 0))
    {
        *result_ptr = VAPP_WIDGET_FMR_STATE_PLAY_NO_LIST;
    }
    else if (!mmi_fmrdo_is_power_on())
    {
        *result_ptr = VAPP_WIDGET_FMR_STATE_READY;
    }
    else
    {
        *result_ptr = VAPP_WIDGET_FMR_STATE_PLAY;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_FMR_GET_STATE, *result_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_fmr_get_info
 * DESCRIPTION
 *  Get information
 * PARAMETERS
 *  info_type       [IN]        Information type
 *  result_ptr      [OUT]       Result
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_fmr_get_info(VappHsWidgetFmrGetInfoEnum info_type, void* result_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, VADP_FMR_GET_INFO, info_type);
    
    if (mmi_fmrdo_need_init())
    {
        mmi_fmrdo_init_nvram();
    }
    switch(info_type)
    {
        case VAPP_HS_WIDGET_FMR_INFO_STATE:
            vadp_v2p_fmr_get_state((U8*)result_ptr);
            break;

        case VAPP_HS_WIDGET_FMR_INFO_CH_TITLE:
            /* Channel_name points to channel name or will be NULL */
            mmi_fmrdo_get_cur_channel_name((PU8*)result_ptr);
            break;

        case VAPP_HS_WIDGET_FMR_INFO_CH_NUM:
            mmi_fmrdo_get_cur_channel_idx((S16*)result_ptr);
            break;
        default:
            ASSERT(0);
    }
} 


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_fmr_copy_title
 * DESCRIPTION
 *  Copy the string
 * PARAMETERS
 *  dest_ptr        [IN]    Destination string
 *  source_ptr      [IN]    Source string
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_fmr_copy_title(void* dest_ptr, void* source_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR *) dest_ptr, (CHAR *)source_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_fmr_is_searching
 * DESCRIPTION
 *  Check if FM radio is searching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vadp_v2p_fmr_is_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_get_cur_state(&state);
    return (state == FMRDO_STATE_SEARCH_ALL || state == FMRDO_STATE_SEARCH_ONE);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_fmr_launch_app
 * DESCRIPTION
 *  Lanuch app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_fmr_launch_app(void)
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

    mmi_fmrdo_run_app();
}
#endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */
