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
 *  Vapp_email_acct_wizard.cpp
 *
 * Project:
 * --------
 *  COSMOS Email Account Creation Wizard
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vapp_email_setting.h"
#include "vapp_email_acct_wizard.h"
#include "vapp_email_acct.h"
#include "vapp_dtcnt_gprot.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
extern "C"{
#include "cbm_api.h"
}

VfxBool VappEmailAcctWizardPop::onKeyInput(VfxKeyEvent & event)
{
    if (event.type != VFX_KEY_EVENT_TYPE_DOWN)
    {
        return VcpIndicatorPopup::onKeyInput(event);
    }

    switch (event.keyCode)
    {
        case VFX_KEY_CODE_BACK:
            if ((m_popupType ==
                    VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON) ||
                (m_popupType ==
                    VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON))
            {
                m_signalCanceled.emit(this, 0);
            }
            break;

        case VFX_KEY_CODE_HOME:
            m_signalCanceled.emit(this, 0);
            break;
    }

    return VcpIndicatorPopup::onKeyInput(event);
}

/****************** Account Create Wizard Main Screen ******************/
VappEmailAcctWizardScreen::VappEmailAcctWizardScreen():
    acctTemplate(NULL),
    acctTemplateIndex(0)
{
    memset(&currAcctInfo, 0, sizeof(srv_email_acct_info_struct));
}

VappEmailAcctWizardScreen::~VappEmailAcctWizardScreen()
{
    if (acctTemplate != NULL)
    {
        VFX_FREE_MEM(acctTemplate);
    }
}

void VappEmailAcctWizardScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    VappEmailAcctWizardTemplatePage *page;
    VFX_OBJ_CREATE(page, VappEmailAcctWizardTemplatePage, this);
    pushPage(0, page);
}

void VappEmailAcctWizardScreen::setAcctTemplateIndex(VfxU32 index)
{
    acctTemplateIndex = index;
}

VfxU32 VappEmailAcctWizardScreen::getAcctTemplateIndex() const
{
    return acctTemplateIndex;
}

/****************** Account Wizard Template List Page ******************/
VappEmailAcctWizardTemplatePage::VappEmailAcctWizardTemplatePage()
    :
    m_menu(NULL),
    selectedIndex(0),
    acctTemplateNum(0)
{
}

void VappEmailAcctWizardTemplatePage::onInit()
{
    VfxPage::onInit();

    vapp_email_set_titlebar(VFX_WSTR_RES(STR_GLOBAL_TEMPLATE), this);

    mmi_email_app_core_result_enum res;
    res = mmi_email_acct_temp_get_group_num((S32*)&acctTemplateNum);
    VEMAIL_TRC_ACCT_TEMPLATE_NUM(res);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    m_menu->setRect(0, 0, getSize().width, getSize().height);
    m_menu->m_signalItemTapped.connect(
        this, &VappEmailAcctWizardTemplatePage::onTapped);
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}

void VappEmailAcctWizardTemplatePage::onTapped(VcpListMenu *menu, VfxU32 index)
{
    VappEmailAcctWizardScreen *aws = (VappEmailAcctWizardScreen*)getMainScr();

    srv_email_acct_init_acct_info(&aws->currAcctInfo);

    VEMAIL_TRC_ACCT_TEMPLATE_NUM(acctTemplateNum);
    VEMAIL_TRC_ACCT_TEMPLATE_CHOOSE_IDEX(index);

    if (acctTemplateNum == index)
    {
        // the Last item "Others"
        VappEmailAcctWizardOthersBasicPage *tmplOthersPage;
        VFX_OBJ_CREATE(
            tmplOthersPage, VappEmailAcctWizardOthersBasicPage, this);
        getMainScr()->pushPage(0, tmplOthersPage);
    }
    else
    {
        aws->setAcctTemplateIndex(index);

        if (aws->acctTemplate == NULL)
        {
            VFX_ALLOC_MEM(
                aws->acctTemplate,
                sizeof(mmi_email_acct_temp_struct),
                getMainScr());
            memset(aws->acctTemplate, 0, sizeof(mmi_email_acct_temp_struct));
        }

        mmi_email_app_core_result_enum res;
        WCHAR tmplGrpName[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
        mmi_email_acct_temp_get_group_name(
            aws->getAcctTemplateIndex(),
            tmplGrpName,
            SRV_EMAIL_MAX_ACCT_NAME_LEN + 1);

        res = mmi_email_acct_temp_get_group_data_by_index(
                tmplGrpName, 0, aws->acctTemplate);
        if (res != MMI_EMAIL_SUCCESS)
        {
            vapp_email_alert_cfm(STR_GLOBAL_ERROR);
            return;
        }

        VappEmailAcctWizardFinishPage *finishPage;
        VFX_OBJ_CREATE_EX(
            finishPage, VappEmailAcctWizardFinishPage, this, (VFX_TRUE));
        getMainScr()->pushPage(0, finishPage);
    }
}

VfxBool VappEmailAcctWizardTemplatePage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    if ((VfxS32)index < acctTemplateNum)
    {
        WCHAR tmplGrpName[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];
        mmi_email_app_core_result_enum app_core_op_result;
        app_core_op_result = mmi_email_acct_temp_get_group_name(
            index, tmplGrpName, SRV_EMAIL_MAX_ACCT_NAME_LEN + 1);
        if (MMI_EMAIL_SUCCESS == app_core_op_result)
        {
            text.loadFromMem((const VfxWChar*)tmplGrpName);
        }
    }
    else if ((VfxS32)index == this->acctTemplateNum)
    {
        text = VFX_WSTR_RES(STR_EMAIL_FTO_OTHERS);
    }
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}

VfxBool VappEmailAcctWizardTemplatePage::getItemImage(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxImageSrc &image)
{
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        if (index < (VfxU32)acctTemplateNum)
        {
            image.setResId(IMG_EMAIL_FTO_LIST_ACCT_NORMAIL_DEFAULT);
        }
        else
        {
            image.setResId(IMG_EMAIL_FTO_LIST_ACCT_NORMAIL_OHTERS);
        }
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxU32 VappEmailAcctWizardTemplatePage::getCount() const
{
    return this->acctTemplateNum + 1;
}

VcpListMenuItemStateEnum VappEmailAcctWizardTemplatePage::getItemState(
    VfxU32 index) const
{
    if (selectedIndex == index)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

/****************** Account Wizard Address & Password Page ******************/
void VappEmailAcctWizardOthersBasicPage::onInit()
{
    VfxPage::onInit();

    vapp_email_set_titlebar(VFX_WSTR_RES(STR_EMAIL_FTO_BASIC_INFO_1_3), this);

    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappEmailAcctWizardOthersBasicPage::onToolBarClick);
    m_toolBar->addItem(
                'NEXT',
                VFX_WSTR_RES(STR_EMAIL_FTO_TOOLBAR_NEXT),
                IMG_EMAIL_FTO_TB_NEXT);
    m_toolBar->addItem(
                'CANC',
                VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                IMG_EMAIL_FTO_CANCEL);
    setBottomBar(m_toolBar);

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setPos(0, 0);
    form->setBounds(VfxRect(0, 0, getRect().size.width, getRect().size.height));
    form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(funcBar, VcpFunctionBar, this);
    funcBar->addItem(FUNCBAR_PREV, VFX_WSTR_RES(STR_EMAIL_FTO_PREV));
    funcBar->addItem(FUNCBAR_NEXT, VFX_WSTR_RES(STR_EMAIL_FTO_NEXT));
    funcBar->addItem(FUNCBAR_OK, VFX_WSTR_RES(STR_EMAIL_EMAIL_FUNCBAR_OK));
    funcBar->setItemSpecial(FUNCBAR_OK);
    funcBar->m_signalButtonTap.connect(this, &VappEmailAcctWizardOthersBasicPage::onFuncBarClick);

    srv_email_acct_info_struct *currAcct = &((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo;

    // Email Address
    addrTextInput = vapp_email_create_text_input_form_item(
                        VFX_WSTR_RES(STR_EMAIL_FTO_EMAIL_ADDR),
                        currAcct->email_addr.email_addr,
                        MMI_EMAIL_MAX_ADDR_LEN,
                        IMM_INPUT_TYPE_EMAIL, 
                        IME_SETTING_FLAG_NONE,
                        VFX_TRUE,
                        funcBar,
                        form);

    // User name
    userTextInput = vapp_email_create_text_input_form_item(
                        VFX_WSTR_RES(STR_GLOBAL_USERNAME),
                        (VfxWChar*)L"",
                        SRV_EMAIL_MAX_USERNAME_LEN,
                        IMM_INPUT_TYPE_EMAIL, 
                        IME_SETTING_FLAG_NONE,
                        VFX_TRUE,
                        funcBar,
                        form);

    // Password
    pswdTextInput = vapp_email_create_text_input_form_item(
                        VFX_WSTR_RES(STR_GLOBAL_PASSWORD),
                        currAcct->in_auth.password,
                        SRV_EMAIL_MAX_PASSWORD_LEN,
                        IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, 
                        IME_SETTING_FLAG_NONE,
                        VFX_TRUE,
                        funcBar,
                        form);

    addrTextInput->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctWizardOthersBasicPage::onTextActivated);
    userTextInput->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctWizardOthersBasicPage::onTextActivated);
    pswdTextInput->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctWizardOthersBasicPage::onTextActivated);

    form->addCaption(VFX_WSTR_RES(STR_EMAIL_FTO_USER_INFO), ADDR_USER_INFO_ENUM);
    form->addItem(addrTextInput, ADDR_TEXTINPUT_ENUM);
    form->addItem(userTextInput, USER_NAME_TEXTINPUT_ENUM);
    form->addItem(pswdTextInput, PSWD_TEXTINPUT_ENUM);

    if (mmi_wcslen(currAcct->email_addr.email_addr) > 0)
    {
        userTextInput->getTextBox()->setAutoActivated(VFX_TRUE);
    }
    else
    {
        addrTextInput->getTextBox()->setAutoActivated(VFX_TRUE);
    }
}

void VappEmailAcctWizardOthersBasicPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    funcBar->setLayout(param.rotateTo);
}

void VappEmailAcctWizardOthersBasicPage::onToolBarClick(
    VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 'NEXT':
        {
            VfxBool encounterError = VFX_FALSE;

            srv_email_acct_info_struct *curr_acct =
                &((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo;

            if (addrTextInput->getText().getLength() == 0)
            {
                encounterError = VFX_TRUE;
                addrTextInput->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_EMAIL_ADDR));
            }
            else if (!vapp_email_util_chk_addr(
                addrTextInput->getText().getBuf()))
            {
                encounterError = VFX_TRUE;
                addrTextInput->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_INVALID_EMAIL_ADDR));
            }
            else if (VappEmailAcct::isAcctAddrExist(
                addrTextInput->getText().getBuf(), EMAIL_ACCT_INVALID_ID))
            {
                encounterError = VFX_TRUE;
                addrTextInput->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_ADDR_EXIST));
            }
            else
            {
                addrTextInput->setWarningText(VFX_WSTR_EMPTY);
            }

            if (userTextInput->getText().getLength() == 0)
            {
                encounterError = VFX_TRUE;
                userTextInput->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_USER_NAME));
            }
            else
            {
                userTextInput->setWarningText(VFX_WSTR_EMPTY);
            }

            if (pswdTextInput->getText().getLength() == 0)
            {
                encounterError = VFX_TRUE;
                pswdTextInput->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_PSWD));
            }
            else
            {
                pswdTextInput->setWarningText(VFX_WSTR_EMPTY);
            }

            if (encounterError)
            {
                return;
            }

            mmi_wcsncpy(curr_acct->email_addr.email_addr,
                        addrTextInput->getText().getBuf(),
                        SRV_EMAIL_MAX_ADDR_LEN);
            mmi_wcsncpy(curr_acct->acct_name,
                        curr_acct->email_addr.email_addr,
                        SRV_EMAIL_MAX_ACCT_NAME_LEN);
            mmi_wcsncpy(curr_acct->in_auth.username,
                        userTextInput->getText().getBuf(),
                        SRV_EMAIL_MAX_USERNAME_LEN);
            mmi_wcsncpy(curr_acct->in_auth.password,
                        pswdTextInput->getText().getBuf(),
                        SRV_EMAIL_MAX_PASSWORD_LEN);
            mmi_wcsncpy(curr_acct->out_auth.username,
                        curr_acct->in_auth.username,
                        SRV_EMAIL_MAX_USERNAME_LEN);
            mmi_wcsncpy(curr_acct->out_auth.password,
                        curr_acct->in_auth.password,
                        SRV_EMAIL_MAX_PASSWORD_LEN);
            curr_acct->in_auth.auth_type = SRV_EMAIL_AUTH_USER;
            curr_acct->out_auth.auth_type = SRV_EMAIL_AUTH_USER;

            VfxResId item_res[] = {STR_EMAIL_POP3_ID, STR_EMAIL_IMAP4_ID};
            VFX_OBJ_CREATE_EX(
                protocolPage,
                VappEmailListSingleSelectTmplPage,
                this,
                (VFX_TRUE));
            protocolPage->setListItem(2, STR_EMAIL_FTO_PROTOCOL_2_3, item_res);
            protocolPage->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION);
            protocolPage->setInitSelectItem(0);
            protocolPage->setNoPopPage();
            protocolPage->setToolBar(
                'NEXT', STR_EMAIL_FTO_TOOLBAR_NEXT, IMG_EMAIL_FTO_TB_NEXT,
                'CANC', STR_GLOBAL_CANCEL, IMG_EMAIL_FTO_CANCEL);
            protocolPage->m_signal_toolbar_Tap.connect(
                this,
                &VappEmailAcctWizardOthersBasicPage::onSubPageToolBarClick);
            getMainScr()->pushPage(0, protocolPage);
            break;
        }
        case 'CANC':
        {
            getMainScr()->exit();
            break;
        }
    }
}

void VappEmailAcctWizardOthersBasicPage::onFuncBarClick(VfxObject*, VfxId id)
{
    switch (id)
    {
        case FUNCBAR_PREV:
            prevEditor->activate();
            break;
        case FUNCBAR_NEXT:
            nextEditor->activate();
            break;
        case FUNCBAR_OK:
            currEditor->deactivate();
            onToolBarClick(NULL, 'NEXT');
            break;
    }
}

void VappEmailAcctWizardOthersBasicPage::onTextActivated(
    VcpTextEditor *sender, VfxBool activated)
{
    if (activated)
    {
        currEditor = sender;
        if (sender == addrTextInput->getTextBox())
        {
            prevEditor = NULL;
            nextEditor = userTextInput->getTextBox();
        }
        else if (sender == userTextInput->getTextBox())
        {
            prevEditor = addrTextInput->getTextBox();
            nextEditor = pswdTextInput->getTextBox();
        }
        else if (sender == pswdTextInput->getTextBox())
        {
            prevEditor = userTextInput->getTextBox();
            nextEditor = NULL;
        }
        funcBar->setDisableItem(FUNCBAR_PREV, prevEditor == NULL);
        funcBar->setDisableItem(FUNCBAR_NEXT, nextEditor == NULL);
    }
}

void VappEmailAcctWizardOthersBasicPage::onSubPageToolBarClick(
    VfxObject* sender, VfxId id, VfxS32 selectedIndex)
{
    switch (id)
    {
        case 'NEXT':
        {
            srv_email_acct_info_struct *curr_acct =
                &((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo;

            curr_acct->protocol =
                (selectedIndex == 0) ?
                SRV_EMAIL_PROT_POP3 :
                SRV_EMAIL_PROT_IMAP4;

            VappEmailAcctWizardFinishPage *finishPage;
            VFX_OBJ_CREATE_EX(
                finishPage, VappEmailAcctWizardFinishPage, this, (VFX_FALSE));
            getMainScr()->pushPage(0, finishPage);
            break;
        }
        case 'CANC':
        {
            getMainScr()->exit();
            break;
        }
    }
}

/****************** Account Wizard Address & Password Page ******************/
VappEmailAcctWizardFinishPage::VappEmailAcctWizardFinishPage(VfxBool byTmpl):
    indicatorPop(NULL),
    createByTemplate(byTmpl),
    acctHandle(EMAIL_ACCT_INVALID_HANDLE)
{
}

VfxBool VappEmailStillSaveCfmPop::onKeyInput(VfxKeyEvent & event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN &&
        event.keyCode == VFX_KEY_CODE_HOME)
    {
        m_signalButtonClicked.emit(this, VCP_CONFIRM_POPUP_BUTTON_CANCEL);
    }

    return VcpConfirmPopup::onKeyInput(event);
}


VappEmailAcctWizardFinishPage::~VappEmailAcctWizardFinishPage()
{
}

void VappEmailAcctWizardFinishPage::onInit()
{
    VfxPage::onInit();

    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappEmailAcctWizardFinishPage::onToolBarClick);
    m_toolBar->addItem(
        'TEST', VFX_WSTR_RES(STR_EMAIL_FTO_FINISH), IMG_EMAIL_FTO_SAVE);
    m_toolBar->addItem(
        'CNCL', VFX_WSTR_RES(STR_GLOBAL_CANCEL), IMG_EMAIL_FTO_CANCEL);
    setBottomBar(m_toolBar);

    VFX_OBJ_CREATE(funcBar, VcpFunctionBar, this);
    funcBar->addItem(FUNCBAR_PREV, VFX_WSTR_RES(STR_EMAIL_FTO_PREV));
    funcBar->addItem(FUNCBAR_NEXT, VFX_WSTR_RES(STR_EMAIL_FTO_NEXT));
    funcBar->addItem(FUNCBAR_FINISH, VFX_WSTR_RES(STR_EMAIL_FTO_FINISH));
    funcBar->setItemSpecial(FUNCBAR_FINISH);
    funcBar->m_signalButtonTap.connect(
        this, &VappEmailAcctWizardFinishPage::onFuncBarClick);

    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setPos(0, 0);
    form->setBounds(VfxRect(0, 0, getRect().size.width, getRect().size.height));

    if (createByTemplate)
    {
        tmplOnInit();
    }
    else
    {
        othersOnInit();
    }

    form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappEmailAcctWizardFinishPage::onDeinit()
{
    EMAIL_ACCT_ID savedAcctId;
    VappEmailAcctStateEnum acctState;
    
    savedAcctId = ((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo.acct_id;
    acctState = VappEmailMgr::getInstance()->getAcctState(savedAcctId);

    if (acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_TEST_WAITING ||
        acctState == VAPP_EMAIL_ACCT_STATE_NETWORK_TESTING)
    {
        /* deinit at background, we should cancel account testing */
        VappEmailMgr::getInstance()->cancelTestAcctNetwork(savedAcctId);
    }

    VfxPage::onDeinit();
}


void VappEmailAcctWizardFinishPage::tmplOnInit()
{
    vapp_email_set_titlebar(VFX_WSTR_RES(STR_EMAIL_FTO_BASIC_INFO), this);

    VappEmailStateEnum emailState =
        VappEmailMgr::getInstance()->getEmailAppState();

    VappEmailAcctWizardScreen *aws = (VappEmailAcctWizardScreen*)getMainScr();

    //address
    addrTextInput = vapp_email_create_text_input_form_item(
                        VFX_WSTR_RES(STR_EMAIL_FTO_EMAIL_ADDR),
                        (VfxWChar*)&aws->acctTemplate->addr,
                        MMI_EMAIL_MAX_ADDR_LEN,
                        IMM_INPUT_TYPE_EMAIL, 
                        IME_SETTING_FLAG_NONE,
                        VFX_TRUE,
                        funcBar,
                        form);
    
    //password
    pswdTextInput = vapp_email_create_text_input_form_item(
                        VFX_WSTR_RES(STR_GLOBAL_PASSWORD),
                        (VfxWChar*)L"",
                        SRV_EMAIL_MAX_PASSWORD_LEN,
                        IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, 
                        IME_SETTING_FLAG_NONE,
                        VFX_TRUE,
                        funcBar,
                        form);
    
    addrTextInput->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctWizardFinishPage::onTextActivated);
    pswdTextInput->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctWizardFinishPage::onTextActivated);

    form->addItem(addrTextInput, ADDR_TEXTINPUT_ENUM);
    form->addItem(pswdTextInput, PSWD_TEXTINPUT_ENUM);

    addrTextInput->getTextBox()->setAutoActivated(VFX_TRUE, 0);
}

void VappEmailAcctWizardFinishPage::othersOnInit()
{
    vapp_email_set_titlebar(VFX_WSTR_RES(STR_EMAIL_FTO_SERVER_INFO_3_3), this);

    VappEmailStateEnum emailState =
        VappEmailMgr::getInstance()->getEmailAppState();

    srv_email_acct_info_struct *currAcct =
        &((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo;
    VfxWChar *domainPtr = mmi_wcschr(currAcct->email_addr.email_addr, L'@');
    if (domainPtr != NULL)
    {
        domainPtr += 1;
    }
    VfxWString serverText;

    if (currAcct->protocol == SRV_EMAIL_PROT_POP3)
    {
        serverText = VFX_WSTR("pop.");
    }
    else
    {
        serverText = VFX_WSTR("imap.");
    }

    if (domainPtr != NULL)
    {
        serverText += VFX_WSTR_MEM(domainPtr);
    }

    //incoming server
    incomingEditor = vapp_email_create_text_input_form_item(
                        VFX_WSTR_RES(STR_EMAIL_FTO_INCOMING_SERVER),
                        (VfxWChar*)serverText.getBuf(),
                        SRV_EMAIL_MAX_SERVER_NAME_LEN,
                        IMM_INPUT_TYPE_EMAIL, 
                        IME_SETTING_FLAG_NONE,
                        VFX_TRUE,
                        funcBar,
                        form);

    //outgoing server
    serverText = VFX_WSTR("smtp.");
    if (domainPtr != NULL)
    {
        serverText += VFX_WSTR_MEM(domainPtr);
    }

    outgoingEditor = vapp_email_create_text_input_form_item(
                        VFX_WSTR_RES(STR_EMAIL_FTO_OUTGOING_SERVER),
                        (VfxWChar*)serverText.getBuf(),
                        SRV_EMAIL_MAX_SERVER_NAME_LEN,
                        IMM_INPUT_TYPE_EMAIL, 
                        IME_SETTING_FLAG_NONE,
                        VFX_TRUE,
                        funcBar,
                        form);

    incomingEditor->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctWizardFinishPage::onTextActivated);
    outgoingEditor->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctWizardFinishPage::onTextActivated);

    form->addItem(incomingEditor, INCOMING_EDITOR_ENUM);
    form->addItem(outgoingEditor, OUTGOING_EDITOR_ENUM);

    incomingEditor->getTextBox()->setAutoActivated(VFX_TRUE);
}

void VappEmailAcctWizardFinishPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    funcBar->setLayout(param.rotateTo);
}

void VappEmailAcctWizardFinishPage::onFuncBarClick(VfxObject*, VfxId id)
{
    switch (id)
    {
        case FUNCBAR_PREV:
            prevEditor->activate();
            break;
        case FUNCBAR_NEXT:
            nextEditor->activate();
            break;
        case FUNCBAR_TEST:
            currEditor->deactivate();
            onToolBarClick(NULL, 'TEST');
            break;
        case FUNCBAR_FINISH:
            currEditor->deactivate();
            onToolBarClick(NULL, 'TEST');
            break;
    }
}

void VappEmailAcctWizardFinishPage::onTextActivated(
    VcpTextEditor *sender, VfxBool activated)
{
    if (activated)
    {
        currEditor = sender;

        if (createByTemplate)
        {
            if (sender == addrTextInput->getTextBox())
            {
                prevEditor = NULL;
                nextEditor = pswdTextInput->getTextBox();
            }
            else if (sender == pswdTextInput->getTextBox())
            {
                prevEditor = addrTextInput->getTextBox();
                nextEditor = NULL;
            }
        }
        else
        {
            if (sender == incomingEditor->getTextBox())
            {
                prevEditor = NULL;
                nextEditor = outgoingEditor->getTextBox();
            }
            else if (sender == outgoingEditor->getTextBox())
            {
                prevEditor = incomingEditor->getTextBox();
                nextEditor = NULL;
            }
        }

        funcBar->setDisableItem(FUNCBAR_PREV, prevEditor == NULL);
        funcBar->setDisableItem(FUNCBAR_NEXT, nextEditor == NULL);
    }
}

void VappEmailAcctWizardFinishPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 'TEST':
        {
            saveAndTest();
            break;
        }
        case 'FINI':
        {
            saveOnly();
            break;
        }
        case 'CNCL':
        {
            getMainScr()->exit();
            break;
        }
    }
}

VfxBool VappEmailAcctWizardFinishPage::isNetworkValid()
{
    VappEmailStateEnum emailState =
        VappEmailMgr::getInstance()->getEmailAppState();
    if (emailState == VAPP_EMAIL_STATE_FLIGHT_MODE)
    {
        vapp_email_util_nmgr_balloon(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE);
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxBool VappEmailAcctWizardFinishPage::isEditorDataValid()
{
    VfxBool encounterError = VFX_FALSE;

    if (createByTemplate)
    {
        VappEmailAcctWizardScreen *aws =
            (VappEmailAcctWizardScreen*)getMainScr();

        if (addrTextInput->getText().getLength() == 0)
        {
            encounterError = VFX_TRUE;
            addrTextInput->setWarningText(
                VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_EMAIL_ADDR));
        }
        else if (!vapp_email_util_chk_addr(addrTextInput->getText().getBuf()))
        {
            encounterError = VFX_TRUE;
            addrTextInput->setWarningText(
                VFX_WSTR_RES(STR_EMAIL_FTO_INVALID_EMAIL_ADDR));
        }
        else if (VappEmailAcct::isAcctAddrExist(
                    addrTextInput->getText().getBuf(), EMAIL_ACCT_INVALID_ID))
        {
            encounterError = VFX_TRUE;
            addrTextInput->setWarningText(
                VFX_WSTR_RES(STR_EMAIL_FTO_ADDR_EXIST));
        }
        else
        {
            addrTextInput->setWarningText(VFX_WSTR_EMPTY);
        }

        if (pswdTextInput->getText().getLength() == 0)
        {
            encounterError = VFX_TRUE;
            pswdTextInput->setWarningText(
                VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_PSWD));
        }
        else
        {
            pswdTextInput->setWarningText(VFX_WSTR_EMPTY);
        }

        return !encounterError;
    }

    if (!vapp_email_util_is_server_vaild(incomingEditor->getText().getBuf()))
    {
        encounterError = VFX_TRUE;
        incomingEditor->setWarningText(
            VFX_WSTR_RES(STR_EMAIL_FTO_INVLAID_SERVER_ADDR));
    }
    else
    {
        incomingEditor->setWarningText(VFX_WSTR_EMPTY);
    }

    if (!vapp_email_util_is_server_vaild(outgoingEditor->getText().getBuf()))
    {
        encounterError = VFX_TRUE;
        outgoingEditor->setWarningText(
            VFX_WSTR_RES(STR_EMAIL_FTO_INVLAID_SERVER_ADDR));
    }
    else
    {
        outgoingEditor->setWarningText(VFX_WSTR_EMPTY);
    }

    return !encounterError;
}

void VappEmailAcctWizardFinishPage::saveEditorData()
{
    srv_email_acct_info_struct *currAcct =
        &((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo;

    if (createByTemplate)
    {
        mmi_wcsncpy(currAcct->email_addr.email_addr,
                    addrTextInput->getText().getBuf(),
                    SRV_EMAIL_MAX_ADDR_LEN);
        mmi_wcsncpy(currAcct->in_auth.password,
                    pswdTextInput->getText().getBuf(),
                    SRV_EMAIL_MAX_PASSWORD_LEN);
        return;
    }

    mmi_wcsncpy(currAcct->in_server.server_name,
                incomingEditor->getText().getBuf(),
                SRV_EMAIL_MAX_SERVER_NAME_LEN);
    mmi_wcsncpy(currAcct->out_server.server_name,
                outgoingEditor->getText().getBuf(),
                SRV_EMAIL_MAX_SERVER_NAME_LEN);
}

void VappEmailAcctWizardFinishPage::fillAcctInfo()
{
    srv_email_acct_info_struct *currAcct =
        &((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo;

    if (createByTemplate)
    {
        VappEmailAcctWizardScreen* aws =
            (VappEmailAcctWizardScreen*)getMainScr();

        currAcct->protocol = aws->acctTemplate->protocol;
        VfxBool isPop3 = SRV_EMAIL_PROT_POP3 == currAcct->protocol;

        memcpy(&(currAcct->in_server),
               &(aws->acctTemplate->incoming_server),
               sizeof(mmi_email_acct_server_struct));
        if (currAcct->in_server.port_num == 0)
        {
            currAcct->in_server.port_num =
                isPop3 ?
                VAPP_EMAIL_POP3_PORT_NUMBER :
                VAPP_EMAIL_IMAP_PORT_NUMBER;
        }
        if (currAcct->in_server.sec_port_num == 0)
        {
            currAcct->in_server.sec_port_num =
                isPop3 ?
                VAPP_EMAIL_POP3_SECURITY_PORT_NUMBER :
                VAPP_EMAIL_IMAP_SECURITY_PORT_NUMBER;
        }

        memcpy(&(currAcct->out_server),
               &(aws->acctTemplate->outgoing_server),
               sizeof(mmi_email_acct_server_struct));
        if (currAcct->out_server.port_num == 0)
        {
            currAcct->out_server.port_num = VAPP_EMAIL_SMTP_PORT_NUMBER;
        }
        if (currAcct->out_server.sec_port_num == 0)
        {
            currAcct->out_server.sec_port_num =
                VAPP_EMAIL_SMTP_SECURITY_PORT_NUMBER;
        }

        VfxU32 user_name_length =
            mmi_wcschr(addrTextInput->getText().getBuf(), L'@') -
            addrTextInput->getText().getBuf();

        if (user_name_length > SRV_EMAIL_MAX_USERNAME_LEN)
        {
            user_name_length = SRV_EMAIL_MAX_USERNAME_LEN;
        }

        mmi_wcsncpy(currAcct->in_auth.username,
                    currAcct->email_addr.email_addr,
                    aws->acctTemplate->username_format ?
                        SRV_EMAIL_MAX_USERNAME_LEN : user_name_length);

        if (aws->acctTemplate->outgoing_auth)
        {
            currAcct->in_auth.auth_type = SRV_EMAIL_AUTH_USER;
            memcpy(&(currAcct->out_auth),
                   &(currAcct->in_auth),
                   sizeof(srv_email_auth_struct));
        }
        else
        {
            currAcct->out_auth.auth_type = SRV_EMAIL_AUTH_NONE;
        }
    }
    else
    {
        currAcct->in_server.port_num =
            currAcct->protocol == SRV_EMAIL_PROT_POP3 ?
                VAPP_EMAIL_POP3_PORT_NUMBER : VAPP_EMAIL_IMAP_PORT_NUMBER;
        currAcct->in_server.sec_mode = SRV_EMAIL_SEC_NONE;
        currAcct->in_server.sec_port_num =
            ((currAcct->protocol == SRV_EMAIL_PROT_POP3)?
            VAPP_EMAIL_POP3_SECURITY_PORT_NUMBER:
            VAPP_EMAIL_IMAP_SECURITY_PORT_NUMBER);
        currAcct->out_server.port_num = VAPP_EMAIL_SMTP_PORT_NUMBER;
        currAcct->out_server.sec_mode = SRV_EMAIL_SEC_NONE;
        currAcct->out_server.sec_port_num =
            VAPP_EMAIL_SMTP_SECURITY_PORT_NUMBER;
    }

    
    VfxU32 simIndex;
    U8 app_id;
    cbm_app_info_struct app_info;
    app_info.app_type = DTCNT_APPTYPE_EMAIL;
    cbm_register_app_id_with_app_info(&app_info, &app_id);

    for (simIndex = 0; simIndex < MMI_MAX_SIM_NUM; simIndex++)
    {
        cbm_sim_id_enum cbm_sim_id;

        switch (simIndex)
        {
            case 0:
                cbm_sim_id = CBM_SIM_ID_SIM1;
                break;
            case 1:
                cbm_sim_id = CBM_SIM_ID_SIM2;
                break;
            case 2:
                cbm_sim_id = CBM_SIM_ID_SIM3;
                break;
            case 3:
                cbm_sim_id = CBM_SIM_ID_SIM4;
                break;
            default:
                cbm_sim_id = CBM_SIM_ID_SIM1;
                break;                
        }

        currAcct->in_server.data_acct[simIndex] = cbm_encode_data_account_id(
                                                        CBM_DEFAULT_ACCT_ID,
                                                        cbm_sim_id,
                                                        app_id,
                                                        MMI_FALSE);
        currAcct->out_server.data_acct[simIndex] = currAcct->in_server.data_acct[simIndex];
    }
    cbm_deregister_app_id(app_id);

    currAcct->in_server.wifi_only = MMI_FALSE;
    currAcct->out_server.wifi_only = MMI_FALSE;
    currAcct->acct_type = SRV_EMAIL_ACCT_USER_CONFIGURED;

    mmi_wcsncpy(currAcct->acct_name,
                currAcct->email_addr.email_addr,
                SRV_EMAIL_MAX_ACCT_NAME_LEN);

    VappEmailAcct::setAcctAttribute(currAcct);
}

void VappEmailAcctWizardFinishPage::setNeedTestNetWork(VfxBool need)
{
    needTestNetwork = need;
}

VfxBool VappEmailAcctWizardFinishPage::matchTemplate()
{
    VappEmailAcctWizardScreen* aws = (VappEmailAcctWizardScreen*)getMainScr();
    S32 index = -1;

    mmi_email_acct_temp_check_addr(
        mmi_wcschr(addrTextInput->getText().getBuf(), L'@'), &index);
    if (index == -1)
    {
        return VFX_FALSE;
    }
    else
    {
        mmi_email_acct_temp_get_acct(index, aws->acctTemplate);
        return VFX_TRUE;
    }
}

void VappEmailAcctWizardFinishPage::onCfmChooseContinue(
    VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VappEmailAcctWizardOthersBasicPage *tmplOthersPage;
        VFX_OBJ_CREATE(
            tmplOthersPage,
            VappEmailAcctWizardOthersBasicPage,
            getMainScr());
        getMainScr()->pushPage(0, tmplOthersPage);
        vfxPostInvoke0(this, &VfxPage::exit);
    }
}

void VappEmailAcctWizardFinishPage::saveAndTest()
{
    if (!isEditorDataValid())
        return;
    if (createByTemplate && !matchTemplate())
    {
        saveEditorData();

        VcpConfirmPopup *confirm;
        VFX_OBJ_CREATE(confirm, VcpConfirmPopup, getMainScr());
        confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
        confirm->setText(VFX_WSTR_RES(STR_EMAIL_FTO_CANNOT_MATCH_TMPL));
        confirm->setAutoDestory(VFX_TRUE);
        confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        confirm->setCustomButton(VFX_WSTR_RES(STR_EMAIL_FTO_CONTINUE),
                                 VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                                 VCP_POPUP_BUTTON_TYPE_RECOMMEND,
                                 VCP_POPUP_BUTTON_TYPE_CANCEL);
        confirm->m_signalButtonClicked.connect(
            this, &VappEmailAcctWizardFinishPage::onCfmChooseContinue);
        confirm->show(VFX_TRUE);
        return;
    }

    setNeedTestNetWork(VFX_TRUE);

    saveEditorData();

    fillAcctInfo();

    saveAcct();
}

void VappEmailAcctWizardFinishPage::saveOnly()
{
    if (!isEditorDataValid())
        return;

    setNeedTestNetWork(VFX_FALSE);

    saveEditorData();

    fillAcctInfo();

    saveAcct();
}

void VappEmailAcctWizardFinishPage::saveAcct()
{
    srv_email_result_enum res;
    VfxResId errResId = STR_GLOBAL_ERROR;
    srv_email_acct_info_struct *currAcct =
        &((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo;

    res = srv_email_acct_create(EMAIL_SRV_INVALID_HANDLE, &acctHandle);

    res = srv_email_acct_new(acctHandle, &(currAcct->acct_id));
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        errResId = ((res == SRV_EMAIL_RESULT_ACCT_ID_REACH_MAX_NUM) ?
                    STR_EMAIL_FTO_MAX_NUM_REACHED :
                    vapp_email_util_get_err_code(res, srv_email_errno_get()));
        goto ERROR_EXIT;
    }

    res = srv_email_acct_edit(acctHandle, currAcct);
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        errResId = vapp_email_util_get_err_code(res, srv_email_errno_get());
        goto ERROR_EXIT;
    }

    res = srv_email_acct_save_async(
            acctHandle,
            &VappEmailAcctWizardFinishPage::saveAcctProc, this);
    if (res != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        errResId = vapp_email_util_get_err_code(res, srv_email_errno_get());
        goto ERROR_EXIT;
    }

    VappEmailAcct::setGlobalSaveSendEmails(VFX_FALSE, currAcct->acct_id);

    VFX_OBJ_CREATE(indicatorPop, VappEmailAcctWizardPop, this);
    indicatorPop->setInfoType(
        needTestNetwork ?
            VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON :
            VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    indicatorPop->setText(
        VFX_WSTR_RES((needTestNetwork ?
            STR_EMAIL_FTO_VERIFYING :
            STR_GLOBAL_SAVING)));
    indicatorPop->setAutoDestory(VFX_TRUE);
    indicatorPop->m_signalCanceled.connect(
        this, &VappEmailAcctWizardFinishPage::saveAcctCancelProc);
    indicatorPop->show(VFX_TRUE);
    return;

ERROR_EXIT:
    vapp_email_alert_cfm(errResId);
    srv_email_acct_destroy(acctHandle);
}

void VappEmailAcctWizardFinishPage::saveAcctCancelProc(VfxObject*, VfxFloat)
{
    VEMAIL_TRC_ACCT_SAVE_CANCEL();

    indicatorPop = NULL;
    srv_email_acct_save_async_abort();
    srv_email_acct_destroy(acctHandle);
    acctHandle = EMAIL_ACCT_INVALID_HANDLE;
}

void VappEmailAcctWizardFinishPage::saveAcctProc(
    srv_email_result_enum res, void *userData)
{
    VappEmailAcctWizardFinishPage *page =
        static_cast<VappEmailAcctWizardFinishPage*>(userData);
    VappEmailAcctWizardScreen *scr =
        static_cast<VappEmailAcctWizardScreen*>(page->getMainScr());

    if (page == NULL || scr == NULL)
    {
        // some error happen
        // for example, Email exit caused by memory card pluged out
        return;
    }

    VfxBool needDelAcct = VFX_FALSE;

    VEMAIL_TRC_ACCT_SAVE_PROC(res);

    if (res == SRV_EMAIL_RESULT_SUCC)
    {
        if (!VappEmailAcct::initMiscInfo(scr->currAcctInfo.acct_id))
        {
            VEMAIL_TRC_ACCT_SAVE_INIT_MISC_FAIL();
            needDelAcct = VFX_TRUE;
        }
    }
    else
    {
        needDelAcct = VFX_TRUE;
    }

    srv_email_acct_destroy(page->acctHandle);
    page->acctHandle = EMAIL_ACCT_INVALID_HANDLE;

    if (needDelAcct)
    {
        srv_email_result_enum delRes;
        delRes = srv_email_acct_delete(scr->currAcctInfo.acct_id);

        VEMAIL_TRC_ACCT_SAVE_PROC_DEL_ACCT(delRes);
    }

    if (needDelAcct || !page->needTestNetwork)
    {
        VFX_OBJ_CLOSE(page->indicatorPop);

        if (needDelAcct)
        {
            vapp_email_alert_cfm(
                vapp_email_util_get_err_code(res, srv_email_errno_get()));
        }

        scr->exit();
    }
    else
    {
        // refresh the signal handle function
        page->indicatorPop->m_signalCanceled.disconnect(
            page, &VappEmailAcctWizardFinishPage::saveAcctCancelProc);
        page->indicatorPop->m_signalCanceled.connect(
            page, &VappEmailAcctWizardFinishPage::testNetworkCancelProc);

        // start testing network, handle the signal anyway
        VappEmailMgr::getInstance()->m_signalAcctNwkDone.connect(
            page, &VappEmailAcctWizardFinishPage::testNetworkProc);
        VappEmailResEnum mgrRes =
            VappEmailMgr::getInstance()->testAcctNetwork(
                scr->currAcctInfo.acct_id);
            VEMAIL_TRC_ACCT_SAVE_PROC_TEST_NWK(mgrRes);
        }
}

void VappEmailAcctWizardFinishPage::testNetworkCancelProc(VfxObject*, VfxFloat)
{
    VEMAIL_TRC_ACCT_SAVE_TEST_NWK_CANCEL();

    indicatorPop = NULL;

    EMAIL_ACCT_ID savedAcctId =
        ((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo.acct_id;

    VappEmailMgr::getInstance()->cancelTestAcctNetwork(savedAcctId);

    delCurrAcct();
}

void VappEmailAcctWizardFinishPage::delCurrAcct()
{
    EMAIL_ACCT_ID savedAcctId =
        ((VappEmailAcctWizardScreen*)getMainScr())->currAcctInfo.acct_id;

    srv_email_result_enum delRes = srv_email_acct_delete(savedAcctId);
    if (delRes != SRV_EMAIL_RESULT_SUCC)
    {
        VEMAIL_TRC_ACCT_SAVE_PROC_DEL_ACCT(delRes);
        return;
    }

    mmi_email_auto_check_delete_acct(savedAcctId, MMI_TRUE);
    mmi_email_sig_delete_acct(savedAcctId, MMI_TRUE);
}

void VappEmailAcctWizardFinishPage::testNetworkProc(
    EMAIL_ACCT_ID acctId,
    VappEmailNwkDoneEnum nwkDoneType,
    VappEmailResStruct res)
{
    if (nwkDoneType != VAPP_EMAIL_NWK_DONE_NETWORK_TEST)
    {
        return;
    }

    if (indicatorPop != NULL && indicatorPop->isValid())
    {
        VFX_OBJ_CLOSE(indicatorPop);
    }

    VEMAIL_TRC_ACCT_SAVE_TEST_NWK_RESUTL(res.result, res.major, res.minor);

    if (res.result == VAPP_EMAIL_RES_SUCC)
    {
        closePrevMainScr();
        getMainScr()->exit();
    }
    else
    {
        VappEmailStillSaveCfmPop *retryCfm;
        VFX_OBJ_CREATE(retryCfm, VappEmailStillSaveCfmPop, findScreen());

        retryCfm->setText(VFX_WSTR_RES(STR_EMAIL_FTO_TEST_FAILED));
        retryCfm->setInfoType(VCP_POPUP_TYPE_FAILURE);
        retryCfm->setAutoDestory(VFX_TRUE);
        retryCfm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        retryCfm->setCustomButton(
            VFX_WSTR_RES(STR_EMAIL_FTO_STILL_SAVE),
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_CANCEL);

        retryCfm->m_signalButtonClicked.connect(this,
            &VappEmailAcctWizardFinishPage::confirmChooseProc);
        retryCfm->show(VFX_TRUE);
    }
}

void VappEmailAcctWizardFinishPage::confirmChooseProc(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        closePrevMainScr();
        getMainScr()->exit();
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2 ||
             id == VCP_CONFIRM_POPUP_BUTTON_CANCEL)
    {
        delCurrAcct();
    }
}

void VappEmailAcctWizardFinishPage::closePrevMainScr()
{
    if (globalSettingScrPtr != NULL)
    {
        globalSettingScrPtr->exit();
    }
}

