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
 *  vapp_launcher_key_primitive.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the tool bar, ....
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
#include "vcp_include.h"
#include "vcp_sse.h"
#include "mmi_rp_vapp_launcher_key_def.h"
#include "vapp_launcher_key_def.h"
#include "vapp_launcher_key_primitive.h"
#include "vapp_launcher_key_director.h"

#include "vapp_launcher_key_mainmenu.h"
#include "vapp_launcher_key_mainmenu_builder.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "Wgui.h"
#include "mmi_frm_utility_gprot.h"
#include "GlobalResdef.h"
#include "PixcomFontEngine.h"
#include "gui_effect_oem.h"

#include "NwNameSrvGprot.h"
#include "AppMgrSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "PhoneSetupGprots.h"
#include "SatGprots.h"
#include "SatSrvGprot.h"
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "NetSetAppGprot.h"
#endif
#ifdef __MMI_SEARCH_WEB__
#include "SearchWebGProt.h"
#endif
#ifdef __cplusplus
}
#endif



/*****************************************************************************
 * Toolbar Class
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappKeyLauncherToolbar", VappKeyLauncherToolbar, VfxFrame);

VappKeyLauncherToolbar::VappKeyLauncherToolbar():
	m_style(STYLE_IDLE)
{
}


void VappKeyLauncherToolbar::onInit()
{
    VfxFrame::onInit();

	setSize(LCD_WIDTH, VAPP_KMM_SOFTKEY_BAR_HEIGHT);

	VFX_OBJ_CREATE(m_softkeybar, VcpSoftkey, this);
	m_softkeybar->setBounds(VfxRect(0, 0, LCD_WIDTH, VAPP_KMM_SOFTKEY_BAR_HEIGHT));
	m_softkeybar->getCallback(VCP_SOFTKEY_LSK).connect(this, &VappKeyLauncherToolbar::onEventLsk);
	m_softkeybar->getCallback(VCP_SOFTKEY_RSK).connect(this, &VappKeyLauncherToolbar::onEventRsk);
	m_softkeybar->setSoftkeyWidth(VCP_SOFTKEY_LSK, VAPP_KMM_SOFTKEY_WIDTH - (m_softkeybar->getBorderGap() + m_softkeybar->getShiftOffset()));
	m_softkeybar->setSoftkeyWidth(VCP_SOFTKEY_RSK, VAPP_KMM_SOFTKEY_WIDTH - m_softkeybar->getBorderGap());
#ifndef __MMI_MAINLCD_320X240__	
	m_softkeybar->setImgContent(VfxImageSrc(IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_BG));
	m_softkeybar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_softkeybar->setFont(VfxFontDesc(VAPP_LAUNCHER_KEY_MM_SOFTKEY_FONT_SIZE));
#else
	m_softkeybar->setSoftkeyBackground(VCP_SOFTKEY_LSK, VfxImageSrc(IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_BG));
	m_softkeybar->setSoftkeyBackground(VCP_SOFTKEY_RSK, VfxImageSrc(IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_BG));
	m_softkeybar->setSoftkeyBackgroundContentPlacement(VCP_SOFTKEY_LSK, VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_softkeybar->setSoftkeyBackgroundContentPlacement(VCP_SOFTKEY_RSK, VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#endif /* __MMI_MAINLCD_320X240__ */
	
	m_softkeybar->setBorderGap(VAPP_KMM_SOFTKEY_BAR_GAP);
}


void VappKeyLauncherToolbar::setHidden(VfxBool value)
{
	m_softkeybar->disableSoftkey(value);
	VfxFrame::setHidden(value);
}


void VappKeyLauncherToolbar::setStyle(ToolbarStyle style)
{
	m_style = style;
	
#ifndef __MMI_MAINLCD_320X240__	
	if (STYLE_IDLE == style)
	{
		m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_ID_VAPP_KEYLAUNCHER_MAINMENU), VFX_IMAGE_SRC_NULL);
		m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(STR_ID_VAPP_KEYLAUNCHER_WIDGETS), VFX_IMAGE_SRC_NULL);
	}
	else if (STYLE_WIDGETS == style)
	{
		m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(STR_ID_VAPP_KEYLAUNCHER_MAINMENU), VFX_IMAGE_SRC_NULL);
		m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_RES(STR_ID_VAPP_KEYLAUNCHER_IDLE), VFX_IMAGE_SRC_NULL);
	}
#else
	
if (STYLE_IDLE == style)
{
	m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_MENU));
	m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_WIDGET));
}
else if (STYLE_WIDGETS == style)
{
	m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_MENU));
	m_softkeybar->setSoftkey(VCP_SOFTKEY_RSK, VFX_WSTR_NULL, VfxImageSrc(IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_IDLE));
}
#endif /* __MMI_MAINLCD_320X240__  */
}


void VappKeyLauncherToolbar::onEventLsk(VcpSoftkeyEventEnum event_type)
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_TOOLBAR_ON_EVENT,
							'L', event_type, m_style));
	
		VfxId id;
		if (m_style == STYLE_IDLE)
			id = MAINMENU_IN_IDLE;
		else
			id = MAINMENU_IN_WIDGET;

	if (event_type == VCP_SOFTKEY_UP)
    {
		vfxPostInvoke2(this, &VappKeyLauncherToolbar::onPostExecute, id, VCP_SOFTKEY_UP);
	}
	else if (event_type == VCP_SOFTKEY_DOWN)
	{
		vfxPostInvoke2(this, &VappKeyLauncherToolbar::onPostExecute, id, VCP_SOFTKEY_DOWN);
	}
}


void VappKeyLauncherToolbar::onEventRsk(VcpSoftkeyEventEnum event_type)
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_TOOLBAR_ON_EVENT,
							'R', event_type, m_style));
	
		VfxId id;
		if (m_style == STYLE_IDLE)
			id = WIDGET_IN_IDLE;
		else
			id = IDLE_IN_WIDGET;

    if (event_type == VCP_SOFTKEY_UP)
    {
		vfxPostInvoke2(this, &VappKeyLauncherToolbar::onPostExecute, id, VCP_SOFTKEY_UP);
    }
	else if (event_type == VCP_SOFTKEY_DOWN)
	{
		vfxPostInvoke2(this, &VappKeyLauncherToolbar::onPostExecute, id, VCP_SOFTKEY_DOWN);
    }
}


void VappKeyLauncherToolbar::onPostExecute(VfxId id, VcpSoftkeyEventEnum event)
{
    m_signalExecute.emit(this, id, event);
}


/*****************************************************************************
 * Idle page, Which is one page of Home
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappKeyLauncherIdlePage", VappKeyLauncherIdlePage, VfxControl);

VappKeyLauncherIdlePage::VappKeyLauncherIdlePage()
{
}


void VappKeyLauncherIdlePage::onInit()
{
    VfxControl::onInit();

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__)
	// Start to create and draw datetime frame
	VappLauncherKeyClock *m_date;
	VFX_OBJ_CREATE_EX(m_date, VappLauncherKeyClock, this, (VfxPoint(0, 0)));
#endif

#if !defined(__MMI_NCENTER_SUPPORT__) || defined(__MMI_KEY_ONLY_NCENTER__)
	// Start to create and draw operator name if not support NCenter
	VappKeyLauncherOperatorFrame *m_opName;
	VFX_OBJ_CREATE(m_opName, VappKeyLauncherOperatorFrame, this);
	m_opName->setPos(VAPP_KEYLAUNCHER_OP_FRAME_X, VAPP_KEYLAUNCHER_OP_FRAME_Y);
#endif
#ifndef __MMI_NCENTER_SUPPORT__
	// Start to create and draw idle text mode (SAT)
	VappKeyLauncherIdleModeText *m_idleMode;
	VFX_OBJ_CREATE(m_idleMode,	VappKeyLauncherIdleModeText, this);
	m_idleMode->setRect(VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_X, 
						VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_Y, 
						VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH, 
						VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT);
#endif /* __MMI_NCENTER_SUPPORT__ */

#ifdef __MMI_SEARCH_WEB__
	// Start to create and draw baidu or google search bar
	if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT))
	{
		VappKeyLauncherSearchBar *searchBar;
		VFX_OBJ_CREATE(searchBar, VappKeyLauncherSearchBar, this);
		if(mmi_phnset_shortcut_manager_get_shortcut_number() > 0)
			searchBar->setPos(VAPP_KEYLAUNCHER_SEARCH_BAR_X, VAPP_KEYLAUNCHER_SEARCH_BAR_Y_A);
		else
			searchBar->setPos(VAPP_KEYLAUNCHER_SEARCH_BAR_X, VAPP_KEYLAUNCHER_SEARCH_BAR_Y_B);
	}
#endif /* __MMI_SEARCH_WEB__ */

	// Start to create and draw shortcut
	createShortcutView();
}


void VappKeyLauncherIdlePage::setHidden(VfxBool value)
{
	VfxControl::setHidden(value);

	setFocused(value != VFX_TRUE); // for receive Key event
	m_shortcut->setHidden(value);
	m_shortcut->setFocused(value != VFX_TRUE); // for receive Key event
}


void VappKeyLauncherIdlePage::createShortcutView()
{
	VFX_OBJ_CREATE(m_shortcut, VappKeyLauncherShortcut, this);
	m_shortcut->setPos(0, VAPP_KEYLAUNCHER_SHORTCUT_Y);
	m_shortcut->createView();
}


/***************************************************************************** 
 * Class VappKeyLauncherShortcut 
 *****************************************************************************/

VfxU32 VappKeyLauncherShortcut::m_shortcutHighlightIdx = 0;

VappKeyLauncherShortcut::VappKeyLauncherShortcut() :
	m_shortcutCount(0)
{
	for (VfxS32 i = 0 ; i < SHORTCUT_MAX_COUNT ; i++)
    {
        //m_shortcutPackage[i] = NULL;
        memset(m_shortcutPackage[i], 0x00, MMI_APP_NAME_MAX_LEN * sizeof(mmi_app_package_char));
		m_shortcutCell[i] = NULL;
    }
}


VfxBool VappKeyLauncherShortcut::onKeyInput(VfxKeyEvent &event)
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_SHORTCUT_ON_KEY_INPUT,
							event.keyCode, event.type));
	
	if (m_shortcutCount == 0)
	{
		return VfxControl::onKeyInput(event);; // Current no shortcut App
	}
	
	VfxS32 inc = 0;
	if (event.keyCode == VFX_KEY_CODE_ARROW_RIGHT &&
        (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
         event.type == VFX_KEY_EVENT_TYPE_REPEAT))
	{
		inc = 1; // switch highlight to next shortcut
	}
	else if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT &&
             (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
              event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
		inc = -1; // switch highlight to pervious shortcut
	}
	else if ((event.keyCode == VFX_KEY_CODE_ARROW_RIGHT ||
			  event.keyCode == VFX_KEY_CODE_ARROW_LEFT) &&
             event.type == VFX_KEY_EVENT_TYPE_UP)
	{
		// Mean to Don't rount key to parent
		return VFX_TRUE;
	}
	else if (event.keyCode == VFX_KEY_CODE_CSK &&
             event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		((VappKeyLauncherDirector *)(getParent()->getParent()))->delayWallpaper(10000); // fine tune performance
		return VFX_TRUE;
	}
	else if (event.keyCode == VFX_KEY_CODE_CSK &&
             event.type == VFX_KEY_EVENT_TYPE_UP)
	{
		// Launch highlighted shortcut
		//vfxPostInvoke(this, &VappKeyLauncherShortcut::launchShortcut);
		launchShortcut(NULL);
		return VFX_TRUE;
	}

	if (inc != 0)
	{
		switchShortcutHighlight(inc);
		return VFX_TRUE;
	}
	return VfxControl::onKeyInput(event);
}


VfxBool VappKeyLauncherShortcut::onPenInput(VfxPenEvent &event)
{
	if (m_shortcutCount == 0)
	{
		return VfxControl::onPenInput(event);; // Current no shortcut App
	}

	if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
	{
		for (VfxU32 i = 0 ; i < m_shortcutCount ; i++)
		{
			if (m_shortcutCell[i]->containPoint(event.getRelPos(m_shortcutCell[i])) == VFX_TRUE)
			{
				((VappKeyLauncherDirector *)(getParent()->getParent()))->delayWallpaper(10000); // fine tune performance
				
				if (m_shortcutHighlightIdx != i)
					switchShortcutHighlight(m_shortcutCount + i - m_shortcutHighlightIdx);

				return VFX_TRUE;
			}
		}
	}
	else if (event.type == VFX_PEN_EVENT_TYPE_UP)
	{
		if (m_shortcutCell[m_shortcutHighlightIdx]->containPoint(event.getRelPos(m_shortcutCell[m_shortcutHighlightIdx])) == VFX_TRUE)
			{
			//vfxPostInvoke(this, &VappKeyLauncherShortcut::launchShortcut);
			launchShortcut(NULL);

				return VFX_TRUE;
			}
		((VappKeyLauncherDirector *)(getParent()->getParent()))->delayWallpaper(0); // fine tune performance
	}
	return VfxControl::onPenInput(event);
}
	

void VappKeyLauncherShortcut::createView()
{
	// Get Shortcut max count from Setting app
	m_shortcutCount = mmi_phnset_shortcut_manager_get_shortcut_number();
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_SHORTCUT_CREATE, m_shortcutCount));
	VFX_ASSERT(m_shortcutCount <= SHORTCUT_MAX_COUNT);

	if (m_shortcutCount == 0)
	{
		return; // Current no shortcut App
	}
	if (m_shortcutHighlightIdx >= m_shortcutCount)
	{
		m_shortcutHighlightIdx = m_shortcutCount - 1; // Indicate User reduce shortcut count from Setting.
	}

	// Init shortcut package from Setting app
	mmi_phnset_shortcut_manager_get_shortcut_list(m_shortcutPackage);

	for (VfxU32 i = 0 ; i < m_shortcutCount ; i++)
	{
	    m_shortcutCell[i] = createKmmCell(m_shortcutPackage[i], this, isShortcutPreInstalled(i));
		m_shortcutCell[i]->setPos(
			i * (m_shortcutCell[i]->getSize().width) + VAPP_KMM_MENU_MARGERN_X,
			0);
		m_shortcutCell[i]->setIsBorderColor(VFX_TRUE);
		m_shortcutCell[i]->registerBadgeEvent();
	    m_shortcutCell[i]->onCellDisplay();
	}

	// Set shortcut frame size in idle page
	setSize(LCD_WIDTH, m_shortcutCell[0]->getSize().height);

	// Hightlight origal shortcut, if has
	switchShortcutHighlight(0);
}


VfxBool VappKeyLauncherShortcut::isShortcutPreInstalled(VfxU32 index)
{
    VfxS32 num = srv_appmgr_get_app_package_num(
                    SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    if (num == 0)
    {
        return VFX_FALSE;
    }

    //
    // Get all pre-installed APP package name.
    //
    mmi_app_package_name_struct *package;

    VFX_ALLOC_MEM(package, num * sizeof(mmi_app_package_name_struct), this);

    mmi_ret ret = srv_appmgr_get_app_package_list(
                    SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE,
                    package,
                    num);
    VFX_ASSERT(ret != MMI_RET_ERR);

    //
    // Check if this APP belongs to pre-installed APP.
    //
    VfxBool isFound = VFX_FALSE;

    for (VfxS32 i = 0; i < num; i++)
    {
        if (strcmp(m_shortcutPackage[index], package[i]) == 0)
        {
            isFound = VFX_TRUE;
            break;
        }
    }

    VFX_FREE_MEM(package);

    return isFound;
}


void VappKeyLauncherShortcut::switchShortcutHighlight(VfxS32 inc)
{
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_SHORTCUT_SWITCH_HIGHLIGHT, 
							m_shortcutHighlightIdx, inc));
	
	if (m_shortcutCount == 0)
	{
		return; // Current no shortcut App
	}
	
	if (inc == 0)
	{
		m_shortcutCell[m_shortcutHighlightIdx]->setIsHighlighted(VFX_TRUE, VFX_TRUE);
	}
	else // switch highlight to next or pervios
	{
		m_shortcutCell[m_shortcutHighlightIdx]->setIsHighlighted(VFX_FALSE, VFX_TRUE);
		m_shortcutHighlightIdx += inc;
		m_shortcutHighlightIdx = (m_shortcutHighlightIdx + m_shortcutCount) % m_shortcutCount;
		m_shortcutCell[m_shortcutHighlightIdx]->setIsHighlighted(VFX_TRUE, VFX_TRUE);
	}
}


void VappKeyLauncherShortcut::launchShortcut(void *userData)
{
	VFX_UNUSED(userData);
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_SHORTCUT_LAUNCH));

	gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_MAINMENU);
#if defined(__PLUTO_3D_V10__) && defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)
	vcpSseSetupScenarioByApp(m_shortcutPackage[m_shortcutHighlightIdx]);
#endif
	srv_appmgr_launch(m_shortcutPackage[m_shortcutHighlightIdx]);
}
	

/***************************************************************************** 
 * Class VappKeyLauncherOperatorElement 
 *****************************************************************************/
VappKeyLauncherOperatorElement::VappKeyLauncherOperatorElement(VfxS32 simId):
    m_simId(simId),
	m_imgSim(NULL),
	m_textOPN(NULL),
	m_textSPN(NULL),
	m_rightParenthesis(NULL),
	m_textPosX(VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_X)
{
}

void VappKeyLauncherOperatorElement::onInit()
{
    VfxFrame::onInit();

    setSize(VAPP_KEYLAUNCHER_OP_FRAME_WIDTH, VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT);

	if (srv_sim_ctrl_get_num_of_inserted() > 1) // two or more SIM inserted
	{
		VFX_OBJ_CREATE(m_imgSim, VfxImageFrame, this);
		if (mmi_fe_is_r2l_state() == MMI_TRUE) // some lauauge support r2l, such as arabic
		{
			m_imgSim->setAnchor(1.0, 0.5);
			m_imgSim->setPos(VAPP_KEYLAUNCHER_OP_FRAME_WIDTH - VAPP_KEYLAUNCHER_OP_FRAME_ICON_X, 
							VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT/2);
		}
		else
		{
		m_imgSim->setAnchor(0, 0.5);
		m_imgSim->setPos(VAPP_KEYLAUNCHER_OP_FRAME_ICON_X, VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT/2);
		}
		//m_imgSim->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);

		MMI_IMG_ID simImgRes[] = {IMG_GLOBAL_SIM1, IMG_GLOBAL_SIM2, IMG_GLOBAL_SIM3, IMG_GLOBAL_SIM4};
    	m_imgSim->setResId(simImgRes[m_simId]);

		m_textPosX = m_imgSim->getSize().width + 2;
	}
#ifdef __MMI_MAINLCD_320X240__
	else // only has one or no sim inserted
	{
		setSize(LCD_WIDTH - 2 * VAPP_KEYLAUNCHER_OP_FRAME_X, VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT);
	}
#endif
	
    VfxFontDesc fontDesc;
	fontDesc.effect = VFX_FONT_DESC_EFFECT_BORDER;

    VFX_OBJ_CREATE(m_textOPN, VfxTextFrame, this);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE);
    m_textOPN->setFont(fontDesc);

    VFX_OBJ_CREATE(m_textSPN, VfxTextFrame, this);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_SIZE);
    m_textSPN->setFont(fontDesc);
    
    VFX_OBJ_CREATE(m_rightParenthesis, VfxTextFrame, this);
	if (mmi_fe_is_r2l_state() == MMI_TRUE) // some lauauge support r2l, such as arabic
	{
    	m_rightParenthesis->setString(VFX_WSTR_EMPTY); // OpName - Sim name
	}
	else
	{
    	m_rightParenthesis->setString(VFX_WSTR(")"));  // OpName (Sim name)
	}	
	fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE);
    m_rightParenthesis->setFont(fontDesc);
	m_rightParenthesis->setHidden(VFX_TRUE);
}


void VappKeyLauncherOperatorElement::updateOperatorName(VfxS32 maxWidth)
{
    srv_nw_name_service_indication_struct tmp_indication;

    srv_nw_name_get_service_indication_string(mmi_frm_index_to_sim(m_simId), &tmp_indication);  
    m_textOPN->setString(VFX_WSTR_MEM(tmp_indication.line1));
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    m_textSPN->setString(VFX_WSTR_MEM(tmp_indication.line2));

	VfxS32 yPos;
    if(tmp_indication.line2[0] != 0)
    {
    	if (mmi_fe_is_r2l_state() == MMI_TRUE) // some lauauge support r2l, such as arabic
		{
			m_textOPN->setAnchor(1.0, 0);
			m_textSPN->setAnchor(1.0, 0);

			m_textOPN->setPos(getSize().width - m_textPosX , VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y);
			m_textSPN->setPos(getSize().width - m_textPosX , VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_Y);
    	}
		else
    {
        m_textOPN->setAnchor(0, 0);
		m_rightParenthesis->setAnchor(0, 0);
		
        m_textOPN->setPos(m_textPosX , VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y);
        m_textSPN->setPos(m_textPosX , VAPP_KEYLAUNCHER_OP_FRAME_SUB_TEXT_Y);
		}
		
        m_textSPN->setHidden(VFX_FALSE);
		yPos = VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_Y;
    }
    else
    {
    	if (mmi_fe_is_r2l_state() == MMI_TRUE) // some lauauge support r2l, such as arabic
		{
			m_textOPN->setAnchor(1.0, 0.5);			
			m_textOPN->setPos(getSize().width - m_textPosX , VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT/2);
    }
    else
    {
        m_textOPN->setAnchor(0, 0.5);
		m_rightParenthesis->setAnchor(0, 0.5);
		
        m_textOPN->setPos(m_textPosX , VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT/2);
		}
		yPos = VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT/2;
        m_textSPN->setHidden(VFX_TRUE);
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	VfxWChar *buffer;
	VfxWString simName;
	buffer = mmi_netset_get_sim_name(mmi_frm_index_to_sim(m_simId));

    if (buffer == NULL || buffer[0] == 0)
		simName = VFX_WSTR_EMPTY;
	else
	    simName = VFX_WSTR_MEM(buffer);
#else
    VfxWString simName = VFX_WSTR_EMPTY;
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	if(simName.isEmpty())
    {
		m_rightParenthesis->setHidden(VFX_TRUE);
    }
	else
	{
	    m_rightParenthesis->setHidden(VFX_FALSE);

		VfxWString temp;
		temp = VFX_WSTR_MEM(tmp_indication.line1);
		if (mmi_fe_is_r2l_state() == MMI_TRUE) // some lauauge support r2l, such as arabic
		{
			temp += VFX_WSTR(" - ");
		}
		else
		{
		temp += VFX_WSTR(" (");
		}
		temp += VFX_WSTR_MEM(simName);
		m_textOPN->setString(temp);
	}

	VfxS32 maxWidthSimName = getSize().width - m_textPosX - m_rightParenthesis->getSize().width;
		if (maxWidthSimName > m_textOPN->getSize().width)
		{
			m_textOPN->setAutoResized(VFX_TRUE);
			m_textOPN->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
			maxWidthSimName = m_textOPN->getSize().width;
		}
		else
		{
		//m_textOPN->setAutoResized(VFX_FALSE);
			m_textOPN->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		}
		m_textOPN->setSize(maxWidthSimName, m_textOPN->getSize().height);
		m_textOPN->setVerticalToCenter(VFX_TRUE);
	m_textSPN->setSize(getSize().width - m_textPosX, m_textSPN->getSize().height);
		
	    m_rightParenthesis->setPos(m_textOPN->getPos().x + m_textOPN->getSize().width, yPos);

	if (mmi_fe_is_r2l_state() == MMI_TRUE) // some lauauge support r2l, such as arabic
	{
		m_textOPN->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
		m_textSPN->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
	}

}


/***************************************************************************** 
 * Class VappKeyLauncherOperatorFrame 
 *****************************************************************************/
VappKeyLauncherOperatorFrame::VappKeyLauncherOperatorFrame():
	m_text(NULL)
{
	for(VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        m_operElement[i] = NULL;
    }
}

void VappKeyLauncherOperatorFrame::onInit()
{
    VfxFrame::onInit();

    setSize(LCD_WIDTH - 2 * VAPP_KEYLAUNCHER_OP_FRAME_X, MMI_SIM_TOTAL * VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT);

	VFX_OBJ_CREATE(m_text, VfxTextFrame, this);	
	VfxFontDesc fontDesc;
	fontDesc.effect = VFX_FONT_DESC_EFFECT_BORDER;
	fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_SIZE);
	m_text->setFont(fontDesc);
	if (mmi_fe_is_r2l_state() == MMI_TRUE) // some lauauge support r2l, such as arabic
	{
		m_text->setAnchor(1.0, 0.5);
		m_text->setPos(getSize().width - VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_X , VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT/2);
	}
	else
	{
	m_text->setAnchor(0, 0.5);
	m_text->setPos(VAPP_KEYLAUNCHER_OP_FRAME_MAIN_TEXT_X , VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT/2);
	}
	m_text->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);

    initOperatorNameCell();
    update(getSize().width);

    mmi_frm_cb_reg_event(EVT_ID_SRV_NW_NAME_CHANGED, &VappKeyLauncherOperatorFrame::eventHandler, this);
}


void VappKeyLauncherOperatorFrame::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_NW_NAME_CHANGED, &VappKeyLauncherOperatorFrame::eventHandler, this);
    VfxFrame::onDeinit();
}


mmi_ret VappKeyLauncherOperatorFrame::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappKeyLauncherOperatorFrame* operatorFrame = (VappKeyLauncherOperatorFrame *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_NW_NAME_CHANGED:
			VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_OP_EVENT_HDLR));
            operatorFrame->update(operatorFrame->getSize().width);
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void VappKeyLauncherOperatorFrame::initOperatorNameCell()
{
    VfxS32 i;
    for(i = 0; i < MMI_SIM_TOTAL; i++)
    {
        VFX_OBJ_CREATE_EX(m_operElement[i], VappKeyLauncherOperatorElement, this, (i));
    }
}


void VappKeyLauncherOperatorFrame::update(VfxS32 maxWidth)
{
    VfxS32 i;
    VfxS32 numSIMInsert = 0;
    for(i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if(!srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
        {
            m_operElement[i]->setHidden(VFX_TRUE);
            continue;
        }
	#ifdef __MMI_MAINLCD_320X240__	
        m_operElement[i]->setPos(0 + (numSIMInsert%2) * (LCD_WIDTH/2), (numSIMInsert/2)*VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT);
	#else
		m_operElement[i]->setPos(0, numSIMInsert*VAPP_KEYLAUNCHER_OP_FRAME_HEIGHT);
	#endif
        m_operElement[i]->setHidden(VFX_FALSE);
        numSIMInsert++;
    }
	
	VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_OP_UPDATE, numSIMInsert));

	m_text->setHidden(VFX_FALSE);
    
	//if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
	if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
	{
		m_text->setString(VFX_WSTR_RES(STR_ID_VAPP_KEYLAUNCHER_FLIGHT_MODE));
		for(i = 0; i < MMI_SIM_TOTAL; i++)
	    {
			m_operElement[i]->setHidden(VFX_TRUE);
	    }
	}
	else if(numSIMInsert == 0)
    {
        // No SIM inserted
		m_text->setString(VFX_WSTR_RES(STR_ID_VAPP_KEYLAUNCHER_ECC));
    }
	else if(numSIMInsert >= 1)
    {
		m_text->setHidden(VFX_TRUE);
		
        // Has SiM inserted, and not in Flight mode
        for(i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if(!srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
            {
                continue;
            }
            m_operElement[i]->updateOperatorName(maxWidth);
        }
    }
}


/********************************************************************************************* 
 * Class VappKeyLauncherIdleModeText: idle mode text class used for display SAT icon
 ********************************************************************************************/
VappKeyLauncherIdleModeText::VappKeyLauncherIdleModeText() :
    m_idleModeText(NULL),
    m_idleModeIcon(NULL),
    m_idleModeStr(VFX_WSTR_NULL)
{
}

void VappKeyLauncherIdleModeText::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_idleModeIcon, VfxImageFrame, this);
	m_idleModeIcon->setAnchor(0.0f, 0.5f);
    m_idleModeIcon->setPos(VAPP_KEYLAUNCHER_IDLE_MODE_ICON_X, VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT >> 1);
    m_idleModeIcon->setSize(VAPP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH, VAPP_KEYLAUNCHER_IDLE_MODE_ICON_HEIGHT);
    m_idleModeIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	
    VFX_OBJ_CREATE(m_idleModeText, VcpMarquee, this);
    m_idleModeText->setAnchor(0.0f, 0.5f);
    m_idleModeText->setPos(VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_X, VAPP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT >> 1);
    m_idleModeText->setSize(VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_WIDTH, VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_HEIGHT);
    m_idleModeText->setHalign(VcpMarquee::HALIGN_CENTER);
    m_idleModeText->setSpeed(VAPP_KEYLAUNCHER_IDLE_MODE_MARQUEE_SPEED);

	updateSAT();

	mmi_frm_cb_reg_event(EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY, &VappKeyLauncherIdleModeText::eventHandler, this);
}

void VappKeyLauncherIdleModeText::onDeinit()
{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY, &VappKeyLauncherIdleModeText::eventHandler, this);
	VfxFrame::onDeinit();
}

void VappKeyLauncherIdleModeText::setIdleModeText(const VfxWString &str)
{
    if (m_idleModeStr == str)
    {
        return;
    }
    
    if (str.isNull())
    {
        m_idleModeText->clearMovableFrame(); // stop scroll internally
    }
    else
    {
		VfxFontDesc fontDesc;
		fontDesc.effect = VFX_FONT_DESC_EFFECT_BORDER;
		fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_KEYLAUNCHER_IDLE_MODE_TEXT_SIZE);
		
        m_idleModeText->setMovableFrame(str, fontDesc);
        m_idleModeText->startScroll();
    }

    m_idleModeStr = str;
}

void VappKeyLauncherIdleModeText::setIdleModeIcon(const VfxU8 *iconPtr)
{
    if (iconPtr == NULL)
    {
        m_idleModeIcon->setHidden(VFX_TRUE);
    }
    else
    {
        m_idleModeIcon->setHidden(VFX_FALSE);
        m_idleModeIcon->setImgContent(VfxImageSrc(iconPtr));
    }
}


mmi_ret VappKeyLauncherIdleModeText::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappKeyLauncherIdleModeText* operatorFrame = (VappKeyLauncherIdleModeText *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY:
			VAPP_KEYLAUNCHER_LOG((TRC_VAPP_LAUNCHER_KEY_HS_OP_EVENT_HDLR));
            operatorFrame->updateSAT();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void VappKeyLauncherIdleModeText::updateSAT()
{
	const VfxWChar* text = (VfxWChar*)GetSATIdleText();
	setIdleModeText(VFX_WSTR_MEM(text));

	const VfxU8 * icon = (VfxU8 *)GetSATIdleIcon();
	setIdleModeIcon(icon);
}


/*****************************************************************************
 * VappKeyLauncherSearchBar
 *****************************************************************************/
#ifdef __MMI_SEARCH_WEB__
 
VFX_IMPLEMENT_CLASS("VappKeyLauncherSearchBar", VappKeyLauncherSearchBar, VfxControl);

VappKeyLauncherSearchBar::VappKeyLauncherSearchBar()
{
}


void VappKeyLauncherSearchBar::onInit()
{
    VfxControl::onInit();
	
	setSize(VAPP_KEYLAUNCHER_SEARCH_BAR_WIDTH, VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT);

	// Start to create and draw search bg frame
	setImgContent(VfxImageSrc(IMG_ID_VAPP_KEYLAUNCHER_SEARCH_BAR_BG));
	setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

	const VfxU8 *image;
    const VfxWChar *string;
	if(mmi_search_web_get_idle_hint(&image, &string))
	{
		VfxImageFrame *icon;
		VFX_OBJ_CREATE(icon,  VfxImageFrame, this);
		icon->setMem(image);

		VfxTextFrame *text;
		VFX_OBJ_CREATE(text,  VfxTextFrame, this);
		text->setString(VFX_WSTR_MEM(string));
		VfxFontDesc fontDesc;
	    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_SIZE);
    	text->setFont(fontDesc);
		text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		text->setSize(VAPP_KEYLAUNCHER_SEARCH_BAR_WIDTH - VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_X - 5, 
						text->getSize().height);		

		if (mmi_fe_is_r2l_state() == MMI_TRUE) // some lauauge support r2l, such as arabic
		{
			icon->setAnchor(1.0, 0);
			icon->setPos(VAPP_KEYLAUNCHER_SEARCH_BAR_WIDTH - VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_X, 
						VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_Y);
			
			text->setAnchor(1.0, 0.5);
			text->setPos(VAPP_KEYLAUNCHER_SEARCH_BAR_WIDTH - VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_X, 
						VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT / 2);			
			text->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
		}
		else
		{
			icon->setAnchor(0, 0);
			icon->setPos(VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_X, VAPP_KEYLAUNCHER_SEARCH_BAR_ICON_Y);
			
			text->setAnchor(0, 0.5);
			text->setPos(VAPP_KEYLAUNCHER_SEARCH_BAR_STRING_X, VAPP_KEYLAUNCHER_SEARCH_BAR_HEIGHT / 2);
		}
	}
}


VfxBool VappKeyLauncherSearchBar::onPenInput(VfxPenEvent &event)
{
	if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
	{
		return VFX_TRUE;
	}
	else if (event.type == VFX_PEN_EVENT_TYPE_UP)
	{
		if (containPoint(event.getRelPos(this)) == VFX_TRUE)
			mmi_search_web_trigger_by_hot_key(MMI_SEARCH_WEB_HOT_KEY_TOUCH_HINT);
		return VFX_TRUE;
	}
	return VfxControl::onPenInput(event);
}


#endif /* __MMI_SEARCH_WEB__ */


#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */

