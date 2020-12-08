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
 *  vapp_phb_mycard.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "vapp_phb_gprot.h"

#ifdef __MMI_PHB_MYCARD__
#include "mmi_rp_vapp_contact_def.h"

#include "vapp_phb_mycard.h"
#include "vapp_phb_info.h"
#include "vapp_phb_app.h"

#ifdef __MMI_OPP_SUPPORT__
#include "vapp_bt_send_gprot.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif


#ifdef __MMI_EMAIL__
#include "EmailAppGprot.h"
#endif

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappPhbMycardScr
 *****************************************************************************/
void VappPhbMycardScr::on1stReady()
{
    VfxMainScr::on1stReady();

    // register event handler
    ContactTask *task = GET_CONTACT_TASK();
    task->m_signalTask.connect(this, &VappPhbMycardScr::onContactUpdated);

    // vcard object
    VFX_OBJ_CREATE_EX(m_contact, Contact, this, (VAPP_CONTACT_TYPE_MYCARD));

    VappContactName& name = m_contact->getName();

    // add mycard
    if (name.getString().isEmpty() && m_contact->getNumberCount() == 0 && m_contact->getEmailCount() == 0)
    {
        VappPhbMycardEditorPage *page;
        VFX_OBJ_CREATE_EX(page, VappPhbMycardEditorPage, this, (NULL));
        pushPage(VFX_ID_NULL, page);

        page->m_signalSaved.connect(this, &VappPhbMycardScr::onSavedDone);
    }
    // mycard profile
    else
    {
        VappPhbMycardProfilePage *page;
        VFX_OBJ_CREATE_EX(page, VappPhbMycardProfilePage, this, (NULL));
        pushPage(VFX_ID_NULL, page);
    }
}


void VappPhbMycardScr::onContactUpdated(ContactTask* task, mmi_event_struct* evt)
{
    // dispatch the event to sub pages
    processProc(evt);
}


void VappPhbMycardScr::onSavedDone()
{
    VappPhbMycardProfilePage *page;
    VFX_OBJ_CREATE_EX(page, VappPhbMycardProfilePage, this, (NULL));

    pushPage(VFX_ID_NULL, page);

    setAutoClose(VFX_TRUE);
}


/***************************************************************************** 
 * Class VappPhbMycardEditorPage
 *****************************************************************************/
VappPhbMycardEditorPage::VappPhbMycardEditorPage(Contact *contact):
    m_form(NULL),
    m_contact(contact),
    m_field(NULL),
    m_numCount(0),
    m_emailCount(0),
    m_activeEditor(NULL)
{
}


void VappPhbMycardEditorPage::onInit()
{
    VfxPage::onInit();

    // create contact
    VFX_OBJ_CREATE_EX(m_contact, Contact, this, (VAPP_CONTACT_TYPE_MYCARD));

    // create title bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(VAPP_PHB_STR_MYCARD)); 
    setTopBar(titleBar);

    // create tool bar
    VcpToolBar* toolbar; 
    VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
    toolbar->addItem(PB_CONTACT_EDITOR_CMD_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolbar->addItem(PB_CONTACT_EDITOR_CMD_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    setBottomBar(toolbar);

    // create form
    createForm();

    // connect signal
    toolbar->m_signalButtonTap.connect(this, &VappPhbMycardEditorPage::onToolBarClick);
}


#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
mmi_ret VappPhbMycardEditorPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_FIELD_TYPE_CHNAGED_IND:
        {
            srv_phb_field_type_changed_ind_struct *args = (srv_phb_field_type_changed_ind_struct*) evt;
            if (args->is_delete && args->result)
            {
                if (args->field_type == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
                {
                    VfxU32 count = m_contact->getNumberCount();
                    for (VfxU32 i = 0; i < count && i < m_contact->getNumberMaxCount(); i++)
                    {
                        VappContactNumber& num = m_contact->getNumber(i);
                        if (num.getSubType() == args->field_sub_type)
                        {
                            num.setSubType(MMI_PHB_NUM_TYPE_MOBILE);
                            num.setLabel(VFX_WSTR_RES(VAPP_PHB_STR_MOBILE));
                        }
                    }

                    VappContactFieldItem item = m_field->getItemByItemType(PB_CONTACT_ITEM_NUMBER_NEW);
                    VfxU32 itemId = item.m_itemId;

                    for (VfxU32 i = 0; i < count; i++)
                    {
                        item = m_field->getPrevItem(itemId);
                        itemId = item.m_itemId;

                        if (item.m_fieldType == args->field_sub_type)
                        {
                            VcpFormItemRemovableTextEntry *numItem = (VcpFormItemRemovableTextEntry*) item.m_obj;
                            numItem->getLeftButton()->setText(VFX_WSTR_RES(VAPP_PHB_STR_MOBILE));

                            VappContactFieldItem& tempItem = m_field->getItem(itemId);
                            tempItem.m_fieldType = MMI_PHB_NUM_TYPE_MOBILE;
                        }
                    }
                }
                else if (args->field_type == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
                {
                    VfxU32 count = m_contact->getEmailCount();
                    for (VfxU32 i = 0; i < count && i < m_contact->getEmailMaxCount(); i++)
                    {
                        VappContactEmail& email = m_contact->getEmail(i);
                        if (email.getSubType() == args->field_sub_type)
                        {
                            email.setSubType(MMI_PHB_EMAIL_TYPE_OFFICE);
                            email.setLabel(VFX_WSTR_RES(VAPP_PHB_STR_WORK));
                        }
                    }

                    VappContactFieldItem item = m_field->getItemByItemType(PB_CONTACT_ITEM_EMAIL_NEW);
                    VfxU32 itemId = item.m_itemId;

                    for (VfxU32 i = 0; i < count; i++)
                    {
                        item = m_field->getPrevItem(itemId);
                        itemId = item.m_itemId;

                        if (item.m_fieldType == args->field_sub_type)
                        {
                            VcpFormItemRemovableTextEntry *numItem = (VcpFormItemRemovableTextEntry*) item.m_obj;
                            numItem->getLeftButton()->setText(VFX_WSTR_RES(VAPP_PHB_STR_WORK));

                            VappContactFieldItem& tempItem = m_field->getItem(itemId);
                            tempItem.m_fieldType = MMI_PHB_EMAIL_TYPE_OFFICE;
                        }
                    }
                }
            }
            break;
        }
    }

    return VfxPage::onProc(evt);
}
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */


void VappPhbMycardEditorPage::createForm()
{
    // create form
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // create item field vector
    VFX_OBJ_CREATE(m_field, VappPhbFieldItem, m_form);

    createName();

    createNumber();

    createEmail();
}


void VappPhbMycardEditorPage::createName()
{
    VappContactName& name = m_contact->getName();

    // first name
    VcpFormItemTextInput *text;
    VFX_OBJ_CREATE(text, VcpFormItemTextInput, m_form);

    VappContactFieldItem item;
    item.m_itemId = m_field->getNewItemId();
    m_field->setItem(item);

    text->setLabelPosition(VCPFORM_TOP_LEFT);
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    text->setLabelText(VFX_WSTR_RES(VAPP_PHB_STR_FIRST_NAME));
#else
    text->setLabelText(VFX_WSTR_RES(VAPP_PHB_STR_NAME));
#endif /*__MMI_PHB_LAST_NAME_FIELD__*/
    VcpTextEditor *editor;
    editor = text->getTextBox();
    editor->setText(name.getGivenBuf(), MMI_PHB_NAME_FIELD_LENGTH, VFX_TRUE);
    editor->setIME(IMM_INPUT_TYPE_SENTENCE, IME_DISABLE_NEW_LINE_SYMBOL);
    editor->m_signalActivated.connect(this, &VappPhbMycardEditorPage::onEditorActived);

    m_form->addItem(text, item.m_itemId);

    // last name
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    VFX_OBJ_CREATE(text, VcpFormItemTextInput, m_form);

    item.m_itemId = m_field->getNewItemId();
    m_field->setItem(item);

    text->setLabelPosition(VCPFORM_TOP_LEFT);
    text->setLabelText(VFX_WSTR_RES(VAPP_PHB_STR_LAST_NAME));

    editor = text->getTextBox();
    editor->setText(name.getFamilyBuf(), MMI_PHB_NAME_FIELD_LENGTH, VFX_TRUE);
    editor->setIME(IMM_INPUT_TYPE_SENTENCE, IME_DISABLE_NEW_LINE_SYMBOL);
    editor->m_signalActivated.connect(this, &VappPhbMycardEditorPage::onEditorActived);

    m_form->addItem(text, item.m_itemId);
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */
}


void VappPhbMycardEditorPage::createNumber()
{
    // create number caption
    m_form->addCaption(VFX_WSTR_RES(VAPP_PHB_STR_NUMBER));

    // create exist number
    VfxU32 numCount = m_contact->getNumberCount();
    for (VfxU32 i = 0; i < numCount; i++)
    {
        // get number instance
        VappContactNumber& number = m_contact->getNumber(i);

        VcpFormItemRemovableTextEntry *addNum = NULL;
        VFX_OBJ_CREATE(addNum, VcpFormItemRemovableTextEntry, m_form);

        VappContactFieldItem item;
        item.m_itemId = m_field->getNewItemId();
        item.m_itemType = PB_CONTACT_ITEM_NUMBER;
        item.m_fieldId = i;
        item.m_fieldType = number.getSubType();
        item.m_obj = addNum;
        m_field->setItem(item);

        addNum->setMode(VFX_FALSE);
        addNum->getLeftButton()->setText(number.getLabel());
        addNum->getLeftButton()->setId(item.m_itemId);

        VcpTextEditor *editor;
        editor = addNum->getTextBox();
        editor->setIME(IMM_INPUT_TYPE_PHONE_NUMBER, IME_PLUS_CHAR_HANDLING);
        editor->setText(number.getBuf(), MMI_PHB_NUMBER_LENGTH, VFX_TRUE);
        editor->m_signalActivated.connect(this, &VappPhbMycardEditorPage::onEditorActived);

        addNum->getLeftButton()->m_signalClicked.connect(this, &VappPhbMycardEditorPage::onItemLabelClick);
        addNum->m_signalAddRemoveClick.connect(this, &VappPhbMycardEditorPage::onNumberClick);
        m_form->addItem(addNum, item.m_itemId);

        // number count
        m_numCount++;
    }

    // create new number
    createNewNumber();
}


void VappPhbMycardEditorPage::createNewNumber()
{
    // create new number item
    VappContactFieldItem item;
    item.m_itemId = m_field->getNewItemId();
    item.m_itemType = PB_CONTACT_ITEM_NUMBER_NEW;

    VcpFormItemRemovableTextEntry *addNum;
    VFX_OBJ_CREATE(addNum, VcpFormItemRemovableTextEntry, m_form);
    addNum->setMode(VFX_TRUE);
    addNum->getLeftButton()->setText(VFX_WSTR_RES(VAPP_PHB_STR_MOBILE));
    addNum->m_signalAddRemoveClick.connect(this, &VappPhbMycardEditorPage::onNumberClick);
    m_form->addItem(addNum, item.m_itemId);

    item.m_obj = addNum;
    m_field->setItem(item);

    if (m_contact->getNumberCount() == m_contact->getNumberMaxCount())
    {
        addNum->setIsHidden(VFX_TRUE);
    }
}


void VappPhbMycardEditorPage::createEmail()
{
    // create E-email caption
    m_form->addCaption(VFX_WSTR_RES(VAPP_PHB_STR_EMAIL));

    // create exist email item
    VfxU32 emailCount = m_contact->getEmailCount();
    for (VfxU32 i = 0; i < emailCount; i++)
    {
        // get email instance
        VappContactEmail& email = m_contact->getEmail(i);

        VcpFormItemRemovableTextEntry *addEmail = NULL;
        VFX_OBJ_CREATE(addEmail, VcpFormItemRemovableTextEntry, m_form);

        VappContactFieldItem item;
        item.m_itemId = m_field->getNewItemId();
        item.m_itemType = PB_CONTACT_ITEM_EMAIL;
        item.m_fieldId = i;
        item.m_fieldType = email.getSubType();
        item.m_obj = addEmail;
        m_field->setItem(item);

        addEmail->getLeftButton()->setText(email.getLabel());
        addEmail->getLeftButton()->setId(item.m_itemId);
        addEmail->setMode(VFX_FALSE);

        VcpTextEditor *editor;
        editor = addEmail->getTextBox();
        editor->setIME(IMM_INPUT_TYPE_EMAIL, IME_DISABLE_NEW_LINE_SYMBOL);
        editor->setText(email.getBuf(), MMI_PHB_EMAIL_LENGTH, VFX_TRUE);
        editor->m_signalActivated.connect(this, &VappPhbMycardEditorPage::onEditorActived);

        addEmail->getLeftButton()->m_signalClicked.connect(this, &VappPhbMycardEditorPage::onItemLabelClick);
        addEmail->m_signalAddRemoveClick.connect(this, &VappPhbMycardEditorPage::onEmailClick);
        m_form->addItem(addEmail, item.m_itemId);

        // email count
        m_emailCount++;
    }

    // create new email
    createNewEmail();
}


void VappPhbMycardEditorPage::createNewEmail()
{
    // create new number item
    VappContactFieldItem item;
    item.m_itemId = m_field->getNewItemId();
    item.m_itemType = PB_CONTACT_ITEM_EMAIL_NEW;

    VcpFormItemRemovableTextEntry *addEmail;
    VFX_OBJ_CREATE(addEmail, VcpFormItemRemovableTextEntry, m_form);

    addEmail->setMode(VFX_TRUE);
    addEmail->getLeftButton()->setText(VFX_WSTR_RES(VAPP_PHB_STR_WORK));
    addEmail->m_signalAddRemoveClick.connect(this, &VappPhbMycardEditorPage::onEmailClick);
    m_form->addItem(addEmail, item.m_itemId);

    item.m_obj = addEmail;
    m_field->setItem(item);

    if (m_contact->getEmailCount() == m_contact->getEmailMaxCount())
    {
        addEmail->setIsHidden(VFX_TRUE);
    }
}


void VappPhbMycardEditorPage::onItemLabelSelected(VfxU32 type, VfxWString label, VfxU32 userData)
{
    VappContactFieldItem& item = m_field->getItem(userData);
    item.m_fieldType = type;

    // update label
    VcpFormItemRemovableTextEntry *obj = (VcpFormItemRemovableTextEntry*) item.m_obj;
    obj->getLeftButton()->setText(label);

    // update contact obj
    if (item.m_itemType == PB_CONTACT_ITEM_NUMBER)
    {
        m_contact->getNumber(item.m_fieldId).setSubType(type);
        m_contact->getNumber(item.m_fieldId).setLabel(label);
    }
    else
    {
        m_contact->getEmail(item.m_fieldId).setSubType(type);
        m_contact->getEmail(item.m_fieldId).setLabel(label);
    }
}


void VappPhbMycardEditorPage::onItemLabelClick(VfxObject* obj, VfxId id)
{
    // pre handler
    onEditorPreActive();

    VappContactFieldItem item = m_field->getItem(id);
    mmi_phb_contact_field_id_enum field;
    if (item.m_itemType == PB_CONTACT_ITEM_NUMBER)
    {
        field = MMI_PHB_CONTACT_FIELD_ID_NUMBER;
    }
    else
    {
        field = MMI_PHB_CONTACT_FIELD_ID_EMAIL;
    }

    VappPhbTypeSelectorPage *page;
    VFX_OBJ_CREATE_EX(
        page, 
        VappPhbTypeSelectorPage,
        getMainScr(),
        (item.m_fieldType, field, m_contact->getStorage(), id));

    page->m_typeSelected.connect(this, &VappPhbMycardEditorPage::onItemLabelSelected);

    getMainScr()->pushPageHandler(VFX_ID_NULL, page);
}


void VappPhbMycardEditorPage::onNumberClick(VcpFormItemRemovableTextEntry* obj, VfxId id, VfxBool addRemove)
{
    // pre handler
    onEditorPreActive();

    // add new number
    if (addRemove)
    {
        if (m_numCount < m_contact->getNumberMaxCount())
        {
            VappContactNumber tempNumber(
                            VFX_WSTR_EMPTY,
                            VFX_WSTR_RES(VAPP_PHB_STR_MOBILE),
                            MMI_PHB_CONTACT_FIELD_NUMBER,
                            MMI_PHB_NUM_TYPE_MOBILE,
                            MMI_PHB_SUB_ID_NEW,
                            VFX_FALSE);

            m_contact->setNumber(tempNumber, m_numCount);
            VappContactNumber& number = m_contact->getNumber(m_numCount);

            VcpFormItemRemovableTextEntry *addNum = NULL;
            VFX_OBJ_CREATE(addNum, VcpFormItemRemovableTextEntry, m_form);

            VappContactFieldItem item;
            item.m_itemId = m_field->getNewItemId();
            item.m_itemType = PB_CONTACT_ITEM_NUMBER;
            item.m_fieldId = m_numCount;
            item.m_fieldType = number.getSubType();
            item.m_obj = addNum;

            VappContactFieldItem tempItem = m_field->getItemByItemType(PB_CONTACT_ITEM_NUMBER_NEW);
            m_field->insertItem(item, tempItem.m_itemId);

            addNum->setMode(VFX_FALSE);
            addNum->getLeftButton()->setText(number.getLabel());
            addNum->getLeftButton()->setId(item.m_itemId);

            VcpTextEditor *editor;
            editor = addNum->getTextBox();
            editor->setIME(IMM_INPUT_TYPE_PHONE_NUMBER, IME_PLUS_CHAR_HANDLING);
            editor->setText(number.getBuf(), MMI_PHB_NUMBER_LENGTH, VFX_TRUE);
            editor->m_signalActivated.connect(this, &VappPhbMycardEditorPage::onEditorActived);

            addNum->getLeftButton()->m_signalClicked.connect(this, &VappPhbMycardEditorPage::onItemLabelClick);
            addNum->m_signalAddRemoveClick.connect(this, &VappPhbMycardEditorPage::onNumberClick);
            m_form->insertItem(addNum, id, item.m_itemId);

            m_numCount++;

            if (m_numCount == m_contact->getNumberMaxCount())
            {
                VcpFormItemRemovableTextEntry *newItem = (VcpFormItemRemovableTextEntry*) m_field->getObj(PB_CONTACT_ITEM_NUMBER_NEW);
                newItem->setIsHidden(VFX_TRUE);
            }
        }
        // should remove add number item
    }
    // remove exist number
    else
    {
        VappContactFieldItem item = m_field->getItem(id);
        m_contact->removeNumber(item.m_fieldId);

        VfxU32 itemId = item.m_itemId;
        while (1)
        {
            VappContactFieldItem &tempItem = m_field->getNextItem(itemId);
            if (tempItem.m_itemType == PB_CONTACT_ITEM_NUMBER_NEW)
            {
                break;
            }
            else
            {
                itemId = tempItem.m_itemId;
                tempItem.m_fieldId--;
            }
        }

        m_form->removeItem(id);
        m_field->removeItem(id);

        m_numCount--;

        VcpFormItemRemovableTextEntry *newItem = (VcpFormItemRemovableTextEntry*) m_field->getObj(PB_CONTACT_ITEM_NUMBER_NEW);
        newItem->setIsHidden(VFX_FALSE);
    }
}


void VappPhbMycardEditorPage::onEmailClick(VcpFormItemRemovableTextEntry* obj, VfxId id, VfxBool addRemove)
{
    // pre handler
    onEditorPreActive();

    // add new number
    if (addRemove)
    {
        if (m_emailCount < m_contact->getEmailMaxCount())
        {
            VappContactEmail tempEmail(
                            VFX_WSTR_EMPTY,
                            VFX_WSTR_RES(VAPP_PHB_STR_WORK),
                            MMI_PHB_CONTACT_FIELD_EMAIL,
                            MMI_PHB_EMAIL_TYPE_OFFICE,
                            MMI_PHB_SUB_ID_NEW,
                            VFX_FALSE);

            m_contact->setEmail(tempEmail, m_emailCount);
            VappContactEmail& email = m_contact->getEmail(m_emailCount);

            VcpFormItemRemovableTextEntry *addEmail = NULL;
            VFX_OBJ_CREATE(addEmail, VcpFormItemRemovableTextEntry, m_form);

            VappContactFieldItem item;
            item.m_itemId = m_field->getNewItemId();
            item.m_itemType = PB_CONTACT_ITEM_EMAIL;
            item.m_fieldId = m_emailCount;
            item.m_fieldType = email.getSubType();
            item.m_obj = addEmail;

            VappContactFieldItem tempItem = m_field->getItemByItemType(PB_CONTACT_ITEM_EMAIL_NEW);
            m_field->insertItem(item, tempItem.m_itemId);

            addEmail->getLeftButton()->setText(email.getLabel());
            addEmail->getLeftButton()->setId(item.m_itemId);
            addEmail->setMode(VFX_FALSE);

            VcpTextEditor *editor;
            editor = addEmail->getTextBox();
            editor->setIME(IMM_INPUT_TYPE_EMAIL, IME_DISABLE_NEW_LINE_SYMBOL);
            editor->setText(email.getBuf(), MMI_PHB_EMAIL_LENGTH, VFX_TRUE);
            editor->m_signalActivated.connect(this, &VappPhbMycardEditorPage::onEditorActived);

            addEmail->getLeftButton()->m_signalClicked.connect(this, &VappPhbMycardEditorPage::onItemLabelClick);
            addEmail->m_signalAddRemoveClick.connect(this, &VappPhbMycardEditorPage::onEmailClick);
            m_form->insertItem(addEmail, id, item.m_itemId);

            m_emailCount++;

            if (m_emailCount == m_contact->getEmailMaxCount())
            {
                VcpFormItemRemovableTextEntry *newItem = (VcpFormItemRemovableTextEntry*) m_field->getObj(PB_CONTACT_ITEM_EMAIL_NEW);
                newItem->setIsHidden(VFX_TRUE);
            }
        }
        // should remove add number item
    }
    // remove exist number
    else
    {
        VappContactFieldItem item = m_field->getItem(id);
        m_contact->removeEmail(item.m_fieldId);

        VfxU32 itemId = item.m_itemId;
        while (1)
        {
            VappContactFieldItem &tempItem = m_field->getNextItem(itemId);
            if (tempItem.m_itemType == PB_CONTACT_ITEM_EMAIL_NEW)
            {
                break;
            }
            else
            {
                itemId = tempItem.m_itemId;
                tempItem.m_fieldId--;
            }
        }

        m_form->removeItem(id);
        m_field->removeItem(id);

        m_emailCount--;

        VcpFormItemRemovableTextEntry *newItem = (VcpFormItemRemovableTextEntry*) m_field->getObj(PB_CONTACT_ITEM_EMAIL_NEW);
        newItem->setIsHidden(VFX_FALSE);
    }
}


void VappPhbMycardEditorPage::onEditorActived(VcpTextEditor *editor, VfxBool isActived)
{
    if (isActived)
    {
        m_activeEditor = editor;
    }
}


void VappPhbMycardEditorPage::onEditorPreActive()
{
    if (m_activeEditor)
    {
        m_activeEditor->deactivate();
        m_activeEditor = NULL;
    }
}


void VappPhbMycardEditorPage::save()
{
    // check empty name, number, email
    if (m_contact->getName().isEmpty())
    {
        VfxBool isEmptyContact = VFX_TRUE;

        // check number
        VfxU32 count = m_contact->getNumberCount();
        for (VfxU32 i = 0; i < count && i < m_contact->getNumberMaxCount(); i++)
        {
            VappContactNumber& num = m_contact->getNumber(i);
            if (!num.isEmpty())
            {
                isEmptyContact = VFX_FALSE;
                break;
            }
        }

        // check email
        if (isEmptyContact)
        {
            count = m_contact->getEmailCount();
            for (VfxU32 i = 0; i < count && i < m_contact->getEmailMaxCount(); i++)
            {
                VappContactEmail& email = m_contact->getEmail(i);
                if (!email.isEmpty())
                {
                    isEmptyContact = VFX_FALSE;
                    break;
                }
            }
        }

        // popup error
        if (isEmptyContact)
        {
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, VFX_WSTR_RES(STR_ID_VAPP_PHB_NAME_WARNING));
            return;
        }
    }

    // check data valid
    VfxBool valid = VFX_TRUE;
    VfxId id = 0;
    for (VfxU32 i = 0; i < m_field->getItemCount(); i++)
    {
        VappContactFieldItem item = m_field->getItemByIndex(i);
        switch (item.m_itemType)
        {
            case PB_CONTACT_ITEM_NUMBER:
            {
                if (m_contact->getNumberMaxCount() == 1)
                {
                    VcpFormItemTextInput *text = (VcpFormItemTextInput*)item.m_obj;
                    if (!checkValidNumber(text->getTextBox()->getText(), m_contact->getStorage()))
                    {
                        if (valid)
                        {
                            id = item.m_itemId;
                            valid = VFX_FALSE;
                        }
                        text->setWarningText(VFX_WSTR_RES(STR_GLOBAL_INVALID_NUMBER));
                    }
                    else
                    {
                        text->setWarningText(VFX_WSTR_EMPTY);
                    }
                }
                else
                {
                    VcpFormItemRemovableTextEntry *text = (VcpFormItemRemovableTextEntry*) item.m_obj;
                    if (!checkValidNumber(text->getTextBox()->getText(), m_contact->getStorage()))
                    {
                        if (valid)
                        {
                            id = item.m_itemId;
                            valid = VFX_FALSE;
                        }
                        text->setWarningText(VFX_WSTR_RES(STR_GLOBAL_INVALID_NUMBER));
                    }
                    else
                    {
                        text->setWarningText(VFX_WSTR_EMPTY);
                    }
                }
                break;
            }
            case PB_CONTACT_ITEM_EMAIL:
            {
                VcpFormItemRemovableTextEntry *text = (VcpFormItemRemovableTextEntry*) item.m_obj;
                VfxWChar *value = text->getTextBox()->getText();
                if (mmi_wcslen(value) > 0 && !applib_is_valid_email_address_unicode(value))
                {
                    if (valid)
                    {
                        id = item.m_itemId;
                        valid = VFX_FALSE;
                    }
                    text->setWarningText(VFX_WSTR_RES(STR_GLOBAL_INVALID_EMAIL_ADDRESS));
                }
                else
                {
                    text->setWarningText(VFX_WSTR_EMPTY);
                }
                break;
            }
        }
    }

    if (!valid)
    {
        m_form->scrollItemToView(id, VCPFORM_SCROLL_TOP, VFX_TRUE);
        return;
    }

    mmi_phb_my_number_struct *mycard =
        (mmi_phb_my_number_struct*) mmi_frm_temp_alloc(sizeof(mmi_phb_my_number_struct));

    m_contact->buildMycard(mycard);

    srv_phb_write_my_number(mycard);

    mmi_frm_temp_free(mycard);

    getMainScr()->setAutoClose(VFX_FALSE);
    getMainScr()->popPage();

    m_signalSaved.postEmit();
}


void VappPhbMycardEditorPage::onToolBarClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case PB_CONTACT_EDITOR_CMD_SAVE:
        {
            save();
            break;
        }
        case PB_CONTACT_EDITOR_CMD_CANCEL:
        {
            getMainScr()->popPage();
            break;
        }
    }
}


/***************************************************************************** 
 * Class VappPhbMycardProfilePage
 *****************************************************************************/
VappPhbMycardProfilePage::VappPhbMycardProfilePage(Contact *contact):
    m_contact(contact),
    m_form(NULL),
#ifdef __MMI_VCARD__
    m_vcard(NULL),
#endif
    m_path(NULL)
{
}


#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
mmi_ret VappPhbMycardProfilePage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_FIELD_TYPE_CHNAGED_IND:
        {
            VFX_OBJ_CLOSE(m_contact);
            // create contact
            VFX_OBJ_CREATE_EX(m_contact, Contact, this, (VAPP_CONTACT_TYPE_MYCARD));
            // refresh form
            VFX_OBJ_CLOSE(m_form);
            createForm();
            break;
        }
    }

    return VfxPage::onProc(evt);
}
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */


void VappPhbMycardProfilePage::onInit()
{
    VfxPage::onInit();

    // create contact
    VFX_OBJ_CREATE_EX(m_contact, Contact, this, (VAPP_CONTACT_TYPE_MYCARD));

    // create title bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(VAPP_PHB_STR_MYCARD));
    setTopBar(titleBar);

    // create tool bar
    VcpToolBar* toolbar; 
    VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
#ifdef __MMI_VCARD__
    toolbar->addItem(VAPP_PHB_MYCARD_PROFILE_SHARE, VFX_WSTR_RES(STR_GLOBAL_SHARE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SHARE);
#endif
    toolbar->addItem(VAPP_PHB_MYCARD_PROFILE_EDIT, VFX_WSTR_RES(STR_GLOBAL_EDIT), VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
    setBottomBar(toolbar);

    // create form
    createForm();

    // connect signal    
    toolbar->m_signalButtonTap.connect(this, &VappPhbMycardProfilePage::onToolBarClick);
}


void VappPhbMycardProfilePage::createForm()
{
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // name
    VappPhbViewerNameFormItem *item;
    VFX_OBJ_CREATE(item, VappPhbViewerNameFormItem, m_form);

    VappContactName& name = m_contact->getName();
    if (name.getString().isEmpty())
    {
        item->setName(VFX_WSTR_RES(VAPP_PHB_STR_UNNAMED));
    }
    else
    {
        item->setName(name.getString());
    }
    item->setImage(VfxImageSrc());
    m_form->addItem(item);

    // number
    if (m_contact->getNumberCount())
    {
        m_form->addCaption(VFX_WSTR_RES(VAPP_PHB_STR_NUMBER));

        for (VfxU32 i = 0; i < m_contact->getNumberCount(); i++)
        {
            VappPhbViewerLabelTextFormItem *item;
            VFX_OBJ_CREATE(item, VappPhbViewerLabelTextFormItem, m_form);

            VappContactNumber& number = m_contact->getNumber(i);
            item->setItemContent(number.getLabel(), number.getString());
            m_form->addItem(item);
        }
    }

    // email
    if (m_contact->getEmailCount())
    {
        m_form->addCaption(VFX_WSTR_RES(VAPP_PHB_STR_EMAIL));

        for (VfxU32 i = 0; i < m_contact->getEmailCount(); i++)
        {
            VappPhbViewerLabelTextFormItem *item;
            VFX_OBJ_CREATE(item, VappPhbViewerLabelTextFormItem, m_form);

            VappContactEmail& email = m_contact->getEmail(i);
            item->setItemContent(email.getLabel(), email.getString());
            m_form->addItem(item);
        }
    }
}

#ifdef __MMI_VCARD__

void VappPhbMycardProfilePage::shareContact()
{
    // check usb mass storage
    if (!vapp_phb_usb_app_is_available())
    {
        return;
    }

    VcpCommandPopup *option;
    VFX_OBJ_CREATE(option, VcpCommandPopup, this);

    option->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_SHARE_MY_CARD));

    option->addItem(VAPP_CONTACT_SHARE_BY_SMS, VFX_WSTR_RES(STR_ID_VAPP_PHB_SHARE_WITH_SMS), VCP_POPUP_BUTTON_TYPE_NORMAL);
    option->addItem(VAPP_CONTACT_SHARE_BY_MMS, VFX_WSTR_RES(STR_ID_VAPP_PHB_SHARE_WITH_MMS), VCP_POPUP_BUTTON_TYPE_NORMAL);
#ifdef __MMI_EMAIL__
    option->addItem(VAPP_CONTACT_SHARE_BY_EMAIL, VFX_WSTR_RES(STR_ID_VAPP_PHB_SHARE_WITH_EMAIL), VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
    option->addItem(VAPP_CONTACT_SHARE_BY_BT, VFX_WSTR_RES(STR_ID_VAPP_PHB_SHARE_WITH_BLUETOOTH), VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
    option->addItem(VAPP_CONTACT_SHARE_TOTAL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

    option->m_signalButtonClicked.connect(this, &VappPhbMycardProfilePage::onShareSelected);

    option->show(VFX_TRUE);
}
#endif

#ifdef __MMI_VCARD__
void VappPhbMycardProfilePage::onShareSelected(VfxObject *obj, VfxId id)
{
    if (!vapp_phb_usb_app_is_available())
    {
        return;
    }

    VFX_OBJ_CREATE_EX(m_vcard, VappContactvCard, this, (m_contact));

    VfxS32 result;
    m_path = m_vcard->getFile(&result);

    if (m_path == NULL)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(STR_GLOBAL_NOT_ENOUGH_MEMORY).getBuf());
        return;
    }

    switch (id)
    {
    case VAPP_CONTACT_SHARE_BY_SMS:
    case VAPP_CONTACT_SHARE_BY_MMS:
    {
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
        VappUcEntryStruct *ucEntry;
        ucEntry = (VappUcEntryStruct*) mmi_frm_temp_alloc(sizeof(VappUcEntryStruct));

        memset(ucEntry, 0, sizeof(VappUcEntryStruct));
        ucEntry->info_type = SRV_UC_INFO_TYPE_VCARD;
        ucEntry->operation = (id == VAPP_CONTACT_SHARE_BY_SMS) ? UC_OPERATION_SEND_VCARD_AS_SMS : UC_OPERATION_SEND_VCARD_AS_MMS;
        ucEntry->msg_type = (id == VAPP_CONTACT_SHARE_BY_SMS) ? SRV_UC_MSG_TYPE_SMS_ONLY : SRV_UC_MSG_TYPE_MMS_ONLY;
        ucEntry->type = SRV_UC_STATE_WRITE_NEW_MSG;
        ucEntry->auto_delete_file = TRUE;
        ucEntry->callback_para = this;
        ucEntry->media_num = 1;
        ucEntry->file_path = (U8*) m_path;

        vappUcAppLauncher(ucEntry);

        mmi_frm_temp_free(ucEntry);
        break;
#endif
    }

#ifdef __MMI_EMAIL__
    case VAPP_CONTACT_SHARE_BY_EMAIL:
    {
        mmi_email_app_send_attch_ext((CHAR*) m_path, MMI_TRUE);
        break;
    }
#endif /* __MMI_EMAIL__ */

#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
    case VAPP_CONTACT_SHARE_BY_BT:
    {
        vapp_bt_send_app_info info;
        info.group_id = getApp()->getGroupId();
        info.callback = NULL;
        info.user_data = NULL;

        VfxWChar* pathArray[1];
        pathArray[0] = m_path;
        vapp_bt_send_obj(&info, VAPP_BT_SEND_DELETE_FILE, 1, pathArray);
        break;
    }
#endif /* __MMI_OPP_SUPPORT__ */
    }
}
#endif

void VappPhbMycardProfilePage::onToolBarClick(VfxObject *obj, VfxId id)
{
    switch (id)
    {
    #ifdef __MMI_VCARD__
        case VAPP_PHB_MYCARD_PROFILE_SHARE:
        {
            shareContact();
            break;
        }
    #endif
        case VAPP_PHB_MYCARD_PROFILE_EDIT:
        {
            VappPhbMycardEditorPage *page;
            VFX_OBJ_CREATE_EX(page, VappPhbMycardEditorPage, this, (NULL));
            getMainScr()->pushPage(VFX_ID_NULL, page);

            page->m_signalSaved.connect(this, &VappPhbMycardProfilePage::onSavedDone);
            break;
        }
    }
}


void VappPhbMycardProfilePage::onSavedDone()
{
    VFX_OBJ_CLOSE(m_contact);
    VFX_OBJ_CREATE_EX(m_contact, Contact, this, (VAPP_CONTACT_TYPE_MYCARD));

    VFX_OBJ_CLOSE(m_form);

    createForm();

    getMainScr()->setAutoClose(VFX_TRUE);
}

#endif  /* __MMI_PHB_MYCARD__ */


