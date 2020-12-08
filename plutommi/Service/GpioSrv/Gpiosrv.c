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
 * GpioSrv.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "UcmSrvGprot.h"
#include "Device.h"
#include "PoweronChargerProt.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_gprot.h"

#include "mmiapi_enum.h"
#include "mmiapi_struct.h"
#include "CharBatSrvGprot.h"
#include "GpioSrvGprot.h"
#include "GpioSrvprot.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "device.h"
#include "mmi_msg_struct.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "kal_public_api.h"
#include "custom_led_patterns.h"
#include "l4c_nw_cmd.h"
#include "IdleAppDef.h"
#include "custom_srv_prof_defs.h"
#include "kal_general_types.h"
/* auto add by kw_check end */

/***************************************************************************** 
* Local variable
*****************************************************************************/
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && !defined(__AMNT__)
#if defined (__MTK_TARGET__)
static U8 g_clam_state = 0;   /* Sync with Drv state */
#else 
static U8 g_clam_state = 1;
#endif 
//#else 
//static U8 g_clam_state = 1;
#endif 

static U8 gpioOutOfCtrl;    /* for LED */
#if 0 
/* under construction !*/
#endif
static U8 g_gpio_pending_vib_stop = MMI_FALSE;    /* for pending Vibrator stop*/
static U8 g_gpio_pending_vib_stop_id;    /* for pending Vibrator stop id*/

static U8 IsCallerGroupPatternPlaying;
static MMI_BOOL g_led_pattern_flag;
#ifdef __OP01_FWPBW__
static MMI_BOOL g_gpio_transmitter_is_hold_on;
#endif

static srv_gpio_pwron_ready_struct g_srv_gpio_pwron_ready_s = {
                                        MMI_FALSE, 
                                        NULL,
                                        NULL};

static void srv_vibrator_req_hdlr(void *msg);
#if 0 
/* under construction !*/
#endif
static void srv_gpio_play_req_hdlr(void *inMsg);
#if 0
/* under construction !*/
#endif
/***************************************************************************** 
* External variable
*****************************************************************************/
srv_gpio_property_info_struct g_srv_gpio_property_info = {
                                    MMI_FALSE, // keypad_locked
                                    0         // curr_mode
                                    };


/***************************************************************************** 
* External functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_init
 * DESCRIPTION
 *  Initialisation function for Back Light Test
 *  
 *  PARAMETERS: void
 *  void
 *****************************************************************************/
void srv_gpio_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_backlight_set_mode, MSG_ID_MMI_EQ_SET_SLEEP_MODE_REQ_IND);
    SetProtocolEventHandler(srv_speech_at_query_mute, PRT_MMI_EQ_QUERY_MUTE_MODE_REQ_IND);
    SetProtocolEventHandler(srv_speech_at_set_mute, PRT_MMI_EQ_MUTE_CHANGE_IND);
 
    SetProtocolEventHandler(srv_backlight_at_set_level_hdlr, MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ_IND);
    SetProtocolEventHandler(srv_backlight_at_query_level_hdlr, MSG_ID_MMI_AT_CBKLT_QUERY_REQ_IND);

    SetProtocolEventHandler(srv_speech_at_set_hand_free, MSG_ID_MMI_EQ_SET_HAND_FREE_MODE_REQ_IND);
    SetProtocolEventHandler(srv_speech_at_query_hand_free, MSG_ID_MMI_EQ_QUERY_HAND_FREE_MODE_REQ_IND);
}



/*****************************************************************************
 * FUNCTION
 *  srv_gpio_shutdown_hdlr
 * DESCRIPTION
 *  to enable necessary indication when shutdown
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
mmi_ret srv_gpio_shutdown_hdlr(mmi_event_struct *evt)
{
    SetProtocolEventHandler(srv_vibrator_req_hdlr, MSG_ID_MMIAPI_GPIO_POST_VIB_REQ);
    SetProtocolEventHandler(srv_gpio_detect_ind_hdlr, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_event_hdlr
 * DESCRIPTION
 *  set event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_gpio_set_event_hdlr(void)
{
    /* GPIO device Detect indication event handler */
    SetProtocolEventHandler(srv_gpio_detect_ind_hdlr, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
    #if 0
/* under construction !*/
    #endif
    SetProtocolEventHandler(srv_gpio_play_req_hdlr, MSG_ID_MMIAPI_DEVICE_PLAY_REQ);
     #if 0 
/* under construction !*/
/* under construction !*/
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_gpio_emit_event
 * DESCRIPTION
 *  emit GPIO event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_gpio_emit_event(U16 event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    mmi_ret ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, event_id);
    ret = mmi_frm_cb_emit_event(&evt);

    if (ret == MMI_RET_OK || ret == MMI_RET_ERR_NO_REG_CB)
        return MMI_TRUE;

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_post_event
 * DESCRIPTION
 *  emit GPIO event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gpio_post_event(U16 event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, event_id);
    mmi_frm_cb_emit_post_event(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_send_message
 * DESCRIPTION
 *  Send message to other modules
 *  
 *  PARAMETERS: mmiapi_device_play_req_struct *
 *  src_mod_id          [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]        
 *  peer_buf_ptr        [IN]        
 *****************************************************************************/
void srv_gpio_send_message(int src_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType) src_mod_id, (oslMsgType) msg_id, 
                        (oslParaType*) local_param_ptr, (oslPeerBuffType *)peer_buf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_device_level
 * DESCRIPTION
 *  Set Levels of Devices like LCD, LEDs; 
 *  some device execute this level at once; some don't, such as GPIO_DEV_FTE_FEEDBACK_VIB
 * PARAMETERS
 *  device      [IN] gpio_device_enum       
 *  level       [IN] gpio_device_led_level_typedef
 *****************************************************************************/
void srv_gpio_set_device_level(srv_gpio_dev_enum device, srv_gpio_dev_level_enum level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if (device == GPIO_DEV_FTE_FEEDBACK_VIB)
    {
        mmi_eq_set_gpio_level_req_struct *req;
        req = OslConstructDataPtr(sizeof(mmi_eq_set_gpio_level_req_struct));
        req->gpio_dev_type = device;
        req->gpio_dev_level = level;

        srv_gpio_send_message(MOD_L4C, MSG_ID_MMI_EQ_SET_GPIO_LEVEL_REQ, req, NULL);
    }
    else
    {
        mmi_eq_exe_gpio_level_req_struct *setGPIOLevelReq;

    #ifdef __LCD_ESD_RECOVERY__
        if ((device == GPIO_DEV_LED_MAINLCD) || (device == GPIO_DEV_LED_SUBLCD))
        {
            if (level == LED_LIGHT_LEVEL0)
            {
                gdi_lcd_stop_esd_recovery_timer();
            }
            else
            {
                gdi_lcd_start_esd_recovery_timer();
            }
        }
    #endif /* __LCD_ESD_RECOVERY__ */ 

        setGPIOLevelReq = OslConstructDataPtr(sizeof(mmi_eq_exe_gpio_level_req_struct));
        setGPIOLevelReq->gpio_dev_type = device;
        if ((device == GPIO_DEV_LED_MAINLCD) && (level == LED_LIGHT_LEVEL5))
        {
            setGPIOLevelReq->gpio_dev_level = srv_backlight_get_real_level(SRV_BACKLIGHT_TYPE_MAINLCD);
        }
        else if (device == GPIO_DEV_LED_BACKLIGHT_DIMMING)
        {
            if (srv_backlight_get_real_level(SRV_BACKLIGHT_TYPE_MAINLCD) <= LED_LIGHT_LEVEL1)
                setGPIOLevelReq->gpio_dev_level = LED_LIGHT_LEVEL1; /* don't pass level 0 to L4UEM */
            else
                setGPIOLevelReq->gpio_dev_level = srv_backlight_get_real_level(SRV_BACKLIGHT_TYPE_MAINLCD) - 1;
        }
        else
        {
            setGPIOLevelReq->gpio_dev_level = level;
        }

        srv_gpio_send_message(MOD_L4C, MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ, setGPIOLevelReq, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_detect_send_ack
 * DESCRIPTION
 *  send ack to PS
 * PARAMETERS
 *  action          [IN]        
 *  Action(?)       [IN]        Battery_sttus
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gpio_detect_send_ack(U8 gpio_device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_gpio_detect_res_req_struct *param_ack;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ack = OslConstructDataPtr(sizeof(mmi_eq_gpio_detect_res_req_struct));

    param_ack->ext_gpio_device = gpio_device;

    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_SEND_DETECT_ACK, param_ack->ext_gpio_device);

    srv_gpio_send_message(MOD_L4C, MSG_ID_MMI_EQ_GPIO_DETECT_RES_REQ, param_ack, (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_check_pwron_ready
 * DESCRIPTION
 *  check if device aux detect is done. if detect is done (means gpio is ready), 
 *  will return MMI_TRUE and don't callback notifier; else, detect unfinish (means
 *  gpio is not ready), will return MMI_FALSE and store this cbk, then callback 
 *  notifier until detect done. if Caller just to check and don't want to callback,
 *  caller can pass NULL to notifier and user_data
 * PARAMETERS
 *  notifier :      [IN] callback function
 *  user_data :     [IN]
 * RETURNS
 *  MMI_TRUE: GPIO is ready
 *****************************************************************************/ 
MMI_BOOL srv_gpio_check_pwron_ready(SRV_GPIO_PWRON_READY_NOTIFIER notifier,
                                            void *user_data)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, 
        TRC_SRV_GPIO_GPIO_CHECK_PWRON_READY, 
        g_srv_gpio_pwron_ready_s.is_ready,
        notifier);
    
    if (g_srv_gpio_pwron_ready_s.is_ready == MMI_TRUE)
        return MMI_TRUE;

    if (notifier != NULL)
    {
        g_srv_gpio_pwron_ready_s.ready_callback = notifier;
        g_srv_gpio_pwron_ready_s.user_data = user_data;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_gpio_detect_ind_hdlr
 * DESCRIPTION
 *  Event handler of gpio detect indication
 *  
 *  PARAMETERS: mmi_eq_gpio_detect_ind_struct *
 *  info        [IN]        
 *****************************************************************************/
void srv_gpio_detect_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_gpio_detect_ind_struct *gpioDetectInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gpioDetectInd = (mmi_eq_gpio_detect_ind_struct*) info;

    srv_gpio_detect_send_ack(gpioDetectInd->gpio_device);

    /*
     * Because it is possible that L4 power-on indication comes but the earphone
     * detection has not completed, MMI boot-up starts when both of them 
     * say it is ready; otherwise, the terminal with the earphone plugged could
     * bootup with the sound comes from the loudspeaker.
     */
    if (gpioDetectInd->gpio_device == EXT_DEV_AUX_DETECT_DONE)
    {
        g_srv_gpio_pwron_ready_s.is_ready = MMI_TRUE;
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, 
            TRC_SRV_GPIO_GPIO_IS_READY, 
            g_srv_gpio_pwron_ready_s.ready_callback);
        if (NULL != g_srv_gpio_pwron_ready_s.ready_callback)
        {
            g_srv_gpio_pwron_ready_s.ready_callback(NULL, g_srv_gpio_pwron_ready_s.user_data);
            g_srv_gpio_pwron_ready_s.ready_callback = NULL;
            g_srv_gpio_pwron_ready_s.user_data = NULL;
        }
        return;
    }

    switch (gpioDetectInd->gpio_device)
    {       
        case EXT_DEV_EARPHONE:  /* Earphone plug in/out */
        {            
	    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_EARPHONE_IND);
            srv_earphone_connect_hdlr((MMI_BOOL)gpioDetectInd->on_off);
            break;
        }
    
        case EXT_DEV_KEY_1: /* SEND(END) key press */
        {
            if (srv_bootup_is_launched())
            {
                srv_gpio_post_event(EVT_ID_GPIO_EXT_DEV_KEY_1);
            }

            break;
        }

	#ifdef __MMI_CLAMSHELL__        /* { */
        case EXT_DEV_CLAM_OPEN: /* Clam open */
        {
          g_clam_state = 1;
                          
            if (!srv_bootup_is_launched() || srv_shutdown_is_running())
            {
              MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_IND_BEFORE_POWER_ON);
              return;
            }

            srv_gpio_post_event(EVT_ID_GPIO_CLAM_OPEN);
            
            break;
        }

        case EXT_DEV_CLAM_CLOSE:    /* Clam close */
        {
            g_clam_state = 0;
            
            if (!srv_bootup_is_launched() || srv_shutdown_is_running())
            {             
              MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_IND_BEFORE_POWER_ON);
              return;
            }
            
            srv_gpio_post_event(EVT_ID_GPIO_CLAM_CLOSE);
            break;            
        }
	#endif /* __MMI_CLAMSHELL__ */ /* } */
	
	#if defined(__KJX_RFID__)
		case EXT_DEV_RFID_OPEN:
		{				
			kal_prompt_trace(MOD_TST,"EXT_DEV_RFID_OPEN");
			if (!srv_bootup_is_launched() || srv_shutdown_is_running())
			{
				MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_IND_BEFORE_POWER_ON);
				return;
			}
			srv_gpio_post_event(EVT_ID_GPIO_RFID_OPEN);
			break;
		}
		case EXT_DEV_RFID_CLOSE: 
		{		
			kal_prompt_trace(MOD_TST,"EXT_DEV_RFID_CLOSE"); 
			if (!srv_bootup_is_launched() || srv_shutdown_is_running())
			{			  
				MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_IND_BEFORE_POWER_ON);
				return;
			}
			srv_gpio_post_event(EVT_ID_GPIO_RFID_CLOSE);
			break;			  
		}		
	#endif
	
	#if defined(__BLE_MODULE_SUPPORT__)
		case EXT_DEV_BLE_MOD_SPI_OPEN:
		{				
			kal_prompt_trace(MOD_TST,"EXT_DEV_BLE_MOD_SPI_OPEN");
			if (!srv_bootup_is_launched() || srv_shutdown_is_running())
			{
			MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_IND_BEFORE_POWER_ON);
			return;
			}
			srv_gpio_post_event(EVT_ID_GPIO_BLE_MOD_SPI_OPEN);
			break;
		}

		case EXT_DEV_BLE_MOD_SPI_CLOSE: 
		{		
			kal_prompt_trace(MOD_TST,"EXT_DEV_BLE_MOD_SPI_CLOSE"); 
			if (!srv_bootup_is_launched() || srv_shutdown_is_running())
			{			  
			MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_IND_BEFORE_POWER_ON);
			return;
			}

			srv_gpio_post_event(EVT_ID_GPIO_BLE_MOD_SPI_CLOSE);
			break;			  
		}		
	#endif

	#ifdef __OP01_FWPBW__
        case EXT_DEV_TRANSMITTER_HOLD_ON:
        {
            g_gpio_transmitter_is_hold_on = MMI_TRUE;
            if (!srv_bootup_is_launched() || srv_shutdown_is_running())
            {             
              MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_IND_BEFORE_POWER_ON);
              return;
            }
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            srv_gpio_post_event(EVT_ID_GPIO_TRANSMITTER_HOLD_ON);
            break;
        }
        case EXT_DEV_TRANSMITTER_PUT_DOWN:
        {
            g_gpio_transmitter_is_hold_on = MMI_FALSE;
            if (!srv_bootup_is_launched() || srv_shutdown_is_running())
            {             
              MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_IND_BEFORE_POWER_ON);
              return;
            }
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            srv_gpio_post_event(EVT_ID_GPIO_TRANSMITTER_PUT_DOWN);
        }
	#endif

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsClamClose
 * DESCRIPTION
 *  Query clam statue
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
MMI_BOOL srv_clam_is_close(void)
{
#ifdef __MMI_CLAMSHELL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_clam_state)
    {
        return MMI_TRUE;    /* 0: Close */
    }
    else
#endif /* __MMI_CLAMSHELL__ */ 
        return MMI_FALSE;   /* 1: Open */
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_clam_state
 * DESCRIPTION
 *  Set clam state
 * PARAMETERS
 *  clam_state      [IN]        Clam state
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clam_set_state(U16 clam_state)
{
#ifdef __MMI_CLAMSHELL__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clam_state == EXT_DEV_CLAM_OPEN)
    {
        g_clam_state = 1;  /* open */
    }
    else if (clam_state == EXT_DEV_CLAM_CLOSE)
    {
        g_clam_state = 0;  /* close */
    }
    else
    {
        MMI_ASSERT(0);  /* wrong parameter */
    }

#else /* __MMI_CLAMSHELL__ */ 
    MMI_ASSERT(0);  /* shall not call this function when no clam support */
#endif /* __MMI_CLAMSHELL__ */ 
}



/*****************************************************************************
 * FUNCTION
 *  IsClamToneAllow
 * DESCRIPTION
 *  Query if clam tone allow to play (No other audio tone is playing, except clam tone it self
 *  
 *  PARAMETERS:
 *  void
 *****************************************************************************/
MMI_BOOL srv_gpio_allow_clam_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CLAMSHELL__) || defined(__MMI_SLIDE__)    
    if (((srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL) || srv_bootup_is_exception_mode()) 
        && (!AlmIsRTCPwron()) && 
        ((!srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) ||
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CSD_CALL_TYPE_ALL, NULL) > 0))
        && srv_gpio_emit_event(EVT_ID_GPIO_CLAM_OPEN_CLOSE_QUERY_TONE))
        {
            return MMI_TRUE;
        }
    else
#endif /* #if defined(__MMI_CLAMSHELL__) || defined(__MMI_SLIDE__) */

    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_vibrator_handle_ctrl_req
 * DESCRIPTION
 *  Api for other modules get gpio control
 *  
 *  PARAMETERS: action: MMIAPI_DEV_CTRL_GET / MMIAPI_DEV_CTRL_RELEASE
 *  action      [IN]        
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_vibrator_play_req
 * DESCRIPTION
 *  Directly handle vibrate to play or stop, not send primitive to myself
 * PARAMETERS
 *  id   : [IN]  PATTERN_ID
 *  type : [IN]  PATTERN_TYPE
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_vibrator_play_req(PATTERN_ID id, PATTERN_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
    srv_pattern_play_req((U8)id, (U8)type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_vibrator_req_hdlr
 * DESCRIPTION
 *  to handle post event of srv_vibrator_post_req
 * PARAMETERS
 *  msg : [IN]  vib post event
 * RETURNS
 *  void
 *****************************************************************************/ 
static void srv_vibrator_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_gpio_post_vib_req_struct *ind = (mmiapi_gpio_post_vib_req_struct *)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_VIB_REQ_HDLR, gpioVibOutOfCtrl, ind->id, ind->type);
    
    srv_vibrator_play_req((PATTERN_ID) ind->id, (PATTERN_TYPE) ind->type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_play_vibrate
 * DESCRIPTION
 *  to post vibrator to play once/repeat/stop
 * PARAMETERS
 *  id   [IN]  srv_gpio_pattern_id_enum (PATTERN_ID), from VIB_PATTERN_BEGIN to VIB_PATTERN_END
 *  type [IN]  srv_gpio_pattern_type_enum (PATTERN_TYPE)
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_gpio_play_vibrate(srv_gpio_pattern_id_enum id, srv_gpio_pattern_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_vibrator_post_req(id, type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_vibrator_post_req
 * DESCRIPTION
 *  to post vibrator on/off event
 * PARAMETERS
 *  on : [IN]  on or off
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_vibrator_post_req(PATTERN_ID id, PATTERN_TYPE type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_PLAY_VIBRATE, id, type);
#if 1 /* now IMY phaseout, so no vib race-condition, we can directly send request to L4UEM */    
    srv_vibrator_play_req(id, type);
#else
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
}


/*****************************************************************************
 * FUNCTION
 *  srv_led_pattern_set_flag
 * DESCRIPTION
 *  set led pattern flag
 * PARAMETERS
 *  flag     [IN]        led pattern flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_led_pattern_set_flag(MMI_BOOL flag)
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
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_led_pattern_ctrl_req_hdlr
 * DESCRIPTION
 *  Handler of MSG_ID_MMIAPI_LED_CONTROL_REQ
 * PARAMETERS
 *  msg     [IN]        Requested data
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
/*****************************************************************************
 * FUNCTION
 *  srv_led_pattern_get_bg_pattern
 * DESCRIPTION
 *  get background led pattern
 *  
 *  PARAMETERS:
 *
 *  RETURNS 
 *  background pattern
 *****************************************************************************/
U8 srv_led_pattern_get_bg_pattern(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 band_pattern = LED_NoService;
        return band_pattern;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_LED_POWERON_CHARGEFULL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_LED_POWERON_CHARGEFULL__ */ 
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
/* under construction !*/
/* under construction !*/
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_play_pattern
 * DESCRIPTION
 *  To start or stop LED/LCD/vibrator Pattern, e.g. Battery status pattern,
 *  Network Info status pattern, ...
 * PARAMETERS
 *  id     [IN] srv_gpio_pattern_id_enum, refer PATTERN_ID defined in Device.h
 *  type   [IN] srv_gpio_pattern_type_enum, refer PATTERN_TYPE
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gpio_play_pattern(srv_gpio_pattern_id_enum pattern, srv_gpio_pattern_type_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signed char pat = (signed char)pattern;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
 //   MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_SRV_GPIO_PLAY_PATTERN, 
   //     pattern, action, g_srv_gpio_property_info.curr_mode, gpioOutOfCtrl, gpioVibOutOfCtrl, g_led_pattern_flag);
    
#if ( defined(__MMI_ENGINEER_MODE__) || defined(__MMI_FACTORY_MODE__))
    if (g_srv_gpio_property_info.curr_mode != 0) // mean in ENGINEERING_MODE or FACTORY_MODE
    {
        return;
    }
#endif 

    /* Other module might request to obtain control of LEDs from MMI */
    if (gpioOutOfCtrl == 1 && !(pat >= VIB_PATTERN_BEGIN && pat <= VIB_PATTERN_END))
    {
        return;
    }
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    /* Background LED pattern (for example: Camp on LED, Low battery...etc) */
    /* play request might comes anytime, it will interrupt the on going  */
    /* caller group pattern */
    if ((IsCallerGroupPatternPlaying)
        && (((pat >= LED_PATTERN_BEGIN) && (pat < LED_Caller1)) || ((pat > LED_Caller6) && (pat <= LED_PATTERN_END))))
    {
        return;
    }

    if (!g_led_pattern_flag && pat >= LED_PATTERN_BEGIN && pat <= LED_PATTERN_END)
    {
        return;
    }

    if ((!g_led_pattern_flag) && pattern == srv_led_pattern_get_bg_pattern() && action != PLAY_STOP)
    {
        return;
    }

    srv_pattern_send_req_to_hw(pat, action);

    /* Start play CampOn LED pattern */
    if ((pat >= LED_PATTERN_BEGIN && pat < LED_PATTERN_END) && 
        (action == PLAY_STOP) && 
        (g_led_pattern_flag) && 
        srv_bootup_is_completed())
    {
	 #if defined(__KJX_FUN__)	//xb add 2016-09-08 开机只震动一次
		srv_pattern_send_req_to_hw(srv_led_pattern_get_bg_pattern(), PLAY_ONCE);
	 #else
		srv_pattern_send_req_to_hw(srv_led_pattern_get_bg_pattern(), PLAY_REPEAT);
	 #endif
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_pattern_play_req
 * DESCRIPTION
 *  will be phased out, please use new SDK API: srv_gpio_play_pattern
 *  Plays a pattern on vibrator or LED 
 * PARAMETERS:
 *  pattern     [IN]        pattern type to be played
 *  action      [IN]        ON/OFF
 * Returns
 * void
 *****************************************************************************/
extern void srv_pattern_play_req(U8 pattern, U8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum) pattern, (srv_gpio_pattern_type_enum) action);
}


/*****************************************************************************
 * FUNCTION
 *  srv_led_pattern_start_caller_group
 * DESCRIPTION
 *  Plays pattern as caller group functionality
 *  
 *  PARAMETERS:
 *  pattern     [IN]        
 *****************************************************************************/
void srv_led_pattern_start_caller_group(U16 pattern)
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
}


/*****************************************************************************
 * FUNCTION
 *  srv_led_pattern_stop_caller_group
 * DESCRIPTION
 *  Stops pattern as caller group functionality
 *  
 *  PARAMETERS:
 *  pattern     [IN]        
 *****************************************************************************/
void srv_led_pattern_stop_caller_group(U16 pattern)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}




/*****************************************************************************
 * FUNCTION
 *  GpioPlayReq
 * DESCRIPTION
 *  Other module control gpio device
 *  
 *  PARAMETERS: p_type, p_level
 *  p_type      [IN]        
 *  p_level     [IN]        
 *****************************************************************************/
kal_uint8 srv_gpio_play_req(kal_uint8 p_type, kal_uint8 p_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_TRUE;
    U8 device = 0, level = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_type)
    {
        case MMIAPI_DEV_TYPE_MAINLCD_BL:
            device = GPIO_DEV_LED_MAINLCD;
            break;
        case MMIAPI_DEV_TYPE_SUBLCD_BL:
            device = GPIO_DEV_LED_SUBLCD;
            break;
        case MMIAPI_DEV_TYPE_KEYPAD_BL:
            device = GPIO_DEV_LED_KEY;
            break;
        case MMIAPI_DEV_TYPE_LED_1:
            device = GPIO_DEV_LED_STATUS_1;
            break;
        case MMIAPI_DEV_TYPE_LED_2:
            device = GPIO_DEV_LED_STATUS_2;
            break;
        case MMIAPI_DEV_TYPE_LED_3:
            device = GPIO_DEV_LED_STATUS_3;
            break;
        case MMIAPI_DEV_TYPE_VIBRATOR:
            device = GPIO_DEV_VIBRATOR;
            break;
        default:
            result = MMI_FALSE;
            break;
    }

    switch (p_level)
    {
        case MMIAPI_DEV_LEVEL_0:
            level = LED_LIGHT_LEVEL0;
            break;
        case MMIAPI_DEV_LEVEL_1:
            level = LED_LIGHT_LEVEL1;
            break;
        case MMIAPI_DEV_LEVEL_2:
            level = LED_LIGHT_LEVEL2;
            break;
        case MMIAPI_DEV_LEVEL_3:
            level = LED_LIGHT_LEVEL3;
            break;
        case MMIAPI_DEV_LEVEL_4:
            level = LED_LIGHT_LEVEL4;
            break;
        case MMIAPI_DEV_LEVEL_5:
            level = LED_LIGHT_LEVEL5;
            break;
        default:
            result = MMI_FALSE;
            break;
    }
    srv_gpio_set_device_level((srv_gpio_dev_enum)device, (srv_gpio_dev_level_enum)level);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  GpioPlayReqHdlr
 * DESCRIPTION
 *  Other module play device function through MMI
 *  
 *  PARAMETERS: mmiapi_device_play_req_struct *
 *  inMsg       [IN]        
 *****************************************************************************/
static void srv_gpio_play_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_device_play_req_struct *p = (mmiapi_device_play_req_struct*) inMsg;
    mmiapi_device_play_rsp_struct *p_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_out = OslConstructDataPtr(sizeof(mmiapi_device_play_rsp_struct));
    p_out->result = srv_gpio_play_req(p->type, p->level);
    p_out->type = p->type;
    p_out->level = p->level;
    
    srv_gpio_send_message(p->src_mod_id, MSG_ID_MMIAPI_DEVICE_PLAY_RSP, (void*)p_out, (void*)NULL);

    if (g_gpio_pending_vib_stop==MMI_TRUE)
    {
        srv_pattern_send_req_to_hw(g_gpio_pending_vib_stop_id, 0);
        //PlayPatternReq(g_gpio_pending_vib_stop_id, 0);
        g_gpio_pending_vib_stop = MMI_FALSE; 
    }    
}


/*****************************************************************************
 * FUNCTION
 *  srv_pattern_send_req_to_hw
 * DESCRIPTION
 *  Send pattern request to H/W
 *  
 *  PARAMETERS: pattern: pattern to be played
 *  pattern     [IN]        
 *  action      [IN]        ON/OFF
 *****************************************************************************/
void srv_pattern_send_req_to_hw(U8 pattern, U8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_play_pattern_req_struct *displayLedPattern;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    displayLedPattern = OslConstructDataPtr(sizeof(mmi_eq_play_pattern_req_struct));
    displayLedPattern->pattern = pattern;
    displayLedPattern->action = action;

    srv_gpio_send_message(MOD_L4C, MSG_ID_MMI_EQ_PLAY_PATTERN_REQ, displayLedPattern, NULL);
}

#if defined(__KJX_RFID__)
mmi_ret mmi_rfid_eint_notify_hdlr(mmi_event_struct *event)
{
	switch (event->evt_id)
	{
	case EVT_ID_GPIO_RFID_OPEN:
		kjx_rfid_turn_on();
		break;

	case EVT_ID_GPIO_RFID_CLOSE:
		kjx_rfid_turn_off();
		break;

	default:
		break;
	}
	
	return MMI_RET_OK;
}
#endif

#if defined(__BLE_MODULE_SUPPORT__)
#include "..\\custom\\drv\\Ble_mod\\ble_mod.h"
#include "..\\..\\kjx\\inc\\kjx_prin.h"
extern BOOL g_kjx_ble_is_on;
extern char ble_data[128];
extern void ble_mod_spi_read_bytes(kal_uint8 *pBuff);
extern void ble_mod_delay(kal_uint32 delay_count);

void ble_mod_reset(void)
{
	if(g_kjx_ble_is_on)
	{
		ble_mod_power_off();
		ble_mod_delay(274); //274
		ble_mod_power_on();
	}
}

void ble_mod_get_spi_data(void)
{
	kal_uint8 rx_buff[50]={0},rx_len=0,buffer[128] = {0};
	kal_uint8 i,checktmp = 0;
	static kal_uint8 ble_mode_data_error_timer=0;
	applib_time_struct currTime;

	memset(rx_buff, 0, sizeof(rx_buff));
	ble_mod_spi_read_bytes(rx_buff);

	memcpy(ble_data, rx_buff, sizeof(rx_buff));

#if 0
	memset(&currTime, 0x00, sizeof(currTime));
	applib_dt_get_rtc_time(&currTime);
	sprintf(buffer, "[%04d/%02d/%02d, %02d:%02d.%02d]: %x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x",
		currTime.nYear,currTime.nMonth, currTime.nDay, currTime.nHour, currTime.nMin, currTime.nSec,
		rx_buff[0],rx_buff[1],rx_buff[2],rx_buff[3],rx_buff[4],rx_buff[5],rx_buff[6],rx_buff[7],rx_buff[8],rx_buff[9],rx_buff[10],
		rx_buff[11],rx_buff[12],rx_buff[13],rx_buff[14],rx_buff[15],rx_buff[16],rx_buff[17],rx_buff[18],rx_buff[19],rx_buff[20],
		rx_buff[21],rx_buff[22],rx_buff[23],rx_buff[24],rx_buff[25],rx_buff[26],rx_buff[27],rx_buff[28],rx_buff[29],rx_buff[30],
		rx_buff[31],rx_buff[32],rx_buff[33]);

	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
#endif

#if 0
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("ble_data:%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x,%x",
			rx_buff[0],rx_buff[1],rx_buff[2],rx_buff[3],rx_buff[4],rx_buff[5],rx_buff[6],rx_buff[7],rx_buff[8],rx_buff[9],rx_buff[10],
			rx_buff[11],rx_buff[12],rx_buff[13],rx_buff[14],rx_buff[15],rx_buff[16],rx_buff[17],rx_buff[18],rx_buff[19],rx_buff[20],
			rx_buff[21],rx_buff[22],rx_buff[23],rx_buff[24],rx_buff[25],rx_buff[26],rx_buff[27],rx_buff[28],rx_buff[29],rx_buff[30],
			rx_buff[31],rx_buff[32],rx_buff[33]);
#endif
#endif

	kjx_bt_lbeacon_get_data();

	for(i=0;i<BLE_MOD_DATA_LEN-2;i++)
	{
		checktmp = checktmp^rx_buff[i];
	}

    if(rx_buff[0] != 0xdd || rx_buff[BLE_MOD_DATA_LEN-1] != 0x55)
    {
        ble_mode_data_error_timer++;
        if(ble_mode_data_error_timer > 10)
        {
            ble_mode_data_error_timer = 0;
            ble_mod_reset();
        }
    }
	else if(checktmp != rx_buff[BLE_MOD_DATA_LEN-2])
	{
		ble_mode_data_error_timer++;
        if(ble_mode_data_error_timer > 10)
        {
            ble_mode_data_error_timer = 0;
            ble_mod_reset();
        }
	}
    else
    {
        ble_mode_data_error_timer = 0;
    }
}

void ble_mod_receive_message_rsp(void * msg)
{
    ble_mod_get_spi_data();
}

void BLE_Mod_Receive_Msg_req(void* data_ptr)
{
    MYQUEUE Message;

    Message.oslMsgId = MSG_ID_MMI_BLE_MOD_MESSAGE_IND;
    Message.oslDataPtr = (oslParaType*)data_ptr;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI  ;
    Message.oslDestId = MOD_MMI;
    OslMsgSendExtQueue(&Message);

}

void ble_mod_init_msg_protocol(kal_bool flag)
{
    if(flag)
    {
        SetProtocolEventHandler(ble_mod_receive_message_rsp, MSG_ID_MMI_BLE_MOD_MESSAGE_IND);
    }
    else
    {
        ClearProtocolEventHandler(MSG_ID_MMI_BLE_MOD_MESSAGE_IND);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ble_mod_eint_notify_hdlr
 * DESCRIPTION
 *  notify hdlr of ble module spi open/close.
 * PARAMETERS
 *  notify_flag     [IN]        Notify flag
 *  para            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ble_mod_eint_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
	{
	case EVT_ID_GPIO_BLE_MOD_SPI_OPEN:
		if(g_kjx_ble_is_on)
		{
			ble_mod_get_spi_data();
		}
		break;
		
	case EVT_ID_GPIO_BLE_MOD_SPI_CLOSE:
		break;

	default:
		break;
	}
	
    return MMI_RET_OK;
}
#endif

#ifdef __OP01_FWPBW__

/*****************************************************************************
 * FUNCTION
 *  srv_gpio_transmitter_is_hold_on
 * DESCRIPTION
 *  Check current fixed phone transmitter's states, if it is hold on
 * PARAMETERS:
 *  void
 * RETURNS:
 *  MMI_BOOL, return MMI_TRUE if transmitter is hold on,
 *            return MMI_FALSE if transmitter is put down
 *****************************************************************************/
MMI_BOOL srv_gpio_transmitter_is_hold_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_gpio_transmitter_is_hold_on;
}

#endif /* __OP01_FWPBW__ */

/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_property_info
 * DESCRIPTION
 *  set gpio service property data, caller only need fill the field info in info_struct, 
 *  relation with info_type para
 * PARAMETERS
 *  info_type :      [IN] refer srv_gpio_property_info_enum
 *  info_struct :    [IN] refer srv_gpio_property_info_struct
 * RETURNS
 *  MMI_BOOL : set success, return MMI_TRUE;
 *****************************************************************************/ 
MMI_BOOL srv_gpio_set_property_info(srv_gpio_property_info_enum info_type,
                                    srv_gpio_property_info_struct *info_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (info_type)
    {
        case SRV_GPIO_PROPERTY_KEYPAD_LOCKED_FLAG:
            g_srv_gpio_property_info.keypad_locked = info_struct->keypad_locked;
            break;

        case SRV_GPIO_PROPERTY_SET_CURR_MODE:
            g_srv_gpio_property_info.curr_mode = info_struct->curr_mode;
            break;

        default :
            break;
    }
    return MMI_TRUE;
}

