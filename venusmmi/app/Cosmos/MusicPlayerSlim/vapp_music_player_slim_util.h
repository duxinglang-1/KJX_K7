
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifndef __VAPP_MUSIC_PLAYER_UTIL_H__
#define __VAPP_MUSIC_PLAYER_UTIL_H__

#include "mmi_rp_vapp_music_player_slim_def.h"
#include "vapp_music_player_slim.h"
#include "vapp_music_player_slim_session.h"
#include "FileMgrSrvGProt.h"
extern "C"
{
#include "UcmSrvGprot.h"
}
/***************************************************************************** 
 * utility function
 *****************************************************************************/
inline VfxApp* findRootApp(VfxObject *obj)
{
    VfxApp *pApp = NULL;
    for(VfxObject *pObj = obj; pObj != NULL; pObj = pObj->getParent())
    {
        pApp = VFX_OBJ_DYNAMIC_CAST(pObj, VfxApp);
        if(pApp != NULL)
        {
            return pApp;
        }
    }

    // root should be VfxApp
    VFX_ASSERT(0);
    return NULL;
}
inline VappMusicPlayerAppSlim* getMusicPlayerSlimApp()
{
    VfxApp *app = VfxAppLauncher::findApp(
                    VAPP_MUSIC_PLAYER_SLIM, 
                    VFX_OBJ_CLASS_INFO(VappMusicPlayerAppSlim), 
                    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

    return VFX_OBJ_DYNAMIC_CAST(app, VappMusicPlayerAppSlim);
}
inline VappMusicPlayerSession* getMusicPlayerSession()
{
    VappMusicPlayerSession *session = VFX_OBJ_GET_INSTANCE(VappMusicPlayerSession);
    return session;
}
inline const WCHAR* getFilenamebyPath(const WCHAR* path)
{
    S32 pos;

    pos = srv_fmgr_path_get_filename_pos(path);
    if(pos < 0)
        return NULL;

    return path + pos;
}
inline VfxBool checkMemoryCardReady()
{
   return FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR;
}
inline VfxBool isMakingCall()
{
    return srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0;
}
#endif /*   __VAPP_MUSIC_PLAYER_UTIL_H__    */

#endif //__MMI_MUSIC_PLAYER_SLIM__