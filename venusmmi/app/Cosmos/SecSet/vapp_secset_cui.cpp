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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vcui_secset_gprot.h"
#include "vapp_secset_cui.h"
#include "GlobalResDef.h"
extern "C"
{
#include "SecSetCuiGprot.h"
}


extern "C"
mmi_id vcui_verify_create(mmi_id grp_id, vcui_verify_type_enum type)
{
    mmi_id instance_id = 0;

    switch (type)
    {
        case VCUI_VERIFY_TYPE_PHONE_PASSWORD:
        {
            instance_id = VfxAppLauncher::createCui(
                VCUI_VERIFY,
                VFX_OBJ_CLASS_INFO(VcuiSecSetVerifyPhonePwd),
                grp_id);
            VcuiSecSetVerifyPhonePwd *instance =
                static_cast<VcuiSecSetVerifyPhonePwd*>(VfxApp::getObject(instance_id));
            break;
        }
        case VCUI_VERIFY_TYPE_CHV1:
        {
            instance_id = VfxAppLauncher::createCui(
                VCUI_VERIFY,
                VFX_OBJ_CLASS_INFO(VcuiSecSetVerifyChv),
                grp_id);
            VcuiSecSetVerifyChv *instance =
                static_cast<VcuiSecSetVerifyChv*>(VfxApp::getObject(instance_id));
            instance->setType(SRV_SIM_CTRL_PWD_TYPE_CHV1);
            break;
        }
        case VCUI_VERIFY_TYPE_CHV2:
        {
            instance_id = VfxAppLauncher::createCui(
                VCUI_VERIFY,
                VFX_OBJ_CLASS_INFO(VcuiSecSetVerifyChv),
                grp_id);
            VcuiSecSetVerifyChv *instance =
                static_cast<VcuiSecSetVerifyChv*>(VfxApp::getObject(instance_id));
            instance->setType(SRV_SIM_CTRL_PWD_TYPE_CHV2);
            break;
        }
    }

    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_VERIFY_CREATE, grp_id, type, instance_id);

    return instance_id;
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

extern "C"
void vcui_verify_set_sim(mmi_id instance_id, mmi_sim_enum sim)
{
    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_VERIFY_SET_SIM, instance_id, sim);

    VcuiSecSetVerifyChv *instance =
        VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(instance_id), VcuiSecSetVerifyChv);
    if (instance != NULL)
    {
        instance->setSim(sim);
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern "C"
void vcui_verify_run(mmi_id instance_id)
{
    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_VERIFY_RUN, instance_id);

    VcuiSecSetVerify *instance = VcuiSecSetVerify::getInstance(instance_id);
    
    // run() may be overwritten for pre-checks
    // Don't call VfxAppLauncher::runCui() here
    instance->run();
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern "C"
void vcui_verify_close(mmi_id instance_id)
{
    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_VERIFY_CLOSE, instance_id);
    VfxAppLauncher::terminate(instance_id);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VFX_IMPLEMENT_VIRTUAL_CLASS("VcuiSecSetVerify", VcuiSecSetVerify, VfxCui);


VcuiSecSetVerify* VcuiSecSetVerify::getInstance(mmi_id instance_id)
{
    VcuiSecSetVerify *instance =
        VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(instance_id), VcuiSecSetVerify);
    VFX_ASSERT(instance != NULL);
    
    return instance;
}


mmi_ret VcuiSecSetVerify::sendToCallerExt(void *evt, VfxBool post)
{
    mmi_ret ret = MMI_RET_OK;
    mmi_group_event_struct *grpEvt = static_cast<mmi_group_event_struct*>(evt);
    
    grpEvt->sender_id = getGroupId();
    
    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_VERIFY_SEND_TO_CALLER,
        grpEvt->evt_id, grpEvt->sender_id);
    
    if (post)
    {
        postToCaller(grpEvt);
    }
    else
    {
        ret = sendToCaller(grpEvt);
    }

    return ret;
}


void VcuiSecSetVerify::run()
{
    VfxAppLauncher::runCui(getGroupId());
}


void VcuiSecSetVerify::popupAndNotifyFailure(
        const VfxWString &msg,
        vcui_verify_fail_cause_enum cause)
{
    m_fail_cause = cause;

    if (!m_smallScreenForPopup.isValid())
    {
        VFX_OBJ_CREATE(m_smallScreenForPopup, SmallScreen, this);
    }

    VcpConfirmPopup *confirmPopup;
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, m_smallScreenForPopup.get());
    confirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    confirmPopup->setText(msg);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VcuiSecSetVerifyChv::onFailureConfirmedToNotify);

    m_smallScreenForPopup->show();
    confirmPopup->show(VFX_TRUE);
}


void VcuiSecSetVerify::onFailureConfirmedToNotify(VfxObject *obj, VfxId id)
{
    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_FAILURE_TO_NOTIFY, m_fail_cause);

    vcui_verify_result_evt_struct result_evt;
    MMI_FRM_INIT_EVENT(&result_evt, EVT_ID_VCUI_VERIFY_RESULT);
    result_evt.success = MMI_FALSE;
    result_evt.fail_cause = m_fail_cause;
    sendToCallerExt(&result_evt, VFX_FALSE);
}


void VcuiSecSetVerify::popupAndNotifyCancel(
    const VfxWString &msg,
    vcui_verify_cancel_cause_enum cause)
{
    m_cancel_cause = cause;

    if (!m_smallScreenForPopup.isValid())
    {
        VFX_OBJ_CREATE(m_smallScreenForPopup, SmallScreen, this);
    }
    
    VcpConfirmPopup *confirmPopup;
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, m_smallScreenForPopup.get());
    confirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    confirmPopup->setText(msg);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VcuiSecSetVerifyChv::onCancelConfirmedToNotify);

    m_smallScreenForPopup->show();
    confirmPopup->show(VFX_TRUE);
}


void VcuiSecSetVerify::onCancelConfirmedToNotify(VfxObject *obj, VfxId id)
{
    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_CANCEL_TO_NOTIFY, m_cancel_cause);

    vcui_verify_cancel_evt_struct cancel_evt;
    MMI_FRM_INIT_EVENT(&cancel_evt, EVT_ID_VCUI_VERIFY_CANCEL);
    cancel_evt.cause = m_cancel_cause;
    sendToCallerExt(&cancel_evt, VFX_FALSE);
}


VfxAppCloseAnswerEnum VcuiSecSetVerify::onProcessClose(VfxAppCloseOption option)
{
    vcui_verify_passive_closing_evt_struct closing_evt;
    MMI_FRM_INIT_EVENT(&closing_evt, EVT_ID_VCUI_VERIFY_PASSIVE_CLOSING);
    if (sendToCallerExt(&closing_evt, VFX_FALSE) == VCUI_SECSET_DONT_CLOSE)
    {
        MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_ON_PROCESS_CLOSE, option, VFX_APP_CLOSE_ANSWER_NO);
        return VFX_APP_CLOSE_ANSWER_NO;
    }

    MMI_TRACE(VCUI_SECSET_TRC_GROUP, TRC_VCUI_SECSET_ON_PROCESS_CLOSE, option, VFX_APP_CLOSE_ANSWER_YES);
    return VFX_APP_CLOSE_ANSWER_YES;
}

