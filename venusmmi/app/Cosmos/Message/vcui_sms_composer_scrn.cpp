/*  Copyright Statement:
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
 *  vcui_sms_composer_scrn.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author: Qian Zhao
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_SMS_COMPOSER__
#include "vapp_contact_entry.h"
#include "vapp_contact_list.h"

#include "Vapp_sim_setting_gprot.h"

#include "vcui_sms_composer_scrn.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "CustDataRes.h"

#include "ModeSwitchSrvGprot.h"
#include "GeneralSettingSrvGprot.h"
#include "SimCtrlSrvGprot.h"

#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vcui_sms_composer_def.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
 
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
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
#endif

/******************************************************************************/
/*                          Class VcuiSmsComposer                             */
/******************************************************************************/
VFX_IMPLEMENT_CLASS("VcuiSmsComposer", VcuiSmsComposer, VfxCui);

VcuiSmsComposer::VcuiSmsComposer():
    m_isRotate(VFX_TRUE),
    m_entryData(NULL)        
{
}

void VcuiSmsComposer::onDeinit()
{
    freeEntryData();
    
    VfxCui::onDeinit();    
}

void VcuiSmsComposer::setRotate(VfxBool isRotate)
{
    m_isRotate = isRotate;
}

VcuiSmsComposerEntryStruct *VcuiSmsComposer::getEntryData( ) const
{
    return m_entryData;
}

void VcuiSmsComposer::setEntryData(const VcuiSmsComposerEntryStruct *entryData)
{
  
    freeEntryData();
       
    if (NULL != entryData)
    {    
        VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_SET_ENTRY_DATA_ADDR, 
            entryData->addr_num, NULL == entryData->addr);

        VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_SET_ENTRY_DATA_TEXT, 
            entryData->text_num, NULL == entryData->text_buffer);
            
        VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_SET_ENTRY_DATA_PARA, entryData->operation, 
            entryData->msg_id, entryData->sim_id, entryData->app_id, NULL == entryData->info);
    
        /* alloc new memory to store */
        VFX_ALLOC_MEM(m_entryData, sizeof(VcuiSmsComposerEntryStruct), this);
        vfx_sys_mem_zero(m_entryData, sizeof(VcuiSmsComposerEntryStruct) );
        vfx_sys_mem_copy(m_entryData, entryData, sizeof(VcuiSmsComposerEntryStruct) );

        if (VcuiSmsComposerUtility::getMaxRecipientCount() < entryData->addr_num)
        {
           m_entryData->addr_num = VcuiSmsComposerUtility::getMaxRecipientCount();
        }

        if (VcuiSmsComposerUtility::getMaxContentTextCount() < entryData->text_num)
        {
           m_entryData->text_num = VcuiSmsComposerUtility::getMaxContentTextCount();
        }
        
        if(m_entryData->addr_num > 0)
        {
            VFX_ALLOC_MEM(m_entryData->addr, sizeof(VcuiSmsComposerAddrStruct) * m_entryData->addr_num, this);
            vfx_sys_mem_zero(m_entryData->addr, sizeof(VcuiSmsComposerAddrStruct) * m_entryData->addr_num);
            vfx_sys_mem_copy(m_entryData->addr, entryData->addr, sizeof(VcuiSmsComposerAddrStruct) * m_entryData->addr_num);

            for(VfxS32 i=0;i<m_entryData->addr_num;i++)
            {      
                VfxU16 len = mmi_ucs2strlen((VfxChar*) (entryData->addr[i].addr) );        
                VFX_ALLOC_MEM(m_entryData->addr[i].addr, (sizeof(VfxChar) * (len + 1) * ENCODING_LENGTH) , this);
                MMI_ASSERT(m_entryData->addr[i].addr);
                vfx_sys_mem_zero(m_entryData->addr[i].addr, (sizeof(VfxChar) * (len + 1) * ENCODING_LENGTH));
                vfx_sys_mem_copy(m_entryData->addr[i].addr, entryData->addr[i].addr, (len * ENCODING_LENGTH));
            }
        }
        else
        {
            m_entryData->addr = NULL;
        }
        
        if(m_entryData->text_num > 0)
        {
            VfxU16 len = mmi_ucs2strlen((VfxChar*) (entryData->text_buffer) );
            VFX_ALLOC_MEM(m_entryData->text_buffer, sizeof(VfxChar) * ((len + 1) * ENCODING_LENGTH), this);     
            vfx_sys_mem_zero(m_entryData->text_buffer, sizeof(VfxChar) * ((len + 1) * ENCODING_LENGTH));
            vfx_sys_mem_copy(m_entryData->text_buffer, entryData->text_buffer, sizeof(VfxChar) * (len * ENCODING_LENGTH));       
        }
        else
        {
            m_entryData->text_buffer = NULL;
        }
   }    
    
}

void VcuiSmsComposer::freeEntryData()
{
    /* free memory if exist */
    if(m_entryData)
    {   
        VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_FREE_ENTRY_DATA, m_entryData->addr_num);
        
        for(VfxS32 i=0;i<m_entryData->addr_num;i++)
        {
            VFX_FREE_MEM(m_entryData->addr[i].addr);
        }  
        VFX_FREE_MEM(m_entryData->addr);
        VFX_FREE_MEM(m_entryData->text_buffer);
        VFX_FREE_MEM(m_entryData);    
    }
}

void VcuiSmsComposer::onRun(void * args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);
    
    VcuiSmsComposerScrn *scr;
    VFX_OBJ_CREATE(scr, VcuiSmsComposerScrn, this);
    scr->show ();
}

mmi_ret VcuiSmsComposer::onProc(mmi_event_struct * evt)
{
    return VfxApp::onProc(evt);
}

/******************************************************************************/
/*                          Class VcuiSmsComposerScrn                         */
/******************************************************************************/
// VFX_IMPLEMENT_CLASS ("VcuiSmsComposerScrn", VcuiSmsComposerScrn, VfxMainScr);

void VcuiSmsComposerScrn::on1stReady ()
{
    VfxMainScr::on1stReady ();

    VcuiSmsComposerPage* page = NULL;    
    VFX_OBJ_CREATE (page, VcuiSmsComposerPage, this);
    pushPage (0, page);

    m_pageWeakPtr = page;
	m_isOn2ndReady = VFX_FALSE;  //for APP to Page switch performance
}

void VcuiSmsComposerScrn::on2ndReady()
{	
	VfxMainScr::on2ndReady();
	
	m_isOn2ndReady = VFX_TRUE;  //for APP to Page switch performance

	if(m_pageWeakPtr.isValid())
	{		
		// performance for scrn to scrn		
		VcuiSmsComposerPage *tempPage = m_pageWeakPtr.get();
		if((VFX_FALSE == tempPage->isPageReady()) && 
		   (VFX_FALSE == tempPage->isGettingData()))
		{
		    tempPage->page2ndEnter();	
	    }
	}	
}

VfxBool VcuiSmsComposerScrn::getIsOn2ndReady() //for APP to Page switch performance
{
	return m_isOn2ndReady;
}

/******************************************************************************/
/*                          Class VcuiSmsComposerPage                         */
/******************************************************************************/
// VFX_IMPLEMENT_CLASS("VcuiSmsComposerPage", VcuiSmsComposerPage, VfxPage);

VcuiSmsComposerPage::VcuiSmsComposerPage():
    m_titleBar(NULL),
    m_recipientList(NULL), 
    m_content(NULL),      
    m_form(NULL), 
    m_editor(NULL),
    m_toolBar(NULL),
    m_funcBar(NULL),
    m_curEditor(NULL),   
    m_loading(NULL),
    m_hintText(NULL),
    m_contactlist(NULL),  
    m_waitingPop(NULL),
    m_phbCuiId(0),
    m_itemsAlraedyDraw(0),
    m_backUpitemsAlraedyDraw(0),
    m_cursorIndexToHeighlight(0),    
    m_pbInsertState(VCUI_SMS_COMPOSER_STATE_NONE),
    m_isRotate(VFX_TRUE), 
    m_isPageReady(VFX_FALSE),
    m_isGettingData(VFX_FALSE),
    m_dataProvider(NULL)
{
}

VfxBool VcuiSmsComposerPage::isPageReady()
{
    return m_isPageReady;
}

VfxBool VcuiSmsComposerPage::isGettingData()
{
    return m_isGettingData;
}

VcpContactSelector* VcuiSmsComposerPage::getContactSelector() const
{
    return m_recipientList;
}

void VcuiSmsComposerPage::setRotate(VfxBool isRotate)
{
    m_isRotate = isRotate;
}

void VcuiSmsComposerPage::setContactChange(VcpContactSelector *obj)
{
    VcpContact *list = NULL;
    VcuiSmsComposerResultEnum result = VCUI_SMS_COMPOSER_RESULT_OK;
    
    result = m_dataProvider->resetRecipient();
    if (0 != m_recipientList->getContactCount())
    {      
        list = m_recipientList->getContactList();
        while((NULL != list) && (VCUI_SMS_COMPOSER_RESULT_OK == result))
        {
            result = m_dataProvider->addRecipient((VfxWChar *)list->m_phoneNumber.getBuf());
            list = list->getNext();
        }
    }

    if(VCUI_SMS_COMPOSER_RESULT_OK != result)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            (WCHAR*)GetString(STR_GLOBAL_ERROR));   
    }
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_CONTACT_CHANGE, 
        m_recipientList->getContactCount(), m_dataProvider->getRecipientNum());
}

void VcuiSmsComposerPage::setBounds(const VfxRect &value)
{
	VfxPage::setBounds(value);
	if (m_form != NULL)
	{
		if (m_contactlist != NULL && m_backUpitemsAlraedyDraw != 0)
		{
			VfxSize itemSIze;	
			if ((m_itemsAlraedyDraw & VCUI_SMS_COMPOSER_FORM_RECIPIENT) && m_recipientList)
			{
				itemSIze = m_recipientList->getSize();

			}
			else
			{
				itemSIze.width = 0;
				itemSIze.height = 0;
			}

			VfxSize controlSize;
			controlSize.width = getSize().width;
			controlSize.height = getSize().height - itemSIze.height - m_form->getContentTopGap();
			m_contactlist->setSize(controlSize.width, controlSize.height);
			
			VcpFormItemBase *item = m_form->getItem(VCUI_SMS_COMPOSER_FORM_CONTACT);
			if (item)
			{
				item->setHeight(controlSize.height);
			}
		}
	
        if(m_recipientList)
        {
   			/*for rotation*/
			m_recipientList->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
											VFX_FRAME_ALIGNER_MODE_NONE, 
											VFX_FRAME_ALIGNER_MODE_SIDE,
											VFX_FRAME_ALIGNER_MODE_NONE);
            m_recipientList->checkUpdate();
        }

	    if(m_content)
        {
        	vrt_size_struct mainScreenSize;
        	vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        	m_content->setAutoResized(VFX_TRUE);

        	// If current cursor is last position in content, scroll hintText to view	   
            if((m_curEditor == m_content) && (0 == m_content->getCharAfterCursor()))
            {    
                m_form->scrollItemToView(VCUI_SMS_COMPOSER_FORM_HINT, VCPFORM_SCROLL_BOTTOM);   
            }  
        } 
	}
}

void VcuiSmsComposerPage::page2ndEnter()
{  
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_2ND_ENTER);

    m_isPageReady = VFX_TRUE;

    /* form */
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize().width, getSize().height);
    m_form->setPos(0, 0);
    m_form->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE);

    /* first custom form of recipient selector */
    VcpFormItemCustomFrame *recipientListBg;
    VFX_OBJ_CREATE(recipientListBg, VcpFormItemCustomFrame, m_form);
    VFX_OBJ_CREATE(m_recipientList, VcpContactSelector, recipientListBg);
    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    m_recipientList->setBounds(VfxRect(0, 0, (mainScreenSize.width - 2 * VCUI_SMS_COMPOSER_LEFT_MARGIN), 
        VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_TOP_GAP + VCP_CONTACT_SELECTOR_BUTTOM_GAP));
    m_recipientList->setPos(VCUI_SMS_COMPOSER_LEFT_MARGIN, 0);
    m_recipientList->setHintText(VFX_WSTR_RES(STR_ID_VCUI_SMSC_TO_AS_HINT));
    m_recipientList->m_signalSearchButtonClicked.connect(this, &VcuiSmsComposerPage::onSearchButtonClicked);
    m_recipientList->m_signalMoreButtonClicked.connect(this, &VcuiSmsComposerPage::onMoreButtonClicked);   
    m_recipientList->m_signalBoundsChanged.connect(this, &VcuiSmsComposerPage::onFormItemBoundsChanged);
    m_recipientList->m_signalContactChanged.connect(this, &VcuiSmsComposerPage::onRecipientListNumChanged);   
    m_recipientList->m_signalTextChanged.connect(this, &VcuiSmsComposerPage::onRecipientListTextChanged);
    m_editor = m_recipientList->getInputbox();                        
    m_editor->setText(VFX_WSTR_EMPTY, VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN); 
    m_editor->m_signalBeforeChange.connect(this, &VcuiSmsComposerPage::onToEditorBeforeChange); 
    m_editor->setEnterKeyStyle(IME_VK_ENTER_KEY_STYLE_DONE);
	m_editor->setEnterKeyEnabled(VFX_FALSE);
    m_editor->m_signalEnterKeyClicked.connect(this, &VcuiSmsComposerPage::onToEditerEnterKeyClicked);
    m_editor->m_signalActivated.connect(this, &VcuiSmsComposerPage::onTextEditorActivated);
    recipientListBg->attachCustomFrame(m_recipientList);
    recipientListBg->setHeight(m_recipientList->getSize().height);  
    m_recipientList->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_NONE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_NONE);

    /* second custom form of content */
    VcpFormItemCustomFrame *contentBg;
    VFX_OBJ_CREATE(contentBg, VcpFormItemCustomFrame, m_form);
    VFX_OBJ_CREATE(m_content, VcpTextEditor, contentBg);   
    m_content->setText(m_dataProvider->getContentDataBuffer(), 
        VcuiSmsComposerUtility::getMaxContentTextCount(), VFX_TRUE);   
    m_content->setAutoAnimate(VFX_TRUE);
    m_content->setUnderline(VFX_TRUE);
    m_content->disableBackground(VFX_TRUE);
    m_content->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_content->setColor(VCP_TEXT_HINT_TEXT_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));    
    m_content->setColor(VCP_TEXT_UNDERLINE_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_LINK));
    m_content->setMinLineHeight(VCUI_SMS_COMPOSER_MSG_VIEW_CONT_LINE_HEIGHT);
    m_content->setSize(
        getSize().width - (2 * VCUI_SMS_COMPOSER_LEFT_MARGIN), VCUI_SMS_COMPOSER_STANDARD_BTN_HEIGHT);
    m_content->setPos(VCUI_SMS_COMPOSER_LEFT_MARGIN, 0);
    m_content->setAutoResized(VFX_TRUE);
    m_content->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    m_content->setHint(STR_ID_VCUI_SMSC_TXT_EDITOR_HINT_ID);
    m_content->setCounterDisplayMode(VCP_TEXT_COUNTER_DISP_HIDE);
    m_content->m_signalBoundsChanged.connect(this, &VcuiSmsComposerPage::onFormItemBoundsChanged);
    m_content->m_signalTextChanged.connect(this, &VcuiSmsComposerPage::onContentTextChanged);    
    m_content->m_signalActivated.connect(this, &VcuiSmsComposerPage::onTextEditorActivated);
    contentBg->attachCustomFrame(m_content);
    contentBg->setHeight(VCUI_SMS_COMPOSER_STANDARD_BTN_HEIGHT + VCPFRM_ITEM_HORZ_GAP);
    m_content->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE);

    /* third custom form of content */
    VcpFormItemCustomFrame *hintTextBg;
    VFX_OBJ_CREATE(hintTextBg, VcpFormItemCustomFrame, m_form);
    VFX_OBJ_CREATE(m_hintText, VfxTextFrame, hintTextBg);
    m_hintText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_1)));
	m_hintText->setAnchor(1,0);
    m_hintText->setPos(m_form->getSize().width - VCUI_SMS_COMPOSER_LEFT_MARGIN, 0);
    m_hintText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
    m_hintText->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
    hintTextBg->attachCustomFrame(m_hintText);
    hintTextBg->setHeight(m_hintText->getSize().height);
    m_hintText->setSize(m_form->getSize().width - (VCUI_SMS_COMPOSER_LEFT_MARGIN * 2), 
        m_hintText->getSize().height);
    // must set auto resize after setsize, because hintText use default height.
	m_hintText->setAutoResized(VFX_FALSE); 
    m_hintText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE); 
    updateHintText();
    
    // functionBar
    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);
    m_funcBar->addItem((VfxResId)STR_GLOBAL_SEND, (VfxId)VCUI_SMS_COMPOSER_FUNC_BAR_SEND);
    m_funcBar->setItemSpecial(VCUI_SMS_COMPOSER_FUNC_BAR_SEND);
    m_funcBar->m_signalButtonTap.connect(this, &VcuiSmsComposerPage::onFunctionBarClicked);
    m_content->setFunctionBar(m_funcBar);
	m_editor->setFunctionBar(m_funcBar);

    /* add custom form item to form base */
    m_form->addItem(recipientListBg, VCUI_SMS_COMPOSER_FORM_RECIPIENT);
    m_form->addItem(contentBg, VCUI_SMS_COMPOSER_FORM_CONTENT);    
    m_form->addItem(hintTextBg, VCUI_SMS_COMPOSER_FORM_HINT);
    m_itemsAlraedyDraw |= VCUI_SMS_COMPOSER_FORM_RECIPIENT; 
    m_itemsAlraedyDraw |= VCUI_SMS_COMPOSER_FORM_CONTENT;
	m_itemsAlraedyDraw |= VCUI_SMS_COMPOSER_FORM_HINT;  
	
    m_toolBar->setIsUnhittable(VFX_FALSE);
    
    setTextEditorAutoActivated();
    
    updateToggleBar();
}

void VcuiSmsComposerPage::onInit()
{
    VfxPage::onInit();    
   
	VcuiSmsComposer* app = (VcuiSmsComposer*) getApp();
    VcuiSmsComposerEntryStruct * entryData= app->getEntryData();       
    VFX_OBJ_CREATE(m_dataProvider,VcuiSmsComposerDataProvider, this);
    m_dataProvider->m_signalRefresh.connect(this, &VcuiSmsComposerPage::onDataRefreshHdlr);	
    m_isGettingData = m_dataProvider->setEntryData(entryData);

    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_ONINIT, NULL == entryData, m_isGettingData);

    // titleBar
    createTitleBar();

    // toolBar
    createToolBar();

    if(!entryData && !m_isGettingData)
    {
        // UM new message
        page2ndEnter();   
    }

    if(m_isGettingData)
    {
        VFX_OBJ_CREATE(m_loading, VcpActivityIndicator, this);
        m_loading->setHiddenWhenStopped(VFX_TRUE);
    	m_loading->setPos(getSize().width/2 - m_loading->getSize().width/2, 
    	    getSize().height/2 - m_loading->getSize().height/2);
    	m_loading->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID);
        m_loading->start();        
    }
}

void VcuiSmsComposerPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
}

void VcuiSmsComposerPage::onEntered()
{
    VfxPage::onEntered();
}

void VcuiSmsComposerPage::onDeinit()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_ONDEINIT);

    if(m_loading)
    {
        m_loading->stop();  
        m_loading = NULL;                   
    }  

    if(m_waitingPop)
    {
        VFX_OBJ_CLOSE(m_waitingPop);
        m_waitingPop = NULL;   
    }

    VfxPage::onDeinit();
}

void VcuiSmsComposerPage::onUpdate()
{
    VfxPage::onUpdate();
}

mmi_ret VcuiSmsComposerPage::onProc(mmi_event_struct *evt)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_ONPROC);
    
	VfxBool need_set_active_vk = VFX_FALSE;

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PHB_LIST_RESULT:
        {
            if (GRP_ID_INVALID != m_phbCuiId)
            {
                vcui_phb_list_result_event_struct *phBookEvt = 
                    (vcui_phb_list_result_event_struct*)evt;

                VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_ONPROC_RESULT, 
                    phBookEvt->result, m_phbCuiId, m_pbInsertState);

                if (phBookEvt->result > 0)
                {                              
                    if (VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NUM == m_pbInsertState ||
                        VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NAME == m_pbInsertState)
                    {
                        VfxWChar *buff = NULL;  
                        VfxU16 buffLen = 
                            (VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN + 1) * ENCODING_LENGTH;

                        VFX_ALLOC_MEM(buff, buffLen, this);
                        if (VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NUM == m_pbInsertState)
                        {
                          vcui_phb_list_get_selected_contact_data_by_index(
                            m_phbCuiId, buff , buffLen , 0);
                        }
                        else if (VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NAME == m_pbInsertState)
                        {
                           vcui_phb_list_get_selected_contact_name_by_index(
                            m_phbCuiId, buff, buffLen, 0);
                        }

                        insertContentText((VfxWChar*)buff, VFX_FALSE);
                        need_set_active_vk = VFX_TRUE;
                        VFX_FREE_MEM(buff);             
                    }
                    else if (VCUI_SMS_COMPOSER_STATE_INSERT_ADDRESS == m_pbInsertState)
                    {
                        handleAddrInsertionEvent(phBookEvt->select_count);
                    }
                }
                vcui_phb_list_close(m_phbCuiId);
                m_phbCuiId = 0;  
            }            
            break;
        }    
        default:
            break;
     }

	if(need_set_active_vk)
	{
		setContentTextEditorActive();
	}

    return VfxPage::onProc(evt);
}

void VcuiSmsComposerPage::onBack()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_ONBACK);

    postEventToCaller(EVT_ID_CUI_SMS_COMPOSER_CLOSE);
}

void VcuiSmsComposerPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void VcuiSmsComposerPage::onRotate(const VfxScreenRotateParam &param)
{
    VfxPage::onRotate(param);
    
    updateToggleBar(); 
}

void VcuiSmsComposerPage::onFunctionBarClicked (VfxObject *sender, VfxId id)
{
    if(NULL == sender || m_funcBar != sender)
    {
        return;
    }
        
    switch(id)
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
        case VCUI_SMS_COMPOSER_FUNC_BAR_SEND:
            clickSendButton();
            break;
        case VCUI_SMS_COMPOSER_FUNC_BAR_INSERT:
            clickInsertButton();
            break;
        default:
            break;
    }
}

void VcuiSmsComposerPage::onToolBarClicked(VfxObject *obj, VfxId id)
{
    if(NULL == obj || m_toolBar != obj)
    {
        return;
    }
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_TOOLBAR_CLICK, id);

    switch(id)
    {
	    case VCUI_SMS_COMPOSER_TOOLBAR_SEND:	
            clickSendButton();
	        break;
    	case VCUI_SMS_COMPOSER_TOOLBAR_SAVE:	
            clickSaveButton();
    	    break;
        case VCUI_SMS_COMPOSER_TOOLBAR_SWITCH_SIM:
            clickSwitchSimButton();
    		break;
        case VCUI_SMS_COMPOSER_TOOLBAR_INSERT:    
            clickInsertButton();
            break;
        default:
            break;
	}
}

void VcuiSmsComposerPage::onCommandPopClicked(VfxObject *obj, VfxId id)
{
    if(NULL == obj)
    {
        return;

    }

    switch(id)
    {
    	case VCUI_SMS_COMPOSER_POP_SIM1:
        case VCUI_SMS_COMPOSER_POP_SIM2:	
        case VCUI_SMS_COMPOSER_POP_SIM3:	
        case VCUI_SMS_COMPOSER_POP_SIM4:
        {
            m_dataProvider->setSimId((mmi_sim_enum)id);

            updateTitleBar();
            updateToolBar();
            updateFunctionBar();            
            updateToggleBar();
            
			VfxU16 sim_buffer[50] = {0,};
            VcuiSmsComposerUtility::getSwitchSimStr(sim_buffer, m_dataProvider->getSimId());
			mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
			    MMI_EVENT_INFO_BALLOON, 
			    MMI_NMGR_BALLOON_TYPE_INFO,
			    (WCHAR*)(sim_buffer));			    
            break;
        }
        case VCUI_SMS_COMPOSER_POP_PHB_NUM:    
        case VCUI_SMS_COMPOSER_POP_PHB_NAME:
        {           
            if (VCUI_SMS_COMPOSER_POP_PHB_NAME == id)
            {
                m_pbInsertState = VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NAME;   
                openPhbCui(VFX_FALSE, MMI_PHB_CONTACT_FIELD_NAME);
            }
            else
            {
                m_pbInsertState = VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NUM;  
                openPhbCui(VFX_FALSE, MMI_PHB_CONTACT_FIELD_NUMBER);
            }           
            break;
        }        
        default :
            break;
    }
}

void VcuiSmsComposerPage::onConfirmPopClicked(VfxObject* obj, VfxId id)
{
    if(VCP_CONFIRM_POPUP_BUTTON_YES == id)
    {
        m_dataProvider->setSimId(VcuiSmsComposerUtility::getValidSimToSend());
        
        updateTitleBar();
        updateToolBar();
        updateFunctionBar();            
        updateToggleBar();

        if(!(m_dataProvider->getSimId() & VcuiSmsComposerUtility::getBlockedSim()))
        {
            sendSms();
        }
        else
        {
            VfxResId strId = 0;
            switch(m_dataProvider->getSimId())
            {
                case MMI_SIM1:
                    strId = STR_ID_VCUI_SMSC_BLOCKED_SIM1_ID;
                    break;
                case MMI_SIM2:
                    strId = STR_ID_VCUI_SMSC_BLOCKED_SIM2_ID;
                    break;
                case MMI_SIM3:
                    strId = STR_ID_VCUI_SMSC_BLOCKED_SIM3_ID;
                    break;
                case MMI_SIM4:
                    strId = STR_ID_VCUI_SMSC_BLOCKED_SIM4_ID;
                    break;                    
            }
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_FAILURE, 
                (WCHAR*)GetString(strId));
        }
    }
}

void VcuiSmsComposerPage::onSearchButtonClicked()
{
	if (m_recipientList->getContactCount() >= VcuiSmsComposerUtility::getMaxRecipientCount())
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
		    MMI_EVENT_INFO_BALLOON, 
		    MMI_NMGR_BALLOON_TYPE_FAILURE, 
		    (WCHAR*)GetString(STR_ID_VCUI_SMSC_RECIPIENT_NUMBER_EXCEED_ID));
		return;
	}
    m_pbInsertState = VCUI_SMS_COMPOSER_STATE_INSERT_ADDRESS;
    openPhbCui(VFX_TRUE,  MMI_PHB_CONTACT_FIELD_NUMBER);    
}

void VcuiSmsComposerPage::onFormItemBoundsChanged(VfxFrame *obj, const VfxRect &rect)
{
    if(NULL == obj || (m_recipientList != obj && m_content != obj))
    {
        return;
    }

    if (obj->getSize().height != rect.getHeight())
    {   
        VcpFormItemCustomFrame *formBg = (VcpFormItemCustomFrame *)obj->getParentFrame();
        formBg->setHeight(obj->getSize().height);
        if (VCUI_SMS_COMPOSER_FORM_RECIPIENT == formBg->getId())
        {            
            formBg->setHeight(obj->getSize().height);
        }
        else if (VCUI_SMS_COMPOSER_FORM_CONTENT == formBg->getId())
        {  
        	// If current cursor is last position in content, scroll hintText to view	   
            if((m_curEditor == m_content) && (0 == m_content->getCharAfterCursor()))
            {    
                // scroll hintText to view when content bound increased.
                if(obj->getSize().height > rect.getHeight())
                {
                    m_form->scrollItemToView(
                        VCUI_SMS_COMPOSER_FORM_HINT, VCPFORM_SCROLL_BOTTOM, VFX_FALSE);  
                }
            }             
            // formBg->setHeight(obj->getSize().height + VCPFRM_ITEM_HORZ_GAP/2);            
            formBg->setHeight(obj->getSize().height);
        }
    }
}

void VcuiSmsComposerPage::onContentTextChanged(VcpTextEditor *obj)
{
    if(NULL == obj || m_content != obj)
    {
        return;
    }

    updateHintText();
    
/*
    updateToolBar();
    updateFunctionBar();
 */
}

void VcuiSmsComposerPage::onRecipientListNumChanged(VcpContactSelector *obj, VcpContactChangedEnum state)
{
    if(NULL == obj || m_recipientList != obj)
    {
        return;
    }

    if (VCP_CONTACT_CHANGED_DELETE == state)
    {
        setContactChange(obj);
    }
    
    updateToolBar();
    updateFunctionBar();
}

void VcuiSmsComposerPage::onMoreButtonClicked(VcpContactSelector *obj)
{
    if(NULL == obj || m_recipientList != obj)
    {
        return;
    }

    /* entry another page to show the recipient list */
    VcuiSmsComposerRecipientPage *recipient = NULL;
    VFX_OBJ_CREATE_EX(recipient, VcuiSmsComposerRecipientPage, this, (this));
    recipient->setRotate(m_isRotate);
    getMainScr()->pushPage(VFX_ID_NULL, recipient);
}

void VcuiSmsComposerPage::onRecipientListTextChanged(VcpContactSelector *obj, VfxWChar *text)
{
    if(NULL == obj || m_recipientList != obj)
    {
        return;
    }
        
	if (vfx_sys_wcslen(text) == 0)
	{
        m_recipientList->hideContact(VFX_FALSE);
        m_recipientList->getInputbox()->setEnterKeyEnabled(VFX_FALSE);
        
		/*No Text so show all control*/
		if (m_backUpitemsAlraedyDraw)
		{
    		if(NULL != m_contactlist)
    		{
    			m_form->removeItem(VCUI_SMS_COMPOSER_FORM_CONTACT);	
    			m_form->scrollItemToView(VCUI_SMS_COMPOSER_FORM_RECIPIENT, VCPFORM_SCROLL_BOTTOM);	
    		}
            m_contactlist = NULL;	

			hideUnhideFormItem(VCUI_SMS_COMPOSER_FORM_CONTACT , VFX_TRUE);
			hideUnhideFormItem(m_backUpitemsAlraedyDraw , VFX_FALSE);
			m_itemsAlraedyDraw = m_backUpitemsAlraedyDraw;
			m_backUpitemsAlraedyDraw = 0;
			
    		m_form->scrollItemToView(VCUI_SMS_COMPOSER_FORM_RECIPIENT, VCPFORM_SCROLL_BOTTOM);	
		}
	}
	else if (m_contactlist == NULL)
	{
		VcpFormItemBase *selectedItem = m_form->getItem(VCUI_SMS_COMPOSER_FORM_RECIPIENT);
		VfxSize formSize = m_form->getSize();
		VfxSize ItemSize = selectedItem->getSize();
		VfxSize controlSize;
		controlSize.width = formSize.width;
		controlSize.height = formSize.height - ItemSize.height - m_form->getContentTopGap();	
		controlSize.height = (controlSize.height >= 0)? controlSize.height: 0;
		
		VcpFormItemCustomFrame *frame_part = NULL;
		VFX_OBJ_CREATE(frame_part, VcpFormItemCustomFrame, m_form);
		VFX_OBJ_CREATE_EX(m_contactlist, 
		    VcuiSmsComposerContactList, frame_part, (vfx_sys_wcslen(text)));
		m_contactlist->setSize(controlSize.width, controlSize.height); /*for rotation*/
		m_contactlist->m_signalListUpdated.connect(this, &VcuiSmsComposerPage::onContactListUpdate);		
	    m_contactlist->setAlignField(MMI_PHB_CONTACT_FIELD_NUMBER);
		m_contactlist->setSearchString(VFX_WSTR_MEM(text));			
		m_contactlist->getList();				
		frame_part->setHeight(controlSize.height);
		frame_part->attachCustomFrame(m_contactlist);
		frame_part->setIsHidden(VFX_TRUE);
        m_recipientList->getInputbox()->setEnterKeyEnabled(VFX_TRUE);
		m_contactlist->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_NONE, 
						VFX_FRAME_ALIGNER_MODE_SIDE,
						VFX_FRAME_ALIGNER_MODE_NONE);
						
        m_form->addItem(frame_part, VCUI_SMS_COMPOSER_FORM_CONTACT);
	}
	else
	{
		m_contactlist->updateHintList(text);
        m_recipientList->getInputbox()->setEnterKeyEnabled(VFX_TRUE);
	}
	
    updateToolBar();
    updateFunctionBar();
}

void VcuiSmsComposerPage::onContactListUpdate(VfxU32 count)
{
    if(NULL == m_contactlist)
    {
        return;
    }

	if (count == 0)
	{
		if (m_backUpitemsAlraedyDraw != 0)
		{
			hideUnhideFormItem(VCUI_SMS_COMPOSER_FORM_CONTACT , VFX_TRUE);
			hideUnhideFormItem(m_backUpitemsAlraedyDraw , VFX_FALSE);
			m_itemsAlraedyDraw = m_backUpitemsAlraedyDraw;
			m_backUpitemsAlraedyDraw = 0;
			
			m_recipientList->hideContact(VFX_FALSE);
			m_form->scrollItemToView(VCUI_SMS_COMPOSER_FORM_RECIPIENT, VCPFORM_SCROLL_BOTTOM);			
		}	
	}
	else
	{
		if (!(m_itemsAlraedyDraw & VCUI_SMS_COMPOSER_FORM_CONTACT) && 
		    m_contactlist && m_contactlist->isMenuListActivated())
		{
			/*If meulist is not drawn draw it now*/
			hideUnhideFormItem((m_itemsAlraedyDraw & ~VCUI_SMS_COMPOSER_FORM_RECIPIENT), VFX_TRUE);
			hideUnhideFormItem(VCUI_SMS_COMPOSER_FORM_CONTACT, VFX_FALSE);
			m_backUpitemsAlraedyDraw = m_itemsAlraedyDraw;
			m_itemsAlraedyDraw = VCUI_SMS_COMPOSER_FORM_RECIPIENT | VCUI_SMS_COMPOSER_FORM_CONTACT;
		
			m_recipientList->hideContact(VFX_TRUE);	
			VfxSize controlSize;
			VfxSize formSize = m_form->getSize();
			VfxSize itemSize = m_form->getItem(VCUI_SMS_COMPOSER_FORM_RECIPIENT)->getSize();
			controlSize.width = formSize.width;
			controlSize.height = formSize.height - itemSize.height - m_form->getContentTopGap();
			m_contactlist->setSize(controlSize.width, controlSize.height);			
			m_contactlist->setTappedHandler(this, &VcuiSmsComposerPage::onContactlistItemTap);
			VcpFormItemBase *item = m_form->getItem(VCUI_SMS_COMPOSER_FORM_CONTACT);
			if (item)
			{			
                item->setIsHidden(VFX_FALSE);
				item->setHeight(controlSize.height);
			}			
		}
	}
}

void VcuiSmsComposerPage::onContactlistItemTap(VcpListMenu *listMenu, VfxU32 itemIndex)
{
    if(NULL == listMenu)
    {
        return;
    }

	VfxWChar *buff = NULL;
	VappContactNumber num;
	VcuiSmsComposerAddressTypeEnum addrType = VCUI_SMS_COMPOSER_ADDRESS_TYPE_TOTAL_NUM;

	ContactList* contactList = m_contactlist->getContactList();
    ContactEntry entry(contactList->getId(itemIndex));
    VfxU32 type = contactList->getType(itemIndex);
    VfxU32 subId = contactList->getSubId(itemIndex);
    
    switch(type)
    {
	    case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
		{		
            addrType =  VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER;
		    num = entry.getNumberById(subId);
		    buff = num.getBuf();
		    if(!VcuiSmsComposerUtility::checkIsAsciiString((VfxU8*) buff) || 
		       !VcuiSmsComposerUtility::checkIsPhoneNum((VfxU8*)buff))
		    {
			    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
			        MMI_EVENT_INFO_BALLOON, 
			        MMI_NMGR_BALLOON_TYPE_FAILURE,
			        (WCHAR*)GetString(STR_ID_VCUI_SMSC_INVALID_RECIPIENT));
			    return;
		    }
			else if(mmi_ucs2strlen((CHAR *)buff) > VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
				    MMI_EVENT_INFO_BALLOON, 
				    MMI_NMGR_BALLOON_TYPE_FAILURE,
				    (WCHAR*)GetString(STR_ID_VCUI_SMSC_NUMBER_LENGTH_EXCEED_ID));
			    return;					
			}			
            break;
	    }	    
	    default :		    
	        break;
    }
    
    VappContactName contactName = entry.getName();
    if (mmi_ucs2strlen((CHAR*)contactName.getString().getBuf()) > 0)
    {
        insertRecipientAddr(contactName.getString().getBuf(), buff, addrType);
    }
    else
    {       
        insertRecipientAddr(NULL, buff, addrType);
    }
	
    restoreFormItem();
}

void VcuiSmsComposerPage::onToEditorBeforeChange(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret)
{
    if(NULL == m_editor)
    {
        return;
    }

    if (type == VCP_TEXT_CHANGE_INSERT_CHAR)
    {
    	if (m_recipientList->getContactCount() >= VcuiSmsComposerUtility::getMaxRecipientCount())
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_FAILURE, 
                (WCHAR*)GetString(STR_ID_VCUI_SMSC_RECIPIENT_NUMBER_EXCEED_ID));
            *ret = VFX_FALSE;
            return;
        }
        
        if(10 == text[0])
        {
            VfxWChar *addrStr = m_editor->getText();
            if(0 != vfx_sys_wcslen(addrStr))
            {       
                insertRecipientAddr(NULL, addrStr, VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER);
                
                m_recipientList->hideContact(VFX_FALSE);                
		        restoreFormItem();
            }
            *ret = VFX_FALSE;
        }
        *ret = VFX_TRUE;
    }
}

void VcuiSmsComposerPage::onToEditerEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle)
{
    // Tap EnterKey not clear editor (follow UC UE)
	if (NULL == editor || m_editor != editor)
	{
		return;
	}

	if (m_recipientList->getContactCount() >= VcuiSmsComposerUtility::getMaxRecipientCount())
	{
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)GetString(STR_ID_VCUI_SMSC_RECIPIENT_NUMBER_EXCEED_ID));    
		return;
	}
	
    VfxWChar *addrStr = m_editor->getText();
    if(vfx_sys_wcslen(addrStr) != 0)
    {
        if (VcuiSmsComposerUtility::checkIsAsciiString((VfxU8*) addrStr) && 
            VcuiSmsComposerUtility::checkIsPhoneNum((VfxU8*)addrStr))
        {      		
			if(mmi_ucs2strlen((CHAR *)addrStr) > VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
				    MMI_EVENT_INFO_BALLOON, 
				    MMI_NMGR_BALLOON_TYPE_FAILURE, 
				    (WCHAR*)GetString(STR_ID_VCUI_SMSC_NUMBER_LENGTH_EXCEED_ID));			    					
			}
			else
            {
                insertRecipientAddr(NULL, addrStr, VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER);
                m_recipientList->hideContact(VFX_FALSE);
                restoreFormItem();
            }
        }
        else
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_FAILURE, 
                (WCHAR*)GetString(STR_ID_VCUI_SMSC_INVALID_RECIPIENT));     
        }
    }
}

void VcuiSmsComposerPage::onTextEditorActivated(VcpTextEditor *editor, VfxBool activated)
{
	if (NULL == editor || (m_editor != editor && m_content != editor))
	{
		return;
	}
   
    if ((editor == m_editor)  && (VFX_FALSE == activated))
    {
        VfxWChar *addrStr = m_editor->getText();

        if(0 != vfx_sys_wcslen(addrStr))
        {
            if((1 == vfx_sys_wcslen(addrStr)) && (10 == addrStr[0]))
            {
                // skip
            }
            else
            {                
                insertRecipientAddr(NULL, addrStr, VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER);
            }
        }
        
    	if(m_contactlist && m_contactlist->isMenuListActivated())
    	{
    	    restoreFormItem();
    	}
    }


    if(activated && (editor == m_content))
    {    
        m_form->scrollItemToView(VCUI_SMS_COMPOSER_FORM_HINT, VCPFORM_SCROLL_BOTTOM);   
    }
    
    if (activated)
    {   
        m_curEditor = editor;
        updateFunctionBar();   
    }
    else
    {        
        m_curEditor = NULL;       
        updateToolBar();
    } 
}

void VcuiSmsComposerPage::onDataRefreshHdlr(VcuiSmsComposerRefreshTypeEnum refresh_type, VcuiSmsComposerResultEnum result)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_DATA_REFRESH_HDLR, refresh_type, result);

    switch(refresh_type)
    {     
        case VCUI_SMS_COMPOSER_SENDING_SMS_DONE:            
            handleSendDoneEvent(result);           
            break;
        case VCUI_SMS_COMPOSER_SAVING_SMS_DONE:
            handleSaveDoneEvent(result);
            break;
        case VCUI_SMS_COMPOSER_LOADING_DATA_DONE:
            handleDataReadyEvent(result);
            break;
        case VCUI_SMS_COMPOSER_SIM_REFRESH:
            handleSimRefreshEvent(result);
            break;
        case VCUI_SMS_COMPOSER_NEED_CLOSE_APP:
            handleCloseAppEvent(result);
            break;   
        default:
            break;
    }
}

void VcuiSmsComposerPage::createTitleBar()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_CREATE_TITLEBAR, m_dataProvider->getSimId());

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    VfxU16 *titleText = NULL;
    VFX_ALLOC_MEM(titleText, sizeof(VfxU16) * 50, this);
    memset(titleText, 0, 50);
    VcuiSmsComposerUtility::getTitleBarStr(titleText, m_dataProvider->getSimId());
    m_titleBar->setTitle((VfxWChar*)titleText);
    setTopBar(m_titleBar);    
    VFX_FREE_MEM(titleText);
}

void VcuiSmsComposerPage::createToolBar()
{
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this); 
    m_toolBar->addItem(VCUI_SMS_COMPOSER_TOOLBAR_INSERT, STR_ID_VCUI_SMSC_INSERT_ID, IMG_ID_VCUI_SMSC_INSERT_ID);    
#if (MMI_MAX_SIM_NUM >= 2)
    if (VcuiSmsComposerUtility::getAllSimCount() >=2)
    {
        m_toolBar->addItem(VCUI_SMS_COMPOSER_TOOLBAR_SWITCH_SIM, STR_ID_VCUI_SMSC_SWITCH_SIM_ID, IMG_ID_VCUI_SMSC_SWITCH_SIM_ID); 
    }
#endif
    m_toolBar->addItem(VCUI_SMS_COMPOSER_TOOLBAR_SAVE, STR_GLOBAL_SAVE, IMG_ID_VCUI_SMSC_SAVE_AS_ID);
    m_toolBar->addItem(VCUI_SMS_COMPOSER_TOOLBAR_SEND, STR_GLOBAL_SEND, IMG_ID_VCUI_SMSC_SEND_ID);
    m_toolBar->m_signalButtonTap.connect(this, & VcuiSmsComposerPage::onToolBarClicked);    
    m_toolBar->setIsUnhittable(VFX_TRUE);
    setBottomBar(m_toolBar);
}

void VcuiSmsComposerPage::updateToolBar()
{
    if(NULL == m_recipientList || NULL == m_editor ||
       NULL == m_funcBar || NULL == m_toolBar)
    {
        return;
    }
    
    // if ((0 == m_recipientList->getContactCount() && 0 == vfx_sys_wcslen(m_editor->getText())) ||
    //    (VFX_FALSE == isSendButtonValid()))
    if(VFX_FALSE == isSendButtonValid())
    {
        m_funcBar->setDisableItem(VCUI_SMS_COMPOSER_FUNC_BAR_SEND, VFX_TRUE);
        m_toolBar->setDisableItem(VCUI_SMS_COMPOSER_TOOLBAR_SEND, VFX_TRUE);
    }
    else
    {
        m_funcBar->setDisableItem(VCUI_SMS_COMPOSER_FUNC_BAR_SEND, VFX_FALSE);
        m_toolBar->setDisableItem(VCUI_SMS_COMPOSER_TOOLBAR_SEND, VFX_FALSE);
    }
}

void VcuiSmsComposerPage::updateFunctionBar()
{
    if(NULL == m_funcBar || NULL == m_recipientList || 
       NULL == m_editor || NULL == m_content)
    {
        return;

    }
    
    if(m_curEditor == m_editor)
    {
        m_funcBar->removeItem(VCUI_SMS_COMPOSER_FUNC_BAR_INSERT);
        // m_funcBar->addItem((VfxResId)STR_GLOBAL_NEXT, (VfxId)VCUI_SMS_COMPOSER_FUNC_BAR_NEXT);
        // m_funcBar->setDisableItem(VCUI_SMS_COMPOSER_FUNC_BAR_NEXT, VFX_FALSE);
    }
    else if(m_curEditor == m_content)
    {
        // m_funcBar->removeItem(VCUI_SMS_COMPOSER_FUNC_BAR_NEXT);
        m_funcBar->addItem((VfxResId)STR_ID_VCUI_SMSC_INSERT_ID, (VfxId)VCUI_SMS_COMPOSER_FUNC_BAR_INSERT);
        m_funcBar->setDisableItem(VCUI_SMS_COMPOSER_FUNC_BAR_INSERT, VFX_FALSE); 
    }
    
    // if ((0 == m_recipientList->getContactCount() && 0 == vfx_sys_wcslen(m_editor->getText())) ||
    //    (VFX_FALSE == isSendButtonValid()))
    if(VFX_FALSE == isSendButtonValid())
    {
        m_funcBar->setDisableItem(VCUI_SMS_COMPOSER_FUNC_BAR_SEND, VFX_TRUE);
    }
    else
    {
        m_funcBar->setDisableItem(VCUI_SMS_COMPOSER_FUNC_BAR_SEND, VFX_FALSE);
    }
}

void VcuiSmsComposerPage::updateHintText()
{
    if(NULL == m_hintText || NULL == m_content || NULL == m_dataProvider)
    {
        return;
    }
    
    VfxS32 remain_character, current_segment, max_character, max_character_in_one_segment;
    m_dataProvider->getSmsTextInfoNum(remain_character,
        current_segment, max_character, max_character_in_one_segment);
    
    VfxChar *text_buffer = NULL;
    VFX_ALLOC_MEM(text_buffer, sizeof(VfxChar) * 50, this);
    memset(text_buffer, 0, sizeof(VfxChar) * 50);
    VcuiSmsComposerUtility::getHintTextStr(remain_character,
        current_segment, max_character_in_one_segment, text_buffer);    
    m_hintText->setString((const VfxWChar *)text_buffer);      
    VFX_FREE_MEM(text_buffer);

    // update content MaxLength
    m_content->setMaxLength(max_character);
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_UPDATE_HINTTEXT, 
        remain_character, current_segment, max_character, max_character_in_one_segment);
}

void VcuiSmsComposerPage::updateToggleBar(void)
{
    if(NULL == m_titleBar || NULL == m_dataProvider)
    {
        return;
    }
    
	if (getRotate() == VFX_SCR_ROTATE_TYPE_LANDSCAPE || getRotate() == VFX_SCR_ROTATE_TYPE_270 ||
		getRotate() == VFX_SCR_ROTATE_TYPE_90)
	{
        toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_FALSE);
        
		if(VcuiSmsComposerUtility::getValidSim())
		{
			VfxU16 text_buffer[50] = {0,};
			VcuiSmsComposerUtility::getSendButtonStr(text_buffer, m_dataProvider->getSimId());
			if(m_funcBar)
			{		
                m_funcBar->changeItem(VCUI_SMS_COMPOSER_FUNC_BAR_SEND, (VfxWChar*)text_buffer);
			}
		}
	}
	else
	{
		toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_TRUE);	
		if(m_funcBar)
		{		
            m_funcBar->changeItem((VfxResId)STR_GLOBAL_SEND, (VfxId)VCUI_SMS_COMPOSER_FUNC_BAR_SEND);
        }
	}
}

void VcuiSmsComposerPage::updateTitleBar()
{
    if(NULL == m_titleBar || NULL == m_dataProvider)
    {
        return;
    }
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_UPDATE_TITLEBAR, m_dataProvider->getSimId());

    VfxChar *text_buffer = NULL;
    VFX_ALLOC_MEM(text_buffer, sizeof(VfxChar) * 50, this);
    memset(text_buffer, 0, sizeof(VfxChar) * 50);
    VcuiSmsComposerUtility::getTitleBarStr((VfxU16 *)text_buffer, m_dataProvider->getSimId());
    m_titleBar->setTitle((VfxWChar*)text_buffer);   
    VFX_FREE_MEM(text_buffer);
}

void VcuiSmsComposerPage::hideUnhideFormItem(VfxU32 ids, VfxBool isHide)
{
	VcpFormItemBase *item = NULL;
	VfxU32 temp = 1;

	while (temp < VCUI_SMS_COMPOSER_FORM_END)
	{
		if ((ids & temp) ==   temp)
		{
			item = m_form->getItem(temp);
			if (item)
			{
				item->setIsHidden(isHide);
			}
			item = NULL;
		}
		temp = temp << 1;
   }
}

void VcuiSmsComposerPage::restoreFormItem()
{
	if (m_backUpitemsAlraedyDraw)
	{
		m_form->removeItem(VCUI_SMS_COMPOSER_FORM_CONTACT);
		m_contactlist = NULL;
		
		hideUnhideFormItem(m_backUpitemsAlraedyDraw , VFX_FALSE);
		m_itemsAlraedyDraw = m_backUpitemsAlraedyDraw;		
		m_backUpitemsAlraedyDraw = 0;

		m_form->scrollItemToView(VCUI_SMS_COMPOSER_FORM_RECIPIENT, VCPFORM_SCROLL_BOTTOM);
	}
}

void VcuiSmsComposerPage::clickSendButton(void)
{
    if(m_curEditor == m_editor)
    {
        VfxWChar *addrStr = m_editor->getText();       
        if(0 != vfx_sys_wcslen(addrStr))
        {
            if((1 == vfx_sys_wcslen(addrStr)) && (10 == addrStr[0]))
            {
                // skip
            }
            else
            {                
                if(VFX_FALSE == 
                    insertRecipientAddr(NULL, addrStr, VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER))
                {
                    // follow UC design
                    // return;
                }
            }
        }
    }

    if(0 == m_recipientList->getContactCount())
    {
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
		    MMI_EVENT_INFO_BALLOON, 
		    MMI_NMGR_BALLOON_TYPE_FAILURE, 
		    (WCHAR*)GetString(STR_ID_VCUI_SMSC_PLS_ADD_RECIPIENT_ID));
	    return;
    }

	if(VcuiSmsComposerUtility::checkIsFlightMode())
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
		    MMI_EVENT_INFO_BALLOON, 
		    MMI_NMGR_BALLOON_TYPE_FAILURE, 
		    (WCHAR*)GetString(STR_ID_VCUI_SMSC_FLIGHT_MODE));
	    return;
	}

	if(!(m_dataProvider->getSimId() & (VcuiSmsComposerUtility::getValidSim()))) 
	{	    
	    showSwapSimConfirmPop();
        return;
	}

    sendSms();
}

void VcuiSmsComposerPage::clickSaveButton(void)
{
    if(m_curEditor == m_editor)
    {
        VfxWChar *addrStr = m_editor->getText();       
        if(0 != vfx_sys_wcslen(addrStr))
        {
            if((1 == vfx_sys_wcslen(addrStr)) && (10 == addrStr[0]))
            {
                // skip
            }
            else
            {                
                if(VFX_FALSE == 
                    insertRecipientAddr(NULL, addrStr, VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER))
                {
                    // follow UC design
                    // return;
                }
            }
        }
    }
    
    saveSms();
}

void VcuiSmsComposerPage::clickInsertButton(void)
{
    VcpCommandPopup *commandPopup = NULL;
    VFX_OBJ_CREATE(commandPopup, VcpCommandPopup, this);
    commandPopup->setText(STR_ID_VCUI_SMSC_INSERT_ID);
    commandPopup->addItem(VCUI_SMS_COMPOSER_POP_PHB_NAME, STR_ID_VCUI_SMSC_INSERT_PHB_NAME_ID);
    commandPopup->addItem(VCUI_SMS_COMPOSER_POP_PHB_NUM, STR_ID_VCUI_SMSC_INSERT_PHB_NUMBER_ID);
    commandPopup->addItem(0xFFFF, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);         
    commandPopup->setAutoDestory(VFX_TRUE);
    commandPopup->m_signalButtonClicked.connect(this, &VcuiSmsComposerPage::onCommandPopClicked); 
    commandPopup->show(VFX_TRUE);
}

void VcuiSmsComposerPage::clickSwitchSimButton(void)
{
#if (MMI_MAX_SIM_NUM >= 2)     
    mmi_sim_enum send_sim_id = m_dataProvider->getSimId();
    
#if (MMI_MAX_SIM_NUM >= 3)
    if((VcuiSmsComposerUtility::getAllSimCount() > 2) ||
        ((VcuiSmsComposerUtility::getAllSimCount() == 2) && !(send_sim_id & VcuiSmsComposerUtility::getValidSim())))
    {            
        VfxU16 text_buffer[50] = {0,};
        VcpCommandPopup *commandPopup = NULL;
        VFX_OBJ_CREATE(commandPopup, VcpCommandPopup, this);
        commandPopup->setText(STR_ID_VCUI_SMSC_SWITCH_SIM_ID);

        if((VcuiSmsComposerUtility::getValidSim() & MMI_SIM1) && send_sim_id != MMI_SIM1)
        {           
            memset(text_buffer, 0, 50);
            VcuiSmsComposerUtility::getSimNameStr(MMI_SIM1, text_buffer);
            commandPopup->addItem(VCUI_SMS_COMPOSER_POP_SIM1, (VfxWChar*)text_buffer);
        }
        
        if((VcuiSmsComposerUtility::getValidSim() & MMI_SIM2) && send_sim_id != MMI_SIM2)
        {            
            memset(text_buffer, 0, 50);
            VcuiSmsComposerUtility::getSimNameStr(MMI_SIM2, text_buffer);
            commandPopup->addItem(VCUI_SMS_COMPOSER_POP_SIM2, (VfxWChar*)text_buffer);
        }
        
        if((VcuiSmsComposerUtility::getValidSim() & MMI_SIM3) && send_sim_id != MMI_SIM3)
        {       
            memset(text_buffer, 0, 50);
            VcuiSmsComposerUtility::getSimNameStr(MMI_SIM3, text_buffer);
            commandPopup->addItem(VCUI_SMS_COMPOSER_POP_SIM3, (VfxWChar*)text_buffer);
        }
        
        if((VcuiSmsComposerUtility::getValidSim() & MMI_SIM4) && send_sim_id != MMI_SIM4)
        {      
            memset(text_buffer, 0, 50);
            VcuiSmsComposerUtility::getSimNameStr(MMI_SIM4, text_buffer);
            commandPopup->addItem(VCUI_SMS_COMPOSER_POP_SIM4, (VfxWChar*)text_buffer);
        }
        
        commandPopup->addItem(0xFFFF, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);         
        commandPopup->setAutoDestory(VFX_TRUE);
        commandPopup->m_signalButtonClicked.connect(this, &VcuiSmsComposerPage::onCommandPopClicked); 
        commandPopup->show(VFX_TRUE);
    }
    else
#endif
    {
        if(MMI_SIM1 == send_sim_id)  
        {
            m_dataProvider->setSimId(MMI_SIM2);
        }
        else
        {       
            m_dataProvider->setSimId(MMI_SIM1);
        }

        updateTitleBar();
        updateToolBar();
        updateFunctionBar();            
        updateToggleBar();

        VfxU16 sim_buffer[50] = {0,};   
        VcuiSmsComposerUtility::getSwitchSimStr(sim_buffer, m_dataProvider->getSimId());
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)(sim_buffer));
    }    
#endif
}

void VcuiSmsComposerPage::handleDataReadyEvent(VcuiSmsComposerResultEnum result)
{
    m_isGettingData = VFX_FALSE;
    
    if(!m_isPageReady)
        page2ndEnter();
        
    if(m_loading)
    {
        m_loading->stop();  
        m_loading = NULL;                   
    }   

    // clear m_recipientList firstly
    m_recipientList->clear();
    
    VcuiSmsComposerResultEnum dataState = VCUI_SMS_COMPOSER_RESULT_OK;
    VfxWChar *recipientAddr = NULL;  
    VfxWChar *recipientName = NULL;
    VfxU16 buffLen = (VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN + 1) * ENCODING_LENGTH;
    
    VFX_ALLOC_MEM(recipientAddr, buffLen, this);            
    VFX_ALLOC_MEM(recipientName, buffLen, this);  
    
    for(VfxU8 count = 0; count < m_dataProvider->getRecipientNum(); count++)
    {      
        memset(recipientAddr, 0, buffLen);                
        dataState = m_dataProvider->getRecipient(count, recipientAddr, buffLen); 
        if(VCUI_SMS_COMPOSER_RESULT_OK != dataState)
        {
            continue;
        }
        
        memset(recipientName, 0, buffLen);
        srv_phb_get_name_by_number(
            (U16 *)recipientAddr, (U16 *)recipientName, VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN);
        if(mmi_ucs2strlen((CHAR*)recipientName) > 0)
        {
            m_recipientList->add(
                VFX_WSTR_MEM(recipientName), VFX_WSTR_MEM(recipientAddr), VFX_WSTR_EMPTY);
        }
        else
        {    
            m_recipientList->add(
                VFX_WSTR_EMPTY, VFX_WSTR_MEM(recipientAddr), VFX_WSTR_EMPTY);
        }
    }     
    
    m_recipientList->checkUpdate();
    m_content->checkUpdate();      
    updateTitleBar();
    
    VFX_FREE_MEM(recipientAddr);            
    VFX_FREE_MEM(recipientName);
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_DATA_READY, 
        m_recipientList->getContactCount(), m_dataProvider->getRecipientNum());
}

void VcuiSmsComposerPage::handleAddrInsertionEvent(VfxU16 cnt)
{
    VfxU16 string_id = 0;
    VfxU32 count = 0;
	VfxU16 buffLen = 0;
	VfxWChar *buff = NULL;
	VfxWChar *recipientName = NULL;
    VfxBool invalid_address = VFX_FALSE;    

	buffLen = (VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN + 1)* ENCODING_LENGTH;
	VFX_ALLOC_MEM(buff, buffLen, this);
	VFX_ALLOC_MEM(recipientName, buffLen, this);

    for (VfxU32 index = 0 ; index < cnt; index++)
    {
		//Check if MAX count is already reached, if so display the popup and return
		if (m_recipientList->getContactCount() >= VcuiSmsComposerUtility::getMaxRecipientCount())
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_FAILURE, 
                (WCHAR*)GetString(STR_ID_VCUI_SMSC_RECIPIENT_NUMBER_EXCEED_ID));
			VFX_SYS_FREE_MEM(buff);
			VFX_SYS_FREE_MEM(recipientName);
            return;
        }
        
		//Get the data from the phonebook
		memset(buff, 0, buffLen);
		vcui_phb_list_get_selected_contact_data_by_index(m_phbCuiId, buff , buffLen , index);

		if (VcuiSmsComposerUtility::checkIsAsciiString((VfxU8*) buff) && 
		    VcuiSmsComposerUtility::checkIsPhoneNum((VfxU8*)buff))
		{
			//Phone Number
			if (mmi_ucs2strlen((CHAR* )buff) > VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN)
			{
				invalid_address = VFX_TRUE;
				count++;
				continue;
			}
		}
		else
		{
			invalid_address = VFX_TRUE;
			count++;
			continue;
		}
      
		/*Now add the address in contact selector*/
		memset(recipientName, 0, buffLen);
		vcui_phb_list_get_selected_contact_name_by_index(m_phbCuiId, recipientName, buffLen, index);
		if (mmi_ucs2strlen((CHAR*)recipientName) > 0)
		{
			insertRecipientAddr(recipientName, buff, VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER);
		}
		else
		{			
			insertRecipientAddr(NULL, buff, VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER);
		}
	}
      
	if (invalid_address)
    {
        if (cnt == 1)
        {
            string_id = STR_ID_VCUI_SMSC_INVALID_RECIPIENT;
        }  
        else
        {
			string_id = STR_ID_VCUI_SMSC_INVALID_RECIPIENTS_REMOVED;
		}
    }
  
    if (string_id)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            (WCHAR*)GetString(string_id));
    }
	
	VFX_FREE_MEM(buff);
	VFX_FREE_MEM(recipientName);
}

void VcuiSmsComposerPage::handleSendDoneEvent(VcuiSmsComposerResultEnum result)
{
    if(VCUI_SMS_COMPOSER_RESULT_OK == result)
    {       
        postEventToCaller(EVT_ID_CUI_SMS_COMPOSER_CLOSE);
    }
    else if(VCUI_SMS_COMPOSER_RESULT_MEM_FULL == result)
    {
        // follow UC UE design
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            (WCHAR*)GetString(VcuiSmsComposerUtility::getErrorStrId(result)));
        postEventToCaller(EVT_ID_CUI_SMS_COMPOSER_CLOSE);
    }
    else
    {
        if(m_waitingPop)
        {
            VFX_OBJ_CLOSE(m_waitingPop);
            m_waitingPop = NULL;   
        }   
        
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            (WCHAR*)GetString(VcuiSmsComposerUtility::getErrorStrId(result)));
    }
}

void VcuiSmsComposerPage::handleSaveDoneEvent(VcuiSmsComposerResultEnum result)
{
    if(VCUI_SMS_COMPOSER_RESULT_OK == result)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_INFO, 
            (WCHAR*)GetString(STR_GLOBAL_SAVED));			       
        postEventToCaller(EVT_ID_CUI_SMS_COMPOSER_CLOSE);
    }
    else
    {
        if(m_waitingPop)
        {
            VFX_OBJ_CLOSE(m_waitingPop);
            m_waitingPop = NULL;   
        }
        
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            (WCHAR*)GetString(VcuiSmsComposerUtility::getErrorStrId(result)));
    }
}

void VcuiSmsComposerPage::handleSimRefreshEvent(VcuiSmsComposerResultEnum result)
{
    if(VCUI_SMS_COMPOSER_RESULT_OK == result)
    {			
        updateTitleBar();
        updateToolBar();
        updateFunctionBar();            
        updateToggleBar();
    }
    else
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            (WCHAR*)GetString(VcuiSmsComposerUtility::getErrorStrId(result)));
    }

}

void VcuiSmsComposerPage::handleCloseAppEvent(VcuiSmsComposerResultEnum result)
{
    if(VCUI_SMS_COMPOSER_RESULT_OK == result)
    {	
        // do nothing
    }
    else
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            (WCHAR*)GetString(VcuiSmsComposerUtility::getErrorStrId(result)));
    }
    
    postEventToCaller(EVT_ID_CUI_SMS_COMPOSER_CLOSE);
}

VfxBool VcuiSmsComposerPage::insertRecipientAddr(const VfxWChar *name, const VfxWChar *address, VfxU32 addressType)
{
    VfxBool insert_result = VFX_TRUE;
    
	if(VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER == addressType)
	{
		if (m_recipientList->getContactCount() >= VcuiSmsComposerUtility::getMaxRecipientCount())
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_FAILURE,
                (WCHAR*)GetString(STR_ID_VCUI_SMSC_RECIPIENT_NUMBER_EXCEED_ID));    
            insert_result = VFX_FALSE;
        }   
        
        if (VcuiSmsComposerUtility::checkIsAsciiString((VfxU8*) address) && 
            VcuiSmsComposerUtility::checkIsPhoneNum((VfxU8*)address) && insert_result)
        {
            VcuiSmsComposerResultEnum result = m_dataProvider->addRecipient((VfxWChar *)address);
            if(VCUI_SMS_COMPOSER_RESULT_OK != result)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                    MMI_EVENT_INFO_BALLOON, 
                    MMI_NMGR_BALLOON_TYPE_FAILURE, 
                    (WCHAR*)GetString(STR_GLOBAL_FAILED_TO_SAVE));    
                insert_result = VFX_FALSE;
            }   
            else
            {
                m_recipientList->add(VFX_WSTR_MEM(name), VFX_WSTR_MEM(address), VFX_WSTR_EMPTY);
            }
        }
        else if(insert_result)
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_FAILURE, 
                (WCHAR*)GetString(STR_ID_VCUI_SMSC_INVALID_RECIPIENT));                  
            insert_result = VFX_FALSE;
        }
    }
	else
	{
	    // For extensional development in future
	    // m_recipientList->add(VFX_WSTR_MEM(name), VFX_WSTR_EMPTY, VFX_WSTR_MEM(address));
	}
	
    m_editor->deleteAll();    
    m_editor->setEnterKeyEnabled(VFX_FALSE);	
    m_recipientList->checkUpdate();
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_INSERT_RECIPIENT_ADDR, 
        insert_result, m_recipientList->getContactCount(), m_dataProvider->getRecipientNum());
    
    return insert_result;
}

void VcuiSmsComposerPage::insertContentText(VfxWChar *string, VfxBool isReplace)
{
    if(NULL == m_content)
    {
        return;
    }
    
	VfxU16 length = mmi_ucs2strlen((CHAR *) string);
	// VfxU32 ret = 1;
	if (isReplace)
	{
		m_content->deleteAll();
	}

    if (string != NULL)
    {
		VfxS32 cursorCurrentPos = 0;
#if 0		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif     
        m_content->insertText(string);        
        m_content->insertText((VfxWChar)L' ');
		cursorCurrentPos = m_content->getCursorIndex();
		m_cursorIndexToHeighlight = cursorCurrentPos;
    }

}

void VcuiSmsComposerPage::showSwapSimConfirmPop(void)
{
    VfxChar *text_buffer = NULL;
    VFX_ALLOC_MEM(text_buffer, sizeof(VfxChar) * 200, this);
    memset(text_buffer, 0, sizeof(VfxChar) * 200);
    VcuiSmsComposerUtility::getSwapSimStr((VfxU16 *)text_buffer, m_dataProvider->getSimId());
    
    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
    confirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    confirm->setText((VfxWChar*)text_buffer);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirm->setCustomButton(VfxWString(STR_ID_VCUI_SMSC_CONTINUE), 
                VfxWString(STR_GLOBAL_CANCEL), 
                VCP_POPUP_BUTTON_TYPE_NORMAL, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirm->m_signalButtonClicked.connect(this, &VcuiSmsComposerPage::onConfirmPopClicked);
    confirm->setAutoDestory(VFX_TRUE);
    confirm->show(VFX_TRUE);
    
	VFX_FREE_MEM(text_buffer);
}

void VcuiSmsComposerPage::setContentTextEditorActive(void)
{
	if(m_content)
	{
		if(m_cursorIndexToHeighlight != 0)
		{
			m_content->setCursorIndex(m_cursorIndexToHeighlight);
			m_cursorIndexToHeighlight = 0;
		}
		vfxPostInvoke1(m_content, &VcpTextEditor::activate, VFX_TRUE);
	}
}

void VcuiSmsComposerPage::setTextEditorAutoActivated()
{
    if (m_recipientList)
    {
        // m_recipientList->getContactCount() is 0 at this time.
        if(m_dataProvider->getRecipientNum() >0)
        {
            if(m_content)
            {
                m_content->setAutoActivated(VFX_TRUE);
                m_curEditor = m_content;
            }
        }
        else
        {
            m_recipientList->getInputbox()->setAutoActivated(VFX_TRUE);
            m_curEditor = m_editor;
        }
    }
    else if(m_content)
    {
        m_content->setAutoActivated(VFX_TRUE);
        m_curEditor = m_content;
    }
}

VfxBool VcuiSmsComposerPage::isSendButtonValid(void)
{    
    VcuiSmsComposerOperationEnum operation_type = m_dataProvider->getOperationType();    
    mmi_sim_enum send_sim_id = m_dataProvider->getSimId();
    
    if ( !VcuiSmsComposerUtility::checkIsFlightMode())
    {
        if( !((VcuiSmsComposerUtility::getValidSim() & ~(VcuiSmsComposerUtility::getInvalidSim())) & send_sim_id) &&
		    !((1 == VcuiSmsComposerUtility::getAllSimCount()) && !(VcuiSmsComposerUtility::getValidSim() == VcuiSmsComposerUtility::getClosedSim()) && 
		    (VCUI_SMS_COMPOSER_OPERATION_REPLY == operation_type) && !(send_sim_id & VcuiSmsComposerUtility::getValidSim())))	    
        {
            return VFX_FALSE;
        }
        else
        {
            return VFX_TRUE;
        }
    }
    else
    {
        if( VcuiSmsComposerUtility::getValidSim() & send_sim_id )
            return VFX_TRUE;
        else    
            return VFX_FALSE; 
    }
}

void VcuiSmsComposerPage::openPhbCui(VfxBool isMultiSelect, VfxU32 mode)
{
	m_phbCuiId = vcui_phb_list_create(getApp()->getGroupId());
	
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_OPEN_PHB_CUI, m_phbCuiId, m_pbInsertState);

    if (m_phbCuiId > 0)
    {      
        vcui_phb_list_set_req_field(m_phbCuiId, mode);			 		
        if (!isMultiSelect)
        {
            vcui_phb_list_set_req_count(m_phbCuiId, 1);			 
        }
        else
        {
            vcui_phb_list_set_req_count(m_phbCuiId, 
                (VcuiSmsComposerUtility::getMaxRecipientCount() - m_recipientList->getContactCount()));
        }
        
        if(VCUI_SMS_COMPOSER_STATE_INSERT_ADDRESS == m_pbInsertState)
        {
            vcui_phb_list_set_title_str(m_phbCuiId ,STR_ID_VCUI_SMSC_ADD_RECIPIENT);
        }
  
        vfxSetCuiCallerScr(m_phbCuiId, getMainScr());
        vcui_phb_list_run(m_phbCuiId);
    }
}

void VcuiSmsComposerPage::postEventToCaller(VcuiSmsComposerEventEnum eventId)
{

    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_POST_EVENT, eventId);

    /* emit a event to the caller */
    VcuiSmsComposerEventStruct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, eventId, getApp()->getGroupId());
    getApp()->postToCaller((mmi_group_event_struct*)&evt);    
    // getApp()->sendToCaller((mmi_group_event_struct*)&evt); // MAUI_03307218   
}

void VcuiSmsComposerPage::sendSms()
{
    VcuiSmsComposerResultEnum result = m_dataProvider->sendSms();    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_SEND_SMS, result);
    if(VCUI_SMS_COMPOSER_RESULT_OK != result)
    {    
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            (WCHAR*)GetString(VcuiSmsComposerUtility::getErrorStrId(result)));       
    }
    else
    {
        VFX_OBJ_CREATE(m_waitingPop, VcpIndicatorPopup, this);
        m_waitingPop->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_waitingPop->setText(STR_GLOBAL_SENDING);
        m_waitingPop->setAutoDestory(VFX_FALSE);
        m_waitingPop->show(VFX_TRUE);
    }
}

void VcuiSmsComposerPage::saveSms()
{
    VcuiSmsComposerResultEnum result = m_dataProvider->saveSms();
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_COMPOSER_PAGE_SAVE_SMS, result);
    if(VCUI_SMS_COMPOSER_RESULT_OK != result)
    {    
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
            MMI_EVENT_INFO_BALLOON, 
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            (WCHAR*)GetString(VcuiSmsComposerUtility::getErrorStrId(result)));       
    }
    else
    {
        VFX_OBJ_CREATE(m_waitingPop, VcpIndicatorPopup, this);
        m_waitingPop->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_waitingPop->setText(STR_GLOBAL_SAVING);
        m_waitingPop->setAutoDestory(VFX_FALSE);
        m_waitingPop->show(VFX_TRUE);

    }
}

/******************************************************************************/
/*                          Class VcuiSmsComposerRecipientPage                */
/******************************************************************************/
// VFX_IMPLEMENT_CLASS("VcuiSmsComposerRecipientPage", VcuiSmsComposerRecipientPage, VfxPage);

VcuiSmsComposerRecipientPage::VcuiSmsComposerRecipientPage(VcuiSmsComposerPage *mainPage):
    m_isRotate(VFX_TRUE), 
    m_mainPage(mainPage)
{
    m_contactSelector = m_mainPage->getContactSelector();
    m_recipientCount = m_contactSelector->getContactCount();
}

void VcuiSmsComposerRecipientPage::setRotate(VfxBool isRotate)
{
    m_isRotate = isRotate;
}

void VcuiSmsComposerRecipientPage::onInit()
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_RECIPIENT_PAGE_ONINIT, m_recipientCount);

    VfxPage::onInit();

    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitle(STR_GLOBAL_RECIPIENTS);
    setTopBar(title);

    VcpListMenu *list;
    VFX_OBJ_CREATE(list, VcpListMenu, this);
    list->setContentProvider(this);
    list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);    
	list->setItemHighlightHidden(VFX_TRUE);
    list->m_signalCmdButtonClicked.connect(this, &VcuiSmsComposerRecipientPage::onDeleteRecipient);
    list->setSize(getSize());
    list->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE);
}

void VcuiSmsComposerRecipientPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    if (!m_isRotate)
    {
        param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
    }
}

VfxU32 VcuiSmsComposerRecipientPage::getCount() const
{
    if (NULL == m_mainPage)
    {
        return 0;
    }

    return m_recipientCount;
}

VfxBool VcuiSmsComposerRecipientPage::getItemText(
            VfxU32 index, 
            VcpListMenuFieldEnum fieldType, 
            VfxWString &text, 
            VcpListMenuTextColorEnum &color)
{
    if(m_recipientCount > 0)
    {
        VcpContact *contact;
        VfxS32 count = 0;
        VfxS32 max_Count = m_contactSelector->getContactCount();
        VfxU16 string[100] = {0,};

        contact = m_contactSelector->getContactList();

        for (count = 0; (count< max_Count) && ((U32)count < index); count++)
        {
            contact = contact->getNext();
        }
        
        if(count == index && contact != NULL)
        {
            if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
            {
                if(!contact->m_name.isEmpty())
                {
                    mmi_ucs2ncpy(
                        (CHAR *)string, (CHAR *)contact->m_name.getBuf(), contact->m_name.getLength());
                }
                else
                {
                    mmi_ucs2cat((CHAR *)string, (CHAR *) GetString(STR_ID_VCUI_SMSC_UNNAMED));
                }                
                text.loadFromMem((const VfxWChar *)string);
            }
                       
            if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
            {
                if(!contact->m_phoneNumber.isEmpty())
                {
                    mmi_ucs2ncpy(
                        (CHAR *)string, (CHAR *)contact->m_phoneNumber.getBuf(), contact->m_phoneNumber.getLength());
                }
                else if(!contact->m_email.isEmpty())
                {
                    mmi_ucs2ncpy(
                        (CHAR *)string, (CHAR *)contact->m_email.getBuf(), contact->m_email.getLength());
                }             
                text.loadFromMem((const VfxWChar *)string);
                color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
            }
        }
    }
    
    return VFX_TRUE;
}

VfxBool VcuiSmsComposerRecipientPage::getItemImage(
            VfxU32 index, 
            VcpListMenuFieldEnum fieldType, 
            VfxImageSrc &image)
{
    if (NULL == m_mainPage)
    {
        return VFX_FALSE;
    }

    if (VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL == fieldType ||
        VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED == fieldType ||
        VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT == fieldType)
    {
        image.setResId(IMG_ID_VCUI_SMSC_BTN_DELETE);        
    }
    
    return VFX_TRUE;
}

void VcuiSmsComposerRecipientPage::onDeleteRecipient(VcpListMenu *list, VfxU32 index)
{
    m_contactSelector->remove(index);    
    m_recipientCount = m_contactSelector->getContactCount();
    
    m_mainPage->setContactChange(m_contactSelector);

    if (0 == m_recipientCount)
    {
        exit();
    }
    else
    {
        list->resetAllItems(VFX_TRUE);
    }
    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_SCRN_RECIPIENT_PAGE_DELETE_ADDR, m_recipientCount);
}

#endif /* __MMI_SMS_COMPOSER__ */
