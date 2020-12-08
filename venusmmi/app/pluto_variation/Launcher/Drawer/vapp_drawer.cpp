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
 *  vapp_drawer.cpp
 *
 * Project:
 * --------
 *  Launcher
 *
 * Description:
 * ------------
 *  Launcher drawer
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER__

#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "vrt_system.h"
#include "vfx_async_signal.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_menu_transition.h"
#include "vapp_drawer.h"
#include "vapp_drawer_builder.h"
#include "vapp_drawer_page_menu.h"
#include "vapp_drawer_shortcut_bar.h" // for the order data utils
#include "vapp_drawer_gprot.h"
#include "mmi_rp_vapp_drawer_def.h"

extern "C" {
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "app_mem.h"
#include "CommonScreensResDef.h"
#include "AppMgrSrvGprot.h"
#include "MREAppMgrSrvGprot.h"
#include "JavaAppFactorySrvGprot.h"
#include "PhoneSetupGprots.h"
#include "Wgui.h" // for MMI_STATUS_BAR_HEIGHT
}

#define __VAPP_DRAWER_INSTANTIATE_DEFAULT_ORDER__
#include "vapp_drawer_default_order.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


/*****************************************************************************
 * Define
 *****************************************************************************/

#define VAPP_DRAWER_RELEASE_UI_ON_EXIT

static const VfxS32 VAPP_DRAWER_MAX_CNTX_MEM_SIZE = 300 * 1024;

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_DRAWER_SCREEN_WIDTH = 480;
static const VfxS32 VAPP_DRAWER_SCREEN_HEIGHT = 800;
static const VfxS32 VAPP_DRAWER_BOTTOM_BAR_HEIGHT = 120;
static const VfxS32 VAPP_DRAWER_BOTTOM_BAR_SHADOW_HEIGHT = 4;
static const VfxS32 VAPP_DRAWER_LINE_HEIGHT = 2;

static const VfxS32 VAPP_DRAWER_CELL_ROW_COUNT = 5;
static const VfxS32 VAPP_DRAWER_CELL_COLUMN_COUNT = 4;
static const VfxS32 VAPP_DRAWER_CELL_START_X = 0;
static const VfxS32 VAPP_DRAWER_CELL_START_Y = 69;
static const VfxS32 VAPP_DRAWER_CELL_OFFSET_X = 120;
static const VfxS32 VAPP_DRAWER_CELL_OFFSET_Y = 122;
static const VfxS32 VAPP_DRAWER_PAGE_MARGIN = 27;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_VISIBLE_SHIFT_Y = -2;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_DRAWER_SCREEN_WIDTH = 240;
static const VfxS32 VAPP_DRAWER_SCREEN_HEIGHT = 320;
#else
static const VfxS32 VAPP_DRAWER_SCREEN_WIDTH = 240;
static const VfxS32 VAPP_DRAWER_SCREEN_HEIGHT = 400;
#endif

static const VfxS32 VAPP_DRAWER_BOTTOM_BAR_HEIGHT = 60;
static const VfxS32 VAPP_DRAWER_BOTTOM_BAR_SHADOW_HEIGHT = 2;
static const VfxS32 VAPP_DRAWER_LINE_HEIGHT = 1;

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_DRAWER_CELL_ROW_COUNT = 3;
static const VfxS32 VAPP_DRAWER_CELL_COLUMN_COUNT = 3;
#else
static const VfxS32 VAPP_DRAWER_CELL_ROW_COUNT = 4;
static const VfxS32 VAPP_DRAWER_CELL_COLUMN_COUNT = 3;
#endif

static const VfxS32 VAPP_DRAWER_CELL_START_X = 0;
static const VfxS32 VAPP_DRAWER_CELL_START_Y = 40;
static const VfxS32 VAPP_DRAWER_CELL_OFFSET_X = 80;

#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_DRAWER_CELL_OFFSET_Y = 73;
#else
static const VfxS32 VAPP_DRAWER_CELL_OFFSET_Y = 75;
#endif

static const VfxS32 VAPP_DRAWER_PAGE_MARGIN = 15;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_VISIBLE_SHIFT_Y = -6;

#else // default HVGA 320X480
static const VfxS32 VAPP_DRAWER_SCREEN_WIDTH = 320;
static const VfxS32 VAPP_DRAWER_SCREEN_HEIGHT = 480;
static const VfxS32 VAPP_DRAWER_BOTTOM_BAR_HEIGHT = 80;
static const VfxS32 VAPP_DRAWER_BOTTOM_BAR_SHADOW_HEIGHT = 2;
static const VfxS32 VAPP_DRAWER_LINE_HEIGHT = 1;

static const VfxS32 VAPP_DRAWER_CELL_ROW_COUNT = 4;
static const VfxS32 VAPP_DRAWER_CELL_COLUMN_COUNT = 4;
static const VfxS32 VAPP_DRAWER_CELL_START_X = 0;
static const VfxS32 VAPP_DRAWER_CELL_START_Y = 40;
static const VfxS32 VAPP_DRAWER_CELL_OFFSET_X = 80;
static const VfxS32 VAPP_DRAWER_CELL_OFFSET_Y = 90;
static const VfxS32 VAPP_DRAWER_PAGE_MARGIN = 20;
static const VfxS32 VAPP_DRAWER_SHORTCUT_BAR_VISIBLE_SHIFT_Y = -5;

#endif

static const VfxS32 VAPP_DRAWER_BOTTOM_BAR_Y = VAPP_DRAWER_SCREEN_HEIGHT - VAPP_DRAWER_BOTTOM_BAR_HEIGHT;

static const VfxS32 VAPP_DRAWER_CELL_COUNT_IN_PAGE = VAPP_DRAWER_CELL_ROW_COUNT * VAPP_DRAWER_CELL_COLUMN_COUNT;

static const VfxColor VAPP_DRAWER_SPLITTER_COLOR = VfxColor(255, 80, 80, 80);

/*****************************************************************************
 * Enum
 *****************************************************************************/
 
enum vapp_drawer_scr_enum
{
    SCR_ID_VAPP_DRAWER_BASE = VAPP_DRAWER,
    SCR_ID_VAPP_DRAWER_MAIN,
    SCR_ID_VAPP_DRAWER_END_OF_ENUM
};

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

static mmi_id g_vapp_drawer_group_id = GRP_ID_INVALID;
static VappDrawerScr *g_vapp_drawer_scr = NULL;
static VappDrawerCell *g_vapp_drawer_uninstalled_cell = NULL;

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

static mmi_ret vapp_drawer_group_proc(mmi_event_struct* evt);
static void vapp_drawer_entry();
static void vapp_drawer_exit();
static void vapp_drawer_init();
static void vapp_drawer_deinit();

static mmi_ret vapp_post_display_confirm(mmi_event_struct *evt);
static mmi_ret vapp_drawer_confirm_proc(mmi_alert_result_evt_struct *evt);
static void vapp_display_popup(VappDrawerPopupCtx *popupCtx);
static void vapp_drawer_uninstall_app_callback(srv_appmgr_cb_event_enum result, void *user_data);
static mmi_ret vapp_drawer_post_delete_uninstall_screen(mmi_event_struct *evt);


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

static mmi_ret vapp_drawer_group_proc(mmi_event_struct* evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
            VappDrawerScr::setOrganizeChanged(VFX_FALSE);
            break;
        case EVT_ID_GROUP_DEINIT:
            g_vapp_drawer_group_id = GRP_ID_INVALID;
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

static void vapp_drawer_entry()
{
    if (mmi_frm_scrn_enter(g_vapp_drawer_group_id,
                           SCR_ID_VAPP_DRAWER_MAIN,
                           vapp_drawer_exit,
                           vapp_drawer_entry,
                           MMI_FRM_FULL_SCRN))
    {
        vapp_drawer_init();
    }
}

static void vapp_drawer_exit()
{
    vapp_drawer_deinit();
}

static void vapp_drawer_init()
{
    VfxAppCatScr::initalizeWithScrAsmSize(VAPP_DRAWER_MAX_CNTX_MEM_SIZE);
    
	VFX_OBJ_CREATE(g_vapp_drawer_scr, VappDrawerScr, VfxAppCatScr::getContext());
}

static void vapp_drawer_deinit()
{
    VFX_OBJ_CLOSE(g_vapp_drawer_scr);
    
    VfxAppCatScr::deinitalize();
}

static mmi_ret vapp_post_display_confirm(mmi_event_struct *evt)
{
    if (evt && g_vapp_drawer_group_id != GRP_ID_INVALID)
    {
        VappDrawerConfirmCtx *confirmCtx = (VappDrawerConfirmCtx *)(evt->user_data);
        
        mmi_confirm_property_struct confirmProperty;
        mmi_confirm_property_init(&confirmProperty, confirmCtx->ctype);
        confirmProperty.callback = confirmCtx->proc;
        confirmProperty.parent_id = g_vapp_drawer_group_id;
        confirmProperty.f_auto_question_mark = MMI_TRUE;
        
        const MMI_STR_ID string_id = confirmCtx->string_id;
        mmi_event_notify_enum event = confirmCtx->event;
        
        VFX_FREE_MEM(confirmCtx);
        
        mmi_confirm_display_ext(
            string_id,
            event,
            &confirmProperty);
    }
    
    return MMI_RET_OK;
}

static mmi_ret vapp_drawer_confirm_proc(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                VappDrawerPopupCtx popupCtx;
                popupCtx.string_id = STR_ID_VAPP_DRAWER_UNINSTALLING;
                popupCtx.event = MMI_EVENT_PROGRESS;
                popupCtx.parent_id = g_vapp_drawer_group_id;
                vapp_display_popup(&popupCtx);
                
                mmi_app_package_name_struct appName;
                g_vapp_drawer_uninstalled_cell->getCellAppName(appName);
                if (srv_appmgr_uninstall_app(appName, vapp_drawer_uninstall_app_callback, NULL) == MMI_RET_ERR)
                {
                    VappDrawerPopupCtx popupCtx;
                    popupCtx.string_id = STR_GLOBAL_FAILED;
                    popupCtx.event = MMI_EVENT_FAILURE;
                    popupCtx.parent_id = g_vapp_drawer_group_id;
                    vapp_display_popup(&popupCtx);
                    
                    g_vapp_drawer_uninstalled_cell = NULL;
                }
            	break;
            	
            case MMI_ALERT_CNFM_NO:
                g_vapp_drawer_uninstalled_cell = NULL;
            	break;
        }
    }
    
    return MMI_RET_OK;
}

static void vapp_display_popup(VappDrawerPopupCtx *popupCtx)
{
    mmi_popup_property_struct popup_property;
    mmi_popup_property_init(&popup_property);
    
    if (popupCtx)
    {
        if (popupCtx->event == MMI_EVENT_PROGRESS)
        {
            popup_property.f_auto_dismiss = MMI_FALSE;
        }
        else
        {
            popup_property.f_auto_dismiss = MMI_TRUE;
        }
        popup_property.parent_id = popupCtx->parent_id;
        mmi_popup_display_ext(popupCtx->string_id, popupCtx->event, &popup_property);
    }
}

static void vapp_drawer_uninstall_app_callback(srv_appmgr_cb_event_enum result, void *user_data)
{
    VappDrawerPopupCtx popupCtx;
    
    switch (result)
    {
        case SRV_APPMGR_CB_EVENT_DONE:
			mmi_event_struct evt;
 			MMI_FRM_INIT_EVENT(&evt, 0);
			mmi_frm_post_event(&evt, vapp_drawer_post_delete_uninstall_screen, 0);
			return;
            
        case SRV_APPMGR_CB_EVENT_ERROR:
        case SRV_APPMGR_CB_EVENT_CANCEL:
        default:
            popupCtx.string_id = STR_GLOBAL_FAILED;
            popupCtx.event = MMI_EVENT_FAILURE;
            break;
    }

    if (g_vapp_drawer_group_id != GRP_ID_INVALID)
    {
        popupCtx.parent_id  = g_vapp_drawer_group_id;
    }
    else
    {
        popupCtx.parent_id  = GRP_ID_ROOT;
    }
    vapp_display_popup(&popupCtx);
    
    g_vapp_drawer_uninstalled_cell = NULL;
}

static mmi_ret vapp_drawer_post_delete_uninstall_screen(mmi_event_struct *evt)
{
    mmi_frm_display_dummy_screen();
	mmi_frm_scrn_close_active_id();
	return MMI_RET_OK;
}


/*****************************************************************************
 * Global Function
 *****************************************************************************/
extern "C" MMI_ID vapp_drawer_launch(void *param, U32 param_size)
{
    g_vapp_drawer_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vapp_drawer_group_proc, NULL);
    mmi_frm_group_enter(g_vapp_drawer_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    vapp_drawer_entry();

    return g_vapp_drawer_group_id;
}

void vapp_drawer_uninstall_app(VappDrawerCell *cell)
{
    g_vapp_drawer_uninstalled_cell = cell;
    
    mmi_app_package_name_struct appName;
    g_vapp_drawer_uninstalled_cell->getCellAppName(appName);
    
    if ((srv_appmgr_get_app_package_type(appName) == SRV_APPMGR_MRE_APP_PACKAGE_TYPE &&
        srv_mre_appmgr_is_bg_running(appName))
    #ifdef __J2ME__
        ||
        (srv_appmgr_get_app_package_type(appName) == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE &&
        srv_java_appfactory_is_app_running(appName))
    #endif
        )
    {
        VappDrawerPopupCtx popupCtx;
        popupCtx.string_id = STR_ID_VAPP_DRAWER_EXIT_RUNNING_APP;
        popupCtx.event = MMI_EVENT_FAILURE;
        popupCtx.parent_id = g_vapp_drawer_group_id;
        vapp_display_popup(&popupCtx);
    }
    else
    {
        VappDrawerConfirmCtx *confirmCtx;
        VFX_ALLOC_MEM(confirmCtx, sizeof(VappDrawerConfirmCtx), g_vapp_drawer_scr);
        
        confirmCtx->string_id = STR_ID_VAPP_DRAWER_UNINSTALL;
        confirmCtx->event = MMI_EVENT_QUERY;
        confirmCtx->ctype = CNFM_TYPE_YESNO;
        confirmCtx->proc = (mmi_proc_func)vapp_drawer_confirm_proc;
        
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, vapp_post_display_confirm, confirmCtx);
    }
}

/***************************************************************************** 
 * Class VappDrawerScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDrawerScr", VappDrawerScr, VfxAppCatScr);

VfxS32 VappDrawerScr::m_currentPage = 0;
VfxBool VappDrawerScr::m_isOrganizeMode = VFX_FALSE;

VappDrawerScr::VappDrawerScr():
    m_statusBar(NULL),
    m_menu(NULL),
    m_builder(NULL),
    m_bgImageFrame(NULL),
    m_shortcutBarBgFrame(NULL),
    m_shortcutBarBgFrameShadow(NULL),
    m_isDataDirty(VFX_FALSE)
{
    for (VfxS32 i = 0; i < 5; ++i)
    {
        m_lines[i] = NULL;
    }
}

void VappDrawerScr::reloadMainmenu()
{
    vappDrawerCheckLoadOrderData();
    m_isDataDirty |= vappDrawerGetIsDataDirty();
    
    if (m_builder != NULL)
    {
        m_menu->clearAllMenuItems();
        m_builder->loadMenu(m_menu);
    }
}

void VappDrawerScr::setOrganizeChanged(VfxBool organizeMode)
{
    m_isOrganizeMode = organizeMode;
}

void VappDrawerScr::onInit()
{
    VfxAppCatScr::onInit();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOI", SA_start);
#endif
    // allocate mem
    vappDrawerCheckLoadOrderData();
    m_isDataDirty |= vappDrawerGetIsDataDirty();

#ifndef VAPP_DRAWER_RELEASE_UI_ON_EXIT
    initUI();
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOI", SA_stop);
#endif
}

void VappDrawerScr::onDeinit()
{
#ifndef VAPP_DRAWER_RELEASE_UI_ON_EXIT
    deinitUI();
#endif

    VfxAppCatScr::onDeinit();
}

void VappDrawerScr::onEnter(VfxBool isBackward)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOE", SA_start);
#endif
    VfxAppCatScr::onEnter(isBackward);

    if (!isBackward)
    {
        m_currentPage = 0;
        m_isOrganizeMode = VFX_FALSE;
    }

#ifdef VAPP_DRAWER_RELEASE_UI_ON_EXIT
    initUI();
#endif

    if (m_isOrganizeMode)
    {
        m_menu->enterOrganizationMode();
    }

    m_menu->showMenuItems();
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOE", SA_stop);
#endif
}

void VappDrawerScr::onExit(VfxBool isBackward)
{
    if (m_isOrganizeMode)
    {
        if (g_vapp_drawer_uninstalled_cell == NULL)
        {
            m_menu->leaveOrganizationMode(VFX_FALSE);
        }
        else
        {
            m_menu->compactPages(VFX_FALSE);
        }
        
        m_isDataDirty = VFX_TRUE;
    }

    if (m_isDataDirty)
    {
        m_builder->saveMenu(m_menu);
        vappDrawerSaveData();
        m_isDataDirty = VFX_FALSE;
    }

    VfxAppCatScr::onExit(isBackward);
}

void VappDrawerScr::onExited(VfxBool isBackward)
{
#ifdef VAPP_DRAWER_RELEASE_UI_ON_EXIT
    deinitUI();
#endif

    VfxAppCatScr::onExited(isBackward);
}

void VappDrawerScr::onSnapshotEnter()
{
    VfxAppCatScr::onSnapshotEnter();

#ifdef VAPP_DRAWER_RELEASE_UI_ON_EXIT
    initUI();
#endif

    if (m_isOrganizeMode)
    {
        m_menu->enterOrganizationMode();
    }

    m_menu->showMenuItems();
}

void VappDrawerScr::onSnapshotExit()
{
#ifdef VAPP_DRAWER_RELEASE_UI_ON_EXIT
    deinitUI();
#endif

    VfxAppCatScr::onSnapshotExit();
}

VfxBool VappDrawerScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
        case VFX_KEY_CODE_LSK:
        case VFX_KEY_CODE_CSK:
            if (m_isOrganizeMode)
            {
                m_menu->leaveOrganizationMode();
                m_builder->saveMenu(m_menu);
                vappDrawerSaveData();
                m_isDataDirty = VFX_FALSE;
            }
            return VFX_TRUE;
        case VFX_KEY_CODE_RSK:
            if (m_isOrganizeMode)
            {
                m_menu->leaveOrganizationMode();
                m_builder->saveMenu(m_menu);
                vappDrawerSaveData();
                m_isDataDirty = VFX_FALSE;
            }
            else
            {
                mmi_frm_scrn_close_active_id();
            }
            return VFX_TRUE;
        default:
            break;
        };
    }
    return VfxAppCatScr::onKeyInput(event);
}


void VappDrawerScr::initMenu()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIM", SA_start);
#endif
    VFX_OBJ_CREATE(m_menu, VappDrawerPageMenu, this);
    VcpPageMenuLayout layout;
    layout.rowCount = VAPP_DRAWER_CELL_ROW_COUNT;
    layout.columnCount = VAPP_DRAWER_CELL_COLUMN_COUNT;
    layout.cellStartX = VAPP_DRAWER_CELL_START_X;
    layout.cellStartY = VAPP_DRAWER_CELL_START_Y;
    layout.cellOffsetX = VAPP_DRAWER_CELL_OFFSET_X;
    layout.cellOffsetY = VAPP_DRAWER_CELL_OFFSET_Y;
    layout.pageMargin = VAPP_DRAWER_PAGE_MARGIN;
    layout.bottomBarOffsetY = VAPP_DRAWER_BOTTOM_BAR_Y;
    layout.bottomBarVisibleShiftY = VAPP_DRAWER_SHORTCUT_BAR_VISIBLE_SHIFT_Y;
    m_menu->setMenuLayout(layout);
    m_menu->setPos(VfxPoint(0, 0));
    m_menu->setSize(VfxSize(VAPP_DRAWER_SCREEN_WIDTH, VAPP_DRAWER_SCREEN_HEIGHT));
    m_menu->setCellIconSize(VfxSize(VAPP_DRAWER_CELL_OFFSET_X, VAPP_DRAWER_CELL_OFFSET_Y) );
    m_menu->m_appClicked.connect(this, &VappDrawerScr::onAppClicked);
    m_menu->m_organizationChanged.connect(this, &VappDrawerScr::onOrganizeChanged);

#if defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
    mmi_phnset_menu_transition_type_enum transitionType = mmi_phnset_menu_effect_get_menu_transition_type();
    if (transitionType == MMI_PHNSET_VCP_PAGE_MENU_TRANSITION_TYPE_SHUFFLE)
    {
        m_menu->setTransitionEffect((VcpPageMenuTransitionType)(VCP_PAGE_MENU_TRANSITION_TYPE_NORMAL + rand()%VCP_PAGE_MENU_TRANSITION_TYPE_MAX));
    }
    else
    {
        m_menu->setTransitionEffect((VcpPageMenuTransitionType)(transitionType - 1));
    }
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIM", SA_stop);
    SLA_CustomLogging("MIM", SA_start);
#endif
    mmi_app_package_name_struct * orderList = vappDrawerGetAllOrderData() + VAPP_DRAWER_MAX_GROUP_APP_DATA;
    mmi_app_package_name_struct * barOrderList = vappDrawerGetAllOrderData();
    
    VFX_OBJ_CREATE(m_builder, VappDrawerBuilder, this);
    m_builder->setAppOrderData(orderList, VAPP_DRAWER_MAX_APP_DATA);
    m_builder->setAppGroupData(barOrderList, VAPP_DRAWER_MAX_GROUP_APP_DATA);
    m_builder->loadMenu(m_menu);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIM", SA_stop);
#endif
}

void VappDrawerScr::initUI()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIU", SA_start);
#endif

    // create bg image frame
    VFX_OBJ_CREATE(m_bgImageFrame, VfxFrame, this);
    m_bgImageFrame->setPos(0, 0);
    m_bgImageFrame->setSize(VAPP_DRAWER_SCREEN_WIDTH, VAPP_DRAWER_SCREEN_HEIGHT);
    m_bgImageFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_DRAWER_BG));
    m_bgImageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgImageFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    vcpPageMenuApplyFrameRenderHints(m_bgImageFrame);

    // create the split lines
    for (VfxS32 i = 0; i < VAPP_DRAWER_CELL_ROW_COUNT - 1; ++i)
    {
        const VfxS32 posY = VAPP_DRAWER_CELL_START_Y + VAPP_DRAWER_CELL_OFFSET_Y +
            VAPP_DRAWER_CELL_OFFSET_Y * i;
        VFX_OBJ_CREATE(m_lines[i], VfxFrame, this);
        m_lines[i]->setPos(0, posY);
        m_lines[i]->setSize(VAPP_DRAWER_SCREEN_WIDTH, VAPP_DRAWER_LINE_HEIGHT);
        m_lines[i]->setBgColor(VAPP_DRAWER_SPLITTER_COLOR);
        m_lines[i]->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
        vcpPageMenuApplyFrameRenderHints(m_lines[i]);
    }

    // create bg
    VFX_OBJ_CREATE(m_shortcutBarBgFrame, VfxFrame, this);
    m_shortcutBarBgFrame->setPos(0, VAPP_DRAWER_BOTTOM_BAR_Y);
    m_shortcutBarBgFrame->setSize(VAPP_DRAWER_SCREEN_WIDTH, VAPP_DRAWER_BOTTOM_BAR_HEIGHT);
    m_shortcutBarBgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_DRAWER_TOOLBAR_BG));
    m_shortcutBarBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_shortcutBarBgFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    vcpPageMenuApplyFrameRenderHints(m_shortcutBarBgFrame);

    // create bg shadow
    VFX_OBJ_CREATE(m_shortcutBarBgFrameShadow, VfxFrame, this);
    m_shortcutBarBgFrameShadow->setPos(0, VAPP_DRAWER_BOTTOM_BAR_Y -
            VAPP_DRAWER_BOTTOM_BAR_SHADOW_HEIGHT);
    m_shortcutBarBgFrameShadow->setSize(VAPP_DRAWER_SCREEN_WIDTH,
            VAPP_DRAWER_BOTTOM_BAR_SHADOW_HEIGHT);
    m_shortcutBarBgFrameShadow->setImgContent(VfxImageSrc(IMG_ID_VAPP_DRAWER_TOOLBAR_SHADOW) );
    m_shortcutBarBgFrameShadow->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    // create status bar
    VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
    m_statusBar->setAutoAnimate(VFX_TRUE);
    m_statusBar->setPos(0, 0);
    vcpPageMenuApplyFrameRenderHints(m_statusBar);

    // create VappDrawerPageMenu
    initMenu();

    m_menu->setCurrentPageIndex(m_currentPage, VFX_FALSE);

    m_statusBar->bringToFront();
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIU", SA_stop);
#endif
}

void VappDrawerScr::deinitUI()
{
    m_currentPage = m_menu->getCurrentPageIndex();
    VFX_OBJ_CLOSE(m_statusBar);
    VFX_OBJ_CLOSE(m_builder);
    VFX_OBJ_CLOSE(m_menu);
    VFX_OBJ_CLOSE(m_shortcutBarBgFrameShadow);
    VFX_OBJ_CLOSE(m_shortcutBarBgFrame);
    VFX_OBJ_CLOSE(m_bgImageFrame);

    for (VfxS32 i = 0; i < VAPP_DRAWER_CELL_ROW_COUNT - 1; ++i)
    {
        VFX_OBJ_CLOSE(m_lines[i]);
    }
}

void VappDrawerScr::onAppClicked(VcpPageMenuCell *cell)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOA", SA_start);
#endif
    VappDrawerCell *mmCell = static_cast<VappDrawerCell*>(cell);
    mmi_app_package_name_struct appName;
    mmCell->getCellAppName(appName);

    if (strncmp(appName, "native.mtk.desktop", MMI_APP_NAME_MAX_LEN) == 0)
    {
        mmi_frm_scrn_close_active_id();
        return;
    }
    if (strncmp(appName, "native.mtk.drawer", MMI_APP_NAME_MAX_LEN) == 0)
    {
        m_menu->setEnableMenuAnim(VFX_TRUE);
        return;
    }
    srv_appmgr_launch(appName);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOA", SA_stop);
#endif
}

void VappDrawerScr::onOrganizeChanged(VfxBool organizeMode)
{
    m_isOrganizeMode = organizeMode;
}

VfxS32 vappDrawerGetCellCountInPage()
{
    return VAPP_DRAWER_CELL_COUNT_IN_PAGE;
}

#endif // __MMI_VUI_LAUNCHER__

