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
 *  vapp_secset_hp_veri.cpp
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
#include "MMI_features.h"

extern "C"
{
#include "GlobalResDef.h"
#include "BootupSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NotificationGprot.h"
#include "GpioSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
}

#include "mmi_rp_vapp_secset_hpveri_def.h"
#include "vfx_main_scr.h"

#include "vapp_secset.h"
#include "vapp_secset_chv.h"
#include "vapp_secset_str.h"
#include "vapp_ncenter_gprot.h"
#include "vapp_ncenter.h"
#include "vapp_bootup_sec.h"

#include "vapp_secset_hp_veri.h"

using namespace VappSecSetStr;


/***************************************************************************** 
 * Include
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSecSetHPVeri", VappSecSetHPVeri, VfxApp);

VfxBool VappSecSetHPVeri::s_appIsLaunched = VFX_FALSE;
VfxBool VappSecSetHPVeri::s_invokedNmgr = VFX_FALSE;
VappSecSetHPVeri* VappSecSetHPVeri::s_singletonApp = NULL;

void VappSecSetHPVeri::onInit()
{
    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_HPVERIFY_ON_INIT);

    VFX_ASSERT(s_singletonApp == NULL);
    s_singletonApp = this;
    s_appIsLaunched = VFX_TRUE;

    // Set not to be shown in out-of-memory list
    mmi_frm_asm_property_struct property;
    if (mmi_frm_asm_get_property(getGroupId(), &property))
    {
        property.f_hide_in_oom = 1;
        mmi_frm_asm_set_property(getGroupId(), &property);
    }

    mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);

    // Non-public API, only for highest-priority verification
    VappNCenter *nCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    nCenter->setDisableDrag(VFX_TRUE);

	mmi_frm_cb_reg_event(EVT_ID_GPIO_BACKLIGHT_DIMMING, VappSecSetHPVeri::onEvtHdlr, getObjHandle());
	mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VappSecSetHPVeri::onEvtHdlr, getObjHandle());

}


void VappSecSetHPVeri::onDeinit()
{
    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_HPVERIFY_ON_DEINIT);

    VFX_ASSERT(s_singletonApp == this);
    s_singletonApp = NULL;
    s_appIsLaunched = VFX_FALSE;

    if (m_actionSeq.isValid())
    {
        VFX_OBJ_CLOSE(m_actionSeq);
    }

    // Non-public API, only for highest-priority verification
    VappNCenter *nCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    nCenter->setDisableDrag(VFX_FALSE);

    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);

	mmi_frm_cb_dereg_event(EVT_ID_GPIO_BACKLIGHT_DIMMING, VappSecSetHPVeri::onEvtHdlr, getObjHandle());
	mmi_frm_cb_dereg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, VappSecSetHPVeri::onEvtHdlr, getObjHandle());
}


mmi_ret VappSecSetHPVeri::onEvtHdlr(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_GPIO_BACKLIGHT_DIMMING:
		case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
			return MMI_RET_ERR;

		default:
			break;
	}
	
	return MMI_RET_OK;
}


VappSecSetHPVeri *VappSecSetHPVeri::getApp()
{
    return s_singletonApp;
}

void VappSecSetHPVeri::onRun(void *args, VfxU32 argSize)
{
    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_HPVERIFY_ON_RUN);

    VFX_OBJ_CREATE(m_mainScr, VfxMainScr, this);
    
    doNextVerification();
    m_mainScr->setAutoClose(VFX_FALSE);
    m_mainScr->show();
    m_mainScr->setAllowDelete(VFX_FALSE);
}

VfxAppCloseAnswerEnum VappSecSetHPVeri::onProcessClose(VfxAppCloseOption option)
{
    return VFX_APP_CLOSE_ANSWER_NO; /* Not allow closing */
}

VfxBool VappSecSetHPVeri::needVerification()
{
    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = srv_sim_ctrl_get_sim_by_index(i);
        srv_sim_ctrl_ua_cause_enum ua_cause = srv_sim_ctrl_get_unavailable_cause(sim);

        switch (ua_cause)
        {
            case SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED:
                return VFX_TRUE;

            case SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED:
                return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


MMI_BOOL VappSecSetHPVeri::runAppFromNmgr(mmi_scenario_id scen_id, void *arg)
{
    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_HPVERIFY_RUN_FROM_NMGR, s_appIsLaunched);

    s_invokedNmgr = VFX_FALSE;

    // SIM status may change when NMGR call back, so we also need check the newest
    // status by needVerification()
    if (!s_appIsLaunched && needVerification())
    {
        // to avoid runAppFromNmgr invoked twice from NMGR for different SIM events
        s_appIsLaunched = VFX_TRUE;

        MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_HPVERIFY_LAUNCH_APP);
        
        VfxAppLauncher::launch(
            VAPP_SECSET_HPVERI,
            VFX_OBJ_CLASS_INFO(VappSecSetHPVeri),
            GRP_ID_ROOT);

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


VfxBool VappSecSetHPVeri::doNextVerification()
{
    for (VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum sim = srv_sim_ctrl_get_sim_by_index(i);
        srv_sim_ctrl_ua_cause_enum ua_cause = srv_sim_ctrl_get_unavailable_cause(sim);
		
		ua_cause = srv_sim_ctrl_get_unavailable_cause(sim);
		
		if (srv_sim_ctrl_is_initializing(sim))
		{
			VappBootupSecPageSeq *bootupSecSeq;
			
			VFX_OBJ_CREATE(bootupSecSeq, VappBootupSecPageSeq, this);
			bootupSecSeq->m_signalDone.connect(this, &VappSecSetHPVeri::onVerifyDone);
			bootupSecSeq->show(m_mainScr);

			return VFX_TRUE;
		}
        else if (ua_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
        {
            VappSecSetUbchvSeq *ubchvSeq;
            VFX_OBJ_CREATE(ubchvSeq, VappSecSetUbchvSeq, this);
            ubchvSeq->setSimAndType(sim, SRV_SIM_CTRL_PWD_TYPE_UBCHV1);
            ubchvSeq->setBackEnabled(VFX_FALSE);
            ubchvSeq->m_signalDone.connect(this, &VappSecSetHPVeri::onVerifyDone);
            ubchvSeq->show(m_mainScr);
            
            m_actionSeq = ubchvSeq;
            m_activeSim = sim;

            MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_HPVERIFY_DO_NEXT_VERI, sim, ua_cause);
            return VFX_TRUE;
        }
        else if (ua_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED)
        {
            VappSecSetVerifyChvSeq *verifySeq;
            VFX_OBJ_CREATE(verifySeq, VappSecSetVerifyChvSeq, this);
            verifySeq->setSimAndType(sim, SRV_SIM_CTRL_PWD_TYPE_CHV1);
            verifySeq->setRetryUntilSuccess(VFX_TRUE);
            verifySeq->setBackEnabled(VFX_FALSE);
            verifySeq->m_signalDone.connect(this, &VappSecSetHPVeri::onVerifyDone);
            verifySeq->show(m_mainScr);

            m_actionSeq = verifySeq;
            m_activeSim = sim;

            MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_HPVERIFY_DO_NEXT_VERI, sim, ua_cause);
            return VFX_TRUE;
        }
    }


    MMI_TRACE(VAPP_SECSET_TRC_GROUP, TRC_VAPP_SECSET_HPVERIFY_DO_NEXT_VERI, MMI_SIM_NONE, 0);
    return VFX_FALSE;
}


void VappSecSetHPVeri::onVerifyDone(VappSecSetPageSeq *seqObj, VfxS32 result)
{
    mmi_sim_enum sim = MMI_SIM_NONE;
    srv_sim_ctrl_pwd_type_enum chv_type = SRV_SIM_CTRL_PWD_TYPE_NONE;

    VappSecSetChvBaseSeq *baseSeq = VFX_OBJ_DYNAMIC_CAST(seqObj, VappSecSetChvBaseSeq);
    if (baseSeq != NULL)
    {
        sim = baseSeq->getSim();
        chv_type = baseSeq->getType();
    }

    if (!doNextVerification())
    {
    	/*
    	 * [MAUI_02650219]
    	 * Leave seqObj to be closed by app deinit. Otherwise we may see an empty
    	 * page on the app destory animation.
		 */
        exit();
    }
    else
    {
        VFX_OBJ_CLOSE(seqObj);
    }

    if (sim != MMI_SIM_NONE && result == VappSecSetChv::RESULT_SUCCESS)
    {
        if (chv_type == SRV_SIM_CTRL_PWD_TYPE_UBCHV1)
        {
            VfxWString msgStr = getChvStr(sim, chv_type, STR_CHV_UNBLOCKED);
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_HIGHEST_SCRN,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_SUCCESS,
                msgStr.getBuf());
        }
        else if (chv_type == SRV_SIM_CTRL_PWD_TYPE_CHV1)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_HIGHEST_SCRN,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_SUCCESS,
                VFX_WSTR_RES(STR_GLOBAL_DONE).getBuf());
        }
    }
}


mmi_ret VappSecSetHPVeri::onSimAvailabilityChanged(mmi_event_struct *evt)
{
    srv_sim_ctrl_availability_changed_evt_struct *change_evt =
        reinterpret_cast<srv_sim_ctrl_availability_changed_evt_struct*>(evt);

    if (!srv_bootup_is_completed())
    {
        return MMI_RET_OK;
    }

    VappSecSetHPVeri *app = getApp();

    MMI_TRACE(VAPP_SECSET_TRC_GROUP, 
			  TRC_VAPP_SECSET_HPVERIFY_DO_AVAI_CHANGED,
        	  change_evt->sim,
        	  change_evt->unavailable_cause,
        	  change_evt->unavailable_cause_before,
        	  change_evt->is_available_now,
        	  change_evt->is_available_before,
        	  s_appIsLaunched,
        	  (VfxU32)app);
    
    switch (change_evt->unavailable_cause)
    {
        case SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED:
        case SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED:
            if (!s_appIsLaunched)
            {
                if (!s_invokedNmgr)
                {
                    s_invokedNmgr = VFX_TRUE;
                    mmi_frm_nmgr_notify_by_app(
                        MMI_SCENARIO_ID_HIGHEST_SCRN,
                        MMI_EVENT_SIM_VERIFICATION,
                        runAppFromNmgr,
                        NULL);
                }
            }
            else if (app != NULL) // app is running
            {
                if (app->m_activeSim == change_evt->sim)
                {
                    // Do nothing, being processed by the app instance
                }
                else if (change_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED)
                {
                    VfxWString msgStr = getChvStr(change_evt->sim, SRV_SIM_CTRL_PWD_TYPE_CHV1, STR_CHV_BLOCKED);
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_HIGHEST_SCRN,
                        MMI_EVENT_SIM_VERIFICATION,
                        MMI_NMGR_BALLOON_TYPE_INFO,
                        const_cast<VfxWChar*>(msgStr.getBuf()));
                }
            }
            break;			
		
        default:
            break;
    }
	
#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
	if (change_evt->is_available_now && !change_evt->is_available_before)
	{
		notifySimReady(change_evt->sim);
	}
#endif //__SIM_HOT_SWAP_SUPPORT__

    return MMI_RET_OK;
}

#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
void VappSecSetHPVeri::notifySimReady(mmi_sim_enum sim)
{
	VfxWString simReadyStr;
	
#if (MMI_MAX_SIM_NUM >= 2)
	simReadyStr = composeSimStr(STR_ID_VAPP_SECSET_SIMX_READY, sim);
#else
    simReadyStr.loadFromRes(STR_ID_VAPP_SECSET_SIM_READY);
#endif /* (MMI_MAX_SIM_NUM >= 2) */

	mmi_frm_nmgr_balloon(
		MMI_SCENARIO_ID_HIGHEST_SCRN,
		MMI_EVENT_SIM_VERIFICATION,
		MMI_NMGR_BALLOON_TYPE_INFO,
		(const WCHAR *)simReadyStr.getBuf());
}
#endif //__SIM_HOT_SWAP_SUPPORT__


void VappSecSetHPVeri::tryToLaunch(mmi_sim_enum sim)
{
    if (!s_appIsLaunched && !s_invokedNmgr)
    {
        s_invokedNmgr = VFX_TRUE;
        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_HIGHEST_SCRN,
            MMI_EVENT_SIM_VERIFICATION,
            runAppFromNmgr,
            NULL);
    }
}


void vapp_secset_hpveri_try_to_launch(mmi_sim_enum sim)
{
    VappSecSetHPVeri::tryToLaunch(sim);
}


extern "C"
mmi_ret vapp_secset_hpveri_on_sim_availability_changed(mmi_event_struct *evt)
{
    return VappSecSetHPVeri::onSimAvailabilityChanged(evt);
}


#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
static mmi_sim_enum vapp_secset_hpveri_get_next_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_sim_enum sim;
    srv_sim_ctrl_ua_cause_enum ua_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        sim = mmi_frm_index_to_sim(i);
        
        ua_cause = srv_sim_ctrl_get_unavailable_cause(sim);
        switch (ua_cause)
        {
            case SRV_SIM_CTRL_UA_CAUSE_CHV1_REQUIRED:
            case SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED:
            case SRV_SIM_CTRL_UA_CAUSE_PERSON_REQUIRED:
                return sim;
        }
    }

    return MMI_SIM_NONE;
}

extern "C"
mmi_ret vapp_secset_on_bootup_completed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_secset_hpveri_get_next_sim();
    if (VappSecSetHPVeri::needVerification())
    {
        VappSecSetHPVeri::tryToLaunch(MMI_SIM_NONE);
    }

    return MMI_RET_OK;
}
#endif /* defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__) */

