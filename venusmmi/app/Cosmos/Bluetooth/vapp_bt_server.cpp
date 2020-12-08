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
 *  vapp_bt_server.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C" {
#include "GlobalResDef.h"
#include "Conversions.h"
#include "Mmi_cb_mgr_gprot.h"
#include "MMI_conn_app_trc.h"
}

#include "Vfx_datatype.h"
#include "mmi_rp_vapp_bt_main_def.h"
#include "vapp_bt_server.h"
#include "vapp_nmgr_gprot.h" // for vapp_nmgr_global_popup_show_confirm_two_button_id

/*****************************************************************************
 * Class VbtServerAgent
 *****************************************************************************/
VbtServerAgent *VbtServerAgent::m_selfInstance = NULL;

//VFX_IMPLEMENT_CLASS("VbtServerAgent", VbtServerAgent, VfxApp);

//void VbtServerAgent::onRun(void *args,VfxU32 argSize)
//{
//    VfxApp::onRun(args, argSize);

//    m_selfInstance = this;

//    m_refCount = 0;
//}

VbtServer* VbtServerAgent::launchServer(VbtServer *server, srv_bt_cm_bt_addr* addr)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_BTSERVER_LAUNCH);

 //   if (!m_selfInstance)
 //       VfxAppLauncher::launch(
 //           VAPP_BT_SERVER,
 //           VFX_OBJ_CLASS_INFO(VbtServerAgent),
 //           GRP_ID_ROOT);
    
 //   m_selfInstance->m_refCount++;
    
 //   server = (VbtServer *)classInfo->createObject(m_selfInstance);    
    server->m_devAddr = *addr;
    server->popupHandle = 0;
    server->onStart();

    return server;
}

void VbtServerAgent::terminateServer(VbtServer *instance)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_BTSERVER_TERMINATE);

//    VFX_ASSERT(m_selfInstance && m_selfInstance->m_refCount);
    instance->onStop();
    VFX_OBJ_CLOSE(instance);

}

//VFX_IMPLEMENT_CLASS("VbtServer", VbtServer, VfxObject);

void VbtServer::onStart()
{
    startNmgr();
}

void VbtServer::onStop()
{
	if(popupHandle)
		vapp_nmgr_global_popup_cancel(popupHandle);
}

void VbtServer::stop()
{
    VbtServerAgent::terminateServer(this);
}

void VbtServer::startNmgr()
{	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_BTSERVER_STARTNMGR);
#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_get_authorize(&m_devAddr) == SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT)
    {
    	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_BTSERVER_TRUST_DEV);
        onAuthorizeDone(VFX_TRUE);
        return;
    }
#endif
	showAuthorize();

}

void VbtServer::showAuthorize()
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_BTSERVER_SHOW_AUTHORIZE);
    getDisplayText(m_displayText, &m_devAddr);

	popupHandle = vapp_nmgr_global_popup_show_confirm_two_button_str(
        MMI_SCENARIO_ID_BT_ACCESS_REQ,
        VCP_POPUP_TYPE_QUESTION, 
        m_displayText, 
        VFX_WSTR_RES(STR_ID_VAPP_BT_ACCEPT), 
        VFX_WSTR_RES(STR_ID_VAPP_BT_REJECT),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        &VbtServer::onConfirmDone,
        this);
}

void VbtServer::onConfirmDone(VfxId id, void *userData)
{
    VbtServer* server = (VbtServer*)userData;
	server->popupHandle = 0;
    switch (id)
    {
    case VCP_CONFIRM_POPUP_BUTTON_USER_1:
    	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_BTSERVER_ON_CONFIRMDONE_OK);
        server->onAuthorizeDone(VFX_TRUE);
        break;

    case VCP_CONFIRM_POPUP_BUTTON_USER_2:
    case VCP_POPUP_BUTTON_NO_PRESSED:
    case VCP_CONFIRM_POPUP_BUTTON_CANCEL:
   		MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_BTSERVER_ON_CONFIRMDONE_NO);
        server->onAuthorizeDone(VFX_FALSE);
        break;

    default:
        break;
    }
}

void VbtServer::getDisplayText(VfxWString &text, srv_bt_cm_bt_addr *addr)
{
	VfxWChar devName[SRV_BT_CM_BD_NAME_UCS2_LEN+1];
	VfxWChar* textArray;

	textArray = text.lockBuf(80);
    srv_bt_cm_get_dev_name(&m_devAddr, SRV_BT_CM_BD_FNAME_LEN, (U8*)textArray);
    
    mmi_chset_utf8_to_ucs2_string((VfxU8 *)devName, SRV_BT_CM_BD_NAME_UCS2_LEN, (U8*)textArray);
	mmi_wsprintf(textArray,160,STR_ID_VAPP_BT_ACCEPT_ASK,devName);
	text.unlockBuf();
}

void VbtServer::errorHandle()
{
    WCHAR* str;
    str = (WCHAR*)GetString(STR_ID_VAPP_BT_RECV_FAIL);
    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_BLUETOOTH,
        MMI_NMGR_BALLOON_TYPE_INFO,
        str);
}

