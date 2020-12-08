/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_sound_settings_gprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __VAPP_SOUND_SETTINGS_GPROT_H__
#define __VAPP_SOUND_SETTINGS_GPROT_H__


#include "vfx_main_scr.h"
#include "vcp_popup.h"
#include "vcp_slider.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_audio.h"

extern void vapp_sound_settings_launch(VfxMainScr* scr);
extern void vapp_sound_settings_update_status_icon(void);

#ifdef __cplusplus
}
#endif

#ifdef __MMI_SET_AS_RINGTONE_POPUP__

class VappSetAsRingToneCommandPopup : public VcpCommandPopup
{
    VFX_DECLARE_CLASS(VappSetAsRingToneCommandPopup);

public:
    enum
    {
        BTN_INCOMING_SIM1,
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        BTN_INCOMING_SIM2,
    #endif
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        BTN_INCOMING_SIM3,
    #endif
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        BTN_INCOMING_SIM4,
    #endif
        BTN_MESSAGE_SIM1,
    #if (SRV_PROF_SMS_TONE_AMOUNT > 1)
        BTN_MESSAGE_SIM2,
    #endif
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
        BTN_EMAIL_SIM1,
    #endif
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
        BTN_EMAIL_SIM2,
    #endif
        BTN_CANCEL
    };

    const VfxWChar *m_path;

    VappSetAsRingToneCommandPopup():
        m_path(NULL)
    {}

    VappSetAsRingToneCommandPopup(const VfxWChar *path);

    void showCommandPopup(void);
    void onButtonClicked(VfxObject *obj, VfxId id);

};

#endif

/***************************************************************************** 
 * Class VappSetVolumePopup
 *****************************************************************************/
class VappSetVolumePopup : public VfxBasePopup
{
    VFX_DECLARE_CLASS(VappSetVolumePopup);

private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        POPUP_WIDTH = 290,
        POPUP_HEIGHT = 161,
        UP_HEIGHT = 25,
        ICON_X = 11,
        ICON_Y = 49,
        BAR_LENGTH = 219,
        BAR_X = 50, 
        BAR_Y = 47,
        BTN_X = 11,
        BTN_Y = 100,
        BTN_WIDTH = 268,
        BTN_HEIGHT = 45,
        TEXT_FONT_SIZE = 15
#elif defined(__MMI_MAINLCD_480X800__)
        POPUP_WIDTH = 446,
        POPUP_HEIGHT = 226,
        UP_HEIGHT = 45,
        ICON_X = 21,
        ICON_Y = 68, //70
        BAR_LENGTH = 338,
        BAR_X = 87, 
        BAR_Y = 72,
        BTN_X = 21,
        BTN_Y = 131,
        BTN_WIDTH = 404,
        BTN_HEIGHT = 70,
        TEXT_FONT_SIZE = 24
#elif defined(__MMI_MAINLCD_240X400__)
        POPUP_WIDTH = 222,
        POPUP_HEIGHT = 130,
        UP_HEIGHT = 20,
        ICON_X = 8,
        ICON_Y = 34,
        BAR_LENGTH = 175,
        BAR_X = 39,
        BAR_Y = 36,
        BTN_X = 8,
        BTN_Y = 74,
        BTN_WIDTH = 206,
        BTN_HEIGHT = 40,
        TEXT_FONT_SIZE = 13
#else  //if defined(__MMI_MAINLCD_240X320__)
        POPUP_WIDTH = 222,
        POPUP_HEIGHT = 130,
        UP_HEIGHT = 20,
        ICON_X = 8,
        ICON_Y = 34,
        BAR_LENGTH = 175,
        BAR_X = 39,
        BAR_Y = 36,
        BTN_X = 8,
        BTN_Y = 74,
        BTN_WIDTH = 206,
        BTN_HEIGHT = 40,
        TEXT_FONT_SIZE = 13
#endif
    };

public:
    enum
    {
        VOL_0,
        VOL_1,
        VOL_2,
        VOL_3,
        VOL_4,
        VOL_5,
        VOL_6,
        VOL_7
    };

private:
    VfxTextFrame* m_volText;
    VfxU8 m_max;
    VfxU8 m_min;

public:
    VfxSignal1 <VfxU8> m_signalBtnClicked;
    VfxBool m_is_previewing;
    VfxU8 m_vol;
    VcpSlider* m_slider;
    VfxTimer *m_previewTimer;
    static VappSetVolumePopup *m_self;

protected:
    virtual void onInit(void);
    virtual void onDeinit(void);
    virtual void onEnter();
    virtual void onExit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    void onSliderMoved(VfxObject *obj, VfxFloat oldval, VfxFloat newval);
    void onButtonClicked(VfxObject *sender, VfxId id);

    void previewRing(VfxTimer *source);
    void onSetVol(VfxKeyCodeEnum keycode);
    static void previewRingPlayCallback(mdi_result result, void *user_data);

public:
    void setInitVol(VfxU8 vol);
    VfxU8 getVol(void);
    void setTitle(VfxResId id);
    void setVolRange(VfxU8 max, VfxU8 min);
    void stopPreviewTimer(void);
#ifdef __BT_SPK_VOL_CONTROL__
    static void onBtVolHfp(VfxU8 bt_volume);
#endif
    VappSetVolumePopup();

};



#endif /* __VAPP_SOUND_SETTINGS_GPROT_H__ */

