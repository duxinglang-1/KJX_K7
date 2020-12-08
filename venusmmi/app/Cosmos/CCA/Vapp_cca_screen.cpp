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
 *  vapp_usb_basecontext.cpp
 *
 * Project:
 * --------
 *  Venus
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h" 


#ifdef __MMI_CCA_SUPPORT__ 

/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#include "MMI_include.h"
#include "GlobalResDef.h"
#include "CCASrvGProt.h"
#include "CCASrvIProt.h"
}
#endif
#include "vcp_status_icon_bar.h"
#include "Vcp_popup.h"
#include "Vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"
#include "mmi_rp_vapp_cca_def.h"
#include "Vapp_cca_screen.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"

#define VAPP_CCA_GLOBAL_INVALID_ID  0xffffffff

/***************************************************************************** 
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCCAInstallInfoItem", VappCCAInstallInfoItem, VfxObject);
VFX_IMPLEMENT_CLASS("VappCCAEventSimpleObject", VappCCAEventSimpleObject, VfxObject);

void VappCCAMMIDataPack::addData(VfxObject* data)
{
    m_instList.append(data);
}

VfxObject* VappCCAMMIDataPack::getData(VfxU32 index)
{
    VfxU32     i;
    VfxU32     count;
    VfxObjListEntry *entry;
    
    count = m_instList.getEntryCount();
    if (index >= count)
    {
        return NULL;
    }
    
    entry = m_instList.getHead();
    i = 0;
    while (i < index)
    {
        entry = entry->getNext();
        i++;
    }

    if (i == count)
    {
        return NULL;
    }
    
    return entry->get();
}

VfxS32 VappCCAMMIDataPack::getDataCount(void)
{
    return (U32)m_instList.getEntryCount();
}

void VappCCAMMIDataPack::closeAll(void)
{
    VfxObjListEntry *entry;
    VfxObject *obj;
    
    if (m_instList.isEmpty())
    {
        return;
    }
    
    entry = m_instList.getHead();
    while(entry)
    {
        obj = entry->get();
        if (obj)
        {
            VFX_OBJ_CLOSE(obj);
        }
        entry = entry->getNext();
    }

    m_instList.clear();
}

VfxU32 VappCCAListProvider::getCount() const
{
    return m_data->getDataCount() - 1;
}
    
VfxBool VappCCAListProvider::getItemText(
        VfxU32 index, 
        VcpListMenuFieldEnum fieldType,          
        VfxWString &text,                        
        VcpListMenuTextColorEnum &color)
{
    VappCCAInstallInfoItem *item;

    item = VFX_OBJ_DYNAMIC_CAST(getItem(index + 1), VappCCAInstallInfoItem);
    if (!item)
    {
        VFX_ASSERT(0);
        return VFX_FALSE;
    }

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text = getAppName(item->m_appId);   
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text = getStateString(item->m_state);
    }
    else
    {
        return VFX_FALSE;
    }

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

    return VFX_TRUE;
}
        
VcpListMenuItemStateEnum VappCCAListProvider::getItemState(VfxU32 index) const
{
    VappCCAInstallInfoItem *item;

    item = (VappCCAInstallInfoItem*)getItem(index + 1);
    if (item->m_selected == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

void VappCCAListProvider::setContent(VappCCAMMIDataPack *data)
{
    if (!data)
    {
        return;
    }

    m_data = data;
}

VappCCAMMIDataPack* VappCCAListProvider::getContent(void)
{
    return m_data;
}

VfxObject* VappCCAListProvider::getItem(VfxS32 index) const
{
    return m_data->getData(index);
}

VfxS32 VappCCAListProvider::getItemCount(void)
{
    return m_data->getDataCount();
}

VfxWString VappCCAListProvider::getAppName(VfxU32 appId)
{
    switch(appId)
    {
        case SRV_CCA_CONFIG_DTACCT:
            return VFX_WSTR_RES(STR_GLOBAL_DATA_ACCOUNT);
    #if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
        case SRV_CCA_CONFIG_WLAN:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_WLAN);
    #endif
    #ifdef BROWSER_SUPPORT
        case SRV_CCA_CONFIG_BROWSER:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_BROWSER);
    #endif
    #ifdef MMS_SUPPORT
        case SRV_CCA_CONFIG_MMS:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_MMS);
    #endif
        case SRV_CCA_CONFIG_EMAIL:
            return VFX_WSTR_RES(STR_GLOBAL_EMAIL);
    #ifdef __MMI_SYNCML_CCA_SUPPORT__
        case SRV_CCA_CONFIG_SYNCMLDS:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_SYNCMLDS);
    #endif
    #ifdef SYNCML_DM_SUPPORT
        case SRV_CCA_CONFIG_SYNCMLDM:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_SYNCMLDM);
    #endif
    #ifdef __MMI_IMPS_OTA__
        case SRV_CCA_CONFIG_IMPS:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_IMPS);
    #endif
    #if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
        case SRV_CCA_CONFIG_WLAN_DMP:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_WLAN);
    #endif
    #ifdef __MMI_VOIP_OTAP_DMP__
/* under construction !*/
/* under construction !*/
    #endif
    #ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
        case SRV_CCA_CONFIG_PUSH:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_PUSH);
    #endif
    #ifdef __MMI_STREAMING_OTAP__
        case SRV_CCA_CONFIG_RTSP:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_RTSP);
    #endif
    #ifdef __MMI_AGPS_OTAP__
        case SRV_CCA_CONFIG_SUPL:
            return VFX_WSTR_RES(STR_ID_VAPP_CCA_SUPL);
    #endif
    
        default:
            return VFX_WSTR_EMPTY;
    }
}

VfxWString VappCCAListProvider::getStateString(VfxU16 state)
{
    if(state <= SRV_CCA_STATUS_SETTING_SKIPPED)
    {
        return VFX_WSTR_RES(STR_ID_VAPP_CCA_CONFIGURED + (state - SRV_CCA_STATUS_OK));
    }
    else if(state == SRV_CCA_STATUS_SETTING_NOT_INSTALLED)
    {
        return VFX_WSTR_RES(STR_ID_VAPP_CCA_NOT_INSTALLED);
    }
    else
    {
        return VFX_WSTR_NULL;
    }         
}

VappCCAPage::VappCCAPage()
{
    m_toolBar = NULL;
    m_progress = NULL;
}

VappCCAPage::VappCCAPage(page_id_enum pageId, VappCCAMMIDataPack *data)
{
    m_pageId = pageId;
    m_toolBar = NULL;
    m_progress = NULL;
    m_content.setContent(data);
}

void VappCCAPage::onInit()
{
    VfxPage::onInit();
	
	if (m_pageId == PAGE_ID_INSTALL_LIST || m_pageId == PAGE_ID_INSTALL_RESULT)
	{
		createInstallResultList(m_pageId);
	}
	else
	{		
		VFX_ASSERT(0);
        return;
	}
}
void VappCCAPage::createInstallResultList(page_id_enum pageId)
{
    VcpListMenu *listMenu;
    VcpTitleBar *bar;

    setStatusBar(VFX_TRUE);
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);//PAGE_ID_INSTALL_LIST,PAGE_ID_INSTALL_RESULT,
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    VFX_OBJ_CREATE(listMenu, VcpListMenu, this);
    
    listMenu->setContentProvider(&m_content);
    listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    listMenu->setSize(getSize());
    listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    
    if(pageId == PAGE_ID_INSTALL_LIST)
    {
        bar->setTitle((VfxResId)(STR_ID_VAPP_CCA_INSTALL_LIST_TITLE));
        m_toolBar->addItem(BTN_ID_INSTALL, (VfxResId)(STR_GLOBAL_INSTALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_INSTALL);
        m_toolBar->addItem(BTN_ID_CANCEL, (VfxResId)(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
                
        listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);        
        listMenu->m_signalItemSelectionStateChanged.connect(this, &VappCCAPage::onListItemStateChanged);
        updateButtons();
    }
    else
    {
        bar->setTitle((VfxResId)(STR_ID_VAPP_CCA_INSTALL_RESULT_TITLE));
        m_toolBar->addItem(BTN_ID_INSTALL_RESULT_OK, (VfxResId)(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
        
        listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        listMenu->setItemHighlightHidden(VFX_TRUE);
    }
        
    setTopBar(bar);
    m_toolBar->m_signalButtonTap.connect(this, &VappCCAPage::onListSelect);
    setBottomBar(m_toolBar);
    
}

void VappCCAPage::updateButtons(void)
{
    VfxU32 i;
    VfxBool selected = VFX_FALSE;
	
    for (i = 0; i < m_content.getCount(); i++)
    {
        if (m_content.getItemState(i) == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            selected = VFX_TRUE;
            break;
        }
    }

    if (selected == VFX_FALSE)
    {
        m_toolBar->setDisableItem(BTN_ID_INSTALL, VFX_TRUE);
    }
}
void VappCCAPage::disableButtons(void)
{
	m_toolBar->setDisableItem(BTN_ID_INSTALL, VFX_TRUE);
	m_toolBar->setDisableItem(BTN_ID_CANCEL, VFX_TRUE);
}

void VappCCAPage::showProgress(void)
{
    if (!m_progress)
    {
        VFX_OBJ_CREATE(m_progress, VcpActivityIndicator, this);
        m_progress->setSize(VfxSize(30,30));
        m_progress->setAnchor(0.5, 0.5);
        m_progress->setHiddenWhenStopped(VFX_TRUE);
        m_progress->setPos(getSize().width / 2, getSize().height / 2);
		m_progress->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                               VFX_FRAME_ALIGNER_MODE_MID,
                               VFX_FRAME_ALIGNER_MODE_MID,
                               VFX_FRAME_ALIGNER_MODE_MID);
    }
    setIsDisabled(VFX_TRUE);
    m_progress->start();
}

void VappCCAPage::closeProgress(void)
{
    if (m_progress)
    {
        setIsDisabled(VFX_FALSE);
        VFX_OBJ_CLOSE(m_progress);
        m_progress = NULL;
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

VfxBool VappCCAPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch(event.keyCode)
        {
            case VFX_KEY_CODE_BACK:
            {
                if (m_pageId == PAGE_ID_INSTALL_RESULT)
                {
                    m_listSelSignal.emit(m_pageId, LIST_SEL_INSTALL_RESULT_OK, NULL);
                }
                else if (m_pageId == PAGE_ID_INSTALL_LIST && !m_progress)
                {
                    m_listSelSignal.emit(m_pageId, LIST_SEL_INSTALL_CANCEL, NULL);
                }
            }
            return VFX_TRUE;

            default:
            break;
        }
    }
    return VfxPage::onKeyInput(event);
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
void VappCCAPage::onListSelect(VfxObject* obj, VfxId id)
{
    switch(id)
    {
        case BTN_ID_INSTALL:
        {
            disableButtons();
            showProgress();
            m_listSelSignal.emit(m_pageId, LIST_SEL_INSTALL, m_content.getContent());
        }
        break;

        case BTN_ID_CANCEL:
        {
            m_listSelSignal.emit(m_pageId, LIST_SEL_INSTALL_CANCEL, NULL);
        }
        break;

        case BTN_ID_INSTALL_RESULT_OK:
        {
            m_listSelSignal.emit(m_pageId, LIST_SEL_INSTALL_RESULT_OK, NULL);
        }
        break;
            
        default:
        {
            VFX_ASSERT(0);
        }
        return;
    }
}

void VappCCAPage::onListItemStateChanged(VcpListMenu* obj, 
        VfxU32 index, 
        VcpListMenuItemStateEnum newState)
{
    VappCCAInstallInfoItem *item;
    VappCCAInstallInfoItem *checkItem;
    VfxS32 i;
    VfxBool allUnsel = VFX_TRUE;
    
    /* Changed item*/
    item = VFX_OBJ_DYNAMIC_CAST(m_content.getItem(index + 1), VappCCAInstallInfoItem);
    if (!item)
    {
        VFX_ASSERT(0);
        return;
    }

    item->m_selected = newState;
    
    if (newState == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
    {
        /* Check each item, if unselected is its dependent item, unselect the item also*/
        for (i = 1; i < m_content.getItemCount(); i++)
        {
            checkItem = VFX_OBJ_DYNAMIC_CAST(m_content.getItem(i), VappCCAInstallInfoItem);
            if (checkItem && (checkItem->m_dependId == item->m_id))
            {
                checkItem->m_selected = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
                obj->updateItem(i - 1);
            }
            if (checkItem->m_selected == VCP_LIST_MENU_ITEM_STATE_SELECTED)
            {
                allUnsel = VFX_FALSE;
            }
        }
    }
    else if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        allUnsel = VFX_FALSE;
        for (i = 1; i < m_content.getItemCount(); i++)
        {
            checkItem = VFX_OBJ_DYNAMIC_CAST(m_content.getItem(i), VappCCAInstallInfoItem);
            /* Select the dependent item*/
            if ((checkItem != item) && (checkItem->m_id == item->m_dependId))
            {
				checkItem->m_selected = VCP_LIST_MENU_ITEM_STATE_SELECTED;
                obj->updateItem(i - 1);
                break;
            }
        }
    }

    if (m_toolBar)
    {
        if (allUnsel == VFX_FALSE)
        {
            m_toolBar->setDisableItem(BTN_ID_INSTALL, VFX_FALSE);
        }
        else
        {
            m_toolBar->setDisableItem(BTN_ID_INSTALL, VFX_TRUE);
        }
    }
}

void VappCCAPinScreen::onInit()
{
    VcpStatusIconBar *statusBar;
    VfxAppScr::onInit();
    
    VFX_OBJ_CREATE(statusBar, VcpStatusIconBar, this);
    statusBar->setAutoAnimate(VFX_TRUE);
    statusBar->setPos(0, 0);
    statusBar->bringToFront();
}
void VappCCAPinScreen::onEnter(VfxBool isBackward)
{    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    m_dir = renderer->getPreScreenRotateType();
    VfxAppScr::onEnter(VFX_TRUE);
}
void VappCCAPinScreen::onBeforeDeinit()
{
    //close GlobalPopup
    if (m_popup)
    {
        vapp_nmgr_global_popup_cancel(m_popup);
        m_popup = 0;
    }
    closePinVerify();
    //closeGlobalPopup();
}

void VappCCAPinScreen::onObjectNotify(VfxId id, void *userData)
{
    switch(id)
    {
        case VFX_OBJECT_NOTIFY_ID_BEFORE_DEINIT:
        {
            onBeforeDeinit();
        }
        return;

        default:
        {
            VfxAppScr::onObjectNotify(id, userData);
        }
        return;
    }	
}

void VappCCAPinScreen::onQueryRotateEx(VfxScreenRotateParam & param)
{
    param.rotateTo = m_dir;
}

void VappCCAPinScreen::showPinVerify(void)
{
    if (!m_pinPopup)
    {
        VFX_OBJ_CREATE(m_pinPopup, VcpInputPopup, this);
    }

    VsrvInputBinding inputBind(
        IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
        0,
        IME_INPUT_STYLE_NONE,
        static_cast<InputConnection*> (m_pinPopup->getInputbox()->m_editing));

    m_pinPopup->getInputbox()->setIME(inputBind);
    m_pinPopup->setHintText(VFX_WSTR_EMPTY); 
    m_pinPopup->m_signalButtonClicked.connect(this, &VappCCAPinScreen::onPinButtonClicked);
    m_pinPopup->setText(VFX_WSTR_EMPTY, SRV_CCA_MAX_PIN_CHARS, VFX_FALSE);
    m_pinPopup->setTitle((VfxResId)(STR_ID_VAPP_CCA_PIN_TITLE));
    m_pinPopup->show(VFX_TRUE);
}

void VappCCAPinScreen::closePinVerify(void)
{
    if (m_pinPopup && m_pinPopup->isValid())
    {
        m_pinPopup->exit(VFX_TRUE);
        m_pinPopup = NULL;
    }
}

void VappCCAPinScreen::onPinButtonClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    VfxWString inputString;
    VcpInputPopup *popup = (VcpInputPopup*)sender;
    VappCCAMMIDataPack pack;
    VappCCAEventSimpleObject simpObj;
    
    if (id == VCP_INPUT_POPUP_BTN_OK)
    {
        inputString = popup->getText();
        simpObj.m_value = (VfxS32)&inputString;
        pack.addData(&simpObj);
        
        m_screenSelSignal.emit(SCREEN_SEL_PIN, &pack);
    }
    else if (id == VCP_INPUT_POPUP_BTN_CANCEL)
    {
        m_screenSelSignal.emit(SCREEN_SEL_PIN_CANCEL, NULL);
        m_pinPopup = NULL;
    }
}

void VappCCAPinScreen::showPopup(popup_type_enum type)
{
    VfxId            popupString;
    PopupCallBackPtr callback = globalPinPopupCallback;
    
    switch(type)
    {

        case POPUP_TYPE_MEM_FULL:
        {
            popupString = STR_GLOBAL_INSUFFICIENT_MEMORY;
        }
        break;
                                        
        case POPUP_TYPE_INVAID_MSG:
        {
            popupString = STR_ID_VAPP_CCA_INVALID_SETTINGS;
        }
        return;
            
        case POPUP_TYPE_NO_APP:
        {
            popupString = STR_ID_VAPP_CCA_NO_APP;
        }
        break;
            
        case POPUP_TYPE_NO_AVAILABLE:
        {
            popupString = STR_ID_VAPP_CCA_NO_AVAILABLE;
        }
        break;

        case POPUP_TYPE_PIN_ABORT:
        {
            popupString = STR_ID_VAPP_CCA_PIN_ABORT;
        }
        break;
            
        case POPUP_TYPE_PIN_RETRY:
        {
            popupString = STR_ID_VAPP_CCA_PIN_NEED_RETRY;
            if (m_pinPopup)
            {
                m_pinPopup->setText(VFX_WSTR_EMPTY, SRV_CCA_MAX_PIN_CHARS, VFX_FALSE);
                m_pinPopup->setErrorText((VfxResId)(popupString));
            }
        }
        return;
            
        case POPUP_TYPE_PIN_FAIL:
        case POPUP_TYPE_PIN_MAX_RETRY:
        {
            popupString = STR_ID_VAPP_CCA_PIN_FAIL;
            callback = globalPopupInvalidPinCallback;
        }
        break;

        default:
        return;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    m_popup = showNMGRGlobalPopup(VCP_POPUP_TYPE_FAILURE,
        popupString,
        callback,
        this);
}

VappCCAScreen::VappCCAScreen()
{
    m_dataPack = NULL;
    m_popup = 0;
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
void globalPopupCallback (VfxId id, void *usrData)
{
    VappCCAScreen *screen = (VappCCAScreen*)usrData;
    if (id != VAPP_CCA_GLOBAL_INVALID_ID && screen && screen->isValid())
    {
        screen->m_screenSelSignal.emit(SCREEN_SEL_POPUP_OK, NULL);
    }
}

void globalPinPopupCallback (VfxId id, void *usrData)
{
    VappCCAPinScreen *screen = (VappCCAPinScreen*)usrData;
    if (id != VAPP_CCA_GLOBAL_INVALID_ID && screen && screen->isValid())
    {
        screen->m_screenSelSignal.emit(SCREEN_SEL_POPUP_OK, NULL);
    }
}

void globalPopupInvalidPinCallback (VfxId id, void *usrData)
{
    VappCCAPinScreen *screen = (VappCCAPinScreen*)usrData;
    if (screen && screen->isValid())
    {
        screen->m_screenSelSignal.emit(SCREEN_SEL_INVALID_PIN_POPUP_OK, NULL);
    }
}

void VappCCAScreen::showPreInstall(VappCCAMMIDataPack *data)
{
    VappCCAEventSimpleObject *simpObj;

    /* Check if it has been installed*/
    simpObj = VFX_OBJ_DYNAMIC_CAST(data->getData(0), VappCCAEventSimpleObject);
    if (simpObj)
    {
        setDataPack(data);
        showInstallList(data);
    }
    show();
}

void VappCCAScreen::showInstallList(VappCCAMMIDataPack *data)
{
    VappCCAPage *page;

    VFX_OBJ_CREATE_EX(page, VappCCAPage, this,(VappCCAPage::PAGE_ID_INSTALL_LIST,data));
    page->m_listSelSignal.connect(this, &VappCCAScreen::onListSelect);
    pushPage(VappCCAPage::PAGE_ID_INSTALL_LIST, page);
    show();
}

void VappCCAScreen::closeInstallList(void)
{
    closePage(VappCCAPage::PAGE_ID_INSTALL_LIST);
    clearDataPack();
}

void VappCCAScreen::showInstallResult(VappCCAMMIDataPack *data)
{
    VappCCAPage *page;

    VFX_OBJ_CREATE_EX(page,VappCCAPage, this,(VappCCAPage::PAGE_ID_INSTALL_RESULT,data));
    page->m_listSelSignal.connect(this, &VappCCAScreen::onListSelect);
    pushPage(VappCCAPage::PAGE_ID_INSTALL_RESULT, page);
}

void VappCCAScreen::closeInstallResult(void)
{
    closePage(VappCCAPage::PAGE_ID_INSTALL_RESULT);
}

void VappCCAScreen::onBeforeDeinit()
{
    if (m_popup)
    {
        vapp_nmgr_global_popup_cancel(m_popup);
        m_popup = 0;
    }
}

void VappCCAScreen::onObjectNotify(VfxId id, void *userData)
{
    switch(id)
    {
        case VFX_OBJECT_NOTIFY_ID_BEFORE_DEINIT:
        {
            onBeforeDeinit();
        }
        return;

        default:
        {
            VfxMainScr::onObjectNotify(id, userData);
        }
        return;
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

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappCCAScreen::onListSelect(VappCCAPage::page_id_enum id,
        VappCCAPage::list_sel_type_enum sel,
        VappCCAMMIDataPack* data)
{
    switch(sel)
    {
        case VappCCAPage::LIST_SEL_INSTALL:
        {
            m_screenSelSignal.emit(SCREEN_SEL_INSTALL, data);
        }
        break;

        case VappCCAPage::LIST_SEL_INSTALL_CANCEL:
        {
            m_screenSelSignal.emit(SCREEN_SEL_INSTALL_CANCEL, NULL);
        }
        break;

        case VappCCAPage::LIST_SEL_INSTALL_RESULT_OK:
        {
            m_screenSelSignal.emit(SCREEN_SEL_INSTALL_RESULT, NULL);
        }
        break;
            
        default:
        return;
    }
}

void VappCCAScreen::setDataPack(VappCCAMMIDataPack *pack)
{
    m_dataPack = pack;
}

VappCCAMMIDataPack* VappCCAScreen::getDataPack(void)
{
    return m_dataPack;
}

void VappCCAScreen::clearDataPack(void)
{
    if (m_dataPack)
    {
        m_dataPack->closeAll();
        m_dataPack = NULL;
    }
}

VfxS32 showGlobalPopup(popup_type_enum type)
{
    //VcpPopupTypeEnum popupType;
    VfxResId popupString;
    
    switch(type)
    {
        case POPUP_TYPE_MEM_FULL:
        {
            popupString = STR_GLOBAL_INSUFFICIENT_MEMORY;
        }
        break;
            
        case POPUP_TYPE_INVAID_MSG:
        {
            popupString = STR_ID_VAPP_CCA_INVALID_SETTINGS;
        }
        break;

        case POPUP_TYPE_NO_APP:
        {
            popupString = STR_ID_VAPP_CCA_NO_APP;
        }
        break;

        case POPUP_TYPE_NO_AVAILABLE:
        {
            popupString = STR_ID_VAPP_CCA_NO_AVAILABLE;
        }
        break;

        case POPUP_TYPE_AUTH_FAIL:
        {
            popupString = STR_ID_VAPP_CCA_AUTH_FAIL;
        }
            break;
                
        default:
        return 0;
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
#endif
    return showNMGRGlobalPopup(VCP_POPUP_TYPE_FAILURE,
        popupString,
        globalPopupCallback,
        NULL);
}

VfxS32 showNMGRGlobalPopup(VcpPopupTypeEnum type, VfxResId str, PopupCallBackPtr cb, void *data)
{
    return vapp_nmgr_global_popup_show_confirm_one_button_id(MMI_SCENARIO_ID_CCA,
        type,
        str,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        cb,
        data);
}
#endif  /*__MMI_CCA_SUPPORT__*/

