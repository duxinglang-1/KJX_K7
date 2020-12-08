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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**********************************************************************************/
#include "mmi_features.h"

#include "vapp_cbs_language_page.h"
#include "vapp_sms_util.h"


static const VfxId lang_str_id[SRV_CBS_MAX_LANG_SUPPORT] = 
{
	STR_ID_VAPP_CBS_LANG_GERMAN,//0
	STR_ID_VAPP_CBS_LANG_ENGLISH,
	STR_ID_VAPP_CBS_LANG_ITALIAN,
	STR_ID_VAPP_CBS_LANG_FRENCH,
	STR_ID_VAPP_CBS_LANG_SPANISH,
	STR_ID_VAPP_CBS_LANG_DUTCH,//5
	STR_ID_VAPP_CBS_LANG_SWEDISH,
	STR_ID_VAPP_CBS_LANG_DANISH,
	STR_ID_VAPP_CBS_LANG_PORTUGUESE,
	STR_ID_VAPP_CBS_LANG_FINNISH,
	STR_ID_VAPP_CBS_LANG_NORWEGIAN,//10
	STR_ID_VAPP_CBS_LANG_GREEK,
	STR_ID_VAPP_CBS_LANG_TURKISH,
	STR_ID_VAPP_CBS_LANG_HUNGARIAN,
	STR_ID_VAPP_CBS_LANG_POLISH,
	STR_ID_VAPP_CBS_LANG_CZECH,//15
	STR_ID_VAPP_CBS_LANG_HEBREW,
	STR_ID_VAPP_CBS_LANG_ARABIC,
	STR_ID_VAPP_CBS_LANG_RUSSIAN,
	STR_ID_VAPP_CBS_LANG_ICELANDIC, //20
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
	STR_ID_VAPP_CBS_LANG_OTHERS,
	0
};

//VFX_IMPLEMENT_CLASS("VappCbsLanguagePage", VappCbsLanguagePage, VfxPage);
VappCbsLanguagePage::VappCbsLanguagePage(VfxS32 sim) : 
		m_languageList(NULL), 
		m_toolBar(NULL),
		m_SIM(sim), 
		m_processingPopup(0),
		m_selectedNumber(0)		
{
	// do nothing but init memebers
};
// cntx
VfxS32 VappCbsLanguagePage::getSim()
{
	return m_SIM;
};

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappCbsLanguagePage::initLanguageInfo()
{
    kal_bool result = srv_cbs_get_language(&m_languageData, vapp_sms_sim_index_to_sim_id(getSim()));
	if (!result)
	{
		VfxObject *self = this;
		VFX_OBJ_CLOSE(self);
	}
	else
	{
		setSelectedNumber();
	}
}


void VappCbsLanguagePage::setSelectedNumber()
{
	m_selectedNumber = 0;
	if (m_languageData.is_all_on)
	{
		m_selectedNumber = m_languageData.total;
	}
	else 
	{
		for (VfxU32 i = 0; i < m_languageData.total; ++i)
		{
			if(m_languageData.entry[i].mask)
			{
				++m_selectedNumber;
			}
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

void VappCbsLanguagePage::languageChangeCallBack(cbsCallbackStruct *callbackData)
{
	
	VappCbsLanguagePage *actionPage = (VappCbsLanguagePage *)VfxObject::handleToObject((VfxObjHandle)callbackData->user_data);
	if (NULL != actionPage)
	{
		actionPage->initLanguageInfo();
		actionPage->m_languageList->reset();
		VFX_OBJ_CLOSE(actionPage->m_processingPopup);
		if (!callbackData->result)
		{
			//actionPage->showErrorConfirm(VFX_WSTR_RES(STR_GLOBAL_FAILED));
			vapp_cbs_show_error_confirm(actionPage, VFX_WSTR_RES(STR_GLOBAL_FAILED), CBS_FAILURE_CONF);
		}
		else
		{
			if (actionPage->isActive())
			{
				actionPage->getMainScr()->popPage();
			}
			else
			{
				VFX_OBJ_CLOSE(actionPage);
			}
		}
	}
};


void VappCbsLanguagePage::onToolBarClick(VfxObject* sender, VfxId id)
{
	switch (id)
	{
		case OK:
        {
		    VFX_OBJ_CREATE(m_processingPopup, VcpIndicatorPopup, this);
            m_processingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
            m_processingPopup->setText((VfxResId)STR_GLOBAL_SAVING);
			m_processingPopup->show(VFX_TRUE);
			
            srv_cbs_select_language(
                &m_languageData,
                vapp_sms_sim_index_to_sim_id(m_SIM),
                languageChangeCallBack,
                getObjHandle());
			
			break;
        }
		case CANCEL:
        {
		    getMainScr()->popPage();
			break;
        }
			
		default:
			//VFX_ASSERT((id == OK) || (id == CANCEL));
			break;
	}
}


void VappCbsLanguagePage::onListItemStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	SRV_BOOL isSelected = ((newState == VCP_LIST_MENU_ITEM_STATE_SELECTED) ? SRV_TRUE : SRV_FALSE);
	if (ALL_INDEX == index)
	{
		if (m_languageData.is_all_on != isSelected)
		{
			for (VfxU32 i = 1; i < m_languageData.total + 1; ++i)
			{
	            m_languageData.entry[i - 1].mask = isSelected;
			}
	        m_languageData.is_all_on = isSelected;

	        m_selectedNumber = ((newState == VCP_LIST_MENU_ITEM_STATE_SELECTED) ? m_languageData.total : 0);

			m_languageList->updateAllItems();
		}
	}
	else 
	{
		if (m_languageData.entry[index - 1].mask != isSelected)
		{
			m_languageData.entry[index - 1].mask= isSelected;
			m_languageList->updateItem(index);
			
			if (isSelected)
			{
	            if (m_selectedNumber < m_languageData.total)
	            {
	                ++m_selectedNumber;
	            }
	            //VFX_ASSERT(m_selectedNumber <= m_languageData.total);
			    if(m_selectedNumber == m_languageData.total)
			    {
					m_languageData.is_all_on = isSelected;
					m_languageList->updateItem(ALL_INDEX);
					m_languageList->updateItem(index);
			    }
			}
			else
			{
				if(m_selectedNumber > 0)
	            {
				    --m_selectedNumber;
	            }

				if (m_languageData.is_all_on != isSelected)
		        {
		            m_languageData.is_all_on = isSelected;
					m_languageList->updateItem(ALL_INDEX);
					m_languageList->updateItem(index);
			    }
			}
		}
	}
    m_toolBar->setDisableItem(OK, VFX_FALSE);
}


void VappCbsLanguagePage::onInit()
{
	VfxPage::onInit();
	VcpTitleBar *tempTitle;
	VFX_OBJ_CREATE(tempTitle, VcpTitleBar, this);
	tempTitle->setTitle((VfxResId)STR_ID_VAPP_CBS_MAIN_LANGUAGES);
    setTopBar(tempTitle);
	
	VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
	m_toolBar->addItem(OK, (VfxResId)STR_GLOBAL_SAVE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
	m_toolBar->addItem(CANCEL, (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	setBottomBar(m_toolBar);
	m_toolBar->m_signalButtonTap.connect(this, &VappCbsLanguagePage::onToolBarClick);

	initLanguageInfo();
	VFX_OBJ_CREATE(m_languageList, VcpListMenu, this);
	m_languageList->setContentProvider(this);
	m_languageList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_languageList->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
	m_languageList->setPos(VfxPoint(0, 0));
	VfxSize parentSize = getSize();
	
	m_languageList->setSize(parentSize);
	m_languageList->m_signalItemSelectionStateChanged.connect(this, &VappCbsLanguagePage::onListItemStateChanged);
    m_languageList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,   // mode for left side
        VFX_FRAME_ALIGNER_MODE_SIDE,    // mode for top side
        VFX_FRAME_ALIGNER_MODE_SIDE,  // mode for right side
        VFX_FRAME_ALIGNER_MODE_SIDE  // mode for bottom side
    );
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


VfxU32 VappCbsLanguagePage::getCount() const
{
	return m_languageData.total + 1;
}

VfxBool VappCbsLanguagePage::getItemIsDisabled(
	VfxU32 index	   // [IN] the index of item
	) const 
{
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
#endif
	return VFX_FALSE;
}

VfxBool VappCbsLanguagePage::getItemText(
	VfxU32 index,					 // [IN] the index of item
	VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
	VfxWString &text,				 // [OUT] the text resource
	VcpListMenuTextColorEnum &color  // [OUT] the text color
	)
{
    switch (fieldType)
    {
	    case VCP_LIST_MENU_FIELD_TEXT:
		    if (index == ALL_INDEX)
		    {
			    text.loadFromRes(STR_ID_VAPP_CBS_LANG_ALL_LANGS);
		    }
		    else
		    {
			    text.loadFromRes(lang_str_id[m_languageData.entry[index - 1].lang_type]);
		    }
		    return VFX_TRUE;

        default:
		    return VFX_FALSE;

    }
};

VcpListMenuItemStateEnum VappCbsLanguagePage::getItemState(	VfxU32 index ) const
{
	
	kal_bool isSelected;
	if (index == ALL_INDEX)
	{
		isSelected = m_languageData.is_all_on;
	}
	else
	{
		isSelected = m_languageData.entry[index - 1].mask;
	}
	return isSelected ? VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}



void VappCbsLanguagePage::onQueryRotateEx(VfxScreenRotateParam & param)
{
}

