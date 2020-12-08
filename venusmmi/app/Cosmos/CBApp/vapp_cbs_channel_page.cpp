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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Vapp_CBS_pages.cpp
 *
 * Project:
 * --------
 *  App CBS
 *
 * Description:
 * ------------
 *  Venus App CBS multi option screen implements for C++
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "vapp_cbs_iprot.h"
#include "vapp_cbs_channel_page.h"
#include "vapp_cbs_channel_editor_page.h"
#include "vapp_cbs_msgs_page.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vapp_sms_util.h"


/* channel list */

//VFX_IMPLEMENT_CLASS("VappCbsChannelListPage", VappCbsChannelListPage, VfxPage);
void VappCbsChannelListPage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_ADD_CHNL, channelChangeProc, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_DEL_CHNL, channelChangeProc, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_UPDATE_CHNL, channelChangeProc, this);
    VfxPage::onDeinit();
};

/*channel list page */
void VappCbsChannelListPage::onInit()
{	

	VfxPage::onInit();
	VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
	m_titleBar->setTitle((VfxResId)STR_ID_VAPP_CBS_MSG_LIST_NORMAL_TITLE);
    setTopBar(m_titleBar);

	VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
	m_toolBar->addItem(ADD, (VfxResId)(STR_GLOBAL_ADD), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
	m_toolBar->addItem(TO_DELETE, (VfxResId)(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	setBottomBar(m_toolBar);
	m_toolBar->m_signalButtonTap.connect(this, &VappCbsChannelListPage::onToolBarClick);
    
    mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_ADD_CHNL, channelChangeProc, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_DEL_CHNL, channelChangeProc, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_UPDATE_CHNL, channelChangeProc, this);
	
	initChannelInfo();
	VFX_OBJ_CREATE(m_channelList, VcpListMenu, this);
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_ENTRY_NORMAL, m_SIM, getCount(), m_isReentry);
	m_channelList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
	
	m_channelList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);
	m_channelList->setContentProvider(this);
	m_channelList->setPos(VfxPoint(0, 0));
    
	VfxSize parentSize = getSize();
    m_channelList->setSize(parentSize);
	m_channelList->m_signalCmdButtonClicked.connect(this, &VappCbsChannelListPage::onItemButtonTouched);
	m_channelList->m_signalItemTapped.connect(this, &VappCbsChannelListPage::onItemTouched);
	m_isReentry = VFX_TRUE;
    m_channelList->setAlignParent(
                                    VFX_FRAME_ALIGNER_MODE_SIDE,   // mode for left side
                                    VFX_FRAME_ALIGNER_MODE_SIDE,    // mode for top side
                                    VFX_FRAME_ALIGNER_MODE_SIDE,  // mode for right side
                                    VFX_FRAME_ALIGNER_MODE_SIDE);

    handleIfListPageEmpty();
    m_toolBar->setDisableItem(ADD, (getCount() == SRV_CBS_MAX_CHNL_NUM));
	
	
}

void VappCbsChannelListPage::handleIfListPageEmpty()
{
    if (!m_isOpt)
    {
        m_toolBar->setDisableItem(TO_DELETE, (getCount() == 0)); 
    }
}


VappCbsChannelListPage::VappCbsChannelListPage(VfxS32 sim) : 
	m_toolBar(NULL), 
	m_channelList(NULL), 
	m_SIM(sim),
	m_titleBar(NULL),
	m_isAdding(VFX_TRUE),
	m_isOpt(VFX_FALSE),
	m_isCancelled(VFX_FALSE),
	m_confirmPopup(NULL),
	m_processingPopup(NULL)
{
	// do nothing
};


VfxS32 VappCbsChannelListPage::getSim()
{
	return m_SIM;
};
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void VappCbsChannelListPage::resetMasks()
{
	for (VfxU32 i = 0; i < SRV_CBS_MAX_CHNL_NUM; ++i)
	{
		m_channelId[i] = VAPP_CB_INVALID_CHANNEL_ID;
		m_selectionMask[i] = VFX_FALSE;
	}
	m_totalSelection = 0;
	//m_isReentry = VFX_FALSE;
	m_toolBar->setDisableItem(DELETE, (m_totalSelection == 0));
}

VfxBool VappCbsChannelListPage::getSelectionByID(VfxId channelId) const
{
	for (VfxU32 i = 0; i < SRV_CBS_MAX_CHNL_NUM; ++i)
	{
		if (m_channelId[i] == channelId)
		{
			return m_selectionMask[i];
		}
	}
	return VFX_FALSE;
};

void VappCbsChannelListPage::onBack()
{
    if (m_isOpt)
    {
        switchToListPage();
    }
    else
    {
        VfxPage::onBack();
    }
}

// fill UI status of selection
void VappCbsChannelListPage::fillMasks()
{
	// temp info for cache
    VfxId channelId[SRV_CBS_MAX_CHNL_NUM]; 			// temp data for backup
    VfxBool selectionMask[SRV_CBS_MAX_CHNL_NUM];	// temp data for backup
	
	//fill selection mask to backup data
	for (VfxU32 i = 0; i < m_channelInfo.total; ++i)
	{
		channelId[i] = m_channelInfo.entry[i].id;
		selectionMask[i] = getSelectionByID(channelId[i]); // here backup original UI status
	}

	// clear orginal UI status
	resetMasks();
	
    m_totalSelection = 0;
	//fill data of UI status
	for (VfxU32 i = 0; i < m_channelInfo.total; ++i)
	{
		m_channelId[i] = channelId[i];
		m_selectionMask[i] = selectionMask[i];
        if(m_selectionMask[i])
        {
            ++m_totalSelection;
        }
	}
	m_isReentry = VFX_TRUE;
	m_toolBar->setDisableItem(DELETE, (m_totalSelection == 0));
};

//show channel list after related info is set, SIM here
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
void VappCbsChannelListPage::onListItemStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	VfxBool isSelected = ((newState == VCP_LIST_MENU_ITEM_STATE_SELECTED) ? VFX_TRUE : VFX_FALSE);
	if (m_selectionMask[index] != isSelected)
	{
		m_selectionMask[index] = isSelected;
		m_channelList->updateItem(index);
		if (isSelected)
		{
			//VFX_ASSERT(m_totalSelection < m_channelInfo.total);
			++m_totalSelection;
			m_isAdding = VFX_TRUE;
		}
		else
		{
			//VFX_ASSERT(m_totalSelection > 0);
			--m_totalSelection;
			m_isAdding = VFX_FALSE;
		}

	}
	if (m_totalSelection < m_channelInfo.total)
	{
		m_isAdding = VFX_TRUE;
	}
	if (m_totalSelection == m_channelInfo.total)
	{
		m_isAdding = VFX_FALSE;
	}
	if (m_isAdding)
	{
		m_toolBar->changeItem(ALL, (VfxResId)VCP_STR_TOOL_BAR_SELECT_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
	}
	else
	{
		m_toolBar->changeItem(ALL, (VfxResId)VCP_STR_TOOL_BAR_UNSELECT_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
	}
	m_toolBar->setDisableItem(DELETE, (m_totalSelection == 0));
	m_toolBar->setDisableItem(ALL, (getCount() == 0));
}


void VappCbsChannelListPage::onToolBarClick(VfxObject* sender, VfxId id)
{
	switch (id)
	{
		case ADD:
            if (getCount() < m_channelInfo.max_entry)
            {
    			createAndShowEditor(VFX_TRUE);
            }
            else
            {
                //showErrorConfirm(VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL));
				vapp_cbs_show_error_confirm(this, VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL), CBS_FAILURE_CONF);
            }
			break;
			
		case TO_DELETE:
			switchToOptPage();
			break;
			
		case ALL:
		{
			selectAll(m_isAdding);
			m_isAdding = !m_isAdding;
			VfxId str = VCP_STR_TOOL_BAR_UNSELECT_ALL;
			VfxId img = VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL;
			m_totalSelection = m_channelInfo.total;
			m_toolBar->setDisableItem(DELETE, VFX_FALSE);
			
			if(m_isAdding)
			{
				str = VCP_STR_TOOL_BAR_SELECT_ALL;
				img = VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL;
				m_totalSelection = 0;
				m_toolBar->setDisableItem(DELETE, VFX_TRUE);
			}
			m_toolBar->changeItem(ALL, (VfxResId)(str), img);
			break;
		}
		case CANCEL:
			switchToListPage();
			break;
			
		case DELETE:
			//VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
		    //m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);

            fillDeleteData();

            //VfxResId stringID = STR_ID_VAPP_CBS_CHANNEL_DELETE_CONFIRM_1;
			//VfxWString ask = VFX_WSTR_RES(stringID);
            
			//VfxWString number;
			//number.format("%d", m_totalToDelete);
			//ask += VFX_WSTR("(");
			//ask += number;
			//ask += VFX_WSTR(")");
			//ask += VFX_WSTR("?");
			
			VfxWString ask;
			vapp_cbs_delete_confirm_str(ask, m_totalToDelete, CBS_CHANNEL_STR);
			
		    //m_confirmPopup->setText(ask);
		    //m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
		    //m_confirmPopup->setCustomButton((VFX_WSTR_RES(STR_GLOBAL_DELETE)), (VFX_WSTR_RES(STR_GLOBAL_CANCEL)), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
		    //m_confirmPopup->show(VFX_TRUE);
		    VcpConfirmPopup *m_confirmPopup = vapp_cbs_show_error_confirm(this, ask, CBS_WARNING_CONF);
		    m_confirmPopup->m_signalButtonClicked.connect(this, &VappCbsChannelListPage::eventHandler);

	}
};


void VappCbsChannelListPage::onItemButtonTouched(VcpListMenu *sender, VfxU32 index)
{
	createAndShowEditor(VFX_FALSE, &m_channelInfo.entry[index]);
}


void VappCbsChannelListPage::createAndShowEditor(VfxBool isNew, srv_cbs_chnl_entry_struct *channel)
{
	VfxMainScr *relatedScr = (VfxMainScr *)(getMainScr());
	VappCbsChannelEditorPage *channelEditorPage;
	VFX_OBJ_CREATE_EX(channelEditorPage, VappCbsChannelEditorPage, relatedScr, (m_SIM, channel, isNew));
	//channelEditorPage->setIsNewChannel(isNew);
	//channelEditorPage->setSim(m_SIM);
	//channelEditorPage->setChannel(channel);
	//channelEditorPage->updateForm();
	relatedScr->pushPage(0, channelEditorPage);
}


void VappCbsChannelListPage::onItemTouched(VcpListMenu *sender, VfxU32 index)
{
	VfxMainScr *relatedScr = (VfxMainScr *)(getMainScr());
	VappCbsMsgListPage *msgListPage;
	VFX_OBJ_CREATE_EX(msgListPage, VappCbsMsgListPage, relatedScr, (m_SIM, m_channelInfo.entry[index].id));
	//msgListPage->setSim(m_SIM);
	//msgListPage->setChannel(m_channelInfo.entry[index].id);
	//msgListPage->initMsgInfo();
	//msgListPage->showList();
	//msgListPage->switchToViwePage();
	relatedScr->pushPage(0, msgListPage);
}



void VappCbsChannelListPage::eventHandler(VfxObject* obj, VfxId id)
{
	VFX_OBJ_CLOSE(m_confirmPopup);
	switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        {
		    break;
	    }
    		
	    case VCP_CONFIRM_POPUP_BUTTON_USER_1:
	    {
    		
		    VFX_OBJ_CREATE(m_processingPopup,VcpIndicatorPopup,getMainScr());
            m_processingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
            m_processingPopup->setText((VfxResId)STR_GLOBAL_DELETING);
            m_processingPopup->m_signalCanceled.connect(this, &VappCbsChannelListPage::onCanceled);
			m_processingPopup->m_signalButtonClicked.connect(this, &VappCbsChannelListPage::processingPopupKeyHandler);
            m_processingPopup->setProgress(0);
			m_processingPopup->show(VFX_TRUE);

		    m_isCancelled = VFX_FALSE;
		    deleteChannels();
		    break;
	    }
    }
}

void VappCbsChannelListPage::errorConfirmEventHandler(VfxObject* obj, VfxId id)
{
    switchToListPage();
}


void VappCbsChannelListPage::processingPopupKeyHandler(VfxObject* obj, VfxId evt)
{
	if (VCP_POPUP_BUTTON_CANCEL_PRESSED == evt)
	{
		m_isCancelled = VFX_TRUE;
		m_processingPopup = NULL;
        VFX_OBJ_CREATE(m_processingPopup,VcpIndicatorPopup,getMainScr());
        m_processingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_processingPopup->setText((VfxResId)STR_GLOBAL_CANCELLING);
	}
}


void VappCbsChannelListPage::onCanceled(VfxObject* obj, VfxFloat curr_progress)
{
    m_isCancelled = VFX_TRUE;
	
	m_processingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
	m_processingPopup->setText((VfxResId)STR_GLOBAL_CANCELLING);
}


void VappCbsChannelListPage::fillDeleteData()
{
	m_totalToDelete = 0;
	for (VfxU32 i = 0; i < m_channelInfo.total; ++i)
	{
		//VFX_ASSERT(m_channelId[i] == m_channelInfo.entry[i].id);
		if (m_selectionMask[i])
		{
			 m_channelToDelete[m_totalToDelete] = m_channelId[i];
			 ++m_totalToDelete;
		}
		
		VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_IS_SELECT, m_channelId[i], m_selectionMask[i]);
	}
	m_currDeleteIndex = 0;
}
void VappCbsChannelListPage::resetDeleteData()
{
	
	m_totalToDelete = 0;
	for (VfxU32 i = 0; i <SRV_CBS_MAX_CHNL_NUM; ++i)
	{
		m_selectionMask[i] = VFX_FALSE;
    	m_channelToDelete[i] = VAPP_CB_INVALID_MSG_ID;
	}
	m_currDeleteIndex = 0;
	m_isCancelled = VFX_FALSE;
}

void VappCbsChannelListPage::deleteChannels()
{
	fillDeleteData();
	
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_ENTRY_PRE_DELETE, getCount(), m_totalToDelete);
	
	//VFX_ASSERT (m_totalToDelete > 0);
	srv_cbs_delete_channel(m_channelToDelete[0], vapp_sms_sim_index_to_sim_id(getSim()), channelDeleteCallback, getObjHandle());
};

void VappCbsChannelListPage::updateProcess()
{
	if ((m_processingPopup != NULL) && (m_processingPopup->getInfoType() == VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON))
	{	
		//VFX_ASSERT(m_totalToDelete);
		m_processingPopup->setProgress(((VfxFloat)m_currDeleteIndex) / m_totalToDelete);
	}
}

void VappCbsChannelListPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
}


void VappCbsChannelListPage::switchToOptPage()
{
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_ENTRY_OPT, m_SIM, getCount(), m_isReentry);
	m_isOpt = VFX_TRUE;
	m_titleBar->setTitle((VfxResId)STR_ID_VAPP_CBS_CHANNEL_DELETE_TITLE);
	m_channelList->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
	m_channelList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL);
	m_toolBar->removeItem(ADD);
	m_toolBar->removeItem(TO_DELETE);
	m_toolBar->addItem(ALL, (VfxResId)VCP_STR_TOOL_BAR_SELECT_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
	m_toolBar->addItem(DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	m_toolBar->addItem(CANCEL, (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	m_toolBar->setDisableItem(DELETE, VFX_TRUE);
	
	m_channelList->m_signalItemSelectionStateChanged.connect(this, &VappCbsChannelListPage::onListItemStateChanged);
	m_channelList->m_signalCmdButtonClicked.disconnect(this, &VappCbsChannelListPage::onItemButtonTouched);
	m_channelList->m_signalItemTapped.disconnect(this, &VappCbsChannelListPage::onItemTouched);
	
	resetMasks();
	initChannelInfo();
	fillMasks();
	resetDeleteData();
    m_channelList->updateAllItems();
	m_isAdding = VFX_TRUE;
    handleIfListPageEmpty();
}

void VappCbsChannelListPage::switchToListPage()
{
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_ENTRY_LIST, m_SIM, getCount(), m_isReentry);

	m_isOpt = VFX_FALSE;
	m_titleBar->setTitle((VfxResId)STR_ID_VAPP_CBS_MSG_LIST_NORMAL_TITLE);

	m_channelList->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
	m_channelList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);
	
	m_toolBar->addItem(ADD, (VfxResId)STR_GLOBAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
	m_toolBar->addItem(TO_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_toolBar->setDisableItem(ADD, (getCount() == SRV_CBS_MAX_CHNL_NUM));
    handleIfListPageEmpty();

	m_toolBar->removeItem(ALL);
	m_toolBar->removeItem(DELETE);
	m_toolBar->removeItem(CANCEL);
	m_channelList->m_signalCmdButtonClicked.connect(this, &VappCbsChannelListPage::onItemButtonTouched);
	m_channelList->m_signalItemSelectionStateChanged.disconnect(this, &VappCbsChannelListPage::onListItemStateChanged);
	m_channelList->m_signalItemTapped.connect(this, &VappCbsChannelListPage::onItemTouched);
}

void VappCbsChannelListPage::selectAll(VfxBool isSelect)
{   
    m_isReentry = VFX_TRUE;
	for (VfxU32 i = 0; i < m_channelInfo.total; ++i)
	{
        m_selectionMask[i] = isSelect;
	}
    m_channelList->updateAllItems();
}

mmi_ret VappCbsChannelListPage::channelChangeProc(mmi_event_struct *param)
{
	VappCbsChannelListPage *existingPage = (VappCbsChannelListPage *)param->user_data;
	if (existingPage)
	{
		VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_CHANGE_PROC, param->evt_id, existingPage->getCount());
    	existingPage->initChannelInfo();
        existingPage->fillMasks();
        if (EVT_ID_SRV_CBS_UPDATE_CHNL != param->evt_id)
        {
            existingPage->m_channelList->reset();
        }
        else
        {
            srv_cbs_update_chnl_event_struct *event_data = (srv_cbs_update_chnl_event_struct *)param;
            VfxS32 channelIndex = existingPage->getChannelIndexById(event_data->new_chnl.id);
            if (channelIndex >= 0)
            {
                existingPage->m_channelList->updateItem(channelIndex);
            }
        }
        existingPage->handleIfListPageEmpty();
        existingPage->m_toolBar->setDisableItem(ADD, (existingPage->getCount() == SRV_CBS_MAX_CHNL_NUM));
		existingPage->m_toolBar->setDisableItem(ALL, (existingPage->getCount() == 0));
	}
	return MMI_OK;
}

VfxS32 VappCbsChannelListPage::getChannelIndexById(VfxU32 channelId)
{   
    VfxS32 i = getCount();
    for (i = i - 1; i >= 0; i--)
    {
        if (m_channelInfo.entry[i].id == channelId)
        {
            break;
        }
    }
    return i;
}

void VappCbsChannelListPage::channelDeleteCallback(cbsCallbackStruct *callbackData)
{

	VappCbsChannelListPage *actionPage = (VappCbsChannelListPage *)VfxObject::handleToObject((VfxObjHandle)callbackData->user_data);
	//VfxBool isFinished = VFX_FALSE;
	VfxBool isMsgDeleted = VFX_TRUE;
	if (actionPage != NULL)
	{
		VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_DELETEING,actionPage->m_channelToDelete[actionPage->m_currDeleteIndex], callbackData->result);
		VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_DELETE_RESULT, actionPage->m_currDeleteIndex, callbackData->result);
		if (!actionPage->m_isCancelled)
		{
			if (callbackData->result)
			{
			    /*delete realted msg*/
				srv_sms_sim_enum currSim = vapp_sms_sim_index_to_sim_id(actionPage->m_SIM);
				VfxU32 allNubmer = srv_cbs_get_msg_num(currSim);
                VfxId msgId[SRV_CBS_MAX_MSG_NUM];
                
				for (VfxU32 i = 0; i < allNubmer; ++i)
				{
					msgId[i] = srv_cbs_get_msg_id(i, currSim);
                }
                
				for (VfxU32 i = 0; i < allNubmer; ++i)
				{
					if (srv_cbs_get_msg_chnl_id(msgId[i], currSim) == actionPage->m_channelToDelete[(actionPage->m_currDeleteIndex)])
					{
						if (!srv_cbs_delete_msg(msgId[i], currSim))
						{
							isMsgDeleted = VFX_FALSE;
							break;
						}
					}
				}
				/*delete related msg end */
				if (isMsgDeleted)
				{
					++(actionPage->m_currDeleteIndex);
					if ((actionPage->m_currDeleteIndex) <  (actionPage->m_totalToDelete))
					{
		              	srv_cbs_delete_channel(actionPage->m_channelToDelete[actionPage->m_currDeleteIndex], 
						vapp_sms_sim_index_to_sim_id(actionPage->getSim()), channelDeleteCallback, actionPage->getObjHandle());
						actionPage->updateProcess();
					}
					else
					{
						// result proc
						//isFinished = VFX_TRUE;
	                    actionPage->resetDeleteData();
						VFX_OBJ_CLOSE(actionPage->m_processingPopup);
						actionPage->switchToListPage();
						//VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_DELETE_RESULT, actionPage->m_currDeleteIndex, callbackData->result);
					}
				}
				else
				{
					//isFinished = VFX_TRUE;
					actionPage->resetDeleteData();
					VFX_OBJ_CLOSE(actionPage->m_processingPopup);
					//actionPage->showErrorConfirm(VFX_WSTR_RES(STR_ID_VAPP_CBS_MSG_LIST_DELETE_FAILED_1));
					vapp_cbs_show_error_confirm(actionPage, VFX_WSTR_RES(STR_ID_VAPP_CBS_MSG_LIST_DELETE_FAILED_1), CBS_FAILURE_CONF);
					//VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_DELETE_RESULT, actionPage->m_currDeleteIndex, callbackData->result);
				}
			}
			else
			{
				// error handle
				//isFinished = VFX_TRUE;
				VFX_OBJ_CLOSE(actionPage->m_processingPopup);
				//actionPage->showErrorConfirm(VFX_WSTR_RES(STR_ID_VAPP_CBS_MSG_LIST_DELETE_FAILED_1));
				vapp_cbs_show_error_confirm(actionPage, VFX_WSTR_RES(STR_ID_VAPP_CBS_MSG_LIST_DELETE_FAILED_1), CBS_FAILURE_CONF);
				//VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_DELETE_RESULT, actionPage->m_currDeleteIndex, callbackData->result);
			}
		}
		else
		{
			//isFinished = VFX_TRUE;
			if (NULL != actionPage->m_processingPopup)
			{
				//actionPage->m_processingPopup->close();
				VFX_OBJ_CLOSE(actionPage->m_processingPopup);
			}
            if ((actionPage->m_currDeleteIndex + 1) <  actionPage->m_totalToDelete) //delete not finished
            {
                //actionPage->showErrorConfirm(VFX_WSTR_RES(STR_ID_VAPP_CBS_MSG_LIST_DELETE_FAILED_1));
				vapp_cbs_show_error_confirm(actionPage, VFX_WSTR_RES(STR_ID_VAPP_CBS_MSG_LIST_DELETE_FAILED_1), CBS_FAILURE_CONF);
            }
            else if (actionPage->getCount() == 1) //finished but nothing left
            {
                actionPage->switchToListPage();
            }
        }
	}
}

// data cache
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
#endif

void VappCbsChannelListPage::initChannelInfo()
{
	srv_cbs_get_channel(&m_channelInfo, vapp_sms_sim_index_to_sim_id(getSim()));
}

VfxBool VappCbsChannelListPage::getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        )
{
    VfxWChar w_name[SRV_CBS_CHNL_NAME_LEN + 1] = {0};
	VfxWChar w_number[VAPP_CBS_CHNL_NUMBER_DISP_LEN + 1] = { 0 };
	VfxChar number[VAPP_CBS_CHNL_NUMBER_DISP_LEN + 1] = { 0 };
    switch (fieldType)
	{
		case VCP_LIST_MENU_FIELD_TEXT:
            srv_cbs_get_channel_name(w_name, m_channelInfo.entry[index].id, vapp_sms_sim_index_to_sim_id(getSim()));
			text.loadFromMem(w_name);
            return VFX_TRUE;

    	case VCP_LIST_MENU_FIELD_SUB_TEXT1: 
			sprintf((char *)number, "%d", (VfxU32)(m_channelInfo.entry[index].id));
			mmi_asc_n_to_ucs2((CHAR *)w_number, (CHAR *)number, VAPP_CBS_CHNL_NUMBER_DISP_LEN);
			text.loadFromMem(w_number);
            return VFX_TRUE;

		default:
			text = VFX_WSTR_EMPTY;
            return VFX_FALSE;
	}
}

VfxBool VappCbsChannelListPage::getItemImage(
	VfxU32 index,
	VcpListMenuFieldEnum fieldType,
	VfxImageSrc &image
	)
{
	switch (fieldType)
	{

		case VCP_LIST_MENU_FIELD_ICON:
        {
            VfxU32 channelIndex  = index < m_channelInfo.total ? index : m_channelInfo.total;
		    if (m_channelInfo.entry[channelIndex].mask)
		    {
			    image = VfxImageSrc(IMG_ID_VAPP_CBS_VIEWER_TITLE_LIST_ICON);
			    return VFX_TRUE;
		    }
		    else
		    {
			    image = VfxImageSrc(IMG_ID_VAPP_CBS_VIEWER_TITLE_LIST_ICON_UNSUB);
			    return VFX_TRUE;
		    }
        }
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
		default:
			image = VfxImageSrc(IMG_ID_VAPP_CBS_CHANNEL_LIST_EDIT);
			return VFX_TRUE;

    }
}


VfxU32 VappCbsChannelListPage::getCount() const
{
	return m_channelInfo.total;
}

VcpListMenuItemStateEnum VappCbsChannelListPage::getItemState(VfxU32 index) const
{
	if (!m_isReentry)
	{
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
	else
	{
		VfxId channelId = m_channelInfo.entry[index].id;
		return getSelectionByID(channelId)? VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
}

VfxBool VappCbsChannelListPage::getMenuEmptyText(
    VfxWString & text,
    VcpListMenuTextColorEnum & color)
{
    text.loadFromRes(STR_ID_VAPP_CBS_CHANNEL_EMPTY_STRING);
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}

