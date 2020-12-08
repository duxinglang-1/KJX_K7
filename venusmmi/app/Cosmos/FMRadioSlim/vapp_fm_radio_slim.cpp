/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   vapp_fm_radio_slim.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FM Radio file
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

#ifdef __MMI_FM_RADIO_SLIM__

#ifdef __cplusplus
extern "C"
{
#endif
#include "ProfilesSrv.h" 
#include "mdi_audio.h"
#include "mdi_include.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_fm_radio_def.h"
#include "mmi_rp_vapp_soundrec_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "Mmi_frm_events_gprot.h"
#include "Filemgrcuigprot.h"
#include "FileMgrSrvGProt.h"
#include "GlobalConstants.h"
#include "AppMgrSrvGProt.h"
#include "USBSrvGProt.h"
#include "GpioSrvGprot.h"
#include "UcmSrvGprot.h"
#include "NotificationGprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_vapp_usbmmi_def.h"
#endif
#include "Mmi_cb_mgr_gprot.h"
#include "SoundRecSrvGProt.h"
#include "Nvram_interface.h" /* nvram_get_default_value */
#include "mmi_frm_nvram_gprot.h" /* reset nvram record */
#include "Wgui_categories_util.h"
#include "mmi_rp_srv_prof_def.h"
#include "MMI_media_app_trc.h"

//klawmo
#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif

#include "vapp_vol_dialog_gprot.h"
#include "vapp_fm_radio_slim.h"
#include "vcp_global_popup.h"
#include "vcp_activity_indicator.h"
#include "Vapp_usb_gprot.h"
#include "Vfx_adp_device.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

MMI_ID vapp_fm_radio_launch_app(void)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
	DCM_Load(DYNAMIC_CODE_COMPRESS_FMRADIO, 0, 0);
#endif
    return VfxAppLauncher::launch( 
                    VAPP_FM_RADIO,
                    VFX_OBJ_CLASS_INFO(VappFMRadioApp),
                    GRP_ID_ROOT);
}

MMI_ID vapp_fm_radio_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    MMI_ID app_id = 0;

    if (param == NULL && param_size == 0)
    {
        app_id = vapp_fm_radio_launch_app();
    }
    else
    {
        switch (param->cat)
        {
	        case MMI_LAUNCH_APP_IN_OPEN_CATEGORY:
	            app_id = vapp_fm_radio_launch_app();
	            break;
        }
    }
    return app_id;
}

#ifdef __cplusplus
}
#endif

#pragma arm section code = "DYNAMIC_CODE_FMRADIO_ROCODE", rodata = "DYNAMIC_CODE_FMRADIO_RODATA"

/***************************************************************************** 
 * Class VappFMRadioApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappFMRadioApp", VappFMRadioApp, VfxApp);

VappFMRadioApp* VappFMRadioApp::m_self = NULL;

VappFMRadioApp::VappFMRadioApp():
    m_state(VADP_FM_RADIO_POWER_OFF),
    m_curFreq(900),
    m_delaySetFreqTimer(NULL),
#ifdef __MMI_FM_VIA_A2DP__ 
	m_a2dpConnectTimer(NULL), 
#endif
    m_mainPage(NULL)
{
}

void VappFMRadioApp::onInit(void)
{
    VfxApp::onInit();
	
    m_self = this;
	
	//m_state must update first
    queryState();

    m_curFreq = (VfxU16)vadp_fm_radio_get_cur_freq();

	if(!srv_earphone_is_plug_in() && vadp_fm_radio_get_aud_path() == MDI_DEVICE_SPEAKER_BOTH)
    {
        vadp_fm_radio_reset_aud_path();
    }

    VFX_OBJ_CREATE(m_delaySetFreqTimer, VfxTimer, this);
    m_delaySetFreqTimer->m_signalTick.connect(this, &VappFMRadioApp::setFreqHdlr);
    m_delaySetFreqTimer->setStartDelay(500);

    VFX_OBJ_CREATE(m_delaySetPowerOnFreqTimer, VfxTimer, this);
    m_delaySetPowerOnFreqTimer->m_signalTick.connect(this, &VappFMRadioApp::setFreqHdlr);
    m_delaySetPowerOnFreqTimer->setStartDelay(100);

    registerCBEvent(EVT_ID_VAPP_FM_SCAN_DONE, VFX_TRUE);

	vadp_fm_radio_register_general_callback(&VappFMRadioApp::generalCallback, getObjHandle(), VADP_FM_RADIO_APP);
	vadp_fm_radio_register_background_callback((mdi_bg_callback)&VappFMRadioApp::backgroundCallback, getObjHandle(), VADP_FM_RADIO_APP);
	vadp_fm_radio_register_proc_callback(&VappFMRadioApp::procCallback, getObjHandle(), VADP_FM_RADIO_APP);

#if defined(__MMI_NCENTER_SUPPORT__)
	VappNCenter *ncenter =  VFX_OBJ_GET_INSTANCE(VappNCenter);
	if(ncenter != NULL)
	{
		ncenter->m_signalEvent.connect(this, &VappFMRadioApp::onNCenterStatusChanged);
	}
#endif
}

void VappFMRadioApp::onDeinit(void)
{
	if(m_delaySetPowerOnFreqTimer->getIsEnabled())
	{
		m_delaySetPowerOnFreqTimer->stop();
		mdi_fmr_set_freq(m_curFreq);
		mdi_audio_set_volume(MDI_VOLUME_FMR, srv_prof_get_media_vol());
	}

#ifdef __MMI_FM_VIA_A2DP__
	if(m_a2dpConnectTimer != NULL)
	{
		VFX_OBJ_CLOSE(m_a2dpConnectTimer);
	}
#endif

	vadp_fm_radio_update_state(m_state);

    registerCBEvent(EVT_ID_VAPP_FM_SCAN_DONE, VFX_FALSE);

	vadp_fm_radio_deregister_general_callback(VADP_FM_RADIO_APP);
	vadp_fm_radio_deregister_background_callback(VADP_FM_RADIO_APP);
	vadp_fm_radio_deregister_proc_callback(VADP_FM_RADIO_APP);

#if defined(__MMI_NCENTER_SUPPORT__)
	VappNCenter *ncenter =	VFX_OBJ_GET_INSTANCE(VappNCenter);
	if(ncenter != NULL)
	{
		ncenter->m_signalEvent.disconnect(this, &VappFMRadioApp::onNCenterStatusChanged);
	}
#endif

	m_self = NULL;

    VfxApp::onDeinit();

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
	DCM_Unload(DYNAMIC_CODE_COMPRESS_FMRADIO);
#endif
}

VfxAppCloseAnswerEnum VappFMRadioApp::onProcessClose(VfxAppCloseOption options, VfxAppCloseReason reason)
{
#ifndef __MMI_ASM_OOM_AUTO_KILL__
    // If closed by OOM, power off and close FM Radio directly, not go to background. 
    if (reason & VFX_APP_CLOSE_REASON_OOM_FLAG)
    {
        powerOff();
        return VFX_APP_CLOSE_ANSWER_YES;
    }
#endif

    return VfxApp::onProcessClose(options, reason);
}

void VappFMRadioApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VFX_OBJ_CREATE(m_scr, VappFMRadioScreen, this);
    m_scr->show();
}

mmi_ret VappFMRadioApp::onProc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
    	case EVT_ID_VAPP_FM_SCAN_DONE:
		{
			setState(VADP_FM_RADIO_POWER_ON);

			// update channel list page
			VappFMRadioChannelListPage *listPage = (VappFMRadioChannelListPage*) m_scr->getPage(VappFMRadioApp::PAGE_CHANNEL_LIST);
			if(listPage != NULL)
			{
				listPage->onAutoScanDone();
			}

			break;
		}
		default:
			break;
    }

    return MMI_RET_OK;
}

#if defined(__MMI_NCENTER_SUPPORT__)
void VappFMRadioApp::onNCenterStatusChanged(VappNCenterEventEnum evt)
{
    switch (evt)
    {
        case VAPP_NCENTER_EVENT_ENTER:
		{
			#ifdef __MMI_AVRCP_SUPPORT__
				vadp_fm_radio_deregister_avrcp_cmd_callback(VADP_FM_RADIO_APP);
			#endif
            break;
        }  
        case VAPP_NCENTER_EVENT_EXITED:
		{
			onAppUpdate();
			m_mainPage->updateChannelBox();

			#ifdef __MMI_AVRCP_SUPPORT__	
				vadp_fm_radio_register_avrcp_cmd_callback(&VappFMRadioApp::avrcpCmdCallback, getObjHandle(), VADP_FM_RADIO_APP);
			#endif
            break;
        }         
        default:
            break;
    }	
}
#endif

void VappFMRadioApp::onAppUpdate(void)
{

	queryState();
	
	updateSpeakerState();

	setState(m_state);

}

void VappFMRadioApp::queryState(void)
{
    m_state = vadp_fm_radio_query_state();
}

void VappFMRadioApp::procCallback(mmi_event_struct *evt, void *user_data)
{
    VappFMRadioApp* ptr = (VappFMRadioApp*)handleToObject((VfxObjHandle)user_data);

	switch(evt->evt_id)
	{
		case EVT_ID_GPIO_EARPHONE_PLUG_OUT:
		{
			ptr->updateSpeakerState();
			#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
				ptr->pureSetState(VADP_FM_RADIO_POWER_OFF);
			#endif

			break;
		}

		case EVT_ID_GPIO_EARPHONE_PLUG_IN:
		{
			ptr->updateSpeakerState();
			break;
		}

	//klawmo
	#ifdef __DM_LAWMO_SUPPORT__
		case EVT_ID_SRV_DM_LAWMO_LOCK_IND:
		{
			ptr->pureSetState(VADP_FM_RADIO_POWER_OFF);
			break;
		}
	#endif
		
		default:
			break;

	}

}

VfxBool VappFMRadioApp::isDelaySetPowerOnFreqEnable()
{
	return m_delaySetPowerOnFreqTimer->getIsEnabled();
}

VfxBool VappFMRadioApp::isFMRadioMainInterfaceActive()
{
	return (m_scr->getTopPageId() == PAGE_MAIN_PAGE);
}

void VappFMRadioApp::updateSpeakerState(void)
{
	m_mainPage->m_control->updateSpeakerBtn(vadp_fm_radio_get_aud_path());
}

void VappFMRadioApp::generalCallback(mdi_result result, void* user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_APP_GENERALCALLBACK, result);

    VappFMRadioApp* ptr = (VappFMRadioApp*)handleToObject((VfxObjHandle)user_data);

    if(ptr == NULL)
    {
        return;
    }

    switch(result)
    {
		case MDI_AUDIO_TERMINATED:
        {
			ptr->pureSetState(VADP_FM_RADIO_INTERRUPT);

            break;
        }
		default:
			break;
    }
}

MMI_BOOL VappFMRadioApp::backgroundCallback(mdi_result result, void *user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_APP_BACKGROUNDCALLBACK, result);

    VappFMRadioApp* ptr = (VappFMRadioApp*)handleToObject((VfxObjHandle)user_data);

    if(ptr == NULL)
    {
        return MMI_TRUE;
    }

    switch(result)
    {
        /*stop by other app*/
        case MDI_AUDIO_TERMINATED:
		{
			ptr->pureSetState(VADP_FM_RADIO_POWER_OFF);
			break;
		}
		case MDI_AUDIO_RESUME:
        {
			ptr->pureSetState(VADP_FM_RADIO_POWER_ON);
            break;
        }
    }

    return MMI_TRUE;
}

void VappFMRadioApp::powerOn(void)
{
    if(m_state != VADP_FM_RADIO_INTERRUPT)
    {
        mdi_audio_terminate_background_play();
    }		
	
	if(m_delaySetFreqTimer->getIsEnabled())
	{
		m_delaySetFreqTimer->stop();
	}
	m_delaySetPowerOnFreqTimer->start();

	vadp_fm_radio_power_on_with_path(vadp_fm_radio_get_aud_path(), VADP_FM_RADIO_APP);
    vadp_fm_radio_set_background_handler();

	setState(VADP_FM_RADIO_POWER_ON);
}

void VappFMRadioApp::powerOff(void)
{
	if(m_state != VADP_FM_RADIO_INTERRUPT)
	{
		vadp_fm_radio_app_power_off();
	}

	vadp_fm_radio_clear_background_handler();

	setState(VADP_FM_RADIO_POWER_OFF);
}

void VappFMRadioApp::switchOutputPath(void)
{
    if(!srv_earphone_is_plug_in())
    {
        return;
    }   

    vadp_fm_radio_toggle_aud_path();
    if(getState() != VADP_FM_RADIO_POWER_OFF && getState() != VADP_FM_RADIO_INTERRUPT)
    {	
		#if (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))
			vadp_fm_radio_toggle_bt_aud_path();
		#endif
		
        mdi_fmr_set_output_path(vadp_fm_radio_get_aud_path());
    }
    updateSpeakerState();
}

vadp_fm_radio_state_enum VappFMRadioApp::getState(void)
{
    return m_state;
}

void VappFMRadioApp::pureSetState(vadp_fm_radio_state_enum state)
{
    if(m_state != state)
    {
        m_stateChanged.emit(m_state, state);
    }

    m_state = state;

    m_mainPage->updateState();
}

void VappFMRadioApp::setState(vadp_fm_radio_state_enum state)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_APP_SET_STATE, state);

	pureSetState(state);

    /*inform widget about state change*/
	//set state every time when state change
    vadp_fm_radio_update_state(state);
}

VfxU16 VappFMRadioApp::getFreq(void)
{
    return m_curFreq;
}

void VappFMRadioApp::setFreq(VfxU16 freq, VfxBool is_apply)
{
    if(freq > MAX_FREQ)
    {
        freq = MAX_FREQ;        
    }

    if(freq < MIN_FREQ)
    {
        freq = MIN_FREQ;        
    }

    m_curFreq = freq;

	vadp_fm_radio_set_cur_freq(freq);

    if(is_apply)
    {		
        mdi_fmr_set_freq(m_curFreq);
		mdi_audio_set_volume(MDI_VOLUME_FMR, srv_prof_get_media_vol());
    }

}

void VappFMRadioApp::setSeekFreq(VfxU16 freq, VfxBool is_apply)
{
    m_curFreq = freq;
}

void VappFMRadioApp::setFreqHdlr(VfxTimer *source)
{
    VFX_UNUSED(source);

    mdi_fmr_set_freq(m_curFreq);
	mdi_audio_set_volume(MDI_VOLUME_FMR, srv_prof_get_media_vol());
}

void VappFMRadioApp::delaySetFreq(void)
{
    m_delaySetFreqTimer->start();
}

#ifdef __MMI_FM_VIA_A2DP__
void VappFMRadioApp::connectA2dpBegin(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_APP_CONNECT_A2DP_BEGIN);
	
	if(m_a2dpConnectTimer == NULL)
	{
		VFX_OBJ_CREATE(m_a2dpConnectTimer, VfxTimer, this);
	}
	else
	{
		m_a2dpConnectTimer->stop();
	}
	const VfxU32 CONNECT_A2DP_TIMEOUT_TIME = 2000;	// ms
	m_a2dpConnectTimer->m_signalTick.connect(this, &VappFMRadioApp::onConnectA2dpTimeout);
	m_a2dpConnectTimer->setStartDelay(CONNECT_A2DP_TIMEOUT_TIME); 
	m_a2dpConnectTimer->start();
}

void VappFMRadioApp::connectA2dpEnd(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_APP_CONNECT_A2DP_END);

	if(m_a2dpConnectTimer != NULL)
	{
		VFX_OBJ_CLOSE(m_a2dpConnectTimer);
	}
	
	m_mainPage->closeLoadingPopup();
}

void VappFMRadioApp::onConnectA2dpTimeout(VfxTimer *timer)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_APP_ON_CONNECT_A2DP_TIMEOUT);

	if(m_a2dpConnectTimer != NULL)
	{
    	VFX_OBJ_CLOSE(m_a2dpConnectTimer);
	}

	if(vadp_fm_radio_is_connecting_bt_headset())
	{
		m_mainPage->createLoadingPopup();
	}
}

#endif // __MMI_FM_VIA_A2DP__

#ifdef __MMI_AVRCP_SUPPORT__
VfxBool VappFMRadioApp::avrcpCmdCallback(VfxKeyEvent & event, VfxBool is_from_avrcp, void *user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_APP_AVRCP_CMD_CALLBACK, event.keyCode);
	
	VappFMRadioApp* ptr = (VappFMRadioApp*)handleToObject((VfxObjHandle)user_data);
	if(ptr != NULL) 
	{
		return ptr->m_mainPage->processKeyEvent(event, is_from_avrcp);
	}

	return VFX_FALSE;
}
#endif // __MMI_AVRCP_SUPPORT__


/***************************************************************************** 
 * Class VappFMRadioScreen
 *****************************************************************************/
VappFMRadioScreen::VappFMRadioScreen()
{}

void VappFMRadioScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    VappFMRadioMainPage *page;

    VFX_OBJ_CREATE(page, VappFMRadioMainPage, this);
    pushPage(VappFMRadioApp::PAGE_MAIN_PAGE,page);

    VappFMRadioApp *app;
    app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFMRadioApp);
    
    app->m_mainPage = page;
}

void VappFMRadioScreen::onEnter(VfxBool isBackward)
{
#ifdef __MMI_AVRCP_SUPPORT__
	#if defined(__MMI_NCENTER_SUPPORT__)
		// if Ncenter has entered, no need to register AVRCP 
		VappNCenter *ncenter =	VFX_OBJ_GET_INSTANCE(VappNCenter);
		if((ncenter != NULL) && ncenter->getNCenterEntered())
		{
			return;
		}
	#endif

	VappFMRadioApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappFMRadioApp);
	if (app == NULL)
    {
        return;
    }
	vadp_fm_radio_register_avrcp_cmd_callback(&VappFMRadioApp::avrcpCmdCallback, app->getObjHandle(), VADP_FM_RADIO_APP);
#endif
}

void VappFMRadioScreen::onExited(VfxBool isBackward)
{
#ifdef __MMI_AVRCP_SUPPORT__
	vadp_fm_radio_deregister_avrcp_cmd_callback(VADP_FM_RADIO_APP);
#endif

    VfxMainScr::onExited(isBackward);
}


/***************************************************************************** 
 * Class VappFMRadioChannelBox
 *****************************************************************************/
VappFMRadioChannelBox::VappFMRadioChannelBox():
	m_channelName(NULL),
    m_channelNumber(NULL),
    m_seekingPrompt(NULL)
{}

void VappFMRadioChannelBox::onInit(void)
{
    VfxControl::onInit();

	// set rect
    setPos(VappFMRadioInfo::CHANNEL_BOX_X,VappFMRadioInfo::CHANNEL_BOX_Y);
	setSize(VappFMRadioInfo::CHANNEL_BOX_WIDTH,VappFMRadioInfo::CHANNEL_BOX_HEIGHT);

	//channel name
    VFX_OBJ_CREATE(m_channelName,VfxTextFrame,this);
    m_channelName->setAnchor(0.5f,0);
    m_channelName->setPos(getSize().width/2,CHANNEL_NAME_Y);
	m_channelName->setSize(getSize().width, CHANNEL_NAME_HEIGHT);
    m_channelName->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CHANNEL_NAME_FONT_SIZE)));
    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_channelName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

	//channel number
    VFX_OBJ_CREATE(m_channelNumber,VfxTextFrame,this);
    m_channelNumber->setAnchor(0.5f,0.5f);
    m_channelNumber->setPos(getSize().width/2,CHANNEL_NUMBER_Y);
    m_channelNumber->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CHANNEL_NUMBER_FONT_SIZE)));
    m_channelNumber->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

	//seeking prompt
    VFX_OBJ_CREATE(m_seekingPrompt,VfxTextFrame,this);
    m_seekingPrompt->setAnchor(0.5f,0);
    m_seekingPrompt->setPos(m_channelName->getPos());
    m_seekingPrompt->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CHANNEL_NAME_FONT_SIZE)));
    m_seekingPrompt->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);	
	m_seekingPrompt->setString(VFX_WSTR_RES(STR_ID_VAPP_FM_SEARCHING));
	m_seekingPrompt->setHidden(VFX_TRUE);
}

void VappFMRadioChannelBox::setLight(VfxBool turn_on)
{
	VfxFloat opacity = (turn_on ? CP_OPACITY_LIGHT : CP_OPACITY_DARK_INFO);
	m_channelNumber->setOpacity(opacity);
	m_channelName->setOpacity(opacity);
}

VfxBool VappFMRadioChannelBox::setFreq(VfxU16 freq)
{
    VfxWChar* favText = NULL;
    VfxWString str;
	
	//VfxFloat num = ((VfxFloat)freq)/10;	
	//str.format("%.1f",num);		
	str.format("%d.%d", freq/10, freq%10);
	m_channelNumber->setString(str);
	m_channelName->setString(VFX_WSTR(""));

    m_signalGetFavName.emit(&favText, freq);
    if(favText != NULL)
    {
        str.loadFromMem(favText);
        m_channelName->setString(str);
		return VFX_TRUE;
    }
	
	return VFX_FALSE;
}

void VappFMRadioChannelBox::showSeekingPrompt(VfxBool isShow)
{
	m_seekingPrompt->setHidden(!isShow);
	m_channelName->setHidden(isShow);
}


/***************************************************************************** 
 * Class VappFMRadioInfo
 *****************************************************************************/
VappFMRadioInfo::VappFMRadioInfo():
    m_channelBox(NULL),
	m_btnPrev(NULL),
    m_btnNext(NULL)
{
}

void VappFMRadioInfo::onInit(void)
{
    VfxControl::onInit();
    drawInfo();
}

void VappFMRadioInfo::setLight(VfxBool turn_on)
{
	m_channelBox->setLight(turn_on);

	VfxFloat opacity = (turn_on ? CP_OPACITY_LIGHT : CP_OPACITY_DARK_INFO);
	m_btnNext->setOpacity(opacity);
	m_btnPrev->setOpacity(opacity);

	m_btnNext->setIsDisabled(!turn_on);
	m_btnPrev->setIsDisabled(!turn_on);
}

void VappFMRadioInfo::drawInfo(void)
{
	// set rect
    setPos(VappFMRadioMainPage::INFO_X,VappFMRadioMainPage::INFO_Y);
    setSize(VappFMRadioMainPage::INFO_WIDTH,VappFMRadioMainPage::INFO_HEIGHT);

	// prev button
    VFX_OBJ_CREATE(m_btnPrev,VcpImageButton,this);
    m_btnPrev->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_PREV));
    m_btnPrev->setId(VappFMRadioMainPage::BTN_PREV);
	m_btnPrev->setPos(BTN_PREV_X,BTN_PREV_Y);
	m_btnPrev->setSize(BTN_PREV_WIDTH,BTN_PREV_HEIGHT);
	m_btnPrev->setIsEffect(VFX_TRUE);
    m_btnPrev->setEffectRatio(HALO_EFFECT_RATIO);

    // next button
    VFX_OBJ_CREATE(m_btnNext,VcpImageButton,this);
    m_btnNext->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_NEXT));
    m_btnNext->setId(VappFMRadioMainPage::BTN_NEXT);
	m_btnNext->setAnchor(1,0);
	m_btnNext->setPos((getSize().width - BTN_PREV_X),BTN_PREV_Y);
	m_btnNext->setSize(m_btnPrev->getSize());
	m_btnNext->setIsEffect(VFX_TRUE);
    m_btnNext->setEffectRatio(HALO_EFFECT_RATIO);

    //Channel Box
    VFX_OBJ_CREATE(m_channelBox,VappFMRadioChannelBox,this);
    m_channelBox->setRect(CHANNEL_BOX_X,CHANNEL_BOX_Y,CHANNEL_BOX_WIDTH,CHANNEL_BOX_HEIGHT);

}


/***************************************************************************** 
 * Class VappFMRadioLPButton
 *****************************************************************************/
VappFMRadioLPButton::VappFMRadioLPButton()
{}

VfxBool VappFMRadioLPButton::onPenInput(VfxPenEvent &event)
{
        switch(event.type)
        {
            case VFX_PEN_EVENT_TYPE_LONG_TAP:
			case VFX_PEN_EVENT_TYPE_DOWN:
			case VFX_PEN_EVENT_TYPE_UP:
            {
                m_buttonStatus.postEmit(this, getId(), event.type);
                return VFX_TRUE;
            }
			
            default:
                break;
        }

        return VcpImageButton::onPenInput(event);
}


/***************************************************************************** 
 * Class VappFMRadioTuner
 *****************************************************************************/
VappFMRadioTuner::VappFMRadioTuner():
	m_pin(NULL),
    m_interval(0),
    m_low_freq(NULL),
    m_high_freq(NULL),
    m_markHotizontal(NULL),
    m_markHotizontalWhite(NULL),
    m_btnArrowL(NULL),
	m_btnArrowR(NULL)
{}

void VappFMRadioTuner::onInit(void)
{
    VfxFrame::onInit();

	// set rect
	setPos(VappFMRadioControl::TUNER_X,VappFMRadioControl::TUNER_Y);
	setSize(VappFMRadioControl::TUNER_WIDTH, VappFMRadioControl::TUNER_HEIGHT);

    // BG image
    VfxImageFrame* bg_tuner;
    VFX_OBJ_CREATE(bg_tuner,VfxImageFrame,this);
    bg_tuner->setResId(IMG_ID_VAPP_FM_TUNER_BG);
    bg_tuner->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bg_tuner->setPos(0,0);
    bg_tuner->setSize(getSize());

	// arrow left button
    VFX_OBJ_CREATE(m_btnArrowL,VappFMRadioLPButton,this);
    m_btnArrowL->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_ARROW_L));
    m_btnArrowL->setId(VappFMRadioMainPage::BTN_ARROWL);
	m_btnArrowL->setPos(BTN_ARROWL_X,BTN_ARROWL_Y);
    m_btnArrowL->setSize(BTN_ARROWL_WIDTH,BTN_ARROWL_HEIGHT);
	
	// arrow right button
    VFX_OBJ_CREATE(m_btnArrowR,VappFMRadioLPButton,this);
    m_btnArrowR->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_ARROW_R));
    m_btnArrowR->setId(VappFMRadioMainPage::BTN_ARROWR);
	m_btnArrowR->setAnchor(1,0);	
	m_btnArrowR->setPos((getSize().width - BTN_ARROWL_X),BTN_ARROWL_Y);
	m_btnArrowR->setSize(m_btnArrowL->getSize());

	// holzontal mark
	const VfxColor MARK_COLOR = VfxColor(255,90,60,17);
    VFX_OBJ_CREATE(m_markHotizontal,VfxFrame,this);
    m_markHotizontal->setRect(MARK_HORIZONTAL_X,MARK_HORIZONTAL_Y,MARK_HORIZONTAL_WIDTH,MARK_HORIZONTAL_HEIGHT);
    m_markHotizontal->setBgColor(MARK_COLOR);
	
    VFX_OBJ_CREATE(m_markHotizontalWhite,VfxFrame,this);
    m_markHotizontalWhite->setRect(MARK_HORIZONTAL_X,MARK_HORIZONTAL_Y+1,MARK_HORIZONTAL_WIDTH,MARK_HORIZONTAL_HEIGHT);
    m_markHotizontalWhite->setBgColor(VFX_COLOR_WHITE);

	// vertical mark
	#if defined(__MMI_MAINLCD_320X480__)
		const VfxU8 hotizontalGapArray[VERTICAL_MARK_COUNT] = {6, 23, 48, 48, 48, 25};
    #else // defined(__MMI_MAINLCD_240X400__) / defined(__MMI_MAINLCD_240X320__)
		const VfxU8 hotizontalGapArray[VERTICAL_MARK_COUNT] = {2, 18, 37, 37, 37, 19};
    #endif   
	VfxU16 verticalMarkPosX = MARK_HORIZONTAL_X;
	for(VfxU8 index=0; index < VERTICAL_MARK_COUNT; index++)
	{
	    VFX_OBJ_CREATE(m_markVertical[index],VfxFrame,this);
		verticalMarkPosX += hotizontalGapArray[index];
		m_markVertical[index]->setPos(verticalMarkPosX, (MARK_HORIZONTAL_Y - MARK_VERTICAL_HEIGHT));
	    m_markVertical[index]->setSize(MARK_VERTICAL_WIDTH, MARK_VERTICAL_HEIGHT);
	    m_markVertical[index]->setBgColor(MARK_COLOR);
	}

    m_interval = (VfxFloat)MARK_HORIZONTAL_WIDTH / VappFMRadioApp::FM_FREQ_NUMBER;

    //87.5mhz
    VFX_OBJ_CREATE(m_low_freq,VfxTextFrame,this);
    m_low_freq->setPos(MARK_HORIZONTAL_X, MARK_HORIZONTAL_Y + MARK_TO_FREQ);
    m_low_freq->setString(VFX_WSTR("87.5MHz"));
    m_low_freq->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FREQ_FONT_SIZE)));
	m_low_freq->setColor(MARK_COLOR);

    //108mhz
    VFX_OBJ_CREATE(m_high_freq,VfxTextFrame,this);
    m_high_freq->setAnchor(1,0);
    m_high_freq->setPos(MARK_HORIZONTAL_X + MARK_HORIZONTAL_WIDTH, MARK_HORIZONTAL_Y + MARK_TO_FREQ);
    m_high_freq->setString(VFX_WSTR("108MHz"));
    m_high_freq->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FREQ_FONT_SIZE)));
	m_high_freq->setColor(MARK_COLOR);
	
    //pin
    VFX_OBJ_CREATE(m_pin,VfxImageFrame,this);
    m_pin->setResId(IMG_ID_VAPP_FM_TUNER_PIN);
	m_pin->setIsUnhittable(VFX_TRUE);

	// tuner touch rect
	m_tunerTouchRect = VfxRect(MARK_HORIZONTAL_X, 0, MARK_HORIZONTAL_WIDTH, getSize().height);
}


void VappFMRadioTuner::setLight(VfxBool turn_on)
{
	VfxFloat opacity = (turn_on ? CP_OPACITY_LIGHT : CP_OPACITY_DARK_TUNER);
	m_btnArrowL->setOpacity(opacity);	
	m_btnArrowR->setOpacity(opacity);
	m_markHotizontal->setOpacity(opacity);
	m_markHotizontalWhite->setOpacity(opacity);
	for(VfxU8 index=0; index < VERTICAL_MARK_COUNT; index++)
	{
		m_markVertical[index]->setOpacity(opacity);
	}
	m_low_freq->setOpacity(opacity);
	m_high_freq->setOpacity(opacity);
}

void VappFMRadioTuner::setPin(VfxU16 freq)
{    
	VfxS32 pinX = MARK_HORIZONTAL_X + (VfxS32) ((freq- VappFMRadioApp::MIN_FREQ) / VappFMRadioTuner::getWheelPixelsToFreq());
    m_pin->setPos(pinX-1,2);
}

VfxBool VappFMRadioTuner::onPenInput(VfxPenEvent &event)
{
    switch(event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
			VfxPoint point = event.getRelPos(this);
            if(m_tunerTouchRect.contains(point))
            {
                return VFX_TRUE;    
            }
            break;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            m_wheelStatus.postEmit(this,event);
            return VFX_TRUE;
        }

        default:
            break;
    }

    return VfxControl::onPenInput(event);

}

VfxFloat VappFMRadioTuner::getWheelPixelsToFreq()
{
	return ((VfxFloat)VappFMRadioApp::FM_FREQ_NUMBER / VappFMRadioTuner::MARK_HORIZONTAL_WIDTH);
}


/***************************************************************************** 
 * Class VappFMRadioControl
 *****************************************************************************/
VappFMRadioControl::VappFMRadioControl():
	m_tuner(NULL),	    
    m_btnPower(NULL),
	m_btnSpeaker(NULL),
    m_btnFav(NULL)
{
}

void VappFMRadioControl::onInit(void)
{
    VfxControl::onInit();

	// set rect
	setPos(VappFMRadioMainPage::PANEL_X,VappFMRadioMainPage::PANEL_Y);
	setSize(VappFMRadioMainPage::PANEL_WIDTH,VappFMRadioMainPage::PANEL_HEIGHT);

    //tuner
    VFX_OBJ_CREATE(m_tuner, VappFMRadioTuner, this);
    m_tuner->setPos(TUNER_X,TUNER_Y);
    m_tuner->setSize(TUNER_WIDTH,TUNER_HEIGHT);

    //speaker button
    VFX_OBJ_CREATE(m_btnSpeaker, VcpImageButton, this);	
    m_btnSpeaker->setPos(BTN_SPEAKER_X, BTN_SPEAKER_Y);
    m_btnSpeaker->setSize(BTN_SPEAKER_WIDTH, BTN_SPEAKER_HEIGHT);
    m_btnSpeaker->setId(VappFMRadioMainPage::BTN_SPEAKER);
	m_btnSpeaker->setIsEffect(VFX_TRUE);
    m_btnSpeaker->setEffectRatio(HALO_EFFECT_RATIO_2);
    updateSpeakerBtn(vadp_fm_radio_get_aud_path());

    //favoriate button
    VFX_OBJ_CREATE(m_btnFav, VcpImageButton, this);
    m_btnFav->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_FAV));
	m_btnFav->setAnchor(1,0);
    m_btnFav->setPos((getSize().width - BTN_SPEAKER_X), BTN_SPEAKER_Y);
    m_btnFav->setSize(m_btnSpeaker->getSize());
    m_btnFav->setId(VappFMRadioMainPage::BTN_FAV);
	m_btnFav->setIsEffect(VFX_TRUE);
    m_btnFav->setEffectRatio(HALO_EFFECT_RATIO_2);

    //power button
    VFX_OBJ_CREATE(m_btnPower, VcpButton, this);
    m_btnPower->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_POWER_OFF,0,0,0));
	m_btnPower->setBgImageList(VcpStateImage(IMG_ID_VAPP_FM_BTN_POWER_N,IMG_ID_VAPP_FM_BTN_POWER_P,0,0));
	m_btnPower->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnPower->setMargin(0,0,0,0);
	m_btnPower->setPos(BTN_POWER_X, BTN_POWER_Y);
    m_btnPower->setSize(BTN_POWER_WIDTH, BTN_POWER_HEIGHT);
    m_btnPower->setId(VappFMRadioMainPage::BTN_POWER);
	m_btnPower->setFuzzy(VFX_FALSE);
}

void VappFMRadioControl::drawButtonState(VfxId button, VfxKeyEventTypeEnum key_event)
{
    switch(button)
    {

        case VappFMRadioMainPage::BTN_POWER :
        {
            if(key_event == VFX_KEY_EVENT_TYPE_DOWN)
            {
                m_btnPower->setState(VCP_BUTTON_STATE_PRESSED);
            }
            else if(key_event == VFX_KEY_EVENT_TYPE_UP)
            {
                m_btnPower->setState(VCP_BUTTON_STATE_NORMAL);
            }
            break;
        }

        default:
            break;
    }

}

void VappFMRadioControl::updateSpeakerBtn(VfxU8 audio_path)
{
	// Show btnSpeaker only in the case of earphone is plug in.	
	if(srv_earphone_is_plug_in())
	{
		m_btnSpeaker->setHidden(VFX_FALSE);
		if(audio_path == MDI_DEVICE_SPEAKER2)
		{
			m_btnSpeaker->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_SPEAKER,0,0,0));
		}
		else
		{
			m_btnSpeaker->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_SPEAKER_ON,0,0,0));
		}
	}
	else
	{
		m_btnSpeaker->setHidden(VFX_TRUE);
	}	
}


/***************************************************************************** 
 * Class VappFMRadioMainPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappFMRadioMainPage", VappFMRadioMainPage, VfxPage);

VappFMRadioMainPage::VappFMRadioMainPage():
    m_app(NULL),
    m_info(NULL),
    m_waitingIcon(NULL),
    m_arrowRTimer(NULL),
    m_arrowLTimer(NULL),
    m_tempFreq(0),
    m_buttonPressed(0),
	m_seekingPromptTimer(NULL),
	m_seekingDelayTimer(NULL),
	m_isSeekingDone(VFX_FALSE),
#ifdef __MMI_FM_VIA_A2DP__
	m_loadingPopup(NULL),
#endif	
	m_control(NULL)
{

}

void VappFMRadioMainPage::onInit(void)
{
    VfxPage::onInit();

    m_app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFMRadioApp);

    //Draw Main Page
    drawMainPage();
	
    vadp_fm_radio_register_seek_callback(&VappFMRadioMainPage::seekCallback, getObjHandle(), VADP_FM_RADIO_APP);
}

void VappFMRadioMainPage::onDeinit(void)
{
    vadp_fm_radio_deregister_seek_callback(VADP_FM_RADIO_APP);

    VfxPage::onDeinit();
}

void VappFMRadioMainPage::onExited(void)
{
	//set freq when exit
	vadp_fm_radio_set_cur_freq(m_app->m_curFreq);

	//for other screen interrupt
	m_arrowLTimer->stop();
	m_arrowRTimer->stop();
	m_control->drawButtonState(BTN_POWER, VFX_KEY_EVENT_TYPE_UP);

    unregisterKeyHandler(VFX_KEY_CODE_ENTER);
    unregisterKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
    unregisterKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);

#ifdef __MMI_FM_VIA_A2DP__
	closeLoadingPopup();
#endif
}

void VappFMRadioMainPage::onEnter(VfxBool isBackward)
{
	m_app->onAppUpdate();
	updateChannelBox();

    registerKeyHandler(VFX_KEY_CODE_ENTER);
    registerKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
    registerKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);
}

void VappFMRadioMainPage::updateChannelBox(void)
{    
	pureUpdateFreq(VFX_FALSE);

	if(m_app->getState() ==  VADP_FM_RADIO_SEEKING)
	{
		m_info->m_channelBox->showSeekingPrompt(VFX_TRUE);				
	}	
}

VfxBool VappFMRadioMainPage::onKeyInput(VfxKeyEvent & event)
{
	return processKeyEvent(event, VFX_FALSE);
}

VfxBool VappFMRadioMainPage::processKeyEvent(VfxKeyEvent & event, VfxBool is_from_avrcp)
{
	if((event.type == VFX_KEY_EVENT_TYPE_DOWN) && (m_app->getState() == VADP_FM_RADIO_SCANING))
	{
		//Pop out balloon "currently not avaiable" only in key down. Do nothing in key up.
		VfxWString info;
		info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());

		return VFX_FALSE;
	}

    switch (event.keyCode)
    {
        case VFX_KEY_CODE_ENTER:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                m_control->drawButtonState(BTN_POWER, VFX_KEY_EVENT_TYPE_DOWN);
                ButtonAction(BTN_POWER);
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                m_control->drawButtonState(BTN_POWER, VFX_KEY_EVENT_TYPE_UP);
            }
            return VFX_TRUE;
        }

        case VFX_KEY_CODE_ARROW_RIGHT:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {            
                m_buttonPressed = BTN_NEXT;
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
            {
                if(!LPButtonAction(BTN_ARROWR, VFX_PEN_EVENT_TYPE_DOWN))
                {
                    return VFX_FALSE;
                }
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                if(m_buttonPressed == BTN_ARROWR)
                {
                    LPButtonAction(BTN_ARROWR, VFX_PEN_EVENT_TYPE_UP);
                }
                else
                {
                    ButtonAction(BTN_NEXT);
                }
            }

            return VFX_TRUE;
        }

        case VFX_KEY_CODE_ARROW_LEFT:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                m_buttonPressed = BTN_PREV;
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
            {
                if(!LPButtonAction(BTN_ARROWL, VFX_PEN_EVENT_TYPE_DOWN))
                {
                    return VFX_FALSE;
                }
                
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                if(m_buttonPressed == BTN_ARROWL)
                {
                    LPButtonAction(BTN_ARROWL, VFX_PEN_EVENT_TYPE_UP);
                }
                else
                {
                    ButtonAction(BTN_PREV);
                }
            }

            return VFX_TRUE;
        }        

    }

    return VfxPage::onKeyInput(event);

}

void VappFMRadioMainPage::arrowBtnLongPressed(VfxTimer *source)
{
    VfxU16 freq = m_app->getFreq();
	if(source == m_arrowLTimer)
	{
	    freq--;
	}
	else // m_arrowRTimer
	{
		freq++;
	    
	}
	m_app->setFreq(freq, VFX_FALSE);
    updateFreq(VFX_TRUE);

    VfxMsec delay = source->getStartDelay();
    delay -= LONGPRESS_DUR_GAP;
    if(delay < LONGPRESS_DUR_MIN)
    {
        delay = LONGPRESS_DUR_MIN;
    }

    source->setStartDelay(delay);
    source->start();

    m_app->delaySetFreq();

}


void VappFMRadioMainPage::onWheelStatus(VfxObject *sender, VfxPenEvent event)
{
    VFX_UNUSED(sender);

    VfxU16 freq = m_app->getFreq();
    VfxS32 rel = event.pos.x - event.prevPos.x;

    freq += (VfxS16) (rel/ VappFMRadioTuner::getWheelPixelsToFreq());

    m_app->setFreq(freq, VFX_FALSE);
    updateFreq(VFX_TRUE);

    m_app->delaySetFreq();
}

VfxBool VappFMRadioMainPage::LPButtonAction(VfxId id, VfxPenEventTypeEnum type)
{
	m_buttonPressed = id;
	VfxU16 freq = m_app->getFreq();

    switch(id)
    {
        case BTN_ARROWL:
        {
            //go to prev one channel
            switch(type)
            {
                case VFX_PEN_EVENT_TYPE_DOWN:
                {
                    freq --;
                    m_app->setFreq(freq, VFX_FALSE);
                    updateFreq(VFX_TRUE);

                    m_arrowLTimer->setStartDelay(LONGPRESS_DUR_MAX);
                    m_arrowLTimer->start();

                    m_app->delaySetFreq();

                    break;
                }
				
                case VFX_PEN_EVENT_TYPE_UP:
                {
                    m_arrowLTimer->stop();
                    break;
                }
            }
            break;
        }
        
        case BTN_ARROWR:
        {
            //go to prev one channel
            switch(type)
            {
                case VFX_PEN_EVENT_TYPE_DOWN:
                {
                    freq ++;
                    m_app->setFreq(freq, VFX_FALSE);
                    updateFreq(VFX_TRUE);

                    m_arrowRTimer->setStartDelay(LONGPRESS_DUR_MAX);
                    m_arrowRTimer->start();

                    m_app->delaySetFreq();
                    break;
                }

                case VFX_PEN_EVENT_TYPE_UP:
                {
                    m_arrowRTimer->stop();
                    break;
                }
            }
            break;
        }   
    }

    return VFX_TRUE;

}

void VappFMRadioMainPage::onButtonStatus(VfxObject *sender, VfxId id, VfxPenEventTypeEnum type)
{
    VFX_UNUSED(sender);
    LPButtonAction(id, type);
}

void VappFMRadioMainPage::seekCallback(mdi_fmr_cb_reason_enum result, U16 stop_freq, MMI_BOOL is_valid, void* user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_MPAGE_SEEK_CALLBACK, result);

    VappFMRadioMainPage* ptr = (VappFMRadioMainPage*)handleToObject((VfxObjHandle)user_data);	
    if(ptr == NULL)
    {    	
        return;
    }

	if(ptr->m_seekingPromptTimer->getIsEnabled())		// (total of seeking time) < SEEKING_PROMPT_TIME
	{
		ptr->m_seekingPromptTimer->stop();
	}									
	
	if(result == MDI_FMR_CB_REASON_ABORT)
	{	 
		ptr->m_isSeekingDone = VFX_FALSE;
		
		ptr->m_info->m_channelBox->showSeekingPrompt(VFX_FALSE);
		ptr->pureUpdateFreq(VFX_FALSE);
	}	
	else if(result == MDI_FMR_CB_REASON_PROCESS)
	{
		ptr->m_app->setSeekFreq((VfxU16)stop_freq, VFX_FALSE);
		return;
	}
	else // MDI_FMR_CB_REASON_DONE
	{			
		ptr->m_app->setSeekFreq((VfxU16)stop_freq, VFX_TRUE);		
		if(ptr->m_seekingDelayTimer->getIsEnabled())	// SEEKING_PROMPT_TIME < total < SEEKING_PROMPT_TIME + SEEKING_PROMPT_DURATION_TIME
		{
			ptr->m_isSeekingDone= VFX_TRUE;
		}
		else											// total < SEEKING_PROMPT_TIME or total > SEEKING_PROMPT_TIME + SEEKING_PROMPT_DURATION_TIME
		{
			ptr->m_info->m_channelBox->showSeekingPrompt(VFX_FALSE);
			ptr->pureUpdateFreq(VFX_FALSE);
		}
	}

	ptr->m_app->pureSetState(VADP_FM_RADIO_POWER_ON);
}

void VappFMRadioMainPage::startSeek(VfxBool forward)
{

    if(m_app->getState() != VADP_FM_RADIO_POWER_ON)
    {
        return;
    }

#if (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))
	if(vadp_fm_radio_is_connecting_bt_headset())
	{	
		VfxWString info;
		info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
		return;
	}
#endif

	m_seekingPromptTimer->start();

    vadp_fm_radio_seek((U16)m_app->getFreq(),forward);

    m_app->setState(VADP_FM_RADIO_SEEKING);
}

void VappFMRadioMainPage::onSeekingTimeout(VfxTimer *source)
{
	if(source == m_seekingPromptTimer)
	{
		if(m_app->getState() != VADP_FM_RADIO_SEEKING)
		{
			return;
		}
	
		m_info->m_channelBox->showSeekingPrompt(VFX_TRUE);
				
		m_seekingDelayTimer->start();
	}
	else // m_seekingDelayTimer
	{
		if(m_isSeekingDone)
		{
			m_info->m_channelBox->showSeekingPrompt(VFX_FALSE);
			pureUpdateFreq(VFX_FALSE);

			m_isSeekingDone = VFX_FALSE;
		}
	}
}

void VappFMRadioMainPage::ButtonAction(VfxId id)
{
	m_buttonPressed = id;

    switch(id)
    {
        case BTN_PREV:
        {
            //go to prev good channel
        #ifndef __FM_RADIO_HW_SEARCH__
            if(m_app->getFreq() == VappFMRadioApp::MIN_FREQ)
            {
                return;
            }
        #endif
		
            startSeek(VFX_FALSE);
            break;
        }

        case BTN_NEXT:
        {
            //go to next good channel
        #ifndef __FM_RADIO_HW_SEARCH__
            if(m_app->getFreq() == VappFMRadioApp::MAX_FREQ)
            {
                return;
            }
        #endif

            startSeek(VFX_TRUE);
            break;
        }

        case BTN_SPEAKER:
        {
            //switch to loudspeaker
            m_app->switchOutputPath();
            break;
        }

        case BTN_FAV:
        {
            VfxWString info;

            //check if fav list full
            if(vapp_fm_radio_get_fav_count() == VAPP_FM_RADIO_FAV_LIST_NUM)
            {
                info = VFX_WSTR_RES(STR_ID_VAPP_FM_FAV_LIST_FULL);
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
                return;
            }

            //add current channel to fav
            VcpInputPopup *addFav;
            VFX_OBJ_CREATE(addFav, VcpInputPopup, this);

            VfxWString add = VFX_WSTR_RES(STR_GLOBAL_ADD);
            VfxWString to_fav = VFX_WSTR_RES(STR_ID_VAPP_FM_TO_FAV);
            VfxWString channel;
            m_tempFreq = m_app->getFreq();
            //channel.format(" FM %.1f ", (VfxFloat)m_tempFreq/10);            
            channel.format(" FM %d.%d ", m_tempFreq/10, m_tempFreq%10);

            VfxWString title;
            title += add;
            title += channel;
            title += to_fav;

            VfxWString channel_name;

            //channel_name.format("FM %.1f",(VfxFloat)m_tempFreq/10);            
            channel_name.format("FM %d.%d", m_tempFreq/10, m_tempFreq%10);

            addFav->setTitle(title);
            addFav->setHintText(VFX_WSTR_RES(STR_ID_VAPP_FM_CHANNEL_NAME));
            addFav->setIME(IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE);
            addFav->m_signalButtonClicked.connect(this,&VappFMRadioMainPage::onAddToFavPopUpButtonClicked);
            addFav->setText(channel_name,19);
			addFav->getInputbox()->setHighlight(0, addFav->getText().getLength());      
            addFav->show(VFX_TRUE);
            break;
        }

        case BTN_POWER:
        {
            if(mdi_audio_is_background_play_suspended())
            {
                VfxWString info;

                info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);

                if (srv_ucm_is_any_call())
                {   
                    info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL);
                }
                            
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
                break;
            }
            
            //power on/off
            if(m_app->getState() == VADP_FM_RADIO_POWER_OFF || m_app->getState() == VADP_FM_RADIO_INTERRUPT)
            {
		    #ifdef __MMI_FM_RADIO_BIND_EARPHONE__
		      #ifdef __MTK_TARGET__
                if(!srv_earphone_is_plug_in())
                {
                    VfxWString info;
                    info = VFX_WSTR_RES(STR_ID_VAPP_FM_PLUG_IN_EARPHONE);
                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
                    break;
                }
		      #endif
		    #endif
                m_app->powerOn();
            }
            else
            {
                m_app->powerOff();
            }

            break;
        }
		
        case TOOL_BAR_BTN_CHANNEL_LIST:
        {
			VappFMRadioChannelListPage *listPage;
            VFX_OBJ_CREATE(listPage, VappFMRadioChannelListPage, getMainScr());
            getMainScr()->pushPage(VappFMRadioApp::PAGE_CHANNEL_LIST, listPage);			
            break;
        }
    }

}

void VappFMRadioMainPage::onButtonClicked(VfxObject *sender, VfxId id)
{
    VFX_UNUSED(sender);
    ButtonAction(id);
}

VfxU16 VappFMRadioMainPage::WStringToFreq(VfxWChar *s, VfxObject* parent)
{
    CHAR *ansii_str;
    S32 len;
    len = mmi_wcslen((WCHAR*)s);
    VFX_ALLOC_MEM(ansii_str, len + 1, parent);
    mmi_wcs_to_asc((CHAR*)ansii_str, (WCHAR*)s);

    double ret;
    ret = atof(ansii_str);
    VFX_FREE_MEM(ansii_str);

    VfxU16 freq = (VfxU16)(ret*10);

    return freq;
}

void VappFMRadioMainPage::onAddToFavPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn)
{
    VFX_UNUSED(sender);

    switch(btn)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            // component already check empty
            VfxWString inputName =((VcpInputPopup*)sender)->getText();
            vapp_fm_radio_add_to_fav_list(m_tempFreq, inputName);
            if(m_info->m_channelBox->setFreq(m_app->getFreq()))
            {
                m_control->m_btnFav->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_FAV_ON,0,0,0));
            }
            else
            {
                m_control->m_btnFav->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_FAV,0,0,0));
            }
            VFX_OBJ_CLOSE(sender);
            break;
        }

        case VCP_INPUT_POPUP_BTN_CANCEL:
        {
            VFX_OBJ_CLOSE(sender);
            break;
        }

        default:
            break;
    }
}

void VappFMRadioMainPage::getFavName(VfxWChar** str, VfxU16 freq)
{
    *str = (VfxWChar*)vapp_fm_radio_get_fav_name(freq);
    return;
}

void VappFMRadioMainPage::updateFreq(VfxBool spin_wheel)
{
	// If user play another channel when seeking, abort this seek.
	if(m_app->getState() == VADP_FM_RADIO_SEEKING)
	{
		mdi_fmr_seek_abort();
	}
	else if(m_seekingDelayTimer->getIsEnabled())
	{
		m_isSeekingDone = VFX_FALSE;
		m_seekingDelayTimer->stop();
	}

	pureUpdateFreq(spin_wheel);
}

void VappFMRadioMainPage::pureUpdateFreq(VfxBool spin_wheel)
{
    VfxU16 freq = m_app->getFreq();

    if(m_info->m_channelBox->setFreq(freq))
    {
        m_control->m_btnFav->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_FAV_ON,0,0,0));
    }
    else
    {
        m_control->m_btnFav->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_FAV,0,0,0));
    }

    m_control->m_tuner->setPin(freq);
}

void VappFMRadioMainPage::updateState(void)
{
    vadp_fm_radio_state_enum state = m_app->getState();

    switch(state)
    {
        case VADP_FM_RADIO_INTERRUPT:
        case VADP_FM_RADIO_POWER_OFF:
        {
            m_info->setLight(VFX_FALSE);
            m_control->m_tuner->setLight(VFX_FALSE);
			m_control->m_btnPower->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_POWER_OFF,0,0,0));
            break;
        }

        case VADP_FM_RADIO_POWER_ON:
        case VADP_FM_RADIO_SEEKING:
        case VADP_FM_RADIO_SCANING:
        {
            m_info->setLight(VFX_TRUE);
            m_control->m_tuner->setLight(VFX_TRUE);
            m_control->m_btnPower->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_POWER_ON,0,0,0));
        }

    }


}

void VappFMRadioMainPage::showWaitingIcon(void)
{
    /* Show loading */
    if(m_waitingIcon == NULL)
    {
        VFX_OBJ_CREATE(m_waitingIcon, VcpActivityIndicator, this);
 
        m_waitingIcon->setAnchor(0.5,0.5);
        m_waitingIcon->setPos((getSize().width/2), (getSize().height/2));
        m_waitingIcon->start();
    }
}

void VappFMRadioMainPage::hideWaitingIcon(void)
{
    if(m_waitingIcon != NULL)
    {
        VFX_OBJ_CLOSE(m_waitingIcon);
        m_waitingIcon = NULL;
    }
}

void VappFMRadioMainPage::drawMainPage(void)
{
	// set background color
	setBgColor(MAIN_PAGE_BG_COLOR);

    //Info
    VFX_OBJ_CREATE(m_info, VappFMRadioInfo, this);
    m_info->setRect(INFO_X,INFO_Y,INFO_WIDTH,INFO_HEIGHT);
    m_info->m_btnNext->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
    m_info->m_btnPrev->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
    m_info->m_channelBox->m_signalGetFavName.connect(this,&VappFMRadioMainPage::getFavName);

	// tool bar
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(TOOL_BAR_BTN_CHANNEL_LIST, VFX_WSTR_RES(STR_ID_VAPP_FM_CHANNEL_LIST), VCP_IMG_TOOL_BAR_COMMON_ITEM_LIST);
	m_toolBar->m_signalButtonTap.connect(this, &VappFMRadioMainPage::onButtonClicked);
	setBottomBar(m_toolBar);

    //Control Panel
    VFX_OBJ_CREATE(m_control, VappFMRadioControl, this);
	m_control->setRect(PANEL_X,PANEL_Y,PANEL_WIDTH, PANEL_HEIGHT);
    m_control->m_btnSpeaker->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
    m_control->m_btnFav->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);  
    m_control->m_btnPower->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
	m_control->m_tuner->m_wheelStatus.connect(this,&VappFMRadioMainPage::onWheelStatus);
	m_control->m_tuner->m_btnArrowL->m_buttonStatus.connect(this,&VappFMRadioMainPage::onButtonStatus);
    m_control->m_tuner->m_btnArrowR->m_buttonStatus.connect(this,&VappFMRadioMainPage::onButtonStatus);  

	// arrow left timer, for long press
    VFX_OBJ_CREATE(m_arrowLTimer, VfxTimer, this);
    m_arrowLTimer->m_signalTick.connect(this, &VappFMRadioMainPage::arrowBtnLongPressed);

	// arrow right timer, for long press
    VFX_OBJ_CREATE(m_arrowRTimer, VfxTimer, this);
    m_arrowRTimer->m_signalTick.connect(this, &VappFMRadioMainPage::arrowBtnLongPressed);

	// for seeking	
	VFX_OBJ_CREATE(m_seekingPromptTimer, VfxTimer, this);
	m_seekingPromptTimer->setStartDelay(SEEKING_PROMPT_TIME);
    m_seekingPromptTimer->m_signalTick.connect(this, &VappFMRadioMainPage::onSeekingTimeout);

	VFX_OBJ_CREATE(m_seekingDelayTimer, VfxTimer, this);
	m_seekingDelayTimer->setStartDelay(SEEKING_PROMPT_DURATION_TIME);
    m_seekingDelayTimer->m_signalTick.connect(this, &VappFMRadioMainPage::onSeekingTimeout);
}

#ifdef __MMI_FM_VIA_A2DP__
void VappFMRadioMainPage::createLoadingPopup()
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_APP_CREATE_LOADING_POPUP);
	
	if(m_loadingPopup == NULL)
	{
	    VFX_OBJ_CREATE(m_loadingPopup, VcpLoadingPopup, this);
	}
	
    m_loadingPopup->show(VFX_TRUE);
	m_loadingPopup->setAutoDestory(VFX_TRUE);
}

void VappFMRadioMainPage::closeLoadingPopup()
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_APP_CLOSE_LOADING_POPUP);

	if(m_loadingPopup != NULL)
	{
		VFX_OBJ_CLOSE(m_loadingPopup);
	}
}
#endif


/***************************************************************************** 
 * Class VappFMRadioAutoMgr
 *****************************************************************************/
void VappFMRadioAutoMgr::onInit(void)
{
	VfxObject::onInit();

	updateFreq();
}

void VappFMRadioAutoMgr::updateFreq()
{
    S16 error;

    ReadValue(NVRAM_VAPP_FMRDO_AUTO_LIST_NUM, &m_total, DS_BYTE, &error);
    ReadRecord(NVRAM_EF_VAPP_FMRDO_AUTO_LIST_LID, 1, &m_freq, sizeof(nvram_ef_vapp_fmrdo_auto_list_struct), &error);
}

VfxU8 VappFMRadioAutoMgr::getTotal(void)
{
    return m_total;
}

VfxU16 VappFMRadioAutoMgr::getFreq(VfxU8 index)
{
    if(index > m_total)
    {
        return 0;
    }
    else
    {
        return m_freq.freq[index];
    }
}


/***************************************************************************** 
 * Class VappFMRadioListAuto
 *****************************************************************************/
VappFMRadioListAuto* VappFMRadioListAuto::m_self = NULL;

VappFMRadioListAuto::VappFMRadioListAuto():
    m_app(NULL),
	m_startCnf(NULL),
	m_autoListToolBar(NULL),
	m_list(NULL),
    m_waiting(NULL),
    m_autoMgr(NULL)
{}

void VappFMRadioListAuto::onInit(void)
{
    VfxFrame::onInit();

    m_self = this;

	// set rect
	setPos(0,0);
	setSize(((VfxFrame*)getParent())->getSize());

    // auto list
    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    m_list->setPos(0,0);
    m_list->setSize(getSize().width, (getSize().height - VCP_TOOL_BAR_HEIGHT));
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT); 
    m_list->setMenuMode(VCP_LIST_MENU_MODE_NORMAL,VFX_FALSE);
    m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    m_list->setContentProvider(this);
    m_list->m_signalItemTapped.connect(this,&VappFMRadioListAuto::onItemTapped);
	
	// auto list tool bar
    VFX_OBJ_CREATE(m_autoListToolBar, VcpToolBar, this);
	m_autoListToolBar->setPos(0,m_list->getSize().height);
	m_autoListToolBar->setSize(getSize().width, VCP_TOOL_BAR_HEIGHT);
    m_autoListToolBar->addItem(TOOL_BAR_BTN_AUTO_SEARCH, VFX_WSTR_RES(STR_ID_VAPP_FM_AUTO_SEARCH), VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
    m_autoListToolBar->m_signalButtonTap.connect(this,&VappFMRadioListAuto::onButtonClicked);
	
    // auto manager
    VFX_OBJ_CREATE(m_autoMgr, VappFMRadioAutoMgr, this);
}

void VappFMRadioListAuto::onDeinit(void)
{
    m_self = NULL;
    VfxFrame::onDeinit();
}

void VappFMRadioListAuto::onItemTapped(VcpListMenu *menu, VfxU32 index)
{
    VfxWString info;

#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
	if(!srv_earphone_is_plug_in())
    {
        info = VFX_WSTR_RES(STR_ID_VAPP_FM_PLUG_IN_EARPHONE);
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
    }
    else 
#endif
    if(m_app->getState() == VADP_FM_RADIO_POWER_OFF)
    {
        info = VFX_WSTR_RES(STR_ID_VAPP_FM_ASK_POWER_ON);
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
    }
    else
    {        
        m_app->setFreq(m_autoMgr->getFreq((VfxU8)index),VFX_TRUE);
        m_app->m_mainPage->updateFreq(VFX_FALSE);		
        m_list->updateAllItems();
    }
}

void VappFMRadioListAuto::onStateChanged(vadp_fm_radio_state_enum pre_state, vadp_fm_radio_state_enum new_state)
{
    if(pre_state == VADP_FM_RADIO_SCANING)
    {
        VFX_OBJ_CLOSE(m_waiting);
    }
}

void VappFMRadioListAuto::setApp(VappFMRadioApp* app)
{
    m_app = app;

    m_app->m_stateChanged.connect(this,&VappFMRadioListAuto::onStateChanged);

}

void VappFMRadioListAuto::updateAutoList(void)
{
    if(m_app->getState() == VADP_FM_RADIO_SCANING)
    {
        showWaitingPopup();
    }
}

void VappFMRadioListAuto::showWaitingPopup(void)
{
	if(m_waiting != NULL)
    {
		return;
	}

    VFX_OBJ_CREATE(m_waiting, VcpIndicatorPopup, this);
    m_waiting->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    m_waiting->setText(VFX_WSTR_RES(STR_ID_VAPP_FM_SEARCHING));
    m_waiting->setAutoDestory(VFX_FALSE);
    m_waiting->m_signalCanceled.connect(this, &VappFMRadioListAuto::onCancelAutoSearch);

    m_waiting->show(VFX_TRUE);
}

void VappFMRadioListAuto::startAutoScan(void)
{
	showWaitingPopup();	

    if(m_app->getState() == VADP_FM_RADIO_INTERRUPT)
    {
        vadp_fm_radio_power_on_with_path(vadp_fm_radio_get_aud_path(), VADP_FM_RADIO_APP);
        vadp_fm_radio_set_background_handler();
        m_app->setState(VADP_FM_RADIO_POWER_ON);
    }

    /* mute and reset */
    mdi_audio_set_mute(MDI_VOLUME_FMR, MMI_TRUE);
#if defined(__MMI_BT_FM_VIA_SCO__)
    mdi_audio_bt_hfp_turn_off();
#endif 

	vadp_fm_radio_scan();

    m_app->setState(VADP_FM_RADIO_SCANING);

}

void VappFMRadioListAuto::abortAutoScan(void)
{
    mdi_fmr_scan_abort();

    m_app->setState(VADP_FM_RADIO_POWER_ON);

#if defined(__MMI_BT_FM_VIA_SCO__)
    mdi_audio_bt_hfp_turn_on();
#endif

    mdi_fmr_set_freq(m_app->getFreq());
    mdi_audio_set_volume(MDI_VOLUME_FMR, srv_prof_get_media_vol());
}

void VappFMRadioListAuto::onAutoScanDone(void)
{
	m_autoMgr->updateFreq();	
	m_list->updateAllItems();
	
	VFX_OBJ_CLOSE(m_waiting);
}

void VappFMRadioListAuto::onCancelAutoSearch(VfxObject* sender, VfxFloat curr_progress)
{
    abortAutoScan();
    m_waiting = NULL;
}

void VappFMRadioListAuto::onAutoSearchButtonClicked(VfxObject* sender, VfxId btn)
{
    switch(btn)
    {
        //continue
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VFX_OBJ_CLOSE(m_startCnf);
			
			if(errBalloonHandler())
			{
				break;
			}

            startAutoScan();
            break;
        }

        //cancel
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        {
            VFX_OBJ_CLOSE(m_startCnf);
            break;
        }
    }

}

void VappFMRadioListAuto::onButtonClicked(VfxObject *sender, VfxId id)
{
	if(errBalloonHandler())
	{
		return;
	}
    else
    {
        //confirm to do auto search
        //VcpConfirmPopup *start_cnf;
        VFX_OBJ_CREATE(m_startCnf, VcpConfirmPopup, this);
        m_startCnf->setInfoType(VCP_POPUP_TYPE_QUESTION);
        m_startCnf->setText(VFX_WSTR_RES(STR_ID_VAPP_FM_AUTO_SEARCH_Q));
        m_startCnf->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_startCnf->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_CONTINUE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_startCnf->setAutoDestory(VFX_FALSE);
        m_startCnf->show(VFX_TRUE);
        m_startCnf->m_signalButtonClicked.connect(this, &VappFMRadioListAuto::onAutoSearchButtonClicked);
    }

}

VfxBool VappFMRadioListAuto::errBalloonHandler(void)
{
    VfxWString info;

    if (srv_ucm_is_any_call())
    {   
        info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL);
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());

		return VFX_TRUE;
	}
    else if((m_app->getState() == VADP_FM_RADIO_POWER_OFF) || (m_app->getState() == VADP_FM_RADIO_INTERRUPT))
    {
        info = VFX_WSTR_RES(STR_ID_VAPP_FM_ASK_POWER_ON);
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());

		return VFX_TRUE;
	}
	else if(m_app->getState() == VADP_FM_RADIO_SEEKING)
	{
		info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());

		return VFX_TRUE;
	}

	return VFX_FALSE;

}

VfxU32 VappFMRadioListAuto::getCount(void) const
{
    return m_autoMgr->getTotal();
}
 
VfxBool VappFMRadioListAuto::getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame *frame)
{
    if(m_app->getFreq() == m_autoMgr->getFreq(index))
    {
    	frame->setColor(LIST_HIGHLIGHT_COLOR);
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappFMRadioListAuto::getItemText(VfxU32 index,                    // [IN] the index of item
                                         VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                                         VfxWString &text,                // [OUT] the text resource
                                         VcpListMenuTextColorEnum &color  // [OUT] the text color
                                         )
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        VfxU16 freq = m_autoMgr->getFreq((VfxU8)index);
		text.format("FM %d.%d", freq/10, freq%10);
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappFMRadioListAuto::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
{
    text = VFX_WSTR_RES(STR_ID_VAPP_FM_AUTO_LIST_EMPTY);
    return VFX_TRUE;
}


/***************************************************************************** 
 * Class VappFMRadioFavMgr
 *****************************************************************************/
void VappFMRadioFavMgr::onInit(void)
{
	VfxObject::onInit();

    S16 error;

    ReadValue(NVRAM_VAPP_FMRDO_FAV_LIST_NUM, &m_total, DS_BYTE, &error);
    ReadRecord(NVRAM_EF_VAPP_FMRDO_FAV_LIST_LID, 1, &m_data, sizeof(nvram_ef_vapp_fmrdo_fav_list_struct), &error);
}

VfxU8 VappFMRadioFavMgr::getTotal(void)
{
    return m_total;
}

VfxU16 VappFMRadioFavMgr::getFreq(VfxU8 index)
{
    if(index > m_total)
    {
        return 0;
    }
    else
    {
        return (VfxU16)m_data.item[index].fav_freq;
    }
}

VfxWChar* VappFMRadioFavMgr::getName(VfxU8 index)
{
    if(index > m_total)
    {
        return NULL;
    }
    else
    {
        return (VfxWChar*)m_data.item[index].fav_name;
    }    
}

void VappFMRadioFavMgr::setEditIndex(VfxU8 index)
{
    m_editIndex = index;
}

VfxU8 VappFMRadioFavMgr::getEditIndex(void)
{
    return m_editIndex;
}

void VappFMRadioFavMgr::DeleteItems(VfxBool* item_p)
{
    nvram_ef_vapp_fmrdo_fav_list_struct* temp_data;
    VFX_ALLOC_MEM(temp_data, sizeof(nvram_ef_vapp_fmrdo_fav_list_struct), this);

    memset(temp_data ,0 , sizeof(nvram_ef_vapp_fmrdo_fav_list_struct));

	VfxU8 j=0;

    for(VfxU8 i=0; i< m_total; i++)
    {
        //not deleted by user
        if(!item_p[i])
        {
            memcpy(&temp_data->item[j], &m_data.item[i], sizeof(nvram_ef_vapp_fmrdo_fav_list_item_struct)); 
            j++;
        }
    }

    if(j != m_total)
    {
        S16 error;

        m_total = j;

        memcpy(&m_data.item, &temp_data->item, sizeof(nvram_ef_vapp_fmrdo_fav_list_struct));

        WriteValue(NVRAM_VAPP_FMRDO_FAV_LIST_NUM, &m_total, DS_BYTE, &error);
        WriteRecord(NVRAM_EF_VAPP_FMRDO_FAV_LIST_LID, 1, &m_data, sizeof(nvram_ef_vapp_fmrdo_fav_list_struct), &error);
    }

    VFX_FREE_MEM(temp_data);
    
}

void VappFMRadioFavMgr::editList(VfxU16 freq, VfxWString name, VfxU8 index)
{
    S16 error;

    m_data.item[index].fav_freq = freq;
    memcpy(&m_data.item[index].fav_name, (const VfxWChar*)name, sizeof(VfxWChar)*(name.getLength()+1) );

    WriteRecord(NVRAM_EF_VAPP_FMRDO_FAV_LIST_LID, 1, &m_data, sizeof(nvram_ef_vapp_fmrdo_fav_list_struct), &error);
}

VfxBool VappFMRadioFavMgr::addToList(VfxU16 freq, VfxWString name)
{
    S16 error;

    if(m_total >= VAPP_FM_RADIO_AUTO_LIST_NUM)
    {
        return VFX_FALSE;
    }

    m_data.item[m_total].fav_freq = freq;

    memcpy(&m_data.item[m_total].fav_name, (const VfxWChar*)name, sizeof(VfxWChar)*(name.getLength()+1) );

    m_total ++ ;

    WriteValue(NVRAM_VAPP_FMRDO_FAV_LIST_NUM, &m_total, DS_BYTE, &error);

    WriteRecord(NVRAM_EF_VAPP_FMRDO_FAV_LIST_LID, 1, &m_data, sizeof(nvram_ef_vapp_fmrdo_fav_list_struct), &error);

    m_favListUpdated.postEmit();

    return VFX_TRUE;

}


/***************************************************************************** 
 * Class VappFMRadioListFav
 *****************************************************************************/
VappFMRadioListFav::VappFMRadioListFav():
    m_app(NULL),
    m_edit(NULL),
    m_addFav(NULL),
    m_favMgr(NULL),
    m_mode(VappFMRadioListFav::ADD_MODE),
    m_tappedIdx(-1),
    m_deleteCnf(NULL),
    m_favListToolBar(NULL),
	m_list(NULL)    
{}

void VappFMRadioListFav::onInit(void)
{
    VfxFrame::onInit();

	// set rect
	setPos(0,0);
	setSize(((VfxFrame*)getParent())->getSize());

    // fav list
    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    m_list->setPos(0,0);
    m_list->setSize(getSize().width, getSize().height - VCP_TOOL_BAR_HEIGHT);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT); 
    m_list->setMenuMode(VCP_LIST_MENU_MODE_NORMAL,VFX_TRUE);
    m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON,VFX_FALSE);
    m_list->setContentProvider(this);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappFMRadioListFav::onSelectedChanged);
    m_list->m_signalCmdButtonClicked.connect(this, &VappFMRadioListFav::onEditButtonClicked);
    m_list->m_signalItemTapped.connect(this,&VappFMRadioListFav::onItemTapped);

    // favorite manager
    VFX_OBJ_CREATE(m_favMgr, VappFMRadioFavMgr, this);
    m_favMgr->m_favListUpdated.connect(this,&VappFMRadioListFav::updateListMenu);

	// fav list tool bar
    VFX_OBJ_CREATE(m_favListToolBar, VcpToolBar, this);
	m_favListToolBar->setPos(0, m_list->getSize().height);
	m_favListToolBar->setSize(getSize().width, VCP_TOOL_BAR_HEIGHT);
    m_favListToolBar->m_signalButtonTap.connect(this,&VappFMRadioListFav::onButtonClicked);
    updateButton();

    for(VfxU8 i =0 ; i<VAPP_FM_RADIO_FAV_LIST_NUM ; i++)
    {
        m_select[i] = VFX_FALSE;
    }
    m_select_total = 0;

}

void VappFMRadioListFav::onItemTapped(VcpListMenu *menu, VfxU32 index)
{

    if( m_mode != ADD_MODE)
    {
        return;
    }

    VfxWString info;
    VfxU8 idx = m_favMgr->getTotal()-index-1;

#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
  #ifdef __MTK_TARGET__
	if(!srv_earphone_is_plug_in())
    {
        info = VFX_WSTR_RES(STR_ID_VAPP_FM_PLUG_IN_EARPHONE);
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
    }
    else
  #endif
#endif
    if(m_app->getState() == VADP_FM_RADIO_POWER_OFF)
    {
        info = VFX_WSTR_RES(STR_ID_VAPP_FM_ASK_POWER_ON);
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
    }
    else
    {
        m_app->setFreq(m_favMgr->getFreq(idx), VFX_TRUE);
        m_tappedIdx = idx;
        m_app->m_mainPage->updateFreq(VFX_TRUE);
		m_tappedIdx = -1;
        m_list->updateAllItems();
    }
}

void VappFMRadioListFav::setApp(VappFMRadioApp* app)
{
    m_app = app;
}

VfxU32 VappFMRadioListFav::getCount(void) const
{
    return m_favMgr->getTotal();
}

VfxBool VappFMRadioListFav::getItemImage(VfxU32 index,                    // [IN] the index of item
                                         VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                                         VfxImageSrc &image               // [OUT] the image resource
                                         ) 
{
    //for command button image
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
        {
            image.setResId(IMG_ID_VAPP_FM_FAV_EDIT);
            return VFX_TRUE;
        }

        default:
            return VFX_FALSE;

    }

}

VcpListMenuItemStateEnum VappFMRadioListFav::getItemState(VfxU32 index) const
{
    VfxU8 idx = m_favMgr->getTotal()-index-1;

    if(m_select[idx])
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

VcpListMenuCellClientBaseFrame* VappFMRadioListFav::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    VfxU8 idx = m_favMgr->getTotal()-(VfxU8)index - 1;
    VfxWChar* name = m_favMgr->getName(idx);

    if(name[0] != 0x00)
    {
        return NULL;
    }

    VcpListMenuCellSingleTextFrame * SingleText = NULL;
    VFX_OBJ_CREATE(SingleText, VcpListMenuCellSingleTextFrame, parentFrame);

    return SingleText;
}

VfxBool VappFMRadioListFav::getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame *frame)
{
    VfxU8 idx = m_favMgr->getTotal()-(VfxU8)index - 1;

    if((m_app->getFreq() == m_favMgr->getFreq(idx)) &&
		((fieldType == VCP_LIST_MENU_FIELD_TEXT) || (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)))
    {
        frame->setColor(LIST_HIGHLIGHT_COLOR);
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappFMRadioListFav::getItemText(VfxU32 index,                    // [IN] the index of item
                                        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                                        VfxWString &text,                // [OUT] the text resource
                                        VcpListMenuTextColorEnum &color  // [OUT] the text color
                                        )
{
    VfxU8 idx = m_favMgr->getTotal()-(VfxU8)index - 1;

    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        VfxWChar* name = m_favMgr->getName(idx);
        if(name[0] != 0x00)
        {
            text = VFX_WSTR_MEM(name);
        }
        else
        {
            VfxU16 freq = m_favMgr->getFreq(idx);
            text.format("FM %d.%d", freq/10, freq%10);
        }
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        VfxWChar* name = m_favMgr->getName(idx);
        if(name[0] != 0x00)
        {
            VfxU16 freq = m_favMgr->getFreq(idx);
            text.format("FM %d.%d", freq/10, freq%10);
        }
        else
        {
            text.setEmpty();
        }
    }
    else
    {
         return VFX_FALSE;
    }

     return VFX_TRUE;
}



VfxBool VappFMRadioListFav::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
{
    text = VFX_WSTR_RES(STR_ID_VAPP_FM_FAV_LIST_EMPTY);
    return VFX_TRUE;
}

void VappFMRadioListFav::onAddToFavPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn)
{
    switch(btn)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            VfxWString inputName =((VcpInputPopup*)sender)->getText(0);
            VfxWString inputFreq =((VcpInputPopup*)sender)->getText(1);

            VfxWString ErrMsg;

            VfxU16 freq = VappFMRadioMainPage::WStringToFreq((VfxWChar *)inputFreq.getBuf(),this);

            if(freq < VappFMRadioApp::MIN_FREQ || freq > VappFMRadioApp::MAX_FREQ)
            {
                ErrMsg = VFX_WSTR_RES(STR_ID_VAPP_FM_INVALID_FQ);
                ((VcpInputPopup*)sender)->setErrorText(ErrMsg,1);
                return;
            }
            
            m_favMgr->addToList(freq, inputName);

            VFX_OBJ_CLOSE(m_addFav);

            updateButton();

            m_app->m_mainPage->pureUpdateFreq(VFX_FALSE);

            VfxWString info;
            info = VFX_WSTR_RES(STR_ID_VAPP_FM_ADDED_TO_FAV);
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
            break;
        }

        case VCP_INPUT_POPUP_BTN_CANCEL:
        {
            VFX_OBJ_CLOSE(m_addFav);
            break;
        }

        default:
            break;
    }
}


void VappFMRadioListFav::onSelectedChanged(VcpListMenu* menu, VfxU32 index, VcpListMenuItemStateEnum state)
{
    VfxU8 idx = m_favMgr->getTotal()-index-1;

    if(state == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
    {
        m_select[idx] = VFX_FALSE;
        m_select_total --;
    }
    else
    {
        m_select[idx] = VFX_TRUE;
        m_select_total ++;
    }

    updateButton();

}

void VappFMRadioListFav::onEditPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn)
{
    switch(btn)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            VfxWString inputName =((VcpInputPopup*)sender)->getText(0);
            VfxWString inputFreq =((VcpInputPopup*)sender)->getText(1);

            VfxWString ErrMsg;

            VfxU16 freq = VappFMRadioMainPage::WStringToFreq((VfxWChar *)inputFreq.getBuf(),this);

            if(freq < VappFMRadioApp::MIN_FREQ || freq > VappFMRadioApp::MAX_FREQ)
            {
                ErrMsg = VFX_WSTR_RES(STR_ID_VAPP_FM_INVALID_FQ);
                ((VcpInputPopup*)sender)->setErrorText(ErrMsg,1);
                return;
            }

            m_favMgr->editList(freq, inputName, m_favMgr->getEditIndex());

            VFX_OBJ_CLOSE(m_edit);

            m_list->updateAllItems();

            VfxU16 cur_freq = m_app->getFreq();

            m_tappedIdx = m_favMgr->getEditIndex();
            m_app->m_mainPage->pureUpdateFreq(VFX_FALSE);
            m_tappedIdx = -1;

            break;
        }

        case VCP_INPUT_POPUP_BTN_CANCEL:
        {
            VFX_OBJ_CLOSE(m_edit);
            break;
        }

        default:
            break;
    }
}


void VappFMRadioListFav::onEditButtonClicked(VcpListMenu *listmenu, VfxU32 index)
{
    VfxU8 idx = m_favMgr->getTotal()-index-1;

    VFX_OBJ_CREATE(m_edit, VcpInputPopup, this);

    VfxWString title;
    title = VFX_WSTR_RES(STR_ID_VAPP_FM_EDIT_CHANNEL);

    VfxWString name = VFX_WSTR_MEM(m_favMgr->getName(idx));

    m_favMgr->setEditIndex(idx);

    m_edit->setGroupNum(2);
    m_edit->setTitle(title);

    VfxWString channel_name;
    channel_name = VFX_WSTR_RES(STR_ID_VAPP_FM_CHANNEL_NAME);

    m_edit->setHintText(channel_name,0);
    m_edit->setIME(IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE,0);
    m_edit->setText(name, 19, VFX_FALSE, 0);

    VfxWString fq;
    fq = VFX_WSTR_RES(STR_ID_VAPP_FM_FQ);

    VfxWString freq;
    freq.format("%d.%d", m_favMgr->getFreq(idx)/10, m_favMgr->getFreq(idx)%10);

    m_edit->setHintText(fq,1);
    m_edit->setIME(IMM_INPUT_TYPE_DECIMAL_NUMERIC, IME_SETTING_FLAG_NONE,1);
    m_edit->setText(freq, 5, VFX_FALSE, 1);
	
	m_edit->getInputbox(0)->m_signalActivated.connect(this, &VappFMRadioListFav::onEditTextActivated);
	m_edit->getInputbox(1)->m_signalActivated.connect(this, &VappFMRadioListFav::onEditTextActivated);
    m_edit->m_signalButtonClicked.connect(this,&VappFMRadioListFav::onEditPopUpButtonClicked);
    m_edit->show(VFX_TRUE);

}

void VappFMRadioListFav::onEditTextActivated(VcpTextEditor *sender, VfxBool activated)
{
    if (activated)
    {
	    VfxWChar *str;
	    str = sender->getText();
	    VfxU32 len;
	    len = mmi_wcslen((WCHAR*)str);
		
        sender->setHighlight(0, len);
    }
}

void VappFMRadioListFav::onDeleteButtonClicked(VfxObject* sender, VfxId btn)
{
    switch(btn)
    {
        //continue
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VFX_OBJ_CLOSE(m_deleteCnf);

            m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT); 
            m_list->setMenuMode(VCP_LIST_MENU_MODE_NORMAL,VFX_TRUE);
            m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON,VFX_FALSE);


            m_favMgr->DeleteItems(m_select);

            for(VfxU8 i =0 ; i<VAPP_FM_RADIO_FAV_LIST_NUM ; i++)
            {
                m_select[i] = VFX_FALSE;
            }

            m_select_total = 0;

            m_mode = ADD_MODE;

            updateButton();

            m_list->resetAllItems();
            m_app->m_mainPage->pureUpdateFreq(VFX_FALSE);
            break;
        }

        //cancel
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        {
            VFX_OBJ_CLOSE(m_deleteCnf);
            break;
        }
    }

}

void VappFMRadioListFav::onButtonClicked(VfxObject *sender, VfxId id)
{
    switch(id)
    {
        case TOOL_BAR_BTN_ADD:
        {
            //VcpInputPopup *addFav;
            VFX_OBJ_CREATE(m_addFav, VcpInputPopup, this);

            VfxWString title;
            title = VFX_WSTR_RES(STR_ID_VAPP_FM_ADD_TO_FAV);

            m_addFav->setGroupNum(2);
            m_addFav->setTitle(title);

            VfxWString channel_name;
            channel_name = VFX_WSTR_RES(STR_ID_VAPP_FM_CHANNEL_NAME);
            
            m_addFav->setHintText(channel_name,0);
            m_addFav->setIME(IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE,0);
            m_addFav->setText(VFX_WSTR(""), 19, VFX_FALSE, 0);

            VfxWString fq;
            fq = VFX_WSTR_RES(STR_ID_VAPP_FM_FQ);
            m_addFav->setHintText(fq,1);
            m_addFav->setIME(IMM_INPUT_TYPE_DECIMAL_NUMERIC, IME_SETTING_FLAG_NONE,1);
            m_addFav->setText(VFX_WSTR(""), 5, VFX_FALSE, 1);

            m_addFav->m_signalButtonClicked.connect(this,&VappFMRadioListFav::onAddToFavPopUpButtonClicked);
            m_addFav->show(VFX_TRUE);

            break;
        }

        case TOOL_BAR_BTN_DELETE:
        {
            m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT); 
            m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION,VFX_TRUE);
            m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);

            m_mode = DELETE_MODE;

            updateButton();

            break;
        }

		case TOOL_BAR_BTN_SELECT_ALL:
        {
			onBtnSelectAllClicked();
			break;
		}

        case TOOL_BAR_BTN_DELETE2:
        {
            VFX_OBJ_CREATE(m_deleteCnf, VcpConfirmPopup, this);
            m_deleteCnf->setInfoType(VCP_POPUP_TYPE_WARNING);

            VfxWChar delete_wchar[30];
            kal_wsprintf(delete_wchar, "%w%d%w", GetString(STR_ID_VAPP_FM_DELETE_FAV_Q_1), m_select_total, GetString(STR_ID_VAPP_FM_DELETE_FAV_Q_2));
            m_deleteCnf->setText(VFX_WSTR_MEM(delete_wchar));

            m_deleteCnf->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            m_deleteCnf->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
            m_deleteCnf->setAutoDestory(VFX_FALSE);
            m_deleteCnf->show(VFX_TRUE);
            m_deleteCnf->m_signalButtonClicked.connect(this, &VappFMRadioListFav::onDeleteButtonClicked);
            break;
        }

        case TOOL_BAR_BTN_CANCEL:
        {
            cancelDelete();
            break;
        }        

        default:
        {
            break;
        }

    }

}

void VappFMRadioListFav::updateButton(void)
{
	m_favListToolBar->removeAllItems();
    if(m_mode == ADD_MODE)
    {	
    	m_favListToolBar->addItem(TOOL_BAR_BTN_ADD, VFX_WSTR_RES(VCP_STR_TOOL_BAR_ADD), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    	m_favListToolBar->addItem(TOOL_BAR_BTN_DELETE, VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

        if(m_favMgr->getTotal() == 0)
        {
            m_favListToolBar->setDisableItem(TOOL_BAR_BTN_DELETE, VFX_TRUE);
        }
        else
        {
            m_favListToolBar->setDisableItem(TOOL_BAR_BTN_DELETE, VFX_FALSE);
        }

        if(m_favMgr->getTotal() == VAPP_FM_RADIO_AUTO_LIST_NUM)
        {
            m_favListToolBar->setDisableItem(TOOL_BAR_BTN_ADD, VFX_TRUE);
        }
        else
        {
            m_favListToolBar->setDisableItem(TOOL_BAR_BTN_ADD, VFX_FALSE);
        }

    }
    else
    {  
        if(m_select_total == m_favMgr->getTotal())
        {
	        m_favListToolBar->addItem(TOOL_BAR_BTN_SELECT_ALL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_UNSELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
	        m_showSelectAll = VFX_FALSE;
        }
        else
        {
			m_favListToolBar->addItem(TOOL_BAR_BTN_SELECT_ALL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
			m_showSelectAll = VFX_TRUE;
        }

    	m_favListToolBar->addItem(TOOL_BAR_BTN_DELETE2, VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    	m_favListToolBar->addItem(TOOL_BAR_BTN_CANCEL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

        if(m_select_total > 0)
        {
            m_favListToolBar->setDisableItem(TOOL_BAR_BTN_DELETE2, VFX_FALSE);
        }
        else
        {
            m_favListToolBar->setDisableItem(TOOL_BAR_BTN_DELETE2, VFX_TRUE);
        }
		
		m_favListToolBar->setDisableItem(TOOL_BAR_BTN_CANCEL, VFX_FALSE);
    }
}

void VappFMRadioListFav::onBtnSelectAllClicked()
{
	VfxU8 favCount = m_favMgr->getTotal();
	VfxBool isSelected;
	if(m_showSelectAll)
	{
		isSelected = VFX_TRUE;
		m_select_total = favCount; 
		m_favListToolBar->changeItem(TOOL_BAR_BTN_SELECT_ALL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_UNSELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
        m_favListToolBar->setDisableItem(TOOL_BAR_BTN_DELETE2, VFX_FALSE);
        m_showSelectAll = VFX_FALSE;		
	}
	else
	{
		isSelected = VFX_FALSE;
		m_select_total = 0; 
		m_favListToolBar->changeItem(TOOL_BAR_BTN_SELECT_ALL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
        m_favListToolBar->setDisableItem(TOOL_BAR_BTN_DELETE2, VFX_TRUE);
        m_showSelectAll = VFX_TRUE;
	}

    for(VfxU8 index = 0; index < favCount; index++)
    {
    	m_select[index] = isSelected;
    }

    // Ask list  to update without emit m_signalItemSelectionStateChanged
    m_list->resetAllItems(VFX_TRUE);	
	
}


void VappFMRadioListFav::updateListMenu(void)
{
    m_list->resetAllItems();
}

void VappFMRadioListFav::addToFavList(VfxU16 freq, VfxWString name)
{
    m_favMgr->addToList(freq,name);

    updateButton();
}

VfxWChar* VappFMRadioListFav::getFavName(VfxU16 freq)
{
    if(m_tappedIdx >= 0)
    {
        if(m_favMgr->m_data.item[m_tappedIdx].fav_freq == freq)
        {
            return (VfxWChar*)m_favMgr->m_data.item[m_tappedIdx].fav_name;
        }
    }

    for(VfxS16 i=m_favMgr->m_total-1 ; i>=0 ; i--)
    {
        if(m_favMgr->m_data.item[i].fav_freq == freq)
        {
            return (VfxWChar*)m_favMgr->m_data.item[i].fav_name;
        }
    }
    return NULL;
}

void VappFMRadioListFav::cancelDelete(void)
{
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT); 
    m_list->setMenuMode(VCP_LIST_MENU_MODE_NORMAL,VFX_TRUE);
    m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON,VFX_FALSE);

    for(VfxU8 i =0 ; i<VAPP_FM_RADIO_FAV_LIST_NUM ; i++)
    {
        m_select[i] = VFX_FALSE;
    }

    m_select_total = 0;

    m_mode = ADD_MODE;

    updateButton();
}

VfxBool VappFMRadioListFav::onBackKey(void)
{
    if(m_mode != DELETE_MODE)
    {
        return VFX_FALSE;
    }

    cancelDelete();

    return VFX_TRUE;
}


/***************************************************************************** 
 * Class VappFMRadioChannelListPage
 *****************************************************************************/
VappFMRadioChannelListPage::VappFMRadioChannelListPage():
	m_app(NULL),
	m_tabBar(NULL),
	m_pagePanel(NULL),
	m_tabChoose(TAB_ITEM_FAVORITE),
    m_autoList(NULL),
    m_favList(NULL)
{
}

void VappFMRadioChannelListPage::onInit()
{
    VfxPage::onInit();

	// init m_app
	m_app = VFX_OBJ_DYNAMIC_CAST(getMainScr()->getApp(),VappFMRadioApp);

	// create tabbar
	VFX_OBJ_CREATE(m_tabBar, VcpTabTitleBar, this);	
	m_tabBar->addTab(TAB_ITEM_AUTO_SEARCH, VcpStateImage(IMG_ID_VAPP_FM_ICON_AUTO_SEARCH), VFX_WSTR_RES(STR_ID_VAPP_FM_AUTO_SEARCH));
	m_tabBar->addTab(TAB_ITEM_FAVORITE, VcpStateImage(IMG_ID_VAPP_FM_ICON_FAV), VFX_WSTR_RES(STR_ID_VAPP_FM_FAV));
	m_tabBar->setHighlightedTab(m_tabChoose);
	m_tabBar->m_signalTabSwitched.connect(this, &VappFMRadioChannelListPage::onTabSwitch);
	setTopBar(m_tabBar);
	
	// create page panel
    VFX_OBJ_CREATE(m_pagePanel, VcpPagePanel, this);
    m_pagePanel->setPos(0,0);	
    m_pagePanel->setSize(getSize().width, (getSize().height - m_tabBar->getSize().height - CFG_UI_STATUS_BAR_HEIGHT));

	// create fav list
	VFX_OBJ_CREATE(m_favList, VappFMRadioListFav, m_pagePanel);
	m_favList->setApp(m_app);
	m_favList->setPos(0,0);
	m_favList->setSize(m_pagePanel->getSize());

	// create auto list
	VFX_OBJ_CREATE(m_autoList, VappFMRadioListAuto, m_pagePanel);
	m_autoList->setApp(m_app);
	m_autoList->setPos(0,0);
	m_autoList->setSize(m_pagePanel->getSize());

	// set current channel list
	if(m_tabChoose == TAB_ITEM_AUTO_SEARCH)
    {
        m_pagePanel->setCurrentFrame(m_autoList);
    }
    else
    {
        m_pagePanel->setCurrentFrame(m_favList);
    }

    registerKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
    registerKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);
}

void VappFMRadioChannelListPage::onTabSwitch (VfxObject* sender, VfxId id)
{
    if(id == TAB_ITEM_AUTO_SEARCH)
    {
        if(m_tabChoose == TAB_ITEM_AUTO_SEARCH)
        {
            return;
        }
	
        m_tabChoose = TAB_ITEM_AUTO_SEARCH;
        updateList();		
        m_pagePanel->switchTo(m_autoList, VCP_PAGE_EFFECT_FADE_IN, 50, VCP_PAGE_DIRECTION_FROM_LEFT, VFX_FALSE);
        m_autoList->m_list->setFocused(VFX_TRUE);
		m_autoList->updateAutoList();
    }
    else
    {
        if(m_tabChoose == TAB_ITEM_FAVORITE)
        {
            return;
        }
		
        m_tabChoose = TAB_ITEM_FAVORITE;
        updateList();		
        m_pagePanel->switchTo(m_favList, VCP_PAGE_EFFECT_FADE_IN, 100, VCP_PAGE_DIRECTION_FROM_RIGHT, VFX_FALSE);
        m_favList->m_list->setFocused(VFX_TRUE);
    }   
}

void VappFMRadioChannelListPage::onBack()
{
    if((m_tabChoose != TAB_ITEM_FAVORITE) || (!m_favList->onBackKey()))
    {
		VfxPage::onBack();
    }
}

VfxBool VappFMRadioChannelListPage::onKeyInput(VfxKeyEvent & event)
{
	if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		if(m_app->getState() == VADP_FM_RADIO_SCANING)
		{
			//Pop out balloon "currently not avaiable" only in key down. Do nothing in key up.
			VfxWString info;
			info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());

			return VFX_FALSE;
		}

		switch (event.keyCode)
		{
			case VFX_KEY_CODE_ARROW_LEFT:
			{
				//switch to auto
				m_tabBar->setHighlightedTab(TAB_ITEM_AUTO_SEARCH);
				onTabSwitch(this, TAB_ITEM_AUTO_SEARCH);
				return VFX_TRUE;				
			}
			
			case VFX_KEY_CODE_ARROW_RIGHT:
			{
				//switch to fav
				m_tabBar->setHighlightedTab(TAB_ITEM_FAVORITE);
				onTabSwitch(this, TAB_ITEM_FAVORITE);
				return VFX_TRUE;
			}
		}
	}
    return VfxPage::onKeyInput(event);
}


void VappFMRadioChannelListPage::updateList(void)
{
    if(m_tabChoose == TAB_ITEM_AUTO_SEARCH)
    {
        m_autoList->m_list->updateAllItems();
    }
    else
    {
        m_favList->m_list->updateAllItems();
    }
}

void VappFMRadioChannelListPage::onAutoScanDone(void)
{
	m_autoList->onAutoScanDone();
}

#pragma arm section code, rodata

#endif /* __MMI_FM_RADIO_SLIM__ */


