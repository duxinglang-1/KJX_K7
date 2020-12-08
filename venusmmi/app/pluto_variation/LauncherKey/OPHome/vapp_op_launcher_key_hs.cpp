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
 *  vapp_op_launcher_key_hs.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements shortcut bar
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_launcher_key_def.h"
#include "vapp_op_launcher_key_hs.h"
#include "vapp_launcher_key_mainmenu_builder.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "AppMgrSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "NwNameSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "SatGprots.h"
#include "SatSrvGprot.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_common_app_trc.h"
#include "GlobalResdef.h"
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#include "NetSetAppGprot.h"
#endif

#include "mmi_rp_vapp_op_launcher_key_hs_def.h"

extern srv_dtcnt_result_enum mmi_wlan_cmcc_entry_deinit(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data);

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * Operator idle page
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappOpKeyLauncherIdlePage", VappOpKeyLauncherIdlePage, VfxControl);
VappOpKeyLauncherIdlePage::VappOp01FocuseStateEnum VappOpKeyLauncherIdlePage::s_focuseState = VappOpKeyLauncherIdlePage::FOCUSE_STATE_SHORTCUT;

VappOpKeyLauncherIdlePage::VappOpKeyLauncherIdlePage() :
	m_dateTime(NULL),
	m_opName(NULL),
	m_idleMode(NULL),
#ifdef __MMI_OP01_WIFI__
	m_wlanButton(NULL),
#endif
	m_shortcutBar(NULL)
{
    if (!srv_mode_switch_is_network_service_available())
    {
        s_focuseState = FOCUSE_STATE_SHORTCUT;
    }
}


void VappOpKeyLauncherIdlePage::onInit()
{
    VfxControl::onInit();

	// Create datetime
	VFX_OBJ_CREATE_EX(m_dateTime, VappLauncherKeyClock, this, (VfxPoint(0, 0)));

	// Create operator name
	createOperatorName();

    VFX_OBJ_CREATE(m_idleMode,	VappOpKeyLauncherIdleModeText, this);
    m_idleMode->setRect(VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_X,
						VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_Y,
						VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_WIDTH,
						VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT);

	// Create shortcut bar
	createShortcutBar();

    // Create WLAN button
#ifdef __MMI_OP01_WIFI__
    if (srv_mode_switch_is_network_service_available())
    {
        createWlanButton();

        m_shortcutBar->m_signalIsFocused.connect(this, &VappOpKeyLauncherIdlePage::onUnFocusedWlanButton);
        m_wlanButton->m_signalIsFocused.connect(this, &VappOpKeyLauncherIdlePage::onUnFocusedShrt);
    }
#endif
}


void VappOpKeyLauncherIdlePage::onDeinit()
{	
    VfxControl::onDeinit();
}


void VappOpKeyLauncherIdlePage::setHidden(VfxBool value)
{
	VfxControl::setHidden(value);

	setFocused(value != VFX_TRUE); // for receive Key event
	m_shortcutBar->setHidden(value);

#ifdef __MMI_OP01_WIFI__
    if (m_wlanButton != NULL)
    {
        m_wlanButton->setHidden(value);
    }
    
    if ((s_focuseState == FOCUSE_STATE_WLAN) && (m_wlanButton != NULL))
    {
        m_wlanButton->setFocused(value != VFX_TRUE); // for receive Key event
    }
    else
    {
        m_shortcutBar->setFocused(value != VFX_TRUE); // for receive Key event
    }    
#else
    m_shortcutBar->setFocused(value != VFX_TRUE); // for receive Key event
#endif
}


void VappOpKeyLauncherIdlePage::createShortcutBar()
{
    VfxBool isFocused = (s_focuseState == FOCUSE_STATE_SHORTCUT) ? VFX_TRUE : VFX_FALSE;
    VFX_OBJ_CREATE_EX(m_shortcutBar, VappOpKeyLauncherShrtBar, this, (isFocused));
    m_shortcutBar->setPos(0, VAPP_OP_KEYLAUNCHER_SHORTCUT_BAR_Y);
}


void VappOpKeyLauncherIdlePage::createOperatorName()
{
	VFX_OBJ_CREATE(m_opName, VappOpKeyLauncherOperatorFrame, this);
	m_opName->setPos(VAPP_OP_KEYLAUNCHER_OPNAME_X, VAPP_OP_KEYLAUNCHER_OPNAME_Y);
}

#ifdef __MMI_OP01_WIFI__
void VappOpKeyLauncherIdlePage::createWlanButton()
{
    VfxBool isFocused = (s_focuseState == FOCUSE_STATE_WLAN) ? VFX_TRUE : VFX_FALSE;
    VFX_OBJ_CREATE_EX(m_wlanButton, VappOp01KeyLauncherWlanSwitch, this, (isFocused));
    m_wlanButton->setPos(VAPP_OP_KEYLAUNCHER_SCREEN_WIDTH - VAPP_OP_KEYLAUNCHER_WLAN_BUTTON_MARGIN, VAPP_OP_KEYLAUNCHER_WLAN_BUTTON_Y);
    m_wlanButton->setAnchor(1.0f, 1.0f);
}


void VappOpKeyLauncherIdlePage::onUnFocusedWlanButton(void)
{
    if (s_focuseState == FOCUSE_STATE_WLAN)
    {
        // Set highlight image
        m_wlanButton->setUnFocused();

        // Set focuse for receive key event
        m_shortcutBar->setFocused(VFX_TRUE);
        m_wlanButton->setFocused(VFX_FALSE);

        s_focuseState = FOCUSE_STATE_SHORTCUT;
    }    
}


void VappOpKeyLauncherIdlePage::onUnFocusedShrt(void)
{
    if (s_focuseState == FOCUSE_STATE_SHORTCUT)
    {
        // Set highlight image
        m_shortcutBar->setUnFocused();

        // Set focuse for receive key event
        m_shortcutBar->setFocused(VFX_FALSE);
        m_wlanButton->setFocused(VFX_TRUE);

        s_focuseState = FOCUSE_STATE_WLAN;
    }
}


VfxBool VappOpKeyLauncherIdlePage::onKeyInput(VfxKeyEvent &event)
{
    if (m_wlanButton != NULL)
    {
    	if (event.keyCode == VFX_KEY_CODE_ARROW_UP && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    	{
        	if (s_focuseState == FOCUSE_STATE_SHORTCUT)
            {
                s_focuseState = FOCUSE_STATE_WLAN;

                // Set highlight image
                m_wlanButton->setIsFocused();
                m_shortcutBar->setUnFocused();

                // Set focuse for receive key event
                m_shortcutBar->setFocused(VFX_FALSE);
                m_wlanButton->setFocused(VFX_TRUE);
            }
    		return VFX_TRUE;
    	}
    	else if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN && event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
        	if (s_focuseState == FOCUSE_STATE_WLAN)
            {
                s_focuseState = FOCUSE_STATE_SHORTCUT;

                // Set highlight image
                m_wlanButton->setUnFocused();
                m_shortcutBar->setIsFocused();

                // Set focuse for receive key event
                m_shortcutBar->setFocused(VFX_TRUE);
                m_wlanButton->setFocused(VFX_FALSE);
            }
    		return VFX_TRUE;
    	}
    }

	return VfxControl::onKeyInput(event);
}
#endif /* __MMI_OP01_WIFI__ */

/***************************************************************************** 
 * Class VappOpKeyLauncherShrtBar
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappOpKeyLauncherShrtBar", VappOpKeyLauncherShrtBar, VfxControl);
VfxU32 VappOpKeyLauncherShrtBar::m_shortcutHighlightIdx = 0;

VappOpKeyLauncherShrtBar::VappOpKeyLauncherShrtBar(VfxBool isFocused) :
	m_shortcutCount(SHORTCUT_COUNT_MAX),
    m_isFocused(isFocused)
{
	for (VfxU32 i = 0 ; i < m_shortcutCount ; i++)
    {
        memset(m_shortcutPackage[i], 0x00, MMI_APP_NAME_MAX_LEN * sizeof(mmi_app_package_char));
		m_shortcutCell[i] = NULL;
    }
}


void VappOpKeyLauncherShrtBar::onInit()
{
    VfxControl::onInit();

	// Init shortcut package
	initShortcut();

    // Create shortcut
	for (VfxU32 i = 0 ; i < m_shortcutCount ; i++)
	{
	    m_shortcutCell[i] = createKmmCell(m_shortcutPackage[i], this, VFX_FALSE);
		m_shortcutCell[i]->setPos(SHORTCUT_BAR_MARGIN + i * m_shortcutCell[i]->getSize().width, 0);
		m_shortcutCell[i]->setIsBorderColor(VFX_TRUE);
	    m_shortcutCell[i]->onCellDisplay();
	}

	// Set shortcut bar size in idle page
	setSize(SHORTCUT_BAR_WIDTH, m_shortcutCell[0]->getSize().height);

    if (m_isFocused)
    {
        switchShortcutHighlight(0);
    }

    VAPP_OP_KEYLAUNCHER_LOG((TRC_VAPP_OP_LAUNCHER_KEY_HS_SHORTCUT_CREATE, m_shortcutCount));
	VFX_ASSERT(m_shortcutCount <= SHORTCUT_COUNT_MAX);
}


void VappOpKeyLauncherShrtBar::onDeinit()
{	
    VfxControl::onDeinit();
}


void VappOpKeyLauncherShrtBar::setIsFocused()
{
    m_shortcutCell[m_shortcutHighlightIdx]->setIsHighlighted(VFX_TRUE, VFX_TRUE);
    m_isFocused = VFX_TRUE;
}


void VappOpKeyLauncherShrtBar::setUnFocused()
{
    m_shortcutCell[m_shortcutHighlightIdx]->setIsHighlighted(VFX_FALSE, VFX_TRUE);
    m_isFocused = VFX_FALSE;
}


VfxBool VappOpKeyLauncherShrtBar::onKeyInput(VfxKeyEvent &event)
{
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
	else if (event.keyCode == VFX_KEY_CODE_CSK &&
             event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
		return VFX_TRUE;
	}
	else if (event.keyCode == VFX_KEY_CODE_CSK &&
             event.type == VFX_KEY_EVENT_TYPE_UP)
	{
		// Launch highlighted shortcut
		vfxPostInvoke(this, &VappOpKeyLauncherShrtBar::launchShortcut);
		return VFX_TRUE;
	}
	else if ((event.keyCode == VFX_KEY_CODE_ARROW_RIGHT ||
			  event.keyCode == VFX_KEY_CODE_ARROW_LEFT) &&
             event.type == VFX_KEY_EVENT_TYPE_UP)
	{
		// Mean to Don't rount key to parent
		return VFX_TRUE;
	}

	if (inc != 0)
	{
		switchShortcutHighlight(inc);
		return VFX_TRUE;
	}
	return VfxControl::onKeyInput(event);
}


VfxBool VappOpKeyLauncherShrtBar::onPenInput(VfxPenEvent &event)
{
	if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
	{
		for (VfxU32 i = 0 ; i < m_shortcutCount ; i++)
		{
			if (m_shortcutCell[i]->containPoint(event.getRelPos(m_shortcutCell[i])) == VFX_TRUE)
			{
			    m_signalIsFocused.emit();
				if (m_shortcutHighlightIdx != i)
                {
                    switchShortcutHighlight(m_shortcutCount + i - m_shortcutHighlightIdx);
                }
                else if (!m_isFocused)
                {
                    switchShortcutHighlight(0);
                }

				return VFX_TRUE;
			}
		}
	}
	else if (event.type == VFX_PEN_EVENT_TYPE_UP)
	{
		for (VfxU32 i = 0 ; i < m_shortcutCount ; i++)
		{
			if (m_shortcutCell[i]->containPoint(event.getRelPos(m_shortcutCell[i])) == VFX_TRUE)
			{
				if (m_shortcutHighlightIdx == i)
					vfxPostInvoke(this, &VappOpKeyLauncherShrtBar::launchShortcut);

				return VFX_TRUE;
			}
		}
	}
	return VfxControl::onPenInput(event);
}


void VappOpKeyLauncherShrtBar::initShortcut()
{
    m_shortcutCount = 0;
    srv_app_info_struct info;

    if (srv_appmgr_get_app_package_info("native.mtk.dialer", &info) == MMI_RET_OK)
    {
        strcpy(m_shortcutPackage[m_shortcutCount], "native.mtk.dialer");
        m_shortcutCount++;
    }

    if (srv_appmgr_get_app_package_info("native.mtk.messaging", &info) == MMI_RET_OK)
    {
        strcpy(m_shortcutPackage[m_shortcutCount], "native.mtk.messaging");
        m_shortcutCount++;
    }

    if (srv_appmgr_get_app_package_info("native.mtk.phonebook", &info) == MMI_RET_OK)
    {
        strcpy(m_shortcutPackage[m_shortcutCount], "native.mtk.phonebook");
        m_shortcutCount++;
    }

    if (srv_appmgr_get_app_package_info("native.mtk.op01_monternet", &info) == MMI_RET_OK)
    {
        strcpy(m_shortcutPackage[m_shortcutCount], "native.mtk.op01_monternet");
        m_shortcutCount++;
    }

#if 0
#if (defined(OBIGO_Q05A) || defined(OBIGO_Q03C_BROWSER))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(OPERA_BROWSER)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


void VappOpKeyLauncherShrtBar::switchShortcutHighlight(VfxS32 inc)
{
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


void VappOpKeyLauncherShrtBar::launchShortcut(void *userData)
{
	VFX_UNUSED(userData);
	VAPP_OP_KEYLAUNCHER_LOG((TRC_VAPP_OP_LAUNCHER_KEY_HS_SHORTCUT_LAUNCH, m_shortcutHighlightIdx));
	srv_appmgr_launch(m_shortcutPackage[m_shortcutHighlightIdx]);
}


/***************************************************************************** 
 * Class VappOpKeyLauncherOperatorElement 
 *****************************************************************************/
VappOpKeyLauncherOperatorElement::VappOpKeyLauncherOperatorElement(VfxS32 simId):
    m_simId(simId),
	m_imgSim(NULL),
	m_textOPN(NULL),
	m_textSPN(NULL),
	m_rightParenthesis(NULL),
	m_textPosX(VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_X)
{
}


void VappOpKeyLauncherOperatorElement::onInit()
{
    VfxFrame::onInit();

    setSize(VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_WIDTH, VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT);

	if (srv_sim_ctrl_get_num_of_inserted() > 1) // two or more SIM inserted
	{
		VFX_OBJ_CREATE(m_imgSim, VfxImageFrame, this);
		m_imgSim->setAnchor(0, 0.5);
		m_imgSim->setPos(VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_ICON_X, VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT >> 1);

		MMI_IMG_ID simImgRes[] = {IMG_GLOBAL_SIM1, IMG_GLOBAL_SIM2, IMG_GLOBAL_SIM3, IMG_GLOBAL_SIM4};
    	m_imgSim->setResId(simImgRes[m_simId]);

		m_textPosX = m_imgSim->getSize().width + VAPP_OP_KEYLAUNCHER_OPNAME_ICON_TEXT_GAP;
	}
	
    VfxFontDesc fontDesc;
	fontDesc.effect = VFX_FONT_DESC_EFFECT_BORDER;

    VFX_OBJ_CREATE(m_textOPN, VfxTextFrame, this);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE);
    m_textOPN->setFont(fontDesc);

    VFX_OBJ_CREATE(m_textSPN, VfxTextFrame, this);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_SUB_TEXT_SIZE);
    m_textSPN->setFont(fontDesc);
    
    VFX_OBJ_CREATE(m_rightParenthesis, VfxTextFrame, this);
    m_rightParenthesis->setString(VFX_WSTR(")"));
	fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE);
    m_rightParenthesis->setFont(fontDesc);
	m_rightParenthesis->setHidden(VFX_TRUE);
}


void VappOpKeyLauncherOperatorElement::updateOperatorName()
{
    srv_nw_name_service_indication_struct tmp_indication;

    srv_nw_name_get_service_indication_string(mmi_frm_index_to_sim(m_simId), &tmp_indication);  
    m_textOPN->setString(VFX_WSTR_MEM(tmp_indication.line1));
    m_textSPN->setString(VFX_WSTR_MEM(tmp_indication.line2));

	VfxS32 yPos;

    if(mmi_wcslen(tmp_indication.line2))
    {
        m_textOPN->setAnchor(0, 0);
		m_rightParenthesis->setAnchor(0, 0);
		
        m_textOPN->setPos(m_textPosX, VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_Y);
		yPos = VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_Y;
        m_textSPN->setPos(m_textPosX, VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_SUB_TEXT_Y);
        m_textSPN->setHidden(VFX_FALSE);
    }
    else
    {
        m_textOPN->setAnchor(0, 0.5);
		m_rightParenthesis->setAnchor(0, 0.5);
		
        m_textOPN->setPos(m_textPosX , VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT >> 1);
		yPos = (VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT >> 1);
        m_textSPN->setHidden(VFX_TRUE);
    }

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	VfxWChar *buffer;
	VfxWString simName;
	buffer = mmi_netset_get_sim_name(mmi_frm_index_to_sim(m_simId));

    if (buffer == NULL || buffer[0] == 0)
    {
        simName = VFX_WSTR_EMPTY;
    }		
	else
    {
        simName = VFX_WSTR_MEM(buffer);
    }

#else
    VfxWString simName = VFX_WSTR_EMPTY;
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
		temp += VFX_WSTR(" (");
		temp += VFX_WSTR_MEM(simName);
		m_textOPN->setString(temp);

		VfxS32 maxWidthSimName = getSize().width - m_textOPN->getPos().x - m_rightParenthesis->getSize().width;
		if (maxWidthSimName > m_textOPN->getSize().width)
		{
			m_textOPN->setAutoResized(VFX_TRUE);
			m_textOPN->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
			maxWidthSimName = m_textOPN->getSize().width;
		}
		else
		{
			m_textOPN->setAutoResized(VFX_FALSE);
			m_textOPN->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		}
		m_textOPN->setSize(maxWidthSimName, m_textOPN->getSize().height);
		m_textOPN->setVerticalToCenter(VFX_TRUE);
		
	    m_rightParenthesis->setPos(m_textOPN->getPos().x + m_textOPN->getSize().width, yPos);
	}
}


/***************************************************************************** 
 * Class VappOpKeyLauncherOperatorFrame 
 *****************************************************************************/
VappOpKeyLauncherOperatorFrame::VappOpKeyLauncherOperatorFrame():
	m_text(NULL)
{
	for(VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        m_operElement[i] = NULL;
    }
}


void VappOpKeyLauncherOperatorFrame::onInit()
{
    VfxFrame::onInit();

    setSize(VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_WIDTH, MMI_SIM_TOTAL * VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT);

	VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
	VfxFontDesc fontDesc;
	fontDesc.effect = VFX_FONT_DESC_EFFECT_BORDER;
	fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_SIZE);
	m_text->setFont(fontDesc);
	m_text->setAnchor(0, 0.5);
	m_text->setPos(VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_MAIN_TEXT_X, VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT >> 1);

    initOperatorNameCell();
    update();

    mmi_frm_cb_reg_event(EVT_ID_SRV_NW_NAME_CHANGED, &VappOpKeyLauncherOperatorFrame::refreshOpName, this);
}


void VappOpKeyLauncherOperatorFrame::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_NW_NAME_CHANGED, &VappOpKeyLauncherOperatorFrame::refreshOpName, this);
    VfxFrame::onDeinit();
}


mmi_ret VappOpKeyLauncherOperatorFrame::refreshOpName(mmi_event_struct* event)
{
    MMI_ASSERT(event);
    VappOpKeyLauncherOperatorFrame* operatorFrame = (VappOpKeyLauncherOperatorFrame *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_NW_NAME_CHANGED:
			VAPP_OP_KEYLAUNCHER_LOG((TRC_VAPP_OP_LAUNCHER_KEY_HS_REFRESH_OPNAME));
            operatorFrame->update();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void VappOpKeyLauncherOperatorFrame::initOperatorNameCell()
{
    VfxS32 i;
    for(i = 0; i < MMI_SIM_TOTAL; i++)
    {
        VFX_OBJ_CREATE_EX(m_operElement[i], VappOpKeyLauncherOperatorElement, this, (i));
    }
}


void VappOpKeyLauncherOperatorFrame::update()
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

        m_operElement[i]->setPos(0, numSIMInsert * VAPP_OP_KEYLAUNCHER_OPNAME_FRAME_HEIGHT);
        m_operElement[i]->setHidden(VFX_FALSE);
        numSIMInsert++;
    }
	
	VAPP_OP_KEYLAUNCHER_LOG((TRC_VAPP_OP_LAUNCHER_KEY_HS_UPDATE_OPNAME, numSIMInsert));

	m_text->setHidden(VFX_FALSE);
    
	if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
	{
		m_text->setString(VFX_WSTR_RES(STR_ID_VAPP_OP_KEYLAUNCHER_FLIGHT_MODE));
		for(i = 0; i < MMI_SIM_TOTAL; i++)
	    {
			m_operElement[i]->setHidden(VFX_TRUE);
	    }
	}
	else if(numSIMInsert == 0)
    {
        // No SIM inserted
		m_text->setString(VFX_WSTR_RES(STR_ID_VAPP_OP_KEYLAUNCHER_ECC));
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
            m_operElement[i]->updateOperatorName();
        }
    }
}


/*************************************************************************************************** 
 * Class VappOpKeyLauncherIdleModeText: idle mode text class used for display SAT icon  and string
 **************************************************************************************************/
VappOpKeyLauncherIdleModeText::VappOpKeyLauncherIdleModeText() :
    m_idleModeText(NULL),
    m_idleModeIcon(NULL),
    m_idleModeStr(VFX_WSTR_NULL)
{
}


void VappOpKeyLauncherIdleModeText::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_idleModeIcon, VfxImageFrame, this);
	m_idleModeIcon->setAnchor(0.0f, 0.5f);
    m_idleModeIcon->setPos(VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_X, VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT >> 1);
    m_idleModeIcon->setSize(VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_WIDTH, VAPP_OP_KEYLAUNCHER_IDLE_MODE_ICON_HEIGHT);
    m_idleModeIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	
    VFX_OBJ_CREATE(m_idleModeText, VcpMarquee, this);
    m_idleModeText->setAnchor(0.0f, 0.5f);
    m_idleModeText->setPos(VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_X, VAPP_OP_KEYLAUNCHER_IDLE_MODE_FRAME_HEIGHT >> 1);
    m_idleModeText->setSize(VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_WIDTH, VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_HEIGHT);
    m_idleModeText->setHalign(VcpMarquee::HALIGN_CENTER);
    m_idleModeText->setSpeed(VAPP_OP_KEYLAUNCHER_IDLE_MODE_MARQUEE_SPEED);

	updateSAT();

	mmi_frm_cb_reg_event(EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY, &VappOpKeyLauncherIdleModeText::refreshIdleModeText, this);
}


void VappOpKeyLauncherIdleModeText::onDeinit()
{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY, &VappOpKeyLauncherIdleModeText::refreshIdleModeText, this);
	VfxFrame::onDeinit();
}


void VappOpKeyLauncherIdleModeText::setIdleModeText(const VfxWString &str)
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
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_OP_KEYLAUNCHER_IDLE_MODE_TEXT_SIZE);
		
        m_idleModeText->setMovableFrame(str, fontDesc);
        m_idleModeText->startScroll();
    }

    m_idleModeStr = str;
}


void VappOpKeyLauncherIdleModeText::setIdleModeIcon(const VfxU8 *iconPtr)
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


mmi_ret VappOpKeyLauncherIdleModeText::refreshIdleModeText(mmi_event_struct* event)
{
    VappOpKeyLauncherIdleModeText* idleModeText = (VappOpKeyLauncherIdleModeText *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY:
			VAPP_OP_KEYLAUNCHER_LOG((TRC_VAPP_OP_LAUNCHER_KEY_HS_REFRESH_SAT));
            idleModeText->updateSAT();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void VappOpKeyLauncherIdleModeText::updateSAT()
{
	const VfxWChar* text = (VfxWChar*)GetSATIdleText();
	setIdleModeText(VFX_WSTR_MEM(text));

	const VfxU8 * icon = (VfxU8 *)GetSATIdleIcon();
	setIdleModeIcon(icon);
}


#ifdef __MMI_OP01_WIFI__
/***************************************************************************** 
 * Class VappOp01KeyLauncherWlanSwitch: WLAN switch class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappOp01KeyLauncherWlanSwitch", VappOp01KeyLauncherWlanSwitch, VfxControl); 
VappOp01KeyLauncherWlanSwitch::VappOp01KeyLauncherWlanSwitch(VfxBool isFocused) :
    m_buttonBg(NULL),
    m_wlanIcon(NULL),
    m_IndFrame(NULL),
    m_indTimer(NULL),
    m_scrollIndex(0),
    m_isFocused(isFocused),
    m_isNeedSwitch(VFX_TRUE),
    m_wlanStatus(WLAN_SWITCH_TOTAL)
{
    for (VfxS32 i = 0; i < 4; i++)
    {
        m_switchInd[i] = NULL;
    }
}


void VappOp01KeyLauncherWlanSwitch::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_buttonBg, VfxImageFrame, this);
    m_buttonBg->setPos(0, 0);
    m_buttonBg->setImgContent(VfxImageSrc(m_isFocused ? IMG_ID_VAPP_WLAN_BUTTON_PRESSED_BG : IMG_ID_VAPP_WLAN_BUTTON_NORMAL_BG));

    VfxSize size = m_buttonBg->getBounds().size;

    VFX_OBJ_CREATE(m_wlanIcon, VfxImageFrame, this);
    m_wlanIcon->setPos(size.width >> 1, size.height >> 1);
    m_wlanIcon->setAnchor(0.5f, 0.5f);

    VFX_OBJ_CREATE(m_IndFrame, VfxFrame, this);
    m_IndFrame->setPos(IND_POS_X, IND_POS_Y);
    m_IndFrame->setBounds(0, 0, m_buttonBg->getBounds().getWidth(), IND_HEIGHT);

    VfxS32 posX = 0;
    for (VfxS32 i = 0; i < 4; i++)
    {
        VFX_OBJ_CREATE(m_switchInd[i], VfxImageFrame, m_IndFrame);
        m_switchInd[i]->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_PROGRESS_DOT));
        m_switchInd[i]->setPos(posX, 0);
        posX += m_switchInd[i]->getSize().width + IND_GAP;
    }

    // Timer for indicator scrolling
    VFX_OBJ_CREATE(m_indTimer, VfxTimer, this);

    m_wlanStatus = getWlanState();
    VfxResId resId = 0;
    switch (m_wlanStatus)
    {
        case WLAN_SWITCH_POWER_OFF:
            resId = m_isFocused ? IMG_ID_VAPP_WLAN_DISABLE_ICON_PRESSED : IMG_ID_VAPP_WLAN_DISABLE_ICON_NORMAL;
            m_wlanIcon->setImgContent(VfxImageSrc(resId));
            m_IndFrame->setHidden(VFX_TRUE);
            break;

        case WLAN_SWITCH_POWER_WAITING:
            resId = m_isFocused ? IMG_ID_VAPP_WLAN_DISABLE_ICON_PRESSED : IMG_ID_VAPP_WLAN_DISABLE_ICON_NORMAL;
            m_wlanIcon->setImgContent(VfxImageSrc(resId));
            m_IndFrame->setHidden(VFX_FALSE);
            startScrollInd();
            break;

        case WLAN_SWITCH_POWER_ON:
        case WLAN_SWITCH_CONNECTED:
            resId = m_isFocused ? IMG_ID_VAPP_WLAN_ENABLE_ICON_PRESSED : IMG_ID_VAPP_WLAN_ENABLE_ICON_NORMAL;
            m_wlanIcon->setImgContent(VfxImageSrc(resId));
            m_IndFrame->setHidden(VFX_TRUE);
            break;

        case WLAN_SWITCH_CONNECT_WAITING:
            resId = m_isFocused ? IMG_ID_VAPP_WLAN_ENABLE_ICON_PRESSED : IMG_ID_VAPP_WLAN_ENABLE_ICON_NORMAL;
            m_wlanIcon->setImgContent(VfxImageSrc(resId));
            m_IndFrame->setHidden(VFX_FALSE);
            startScrollInd();
            break;

        default:
            break;       
    }

    VfxRect bounds = getBounds();
    bounds.size = m_buttonBg->getBounds().size;
    setBounds(bounds);

    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_ACTIVE, refreshWlanButton, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_CONNECTED, refreshWlanButton, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_INACTIVE, refreshWlanButton, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_SCAN, refreshWlanButton, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_CONNECT, refreshWlanButton, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND, refreshWlanButton, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND, refreshWlanButton, this);
}


void VappOp01KeyLauncherWlanSwitch::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND, refreshWlanButton, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND, refreshWlanButton, this);    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_CONNECTED, refreshWlanButton, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_SCAN, refreshWlanButton, this);    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_INACTIVE, refreshWlanButton, this);    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_CONNECT, refreshWlanButton, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_ACTIVE, refreshWlanButton, this);    

    VfxControl::onDeinit();
}


VappOp01KeyLauncherWlanSwitch::VappOP01WlanStateEnum VappOp01KeyLauncherWlanSwitch::getWlanState()
{
    VappOP01WlanStateEnum wlan_state = WLAN_SWITCH_POWER_OFF;

    switch (srv_dtcnt_wlan_state())
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
            wlan_state = WLAN_SWITCH_POWER_OFF;
            break;

        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
            wlan_state = WLAN_SWITCH_POWER_WAITING;
            break;

        case SRV_DTCNT_WLAN_STATE_INIT:
            wlan_state = WLAN_SWITCH_POWER_ON;
            break;
            
        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
            wlan_state = WLAN_SWITCH_CONNECT_WAITING;
            break;
            
        case SRV_DTCNT_WLAN_STATE_CONNECTED:
            wlan_state = WLAN_SWITCH_CONNECTED;
            break;
            
        default:
            wlan_state = WLAN_SWITCH_POWER_OFF;
            break;
    }

    return wlan_state;
}


mmi_ret VappOp01KeyLauncherWlanSwitch::refreshWlanButton(mmi_event_struct* event)
{
    VappOp01KeyLauncherWlanSwitch *wlanButton = (VappOp01KeyLauncherWlanSwitch *)event->user_data;
    switch (event->evt_id)
    {
        case EVT_ID_SRV_DTCNT_WLAN_ACTIVE:
        case EVT_ID_SRV_DTCNT_WLAN_CONNECTED:
        case EVT_ID_SRV_DTCNT_WLAN_INACTIVE:
        case EVT_ID_SRV_DTCNT_WLAN_SCAN:
        case EVT_ID_SRV_DTCNT_WLAN_CONNECT:
        case EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND:
        case EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND:
            wlanButton->updateButton();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
};


VfxBool VappOp01KeyLauncherWlanSwitch::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_signalIsFocused.emit();
        if (m_indTimer->getIsEnabled())
        {
            return VFX_FALSE;
        }

        m_isFocused = VFX_TRUE;
        setWlanButtonState();
        m_IndFrame->setHidden(VFX_TRUE);
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        VfxRect bounds = getBounds();
        if (bounds.contains(event.getRelPos(this)))
        {
            startScrollInd();
            switchWlan();
        }
        return VFX_TRUE;
    }

    return VfxControl::onPenInput(event);
}


VfxBool VappOp01KeyLauncherWlanSwitch::onKeyInput(VfxKeyEvent &event)
{
	if (event.keyCode == VFX_KEY_CODE_CSK &&
             event.type == VFX_KEY_EVENT_TYPE_DOWN)
	{
	    
	    m_isNeedSwitch = m_indTimer->getIsEnabled() ? VFX_FALSE : VFX_TRUE;

		return VFX_TRUE;
	}
	else if (event.keyCode == VFX_KEY_CODE_CSK &&
             event.type == VFX_KEY_EVENT_TYPE_UP)
	{
	    if (m_isNeedSwitch == VFX_TRUE)
        {   
	        // Launch WLAN switch
            startScrollInd();
            switchWlan();
        }

		return VFX_TRUE;
	}

	return VfxControl::onKeyInput(event);
}


void VappOp01KeyLauncherWlanSwitch::switchWlan()
{
    srv_dtcnt_result_enum ret = SRV_DTCNT_RESULT_SUCCESS;

    // Call WLAN switch API and the state needs AP to store it.
    if ((srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_ACTIVE) ||
        (srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_CONNECTED))
    {
        ret = mmi_wlan_cmcc_entry_deinit(VappOp01KeyLauncherWlanSwitch::wlanSwitchRsponse, (void *)getObjHandle());
    }
    else
    {
        ret = srv_dtcnt_wlan_init(NULL, NULL);
    }

    if (ret == SRV_DTCNT_RESULT_FAILED)
    {
        wlanSwitchRsponse((void *)getObjHandle(), SRV_DTCNT_WLAN_REQ_RES_DONE);
    }
}


void VappOp01KeyLauncherWlanSwitch::wlanSwitchRsponse(void *user_data, srv_dtcnt_wlan_req_res_enum res)
{
    if (res == SRV_DTCNT_WLAN_REQ_RES_DONE)
    {        
        VappOp01KeyLauncherWlanSwitch *wlanSwitch = (VappOp01KeyLauncherWlanSwitch *)VfxObject::handleToObject((VfxObjHandle*)user_data);
        if (wlanSwitch)
        {
            wlanSwitch->updateButton();
        }        
    }
}


void VappOp01KeyLauncherWlanSwitch::startScrollInd()
{
    if (m_indTimer)
    {
        m_indTimer->m_signalTick.connect(this, &VappOp01KeyLauncherWlanSwitch::onStartScrollInd);
        m_indTimer->setStartDelay(0);
        m_indTimer->setDuration(300);
        m_indTimer->start();
    }
}


void VappOp01KeyLauncherWlanSwitch::onStartScrollInd(VfxTimer *timer)
{
    m_IndFrame->setHidden(VFX_FALSE);

    for (VfxS32 i = 0; i < IND_NUMBER; i++)
    {
        if (m_scrollIndex == IND_NUMBER)
        {
            m_IndFrame->setHidden(VFX_TRUE);
            break;            
        }
        
        if (i <= m_scrollIndex)
        {
            m_switchInd[i]->setHidden(VFX_FALSE);
        }
        else
        {
            m_switchInd[i]->setHidden(VFX_TRUE);
        }
    }

    m_scrollIndex++;
    if (m_scrollIndex == IND_NUMBER + 1)
    {
        m_scrollIndex = 0;
    }
}


void VappOp01KeyLauncherWlanSwitch::setWlanButtonState()
{
    if (!m_isFocused)
    {
        m_buttonBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_BUTTON_NORMAL_BG));
        if (m_wlanStatus == WLAN_SWITCH_POWER_OFF)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_DISABLE_ICON_NORMAL));
        }
        else if (m_wlanStatus == WLAN_SWITCH_POWER_WAITING)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_DISABLE_ICON_NORMAL));
        }
        else if (m_wlanStatus == WLAN_SWITCH_POWER_ON)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_ENABLE_ICON_NORMAL));
        }
        else if (m_wlanStatus == WLAN_SWITCH_CONNECT_WAITING)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_ENABLE_ICON_NORMAL));
        }
        else if (m_wlanStatus == WLAN_SWITCH_CONNECTED)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_ENABLE_ICON_NORMAL));
        }
    }
    else
    {
        m_buttonBg->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_BUTTON_PRESSED_BG));

        if (m_wlanStatus == WLAN_SWITCH_CONNECTED)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_ENABLE_ICON_PRESSED));
        }
        else if (m_wlanStatus == WLAN_SWITCH_POWER_ON)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_ENABLE_ICON_PRESSED));
        }
        else if (m_wlanStatus == WLAN_SWITCH_POWER_OFF)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WLAN_DISABLE_ICON_PRESSED));
        }
    }
}


void VappOp01KeyLauncherWlanSwitch::updateButton()
{
    if (m_indTimer != NULL)
    {
        m_indTimer->stop();
    }

    m_wlanStatus = getWlanState();
    m_IndFrame->setHidden(VFX_TRUE);
    m_scrollIndex = 0;
    setWlanButtonState();
}


void VappOp01KeyLauncherWlanSwitch::setIsFocused()
{
    m_isFocused = VFX_TRUE;
    setWlanButtonState();
}


void VappOp01KeyLauncherWlanSwitch::setUnFocused()
{
    m_isFocused = VFX_FALSE;
    setWlanButtonState();
}

#endif /* __MMI_OP01_WIFI__ */

#endif /* defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__) */

