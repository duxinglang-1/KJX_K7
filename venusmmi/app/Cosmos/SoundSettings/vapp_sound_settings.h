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
*  vapp_sound_settings.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Cosmos sound settings header file
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
 *
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef __SOUND_SETTINGS_H__
#define __SOUND_SETTINGS_H__

extern "C"
{
#include "MMI_features.h"
#include "ProfilesSrv.h" 
}

#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vcp_form.h"
//#include "vcp_page_panel.h"
//#include "vcp_tabctrl_page.h"

/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/

enum
{
        INCOMING_SIM1_EXT_SLOT = 0,
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        INCOMING_SIM2_EXT_SLOT,
#endif
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        INCOMING_SIM3_EXT_SLOT,
#endif
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        INCOMING_SIM4_EXT_SLOT,
#endif
        MESSAGE_SIM1_EXT_SLOT,
#if (SRV_PROF_SMS_TONE_AMOUNT > 1)
        MESSAGE_SIM2_EXT_SLOT,
#endif
#if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
        MAIL_SIM1_EXT_SLOT,
#endif
#if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
        MAIL_SIM2_EXT_SLOT,
#endif
        NUM_OF_SLOT
};

class VappSoundSettings;
class VappSoundSettingsScreen;
class VappSoundSettingsMainPage;
class VappSetVolumePopup;

/***************************************************************************** 
 * Class VappSoundSettings
 *****************************************************************************/
class VappSoundSettings : public VfxApp
{
    VFX_DECLARE_CLASS(VappSoundSettings);

public:
    VcpForm *m_form;
    VappSoundSettingsMainPage *m_mainPage;
    mmi_id m_toneSelectorCui;

protected:
    virtual void onInit(void);
    virtual void onDeinit(void);
    void onSelectedResult(VfxU32 type, VfxU16 ring_tone);

    VappSoundSettings();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *param);
};

/***************************************************************************** 
 * Class VappSoundSettingsScreen
 *****************************************************************************/
class VappSoundSettingsScreen : public VfxMainScr
{

// Override
public:
    VappSoundSettingsScreen(void);
    virtual void on1stReady(void);
};

/***************************************************************************** 
 * Class VappSoundSettingsMainPage
 *****************************************************************************/
class VappSoundSettingsMainPage : public VfxPage
{

public:
    enum
    {
        SILENT_S = 0,
        VIB_S,
        RING_VOL_L,
        NOTI_SOUND_S,
        //INCOMING_C,
        INCOMING_SIM1_L,
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        INCOMING_SIM2_L,
    #endif
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        INCOMING_SIM3_L,
    #endif
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        INCOMING_SIM4_L,
    #endif
        //MESSAGE_C,
        MESSAGE_SIM1_L,
//    #if (SRV_PROF_SMS_TONE_AMOUNT > 1)
//        MESSAGE_SIM2_L,
//    #endif
        //MAIL_C,
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
        MAIL_SIM1_L,
    #endif
//    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
//        MAIL_SIM2_L,
//    #endif
        //DEVICE_SOUND_C,
    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
    #endif
        DIAL_PAD_SOUND_S,
        SYSTEM_ALERT_S,
    #ifndef __MMI_POWER_ON_OFF_MUTE__
        POWER_ON_OFF_S,
    #endif
        TOTAL_NUM,
        INCOMING_C,
        MESSAGE_C,
        MAIL_C,
        DEVICE_SOUND_C
    };

    VappSoundSettings* m_app;

    VfxWeakPtr<VappSetVolumePopup> m_volWeakPtr;

    VcpFormItemSwitchCell *m_notiSound;
    VcpFormItemSwitchCell *m_touchSwitch;
    VcpFormItemSwitchCell *m_touchSound;
    VcpFormItemSwitchCell *m_dialSound;
    VcpFormItemSwitchCell *m_systemAlert;
    VcpFormItemSwitchCell *m_powerSwitch;
public:
    VappSoundSettingsMainPage();
    virtual void onInit(void);
    void profileSwitched(void);
    void vibSwitched(void);
    virtual void onExit(VfxBool isBackward);

private:
    void showToneHint(VcpFormItemLauncherCell *Cell, srv_prof_audio_id audio_id);
    void drawMainPage(void);
    void updateSilent(void);
    void onLauncher(VcpFormItemCell* sender, VfxId Id);
    void onSwitchChanged(VcpFormItemSwitchCell* sender, VfxId Id, VfxBool on_off);
    void onVolButtonClicked(VfxU8 vol);

    void setToneSelectorParam(
            mmi_id cui_id,
            VfxU32 menu_id,
            VfxResId str_id,
            VfxResId img_id,
            srv_prof_settings_enum setting_item,
            VfxU16 filter_id);

    VcpFormItemSwitchCell* onCreateSwitchMenu(
            VfxS32 menu_item,
            VfxU32 cap_id,
            VfxU32 hint_id,
            VfxBool switch_on);
    
    VcpFormItemLauncherCell* onCreateRingToneMenu(
            VfxS32 menu_item,
            VfxResId str_id);

};

#endif
