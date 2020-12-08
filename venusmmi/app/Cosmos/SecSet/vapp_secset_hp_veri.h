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
 *  vapp_secset_hp_veri.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#include "vfx_datatype.h"
#include "vfx_weak_ptr.h"
#include "vfx_app.h"


/***************************************************************************** 
 * VappSecSetHPVeri
 *****************************************************************************/
class VappSecSetPageSeq;
class VfxMainScr;
class VappSecSetHPVeri : public VfxApp
{
    VFX_DECLARE_CLASS(VappSecSetHPVeri);

private:
    VfxMainScr *m_mainScr;
    VfxWeakPtr<VappSecSetPageSeq> m_actionSeq;
    mmi_sim_enum m_activeSim;
    static VfxBool s_appIsLaunched; // To avoid app from being launched twice
                                    // Set to be true if VfxAppLauncher::launch() is called,
                                    // and reset on app's deinit.
                                    // If VfxAppLauncher::launch() postly executes, s_singletonApp
                                    // may still be NULL even if s_appIsLaunched is already true.
    static VfxBool s_invokedNmgr;
    static VappSecSetHPVeri *s_singletonApp;
	
    static MMI_BOOL runAppFromNmgr(mmi_scenario_id scen_id, void *arg);
	static mmi_ret onEvtHdlr(mmi_event_struct *evt);
	
    VfxBool doNextVerification();
    void onVerifyDone(VappSecSetPageSeq *seqObj, VfxS32 result);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRun(void *args, VfxU32 argSize);

	using VfxApp::onProcessClose;
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

public:
    VappSecSetHPVeri() :
        m_mainScr(NULL),
        m_actionSeq(NULL)
    {
    }

    static VappSecSetHPVeri *getApp();

    static mmi_ret onSimAvailabilityChanged(mmi_event_struct *evt);
	#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
	static void VappSecSetHPVeri::notifySimReady(mmi_sim_enum sim);
	#endif
	
    static void tryToLaunch(mmi_sim_enum sim);
	static VfxBool needVerification();
};

