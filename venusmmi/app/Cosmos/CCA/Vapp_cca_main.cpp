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
 *  vapp_usb_basecontext.cpp
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
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h" 



#ifdef __MMI_CCA_SUPPORT__ 

/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef __AFX_RT_TEST__
#include "vtst_rt_main.h"
#endif
#ifdef __cplusplus
extern "C"
{
#include "MMI_include.h"
//#include "CCASrvGProt.h"
#include "CCASrvIProt.h"
}
#endif
#include "Vcp_list_menu.h"
#include "Vapp_cca_gprot.h"
#include "vapp_nmgr_gprot.h"
#include "vapp_msg_gprot.h"
#include "vsrv_notification.h"
#include "vsrv_ncenter.h"
#include "notificationGprot.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "mmi_rp_vapp_cca_def.h"
#include "mmi_rp_vapp_msg_def.h"
#include "mmi_frm_timer_gprot.h"

#include "Vapp_cca_main.h"


extern "C" mmi_ret vapp_cca_event_hdlr(mmi_event_struct *evt);
extern "C" void vapp_cca_srv_notify_hdlr(mmi_event_struct *evt);
extern "C" void vapp_cca_create_inst(mmi_event_struct *evt);
extern "C" void vapp_cca_srv_event_hdlr(mmi_event_struct *evt);
extern "C" void vapp_cca_srv_invalid_msg_hdlr(mmi_event_struct *evt);

VappCCAInstMgr* VappCCAInstMgr::m_singleInst = NULL;
VfxU32 VappCCAInstMgr::m_instBuf[(sizeof(VappCCAInstMgr) + 3) / 4];
VfxU32 g_unSupportPopup = 0;

#ifdef __MMI_PROV_IN_UM__
extern "C" MMI_ID vapp_prov_get_group_id(void);
extern "C" void vcui_cca_launch(void *arg, VfxU32 argSize);
#else
extern "C" void vapp_cca_srv_recv_new_msg_hdlr(mmi_event_struct *evt); 
extern "C" void vapp_cca_launch(void *arg, VfxU32 argSize);
#endif /* __MMI_PROV_IN_UM__ */

/***************************************************************************** 
 * Function
 *****************************************************************************/

extern "C" mmi_ret vapp_cca_init(mmi_event_struct *evt)
{
    srv_cca_init(evt);
    srv_cca_set_event_proc(SRV_CCA_INVALID_HANDLE, vapp_cca_event_hdlr, NULL);
    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_cca_event_hdlr(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_9, TRC_MMI_VAPP_CCA_EVENT_HDLR, evt->evt_id);
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_CCA_NOTIFY:
        {
		    MMI_TRACE(TRACE_GROUP_9, TRC_MMI_VAPP_CCA_SRV_NOTIFY_HDLR, evt->evt_id);
            vapp_cca_srv_notify_hdlr(evt);
        }
        break;
        
        case EVT_ID_SRV_CCA_RECV_INVALID_MSG:
        {
            vapp_cca_srv_invalid_msg_hdlr(evt);
        }
        break;
        
#ifndef __MMI_PROV_IN_UM__
		case EVT_ID_SRV_CCA_RECV_NEW_MSG:
		{
		    vapp_cca_srv_recv_new_msg_hdlr(evt);   
		}
        break;
#endif
 
        default:
        { 
            vapp_cca_srv_event_hdlr(evt);
        }
        break;
    }    
	return MMI_RET_OK;
}

extern "C" void vapp_cca_srv_notify_hdlr(mmi_event_struct *evt)
{
    srv_cca_evt_notify_struct *event = (srv_cca_evt_notify_struct*)evt;
    popup_type_enum type;
    
	
    if(event->type <= SRV_CCA_NOTIFY_TYPE_NOT_AVAILABLE)
    {
        type = (popup_type_enum)(POPUP_TYPE_MEM_FULL + (event->type - SRV_CCA_NOTIFY_TYPE_MEM_FULL));
    }
    else
    {
        return;
    }
    
    g_unSupportPopup = showGlobalPopup(type);
   
#ifdef __MMI_PROV_IN_UM__
    VappMsgApp *msgScr = (VappMsgApp *)VfxAppLauncher::findApp(VAPP_MSG, VFX_OBJ_CLASS_INFO(VappMsgApp), 
		VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

    if(msgScr)
    {
        msgScr->setSubMsgCareHomeKeyCb(vapp_cca_close_popup, NULL);
    }
#endif /* __MMI_PROV_IN_UM__ */   
}

extern "C" void vapp_cca_close_popup(VfxBool & result,void *user_data)
{
    result = VFX_FALSE;
    if (g_unSupportPopup)
    {
        vapp_nmgr_global_popup_cancel(g_unSupportPopup);
        g_unSupportPopup = 0;
    }
}

extern "C" void vapp_cca_srv_invalid_msg_hdlr(mmi_event_struct *evt)
{
    srv_cca_evt_recv_invalid_msg_struct *event = (srv_cca_evt_recv_invalid_msg_struct*)evt;
    if(event->status == SRV_CCA_STATUS_AUTH_FAILED)
    {
        showGlobalPopup(POPUP_TYPE_AUTH_FAIL);
    }
    else
    {
        showGlobalPopup(POPUP_TYPE_INVAID_MSG);
    }
}

extern "C" void vapp_cca_srv_event_hdlr(mmi_event_struct *evt)
{
    VappCCAInstMgr *instMgr = VFX_OBJ_GET_INSTANCE(VappCCAInstMgr);	
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_CCA_VERIFY_PIN:        
        case EVT_ID_SRV_CCA_PRE_INSTALL:
            vapp_cca_create_inst(evt);            
            break;
        
        case EVT_ID_SRV_CCA_POST_INSTALL:            
        {
            srv_cca_evt_post_install_struct *event = (srv_cca_evt_post_install_struct*)evt;
            
            if (!instMgr->getInst())
            {
	            srv_cca_evt_install_finished_struct info;

	            info.h_cca = event->h_cca;
	            info.is_msg_from_box = MMI_TRUE;
	            srv_cca_apply_action(event->h_cca, SRV_CCA_ACTION_TYPE_INSTALL_COMPLETE, &info, sizeof(info));

	            return;
            }
            instMgr->m_eventSignal.emit(VAPP_CCA_EVENT_INSTALL_RESULT, evt);
        }
        break;

        case EVT_ID_SRV_CCA_INSTALL_FINISHED:
        {            
            instMgr->m_eventSignal.emit(VAPP_CCA_EVENT_INSTALL_FINISHED, NULL);
#ifndef __MMI_PROV_IN_UM__ 
            VappCCANotifyMgr::createNcenterCell();
#endif /* __MMI_PROV_IN_UM__ */ 
        }
        break;

	 	default:
	 	break;
    }
}

extern "C" void vapp_cca_create_inst(mmi_event_struct *evt)
{
    VappCCAInstMgr *instMgr = VFX_OBJ_GET_INSTANCE(VappCCAInstMgr);

    MMI_TRACE(TRACE_GROUP_9, TRC_MMI_VAPP_CCA_CREATE_INST);
    if (!instMgr->hasInst())
    {
        void *arg = (void *)evt;
        VfxU32 argSize = 0;

        switch(evt->evt_id)
        {
            case EVT_ID_SRV_CCA_VERIFY_PIN:  
            {    
                argSize = sizeof(srv_cca_evt_verify_pin_struct);
                break;
            }
            case EVT_ID_SRV_CCA_PRE_INSTALL:
            {              
                argSize = sizeof(srv_cca_evt_pre_install_struct);
                break;
            }
            default:
                return;
        }
#ifndef __MMI_PROV_IN_UM__  		
        vapp_cca_launch(arg, argSize);
#else
	    vcui_cca_launch(arg, argSize);
#endif
    }
    else
    {
        switch(evt->evt_id)
        {
            case EVT_ID_SRV_CCA_VERIFY_PIN:  
            {    
                instMgr->m_eventSignal.emit(VAPP_CCA_EVENT_PIN_CHECK, evt); 
                break;
            }
            case EVT_ID_SRV_CCA_PRE_INSTALL:
            {              
                instMgr->m_eventSignal.emit(VAPP_CCA_EVENT_PRE_INSTALL, evt);  
                break;
            }
            default:
                return;
        }
    }
//#endif /* __MMI_PROV_IN_UM__ */
}

#ifdef __MMI_PROV_IN_UM__
extern "C" void vcui_cca_launch(void *arg, VfxU32 argSize)
{   
    mmi_id inst = 0;
    inst = VfxAppLauncher::createCui( 
    		VAPP_CCA,
    		VFX_OBJ_CLASS_INFO(VappCCACui),
    		vapp_prov_get_group_id(),
    		arg,
    		argSize);

    // Launch CUI always has enough memory, so createCui and OnRun synchronism.
    VappCCAInstMgr *instMgr = VFX_OBJ_GET_INSTANCE(VappCCAInstMgr);
    VappCCACui *app =  VFX_OBJ_DYNAMIC_CAST(instMgr->getInst(), VappCCACui);
    app->setInstId(inst);
    VfxAppLauncher::runCui(inst);
}
#else
extern "C" void vapp_cca_launch(void *arg, VfxU32 argSize)
{
    mmi_id inst;
    inst = VfxAppLauncher::launch( 
            VAPP_CCA,
            VFX_OBJ_CLASS_INFO(VappCCACui),
            GRP_ID_ROOT,
    		arg,
		    argSize);

    // Launch App failed, cancel cca_srv job
    if(0 == inst)
    {    
        srv_cca_apply_action(SRV_CCA_INVALID_HANDLE, SRV_CCA_ACTION_TYPE_CANCEL_NEW_MSG, NULL, 0);
        return;
    }
            
    // Launch App may be not enough memory before OnRun, so can't call setInstId at here   
    VFX_OBJ_GET_INSTANCE(VappCCAInstMgr);
}
#endif /* __MMI_PROV_IN_UM__ */

mmi_id vapp_cca_get_parent_id(void)
{
    VappCCAInstMgr *instMgr = VFX_OBJ_GET_INSTANCE(VappCCAInstMgr);
    VappCCACui *app =  VFX_OBJ_DYNAMIC_CAST(instMgr->getInst(), VappCCACui);
    if (app)
    {
        return app->getInstId();
    }
    else
    {
        return 0;
    }
}

VfxAppScr* vapp_cca_get_parent_screen(void)
{
    VappCCAInstMgr *instMgr = VFX_OBJ_GET_INSTANCE(VappCCAInstMgr);
    VappCCACui *app =  VFX_OBJ_DYNAMIC_CAST(instMgr->getInst(), VappCCACui);
    if (app)
    {
        return app->getMainScreen();
    }
    else
    {
        return NULL;
    }
}

#ifndef __MMI_PROV_IN_UM__ 
extern "C" void vapp_cca_srv_recv_new_msg_hdlr(mmi_event_struct *evt)
{

	MMI_TRACE(TRACE_GROUP_9, TRC_MMI_VAPP_CCA_SRV_RECV_NEW_MSG_HDLR);	
    if(0 == srv_cca_get_unread_msg_num(NULL, 0, NULL))
    {
        return;
    }

    VappCCANotifyMgr::createNSS();   
    VappCCANotifyMgr::createNcenterCell();
}

NMGR_HANDLE VappCCANotifyMgr::m_nssHandle = 0;  

void VappCCANotifyMgr::viewNewSettingMsg()
{
    srv_cca_apply_action(SRV_CCA_INVALID_HANDLE, SRV_CCA_ACTION_TYPE_VIEW_NEW_MSG, NULL, 0);
    
    clearNSS();
    clearNcenterCell();
    // update Ncenter cell
    createNcenterCell();
}

void VappCCANotifyMgr::showInstallingPopup(void)
{
    vapp_nmgr_global_popup_show_confirm_one_button_id(
                MMI_SCENARIO_ID_DEFAULT,
                VCP_POPUP_TYPE_WARNING, 
                STR_ID_VAPP_CCA_INSTALLING_RETRY, 
                STR_GLOBAL_OK, 
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                NULL,
                NULL); 
}

mmi_ret VappCCANotifyMgr::nssIntentCallback(mmi_event_struct *param)
{   
    if(EVT_ID_NMGR_POPUP_APP_LAUNCH == param->evt_id||
       EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH == param->evt_id)
    {     
        if(NULL != VfxApp::getObject(VAPP_CCA))
        {
            StartTimer(TIMER_ID_VAPP_CCA_NMGR_POPUP, 0, VappCCANotifyMgr::showInstallingPopup);                       
        }
        else
        {
            viewNewSettingMsg();            
        }
    }
    return MMI_RET_OK;  
}

void VappCCANotifyMgr::createNSS()
{
    VfxU32 unread_num = srv_cca_get_unread_msg_num(NULL, 0, NULL);
        
    VfxWString tmp;    
    tmp = VfxWString().format("%d ", unread_num);    
    tmp += VFX_WSTR_RES(STR_ID_VAPP_CCA_NCENTER_NEW_SETTING); 

    mmi_frm_nmgr_alert_struct alert_info;    
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
    alert_info.app_id = VAPP_MSG;
    alert_info.scen_id = MMI_SCENARIO_ID_CCA;
    alert_info.event_type = MMI_EVENT_UNREAD_MSG;   
    /*fill in the notification information, if your app's notification can be controlled by NSS, your UI mask must include icon, status bar and popup*/
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
    alert_info.behavior_mask = PREFER_POPUP; // or PREFER_STATUS_BAR. PREFER_ICON_ONLY
    alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
    alert_info.status_bar_para.image.id = IMG_SI_PROVMSG;
#else
    alert_info.status_bar_para.image.id = IMG_SI_SMS_INDICATOR;
#endif
    alert_info.status_bar_para.display_string = (WCHAR *)tmp.getBuf();     
    alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
    alert_info.popup_para.image_type = MMI_NMGR_IMG_RES_ID;
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
    alert_info.popup_para.image.id = IMG_SI_PROVMSG;
#else
    alert_info.popup_para.image.id = IMG_SI_SMS_INDICATOR;
#endif
    alert_info.popup_para.popup_string = (WCHAR *)tmp.getBuf();
    alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_INSTALL);
    alert_info.status_bar_icon_para.icon_id = STATUS_ICON_PROVMSG_STATE;  
    /*fill in the app launch callback*/
    alert_info.app_proc_para.scrn_group_proc = &VappCCANotifyMgr::nssIntentCallback;
    alert_info.app_proc_para.user_data = NULL;	
    alert_info.app_proc_para.data_size = 0;
    m_nssHandle = mmi_frm_nmgr_alert(&alert_info);
}

void VappCCANotifyMgr::clearNSS(void)
{
    if (VappCCANotifyMgr::m_nssHandle)
    {
        mmi_frm_nmgr_alert_cancel(VappCCANotifyMgr::m_nssHandle);
        VappCCANotifyMgr::m_nssHandle = 0;
    }
}

void VappCCANotifyMgr::createNcenterCell()
{
    VfxU32 unread_num = srv_cca_get_unread_msg_num(NULL, 0, NULL);
    if (!unread_num)
        return;

    VsrvNGroupSingleTitle *group = NULL;
    VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_MSG));
    group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MSG)); 

    VfxWString tmp;    
    tmp = VfxWString().format("%d ", unread_num);    
    tmp += VFX_WSTR_RES(STR_ID_VAPP_CCA_NCENTER_NEW_SETTING); 
    
    VsrvNotificationEvent *noti;   
    VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup*) group, VAPP_MSG_NCENTER_CCA_CELL));       
    noti->setIcon(VfxImageSrc(IMG_ID_VAPP_MSG_NCENTER_UNREAD));
    noti->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CCA_NCENTER_SETTING_MESSAGE));
    noti->setSubText(tmp);
    noti->setAutoClose(VFX_FALSE);
    noti->setAutoLaunch(VFX_TRUE);                
    noti->setIntentCallback(VappCCANotifyMgr::ncenterIntentCallback, NULL, 0);
    noti->setCurrentTime();
    noti->notify();
	return;	
}

void VappCCANotifyMgr::ncenterIntentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    if (0 < srv_cca_get_unread_msg_num(NULL, 0, NULL))
    {
        if (VSRV_NINTENT_TYPE_LAUNCH == intent.type)
        {	       
            if(NULL != VfxApp::getObject(VAPP_CCA))
            {
                StartTimer(TIMER_ID_VAPP_CCA_NMGR_POPUP, 0, VappCCANotifyMgr::showInstallingPopup);                    
            }
            else
            {
                viewNewSettingMsg();
            }
        }
        else if (VSRV_NINTENT_TYPE_CLEAR == intent.type)
        {     
        	srv_cca_apply_action(SRV_CCA_INVALID_HANDLE, SRV_CCA_ACTION_TYPE_CANCEL_NEW_MSG, NULL, 0);
            clearNSS();
            clearNcenterCell();	
        }
        else if (VSRV_NINTENT_TYPE_LANGUAGE_CHANGED == intent.type)
        {
            VsrvNGroupSingleTitle *group = NULL;
            VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_MSG));
            group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MSG)); 
            
            VfxU32 unread_num = srv_cca_get_unread_msg_num(NULL, 0, NULL);
            VfxWString tmp;                          
            tmp = VfxWString().format("%d ", unread_num);    
            tmp += VFX_WSTR_RES(STR_ID_VAPP_CCA_NCENTER_NEW_SETTING);           
            VsrvNotificationEvent *notification = (VsrvNotificationEvent *)noti; 
            notification->setSubText(tmp);
            notification->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CCA_NCENTER_SETTING_MESSAGE));
            notification->notify();
        }
    }
}

void VappCCANotifyMgr::clearNcenterCell(void)
{
    VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_MSG, VAPP_MSG_NCENTER_CCA_CELL);
}
#endif /* __MMI_PROV_IN_UM__ */

VappCCAInstMgr* VappCCAInstMgr::getInstance(void)
{
    if (!m_singleInst)
    {
       new (m_instBuf) VappCCAInstMgr();
       m_singleInst = (VappCCAInstMgr*)m_instBuf;
    }
    return m_singleInst;
}

VFX_IMPLEMENT_CLASS("VappCCACui", VappCCACui, VfxCui);

VfxWChar VappCCACui::m_pinBuf[] = {0,};

VappCCACui::VappCCACui()
{
    m_state = MMI_STATE_IDLE;
    m_screen = NULL;
    m_pinScreen = NULL;
    m_instId = 0;
}

VappCCACui::~VappCCACui()
{
}

void VappCCACui::onInit()
{
    VfxCui::onInit();
    VappCCAInstMgr *instMgr = VFX_OBJ_GET_INSTANCE(VappCCAInstMgr);
    instMgr->m_eventSignal.connect(this, &VappCCACui::onCCAEvent);
    instMgr->addInst(this);
}

void VappCCACui::onRun(void* args, VfxU32 argSize)  
{   
    VfxCui::onRun(args, argSize);    
    VappCCACui *app = (VappCCACui *)VfxApp::getObject(VAPP_CCA);
    if(NULL != app)
    {
        app->setInstId(app->getGroupId());
    }
    
    VappCCAInstMgr *instMgr = VFX_OBJ_GET_INSTANCE(VappCCAInstMgr);
    mmi_event_struct *evt = (mmi_event_struct *)args;
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_CCA_VERIFY_PIN:  
        {           
            instMgr->m_eventSignal.emit(VAPP_CCA_EVENT_PIN_CHECK, evt);
            break;
        }
        case EVT_ID_SRV_CCA_PRE_INSTALL:
        {          
            instMgr->m_eventSignal.emit(VAPP_CCA_EVENT_PRE_INSTALL, evt);
            break;
        }
        default:
            return;
    }    
}

void VappCCACui::onDeinit()
{
    VfxCui::onDeinit();
    VappCCAInstMgr *instMgr = VFX_OBJ_GET_INSTANCE(VappCCAInstMgr);
    instMgr->m_eventSignal.disconnect(this, &VappCCACui::onCCAEvent);
    instMgr->removeInst(this);
}

VfxAppCloseAnswerEnum VappCCACui::onProcessClose(VfxAppCloseOption options)
{
    switch(getState())
    {            
        case MMI_STATE_PIN:
        {
            applyPinVerifyCancel();
        }
        break;
            
        case MMI_STATE_PRE_INSTALL: 
        case MMI_STATE_INSTALL_LIST:
        case MMI_STATE_INSTALL_RESULT:
        {
            installFinished();
        }
        break;
            
        case MMI_STATE_IDLE:    
        case MMI_STATE_INSTALLING:
        break;
            
        default:
            return VfxCui::onProcessClose(options);
    }
    return VFX_APP_CLOSE_ANSWER_YES;
}

void VappCCACui::onCCAEvent(vapp_cca_event_enum event, mmi_event_struct *data)
{
    switch(event)
    {
        case VAPP_CCA_EVENT_PIN_CHECK:
        {
            showPinVerify(data);
        }
        break;
            
        case VAPP_CCA_EVENT_PRE_INSTALL:
        {
            showPreInstall(data);
        }
        break;
                       
        case VAPP_CCA_EVENT_INSTALL_RESULT:
        {
            showInstallResult(data);
        }
        break;
            
        case VAPP_CCA_EVENT_INSTALL_FINISHED:
        {
            terminate();
        }
        break;
			
        default:
            return;
    }
}

void VappCCACui::onScreenSel(screen_sel_result_enum result, VappCCAMMIDataPack* data)
{
    switch(result)
    {
        case SCREEN_SEL_PIN:
        {
            VfxWString *pin;
            VfxWChar *pinBuf;
            VappCCAEventSimpleObject *simpObj;
            simpObj = (VappCCAEventSimpleObject*)data->getData(0);
            pin = (VfxWString*)simpObj->m_value;
            pinBuf = (VfxWChar*)pin->getBuf();
            applyPinVerify(pinBuf);
        }
        break;
            
        case SCREEN_SEL_PIN_CANCEL:
        {
            applyPinVerifyCancel();
        }
        break;

        case SCREEN_SEL_INSTALL:
        {
            install(data);
        }
        break;
			
        case SCREEN_SEL_INSTALL_CANCEL:
        case SCREEN_SEL_INSTALL_RESULT:
        {
            installFinished();
        }
        break;
        
        case SCREEN_SEL_INVALID_PIN_POPUP_OK:
        {
            setState(MMI_STATE_PIN_FAIL);
            applyPinVerifyCancel();
        }
        break;
            
        case SCREEN_SEL_POPUP_OK:
        {
            onPopupSel();
        }
        break;
            
        default:
        break;
    }
}

void VappCCACui::openMainScreen(void)
{
    VFX_OBJ_CREATE(m_screen, VappCCAScreen, this);
    m_screen->m_screenSelSignal.connect(this, &VappCCACui::onScreenSel);
    m_screen->show();
}

void VappCCACui::closeMainScreen(void)
{
    if (m_screen)
    {
        m_screen->exit();
        m_screen = NULL;
    }
}

void VappCCACui::openPinScreen(void)
{
    if (!m_pinScreen)
    {
        VFX_OBJ_CREATE(m_pinScreen, VappCCAPinScreen, this);
        m_pinScreen->m_screenSelSignal.connect(this, &VappCCACui::onScreenSel);
        m_pinScreen->show();
    }
}

void VappCCACui::closePinScreen(void)
{
    if (m_pinScreen)
    {
        m_pinScreen->exit();
        m_pinScreen = NULL;
    }
}

void VappCCACui::showPinVerify(mmi_event_struct *data)
{
    srv_cca_evt_verify_pin_struct *paramData = (srv_cca_evt_verify_pin_struct*)data;    
    popup_type_enum popupType;

    openPinScreen();
    setState(MMI_STATE_PIN);
    setCCAHandle(paramData->h_cca);
    
    switch(paramData->status)
    {
        case SRV_CCA_VERIFY_PIN_STATUS_REQ:
        {
            if (m_pinScreen)
            {
                m_pinScreen->showPinVerify();
            }
        }
        return;
            
        case SRV_CCA_VERIFY_PIN_STATUS_MEM_FULL:
        {
            popupType = POPUP_TYPE_MEM_FULL;
        }
        break;
            
        case SRV_CCA_VERIFY_PIN_STATUS_ABORT:
        {
            popupType = POPUP_TYPE_PIN_ABORT;
        }
        break;
            
        case SRV_CCA_VERIFY_PIN_STATUS_RETRY:
        {
            if (paramData->cur_attempt > paramData->max_attempts)
            {
                popupType = POPUP_TYPE_PIN_MAX_RETRY;
                break;
            }
            popupType = POPUP_TYPE_PIN_RETRY;
            if (m_pinScreen)
            {
                m_pinScreen->showPopup(popupType);
            }
        }
        return;
            
        case SRV_CCA_VERIFY_PIN_STATUS_FAIL:
        {
            popupType = POPUP_TYPE_PIN_FAIL;
        }
        break;
            
        case SRV_CCA_VERIFY_PIN_STATUS_PASS:
        {
            if (m_pinScreen)
            {
                m_pinScreen->closePinVerify();
            }
        }
        return;

        default:
        {
            VFX_ASSERT(0);
            setState(MMI_STATE_IDLE);
        }
        return;
    }

    if (m_pinScreen)
    {
        m_pinScreen->showPopup(popupType);
        m_pinScreen->closePinVerify();
    }
    
}

void VappCCACui::showInstallResult(mmi_event_struct *data)
{
    srv_cca_evt_post_install_struct *postInfo = (srv_cca_evt_post_install_struct*)data;
    VappCCAMMIDataPack *pack;
    VappCCAInstallInfoItem *item;
    VappCCAEventSimpleObject *simpObj;
    VfxS32 i;

    MMI_TRACE(TRACE_GROUP_9, TRC_MMI_VAPP_CCA_CUI_SHOWINSTALLRESULT);
	
    setState(MMI_STATE_INSTALL_RESULT);

    setCCAHandle(postInfo->h_cca);
    
    VFX_OBJ_CREATE(pack, VappCCAMMIDataPack, this);
    VFX_OBJ_CREATE(simpObj, VappCCAEventSimpleObject, this);

    /* 1st thing in pack indicates whether the msg has been installed*/
    simpObj->m_value = (VfxS32)postInfo->msg_config_result;
    pack->addData(simpObj);
    
    for (i = 0; i < postInfo->config_num; i++)
    {
        VFX_OBJ_CREATE(item, VappCCAInstallInfoItem, this);
        
        item->m_appId = postInfo->app_config_result[i].config_id;
        item->m_state = postInfo->app_config_result[i].result;

        /* For each AP*/
        pack->addData(item);
    }
    if (m_screen)
    {
        m_screen->showInstallResult(pack);
        m_screen->closeInstallList();
    }
}

void VappCCACui::showPreInstall(mmi_event_struct *data)
{
    srv_cca_evt_pre_install_struct *preInfo = (srv_cca_evt_pre_install_struct*)data;
    VappCCAMMIDataPack *pack;
    VappCCAInstallInfoItem *item;
    VappCCAEventSimpleObject *simpObj;
    VfxS32 i;
    VfxS32 dataAccountIdx = -1;

    MMI_TRACE(TRACE_GROUP_9, TRC_MMI_VAPP_CCA_CUI_SHOWPREINSTALL);
	
    setState(MMI_STATE_PRE_INSTALL);
    openMainScreen();
    closePinScreen();
    
    setCCAHandle(preInfo->h_cca);
    setBoxMsg(preInfo->is_msg_from_box? VFX_TRUE: VFX_FALSE);
    
    VFX_OBJ_CREATE(pack, VappCCAMMIDataPack, this);
    VFX_OBJ_CREATE(simpObj, VappCCAEventSimpleObject, this);

    /* 1st thing in pack indicates whether the msg has been installed*/
    simpObj->m_value = (VfxS32)preInfo->has_config_result;
    pack->addData(simpObj);
    
    for (i = 0; i < preInfo->config_num; i++)
    {
        if (preInfo->app_config_result[i].config_id == SRV_CCA_CONFIG_DTACCT)
        {
            dataAccountIdx = i;
        }
    }
    for (i = 0; i < preInfo->config_num; i++)
    {
        VFX_OBJ_CREATE(item, VappCCAInstallInfoItem, this);
        
        item->m_appId = preInfo->app_config_result[i].config_id;
        item->m_id = i;
        item->m_dependId = dataAccountIdx;
        if (i != dataAccountIdx &&
            (preInfo->app_config_result[i].result == SRV_CCA_STATUS_OK ||
            preInfo->app_config_result[i].result == SRV_CCA_STATUS_SETTING_UPDATED))
        {
            item->m_selected = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
        else
        {
            item->m_selected = VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        if (!preInfo->has_config_result)
        {
            item->m_state = SRV_CCA_STATUS_SETTING_NOT_INSTALLED;
        }
        else
        {
            item->m_state = preInfo->app_config_result[i].result;
        }

        /* For each AP*/
        pack->addData(item);
    }

    if (m_screen)
    {
        m_screen->showPreInstall(pack);
    }
}

void VappCCACui::install(VappCCAMMIDataPack *data)
{
    srv_cca_act_para_start_install_struct act;
    VappCCAInstallInfoItem *item;
    VfxS32 num;
    VfxS32 i;
    VfxS32 selNum = 0;
    
    num = data->getDataCount() - 1;
    if (num > SRV_CCA_MAX_APPS)
    {
        VFX_ASSERT(0);
        num = SRV_CCA_MAX_APPS;
    }
    act.h_cca = getCCAHandle();
    act.has_selected = (kal_bool)(num != 0);
    act.sel_config_num = num;

    for (i = 1; i <= num; i++)
    {
        item = (VappCCAInstallInfoItem*)data->getData(i);
        if (item->m_selected == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            act.sel_config_ids[selNum++] = item->m_appId;
        }
    }
    act.sel_config_num = selNum;

    srv_cca_apply_action(getCCAHandle(), SRV_CCA_ACTION_TYPE_START_INSTALL, &act, sizeof(act));
    setState(MMI_STATE_INSTALLING);
}

void VappCCACui::installFinished(void)
{
    srv_cca_evt_install_finished_struct info;

    info.h_cca = getCCAHandle();;
    info.is_msg_from_box = (kal_bool)getBoxMsg();
    srv_cca_apply_action(getCCAHandle(), SRV_CCA_ACTION_TYPE_INSTALL_COMPLETE, &info, sizeof(info));
}

void VappCCACui::onPopupSel(void)
{
    if (getState() == MMI_STATE_PIN)
    {
        if (m_pinScreen)
        {
            m_pinScreen->showPinVerify();
        }
        return;
    }
    terminate();
}

void VappCCACui::applyPinVerify(VfxWChar *buf)
{
    setPinBuf(buf);
    srv_cca_apply_action(getCCAHandle(), SRV_CCA_ACTION_TYPE_PIN_INPUT, m_pinBuf, sizeof(m_pinBuf));
}

void VappCCACui::applyPinVerifyCancel(void)
{
    srv_cca_apply_action(getCCAHandle(), SRV_CCA_ACTION_TYPE_PIN_ABORT, NULL, 0);
    #ifndef __MMI_PROV_IN_UM__
    if (m_pinScreen)
        m_pinScreen->exit();
    #endif
}

void VappCCACui::setPinBuf(VfxWChar* buf)
{
    if (!buf)
    {
        m_pinBuf[0] = 0;
    }
    else
    {
        kal_wstrcpy(m_pinBuf, buf);
    }
}

void VappCCACui::terminate(void)
{
    if (m_instId)
    {
        VfxAppLauncher::terminate(m_instId);
    }
}

#endif  /* __MMI_CCA_SUPPORT__ */

