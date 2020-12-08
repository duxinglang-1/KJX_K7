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
 *   vapp_fm_radio_ncenter_slim.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  FM Radio NCenter source code file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "MMI_features.h"

#ifdef __MMI_FM_RADIO_SLIM__

#if defined(__MMI_NCENTER_SUPPORT__)

#include "vapp_fm_radio_slim.h"
#include "vapp_fm_radio_ncenter_slim.h"
#include "vapp_fm_radio_util_slim.h"
#include "vcp_global_popup.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "UcmSrvGprot.h"
#include "mmi_rp_vapp_fm_radio_def.h"
#include "mmi_rp_app_ncenter_def.h"
#include "MMI_media_app_trc.h"
#include "mmi_cb_mgr_gprot.h"
#include "AppMgrSrvGprot.h"

mmi_ret vapp_fm_radio_on_ncenter_update(mmi_event_struct *evt)
{
    vapp_fm_radio_ncenter_update_evt_struct *power_evt = (vapp_fm_radio_ncenter_update_evt_struct*) evt;

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_ON_NCENTER_UPDATE, power_evt->is_shown);

    if(power_evt->is_shown)
    {
    	// create fm group
		VsrvNGroupSingleTitle *fm_group;
		VSRV_NGROUP_CREATE_EX(fm_group, VsrvNGroupSingleTitle, (VAPP_FM_RADIO));
		fm_group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_FM));

		// create fm notification
		VsrvNotificationCustom *fm_noti;
		VSRV_NOTIFICATION_CREATE_EX(fm_noti, VsrvNotificationCustom, ((VsrvNGroup*)fm_group, 0));
		fm_noti->setHeight(VappFmRadioNCell::FM_NCELL_HEIGHT);
		fm_noti->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VappFmRadioNCell), VSRV_NVIEWER_TYPE_GENERAL);
		fm_noti->setCategory(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING);
		fm_noti->setAutoLaunch(VFX_FALSE);
		fm_noti->setAutoClose(VFX_FALSE);
		fm_noti->notify();		
	}
    else
    {
    	VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_FM_RADIO, 0);
    }

    return MMI_OK;
}

static MMI_BOOL vapp_fm_radio_ncell_callback(mmi_scenario_id scen_id, void *user_data)
{   
    //dummy
    return MMI_TRUE;
}


// Confim to close FM Radio NCell
static void vapp_fm_radio_ncell_on_popup_exit(VfxId id, void *userData)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_NCELL_ON_POPUP_EXIT);

	vadp_fm_radio_set_global_popup_could_close(VFX_TRUE);

    if(id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
    	// close fm ncenter widget
        VsrvNotification* noti = (VsrvNotification*) userData;	
        VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);        
        if (nm->checkNotification(noti))
        {
            vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_TERMINATE, noti);

			vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, noti);
            VSRV_NOTIFICATION_CLOSE(noti);
        }
    }
}


/***************************************************************************** 
 * Class VappFmRadioNCell    
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappFmRadioNCell", VappFmRadioNCell, VsrvNCell);

void VappFmRadioNCell::onCreateView(void* viewData, VfxU32 viewDataSize)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_NCELL_ON_CREATE_VIEW);

	// set rect
    VsrvNCell::onCreateView(viewData, viewDataSize);
	setSize(FM_NCELL_WIDTH, FM_NCELL_HEIGHT);

	// create fm panel
	VFX_OBJ_CREATE(m_fmPanel, VappWidgetFmRadioPanel, this);
	
	// create close image
    VFX_OBJ_CREATE(m_closeButton, VcpImageButton, this);
    m_closeButton->setImage(VcpStateImage(VAPP_IMG_NCENTER_CLOSE_ICON));
	m_closeButton->setAnchor(1.0f,0.0f);
    m_closeButton->setPos((getSize().width - VappWidgetFmRadioPanel::PN_IMAGE_BTN_X - VappWidgetFmRadioPanel::PN_X), (VappWidgetFmRadioPanel::PN_IMAGE_BTN_Y + VappWidgetFmRadioPanel::PN_Y));	
	m_closeButton->setSize(VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH, VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_HEIGHT);    
    m_closeButton->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
	m_closeButton->m_signalClicked.connect(this, &VappFmRadioNCell::onCloseButtonClicked);
}

void VappFmRadioNCell::onCloseView()
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_NCELL_ON_CLOSE_VIEW, m_fmPanel->m_state);

    VFX_OBJ_CLOSE(m_closeButton);
    VFX_OBJ_CLOSE(m_fmPanel);
}

void VappFmRadioNCell::onProcessIntent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_NCELL_ON_PROCESS_INTENT, intent);

	// no need to process VSRV_NINTENT_TYPE_LAUNCH type
    if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
	{
		m_fmPanel->powerOff();
	}
}

void VappFmRadioNCell::onCloseButtonClicked(VfxObject* sender, VfxId id)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_NCELL_ON_CLOSE_BUTTON_CLICKED);

    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_WARNING, &vapp_fm_radio_ncell_callback, this);

	VfxU32 popupHandle = vcp_global_popup_show_confirm_two_button_str(GRP_ID_ROOT,
							VCP_POPUP_TYPE_WARNING,
					        VFX_WSTR_RES(STR_ID_VAPP_FM_POWER_OFF_FM_Q),
					        VFX_WSTR_RES(STR_GLOBAL_OK),
					        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
					        VCP_POPUP_BUTTON_TYPE_WARNING,
					        VCP_POPUP_BUTTON_TYPE_CANCEL,
					        &vapp_fm_radio_ncell_on_popup_exit,
					        getNotification()
					        ); 
	vadp_fm_radio_set_global_popup_handle(popupHandle);
}


/*****************************************************************************
 * FM Radio Widget Panel Class
 *****************************************************************************/
VappWidgetFmRadioPanel::VappWidgetFmRadioPanel():
	m_state(VADP_FM_RADIO_POWER_OFF),
    m_LCD(NULL),
    m_buttonId(0),
	m_buttonPressed(0),
	m_btnPower(NULL),
    m_btnNext(NULL),
    m_btnPrev(NULL),
	m_seekingPromptTimer(NULL),
	m_seekingDelayTimer(NULL),
	m_isSeekingDone(VFX_FALSE)
{

}

MMI_BOOL VappWidgetFmRadioPanel::backgroundCallback(mdi_result result, void *user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FM_WIDGET_BACKGROUNDCALLBACK, result);

    VappWidgetFmRadioPanel* ptr = (VappWidgetFmRadioPanel*)handleToObject((VfxObjHandle)user_data);

    if(ptr == NULL)
    {
        return MMI_TRUE;
    }

    switch(result)
    {
        /*stop by other app*/
        case MDI_AUDIO_TERMINATED:
        {
            ptr->setState(VADP_FM_RADIO_POWER_OFF);
            break;
        }
		
        case MDI_AUDIO_RESUME:
        {
			ptr->setState(VADP_FM_RADIO_POWER_ON);
            break;
        }

        default:
            break;
    }

    return MMI_TRUE;
}

void VappWidgetFmRadioPanel::generalCallback(mdi_result result, void* user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FM_WIDGET_GENERALCALLBACK, result);

    VappWidgetFmRadioPanel* ptr = (VappWidgetFmRadioPanel*)handleToObject((VfxObjHandle)user_data);

    if(ptr == NULL)
    {
        return;
    }

    switch(result)
    {
        case MDI_AUDIO_TERMINATED:
        {
            ptr->interrupted();
            break;
        }
    }
}

void VappWidgetFmRadioPanel::interrupted(void)
{
    if(m_state != VADP_FM_RADIO_POWER_OFF)
    {
        setState(VADP_FM_RADIO_INTERRUPT);
    }

	#ifdef __MMI_AVRCP_SUPPORT__
		vadp_fm_radio_deregister_avrcp_cmd_callback(getAppId());
	#endif
}

void VappWidgetFmRadioPanel::setState(vadp_fm_radio_state_enum state)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FM_WIDGET_SETSTATE, state);

    m_state = state;

    updateState();

    vadp_fm_radio_update_state(state);

}

void VappWidgetFmRadioPanel::powerOn(void)
{
    mdi_audio_terminate_background_play();

	vadp_fm_radio_set_background_handler();

	U8 appId = getAppId();
	vadp_fm_radio_power_on_with_path(vadp_fm_radio_get_aud_path(), appId);
	
	#ifdef __MMI_AVRCP_SUPPORT__	
		vadp_fm_radio_register_avrcp_cmd_callback(&VappWidgetFmRadioPanel::avrcpCmdCallback, getObjHandle(), appId);
	#endif	

    setState(VADP_FM_RADIO_POWER_ON);
}

void VappWidgetFmRadioPanel::powerOff(void)
{
    if(m_state != VADP_FM_RADIO_INTERRUPT)
    {
        vadp_fm_radio_power_off();
    }

    vadp_fm_radio_clear_background_handler();

	#ifdef __MMI_AVRCP_SUPPORT__
		U8 appId = getAppId();
		vadp_fm_radio_deregister_avrcp_cmd_callback(appId);
		
		// If power off from widget, we need to set btnPower to normal state
		// for can't receive keyup event after deregister_avrcp_cmd_callback func.
		m_btnPower->setState(VCP_BUTTON_STATE_NORMAL);
	#endif // __MMI_AVRCP_SUPPORT__

    setState(VADP_FM_RADIO_POWER_OFF);

}

void VappWidgetFmRadioPanel::ButtonAction(VfxId id)
{
    m_state = vadp_fm_radio_query_state();

	m_buttonPressed = id;
	
	if(m_state == VADP_FM_RADIO_SCANING)
	{
		VfxWString info;
		info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
		return;
	}

	switch(id)
    {
        case BTN_POWER:
        {
            switch(m_state)
            {
                case VADP_FM_RADIO_POWER_ON:
                case VADP_FM_RADIO_SEEKING:
                {
                    powerOff();
                    break;
                }

                case VADP_FM_RADIO_INTERRUPT:
                case VADP_FM_RADIO_POWER_OFF:
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
                    powerOn();
                    break;
                }
            }

            break;
        }

        case BTN_NEXT:
        {
            //go to prev good channel
        #ifndef __FM_RADIO_HW_SEARCH__
            if(m_curFreq == VappWidgetFmRadioPanel::MAX_FREQ)
            {
                return;
            }
        #endif
		
            startSeek(VFX_TRUE);

            break;
        }

        case BTN_PREV:
        {
            //go to prev good channel
        #ifndef __FM_RADIO_HW_SEARCH__
            if(m_curFreq == VappWidgetFmRadioPanel::MIN_FREQ)
            {
                return;
            }
        #endif
		
            startSeek(VFX_FALSE);

            break;
        }

    }
}

void VappWidgetFmRadioPanel::onButtonClicked(VfxObject* obj, VfxId id)
{
    ButtonAction(id);
}

void VappWidgetFmRadioPanel::startSeek(VfxBool forward)
{
    if(m_state != VADP_FM_RADIO_POWER_ON || m_state == VADP_FM_RADIO_SEEKING ||
		m_state == VADP_FM_RADIO_SCANING)
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
	
    vadp_fm_radio_seek((U16)m_curFreq,forward);

    setState(VADP_FM_RADIO_SEEKING);
}

void VappWidgetFmRadioPanel::seekCallback(mdi_fmr_cb_reason_enum result, U16 stop_freq, MMI_BOOL is_valid, void* user_data)
{
    VappWidgetFmRadioPanel* ptr = (VappWidgetFmRadioPanel*)handleToObject((VfxObjHandle)user_data);    
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
		ptr->m_isSeekingDone= VFX_FALSE;
	    ptr->m_LCD->updateChannel();
	}
    else if(result == MDI_FMR_CB_REASON_PROCESS)
    {
        ptr->setFreq((VfxU16)stop_freq);
		return;
    }
    else // MDI_FMR_CB_REASON_DONE
    {	
        ptr->setFreq((VfxU16)stop_freq);		
		if(ptr->m_seekingDelayTimer->getIsEnabled())	// SEEKING_PROMPT_TIME < total < SEEKING_PROMPT_TIME + SEEKING_PROMPT_DURATION_TIME
		{
			ptr->m_isSeekingDone= VFX_TRUE;
		}
		else											// total < SEEKING_PROMPT_TIME or total > SEEKING_PROMPT_TIME + SEEKING_PROMPT_DURATION_TIME
		{
	        ptr->m_LCD->updateChannel();
		}
    }
					
    ptr->setState(VADP_FM_RADIO_POWER_ON);
}

void VappWidgetFmRadioPanel::onSeekingTimeout(VfxTimer *source)
{
	if(source == m_seekingPromptTimer)
	{
		if(m_state != VADP_FM_RADIO_SEEKING)
		{
			return;
		}
		
		m_LCD->showSeekingPrompt(VFX_TRUE);
				
		m_seekingDelayTimer->start();
	}
	else // m_seekingDelayTimer
	{
		if(m_isSeekingDone)
		{
			m_LCD->updateChannel();

			m_isSeekingDone = VFX_FALSE;
		}
	}
}

void VappWidgetFmRadioPanel::setFreq(VfxU16 freq)
{
    if(freq > MAX_FREQ)
    {
        freq = MAX_FREQ;        
    }

    if(freq < MIN_FREQ)
    {
        freq = MIN_FREQ;        
    }

    if(m_curFreq == freq)
    {
        return;
    }

    m_curFreq = freq;

}

void VappWidgetFmRadioPanel::updateState(void)
{
    switch(m_state)
    {
        case VADP_FM_RADIO_POWER_ON:
        case VADP_FM_RADIO_SEEKING:
		case VADP_FM_RADIO_SCANING:
        {
			VfxResId powerOnImage = IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_ON;
            m_btnPower->setImage(VcpStateImage(powerOnImage, powerOnImage, 0, 0));
            m_btnNext->setIsDisabled(VFX_FALSE);
            m_btnPrev->setIsDisabled(VFX_FALSE);
            break;
        }

        case VADP_FM_RADIO_INTERRUPT:
        case VADP_FM_RADIO_POWER_OFF:
        {			
			VfxResId powerOffImage = IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_OFF;			
            m_btnPower->setImage(VcpStateImage(powerOffImage, powerOffImage, 0, 0));
            m_btnNext->setIsDisabled(VFX_TRUE);
            m_btnPrev->setIsDisabled(VFX_TRUE);
            break;
        }
    }

    m_LCD->updateState(m_state);
}

void VappWidgetFmRadioPanel::updateInfo(void)
{
    m_state = vadp_fm_radio_query_state();

    /*fm radio app shall always save current freq when exit screen*/
    m_curFreq = (VfxU16)vadp_fm_radio_get_cur_freq();
}

U8 VappWidgetFmRadioPanel::getAppId()
{
	return VADP_FM_RADIO_NCENTER;
}

void VappWidgetFmRadioPanel::updateChannelBox(void)
{
	if(m_state == VADP_FM_RADIO_SEEKING)
    {
		m_LCD->showSeekingPrompt(VFX_TRUE);				
    }
    else
    {
    	m_LCD->updateChannel();
    }
}
void VappWidgetFmRadioPanel::onLockKeyHandler(VfxTimer *source)
{
	ButtonAction(m_buttonId);
}

VfxBool VappWidgetFmRadioPanel::processKeyEvent(VfxKeyEvent & event, VfxBool is_from_avrcp)
{
	// TODO:
	// kal_prompt_trace(MOD_MMI_MEDIA_APP, "[FM RADIO] VappWidgetFmRadioPanel::processKeyEvent(), m_mode=%d ", m_mode);

	m_state = vadp_fm_radio_query_state();
	if(m_state == VADP_FM_RADIO_SCANING)
	{
		//Pop out balloon "currently not avaiable" only in key down. Do nothing in key up.
		if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
		{
			VfxWString info;
			info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE);
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
		}
		return VFX_FALSE;
	}

    switch (event.keyCode)
    {
        case VFX_KEY_CODE_ENTER:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                m_btnPower->setState(VCP_BUTTON_STATE_PRESSED);
                ButtonAction(BTN_POWER);
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                m_btnPower->setState(VCP_BUTTON_STATE_NORMAL);
            }

            return VFX_TRUE;
        }

        case VFX_KEY_CODE_ARROW_RIGHT:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN && 
				(m_state == VADP_FM_RADIO_POWER_ON || m_state == VADP_FM_RADIO_SEEKING))
            {
				m_buttonId = BTN_NEXT;
            	m_btnNext->setState(VCP_BUTTON_STATE_PRESSED);
				m_keyTimer->start(); 
            }
			else if(event.type == VFX_KEY_EVENT_TYPE_UP && 
				(m_state == VADP_FM_RADIO_POWER_ON || m_state == VADP_FM_RADIO_SEEKING))
            {
                m_btnNext->setState(VCP_BUTTON_STATE_NORMAL);
            }

            return VFX_TRUE;
        }

        case VFX_KEY_CODE_ARROW_LEFT:
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN && 
				(m_state == VADP_FM_RADIO_POWER_ON || m_state == VADP_FM_RADIO_SEEKING))
            {
            	m_buttonId = BTN_PREV;
            	m_btnPrev->setState(VCP_BUTTON_STATE_PRESSED);				
				m_keyTimer->start();     				
            }
			else if(event.type == VFX_KEY_EVENT_TYPE_UP && 
				(m_state == VADP_FM_RADIO_POWER_ON || m_state == VADP_FM_RADIO_SEEKING))
            {
                m_btnPrev->setState(VCP_BUTTON_STATE_NORMAL);
            }

            return VFX_TRUE;
        }        

    }

    return VFX_FALSE;
}


void VappWidgetFmRadioPanel::onDeinit(void)
{
    vadp_fm_radio_set_cur_freq((U16)m_curFreq);

	U8 appId = getAppId();	
    vadp_fm_radio_deregister_general_callback(appId);
    vadp_fm_radio_deregister_background_callback(appId);
    vadp_fm_radio_deregister_seek_callback(appId);

#ifdef __MMI_AVRCP_SUPPORT__
	vadp_fm_radio_deregister_avrcp_cmd_callback(appId);
#endif

	mmi_frm_cb_dereg_event(EVT_ID_VAPP_FM_SCAN_DONE, (mmi_proc_func)&VappWidgetFmRadioPanel::onProc, getObjHandle());

	vadp_fm_radio_close_global_popup(); 
		
    VfxControl::onDeinit();
}

void VappWidgetFmRadioPanel::onInit(void)
{
    VfxControl::onInit();

	createNCenterPanelUI();

	VFX_OBJ_CREATE(m_keyTimer, VfxTimer, this);
	m_keyTimer->setStartDelay(0);
	m_keyTimer->m_signalTick.connect(this, &VappWidgetFmRadioPanel::onLockKeyHandler);
	
	//for seeking	
	VFX_OBJ_CREATE(m_seekingPromptTimer, VfxTimer, this);
	m_seekingPromptTimer->setStartDelay(SEEKING_PROMPT_TIME);
	m_seekingPromptTimer->m_signalTick.connect(this, &VappWidgetFmRadioPanel::onSeekingTimeout);
	
	VFX_OBJ_CREATE(m_seekingDelayTimer, VfxTimer, this);
	m_seekingDelayTimer->setStartDelay(SEEKING_PROMPT_DURATION_TIME);
	m_seekingDelayTimer->m_signalTick.connect(this, &VappWidgetFmRadioPanel::onSeekingTimeout);

    updateInfo();
    updateState();
	updateChannelBox();
	
	U8 appId = getAppId();
	vadp_fm_radio_register_general_callback(&VappWidgetFmRadioPanel::generalCallback, getObjHandle(), appId);
	vadp_fm_radio_register_background_callback((mdi_bg_callback)&VappWidgetFmRadioPanel::backgroundCallback, getObjHandle(), appId);
	vadp_fm_radio_register_seek_callback(&VappWidgetFmRadioPanel::seekCallback, getObjHandle(), appId);
#ifdef __MMI_AVRCP_SUPPORT__
	if(vadp_fm_radio_is_playing()) // If in widget mode, only need to register avrcpCmdCallback when fm is playing.
	{
		vadp_fm_radio_register_avrcp_cmd_callback(&VappWidgetFmRadioPanel::avrcpCmdCallback, getObjHandle(), appId);
	}
#endif

	mmi_frm_cb_reg_event(EVT_ID_VAPP_FM_SCAN_DONE, (mmi_proc_func)&VappWidgetFmRadioPanel::onProc, getObjHandle());
}

void VappWidgetFmRadioPanel::createNCenterPanelUI(void)
{	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_SLIM_WIDGET_CREATE_NCELL_PANEL_UI);

	// set panel region
	VfxSize size = ((VfxFrame*) getParent())->getSize();
	setPos(PN_X, PN_Y);
	setSize(size.width - PN_X*2, PN_HEIGHT);
    setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    //create BG image
    VfxImageFrame* bgImage;
    VFX_OBJ_CREATE(bgImage, VfxImageFrame, this);	
    bgImage->setResId(IMG_ID_VAPP_NCENTER_FMR_BACKGROUND);    
    bgImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bgImage->setSize(getSize());	
    bgImage->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

	//create FM image
    VfxImageFrame* fmImage;
    VFX_OBJ_CREATE(fmImage, VfxImageFrame, this);
    fmImage->setResId(IMG_ID_VAPP_NCENTER_FM_ICON);
    fmImage->setPos(PN_IMAGE_BTN_X,PN_IMAGE_BTN_Y);
    fmImage->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);

	// create FM channel name
    VFX_OBJ_CREATE_EX(m_LCD, VappWidgetFmRadioLcd, this, (this));
    m_LCD->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

	// create previous button
    VFX_OBJ_CREATE(m_btnPrev, VcpButton, this);
	m_btnPrev->setId(BTN_PREV);
	m_btnPrev->setMargin(0,0,0,0);
	m_btnPrev->setPos(PN_BUTTON_X,PN_BUTTON_Y);
	m_btnPrev->setSize(PN_BUTTON_WIDTH, PN_BUTTON_HEIGHT);
    m_btnPrev->setImage(VcpStateImage(IMG_ID_VAPP_NCENTER_FMR_BTN_PREV,IMG_ID_VAPP_NCENTER_FMR_BTN_PREV,IMG_ID_VAPP_NCENTER_FMR_BTN_PREV_D,0));
    m_btnPrev->setBgImageList(VcpStateImage(IMG_ID_VAPP_NCENTER_FMR_BTN_BG_N,IMG_ID_VAPP_NCENTER_FMR_BTN_BG_P,IMG_ID_VAPP_NCENTER_FMR_BTN_BG_N,0));
	m_btnPrev->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnPrev->m_signalClicked.connect(this, &VappWidgetFmRadioPanel::onButtonClicked);
    m_btnPrev->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_NONE);
	m_btnPrev->setFuzzy(VFX_FALSE);

	// create next button
	VFX_OBJ_CREATE(m_btnNext, VcpButton, this);
	m_btnNext->setId(BTN_NEXT);
	m_btnNext->setMargin(0,0,0,0);
	m_btnNext->setAnchor(1.0f,0.0f);
	m_btnNext->setPos(getSize().width - PN_BUTTON_X, PN_BUTTON_Y);
	m_btnNext->setSize(PN_BUTTON_WIDTH, PN_BUTTON_HEIGHT);
    m_btnNext->setImage(VcpStateImage(IMG_ID_VAPP_NCENTER_FMR_BTN_NEXT,IMG_ID_VAPP_NCENTER_FMR_BTN_NEXT,IMG_ID_VAPP_NCENTER_FMR_BTN_NEXT_D,0));
    m_btnNext->setBgImageList(VcpStateImage(IMG_ID_VAPP_NCENTER_FMR_BTN_BG_N,IMG_ID_VAPP_NCENTER_FMR_BTN_BG_P,IMG_ID_VAPP_NCENTER_FMR_BTN_BG_N,0));
	m_btnNext->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnNext->m_signalClicked.connect(this, &VappWidgetFmRadioPanel::onButtonClicked);
    m_btnNext->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);
	m_btnNext->setFuzzy(VFX_FALSE);

	// create power button
	VFX_OBJ_CREATE(m_btnPower, VcpButton, this);
	m_btnPower->setId(BTN_POWER);
	m_btnPower->setMargin(0,0,0,0);
	m_btnPower->setAnchor(0.5f,0.5f);
	m_btnPower->setPos(getSize().width/2, PN_BUTTON_Y + PN_BUTTON_HEIGHT/2);
	m_btnPower->setSize(PN_POWER_BUTTON_WIDTH, PN_POWER_BUTTON_HEIGHT);
	m_btnPower->setImage(VcpStateImage(IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_OFF,IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_OFF,0,0));
	m_btnPower->setBgImageList(VcpStateImage(IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_N,IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_P,0,0));
	m_btnPower->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnPower->m_signalClicked.connect(this, &VappWidgetFmRadioPanel::onButtonClicked);	
    m_btnPower->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);
	m_btnPower->setFuzzy(VFX_FALSE);
}

mmi_ret VappWidgetFmRadioPanel::onProc(mmi_event_struct *evt)
{
    VappWidgetFmRadioPanel* panel = (VappWidgetFmRadioPanel*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    if(panel == NULL)
    {
        return MMI_RET_OK;
    }

    switch(evt->evt_id)
    {
    	case EVT_ID_VAPP_FM_SCAN_DONE:
		{
			panel->setState(VADP_FM_RADIO_POWER_ON);

			break;
    	}
		
		default:
			break;
   }

   return MMI_RET_OK;
}

#ifdef __MMI_AVRCP_SUPPORT__
VfxBool VappWidgetFmRadioPanel::avrcpCmdCallback(VfxKeyEvent & event, VfxBool is_from_avrcp, void *user_data)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FM_WIDGET_AVRCP_CMD_CALLBACK, event.keyCode);

	VappWidgetFmRadioPanel* ptr = (VappWidgetFmRadioPanel*)handleToObject((VfxObjHandle)user_data);
	if(ptr != NULL)
	{
		return ptr->processKeyEvent(event, is_from_avrcp);
	}

	return VFX_FALSE;
}
#endif


/*****************************************************************************
 * FM Radio Widget LCD Class
 *****************************************************************************/
VappWidgetFmRadioLcd::VappWidgetFmRadioLcd(VappWidgetFmRadioPanel *fmPanel):
    m_channel(NULL),
    m_seekingPrompt(NULL),
    m_panel(fmPanel)
{

}

void VappWidgetFmRadioLcd::onInit()
{
    VfxControl::onInit();

	createNCenterLcdUI();
}

void VappWidgetFmRadioLcd::createNCenterLcdUI(void)
{
	// create channel
    VFX_OBJ_CREATE(m_channel,VfxTextFrame,this);
    m_channel->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VappWidgetFmRadioPanel::PN_CHANNEL_FONT_SIZE)));

	//Seeking prompt
    VFX_OBJ_CREATE(m_seekingPrompt,VfxTextFrame,this);
    m_seekingPrompt->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VappWidgetFmRadioPanel::PN_CHANNEL_FONT_SIZE)));
	m_seekingPrompt->setString(VFX_WSTR_RES(STR_ID_VAPP_FM_SEARCHING));
	m_seekingPrompt->setHidden(VFX_TRUE);

	VfxSize size = ((VfxFrame*) getParent())->getSize();
	setPos(VappWidgetFmRadioPanel::PN_CHANNEL_TEXT_X, VappWidgetFmRadioPanel::PN_CHANNEL_TEXT_Y);
	setSize((size.width - VappWidgetFmRadioPanel::PN_CHANNEL_TEXT_X*2), m_channel->getSize().height);
}

void VappWidgetFmRadioLcd::updateChannel(void)
{
	VfxU16 curFreq = m_panel->m_curFreq;
	VfxWChar* name = (VfxWChar*)vapp_fm_radio_get_fav_name(curFreq);

	VfxWString str;
	if(name != NULL)
	{
		str = VFX_WSTR_MEM(name);
	}
	else
	{
		//str.format("FM %.1f", ((VfxFloat)curFreq/10));
		str.format("FM %d.%d", curFreq/10, curFreq%10);
	}
	
    m_channel->setString(str);
	showSeekingPrompt(VFX_FALSE); 
}

void VappWidgetFmRadioLcd::showSeekingPrompt(VfxBool isShow)
{
	m_seekingPrompt->setHidden(!isShow);
    m_channel->setHidden(isShow);	
}

void VappWidgetFmRadioLcd::updateState(vadp_fm_radio_state_enum state)
{
	switch(state)
	{
	    case VADP_FM_RADIO_INTERRUPT:
	    case VADP_FM_RADIO_POWER_OFF:
	    {
			updateChannel();
	        break;
	    }
	}
}

#ifdef __cplusplus
}
#endif

#endif // defined(__MMI_NCENTER_SUPPORT__)

#endif /* __MMI_FM_RADIO_SLIM__ */
