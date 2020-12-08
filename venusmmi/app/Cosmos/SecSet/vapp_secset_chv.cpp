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
#include "vcui_dialer_gprot.h"
#include "GlobalResDef.h"
extern "C"
{
#include "SimCtrlSrvGprot.h"
#include "SecSetSrvGprot.h"
}


using namespace VappSecSetStr;
using namespace VappSecSetChv;


ResultEnum VappSecSetChv::mapFailCauseToResult(
    srv_sim_ctrl_fail_cause_enum fail_cause)
{
    ResultEnum result;

    switch (fail_cause)
    {
        case SRV_SIM_CTRL_FAIL_CAUSE_WRONG_PASSWORD:
            result = RESULT_WRONG_PASSWORD;
            break;
            
        case SRV_SIM_CTRL_FAIL_CAUSE_OPERATION_BLOCKED:
            result = RESULT_ALREADY_BLOCKED;
            break;
            
        case SRV_SIM_CTRL_FAIL_CAUSE_TEMP_FAIL:
            result = RESULT_TEMP_FAIL;
            break;

        case SRV_SIM_CTRL_FAIL_CAUSE_SIM_ERROR:
            result = RESULT_SIM_ERROR;
            break;

        default:
            result = RESULT_INVALID;
            break;
    }

    return result;
}


srv_sim_ctrl_pwd_type_enum VappSecSetChv::getUbchvType(
    srv_sim_ctrl_pwd_type_enum chv_type)
{
    srv_sim_ctrl_pwd_type_enum ubchv_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV1;

    switch (chv_type)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV1:
            ubchv_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV1;
            break;

        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV2:
            ubchv_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV2;
            break;

        default:
            VFX_ASSERT(0);
    }

    return ubchv_type;
}

#pragma arm section code = "DYNAMIC_CODE_SECSET_ROCODE", rodata = "DYNAMIC_CODE_SECSET_RODATA"

VfxBool VappSecSetPage::getSimAndChvType(
    VcpFormItemCell *cell,
    VfxId id,
    mmi_sim_enum *outSim,
    srv_sim_ctrl_pwd_type_enum *outChvType)
{
    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        SimSettingForm *simForm = &m_simSetting[i];
        mmi_sim_enum sim = srv_sim_ctrl_get_sim_by_index(i);
        
        if (cell == simForm->chv1Lock ||
            cell == simForm->changeChv1)
        {
            *outSim = sim;
            *outChvType = SRV_SIM_CTRL_PWD_TYPE_CHV1;
            return VFX_TRUE;
        }
        else if (cell == simForm->changeChv2)
        {
            *outSim = sim;
            *outChvType = SRV_SIM_CTRL_PWD_TYPE_CHV2;
            return VFX_TRUE;
        }
    }

    *outSim = MMI_SIM_NONE;
    *outChvType = SRV_SIM_CTRL_PWD_TYPE_NONE;

    return VFX_FALSE;
}


void VappSecSetPage::onChvLockSwitching(
    VcpFormItemSwitchCell *cell,
    VfxId id,
    VfxBool newVal)
{
    mmi_sim_enum sim;
    srv_sim_ctrl_pwd_type_enum type;

    if (!getSimAndChvType(cell, id, &sim, &type))
    {
        return;
    }

    VappSecSetChvLockSeq *chvLockSeq;
    VFX_OBJ_CREATE(chvLockSeq, VappSecSetChvLockSeq, this);
    chvLockSeq->setSimAndType(sim, type);
    chvLockSeq->setTargetValue(newVal);
    chvLockSeq->m_signalDone.connect(this, &VappSecSetPage::onChvLockSwitchDone);
    
    m_actionPageSeq = chvLockSeq;
    m_actionPageSeq->show(getMainScr());
}


void VappSecSetPage::onChvLockSwitchDone(VappSecSetPageSeq *actionPageSeq, VfxS32 result)
{
    VFX_OBJ_CLOSE(m_actionPageSeq);
}


VFX_IMPLEMENT_CLASS("VappSecSetChvLockSeq", VappSecSetChvLockSeq, VappSecSetChvBaseSeq);

void VappSecSetChvLockSeq::onInit()
{
    VappSecSetChvBaseSeq::onInit();
}


void VappSecSetChvLockSeq::onDeinit()
{
    if (m_pwdPage.isValid())
    {
        getMainScr()->closePage(m_pwdPage->getId());
    }

    VappSecSetChvBaseSeq::onDeinit();
}


void VappSecSetChvLockSeq::onShow()
{
    VFX_ASSERT(m_sim != MMI_SIM_NONE);

    if (!srv_sim_ctrl_is_available(m_sim))
    {
        displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            VFX_WSTR_RES(STR_GLOBAL_UNAVAILABLE_SIM),
            RESULT_UNAVAILABLE);
        return;
    }

    if (srv_sim_ctrl_pwd_is_blocked(m_sim, m_type))
    {
        // If we support user set CHV2, we should invoke UBCHV2 here
        displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            getChvStr(m_sim, m_type, STR_CHV_BLOCKED),
            RESULT_ALREADY_BLOCKED);
        return;
    }

    VFX_OBJ_CREATE(m_pwdPage, VappPasswordPage, getMainScr());
    m_pwdPage->setLengthRestriction(
        SRV_SIM_CTRL_MIN_CHV_LEN,
        SRV_SIM_CTRL_MAX_CHV_LEN);
    VfxWString inputChvStr = getChvStr(m_sim, m_type, STR_INPUT_CHV);
    m_pwdPage->setPrompt(inputChvStr);
    VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(m_sim, m_type);
    m_pwdPage->setExtraMessage(getRemainingPromptStr(nRemainingAttempts, this));
    m_pwdPage->setAuxButton(
        VappPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VappPasswordPage::AUX_TYPE_NEGATIVE);
    m_pwdPage->m_signalDone.connect(this, &VappSecSetChvLockSeq::onChvInputted);
    m_pwdPage->m_signalAuxSelected.connect(this, &VappSecSetChvLockSeq::onCancelSelected);
    m_pwdPage->m_signalBack.connect(
        this,
        &VappSecSetChvLockSeq::notifyResultOnGoBack<RESULT_GO_BACK>);
    
    getMainScr()->pushPage(0, m_pwdPage.get());
    getMainScr()->show();
    m_pwdPage->activateEditor();

    pushItemAndKickExists(this);
}


void VappSecSetChvLockSeq::onChvInputted(VappPasswordPage *pwdPage)
{
    showWaiting();

    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_CHV_LOCK_ON_INPUTTED,
        m_sim, m_type, m_targetValue);

    srv_sim_ctrl_set_enabled(
        m_sim,
        m_type,
        pwdPage->getInput(),
        to_MMI_BOOL(m_targetValue),
        &VappSecSetChvLockSeq::onSetEnabledResult,
        getObjHandle());
}


mmi_ret VappSecSetChvLockSeq::onSetEnabledResult(mmi_event_struct *evt)
{
    srv_sim_ctrl_set_enabled_result_evt_struct *result_evt =
        reinterpret_cast<srv_sim_ctrl_set_enabled_result_evt_struct*>(evt);

    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_CHV_SET_ENABLED_RESULT,
        result_evt->sim, result_evt->type, result_evt->success, result_evt->fail_cause);
        
    VappSecSetChvLockSeq *seqObj;
    VAPP_SECSET_HANDLE_TO_OBJECT(seqObj, VappSecSetChvLockSeq, result_evt->user_data);

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
            // We only support CHV1 lock now
            srv_sim_ctrl_pwd_type_enum ubchv_type = SRV_SIM_CTRL_PWD_TYPE_UBCHV1;

            if (!srv_sim_ctrl_pwd_is_blocked(result_evt->sim, ubchv_type))
            {
                // UBCHV1 module will display
                vapp_secset_hpveri_try_to_launch(result_evt->sim);
                seqObj->notifyDone(RESULT_WRONG_PASSWORD);
            }
            else // UBCHV is also blocked
            {
                // Popup PIN blocked and go back
                seqObj->displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    getChvStr(result_evt->sim, result_evt->type, STR_CHV_BLOCKED),
                    RESULT_WRONG_PASSWORD);
            }
        }
        else
        {
            VfxWString prompt =
                getChvStr(result_evt->sim, result_evt->type, STR_WRONG_CHV);
            VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(result_evt->sim, result_evt->type);
            VfxWString failureMsg = getFailureMsgWithRemaining(prompt, nRemainingAttempts, seqObj);

            seqObj->displayPopupAndDone(
                VCP_POPUP_TYPE_FAILURE,
                failureMsg,
                RESULT_WRONG_PASSWORD);
        }
    }
    else
    {
        VfxWString failureMsg =
            getSimFailureMessage(result_evt->sim, result_evt->type, result_evt->fail_cause);
        seqObj->displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            failureMsg,
            mapFailCauseToResult(result_evt->fail_cause));
    }

    return MMI_RET_OK;
}


void VappSecSetChvLockSeq::onCancelSelected(
    VappPasswordPage *pwdPage,
    VappPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}


void VappSecSetPage::onSimChangeChvTapped(VcpFormItemCell *item, VfxId id)
{
    mmi_sim_enum sim;
    srv_sim_ctrl_pwd_type_enum chv_type;

    if (!getSimAndChvType(item, id, &sim, &chv_type))
    {
        return;
    }

    VappSecSetChangeChvSeq *changeSeq;
    VFX_OBJ_CREATE(changeSeq, VappSecSetChangeChvSeq, this);
    changeSeq->setSimAndType(sim, chv_type);
    changeSeq->m_signalDone.connect(this, &VappSecSetPage::onSimChangeChvDone);

    m_actionPageSeq = changeSeq;
    m_actionPageSeq->show(getMainScr());
}


void VappSecSetPage::onSimChangeChvDone(VappSecSetPageSeq *pageSeq, VfxS32 result)
{
    VappSecSetChangeChvSeq *changeSeq = VFX_OBJ_DYNAMIC_CAST(pageSeq, VappSecSetChangeChvSeq);

    if (changeSeq == NULL)
    {
        return;
    }
    
    mmi_sim_enum sim = changeSeq->getSim();
    srv_sim_ctrl_pwd_type_enum type = changeSeq->getType();

    VFX_OBJ_CLOSE(m_actionPageSeq);

    if (result == RESULT_SUCCESS)
    {
        VfxWString msgStr = getChvStr(sim, type, STR_CHV_CHANGED);
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_SUCCESS,
            msgStr.getBuf());
    }
    else if (result == RESULT_UNBLOCKED)
    {
        VfxWString msgStr = getChvStr(sim, type, STR_CHV_UNBLOCKED);
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_SUCCESS,
            msgStr.getBuf());
    }
}


VFX_IMPLEMENT_CLASS("VappSecSetChangeChvSeq", VappSecSetChangeChvSeq, VappSecSetChvBaseSeq);


void VappSecSetChangeChvSeq::onInit()
{
    VappSecSetChvBaseSeq::onInit();
}


void VappSecSetChangeChvSeq::onDeinit()
{
    closeChangeChvPages();
    
    if (m_ubchvSeq.isValid())
    {
        VFX_OBJ_CLOSE(m_ubchvSeq);
    }
    
    VappSecSetChvBaseSeq::onDeinit();
}


void VappSecSetChangeChvSeq::onShow()
{
    if (!srv_sim_ctrl_is_available(m_sim))
    {
        displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            VFX_WSTR_RES(STR_GLOBAL_UNAVAILABLE_SIM),
            RESULT_UNAVAILABLE);
        return;
    }

    if (srv_sim_ctrl_pwd_is_blocked(m_sim, m_type))
    {
        srv_sim_ctrl_pwd_type_enum ubchv_type = getUbchvType(m_type);
        if (srv_sim_ctrl_pwd_is_blocked(m_sim, ubchv_type))
        {
            displayPopupAndDone(
                VCP_POPUP_TYPE_FAILURE,
                getChvStr(m_sim, m_type, STR_CHV_BLOCKED),
                RESULT_ALREADY_BLOCKED);
        }
        else if (ubchv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2)
        {
            VFX_OBJ_CREATE(m_ubchvSeq, VappSecSetUbchvSeq, this);
            m_ubchvSeq->setSimAndType(m_sim, ubchv_type);
            m_ubchvSeq->m_signalDone.connect(this, &VappSecSetChangeChvSeq::onUbchvDone);
            m_ubchvSeq->show(getMainScr());
        }
        else
        {
            // CHV1, should be impossible at present
            displayPopupAndDone(
                VCP_POPUP_TYPE_FAILURE,
                getChvStr(m_sim, m_type, STR_CHV_BLOCKED),
                RESULT_ALREADY_BLOCKED);
        }
    
        return;
    }

    if (!srv_sim_ctrl_pwd_is_enabled(m_sim, m_type))
    {
        displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            getChvStr(m_sim, m_type, STR_CHV_DISABLED),
            RESULT_DISABLED);
        return;
    }

    VFX_OBJ_CREATE(m_oldPwdPage, VappPasswordPage, getMainScr());
    m_oldPwdPage->setLengthRestriction(
        SRV_SIM_CTRL_MIN_CHV_LEN,
        SRV_SIM_CTRL_MAX_CHV_LEN);
    VfxWString inputChvStr = getChvStr(m_sim, m_type, STR_OLD_CHV);
    m_oldPwdPage->setPrompt(inputChvStr);
    VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(m_sim, m_type);
    m_oldPwdPage->setExtraMessage(getRemainingPromptStr(nRemainingAttempts, this));
    m_oldPwdPage->setAuxButton(
        VappPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VappPasswordPage::AUX_TYPE_NEGATIVE);
    m_oldPwdPage->m_signalDone.connect(this, &VappSecSetChangeChvSeq::onOldChvInputted);
    m_oldPwdPage->m_signalAuxSelected.connect(this, &VappSecSetChangeChvSeq::onCancelSelectedOnOldChv);
    m_oldPwdPage->m_signalBack.connect(
        this,
        &VappSecSetChangeChvSeq::notifyResultOnGoBack<RESULT_GO_BACK>);
    
    getMainScr()->pushPage(0, m_oldPwdPage.get());
    getMainScr()->show();
    m_oldPwdPage->activateEditor();

    pushItemAndKickExists(this);
}


void VappSecSetChangeChvSeq::closeChangeChvPages()
{
    if (m_oldPwdPage.isValid())
    {
        getMainScr()->closePage(m_oldPwdPage->getId());
    }
    if (m_newPwdPage.isValid())
    {
        getMainScr()->closePage(m_newPwdPage->getId());
    }
}


void VappSecSetChangeChvSeq::onOldChvInputted(VappPasswordPage *pwdPage)
{
    VFX_OBJ_CREATE(m_newPwdPage, VappConfirmPasswordPage, getMainScr());
    m_newPwdPage->setLengthRestriction(
        SRV_SIM_CTRL_MIN_CHV_LEN,
        SRV_SIM_CTRL_MAX_CHV_LEN);
    m_newPwdPage->setPrompt(
        getChvStr(m_sim, m_type, STR_NEW_CHV),
        getChvStr(m_sim, m_type, STR_CONFIRM_CHV));
    m_newPwdPage->setDiffInputPrompt(getChvStr(m_sim, m_type, STR_DIFF_CHV));
    m_newPwdPage->setAuxButton(
        VappConfirmPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VappConfirmPasswordPage::AUX_TYPE_NEGATIVE);
    m_newPwdPage->m_signalDone.connect(this, &VappSecSetChangeChvSeq::onNewChvInputted);
    m_newPwdPage->m_signalAuxSelected.connect(this, &VappSecSetChangeChvSeq::onCancelSelectedOnNewChv);
    
    getMainScr()->pushPage(0, this->m_newPwdPage.get());
    m_newPwdPage->activateEditor();
}


void VappSecSetChangeChvSeq::onNewChvInputted(VappConfirmPasswordPage *confirmPage)
{
    showWaiting();

    srv_sim_ctrl_change_password(
        m_sim,
        m_type,
        m_oldPwdPage->getInput(),
        m_newPwdPage->getInput(),
        &VappSecSetChangeChvSeq::onChangePasswordResult,
        getObjHandle());
}


mmi_ret VappSecSetChangeChvSeq::onChangePasswordResult(mmi_event_struct *evt)
{
    srv_sim_ctrl_change_password_result_evt_struct *result_evt =
        reinterpret_cast<srv_sim_ctrl_change_password_result_evt_struct*>(evt);
        
    VappSecSetChangeChvSeq *seqObj;
    VAPP_SECSET_HANDLE_TO_OBJECT(seqObj, VappSecSetChangeChvSeq, result_evt->user_data);
    
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
            srv_sim_ctrl_pwd_type_enum ubchv_type = getUbchvType(result_evt->type);

            if (!srv_sim_ctrl_pwd_is_blocked(result_evt->sim, ubchv_type))
            {
                if (result_evt->type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
                {
                    // UBCHV1 module will display
                    vapp_secset_hpveri_try_to_launch(result_evt->sim);
                    seqObj->notifyDone(RESULT_WRONG_PASSWORD);
                }
                else
                {
                    VFX_OBJ_CREATE(seqObj->m_ubchvSeq, VappSecSetUbchvSeq, seqObj);
                    seqObj->m_ubchvSeq->setSimAndType(result_evt->sim, ubchv_type);
                    seqObj->m_ubchvSeq->m_signalDone.connect(seqObj, &VappSecSetChangeChvSeq::onUbchvDone);
                    seqObj->m_ubchvSeq->show(seqObj->getMainScr());

                    seqObj->closeChangeChvPages();
                }
            }
            else // UBCHV is also blocked
            {
                // Popup PIN blocked and go back
                seqObj->displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    getChvStr(result_evt->sim, result_evt->type, STR_CHV_BLOCKED),
                    RESULT_WRONG_PASSWORD);
            }
        }
        else
        {
            VfxWString prompt =
                getChvStr(result_evt->sim, result_evt->type, STR_WRONG_CHV);
            VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(result_evt->sim, result_evt->type);
            VfxWString failureMsg = getFailureMsgWithRemaining(
                prompt,
                nRemainingAttempts,
                seqObj);

            seqObj->displayPopupAndDone(
                VCP_POPUP_TYPE_FAILURE,
                failureMsg,
                RESULT_WRONG_PASSWORD);
        }

    }
    else
    {
        VfxWString failureMsg =
            getSimFailureMessage(result_evt->sim, result_evt->type, result_evt->fail_cause);
        seqObj->displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            failureMsg,
            mapFailCauseToResult(result_evt->fail_cause));
    }

    return MMI_RET_OK;
}


void VappSecSetChangeChvSeq::onUbchvDone(VappSecSetPageSeq *pageSeq, VfxS32 result)
{
    if (result == RESULT_SUCCESS)
    {
        notifyDone(RESULT_UNBLOCKED);
    }
    else
    {
        notifyDone(result);
    }
}


void VappSecSetChangeChvSeq::onCancelSelectedOnOldChv(
    VappPasswordPage *page,
    VappPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}


void VappSecSetChangeChvSeq::onCancelSelectedOnNewChv(
    VappConfirmPasswordPage *page,
    VappConfirmPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}


VfxBool VappSecSetChangeChvSeq::isDerivedInstance(const VappSecSetChvBaseSeq *seq)
{
    return (this == seq || m_ubchvSeq.get() == seq);
}
#pragma arm section code, rodata


VFX_IMPLEMENT_CLASS("VappSecSetVerifyChvSeq", VappSecSetVerifyChvSeq, VappSecSetChvBaseSeq);

void VappSecSetVerifyChvSeq::onInit()
{
    VappSecSetChvBaseSeq::onInit();
}


void VappSecSetVerifyChvSeq::onDeinit()
{
    if (m_pwdPage.isValid())
    {
        getMainScr()->closePage(m_pwdPage->getId());
    }
    if (m_ubchvSeq.isValid())
    {
        VFX_OBJ_CLOSE(m_ubchvSeq);
    }

    VappSecSetChvBaseSeq::onDeinit();
}


void VappSecSetVerifyChvSeq::setBackEnabled(VfxBool enabled)
{
    m_backEnabled = enabled;
}


void VappSecSetVerifyChvSeq::onShow()
{
    VFX_ASSERT(m_sim != MMI_SIM_NONE);

    if (!srv_sim_ctrl_is_available(m_sim))
    {
        displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            VFX_WSTR_RES(STR_GLOBAL_UNAVAILABLE_SIM),
            RESULT_UNAVAILABLE);
        return;
    }

    if (srv_sim_ctrl_pwd_is_blocked(m_sim, m_type))
    {
        srv_sim_ctrl_pwd_type_enum ubchv_type = getUbchvType(m_type);
        if (srv_sim_ctrl_pwd_is_blocked(m_sim, ubchv_type))
        {
            displayPopupAndDone(
                VCP_POPUP_TYPE_FAILURE,
                getChvStr(m_sim, m_type, STR_CHV_BLOCKED),
                RESULT_ALREADY_BLOCKED);
        }
        else if (ubchv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV2)
        {
            VFX_OBJ_CREATE(m_ubchvSeq, VappSecSetUbchvSeq, this);
            m_ubchvSeq->setSimAndType(m_sim, ubchv_type);
            m_ubchvSeq->m_signalDone.connect(this, &VappSecSetVerifyChvSeq::onUbchvDone);
            m_ubchvSeq->show(getMainScr());
        }
        else
        {
            // CHV1, should be impossible at present
            displayPopupAndDone(
                VCP_POPUP_TYPE_FAILURE,
                getChvStr(m_sim, m_type, STR_CHV_BLOCKED),
                RESULT_ALREADY_BLOCKED);
        }
    
        return;
    }


    // We allow verification only if CHV is enabled
    VFX_ASSERT(srv_sim_ctrl_pwd_is_enabled(m_sim, m_type));


    VFX_OBJ_CREATE(m_pwdPage, VappPasswordPage, getMainScr());
    m_pwdPage->setLengthRestriction(
        SRV_SIM_CTRL_MIN_CHV_LEN,
        SRV_SIM_CTRL_MAX_CHV_LEN);
    m_pwdPage->setPrompt(getChvStr(m_sim, m_type, STR_INPUT_CHV));
    VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(m_sim, m_type);
    m_pwdPage->setExtraMessage(getRemainingPromptStr(nRemainingAttempts, this));
    m_pwdPage->m_signalDone.connect(this, &VappSecSetVerifyChvSeq::onChvInputted);
    if (m_backEnabled)
    {
        m_pwdPage->setAuxButton(
            VappPasswordPage::AUX_BUTTON_DEFAULT,
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VappPasswordPage::AUX_TYPE_NEGATIVE);
        m_pwdPage->m_signalAuxSelected.connect(this, &VappSecSetVerifyChvSeq::onCancelSelected);
    }
    else
    {
        m_pwdPage->setAuxButton(
            VappPasswordPage::AUX_BUTTON_DEFAULT,
            VFX_WSTR_RES(STR_ID_VAPP_SECSET_EMERGENCY),
            VappPasswordPage::AUX_TYPE_CRITICAL);
        m_pwdPage->m_signalAuxSelected.connect(this, &VappSecSetVerifyChvSeq::onEmergencySelected);
    }
    m_pwdPage->setAllowDelete(m_backEnabled);
    m_pwdPage->m_signalBack.connect(
        this,
        &VappSecSetVerifyChvSeq::notifyResultOnGoBack<RESULT_GO_BACK>);
    
    getMainScr()->pushPage(0, m_pwdPage.get());
    getMainScr()->show();
    m_pwdPage->activateEditor();

    pushItemAndKickExists(this);
}


void VappSecSetVerifyChvSeq::onChvInputted(VappPasswordPage *page)
{
    showWaiting();

    srv_sim_ctrl_verify(
        m_sim,
        m_type,
        page->getInput(),
        &VappSecSetVerifyChvSeq::onVerifyResult,
        getObjHandle());
}


mmi_ret VappSecSetVerifyChvSeq::onVerifyResult(mmi_event_struct *evt)
{
    srv_sim_ctrl_verify_result_evt_struct *result_evt =
        reinterpret_cast<srv_sim_ctrl_verify_result_evt_struct*>(evt);
        
    VappSecSetVerifyChvSeq *seqObj;
    VAPP_SECSET_HANDLE_TO_OBJECT(seqObj, VappSecSetVerifyChvSeq, result_evt->user_data);

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
            srv_sim_ctrl_pwd_type_enum ubchv_type = getUbchvType(result_evt->type);

            if (!srv_sim_ctrl_pwd_is_blocked(result_evt->sim, ubchv_type))
            {
                if (result_evt->type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
                {
                    // UBCHV1 module will display
                    vapp_secset_hpveri_try_to_launch(result_evt->sim);
                    seqObj->notifyDone(RESULT_WRONG_PASSWORD);
                }
                else
                {
                    VFX_OBJ_CREATE(seqObj->m_ubchvSeq, VappSecSetUbchvSeq, seqObj);
                    seqObj->m_ubchvSeq->setSimAndType(result_evt->sim, ubchv_type);
                    seqObj->m_ubchvSeq->m_signalDone.connect(seqObj, &VappSecSetVerifyChvSeq::onUbchvDone);
                    seqObj->m_ubchvSeq->show(seqObj->getMainScr());

                    seqObj->getMainScr()->closePage(seqObj->m_pwdPage->getId());
                }
            }
            else // UBCHV is also blocked
            {
                // Popup PIN blocked and go back
                seqObj->displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    getChvStr(result_evt->sim, result_evt->type, STR_CHV_BLOCKED),
                    RESULT_WRONG_PASSWORD);
            }
        }
        else
        {
            VfxWString prompt =
                getChvStr(result_evt->sim, result_evt->type, STR_WRONG_CHV);
            VfxWString failureMsg = getFailureMsgWithRemaining(
                prompt,
                result_evt->n_remaining_attempts,
                seqObj);

            if (seqObj->m_retryUntilSuccess)
            {
                seqObj->displayPopupAndBack(
                    VCP_POPUP_TYPE_FAILURE,
                    failureMsg);
            }
            else
            {
                seqObj->displayPopupAndDone(
                    VCP_POPUP_TYPE_FAILURE,
                    failureMsg,
                    RESULT_WRONG_PASSWORD);
            }
        }
    }
    else
    {
        VfxWString failureMsg =
            getSimFailureMessage(result_evt->sim, result_evt->type, result_evt->fail_cause);
        seqObj->displayPopupAndDone(
            VCP_POPUP_TYPE_FAILURE,
            failureMsg,
            mapFailCauseToResult(result_evt->fail_cause));
    }

    return MMI_RET_OK;
}


void VappSecSetVerifyChvSeq::onPopupBack(VfxS32 id)
{
    VfxS32 nRemainingAttempts = srv_sim_ctrl_get_n_remaining_attempts(m_sim, m_type);
    m_pwdPage->setExtraMessage(getRemainingPromptStr(nRemainingAttempts, this));
    m_pwdPage->clearInput();
    m_pwdPage->activateEditor();
}


void VappSecSetVerifyChvSeq::onCancelSelected(
    VappPasswordPage *pwdPage,
    VappPasswordPage::AuxButtonEnum id)
{
    notifyDone(RESULT_CANCEL);
}


void VappSecSetVerifyChvSeq::onUbchvDone(VappSecSetPageSeq *pageSeq, VfxS32 result)
{
    if (result == RESULT_SUCCESS)
    {
        notifyDone(RESULT_UNBLOCKED);
    }
    else
    {
        notifyDone(result);
    }
}


void VappSecSetVerifyChvSeq::onEmergencySelected(
    VappPasswordPage *page,
    VappPasswordPage::AuxButtonEnum id)
{
    showDialerForEmergency();
}


VfxBool VappSecSetVerifyChvSeq::shouldBeClosedOnUnavailable(srv_sim_ctrl_ua_cause_enum cause)
{
    if (m_type == SRV_SIM_CTRL_PWD_TYPE_CHV1 && cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxBool VappSecSetVerifyChvSeq::isDerivedInstance(const VappSecSetChvBaseSeq *seq)
{
    return (this == seq || m_ubchvSeq.get() == seq);
}


VFX_IMPLEMENT_VIRTUAL_CLASS("VappSecSetChvBaseSeq", VappSecSetChvBaseSeq, VappSecSetPageSeq);

VfxBool VappSecSetChvBaseSeq::s_inited = VFX_FALSE;
VfxWeakPtr<VappSecSetChvBaseSeq> VappSecSetChvBaseSeq::s_chvItems[MMI_SIM_TOTAL][2];

VfxS32 VappSecSetChvBaseSeq::getChvTypeIndex(srv_sim_ctrl_pwd_type_enum type)
{
    VfxS32 chvIndex = 0;

    switch (type)
    {
        case SRV_SIM_CTRL_PWD_TYPE_CHV1:
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV1:
            chvIndex = 0;
            break;

        case SRV_SIM_CTRL_PWD_TYPE_CHV2:
        case SRV_SIM_CTRL_PWD_TYPE_UBCHV2:
            chvIndex = 1;
            break;

        default:
            VFX_ASSERT(0);
            break;
    }

    return chvIndex;
}


void VappSecSetChvBaseSeq::onDeinit()
{
    VfxS32 simIndex = srv_sim_ctrl_get_index(m_sim);
    VfxS32 chvIndex = getChvTypeIndex(m_type);

    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_CHV_ON_DEINIT, m_sim, m_type);

    if (s_chvItems[simIndex][chvIndex] == this)
    {
        s_chvItems[simIndex][chvIndex] = NULL;
    }
}


VfxBool VappSecSetChvBaseSeq::isDerivedInstance(const VappSecSetChvBaseSeq *seq)
{
    return (seq == this);
}


void VappSecSetChvBaseSeq::pushItemAndKickExists(VappSecSetChvBaseSeq *item)
{
    VFX_ASSERT(item->m_sim != MMI_SIM_NONE);

    if (!s_inited)
    {
        for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
        {
            s_chvItems[i][0] = NULL;
            s_chvItems[i][1] = NULL;
        }
        s_inited = VFX_TRUE;
    }

    VfxS32 simIndex = srv_sim_ctrl_get_index(item->m_sim);
    VfxS32 chvIndex = getChvTypeIndex(item->m_type);
    VfxWeakPtr<VappSecSetChvBaseSeq> &chvItem = s_chvItems[simIndex][chvIndex];

    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_CHV_NEW_ITEM, (VfxU32)item, item->m_sim, item->m_type);

    if (chvItem.isValid())
    {
        if (chvItem.get() != item &&
            !chvItem->isDerivedInstance(item))
        {
            MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_CHV_KICK_ITEM, (VfxU32)(chvItem.get()));
            chvItem->requestClose(RESULT_ANOTHER_INST_RUN);
            chvItem = item;
        }
        else
        {
            // The same item or derived item, do nothing
        }
    }
    else
    {
        chvItem = item;
    }
}


VfxBool VappSecSetChvBaseSeq::isValid(const VappSecSetChvBaseSeq *item)
{
    if (!s_inited)
    {
        return VFX_FALSE;
    }

    VfxS32 simIndex = srv_sim_ctrl_get_index(item->m_sim);
    VfxS32 chvIndex = getChvTypeIndex(item->m_type);
    VfxWeakPtr<VappSecSetChvBaseSeq> &chvItem = s_chvItems[simIndex][chvIndex];

    if (chvItem.isValid())
    {
        if (chvItem.get() == item ||
            chvItem->isDerivedInstance(item))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VfxBool VappSecSetChvBaseSeq::shouldBeClosedOnUnavailable(srv_sim_ctrl_ua_cause_enum cause)
{
    return VFX_TRUE;
}


void VappSecSetChvBaseSeq::requestClose(ResultEnum cause)
{
    notifyDone(cause);
}


mmi_ret VappSecSetChvBaseSeq::onSimAvailabilityChanged(mmi_event_struct *evt)
{
    srv_sim_ctrl_availability_changed_evt_struct *avai_evt =
        reinterpret_cast<srv_sim_ctrl_availability_changed_evt_struct*>(evt);

    if (!avai_evt->is_available_now)
    {
        VfxS32 simIndex = srv_sim_ctrl_get_index(avai_evt->sim);

        MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_CHV_SIM_NOT_AVAILABLE, avai_evt->sim);
        
        VfxWeakPtr<VappSecSetChvBaseSeq> &chv1Item = s_chvItems[simIndex][0];
        if (chv1Item.isValid() &&
            chv1Item->shouldBeClosedOnUnavailable(avai_evt->unavailable_cause))
        {
            MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_CHV_CLOSE_ITEM, (VfxU32)(chv1Item.get()));
            chv1Item->requestClose(RESULT_UNAVAILABLE);
        }

        VfxWeakPtr<VappSecSetChvBaseSeq> &chv2Item = s_chvItems[simIndex][1];
        if (chv2Item.isValid())
        {
            MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_CHV_CLOSE_ITEM, (VfxU32)(chv2Item.get()));
            chv2Item->requestClose(RESULT_UNAVAILABLE);
        }
    }

    return MMI_RET_OK;
}


void VappSecSetChvBaseSeq::showDialerForEmergency()
{
    mmi_id dialer_cui = vcui_dialer_create_ex(getMainScr()->getGroupId(), VCUI_DIALER_TYPE_EMERGENCY);
    vcui_dialer_set_dial_string(dialer_cui, VFX_WSTR("112"));
    mmi_frm_group_set_caller_proc(dialer_cui, &VappSecSetChvBaseSeq::onDialerCuiEvent, this);
    vcui_dialer_run(dialer_cui);
}


mmi_ret VappSecSetChvBaseSeq::onDialerCuiEvent(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
        {
            vcui_dialer_close_req_evt_struct *close_evt =
                reinterpret_cast<vcui_dialer_close_req_evt_struct*>(evt);
            vcui_dialer_close(close_evt->sender_id);
            break;
        }
    }

    return MMI_RET_OK;
}


extern "C"
mmi_ret vapp_secset_on_sim_availability_changed(mmi_event_struct *evt)
{
    vapp_secset_hpveri_on_sim_availability_changed(evt);
    
    return VappSecSetChvBaseSeq::onSimAvailabilityChanged(evt);
}
