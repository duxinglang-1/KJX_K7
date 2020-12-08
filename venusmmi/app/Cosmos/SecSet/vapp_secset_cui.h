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
 *  vapp_secset.h
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

#ifndef __VAPP_SECSET_CUI_H__
#define __VAPP_SECSET_CUI_H__


#include "MMI_features.h"
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_secset_def.h"
#include "vapp_password_page_gprot.h"
#include "vapp_secset_page_seq.h"
#include "vcui_secset_gprot.h"
extern "C"
{
#include "MMIDataType.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_trc.h"
}


#define VCUI_SECSET_TRC_GROUP MMI_COMMON_TRC_G7_SETTING


class VcuiSecSetVerify : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiSecSetVerify);

private:
    VfxWeakPtr<VfxMainScr> m_mainScr;
    vcui_verify_fail_cause_enum m_fail_cause;
    vcui_verify_cancel_cause_enum m_cancel_cause;

    class SmallScreen : public VfxAppScr
    {
    public:
        SmallScreen()
        {
            setIsSmallScreen();
        }
    };

    VfxWeakPtr<SmallScreen> m_smallScreenForPopup;

protected:

    VcuiSecSetVerify() :
        m_mainScr(NULL),
        m_fail_cause(VCUI_VERIFY_FAIL_CAUSE_NONE),
        m_cancel_cause(VCUI_VERIFY_CANCEL_CAUSE_USER_CANCEL),
        m_smallScreenForPopup(NULL)
    {
    }
    
    mmi_ret sendToCallerExt(void *evt, VfxBool post = VFX_TRUE);

    void popupAndNotifyFailure(
        const VfxWString &msg,
        vcui_verify_fail_cause_enum cause);
    void onFailureConfirmedToNotify(VfxObject *obj, VfxId id);
    void popupAndNotifyCancel(
        const VfxWString &msg,
        vcui_verify_cancel_cause_enum cause);
    void onCancelConfirmedToNotify(VfxObject *obj, VfxId id);

	using VfxCui::onProcessClose;
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption option);

    void createMainScr()
    {
        if (m_mainScr == NULL)
        {
            VFX_OBJ_CREATE(m_mainScr, VfxMainScr, this);
            m_mainScr->setAutoClose(VFX_FALSE);
        }
    }

    inline VfxMainScr* getMainScr()
    {
        return m_mainScr.get();
    }
    
public:

    static VcuiSecSetVerify* getInstance(mmi_id instance_id);

    virtual void run();
};


class VcuiSecSetVerifyChv : public VcuiSecSetVerify
{
    VFX_DECLARE_CLASS(VcuiSecSetVerifyChv);

private:
    mmi_sim_enum m_sim;
    srv_sim_ctrl_pwd_type_enum m_type;
    VfxWeakPtr<VappSecSetPageSeq> m_verifySeq;

    void onVerifyDone(VappSecSetPageSeq *pageSeq, VfxS32 result);

protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();

public:

    VcuiSecSetVerifyChv() :
#if (MMI_MAX_SIM_NUM >= 2)
        m_sim(MMI_SIM_NONE),
#else
        m_sim(MMI_SIM1),
#endif
        m_type(SRV_SIM_CTRL_PWD_TYPE_NONE),
        m_verifySeq(NULL)
    {
    }

    void setType(srv_sim_ctrl_pwd_type_enum type)
    {
        VFX_ASSERT(type == SRV_SIM_CTRL_PWD_TYPE_CHV1 || type == SRV_SIM_CTRL_PWD_TYPE_CHV2);
        m_type = type;
    }

    void setSim(mmi_sim_enum sim)
    {
        m_sim = sim;
    }

    virtual void run();
};


class VcuiSecSetVerifyPhonePwd : public VcuiSecSetVerify
{
    VFX_DECLARE_CLASS(VcuiSecSetVerifyPhonePwd);

private:
    VfxWeakPtr<VappSecSetPageSeq> m_verifySeq;

    void onVerifyDone(VappSecSetPageSeq *pageSeq, VfxS32 result);

protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();

public:
    VcuiSecSetVerifyPhonePwd() :
        m_verifySeq(NULL)
    {
    }
};


#endif /* __VAPP_SECSET_CUI_H__ */
