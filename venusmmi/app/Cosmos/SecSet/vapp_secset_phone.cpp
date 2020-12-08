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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_secset_cui.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Security setting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vapp_secset.h"
#include "vapp_secset_phone.h"
#include "GlobalResDef.h"
extern "C"
{
#include "SecSetSrvGprot.h"
#include "SecSetCuiGprot.h" /* for developing CUI */
}

using namespace VappSecSetPhone;

#pragma arm section code = "DYNAMIC_CODE_SECSET_ROCODE", rodata = "DYNAMIC_CODE_SECSET_RODATA"
void VappSecSetPage::onPhoneLockSwitching(VcpFormItemSwitchCell *cell, VfxId id, VfxBool newVal)
{
    VappSecSetPhoneLockSeq *phoneLockSeq;
    VFX_OBJ_CREATE(phoneLockSeq, VappSecSetPhoneLockSeq, this);
    phoneLockSeq->setTargetValue(newVal);
    phoneLockSeq->m_signalDone.connect(this, &VappSecSetPage::onPhoneLockSwitchDone);
    
    m_actionPageSeq = phoneLockSeq;
    m_actionPageSeq->show(getMainScr());
}


void VappSecSetPage::onPhoneLockSwitchDone(VappSecSetPageSeq *actionPageSeq, VfxS32 result)
{
    VFX_OBJ_CLOSE(m_actionPageSeq);
}


VFX_IMPLEMENT_CLASS("VappSecSetPhoneLockSeq", VappSecSetPhoneLockSeq, VappSecSetPageSeq);

void VappSecSetPhoneLockSeq::onInit()
{
    VappSecSetPageSeq::onInit();
}


void VappSecSetPhoneLockSeq::onDeinit()
{
    if (m_pwdPage.isValid())
    {
        getMainScr()->closePage(m_pwdPage->getId());
    }
    VappSecSetPageSeq::onDeinit();
}


void VappSecSetPhoneLockSeq::onShow()
{
    VFX_OBJ_CREATE(m_pwdPage, VappPasswordPage, getMainScr());
    m_pwdPage->setLengthRestriction(
        SRV_SECSET_MIN_PHONE_PASSWORD_LEN,
        SRV_SECSET_MAX_PHONE_PASSWORD_LEN);
    m_pwdPage->setPrompt(VFX_WSTR_RES(STR_ID_VAPP_SECSET_INPUT_PHONE_PASSWORD));
    m_pwdPage->setAuxButton(
        VappPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VappPasswordPage::AUX_TYPE_NEGATIVE);
    m_pwdPage->m_signalDone.connect(this, &VappSecSetPhoneLockSeq::onPasswordInputted);
    m_pwdPage->m_signalAuxSelected.connect(this, &VappSecSetPhoneLockSeq::onCancelSelected);
    m_pwdPage->m_signalBack.connect(
        this,
        &VappSecSetPhoneLockSeq::notifyResultOnGoBack<RESULT_GO_BACK>);
    
    getMainScr()->pushPage(0, m_pwdPage.get());
    getMainScr()->show();
    m_pwdPage->activateEditor();
}


void VappSecSetPhoneLockSeq::onPasswordInputted(VappPasswordPage *page)
{
    showWaiting();

    srv_secset_phone_lock_set_enabled(
        to_MMI_BOOL(m_targetValue),
        m_pwdPage->getInput(),
        &VappSecSetPhoneLockSeq::onSetPhoneLockResult,
        getObjHandle());
}


mmi_ret VappSecSetPhoneLockSeq::onSetPhoneLockResult(mmi_event_struct *evt)
{
    srv_secset_phone_lock_set_enabled_result_evt_struct *result_evt =
        reinterpret_cast<srv_secset_phone_lock_set_enabled_result_evt_struct*>(evt);
        
    VappSecSetPhoneLockSeq *seqObj;
    VAPP_SECSET_HANDLE_TO_OBJECT(seqObj, VappSecSetPhoneLockSeq, result_evt->user_data);

    if (seqObj == NULL)
    {
        return MMI_RET_OK;
    }

    seqObj->closeWaiting();

    if (result_evt->success)
    {
        seqObj->notifyDone(RESULT_SUCCESS);
    }
    else
    {
        seqObj->displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_WRONG_PHONE_PASSWORD),
            RESULT_WRONG_PASSWORD);
    }

    return MMI_RET_OK;
}


void VappSecSetPhoneLockSeq::onCancelSelected(
    VappPasswordPage *page,
    VappPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}


void VappSecSetPage::onPhoneChangePwdTapped(VcpFormItemCell *item, VfxId id)
{
    VappSecSetPhoneChangePwdSeq *change_seq;
    VFX_OBJ_CREATE(change_seq, VappSecSetPhoneChangePwdSeq, this);
    change_seq->m_signalDone.connect(this, &VappSecSetPage::onPhoneChangePwdDone);

    m_actionPageSeq = change_seq;
    m_actionPageSeq->show(getMainScr());
}


void VappSecSetPage::onPhoneChangePwdDone(VappSecSetPageSeq *actionPageSeq, VfxS32 result)
{
    VFX_OBJ_CLOSE(m_actionPageSeq);

    if (result == RESULT_SUCCESS)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_SUCCESS,
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_PHONE_PASSWORD_CHANGED).getBuf());
    }
}


VFX_IMPLEMENT_CLASS("VappSecSetPhoneChangePwdSeq", VappSecSetPhoneChangePwdSeq, VappSecSetPageSeq);

void VappSecSetPhoneChangePwdSeq::onInit()
{
    VappSecSetPageSeq::onInit();
}


void VappSecSetPhoneChangePwdSeq::onDeinit()
{
    if (m_oldPwdPage.isValid())
    {
        getMainScr()->closePage(m_oldPwdPage->getId());
    }
    if (m_newPwdPage.isValid())
    {
        getMainScr()->closePage(m_newPwdPage->getId());
    }

    VappSecSetPageSeq::onDeinit();
}


void VappSecSetPhoneChangePwdSeq::onShow()
{
    VFX_OBJ_CREATE(m_oldPwdPage, VappPasswordPage, getMainScr());
    m_oldPwdPage->setLengthRestriction(
        SRV_SECSET_MIN_PHONE_PASSWORD_LEN,
        SRV_SECSET_MAX_PHONE_PASSWORD_LEN);
    m_oldPwdPage->setPrompt(VFX_WSTR_RES(STR_ID_VAPP_SECSET_OLD_PHONE_PASSWORD));
    m_oldPwdPage->setAuxButton(
        VappPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VappPasswordPage::AUX_TYPE_NEGATIVE);
    m_oldPwdPage->m_signalDone.connect(this, &VappSecSetPhoneChangePwdSeq::onOldPhonePasswordInputted);
    m_oldPwdPage->m_signalAuxSelected.connect(this, &VappSecSetPhoneChangePwdSeq::onCancelSelectedOnOldPwd);
    m_oldPwdPage->m_signalBack.connect(
        this,
        &VappSecSetPhoneChangePwdSeq::notifyResultOnGoBack<RESULT_GO_BACK>);
    
    getMainScr()->pushPage(0, m_oldPwdPage.get());
    getMainScr()->show();
    m_oldPwdPage->activateEditor();
}


void VappSecSetPhoneChangePwdSeq::onOldPhonePasswordInputted(VappPasswordPage *oldPwdPage)
{
    showWaiting();

    srv_secset_verify_phone_password(
        m_oldPwdPage->getInput(),
        &VappSecSetPhoneChangePwdSeq::onPhonePasswordVerifyResult,
        this);
}


mmi_ret VappSecSetPhoneChangePwdSeq::onPhonePasswordVerifyResult(mmi_event_struct *evt)
{
    srv_secset_verify_phone_password_result_evt_struct *result_evt =
        reinterpret_cast<srv_secset_verify_phone_password_result_evt_struct*>(evt);
    VappSecSetPhoneChangePwdSeq *seqObj =
        static_cast<VappSecSetPhoneChangePwdSeq*>(result_evt->user_data);

    seqObj->closeWaiting();

    if (result_evt->success)
    {
        VFX_OBJ_CREATE(seqObj->m_newPwdPage, VappConfirmPasswordPage, seqObj->getMainScr());
        seqObj->m_newPwdPage->setLengthRestriction(
            SRV_SECSET_MIN_PHONE_PASSWORD_LEN,
            SRV_SECSET_MAX_PHONE_PASSWORD_LEN);
        seqObj->m_newPwdPage->setPrompt(
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_NEW_PHONE_PASSWORD),
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_CONFIRM_NEW_PHONE_PASSWORD));
        seqObj->m_newPwdPage->setDiffInputPrompt(VFX_WSTR_RES(STR_ID_VAPP_SECSET_DIFF_NEW_PHONE_PASSWORD));
        seqObj->m_newPwdPage->setAuxButton(
            VappConfirmPasswordPage::AUX_BUTTON_DEFAULT,
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VappConfirmPasswordPage::AUX_TYPE_NEGATIVE);
        seqObj->m_newPwdPage->m_signalDone.connect(seqObj, &VappSecSetPhoneChangePwdSeq::onNewPhonePasswordInputted);
        seqObj->m_newPwdPage->m_signalAuxSelected.connect(seqObj, &VappSecSetPhoneChangePwdSeq::onCancelSelectedOnNewPwd);
        
        seqObj->getMainScr()->pushPage(0, seqObj->m_newPwdPage.get());
        seqObj->m_newPwdPage->activateEditor();
    }
    else
    {
        seqObj->displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_WRONG_PHONE_PASSWORD),
            RESULT_WRONG_PASSWORD);
    }

    return MMI_RET_OK;
}


void VappSecSetPhoneChangePwdSeq::onNewPhonePasswordInputted(VappConfirmPasswordPage *newPwdPage)
{
    showWaiting();

    srv_secset_change_phone_password(
        m_oldPwdPage->getInput(),
        m_newPwdPage->getInput(),
        &VappSecSetPhoneChangePwdSeq::onChangePasswordResult,
        getObjHandle());
}


mmi_ret VappSecSetPhoneChangePwdSeq::onChangePasswordResult(mmi_event_struct *evt)
{
    srv_secset_change_phone_password_result_evt_struct *result_evt =
        reinterpret_cast<srv_secset_change_phone_password_result_evt_struct*>(evt);
        
    VappSecSetPhoneChangePwdSeq *seqObj;
    VAPP_SECSET_HANDLE_TO_OBJECT(seqObj, VappSecSetPhoneChangePwdSeq, result_evt->user_data);

    if (seqObj == NULL)
    {
        return MMI_RET_OK;
    }

    seqObj->closeWaiting();

    if (result_evt->success)
    {
        seqObj->notifyDone(RESULT_SUCCESS);
    }
    else
    {
        seqObj->displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_WRONG_PHONE_PASSWORD),
            RESULT_WRONG_PASSWORD);
    }

    return MMI_RET_OK;
}


void VappSecSetPhoneChangePwdSeq::onCancelSelectedOnOldPwd(
    VappPasswordPage *page,
    VappPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}


void VappSecSetPhoneChangePwdSeq::onCancelSelectedOnNewPwd(
    VappConfirmPasswordPage *page,
    VappConfirmPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}
#pragma arm section code, rodata

VFX_IMPLEMENT_CLASS("VappSecSetPhoneVerifySeq", VappSecSetPhoneVerifySeq, VappSecSetPageSeq);

void VappSecSetPhoneVerifySeq::onInit()
{
    VappSecSetPageSeq::onInit();
}


void VappSecSetPhoneVerifySeq::onDeinit()
{
    if (m_pwdPage.isValid())
    {
        getMainScr()->closePage(m_pwdPage->getId());
    }
    VappSecSetPageSeq::onDeinit();
}


void VappSecSetPhoneVerifySeq::onShow()
{
    VFX_OBJ_CREATE(m_pwdPage, VappPasswordPage, getMainScr());
    m_pwdPage->setLengthRestriction(
        SRV_SECSET_MIN_PHONE_PASSWORD_LEN,
        SRV_SECSET_MAX_PHONE_PASSWORD_LEN);
    m_pwdPage->setPrompt(VFX_WSTR_RES(STR_ID_VAPP_SECSET_INPUT_PHONE_PASSWORD));
    m_pwdPage->setAuxButton(
        VappPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VappPasswordPage::AUX_TYPE_NEGATIVE);
    m_pwdPage->m_signalDone.connect(this, &VappSecSetPhoneVerifySeq::onPasswordInputted);
    m_pwdPage->m_signalAuxSelected.connect(this, &VappSecSetPhoneVerifySeq::onCancelSelected);
    m_pwdPage->m_signalBack.connect(
        this,
        &VappSecSetPhoneVerifySeq::notifyResultOnGoBack<RESULT_GO_BACK>);
    
    getMainScr()->pushPage(0, m_pwdPage.get());
    getMainScr()->show();
    m_pwdPage->activateEditor();
}


void VappSecSetPhoneVerifySeq::onPasswordInputted(VappPasswordPage *page)
{
    showWaiting();

    srv_secset_verify_phone_password(
        m_pwdPage->getInput(),
        &VappSecSetPhoneVerifySeq::onVerifyResult,
        getObjHandle());
}


mmi_ret VappSecSetPhoneVerifySeq::onVerifyResult(mmi_event_struct *evt)
{
    srv_secset_verify_phone_password_result_evt_struct *result_evt =
        reinterpret_cast<srv_secset_verify_phone_password_result_evt_struct*>(evt);
        
    VappSecSetPhoneVerifySeq *seqObj;
    VAPP_SECSET_HANDLE_TO_OBJECT(seqObj, VappSecSetPhoneVerifySeq, result_evt->user_data);

    if (seqObj == NULL)
    {
        return MMI_RET_OK;
    }

    seqObj->closeWaiting();

    if (result_evt->success)
    {
        seqObj->notifyDone(RESULT_SUCCESS);
    }
    else
    {
        seqObj->displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_WRONG_PHONE_PASSWORD),
            RESULT_WRONG_PASSWORD);
    }

    return MMI_RET_OK;
}


void VappSecSetPhoneVerifySeq::onCancelSelected(
    VappPasswordPage *page,
    VappPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}
