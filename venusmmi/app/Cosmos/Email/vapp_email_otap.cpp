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
 *  Vapp_email_otap.cpp
 *
 * Project:
 * --------
 *  COSMOS Email Account OTAP
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

#include "vapp_email_otap.h"
#include "vapp_email_acct.h"
#include "vapp_email_util.h"
#include "vapp_email_mgr.h"
#include "vapp_dtcnt_gprot.h"
#include "vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"

#ifdef __MMI_EMAIL_OTAP__
#include "vapp_cca_gprot.h"
#include "mmi_rp_vapp_cca_def.h"

void vapp_email_gen_acct_name(WCHAR *p_acct_name)
{
    WCHAR *p_acct_name_base = NULL;
    S32 j = 0;
    S32 i = 0;
    VfxU32 acct_num = 0;
    WCHAR *acctsNames[MMI_EMAIL_MAX_ACCTS];

    srv_email_acct_get_num(&acct_num);
    
    if (mmi_wcslen(p_acct_name) < SRV_EMAIL_MAX_ACCT_NAME_LEN - 3)
    {
        for (j = 0; j < (S32)acct_num; j++)
        {
            if (0 == mmi_wcscmp(p_acct_name, acctsNames[j]))
            {
                if (p_acct_name_base == NULL)
                {
                    p_acct_name_base = acctsNames[j];
                }
                ++i;
                j = -1;
                kal_wsprintf(
                    p_acct_name,
                    "%w%c%d%c",
                    p_acct_name_base,
                    '(',
                    i,
                    ')');
            }
        }
    }
}

srv_email_result_enum vapp_email_otap_read_acct(
                        EMAIL_SRV_HANDLE srv_handle,
                        EMAIL_ACCT_HANDLE *p_acct_handle,
                        EMAIL_ACCT_ID acct_id,
                        srv_email_acct_info_struct *p_acct_info)
{
    srv_email_result_enum res = SRV_EMAIL_RESULT_SUCC;

    res = srv_email_acct_create(srv_handle, p_acct_handle);
    if (SRV_EMAIL_RESULT_SUCC != res)
    {
        goto MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END;
    }

    res = srv_email_acct_open(*p_acct_handle, acct_id);
    if (SRV_EMAIL_RESULT_SUCC != res)
    {
        goto MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END;
    }
    
    res = srv_email_acct_read(*p_acct_handle, p_acct_info);
    if (SRV_EMAIL_RESULT_SUCC != res)
    {
        goto MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END;
    }

    res = srv_email_acct_destroy(*p_acct_handle);
    if (SRV_EMAIL_RESULT_SUCC != res)
    {
        goto MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END;
    }
    return res;

MMI_EMAIL_OTAP_READ_ACCOUNT_INFO_ERROR_END:
    srv_email_acct_destroy(*p_acct_handle);
    return res;
}

extern "C" mmi_id cui_email_otap_create(mmi_id parent_id)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
        VCUI_EMAIL_OTAP,                              /* Cui's app id */
        VFX_OBJ_CLASS_INFO(VcuiEmailOtapCui), /* Cui class */
        parent_id,                            /* parent group id */
        NULL, 0);                             /* parameters, if any */
    return cui_id;
}

extern "C" void cui_email_otap_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

extern "C" void cui_email_otap_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}

#define VAPP_EMAIL_OTAP_CFM_POP_END 'ENDK'
VfxBool VappEmailOtapCfmPop::onKeyInput(VfxKeyEvent & event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN &&
        event.keyCode == VFX_KEY_CODE_HOME)
    {
        m_signalButtonClicked.emit(this, VAPP_EMAIL_OTAP_CFM_POP_END);
    }

    return VcpConfirmPopup::onKeyInput(event);
}

VFX_IMPLEMENT_CLASS("VcuiEmailOtapCui", VcuiEmailOtapCui, VfxCui);
void VcuiEmailOtapCui::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappEmailOtapScrn *mainScrn;
    VFX_OBJ_CREATE(mainScrn, VappEmailOtapScrn, this);
    mainScrn->show();
}

VappEmailOtapScrn::VappEmailOtapScrn()
    : needDestroy(VFX_TRUE), isReplaceAcct(VFX_FALSE)
{
}

VappEmailOtapScrn::~VappEmailOtapScrn()
{
    if (needDestroy)
    {
        VappEmailOtap *otapInst = VappEmailOtap::getInstance();
        if (otapInst->otapHandle != 0)
        {
            srv_email_otap_finish_install(otapInst->otapHandle);
            otapInst->otapHandle = 0;
        }
    }
}

void VappEmailOtapScrn::on1stReady(void)
{
    VappEmailOtapProfInfoPage *page;
    VFX_OBJ_CREATE(page, VappEmailOtapProfInfoPage, this);
    pushPage(0, page);
}

void VappEmailOtapScrn::onConfirmChoosed(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES || id == VAPP_EMAIL_OTAP_CFM_POP_END)
    {
        VappEmailOtap *otapInst = VappEmailOtap::getInstance();

        srv_email_otap_skip_prof(
                otapInst->otapHandle, 
                MMI_TRUE, 
                otapInst->profIndex, 
                SRV_EMAIL_SKIP_ENDKEY);
        srv_email_otap_finish_install(otapInst->otapHandle);
        otapInst->otapHandle = 0;
    }
}

void VappEmailOtapScrn::handleBackKey()
{
    VappEmailOtapCfmPop *retryConfirm;
    VFX_OBJ_CREATE(retryConfirm, VappEmailOtapCfmPop, this);

    retryConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_CCA_EXIT_INSTALL_CONFIRM));
    retryConfirm->setInfoType(VCP_POPUP_TYPE_QUESTION);
    retryConfirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    retryConfirm->m_signalButtonClicked.connect(
        this, 
        &VappEmailOtapScrn::onConfirmChoosed);
    retryConfirm->show(VFX_TRUE);
}

void VappEmailOtapScrn::setNoDestroy(void)
{
    needDestroy = VFX_FALSE;
}

void VappEmailOtapScrn::onOtapSaveProc(
    srv_email_result_struct *res, 
    EMAIL_ACCT_ID acctId,
    EMAIL_REQ_ID reqId, 
    void *userData)
{
    VappEmailOtap *otapInst = VappEmailOtap::getInstance();
    VappEmailOtapScrn *p = (VappEmailOtapScrn*)userData;
    VFX_OBJ_CLOSE(p->indicator_pop);

    if (MMI_TRUE == res->result)
    {
        if (!VappEmailAcct::initMiscInfo(acctId))
        {
            srv_email_acct_delete(acctId);
            VappEmailMgr::getInstance()->notifyAcctDelete(acctId);
        }
    }

    if (p->isReplaceAcct)
    {
        /* notify mgr to remove old account after replace */
        VappEmailMgr::getInstance()->notifyAcctDelete(acctId);
        p->isReplaceAcct = VFX_FALSE;
    }

    p->setNoDestroy();

    cui_email_otap_close(otapInst->cuiId);
    
    otapInst->profIndex++;
    otapInst->handleNextProf();
}


void VappEmailOtapProfInfoPage::onInit()
{
    VfxPage::onInit();

    vapp_email_set_titlebar(STR_ID_VAPP_CCA_INSTALL_SETTING, this);

    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappEmailOtapProfInfoPage::onToolBarClick);
    m_toolBar->addItem(
        'INST',
        VFX_WSTR_RES(STR_GLOBAL_INSTALL),
        IMG_ID_VAPP_CCA_INSTALL);
    m_toolBar->addItem(
        'SKIP',
        VFX_WSTR_RES(STR_ID_VAPP_CCA_SKIP),
        IMG_ID_VAPP_CCA_SKIP);
    setBottomBar(m_toolBar);

    VcpTextView *m_text;
    VFX_OBJ_CREATE(m_text, VcpTextView, this);

    m_text->setPos(LEFT_GAPS, TOP_GAPS);
    m_text->setSize(
        getSize().width - LEFT_GAPS - RIGHT_GAPS,
        getSize().height - TOP_GAPS - BOTTOM_GAPS);
    m_text->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_text->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    prepareProfInfo(m_text);
}

VfxBool VappEmailOtapProfInfoPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        ((VappEmailOtapScrn*)getMainScr())->handleBackKey();
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_HOME &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        VappEmailOtap *otapInst = VappEmailOtap::getInstance();
        srv_email_otap_skip_prof(
                otapInst->otapHandle, 
                MMI_TRUE, 
                otapInst->profIndex, 
                SRV_EMAIL_SKIP_ENDKEY);
        srv_email_otap_finish_install(otapInst->otapHandle);
        otapInst->otapHandle = 0;
    }
    return VfxPage::onKeyInput(event);
}

void VappEmailOtapProfInfoPage::prepareProfInfo(VcpTextView *text)
{
    WCHAR *showText;

    VappEmailOtap *otapInst = VappEmailOtap::getInstance();

    VFX_ALLOC_MEM(showText, 2048, this);
    
    /* E-Mail */
    mmi_wcscpy(showText, (WCHAR*)GetString(STR_GLOBAL_EMAIL));
    mmi_wcscat(showText, (WCHAR*)L"\n");

    /* Profile: 1/3 */
    mmi_wcscat(showText, (WCHAR*)GetString(STR_ID_VAPP_CCA_PROFILE));
    mmi_wcscat(showText, (WCHAR*)GetString(STR_EMAIL_COLON_ID));
    mmi_wcscat(showText, (WCHAR*)L" ");
    kal_wsprintf(
        showText + mmi_wcslen(showText),
        "%d/%d",
        (otapInst->profIndex + 1),
        otapInst->profNum);
    mmi_wcscat(showText, (WCHAR*)L"\n");

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (MMI_TRUE == otapInst->currProfInfo.updatable)
    {
        mmi_wcscat(showText, (WCHAR*)GetString(STR_ID_VAPP_CCA_UPDATE_PROFILE));
        mmi_wcscat(showText, (WCHAR*)L"\n");
    }
#endif

    /* Account name */
    if (mmi_wcslen(otapInst->currProfInfo.prof_name))
    {
        mmi_wcscat(showText, (WCHAR*)L"\n");
        mmi_wcscat(showText, (WCHAR*)GetString(STR_EMAIL_ACCT_NAME_ID));
        mmi_wcscat(showText, (WCHAR*)GetString(STR_EMAIL_COLON_ID));
        mmi_wcscat(showText, (WCHAR*)L" ");
        mmi_wcscat(showText, (otapInst->currProfInfo.prof_name));
    }

    /* From */
    if (mmi_wcslen(otapInst->currProfInfo.from))
    {
        mmi_wcscat(showText, (WCHAR*)L"\n");
        mmi_wcscat(showText, (WCHAR*)GetString(STR_EMAIL_FTO_FROM));
        mmi_wcscat(showText, (WCHAR*)GetString(STR_EMAIL_COLON_ID));
        mmi_wcscat(showText, (WCHAR*)L" ");
        mmi_wcscat(showText, (otapInst->currProfInfo.from));
    }

    /* Outgoing Server */
    if (mmi_wcslen(otapInst->currProfInfo.out_server))
    {
        mmi_wcscat(showText, (WCHAR*)L"\n");
        mmi_wcscat(showText, (WCHAR*)GetString(STR_EMAIL_OUTGOING_SERVER_ID));
        mmi_wcscat(showText, (WCHAR*)GetString(STR_EMAIL_COLON_ID));
        mmi_wcscat(showText, (WCHAR*)L" ");
        mmi_wcscat(showText, (otapInst->currProfInfo.out_server));
    }

    /* Incoming Server */
    if (mmi_wcslen(otapInst->currProfInfo.in_server))
    {
        mmi_wcscat(showText, (WCHAR*)L"\n");
        mmi_wcscat(showText, (WCHAR*)GetString(STR_EMAIL_FTO_INCOMING_SERVER));
        mmi_wcscat(showText, (WCHAR*)GetString(STR_EMAIL_COLON_ID));
        mmi_wcscat(showText, (WCHAR*)L" ");
        mmi_wcscat(showText, (otapInst->currProfInfo.in_server));
    }

    text->setText((const VfxWChar*)showText);

    VFX_FREE_MEM(showText);
}

void VappEmailOtapProfInfoPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    srv_email_result_enum res;
    VappEmailOtap *otapInst = VappEmailOtap::getInstance();
    switch(id)
    {
        case 'INST':
        {
            if (otapInst->currProfInfo.updatable)
            {
                res = srv_email_otap_update_prof(
                    otapInst->otapHandle, 
                    otapInst->profIndex,
                    otapInst->acctName);
                
                if (res == SRV_EMAIL_RESULT_SUCC)
                {
                    res = vapp_email_otap_read_acct(
                            otapInst->srvHandle, 
                            &otapInst->acctHandle,
                            otapInst->currProfInfo.update_acct_id, 
                            &otapInst->currAcctInfo);
                }

                ((VappEmailOtapScrn*)getMainScr())->setNoDestroy();
                
                // update profile done
                getApp()->exit();
                otapInst->profIndex++;
                otapInst->handleNextProf();
            }
            else    // start install 
            {
                U32 acctNum = 0;
                srv_email_acct_get_num(&acctNum);
        		if (acctNum < MMI_EMAIL_MAX_ACCTS)
        		{
                    EMAIL_ACCT_ID acctId;
                    EMAIL_REQ_ID reqId;
                    res = srv_email_otap_add_prof_async(
                            otapInst->otapHandle,
                            otapInst->profIndex,
                            otapInst->acctName,
                            &acctId,
                            &reqId,
                            &VappEmailOtapScrn::onOtapSaveProc,
                            getMainScr());
                    if (res != SRV_EMAIL_RESULT_WOULDBLOCK)
                    {
                        ((VappEmailOtapScrn*)getMainScr())->setNoDestroy();
                        getApp()->exit();
                        otapInst->profIndex++;
                        otapInst->handleNextProf();
                        return;
                    }

                    // show loading
                    vapp_email_indicator_pop(
                        &((VappEmailOtapScrn*)getMainScr())->indicator_pop,
                        STR_GLOBAL_SAVING, 
                        this);
        		}
                else
                {
                    // show account list for user to replace
                    VappEmailOtapAcctListPage *page;
                    VFX_OBJ_CREATE(page, VappEmailOtapAcctListPage, this);
                    getMainScr()->pushPage(0, page);
                }
            }
            break;
        }
        case 'SKIP':
        {
            srv_email_otap_skip_prof(
                otapInst->otapHandle, 
                MMI_FALSE, 
                otapInst->profIndex, 
                SRV_EMAIL_SKIP_NORMAL);

            ((VappEmailOtapScrn*)getMainScr())->setNoDestroy();
            getApp()->exit();
            otapInst->profIndex++;
            otapInst->handleNextProf();
            break;
        }
    }
}


void VappEmailOtapAcctListPage::initData(void)
{
    m_selectedIndex = 0;
    
    m_acctCount = 0;

    srv_email_acct_get_num(&m_acctCount);

    for (VfxU32 i = 0; i < MMI_EMAIL_MAX_ACCTS; ++i)
    {
        m_acctId[i] = EMAIL_ACCT_INVALID_ID;
    }
    srv_email_acct_get_acct_id(
        0,
        (VfxS32*)&m_acctCount,
        (EMAIL_ACCT_ID*)&m_acctId[0]);
}

void VappEmailOtapAcctListPage::onInit()
{
    VfxPage::onInit();

    vapp_email_set_titlebar(STR_ID_VAPP_CCA_REPLACE_SETTING, this);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION, VFX_TRUE);
    m_menu->m_signalItemSelectionStateChanged.connect(
        this, &VappEmailOtapAcctListPage::onItemStateChanged);
    m_menu->setRect(0, 0, getSize().width, getSize().height);
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this, &VappEmailOtapAcctListPage::onToolBarClick);
    m_toolBar->addItem(
        'RPLC',
        VFX_WSTR_RES(STR_GLOBAL_REPLACE),
        IMG_ID_VAPP_CCA_REPLACE);
    m_toolBar->addItem(
        'CNCL',
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        IMG_EMAIL_FTO_CANCEL);
    setBottomBar(m_toolBar);
}

void VappEmailOtapAcctListPage::onEnter(VfxBool isBackward)
{
    initData();
    m_menu->updateAllItems();

    /*
      User may enter Email from NCenter, switch storage, and back to this page.
      In this case, disable the toolbar item
    */ 
    if (m_acctCount < MMI_EMAIL_MAX_ACCTS)
    {
        m_toolBar->setDisableItem('RPLC', VFX_TRUE);
    }
}

VfxBool VappEmailOtapAcctListPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        ((VappEmailOtapScrn*)getMainScr())->handleBackKey();
        return VFX_TRUE;
    }
    else if (event.keyCode == VFX_KEY_CODE_HOME &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        VappEmailOtap *otapInst = VappEmailOtap::getInstance();
        srv_email_otap_skip_prof(
                otapInst->otapHandle, 
                MMI_TRUE, 
                otapInst->profIndex, 
                SRV_EMAIL_SKIP_ENDKEY);
        srv_email_otap_finish_install(otapInst->otapHandle);
        otapInst->otapHandle = 0;
    }
    return VfxPage::onKeyInput(event);
}

void VappEmailOtapAcctListPage::onItemStateChanged(
    VcpListMenu *sender,
    VfxU32 index,
    VcpListMenuItemStateEnum newState)
{
    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        m_selectedIndex = index;
    }
}

void VappEmailOtapAcctListPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    VappEmailOtap *otapInst = VappEmailOtap::getInstance();
    
    switch(id)
    {
        case 'RPLC':
        {
            EMAIL_ACCT_ID replacedAcctId;
            srv_email_result_enum result;
            EMAIL_REQ_ID reqId;
            VappEmailAcctStateEnum acctState;

            if (VappEmailMgr::getInstance()->isAcctEntered(m_acctId[m_selectedIndex]))
            {
                vapp_email_alert_cfm(STR_ID_VAPP_CCA_PROFILE_IN_USE);
                return;
            }

#ifdef __MMI_EMAIL_IMAP_PUSH__
            if (m_acctId[m_selectedIndex] == VappEmailPush::getPushAcctId())
            {
                VfxWString buttonStr(VFX_WSTR_RES(STR_GLOBAL_OK));
                VfxWString str1(VFX_WSTR_RES(STR_EMAIL_FTO_PUSH_EMAIL_ACCT));
                VfxWString str2(VFX_WSTR_RES(STR_EMAIL_FTO_CANNOT_REPLACE));
                VfxWString text;
				text += str1;
				text += VFX_WSTR("\n");
				text += str2;
                
                vapp_nmgr_global_popup_show_confirm_one_button_str(
                        MMI_SCENARIO_ID_DEFAULT,
                        VCP_POPUP_TYPE_FAILURE, 
                        text, 
                        buttonStr, 
                        VCP_POPUP_BUTTON_TYPE_NORMAL,
                        NULL,
                        NULL);
                return;
            }
#endif /* #ifdef __MMI_EMAIL_IMAP_PUSH__ */

            acctState = VappEmailMgr::getInstance()->getAcctState(m_acctId[m_selectedIndex]);
            if (acctState != VAPP_EMAIL_ACCT_STATE_NORMAL &&
                acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_SEND_FAIL &&
                acctState != VAPP_EMAIL_ACCT_STATE_NETWORK_REFRESH_FAIL)
            {
                vapp_email_alert_cfm(STR_ID_VAPP_CCA_PROFILE_IN_USE);
                return;
            }

            VappEmailOtapScrn *mainScr = (VappEmailOtapScrn*)getMainScr();
            mainScr->isReplaceAcct = VFX_TRUE;

            VappEmailStateEnum emailState;
            emailState = VappEmailMgr::getInstance()->getEmailAppState();    
            if (emailState == VAPP_EMAIL_STATE_DEINITED ||
                emailState == VAPP_EMAIL_STATE_INITIALIZING ||
                emailState == VAPP_EMAIL_STATE_USB_MODE ||
                emailState == VAPP_EMAIL_STATE_TCARD_OUT)
            {
                VfxResId errId = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
                if (emailState == VAPP_EMAIL_STATE_USB_MODE)
                {
                    errId = STR_EMAIL_FTO_OTAP_FAIL_MASS_STORAGE;
                }
                vapp_email_alert_cfm(errId);
                //srv_email_otap_finish_install(otapInst->otapHandle);
                //otapInst->otapHandle = 0;
                return;
            }

            result = srv_email_otap_replace_prof_async(
                otapInst->otapHandle, 
                otapInst->profIndex,
                otapInst->acctName,
                m_acctId[m_selectedIndex],
                &replacedAcctId,
                &reqId,
                &VappEmailOtapScrn::onOtapSaveProc, 
                mainScr);
            if (result != SRV_EMAIL_RESULT_WOULDBLOCK &&
                result != SRV_EMAIL_RESULT_SUCC)
            {
                vapp_email_alert_cfm(
                    vapp_email_util_get_err_code(result,srv_email_errno_get()));
                return;
            }

            vapp_email_indicator_pop(
                &((VappEmailOtapScrn*)getMainScr())->indicator_pop,
                STR_GLOBAL_SAVING, 
                this);
            break;
        }
        case 'CNCL':
        {
            /*srv_email_otap_skip_prof(
                otapInst->otapHandle, 
                MMI_FALSE, 
                otapInst->profIndex, 
                SRV_EMAIL_SKIP_NORMAL);
            
            ((VappEmailOtapScrn*)getMainScr())->setNoDestroy();
            getApp()->exit();
            otapInst->profIndex++;
            otapInst->handleNextProf();*/
            getMainScr()->popPage();
            break;
        }
    }
}

VfxBool VappEmailOtapAcctListPage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    if (index < (VfxU32)m_acctCount)
    {
        srv_email_acct_info_cache_struct acctInfo;
        srv_email_acct_cache_get(m_acctId[index], &acctInfo);
        text.loadFromMem((const VfxWChar*)&acctInfo.acct_name);

        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxU32 VappEmailOtapAcctListPage::getCount() const
{
    return m_acctCount;
}

VcpListMenuItemStateEnum VappEmailOtapAcctListPage::getItemState(
    VfxU32 index) const
{
    if (index == m_selectedIndex)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappEmailOtap);
void VappEmailOtap::sysInit(void)
{
    srv_email_register_otap_notify(0, VappEmailOtap::mainProc, NULL);
}

void VappEmailOtap::mainProc(VfxU32 profNum)
{
    VappEmailOtap *otapInst = VappEmailOtap::getInstance();
    
    srv_email_result_enum res;
    res = srv_email_otap_start_install(&(otapInst->otapHandle));
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        return;
    }

    srv_email_otap_option_struct otapOption;
    otapOption.same_dtcnt = MMI_TRUE;
    res = srv_email_otap_set_option(otapInst->otapHandle, &otapOption);
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        res = srv_email_otap_finish_install(otapInst->otapHandle);
        otapInst->otapHandle = 0;
        return;
    }

    VappEmailStateEnum emailState =
            VappEmailMgr::getInstance()->getEmailAppState();    
    if (emailState == VAPP_EMAIL_STATE_DEINITED ||
        emailState == VAPP_EMAIL_STATE_INITIALIZING ||
        emailState == VAPP_EMAIL_STATE_USB_MODE ||
        emailState == VAPP_EMAIL_STATE_TCARD_OUT)
    {
        VfxResId errId = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
        if (emailState == VAPP_EMAIL_STATE_USB_MODE)
        {
            errId = STR_EMAIL_FTO_OTAP_FAIL_MASS_STORAGE;
        }
        vapp_email_alert_cfm(errId);
        res = srv_email_otap_finish_install(otapInst->otapHandle);
        otapInst->otapHandle = 0;
        return;
    }

    otapInst->profIndex = 0;
    otapInst->profNum = profNum;

    otapInst->handleNextProf();
}

static VfxBool lastAcctExist = VFX_FALSE;
void VappEmailOtap::handleNextProf(void)
{
	if(profIndex + 1 > profNum)
	{
        // no more profile, call SRV and return;
        if (otapHandle != 0)
        {
            lastAcctExist = VFX_FALSE;
        srv_email_otap_finish_install(otapHandle);
            otapHandle = 0;
        }
        return;
	}

    // start handle next profile
    srv_email_result_enum res;

    res = srv_email_otap_get_prof_info(otapHandle, profIndex, &currProfInfo);
    
    if(res != SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_otap_skip_prof(
            otapHandle, 
            MMI_FALSE, 
            profIndex, 
            SRV_EMAIL_SKIP_ERROR);
        ++profIndex;
        
        handleNextProf();
        return;
    }

    if (mmi_wcslen(currProfInfo.from) != 0)
    {
        mmi_wcsncpy(acctName, currProfInfo.from, SRV_EMAIL_MAX_ACCT_NAME_LEN);

        // check whether this account exist
        if (!currProfInfo.updatable && VappEmailAcct::isAcctAddrExist(
                currProfInfo.from, EMAIL_ACCT_INVALID_ID))
        {
            srv_email_otap_skip_prof(
            otapHandle, 
            MMI_FALSE, 
            profIndex, 
            SRV_EMAIL_SKIP_ERROR);
            ++profIndex;
            
            // global pop
            if (!lastAcctExist)
            {
            vapp_email_alert_cfm(STR_EMAIL_FTO_ADDR_EXIST);
                lastAcctExist = VFX_TRUE;
            }
            
            handleNextProf();
            return;
        }
    }
    else
    {
        mmi_wcsncpy(
            acctName,
            currProfInfo.in_server,
            SRV_EMAIL_MAX_ACCT_NAME_LEN);
    }

    lastAcctExist = VFX_FALSE;

    mmi_id parentId = vapp_cca_get_parent_id();
    if (parentId != 0)
    {
        cuiId = cui_email_otap_create(parentId);
        cui_email_otap_run(cuiId);
    }
}

#endif


