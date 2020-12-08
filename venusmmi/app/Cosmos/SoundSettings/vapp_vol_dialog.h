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
 *   vapp_vol_dialog.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Volume Dialog header file
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __VOLUME_DIALOG_H__
#define __VOLUME_DIALOG_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_frame_effect.h"
#include "Vapp_vol_dialog_gprot.h"

/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/
class VappVolumeDialog;

/***************************************************************************** 
 * Class VappSoundSettings
 *****************************************************************************/
class VappVolumeDialog : public VfxControl
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappVolumeDialog);

public:

    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        VOL_DIALOG_WIDTH = 284,
        VOL_DIALOG_HEIGHT = 110,
        VOL_DIALOG_X = LCD_WIDTH/2,
        VOL_DIALOG_Y = LCD_HEIGHT/2,
        TITLE_X = VOL_DIALOG_WIDTH/2,
        TITLE_Y = 42,
        ICON_X = 17,
        ICON_Y = 22,
        BAR_X = VOL_DIALOG_WIDTH/2,
        BAR_Y = 81,
        BAR_LENGTH = VOL_DIALOG_WIDTH - 17*2,
        TEXT_FONT_SIZE = 18,
        ROTATE_EXTND_SIZE = 50
#elif defined(__MMI_MAINLCD_480X800__)
        VOL_DIALOG_WIDTH = 446,
        VOL_DIALOG_HEIGHT = 181,
        VOL_DIALOG_X = LCD_WIDTH/2,
        VOL_DIALOG_Y = LCD_HEIGHT/2,
        TITLE_X = VOL_DIALOG_WIDTH/2,
        TITLE_Y = 68,
        ICON_X = 31,
        ICON_Y = 37,
        BAR_X = VOL_DIALOG_WIDTH/2,
        BAR_Y = 125,
        BAR_LENGTH = VOL_DIALOG_WIDTH - 31*2,
        TEXT_FONT_SIZE = 30,
        ROTATE_EXTND_SIZE = 75
#elif defined(__MMI_MAINLCD_240X400__)
        VOL_DIALOG_WIDTH = 222,
        VOL_DIALOG_HEIGHT = 92,
        VOL_DIALOG_X = LCD_WIDTH/2,
        VOL_DIALOG_Y = LCD_HEIGHT/2,
        TITLE_X = VOL_DIALOG_WIDTH/2,
        TITLE_Y = 30,
        ICON_X = 14,
        ICON_Y = 14,
        BAR_X = VOL_DIALOG_WIDTH/2,
        BAR_Y = 60,
        BAR_LENGTH = VOL_DIALOG_WIDTH - 14*2,
        TEXT_FONT_SIZE = 16,
        ROTATE_EXTND_SIZE = 37
#else//if defined(__MMI_MAINLCD_240X320__)
        VOL_DIALOG_WIDTH = 222,
        VOL_DIALOG_HEIGHT = 92,
        VOL_DIALOG_X = LCD_WIDTH/2,
        VOL_DIALOG_Y = LCD_HEIGHT/2,
        TITLE_X = VOL_DIALOG_WIDTH/2,
        TITLE_Y = 30,
        ICON_X = 14,
        ICON_Y = 14,
        BAR_X = VOL_DIALOG_WIDTH/2,
        BAR_Y = 60,
        BAR_LENGTH = VOL_DIALOG_WIDTH - 14*2,
        TEXT_FONT_SIZE = 16,
        ROTATE_EXTND_SIZE = 20
#endif
    };

    enum VappVolumeDialogStateEnum
    {
        STATE_IDLE,
        STATE_RING,
        STATE_MEDIA,
        STATE_MEDIA_FM,
        STATE_MEDIA_ATV,
        STATE_SPEECH,
        STATE_NOT_SHOWN
    };

    enum
    {
        VOL_0,
        VOL_1,
        VOL_2,
        VOL_3,
        VOL_4,
        VOL_5,
        VOL_6,
        VOL_7,
        //7 levels
        VOL_8,
        VOL_9,
        VOL_10,
        VOL_11,
        VOL_12,
        VOL_13,
        VOL_14,
        VOL_15,
        VOL_16
    };

public:
    VappVolumeDialogStateEnum m_state;
    VfxImageFrame * m_icon;
    VfxTextFrame  *m_title;
    VcpSlider     *m_slider;
    VfxU8          m_max;
    VfxU8          m_vol;
    VfxBool        m_vib;
    VfxBool        m_vibTmp;
    VfxTopLevel   *m_topLevel;
    VfxTimer      *m_disappearTimer;
    VfxTimer      *m_previewTimer;
    VfxTimer      *m_repeatTimer;
    VcpFrameEffect *m_frameEffect;

public:
    virtual void onInit();
    virtual vrt_allocator_handle getAllocator();

    VappVolumeDialog();
    VappVolumeDialogStateEnum queryState(void);
    void updateDialog(void);
    void updateIcon(void);
    void onRotate(VfxScreenRotateParam param);
    void dialogFinished(void);
    void forceDisappear(void);

    static mmi_ret onProc(mmi_event_struct *evt);

#ifdef __BT_SPK_VOL_CONTROL__
    void onVolHfp(VfxU8 bt_volume);
#endif
    void onVolKey(mmi_keypads_enum key_code, mmi_key_types_enum key_type);
    void timeOutDisappear(VfxTimer *source);
    void disappear(void);
    void previewRing(VfxTimer *source);
    void profileSwitched(void);
    void modeSwitched(void);

    void onSliderPressed(VcpSlider *obj, VfxFloat val);
    void onSliderReleased(VcpSlider *obj, VfxFloat val);
    void onSliderMoved(VfxObject *obj, VfxFloat oldval, VfxFloat newval);

    void onFrameEffectFinished(VfxFrame *target, VfxBool isCompleted);
    void onScreenChanged(VfxWeakPtr<VfxScreen> scr);

    void onSetNotShownVol(mmi_keypads_enum keycode);
    void onSetSpeechVol(mmi_keypads_enum keycode);
    void onSetMediaVol(mmi_keypads_enum keycode);
    void onSetRingVol(mmi_keypads_enum keycode);
    void onIncreaseRepeat(VfxTimer *source);
    void onDecreaseRepeat(VfxTimer *source);

    void setDecreaseRing(void);
    void setIncreaseRing(void);
    void setRepeatVol(mmi_keypads_enum keycode);
    void setProfileMediaVol(VfxU8 vol);
    
    void setProfileVibAlertType(
            srv_prof_alert_type_enum type_profile2,
            srv_prof_alert_type_enum type_profile1,
            MMI_BOOL can_vib);
    
    void setStateVol(
            VappVolumeDialogStateEnum state, 
            mmi_keypads_enum key_code);

};

#endif
