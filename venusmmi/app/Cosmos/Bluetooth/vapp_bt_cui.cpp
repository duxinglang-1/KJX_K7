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
 *  vapp_bt_cui.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h" 
#ifdef __MMI_BT_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "BtcmSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "conversions.h"
#include "GlobalResDef.h"
}

#include "vcp_include.h"
#include "vfx_app_launcher.h"
#include "mmi_rp_vapp_bt_main_def.h"
#include "vapp_bt_main.h"
#include "vapp_bt_cui.h"
#include "vcui_bt_gprot.h"
#include "vcp_confirm_popup.h"
#include "vcp_popup_data_type.h"
#include "Vcp_global_popup.h"
#include "vapp_ncenter_gprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifndef __VAPP_BT_DEBUG_INTENAL__
#define __VAPP_BT_DEBUG_INTENAL__
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
mmi_id VappBtPowerOnCui::m_btPowerOnCuiId = GRP_ID_INVALID;

/***************************************************************************** 
 * Function
 *****************************************************************************/

void VappBtSelDevPage::onInit()
{
	VfxResId strId,strId2, imageId;
	VfxS32 bottomButId;
	
	
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSELDEVPAGE_ONINIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    VappBTPageBase::onInit();
	m_selectDevInfo = NULL;

    VFX_OBJ_CREATE(m_btSelDevPageTitleBar, VcpTitleBar, this);
	strId2 = STR_ID_VAPP_BT_RECENT_DEVICE;
    setTopBar(m_btSelDevPageTitleBar);

	initDevLis();

    VFX_OBJ_CREATE(m_btSelDevPageBBar, VcpToolBar, this);
    setBottomBar(m_btSelDevPageBBar);

	
    VfxU32 eventMask = SRV_BT_CM_EVENT_CONNECT_RES |
        SRV_BT_CM_EVENT_DISCONNECT_IND |
        SRV_BT_CM_EVENT_RELEASE_ALL_CONN |
        SRV_BT_CM_EVENT_PAIR_RES |
        SRV_BT_CM_EVENT_INQUIRY_IND | 
        SRV_BT_CM_EVENT_INQUIRY_COMPLETE; // SRV_BT_CM_EVENT_PAIR_RES:for update device name

	setNotifyEvents(eventMask);
	m_recentUsedDevNum = (VfxU32)srv_bt_cm_get_dev_num(SRV_BT_CM_RECENT_USED_DEV);

	strId = STR_GLOBAL_SEARCH;
	imageId = IMG_ID_VAPP_BT_DEV_SEARCHING;
	bottomButId	 = VAPP_BT_SEL_DEV_PAGE_BOTTOM_SEARCH_BUT_ID;
	
    if (m_recentUsedDevNum > 0)
    {
		m_devType = SRV_BT_CM_RECENT_USED_DEV;

        for (VfxU32 i = 0; i < m_recentUsedDevNum; i++)
        {
            const srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_dev_info_by_index(
                i, SRV_BT_CM_RECENT_USED_DEV);
            if (dev_info)
            {
                memcpy(
                    &m_recentUsedDev[i],
                    dev_info,
                    sizeof(srv_bt_cm_dev_struct));
            }
        }
    }
    else
    {
		m_devType = SRV_BT_CM_DISCOVERED_DEV;

		if (srv_bt_cm_search(
				SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST,
				60,
				((VappBtSelDevCui*)getApp())->getSelDevCodMask(),
				MMI_TRUE) ==
			SRV_BT_CM_RESULT_SUCCESS)
		{
			strId = STR_ID_VAPP_BT_STOP_SEARCH;
			imageId = IMG_ID_VAPP_BT_DEV_SEARCH_STOP;
			bottomButId  = VAPP_BT_SEL_DEV_PAGE_BOTTOM_STOP_BUT_ID;
			strId2 = STR_GLOBAL_SEARCHING;
			m_isSearching = VFX_TRUE;
		}
    }
	m_btSelDevPageTitleBar->setTitle(VFX_WSTR_RES(strId2));
	m_btSelDevPageBBar->addItem(bottomButId, VFX_WSTR_RES(strId), imageId);
	m_btSelDevPageBBar->m_signalButtonTap.connect(this, &VappBtSelDevPage::onSearch);
}


void VappBtSelDevPage::onDeinit()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSELDEVPAGE_ONDEINIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if (m_isSearching)
    {
        srv_bt_cm_search_abort();
    }
	VFX_FREE_MEM(m_selectDevInfo);
    VappBTPageBase::onDeinit();
}

void VappBtSelDevPage::onBack()
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSELDEVPAGEONBACK);
#endif  // __VAPP_BT_DEBUG_INTENAL__
	
	((VappBtSelDevCui*)getApp())->sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);

    //VfxAppLauncher::terminate(getMainScr()->getGroupId());
    VfxPage::onBack();
}


void VappBtSelDevPage::onSearch(VfxObject* obj, VfxId id)
{
	VfxResId strId,strId2, imageId;
		
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSELDEVPAGE_ONSEARCH);
#endif  // __VAPP_BT_DEBUG_INTENAL__

	if(VAPP_BT_SEL_DEV_PAGE_BOTTOM_SEARCH_BUT_ID == id)
	{
	    if (srv_bt_cm_search(
	            SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST,
	            60, //VAPP_BT_INQUIRY_TIMEOUT_DURATION,
	            ((VappBtSelDevCui*)getApp())->getSelDevCodMask(),
	            MMI_TRUE) ==
	        SRV_BT_CM_RESULT_SUCCESS)
	    {
	 		m_btSelDevPageBBar->removeItem(id);
			strId2 = STR_GLOBAL_SEARCHING;
			strId = STR_ID_VAPP_BT_STOP_SEARCH;
			imageId = IMG_ID_VAPP_BT_DEV_SEARCH_STOP;
			m_isSearching = VFX_TRUE;
    		updateDevList(SRV_BT_CM_DISCOVERED_DEV);
	    }
	    else
	    {
			popupBalloonMsg(STR_ID_VAPP_BT_NOT_AVAILABLE);
			return;
	    }
	}
	else
	{
	 	m_btSelDevPageBBar->removeItem(id);
		srv_bt_cm_search_abort();
		m_isSearching = VFX_FALSE;
		strId2 = STR_ID_VAPP_BT_DEVICE_FOUND;
		strId = STR_ID_VAPP_BT_RESEARCH;
		imageId = IMG_ID_VAPP_BT_DEV_SEARCHING;

		//update list.
		updateDevList(SRV_BT_CM_DISCOVERED_DEV);
	}
    m_btSelDevPageBBar->addItem(VAPP_BT_SEL_DEV_PAGE_BOTTOM_BUT_ID_TOtAL - id, VFX_WSTR_RES(strId), imageId);
	m_btSelDevPageTitleBar->setTitle(VFX_WSTR_RES(strId2));
}


/*---------------------------------------------------------------------------*
 * Function: getDevInfoByIndex()
 * Description: get the dev info by the index.
 *    @return: return the dev information.
 *---------------------------------------------------------------------------*/
const srv_bt_cm_dev_struct* VappBtSelDevPage::getDevInfoByIndex(U32 index)
{
    VFX_LOG_FUNC;
//local var:
	const srv_bt_cm_dev_struct* devInfo;
//func implementation:
	if(SRV_BT_CM_RECENT_USED_DEV == m_devType)
	{
		devInfo = &m_recentUsedDev[index];		
	}
	else
	{
		devInfo = VappBTPageBase::getDevInfoByIndex(index);
	}
	return devInfo;
}

/*---------------------------------------------------------------------------*
 * Function: onClickedDev()
 * Description: virtual function from VappBTPageBase, call back when a dev in the list being clicked.
 *---------------------------------------------------------------------------*/
void VappBtSelDevPage::onClickedDev(VfxU32 index, const srv_bt_cm_dev_struct* dev_Info)
{
    VFX_LOG_FUNC;
//local var:
    cui_bt_select_device_result evt;
	
//func implementation:
	if(m_isSearching)
	{
		//save the dev info, and post to caller when recieve SRV_BT_CM_EVENT_INQUIRY_COMPLETE event.
		if(!m_selectDevInfo)
		{
			VFX_ALLOC_MEM(m_selectDevInfo, sizeof(srv_bt_cm_dev_struct), this);
		}
	    memcpy(
	        m_selectDevInfo,
	        dev_Info,
	        sizeof(srv_bt_cm_dev_struct));

		//stop it.
		srv_bt_cm_search_abort();
	}
	else
	{
	    MMI_FRM_INIT_GROUP_EVENT(
	        (cui_bt_select_device_result*)&evt,
	        EVT_ID_GROUP_CUI_BT_SELECT_DEVICE,
	        getMainScr()->getGroupId());
	    evt.result = VFX_TRUE;
	    evt.cui_id = VappBtSelDevCui::m_btSelDevCuiId;
	    memcpy(
	        &evt.dev_info,
	        dev_Info,
	        sizeof(srv_bt_cm_dev_struct));
	    ((VappBtSelDevCui*)getApp())->postToCaller((mmi_group_event_struct*)&evt, VFX_CALLBACK_NULL);
	}
}

VfxBool VappBtSelDevPage::isSearching()
{
    return m_isSearching;
}


/*---------------------------------------------------------------------------*
 * Function: handleBtEvents()
 * Description: virtual function from VappBTPageBase, call back when a BT event arised.
 *	  @event: the event Id.
 *---------------------------------------------------------------------------*/
void VappBtSelDevPage::handleBtEvents(VfxU32 event, void* para)
{
//local var:
	
//func implementation:
#ifdef __VAPP_BT_DEBUG_INTENAL__
		MMI_TRACE(
			MMI_CONN_TRC_G7_BT,
			MMI_VAPPBTSELDEVPAGE_HANDLEBTENENTS,
			event);
#endif  // __VAPP_BT_DEBUG_INTENAL__
    switch (event)
    {
        case SRV_BT_CM_EVENT_INQUIRY_COMPLETE:
			if(m_isSearching)
			{
				if(m_selectDevInfo)
				{
					cui_bt_select_device_result evt;
					MMI_FRM_INIT_GROUP_EVENT(
				        (cui_bt_select_device_result*)&evt,
				        EVT_ID_GROUP_CUI_BT_SELECT_DEVICE,
				        getMainScr()->getGroupId());
					    evt.result = VFX_TRUE;
					    evt.cui_id = VappBtSelDevCui::m_btSelDevCuiId;
					memcpy(
				        &evt.dev_info,
				        m_selectDevInfo,
				        sizeof(srv_bt_cm_dev_struct));
				    ((VappBtSelDevCui*)getApp())->postToCaller((mmi_group_event_struct*)&evt, VFX_CALLBACK_NULL);
						return;
				}
			m_isSearching = VFX_FALSE;
            m_btSelDevPageTitleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BT_DEVICE_FOUND));
            m_btSelDevPageBBar->removeItem(VAPP_BT_SEL_DEV_PAGE_BOTTOM_STOP_BUT_ID);
            m_btSelDevPageBBar->addItem(VAPP_BT_SEL_DEV_PAGE_BOTTOM_SEARCH_BUT_ID, VFX_WSTR_RES(STR_ID_VAPP_BT_RESEARCH), IMG_ID_VAPP_BT_DEV_SEARCHING);
            }
            break;
        case SRV_BT_CM_EVENT_INQUIRY_IND:
			if(!m_isSearching)
			{
				break;
			}
        case SRV_BT_CM_EVENT_CONNECT_RES:
        case SRV_BT_CM_EVENT_DISCONNECT_IND:
        case SRV_BT_CM_EVENT_RELEASE_ALL_CONN:
        case SRV_BT_CM_EVENT_PAIR_RES:
            m_btDevListMenu->resetAllItems();
            break;  
        default:
            break;
    }
    
}

/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Description: the count of dev list.
 *    @return: return the dev list count.
 *---------------------------------------------------------------------------*/
VfxU32 VappBtSelDevPage::getCount() const
{
	VFX_LOG_FUNC1("return: %d", srv_bt_cm_get_dev_num(m_devType));
//local var:
	
//func implementation:
	if(SRV_BT_CM_RECENT_USED_DEV == m_devType)
	{
        return m_recentUsedDevNum;
	}
	else
		return VappBTPageBase::getCount();
}

/*---------------------------------------------------------------------------*
 * Function: getMenuEmptyText()
 * Description: get text when the dev list is empty.
 *    @return: VFX_TRUE if success.
 *---------------------------------------------------------------------------*/
VfxBool VappBtSelDevPage::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
    if (!m_isSearching)
    {
        text = VFX_WSTR_RES(STR_ID_VAPP_BT_NO_DEV_FOUND);
    }
    else
    {
        text = VFX_WSTR("");
    }

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}

VFX_IMPLEMENT_CLASS("VappBtSelDevCui", VappBtSelDevCui, VfxApp);
VfxU32 VappBtSelDevCui::m_btSelDevCuiRefCnt = 0;
mmi_id VappBtSelDevCui::m_btSelDevCuiId = GRP_ID_INVALID;

void VappBtSelDevCui::onInit()
{
    VfxCui::onInit();
	m_btPowerOnScrcmSrvHd = 0;
    ++VappBtSelDevCui::m_btSelDevCuiRefCnt;
}


void VappBtSelDevCui::onDeinit()
{
    --VappBtSelDevCui::m_btSelDevCuiRefCnt;
    VappBtSelDevCui::m_btSelDevCuiId = GRP_ID_INVALID;
	if(m_btPowerOnScrcmSrvHd > 0)
	{
		srv_bt_cm_reset_notify(m_btPowerOnScrcmSrvHd);
		m_btPowerOnScrcmSrvHd = 0;
	}
    VfxCui::onDeinit();
}


void VappBtSelDevCui::onRun(void *args, VfxU32 argSize)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSELDEVCUI_ONRUN,
        VappBtSelDevCui::m_btSelDevCuiRefCnt);
#endif  // __VAPP_BT_DEBUG_INTENAL__
	VfxCui::onRun(args, argSize);

    cui_bt_select_device_struct* para = (cui_bt_select_device_struct*)args;
	m_btSelDevCuiCodMask = para->cod_mask;
	

    // waiting for the CUI event, then create the mainscreen
    if (srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF)
    {
		m_btPowerOnScrcmSrvHd = srv_bt_cm_set_notify(
			&VappBtSelDevCui::btPowerOnEventHandle,
			SRV_BT_CM_EVENT_ACTIVATE | SRV_BT_CM_EVENT_DEACTIVATE,
			getObjHandle());
		if (m_btPowerOnScrcmSrvHd > 0)
		{
    		VFX_OBJ_CREATE(m_smallScr, VappBTSmallScr, this);
			
				VfxResId strId;
				VcpConfirmPopup* confirmPopup;
				VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, m_smallScr);
				confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
				if (!srv_mode_switch_is_network_service_available())
				{
					strId = STR_ID_VAPP_BT_IN_FLIGHT_MODE_ASK;
				}
				else
				{
					strId = STR_ID_VAPP_BT_POWER_ON_BLUETOOTH_FIRST;
				}
				confirmPopup->setText(VFX_WSTR_RES(strId));
			
				confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
				confirmPopup->setCustomButton(
					VFX_WSTR_RES(STR_GLOBAL_YES),
					VFX_WSTR_RES(STR_GLOBAL_NO),
					VCP_POPUP_BUTTON_TYPE_NORMAL,
					VCP_POPUP_BUTTON_TYPE_CANCEL);
				confirmPopup->m_signalButtonClicked.connect(this, &VappBtSelDevCui::onButtonClick);
				confirmPopup->show(VFX_TRUE);
				m_smallScr->show();
		}
		else
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR *)GetString(STR_ID_VAPP_BT_NOT_AVAILABLE)
				);
			sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);
        }
    }
    else
    {
		m_btPowerOnScrcmSrvHd = srv_bt_cm_set_notify(
			&VappBtSelDevCui::btPowerOnEventHandle,
			SRV_BT_CM_EVENT_DEACTIVATE,
			getObjHandle());
		if(m_btPowerOnScrcmSrvHd > 0)
		{
		    VfxMainScr* btSelDevCuiScr;
	        VFX_OBJ_CREATE(btSelDevCuiScr, VfxMainScr, this);
		    addPageToScr(btSelDevCuiScr);
	        btSelDevCuiScr->show();
		}
		else
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR *)GetString(STR_ID_VAPP_BT_NOT_AVAILABLE)
				);
			sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);
        }
    }
}

/*---------------------------------------------------------------------------*
 * Function: onButtonClick()
 * Description: call back when user clicked confirm form button. 
 *---------------------------------------------------------------------------*/
void VappBtSelDevCui::onButtonClick(VfxObject* sender, VfxU32 id)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		MMI_VAPPBTDEVCUI_ONBUTTONCLICK,
		id);
#endif  // __VAPP_BT_DEBUG_INTENAL__

	switch (id)
	{
		case VCP_CONFIRM_POPUP_BUTTON_YES:
			{
			    VcpIndicatorPopup* indicatorPopup;
			    VFX_OBJ_CREATE(indicatorPopup, VcpIndicatorPopup, m_smallScr);
			    indicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
			    indicatorPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_BT_PLEASE_WAIT));
			    indicatorPopup->show(VFX_TRUE);
				srv_bt_cm_switch_on();
			}
			break;
			
		case VCP_CONFIRM_POPUP_BUTTON_NO:
		case VCP_POPUP_BUTTON_NO_PRESSED:
		default:
			
			sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);
			break;
	}
}

/*---------------------------------------------------------------------------*
 * Function: btPowerOnEventHandle()
 * Description: handle the bt call back event.
 *---------------------------------------------------------------------------*/
void VappBtSelDevCui::btPowerOnEventHandle(VfxU32 event, void* para)
{
//local var:
	srv_bt_cm_activate_struct* res;
	VappBtSelDevCui* self;
	
//func implementation:
	res = (srv_bt_cm_activate_struct*)para;
	self = (VappBtSelDevCui*)VfxObject::handleToObject(res->user_data);
	if(!self)
	{
		return;
	}
    if (SRV_BT_CM_EVENT_ACTIVATE == event)
    {
		srv_bt_cm_reset_notify(self->m_btPowerOnScrcmSrvHd);
		
		self->m_btPowerOnScrcmSrvHd = srv_bt_cm_set_notify(
			&VappBtSelDevCui::btPowerOnEventHandle,
			SRV_BT_CM_EVENT_DEACTIVATE,
			res->user_data);
		if(self->m_btPowerOnScrcmSrvHd>0)
		{
	        VfxMainScr* btSelDevCuiScr;
	        VFX_OBJ_CREATE(btSelDevCuiScr, VfxMainScr, self);
			self->addPageToScr(btSelDevCuiScr);
	        btSelDevCuiScr->show();
			self->m_smallScr->exit();
		}
		else
		{
			mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR *)GetString(STR_ID_VAPP_BT_NOT_AVAILABLE)
				);
			self->sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);
		}
    }
	else if(SRV_BT_CM_EVENT_DEACTIVATE == event)
	{
		vapp_ncenter_disable_leave();
		self->sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);
		self->exit();
	}
}

/*---------------------------------------------------------------------------*
 * Function: onScrBack()
 * Description: virtual function from VfxApp,
 *    When receiving the BACK key in the screen, the function will be invoked.
 *    @return:
 *---------------------------------------------------------------------------*/
VfxBool VappBtSelDevCui::onScrBack(VfxAppScr *scr)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
    sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);
	return VfxApp::onScrBack(scr);
}

/*---------------------------------------------------------------------------*
 * Function: addPageToScr()
 * Description: add VappBtSelDevPage to screen.
 *---------------------------------------------------------------------------*/
void VappBtSelDevCui::addPageToScr(VfxMainScr *scr)
{
//local var:
	VappBtSelDevPage* btSelDevScrPage;
//func implementation:

#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSELDEVSCREEN_ON1STREADY);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    VFX_OBJ_CREATE(btSelDevScrPage, VappBtSelDevPage, scr);
    scr->pushPage(1, btSelDevScrPage);
}

/*---------------------------------------------------------------------------*
 * Function: sendMsgToCaller()
 * Description: Duplicate codes.
 *---------------------------------------------------------------------------*/
void VappBtSelDevCui::sendMsgToCaller(VfxBool aResult, VfxAppPostToCallerCb aCb)
{
	VFX_LOG_FUNC;
//local var:
	cui_bt_select_device_result evt;

//func implementation:
	MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_GROUP_CUI_BT_SELECT_DEVICE, getGroupId());
	evt.result = aResult;
	evt.cui_id = VappBtSelDevCui::m_btSelDevCuiId;
	postToCaller((mmi_group_event_struct*)&evt, aCb);
}

VfxU32 VappBtSelDevCui::getSelDevCodMask()
{
    return m_btSelDevCuiCodMask;
}


VfxBool VappBtSelDevCui::btSelDevPreCheck(void)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTSELDEVCUI_BTSELDEVPRECHECK,
        VappBtSelDevCui::m_btSelDevCuiRefCnt);
#endif  // __VAPP_BT_DEBUG_INTENAL__

#ifdef __BT_AUTO_DETECT_SUPPORT__
    if (srv_bt_chip_available() && VappBtSelDevCui::m_btSelDevCuiRefCnt == 0)
#else
    if (VappBtSelDevCui::m_btSelDevCuiRefCnt == 0)
#endif
    {
        if (VappBtCm::getInitPowerStatus())
        {
            switch (srv_bt_cm_get_power_status())
            {
                case SRV_BT_CM_POWER_OFF:
                case SRV_BT_CM_POWER_ON:
                    return VFX_TRUE;
            }
        }
    }

    return VFX_FALSE;
}


VfxAppCloseAnswerEnum VappBtSelDevCui::onProcessClose(VfxAppCloseOption options)
{
	sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);

    return VFX_APP_CLOSE_ANSWER_YES;
}


mmi_ret VappBtSelDevCui::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_CUI_BT_POWER_ON:
            cui_bt_power_on_result* para = (cui_bt_power_on_result*)evt;

            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                MMI_VAPPBTSELDEVCUI_ONPROC,
                para->result);

            vcui_bt_power_on_close(para->cui_id);
            if (para->result)
            {
			    VfxMainScr* btSelDevCuiScr;
                VFX_OBJ_CREATE(btSelDevCuiScr, VfxMainScr, this);
			    addPageToScr(btSelDevCuiScr);
                btSelDevCuiScr->show();
            }
            else
            {
				sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);

                //VfxAppLauncher::terminate(getGroupId());
            }
            break;
    }

    return MMI_RET_OK;
}



extern "C"
{
    mmi_id vcui_bt_select_device_create(mmi_id appId, cui_bt_select_device_struct* para)
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            MMI_VCUI_BT_SELECT_DEVICE,
            appId,
            para->cod_mask,
            para->service_id);
#endif  // __VAPP_BT_DEBUG_INTENAL__

        if (VappBtSelDevCui::btSelDevPreCheck())
        {
            VappBtSelDevCui::m_btSelDevCuiId = VfxAppLauncher::createCui(
                VCUI_BT_SELDEV,
                VFX_OBJ_CLASS_INFO(VappBtSelDevCui),
                appId,
                (void*)para,
                sizeof(cui_bt_select_device_struct*));

            return VappBtSelDevCui::m_btSelDevCuiId;
        }

        return GRP_ID_INVALID;
    }

    void vcui_bt_select_device_run(mmi_id cui_id)
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            VCUI_BT_SELECT_DEVICE_RUN,
            cui_id,
            VappBtSelDevCui::m_btSelDevCuiId);
#endif  // __VAPP_BT_DEBUG_INTENAL__

        VfxAppLauncher::runCui(cui_id);
    }
    

    void vcui_bt_select_device_close(mmi_id cui_id)
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            VCUI_BT_SELECT_DEVICE_CLOSE,
            cui_id,
            VappBtSelDevCui::m_btSelDevCuiId);
#endif  // __VAPP_BT_DEBUG_INTENAL__

        VfxAppLauncher::terminate(cui_id);
    }
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
extern "C"
VfxBool vcui_bt_power_on(mmi_id appId, cui_bt_power_on_struct* para)
{
    return VFX_FALSE;
}


extern "C"
mmi_id vcui_bt_power_on_create(mmi_id appId, cui_bt_power_on_struct* para)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        VCUI_BT_POWER_ON_CREATE,
        appId,
        para->confirm_type);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if (VappBtPowerOnCui::m_btPowerOnCuiId != GRP_ID_INVALID)
    {
        return GRP_ID_INVALID;
    }

#ifdef __BT_AUTO_DETECT_SUPPORT__
    if ((srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF) &&
        srv_bt_chip_available())
#else
        if ((srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_OFF))
#endif
    {
        VappBtPowerOnCui::m_btPowerOnCuiId = VfxAppLauncher::createCui(
            VCUI_BT_POWERON,
            VFX_OBJ_CLASS_INFO(VappBtPowerOnCui),
            appId,
            (void*)para,
            sizeof(cui_bt_power_on_struct*));

        return VappBtPowerOnCui::m_btPowerOnCuiId;
    }

    return GRP_ID_INVALID;
}

extern "C"
void vcui_bt_power_on_run(mmi_id cui_id)
{
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        VCUI_BT_POWER_ON_RUN,
        cui_id);

    VfxAppLauncher::runCui(cui_id);
}

extern "C"
void vcui_bt_power_on_close(mmi_id cui_id)
{
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        VCUI_BT_POWER_ON_CLOSE,
        cui_id);

    VfxAppLauncher::terminate(cui_id);
}

VFX_IMPLEMENT_CLASS("VappBtPowerOnCui", VappBtPowerOnCui, VfxApp);
void VappBtPowerOnCui::onRun(void* args, VfxU32 argSize)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTPOWERONCUI_ONRUN);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    VfxCui::onRun(args, argSize);
    cui_bt_power_on_struct* para = (cui_bt_power_on_struct*)args;

	m_btPowerOnScrcmSrvHd = srv_bt_cm_set_notify(
        &VappBtPowerOnCui::btPowerOnEventHandle,
        SRV_BT_CM_EVENT_ACTIVATE,
        getObjHandle());
    if (m_btPowerOnScrcmSrvHd > 0)
    {
		
	    VFX_OBJ_CREATE(m_smallScr, VappBTSmallScr, this);
		
        switch (para->confirm_type)
        {
	        case CUI_BT_POWER_ON_WITH_FLIGHT_MODE_CONFIRM_ONLY:
	            if (!srv_mode_switch_is_network_service_available())              // ZHY: if in flight mode
	            {
					break;
	            }
			case CUI_BT_POWER_ON_WITHOUT_CONFIRM:
				showIndictorPopup();
				srv_bt_cm_switch_on();
				return;

	        case CUI_BT_POWER_ON_WITH_ALL_CONFIRM:
	            break;
        }
		showConfirmScreen();
		m_smallScr->show();
    }
    else
    {
	    sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);
        //VfxAppLauncher::terminate(getGroupId());
    }
}


/*---------------------------------------------------------------------------*
 * Function: btPowerOnEventHandle()
 * Description: handle the bt call back event.
 *---------------------------------------------------------------------------*/
void VappBtPowerOnCui::btPowerOnEventHandle(U32 event, void* para)
{
//local var:
	srv_bt_cm_activate_struct* res;
	VappBtPowerOnCui* self;
	
//func implementation:
	res = (srv_bt_cm_activate_struct*)para;
	self = (VappBtPowerOnCui*)VfxObject::handleToObject(res->user_data);
    if (self && SRV_BT_CM_EVENT_ACTIVATE == event)
    {
        self->sendMsgToCaller(!(!(res->result)),VFX_CALLBACK_NULL);
    }
}

/*---------------------------------------------------------------------------*
 * Function: showIndictorPopup()
 * Description: show indictor popup
 *---------------------------------------------------------------------------*/
void VappBtPowerOnCui::showIndictorPopup(void)
{
    VFX_LOG_FUNC;
//local var:
    VcpIndicatorPopup* indicatorPopup;
	
//func implementation:
    VFX_OBJ_CREATE(indicatorPopup, VcpIndicatorPopup, m_smallScr);
    indicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    indicatorPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_BT_PLEASE_WAIT));
    indicatorPopup->show(VFX_TRUE);
}

/*---------------------------------------------------------------------------*
 * Function: showConfirmScreen()
 * Description: show globle popup to get user's choice.
 *---------------------------------------------------------------------------*/
void VappBtPowerOnCui::showConfirmScreen(void)
{
#ifdef __MMI_BT_IN_FLIGHT_MODE__
    VFX_LOG_FUNC;
//local var:
	VfxResId strId;
	VcpConfirmPopup* confirmPopup;

//func implementation:
	VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, m_smallScr);
	confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
	if (!srv_mode_switch_is_network_service_available())
	{
		strId = STR_ID_VAPP_BT_IN_FLIGHT_MODE_ASK;
	}
	else
	{
		strId = STR_ID_VAPP_BT_POWER_ON_BLUETOOTH_FIRST;
	}
	confirmPopup->setText(VFX_WSTR_RES(strId));

	confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
	confirmPopup->setCustomButton(
		VFX_WSTR_RES(STR_GLOBAL_YES),
		VFX_WSTR_RES(STR_GLOBAL_NO),
		VCP_POPUP_BUTTON_TYPE_NORMAL,
		VCP_POPUP_BUTTON_TYPE_CANCEL);
	confirmPopup->m_signalButtonClicked.connect(this, &VappBtPowerOnCui::onButtonClick);
	confirmPopup->show(VFX_TRUE);
#endif //__MMI_BT_IN_FLIGHT_MODE__
}


/*---------------------------------------------------------------------------*
 * Function: onButtonClick()
 * Description: call back when user clicked confirm form button. 
 *---------------------------------------------------------------------------*/
void VappBtPowerOnCui::onButtonClick(VfxObject* sender, VfxU32 id)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		MMI_VAPPPOWERONCUI_ONBUTTONCLICK,
		id);
#endif  // __VAPP_BT_DEBUG_INTENAL__

	switch (id)
	{
		case VCP_CONFIRM_POPUP_BUTTON_YES:
			showIndictorPopup();
			srv_bt_cm_switch_on();
			break;
			
		case VCP_CONFIRM_POPUP_BUTTON_NO:
		case VCP_POPUP_BUTTON_NO_PRESSED:
		default:
			sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);
			break;
	}
}


/*---------------------------------------------------------------------------*
 * Function: sendMsgToCaller()
 * Description: Duplicate codes.
 *---------------------------------------------------------------------------*/
void VappBtPowerOnCui::sendMsgToCaller(VfxBool aResult, VfxAppPostToCallerCb aCb)
{
    VFX_LOG_FUNC;
//local var:
    cui_bt_power_on_result evt;

//func implementation:
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_GROUP_CUI_BT_POWER_ON, getGroupId());
    evt.cui_id = VappBtPowerOnCui::m_btPowerOnCuiId;
    evt.result = aResult;
    postToCaller((mmi_group_event_struct*)&evt, aCb);
}

VfxAppCloseAnswerEnum VappBtPowerOnCui::onProcessClose(VfxAppCloseOption options)
{
	sendMsgToCaller(VFX_FALSE, VFX_CALLBACK_NULL);
    return VFX_APP_CLOSE_ANSWER_YES;
}


void VappBtPowerOnCui::onDeinit()
{
    if (m_btPowerOnScrcmSrvHd > 0)
    {
        srv_bt_cm_reset_notify(m_btPowerOnScrcmSrvHd);
    }
    VappBtPowerOnCui::m_btPowerOnCuiId = GRP_ID_INVALID;
    VfxCui::onDeinit();
}
#endif  // __MMI_BT_SUPPORT__
