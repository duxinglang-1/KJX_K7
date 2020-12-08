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
 *  Vapp_dm_lawmo.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Device management LAWMO cosmos UI.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __DM_LAWMO_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vapp_dm_lawmo.h"
#include "vcp_global_popup.h"
#include "vcui_dialer_gprot.h"
#include "vapp_wallpaper.h"
#include "vapp_wallpaper_kit.h"
#include "vapp_wallpaper_cfg.h"
#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_wallpaper_def.h"
#include "vapp_screen_lock_gprot.h"

extern "C"
{
#include "GlobalResDef.h"
#include "mmi_rp_srv_dm_def.h"
#include "mmi_rp_vapp_dm_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "DmSrvIprot.h"
#include "DmSrvGprot.h"
}

/***************************************************************************** 
 * Static Variable
 *****************************************************************************/
static MMI_ID vappDmLawmoLockGid;
static MMI_ID vappDmLawmoWipeGid;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

extern "C" 
{
MMI_ID vappDmLawmoLockEvtHdlr()
{
    mmi_frm_close_to_idle_group();
    vappDmLawmoLockGid = VfxAppLauncher::launch(
        VAPP_DM,
        VFX_OBJ_CLASS_INFO(VappDmLawmoLock),
        GRP_ID_ROOT,
        NULL,
        0);
    return vappDmLawmoLockGid;
}

MMI_ID vappDmLawmoWipeEvtHdlr()
{
    mmi_frm_close_to_idle_group();
    vappDmLawmoWipeGid = VfxAppLauncher::launch(
        VAPP_DM,
        VFX_OBJ_CLASS_INFO(VappDmLawmoWipe),
        GRP_ID_ROOT,
        NULL,
        0);
    return vappDmLawmoWipeGid;
}

mmi_ret vappDmLawmoScreenLockPreLockHdlr(mmi_event_struct *evt)
{
    // if locked
    return MMI_RET_ERR;
}

mmi_ret vappDmLawmoLockIndHdlr(mmi_event_struct *evt)
{
    srv_dm_lawmo_lock_ind_evt_struct *lawmo_lock_ind =
        (srv_dm_lawmo_lock_ind_evt_struct*)evt;
    switch (lawmo_lock_ind->cmd)
    {
        case SRV_DM_LAWMO_LOCK_CMD_LOCK:
        {
            vappDmLawmoLockEvtHdlr();
            break;
        }

        case SRV_DM_LAWMO_LOCK_CMD_UNLOCK:
        {
            VfxAppLauncher::terminate(vappDmLawmoLockGid);
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}

mmi_ret vappDmLawmoWipeIndHdlr(mmi_event_struct *evt)
{
    srv_dm_lawmo_wipe_ind_evt_struct *lawmo_wipe_ind =
        (srv_dm_lawmo_wipe_ind_evt_struct*)evt;
    switch (lawmo_wipe_ind->cmd)
    {
        case SRV_DM_LAWMO_WIPE_CMD_START:
        {
            vappDmLawmoWipeEvtHdlr();
            break;
        }

        case SRV_DM_LAWMO_WIPE_CMD_FINISH:
        {
            VfxAppLauncher::terminate(vappDmLawmoWipeGid);
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}
}

VFX_IMPLEMENT_CLASS("VappDmLawmoLock", VappDmLawmoLock, VfxApp);
void VappDmLawmoLock::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappDmLawmoLockMainScrn *mainScrn;
    VFX_OBJ_CREATE(mainScrn, VappDmLawmoLockMainScrn, this);
    mainScrn->show();
}


void VappDmLawmoLock::onInit()
{
    VfxApp::onInit();
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_TRUE);
}


void VappDmLawmoLock::onDeinit()
{
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
    registerCBEvent(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, VFX_FALSE);
    VfxApp::onDeinit();
}


mmi_ret VappDmLawmoLock::onProc(mmi_event_struct * evt)
{
    mmi_ret ret = MMI_RET_OK;
    switch(evt->evt_id)
    {
        case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
        {
            ret = MMI_RET_ERR;
            break;
        }

        default:
            break;
    }
    return ret;
}


VfxAppCloseAnswerEnum VappDmLawmoLock::onProcessClose(VfxAppCloseOption options)
{
    return VFX_APP_CLOSE_ANSWER_NO;
}


VFX_IMPLEMENT_CLASS("VappDmLawmoLockMainScrn", VappDmLawmoLockMainScrn, VfxMainScr);
void VappDmLawmoLockMainScrn::on1stReady()
{
    VfxMainScr::on1stReady();
    VappDmLawmoLockPage *LockPage;
    VFX_OBJ_CREATE(LockPage, VappDmLawmoLockPage, this);
    pushPage(0, LockPage);
}


VFX_IMPLEMENT_CLASS("VappDmLawmoLockPage", VappDmLawmoLockPage, VfxPage);
void VappDmLawmoLockPage::onInit()
{
    VfxPage::onInit();
    
    setStatusBar(VFX_FALSE);
    
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_DM_LAWMO_LOCK_INFO);
    setTopBar(bar);
#if 0
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
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);

    VappWallpaperKit *wallpaperKit;
    VFX_OBJ_CREATE(wallpaperKit, VappWallpaperKit, this);
    VappWallpaper *wallpaper;
    wallpaper = wallpaperKit->create(wallpaperInterface->getWallpaperId(VAPP_WALLPAPER_LOCK_SCREEN), this);
    wallpaper->setSource(VAPP_WALLPAPER_SRC_LOCK);
    wallpaper->createView();
    wallpaper->setIsDisabled(VFX_TRUE);
    wallpaper->suspend();
    wallpaper->resume();

    VFX_OBJ_CLOSE(wallpaperKit);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->addItem(0, STR_GLOBAL_DIAL, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    toolBar->m_signalButtonTap.connect(this, &VappDmLawmoLockPage::dialSos);
    setBottomBar(toolBar);

    setAllowDelete(VFX_FALSE);
}


void VappDmLawmoLockPage::onEnter()
{
    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
}


void VappDmLawmoLockPage::dialSos(VfxObject* obj, VfxId itemId)
{
    if (itemId == 0)
    {
        MMI_ID cuiId;
        cuiId = vcui_dialer_create_ex(
            getMainScr()->getGroupId(),
            VCUI_DIALER_TYPE_EMERGENCY);
        vcui_dialer_run(cuiId);
    }
}


VFX_IMPLEMENT_CLASS("VappDmLawmoWipe", VappDmLawmoWipe, VfxApp);
void VappDmLawmoWipe::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappDmLawmoWipeMainScrn *mainScrn;
    VFX_OBJ_CREATE(mainScrn, VappDmLawmoWipeMainScrn, this);
    mainScrn->show();
}


mmi_ret VappDmLawmoWipe::onProc(mmi_event_struct * evt)
{
    mmi_ret ret = MMI_RET_OK;
    switch(evt->evt_id)
    {
        case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
        {
            ret = MMI_RET_ERR;
            break;
        }

        default:
            break;
    }
    return ret;
}


VfxAppCloseAnswerEnum VappDmLawmoWipe::onProcessClose(VfxAppCloseOption options)
{
    return VFX_APP_CLOSE_ANSWER_NO;
}


VFX_IMPLEMENT_CLASS("VappDmLawmoWipeMainScrn", VappDmLawmoWipeMainScrn, VfxAppScr);
VappDmLawmoWipeMainScrn::VappDmLawmoWipeMainScrn()
{
    setIsSmallScreen();
}

void VappDmLawmoWipeMainScrn::onInit()
{
    VfxAppScr::onInit();
    VcpIndicatorPopup *IndPopup;
    VFX_OBJ_CREATE(IndPopup, VcpIndicatorPopup, this);
    IndPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    IndPopup->setText(STR_GLOBAL_DELETING);
    IndPopup->show(VFX_TRUE);
}

#endif /* __DM_LAWMO_SUPPORT__ */
