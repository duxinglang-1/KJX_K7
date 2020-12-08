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
 *  vapp_music_player_sound_setting.cpp
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
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

#include "vapp_music_player_sound_setting.h"
#include "mmi_rp_vapp_music_player_def.h"
#include "vapp_music_player.h"

extern "C"
{
#include "aud_defs.h"
#include "med_main.h"
#include "..\..\..\..\plutommi\service\inc\SoundEffectSrvGProt.h"
}


/***************************************************************************** 
 * VappMusicPlayerSettingPage Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSettingPage", VappMusicPlayerSettingPage, VfxPage);
VappMusicPlayerSettingPage::VappMusicPlayerSettingPage():
m_mode(MODE_APP),
m_effect_obj(NULL)
{
}

VappMusicPlayerSettingPage::VappMusicPlayerSettingPage(VfxU8 mode, VappMusicPlayerSoundEffect *obj):
m_mode(mode),
m_effect_obj(obj)
{
}

void VappMusicPlayerSettingPage::onInit()
{
    VfxPage::onInit();

    /* Create title bar */
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_TITLE_SETTING));
    setTopBar(bar);

    /* Create Form */
    VcpForm *m_form;
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());

    VcpFormItemLauncherCell *m_setting[SETTING_TOTAL];

#if defined(__MMI_AUDIO_EQUALIZER__) || defined(__MMI_AUDIO_SURROUND_EFFECT__) || defined(__MMI_AUDIO_REVERB_EFFECT__)
    /* Caption - sound effect */
    VcpFormItemCaption *caption_sound;
    VFX_OBJ_CREATE(caption_sound, VcpFormItemCaption, m_form);
    caption_sound->setText(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_SUBTITILE_SOUND_SETTING));
    m_form->addItem(caption_sound);

    /* Button - Sound Effect */
    VFX_OBJ_CREATE(m_setting[SETTING_SOUND], VcpFormItemLauncherCell, m_form);
    m_setting[SETTING_SOUND]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_SETTING_SNDEFFECT));
    //m_setting[SETTING_SOUND]->setHintText(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_SETTING_SNDEFFECT_SUB));
    m_setting[SETTING_SOUND]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_setting[SETTING_SOUND]->m_signalTap.connect(this, &VappMusicPlayerSettingPage::onItemTapped);
    m_form->addItem(m_setting[SETTING_SOUND], SETTING_SOUND);
#endif

    /* Only allow to reset database in application */
    if(MODE_APP == m_mode)
    {
        /* Caption - database */
        VcpFormItemCaption *caption_db;
        VFX_OBJ_CREATE(caption_db, VcpFormItemCaption, m_form);
        caption_db->setText(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_SUBTITILE_DB_SETTING));
        m_form->addItem(caption_db);

        /* Button - Sound Effect */
        VFX_OBJ_CREATE(m_setting[SETTING_RESET_DB], VcpFormItemLauncherCell, m_form);
        m_setting[SETTING_RESET_DB]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_SETTING_RESET_DB));
        m_setting[SETTING_RESET_DB]->m_signalTap.connect(this, &VappMusicPlayerSettingPage::onItemTapped);
        m_form->addItem(m_setting[SETTING_RESET_DB], SETTING_RESET_DB);
    }
}

VfxBool VappMusicPlayerSettingPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_BACK)
    {
        onBack();
        return VFX_FALSE;
    }

    return VfxPage::onKeyInput(event);
}

void VappMusicPlayerSettingPage::onItemTapped(VcpFormItemCell* sender, VfxId Id)
{
    switch(Id)
    {
        case SETTING_SOUND:
            {
                VappMusicPlayerSettingRadioPage *page;
                VFX_OBJ_CREATE_EX(page, VappMusicPlayerSettingRadioPage, getMainScr(), (m_effect_obj));
                getMainScr()->pushPage(0, page);        
                
                VappMusicPlayerApp *app = reinterpret_cast<VappMusicPlayerApp*>(getApp());
                app->onPlayerPageCallback(FUNC_ID_GO_TO_SOUND_EFFECT);
            }
            break;

        case SETTING_RESET_DB:
            resetDBConfirmPopup();
            break;

        default:
            break;
    }
}

void VappMusicPlayerSettingPage::resetDBConfirmPopup(void)
{
    VappMusicPlayerApp *app = reinterpret_cast<VappMusicPlayerApp*>(getApp());
    app->popupConfirm(
            VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_RESET_HINT),
            VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_POPUP_BTN_RESET), 
            VCP_POPUP_TYPE_WARNING,
            VCP_CONFIRM_BUTTON_SET_USER_DEFINE,
            VCP_POPUP_BUTTON_TYPE_WARNING
            );

    app->setActionMode(ACTION_RESET);
}

/***************************************************************************** 
 * VappMusicPlayerSettingRadioPage Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSettingRadioPage", VappMusicPlayerSettingRadioPage, VfxPage);
VappMusicPlayerSettingRadioPage::VappMusicPlayerSettingRadioPage() :
m_init_group(0),
m_init_index(0),
m_select_group(0),
m_select_index(0),
m_effect_obj(NULL)
{
}

VappMusicPlayerSettingRadioPage::VappMusicPlayerSettingRadioPage(VappMusicPlayerSoundEffect *obj) :
m_init_group(0),
m_init_index(0),
m_select_group(0),
m_select_index(0),
m_effect_obj(obj)
{
    /* restore effect */
    if((m_init_group != m_select_group) || (m_init_index != m_select_index))
    {
        m_effect_obj->setEffect(m_init_group, m_init_index);
        m_select_group = m_init_group;
        m_select_index = m_init_index;
    }
}

void VappMusicPlayerSettingRadioPage::onInit()
{
    VfxPage::onInit();

    /* Get data from effect object */
    if(m_effect_obj != NULL)
    {
        m_init_group = m_select_group = m_effect_obj->getEffectGroup();
        m_init_index = m_select_index = m_effect_obj->getEffectIndex();
    }

    /* Create title bar */
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_SETTING_SNDEFFECT));
    setTopBar(bar);

    /* Create tool bar */
    VcpToolBar *m_toolbar;
    VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
    ///// TODO: change to global string/image after W10.45
    m_toolbar->addItem(0, VFX_WSTR_RES(VCP_STR_TOOL_BAR_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolbar->addItem(1, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolbar->m_signalButtonTap.connect(this, &VappMusicPlayerSettingRadioPage::onButtonClicked);
    setBottomBar(m_toolbar); /* Set to browse mode at beginning */

    /* Create radio list */
    VcpGroupListMenu *m_list;
    VFX_OBJ_CREATE(m_list, VcpGroupListMenu, this);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    m_list->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION,VFX_FALSE);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappMusicPlayerSettingRadioPage::onStateChanged);
    m_list->setContentProvider(this);
    m_list->setRect(getRect());
    m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    
}

void VappMusicPlayerSettingRadioPage::onDeinit()
{
    restoreValue();

    VfxPage::onDeinit();
}

VfxBool VappMusicPlayerSettingRadioPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN && event.keyCode == VFX_KEY_CODE_BACK)
    {
        restoreValue();
        onBack();
        return VFX_FALSE;
    }

    return VfxPage::onKeyInput(event);
}

void VappMusicPlayerSettingRadioPage::onButtonClicked(VfxObject* obj, VfxId id)
{
    /* Apply */
    if(id == 0)
    {
        m_effect_obj->saveEffect();
        m_init_group = m_select_group;
        m_init_index = m_select_index;
    }
    /* Cancel */
    else
    {
        restoreValue();
    }

    VappMusicPlayerApp *app = reinterpret_cast<VappMusicPlayerApp*>(getApp());
    app->onPlayerPageCallback(FUNC_ID_SOUND_EFFECT_CLOSE);

    getMainScr()->popPage();
}

void VappMusicPlayerSettingRadioPage::restoreValue()
{
    /* restore effect */
    if((m_init_group != m_select_group) || (m_init_index != m_select_index))
    {
        m_effect_obj->setEffect(m_init_group, m_init_index);
        m_select_group = m_init_group;
        m_select_index = m_init_index;
    }
}

void VappMusicPlayerSettingRadioPage::onStateChanged(VcpGroupListMenu *menu, VcpMenuPos pos, VcpListMenuItemStateEnum newState)
{
    if(VCP_LIST_MENU_ITEM_STATE_SELECTED == newState)
    {
        m_select_group = pos.group;
        m_select_index = pos.pos;

        m_effect_obj->setEffect(m_select_group, m_select_index);        
    }
}

VfxU32 VappMusicPlayerSettingRadioPage::getGroupCount() const
{
    return SOUND_EFFECTS_TOTAL;
}

VfxU32 VappMusicPlayerSettingRadioPage::getCount(VfxU32 group) const
{
    switch(group)
    {
        case SOUND_EFFECTS_NONE:
            return 1;
            break;
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SOUND_EFFECTS_EQ:
            return srv_sound_effect_get_count(SRV_SOUND_EFFECT_TYPE_EQ);
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SOUND_EFFECTS_SURROUND:
            return srv_sound_effect_get_count(SRV_SOUND_EFFECT_TYPE_SURROUND);
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SOUND_EFFECTS_REVERB:
            return srv_sound_effect_get_count(SRV_SOUND_EFFECT_TYPE_REVERB);
            break;
    #endif
        default:
            return 0;
            break;
    }

}

VfxBool VappMusicPlayerSettingRadioPage::hasGroupHeader(VfxS32 group) const
{
    if(SOUND_EFFECTS_NONE == group)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxBool VappMusicPlayerSettingRadioPage::getItemText(
    VcpMenuPos pos,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    switch(pos.group)
    {
        case SOUND_EFFECTS_NONE:
            if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text = VFX_WSTR_RES(STR_GLOBAL_NONE);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            break;
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SOUND_EFFECTS_EQ:
            if(fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
            {
                text = VfxWString().loadFromMem(srv_sound_effect_get_name(SRV_SOUND_EFFECT_TYPE_EQ, -1));
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;        
            }
            if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text = VfxWString().loadFromMem(srv_sound_effect_get_name(SRV_SOUND_EFFECT_TYPE_EQ, pos.pos));
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }            
            break;
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SOUND_EFFECTS_SURROUND:
            if(fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
            {
                text = VfxWString().loadFromMem(srv_sound_effect_get_name(SRV_SOUND_EFFECT_TYPE_SURROUND, -1));
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;        
            }
            if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text = VfxWString().loadFromMem(srv_sound_effect_get_name(SRV_SOUND_EFFECT_TYPE_SURROUND, pos.pos));
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }             
            break;
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SOUND_EFFECTS_REVERB:
            if(fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
            {
                text = VfxWString().loadFromMem(srv_sound_effect_get_name(SRV_SOUND_EFFECT_TYPE_REVERB, -1));
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;        
            }
            if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                text = VfxWString().loadFromMem(srv_sound_effect_get_name(SRV_SOUND_EFFECT_TYPE_REVERB, pos.pos));
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }             
            break;
    #endif
        default:
            return 0;
            break;
    }
    return VFX_FALSE;
}

VcpListMenuItemStateEnum VappMusicPlayerSettingRadioPage::getItemState(VcpMenuPos pos) const
{
    if(pos.group == m_select_group && pos.pos == m_select_index)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

/***************************************************************************** 
 * VappMusicPlayerSoundEffect Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSoundEffect", VappMusicPlayerSoundEffect, VfxObject);

VappMusicPlayerSoundEffect::VappMusicPlayerSoundEffect() :
    m_isEffectOn(VFX_FALSE),
    m_effectType(0),
    m_effectIndex(0)
{
    srv_sound_effect_init();
    
    VfxS16 error = 0;
    ReadValue(NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_TYPE, &m_effectType, DS_BYTE, &error);
    ReadValue(NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_INDEX, &m_effectIndex, DS_BYTE, &error);
}

VappMusicPlayerSoundEffect::~VappMusicPlayerSoundEffect()
{
    if(m_isEffectOn)
    {
        turnOffEffect();
    }
}

VfxU8 VappMusicPlayerSoundEffect::getEffectGroup(void)
{
    VfxU8 group;

    switch(m_effectType)
    {
        case SRV_SOUND_EFFECT_TYPE_NONE:
            group = SOUND_EFFECTS_NONE;
            break;
#ifdef __MMI_AUDIO_EQUALIZER__
        case SRV_SOUND_EFFECT_TYPE_EQ:
            group = SOUND_EFFECTS_EQ;
            break;
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_SURROUND:
            group = SOUND_EFFECTS_SURROUND;
            break;
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SRV_SOUND_EFFECT_TYPE_REVERB:
            group = SOUND_EFFECTS_REVERB;
            break;
#endif
        default:
            group = SOUND_EFFECTS_NONE;
            break;
    }

    return group;
}

VfxU8 VappMusicPlayerSoundEffect::getEffectIndex(void)
{
    return m_effectIndex;
}

void VappMusicPlayerSoundEffect::setEffect(VfxU8 group, VfxU8 index)
{
    switch(group)
    {
        case SOUND_EFFECTS_NONE:
            m_effectType = SRV_SOUND_EFFECT_TYPE_NONE;
            break;
#ifdef __MMI_AUDIO_EQUALIZER__
        case SOUND_EFFECTS_EQ:
            m_effectType = SRV_SOUND_EFFECT_TYPE_EQ;
            break;
#endif
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SOUND_EFFECTS_SURROUND:
            m_effectType = SRV_SOUND_EFFECT_TYPE_SURROUND;
            break;
#endif
#ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SOUND_EFFECTS_REVERB:
            m_effectType = SRV_SOUND_EFFECT_TYPE_REVERB;
            break;
#endif
        default:
            m_effectType = SRV_SOUND_EFFECT_TYPE_NONE;
            break;
    }

    m_effectIndex = index;

    /* Change effect if audio is playing */
    if(m_isEffectOn)
    {
        turnOffEffect();
        turnOnEffect();
    }
}

void VappMusicPlayerSoundEffect::saveEffect(void)
{
    VfxS16 error = 0;
    WriteValue(NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_TYPE, &m_effectType, DS_BYTE, &error);
    WriteValue(NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_INDEX, &m_effectIndex, DS_BYTE, &error);
}

void VappMusicPlayerSoundEffect::turnOnEffect(void)
{
    if(m_effectType != 0 || m_effectIndex != 0)
    {
        /* May handle callback here if other app may use in the future */
        srv_sound_effect_turn_on(static_cast<srv_sound_effect_type_enum>(m_effectType), m_effectIndex, NULL, NULL);
    }

    m_isEffectOn = VFX_TRUE;
}

void VappMusicPlayerSoundEffect::turnOffEffect(void)
{
    srv_sound_effect_turn_off();
    m_isEffectOn = VFX_FALSE;
}

#endif //__COSMOS_MUSICPLY__
