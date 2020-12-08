/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_fm_radio.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the cosmos fm radio widget.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FM_RADIO__) || defined(__MMI_NCENTER_SUPPORT__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_fm_radio.h"
#include "mmi_rp_vapp_widget_fm_radio_def.h"
#include "mmi_rp_vapp_fm_radio_def.h"
#include "vcp_include.h"
#include "vapp_vol_dialog_gprot.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "Vfx_adp_device.h"
#include "MMI_media_app_trc.h"
#include "vcp_global_popup.h"

#include "../xml/vfx_xml_loader.h"

/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#include "AppMgrSrvGprot.h" /* To check if fm radio is alive */
#include "GpioSrvGprot.h"
#include "UcmSrvGprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mdi_audio.h"
#include "mmi_rp_srv_prof_def.h"
#include "NotificationGprot.h"

//klawmo
#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif
#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * FM Radio Widget LCD Class
 *****************************************************************************/

VappWidgetFmRadioLcd::VappWidgetFmRadioLcd(VappWidgetFmRadioPanel *fmPanel):
    m_dark(NULL),
    m_highlight(NULL),
    m_channel(NULL),
    m_seekingPrompt(NULL),
	m_panel(fmPanel)    
{

}

void VappWidgetFmRadioLcd::onInit()
{
    VfxControl::onInit();

	if(m_panel->m_mode == VappWidgetFmRadioPanel::MODE_NCENTER)
	{
		#if defined(__MMI_NCENTER_SUPPORT__)
			createNCenterLcdUI();
		#endif
	}
	else
	{
		#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
			createWidgetLcdUI();
		#endif
	}
}

#if defined(__MMI_NCENTER_SUPPORT__)
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
	setSize(size.width - VappWidgetFmRadioPanel::PN_CHANNEL_TEXT_X*2, m_channel->getSize().height);
}
#endif

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
void VappWidgetFmRadioLcd::createWidgetLcdUI(void)
{
	VFX_OBJ_CREATE(m_dark,VfxFrame,this);
    m_dark->setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_FMR_LCD_BG));
    m_dark->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_dark->setSize(LCD_W,LCD_H);

    VFX_OBJ_CREATE(m_highlight,VfxFrame,this);
    m_highlight->setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_FMR_LCD_ON));
    m_highlight->setSize(LCD_W,LCD_H);

	VfxFrame* spot;
    VFX_OBJ_CREATE(spot,VfxFrame,this);
    spot->setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_FMR_LCD_HL));
    spot->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    spot->setSize(LCD_W,LCD_H);

    VFX_OBJ_CREATE(m_channel,VfxTextFrame,this);
    m_channel->setPos(FM_X,FM_Y);
    m_channel->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CHANNEL_FONT_ZISE)));

	//Seeking prompt
    VFX_OBJ_CREATE(m_seekingPrompt,VfxTextFrame,this);
    m_seekingPrompt->setPos(FM_X,FM_Y);
    m_seekingPrompt->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CHANNEL_FONT_ZISE)));
	m_seekingPrompt->setString(VFX_WSTR_RES(STR_ID_VAPP_FM_SEARCHING));
	m_seekingPrompt->setColor(VfxColor(255,21,21,21));
	m_seekingPrompt->setHidden(VFX_TRUE);
}
#endif

void VappWidgetFmRadioLcd::updateChannel(void)
{
	VfxU16 curFreq = m_panel->m_curFreq;
	VfxWChar* name = (VfxWChar*)vapp_fm_radio_get_fav_name(curFreq);

	VfxWString str;
	if((m_panel->m_mode == VappWidgetFmRadioPanel::MODE_NCENTER) && (name != NULL))
	{
		str = VFX_WSTR_MEM(name);
	}
	else
	{
		str.format("FM %.1f", ((VfxFloat)curFreq/10));
	}
	
    m_channel->setString(str);
	showSeekingPrompt(VFX_FALSE); 
}

VfxBool VappWidgetFmRadioLcd::onPenInput(VfxPenEvent & event)
{
    if(m_panel->m_mode != VappWidgetFmRadioPanel::MODE_WIDGET)
    {
        return VfxControl::onPenInput(event);
    }

    switch(event.type)
    {
        case VFX_PEN_EVENT_TYPE_UP:
        {
            srv_appmgr_launch("native.mtk.fmradio");
            break;
        }
    }

    return VFX_TRUE;
}

void VappWidgetFmRadioLcd::showSeekingPrompt(VfxBool isShow)
{
	m_seekingPrompt->setHidden(!isShow);

    m_channel->setHidden(isShow);	
}

void VappWidgetFmRadioLcd::updateState(vadp_fm_radio_state_enum state)
{
	if(m_panel->m_mode == m_panel->MODE_NCENTER)
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
	else
	{
	    switch(state)
	    {
	        case VADP_FM_RADIO_POWER_ON:
	        case VADP_FM_RADIO_SEEKING:
			case VADP_FM_RADIO_SCANING:
	        {
	            m_dark->setHidden(VFX_TRUE);
	            m_highlight->setHidden(VFX_FALSE);
	            m_channel->setColor(VfxColor(255,21,21,21));
	            break;
	        }

	        case VADP_FM_RADIO_INTERRUPT:
	        case VADP_FM_RADIO_POWER_OFF:
	        {
	            m_dark->setHidden(VFX_FALSE);
	            m_highlight->setHidden(VFX_TRUE);
	            m_channel->setColor(VfxColor(255,75,75,75));
				updateChannel();
	            break;
	        }
	    }
	}
}

/*****************************************************************************
 * FM Radio Widget Info Panel Class
 *****************************************************************************/
VappWidgetFmRadioPanel::VappWidgetFmRadioPanel(VfxU8 mode = MODE_WIDGET):
    m_background(NULL),
    m_hole(NULL),
	m_buttonId(0),
	m_btnPower(NULL),
    m_btnNext(NULL),
    m_btnPrev(NULL), 
	m_buttonPressed(0),
	m_keyTimer(NULL),
	m_seekingPromptTimer(NULL),
	m_seekingDelayTimer(NULL),
	m_isSeekingDone(VFX_FALSE),	
#ifdef __MMI_FM_RADIO_RECORD__
	m_startCnf(NULL),
#endif	
    m_state(VADP_FM_RADIO_POWER_OFF),
	m_LCD(NULL),
	m_mode(mode)
{

}

void VappWidgetFmRadioPanel::interrupted(void)
{
    if(m_state != VADP_FM_RADIO_POWER_OFF)
    {
        setState(VADP_FM_RADIO_INTERRUPT);
    }

	#ifdef __MMI_AVRCP_SUPPORT__
		vadp_fm_radio_deregister_avrcp_cmd_callback(getAppId());
	#endif // __MMI_AVRCP_SUPPORT__
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

void VappWidgetFmRadioPanel::onWidgetUpdate(mmi_event_struct *evt, void *user_data)
{
    VappWidgetFmRadioPanel* ptr = (VappWidgetFmRadioPanel*)handleToObject((VfxObjHandle)user_data);

	vadp_fm_radio_state_enum state;
	state = vadp_fm_radio_query_state();
	ptr->setState(state);
}

/*
void VappWidgetFmRadioPanel::pureSetState(vadp_fm_radio_state_enum state)
{
    if(m_state == VADP_FM_RADIO_SEEKING)
    {
        m_curFreq = (VfxU16)vadp_fm_radio_get_cur_freq();
        m_LCD->updateChannel();
    }

    m_state = state;
    updateState();
}
*/

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

	if(MODE_LOCK == m_mode)
    {
        vadp_fm_radio_power_on_with_path(vadp_fm_radio_get_aud_path(), VADP_FM_RADIO_LOCK);
    }
    else
    {
    	U8 appId = getAppId();
        vadp_fm_radio_power_on_with_path(vadp_fm_radio_get_aud_path(), appId);

		#ifdef __MMI_AVRCP_SUPPORT__	
			vadp_fm_radio_register_avrcp_cmd_callback(&VappWidgetFmRadioPanel::avrcpCmdCallback, getObjHandle(), appId);
		#endif // __MMI_AVRCP_SUPPORT__	
    }

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
		if(m_mode != MODE_LOCK)
		{
		    U8 appId = getAppId();
			vadp_fm_radio_deregister_avrcp_cmd_callback(appId);

			// If power off from widget, we need to set btnPower to normal state
			// for can't receive keyup event after deregister_avrcp_cmd_callback func.
			m_btnPower->setState(VCP_BUTTON_STATE_NORMAL);
		}
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

		#ifdef __MMI_FM_RADIO_RECORD__
			vadp_fm_radio_record_state_enum rec_state = vadp_fm_radio_query_rec_state();

            if(rec_state != VADP_FM_RADIO_REC_IDLE && rec_state != VADP_FM_RADIO_REC_DISABLED)
            {
                if(stopRecConfirm())
                {
					m_btnNext->setState(VCP_BUTTON_STATE_NORMAL);
                    return;
                }
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
		
		#ifdef __MMI_FM_RADIO_RECORD__
			vadp_fm_radio_record_state_enum rec_state = vadp_fm_radio_query_rec_state();
			
			if(rec_state != VADP_FM_RADIO_REC_IDLE && rec_state != VADP_FM_RADIO_REC_DISABLED)
            {
                if(stopRecConfirm())
                {
					m_btnPrev->setState(VCP_BUTTON_STATE_NORMAL);
                    return;
                }
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
			VfxResId powerOnImage = NULL;
			if(m_mode == MODE_NCENTER)
			{
				#if defined(__MMI_NCENTER_SUPPORT__)
					powerOnImage = IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_ON;
				#endif
			}
			else
			{	
				#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
					powerOnImage = IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_ON;
				#endif
			}

            m_btnPower->setImage(VcpStateImage(powerOnImage, powerOnImage, 0, 0));
            m_btnNext->setIsDisabled(VFX_FALSE);
            m_btnPrev->setIsDisabled(VFX_FALSE);
            break;
        }

        case VADP_FM_RADIO_INTERRUPT:
        case VADP_FM_RADIO_POWER_OFF:
        {			
			VfxResId powerOffImage = NULL;
			if(m_mode == MODE_NCENTER)
			{
				#if defined(__MMI_NCENTER_SUPPORT__)
					powerOffImage = IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_OFF;
				#endif
			}
			else
			{	
				#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
					powerOffImage = IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_OFF;
				#endif
			}
			
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
	U8 appId = 0;
	switch(m_mode)
	{
		case MODE_WIDGET:
		{
			appId = VADP_FM_RADIO_WIDGET;
			break;
		}
		case MODE_LOCK:
		{
			appId = VADP_FM_RADIO_LOCK;
			break;
		}
		case MODE_NCENTER:
		{
			appId = VADP_FM_RADIO_NCENTER;
			break;
		}
		default:
		{
			ASSERT(0);
		}
	}

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_WIDGET_GET_APP_ID, appId);
	
	return appId;
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

#ifdef __MMI_FM_RADIO_RECORD__
#if defined(__MMI_NCENTER_SUPPORT__)
static void vapp_fm_radio_widget_on_stop_rec_button_clicked(VfxId id, void *userData)
{
	VappWidgetFmRadioPanel *fmNCellPanel = (VappWidgetFmRadioPanel*) userData;	
	fmNCellPanel->onStopRecButtonClicked(fmNCellPanel, id);	
}
#endif

VfxBool VappWidgetFmRadioPanel::stopRecConfirm()
{
	vadp_fm_radio_record_state_enum rec_state = vadp_fm_radio_query_rec_state();
	
	if(rec_state == VADP_FM_RADIO_REC_IDLE || rec_state == VADP_FM_RADIO_REC_DISABLED)
    {
        return VFX_FALSE;
    }

	if(m_startCnf != NULL)
	{
		return VFX_FALSE;
	}

#if defined(__MMI_NCENTER_SUPPORT__)	
	if(m_mode == MODE_NCENTER)
	{
		VfxU32 popupHandle = vcp_global_popup_show_confirm_two_button_str(GRP_ID_ROOT,
								VCP_POPUP_TYPE_QUESTION,
						        VFX_WSTR_RES(STR_ID_VAPP_FM_ASK_STOP_REC),
						        VFX_WSTR_RES(STR_GLOBAL_CONTINUE),
						        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
						        VCP_POPUP_BUTTON_TYPE_NORMAL,
						        VCP_POPUP_BUTTON_TYPE_CANCEL,
						        &vapp_fm_radio_widget_on_stop_rec_button_clicked,
						        this
						        );
		vadp_fm_radio_set_global_popup_handle(popupHandle);
	}
	else		
#endif
	{
		VFX_OBJ_CREATE(m_startCnf, VcpConfirmPopup, this);	
		m_startCnf->setInfoType(VCP_POPUP_TYPE_QUESTION);
		m_startCnf->setText(VFX_WSTR_RES(STR_ID_VAPP_FM_ASK_STOP_REC));
		m_startCnf->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
		m_startCnf->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_CONTINUE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
		m_startCnf->setAutoDestory(VFX_FALSE);
		m_startCnf->show(VFX_TRUE);
		m_startCnf->m_signalButtonClicked.connect(this, &VappWidgetFmRadioPanel::onStopRecButtonClicked);
	}

	return VFX_TRUE;
}

void VappWidgetFmRadioPanel::onStopRecButtonClicked(VfxObject* sender, VfxId btn)
{
    switch(btn)
    {
        //continue
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
			VFX_OBJ_CLOSE(m_startCnf);
			vadp_fm_radio_stop_record(MMI_TRUE);
			if(m_buttonPressed == VappWidgetFmRadioPanel::BTN_NEXT)
			{
				startSeek(VFX_TRUE);
			}
			else if(m_buttonPressed == VappWidgetFmRadioPanel::BTN_PREV)
			{
				startSeek(VFX_FALSE);
			}
            break;
        }

        //cancel
        default:
        {
			VFX_OBJ_CLOSE(m_startCnf);
            break;
        }
    }
	
}

#endif

void VappWidgetFmRadioPanel::onLockKeyHandler(VfxTimer *source)
{
	ButtonAction(m_buttonId);
}

VfxBool VappWidgetFmRadioPanel::onKeyInput(VfxKeyEvent & event)
{	
	if(m_mode != MODE_LOCK)
    {
        return VFX_FALSE;
    }

	return processKeyEvent(event, VFX_FALSE);
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
    if(m_mode == MODE_LOCK)
    {
        unregisterKeyHandler(VFX_KEY_CODE_ENTER);
        unregisterKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
        unregisterKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);
    }
	
    vadp_fm_radio_deregister_general_callback(appId);
    vadp_fm_radio_deregister_background_callback(appId);
    vadp_fm_radio_deregister_seek_callback(appId);

	vadp_fm_radio_deregister_proc_callback(VADP_FM_RADIO_WIDGET);

#ifdef __MMI_AVRCP_SUPPORT__
	vadp_fm_radio_deregister_avrcp_cmd_callback(appId);
#endif // __MMI_AVRCP_SUPPORT__

	mmi_frm_cb_dereg_event(EVT_ID_VAPP_FM_SCAN_DONE, (mmi_proc_func)&VappWidgetFmRadioPanel::onProc, getObjHandle());

	if(m_mode == MODE_NCENTER)
	{
		vadp_fm_radio_close_global_popup(); 
	}
	
    VfxControl::onDeinit();
}

void VappWidgetFmRadioPanel::onInit(void)
{
    VfxControl::onInit();

	if(m_mode == MODE_NCENTER)
	{	
		#if defined(__MMI_NCENTER_SUPPORT__)
			createNCenterPanelUI();
		#endif
	}
	else
	{
		#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
			createWidgetPanelUI();
		#endif
	}

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
	if((m_mode == MODE_LOCK) ||
		vadp_fm_radio_is_playing()) // If in widget mode, only need to register avrcpCmdCallback when fm is playing.
	{
		vadp_fm_radio_register_avrcp_cmd_callback(&VappWidgetFmRadioPanel::avrcpCmdCallback, getObjHandle(), appId);
	}
#endif // __MMI_AVRCP_SUPPORT__

	vadp_fm_radio_register_proc_callback(&VappWidgetFmRadioPanel::onWidgetUpdate, getObjHandle(), VADP_FM_RADIO_WIDGET);

	mmi_frm_cb_reg_event(EVT_ID_VAPP_FM_SCAN_DONE, (mmi_proc_func)&VappWidgetFmRadioPanel::onProc, getObjHandle());
}

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
void VappWidgetFmRadioPanel::createWidgetPanelUI(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_WIDGET_CREATE_WIDGET_PANEL_UI);

    /* Create loader */
    VfxXmlLoader *loader;
    VFX_OBJ_CREATE(loader, VfxXmlLoader, this);
    loader->loadXml(VAPP_WIDGET_FM_LAYOUT_WIDGET);

    m_background = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("background")), VfxImageFrame);
    m_background->setSize(WIDGET_FM_WIDTH,WIDGET_FM_HEIGHT);
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    m_width = m_background->getRect().getWidth();
    m_height = m_background->getRect().getHeight();
	setSize(m_width,m_height);

    m_hole = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("hole")), VfxImageFrame);
    m_width_hole = m_hole->getRect().getWidth();
    m_height_hole = m_hole->getRect().getHeight();
#ifdef __LOW_COST_SUPPORT_COMMON__
	m_hole->setResId(IMG_ID_VAPP_FM_HOLE);
#else
	m_hole->setResId(IMG_ID_VAPP_WIDGET_FMR_HOLE);
#endif
    m_hole->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_hole->setSize(m_width_hole, m_height_hole);

    VfxImageFrame *tempImgFrame = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("LCD")), VfxImageFrame);
    VfxRect rect = tempImgFrame->getRect();

    VFX_OBJ_CREATE_EX(m_LCD, VappWidgetFmRadioLcd, this, (this));
    m_LCD->setSize(tempImgFrame->getRect().getWidth(), tempImgFrame->getRect().getHeight());
    m_LCD->setPos(tempImgFrame->getPos().x,tempImgFrame->getPos().y);

    VFX_OBJ_CLOSE(tempImgFrame);

    /* Create button */
    m_btnPower = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("btn_power")), VcpButton);
    m_btnPower->setId(BTN_POWER);
	m_btnPower->setMargin(0,0,0,0);
    m_btnPower->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_OFF,IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_OFF,0,0));
    m_btnPower->setBgImageList(VcpStateImage(IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_N,IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_P,0,0));
	m_btnPower->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnPower->m_signalClicked.connect(this, &VappWidgetFmRadioPanel::onButtonClicked);
	m_btnPower->setFuzzy(VFX_FALSE);

    VFX_OBJ_CLOSE(tempImgFrame);

    /* Handle Lock mode */
    if(MODE_LOCK == m_mode)
    {
        registerKeyHandler(VFX_KEY_CODE_ENTER);
        registerKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
        registerKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);
    }

	/* Pos of these two buttons are defined based on pos of power button, so it is created after the pos of power button is decided*/
    VFX_OBJ_CREATE(m_btnNext, VcpButton, this);
    m_btnNext->setAnchor(0.0,0.0);
	m_btnNext->setMargin(0,0,0,0);
    m_btnNext->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_FMR_BTN_NEXT,IMG_ID_VAPP_WIDGET_FMR_BTN_NEXT,IMG_ID_VAPP_WIDGET_FMR_BTN_NEXT_D,0));
    m_btnNext->setBgImageList(VcpStateImage(IMG_ID_VAPP_WIDGET_FMR_BTN_BG_N,IMG_ID_VAPP_WIDGET_FMR_BTN_BG_P,IMG_ID_VAPP_WIDGET_FMR_BTN_BG_N,0));
	m_btnNext->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnNext->setSize(PN_BUTTON_W,PN_BUTTON_H);
    m_btnNext->setId(BTN_NEXT);
    VfxS32 posx = m_btnPower->getPos().x + m_btnPower->getSize().width/2 + GAP_NEXT_POWER;
    VfxS32 posy = m_btnPower->getPos().y + (m_btnPower->getSize().height - m_btnNext->getSize().height)/2;
    m_btnNext->setPos(posx,posy);
	m_btnNext->setFuzzy(VFX_FALSE);

    VFX_OBJ_CREATE(m_btnPrev, VcpButton, this);
    m_btnPrev->setAnchor(1.0,0.0);
	m_btnPrev->setMargin(0,0,0,0);
    m_btnPrev->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_FMR_BTN_PREV,IMG_ID_VAPP_WIDGET_FMR_BTN_PREV,IMG_ID_VAPP_WIDGET_FMR_BTN_PREV_D,0));
    m_btnPrev->setBgImageList(VcpStateImage(IMG_ID_VAPP_WIDGET_FMR_BTN_BG_N,IMG_ID_VAPP_WIDGET_FMR_BTN_BG_P,IMG_ID_VAPP_WIDGET_FMR_BTN_BG_N,0));
	m_btnPrev->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_btnPrev->setSize(PN_BUTTON_W,PN_BUTTON_H);
    m_btnPrev->setId(BTN_PREV);
    posx = m_btnPower->getPos().x - m_btnPower->getSize().width/2 - GAP_PREV_POWER;
    m_btnPrev->setPos(posx,posy);
	m_btnPrev->setFuzzy(VFX_FALSE);
    m_btnNext->m_signalClicked.connect(this, &VappWidgetFmRadioPanel::onButtonClicked);
    m_btnPrev->m_signalClicked.connect(this, &VappWidgetFmRadioPanel::onButtonClicked);

    /* Close XML Loader */
    VFX_OBJ_CLOSE(loader);

}
#endif

#if defined(__MMI_NCENTER_SUPPORT__)
void VappWidgetFmRadioPanel::createNCenterPanelUI(void)
{	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_FMRADIO_WIDGET_CREATE_NCELL_PANEL_UI);

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
#endif

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

void VappWidgetFmRadioPanel::setPanelActive(VfxBool is_active)
{
	if(!is_active)
	{
		m_btnPower->setState(VCP_BUTTON_STATE_NORMAL);
		m_btnNext->setState(VCP_BUTTON_STATE_NORMAL);
		m_btnPrev->setState(VCP_BUTTON_STATE_NORMAL);
	}
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

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)

/*****************************************************************************
 * Music Player Widget Class
 *****************************************************************************/
VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidgetFmRadio, VAPP_WIDGET_TYPE_FM_RADIO, VappWidgetFmRadioPublisher);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetFmRadio, VappWidget);
VappWidgetFmRadio::VappWidgetFmRadio()
{
}

#if defined(__MMI_NCENTER_SUPPORT__)
void VappWidgetFmRadio::onInit()
{
    VappWidget::onInit();

    VappNCenter *ncenter =  VFX_OBJ_GET_INSTANCE(VappNCenter);
	if(ncenter != NULL)
	{
		ncenter->m_signalEvent.connect(this, &VappWidgetFmRadio::onNCenterStatusChanged);
	}
}

void VappWidgetFmRadio::onDeinit()
{
    VappNCenter *ncenter =  VFX_OBJ_GET_INSTANCE(VappNCenter);
	if(ncenter != NULL)
	{
		ncenter->m_signalEvent.disconnect(this, &VappWidgetFmRadio::onNCenterStatusChanged);
	}

	VappWidget::onDeinit();
}

void VappWidgetFmRadio::onNCenterStatusChanged(VappNCenterEventEnum evt)
{
    switch (evt)
    {
        case VAPP_NCENTER_EVENT_EXIT:
		{
			if(m_panel != NULL)
			{
	            m_panel->updateInfo();
	    		m_panel->updateState();
				m_panel->updateChannelBox();
			}
            break;
        }
            
        default:
            break;
    }	
}
#endif

VappWidgetId VappWidgetFmRadio::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_FM_RADIO);
}


VfxSize VappWidgetFmRadio::getMaxSize() const
{
    return VfxSize(VappWidgetFmRadioPanel::WIDGET_FM_WIDTH, VappWidgetFmRadioPanel::WIDGET_FM_HEIGHT);
}


VfxS32 VappWidgetFmRadio::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_FMR_RADIO);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetFmRadio::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_FMR_ICON);

    return icon;
}

void VappWidgetFmRadio::onCreateView()
{
    VappWidget::onCreateView();

    VFX_OBJ_CREATE_EX(m_panel, VappWidgetFmRadioPanel, this, (VappWidgetFmRadioPanel::MODE_WIDGET));
}

void VappWidgetFmRadio::onSerializeView(VfxArchive *ar)
{
    VFX_OBJ_CLOSE(m_panel);
}

void VappWidgetFmRadio::onRestoreView(VfxArchive *ar)
{
    VFX_OBJ_CREATE_EX(m_panel, VappWidgetFmRadioPanel, this, (VappWidgetFmRadioPanel::MODE_WIDGET));
}

void VappWidgetFmRadio::onReleaseView()
{
    VFX_OBJ_CLOSE(m_panel);

    VappWidget::onReleaseView();
}

VfxPoint VappWidgetFmRadio::onGetEditButtonOffset(void)
{
    return VfxPoint(VappWidgetFmRadioPanel::WIDGET_FM_WIDTH - VappWidgetFmRadioPanel::WIDGET_FM_GET_BUFFER_OFFSET_X, VappWidgetFmRadioPanel::WIDGET_FM_GET_BUFFER_OFFSET_Y);
}
#endif // defined(__MMI_VUI_WIDGET_FM_RADIO__)

#endif /* defined(__MMI_VUI_WIDGET_FM_RADIO__) || defined(__MMI_NCENTER_SUPPORT__) */

