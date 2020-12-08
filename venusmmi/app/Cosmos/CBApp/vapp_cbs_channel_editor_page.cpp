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
 * Vapp_cbs_pages.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================

**********************************************************************************/
#include "mmi_features.h"

#include "vapp_cbs_channel_editor_page.h"
#include "vapp_sms_util.h"

#define VAPP_CBS_CHNL_NUMBER_INPUT_LEN       5       /* 0 - 0xFFFF (0 - 65535) */
#define VaPP_CBS_CHNL_NUMBER_INPUT_MAX_VALUE 61439
// editor form
//VFX_IMPLEMENT_CLASS("VappCbsChannelEditorForm", VappCbsChannelEditorForm, VcpForm);
void VappCbsChannelEditorForm::createItems()
{
	VfxU32 i = 0;

	VFX_OBJ_CREATE(m_channelNameInput, VcpFormItemTextInput,this);
	m_channelNameInput->setLabelText((VfxResId)STR_ID_VAPP_CBS_CHANNEL_EDITOR_CHANNEL_NAME);
	m_channelNameInput->getTextBox()->setIME(IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE);
	m_channelNameInput->getTextBox()->setMaxLength(SRV_CBS_CHNL_NAME_LEN);
	addItem(m_channelNameInput, i++);
	
	VFX_OBJ_CREATE(m_channelNumberInput, VcpFormItemTextInput, this);
	m_channelNumberInput->setLabelText((VfxResId)STR_ID_VAPP_CBS_CHANNEL_EDITOR_CHANNEL_NUMBER);
	m_channelNumberInput->getTextBox()->setIME(IMM_INPUT_TYPE_NUMERIC, IME_SETTING_FLAG_NONE);
	m_channelNumberInput->getTextBox()->setMaxLength(VAPP_CBS_CHNL_NUMBER_INPUT_LEN);
	addItem(m_channelNumberInput, i++);

	VFX_OBJ_CREATE(m_subscribe, VcpFormItemSwitchCell,this);
	m_subscribe->setMainText((VfxResId)STR_ID_VAPP_CBS_CHANNEL_EDITOR_CHANNEL_SUBSCRIBE);
	m_subscribe->setSwitchStatus(VFX_TRUE);
	m_subscribe->m_signalSwitchChangeReq.connect(getParentFrame(), &VappCbsChannelEditorPage::activationSwitched);
	addItem(m_subscribe, i++);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappCbsChannelEditorForm::activeTextEditor(VfxBool isNameEditor, VfxBool isActive)
{
	VcpTextEditor *textEditor = NULL;
	if (isNameEditor)
		textEditor = m_channelNameInput->getTextBox();		
	else
		textEditor = m_channelNumberInput->getTextBox();
	if (isActive)
		textEditor->activate();
	else
		textEditor->deactivate();
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
#endif
void VappCbsChannelEditorForm::setFuncBar(VcpFunctionBar *funcBar, VfxBool isNameFuncBar)
{
	if (isNameFuncBar)
		m_channelNameInput->getTextBox()->setFunctionBar(funcBar);
	else
		m_channelNumberInput->getTextBox()->setFunctionBar(funcBar);
};

VcpTextEditor *VappCbsChannelEditorForm::getNameEditor(void)
{
	return m_channelNameInput->getTextBox();
};

VcpTextEditor *VappCbsChannelEditorForm::getNumberEditor(void)
{
	return m_channelNumberInput->getTextBox();
}

VcpFormItemTextInput *VappCbsChannelEditorForm::getNumberItem(void)
{
	return m_channelNumberInput;
};


VappCbsChannelEditorForm::VappCbsChannelEditorForm() : m_subscribe(NULL), m_channelNameInput(NULL), m_channelNumberInput(NULL)
{
	// do nothing but init members
};

const VfxWString VappCbsChannelEditorForm::getName(void)
{
    VfxWString tempString = m_channelNameInput->getText();
    return tempString;
};

const  VfxWString VappCbsChannelEditorForm::getNumber(void)
{
   VfxWString tempString = m_channelNumberInput->getText();
   return tempString;
};


VfxBool VappCbsChannelEditorForm::getSubscribeStatus(void)
{
    return m_subscribe->getSwitchStatus();
};


void VappCbsChannelEditorForm::setNameValue(VfxWString string)
{
    m_channelNameInput->setText(string);
	m_channelNameInput->getTextBox()->setMaxLength(SRV_CBS_CHNL_NAME_LEN);
};


void VappCbsChannelEditorForm::setNumberValue(VfxWString number)
{
    m_channelNumberInput->setText(number);
};


void VappCbsChannelEditorForm::setSubscribeStatus(VfxBool is_subscribed)
{
    m_subscribe->setSwitchStatus(is_subscribed);
}


void VappCbsChannelEditorForm::disabledNumber()
{
    m_channelNumberInput->setIsDisabled(VFX_TRUE);
}



// editor page
//VFX_IMPLEMENT_CLASS("VappCbsChannelEditorPage", VappCbsChannelEditorPage, VfxPage);


void VappCbsChannelEditorPage::onInit()
{
	VfxPage::onInit();
//title bar
	VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
	VfxWString title;
	title.loadFromRes(STR_ID_VAPP_CBS_CHANNEL_EDITOR_TITLE);
	m_titleBar->setTitle(title);
	setTopBar(m_titleBar);
	
	VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
	m_toolBar->addItem(SAVE, (VfxResId)STR_GLOBAL_SAVE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	m_toolBar->addItem(CANCEL, (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	setBottomBar(m_toolBar);
	m_toolBar->m_signalButtonTap.connect(this, &VappCbsChannelEditorPage::onToolBarClick);
	
	VFX_OBJ_CREATE(m_channelEditor, VappCbsChannelEditorForm, this);
	m_channelEditor->setPos(0,0);
	VfxSize barSize = m_titleBar->getSize();
	VfxSize titleBarSize = m_titleBar->getSize();
	VfxSize parentSize = getSize();
	m_channelEditor->setSize(parentSize);
    m_channelEditor->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,   // mode for left side
        VFX_FRAME_ALIGNER_MODE_SIDE,    // mode for top side
        VFX_FRAME_ALIGNER_MODE_SIDE,  // mode for right side
        VFX_FRAME_ALIGNER_MODE_SIDE  // mode for bottom side
    );
	m_channelEditor->createItems();

    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
    m_funcBar->m_signalButtonTap.connect(this, &VappCbsChannelEditorPage::onFuncBarClick);
	//updateForm();

	if (!m_isNewChannel)
	{
        VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_EDITOR_ENTRY, m_currChannel->id, m_isNewChannel);
		VfxWChar name[SRV_CBS_CHNL_NAME_LEN + 1];
        srv_cbs_get_channel_name(name, m_currChannel->id, vapp_sms_sim_index_to_sim_id(m_currSim));
		m_channelEditor->setNameValue(VFX_WSTR_MEM(name));
		//m_channelEditor->setNameFuncBar(m_funcBar);
		m_channelEditor->setFuncBar(m_funcBar, VFX_TRUE);
		VfxWString tempString;
		tempString.format("%d", m_currChannel->id);
		m_channelEditor->setNumberValue(tempString);
		m_channelEditor->disabledNumber();
		m_channelEditor->setSubscribeStatus((m_currChannel->mask ? VFX_TRUE : VFX_FALSE));
	#ifdef _VAPP_CBS_AUTO_CHECK_
		m_channelEditor->getNameEditor()->m_signalTextChanged.connect(this, &VappCbsChannelEditorPage::onTextChanged);
	#endif
} 
	else
	{
		m_channelEditor->setFuncBar(m_funcBar, VFX_FALSE);
		m_channelEditor->setFuncBar(m_funcBar, VFX_TRUE);
		m_funcBar->addItem((VfxResId)STR_ID_VAPP_CBS_CHANNEL_EDITOR_FUNCBAR_PREV, (VfxId)FUNCBAR_PREV);
		m_funcBar->addItem((VfxResId)STR_ID_VAPP_CBS_CHANNEL_EDITOR_FUNCBAR_NEXT, (VfxId)FUNCBAR_NEXT);
	#ifdef _VAPP_CBS_AUTO_CHECK_
		m_channelEditor->getNumberEditor()->m_signalTextChanged.connect(this, &VappCbsChannelEditorPage::onTextChanged);
	#endif
		m_channelEditor->getNameEditor()->m_signalActivated.connect(this, &VappCbsChannelEditorPage::onNameEditorActivated);
		m_channelEditor->getNumberEditor()->m_signalActivated.connect(this, &VappCbsChannelEditorPage::onNumberEditorActivated);
} 
	//m_channelEditor->activeNameEditor();
	m_channelEditor->activeTextEditor(VFX_TRUE, VFX_FALSE);
	m_funcBar->addItem((VfxResId)STR_GLOBAL_SAVE, (VfxId)FUNCBAR_SAVE);

	m_funcBar->setItemSpecial(FUNCBAR_SAVE);
	
#ifdef _VAPP_CBS_AUTO_CHECK_
	m_funcBar->setDisableItem(FUNCBAR_SAVE, VFX_TRUE);
	m_toolBar->setDisableItem(SAVE, VFX_TRUE);
#endif
} 


VappCbsChannelEditorPage::VappCbsChannelEditorPage(VfxS32 sim, srv_cbs_chnl_entry_struct *channel, VfxBool isNewChannel) : 
    m_channelEditor(NULL),
	m_titleBar(NULL), 
    m_toolBar(NULL),
    m_isNewChannel(isNewChannel),
    m_currSim(sim),
    m_currChannel(channel), 
    m_processingPopup(NULL), 
    m_confirmPopup(NULL),
    m_funcBar(NULL),
    m_isInProcessing(VFX_FALSE)
 {
 	//do nothing but init members
 }
	
//void VappCbsChannelEditorPage::setSim(VfxS32 sim)
//{
    //m_currSim = sim;
//}


VfxS32 VappCbsChannelEditorPage::getSim()
{
    return m_currSim;
}


//void VappCbsChannelEditorPage::setChannel(srv_cbs_chnl_entry_struct *channel)
//{
    //m_currChannel = channel;
//}


//srv_cbs_chnl_entry_struct * VappCbsChannelEditorPage::getChannel()
//{
    //return m_currChannel;
//}


//void VappCbsChannelEditorPage::setIsNewChannel(VfxBool isNewChannel)
//{
    //m_isNewChannel = isNewChannel;
//};


void VappCbsChannelEditorPage::activationSwitched(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    m_channelEditor->setSubscribeStatus(newStatus);
}


void VappCbsChannelEditorPage::onQueryRotateEx(VfxScreenRotateParam & param)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef _VAPP_CBS_AUTO_CHECK_
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef _VAPP_CBS_AUTO_CHECK_
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef _VAPP_CBS_AUTO_CHECK_
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif

#ifdef _VAPP_CBS_AUTO_CHECK_
void VappCbsChannelEditorPage::onTextChanged(VcpTextEditor *editor)
{
	VfxBool isDisable = VFX_FALSE; 
	if(!m_isNewChannel)
	{
		isDisable = VFX_FALSE;
	}
	else
	{	
		VfxU32 dummy = 0;
        vappCbsChannelEditorNumberInputErrorEnum errorCode = channelInputCheck(dummy);

		//VfxBool isDisable; 
		
		if (NO_ERROR == errorCode)
		{
			isDisable = VFX_FALSE;
			m_channelEditor->getNumberItem()->setWarningText(VFX_WSTR_NULL);
		}
		else
		{
			isDisable = VFX_TRUE;
			m_channelEditor->getNumberItem()->setWarningText(getErrorString(errorCode));
		}
	}
	m_funcBar->setDisableItem(FUNCBAR_SAVE, isDisable);
	m_toolBar->setDisableItem(SAVE, isDisable);
}
#endif




void VappCbsChannelEditorPage::onNameEditorActivated(VcpTextEditor *editor, VfxBool activated)
{
	if (activated)
	{
		m_funcBar->setDisableItem(FUNCBAR_PREV, VFX_TRUE);
		m_funcBar->setDisableItem(FUNCBAR_NEXT, VFX_FALSE);
	}
}
void VappCbsChannelEditorPage::onNumberEditorActivated(VcpTextEditor *editor, VfxBool activated)
{	
	if (activated)
	{
		m_funcBar->setDisableItem(FUNCBAR_PREV, VFX_FALSE);
		m_funcBar->setDisableItem(FUNCBAR_NEXT, VFX_TRUE);
	}
}

void VappCbsChannelEditorPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    if (!m_isInProcessing)
    {
    	switch (id)
    	{
    		case SAVE:
        	{
    			save();
               	break;

    		}
    		case CANCEL:
            {
    			if (isActive())
    			{
    				getMainScr()->popPage();
    			}
    			else
    			{
    				VfxObject *self = this;
    				VFX_OBJ_CLOSE(self);
    			}
    			break;
            }
    			
    		default:
    			//VFX_ASSERT((id == SAVE)|| (id == CANCEL));
    			break;
    	}
    }
}


void VappCbsChannelEditorPage::confirmEventHandler(VfxObject* obj, VfxId id)
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
    		save();
		    break;
	    }
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
#endif

VappCbsChannelEditorPage::vappCbsChannelEditorNumberInputErrorEnum VappCbsChannelEditorPage::channelInputCheck(VfxU32 &channelId)
{
	VfxWString nubmerString = m_channelEditor->getNumber();
	VfxU32 chnl_id = 0;
    VfxU16 tempNum[VAPP_CBS_CHNL_NUMBER_DISP_LEN + 1] = { 0 };
	memcpy(tempNum, nubmerString.getBuf(), sizeof(tempNum));
	if (tempNum[0] == 0)
	{	
		channelId = VAPP_CB_INVALID_CHANNEL_ID;
		return NUBMER_EMPTY; 
	}
	for(VfxU32 i = 0; i < VAPP_CBS_CHNL_NUMBER_DISP_LEN; ++i)
	{
		VfxU16 tempChar = tempNum[i];
		if (0 == tempChar)
		{
			break;
		}
		/*
		if (tempChar > '9' || tempChar < '0')
		{
			channelId = VAPP_CB_INVALID_CHANNEL_ID;
			return INVALID_INPUT;
		}
		else
		{
			chnl_id *= 10;
			chnl_id += (tempNum[i] - '0');
		}
		*/
		chnl_id *= 10;
		chnl_id += (tempNum[i] - '0');
	}

	
	channelId = chnl_id;
	if ((chnl_id > VaPP_CBS_CHNL_NUMBER_INPUT_MAX_VALUE) ||
		((chnl_id > 4095) && (chnl_id < 4352))
		)
	{
		return NUBMER_EXCEED;
	}
	return NO_ERROR;
}

VfxWString VappCbsChannelEditorPage::getErrorString(vappCbsChannelEditorNumberInputErrorEnum error)
{

	const mmi_rp_vapp_cbs_str_enum resId[] = 
		{
			STR_ID_VAPP_CBS_CHANNEL_EDITOR_NUM_LEN_EXCEEDED,
			STR_ID_VAPP_CBS_NUM_CANNOT_BE_EMPTY	
		};
	return VFX_WSTR_RES(resId[error]);
	/*
	switch (error)
	{
		case INVALID_INPUT:
		{
			return VFX_WSTR_RES(STR_GLOBAL_INVALID_INPUT);
		}
		
		case NUBMER_EXCEED:
		{
			return VFX_WSTR_RES(STR_ID_VAPP_CBS_CHANNEL_EDITOR_NUM_LEN_EXCEEDED);
		}

		case NUBMER_EMPTY:
		{
			return VFX_WSTR_RES(STR_ID_VAPP_CBS_NUM_CANNOT_BE_EMPTY);
		}
		
		default :
			return VFX_WSTR_RES(0);
	}*/
}


void VappCbsChannelEditorPage::save()
{
    if (m_isNewChannel)
    {
		//m_channelEditor->deactiveNumberEditor();
		m_channelEditor->activeTextEditor(VFX_FALSE, VFX_FALSE);
    	VFX_LOG(VAPP_CBS_TRC_GROUP, TRC_VAPP_CBS_CHANNEL_EDITOR_SUBMIT,0xffff, m_isNewChannel);
    }
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
	//m_channelEditor->deactiveNameEditor();
	m_channelEditor->activeTextEditor(VFX_TRUE, VFX_FALSE);
	
	srv_cbs_chnl_entry_struct chnl_entry;
	VfxWString nameString = m_channelEditor->getName();
	mmi_wcscpy(chnl_entry.name, nameString.getBuf());
	VfxU32 chnl_id = 0;
	vappCbsChannelEditorNumberInputErrorEnum errorCause = channelInputCheck(chnl_id);

	VfxWString errorPrompt;
	if (NO_ERROR != errorCause)
	{
		errorPrompt = getErrorString(errorCause);
		m_channelEditor->getNumberItem()->setWarningText(errorPrompt);
		return;
	}
	else
	{
		m_channelEditor->getNumberItem()->setWarningText(VFX_WSTR_NULL);
	}

    chnl_entry.mask = (m_channelEditor->getSubscribeStatus() ? SRV_TRUE : SRV_FALSE);
	chnl_entry.id = chnl_id;
	
	
    m_isInProcessing = VFX_TRUE;
	if (m_isNewChannel)
	{
        VFX_OBJ_CREATE(m_processingPopup, VcpIndicatorPopup, this);
        m_processingPopup->setText((VfxResId)STR_GLOBAL_SAVING);
        m_processingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_processingPopup->show(VFX_TRUE);
		srv_cbs_add_channel(
			&chnl_entry,
			vapp_sms_sim_index_to_sim_id(m_currSim),
			channelActionCallback,
			getObjHandle());

	}
	else
	{
		srv_cbs_update_channel(
	        &chnl_entry,
	        m_currChannel,
			vapp_sms_sim_index_to_sim_id(m_currSim),
	        channelActionCallback,
	        getObjHandle());
	}
}

void VappCbsChannelEditorPage::onFuncBarClick(VfxObject*, VfxId id)
{
    if (!m_isInProcessing)
    {
        switch (id)
        {
            case FUNCBAR_PREV:
    		{
    			//VFX_ASSERT(m_isNewChannel);
                //m_channelEditor->activeNameEditor();
                m_channelEditor->activeTextEditor(VFX_TRUE, VFX_TRUE);
    			//m_funcBar->setDisableItem(FUNCBAR_PREV, VFX_TRUE);
    			//m_funcBar->setDisableItem(FUNCBAR_NEXT, VFX_FALSE);
                break;
        	}
            case FUNCBAR_NEXT:
    		{
    			//VFX_ASSERT(m_isNewChannel);
                //m_channelEditor->activeNumberEditor();
                m_channelEditor->activeTextEditor(VFX_FALSE, VFX_TRUE);
    			//m_funcBar->setDisableItem(FUNCBAR_PREV, VFX_FALSE);
    			//m_funcBar->setDisableItem(FUNCBAR_NEXT, VFX_TRUE);
                break;
        	}
            case FUNCBAR_SAVE:
    		{
    			onToolBarClick(NULL, SAVE);
    			break;
        	}
    		
            default:
                return;
        }
    }
}

void VappCbsChannelEditorPage::channelActionCallback(cbsCallbackStruct* callbackData)
{
	VappCbsChannelEditorPage *actionPage = (VappCbsChannelEditorPage *)VfxObject::handleToObject((VfxObjHandle)callbackData->user_data);
	if (actionPage != NULL)
	{
	    actionPage->m_isInProcessing = VFX_FALSE;
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
      	#endif
		    VFX_OBJ_CLOSE(actionPage->m_processingPopup);
		if (callbackData->result)
		{
			VfxMainScr *relatedScr = (VfxMainScr *)(actionPage->getMainScr());
			if (actionPage->isActive())
			{
				relatedScr->popPage();
			}
			else
			{
				//actionPage->close();
				VFX_OBJ_CLOSE(actionPage);
			}
		}
		else
		{
			switch (callbackData->cause)
			{
				case SRV_SMS_CAUSE_CB_CHNL_DUPLICATED:
				{
					actionPage->m_channelEditor->getNumberItem()->setWarningText((VfxResId)STR_ID_VAPP_CBS_CHANNEL_EDITOR_CHNL_DUPLICTED);
					break;
				}

				case SRV_SMS_CAUSE_CB_CHNL_FULL:
 				{
					
					actionPage->m_channelEditor->getNumberItem()->setWarningText(VFX_WSTR_NULL);
					//actionPage->showErrorConfirm(VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL));
					vapp_cbs_show_error_confirm(actionPage, VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL), CBS_FAILURE_CONF);
					break;
				}

				default:
					//actionPage->showErrorConfirm(VFX_WSTR_RES(STR_GLOBAL_FAILED_TO_SAVE));
					vapp_cbs_show_error_confirm(actionPage, VFX_WSTR_RES(STR_GLOBAL_FAILED_TO_SAVE), CBS_FAILURE_CONF);
 			}
		}
	}
}

