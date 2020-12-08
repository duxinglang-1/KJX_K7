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
 *  vapp_secset_chv.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SECSET_CHV_H__
#define __VAPP_SECSET_CHV_H__


#include "MMI_features.h"
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_secset_def.h"
#include "vapp_password_page_gprot.h"
#include "vapp_secset_page_seq.h"
extern "C"
{
#include "MMIDataType.h"
#include "SimCtrlSrvGprot.h"
}

namespace VappSecSetChv
{
    enum ResultEnum
    {
        RESULT_INVALID,
        RESULT_SUCCESS,
        RESULT_UNBLOCKED,
        RESULT_WRONG_PASSWORD,
        RESULT_CANCEL,
        RESULT_GO_BACK,
        RESULT_ALREADY_BLOCKED,
        RESULT_DISABLED,
        RESULT_UNAVAILABLE,
        RESULT_TEMP_FAIL,
        RESULT_SIM_ERROR,
        RESULT_ANOTHER_INST_RUN,

        RESULT_END_OF_ENUM
    };

    ResultEnum mapFailCauseToResult(srv_sim_ctrl_fail_cause_enum fail_cause);
    srv_sim_ctrl_pwd_type_enum getUbchvType(srv_sim_ctrl_pwd_type_enum chv_type);
}


extern "C"
mmi_ret vapp_secset_on_sim_availability_changed(mmi_event_struct *evt);


class VappSecSetChvBaseSeq : public VappSecSetPageSeq
{
    VFX_DECLARE_CLASS(VappSecSetChvBaseSeq);

private:
    static VfxBool s_inited;
    static VfxWeakPtr<VappSecSetChvBaseSeq> s_chvItems[MMI_SIM_TOTAL][2];

    static VfxS32 getChvTypeIndex(srv_sim_ctrl_pwd_type_enum chvType);

    friend mmi_ret vapp_secset_on_sim_availability_changed(mmi_event_struct *evt);
    static mmi_ret onSimAvailabilityChanged(mmi_event_struct *evt);
    static mmi_ret onDialerCuiEvent(mmi_event_struct *evt);

protected:
    mmi_sim_enum m_sim;
    srv_sim_ctrl_pwd_type_enum m_type;

    static void pushItemAndKickExists(VappSecSetChvBaseSeq *item);
    static VfxBool isValid(const VappSecSetChvBaseSeq *item);
    virtual VfxBool shouldBeClosedOnUnavailable(srv_sim_ctrl_ua_cause_enum cause);
    void requestClose(VappSecSetChv::ResultEnum cause);
    virtual VfxBool isDerivedInstance(const VappSecSetChvBaseSeq *seq);
    virtual void onDeinit();

    VappSecSetChvBaseSeq() :
        m_sim(MMI_SIM_NONE),
        m_type(SRV_SIM_CTRL_PWD_TYPE_NONE)
    {
    }

    void showDialerForEmergency();

public:
    void setSimAndType(mmi_sim_enum sim, srv_sim_ctrl_pwd_type_enum type)
    {
        m_sim = sim;
        m_type = type;
    }

    mmi_sim_enum getSim()
    {
        return m_sim;
    }

    srv_sim_ctrl_pwd_type_enum getType()
    {
        return m_type;
    }
};


class VappSecSetUbchvSeq : public VappSecSetChvBaseSeq
{
    VFX_DECLARE_CLASS(VappSecSetUbchvSeq);

private:
    VfxWeakPtr<VappPasswordPage> m_ubchvPage;
    VfxWeakPtr<VappConfirmPasswordPage> m_newChvPage;
    VfxBool m_backEnabled;

    void onUbchvInputted(VappPasswordPage *ubchvPage);
    void onNewChvInputted(VappConfirmPasswordPage *newChvPage);
    static mmi_ret onVerifyResult(mmi_event_struct *evt);
    void onCancelSelectedOnUbchv(
        VappPasswordPage *page,
        VappPasswordPage::AuxButtonEnum id);
    void onCancelSelectedOnNewChv(
        VappConfirmPasswordPage *page,
        VappConfirmPasswordPage::AuxButtonEnum id);
    void onEmergencySelectedOnUbchv(
        VappPasswordPage *page,
        VappPasswordPage::AuxButtonEnum id);
    void onEmergencySelectedOnNewChv(
        VappConfirmPasswordPage *page,
        VappConfirmPasswordPage::AuxButtonEnum id);

    void onPromptPopupConfirmed(VfxObject *obj, VfxId id);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onShow();
    virtual void onPopupBack(VfxS32 id);
    virtual VfxBool shouldBeClosedOnUnavailable(srv_sim_ctrl_ua_cause_enum cause);

public:
    VappSecSetUbchvSeq() :
        m_ubchvPage(NULL),
        m_newChvPage(NULL),
        m_backEnabled(VFX_TRUE)
    {
    }

    void setBackEnabled(VfxBool enabled);
};


class VappSecSetChvLockSeq : public VappSecSetChvBaseSeq
{
    VFX_DECLARE_CLASS(VappSecSetChvLockSeq);

private:
    VfxWeakPtr<VappPasswordPage> m_pwdPage;
    VfxBool m_targetValue;

    void onChvInputted(VappPasswordPage *page);
    static mmi_ret onSetEnabledResult(mmi_event_struct *evt);
    void onCancelSelected(
        VappPasswordPage *pwdPage,
        VappPasswordPage::AuxButtonEnum id);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onShow();

public:
    VappSecSetChvLockSeq() :
        m_pwdPage(NULL),
        m_targetValue(VFX_FALSE)
    {
    }

    void setTargetValue(VfxBool targetValue)
    {
        m_targetValue = targetValue;
    }
};


class VappSecSetChangeChvSeq : public VappSecSetChvBaseSeq
{
    VFX_DECLARE_CLASS(VappSecSetChangeChvSeq);
    
private:
    VfxWeakPtr<VappPasswordPage> m_oldPwdPage;
    VfxWeakPtr<VappConfirmPasswordPage> m_newPwdPage;
    VfxWeakPtr<VappSecSetUbchvSeq> m_ubchvSeq;

    void closeChangeChvPages();
    void onOldChvInputted(VappPasswordPage *pwdPage);
    void onNewChvInputted(VappConfirmPasswordPage *confirmPage);
    static mmi_ret onChangePasswordResult(mmi_event_struct *evt);
    void onCancelSelectedOnOldChv(
        VappPasswordPage *page,
        VappPasswordPage::AuxButtonEnum id);
    void onCancelSelectedOnNewChv(
        VappConfirmPasswordPage *page,
        VappConfirmPasswordPage::AuxButtonEnum id);
    void onUbchvDone(VappSecSetPageSeq *pageSeq, VfxS32 result);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onShow();
    virtual VfxBool isDerivedInstance(const VappSecSetChvBaseSeq *seq);

public:
    VappSecSetChangeChvSeq() :
        m_oldPwdPage(NULL),
        m_newPwdPage(NULL),
        m_ubchvSeq(NULL)
    {
    }
};



class VappSecSetVerifyChvSeq : public VappSecSetChvBaseSeq
{
    VFX_DECLARE_CLASS(VappSecSetVerifyChvSeq);

private:
    VfxWeakPtr<VappPasswordPage> m_pwdPage;
    VfxWeakPtr<VappSecSetUbchvSeq> m_ubchvSeq;
    VfxBool m_retryUntilSuccess;
    VfxBool m_backEnabled;

    void onChvInputted(VappPasswordPage *page);
    static mmi_ret onVerifyResult(mmi_event_struct *evt);
    void onCancelSelected(
        VappPasswordPage *pwdPage,
        VappPasswordPage::AuxButtonEnum id);
    void onUbchvDone(VappSecSetPageSeq *pageSeq, VfxS32 result);
    void onEmergencySelected(
        VappPasswordPage *page,
        VappPasswordPage::AuxButtonEnum id);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onShow();
    virtual void onPopupBack(VfxS32 id);
    virtual VfxBool isDerivedInstance(const VappSecSetChvBaseSeq *seq);
    virtual VfxBool shouldBeClosedOnUnavailable(srv_sim_ctrl_ua_cause_enum cause);

public:
    VappSecSetVerifyChvSeq() :
        m_pwdPage(NULL),
        m_ubchvSeq(NULL),
        m_retryUntilSuccess(VFX_FALSE),
        m_backEnabled(VFX_TRUE)
    {
    }

    void setRetryUntilSuccess(VfxBool enabled)
    {
        m_retryUntilSuccess = enabled;
    }

    void setBackEnabled(VfxBool enabled);
};


extern "C"
mmi_ret vapp_secset_hpveri_on_sim_availability_changed(mmi_event_struct *evt);

void vapp_secset_hpveri_try_to_launch(mmi_sim_enum sim);

#endif /* __VAPP_SECSET_CHV_H__ */
