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
 *  vapp_bootup_security.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Bootup security verify main scr
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_BOOTUP_SEC_H__
#define __VAPP_BOOTUP_SEC_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "MMIDatatype.h"

extern "C"
{
#include "BootupSrvIprot.h"
#include "SimCtrlSrvGprot.h"
}

#include "GlobalResDef.h"
#include "mmi_rp_vapp_bootup_def.h"

#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_weak_ptr.h"
#include "vfx_signal.h"

#include "vcp_confirm_popup.h"
#include "vcp_popup_data_type.h"
#include "vapp_secset_page_seq.h"
#include "vapp_password_page_gprot.h"

/***************************************************************************** 
 * Class VappBootupMustSelectPopup declear
 *****************************************************************************/
class VappBootupMustSelectPopup : public VcpConfirmPopup
{
protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &keyEvt);
};

/***************************************************************************** 
 * Class VappBootupSecMainScr
 *****************************************************************************/
class VappPasswordPage;
class VcpIndicatorPopup;
class VfxBasePopup;
class VappBootupSecPageSeq : public VappSecSetPageSeq
{
public:
    VappBootupSecPageSeq();

// Interface
public:
	VfxBool verifySecurity(mmi_proc_func proc, void *userData);
	mmi_ret processSimStatus(mmi_event_struct *evt);
	
// Override
protected:
	virtual void onInit(void);
	virtual void onDeinit(void);
	virtual void onShow(void);

// Implement
private:  

    /* For verification */   
    void veriClosePages(VfxPage *page1, VfxPage *page2 = NULL);
    void veriPushPage(VfxPage *page);
    VfxBool doNextVerification();
    void veriGoNextStep();
    void veriDisplayPopupAndGoNext(VcpPopupTypeEnum type, const VfxWString &msg);
    void onVeriPopupConfirmedForNext(VfxObject *obj, VfxId id);
    void veriDisplayPopupAndGoBack(VcpPopupTypeEnum type, const VfxWString &msg);
    void onVeriPopupConfirmedForBack(VfxObject *obj, VfxId id);
    void veriDisplayPopupForShutdown(VcpPopupTypeEnum type, const VfxWString &msg);
    void onVeriPopupConfirmedForShutdown(VfxObject *obj, VfxId id);
    
    void verifyPhoneLock();
    void onUserInputtedPhonePwd(VappPasswordPage *pwdPage);
    static void onPhoneLockVerifyResult(
        void *user_data,
        const srv_bootup_verify_result_struct *result);

    void verifySim(mmi_sim_enum sim);
    void verifySimChvOrPer(
        mmi_sim_enum sim,
        srv_bootup_verification_type_enum type,
        VfxS32 nRemainingAttempts);
    void onUserInputtedChvOrPer(VappPasswordPage *pwdPage);
    static void onSimVerifyResult(
        void *user_data,
        const srv_bootup_verify_result_struct *result);
    void verifySimUbchv(
        mmi_sim_enum sim,
        srv_bootup_verification_type_enum type,
        VfxS32 nRemainingAttempts);
    void onUserInputtedUbchv(VappPasswordPage *pwdPage);
    void onUserInputtedNewChv(VappConfirmPasswordPage *pwdPage);
    void showDialerForEmergency();
    static mmi_ret onDialerCuiEvent(mmi_event_struct *evt);
    void onEmergencySelectedOnPwd(
        VappPasswordPage *page,
        VappPasswordPage::AuxButtonEnum aux);
    void onEmergencySelectedOnNewChv(
        VappConfirmPasswordPage *page,
        VappConfirmPasswordPage::AuxButtonEnum aux);

    static mmi_ret onSimStatusChange(mmi_event_struct *evt);	
private:
    
    // Instance for waiting indicator, maintained by showWaiting(), closeWaiting()
    VcpIndicatorPopup *m_waitingInd;

    // Proc pointer for callback
    mmi_proc_func m_callbackProc;
    // User data pointer for callback
    void *m_callbackUserData;

	// Which SIM is in verification
    mmi_sim_enum m_verifyingSim;
    // Verification type, for AT commend verification
    srv_bootup_verification_type_enum m_verifyingType;
    // The number of remaining attempts, for the check of AT commend verification
    VfxS32 m_veriNRemainingAttempts;
    // Fatal error cause of current error popup
    srv_sim_ctrl_ua_cause_enum m_simFatalErrorCause;
    // Begin index of free verification pages
    VfxId m_veriPagesFree;
    // Page for verificaton
    VfxWeakPtr<VappPasswordPage> m_veriPage;
    // Password-confirmation page, used for UBCHV
    VfxWeakPtr<VappConfirmPasswordPage> m_veriCfmPage;
    // Popup instance on verification stage if any
    VfxWeakPtr<VfxBasePopup> m_veriPopup;

};

#endif /* __VAPP_BOOTUP_SEC_H__ */


