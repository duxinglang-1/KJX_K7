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
 *  vapp_launcher_cosmos_mm.cpp
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Launcher Cosmos
 *
 * Description:
 * ------------
 *  Launcher Cosmos Main Menu
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_COSMOS__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_context.h"

#include "vcp_include.h"
#include "vcp_page_menu_transition.h"
#include "vcp_status_icon_bar.h"
#include "vcp_global_popup.h"    
#include "vcp_indicator_popup.h" // for VcpIndicatorPopup

#ifndef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
#include "vapp_platform_context.h"
#endif

#include "vapp_launcher.h"

#include "vapp_launcher_cosmos_mm.h"
#include "vapp_launcher_cosmos_mm_builder.h"
#include "vapp_launcher_cosmos_mm_default_order.h"
#include "vapp_launcher_cosmos_mm_gprot.h"
#include "vapp_launcher_cosmos_mm_page_menu.h"
#include "vapp_launcher_cosmos_mm_shortcut_bar.h" // for the order data utils
#include "mmi_rp_vapp_launcher_cosmos_mm_def.h"
#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
#include "mmi_rp_vapp_launcher_cosmos_mm_barrel_setting_def.h"
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

#include "vapp_launcher_app.h" // for VappLauncherApp
#include "vapp_launcher_gprot.h"

#include "vapp_ncenter.h"

extern "C"
{
#include "nvram_common_defs.h"
#include "Wgui.h" // for MMI_STATUS_BAR_HEIGHT
#include "AppMgrSrvGprot.h"
#include "SensorSrvGport.h"
#include "MREAppMgrSrvGprot.h"      // for query if there is MRE app running
#include "JavaAppFactorySrvGprot.h" // for query if there is Java app running
}

#if defined(__COSMOS_3D_V10__) && defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
#include "vcp_sse.h"
#endif

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


/*****************************************************************************
 * Define
 *****************************************************************************/
#ifndef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
#define VAPP_LAUNCHER_COSMOS_MM_LAUNCH_WITH_PLATFORM_CONTEXT
#endif

#ifndef VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
#define VAPP_LAUNCHER_COSMOS_MM_RELEASE_UI_ON_EXIT
#endif

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

static VappLauncherCosmosMmCell *g_vapp_launcher_cosmos_mm_uninstalled_cell = NULL;
static VfxBool m_gIsUninstallBtnClicked = VFX_FALSE;

/*****************************************************************************
 * Local Variable
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SCREEN_WIDTH = 480;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SCREEN_HEIGHT = 800;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_HEIGHT = 130;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_ROW_COUNT = 4;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_COLUMN_COUNT = 4;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_START_X = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_START_Y = MMI_STATUS_BAR_HEIGHT;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_X = 120;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_Y = 149;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_PAGE_MARGIN = 27;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_VISIBLE_SHIFT_Y = -2;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SCREEN_WIDTH = 240;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SCREEN_HEIGHT = 320;
#else
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SCREEN_WIDTH = 240;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SCREEN_HEIGHT = 400;
#endif

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_HEIGHT = 60;

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_ROW_COUNT = 3;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_COLUMN_COUNT = 4;
#else
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_ROW_COUNT = 4;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_COLUMN_COUNT = 4;
#endif

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_START_X = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_START_Y = MMI_STATUS_BAR_HEIGHT;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_X = 60;

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_Y = 73;
#else
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_Y = 75;
#endif

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_PAGE_MARGIN = 15;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_VISIBLE_SHIFT_Y = -6;

#else // default HVGA 320X480
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SCREEN_WIDTH = 320;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_SCREEN_HEIGHT = 480;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_HEIGHT = 80;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_ROW_COUNT = 4;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_COLUMN_COUNT = 4;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_START_X = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_START_Y = MMI_STATUS_BAR_HEIGHT;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_X = 80;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_Y = 90;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_PAGE_MARGIN = 20;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_VISIBLE_SHIFT_Y = -5;

#endif

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_Y = VAPP_LAUNCHER_COSMOS_MM_SCREEN_HEIGHT - VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_HEIGHT;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_COUNT_IN_PAGE = VAPP_LAUNCHER_COSMOS_MM_CELL_ROW_COUNT * VAPP_LAUNCHER_COSMOS_MM_CELL_COLUMN_COUNT;

#ifdef VAPP_LAUNCHER_COSMOS_MM_TRANSLUCENT_BACKGROUND
static const VfxFloat VAPP_LAUNCHER_COSMOS_MM_WALLPAPER_MASK_ALPHA = 0.75f;
#endif

#ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_ANIMTIME = 400;
#endif

#if !defined(VAPP_LAUNCHER_COSMOS_MM_LAUNCH_WITH_PLATFORM_CONTEXT) && (!defined (VAPP_LAUNCHER_COSMOS_MM_IN_PAGE) || defined(__AFX_RT_TEST__))
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CNTX_MEMORY_SIZE = 600 * 1024;

static VfxU8 s_vappLauncherCosmosMmCntxMemPool[VAPP_LAUNCHER_COSMOS_MM_CNTX_MEMORY_SIZE];
#endif

static VappLauncherCosmosMmContent *s_vappLauncherCosmosMm = NULL;


/*****************************************************************************
 * Global Function
 *****************************************************************************/

extern "C" MMI_ID vapp_launcher_cosmos_mm_launch(void* param, U32 param_size)
{
#if defined(__AFX_RT_TEST__) || !defined(VAPP_LAUNCHER_COSMOS_MM_IN_PAGE)

#ifdef VAPP_LAUNCHER_COSMOS_MM_LAUNCH_WITH_PLATFORM_CONTEXT
    VfxContext *cntx = VFX_OBJ_GET_INSTANCE(VappPlatformContext);
#else
    static VfxContext *cntx = NULL;

    if (cntx == NULL)
    {
        VFX_OBJ_CREATE(cntx, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
        cntx->assignPool(s_vappLauncherCosmosMmCntxMemPool, VAPP_LAUNCHER_COSMOS_MM_CNTX_MEMORY_SIZE);
    }
#endif

    return VfxAppLauncher::launchWithCtx(
        VAPP_LAUNCHER_COSMOS_MM,
        VFX_OBJ_CLASS_INFO(VappLauncherCosmosMmApp),
        GRP_ID_ROOT,
        cntx);
#else
	//Please close VAPP_LAUNCHER_COSMOS_MM_IN_PAGE, if you need call this function to launch cosmos main menu.
	return GRP_ID_INVALID;
#endif /* defined(__AFX_RT_TEST__) || !defined(VAPP_LAUNCHER_COSMOS_MM_IN_PAGE) */

}

VfxS32 vappLauncherCosmosMmGetCellCountInPage()
{
    return VAPP_LAUNCHER_COSMOS_MM_CELL_COUNT_IN_PAGE;
}

VappLauncherCosmosMmContent *vappLauncherCosmosMmGetInstance()
{
    return s_vappLauncherCosmosMm;
}

void vappLauncherCosmosMmUninstallApp(VappLauncherCosmosMmCell *cell)
{
    VappLauncherCosmosMmContent *content = vappLauncherCosmosMmGetInstance();
    content->onDelBtnClicked(cell);
}

#if (defined(__AFX_RT_TEST__) || !defined(VAPP_LAUNCHER_COSMOS_MM_IN_PAGE))

/*****************************************************************************
 * Class VappLauncherCosmosMmApp
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmApp", VappLauncherCosmosMmApp, VfxApp);

void VappLauncherCosmosMmApp::onRun(void *args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VFX_OBJ_CREATE(m_scr, VappLauncherCosmosMmScr, this);
    m_scr->show();
}


/*****************************************************************************
 * Class VappLauncherCosmosMmScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmScr", VappLauncherCosmosMmScr, VfxAppScr);

VappLauncherCosmosMmScr::VappLauncherCosmosMmScr():
    m_content(NULL)
{
}

void VappLauncherCosmosMmScr::reloadMainmenu()
{
    m_content->reloadMainmenu();
}

void VappLauncherCosmosMmScr::onInit()
{
    VfxAppScr::onInit();
    
    VFX_OBJ_CREATE(m_content, VappLauncherCosmosMmContent, this);
    m_content->setFocused(VFX_TRUE);
    m_content->setSize(VAPP_LAUNCHER_COSMOS_MM_SCREEN_WIDTH, VAPP_LAUNCHER_COSMOS_MM_SCREEN_HEIGHT);
}

void VappLauncherCosmosMmScr::onDeinit()
{
    VFX_OBJ_CLOSE(m_content);
    
    VfxAppScr::onDeinit();
}

void VappLauncherCosmosMmScr::onEnter(VfxBool isBackward)
{
    VfxAppScr::onEnter(isBackward);

    m_content->onMainmenuEnter(isBackward);
}

void VappLauncherCosmosMmScr::onEntered(VfxBool isBackward)
{
    VfxAppScr::onEnter(isBackward);

    m_content->onMainmenuEntered();
}

void VappLauncherCosmosMmScr::onExit(VfxBool isBackward)
{
    m_content->onMainmenuExit();
    
    VfxAppScr::onExit(isBackward);
}

void VappLauncherCosmosMmScr::onExited(VfxBool isBackward)
{
    m_content->onMainmenuExited();
    
    VfxAppScr::onExited(isBackward);
}

void VappLauncherCosmosMmScr::onSnapshotEnter()
{
    VfxAppScr::onSnapshotEnter();
    
    m_content->onMainmenuEnter(VFX_TRUE);
}

void VappLauncherCosmosMmScr::onSnapshotExit()
{
    m_content->onMainmenuExited();
    
    VfxAppScr::onSnapshotExit();
}
#endif /* defined(__AFX_RT_TEST__) || !defined(VAPP_LAUNCHER_COSMOS_MM_IN_PAGE) */

#ifdef VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
/*****************************************************************************
 * Class VappLauncherCosmosMmPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmPage", VappLauncherCosmosMmPage, VfxPage);

VappLauncherCosmosMmPage::VappLauncherCosmosMmPage(VappLauncherCosmosMmContent *content):
    m_content(content)
{
}

void VappLauncherCosmosMmPage::onInit()
{
    VfxPage::onInit();
    
    setStatusBarBg(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_STATUS_BAR_BG);
    setTranslucent(VFX_TRUE);
    
    addChildFrame(m_content);
    m_content->setHidden(VFX_FALSE);
    m_content->setFocused(VFX_TRUE);
    m_content->setSize(VAPP_LAUNCHER_COSMOS_MM_SCREEN_WIDTH, VAPP_LAUNCHER_COSMOS_MM_SCREEN_HEIGHT);

    VappLauncherApp *launcherApp = VFX_OBJ_DYNAMIC_CAST(getApp(), VappLauncherApp);
    VFX_ASSERT(launcherApp);

    launcherApp->m_signalInactive.connect(this, &VappLauncherCosmosMmPage::onAppInactive);
}

void VappLauncherCosmosMmPage::onDeinit()
{
    VfxMainScr *mainScr;
    mainScr = VfxMainScr::findMainScr(this);
    VFX_ASSERT(mainScr);
    mainScr->addChildFrame(m_content);
    
    m_content->setHidden(VFX_TRUE);
    m_content->setFocused(VFX_FALSE);
    
    VfxPage::onDeinit();
}

void VappLauncherCosmosMmPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
    
    m_content->onMainmenuEnter(isBackward);
}

void VappLauncherCosmosMmPage::onEntered()
{
    VfxPage::onEntered();
    
    m_content->onMainmenuEntered();
}

void VappLauncherCosmosMmPage::onExited2()
{
    m_content->onMainmenuExit();
    
    VfxPage::onExited2();
}

void VappLauncherCosmosMmPage::onAppInactive(VfxBool isSnapshot)
{
    m_content->onMainmenuExited();
}
#endif // VAPP_LAUNCHER_COSMOS_MM_IN_PAGE


/*****************************************************************************
 * Class VappLauncherCosmosMmContent
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmContent", VappLauncherCosmosMmContent, VfxControl);

VfxS32 VappLauncherCosmosMmContent::s_currentPage = 0;

VappLauncherCosmosMmContent::VappLauncherCosmosMmContent():
    m_statusBar(NULL),
    m_menu(NULL),
    m_builder(NULL),
    m_iconScaleTimeline(NULL),
#ifdef VAPP_LAUNCHER_COSMOS_MM_TRANSLUCENT_BACKGROUND
    m_wallpaperMask(NULL),
#endif
#ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    m_doubleTapSensorHandle(SRV_SENSOR_MOTION_INVALID_PARAM),
    m_doubleTapSwitchDirection(0),
    m_doubleTapTimer(NULL),
#endif
    m_dataSyncVersion(-1),
    m_isDataDirty(VFX_FALSE),
    m_isOrganizeMode(0),
    m_deletingPopup(NULL),
    m_isPopupAutoDestory(VFX_FALSE),
    m_isEnter(VFX_FALSE),
    m_isEnterBackward(VFX_FALSE)
{
}

void VappLauncherCosmosMmContent::onMainmenuEnter(VfxBool isBackward)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM0", SA_start);
#endif

    m_isEnter = VFX_TRUE;
    m_isEnterBackward = isBackward;

#ifdef VAPP_LAUNCHER_COSMOS_MM_RELEASE_UI_ON_EXIT
    initUI();
#endif

    // reload menu
    if (m_dataSyncVersion != vappLauncherCosmosMmGetSycnVersion())
    {
        reloadMainmenu();
    }

    m_menu->refreshMenu();
    m_menu->setCurrentPageIndex(s_currentPage, VFX_FALSE);
    
#ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    startListenMotionSensor();
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM0", SA_stop);
#endif
}

void VappLauncherCosmosMmContent::onMainmenuEntered()
{
    if (!m_isEnterBackward)
    {
        m_menu->preLoadAndCacheNeighborPageCell();
    }
}

void VappLauncherCosmosMmContent::onMainmenuExit()
{
    if (m_isOrganizeMode)
    {
        // Do not leave edit mode if it's in the uninstalling status.
        if (g_vapp_launcher_cosmos_mm_uninstalled_cell != NULL && m_gIsUninstallBtnClicked)
        {
            m_menu->compactPages(VFX_FALSE);
        }
        else
        {
            // The rest of behaviour must leave edit mode (e.g. enter screen lock)
            m_menu->leaveOrganizationMode(VFX_TRUE);
        }
        //m_menu->leaveOrganizationMode();
        m_isDataDirty = VFX_TRUE;
    }

    if (m_isDataDirty)
    {
        m_builder->saveMenu(m_menu);
        vappLauncherCosmosMmSaveData();
        m_isDataDirty = VFX_FALSE;
    }

    m_menu->serializeMenu();
    
#ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
    stopListenMotionSensor();
#endif

    m_isEnter = VFX_FALSE;
}

void VappLauncherCosmosMmContent::onMainmenuExited()
{
#ifdef VAPP_LAUNCHER_COSMOS_MM_RELEASE_UI_ON_EXIT
    deinitUI();
#endif
}

void VappLauncherCosmosMmContent::reloadMainmenu()
{
    vappLauncherCosmosMmCheckLoadOrderData();
    m_isDataDirty |= vappLauncherCosmosMmGetIsDataDirty();
    m_dataSyncVersion = vappLauncherCosmosMmGetSycnVersion();

    if (m_builder != NULL)
    {
        mmi_app_package_name_struct appName;
        if (g_vapp_launcher_cosmos_mm_uninstalled_cell)
        {
            g_vapp_launcher_cosmos_mm_uninstalled_cell->getCellAppName(appName);
        }
        
        m_menu->clearAllMenuItems();
        
        if (g_vapp_launcher_cosmos_mm_uninstalled_cell)
        {
            m_builder->loadMenu(m_menu, &appName, &g_vapp_launcher_cosmos_mm_uninstalled_cell);
        }
        else
        {
            m_builder->loadMenu(m_menu, NULL, NULL);
        }

        if (m_isOrganizeMode)
        {
            m_menu->enterOrganizationMode();
        }
    }
}

void VappLauncherCosmosMmContent::setIsUninstallingMode(VfxBool isUninstalling)
{
    m_menu->setIsUninstallingMode(isUninstalling);
}

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
void VappLauncherCosmosMmContent::setTransitionEffect(VcpPageMenuTransitionType transitionType)
{
    m_menu->setTransitionEffect(transitionType);
}
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__

#ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
void VappLauncherCosmosMmContent::startListenMotionSensor()
{
    if (m_doubleTapSensorHandle == SRV_SENSOR_MOTION_INVALID_PARAM && m_isEnter)
    {
        m_doubleTapSensorHandle = srv_sensor_start_listen(SRV_SENSOR_MOTION_DOUBLE_TAP, NULL, &VappLauncherCosmosMmContent::sensorHandler, this);
    }
}

void VappLauncherCosmosMmContent::stopListenMotionSensor()
{
    if (m_doubleTapSensorHandle != SRV_SENSOR_MOTION_INVALID_PARAM && m_isEnter)
    {
        srv_sensor_stop_listen(m_doubleTapSensorHandle);
        m_doubleTapSensorHandle = SRV_SENSOR_MOTION_INVALID_PARAM;
    }
}
#endif

void VappLauncherCosmosMmContent::onInit()
{
    VfxControl::onInit();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOI", SA_start);
#endif

    VappLauncherScreen *launcherScreen = static_cast<VappLauncherScreen *>(VfxMainScr::findMainScr(this));
    VFX_ASSERT(launcherScreen);
    launcherScreen->m_signalScreenOnEntered.connect(this, &VappLauncherCosmosMmContent::onScreenEntered);
    launcherScreen->setBgColor(VFX_COLOR_TRANSPARENT);
    
#if !defined(VAPP_LAUNCHER_COSMOS_MM_TRANSLUCENT_BACKGROUND)
    setBgColor(VFX_COLOR_BLACK);
#endif

    vappLauncherCosmosMmCheckLoadOrderData();
    m_isDataDirty |= vappLauncherCosmosMmGetIsDataDirty();
    m_dataSyncVersion = vappLauncherCosmosMmGetSycnVersion();

    VappLauncher *launcher = findLauncher();
    VFX_ASSERT(launcher);
    if (!launcher->isRestoreStatus())
    {
        s_currentPage = 0;
    }

#ifndef VAPP_LAUNCHER_COSMOS_MM_RELEASE_UI_ON_EXIT
    initUI();
#endif

    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE,  &VappLauncherCosmosMmContent::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,  &VappLauncherCosmosMmContent::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,  &VappLauncherCosmosMmContent::eventHandler, this);

    s_vappLauncherCosmosMm = this;
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOI", SA_stop);
#endif
}

void VappLauncherCosmosMmContent::onDeinit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOD", SA_start);
#endif
    
    VappLauncherScreen *launcherScreen = static_cast<VappLauncherScreen *>(VfxMainScr::findMainScr(this));
    VFX_ASSERT(launcherScreen);
    launcherScreen->m_signalScreenOnEntered.disconnect(this, &VappLauncherCosmosMmContent::onScreenEntered);
    
#ifndef VAPP_LAUNCHER_COSMOS_MM_RELEASE_UI_ON_EXIT
    deinitUI();
#endif

    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE, &VappLauncherCosmosMmContent::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE, &VappLauncherCosmosMmContent::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE, &VappLauncherCosmosMmContent::eventHandler, this);
    
    s_vappLauncherCosmosMm = NULL;
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOD", SA_stop);
#endif

    VfxControl::onDeinit();
}

VfxBool VappLauncherCosmosMmContent::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
        case VFX_KEY_CODE_BACK:
        case VFX_KEY_CODE_HOME:
            if (m_isOrganizeMode)
            {
                m_menu->leaveOrganizationMode();
                m_builder->saveMenu(m_menu);
                vappLauncherCosmosMmSaveData();
                m_isDataDirty = VFX_FALSE;
                return VFX_TRUE;
            }
            break;
        default:
            break;
        };
    }
    return VfxControl::onKeyInput(event);
}

void VappLauncherCosmosMmContent::initUI()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIU", SA_start);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM1", SA_start);
#endif

    // Create VappLauncherCosmosMmPageMenu
    initMenu();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM1", SA_stop);
#endif
    
#ifdef VAPP_LAUNCHER_COSMOS_MM_TRANSLUCENT_BACKGROUND
    // Create wallpaper translucent mask
    VFX_OBJ_CREATE(m_wallpaperMask, VfxFrame, this);
    m_wallpaperMask->setSize(VAPP_LAUNCHER_COSMOS_MM_SCREEN_WIDTH, VAPP_LAUNCHER_COSMOS_MM_SCREEN_HEIGHT);
    m_wallpaperMask->setBgColor(VFX_COLOR_BLACK);
    m_wallpaperMask->setOpacity(VAPP_LAUNCHER_COSMOS_MM_WALLPAPER_MASK_ALPHA);
    m_wallpaperMask->sendToBack();
#endif
    
#ifndef VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
    // Create status bar
    VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
    m_statusBar->setAutoAnimate(VFX_TRUE);
    m_statusBar->setPos(0, 0);
    m_statusBar->bringToFront();
#endif

    // Connect the notification center changed signal.
    VappNCenter *ncenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    ncenter->m_signalEvent.connect(this, &VappLauncherCosmosMmContent::onNotificationCenterChanged);
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIU", SA_stop);
#endif
}

void VappLauncherCosmosMmContent::deinitUI()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MDU", SA_start);
#endif

    // Disconnect the notification center changed signal.
    VappNCenter *ncenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    ncenter->m_signalEvent.disconnect(this, &VappLauncherCosmosMmContent::onNotificationCenterChanged);
    
    VFX_OBJ_CLOSE(m_statusBar);
#ifdef VAPP_LAUNCHER_COSMOS_MM_TRANSLUCENT_BACKGROUND
    VFX_OBJ_CLOSE(m_wallpaperMask);
#endif
    VFX_OBJ_CLOSE(m_builder);
    VFX_OBJ_CLOSE(m_menu);

	if (m_deletingPopup)
		VFX_OBJ_CLOSE(m_deletingPopup);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MDU", SA_stop);
#endif
}

void VappLauncherCosmosMmContent::initMenu()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM1", SA_start);
#endif

    VFX_OBJ_CREATE(m_menu, VappLauncherCosmosMmPageMenu, this);
    VcpPageMenuLayout layout;
    layout.rowCount = VAPP_LAUNCHER_COSMOS_MM_CELL_ROW_COUNT;
    layout.columnCount = VAPP_LAUNCHER_COSMOS_MM_CELL_COLUMN_COUNT;
    layout.cellStartX = VAPP_LAUNCHER_COSMOS_MM_CELL_START_X;
    layout.cellStartY = VAPP_LAUNCHER_COSMOS_MM_CELL_START_Y;
    layout.cellOffsetX = VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_X;
    layout.cellOffsetY = VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_Y;
    layout.pageMargin = VAPP_LAUNCHER_COSMOS_MM_PAGE_MARGIN;
    layout.bottomBarOffsetY = VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_Y;
    layout.bottomBarVisibleShiftY = VAPP_LAUNCHER_COSMOS_MM_BOTTOM_BAR_VISIBLE_SHIFT_Y;
    m_menu->setPos(VfxPoint(0, 0));
    m_menu->setSize(VfxSize(VAPP_LAUNCHER_COSMOS_MM_SCREEN_WIDTH, VAPP_LAUNCHER_COSMOS_MM_SCREEN_HEIGHT));
    m_menu->setMenuLayout(layout);
    m_menu->setCellIconSize(VfxSize(VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_X, VAPP_LAUNCHER_COSMOS_MM_CELL_OFFSET_Y) );
    m_menu->m_appClicked.connect(this, &VappLauncherCosmosMmContent::onAppClicked);
    m_menu->m_organizationChanged.connect(this, &VappLauncherCosmosMmContent::onOrganizeChanged);
    m_menu->m_pageChanged.connect(this, &VappLauncherCosmosMmContent::onPageChanged);

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    // Read barrel setting from nvram
    VfxS16 sError = 0;
    VfxU8 setting = 0;
    ReadValue(NVRAM_VAPP_LAUNCHER_COSMOS_MM_BARREL_SETTING, (void*)&setting, DS_BYTE, & sError);
    m_menu->setTransitionEffect((VcpPageMenuTransitionType)setting);
#endif // __MMI_VUI_MAIN_MENU_SWITCH_EFFECT__
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM1", SA_stop);
    SLA_CustomLogging("MM1", SA_start);
#endif
    VfxU32 *orderList = vappLauncherCosmosMmGetAllOrderData() + VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA;
    VfxU32 *barOrderList = vappLauncherCosmosMmGetAllOrderData();

    VFX_OBJ_CREATE(m_builder, VappLauncherCosmosMmBuilder, this);
    m_builder->setAppOrderData(orderList, VAPP_LAUNCHER_COSMOS_MM_MAX_APP_DATA);
    m_builder->setAppGroupData(barOrderList, VAPP_LAUNCHER_COSMOS_MM_MAX_GROUP_APP_DATA);
    m_builder->loadMenu(m_menu, NULL, NULL);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM1", SA_stop);
#endif
}

void VappLauncherCosmosMmContent::onScreenEntered(VfxBool isBackward)
{
    if (m_isEnter)
    {
        m_menu->preLoadAndCacheNeighborPageCell();
    }
}

void VappLauncherCosmosMmContent::onAppClicked(VcpPageMenuCell * cell)
{
    VappLauncherCosmosMmCell * mmCell = static_cast<VappLauncherCosmosMmCell*>(cell);
    mmi_app_package_name_struct appName;
    mmCell->getCellAppName(appName);

    if (strncmp(appName, "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) == 0)
    {
#ifdef VAPP_LAUNCHER_COSMOS_MM_IN_PAGE
        VappLauncherCosmosMmPage * container = (VappLauncherCosmosMmPage *)getParentFrame();
#else
        VappLauncherCosmosMmScr * container = (VappLauncherCosmosMmScr *)getParentFrame();
#endif
        container->back();
        return;
    }

    MMI_ID id = srv_appmgr_launch(appName);

    // Remove pressed down effect if still in main menu
    if (s_vappLauncherCosmosMm && m_isEnter && m_menu)
    {
        m_menu->checkUpdate();
    }
    
#if defined(__COSMOS_3D_V10__) && defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
    vcpSseSetupScenarioByApp(appName);
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) */
}

void VappLauncherCosmosMmContent::onOrganizeChanged(VfxBool organizeMode)
{
    m_isOrganizeMode = organizeMode;
}

void VappLauncherCosmosMmContent::onPageChanged(VfxS32 pageIndex)
{
    s_currentPage = pageIndex;
}

VappLauncher *VappLauncherCosmosMmContent::findLauncher()
{
    for (VfxFrame *f = this; f != NULL; f = f->getParentFrame())
    {
        if(f->isKindOf(VFX_OBJ_CLASS_INFO(VappLauncher)))
        {
            return VFX_OBJ_DYNAMIC_CAST(f, VappLauncher);
        }
    }
    
    return NULL;
}

void VappLauncherCosmosMmContent::onDelBtnClicked(VappLauncherCosmosMmCell *cell)
{

    m_gIsUninstallBtnClicked = VFX_TRUE;
    
    // Freeze icon shaking
    setIsUninstallingMode(VFX_TRUE);

    g_vapp_launcher_cosmos_mm_uninstalled_cell = cell;
    mmi_app_package_name_struct appName;
    cell->getCellAppName(appName);

    if ((srv_appmgr_get_app_package_type(appName) == SRV_APPMGR_MRE_APP_PACKAGE_TYPE &&
        srv_mre_appmgr_is_bg_running(appName)) ||
        (srv_appmgr_get_app_package_type(appName) == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE
    #if defined(__J2ME__)
         && srv_java_appfactory_is_app_running(appName)
    #endif
        ))
    {
        // Deleting App is running
        VcpConfirmPopup* popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
        popup->m_signalButtonClicked.connect(this, &VappLauncherCosmosMmContent::onBgRunningPopupClicked);
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        popup->setText((STR_ID_VAPP_LAUNCHER_COSMOS_MM_EXIT_RUNNING_APP));
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setAutoDestory(VFX_TRUE);
        popup->show(VFX_TRUE);        
        
    }
    else
    {
        // append the app name for deleteing
        WCHAR temp[MMI_APP_NAME_MAX_LEN];
        srv_appmgr_get_app_package_name(appName, temp);
        VfxWString strAppName;
        strAppName.loadFromMem(temp);
        VfxWString strAsk = VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_COSMOS_MM_UNINSTALL);
        strAsk += strAppName;
        strAsk += VFX_WSTR("?");


        VcpConfirmPopup* popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
        popup->m_signalButtonClicked.connect(this, &VappLauncherCosmosMmContent::onPopupButtonClicked);
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setInfoType(VCP_POPUP_TYPE_WARNING);
        popup->setText(strAsk);
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        popup->setCustomButton(
            (STR_ID_VAPP_LAUNCHER_COSMOS_MM_UNINSTALL),
            (STR_GLOBAL_CANCEL),
            VCP_POPUP_BUTTON_TYPE_WARNING,
            VCP_POPUP_BUTTON_TYPE_CANCEL);
        popup->setAutoDestory(VFX_TRUE);
        popup->show(VFX_TRUE);    
    }
}

void VappLauncherCosmosMmContent::onBgRunningPopupClicked(VfxObject* obj,VfxId id)
{
    // recover icon shaking
    setIsUninstallingMode(VFX_FALSE);
}

void VappLauncherCosmosMmContent::onPopupButtonClicked(VfxObject* obj,VfxId id)
{

	switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:

            mmi_app_package_name_struct appName;
            g_vapp_launcher_cosmos_mm_uninstalled_cell->getCellAppName(appName);

            // MAUI_03228575, When user confirmed(clicked) to uninstall the app
            // MRE will delete image icon of the app, but VRT did not notify this and keep rendering.
            // So that, the image will turns messy.
            // Solution: suspend VRT until commit.
            // Note: This issue is not happended by 12.24&28MP and the solution is provided by feifei.chen
            VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
            g_vapp_launcher_cosmos_mm_uninstalled_cell->resetCellImage();

            // error handling if uninstall failed.
            if (srv_appmgr_uninstall_app(appName,&VappLauncherCosmosMmContent::onUninstallAppCallback, NULL) == MMI_RET_ERR)
            {
                // show balloon of uninstall failed.
                VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO,VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_COSMOS_MM_DELETE_FAILED));
                g_vapp_launcher_cosmos_mm_uninstalled_cell = NULL;

                return;
            }

            if (g_vapp_launcher_cosmos_mm_uninstalled_cell != NULL)
            {
                VFX_OBJ_CREATE(m_deletingPopup, VcpIndicatorPopup, this);
                m_deletingPopup->setInfoType (VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
                m_deletingPopup->setText((STR_ID_VAPP_LAUNCHER_COSMOS_MM_UNINSTALLING));
                m_deletingPopup->show(VFX_TRUE);
            }
            break;

        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
            g_vapp_launcher_cosmos_mm_uninstalled_cell = NULL;
            break;
    }
    m_gIsUninstallBtnClicked = VFX_FALSE;

    // recover icon shaking
    setIsUninstallingMode(VFX_FALSE);
}

void VappLauncherCosmosMmContent::closeDeletingPopup()
{
    if (!m_deletingPopup)
    {
        //MRE app would call uninstall callback before popup create. Need to add flag for it.
        m_isPopupAutoDestory = VFX_TRUE;
        return;
    }
	
    VFX_OBJ_CLOSE(m_deletingPopup);
	
    if (m_isEnter)
    {
        reloadMainmenu();
    }
    else
    {
        vappLauncherCosmosMmSetNeedSycn();
    }
}

void VappLauncherCosmosMmContent::onUninstallAppCallback(srv_appmgr_cb_event_enum result, void *user_data)
{
    s_vappLauncherCosmosMm->closeDeletingPopup();

    switch (result)
    {
        case SRV_APPMGR_CB_EVENT_DONE:

            return;
        case SRV_APPMGR_CB_EVENT_ERROR:
        case SRV_APPMGR_CB_EVENT_CANCEL:
        default:
            break;
    }
    
    g_vapp_launcher_cosmos_mm_uninstalled_cell = NULL;
}

mmi_ret VappLauncherCosmosMmContent::eventHandler(mmi_event_struct *event)
{
    VappLauncherCosmosMmContent *mainmenuContent = (VappLauncherCosmosMmContent *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
            if (mainmenuContent->m_isEnter)
            {
                mainmenuContent->reloadMainmenu();
            }
            break;
        case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
        {
            if (mainmenuContent->m_isEnter)
            {
                g_vapp_launcher_cosmos_mm_uninstalled_cell->scaleDeletingIcon();
                g_vapp_launcher_cosmos_mm_uninstalled_cell->m_signalDeleteIconScaled.connect(
                    mainmenuContent, &VappLauncherCosmosMmContent::onDeleteIconScaled);
            }
            g_vapp_launcher_cosmos_mm_uninstalled_cell = NULL;
            break;
        }            
        default:
            break;
    }
    return MMI_RET_OK;
}

void VappLauncherCosmosMmContent::onDeleteIconScaled(VfxBool isScaled)
{
    if (isScaled)
    {
        if (m_deletingPopup && !m_isPopupAutoDestory)
            return;
		
        if (m_deletingPopup && m_isPopupAutoDestory)
            VFX_OBJ_CLOSE(m_deletingPopup);

        m_isPopupAutoDestory = VFX_FALSE;

        if (m_isEnter)
        {
            reloadMainmenu();
        }
        else
        {
            vappLauncherCosmosMmSetNeedSycn();
        }
    }
}

void VappLauncherCosmosMmContent::onNotificationCenterChanged(VappNCenterEventEnum event)
{
    switch (event)
    {
        case VAPP_NCENTER_EVENT_ENTER:
            // Suspend icon shaking
            m_menu->setIsEnterNCenter(VFX_TRUE);
            
        #ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
            stopListenMotionSensor();
        #endif
        
            break;

        case VAPP_NCENTER_EVENT_EXITED:
            // Resume icon shaking
            m_menu->setIsEnterNCenter(VFX_FALSE);
            
        #ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
            startListenMotionSensor();
        #endif
        
            break;

        default:
            break;
    }
}

#ifdef VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_TO_CHANGE_SWITCH_EFFECT
void VappLauncherCosmosMmContent::onDoubleTapTimerTick(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);
    
    if (m_doubleTapSwitchDirection == 1)
    {
        m_menu->setCurrentPageIndex(m_menu->getCurrentPageIndex() - 1, VFX_TRUE);
    }
    else if (m_doubleTapSwitchDirection == -1)
    {
        m_menu->setCurrentPageIndex(m_menu->getCurrentPageIndex() + 1, VFX_TRUE);
    }
}

void VappLauncherCosmosMmContent::sensorHandler(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
    VappLauncherCosmosMmContent *mainmenu = (VappLauncherCosmosMmContent *)user_data;
    
    if (mainmenu->m_isOrganizeMode)
    {
        return;
    }

    if (sensor_type == SRV_SENSOR_MOTION_DOUBLE_TAP)
    {
        VcpPageMenuTransitionType transitionType = (VcpPageMenuTransitionType)(mainmenu->m_menu->getTransitionEffect() + 1);
        if (transitionType == VCP_PAGE_MENU_TRANSITION_TYPE_MAX)
        {
            transitionType = VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL;
        }
        mainmenu->m_menu->setTransitionEffect(transitionType);
        
        // Write to NVRAM
        VfxS16 sError = 0;
        WriteValue(NVRAM_VAPP_LAUNCHER_COSMOS_MM_BARREL_SETTING, (void *)&transitionType, DS_BYTE, &sError);
        
        // Play animation
        if (mainmenu->m_menu->getCurrentPageIndex() < mainmenu->m_menu->getPageCount() - 1)
        {
            mainmenu->m_doubleTapSwitchDirection = 1;
            mainmenu->m_menu->setCurrentPageIndex(mainmenu->m_menu->getCurrentPageIndex() + 1, VFX_TRUE);
        }
        else
        {
            mainmenu->m_doubleTapSwitchDirection = -1;
            mainmenu->m_menu->setCurrentPageIndex(mainmenu->m_menu->getCurrentPageIndex() - 1, VFX_TRUE);
        }
        
        VFX_OBJ_CREATE(mainmenu->m_doubleTapTimer, VfxTimer, mainmenu);
        mainmenu->m_doubleTapTimer->m_signalTick.connect(mainmenu, &VappLauncherCosmosMmContent::onDoubleTapTimerTick);
        mainmenu->m_doubleTapTimer->setStartDelay(VAPP_LAUNCHER_COSMOS_MM_MOTION_DOUBLE_TAP_ANIMTIME);
        mainmenu->m_doubleTapTimer->start();
    }
}
#endif


#ifdef __AFX_RT_TEST__
#include "vtst_rt_main.h"
VtstTestResultEnum vtst_rt_vapp_cosmos_mainmenu(VfxU32 param)
{
    vapp_launcher_cosmos_mm_launch(NULL, 0);
    return VTST_TR_OK;
}
#endif // __AFX_RT_TEST__


#endif // __MMI_VUI_LAUNCHER_COSMOS__

