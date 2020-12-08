
#include "mmi_features.h"
#if  defined(__MMI_MUSIC_PLAYER_SLIM__) && defined(__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__)

#include "vapp_music_player_slim_sound_setting.h"
#include "mmi_rp_vapp_music_player_slim_def.h"
#include "vapp_music_player_slim.h"
#include "vapp_music_player_slim_util.h"

extern "C"
{
#include "aud_defs.h"
#include "med_main.h"
#include "..\..\..\..\plutommi\service\inc\SoundEffectSrvGProt.h"
}

/***************************************************************************** 
 * VappMusicPlayerSettingRadioPage Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSettingRadioPage", VappMusicPlayerSettingRadioPage, VfxPage);
VappMusicPlayerSettingRadioPage::VappMusicPlayerSettingRadioPage():
m_init_group(0),
m_init_index(0),
m_select_group(0),
m_select_index(0)
{
}
void VappMusicPlayerSettingRadioPage::onInit()
{
    VfxPage::onInit();
    m_session = getMusicPlayerSession();

    /*get group and index from session*/
    m_init_group = m_select_group = m_session->getEffectGroup();
    m_init_index = m_select_index = m_session->getEffectIndex();

    /* Create title bar */
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MUSIC_PLAYER_SETTING_SNDEFFECT));
    setTopBar(bar);

    /* Create tool bar */
    VcpToolBar *m_toolbar;
    VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
    m_toolbar->addItem(0, VFX_WSTR_RES(VCP_STR_TOOL_BAR_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolbar->addItem(1, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolbar->m_signalButtonTap.connect(this, &VappMusicPlayerSettingRadioPage::onButtonClicked);
    setBottomBar(m_toolbar);

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
    /*deinit need to restore*/
    restoreValue();
    VfxPage::onDeinit();
}
void VappMusicPlayerSettingRadioPage::onButtonClicked(VfxObject* obj, VfxId id)
{
    /* click ok */
    if(id == 0)
    {
        m_init_group = m_select_group;
        m_init_index = m_select_index;
    }
    /* click Cancel */
    else
    {
        restoreValue();
    }
    getMainScr()->popPage();
}
void VappMusicPlayerSettingRadioPage::restoreValue()
{
    /* restore effect */
    if((m_init_group != m_select_group) || (m_init_index != m_select_index))
    {
        m_session->setEffect(m_init_group, m_init_index);
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

        m_session->setEffect(m_select_group, m_select_index);          
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
    #ifdef __MMI_AUDIO_EQUALIZER__
        case SOUND_EFFECTS_EQ:
            return srv_sound_effect_get_count(SRV_SOUND_EFFECT_TYPE_EQ);
    #endif
    #ifdef __MMI_AUDIO_SURROUND_EFFECT__
        case SOUND_EFFECTS_SURROUND:
            return srv_sound_effect_get_count(SRV_SOUND_EFFECT_TYPE_SURROUND);
    #endif
    #ifdef __MMI_AUDIO_REVERB_EFFECT__
        case SOUND_EFFECTS_REVERB:
            return srv_sound_effect_get_count(SRV_SOUND_EFFECT_TYPE_REVERB);
    #endif
        default:
            return 0;
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

#endif //__COSMOS_MUSICPLY__
