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
 *  vapp_network_selection.cpp
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
#include "vapp_network_selection.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_vcui_mobile_nw_setting_def.h"

#include "vapp_preferred_network.h"
#ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__
#include "vapp_network_checking.h"
#endif
extern "C"
{
#include "L4crac_enums.h"
#include "NetSetSrvGprot.h"
#include "UcmSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "GlobalResDef.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_NW_SELECT_SEGMENT_BTN_WIDTH  (LCD_WIDTH * 2 / 3)
#define VAPP_NW_SELECT_SEGMENT_BTN_HEIGHT (VCPFRM_STD_UI_CNTRL_HEIGHT)
#define VAPP_NW_SELECT_FORM_POS_Y         (VCPFRM_STD_CELL_HEIGHT)


#define VAPP_NW_SELECT_AUTO_STRING       (VFX_WSTR_RES(STR_GLOBAL_AUTOMATIC))
#define VAPP_NW_SELECT_MANUAL_STRING     (VFX_WSTR_RES(STR_GLOBAL_MANUAL))

#define VAPP_NW_SELECT_AUTO_SELECT_MAIN  (VFX_WSTR_RES(STR_ID_VAPP_SETTING_AUTO_SELECT))
#define VAPP_NW_SELECT_AUTO_SELECT_HINT  (VFX_WSTR_RES(STR_ID_VAPP_SETTING_AUTO_SELECT_NETWORK))
#define VAPP_NW_SELECT_AUTO_SERVICE_SELECT_MAIN  (VFX_WSTR_RES(STR_ID_VAPP_SETTING_NETWORK_SERVICE_MODE))
#define VAPP_NW_SELECT_AUTO_PREFERENCE_MAIN  (VFX_WSTR_RES(STR_ID_VAPP_SETTING_PREFERRED_NETWORK))
#define VAPP_NW_SELECT_AUTO_PREFERENCE_HINT  (VFX_WSTR_RES(STR_ID_VAPP_SETTING_PREFERRED_NETWORK_HINT))
#define VAPP_NW_SELECT_AUTO_HINT  (VFX_WSTR_RES(STR_ID_VAPP_SETTING_AUTO_SELECTION_PAGE_HINT))

#define VAPP_NW_SELECT_MANUAL_REFRESH_MAIN  (VFX_WSTR_RES(STR_GLOBAL_REFRESH))
#define VAPP_NW_SELECT_MANUAL_REFRESH_HINT  (VFX_WSTR_RES(STR_ID_VAPP_SETTING_MANUAL_REFRESH_HINT))
#define VAPP_NW_SELECT_MANUAL_OPERATOR_CAPTION  (VFX_WSTR_RES(STR_ID_VAPP_SETTING_AVAILABLE_NETWORK))

VfxWString VappServiceSelectionString[3];
VfxBool VappNetworkSelectionListParser::m_isGetListAborted = VFX_FALSE;
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
extern const VfxResId g_vapp_sim_id_map_table[MMI_MAX_SIM_NUM];

typedef enum
{
    VAPP_NW_SELECT_AUTO_SELECT_ID,
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)    
/* under construction !*/
#endif
    VAPP_NW_SELECT_AUTO_PREFERENCE_ID,

    VAPP_NW_SELECT_AUTO_CELL_ID_END
}VappNwSelectAutoCellIdEnum;

typedef enum
{
    VAPP_NW_SELECT_MANUAL_REFRESH_ID,
    VAPP_NW_SELECT_MANUAL_CAPTION_ID,
    VAPP_NW_SELECT_MANUAL_PLMN_START,

    VAPP_NW_SELECT_MANUAL_CELL_ID_END
}VappNwSelectManualCellIdEnum;

VfxBool VappNetworkSelectionPage::m_isPageAvailable = VFX_FALSE;
/***************************************************************************** 
 * Class 
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNetworkSelectionPage", VappNetworkSelectionPage, VfxPage);
void VappNetworkSelectionPage::onInit()
{
    VfxPage::onInit();
    
//    setBgColor(VFX_COLOR_WHITE);
    VappServiceSelectionString[0] = VFX_WSTR("GSM");
    VappServiceSelectionString[1] = VFX_WSTR("WCDMA");
    VappServiceSelectionString[2] = VFX_WSTR_RES(STR_ID_VAPP_SETTING_GSM_WCDMA_AUTO);
    
    if (m_sim == MMI_SIM_NONE)
	{
        ASSERT(0);	
	}
    m_serviceMode = (srv_netset_nw_selection_mode_enum)srv_netset_get_nw_selection_mode(m_sim);

    VappNetworkSelectionInterface *nwSelectionInterface = (VappNetworkSelectionInterface*)VFX_OBJ_GET_INSTANCE(VappNetworkSelectionInterface);
    nwSelectionInterface->Init(m_sim);
   
    VfxResId simStrId;
    if (srv_sim_ctrl_get_num_of_inserted() > 1) 
    {
        simStrId = g_vapp_sim_id_map_table[mmi_frm_sim_to_index(m_sim)];
    }
    else
    {
        simStrId = STR_GLOBAL_SIM;
    }

    VfxWString titleStr(simStrId);
    titleStr += VFX_WSTR(" ");
    titleStr += VFX_WSTR_RES(STR_ID_VAPP_SETTING_SIM_NETWORK_OPERATOR);
    
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(titleStr);
    setTopBar(titleBar);
    
    VFX_OBJ_CREATE(m_segBtn, VcpSegmentButton, this);
    m_segBtn->setAnchor(0.5, 0.5);
    m_segBtn->setPos(LCD_WIDTH / 2, VAPP_NW_SELECT_FORM_POS_Y / 2);
    m_segBtn->setSize(VAPP_NW_SELECT_SEGMENT_BTN_WIDTH, VAPP_NW_SELECT_SEGMENT_BTN_HEIGHT);
    m_segBtn->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
    m_segBtn->addButton(0, NULL, VAPP_NW_SELECT_AUTO_STRING);
    m_segBtn->addButton(1, NULL, VAPP_NW_SELECT_MANUAL_STRING);  
    
    m_segBtn->m_signalButtonClicked.connect(this, &VappNetworkSelectionPage::onSegBtnTap);

    m_segBtn->setButtonIsHighlighted((m_serviceMode == SRV_NETSET_MANUAL_SEL ? 1 : 0), VFX_TRUE);
}

void VappNetworkSelectionPage::InitPage()
{
    updateForm(m_serviceMode == SRV_NETSET_MANUAL_SEL ? 1 : 0);
}

void VappNetworkSelectionPage::onEntered()
{
    VfxPage::onEntered();
    if (srv_ucm_is_any_call())
    {
        getMainScr()->popPage();
    }
}

void VappNetworkSelectionPage::onExit(VfxBool isBackward)
{
    if (VFX_TRUE == isBackward)
    {
        if (!getMainScr()->getIsSnapshotDrawing())
        {
            VappNetworkSelectionInterface *nwSelectionInterface = (VappNetworkSelectionInterface*)VFX_OBJ_GET_INSTANCE(VappNetworkSelectionInterface);
            nwSelectionInterface->close();
            m_isPageAvailable = VFX_FALSE;
        }
    }
    
    VfxPage::onExit(isBackward);
}
void VappNetworkSelectionPage::updateForm(VfxId formId)
{
    switch (formId)
	{
	case 0:
		updateAutoForm();
		break;
    case 1:
        updateManualForm();
        break;
	default:
		break;
	}    
}

void VappNetworkSelectionPage::onSegBtnTap(VfxObject *obj, VfxId id)
{
    m_segBtn->setButtonIsHighlighted(id, VFX_TRUE);
    m_segBtn->setButtonIsHighlighted((id == 0 ? 1 : 0), VFX_FALSE);

    srv_netset_nw_selection_mode_enum switchType = (id == 0 ? SRV_NETSET_AUTO_SEL : SRV_NETSET_MANUAL_SEL);
    if (m_serviceMode == switchType)
    {
	    return;
    }
    m_serviceMode = switchType;
    srv_netset_set_nw_selection_mode(m_sim, switchType, &VappNetworkSelectionPage::settingRspProc, getObjHandle());
    updateForm(id);
}

void VappNetworkSelectionPage::updateAutoForm()
{
    if (!m_autoForm)
	{
	    VFX_OBJ_CREATE(m_autoForm, VappAutoNetworkSelectionForm, this);
    	m_autoForm->setPos(0, VAPP_NW_SELECT_FORM_POS_Y);
    	m_autoForm->setBounds(this->getBounds());
    	m_autoForm->setViewRect(this->getBounds());
//    	m_autoForm->setBgColor(VFX_COLOR_WHITE);
    	m_autoForm->enableVerticalScrollIndicator(VFX_TRUE);
    	m_autoForm->setBorderColor(VFX_COLOR_BLACK);       
        m_autoForm->setSim(m_sim);
        /* wait for the data is ready */
	}
    m_autoForm->m_signalFormIsReady.connect(this, &VappNetworkSelectionPage::onAutoFormReady);

    m_autoForm->updateForm();

}

void VappNetworkSelectionPage::onAutoFormReady()
{
    m_signalPageIsReady.emit();
    if (m_manualForm)
    {
        m_manualForm->setHidden(VFX_TRUE);	
	m_autoForm->setHidden(VFX_FALSE);
    }
    m_autoForm->m_signalFormIsReady.disconnect(this, &VappNetworkSelectionPage::onAutoFormReady);
}

void VappNetworkSelectionPage::updateManualForm()
{
    if (m_autoForm)
	{
	    m_autoForm->setHidden(VFX_TRUE);
	}
   
    if (!m_manualForm)
	{
	    VFX_OBJ_CREATE(m_manualForm, VappManualNetworkSelectionForm, this);
    	m_manualForm->setPos(0, VAPP_NW_SELECT_FORM_POS_Y);
        VfxSize formSize = getSize();
        formSize.height -= VAPP_NW_SELECT_FORM_POS_Y;
        m_manualForm->setSize(formSize);
//    	m_manualForm->setBgColor(VFX_COLOR_WHITE);
    	m_manualForm->enableVerticalScrollIndicator(VFX_TRUE);
    	m_manualForm->setBorderColor(VFX_COLOR_BLACK);   
        m_manualForm->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        
        m_manualForm->setSim(m_sim);
        
        m_manualForm->updateForm();
        /* no need to wait for data ready */
        m_signalPageIsReady.emit();
	}
    else
    {
        m_manualForm->setHidden(VFX_FALSE);
    }
}

void VappNetworkSelectionPage::setNwSelectionModeRsp(mmi_nw_set_plmn_select_mode_rsp_struct *result)
{
    if (!result->result)
	{
        VcpConfirmPopup *popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, getMainScr());        
        popup->setText(STR_ID_VAPP_SETTING_SWITCH_SELECTION_MODE_FAILED);
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
//        popup->setTextAlignMode((VfxTextFrame::AlignModeEnum)3);
        popup->show(VFX_TRUE);
	}
}

mmi_ret VappNetworkSelectionPage::settingRspProc(mmi_event_struct *evt)
{
    if (!VappNetworkSelectionPage::isPageAvailable())
    {
	    return MMI_RET_OK;
    }

    VappNetworkSelectionPage *page = (VappNetworkSelectionPage *)VfxObject::handleToObject((VfxObjHandle)evt->user_data);

    if (page)
	{
        srv_netset_rsp_event_struct *srvRspEvt;        
        srvRspEvt = (srv_netset_rsp_event_struct*)evt;
        switch (evt->evt_id)
    	{
        case EVT_ID_SRV_NETSET_SET_NW_SELECTION_MODE_RSP:
            page->setNwSelectionModeRsp(srvRspEvt->rsp_data.set_nw_selection_mode_rsp_data);
            break;
    	default:
            break;		
    	}	
	}
    return MMI_RET_OK;
}
/***************************************************************************** 
 * 
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappAutoNetworkSelectionForm", VappAutoNetworkSelectionForm, VcpForm);
void VappAutoNetworkSelectionForm::onDeinit()
{
    if (m_currentPopup != NULL)
	{
	    m_currentPopup->exit(VFX_TRUE);
	}
    
	VcpForm::onDeinit();
}
void VappAutoNetworkSelectionForm::updateForm()
{
    if (!m_isInit)
	{
        VFX_OBJ_CREATE(m_autoSelect, VcpFormItemLauncherCell, this);
        m_autoSelect->setMainText(VAPP_NW_SELECT_AUTO_SELECT_MAIN);
        m_autoSelect->setHintText(VAPP_NW_SELECT_AUTO_SELECT_HINT);
        m_autoSelect->m_signalTap.connect(this, &VappAutoNetworkSelectionForm::onAutoSelectPlmn);
        addItem(m_autoSelect, VAPP_NW_SELECT_AUTO_SELECT_ID);   
        
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

#if !defined(__LOW_COST_SUPPORT_COMMON__)
        VFX_OBJ_CREATE(m_autoPreference, VcpFormItemLauncherCell, this);
        m_autoPreference->setMainText(VAPP_NW_SELECT_AUTO_PREFERENCE_MAIN);
        m_autoPreference->setHintText(VAPP_NW_SELECT_AUTO_PREFERENCE_HINT);        
        m_autoPreference->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_autoPreference->m_signalTap.connect(this, &VappAutoNetworkSelectionForm::onEntryPreferrence);
        addItem(m_autoPreference, VAPP_NW_SELECT_AUTO_PREFERENCE_ID);  	
#endif //#if !defined(__LOW_COST_SUPPORT_COMMON__)
        m_isInit = VFX_TRUE;
	}
    
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
    {
        m_signalFormIsReady.emit();
    }
}

void VappAutoNetworkSelectionForm::onAutoSelectPlmn(VcpFormItemCell* sender, VfxId senderId)
{
    VFX_OBJ_CREATE(m_autoCampOnPopup, VcpIndicatorPopup, ((VfxPage*)getParent())->getMainScr());
    m_currentPopup = m_autoCampOnPopup;
    m_autoCampOnPopup->setText(STR_ID_VAPP_SETTING_AUTO_SELECT_NETWORK);
    m_autoCampOnPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_autoCampOnPopup->show(VFX_TRUE);
    VappNetworkSelectionInterface *nwSelectionInterface =  (VappNetworkSelectionInterface*)VFX_OBJ_GET_INSTANCE(VappNetworkSelectionInterface);
    nwSelectionInterface->m_signalAutoCampOnResult.connect(this, &VappAutoNetworkSelectionForm::autoSelectPlmnRsp);    
    nwSelectionInterface->autoCampOn();
}

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_DUAL_SIM_DYNAMIC_MODE__ */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

#if !defined(__LOW_COST_SUPPORT_COMMON__)
void VappAutoNetworkSelectionForm::onEntryPreferrence(VcpFormItemCell* sender, VfxId senderId)
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    prefNwSettingInterface->m_signalListReady.connect(this, &VappAutoNetworkSelectionForm::onPreferrenceListReady);
    prefNwSettingInterface->initInterface(m_sim, this);  
    prefNwSettingInterface->updateList();
}

void VappAutoNetworkSelectionForm::onPreferrenceListReady(VfxBool result)
{
    VappPreferredNwSettingInterface *prefNwSettingInterface = VFX_OBJ_GET_INSTANCE(VappPreferredNwSettingInterface);
    prefNwSettingInterface->m_signalListReady.disconnect(this, &VappAutoNetworkSelectionForm::onPreferrenceListReady);
    if (result)
	{
        VappSettingPreferredNetworkMainPage *page;
        VFX_OBJ_CREATE_EX(page, VappSettingPreferredNetworkMainPage, ((VfxPage*)getParent())->getMainScr(), (m_sim));
        ((VfxPage*)getParent())->getMainScr()->pushPage(0, page);
	}
    else
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE).getBuf());
        prefNwSettingInterface->closeInterface();
    }
}
#endif // #if !defined(__LOW_COST_SUPPORT_COMMON__)
void VappAutoNetworkSelectionForm::autoSelectPlmnRsp(VfxBool result)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] autoSelectPlmnRsp %d, m_autoCampOnPopup %d", result, m_autoCampOnPopup);
    if (m_autoCampOnPopup)
    {
        m_autoCampOnPopup->exit(VFX_TRUE);
        m_autoCampOnPopup = NULL;
    }
    m_currentPopup = NULL;
    if (!result)
    {
        VFX_OBJ_CREATE(m_failedPopup, VcpConfirmPopup, ((VfxPage*)getParent())->getMainScr());        
        m_currentPopup = m_failedPopup;
        m_failedPopup->setText(STR_ID_VAPP_SETTING_FAILED_TO_CONNECT);
        m_failedPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        m_failedPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        m_failedPopup->m_signalButtonClicked.connect(this, &VappAutoNetworkSelectionForm::onPopClicked);
        m_failedPopup->show(VFX_TRUE);
	}
    #ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__    
    VappNetworkCheckingController *networkCheckingController = VFX_OBJ_GET_INSTANCE(VappNetworkCheckingController);
    if (srv_nw_info_get_service_availability(m_sim == MMI_SIM1 ? MMI_SIM2 : MMI_SIM1) != SRV_NW_INFO_SA_FULL_SERVICE)
    {
	// If the other SIM is not in full service status, enable checking.
        networkCheckingController->enableNetworkChecking(m_sim);	
    }
    #endif /* __MMI_DUAL_SIM_DYNAMIC_MODE__ */
}

void VappAutoNetworkSelectionForm::onPopClicked(VfxObject* sender, VfxId id)
{
    if (m_failedPopup)
	{
	    m_failedPopup->exit(VFX_TRUE);
        m_failedPopup = NULL;
        m_currentPopup = NULL;
	}
}
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
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
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
/***************************************************************************** 
 * VappNetworkSelectionPlmnNode
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNetworkSelectionPlmnNode", VappNetworkSelectionPlmnNode, VappSettingPlmnNodeBase);
VappNetworkSelectionPlmnNode::VappNetworkSelectionPlmnNode(const CHAR* plmn, srv_netset_rat_mode_enum rat, VfxU8 type)
{
    memset(m_plmn, 0, (MAX_PLMN_LEN + 1));
    memcpy(m_plmn, plmn, (MAX_PLMN_LEN + 1));
    m_rat = rat;
    m_type = type;   
}   
VappNetworkSelectionPlmnNode::VappNetworkSelectionPlmnNode(VappNetworkSelectionPlmnNode *node)
{
    memset(m_plmn, 0, (MAX_PLMN_LEN + 1));
    memcpy(m_plmn, node->getPlmn(), (MAX_PLMN_LEN + 1));
    m_rat = node->getRat();
    m_type = node->getType();   
}

void VappNetworkSelectionPlmnNode::setValue(VappNetworkSelectionPlmnNode *node)
{
    memset(m_plmn, 0, (MAX_PLMN_LEN + 1));
    memcpy(m_plmn, node->getPlmn(), (MAX_PLMN_LEN + 1));
    m_rat = node->getRat();
    m_type = node->getType();   
}

/***************************************************************************** 
 * VappNetworkSelectionCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNetworkSelectionCell", VappNetworkSelectionCell, VcpFormItemLauncherCell);
void VappNetworkSelectionCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    VFX_OBJ_CREATE(m_iconFrame, VfxImageFrame, this);

    m_iconFrame->setRect(VfxRect(IMG_LEFT_GAPS, 
                             (getBounds().getHeight() - IMG_MAX_HEIGHT) / 2,
                             IMG_MAX_WIDTH,
                             IMG_MAX_HEIGHT));

    m_mainText->setRect(VfxRect(TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, 
                                 m_mainText->getPos().y,
                                 getRect().getWidth() - TEXT_LEFT_GAPS - TEXT_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH) - (IMG_2_MAX_WIDTH + IMG_2_RIGHT_GAPS),
                                 m_mainText->getRect().getHeight()));
}

void VappNetworkSelectionCell::onUpdate()
{
    VcpFormItemLauncherCell::onUpdate();
    if(m_mainText)
    {
        m_mainText->setPos(TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, m_mainText->getPos().y);
    }
    if(m_hintText)
    {
        m_hintText->setPos((TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH), m_hintText->getPos().y);
    }
}

void VappNetworkSelectionCell::setHintPosition()
{
    m_hintText->setAnchor(0,1.0);
    m_hintText->setPos((TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH), m_hintText->getPos().y);
}

/***************************************************************************** 
 * VappNetworkSelectionListParser
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNetworkSelectionListParser", VappNetworkSelectionListParser, VfxObject);
void VappNetworkSelectionListParser::updateList()
{
    ASSERT(m_sim != MMI_SIM_NONE);
    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
    #else
    updateListInt();
    #endif
}

void VappNetworkSelectionListParser::updateListInt()
{
    if (m_waitingForAbort)
    {
        m_waitingForAbort = VFX_FALSE;
        m_currentProcess = VAPP_NETWORK_SELECTION_NO_PROCESS;
        m_signalGetListAbort.emit(VFX_TRUE, VAPP_NETWORK_SELECTION_ABORT_GET_LIST);
        return;
    }
    m_currentProcess = VAPP_NETWORK_SELECTION_GET_LIST;
    srv_netset_get_plmn(m_sim, &VappNetworkSelectionListParser::getPlmnListProc, getObjHandle());
}

void VappNetworkSelectionListParser::updateListAfterCampOn()
{
    //
    CHAR currentPlmn[MAX_PLMN_LEN + 1];
	if (!srv_nw_info_get_nw_plmn(m_sim, currentPlmn, MAX_PLMN_LEN + 1))
	{
		memset(currentPlmn, 0x00, MAX_PLMN_LEN + 1);
	}
    
    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
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
    #endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

    VfxU8 i;
    for (i = 0; i < m_list->getCount(); i++)
    {
	VappNetworkSelectionPlmnNode *node = (VappNetworkSelectionPlmnNode*)m_list->getNode(i);
        if ((memcmp(node->getPlmn(), currentPlmn, MAX_PLMN_LEN) == 0)
    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
    #endif
            )
    	{
    	    node->setType(node->getType() | VAPP_SETTING_CURRENT_PLMN);
    	}
        else
        {
            node->setType(node->getType() & ~VAPP_SETTING_CURRENT_PLMN);
        }
    }
}

mmi_ret VappNetworkSelectionListParser::getPlmnListProc(mmi_event_struct *evt)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] getPlmnListProc 0");
    if (VappNetworkSelectionListParser::isGetListAborted() || !evt->user_data)
    {
	return MMI_RET_OK;
    }
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] getPlmnListProc 1");

    VappNetworkSelectionListParser *parser = (VappNetworkSelectionListParser*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);

    if (!parser)
	{
	    return MMI_RET_OK;
	}

    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] getPlmnListProc 2");

    if (evt->evt_id == EVT_ID_SRV_NETSET_GET_PLMN_RSP)
	{
	    parser->onGetPlmnList(evt);
	}
    else if (evt->evt_id == EVT_ID_SRV_NETSET_ABORT_PLMN_RSP)
	{
	    parser->m_signalGetListAbort.emit(VFX_TRUE, VAPP_NETWORK_SELECTION_ABORT_GET_LIST);
	}
	return MMI_RET_OK;
}

void VappNetworkSelectionListParser::onGetPlmnList(mmi_event_struct *evt)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] onGetPlmnList");
    m_currentProcess = VAPP_NETWORK_SELECTION_NO_PROCESS;
    srv_netset_rsp_event_struct *rsp_evt = (srv_netset_rsp_event_struct*)evt;
    mmi_nw_get_plmn_list_rsp_struct *get_plmn_rsp = (mmi_nw_get_plmn_list_rsp_struct*)(rsp_evt->rsp_data.get_plmn_rsp_data);
    
    if (rsp_evt->result == SRV_NETSET_RSP_RESULT_BUSY)
    {
        m_signalListReady.emit(VFX_FALSE, VAPP_NETWORK_SELECTION_GET_LIST);
    	return;
    }
    
    if (get_plmn_rsp->result.flag == L4C_OK 
        && get_plmn_rsp->length 
        && !srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        createList(get_plmn_rsp);
    }
    else
    {
        m_signalListReady.emit(VFX_FALSE, VAPP_NETWORK_SELECTION_GET_LIST);
    }
}

void VappNetworkSelectionListParser::createList(mmi_nw_get_plmn_list_rsp_struct *data)
{    
    VFX_OBJ_CREATE(m_list, VappSettingPlmnList, this);
    VfxU8 i = 0;
	CHAR currentPlmn[MAX_PLMN_LEN + 1];
    CHAR homePlmn[MAX_PLMN_LEN + 1];
    
	if (!srv_nw_info_get_nw_plmn(m_sim, currentPlmn, MAX_PLMN_LEN + 1))
	{
		memset(currentPlmn, 0x00, MAX_PLMN_LEN + 1);
	}
	if (!srv_sim_ctrl_get_home_plmn(m_sim, homePlmn, MAX_PLMN_LEN + 1))
	{
		memset(homePlmn, 0x00, MAX_PLMN_LEN + 1);
	}
    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
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
    #endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
    srv_nw_info_service_availability_enum serviceAvailability = srv_nw_info_get_service_availability(m_sim);

    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] createList service %d", serviceAvailability);
    
    for (i = 0; i < data->length; i++)
	{
	    l4c_rat_plmn_info_struct *dataStruct = (l4c_rat_plmn_info_struct*)(&data->list[i]);
		VappNetworkSelectionPlmnNode *node;
        VfxU8 type = VAPP_SETTING_PLMN_TYPE_NONE;
        // Check current PLMN
        if (strcmp((CHAR*)currentPlmn, (CHAR*)dataStruct->plmn_id) == 0 
            && (serviceAvailability == SRV_NW_INFO_SA_FULL_SERVICE) 
        #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
        #endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
            )
    	{
    	    type |= VAPP_SETTING_CURRENT_PLMN;
    	}

        // Check home PLMN
        if ((i < data->num_of_hplmn || (strcmp((CHAR*)homePlmn, (CHAR*)dataStruct->plmn_id) == 0))
            || (srv_netset_get_plmn_index((CHAR*)homePlmn) == srv_netset_get_plmn_index((CHAR*)dataStruct->plmn_id)))         // OP case
    	{
    	    type |= VAPP_SETTING_HOME_PLMN;
    	}        
        
        // Check forbidden PLMN
        else if (dataStruct->status == 3)
    	{
    	    type |= VAPP_SETTING_FORBIDDEN_PLMN;
    	}
        // Unknown PLMN
        else
        {
            type |= VAPP_SETTING_UNKNOWN_PLMN;
        }
        
        VFX_OBJ_CREATE_EX(node, VappNetworkSelectionPlmnNode, this, 
            ((const CHAR*)data->list[i].plmn_id, (srv_netset_rat_mode_enum)data->list[i].rat, type));
        m_list->appendNode(node);
	}
    m_signalListReady.emit(VFX_TRUE, VAPP_NETWORK_SELECTION_GET_LIST);
}

void VappNetworkSelectionListParser::abortGetList()
{
    if (m_currentProcess == VAPP_NETWORK_SELECTION_GET_LIST)
    {
        srv_netset_abort_plmn(m_sim, &VappNetworkSelectionListParser::getPlmnListProc, getObjHandle());	  
    }
    else if (m_currentProcess == VAPP_NETWORK_SELECTION_SWITCH_RAT)
    {
        m_waitingForAbort = VFX_TRUE;
    }
    else
    {
        m_signalGetListAbort.emit(VFX_TRUE, VAPP_NETWORK_SELECTION_ABORT_GET_LIST);
    }
}

void VappNetworkSelectionListParser::abortGetListBeforeClose()
{
    m_isGetListAborted = VFX_TRUE;
    abortGetList();
}

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
/***************************************************************************** 
 * VappNetworkSelectionListProvider
 *****************************************************************************/
VfxWString VappNetworkSelectionListProvider::getPlmnName(VfxId plmnId)
{
    VappNetworkSelectionPlmnNode *node = (VappNetworkSelectionPlmnNode*)m_list->getNode(plmnId);
    return node->getOperatorName();
}

VfxWString VappNetworkSelectionListProvider::getPlmnRat(VfxId plmnId)
{
    VfxWString temp_WString = VFX_WSTR_EMPTY;
    VappNetworkSelectionPlmnNode *node = (VappNetworkSelectionPlmnNode*)m_list->getNode(plmnId);
    switch (node->getRat())
	{
	case SRV_NETSET_RAT_GSM:
		temp_WString = VFX_WSTR("2G");
		break;

	case SRV_NETSET_RAT_UMTS:
		temp_WString = VFX_WSTR("3G");
		break;

	default:
        break;		
	}
    return temp_WString;
}

VfxId VappNetworkSelectionListProvider::getPlmnIconId(VfxId plmnId)
{
    VappNetworkSelectionPlmnNode *node = (VappNetworkSelectionPlmnNode*)m_list->getNode(plmnId);
    VfxId iconId = 0;
    if (node->getType() & VAPP_SETTING_HOME_PLMN)
	{
		iconId = IMG_ID_VAPP_SETTING_HOME_PLMN;
	}
    else if (node->getType() & VAPP_SETTING_UNKNOWN_PLMN)
    {
		iconId = IMG_ID_VAPP_SETTING_UNKNOWN_PLMN;    
    }
    else if (node->getType() & VAPP_SETTING_FORBIDDEN_PLMN)
    {
		iconId = IMG_ID_VAPP_SETTING_FORBIDDEN_PLMN;
    }

    if ((node->getType() & VAPP_SETTING_CURRENT_PLMN) && iconId != 0)
	{
	    // Selected icon ID = Non-selected icon ID + 1
	    iconId++;
	}
    return iconId;
}

VfxWString VappNetworkSelectionListProvider::getAdditonalInformation(VfxId plmnId)
{
    return VFX_WSTR_EMPTY;
}
/***************************************************************************** 
 * VappNetworkSelectionController
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNetworkSelectionController", VappNetworkSelectionController, VfxObject);
void VappNetworkSelectionController::campOn(mmi_sim_enum sim, VappNetworkSelectionPlmnNode *node)
{
    ASSERT(sim != MMI_SIM_NONE);
    m_campOnNode.setValue(node);
    m_isAutoCampOn = VFX_FALSE;
    m_sim = sim;
    campOnInt();
}

void VappNetworkSelectionController::campOnInt()
{
    ASSERT(m_sim != MMI_SIM_NONE);
    srv_netset_set_plmn_manual(
        m_sim, m_campOnNode.getPlmn(), 
        (srv_netset_rat_mode_enum)m_campOnNode.getRat(), 
        &VappNetworkSelectionController::campOnProc, 
        getObjHandle());
}

void VappNetworkSelectionController::autoCampOn(mmi_sim_enum sim)
{
    ASSERT(sim != MMI_SIM_NONE);
    m_isAutoCampOn = VFX_TRUE;
    srv_netset_set_plmn_auto(sim, &VappNetworkSelectionController::campOnProc, getObjHandle());
}

mmi_ret VappNetworkSelectionController::campOnProc(mmi_event_struct *evt)
{
    if (!evt->user_data)
	{
	    return MMI_RET_OK;
	}
    
    VappNetworkSelectionController *controller = (VappNetworkSelectionController*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    if (!controller)
	{
	    return MMI_RET_OK;
	}
    
    if (evt->evt_id == EVT_ID_SRV_NETSET_SET_PLMN_RSP)
	{
        srv_netset_rsp_event_struct *rspEvt = (srv_netset_rsp_event_struct*)evt;
        mmi_nw_set_plmn_rsp_struct *setPlmnRsp = (mmi_nw_set_plmn_rsp_struct*)(rspEvt->rsp_data.set_plmn_rsp_data);
        controller->campOnFinished(setPlmnRsp);
	}
	return MMI_RET_OK;
}

void VappNetworkSelectionController::campOnFinished(mmi_nw_set_plmn_rsp_struct *data)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] campOnFinished() data %d, m_isAutoCampOn %d", data, m_isAutoCampOn);

    if  (m_isAutoCampOn)
	{
        VfxBool result = ((data->result.flag == L4C_OK) && (data->status == L4C_RAC_OK) ? VFX_TRUE : VFX_FALSE);
   	    m_signalAutoCampOnResult.emit(result, VAPP_NETWORK_SELECTION_AUTO_CAMP_ON);
	}
    else
    {
        if((data->result.flag == L4C_OK) && (data->status == L4C_RAC_OK)
            && !strcmp((CHAR*)(m_campOnNode.getPlmn()), (CHAR*)data->plmn)
            #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
            #endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
           )
        {
            m_signalCampOnResult.emit(VFX_TRUE, VAPP_NETWORK_SELECTION_CAMP_ON);
        }
        else
        {
            // TODO: Add this PLMN to forbidden list
            m_signalCampOnResult.emit(VFX_FALSE, VAPP_NETWORK_SELECTION_CAMP_ON);                
        }		
        m_sim = MMI_SIM_NONE;
    }
}
/***************************************************************************** 
 * VappNetworkSelectionInterface
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappNetworkSelectionInterface);
VfxBool VappNetworkSelectionInterface::updateList(VfxObject *parent)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] Update list");
    if (!m_parser)
	{
        VFX_OBJ_CREATE_EX(m_parser, VappNetworkSelectionListParser, parent, (m_sim));
        m_parser->m_signalListReady.connect(this, &VappNetworkSelectionInterface::processSignal);
        m_parser->m_signalGetListAbort.connect(this, &VappNetworkSelectionInterface::processSignal);
	}

    if (!m_provider)
	{
        VFX_OBJ_CREATE(m_provider, VappNetworkSelectionListProvider, parent);
	}

    if (m_list)
	{
        VFX_OBJ_CLOSE(m_list);
        m_list = NULL;	
	}
    setProcess(VAPP_NETWORK_SELECTION_GET_LIST);
    m_parser->updateList();
    return VFX_TRUE;
}

void VappNetworkSelectionInterface::updateListAfterCampOn()
{
    ASSERT(m_parser);
    m_parser->updateListAfterCampOn();
}

void VappNetworkSelectionInterface::abortGetList() 
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] Abort get list");
    //ASSERT(m_parser);
    if (NULL != m_parser)
    {
        setProcess(VAPP_NETWORK_SELECTION_ABORT_GET_LIST);
        m_parser->abortGetList();
    }
}

VfxU16 VappNetworkSelectionInterface::getCount() 
{
    ASSERT(m_list);
    return m_list->getCount();
}

VfxWString VappNetworkSelectionInterface::getPlmnName(VfxId plmnId) 
{
    ASSERT(m_provider);
    return m_provider->getPlmnName(plmnId);
}

VfxWString VappNetworkSelectionInterface::getPlmnRat(VfxId plmnId) 
{
    ASSERT(m_provider);
    return m_provider->getPlmnRat(plmnId);
}


VfxId VappNetworkSelectionInterface::getPlmnIconId(VfxId plmnId) 
{
    ASSERT(m_provider);
    return m_provider->getPlmnIconId(plmnId);
}

VfxWString VappNetworkSelectionInterface::getAdditonalInformation(VfxId plmnId) 
{
    ASSERT(m_provider);
    return m_provider->getAdditonalInformation(plmnId);
}

void VappNetworkSelectionInterface::campOn(VfxId plmnId) 
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] Camp on %d", plmnId);
    ASSERT(m_list);
    setProcess(VAPP_NETWORK_SELECTION_CAMP_ON);
    m_controller.campOn(m_sim, (VappNetworkSelectionPlmnNode*)m_list->getNode(plmnId));
}

void VappNetworkSelectionInterface::autoCampOn()
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] Auto camp on");
    setProcess(VAPP_NETWORK_SELECTION_AUTO_CAMP_ON);
    m_controller.autoCampOn(m_sim);    
}

    // Internal used
void VappNetworkSelectionInterface::processSignal(VfxBool result, VappNetworkSelectionProcessState processType)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] process signal result %d, type %d, m_list %d", result, processType, m_list);
    switch (processType)
	{
	case VAPP_NETWORK_SELECTION_GET_LIST:
        if (result)
    	{
    		m_list = m_parser->getList();
            m_provider->setList(m_list);
    	}
        m_signalListReady.emit(result);
		break;
        
    case VAPP_NETWORK_SELECTION_ABORT_GET_LIST:
        m_signalAbortGetList.emit(result);
        break;

    case VAPP_NETWORK_SELECTION_CAMP_ON:
        m_signalCampOnResult.emit(result);
        break;

    case VAPP_NETWORK_SELECTION_AUTO_CAMP_ON:
        m_signalAutoCampOnResult.emit(result);
        break;        
        
	default:
        ASSERT(0);
		break;
	}
    endProcess();
}

/***************************************************************************** 
 * VappManualNetworkSearchingPopup()
 *****************************************************************************/
void VappManualNetworkSearchingPopup::onDeinit()
{
    VcpIndicatorPopup::onDeinit();
    m_signalPopupDestroyed.emit();
}

/***************************************************************************** 
 * VappManualNetworkSelectionForm
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappManualNetworkSelectionForm", VappManualNetworkSelectionForm, VcpForm);
void VappManualNetworkSelectionForm::onDeinit()
{
    if (m_currentPopup != NULL)
	{
	    m_currentPopup->exit(VFX_TRUE);
	}
    VcpForm::onDeinit();
}

void VappManualNetworkSelectionForm::clearCell()
{
    // Clear all PLMN cell
    VfxU8 i;
    VfxU8 staticCellNum = VAPP_NW_SELECT_MANUAL_CAPTION_ID + 1;
    for (i = VAPP_NW_SELECT_MANUAL_PLMN_START; getItemCount() > staticCellNum; i++)
	{
		removeItem(i);
	}
}

void VappManualNetworkSelectionForm::updateForm()
{
    if (!m_isInit)
	{
        VFX_OBJ_CREATE(m_manualRefreshCell, VcpFormItemLauncherCell, this);
        m_manualRefreshCell->setMainText(VAPP_NW_SELECT_MANUAL_REFRESH_MAIN);
        m_manualRefreshCell->setHintText(VAPP_NW_SELECT_MANUAL_REFRESH_HINT);
        m_manualRefreshCell->m_signalTap.connect(this, &VappManualNetworkSelectionForm::onManualRefresh);
        addItem(m_manualRefreshCell, VAPP_NW_SELECT_MANUAL_REFRESH_ID);    

        VcpFormItemCaption *caption;
        VFX_OBJ_CREATE(caption, VcpFormItemCaption, this);
        caption->setText(VAPP_NW_SELECT_MANUAL_OPERATOR_CAPTION);
        addItem(caption, VAPP_NW_SELECT_MANUAL_CAPTION_ID);	

        m_isInit = VFX_TRUE;
	}
    
    // Clear all PLMN cell
    clearCell();
    

    // Disable Refresh cell
    m_manualRefreshCell->setIsDisabled(VFX_TRUE);

    if (m_searchingPopup)
	{
	    ASSERT(0);
	}
    // Show searching popup
    VFX_OBJ_CREATE(m_searchingPopup, VappManualNetworkSearchingPopup, ((VfxPage*)getParent())->getMainScr());        
    m_currentPopup = m_searchingPopup;
    m_searchingPopup->setText(STR_ID_VAPP_SETTING_SEARCHING_AVAILABLE_NETWORKS);
    m_searchingPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    m_searchingPopup->m_signalButtonClicked.connect(this, &VappManualNetworkSelectionForm::onCancelSearching);
    m_searchingPopup->m_signalPopupDestroyed.connect(this, &VappManualNetworkSelectionForm::stopManualRefreshWhenExitPopup);
    m_searchingPopup->setAutoDestory(VFX_TRUE);
    m_searchingPopup->show(VFX_TRUE);

    VappNetworkSelectionInterface *nwSelectionInterface = VFX_OBJ_GET_INSTANCE(VappNetworkSelectionInterface);
    nwSelectionInterface->m_signalListReady.connect(this, &VappManualNetworkSelectionForm::onPlmnListReady);

    VfxObject* thisParent = getParent();
    nwSelectionInterface->updateList(thisParent);
}

void VappManualNetworkSelectionForm::onCancelSearching(VfxObject* sender, VfxId id)
{
    // If get list process is already canceled because of popup destroyed, m_searchingPopup = NULL
    // Check if m_searchingPopup exsit to avoid send duplicate abort message
    if (id == 'NoOK' && m_searchingPopup)
	{
	    stopManualRefresh();
	}
}
void VappManualNetworkSelectionForm::onManualRefresh(VcpFormItemCell* sender, VfxId senderId)
{
    updateForm();
}

void VappManualNetworkSelectionForm::stopManualRefreshWhenExitPopup()
{
    m_searchingPopup = NULL;
    m_currentPopup = NULL;
    stopManualRefresh();
}

void VappManualNetworkSelectionForm::stopManualRefresh()
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] stop manual refresh");
    if (m_searchingPopup)
    {
        m_searchingPopup->m_signalPopupDestroyed.disconnect(this, &VappManualNetworkSelectionForm::stopManualRefreshWhenExitPopup);
        m_searchingPopup->exit(VFX_TRUE);
        m_searchingPopup = NULL;	
        m_currentPopup = NULL;
    }

    VcpIndicatorPopup *popup;
    VFX_OBJ_CREATE(popup, VcpIndicatorPopup, ((VfxPage*)getParent())->getMainScr());
    popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    popup->setText(STR_GLOBAL_PLEASE_WAIT);
    popup->show(VFX_TRUE);
    m_currentPopup = popup;
    
    VappNetworkSelectionInterface *nwSelectionInterface = VFX_OBJ_GET_INSTANCE(VappNetworkSelectionInterface);
    nwSelectionInterface->m_signalAbortGetList.connect(this, &VappManualNetworkSelectionForm::stopManualRefreshDone);
    nwSelectionInterface->abortGetList();
}

void VappManualNetworkSelectionForm::stopManualRefreshDone(VfxBool result)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Network selection] stop manula refresh done");
    VappNetworkSelectionInterface *nwSelectionInterface = VFX_OBJ_GET_INSTANCE(VappNetworkSelectionInterface);    
    nwSelectionInterface->m_signalListReady.disconnect(this, &VappManualNetworkSelectionForm::onPlmnListReady);
    m_manualRefreshCell->setIsDisabled(VFX_FALSE);
    if (m_currentPopup != NULL)
    {
	m_currentPopup->exit(VFX_TRUE);
        m_currentPopup = NULL;
    }
}
void VappManualNetworkSelectionForm::onPlmnListReady(VfxBool result)
{
    if (m_searchingPopup)
    {
    m_searchingPopup->m_signalPopupDestroyed.disconnect(this, &VappManualNetworkSelectionForm::stopManualRefreshWhenExitPopup);
    }
    
    if (result)
    {
        updatePlmnList();
    }
    else
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE, 
            VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE).getBuf());
    }
    
    if (m_searchingPopup)
	{
        m_searchingPopup->exit(VFX_TRUE);
        m_searchingPopup = NULL;
        m_currentPopup = NULL;
	}
    m_manualRefreshCell->setIsDisabled(VFX_FALSE);
}

void VappManualNetworkSelectionForm::updatePlmnList()
{
    VfxU8 baseId = VAPP_NW_SELECT_MANUAL_CAPTION_ID + 1;
    VfxU8 i;
    clearCell();
    VappNetworkSelectionInterface *nwSelectionInterface = VFX_OBJ_GET_INSTANCE(VappNetworkSelectionInterface);
    for (i = 0; i < nwSelectionInterface->getCount(); i++)
	{
	    VappNetworkSelectionCell *cell;
        VFX_OBJ_CREATE(cell, VappNetworkSelectionCell, this);
        cell->setMainText(nwSelectionInterface->getPlmnName(i));
        cell->setHintText(nwSelectionInterface->getPlmnRat(i));
        cell->setHintPosition();
        cell->setIconResId(nwSelectionInterface->getPlmnIconId(i));
        cell->m_signalTap.connect(this, &VappManualNetworkSelectionForm::onCampOn);
        addItem(cell, (baseId + i));
	}	
}

void VappManualNetworkSelectionForm::onCampOn(VcpFormItemCell* sender, VfxId senderId)
{
    m_selectId = senderId - (VAPP_NW_SELECT_MANUAL_CAPTION_ID + 1);
    campOnPlmn(m_selectId);
}
void VappManualNetworkSelectionForm::campOnPlmn(VfxId plmnId)
{
/*
    VfxWString popupString = VFX_WSTR("Connecting to ");
    popupString += nwSelectionInterface->getPlmnName(plmnId);
*/
    VFX_OBJ_CREATE(m_progressPopup, VcpIndicatorPopup, findScreen());
    m_currentPopup = m_progressPopup;
    m_progressPopup->setText(STR_ID_VAPP_SETTING_CONNECTING);
    m_progressPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_progressPopup->show(VFX_TRUE);  

    VappNetworkSelectionInterface *nwSelectionInterface = VFX_OBJ_GET_INSTANCE(VappNetworkSelectionInterface);    
    nwSelectionInterface->m_signalCampOnResult.connect(this, &VappManualNetworkSelectionForm::onCampOnFinish);
    nwSelectionInterface->campOn(plmnId);    

    #ifdef __MMI_DUAL_SIM_DYNAMIC_MODE__    
    VappNetworkCheckingController *networkCheckingController = VFX_OBJ_GET_INSTANCE(VappNetworkCheckingController);
    VfxU8 i;
    for (i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
		if (srv_nw_info_get_service_availability(mmi_frm_index_to_sim(i)) == SRV_NW_INFO_SA_FULL_SERVICE)
		{
		    break;
		}
	}
    if (i == MMI_MAX_SIM_NUM)
    {
   	    // All the SIM is not in full service status, enable checking.
   	    // If one SIM is in full service, when camp on PLMN failed,
   	    // it will automatically camp on the previouse one
   	    // Thus it is no need to check the service
        networkCheckingController->enableNetworkChecking(m_sim);	
    }
    #endif /* __MMI_DUAL_SIM_DYNAMIC_MODE__ */
}

void VappManualNetworkSelectionForm::onCampOnFinish(VfxBool result)
{
    if (m_progressPopup)
    {
    m_progressPopup->exit(VFX_TRUE);
    m_progressPopup = NULL;
    }

    m_currentPopup = NULL;
    if (!result)
	{
        VFX_OBJ_CREATE(m_retryPopup, VcpConfirmPopup, findScreen());        
        m_currentPopup = m_retryPopup;
        m_retryPopup->setText(STR_GLOBAL_NOT_AVAILABLE);
        m_retryPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_retryPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        m_retryPopup->setCustomButton(STR_ID_VAPP_SETTING_RETRY, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_retryPopup->m_signalButtonClicked.connect(this, &VappManualNetworkSelectionForm::onPopClicked);
        m_retryPopup->show(VFX_TRUE);
	}
    else
    {
        VappNetworkSelectionInterface *nwSelectionInterface = VFX_OBJ_GET_INSTANCE(VappNetworkSelectionInterface);
        nwSelectionInterface->updateListAfterCampOn();
        updatePlmnList();
    }
}

void VappManualNetworkSelectionForm::onPopClicked(VfxObject* sender, VfxId id)
{
    if (id == 'USR1')
	{
        campOnPlmn(m_selectId);
	}
    if (m_retryPopup)
	{
	    m_retryPopup->exit(VFX_TRUE);
        m_retryPopup = NULL;
        m_currentPopup = NULL;
	}
}

