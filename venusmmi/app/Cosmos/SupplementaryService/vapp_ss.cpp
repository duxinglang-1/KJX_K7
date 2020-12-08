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
 *  vapp_ss.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  		The event coming order:
 *				EVT_ID_SRV_UCM_INTERCEPT_QUERY
 *				EVT_ID_SRV_SS_ACT_NOTIFY: start
 *				EVT_ID_SRV_SS_INDICATION
 *				EVT_ID_SRV_SS_ACT_NOTIFY: end
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

extern "C" 
{

#include "GlobalResDef.h"
#include "SsCore.h"
#include "SsSrvGprot.h" /* srv_ss_act_req */
#include "Mmi_rp_srv_ss_def.h" /* EVT ID */
#include "Mmi_cb_mgr_gprot.h" /* mmi_frm_cb_reg_event */
#include "UcmSrvGprot.h" /* srv_ucm_intercept_query_evt_struct */
#include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_get_num_of_inserted */
#include "MMI_common_app_trc.h"
#include "MMI_rp_srv_nmgr_def.h"
#include "wgui_categories_list.h"
}

#include "Vapp_nmgr_gprot.h"
#include "vcp_include.h"
#include "vapp_screen_lock_gprot.h"

#include "mmi_rp_vapp_ss_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_app_launcher.h"
#include "vfx_renderer.h"

#include "Vcp_global_popup.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_text_editor.h"

#include "Vapp_sim_setting_gprot.h "
#include "vapp_ss.h"
#include "vapp_ncenter.h"
#ifdef __VAPP_SS_SHOW_IN_NCENTER__
#include "vsrv_ncenter.h"
#endif // __VAPP_SS_SHOW_IN_NCENTER__
/***************************************************************************** 
 * Define
 *****************************************************************************/
//#define __SS_USSR_UT__

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
	VfxId launch_id;

	mmi_sim_enum sim;
	vapp_ss_type_enum type;
	union
	{
		VfxWChar buffer[SRV_SS_MAX_LENGTH + 1];
	}u;
	
}vapp_ss_launch_param_struct;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" mmi_ret vapp_ss_intercept(mmi_event_struct *para)
{
	return VappSsApp::processIntercept(para);
}

extern "C" mmi_ret vapp_ss_hdlr_act_notify(mmi_event_struct *para)
{
    srv_ss_act_notify_evt_struct *evt = (srv_ss_act_notify_evt_struct*)para;

    switch (evt->type)
    {
        case SRV_SS_ACT_NOTIFY_START:
        {
            srv_ss_act_req_struct *req = (srv_ss_act_req_struct*)(evt->info);
            if (req->source != SRV_SS_SRC_COMMON)
            {
                /* display ss screen by other app */
                return MMI_RET_OK;
            }
            break;
        }

        case SRV_SS_ACT_NOTIFY_END:
        {
            srv_ss_rsp_struct *rsp = (srv_ss_rsp_struct*)(evt->info);
            if (rsp->source != SRV_SS_SRC_COMMON)
            {
                /* display ss screen by other app */
                return MMI_RET_OK;
            }
            break;
        }
		default:
			break;
    }

	VappSsNCell *ncell = VFX_OBJ_GET_INSTANCE(VappSsNCell);
	ncell->onActNotify(para);
	
    return MMI_RET_OK;
}


extern "C" mmi_ret vapp_ss_hdlr_ind(mmi_event_struct *para)
{
    srv_ss_ind_evt_struct *evt = (srv_ss_ind_evt_struct*)para;

    if (evt->source != SRV_SS_SRC_COMMON)
    {
        /* display ss screen by other app */
        return MMI_RET_OK;
    }

	VappSsNCell *ncell = VFX_OBJ_GET_INSTANCE(VappSsNCell);
	ncell->onIndication(para);

    return MMI_RET_OK;
}

#ifdef __SS_USSR_UT__
extern "C" void vapp_ss_hdlr_ut_ind(void)
{
	srv_ss_ussr_ind_struct ussr;

	ussr.direction = SRV_SS_DIR_MO;
	ussr.string[0] = 'A';
	ussr.string[0] = 0;
	ussr.string[0] = 0;
	ussr.string[0] = 0;
	
	srv_ss_ind_evt_struct ind;
	ind.sim = MMI_SIM1;
	ind.source = SRV_SS_SRC_COMMON;
	ind.data = &ussr;
	
	srv_ss_ind_evt_struct evt;
	evt.sim = MMI_SIM1;
	evt.source = SRV_SS_SRC_COMMON;
	evt.ind_type = SRV_SS_IND_USSR;
	evt.data = &ind;
	
	vapp_ss_hdlr_ind((mmi_event_struct *)&evt);
}
#endif /* __SS_USSR_UT__ */

/***************************************************************************** 
 * Class VappSsNCell Implementation
 *****************************************************************************/

// Memory pool
static VfxU8 g_ssNCellMemPool[3 * 1024];
static VfxContext *s_ssCcontext = NULL;

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappSsNCell);
void VappSsNCell::onInit()
{
    if (NULL == s_ssCcontext)
    {
        VFX_OBJ_CREATE(s_ssCcontext, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
        s_ssCcontext->assignPool(g_ssNCellMemPool, sizeof(g_ssNCellMemPool)/sizeof(VfxU8));
    }
	VfxObject::onInit();

	for (VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
		m_msg[i].sim = mmi_frm_index_to_sim(i);
		m_msg[i].type = SS_TYPE_UNKNOWN;
		m_msg[i].timerObjHandle = NULL;
		m_msg[i].msg.setEmpty();
    #ifdef __VAPP_SS_SHOW_IN_NCENTER__
        m_alertHandle[i] = 0;
    #endif
	}
}

vrt_allocator_handle VappSsNCell::getAllocator()
{
    return s_ssCcontext->getAllocator();
}

VfxBool VappSsNCell::notifyApp(vapp_ss_msg_struct *msg)
{
    VappSsApp *app = getApp(msg->sim);

    if (app != NULL)
    {
    	app->onEvent(msg);
		
        if (!srv_ucm_query_call_count(
                    (srv_ucm_call_state_enum)(SRV_UCM_INCOMING_STATE|SRV_UCM_OUTGOING_STATE), 
                    SRV_UCM_CALL_TYPE_ALL, NULL) &&
                !app->isActive() &&
                !app->isAborting())
        {
        	VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
            if (NCenter)
            {
                NCenter->leave();
            }
			app->setActive();
        }
        
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappSsNCell::entryApp(vapp_ss_msg_struct *msg)
{
    if (!notifyApp(msg))
    {
    	vapp_ss_launch_param_struct param;

		param.launch_id = VappSsApp::LAUNCH_ID_MSG;
		param.sim = msg->sim;
		param.type = msg->type;
		
		vfx_sys_wcsncpy(param.u.buffer, msg->msg.getBuf(), msg->msg.getLength());
		
        VfxAppLauncher::launch( 
            VappSsApp::getAppId(msg->sim),
            VFX_OBJ_CLASS_INFO(VappSsApp),
            GRP_ID_ROOT,
            &param,
            sizeof(vapp_ss_launch_param_struct));
    }   
}

void VappSsNCell::onActNotify(mmi_event_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_act_notify_evt_struct *evt = (srv_ss_act_notify_evt_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_SS_ON_ACT, evt->type, evt->act_op);
    if (evt->act_op == SRV_SS_ACT_ABORT)
    {
    	/*
        if (m_timer)
        {
            m_timer->stop();
        }*/
        return;
    }

	vapp_ss_msg_struct *msg;
    switch (evt->type)
    {
        case SRV_SS_ACT_NOTIFY_START:
        {
			srv_ss_act_req_struct *req = (srv_ss_act_req_struct*)(evt->info);
			msg = getMsg(req->sim);

			VfxTimer *timer = (VfxTimer *)VfxObject::handleToObject(msg->timerObjHandle);
            if (timer != NULL)
            {
                timer->stop();
            }

			VfxS32 callCnt = srv_ucm_query_call_count(
								(srv_ucm_call_state_enum)(SRV_UCM_INCOMING_STATE|SRV_UCM_OUTGOING_STATE), 
								SRV_UCM_CALL_TYPE_ALL, 
								NULL);
			
            if (callCnt == 0)
            {
    			VappSsApp *app = getApp(req->sim);
				
				if ((app != NULL) && (app->m_msg.type == SS_TYPE_REQUESTING))
				{
					return;
				}		
				
                msg->sim = req->sim;
                msg->type = SS_TYPE_REQUESTING;
				//Just show popup, don't need to send anything.
                msg->msg.setEmpty();
				
                entryApp(msg);
            }
            break;
        }

        case SRV_SS_ACT_NOTIFY_END:
        {
            srv_ss_rsp_struct *rsp = (srv_ss_rsp_struct*)(evt->info);
            srv_ss_ussd_rsp_struct *ussd_rsp = (srv_ss_ussd_rsp_struct*)(rsp->data);

            if ((rsp->opcode == SRV_SS_ACT_USSD) &&
                (rsp->result == SRV_SS_RESULT_OK) &&
                (!ussd_rsp || !(ussd_rsp->end_of_session)))
            {
                /* don't display the result, wait for the following ss msg (ussn / ussr...) */
                return;
            }

            mmi_ss_result_struct res;
            mmi_ss_derive_result(rsp, &res);

			msg = getMsg(rsp->sim);
            msg->sim = rsp->sim;
            msg->type = SS_TYPE_USSD;
            if (mmi_ucs2strlen((CHAR *)res.string))
            {
                msg->msg.loadFromMem((const VfxWChar *)res.string);
            }
            else if (res.result == SRV_SS_RESULT_OK)
            {
                msg->msg.loadFromRes(STR_GLOBAL_DONE);
            }
            else
            {
                msg->msg.loadFromRes(STR_GLOBAL_ERROR);
            }

            if (!notifyApp(msg))
            {
				showNotify(msg);
            }
            break;
        }
 
        default:
            break;
    }
}

void VappSsNCell::onIndication(mmi_event_struct* info)
{
    srv_ss_ind_evt_struct *evt = (srv_ss_ind_evt_struct*)info;

    vapp_ss_msg_struct *msg = getMsg(evt->sim);

	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_SS_ON_CELL_IND, evt->sim, evt->ind_type);

    switch (evt->ind_type)
    {
        case SRV_SS_IND_USSR:
        {
            msg->type = SS_TYPE_USSR;

            srv_ss_ussr_ind_struct *ussr = (srv_ss_ussr_ind_struct*)(evt->data);
            msg->msg.loadFromMem(ussr->string);
			
            break;
        }

        case SRV_SS_IND_USSN:
        {
            msg->type = SS_TYPE_USSN;

            srv_ss_ussn_ind_struct *ussn = (srv_ss_ussn_ind_struct*)(evt->data);
            msg->msg.loadFromMem(ussn->string);
            break;
        }

        case SRV_SS_IND_ABORT:
        {
            msg->type = SS_TYPE_ABORT;
			VfxTimer *timer = (VfxTimer *)VfxObject::handleToObject(msg->timerObjHandle);
            if (timer != NULL)
            {
                timer->stop();
            }
            notifyApp(msg);
            break;
        }

        default:
            break;
    }


    if ((evt->ind_type == SRV_SS_IND_USSR) || (evt->ind_type == SRV_SS_IND_USSN))
    {
        if (evt->ind_type == SRV_SS_IND_USSR)
        {
        	VfxTimer *timer = (VfxTimer *)VfxObject::handleToObject(msg->timerObjHandle);
            if (timer == NULL)
            {
                VFX_OBJ_CREATE(timer, VfxTimer, this);
                timer->m_signalTick.connect(this, &VappSsNCell::onTimeOut);
				msg->timerObjHandle = timer->getObjHandle();
            }
			
            timer->setDuration(30000);
            timer->setStartDelay(30000);
            timer->start();
        }

        if (!notifyApp(msg))
        {
           showNotify(msg);
        }
    }
}

#ifdef __VAPP_SS_SHOW_IN_NCENTER__
void VappSsNCell::onIntMsg(vapp_ss_msg_struct *msg)
{	
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_SS_ON_CELL_INTMSG, msg->sim, msg->type);

	vapp_ss_msg_struct *ssMsg = getMsg(msg->sim);
	ssMsg->sim = msg->sim;
	ssMsg->type = msg->type;
	ssMsg->msg = msg->msg;
	
    if (ssMsg->type != SS_TYPE_INT_HIDE)
    {
		showNotify(ssMsg, VFX_FALSE);
    }
    else
    {
        releaseNotify(ssMsg->sim);
    }
}

void VappSsNCell::onNCenterLeave(mmi_sim_enum sim)
{
    entryApp(getMsg(sim));
    closeAlertHandle(sim);
    releaseNotify(sim);
}

void VappSsNCell::onClearAll()
{
	for (VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
	    VappSsApp *app = getApp(mmi_frm_index_to_sim(i));
		vapp_ss_msg_struct *msg = getMsg(mmi_frm_index_to_sim(i));
		
	    if ((app == NULL) && msg->type == SS_TYPE_USSR)
	    {
	        /* Never launch / update the app, abort ss */
	        srv_ss_abort_req_struct req;
			
	        req.sim = mmi_frm_index_to_sim(i);
	        req.source = SRV_SS_SRC_COMMON;
	        srv_ss_act_req(SRV_SS_ACT_ABORT, &req, NULL, NULL);
	    }
	    releaseNotify(mmi_frm_index_to_sim(i));
        closeAlertHandle(mmi_frm_index_to_sim(i));
	}

	VFX_OBJ_CLOSE_INSTANCE(VappSsNCell);
}

static mmi_ret vapp_ss_nss_proc(mmi_event_struct *evt)
{
    if (EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH == evt->evt_id)
    {
        VappSsNCell *ncell = VFX_OBJ_GET_INSTANCE(VappSsNCell);
        if (ncell) 
        {
            ncell->onNCenterLeave(*(mmi_sim_enum*)evt->user_data);
        }
    }
    return MMI_TRUE;
}
#else
static MMI_BOOL vapp_ss_notify_user(mmi_scenario_id scen_id, void *arg)
{
    vapp_ss_msg_struct *msg = (vapp_ss_msg_struct *)arg;
    VappSsNCell *ncell = VFX_OBJ_GET_INSTANCE(VappSsNCell);
    if (msg && ncell)
    {
        ncell->entryApp(msg);
    }
    return MMI_TRUE;
}
#endif // __VAPP_SS_SHOW_IN_NCENTER__

void VappSsNCell::showNotify(vapp_ss_msg_struct *msg, VfxBool isShowSimX)
{
#ifdef __VAPP_SS_SHOW_IN_NCENTER__
	// Preview in Status bar
	if (isShowSimX)
	{
    	VfxWString str;

    	if (srv_sim_ctrl_get_num_of_inserted() > 1)
    	{
    		str.loadFromRes(VappSsApp::getSimStrId(msg->sim));
    		str += VFX_WSTR(" ");
    	}

    	str += VFX_WSTR_RES(STR_ID_VAPP_SS_USSD_MSG);
    	str += VFX_WSTR(": ");
    	str += msg->msg;

        // SS_support_NSS-BEGIN
        mmi_frm_nmgr_alert_struct alert_info;
        memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));
        alert_info.app_id = VappSsApp::getAppId(msg->sim);
        alert_info.scen_id = MMI_SCENARIO_ID_SS;
        alert_info.event_type = MMI_EVENT_GENERAL_PREVIEW;
        alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
        alert_info.behavior_mask = FORCE_STATUS_BAR;
        alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
        alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
        alert_info.status_bar_para.image.id = IMG_ID_DEFAULT_PREVIEW_ICON;
        alert_info.status_bar_para.display_string = (WCHAR*)str.getBuf();
        alert_info.status_bar_icon_para.icon_id = STATUS_ICON_INVALID_ID;
        alert_info.app_proc_para.scrn_group_proc = vapp_ss_nss_proc;
        mmi_sim_enum sim_info = msg->sim;
        alert_info.app_proc_para.user_data = (void *)&sim_info;
        alert_info.app_proc_para.data_size = sizeof(sim_info);
        m_alertHandle[mmi_frm_sim_to_index(sim_info)] = mmi_frm_nmgr_alert(&alert_info);
    } // SS_support_NSS-END
    // SS_support_NCenter2.0
	createNotify(msg);
#else
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_SS, MMI_EVENT_DEFAULT, vapp_ss_notify_user, (void *)msg);
#endif // __VAPP_SS_SHOW_IN_NCENTER__
}
#ifdef __VAPP_SS_SHOW_IN_NCENTER__
void VappSsNCell::createNotify(vapp_ss_msg_struct *msg)
{
	//
	// This macro will query the existed group
	//
	VsrvNGroupSingleTitle *notiGrp;
	VSRV_NGROUP_CREATE_EX(notiGrp, VsrvNGroupSingleTitle, (VAPP_SS));
	notiGrp->setTitle(STR_ID_VAPP_SS_TITLE);
	
	VsrvNotification *notify = notiGrp->queryNotification((VsrvNotificationId)msg->sim);
	if (notify == NULL)
	{
		VsrvNotificationEvent *ssNotify;
		VSRV_NOTIFICATION_CREATE_EX(ssNotify, VsrvNotificationEvent, (VAPP_SS, (VsrvNotificationId)msg->sim));
		
		VfxWString str;
		if (srv_sim_ctrl_get_num_of_inserted() > 1)
		{
			str.loadFromRes(VappSsApp::getSimStrId(msg->sim));
			str += VFX_WSTR(" ");
		}
		
		str += VFX_WSTR_RES(STR_ID_VAPP_SS_USSD_MSG);
		ssNotify->setMainText(str);
		ssNotify->setSubText(msg->msg);

		VfxU32 objHandle = (VfxU32)getObjHandle();
		ssNotify->setIntentCallback(VappSsNCell::notifyIntentCallback, &objHandle, sizeof(VfxU32));

		notify = ssNotify;
	}
	
	notify->notify();
	
}

void VappSsNCell::releaseNotify(mmi_sim_enum sim)
{
	VSRV_NOTIFICATION_CLOSE_EX(VAPP_SS, (VsrvNotificationId)sim);
}

void VappSsNCell::notifyIntentCallback(
						VsrvNotification* noti, 
						VsrvNIntent intent, 
						void* userData, 
						VfxU32 userDataSize)
{

	VfxU32 objHandle;
	memcpy(&objHandle, userData, userDataSize);
	
	VappSsNCell *objCell = (VappSsNCell *)handleToObject((VfxObjHandle)objHandle);
	
	if (objCell != NULL)
	{
		switch (intent.type)
		{
			case VSRV_NINTENT_TYPE_CLEAR:
				objCell->onClearAll();
				break;
				
			case VSRV_NINTENT_TYPE_LAUNCH:
				objCell->onNCenterLeave((mmi_sim_enum)noti->getId());
				break;
				
			default:
				break;
		};
	}
}

void VappSsNCell::closeAlertHandle(mmi_sim_enum sim)
{
    U32 id = mmi_frm_sim_to_index(sim);
    if (0 != m_alertHandle[id])
    {
        mmi_frm_nmgr_alert_cancel(m_alertHandle[id]);
        m_alertHandle[id] = 0;
    }
}
#endif // __VAPP_SS_SHOW_IN_NCENTER__

void VappSsNCell::onTimeOut(VfxTimer *sender)
{
	vapp_ss_msg_struct *msg;
	VfxTimer *timer;
	VfxU32 i;
	for (i = 0; i < MMI_MAX_SIM_NUM; i++)
	{
		msg = getMsg(mmi_frm_index_to_sim(i));
		timer = (VfxTimer *)handleToObject(msg->timerObjHandle);
		if (sender == timer)
		{
			break;
		}
	}

	if (i == MMI_MAX_SIM_NUM)
	{
		return;
	}

	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_SS_ON_TIMEOUT, msg->sim, msg->type);
	
    srv_ss_abort_req_struct req;
	
    req.sim = mmi_frm_index_to_sim(i);
    req.source = SRV_SS_SRC_COMMON;
    srv_ss_act_req(SRV_SS_ACT_ABORT, &req, NULL, NULL);

	msg->type = SS_TYPE_EXPIRE;
    notifyApp(msg);

	msg->msg.loadFromRes(STR_ID_VAPP_SS_TIMEOUT2);
}

VappSsApp *VappSsNCell::getApp(mmi_sim_enum sim)
{
	VappSsApp *app;
	
	app = (VappSsApp *)VfxAppLauncher::findApp(
				VappSsApp::getAppId(sim),
				VFX_OBJ_CLASS_INFO(VappSsApp), 
				VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_SS_NOTIFY_APP, app);

	return app;
}

vapp_ss_msg_struct *VappSsNCell::getMsg(mmi_sim_enum sim)
{
	return &m_msg[mmi_frm_sim_to_index(sim)];
}

#ifdef __VAPP_SS_SELCET_SIM__
#if (MMI_MAX_SIM_NUM >= 2)
/***************************************************************************** 
 * Class VappSsSimSelScr
 *****************************************************************************/
void VappSsSimSelScr::onInit(void)
{
	VappSsSmallScr::onInit();

	VFX_ASSERT(m_sim != 0);
	
	VcpMenuPopup *menuPop;

	VFX_OBJ_CREATE(menuPop, VcpMenuPopup, this);
	menuPop->setAutoDestory(VFX_TRUE);
	menuPop->setTitle(STR_GLOBAL_SELECT);
	
	for (VfxU32 i = 0; i < MMI_SIM_TOTAL; i++)
	{	
		if (m_sim & mmi_frm_index_to_sim(i))
		{			
			menuPop->addItem((VfxId)mmi_frm_index_to_sim(i), vapp_sim_settings_get_sim_name_with_sim_id(mmi_frm_index_to_sim(i)));
		}
	}

	menuPop->m_signalMenuCallback.connect(this, &VappSsSimSelScr::onMenuCallack); 

	m_menuPopupWeakPtr =  menuPop;

	mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, &VappSsSimSelScr::hdlrSimAvailabilityChange, getObjHandle());
}

void VappSsSimSelScr::onDeinit(void)
{
	if (m_menuPopupWeakPtr.isValid())
	{
		VcpMenuPopup *menuPop = m_menuPopupWeakPtr.get();

		VFX_OBJ_CLOSE(menuPop);
	}
	
	mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, &VappSsSimSelScr::hdlrSimAvailabilityChange, getObjHandle());

	VappSsSmallScr::onDeinit();
}

void VappSsSimSelScr::onEnter(VfxBool isBackward)

{
	VfxAppScr::onEnter(isBackward);

	if (m_menuPopupWeakPtr.isValid())
	{
		VcpMenuPopup *menuPop = m_menuPopupWeakPtr.get();
		menuPop->showMenu();
	}
}


void VappSsSimSelScr::onMenuCallack(VcpMenuPopup* menu, VcpMenuPopupEventEnum evt, VcpMenuPopupItem *item)
{
	if (evt == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
		m_signalSimSelect.emit(item->getId());
	}
	else if (evt == VCP_MENU_POPUP_EVENT_MENU_CANCEL)
	{
		exit();
	}
}

void VappSsSimSelScr::processSimChange(mmi_event_struct *evt)
{
	srv_sim_ctrl_availability_changed_evt_struct *simEvt = (srv_sim_ctrl_availability_changed_evt_struct *)evt;
	
	if ((simEvt->sim & m_sim) &&
		simEvt->is_available_before &&
		!simEvt->is_available_now)
	{
		VcpMenuPopup *menuPop = m_menuPopupWeakPtr.get();
		VcpMenuPopupItem *item = menuPop->getItemById((VfxId)simEvt->sim);
		if (item != NULL)
		{
			menuPop->removeItem(item);
		}
	}
}

mmi_ret VappSsSimSelScr::hdlrSimAvailabilityChange(mmi_event_struct *evt)
{
	VappSsSimSelScr *thiz = (VappSsSimSelScr *)handleToObject((VfxObjHandle)evt->user_data);

	if (thiz != NULL)
	{
		thiz->processSimChange(evt);
	}
	
    return MMI_RET_OK;
}
#endif // MMI_MAX_SIM_NUM 
#endif
/***************************************************************************** 
 * Class VappSsApp
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSsApp", VappSsApp, VfxApp);
const VfxId VappSsApp::s_interceptExcludeModID[] = 
{
	SRV_UCM_MODULE_ORIGIN_AT,
#if (MMI_MAX_SIM_NUM >= 2)
	SRV_UCM_MODULE_ORIGIN_AT_SIM2,
#if (MMI_MAX_SIM_NUM >= 3)
	SRV_UCM_MODULE_ORIGIN_AT_SIM3,
#if (MMI_MAX_SIM_NUM >= 4)
	SRV_UCM_MODULE_ORIGIN_AT_SIM4,
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
	SRV_UCM_MODULE_ORIGIN_SAT,
	SRV_UCM_MODULE_ORIGIN_CCBS,
	SRV_UCM_MODULE_ORIGIN_VOICE_MAIL
};

const VappSsNcellInfo VappSsApp::s_NcellInfo[MMI_MAX_SIM_NUM] =
{
	{VAPP_SS, 	STR_GLOBAL_SIM_1},
#if (MMI_MAX_SIM_NUM >= 2)
	{VAPP_SS_2, STR_GLOBAL_SIM_2},
#if (MMI_MAX_SIM_NUM >= 3)
	{VAPP_SS_3, STR_GLOBAL_SIM_3},
#if (MMI_MAX_SIM_NUM >= 4)
	{VAPP_SS_4, STR_GLOBAL_SIM_4}
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
};


/***************************************************************************** 
 * Class  VappSsApp Implementation
 *****************************************************************************/
VappSsApp::VappSsApp() 
	: m_scr(NULL), 
	  m_scrWeakPtr(NULL),
	  m_smallScr(NULL), 
	  m_localAbort(VFX_FALSE), 
	  m_isRequsting(VFX_FALSE),
	  m_data(NULL)
{
	memset(&m_msg, 0, sizeof(m_msg));
	m_msg.type = SS_TYPE_UNKNOWN;
}

VfxResId VappSsApp::getSimStrId(mmi_sim_enum sim)
{
	if (sim == MMI_SIM_NONE)
	{
		return 0;
	}

	return s_NcellInfo[mmi_frm_sim_to_index(sim)].strId;	
}

mmi_id VappSsApp::getAppId(mmi_sim_enum sim)
{
	if (sim == MMI_SIM_NONE)
	{
		return 0;
	}

	return s_NcellInfo[mmi_frm_sim_to_index(sim)].appId;
}

mmi_ret VappSsApp::processIntercept(mmi_event_struct *para)
{
	srv_ucm_intercept_query_evt_struct *evt = (srv_ucm_intercept_query_evt_struct*)para;

	mmi_sim_enum real_sim = mmi_ss_get_sim_by_ucm_call_type(evt->call_type);

	WCHAR ucs2_str[SRV_SS_MAX_LENGTH + 1];
	mmi_asc_n_to_ucs2((CHAR *)ucs2_str, (CHAR *)(evt->num_uri), SRV_SS_MAX_LENGTH);
	VfxU8 length = (VfxU8)mmi_ucs2strlen((CHAR *)ucs2_str);

	VfxU32 i;
	mmi_sim_enum sim;

	for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
		sim = mmi_frm_index_to_sim(i);
		if (!srv_ss_is_valid_ss_string(sim, length, ucs2_str))
		{
			real_sim = (mmi_sim_enum)(real_sim & (~sim));
		}
	}

	// For invalid SS string
	if (real_sim == 0)
	{
		return SRV_UCM_INTERCEPT_QUERY_RESULT_NO;
	}

	// Don't handle the intercept from the excluded module ID.
	for (i = 0; i < sizeof(VappSsApp::s_interceptExcludeModID) / sizeof(VfxId); i++)
	{
		if (evt->module_id == VappSsApp::s_interceptExcludeModID[i])
		{
			return SRV_UCM_INTERCEPT_QUERY_RESULT_NO;	
		}
	}
	
	// Clear unvalibale SIM
	for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
		sim = mmi_frm_index_to_sim(i);
		if (!srv_ss_is_available(sim))
		{
			real_sim = (mmi_sim_enum)(real_sim & (~sim));
		}
	}

	VfxU32 sim_total = 0;
	for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
		if (real_sim & mmi_frm_index_to_sim(i))
		{
			sim_total++;
		}
	}

	if (sim_total == 0)
	{
		/* no sim is available */
		/* get the first original sim */
		real_sim = mmi_ss_get_sim_by_ucm_call_type(evt->call_type);

		for (i = 0; i < MMI_SIM_TOTAL; i++)
		{
			if (real_sim & mmi_frm_index_to_sim(i))
			{
				real_sim = mmi_frm_index_to_sim(i);
				break;
			}
		}

	}
#ifdef __VAPP_SS_SELCET_SIM__
	// Ask User to select the SIM.
#if (MMI_MAX_SIM_NUM >= 2)
	else if (sim_total > 1)
	{
		vapp_ss_launch_param_struct para;
		
		para.launch_id = VappSsApp::LAUNCH_ID_SIM_SELECTION;
		para.sim = real_sim;
		
		vfx_sys_wcscpy(para.u.buffer, (const VfxWChar *)ucs2_str);

		VfxAppLauncher::launch( 
			VAPP_SS,
			VFX_OBJ_CLASS_INFO(VappSsApp),
			GRP_ID_ROOT,
			&para,
			sizeof(vapp_ss_launch_param_struct));

		return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;
	}
#endif // MMI_MAX_SIM_NUM 
	else
	{
		// Only one SIM, just use real_sim
	}
#endif // __VAPP_SS_SELCET_SIM__
	vapp_ss_launch_param_struct paraSend;
	
	paraSend.launch_id = VappSsApp::LAUNCH_ID_MSG;
	paraSend.sim = real_sim;
	paraSend.type = SS_TYPE_REQUESTING;
	
	vfx_sys_wcscpy(paraSend.u.buffer, (const VfxWChar *)ucs2_str);
	
	VfxAppLauncher::launch( 
		VappSsApp::getAppId(real_sim),
		VFX_OBJ_CLASS_INFO(VappSsApp),
		GRP_ID_ROOT,
		&paraSend,
		sizeof(vapp_ss_launch_param_struct));

	return SRV_UCM_INTERCEPT_QUERY_RESULT_YES;

}

VfxBool VappSsApp::sendSS(const mmi_sim_enum sim, const VfxWChar *ss, const VfxU32 &len)
{
    srv_ss_operation_req_struct req;
	
    req.sim = sim;
	req.source = SRV_SS_SRC_COMMON;
	
	vfx_sys_wcsncpy((VfxWChar *)req.string, ss, len);

	srv_ss_result_enum result;
	result = srv_ss_act_req(SRV_SS_ACT_SS_OPERATION, &req, NULL, NULL);
    m_isRequsting = VFX_TRUE;
	if (result != SRV_SS_RESULT_OK)
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
							 MMI_EVENT_INFO_BALLOON,
							 MMI_NMGR_BALLOON_TYPE_FAILURE,
							 (WCHAR*)GetString(srv_ss_get_result_string(result)));

		return VFX_FALSE;
	}

	return VFX_TRUE;
}

void VappSsApp::onDeinit()
{
#ifdef __VAPP_SS_SHOW_IN_NCENTER__
    VappSsNCell *ncell = VFX_OBJ_GET_INSTANCE(VappSsNCell);
    if (ncell && (m_msg.sim & MMI_SIM_ALL))
    {
        ncell->releaseNotify(m_msg.sim);
    }
#endif // __VAPP_SS_SHOW_IN_NCENTER__
    m_isRequsting = VFX_FALSE;
	VFX_FREE_MEM(m_data);
	
	VfxApp::onDeinit();
}

void VappSsApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    m_scr = NULL;
	m_scrWeakPtr = NULL;
    m_smallScr = NULL;
    m_localAbort = VFX_FALSE;

	if (args != NULL)
	{
		vapp_ss_launch_param_struct *para = (vapp_ss_launch_param_struct *)args;
		
		VFX_ALLOC_MEM(m_data, sizeof(vapp_ss_launch_param_struct), this);
		memcpy(m_data, para, sizeof(vapp_ss_launch_param_struct));
		
		switch(para->launch_id)
		{
#ifdef __VAPP_SS_SELCET_SIM__
#if (MMI_MAX_SIM_NUM >= 2)
			case LAUNCH_ID_SIM_SELECTION:
			{
				VappSsSimSelScr *simSelScr;
				
				VFX_OBJ_CREATE_EX(simSelScr, VappSsSimSelScr, this, (para->sim));
				
				simSelScr->m_signalSimSelect.connect(this, &VappSsApp::onSimSelect);
				simSelScr->show();
			}
			break;
#endif // MMI_MAX_SIM_NUM
#endif // __VAPP_SS_SELCET_SIM__
			case LAUNCH_ID_MSG:		
			{
				vapp_ss_msg_struct msg;
				
				msg.sim = para->sim;
				msg.type = para->type;
				msg.msg.loadFromMem(para->u.buffer);
				
				onEvent(&msg);
			}
			break;

			default:
				break;
		}

	}

}

void VappSsApp::onEvent(vapp_ss_msg_struct *msg)
{
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_SS_ON_EVENTS, msg->sim, msg->type, m_localAbort);

    m_msg.sim = msg->sim;
    m_msg.type = msg->type;
    m_msg.msg = msg->msg;

    VfxId id = 1;
    VfxId prevId = 2;

	m_scr = m_scrWeakPtr.get();
	
    if (m_scr)
    {
        if (m_scr->isPageIdValid(id))
        {
            id = 2;
            prevId = 1;
        }
    }
    if (SS_TYPE_REQUESTING != msg->type)
    {
        m_isRequsting = VFX_FALSE;
    }
    switch (msg->type)
    {
        case SS_TYPE_USSD:
        case SS_TYPE_USSN:
        case SS_TYPE_USSR:
        {
			VfxBool isFirst = VFX_FALSE;
            if (!m_scr)
            {
                VFX_OBJ_CREATE(m_scr, VfxMainScr, this);
				isFirst = VFX_TRUE;
                m_scrWeakPtr = m_scr;
            }

			VappSsPageMsg *page;
			VFX_OBJ_CREATE(page, VappSsPageMsg, m_scr);
			m_scr->pushPage(id, page);

			if (isFirst)
			{
            	m_scr->show();
			}
            
            m_scr->closePage(prevId);

            if (m_smallScr)
            {
                m_smallScr->back();
                m_smallScr = NULL;
            }
            break;
        }

        case SS_TYPE_REQUESTING:
        {
			VcpIndicatorPopup *sendingPop;
            if (!m_scr)
            {
                VFX_OBJ_CREATE(m_smallScr, VappSsSmallScr, this);
                m_smallScr->show();

                VFX_OBJ_CREATE(sendingPop, VcpIndicatorPopup, m_smallScr);
            }
            else
            {
                VFX_OBJ_CREATE(sendingPop, VcpIndicatorPopup, m_scr->getPage(prevId));
            }
			
			sendingPop->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
			sendingPop->setText(STR_ID_VAPP_SS_REQUESTING);
			sendingPop->m_signalCanceled.connect(this, &VappSsApp::onAbort);
			sendingPop->setAutoDestory(VFX_TRUE);

			//
			// Send SS after popup is show completely to avoid the seding popup flash and exit quickly.
			//
			if (m_msg.msg.getLength() != 0)
			{
				sendingPop->m_signalPopupState.connect(this, &VappSsApp::onPopState);
			}
			sendingPop->show(VFX_TRUE);
				
            break;
        }

        case SS_TYPE_ABORT: /* local cancel / expiry or remote abort */
        {
            if (m_localAbort)
            {
                m_localAbort = VFX_FALSE;
            }
            else
            {
				// As spec, there should be only one USSR session with 30s
				vapp_nmgr_global_popup_show_confirm_one_button_id(
					MMI_SCENARIO_ID_SS,
					VCP_POPUP_TYPE_INFO,
					STR_ID_VAPP_SS_ABORTED,
					STR_GLOBAL_OK,
					VCP_POPUP_BUTTON_TYPE_NORMAL,
					VappSsApp::popupCallback,
					getObjHandle());

            }
            break;
        }

        case SS_TYPE_EXPIRE: /* local expiry (receive EXPIRE and then ABORT) */
        {
			if (!m_localAbort)
			{
			// As spec, there should be only one USSR session with 30s
			vapp_nmgr_global_popup_show_confirm_one_button_id(
				MMI_SCENARIO_ID_SS,
				VCP_POPUP_TYPE_INFO,
				STR_ID_VAPP_SS_TIMEOUT,
				STR_GLOBAL_OK,
				VCP_POPUP_BUTTON_TYPE_NORMAL,
				VappSsApp::popupCallback,
				getObjHandle());
			
					m_localAbort = VFX_TRUE;
			}
            break;
        }

        case SS_TYPE_CANCEL: /* local abort (receive CANCEL and then ABORT) */
        {
            m_localAbort = VFX_TRUE;
            onAbort(this, 0);
            break;
        }
    }
}

void VappSsApp::onPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state)
{
    if(!m_isRequsting && (m_msg.type == SS_TYPE_REQUESTING) && (state == VFX_BASE_POPUP_AFTER_START_ANIMATION))
    {
        VfxBool ret = sendSS(m_msg.sim, m_msg.msg.getBuf(),	m_msg.msg.getLength());
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

        if (!ret)
        {
            terminateApp(this, 0);
        }
    }
}

void VappSsApp::popupCallback(VfxId id, void *userData)
{
	VappSsApp *thiz = (VappSsApp *)handleToObject((VfxObjHandle)userData);
	
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_SS_POP_CALLBACK, thiz);

	if (thiz != NULL)
	{
		VfxAppLauncher::terminate(thiz->getGroupId());
	}
}
#ifdef __VAPP_SS_SELCET_SIM__
#if (MMI_MAX_SIM_NUM >= 2)
void VappSsApp::onSimSelect(VfxId id)
{
	vapp_ss_launch_param_struct *para = (vapp_ss_launch_param_struct *)m_data;
	
    sendSS((mmi_sim_enum)id, (const VfxWChar *)para->u.buffer, 
            vfx_sys_wcslen((const VfxWChar *)para->u.buffer));

    terminateApp(this, id);
}
#endif // MMI_MAX_SIM_NUM
#endif // __VAPP_SS_SELCET_SIM__
void VappSsApp::onAbort(VfxObject* obj, VfxFloat id)
{
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, VAPP_SS_ON_ABORT, m_msg.sim, id);

    srv_ss_abort_req_struct req;
	
    req.sim = m_msg.sim;
    req.source = SRV_SS_SRC_COMMON;

    srv_ss_act_req(SRV_SS_ACT_ABORT, &req, NULL, NULL);
#ifdef __VAPP_SS_SHOW_IN_NCENTER__
    VappSsNCell *ncell = VFX_OBJ_GET_INSTANCE(VappSsNCell);
    if (ncell)
    {
        ncell->releaseNotify(m_msg.sim);
    }
#endif // __VAPP_SS_SHOW_IN_NCENTER__
    terminateApp(this, id);
}

void VappSsApp::onGroupActive()
{
    if(vapp_screen_lock_is_exist())
    {
        vapp_screen_lock_close();
    }
#ifdef __VAPP_SS_SHOW_IN_NCENTER__
	VappSsNCell *ncell = VFX_OBJ_GET_INSTANCE(VappSsNCell);

    if (ncell && (m_msg.sim & MMI_SIM_ALL))
    {
        vapp_ss_msg_struct msg;
		
        msg.sim = m_msg.sim;
        msg.type = SS_TYPE_INT_HIDE;
        msg.msg.setEmpty();
		msg.timerObjHandle = m_msg.timerObjHandle;
		
        ncell->onIntMsg(&msg);
    }
#endif // __VAPP_SS_SHOW_IN_NCENTER__
}

void VappSsApp::onGroupInactive()
{
	VappSsNCell *ncell = VFX_OBJ_GET_INSTANCE(VappSsNCell);

    if (ncell != NULL)
    {
    	// is aborting.
    	if (m_localAbort && m_msg.type == SS_TYPE_EXPIRE)
    	{
    		return;
    	}
	#ifdef __VAPP_SS_SHOW_IN_NCENTER__	
		if (!mmi_frm_is_in_backward_scenario())
		{
	        vapp_ss_msg_struct msg;
			
	        msg.sim = m_msg.sim;
	        msg.type = m_msg.type;
	        msg.msg = m_msg.msg;
			msg.timerObjHandle = m_msg.timerObjHandle;
			
	        ncell->onIntMsg(&msg);
	    }
    #endif // __VAPP_SS_SHOW_IN_NCENTER__
    }
    else if (m_msg.type == SS_TYPE_USSR)
    {
        onAbort(this, 0);
    }
}

void VappSsApp::terminateApp(VfxObject* sender, VfxId id)
{
    VfxAppLauncher::terminate(getGroupId());
}

/***************************************************************************** 
 * Class  VappSsPageMsg Implementation
 *****************************************************************************/
void VappSsPageMsg::onInit()
{
    VfxPage::onInit(); // call base class

    m_app = VFX_OBJ_DYNAMIC_CAST(getMainScr()->getApp(), VappSsApp);
    MMI_ASSERT(m_app);

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    VfxWString str = VFX_WSTR_RES(STR_ID_VAPP_SS_USSD_MSG);
    if (srv_sim_ctrl_get_num_of_inserted() > 1)
    {
	    str += VFX_WSTR(" (");

		str += VFX_WSTR_RES(VappSsApp::getSimStrId(m_app->m_msg.sim));	

	    str += VFX_WSTR(")");
    }
    titlebar->setTitle(str);
    setTopBar(titlebar);

    VcpTextView *text; /* scroll */
    VFX_OBJ_CREATE(text, VcpTextView, this);
    text->setPos(10, 10);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);

    if (m_app->m_msg.type != SS_TYPE_USSR)
    {
        text->setSize(getSize().width - 20, getSize().height - 20);
        m_textInput = NULL;
        m_toolBar->addItem('OKAY', STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    }
    else
    {
        text->setSize(getSize().width - 20, getSize().height - 80);

        VFX_OBJ_CREATE(m_textInput, VcpTextEditor , this);
        m_textInput->setAnchor(0.5, 1);
        m_textInput->setPos(VfxPoint(getSize().width / 2, getSize().height - 10));
    #ifdef __MMI_MAINLCD_320X480__
        m_textInput->setBounds(VfxRect(0, 0, 310, 40));
    #elif defined(__MMI_MAINLCD_480X800__)
        m_textInput->setBounds(VfxRect(0, 0, 450, 70));
    #elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        m_textInput->setBounds(VfxRect(0, 0, 226, 27));
    #endif /* __MMI_MAINLCD_320X480__ */

        m_textInput->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_NONE,
                        VFX_FRAME_ALIGNER_MODE_MID,
                        VFX_FRAME_ALIGNER_MODE_SIDE);
        m_textInput->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
        m_textInput->setIME(INPUT_TYPE_USE_ENCODING_BASED_LENGTH|INPUT_TYPE_ONE_LESS_CHARACTER|IMM_INPUT_TYPE_SENTENCE);
        m_textInput->setText(VFX_WSTR_EMPTY, SRV_SS_MAX_LENGTH);
        m_textInput->m_signalTextChanged.connect(this, &VappSsPageMsg::onTextChanged); 

        m_toolBar->addItem('SEND', STR_GLOBAL_SEND, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND);
        m_toolBar->addItem('CANL', STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
		m_toolBar->setDisableItem('SEND', VFX_TRUE);
    }

    text->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    text->setAlignMode(VCP_TEXT_ALIGN_MODE_NATURAL);
    text->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    text->setText(m_app->m_msg.msg);

    m_toolBar->m_signalButtonTap.connect(this, &VappSsPageMsg::onToolBarTapped);
    setBottomBar(m_toolBar);

}

void VappSsPageMsg::onTextChanged(VcpTextEditor* editor)
{
    if (mmi_ucs2strlen((CHAR *)m_textInput->getText()) != 0)
    {
        m_toolBar->setDisableItem('SEND', VFX_FALSE);
    }
    else
    {
        m_toolBar->setDisableItem('SEND', VFX_TRUE);
    }
}

void VappSsPageMsg::onToolBarTapped(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 'OKAY': /* OK */
            getMainScr()->popPage();
            break;

        case 'SEND': /* SEND */
        {
            srv_ss_operation_req_struct ussd;
			
            ussd.sim = m_app->m_msg.sim;
            ussd.source = SRV_SS_SRC_COMMON;
            mmi_ucs2cpy((CHAR *)ussd.string, (CHAR *)m_textInput->getText());

            srv_ss_result_enum result;
            result = srv_ss_act_req(SRV_SS_ACT_SS_OPERATION, &ussd, NULL, NULL);
            if (result != SRV_SS_RESULT_OK)
            {
                vapp_ss_msg_struct msg;
                msg.sim = m_app->m_msg.sim;
                msg.type = SS_TYPE_USSD;
                msg.msg.loadFromRes(srv_ss_get_result_string(result));
                m_app->onEvent(&msg);
            }
            break;
        }

        case 'CANL': /* CANCEL */
        {
            vapp_ss_msg_struct msg;
            msg.sim = m_app->m_msg.sim;
            msg.type = SS_TYPE_CANCEL;
            msg.msg = VFX_WSTR_EMPTY;
            m_app->onEvent(&msg);
            break;
        }
    }
}

