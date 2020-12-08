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
 *  vapp_sms_setting_content.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#ifdef __MMI_MESSAGES_TEMPLATE__
#include "GlobalResDef.h"
#include "vapp_text_template_scrn.h"
#include "vapp_text_template_core.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "mmi_rp_vapp_msg_def.h"
#include "vcp_include.h"
//#include "vapp_msg_misc_cp.h" // for iterator view
#include "vapp_uc_gprot.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vfx_adp_device.h"

#ifdef __MMI_SMS_COMPOSER__
    #include "vcui_sms_composer_gprot.h"
#endif

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "UcSrvGprot.h"
    #include "Unicodexdcl.h"
    #include "CustDataRes.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/*****************************************************************************
 * Class VappTextTemplateListPage Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappTextTemplateListPage", VappTextTemplateListPage, VfxPage);

VappTextTemplateListPage::VappTextTemplateListPage():
    m_listMenu(NULL),
    m_templateList(NULL),
    m_initTemplateListDone(VFX_FALSE)
{

}

void VappTextTemplateListPage::onInit()
{
    Super::onInit();

    VFX_OBJ_CREATE(m_title, VcpTitleBar, this);
    m_title->setTitle((VfxResId)STR_ID_VAPP_SMS_TEMPLATE_SELECT);
    setTopBar(m_title);

    //VFX_OBJ_CREATE(m_templateList, SmsTemplateList, this);
    m_templateList = VFX_OBJ_GET_INSTANCE(SmsTemplateList);
    m_templateList->m_signalInitDone.connect(this, &Self::onLoadTemplateListDone);
    onLoadTemplateListDone(m_templateList, VFX_TRUE);
}

void VappTextTemplateListPage::onDeinit()
{
    if (m_templateList)
    {
        m_templateList->m_signalAddTemplate.disconnect(this, &Self::onUpdateTemplateList);
        m_templateList->m_signalDelTemplate.disconnect(this, &Self::onUpdateTemplateList);
    }

    Super::onDeinit();
}

void VappTextTemplateListPage::closePage()
{
    VFX_OBJ_ASSERT_VALID(this);
    VappTextTemplateListPage *self = this;
    VfxId pageId = getMainScr()->getPageId(self);
    getMainScr()->closePage(pageId);
}

VfxU32 VappTextTemplateListPage::getCount() const
{
    return m_templateList->getListSize();
}

VfxBool VappTextTemplateListPage::getItemText(VfxU32 index,VcpListMenuFieldEnum fieldType,VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        VFX_ASSERT(index < m_templateList->getListSize());

        const VfxWChar *content = m_templateList->getContentShortcut(index);

        if (content[0] != '\0')
        {
            text.loadFromMem(content);
        }
        else
        {
            text.loadFromRes(STR_GLOBAL_EMPTY_LIST);
        }
    }

    return VFX_TRUE;
}

VfxBool VappTextTemplateListPage::getMenuEmptyText(VfxWString & text,VcpListMenuTextColorEnum & color)
{
    if (0 == m_templateList->getListSize())
    {
        text.loadFromRes(STR_ID_VAPP_MSG_NO_MESSAGES);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappTextTemplateListPage::onUpdateTemplateList(VfxObject *sender, VfxU16 templateId, VfxU16 listIndex)
{
    m_listMenu->resetAllItems(VFX_TRUE);
}

void VappTextTemplateListPage::onItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(index < m_templateList->getListSize());

    if(sender == m_listMenu)
    {
        VfxU16 templateId = m_templateList->getTemplateId(index);

        m_signalTemplateTapped.postEmit(
            this, 
            VFX_WSTR_MEM(m_templateList->getContent(index)), 
            templateId);
    }
}

void VappTextTemplateListPage::onLoadTemplateListDone(VfxObject *sender, VfxBool result)
{
    m_templateList->m_signalInitDone.disconnect(this, &Self::onLoadTemplateListDone);

    if (result)
    {
        VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

        m_listMenu->setAutoAnimate(VFX_FALSE);
        VfxSize parentSize = getSize();
        m_listMenu->setSize(parentSize);
        m_listMenu->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
        m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
        m_listMenu->setContentProvider(this);
        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_listMenu->m_signalItemTapped.connect(this, &Self::onItemTapped);
        m_templateList->m_signalAddTemplate.connect(this, &Self::onUpdateTemplateList);
        m_templateList->m_signalDelTemplate.connect(this, &Self::onUpdateTemplateList);
    }
    else
    {

    }
}

void VappTextTemplateListPage::setListMenuSize(VfxS32 width, VfxS32 height)
{
    m_listMenu->setSize(width, height);
}
void VappTextTemplateListPage::setListMenuPos(VfxS32 x, VfxS32 y)
{
    m_listMenu->setPos(x, y);
}
void VappTextTemplateListPage::setTitleString(VfxWString str)
{
    m_title->setTitle(str);
}

void VappTextTemplateListPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

/*****************************************************************************
 * Class VappTextTemplatePage Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappTextTemplatePage", VappTextTemplatePage, VfxPage);

VappTextTemplatePage::VappTextTemplatePage():
    m_listMenu(NULL),
    m_templateList(NULL),
    m_toolBar(NULL),
    m_hasCheckBox(VFX_FALSE),
    m_initTemplateListDone(VFX_FALSE),
    m_deleteConfirmed(VFX_FALSE),
    m_curTemplateId(SRV_SMS_TEMPLATE_INVALIDE_ID),
    m_selectCount(0)
{
    memset(m_checkBit, 0x00, VAPP_SMS_TEMPLATE_CHECK_BIT_U8_NUM);
}

void VappTextTemplatePage::onInit()
{
    VfxPage::onInit();

    m_templateList = VFX_OBJ_GET_INSTANCE(SmsTemplateList);
    onLoadTemplateListDone(m_templateList, VFX_TRUE);
}
void VappTextTemplatePage::onDeinit()
{
    VfxPage::onDeinit();
    m_templateList->m_signalAddTemplate.disconnect(this, &Self::onAddTemplate);
    m_templateList->m_signalDelTemplate.disconnect(this, &Self::onDelTemplate);
}

VfxU32 VappTextTemplatePage::getCount() const
{
    return m_templateList->getListSize();
}

VfxBool VappTextTemplatePage::getItemText(VfxU32 index,VcpListMenuFieldEnum fieldType,VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        VFX_ASSERT(index < m_templateList->getListSize());

        const VfxWChar *content = m_templateList->getContentShortcut(index);

        if (content[0] != '\0')
        {
            text.loadFromMem(content);
        }
        else
        {
            text.loadFromRes(STR_GLOBAL_EMPTY_LIST);
        }
    }

    return VFX_TRUE;
}

VfxBool VappTextTemplatePage::getMenuEmptyText(VfxWString & text,VcpListMenuTextColorEnum & color)
{
    if (0 == m_templateList->getListSize())
    {
        text.loadFromRes(STR_ID_VAPP_MSG_NO_MESSAGES);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxBool VappTextTemplatePage::getCheckedState(VfxU16 templateId) const
{
    VfxU8 check = m_checkBit[templateId/8];

    if (check&(0x01<<(templateId%8)))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappTextTemplatePage::setCheckedState(VfxU16 templateId, VfxBool set)
{
    VfxU8 check = m_checkBit[templateId/8];
    VfxU8 temp;

    if (set)
    {
        if (!getCheckedState(templateId))
        {
            temp = 0x01<<(templateId%8);
            check |= temp;
            m_selectCount++;
            onUpdateMarkToolBar(set);
        }
    }
    else
    {
        if (getCheckedState(templateId))
        {
            temp = ~(0x01<<(templateId%8));
            check &= temp;
            VFX_ASSERT(m_selectCount > 0);
            m_selectCount--;
            onUpdateMarkToolBar(set);
        }
    }

    m_checkBit[templateId/8] = check;
}

void VappTextTemplatePage::setAllCheckedState(VfxBool set)
{
    VfxU16 index;

    VfxU16 total = m_templateList->getListSize();
    VfxU16 templateId;
    for(index = 0; index < total; index++)
    {
        templateId = m_templateList->getTemplateId(index);
        setCheckedState(templateId, set);
    }
}

VcpListMenuItemStateEnum VappTextTemplatePage::getItemState(VfxU32 index) const
{
    if (m_hasCheckBox)
    {
        VfxU16 templateId = m_templateList->getTemplateId(index);

        if (getCheckedState(templateId))
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

void VappTextTemplatePage::onAddTemplate(VfxObject *sender, VfxU16 templateId, VfxU16 listIndex)
{
    m_listMenu->resetAllItems(VFX_TRUE);

    if (!m_hasCheckBox)
    {
        onUpdateNormalToolBar();
    }
    else
    {
        onUpdateMarkToolBar(VFX_FALSE);
    }
}

void VappTextTemplatePage::onDelTemplate(VfxObject *sender, VfxU16 templateId, VfxU16 listIndex)
{
    m_listMenu->resetAllItems(VFX_TRUE);

    if (!m_hasCheckBox)
    {
        onUpdateNormalToolBar();
    }
    else
    {
        if (getCheckedState(templateId))
        {
            setCheckedState(templateId, VFX_FALSE);
        }
        else
        {
            onUpdateMarkToolBar(VFX_TRUE);
        }
    }
}

void VappTextTemplatePage::onChangeToNormalMode()
{
    if (m_listMenu != NULL)
    {
        m_listMenu->m_signalItemSelectionStateChanged.disconnect(this, &Self::onItemStateChanged);
    }
    m_hasCheckBox = VFX_FALSE;
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_listMenu->m_signalItemTapped.connect(this, &Self::onItemTapped);

    if (m_toolBar)
    {
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_SELECT_ALL);
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_UNSELECT_ALL);
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_DELETE);
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_CANCEL);
    }
    m_toolBar->addItem(ITEM_ID_TOOLBAR1_ADD, (VfxResId)STR_GLOBAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    m_toolBar->addItem(ITEM_ID_TOOLBAR1_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

    onUpdateNormalToolBar();
}

void VappTextTemplatePage::onChangeToMarkMode()
{
    if (m_listMenu != NULL)
    {
        m_listMenu->m_signalItemTapped.disconnect(this, &Self::onItemTapped);
    }
    m_hasCheckBox = VFX_TRUE;
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
    m_listMenu->m_signalItemSelectionStateChanged.connect(this, &Self::onItemStateChanged);

    if (m_toolBar)
    {
        m_toolBar->removeItem(ITEM_ID_TOOLBAR1_ADD);
        m_toolBar->removeItem(ITEM_ID_TOOLBAR1_DELETE);
    }

    m_toolBar->addItem(ITEM_ID_TOOLBAR2_SELECT_ALL, (VfxResId)VCP_STR_TOOL_BAR_SELECT_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_toolBar->addItem(ITEM_ID_TOOLBAR2_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_toolBar->addItem(ITEM_ID_TOOLBAR2_CANCEL, (VfxResId)STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    m_toolBar->setDisableItem(ITEM_ID_TOOLBAR2_DELETE, VFX_TRUE);

    setAllCheckedState(VFX_FALSE);
    m_listMenu->updateAllItems();
}

void VappTextTemplatePage::onUpdateNormalToolBar()
{
    if (m_templateList->getListSize())
    {
        m_toolBar->setDisableItem(ITEM_ID_TOOLBAR1_DELETE, VFX_FALSE);
    }
    else
    {
        m_toolBar->setDisableItem(ITEM_ID_TOOLBAR1_DELETE, VFX_TRUE);
    }
}

void VappTextTemplatePage::onUpdateMarkToolBar(VfxBool set)
{
    VfxU16 Size = m_templateList->getListSize();

    if ((m_selectCount + 1) == Size && !set)
    {
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_UNSELECT_ALL);
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_DELETE);
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_CANCEL);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR2_SELECT_ALL,
            (VfxResId)VCP_STR_TOOL_BAR_SELECT_ALL,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR2_DELETE,
            (VfxResId)STR_GLOBAL_DELETE,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR2_CANCEL,
            (VfxResId)STR_GLOBAL_CANCEL,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    }
    else if (m_selectCount == Size)
    {
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_SELECT_ALL);
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_DELETE);
        m_toolBar->removeItem(ITEM_ID_TOOLBAR2_CANCEL);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR2_UNSELECT_ALL,
            (VfxResId)VCP_STR_TOOL_BAR_UNSELECT_ALL,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR2_DELETE,
            (VfxResId)STR_GLOBAL_DELETE,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR2_CANCEL,
            (VfxResId)STR_GLOBAL_CANCEL,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    }

    if (m_selectCount)
    {
        m_toolBar->setDisableItem(ITEM_ID_TOOLBAR2_DELETE, VFX_FALSE);
    }
    else
    {
        m_toolBar->setDisableItem(ITEM_ID_TOOLBAR2_DELETE, VFX_TRUE);
    }
}

void VappTextTemplatePage::onItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(index < m_templateList->getListSize());

    if(sender == m_listMenu && !m_hasCheckBox)
    {
        VfxU16 templateId = m_templateList->getTemplateId(index);

        VappTextTemplateViewerPage *page;
        VFX_OBJ_CREATE_EX(page, VappTextTemplateViewerPage, getMainScr(), (templateId));
        getMainScr()->pushPage(VFX_ID_NULL, page);
    }
}

void VappTextTemplatePage::onItemLongTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(index < m_templateList->getListSize());

    if(sender == m_listMenu && !m_hasCheckBox)
    {
        m_curTemplateId = m_templateList->getTemplateId(index);
        VcpMenuPopup *menuPopup;
        VFX_OBJ_CREATE(menuPopup, VcpMenuPopup, this);
    	menuPopup->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SMS_MESSAGE_OPTION));
        menuPopup->addItem(ITEM_ID_LONGTAP_ID_USE, (VfxResId)STR_GLOBAL_USE);
        menuPopup->addItem(ITEM_ID_LONGTAP_ID_DELETE, (VfxResId)STR_GLOBAL_DELETE);
        menuPopup->addItem(ITEM_ID_LONGTAP_ID_EDIT, (VfxResId)STR_GLOBAL_EDIT);
        menuPopup->m_signalMenuCallback.connect(this, &Self::onLongTappedMenuPopupClicked); 
		menuPopup->showMenu();

        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
    }
}

void VappTextTemplatePage::onItemStateChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    VfxU16 templateId = m_templateList->getTemplateId(index);

    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        setCheckedState(templateId,VFX_TRUE);
    }
    else
    {
        setCheckedState(templateId,VFX_FALSE);
    }
}

void VappTextTemplatePage::onLongTappedMenuPopupClicked(VcpMenuPopup *sender, VcpMenuPopupEventEnum eventType, VcpMenuPopupItem *item)
{
    if (VCP_MENU_POPUP_EVENT_ITEM_SELECTED == eventType)
    {
        VfxId id = item->getId();

        if (id == ITEM_ID_LONGTAP_ID_DELETE)
        {
            VcpConfirmPopup *confirm;
            VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
            confirm->setText((VfxResId)STR_ID_VAPP_SMS_DELETE_TEMPLATE_QUERY);
            confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
            confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            confirm->setCustomButton(
                (VfxResId)STR_GLOBAL_DELETE,
                (VfxResId)STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            confirm->m_signalButtonClicked.connect(this, &Self::onPreDeleteSingleTemplate);
            confirm->m_signalPopupState.connect(this, &Self::onDeleteSingleTemplate);
            confirm->setAutoDestory(VFX_TRUE);
            confirm->show(VFX_TRUE);
        }
        else
        {
            SmsTemplate *textTemplate;
            VFX_OBJ_CREATE_EX(textTemplate, SmsTemplate, this, (m_curTemplateId));
			
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
            VappUcEntryStruct data;
            memset(&data, 0, sizeof(VappUcEntryStruct));
            data.text_buffer = (U8*)textTemplate->getContent();
            data.text_num = (U16)wcslen((wchar_t*)textTemplate->getContent())*ENCODING_LENGTH;

            if (id == ITEM_ID_LONGTAP_ID_USE)
            {
                data.info_type = SRV_UC_INFO_TYPE_SMS_TEMPLATE;
                data.operation = UC_OPERATION_WRITE_NEW_MSG;
                data.type = SRV_UC_STATE_WRITE_NEW_MSG;

                mmi_id cuiId;
                cuiId = vcui_unifiedcomposer_create(getApp()->getGroupId(), &data);
                if (cuiId != GRP_ID_INVALID)
                {
                    vfxSetCuiCallerScr(cuiId, getMainScr());
                    vcui_unifiedcomposer_run(cuiId);
                }
                //vappUcAppLauncher(&data);
            }
            else if (id == ITEM_ID_LONGTAP_ID_EDIT)
            {
                data.msg_id = m_curTemplateId;
                data.info_type = SRV_UC_INFO_TYPE_SMS_TEMPLATE;
                data.operation = UC_OPERATION_EDIT_SMS_TEMPLATE;
                data.type = SRV_UC_STATE_EDIT_EXISTED_MSG;
                data.msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
            }

                mmi_id cuiId;
                cuiId = vcui_unifiedcomposer_create(getApp()->getGroupId(), &data);
                if (cuiId != GRP_ID_INVALID)
                {
                    vfxSetCuiCallerScr(cuiId, getMainScr());
                    vcui_unifiedcomposer_run(cuiId);
                }
            }
#endif /* (__MMI_UNIFIED_COMPOSER__) || (__MMI_MMS_STANDALONE_COMPOSER__)*/
#ifdef __MMI_SMS_COMPOSER__
			mmi_id smsComposerCui = 0;
			VcuiSmsComposerEntryStruct *entryData;
			VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
			vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );

            if (id == ITEM_ID_LONGTAP_ID_USE)
            {
                entryData.operation = VCUI_SMS_COMPOSER_OPERATION_NEW;

            }
            else if (id == ITEM_ID_LONGTAP_ID_EDIT)
            {
                entryData.msg_id = m_curTemplateId;
                entryData.operation = VCUI_SMS_COMPOSER_OPERATION_EDIT;             
            }
		
			// set text
			entryData->text_buffer = (VfxChar*)textTemplate->getContent();
			entryData->text_num = mmi_ucs2strlen((CHAR*)textTemplate->getContent());
											
			smsComposerCui = vcui_sms_composer_create(getApp()->getGroupId());
			if(smsComposerCui !=  GRP_ID_INVALID)
			{
				vcui_sms_composer_set_entry_data(smsComposerCui, entryData);		
				vfxSetCuiCallerScr(smsComposerCui, getMainScr());
				vcui_sms_composer_run(smsComposerCui);
			}
			VFX_FREE_MEM(entryData);
#endif /* __MMI_SMS_COMPOSER__ */
        }
    }
}

mmi_ret VappTextTemplatePage::onProc(mmi_event_struct * evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
        {
            cui_msgcomposer_evt_struct *ucEvt = (cui_msgcomposer_evt_struct *)evt;
            /* just close it */
            vcui_unifiedcomposer_close(ucEvt->sender_id);
            break;
        }
    }

    return MMI_RET_OK;
}

void VappTextTemplatePage::onBack()
{
    if (m_hasCheckBox)
    {
        onChangeToNormalMode();
    }
    else
    {
        Super::onBack();
    }
}

void VappTextTemplatePage::onToolbarTapped(VfxObject *sender, VfxId id)
{
    if (m_toolBar == sender)
    {
        if (m_hasCheckBox)
        {
            if (id == ITEM_ID_TOOLBAR2_SELECT_ALL)
            {
                setAllCheckedState(VFX_TRUE);
                m_listMenu->updateAllItems();
            }
            else if (id == ITEM_ID_TOOLBAR2_UNSELECT_ALL)
            {
                setAllCheckedState(VFX_FALSE);
                m_listMenu->updateAllItems();
            }
            else if (id == ITEM_ID_TOOLBAR2_DELETE)
            {
                VfxChar asciiString[10];
                VfxWChar ucs2String[10];
                VfxWChar PopString[100];
                    mmi_ucs2cpy((S8*) PopString, (S8*) GetString(STR_ID_VAPP_SMS_DEL_SELECT_TEMPLATES));
                sprintf((S8*) asciiString, "(%d)?", m_selectCount);
                mmi_asc_to_ucs2((S8*) ucs2String, (S8*) asciiString);
                mmi_ucs2cat((S8*) PopString, (S8*) ucs2String);
              
                VcpConfirmPopup *deleteConfirm;
                VFX_OBJ_CREATE(deleteConfirm, VcpConfirmPopup, this);
                deleteConfirm->setInfoType(VCP_POPUP_TYPE_WARNING);
                deleteConfirm->setText(PopString);
                deleteConfirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
                deleteConfirm->setCustomButton(
                    (VfxResId)STR_GLOBAL_DELETE,
                    (VfxResId)STR_GLOBAL_CANCEL,
                    VCP_POPUP_BUTTON_TYPE_WARNING,
                    VCP_POPUP_BUTTON_TYPE_CANCEL);

                deleteConfirm->m_signalButtonClicked.connect(this, &Self::onPreDeleteTemplate);
                deleteConfirm->m_signalPopupState.connect(this, &Self::onDeleteTemplate);
                deleteConfirm->setAutoDestory(VFX_TRUE);
                deleteConfirm->show(VFX_TRUE);
            }
            else if (id == ITEM_ID_TOOLBAR2_CANCEL)
            {
                onChangeToNormalMode();
            }
        }
        else
        {
            if (id == ITEM_ID_TOOLBAR1_ADD)
            {
                if (m_templateList->isTemplateFull())
                {
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        VFX_WSTR_RES(STR_ID_VAPP_SMS_TEMPLATE_FULL));
                }
                else
                {
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
                    VappUcEntryStruct data;
                    memset(&data, 0, sizeof(VappUcEntryStruct));

                    data.info_type = SRV_UC_INFO_TYPE_SMS_TEMPLATE;
                    data.operation = UC_OPERATION_WRITE_NEW_SMS_TEMPLATE;
                    data.type = SRV_UC_STATE_WRITE_NEW_MSG;    

                    mmi_id cuiId;
                    cuiId = vcui_unifiedcomposer_create(getApp()->getGroupId(), &data);
                    if (cuiId != GRP_ID_INVALID)
                    {
                        vfxSetCuiCallerScr(cuiId, getMainScr());
                        vcui_unifiedcomposer_run(cuiId);
                    }
#endif /* (__MMI_UNIFIED_COMPOSER__) || (__MMI_MMS_STANDALONE_COMPOSER__)*/
#ifdef __MMI_SMS_COMPOSER__					
				    mmi_id smsComposerCui = 0;
				    VcuiSmsComposerEntryStruct *entryData;
				    VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
				    vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );				    

					// set operation method to a existed msg, only for message app internal use
					entryData->operation = VCUI_SMS_COMPOSER_OPERATION_NEW;

				    smsComposerCui = vcui_sms_composer_create(getApp()->getGroupId());
				    if(smsComposerCui !=  GRP_ID_INVALID)
				    {
				        vcui_sms_composer_set_entry_data(smsComposerCui, entryData);        
				        vfxSetCuiCallerScr(smsComposerCui, getMainScr());
				        vcui_sms_composer_run(smsComposerCui);
				    }
				    VFX_FREE_MEM(entryData);
#endif /* __MMI_SMS_COMPOSER__ */
                }
            }
            else if (id == ITEM_ID_TOOLBAR1_DELETE)
            {
                onChangeToMarkMode();
            }
        }
    }
}


void VappTextTemplatePage::onPreDeleteSingleTemplate(VfxObject *sender, VfxId id)
{
    VFX_UNUSED(sender);

    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_deleteConfirmed = VFX_TRUE;
    }
}

void VappTextTemplatePage::onDeleteSingleTemplate(VfxBasePopup *popup, VfxBasePopupStateEnum state)
{
    //VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONCONFIRMPOPUPSTATECHANGED, state, m_deleteConfirmed);

    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        if (m_deleteConfirmed)
        {
            srv_sms_template_delete(m_curTemplateId);

            m_deleteConfirmed = VFX_FALSE;
        }
    }
}

void VappTextTemplatePage::onPreDeleteTemplate(VfxObject *sender, VfxId id)
{
    VFX_UNUSED(sender);

    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_deleteConfirmed = VFX_TRUE;
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        //do nothing
    }
}

void VappTextTemplatePage::onDeleteTemplate(
    VfxBasePopup *popup, 
    VfxBasePopupStateEnum state)
{
    //VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONCONFIRMPOPUPSTATECHANGED, state, m_deleteConfirmed);

    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        if (m_deleteConfirmed)
        {
            VfxS16 index;
            VfxU16 templateId;
            VfxU16 listSize = m_templateList->getListSize();
            for (index = listSize-1; index >= 0; index--)
            {
                templateId = m_templateList->getTemplateId(index);
                if (getCheckedState(templateId))
                {
                    m_templateList->onDelete(templateId);
                }
                setCheckedState(templateId, VFX_FALSE);
            }
            m_deleteConfirmed = VFX_FALSE;

            onChangeToNormalMode();
        }
    }
}

void VappTextTemplatePage::onLoadTemplateListDone(VfxObject *sender, VfxBool result)
{
    m_templateList->m_signalInitDone.disconnect(this, &Self::onLoadTemplateListDone);

    if (result)
    {
        VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
        m_listMenu->setPos(0, 0);
        VfxSize parentSize = getSize();
        m_listMenu->setSize(parentSize);
        m_listMenu->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);
        m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
        m_listMenu->setContentProvider(this);
        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_listMenu->m_signalItemTapped.connect(this, &Self::onItemTapped);
        m_listMenu->m_signalItemLongTapped.connect(this, &Self::onItemLongTapped);
        m_templateList->m_signalAddTemplate.connect(this, &Self::onAddTemplate);
        m_templateList->m_signalDelTemplate.connect(this, &Self::onDelTemplate);

        VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR1_ADD,
            (VfxResId)STR_GLOBAL_ADD,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR1_DELETE,
            (VfxResId)STR_GLOBAL_DELETE,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
        m_toolBar->m_signalButtonTap.connect(this, &Self::onToolbarTapped);

        if (m_templateList->getListSize())
        {
            m_toolBar->setDisableItem(ITEM_ID_TOOLBAR1_DELETE, VFX_FALSE);
        }
        else
        {
            m_toolBar->setDisableItem(ITEM_ID_TOOLBAR1_DELETE, VFX_TRUE);
        }

        setBottomBar(m_toolBar);
    }
    else
    {

    }
}

void VappTextTemplatePage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

/*****************************************************************************
 * Class VappTextTemplateViewerPage Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappTextTemplateViewerPage", VappTextTemplateViewerPage, VfxPage);

VappTextTemplateViewerPage::VappTextTemplateViewerPage():
    m_templateView(NULL),
    m_toolBar(NULL),
    m_template(NULL),
    m_templateId(0),
    m_deleteConfirmed(VFX_FALSE)
{
}

VappTextTemplateViewerPage::VappTextTemplateViewerPage(VfxU16 templateId):
    m_templateView(NULL),
    m_toolBar(NULL),
    m_template(NULL),
    m_templateId(templateId),
    m_deleteConfirmed(VFX_FALSE)
{
}

void VappTextTemplateViewerPage::onInit()
{
    Super::onInit();

    setBgColor(VFX_COLOR_RES(VAPP_SMS_VIEWER_TEXT_BACKGROUND_COLOR));

    VFX_OBJ_CREATE_EX(m_template, SmsTemplate, this, (m_templateId));

    SmsTemplateList *templateList = VFX_OBJ_GET_INSTANCE(SmsTemplateList);
    templateList->m_signalDelTemplate.connect(this, &Self::onDelTemplate);

    VFX_OBJ_CREATE(m_templateView, VcpTextView, this);
    m_templateView->setPos(0, 0);
    VfxSize parentSize = getSize();
    m_templateView->setSize(parentSize);
    m_templateView->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_templateView->setMargins(
        TEXT_VIEW_MARGIN_LEFT,
        TEXT_VIEW_MARGIN_TOP,
        TEXT_VIEW_MARGIN_LEFT,
        TEXT_VIEW_MARGIN_BUTTOM);
    m_templateView->setText(m_template->getContent(), NULL); // set text without any text format
    m_templateView->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    m_templateView->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(VAPP_SMS_TEXT_COLOR));
#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__

    VcpIconTable *iconTable = VappUcEmoticon::getEmotionTablePointer();
    VfxU32 tableSize = VappUcEmoticon::getEmotionTableSize();
    m_templateView->setIconMode(VFX_TRUE, iconTable, (VfxU8)tableSize);
#endif

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(
        TOOLBAR_ID_USE,
        (VfxResId)STR_GLOBAL_USE,
        IMG_ID_VAPP_SMS_TOOLBAR_USE);
    m_toolBar->addItem(
        TOOLBAR_ID_EDIT,
        (VfxResId)STR_GLOBAL_EDIT,
        VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
    m_toolBar->addItem(
        TOOLBAR_ID_DELETE,
        (VfxResId)STR_GLOBAL_DELETE,
        VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_toolBar->m_signalButtonTap.connect(this, &Self::onToolBarClick); // connect tool bar signal
    setBottomBar(m_toolBar);
}

void VappTextTemplateViewerPage::onDeinit()
{
    SmsTemplateList *templateList = VFX_OBJ_GET_INSTANCE(SmsTemplateList);
    templateList->m_signalAddTemplate.disconnect(this, &Self::onDelTemplate);

    Super::onDeinit();
}

void VappTextTemplateViewerPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    if (id == TOOLBAR_ID_DELETE)
    {
        VcpConfirmPopup *confirm;
        VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
        confirm->setText((VfxResId)STR_ID_VAPP_SMS_DELETE_TEMPLATE_QUERY);
        confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
        confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        confirm->setCustomButton(
            (VfxResId)STR_GLOBAL_DELETE,
            (VfxResId)STR_GLOBAL_CANCEL,
            VCP_POPUP_BUTTON_TYPE_WARNING,
            VCP_POPUP_BUTTON_TYPE_CANCEL);
        confirm->m_signalButtonClicked.connect(this, &Self::onPreDeleteTemplate);
        confirm->m_signalPopupState.connect(this, &Self::onDeleteTemplate);
        confirm->setAutoDestory(VFX_TRUE);
        confirm->show(VFX_TRUE);
    }
    else
    {
        const WCHAR *content = m_template->getContent();

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
        VappUcEntryStruct data;
        memset(&data, 0, sizeof(VappUcEntryStruct));
        data.text_buffer = (U8*)m_template->getContent();
        data.text_num = (U16)wcslen((wchar_t*)m_template->getContent())*ENCODING_LENGTH;

        if (id == TOOLBAR_ID_USE)
        {
            data.info_type = SRV_UC_INFO_TYPE_SMS_TEMPLATE;
            data.operation = UC_OPERATION_WRITE_NEW_MSG;
            data.type = SRV_UC_STATE_WRITE_NEW_MSG;
        }
        else if (id == TOOLBAR_ID_EDIT)
        {
            VFX_OBJ_ASSERT_VALID(this);
            VappTextTemplateViewerPage *self = this;
            VfxId pageId = getMainScr()->getPageId(self);

            data.msg_id = m_templateId;
            data.info_type = SRV_UC_INFO_TYPE_SMS_TEMPLATE;
            data.operation = UC_OPERATION_EDIT_SMS_TEMPLATE;
            data.type = SRV_UC_STATE_EDIT_EXISTED_MSG;
            data.msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
        }

            mmi_id cuiId;
            cuiId = vcui_unifiedcomposer_create(getApp()->getGroupId(), &data);
            if (cuiId != GRP_ID_INVALID)
            {
                mmi_frm_group_set_caller_proc(cuiId, onCuiProc, NULL);
                //vfxSetCuiCallerScr(cuiId, getMainScr());
                vcui_unifiedcomposer_run(cuiId);
            }
#endif /* (__MMI_UNIFIED_COMPOSER__) || (__MMI_MMS_STANDALONE_COMPOSER__)*/

#ifdef __MMI_SMS_COMPOSER__
		
	    mmi_id smsComposerCui = 0;
	    VcuiSmsComposerEntryStruct *entryData;
	    VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
	    vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );

	    if (id == TOOLBAR_ID_USE)
        {
            entryData.operation = VCUI_SMS_COMPOSER_OPERATION_NEW;

        }
        else if (id == TOOLBAR_ID_EDIT)
        {
        	VFX_OBJ_ASSERT_VALID(this);
            entryData.msg_id = m_templateId;
            entryData.operation = VCUI_SMS_COMPOSER_OPERATION_EDIT;             
        }
		
		// set text
		entryData->text_buffer = (VfxChar*)m_template->getContent();
		entryData->text_num = mmi_ucs2strlen((CHAR*)m_template->getContent());

	    smsComposerCui = vcui_sms_composer_create(getApp()->getGroupId());
	    if(smsComposerCui !=  GRP_ID_INVALID)
	    {
	        vcui_sms_composer_set_entry_data(smsComposerCui, entryData);        
	        vfxSetCuiCallerScr(smsComposerCui, getMainScr());
	        vcui_sms_composer_run(smsComposerCui);
	    }
	    VFX_FREE_MEM(entryData);
#endif /* __MMI_SMS_COMPOSER__ */
    }
}

mmi_ret VappTextTemplateViewerPage::onCuiProc(mmi_event_struct * evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
        {
            cui_msgcomposer_evt_struct *ucEvt = (cui_msgcomposer_evt_struct *)evt;
            /* just close it */
            vcui_unifiedcomposer_close(ucEvt->sender_id);
            break;
        }
    }

    return MMI_RET_OK;
}

void VappTextTemplateViewerPage::onPreDeleteTemplate(VfxObject *sender, VfxId id)
{
    VFX_UNUSED(sender);

    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_deleteConfirmed = VFX_TRUE;
    }
}

void VappTextTemplateViewerPage::onDeleteTemplate(VfxBasePopup *popup, VfxBasePopupStateEnum state)
{
    //VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONCONFIRMPOPUPSTATECHANGED, state, m_deleteConfirmed);

    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        if (m_deleteConfirmed)
        {
            srv_sms_template_delete(m_templateId);

            m_deleteConfirmed = VFX_FALSE;
        }
    }
}

void VappTextTemplateViewerPage::onDelTemplate(VfxObject *sender, VfxU16 templateId, VfxU16 listIndex)
{
    if (m_templateId == templateId)
    {
        VFX_OBJ_ASSERT_VALID(this);
        VappTextTemplateViewerPage *self = this;
        VfxId pageId = getMainScr()->getPageId(self);
        getMainScr()->closePage(pageId);
    }
}

void VappTextTemplateViewerPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

#if 0 // for iterator view
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // end if 0, for iterator view

#endif //__SRV_SMS_TEMPLATE__

