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
 *  vapp_callset.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

extern "C" 
{
#include "GlobalResDef.h"
#include "CallSetSrvGprot.h"
#include "CallSetSrvIprot.h" // srv_callset_is_available
#include "SsSrvGprot.h" // srv_ss_act_req
#include "UcmSrvGprot.h" // SRV_UCM_MAX_NUM_URI_LEN
#include "Custom_phb_config.h" // MMI_PHB_NUMBER_PLUS_LENGTH
#include "SimCtrlSrvGprot.h" // EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED
#include "ModeSwitchSrvGprot.h"  // EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY
#include "wgui_categories_util.h" // wgui_status_icon_bar_xxx
#include "NotificationGprot.h"

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif
}

#include "Mmi_rp_vapp_callset_def.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "mmi_rp_app_cosmos_global_def.h"

#include "App_str.h" /* app_ucs2_itoa */

#include "vfx_signal.h"
#include "vfx_text_frame.h"

#include "vcp_command_popup.h"
#include "vcp_confirm_popup.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_form.h"
#include "vcp_function_bar.h"
#include "vcp_indicator_popup.h"

#include "Vcui_phb_gprot.h"
#include "Vcui_secset_gprot.h"
#include "Vapp_sim_setting_gprot.h"

#include "vapp_callset.h"
#include "vapp_callset_cf.h"
#include "vapp_callset_cb.h"
#ifdef __MMI_VIDEO_TELEPHONY__
#include "vapp_callset_vt.h"
#endif /* __MMI_VIDEO_TELEPHONY__ */
#ifdef __MMI_CALLSET_CUG__
#include "vapp_callset_cug.h"
#endif
#ifdef __CTM_SUPPORT__
#include "vapp_callset_ctm.h"
#endif

#pragma arm section code = "DYNAMIC_CODE_CALLSET_ROCODE", rodata = "DYNAMIC_CODE_CALLSET_RODATA"  
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_CALLSET_WAIT_POPUP(_wait, _parent, _text, _cb) \
		do														\
		{														\
			VFX_OBJ_CREATE(_wait, VcpIndicatorPopup, this); 	\
			_wait->setInfoType(_cb ? VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON : VCP_INDICATOR_POPUP_STYLE_ACTIVITY); \
			_wait->setText(_text);								\
			if (_cb)											\
			{													\
				_wait->m_signalCanceled.connect(this, _cb); 	\
			}													\
			_wait->setAutoDestory(VFX_TRUE);					\
			_wait->show(VFX_TRUE);								\
		} while(0)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VappCallSetCntx *callset_p = NULL;

/***************************************************************************** 
 * Function
 *****************************************************************************/

extern "C" mmi_ret vapp_callset_hdlr_rsp(mmi_event_struct *info)
{
    if (!callset_p ||
            callset_p->m_asyncPage == NULL)
    {
        return MMI_RET_OK;
    }

    callset_p->m_asyncPage->onResult(info);

    return MMI_RET_OK;
}

#pragma arm section code, rodata

extern "C" mmi_ret vapp_callset_hdlr_cfu_status_ind(mmi_event_struct *info)
{
	srv_callset_cfu_status_evt_struct *cfu_evt = (srv_callset_cfu_status_evt_struct *)info;

    if ((cfu_evt->status & SRV_CALLSET_CFU_LINE1_ACTIVATED) || (cfu_evt->status  & SRV_CALLSET_CFU_LINE2_ACTIVATED))
    {
		VappCallSetPageMain::s_cfuBit = (mmi_sim_enum)(VappCallSetPageMain::s_cfuBit | cfu_evt->sim);
    }
    else
    {        
		VappCallSetPageMain::s_cfuBit = (mmi_sim_enum)(VappCallSetPageMain::s_cfuBit & (~cfu_evt->sim));
    }

	if (VappCallSetPageMain::s_cfuBit != MMI_SIM_NONE)
	{
		wgui_status_icon_bar_set_icon_display(STATUS_ICON_CALL_FORWARD);
	}
	else
	{
		wgui_status_icon_bar_reset_icon_display(STATUS_ICON_CALL_FORWARD);
	}

    wgui_status_icon_bar_update();

    return MMI_RET_OK;
}


void vapp_callset_attach_cell(VfxMainScr *mainScr)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("cin", SA_start);
#endif

    VappCallSetPageMain *page;
    VFX_OBJ_CREATE(page, VappCallSetPageMain, mainScr);
    mainScr->pushPage(VFX_ID_NULL, page);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("cin", SA_stop);
#endif
}

mmi_sim_enum VappCallSetPageMain::s_cfuBit = MMI_SIM_NONE;

VappCallSetPageMain::VappCallSetPageMain()
	: m_redial(NULL),
	  m_ctr(NULL),
 	  m_quickEnd(NULL),
	  m_quickEndTime(NULL),
	  m_ctmSetting(NULL),
	  m_form(NULL)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
		DCM_Load(DYNAMIC_CODE_COMPRESS_CALLSET, 0, 0);
#endif
}

VappCallSetPageMain::~VappCallSetPageMain()
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
		DCM_Unload(DYNAMIC_CODE_COMPRESS_CALLSET);
#endif
}

#pragma arm section code = "DYNAMIC_CODE_CALLSET_ROCODE", rodata = "DYNAMIC_CODE_CALLSET_RODATA" 
void VappCallSetPageMain::onInit()
{
    VfxPage::onInit(); // call base class
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappCallSetPageMain::hdlrModeChange, getObjHandle());
    if (!callset_p)
    {
        VFX_OBJ_CREATE(callset_p, VappCallSetCntx, this); 
    }

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_CALLSET_CALL_SETTING);
    setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemLauncherCell *launch;

#ifdef __MMI_CM_BLACK_LIST__
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c01", SA_start);
#endif

    /* black list */
    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
    launch->setMainText(STR_ID_VAPP_CALLSET_BLACKLIST);
    launch->setHintText(STR_ID_VAPP_CALLSET_BLACKLIST_HINT);
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
    m_form->addItem(launch, ID_LAUNCH_CALLSET_BL);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c01", SA_stop);
#endif
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c02", SA_start);
#endif

#ifdef __MMI_CM_WHITE_LIST__
    /* white list */
    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
    launch->setMainText(STR_ID_VAPP_CALLSET_WHITELIST);
    launch->setHintText(STR_ID_VAPP_CALLSET_WHITELIST_HINT);
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
    m_form->addItem(launch, ID_LAUNCH_CALLSET_WL);
#endif /* __MMI_CM_WHITE_LIST__ */

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c02", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c03", SA_start);
#endif

    /* Auto redial */
    VFX_OBJ_CREATE(m_redial, VcpFormItemLauncherCell, m_form);
    m_redial->setMainText(STR_ID_VAPP_CALLSET_AUTOREDIAL);
    m_redial->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_redial->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
    m_form->addItem(m_redial, ID_LAUNCH_CALLSET_REDIAL);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c03", SA_stop);
#endif

#if 1
#ifdef __IP_NUMBER__
    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
    launch->setMainText(STR_ID_VAPP_CALLSET_IP_NUMBER);
    launch->setHintText(STR_ID_VAPP_CALLSET_IP_SET);
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
    m_form->addItem(launch, ID_LAUNCH_CALLSET_IP_NUM);
#endif /* __IP_NUMBER__ */
#endif


#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c04", SA_start);
#endif

    VcpFormItemSwitchCell *swh;

#ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
    /* call time display */
    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, m_form);
    swh->setMainText(STR_ID_VAPP_CALLSET_CTD);
    swh->setHintText(STR_ID_VAPP_CALLSET_CTD_HINT);
    swh->setSwitchStatus(
            srv_callset_call_time_display_get_mode() ? 
            VFX_TRUE : VFX_FALSE);
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageMain::onSwitch);
	swh->m_signalToggleAnimationDone.connect(this, &VappCallSetPageMain::onAniDone);
	
    m_form->addItem(swh, ID_LAUNCH_CALLSET_CTD);
#endif /* __MMI_CALLSET_CTD_CONFIGURABLE__ */
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c04", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c05", SA_start);
#endif

    /* call time reminder */
    VFX_OBJ_CREATE(m_ctr, VcpFormItemLauncherCell, m_form);
    m_ctr->setMainText(STR_ID_VAPP_CALLSET_CTR);
    m_ctr->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_ctr->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
    m_form->addItem(m_ctr, ID_LAUNCH_CALLSET_CTR);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c05", SA_stop);
#endif


#ifdef __MMI_CH_QUICK_END__
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c06", SA_start);
#endif

    /* quick end */
    VFX_OBJ_CREATE(m_quickEnd, VcpFormItemSwitchCell, m_form);
    m_quickEnd->setMainText(STR_ID_VAPP_CALLSET_QUICK_END);
    m_quickEnd->m_signalSwitchChangeReq.connect(this, &VappCallSetPageMain::onSwitch);
	m_quickEnd->m_signalToggleAnimationDone.connect(this, &VappCallSetPageMain::onAniDone);
    m_form->addItem(m_quickEnd, ID_LAUNCH_CALLSET_QUICK_END);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c06", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c07", SA_start);
#endif

    VFX_OBJ_CREATE(m_quickEndTime, VcpFormItemLauncherCell, m_form);
    m_quickEndTime->setMainText(STR_ID_VAPP_CALLSET_QUICK_END_TIME);
    m_quickEndTime->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_quickEndTime->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
    m_form->addItem(m_quickEndTime, ID_LAUNCH_CALLSET_QUICK_END_TIME);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c07", SA_stop);
#endif
#endif /* __MMI_CH_QUICK_END__ */

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c08", SA_start);
#endif

#ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
    /* reject unknown caller */
    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, m_form);
    swh->setMainText(STR_ID_VAPP_CALLSET_BLACKLIST_REJ_UNKNOWN_NUM);
    swh->setSwitchStatus(
            (srv_callset_blacklist_get_mode(NULL) & SRV_CALLSET_BLACKLIST_UNKNOWN_CALLER) ? 
            VFX_TRUE : VFX_FALSE);
    swh->setHintText(STR_ID_VAPP_CALLSET_BLACKLIST_REJ_UNKNOWN_NUM);
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageMain::onSwitch);
	swh->m_signalToggleAnimationDone.connect(this, &VappCallSetPageMain::onAniDone);
    m_form->addItem(swh, ID_LAUNCH_CALLSET_REJECT_UNKNOWN_CALLER);
#endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c08", SA_stop);
#endif


#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c09", SA_start);
#endif

#ifdef __MMI_UCM_REJECT_BY_SMS__
    /* reject by sms */
    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
    launch->setMainText(STR_ID_VAPP_CALLSET_REJ_BY_SMS);
    launch->setHintText(STR_ID_VAPP_CALLSET_REJ_BY_SMS_HINT);
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
    m_form->addItem(launch, ID_LAUNCH_CALLSET_REJECT_BY_SMS);
#endif /* __MMI_UCM_REJECT_BY_SMS__ */

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c09", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c10", SA_start);
#endif

#ifdef __MMI_CONNECT_NOTICE__
    /* connect notice */
    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, m_form);
    swh->setMainText(STR_ID_VAPP_CALLSET_CONNECT_NOTICE);
    swh->setSwitchStatus(
            srv_callset_connect_notice_get_mode() ? 
            VFX_TRUE : VFX_FALSE);
    swh->setHintText(STR_ID_VAPP_CALLSET_CONNECT_NOTICE_HINT);
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageMain::onSwitch);
	swh->m_signalToggleAnimationDone.connect(this, &VappCallSetPageMain::onAniDone);
    m_form->addItem(swh, ID_LAUNCH_CALLSET_CONNECT_NOTICE);
#endif /* __MMI_CONNECT_NOTICE__ */

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c10", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c12", SA_start);
#endif

    /* answer mode */
    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, m_form);
    swh->setMainText(STR_ID_VAPP_CALLSET_AUTO_ANS);
    swh->setHintText(STR_ID_VAPP_CALLSET_ANS_MODE_AUTO);
    swh->setSwitchStatus(
            (srv_callset_answer_mode_get_mode() & SRV_CALLSET_ANSWER_MODE_AUTO) ? 
            VFX_TRUE : VFX_FALSE);
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageMain::onSwitch);
	swh->m_signalToggleAnimationDone.connect(this, &VappCallSetPageMain::onAniDone);
    m_form->addItem(swh, ID_LAUNCH_CALLSET_ANSWER_MODE);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c12", SA_stop);
#endif

#ifdef __CTM_SUPPORT__
    /* ctm */

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c13", SA_start);
#endif

    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, m_form);
    swh->setMainText(STR_ID_VAPP_CALLSET_CTM);
    swh->setSwitchStatus(srv_callset_ctm_get_mode() ? VFX_TRUE : VFX_FALSE);
    swh->setHintText(STR_ID_VAPP_CALLSET_CTM_HINT);
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageMain::onSwitch);
	swh->m_signalToggleAnimationDone.connect(this, &VappCallSetPageMain::onAniDone);

    m_form->addItem(swh, ID_LAUNCH_CALLSET_CTM);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c13", SA_stop);
#endif


#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c14", SA_start);
#endif

    VFX_OBJ_CREATE(m_ctmSetting, VcpFormItemLauncherCell, m_form);
    m_ctmSetting->setMainText(STR_ID_VAPP_CALLSET_CTM_MODE);
    m_ctmSetting->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_ctmSetting->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
    m_form->addItem(m_ctmSetting, ID_LAUNCH_CALLSET_CTM_MODE);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c14", SA_stop);
#endif

#endif /* __CTM_SUPPORT__ */

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c15", SA_start);
#endif

#ifdef __MMI_VIDEO_TELEPHONY__
    /* VT */
    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
    launch->setMainText(STR_ID_VAPP_CALLSET_VT);
    launch->setHintText(STR_ID_VAPP_CALLSET_VT_HINT);
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
    m_form->addItem(launch, ID_LAUNCH_CALLSET_VT);
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c15", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c16", SA_start);
#endif

	/* advanced */
	VFX_OBJ_CREATE(m_additionalSetting, VcpFormItemLauncherCell, m_form);
	m_additionalSetting->setMainText(STR_ID_VAPP_CALLSET_MORE);
	m_additionalSetting->setHintText(STR_ID_VAPP_CALLSET_MORE_HINT);
	m_additionalSetting->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	m_additionalSetting->m_signalTap.connect(this, &VappCallSetPageMain::onItemTap);
	m_form->addItem(m_additionalSetting, ID_LAUNCH_CALLSET_ADITIONAL_SETTINGS);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c16", SA_stop);
#endif
}

void VappCallSetPageMain::onDeinit()
{
    callset_p = NULL;
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappCallSetPageMain::hdlrModeChange, getObjHandle());

    VfxPage::onDeinit();
}

void VappCallSetPageMain::onEnter(VfxBool isBackward)
{
    updateForm();
}

void VappCallSetPageMain::updateForm(void)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c17", SA_start);
#endif

    /* redial */
    switch (srv_callset_redial_get_mode())
    {
        case SRV_CALLSET_REDIAL_AUTO:
            m_redial->setHintText(STR_ID_VAPP_CALLSET_AUTOREDIAL_ALWAYS);
            break;

        case SRV_CALLSET_REDIAL_OFF:
            m_redial->setHintText(STR_ID_VAPP_CALLSET_AUTOREDIAL_NEVER);
            break;

        case SRV_CALLSET_REDIAL_CONFIRM:
            m_redial->setHintText(STR_ID_VAPP_CALLSET_AUTOREDIAL_CONF);
            break;
    }

    /* call time reminder */
    srv_callset_ctr_struct ctr_info;
    VfxWString tmp_str;
    VfxWChar time_str[5];
    memset(time_str, 0, sizeof(time_str));
    if (srv_callset_ctr_get_mode(&ctr_info) == SRV_CALLSET_RESULT_OK)
    {
        switch (ctr_info.mode)
        {
            case SRV_CALLSET_CTR_MODE_SINGLE:
                tmp_str.loadFromRes(STR_ID_VAPP_CALLSET_CTR_SING);
                tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_LEFT_PARENTHESIS);
                break;

            case SRV_CALLSET_CTR_MODE_PERIODIC:
                tmp_str.loadFromRes(STR_ID_VAPP_CALLSET_CTR_PERIOD);
                tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_LEFT_PARENTHESIS);
                break;

            default:
                tmp_str.loadFromRes(STR_GLOBAL_OFF);
                break;
        }
        if (ctr_info.mode == SRV_CALLSET_CTR_MODE_SINGLE ||
             ctr_info.mode == SRV_CALLSET_CTR_MODE_PERIODIC)
        {
            if (ctr_info.time > 9999)
            {
                ctr_info.mode = SRV_CALLSET_CTR_MODE_OFF;
                tmp_str.loadFromRes(STR_GLOBAL_OFF);
            }
            else
            {
                app_ucs2_itoa(ctr_info.time, (kal_int8*)time_str, 10);
                tmp_str += VFX_WSTR_MEM(time_str);
                tmp_str += VFX_WSTR_RES((ctr_info.time < 2) ? STR_ID_VAPP_CALLSET_SEC : STR_ID_VAPP_CALLSET_SECS);
                tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_RIGHT_PARENTHESIS);
            }
        }
    }
    else
    {
        tmp_str.loadFromRes(STR_GLOBAL_OFF);
    }
    m_ctr->setHintText(tmp_str);


    /* quick end */
#ifdef __MMI_CH_QUICK_END__
    if (srv_callset_auto_quick_end_get_mode(
            (MMI_BOOL*)&(callset_p->m_inQuickEnd), 
            (U16*)&(callset_p->m_inQuickEndTime)) == SRV_CALLSET_RESULT_OK)
    {
        if (callset_p->m_inQuickEnd)
        {
            m_quickEnd->setSwitchStatus(VFX_TRUE);

            memset(time_str, 0, sizeof(time_str));
            app_ucs2_itoa((kal_int32)callset_p->m_inQuickEndTime, 
                (kal_int8*)time_str, 10);
            tmp_str.loadFromRes(STR_ID_VAPP_CALLSET_QUICK_END_HINT1);
            tmp_str += VFX_WSTR_MEM(time_str);
            if (callset_p->m_inQuickEndTime == 1)
            {
                tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_SEC);
            }
            else
            {
                tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_SECS);
            }
            tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_QUICK_END_HINT2);
            m_quickEnd->setHintText(tmp_str);

            tmp_str.loadFromMem(time_str);
            if (callset_p->m_inQuickEndTime == 1)
            {
                tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_SEC);
            }
            else
            {
                tmp_str += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_SECS);
            }
            m_quickEndTime->setHintText(tmp_str);
        }
        else
        {
			m_quickEnd->setSwitchStatus(VFX_FALSE);
            m_quickEnd->setHintText(STR_GLOBAL_OFF);
            m_quickEndTime->setHintText(STR_GLOBAL_OFF);
        }
    }
    else
    {
        m_quickEnd->setSwitchStatus(VFX_FALSE);
        m_quickEnd->setHintText(STR_GLOBAL_OFF);
        m_quickEndTime->setHintText(STR_GLOBAL_OFF);
    }
#endif /* __MMI_CH_QUICK_END__ */

#ifdef __CTM_SUPPORT__
    /* ctm */
    switch (srv_callset_ctm_get_setting())
    {
        case SRV_CALLSET_CTM_SETTING_BAUDOT:
            m_ctmSetting->setHintText(STR_ID_VAPP_CALLSET_CTM_BAUDOT);
            break;

        case SRV_CALLSET_CTM_SETTING_HCO:
            m_ctmSetting->setHintText(STR_ID_VAPP_CALLSET_CTM_HCO);
            break;

        case SRV_CALLSET_CTM_SETTING_VCO:
            m_ctmSetting->setHintText(STR_ID_VAPP_CALLSET_CTM_VCO);
            break;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    }
 #endif /* __CTM_SUPPORT__ */
    // Disable additional call setting if no SIM inserted or network not available
    if (srv_sim_ctrl_get_num_of_inserted() == 0
        || MMI_SIM_NONE == srv_sim_ctrl_get_one_available_sim()
        || MMI_FALSE == srv_mode_switch_is_network_service_available())
    {
        m_additionalSetting->setIsDisabled(VFX_TRUE);
    }
    else
    {
        m_additionalSetting->setIsDisabled(VFX_FALSE);
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("c17", SA_stop);
#endif
}

void VappCallSetPageMain::onItemTap(VcpFormItemCell *item, VfxId id)
{
    switch (id)
    {
    #ifdef __MMI_CM_BLACK_LIST__
        case ID_LAUNCH_CALLSET_BL:
            VappCallSetPageBL *pageBL;
            VFX_OBJ_CREATE(pageBL, VappCallSetPageBL, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageBL);
            break;
    #endif /* __MMI_CM_BLACK_LIST__ */

    #ifdef __MMI_CM_WHITE_LIST__
        case ID_LAUNCH_CALLSET_WL:
            VappCallSetPageWL *pageWL;
            VFX_OBJ_CREATE(pageWL, VappCallSetPageWL, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageWL);
            break;
    #endif /* __MMI_CM_WHITE_LIST__ */

        case ID_LAUNCH_CALLSET_REDIAL:
            VappCallSetPageRedial *pageRedial;
            VFX_OBJ_CREATE(pageRedial, VappCallSetPageRedial, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageRedial);
            break;

    #ifdef __IP_NUMBER__
        case ID_LAUNCH_CALLSET_IP_NUM:
            VappCallSetPageIpNum *pageIpNum;
            VFX_OBJ_CREATE(pageIpNum, VappCallSetPageIpNum, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageIpNum);
            break;
    #endif /* __IP_NUMBER__ */

        case ID_LAUNCH_CALLSET_CTR:
            VappCallSetPageCtr *pageCtr;
            VFX_OBJ_CREATE(pageCtr, VappCallSetPageCtr, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageCtr);
            break;

    #ifdef __MMI_CH_QUICK_END__
        case ID_LAUNCH_CALLSET_QUICK_END_TIME:
            VappCallSetPageQuickEnd *pageQuickEnd;
            VFX_OBJ_CREATE(pageQuickEnd, VappCallSetPageQuickEnd, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageQuickEnd);
            break;
    #endif /* __MMI_CH_QUICK_END__ */

    #ifdef __MMI_UCM_REJECT_BY_SMS__
        case ID_LAUNCH_CALLSET_REJECT_BY_SMS:
            VappCallSetPageRejBySms *pageRejBySms;
            VFX_OBJ_CREATE(pageRejBySms, VappCallSetPageRejBySms, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageRejBySms);
            break;
    #endif /* __MMI_UCM_REJECT_BY_SMS__ */

    #ifdef __CTM_SUPPORT__
        case ID_LAUNCH_CALLSET_CTM_MODE:
            VappCallSetPageCtm *pageCtm;
            VFX_OBJ_CREATE(pageCtm, VappCallSetPageCtm, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageCtm);
            break;
    #endif /* __CTM_SUPPORT__ */

    #ifdef __MMI_VIDEO_TELEPHONY__
        case ID_LAUNCH_CALLSET_VT:
            VappCallSetPageVt *pageVt;
            VFX_OBJ_CREATE(pageVt, VappCallSetPageVt, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageVt);
            break;
    #endif /* __MMI_VIDEO_TELEPHONY__ */

        case ID_LAUNCH_CALLSET_ADITIONAL_SETTINGS:
	    #if (MMI_MAX_SIM_NUM >= 2)
			if (srv_sim_ctrl_get_num_of_inserted() >= 2)
			{
				VappCallSetPageSimSel *pageSimSel;
				VFX_OBJ_CREATE(pageSimSel, VappCallSetPageSimSel, getMainScr());
				getMainScr()->pushPage(VFX_ID_NULL, pageSimSel);
			}
			else
	    #endif // MMI_MAX_SIM_NUM
			{
				// If no SIM inserted, the Additional setting cell willbe disable, so m_sim won't be 0
				callset_p->m_sim = (mmi_sim_enum)srv_sim_ctrl_get_one_available_sim();
				VappCallSetPageAdditional *pageAdditional;
				VFX_OBJ_CREATE(pageAdditional, VappCallSetPageAdditional, getMainScr());
				getMainScr()->pushPage(VFX_ID_NULL, pageAdditional);
			}

            break;
			
		default:
			break;
    }
}

void VappCallSetPageMain::onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
	item->setSwitchStatus(state);
}

void VappCallSetPageMain::onAniDone(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
    srv_callset_result_enum result;
	
    switch (id)
    {
    #ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
        case ID_LAUNCH_CALLSET_CTD:
            srv_callset_call_time_display_set_mode((MMI_BOOL)state);
            break;
    #endif /* __MMI_CALLSET_CTD_CONFIGURABLE__ */

        case ID_LAUNCH_CALLSET_ANSWER_MODE:
            result = srv_callset_answer_mode_switch_mode(SRV_CALLSET_ANSWER_MODE_AUTO, (MMI_BOOL)state);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this,
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                item->setSwitchStatus(!state);
            }
            break;

    #ifdef __MMI_CH_QUICK_END__
        case ID_LAUNCH_CALLSET_QUICK_END:
            if (!state || callset_p->m_inQuickEndTime)
            {
                result = srv_callset_auto_quick_end_set_mode(
                    (MMI_BOOL)state, 
                    (U16)callset_p->m_inQuickEndTime);
                if (result != SRV_CALLSET_RESULT_OK)
                {
                    VAPP_CALLSET_FAIL_POPUP(this,
                        VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                    item->setSwitchStatus(!state);
                }
                else
                {
                    callset_p->m_inQuickEnd = state;
                    updateForm(); /* update hint */
                }
            }
            else
            {
                callset_p->m_inQuickEnd = VFX_TRUE;

                VappCallSetPageQuickEnd *pageQuickEnd;
                VFX_OBJ_CREATE(pageQuickEnd, VappCallSetPageQuickEnd, getMainScr());
                getMainScr()->pushPage(VFX_ID_NULL, pageQuickEnd);
            }
            break;
    #endif /* __MMI_CH_QUICK_END__ */

    #ifdef __MMI_CONNECT_NOTICE__
        case ID_LAUNCH_CALLSET_CONNECT_NOTICE:
            srv_callset_connect_notice_set_mode((MMI_BOOL)state);
            break;
    #endif /* __MMI_CONNECT_NOTICE__ */

    #ifdef __CTM_SUPPORT__
        case ID_LAUNCH_CALLSET_CTM:
            if (srv_callset_ctm_get_mode() != (MMI_BOOL)state)
            {
                srv_callset_ctm_setting_struct ctm;
                ctm.mode = (MMI_BOOL)state;
                ctm.setting = srv_callset_ctm_get_setting();
                result = srv_callset_ctm_set_mode(&ctm);
                if (result != SRV_CALLSET_RESULT_OK)
                {
                    VAPP_CALLSET_FAIL_POPUP(this,
                        VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                    item->setSwitchStatus(!state);
                }
            }

            break;
    #endif /* __CTM_SUPPORT__ */

    #ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
        case ID_LAUNCH_CALLSET_REJECT_UNKNOWN_CALLER:
            result = srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_UNKNOWN_CALLER, (MMI_BOOL)state, NULL);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this,
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                item->setSwitchStatus(!state);
            }

            break;
    #endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
    }
}

void VappCallSetPageMain::updateAccordingMode()
{
    if (MMI_FALSE == srv_mode_switch_is_network_service_available())
    {
        m_additionalSetting->setIsDisabled(VFX_TRUE);
        VfxId mainPageId = getId();
        VfxMainScr *mainScr = getMainScr();
        VfxId upperId = mainScr->getNextPageId(mainPageId);
        while(VFX_ID_NULL != upperId)
        {
            mainScr->closePage(upperId);
            upperId = mainScr->getNextPageId(mainPageId);
        }
    }
    else
    {
        m_additionalSetting->setIsDisabled(VFX_FALSE);
    }
}

mmi_ret VappCallSetPageMain::hdlrModeChange(mmi_event_struct *evt)
{
    VappCallSetPageMain *thiz = (VappCallSetPageMain *)handleToObject((VfxObjHandle)evt->user_data);
    thiz->updateAccordingMode();
    return MMI_RET_OK;
}

VappCallSetPageCommonInputAsync::VappCallSetPageCommonInputAsync(VfxBool isAsync)
	: m_titleBar(NULL),
	  m_mainText(NULL),
	  m_hint(NULL),
	  m_textInput(NULL),
	  m_funcBar(NULL),
	  m_toolBar(NULL),
	  m_isAsync(isAsync)
{
}

void VappCallSetPageCommonInputAsync::onInit()
{
    VappCallSetAsyncPage::onInit(); // call base class

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    setTopBar(m_titleBar);

    //setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    VFX_OBJ_CREATE(m_mainText, VfxTextFrame, this);
    m_mainText->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_mainText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_mainText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));

    VFX_OBJ_CREATE(m_textInput, VcpTextEditor , this);
    m_textInput->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_textInput->m_signalTextChanged.connect(this, &VappCallSetPageCommonInputAsync::onTextChanged); 

    VFX_OBJ_CREATE(m_hint, VfxTextFrame, this);
    m_hint->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_hint->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
	if (m_isAsync)
	{
    m_hint->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
	}

    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, m_textInput);
    m_funcBar->addItem((VfxResId)STR_GLOBAL_OK, (VfxId)VAPP_CALLSET_FUNC_OK);
    m_funcBar->setItemSpecial(VAPP_CALLSET_FUNC_OK);
    m_funcBar->m_signalButtonTap.connect(this, &VappCallSetPageCommonInputAsync::onFuncBtnClicked);
    m_textInput->setFunctionBar(m_funcBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(VAPP_CALLSET_FUNC_OK, STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem(VAPP_CALLSET_FUNC_CANCEL, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageCommonInputAsync::onFuncBtnClicked);
    setBottomBar(m_toolBar);


#ifdef __MMI_MAINLCD_320X480__
    m_mainText->setPos(VfxPoint(10, 25));
    m_mainText->setSize(300, 40);
    m_textInput->setPos(VfxPoint(10, 60));
    m_textInput->setSize(300, 40);
    m_hint->setPos(VfxPoint(10, 105));
    m_hint->setSize(300, 40);

#elif defined(__MMI_MAINLCD_480X800__)
    m_mainText->setPos(VfxPoint(15, 30));
    m_mainText->setSize(450, 70);
    m_mainText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(32), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_textInput->setPos(VfxPoint(15, 90));
    m_textInput->setSize(450, 70);
    m_hint->setPos(VfxPoint(15, 170));
	if (m_isAsync)
	{
    	m_hint->setSize(450, 140);
	}
	else
	{
		m_hint->setSize(450, 70);
	}
    m_hint->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(32), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    m_mainText->setPos(VfxPoint(7, 15));
    m_mainText->setSize(226, 27);
    m_mainText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(14), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_textInput->setPos(VfxPoint(7, 40));
    m_textInput->setSize(226, 27);
    m_hint->setPos(VfxPoint(7, 70));
	if (m_isAsync)
	{
    	m_hint->setSize(226, 54);
	}
	else
	{
		m_hint->setSize(226, 27);
	}
    m_hint->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(14), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));

#endif /* __MMI_MAINLCD_320X480__ */
}

void VappCallSetPageCommonInputAsync::setInputBuf(const VfxU32 &maxInputLen, const VfxWString &defaultInput)
{
    m_textInput->setText(defaultInput, maxInputLen);
}

void VappCallSetPageCommonInputAsync::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VAPP_CALLSET_FUNC_CANCEL:
            getMainScr()->popPage();
            break;
    }
}

void VappCallSetPageCommonInputAsync::onTextChanged(VcpTextEditor* editor)
{
    if (mmi_ucs2strlen((CHAR *)m_textInput->getText()))
    {
        m_funcBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
        m_toolBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
    }
    else
    {
        m_funcBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
        m_toolBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_TRUE);
    }
}


#ifdef __MMI_CM_BLACK_LIST__

void VappCallSetPageBL::onInit()
{
    VfxPage::onInit(); // call base class

    m_phbId = NULL;

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(STR_ID_VAPP_CALLSET_BLACKLIST);
    setTopBar(titlebar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setBounds(0, 0, getSize().width, getSize().height);
    m_form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemSwitchCell *swh;
    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, m_form);
    swh->setMainText(STR_ID_VAPP_CALLSET_BLACKLIST_FROM_LIST);
    swh->setSwitchStatus(
            (srv_callset_blacklist_get_mode(NULL) & SRV_CALLSET_BLACKLIST_FROM_LIST) ? 
            VFX_TRUE : VFX_FALSE);
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageBL::onSwitch);
    m_form->addItem(swh, 1);

    m_form->addCaption(STR_ID_VAPP_CALLSET_LIST_NUM);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(1, STR_ID_VAPP_CALLSET_LIST_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageBL::onToolBarTapped);
    setBottomBar(m_toolBar);

    m_minBlNumId = 2;
    m_count = 0;
    updateList();
}

void VappCallSetPageBL::updateList(void)
{
    VfxU32 i;
    VcpFormItemAidButtonCell *aid;
    VcpFormItemLauncherCell *launch;
    launch = VFX_OBJ_DYNAMIC_CAST(m_form->getItem(m_minBlNumId), VcpFormItemLauncherCell);
    if (m_count)
    {
        for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
        {
            aid = VFX_OBJ_DYNAMIC_CAST(m_form->getItem(i + m_minBlNumId), VcpFormItemAidButtonCell);
            if (aid)
            {
                m_form->removeItem(i + m_minBlNumId);
            }
            else
            {
                break;
            }        
        }
    }
    else if (launch)
    {
        m_form->removeItem(m_minBlNumId);
    }


    m_count = 0;
    for (i = 0; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
    {
        srv_callset_bl_item_struct item;
        item.index = i;
        item.adv_param = NULL;
        if ((srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK)
                && (mmi_ucs2strlen((CHAR *)item.number)))
        {
            VFX_OBJ_CREATE(aid, VcpFormItemAidButtonCell, m_form);
            aid->setMainText(item.number);
            aid->getAidButton()->setBgImageList(VcpStateImage(0));
            aid->getAidButton()->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
            aid->getAidButton()->setImage(VcpStateImage(IMG_ID_CALLSET_DEL));
            aid->getAidButton()->setIsAutoResized(VFX_TRUE);
            aid->getAidButton()->setMargin(0, 0, 0, 0);
            aid->m_signalAidButtonPress.connect(this, &VappCallSetPageBL::onDel);
            m_form->addItem(aid, m_count + m_minBlNumId);
            m_count++;
        }
    }
    if (!m_count)
    {
        VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
        launch->setMainText(STR_GLOBAL_EMPTY_LIST);
		launch->m_mainText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
        launch->setIsTappable(VFX_FALSE);
        m_form->addItem(launch, m_minBlNumId);
    }

    if (m_count < SRV_CALLSET_BLACKLIST_MAX_ITEM)
    {
        m_toolBar->setDisableItem(1, VFX_FALSE);
    }
    else
    {
        m_toolBar->setDisableItem(1, VFX_TRUE);
    }
}

void VappCallSetPageBL::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (isBackward)
    {
        updateList();
    }
}

mmi_ret VappCallSetPageBL::onProc(mmi_event_struct *evt)
{
    vcui_phb_list_result_event_struct *res = (vcui_phb_list_result_event_struct*)evt;

	if (evt->evt_id != EVT_ID_CUI_PHB_LIST_RESULT)
	{
		return VfxPage::onProc(evt);
	}
	
    if (!res->result ||(res->select_count != 1))
    {
        /* ignore */
        vcui_phb_list_close(m_phbId); 
        m_phbId = GRP_ID_INVALID;
        return VfxPage::onProc(evt);
    }

    WCHAR num[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    vcui_phb_list_get_selected_contact_data(m_phbId, num, MMI_PHB_NUMBER_PLUS_LENGTH);

    srv_callset_result_enum result;
    result = srv_callset_blacklist_add_number(
        (U8)mmi_ucs2strlen((CHAR *)num), num, NULL, NULL);
    if (result != SRV_CALLSET_RESULT_OK)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                             MMI_EVENT_INFO_BALLOON,
                             MMI_NMGR_BALLOON_TYPE_FAILURE,
                             (WCHAR*)GetString(srv_callset_get_result_string_id(result)));
    }
    else
    {
        vcui_phb_list_close(m_phbId);
        m_phbId = GRP_ID_INVALID; 
    }

    return MMI_RET_OK;

}

void VappCallSetPageBL::onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
    srv_callset_result_enum result;
    switch (id)
    {
        case 1:
            result = srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_FROM_LIST, (MMI_BOOL)state, NULL);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                item->setSwitchStatus(!state);
            }
            else
            {
                item->setSwitchStatus(state);
            }
            break;
    }
}

void VappCallSetPageBL::onDel(VcpFormItemAidButtonCell* item, VfxId id)
{
    if (id >= (m_minBlNumId + SRV_CALLSET_BLACKLIST_MAX_ITEM))
    {
        return;
    }

    m_tmpNum = item->getMainText();

    VcpConfirmPopup *cnf;
    VFX_OBJ_CREATE(cnf, VcpConfirmPopup, this);
    cnf->setInfoType(VCP_POPUP_TYPE_WARNING);
    cnf->setText(STR_ID_VAPP_CALLSET_BLACKLIST_DEL_CNF);
    cnf->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    cnf->setCustomButton(STR_GLOBAL_REMOVE, STR_GLOBAL_CANCEL,
                            VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    cnf->m_signalButtonClicked.connect(this, &VappCallSetPageBL::onConfirmClicked);
    cnf->setAutoDestory(VFX_TRUE);
    cnf->show(VFX_TRUE);
}

void VappCallSetPageBL::onToolBarTapped(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 1:
            VcpCommandPopup *cmd;
            VFX_OBJ_CREATE(cmd, VcpCommandPopup, this);
            cmd->setInfoType(VCP_POPUP_TYPE_INFO);
            cmd->setText(STR_ID_VAPP_CALLSET_LIST_ADD);
            cmd->addItem(1, STR_ID_VAPP_CALLSET_INPUT_NUMBER);
            cmd->addItem(2, STR_ID_VAPP_CALLSET_SEL_PHB);
            cmd->addItem(3, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);//Li Chen
            cmd->m_signalButtonClicked.connect(this, &VappCallSetPageBL::onCmdBtnClicked);
            cmd->setAutoDestory(VFX_TRUE);
            cmd->show(VFX_TRUE);
            break;
    }
}

void VappCallSetPageBL::onCmdBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 1:
            VappCallSetPageBLEdit *pageBLEdit;
            VFX_OBJ_CREATE(pageBLEdit, VappCallSetPageBLEdit, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageBLEdit);
            break;

        case 2:
            m_phbId = vcui_phb_list_create(getApp()->getGroupId());
            if (m_phbId != GRP_ID_INVALID)
            {
            	// for OP01
            	vfxSetCuiCallerScr(m_phbId, getMainScr());
                vcui_phb_list_set_req_type(m_phbId, VAPP_PHB_LIST_SINGLE_SELECTOR);
                vcui_phb_list_set_req_field(m_phbId, MMI_PHB_CONTACT_FIELD_NUMBER);
                vcui_phb_list_run(m_phbId);
            }
            break;
    }
}

void VappCallSetPageBL::onConfirmClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
            VfxU32 index = 0;
            srv_callset_result_enum result;
            result = srv_callset_blacklist_delete_number(
                        m_tmpNum.getLength(), 
                        (WCHAR*)m_tmpNum.getBuf(), NULL, (PU8)&index);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
            }
            else
            {
                /* move and fill the empty item */
                srv_callset_bl_item_struct item;
                item.adv_param = NULL;
				
                for (VfxU32 i = index + 1; i < SRV_CALLSET_BLACKLIST_MAX_ITEM; i++)
                {
                    item.index = i;
                    if ((srv_callset_blacklist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                        mmi_ucs2strlen((CHAR *)item.number))
                    {
                        srv_callset_bl_item_struct item2;
                        memset(&item2, 0, sizeof(srv_callset_bl_item_struct));
                        item2.index = item.index;
                        srv_callset_blacklist_set_number(&item2);
                        item.index = i - 1;
                        srv_callset_blacklist_set_number(&item);
                    }
                }
            }
            updateList();
            break;
    }
}



void VappCallSetPageBLEdit::onInit()
{
    VappCallSetPageCommonInputAsync::onInit(); // call base class

    m_titleBar->setTitle(STR_ID_VAPP_CALLSET_INPUT_NUMBER);
    m_mainText->setString(STR_ID_VAPP_CALLSET_BLACKLIST_INPUT_NUMBER);
    
    m_textInput->setIME(IMM_INPUT_TYPE_PHONE_NUMBER, IME_PLUS_CHAR_HANDLING);
    setInputBuf(SRV_UCM_MAX_NUM_URI_LEN - 1, VFX_WSTR_EMPTY);
    
    m_funcBar->m_signalButtonTap.connect(this, &VappCallSetPageBLEdit::onFuncBtnClicked);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageBLEdit::onFuncBtnClicked);

}

void VappCallSetPageBLEdit::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VAPP_CALLSET_FUNC_OK:
        {
            srv_callset_result_enum result;
            result = srv_callset_blacklist_add_number(
                (U8)mmi_ucs2strlen((CHAR *)m_textInput->getText())
                , (WCHAR*)m_textInput->getText(), NULL, NULL);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
            }
            else
            {
                getMainScr()->popPage();
            }
            break;
        }

        default:
            return VappCallSetPageCommonInputAsync::onFuncBtnClicked(sender, id);
    }
}
#endif /* __MMI_CM_BLACK_LIST__ */


#ifdef __MMI_CM_WHITE_LIST__

void VappCallSetPageWL::onInit()
{
    VfxPage::onInit(); // call base class

    m_phbId = NULL;
    m_passwdId = NULL;
    m_func = NULL;

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(STR_ID_VAPP_CALLSET_WHITELIST);
    setTopBar(titlebar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setBounds(0, 0, getSize().width, getSize().height);
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemSwitchCell *swh;
    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, m_form);
    swh->setMainText(STR_ID_VAPP_CALLSET_WHITELIST_FROM_LIST);
    swh->setSwitchStatus(
            (srv_callset_whitelist_get_mode(NULL) & SRV_CALLSET_WHITELIST_FROM_LIST) ? 
            VFX_TRUE : VFX_FALSE);
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageWL::onSwitch);
    m_form->addItem(swh, 1);

    m_form->addCaption(STR_ID_VAPP_CALLSET_LIST_NUM);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(1, STR_ID_VAPP_CALLSET_LIST_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageWL::onToolBarTapped);
    setBottomBar(m_toolBar);

    m_minWlNumId = 2;
    m_count = 0;
    updateList();
}

void VappCallSetPageWL::updateList(void)
{
    VfxU32 i;
    VcpFormItemAidButtonCell *aid;
    VcpFormItemLauncherCell *launch;
    launch = VFX_OBJ_DYNAMIC_CAST(m_form->getItem(m_minWlNumId), VcpFormItemLauncherCell);
    if (m_count)
    {
        for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
        {
            aid = VFX_OBJ_DYNAMIC_CAST(m_form->getItem(i + m_minWlNumId), VcpFormItemAidButtonCell);
            if (aid)
            {
                m_form->removeItem(i + m_minWlNumId);
            }
            else
            {
                break;
            }        
        }
    }
    else if (launch)
    {
        m_form->removeItem(m_minWlNumId);
    }


    m_count = 0;
    for (i = 0; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
    {
        srv_callset_wl_item_struct item;
        item.index = i;
        item.adv_param = NULL;
        if ((srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK)
                && (mmi_ucs2strlen((CHAR *)item.number)))
        {
            VFX_OBJ_CREATE(aid, VcpFormItemAidButtonCell, m_form);
            aid->setMainText(item.number);
            aid->getAidButton()->setBgImageList(VcpStateImage(0));
            aid->getAidButton()->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
            aid->getAidButton()->setImage(VcpStateImage(IMG_ID_CALLSET_DEL));
            aid->getAidButton()->setIsAutoResized(VFX_TRUE);
            aid->getAidButton()->setMargin(0, 0, 0, 0);
            aid->m_signalAidButtonPress.connect(this, &VappCallSetPageWL::onDel);
            m_form->addItem(aid, m_count + m_minWlNumId);
            m_count++;
        }
    }
    if (!m_count)
    {
        VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
        launch->setMainText(STR_GLOBAL_EMPTY_LIST);
		launch->m_mainText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
        launch->setIsTappable(VFX_FALSE);
        m_form->addItem(launch, m_minWlNumId);
    }

    if (m_count < SRV_CALLSET_WHITELIST_MAX_ITEM)
    {
        m_toolBar->setDisableItem(1, VFX_FALSE);
    }
    else
    {
        m_toolBar->setDisableItem(1, VFX_TRUE);
    }
}

void VappCallSetPageWL::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (isBackward)
    {
        updateList();
    }
}

mmi_ret VappCallSetPageWL::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PHB_LIST_RESULT:
        {
            vcui_phb_list_result_event_struct *res = (vcui_phb_list_result_event_struct*)evt;
            if (!res->result || (res->select_count != 1))
            {
                /* ignore */
                vcui_phb_list_close(m_phbId); 
                m_phbId = GRP_ID_INVALID;
                return VfxPage::onProc(evt);
            }

            vcui_phb_list_get_selected_contact_data(m_phbId, m_num, MMI_PHB_NUMBER_PLUS_LENGTH);
            vcui_phb_list_close(m_phbId);
            m_phbId = GRP_ID_INVALID;

            m_func = &VappCallSetPageWL::onAddFromPhb;
            m_passwdId = vcui_verify_create(getApp()->getGroupId(), VCUI_VERIFY_TYPE_PHONE_PASSWORD);
            if (m_passwdId != GRP_ID_INVALID)
            {
                vcui_verify_run(m_passwdId);
            }
            break;
        }

        case EVT_ID_VCUI_VERIFY_RESULT:
        {
            vcui_verify_result_evt_struct *ver = (vcui_verify_result_evt_struct*)evt;
            if (ver->success)
            {
                (*this.*m_func)();
            }

            vcui_verify_close(m_passwdId);
            m_passwdId = NULL;

            break;
        }

        case EVT_ID_VCUI_VERIFY_CANCEL:
        {
            vcui_verify_close(m_passwdId);
            m_passwdId = NULL;
            break;
        }

        default:
            return VfxPage::onProc(evt);
    }

    return MMI_RET_OK;

}


void VappCallSetPageWL::onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
    srv_callset_result_enum result;
    switch (id)
    {
        case 1:
            result = srv_callset_whitelist_switch_mode(SRV_CALLSET_WHITELIST_FROM_LIST, (MMI_BOOL)state, NULL);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                item->setSwitchStatus(!state);
            }
            else
            {
                item->setSwitchStatus(state);
            }
            break;
    }
}

void VappCallSetPageWL::onDel(VcpFormItemAidButtonCell* item, VfxId id)
{
    if (id >= (m_minWlNumId + SRV_CALLSET_WHITELIST_MAX_ITEM))
    {
        return;
    }

    m_tmpNum = item->getMainText();

    m_func = &VappCallSetPageWL::onDelContinue;
    m_passwdId = vcui_verify_create(getApp()->getGroupId(), VCUI_VERIFY_TYPE_PHONE_PASSWORD);
    if (m_passwdId != GRP_ID_INVALID)
    {
        vcui_verify_run(m_passwdId);
    }

}

void VappCallSetPageWL::onDelContinue()
{
    VfxU32 index = 0;
    srv_callset_result_enum result;
    result = srv_callset_whitelist_delete_number(
                m_tmpNum.getLength(), 
                (WCHAR*)m_tmpNum.getBuf(), NULL, (PU8)&index);
    if (result != SRV_CALLSET_RESULT_OK)
    {
        VAPP_CALLSET_FAIL_POPUP(this, 
            VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
    }
    else
    {
        /* move and fill the empty item */
        srv_callset_wl_item_struct item;
        item.adv_param = NULL;
        for (int i = index + 1; i < SRV_CALLSET_WHITELIST_MAX_ITEM; i++)
        {
            item.index = i;
            if ((srv_callset_whitelist_get_item(&item) == SRV_CALLSET_RESULT_OK) &&
                mmi_ucs2strlen((CHAR *)item.number))
            {
                srv_callset_wl_item_struct item2;
                memset(&item2, 0, sizeof(srv_callset_wl_item_struct));
                item2.index = item.index;
                srv_callset_whitelist_set_number(&item2);
                item.index = i - 1;
                srv_callset_whitelist_set_number(&item);
            }
        }
    }
    updateList();

}

void VappCallSetPageWL::onToolBarTapped(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 1:
            VcpCommandPopup *cmd;
            VFX_OBJ_CREATE(cmd, VcpCommandPopup, this);
            cmd->setInfoType(VCP_POPUP_TYPE_INFO);
            cmd->setText(STR_ID_VAPP_CALLSET_LIST_ADD);
            cmd->addItem(1, STR_ID_VAPP_CALLSET_INPUT_NUMBER);
            cmd->addItem(2, STR_ID_VAPP_CALLSET_SEL_PHB);
            cmd->addItem(3, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);//Li Chen
            cmd->m_signalButtonClicked.connect(this, &VappCallSetPageWL::onCmdBtnClicked);
            cmd->setAutoDestory(VFX_TRUE);
            cmd->show(VFX_TRUE);
            break;
    }
}

void VappCallSetPageWL::onCmdBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 1:
            VappCallSetPageWLEdit *pageWLEdit;
            VFX_OBJ_CREATE(pageWLEdit, VappCallSetPageWLEdit, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageWLEdit);
            break;

        case 2:
            m_phbId = vcui_phb_list_create(getApp()->getGroupId());
            if (m_phbId != GRP_ID_INVALID)
            {
                vcui_phb_list_set_req_type(m_phbId, VAPP_PHB_LIST_SINGLE_SELECTOR);
                vcui_phb_list_set_req_field(m_phbId, MMI_PHB_CONTACT_FIELD_NUMBER);
                vcui_phb_list_run(m_phbId);
            }
            break;
    }
}

void VappCallSetPageWL::onAddFromPhb()
{   
    srv_callset_result_enum result;
    result = srv_callset_whitelist_add_number(
        (U8)mmi_ucs2strlen((CHAR *)m_num), m_num, NULL, NULL);
    if (result != SRV_CALLSET_RESULT_OK)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                             MMI_EVENT_INFO_BALLOON,
                             MMI_NMGR_BALLOON_TYPE_FAILURE,
                             (WCHAR*)GetString(srv_callset_get_result_string_id(result)));
    }
}



void VappCallSetPageWLEdit::onInit()
{
    VappCallSetPageCommonInputAsync::onInit(); // call base class

    m_passwdId = NULL;
    m_func = NULL;

    m_titleBar->setTitle(STR_ID_VAPP_CALLSET_INPUT_NUMBER);
    m_mainText->setString(STR_ID_VAPP_CALLSET_WHITELIST_INPUT_NUMBER);
    
    m_textInput->setIME(IMM_INPUT_TYPE_PHONE_NUMBER, IME_PLUS_CHAR_HANDLING);
    setInputBuf(SRV_UCM_MAX_NUM_URI_LEN - 1, VFX_WSTR_EMPTY);

    m_funcBar->m_signalButtonTap.connect(this, &VappCallSetPageWLEdit::onFuncBtnClicked);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageWLEdit::onFuncBtnClicked);
    
}

mmi_ret VappCallSetPageWLEdit::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_VERIFY_RESULT:
        {
            vcui_verify_result_evt_struct *ver = (vcui_verify_result_evt_struct*)evt;
            if (ver->success)
            {
                (*this.*m_func)();
                /* may close this page in m_func */
            }

            vcui_verify_close(m_passwdId);

            /* m_passwdId = NULL; */ /* not allow to access any member due to update procedure is called during vcui close, thus this page may have been closed */
            break;
        }

        case EVT_ID_VCUI_VERIFY_CANCEL:
        {
            vcui_verify_close(m_passwdId);
            m_passwdId = NULL;
            break;
        }

        default:
            return VappCallSetPageCommonInputAsync::onProc(evt);
    }

    return MMI_RET_OK;
}

void VappCallSetPageWLEdit::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VAPP_CALLSET_FUNC_OK:
        {
            m_func = &VappCallSetPageWLEdit::onAdd;
            m_passwdId = vcui_verify_create(getApp()->getGroupId(), VCUI_VERIFY_TYPE_PHONE_PASSWORD);
            if (m_passwdId != GRP_ID_INVALID)
            {
                vcui_verify_run(m_passwdId);
            }
            break;
        }

        default:
            return VappCallSetPageCommonInputAsync::onFuncBtnClicked(sender, id);
    }
}

void VappCallSetPageWLEdit::onAdd()
{
    srv_callset_result_enum result;
    result = srv_callset_whitelist_add_number(
        (U8)mmi_ucs2strlen((CHAR *)m_textInput->getText())
        , (WCHAR*)m_textInput->getText(), NULL, NULL);
    if (result != SRV_CALLSET_RESULT_OK)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                             MMI_EVENT_INFO_BALLOON,
                             MMI_NMGR_BALLOON_TYPE_FAILURE,
                             (WCHAR*)GetString(srv_callset_get_result_string_id(result)));
    }
    else
    {
        getMainScr()->popPage();
    }
}
#endif /* __MMI_CM_WHITE_LIST__ */



void VappCallSetPageRedial::onInit()
{
    VfxPage::onInit(); // call base class

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(STR_ID_VAPP_CALLSET_AUTOREDIAL);
    setTopBar(titlebar);
#ifdef __MMI_UCM_MO_FAIL_POST_ACTION__
    m_count = 3;
#else
    m_count = 2;
#endif /* __MMI_UCM_MO_FAIL_POST_ACTION__ */

    switch (srv_callset_redial_get_mode())
    {
        case SRV_CALLSET_REDIAL_AUTO:
            m_activateIndex = 0;
            break;
    #ifdef __MMI_UCM_MO_FAIL_POST_ACTION__
        case SRV_CALLSET_REDIAL_CONFIRM:
            m_activateIndex = 2;
            break;
    #endif /* __MMI_UCM_MO_FAIL_POST_ACTION__ */
        default:
            m_activateIndex = 1;
            break;
    }

    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);
    menu->setSize(getSize());
    menu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setContentProvider(this);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    menu->m_signalItemSelectionStateChanged.connect(this, &VappCallSetPageRedial::onSelect);
    menu->m_signalItemTapped.connect(this, &VappCallSetPageRedial::onTapped);
}

VfxBool VappCallSetPageRedial::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

    switch (index)
    {
        case 0:
            text.loadFromRes(STR_ID_VAPP_CALLSET_AUTOREDIAL_ALWAYS);
            break;

        case 1:
            text.loadFromRes(STR_ID_VAPP_CALLSET_AUTOREDIAL_NEVER);
            break;
    #ifdef __MMI_UCM_MO_FAIL_POST_ACTION__
        case 2:
            text.loadFromRes(STR_ID_VAPP_CALLSET_AUTOREDIAL_CONF);
            break;
    #endif /* __MMI_UCM_MO_FAIL_POST_ACTION__ */
        default:
            return VFX_FALSE;
    }

    return VFX_TRUE;
}

VfxU32 VappCallSetPageRedial::getCount() const {return m_count;}

VcpListMenuItemStateEnum VappCallSetPageRedial::getItemState(
    VfxU32 index   
    ) const 
{
    return (index == m_activateIndex) ?
                VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

void VappCallSetPageRedial::onSelect(
    VcpListMenu* menu, 
    VfxU32 index, 
    VcpListMenuItemStateEnum state
    )
{
    if (state != VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        return;
    }

    switch (index)
    {
        case 0:
            srv_callset_redial_set_mode(SRV_CALLSET_REDIAL_AUTO);
            break;

        case 1:
            srv_callset_redial_set_mode(SRV_CALLSET_REDIAL_OFF);
            break;
    #ifdef __MMI_UCM_MO_FAIL_POST_ACTION__
        case 2:
            srv_callset_redial_set_mode(SRV_CALLSET_REDIAL_CONFIRM);
            break;
    #endif /* __MMI_UCM_MO_FAIL_POST_ACTION__ */
    }

    m_activateIndex = index;
}

void VappCallSetPageRedial::onTapped(
    VcpListMenu* menu,
    VfxU32 index)
{
    getMainScr()->popPage();
}


#ifdef __IP_NUMBER__

void VappCallSetPageIpNumEdit::onInit()
{
    VappCallSetPageCommonInputAsync::onInit(); // call base class

    m_titleBar->setTitle(STR_ID_VAPP_CALLSET_INPUT_NUMBER);
    m_mainText->setString(STR_ID_VAPP_CALLSET_IP_EDIT);

	VsrvInputBinding inputBinding(
		IMM_INPUT_TYPE_PHONE_NUMBER, 
		0, 
		IME_INPUT_STYLE_NONE, 
		m_textInput->m_editing
		);
	inputBinding.setDisabledChars(VFX_WSTR("*-#pw"));
	m_textInput->setIME(inputBinding);
    setInputBuf(SRV_CALLSET_MAX_IP_NUMBER_LEN - 1, VFX_WSTR_EMPTY);
    
    m_funcBar->m_signalButtonTap.connect(this, &VappCallSetPageIpNumEdit::onFuncBtnClicked);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageIpNumEdit::onFuncBtnClicked);
}

void VappCallSetPageIpNumEdit::setNumIndex(VfxU8 idx)
{
    MMI_ASSERT(idx < SRV_CALLSET_MAX_IP_NUMBER);
    m_index = idx;
    srv_callset_ip_number_item_struct item;
    if ((srv_callset_ip_number_get_item(m_index, &item) == SRV_CALLSET_RESULT_OK) &&
            mmi_ucs2strlen((CHAR *)item.number))
    {
        setInputBuf(SRV_CALLSET_MAX_IP_NUMBER_LEN - 1, VFX_WSTR_MEM(item.number));
    }
}

void VappCallSetPageIpNumEdit::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VAPP_CALLSET_FUNC_OK:
        {
            srv_callset_result_enum result;
            result = srv_callset_ip_number_set_number(
                m_index
                , (U8)mmi_ucs2strlen((CHAR *)m_textInput->getText())
                , (WCHAR*)m_textInput->getText());
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
            }
            else
            {
                getMainScr()->popPage();
            }
            break;
        }

        default:
            return VappCallSetPageCommonInputAsync::onFuncBtnClicked(sender, id);
    }
}
void VappCallSetPageIpNumEdit::onTextChanged(VcpTextEditor* editor)
{
    m_funcBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
    m_toolBar->setDisableItem(VAPP_CALLSET_FUNC_OK, VFX_FALSE);
}

void VappCallSetPageIpNum::onInit()
{
    VfxPage::onInit(); // call base class
    mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, &VappCallSetPageIpNum::hdlrSimAvailabilityChange, getObjHandle());

    m_selIndex = -1;
    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(STR_ID_VAPP_CALLSET_IP_NUMBER);
    setTopBar(titlebar);
    
    VFX_OBJ_CREATE(m_listmenu, VcpListMenu, this);
    m_listmenu->setSize(getSize());
    m_listmenu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    m_listmenu->setContentProvider(this);
    m_listmenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);
    m_listmenu->m_signalCmdButtonClicked.connect(this, &VappCallSetPageIpNum::onClickCmdButton);
    m_listmenu->m_signalItemTapped.connect(this, &VappCallSetPageIpNum::onTapped);
}

void VappCallSetPageIpNum::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, &VappCallSetPageIpNum::hdlrSimAvailabilityChange, getObjHandle());

    VfxPage::onDeinit();
}

void VappCallSetPageIpNum::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
    updateIpNum();
    if (m_listmenu)
    {
        m_listmenu->updateAllItems();
    }
}

void VappCallSetPageIpNum::updateIpNum()
{
    if(srv_sim_ctrl_is_inserted(MMI_SIM1))
    {
        srv_callset_ip_number_get_activated_number(MMI_SIM1, &m_ip_num); 
        if ( mmi_ucs2strlen((CHAR *)m_ip_num.number))
        {
        callset_p->m_sim = (mmi_sim_enum)(callset_p->m_sim | MMI_SIM1);
        }
    }
    else
    {
        srv_callset_ip_number_deactivate(MMI_SIM1,0);
        srv_callset_ip_number_deactivate(MMI_SIM1,1);
        srv_callset_ip_number_deactivate(MMI_SIM1,2);
    }
#if (MMI_MAX_SIM_NUM >= 2)
    if(srv_sim_ctrl_is_inserted(MMI_SIM2))
    {
        srv_callset_ip_number_get_activated_number(MMI_SIM2, &m_ip_num);
        if ( mmi_ucs2strlen((CHAR *)m_ip_num.number))
        {
            callset_p->m_sim = (mmi_sim_enum)(callset_p->m_sim | MMI_SIM2);
        }
    }
    else
    {
        srv_callset_ip_number_deactivate(MMI_SIM2,0);
        srv_callset_ip_number_deactivate(MMI_SIM2,1);
        srv_callset_ip_number_deactivate(MMI_SIM2,2);
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}

VfxBool VappCallSetPageIpNum::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    if (index >= SRV_CALLSET_MAX_IP_NUMBER)
    {
        return VFX_FALSE;
    }

    srv_callset_ip_number_item_struct item;
    if ((srv_callset_ip_number_get_item(index, &item) == SRV_CALLSET_RESULT_OK) &&
            mmi_ucs2strlen((CHAR *)item.number))
    {
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        text.loadFromMem(item.number);
    }
    else
    {
        color = VCP_LIST_MENU_TEXT_COLOR_DISABLED;
        text.loadFromRes(STR_GLOBAL_EMPTY_LIST);
    }

    return VFX_TRUE;
}

VfxBool VappCallSetPageIpNum::getItemImage(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxImageSrc &image
    )
{
    if (index >= SRV_CALLSET_MAX_IP_NUMBER)
    {
        return VFX_FALSE;
    }

if (VCP_LIST_MENU_FIELD_ICON == fieldType)
{
    srv_callset_ip_number_item_struct item;
    if ((srv_callset_ip_number_get_item(index, &item) == SRV_CALLSET_RESULT_OK) &&
            item.status != SRV_CALLSET_IP_NUMBER_OFF)
    {
        //set different image icon for different activated sim card
        if (srv_sim_ctrl_is_inserted(MMI_SIM1) && srv_sim_ctrl_is_inserted(MMI_SIM2) && 
            (SRV_CALLSET_IP_NUMBER_SIM1_ACTIVATED |SRV_CALLSET_IP_NUMBER_SIM2_ACTIVATED) == item.status)
        {
            image.setResId(IMG_ID_CALLSET_VICON_SIM12); 
        }
        else if (srv_sim_ctrl_is_inserted(MMI_SIM1) && (SRV_CALLSET_IP_NUMBER_SIM1_ACTIVATED & item.status))
        {
            image.setResId(IMG_COSMOS_SIM1); 
        }
        else if (srv_sim_ctrl_is_inserted(MMI_SIM2) && (SRV_CALLSET_IP_NUMBER_SIM2_ACTIVATED & item.status))
        {
            image.setResId(IMG_COSMOS_SIM2); 
        }
    }

}
else if (VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL == fieldType ||
		 VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED == fieldType ||
		 VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED == fieldType ||
		 VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT == fieldType)
{
      image.setResId(IMG_COSMOS_EDIT);

}
return VFX_TRUE;

}


VfxU32 VappCallSetPageIpNum::getCount() const {return SRV_CALLSET_MAX_IP_NUMBER;}

VfxBool VappCallSetPageIpNum::getItemIsHighlightable(VfxU32 index) const
{
	srv_callset_ip_number_item_struct item;
    if ((srv_callset_ip_number_get_item(index, &item) == SRV_CALLSET_RESULT_OK) &&
            mmi_ucs2strlen((CHAR *)item.number))
    {
   	    return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappCallSetPageIpNum::onClickCmdButton(VcpListMenu *listmenu, VfxU32 index)
{
    // go to editor for user to editing ip number
    VappCallSetPageIpNumEdit *pageIpNumEdit;
    VFX_OBJ_CREATE(pageIpNumEdit, VappCallSetPageIpNumEdit, getMainScr());
    pageIpNumEdit->setNumIndex(index);
    getMainScr()->pushPage(VFX_ID_NULL, pageIpNumEdit);

}

void VappCallSetPageIpNum::onTapped(
    VcpListMenu* menu,
    VfxU32 index)
{
        m_selIndex = index;
        VcpMenuPopup *menuPopup;
        VfxWString str_act;
        VfxWString str_dat;
        srv_callset_ip_number_item_struct item;
        
        if ((srv_callset_ip_number_get_item(index, &item) == SRV_CALLSET_RESULT_OK) &&
                mmi_ucs2strlen((CHAR *)item.number))
        {
        VFX_OBJ_CREATE(menuPopup, VcpMenuPopup, this);
        menuPopup->setTitle(STR_GLOBAL_SELECT);
        
        //create cells of menu popup
        if (srv_sim_ctrl_is_inserted(MMI_SIM1))
        {
            str_act = vapp_sim_settings_get_sim_name_with_sim_id(MMI_SIM1);
            str_act += VFX_WSTR("  ");
            str_dat = str_act;
            str_act += VFX_WSTR_RES(STR_GLOBAL_ACTIVATE);
            str_dat += VFX_WSTR_RES(STR_GLOBAL_DEACTIVATE);
        
            menuPopup->addItem('ACT1',str_act);
            menuPopup->addItem('DAT1', str_dat);
        }
        
#if (MMI_MAX_SIM_NUM >= 2)
        if (srv_sim_ctrl_is_inserted(MMI_SIM2))
        {
            str_act = vapp_sim_settings_get_sim_name_with_sim_id(MMI_SIM2);
            str_act += VFX_WSTR("  ");
            str_dat = str_act;
            str_act += VFX_WSTR_RES(STR_GLOBAL_ACTIVATE);
            str_dat += VFX_WSTR_RES(STR_GLOBAL_DEACTIVATE);
    
            menuPopup->addItem('ACT2', str_act);
            menuPopup->addItem('DAT2', str_dat);
        }
#endif /* (MMI_MAX_SIM_NUM >= 2) */
        menuPopup->addItem('CEL', STR_GLOBAL_CANCEL);
        menuPopup->m_signalMenuCallback.connect(this, &VappCallSetPageIpNum::onMenuSelected);
        menuPopup->show(VFX_TRUE);
        }

}

void VappCallSetPageIpNum::onMenuSelected(VcpMenuPopup *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item)
{//Li Chen
    if (VCP_MENU_POPUP_EVENT_ITEM_SELECTED == event)
    {
        if ('ACT1' == item->getId())
        { 
            //active an ip number
            callset_p->m_sim = (mmi_sim_enum)(callset_p->m_sim | MMI_SIM1);
            srv_callset_ip_number_activate(MMI_SIM1, m_selIndex);
            m_listmenu->updateAllItems();
        }
        else if('DAT1' == item->getId())
        {
            //dective an ip number
            callset_p->m_sim = (mmi_sim_enum)(callset_p->m_sim | (~MMI_SIM1));
            srv_callset_ip_number_deactivate(MMI_SIM1, m_selIndex);
            m_listmenu->updateAllItems();
        }
#if (MMI_MAX_SIM_NUM >= 2)
        else if ('ACT2' == item->getId())
        {
            callset_p->m_sim = (mmi_sim_enum)(callset_p->m_sim | MMI_SIM2);
            srv_callset_ip_number_activate(MMI_SIM2, m_selIndex);
            m_listmenu->updateAllItems();
        }
        else if('DAT2' == item->getId())
        {
            callset_p->m_sim = (mmi_sim_enum)(callset_p->m_sim | (~MMI_SIM2));
            srv_callset_ip_number_deactivate(MMI_SIM2, m_selIndex);
            m_listmenu->updateAllItems();
        }
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    }
    else
    {
        m_selIndex = -1;
    }
}

mmi_ret VappCallSetPageIpNum::hdlrSimAvailabilityChange(mmi_event_struct *evt)
{
    VappCallSetPageIpNum *thiz = (VappCallSetPageIpNum *)handleToObject((VfxObjHandle)evt->user_data);
	
	if (thiz != NULL)
	{
        thiz->updateIpNum();
		thiz->m_listmenu->updateAllItems();
	}   

    return MMI_RET_OK;
}
#endif /* __IP_NUMBER__ */


void VappCallSetPageCtr::onInit()
{
    VfxPage::onInit(); // call base class

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(STR_ID_VAPP_CALLSET_CTR);
    setTopBar(titlebar);

    m_count = 3;

    srv_callset_ctr_struct info;
    m_activateIndex = 0;
    if (srv_callset_ctr_get_mode(&info) == SRV_CALLSET_RESULT_OK)
    {
        switch (info.mode)
        {
            case SRV_CALLSET_CTR_MODE_PERIODIC:
                m_activateIndex = 2;
                break;
        
            case SRV_CALLSET_CTR_MODE_SINGLE:
                m_activateIndex = 1;
                break;
        
            default:
                break;
        }
    }

    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);
    menu->setSize(getSize());
    menu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setContentProvider(this);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    menu->m_signalItemTapped.connect(this, &VappCallSetPageCtr::onTapped);
}

VfxBool VappCallSetPageCtr::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

    switch (index)
    {
        case 0:
            text.loadFromRes(STR_GLOBAL_OFF);
            break;

        case 1:
            text.loadFromRes(STR_ID_VAPP_CALLSET_CTR_SING);
            break;

        case 2:
            text.loadFromRes(STR_ID_VAPP_CALLSET_CTR_PERIOD);
            break;

        default:
            return VFX_FALSE;
    }

    return VFX_TRUE;
}

VfxU32 VappCallSetPageCtr::getCount() const {return m_count;}

VcpListMenuItemStateEnum VappCallSetPageCtr::getItemState(
    VfxU32 index   
    ) const 
{
    return (index == m_activateIndex) ?
                VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

void VappCallSetPageCtr::onTapped(
    VcpListMenu* menu,
    VfxU32 index)
{
    switch (index)
    {
        case 0:
            srv_callset_ctr_struct ctr;
            memset(&ctr, 0, sizeof(srv_callset_ctr_struct));
            ctr.mode = SRV_CALLSET_CTR_MODE_OFF;
            srv_callset_result_enum result;
            result = srv_callset_ctr_set_mode(&ctr);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
            }
            getMainScr()->popPage();
            break;

        case 1:
            callset_p->m_inCtr = SRV_CALLSET_CTR_MODE_SINGLE;
            VappCallSetPageCtrTime *pageCtrTime;
            VFX_OBJ_CREATE(pageCtrTime, VappCallSetPageCtrTime, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageCtrTime);
            break;

        case 2:
            callset_p->m_inCtr = SRV_CALLSET_CTR_MODE_PERIODIC;
            VFX_OBJ_CREATE(pageCtrTime, VappCallSetPageCtrTime, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageCtrTime);
            break;
    }

    m_activateIndex = index;

}


void VappCallSetPageCtrTime::onInit()
{
    VappCallSetPageCommonInputAsync::onInit(); // call base class

    m_titleBar->setTitle(STR_ID_VAPP_CALLSET_CTR_TIME);

    VfxWString tmpStr = VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CTR);
    tmpStr += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_LEFT_PARENTHESIS);
    if (callset_p->m_inCtr == SRV_CALLSET_CTR_MODE_SINGLE)
    {
        tmpStr += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CTR_SING);
        setInputBuf(4, VFX_WSTR_EMPTY);
        m_hint->setString(STR_ID_VAPP_CALLSET_CTR_RANGE_SING);
    }
    else if (callset_p->m_inCtr == SRV_CALLSET_CTR_MODE_PERIODIC)
    {
        tmpStr += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CTR_PERIOD);
        setInputBuf(2, VFX_WSTR_EMPTY);
        m_hint->setString(STR_ID_VAPP_CALLSET_CTR_RANGE_PERIODIC);
    }
    tmpStr += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_RIGHT_PARENTHESIS);
    m_mainText->setString(tmpStr);

    m_textInput->setIME(IMM_INPUT_TYPE_NUMERIC);

    m_funcBar->m_signalButtonTap.connect(this, &VappCallSetPageCtrTime::onFuncBtnClicked);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageCtrTime::onFuncBtnClicked);
    
}

void VappCallSetPageCtrTime::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VAPP_CALLSET_FUNC_OK:
        {
            srv_callset_ctr_struct ctr;
            ctr.mode = callset_p->m_inCtr;
            ctr.time = (U16)app_ucs2_atoi((kal_int8*)m_textInput->getText());

            srv_callset_result_enum result;
            result = srv_callset_ctr_set_mode(&ctr);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
            }
            else
            {
                getMainScr()->popPage();
                getMainScr()->popPage();
            }
            break;
        }

        default:
            return VappCallSetPageCommonInputAsync::onFuncBtnClicked(sender, id);
    }
}


#ifdef __MMI_CH_QUICK_END__

void VappCallSetPageQuickEnd::onInit()
{
    VappCallSetPageCommonInputAsync::onInit(); // call base class

    m_titleBar->setTitle(STR_ID_VAPP_CALLSET_QUICK_END_INPUT_TIME);
    m_mainText->setString(STR_ID_VAPP_CALLSET_QUICK_END_TIME);
    
    m_textInput->setIME(IMM_INPUT_TYPE_NUMERIC);

	if (callset_p->m_inQuickEndTime != 0)
	{
	    VfxWChar time_str[5];
    	memset(time_str, 0, sizeof(time_str));
    	app_ucs2_itoa((kal_int32)callset_p->m_inQuickEndTime, (kal_int8*)time_str, 10);
	
		setInputBuf(4, VFX_WSTR_MEM(time_str));
	}
	else
	{
		setInputBuf(4, VFX_WSTR_NULL);
	}
    
    
    m_hint->setString(STR_ID_VAPP_CALLSET_QUICK_END_DURATION);

    m_funcBar->m_signalButtonTap.connect(this, &VappCallSetPageQuickEnd::onFuncBtnClicked);
    m_toolBar->m_signalButtonTap.connect(this, &VappCallSetPageQuickEnd::onFuncBtnClicked);
    
}

void VappCallSetPageQuickEnd::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VAPP_CALLSET_FUNC_OK:
        {
            callset_p->m_inQuickEndTime = app_ucs2_atoi((kal_int8*)m_textInput->getText());

            srv_callset_result_enum result;
            result = srv_callset_auto_quick_end_set_mode(
                (MMI_BOOL)callset_p->m_inQuickEnd, 
                (U16)callset_p->m_inQuickEndTime);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this,
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
            }
            else
            {
                getMainScr()->popPage();
            }
            break;
        }

        default:
            return VappCallSetPageCommonInputAsync::onFuncBtnClicked(sender, id);
    }
}
#endif /* __MMI_CH_QUICK_END__ */


#ifdef __MMI_UCM_REJECT_BY_SMS__
void VappCallSetPageRejBySms::onInit()
{
    VfxPage::onInit(); // call base class

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setBounds(0, 0, getSize().width, getSize().height);
    form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_CALLSET_REJ_BY_SMS);
    setTopBar(bar);

    VcpFormItemSwitchCell *swh;
    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, form);
    swh->setMainText(STR_ID_VAPP_CALLSET_REJ_BY_SMS_USE);
    swh->setSwitchStatus(
            srv_callset_reject_by_sms_get_mode() ? 
            VFX_TRUE : VFX_FALSE);
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageRejBySms::onSwitch);
    form->addItem(swh, 1);

    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, form);
    swh->setMainText(STR_ID_VAPP_CALLSET_REJ_BY_SMS_REJ_AFTER_SEND);
    swh->setSwitchStatus(
        (srv_callset_reject_by_sms_get_setting() == SRV_CALLSET_REJ_BY_SMS_END_CALL_AFTER_SEND) ? 
        VFX_TRUE : VFX_FALSE);
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageRejBySms::onSwitch);
    form->addItem(swh, 2);

    VcpFormItemLauncherCell *launch;
    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, form);
    launch->setMainText(STR_ID_VAPP_CALLSET_REJ_BY_SMS_TEMPLATE);
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetPageRejBySms::onItemTap);
    form->addItem(launch, 3);
}

void VappCallSetPageRejBySms::onItemTap(VcpFormItemCell *item, VfxId id)
{
    switch (id)
    {
        case 3:
            VappCallSetPageSmsTemplate *page;
            VFX_OBJ_CREATE(page, VappCallSetPageSmsTemplate, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, page);
            break;
    }
}

void VappCallSetPageRejBySms::onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
    switch (id)
    {
        case 1:
            srv_callset_reject_by_sms_set_mode((MMI_BOOL)state);
            item->setSwitchStatus(state);
            break;

        case 2:
            srv_callset_result_enum result;
            result = srv_callset_reject_by_sms_set_setting(
                state ? SRV_CALLSET_REJ_BY_SMS_END_CALL_AFTER_SEND : SRV_CALLSET_REJ_BY_SMS_DEFAULT);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                item->setSwitchStatus(!state);
            }
            else
            {
                item->setSwitchStatus(state);
            }
            break;
    }
}



void VappCallSetPageSmsTemplate::onInit()
{
    VappTextTemplatePage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_CALLSET_REJ_BY_SMS_TEMPLATE);
    setTopBar(bar);    
}

void VappCallSetPageSmsTemplate::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}
#endif /* __MMI_UCM_REJECT_BY_SMS__ */


#if (MMI_MAX_SIM_NUM >= 2)
void VappCallSetPageSimSel::onInit()
{
    VfxPage::onInit(); // call base class

    mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, &VappCallSetPageSimSel::hdlrSimAvailabilityChange, getObjHandle());

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setBounds(0, 0, getSize().width, getSize().height);
    form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_CALLSET_SEL_SIM);
    setTopBar(bar);

	for (VfxU32 i = 0; i < MMI_SIM_TOTAL; i++)
	{
		VFX_OBJ_CREATE(m_launchSim[i], VcpFormItemLauncherCell, form);

		m_launchSim[i]->setMainText(vapp_sim_settings_get_sim_name_with_sim_id(mmi_frm_index_to_sim(i)));
			
		m_launchSim[i]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
		m_launchSim[i]->m_signalTap.connect(this, &VappCallSetPageSimSel::onItemTap);
		form->addItem(m_launchSim[i], (VfxId)mmi_frm_index_to_sim(i));
	}

}

void VappCallSetPageSimSel::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, &VappCallSetPageSimSel::hdlrSimAvailabilityChange, getObjHandle());

    VfxPage::onDeinit();
}

void VappCallSetPageSimSel::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    updateForm();
}

void VappCallSetPageSimSel::updateForm()
{
	for (VfxU32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
		if (!srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
	    {
			m_launchSim[i]->setIsHidden(VFX_TRUE);
	    }
	    else
	    {
	    	m_launchSim[i]->setIsHidden(VFX_FALSE);
			if (!srv_callset_is_available(mmi_frm_index_to_sim(i)))
			{
				m_launchSim[i]->setIsDisabled(VFX_TRUE);
			}
			else
			{
				m_launchSim[i]->setIsDisabled(VFX_FALSE);
			}
		}
    }
}

void VappCallSetPageSimSel::onItemTap(VcpFormItemCell *item, VfxId id)
{
	callset_p->m_sim = (mmi_sim_enum)id;

    VappCallSetPageAdditional *pageAdditional;
    VFX_OBJ_CREATE(pageAdditional, VappCallSetPageAdditional, getMainScr());
	
    getMainScr()->pushPage(VFX_ID_NULL, pageAdditional);
}

mmi_ret VappCallSetPageSimSel::hdlrSimAvailabilityChange(mmi_event_struct *evt)
{
    VappCallSetPageSimSel *thiz = (VappCallSetPageSimSel *)handleToObject((VfxObjHandle)evt->user_data);
	
	if (thiz != NULL)
	{
		thiz->updateForm();
	}   

    return MMI_RET_OK;
}
#endif /* MMI_MAX_SIM_NUM */


void VappCallSetAsyncPage::onInit()
{
    VfxPage::onInit(); // call base class

    m_state = STATE_NONE;
    m_wait = NULL;
}

void VappCallSetAsyncPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    callset_p->m_asyncPage = this;
}

void VappCallSetAsyncPage::onExit(VfxBool isBackward)
{
    callset_p->m_asyncPage = NULL;

    VfxPage::onExit(isBackward);
}

void VappCallSetAsyncPage::setCurrState(const VfxU32 &state)
{
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_CALLSET_SET_STATE, state);
	
	m_state = state;
}

VfxU32 VappCallSetAsyncPage::getCurrState(void)
{
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_CALLSET_GET_STATE, m_state);
	return m_state;
}

void VappCallSetAsyncPage::showWaitPopup(const VfxWString &text, const VfxBool &allowCancel)
{
    VAPP_CALLSET_WAIT_POPUP(m_wait, this, text, 
        (allowCancel ? &VappCallSetAsyncPage::onCancelClicked : NULL));
}

void VappCallSetAsyncPage::leaveWaitPopup(void)
{
    if (m_wait)
    {
        m_wait->leave(VFX_TRUE);
        m_wait = NULL;
    }
}

void VappCallSetAsyncPage::onCancelClicked(VfxObject* sender, VfxFloat progress)
{
    setCurrState(STATE_NONE);
    onResult(NULL);
}


void VappCallSetPageAdditional::onInit()
{
    VappCallSetAsyncPage::onInit(); // call base class

    mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, &VappCallSetPageAdditional::hdlrSimAvailabilityChange, getObjHandle());

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setBounds(0, 0, getSize().width, getSize().height);
    form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);

    VfxWString str;
	if (srv_sim_ctrl_get_num_of_inserted() >= 2)
	{
    	str = vapp_sim_settings_get_sim_name_with_sim_id((callset_p->m_sim));
	}
	else
	{
		str.loadFromRes(STR_ID_VAPP_CALLSET_MORE);
	}

    bar->setTitle(str);
    setTopBar(bar);

#ifdef __MMI_CALLSET_CALLER_ID__
	m_callerIdState = STATE_NONE;
	if (srv_callset_is_caller_id_supported(callset_p->m_sim))
	{
		VFX_OBJ_CREATE(m_cid, VcpFormItemSwitchCell, form);
		m_cid->setMainText(STR_ID_VAPP_CALLSET_CID_HIDE);
		m_cid->setHintText(STR_ID_VAPP_CALLSET_CID_HINT);
		m_cid->m_signalSwitchChangeReq.connect(this, &VappCallSetPageAdditional::onSwitchCallerId);
		form->addItem(m_cid, 1);
	}

#endif /* __MMI_CALLSET_CALLER_ID__ */


    VFX_OBJ_CREATE(m_cw, VcpFormItemSwitchCell, form);
    m_cw->setMainText(STR_ID_VAPP_CALLSET_CALLWAIT);
    m_cw->setHintText(STR_ID_VAPP_CALLSET_CALLWAIT_HINT);
    m_cw->m_signalSwitchChangeReq.connect(this, &VappCallSetPageAdditional::onSwitchCw);
    form->addItem(m_cw, 2);
    m_cwEnabled = VFX_FALSE;
	if (!srv_ss_check_capability(callset_p->m_sim, SRV_SS_ACT_CALL_WAIT, 0, SRV_SS_ALL_CALL))
	{
		m_cw->setIsHidden(VFX_TRUE);
	}
	else
	{
		m_cw->setIsHidden(VFX_FALSE);
	}

	VcpFormItemLauncherCell *launch;
	if (srv_ss_check_capability(callset_p->m_sim, SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFALL, SRV_SS_ALL_CALL))
	{
		VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, form);
		launch->setMainText(STR_ID_VAPP_CALLSET_CALLFWD);
		launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
		launch->m_signalTap.connect(this, &VappCallSetPageAdditional::onItemTap);
		form->addItem(launch, 3);
	}

	if (srv_ss_check_capability(callset_p->m_sim, SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BAC, SRV_SS_ALL_CALL))
	{
	    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, form);
	    launch->setMainText(STR_ID_VAPP_CALLSET_CALL_BAR);
	    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	    launch->m_signalTap.connect(this, &VappCallSetPageAdditional::onItemTap);
	    form->addItem(launch, 4);	
	}

#ifdef __MMI_CALLSET_CUG__
    VFX_OBJ_CREATE(m_cug, VcpFormItemLauncherCell, form);
    m_cug->setMainText(STR_ID_VAPP_CALLSET_CUG);
    m_cug->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_cug->m_signalTap.connect(this, &VappCallSetPageAdditional::onItemTap);
    form->addItem(m_cug, 5);
	if (!srv_callset_is_cug_supported(callset_p->m_sim))
	{
		m_cug->setIsHidden(VFX_TRUE);
	}
	else
	{
		m_cug->setIsHidden(VFX_FALSE);
	}
#endif /* __MMI_CALLSET_CUG__ */

    if (srv_callset_line_switch_get_id(callset_p->m_sim) != SRV_CALLSET_LINE_NOT_SUPPORT)
    {
        VFX_OBJ_CREATE(m_lsw, VcpFormItemLauncherCell, form);
        m_lsw->setMainText(STR_ID_VAPP_CALLSET_LINE_SWITCH);
        m_lsw->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_lsw->m_signalTap.connect(this, &VappCallSetPageAdditional::onItemTap);
        form->addItem(m_lsw, 6);
    }

}

void VappCallSetPageAdditional::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, &VappCallSetPageAdditional::hdlrSimAvailabilityChange, getObjHandle());

    VappCallSetAsyncPage::onDeinit();
}

void VappCallSetPageAdditional::onEnter(VfxBool isBackward)
{
    VappCallSetAsyncPage::onEnter(isBackward);

    updateForm();
    queryData();
}

void VappCallSetPageAdditional::onExit(VfxBool isBackward)
{
    if (getCurrState() == STATE_GET_CW ||
        getCurrState() == STATE_SET_CW)
    {
		VappCallSetPageAdditional::sendAbortSS();

        m_callerIdState = STATE_NONE;
    }

    VappCallSetAsyncPage::onExit(isBackward);
}

void VappCallSetPageAdditional::updateForm(void)
{
#ifdef __MMI_CALLSET_CUG__
	if (!m_cug->getIsHidden())
	{
	    srv_callset_cug_get_item_struct item;
	    VfxU32 id = (VfxU32)srv_callset_cug_get_actviated_id(callset_p->m_sim);
	    if (id > 9)
	    {
	        m_cug->setHintText(STR_GLOBAL_OFF);
	    }
	    else if ((srv_callset_cug_get_item(callset_p->m_sim, id, &item) == SRV_CALLSET_RESULT_OK) &&
	                mmi_ucs2strlen((CHAR *)item.name))
	    {
	        VfxWString tmpStr;

			tmpStr.format("[%d] ", id);
	        tmpStr += VFX_WSTR_MEM(item.name);
	        m_cug->setHintText(tmpStr);
	    }
	    else
	    {
	        m_cug->setHintText(STR_GLOBAL_OFF);
	    }
	}
#endif /* __MMI_CALLSET_CUG__ */

    switch (srv_callset_line_switch_get_id(callset_p->m_sim))
    {
        case SRV_CALLSET_LINE_NOT_SUPPORT:
            break;

        case SRV_CALLSET_LINE2:
            m_lsw->setHintText(STR_ID_VAPP_CALLSET_LSW_LINE2);
            break;

        default:
            m_lsw->setHintText(STR_ID_VAPP_CALLSET_LSW_LINE1);
            break;
    }
}

void VappCallSetPageAdditional::queryData(void)
{
#ifdef __MMI_CALLSET_CALLER_ID__
	if (srv_callset_is_caller_id_supported(callset_p->m_sim))
	{
		getCallerIdState();
	}    
#endif /* __MMI_CALLSET_CALLER_ID__ */

    m_cw->setSwitchStatus(VFX_FALSE);
    m_cw->setIsDisabled(VFX_TRUE);
    m_cw->showProcessInd();

    srv_ss_call_wait_req_struct req;

    req.sim = callset_p->m_sim;
    req.source = SRV_SS_SRC_CALLSET;
    req.action = SRV_SS_ACTION_TYPE_QUERY;
    srv_ss_act_req(
            SRV_SS_ACT_CALL_WAIT, 
            &req, 
            vapp_callset_hdlr_rsp, 
            NULL);

    setCurrState(STATE_GET_CW);

}


#ifdef __MMI_CALLSET_CALLER_ID__
void VappCallSetPageAdditional::onSwitchCallerId(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
	m_cid->setIsDisabled(VFX_TRUE);
	m_cid->showProcessInd();
	
	srv_callset_cid_set_mode_struct cid_info;

	cid_info.sim = callset_p->m_sim;
	cid_info.mode = state ? SRV_CALLSET_CALLER_ID_HIDE : SRV_CALLSET_CALLER_ID_SHOW;
	srv_callset_caller_id_set_mode(&cid_info, VappCallSetPageAdditional::onCallerIDCallback, getObjHandle());

	m_callerIdState = STATE_SET_CID;
}

void VappCallSetPageAdditional::getCallerIdState(void)
{
	if (m_cid->getIsHidden())
	{
		return;
	}
	
	m_cid->setSwitchStatus(VFX_FALSE);
	m_cid->setIsDisabled(VFX_TRUE);
	m_cid->showProcessInd();

	srv_callset_caller_id_mode_enum mode;
	mode = srv_callset_caller_id_get_mode(callset_p->m_sim);

	if (mode == SRV_CALLSET_CALLER_ID_BY_NETWORK)
	{
		/* invalid mode */
		/* continue to set cid */
		srv_callset_cid_set_mode_struct cid_info;

		cid_info.sim = callset_p->m_sim;
		cid_info.mode = SRV_CALLSET_CALLER_ID_SHOW;
		srv_callset_caller_id_set_mode(
			&cid_info, VappCallSetPageAdditional::onCallerIDCallback, getObjHandle());
		
		m_callerIdState =  STATE_SET_CID;
	}
	else
	{
		/* canceled and get cid successfully */
		/* continue to update cid */
		m_callerIdState = STATE_GET_CID;
		processCallIDEvt(NULL);
	}

}

mmi_ret VappCallSetPageAdditional::onCallerIDCallback(mmi_event_struct *evt)
{
	VappCallSetPageAdditional *thiz = (VappCallSetPageAdditional *)handleToObject((VfxObjHandle)evt->user_data);

	if (thiz != NULL)
	{
		thiz->processCallIDEvt(evt);
	}

	return MMI_RET_OK;
}

void VappCallSetPageAdditional::processCallIDEvt(mmi_event_struct *evt)
{
	if (m_cid->getIsHidden())
	{
		return;
	}

	switch(m_callerIdState)
	{
        case STATE_SET_CID:
        {
            srv_callset_rsp_evt_struct *cid_evt_2 = (srv_callset_rsp_evt_struct*)evt;
            srv_callset_result_struct *cid_result_2 = (srv_callset_result_struct*)(cid_evt_2->data);
            if (cid_result_2->result != SRV_CALLSET_RESULT_OK)
            {
                m_cid->hideProcessInd();
				m_callerIdState = STATE_NONE;
            }
            else
            {
                m_callerIdState = STATE_GET_CID;
                processCallIDEvt(NULL);
            }
            break;
        }

        case STATE_GET_CID:
        {
			srv_callset_caller_id_mode_enum mode;
            mode = srv_callset_caller_id_get_mode(callset_p->m_sim);
            m_cid->hideProcessInd();
            if (mode != SRV_CALLSET_CALLER_ID_BY_NETWORK)
            {
                m_cid->setIsDisabled(VFX_FALSE);
                m_cid->setSwitchStatus((mode == SRV_CALLSET_CALLER_ID_HIDE) ? VFX_TRUE : VFX_FALSE);
            }
            m_callerIdState = STATE_NONE;
            break;
        }
		
		default:
			break;
	}
}
#endif /*  __MMI_CALLSET_CALLER_ID__ */

void VappCallSetPageAdditional::onResult(mmi_event_struct *info)
{
    if (getCurrState() >= STATE_INVALID)
    {
        /* abnomal */
        return;
    }

    srv_ss_rsp_evt_struct *evt = (srv_ss_rsp_evt_struct*)info;
    srv_ss_call_wait_rsp_struct *cw_rsp;

    switch (getCurrState())
    {
        case STATE_GET_CW:
        {
            if (info->evt_id != EVT_ID_SRV_SS_ACT_RESPONSE ||
                evt->rsp.opcode != SRV_SS_ACT_CALL_WAIT ||
                evt->rsp.result == SRV_SS_RESULT_ABORT)
            {
                /* ignore */
                /* may receive the rsp for other pages (cf / cb...) */
                return;
            }

            /* cw result */
            m_cw->hideProcessInd();
            if (evt->rsp.result == SRV_SS_RESULT_OK)
            {
                m_cw->setIsDisabled(VFX_FALSE);
                cw_rsp = (srv_ss_call_wait_rsp_struct*)(evt->rsp.data);
                switch (cw_rsp->status)
                {
                    case SRV_SS_STATUS_ACTIVATED:
                    case SRV_SS_STATUS_ACTIVATED_PERMANTLY:
                    case SRV_SS_STATUS_ACTIVATED_BY_DEFAULT:
                    case SRV_SS_STATUS_PROVIDED:
                        m_cw->setSwitchStatus(VFX_TRUE);
                        break;
                }
            }
            setCurrState(STATE_NONE);
            break;
        }

        case STATE_SET_CW:
        {
            m_cw->hideProcessInd();

            if (evt->rsp.result != SRV_SS_RESULT_OK)
            {
                m_cw->setSwitchStatus(VFX_FALSE);
            }
            else
            {
                m_cw->setIsDisabled(VFX_FALSE);
                cw_rsp = (srv_ss_call_wait_rsp_struct*)(evt->rsp.data);
                switch (cw_rsp->status)
                {
                    case SRV_SS_STATUS_ACTIVATED:
                    case SRV_SS_STATUS_ACTIVATED_PERMANTLY:
                    case SRV_SS_STATUS_ACTIVATED_BY_DEFAULT:
                    case SRV_SS_STATUS_PROVIDED:
                        m_cw->setSwitchStatus(VFX_TRUE);
                        break;

                    default:
                        m_cw->setSwitchStatus(VFX_FALSE);
                        break;
                }
            }

            setCurrState(STATE_NONE);

            break;
        }
    }
}

void VappCallSetPageAdditional::onSelectType(VfxId id, VfxU32 usrData)
{
	callset_p->m_inCallType = (srv_ss_call_type_enum)id;

	if (usrData == 3)
	{
	    VappCallSetPageCf *page;
	    VFX_OBJ_CREATE(page, VappCallSetPageCf, getMainScr());
	    getMainScr()->pushPage(VFX_ID_NULL, page);
	}
	else if (usrData == 4)
	{		
		VappCallSetPageCb *page;
		VFX_OBJ_CREATE(page, VappCallSetPageCb, getMainScr());
		getMainScr()->pushPage(VFX_ID_NULL, page);
	}
}

void VappCallSetPageAdditional::onItemTap(VcpFormItemCell *item, VfxId id)
{
    switch (id)
    {
        case 3:
			VappCallSetCallTypeSelPage *cfSelPage;
	
            VFX_OBJ_CREATE_EX(cfSelPage, VappCallSetCallTypeSelPage, getMainScr(), (id));
			cfSelPage->setTitleString(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CALLFWD));
			cfSelPage->m_signalCalType.connect(this, &VappCallSetPageAdditional::onSelectType);
			
			getMainScr()->pushPage(VFX_ID_NULL, cfSelPage);
            break;

        case 4:
	#ifdef __MMI_CB_CALLTYPE_SUPPORT__
			VappCallSetCallTypeSelPage *cbSelPage;
	
            VFX_OBJ_CREATE_EX(cbSelPage, VappCallSetCallTypeSelPage, getMainScr(), (id));
			cbSelPage->setTitleString(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CALL_BAR));
			cbSelPage->m_signalCalType.connect(this, &VappCallSetPageAdditional::onSelectType);
			
            getMainScr()->pushPage(VFX_ID_NULL, cbSelPage);
	#else
		    VappCallSetPageCb *page;
		    VFX_OBJ_CREATE(page, VappCallSetPageCb, getMainScr());
		    getMainScr()->pushPage(VFX_ID_NULL, page);
	#endif
            break;

    #ifdef __MMI_CALLSET_CUG__
        case 5:
            VappCallSetPageCug *pageCug;
            VFX_OBJ_CREATE(pageCug, VappCallSetPageCug, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageCug);
            break;
    #endif /* __MMI_CALLSET_CUG__ */

        case 6:
            VappCallSetPageLsw *pageLsw;
            VFX_OBJ_CREATE(pageLsw, VappCallSetPageLsw, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageLsw);
            break;
    }
}

void VappCallSetPageAdditional::onSwitchCw(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
    m_cw->setIsDisabled(VFX_TRUE);
    m_cw->showProcessInd();
	
    srv_ss_call_wait_req_struct req;
    
    req.sim = callset_p->m_sim;
    req.source = SRV_SS_SRC_CALLSET;
    req.action = state ? SRV_SS_ACTION_TYPE_ACTIVATE : SRV_SS_ACTION_TYPE_DEACTIVATE;
    srv_ss_act_req(
            SRV_SS_ACT_CALL_WAIT, 
            &req, 
            vapp_callset_hdlr_rsp, 
            NULL);
    
    setCurrState(STATE_SET_CW);
}

void VappCallSetPageAdditional::sendAbortSS(void)
{
	srv_ss_abort_req_struct abortReq;
	
	abortReq.sim = callset_p->m_sim;
	abortReq.source = SRV_SS_SRC_CALLSET;
	
	srv_ss_act_req(SRV_SS_ACT_ABORT, &abortReq, NULL, NULL);
}

mmi_ret VappCallSetPageAdditional::hdlrSimAvailabilityChange(mmi_event_struct *evt)
{
    srv_sim_ctrl_availability_changed_evt_struct *sim_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;

    if (sim_evt->sim != callset_p->m_sim)
    {
        return MMI_RET_OK;
    }

    if (!sim_evt->is_available_now)
    {
        VappCallSetPageAdditional *page = (VappCallSetPageAdditional *)handleToObject((VfxObjHandle)evt->user_data);
		if (page != NULL)
		{
        	page->getApp()->exit();
		}
    }

    return MMI_RET_OK;
}



void VappCallSetPageLsw::onInit()
{
    VappCallSetAsyncPage::onInit(); // call base class

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(STR_ID_VAPP_CALLSET_LSW_SEL_LINE);
    setTopBar(titlebar);

    m_count = 2;

    switch (srv_callset_line_switch_get_id(callset_p->m_sim))
    {
        case SRV_CALLSET_LINE1:
            m_activateIndex = 0;
            break;

        default:
            m_activateIndex = 1;
            break;
    }

    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);
    menu->setSize(getSize());
    menu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setContentProvider(this);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    menu->m_signalItemTapped.connect(this, &VappCallSetPageLsw::onTapped);
}

void VappCallSetPageLsw::onExit(VfxBool isBackward)
{
    if (getCurrState() == STATE_ACT)
    {
        setCurrState(STATE_ABORT);
        onResult(NULL);
    }

    VappCallSetAsyncPage::onExit(isBackward);
}

VfxBool VappCallSetPageLsw::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	text.loadFromRes(STR_ID_VAPP_CALLSET_LSW_LINE1 + index);
    return VFX_TRUE;
}

VfxU32 VappCallSetPageLsw::getCount() const {return m_count;}

VcpListMenuItemStateEnum VappCallSetPageLsw::getItemState(
    VfxU32 index   
    ) const 
{
    return (index == m_activateIndex) ?
                VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

void VappCallSetPageLsw::onTapped(
    VcpListMenu* menu,
    VfxU32 index)
{
    srv_callset_line_switch_struct lsw;
    lsw.sim = callset_p->m_sim;
	lsw.line_id = (srv_callset_line_id_enum)(SRV_CALLSET_LINE1 + index);

    srv_callset_result_enum result;
    result = srv_callset_line_switch_set_id(&lsw, vapp_callset_hdlr_rsp, NULL);
    setCurrState(STATE_ACT);
    showWaitPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT), VFX_FALSE);
    if (result != SRV_CALLSET_RESULT_OK)
    {
        srv_callset_rsp_evt_struct evt;
        srv_callset_result_struct res;
        res.sim = callset_p->m_sim;
        res.result = result;
        evt.data = &res;
        onResult((mmi_event_struct*)&evt);
    }
    m_activateIndex = index;
}

void VappCallSetPageLsw::onResult(mmi_event_struct *info)
{
    if (getCurrState() == STATE_NONE ||
            getCurrState() >= STATE_INVALID)
    {
        /* abort rsp from the previous page or abnormal */
        return;
    }

    if (getCurrState() != STATE_ABORT)
    {
        srv_callset_rsp_evt_struct *evt = (srv_callset_rsp_evt_struct*)info;
        MMI_ASSERT(info);
        srv_callset_result_struct *res = (srv_callset_result_struct*)(evt->data);
        MMI_ASSERT(res);
        
        if (res->result != SRV_CALLSET_RESULT_OK)
        {
            VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_callset_get_result_string_id(res->result)));
        }
    }

    setCurrState(STATE_NONE);
    leaveWaitPopup();
    getMainScr()->popPage();

}


/***************************************************************************** 
 * VappCallSetCallTypeSelPage
 *****************************************************************************/

void VappCallSetCallTypeSelPage::onInit()
{
    VfxPage::onInit(); // call base class

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    setTopBar(bar);

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
	form->setSize(getSize());	
    form->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemLauncherCell *launch;

    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, form);
    launch->setMainText(STR_ID_VAPP_CALLSET_VOICE);
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetCallTypeSelPage::onItemTap);
    form->addItem(launch, SRV_SS_VOICE_CALL);

#ifdef __MMI_VIDEO_TELEPHONY__
    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, form);
    launch->setMainText(STR_ID_VAPP_CALLSET_VIDEO);
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetCallTypeSelPage::onItemTap);
    form->addItem(launch, SRV_SS_VIDEO_CALL);
#endif /* __MMI_VIDEO_TELEPHONY__ */

    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, form);
    launch->setMainText(STR_ID_VAPP_CALLSET_DATA);
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetCallTypeSelPage::onItemTap);
    form->addItem(launch, SRV_SS_DATA_CALL);
}

void VappCallSetCallTypeSelPage::setTitleString(const VfxWString &title)
{
	VcpTitleBar *bar = (VcpTitleBar *)getBar(VFX_PAGE_BAR_LOCATION_TOP);
	bar->setTitle(title);
}

void VappCallSetCallTypeSelPage::onItemTap(VcpFormItemCell *item, VfxId id)
{
	m_signalCalType.postEmit(id, m_usrData);
}

#pragma arm section code, rodata
