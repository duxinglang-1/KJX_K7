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
 *   vapp_fm_radio.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  FM Radio file
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

#ifdef __MMI_FM_RADIO__

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
#include "vapp_fm_radio.h"
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

mmi_ret vapp_fm_radio_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

#ifdef __cplusplus
}
#endif

VFX_IMPLEMENT_CLASS("VappFMRadioApp", VappFMRadioApp, VfxApp);

VappFMRadioApp* VappFMRadioApp::m_self = NULL;

VappFMRadioApp::VappFMRadioApp():
    m_state(VADP_FM_RADIO_POWER_OFF),
    m_curFreq(900),
    m_preFreq(900),
    m_delaySetFreqTimer(NULL),
    m_delaySetPowerOnFreqTimer(NULL),
#ifdef __MMI_FM_RADIO_RECORD__
	m_recState(VADP_FM_RADIO_REC_IDLE),
    m_recTime(0),
    m_storage(STORAGE_PHONE),
    m_quality(VappFMRadioApp::QUALITY_STANDARD),
    m_pathLoopTimer(NULL),
    m_recTimer(NULL),
    m_errRecStr(STR_GLOBAL_ERROR),
#endif
#ifdef __FM_RADIO_RDS_SUPPORT__
    m_RDS(VFX_FALSE),
    m_AF(VFX_FALSE),
    m_TP(VFX_FALSE),
    m_RDSMask(0),
#endif
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

#ifdef __MMI_FM_RADIO_RECORD__
	#ifdef __LOW_COST_SUPPORT_COMMON__
		setStorage(STORAGE_MEMORY_CARD);
	#endif
#endif

	//m_state must update first
    queryState();

    m_curFreq = (VfxU16)vadp_fm_radio_get_cur_freq();

	if(!srv_earphone_is_plug_in() && vadp_fm_radio_get_aud_path() == MDI_DEVICE_SPEAKER_BOTH)
    {
        vadp_fm_radio_reset_aud_path();
    }

    S16 error;
	//ReadValue(NVRAM_VAPP_FMRDO_CUR_FREQ, &m_curFreq, DS_SHORT, &error);
#ifdef __MMI_FM_RADIO_RECORD__
    ReadValue(NVRAM_VAPP_FMRDO_STORAGE, &m_storage, DS_BYTE, &error);
    ReadValue(NVRAM_VAPP_FMRDO_QUALITY, &m_quality, DS_BYTE, &error);
#endif

#ifdef __FM_RADIO_RDS_SUPPORT__
    ReadValue(NVRAM_VAPP_FMRDO_RDS, &m_RDS, DS_BYTE, &error);
    ReadValue(NVRAM_VAPP_FMRDO_AF, &m_AF, DS_BYTE, &error);
    ReadValue(NVRAM_VAPP_FMRDO_TP, &m_TP, DS_BYTE, &error);
#endif


    /*clear program name first*/
#ifdef __FM_RADIO_RDS_SUPPORT__
    memset(&m_programName, 0, sizeof(m_programName));
    memset(&m_radioText, 0, sizeof(m_radioText));
#endif

#ifdef __MMI_FM_RADIO_RECORD__
    VFX_OBJ_CREATE(m_pathLoopTimer, VfxTimer, this);
    m_pathLoopTimer->setStartDelay(200);
    m_pathLoopTimer->m_signalTick.connect(this, &VappFMRadioApp::onFindRecPathLoopTimeOut);

    VFX_OBJ_CREATE(m_recTimer, VfxTimer, this);
    m_recTimer->setStartDelay(0);
    m_recTimer->setDuration(250);
    m_recTimer->m_signalTick.connect(this, &VappFMRadioApp::onRecTimeTextUpdate);
#endif

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
	}

#ifdef __MMI_FM_VIA_A2DP__
	if(m_a2dpConnectTimer != NULL)
	{
		VFX_OBJ_CLOSE(m_a2dpConnectTimer);
	}
#endif

#ifdef __MMI_FM_RADIO_RECORD__
	vadp_fm_radio_set_rec_state(m_recState);
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
			
		#ifdef __FM_RADIO_RDS_SUPPORT__
			turnOnRDS();
		#endif

			if(m_mainPage->m_list != NULL)
			{
				m_mainPage->m_list->m_autoList->m_autoMgr->updateFreq(
					m_mainPage->m_list->m_autoList->m_autoMgr->m_total,
					m_mainPage->m_list->m_autoList->m_autoMgr->m_freq);
				
				m_mainPage->m_list->m_autoList->m_list->updateAllItems();
				
				VFX_OBJ_CLOSE(m_mainPage->m_list->m_autoList->m_waiting);
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
        case VAPP_NCENTER_EVENT_EXIT:
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

#ifdef __MMI_FM_RADIO_RECORD__
	setRecState(m_recState, VFX_FALSE);
	recTimeUpdate();

	m_memoryCardPlugged.emit();
#endif

}

void VappFMRadioApp::queryState(void)
{
    m_state = vadp_fm_radio_query_state();
	
	#ifdef __MMI_FM_RADIO_RECORD__
		m_recState = vadp_fm_radio_query_rec_state();

	#ifdef __MMI_USB_SUPPORT__
	    /* check is in mass storage mode */
	    if (srv_usb_is_in_mass_storage_mode())
	    {
	        m_recState = VADP_FM_RADIO_REC_DISABLED;
	    }
	#endif /* __MMI_USB_SUPPORT__ */ 
	#endif

}

void VappFMRadioApp::procCallback(mmi_event_struct *evt, void *user_data)
{
    VappFMRadioApp* ptr = (VappFMRadioApp*)handleToObject((VfxObjHandle)user_data);

	switch(evt->evt_id)
	{

	#ifdef __MMI_FM_RADIO_RECORD__
	#ifdef __MMI_USB_SUPPORT__
		case EVT_ID_USB_ENTER_MS_MODE:
		{
			ptr->stopRec(VFX_FALSE, VFX_FALSE);
			ptr->setRecState(VADP_FM_RADIO_REC_DISABLED, VFX_FALSE);
			break;
		}

		case EVT_ID_USB_EXIT_MS_MODE:
		{
			ptr->setRecState(VADP_FM_RADIO_REC_IDLE, VFX_FALSE);
			break;
		}
	#endif
	#endif

		case EVT_ID_GPIO_EARPHONE_PLUG_OUT:
		{
			ptr->updateSpeakerState();
			#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
				ptr->stopRec(VFX_FALSE, VFX_FALSE);
				ptr->pureSetState(VADP_FM_RADIO_POWER_OFF);
			#endif

			break;
		}

		case EVT_ID_GPIO_EARPHONE_PLUG_IN:
		{
			ptr->updateSpeakerState();
			break;
		}

		case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
		{
			#ifdef __MMI_FM_RADIO_RECORD__
				ptr->stopRec(VFX_FALSE, VFX_FALSE);
			#endif
			break;
		}

	//klawmo
	#ifdef __DM_LAWMO_SUPPORT__
		case EVT_ID_SRV_DM_LAWMO_LOCK_IND:
		{
			ptr->stopRec(VFX_FALSE, VFX_FALSE);
			ptr->pureSetState(VADP_FM_RADIO_POWER_OFF);
			break;
		}
	#endif

	#ifdef __MMI_FM_RADIO_RECORD__
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
		{
			ptr->m_memoryCardPlugged.emit();
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
	if((m_mainPage != NULL) && (m_scr->isActive()) && (m_mainPage->isActive())			//FM Radio main page active 
		&& (m_mainPage->m_pagePanel != NULL) && (m_mainPage->m_control != NULL)
		&& (m_mainPage->m_pagePanel->getCurrentFrame() == m_mainPage->m_control))		//FM Radio main interface active
	{
		return VFX_TRUE;
	}

	return VFX_FALSE;
}

void VappFMRadioApp::updateSpeakerState(void)
{
	m_mainPage->m_control->updateSpeakerBtn(vadp_fm_radio_get_aud_path());
}

void VappFMRadioApp::generalCallback(mdi_result result, void* user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_GENERALCALLBACK, result);

    VappFMRadioApp* ptr = (VappFMRadioApp*)handleToObject((VfxObjHandle)user_data);

    if(ptr == NULL)
    {
        return;
    }

    switch(result)
    {
		case MDI_AUDIO_TERMINATED:
        {
			
		#ifdef __MMI_FM_RADIO_RECORD__
			ptr->stopRec(VFX_FALSE, VFX_FALSE);
		#endif
			ptr->pureSetState(VADP_FM_RADIO_INTERRUPT);

            break;
        }
		default:
			break;
    }
}

MMI_BOOL VappFMRadioApp::backgroundCallback(mdi_result result, void *user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_BACKGROUNDCALLBACK, result);

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

#ifdef __FM_RADIO_RDS_SUPPORT__

void VappFMRadioApp::RDSCallback(mdi_rds_event_struct *buffer, void *user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_RDSCALLBACK, buffer->event);

    VappFMRadioApp* ptr = (VappFMRadioApp*)handleToObject((VfxObjHandle)user_data);

    if(ptr == NULL)
    {
        return; //MMI_TRUE;
    }

    switch(buffer->event)
    {
        case MDI_RDS_EVENT_FLAGS:
        {
            if(buffer->flag & MDI_RDS_FLAG_IS_TP)
            {
                if(buffer->data[0])
                {
                    ptr->setMask(VAPP_FMRADIO_TP);
                }
                else
                {
                    ptr->clearMask(VAPP_FMRADIO_TP);
                }
            }

            break;
        }

        case MDI_RDS_EVENT_PROGRAMNAME:
        {
            if(ptr->m_RDS)
            {
                /* check if user have it's own naming first */
                mmi_ucs2ncpy((CHAR*)(ptr->m_programName),(CHAR*)(buffer->data), VAPP_FMRADIO_RDS_PN_CHAR_NUM- 1);
                ptr->setMask(VAPP_FMRADIO_PN);
                ptr->m_mainPage->m_info->updateInfoString();
            }
            break;
        }
	
        case MDI_RDS_EVENT_LAST_RADIOTEXT:
        {
			if (ptr->m_RDS)
            {
                mmi_ucs2ncpy((CHAR*)(ptr->m_radioText),(CHAR*)(buffer->data), VAPP_FMRADIO_RDS_RT_CHAR_NUM);
                ptr->setMask(VAPP_FMRADIO_RT);
                ptr->m_mainPage->m_info->updateInfoString();
            }
            break;
        }

        case MDI_RDS_EVENT_AF:
        {
            ptr->setFreq((VfxU16)buffer->data[0],VFX_FALSE);
            ptr->m_mainPage->updateFreq(VFX_FALSE);
            break;
        }

        case MDI_RDS_EVENT_AF_LIST:
        {
            ptr->setMask(VAPP_FMRADIO_AF);
            break;
        }

        case MDI_RDS_EVENT_TAON:
        {
            ptr->setMask(VAPP_FMRADIO_TAON);
            ptr->setFreq((VfxU16)buffer->data[0],VFX_FALSE);
            ptr->m_mainPage->updateFreq(VFX_FALSE);

            break;
        }

        case MDI_RDS_EVENT_TAON_OFF:
        {
            if(ptr->m_RDSMask & VAPP_FMRADIO_TAON)
            {
                ptr->clearMask(VAPP_FMRADIO_TAON);
                ptr->setFreq((VfxU16)buffer->data[0],VFX_FALSE);
                ptr->m_mainPage->updateFreq(VFX_FALSE);
            }
            break;
        }

		default:
            break;

    }


}

void VappFMRadioApp::turnOnRDS(void)
{
    if(m_RDS)
    {
        MMI_BOOL af_support = MMI_FALSE;
        MMI_BOOL tp_support = MMI_FALSE;
        
        if(m_AF 
        #ifdef __MMI_FM_RADIO_RECORD__
            && (m_recState == VADP_FM_RADIO_REC_IDLE || m_recState == VADP_FM_RADIO_REC_DISABLED)
        #endif
          )
        {
            af_support = MMI_TRUE;
        }

        if(m_TP 
         #ifdef __MMI_FM_RADIO_RECORD__
            && (m_recState == VADP_FM_RADIO_REC_IDLE || m_recState == VADP_FM_RADIO_REC_DISABLED)
         #endif
          )
        {
            tp_support = MMI_TRUE;
        }

    	mdi_result result = mdi_fmr_rds_enable(&VappFMRadioApp::RDSCallback, af_support, tp_support, getObjHandle());

        if(result == MDI_AUDIO_SUCCESS)
        {
            setMask(VAPP_FMRADIO_RDS_ON);
        }
    }
}

void VappFMRadioApp::turnOffRDS(void)
{
	mdi_fmr_rds_disable();
	resetRDS(VAPP_FMRADIO_RDS_OFF);
}

void VappFMRadioApp::resetRDS(VfxU16 mask)
{
    memset(&m_programName, 0, sizeof(m_programName));
    memset(&m_radioText, 0, sizeof(m_radioText));

    clearMask(mask);

	m_mainPage->m_info->updateInfoString();
}

void VappFMRadioApp::enableAFTP(void)
{
    MMI_BOOL af_support = MMI_FALSE;
    MMI_BOOL tp_support = MMI_FALSE;

    if(m_AF 
    #ifdef __MMI_FM_RADIO_RECORD__
        && (m_recState == VADP_FM_RADIO_REC_IDLE || m_recState == VADP_FM_RADIO_REC_DISABLED)
    #endif
      )
    {
        af_support = MMI_TRUE;
    }
    
    if(m_TP 
     #ifdef __MMI_FM_RADIO_RECORD__
        && (m_recState == VADP_FM_RADIO_REC_IDLE || m_recState == VADP_FM_RADIO_REC_DISABLED)
     #endif
      )
    {
        tp_support = MMI_TRUE;
    }

    if(m_RDSMask & VAPP_FMRADIO_RDS_ON)
    {
        mdi_fmr_rds_af_tp_setting(af_support,tp_support);
    }

	if(!af_support)
	{
		clearMask(VAPP_FMRADIO_AF);
	}

	if(!tp_support)
	{
		clearMask(VAPP_FMRADIO_TP);
	}

    return;

}

void VappFMRadioApp::disableAFTP(void)
{
    if(m_RDSMask & VAPP_FMRADIO_RDS_ON)
    {
        mdi_fmr_rds_af_tp_setting(MMI_FALSE,MMI_FALSE);
        clearMask(VAPP_FMRADIO_AF);
        clearMask(VAPP_FMRADIO_TP);
    }

}

void VappFMRadioApp::clearMask(VfxU16 mask)
{
	m_RDSMask &= (~mask);
	m_mainPage->updateRDSArea();
}

void VappFMRadioApp::setMask(VfxU16 mask)
{
	m_RDSMask |= mask;
	if(m_mainPage != NULL)
	{
		m_mainPage->updateRDSArea();
	}
}

VfxBool VappFMRadioApp::getRDS(VappFMRadioApp::VappFMRadioRDSTypes type)
{
    switch(type)
    {
        case TYPE_RDS:
        {
            return m_RDS;
        }

        case TYPE_AF:
        {
            return m_AF;
        }

        case TYPE_TP:
        {
            return m_TP;
        }

        default:
            return VFX_FALSE;
    }

}

void VappFMRadioApp::setRDS(VappFMRadioApp::VappFMRadioRDSTypes type, VfxBool turn_on)
{
    S16 error;

    switch(type)
    {
        case TYPE_RDS:
        {
            m_RDS = turn_on;
            WriteValue(NVRAM_VAPP_FMRDO_RDS, &m_RDS, DS_BYTE, &error);

            if(turn_on)
            {
                turnOnRDS();
            }
            else
            {
                turnOffRDS();
            }

            break;
        }

        case TYPE_AF:
        {
            m_AF = turn_on;
            WriteValue(NVRAM_VAPP_FMRDO_AF, &m_AF, DS_BYTE, &error);
            enableAFTP();
            break;
        }

        case TYPE_TP:
        {
            m_TP = turn_on;
            WriteValue(NVRAM_VAPP_FMRDO_TP, &m_TP, DS_BYTE, &error);
            enableAFTP();
            break;
        }

        default:
            return;// VFX_FALSE;
    }


}

/*
void VappFMRadioApp::updateProgramName(void)
{
    if(m_mainPage->m_list == NULL)
    {
        return;
    }

    VfxWChar* fav_name = m_mainPage->m_list->m_favList->getFavName(m_curFreq);

    if(fav_name == NULL)
    {
        return;
    }
    memcpy(m_programName, fav_name, sizeof(m_programName));
}
*/

#endif

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

#ifdef __FM_RADIO_RDS_SUPPORT__
    turnOnRDS();
#endif

	setState(VADP_FM_RADIO_POWER_ON);
}

void VappFMRadioApp::powerOff(void)
{
#ifdef __MMI_FM_RADIO_RECORD__    
	stopRec(VFX_TRUE, VFX_TRUE);
#endif

#ifdef __FM_RADIO_RDS_SUPPORT__
	turnOffRDS();
#endif

	if(m_state != VADP_FM_RADIO_INTERRUPT)
	{
		vadp_fm_radio_app_power_off();
	}

	vadp_fm_radio_clear_background_handler();

	setState(VADP_FM_RADIO_POWER_OFF);
}

#ifdef __MMI_FM_RADIO_RECORD__

void VappFMRadioApp::recTimeUpdate()
{
    if((m_recState == VADP_FM_RADIO_REC_ING) || (m_recState == VADP_FM_RADIO_REC_PAUSE))
    {
	#ifdef __MTK_TARGET__
        m_recTime = mdi_audio_get_record_time();
	#else
        m_recTime = (m_recTime/1000 + 1)*1000;
	#endif

	    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_RECTIME_UPDATE, m_recTime);

        m_mainPage->updateRecTime(m_recTime);
    }
}

void VappFMRadioApp::onRecTimeTextUpdate(VfxTimer *source)
{
	recTimeUpdate();
}

MMI_BOOL VappFMRadioApp::errRecNmgrCallback(mmi_scenario_id scen_id, void *arg)
{
    VappFMRadioApp* app = (VappFMRadioApp*)VfxObject::handleToObject((VfxObjHandle)arg);

    if(app == NULL)
    {
        return MMI_FALSE;
    }

    vcp_global_popup_show_confirm_one_button_id(GRP_ID_ROOT, VCP_POPUP_TYPE_FAILURE, app->m_errRecStr, STR_GLOBAL_OK, VCP_POPUP_BUTTON_TYPE_NORMAL, NULL, NULL);

    return MMI_TRUE;
}


void VappFMRadioApp::recErrorPopup(VappFMRadioApp::VappFMRadioRecErr err, S32 fs_error)
{
    m_errRecStr = STR_GLOBAL_ERROR;

    if(err == REC_ERR_FS)
    {
        m_errRecStr = (VfxResId)srv_fmgr_fs_error_get_string(fs_error);
    }
    else if(err == REC_ERR_RUN_OUT_FILE_NAME)
    {
        m_errRecStr = STR_ID_VAPP_FM_REC_LIST_FULL;
    }
	else if(err == REC_ERR_MDI)
	{
		if(fs_error == MDI_AUDIO_FAIL)
		{
			m_errRecStr = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
		}
		else
		{
		    mmi_event_notify_enum popup_type;
		    m_errRecStr = (VfxResId)mdi_util_get_mdi_error_info((mdi_result)fs_error,&popup_type);
		}
	}

    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, &VappFMRadioApp::errRecNmgrCallback, getObjHandle());

}

VappFMRadioApp::VappFMRadioRecErr VappFMRadioApp::checkRecFolderPath(VfxWChar *folder_path, S32 *fs_error)
{
    S32 result;

    /* Check and create folder */
    if((result = srv_fmgr_fs_create_folder(folder_path)) < FS_NO_ERROR)
    {
        *fs_error = result;
        return REC_ERR_FS;
    }

    return REC_ERR_SUCCESS;

}

void VappFMRadioApp::onFindRecPathLoopTimeOut(VfxTimer *source)
{
    S32 fs_error;
    VappFMRadioRecErr result;
    mdi_result rec_result;

    result = findRecPathLoop(&fs_error);

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_FIND_RECPATHLOOP, result);
    
    switch(result)
    {
        case REC_ERR_SUCCESS:
        {
            m_mainPage->hideWaitingIcon();
            mdi_audio_rec_param_struct rec_param;

            if(m_quality == QUALITY_STANDARD)
            {
                mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, MDI_AUDIO_REC_QUALITY_LOW, &rec_param);
            }
            else
            {
                mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, MDI_AUDIO_REC_QUALITY_HIGH, &rec_param);
            }
			
			rec_result = mdi_fmr_start_record(m_recPath, rec_param.format, MDI_AUDIO_REC_QUALITY_AUTO);

            if (rec_result == MDI_AUDIO_SUCCESS)
            {
                setRecState(VADP_FM_RADIO_REC_ING, VFX_TRUE);
            }
            else
            {
                recErrorPopup(REC_ERR_MDI, rec_result);
                setRecState(VADP_FM_RADIO_REC_IDLE, VFX_FALSE);
            }

            break;
        }

        case REC_ERR_RUN_OUT_FILE_NAME:
        case REC_ERR_FS:
        {
            m_mainPage->hideWaitingIcon();
            recErrorPopup(result,fs_error);
            setRecState(VADP_FM_RADIO_REC_IDLE, VFX_FALSE);
            break;
        }

        case REC_ERR_LOOP:
        {
            m_pathLoopTimer->start();
            break;
        }
    }
 
}

VappFMRadioApp::VappFMRadioRecErr VappFMRadioApp::findRecPathLoop(S32 *fs_error)
{
    mdi_audio_rec_param_struct rec_param;
    VfxU8 drive;
    VfxU16 index = m_last_seq;
    VfxU16 stop_index;
    int ret;
 
    if(m_quality == QUALITY_STANDARD)
    {
        mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, MDI_AUDIO_REC_QUALITY_LOW, &rec_param);
    }
    else
    {
        mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, MDI_AUDIO_REC_QUALITY_HIGH, &rec_param);
    }
 
    if(m_storage == STORAGE_MEMORY_CARD)
    {
        drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
    }
    else
    {
        drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE);
    }

    if(m_last_seq > m_stop_seq)
    {
        if( (index + VAPP_FMRADIO_REC_FIND_RANGE - 1) <= VAPP_FMRADIO_REC_MAX_SEQUENCE)
        {
            stop_index = index + VAPP_FMRADIO_REC_FIND_RANGE - 1;
        }
        else
        {
            stop_index = VAPP_FMRADIO_REC_MAX_SEQUENCE;
        }
    }
    else
    {
        if( (index + VAPP_FMRADIO_REC_FIND_RANGE - 1) <= m_stop_seq)
        {
            stop_index = index + VAPP_FMRADIO_REC_FIND_RANGE - 1;
        }
        else 
        {
            stop_index = m_stop_seq;
        }
    }

    do
    {
        kal_wsprintf(m_recPath, "%c:\\%w%w%03d%w", drive, RECORD_DOWNLOAD_FOLDER_NAME, GetString(STR_ID_VAPP_FM_REC_PREFIX), index, rec_param.file_ext);

        /* Check if file exists */
		ret = FS_Open(m_recPath, FS_READ_ONLY);
        if(FS_FILE_NOT_FOUND == ret)
        {
            m_last_seq = index + 1;
            S16 error;
            WriteValue(NVRAM_VAPP_FMRDO_REC_SEQ, &m_last_seq, DS_SHORT, &error);
            return REC_ERR_SUCCESS;
        }
        else if(ret < FS_NO_ERROR)
        {
            /* Other file system error */
            *fs_error = ret;
            return REC_ERR_FS;
        }
        FS_Close(ret);
		index++;
    } while (index <= stop_index);

    m_last_seq = index;

    if(m_last_seq > VAPP_FMRADIO_REC_MAX_SEQUENCE)
    {
       m_last_seq = 1;
    }

    S16 error;
    WriteValue(NVRAM_VAPP_FMRDO_REC_SEQ, &m_last_seq, DS_SHORT, &error);

    if((index-1) == m_stop_seq)
    {
        return REC_ERR_RUN_OUT_FILE_NAME;
    }

    m_pathLoopTimer->start();

    return REC_ERR_LOOP;

}

VappFMRadioApp::VappFMRadioRecErr VappFMRadioApp::getRecFilePath(VfxWChar *filepath, S32 *fs_error)//, const VfxWChar *ext)
{
    VfxU16 index = 1;
    VfxU8 drive;
    VappFMRadioRecErr result;

    VfxWChar folder_path[VAPP_FMRADIO_REC_FOLDER_LEN + 1];

    if(m_storage == STORAGE_MEMORY_CARD)
    {
        drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
    }
    else
    {
        drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE);
    }
    kal_wsprintf(folder_path, "%c:\\%w", drive, RECORD_DOWNLOAD_FOLDER_NAME);

    /* check and create folder */
    result = checkRecFolderPath(folder_path, fs_error);

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_CHECK_RECFOLDERPATH, result);

    if(result != REC_ERR_SUCCESS)
    {
        return result;
    }

    /* Create File */
    /* Check if folder empty. if empty, reset the max file sequence */
    FMGR_FILTER filter;
    S16 error;

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AMR);

    if(srv_fmgr_fs_path_is_not_empty(folder_path, &filter) == 0)
    {
        /*folder empty*/
        WriteValue(NVRAM_VAPP_FMRDO_REC_SEQ, &index, DS_SHORT, &error);
    }
    else
    {
        /* Get lats max sequence number */
        ReadValue(NVRAM_VAPP_FMRDO_REC_SEQ, &index, DS_SHORT, &error);

        if(index > VAPP_FMRADIO_REC_MAX_SEQUENCE)
        {
            index = 1;
            WriteValue(NVRAM_VAPP_FMRDO_REC_SEQ, &index, DS_SHORT, &error);
        }
    }

    m_last_seq = index;

    if(m_last_seq == 1)
    {
        m_stop_seq = VAPP_FMRADIO_REC_MAX_SEQUENCE;
    }
    else
    {
        m_stop_seq = m_last_seq - 1;
    }

    result = findRecPathLoop(fs_error);

    return result; 

}

vapp_fm_radio_check_size_result VappFMRadioApp::getRecordDrvFreeSpace(void)
{
    VfxU8 drive_str[32];
    FS_DiskInfo diskinfo;
    VfxU8 drive;
	vapp_fm_radio_check_size_result result;
	result.disk_size = 0; result.remain_time = 0;

	if(m_storage == STORAGE_MEMORY_CARD)
    {
        drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
    }
    else
    {
        drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE);
    }

    kal_wsprintf((U16*) drive_str, "%c:\\", drive);

    result.ret = FS_GetDevStatus(drive, FS_FEATURE_STATE_ENUM);
    if (result.ret >= FS_NO_ERROR)
    {
        result.ret = FS_GetDiskInfo((U16*) drive_str, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
	    if (result.ret >= FS_NO_ERROR)
	    {
            result.disk_size = diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
	    }
    }

    return result;
}

vapp_fm_radio_check_size_result VappFMRadioApp::checkRecordRemainTime(void)
{
	VfxS32 record_rate;
	vapp_fm_radio_check_size_result result;

	
    /* Get record bitrate */
    mdi_audio_rec_param_struct rec_param;
	if(m_quality == QUALITY_STANDARD)
	{
		mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, MDI_AUDIO_REC_QUALITY_LOW, &rec_param);
	}
	else
	{
		mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, MDI_AUDIO_REC_QUALITY_HIGH, &rec_param);
	}

    record_rate = rec_param.byte_rate;
    
    /* Get disk size */
    result = getRecordDrvFreeSpace();

    /* Caculate remain time (in seconds) */
    if(record_rate > 0)
    {
        result.remain_time = (U64) (result.disk_size / record_rate);
    }

	return result;
}

void VappFMRadioApp::startRec(void)
{
    mdi_result rec_result;

    if(m_recState == VADP_FM_RADIO_REC_PAUSE)
    {
        rec_result = mdi_fmr_resume_record();

        if (rec_result == MDI_AUDIO_SUCCESS)
        {
            setRecState(VADP_FM_RADIO_REC_ING, VFX_FALSE);
        }
        else
        {
            recErrorPopup(REC_ERR_MDI, rec_result);
            setRecState(VADP_FM_RADIO_REC_IDLE, VFX_FALSE);
        }
    }
    else
    {
		vapp_fm_radio_check_size_result check_result;

		check_result = checkRecordRemainTime();

		if(check_result.remain_time == 0)
		{
			if(check_result.ret >= 0)
			{
				recErrorPopup(REC_ERR_MDI, MDI_AUDIO_DISC_FULL);
			}
			else
			{
				recErrorPopup(REC_ERR_FS, (S32)check_result.ret);
			}
			return;
		}
	
        S32 fs_error;
        VappFMRadioRecErr result = getRecFilePath(m_recPath, &fs_error);

		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_STARTREC_GETPATH, result);

        switch(result)
        {
            case REC_ERR_SUCCESS:
            {
                mdi_audio_rec_param_struct rec_param;

                if(m_quality == QUALITY_STANDARD)
                {
                    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, MDI_AUDIO_REC_QUALITY_LOW, &rec_param);
                }
                else
                {
                    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, MDI_AUDIO_REC_QUALITY_HIGH, &rec_param);
                }

				rec_result = mdi_fmr_start_record(m_recPath, rec_param.format, MDI_AUDIO_REC_QUALITY_AUTO);
				
				MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_STARTREC, rec_result);

                if (rec_result == MDI_AUDIO_SUCCESS)
                {
                    setRecState(VADP_FM_RADIO_REC_ING, VFX_TRUE);
                }
                else
                {
                    recErrorPopup(REC_ERR_MDI, rec_result);
                }
                break;
            }

            case REC_ERR_RUN_OUT_FILE_NAME:
            case REC_ERR_FS:
            {
                recErrorPopup(result,fs_error);
                break;
            }

            case REC_ERR_LOOP:
            {
                m_mainPage->showWaitingIcon();
                setRecState(VADP_FM_RADIO_REC_FIND_PATH, VFX_FALSE);
                break;
            }
        }

    }

    return;

}

void VappFMRadioApp::pauseRec(void)
{
    mdi_result rec_result = mdi_fmr_pause_record();
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_PAUSEREC, rec_result);

    if(rec_result == MDI_AUDIO_SUCCESS)
    {
        setRecState(VADP_FM_RADIO_REC_PAUSE, VFX_FALSE);
    }
    else
    {
        recErrorPopup(REC_ERR_MDI, rec_result);
        setRecState(VADP_FM_RADIO_REC_IDLE, VFX_FALSE);
    }

    return ;
}

void VappFMRadioApp::stopRec(VfxBool need_inform, VfxBool need_stop)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_STOPREC, m_recState);

	switch(m_recState)
	{
		case VADP_FM_RADIO_REC_FIND_PATH:
		{
			m_pathLoopTimer->stop();
			m_mainPage->hideWaitingIcon();
			setRecState(VADP_FM_RADIO_REC_IDLE, VFX_FALSE);
			break;
		}

		case VADP_FM_RADIO_REC_ING:
		case VADP_FM_RADIO_REC_PAUSE:
		{
			if(need_stop)
			{
	            mdi_fmr_stop_record();

	            if(need_inform)
	            {
	                VfxWString info;
	                info = VFX_WSTR_RES(STR_ID_VAPP_FM_REC_SAVED);
	                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
	            }
			}
			
            setRecState(VADP_FM_RADIO_REC_IDLE, VFX_FALSE);

            break;
		}

		case VADP_FM_RADIO_REC_SAVE:
		{
			saveRec();
			break;
		}

	}

}

void VappFMRadioApp::saveRec(void)
{
    setRecState(VADP_FM_RADIO_REC_IDLE, VFX_FALSE);
}

void VappFMRadioApp::cancelSaveRec(void)
{
    FS_Delete((const WCHAR * )m_recPath);
    setRecState(VADP_FM_RADIO_REC_IDLE, VFX_FALSE);
}

vadp_fm_radio_record_state_enum VappFMRadioApp::getRecState(void)
{
    return m_recState;
}

void VappFMRadioApp::setRecState(vadp_fm_radio_record_state_enum state, VfxBool is_start)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_SETREC_STATE, state);

    m_recStateChanged.emit(m_recState, state);

    m_recState = state;

	vadp_fm_radio_set_rec_state(state);

    switch(m_recState)
    {
        case VADP_FM_RADIO_REC_ING:
        {
            m_recTimer->start();
			if(is_start)
			{
				m_mainPage->updateRecTime(0);
			}
            break;
        }

        case VADP_FM_RADIO_REC_IDLE:
        {
            m_recTime = 0;
            m_recTimer->stop();
            m_mainPage->closeStopRecConfirms();
            break;
        }

        case VADP_FM_RADIO_REC_DISABLED:
        {
            m_recTime = 0;
            m_recTimer->stop();
            break;
        }

        case VADP_FM_RADIO_REC_SAVE:
        {
            m_mainPage->closeStopRecConfirms();
            break;
        }

        default:
        {
            m_recTimer->stop();
            break;
        }
    }

#ifdef __FM_RADIO_RDS_SUPPORT__
    if(m_recState == VADP_FM_RADIO_REC_IDLE || m_recState == VADP_FM_RADIO_REC_DISABLED)
    {
        enableAFTP();
    }
    else
    {
        disableAFTP();
    }
#endif

    m_mainPage->updateState();
}

VappFMRadioStorageEnum VappFMRadioApp::getStorage(void)
{
    return m_storage;
}

void VappFMRadioApp::setStorage(VappFMRadioStorageEnum storage)
{
    m_storage = storage;

    S16 error;
    WriteValue(NVRAM_VAPP_FMRDO_STORAGE, &m_storage, DS_BYTE, &error);
}

VappFMRadioApp::VappFMRadioQualityEnum VappFMRadioApp::getQuality(void)
{
    return m_quality;
}

void VappFMRadioApp::setQuality(VappFMRadioQualityEnum quality)
{
    m_quality = quality;

    S16 error;
    WriteValue(NVRAM_VAPP_FMRDO_QUALITY, &m_quality, DS_BYTE, &error);
}

#endif /*__MMI_FM_RADIO_RECORD__*/

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

/*
VfxWString VappFMRadioApp::getChannelName(void)
{
    VfxWString string;
    VfxBool isHidden = m_mainPage->m_info->m_channelBox->m_favName->getHidden();

    if(isHidden)
    {
        VfxFloat freq = ((VfxFloat)m_curFreq)/10;
        string.format("FM%.1f",freq);
    }
    else
    {
        string = m_mainPage->m_info->m_channelBox->m_favName->getString();
    }

    return string;
}
*/

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
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_SET_STATE, state);

	pureSetState(state);

    /*inform widget about state change*/
	//set state every time when state change
    vadp_fm_radio_update_state(state);
}

////never used
VfxU16 VappFMRadioApp::getPreFreq(void)
{
    return m_preFreq;
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

    m_preFreq = m_curFreq;

    m_curFreq = freq;

	vadp_fm_radio_set_cur_freq(freq);

    if(is_apply)
    {
		#ifdef __FM_RADIO_RDS_SUPPORT__
			resetRDS(VAPP_FMRADIO_RESET_ALL);
		#endif
		
        mdi_fmr_set_freq(m_curFreq);
    }

}

void VappFMRadioApp::setSeekFreq(VfxU16 freq, VfxBool is_apply)
{
    m_preFreq = m_curFreq;

    m_curFreq = freq;

    if(is_apply)
    {
	#ifdef __FM_RADIO_RDS_SUPPORT__
		resetRDS(VAPP_FMRADIO_RESET_ALL);
	#endif
    }

}

void VappFMRadioApp::setFreqHdlr(VfxTimer *source)
{
    VFX_UNUSED(source);

    mdi_fmr_set_freq(m_curFreq);

	#ifdef __FM_RADIO_RDS_SUPPORT__
		turnOnRDS();
	#endif
}

void VappFMRadioApp::delaySetFreq(void)
{
	#ifdef __FM_RADIO_RDS_SUPPORT__
		turnOffRDS();
	#endif
	
    m_delaySetFreqTimer->start();
}

#ifdef __MMI_FM_VIA_A2DP__
void VappFMRadioApp::connectA2dpBegin(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_CONNECT_A2DP_BEGIN);
	
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
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_CONNECT_A2DP_END);

	if(m_a2dpConnectTimer != NULL)
	{
		VFX_OBJ_CLOSE(m_a2dpConnectTimer);
	}
	
	m_mainPage->closeLoadingPopup();
}

void VappFMRadioApp::onConnectA2dpTimeout(VfxTimer *timer)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_ON_CONNECT_A2DP_TIMEOUT);

	if(m_a2dpConnectTimer != NULL)
	{
    	VFX_OBJ_CLOSE(m_a2dpConnectTimer);
	}

	if(vadp_fm_radio_is_connecting_a2dp())
	{
		m_mainPage->createLoadingPopup();
	}
}

#endif // __MMI_FM_VIA_A2DP__

#ifdef __MMI_AVRCP_SUPPORT__
VfxBool VappFMRadioApp::avrcpCmdCallback(VfxKeyEvent & event, VfxBool is_from_avrcp, void *user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_AVRCP_CMD_CALLBACK, event.keyCode);
	
	VappFMRadioApp* ptr = (VappFMRadioApp*)handleToObject((VfxObjHandle)user_data);
	if(ptr != NULL) 
	{
		return ptr->m_mainPage->processKeyEvent(event, is_from_avrcp);
	}

	return VFX_FALSE;
}
#endif // __MMI_AVRCP_SUPPORT__


/////////////////////////////////////////////////////////////////////////////////

VappFMRadioScreen::VappFMRadioScreen()
{}

void VappFMRadioScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    VappFMRadioMainPage *page;

    VFX_OBJ_CREATE(page, VappFMRadioMainPage, this);
    pushPage(0,page);

    VappFMRadioApp *app;
    app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFMRadioApp);
    
    app->m_mainPage = page;
}

void VappFMRadioScreen::on2ndReady()
{
	VappFMRadioApp* app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappFMRadioApp);

    //List Panel
    VFX_OBJ_CREATE(app->m_mainPage->m_list, VappFMRadioList, app->m_mainPage->m_pagePanel);
    app->m_mainPage->m_pagePanel->setCurrentFrame(app->m_mainPage->m_control);
}

void VappFMRadioScreen::onEnter(VfxBool isBackward)
{
	VappFMRadioApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappFMRadioApp);
	if (app == NULL)
    {
        return;
    }

#ifdef __FM_RADIO_RDS_SUPPORT__
	// If fm is truned on by widget / lock, then need to turn on RDS.
    if (app->getState() == VADP_FM_RADIO_POWER_ON)
    {
        app->turnOnRDS();
    }
#endif


#ifdef __MMI_AVRCP_SUPPORT__	
	#if defined(__MMI_NCENTER_SUPPORT__)
		// if Ncenter has entered, no need to register AVRCP 
		VappNCenter *ncenter =	VFX_OBJ_GET_INSTANCE(VappNCenter);
		if((ncenter != NULL) && ncenter->getNCenterEntered())
		{
			return;
		}
	#endif	
	vadp_fm_radio_register_avrcp_cmd_callback(&VappFMRadioApp::avrcpCmdCallback, app->getObjHandle(), VADP_FM_RADIO_APP);
#endif
}

void VappFMRadioScreen::onExited(VfxBool isBackward)
{
#ifdef __FM_RADIO_RDS_SUPPORT__
    VappFMRadioApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappFMRadioApp);
    if ((app != NULL) && (app->getState() == VADP_FM_RADIO_POWER_ON))
    {
        app->turnOffRDS();
    }
#endif

#ifdef __MMI_AVRCP_SUPPORT__
	vadp_fm_radio_deregister_avrcp_cmd_callback(VADP_FM_RADIO_APP);
#endif

    VfxMainScr::onExited(isBackward);
}


/////////////////////////////////////////////////////////////////////////////////
#ifdef __FM_RADIO_RDS_SUPPORT__

VappFMRadioRDSArea::VappFMRadioRDSArea():
    m_TP(NULL),
    m_AF(NULL),
    m_RDS(NULL)
{

}

void VappFMRadioRDSArea::onInit(void)
{
    VfxFrame::onInit();

    VfxU8 pos_x = 0;
    VfxU8 pos_y = 0;

    //TP
    VFX_OBJ_CREATE(m_TP, VfxTextFrame, this);
    m_TP->setPos(pos_x,pos_y);
    m_TP->setString(VFX_WSTR("TP"));
    m_TP->setColor(VFX_COLOR_BLACK);
    m_TP->setOpacity(0.5);
    m_TP->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(RDS_FONT_SIZE)));
    pos_x += m_TP->getSize().width;

    //spliter1
    pos_x += DISTANCE;
    VfxImageFrame *spliter1;
    VFX_OBJ_CREATE(spliter1, VfxImageFrame, this);
    spliter1->setPos(pos_x,pos_y);
    spliter1->setResId(IMG_ID_VAPP_FM_SPLITER);
    pos_x += spliter1->getSize().width;

    //AF
    pos_x += DISTANCE;
    VFX_OBJ_CREATE(m_AF, VfxTextFrame, this);
    m_AF->setPos(pos_x,pos_y);
    m_AF->setString(VFX_WSTR("AF"));
    m_AF->setColor(VFX_COLOR_BLACK);
    m_AF->setOpacity(0.5);
    m_AF->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(RDS_FONT_SIZE)));
    pos_x += m_AF->getSize().width;

    //spliter2
    pos_x += DISTANCE;
    VfxImageFrame *spliter2;
    VFX_OBJ_CREATE(spliter2, VfxImageFrame, this);
    spliter2->setPos(pos_x,pos_y);
    spliter2->setResId(IMG_ID_VAPP_FM_SPLITER);
    pos_x += spliter2->getSize().width;

    //RDS
    pos_x += DISTANCE;
    VFX_OBJ_CREATE(m_RDS, VfxTextFrame, this);
    m_RDS->setPos(pos_x,pos_y);
    m_RDS->setString(VFX_WSTR("RDS"));
    m_RDS->setColor(VFX_COLOR_BLACK);
    m_RDS->setOpacity(0.5);
    m_RDS->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(RDS_FONT_SIZE)));
    
}

void VappFMRadioRDSArea::setLight(VappFMRadioApp::VappFMRadioRDSTypes area, VfxBool turn_on)
{
    VfxFloat opacity = 0.5;

    if(turn_on)
    {
        opacity = 1;
    }
        
    switch(area)
    {
        case VappFMRadioApp::TYPE_RDS:
        {
            m_RDS->setOpacity(opacity);
            break;
        }

        case VappFMRadioApp::TYPE_AF:
        {
            m_AF->setOpacity(opacity);
            break;
        }

        case VappFMRadioApp::TYPE_TP:
        {
            m_TP->setOpacity(opacity);
            break;
        }

        case VappFMRadioApp::TYPE_ALL:
        {
            m_RDS->setOpacity(opacity);
            m_AF->setOpacity(opacity);
            m_TP->setOpacity(opacity);
            break;
        }

        default:
            break;

    }
}
#endif /*__FM_RADIO_RDS_SUPPORT__*/

/////////////////////////////////////////////////////////////////////////////////

VappFMRadioLPButton::VappFMRadioLPButton()
{}

VfxBool VappFMRadioLPButton::onPenInput(VfxPenEvent &event)
{
        switch(event.type)
        {
            case VFX_PEN_EVENT_TYPE_LONG_TAP:
            {
                m_buttonStatus.postEmit(this, getId(), VFX_PEN_EVENT_TYPE_LONG_TAP);
                return VFX_TRUE;
            }

            case VFX_PEN_EVENT_TYPE_DOWN:
            {
                m_buttonStatus.postEmit(this, getId(), VFX_PEN_EVENT_TYPE_DOWN);
                return VFX_TRUE;
            }

            case VFX_PEN_EVENT_TYPE_UP:
            {
                m_buttonStatus.postEmit(this, getId(), VFX_PEN_EVENT_TYPE_UP);
                return VFX_TRUE;
            }

            default:
                break;
        }

        return VcpImageButton::onPenInput(event);

}


/////////////////////////////////////////////////////////////////////////////////

VappFMRadioWheel::VappFMRadioWheel():
    m_app(NULL),
    m_wheelBar(NULL),
    m_timeline(NULL)
{}
 
void VappFMRadioWheel::onInit(void)
{
    VfxControl::onInit();

    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappFMRadioApp);

    //BG image
    VfxImageFrame* wheel;
    VFX_OBJ_CREATE(wheel,VfxImageFrame,this);
    wheel->setResId(IMG_ID_VAPP_FM_WHEEL);
    wheel->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    wheel->setPos(0,0);

    //wheel bar
    VFX_OBJ_CREATE(m_wheelBar,VfxImageFrame,this);
    m_wheelBar->setPos(BAR_X,BAR_Y);
    m_wheelBar->setPropertyEffectCallback(m_wheelBar,redrawWheelBarCallback,NULL,0);
    m_wheelBar->setBounds(0, getWheelBarCount(m_app->getFreq())*BAR_HEIGHT, BAR_WIDTH,BAR_HEIGHT);
    m_wheelBar->setPosZ(m_app->getFreq());

    VfxImageFrame *barBg;
    VFX_OBJ_CREATE(barBg,VfxImageFrame,m_wheelBar);
    barBg->setResId(IMG_ID_VAPP_FM_WHEEL_BAR);

    //timeline
    VFX_OBJ_CREATE(m_timeline,VfxFloatTimeline,this);
    m_timeline->setTarget(m_wheelBar);
    m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
    m_timeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    m_timeline->setStartDelay(0);
    m_timeline->setDurationTime(200);

    VfxImageFrame *shadowL;
    VFX_OBJ_CREATE(shadowL,VfxImageFrame,this);
    shadowL->setResId(IMG_ID_VAPP_FM_WHEEL_SHADOW);
    shadowL->setPos(SHADOW_X,SHADOW_Y);

    VfxTransform mirror(VFX_TRANSFORM_TYPE_MATRIX3X3);
    mirror.data.matrix3x3.m[0]= -1;
    mirror.data.matrix3x3.m[6]= SHADOW_WIDTH;

    VfxImageFrame *shadowR;
    VFX_OBJ_CREATE(shadowR,VfxImageFrame,this);
    shadowR->setResId(IMG_ID_VAPP_FM_WHEEL_SHADOW);
    shadowR->setPos(WHEEL_WIDTH - shadowR->getSize().width - SHADOW_X, SHADOW_Y);
    shadowR->setTransform(mirror);

}

vrt_render_dirty_type_enum VappFMRadioWheel::redrawWheelBarCallback(
                                                 vrt_frame_visual_property_struct *target_frame,
                                                 const vrt_frame_visual_property_struct *watch_frame,
                                                 void *user_data,
                                                 vrt_u32 user_data_size)
{
    VFX_UNUSED(watch_frame);
    VFX_UNUSED(user_data);
    VFX_UNUSED(user_data_size);

    target_frame->bounds = VfxRect(0, getWheelBarCount((VfxU16)vfxFloor(target_frame->pos_z))*BAR_HEIGHT, BAR_WIDTH,BAR_HEIGHT);

    return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
}


VfxU8 VappFMRadioWheel::getWheelBarCount(VfxU16 freq)
{
    VfxU8 count = 0;

    if(freq > m_centerFreq)
    {
        count = (BAR_NUM - (freq - m_centerFreq)%BAR_NUM)%BAR_NUM;
    }
    else
    {
        count = (m_centerFreq - freq)%BAR_NUM;
    }

    return count;
}

void VappFMRadioWheel::spinWheel(VfxS32 freq)
{
    m_timeline->setToValue(freq);
    m_timeline->start();

    m_wheelBar->setPosZ(freq);

}

/////////////////////////////////////////////////////////////////////////////////

VappFMRadioWheelArea::VappFMRadioWheelArea():
    m_app(NULL)
{}
 
void VappFMRadioWheelArea::onInit(void)
{
    VfxControl::onInit();

    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappFMRadioApp);
}

VfxBool VappFMRadioWheelArea::onPenInput(VfxPenEvent &event)
{
#ifdef __MMI_FM_RADIO_RECORD__
    if(m_app->m_mainPage->stopRecConfirm())
    {
        return VfxControl::onPenInput(event);
    }
#endif

    VfxPoint point = event.getRelPos(this);
    VfxBool  contains = this->containPoint(point);

    switch(event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            if(contains)
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


/////////////////////////////////////////////////////////////////////////////////

VappFMRadioTuner::VappFMRadioTuner():
    m_pin(NULL),
    m_interval(0),
    m_light(NULL),
    m_mark(NULL),
    m_low_freq(NULL),
    m_high_freq(NULL)
{}

void VappFMRadioTuner::onInit(void)
{
    VfxFrame::onInit();

    //BG image
    VfxImageFrame* bg_tuner;
    VFX_OBJ_CREATE(bg_tuner,VfxImageFrame,this);
    bg_tuner->setResId(IMG_ID_VAPP_FM_TUNER_BG);
    bg_tuner->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bg_tuner->setPos(0,0);
    bg_tuner->setSize(VappFMRadioControl::TUNER_WIDTH,VappFMRadioControl::TUNER_HEIGHT);

    //mark
    VFX_OBJ_CREATE(m_mark,VfxImageFrame,this);
    m_mark->setResId(IMG_ID_VAPP_FM_TUNER_MARK);
    m_mark->setPos(MARK_X,MARK_Y);

    m_interval = (VfxFloat)MARK_LENGTH / (VappFMRadioApp::MAX_FREQ - VappFMRadioApp::MIN_FREQ);

    //87.5mhz
    VFX_OBJ_CREATE(m_low_freq,VfxTextFrame,this);
    m_low_freq->setPos(MARK_X, MARK_Y+MARK_TO_FREQ);
    m_low_freq->setString(VFX_WSTR("87.5MHz"));
    m_low_freq->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FREQ_FONT_SIZE)));

    //108mhz
    VFX_OBJ_CREATE(m_high_freq,VfxTextFrame,this);
    m_high_freq->setAnchor(1,0);
    m_high_freq->setPos(MARK_X + m_mark->getSize().width, MARK_Y+MARK_TO_FREQ);
    m_high_freq->setString(VFX_WSTR("108MHz"));
    m_high_freq->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FREQ_FONT_SIZE)));

    //light
    VFX_OBJ_CREATE(m_light,VfxImageFrame,this);
    m_light->setResId(IMG_ID_VAPP_FM_TUNER_LIGHT);
    m_light->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_light->setPos(0,0);
    m_light->setSize(VappFMRadioControl::TUNER_WIDTH,VappFMRadioControl::TUNER_HEIGHT);

    //pin
    VFX_OBJ_CREATE(m_pin,VfxImageFrame,this);
    m_pin->setResId(IMG_ID_VAPP_FM_TUNER_PIN);

}


void VappFMRadioTuner::setLight(VfxBool turn_on)
{
    m_light->setHidden(!turn_on);

    if(turn_on)
    {
        m_mark->setOpacity(1.0);
        m_low_freq->setOpacity(1.0);
        m_high_freq->setOpacity(1.0);
    }
    else
    {
        m_mark->setOpacity(0.2);
        m_low_freq->setOpacity(0.2);
        m_high_freq->setOpacity(0.2);
    }
}

void VappFMRadioTuner::setPin(VfxU16 freq)
{
    VfxS32 pinX = MARK_X + (VfxS32)((freq- VappFMRadioApp::MIN_FREQ)*m_interval + 0.5) ;
    //m_pinX = 40;
    m_pin->setPos(pinX,0);
}

/////////////////////////////////////////////////////////////////////////////////

VappFMRadioControl::VappFMRadioControl():
    m_btnSpeaker(NULL),
#ifdef __FM_RADIO_RDS_SUPPORT__
    m_RDSArea(NULL),
#endif
    m_btnFav(NULL),
    m_tuner(NULL),
    m_btnArrowL(NULL),
    m_wheel(NULL),
    m_btnArrowR(NULL),
    m_btnPower(NULL),
#ifdef __MMI_FM_RADIO_RECORD__
    m_btnRrecStart(NULL),
    m_btnRecStop(NULL),
#endif
#if defined(__MMI_FM_RADIO_RECORD__) || defined(__FM_RADIO_RDS_SUPPORT__)
    m_btnSetting(NULL),
#endif
    m_btnList(NULL)
{}

void VappFMRadioControl::onInit(void)
{
    VfxControl::onInit();

    setPos(0,0);
    setSize(VappFMRadioMainPage::PANEL_WIDTH,VappFMRadioMainPage::PANEL_HEIGHT);

    //BG image
    VfxImageFrame* bg_bottom;
    VFX_OBJ_CREATE(bg_bottom,VfxImageFrame,this);
    bg_bottom->setResId(IMG_ID_VAPP_FM_BG_BOTTOM);
    bg_bottom->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bg_bottom->setRect(0,0, getSize().width, getSize().height);

    //headset button
    VFX_OBJ_CREATE(m_btnSpeaker, VcpImageButton, this);
    m_btnSpeaker->setPos(HEADSET_X, HEADSET_Y);
    m_btnSpeaker->setSize(HEADSET_WIDTH, HEADSET_HEIGHT);
    m_btnSpeaker->setId(VappFMRadioMainPage::BTN_SPEAKER);
    updateSpeakerBtn(vadp_fm_radio_get_aud_path());


    //RDSArea
#ifdef __FM_RADIO_RDS_SUPPORT__
    VFX_OBJ_CREATE(m_RDSArea, VappFMRadioRDSArea, this);
    m_RDSArea->setPos(RDS_BOX_X,RDS_BOX_Y);
    m_RDSArea->setSize(RDS_BOX_WIDTH,RDS_BOX_HEIGHT);
#endif

    //favoriate button
    VFX_OBJ_CREATE(m_btnFav, VcpImageButton, this);
    m_btnFav->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_FAV,0,0,0));
    m_btnFav->setPos(FAV_X, FAV_Y);
    m_btnFav->setSize(FAV_WIDTH, FAV_HEIGHT);
    m_btnFav->setId(VappFMRadioMainPage::BTN_FAV);

    //tuner
    VFX_OBJ_CREATE(m_tuner, VappFMRadioTuner, this);
    m_tuner->setPos(TUNER_X,TUNER_Y);
    m_tuner->setSize(TUNER_WIDTH,TUNER_HEIGHT);

    //arrow L
    VFX_OBJ_CREATE(m_btnArrowL,VappFMRadioLPButton,this);
    m_btnArrowL->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_ARROW_L));
    m_btnArrowL->setId(VappFMRadioMainPage::BTN_ARROWL);
    m_btnArrowL->setPos(ARROW_L_X, ARROW_L_Y);
    m_btnArrowL->setSize(ARROW_WIDTH, ARROW_HEIGHT);

    //wheel
    VFX_OBJ_CREATE(m_wheel,VappFMRadioWheel,this);
    m_wheel->setPos(WHEEL_X,WHEEL_Y);
    m_wheel->setSize(WHEEL_WIDTH,WHEEL_HEIGHT);

    //wheel area
    VFX_OBJ_CREATE(m_wheelArea,VappFMRadioWheelArea,this);
    m_wheelArea->setPos(WHEEL_X,WHEEL_Y-WHEEL_HEIGHT_EXPAND);
    m_wheelArea->setSize(WHEEL_WIDTH,WHEEL_HEIGHT+ 2*WHEEL_HEIGHT_EXPAND);

    //arrow R
    VFX_OBJ_CREATE(m_btnArrowR,VappFMRadioLPButton,this);
    m_btnArrowR->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_ARROW_R));
    m_btnArrowR->setId(VappFMRadioMainPage::BTN_ARROWR);
    m_btnArrowR->setPos(ARROW_R_X, ARROW_R_Y);
    m_btnArrowR->setSize(ARROW_WIDTH, ARROW_HEIGHT);

    //hole
    VfxImageFrame* hole;
    VFX_OBJ_CREATE(hole,VfxImageFrame,this);
    hole->setResId(IMG_ID_VAPP_FM_HOLE);
    hole->setPos(HOLE_X,HOLE_Y);
#ifdef __LOW_COST_SUPPORT_COMMON__
    hole->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    hole->setRect(HOLE_X, HOLE_Y, HOLE_WIDTH, HOLE_HEIGHT);
#endif

    //power button
    VFX_OBJ_CREATE(m_btnPower, VcpButton, this);
    m_btnPower->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_POWER_OFF,0,0,0));
	m_btnPower->setBgImageList(VcpStateImage(IMG_ID_VAPP_FM_BTN_POWER_N,IMG_ID_VAPP_FM_BTN_POWER_P,0,0));
	m_btnPower->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnPower->setMargin(0,0,0,0);
	m_btnPower->setPos(POWER_X, POWER_Y);
    m_btnPower->setSize(POWER_WIDTH, POWER_HEIGHT);
    m_btnPower->setId(VappFMRadioMainPage::BTN_POWER);
	m_btnPower->setFuzzy(VFX_FALSE);

#ifdef __MMI_FM_RADIO_RECORD__
    //record start button
    VFX_OBJ_CREATE(m_btnRrecStart, VcpButton, this);
    m_btnRrecStart->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC_D,0));
    m_btnRrecStart->setBgImageList(VcpStateImage(IMG_ID_VAPP_FM_BTN_BG_N,IMG_ID_VAPP_FM_BTN_BG_P,IMG_ID_VAPP_FM_BTN_BG_N,0));
	m_btnRrecStart->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnRrecStart->setMargin(0,0,0,0);
	m_btnRrecStart->setPos(REC_START_X, REC_START_Y);
    m_btnRrecStart->setSize(REC_START_WIDTH, REC_START_HEIGHT);
    m_btnRrecStart->setId(VappFMRadioMainPage::BTN_REC_START);

    //record stop button
    VFX_OBJ_CREATE(m_btnRecStop, VcpButton, this);
    m_btnRecStop->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_STOP,IMG_ID_VAPP_FM_BTN_STOP,0,0));
    m_btnRecStop->setBgImageList(VcpStateImage(IMG_ID_VAPP_FM_BTN_BG_N,IMG_ID_VAPP_FM_BTN_BG_P,0,0));
	m_btnRecStop->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnRecStop->setMargin(0,0,0,0);
	m_btnRecStop->setPos(REC_STOP_X, REC_STOP_Y);
    m_btnRecStop->setSize(REC_STOP_WIDTH, REC_STOP_HEIGHT);
    m_btnRecStop->setId(VappFMRadioMainPage::BTN_REC_STOP);

    //record time
    VFX_OBJ_CREATE(m_recTimeText, VfxTextFrame, this);
    m_recTimeText->setPos(REC_TIME_X, REC_TIME_Y);
    m_recTimeText->setSize(REC_TIME_WIDTH, REC_TIME_HEIGHT);
    //m_recTimeText->setString(VFX_WSTR("01:13:26"));
    m_recTimeText->setColor(VFX_COLOR_WHITE);
    m_recTimeText->setAutoResized(VFX_FALSE);
    m_recTimeText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    VfxFontDesc font;
    font.attr |= VFX_FONT_DESC_ATTR_MONOSPACE;
    font.size = VFX_FONT_DESC_VF_SIZE(REC_TIME_FONT_SIZE);
    m_recTimeText->setFont(font);
    //m_recTimeText->setFont(VfxFontDesc());
    updateRecTimeText(0);
#endif
    
    //list button
    VFX_OBJ_CREATE(m_btnList, VcpButton, this);
    m_btnList->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_LIST,IMG_ID_VAPP_FM_BTN_LIST,0,0));
    m_btnList->setBgImageList(VcpStateImage(IMG_ID_VAPP_FM_BTN_BG_N,IMG_ID_VAPP_FM_BTN_BG_P,0,0));
	m_btnList->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnList->setMargin(0,0,0,0);
	m_btnList->setPos(LIST_X, LIST_Y);
    m_btnList->setSize(LIST_WIDTH, LIST_HEIGHT);
    m_btnList->setId(VappFMRadioMainPage::BTN_LIST);

    //stting button
#if defined(__MMI_FM_RADIO_RECORD__) || defined(__FM_RADIO_RDS_SUPPORT__)
    VFX_OBJ_CREATE(m_btnSetting, VcpButton, this);
    m_btnSetting->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_SETTING,IMG_ID_VAPP_FM_BTN_SETTING,0,0));
    m_btnSetting->setBgImageList(VcpStateImage(IMG_ID_VAPP_FM_BTN_BG_N,IMG_ID_VAPP_FM_BTN_BG_P,0,0));
	m_btnSetting->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnSetting->setMargin(0,0,0,0);
	m_btnSetting->setPos(SETTING_X, SETTING_Y);
    m_btnSetting->setSize(SETTING_WIDTH, SETTING_HEIGHT);
    m_btnSetting->setId(VappFMRadioMainPage::BTN_SETTING);
#endif

	setBtnHaloEffect();
}

void VappFMRadioControl::setBtnHaloEffect()
{	
	const VfxFloat HALO_EFFECT_RATIO = 1.5f; 

	m_btnSpeaker->setIsEffect(VFX_TRUE);
    m_btnSpeaker->setEffectRatio(HALO_EFFECT_RATIO);
	
	m_btnFav->setIsEffect(VFX_TRUE);
    m_btnFav->setEffectRatio(HALO_EFFECT_RATIO);
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
	// Show btnHeadset only in the case of earphone is plug in.	
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

#ifdef __MMI_FM_RADIO_RECORD__
void VappFMRadioControl::updateRecTimeText(VfxU32 time)
{
    VfxWChar str_buf[12];
    VfxU32 hour, minute, second;

    time = time / 1000;

    hour = time / 3600;
    minute = (time %3600)/60;
    second = (time %3600)%60;

    kal_wsprintf(str_buf, "%02d:%02d:%02d", hour, minute, second);

    m_recTimeText->setString(VFX_WSTR_MEM(str_buf));
}
#endif

/////////////////////////////////////////////////////////////////////////////////

void VappFMRadioListTabItem::onInit(void)
{
	VfxControl::onInit();

    //icon
    VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
    //text
    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);

}

VfxBool VappFMRadioListTabItem::onPenInput(VfxPenEvent & event)
{

    if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_signalChoose.postEmit(m_id);
        return VFX_TRUE;
    }

    return VFX_TRUE;
}

//void VappFMRadioListTabItem::setChoose(VfxBool choose)
//{
//    if(choose)
//    {
//        m_choosen = VFX_TRUE;
//        this->setImgContent(VfxImageSrc(IMG_ID_VAPP_FM_TAB_SELECTED));
//    }
//    else
//    {
//        m_choosen = VFX_FALSE;
//        this->setImgContent(VfxImageSrc(IMG_ID_VAPP_FM_TAB_UNSELECTED));
//    }
//}

/////////////////////////////////////////////////////////////////////////////////

VappFMRadioListTab::VappFMRadioListTab():
    m_bg(NULL),
    m_auto(NULL),
    m_fav(NULL)
{}

void VappFMRadioListTab::onInit(void)
{
	VfxFrame::onInit();

    VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
    m_bg->setPos(0,0);

    //auto search tab
    VFX_OBJ_CREATE(m_auto, VappFMRadioListTabItem, this);
    m_auto->setSize(AUTO_WIDTH, AUTO_HEIGHT);
    m_auto->setPos(AUTO_X,AUTO_Y);
    m_auto->m_icon->setResId(IMG_ID_VAPP_FM_ICON_AUTO_SEARCH);
    m_auto->m_icon->setAnchor(0,0.5);
    m_auto->m_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE)));
    m_auto->m_text->setString(VFX_WSTR_RES(STR_ID_VAPP_FM_AUTO_SEARCH));
    m_auto->m_text->setColor(VfxColor(255,21,21,21));
    m_auto->m_text->setAnchor(0,0.5);
    m_auto->m_id = VappFMRadioList::AUTO_SEARCH;
//    m_auto->m_signalChoose.connect(this,&VappFMRadioList::onTabChoose);

    VfxS16 w1 = m_auto->m_icon->getSize().width ;
    VfxS16 w2 = m_auto->m_text->getSize().width ;
    VfxS16 W = (w1 + VappFMRadioListTabItem::TEXT_X_GAP + w2)/2;

	if(W*2 > TEXT_LEN)
	{
		w2 = TEXT_LEN - w1 - VappFMRadioListTabItem::TEXT_X_GAP;
		m_auto->m_text->setSize(w2, AUTO_HEIGHT);
		m_auto->m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		m_auto->m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
		W = (w1 + VappFMRadioListTabItem::TEXT_X_GAP + w2)/2;
	}

    VfxS16 icon_x = (AUTO_WIDTH)/2 - W;
    VfxS16 text_x = icon_x + w1 + VappFMRadioListTabItem::TEXT_X_GAP;

    m_auto->m_icon->setPos(icon_x,AUTO_HEIGHT/2);
    m_auto->m_text->setPos(text_x,AUTO_HEIGHT/2);

    //fav tab
    VFX_OBJ_CREATE(m_fav, VappFMRadioListTabItem, this);
    m_fav->setSize(FAV_WIDTH, FAV_HEIGHT);
    m_fav->setPos(FAV_X,FAV_Y);
    m_fav->m_icon->setResId(IMG_ID_VAPP_FM_ICON_FAV);
    m_fav->m_icon->setAnchor(0,0.5);
    m_fav->m_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE)));
    m_fav->m_text->setString(VFX_WSTR_RES(STR_ID_VAPP_FM_FAV));
    m_fav->m_text->setColor(VfxColor(255,21,21,21));
    m_fav->m_text->setAnchor(0,0.5);
    m_fav->m_id = VappFMRadioList::FAVORITE;
//    m_fav->m_signalChoose.connect(this,&VappFMRadioList::onTabChoose);

    w1 = m_fav->m_icon->getSize().width ;
    w2 = m_fav->m_text->getSize().width ;
    W = (w1 + VappFMRadioListTabItem::TEXT_X_GAP + w2)/2;

	if(W*2 > TEXT_LEN)
	{
		w2 = TEXT_LEN - w1 - VappFMRadioListTabItem::TEXT_X_GAP;
		m_fav->m_text->setSize(w2, FAV_HEIGHT);
		m_fav->m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		m_fav->m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
		W = (w1 + VappFMRadioListTabItem::TEXT_X_GAP + w2)/2;
	}
	 
    icon_x = (FAV_WIDTH)/2 - W;
    text_x = icon_x + w1 + VappFMRadioListTabItem::TEXT_X_GAP;

    m_fav->m_icon->setPos(icon_x,FAV_HEIGHT/2);
    m_fav->m_text->setPos(text_x,FAV_HEIGHT/2);

}

void VappFMRadioListTab::setChoose(VappFMRadioList::VappFMRadioTabMode tab)
{
    VfxTransform mirror(VFX_TRANSFORM_TYPE_MATRIX3X3);

    if(tab == VappFMRadioList::AUTO_SEARCH)
    {
        mirror.data.matrix3x3.m[0]= 1;
        mirror.data.matrix3x3.m[6]= 0;
        m_bg->setTransform(mirror);
        m_bg->setResId(IMG_ID_VAPP_FM_LIST_BG_TAB);
    }
    else
    {
        mirror.data.matrix3x3.m[0]= -1;
        mirror.data.matrix3x3.m[6]= LCD_WIDTH;
        m_bg->setTransform(mirror);
        m_bg->setResId(IMG_ID_VAPP_FM_LIST_BG_TAB);
    }

}

/////////////////////////////////////////////////////////////////////////////////

void VappFMRadioAutoMgr::onInit(void)
{
	VfxObject::onInit();

	updateFreq(m_total, m_freq);
}

void VappFMRadioAutoMgr::updateFreq(VfxU8 total, nvram_ef_vapp_fmrdo_auto_list_struct freq)
{
    S16 error;

    ReadValue(NVRAM_VAPP_FMRDO_AUTO_LIST_NUM, &m_total, DS_BYTE, &error);

    //m_total = 10;

    //for(VfxU8 i=0; i<VAPP_FM_RADIO_AUTO_LIST_NUM; i++)
    //{	
        ReadRecord(NVRAM_EF_VAPP_FMRDO_AUTO_LIST_LID, 1, &m_freq, sizeof(nvram_ef_vapp_fmrdo_auto_list_struct), &error);
        //ReadMultiRecord(NVRAM_EF_VAPP_FMRDO_AUTO_LIST_LID, 1, &m_freq[0], sizeof(U16)*VAPP_FM_RADIO_AUTO_LIST_NUM, VAPP_FM_RADIO_AUTO_LIST_NUM, &error);
        //m_freq[i] = 900 + i*5;
    //}
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


/////////////////////////////////////////////////////////////////////////////////

VappFMRadioListAuto* VappFMRadioListAuto::m_self = NULL;

VappFMRadioListAuto::VappFMRadioListAuto():
    m_app(NULL),
	m_btnSearch(NULL),
    m_startCnf(NULL),
    m_list(NULL),
    m_waiting(NULL),
    m_autoMgr(NULL)
{}

void VappFMRadioListAuto::onInit(void)
{
    VfxFrame::onInit();

    m_self = this;

    //auto list
    VFX_OBJ_CREATE(m_list, VcpListMenu, this);

    m_list->setPos(VappFMRadioList::LIST_X,VappFMRadioList::LIST_Y);
    m_list->setSize(VappFMRadioList::LIST_WIDTH,VappFMRadioList::LIST_HEIGHT);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT); 
    m_list->setMenuMode(VCP_LIST_MENU_MODE_NORMAL,VFX_FALSE);
    m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    m_list->setBgColor(VfxColor(255,223,223,223));
    m_list->setContentProvider(this);
    m_list->m_signalItemTapped.connect(this,&VappFMRadioListAuto::onItemTapped);

    //auto mgr
    VFX_OBJ_CREATE(m_autoMgr, VappFMRadioAutoMgr, this);
    
    //bottom bg
    VfxImageFrame *bg;
    VFX_OBJ_CREATE(bg, VfxImageFrame, this);
    bg->setResId(IMG_ID_VAPP_FM_LIST_BG_BOTTOM);
    bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bg->setPos(VappFMRadioList::BOTTOM_X,VappFMRadioList::BOTTOM_Y);
    bg->setSize(VappFMRadioList::BOTTOM_WIDTH,VappFMRadioList::BOTTOM_HEIGHT);

    //btn auto search
    VFX_OBJ_CREATE(m_btnSearch, VcpButton, this);
    m_btnSearch->setText(VFX_WSTR_RES(STR_ID_VAPP_FM_AUTO_SEARCH));
    m_btnSearch->setPos(AUTO_X,AUTO_Y);
    m_btnSearch->setSize(AUTO_WIDTH,AUTO_HEIGHT);
    m_btnSearch->m_signalClicked.connect(this,&VappFMRadioListAuto::onButtonClicked);

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
    #ifdef __MMI_FM_RADIO_RECORD__
        if(m_app->m_mainPage->stopRecConfirm(m_autoMgr->getFreq((VfxU8)index)))
        {
            return;
        }
        else
    #endif
        {
            m_app->setFreq(m_autoMgr->getFreq((VfxU8)index),VFX_TRUE);
            m_app->m_mainPage->updateFreq(VFX_FALSE);
            m_list->updateAllItems();
        }
    }
}

/*
void VappFMRadioListAuto::closeAutoList(void)
{
    if(m_startCnf != NULL)
    {
        VFX_OBJ_CLOSE(m_startCnf);
    }
}
*/

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

#ifdef __FM_RADIO_RDS_SUPPORT__
    m_app->turnOffRDS();
#endif

	vadp_fm_radio_scan();

    m_app->setState(VADP_FM_RADIO_SCANING);

}

void VappFMRadioListAuto::abortAutoScan(void)
{
    mdi_fmr_scan_abort();

    m_app->setState(VADP_FM_RADIO_POWER_ON);

#ifdef __FM_RADIO_RDS_SUPPORT__
    m_app->turnOnRDS();
#endif

#if defined(__MMI_BT_FM_VIA_SCO__)
    mdi_audio_bt_hfp_turn_on();
#endif

    mdi_fmr_set_freq(m_app->getFreq());
    mdi_audio_set_volume(MDI_VOLUME_FMR, srv_prof_get_media_vol());

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

        #ifdef __MMI_FM_RADIO_RECORD__
            if(m_app->getRecState() != VADP_FM_RADIO_REC_IDLE)
            {
                m_app->stopRec(VFX_TRUE, VFX_TRUE);
            }
        #endif

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

    #ifdef __MMI_FM_RADIO_RECORD__
        if(m_app->getRecState() != VADP_FM_RADIO_REC_IDLE && m_app->getRecState() != VADP_FM_RADIO_REC_DISABLED)
        {
            m_startCnf->setText(VFX_WSTR_RES(STR_ID_VAPP_FM_AUTO_SEARCH_REC_Q));
        }
        else
    #endif
        {
            m_startCnf->setText(VFX_WSTR_RES(STR_ID_VAPP_FM_AUTO_SEARCH_Q));
        }
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
    	frame->setColor(VfxColor(255,0,160,187));
        return VFX_TRUE;
    }
 
    /*For different theme, the un-focused item shall follow FM radio's color, but the hilighted itme shall use theme color*/
    if (m_list->getFocusItemIndex() != index)
    {
        switch(fieldType)
        {
            case VCP_LIST_MENU_FIELD_TEXT:
                frame->setColor(VfxColor(255, 15, 15, 15));
                break;
            default:
                return VFX_FALSE;
        }
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
        VfxFloat freq = ((VfxFloat)m_autoMgr->getFreq((VfxU8)index))/10;

        text.format("FM %.1f",freq);
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappFMRadioListAuto::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
{
    text = VFX_WSTR_RES(STR_ID_VAPP_FM_AUTO_LIST_EMPTY);
    return VFX_TRUE;
}

/////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////

VappFMRadioListFav::VappFMRadioListFav():
    m_app(NULL),
    m_edit(NULL),
    m_addFav(NULL),
    m_favMgr(NULL),
    m_btnL(NULL),
    m_btnR(NULL),
	m_mode(VappFMRadioListFav::ADD_MODE),
	m_tappedIdx(-1),
    m_deleteCnf(NULL),
    m_list(NULL)
{}

void VappFMRadioListFav::onInit(void)
{
    VfxFrame::onInit();

    //fav list
    VFX_OBJ_CREATE(m_list, VcpListMenu, this);

    m_list->setPos(VappFMRadioList::LIST_X,VappFMRadioList::LIST_Y);
    m_list->setSize(VappFMRadioList::LIST_WIDTH,VappFMRadioList::LIST_HEIGHT);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT); 
    m_list->setMenuMode(VCP_LIST_MENU_MODE_NORMAL,VFX_TRUE);
    m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON,VFX_FALSE);
    m_list->setBgColor(VfxColor(255,223,223,223));
    m_list->setContentProvider(this);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappFMRadioListFav::onSelectedChanged);
    m_list->m_signalCmdButtonClicked.connect(this, &VappFMRadioListFav::onEditButtonClicked);
    m_list->m_signalItemTapped.connect(this,&VappFMRadioListFav::onItemTapped);

    //fav list
    VFX_OBJ_CREATE(m_favMgr, VappFMRadioFavMgr, this);

    m_favMgr->m_favListUpdated.connect(this,&VappFMRadioListFav::updateListMenu);

    for(VfxU8 i =0 ; i<VAPP_FM_RADIO_FAV_LIST_NUM ; i++)
    {
        m_select[i] = VFX_FALSE;
    }
    m_select_total = 0;

    //bottom bg
    VfxImageFrame *bg;
    VFX_OBJ_CREATE(bg, VfxImageFrame, this);
    bg->setResId(IMG_ID_VAPP_FM_LIST_BG_BOTTOM);
    bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bg->setPos(VappFMRadioList::BOTTOM_X,VappFMRadioList::BOTTOM_Y);
    bg->setSize(VappFMRadioList::BOTTOM_WIDTH,VappFMRadioList::BOTTOM_HEIGHT);

    //btn add
    VFX_OBJ_CREATE(m_btnL, VcpButton, this);
    m_btnL->setText(VFX_WSTR_RES(STR_GLOBAL_ADD));
    m_btnL->setPos(LEFT_BTN_X,LEFT_BTN_Y);
    m_btnL->setSize(BTN_WIDTH,BTN_HEIGHT);
    m_btnL->m_signalClicked.connect(this,&VappFMRadioListFav::onButtonClicked);

    //btn delete
    VFX_OBJ_CREATE(m_btnR, VcpButton, this);
    m_btnR->setText(VFX_WSTR_RES(STR_GLOBAL_DELETE));
    m_btnR->setPos(RIGHT_BTN_X,RIGHT_BTN_Y);
    m_btnR->setSize(BTN_WIDTH,BTN_HEIGHT);
    m_btnR->m_signalClicked.connect(this,&VappFMRadioListFav::onButtonClicked);

    updateButton();

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
    #ifdef __MMI_FM_RADIO_RECORD__
        if(m_app->m_mainPage->stopRecConfirm(m_favMgr->getFreq(idx)))
        {
            return;
        }
        else
    #endif
        {
            m_app->setFreq(m_favMgr->getFreq(idx), VFX_TRUE);
            m_tappedIdx = idx;
            m_app->m_mainPage->updateFreq(VFX_TRUE);
            m_tappedIdx = -1;
            m_list->updateAllItems();
        }
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
       (fieldType == VCP_LIST_MENU_FIELD_TEXT))
    {
        frame->setColor(VfxColor(255,0,160,187));
        return VFX_TRUE;
    }

    /*For different theme, the un-focused item shall follow FM radio's color, but the hilighted itme shall use theme color*/
    if (m_list->getFocusItemIndex() != index)
    {
        switch(fieldType)
        {
            case VCP_LIST_MENU_FIELD_TEXT:
                frame->setColor(VfxColor(255, 15, 15, 15));
                break;
            case VCP_LIST_MENU_FIELD_SUB_TEXT1:
                frame->setColor(VfxColor(255, 144, 144, 144));
                break;
            default:
                return VFX_FALSE;
        }
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
            VfxFloat freq = ((VfxFloat)m_favMgr->getFreq(idx))/10;
            text.format("FM %.1f",freq);
        }        
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        VfxWChar* name = m_favMgr->getName(idx);
        if(name[0] != 0x00)
        {
            VfxFloat freq = ((VfxFloat)m_favMgr->getFreq(idx))/10;
            text.format("FM %.1f", freq);
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
    freq.format("%.1f",(VfxFloat)m_favMgr->getFreq(idx)/10);

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
        case BTN_ADD:
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

        case BTN_DELETE:
        {
            m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT); 
            m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION,VFX_TRUE);
            m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);

            m_mode = DELETE_MODE;

            updateButton();

            break;
        }

        case BTN_DELETE2:
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

        case BTN_CANCEL:
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
    if(m_mode == ADD_MODE)
    {
        m_btnL->setId(BTN_ADD);
        m_btnL->setText(VFX_WSTR_RES(STR_GLOBAL_ADD));

        m_btnR->setId(BTN_DELETE);
        m_btnR->setText(VFX_WSTR_RES(STR_GLOBAL_DELETE));

        if(m_favMgr->getTotal() == 0)
        {
            m_btnR->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_btnR->setIsDisabled(VFX_FALSE);
        }

        if(m_favMgr->getTotal() == VAPP_FM_RADIO_AUTO_LIST_NUM)
        {
            m_btnL->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_btnL->setIsDisabled(VFX_FALSE);
        }

    }
    else
    {
        m_btnL->setId(BTN_DELETE2);
        m_btnL->setText(VFX_WSTR_RES(STR_GLOBAL_DELETE));

        m_btnR->setId(BTN_CANCEL);
        m_btnR->setText(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
        m_btnR->setIsDisabled(VFX_FALSE);

        if(m_select_total >0)
        {
            m_btnL->setIsDisabled(VFX_FALSE);
        }
        else
        {
            m_btnL->setIsDisabled(VFX_TRUE);
        }
    }
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

/*
VfxBool VappFMRadioListFav::checkFavList(VfxU16 freq)
{
    for(VfxU8 i=0; i<m_favMgr->m_total; i++)
    {
        if(m_favMgr->m_data.item[i].fav_freq == freq)
        {
            return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}
*/

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

/*
void VappFMRadioListFav::closeFavList(void)
{
    if(m_mode == DELETE_MODE)
    {
        cancelDelete();
    }

    if(m_edit != NULL)
    {
        VFX_OBJ_CLOSE(m_edit);
    }

    if(m_addFav != NULL)
    {
        VFX_OBJ_CLOSE(m_addFav);
    }

    if(m_deleteCnf != NULL)
    {
        VFX_OBJ_CLOSE(m_deleteCnf);
    }

}
*/

VfxBool VappFMRadioListFav::onBackKey(void)
{
    if(m_mode != DELETE_MODE)
    {
        return VFX_FALSE;
    }

    cancelDelete();

    return VFX_TRUE;
}


/////////////////////////////////////////////////////////////////////////////////

VappFMRadioList::VappFMRadioList():
    m_pagePanel(NULL),
    m_tabChoose(FAVORITE),
    m_autoList(NULL),
    m_favList(NULL)
{
}

void VappFMRadioList::onInit(void)
{
	VfxControl::onInit();

    setPos(0,0);
    setSize(VappFMRadioMainPage::PANEL_WIDTH,VappFMRadioMainPage::PANEL_HEIGHT);

    //setBgColor(VFX_COLOR_AQUA);

    //tab
    VFX_OBJ_CREATE(m_tab, VappFMRadioListTab, this);
    m_tab->setPos(TAB_X,TAB_Y);
    m_tab->setSize(TAB_WIDTH,TAB_HEIGHT);
    m_tab->m_auto->m_signalChoose.connect(this,&VappFMRadioList::onTabChoose);
    m_tab->m_fav->m_signalChoose.connect(this,&VappFMRadioList::onTabChoose);
    m_tab->setChoose(m_tabChoose);

    //page panel
    VFX_OBJ_CREATE(m_pagePanel, VcpPagePanel, this);
    m_pagePanel->setPos(PANEL_X, PANEL_Y);
    m_pagePanel->setSize(PANEL_WIDTH,PANEL_HEIGHT);

    //auto list
    VFX_OBJ_CREATE(m_autoList, VappFMRadioListAuto, m_pagePanel);
    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_autoList->setApp(VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappFMRadioApp));
    m_autoList->setPos(LIST_X, LIST_Y);
    m_autoList->setSize(PANEL_WIDTH,PANEL_HEIGHT);

    //fav list
    VFX_OBJ_CREATE(m_favList, VappFMRadioListFav, m_pagePanel);
    m_favList->setApp(VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappFMRadioApp));
    m_favList->setPos(LIST_X, LIST_Y);
    m_favList->setSize(PANEL_WIDTH,PANEL_HEIGHT);

    if(m_tabChoose == FAVORITE)
    {
        m_pagePanel->setCurrentFrame(m_favList);
    }
    else
    {
        m_pagePanel->setCurrentFrame(m_autoList);
    }


}

void VappFMRadioList::onTabChoose(VappFMRadioTabMode tab)
{
    if(tab == AUTO_SEARCH)
    {
        if(m_tabChoose == AUTO_SEARCH)
        {
            return;
        }
        
        m_tabChoose = AUTO_SEARCH;
        m_tab->setChoose(m_tabChoose);
        updateList();
        m_pagePanel->switchTo(m_autoList, VCP_PAGE_EFFECT_FADE_IN, 100, VCP_PAGE_DIRECTION_FROM_LEFT, VFX_FALSE);
        m_autoList->m_list->setFocused(VFX_TRUE);

		m_autoList->updateAutoList();
    }
    else
    {
        if(m_tabChoose == FAVORITE)
        {
            return;
        }

        m_tabChoose = FAVORITE;
        m_tab->setChoose(m_tabChoose);
        updateList();
        m_pagePanel->switchTo(m_favList, VCP_PAGE_EFFECT_FADE_IN, 100, VCP_PAGE_DIRECTION_FROM_RIGHT, VFX_FALSE);
        m_favList->m_list->setFocused(VFX_TRUE);
    }
}

void VappFMRadioList::updateList(void)
{
    if(m_tabChoose == AUTO_SEARCH)
    {
        m_autoList->m_list->updateAllItems();
    }
    else
    {
        m_favList->m_list->updateAllItems();
    }
}

//void VappFMRadioList::addToFavList(VfxU16 freq, VfxWString name)
//{
//    m_favList->addToFavList(freq, name);
//}

//VfxBool VappFMRadioList::checkFavList(VfxU16 freq)
//{
//    return m_favList->checkFavList(freq);
//}


/////////////////////////////////////////////////////////////////////////////////

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
#ifdef __MMI_FM_RADIO_RECORD__
    m_startCnf(NULL),
    m_recSaveStr(STR_ID_VAPP_FM_SAVE_RECORD_Q_MF),
#endif
    m_control(NULL),
    m_pagePanel(NULL),
    m_list(NULL)
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

/*
void VappFMRadioMainPage::closePage(void)
{
#ifdef __MMI_FM_RADIO_RECORD__
    if(m_startCnf != NULL)
    {
        VFX_OBJ_CLOSE(m_startCnf);
    }
#endif

    m_pagePanel->setCurrentFrame(m_control);

}
*/

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
            if(!is_from_avrcp && (m_pagePanel->getCurrentFrame() == m_list))
            {
                return VFX_FALSE;
            }

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
            if(!is_from_avrcp && (m_pagePanel->getCurrentFrame() == m_list))
            {
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {
                    //switch to fav
                    m_list->m_tab->m_fav->m_signalChoose.postEmit(VappFMRadioList::FAVORITE);
                }

                return VFX_TRUE;
            }

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
            if(!is_from_avrcp && (m_pagePanel->getCurrentFrame() == m_list))
            {
                if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {
                    //switch to auto
                    m_list->m_tab->m_auto->m_signalChoose.postEmit(VappFMRadioList::AUTO_SEARCH);
                }

                return VFX_TRUE;

            }

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

void VappFMRadioMainPage::onBack()
{
    if(m_pagePanel->getCurrentFrame() == m_list)
    {
        if(!m_list->m_favList->onBackKey() || m_list->m_tabChoose == VappFMRadioList::AUTO_SEARCH)
        {
            m_pagePanel->switchTo(m_control, VCP_PAGE_EFFECT_LEAVE, 350, VCP_PAGE_DIRECTION_FROM_UP, VFX_FALSE);
        }
    }
    else
    {
        m_app->exit();
    }
}

void VappFMRadioMainPage::arrowLLongPressed(VfxTimer *source)
{
    VFX_UNUSED(source);

    VfxU16 freq = m_app->getFreq();

    freq --;
    m_app->setFreq(freq, VFX_FALSE);
    updateFreq(VFX_TRUE);

    VfxMsec delay = m_arrowLTimer->getStartDelay();
    delay -= LONGPRESS_DUR_GAP;
    if(delay < LONGPRESS_DUR_MIN)
    {
        delay = LONGPRESS_DUR_MIN;
    }

    m_arrowLTimer->setStartDelay(delay);
    m_arrowLTimer->start();

    m_app->delaySetFreq();

}

void VappFMRadioMainPage::arrowRLongPressed(VfxTimer *source)
{
    VFX_UNUSED(source);

    VfxU16 freq = m_app->getFreq();

    freq ++;
    m_app->setFreq(freq, VFX_FALSE);
    updateFreq(VFX_TRUE);

    VfxMsec delay = m_arrowRTimer->getStartDelay();
    delay -= LONGPRESS_DUR_GAP;
    if(delay < LONGPRESS_DUR_MIN)
    {
        delay = LONGPRESS_DUR_MIN;
    }
    m_arrowRTimer->setStartDelay(delay);
    m_arrowRTimer->start();

    m_app->delaySetFreq();

}

void VappFMRadioMainPage::onWheelStatus(VfxObject *sender, VfxPenEvent event)
{
    VFX_UNUSED(sender);

    VfxU16 freq = m_app->getFreq();
    VfxS32 rel = event.pos.x - event.prevPos.x;
    
    freq += rel/WHEEL_PIXELS_TO_FREQ;

    m_app->setFreq(freq, VFX_FALSE);
    updateFreq(VFX_TRUE);

    m_app->delaySetFreq();

}

VfxBool VappFMRadioMainPage::LPButtonAction(VfxId id, VfxPenEventTypeEnum type)
{
	m_buttonPressed = id;
	VfxU16 freq = m_app->getFreq();

#ifdef __MMI_FM_RADIO_RECORD__
    if(stopRecConfirm())
    {
        return VFX_FALSE;
    }
#endif

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
#endif //0

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
#endif //0

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

#ifdef __MMI_FM_RADIO_RECORD__
void VappFMRadioMainPage::onNoMemoryCardButtonClicked(VfxObject* sender, VfxId btn)
{
    switch(btn)
    {
        //yes
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VFX_OBJ_CLOSE(sender);
            m_app->setStorage(STORAGE_PHONE);
            m_app->startRec();
            break;
        }

        //cancel
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        {
            VFX_OBJ_CLOSE(sender);
            break;
        }

        default:
            break;
    }
}
#endif

void VappFMRadioMainPage::seekCallback(mdi_fmr_cb_reason_enum result, U16 stop_freq, MMI_BOOL is_valid, void* user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_MPAGE_SEEK_CALLBACK, result);

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
	#ifdef __FM_RADIO_RDS_SUPPORT__
		ptr->m_app->turnOnRDS();
	#endif
}

void VappFMRadioMainPage::abortSeek(void)
{
	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO]abortSeek() ");

	mdi_fmr_seek_abort();
}

void VappFMRadioMainPage::startSeek(VfxBool forward)
{

    if(m_app->getState() != VADP_FM_RADIO_POWER_ON)
    {
        return;
    }

	m_seekingPromptTimer->start();

    /*clear RDS mask first in case during process shows wrong RDS info*/
#ifdef __FM_RADIO_RDS_SUPPORT__
    m_app->turnOffRDS();
#endif

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

#ifdef __MMI_FM_RADIO_RECORD__
void VappFMRadioMainPage::closeStopRecConfirms(void)
{
    if( m_startCnf != NULL )
    {
        VFX_OBJ_CLOSE(m_startCnf);
    }
}

void VappFMRadioMainPage::onStopRecButtonClickedInternal(VfxObject* sender, VfxId btn)
{
    switch(btn)
    {
        //continue
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VFX_OBJ_CLOSE(m_startCnf);
            m_app->stopRec(VFX_TRUE, VFX_TRUE);
			if(m_buttonPressed == BTN_PREV)
			{
				startSeek(VFX_FALSE);
			}
			else if(m_buttonPressed == BTN_NEXT)
			{
				startSeek(VFX_TRUE);
			}
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

VfxBool VappFMRadioMainPage::stopRecConfirm(void)
{
    if(m_app->getRecState() == VADP_FM_RADIO_REC_IDLE || m_app->getRecState() == VADP_FM_RADIO_REC_DISABLED)
    {
        return VFX_FALSE;
    }

    if(m_app->getRecState() == VADP_FM_RADIO_REC_SAVE)
    {
        m_app->stopRec(VFX_FALSE, VFX_TRUE);
        return VFX_FALSE;
    }

    else
    {
        closeStopRecConfirms();

        //confirm to do auto search
        VFX_OBJ_CREATE(m_startCnf, VcpConfirmPopup, this);
    
        m_startCnf->setInfoType(VCP_POPUP_TYPE_QUESTION);
        m_startCnf->setText(VFX_WSTR_RES(STR_ID_VAPP_FM_ASK_STOP_REC));
        m_startCnf->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
		m_startCnf->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_CONTINUE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_startCnf->setAutoDestory(VFX_FALSE);
        m_startCnf->show(VFX_TRUE);
        m_startCnf->m_signalButtonClicked.connect(this, &VappFMRadioMainPage::onStopRecButtonClickedInternal);
    }

    return VFX_TRUE;
}

void VappFMRadioMainPage::onSetFreqStopRecButtonClicked(VfxObject* sender, VfxId btn)
{
    switch(btn)
    {
        //continue
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VFX_OBJ_CLOSE(m_startCnf);
            m_app->stopRec(VFX_TRUE, VFX_TRUE);
            m_app->setFreq(m_tempFreq, VFX_TRUE);
            updateFreq(VFX_FALSE);
            m_tempFreq = 0 ;

            if(m_pagePanel->getCurrentFrame() == m_list)
            {
                m_list->updateList();
            }

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

VfxBool VappFMRadioMainPage::stopRecConfirm(VfxU16 freq)
{
    if(m_app->getRecState() == VADP_FM_RADIO_REC_IDLE || m_app->getRecState() == VADP_FM_RADIO_REC_DISABLED)
    {
        return VFX_FALSE;
    }

    if(m_app->getRecState() == VADP_FM_RADIO_REC_SAVE)
    {
        m_app->stopRec(VFX_FALSE, VFX_TRUE);
        return VFX_FALSE;
    }

    m_tempFreq = freq;

    //confirm to do auto search
    closeStopRecConfirms();
    
    VFX_OBJ_CREATE(m_startCnf, VcpConfirmPopup, this);

    m_startCnf->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_startCnf->setText(VFX_WSTR_RES(STR_ID_VAPP_FM_ASK_STOP_REC));
    m_startCnf->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_startCnf->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_CONTINUE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_startCnf->setAutoDestory(VFX_FALSE);
    m_startCnf->show(VFX_TRUE);
    m_startCnf->m_signalButtonClicked.connect(this, &VappFMRadioMainPage::onSetFreqStopRecButtonClicked);

    return VFX_TRUE;

}
#endif 

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

        #ifdef __MMI_FM_RADIO_RECORD__
            if(stopRecConfirm())
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

        #ifdef __MMI_FM_RADIO_RECORD__
            if(stopRecConfirm())
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
            if(m_list->m_favList->getCount() == VAPP_FM_RADIO_FAV_LIST_NUM)
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
            channel.format(" FM %.1f ", (VfxFloat)m_tempFreq/10);

            VfxWString title;
            title += add;
            title += channel;
            title += to_fav;

            VfxWString channel_name;
	    #ifdef __FM_RADIO_RDS_SUPPORT__
            VfxWChar* Text;
            getProgramName(&Text);
            if(Text[0] != 0)
            {
                channel_name += VFX_WSTR_MEM(Text);
            }
            else
	    #endif
            channel_name.format("FM %.1f",(VfxFloat)m_tempFreq/10);

            addFav->setTitle(title);
            addFav->setHintText(VFX_WSTR_RES(STR_ID_VAPP_FM_CHANNEL_NAME));
            addFav->setIME(IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE);
            addFav->m_signalButtonClicked.connect(this,&VappFMRadioMainPage::onAddToFavPopUpButtonClicked);
            addFav->setText(channel_name,19);
			addFav->getInputbox()->setHighlight(0, addFav->getText().getLength());      
            //((VcpTextEditor *)(addFav->getInputbox()))->activate();
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

	#ifdef __MMI_FM_RADIO_RECORD__
        case BTN_REC_START:
        {
            if(m_app->getRecState() == VADP_FM_RADIO_REC_DISABLED)
            {
                break;
            }
            //pause record
            else if(m_app->getRecState() == VADP_FM_RADIO_REC_ING)
            {
                m_app->pauseRec();
            }
            //start record
            else if(m_app->getRecState() == VADP_FM_RADIO_REC_PAUSE)
            {
                m_app->startRec();
            }
			else if(m_app->getState() == VADP_FM_RADIO_SEEKING || 
				m_app->getState() == VADP_FM_RADIO_SCANING || 
				m_app->getRecState() == VADP_FM_RADIO_REC_FIND_PATH)
            {
                VfxWString info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());				
            }
		#if (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))
            //check if currently BT connect
            else if(!mdi_audio_is_resource_available(MDI_AUDIO_RECORD_FM_RADIO, NULL))
            {
                VfxWString info = VFX_WSTR_RES(STR_ID_VAPP_FM_REC_CONFLICT_WITH_BT_CONNECT);
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
            }
		#endif
            //memory card not existed
            else if(m_app->getStorage() == STORAGE_MEMORY_CARD && !srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
            {
            	#ifdef __LOW_COST_SUPPORT_COMMON__
	                VfxWString info = VFX_WSTR_RES(STR_ID_VAPP_SNDREC_INSERT_MEMORY_CARD);
	                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
				#else
	                VcpConfirmPopup *no_memory_card;
	                VFX_OBJ_CREATE(no_memory_card, VcpConfirmPopup, this);

	                no_memory_card->setInfoType(VCP_POPUP_TYPE_QUESTION);
	                no_memory_card->setText(VFX_WSTR_RES(STR_ID_VAPP_FM_MC_REMOVED_USE_PHONE_Q));
	                no_memory_card->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	                no_memory_card->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_YES) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
	                no_memory_card->setAutoDestory(VFX_FALSE);
	                no_memory_card->show(VFX_TRUE);
	                no_memory_card->m_signalButtonClicked.connect(this, &VappFMRadioMainPage::onNoMemoryCardButtonClicked);
				#endif
            }
            //start record
            else
            {
                m_app->startRec();
            }
            break;
        }

        case BTN_REC_STOP:
        {
            //stop record
            m_app->stopRec(VFX_TRUE, VFX_TRUE);
            break;
        }
	#endif

        case BTN_LIST:
        {
            m_list->updateList();
            //switch to list screen
            m_pagePanel->switchTo(m_list, VCP_PAGE_EFFECT_ENTER, 350, VCP_PAGE_DIRECTION_FROM_BOTTOM, VFX_FALSE);
            break;
        }

        case BTN_SETTING:
        {
    	#if defined(__MMI_FM_RADIO_RECORD__) || defined(__FM_RADIO_RDS_SUPPORT__)
			#if defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__FM_RADIO_RDS_SUPPORT__)
	            //enter quality page
	            VappFMRadioQualitySettingPage *quality_setting_page;
	            VFX_OBJ_CREATE(quality_setting_page, VappFMRadioQualitySettingPage, getMainScr());
	            getMainScr()->pushPage(0,quality_setting_page);
			#else
	            //enter setting screen
	            VappFMRadioSettingPage *setting_page;
	            VFX_OBJ_CREATE(setting_page, VappFMRadioSettingPage, getMainScr());
	            getMainScr()->pushPage(0,setting_page);

			#endif
    	#endif
            break;
        }
    }

}

void VappFMRadioMainPage::onButtonClicked(VfxObject *sender, VfxId id)
{
    VFX_UNUSED(sender);
    ButtonAction(id);
}

#ifdef __MMI_FM_RADIO_RECORD__
void VappFMRadioMainPage::onRecSavePopUpButtonClicked(VfxId btn, void *user_data)
{

    VappFMRadioMainPage* ptr = (VappFMRadioMainPage*)handleToObject((VfxObjHandle)user_data);

    switch(btn)
    {
        //save
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            ptr->m_app->saveRec();

            VfxWString info = VFX_WSTR_RES(STR_ID_VAPP_FM_REC_SAVED);
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
            break;
        }

        //cancel
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        {
            ptr->m_app->cancelSaveRec();
            break;
        }

        default:
            break;
    }
}

void VappFMRadioMainPage::updateRecTime(VfxU32 time)
{
    m_control->updateRecTimeText(time);
}
#endif /*__MMI_FM_RADIO_RECORD__*/

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

void VappFMRadioMainPage::onSetFreqPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn)
{
    VFX_UNUSED(sender);

    switch(btn)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            VfxWString ErrMsg;
            VfxWString inputText = ((VcpInputPopup*)sender)->getText();

            if(inputText.isEmpty())
            {
                ErrMsg.format("Can not be empty");
                ((VcpInputPopup*)sender)->setErrorText(ErrMsg);
                return;
            }

            VfxU16 freq = WStringToFreq((VfxWChar *)inputText.getBuf(),this);

            if(freq < VappFMRadioApp::MIN_FREQ || freq > VappFMRadioApp::MAX_FREQ)
            {
                ErrMsg = VFX_WSTR_RES(STR_ID_VAPP_FM_INVALID_FQ);

                ((VcpInputPopup*)sender)->setErrorText(ErrMsg);
                return;
            }

        #ifdef __MMI_FM_RADIO_RECORD__
            if(stopRecConfirm(freq))
            {
                VFX_OBJ_CLOSE(sender);
                return;
            }
        #endif
            m_app->setFreq(freq, VFX_TRUE);
            updateFreq(VFX_FALSE);
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

void VappFMRadioMainPage::onAddToFavPopUpButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum btn)
{
    VFX_UNUSED(sender);

    switch(btn)
    {
        case VCP_INPUT_POPUP_BTN_OK:
        {
            // component already check empty
            VfxWString inputName =((VcpInputPopup*)sender)->getText();
            m_list->m_favList->addToFavList(m_tempFreq, inputName);
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
    if(m_list == NULL)
    {
        *str = (VfxWChar*)vapp_fm_radio_get_fav_name(freq);
        return;
    }

    VfxWChar* fav_name = m_list->m_favList->getFavName(freq);

    *str = fav_name;

    return;
}

#ifdef __FM_RADIO_RDS_SUPPORT__
void VappFMRadioMainPage::getProgramName(VfxWChar** str)
{
    *str = m_app->m_programName;
}

void VappFMRadioMainPage::getRadioText(VfxWChar** str)
{
    *str = m_app->m_radioText;
}
#endif

void VappFMRadioMainPage::onEnterFreqSet(void)
{
    VcpInputPopup* freqSetPopUp;

    VFX_OBJ_CREATE(freqSetPopUp, VcpInputPopup, this);

    VfxWString title;
    title = VFX_WSTR_RES(STR_ID_VAPP_FM_SET_FQ);

    VfxWString hint;
    hint = VFX_WSTR_RES(STR_ID_VAPP_FM_FQ);

    VfxWString freq;
    freq.format("%.1f",(VfxFloat)m_app->getFreq()/10);
    
    freqSetPopUp->setTitle(title);
    freqSetPopUp->setHintText(hint);
    freqSetPopUp->setText(freq,5);    
    freqSetPopUp->setIME(IMM_INPUT_TYPE_DECIMAL_NUMERIC, IME_SETTING_FLAG_NONE);
    freqSetPopUp->getInputbox()->setHighlight(0, freqSetPopUp->getText().getLength());
	freqSetPopUp->m_signalButtonClicked.connect(this,&VappFMRadioMainPage::onSetFreqPopUpButtonClicked);
    freqSetPopUp->show(VFX_TRUE);
}

void VappFMRadioMainPage::updateFreq(VfxBool spin_wheel)
{
	// If user play another channel when seeking, abort this seek.
	if(m_app->getState() == VADP_FM_RADIO_SEEKING)
	{
		abortSeek();
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

#ifdef __FM_RADIO_RDS_SUPPORT__
    m_info->updateInfoString();
#endif

    m_control->m_tuner->setPin(freq);

    if(spin_wheel)
    {
        m_control->m_wheel->spinWheel(freq);
    }

    if(m_pagePanel->getCurrentFrame() == m_list)
    {
        m_list->updateList();
    }

}

#ifdef __FM_RADIO_RDS_SUPPORT__
void VappFMRadioMainPage::updateRDSArea(void)
{
    if(m_app->m_RDSMask & VAPP_FMRADIO_TP)
    {
        m_control->m_RDSArea->setLight(VappFMRadioApp::TYPE_TP , VFX_TRUE);
    }
    else
    {
        m_control->m_RDSArea->setLight(VappFMRadioApp::TYPE_TP , VFX_FALSE);
    }

    if(m_app->m_RDSMask & VAPP_FMRADIO_AF)
    {
        m_control->m_RDSArea->setLight(VappFMRadioApp::TYPE_AF , VFX_TRUE);
    }
    else
    {
        m_control->m_RDSArea->setLight(VappFMRadioApp::TYPE_AF , VFX_FALSE);
    }

    if((m_app->m_RDSMask & VAPP_FMRADIO_PN) || (m_app->m_RDSMask & VAPP_FMRADIO_RT))
    {
        m_control->m_RDSArea->setLight(VappFMRadioApp::TYPE_RDS , VFX_TRUE);
    }
    else
    {
        m_control->m_RDSArea->setLight(VappFMRadioApp::TYPE_RDS , VFX_FALSE);
    }

}
#endif


void VappFMRadioMainPage::updateState(void)
{
    vadp_fm_radio_state_enum state = m_app->getState();
#ifdef __MMI_FM_RADIO_RECORD__
    vadp_fm_radio_record_state_enum recState = m_app->getRecState();
#endif

    switch(state)
    {
        case VADP_FM_RADIO_INTERRUPT:
        case VADP_FM_RADIO_POWER_OFF:
        {
            m_info->setLight(VFX_FALSE);
            m_control->m_tuner->setLight(VFX_FALSE);
			m_control->m_btnPower->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_POWER_OFF,0,0,0));
        #ifdef __MMI_FM_RADIO_RECORD__
            m_control->m_btnRrecStart->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC_D,0));
            m_control->m_btnRrecStart->setIsDisabled(VFX_TRUE);
            m_control->m_btnRecStop->setHidden(VFX_TRUE);
            m_control->m_recTimeText->setHidden(VFX_TRUE);
        #endif
            break;
        }

        case VADP_FM_RADIO_POWER_ON:
        case VADP_FM_RADIO_SEEKING:
        case VADP_FM_RADIO_SCANING:
        {
            m_info->setLight(VFX_TRUE);
            m_control->m_tuner->setLight(VFX_TRUE);
            m_control->m_btnPower->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_POWER_ON,0,0,0));
        #ifdef __MMI_FM_RADIO_RECORD__
            m_control->m_btnRrecStart->setIsDisabled(VFX_FALSE);

            switch(recState)
            {
                case VADP_FM_RADIO_REC_IDLE:
                case VADP_FM_RADIO_REC_FIND_PATH:
                {
                    m_control->m_btnRrecStart->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC_D,0));
					m_control->m_btnRrecStart->setIsDisabled(VFX_FALSE);
					m_control->m_btnRecStop->setHidden(VFX_TRUE);
                    m_control->m_recTimeText->setHidden(VFX_TRUE);                    
                    break;
                }

                case VADP_FM_RADIO_REC_ING:
                {
                    m_control->m_btnRrecStart->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_PAUSE,IMG_ID_VAPP_FM_BTN_PAUSE,IMG_ID_VAPP_FM_BTN_REC_D,0));
                    m_control->m_btnRecStop->setHidden(VFX_FALSE);
                    m_control->m_recTimeText->setHidden(VFX_FALSE);         
                    break;
                }
                
                case VADP_FM_RADIO_REC_PAUSE:
                {
                    m_control->m_btnRrecStart->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC_D,0));
                    break;
                }

                case VADP_FM_RADIO_REC_SAVE:
                {
                    m_control->m_btnRecStop->setHidden(VFX_TRUE);
                    m_control->m_recTimeText->setHidden(VFX_TRUE);
                    m_control->m_btnRrecStart->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC,IMG_ID_VAPP_FM_BTN_REC_D,0));
                    break;
                }

                case VADP_FM_RADIO_REC_DISABLED:
                {
                    m_control->m_btnRecStop->setHidden(VFX_TRUE);
                    m_control->m_recTimeText->setHidden(VFX_TRUE);
                    m_control->m_btnRrecStart->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_REC_D,0,0,0));
					m_control->m_btnRrecStart->setIsDisabled(VFX_TRUE);
					break;
                }

            }
            break;
        #endif

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

/*
void VappFMRadioMainPage::createListPanel(void)
{
    if(m_list == NULL)
    {
        VFX_OBJ_CREATE(m_list, VappFMRadioList, m_pagePanel);    
    }
}

void VappFMRadioMainPage::closeListPanel(void)
{
    if(m_app->getState() == VADP_FM_RADIO_SCANING)
    {
        m_list->m_autoList->abortAutoScan();
    }

    VFX_OBJ_CLOSE(m_list);
}
*/

void VappFMRadioMainPage::drawMainPage(void)
{
    //Page Panel
    VFX_OBJ_CREATE(m_pagePanel, VcpPagePanel, this);
    m_pagePanel->setRect(PANEL_X,PANEL_Y,PANEL_WIDTH,PANEL_HEIGHT);

    //Control Panel
    VFX_OBJ_CREATE(m_control, VappFMRadioControl, m_pagePanel);

    m_control->m_btnSpeaker->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
    m_control->m_btnFav->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);

    m_control->m_btnArrowL->m_buttonStatus.connect(this,&VappFMRadioMainPage::onButtonStatus);
    m_control->m_btnArrowR->m_buttonStatus.connect(this,&VappFMRadioMainPage::onButtonStatus);

    m_control->m_wheelArea->m_wheelStatus.connect(this,&VappFMRadioMainPage::onWheelStatus);

    m_control->m_btnPower->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
    m_control->m_btnList->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
#if defined(__MMI_FM_RADIO_RECORD__) || defined(__FM_RADIO_RDS_SUPPORT__)
    m_control->m_btnSetting->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
  #ifdef __MMI_FM_RADIO_RECORD__
    m_control->m_btnRrecStart->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
    m_control->m_btnRecStop->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
  #endif
#endif

    //Info
    VFX_OBJ_CREATE(m_info, VappFMRadioInfo, this);
    m_info->setRect(INFO_X,INFO_X,INFO_WIDTH,INFO_HEIGHT);
    m_info->m_btnNext->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
    m_info->m_btnPrev->m_signalClicked.connect(this,&VappFMRadioMainPage::onButtonClicked);
    m_info->m_channelBox->m_signalBoxPressed.connect(this,&VappFMRadioMainPage::onEnterFreqSet);
    m_info->m_channelBox->m_signalGetFavName.connect(this,&VappFMRadioMainPage::getFavName);
#ifdef __FM_RADIO_RDS_SUPPORT__
    m_info->m_signalGetProgramName.connect(this,&VappFMRadioMainPage::getProgramName);
    m_info->m_signalGetRadioText.connect(this,&VappFMRadioMainPage::getRadioText);
#endif

    VFX_OBJ_CREATE(m_arrowLTimer, VfxTimer, this);
    m_arrowLTimer->m_signalTick.connect(this, &VappFMRadioMainPage::arrowLLongPressed);

    VFX_OBJ_CREATE(m_arrowRTimer, VfxTimer, this);
    m_arrowRTimer->m_signalTick.connect(this, &VappFMRadioMainPage::arrowRLongPressed);

	// for seeking
	const VfxU16 SEEKING_PROMPT_TIME  = 200;
	const VfxU16 SEEKING_PROMPT_DURATION_TIME = 300;
	
	VFX_OBJ_CREATE(m_seekingPromptTimer, VfxTimer, this);
	m_seekingPromptTimer->setStartDelay(SEEKING_PROMPT_TIME);
    m_seekingPromptTimer->m_signalTick.connect(this, &VappFMRadioMainPage::onSeekingTimeout);

	VFX_OBJ_CREATE(m_seekingDelayTimer, VfxTimer, this);
	m_seekingDelayTimer->setStartDelay(SEEKING_PROMPT_DURATION_TIME);
    m_seekingDelayTimer->m_signalTick.connect(this, &VappFMRadioMainPage::onSeekingTimeout);

    //updateState();
	
    m_pagePanel->setCurrentFrame(m_control);

}

#ifdef __MMI_FM_VIA_A2DP__
void VappFMRadioMainPage::createLoadingPopup()
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_CREATE_LOADING_POPUP);
	
	if(m_loadingPopup == NULL)
	{
	    VFX_OBJ_CREATE(m_loadingPopup, VcpLoadingPopup, this);
	}
	
    m_loadingPopup->show(VFX_TRUE);
	m_loadingPopup->setAutoDestory(VFX_TRUE);
}

void VappFMRadioMainPage::closeLoadingPopup()
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_APP_CLOSE_LOADING_POPUP);

	if(m_loadingPopup != NULL)
	{
		VFX_OBJ_CLOSE(m_loadingPopup);
	}
}
#endif // __MMI_FM_VIA_A2DP__


/////////////////////////////////////////////////////////////////////////////////

VappFMRadioInfo::VappFMRadioInfo():
	m_channelBox(NULL),
#ifdef __FM_RADIO_RDS_SUPPORT__
	m_infoString(NULL),
#endif
    m_btnPrev(NULL),
    m_btnNext(NULL)
{
}

void VappFMRadioInfo::onInit(void)
{
    VfxControl::onInit();
    drawInfo();
}

#ifdef __FM_RADIO_RDS_SUPPORT__
void VappFMRadioInfo::updateInfoString()
{
    VfxWString str;
    VfxWChar* Text;

    m_signalGetProgramName.emit(&Text);
    if(Text[0] != 0)
    {
        str += VFX_WSTR_MEM(Text);
    }

    m_signalGetRadioText.emit(&Text);
    if(Text[0] != 0)
    {
        if(!str.isEmpty())
        {
            str += VFX_WSTR(". ");
        }
        str += VFX_WSTR_MEM(Text);
    }

    VfxWString str2 = m_infoString->getText();

    if(str != str2)
    {
        m_infoString->clearMovableFrame();

        if(!str.isEmpty())
        {    
            m_infoString->setMovableFrame(str, VfxFontDesc(VFX_FONT_DESC_VF_SIZE(RDS_FONT_SIZE)));
            m_infoString->startScroll();
        }
    }

}
#endif

void VappFMRadioInfo::setLight(VfxBool turn_on)
{
    if(turn_on)
    {
        m_channelBox->setLight(turn_on);
    
        m_btnNext->setOpacity(1.0);
        m_btnPrev->setOpacity(1.0);
    #ifdef __FM_RADIO_RDS_SUPPORT__
        m_infoString->setOpacity(1.0);
    #endif
    }
    else
    {
        m_channelBox->setLight(turn_on);

        m_btnNext->setOpacity(0.3);
        m_btnPrev->setOpacity(0.3);
    #ifdef __FM_RADIO_RDS_SUPPORT__
        m_infoString->setOpacity(0.2);
    #endif
    }
}

void VappFMRadioInfo::drawInfo(void)
{
    setPos(VappFMRadioMainPage::INFO_X,VappFMRadioMainPage::INFO_Y);
    setSize(VappFMRadioMainPage::INFO_WIDTH,VappFMRadioMainPage::INFO_HEIGHT);

    //BG image
    VfxImageFrame* bg_up;
    VFX_OBJ_CREATE(bg_up,VfxImageFrame,this);
    bg_up->setResId(IMG_ID_VAPP_FM_BG_UP);
    bg_up->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bg_up->setRect(0,0, getSize().width, getSize().height);

    //LCD BG
    VfxImageFrame* LCD_bg;
    VFX_OBJ_CREATE(LCD_bg,VfxImageFrame,this);
    LCD_bg->setResId(IMG_ID_VAPP_FM_LCD_BG);
    LCD_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    LCD_bg->setRect(LCD_BG_X, LCD_BG_Y, LCD_BG_WIDTH, LCD_BG_HEIGHT);

    //BTN prev
    VFX_OBJ_CREATE(m_btnPrev,VcpImageButton,this);
    m_btnPrev->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_PREV));
    m_btnPrev->setId(VappFMRadioMainPage::BTN_PREV);
    m_btnPrev->setRect(VfxRect(BTN_PREV_X,BTN_PREV_Y,BTN_PREV_WIDTH,BTN_PREV_HEIGHT));

    //BTN next
    VFX_OBJ_CREATE(m_btnNext,VcpImageButton,this);
    m_btnNext->setImage(VcpStateImage(IMG_ID_VAPP_FM_BTN_NEXT));
    m_btnNext->setId(VappFMRadioMainPage::BTN_NEXT);
    m_btnNext->setRect(VfxRect(BTN_NEXT_X,BTN_NEXT_Y,BTN_NEXT_WIDTH,BTN_NEXT_HEIGHT));

    //Channel Box
    VFX_OBJ_CREATE(m_channelBox,VappFMRadioChannelBox,this);
    m_channelBox->setRect(BTN_CHANNEL_X,BTN_CHANNEL_Y,BTN_CHANNEL_WIDTH,BTN_CHANNEL_HEIGHT);

    //Line
    VfxFrame* line;
    VFX_OBJ_CREATE(line,VfxFrame,this);
    line->setRect(LINE_X,LINE_Y,LINE_WIDTH,LINE_HEIGHT);
    line->setBgColor(VfxColor(255,66,66,66));

    //Info string
#ifdef __FM_RADIO_RDS_SUPPORT__
    // Marquee
    VFX_OBJ_CREATE(m_infoString, VcpMarquee, this);
    m_infoString->setPos(RDS_X, RDS_Y);
    m_infoString->setSize(RDS_WIDTH, RDS_HEIGHT);
    m_infoString->setTextColor(VFX_COLOR_WHITE);
    m_infoString->setValign(VcpMarquee::VALIGN_CENTER);
    m_infoString->setHalign(VcpMarquee::HALIGN_CENTER);
    m_infoString->setSpeed(10);

#endif

}

/////////////////////////////////////////////////////////////////////////////////

VappFMRadioChannelBox::VappFMRadioChannelBox():
    m_channel(NULL),
    m_enabled(VFX_FALSE)
{}

void VappFMRadioChannelBox::onInit(void)
{
    VfxControl::onInit();

    //Channel
    VFX_OBJ_CREATE(m_channel,VfxTextFrame,this);
    m_channel->setAnchor(0.5,0);
    m_channel->setPos(FAV_X,FAV_Y);
    m_channel->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CHANNEL_FONT_ZISE)));

    //Fav name
    VFX_OBJ_CREATE(m_favName,VfxTextFrame,this);
    m_favName->setAnchor(0.5,0);
    m_favName->setPos(FAV_X,FAV_Y);
    m_favName->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CHANNEL_FONT_ZISE)));
    m_favName->setSize(FAV_WIDTH,FAV_HEIGHT);
    m_favName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_favName->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);


}

void VappFMRadioChannelBox::setLight(VfxBool turn_on)
{
    if(turn_on)
    {
        m_channel->setOpacity(1.0);
        m_favName->setOpacity(1.0);
        m_enabled = VFX_TRUE;
    }
    else
    {
        m_channel->setOpacity(0.2);
        m_favName->setOpacity(0.2);
        m_enabled = VFX_FALSE;
    }

}
VfxBool VappFMRadioChannelBox::setFreq(VfxU16 freq)
{
    VfxWChar* favText = NULL;
    VfxWString str;
    m_signalGetFavName.emit(&favText, freq);

    if(favText != NULL)
    {
        str.loadFromMem(favText);
        m_favName->setString(str);

        m_favName->setHidden(VFX_FALSE);
        m_channel->setHidden(VFX_TRUE);
        return VFX_TRUE;
    }
    else
    {
        VfxFloat num = ((VfxFloat)freq)/10;
		
		str.format("FM %.1f",num);
        m_channel->setString(str);

        m_favName->setHidden(VFX_TRUE);
        m_channel->setHidden(VFX_FALSE);
        return VFX_FALSE;
    }

}

VfxBool VappFMRadioChannelBox::onPenInput(VfxPenEvent & event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN && m_enabled)
    {
        m_signalBoxPressed.postEmit();
        return VFX_TRUE;
    }

    return VfxControl::onPenInput(event);
}

void VappFMRadioChannelBox::showSeekingPrompt(VfxBool isShow)
{
	if(isShow)
	{
		m_favName->setString(VFX_WSTR_RES(STR_ID_VAPP_FM_SEARCHING));
	}
	m_favName->setHidden(!isShow);
    m_channel->setHidden(isShow);	
}

/////////////////////////////////////////////////////////////////////////////////

VappFMRadioSettingPage::VappFMRadioSettingPage():
    m_form(NULL),
#ifdef __MMI_FM_RADIO_RECORD__
	#ifndef __LOW_COST_SUPPORT_COMMON__
    m_storage_launcher(NULL),
	#endif
    m_quality_launcher(NULL),
#endif
#ifdef __FM_RADIO_RDS_SUPPORT__
    m_RDS_switch(NULL),
    m_AF_switch(NULL),
    m_TP_switch(NULL),
#endif
    m_app(NULL)
{}

void VappFMRadioSettingPage::onInit(void)
{
    VfxPage::onInit();

    m_app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFMRadioApp);

    //Draw Setting Page
    drawSettingPage();

#ifdef __MMI_FM_RADIO_RECORD__
	m_app->m_recStateChanged.connect(this,&VappFMRadioSettingPage::onRecStateChanged);
#endif
}

#ifdef __MMI_FM_RADIO_RECORD__
void VappFMRadioSettingPage::onRecStateChanged(vadp_fm_radio_record_state_enum pre_state , vadp_fm_radio_record_state_enum cur_state)
{
	
	if(cur_state != VADP_FM_RADIO_REC_IDLE)
	{
	#ifndef __LOW_COST_SUPPORT_COMMON__
		m_storage_launcher->setIsDisabled(VFX_TRUE);
	#endif
		m_quality_launcher->setIsDisabled(VFX_TRUE);
	
	#ifdef __MMI_USB_SUPPORT__
		// If usb is in mass storage mode, then recording state is disabled, but recording quality can be changed. 
		if(srv_usb_is_in_mass_storage_mode())
		{			
			m_quality_launcher->setIsDisabled(VFX_FALSE);
		}
	#endif
	}
	else
	{
	#ifndef __LOW_COST_SUPPORT_COMMON__
		m_storage_launcher->setIsDisabled(VFX_FALSE);
	#endif
		m_quality_launcher->setIsDisabled(VFX_FALSE);
	}

}
#endif

void VappFMRadioSettingPage::onLauncher(VcpFormItemCell* sender, VfxId id)
{
    VFX_UNUSED(sender);

    switch(id)
    {
    #ifndef __LOW_COST_SUPPORT_COMMON__
        case STORAGE_L:
        {
            //enter storage page            
            VappFMRadioStorageSettingPage *storage_setting_page;
            VFX_OBJ_CREATE(storage_setting_page, VappFMRadioStorageSettingPage, getMainScr());
            getMainScr()->pushPage(0,storage_setting_page);
            break;
        }
	#endif

        case QUALITY_L:
        {
            //enter quality page
            VappFMRadioQualitySettingPage *quality_setting_page;
            VFX_OBJ_CREATE(quality_setting_page, VappFMRadioQualitySettingPage, getMainScr());
            getMainScr()->pushPage(0,quality_setting_page);
            break;
        }
    }

}

void VappFMRadioSettingPage::onEnter(VfxBool isBackward)
{
    VFX_UNUSED(isBackward);

#ifdef __MMI_FM_RADIO_RECORD__
	#ifndef __LOW_COST_SUPPORT_COMMON__
    if(m_app->getStorage() == STORAGE_PHONE)
    {
	    m_storage_launcher->setHintText(VFX_WSTR_RES(STR_GLOBAL_PHONE));
    }
    else
    {
	    m_storage_launcher->setHintText(VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD));
    }
	#endif

    if(m_app->getQuality() == VappFMRadioApp::QUALITY_STANDARD)
    {
        m_quality_launcher->setHintText(VFX_WSTR_RES(STR_ID_VAPP_FM_QUALITY_STANDARD));
    }
    else
    {
        m_quality_launcher->setHintText(VFX_WSTR_RES(STR_ID_VAPP_FM_QUALITY_HIGH));
    }

	onRecStateChanged(m_app->getRecState(),m_app->getRecState());

#endif

#ifdef __FM_RADIO_RDS_SUPPORT__

    if(m_app->getRDS(VappFMRadioApp::TYPE_RDS))
    {
        m_RDS_switch->setSwitchStatus(VFX_TRUE);
        m_AF_switch->setIsDisabled(VFX_FALSE);
        m_TP_switch->setIsDisabled(VFX_FALSE);
    }
    else
    {
        m_RDS_switch->setSwitchStatus(VFX_FALSE);
        m_AF_switch->setIsDisabled(VFX_TRUE);
        m_TP_switch->setIsDisabled(VFX_TRUE);
    }

    if(m_app->getRDS(VappFMRadioApp::TYPE_AF))
    {
        m_AF_switch->setSwitchStatus(VFX_TRUE);
    }
    else
    {
        m_AF_switch->setSwitchStatus(VFX_FALSE);
    }

    if(m_app->getRDS(VappFMRadioApp::TYPE_TP))
    {
        m_TP_switch->setSwitchStatus(VFX_TRUE);
    }
    else
    {
        m_TP_switch->setSwitchStatus(VFX_FALSE);
    }
#endif


}

void VappFMRadioSettingPage::onSwitchChanged(VcpFormItemSwitchCell* sender, VfxId id, VfxBool turn_on)
{
    VFX_UNUSED(sender);
#ifdef __FM_RADIO_RDS_SUPPORT__
    switch(id)
    {
        case RDS_S:
        {
            if(turn_on)
            {
                sender->setSwitchStatus(VFX_TRUE);
                m_AF_switch->setIsDisabled(VFX_FALSE);
                m_TP_switch->setIsDisabled(VFX_FALSE);
            }
            else
            {
                sender->setSwitchStatus(VFX_FALSE);
                m_AF_switch->setIsDisabled(VFX_TRUE);
                m_TP_switch->setIsDisabled(VFX_TRUE);
            }

            m_app->setRDS(VappFMRadioApp::TYPE_RDS, turn_on);

            break;
        }

        case AF_S:
        {
            if(turn_on)
            {
                sender->setSwitchStatus(VFX_TRUE);
            }
            else
            {
                sender->setSwitchStatus(VFX_FALSE);
            }

            m_app->setRDS(VappFMRadioApp::TYPE_AF, turn_on);

            break;
        }

        case TP_S:
        {
            if(turn_on)
            {
                sender->setSwitchStatus(VFX_TRUE);
            }
            else
            {
                sender->setSwitchStatus(VFX_FALSE);
            }

            m_app->setRDS(VappFMRadioApp::TYPE_TP, turn_on);

            break;
        }

    }
#endif
}


void VappFMRadioSettingPage::drawSettingPage(void)
{

    VcpTitleBar *tBar;
    VFX_OBJ_CREATE(tBar, VcpTitleBar, this);
    tBar->setTitle(VFX_WSTR_RES(STR_GLOBAL_SETTINGS));
    setTopBar(tBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());

#ifdef __MMI_FM_RADIO_RECORD__
	#ifndef __LOW_COST_SUPPORT_COMMON__
	    //Storage Launcher
		VFX_OBJ_CREATE(m_storage_launcher, VcpFormItemLauncherCell, m_form);
		m_storage_launcher->setMainText(VFX_WSTR_RES(STR_ID_VAPP_FM_STORAGE));
		m_storage_launcher->m_signalTap.connect(this, &VappFMRadioSettingPage::onLauncher);
	    m_storage_launcher->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	    m_form->addItem(m_storage_launcher, STORAGE_L);
	#endif

    //Quality Launcher
	VFX_OBJ_CREATE(m_quality_launcher, VcpFormItemLauncherCell, m_form);
	m_quality_launcher->setMainText(VFX_WSTR_RES(STR_ID_VAPP_FM_QUALITY));
	m_quality_launcher->m_signalTap.connect(this, &VappFMRadioSettingPage::onLauncher);
    m_quality_launcher->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_form->addItem(m_quality_launcher, QUALITY_L);
#endif

#ifdef __FM_RADIO_RDS_SUPPORT__
    //RDS Switch
    VFX_OBJ_CREATE(m_RDS_switch, VcpFormItemSwitchCell, m_form);
    m_RDS_switch->setMainText(VFX_WSTR_RES(STR_ID_VAPP_FM_RDS));
    m_RDS_switch->m_signalSwitchChangeReq.connect(this, &VappFMRadioSettingPage::onSwitchChanged);
    m_form->addItem(m_RDS_switch,RDS_S);

    //AF Switch
    VFX_OBJ_CREATE(m_AF_switch, VcpFormItemSwitchCell, m_form);
    m_AF_switch->setMainText(VFX_WSTR_RES(STR_ID_VAPP_FM_AF));
    m_AF_switch->m_signalSwitchChangeReq.connect(this, &VappFMRadioSettingPage::onSwitchChanged);
    m_form->addItem(m_AF_switch,AF_S);


    //TP Switch
    VFX_OBJ_CREATE(m_TP_switch, VcpFormItemSwitchCell, m_form);
    m_TP_switch->setMainText(VFX_WSTR_RES(STR_ID_VAPP_FM_TP));
    m_TP_switch->m_signalSwitchChangeReq.connect(this, &VappFMRadioSettingPage::onSwitchChanged);
    m_form->addItem(m_TP_switch,TP_S);
#endif

}

/////////////////////////////////////////////////////////////////////////////////

#ifndef __LOW_COST_SUPPORT_COMMON__

VappFMRadioStorageSettingPage::VappFMRadioStorageSettingPage():
    m_app(NULL)
{}

void VappFMRadioStorageSettingPage::onInit(void)
{
    VfxPage::onInit();

    m_app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFMRadioApp);

#ifdef __MMI_FM_RADIO_RECORD__
    m_app->m_memoryCardPlugged.connect(this,&VappFMRadioStorageSettingPage::onMemoryCardChanged);
	m_app->m_recStateChanged.connect(this,&VappFMRadioStorageSettingPage::onRecStateChanged);
#endif

    VcpTitleBar *tBar;
    VFX_OBJ_CREATE(tBar, VcpTitleBar, this);
    tBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_FM_STORAGE));
    setTopBar(tBar);

    
    VFX_OBJ_CREATE(m_storage_setting, VcpListMenu, this);

    m_storage_setting->setPos(0,0);
    m_storage_setting->setSize(getSize());
    m_storage_setting->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT); 
    m_storage_setting->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK,VFX_FALSE);
    m_storage_setting->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    m_storage_setting->setContentProvider(this);
    m_storage_setting->m_signalItemTapped.connect(this, &VappFMRadioStorageSettingPage::onItemTapped);

}

void VappFMRadioStorageSettingPage::onMemoryCardChanged(void)
{
    m_storage_setting->updateAllItems();
}

void VappFMRadioStorageSettingPage::onRecStateChanged(vadp_fm_radio_record_state_enum pre_state , vadp_fm_radio_record_state_enum cur_state)
{
    if(cur_state != VADP_FM_RADIO_REC_IDLE)
	{
	 	getMainScr()->popPage();	
    }
}

VfxU32 VappFMRadioStorageSettingPage::getCount(void) const
{
    return STORAGE_TOTAL;
}

VfxBool VappFMRadioStorageSettingPage::getItemText(VfxU32 index,                    // [IN] the index of item
                                                   VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                                                   VfxWString &text,                // [OUT] the text resource
                                                   VcpListMenuTextColorEnum &color  // [OUT] the text color
                                                   )
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        switch(index)
        {
            case STORAGE_PHONE:
            {
                text = VFX_WSTR_RES(STR_GLOBAL_PHONE);
                return VFX_TRUE;
            }

            case STORAGE_MEMORY_CARD:
            {
                text = VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD);
                return VFX_TRUE;
            }

            default:
                break;
        }

    }

    return VFX_FALSE;
}

/*
void VappFMRadioStorageSettingPage::onMemoryCardRemovButtonClicked(VfxObject* sender, VfxId btn)
{
    VFX_UNUSED(sender);

    switch(btn)
    {
        case VCP_CONFIRM_POPUP_BUTTON_OK:
        {
            getMainScr()->popPage();
            break;
        }

        default:
            break;
    }
}
*/

void VappFMRadioStorageSettingPage::onItemTapped(VcpListMenu *menu, VfxU32 index)
{
    switch(index)
    {
        case STORAGE_PHONE:
        {
        #ifdef __MMI_FM_RADIO_RECORD__
            m_app->setStorage(STORAGE_PHONE);
        #endif
            getMainScr()->popPage();
            break;
        }

        case STORAGE_MEMORY_CARD:
        {
        #ifdef __MMI_FM_RADIO_RECORD__
            m_app->setStorage(STORAGE_MEMORY_CARD);
        #endif
            getMainScr()->popPage();
            break;
        }

        default:
            break;
        
    }
}


VfxBool VappFMRadioStorageSettingPage::getItemIsDisabled(VfxU32 index) const
{
    if( index == STORAGE_MEMORY_CARD && !srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VcpListMenuItemStateEnum VappFMRadioStorageSettingPage::getItemState(VfxU32 index) const
{
#ifdef __MMI_FM_RADIO_RECORD__
    switch(index)
    {
        case STORAGE_PHONE:
        {
            if(m_app->getStorage() == STORAGE_PHONE)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            break;
        }

        case STORAGE_MEMORY_CARD:
        {
            if(m_app->getStorage() == STORAGE_MEMORY_CARD)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            break;
        }

        default:
            break;
    }
#endif

    return VCP_LIST_MENU_ITEM_STATE_NONE;

}

#endif

/////////////////////////////////////////////////////////////////////////////////

VappFMRadioQualitySettingPage::VappFMRadioQualitySettingPage():
    m_app(NULL)
{}

void VappFMRadioQualitySettingPage::onInit(void)
{
    VfxPage::onInit();

    m_app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappFMRadioApp);

    VcpTitleBar *tBar;
    VFX_OBJ_CREATE(tBar, VcpTitleBar, this);
    tBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_FM_QUALITY));
    setTopBar(tBar);

    VcpListMenu *quality_setting;
    
    VFX_OBJ_CREATE(quality_setting, VcpListMenu, this);

    quality_setting->setPos(0,0);
    quality_setting->setSize(getSize());
    quality_setting->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT); 
    quality_setting->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK,VFX_FALSE);
    quality_setting->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    quality_setting->setContentProvider(this);
    quality_setting->m_signalItemTapped.connect(this, &VappFMRadioQualitySettingPage::onItemTapped);

}

VfxU32 VappFMRadioQualitySettingPage::getCount(void) const
{
    return VappFMRadioApp::QUALITY_TOTAL;
}

VfxBool VappFMRadioQualitySettingPage::getItemText(VfxU32 index,                    // [IN] the index of item
                                                   VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                                                   VfxWString &text,                // [OUT] the text resource
                                                   VcpListMenuTextColorEnum &color  // [OUT] the text color
                                                   )
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        switch(index)
        {
            case VappFMRadioApp::QUALITY_STANDARD:
            {
                text = VFX_WSTR_RES(STR_ID_VAPP_FM_QUALITY_STANDARD);
                return VFX_TRUE;
            }

            case VappFMRadioApp::QUALITY_HIGH:
            {
                text = VFX_WSTR_RES(STR_ID_VAPP_FM_QUALITY_HIGH);
                return VFX_TRUE;
            }

            default:
                break;
        }

    }

    return VFX_FALSE;
}


void VappFMRadioQualitySettingPage::onItemTapped(VcpListMenu *menu, VfxU32 index)
{
    switch(index)
    {
        case VappFMRadioApp::QUALITY_STANDARD:
        {
        #ifdef __MMI_FM_RADIO_RECORD__
            m_app->setQuality(VappFMRadioApp::QUALITY_STANDARD);
        #endif
            getMainScr()->popPage();
            break;
        }

        case VappFMRadioApp::QUALITY_HIGH:
        {
        #ifdef __MMI_FM_RADIO_RECORD__
            m_app->setQuality(VappFMRadioApp::QUALITY_HIGH);
        #endif
            getMainScr()->popPage();
            break;
        }

        default:
            break;
        
    }
}

VfxBool VappFMRadioQualitySettingPage::getItemIsDisabled(VfxU32 index) const
{
#ifdef __MMI_FM_RADIO_RECORD__
#ifdef __MMI_USB_SUPPORT__
	// If usb is in mass storage mode, then recording state is disabled, but recording quality can be changed. 
	if(srv_usb_is_in_mass_storage_mode())
	{
		return VFX_FALSE;
	}
#endif	
	if(m_app->getRecState() != VADP_FM_RADIO_REC_IDLE)
	{
		return VFX_TRUE;
	}
#endif
	return VFX_FALSE;
}

VcpListMenuItemStateEnum VappFMRadioQualitySettingPage::getItemState(VfxU32 index) const
{
#ifdef __MMI_FM_RADIO_RECORD__
    switch(index)
    {
        case VappFMRadioApp::QUALITY_STANDARD:
        {
            if(m_app->getQuality() == VappFMRadioApp::QUALITY_STANDARD)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            break;
        }

        case VappFMRadioApp::QUALITY_HIGH:
        {
            if(m_app->getQuality() == VappFMRadioApp::QUALITY_HIGH)
            {
                return VCP_LIST_MENU_ITEM_STATE_SELECTED;
            }
            break;
        }

        default:
            break;
    }
#endif

    return VCP_LIST_MENU_ITEM_STATE_NONE;

}

#endif /* __MMI_FM_RADIO__ */


