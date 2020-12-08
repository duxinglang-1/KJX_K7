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
 *  vapp_bt_dun.cpp
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
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_DUN_SUPPORT__

extern "C" {

#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "dcl.h"
#include "bluetooth_struct.h"
#include "BTcmSrvGprot.h"
#include "Conversions.h"
#include "MMI_conn_app_trc.h"

}

#include "vapp_platform_context.h" // for VappPlatformContext

#include "mmi_rp_vapp_bt_main_def.h"
#include "Vapp_bt_server.h"
#include "vapp_bt_dun.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VfxU8 VbtDunService::m_state = DUN_STAT_IDLE;
VfxS32 VappBTDUNServer::m_connId = 0;
DCL_DEV VappBTDUNServer::m_port = uart_port1;
VfxU8 VappBTDUNServer::m_buf[MMI_DUN_BUF_SIZE] = {0};
VappBTDUNServer* VappBTDUNServer::m_inst = NULL;

/***************************************************************************** 
 * Function
 *****************************************************************************/
void vapp_dun_init(void *param)
{
  VbtDunService::onInit();
}

void vapp_dun_deinit(void *param)
{
    VbtDunService::onDeInit();
}


void VbtDunService::onInit(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DUN_INIT);

#if 1 // for slim
	for(VfxU32 i = 0; i < 6; i++)
	{
		mmi_frm_set_protocol_event_handler(MSG_ID_BT_DUN_CONNECT_IND + i,
        	(PsIntFuncPtr)&VbtDunService::onProtocolMessage, MMI_FALSE);
	}
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
    m_state = DUN_STAT_IDLE;
    VappBTDUNServer::m_connId = 0;
    VappBTDUNServer::m_port = uart_port1;

    srv_bt_cm_profile_struct dun_prof;

    dun_prof.profile_id = SRV_BT_CM_DUN_PROFILE_UUID;
    dun_prof.activater = onActivate;
    dun_prof.deactivater = onDeactivate;
    dun_prof.disconnector = onDisconnect;
    
    srv_bt_cm_profile_register((const srv_bt_cm_profile_struct *)&dun_prof);
}

void VbtDunService::onDeInit(void)
{
    m_state = DUN_STAT_IDLE;
    VappBTDUNServer::m_connId = 0;
    VappBTDUNServer::m_port = uart_port1;
    VappBTDUNServer::m_inst = NULL;
}


VfxU8 VbtDunService::onProtocolMessage(void *ilmData, VfxS32 srcModule, ilm_struct *ilm)
{
    switch(ilm->msg_id)
    {
        case MSG_ID_BT_DUN_ACTIVATE_CNF:
            onActivateDone();
            break;

        case MSG_ID_BT_DUN_DEACTIVATE_CNF:
            onDeactivateDone();
            break;

        case MSG_ID_BT_DUN_CONNECT_IND_REQ:
            onAuthStart((void *)ilm->local_para_ptr);
            break;

        case MSG_ID_BT_DUN_CONNECT_IND:
            VappBTDUNServer::m_inst->onConnectDone((void *)ilm->local_para_ptr);
            break;

        case MSG_ID_BT_DUN_DISCONNECT_IND:
        case MSG_ID_BT_DUN_DISCONNECT_CNF:
            if (VappBTDUNServer::m_inst)
            {
                VappBTDUNServer::m_inst->stop();
            }
            break;

        default:
            break;
    }
    return 0;
}

void VbtDunService::onActivate(void)
{
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_ACTIVATE_REQ, NULL, NULL);
}

void VbtDunService::onActivateDone(void)
{       
    srv_bt_cm_activate_cnf_hdler((U32)SRV_BT_CM_DUN_PROFILE_UUID);
    m_state = DUN_STAT_ACTIVATE;
}

void VbtDunService::onDeactivate(void)
{
    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_DEACTIVATE_REQ, NULL, NULL);
}

void VbtDunService::onDeactivateDone(void)
{       
    srv_bt_cm_deactivate_cnf_hdler((U32)SRV_BT_CM_DUN_PROFILE_UUID);
    m_state = DUN_STAT_IDLE;
}

void VbtDunService::onDisconnect(VfxU32 conn_id)
{
    bt_dun_disconnect_req_struct* msg_p = 
        (bt_dun_disconnect_req_struct*)construct_local_para(sizeof(bt_dun_disconnect_req_struct), TD_CTRL);;

    if (conn_id != VappBTDUNServer::m_connId)
        return;
    
    msg_p->port = (DCL_DEV)VappBTDUNServer::m_port;

    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_DISCONNECT_REQ, msg_p,NULL);

    m_state = DUN_STAT_DISCONNECT;
}


VFX_IMPLEMENT_CLASS("VappBTDUNServer", VappBTDUNServer, VbtServer);


void VbtDunService::onAuthStart(void *param)
{
    bt_dun_connect_ind_req_struct *auth_ind = (bt_dun_connect_ind_req_struct *)param;

    srv_bt_cm_bt_addr bt_addr;  
 
    bt_addr.lap = auth_ind->lap;
    bt_addr.uap = auth_ind->uap;
    bt_addr.nap = auth_ind->nap;

    VappBTDUNServer::m_port = (DCL_DEV)auth_ind->port;
          
    if(m_state == DUN_STAT_ACTIVATE)
    {
        m_state = DUN_STAT_AUTHORIZING;
        U8 dev_name[SRV_BT_CM_BD_FNAME_LEN];
        srv_bt_cm_get_dev_name(&bt_addr,SRV_BT_CM_BD_FNAME_LEN,dev_name);

        VappBTDUNServer::m_connId = srv_bt_cm_start_conn(
                                        MMI_TRUE,
                                        SRV_BT_CM_DUN_PROFILE_UUID,
                                        &bt_addr,
                                        (CHAR *)dev_name);

        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DUN_AUTHORIZE_IND, m_state,VappBTDUNServer::m_connId);
        
        if (VappBTDUNServer::m_connId < 0)
        {
            bt_dun_connect_ind_res_struct* auth_rsp = (bt_dun_connect_ind_res_struct*)construct_local_para(sizeof(bt_dun_connect_ind_res_struct),TD_UL);

            auth_rsp->lap = bt_addr.lap;
            auth_rsp->uap = bt_addr.uap;
            auth_rsp->nap = bt_addr.nap;
            auth_rsp->result = (U8)MMI_FALSE;
            auth_rsp->port = auth_ind->port;

            m_state = DUN_STAT_ACTIVATE;

            srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_CONNECT_IND_RES, (void*)auth_rsp, NULL);
            return;
        }

		VFX_OBJ_CREATE(VappBTDUNServer::m_inst, VappBTDUNServer, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
		VbtServerAgent::launchServer(VappBTDUNServer::m_inst, &bt_addr);
        VappBTDUNServer::m_inst->m_devAddr = bt_addr;
    }
    else
    {
        bt_dun_connect_ind_res_struct* auth_rsp = (bt_dun_connect_ind_res_struct*)construct_local_para(sizeof(bt_dun_connect_ind_res_struct),TD_UL);

        auth_rsp->lap = bt_addr.lap;
        auth_rsp->uap = bt_addr.uap;
        auth_rsp->nap = bt_addr.nap;
        auth_rsp->result = (U8)MMI_FALSE;
        auth_rsp->port = auth_ind->port;

        m_state = DUN_STAT_ACTIVATE;
       
        srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_CONNECT_IND_RES, (void*)auth_rsp, NULL);
    } 
}


void VappBTDUNServer::onAuthorizeDone(VfxBool result)
{
   if (VbtDunService::m_state == DUN_STAT_AUTHORIZING)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DUN_AUTHORIZE_DONE, VbtDunService::m_state,result);
        bt_dun_connect_ind_res_struct* auth_rsp = 
            (bt_dun_connect_ind_res_struct*)construct_local_para(sizeof(*auth_rsp),TD_UL);

        auth_rsp->lap = m_devAddr.lap;
        auth_rsp->uap = m_devAddr.uap;
        auth_rsp->nap = m_devAddr.nap;
        auth_rsp->port =  m_port;
		
		auth_rsp->txBufPtr = m_buf;
		auth_rsp->txBufSize = MMI_DUN_BUF_SIZE/2;
		auth_rsp->rxBufPtr = m_buf + MMI_DUN_BUF_SIZE/2;
		auth_rsp->rxBufSize = MMI_DUN_BUF_SIZE/2;
		
        auth_rsp->result = (U8)result;
       
        VbtDunService::m_state = DUN_STAT_ACTIVATE;
        
        srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_DUN_CONNECT_IND_RES, (void*)auth_rsp, NULL);

    } 
}

void VappBTDUNServer::onConnectDone(void *param)
{
//    bt_dun_connect_ind_struct *msg_p = (bt_dun_connect_ind_struct *)param;
       
    VbtDunService::m_state = DUN_STAT_CONNECT;
  
    srv_bt_cm_connect_ind(m_connId);
}



void VappBTDUNServer::onStop(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_DUN_STOP, VbtDunService::m_state,m_connId);
    if (m_connId > 0)
    {
        srv_bt_cm_stop_conn(m_connId);

        VbtDunService::m_state = DUN_STAT_ACTIVATE;
        m_connId = 0;
        m_port = uart_port1;

        VbtServer::onStop();
    }
}

#endif //__MMI_DUN_SUPPORT__

