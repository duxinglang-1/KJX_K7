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
 *  Vapp_sat.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements application functions for SAT feature.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"

#ifdef __cplusplus
extern "C"{
#endif

#include "MMIDataType.h"
#include "GpioSrvGprot.h"
#include "GeneralSettingSrvGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "AlarmSrvGprot.h"
#include "UcmSrvGprot.h"
#include "SatSrvGprot.h"
#include "SatCoreProt.h"
#include "ImeiSrvGprot.h"
#include "NwNameSrvGprot.h"
#include "mmi_rp_srv_sat_def.h"
#include "Lang_interface.h"

#ifdef __cplusplus
}
#endif

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vtst_rt_main.h"
#include "vapp_launcher_gprot.h"
#include "vapp_screen_lock_gprot.h"
#include "vcp_popup_data_type.h"
#include "vcp_global_popup.h"
#include "vcp_indicator_popup.h"
#include "vapp_nmgr_gprot.h"
#include "vapp_setting_language_setting.h"

#include "vapp_sat.h"
#include "vapp_sat_base.h"
#include "vapp_sat_view.h"
#include "vapp_sat_editor.h"
#include "vapp_sat_list_menu.h"
#include "vadp_app_trc.h"
#include "vadp_app_trc_gen.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vapp_ncenter_base_cell.h"
#include "ModeSwitchSrvGProt.h"



/**************************************************************
 * Function Defination                                        *
 **************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void vapp_sat_init(void)
{
    for (VfxU16 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        VFX_OBJ_GET_INSTANCE(VappSatMgr)->setSnapScrn((mmi_sim_enum)(1 << i), NULL); 
    }

    VFX_OBJ_GET_INSTANCE(VappSatMgr)->setMainScrn(NULL);
}


mmi_ret mmi_sat_recv_ind(mmi_event_struct *evt)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_INDICATION, evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SAT_PROACTIVE_SIM:
        {
            srv_sat_proactive_sim_event_struct *event = (srv_sat_proactive_sim_event_struct *)evt;
            mmi_ret evt_flag = vapp_sat_handle_instant_cmd(event->proactive_sim);
			return evt_flag;			
            //break;
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
/* under construction !*/
#endif
        default:
            break;
    }

    return MMI_RET_OK;
}
#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
mmi_ret mmi_sat_sim_change_ind(mmi_event_struct *evt)
{
	srv_sim_ctrl_availability_changed_evt_struct *event = (srv_sim_ctrl_availability_changed_evt_struct *)evt;
	VappSatApp *app = (VappSatApp *)VfxAppLauncher::findApp(
											VAPP_SAT,
											VFX_OBJ_CLASS_INFO(VappSatApp),
											VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

	if (event->is_available_before != event->is_available_now)
		{
			if(app)
			{
				VfxAppLauncher::terminate(app->getGroupId());
			}
		}
	return MMI_RET_OK;
}
#endif //__SIM_RECOVERY_ENHANCEMENT__ || __SIM_HOT_SWAP_SUPPORT__

mmi_ret mmi_sat_mode_switch_ind(mmi_event_struct *evt)
{
	VappSatApp *app = (VappSatApp *)VfxAppLauncher::findApp(
											VAPP_SAT,
											VFX_OBJ_CLASS_INFO(VappSatApp),
											VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);
	if(app && evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY)
	{
		VfxAppLauncher::terminate(app->getGroupId());
	}
	
	return MMI_RET_OK;

}



mmi_ret mmi_sat_recv_idle_ind(mmi_event_struct *evt)
{
#ifndef __SAT_LOWCOST_UI_DISABLE__
    srv_sat_envelope_idle_screen_available();
#endif /* __SAT_LOWCOST_UI_DISABLE__ */

    return MMI_RET_OK;
}


MMI_BOOL vapp_sat_app_pre_launch(mmi_scenario_id scen_id, void *arg)
{
    vapp_sat_sim_launch((srv_sat_proactive_sim_struct *)arg);

    return MMI_TRUE;
}


mmi_ret vapp_sat_handle_instant_cmd(srv_sat_proactive_sim_struct *cmd_info)
{
    if (VfxAppLauncher::findApp(VAPP_SAT, VFX_OBJ_CLASS_INFO(VappSatApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG))
    {
        return MMI_RET_OK;
    }

    switch (cmd_info->cmd_type)
    {
        case SRV_SAT_CMD_DISPLAY_TEXT:
            //srv_sat_display_text_struct *display_text = (srv_sat_display_text_struct *)(&cmd_info->cmd_data);

		    if (!vapp_launcher_is_active() &&
		        !VfxAppLauncher::findApp(VAPP_SAT, VFX_OBJ_CLASS_INFO(VappSatApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG) &&
		        ((srv_sat_display_text_struct *)(&cmd_info->cmd_data))->priority == SRV_SAT_PRIORITY_NORMAL)
		    {
		        srv_sat_terminal_response_display_text(
		            cmd_info->sim_id,
		            SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD,
		            SRV_SAT_ADDITIONAL_RES_SCREEN_BUSY);

		        return MMI_RET_DONT_CARE;
		    }

		    if (vapp_screen_lock_is_locked())
		    {
		        vapp_sat_sim_launch(cmd_info);
				return MMI_RET_DONT_CARE;
		    }
            break;

        case SRV_SAT_CMD_SEND_DTMF:
            //vapp_sat_send_dtmf_process(cmd_info);
            //srv_sat_terminal_response_send_dtmf_stage1(cmd_info->sim_id);
            break;

        case SRV_SAT_CMD_SETUP_MENU:
        case SRV_SAT_CMD_SETUP_IDLE_MODE_TEXT:
        case SRV_SAT_CMD_REFRESH:
            return MMI_RET_DONT_CARE;

        default:
            break;
    }
            mmi_frm_nmgr_notify_by_app(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_NON_TONE,
                    vapp_sat_app_pre_launch,
                    cmd_info);
	return MMI_RET_DONT_CARE;
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
#endif
mmi_ret vapp_sat_onRecvIdleTextInd(mmi_event_struct *evt)
{
	VFX_ASSERT(evt != NULL);
	srv_sat_setup_idle_display_event_struct *idle_mode_text = (srv_sat_setup_idle_display_event_struct *)evt;
	VsrvNGroupSingleTitle *group = NULL;
	VSRV_NGROUP_CREATE_EX(group , VsrvNGroupSingleTitle, (VAPP_SAT));
	group->setTitle(VFX_WSTR_RES(STR_ID_SAT_MENU_TITLE));
	VsrvNotificationCustom *noti = NULL;
	if(idle_mode_text->present)
	{
		mmi_frm_notification_para_struct noti_status;
    noti_status.option = 0;
    noti_status.text = srv_sat_get_idle_display_text(idle_mode_text->sim_id);
		mmi_frm_nmgr_notify(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SAT_IDLE_TEXT, &noti_status);
		VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationCustom , (group, mmi_frm_sim_to_index(idle_mode_text->sim_id)));
		noti->setCategory(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT);
		noti->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VappSatNcell), VSRV_NVIEWER_TYPE_GENERAL, evt, sizeof(srv_sat_setup_idle_display_event_struct));
		noti->setFlag(VSRV_NOTIFICATION_FLAG_NO_CLEAR_BUTTON, VFX_TRUE);
				VfxDateTime dateTime;
		dateTime.setCurrentTime();
		noti->setTimeStamp(dateTime);
		noti->setAutoClose(VFX_FALSE);
		noti->notify();
		
	}
	else
	{
		VSRV_NOTIFICATION_CLOSE_EX(group, mmi_frm_sim_to_index(idle_mode_text->sim_id));
	}
	if(group->getCount() == 0)
	{
		VSRV_NGROUP_CLOSE_EX(VAPP_SAT);
	}
	return MMI_RET_OK;

}

/***************************************************************************** 
 * Vapp_Sat Launch
 *****************************************************************************/
void vapp_sat_user_launch(void)
{
    U32 i;

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_USER_LAUNCH);

    VappSatParam param;
    param.act       = VAPP_SAT_USER_ACT;
    param.simId     = MMI_SIM1;
    param.cmdType   = SRV_SAT_CMD_SETUP_MENU;

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum simId = (mmi_sim_enum)(1 << i);
        if (srv_sat_is_menu_present(simId))
        {
            param.simId = simId;
            break;
        }
    }

    VfxAppLauncher::launch(
        VAPP_SAT,
        VFX_OBJ_CLASS_INFO(VappSatApp),
        GRP_ID_ROOT,
        &param,
        sizeof(VappSatParam));
}


void vapp_sat_sim_launch(srv_sat_proactive_sim_struct *cmd_info)
{
    VappSatParam param;
    param.act       = VAPP_SAT_SIM_ACT;
    param.simId     = cmd_info->sim_id;
    param.cmdType   = cmd_info->cmd_type;

    VappSatApp *app = (VappSatApp *)VfxAppLauncher::findApp(VAPP_SAT, VFX_OBJ_CLASS_INFO(VappSatApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG);

    if (!app)
    {
        VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_SIM_LAUNCH);

        VfxAppLauncher::launch(
            VAPP_SAT,
            VFX_OBJ_CLASS_INFO(VappSatApp),
            GRP_ID_ROOT,
            &param,
            sizeof(VappSatParam));
    }
}


void vapp_sat_cmd_session_end(srv_sat_proactive_sim_struct *cmd_info)
{
}


void mmi_sat_calculate_screen_capability(kal_uint8 *max_char_down, kal_uint8 *max_char_accross)
{
    /* approximate calculation */
    *max_char_down = (U8)(VCP_INDICATOR_POPUP_TEXT_HEIGHT / VCP_INDICATOR_POPUP_FONT_SIZE);
    *max_char_accross = (U8)((VCP_INDICATOR_POPUP_CONTENT_WIDTH) / VCP_INDICATOR_POPUP_FONT_SIZE);
}

#ifdef __cplusplus
}
#endif


#ifdef __AFX_RT_TEST__
void VappVtstSatLaunch(void)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_USER_LAUNCH);

    VappSatParam param;
    param.act       = VAPP_SAT_USER_ACT;
    param.simId     = MMI_SIM_NONE;
    param.cmdType   = SRV_SAT_CMD_SETUP_MENU;

    VfxAppLauncher::launch(
        VAPP_SAT,
        VFX_OBJ_CLASS_INFO(VappSatApp),
        GRP_ID_ROOT,
        &param,
        sizeof(VappSatParam));

}


VtstTestResultEnum vtst_rt_vapp_sat(VfxU32 param)
{
    VFX_UNUSED(param);
    VappVtstSatLaunch();

   return VTST_TR_OK;
}
#endif

/***************************************************************************** 
 * Class VappSatNcell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSatNcell", VappSatNcell, VsrvNCell);

void VappSatNcell::onCreateView(void * viewData,VfxU32 viewDataSize)
{
	VsrvNCell::onCreateView(viewData, viewDataSize);

        VFX_OBJ_CREATE(m_notification, VappSatContextNcell, this);
        m_notification->setNotification(getNotification());
        setSize(m_notification->getSize());

		m_notification->setIsDisabled(VFX_TRUE);
        m_notification->createBaseCellWithMarquee(viewData);

}

//VFX_IMPLEMENT_CLASS("VappSatContextNcell", VappSatContextNcell, VappNCenterEventCell);
VappSatContextNcell::VappSatContextNcell()
{
}

VappSatContextNcell::~VappSatContextNcell()
{
}

void VappSatContextNcell::onInit()
{
	VappNCenterEventCell::onInit();
}

void VappSatContextNcell::updateElements()
{

	VappNCenterEventCell::updateElements();
}

void VappSatContextNcell::createBaseCellWithMarquee(void *viewData)
{
	srv_sat_setup_idle_display_event_struct *idle_mode_text_ext = (srv_sat_setup_idle_display_event_struct *)viewData;
	srv_nw_name_service_indication_struct tmp_indication;
	if(srv_imei_is_valid(idle_mode_text_ext->sim_id))
	{
		srv_nw_name_get_service_indication_string(idle_mode_text_ext->sim_id, &tmp_indication);
		m_mainText->setString(tmp_indication.line2);
	}
	else
	{
		if(idle_mode_text_ext->sim_id == MMI_SIM1)
		{
			m_mainText->setString(STR_ID_VAPP_SAT_SIM1);

		}		
#if MMI_MAX_SIM_NUM >= 2
		else if(idle_mode_text_ext->sim_id == MMI_SIM2)
	{
			m_mainText->setString(STR_ID_VAPP_SAT_SIM2);
	}
#if MMI_MAX_SIM_NUM >= 3
		else if(idle_mode_text_ext->sim_id == MMI_SIM3)
    {
			m_mainText->setString(STR_ID_VAPP_SAT_SIM3);

    }
#if MMI_MAX_SIM_NUM >= 4	
		else if(idle_mode_text_ext->sim_id == MMI_SIM4) 		{
			m_mainText->setString(STR_ID_VAPP_SAT_SIM4);

		}
#endif
#endif
#endif

	}	
	

	VFX_OBJ_CREATE(m_cText, VcpMarquee, this);
	//srv_nw_name_get_service_indication_string(mmi_sim_enum sim,srv_nw_name_service_indication_struct * service_indication)
	if(srv_sat_get_idle_display_icon(idle_mode_text_ext->sim_id) == NULL)
	{
		m_icon->setImgContent(VfxImageSrc(IMG_ID_VAPP_SAT_PREVIEW));
	}
	else
	{
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    m_icon->setImgContent(VfxImageSrc(srv_sat_get_idle_display_icon(idle_mode_text_ext->sim_id)));
#else
		m_icon->setImgContent(VfxImageSrc(IMG_ID_VAPP_SAT_PREVIEW));
#endif //__SAT_DISABLE_ICON_SUPPORT__
        }
    	m_cText->setPos(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X, VAPP_NCENTER_EVENT_CELL_HEIGHT - VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y);
	m_cText->setAnchor(0, 1.0f);
	//m_cText->setPos(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X, VAPP_NCENTER_EVENT_CELL_HEIGHT - VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y);
	m_cText->setAutoResized(VFX_TRUE);
	m_cText->setSize(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH, m_subText->getSize().height);
	m_cText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

	
    m_cText->setMovableFrame(srv_sat_get_idle_display_text(idle_mode_text_ext->sim_id), VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE)));
    m_cText->setTextColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
    m_cText->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);
    m_cText->startScroll();


	VsrvNotificationEvent* noti = (VsrvNotificationEvent*)m_noti;
	VfxDateTime currTime, notiTime = noti->getTimeStamp();
	currTime.setCurrentTime();
	if (notiTime.getYear() == currTime.getYear()&&
            notiTime.getMonth() == currTime.getMonth() &&
            notiTime.getDay() == currTime.getDay())
    {
        m_rightText->setString(noti->getTimeStamp().getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE)); 
    }
    else
    {
		m_rightText->setString(noti->getTimeStamp().getDateTimeString(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY));                                        
}

}


/***************************************************************************** 
 * Class VappSatMgr
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappSatMgr);

VappSatMgr::VappSatMgr()
{
    for (VfxU8 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        m_satMainScrn[i] = NULL;
        m_menuItemIndex[i] = -1; // -1 is invalid value
    }
}


VappSatMainScrn *VappSatMgr::getScrn(VappSatScreenIdEnum scrnId)
{
    return m_satMainScrn[scrnId];
}


void VappSatMgr::setMainScrn(VappSatMainScrn *scrn)
{
    m_satMainScrn[VAPP_SAT_MAIN_SCRN] = scrn;
}


VappSatMainScrn *VappSatMgr::getMainScrn()
{
    return m_satMainScrn[VAPP_SAT_MAIN_SCRN];
}


void VappSatMgr::setSnapScrn(mmi_sim_enum simId, VappSatMainScrn *scrn)
{
    switch (simId)
    {
        case MMI_SIM1:
            m_satMainScrn[VAPP_SAT_SNAP_SCRN_SIM1] = scrn;
            break;

    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            m_satMainScrn[VAPP_SAT_SNAP_SCRN_SIM2] = scrn;
            break;

    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            m_satMainScrn[VAPP_SAT_SNAP_SCRN_SIM3] = scrn;
            break;

    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            m_satMainScrn[VAPP_SAT_SNAP_SCRN_SIM4] = scrn;
            break;

    #endif
    #endif
    #endif /* MMI_MAX_SIM_NUM >= 2 */

        default:
            VFX_ASSERT(0);
            break;
    }
}


VappSatMainScrn *VappSatMgr::getSnapScrn(mmi_sim_enum simId)
{
    for (VfxU8 i = 1; i <= MMI_SIM_TOTAL; i++)
    {
        if (m_satMainScrn[i] != NULL && m_satMainScrn[i]->getScrnSimId() == simId)
        {
            return m_satMainScrn[i];
        }
    }

    return NULL;
}


void VappSatMgr::setMainMenuItemIndex(mmi_sim_enum simiId, VfxS32 index)
{
    m_menuItemIndex[simId2Index(simiId)] = index;
}


VfxS32 VappSatMgr::getMainMenuItemIndex(mmi_sim_enum simiId)
{
    return  m_menuItemIndex[simId2Index(simiId)];
}


VfxU32 VappSatMgr::simId2Index(mmi_sim_enum simId)
{
    return mmi_frm_sim_to_index(simId);
}


/***************************************************************************** 
 * Class VappSatApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSatApp", VappSatApp, VfxApp);

VappSatApp::VappSatApp()
 //   m_endEvt(VFX_TRUE)
{
	popupInfo = NULL;
}


void VappSatApp::onInit(void)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_APP_ONINIT);

    VfxApp::onInit();
    onRegIndHdlr();
}


void VappSatApp::onDeinit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_APP_ONDEINIT);
    srv_sat_session_reset();

    onDeRegIndHdlr();
    VfxApp::onDeinit();
}


void VappSatApp::onRun(void* args, VfxU32 argSize)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_APP_ONRUN);

    VfxApp::onRun(args, argSize);

    VappSatParam *param = (VappSatParam *)args;

    // User launch app.
   // if (param->act == VAPP_SAT_USER_ACT)
    //{
     //   m_endEvt = VFX_FALSE;
    //}
#ifndef __SAT_LOWCOST_UI_DISABLE__
    if (param->cmdType == SRV_SAT_CMD_LANGUAGE_NOTIFICATION)
    {
        srv_sat_proactive_sim_struct *cmdInfo = (srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(param->simId);
        //srv_sat_language_notification_struct *language = (srv_sat_language_notification_struct *)(&cmdInfo->cmd_data);
        languageNotification(cmdInfo);
    }
    else
#endif
    {

        showScreen(param);
    }
}


VfxBool VappSatApp::showScreen(const VappSatParam *param)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_APP_SHOWSCREEN, param->act, param->simId, param->cmdType);

    VfxBool ret = VFX_FALSE;
    VappSatMainScrn *scrn;

    if (param->act == VAPP_SAT_USER_ACT)
    {
        scrn = VFX_OBJ_GET_INSTANCE(VappSatMgr)->getMainScrn();
        if (scrn == NULL)
        {
            VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_APP_SHOWSCREEN_NEW);

            VFX_OBJ_CREATE_EX(scrn, VappSatMainScrn, this, (param->act, param->simId, param->cmdType));
            VFX_ASSERT(scrn != NULL);
            VFX_OBJ_GET_INSTANCE(VappSatMgr)->setMainScrn(scrn);

            ret = VFX_TRUE;
            scrn->show();
        }
    }
    else
    {
        scrn = VFX_OBJ_GET_INSTANCE(VappSatMgr)->getSnapScrn(param->simId);
        if (scrn == NULL)
        {
            VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_APP_SHOWSCREEN_NEW);

		#if  0
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
            {
                VFX_OBJ_CREATE_EX(scrn, VappSatMainScrn, this, (param->act, param->simId, param->cmdType));
                VFX_ASSERT(scrn != NULL);
                VFX_OBJ_GET_INSTANCE(VappSatMgr)->setSnapScrn(param->simId, scrn);
                
                ret = VFX_TRUE;
                scrn->show();
            }
        }
    }

    return ret;
}


VfxAppCloseAnswerEnum VappSatApp::onProcessClose(VfxAppCloseOption options)
{
    VfxAppCloseAnswerEnum ret = VFX_APP_CLOSE_ANSWER_YES;

    if ((options & VFX_APP_CLOSE_OPTION_NO_FLAG) && !checkBeforeClose())
    {
        ret = VFX_APP_CLOSE_ANSWER_NO;
    }

    return ret;
}


VfxBool VappSatApp::checkBeforeClose()
{
    VfxBool ret = VFX_TRUE;
    VappSatMainScrn *scrn;

    for (VfxU8 i = 0; i < VAPP_SAT_SCRN_END; i++)
    {
        scrn = VFX_OBJ_GET_INSTANCE(VappSatMgr)->getScrn((VappSatScreenIdEnum)i);
        if (scrn)
        {
            if (scrn->getScrnCmdType() == SRV_SAT_CMD_SEND_SMS ||
                scrn->getScrnCmdType() == SRV_SAT_CMD_SEND_SS ||
                scrn->getScrnCmdType() == SRV_SAT_CMD_SEND_SS_RETURN_RESULT ||
                scrn->getScrnCmdType() == SRV_SAT_CMD_SEND_USSD ||
    #ifdef __SATCB__
                scrn->getScrnCmdType() == SRV_SAT_CMD_RUN_AT_COMMAND||
	#endif
                scrn->getScrnCmdType() == SRV_SAT_CMD_SEND_USSD_RETURN_RESULT )
				
            {
                ret = VFX_FALSE;
                break;
            }
        }
    }

    return ret;
}


mmi_ret VappSatApp::onRecvInd(mmi_event_struct *evt)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_APP_ONRECVIND, evt->evt_id);

    VappSatApp *app = (VappSatApp *)evt->user_data;

    return app->onProc(evt);
}


mmi_ret VappSatApp::onProc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_OK;

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_APP_ONPROC, evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SAT_PROACTIVE_SIM:
        {
           /* if (m_endEvt)
            {
                m_endEvt = VFX_FALSE;

                ret =  MMI_RET_DONT_CARE;
                break;
            }*/

            srv_sat_proactive_sim_event_struct *event = (srv_sat_proactive_sim_event_struct *)evt;
            srv_sat_proactive_sim_struct *cmd_info = (srv_sat_proactive_sim_struct *)event->proactive_sim;

            if (cmd_info->cmd_type == SRV_SAT_CMD_SETUP_MENU || cmd_info->cmd_type == SRV_SAT_CMD_SETUP_IDLE_MODE_TEXT)
            {
                break;
            }

            VappSatParam param;
            param.act       = VAPP_SAT_SIM_ACT;
            param.simId     = cmd_info->sim_id;
            param.cmdType   = cmd_info->cmd_type;
#ifndef __SAT_LOWCOST_UI_DISABLE__
            if (cmd_info->cmd_type == SRV_SAT_CMD_LANGUAGE_NOTIFICATION)
            {
                //srv_sat_language_notification_struct *language = (srv_sat_language_notification_struct *)(&cmd_info->cmd_data);
                languageNotification(cmd_info);

                ret =  MMI_RET_DONT_CARE;
                break;
            }
#endif
			if(cmd_info->cmd_type == SRV_SAT_CMD_REFRESH)
			{
				simRefreshProcess(cmd_info);
				ret = MMI_RET_DONT_CARE;
				break;
			}

            if (showScreen(&param))
            {
                ret = MMI_RET_DONT_CARE;
            }

            break;
        }

       // case EVT_ID_SRV_SAT_SETUP_MENU:
       // case EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY:
        //case EVT_ID_SRV_SAT_SIM_REFRESH:
        case EVT_ID_SRV_SAT_SESSION_END:
			//VFX_OBJ_CLOSE(popupInfo);
			//if(popupInfo)
			//{
			//	popupInfo->exit(VFX_TRUE);
			//}
        default:
            break;
    }

    return ret;
}


mmi_ret VappSatApp::onRecvIdleInd(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


void VappSatApp::onRegIndHdlr()
{
    mmi_frm_cb_reg_event(EVT_ID_SRV_SAT_PROACTIVE_SIM, &VappSatApp::onRecvInd, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SAT_SESSION_END, &VappSatApp::onRecvInd, this);
}


void VappSatApp::onDeRegIndHdlr()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SAT_PROACTIVE_SIM, &VappSatApp::onRecvInd, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SAT_SESSION_END, &VappSatApp::onRecvInd, this);
}

#ifndef __SAT_LOWCOST_UI_DISABLE__
//void VappSatApp::languageNotification(srv_sat_proactive_sim_struct *language)
void VappSatApp::languageNotification(srv_sat_proactive_sim_struct *cmd_info)
{
    srv_sat_language_notification_struct *language = (srv_sat_language_notification_struct *)(&cmd_info->cmd_data);
#ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    U8 lang_sel = language->lang[0];
    if (language->is_specified)
    {
    
        lang_sel = (U8)GetLanguageIndexByLangCode((CHAR *)language->lang);
    }

    if (lang_sel == srv_setting_get_language())
#else
	U8 *lang_sel;
	U8 langSSC[SSC_SIZE];
	srv_setting_get_language(langSSC);
	if(language->is_specified)
	{
		mmi_li_get_ssc_by_lcc(language->lang, &lang_sel);
	}
	else
	{	
		lang_sel = langSSC;
	}

	if(strcmp((CHAR *)lang_sel, (CHAR *)langSSC))	
#endif
    {
        srv_sat_terminal_response_language_notification(
            cmd_info->sim_id,
            SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);

        if (!VFX_OBJ_GET_INSTANCE(VappSatMgr)->getMainScrn())
        {
            exit();
        }
        return;
    }

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    vapp_nmgr_global_popup_show_confirm_one_button_id(
        MMI_SCENARIO_ID_DEFAULT,
        VCP_POPUP_TYPE_WARNING,
        STR_ID_VAPP_SAT_LANGUAGE_RESET,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_WARNING,
        &VappSatApp::onLangNotifyBtnTapped,
        cmd_info);
}


void VappSatApp::onLangNotifyBtnTapped(VfxId id, void *user_data)
{
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
#else
    mmi_event_struct evt;
    MMI_FRM_INIT_EVENT(&evt, 0);
    mmi_frm_post_event(&evt, &VappSatApp::langAsyncSwitch, user_data);
#endif
}


mmi_ret VappSatApp::langAsyncSwitch(mmi_event_struct *evt)
{
    srv_sat_proactive_sim_struct *cmd_info = (srv_sat_proactive_sim_struct *)evt->user_data;

    srv_sat_language_notification_struct *language = (srv_sat_language_notification_struct *)(&cmd_info->cmd_data);
#ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    U8 lang_sel = language->lang[0];
    if (language->is_specified)
    {
	
        lang_sel = (U8)GetLanguageIndexByLangCode((CHAR *)language->lang);
    }
	vapp_setting_language_hdl_for_sat(lang_sel);

#else
	U8 *lang_sel;
	U8 langSSC[SSC_SIZE];
	srv_setting_get_language(langSSC);
	if(language->is_specified)
	{
		mmi_li_get_ssc_by_lcc(language->lang, &lang_sel);
	}
	else
	{
		lang_sel = langSSC;
		//strcpy((CHAR *)lang_sel, (CHAR *)langSSC);
	}
    vapp_setting_language_hdl_for_sat(lang_sel);
#endif


    //vapp_setting_language_hdl(lang_sel, VAPP_SAT);
    

    mmi_event_struct event;
    MMI_FRM_INIT_EVENT(&event, 0);
    mmi_frm_post_event(&event, &VappSatApp::langResponse, cmd_info);

    return MMI_RET_OK;
}


mmi_ret VappSatApp::langResponse(mmi_event_struct *evt)
{
    srv_sat_proactive_sim_struct *cmd_info = (srv_sat_proactive_sim_struct *)evt->user_data;

    srv_sat_terminal_response_language_notification(
        cmd_info->sim_id,
        SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY);

    return MMI_RET_OK;
}

#endif
void VappSatApp::simRefreshProcess(srv_sat_proactive_sim_struct *cmd_info)
{
    VfxWString string;
    //srv_sat_proactive_sim_struct *cmdInfo = (srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(m_simId);

#if (MMI_MAX_SIM_NUM >= 2)
    switch (cmd_info->sim_id)
    {
        case MMI_SIM1:
			string.loadFromRes(STR_GLOBAL_SIM_1);
            break;

        case MMI_SIM2:
			string.loadFromRes(STR_GLOBAL_SIM_2);
            break;
#if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
			string.loadFromRes(STR_GLOBAL_SIM_3);
            break;
#if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
			string.loadFromRes(STR_GLOBAL_SIM_4);
            break;
#endif
#endif
        default:
			string.loadFromRes(STR_GLOBAL_SIM);
            break;
    }
#else

	string.loadFromRes(STR_GLOBAL_SIM);
#endif

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    srv_sat_refresh_struct *refresh = (srv_sat_refresh_struct *)(&cmd_info->cmd_data);
    if (refresh->refresh_type == SRV_SAT_REFRESH_RESET)
    {
    #ifdef __SIM_RESET_BY_SIM__
        string += VFX_WSTR_RES(STR_ID_VAPP_SAT_SIM_REFRESH);
        showPopup(string, cmd_info->sim_id);
    #else
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
        {
            string += VFX_WSTR_RES(STR_ID_VAPP_SAT_SIM_RESET);
            showResetPopup(string, cmd_info->sim_id);
        }
    #endif /*__SIM_RESET_BY_SIM__ */
    }
    else
    {
        string += VFX_WSTR_RES(STR_ID_VAPP_SAT_SIM_REFRESH);
        showPopup(string, cmd_info->sim_id);
    }
}


void VappSatApp::showPopup(VfxWString string , mmi_sim_enum simId)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_POPUP_SCRN_POPUP);
	VappSatMainScrn *scrn  = NULL;
	scrn = VFX_OBJ_GET_INSTANCE(VappSatMgr)->getSnapScrn(simId);
	if(scrn == NULL)
	{
		scrn = VFX_OBJ_GET_INSTANCE(VappSatMgr)->getMainScrn();

	}
	VFX_ASSERT(scrn != NULL);
    //VcpIndicatorPopup *popupInfo;
    VFX_OBJ_CREATE(popupInfo, VcpIndicatorPopup, scrn);

    popupInfo->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    popupInfo->setText(string);
    popupInfo->setAutoDestory(VFX_TRUE);
    popupInfo->show(VFX_TRUE);
}


void VappSatApp::showResetPopup(VfxWString string, mmi_sim_enum simId)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_POPUP_SCRN_POPUP);
	VappSatMainScrn *scrn  = NULL;
	scrn = VFX_OBJ_GET_INSTANCE(VappSatMgr)->getSnapScrn(simId);
	if(scrn == NULL)
	{
		scrn = VFX_OBJ_GET_INSTANCE(VappSatMgr)->getMainScrn();

	}
	VFX_ASSERT(scrn != NULL);

    VcpConfirmPopup *resetPopup;
    VFX_OBJ_CREATE(resetPopup, VcpConfirmPopup, scrn);

    resetPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    resetPopup->setText(string);
    resetPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    resetPopup->setAutoDestory(VFX_TRUE);
    resetPopup->show(VFX_TRUE);

    resetPopup->m_signalButtonClicked.connect(this, &VappSatApp::onResetPhone);
}


void VappSatApp::onResetPhone(VfxObject* obj, VfxId id)
{
	VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_POPUP_SCRN_ONRESETPHONE);
    srv_alm_normal_reset(MMI_TRUE, 3);
}





/***************************************************************************** 
 * Class VappSatMainScrn
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSatMainScrn", VappSatMainScrn, VfxMainScr);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VappSatMainScrn::VappSatMainScrn(VappSatLaunchModeEnum act, mmi_sim_enum simId, srv_sat_cmd_enum cmdType) :
    //m_act(act),
    m_simId(simId),
    m_cmdType(cmdType),
    m_page(NULL)
{
}


void VappSatMainScrn::onInit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MAIN_SCRN_ONINIT);

    VfxMainScr::onInit();
	m_rflag = 0;

    onRegIndHdlr();
}


void VappSatMainScrn::onDeinit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MAIN_SCRN_ONDEINIT);

    onDeRegIndHdlr();
	if (!m_rflag)
    	{
			onResponse();    		
    	}
    if (getScrnCmdType() == SRV_SAT_CMD_SETUP_MENU)
    {
        VFX_OBJ_GET_INSTANCE(VappSatMgr)->setMainScrn(NULL);
        VFX_OBJ_GET_INSTANCE(VappSatMgr)->setMainMenuItemIndex(getScrnSimId(), -1);
    }
    else
    {
        VFX_OBJ_GET_INSTANCE(VappSatMgr)->setSnapScrn(getScrnSimId(), NULL);
    }
	m_rflag = 0;

    VfxMainScr::onDeinit();
}

void VappSatMainScrn::onResponse()
{
	srv_sat_terminal_res_enum res_enum = SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER;
	switch(getScrnCmdType())
	{
		case SRV_SAT_CMD_SELECT_ITEM:
			{
				srv_sat_terminal_response_select_item(
						m_simId,
						res_enum,
						NULL);
				break;
			}
		case SRV_SAT_CMD_DISPLAY_TEXT:
			{
				 srv_sat_terminal_response_display_text(
					   m_simId,
					   res_enum,
					   SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
				 break;
			}
		case SRV_SAT_CMD_GET_INKEY:
			{
				 srv_sat_terminal_response_get_inkey(
				      m_simId,
				      res_enum,
					  MMI_FALSE,
					  NULL);
				 break;
			}
		case SRV_SAT_CMD_GET_INPUT:
			{
				  srv_sat_terminal_response_get_input(
					   m_simId,
				       res_enum,
					   NULL);
				  break;
			}
		case SRV_SAT_CMD_SETUP_CALL:
			{
				  srv_sat_terminal_response_setup_call_stage2(
				      m_simId,
				      res_enum,
				      SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
				  break;
			}
	}

}

mmi_ret VappSatMainScrn::onRecvSatInd(mmi_event_struct *evt)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MAIN_SCRN_ONRECVIND, evt->evt_id);

    VappSatMainScrn *scrn = (VappSatMainScrn *)evt->user_data;
    scrn->processProc(evt);

    return MMI_RET_OK;
}


mmi_ret VappSatMainScrn::onProc(mmi_event_struct *evt)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MAIN_SCRN_ONPROC, evt->evt_id);

    if (getPageCount() <= 0 && evt->evt_id == EVT_ID_SRV_SAT_PROACTIVE_SIM)
    {
        srv_sat_proactive_sim_event_struct *event = (srv_sat_proactive_sim_event_struct *)evt;

        //if (!isPopup(event->proactive_sim->cmd_type) && event->proactive_sim->sim_id == getScrnSimId())
        if( event->proactive_sim->sim_id == getScrnSimId())
        {
            //setScrnCmdType(event->proactive_sim->cmd_type);
            m_cmdType = event->proactive_sim->cmd_type;
            showPage();
        }
    }

    return VfxMainScr::onProc(evt);
}


void VappSatMainScrn::onEnter(VfxBool isBackward)
{
    if (getScrnCmdType() == SRV_SAT_CMD_SETUP_MENU)
    {
        VFX_OBJ_GET_INSTANCE(VappSatMgr)->setMainMenuItemIndex(getScrnSimId(), -1);
    }
}


void VappSatMainScrn::onExit(VfxBool isBackward)
{
    if (getScrnCmdType() == SRV_SAT_CMD_DISPLAY_TEXT)
    {
   	if(m_page.isValid())
   		{
      VappSatViewPage *view = VFX_OBJ_DYNAMIC_CAST(m_page.get(), VappSatViewPage);
        if (view->getIsSent())
        {
            view->exit();
        }
    }
}
}


void VappSatMainScrn::on1stReady()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MAIN_SCRN_ON1STREADY);

    VfxMainScr::on1stReady();

    if (!m_page.get())
    {
        showPage();
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __POPUP_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

S32 VappSatMainScrn::getSatReadyNum()
{
    S32 num = 0;
    U32 i;

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (srv_sat_is_menu_present((mmi_sim_enum)(1 << i)))
        {
            num++;
        }
    }

    return num;
}


mmi_sim_enum VappSatMainScrn::callTypeToSimId(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(call_type & SRV_UCM_SIM1_CALL_TYPE_ALL)
    {
        sim_id = MMI_SIM1;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if(call_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
    {
        sim_id = MMI_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if(call_type & SRV_UCM_SIM3_CALL_TYPE_ALL)
    {
        sim_id = MMI_SIM3;
    }
#endif /* MMI_MAX_SIM_NUM >= 3 */
#if (MMI_MAX_SIM_NUM >= 4)
    else if(call_type & SRV_UCM_SIM4_CALL_TYPE_ALL)
    {
        sim_id = MMI_SIM4;
    }
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 2 */
    else
    {
        sim_id = MMI_SIM_NONE;
    }

    VFX_ASSERT(sim_id);

    return sim_id;
}


mmi_ret VappSatMainScrn::onRecvUcmInd(mmi_event_struct *evt)
{
    srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *)evt;    
    switch (ind->ind_type)
    {
        case SRV_UCM_OUTGOING_CALL_IND:
        {
            srv_ucm_outgoing_call_ind_struct *call_outgoing = (srv_ucm_outgoing_call_ind_struct *)ind->ptr;
            mmi_sim_enum simId = MMI_SIM_NONE;

            if (call_outgoing->module_id == SRV_UCM_MODULE_ORIGIN_SAT)
            {
                simId = callTypeToSimId(call_outgoing->uid_info.call_type);
                VappSatMainScrn *scrn  =  VFX_OBJ_GET_INSTANCE(VappSatMgr)->getSnapScrn(simId);

                if (scrn->getScrnSimId() == simId && scrn->getScrnCmdType() == SRV_SAT_CMD_SETUP_CALL)
                {
                    scrn->popPage();
                }
            }

            break;
        }

        case SRV_UCM_RELEASE_IND:
        {
            srv_ucm_release_ind_struct *call_release = (srv_ucm_release_ind_struct *)ind->ptr;
            mmi_sim_enum simId = MMI_SIM_NONE;

            if (call_release->module_id == SRV_UCM_MODULE_ORIGIN_SAT)
            {
                simId = callTypeToSimId(call_release->uid_info.call_type);

                srv_sat_setup_call_abort_req(simId);
	#ifndef	__SAT_DISABLE_ICON_SUPPORT__
                vapp_sat_free_calling_icon_path(simId);               
	#endif
            }

            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


void VappSatMainScrn::showPage()
{
	m_rflag = 1;

    if (getScrnSimId() == MMI_SIM_NONE)
    {
        return;
    }

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MAIN_SCRN_SHOWPAGE, getScrnSimId(), getScrnCmdType());

    if (m_page.get() && getScrnSimId() == ((VappSatBasePage *)m_page.get())->getSimId() && getScrnCmdType() != SRV_SAT_CMD_SETUP_MENU)
    {
        m_page = NULL;
    }

	if(((VappSatApp *)this->getApp())->popupInfo)
	{
		((VappSatApp *)this->getApp())->popupInfo->exit(VFX_TRUE);
		VFX_OBJ_CLOSE(((VappSatApp *)this->getApp())->popupInfo);
	}

    switch (getScrnCmdType())
    {
        case SRV_SAT_CMD_SETUP_MENU:
        {
        #if (MMI_MAX_SIM_NUM == 1)
            VFX_OBJ_CREATE_EX(m_page, VappSatMenuPage, this, (getScrnSimId(), (srv_sat_setup_menu_struct *)srv_sat_get_setup_menu(m_simId)));
        #else

            if (getSatReadyNum() <= 1)
            {
                VFX_OBJ_CREATE_EX(m_page, VappSatMenuPage, this, (getScrnSimId(), (srv_sat_setup_menu_struct *)srv_sat_get_setup_menu(m_simId)));
            }
            else
            {
                VFX_OBJ_CREATE(m_page, VappSatMainMenuCtrlPage, this);
            }
        #endif /* MMI_MAX_SIM_NUM == 1 */

            break;
        }

        case SRV_SAT_CMD_SELECT_ITEM:
        {
            VFX_OBJ_CREATE_EX(m_page, VappSatMenuPage, this, ((srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(m_simId)));
            break;
        }

        case  SRV_SAT_CMD_GET_INKEY:
        {
            srv_sat_get_inkey_struct *get_inkey = (srv_sat_get_inkey_struct *)(&srv_sat_get_last_proactive_sim(getScrnSimId())->cmd_data);
            if (get_inkey->input_type == SRV_SAT_INPUT_YES_NO)
            {
                VFX_OBJ_CREATE_EX(m_page, VappSatViewPage, this, ((srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(m_simId)));
            }
            else
            {
                VFX_OBJ_CREATE_EX(m_page, VappSatEditorPage, this, ((srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(m_simId)));
            }

            break;
        }

        case  SRV_SAT_CMD_GET_INPUT:
        {
            VFX_OBJ_CREATE_EX(m_page, VappSatEditorPage, this, ((srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(getScrnSimId())));

            break;
        }

        case SRV_SAT_CMD_DISPLAY_TEXT:
        case SRV_SAT_CMD_SETUP_CALL:
        case SRV_SAT_CMD_PLAY_TONE:
        case SRV_SAT_CMD_SEND_DTMF:

    #ifdef BROWSER_SUPPORT
	#ifdef __SATCC__
        case SRV_SAT_CMD_LAUNCH_BROWSER:
	#endif
    #endif /* BROWSER_SUPPORT */

    #ifdef __SATCE__
        case SRV_SAT_CMD_OPEN_CHANNEL:
        case SRV_SAT_CMD_CLOSE_CHANNEL:
        case SRV_SAT_CMD_SEND_DATA:
        case SRV_SAT_CMD_RECEIVE_DATA:
    #endif /*__SATCE__*/

    #ifndef __POPUP_SUPPORT__
	#ifdef __SATCB__
        case SRV_SAT_CMD_RUN_AT_COMMAND:
	#endif //__SATCB__
    #endif /* __POPUP_SUPPORT__ */

        case SRV_SAT_CMD_SEND_SMS:
        case SRV_SAT_CMD_SEND_SS:
        case SRV_SAT_CMD_SEND_SS_RETURN_RESULT:
        case SRV_SAT_CMD_SEND_USSD:
        case SRV_SAT_CMD_SEND_USSD_RETURN_RESULT:
		case SRV_SAT_CMD_REFRESH:
        {
            VFX_OBJ_CREATE_EX(m_page, VappSatViewPage, this, ((srv_sat_proactive_sim_struct *)srv_sat_get_last_proactive_sim(getScrnSimId())));

            break;
        }

    #ifndef __POPUP_SUPPORT__
        case SRV_SAT_CMD_SETUP_IDLE_MODE_TEXT:
        case SRV_SAT_CMD_PROVIDE_LOCAL_INFORMATION:
        {
            return;
        }
    #endif /* __POPUP_SUPPORT__ */

        default:
            break;
    }


    VFX_ASSERT(m_page.get() != NULL);
    pushPage(VFX_ID_NULL, m_page.get());
}


mmi_sim_enum VappSatMainScrn::getScrnSimId() const
{
    return m_simId;
}


srv_sat_cmd_enum VappSatMainScrn::getScrnCmdType() const
{
    return m_cmdType;
}


void VappSatMainScrn::setScrnCmdType(srv_sat_cmd_enum cmdType)
{
    m_cmdType = cmdType;
}


void VappSatMainScrn::onRegIndHdlr()
{
    mmi_frm_cb_reg_event(EVT_ID_SRV_SAT_PROACTIVE_SIM, &VappSatMainScrn::onRecvSatInd, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_SAT_SESSION_END, &VappSatMainScrn::onRecvSatInd, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_INDICATION, &VappSatMainScrn::onRecvUcmInd, this);
}


void VappSatMainScrn::onDeRegIndHdlr()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SAT_PROACTIVE_SIM, &VappSatMainScrn::onRecvSatInd, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SAT_SESSION_END, &VappSatMainScrn::onRecvSatInd, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_INDICATION, &VappSatMainScrn::onRecvUcmInd, this);
}


/***************************************************************************** 
 * Class VappSatPopupScrn
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSatPopupScrn", VappSatPopupScrn, VfxAppScr);
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
#if (MMI_MAX_SIM_NUM >= 2)
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
#else
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __SIM_RESET_BY_SIM__
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /*__SIM_RESET_BY_SIM__ */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
