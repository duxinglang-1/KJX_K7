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
 *  vapp_secset_phone.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SECSET_PHONE_H__
#define __VAPP_SECSET_PHONE_H__


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
}


namespace VappSecSetPhone
{
    enum ResultEnum
    {
        RESULT_SUCCESS,
        RESULT_WRONG_PASSWORD,
        RESULT_CANCEL,
        RESULT_GO_BACK,

        RESULT_END_OF_ENUM
    };
}


class VappSecSetPhoneLockSeq : public VappSecSetPageSeq
{
    VFX_DECLARE_CLASS(VappSecSetPhoneLockSeq);

private:
    VfxWeakPtr<VappPasswordPage> m_pwdPage;
    VfxBool m_targetValue;

    void onPasswordInputted(VappPasswordPage *page);
    static mmi_ret onSetPhoneLockResult(mmi_event_struct *evt);
    void onCancelSelected(
        VappPasswordPage *page,
        VappPasswordPage::AuxButtonEnum id);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onShow();

public:
    VappSecSetPhoneLockSeq() : m_pwdPage(NULL), m_targetValue(VFX_FALSE)
    {
    }

    void setTargetValue(VfxBool targetValue)
    {
        m_targetValue = targetValue;
    }
};


class VappSecSetPhoneChangePwdSeq : public VappSecSetPageSeq
{
    VFX_DECLARE_CLASS(VappSecSetPhoneChangePwdSeq);

private:
    VfxWeakPtr<VappPasswordPage> m_oldPwdPage;
    VfxWeakPtr<VappConfirmPasswordPage> m_newPwdPage;

    void onOldPhonePasswordInputted(VappPasswordPage *oldPwdPage);
    static mmi_ret onPhonePasswordVerifyResult(mmi_event_struct *evt);
    void onNewPhonePasswordInputted(VappConfirmPasswordPage *newPwdPage);
    static mmi_ret onChangePasswordResult(mmi_event_struct *evt);
    void onCancelSelectedOnOldPwd(
        VappPasswordPage *page,
        VappPasswordPage::AuxButtonEnum id);
    void onCancelSelectedOnNewPwd(
        VappConfirmPasswordPage *page,
        VappConfirmPasswordPage::AuxButtonEnum id);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onShow();

public:
    VappSecSetPhoneChangePwdSeq() :
        m_oldPwdPage(NULL),
        m_newPwdPage(NULL)
    {
    }
};


class VappSecSetPhoneVerifySeq : public VappSecSetPageSeq
{
    VFX_DECLARE_CLASS(VappSecSetPhoneVerifySeq);

private:
    VfxWeakPtr<VappPasswordPage> m_pwdPage;

    void onPasswordInputted(VappPasswordPage *page);
    static mmi_ret onVerifyResult(mmi_event_struct *evt);
    void onCancelSelected(
        VappPasswordPage *page,
        VappPasswordPage::AuxButtonEnum id);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onShow();

public:
    VappSecSetPhoneVerifySeq() : m_pwdPage(NULL)
    {
    }
};


#endif /* __VAPP_SECSET_PHONE_H__ */
