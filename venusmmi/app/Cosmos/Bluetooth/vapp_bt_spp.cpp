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
 *  vapp_bt_spp.cpp
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
#include "MMI_features.h"
#ifdef __MMI_SPP_SUPPORT__
extern "C" {
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "dcl.h"
#include "bluetooth_struct.h"
#include "BtcmSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "SppSrvGprot.h"
}

#include "vapp_platform_context.h" // for VappPlatformContext

#include "vapp_bt_addr.h"
#include "vapp_bt_spp.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VappBTSPPServer* VappBTSPPServer::m_sppServer;
SppHandle VappBTSPPServer::m_handle;

/***************************************************************************** 
 * Function
 *****************************************************************************/
void vapp_spp_init(void *param)
{
	VfxU32 evt_mask = 0;

	srv_spp_init();
	
	VappBTSPPServer::m_handle = srv_spp_open();
	if (VappBTSPPServer::m_handle == SRV_SPP_INVALID_HANDLE) return;
	evt_mask = SRV_SPP_EVENT_BIND_FAIL|
			SRV_SPP_EVENT_AUTHORIZE|
			SRV_SPP_EVENT_CONNECT|
			SRV_SPP_EVENT_READY_TO_WRITE|
			SRV_SPP_EVENT_READY_TO_READ|
			SRV_SPP_EVENT_DISCONNECT;
	srv_spp_set_notify_hdlr(VappBTSPPServer::m_handle,
						evt_mask, 
						&VappBTSPPServer::srvEventHandler,
						NULL
						);
	srv_spp_bind(VappBTSPPServer::m_handle, SRV_BT_CM_SPP_PROFILE_UUID);
}

void vapp_spp_deinit(void *param)
{
	srv_spp_close(VappBTSPPServer::m_handle);
}

VFX_IMPLEMENT_CLASS("VappBTSPPServer", VappBTSPPServer, VbtServer);

VfxS32 VappBTSPPServer::srvEventHandler(VfxU32 evt, void* para)
{
	srv_spp_event_cntx* notifyPara = (srv_spp_event_cntx*)para;
	switch (evt)
	{
	case SRV_SPP_EVENT_BIND_FAIL:
		srv_spp_close(VappBTSPPServer::m_handle);
		break;
	case SRV_SPP_EVENT_AUTHORIZE:
	{
		if (!VappBTSPPServer::m_sppServer)
		{
			srv_bt_cm_bt_addr btAddr;
			srv_spp_get_dev_addr(notifyPara->para, &btAddr);

			VFX_OBJ_CREATE(VappBTSPPServer::m_sppServer, VappBTSPPServer, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
			VbtServerAgent::launchServer(VappBTSPPServer::m_sppServer, &btAddr);	

			VappBTSPPServer::m_sppServer->setConnId(notifyPara->para);
		}
		else srv_spp_reject(notifyPara->para);
		break;
	}
	case SRV_SPP_EVENT_DISCONNECT:
		VbtServerAgent::terminateServer(VappBTSPPServer::m_sppServer);
		break;
	default:
		break;
	}
		return MMI_RET_OK;
}

void VappBTSPPServer::onAuthorizeDone(VfxBool result)
{
	if (result)
		srv_spp_accept(
			m_connId,
			m_buf,
			SRV_SPP_MIN_BUFF_SIZE/2,
			SRV_SPP_MIN_BUFF_SIZE/2
			);
	else
	{
		srv_spp_reject(m_connId);
	}
}

void VappBTSPPServer::setConnId(VfxS32 connId)
{
	m_connId = connId;
}

VfxS32 VappBTSPPServer::getConnId()
{
	return m_connId;
}

VfxU8* VappBTSPPServer::getBuf()
{
	return m_buf;
}
#endif/*__MMI_SPP_SUPPORT__*/

