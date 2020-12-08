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
*  vapp_sound_settings.cpp
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Cosmos sound settings file
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 *
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

extern "C"
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif
}

#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_features.h"
#include "ProfilesSrv.h" 
#include "MMIDataType.h"
#include "SimCtrlSrvGprot.h"
#include "mdi_audio.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "mmi_rp_srv_venus_component_menu_popup_def.h"
#include "mmi_rp_vapp_sound_settings_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "USBSrvGProt.h"
#include "Filemgrcuigprot.h"
#include "GlobalConstants.h"
#include "Wgui_categories_util.h"
#include "Gui_typedef.h"
#ifdef __cplusplus
}
#endif

#include "vapp_sound_settings_gprot.h"
#include "vcui_tone_selector.h"
#include "vapp_sound_settings.h"
#include "vcp_popup.h"
#include "vapp_vol_dialog_gprot.h"

#include "Vapp_usb_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
VappSetVolumePopup* VappSetVolumePopup::m_self = NULL;

/*****************************************************************************
 * Function
 *****************************************************************************/

#ifdef __BT_SPK_VOL_CONTROL__
static MMI_BOOL vapp_volume_popup_hfp_sync_callback(U8 volume, MMI_BOOL is_mute)
{
	VappSetVolumePopup::onBtVolHfp(volume);
    return MMI_TRUE;
}
#endif


void vapp_sound_settings_launch(VfxMainScr* scr)
{
//DCM
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
    DCM_Load(DYNAMIC_CODE_COMPRESS_SOUNDSET, 0, 0);
#endif


#ifdef __MMI_USB_SUPPORT__
    if(srv_usb_is_in_mass_storage_mode())
    {
        vapp_usb_unavailable_popup(0);
        return;
    }
#endif

    VfxAppLauncher::launch( 
        VAPP_SOUND_SETTINGS, 
        VFX_OBJ_CLASS_INFO(VappSoundSettings),
        GRP_ID_ROOT);

}

#ifdef __SIM_HOT_SWAP_SUPPORT__
mmi_ret vapp_sound_settings_sim_ctrl_change_detected_hdlr(mmi_event_struct *evt)
{
	srv_sim_ctrl_event_detected_evt_struct *sim_ctrl_evt = (srv_sim_ctrl_event_detected_evt_struct *)evt;

    switch(sim_ctrl_evt->evt_id)
    {
    	case EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED:
        {			
			if (SRV_SIM_CTRL_EVENT_DET_REMOVED == sim_ctrl_evt->type || 
				SRV_SIM_CTRL_EVENT_DET_INSERTED == sim_ctrl_evt->type || 
				SRV_SIM_CTRL_EVENT_DET_RECOVERY_START == sim_ctrl_evt->type || 
				SRV_SIM_CTRL_EVENT_DET_RECOVERY_END == sim_ctrl_evt->type)
			{
				VfxApp *app = VfxAppLauncher::findApp(
								VAPP_SOUND_SETTINGS,
								VFX_OBJ_CLASS_INFO(VappSoundSettings),
								VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);
				if (app)
				{
					VfxAppLauncher::terminate(app->getGroupId());
				}
			}
			break;
        }
		default:
        	break;
    }
	
	return MMI_RET_OK;
}
#endif

static MMI_BOOL vapp_prof_get_ext_file_slot(U16 profile_id, srv_prof_settings_enum setting, U8 * slot)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = SRV_PROF_EXT_MELODY_NUM;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (setting)
    {
        case SRV_PROF_SETTINGS_MT_CALL_TONE:
        {
            i = INCOMING_SIM1_EXT_SLOT;
            break;
        }
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        case SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE:
        {
            i = INCOMING_SIM2_EXT_SLOT;
            break;
        }
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        case SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE:
        {
            i = INCOMING_SIM3_EXT_SLOT;
            break;
        }
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        case SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE:
        {
            i = INCOMING_SIM4_EXT_SLOT;
            break;
        }
    #endif
    #endif
    #endif

		case SRV_PROF_SETTINGS_MMS_TONE:
		{
			i = MESSAGE_SIM1_EXT_SLOT;
            break;
		}
	#if (SRV_PROF_SMS_TONE_AMOUNT > 1)
		case SRV_PROF_SETTINGS_MMS_CARD2_TONE:
		{
			i = MESSAGE_SIM2_EXT_SLOT;
            break;
		}
	#endif
	
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
        case SRV_PROF_SETTINGS_EMAIL_TONE:
		{
			i = MAIL_SIM1_EXT_SLOT;
            break;
		}
    #endif
	#if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
        case SRV_PROF_SETTINGS_EMAIL_CARD2_TONE:
		{
			i = MAIL_SIM2_EXT_SLOT;
            break;
		}
	#endif
        default:
            return MMI_FALSE;
    }
    if (profile_id == SRV_PROF_PROFILE_1)
    {
        *slot = i;
    }
    else
    {
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}

static U8 vapp_prof_srv_event_handler(srv_prof_cb_enum event, void* input, void* output)
{
	U8 result = SRV_PROF_RET_SUCCESS;
    srv_prof_settings_enum setting;
	switch (event)
    {
        case SRV_PROF_CB_SLOT_QUERY:
        {
            setting = (srv_prof_settings_enum)*(U16*)input;
            if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) > 0)
            {
            	//silent on
                return (U8)SRV_PROF_RET_SETTING_NOT_SUPPORTED;
            }
            if (setting == SRV_PROF_SETTINGS_MT_CALL_TONE
                || setting == SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE
                || setting == SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE
                || setting == SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE
                || setting == SRV_PROF_SETTINGS_MMS_TONE
                || setting == SRV_PROF_SETTINGS_MMS_CARD2_TONE
                || setting == SRV_PROF_SETTINGS_EMAIL_TONE
                || setting == SRV_PROF_SETTINGS_EMAIL_CARD2_TONE
                )
            {
                vapp_prof_get_ext_file_slot(srv_prof_get_activated_profile(), setting, (U8*)output);
            }
            else
            {
                result = (U8)SRV_PROF_RET_SETTING_NOT_SUPPORTED;
            }
            break;
        }
        default:
            break;
    }
    return result;
}

void vapp_sound_settings_update_status_icon(void)
{
    VfxU8 vol;
    vol = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_ring_vol());
    VfxBool silent = vol == VappSetVolumePopup::VOL_0 ;
    MMI_BOOL vibrate = srv_prof_if_can_vibrate();

    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SILENT);
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_VIBRATION);
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_VIBRATE_AND_RING);

    if(silent && !vibrate )
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_SILENT);
    }
    else if(silent && vibrate)
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_VIBRATION);
    }
    else if(!silent && vibrate)
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_VIBRATE_AND_RING);
    }

    wgui_status_icon_bar_update();

}

mmi_ret vapp_sound_settings_init(mmi_event_struct *evt)
{
    U8 count;

    vapp_sound_settings_update_status_icon();

    srv_prof_setting_struct settings_normal;
    srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings_normal);

    srv_prof_setting_struct settings_silent;
    srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings_silent);

	//sync the msg volume with ring volume
	settings_normal.msg_vol = settings_normal.ring_vol;

#ifdef __MMI_UNIQUE_MEDIA_VOL__
    settings_silent.media_vol = settings_normal.media_vol;
#endif
    settings_silent.vibrate = settings_normal.vibrate;

#if (SRV_PROF_SMS_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_SMS_TONE_AMOUNT; count++)
    {
        settings_silent.sms_tone[count] = settings_normal.sms_tone[count];
    }
#endif

    /* mms tone */
#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_MMS_TONE_AMOUNT; count++)
    {
        settings_silent.mms_tone[count] = settings_normal.mms_tone[count];
    }
#endif

    /* email tone */
#if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_EMAIL_TONE_AMOUNT; count++)
    {
        settings_silent.email_tone[count] = settings_normal.email_tone[count];
    }
#endif

    /* voice tone */
#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_VOICE_TONE_AMOUNT; count++)
    {
        settings_silent.voice_tone[count] = settings_normal.voice_tone[count];
    }
#endif

    /* mt call tone */
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_MT_CALL_TONE_AMOUNT; count++)
    {
        settings_silent.mt_call_tone[count] = settings_normal.mt_call_tone[count];
    }
#endif

    /* vt call tone */
#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_VT_CALL_TONE_AMOUNT; count++)
    {
        settings_silent.vt_call_tone[count] = settings_normal.vt_call_tone[count];
    }
#endif

    srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings_normal);

    srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings_silent);

	srv_prof_register_app_callback((srv_profiles_notify_callback)vapp_prof_srv_event_handler);

    return MMI_RET_OK;

}
#ifdef __cplusplus
}
#endif

/*
//DCM
*/

#pragma arm section code = "DYNAMIC_CODE_SOUNDSET_ROCODE", rodata = "DYNAMIC_CODE_SOUNDSET_RODATA"


VFX_IMPLEMENT_CLASS("VappSoundSettings", VappSoundSettings, VfxApp);

VappSoundSettings::VappSoundSettings():
    m_form(NULL),
    m_mainPage(NULL),
    m_toneSelectorCui(0) 
{

}

void VappSoundSettings::onInit(void)
{
    VfxApp::onInit();
    registerCBEvent(EVT_ID_VOL_DIALOG_VIB_CHANGED, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_PROF_PROFILE_SWITCHED, VFX_TRUE);
	
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_TRUE);
#endif
}

void VappSoundSettings::onDeinit(void)
{
    registerCBEvent(EVT_ID_VOL_DIALOG_VIB_CHANGED, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_PROF_PROFILE_SWITCHED, VFX_FALSE);
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_FALSE);
#endif
    VfxApp::onDeinit();

//DCM
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_SOUNDSET);
#endif

}

void VappSoundSettings::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappSoundSettingsScreen *scr;
    VFX_OBJ_CREATE(scr, VappSoundSettingsScreen, this);
    scr->setTransitType(VFX_SCR_TRANSIT_TYPE_CUI);
    scr->show();
}

void VappSoundSettings::onSelectedResult(VfxU32 type, VfxU16 ring_tone)
{
	srv_prof_setting_struct settings_normal;
	srv_prof_setting_struct settings_silent;
	
	srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings_normal);
	srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings_silent);

	switch(type)
	{
		case VappSoundSettingsMainPage::INCOMING_SIM1_L:
		{
			settings_normal.mt_call_tone[0] = ring_tone;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_normal.vt_call_tone[0] = ring_tone;
		#endif
		
			settings_silent.mt_call_tone[0] = ring_tone;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_silent.vt_call_tone[0] = ring_tone;
		#endif
			break;
		}
		
	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
		case VappSoundSettingsMainPage::INCOMING_SIM2_L:
		{
			settings_normal.mt_call_tone[1] = ring_tone;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_normal.vt_call_tone[1] = ring_tone;
		#endif
		
			settings_silent.mt_call_tone[1] = ring_tone;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_silent.vt_call_tone[1] = ring_tone;
		#endif
			break;
		}
	#endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
		case VappSoundSettingsMainPage::INCOMING_SIM3_L:
		{
			settings_normal.mt_call_tone[2] = ring_tone;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_normal.vt_call_tone[2] = ring_tone;
		#endif
		
			settings_silent.mt_call_tone[2] = ring_tone;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_silent.vt_call_tone[2] = ring_tone;
		#endif
			break;
		}
	#endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
		case VappSoundSettingsMainPage::INCOMING_SIM4_L:
		{
			settings_normal.mt_call_tone[3] = ring_tone;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_normal.vt_call_tone[3] = ring_tone;
		#endif
		
			settings_silent.mt_call_tone[3] = ring_tone;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_silent.vt_call_tone[3] = ring_tone;
		#endif
			break;
		}
	#endif

		case VappSoundSettingsMainPage::MESSAGE_SIM1_L:
		{
			settings_normal.sms_tone[0] = ring_tone;
		#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
			settings_normal.mms_tone[0] = ring_tone;
		#endif
		#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
			settings_normal.voice_tone[0] = ring_tone;
		#endif
			
			settings_silent.sms_tone[0] = ring_tone;
		#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
			settings_silent.mms_tone[0] = ring_tone;
		#endif
		#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
			settings_silent.voice_tone[0] = ring_tone;
		#endif
			break;
		}

	#if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
		case VappSoundSettingsMainPage::MAIL_SIM1_L:
		{
			settings_normal.email_tone[0] = ring_tone;
			settings_silent.email_tone[0] = ring_tone;
		}
	#endif
	}
	
	srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings_normal);
	srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings_silent);

}

mmi_ret VappSoundSettings::onProc(mmi_event_struct* evt)
{
    VfxApp::onProc(evt);

    switch(evt->evt_id)
    {
        case EVT_ID_VOL_DIALOG_VIB_CHANGED:
        {
            m_mainPage->vibSwitched();
        }

        case EVT_ID_SRV_PROF_PROFILE_SWITCHED:
        {
            m_mainPage->profileSwitched();
            break;
        }
		
	#ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            this->exit();
            break;
        }
	#endif

        case EVT_ID_VCUI_TONE_SELECTOR_CLOSE_REQUEST:
        {
            mmi_group_event_struct* evt_cui = (mmi_group_event_struct*)evt;
            VFX_ASSERT(m_toneSelectorCui == evt_cui->sender_id);
            vcui_tone_selector_close(m_toneSelectorCui);
            break;
        }

        case EVT_ID_VCUI_TONE_SELECTOR_RESULT:
        {
            vcui_tone_selector_evt_struct* evt_cui = (vcui_tone_selector_evt_struct*)evt;
            VFX_ASSERT(m_toneSelectorCui == evt_cui->sender_id);
            VfxU32 type = (VfxU32)vcui_tone_selector_get_user_data(m_toneSelectorCui);
            VfxResId stringId = 0;
            VfxS32 extId = 0;
            VfxWChar ext_path[SRV_FMGR_PATH_MAX_LEN + 1];

            switch(type)
            {
                case VappSoundSettingsMainPage::INCOMING_SIM1_L:
                {
                    VcpFormItemLauncherCell* Cell = (VcpFormItemLauncherCell*)m_form->getItem(VappSoundSettingsMainPage::INCOMING_SIM1_L);

                    if(evt_cui->is_default_sound)
                    {
						onSelectedResult(type, evt_cui->selected_tone);

                        stringId = (VfxResId)srv_prof_get_string_id_from_srv_audio_id(evt_cui->selected_tone);
                        Cell->setHintText(VFX_WSTR_RES(stringId));
                    }
                    else
                    {
                        mmi_ret result = vcui_tone_selector_get_selected_filepath(m_toneSelectorCui ,NULL, ext_path, SRV_FMGR_PATH_BUFFER_SIZE);
                        if(result != 0)
                        {
                            //error
                            break;
                        }
                        srv_prof_set_file_path_to_ext_melody(INCOMING_SIM1_EXT_SLOT, (WCHAR *)ext_path);
                        extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,INCOMING_SIM1_EXT_SLOT);

						onSelectedResult(type, extId);

                        WCHAR * ext_name_p = srv_fmgr_path_get_filename_ptr(ext_path);

                        if (ext_name_p != NULL)
                        {
                            VfxWChar ext_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
                            mmi_wcscpy(ext_name, ext_name_p);
                            srv_fmgr_path_hide_extension(ext_name);
                            Cell->setHintText(VFX_WSTR_MEM((VfxWChar *)ext_name));
                        }
                        else
                        {
                            Cell->setHintText(VFX_WSTR_EMPTY);
                        }

                    }
                    break;
                }

            #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
                case VappSoundSettingsMainPage::INCOMING_SIM2_L:
                {
                    VcpFormItemLauncherCell* Cell = (VcpFormItemLauncherCell*)m_form->getItem(VappSoundSettingsMainPage::INCOMING_SIM2_L);

                    if(evt_cui->is_default_sound)
                    {
						onSelectedResult(type, evt_cui->selected_tone);

                        stringId = (VfxResId)srv_prof_get_string_id_from_srv_audio_id(evt_cui->selected_tone);
                        Cell->setHintText(VFX_WSTR_RES(stringId));
                    }
                    else
                    {
                        mmi_ret result = vcui_tone_selector_get_selected_filepath(m_toneSelectorCui ,NULL, ext_path, SRV_FMGR_PATH_BUFFER_SIZE);
                        if(result != 0)
                        {
                            //error
                            break;
                        }
                        srv_prof_set_file_path_to_ext_melody(INCOMING_SIM2_EXT_SLOT, (WCHAR *)ext_path);
                        extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,INCOMING_SIM2_EXT_SLOT);

						onSelectedResult(type, extId);

                        WCHAR * ext_name_p = srv_fmgr_path_get_filename_ptr(ext_path);

                        if (ext_name_p != NULL)
                        {
                            VfxWChar ext_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
                            mmi_wcscpy(ext_name, ext_name_p);
                            srv_fmgr_path_hide_extension(ext_name);
                            Cell->setHintText(VFX_WSTR_MEM((VfxWChar *)ext_name));
                        }
                        else
                        {
                            Cell->setHintText(VFX_WSTR_EMPTY);
                        }

                    }

                    break;
                }
            #endif

            #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
                case VappSoundSettingsMainPage::INCOMING_SIM3_L:
                {
                    VcpFormItemLauncherCell* Cell = (VcpFormItemLauncherCell*)m_form->getItem(VappSoundSettingsMainPage::INCOMING_SIM3_L);

                    if(evt_cui->is_default_sound)
                    {
						onSelectedResult(type, evt_cui->selected_tone);

                        stringId = (VfxResId)srv_prof_get_string_id_from_srv_audio_id(evt_cui->selected_tone);
                        Cell->setHintText(VFX_WSTR_RES(stringId));
                    }
                    else
                    {
                        mmi_ret result = vcui_tone_selector_get_selected_filepath(m_toneSelectorCui ,NULL, ext_path, SRV_FMGR_PATH_BUFFER_SIZE);
                        if(result != 0)
                        {
                            //error
                            break;
                        }
                        srv_prof_set_file_path_to_ext_melody(INCOMING_SIM3_EXT_SLOT, (WCHAR *)ext_path);
                        extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,INCOMING_SIM3_EXT_SLOT);

						onSelectedResult(type, extId);

                        WCHAR * ext_name_p = srv_fmgr_path_get_filename_ptr(ext_path);

                        if (ext_name_p != NULL)
                        {
                            VfxWChar ext_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
                            mmi_wcscpy(ext_name, ext_name_p);
                            srv_fmgr_path_hide_extension(ext_name);
                            Cell->setHintText(VFX_WSTR_MEM((VfxWChar *)ext_name));
                        }
                        else
                        {
                            Cell->setHintText(VFX_WSTR_EMPTY);
                        }

                    }

                    break;
                }
            #endif
            
            #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
                case VappSoundSettingsMainPage::INCOMING_SIM4_L:
                {
                    VcpFormItemLauncherCell* Cell = (VcpFormItemLauncherCell*)m_form->getItem(VappSoundSettingsMainPage::INCOMING_SIM4_L);

                    if(evt_cui->is_default_sound)
                    {
						onSelectedResult(type, evt_cui->selected_tone);

                        stringId = (VfxResId)srv_prof_get_string_id_from_srv_audio_id(evt_cui->selected_tone);
                        Cell->setHintText(VFX_WSTR_RES(stringId));
                    }
                    else
                    {
                        mmi_ret result = vcui_tone_selector_get_selected_filepath(m_toneSelectorCui ,NULL, ext_path, SRV_FMGR_PATH_BUFFER_SIZE);
                        if(result != 0)
                        {
                            //error
                            break;
                        }
                        srv_prof_set_file_path_to_ext_melody(INCOMING_SIM4_EXT_SLOT, (WCHAR *)ext_path);
                        extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,INCOMING_SIM4_EXT_SLOT);

						onSelectedResult(type, extId);

                        WCHAR * ext_name_p = srv_fmgr_path_get_filename_ptr(ext_path);

                        if (ext_name_p != NULL)
                        {
                            VfxWChar ext_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
                            mmi_wcscpy(ext_name, ext_name_p);
                            srv_fmgr_path_hide_extension(ext_name);
                            Cell->setHintText(VFX_WSTR_MEM((VfxWChar *)ext_name));
                        }
                        else
                        {
                            Cell->setHintText(VFX_WSTR_EMPTY);
                        }

                    }

                    break;
                }
            #endif

                case VappSoundSettingsMainPage::MESSAGE_SIM1_L:
                {
                    VcpFormItemLauncherCell* Cell = (VcpFormItemLauncherCell*)m_form->getItem(VappSoundSettingsMainPage::MESSAGE_SIM1_L);

                    if(evt_cui->is_default_sound)
                    {
						onSelectedResult(type, evt_cui->selected_tone);

                        stringId = (VfxResId)srv_prof_get_string_id_from_srv_audio_id(evt_cui->selected_tone);
                        Cell->setHintText(VFX_WSTR_RES(stringId));
                    }
                    else
                    {
                        mmi_ret result = vcui_tone_selector_get_selected_filepath(m_toneSelectorCui ,NULL, ext_path, SRV_FMGR_PATH_BUFFER_SIZE);
                        if(result != 0)
                        {
                            //error
                            break;
                        }
                        srv_prof_set_file_path_to_ext_melody(MESSAGE_SIM1_EXT_SLOT, (WCHAR *)ext_path);
                        extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,MESSAGE_SIM1_EXT_SLOT);

						onSelectedResult(type, extId);

                        WCHAR * ext_name_p = srv_fmgr_path_get_filename_ptr(ext_path);

                        if (ext_name_p != NULL)
                        {
                            VfxWChar ext_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
                            mmi_wcscpy(ext_name, ext_name_p);
                            srv_fmgr_path_hide_extension(ext_name);
                            Cell->setHintText(VFX_WSTR_MEM((VfxWChar *)ext_name));
                        }
                        else
                        {
                            Cell->setHintText(VFX_WSTR_EMPTY);
                        }

                    }

                    break;
                }

            #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
                case VappSoundSettingsMainPage::MAIL_SIM1_L:
                {
                    VcpFormItemLauncherCell* Cell = (VcpFormItemLauncherCell*)m_form->getItem(VappSoundSettingsMainPage::MAIL_SIM1_L);

                    if(evt_cui->is_default_sound)
                    {
						onSelectedResult(type, evt_cui->selected_tone);
                        stringId = (VfxResId)srv_prof_get_string_id_from_srv_audio_id(evt_cui->selected_tone);
                        Cell->setHintText(VFX_WSTR_RES(stringId));
                    }
                    else
                    {
                        mmi_ret result = vcui_tone_selector_get_selected_filepath(m_toneSelectorCui ,NULL, ext_path, SRV_FMGR_PATH_BUFFER_SIZE);
                        if(result != 0)
                        {
                            //error
                            break;
                        }
                        srv_prof_set_file_path_to_ext_melody(MAIL_SIM1_EXT_SLOT, (WCHAR *)ext_path);
                        extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,MAIL_SIM1_EXT_SLOT);
						onSelectedResult(type, extId);

                        WCHAR * ext_name_p = srv_fmgr_path_get_filename_ptr(ext_path);

                        if (ext_name_p != NULL)
                        {
                            VfxWChar ext_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
                            mmi_wcscpy(ext_name, ext_name_p);
                            srv_fmgr_path_hide_extension(ext_name);
                            Cell->setHintText(VFX_WSTR_MEM((VfxWChar *)ext_name));
                        }
                        else
                        {
                            Cell->setHintText(VFX_WSTR_EMPTY);
                        }

                    }

                    break;
                }
            #endif

                default:
                    break;

            }

            break;
        }

    default:
        break;
    }

    return MMI_RET_OK;
}

/////////////////////////////////////////////////////////////////////////////////

VappSoundSettingsScreen::VappSoundSettingsScreen()
{}

void VappSoundSettingsScreen::on1stReady()
{
    VfxMainScr::on1stReady();
	//setBgColor(VFX_COLOR_BLACK);

    VappSoundSettingsMainPage *page;

    VFX_OBJ_CREATE(page, VappSoundSettingsMainPage, this);
    pushPage(0,page);

    VappSoundSettings *app;
    app = VFX_OBJ_DYNAMIC_CAST(getApp(),VappSoundSettings);
    
    app->m_mainPage = page;

}

/////////////////////////////////////////////////////////////////////////////////

VappSoundSettingsMainPage::VappSoundSettingsMainPage():
    m_volWeakPtr(NULL) 
{
}

void VappSoundSettingsMainPage::onInit(void)
{
    VfxPage::onInit();

    m_app = (VappSoundSettings*)getApp();

    //Draw Main Page
    drawMainPage();
}

void VappSoundSettingsMainPage::onExit(VfxBool isBackward)
{
    if (m_volWeakPtr.isValid())
    {
        VappSetVolumePopup *volPopup = m_volWeakPtr.get();

        volPopup->stopPreviewTimer();
    }

    VfxPage::onExit(isBackward);
}

void VappSoundSettingsMainPage::onVolButtonClicked(VfxU8 vol)
{
    srv_prof_volume_level ring_vol = (srv_prof_volume_level)vol;
    srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, (void*)&ring_vol);
    srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_MESSAGE_VOL_LEVEL, (void*)&ring_vol);
    vapp_sound_settings_update_status_icon();
}

void VappSoundSettingsMainPage::setToneSelectorParam(
		mmi_id cui_id,
		VfxU32 menu_id,
		VfxResId str_id,
		VfxResId img_id,
		srv_prof_settings_enum setting_item,
		VfxU16 filter_id)
{
	srv_prof_audio_id audio_id;
	
    VfxU16 fileNum = (VfxU16)srv_prof_get_num_of_audio_resource(SRV_PROF_AUDIO_RES_FILE);
    VfxU16 fileStart = (VfxU16)srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,0);
    VfxU16 fileEnd = fileStart + fileNum -1;
	
	srv_prof_get_current_profile_value(setting_item, (void*)&audio_id); 
    if(audio_id >= fileStart && audio_id <= fileEnd)
    {
    	audio_id = 0;
    }
	
	vcui_tone_selector_set_title_id(cui_id, str_id,img_id);
    vcui_tone_selector_set_hightlight_tone(cui_id, audio_id);
    vcui_tone_selector_set_filter(cui_id, filter_id);
    vcui_tone_selector_set_user_data(cui_id,(void*)menu_id);
    vcui_tone_selector_run(cui_id);
}

void VappSoundSettingsMainPage::onLauncher(VcpFormItemCell* sender, VfxId id)
{
    mmi_id gid = m_app->getGroupId();
    VfxU16 filter = 0;
	VfxResId titleId = STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE;
    VCUI_TONE_SELECTOR_FILTER_SET(filter,VCUI_TONE_SELECTOR_FILTER_FILE);

    switch(id)
    {
        case RING_VOL_L:
        {
            VappSetVolumePopup *volPopup;
            VFX_OBJ_CREATE(volPopup, VappSetVolumePopup, this);
            volPopup->setInitVol(MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_ring_vol()));
            volPopup->setTitle(STR_ID_VAPP_SND_SET_RING_VOL_CAP);
            volPopup->m_signalBtnClicked.connect(this,&VappSoundSettingsMainPage::onVolButtonClicked);
            volPopup->show(VFX_TRUE);
            m_volWeakPtr = volPopup;
            break;
        }

        case INCOMING_SIM1_L:
        {
            m_app->m_toneSelectorCui = vcui_tone_selector_create(gid); 
			
            if (srv_sim_ctrl_get_num_of_inserted() > 1)
				titleId = STR_ID_VAPP_SND_SET_SIM1_CAP;
        
            VCUI_TONE_SELECTOR_FILTER_SET(filter,VCUI_TONE_SELECTOR_FILTER_RING);
			setToneSelectorParam(
					m_app->m_toneSelectorCui,
					INCOMING_SIM1_L,
					titleId,
					NULL,
					SRV_PROF_SETTINGS_MT_CALL_TONE,
					filter);

            break;
        }

    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        case INCOMING_SIM2_L:
        {
            m_app->m_toneSelectorCui = vcui_tone_selector_create(gid); 
            if (srv_sim_ctrl_get_num_of_inserted() > 1)
				titleId = STR_ID_VAPP_SND_SET_SIM2_CAP;
			
            VCUI_TONE_SELECTOR_FILTER_SET(filter,VCUI_TONE_SELECTOR_FILTER_RING);
			setToneSelectorParam(
					m_app->m_toneSelectorCui,
					INCOMING_SIM2_L,
					titleId,
					NULL,
					SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,
					filter);
			break;
        }
    #endif

    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        case INCOMING_SIM3_L:
        {
            m_app->m_toneSelectorCui = vcui_tone_selector_create(gid); 
            if (srv_sim_ctrl_get_num_of_inserted() > 1)
				titleId = STR_ID_VAPP_SND_SET_SIM3_CAP;

            VCUI_TONE_SELECTOR_FILTER_SET(filter,VCUI_TONE_SELECTOR_FILTER_RING);
			setToneSelectorParam(
					m_app->m_toneSelectorCui,
					INCOMING_SIM3_L, 
					titleId,
					NULL,
					SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE,
					filter);
			break;
        }
    #endif
    
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        case INCOMING_SIM4_L:
        {
            m_app->m_toneSelectorCui = vcui_tone_selector_create(gid); 
            if (srv_sim_ctrl_get_num_of_inserted() > 1)
				titleId = STR_ID_VAPP_SND_SET_SIM4_CAP;

            VCUI_TONE_SELECTOR_FILTER_SET(filter,VCUI_TONE_SELECTOR_FILTER_RING);
			setToneSelectorParam(
					m_app->m_toneSelectorCui,
					INCOMING_SIM4_L, 
					titleId,
					NULL,
					SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE,
					filter);
			break;
        }
    #endif

        case MESSAGE_SIM1_L:
        {
            m_app->m_toneSelectorCui = vcui_tone_selector_create(gid); 
			titleId = STR_ID_VAPP_SND_SET_MESSAGE_TONE;
            VCUI_TONE_SELECTOR_FILTER_SET(filter,VCUI_TONE_SELECTOR_FILTER_TONE);
			setToneSelectorParam(
					m_app->m_toneSelectorCui,
					MESSAGE_SIM1_L, 
					titleId,
					NULL,
					SRV_PROF_SETTINGS_SMS_TONE,
					filter);
			break;
        }

    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
        case MAIL_SIM1_L:
        {
            m_app->m_toneSelectorCui = vcui_tone_selector_create(gid); 
			titleId = STR_ID_VAPP_SND_SET_MAIL_TONE;
            VCUI_TONE_SELECTOR_FILTER_SET(filter,VCUI_TONE_SELECTOR_FILTER_TONE);
			setToneSelectorParam(
					m_app->m_toneSelectorCui,
					MAIL_SIM1_L, 
					titleId,
					NULL,
					SRV_PROF_SETTINGS_EMAIL_TONE,
					filter);
			break;
        }
    #endif
    }

}

void VappSoundSettingsMainPage::vibSwitched(void)
{
    VcpFormItemSwitchCell* Cell = (VcpFormItemSwitchCell*)m_app->m_form->getItem(SILENT_S);
    Cell = (VcpFormItemSwitchCell*)m_app->m_form->getItem(VIB_S);

    if(srv_prof_if_can_vibrate())
    {
        Cell->setSwitchStatus(VFX_TRUE);
    }
    else
    {
        Cell->setSwitchStatus(VFX_FALSE);
    }

}

void VappSoundSettingsMainPage::profileSwitched(void)
{
    VcpFormItemSwitchCell* Cell = (VcpFormItemSwitchCell*)m_app->m_form->getItem(SILENT_S);

    if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) > 0)
    {
        Cell->setSwitchStatus(VFX_TRUE);
    }
    else
    {
        Cell->setSwitchStatus(VFX_FALSE);
    }

    updateSilent();
}

void VappSoundSettingsMainPage::updateSilent(void)
{
    VfxBool silent_on;

    if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) > 0)
    {
        silent_on = VFX_TRUE;
    }
    else
    {
        silent_on = VFX_FALSE;
    }

    vapp_sound_settings_update_status_icon();

    VcpFormItemBase* item;

    for(VfxU8 i= RING_VOL_L; i<TOTAL_NUM ; i++ )
    {
        item = m_app->m_form->getItem(i);

	#if 0
/* under construction !*/
/* under construction !*/
		#if (SRV_PROF_MT_CALL_TONE_AMOUNT == 1)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
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
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
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
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

        switch(i)
        {
			case RING_VOL_L:
			{
				item->setIsDisabled(silent_on);
				break;
			}
            case NOTI_SOUND_S:
            {
                MMI_BOOL state_noti;
                srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_NOTIFICATION_SOUND, (void*)&state_noti);
                if(silent_on)
                {
                    m_notiSound->setSwitchStatus(VFX_FALSE);
                }
                else
                {
                    m_notiSound->setSwitchStatus(state_noti);
                }
				
				item->setIsDisabled(silent_on);
                break;
            }
            
        #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
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

            case DIAL_PAD_SOUND_S:
            {
                srv_prof_keypad_tone_type_enum state_dial;
                srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE,(void*)&state_dial);
                if(silent_on || state_dial == SRV_PROF_KEYPAD_SILENT)
                {
                    m_dialSound->setSwitchStatus(VFX_FALSE);
                }
                else
                {
                    m_dialSound->setSwitchStatus(VFX_TRUE);
                }
				
				item->setIsDisabled(silent_on);
                break;
            }

            case SYSTEM_ALERT_S:
            {
                MMI_BOOL state_system;
                srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SYSTEM_ALERT,(void*)&state_system);
                if(silent_on)
                {
                    m_systemAlert->setSwitchStatus(VFX_FALSE);
                }
                else
                {
                    m_systemAlert->setSwitchStatus(state_system);
                }
				
				item->setIsDisabled(silent_on);
                break;
            }
            
        #ifndef __MMI_POWER_ON_OFF_MUTE__
            case POWER_ON_OFF_S:
            {
                MMI_BOOL state_power;                
                srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_POWER_ON_OFF_TONE,(void*)&state_power);
                if(silent_on)
                {
                    m_powerSwitch->setSwitchStatus(VFX_FALSE);
                }
                else
                {
                    m_powerSwitch->setSwitchStatus(state_power);
                }
				
				item->setIsDisabled(silent_on);
                break;
            }
        #endif
            
            default:
                break;
        }

    }

}

void VappSoundSettingsMainPage::onSwitchChanged(VcpFormItemSwitchCell* sender, VfxId id, VfxBool on_off)
{
    VFX_UNUSED(sender);

	VfxBool switch_on = VFX_TRUE;

    switch(id)
    {
        case SILENT_S:
        {
            if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) > 0 )
            {
                //on -> off
                srv_prof_activate_profile(SRV_PROF_PROFILE_1);
                switch_on = VFX_FALSE;
            }
            else
            {
                //off -> on
                srv_prof_activate_profile(SRV_PROF_PROFILE_2);
            }
            updateSilent();
            break;
        }

//AT command in service not handled, and srv_prof_register_app_callback
        case VIB_S:
        {
            srv_prof_setting_struct settings;

            if(srv_prof_if_can_vibrate())
            {
                //on -> off
                srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings);
                settings.alert_type = SRV_PROF_ALERT_TYPE_SILENT;
                settings.vibrate = MMI_FALSE;
                srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings);

                srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
                settings.alert_type = SRV_PROF_ALERT_TYPE_RING;
                settings.vibrate = MMI_FALSE;
                srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);

				switch_on = VFX_FALSE;
            }
            else
            {
                //off -> on
                srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings);
                settings.alert_type = SRV_PROF_ALERT_TYPE_VIB_ONLY;
                settings.vibrate = MMI_TRUE;
                srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings);

                srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
                settings.alert_type = SRV_PROF_ALERT_TYPE_VIB_AND_RING;
                settings.vibrate = MMI_TRUE;
                srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);
            }
            vapp_sound_settings_update_status_icon();

            break;
        }

        case NOTI_SOUND_S:
        {
            MMI_BOOL noti_sound;

            if(srv_prof_if_can_ring())
            {
                //on -> off
                noti_sound = MMI_FALSE;
                switch_on = VFX_FALSE;
            }
            else
            {
                //off -> on
                noti_sound = MMI_TRUE;
            }

            srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_NOTIFICATION_SOUND, (void*)&noti_sound);

            break;
        }

    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
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

        case DIAL_PAD_SOUND_S:
        {
            srv_prof_keypad_tone_type_enum dail_sound;
            srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE,(void*)&dail_sound);

            if(dail_sound != SRV_PROF_KEYPAD_SILENT)
            {
                //on -> off
                dail_sound = SRV_PROF_KEYPAD_SILENT;
                switch_on = VFX_FALSE;
            }
            else
            {
                //off -> on
                dail_sound = SRV_PROF_KEYPAD_TONE;
            }
            srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void*)&dail_sound);

            break;
        }        

        case SYSTEM_ALERT_S:
        {
            MMI_BOOL system_alert;
            srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SYSTEM_ALERT,(void*)&system_alert);

            if(system_alert)
            {
                //on -> off
                system_alert = MMI_FALSE;
                switch_on = VFX_FALSE;
            }
            else
            {
                //off -> on
                system_alert = MMI_TRUE;
            }
            srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_SYSTEM_ALERT, (void*)&system_alert);

            break;
        }

    #ifndef __MMI_POWER_ON_OFF_MUTE__
        case POWER_ON_OFF_S:
        {
            MMI_BOOL power_on_off;
            srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_POWER_ON_OFF_TONE,(void*)&power_on_off);

            if(power_on_off)
            {
                //on -> off
                power_on_off = MMI_FALSE;
                switch_on = VFX_FALSE;
            }
            else
            {
                //off -> on
                power_on_off = MMI_TRUE;
            }
            srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_POWER_ON_OFF_TONE, (void*)&power_on_off);
            break;
        }
    #endif

        default:
            break;
    }

	sender->setSwitchStatus(switch_on);
	
}

void VappSoundSettingsMainPage::showToneHint(VcpFormItemLauncherCell *Cell, srv_prof_audio_id audio_id)
{
    VfxU16 index;
    srv_prof_audio_resource_type_enum type ;
    VfxResId stringId;
    VfxWChar ext_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    VfxWChar ext_path[SRV_FMGR_PATH_MAX_LEN + 1];

    type = srv_prof_get_audio_info_from_audio_resourece(audio_id, (U16*)&index);

    if(type == SRV_PROF_AUDIO_RES_FILE)
    {
        if (srv_prof_get_file_path_by_audio_id((WCHAR*)ext_path, audio_id) == SRV_PROF_RET_SUCCESS)
        {
            WCHAR* ext_name_p = srv_fmgr_path_get_filename_ptr(ext_path);

            if (ext_name_p != NULL)
            {
                mmi_wcscpy(ext_name, ext_name_p);
                srv_fmgr_path_hide_extension(ext_name);
                Cell->setHintText(VFX_WSTR_MEM((VfxWChar *)ext_name));
            }
            else
            {
                Cell->setHintText(VFX_WSTR_EMPTY);
            }
        }
    }
    else
    {
        stringId = (VfxResId)srv_prof_get_string_id_from_srv_audio_id(audio_id);
        Cell->setHintText(VFX_WSTR_RES(stringId));
    }

}

VcpFormItemSwitchCell* VappSoundSettingsMainPage::onCreateSwitchMenu(
		VfxS32 menu_item,
		VfxU32 cap_id,
		VfxU32 hint_id,
		VfxBool switch_on)
{
	VcpFormItemSwitchCell *switch_menu;

	VFX_OBJ_CREATE(switch_menu, VcpFormItemSwitchCell, m_app->m_form);
	switch_menu->setMainText(VFX_WSTR_RES(cap_id));
	switch_menu->setHintText(VFX_WSTR_RES(hint_id));
	switch_menu->setSwitchStatus(switch_on);
	switch_menu->m_signalSwitchChangeReq.connect(this, &VappSoundSettingsMainPage::onSwitchChanged);
	m_app->m_form->addItem(switch_menu, menu_item);
	return switch_menu;
}

VcpFormItemLauncherCell* VappSoundSettingsMainPage::onCreateRingToneMenu(
		VfxS32 menu_item,
		VfxResId str_id)
{
	VcpFormItemLauncherCell *sim_menu;
	VFX_OBJ_CREATE(sim_menu, VcpFormItemLauncherCell, m_app->m_form);
	sim_menu->setMainText(VFX_WSTR_RES(str_id));
	sim_menu->m_signalTap.connect(this, &VappSoundSettingsMainPage::onLauncher);
	sim_menu->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	m_app->m_form->addItem(sim_menu, menu_item);
	return sim_menu;
}

void VappSoundSettingsMainPage::drawMainPage(void)
{
    // Title Bar
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SND_SET_TITLE));

    setTopBar(bar);
    VFX_OBJ_CREATE(m_app->m_form, VcpForm, this);

    m_app->m_form->setSize(getSize());
	m_app->m_form->setAlignParent(
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE,
		VFX_FRAME_ALIGNER_MODE_SIDE);

    srv_prof_setting_struct settings;
    srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);

	VfxBool is_switch_on = VFX_FALSE;

    //Silent Switch
    if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) > 0 )
    {
  		is_switch_on = VFX_TRUE;
    }
    else
    {
        is_switch_on = VFX_FALSE;
    }
	onCreateSwitchMenu(
		SILENT_S,
		STR_ID_VAPP_SND_SET_SILENT_CAP,
		STR_ID_VAPP_SND_SET_SILENT_HINT,
		is_switch_on);
	
	
    //Vibration Switch
    if(srv_prof_if_can_vibrate())
    {
        is_switch_on = VFX_TRUE;
    }
    else
    {
        is_switch_on = VFX_FALSE;
    }
	onCreateSwitchMenu(
		VIB_S,
		STR_ID_VAPP_SND_SET_VIB_CAP,
		STR_ID_VAPP_SND_SET_VIB_HINT,
		is_switch_on);

    //Ring Vol Launcher
    VcpFormItemLauncherCell *ring_vol_launcher;
	VFX_OBJ_CREATE(ring_vol_launcher, VcpFormItemLauncherCell, m_app->m_form);
	ring_vol_launcher->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SND_SET_RING_VOL_CAP));
	ring_vol_launcher->setHintText(VFX_WSTR_RES(STR_ID_VAPP_SND_SET_RING_VOL_HINT));
	ring_vol_launcher->m_signalTap.connect(this, &VappSoundSettingsMainPage::onLauncher);
    m_app->m_form->addItem(ring_vol_launcher, RING_VOL_L);

    //Notification Sound Switch
    if(settings.noti_sound)
    {
        is_switch_on = VFX_TRUE;
    }
    else
    {
        is_switch_on = VFX_FALSE;
    }
	m_notiSound = onCreateSwitchMenu(
						NOTI_SOUND_S,
						STR_ID_VAPP_SND_SET_NOTI_SND_CAP,
						STR_ID_VAPP_SND_SET_NOTI_SND_HINT,
						is_switch_on);


#if (SRV_PROF_MT_CALL_TONE_AMOUNT == 1)

	VcpFormItemLauncherCell *incoming_sim1_launcher;
	incoming_sim1_launcher = onCreateRingToneMenu(
									INCOMING_SIM1_L,
									STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE);
	showToneHint(incoming_sim1_launcher, settings.mt_call_tone[0]);

#endif

#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)

	if (srv_sim_ctrl_get_num_of_inserted()== 0)
	{
		VcpFormItemLauncherCell *incoming_sim1_launcher;
		incoming_sim1_launcher = onCreateRingToneMenu(
										INCOMING_SIM1_L,
										STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE);
		showToneHint(incoming_sim1_launcher, settings.mt_call_tone[0]);
	}

	if (srv_sim_ctrl_get_num_of_inserted()== 1)
	{
		//Incoming Call
		if(srv_sim_ctrl_is_inserted(MMI_SIM1))
		{
			VcpFormItemLauncherCell *incoming_sim1_launcher;
			incoming_sim1_launcher = onCreateRingToneMenu(
											INCOMING_SIM1_L,
											STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE);
			showToneHint(incoming_sim1_launcher, settings.mt_call_tone[0]);
		}

		if(srv_sim_ctrl_is_inserted(MMI_SIM2))
		{
			VcpFormItemLauncherCell *incoming_sim2_launcher;
			incoming_sim2_launcher = onCreateRingToneMenu(
											INCOMING_SIM2_L,
											STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE);
			showToneHint(incoming_sim2_launcher, settings.mt_call_tone[1]);
		}

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
		if(srv_sim_ctrl_is_inserted(MMI_SIM3))
		{
			VcpFormItemLauncherCell *incoming_sim3_launcher;
			incoming_sim3_launcher = onCreateRingToneMenu(
											INCOMING_SIM3_L,
											STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE);
			showToneHint(incoming_sim3_launcher, settings.mt_call_tone[2]);
		}
	#endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
		if(srv_sim_ctrl_is_inserted(MMI_SIM4))
		{
			VcpFormItemLauncherCell *incoming_sim4_launcher;
			incoming_sim4_launcher = onCreateRingToneMenu(
											INCOMING_SIM4_L,
											STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE);
			showToneHint(incoming_sim4_launcher, settings.mt_call_tone[3]);
		}
	#endif
	}
#endif

	//New Message SIM1
	VcpFormItemLauncherCell *message_sim1_launcher;
	message_sim1_launcher = onCreateRingToneMenu(
									MESSAGE_SIM1_L,
									STR_ID_VAPP_SND_SET_MESSAGE_TONE);
	showToneHint(message_sim1_launcher,settings.sms_tone[0]);

#if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
	//New Mail SIM1
	VcpFormItemLauncherCell *mail_sim1_launcher;
	mail_sim1_launcher = onCreateRingToneMenu(
								MAIL_SIM1_L,
								STR_ID_VAPP_SND_SET_MAIL_TONE);
	showToneHint(mail_sim1_launcher,settings.email_tone[0]);
#endif

#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
	if (srv_sim_ctrl_get_num_of_inserted() > 1)
	{
		//Incoming Call Caption
		m_app->m_form->addCaption(VFX_WSTR_RES(STR_ID_VAPP_SND_SET_INCOMING_CALL_TITLE),INCOMING_C);

		//Incoming Call SIM1
		if(srv_sim_ctrl_is_inserted(MMI_SIM1))
		{
			VcpFormItemLauncherCell *incoming_sim1_launcher;
			incoming_sim1_launcher = onCreateRingToneMenu(
											INCOMING_SIM1_L,
											STR_ID_VAPP_SND_SET_SIM1_CAP);
			showToneHint(incoming_sim1_launcher,settings.mt_call_tone[0]);
		}

		//Incoming Call SIM2
		if(srv_sim_ctrl_is_inserted(MMI_SIM2))
		{
			VcpFormItemLauncherCell *incoming_sim2_launcher;		
			incoming_sim2_launcher = onCreateRingToneMenu(
											INCOMING_SIM2_L,
											STR_ID_VAPP_SND_SET_SIM2_CAP);
			showToneHint(incoming_sim2_launcher,settings.mt_call_tone[1]);
		}
		
	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
		//Incoming Call SIM3
		if(srv_sim_ctrl_is_inserted(MMI_SIM3))
		{
			VcpFormItemLauncherCell *incoming_sim3_launcher;
			incoming_sim3_launcher = onCreateRingToneMenu(
											INCOMING_SIM3_L,
											STR_ID_VAPP_SND_SET_SIM3_CAP);
			showToneHint(incoming_sim3_launcher,settings.mt_call_tone[2]);
		}
	#endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
		//Incoming Call SIM4
		if(srv_sim_ctrl_is_inserted(MMI_SIM4))
		{
			VcpFormItemLauncherCell *incoming_sim4_launcher;
			incoming_sim4_launcher = onCreateRingToneMenu(
											INCOMING_SIM4_L,
											STR_ID_VAPP_SND_SET_SIM4_CAP);
			showToneHint(incoming_sim4_launcher,settings.mt_call_tone[3]);
		}
	#endif
	}
#endif

    //Device Sound Caption
    m_app->m_form->addCaption(VFX_WSTR_RES(STR_ID_VAPP_SND_SET_DEVICE_SND_CAP),MESSAGE_C);

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
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

    //Dial Pad Sound
    if(settings.keypad_tone_type != SRV_PROF_KEYPAD_SILENT)
    {
        is_switch_on = VFX_TRUE;
    }
    else
    {
        is_switch_on = VFX_FALSE;
    }
	m_dialSound = onCreateSwitchMenu(
						DIAL_PAD_SOUND_S,
						STR_ID_VAPP_SND_SET_DIAL_PAD_CAP,
						STR_ID_VAPP_SND_SET_DIAL_PAD_HINT,
						is_switch_on);

    //System Alert Sound
    if(settings.system_alert)
    {
        is_switch_on = VFX_TRUE;
    }
    else
    {
        is_switch_on = VFX_FALSE;
    }
	m_systemAlert = onCreateSwitchMenu(
						SYSTEM_ALERT_S,
						STR_ID_VAPP_SND_SET_SYSTEM_ALERT_CAP,
						STR_ID_VAPP_SND_SET_SYSTEM_ALERT_HINT,
						is_switch_on);

#ifndef __MMI_POWER_ON_OFF_MUTE__
    //Power On OFF Sound
    if(settings.power_on_off_tone)
    {
        is_switch_on = VFX_TRUE;
    }
    else
    {
        is_switch_on = VFX_FALSE;
    }
	m_powerSwitch = onCreateSwitchMenu(
						POWER_ON_OFF_S,
						STR_ID_VAPP_SND_SET_POWER_SND_CAP,
						STR_ID_VAPP_SND_SET_POWER_SND_HINT,
						is_switch_on);
	m_powerSwitch->setHintText(VFX_WSTR_NULL);
	
#endif

    updateSilent();

}

//DCM
#pragma arm section code, rodata


#ifdef __MMI_SET_AS_RINGTONE_POPUP__

/////////////////////////////////////////////////////////////////////////////////

VFX_IMPLEMENT_CLASS("VappSetAsRingToneCommandPopup", VappSetAsRingToneCommandPopup, VcpCommandPopup);

VappSetAsRingToneCommandPopup::VappSetAsRingToneCommandPopup(const VfxWChar *path)
{
    MMI_ASSERT(path);
    m_path = path;
}

void VappSetAsRingToneCommandPopup::showCommandPopup(void)
{
    setInfoType(VCP_POPUP_TYPE_INFO);
    setText(VFX_WSTR_RES(STR_ID_VAPP_SND_SET_AS_RING_TONE));
	
	if (srv_sim_ctrl_get_num_of_inserted() == 0)
	{
		addItem(BTN_INCOMING_SIM1, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE));
	}

	if (srv_sim_ctrl_get_num_of_inserted() == 1)
	{
	
	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 0)
        if(srv_sim_ctrl_is_inserted(MMI_SIM1))
        {
        	addItem(BTN_INCOMING_SIM1, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE));
    	}
    #endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        if(srv_sim_ctrl_is_inserted(MMI_SIM2))
        {
        	addItem(BTN_INCOMING_SIM2, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE));
    	}
    #endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        if(srv_sim_ctrl_is_inserted(MMI_SIM3))
        {
        	addItem(BTN_INCOMING_SIM3, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE));
    	}
    #endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        if(srv_sim_ctrl_is_inserted(MMI_SIM4))
        {
        	addItem(BTN_INCOMING_SIM4, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_INCOMING_CALL_TONE));
    	}
    #endif
	
	}

	if (srv_sim_ctrl_get_num_of_inserted() > 1)
	{
	
	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 0)
        if(srv_sim_ctrl_is_inserted(MMI_SIM1))
        {
        	addItem(BTN_INCOMING_SIM1, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_SIM1_CAP));
    	}
    #endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        if(srv_sim_ctrl_is_inserted(MMI_SIM2))
        {
        	addItem(BTN_INCOMING_SIM2, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_SIM2_CAP));
    	}
    #endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        if(srv_sim_ctrl_is_inserted(MMI_SIM3))
        {
        	addItem(BTN_INCOMING_SIM3, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_SIM3_CAP));
    	}
    #endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        if(srv_sim_ctrl_is_inserted(MMI_SIM4))
        {
        	addItem(BTN_INCOMING_SIM4, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_SIM4_CAP));
    	}
    #endif
	
	}

    addItem(BTN_MESSAGE_SIM1, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_MESSAGE_TONE));
#if (SRV_PROF_SMS_TONE_AMOUNT > 1)
//    addItem(BTN_MESSAGE_SIM2, VFX_WSTR("SIM 2 message tone"));
#endif

#if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
    addItem(BTN_EMAIL_SIM1, VFX_WSTR_RES(STR_ID_VAPP_SND_SET_MAIL_TONE));
#endif

#if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
//    addItem(BTN_EMAIL_SIM2, VFX_WSTR("SIM 2 Email tone"));
#endif

    addItem(BTN_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

    show(VFX_TRUE);
    m_signalButtonClicked.connect(this, &VappSetAsRingToneCommandPopup::onButtonClicked);

}

void VappSetAsRingToneCommandPopup::onButtonClicked(VfxObject *obj, VfxId id)
{

    U16 extId;
	srv_prof_setting_struct settings_normal;
	srv_prof_setting_struct settings_silent;
	
	srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings_normal);
	srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings_silent);

    switch(id)
    {
        case BTN_INCOMING_SIM1:
        {
            srv_prof_set_file_path_to_ext_melody(INCOMING_SIM1_EXT_SLOT,(WCHAR*)m_path);
            extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,INCOMING_SIM1_EXT_SLOT);

			settings_normal.mt_call_tone[0] = extId;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_normal.vt_call_tone[0] = extId;
		#endif
		
			settings_silent.mt_call_tone[0] = extId;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_silent.vt_call_tone[0] = extId;
		#endif
			break;
        }

    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        case BTN_INCOMING_SIM2:
        {
            srv_prof_set_file_path_to_ext_melody(INCOMING_SIM2_EXT_SLOT,(WCHAR*)m_path);
            extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,INCOMING_SIM2_EXT_SLOT);

			settings_normal.mt_call_tone[1] = extId;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_normal.vt_call_tone[1] = extId;
		#endif
		
			settings_silent.mt_call_tone[1] = extId;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_silent.vt_call_tone[1] = extId;
		#endif
            break;
        }
    #endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        case BTN_INCOMING_SIM3:
        {
            srv_prof_set_file_path_to_ext_melody(INCOMING_SIM3_EXT_SLOT,(WCHAR*)m_path);
            extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,INCOMING_SIM3_EXT_SLOT);

			settings_normal.mt_call_tone[2] = extId;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_normal.vt_call_tone[2] = extId;
		#endif
		
			settings_silent.mt_call_tone[2] = extId;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_silent.vt_call_tone[2] = extId;
		#endif
            break;
        }
    #endif

	#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        case BTN_INCOMING_SIM4:
        {
            srv_prof_set_file_path_to_ext_melody(INCOMING_SIM4_EXT_SLOT,(WCHAR*)m_path);
            extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,INCOMING_SIM4_EXT_SLOT);

			settings_normal.mt_call_tone[3] = extId;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_normal.vt_call_tone[3] = extId;
		#endif
		
			settings_silent.mt_call_tone[3] = extId;
		#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
			settings_silent.vt_call_tone[3] = extId;
		#endif
            break;
        }
    #endif

        case BTN_MESSAGE_SIM1:
        {
            srv_prof_set_file_path_to_ext_melody(MESSAGE_SIM1_EXT_SLOT,(WCHAR*)m_path);
            extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,MESSAGE_SIM1_EXT_SLOT);

			settings_normal.sms_tone[0] = extId;
		#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
			settings_normal.mms_tone[0] = extId;
		#endif
		#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
			settings_normal.voice_tone[0] = extId;
		#endif
			
			settings_silent.sms_tone[0] = extId;
		#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
			settings_silent.mms_tone[0] = extId;
		#endif
		#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
			settings_silent.voice_tone[0] = extId;
		#endif
            break;
        }

    #if (SRV_PROF_SMS_TONE_AMOUNT > 1)
        case BTN_MESSAGE_SIM2:
        {
            srv_prof_set_file_path_to_ext_melody(MESSAGE_SIM2_EXT_SLOT,(WCHAR*)m_path);
            extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,MESSAGE_SIM2_EXT_SLOT);

			settings_normal.sms_tone[1] = extId;
		#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
			settings_normal.mms_tone[1] = extId;
		#endif
		#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
			settings_normal.voice_tone[1] = extId;
		#endif
			
			settings_silent.sms_tone[1] = extId;
		#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
			settings_silent.mms_tone[1] = extId;
		#endif
		#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
			settings_silent.voice_tone[1] = extId;
		#endif
            break;
        }
    #endif

    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
        case BTN_EMAIL_SIM1:
        {
            srv_prof_set_file_path_to_ext_melody(MAIL_SIM1_EXT_SLOT,(WCHAR*)m_path);
            extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,MAIL_SIM1_EXT_SLOT);

			settings_normal.email_tone[0] = extId;
			settings_silent.email_tone[0] = extId;
            break;
        }
    #endif

    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
        case BTN_EMAIL_SIM2:
        {
            srv_prof_set_file_path_to_ext_melody(MAIL_SIM2_EXT_SLOT,(WCHAR*)m_path);
            extId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_FILE,MAIL_SIM2_EXT_SLOT);

			settings_normal.email_tone[1] = extId;
			settings_silent.email_tone[1] = extId;
            break;
        }
    #endif

        case BTN_CANCEL:
        {
            break;
        }
    }
	
	srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings_normal);
	srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings_silent);

    VFX_OBJ_CLOSE(obj);

}
#endif

/////////////////////////////////////////////////////////////////////////////////

VFX_IMPLEMENT_CLASS("VappSetVolumePopup", VappSetVolumePopup, VfxBasePopup);

VappSetVolumePopup::VappSetVolumePopup(void):
    m_volText(NULL),
	m_max(VOL_7),
	m_min(VOL_0),
    m_is_previewing(VFX_FALSE),
	m_vol(VOL_3),
	m_slider(NULL),
	m_previewTimer(NULL)
{
}

void VappSetVolumePopup::onInit(void)
{
    VfxBasePopup::onInit();

	m_self = this;

    setAutoAnimate(VFX_TRUE);
    setBounds(0, 0, POPUP_WIDTH, POPUP_HEIGHT);

    VfxFrame* background_top;
    VFX_OBJ_CREATE(background_top, VfxFrame, this);
    background_top->setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_TITLE_BG));
    background_top->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    background_top->setSize(POPUP_WIDTH, UP_HEIGHT);
	background_top->setIsUnhittable(VFX_TRUE);

    VfxFrame* background_bot;
    VFX_OBJ_CREATE(background_bot, VfxFrame, this);
    background_bot->setImgContent(VfxImageSrc(VCP_IMG_MENU_POPUP_BG));
    background_bot->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    background_bot->setPos(0, UP_HEIGHT);
    background_bot->setSize(POPUP_WIDTH, POPUP_HEIGHT - UP_HEIGHT);
	background_bot->setIsUnhittable(VFX_TRUE);

    //volume text
    VFX_OBJ_CREATE(m_volText, VfxTextFrame, background_top);
    m_volText->setAutoResized(VFX_FALSE);
    m_volText->setSize(POPUP_WIDTH, UP_HEIGHT);
    m_volText->setString(VFX_WSTR_RES(STR_GLOBAL_VOLUME));
    m_volText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE)));
    m_volText->setVerticalToCenter(VFX_TRUE);
    m_volText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    //icon
    VfxImageFrame* vol_icon;
    VFX_OBJ_CREATE(vol_icon,VfxImageFrame,this);
    vol_icon->setResId(IMG_ID_VAPP_VOL_DIALOG_RING);
    vol_icon->setPos(ICON_X,ICON_Y);

    //Slider
    VFX_OBJ_CREATE(m_slider, VcpSlider, this);
    m_slider->setPos(BAR_X, BAR_Y);
    m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_slider->setLength(BAR_LENGTH);
    m_slider->setMaxValue(m_max);
    m_slider->setMinValue(m_min);
    m_slider->setTotalDiscreteStepsForPen(m_max - m_min);
    m_slider->setCurrentValue(m_vol);

    m_slider->m_signalUserChangedValue.connect(this, &VappSetVolumePopup::onSliderMoved);

    VcpButton* btn;
    VFX_OBJ_CREATE(btn, VcpButton, this);
    btn->setText(VFX_WSTR_RES(STR_GLOBAL_OK));
    btn->setPos(BTN_X,BTN_Y);
    btn->setSize(BTN_WIDTH,BTN_HEIGHT);
    btn->m_signalClicked.connect(this,&VappSetVolumePopup::onButtonClicked);

    VFX_OBJ_CREATE(m_previewTimer, VfxTimer, this);
    m_previewTimer->setStartDelay(500);
    m_previewTimer->m_signalTick.connect(this, &VappSetVolumePopup::previewRing);

    vapp_volume_dialog_disappear();
 
}

void VappSetVolumePopup::onEnter()
{
    VfxBasePopup::onEnter();
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(VAPP_SOUND_SETTINGS, MDI_AUD_VOL_LEVEL_EXTEND, vapp_volume_popup_hfp_sync_callback);
#endif

}

void VappSetVolumePopup::onExit()
{
#ifdef __BT_SPK_VOL_CONTROL__
	mdi_audio_bt_clear_volume_sync_callback(VAPP_SOUND_SETTINGS);
#endif
}

void VappSetVolumePopup::onDeinit(void)
{
	m_is_previewing = VFX_FALSE;

    m_self = NULL;
	m_previewTimer = NULL;

	VfxBasePopup::onDeinit();
}

void VappSetVolumePopup::setInitVol(VfxU8 vol)
{
    if(vol > m_max)
    {
        vol = m_max;
    }

    if(vol < m_min)
    {
        vol = m_min;
    }    

    m_vol = vol;

    m_slider->setCurrentValue(m_vol);

}

VfxU8 VappSetVolumePopup::getVol(void)
{
    return m_vol;
}

void VappSetVolumePopup::setTitle(VfxResId id)
{
    m_volText->setString(VFX_WSTR_RES(id));
}

void VappSetVolumePopup::setVolRange(VfxU8 max, VfxU8 min)
{
    m_max = max;
    m_min = min;

    m_slider->setMaxValue(max);
    m_slider->setMinValue(min);
    m_slider->setTotalDiscreteStepsForPen(max-min);
}

void VappSetVolumePopup::previewRingPlayCallback(mdi_result result, void *user_data)
{
    VappSetVolumePopup* ptr = (VappSetVolumePopup*)handleToObject((VfxObjHandle)user_data);

    if(ptr == NULL)
    {
        return;
    }
	ptr->m_is_previewing = VFX_FALSE;
}

void VappSetVolumePopup::previewRing(VfxTimer *source)
{
    if(mdi_audio_is_resource_available(MDI_AUDIO_PLAY_STRING,NULL) || m_is_previewing)
    {
        U8 *audio_data;
        U8 audio_type;
        U32 audio_len;

        audio_data = get_audio(AUD_ID_VAPP_SND_SET_PREVIEW, &audio_type, &audio_len);

        ASSERT(audio_data != NULL);
        
        mdi_audio_play_string_with_vol_path(
                 (void*)audio_data,
                 audio_len,
                 audio_type,
                 MDI_AUDIO_PLAY_ONCE,
                 &VappSetVolumePopup::previewRingPlayCallback,
                 getObjHandle(),
                 MDI_AUD_VOL_MUTE(m_vol),
                 MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2)
                 );

		m_is_previewing = VFX_TRUE;
 
    }
}

void VappSetVolumePopup::stopPreviewTimer(void)
{
    m_previewTimer->stop();
}

void VappSetVolumePopup::onSetVol(VfxKeyCodeEnum keycode)
{
    m_previewTimer->start();
	
	if((keycode == VFX_KEY_CODE_VOL_DOWN) && (m_vol > m_min))
	{
		m_vol --;
	}
	if((keycode == VFX_KEY_CODE_VOL_UP) && (m_vol < m_max))
	{
		m_vol ++;
	}
	
    m_slider->setCurrentValue(m_vol);
}

#ifdef __BT_SPK_VOL_CONTROL__
void VappSetVolumePopup::onBtVolHfp(VfxU8 bt_volume)
{	
    VfxU8 app_volume = 0;
	app_volume = (VfxU8)mdi_audio_bt_get_volume_level_from_type((U8)bt_volume, MDI_AUD_VOL_LEVEL_NORMAL_MUTE);

	if(m_self->m_previewTimer)
		m_self->m_previewTimer->start();
	
	if(m_self->m_vol != app_volume)
		m_self->m_vol = app_volume;
	
    m_self->m_slider->setCurrentValue(app_volume);
}
#endif

VfxBool VappSetVolumePopup::onKeyInput(VfxKeyEvent &event)
{
    switch(event.keyCode)
    {
        case VFX_KEY_CODE_BACK:
        {
            return VFX_TRUE;
        }

        case VFX_KEY_CODE_VOL_DOWN:
		case VFX_KEY_CODE_VOL_UP:
        {
            switch(event.type)
            {
                case KEY_LONG_PRESS:
                case KEY_REPEAT:
                case KEY_EVENT_DOWN:
                {
                    onSetVol(event.keyCode);
                    return VFX_TRUE;
                }

                default:
                    return VFX_TRUE;
            }
        }

    }

    return VfxBasePopup::onKeyInput(event);

}

void VappSetVolumePopup::onSliderMoved(VfxObject *obj, VfxFloat oldval, VfxFloat newval)
{
    m_previewTimer->start();

    if(m_vol == (VfxU8)newval)
    {
        return ;
    }

    m_vol = newval;
}

void VappSetVolumePopup::onButtonClicked(VfxObject *sender, VfxId id)
{
    m_previewTimer->stop();

    m_signalBtnClicked.postEmit(m_vol);

    leave(VFX_TRUE);
}


