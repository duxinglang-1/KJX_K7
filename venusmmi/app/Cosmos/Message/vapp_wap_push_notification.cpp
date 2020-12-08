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
 *  vapp_wap_push_notification.cpp
 *
 * Project:
 * --------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_wap_push_notification.h"
#include "vapp_wap_push_interface.h"
#include "vapp_wap_push_viewer.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_wap_push_def.h"
#include "vcp_global_popup.h"
#include "vapp_msg_ncenter_gprot.h"
#include "mmi_rp_vapp_msg_def.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */

#include "WAPPushSrvProts.h"
#include "WAPPushSrvTypes.h"


#ifdef __cplusplus
}
#endif /* __CPLUSPLUS__ */



/*****************************************************************************
 * Class VappFirstCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappPushNotificationApp", VappPushNotificationApp, VfxApp);

void VappPushNotificationApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
	VappPushNotificationParam *arg = (VappPushNotificationParam*)args;
	ASSERT(arg);
    VFX_OBJ_CREATE_EX(m_scr, VappPushNotificationScr, this, (arg->msg_id, arg->msg_type));
	m_scr->setGroupID(getGroupId());
    m_scr->show();
}

/***************************************************************************** 
 * Class VappPushNotificationScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappPushNotificationScr", VappPushNotificationScr, VfxMainScr);
VappPushNotificationScr::VappPushNotificationScr(VfxU32 msgId, VfxU32 msgType):
    m_msgId(msgId),
    m_msgType(msgType)   

{	
    if(m_msgType == 0)
    {
        setIsSmallScreen();
    }
}

void VappPushNotificationScr::on1stReady()
{
    VfxMainScr::on1stReady();
	

    g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;
   
	if(m_msgType)
    {
        VappWapPushViewerPage *pushViewerPage;
		VFX_OBJ_CREATE_EX(pushViewerPage, VappWapPushViewerPage, this, (m_msgId));
		pushPage(0, pushViewerPage);
	}
	else
    {
        setBgColor(VFX_COLOR_TRANSPARENT);
		VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
		m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
		m_popup->setText((VfxResId)STR_GLOBAL_PLEASE_WAIT);
		m_popup->setAutoDestory(VFX_FALSE);
		m_popup->show(VFX_TRUE);

		VfxAppWapPushInterface::vappWapPushLauchMsgURL(m_msgId, this,&VappPushNotificationScr::onLauchMsgURLNotify);
	#ifdef  __MMI_BRW_PUSH_DELETE_SL_AFTER_LAUNCH_SUPPORT__
		srv_wap_push_send_del_req_to_pmg (m_msgId, PUSH_DEL_SL_AFTER_LOAD_TRANS_ID);
	#else
		srv_wap_push_update_service_msg_req(m_msgId);
		srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
	#endif /* __MMI_BRW_PUSH_DELETE_SL_AFTER_LAUNCH_SUPPORT__ */

	}
}

void VappPushNotificationScr::onLauchMsgURLNotify(void)
{
#ifdef __MMI_PUSH_IN_UM__
    srv_wap_push_send_um_refresh_ind(m_msgId,SRV_UM_REFRESH_MSG_STATUS_CHANGED ,NULL);
#endif
	m_popup->hide(VFX_TRUE);
    VFX_OBJ_CLOSE(m_popup);
	VfxAppLauncher::terminate(m_groupID);
}

	
void VappPushNotificationScr::onDeinit(void)
{    
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_lauchMsgURLNotify.disconnect(this , &VappPushNotificationScr::onLauchMsgURLNotify);
    VfxMainScr::onDeinit();

    if (srv_wap_push_get_first_msg())
    {
        srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOTIFY);
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_WAP_PUSH, MMI_EVENT_UNREAD_MSG, vapp_wap_push_handle_high_message, (void *)NULL);
    }
    else
    {
    	srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY);
    }	
}

void VappPushNotificationScr::onQueryRotateEx(VfxScreenRotateParam & param)
{
    if(!(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270))
    {
        param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
    }        
}


//******************************************************************************
#ifdef WAP_SUPPORT

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappWapPushNCenterHdlr);

void VappWapPushNCenterHdlr::onInit()
{
	VfxObject::onInit();
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    VfxAppWapPushInterface *wapPushInterface = VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface);
    wapPushInterface->m_trustlistSettingScrActiveCallback.connect(this , &VappWapPushNCenterHdlr::onTrustlistSettingScrActive);
#endif
}

void VappWapPushNCenterHdlr::showNSSContent(VfxWString* previewText)
{
    mmi_frm_nmgr_alert_struct noti;
    memset(&noti, 0, sizeof(mmi_frm_nmgr_alert_struct));
    noti.app_id = VAPP_MSG;
    noti.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;//MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
    noti.alert_option = 0;
    noti.scen_id = MMI_SCENARIO_ID_DEFAULT;
    noti.event_type = MMI_EVENT_UNREAD_MSG;
    noti.behavior_mask = PREFER_STATUS_BAR;
    noti.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    noti.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
    noti.status_bar_para.image.id = IMG_SI_MESSAGE_UNREAD;
    noti.status_bar_para.display_string = (WCHAR*)previewText->getBuf();
    noti.app_proc_para.scrn_group_proc = &onTapNSSCallback;
    noti.app_proc_para.user_data = NULL;
    noti.app_proc_para.data_size = 0;
    noti.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
    noti.popup_para.image_type = MMI_NMGR_IMG_RES_ID;
    noti.popup_para.image.id = IMG_SI_MESSAGE_UNREAD;
    noti.popup_para.popup_string = (WCHAR*)previewText->getBuf();
    VfxWString button_string;
	button_string.loadFromRes(STR_ID_VAPP_MSG_NSS_VIEW);
    noti.popup_para.popup_button_string = (WCHAR*)button_string.getBuf();
    mmi_frm_nmgr_alert(&noti);
}

void VappWapPushNCenterHdlr::createView()
{
    srv_wap_push_dlg_queue_struct *message = NULL;
    message = srv_wap_push_get_dialogue_date ();


    VsrvNGroupSingleTitle *group = NULL;
    VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_MSG));
    group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MSG));

    VsrvNotificationEvent *pNoti;
    VSRV_NOTIFICATION_CREATE_EX(pNoti, VsrvNotificationEvent, ((VsrvNGroup *)group, VAPP_MSG_NCENTER_WAP_PUSH_CELL));
    	
    pNoti->setAutoLaunch(VFX_TRUE);
    pNoti->setAutoClose(VFX_FALSE);
    pNoti->setIcon(VfxImageSrc(IMG_ID_WAP_PUSH_VENUS_MESSAGE_ICON));
    pNoti->setMainText(VFX_WSTR_RES(STR_ID_VAPP_PUSH_SERVICE_MESSAGE));
    if (message->dlg_type == WAP_PMG_DLG_SIA_CONFIRM)
    {
        pNoti->setSubText(VFX_WSTR_RES(STR_ID_VAPP_PUSH_SIA_REQ_TITLE));
    }
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    else
    {
        pNoti->setSubText(VFX_WSTR_RES(STR_ID_VAPP_PUSH_UNMATCHED_ADDRESS));
    }
#endif/*__MMI_WAP_PUSH_WHITE_LIST__*/

    pNoti->setIntentCallback(onTap, (void *)NULL, 0);
    pNoti->setCurrentTime();
    pNoti->notify();
	
}

void VappWapPushNCenterHdlr::updateCellStatus(void)
{
    srv_wap_push_dlg_queue_struct *message = NULL;
    message = srv_wap_push_get_dialogue_date();

    if(message)
    {
        if(!m_popupHandle)
        {
            if (!m_isCellActive)
            {
                VfxWString prefix;
                if(message->dlg_type == WAP_PMG_DLG_SIA_CONFIRM)
                {
                    prefix.loadFromRes(STR_ID_VAPP_PUSH_SIA_NOTIFICATION);
                }
            #ifdef __MMI_WAP_PUSH_WHITE_LIST__
                else
                {
                    prefix.loadFromRes(STR_ID_VAPP_PUSH_UNMATCHED_ADDR_NOTIFICATION);
                }            
            #endif				
                showNSSContent(&prefix);
            }
            createView();
        }
        m_isShow = VFX_TRUE;
    }
    else
    {
        m_isShow = VFX_FALSE;
    }		
}

void VappWapPushNCenterHdlr::connectUnKnownListDataReceive(VfxU32 type)
{
    m_notificationOption = type;
}

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
void VappWapPushNCenterHdlr::onTrustlistSettingScrActive(VfxBool isActive)
{
    if (isActive == VFX_TRUE)
    {
        if (m_isShow == VFX_TRUE)
        {
            m_isCellActive = VFX_TRUE;
            VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_MSG, VAPP_MSG_NCENTER_WAP_PUSH_CELL);
        } 
        m_isShow = VFX_TRUE;
    }
    else
    {
        updateCellStatus();
        m_isCellActive = VFX_FALSE;
    }
}
#endif

static mmi_ret postCall(mmi_event_struct *param)
{
    onShowNsCeContent();
    return MMI_RET_OK;
    
}

extern "C" mmi_ret onTapNSSCallback (mmi_event_struct *param)
{	
    if(param->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH ||
        param->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH)
    {
        mmi_event_struct evt;

        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, postCall, NULL);
    }
    return MMI_RET_OK;
}

void onShowNsCeContent()
{
    VappWapPushNCenterHdlr *pNcenter = VFX_OBJ_GET_INSTANCE(VappWapPushNCenterHdlr);
    srv_wap_push_dlg_queue_struct *message = NULL;
    message = srv_wap_push_get_dialogue_date ();
    pNcenter->m_popupHandle = 0;

    if (message->dlg_type == WAP_PMG_DLG_SIA_CONFIRM)
    {
        VfxWString str;
		str.loadFromRes(STR_ID_VAPP_PUSH_SETUP_CONNECTION);
        str += VFX_WSTR_STATIC((VfxWChar *)message->dl_info);
        str += VFX_WSTR_RES(STR_ID_VAPP_PUSH_QUESTION_MARK);
        pNcenter->m_popupHandle = vcp_global_popup_show_confirm_two_button_str(
            GRP_ID_ROOT,
            VCP_POPUP_TYPE_QUESTION,
            str,
            VFX_WSTR_RES(STR_GLOBAL_ACCEPT),
            VFX_WSTR_RES(STR_ID_VAPP_PUSH_REJECT),
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            onConfirmDialog,
            NULL
            );
    }
    else
    {
    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
        VfxS32 temp;
        VfxWString str;
		str.loadFromRes(STR_ID_VAPP_PUSH_RECEIVE_FROM_ADDRESS);
        str += VFX_WSTR_STATIC((VfxWChar *)message->dl_info);
        str += VFX_WSTR_RES(STR_ID_VAPP_PUSH_QUESTION_MARK);
        temp = vcp_global_popup_show_command_create_str(GRP_ID_ROOT, str, onConfirmUnmatchedAddressDialog, NULL);
        vcp_global_popup_show_command_add_str(temp, VAPP_PUSH_NOTIFICATION_CONFIRM_ACCEPT_UNKNOWN_ADDR, VFX_WSTR_RES(STR_GLOBAL_ACCEPT), VCP_POPUP_BUTTON_TYPE_NORMAL);
        if(srv_wap_push_get_setting_index(SRV_WAP_PUSH_SETTING_ENABLE_WHITE_LIST)==SRV_WAP_PUSH_WL_SETTING_NOTIFY)
        {
            vcp_global_popup_show_command_add_str(temp, VAPP_PUSH_NOTIFICATION_CONFIRM_ACCEPT_AND_ADD_UNKNOWN_ADDR, VFX_WSTR_RES(STR_ID_VAPP_PUSH_ACCEPT_AND_ADD_WL), VCP_POPUP_BUTTON_TYPE_NORMAL);
        }
        vcp_global_popup_show_command_add_str(temp, VAPP_PUSH_NOTIFICATION_CONFIRM_REJECT_UNKNOWN_ADDR, VFX_WSTR_RES(STR_ID_VAPP_PUSH_REJECT), VCP_POPUP_BUTTON_TYPE_NORMAL);
    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
        if(srv_wap_push_get_setting_index(SRV_WAP_PUSH_SETTING_ENABLE_BLACK_LIST)==SRV_WAP_PUSH_BL_SETTING_NOTIFY)
        {
            vcp_global_popup_show_command_add_str(temp, VAPP_PUSH_NOTIFICATION_CONFIRM_REJECT_AND_ADD_UNKNOWN_ADDR, VFX_WSTR_RES(STR_ID_VAPP_PUSH_REJECT_AND_ADD_BL), VCP_POPUP_BUTTON_TYPE_NORMAL);
        }
    #endif
        vcp_global_popup_show_command_show_str(temp);
        pNcenter->m_popupHandle = temp;
    #endif
    }
    VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_MSG, VAPP_MSG_NCENTER_WAP_PUSH_CELL);
}


void onTap(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    VappWapPushNCenterHdlr *pNcenter = VFX_OBJ_GET_INSTANCE(VappWapPushNCenterHdlr);
    if (VSRV_NINTENT_TYPE_LAUNCH == intent.type)
    {		
        onShowNsCeContent();
    }
    if (VSRV_NINTENT_TYPE_CLEAR == intent.type && VFX_TRUE == pNcenter->m_isShow)
    {
        pNcenter->m_isShow = VFX_FALSE;
        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_MSG, VAPP_MSG_NCENTER_WAP_PUSH_CELL);		
    }
}

void onConfirmDialog (VfxId id, void *userData) 
{
    srv_wap_push_dlg_queue_struct *message = NULL;
    message = srv_wap_push_get_dialogue_date ();
    VappWapPushNCenterHdlr *pNcenter = VFX_OBJ_GET_INSTANCE(VappWapPushNCenterHdlr);
    pNcenter->m_popupHandle = 0;

    ASSERT(message);

    switch(id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            srv_wap_push_send_sia_cnf(TRUE, message->trans_id);
            srv_wap_push_delete_from_dlg_queue(message->trans_id);	
            pNcenter->updateCellStatus();	
        }
        break;

        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        {
            srv_wap_push_send_sia_cnf(FALSE, message->trans_id);
            srv_wap_push_delete_from_dlg_queue(message->trans_id);	
            pNcenter->updateCellStatus();	

        }
        break;

        default:
        {
            srv_wap_push_send_sia_cnf(FALSE, message->trans_id);
            srv_wap_push_delete_from_dlg_queue(message->trans_id);	
            pNcenter->updateCellStatus();
        }
        break;
    }
}

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
void onConfirmUnmatchedAddressDialog (VfxId id, void *userData) 
{
    srv_wap_push_dlg_queue_struct *message = NULL;
    message = srv_wap_push_get_dialogue_date ();
    VappWapPushNCenterHdlr *pNcenter = VFX_OBJ_GET_INSTANCE(VappWapPushNCenterHdlr);
    pNcenter->m_popupHandle = 0;

    ASSERT(message);

    switch(id)
    {
        case VAPP_PUSH_NOTIFICATION_CONFIRM_ACCEPT_UNKNOWN_ADDR:
        {
            srv_wap_push_send_unknwn_addr_cnf(TRUE, message->trans_id);
            srv_wap_push_delete_from_dlg_queue(message->trans_id);
            pNcenter->updateCellStatus();
        }
        break;

        case VAPP_PUSH_NOTIFICATION_CONFIRM_ACCEPT_AND_ADD_UNKNOWN_ADDR:
        {
            pNcenter->connectUnKnownListDataReceive(VAPP_PUSH_NOTIFICATION_CONFIRM_ACCEPT_AND_ADD_UNKNOWN_ADDR);
            srv_wap_push_get_dlg_data_req(message->trans_id);
        }
        break;
        
        case VAPP_PUSH_NOTIFICATION_CONFIRM_REJECT_UNKNOWN_ADDR:
        {
            srv_wap_push_send_unknwn_addr_cnf(FALSE, message->trans_id);
            srv_wap_push_delete_from_dlg_queue(message->trans_id);
            pNcenter->updateCellStatus();
        }
        break;

        case VAPP_PUSH_NOTIFICATION_CONFIRM_REJECT_AND_ADD_UNKNOWN_ADDR:		
        {
            pNcenter->connectUnKnownListDataReceive(VAPP_PUSH_NOTIFICATION_CONFIRM_REJECT_AND_ADD_UNKNOWN_ADDR);
            srv_wap_push_get_dlg_data_req(message->trans_id);
        }
        break;

        default:
        {
            srv_wap_push_send_unknwn_addr_cnf(FALSE, message->trans_id);
            srv_wap_push_delete_from_dlg_queue(message->trans_id);	
            pNcenter->updateCellStatus();
        }        	
        break;
    }

}
#endif
#endif



