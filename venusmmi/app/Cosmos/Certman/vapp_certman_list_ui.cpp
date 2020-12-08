/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  vapp_certman_list_ui.cpp
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  Implementation of venus certificate manager list UI. This includes the
*  UI when appliction is launched from security menu or by other applications
*  for selecting a certificate.h
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "stack_common.h"
#include "stack_msgs.h"
#include "vfx_uc_include.h"
#include "vapp_certman_list_ui.h"
#include "vapp_certman_util.h"
#include "vapp_certman_pluto_adaptor.h"
#include "mmi_rp_vapp_certman_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vapp_setting_framework_gprot.h "
#include "vcp_menu_popup.h"
#include "GlobalResDef.h"
#include "vfx_adp_device.h"

void vapp_certman_launch_cert_list(void)
{
    VfxAppLauncher::launch(
        VAPP_CERTMAN,                            // todo: use own app base
        VFX_OBJ_CLASS_INFO(VappCertmanListApp),
        GRP_ID_ROOT);
}

VFX_IMPLEMENT_CLASS("VappCertmanListApp", VappCertmanListApp, VfxCui);
VFX_IMPLEMENT_CLASS("VappCertmanCertListScr", VappCertmanCertListScr, VfxMainScr);

void VappCertmanListApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display cert list
    VappCertmanCertListScr *scr;

    VFX_OBJ_CREATE(scr, VappCertmanCertListScr, this);
    scr->show();
}

void VappCertmanCertListScr::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and tabbed page screen
    VappCertmanCertListTabContainer *page;
    VFX_OBJ_CREATE(page, VappCertmanCertListTabContainer, this);
    pushPage(VappCertmanCertListScr::TAB_CONTAINER_PAGE_ID, page);
}


void VappCertmanCertListTabContainer::onInit()
{
    VcpTabCtrlPage::onInit();

    addTab(VappCertmanCertListScr::AUTH_CERT_TAB_PAGE_ID, VfxWString(STR_ID_VAPP_CERTMAN_AUTHORITY_CERTS), VcpStateImage(IMG_ID_CERTMAN_AUTH_CERT));
    addTab(VappCertmanCertListScr::USER_CERT_TAB_PAGE_ID, VfxWString(STR_ID_VAPP_CERTMAN_PERSONAL_CERTS), VcpStateImage(IMG_ID_CERTMAN_USER_CERT));
    setCurrTab(VappCertmanCertListScr::AUTH_CERT_TAB_PAGE_ID);
}


VfxPage *VappCertmanCertListTabContainer::onCreateTabPage(VfxId tabId)
{
    VappCertmanCertListPage *page = NULL;
    switch(tabId)
    {
    case VappCertmanCertListScr::AUTH_CERT_TAB_PAGE_ID:
        VFX_OBJ_CREATE_EX(page, VappCertmanCertListPage, this, 
            (CERTMAN_CERTGRP_ROOTCA |CERTMAN_CERTGRP_OTHERUSER|CERTMAN_CERTGRP_CA,
            VAPP_CERTMAN_PUBKEY_TYPE_ALL,
            STR_ID_VAPP_CERTMAN_CERTIFICATES,
            VappCertmanCertListPage::LIST_PURPOSE_VIEW_CERT, NULL));
        auth_list_page = page;
        break;

    case VappCertmanCertListScr::USER_CERT_TAB_PAGE_ID:
        VFX_OBJ_CREATE_EX(page, VappCertmanCertListPage, this, 
            (CERTMAN_CERTGRP_PERSONAL,
            VAPP_CERTMAN_PUBKEY_TYPE_ALL,
            STR_ID_VAPP_CERTMAN_CERTIFICATES,
            VappCertmanCertListPage::LIST_PURPOSE_VIEW_CERT, NULL));
        user_list_page = page;
        break;

    }
    return page;
}

/*-----------------------certificate list page begin-----------------------------*/

VappCertmanCertListPage *VappCertmanCertListTabContainer::get_auth_list_page(void)
{
    return auth_list_page;
}


VappCertmanCertListPage *VappCertmanCertListTabContainer::get_user_list_page(void)
{
    return user_list_page;
}


VfxBool VappCertmanCertListPage::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    ) 
{

    /* special case for selecting one certificate from the list */

    if (list_purpose == LIST_PURPOSE_SELECT)
    {
        if ((fieldType == VCP_LIST_MENU_FIELD_TEXT)&&(index <= 0))
        {
            text.loadFromRes(STR_GLOBAL_NONE);
             color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
            return VFX_TRUE;
        }
        index --;
    }


    if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        applib_time_struct not_after;
        not_after = certificate_list_data.get_cert_list_item(index)->getnotafter();

        VfxDateTime valid_to_date_time;
        valid_to_date_time.setDate(not_after.nYear, not_after.nMonth, not_after.nDay);

        VfxDateTime current_time;
        current_time.setCurrentTime();

        if (valid_to_date_time.compareWith(current_time) == VfxDateTime::LESS)
        {
            text.loadFromRes(STR_ID_VAPP_CERTMAN_EXPIRED);
        }
        else
        {
            text = valid_to_date_time.getDateTimeString(VFX_DATE_TIME_DATE_YEAR|VFX_DATE_TIME_DATE_MONTH|VFX_DATE_TIME_DATE_DAY);
        }

    }
    else if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        if (certificate_list_data.get_cert_list_item(index)->getdcs() == CERTMAN_DCS_ASCII)
        {
            text.format("%s", certificate_list_data.get_cert_list_item(index)->getcertlabel());
        }
        else
        {
            
			text.loadFromMem((VfxWChar*)certificate_list_data.get_cert_list_item(index)->getcertlabel());
        }
    }
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}


VfxBool VappCertmanCertListPage::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
{
    text = empty_text;
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}


VfxBool VappCertmanCertListPage::getItemImage(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc &image              // [OUT] the image resource
    )
{
    if ((fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA2)&&
        (certificate_list_data.get_cert_list_item(index)->getcertprop() & CERTMAN_PROP_READ_ONLY))
    {
        image = VfxImageSrc(IMG_ID_CERTMAN_READ_ONLY);
    }
    return VFX_TRUE;
}


VappCertmanCertListPage::VappCertmanCertListPage(VfxU32 cert_group, 
                                                 VfxU32 key_type,
                                                 VfxResId title,
                                                 vapp_certman_list_purpose_enum list_purpose,
                                                 VappCertmanListPageUser* list_user) : certificate_list_data(cert_group, key_type, this),
                                                 cert_list_behavior(this)
{

    if (list_purpose == LIST_PURPOSE_VIEW_CERT)
    {
        cert_list_behavior.SetLongTabBehavior(VAPP_CERTMAN_LIST_LAUNCH_CONTEXT_MENU);
    }
    else
    {
        cert_list_behavior.SetLongTabBehavior(VAPP_CERTMAN_LIST_IGNORE_LONG_TAP);
    }
    this->list_user = list_user;
    this->list_purpose = list_purpose;
    this->title = title;
}


VappCertmanCertListPage::VappCertmanCertListPage(VfxU32 key_purpose, VfxU32 cert_group, VfxU32 key_type, 
                                                 vapp_certman_list_purpose_enum list_purpose,
                                                 VfxU32 *pubkey_types, VfxU32 pubkey_type_num,
                                                 VfxWChar *issuer_filename, VappCertmanListPageUser* list_user) :
certificate_list_data(key_purpose, cert_group, pubkey_types,
                      pubkey_type_num, issuer_filename, this),
                      cert_list_behavior(this)
{
    if (list_purpose == LIST_PURPOSE_VIEW_CERT)
    {
        cert_list_behavior.SetLongTabBehavior(VAPP_CERTMAN_LIST_LAUNCH_CONTEXT_MENU);
    }
    else
    {
        cert_list_behavior.SetLongTabBehavior(VAPP_CERTMAN_LIST_IGNORE_LONG_TAP);
    }

    this->list_user = list_user;
    this->list_purpose = list_purpose;
}


void VappCertmanCertListPage::onInit(void)
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(listmenu, VcpListMenu, this);

    VfxRect page_rect = getRect();
    VfxRect rect(0, 0, page_rect.size.width, page_rect.size.height);
    VFX_OBJ_CREATE(progress_popup, VcpActivityIndicator, getMainScr());
    progress_popup->setPos((page_rect.size.width)/2, (page_rect.size.height)/2);
    progress_popup->start();

    if (list_purpose == LIST_PURPOSE_SELECT_MULTIPLE)
    {
        listmenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_MULTI_CHECK_MARK);
        listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);

        VcpTitleBar* titleBar;
        VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);

        /* title as provided by caller */
        titleBar->setTitle(VfxWString(title));
        this->setTopBar(titleBar);
    }
    else if (list_purpose == LIST_PURPOSE_SELECT)
    {
        listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
        VcpTitleBar* titleBar;
        VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);

        /* title as provided by caller */
        titleBar->setTitle(VfxWString(title));
        this->setTopBar(titleBar);
    }
    else if (list_purpose == LIST_PURPOSE_VIEW_CERT)
    {
        listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT_EX); // check
    }
    else
    {
        VFX_ASSERT(0);
    }

    listmenu->setContentProvider(this);

    listmenu->m_signalItemTapped.connect(this, &VappCertmanCertListPage::m_signalTapCertItem);
    listmenu->m_signalItemLongTapped.connect(this, &VappCertmanCertListPage::m_signalItemLongTapped);

    listmenu->m_signalFocusChanged.connect(this, &VappCertmanCertListPage::m_signalCertFocusChanged);

    if (list_purpose == LIST_PURPOSE_SELECT_MULTIPLE)
    {
        VcpToolBar *bbar;
        VFX_OBJ_CREATE(bbar, VcpToolBar, this);
        setBottomBar(bbar);
        bbar->addItem(OK_BUTTON_ID, VfxWString(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
        bbar->addItem(CANCEL_BUTTON_ID, VfxWString(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        bbar->m_signalButtonTap.connect(this, &VappCertmanCertListPage::onToolBarClick);
    }

    /* list size */
    listmenu->setRect(rect);
    listmenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappCertmanCertListPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case OK_BUTTON_ID:
        {
            VfxU32 selected_cert_ids[VAPP_CERTMAN_CERTIFICATES_MAX];
            VfxU32 selected_count = 0;
            VfxU32 total_count = certificate_list_data.get_cert_count();
            for (VfxU32 i =0; i<total_count; i++)
            {
                if (certificate_list_data.get_cert_list_item(i)->is_selected())
                {
                    selected_cert_ids[selected_count++] = VFX_TRUE;
                }
            }
            list_user->vapp_certman_select_certificates_rsp(VFX_TRUE, selected_count, selected_cert_ids);
        }
        break;		
    case CANCEL_BUTTON_ID:
        {
            list_user->vapp_certman_select_certificates_rsp(VFX_FALSE, 0, NULL);
        }
        break;
    }
}

void VappCertmanCertListPage::m_signalTapCertItem(VcpListMenu *sender, VfxU32 index)
{
    if (list_purpose == LIST_PURPOSE_VIEW_CERT)
    {
        VappCertmanViewDetailsPage *page;
        VFX_OBJ_CREATE_EX(page, VappCertmanViewDetailsPage, getMainScr(), (certificate_list_data.get_cert_list_item(index)));
        getMainScr()->pushPage(VappCertmanCertListScr::CERT_DETAILS_PAGE_ID, page);
    }
    else if (list_purpose == LIST_PURPOSE_SELECT)
    {
        /*todo: adjust for none option */
        if (index == 0)
        {
             VfxU32 cert_id = 0;
            list_user->vapp_certman_select_certificates_rsp(VFX_TRUE, 1, &cert_id);
        }
        else
        {
            /* because "none" item shifts the list by one, we need to return the index of 
               one previous item */
            VfxU32 cert_id = certificate_list_data.get_cert_list_item(index-1)->getcertid();
            list_user->vapp_certman_select_certificates_rsp(VFX_TRUE, 1, &cert_id);
        }
    }
    else if (list_purpose == LIST_PURPOSE_SELECT_MULTIPLE)
    {
        certificate_list_data.get_cert_list_item(index)->toggle_select();
    }
}


void VappCertmanCertListPage::m_signalItemLongTapped(VcpListMenu *sender, VfxU32 index)
{
    cert_list_behavior.m_HandleLongTapCertItem(sender, index);
}


void VappCertmanCertListPage::m_signalCertFocusChanged(VcpListMenu *sender, VfxU32 Currindex, VfxU32 Previndex)
{
    focused_index = Currindex;
}

void VappCertmanCertListPage::onBack()
{
    if (list_user)
    {
        list_user->vapp_certman_select_certificates_rsp(VFX_FALSE, 1, NULL);
    }
    else
    {
        VfxPage::onBack();
    }
}


VfxU32 VappCertmanCertListPage::getCount() const
{
    VfxU32 num = certificate_list_data.get_cert_count();

    /* add one for "none" entry */
    if (list_purpose == LIST_PURPOSE_SELECT)
    {
        num++;
    }
    return num;
}


VcpListMenuItemStateEnum VappCertmanCertListPage::getItemState(
    VfxU32 index   // [IN] index of the item
    ) const
{
    if (list_purpose == LIST_PURPOSE_SELECT_MULTIPLE)
    {
        if(certificate_list_data.get_cert_list_item(index)->is_selected())
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_NONE;
    }
}


void VappCertmanCertListPage::updatelistmenu(void)
{
    // mechanism changes in 10.41. This will not work
    if (certificate_list_data.get_cert_count()==0)
    {
        empty_text = VfxWString(STR_ID_VAPP_CERTMAN_NO_CERTS);
    }
    else
    {
        empty_text.setEmpty(); 
    }
    listmenu->updateAllItems();
}


void VappCertmanCertListPage::VappCertmanDataRspHndlr(void* msg)
{
    VFX_OBJ_CLOSE(progress_popup);
    updatelistmenu();
}


void VappCertmanCertListPage::refresh_list(void)
{
    certificate_list_data.refresh();
}


const VappCertmanCertListData& VappCertmanCertListPage::GetCertListDataObj(void)
{
    return certificate_list_data;
}

/*-----------------------certificate list page ends-----------------------------*/

/*-----------------------certificate list behavior begins-----------------------------*/


VappCertmanCertListBehavior::VappCertmanCertListBehavior(VappCertmanCertListPage* list_page)
{
    this->list_page = list_page;
}

void VappCertmanCertListBehavior::SetLongTabBehavior(VappCertmanCertListLongTapBehaviorEnum behavior)
{
    LongTapBehavior = behavior;
}


void VappCertmanCertListBehavior::m_HandleLongTapCertItem(VcpListMenu *sender, VfxU32 index)
{
    if (LongTapBehavior == VAPP_CERTMAN_LIST_LAUNCH_CONTEXT_MENU)
    {
        /* haptic touch feedback */
        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

        VappCertmanCertListMenuPopup *m_menu;

        const VappCertmanCertListData& certificate_list_data = list_page->GetCertListDataObj();
        VappCertmanCertListDataItem* cert_list_item = certificate_list_data.get_cert_list_item(index);

        VFX_OBJ_CREATE_EX(m_menu, VappCertmanCertListMenuPopup, sender, (cert_list_item));
    }
}

/*-----------------------certificate list behavior ends-----------------------------*/

/*-------------------certificate list context menu begins---------------------------*/

VappCertmanCertListMenuPopup::VappCertmanCertListMenuPopup(VappCertmanCertListDataItem* cert_list_item)
{
    this->cert_list_item = cert_list_item;
}

void VappCertmanCertListMenuPopup::onInit(void)
{
    VcpMenuPopup::onInit();

    VfxWString text;
    m_appscr = VfxMainScr::findMainScr(this);

    if (cert_list_item->getdcs() == CERTMAN_DCS_ASCII)
    {
        text.format("%s", cert_list_item->getcertlabel());
    }
    else
    {
        
		text.loadFromMem((VfxWChar*)cert_list_item->getcertlabel());
    }

    setTitle(text);

    VcpMenuPopupItem *item;

    item = createMenuItem(POPUP_MENU_ID_KEY_USAGE, VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_KEY_USAGE));
    insertItem(NULL, NULL, item);

    if (!(cert_list_item->getcertprop() & CERTMAN_PROP_READ_ONLY))
    {
        item = createMenuItem(POPUP_MENU_ID_DELETE, VfxWString(STR_GLOBAL_DELETE));
        insertItem(NULL, NULL, item);
    }
    show(VFX_TRUE);

    m_signalMenuCallback.connect(this, &VappCertmanCertListMenuPopup::m_signalTapItem);
}


void VappCertmanCertListMenuPopup::m_signalTapItem(VcpMenuPopup* menu_popup, VcpMenuPopupEventEnum event_enum, VcpMenuPopupItem* popup_item)
{
    switch(event_enum)
    {
        case VCP_MENU_POPUP_EVENT_ITEM_SELECTED:
        {
            if (popup_item->getId() == POPUP_MENU_ID_KEY_USAGE)
            {
                VappCertmanKeyUsagePage *page;
                VFX_OBJ_CREATE_EX(page, VappCertmanViewKeyUsagePage, m_appscr, (cert_list_item));
                m_appscr->pushPage(VappCertmanCertListScr::KEY_USAGE_PAGE_ID, page);
            }
            else if (popup_item->getId() == POPUP_MENU_ID_DELETE)
            {
                VappCertmanDeleteCnfPopup* m_confirmPopup;
                VFX_OBJ_CREATE_EX(m_confirmPopup, VappCertmanDeleteCnfPopup, m_appscr, (cert_list_item, m_appscr));
                m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
                m_confirmPopup->setText(VfxWString(STR_ID_VAPP_CERTMAN_WARN_DELETE_CERT));
                m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);

                m_confirmPopup->setCustomButton(VfxWString(STR_GLOBAL_DELETE), VfxWString(STR_GLOBAL_CANCEL),
                    VCP_POPUP_BUTTON_TYPE_WARNING,
                    VCP_POPUP_BUTTON_TYPE_CANCEL);

                m_confirmPopup->m_signalButtonClicked.connect(m_confirmPopup, &VappCertmanDeleteCnfPopup::OnClick);

                m_confirmPopup->show(VFX_TRUE);
                m_confirmPopup->setAutoDestory(VFX_FALSE);
            }
            else
            {
                VFX_ASSERT(0);
            }
            break;
        }
        default:
            break;
    }
}


VappCertmanDeleteCnfPopup::VappCertmanDeleteCnfPopup(VappCertmanCertListDataItem* cert_list_item, VfxMainScr *m_appscr)
{
    this->cert_list_item = cert_list_item;
    this->m_appscr = m_appscr;
}


void VappCertmanDeleteCnfPopup::OnClick(VfxObject* sender, VfxId id)
{

    switch(id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VfxRect page_rect = m_appscr->getRect();
            VfxRect rect(1, 1, page_rect.size.width-2, page_rect.size.height-2);
            VappCertmanDeletingProgressPopup *progress_popup;
            VFX_OBJ_CREATE_EX(progress_popup, VappCertmanDeletingProgressPopup, m_appscr,(cert_list_item));
            progress_popup->setPos((page_rect.size.width)/2, (page_rect.size.height)/2);
            progress_popup->start();
            exit(VFX_TRUE);
        }
        break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        default: 
        {
            exit(VFX_TRUE);
        }
        break;
    }
}

/*-------------------certificate list context menu ends---------------------------*/

void VappCertmanViewDetailsPage::setuptoolbar(void)
{
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
    setBottomBar(toolbar);
    
    toolbar->addItem(KEY_USAGE_BUTTON_ID, VfxWString(STR_ID_VAPP_CERTMAN_CERTIFICATE_KEY_USAGE), IMG_ID_CERTMAN_KEY_USAGE);

    if (!(cert_list_item->getcertprop() & CERTMAN_PROP_READ_ONLY))
    {
        toolbar->addItem(DELETE_BUTTON_ID, VfxWString(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    }

    toolbar->m_signalButtonTap.connect(this, &VappCertmanViewDetailsPage::onToolBarClick);
    VfxKeypad::registerHandler(VFX_KEY_CODE_SPECIAL_ALL, this);
}


VappCertmanViewDetailsPage::VappCertmanViewDetailsPage(VappCertmanCertListDataItem* cert_list_item) : VappCertmanDetailsPage(cert_list_item->getcertid())
{
    this->cert_list_item = cert_list_item;
}


void VappCertmanViewDetailsPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case KEY_USAGE_BUTTON_ID:
        {
            VappCertmanKeyUsagePage *page;
            VFX_OBJ_CREATE_EX(page, VappCertmanViewKeyUsagePage, getMainScr(), (cert_list_item));
            getMainScr()->pushPage(VappCertmanCertListScr::KEY_USAGE_PAGE_ID, page);
        }
        break;
    case DELETE_BUTTON_ID:
        {
            VappCertmanDeleteCnfPopup* m_confirmPopup;
            VFX_OBJ_CREATE_EX(m_confirmPopup, VappCertmanDeleteCnfPopup, getMainScr(), (cert_list_item, getMainScr()));
            m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            m_confirmPopup->setText(VfxWString(STR_ID_VAPP_CERTMAN_WARN_DELETE_CERT));
            m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);

            m_confirmPopup->setCustomButton(VfxWString(STR_GLOBAL_DELETE), VfxWString(STR_GLOBAL_CANCEL),
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);

            m_confirmPopup->m_signalButtonClicked.connect(m_confirmPopup, &VappCertmanDeleteCnfPopup::OnClick);

            m_confirmPopup->show(VFX_TRUE);
            m_confirmPopup->setAutoDestory(VFX_FALSE);
        }
        break;
    }
}


VappCertmanViewKeyUsagePage::VappCertmanViewKeyUsagePage(VappCertmanCertListDataItem* cert_list_item) : VappCertmanKeyUsagePage(cert_list_item->key_purpose_all, cert_list_item->key_purpose)
{
    this->cert_list_item = cert_list_item;
}


void VappCertmanViewKeyUsagePage::onToolBarClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
    case KEY_OK_BUTTON_ID:
        {
            /* get data from UI */
            /* update context */

            VfxU32 count_key_usages = 0;
            VfxU32 temp = 0x01;
            cert_list_item->key_purpose = 0;

            for (VfxU32 count = 0; count < VAPP_CERTMAN_TOTAL_KEY_USAGE; count++)
            {
                if ((list_data.key_purpose_all & temp) == temp)
                {
                    if (list_data.list_of_state[count_key_usages] == VFX_TRUE)
                    {
                        cert_list_item->key_purpose |= temp; 
                    }
                    count_key_usages++;
                }
                temp <<= 1;
            }

            VfxRect page_rect = getRect();
            VfxRect rect(1, 1, page_rect.size.width-2, page_rect.size.height-2);
            /* activity to update key usage  */
            VappCertmanKeyUsageUpdateProgressPopup *progress_popup;
            VFX_OBJ_CREATE_EX(progress_popup, VappCertmanKeyUsageUpdateProgressPopup, getMainScr(), (cert_list_item));
            progress_popup->setPos((page_rect.size.width)/2, (page_rect.size.height)/2);
            progress_popup->start();
        }
        break;

    case KEY_CANCEL_BUTTON_ID:
        getMainScr()->popPage();
        break;
    }
}


VappCertmanDeletingProgressPopup::VappCertmanDeletingProgressPopup(VappCertmanCertListDataItem* cert_list_item):delete_req_data(cert_list_item->getcertid(), this)
{
    this->cert_list_item = cert_list_item;
}


void VappCertmanDeletingProgressPopup::VappCertmanDataRspHndlr(void* msg)
{
    VfxPage* tab_container_page = ((VfxMainScr*)getParent())->getPage(VappCertmanCertListScr::TAB_CONTAINER_PAGE_ID);

    if (cert_list_item->getcertgroup() == CERTMAN_CERTGRP_PERSONAL)
    {
        ((VappCertmanCertListTabContainer*)tab_container_page)->get_user_list_page()->refresh_list();
    }
    else
    {
        ((VappCertmanCertListTabContainer*)tab_container_page)->get_auth_list_page()->refresh_list();
    }

    ((VfxMainScr*)getParent())->closePage(VappCertmanCertListScr::CERT_DETAILS_PAGE_ID);
    VappCertmanDeletingProgressPopup *progress_popup = this;
    VFX_OBJ_CLOSE(progress_popup);
}


void VappCertmanKeyUsageUpdateProgressPopup::VappCertmanDataRspHndlr(void* msg)
{
    ((VfxMainScr*)getParent())->popPage();
    VappCertmanKeyUsageUpdateProgressPopup* progress_popup = this;
    VFX_OBJ_CLOSE(progress_popup);
}

VappCertmanKeyUsageUpdateProgressPopup::VappCertmanKeyUsageUpdateProgressPopup(VappCertmanCertListDataItem* cert_list_item) : key_usage_update_req_data(cert_list_item->getcertid(), cert_list_item->getkeypurpose(), this)
{

}


/*  select list ui */

VappCertmanSelectList::~VappCertmanSelectList(void)
{
    VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
    map->remove_by_apphandler(getGroupId());
}


void VappCertmanSelectList::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

     vapp_certman_select_cert_ind_struct *select_cert_ind_p = (vapp_certman_select_cert_ind_struct*)args;
     VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);

	 mmi_id appGroupID = getGroupId();
     map->add(select_cert_ind_p->trans_id, appGroupID);

     mmi_frm_asm_property_struct p;
     mmi_frm_asm_get_property(appGroupID, &p);
     p.f_hide_in_oom = 1;   
     mmi_frm_asm_set_property(appGroupID, &p);
	
    VappCertmanSelectCertScr *scr;
    VFX_OBJ_CREATE_EX (scr, VappCertmanSelectCertScr, this, (args));
    scr->show();
}

/*----------screen---------------*/

VappCertmanSelectCertScr::VappCertmanSelectCertScr(void* msg)
{
    vapp_certman_select_cert_ind_struct *temp_select_certificate_ind = (vapp_certman_select_cert_ind_struct*)msg;
    memcpy(&select_cert_ind, temp_select_certificate_ind, sizeof(vapp_certman_select_cert_ind_struct));
}

void VappCertmanSelectCertScr::on1stReady(void)
{
    VfxMainScr::on1stReady();

    /* create page and push */
    VappCertmanCertListPage *page;
    VappCertmanCertListPage::vapp_certman_list_purpose_enum list_purpose;
    if (select_cert_ind.multiple_selection_flag == VFX_TRUE)
    {
        list_purpose = VappCertmanCertListPage::LIST_PURPOSE_SELECT_MULTIPLE;
    }
    else
    {
        list_purpose = VappCertmanCertListPage::LIST_PURPOSE_SELECT;
    }
    VFX_OBJ_CREATE_EX(page, VappCertmanCertListPage, this, 
        (select_cert_ind.cert_group , select_cert_ind.key_type, select_cert_ind.title, list_purpose,this));
    pushPage(0, page);
}

void VappCertmanSelectCertScr::vapp_certman_select_certificates_rsp(VfxBool result, VfxU32 count, VfxU32* certificate_ids)
{
    vapp_certman_select_cert_rsp_struct *data;
    data = (vapp_certman_select_cert_rsp_struct*) OslConstructDataPtr(sizeof(vapp_certman_select_cert_rsp_struct));
    data->result = result;
    data->trans_id = select_cert_ind.trans_id;

    if (result == VFX_TRUE)
    {
        data->count = count;
        for (VfxU32 temp_count = 0; temp_count < count; temp_count++)
        {
            data->cert_ids[temp_count] = certificate_ids[temp_count];
        }
    }

    VappCertmanUtilities::vapp_certman_send_msg_on_queue(
        MOD_MMI,
        select_cert_ind.source_mod,
        (void*)data,
        (msg_type)MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
     
    VfxAppLauncher::terminate(getApp()->getGroupId());
}


/* select user ui */

VFX_IMPLEMENT_CLASS("VappCertmanSelectUserCertListApp", VappCertmanSelectUserCertListApp, VfxApp);

void VappCertmanSelectUserCertListApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    VappCertmanSelectUserCertScr *scr;
    VFX_OBJ_CREATE_EX (scr, VappCertmanSelectUserCertScr, this, (args));
    scr->show();
}


VappCertmanSelectUserCertListApp::~VappCertmanSelectUserCertListApp(void)
{
    VappCertmanIfMapList *map = VFX_OBJ_GET_INSTANCE(VappCertmanIfMapList);
    map->remove_by_apphandler(getGroupId());
}

/* screen */

VappCertmanSelectUserCertScr::VappCertmanSelectUserCertScr(void* msg)
{
    vapp_certman_select_user_cert_ind_struct *temp_select_user_certificate_ind = (vapp_certman_select_user_cert_ind_struct*)msg;
    memcpy(&select_user_cert_ind, temp_select_user_certificate_ind, sizeof(vapp_certman_select_user_cert_ind_struct));
}

void VappCertmanSelectUserCertScr::on1stReady(void)
{
    VfxMainScr::on1stReady();

    /* create page and push */
    VappCertmanCertListPage *page;

    VFX_OBJ_CREATE_EX(page, VappCertmanCertListPage, this, 
        (select_user_cert_ind.key_purpose,
        CERTMAN_CERTGRP_NONE,
        VAPP_CERTMAN_PUBKEY_TYPE_ALL,
        VappCertmanCertListPage::LIST_PURPOSE_SELECT,
        (VfxU32*)select_user_cert_ind.pubkey_types,
        select_user_cert_ind.pubkey_type_num,
        select_user_cert_ind.issuer_filename,
        this));

    pushPage(0, page);
}


void VappCertmanSelectUserCertScr::vapp_certman_select_certificates_rsp(VfxBool result, VfxU32 count, VfxU32* cert_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_certman_select_user_cert_rsp_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */

    data =
        (vapp_certman_select_user_cert_rsp_struct*)
        OslConstructDataPtr(sizeof(vapp_certman_select_user_cert_rsp_struct));
    data->personal_cert_id = *cert_id;
    data->result = result;
    data->trans_id = select_user_cert_ind.trans_id;
    /* Send the response message */
    VappCertmanUtilities::vapp_certman_send_msg_on_queue(
        MOD_MMI,
        select_user_cert_ind.source_mod,
        (void*)data,
        (msg_type)MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_RSP);
}


/*---------------------------incorporate settings framework----------------------------------------*/
void vapp_certman_launch_cert_setting(VfxMainScr* scr)
{

    mmi_id groupId = VfxAppLauncher::createCui(
        VAPP_CERTMAN,
        VFX_OBJ_CLASS_INFO(VappCertmanListApp),
        scr->getGroupId(), NULL, 0);

    VfxAppLauncher::runCui(groupId);
}

#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* __CERTMAN_SUPPORT__ */
