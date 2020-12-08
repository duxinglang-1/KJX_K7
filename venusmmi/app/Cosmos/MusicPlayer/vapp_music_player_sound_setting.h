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
 *  vapp_music_player_sound_setting.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player sound setting ctrl and page
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_SETTING_PAGE_H__
#define __VAPP_SETTING_PAGE_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"

extern "C"
{
#include "FileMgrSrvGProt.h"
}

typedef enum
{
    SOUND_EFFECTS_NONE,
#ifdef __MMI_AUDIO_EQUALIZER__
    SOUND_EFFECTS_EQ,
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    SOUND_EFFECTS_SURROUND,
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    SOUND_EFFECTS_REVERB,
#endif
    SOUND_EFFECTS_TOTAL
};


/***************************************************************************** 
 * Music Player Control componet: VappMusicPlayerSoundEffect class
 *****************************************************************************/

class VappMusicPlayerSoundEffect : public VfxObject
{
    VFX_DECLARE_CLASS(VappMusicPlayerSoundEffect);

public:
    VappMusicPlayerSoundEffect();
    ~VappMusicPlayerSoundEffect();

    VfxU8 getEffectGroup(void);
    VfxU8 getEffectIndex(void);
    void setEffect(VfxU8 group, VfxU8 index);
    void saveEffect(void);

    void turnOnEffect(void);
    void turnOffEffect(void);

private:
    VfxU8 m_effectType;
    VfxU8 m_effectIndex;
    VfxBool m_isEffectOn;
};

/***************************************************************************** 
 * Music Player Control componet: VappMusicPlayerSettingPage class
 *****************************************************************************/

class VappMusicPlayerSettingRadioPage;

class VappMusicPlayerSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappMusicPlayerSettingPage);

public:
    enum
    {
        MODE_APP,
        MODE_CUI
    };

    VappMusicPlayerSettingPage();
    VappMusicPlayerSettingPage(VfxU8 mode,  VappMusicPlayerSoundEffect *obj);
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

private:
    enum
    {
        SETTING_SOUND,
        SETTING_RESET_DB,
        SETTING_TOTAL
    };

    /* Private functions */
    void onItemTapped(VcpFormItemCell* sender, VfxId Id);
    void resetDBConfirmPopup(void);

    /* Private objects */
    VappMusicPlayerSoundEffect *m_effect_obj;

    /* Variables */
    VfxU8 m_mode;
};

/***************************************************************************** 
 * Music Player Control componet: VappMusicPlayerSettingRadioPage class
 *****************************************************************************/

class VappMusicPlayerSettingRadioPage : public VfxPage, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMusicPlayerSettingRadioPage);

public:
    VappMusicPlayerSettingRadioPage();
    VappMusicPlayerSettingRadioPage(VappMusicPlayerSoundEffect *obj);
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    /* IVcpGroupListMenuContentProvider */
    virtual VfxU32 getGroupCount() const;
    virtual VfxU32 getCount(VfxU32 group) const;
    virtual VfxBool hasGroupHeader(VfxS32 group) const;
    virtual VfxBool getItemText(
        VcpMenuPos pos,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color);
    virtual VcpListMenuItemStateEnum getItemState(
        VcpMenuPos pos) const;


    VfxSignal2 <VfxS32, VfxS32> m_signalSelectNewItem;

private:

    /* Private functions */
    void onButtonClicked(VfxObject* obj, VfxId id);
    void onStateChanged(VcpGroupListMenu *menu, VcpMenuPos pos, VcpListMenuItemStateEnum newState);

    /* Private objects */
    VappMusicPlayerSoundEffect *m_effect_obj;

    /* Private members */
    VfxS32 m_init_group;
    VfxS32 m_init_index;
    VfxS32 m_select_group;
    VfxS32 m_select_index;

public:
    void restoreValue();
};

#endif /*   __VAPP_SETTING_PAGE_H__ */

#endif //__COSMOS_MUSICPLY__
