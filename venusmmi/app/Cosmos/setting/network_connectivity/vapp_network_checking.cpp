/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_network_checking.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_network_checking.h"
#include "vapp_mobile_network_setting.h"
#include "vapp_setting_framework_gprot.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vcp_global_popup.h"

#include "vapp_network_selection.h" // For manual network selection checking
#include "vapp_sim_setting_gprot.h"
extern "C"
{
#include "ModeSwitchSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "NetSetSrvGprot.h" // For manual network selection checking
#include "L4crac_enums.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
extern "C"
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

mmi_ret vapp_network_checking_init(mmi_event_struct *evt)
{
    // CTA Dual SIM network checking
    #ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__
    VappNetworkCheckingController *networkCheckingController = VFX_OBJ_GET_INSTANCE(VappNetworkCheckingController);
    networkCheckingController->enableNetworkCheckingforAllSim();
    #endif
    
    #ifdef __MMI_NETSET_3G_ENHANCE__
    VappManualNetworkCheckingController *manualNetworkCheckingController = VFX_OBJ_GET_INSTANCE(VappManualNetworkCheckingController);
    manualNetworkCheckingController->enableNetworkChecking(MMI_SIM1);    
    #endif /* __MMI_NETSET_3G_ENHANCE__ */
    //StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, (10 * 1000), &vapp_test_no_service);
    return MMI_RET_OK;
}

static MMI_BOOL vapp_network_checking_attach_hdlr(void *msg, S32 src_mod)
{
    mmi_sim_enum sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);
    mmi_nw_attach_ind_struct *nw_attach_ind = (mmi_nw_attach_ind_struct*)msg;

    #ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__
    VappNetworkCheckingController *rfCheckingController = VFX_OBJ_GET_INSTANCE(VappNetworkCheckingController);
    rfCheckingController->onNetworkUsablilityChange(sim, nw_attach_ind->status);
    #endif

    #ifdef __MMI_NETSET_3G_ENHANCE__
    VappManualNetworkCheckingController *networkCheckingController = VFX_OBJ_GET_INSTANCE(VappManualNetworkCheckingController);    
    networkCheckingController->onNetworkUsablilityChange(sim, nw_attach_ind->status);
    #endif /* __MMI_NETSET_3G_ENHANCE__ */
    return MMI_FALSE;
}
}
/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappNetworkCheckingController
 *****************************************************************************/
#ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappNetworkCheckingController);
VappNetworkCheckingController::VappNetworkCheckingController() 
{
    resetCheckingStatus();
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_ATTACH_IND, (PsIntFuncPtr)&vapp_network_checking_attach_hdlr, MMI_TRUE);
}

VappNetworkCheckingController::~VappNetworkCheckingController()
{
    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_NW_ATTACH_IND, (PsIntFuncPtr)&vapp_network_checking_attach_hdlr);
}

void VappNetworkCheckingController::resetCheckingStatus() 
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] resetCheckingStatus()");
    m_isCheckingEnabled = VFX_FALSE;
    memset(m_isSimNoService, VFX_TRUE, (sizeof(VfxBool) * MMI_SIM_TOTAL));
}

void VappNetworkCheckingController::enableNetworkCheckingforAllSim(void)
{
    VfxU32 i;
    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
		mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        enableNetworkChecking(sim);
	}
}

void VappNetworkCheckingController::enableNetworkChecking(mmi_sim_enum sim) 
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] enableNetworkChecking() sim %d", sim);
    if (!srv_mode_switch_is_network_service_available() 
        || srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_OFF
        || !srv_sim_ctrl_is_inserted(sim))
	{
	    // In flight mode
	    return;
	}
    
    VfxU8 insertSim = 0;
    VfxU8 i;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
	    insertSim += (VfxU8) srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i));
	}
    
    if (insertSim == 1)
	{
	    // No SIM can be selected
	    return;
	}
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] enableNetworkChecking() sim %d SET1", sim);
    m_isCheckingEnabled = VFX_TRUE;
    m_isSimNoService[mmi_frm_sim_to_index(sim)] = VFX_FALSE;
}

void VappNetworkCheckingController::onNetworkUsablilityChange(mmi_sim_enum sim, VfxU8 status)
{
    if (!m_isCheckingEnabled)
	{
	    return;
	}
    if (srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_OFF)
	{
	    // The RF is switched OFF
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] onNetworkUsablilityChange() RF is off");
        m_isSimNoService[mmi_frm_sim_to_index(sim)] = VFX_TRUE;
        
        VfxU8 i;
        for (i = 0; i < MMI_SIM_TOTAL; i++)
    	{
    		if (m_isSimNoService[i] == VFX_FALSE)
    		{
    		    // Wait for other RF finish checking
    		    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] onNetworkUsablilityChange() wait");
    		    return;
    		}
    		if (m_isSimNoService[i] == VFX_TRUE && srv_mode_switch_get_network_mode(mmi_frm_index_to_sim(i)) == SRV_MODE_SWITCH_ON)
    		{
    		    // There is RF turn on and no service
    		    showReconfigRfPopup();
                resetCheckingStatus();
                return;
    		}
    	}
        // The checking is aborted by switch checking RF to OFF
        resetCheckingStatus();
        return;
	}
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] onNetworkUsablilityChange() sim %d", sim);    
    if (status == L4C_RAC_OK)
    {
	    // No need to check and display query screen 
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] onNetworkUsablilityChange() reset");    
	resetCheckingStatus();
        return;
    }
    else if (status == L4C_RAC_NO_CELL 
        || status == L4C_RAC_LIMITED_SERVICE
        || status == L4C_RAC_INVALID_SIM)
    {
	m_isSimNoService[mmi_frm_sim_to_index(sim)] = VFX_TRUE;
    }
    VfxU8 i;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
		if (m_isSimNoService[i] == VFX_FALSE)
		{
		    // Wait for other RF finish checking
		    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] onNetworkUsablilityChange() wait");
		    return;
		}
	}
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] onNetworkUsablilityChange() show");
    // All turn on SIM no service
    resetCheckingStatus();
    showReconfigRfPopup();
    VFX_OBJ_CLOSE_INSTANCE(VappNetworkCheckingController);
}

void VappNetworkCheckingController::showReconfigRfPopup()
{
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT,
                                     MMI_EVENT_WARNING,
                                     &VappNetworkCheckingController::onNmgrNotified,
                                     NULL); 
}

MMI_BOOL VappNetworkCheckingController::onNmgrNotified(mmi_scenario_id scenarioId, void *userData)
{
    vcp_global_popup_show_confirm_two_button_id(
    GRP_ID_ROOT,
    VCP_POPUP_TYPE_WARNING, 
    STR_ID_VAPP_SETTING_NO_MOBILE_NETWORK,
    STR_ID_VAPP_SETTING_CHOOSE_SIM,
    STR_GLOBAL_CANCEL,
    VCP_POPUP_BUTTON_TYPE_NORMAL,
    VCP_POPUP_BUTTON_TYPE_CANCEL,
    &VappNetworkCheckingController::onConfirmPopupClicked,
    NULL);
    return MMI_TRUE;
}

void VappNetworkCheckingController::onConfirmPopupClicked(VfxId id, void *userData)
{
    if (id == 'USR1')
    {
	mmi_event_struct evt;
	MMI_FRM_INIT_EVENT(&evt, 0);
        mmi_frm_post_event(&evt, (mmi_proc_func)VappNetworkCheckingController::onEntryRfSelectScreen, NULL);
    }
}

mmi_ret VappNetworkCheckingController::onEntryRfSelectScreen(mmi_event_struct evt)
{
    VfxAppLauncher::launch( 
        VAPP_NETWORK_CHECKING,
        VFX_OBJ_CLASS_INFO(VappNetworkCheckingApp),
        GRP_ID_ROOT);
	return MMI_RET_OK;
}

/***************************************************************************** 
 * VappNetworkCheckingMainScr
 *****************************************************************************/
VfxBool VappNetworkCheckingMainScr::m_isAvailable = VFX_FALSE;
VFX_IMPLEMENT_CLASS("VappNetworkCheckingMainScr", VappNetworkCheckingMainScr, VfxMainScr);
VappNetworkCheckingMainScr::VappNetworkCheckingMainScr()
{
    setIsSmallScreen();
}

void VappNetworkCheckingMainScr::on1stReady()
{
    VfxMainScr::on1stReady();
    m_isAvailable = VFX_TRUE;
    setBgColor(VFX_COLOR_TRANSPARENT);

    showRfSwitchPopup();
}

void VappNetworkCheckingMainScr::showRfSwitchPopup()
{
    VFX_OBJ_CREATE(m_queryPopup, VcpSelectPopup, this);
    m_queryPopup->setAutoDestory(VFX_TRUE);
    m_queryPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_MULTI);
    m_queryPopup->setText(STR_ID_VAPP_SETTING_CHOOSE_SIM);

    VfxU8 i;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
	mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        if (!srv_sim_ctrl_is_inserted(sim))
    	{
    	    continue;
    	}
        m_queryPopup->addItem(i, vapp_sim_settings_get_sim_name_with_sim_id(sim), (srv_mode_switch_get_network_mode(mmi_frm_index_to_sim(i)) == SRV_MODE_SWITCH_ON));
        m_queryPopup->setIsDisableItem(i, !srv_sim_ctrl_is_inserted(sim));
    }
    m_queryPopup->m_signalButtonClicked.connect(this, &VappNetworkCheckingMainScr::onRfSelectPopupClicked);
	m_queryPopup->show(VFX_TRUE);	
}

void VappNetworkCheckingMainScr::onRfSelectPopupClicked(VfxObject *obj, VfxId id)
{
    if (id == 'OK')
    {
	VfxId i = m_queryPopup->getFirstSeletedIndex();
        VfxU8 selectedMode = 0;
		if ((VfxS32)i == -1)
        {
            // No SIM selected switch to all OFF
            selectedMode = SRV_MODE_SWITCH_ALL_OFF;
        }
        else
        {
            VfxId itemId = m_queryPopup->getIdbyIndex(i);
            while (i < MMI_SIM_TOTAL)
            {        	    
        	selectedMode |= mmi_frm_index_to_sim(itemId);
        	i = m_queryPopup->getNextSelectedIndex(i);
                itemId = m_queryPopup->getIdbyIndex(i);
            }
            MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network checking] onRfSelectPopupClicked() selectMode %d", selectedMode);                
            if (selectedMode == srv_mode_switch_get_current_mode())
        	{
        	    // No need to switch
        	    m_signalClose.postEmit();
        	    return;
        	}
        }

        VFX_OBJ_CREATE(m_indPopup, VcpIndicatorPopup, this);
        m_indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_indPopup->setText(STR_GLOBAL_PLEASE_WAIT);
        m_indPopup->show(VFX_TRUE);
	    srv_mode_switch_switch_rf_mode((srv_mode_switch_type_enum)selectedMode, &VappNetworkCheckingMainScr::onRfSwitchFinished, getObjHandle());
        
        if (VappMobileNetworkSettingPage::isPageAvailable())
        {
    	    VappSettingFWMgr *manager = VFX_OBJ_GET_INSTANCE(VappSettingFWMgr);
            VfxAppLauncher::terminate(manager->getAppId());
        }
	}
    else
    {
        m_signalClose.postEmit();
    }
}

mmi_ret VappNetworkCheckingMainScr::onRfSwitchFinished(mmi_event_struct *evt)
{
    if (!VappNetworkCheckingMainScr::isMainScrAvailable())
	{
	    return MMI_RET_OK;
	}
    if (evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH)
	{
        VappNetworkCheckingMainScr *mainScr = (VappNetworkCheckingMainScr*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
        if (mainScr)
    	{
    	    srv_mode_switch_rsp_event_struct *switchEvt = (srv_mode_switch_rsp_event_struct*)evt;
    	    mainScr->switchFinished((VfxBool)switchEvt->result);
    	}
	}
    return MMI_RET_OK;
}

void VappNetworkCheckingMainScr::switchFinished(VfxBool result)
{
    m_signalClose.postEmit();
}
    
/***************************************************************************** 
 * VappNetworkCheckingApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNetworkCheckingApp", VappNetworkCheckingApp, VfxApp);
void VappNetworkCheckingApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);
    VappNetworkCheckingMainScr *mainScr;
    VFX_OBJ_CREATE(mainScr, VappNetworkCheckingMainScr, this);
    mainScr->m_signalClose.connect(this, &VappNetworkCheckingApp::onClose);
    mainScr->show();
}

void VappNetworkCheckingApp::onClose()
{
    exit();
}
#endif /* __MMI_DUAL_SIM_DYNAMIC_MODE__ */

#ifdef __MMI_NETSET_3G_ENHANCE__
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappManualNetworkCheckingController);
void VappManualNetworkCheckingController::enableNetworkChecking(mmi_sim_enum sim)
{
    if (!srv_mode_switch_is_network_service_available() 
        || srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_OFF
        || !srv_sim_ctrl_is_inserted(sim))
	{
	    return;
	}
    m_isCheckingEnabled = VFX_TRUE;
    m_isSimNoService = VFX_FALSE;
}

void VappManualNetworkCheckingController::onNetworkUsablilityChange(mmi_sim_enum sim, VfxU8 status)
{
    if (!m_isCheckingEnabled)
	{
	    return;        
	}
    if (sim != MMI_SIM1)
	{
	    return;
	}
    if (srv_mode_switch_get_network_mode(MMI_SIM1) == SRV_MODE_SWITCH_OFF 
        || srv_mode_switch_is_switching()
        || srv_netset_get_nw_selection_mode(sim) != SRV_NETSET_MANUAL_SEL
        || status == L4C_RAC_OK)
	{
	    // The RF is switched OFF or it is switching
	    resetCheckingStatus();
        return;
	}
    if (status == L4C_RAC_NO_CELL 
        || status == L4C_RAC_LIMITED_SERVICE
        || status == L4C_RAC_INVALID_SIM)
	{
	    m_isSimNoService = VFX_TRUE;
        resetCheckingStatus();
        showNetworkSearchPopup();
	}
}
    
VappManualNetworkCheckingController::VappManualNetworkCheckingController()
{
    resetCheckingStatus();
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_NW_ATTACH_IND, (PsIntFuncPtr)&vapp_network_checking_attach_hdlr, MMI_TRUE);
}

VappManualNetworkCheckingController::~VappManualNetworkCheckingController()
{
    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_NW_ATTACH_IND, (PsIntFuncPtr)&vapp_network_checking_attach_hdlr);
}

void VappManualNetworkCheckingController::showNetworkSearchPopup()
{
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT,
                                     MMI_EVENT_WARNING,
                                     &VappManualNetworkCheckingController::onNmgrNotified,
                                     NULL); 
}

MMI_BOOL VappManualNetworkCheckingController::onNmgrNotified(mmi_scenario_id scenarioId, void *userData)
{
    vcp_global_popup_show_confirm_two_button_id(
    GRP_ID_ROOT,
    VCP_POPUP_TYPE_WARNING, 
    STR_ID_VAPP_SETTING_SET_SIM1_NETWORK,
    STR_GLOBAL_OK,
    STR_GLOBAL_CANCEL,
    VCP_POPUP_BUTTON_TYPE_NORMAL,
    VCP_POPUP_BUTTON_TYPE_CANCEL,
    &VappManualNetworkCheckingController::onConfirmPopupClicked,
    NULL);	
    return MMI_TRUE;
}

void VappManualNetworkCheckingController::resetCheckingStatus()
{
    m_isCheckingEnabled = VFX_FALSE;
    m_isSimNoService = VFX_FALSE;
}

void VappManualNetworkCheckingController::onConfirmPopupClicked(VfxId id, void *userData)
{
    if (id == 'USR1')
	{
        if (VappNetworkSelectionPage::isPageAvailable())
    	{
    	    VappSettingFWMgr *manager = VFX_OBJ_GET_INSTANCE(VappSettingFWMgr);
            VfxAppLauncher::terminate(manager->getAppId());
    	}
        VfxAppLauncher::launch( 
            VAPP_NETWORK_CHECKING,
            VFX_OBJ_CLASS_INFO(VappManualNetworkCheckingApp),
            GRP_ID_ROOT);
	}
}

VFX_IMPLEMENT_CLASS("VappManualNetworkCheckingApp", VappManualNetworkCheckingApp, VfxApp);
void VappManualNetworkCheckingApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);
    VFX_OBJ_CREATE(m_mainScr, VfxMainScr, this);
    m_mainScr->show();

    VFX_OBJ_CREATE_EX(m_nwSelectPage, VappNetworkSelectionPage, m_mainScr, (MMI_SIM1));
    ((VappNetworkSelectionPage*)m_nwSelectPage)->m_signalPageIsReady.connect(this, &VappManualNetworkCheckingApp::onNwSelectPageReady);
    ((VappNetworkSelectionPage*)m_nwSelectPage)->InitPage();
}

void VappManualNetworkCheckingApp::onNwSelectPageReady()
{
    m_mainScr->pushPage(0, m_nwSelectPage);
    ((VappNetworkSelectionPage*)m_nwSelectPage)->m_signalPageIsReady.disconnect(this, &VappManualNetworkCheckingApp::onNwSelectPageReady);
}
#endif /* __MMI_NETSET_3G_ENHANCE__ */
 
