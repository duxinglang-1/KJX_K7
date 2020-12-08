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
 * GpioSpeechSrv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Utility functions for GPIO
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_include.h"

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "device.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "mmi_msg_struct.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "kal_general_types.h"

#include "ProtocolEvents.h"
#include "BootupSrvGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "UcmSrvGprot.h"
#include "GpioSrvGprot.h"
#include "GpioSrvprot.h"
#include "mmi_rp_srv_gpio_def.h"
#if defined(__KJX_FUN__)
#include "TimerEvents.h"
#include "Kjx_prin.h"
#endif
/***************************************************************************** 
* Local variable
*****************************************************************************/
static MMI_BOOL g_is_phone_mute = MMI_FALSE;
static U8 g_earphone_plugged = 0;
static MMI_BOOL g_earphone_status_changed = MMI_FALSE;

static U8 aud_mode_to_resume;
static U8 srv_speech_get_audio_mode_level(void);

#if defined(__KJX_FUN__)
U8 kjx_get_earphone_plugged(void)
{
	return g_earphone_plugged;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_earphone_status_changed
 * DESCRIPTION
 *  Function to be called before entry into idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_earphone_status_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_earphone_status_changed;
}


/*****************************************************************************
 * FUNCTION
 *  srv_earphone_bootup_callback
 * DESCRIPTION
 *  Function to be called before entry into idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_earphone_bootup_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_EARPHONE_BOOTUP_CALLBACK);
    if (g_earphone_plugged)
    {
        srv_gpio_post_event(EVT_ID_GPIO_EARPHONE_PLUG_IN);
    }
    else
    {
        srv_gpio_post_event(EVT_ID_GPIO_EARPHONE_PLUG_OUT);
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_earphone_is_plug_in
 * DESCRIPTION
 *  tell other applications if the earphone exist
 * PARAMETERS
 *  void
 * RETURNS
 *  yse or no
 *****************************************************************************/
MMI_BOOL srv_earphone_is_plug_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_earphone_plugged == 1)
    {
	    if (srv_gpio_emit_event(EVT_ID_GPIO_EARPHONE_QUERY_CTRL))
			return MMI_TRUE;
	}

	return MMI_FALSE;
}

#if defined(__KJX_FUN__)	//xb add 2016-09-19 耳机插拔处理
extern void kjx_factory_earphone_plugout(void);
extern void kjx_factory_earphone_plugin(void);

void kjx_send_earphone_plug_out_event(void)
{
	srv_speech_enable_hand_free();
}

void kjx_send_earphone_plug_in_event(void)
{
	srv_speech_disable_hand_free();
}
#endif
/*****************************************************************************
 * FUNCTION
 *  EarphoneConnectHdlr
 * DESCRIPTION
 *  General handler for earphone plug in/out
 *  
 *  PARAMETERS: is_in
 *  is_in       [IN]        
 *****************************************************************************/
void srv_earphone_connect_hdlr(MMI_BOOL is_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    if (srv_bootup_is_booting() || srv_bootup_is_launched())
    {
        g_earphone_status_changed = MMI_TRUE;
    }
	
#if defined(__KJX_FUN__)/*喇叭、咪头无效处理*/
    if(is_in)
    {
	#if defined(__KJX_LOG_OUTPUT__)
		LOGD("g_earphone_plugged_in");
	#endif
    	
        g_earphone_plugged = 1;
        if((kjx_get_foctory_test_mode() == 1) && (kjx_get_test_mode_earphone()==1))
        {
            kjx_factory_earphone_plugin();
        }
	#if 0 
		/* under construction !*/
		/* under construction !*/
		/* under construction !*/
		/* under construction !*/
		/* under construction !*/
		/* under construction !*/
	#endif
		MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_EARPHONE_IN);
        srv_gpio_post_event(EVT_ID_GPIO_EARPHONE_PLUG_IN);
		
	#if defined(__KJX_FUN__)
	#if defined(CUSTOMER_NAME_TOUR)
		StartTimer(KJX_TIMER_ID_EARPHONE_PLUG_NOTIFY, 300, kjx_send_earphone_plug_in_event);
	#endif
	#endif
    }
    else
#endif
    {
    #if defined(__KJX_LOG_OUTPUT__)
		LOGD("g_earphone_plugged_out");
	#endif
        g_earphone_plugged = 0;
        if((kjx_get_foctory_test_mode() == 1) && (kjx_get_test_mode_earphone()==2))
        {
            kjx_factory_earphone_plugout();
        }

	#if 0 
		/* under construction !*/
		/* under construction !*/
		/* under construction !*/
		/* under construction !*/
		/* under construction !*/
		/* under construction !*/
		/* under construction !*/
	#endif
		MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_EARPHONE_OUT);

        srv_gpio_post_event(EVT_ID_GPIO_EARPHONE_PLUG_OUT);

	#if defined(__KJX_FUN__)
	#if defined(CUSTOMER_NAME_TOUR)
		StartTimer(KJX_TIMER_ID_EARPHONE_PLUG_NOTIFY, 300, kjx_send_earphone_plug_out_event);
	#endif
	#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_is_hand_free
 * DESCRIPTION
 *  Enables Hands Free Mode
 *  
 *  PARAMETERS: mode
 *  void
 *****************************************************************************/
MMI_BOOL srv_speech_is_hand_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_enable_hand_free
 * DESCRIPTION
 *  Enables Hands Free Mode
 *  
 *  PARAMETERS: mode
 *  void
 *****************************************************************************/
void srv_speech_enable_hand_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_gpio_post_event(EVT_ID_GPIO_ENABLE_HAND_FREE);
    mdi_audio_set_audio_mode(AUD_MODE_LOUDSPK);
    srv_speech_set_mode_volume();
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_disable_hand_free
 * DESCRIPTION
 *  Disables Hands Free Mode
 *  
 *  PARAMETERS: mode
 *  void
 *****************************************************************************/
void srv_speech_disable_hand_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_gpio_post_event(EVT_ID_GPIO_DISABLE_HAND_FREE);
	
    if (g_earphone_plugged)        
    {        
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
        srv_speech_set_mode_volume();
    }
    else
    {
        mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
        srv_speech_set_mode_volume();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_save_mode_volume
 * DESCRIPTION
 *  Saves Speech Volume
 *  
 *  PARAMETERS:
 *  level       [IN]        
 *****************************************************************************/
void srv_speech_save_mode_volume(U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 audio_mode = mdi_audio_get_audio_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audio_mode)
    {
        case AUD_MODE_NORMAL:
            WriteValue(NVRAM_NORMAL_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_HEADSET:
            WriteValue(NVRAM_HDSET_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_LOUDSPK:
            WriteValue(NVRAM_LDSPK_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
    }
    srv_speech_set_volume(level);
}

static U8 srv_speech_get_audio_mode_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 audio_mode = mdi_audio_get_audio_mode();
    U8 level=0;
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audio_mode)
    {
        case AUD_MODE_NORMAL:
            ReadValue(NVRAM_NORMAL_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_HEADSET:
            ReadValue(NVRAM_HDSET_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
        case AUD_MODE_LOUDSPK:
            ReadValue(NVRAM_LDSPK_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
            break;
    }
    return level;

}
/*****************************************************************************
 * FUNCTION
 *  srv_speech_set_mode_volume
 * DESCRIPTION
 *  Sets Speech Volume as per the mode
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void srv_speech_set_mode_volume(void)
{
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
#endif
    U8 level=0;
    S16 error;

    level = srv_speech_get_audio_mode_level();
    if(level == 0xFF)
    {             
        level = MDI_AUD_VOL_6;
        WriteValue(NVRAM_HDSET_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
        WriteValue(NVRAM_LDSPK_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
        WriteValue(NVRAM_NORMAL_MODE_VOICE_LEVEL, &level, DS_BYTE, &error);
    }
    srv_speech_set_volume(level);
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_get_mode_volume
 * DESCRIPTION
 *  Gets Speech Volume as per the mode
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
U8 srv_speech_get_mode_volume(void)
{
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
#endif
    U8 level=0;

    level = srv_speech_get_audio_mode_level();
    if (level == 0xFF)
    {
	#ifdef __KJX_FUN__
		level = MDI_AUD_VOL_6;
	#else
        level = MDI_AUD_VOL_3;
	#endif	
    }

    return level;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_mute_req
 * DESCRIPTION
 *  To set Device to mute on/off, Device type: AUDIO_DEVICE_SPEAKER...(AUDIO_DEVICE_XXX)
 *  can set MicroPhone/Speaker/Speaker2 to mute on or off
 * PARAMETERS
 *  device    [IN] srv_gpio_audio_device_enum, refer audio_type_enum defined in Device.h
 *  mute_on   [IN] MMI_TRUE: mute on; MMI_FALSE: mute off
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gpio_set_device_mute(srv_gpio_audio_device_enum device, MMI_BOOL mute_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_mute_req_struct *setMuteReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_SET_DEVICE_MUTE, device, mute_on);
    setMuteReq = OslConstructDataPtr(sizeof(mmi_eq_set_mute_req_struct));
    setMuteReq->audio_device = device;
    setMuteReq->mute_onoff = mute_on;

    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_SET_MUTE_REQ, 
                        (oslParaType*) setMuteReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_is_phone_mute
 * DESCRIPTION
 *  This function informs whethere the phone is in mute or not.
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void   
 * RETURNS
 *  returns MMI_TRUE if muted else MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_speech_is_phone_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_phone_mute;
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_mute_phone
 * DESCRIPTION
 *  This function mutes the phone i,e currently changing the global flag.
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_speech_mute_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_phone_mute = MMI_TRUE;
    srv_gpio_set_device_mute(AUDIO_DEVICE_MICROPHONE, MMI_TRUE);
    srv_gpio_post_event(EVT_ID_GPIO_MUTE_PHONE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_unmute_phone
 * DESCRIPTION
 *  This function unmutes the phone i,e currently changing the global flag.
 *  This is a part of other hardware application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_speech_unmute_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_phone_mute = MMI_FALSE;
    srv_gpio_set_device_mute(AUDIO_DEVICE_MICROPHONE, MMI_FALSE);
    srv_gpio_post_event(EVT_ID_GPIO_UNMUTE_PHONE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_at_set_mute
 * DESCRIPTION
 *  AT Command set Mute
 * PARAMETERS
 *  msg     [?]     Set mute on/off request
 * RETURNS
 *  void
 *****************************************************************************/
void srv_speech_at_set_mute(void *msg)
{
#ifndef __SLIM_AT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_eq_set_mute_req_struct *msgReq = (mmi_eq_set_mute_req_struct*) msg;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        return;
    }
   
    switch (msgReq->audio_device)
    {
        case AUDIO_DEVICE_MICROPHONE:
            if ((msgReq->mute_onoff == MMI_TRUE) && !srv_speech_is_phone_mute())
            {
                srv_speech_mute_phone();
            }
            else if ((msgReq->mute_onoff == MMI_FALSE) && srv_speech_is_phone_mute())
            {
                srv_speech_unmute_phone();
            }
            break;

        case AUDIO_DEVICE_SPEAKER:
            if (msgReq->mute_onoff == MMI_TRUE)
            {
                srv_gpio_set_device_mute(AUDIO_DEVICE_SPEAKER, MMI_TRUE);
            }
            else
            {
                srv_gpio_set_device_mute(AUDIO_DEVICE_SPEAKER, MMI_FALSE);
            }
            break;

        default:
            break;
    }
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_at_query_mute
 * DESCRIPTION
 *  Query mute mode setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void srv_speech_at_query_mute(void *msg, int mod_id)
{
#ifndef __SLIM_AT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_query_mute_mode_res_req_struct *res_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_msg = (mmi_eq_query_mute_mode_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_mute_mode_res_req_struct));

    if (srv_speech_is_phone_mute())
    {
        res_msg->mode = MMI_TRUE;
    }
    else
    {
        res_msg->mode = MMI_FALSE;
    }

    srv_gpio_send_message(mod_id, PRT_MMI_EQ_QUERY_MUTE_MODE_RES_REQ, res_msg, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_at_set_hand_free
 * DESCRIPTION
 *  Query mute mode setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void srv_speech_at_set_hand_free(void *msg, int source, void *data)
{
#ifndef __SLIM_AT__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_eq_set_hand_free_mode_req_ind_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmi_eq_set_hand_free_mode_req_ind_struct*) msg;    
    
    if (req->is_hand_free)
    {
        srv_speech_enable_hand_free();
    }
    else
    {
        srv_speech_disable_hand_free();
    }
#endif   
}


/*****************************************************************************
 * FUNCTION
 *  srv_speech_at_query_hand_free
 * DESCRIPTION
 *  Query mute mode setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
void srv_speech_at_query_hand_free(void *msg, int source, void *data)
{
#ifndef __SLIM_AT__  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_query_hand_free_mode_res_req_struct *rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    rsp = (mmi_eq_query_hand_free_mode_res_req_struct*) 
        OslConstructDataPtr(sizeof(mmi_eq_query_hand_free_mode_res_req_struct));
   
    rsp->is_hand_free = (kal_bool)srv_speech_is_hand_free();

    srv_gpio_send_message(source, MSG_ID_MMI_EQ_QUERY_HAND_FREE_MODE_RES_REQ, (void*)rsp, NULL);
#endif  
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_volume
 * DESCRIPTION
 *  To set Volume level to Volume Type, e.g. VOL_TYPE_KEY... (VOL_TYPE_XXX)
 *  can set rigner/keypad/speech/... volume
 * PARAMETERS
 *  type    [IN] srv_gpio_vol_type_enum, refer volume_type_enum defined in Device.h
 *  volume  [IN] volume level, no more than MAX_VOL_LEVEL
 * RETURNS
 *  void
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
/* under construction !*/
/* under construction !*/
#endif


