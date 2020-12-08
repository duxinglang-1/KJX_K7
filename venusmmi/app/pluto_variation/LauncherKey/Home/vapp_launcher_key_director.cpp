/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_launcher_key_director.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the key launcher director.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vfx_adp_device.h"

#include "vapp_launcher_key_def.h"
#include "vapp_launcher_key_primitive.h"
#include "vapp_op_launcher_key_hs.h"
#include "vapp_launcher_key_widget_menu.h"
#include "vapp_launcher_key_director.h"
#include "vapp_launcher_key_gprot.h"
#include "mmi_rp_vapp_launcher_key_def.h"
#include "vapp_launcher_key_mainmenu.h"
#include "vapp_widget_system.h"

//
// Wallpaper:
//
#include "vapp_wallpaper.h"
#include "vapp_wallpaper_kit.h"
#include "vapp_wallpaper_cfg.h"

//
// C headers
//
extern "C"
{
#include "Wgui.h"	
#include "mmi_frm_events_gprot.h"
#include "mmi_common_app_trc.h"
#include "IdleGprot.h"
#include "PhoneSetupGprots.h"
#include "mmi_frm_mem_gprot.h"
#include "app_mem.h"

#if defined(VAPP_KEYLAUNCHER_UT_ENABLE_SWLA_LOG)
#include "SST_sla.h"
#endif
}


/*****************************************************************************
 * KeyLauncher Director
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappKeyLauncherDirector", VappKeyLauncherDirector, VfxAppCatScr);

VappKeyLauncherDirector::KeyLauncherPage VappKeyLauncherDirector::s_currentPage = VappKeyLauncherDirector::IDLE_PAGE;
VappKeyLauncherDirector::KeyLauncherPage VappKeyLauncherDirector::s_perviousPage = VappKeyLauncherDirector::IDLE_PAGE;

VappKeyLauncherDirector::VappKeyLauncherDirector() :
	m_switchToPage(NULL_PAGE),
	m_idlePage(NULL),
	m_widgetMenu(NULL),
	m_needWidgetMenuFlyIn(VFX_FALSE),
	m_mainmenu(NULL),
	m_needMainMenuFlyIn(VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_NONE),
	m_container(NULL),
    m_wallpaper(NULL),
    m_timerResumeWallpaper(NULL),
    m_toolbar(NULL),
    m_statusIconBar(NULL),
    m_captureKey(VFX_FALSE),
    m_isCapturedPen(VFX_FALSE)
{
    // Do nothing.
}
VappKeyLauncherDirector::VappKeyLauncherDirector(MMI_ID app_id) :
	VfxAppCatScr(app_id),
	m_switchToPage(NULL_PAGE),
	m_idlePage(NULL),
	m_widgetMenu(NULL),
	m_needWidgetMenuFlyIn(VFX_FALSE),
	m_mainmenu(NULL),
	m_needMainMenuFlyIn(VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_NONE),
	m_container(NULL),
    m_wallpaper(NULL),
    m_timerResumeWallpaper(NULL),
    m_toolbar(NULL),
    m_statusIconBar(NULL),
    m_captureKey(VFX_FALSE),
    m_isCapturedPen(VFX_FALSE)
{
    // Do nothing.
}

void VappKeyLauncherDirector::onInit()
{
    VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_ON_INIT, 100));

    VAPP_KEYLAUNCHER_SLA(("HI0", SA_start));

    VfxAppCatScr::onInit();

	// Init Widget Module, it will be executed only once
	vapp_widget_sys_init();

    createWallpaper(WALLPAPER_CREATE_DELAY_TIME);

    createStatusIconBar();
	
	// Mainmenu has its own toolbar, so we only create toolbar for idle page or widget page
	// So need hidden it in Mainmenu page
    createToolbar();

	// User press End key in other App, we should goto Idle page or widget page
	// So s_currentPage will be modify when press End key
	createObjofPage(s_currentPage);

	registerKeyHandler(VFX_KEY_CODE_CSK);

    VAPP_KEYLAUNCHER_SLA(("HI0", SA_stop));

    VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_ON_INIT, 200));
}


void VappKeyLauncherDirector::onDeinit()
{
    VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_ON_DEINIT, 100));

    VAPP_KEYLAUNCHER_SLA(("HD1", SA_start));

    releaseToolbar();

	releaseAllObjofPage();

    releaseStatusIconBar();

    releaseWallpaper();

    VfxAppCatScr::onDeinit();

    VAPP_KEYLAUNCHER_SLA(("HD1", SA_stop));

    VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_ON_DEINIT, 200));
}


void VappKeyLauncherDirector::onExit(VfxBool isBackward)
{
    // It is for video wallpaper
    // Video wallpaper is allow to snapshot when it is suspended
    if (m_wallpaper)
    	m_wallpaper->suspend();
}


VfxBool VappKeyLauncherDirector::onKeyInput(VfxKeyEvent &event)
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_ON_KEY_INPUT,
							event.keyCode, event.type, s_currentPage, s_perviousPage, m_captureKey));
	//
    // CSK.
    //
    if (event.keyCode == VFX_KEY_CODE_CSK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (s_currentPage == IDLE_PAGE)
        {
            switchPage(MAINMENU_PAGE, IDLE_PAGE, VFX_TRUE);			
			return VFX_TRUE;
        }
    }

	//
	//  End Key. (LSK/RSK will be handle by VcpSoftKey)
	//
	if (event.keyCode == VFX_KEY_CODE_END && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (s_currentPage == MAINMENU_PAGE)
        {
			m_captureKey = VFX_TRUE;
            switchPage(s_perviousPage, MAINMENU_PAGE);
			return VFX_TRUE;
        }
    }
	if (event.keyCode == VFX_KEY_CODE_END && event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        if (m_captureKey == VFX_TRUE)
        {
			m_captureKey = VFX_FALSE;
			return VFX_TRUE;
        }
    }

	if ((event.keyCode == VFX_KEY_CODE_ARROW_UP ||
		event.keyCode == VFX_KEY_CODE_ARROW_LEFT ||
  		event.keyCode == VFX_KEY_CODE_ARROW_RIGHT || 
  		event.keyCode == VFX_KEY_CODE_ARROW_DOWN) && s_currentPage != IDLE_PAGE)
	{
		// LNK,RNK,DNK,UNK maybe action for Dediacted Key, only in Idle page
		return VFX_TRUE;
	}

    return VfxAppCatScr::onKeyInput(event);
}


VfxBool VappKeyLauncherDirector::onPenInput(VfxPenEvent &event)
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_ON_PEN_INPUT,
                           event.type, event.pos.x, event.pos.y));
	
	
    if (!m_isCapturedPen && event.type != VFX_PEN_EVENT_TYPE_DOWN)
    {
        return VfxAppCatScr::onPenInput(event);
    }
	
    //
    // Notify the wallpaper that a pen event comes. Wallpaper might show heavy
    // animation for this pen input. For performance, we only notify the
    // wallpaper when this pen event is directly comes from this director,
    // rather than captured other UI component, e.g., widgets.
    //
	m_wallpaper->doPenInput(event);
	
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
		case VFX_PEN_EVENT_TYPE_LONG_TAP:
			
            m_isCapturedPen = VFX_TRUE;

            break;

        case VFX_PEN_EVENT_TYPE_UP:
        case VFX_PEN_EVENT_TYPE_ABORT:

            m_isCapturedPen = VFX_FALSE;
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


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
#endif

void VappKeyLauncherDirector::createObjofPage(KeyLauncherPage page)
{
	if (page == IDLE_PAGE)
	{
		if (m_idlePage)
		{
			m_idlePage->setHidden(VFX_FALSE);
		}
		else
		{
		#ifndef __OP01_3G__
			VFX_OBJ_CREATE(m_idlePage, VappKeyLauncherIdlePage, this);
        #else
            VFX_OBJ_CREATE(m_idlePage, VappOpKeyLauncherIdlePage, this);
        #endif
			m_idlePage->setHidden(VFX_FALSE); // for receive Key event
			m_idlePage->setRect(0, 0, /*m_statusIconBar->getSize().height, */
				LCD_WIDTH, 
				LCD_HEIGHT);// - m_statusIconBar->getSize().height);// - VAPP_KMM_SOFTKEY_BAR_HEIGHT);//VappKeyLauncherToolbar's height);
		}
		m_idlePage->addChildFrame(m_toolbar);
		m_toolbar->setStyle(VappKeyLauncherToolbar::STYLE_IDLE);
	}
	else if (page == WIDGET_PAGE)
	{
		createWidgetMenu();
		m_widgetMenu->addChildFrame(m_toolbar);
		m_toolbar->setStyle(VappKeyLauncherToolbar::STYLE_WIDGETS);
	}
	else if (page == MAINMENU_PAGE)
	{
		m_toolbar->setHidden(VFX_TRUE);

		createMainMenu();
	}

	m_statusIconBar->bringToFront();
}


void VappKeyLauncherDirector::releaseObjofPage(KeyLauncherPage page)
{
	if (page == IDLE_PAGE)
	{
		if (m_idlePage)
		{
			m_idlePage->setHidden(VFX_TRUE);
		}
	}
	else if (page == WIDGET_PAGE)
	{
		releaseWidgetMenu(VFX_FALSE);
	}
	else if (page == MAINMENU_PAGE)
	{
		m_toolbar->setHidden(VFX_FALSE);
		releaseMainMenu(VFX_FALSE);
	}
}


void VappKeyLauncherDirector::releaseAllObjofPage()
{
	// Idle page
	VFX_OBJ_CLOSE(m_idlePage);
	
	// Widget page
	releaseWidgetMenu(VFX_TRUE);

	// Mainmenu page
	releaseMainMenu(VFX_TRUE);
}


void VappKeyLauncherDirector::switchPage(KeyLauncherPage to_page, KeyLauncherPage from_page, VfxBool needFlyIn)
{
	if (m_switchToPage != NULL_PAGE)
	{
		return; // Indicate it is being aync switching page, in case quick press key/pen to switch page
	}

	delayWallpaper(1000); // Start more timer to resume wallpaper, because will draw another page

	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_SWITCH_PAGE, from_page, to_page, needFlyIn));

	if (from_page != MAINMENU_PAGE)
	{
		s_perviousPage = from_page;
	}
	if (to_page == MAINMENU_PAGE)
	{
		if (from_page == IDLE_PAGE)
			m_needMainMenuFlyIn = VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_FROM_IDLE;
		else if (from_page == WIDGET_PAGE)
			m_needMainMenuFlyIn = VAPP_LAUNCHER_KMM_ENTRY_ANIM_TYPE_FROM_WIDGET;
	}

	releaseObjofPage(from_page);

	if (from_page == WIDGET_PAGE)
	{
		// We need show Widget menu fly out animation, 
		// After it is done, start show to_page in onWidgetMenuFly
		m_switchToPage = to_page;
		return;
	}

	if (to_page == WIDGET_PAGE)
	{
		m_needWidgetMenuFlyIn = needFlyIn;
	}
	
	createObjofPage(to_page);
	s_currentPage = to_page;
}


void VappKeyLauncherDirector::createWidgetMenu()
{
	// When enter Widget menu page, should suspend wallpaper
	//m_wallpaper->suspend();
	
	if (m_widgetMenu)
	{
		m_widgetMenu->setHidden(VFX_FALSE);
	}
	else
	{
		VFX_OBJ_CREATE(m_widgetMenu, VappKeyLauncherWidgetMenu, this);
		m_widgetMenu->setHidden(VFX_FALSE); // for receive Key event
		m_widgetMenu->setRect(0, 0, /*m_statusIconBar->getSize().height, */
			LCD_WIDTH, 
			LCD_HEIGHT);// - m_statusIconBar->getSize().height);// - VAPP_KMM_SOFTKEY_BAR_HEIGHT);//VappKeyLauncherToolbar's height
		
		m_widgetMenu->m_signalFly.connect(this, &VappKeyLauncherDirector::onWidgetMenuFly);
	}
	
	m_widgetMenu->show();

	if (m_needWidgetMenuFlyIn) // Only fly in when switch from Idle->Widget, or from Main Menu -> Widget; by RSK
	{
		m_widgetMenu->fly(VappKeyLauncherWidgetMenu::FLY_IN);
	}
}


void VappKeyLauncherDirector::releaseWidgetMenu(VfxBool need_close)
{
	if(!m_widgetMenu)
	{
		return;
	}
	
	if (need_close)
	{
		VFX_OBJ_CLOSE(m_widgetMenu);
	}
	else
	{		
		m_widgetMenu->fly(VappKeyLauncherWidgetMenu::FLY_OUT);
	}

	// When leave Widget menu page, should resume wallpaper
	//m_wallpaper->resume();
}


void VappKeyLauncherDirector::onWidgetMenuFly(
		VappKeyLauncherWidgetMenu::FlyType ft,
		VappKeyLauncherWidgetMenu::FlyState fs)
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_ON_WIDGET_MENU_FLY, ft, fs));
	
	if (fs == VappKeyLauncherWidgetMenu::FLY_START)
	{
		delayWallpaper(WALLPAPER_FLY_DELAY_TIME); // delay time is larger than animation time
	}
	else if (ft == VappKeyLauncherWidgetMenu::FLY_IN &&
		fs == VappKeyLauncherWidgetMenu::FLY_FINISH)
	{
		delayWallpaper(0); // Start 0 timer to resume wallpaper
	}
	else if (ft == VappKeyLauncherWidgetMenu::FLY_OUT &&
		fs == VappKeyLauncherWidgetMenu::FLY_FINISH)
	{
		delayWallpaper(1000); // Start more timer to resume wallpaper, because will draw another page
		
		// After exit effect finish, should hidden widget menu frame and create next page
		m_widgetMenu->setHidden(VFX_TRUE);
	
		createObjofPage(m_switchToPage);
		s_currentPage = m_switchToPage;
		m_switchToPage = NULL_PAGE; // Indicate finish aync switching page, in case quick press key/pen to switch page
	}
}


void VappKeyLauncherDirector::createMainMenu()
{
	if (m_mainmenu)
	{
		m_mainmenu->setHidden(VFX_FALSE);
	}
	else
	{
		VFX_OBJ_CREATE(m_mainmenu, VappKeyMainmenu, this);
		m_mainmenu->setHidden(VFX_FALSE); // for receive Key event
		m_mainmenu->m_backFromMainmenu.connect(this, &VappKeyLauncherDirector::onMainMenuBack);
	
	}

	delayWallpaper(1000);

	// Only fly in when switch from Idle->Main Menu, or from  -> Widget->Main Menu; by RSK
	m_mainmenu->show(m_needMainMenuFlyIn);
}


void VappKeyLauncherDirector::releaseMainMenu(VfxBool need_close)
{
	if(!m_mainmenu)
	{
		return;
	}
	
	if (need_close)
	{
		VFX_OBJ_CLOSE(m_mainmenu);
	}
	else
	{		
		m_mainmenu->setHidden(VFX_TRUE);
	}
}


void VappKeyLauncherDirector::onMainMenuBack()
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_ON_MAIN_MENU_FLY, 
						m_mainmenu->getHidden(), s_perviousPage));
	
	switchPage(s_perviousPage, MAINMENU_PAGE, VFX_TRUE);
}


void VappKeyLauncherDirector::createWallpaper(VfxMsec delayTime)
{
    VFX_ASSERT(!m_wallpaper && !m_timerResumeWallpaper);

    //
    // Create the wallpaper resume time.
    //
    VFX_OBJ_CREATE(m_timerResumeWallpaper, VfxTimer, this);
	
	m_timerResumeWallpaper->m_signalTick.connect(this, &VappKeyLauncherDirector::onResumeWallpaper);

	VFX_OBJ_CREATE(m_container, VfxFrame, this);
	m_container->setPos(0,0);
	m_container->setSize(LCD_WIDTH, LCD_HEIGHT);
	m_container->setCacheMode(VFX_CACHE_MODE_PREVENT);

    //
    // Create the wallpaper.
    //
    m_wallpaper = VappWallpaperKit::createWallpaper(m_container, VAPP_WALLPAPER_SRC_HOMESCREEN, VAPP_KEYLAUNCHER_MAX_PAGE_NUM);
    VFX_ASSERT(m_wallpaper);

    //
    // For performance, suspend it first. Resume the wallpaper according to the
    // 'delayTime'.
    //
    delayWallpaper(delayTime);
}


void VappKeyLauncherDirector::releaseWallpaper()
{
    // Release objects.
    VFX_OBJ_CLOSE(m_wallpaper);
    VFX_OBJ_CLOSE(m_timerResumeWallpaper);
}

void VappKeyLauncherDirector::delayWallpaper(VfxMsec delayTime)
{
    // If wallpaper or timer is not present, this function does nothing.
    if (!m_wallpaper || !m_timerResumeWallpaper)
    {
        return;
    }

    // If timer isn't ongoing, we need frist supend wallpaper.
    // Becuase suspend and resume are paired
    if (!m_timerResumeWallpaper->getIsEnabled())
    {
        m_wallpaper->suspend();
    }

    m_timerResumeWallpaper->setStartDelay(delayTime);
    m_timerResumeWallpaper->start();
}


void VappKeyLauncherDirector::onResumeWallpaper(VfxTimer *timer)
{
    if (m_wallpaper)
    {
        m_wallpaper->resume();
    }
}


void VappKeyLauncherDirector::createToolbar()
{
    VFX_ASSERT(!m_toolbar);

    VFX_OBJ_CREATE(m_toolbar, VappKeyLauncherToolbar, this);
	m_toolbar->setAnchor(0.0f, 1.0f);
    m_toolbar->setPos(0, LCD_HEIGHT); // - m_statusIconBar->getSize().height);
    m_toolbar->m_signalExecute.connect(this, &VappKeyLauncherDirector::onToolbarExecute);
}


void VappKeyLauncherDirector::releaseToolbar()
{
    VFX_OBJ_CLOSE(m_toolbar);
}


void VappKeyLauncherDirector::onToolbarExecute(VfxObject *toolbar, VfxId buttonId, VcpSoftkeyEventEnum event)
{
    VFX_ASSERT(toolbar && toolbar == m_toolbar);
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_DIRECTOR_ON_TOOLBAR_EXCUTE, buttonId));
	
	if (event == VCP_SOFTKEY_DOWN)
	{
		delayWallpaper(2000); // Start more timer to resume wallpaper, because will draw another page
		return;
	}
	
    switch (buttonId)
    {
		case VappKeyLauncherToolbar::MAINMENU_IN_IDLE:
			switchPage(MAINMENU_PAGE, IDLE_PAGE, VFX_TRUE);
			break;

		case VappKeyLauncherToolbar::WIDGET_IN_IDLE:
			switchPage(WIDGET_PAGE, IDLE_PAGE, VFX_TRUE);
			break;

		case VappKeyLauncherToolbar::MAINMENU_IN_WIDGET:
			switchPage(MAINMENU_PAGE, WIDGET_PAGE, VFX_TRUE);
			break;

		case VappKeyLauncherToolbar::IDLE_IN_WIDGET:
			switchPage(IDLE_PAGE, WIDGET_PAGE);
			break;	

        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappKeyLauncherDirector::createStatusIconBar()
{
    VFX_ASSERT(!m_statusIconBar);

	/* status icon bar */
	VFX_OBJ_CREATE(m_statusIconBar, VcpStatusIconBar, this);
    m_statusIconBar->enableBackground(VFX_FALSE);
    m_statusIconBar->setHints(VFX_FRAME_HINTS_SW_OVERLAY);
}


void VappKeyLauncherDirector::releaseStatusIconBar()
{
    VFX_OBJ_CLOSE(m_statusIconBar);
}

#endif /* __MMI_VUI_LAUNCHER_KEY__ */

