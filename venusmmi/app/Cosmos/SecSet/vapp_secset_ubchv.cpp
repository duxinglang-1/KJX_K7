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
 *  vapp_secset_sim.cpp
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
#include "vapp_secset_chv.h"
#include "vapp_secset_str.h"
#include "GlobalResDef.h"
extern "C"
{
#include "SimCtrlSrvGprot.h"
#include "ShutdownSrvGprot.h"
}


using namespace VappSecSetStr;
using namespace VappSecSetChv;

//#pragma arm section code = "DYNAMIC_CODE_SECSET_ROCODE", rodata = "DYNAMIC_CODE_SECSET_RODATA"
VFX_IMPLEMENT_CLASS("VappSecSetUbchvSeq", VappSecSetUbchvSeq, VappSecSetChvBaseSeq);


void VappSecSetUbchvSeq::onInit()
{
    VappSecSetChvBaseSeq::onInit();
}


void VappSecSetUbchvSeq::onDeinit()
{
    if (m_ubchvPage.isValid())
    {
        getMainScr()->closePage(m_ubchvPage->getId());
    }
    if (m_newChvPage.isValid())
    {
        getMainScr()->closePage(m_newChvPage->getId());
    }

    VappSecSetChvBaseSeq::onDeinit();
}


void VappSecSetUbchvSeq::setBackEnabled(VfxBool enabled)
{
    m_backEnabled = enabled;
}


void VappSecSetUbchvSeq::onShow()
{
    VFX_ASSERT(m_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1 || m_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2);

    if (srv_sim_ctrl_pwd_is_blocked(m_sim, m_type))
    {
        displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            getChvStr(m_sim, m_type, STR_UBCHV_BLOCKED),
            RESULT_ALREADY_BLOCKED);
        return;
    }

    VFX_OBJ_CREATE(m_ubchvPage, VappPasswordPage, getMainScr());
    m_ubchvPage->setLengthRestriction(
        SRV_SIM_CTRL_MIN_UBCHV_LEN,
        SRV_SIM_CTRL_MAX_UBCHV_LEN);
    VfxWString inputUbchvStr = getChvStr(m_sim, m_type, STR_INPUT_UBCHV);
    m_ubchvPage->setPrompt(inputUbchvStr);
    VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(m_sim, m_type);
    m_ubchvPage->setExtraMessage(getRemainingPromptStr(nRemainingAttempts, this));
    if (m_backEnabled)
    {
        m_ubchvPage->setAuxButton(
            VappPasswordPage::AUX_BUTTON_DEFAULT,
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VappPasswordPage::AUX_TYPE_NEGATIVE);
        m_ubchvPage->m_signalAuxSelected.connect(this, &VappSecSetUbchvSeq::onCancelSelectedOnUbchv);
    }
    else
    {
        m_ubchvPage->setAuxButton(
            VappPasswordPage::AUX_BUTTON_DEFAULT,
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_EMERGENCY),
            VappPasswordPage::AUX_TYPE_CRITICAL);
        m_ubchvPage->m_signalAuxSelected.connect(this, &VappSecSetUbchvSeq::onEmergencySelectedOnUbchv);
    }
    m_ubchvPage->setAllowDelete(m_backEnabled);
    m_ubchvPage->activateEditor();
    m_ubchvPage->m_signalDone.connect(this, &VappSecSetUbchvSeq::onUbchvInputted);
    m_ubchvPage->m_signalBack.connect(
        this,
        &VappSecSetUbchvSeq::notifyResultOnGoBack<RESULT_GO_BACK>);
    
    getMainScr()->pushPage(0, m_ubchvPage.get());
    getMainScr()->show();


    // CHV blocked prompt popup
    VcpConfirmPopup *promptPopup;
    VFX_OBJ_CREATE(promptPopup, VcpConfirmPopup, getMainScr());
    promptPopup->setText(getChvStr(m_sim, m_type, STR_CHV_BLOCKED_REQ_UBCHV));
    promptPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    promptPopup->setAutoDestory(VFX_TRUE);
    if (m_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
    {
        promptPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        promptPopup->setCustomButton(
            STR_GLOBAL_OK,
            STR_ID_VAPP_SECSET_POWER_OFF,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_WARNING);
    }
    else
    {
        promptPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    }
    promptPopup->m_signalButtonClicked.connect(this, &VappSecSetUbchvSeq::onPromptPopupConfirmed);
    promptPopup->show(VFX_TRUE);

    pushItemAndKickExists(this);
}


void VappSecSetUbchvSeq::onUbchvInputted(VappPasswordPage *ubchvPage)
{
    VFX_OBJ_CREATE(m_newChvPage, VappConfirmPasswordPage, getMainScr());
    m_newChvPage->setLengthRestriction(
        SRV_SIM_CTRL_MIN_CHV_LEN,
        SRV_SIM_CTRL_MAX_CHV_LEN);
    m_newChvPage->setPrompt(
        getChvStr(m_sim, m_type, STR_NEW_CHV),
        getChvStr(m_sim, m_type, STR_CONFIRM_CHV));
    m_newChvPage->setDiffInputPrompt(getChvStr(m_sim, m_type, STR_DIFF_CHV));
    if (m_backEnabled)
    {
        m_newChvPage->setAuxButton(
            VappConfirmPasswordPage::AUX_BUTTON_DEFAULT,
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VappConfirmPasswordPage::AUX_TYPE_NEGATIVE);
        m_newChvPage->m_signalAuxSelected.connect(this, &VappSecSetUbchvSeq::onCancelSelectedOnNewChv);
    }
    else
    {
        m_newChvPage->setAuxButton(
            VappConfirmPasswordPage::AUX_BUTTON_DEFAULT,
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_EMERGENCY),
            VappConfirmPasswordPage::AUX_TYPE_CRITICAL);
        m_newChvPage->m_signalAuxSelected.connect(this, &VappSecSetUbchvSeq::onEmergencySelectedOnNewChv);
    }
    m_newChvPage->m_signalDone.connect(this, &VappSecSetUbchvSeq::onNewChvInputted);
    
    getMainScr()->pushPage(0, this->m_newChvPage.get());
    m_newChvPage->activateEditor();
}


void VappSecSetUbchvSeq::onNewChvInputted(VappConfirmPasswordPage *newChvPage)
{
    showWaiting();

    srv_sim_ctrl_verify_ubchv(
        m_sim,
        m_type,
        m_ubchvPage->getInput(),
        m_newChvPage->getInput(),
        &VappSecSetUbchvSeq::onVerifyResult,
        getObjHandle());
}


mmi_ret VappSecSetUbchvSeq::onVerifyResult(mmi_event_struct *evt)
{
    srv_sim_ctrl_verify_result_evt_struct *result_evt =
        reinterpret_cast<srv_sim_ctrl_verify_result_evt_struct*>(evt);
        
    VappSecSetUbchvSeq *seqObj;
    VAPP_SECSET_HANDLE_TO_OBJECT(seqObj, VappSecSetUbchvSeq, result_evt->user_data);

    if (seqObj == NULL)
    {
        return MMI_RET_OK;
    }

    seqObj->closeWaiting();

    if (result_evt->success)
    {
        seqObj->notifyDone(RESULT_SUCCESS);
    }
    else if (result_evt->fail_cause == SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD)
    {
        if (srv_sim_ctrl_pwd_is_blocked(result_evt->sim, result_evt->type))
        {
            if (result_evt->type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1 &&
                srv_sim_ctrl_get_unavailable_cause(result_evt->sim) == SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED)
            {
                seqObj->displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    getSimStr(result_evt->sim, STR_SIM_BLOCKED),
                    RESULT_WRONG_PASSWORD);
            }
            else
            {
                seqObj->displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    getChvStr(result_evt->sim, result_evt->type, STR_UBCHV_BLOCKED),
                    RESULT_WRONG_PASSWORD);
            }
        }
        else
        {
            VfxWString prompt = getChvStr(result_evt->sim, result_evt->type, STR_WRONG_UBCHV);
            VfxWString failureMsg = getFailureMsgWithRemaining(
                prompt,
                result_evt->n_remaining_attempts,
                seqObj);

            seqObj->displayPopupAndBack(
                VCP_POPUP_TYPE_FAILURE,
                failureMsg);
        }
    }
    else
    {
        VfxWString failureMessage =
            getSimFailureMessage(result_evt->sim, result_evt->type, result_evt->fail_cause);
        seqObj->displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            failureMessage,
            mapFailCauseToResult(result_evt->fail_cause));
    }

    return MMI_RET_OK;
}


void VappSecSetUbchvSeq::onPopupBack(VfxS32 id)
{
    VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(m_sim, m_type);
    m_ubchvPage->setExtraMessage(getRemainingPromptStr(nRemainingAttempts, this));

    if (m_newChvPage.isValid())
    {
        getMainScr()->closePage(m_newChvPage->getId());
    }

    m_ubchvPage->clearInput();
    m_ubchvPage->activateEditor();
}


void VappSecSetUbchvSeq::onPromptPopupConfirmed(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_OK ||
        id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_ubchvPage->activateEditor();
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2) // Power off is selected
    {
        srv_shutdown_normal_start(VAPP_SECSET);
    }
}


void VappSecSetUbchvSeq::onCancelSelectedOnUbchv(
    VappPasswordPage *page,
    VappPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}


void VappSecSetUbchvSeq::onCancelSelectedOnNewChv(
    VappConfirmPasswordPage *page,
    VappConfirmPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}


void VappSecSetUbchvSeq::onEmergencySelectedOnUbchv(
    VappPasswordPage *page,
    VappPasswordPage::AuxButtonEnum id)
{
    showDialerForEmergency();
}


void VappSecSetUbchvSeq::onEmergencySelectedOnNewChv(
    VappConfirmPasswordPage *page,
    VappConfirmPasswordPage::AuxButtonEnum id)
{
    showDialerForEmergency();
}


VfxBool VappSecSetUbchvSeq::shouldBeClosedOnUnavailable(srv_sim_ctrl_ua_cause_enum cause)
{
    if (m_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
    {
        if (cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED ||
            cause == SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED)
        {
            return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}
//#pragma arm section code, rodata

