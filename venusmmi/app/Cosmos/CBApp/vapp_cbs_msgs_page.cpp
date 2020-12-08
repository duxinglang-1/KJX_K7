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
 * Vapp_cbs_msgs_page.cpp
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines class of CB app pages of venus.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**********************************************************************************/
#include "mmi_features.h"

#include "vapp_cbs_msgs_page.h"
#include "vapp_cbs_viewer_page.h"
#include "vapp_sms_util.h"

//VFX_IMPLEMENT_CLASS("VappCbsMsgListPage", VappCbsMsgListPage, VfxPage);

VappCbsMsgListPage::VappCbsMsgListPage(VfxS32 sim, VfxId channel) : 
	m_titleBar(NULL),
	m_toolBar(NULL), 
	m_msgList(NULL), 
	m_SIM(sim),
	m_channel(channel),
	m_totalMsg(0),
	m_selectedNumber(0),
	m_isAdding(VFX_TRUE),
	m_isDeleting(VFX_FALSE),
    m_isMulti(VFX_FALSE) ,
    m_confirmPopup(NULL),
	m_processingPopup(NULL)
{
	// do nothing
};


//cntx
VfxS32 VappCbsMsgListPage::getSim()
{
	return m_SIM;
};
//void VappCbsMsgListPage::setSim(VappCbsSimEnum sim)
//{
	//m_SIM = sim;
//};
//VfxId VappCbsMsgListPage::getChannel()
//{
	//return m_channel;
//}
//void VappCbsMsgListPage::setChannel(VfxId channel)
//{
	//m_channel = channel;
//};


void VappCbsMsgListPage::onBack()
{
    if (m_isMulti)
    {
        switchToViwePage();
    }
    else
    {
        VfxPage::onBack();
    }
}


void VappCbsMsgListPage::onInit()
{
	VfxPage::onInit();
    mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_ADD_MSG, msgChangeProc, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_DEL_MSG, msgChangeProc, this);
	mmi_frm_cb_reg_event(EVT_ID_SRV_CBS_DEL_CHNL, channelChangeProc, this);

	
	VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    setTopBar(m_titleBar);

	
	VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
	m_toolBar->m_signalButtonTap.connect(this, &VappCbsMsgListPage::onToolBarClick);
	setBottomBar(m_toolBar);
	initMsgInfo();

		
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_ENTRY, m_SIM, m_channel, m_isReentry);

	VFX_OBJ_CREATE(m_msgList, VcpListMenu, this);
	m_msgList->setContentProvider(this);
	m_msgList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT);
	m_msgList->setPos(VfxPoint(0, 0));
	VfxSize parentSize = getSize();
	m_msgList->setSize(parentSize);
    m_msgList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,   // mode for left side
        VFX_FRAME_ALIGNER_MODE_SIDE,    // mode for top side
        VFX_FRAME_ALIGNER_MODE_SIDE,  // mode for right side
        VFX_FRAME_ALIGNER_MODE_SIDE  // mode for bottom side
    );
	setTitle();

    handleIfViewPageEmpty();
	switchToViwePage();
	
}

void VappCbsMsgListPage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_DEL_CHNL, channelChangeProc, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_ADD_MSG, msgChangeProc, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CBS_DEL_MSG, msgChangeProc, this);
	VfxPage::onDeinit();
}

/*
void VappCbsMsgListPage::showList()
{
	
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_ENTRY, m_SIM, m_channel, m_isReentry);

	VFX_OBJ_CREATE(m_msgList, VcpListMenu, this);
	m_msgList->setContentProvider(this);
	m_msgList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT);
	m_msgList->setPos(VfxPoint(0, 0));
	VfxSize parentSize = getSize();
	m_msgList->setSize(parentSize);
    m_msgList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,   // mode for left side
        VFX_FRAME_ALIGNER_MODE_SIDE,    // mode for top side
        VFX_FRAME_ALIGNER_MODE_SIDE,  // mode for right side
        VFX_FRAME_ALIGNER_MODE_SIDE  // mode for bottom side
    );
	setTitle();

    handleIfViewPageEmpty();
}
*/
void VappCbsMsgListPage::handleIfViewPageEmpty()
{
    if (!m_isMulti)
    {
        m_toolBar->setDisableItem(TO_DELETE, (getCount() == 0)); 
    }
}

void VappCbsMsgListPage::setTitle()
{
    VfxWString text;
    if (m_isMulti)
    {
        text.loadFromRes(STR_ID_VAPP_CBS_MSG_LIST_DELETE_TITLE);
    }
    else
    {
        VfxWChar w_name[SRV_CBS_CHNL_NAME_LEN + 1] = {0};
    	VfxWChar w_number[VAPP_CBS_CHNL_NUMBER_DISP_LEN + 1] = { 0 };
    	VfxChar number[VAPP_CBS_CHNL_NUMBER_DISP_LEN + 1] = { ' ', 0 };
        srv_cbs_get_channel_name(w_name, m_channel, vapp_sms_sim_index_to_sim_id(getSim()));
    	text.loadFromMem(w_name);
    	sprintf((char *)number, "%d", (VfxU32)(m_channel));
    	mmi_asc_n_to_ucs2((CHAR *)w_number, (CHAR *)number, VAPP_CBS_CHNL_NUMBER_DISP_LEN);
    	text += VFX_WSTR(" ");
    	text += VFX_WSTR_MEM(w_number);
    }
    m_titleBar->setTitle(text);
}


void VappCbsMsgListPage::switchToOptPage()
{
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_ENTRY_OPT_LIST, m_SIM, getCount(), m_selectedNumber,m_isReentry);
	m_isReentry = VFX_FALSE;
    m_isMulti = VFX_TRUE;
	resetMasks();
	m_msgList->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
	m_msgList->m_signalItemSelectionStateChanged.connect(this, &VappCbsMsgListPage::onListItemStateChanged);
	m_msgList->m_signalItemTapped.disconnect(this, &VappCbsMsgListPage::onItemTouched);

    m_toolBar->removeItem(TO_DELETE);
	m_toolBar->addItem(ALL, (VfxResId)VCP_STR_TOOL_BAR_SELECT_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
	m_toolBar->addItem(DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	m_toolBar->addItem(CANCEL, (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	m_toolBar->setDisableItem(DELETE, VFX_TRUE);
	setTitle();
	m_isAdding = VFX_TRUE;

};


void VappCbsMsgListPage::switchToViwePage()
{
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_ENTRY_VIEW_LIST, m_SIM, getCount(), m_selectedNumber,m_isReentry);
    m_isMulti = VFX_FALSE;
	m_msgList->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
	m_msgList->m_signalItemSelectionStateChanged.disconnect(this, &VappCbsMsgListPage::onListItemStateChanged);
	m_msgList->m_signalItemTapped.connect(this, &VappCbsMsgListPage::onItemTouched);
	m_toolBar->addItem(TO_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
	
	m_toolBar->removeItem(ALL);
	m_toolBar->removeItem(DELETE);
	m_toolBar->removeItem(CANCEL);
    refreshDataAndKeepSelectionInfo();
    handleIfViewPageEmpty();
	setTitle();
};

void VappCbsMsgListPage::backupOriginIds()
{
	memcpy(&m_msgIdTemp, &m_msgId, sizeof(m_msgId));
	m_totalMsgTemp = m_totalMsg;
};

void VappCbsMsgListPage::backupOrignalSelection()
{
	//must refresh msg id first
	VfxBool tempSelectionMask[SRV_CBS_MAX_MSG_NUM];
	m_selectedNumber = 0;
	for(VfxS32 i = 0; i < SRV_CBS_MAX_MSG_NUM; i++)
	{
		tempSelectionMask[i] = getSelectionByID(m_msgId[i]);
	}
	
	for(VfxS32 i = 0; i < SRV_CBS_MAX_MSG_NUM; i++)
	{
		m_selectionMask[i] = tempSelectionMask[i];
		if (tempSelectionMask[i])
		{
			++m_selectedNumber;
		}
	}
	
	if (m_isAdding)
	{
		m_toolBar->changeItem(ALL, (VfxResId)VCP_STR_TOOL_BAR_SELECT_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
	}
	else
	{
		m_toolBar->changeItem(ALL, (VfxResId)VCP_STR_TOOL_BAR_UNSELECT_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
	}
	if (m_selectedNumber == 0)
	{
		m_toolBar->changeItem(ALL, (VfxResId)VCP_STR_TOOL_BAR_SELECT_ALL,VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
		m_toolBar->setDisableItem(DELETE, VFX_TRUE);
		m_isAdding = VFX_TRUE;
	}
	if (m_totalMsg == 0)
	{
		m_toolBar->setDisableItem(ALL, VFX_TRUE);
	}
}


void VappCbsMsgListPage::onToolBarClick(VfxObject* sender, VfxId id)
{
	switch(id)
	{
		case TO_DELETE:
		{
			switchToOptPage();
			break;
		}
		case ALL:
		{
			selectAll(m_isAdding);
			m_isAdding = !m_isAdding;
            VfxId str = VCP_STR_TOOL_BAR_UNSELECT_ALL;
			VfxId img = VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL;
            m_selectedNumber = m_totalMsg;

            if(m_isAdding)
            {
                str = VCP_STR_TOOL_BAR_SELECT_ALL;
				img = VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL;
                m_selectedNumber = 0;
            }
			m_toolBar->changeItem(ALL, VFX_WSTR_RES(str),img);
			m_toolBar->setDisableItem(DELETE, m_selectedNumber == 0);
			break;
		}
		case DELETE:
		{
			
			//VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
		    //m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);

            // compose delete confirm string
            // calculate amount of msg to delete
            VfxU32 totalToDelete = 0;
            for (VfxU32 i = 0; i < m_totalMsg; ++i)
            {
                if (m_selectionMask[i])
                {
                    totalToDelete++;
                }
            }
            
            //VfxResId stringID = STR_ID_VAPP_CBS_MSG_LIST_DELETE_CONFIRM_1;
            // string compose
			//VfxWString ask = VFX_WSTR_RES(stringID);
			//VfxWString number;
			//number.format("%d", totalToDelete);
			//ask += VFX_WSTR("(");
			//ask += number;
			//ask += VFX_WSTR(")");
			//ask += VFX_WSTR("?");

			
			VfxWString ask;
			vapp_cbs_delete_confirm_str(ask, totalToDelete, CBS_MSG_STR);
            
		    //m_confirmPopup->setText(ask);
		    //m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
		    //m_confirmPopup->setCustomButton((VFX_WSTR_RES(STR_GLOBAL_DELETE)) , (VFX_WSTR_RES(STR_GLOBAL_CANCEL)), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
		    //m_confirmPopup->show(VFX_TRUE);
		    VcpConfirmPopup *m_confirmPopup = vapp_cbs_show_error_confirm(this, ask, CBS_WARNING_CONF);
		    m_confirmPopup->m_signalButtonClicked.connect(this, &VappCbsMsgListPage::eventHandler);
			break;
		}
		case CANCEL:
		{
			switchToViwePage();
			break;
		}
		default:
			//VFX_ASSERT(id <= CANCEL);
			break;
	}
}
void VappCbsMsgListPage::eventHandler(VfxObject* obj, VfxId id)
{
    VFX_OBJ_CLOSE(m_confirmPopup);
	switch (id)
    {
    		
	    case VCP_CONFIRM_POPUP_BUTTON_USER_1:
	    {
			deleteSelected();
		    break;
	    }
    }
}

void VappCbsMsgListPage::deleteSelected()
{
    VfxId msgIdToDelete[SRV_CBS_MAX_MSG_NUM];
	VfxId totalToDelete = 0;
	m_isDeleting = VFX_TRUE;
	for (VfxU32 i = 0; i < m_totalMsg; ++i)
	{
		if (m_selectionMask[i])
		{
			msgIdToDelete[totalToDelete++] = m_msgId[i];
		}
		
		VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_IS_SELECT, m_msgId[i], m_selectionMask[i]);
	}
	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_PRE_DELETE, m_SIM, getCount(), totalToDelete);
	srv_sms_sim_enum sim = vapp_sms_sim_index_to_sim_id(m_SIM);
    VfxU32 j = 0;
	for (; j < totalToDelete; ++j)
	{
		if (!srv_cbs_delete_msg(msgIdToDelete[j], sim))
		{
			
			VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_DELETEING, msgIdToDelete[j], 0);
			break;
		}
		VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_DELETEING, msgIdToDelete[j], 1);
	}
	if (j < totalToDelete)
	{
		//VcpConfirmPopup *errorPrompt = NULL;
		//VFX_OBJ_CREATE(errorPrompt, VcpConfirmPopup, this);
		VfxWString temp;
		temp.loadFromRes(STR_ID_VAPP_CBS_MSG_LIST_DELETE_FAILED_1);
		VfxWString number;
		number.format("%d", totalToDelete - j);
		temp += number;
		temp += (VFX_WSTR_RES(STR_ID_VAPP_CBS_MSG_LIST_DELETE_FAILED_2));
		vapp_cbs_show_error_confirm(this, temp, CBS_FAILURE_CONF);
		VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_DELETE_RESULT, j, 0);
	}
	else
	{
		switchToViwePage();
	}
	//VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_DELETE_RESULT, j, 1);
	m_isDeleting = VFX_FALSE;
    refreshDataAndKeepSelectionInfo();
	m_msgList->reset();
    //resetDeleteData();
}

void VappCbsMsgListPage::refreshDataAndKeepSelectionInfo()
{
	backupOriginIds();
	initMsgInfo();
    backupOrignalSelection();
    backupOriginIds();
}

void VappCbsMsgListPage::onListItemStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	VfxBool isSelected = ((newState == VCP_LIST_MENU_ITEM_STATE_SELECTED) ? SRV_TRUE : SRV_FALSE);
	
	if (m_selectionMask[index] != isSelected)
	{
		m_selectionMask[index] = isSelected;
		m_msgList->updateItem(index);
		
		if (isSelected)
		{
            if (m_selectedNumber < m_totalMsg)
            {
                ++m_selectedNumber;
            }
            //VFX_ASSERT(m_selectedNumber <= m_totalMsg);
			m_toolBar->setDisableItem(DELETE, VFX_FALSE);
		    if(m_selectedNumber == m_totalMsg)
		    {
		        m_isAdding = VFX_FALSE;
            }
			
		}
		else
		{
			if(m_selectedNumber > 0)
            {
			    --m_selectedNumber;
            }
			if (m_selectedNumber == 0)
	        {
				m_toolBar->setDisableItem(DELETE, VFX_TRUE);
		    }
            m_isAdding = VFX_TRUE;
		}
	}
    if (m_isAdding)
    {
        m_toolBar->changeItem(ALL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SELECT_ALL),VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }
    else
    {
        m_toolBar->changeItem(ALL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_UNSELECT_ALL),VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    m_isReentry = VFX_TRUE;
}
void VappCbsMsgListPage::onItemTouched(VcpListMenu *sender, VfxU32 index)
{
	VfxMainScr *parentScrn = (VfxMainScr *)getMainScr();
	VappCbsViewerPage *viewerPage;
	
	VFX_OBJ_CREATE_EX(viewerPage, VappCbsViewerPage, parentScrn, (m_SIM));
	//viewerPage->setSim(m_SIM);
	//viewerPage->setMsgId(m_msgId[index]);
	//viewerPage->setChannelId(m_channel);
	viewerPage->setMsgIdAndChannelId(m_msgId[index], m_channel);
	if (viewerPage->readContent())
	{
		viewerPage->setElements();
		viewerPage->updateContent();
		parentScrn->pushPage('View', viewerPage);
	}
	else
	{
		VFX_OBJ_CLOSE(viewerPage);
		vapp_cbs_show_error_confirm(this, VFX_WSTR_RES(STR_GLOBAL_FAILED), CBS_FAILURE_CONF);
	}
}
void VappCbsMsgListPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
}

void VappCbsMsgListPage::initMsgInfo()
{
	m_totalMsg = 0;
	SRV_SIM_ENUM currSim = vapp_sms_sim_index_to_sim_id(m_SIM);
	VfxU32 allNubmer = srv_cbs_get_msg_num(currSim);
	for (VfxU32 i = 0; i < allNubmer; ++i)
	{
		VfxU16 msgId = srv_cbs_get_msg_id(i, currSim);
		if (srv_cbs_get_msg_chnl_id(msgId, currSim) == m_channel)
		{
			m_msgId[m_totalMsg] = msgId;
			++m_totalMsg;
		}
	}
	for (VfxU32 j = m_totalMsg; j < SRV_CBS_MAX_MSG_NUM; ++j)
	{
		m_msgId[j] = VAPP_CB_INVALID_MSG_ID;
	}
}


void VappCbsMsgListPage::selectAll(VfxBool isSelect)
{   
    m_isReentry = VFX_TRUE;
	for (VfxU32 i = 0; i < m_totalMsg; ++i)
	{
        m_selectionMask[i] = isSelect;
	}
	m_msgList->updateAllItems();
}


void VappCbsMsgListPage::resetMasks()
{
	for (VfxU32 j = 0; j < SRV_CBS_MAX_MSG_NUM; ++j)
	{
		m_selectionMask[j] = VFX_FALSE;
	}
	m_selectedNumber = 0;
}

void VappCbsMsgListPage::fillMasks()
{
	m_selectedNumber = 0;
	VfxU32 i = 0;
	for (; i < m_totalMsg ; ++i)
	{
		if (m_selectionMask [i] == ((m_msgList->getItemState(i) == VCP_LIST_MENU_ITEM_STATE_SELECTED) ? VFX_TRUE : VFX_FALSE))
		{
			++m_selectedNumber;
		}
	}
	for (; i < SRV_CBS_MAX_MSG_NUM; ++i)
	{
		m_selectionMask [i] = VFX_FALSE;
	}
}


VfxBool VappCbsMsgListPage::getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        )
{
    VfxWChar w_content[VAPP_CBS_MSG_SUBJECT_LENGTH + 1] = {0};
    switch (fieldType)
	{
		case VCP_LIST_MENU_FIELD_TEXT:
        {
            //kal_prompt_trace(MOD_MMI, "[0]%d, [1]%d, index %d", w_content[0],  w_content[1], index);
            //kal_prompt_trace(MOD_MMI, "[0]%d, [1]%d, [2]%d", w_content[0],  w_content[1], w_content[2]);
			srv_cbs_read_msg(m_msgId[index], vapp_sms_sim_index_to_sim_id(getSim()), w_content, VAPP_CBS_MSG_SUBJECT_LENGTH);
			text.loadFromMem(w_content);
            //kal_prompt_trace(MOD_MMI, "[0]%d, [1]%d, [2]%d", w_content[0],  w_content[1], w_content[2]);
            break;
        }

    	case VCP_LIST_MENU_FIELD_SUB_TEXT2: 
        {
			U32 timestampInt;
			timestampInt = srv_cbs_get_msg_time(m_msgId[index], vapp_sms_sim_index_to_sim_id(getSim()));

			MYTIME time;
			mmi_dt_utc_sec_2_mytime(timestampInt, &time, MMI_FALSE);
			
			VfxDateTime timeStamp;
		
			timeStamp.setDate(time.nYear, time.nMonth, time.nDay);
			timeStamp.setTime(time.nHour, time.nMin, time.nSec);

		    VfxDateTime todayStart;
			todayStart.setCurrentTime();
			todayStart.setTime(0, 0, 0);
			
			VfxU32 flags = 0;
			if (timeStamp.compareWith(todayStart) == VfxDateTime::LESS)
			{
				flags = VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;
			}
			else
			{
				flags = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
			}
				
			VfxWChar datatime[CBS_DATATIME_BUFF_LEN + 1];
			timeStamp.getDateTimeString(flags, datatime, CBS_DATATIME_BUFF_LEN);
			text.loadFromMem(datatime);
            break;
        }
        
		default:
        {
        }
	}
    return VFX_TRUE;
}

VfxU32 VappCbsMsgListPage::getCount() const
{
	return m_totalMsg;
}

VfxBool VappCbsMsgListPage::getSelectionByID(VfxId msgId) const
{
	for (VfxU32 i = 0; i < SRV_CBS_MAX_MSG_NUM; ++i)
	{
		if (m_msgIdTemp[i] == msgId)
		{
			return m_selectionMask[i];
		}
	}
	return VFX_FALSE;
};

VcpListMenuItemStateEnum VappCbsMsgListPage::getItemState(VfxU32 index) const
{
	if (!m_isReentry)
	{
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
	else
	{
		//SRV_SIM_ENUM currSim = vappCbsTransfer2SrvSIM(m_SIM);
		VfxId msgId = m_msgId[index];
		return getSelectionByID(msgId)? VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
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
/* under construction !*/
#endif
VfxBool VappCbsMsgListPage::getMenuEmptyText(
    VfxWString & text,
    VcpListMenuTextColorEnum & color)
{
    text.loadFromRes(STR_ID_VAPP_CBS_MSG_LIST_EMPTY_STRING);
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}

void VappCbsMsgListPage::errorConfirmEventHandler(VfxObject* obj, VfxId id)
{
    switchToViwePage();
}



mmi_ret VappCbsMsgListPage::msgChangeProc(mmi_event_struct *param)
{ 
	
	VappCbsMsgListPage *currPage = (VappCbsMsgListPage*)param->user_data;
	if (!currPage->m_isDeleting)
	{
		SRV_SIM_ENUM currSim = vapp_sms_sim_index_to_sim_id(currPage->m_SIM);
		VfxU32 msg_id;
		srv_sms_sim_enum sim_id;
		VfxBool isInList = VFX_FALSE;
		srv_cbs_add_msg_event_struct *event = (srv_cbs_add_msg_event_struct*)param;
		msg_id = event->msg_id;
		sim_id = event->sim_id;
		VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_MSG_CHANGE_PROC, param->evt_id, msg_id, sim_id);
		switch(param->evt_id)
		{
			case EVT_ID_SRV_CBS_ADD_MSG:
			{
				//VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_MSG_CHANGE_PROC, param->evt_id, msg_id, sim_id);
				break;
			}

			case EVT_ID_SRV_CBS_DEL_MSG:
			{

				//VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_MSG_CHANGE_PROC, param->evt_id, msg_id, sim_id);
                if (sim_id == vapp_sms_sim_index_to_sim_id(currPage->getSim()))
                {
                    for(VfxU32 i = 0; i < currPage->m_totalMsgTemp; ++i)
    				{
    					if (currPage->m_msgIdTemp[i] == msg_id)
    					{
    						isInList = VFX_TRUE;
    						break;
    					}
    				}//determine wether the msg being deleted is in msg list
                }
	            break;
			}
			
			default:
				VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_MSG_CHANGE_PROC, param->evt_id, 0xFFFF, 0xFFFF);
				return MMI_RET_OK;
		}
	    if (isInList || 
				((sim_id == vapp_sms_sim_index_to_sim_id(currPage->getSim())) && 
				(srv_cbs_get_msg_chnl_id(msg_id, sim_id) == currPage->m_channel)))
		{
			currPage->refreshDataAndKeepSelectionInfo();
			currPage->m_msgList->reset();
			currPage->m_toolBar->setDisableItem(ALL, (currPage->getCount() == 0));
			currPage->m_toolBar->setDisableItem(DELETE, (currPage->m_selectedNumber == 0));
			currPage->handleIfViewPageEmpty();
        }
	}
	return MMI_RET_OK;
}
mmi_ret VappCbsMsgListPage::channelChangeProc(mmi_event_struct *param)
{
	
	switch(param->evt_id)
	{ 
		case EVT_ID_SRV_CBS_DEL_CHNL:
		{
			VappCbsMsgListPage *currPage = (VappCbsMsgListPage*)param->user_data;
			SRV_SIM_ENUM currSim = vapp_sms_sim_index_to_sim_id(currPage->m_SIM);
			srv_cbs_del_chnl_event_struct *event = (srv_cbs_del_chnl_event_struct*)param;
			
			srv_sms_sim_enum sim_id = event->sim_id;
			VfxId channel_id = event->chnl_id;
			
			VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_MSG_CHANNEL_CHANGE_PROC, param->evt_id, event->chnl_id, sim_id);
			if ((sim_id == vapp_sms_sim_index_to_sim_id(currPage->getSim())) && 
				(channel_id == currPage->m_channel))
			{
				currPage->exit();
				vapp_cbs_show_error_confirm(currPage->getParent(),VFX_WSTR_RES(STR_GLOBAL_DELETED), CBS_INFO_CONF);
				//VcpConfirmPopup *errorPrompt = NULL;
				//VFX_OBJ_CREATE(errorPrompt, VcpConfirmPopup, currPage->getParent());
				//errorPrompt->setInfoType(VCP_POPUP_TYPE_INFO);
				//VfxWString temp = (VFX_WSTR_RES(STR_GLOBAL_DELETED));
				//errorPrompt->setText(temp);
				//errorPrompt->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
				//errorPrompt->setAutoDestory(VFX_TRUE);
				//errorPrompt->show(VFX_TRUE);
			}
		}
	}
	return MMI_RET_OK;
};

