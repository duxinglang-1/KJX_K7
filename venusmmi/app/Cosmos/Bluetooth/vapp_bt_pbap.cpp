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
 *  vapp_bt_pbap.cpp
 *
 * Project:
 * --------
 *  Cosmos
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C" {
#include "MMI_features.h"
}

#ifdef __MMI_PBAP_SUPPORT__

extern "C" {
 
#include "BTcmSrvGprot.h"
#include "Conversions.h"
#include "PbapSrvGprot.h"
#include "MMI_conn_app_trc.h"

}
#include "vapp_platform_context.h" // for VappPlatformContext
#include "mmi_rp_vapp_bt_main_def.h"
#include "Vapp_bt_server.h"
#include "Vapp_bt_pbap.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VfxS32 VbtPbapService::m_srvHd = 0;;
VappBTPBAPServer* VappBTPBAPServer::m_inst = NULL;

/***************************************************************************** 
 * Function
 *****************************************************************************/
void vapp_pbap_init(void *param)
{
  VbtPbapService::onInit();
}

void vapp_pbap_deinit(void *param)
{
    VbtPbapService::onDeInit();
}

void VbtPbapService::onInit(void)
{
    srv_pbap_init();
    
    m_srvHd = srv_pbap_open();

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PBAP_INIT, m_srvHd);
    VfxU32 event_mask =  SRV_PBAP_EVENT_AUTHORIZE_NOTIFY |
                         SRV_PBAP_EVENT_AUTHENTICATION_NOTIFY |
                         SRV_PBAP_EVENT_CONN_NOTIFY |
                         SRV_PBAP_EVENT_DISCONN_NOTIFY;

    srv_pbap_set_notify(m_srvHd, event_mask, &VappBTPBAPServer::serviceEventHandle);
}

void VbtPbapService::onDeInit(void)
{
    srv_pbap_deinit();
    m_srvHd = 0;
}


VFX_IMPLEMENT_CLASS("VappBTPBAPServer", VappBTPBAPServer, VbtServer);

VfxS32 VappBTPBAPServer::serviceEventHandle(VfxS32 handle, VfxU32 eventId, void *para)
{
    if (VbtPbapService::m_srvHd == handle)
    {   
        switch(eventId)
        {
            case SRV_PBAP_EVENT_AUTHORIZE_NOTIFY:
				{
					srv_pbap_auth_notify_struct *auth_notify = (srv_pbap_auth_notify_struct *)para;

					VFX_OBJ_CREATE(m_inst, VappBTPBAPServer, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
					VbtServerAgent::launchServer(m_inst, &(auth_notify->bt_addr));					
                    m_inst->m_connId = auth_notify->conn_id;
                    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PBAP_AUTHORIZE_IND, VappBTPBAPServer::m_inst->m_connId);
				}
				
                break;

            case SRV_PBAP_EVENT_AUTHENTICATION_NOTIFY:
                {
                    memcpy(&(m_inst->authticationPara), para, sizeof(srv_pbap_authentication_notify_struct));
                    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BT_ACCESS_REQ,
                                               MMI_EVENT_INFO,
                                               (mmi_noti_scrn_func_ptr)&VappBTPBAPServer::nmgrHandler,
                                               NULL);
                }
                break;

            case SRV_PBAP_EVENT_DISCONN_NOTIFY:
                mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ,
                    (mmi_noti_scrn_func_ptr)&VappBTPBAPServer::nmgrHandler,
                    NULL);
                m_inst->stop();
                break;
			default:
				break;
        }

        return SRV_PBAP_RESULT_OK;
    }
    return SRV_PBAP_RESULT_INVALID_HANDLE;
}

void VappBTPBAPServer::onAuthorizeDone(VfxBool result)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PBAP_AUTHORIZE_DONE, result);
        
	if (result)
	{
		srv_pbap_accept_conn(VbtPbapService::m_srvHd, NULL);
	}
	else
	{
		srv_pbap_reject_conn(VbtPbapService::m_srvHd);
	}
}

void VappBTPBAPServer::obexAuthticationLaunch(void* arg)
{
    m_inst->m_gid = VfxAppLauncher::launch(
                    VAPP_BT_OBEX_AUTHTICATION,
                    VFX_OBJ_CLASS_INFO(VappBTObexAuthticationApp),
                    GRP_ID_ROOT,
                    arg,
                    sizeof(srv_pbap_authentication_notify_struct));
}
    
VfxBool VappBTPBAPServer::nmgrHandler(mmi_scenario_id secnarioId, void* arg)
{
    mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
    VappBTPBAPServer::obexAuthticationLaunch(&m_inst->authticationPara);
    return VFX_TRUE;
}


void VappBTObexAuthticationScreen::onAuthenPopupBarClick(VfxObject *sender, VcpInputPopupButtonEnum Id)
{	
	VfxWString inputText;
	switch(Id)
	{
		case VCP_INPUT_POPUP_BTN_OK:
            
            VfxU8 input_buf[SRV_BT_CM_BD_FNAME_LEN];
			inputText = ((VcpInputPopup *)sender)->getText();
            
            mmi_ucs2_to_asc((CHAR *) input_buf,(CHAR *)inputText.getBuf());

            srv_pbap_accept_conn(VbtPbapService::m_srvHd, input_buf);   
					
			break;
			
		case VCP_INPUT_POPUP_BTN_CANCEL:

            srv_pbap_reject_conn(VbtPbapService::m_srvHd);
			break;
	}
    VFX_OBJ_CLOSE(sender);
    VfxAppLauncher::terminate(VappBTPBAPServer::m_inst->getGid());
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
}

void VappBTPBAPServer::onStop(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_PBAP_STOP);
    srv_bt_cm_stop_conn(m_connId);
    VbtServer::onStop();    
}

VFX_IMPLEMENT_CLASS("VappBTObexAuthticationApp", VappBTObexAuthticationApp, VfxApp);
//VFX_IMPLEMENT_CLASS("VappBTObexAuthticationScreen", VappBTObexAuthticationScreen, VfxAppScr);

void VappBTObexAuthticationApp::onRun(void* args, VfxU32 size)
{
    VfxApp::onRun(args, size);

    VappBTObexAuthticationScreen* scr;
    VFX_OBJ_CREATE(scr, VappBTObexAuthticationScreen, this);
    scr->show();
    scr->showAuthticationPopup(args);
}

void VappBTObexAuthticationScreen::showAuthticationPopup(void* arg)
{
    VcpInputPopup *authenPopup;
    VFX_OBJ_CREATE(authenPopup, VcpInputPopup, this);

    VfxWChar devName[SRV_BT_CM_BD_NAME_UCS2_LEN];
    srv_pbap_authentication_notify_struct *authNotify = (srv_pbap_authentication_notify_struct*)arg;
    mmi_chset_utf8_to_ucs2_string((VfxU8*)devName, SRV_BT_CM_BD_NAME_UCS2_LEN, (VfxU8*)(authNotify->dev_name));
      
    VfxU16 ui_buf[40];
    mmi_wcscpy(ui_buf, (U16 *)L"PBAP AUTHTICATION:");
    mmi_wcscat(ui_buf, (U16*)L":");

    authenPopup->setTitle(VFX_WSTR_MEM(ui_buf));
    authenPopup->setIME(IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
    authenPopup->setAutoDestory(VFX_FALSE);
    authenPopup->m_signalButtonClicked.connect(this, &VappBTObexAuthticationScreen::onAuthenPopupBarClick);
    authenPopup->show(VFX_TRUE);
}
#endif //__MMI_PBAP_SUPPORT__

