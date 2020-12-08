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
 *  vapp_mobile_network_setting.cpp
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
#include "vapp_mobile_network_setting.h"
#include "vapp_setting_mobile_network_setting.h"
#include "vapp_network_selection.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_vcui_mobile_nw_setting_def.h"
#include "vapp_ncenter_gprot.h"
#include "vapp_network_checking.h" // For SIM network setting checking
#include "vapp_sim_setting_gprot.h" // For SIM name
extern "C"
{
#include "ModeSwitchSrvGprot.h"
#include "NetSetSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwUsabSrvGprot.h"
#include "UcmSrvGprot.h"
#include "NwInfoSrvGprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
mmi_id vcui_mobile_network_setting_create(mmi_id parent_gid)
{
    mmi_id cui_id = GRP_ID_INVALID;
    cui_id = VfxAppLauncher::createCui(
                                    VCUI_MOBILE_NW_SETTING,
                                    VFX_OBJ_CLASS_INFO(VappMobileNetworkSettingCui),
                                    parent_gid);
    return cui_id; 

};

void vcui_mobile_network_setting_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}

void vcui_mobile_network_setting_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
const static VfxResId g_vapp_gprs_connection_mode_string[] =
{
    STR_ID_VAPP_SETTING_GPRS_CONNECTION_WHEN_NEEDED,
    STR_ID_VAPP_SETTING_GPRS_CONNECTION_ALWAYS_CONNECT        
};
#endif /* defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__) */

extern const VfxResId g_vapp_sim_id_map_table[MMI_MAX_SIM_NUM] = 
{
#if (MMI_MAX_SIM_NUM >= 2) 
    STR_GLOBAL_SIM_1
    ,STR_GLOBAL_SIM_2
#if (MMI_MAX_SIM_NUM >= 3) 
    ,STR_GLOBAL_SIM_3
#if (MMI_MAX_SIM_NUM >= 4) 
    ,STR_GLOBAL_SIM_4
#endif
#endif
#else
    STR_GLOBAL_SIM
#endif
};
/***************************************************************************** 
 * Class VappMobileNetworkSettingCui
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA"

VFX_IMPLEMENT_CLASS("VappMobileNetworkSettingCui", VappMobileNetworkSettingCui, VfxCui);
void VappMobileNetworkSettingCui::onRun(void * args,VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);

    VappMobileNetworkSettingMainScr *mobileNetworkSettingScr;
    VFX_OBJ_CREATE(mobileNetworkSettingScr, VappMobileNetworkSettingMainScr, this); 

    mobileNetworkSettingScr->show();
}
/***************************************************************************** 
 * Class VappMobileNetworkSettingMainScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMobileNetworkSettingMainScr", VappMobileNetworkSettingMainScr, VfxMainScr);
void VappMobileNetworkSettingMainScr::on1stReady()
{
    m_settingPage = NULL;
    VFX_OBJ_CREATE(m_settingPage, VappMobileNetworkSettingPage, this);
    //((VappMobileNetworkSettingPage*)m_settingPage)->m_signalPageReady.connect(this, &VappMobileNetworkSettingMainScr::onPageReady);
    ((VappMobileNetworkSettingPage*)m_settingPage)->initPage();
    pushPage(0, m_settingPage);
}

void VappMobileNetworkSettingMainScr::onPageReady()
{
    pushPage(0, m_settingPage);
}
/***************************************************************************** 
 * Class 
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMobileNetworkSettingCell", VappMobileNetworkSettingCell, VcpFormItemLauncherCell);
void VappMobileNetworkSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(STR_ID_VAPP_SETTING_MOBILE_NETWORK_SETTING_TITLE);
    #ifdef __OP01_3G__
    setHintText(STR_ID_VAPP_SETTING_MOBILE_NETWORK_SETTING_HINT_OP01_3G);
    #else /* __OP01_3G__ */
    setHintText(STR_ID_VAPP_SETTING_MOBILE_NETWORK_SETTING_HINT);
    #endif /* __OP01_3G__ */
    m_signalTap.connect(this, &VappMobileNetworkSettingCell::onTap);
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    
    if (!srv_nw_usab_any_sim_is_usable())
	{
	    setIsDisabled(VFX_TRUE);
	}
    else
    {
	    setIsDisabled(VFX_FALSE);
    }    
    m_cuiId = GRP_ID_INVALID;
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY, &VappMobileNetworkSettingCell::updateCellProc, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappMobileNetworkSettingCell::updateCellProc, this);

#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__) && defined(__HSDPA_SUPPORT__) && defined(__HSUPA_SUPPORT__)	
    /* prepare the data for HSPA setting */
    VappMobileNetworkHspaSwitchCell::initData();
#endif
}
VappMobileNetworkSettingCell::~VappMobileNetworkSettingCell()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY, &VappMobileNetworkSettingCell::updateCellProc, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappMobileNetworkSettingCell::updateCellProc, this);
}
void VappMobileNetworkSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    if (srv_ucm_is_any_call())
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
	    return;
    }
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr)
    {
        mmi_id parentId = mainScr->getApp()->getGroupId();
        m_cuiId = vcui_mobile_network_setting_create(parentId);
        if (m_cuiId != GRP_ID_INVALID)
        {
            vcui_mobile_network_setting_run(m_cuiId);
        }
    }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}

mmi_ret VappMobileNetworkSettingCell::updateCellProc(mmi_event_struct *evt)
{
    VfxObject *obj = (VfxObject*)evt->user_data;
    VappMobileNetworkSettingCell *cell = VFX_OBJ_DYNAMIC_CAST(obj, VappMobileNetworkSettingCell);
    if (!cell)
	{
	    return MMI_RET_OK;
	}
    switch (evt->evt_id)
	{
	case EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY:
    {
        if (cell->m_cuiId != GRP_ID_INVALID)
        {
            vapp_ncenter_disable_leave();
            vcui_mobile_network_setting_close(cell->m_cuiId);
            cell->m_cuiId = GRP_ID_INVALID;
        }
                
        cell->setIsDisabled(VFX_TRUE);    	
        break;
    }
    case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
    {
        if (!srv_nw_usab_any_sim_is_usable())
    	{
            cell->setIsDisabled(VFX_TRUE);    		
    	}
        else
        {
            cell->setIsDisabled(VFX_FALSE);
        }
        break;
    }
	default:
        break;		
    }
    return MMI_RET_OK;    
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
#endif
#pragma arm section code, rodata

typedef VfxObject* (*vapp_mobile_network_cell_create_hdlr) (VfxObject*);
/***************************************************************************** 
 * VappMobileNetworkSettingPage
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA"

VFX_IMPLEMENT_CLASS("VappMobileNetworkSettingPage", VappMobileNetworkSettingPage, VfxPage);
VfxBool VappMobileNetworkSettingPage::m_pageIsAvailable = VFX_FALSE;
void VappMobileNetworkSettingPage::onInit()
{
    VfxPage::onInit();
    m_pageIsAvailable = VFX_TRUE;

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_SETTING_MOBILE_NETWORK_SETTING_TITLE);
    setTopBar(titleBar);
}

void VappMobileNetworkSettingPage::initPage()
{
    VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setPos(0, 0);
	m_form->setBounds(this->getBounds());
	m_form->setViewRect(this->getBounds());
//	m_form->setBgColor(VFX_COLOR_WHITE);
	m_form->enableVerticalScrollIndicator(VFX_TRUE);
	m_form->setBorderColor(VFX_COLOR_BLACK);        

    // Add cell to form
    VfxU8 itemIndex = 0;
    m_readyCount = 0;
    const VfxU8 inserted_sim_num = srv_sim_ctrl_get_num_of_inserted();
    vapp_mobile_network_cell_create_hdlr cellArray[] =
    {
        VappMobileNetworkSelectionLaunchCell::createInstance
#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
        ,VappMobileNetworkGprsLaunchCell::createInstance        
#endif /* defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__) */       
#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__) && defined(__HSDPA_SUPPORT__) && defined(__HSUPA_SUPPORT__)	
        ,VappMobileNetworkHspaSwitchCell::createInstance
#endif
    };
    
    for (VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
	    mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            VfxU32 j;

	    if (!srv_sim_ctrl_is_inserted(sim))
		{
		    // Do not displayed un-inserted SIM menu
		    for (j = 0; j < VAPP_MOBILE_NETWORK_SETTING_CELL_TOTAL; j++)
		    {
			m_cell[i][j] = NULL;
		    }
		    continue;
		}

	if (inserted_sim_num > 1) 
        {   
            // SIM caption not needed in single SIM project or only one sim inserted
        VcpFormItemCaption *caption;
        VFX_OBJ_CREATE(caption, VcpFormItemCaption, this);
        caption->setText(vapp_sim_settings_get_sim_name_with_sim_id(sim));
        m_form->addItem(caption, itemIndex);
        itemIndex++;
        }

        // If the sim is not available, then disable the related items.
        VfxBool simNotAvailable = VFX_FALSE;
        if (srv_sim_ctrl_get_unavailable_cause(sim) != SRV_SIM_CTRL_UA_CAUSE_NONE)
        {
            simNotAvailable = VFX_TRUE;
        }
        for (j = 0; j < VAPP_MOBILE_NETWORK_SETTING_CELL_TOTAL; j++)
    	{
    	    m_cell[i][j] = (VcpFormItemBase*)(*cellArray[j])(this);
            VcpFormItemBase *cell = m_cell[i][j];
            m_form->addItem(cell, itemIndex);

            itemIndex++;
            
            if (VFX_TRUE == simNotAvailable)
            {
                cell->setIsDisabled(VFX_TRUE);
            }
            
    	    switch (j)
        	{
            case VAPP_MOBILE_NETWORK_OPERATOR_SELECTION:
            {
                 VappMobileNetworkSelectionLaunchCell *nwCell = (VappMobileNetworkSelectionLaunchCell*)cell;
                 nwCell->setSim(sim);
                 nwCell->m_signalReady.connect(this, &VappMobileNetworkSettingPage::onCellReady);
                 break;
            }
#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
            case VAPP_MOBILE_NETWORK_GPRS_SETTING:
            {
                VappMobileNetworkGprsLaunchCell *gprsCell = (VappMobileNetworkGprsLaunchCell*)cell;
                gprsCell->setSim(sim);
                gprsCell->m_signalReady.connect(this, &VappMobileNetworkSettingPage::onCellReady);
                break;
            }
#endif /* defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__) */
#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__) && defined(__HSDPA_SUPPORT__) && defined(__HSUPA_SUPPORT__)	
            case VAPP_MOBILE_NETWORK_HSPA_SETTING:
            {
                VappMobileNetworkHspaSwitchCell *hspaCell = (VappMobileNetworkHspaSwitchCell*)cell;
                hspaCell->setSim(sim);
                hspaCell->m_signalReady.connect(this, &VappMobileNetworkSettingPage::onCellReady);
        		break;
            }
#endif
        	default:
        		break;
        	}
    	}        
	}
    m_form->setHidden(VFX_TRUE);
    initAllCell();
}

void VappMobileNetworkSettingPage::onEntered()
{
    VfxPage::onEntered();
    // If there is any call, close this page
    if (srv_ucm_is_any_call())
    {
        getMainScr()->popPage();
    }
}

void VappMobileNetworkSettingPage::onCellReady()
{
    VfxU32 simId, cellId;
    do
    {        
        if (m_readyCount == VAPP_MOBILE_NETWORK_SETTING_CELL_TOTAL * MMI_MAX_SIM_NUM)
    	{
    	   m_form->setHidden(VFX_FALSE);
    	   //m_signalPageReady.postEmit();
           return;
    	}
        simId = m_readyCount / VAPP_MOBILE_NETWORK_SETTING_CELL_TOTAL;
        cellId = m_readyCount % VAPP_MOBILE_NETWORK_SETTING_CELL_TOTAL;
        m_readyCount++;
    }
    while (m_cell[simId][cellId] == NULL);
    
    switch (cellId)
	{
    case VAPP_MOBILE_NETWORK_OPERATOR_SELECTION:
    {
         VappMobileNetworkSelectionLaunchCell *nwCell = (VappMobileNetworkSelectionLaunchCell*)m_cell[simId][cellId];
         nwCell->initCell();
         break;
    }
#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
    case VAPP_MOBILE_NETWORK_GPRS_SETTING:
    {
        VappMobileNetworkGprsLaunchCell *gprsCell = (VappMobileNetworkGprsLaunchCell*)m_cell[simId][cellId];
        gprsCell->initCell();
        break;
    }
#endif /* defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__) */
#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__) && defined(__HSDPA_SUPPORT__) && defined(__HSUPA_SUPPORT__)	
    case VAPP_MOBILE_NETWORK_HSPA_SETTING:
    {
        VappMobileNetworkHspaSwitchCell *hspaCell = (VappMobileNetworkHspaSwitchCell*)m_cell[simId][cellId];
        hspaCell->initCell();
		break;
    }
#endif
	default:
		break;
	}
}

void VappMobileNetworkSettingPage::initAllCell()
{
    m_readyCount = 0;
    onCellReady();
}

void VappMobileNetworkSettingPage::DisableCell(mmi_sim_enum sim, VfxBool isDisable)
{
    VfxU32 i;
    for (i = 0; i < VAPP_MOBILE_NETWORK_SETTING_CELL_TOTAL; i++)
	{
		m_cell[mmi_frm_sim_to_index(sim)][i]->setIsDisabled(isDisable);
	}
}
#pragma arm section code, rodata


#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
/***************************************************************************** 
 * VappMobileNetworkGprsLaunchCell
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA"
VFX_IMPLEMENT_CLASS("VappMobileNetworkGprsLaunchCell", VappMobileNetworkGprsLaunchCell, VcpFormItemLauncherCell);
void VappMobileNetworkGprsLaunchCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    m_mode = 0;
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappMobileNetworkGprsLaunchCell::onTapped);
}

void VappMobileNetworkGprsLaunchCell::setSim(mmi_sim_enum sim)
{
    m_sim = sim;

    VfxResId simStrId;
    if (srv_sim_ctrl_get_num_of_inserted() > 1)
    {
        simStrId = g_vapp_sim_id_map_table[mmi_frm_sim_to_index(sim)];
    }
    else
    {
        simStrId = STR_GLOBAL_SIM;
    }

    VfxWString titleStr(simStrId);
    titleStr += VFX_WSTR(" ");
    titleStr += VFX_WSTR_RES(STR_ID_VAPP_SETTING_SIM_GPRS_CONNECTION);
    setMainText(titleStr);
    
    if (srv_mode_switch_get_network_mode(sim) != SRV_MODE_SWITCH_ON)
    {
	setIsDisabled(VFX_TRUE);
    }
}

void VappMobileNetworkGprsLaunchCell::onTapped(VcpFormItemCell* sender, VfxId id)
{
    VappGprsConnectionSettingPage *page;
    VfxMainScr *mainScr = ((VfxPage*)getParent())->getMainScr();
    VFX_OBJ_CREATE(page, VappGprsConnectionSettingPage, mainScr);

	page->setSim(m_sim);
    page->setSelected(m_mode);
	page->m_signalSettingUpdate.connect(this, &VappMobileNetworkGprsLaunchCell::onGprsModeUpdate);
    mainScr->pushPage(0, page);
}

void VappMobileNetworkGprsLaunchCell::initCell()
{
#if (MMI_MAX_SIM_NUM >= 2)
    if (is_test_sim(mmi_frm_sim_to_index(m_sim)))
#endif
    {
        srv_netset_get_gprs_connection_state(m_sim, VappMobileNetworkGprsLaunchCell::onProc, getObjHandle());
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else
    {
        setIsHidden(VFX_TRUE);
        m_signalReady.postEmit();
    }
#endif
}

void VappMobileNetworkGprsLaunchCell::onGetGprsMode(VfxU8 mode)
{
    updateMode(mode);
    m_signalReady.postEmit();
}

void VappMobileNetworkGprsLaunchCell::onGprsModeUpdate(mmi_sim_enum sim, VfxU8 mode)
{
    ASSERT(m_sim == sim);
    updateMode(mode);
}

void VappMobileNetworkGprsLaunchCell::updateMode(VfxU8 mode)
{
    m_mode = mode;
    setHintText(g_vapp_gprs_connection_mode_string[mode]);
}

mmi_ret VappMobileNetworkGprsLaunchCell::onProc(mmi_event_struct *evt)
{
    if(!VappMobileNetworkSettingPage::isPageAvailable())
    {
        return MMI_RET_OK;
    }
    
    if (evt->evt_id == EVT_ID_SRV_NETSET_GET_GPRS_CONNECTION_MODE_RSP)
	{
        srv_netset_rsp_event_struct *rsp_evt = (srv_netset_rsp_event_struct*)evt;
        VappMobileNetworkGprsLaunchCell *cell = (VappMobileNetworkGprsLaunchCell*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
        if (cell)
        {
        cell->onGetGprsMode(rsp_evt->rsp_data.get_gprs_connection_rsp_data->type);
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Mobile network setting] get GPRS mode %d", rsp_evt->rsp_data.get_gprs_connection_rsp_data->type);
	}
	}
    return MMI_RET_OK;
}

/***************************************************************************** 
 * VappGprsConnectionSettingPage
 *****************************************************************************/
VfxBool VappGprsConnectionSettingPage::m_pageIsAvailable = VFX_FALSE;
void VappGprsConnectionSettingPage::onInit()
{
    VfxPage::onInit();
	m_sim = MMI_SIM_NONE;
	m_currentSelected = 0;

    VcpListMenu *listMenu;
    VFX_OBJ_CREATE(listMenu, VcpListMenu, this);
    listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    listMenu->setContentProvider(this);
    listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);    
    listMenu->setRect(0, 0, LCD_WIDTH, LCD_HEIGHT);		 
    listMenu->m_signalItemTapped.connect(this, &VappGprsConnectionSettingPage::onSelectItem);  

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    setTopBar(m_titleBar);
    m_pageIsAvailable = VFX_TRUE;
}

void VappGprsConnectionSettingPage::setSim(mmi_sim_enum sim) 
{
    m_sim = sim;

    VfxResId simStrId;
    if (srv_sim_ctrl_get_num_of_inserted() > 1)
    {
        simStrId = g_vapp_sim_id_map_table[mmi_frm_sim_to_index(sim)];
    }
    else
    {
        simStrId = STR_GLOBAL_SIM;
    }

    VfxWString titleStr(simStrId);
    titleStr += VFX_WSTR(" ");
    titleStr += VFX_WSTR_RES(STR_ID_VAPP_SETTING_SIM_GPRS_CONNECTION);
    m_titleBar->setTitle(titleStr);
}

VfxBool VappGprsConnectionSettingPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
	if (index < (VfxU32)getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
		   text.loadFromRes(g_vapp_gprs_connection_mode_string[index]);
		   color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		   return VFX_TRUE;
		}
	}
	return VFX_FALSE;
}

void VappGprsConnectionSettingPage::onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx)
{
    if (selectIdx != m_currentSelected)
	{
	    srv_netset_set_gprs_connection_state(m_sim, (srv_netset_gprs_connect_mode_enum)selectIdx, &VappGprsConnectionSettingPage::switchProc, getObjHandle());
	}
    else
    {
        getMainScr()->popPage();
    }
}

void VappGprsConnectionSettingPage::onSwitchFinished(mmi_nw_set_gprs_connect_type_rsp_struct *evt)
{
    if (evt->result)
	{
	    m_signalSettingUpdate.emit(m_sim, !m_currentSelected);
        getMainScr()->popPage();
	}
}

mmi_ret VappGprsConnectionSettingPage::switchProc(mmi_event_struct *evt)
{
    if (!VappGprsConnectionSettingPage::isPageAvailable())
	{
	    return MMI_RET_OK;
	}
    VappGprsConnectionSettingPage *page = (VappGprsConnectionSettingPage*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    if (evt->evt_id == EVT_ID_SRV_NETSET_SET_GPRS_CONNECTION_MODE_RSP && page)
	{
	    srv_netset_rsp_event_struct *rsp_evt = (srv_netset_rsp_event_struct*)evt;
        page->onSwitchFinished(rsp_evt->rsp_data.set_gprs_connection_rsp_data);
	}
    return MMI_RET_OK;
}
#pragma arm section code, rodata

#endif /* defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__) */

/***************************************************************************** 
 * VappMobileNetworkSelectionLaunchCell
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA"

VFX_IMPLEMENT_CLASS("VappMobileNetworkSelectionLaunchCell", VappMobileNetworkSelectionLaunchCell, VcpFormItemLauncherCell);
void VappMobileNetworkSelectionLaunchCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappMobileNetworkSelectionLaunchCell::onTapped);
}

void VappMobileNetworkSelectionLaunchCell::setSim(mmi_sim_enum sim)
{
    m_sim = sim;

    VfxResId simStrId;
    if (srv_sim_ctrl_get_num_of_inserted() > 1)
    {
        simStrId = g_vapp_sim_id_map_table[mmi_frm_sim_to_index(sim)];
    }
    else
    {
        simStrId = STR_GLOBAL_SIM;
    }

    VfxWString titleStr(simStrId);
    titleStr += VFX_WSTR(" ");
    titleStr += VFX_WSTR_RES(STR_ID_VAPP_SETTING_SIM_NETWORK_OPERATOR);
    setMainText(titleStr);
    if (srv_mode_switch_get_network_mode(sim) != SRV_MODE_SWITCH_ON)
    {
	setIsDisabled(VFX_TRUE);
    }
}

void VappMobileNetworkSelectionLaunchCell::onTapped(VcpFormItemCell* sender, VfxId id)
{
    VfxMainScr *mainScr = ((VfxPage*)getParent())->getMainScr();
    VFX_OBJ_CREATE_EX(m_nwSelectionPage, VappNetworkSelectionPage, mainScr, (m_sim));
    ((VappNetworkSelectionPage*)m_nwSelectionPage)->m_signalPageIsReady.connect(this, &VappMobileNetworkSelectionLaunchCell::onPageReady);
    ((VappNetworkSelectionPage*)m_nwSelectionPage)->InitPage();
}

void VappMobileNetworkSelectionLaunchCell::onPageReady()
{
    VfxMainScr *mainScr = ((VfxPage*)getParent())->getMainScr();
    mainScr->pushPage(0, m_nwSelectionPage);
    ((VappNetworkSelectionPage*)m_nwSelectionPage)->m_signalPageIsReady.disconnect(this, &VappMobileNetworkSelectionLaunchCell::onPageReady);

}
#pragma arm section code, rodata


/***************************************************************************** 
 * VappMobileNetworkHspaSwitchCell
 *****************************************************************************/
#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__) && defined(__HSDPA_SUPPORT__) && defined(__HSUPA_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA"

VfxBool VappMobileNetworkHspaSwitchCell::m_hspaMode[MMI_MAX_SIM_NUM] = {0};
VappMobileNetworkHspaSwitchCell* VappMobileNetworkHspaSwitchCell::m_cell[MMI_MAX_SIM_NUM] = {NULL};

VFX_IMPLEMENT_CLASS("VappMobileNetworkHspaSwitchCell", VappMobileNetworkHspaSwitchCell, VcpFormItemSwitchCell);
void VappMobileNetworkHspaSwitchCell::onInit()
{
    VcpFormItemSwitchCell::onInit();

//    m_mode = 0;
    setMainText(STR_ID_VAPP_SETTING_HSPA_SWITCH);
    m_signalSwitchChangeReq.connect(this, &VappMobileNetworkHspaSwitchCell::onSwitch);
}

void VappMobileNetworkHspaSwitchCell::onDeinit()
{
    m_cell[mmi_frm_sim_to_index(m_sim)] = NULL;
    VcpFormItemSwitchCell::onDeinit();
}

void VappMobileNetworkHspaSwitchCell::setSim(mmi_sim_enum sim)
{
    m_sim = sim;
    m_cell[mmi_frm_sim_to_index(m_sim)] = this;
    if (m_sim != MMI_SIM1)
	{
	    setIsHidden(VFX_TRUE);
	}

    // if the sim1 has been closed, then hspa should been set false.
    // else then should been set the value in the talbe.
    VfxU16 curMode = (VfxU16)srv_mode_switch_get_current_mode();
    if ((curMode & m_sim) == 0)
    {
        setSwitchStatus(VFX_FALSE);
    }
    else
    {
    setSwitchStatus(m_hspaMode[mmi_frm_sim_to_index(sim)]);
    }
    if (srv_mode_switch_get_network_mode(sim) != SRV_MODE_SWITCH_ON)
    {
	setIsDisabled(VFX_TRUE);
    }
}

void VappMobileNetworkHspaSwitchCell::initCell()
{
    m_signalReady.postEmit();
}

void VappMobileNetworkHspaSwitchCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId id, VfxBool mode)
{
    if (m_hspaMode[mmi_frm_sim_to_index(m_sim)] == mode)
	{
	    return;
	}
    showProcessInd();

    VappMobileNetworkSettingPage *page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMobileNetworkSettingPage);
    if (page)
	{
        page->DisableCell(m_sim, VFX_TRUE);	
	}

    srv_netset_hspa_mode_enum selectMode = (mode == VFX_TRUE ? SRV_NETSET_HSDPA_HSUPA_ON : SRV_NETSET_HSPA_OFF);
    srv_netset_set_hspa_mode(m_sim, selectMode, &VappMobileNetworkHspaSwitchCell::onProc, getObjHandle());
}

void VappMobileNetworkHspaSwitchCell::onGetHspaMode(mmi_sim_enum sim, VfxBool mode)
{
    m_hspaMode[mmi_frm_sim_to_index(sim)] = mode;
}

void VappMobileNetworkHspaSwitchCell::onHspaModeUpdate(VfxBool result)
{
    if (result)
	{
	    m_hspaMode[mmi_frm_sim_to_index(m_sim)] = !m_hspaMode[mmi_frm_sim_to_index(m_sim)];

        VappMobileNetworkSettingPage *page = VFX_OBJ_DYNAMIC_CAST(getParent(), VappMobileNetworkSettingPage);
        if (page)
    	{
            page->DisableCell(m_sim, VFX_FALSE);	
    	}
	}
    else
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            VFX_WSTR_RES(STR_ID_VAPP_SETTING_HSPA_SWITCH_FAILED).getBuf());
    }    
    setSwitchStatus(m_hspaMode[mmi_frm_sim_to_index(m_sim)]);   
    // TODO: Enable related cell
}

mmi_ret VappMobileNetworkHspaSwitchCell::onProc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_NETSET_GET_HSPA_MODE_RSP)
	{
	    srv_netset_rsp_event_struct *rsp_evt = (srv_netset_rsp_event_struct*)evt;
        VappMobileNetworkHspaSwitchCell::onGetHspaMode(MMI_SIM1, rsp_evt->rsp_data.get_hspa_mode_rsp_data->hspa_mode == SRV_NETSET_HSDPA_HSUPA_ON ? VFX_TRUE : VFX_FALSE);
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Mobile network setting] get HSPA %d", rsp_evt->rsp_data.get_hspa_mode_rsp_data->hspa_mode);
        return MMI_RET_OK;
	}

    if(!VappMobileNetworkSettingPage::isPageAvailable())
    {
        return MMI_RET_OK;
    }

    srv_netset_rsp_event_struct *rsp_evt = (srv_netset_rsp_event_struct*)evt;

    //VappMobileNetworkHspaSwitchCell *cell = (VappMobileNetworkHspaSwitchCell*)evt->user_data;
    VappMobileNetworkHspaSwitchCell *cell = VappMobileNetworkHspaSwitchCell::getCell();

    if (NULL == cell)
    {
        return MMI_RET_OK;
    }
    if (evt->evt_id == EVT_ID_SRV_NETSET_SET_HSPA_MODE_RSP)
	{
   	    cell->onHspaModeUpdate(rsp_evt->rsp_data.set_hspa_mode_rsp_data->result);
	}
    return MMI_RET_OK;
}

void VappMobileNetworkHspaSwitchCell::initData()
{
    srv_netset_get_hspa_mode(MMI_SIM1, VappMobileNetworkHspaSwitchCell::onProc, NULL);
}
#pragma arm section code, rodata

#endif

/***************************************************************************** 
 * PCH setting
 *****************************************************************************/
#if defined(__MONITOR_PAGE_DURING_TRANSFER__) //&& !defined(__LOW_COST_SUPPORT_COMMON__)
static srv_netset_pch_mode_enum g_vapp_setting_pch_setting;
const static VfxId g_vapp_setting_pch_string[2] =
{
    STR_ID_VAPP_SETTING_PCH_DATA_PREFER,
    STR_ID_VAPP_SETTING_PCH_CALL_PREFER
};
static mmi_sim_enum g_vapp_setting_pch_set_sim;
VfxSignal1 <VfxBool> g_vapp_setting_pch_set_finish;
extern "C"
{
static mmi_ret vapp_setting_pch_setting_proc(mmi_event_struct *evt);
static mmi_ret vapp_setting_pch_set_pch_int (mmi_event_struct *evt);
static void vapp_setting_pch_set_pch(srv_netset_pch_mode_enum pch)
{
    if (g_vapp_setting_pch_setting == pch)
	{
	    g_vapp_setting_pch_set_finish.emit(VFX_TRUE);
        return;
	}
    g_vapp_setting_pch_setting = pch;
    g_vapp_setting_pch_set_sim = MMI_SIM1;
    vapp_setting_pch_set_pch_int(NULL);
}

static mmi_ret vapp_setting_pch_set_pch_int (mmi_event_struct *evt)
{
    if (g_vapp_setting_pch_set_sim <= mmi_frm_index_to_sim(MMI_MAX_SIM_NUM - 1))
	{
        srv_netset_set_pch_mode(g_vapp_setting_pch_set_sim, g_vapp_setting_pch_setting, vapp_setting_pch_setting_proc, NULL);	
	}

    else
    {
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__    
        U32 i;
        for (i = 0; i < MMI_MAX_SIM_NUM; i++)
        {
            srv_netset_set_peer_pch_mode(mmi_frm_index_to_sim(i), (MMI_BOOL)g_vapp_setting_pch_setting);
        }
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
        g_vapp_setting_pch_set_finish.emit(VFX_TRUE);
    }

    g_vapp_setting_pch_set_sim = (mmi_sim_enum)(g_vapp_setting_pch_set_sim << 1);

    return MMI_RET_OK;
}

static mmi_ret vapp_setting_pch_setting_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
	{
	case EVT_ID_SRV_NETSET_GET_PCH_MODE_RSP:
    {
        /* set PCH setting at boot up */
        mmi_nw_get_gprs_transfer_preference_rsp_struct *rsp_msg = ((srv_netset_rsp_event_struct*)evt)->rsp_data.get_pch_mode_rsp_data;
	    g_vapp_setting_pch_setting = (srv_netset_pch_mode_enum)rsp_msg->prefer;
        g_vapp_setting_pch_set_sim = MMI_SIM2; // Set PCH setting same as SIM1
        vapp_setting_pch_set_pch_int(NULL);
		break;
	}
    
	case EVT_ID_SRV_NETSET_SET_PCH_MODE_RSP:
    {
        /* Sync, query the next setting */
        mmi_event_struct post_evt;
        MMI_FRM_INIT_EVENT(&post_evt, 0);
        mmi_frm_post_event(&post_evt, vapp_setting_pch_set_pch_int, NULL);
		break;
	}
        
	default:
		break;
	}
    return MMI_RET_OK;
}

mmi_ret vapp_setting_pch_setting_init(mmi_event_struct *evt)
{
    srv_netset_get_pch_mode(MMI_SIM1, vapp_setting_pch_setting_proc, NULL);

    return MMI_RET_OK;
}


}



/***************************************************************************** 
 * VappMonitorPchSettingCell
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA"

VFX_IMPLEMENT_CLASS("VappMonitorPchSettingCell", VappMonitorPchSettingCell, VcpFormItemLauncherCell);
void VappMonitorPchSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(STR_ID_VAPP_SETTING_PCH_SETTING);
    setAccessory(VCPFORM_NEXT_ITEM_ICON);

    m_signalTap.connect(this, &VappMonitorPchSettingCell::onTap);
    
    g_vapp_setting_pch_set_finish.connect(this, &VappMonitorPchSettingCell::updateCell);
    updateCell(VFX_TRUE);
}

void VappMonitorPchSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    VappMonitorPchSettingPage *page;
    VfxMainScr *mainScr = (VfxMainScr*)findScreen();
    VFX_OBJ_CREATE(page, VappMonitorPchSettingPage, mainScr);
    mainScr->pushPage(0, page);
}

void VappMonitorPchSettingCell::updateCell(VfxBool result)
{
    setHintText(g_vapp_setting_pch_string[g_vapp_setting_pch_setting]);
}

/***************************************************************************** 
 * VappMonitorPchSettingPage
 *****************************************************************************/
void VappMonitorPchSettingPage::onInit()
{
    VfxPage::onInit();

    m_indPopup = NULL;
    
    VcpListMenu *listMenu;
    VFX_OBJ_CREATE(listMenu, VcpListMenu, this);
    listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    listMenu->setContentProvider(this);
    listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);    
    listMenu->setRect(0, 0, LCD_WIDTH, LCD_HEIGHT);		 
    listMenu->m_signalItemTapped.connect(this, &VappMonitorPchSettingPage::onSelectItem);  

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_SETTING_PCH_SETTING);
    setTopBar(titleBar);
}

VcpListMenuItemStateEnum VappMonitorPchSettingPage::getItemState(VfxU32 index) const
{
    return ((g_vapp_setting_pch_setting == index) ? VCP_LIST_MENU_ITEM_STATE_SELECTED: VCP_LIST_MENU_ITEM_STATE_NONE);
}


VfxBool VappMonitorPchSettingPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
	if (index < (VfxU32)getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
		   text.loadFromRes(g_vapp_setting_pch_string[index]);
		   color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		   return VFX_TRUE;
		}
	}
	return VFX_FALSE;
}

void VappMonitorPchSettingPage::onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx)
{
    if (selectIdx != g_vapp_setting_pch_setting)
	{
	    m_selectIdx = selectIdx;
	    if (selectIdx ==  SRV_NETSET_DATA_PREFER)
		{
		    VcpConfirmPopup *popup;
            VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
            popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            popup->setInfoType(VCP_POPUP_TYPE_WARNING);
            popup->setText(STR_ID_VAPP_SETTING_PCH_DATA_PREFER_CONFIRM);
            popup->setCustomButton(
                STR_GLOBAL_CONTINUE, 
                STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_WARNING,
                VCP_POPUP_BUTTON_TYPE_CANCEL);
            popup->m_signalButtonClicked.connect(this, &VappMonitorPchSettingPage::onConfirmPopupTap);
            popup->show(VFX_TRUE);
            return;
		}
        switchPch();
	}
	else
	{
        getMainScr()->popPage();
	}
}

void VappMonitorPchSettingPage::onConfirmPopupTap(VfxObject* sender, VfxId id)
{
    if (id == 'USR1')
	{
	    switchPch();
	}
}

void VappMonitorPchSettingPage::switchPch(void)
{
    VFX_OBJ_CREATE(m_indPopup, VcpIndicatorPopup, getMainScr());
    m_indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_indPopup->setText(STR_GLOBAL_PLEASE_WAIT);
    m_indPopup->show(VFX_TRUE);
    
    g_vapp_setting_pch_set_finish.connect(this, &VappMonitorPchSettingPage::onSettingFinish);
    vapp_setting_pch_set_pch((srv_netset_pch_mode_enum)m_selectIdx);
}

void VappMonitorPchSettingPage::onSettingFinish(VfxBool result)
{
    if (m_indPopup)
    {
        m_indPopup->exit(VFX_TRUE);
    }
    getMainScr()->popPage();    
}
#pragma arm section code, rodata

#endif //#if defined(__MONITOR_PAGE_DURING_TRANSFER__) //&& !defined(__LOW_COST_SUPPORT_COMMON__)
