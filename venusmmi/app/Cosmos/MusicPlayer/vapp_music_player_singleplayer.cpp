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
 *  vapp_music_player_singleplayer.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player signle player app
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


#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"

#include "vapp_music_player.h"
#include "vapp_music_player_singleplayer.h"
#include "vcui_music_player_gprot.h"
#include "mmi_rp_vapp_music_single_player_def.h"
#include "GlobalResDef.h"

/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * App Launcher
 *****************************************************************************/

// Launching function
extern "C" mmi_id vapp_music_player_singleplayer_launch(const WCHAR* filePath, const WCHAR* title)
{
    VappMusicPlayerSinglePlayerArgStruct *arg = NULL;
    VFX_SYS_ALLOC_MEM(arg, sizeof(VappMusicPlayerSinglePlayerArgStruct));
    VFX_ASSERT(arg);

    mmi_wcsncpy(arg->filePath, filePath, SRV_FMGR_PATH_BUFFER_SIZE);
    mmi_wcsncpy(arg->title, srv_fmgr_path_get_filename_const_ptr(filePath), SRV_FMGR_PATH_BUFFER_SIZE);  


    mmi_id app_id = VfxAppLauncher::launch( 
                    VAPP_MUSIC_SINGLE_PLAYER,
                    VFX_OBJ_CLASS_INFO(VappMusicPlayerSinglePlayerApp),
                    GRP_ID_ROOT,
                    (void*)(arg),
                    sizeof(VappMusicPlayerSinglePlayerArgStruct));

    VFX_SYS_FREE_MEM(arg);

    return app_id;
}

// For file manager file open
extern "C" void vapp_music_player_audio_option_open_handler(mmi_menu_id item_id, const WCHAR* filePath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    VfxApp *app = VfxAppLauncher::findApp(
                        VAPP_MUSIC_SINGLE_PLAYER, 
                        VFX_OBJ_CLASS_INFO(VappMusicPlayerSinglePlayerApp), 
                        VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG
                        );
    if(app)
    {
        // close other instance of single player to make sure there's only one single player exists at a time
        app->exit();
    }

    // allocate continuous option struct
    VappMusicPlayerSinglePlayerArgStruct *arg = NULL;
    VFX_SYS_ALLOC_MEM(arg, sizeof(VappMusicPlayerSinglePlayerArgStruct));
    VFX_ASSERT(arg);

    mmi_wcsncpy(arg->filePath, filePath, SRV_FMGR_PATH_BUFFER_SIZE);
    mmi_wcsncpy(arg->title, srv_fmgr_path_get_filename_const_ptr(filePath), SRV_FMGR_PATH_BUFFER_SIZE);    

    VfxAppLauncher::launch( 
                    VAPP_MUSIC_SINGLE_PLAYER,
                    VFX_OBJ_CLASS_INFO(VappMusicPlayerSinglePlayerApp),
                    GRP_ID_ROOT, 
                    (void*)(arg),
                    sizeof(VappMusicPlayerSinglePlayerArgStruct));

    VFX_SYS_FREE_MEM(arg);
}

/***************************************************************************** 
 * VappMusicPlayerSinglePlayerApp Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSinglePlayerApp", VappMusicPlayerSinglePlayerApp, VfxApp);

void VappMusicPlayerSinglePlayerApp::onInit()
{
    VfxApp::onInit();

    /*Register event handler when APP running */
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_TRUE);
#endif
}

void VappMusicPlayerSinglePlayerApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappMusicPlayerSinglePlayerArgStruct *arg = (VappMusicPlayerSinglePlayerArgStruct*)args;

    VappMusicPlayerSinglePlayerScreen *scr;
    VFX_OBJ_CREATE(scr, VappMusicPlayerSinglePlayerScreen, this);
    scr->pushViewStack(VIEW_TYPE_ALL_SONGS);
    scr->show();

    m_cuiID = vcui_music_player_create(getGroupId(), arg->filePath);
    vfxSetCuiCallerScr(m_cuiID, scr);
    vcui_music_player_run(m_cuiID);
    vcui_music_player_set_title(m_cuiID, arg->title);
}

void VappMusicPlayerSinglePlayerApp::onDeinit()
{
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_FALSE);
#endif

    VfxApp::onDeinit();
}

mmi_ret VappMusicPlayerSinglePlayerApp::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            /* Exit application */
            exit();
            return MMI_RET_OK;
        }
    #endif
    }

    return VfxApp::onProc(evt);
}


/***************************************************************************** 
 * VappMusicPlayerSinglePlayerScreen Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerSinglePlayerScreen", VappMusicPlayerSinglePlayerScreen, VappMusicPlayerScreen);

mmi_ret VappMusicPlayerSinglePlayerScreen::onProc(mmi_event_struct *evt)
{
    VappMusicPlayerSinglePlayerApp *app = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMusicPlayerSinglePlayerApp);

    switch(evt->evt_id)
    {
        case EVT_ID_VCUI_MUSIC_PLAYER_PLAY_FINISH:
            //vcui_music_player_close(app->getCuiID());
            return MMI_RET_OK;
        
        case EVT_ID_VCUI_MUSIC_PLAYER_CLOSE:
            vcui_music_player_close(app->getCuiID());
            app->exit();
            return MMI_RET_OK;
    }

    return VappMusicPlayerScreen::onProc(evt);
}

#endif //__COSMOS_MUSICPLY__
