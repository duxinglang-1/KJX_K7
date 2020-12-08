/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  Vapp_Shell_Recent_Calls.cpp
 * 
 * Project:
 * --------
 *  Venus Shell
 * 
 * Description:
 * ------------
 *  Shell Recent Calls provides users with the convenience of quick accessing 
 *  the recent call logs, including incoming calls, out going calls and missed
 *  calls, without having to open the Kernel Call log app
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_RECENT_CALLS__

#include "vapp_shell_recent_calls.h"

#include "trc/vadp_app_trc.h"

/* auto add by kw_check begin */
#include "vadp_app_trc.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vapp_shell_panel.h"
#include "vfx_system.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vcp_tab_bar.h"
#include "vcp_state_image.h"
#include "vfx_string.h"
#include "vcp_list_menu.h"
#include "vfx_text_frame.h"
#include "vfx_signal.h"
#include "vdat_systime.h"
#include "vcp_popup.h"
#include "vfx_class_info.h"
#include "vfx_date_time.h"
#include "vfx_image_src.h"

/* auto add by kw_check end */

#ifdef __cplusplus
extern "C"
{
#include "DateTimeType.h"     // for mmi_dt_utc_sec_2_mytime
#include "App_datetime.h"     // for applib_time_struct
#include "Phbsrvgprot.h"      // for check exist api
#include "mmi_rp_app_shellapp_base_def.h"
#include "mmi_rp_app_venus_shell_recent_calls_def.h"
#include "UCMGprot.h"
#ifdef __MMI_UNIFIED_COMPOSER__
#include "UcAppGprot.h"
#else
#include "SMSAppGprot.h"
#endif
#include "CalllogSrvGprot.h"
#include "PhbCuiGprot.h"
#include "mmi_rp_app_calllog_def.h"

#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "kal_trace.h"
#include "GlobalResDef.h"
#include "mmi_cb_mgr_gprot.h"
#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "string.h"
#include "mmi_rp_app_phonebook_def.h"
#include "UcmSrvGprot.h"
#include "UcSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "kal_general_types.h"
}
#endif
/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function
 *****************************************************************************/


/*****************************************************************************
 * Class VappShellRC
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappShellRC", VappShellRC, VappShellPanel);

VappShellRC::VappShellRC() :
	m_tabBar(NULL),
	m_cmdPopupWeakPtr(NULL),
	m_helpText(NULL),
	m_RCDataProvider(NULL),	
	m_currListIdx(0),
	m_currListLogIdx(0),
	m_firstInitFlag(VFX_TRUE),
	m_realEnterRCPanel(VFX_FALSE),
	m_bgImage(NULL),
	m_bgShadow(NULL),
	m_bgTopBorder(NULL),
	m_bgTailBorder(NULL)
{
	for (VfxS32 i = 0; i < VAPP_SHELL_RC_LIST_TOTAL; i++)
	{
		m_RCList[i] = NULL;
	}
}


void VappShellRC::onInit()
{
	VappShellPanel::onInit();


    VfxS16 sError;
    VfxU16 currTabIndex = 0;
    ReadValue(NVRAM_SHELL_RECENT_CALLS_TAB_IDX, &currTabIndex, DS_SHORT, &sError);

    m_currListIdx = static_cast<VfxU32>(currTabIndex);
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_ONINIT, m_currListIdx);

	m_RCDataProvider = VFX_OBJ_GET_INSTANCE(VappShellRCDataProvider);	
}


void VappShellRC::onDeinit()
{
	VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_ONDEINIT, m_currListIdx);

	VappShellPanel::onDeinit();
}


void VappShellRC::onInitView()
{
	VappShellPanel::onInitView();
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_ONINITVIEW, m_currListIdx);

    // background image
    VFX_OBJ_CREATE(m_bgImage, VfxImageFrame, this);
    m_bgImage->setResId(VAPP_SHELL_IMG_SWITCH_BG);
    m_bgImage->setBgColor(VFX_COLOR_BLACK);
    m_bgImage->setIsOpaque(VFX_TRUE);
	
	VfxRect appBound;
	getMyBounds(appBound);

	VFX_OBJ_CREATE(m_bgShadow, VfxImageFrame, this);
	m_bgShadow->setResId(VAPP_SHELL_IMG_RC_BG_SHADOW);
    m_bgShadow->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_bgShadow->setPos(appBound.getMinX() - GAP_SHADOW, appBound.getMinY() - GAP_SHADOW);
	m_bgShadow->setSize(appBound.getWidth() + 2 * GAP_SHADOW, appBound.getHeight() + 2 * GAP_SHADOW - 1);

	VFX_OBJ_CREATE(m_bgTopBorder, VfxImageFrame, this);
	m_bgTopBorder->setResId(VAPP_SHELL_IMG_RC_BG_TOP);
    m_bgTopBorder->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	VfxS32 topImgHeight = m_bgTopBorder->getRect().getHeight() - 1; // -1 mean to topImg cover TabBar 1 pixel

	VFX_OBJ_CREATE(m_bgTailBorder, VfxImageFrame, this);
	m_bgTailBorder->setResId(VAPP_SHELL_IMG_RC_BG_TAIL);
    m_bgTailBorder->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_bgTailBorder->setAnchor(0.0f, 1.0f);
	m_bgTailBorder->setPos(appBound.getMinX(), appBound.getMaxY());
	m_bgTailBorder->setSize(appBound.getWidth(), m_bgTailBorder->getRect().getHeight());
	
	// Add tabBar
	VFX_OBJ_CREATE(m_tabBar, VcpTabBar, this);
	m_tabBar->setPos(appBound.getMinX(), appBound.getMinY() + topImgHeight);
	m_tabBar->setLayout(VCP_TABBAR_LAYOUT_TOP);
	VfxS32 tabBarHeight = m_tabBar->getRect().getHeight();
	m_tabBar->setBounds(VfxRect(0, 0, 
					appBound.getWidth(), 
					tabBarHeight));

	VcpStateImage allCallsImg, missedCallsImg;
	allCallsImg.setImage(VAPP_SHELL_IMG_RC_TAB_ALL_CALL_NORMAL,
        VAPP_SHELL_IMG_RC_TAB_ALL_CALL_HILITE, 
        0,
        VAPP_SHELL_IMG_RC_TAB_ALL_CALL_HILITE);
	missedCallsImg.setImage(VAPP_SHELL_IMG_RC_TAB_MISSED_CALL_NORMAL,
        VAPP_SHELL_IMG_RC_TAB_MISSED_CALL_HILITE, 
        0,
        VAPP_SHELL_IMG_RC_TAB_MISSED_CALL_HILITE);
	m_tabBar->addTab(VAPP_SHELL_RC_LIST_ALL, allCallsImg, VFX_WSTR_RES(STR_ID_CLOG_ALL_CALL));
	m_tabBar->addTab(VAPP_SHELL_RC_LIST_MISSED, missedCallsImg, VFX_WSTR_RES(STR_GLOBAL_MISSED_CALLS));
	m_tabBar->setHighlightedTab(m_currListIdx);

	m_RCDataProvider->setCurrListIdx(m_currListIdx);

	m_bgTopBorder->setPos(appBound.getMinX(), appBound.getMinY());
	m_bgTopBorder->setSize(appBound.getWidth(), m_bgTopBorder->getRect().getHeight());

	
	// Add listMenu
	for (VfxS32 i = 0; i < VAPP_SHELL_RC_LIST_TOTAL; i++)
	{ 
		VFX_OBJ_CREATE(m_RCList[i], VcpListMenu, this);
		m_RCList[i]->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_QUINTUPLE_TEXT);
		m_RCList[i]->setContentProvider(m_RCDataProvider);
		m_RCList[i]->setPos(appBound.getMinX(), appBound.getMinY() + topImgHeight + tabBarHeight);
		m_RCList[i]->setAnchor(0.0f, 0.0f);
		m_RCList[i]->setBounds(VfxRect(0, 0, 
			appBound.getWidth(), 
			appBound.getHeight() - tabBarHeight - topImgHeight - m_bgTailBorder->getRect().getHeight()));
	}
	
	VFX_OBJ_CREATE(m_helpText, VfxTextFrame, this);

    // Update the curr List immediately.
    onUpdateList(m_RCDataProvider, m_currListIdx);

	regListener();
}


void VappShellRC::onDeinitView()
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_ONDEINITVIEW);

	  for (VfxS32 i = 0; i < VAPP_SHELL_RC_LIST_TOTAL; i++)
	  {
		  VFX_OBJ_CLOSE(m_RCList[i]);
	  }
	  VFX_OBJ_CLOSE(m_tabBar);
	  VFX_OBJ_CLOSE(m_helpText);
	  VFX_OBJ_CLOSE(m_bgImage);
	  VFX_OBJ_CLOSE(m_bgShadow);
	  VFX_OBJ_CLOSE(m_bgTopBorder);
	  VFX_OBJ_CLOSE(m_bgTailBorder);

	  deregListener();
    VappShellPanel::onDeinitView();
}


void VappShellRC::onEnterView()
{
	VappShellPanel::onEnterView();
	VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_ONENTERVIEW, m_currListIdx);

    m_realEnterRCPanel = VFX_FALSE;
    vfxPostInvoke0(this, &VappShellRC::enterRCPanel);

	// Connect signal to change list when user switch tabBar
	m_tabBar->m_signalTabSwitched.connect(this, &VappShellRC::onChangeList);
	
	// Connect signal to refresh the recent event time string.
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappShellRC::onTimeChanged);

	// Connect signal to refresh the recent call lists.
    m_RCDataProvider->m_signalRCChanged.connect(this, &VappShellRC::onUpdateList);
    
	// Connect signal to list item tap event
	for (VfxS32 i = 0; i < VAPP_SHELL_RC_LIST_TOTAL; i++)
	{
		m_RCList[i]->m_signalItemTapped.connect(this, &VappShellRC::onTabRCItem);
	}
}

void VappShellRC::enterRCPanel()
{
    m_realEnterRCPanel = VFX_TRUE;
}

void VappShellRC::onExitView(ShellExitCauseEnum cause)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_ONEXITVIEW, m_currListIdx, cause, m_realEnterRCPanel);

    if (m_realEnterRCPanel == VFX_TRUE)
    {
		m_RCDataProvider->clearUnreadFlag();
    }
    m_realEnterRCPanel = VFX_FALSE;
    
    m_RCDataProvider->m_signalRCChanged.disconnect(this, &VappShellRC::onUpdateList);
	

    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
	systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappShellRC::onTimeChanged);

	m_tabBar->m_signalTabSwitched.disconnect(this, &VappShellRC::onChangeList);
	for (VfxS32 i = 0; i < VAPP_SHELL_RC_LIST_TOTAL; i++)
	{
		m_RCList[i]->m_signalItemTapped.disconnect(this, &VappShellRC::onTabRCItem);
	}
    VcpCommandPopup *cmdPopup = m_cmdPopupWeakPtr.get();
	if (cmdPopup != NULL)
	{
        VFX_OBJ_CLOSE(cmdPopup);
    }
    
	VappShellPanel::onExitView(cause);
}


void VappShellRC::getMyBounds(VfxRect &appBound)
{
	appBound = getAppBounds();
	appBound.origin.x += GAP_MIN_X;
	appBound.origin.y += GAP_MIN_Y;
	appBound.size.width -= (GAP_MIN_X + GAP_MAX_X);
	appBound.size.height -= (GAP_MIN_Y + GAP_MAX_Y);
}


void VappShellRC::regListener()
{
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_ADD_LOG, VappShellRC::listener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_UPDATE_LOG, VappShellRC::listener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_UPDATE_ALL, VappShellRC::listener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_LOG, VappShellRC::listener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_ALL, VappShellRC::listener, NULL);
	mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_READY, VappShellRC::listener, NULL);
}


void VappShellRC::deregListener()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_ADD_LOG, VappShellRC::listener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_UPDATE_LOG, VappShellRC::listener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_UPDATE_ALL, VappShellRC::listener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_LOG, VappShellRC::listener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_ALL, VappShellRC::listener, NULL);
	mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_READY, VappShellRC::listener, NULL);
}


mmi_ret VappShellRC::listener(mmi_event_struct* evt)
{
    VfxU32 srvState;
	VappShellRCDataProvider *RCDataProvider = VFX_OBJ_GET_INSTANCE(VappShellRCDataProvider);

    switch(evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            cui_phb_save_contact_result_struct* save_ret = (cui_phb_save_contact_result_struct*) evt;
            cui_phb_save_contact_close(save_ret->sender_id);
            break;
        }
              
    	case EVT_ID_SRV_CLOG_ADD_LOG:
        {
            srv_clog_evt_add_log_struct *add_evt = (srv_clog_evt_add_log_struct *) evt;
            VfxU8 log_type = add_evt->new_idf.log_type;
            
            srvState = VappShellRCDataProvider::SRV_READY;
            RCDataProvider->processRCChanged(srvState, log_type);
            break;
    	}
        case EVT_ID_SRV_CLOG_DEL_LOG:
        {
            srv_clog_evt_del_log_struct *del_evt = (srv_clog_evt_del_log_struct *) evt;
            VfxU8 log_type = del_evt->idf.log_type;
            
            srvState = VappShellRCDataProvider::SRV_READY;
            RCDataProvider->processRCChanged(srvState, log_type);
            break;
    	}
        case EVT_ID_SRV_CLOG_UPDATE_LOG:
        case EVT_ID_SRV_CLOG_UPDATE_ALL:
        case EVT_ID_SRV_CLOG_DEL_ALL:
		case EVT_ID_SRV_CLOG_READY:	
        {
            srvState = VappShellRCDataProvider::SRV_READY;
            RCDataProvider->processRCChanged(srvState, SRV_CLOG_CLT_ALL);
            break;
    	}

        default:
            break;
    }

    return MMI_RET_OK;
}
    

void VappShellRC::onUpdateList(VappShellRCDataProvider *rcDP, VfxId updateListIdx)
{    
    VFX_UNUSED(rcDP);
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_UPDATELIST, m_currListIdx, updateListIdx);

	if (m_currListIdx == updateListIdx)
	{
    	setIsHideList(updateListIdx);
        m_RCList[updateListIdx]->reset();
        //m_RCList[updateListIdx]->updateAllItems();
		updateHelpText(updateListIdx);
	}	
}


void VappShellRC::onChangeList(VfxObject *tabBar, VfxId tabIdx)// if need to rsp tabswitch when rc unaviable?
{
    VFX_UNUSED(tabBar);
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_CHANGELIST, m_currListIdx, tabIdx);
    if (m_currListIdx == tabIdx)
    {
        return;
    }
    m_RCList[m_currListIdx]->setContentProvider(NULL);
    m_currListIdx = tabIdx;
    m_RCList[m_currListIdx]->setContentProvider(m_RCDataProvider);
	m_RCDataProvider->setCurrListIdx(tabIdx);

	VfxS16 sError;
    VfxU16 currTabIndex;
    if (VAPP_SHELL_RC_LIST_ALL == m_currListIdx)
	{
		currTabIndex = VAPP_SHELL_RC_LIST_ALL;
	}
	else
	{
		currTabIndex = VAPP_SHELL_RC_LIST_MISSED;
	}
	WriteValue(NVRAM_SHELL_RECENT_CALLS_TAB_IDX, &currTabIndex, DS_SHORT, &sError);

	// Update the time string of each event.    
    onUpdateList(m_RCDataProvider, m_currListIdx);    
}


void VappShellRC::setIsHideList(VfxU32 unhideIdx)
{
	for (VfxU32 i = 0; i < VAPP_SHELL_RC_LIST_TOTAL; i++)
	{
		if (i != unhideIdx)  // should hide 
		{
			m_RCList[i]->setHidden(VFX_TRUE);

		}
		else
		{
			m_RCList[i]->setHidden(VFX_FALSE);

		}		
	}
}


VfxBool VappShellRC::updateHelpText(VfxU32 listIdx)
{
    m_helpText->setColor(VFX_COLOR_BLACK);
	
    if (m_currListIdx != listIdx)
    {
        m_helpText->setHidden(VFX_TRUE);
        return VFX_FALSE;
    }

    if (m_RCDataProvider->getSrvState() != VappShellRCDataProvider::SRV_NOT_READY)
    {
        if (m_RCDataProvider->getCount() != 0)
        {
            m_helpText->setHidden(VFX_TRUE);
            return VFX_FALSE;
        }
        else
        {
            m_helpText->setHidden(VFX_FALSE);
            m_helpText->setString(VFX_WSTR_RES(VAPP_SHELL_STR_RC_NO_CALLS));
        }
    }
    else
    {
        m_helpText->setHidden(VFX_FALSE);
        m_helpText->setString(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
    }
    
    VfxRect appBound = m_RCList[0]->getRect();
	VfxPoint pos = appBound.getMidPoint();
	m_helpText->setAnchor(0.5f, 0.5f);
	m_helpText->setPos(pos);

    return VFX_TRUE;
}


void VappShellRC::onTimeChanged(VfxU32 flag)
{
    if ((flag & VDAT_SYSTIME_CHANGED_DAY) && m_RCDataProvider->getCount() > 0)
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_TIMECHANGE, flag);

        // Update the time string of each call log    
        onUpdateList(m_RCDataProvider, m_currListIdx);
    }
}


void VappShellRC::onTabRCItem(VcpListMenu *list, VfxU32 index)
{
	VFX_UNUSED(list);
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_TABRCITEM, m_currListIdx, index);
    showCmdPopup(index);
	m_currListLogIdx = index;
}


void VappShellRC::showCmdPopup(const VfxU32 &logItemIdx)
{
	if (m_cmdPopupWeakPtr.get() != NULL)
	{
        return;
    }
    VcpCommandPopup *cmdPopup;
	VFX_OBJ_CREATE(cmdPopup, VcpCommandPopup, findScreen());
	
    if (m_RCDataProvider->getLogItem(logItemIdx) == VFX_FALSE)
		return;
	memcpy(&m_tabRCItemPhbID, &m_RCDataProvider->m_RCItemCache.phb_id, sizeof(SRV_PHB_ID));
	

	VfxBool is_voip = (m_RCDataProvider->m_RCItemCache.sub_type == SRV_CLOG_CALL_TYPE_VOIP ? VFX_TRUE : VFX_FALSE);
    VfxBool is_phb_contact = m_RCDataProvider->m_RCItemCache.is_phb_contact;
    VfxBool is_number_empty = m_RCDataProvider->getLogNumber().isEmpty();
	VfxBool is_name_empty = m_RCDataProvider->getLogName().isEmpty();
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_SHOWCMDPOPUP, is_phb_contact, is_name_empty, is_number_empty, is_voip);
    
	VfxWString title; //? todo: if no caller id, no name and no number
    
	if (!is_phb_contact)
	{
		if (!is_number_empty)
		{
			title = m_RCDataProvider->getLogNumber();
		}
		else
		{
			if (is_name_empty)
		    {
			    title = VFX_WSTR_RES(VAPP_SHELL_STR_RC_UNKNOWN);
		    }
		    else
		    {
			    title = m_RCDataProvider->getLogName();
		    }
		}		
	}
    else // is phb contact
    {
		if (is_name_empty)
		{
			title = VFX_WSTR_RES(VAPP_SHELL_STR_RC_UNNAMED);
		}
		else
		{
			title = m_RCDataProvider->getLogName();
		}
		
        if (!is_number_empty)
        {
            title += VFX_WSTR("\n");
            title += m_RCDataProvider->getLogNumber();
        }
    }
    
    //cmdPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    cmdPopup->setText(title);

    if(!is_number_empty)
	{
		cmdPopup->addItem(CMD_MENU_CALL, VFX_WSTR_RES(STR_GLOBAL_DIAL), VCP_POPUP_BUTTON_TYPE_NORMAL);
	}
	if(!is_voip && !is_number_empty)
	{
		cmdPopup->addItem(CMD_MENU_SEND_MSG, VFX_WSTR_RES(STR_GLOBAL_SEND_MESSAGE), VCP_POPUP_BUTTON_TYPE_NORMAL);
	}
    if (!is_phb_contact && !is_number_empty)
	{
		if (CUI_PHB_SAVE_CONTACT_NEW & cui_phb_save_contact_get_support_type())
        {
			cmdPopup->addItem(CMD_MENU_ADD_NEW_CONTACT, VFX_WSTR_RES(STR_ID_PHB_ADD_NEW_CONTACT), VCP_POPUP_BUTTON_TYPE_NORMAL);
        }
		if ((CUI_PHB_SAVE_CONTACT_REPLACE & cui_phb_save_contact_get_support_type()) && !is_voip)
        {
        #ifdef __MMI_SAVE_CONTACT_REPLACE__    
    	    cmdPopup->addItem(CMD_MENU_REPLACE_CONTACT, VFX_WSTR_RES(STR_ID_SAVE_CONTACT_OPT_UPDATE), VCP_POPUP_BUTTON_TYPE_NORMAL);
        #endif
        }
    }
	
	cmdPopup->addItem(CMD_MENU_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    cmdPopup->setAutoDestory(VFX_TRUE);

	cmdPopup->m_signalButtonClicked.connect(this, &VappShellRC::onClickCmdBtn);

    m_cmdPopupWeakPtr = cmdPopup;
	m_cmdPopupWeakPtr.get()->show(VFX_TRUE);    
}


void VappShellRC::onClickCmdBtn(VfxObject *obj, VfxId btn_id)
{
    VFX_UNUSED(obj);

    if (m_cmdPopupWeakPtr.get() == NULL)
        return;
    
	VfxWString tempString = m_cmdPopupWeakPtr.get()->getText();
	const VfxWChar *buffer = tempString.getBuf();
    VfxS32 len = tempString.getLength();

    for (VfxS32 i = len - 1; i >= 0; i--) // find log number (no log name)
    {
        if (buffer[i] == '\n')
        {
            buffer = &buffer[i+1];
            break;
        }
    }


    VfxBool is_voip = (m_RCDataProvider->m_RCItemCache.sub_type == SRV_CLOG_CALL_TYPE_VOIP ? VFX_TRUE : VFX_FALSE);
    VfxBool is_phb_contact = m_RCDataProvider->m_RCItemCache.is_phb_contact;
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_CLICKBTN, is_voip, is_phb_contact, btn_id);
    VfxU32 save_type;
    switch (btn_id)
    {
        case CMD_MENU_CALL:
            makeCall(buffer);
            break;

        case CMD_MENU_SEND_MSG:
            sendSms(buffer);
            break;

        case CMD_MENU_ADD_NEW_CONTACT:
            save_type = CUI_PHB_SAVE_CONTACT_NEW;
            saveContact(buffer, is_voip, save_type);
            break;

        case CMD_MENU_REPLACE_CONTACT:
            save_type = CUI_PHB_SAVE_CONTACT_REPLACE;
            saveContact(buffer, is_voip, save_type);
            break;
			
        default :
            break;
	}
}


void VappShellRC::makeCall(const VfxWChar *number)
{
	mmi_ucm_make_call_para_struct call_para;
	void *phb_udata;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&call_para);
    call_para.dial_type = (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL;
    call_para.ucs2_num_uri = (U16*)number;
    call_para.adv_para.after_make_call_callback = makeCallCb;
	
	if (m_RCDataProvider->getLogItem(m_currListLogIdx) == VFX_FALSE)
		return;
	memcpy(&m_tabRCItemPhbID, &m_RCDataProvider->m_RCItemCache.phb_id, sizeof(SRV_PHB_ID));

	if(srv_phb_check_number_id(m_tabRCItemPhbID))
		phb_udata = srv_phb_create_cm_user_data_by_id(m_tabRCItemPhbID);
	else if(m_RCDataProvider->getLogName().getLength())
		phb_udata = srv_phb_create_cm_user_data((U16 *)(m_RCDataProvider->getLogName().getBuf()), 0, SRV_PHB_INVALID_INDEX);
	else
		phb_udata = NULL;

    call_para.adv_para.after_callback_user_data = phb_udata;
    call_para.adv_para.phb_data = phb_udata;
    mmi_ucm_call_launch(GRP_ID_ROOT, &call_para);

}


void VappShellRC::makeCallCb(mmi_ucm_after_make_call_cb_struct* cb_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(cb_para->user_data)
		srv_phb_destory_cm_user_data(cb_para->user_data);
}


void VappShellRC::sendSms(const VfxWChar *number)
{
#ifdef __MMI_UNIFIED_COMPOSER__
	
    mmi_uc_entry_write_struct data;
    mmi_uc_addr_struct addr;
	
    memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
    memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));
    data.addr_num = 1;
    addr.addr = (U8 *)number;//addr.addr = (kal_uint8*) addr_p;
    
    addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
	
    addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
    data.addr = &addr;
    data.msg_type = MMI_UC_MSG_TYPE_DEFAULT;
    mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
	
#else // __MMI_UNIFIED_COMPOSER__
	
	U8 len;    
    mmi_sms_write_msg_para_struct sms_write_struct;
	sms_write_struct.srcport = 0;
    sms_write_struct.desport = 0;
    sms_write_struct.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    sms_write_struct.stringlength = 0;
    sms_write_struct.string =  NULL;
    sms_write_struct.filename = NULL;
    sms_write_struct.dcs = SMSAL_UCS2_DCS;
    sms_write_struct.dcs_class = 0;
	
    len = mmi_ucs2strlen((const CHAR *)number);
    sms_write_struct.ascii_addr = (U8 *)OslMalloc(len + 1);
	mmi_ucs2_to_asc((CHAR *)sms_write_struct.ascii_addr, (CHAR *)number);
	
	mmi_sms_write_msg_lanch(0, &sms_write_struct);
	
    OslMfree(sms_write_struct.ascii_addr);
#endif // __MMI_UNIFIED_COMPOSER__
}


void VappShellRC::saveContact(const VfxWChar *number, VfxBool is_voip, VfxU32 save_type)
{
	mmi_id cui_id;
    MMI_ID gruop_id;

    gruop_id = mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, VappShellRC::listener, NULL);
    mmi_frm_group_enter(gruop_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_id = cui_phb_save_contact_create(gruop_id);

    if (cui_id != GRP_ID_INVALID)
    {

        cui_phb_save_contact_set_type(cui_id, save_type);

    #ifdef __MMI_VOIP__
        if (is_voip)
        {
            cui_phb_save_contact_set_voip(cui_id, (U16 *)number);
        }
        else
    #endif /* __MMI_VOIP__ */
        {
            cui_phb_save_contact_set_number(cui_id, (U16 *)number);
        }
        cui_phb_save_contact_run(cui_id);
    }
}


/*****************************************************************************
 * Class VappShellRCDataProvider
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShellRCDataProvider", VappShellRCDataProvider, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappShellRCDataProvider);

VappShellRCDataProvider::VappShellRCDataProvider() :
    m_currList(NULL),
    m_currListIdx(0),
    m_srvState(SRV_NOT_READY)
{
}


void VappShellRCDataProvider::setCurrListIdx(VfxU32 currListIdx)
{
	m_currListIdx = currListIdx;
}


VfxU32 VappShellRCDataProvider::getCurrListIdx(void) const
{
	return m_currListIdx;
}


VfxU32 VappShellRCDataProvider::getSrvState()
{
	if (srv_clog_is_ready())
	{
		m_srvState = SRV_READY;
	}
	else
	{
		m_srvState = SRV_NOT_READY;
	}
	
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_SRVSTATE, getCurrListIdx());
	return m_srvState;
}


void VappShellRCDataProvider::processRCChanged(VfxU32 srvState, VfxU8 log_type)
{	
	VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_PROCESSEVENT, m_currListIdx, log_type, srvState);

    m_srvState = srvState;
    if (m_currListIdx == VAPP_SHELL_RC_LIST_MISSED && (log_type & SRV_CLOG_CLT_MISSED) != SRV_CLOG_CLT_MISSED)
        return;    
        
	m_signalRCChanged.emit(this, m_currListIdx);
}


void VappShellRCDataProvider::setMenu(VcpListMenu *listMenu)
{
	m_currList = listMenu;
}


VfxBool VappShellRCDataProvider::getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{    
	if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
	{
		VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_GETTEXT, index, fieldType);   

		if (getLogItem(index) == VFX_FALSE)
			return VFX_FALSE;
		
		if (!m_RCItemCache.name.isEmpty())
		{
			text = m_RCItemCache.name;
		}
		else if (m_RCItemCache.is_phb_contact)
		{
			text = VFX_WSTR_RES(VAPP_SHELL_STR_RC_UNNAMED);
		}
		else
		{
			text = VFX_WSTR_RES(VAPP_SHELL_STR_RC_UNKNOWN);
		}
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	}
	else if (fieldType == VCP_LIST_MENU_FIELD_TAIL_TEXT)
	{
		if (m_RCItemCache.unread_count > 1)
        {
            VfxWString countStr;
            countStr.format("(%d)", m_RCItemCache.unread_count);
            text = countStr;
        }
		else
		{
			text.setNull();
		}
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	}
	else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
	{
		text = m_RCItemCache.number;
		color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
	}
	else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
	{
		color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
		// ingore that timestamp larger than phone time  //VFX_DATE_TIME_DATE_MASK;
		if (m_RCItemCache.timestamp == 0) // indicate this log is sync form SIM, no call timestamp
	    {
            text.setNull();
	    }
        else if (isToday(m_RCItemCache.time))
		{
			text = VFX_WSTR_RES(VAPP_SHELL_STR_RC_TODAY);
		}
		else 
		{
			VfxWChar buf[20];
		    VfxU32 flags;
			if (isCurrYear(m_RCItemCache.time))
		    {
		        flags = VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;
                m_RCItemCache.time.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));		    
		        text = VFX_WSTR_MEM(buf);
		    }
		    else
		    {
		        //flags = VFX_DATE_TIME_DATE_YEAR;
                text.format("%d", m_RCItemCache.time.getYear());
		    }	    
		}
	}
	else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT3)
	{
		if (!isCurrYear(m_RCItemCache.time) || (m_RCItemCache.timestamp == 0))
		{
            text.setNull();
            return VFX_TRUE;
		}

        VfxWChar buf[20];
		VfxU32 flags;
		flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;

		m_RCItemCache.time.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));
		text = VFX_WSTR_MEM(buf);
		color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
	}
	else
	{
		return VFX_FALSE;
	}
	return VFX_TRUE;	
}


VfxBool VappShellRCDataProvider::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        )
{
    if (VCP_LIST_MENU_FIELD_ICON != fieldType)
	{
		return VFX_FALSE;
	}

	if (getLogItem(index) == VFX_FALSE)
			return VFX_FALSE;

    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_GETIMAGE, index, fieldType, m_RCItemCache.log_type);
    
	return getLogIcon(m_RCItemCache, image);
}


VfxBool VappShellRCDataProvider::getLogIcon(
									VappShellRCInfo &log,            // [IN] the log data
									VfxImageSrc &image               // [OUT] the image resource
									)
{
	// Now only support call log, in futrue support sms log, nwpd log
	VfxBool flag = VFX_TRUE;
    switch(log.sub_type)
    {
		case SRV_CLOG_CALL_TYPE_VOICE:
    #if defined(__MMI_VIDEO_TELEPHONY__) || defined(__MMI_VOIP__)
		case SRV_CLOG_CALL_TYPE_VIDEO:
		case SRV_CLOG_CALL_TYPE_VOIP:		
	#endif /* __MMI_VIDEO_TELEPHONY__ || __MMI_VOIP__*/
		{			
		#if (MMI_MAX_SIM_NUM == 1)
			switch(log.log_type)
			{
				case SRV_CLOG_CLT_MISSED:
					image.setResId(VAPP_SHELL_IMG_RC_LIST_MISSED);
					break;

				case SRV_CLOG_CLT_DIALED:
					image.setResId(VAPP_SHELL_IMG_RC_LIST_DIALED);
					break;
							
				case SRV_CLOG_CLT_RECVED:
					image.setResId(VAPP_SHELL_IMG_RC_LIST_RECVED);
					break;
							
				default:
					flag = VFX_FALSE;
					break;
			}			

		#else /* (MMI_MAX_SIM_NUM == 1) */
			switch(log.sim_id)
			{
            #if (MMI_MAX_SIM_NUM >= 2)
				case MMI_SIM1:
				{
					switch(log.log_type)
					{
						case SRV_CLOG_CLT_MISSED:
							image.setResId(VAPP_SHELL_IMG_RC_LM_SIM1);
							break;

						case SRV_CLOG_CLT_DIALED:
							image.setResId(VAPP_SHELL_IMG_RC_LD_SIM1);
							break;
							
						case SRV_CLOG_CLT_RECVED:
							image.setResId(VAPP_SHELL_IMG_RC_LR_SIM1);
							break;
							
						default:
							flag = VFX_FALSE;
							break;
					}
					break;
				}

				case MMI_SIM2:
				{
					switch(log.log_type)
					{
						case SRV_CLOG_CLT_MISSED:
							image.setResId(VAPP_SHELL_IMG_RC_LM_SIM2);
							break;
							
						case SRV_CLOG_CLT_DIALED:
							image.setResId(VAPP_SHELL_IMG_RC_LD_SIM2);
							break;
							
						case SRV_CLOG_CLT_RECVED:
							image.setResId(VAPP_SHELL_IMG_RC_LR_SIM2);
							break;
							
						default:
							flag = VFX_FALSE;
							break;
					}
					break;
				}
            #endif /* (MMI_MAX_SIM_NUM >= 2) */
            
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMI_SIM3:
				{
					switch(log.log_type)
					{
						case SRV_CLOG_CLT_MISSED:
							image.setResId(VAPP_SHELL_IMG_RC_LM_SIM3);
							break;

						case SRV_CLOG_CLT_DIALED:
							image.setResId(VAPP_SHELL_IMG_RC_LD_SIM3);
							break;
							
						case SRV_CLOG_CLT_RECVED:
							image.setResId(VAPP_SHELL_IMG_RC_LR_SIM3);
							break;
							
						default:
							flag = VFX_FALSE;
							break;
					}
					break;
				}
            #endif /* (MMI_MAX_SIM_NUM >= 3) */

            #if (MMI_MAX_SIM_NUM >= 4)
				case MMI_SIM4:
				{
					switch(log.log_type)
					{
						case SRV_CLOG_CLT_MISSED:
							image.setResId(VAPP_SHELL_IMG_RC_LM_SIM4);
							break;
							
						case SRV_CLOG_CLT_DIALED:
							image.setResId(VAPP_SHELL_IMG_RC_LD_SIM4);
							break;
							
						case SRV_CLOG_CLT_RECVED:
							image.setResId(VAPP_SHELL_IMG_RC_LR_SIM4);
							break;
							
						default:
							flag = VFX_FALSE;
							break;
					}
					break;
				}
            #endif /* (MMI_MAX_SIM_NUM >= 4) */

                default:
                    flag = VFX_FALSE;
                    break;
			}
		#endif /* (MMI_MAX_SIM_NUM == 1) */
			break;
		}	
			
		default:
			flag = VFX_FALSE;
			break;
    }    
	
	return flag;
}


VfxU32 VappShellRCDataProvider::getCount() const
{
	SRV_CLOG_HANDLE hdlr;		
	createCLogInstance(hdlr);

    srv_clog_log_identity_struct req = {0};

    req.log_type = (getCurrListIdx() == VAPP_SHELL_RC_LIST_ALL) ? SRV_CLOG_CLT_ALL : SRV_CLOG_CLT_MISSED;


    srv_clog_num_info_struct array = {0};
    VfxS32 flag = VFX_TRUE;    
    flag = srv_clog_get_list_num_info(hdlr, 
                                 (const srv_clog_log_identity_struct *)&req, 
                                 &array);

	srv_clog_destroy(hdlr);
	if (flag != SRV_CLOG_RET_OK)
	{
		return 0;
	}

	VfxU32 itemcount = array.num[SRV_CLOG_LOG_NUM_TYPE_TOTAL_LOGS];
    VFX_LOG(VFX_INFO2, VAPP_SHELL_RC_GETCOUNT, m_currListIdx, itemcount);

	return itemcount;
}


VfxBool VappShellRCDataProvider::isToday(const VfxDateTime &time) const
{
	VfxDateTime currTime;
	currTime.setCurrentTime();

    if (time.getYear() == currTime.getYear()&&
        time.getMonth() == currTime.getMonth() &&
        time.getDay() == currTime.getDay())
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


VfxBool VappShellRCDataProvider::isCurrYear(const VfxDateTime &time) const
{
    VfxDateTime currTime;
	currTime.setCurrentTime();

    if (time.getYear() == currTime.getYear())
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


VfxBool VappShellRCDataProvider::getLogItem(VfxU32 logItemIdx)
{
	SRV_CLOG_HANDLE hdlr;		
	createCLogInstance(hdlr);

    srv_clog_get_list_log_req_struct req = {0};
    srv_clog_get_list_log_cnf_struct cnf_data = {0};

	req.log_type = (getCurrListIdx() == VAPP_SHELL_RC_LIST_ALL) ? SRV_CLOG_CLT_ALL : SRV_CLOG_CLT_MISSED;    
	req.get_by = SRV_CLOG_BY_IDX;
    req.get_elm = logItemIdx;
    req.fields = 0; // all fields

    VfxS32 flag = VFX_TRUE;
	flag = srv_clog_get_list_log(hdlr,
                          (const srv_clog_get_list_log_req_struct *)&req, 
                          &cnf_data);
    srv_clog_destroy(hdlr);
	if (flag != SRV_CLOG_RET_OK)
	{
		return VFX_FALSE;
	}
	
    srv_clog_call_log_struct *callLog = &cnf_data.log.data.call_log;

	m_RCItemCache.cate = callLog->cate;
	m_RCItemCache.sim_id = callLog->sim_id;
	m_RCItemCache.log_type = callLog->log_type;
	m_RCItemCache.sub_type = callLog->sub_type;
    
    m_RCItemCache.name = VFX_WSTR_MEM((VfxWChar *)callLog->name);
	m_RCItemCache.number = VFX_WSTR_MEM((VfxWChar *)callLog->cid);
    
    applib_time_struct startTime; 
    VfxU32 local_sec = applib_dt_sec_utc_to_local(callLog->timestamp[SRV_CLOG_LASTEST_TIME_IDX]);
	mmi_dt_utc_sec_2_mytime(local_sec, &startTime, MMI_FALSE);
    m_RCItemCache.time.setDateTime(&startTime);
    m_RCItemCache.timestamp = callLog->timestamp[SRV_CLOG_LASTEST_TIME_IDX];
    m_RCItemCache.unread_count = callLog->unread_num;

    m_RCItemCache.is_phb_contact = (srv_phb_check_number_id(callLog->phb_id) == MMI_TRUE ? VFX_TRUE : VFX_FALSE);
    //m_RCItemCache.phb_id = callLog->phb_id;
	memcpy(&m_RCItemCache.phb_id, &callLog->phb_id, sizeof(SRV_PHB_ID));

	return VFX_TRUE;
}


const VfxWString& VappShellRCDataProvider::getLogName() const
{
	return m_RCItemCache.name;
}


const VfxWString& VappShellRCDataProvider::getLogNumber() const
{
	return m_RCItemCache.number;
}


void VappShellRCDataProvider::createCLogInstance(SRV_CLOG_HANDLE &hdlr) const
{
	VfxU32 sim_id = MMI_SIM_ALL;

	srv_clog_create_struct rc_create;
    rc_create.identity.cate = SRV_CLOG_CATE_CALL;
    rc_create.identity.sim_id = sim_id;
    rc_create.identity.log_type = (getCurrListIdx() == VAPP_SHELL_RC_LIST_ALL ? SRV_CLOG_CLT_ALL : SRV_CLOG_CLT_MISSED);
    rc_create.identity.sub_type = SRV_CLOG_CALL_TYPE_ALL;
    rc_create.user_data = NULL;

    hdlr = srv_clog_create((const srv_clog_create_struct *)&rc_create);
}


void VappShellRCDataProvider::clearUnreadFlag() const
{
    if (srv_clog_get_unread_missed_call_num() == 0)
        return;
    
    srv_clog_update_all_logs_req_struct req = {0};
	req.log_type = (getCurrListIdx() == VAPP_SHELL_RC_LIST_ALL) ? SRV_CLOG_CLT_ALL : SRV_CLOG_CLT_MISSED;
	req.req_fields = SRV_CLOG_LOG_FIELD_UNREAD_NUM;
	req.read = MMI_TRUE;
	srv_clog_update_all_logs(0, 0,
		(const srv_clog_update_all_logs_req_struct *)&req,
        NULL);	
}


#endif // __MMI_VUI_SHELL_RECENT_CALLS__

