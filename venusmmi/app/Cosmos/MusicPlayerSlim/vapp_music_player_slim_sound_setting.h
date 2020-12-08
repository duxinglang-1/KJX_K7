
#include "mmi_features.h"
#if  defined(__MMI_MUSIC_PLAYER_SLIM__) && defined(__MMI_MUSIC_PLAYER_SLIM_SOUND_EFFECT__)

#ifndef __VAPP_SETTING_PAGE_SLIM_H__
#define __VAPP_SETTING_PAGE_SLIM_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_music_player_slim_datatype.h"
#include "vapp_music_player_slim_util.h"
#include "vapp_music_player_slim.h"

extern "C"
{
#include "FileMgrSrvGProt.h"
}

/***************************************************************************** 
 * Music Player Control componet: VappMusicPlayerSettingRadioPage class
 *****************************************************************************/

class VappMusicPlayerSettingRadioPage : public VfxPage, public IVcpGroupListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappMusicPlayerSettingRadioPage);

public:
    VappMusicPlayerSettingRadioPage();
    virtual void onInit();
    virtual void onDeinit();

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
	void restoreValue();
    void onStateChanged(VcpGroupListMenu *menu, VcpMenuPos pos, VcpListMenuItemStateEnum newState);

    /* Private objects */
    VappMusicPlayerSession *m_session;
    /* Private members */
    VfxS32 m_init_group;
    VfxS32 m_init_index;
    VfxS32 m_select_group;
    VfxS32 m_select_index;
};

#endif /*   __VAPP_SETTING_PAGE_H__ */

#endif //__COSMOS_MUSICPLY__
