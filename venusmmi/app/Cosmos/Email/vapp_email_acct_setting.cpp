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
 *  Vapp_email_acct.cpp
 *
 * Project:
 * --------
 *  COSMOS Email Single Account Setting
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

#include "vapp_email_acct_setting.h"
#include "vapp_email_mgr.h"
#include "Vapp_email_sso.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vcui_dtcnt_select_gprot.h"
#include "vapp_dtcnt_gprot.h"
#include "vcui_gallery_gprot.h"
extern "C"{
#include "FileMgrType.h"
#include "SimCtrlSrvGprot.h"
}

/****************** Account Setting Screen ******************/
VappEmailAcctSettingScreen::VappEmailAcctSettingScreen(EMAIL_ACCT_ID id)
{
    this->acctId = id;
    VEMAIL_TRC_ACCT_SET_ID(id);
}

VappEmailAcctSettingScreen::~VappEmailAcctSettingScreen()
{
    EMAIL_ACCT_ID acctId = acctInfo->getBasicInfo()->acct_id;

    VFX_DELETE(acctInfo);

    VEMAIL_TRC_ACCT_SET_ID(acctId);
    VappEmailMgr::getInstance()->editAcctStop(acctId);
}

void VappEmailAcctSettingScreen::on1stReady(void)
{
    VfxMainScr::on1stReady();

    VappEmailAcctNormalSettingPage *normal_setting_page;
    VFX_OBJ_CREATE(normal_setting_page, VappEmailAcctNormalSettingPage, this);
    pushPage(0, normal_setting_page);
}

srv_email_result_enum VappEmailAcctSettingScreen::show(void)
{
    VFX_ASSERT(acctId != EMAIL_ACCT_INVALID_ID);

    VFX_ALLOC_NEW_EX(acctInfo, VappEmailAcct, this, (acctId));

    srv_email_result_enum res = acctInfo->initData();

    VEMAIL_TRC_ACCT_INIT_DATA(res);

    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        return res;
    }

    VfxMainScr::show();

    return SRV_EMAIL_RESULT_SUCC;
}

VappEmailAcct *VappEmailAcctSettingScreen::getCurrAcct(void) const
{
    return acctInfo;
}

VappEmailAcctSettingScreen *VappEmailTmplAcctSettingPage::getMainScr() const
{
    return static_cast<VappEmailAcctSettingScreen*>(VfxPage::getMainScr());
}

void VappEmailTmplAcctSettingPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    if (funcBar != NULL)
    {
        funcBar->setLayout(param.rotateTo);
    }
}


/****************** Account Normal Setting Page ******************/
void VappEmailAcctNormalSettingPage::onInit(void)
{
    VfxPage::onInit();

    const srv_email_acct_info_struct *acct = getMainScr()->getCurrAcct()->getBasicInfo();

    vapp_email_set_titlebar(VFX_WSTR_MEM(acct->acct_name), this);

    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappEmailAcctNormalSettingPage::onToolBarClick);
    m_toolBar->addItem('SAVE', VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_EMAIL_FTO_SAVE);
    m_toolBar->addItem('DELE', VFX_WSTR_RES(STR_GLOBAL_DELETE), IMG_EMAIL_FTO_DELETE);
    m_toolBar->addItem('ADVC', VFX_WSTR_RES(STR_EMAIL_FTO_ADVANCED), IMG_EMAIL_FTO_SETTING);
    setBottomBar(m_toolBar);

    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setRect(0, 0, getSize().width, getSize().height);
    form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(funcBar, VcpFunctionBar, this);
    funcBar->addItem(FUNCBAR_PREV, VFX_WSTR_RES(STR_EMAIL_FTO_PREV));
    funcBar->addItem(FUNCBAR_NEXT, VFX_WSTR_RES(STR_EMAIL_FTO_NEXT));
    funcBar->addItem(FUNCBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    funcBar->setItemSpecial(FUNCBAR_SAVE);
    funcBar->m_signalButtonTap.connect(
        this, &VappEmailAcctNormalSettingPage::onFuncBarClick);

    //address
    addr = vapp_email_create_text_input_form_item(
                VFX_WSTR_RES(STR_EMAIL_FTO_EMAIL_ADDR),
                (VfxWChar*)&acct->email_addr.email_addr,
                MMI_EMAIL_MAX_ADDR_LEN,
                IMM_INPUT_TYPE_EMAIL,
                IME_SETTING_FLAG_NONE,
                VFX_TRUE,
                funcBar,
                form);
    addr->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctNormalSettingPage::onTextActivated);    

    //account name
    acctName = vapp_email_create_text_input_form_item(
                    VFX_WSTR_RES(STR_EMAIL_ACCT_NAME_ID),
                    (VfxWChar*)&acct->acct_name,
                    SRV_EMAIL_MAX_ACCT_NAME_LEN,
                    IMM_INPUT_TYPE_SENTENCE,
                    IME_SETTING_FLAG_NONE,
                    VFX_TRUE,
                    funcBar,
                    form);
    acctName->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctNormalSettingPage::onTextActivated);

    //display name
    dispName = vapp_email_create_text_input_form_item(
                    VFX_WSTR_RES(STR_EMAIL_DISPLAY_NAME_ID),
                    (VfxWChar*)&acct->email_addr.disp_name,
                    SRV_EMAIL_MAX_DISP_NAME_LEN,
                    IMM_INPUT_TYPE_SENTENCE,
                    IME_SETTING_FLAG_NONE,
                    VFX_TRUE,
                    funcBar,
                    form);
    dispName->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctNormalSettingPage::onTextActivated);
    
    //user name
    userName = vapp_email_create_text_input_form_item(
                    VFX_WSTR_RES(STR_GLOBAL_USERNAME),
                    (VfxWChar*)&acct->in_auth.username,
                    SRV_EMAIL_MAX_USERNAME_LEN,
                    IMM_INPUT_TYPE_EMAIL, 
                    IME_SETTING_FLAG_NONE,
                    VFX_TRUE,
                    funcBar,
                    form);
    userName->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctNormalSettingPage::onTextActivated);

    //password
    pswd = vapp_email_create_text_input_form_item(
                VFX_WSTR_RES(STR_GLOBAL_PASSWORD),
                (VfxWChar*)&acct->in_auth.password,
                SRV_EMAIL_MAX_PASSWORD_LEN,
                IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, 
                IME_SETTING_FLAG_NONE,
                VFX_TRUE,
                funcBar,
                form);
    pswd->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctNormalSettingPage::onTextActivated);

#ifdef __MMI_SSO__
        if (vapp_email_is_cloud_acct(getMainScr()->getCurrAcct()->getBasicInfo()->acct_id))
        {
            addr->setIsDisabled(VFX_TRUE);
            userName->setIsDisabled(VFX_TRUE);
            pswd->setIsDisabled(VFX_TRUE);
        }
#endif /* #ifdef __MMI_SSO__ */

    //default account
    VFX_OBJ_CREATE(defaultDataAcct, VcpFormItemLauncherCell, form);
    defaultDataAcct->setMainText(VFX_WSTR_RES(STR_GLOBAL_DATA_CONN_SETTING));
    defaultDataAcct->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    defaultDataAcct->m_signalTap.connect(
        this, &VappEmailAcctNormalSettingPage::onFormCellClick);
    defaultDataAcct->setIsDisabled(!srv_sim_ctrl_any_sim_is_available());

    //download option
    VFX_OBJ_CREATE(downloadOption, VcpFormItemLauncherCell, form);
    downloadOption->setMainText(VFX_WSTR_RES(STR_EMAIL_FTO_DOWNLOAD_OPTION));
    downloadOption->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    downloadOption->m_signalTap.connect(
        this, &VappEmailAcctNormalSettingPage::onFormCellClick);

    //save sent email
    VFX_OBJ_CREATE(saveSentEmail, VcpFormItemSwitchCell, form);
    saveSentEmail->setIsTappable(VFX_FALSE);
    saveSentEmail->setMainText(VFX_WSTR_RES(STR_EMAIL_SAVE_SENT_EMAILS_ID));
    saveSentEmail->setSwitchStatus(getMainScr()->getCurrAcct()->getSaveSentEmails());
    saveSentEmail->m_signalSwitchChangeReq.connect(
        this, &VappEmailAcctNormalSettingPage::onSwitchClick);
    
    form->addCaption(VFX_WSTR_RES(STR_EMAIL_FTO_USER_INFO), FORM_ITEM_USER_INFO);
    form->addItem(addr, FORM_ITEM_ADDR);
    form->addItem(acctName, FORM_ITEM_ACCT_NAME);
    form->addItem(dispName, FORM_ITEM_DISP_NAME);
    form->addCaption(VFX_WSTR_RES(STR_EMAIL_FTO_LOG_IN_INFO), FORM_ITEM_LOG_IN_INFO);
    form->addItem(userName, FORM_ITEM_USER_NAME);
    form->addItem(pswd, FORM_ITEM_PSWD);
    form->addCaption(VFX_WSTR_RES(STR_EMAIL_FTO_ACCT_INFO), FORM_ITEM_ACCT_INFO);
    form->addItem(defaultDataAcct, FORM_ITEM_DATA_ACCT);
    form->addItem(saveSentEmail, FORM_ITEM_SAVE_SENT_EMAIL);
    form->addItem(downloadOption, FORM_ITEM_DOWNLOAD_OPT);

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    VFX_OBJ_CREATE(checkInterval, VcpFormItemLauncherCell, form);
    checkInterval->setMainText(VFX_WSTR_RES(STR_EMAIL_CHECK_INTERVAL_ID));
    checkInterval->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    checkInterval->m_signalTap.connect(
        this, &VappEmailAcctNormalSettingPage::onFormCellClick);
    form->addItem(checkInterval, FORM_ITEM_CHECK_INTERVAL);
#endif

    VappEmailMgr::getInstance()->m_signalSimAvailableChanged.connect(
        this, &VappEmailAcctNormalSettingPage::onSimAvailableChanged);
}

mmi_ret VappEmailAcctNormalSettingPage::onProc(mmi_event_struct * evt)
{
    cui_dtcnt_select_event_any_sim_selected_struct *dtcntEvt =
                 (cui_dtcnt_select_event_any_sim_selected_struct*)evt;
    switch (evt->evt_id)
    {
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {
            cui_dtcnt_sim_enum sim = dtcntEvt->selectSim;
            VfxU32 accountId = dtcntEvt->accountId;            
            VfxU32 simIndex = 0;
            
            switch (sim)
            {
                case CUI_DTCNT_SIM1:
                    simIndex = 0;
                    break;

                case CUI_DTCNT_SIM2:
                    simIndex = 1;
                    break;

                case CUI_DTCNT_SIM3:
                    simIndex = 2;
                    break;

                case CUI_DTCNT_SIM4:
                    simIndex = 3;
                    break;                    

                default:
                    break;
            }

            VappEmailAcct *acct = getMainScr()->getCurrAcct();

            acct->setDataAcctId(accountId, simIndex, VappEmailAcct::INCOMING);
            acct->setDataAcctId(accountId, simIndex, VappEmailAcct::OUTGOING);

            srv_email_result_enum res = acct->saveAcctInfo();
            VEMAIL_TRC_SAVE_ACCT(res);
            break;
        }
    
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:        
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
            if (appId != 0)
            {
                cbm_deregister_app_id(appId);
                appId = 0;
            }
            vcui_dtcnt_select_close(cuiId);
            break;
            
        default:
            break;
    }
    
    return VappEmailTmplAcctSettingPage::onProc(evt);
}

void VappEmailAcctNormalSettingPage::onFuncBarClick(VfxObject*, VfxId id)
{
    switch (id)
    {
        case FUNCBAR_PREV:
            prevEditor->activate();
            break;
        case FUNCBAR_NEXT:
            nextEditor->activate();
            break;
        case FUNCBAR_SAVE:
            currEditor->deactivate();
            onToolBarClick(NULL, 'SAVE');
            break;
    }
}

void VappEmailAcctNormalSettingPage::onTextActivated(
    VcpTextEditor *sender, VfxBool activated)
{
    if (activated)
    {
        currEditor = sender;

        if (sender == addr->getTextBox())
        {
            prevEditor = NULL;
            nextEditor = acctName->getTextBox();
        }
        else if (sender == acctName->getTextBox())
        {
            prevEditor = addr->getTextBox();
            nextEditor = dispName->getTextBox();
        }
        else if (sender == dispName->getTextBox())
        {
            prevEditor = acctName->getTextBox();
            nextEditor = userName->getTextBox();
        }
        else if (sender == userName->getTextBox())
        {
            prevEditor = dispName->getTextBox();
            nextEditor = pswd->getTextBox();
        }
        else if (sender == pswd->getTextBox())
        {
            prevEditor = userName->getTextBox();
            nextEditor = NULL;
        }
        funcBar->setDisableItem(FUNCBAR_PREV, prevEditor == NULL);
        funcBar->setDisableItem(FUNCBAR_NEXT, nextEditor == NULL);
    }
}

void VappEmailAcctNormalSettingPage::onEnter(VfxBool isBackward)
{
    VfxWString text;
    VappEmailAcct *acct = getMainScr()->getCurrAcct();

    VfxResId dlItemRes[] =
        {
            STR_EMAIL_HEADER_ONLY,
            STR_EMAIL_HEADER_TEXT,
            STR_EMAIL_DOWNLOAD_ALL
        };
    downloadOption->setHintText(
        VFX_WSTR_RES(dlItemRes[(VfxU32)acct->getBasicInfo()->download_option]));

    VfxResId item_res[] =
        {
            STR_GLOBAL_OFF,
            STR_EMAIL_FTO_5_MINS,
            STR_EMAIL_FTO_30_MINS,
            STR_EMAIL_1_HOUR_ID,
            STR_EMAIL_2_HOURS_ID
        };
    VfxU32 index = (VfxU32)acct->getAutoCheckType();
    checkInterval->setHintText(VFX_WSTR_RES(item_res[index]));
}

void VappEmailAcctNormalSettingPage::onConfirmClick(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VappEmailAcct *acct = getMainScr()->getCurrAcct();
            srv_email_result_enum res = acct->delAcct();

            VEMAIL_TRC_DEL_ACCT(acct->getBasicInfo()->acct_id, res);

            getMainScr()->popPage();
            break;
        }
    }
}

void VappEmailAcctNormalSettingPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    VappEmailAcctSettingScreen *scr = (VappEmailAcctSettingScreen*)getMainScr();

    switch (id)
    {
        case 'DELE':
        {
            VcpConfirmPopup *confirm;
            VFX_OBJ_CREATE(confirm, VcpConfirmPopup, findScreen());
            confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
            confirm->setText(VFX_WSTR_RES(STR_EMAIL_FTO_DEL_THE_ACCT));
            confirm->setAutoDestory(VFX_TRUE);
            confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            confirm->setCustomButton(
                        VFX_WSTR_RES(STR_GLOBAL_DELETE),
                        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                        VCP_POPUP_BUTTON_TYPE_WARNING,
                        VCP_POPUP_BUTTON_TYPE_CANCEL);
            confirm->m_signalButtonClicked.connect(
                this, &VappEmailAcctNormalSettingPage::onConfirmClick);
            confirm->show(VFX_TRUE);
            break;
        }
        case 'SAVE':
        {
            VappEmailAcct *acct = getMainScr()->getCurrAcct();

            VfxBool encounterError = VFX_FALSE;
            VfxBool is_cloud = VFX_FALSE;
#ifdef __MMI_SSO__
            is_cloud = vapp_email_is_cloud_acct(acct->getBasicInfo()->acct_id);
#endif

            if (addr->getText().getLength() == 0 && !is_cloud)
            {
                encounterError = VFX_TRUE;
                addr->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_EMAIL_ADDR));
            }
            else if (!vapp_email_util_chk_addr(addr->getText().getBuf()) && !is_cloud)
            {
                encounterError = VFX_TRUE;
                addr->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_INVALID_EMAIL_ADDR));
            }
            else if (VappEmailAcct::isAcctAddrExist(addr->getText().getBuf(),
                        acct->getBasicInfo()->acct_id))
            {
                encounterError = VFX_TRUE;
                addr->setWarningText(VFX_WSTR_RES(STR_EMAIL_FTO_ADDR_EXIST));
            }
            else
            {
                addr->setWarningText(VFX_WSTR_EMPTY);
            }

            if (pswd->getText().getLength() == 0 && !is_cloud)
            {
                encounterError = VFX_TRUE;
                pswd->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_PSWD));
            }
            else
            {
                pswd->setWarningText(VFX_WSTR_EMPTY);
            }

            if (acctName->getText().getLength() == 0)
            {
                encounterError = VFX_TRUE;
                acctName->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_ACCT_NAME));
            }
            else
            {
                acctName->setWarningText(VFX_WSTR_EMPTY);
            }

            if (userName->getText().getLength() == 0 && !is_cloud)
            {
                encounterError = VFX_TRUE;
                userName->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_USER_NAME));
            }
            else
            {
                userName->setWarningText(VFX_WSTR_EMPTY);
            }

            if (encounterError)
            {
                return;
            }

            acct->setAddress(addr->getText());
            acct->setAcctName(acctName->getText());
            acct->setDispName(dispName->getText());
            acct->setUsername(userName->getText(), VappEmailAcct::INCOMING);
            acct->setPassword(pswd->getText(), VappEmailAcct::INCOMING);

            srv_email_result_enum res;
            res = acct->saveAcctInfo();
            VEMAIL_TRC_SAVE_ACCT(res);

            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                vapp_email_alert_cfm(STR_GLOBAL_ERROR);
                return;
            }
            getMainScr()->popPage();
            break;
        }
        case 'ADVC':
        {
            VappEmailAcctAdvSettingMainPage * advPage;
            VFX_OBJ_CREATE(advPage, VappEmailAcctAdvSettingMainPage, this);
            getMainScr()->pushPage(0, advPage);
            return;
        }
    }
}

void VappEmailAcctNormalSettingPage::onSingleSelectSave(
    VfxObject *obj, VfxS32 select_index)
{
    VappEmailAcct *acct = getMainScr()->getCurrAcct();

    if ((VfxObject*)downloadOpt == obj)
    {
        srv_email_download_option_enum dldOpt = SRV_EMAIL_DOWNLOAD_HEADER;

        srv_email_prot_type_enum protocol = acct->getBasicInfo()->protocol;
        switch (select_index)
        {
            case 0:
                dldOpt = SRV_EMAIL_DOWNLOAD_HEADER;
                break;
            case 1:
                if (protocol == SRV_EMAIL_PROT_IMAP4)
                {
                    dldOpt = SRV_EMAIL_DOWNLOAD_HEADER_TEXT;
                }
                else
                {
                    dldOpt = SRV_EMAIL_DOWNLOAD_ALL;
                }
                break;
            case 2:
                dldOpt = SRV_EMAIL_DOWNLOAD_ALL;
                break;
        }
        acct->setDownloadOpt(dldOpt);
    }
    else if ((VfxObject*)chkInterval == obj)
    {
        acct->setAutoCheckType((VappEmailAcct::CheckIntervalEnum)select_index);
    }

    downloadOpt = chkInterval = NULL;

    srv_email_result_enum res = acct->saveAcctInfo();
    VEMAIL_TRC_SAVE_ACCT(res);

    getMainScr()->popPage();
}

void VappEmailAcctNormalSettingPage::onFormCellClick(
    VcpFormItemCell *obj, VfxId id)
{
    VappEmailAcct *acct = getMainScr()->getCurrAcct();

    switch (id)
    {
        case FORM_ITEM_DOWNLOAD_OPT:
        {
            VFX_OBJ_CREATE_EX(
                downloadOpt,
                VappEmailListSingleSelectTmplPage,
                this,
                (VFX_FALSE));

            VfxU32 initSelectItem =
                (VfxU32)acct->getBasicInfo()->download_option;
            srv_email_prot_type_enum protocol = acct->getBasicInfo()->protocol;
            if (protocol == SRV_EMAIL_PROT_IMAP4)
            {
                VfxResId item_res[3] =
                {
                    STR_EMAIL_HEADER_ONLY,
                    STR_EMAIL_HEADER_TEXT,
                    STR_EMAIL_DOWNLOAD_ALL
                };
                downloadOpt->setListItem(
                    3, STR_EMAIL_FTO_DOWNLOAD_OPTION, item_res);
            }
            else
            {
                VfxResId item_res[2] =
                {
                    STR_EMAIL_HEADER_ONLY,
                    STR_EMAIL_DOWNLOAD_ALL
                };
                downloadOpt->setListItem(
                    2, STR_EMAIL_FTO_DOWNLOAD_OPTION, item_res);
                if (initSelectItem > 1)
                    initSelectItem = 1;
            }
            downloadOpt->setInitSelectItem(initSelectItem);
            downloadOpt->m_signal_save.connect(
                this, &VappEmailAcctNormalSettingPage::onSingleSelectSave);
            getMainScr()->pushPage(0, downloadOpt);
            break;
        }
        case FORM_ITEM_CHECK_INTERVAL:
        {
            VfxResId item_res[] =
            {
                STR_GLOBAL_OFF,
                STR_EMAIL_FTO_5_MINS,
                STR_EMAIL_FTO_30_MINS,
                STR_EMAIL_1_HOUR_ID,
                STR_EMAIL_2_HOURS_ID
            };
            VFX_OBJ_CREATE_EX(
                chkInterval,
                VappEmailListSingleSelectTmplPage,
                this,
                (VFX_FALSE));
            chkInterval->setListItem(5, STR_EMAIL_CHECK_INTERVAL_ID, item_res);
            chkInterval->setInitSelectItem(acct->getAutoCheckType());
            chkInterval->m_signal_save.connect(
                this, &VappEmailAcctNormalSettingPage::onSingleSelectSave);
            getMainScr()->pushPage(0, chkInterval);
            break;
        }
        case FORM_ITEM_DATA_ACCT:
        {
            cbm_app_info_struct app_info;
           
            app_info.app_type = DTCNT_APPTYPE_EMAIL;
            cbm_register_app_id_with_app_info(&app_info, &appId);
            
            cui_dtcnt_select_run_struct run_struct;
            memset(&run_struct, 0, sizeof(cui_dtcnt_select_run_struct));

            run_struct.bearers = DATA_ACCOUNT_BEARER_ALL;
            run_struct.app_id = appId;

            VfxU32 simIndex;
            for (simIndex = 0; simIndex < MMI_MAX_SIM_NUM; simIndex++)
            {
                run_struct.sim_account_id[simIndex] =
                    acct->getBasicInfo()->in_server.data_acct[simIndex];
            }

            run_struct.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
            run_struct.option = CUI_DTCNT_SELECT_NONE;
            run_struct.type = CUI_DTCNT_SELECT_TYPE_NORMAL;

            cuiId = vcui_dtcnt_select_create(getMainScr()->getGroupId());
            if (cuiId != GRP_ID_INVALID)
            {
                vfxSetCuiCallerScr(cuiId, getMainScr());
                vcui_dtcnt_select_set_param(cuiId, &run_struct);
                vcui_dtcnt_select_run(cuiId);
            }
            break;
        }
    }
}

void VappEmailAcctNormalSettingPage::onSwitchClick(
    VcpFormItemSwitchCell* cell, VfxId id, VfxBool switch_on)
{
    VappEmailAcct *acct = getMainScr()->getCurrAcct();

    switch (id)
    {
        case FORM_ITEM_SAVE_SENT_EMAIL:
        {
            cell->setSwitchStatus(switch_on);
            acct->setSaveSentEmails(switch_on);

            srv_email_result_enum res = acct->saveAcctInfo();
            VEMAIL_TRC_SAVE_ACCT(res);
            break;
    }
}
}

void VappEmailAcctNormalSettingPage::onSimAvailableChanged(VfxBool simAvailable)
{
    if (simAvailable)
    {
        defaultDataAcct->setIsDisabled(VFX_FALSE);
    }
    else
    {
        defaultDataAcct->setIsDisabled(VFX_TRUE);
    }
}


/****************** Account Advanced Setting Main Page ******************/
void VappEmailAcctAdvSettingMainPage::onInit(void)
{
    VfxPage::onInit();

    vapp_email_set_titlebar(VFX_WSTR_RES(STR_EMAIL_FTO_EMAIL_SETTING), this);

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setRect(0, 0, getSize().width, getSize().height);
    form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemLauncherCell *adv_setting;
    VFX_OBJ_CREATE(adv_setting, VcpFormItemLauncherCell, form);
    adv_setting->setMainText(VFX_WSTR_RES(STR_EMAIL_ACCT_SETTING_ID));
    adv_setting->setAccessory(VCPFORM_NEXT_ITEM_ICON);

    VcpFormItemLauncherCell *outgoing;
    VFX_OBJ_CREATE(outgoing, VcpFormItemLauncherCell, form);
    outgoing->setMainText(VFX_WSTR_RES(STR_EMAIL_FTO_OUTGOING_SERVER));
    outgoing->setAccessory(VCPFORM_NEXT_ITEM_ICON);

#ifdef __MMI_SSO__
    if (vapp_email_is_cloud_acct(getMainScr()->getCurrAcct()->getBasicInfo()->acct_id))
    {
        outgoing->setIsDisabled(VFX_TRUE);
    }
#endif /* #ifdef __MMI_SSO__ */

    VcpFormItemLauncherCell *incoming;
    VFX_OBJ_CREATE(incoming, VcpFormItemLauncherCell, form);
    incoming->setMainText(VFX_WSTR_RES(STR_EMAIL_FTO_INCOMING_SERVER));
    incoming->setAccessory(VCPFORM_NEXT_ITEM_ICON);

    VcpFormItemLauncherCell *signature;
    VFX_OBJ_CREATE(signature, VcpFormItemLauncherCell, form);
    signature->setMainText(VFX_WSTR_RES(STR_EMAIL_SIGNATURE_ID));
    signature->setAccessory(VCPFORM_NEXT_ITEM_ICON);

    adv_setting->m_signalTap.connect(
        this, &VappEmailAcctAdvSettingMainPage::onFormCellClick);
    outgoing->m_signalTap.connect(
        this, &VappEmailAcctAdvSettingMainPage::onFormCellClick);
    incoming->m_signalTap.connect(
        this, &VappEmailAcctAdvSettingMainPage::onFormCellClick);
    signature->m_signalTap.connect(
        this, &VappEmailAcctAdvSettingMainPage::onFormCellClick);

    form->addItem(adv_setting, FORM_ITEM_ACCT_SETTING);
    form->addItem(outgoing, FORM_ITEM_OUTGOING);
    form->addItem(incoming, FORM_ITEM_INCOMING);
    form->addItem(signature, FORM_ITEM_SIGNATURE);
}

void VappEmailAcctAdvSettingMainPage::onFormCellClick(
    VcpFormItemCell *obj, VfxId id)
{
    VfxPage *p = NULL;

    switch (id)
    {
        case FORM_ITEM_ACCT_SETTING:
            VFX_OBJ_CREATE(p, VappEmailAcctAdvSettingAcctPage, this);
            break;
        case FORM_ITEM_OUTGOING:
            VFX_OBJ_CREATE_EX(p, VappEmailAcctAdvSettingServerPage, this, (VappEmailAcctAdvSettingServerPage::EMAIL_OUTGOING_SERVER));
            break;
        case FORM_ITEM_INCOMING:
            VFX_OBJ_CREATE_EX(p, VappEmailAcctAdvSettingServerPage, this, (VappEmailAcctAdvSettingServerPage::EMAIL_INCOMING_SERVER));
            break;
        case FORM_ITEM_SIGNATURE:
            VFX_OBJ_CREATE(p, VappEmailAcctAdvSettingSignaturePage, this);
            break;
    }
    getMainScr()->pushPage(0, p);
}


/****************** Account Advanced Setting Main Page ******************/
void VappEmailAcctAdvSettingAcctPage::onInit(void)
{
    VfxPage::onInit();

    vapp_email_set_titlebar(STR_EMAIL_ACCT_SETTING_ID, this);

    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(this, &VappEmailAcctAdvSettingAcctPage::onToolBarClick);
    m_toolBar->addItem('SAVE', VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_EMAIL_FTO_SAVE);
    m_toolBar->addItem('CNCL', VFX_WSTR_RES(STR_GLOBAL_CANCEL), IMG_EMAIL_FTO_CANCEL);
    setBottomBar(m_toolBar);

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setRect(0, 0, getSize().width, getSize().height);
    form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    const srv_email_acct_info_struct *acct = getMainScr()->getCurrAcct()->getBasicInfo();

    //notification
    VcpFormItemSwitchCell *notification;
    VFX_OBJ_CREATE(notification, VcpFormItemSwitchCell, form);
    notification->setIsTappable(VFX_FALSE);
    notification->setMainText(VFX_WSTR_RES(STR_EMAIL_FTO_NOTIFI_AUTO_UPDATE));
    notification->m_signalSwitchChangeReq.connect(this, &VappEmailAcctAdvSettingAcctPage::onSwitchClick);
    notification->setSwitchStatus(acct->notify_option == SRV_EMAIL_NOTIFY_ON);

    //protocol
    VcpFormItemLauncherCell *protocol;
    VFX_OBJ_CREATE(protocol, VcpFormItemLauncherCell, form);
    protocol->setMainText(VFX_WSTR_RES(STR_EMAIL_PROTOCOL_ID));
    protocol->setIsDisabled(VFX_TRUE);
    protocol->setHintText(
        acct->protocol == SRV_EMAIL_PROT_IMAP4 ?
            VFX_WSTR_RES(STR_EMAIL_IMAP4_ID) : VFX_WSTR_RES(STR_EMAIL_POP3_ID));

    VFX_OBJ_CREATE(funcBar, VcpFunctionBar, this);
    funcBar->addItem(FUNCBAR_PREV, VFX_WSTR_RES(STR_EMAIL_FTO_PREV));
    funcBar->addItem(FUNCBAR_NEXT, VFX_WSTR_RES(STR_EMAIL_FTO_NEXT));
    funcBar->addItem(FUNCBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    funcBar->setItemSpecial(FUNCBAR_SAVE);
    funcBar->m_signalButtonTap.connect(this, &VappEmailAcctAdvSettingAcctPage::onFuncBarClick);

    //rerrive amount(mails)
    VfxWString text;
    VfxU32 retriveAmountTextMaxLen = 0;
    for (VfxU32 tempU32 = 1;
         tempU32 <= SRV_EMAIL_GLOBAL_MAX_MSG_NUM;
         ++retriveAmountTextMaxLen)
    {
        tempU32 *= 10;
    }    
    retriveAmount = vapp_email_create_text_input_form_item(
                        VFX_WSTR_RES(STR_EMAIL_FTO_RETRIEVE_AMOUNT_MAILS),
                        (VfxWChar*)text.format("%d", acct->retrieve_amount).getBuf(),
                        retriveAmountTextMaxLen,
                        IMM_INPUT_TYPE_NUMERIC, 
                        IME_SETTING_FLAG_NONE,
                        VFX_TRUE,
                        funcBar,
                        form);
    retriveAmount->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctAdvSettingAcctPage::onTextActivated);
    
    //download size
    text.format("%d", MMI_EMAIL_MAX_MSG_SIZE / 1024);
    U32 maxMsgSizeLen = text.getLength();
    downloadSize = vapp_email_create_text_input_form_item(
                        VFX_WSTR_RES(STR_EMAIL_FTO_DOWNLOAD_SIZE_KB),
                        (VfxWChar*)text.format("%d", acct->download_size / 1024).getBuf(),
                        maxMsgSizeLen,
                        IMM_INPUT_TYPE_NUMERIC, 
                        IME_SETTING_FLAG_NONE,
                        VFX_TRUE,
                        funcBar,
                        form);
    downloadSize->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctAdvSettingAcctPage::onTextActivated);

    //reply to
    replyTo = vapp_email_create_text_input_form_item(
                    VFX_WSTR_RES(STR_EMAIL_FTO_REPLY_TO_ADDR),
                    ((VfxWChar*)&acct->reply_to_addr.email_addr),
                    MMI_EMAIL_MAX_ADDR_LEN,
                    IMM_INPUT_TYPE_EMAIL, 
                    IME_SETTING_FLAG_NONE,
                    VFX_TRUE,
                    funcBar,
                    form);
    replyTo->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctAdvSettingAcctPage::onTextActivated);

    form->addItem(notification, FORM_ITEM_NOTIFICATION);
    form->addItem(protocol, FORM_ITEM_PROTOCOL);
    form->addItem(retriveAmount, FORM_ITEM_RETRIVE_AMOUNT);
    form->addItem(downloadSize, FORM_ITEM_DOWNLOAD_SIZE);
    form->addItem(replyTo, FORM_ITEM_REPLY_TO);
}

void VappEmailAcctAdvSettingAcctPage::onFuncBarClick(VfxObject*, VfxId id)
{
    switch (id)
    {
        case FUNCBAR_PREV:
            prevEditor->activate();
            break;
        case FUNCBAR_NEXT:
            nextEditor->activate();
            break;
        case FUNCBAR_SAVE:
            currEditor->deactivate(VFX_TRUE);
            onToolBarClick(NULL, 'SAVE');
            break;
    }
}

void VappEmailAcctAdvSettingAcctPage::onTextActivated(
    VcpTextEditor *sender, VfxBool activated)
{
    if (activated)
    {
        currEditor = sender;
        if (sender == retriveAmount->getTextBox())
        {
            prevEditor = NULL;
            nextEditor = downloadSize->getTextBox();
        }
        else if (sender == downloadSize->getTextBox())
        {
            prevEditor = retriveAmount->getTextBox();
            nextEditor = replyTo->getTextBox();
        }
        else if (sender == replyTo->getTextBox())
        {
            prevEditor = downloadSize->getTextBox();
            nextEditor = NULL;
        }
        funcBar->setDisableItem(FUNCBAR_PREV, prevEditor == NULL);
        funcBar->setDisableItem(FUNCBAR_NEXT, nextEditor == NULL);
    }
}

void VappEmailAcctAdvSettingAcctPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case 'SAVE':
        {
            VfxBool encounterError = VFX_FALSE;

            VfxU32 tmpRetrieveAmount = mmi_wcs_wtoi(
                (WCHAR*)retriveAmount->getText().getBuf());
            if ((tmpRetrieveAmount < 1) ||
                (tmpRetrieveAmount > SRV_EMAIL_GLOBAL_MAX_MSG_NUM))
            {
                encounterError = VFX_TRUE;
                retriveAmount->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_INVALID_RETRIEVE_AMOUNT));
            }
            else
            {
                retriveAmount->setWarningText(VFX_WSTR_EMPTY);
            }

            if (replyTo->getText().getLength() != 0 &&
                !vapp_email_util_chk_addr(replyTo->getText().getBuf()))
            {
                encounterError = VFX_TRUE;
                replyTo->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_INVALID_EMAIL_ADDR));
            }
            else
            {
                replyTo->setWarningText(VFX_WSTR_EMPTY);
            }

            VfxU32 getDlSize = 1024 *
                        mmi_wcs_wtoi((WCHAR*)downloadSize->getText().getBuf());
            if ((getDlSize < MMI_EMAIL_MIN_MSG_SIZE) ||
                (getDlSize > MMI_EMAIL_MAX_MSG_SIZE))
            {
                encounterError = VFX_TRUE;
                downloadSize->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_INVALID_DOWNLOAD_SIZE));
            }
            else
            {
                downloadSize->setWarningText(VFX_WSTR_EMPTY);
            }

            if (encounterError)
            {
                return;
            }

            getMainScr()->getCurrAcct()->setReplyTo(replyTo->getText());
            getMainScr()->getCurrAcct()->setRetrieveAmount(tmpRetrieveAmount);
            getMainScr()->getCurrAcct()->setDownloadSize(getDlSize);

            srv_email_result_enum res =
                getMainScr()->getCurrAcct()->saveAcctInfo();
            VEMAIL_TRC_SAVE_ACCT(res);

            getMainScr()->popPage();
            break;
        }
        case 'CNCL':
        {
            getMainScr()->popPage();
            break;
        }
    }
}

void VappEmailAcctAdvSettingAcctPage::onSwitchClick(
    VcpFormItemSwitchCell* cell, VfxId id, VfxBool switch_on)
{
    switch (id)
    {
        case FORM_ITEM_NOTIFICATION:
        {
            getMainScr()->getCurrAcct()->setNotifyOpt(switch_on);
            cell->setSwitchStatus(switch_on);

            getMainScr()->getCurrAcct()->setNotifyOpt(switch_on);

            srv_email_result_enum res =
                getMainScr()->getCurrAcct()->saveAcctInfo();
            VEMAIL_TRC_SAVE_ACCT(res);

            break;
        }
    }
}

/****************** Account Advanced Setting Main Page ******************/
void VappEmailAcctAdvSettingServerPage::onInit(void)
{
    VfxPage::onInit();

    vapp_email_set_titlebar(m_serverType == EMAIL_OUTGOING_SERVER ? 
                                STR_EMAIL_OUTGOING_SERVER_ID : STR_EMAIL_FTO_INCOMING_SERVER, this);

    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappEmailAcctAdvSettingServerPage::onToolBarClick);
    m_toolBar->addItem(
        'SAVE', VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_EMAIL_FTO_SAVE);
    m_toolBar->addItem(
        'CNCL', VFX_WSTR_RES(STR_GLOBAL_CANCEL), IMG_EMAIL_FTO_CANCEL);
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
    funcBar->addItem(FUNCBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    funcBar->setItemSpecial(FUNCBAR_SAVE);
    funcBar->m_signalButtonTap.connect(this, &VappEmailAcctAdvSettingServerPage::onFuncBarClick);

    const srv_email_acct_info_struct *acct = getMainScr()->getCurrAcct()->getBasicInfo();
    const srv_email_server_struct *server = 
        (m_serverType == EMAIL_OUTGOING_SERVER) ? &acct->out_server : &acct->in_server;

    //server
    m_server = vapp_email_create_text_input_form_item(
                VFX_WSTR_RES(m_serverType == EMAIL_OUTGOING_SERVER ? 
                    STR_EMAIL_OUTGOING_SERVER_ID : STR_EMAIL_FTO_INCOMING_SERVER),
                ((VfxWChar*)server->server_name),
                SRV_EMAIL_MAX_SERVER_NAME_LEN,
                IMM_INPUT_TYPE_EMAIL, 
                IME_SETTING_FLAG_NONE,
                VFX_TRUE,
                funcBar,
                form);
    m_server->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctAdvSettingServerPage::onTextActivated);


    //port
    VfxWString text;
    m_port = vapp_email_create_text_input_form_item(
                VFX_WSTR_RES(m_serverType == EMAIL_OUTGOING_SERVER ? STR_EMAIL_FTO_OUTGOING_PORT : STR_EMAIL_FTO_INCOMING_PORT),
                (VfxWChar*)text.format("%d", server->sec_mode == SRV_EMAIL_SEC_SSL_TLS ? server->sec_port_num : server->port_num).getBuf(),
                5,
                IMM_INPUT_TYPE_NUMERIC, 
                IME_SETTING_FLAG_NONE,
                VFX_TRUE,
                funcBar,
                form);
    m_port->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctAdvSettingServerPage::onTextActivated);
    
    //security
    VFX_OBJ_CREATE(m_security, VcpFormItemLauncherCell, form);
    m_security->setMainText(VFX_WSTR_RES(STR_EMAIL_SECURITY_ID));
    m_security->setAccessory(VCPFORM_NEXT_ITEM_ICON);
#ifdef __SSL_SUPPORT__
    m_security->m_signalTap.connect(
    this, &VappEmailAcctAdvSettingServerPage::onFormCellClick);
#else
    m_security->setIsDisabled(VFX_TRUE);
#endif

    form->addItem(m_server, FORM_ITEM_SERVER);
    form->addItem(m_port, FORM_ITEM_PORT);
    form->addItem(m_security, FORM_ITEM_SERCURITY);

    if (m_serverType == EMAIL_OUTGOING_SERVER)
    {
        /* outgoing server */
        VcpFormItemLauncherCell *authentication;
        VFX_OBJ_CREATE(authentication, VcpFormItemLauncherCell, form);
        authentication->setMainText(VFX_WSTR_RES(STR_GLOBAL_AUTHENTICATION));
        authentication->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        authentication->m_signalTap.connect(
            this, &VappEmailAcctAdvSettingServerPage::onFormCellClick);

        form->addItem(authentication, FORM_ITEM_AUTHENTICATION);
    }
    else
    {
        /* incoming server */
        if (acct->protocol == SRV_EMAIL_PROT_POP3)
        {
            VcpFormItemSwitchCell *apop;
            VFX_OBJ_CREATE(apop, VcpFormItemSwitchCell, form);
            apop->setIsTappable(VFX_FALSE);
            apop->setMainText(VFX_WSTR_RES(STR_EMAIL_FTO_APOP_SECURE_LOGIN));
            apop->setSwitchStatus(acct->in_auth.auth_type == SRV_EMAIL_AUTH_APOP);
            apop->m_signalSwitchChangeReq.connect(
                this, &VappEmailAcctAdvSettingServerPage::onSwitchClick);
            form->addItem(apop, FORM_ITEM_APOP_SEC);
        }

#ifdef __MMI_EMAIL_REMOTE_FOLDER__
        if (acct->protocol == SRV_EMAIL_PROT_IMAP4)
        {
            VcpFormItemLauncherCell *remote_fldr;
            VFX_OBJ_CREATE(remote_fldr, VcpFormItemLauncherCell, form);
            remote_fldr->setMainText(VFX_WSTR_RES(STR_EMAIL_FTO_REMOTE_FOLDER));
            remote_fldr->setAccessory(VCPFORM_NEXT_ITEM_ICON);
            remote_fldr->m_signalTap.connect(
                this, &VappEmailAcctAdvSettingServerPage::onFormCellClick);

            VappEmailStateEnum emailState =
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();
            if (emailState == VAPP_EMAIL_STATE_NO_SIM)
            {
                remote_fldr->setIsDisabled(VFX_TRUE);
            }
            form->addItem(remote_fldr, FORM_ITEM_REMOTE_FLDR);
        }
#endif
    }

#ifdef __MMI_SSO__
    if (vapp_email_is_cloud_acct(acct->acct_id))
    {
        m_server->setIsDisabled(VFX_TRUE);
        m_port->setIsDisabled(VFX_TRUE);
        m_security->setIsDisabled(VFX_TRUE);
    }
#endif /* #ifdef __MMI_SSO__ */   
}

void VappEmailAcctAdvSettingServerPage::onEnter(VfxBool isBackward)
{
    const srv_email_server_struct *server = 
        (m_serverType == EMAIL_OUTGOING_SERVER) ? 
            &(getMainScr()->getCurrAcct()->getBasicInfo()->out_server) : 
            &(getMainScr()->getCurrAcct()->getBasicInfo()->in_server);

#ifdef __SSL_SUPPORT__
    VfxResId item_res[] =
    {
        STR_GLOBAL_OFF,
        STR_EMAIL_USING_SSL_ID,
        STR_EMAIL_USING_TLS_ID
    };
    m_security->setHintText(VFX_WSTR_RES(item_res[(VfxU32)server->sec_mode]));
#else
    m_security->setHintText(VFX_WSTR_RES(STR_GLOBAL_OFF));
#endif
}

void VappEmailAcctAdvSettingServerPage::onFormCellClick(
    VcpFormItemCell *obj, VfxId id)
{
    switch (id)
    {
        case FORM_ITEM_SERCURITY:
        {
            VfxResId item_res[] = {
                STR_GLOBAL_OFF,
#ifdef __SSL_SUPPORT__
                STR_EMAIL_USING_SSL_ID,
                STR_EMAIL_USING_TLS_ID,
#endif
                };
            VFX_OBJ_CREATE_EX(
                m_secModePage,
                VappEmailListSingleSelectTmplPage,
                this,
                (VFX_FALSE));
            m_secModePage->setListItem(
                sizeof(item_res)/sizeof(VfxResId),
                STR_EMAIL_SECURITY_ID, item_res);

            VfxU32 initSelectedIndex = 0;
#ifdef __SSL_SUPPORT__
            const srv_email_acct_info_struct *acct_info = getMainScr()->getCurrAcct()->getBasicInfo();
            const srv_email_server_struct *server = 
                (m_serverType == EMAIL_OUTGOING_SERVER) ? &acct_info->out_server : &acct_info->in_server;

            srv_email_sec_mode_enum secMode = server->sec_mode;

            if (secMode <= SRV_EMAIL_SEC_STARTTLS)
            {
                initSelectedIndex = (VfxU32)secMode;
            }
#endif
            m_secModePage->setInitSelectItem(initSelectedIndex);

            m_secModePage->m_signal_save.connect(
                this,
                &VappEmailAcctAdvSettingServerPage::onSingleSelectSave);
            getMainScr()->pushPage(0, m_secModePage);
            break;
        }
        
        case FORM_ITEM_AUTHENTICATION:
        {
            VappEmailAcctAdvSettingOutAuthPage *auth;
            VFX_OBJ_CREATE(auth, VappEmailAcctAdvSettingOutAuthPage, this);
            getMainScr()->pushPage(0, auth);
            break;
        }
        
        case FORM_ITEM_REMOTE_FLDR:
        {
            VappEmailStateEnum emailState =
                VFX_OBJ_GET_INSTANCE(VappEmailMgr)->getEmailAppState();
            if (emailState == VAPP_EMAIL_STATE_FLIGHT_MODE)
            {
                vapp_email_util_nmgr_balloon(
                    STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE);
                return;
            }
            VappEmailAcctAdvSettingRmtFldrPage *fmtFldrPage;
            VFX_OBJ_CREATE(
                fmtFldrPage, VappEmailAcctAdvSettingRmtFldrPage, this);
            getMainScr()->pushPage(0, fmtFldrPage);
            break;
        }
    }
}

void VappEmailAcctAdvSettingServerPage::onSingleSelectSave(
    VfxObject *obj, VfxS32 select_index)
{
    if ((VfxObject*)m_secModePage == obj)
    {
        VappEmailAcct *acct = getMainScr()->getCurrAcct();

        srv_email_sec_mode_enum secMode = (srv_email_sec_mode_enum)select_index;
        acct->setSecMode(
                secMode, 
                m_serverType == EMAIL_OUTGOING_SERVER ? VappEmailAcct::OUTGOING : VappEmailAcct::INCOMING);

        srv_email_result_enum res = acct->saveAcctInfo();
        VEMAIL_TRC_SAVE_ACCT(res);

        const srv_email_acct_info_struct *acct_info = getMainScr()->getCurrAcct()->getBasicInfo();
        const srv_email_server_struct *server = 
                (m_serverType == EMAIL_OUTGOING_SERVER) ? &acct_info->out_server : &acct_info->in_server;
        VfxWString text;
        m_port->getTextBox()->setText(
            text.format(
            "%d",
            secMode == SRV_EMAIL_SEC_SSL_TLS ?
                server->sec_port_num :
                server->port_num),
            5);
    }

    getMainScr()->popPage();
}


void VappEmailAcctAdvSettingServerPage::onSwitchClick(
    VcpFormItemSwitchCell* cell, VfxId id, VfxBool switch_on)
{
    switch (id)
    {
        case FORM_ITEM_APOP_SEC:
        {
            VappEmailAcct *acct = getMainScr()->getCurrAcct();
            cell->setSwitchStatus(switch_on);

            acct->setAuthType(
                switch_on ? SRV_EMAIL_AUTH_APOP : SRV_EMAIL_AUTH_USER,
                VappEmailAcct::INCOMING);

            srv_email_result_enum res = acct->saveAcctInfo();
            VEMAIL_TRC_SAVE_ACCT(res);
            break;
        }
    }
}


void VappEmailAcctAdvSettingServerPage::onFuncBarClick(VfxObject*, VfxId id)
{
    switch (id)
    {
        case FUNCBAR_PREV:
            m_prevEditor->activate();
            break;
        case FUNCBAR_NEXT:
            m_nextEditor->activate();
            break;
        case FUNCBAR_SAVE:
            m_currEditor->deactivate();
            onToolBarClick(NULL, 'SAVE');
            break;
    }
}

void VappEmailAcctAdvSettingServerPage::onTextActivated(
    VcpTextEditor *sender, VfxBool activated)
{
    if (activated)
    {
        m_currEditor = sender;

        if (sender == m_server->getTextBox())
        {
            m_prevEditor = NULL;
            m_nextEditor = m_port->getTextBox();
        }
        else if (sender == m_port->getTextBox())
        {
            m_prevEditor = m_server->getTextBox();
            m_nextEditor = NULL;
        }
        funcBar->setDisableItem(FUNCBAR_PREV, m_prevEditor == NULL);
        funcBar->setDisableItem(FUNCBAR_NEXT, m_nextEditor == NULL);
    }
}

void VappEmailAcctAdvSettingServerPage::onToolBarClick(
    VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case 'SAVE':
        {
            VfxBool encounterError = VFX_FALSE;
            VfxBool is_cloud = VFX_FALSE;
#ifdef __MMI_SSO__
            is_cloud = vapp_email_is_cloud_acct(getMainScr()->getCurrAcct()->getBasicInfo()->acct_id);
#endif

            if (!vapp_email_util_is_server_vaild(m_server->getText().getBuf()) && !is_cloud)
            {
                encounterError = VFX_TRUE;
                m_server->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_INVLAID_SERVER_ADDR));
            }
            else
            {
                m_server->setWarningText(VFX_WSTR_EMPTY);
            }

            VfxU32 port = mmi_wcs_wtoi(
                                (WCHAR*)m_port->getText().getBuf());
            if (!vapp_email_util_server_port_is_valid(port) && !is_cloud)
            {
                encounterError = VFX_TRUE;
                m_port->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_VALID_PORT_RANGE));
            }
            else
            {
                m_port->setWarningText(VFX_WSTR_EMPTY);
            }

            if (encounterError)
            {
                return;
            }

            VappEmailAcct *acct = getMainScr()->getCurrAcct();

            VappEmailAcct::VappEmailServerType serverType = 
                (m_serverType == EMAIL_OUTGOING_SERVER) ? VappEmailAcct::OUTGOING : VappEmailAcct::INCOMING;
            acct->setServerName(m_server->getText(), serverType);

            const srv_email_acct_info_struct *acct_info = getMainScr()->getCurrAcct()->getBasicInfo();
            const srv_email_server_struct *server = 
                    (m_serverType == EMAIL_OUTGOING_SERVER) ? &acct_info->out_server : &acct_info->in_server;

            if (server->sec_mode ==
                SRV_EMAIL_SEC_SSL_TLS)
            {
                acct->setSecPort(port, serverType);
            }
            else
            {
                acct->setPort(port, serverType);
            }

            srv_email_result_enum res = acct->saveAcctInfo();
            VEMAIL_TRC_SAVE_ACCT(res);
            break;
        }
        case 'CNCL':
        {
            break;
        }
    }

    getMainScr()->popPage();
}

/**************** Account Advanced Setting Authentication Page ****************/
void VappEmailAcctAdvSettingOutAuthPage::onInit(void)
{
    VfxPage::onInit();

    vapp_email_set_titlebar(STR_GLOBAL_AUTHENTICATION, this);

    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(this, &VappEmailAcctAdvSettingOutAuthPage::onToolBarClick);
    m_toolBar->addItem('SAVE', VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_EMAIL_FTO_SAVE);
    m_toolBar->addItem('CNCL', VFX_WSTR_RES(STR_GLOBAL_CANCEL), IMG_EMAIL_FTO_CANCEL);
    setBottomBar(m_toolBar);

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setRect(0, 0, getSize().width, getSize().height);
    form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    const srv_email_acct_info_struct *acct = getMainScr()->getCurrAcct()->getBasicInfo();

    VFX_OBJ_CREATE(auth_switch, VcpFormItemSwitchCell, form);
    auth_switch->setIsTappable(VFX_FALSE);
    auth_switch->setMainText(VFX_WSTR_RES(STR_GLOBAL_AUTHENTICATION));
    auth_switch->setSwitchStatus(acct->out_auth.auth_type != SRV_EMAIL_AUTH_NONE);
    auth_switch->m_signalSwitchChangeReq.connect(
        this, &VappEmailAcctAdvSettingOutAuthPage::onSwitchClick);

    VFX_OBJ_CREATE(funcBar, VcpFunctionBar, this);
    funcBar->addItem(FUNCBAR_PREV, VFX_WSTR_RES(STR_EMAIL_FTO_PREV));
    funcBar->addItem(FUNCBAR_NEXT, VFX_WSTR_RES(STR_EMAIL_FTO_NEXT));
    funcBar->addItem(FUNCBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    funcBar->setItemSpecial(FUNCBAR_SAVE);
    funcBar->m_signalButtonTap.connect(this, &VappEmailAcctAdvSettingOutAuthPage::onFuncBarClick);

    //username
    username = vapp_email_create_text_input_form_item(
                    VFX_WSTR_RES(STR_GLOBAL_USERNAME),
                    ((VfxWChar*)acct->out_auth.username),
                    SRV_EMAIL_MAX_USERNAME_LEN,
                    IMM_INPUT_TYPE_EMAIL, 
                    IME_SETTING_FLAG_NONE,
                    VFX_TRUE,
                    funcBar,
                    form);
    username->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctAdvSettingOutAuthPage::onTextActivated);

    //password
    pswd = vapp_email_create_text_input_form_item(
                VFX_WSTR_RES(STR_GLOBAL_PASSWORD),
                ((VfxWChar*)acct->out_auth.password),
                SRV_EMAIL_MAX_PASSWORD_LEN,
                IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD, 
                IME_SETTING_FLAG_NONE,
                VFX_TRUE,
                funcBar,
                form);
    pswd->getTextBox()->m_signalActivated.connect(
        this, &VappEmailAcctAdvSettingOutAuthPage::onTextActivated);

    form->addItem(auth_switch, FORM_ITEM_OUTGOING_AUTH_SWITCH);
    form->addCaption(VFX_WSTR_RES(STR_GLOBAL_AUTHENTICATION), FORM_ITEM_OUTGOING_AUTH_CAP);
    form->addItem(username, FORM_ITEM_OUTGOING_USERNAME);
    form->addItem(pswd, FORM_ITEM_OUTGOING_PSWD);
}

void VappEmailAcctAdvSettingOutAuthPage::onSwitchClick(
    VcpFormItemSwitchCell* cell, VfxId id, VfxBool switch_on)
{
    VappEmailAcct *acct = getMainScr()->getCurrAcct();

    switch (id)
    {
        case FORM_ITEM_OUTGOING_AUTH_SWITCH:
            cell->setSwitchStatus(switch_on);

            acct->setAuthType(
                switch_on ? SRV_EMAIL_AUTH_USER : SRV_EMAIL_AUTH_NONE,
                VappEmailAcct::OUTGOING);

            srv_email_result_enum res = acct->saveAcctInfo();
            VEMAIL_TRC_SAVE_ACCT(res);
            break;
    }
}

void VappEmailAcctAdvSettingOutAuthPage::onFuncBarClick(VfxObject*, VfxId id)
{
    switch (id)
    {
        case FUNCBAR_PREV:
            prevEditor->activate();
            break;
        case FUNCBAR_NEXT:
            nextEditor->activate();
            break;
        case FUNCBAR_SAVE:
            currEditor->deactivate();
            onToolBarClick(NULL, 'SAVE');
            break;
    }
}

void VappEmailAcctAdvSettingOutAuthPage::onTextActivated(
    VcpTextEditor *sender, VfxBool activated)
{
    if (activated)
    {
        currEditor = sender;

        if (sender == username->getTextBox())
        {
            prevEditor = NULL;
            nextEditor = pswd->getTextBox();
        }
        else if (sender == pswd->getTextBox())
        {
            prevEditor = username->getTextBox();
            nextEditor = NULL;
        }
        funcBar->setDisableItem(FUNCBAR_PREV, prevEditor == NULL);
        funcBar->setDisableItem(FUNCBAR_NEXT, nextEditor == NULL);
    }
}

void VappEmailAcctAdvSettingOutAuthPage::onToolBarClick(
    VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case 'SAVE':
        {
            VfxBool encounterError = VFX_FALSE;

            if (username->getText().getLength() == 0)
            {
                encounterError = VFX_TRUE;
                username->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_USER_NAME));
            }
            else
            {
                username->setWarningText(VFX_WSTR_EMPTY);
            }

            if (pswd->getText().getLength() == 0)
            {
                encounterError = VFX_TRUE;
                pswd->setWarningText(
                    VFX_WSTR_RES(STR_EMAIL_FTO_PLEASE_INPUT_PSWD));
            }
            else
            {
                pswd->setWarningText(VFX_WSTR_EMPTY);
            }

            if (encounterError)
            {
                return;
            }
            VappEmailAcct *acct = getMainScr()->getCurrAcct();

            acct->setAuthType(
                auth_switch->getSwitchStatus() ?
                    SRV_EMAIL_AUTH_USER : SRV_EMAIL_AUTH_NONE,
                VappEmailAcct::OUTGOING);
            acct->setUsername(username->getText(), VappEmailAcct::OUTGOING);
            acct->setPassword(pswd->getText(), VappEmailAcct::OUTGOING);

            srv_email_result_enum res = acct->saveAcctInfo();
            VEMAIL_TRC_SAVE_ACCT(res);
            break;
        }
        case 'CNCL':
        {
            break;
        }
    }

    getMainScr()->popPage();
}


/****************** Account Advanced Setting Signature Page ******************/
VappEmailAcctAdvSettingSignaturePage::VappEmailAcctAdvSettingSignaturePage()
    : sig_img(NULL),
      pathChanged(VFX_FALSE)
{
}

void VappEmailAcctAdvSettingSignaturePage::onInit(void)
{
    VfxPage::onInit();

    vapp_email_set_titlebar(STR_EMAIL_SIGNATURE_ID, this);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappEmailAcctAdvSettingSignaturePage::onToolBarClick);
    m_toolBar->addItem(
        'SAVE', VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_EMAIL_FTO_SAVE);
    m_toolBar->addItem(
        'INST', VFX_WSTR_RES(STR_EMAIL_FTO_INSERT), IMG_EMAIL_FTO_INSERT);
    m_toolBar->addItem(
        'CNCL', VFX_WSTR_RES(STR_GLOBAL_CANCEL), IMG_EMAIL_FTO_CANCEL);
    setBottomBar(m_toolBar);

    VappEmailAcct *acct = getMainScr()->getCurrAcct();

    MMI_BOOL status = MMI_FALSE;
    mmi_email_sig_get_status(acct->getBasicInfo()->acct_id, &status);

    memset(&m_signature, 0, sizeof(mmi_email_sig_struct));

    mmi_email_sig_get_signature(
        acct->getBasicInfo()->acct_id, &m_signature);

    sigFilePath[0] = 0;
    if (m_signature.image_num > 0)
    {
        mmi_email_sig_get_image_path(
            acct->getBasicInfo()->acct_id,
            0,
            sigFilePath,
            SRV_FMGR_PATH_MAX_LEN + 1);
    }

    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setPos(0, 0);
    form->setBounds(VfxRect(0, 0, getRect().size.width, getRect().size.height));

    VFX_OBJ_CREATE(autoSig, VcpFormItemSwitchCell, form);
    autoSig->setIsTappable(VFX_FALSE);
    autoSig->setMainText(VFX_WSTR_RES(STR_EMAIL_SIGNATURE_ON_OFF_ID));
    autoSig->setSwitchStatus(status == MMI_TRUE);
    autoSig->m_signalSwitchChangeReq.connect(
        this, &VappEmailAcctAdvSettingSignaturePage::onSwitchCellClick);

    /**************** signature text START *******************/
    VcpFormItemCustomFrame *sig_text;
    VFX_OBJ_CREATE(sig_text, VcpFormItemCustomFrame, form);

    VfxFrame *customframe;
    VFX_OBJ_CREATE(customframe, VfxFrame, form);
    customframe->setSize(
        getRect().size.width,
        VCPFRM_ITEM_HORZ_GAP +
            VcpFormItemCell::MAIN_FONT_SIZE * 4 +
            VcpFormItemCell::TOP_MARGIN +
            VcpFormItemCell::BOTTOM_MARGIN);
    customframe->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT,
                                VFX_FRAME_ALIGNER_MODE_SIDE);
    customframe->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT,
                                VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(sigTextTextEditor, VcpTextEditor, customframe);
    sigTextTextEditor->setText(
        (VfxWChar*)&m_signature.text, MMI_EMAIL_SIG_MAX_TEXT_LEN);
    sigTextTextEditor->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    sigTextTextEditor->setPos(
        VCPFRM_LEFT_INDENT_L1 + VCPFRM_LEFT_INDENT_L2, VCPFRM_ITEM_HORZ_GAP);
    sigTextTextEditor->setSize(
        getRect().size.width - (VCPFRM_LEFT_INDENT_L1+VCPFRM_LEFT_INDENT_L2)*2,
        customframe->getRect().getHeight() - VCPFRM_ITEM_HORZ_GAP);
    sigTextTextEditor->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT,
                                      VFX_FRAME_ALIGNER_MODE_SIDE);
    sigTextTextEditor->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT,
                                      VFX_FRAME_ALIGNER_MODE_SIDE);
    sigTextTextEditor->setAutoDeactivated(VFX_TRUE);
    sig_text->attachCustomFrame(customframe);
    /**************** signature text END *******************/

    VFX_OBJ_CREATE(funcBar, VcpFunctionBar, this);
    funcBar->addItem(FUNCBAR_INSERT, VFX_WSTR_RES(STR_EMAIL_FTO_INSERT));
    funcBar->addItem(FUNCBAR_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    funcBar->setItemSpecial(FUNCBAR_SAVE);
    funcBar->m_signalButtonTap.connect(
        this, &VappEmailAcctAdvSettingSignaturePage::onFuncBarClick);

    sigTextTextEditor->setFunctionBar(funcBar);
    sigTextTextEditor->setAutoDeactivated(VFX_TRUE);
    sigTextTextEditor->m_signalActivated.connect(
        this, &VappEmailAcctAdvSettingSignaturePage::onTextActivated);

    form->addItem(autoSig, FORM_ITEM_SIGNATURE_SWITCH);
    form->addCaption(
            VFX_WSTR_RES(STR_EMAIL_FTO_EDIT_SIG), FORM_ITEM_SIGNATURE_CAP);
    form->addItem(sig_text, FORM_ITEM_SIGNATURE_TEXT);

    insertEnable = VFX_TRUE;
    if (m_signature.image_num > 0)
    {
        insertEnable = VFX_FALSE;
        addSigImgBtn();
        m_toolBar->setDisableItem('INST', VFX_TRUE);
    }

    form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VappEmailMgr::getInstance()->m_signalTcardPlug.connect(
        this, &VappEmailAcctAdvSettingSignaturePage::onTcardPlug);
}

void VappEmailAcctAdvSettingSignaturePage::onQueryRotateEx(VfxScreenRotateParam & param)
{
    if (sig_img != NULL)
    {
        VfxU32 lcdWith;
        if (param.rotateTo == VFX_SCR_ROTATE_TYPE_NORMAL ||
            param.rotateTo == VFX_SCR_ROTATE_TYPE_180)
        {
            lcdWith = LCD_WIDTH;
        }
        else
        {
            lcdWith = LCD_HEIGHT;
        }
       
        removeBtn->setPos(lcdWith - (VCPFRM_STANDARD_BTN_HEIGHT +
                                     VCPFRM_LEFT_INDENT_L1 +
                                     VCPFRM_LEFT_INDENT_L2),
                          VCPFRM_ITEM_HORZ_GAP);

        sigImgBtn->setSize(lcdWith - VCPFRM_SIDE_MARGIN_LARGE
                                   - sigImgBtn->getRect().getMinX()
                                   - VCPFRM_STANDARD_BTN_HEIGHT,
                           VCPFRM_STANDARD_BTN_HEIGHT);
    }
}

void VappEmailAcctAdvSettingSignaturePage::onTcardPlug(VfxBool in)
{
    if (!in &&                          // it's plug-out memory card
        srv_email_get_drive() ==        // current storage is Phone
            srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE) &&
        sigFilePath[0] != L'0' &&       // signature path is validity
        sigFilePath[0] != srv_email_get_drive()  // selected sig is NOT in phone
        )
    {
        onBtnClick(NULL, 'DELE');
    }
}

void VappEmailAcctAdvSettingSignaturePage::addSigImgBtn(void)
{
    VFX_OBJ_CREATE(sig_img, VcpFormItemCustomFrame, form);

    VFX_OBJ_CREATE(removeBtn, VcpCancelButton, sig_img);
    removeBtn->setSize(VCPFRM_STANDARD_BTN_HEIGHT, VCPFRM_STANDARD_BTN_HEIGHT);
    removeBtn->setPos(
                getSize().width - (removeBtn->getSize().width +
                        VCPFRM_LEFT_INDENT_L1 + VCPFRM_LEFT_INDENT_L2),
                VCPFRM_ITEM_HORZ_GAP);
    removeBtn->m_signalClicked.connect(
        this, &VappEmailAcctAdvSettingSignaturePage::onBtnClick);
    removeBtn->setId('DELE');

    VFX_OBJ_CREATE(sigImgBtn, VcpButton, sig_img);
    sigImgBtn->setPos(
        VCPFRM_LEFT_INDENT_L1 + VCPFRM_LEFT_INDENT_L2, VCPFRM_ITEM_HORZ_GAP);
    sigImgBtn->setSize(getRect().size.width - VCPFRM_SIDE_MARGIN_LARGE
        - sigImgBtn->getRect().getMinX() - removeBtn->getRect().getWidth(),
        VCPFRM_STANDARD_BTN_HEIGHT);
    sigImgBtn->m_signalClicked.connect(
        this, &VappEmailAcctAdvSettingSignaturePage::onBtnClick);

    if (!pathChanged)
    {
        sigImgBtn->setText(VFX_WSTR_MEM((WCHAR*)m_signature.image_name[0]));
    }
    else
    {
        VfxWChar *nameTmp = srv_fmgr_path_get_filename_ptr(sigFilePath);
        if (nameTmp != NULL)
            sigImgBtn->setText(VFX_WSTR_MEM(nameTmp));
    }
    sigImgBtn->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
    sigImgBtn->setId('VIEW');

    sig_img->attachCustomFrame(sigImgBtn);
    sig_img->attachCustomFrame(removeBtn);
    sig_img->setHeight(sigImgBtn->getSize().height + (VCPFRM_ITEM_HORZ_GAP<<1));
    sig_img->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT,
                                VFX_FRAME_ALIGNER_MODE_SIDE);
    sig_img->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT,
                                VFX_FRAME_ALIGNER_MODE_SIDE);

    form->addItem(sig_img, FORM_ITEM_SIGNATURE_IMG);
}

void VappEmailAcctAdvSettingSignaturePage::onBtnClick(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case 'VIEW':
        {
            imgViewCuiId = vcui_gallery_image_viewer_create(
                            getApp()->getGroupId(), sigFilePath);

            if (imgViewCuiId != GRP_ID_INVALID)
            {
                vcui_gallery_set_title_str_ptr(imgViewCuiId, sigImgBtn->getText());
                vfxSetCuiCallerScr(imgViewCuiId, getMainScr());
                vcui_gallery_run(imgViewCuiId);
            }
            break;
        }
        case 'DELE':
        {
            sigTextTextEditor->deactivate();

            sigFilePath[0] = 0;
            pathChanged = VFX_TRUE;
            insertEnable = VFX_TRUE;
            m_toolBar->setDisableItem('INST', VFX_FALSE);
            form->removeItem(FORM_ITEM_SIGNATURE_IMG);
            sig_img = NULL;
            break;
        }
    }
}

void VappEmailAcctAdvSettingSignaturePage::onFuncBarClick(VfxObject*, VfxId id)
{
    sigTextTextEditor->deactivate();

    switch (id)
    {
        case FUNCBAR_INSERT:
        {
            FMGR_FILTER filter;
            U32 option_flag = VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON |
                              VCUI_FILE_SELECTOR_OPT_ARCHIVE_AS_UNKNOWN |
                              VCUI_FILE_SELECTOR_OPT_FIXED_PATH_ON;

            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET_IMAGE(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

            fsCuiId = vcui_file_selector_create(
                        getMainScr()->getGroupId(),
                        VFX_WSTR("root"),
                        &filter,
                        VCUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                        option_flag);
            if (fsCuiId != GRP_ID_INVALID)
            {
                vfxSetCuiCallerScr(fsCuiId, getMainScr());
                vcui_file_selector_run(fsCuiId);
            }
            break;
        }
        case FUNCBAR_SAVE:
            onToolBarClick(NULL, 'SAVE');
            break;
    }
}

void VappEmailAcctAdvSettingSignaturePage::onTextActivated(
    VcpTextEditor *sender, VfxBool activated)
{
    if (activated)
    {
        funcBar->setDisableItem(FUNCBAR_INSERT, !insertEnable);
    }
}

void VappEmailAcctAdvSettingSignaturePage::onToolBarClick(
    VfxObject *obj, VfxId id)
{
    const srv_email_acct_info_struct *acctInfo =
            getMainScr()->getCurrAcct()->getBasicInfo();

    switch (id)
    {
        case 'INST':
        {
            FMGR_FILTER filter;
            U32 option_flag = VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON |
                              VCUI_FILE_SELECTOR_OPT_ARCHIVE_AS_UNKNOWN |
                              VCUI_FILE_SELECTOR_OPT_FIXED_PATH_ON;

            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET_IMAGE(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

            fsCuiId = vcui_file_selector_create(
                        getMainScr()->getGroupId(),
                        VFX_WSTR("root"),
                        &filter,
                        VCUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                        option_flag);
            if (fsCuiId != GRP_ID_INVALID)
            {
                vfxSetCuiCallerScr(fsCuiId, getMainScr());
                vcui_file_selector_run(fsCuiId);
            }
            return;
        }
        case 'SAVE':
        {
            MMI_BOOL auto_sig_status =
                autoSig->getSwitchStatus() ? MMI_TRUE : MMI_FALSE;

            if (auto_sig_status != m_signature.validity)
            {
                mmi_email_sig_set_status(
                    acctInfo->acct_id,
                    auto_sig_status);
            }

            mmi_email_sig_set_text(
                acctInfo->acct_id, sigTextTextEditor->getText(),
                (MMI_EMAIL_SIG_MAX_TEXT_LEN + 1));

            if (m_signature.image_num != 0)
            {
                if (mmi_wcslen(sigFilePath) == 0)
                {
                    mmi_email_sig_delete_image(acctInfo->acct_id, 0);
                    goto POP_PAGE;
                }

                if (!pathChanged)
                {
                    goto POP_PAGE;
                }

                mmi_email_sig_edit_image(
                    acctInfo->acct_id,
                    0,
                    sigFilePath,
                    VappEmailAcctAdvSettingSignaturePage::signatureEditDone,
                    getObjHandle());
                goto SHOW_LOADING;
            }
            else if (mmi_wcslen(sigFilePath) != 0)
            {
                S32 ret = mmi_email_sig_add_image(
                    acctInfo->acct_id,
                    sigFilePath,
                    VappEmailAcctAdvSettingSignaturePage::signatureEditDone,
                    getObjHandle());
                if (ret == MMI_EMAIL_WOULDBLOCK)
                {
                goto SHOW_LOADING;
            }
                else
                {
                    goto POP_PAGE;
                }
            }
            break;
        }
        case 'CNCL':
            break;
    }

POP_PAGE:
    getMainScr()->popPage();
    return;

SHOW_LOADING:
    {
        vapp_email_indicator_pop(&indicator_pop, STR_GLOBAL_SAVING, this);
    }
}

void VappEmailAcctAdvSettingSignaturePage::onSwitchCellClick(
    VcpFormItemSwitchCell *cell, VfxId id, VfxBool switch_on)
{
    switch (id)
    {
        case FORM_ITEM_SIGNATURE_SWITCH:
        {
            m_signature.validity = switch_on ? MMI_TRUE : MMI_FALSE;

            mmi_email_app_core_result_enum res;
            res = mmi_email_sig_set_status(
                getMainScr()->getCurrAcct()->getBasicInfo()->acct_id,
                switch_on ? MMI_TRUE : MMI_FALSE);

            if (res == MMI_EMAIL_SUCCESS)
            {
                cell->setSwitchStatus(switch_on);
            }
            else
            {
                vapp_email_alert_cfm(STR_GLOBAL_ERROR);
            }
            break;
        }
    }
}

void VappEmailAcctAdvSettingSignaturePage::signatureEditDone(
    VfxS32 editRes, void *userData)
{
    VappEmailAcctAdvSettingSignaturePage *p =
        (VappEmailAcctAdvSettingSignaturePage *)handleToObject((VfxObjHandle)userData);
    mmi_str_id string_id;

    if (p == NULL)
    {
      return;
    }

    if (p->indicator_pop != NULL && p->indicator_pop->isValid())
    {
    VFX_OBJ_CLOSE(p->indicator_pop);
    }

    if (MMI_EMAIL_SUCCESS != editRes)
    {
        string_id = editRes < 0 ?
                        srv_fmgr_fs_error_get_string(editRes) :
                        STR_GLOBAL_ERROR;
        vapp_email_alert_cfm(string_id);
    }
    p->exit();
}

mmi_ret VappEmailAcctAdvSettingSignaturePage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_FILE_SELECTOR_RESULT:  // evrnt from file manager
        {
            vcui_file_selector_result_event_struct *fmgrEvt;
            fmgrEvt = (vcui_file_selector_result_event_struct*)evt;

            if (fmgrEvt->result > 0)
            {
                srv_fmgr_fileinfo_struct info;
                memset(&info, 0, sizeof(info));
                VfxU32 buffSize = (SRV_FMGR_PATH_MAX_LEN+1) * sizeof(VfxWChar);

                vcui_file_selector_get_selected_filepath(
                    fsCuiId, &info, sigFilePath, buffSize);

                VfxBool needReturn = VFX_FALSE;
                VfxResId errorRes = STR_GLOBAL_ERROR;
                if (info.size == 0)
                {
                    needReturn = VFX_TRUE;
                    errorRes = STR_EMAIL_FTO_EMPTY_FILE;
                }
                else if (info.size > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
                {
                    needReturn = VFX_TRUE;
                    errorRes = STR_EMAIL_FTO_SIZE_TOO_LARGE;
                }
                else
                {
#ifdef __DRM_SUPPORT__
                    VfxBool isDrm = VFX_FALSE;
                    S32 mime_type, mime_subtype, fwd_flag;
                    vapp_email_util_get_mine_type(
                        sigFilePath, &mime_type, &mime_subtype);
                    if (mime_subtype == MIME_SUBTYPE_DRM_MESSAGE)
                    {
                        isDrm = VFX_TRUE;
                    }
                    fwd_flag = mmi_rmgr_check_forward(sigFilePath);
                    if (!(fwd_flag & MMI_RMGR_USAGE_SEND))
                    {
                        isDrm = VFX_TRUE;
                    }
                    if (isDrm)
                    {
                        needReturn = VFX_TRUE;
                        errorRes = STR_GLOBAL_DRM_PROHIBITED;
                    }
#endif /* __DRM_SUPPORT__ */
                }
                if (needReturn)
                {
                    sigFilePath[0] = 0;
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        (WCHAR*)(GetString(errorRes)));
                    return VappEmailTmplAcctSettingPage::onProc(evt);
                }

                pathChanged = VFX_TRUE;
                m_toolBar->setDisableItem('INST', VFX_TRUE);
                insertEnable = VFX_FALSE;
                addSigImgBtn();
            }

            vcui_file_selector_close(fsCuiId);
            break;
        }
        case EVT_ID_VCUI_GALLERY_CLOSE_GID: /* Event from Gallery */
        {
            vcui_gallery_close(imgViewCuiId);
            break;
        }
    }
    return VappEmailTmplAcctSettingPage::onProc(evt);
}

/****************** Account Advanced Setting Signature Page ******************/
VappEmailAcctAdvSettingRmtFldrPage::VappEmailAcctAdvSettingRmtFldrPage():
    reqId(0),
    acctId(EMAIL_ACCT_INVALID_ID),
    acctHandle(0),
    remoteFldrTotal(0),
    dataReady(VFX_FALSE)
{
}

VappEmailAcctAdvSettingRmtFldrPage::~VappEmailAcctAdvSettingRmtFldrPage()
{
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->cancelListRemoteFolder(acctId);

    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
    }
}

void VappEmailAcctAdvSettingRmtFldrPage::onInit(void)
{
    VfxPage::onInit();

    vapp_email_set_titlebar(STR_EMAIL_REMOTE_FOLDER_ID, this);

    acctId = getMainScr()->getCurrAcct()->getBasicInfo()->acct_id;

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    m_menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);
    m_menu->setRect(0, 0, getSize().width, getSize().height);
    m_menu->m_signalCmdButtonClicked.connect(
        this, &VappEmailAcctAdvSettingRmtFldrPage::onCmdBtnClicked);
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}

void VappEmailAcctAdvSettingRmtFldrPage::onEnter(VfxBool isBackward)
{
    if (isBackward)
    {
        return;
    }

    srv_email_acct_create(0, &acctHandle);

    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->m_signalAcctNwkDone.connect(
        this, &VappEmailAcctAdvSettingRmtFldrPage::onRmtFldrReady);
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->m_signalAcctNwkProc.connect(
        this, &VappEmailAcctAdvSettingRmtFldrPage::onRmtFldrEvt);
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->listRemoteFolder(acctId, acctHandle);

    vapp_email_indicator_pop(
        &indicator_pop,
        STR_GLOBAL_LOADING,
        this,
        VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    indicator_pop->m_signalButtonClicked.connect(
        this, &VappEmailAcctAdvSettingRmtFldrPage::onPopPressBack);
}

void VappEmailAcctAdvSettingRmtFldrPage::onPopPressBack(VfxObject* o, VfxId id)
{
    if (id == VCP_POPUP_BUTTON_CANCEL_PRESSED)
    {
        onPopCanceled(o, 0);
    }
}

void VappEmailAcctAdvSettingRmtFldrPage::onPopCanceled(VfxObject*, VfxFloat)
{
    srv_email_acct_destroy(acctHandle);
    acctHandle = EMAIL_ACCT_INVALID_HANDLE;

    getMainScr()->popPage();
}

void VappEmailAcctAdvSettingRmtFldrPage::onPopErrorClick(VfxObject*, VfxId)
{
    if (acctHandle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acctHandle);
        acctHandle = EMAIL_ACCT_INVALID_HANDLE;
    }
    getMainScr()->popPage();
}

VfxU32 VappEmailAcctAdvSettingRmtFldrPage::getCount() const
{
    return remoteFldrTotal > SUPPORTED_RMT_FLDR_MAX_NUM ?
        SUPPORTED_RMT_FLDR_MAX_NUM : remoteFldrTotal;
}

VfxBool VappEmailAcctAdvSettingRmtFldrPage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    if (dataReady)
    {
        VfxU32 folder_num = 1;
        srv_email_result_enum res;
        srv_email_acct_remote_fldr_info_strcut folder_info;

        res = srv_email_acct_get_remote_fldr_info(acctHandle,
                    index, &folder_num, &folder_info);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            return VFX_FALSE;
        }
        isSubscribed[index] = (folder_info.subscribed == MMI_TRUE);
        text.loadFromMem((VfxWChar*)&folder_info.folder_name);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappEmailAcctAdvSettingRmtFldrPage::getItemImage(VfxU32 index,
    VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        image.setResId(
            isSubscribed[index] ?
            IMG_EMAIL_REMOTE_SUB_ID :
            IMG_EMAIL_REMOTE_UNSUB_ID);
        return VFX_TRUE;
    }

    image.setResId(
        isSubscribed[index] ?
        IMG_EMAIL_FTO_LIST_DEL :
        IMG_EMAIL_FTO_LIST_ADD);
    return VFX_TRUE;
}

VfxBool VappEmailAcctAdvSettingRmtFldrPage::getItemIsHighlightable(
    VfxU32 index) const
{
    return VFX_FALSE;
}

void VappEmailAcctAdvSettingRmtFldrPage::onCmdBtnClicked(
    VcpListMenu *sender, VfxU32 index)
{
    srv_email_result_enum res = SRV_EMAIL_RESULT_SUCC;

    res = srv_email_acct_subscribe_remote_fldr(
            acctHandle, index, !isSubscribed[index] ? MMI_TRUE : MMI_FALSE);
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    res = srv_email_acct_remote_fldr_submit_subscribe(acctHandle);
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    isSubscribed[index] = !isSubscribed[index];

    m_menu->updateItem(index);
    return;

EXIT_HANDLE:
    vapp_email_alert_cfm(STR_GLOBAL_ERROR);
}

void VappEmailAcctAdvSettingRmtFldrPage::onRmtFldrReady(
    EMAIL_ACCT_ID acctId, 
    VappEmailNwkDoneEnum nwkDoneType, 
    VappEmailResStruct res)
{
    if (acctId != this->acctId)
    {
        /* when user Cancel feashing from NCenter, 
           VappEmailMgr will send this event to all accounts one by one
        */
        return;
    }

    if (nwkDoneType != VAPP_EMAIL_NWK_DONE_LIST_REMODE_FOLDER)
    {
        if (nwkDoneType == VAPP_EMAIL_NWK_DONE_CANCEL)
        {
        onPopErrorClick(NULL, 0);
        }
        return;
    }

    if (indicator_pop != NULL && indicator_pop->isValid())
    {
        VFX_OBJ_CLOSE(indicator_pop);
    }

    srv_email_result_enum r;
    VfxResId errId = STR_GLOBAL_ERROR;
    if (res.result != VAPP_EMAIL_RES_SUCC)
    {
        if (res.result == VAPP_EMAIL_RES_NETWORK_RUNNING)
        {
            errId = STR_EMAIL_FTO_REFESHING_CANNOT_OPEN;
        }
        else
        {
            errId = vapp_email_util_get_err_code(res.major, res.minor);
        }
        goto ERORR_EXIT;
    }

    r = srv_email_acct_get_remote_fldr_num(acctHandle, &remoteFldrTotal);

    if (r != SRV_EMAIL_RESULT_SUCC)
    {
        errId = vapp_email_util_get_err_code(r, srv_email_errno_get());
        goto ERORR_EXIT;
    }

    dataReady = VFX_TRUE;
    m_menu->reset();
    return;

ERORR_EXIT:
    VcpConfirmPopup *confirm;
    if (findScreen() == NULL)
    {
        return;
    }
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, findScreen());
    confirm->setInfoType(VCP_POPUP_TYPE_FAILURE);
    confirm->setText(VFX_WSTR_RES(errId));
    confirm->setAutoDestory(VFX_TRUE);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirm->show(VFX_TRUE);
    confirm->m_signalButtonClicked.connect(
        this, &VappEmailAcctAdvSettingRmtFldrPage::onPopErrorClick);
}


void VappEmailAcctAdvSettingRmtFldrPage::onRmtFldrEvt(
    VappEmailNwkStateEnum, VfxU32, VappEmailNwkProcEnum status)
{
    if (indicator_pop == NULL || !(indicator_pop->isValid()))
    {
        return;
    }

    switch (status)
    {
        case VAPP_EMAIL_NWK_PROC_CONNECTING:
            indicator_pop->setText(VFX_WSTR_RES(STR_GLOBAL_CONNECTING));
            break;
        case VAPP_EMAIL_NWK_PROC_AUTHORIZING:
            indicator_pop->setText(VFX_WSTR_RES(STR_EMAIL_AUTHORIZING_ID));
            break;
        case VAPP_EMAIL_NWK_PROC_UPDATING:
        case VAPP_EMAIL_NWK_PROC_LISTING_FOLDER:
            indicator_pop->setText(VFX_WSTR_RES(STR_EMAIL_UPDATING_INFO_ID));
            break;
    }
}

