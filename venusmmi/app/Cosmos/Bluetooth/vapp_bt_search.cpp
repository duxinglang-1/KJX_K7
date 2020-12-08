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
 *  vapp_bt_search.cpp
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
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

extern "C" {
#include "MMI_features.h" 
}

#ifdef __MMI_BT_SUPPORT__
extern "C" {
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "Conversions.h"
#include "MMI_conn_app_trc.h"
}

#include "vcp_indicator_popup.h" // for VcpIndicatorPopup
#include "vcp_navi_title_bar.h" // for VcpTitleBar
#include "vcp_tool_bar.h" // for VcpToolBar

#include "mmi_rp_vapp_bt_main_def.h"
#include "vapp_bt_search.h"
#include "vapp_bt_main.h"
#include "vapp_bt_device.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_BT_STOP_SEARCHING_BUTTON     1
#define VAPP_BT_RESEARCHING_BUTTON     2
#if 0
/* under construction !*/
#else
#define VFX_LOG_FUNC
#define VFX_LOG_FUNC1(fmt, p1)
#define VFX_LOG_FUNC2(fmt, p1, p2)
#define VFX_LOG_STATIC_FUNC
#define VFX_LOG_STATIC_FUNC1(fmt, p1)
#define VFX_LOG_STATIC_FUNC2(fmt, p1, p2)
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
 

/***************************************************************************** 
 * Function
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappBTSearchDevPage", VappBTSearchDevPage, VfxPage);

void VappBTSearchDevPage::onDeinit()
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SEARCH_DESTRUCT, m_state);
    if (m_state == VBT_SCH_STATE_SEARCHING)
    {
        srv_bt_cm_search_abort();
    }
    VappBTPageBase::onDeinit();
}

void VappBTSearchDevPage::onInit()
{
	VappBTPageBase::onInit();
	m_pairIndex = -1;
	initDevLis();
	VfxU32 event_mask = SRV_BT_CM_EVENT_INQUIRY_IND |
						SRV_BT_CM_EVENT_INQUIRY_COMPLETE |
						SRV_BT_CM_EVENT_BOND_RES|
						SRV_BT_CM_EVENT_PAIR_RES |
						SRV_BT_CM_EVENT_CONNECT_RES |
						SRV_BT_CM_EVENT_DISCONNECT_IND;
	setNotifyEvents(event_mask);
    m_state = VBT_SCH_STATE_SEARCHING;
	
	VFX_OBJ_CREATE(m_schTitle,VcpTitleBar,this);
	m_schTitle->setTitle(VFX_WSTR_RES(STR_GLOBAL_SEARCHING));
	setTopBar(m_schTitle);

    setBottombar();
    
}

/*---------------------------------------------------------------------------*
 * Function: onClickedDev()
 * Description: virtual function from VappBTPageBase, call back when a dev in the list being clicked.
 *---------------------------------------------------------------------------*/
void VappBTSearchDevPage::onClickedDev(VfxU32 index, const srv_bt_cm_dev_struct* dev_Info)
{
    VFX_LOG_FUNC;
//local var:

//func implementation:
	if (m_state == VBT_SCH_STATE_PAIRING)
    {
		popupBalloonMsg(STR_ID_VAPP_BT_NOT_AVAILABLE);
		return;
    }
	
    U8 paired_num = srv_bt_cm_get_paired_dev_num();
    if (paired_num == SRV_BT_CM_MAX_PAIRED_DEVICE_LIST &&
		!srv_bt_cm_get_dev_info_by_addr(&(dev_Info->bd_addr), SRV_BT_CM_PAIRED_DEV))
    {
		srv_bt_cm_search_abort();
		m_pairIndex = -1;
		popupBalloonMsg(STR_ID_VAPP_BT_PAIRED_DEV_FULL);
        return;
    }
	if (m_state == VBT_SCH_STATE_SEARCHING)
    {
		srv_bt_cm_search_abort();
		m_pairIndex = index;		
    }
	else
	{
	    pairDev(index);
	}
}


/*---------------------------------------------------------------------------*
 * Function: handleBtEvents()
 * Description: virtual function from VappBTPageBase, call back when a BT event arised.
 *---------------------------------------------------------------------------*/
void VappBTSearchDevPage::handleBtEvents(VfxU32 event, void* para)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
	switch(event)
	{
		case SRV_BT_CM_EVENT_BOND_RES:
			bondResult(para);
			break;
			
		case SRV_BT_CM_EVENT_PAIR_RES:
			pairResult(para);
			break;
			
		case SRV_BT_CM_EVENT_INQUIRY_COMPLETE:
			searchComplete(para);
			if(m_pairIndex >= 0)
			{
				pairDev(m_pairIndex);
				m_pairIndex = -1;
			}
			//break; //remove break, to update list.
		case SRV_BT_CM_EVENT_INQUIRY_IND:
		case SRV_BT_CM_EVENT_CONNECT_RES:
		case SRV_BT_CM_EVENT_DISCONNECT_IND:
			updateDevList(SRV_BT_CM_DISCOVERED_DEV);
			break;
		default:
			break;
	}
}

void VappBTSearchDevPage::searchComplete(void *para)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SEARCH_COMPLETE, m_state);
    //srv_bt_cm_inquiry_complete_struct *event = (srv_bt_cm_inquiry_complete_struct *)para;
    m_state = VBT_SCH_STATE_IDLE;
    m_schTitle->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BT_DEVICE_FOUND));

    m_bottomBar->removeItem(VAPP_BT_STOP_SEARCHING_BUTTON);
    m_bottomBar->addItem(VAPP_BT_RESEARCHING_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_BT_RESEARCH), IMG_ID_VAPP_BT_DEV_SEARCHING);
        
    m_bottomBar->m_signalButtonTap.connect(this, &VappBTSearchDevPage::onResearchingBarClick);
    //setBottomBar(m_bottomBar);
}

#ifdef __MMI_BT_AUTHORIZE__
/*---------------------------------------------------------------------------*
 * Function: onAlwayConnBarClick()
 * Description: slot function, call back when user clicked "always connect bar".
 *---------------------------------------------------------------------------*/
void VappBTSearchDevPage::onAlwayConnBarClick(VfxObject* sender, VfxId chosen)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
	if (chosen == VCP_CONFIRM_POPUP_BUTTON_YES) /*press Yes*/
	{
		if (srv_bt_cm_set_authorize(&m_bondDevAddr, SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT) != SRV_BT_CM_RESULT_SUCCESS)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_INFO,
				(WCHAR *)GetString(STR_ID_VAPP_BT_NOT_AVAILABLE)
				);
		}
	}
	getMainScr()->popPage();	
}
#endif  // __MMI_BT_AUTHORIZE__

void VappBTSearchDevPage::bondResult(void *para)
{
    srv_bt_cm_bond_res_struct *event = (srv_bt_cm_bond_res_struct *)para;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SEARCH_BOND_RESULT, event->result, m_firstPair);
    m_state = VBT_SCH_STATE_IDLE;
    //VFX_OBJ_CLOSE(m_pairingPopup);
    if (m_pairingPopup != NULL)
    {
        m_pairingPopup->exit(VFX_TRUE);
        m_pairingPopup = NULL;
    }

    if (event->result == SRV_BT_CM_RESULT_SUCCESS)
    {
#ifdef __MMI_BT_AUTHORIZE__
        if (m_firstPair == VFX_TRUE)
        {
			m_bondDevAddr = event->dev_addr;
            VcpConfirmPopup *alwayConn;
        	VFX_OBJ_CREATE(alwayConn, VcpConfirmPopup,getMainScr());
            
            VfxWString text(VFX_WSTR_RES(STR_ID_VAPP_BT_PAIR_SUCESS));
            text += VFX_WSTR_RES(STR_ID_VAPP_BT_AUTHORIZE_ASK);
    
        	alwayConn->setText(text);
        	alwayConn->setInfoType(VCP_POPUP_TYPE_QUESTION);
        	alwayConn->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
            alwayConn->setCustomButton(
                VFX_WSTR_RES(STR_GLOBAL_YES),
                VFX_WSTR_RES(STR_GLOBAL_NO),
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            //alwayConn->setAutoDestory(VFX_FALSE);

        	alwayConn->m_signalButtonClicked.connect(this, &VappBTSearchDevPage::onAlwayConnBarClick);
        	alwayConn->show(VFX_TRUE);
        }
        else
#endif  // __MMI_BT_AUTHORIZE__
        {
        	getMainScr()->popPage();
			popupBalloonMsg(STR_ID_VAPP_BT_PAIR_SUCESS);
        }

    }
    else
    {
        VcpConfirmPopup *pairFail;
    	VFX_OBJ_CREATE(pairFail, VcpConfirmPopup,getMainScr());
        
    	pairFail->setText(VFX_WSTR_RES(STR_ID_VAPP_BT_PAIR_FAILED));
    	pairFail->setInfoType(VCP_POPUP_TYPE_FAILURE);
        pairFail->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
		pairFail->show(VFX_TRUE);
    }
    
}


/*---------------------------------------------------------------------------*
 * Function: getMenuEmptyText()
 * Description: virtual function from IVcpListMenuContentProvider
 *    @return: VFX_TRUE if success.
 *---------------------------------------------------------------------------*/
VfxBool VappBTSearchDevPage::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
	if ((m_state == VBT_SCH_STATE_IDLE))
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

void VappBTSearchDevPage::pairResult(void *para)
{
    srv_bt_cm_pair_res_struct *event = (srv_bt_cm_pair_res_struct *)para;
    m_firstPair = VFX_FALSE;

    if (event->result == SRV_BT_CM_RESULT_SUCCESS)
    {
        if (m_initiatorPair == VFX_TRUE)
        {
            if (event->is_first_pair == MMI_TRUE)
            {
                m_firstPair = VFX_TRUE;
            } 
        }
	}
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SEARCH_PAIR_RESULT, event->result, m_firstPair, m_initiatorPair);
}

void VappBTSearchDevPage::onBack()
{
   getMainScr()->popPage();
}

void VappBTSearchDevPage::pairDev(VfxU32 index)
{
    m_initiatorPair = VFX_FALSE;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_SEARCH_PAIR_GO, index);
    
    if (srv_bt_cm_bond(index) == SRV_BT_CM_RESULT_SUCCESS)
    {
        m_initiatorPair = VFX_TRUE;
        m_state = VBT_SCH_STATE_PAIRING;
        
        VFX_OBJ_CREATE(m_pairingPopup, VcpIndicatorPopup, getMainScr());

        m_pairingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_pairingPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
    	m_pairingPopup->setAutoDestory(VFX_FALSE);
        //m_pairingPopup->m_signalCanceled.connect(this, &VappBTSearchDevPage::onPairCancelClick);
        //m_pairingPopup->m_signalButtonClicked.connect(this, &VappBTSearchDevPage::onPairBackClick);
        m_pairingPopup->show(VFX_TRUE);
    }
    else
    {
		popupBalloonMsg(STR_ID_VAPP_BT_NOT_AVAILABLE);
    }
}

void VappBTSearchDevPage::setBottombar()
{
	VFX_OBJ_CREATE(m_bottomBar, VcpToolBar, this);
	m_bottomBar->addItem(VAPP_BT_STOP_SEARCHING_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_BT_STOP_SEARCH), IMG_ID_VAPP_BT_DEV_SEARCH_STOP);
    
	m_bottomBar->m_signalButtonTap.connect(this, &VappBTSearchDevPage::onStopBarClick);
	setBottomBar(m_bottomBar);
}


void VappBTSearchDevPage::onStopBarClick(VfxObject* sender, VfxId Id)
{
	if (Id == VAPP_BT_STOP_SEARCHING_BUTTON)
	{
	    srv_bt_cm_search_abort();
        m_state = VBT_SCH_STATE_IDLE;
	    m_schTitle->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BT_DEVICE_FOUND));
        
        m_bottomBar->removeItem(VAPP_BT_STOP_SEARCHING_BUTTON);
        m_bottomBar->addItem(VAPP_BT_RESEARCHING_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_BT_RESEARCH), IMG_ID_VAPP_BT_DEV_SEARCHING);

        m_bottomBar->m_signalButtonTap.connect(this, &VappBTSearchDevPage::onResearchingBarClick);
	    //setBottomBar(m_bottomBar);   
	    m_pairIndex = -1;
	}
}

void VappBTSearchDevPage::onResearchingBarClick(VfxObject* sender, VfxId Id)
{
    if (Id == VAPP_BT_RESEARCHING_BUTTON)
    {
        if (srv_bt_cm_search(
                SRV_BT_CM_MAX_DISCOVERY_RESULTS_IN_LIST,
                MAX_INQUIRY_DURATION,
                SRV_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK,
                MMI_TRUE) == SRV_BT_CM_RESULT_SUCCESS)
        {
            
            m_state = VBT_SCH_STATE_SEARCHING;
            m_schTitle->setTitle(VFX_WSTR_RES(STR_GLOBAL_SEARCHING));

            m_bottomBar->removeItem(VAPP_BT_RESEARCHING_BUTTON);
            m_bottomBar->addItem(
                VAPP_BT_STOP_SEARCHING_BUTTON,
                VFX_WSTR_RES(STR_ID_VAPP_BT_STOP_SEARCH),
                IMG_ID_VAPP_BT_DEV_SEARCH_STOP);
            m_bottomBar->m_signalButtonTap.connect(this, &VappBTSearchDevPage::onStopBarClick);
            //setBottomBar(m_bottomBar);

            updateDevList(SRV_BT_CM_DISCOVERED_DEV);
        }
        else
        {
			popupBalloonMsg(STR_ID_VAPP_BT_NOT_AVAILABLE);
        }
    }
}

#endif // __MMI_BT_SUPPORT__

