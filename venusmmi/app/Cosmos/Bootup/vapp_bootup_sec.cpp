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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_bootup_sec.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Security verification of booting
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "SimCtrlSrvGprot.h"
#include "SecSetSrvGprot.h" /* SRV_SECSET_MIN_PHONE_PASSWORD_LEN */
#include "ShutdownSrvGprot.h"
}

#include "vcui_dialer_gprot.h"

#include "vapp_bootup.h"
#include "vapp_bootup_app.h"
#include "vapp_bootup_sec.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
using namespace VappBootupSimStr;

#define VAPP_BOOTUP_SEC_MAX_PWD_LEN 8

#define VAPP_BOOTUP_WRONG_PERSON_PWD_INIT_TIMEOUT_SEC 30

/*
 * For CTA spec 6.1.2.1
 * If this value is defined and user fails to try the phone password
 * for given number of times, shutdown directly.
 */
#define VAPP_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS 3

/***************************************************************************** 
 * Struct
 *****************************************************************************/
typedef struct
{
    srv_bootup_verification_type_enum type;
    VfxS8 min;
    VfxS8 max;
} vapp_bootup_pwd_length_struct;


/* Minimum length & maximum length of passwords */
static const vapp_bootup_pwd_length_struct g_vapp_bootup_sec_pwd_length[] =
{
    { SRV_BOOTUP_VERI_PHONE_LOCK, SRV_SECSET_MIN_PHONE_PASSWORD_LEN, SRV_SECSET_MAX_PHONE_PASSWORD_LEN },
    { SRV_BOOTUP_VERI_CHV1,     SRV_SIM_CTRL_MIN_CHV_LEN, SRV_SIM_CTRL_MAX_CHV_LEN },
    { SRV_BOOTUP_VERI_UBCHV1,   SRV_SIM_CTRL_MIN_UBCHV_LEN, SRV_SIM_CTRL_MAX_UBCHV_LEN },
#ifdef __SIM_ME_LOCK__
    { SRV_BOOTUP_VERI_NP,       8, 16 },
    { SRV_BOOTUP_VERI_NSP,      8, 16 },
    { SRV_BOOTUP_VERI_SP,       8, 16 },
    { SRV_BOOTUP_VERI_CP,       8, 16 },
    { SRV_BOOTUP_VERI_SIMP,     6, 16 }, /* Min length of PCK should be 6 digits by TS 22.022 */
    { SRV_BOOTUP_VERI_NSSP,     8, 16 },
    { SRV_BOOTUP_VERI_SIMCP,    8, 16 },
#endif /*__SIM_ME_LOCK__*/    
    /* ------------------------------------------------------------------------------ */
    { SRV_BOOTUP_VERI_END_OF_ENUM, 0, 0 }
};

typedef struct
{
    mmi_frm_proc_id_info_struct id_info;
	VfxObjHandle objHandle;
} vapp_bootup_security_cntx_struct;


static vapp_bootup_security_cntx_struct g_vapp_bootup_sec_cntx;

/***************************************************************************** 
 * Local function
 *****************************************************************************/

static VfxBool vapp_bootup_sec_is_need_check(void);
#pragma arm section code = "DYNAMIC_CODE_BOOTUP_ROCODE", rodata = "DYNAMIC_CODE_BOOTUP_RODATA"
static mmi_ret vapp_bootup_sec_on_completed(mmi_event_struct *evt);
/***************************************************************************** 
 * Global function
 *****************************************************************************/
mmi_frm_proc_result_enum vapp_bootup_flow_security(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_FLOW_SECURITY);
	
	if (vapp_bootup_sec_is_need_check())
    {
    	VappBootupApp *app = VappBootupApp::getApp();
		
		vapp_bootup_security_cntx_struct *cntx = &g_vapp_bootup_sec_cntx;
		cntx->id_info = id_info;

		VappBootupSecPageSeq *obj;
		VFX_OBJ_CREATE(obj, VappBootupSecPageSeq, app);

		cntx->objHandle = obj->getObjHandle();
		obj->verifySecurity(vapp_bootup_sec_on_completed, cntx);
		obj->show(app->getMainScr());		

        return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
    }

    return MMI_FRM_PROC_RESULT_COMPLETED;
}

static mmi_ret vapp_bootup_sec_on_completed(mmi_event_struct *evt)
{
    vapp_bootup_security_cntx_struct *cntx =
        static_cast<vapp_bootup_security_cntx_struct*>(evt->user_data);

	VappBootupSecPageSeq *thiz = (VappBootupSecPageSeq *)VfxObject::handleToObject(cntx->objHandle);

	if (thiz != NULL)
	{
		VFX_OBJ_CLOSE(thiz);
	}
	
    mmi_frm_proc_notify_completed(cntx->id_info);

    return MMI_RET_OK;
}
#pragma arm section code, rodata


#ifdef __SIM_ME_LOCK__
static inline VfxBool vapp_bootup_sec_is_personalization(srv_bootup_verification_type_enum type)
{
    switch (type)
    {
        case SRV_BOOTUP_VERI_NP:
        case SRV_BOOTUP_VERI_NSP:
        case SRV_BOOTUP_VERI_SP:
        case SRV_BOOTUP_VERI_CP:
        case SRV_BOOTUP_VERI_SIMP:
        case SRV_BOOTUP_VERI_NSSP:
        case SRV_BOOTUP_VERI_SIMCP:
            return VFX_TRUE;
    }

    return VFX_FALSE;
}
#endif /*__SIM_ME_LOCK__*/

static VfxBool vapp_bootup_sec_is_need_check(void)
{
    if (srv_bootup_phone_lock_is_required())
    {       
        return VFX_TRUE;
    }

    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim;
        sim = srv_sim_ctrl_get_sim_by_index(i);

        if (!srv_bootup_verification_is_passed(sim) &&
            !srv_bootup_veri_is_cancelled(sim))
        {            
            return VFX_TRUE;
        }
    }

	return VFX_FALSE;
}

static VfxBool vapp_bootup_sec_get_length_restriction(
                    srv_bootup_verification_type_enum type,
                    VfxS32 *min_length,
                    VfxS32 *max_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const vapp_bootup_pwd_length_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (entry = g_vapp_bootup_sec_pwd_length;
         entry->type != SRV_BOOTUP_VERI_END_OF_ENUM;
         entry++)
    {
        if (entry->type == type)
        {
            *min_length = entry->min;
            *max_length = entry->max;
            
            return VFX_TRUE;
        }
    }

    *min_length = 4;
    *max_length = VAPP_BOOTUP_SEC_MAX_PWD_LEN;

    return VFX_FALSE;
}

/***************************************************************************** 
 * Class VappBootupMustSelectPopup Implementation
 *****************************************************************************/
VfxBool VappBootupMustSelectPopup::onKeyInput(VfxKeyEvent &keyEvt)
{
    // Close without selection is not allowed
    if (keyEvt.type == VFX_KEY_EVENT_TYPE_DOWN &&
        (keyEvt.keyCode == VFX_KEY_CODE_BACK ||
         keyEvt.keyCode == VFX_KEY_CODE_HOME))
    {
        return VFX_TRUE;
    }

    return VcpConfirmPopup::onKeyInput(keyEvt);
}

/***************************************************************************** 
 * Class VappBootupSecPageSeq Implementation
 *****************************************************************************/
VappBootupSecPageSeq::VappBootupSecPageSeq() :
        m_waitingInd(NULL),
        m_callbackProc(NULL),
        m_callbackUserData(NULL),
        m_verifyingSim(MMI_SIM_NONE),
        m_simFatalErrorCause(SRV_SIM_CTRL_UA_CAUSE_NONE),
        m_veriPagesFree(VappBootupApp::PAGE_VERIFICATION),
        m_veriPage(NULL),
        m_veriCfmPage(NULL),
        m_veriPopup(NULL)
{
}

void VappBootupSecPageSeq::onInit(void)
{
	VappSecSetPageSeq::onInit();

    mmi_frm_cb_reg_event(EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED, 
						&VappBootupSecPageSeq::onSimStatusChange, 
						getObjHandle());
}


void VappBootupSecPageSeq::onDeinit(void)
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED, 
						  &VappBootupSecPageSeq::onSimStatusChange, 
						  getObjHandle());

	VappSecSetPageSeq::onDeinit();
}

void VappBootupSecPageSeq::onShow(void)
{
	doNextVerification();
}

VfxBool VappBootupSecPageSeq::verifySecurity(mmi_proc_func proc, void *userData)
{
    m_callbackProc = proc;
    m_callbackUserData = userData;

    return VFX_FALSE;
}


void VappBootupSecPageSeq::veriClosePages(VfxPage *page1, VfxPage *page2)
{
    if (page1 != NULL)
    {
        getMainScr()->closePage(page1->getId());
    }
    if (page2 != NULL)
    {
        getMainScr()->closePage(page2->getId());
    }
}


void VappBootupSecPageSeq::veriPushPage(VfxPage *page)
{
    getMainScr()->pushPage(m_veriPagesFree, page);
    m_veriPagesFree++;
}


VfxBool VappBootupSecPageSeq::doNextVerification()
{
    // Close pages in background, otherwise user will see the back
    // animation effect.
    VfxPage *toBeClosedPage1 = m_veriPage.get();
    VfxPage *toBeClosedPage2 = m_veriCfmPage.get();
    m_veriPage = NULL;
    m_veriCfmPage = NULL;
    
    m_verifyingSim = MMI_SIM_NONE;
    m_verifyingType = SRV_BOOTUP_VERI_NONE;
    m_veriNRemainingAttempts = 0;

    if (srv_bootup_phone_lock_is_required())
    {
        verifyPhoneLock();
        veriClosePages(toBeClosedPage1, toBeClosedPage2);
        
        return VFX_TRUE;
    }

    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim;
        sim = srv_sim_ctrl_get_sim_by_index(i);

        if (!srv_bootup_verification_is_passed(sim) &&
            !srv_bootup_veri_is_cancelled(sim))
        {
            verifySim(sim);
            veriClosePages(toBeClosedPage1, toBeClosedPage2);
            
            return VFX_TRUE;
        }
    }

    
    return VFX_FALSE;
}


void VappBootupSecPageSeq::veriDisplayPopupAndGoNext(VcpPopupTypeEnum type, const VfxWString &msg)
{
    if (m_veriPopup.isValid())
    {
        m_veriPopup->exit(VFX_TRUE);
    }

    VcpConfirmPopup *confirmPopup;
    
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, getMainScr());
    confirmPopup->setInfoType(type);
    confirmPopup->setText(msg);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->setAutoDestory(VFX_TRUE);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappBootupSecPageSeq::onVeriPopupConfirmedForNext);

    m_veriPopup = confirmPopup;
}


void VappBootupSecPageSeq::veriGoNextStep()
{
    if (!doNextVerification())
    {
        if (m_veriPage.isValid())
        {
            m_veriPage->setIsDisabled(VFX_TRUE);
        }
        if (m_veriCfmPage.isValid())
        {
            m_veriCfmPage->setIsDisabled(VFX_TRUE);
        }

        m_verifyingSim = MMI_SIM_NONE;
        m_simFatalErrorCause = SRV_SIM_CTRL_UA_CAUSE_NONE;

		if (m_callbackProc != NULL)
		{
	        mmi_event_struct completed_evt;
	        mmi_proc_func proc = m_callbackProc;
	        void *user_data = m_callbackUserData;
	        m_callbackProc = NULL;
	        
	        MMI_FRM_INIT_EVENT(&completed_evt, 3);
	        MMI_FRM_SEND_EVENT(&completed_evt, proc, user_data);
		}
		else
		{
			notifyDone(0);
		}
    }
}


void VappBootupSecPageSeq::onVeriPopupConfirmedForNext(VfxObject *obj, VfxId id)
{
    m_simFatalErrorCause = SRV_SIM_CTRL_UA_CAUSE_NONE;
    veriGoNextStep();
}


void VappBootupSecPageSeq::veriDisplayPopupAndGoBack(VcpPopupTypeEnum type, const VfxWString &msg)
{
    VcpConfirmPopup *confirmPopup;

    if (m_veriPopup.isValid())
    {
        m_veriPopup->exit(VFX_TRUE);
    }
    
    VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, getMainScr());
    confirmPopup->setInfoType(type);
    confirmPopup->setText(msg);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappBootupSecPageSeq::onVeriPopupConfirmedForBack);

    m_veriPopup = confirmPopup;
}


void VappBootupSecPageSeq::onVeriPopupConfirmedForBack(VfxObject *obj, VfxId id)
{
    if (m_veriCfmPage.isValid())
    {
        getMainScr()->closePage(m_veriCfmPage->getId());
        m_veriCfmPage = NULL;
    }

    if (m_veriPage.isValid())
    {
        srv_bootup_verification_type_enum type = SRV_BOOTUP_VERI_NONE;

#ifdef VAPP_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS
        if (m_verifyingType == SRV_BOOTUP_VERI_PHONE_LOCK)
        {
            VfxWString remainingMsg = getRemainingPromptStr(m_veriNRemainingAttempts, getMainScr());
            m_veriPage->setExtraMessage(remainingMsg);
        }
        else
#endif
        if (m_verifyingSim != MMI_SIM_NONE)
        {
            type = srv_bootup_get_verification_info(m_verifyingSim, &m_veriNRemainingAttempts);
        
            if (type != SRV_BOOTUP_VERI_NONE &&
                m_veriNRemainingAttempts != SRV_BOOTUP_ATTEMPT_INFINITE_NUMBER)
            {
                VfxWString remainingMsg = getRemainingPromptStr(m_veriNRemainingAttempts, getMainScr());
                m_veriPage->setExtraMessage(remainingMsg);

#if defined(__MMI_SML_UNLOCK_RETRY_TIMER__) && defined(__SIM_ME_LOCK__)
                if (vapp_bootup_sec_is_personalization(type))
                {
                    VfxS32 nAlreadyTrials = SRV_BOOTUP_MAX_PERSONALIZATION_TRIAL_NUM - m_veriNRemainingAttempts;
                    if (nAlreadyTrials > 0)
                    {
                        VfxS32 waitSec = (1 << (nAlreadyTrials - 1)) * VAPP_BOOTUP_WRONG_PERSON_PWD_INIT_TIMEOUT_SEC;
                        m_veriPage->disableDoneButtonForMsec(waitSec * 1000);
                    }
                }
#endif /*(__MMI_SML_UNLOCK_RETRY_TIMER__) && defined(__SIM_ME_LOCK__)*/
            }

            m_simFatalErrorCause = SRV_SIM_CTRL_UA_CAUSE_NONE;
        }

        m_veriPage->clearInput();
        m_veriPage->activateEditor();
    }
}


void VappBootupSecPageSeq::veriDisplayPopupForShutdown(VcpPopupTypeEnum type, const VfxWString &msg)
{
    VcpConfirmPopup *confirmPopup;

    if (m_veriPopup.isValid())
    {
        m_veriPopup->exit(VFX_TRUE);
    }
    
    VFX_OBJ_CREATE(confirmPopup, VappBootupMustSelectPopup, getMainScr());
    confirmPopup->setInfoType(type);
    confirmPopup->setText(msg);
    confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirmPopup->setCustomButton(
        VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_POWER_OFF),
        VFX_WSTR_NULL,
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_NORMAL);
    confirmPopup->show(VFX_TRUE);
    confirmPopup->m_signalButtonClicked.connect(this, &VappBootupSecPageSeq::onVeriPopupConfirmedForShutdown);

    m_veriPopup = confirmPopup;
}


void VappBootupSecPageSeq::onVeriPopupConfirmedForShutdown(VfxObject *obj, VfxId id)
{
    srv_shutdown_normal_start(VAPP_BOOTUP);
}


void VappBootupSecPageSeq::verifyPhoneLock()
{
    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_VERIFY_PHONE_LOCK);

    m_verifyingSim = MMI_SIM_NONE;
    m_verifyingType = SRV_BOOTUP_VERI_PHONE_LOCK;

    VFX_OBJ_CREATE(m_veriPage, VappPasswordPage, getMainScr());
    VfxS32 minPwdLen, maxPwdLen;
    vapp_bootup_sec_get_length_restriction(SRV_BOOTUP_VERI_PHONE_LOCK, &minPwdLen, &maxPwdLen);
    m_veriPage->setLengthRestriction(minPwdLen, maxPwdLen);
    m_veriPage->setPrompt(VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_INPUT_PHONE_PASSWORD));
    m_veriPage->setAllowDelete(VFX_FALSE);
    m_veriPage->m_signalDone.connect(this, &VappBootupSecPageSeq::onUserInputtedPhonePwd);

#ifdef VAPP_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS
    m_veriNRemainingAttempts = VAPP_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS;
    VfxWString remainingMsg = getRemainingPromptStr(m_veriNRemainingAttempts, getMainScr());
    m_veriPage->setExtraMessage(remainingMsg);
#endif
    
    m_veriPage->setAuxButton(
        VappPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_EMERGENCY),
        VappPasswordPage::AUX_TYPE_CRITICAL);
    m_veriPage->m_signalAuxSelected.connect(this, &VappBootupSecPageSeq::onEmergencySelectedOnPwd);

    veriPushPage(m_veriPage.get());

    m_veriPage->activateEditor();
}


void VappBootupSecPageSeq::onUserInputtedPhonePwd(VappPasswordPage *pwdPage)
{
    showWaiting();

    srv_bootup_verify_phone_lock(
        pwdPage->getInput(),
        &VappBootupSecPageSeq::onPhoneLockVerifyResult,
        getObjHandle());
}


void VappBootupSecPageSeq::onPhoneLockVerifyResult(
    void *user_data,
    const srv_bootup_verify_result_struct *result)
{
    VappBootupSecPageSeq *obj = (VappBootupSecPageSeq *)handleToObject((VfxObjHandle)user_data);

	if (obj == NULL)
	{
		return;
	}

    obj->closeWaiting();

    if (result->success)
    {
        obj->veriGoNextStep();
    }
    else
    {
#ifdef VAPP_BOOTUP_SEC_MAX_PHONE_PWD_ATTEMPTS
            
        obj->m_veriNRemainingAttempts--;

        if (obj->m_veriNRemainingAttempts > 0)
        {
            // # of remaining attempts will be updated after user confirmed on the popup
            VfxWString prompt = getMessageOfResult(result);
            VfxWString failureMsg = getFailureMsgWithRemaining(
                prompt,
                obj->m_veriNRemainingAttempts,
                obj);
			
            obj->veriDisplayPopupAndGoBack(VCP_POPUP_TYPE_FAILURE, failureMsg);
        }
        else
        {
            obj->veriDisplayPopupForShutdown(
                VCP_POPUP_TYPE_FAILURE,
                getMessageOfResult(result));
        }
        
#else

        obj->veriDisplayPopupAndGoBack(
            VCP_POPUP_TYPE_FAILURE,
            VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_WRONG_PHONE_PASSWORD));
            
#endif
    }
}


void VappBootupSecPageSeq::verifySim(mmi_sim_enum sim)
{
    m_verifyingSim = sim;
    m_verifyingType = srv_bootup_get_verification_info(sim, &m_veriNRemainingAttempts);
    m_simFatalErrorCause = SRV_SIM_CTRL_UA_CAUSE_NONE;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_VERIFY_SIM, m_verifyingSim, m_verifyingType);

    switch (m_verifyingType)
    {
        case SRV_BOOTUP_VERI_CHV1: 
#ifdef __SIM_ME_LOCK__            
        case SRV_BOOTUP_VERI_NP:
        case SRV_BOOTUP_VERI_NSP:
        case SRV_BOOTUP_VERI_SP:
        case SRV_BOOTUP_VERI_CP:
        case SRV_BOOTUP_VERI_SIMP:
        case SRV_BOOTUP_VERI_NSSP:
        case SRV_BOOTUP_VERI_SIMCP:
#endif /*__SIM_ME_LOCK__*/            
            verifySimChvOrPer(
                sim,
                m_verifyingType,
                m_veriNRemainingAttempts);
            break;

        case SRV_BOOTUP_VERI_UBCHV1:
            verifySimUbchv(
                sim,
                m_verifyingType,
                m_veriNRemainingAttempts);
            break;

        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappBootupSecPageSeq::verifySimChvOrPer(
    mmi_sim_enum sim,
    srv_bootup_verification_type_enum type,
    VfxS32 nRemainingAttempts)
{
    VFX_OBJ_CREATE(m_veriPage, VappPasswordPage, getMainScr());
    
    VfxS32 minPwdLen, maxPwdLen;
    vapp_bootup_sec_get_length_restriction(type, &minPwdLen, &maxPwdLen);
    m_veriPage->setLengthRestriction(minPwdLen, maxPwdLen);
    
    m_veriPage->setPrompt(getInputPrompt(sim, type));
    
    VfxWString remainingMsg = getRemainingPromptStr(nRemainingAttempts, getMainScr());
    m_veriPage->setExtraMessage(remainingMsg);
    
    m_veriPage->m_signalDone.connect(this, &VappBootupSecPageSeq::onUserInputtedChvOrPer);
    m_veriPage->setAuxButton(
        VappPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_EMERGENCY),
        VappPasswordPage::AUX_TYPE_CRITICAL);
    m_veriPage->m_signalAuxSelected.connect(this, &VappBootupSecPageSeq::onEmergencySelectedOnPwd);
    m_veriPage->setAllowDelete(VFX_FALSE);
    
    veriPushPage(m_veriPage.get());
    
    m_veriPage->activateEditor();
}


void VappBootupSecPageSeq::onUserInputtedChvOrPer(VappPasswordPage *pwdPage)
{
    showWaiting();

    srv_bootup_verify(
        m_verifyingSim,
        pwdPage->getInput(),
        &VappBootupSecPageSeq::onSimVerifyResult,
        getObjHandle());
}


void VappBootupSecPageSeq::onSimVerifyResult(
    void *user_data,
    const srv_bootup_verify_result_struct *result)
{
    VappBootupSecPageSeq *obj = (VappBootupSecPageSeq*)handleToObject((VfxObjHandle)user_data);

    if (obj == NULL) return;

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_ON_SIM_VERIFY_RESULT,
        result->success, result->sim, result->fatal_error, result->n_remaining_attempts);

    obj->closeWaiting();

    if (result->success)
    {
        obj->veriGoNextStep();
    }
    else if (!result->fatal_error && result->n_remaining_attempts > 0)
    {
        // # of remaining attempts will be updated after user confirmed on the popup
        VfxWString prompt = getMessageOfResult(result);
        VfxWString failureMsg = getFailureMsgWithRemaining(
            prompt,
            result->n_remaining_attempts,
            obj);
        obj->veriDisplayPopupAndGoBack(VCP_POPUP_TYPE_FAILURE, failureMsg);
        obj->m_veriNRemainingAttempts = result->n_remaining_attempts;
    }
    else
    {
        srv_sim_ctrl_ua_cause_enum cause = srv_sim_ctrl_get_unavailable_cause(result->sim);
        VfxWString errorMsg = getSimErrorMsg(result->sim, cause);

        // User cause PIN blocked and need to show UBCHV
        if (result->type == SRV_BOOTUP_VERI_CHV1)
        {
            if (srv_bootup_get_verification_info(result->sim, NULL) == SRV_BOOTUP_VERI_UBCHV1)
            {
                // Show UBCHV first, let the behavior sync with security setting
                obj->doNextVerification();
                obj->m_simFatalErrorCause = cause;
                obj->veriDisplayPopupAndGoBack(
                    VCP_POPUP_TYPE_FAILURE,
                    errorMsg);
                return;
            }
            else
            {
                errorMsg = getSimErrorMsg(result->sim, SRV_SIM_CTRL_UA_CAUSE_UBCHV1_BLOCKED);
            }
        }

        obj->m_simFatalErrorCause = cause;
        obj->veriDisplayPopupAndGoNext(
            VCP_POPUP_TYPE_FAILURE,
            errorMsg);
    }
}


void VappBootupSecPageSeq::verifySimUbchv(
    mmi_sim_enum sim,
    srv_bootup_verification_type_enum type,
    VfxS32 nRemainingAttempts)
{
    VFX_ASSERT(type == SRV_BOOTUP_VERI_UBCHV1);

    VFX_OBJ_CREATE(m_veriPage, VappPasswordPage, getMainScr());
    
    VfxS32 minPwdLen, maxPwdLen;
    vapp_bootup_sec_get_length_restriction(type, &minPwdLen, &maxPwdLen);
    m_veriPage->setLengthRestriction(minPwdLen, maxPwdLen);
    
    m_veriPage->setPrompt(getInputPrompt(sim, type));
    
    VfxWString remainingMsg = getRemainingPromptStr(nRemainingAttempts, getMainScr());
    m_veriPage->setExtraMessage(remainingMsg);
    
    m_veriPage->m_signalDone.connect(this, &VappBootupSecPageSeq::onUserInputtedUbchv);
    m_veriPage->setAuxButton(
        VappPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_EMERGENCY),
        VappPasswordPage::AUX_TYPE_CRITICAL);
    m_veriPage->m_signalAuxSelected.connect(this, &VappBootupSecPageSeq::onEmergencySelectedOnPwd);
    m_veriPage->setAllowDelete(VFX_FALSE);
        
    veriPushPage(m_veriPage.get());
    
    m_veriPage->activateEditor();
}


void VappBootupSecPageSeq::onUserInputtedUbchv(VappPasswordPage *pwdPage)
{
    VFX_OBJ_CREATE(m_veriCfmPage, VappConfirmPasswordPage, getMainScr());
    
    VfxS32 minPwdLen, maxPwdLen;
    vapp_bootup_sec_get_length_restriction(SRV_BOOTUP_VERI_CHV1, &minPwdLen, &maxPwdLen);
    m_veriCfmPage->setLengthRestriction(minPwdLen, maxPwdLen);

#if (MMI_MAX_SIM_NUM >= 2)
    if (srv_sim_ctrl_get_num_of_inserted() >= 2)
    {
        m_veriCfmPage->setPrompt(
            composeSimStr(STR_ID_VAPP_BOOTUP_SIMX_NEW_CHV1, m_verifyingSim),
            VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_CONFIRM_NEW_CHV1));
    }
    else
#endif
    {
        m_veriCfmPage->setPrompt(
            VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_NEW_CHV1),
            VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_CONFIRM_NEW_CHV1));
    }
        
    m_veriCfmPage->setDiffInputPrompt(VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_CHV1_NOT_MATCH));
    m_veriCfmPage->m_signalDone.connect(this, &VappBootupSecPageSeq::onUserInputtedNewChv);
    
    m_veriCfmPage->setAuxButton(
        VappConfirmPasswordPage::AUX_BUTTON_DEFAULT,
        VFX_WSTR_RES(STR_ID_VAPP_BOOTUP_EMERGENCY),
        VappConfirmPasswordPage::AUX_TYPE_CRITICAL);
    m_veriCfmPage->m_signalAuxSelected.connect(this, &VappBootupSecPageSeq::onEmergencySelectedOnNewChv);
    
    veriPushPage(m_veriCfmPage.get());
    
    m_veriCfmPage->activateEditor();
}


void VappBootupSecPageSeq::onUserInputtedNewChv(VappConfirmPasswordPage *confirmPage)
{
    showWaiting();

    srv_bootup_verify_ubchv(
        m_verifyingSim,
        m_veriPage->getInput(),
        confirmPage->getInput(),
        &VappBootupSecPageSeq::onSimVerifyResult,
        getObjHandle());
}


void VappBootupSecPageSeq::showDialerForEmergency()
{
    mmi_id dialer_cui = vcui_dialer_create_ex(getMainScr()->getGroupId(), VCUI_DIALER_TYPE_EMERGENCY);
    vcui_dialer_set_dial_string(dialer_cui, VFX_WSTR("112"));
    mmi_frm_group_set_caller_proc(dialer_cui, &VappBootupSecPageSeq::onDialerCuiEvent, getObjHandle());
    vcui_dialer_run(dialer_cui);
}


mmi_ret VappBootupSecPageSeq::onDialerCuiEvent(mmi_event_struct *evt)
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


void VappBootupSecPageSeq::onEmergencySelectedOnPwd(
    VappPasswordPage *page,
    VappPasswordPage::AuxButtonEnum aux)
{
    showDialerForEmergency();
}


void VappBootupSecPageSeq::onEmergencySelectedOnNewChv(
    VappConfirmPasswordPage *page,
    VappConfirmPasswordPage::AuxButtonEnum aux)
{
    showDialerForEmergency();
}

mmi_ret VappBootupSecPageSeq::onSimStatusChange(mmi_event_struct *evt)
{
	VappBootupSecPageSeq *obj;

	obj = (VappBootupSecPageSeq *)handleToObject((VfxObjHandle)evt->user_data);
	
    if (obj != NULL)
    {
        return obj->processSimStatus(evt);
    }

    return MMI_RET_OK;
}


mmi_ret VappBootupSecPageSeq::processSimStatus(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_sim_status_changed_evt_struct *status_changed_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(evt->evt_id == EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED);

    status_changed_evt = reinterpret_cast<srv_bootup_sim_status_changed_evt_struct*>(evt);

    MMI_TRACE(VAPP_BOOTUP_TRC_GROUP, TRC_VAPP_BOOTUP_ON_SIM_STATUS_CHANGED,
        m_verifyingSim, status_changed_evt->sim, status_changed_evt->fatal_error);
    
    if (m_verifyingSim == status_changed_evt->sim)
    {
        if (status_changed_evt->fatal_error)
        {
            /* Close the verification screen and do another verification */
            srv_sim_ctrl_ua_cause_enum cause = srv_sim_ctrl_get_unavailable_cause(status_changed_evt->sim);
            if (cause != m_simFatalErrorCause)
            {
            	/*
                veriDisplayPopupAndGoNext(
                    VCP_POPUP_TYPE_FAILURE,
                    getSimErrorMsg(status_changed_evt->sim, cause));
				*/
				if (m_veriPopup.isValid())
				{
					m_veriPopup->exit(VFX_TRUE);
				}

				m_simFatalErrorCause = SRV_SIM_CTRL_UA_CAUSE_NONE;
				veriGoNextStep();

            }
        }
        else
        {
            srv_bootup_verify_result_struct veri_result;
            srv_bootup_verification_type_enum veri_type;
            S32 n_remaining_attempts;

            /*
             * [MAUI_02283184] Feature: verify CHV1/UBCHV1 via AT command
             * Generate a result for current verification, to trigger
             * following UI actions.
             */
            veri_type = srv_bootup_get_verification_info(
                status_changed_evt->sim,
                &n_remaining_attempts);
                
            veri_result.sim = status_changed_evt->sim;
            veri_result.type = m_verifyingType;
            veri_result.success = MMI_FALSE;
            veri_result.fatal_error = status_changed_evt->fatal_error;
            veri_result.n_remaining_attempts = n_remaining_attempts;
            
            if (m_verifyingType != veri_type)
            {
                if (veri_type == SRV_BOOTUP_VERI_NONE)
                {
                    veri_result.success = MMI_TRUE;
                }
                else if (veri_type == SRV_BOOTUP_VERI_UBCHV1 &&
                    m_verifyingType == SRV_BOOTUP_VERI_CHV1)
                {
                    veri_result.success = MMI_FALSE;
                    veri_result.n_remaining_attempts = 0;
                }
                else
                {
                    /* Another veri_type is required */
                    veri_result.success = MMI_TRUE;
                }
            }
            else if (n_remaining_attempts < m_veriNRemainingAttempts)
            {
                veri_result.success = MMI_FALSE;
            }
            else if (n_remaining_attempts == m_veriNRemainingAttempts)
            {
                /* Do nothing */
                return MMI_RET_OK;
            }
            else
            {
                /* Impossible: veri_type is the same, but n_remaining_attempts increased */
                VFX_ASSERT(0);
            }

            if (m_veriPopup.isValid())
            {
                m_veriPopup->exit(VFX_TRUE);
                m_veriPopup = NULL;
            }

            onSimVerifyResult(getObjHandle(), &veri_result);
        }
    }

    return MMI_RET_OK;
}


