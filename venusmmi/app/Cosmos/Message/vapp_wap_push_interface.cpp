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
 *  vapp_XXX.cpp
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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


#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_wap_push_interface.h"
#include "vapp_wap_push_notification.h"
#include "vcp_global_popup.h"
#include "mmi_rp_vapp_wap_push_def.h"
#include "mmi_rp_vapp_wap_push_launch_viewer_def.h"
#include "mmi_rp_srv_status_icons_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "WAPPushSrvProts.h"
#include "WAPPushSrvTypes.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
 #include "MessagesMiscell.h"
#ifdef __MMI_PUSH_IN_UM__

#include "UMSrvDefs.h"

#endif /* __MMI_PUSH_IN_UM__ */

#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VfxS32 g_highConfirmPopupHandle = 0;
static VappPushNotificationParam g_arg;//VappPushNotificationParam *g_arg = NULL;
#ifdef BROWSER_SUPPORT
#define VAPP_PUSH_URL_LGTH  255
static VfxWChar g_ucs2url[256];
#endif

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VfxAppWapPushInterface);
MMI_BOOL launchHighMessage(mmi_scenario_id scen_id, void *arg)
{
    VfxAppLauncher::launch(
        VAPP_WAP_PUSH_LAUNCH_VIEWER,
        VFX_OBJ_CLASS_INFO(VappPushNotificationApp),
        GRP_ID_ROOT, &g_arg, sizeof(VappPushNotificationParam));
    return MMI_TRUE;
}

mmi_ret postLaunchHighMsg (mmi_event_struct *param)
{
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_WAP_PUSH, MMI_EVENT_NON_TONE, launchHighMessage, NULL);	
    return MMI_RET_OK;
}

void onHighMsgConfirm(VfxId id, void *userData)
{
    if (g_highConfirmPopupHandle != 0)
    {
        g_highConfirmPopupHandle = 0;
    }		
	
    srv_wap_push_idle_messge_queue_struct *message = NULL;
    message = srv_wap_push_get_first_msg ();

    if (message == NULL)
    {
        srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY);
        if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
        {
            VfxAppWapPushInterface::displayPopup(STR_GLOBAL_NOT_AVAILABLE, SRV_WAP_PUSH_EVENT_PROPLEM);
        }
        return;
    }

    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        g_arg.msg_id=message->message_id;
        if(message->msg_type == WAP_PMG_MSGTYPE_SI)
        {
            g_arg.msg_type = 1;
        }        
        else
        {
            g_arg.msg_type = 0;
        }        

        //VfxApp::postInvoke(postLaunchHighMsg, arg);	
        VfxApp::postInvoke(postLaunchHighMsg, NULL);
        srv_wap_push_delete_from_msg_queue(message->message_id);
    }
    else
    {
        srv_wap_push_delete_from_msg_queue(message->message_id);
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
}

void vapp_wap_push_notification_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_wap_push_idle_messge_queue_struct *message = NULL;
    message = srv_wap_push_get_first_msg ();

    VfxWString str = VFX_WSTR_RES(STR_ID_VAPP_PUSH_NEW_SERVICE_MESSAGE_FROM);
    str += VFX_WSTR_STATIC((VfxWChar *)message->msg_info);
    VfxWString buttonName;

    if(message->msg_type == WAP_PMG_MSGTYPE_SI)
    {
        str += VFX_WSTR_RES(STR_ID_VAPP_PUSH_VIEW_IT);
        buttonName = VFX_WSTR_RES(STR_GLOBAL_VIEW);	
    }
    else
    {
        str += VFX_WSTR_RES(STR_ID_VAPP_PUSH_LAUNCH_IT_BY_BROWSER);
        buttonName = VFX_WSTR_RES(STR_ID_VAPP_PUSH_LAUNCH_SL_BY_BROWSER);		
    }
    g_highConfirmPopupHandle = vcp_global_popup_show_confirm_two_button_str(
                                    GRP_ID_ROOT,
                                    VCP_POPUP_TYPE_QUESTION,
                                    str,
                                    buttonName,
                                    VFX_WSTR_RES(STR_ID_VAPP_PUSH_IGNORE),
                                    VCP_POPUP_BUTTON_TYPE_NORMAL,
                                    VCP_POPUP_BUTTON_TYPE_NORMAL,
                                    onHighMsgConfirm,
                                    NULL
                                    );

}

MMI_BOOL vapp_wap_push_handle_high_message(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (g_srv_wap_push_cntxt->message_queue_front != NULL)
    {
        vapp_wap_push_notification_launch();
    }
    else
    {
        srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY); /*Message has been deleted*/
    }


    return MMI_TRUE;
}

#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_service_initiation_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onServiceInitiationReq(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_PUSH_IN_UM__
    srv_wap_push_service_init_struct *evt_init = (srv_wap_push_service_init_struct*)evt;
    wps_pmg_dlg_sia_confirm_req_struct *data = (wps_pmg_dlg_sia_confirm_req_struct*) (evt_init->msg);
    VappWapPushNCenterHdlr *wapPushNCenter = VFX_OBJ_GET_INSTANCE(VappWapPushNCenterHdlr);

    VfxWString prefix;

    if (srv_wap_push_enque_dialogue_ex(data->trans_id, WAP_PMG_DLG_SIA_CONFIRM, (S8*)data->host_addr.addr))
    {
        if(!(wapPushNCenter->m_isShow))
        {
            prefix = VFX_WSTR_RES(STR_ID_VAPP_PUSH_SIA_NOTIFICATION);
            wapPushNCenter->showNSSContent(&prefix);
            wapPushNCenter->m_isShow = VFX_TRUE;
            wapPushNCenter->createView();
        }
    }
    else
    {
        VfxAppWapPushInterface::displayPopup(STR_GLOBAL_MEMORY_FULL, SRV_WAP_PUSH_EVENT_PROPLEM);
        srv_wap_push_send_sia_cnf(FALSE, data->trans_id);
    }
	#endif /*__MMI_PUSH_IN_UM__*/
    return MMI_RET_OK;
}
#endif /*WAP_SUPPORT*/

#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  onDlgDataRsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
mmi_ret onDlgDataRsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    srv_wap_push_handle_dlg_data_rsp_struct *evt_dlg_data = (srv_wap_push_handle_dlg_data_rsp_struct*)evt;
    wps_pmg_dlg_query_cnf_struct *data = (wps_pmg_dlg_query_cnf_struct*) evt_dlg_data->msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_HANDLE_DLG_DATA_RSP);
    VappWapPushNCenterHdlr *wapPushNCenter = VFX_OBJ_GET_INSTANCE(VappWapPushNCenterHdlr);
    srv_wap_push_dlg_queue_struct *message = NULL;
    message = srv_wap_push_get_dialogue_date ();
    ASSERT(message);

    switch(wapPushNCenter->m_notificationOption)
    {				
        case VAPP_PUSH_NOTIFICATION_CONFIRM_ACCEPT_AND_ADD_UNKNOWN_ADDR:
        {
            srv_wap_push_initialize_curr_dlg_data((void*)(&(data->dlg_data_union.msg)), WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM);
            srv_wap_push_send_unknwn_addr_cnf(TRUE, g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
            if(srv_wap_push_check_trustlist_full())
            {
                VfxAppWapPushInterface::displayPopup(STR_ID_VAPP_PUSH_TRUST_LIST_FULL, SRV_WAP_PUSH_EVENT_PROPLEM);
                return MMI_RET_OK;
            }            
            srv_wap_push_add_unknwn_addr_to_list(SRV_WAP_PUSH_WHITE_LIST);             
            srv_wap_push_delete_curr_dlg_data();
            srv_wap_push_delete_from_dlg_queue(message->trans_id);	
        }
        break;

        case VAPP_PUSH_NOTIFICATION_CONFIRM_REJECT_AND_ADD_UNKNOWN_ADDR:				
        {
            srv_wap_push_initialize_curr_dlg_data((void*)(&(data->dlg_data_union.msg)), WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM);
            srv_wap_push_send_unknwn_addr_cnf(FALSE, g_srv_wap_push_cntxt->curr_dlg->dlg_data.msg.trans_id);
        #ifdef __MMI_WAP_PUSH_BLACK_LIST__
            if(srv_wap_push_check_blacklist_full())
            {
                VfxAppWapPushInterface::displayPopup(STR_ID_VAPP_PUSH_BLACK_LIST_FULL, SRV_WAP_PUSH_EVENT_PROPLEM); 
                return MMI_RET_OK;
            }                               
        #endif       
            srv_wap_push_add_unknwn_addr_to_list(SRV_WAP_PUSH_BLACK_LIST);                    
            srv_wap_push_delete_curr_dlg_data();
            srv_wap_push_delete_from_dlg_queue(message->trans_id);
        }
        break;
        
        default:
        {
            ASSERT(0);
        }
        break;
    }
    wapPushNCenter->updateCellStatus();
    return MMI_RET_OK;
}
#endif
#endif

#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_service_unknown_addr_req
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
mmi_ret onServiceUnknownAddrReq(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_UNKNOWN_ADDR_REQ);

    srv_wap_push_service_unknown_addr_req_struct* evt_unknown_addr 
        = (srv_wap_push_service_unknown_addr_req_struct*)evt;
    wps_pmg_dlg_unknown_addr_req_struct *data = evt_unknown_addr->msg;

    VfxWString prefix;

    VappWapPushNCenterHdlr *wapPushNCenter = VFX_OBJ_GET_INSTANCE(VappWapPushNCenterHdlr);
    if (srv_wap_push_enque_dialogue_ex(data->trans_id, WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM,(S8*)data->from.addr ))
    {
        if(!(wapPushNCenter->m_isShow))
        {
            prefix = VFX_WSTR_RES(STR_ID_VAPP_PUSH_UNMATCHED_ADDR_NOTIFICATION);
            wapPushNCenter->showNSSContent(&prefix);
            wapPushNCenter->m_isShow = VFX_TRUE;
            wapPushNCenter->createView();
        }
    }
    else
    {
        VfxAppWapPushInterface::displayPopup(STR_GLOBAL_MEMORY_FULL, SRV_WAP_PUSH_EVENT_PROPLEM);
        srv_wap_push_send_unknwn_addr_cnf(FALSE, data->trans_id);
    }	
    return MMI_RET_OK;
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
#endif

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
void VfxAppWapPushInterface::vappWapPushReturnThreeDigitString(VfxU8* StringVal, VfxU8 DigitVal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS8 LocalBuffer[8];
    VfxS8 StrVal[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DigitVal == 0)
    {
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) "000");
    }
    else if (DigitVal < 10)
    {
        sprintf((PS8)LocalBuffer, "00%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    else if (DigitVal < 100)
    {
        sprintf((PS8)LocalBuffer, "0%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    else
    {
        sprintf((PS8)LocalBuffer, "%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    mmi_ucs2cpy((PS8) StringVal, (PS8) StrVal);
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

VfxU32 VfxAppWapPushInterface::vappWapPushGetIcon(VfxU32 msg_status)
{
    return(IMG_ID_WAP_PUSH_VENUS_MESSAGE_LOW_ICON + (msg_status - WAP_PMG_MSGPRIO_LOW));
}

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_progres_evt
 * DESCRIPTION
 *  handles progress event from call back manager
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/

mmi_ret onProgressEvt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_popup_evt
 * DESCRIPTION
 *  handles pop-up event from call back manager
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onPopupEvt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_PUSH_IN_UM__
    srv_wap_push_popup_event_struct *evt_popup = (srv_wap_push_popup_event_struct*)evt; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt_popup->evt_id == EVT_ID_SRV_PUSH_SHOW_POPUP);

    VfxAppWapPushInterface::displayPopup(evt_popup->str_notify, evt_popup->evt_notify);
	#endif /*__MMI_PUSH_IN_UM__*/

    return MMI_RET_OK;
}

void handleHighMessage(U32 message_id, U16 type, CHAR *info_char)
{
    if (!srv_wap_push_enque_msg_ex (message_id, type, info_char))
    {
        VfxAppWapPushInterface::displayPopup(STR_GLOBAL_MEMORY_FULL, SRV_WAP_PUSH_EVENT_PROPLEM);
        srv_wap_push_send_del_req_to_pmg (message_id, PUSH_NEW_MSG_DEL_TRANS_ID);
    }
    else
    {
        if (srv_wap_push_get_notify_nmgr_flag() != SRV_WAP_PUSH_NOTIFY_NMGR_NOTIFY)
        {
            srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOTIFY);
            mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_WAP_PUSH, MMI_EVENT_UNREAD_MSG, vapp_wap_push_handle_high_message, (void *)NULL);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_new_service_msg
 * DESCRIPTION
 *  handles new service messages
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onNewServiceMsg(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_PUSH_IN_UM__
    srv_wap_push_handle_new_service_msg_struct* evt_new_msg = (srv_wap_push_handle_new_service_msg_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_HANDLE_NEW_SERVICE_MSG);
    if (evt_new_msg->enable_push != WAP_PMG_RETR_DISABLED)
    {
        switch(evt_new_msg->new_msg->msg_type)
        {
            case WAP_PMG_MSGTYPE_SL:
            {
                switch (evt_new_msg->new_msg->priority)
                {
                    case WAP_PMG_MSGPRIO_HIGH:
                    {
                        switch(g_push_set_p->general_set.sl_setting)
                        {
                            case SRV_WAP_PUSH_SL_SETTING_DISABLED:
                            {
                                srv_wap_push_send_del_req_to_pmg (evt_new_msg->new_msg->msg_id, PUSH_NEW_MSG_DEL_TRANS_ID);
                            }
                            break;

                            case SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH:
                            {
                                handleHighMessage (evt_new_msg->new_msg->msg_id, WAP_PMG_MSGTYPE_SL, (CHAR*)evt_new_msg->new_msg->from.addr);
                            }
                            break;

                            case SRV_WAP_PUSH_SL_SETTING_PROMPT:    
                            break;
                        }	
                    }
                    break;

                    case WAP_PMG_MSGPRIO_LOW:
                    break;
                }
            }
            break;
            
            case WAP_PMG_MSGTYPE_SI:
            {
                switch (evt_new_msg->new_msg->priority)
                {
                    case WAP_PMG_MSGPRIO_HIGH:
                    {
                        handleHighMessage (evt_new_msg->new_msg->msg_id, WAP_PMG_MSGTYPE_SI, (CHAR*)evt_new_msg->new_msg->from.addr);
                    }
                    break;
                    
                    case WAP_PMG_MSGPRIO_MEDIUM:
                    case WAP_PMG_MSGPRIO_LOW:              	        
                    break;
                }
            }
            break;
        }
    }
    else
    {
        srv_wap_push_send_del_req_to_pmg (evt_new_msg->new_msg->msg_id, PUSH_NEW_MSG_DEL_TRANS_ID);
    }
	#endif /*__MMI_PUSH_IN_UM__*/
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_msg_deleted_by_server_ind_evt
 * DESCRIPTION
 *  handles msg del ind from service
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onMsgDeletedByServerIndEvt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PUSH_IN_UM__
	srv_wap_push_msg_deleted_by_server_ind_struct *evt_msg_del = (srv_wap_push_msg_deleted_by_server_ind_struct*)evt;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_MSG_DELETED_BY_SERVER_IND);

#ifdef __MMI_PUSH_IN_UM__
    srv_wap_push_send_um_refresh_ind(evt_msg_del->msg_id,SRV_UM_REFRESH_MSG_DELETED,NULL);
#endif
#ifdef __MMI_PUSH_IN_UM__
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgDeleteCallback.emit(VFX_TRUE, evt_msg_del->msg_id);
#endif /*__MMI_PUSH_IN_UM__*/
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_del_push_setting_evt
 * DESCRIPTION
 *  Delete Push setting screens
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onDelPushSettingEvt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_ota_list_entry_evt
 * DESCRIPTION
 *  OTA entry
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onOTAlistEntryEvt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_OTA_LIST_ENTRY);
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_OTAlistEntry.emit();
    return MMI_RET_OK;
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

MMI_BOOL launchBrowser(mmi_scenario_id scen_id, void *arg)
{
#ifdef BROWSER_SUPPORT
    wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)g_ucs2url);
#endif /*BROWSER_SUPPORT*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_full_msg_evt
 * DESCRIPTION
 *  handles full message
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onFullMsgEvt(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_handle_msg_struct *evt_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_HANDLE_FULL_MSG);
    evt_msg = (srv_wap_push_handle_msg_struct*)evt;
    if(evt_msg->status == WAP_PMG_STATUS_OK)
    {
        switch(evt_msg->trans_id)
        {
            case PUSH_GET_MSG_ON_IDLE_TRANS_ID:
            break;

            case PUSH_LAUNCH_MSG_URL:
            {
                VfxU16 urr_size = 0;
                VfxS8 *url = (VfxS8 *)evt_msg->url;
                if (url != NULL)
                {
                #ifdef BROWSER_SUPPORT
                    urr_size = vfx_sys_strlen ((VfxChar *)url);
                    if (VAPP_PUSH_URL_LGTH < urr_size)
                    {
                        return MMI_RET_OK;
                    }
                    mmi_asc_to_ucs2((VfxChar*) g_ucs2url, (VfxChar*) url);
                    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_WAP_PUSH, MMI_EVENT_NON_TONE, launchBrowser, NULL);
                #endif /*BROWSER_SUPPORT*/
                    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_lauchMsgURLNotify.emit();
                }
            }
            break;
                
            case PUSH_GET_MSG_TO_DISPLAY_TRANS_ID:
            break;
                
            case PUSH_GET_MSG_TO_DISPLAY_FROM_UM_TRANS_ID:
            {
            #ifdef __MMI_PUSH_IN_UM__
                ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgBodyDispatchCallback.emit(evt_msg->new_msg, (VfxS8 *)evt_msg->url);
                if (g_srv_wap_push_cntxt->read_from_um) //Already sent for high messages
                {
                    srv_wap_push_update_service_msg_req(evt_msg->new_msg->msg_id);
                    srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
                }
                srv_wap_push_send_um_refresh_ind(evt_msg->new_msg->msg_id,SRV_UM_REFRESH_MSG_STATUS_CHANGED ,NULL);
            #endif /* __MMI_PUSH_IN_UM__ */
            }
            break;
                
            case PUSH_GET_MSG_DETAIL_TRANS_ID:
            {
            #ifdef __MMI_PUSH_IN_UM__
            	((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgBodyDispatchCallback.emit(evt_msg->new_msg, (VfxS8 *)evt_msg->url);
            #endif /* __MMI_PUSH_IN_UM__ */
            }
            break;			
          
            default:
            {
                MMI_ASSERT(0);
            }
            break;
        }
    }
    else
    {
        if (evt_msg->trans_id == PUSH_GET_MSG_ON_IDLE_TRANS_ID)
        {
            srv_wap_push_idle_messge_queue_struct *message = NULL;
            message = srv_wap_push_get_first_msg ();
            srv_wap_push_delete_from_msg_queue(message->message_id);
        }
        else
        {
            VfxAppWapPushInterface::displayPopup(STR_GLOBAL_NOT_AVAILABLE, SRV_WAP_PUSH_EVENT_PROPLEM);
        }
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_msg_list_reply
 * DESCRIPTION
 *  handles reply response
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onMsgListReply(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_msg_cnt_rsp
 * DESCRIPTION
 *  handles msg count response
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onMsgCntRsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_draw_unknown_scren
 * DESCRIPTION
 *  draw unknown screen
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onDrawUnknownScren(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_DRAW_UNKNOWN);
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_storage_full_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
 
mmi_ret onStorageFullInd(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
    srv_wap_push_handle_storage_full_ind_struct *evt_storage_full = (srv_wap_push_handle_storage_full_ind_struct*)evt;
    wps_pmg_delete_ind_struct *delete_msg_ind = evt_storage_full->msg;
    //#endif /* __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
    if (delete_msg_ind->msgs[0].msg_id == 0)
    {
        VfxAppWapPushInterface::displayPopup(STR_ID_VAPP_PUSH_STORAGE_FULL, SRV_WAP_PUSH_EVENT_INFO);
        return MMI_RET_OK;
    }
    srv_wap_push_delete_from_msg_queue(delete_msg_ind->msgs[0].msg_id);

#ifdef __MMI_PUSH_IN_UM__
    srv_wap_push_send_um_refresh_ind(delete_msg_ind->msgs[0].msg_id,SRV_UM_REFRESH_MSG_DELETED,NULL);
#endif
    ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgDeleteCallback.emit(VFX_TRUE, delete_msg_ind->msgs[0].msg_id);

    //#else /* __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__ */
    //VfxAppWapPushInterface::displayPopup(STR_ID_VAPP_PUSH_STORAGE_FULL, SRV_WAP_PUSH_EVENT_INFO);
    //#endif /* __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_delete_folder_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onDeleteFolderInd(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_pendig_event_on_idle
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onPendigEventOnIdle(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_push_idle_messge_queue_struct *message = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_wap_push_create_idle_callback_group();
    if (IsKeyPadLockState() == 0)
    {
        if (g_srv_wap_push_cntxt->message_queue_front != NULL)
        {
        //mmi_wap_push_draw_dummy_screen(MMI_TRUE);
            message = srv_wap_push_get_first_msg ();
            MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_IDLE_FOUND_PENDING_MESSAGE, message->message_id);
            srv_wap_push_get_full_message (message->message_id, PUSH_GET_MSG_ON_IDLE_TRANS_ID);
        #ifdef __MMI_PUSH_IN_UM__
            g_srv_wap_push_cntxt->read_from_um = MMI_FALSE;
        #endif /* __MMI_PUSH_IN_UM__ */
        }
        else
        {
            ASSERT(0);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fetch_dlg_from_queue
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onFetchDlgFromQueue(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    //mmi_wap_push_create_idle_callback_group();
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_HDL_IDLE_CALLBACK_FOR_DLG_REQ);
    if (IsKeyPadLockState() == 0)
    {
        srv_wap_push_get_dlg_data_req(g_srv_wap_push_cntxt->dlg_front->trans_id);
    }
    return MMI_RET_OK;
}






/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_mode_finish_switch_event_hdlr
 * DESCRIPTION
 *  handles mode switch
 * PARAMETERS
 *  mmi_event_struct        
 * RETURNS
 *  MMIRESULTENUM
 *****************************************************************************/
mmi_ret onModeFinishSwitchEventHdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_handle_um_enter_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret onUMEnterFolder(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    return MMI_RET_OK;
}

mmi_ret onUpdateIndexingDataFromUM(mmi_event_struct *param)
{
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_push_fetch_dlg_from_queue
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onPushAppInit(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->evt_id == EVT_ID_SRV_PUSH_INBOX_INIT);
    srv_wap_push_set_notify_nmgr_flag(SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY);
    srv_wap_push_init_service_interface();
    srv_wap_push_setting_init();
    srv_wap_push_ui_init();
#ifdef WAP_SUPPORT
    mmi_frm_cb_reg_event(EVT_ID_SRV_PUSH_SERVICE_INIT, onServiceInitiationReq, NULL);
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    mmi_frm_cb_reg_event(EVT_ID_SRV_PUSH_UNKNOWN_ADDR_REQ, onServiceUnknownAddrReq, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_PUSH_HANDLE_DLG_DATA_RSP, onDlgDataRsp, NULL);
#endif /*__MMI_WAP_PUSH_WHITE_LIST__*/
#endif /*WAP_SUPPORT*/
    return MMI_RET_OK;
}
mmi_nmgr_balloon_type_enum VfxAppWapPushInterface::vappWapPushGetBalloonType (VfxU32 event_id)
{
    if(event_id <= SRV_WAP_PUSH_EVENT_PROGRESS)
    {
        return (mmi_nmgr_balloon_type_enum)(MMI_NMGR_BALLOON_TYPE_FAILURE + (event_id - SRV_WAP_PUSH_EVENT_FAILURE));
    }    
    switch (event_id)
    {
        case SRV_WAP_PUSH_EVENT_PROPLEM:
            return MMI_NMGR_BALLOON_TYPE_FAILURE; 

        case SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED:
        case SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED:
            return MMI_NMGR_BALLOON_TYPE_WARNING;

        default:
            return MMI_NMGR_BALLOON_TYPE_FAILURE;      

    }
    
}

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
VfxU32 VfxAppWapPushInterface::vappWapPushGetErrorStrID (VfxU32 errCode)
{
    switch (errCode)
    {
        case SRV_WAP_PUSH_TL_NO_FIELD_ERROR:
            return STR_ID_VAPP_PUSH_ATLEAST_ONE_FIELD_REQUIRED;

        case SRV_WAP_PUSH_TL_INVALID_SENDER:
            return STR_ID_VAPP_PUSH_SETTING_INVALID_SENDER;

        case SRV_WAP_PUSH_TL_INVALID_SMSC:
            return STR_ID_VAPP_PUSH_SETTING_INVALID_SMSC;

        case SRV_WAP_PUSH_TL_INVALID_IP:
            return STR_ID_VAPP_PUSH_INVALID_IP;

        case SRV_WAP_PUSH_TL_SAME_ENTRY:
            return  STR_ID_VAPP_PUSH_SAME_ITEM_EXIST;

        default:
            return STR_GLOBAL_ERROR;
    }
}
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

void VfxAppWapPushInterface::displayPopup(VfxU16 stringId, VfxU32 event_id)
{
    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_WAP_PUSH,
        MMI_EVENT_INFO_BALLOON/*VfxAppWapPushInterface::vappWapPushMapInternalEvent(event_id)*/,
        VfxAppWapPushInterface::vappWapPushGetBalloonType(event_id),
        (WCHAR*)(VFX_WSTR_RES(stringId).getBuf()));
}

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
VfxBool VfxAppWapPushInterface::addrString2Ipv4(VfxChar *src, VfxU8 *dst, VfxU16 dst_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 i, j, len;
    VfxChar *p;
    VfxChar tmp[VAPP_PUSH_IPV4_STR_MAX_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(src);
    if (len == 0 || dst == NULL || dst_size < VAPP_PUSH_IPV4_BYTE_NUM)
    {
        return 0;
    }
    memset(dst, 0x0, dst_size);
    memcpy(tmp, src, VAPP_PUSH_IPV4_STR_MAX_LEN);
    src = tmp;
    for (i = 0; i < VAPP_PUSH_IPV4_BYTE_NUM; i++)
    {
        if ((p = strchr(src, '.')) != NULL)
        {
            *p = '\0';
            if(3 == i)
            {
                return 0;
            }
        }
        else if (i != 3)
        {
            return 0;
        }
        len = strlen(src);
        if (len == 0 || len > 3)
        {
            return 0;
        }
        p = src;
        for (j = 0; j < len; j++)
        {
            if (!VAPP_PUSH_IS_DIGIT(p[j]))
            {
                return 0;
            }
        }
        if (atoi(src) > 255)
        {
            return 0;
        }
        dst[i] = (kal_uint8)atoi(src);
        src += len + 1;
    }
    return 1;
}

#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

/*****************************************************************************
 * FUNCTION
 *  onProcessDeleteAllMsgRsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onProcessDeleteAllMsgRsp(mmi_event_struct* evt)
{
    

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
    
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  onProcessDeleteMsgRsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onProcessDeleteMsgRsp(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_wap_push_delete_msg_cnf_struct *msg_evt = (srv_wap_push_delete_msg_cnf_struct *)evt;

    wps_pmg_delete_msg_cnf_struct *delete_msg_rsp = (wps_pmg_delete_msg_cnf_struct*) msg_evt->msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_INET_TRC_G4_PUSH, TRC_MMI_BRW_PUSH_HDL_PMG_DEL_RSP, delete_msg_rsp->trans_id, delete_msg_rsp->status);
    srv_wap_push_get_msg_count(WAP_PMG_PARAM_NO, PUSH_UPDATE_ICON_TRANS_ID);
    switch (delete_msg_rsp->trans_id)
    {
        case PUSH_DEL_MESSAGE_GENERIC_TRANS_ID:
        if (delete_msg_rsp->status == WAP_PMG_STATUS_OK)
        {
        #ifdef __MMI_PUSH_IN_UM__
            srv_wap_push_send_um_refresh_ind(delete_msg_rsp->msg_id,SRV_UM_REFRESH_MSG_DELETED,NULL);
        #endif
            ((VfxAppWapPushInterface *)VFX_OBJ_GET_INSTANCE(VfxAppWapPushInterface))->m_msgDeleteCallback.emit(VFX_FALSE, delete_msg_rsp->msg_id);
        }
        break;

        default:
        break;
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  onDisplayErrorDlg
 * DESCRIPTION
 *
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onDisplayErrorDlg(mmi_event_struct* evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_wap_push_error_dlg_struct *msg_evt = (srv_wap_push_error_dlg_struct *)evt;
    wps_pmg_error_dlg_struct *message = (wps_pmg_error_dlg_struct*)msg_evt->msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    VfxAppWapPushInterface::displayPopup((U16)message->str_id, SRV_WAP_PUSH_EVENT_FAILURE);
    return MMI_RET_OK;

}

#ifdef __MMI_PUSH_IN_UM__

/*****************************************************************************
 * FUNCTION
 * onDeleteAllRsp
 * DESCRIPTION
 *  Dispatch Function to Handle Mark Several Response from UM.
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret onDeleteAllRsp(mmi_event_struct* evt)
{
    return MMI_RET_OK;
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__

/*****************************************************************************
 * FUNCTION
 * onUMMarkSeveralRsp
 * DESCRIPTION
 *  Dispatch Function to Handle Mark Several Response from UM.
 * PARAMETERS
 *  evt          [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/


mmi_ret onUMMarkSeveralRsp(mmi_event_struct* evt)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/

    return MMI_RET_OK;
}

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_PUSH_IN_UM__ */

#ifdef __cplusplus
}
#endif
