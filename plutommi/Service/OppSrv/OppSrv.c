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
 * OppSrv.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI BIP service.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_OPP_SUPPORT__

/*  Include: MMI header file */
#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif 

/* Applib MIME Header Files */
#include "app_mine.h"

/* BT manager Header Files */
#include "bluetooth_bm_struct.h"

/* OBEX stack Header Files */
#include "bluetooth_struct.h"

#include "BtcmSrvGprot.h"
#include "BTMMIObexGprots.h"

#include "OppSrvGprot.h"
#include "OppSrv.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "fs_type.h"
#include "stack_msgs.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_conn_app_trc.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "app_ltlcom.h"
//#include "stack_ltlcom.h" for HAL rule 5
#include "stack_common.h"
#include "task_config.h"
#include "mmi_rp_file_type_def.h"
/* auto add by kw_check end */

srv_oppc_instance_struct srv_oppc_inst = {0};
srv_oppc_instance_struct *srv_oppc_p = &srv_oppc_inst;

srv_opps_instance_struct srv_opps_inst = {0};
srv_opps_instance_struct *srv_opps_p = &srv_opps_inst;
#define SRV_OPP_EXTERNAL_API
/*****************************************************************************
 * FUNCTION
 *  srv_opp_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  role        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_opp_open(U8 role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (role == SRV_OPP_ROLE_CLIENT)
    {
        if (srv_oppc_p->srv_hd == 0)
            {
            srv_oppc_p->srv_hd = 1;
            return srv_oppc_p->srv_hd;
        }
    }
    else
    {
        if (srv_opps_p->srv_hd == 0)
        {
            srv_opps_p->srv_hd = SRV_OPP_SERVER_HANDLE_BEGIN;
            return srv_opps_p->srv_hd;
        }
    }
    return SRV_OPP_RESULT_INVALID_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_opp_close(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_hd >= SRV_OPP_SERVER_HANDLE_BEGIN)
    {
        srv_opps_p->srv_hd = 0;
    }
    else
    {
        if (!srv_oppc_is_idle())
        {
            srv_oppc_send_end(srv_oppc_p->srv_hd);
        }
        srv_oppc_p->srv_hd = 0;
    }
    return SRV_OPP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_set_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd          [IN]        
 *  event_mask      [IN]        
 *  notifier        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_opp_set_notify(S32 srv_hd, U32 event_mask, bt_notify notifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (notifier == NULL)
        return SRV_OPP_RESULT_INVALID_PARAM;

    if(srv_hd >= SRV_OPP_SERVER_HANDLE_BEGIN)
    {
        srv_opps_p->event_mask = event_mask;
        srv_opps_p->notifier = notifier;
    }
    else
    {
        srv_oppc_p->event_mask = event_mask;
        srv_oppc_p->notifier = notifier;
    }
    return SRV_OPP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_event_hdlr
 * DESCRIPTION
 *  This function is to handle OPP event from OBEX
 * PARAMETERS
 *  msg_id      [IN]        
 *  msg         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_opp_event_hdlr(msg_type msg_id, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG_STATE();

    switch (msg_id)
    {
            /* OPP client/server common event */
        case MSG_ID_GOEP_DISCONNECT_RSP:
            break;

        case MSG_ID_GOEP_DISCONNECT_IND:
            srv_opp_disconnect_ind_handler(msg);
            break;
        case MSG_ID_GOEP_ABORT_IND:
            srv_opps_abort_ind_handler(msg);
            break;

            /* OPP client specific event */
        case MSG_ID_GOEP_CONNECT_RSP:
            srv_oppc_connect_rsp_handler(msg);
            break;
        case MSG_ID_GOEP_PUSH_RSP:
            srv_oppc_push_rsp_handler(msg);
            break;
        case MSG_ID_GOEP_ABORT_RSP:
            srv_oppc_abort_rsp_handler(msg);
            break;

        case MSG_ID_GOEP_OPP_SUPPORTED_FORMATS_IND:
            srv_oppc_supported_formats_ind_handler(msg);
            break;

            /* OPP server event */
        case MSG_ID_GOEP_REGISTER_SERVER_RSP:
            srv_opps_obex_register_server_rsp_handler(msg);
            break;
        case MSG_ID_GOEP_DEREGISTER_SERVER_RSP:
            srv_opps_obex_deregister_server_rsp_handler(msg);
            break;
        case MSG_ID_GOEP_CONNECT_IND:
            srv_opps_connect_ind_handler(msg);
            break;
        case MSG_ID_GOEP_PUSH_IND:
            srv_opps_push_ind_handler(msg);
            break;
        case MSG_ID_GOEP_AUTHORIZE_IND:
            srv_opps_authorize_ind_hdler(msg);
            break;
        case MSG_ID_GOEP_PULL_IND:
            srv_opps_pull_ind_handler(msg);
            break;
        default:           
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_opp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_oppc_init_cntx();
    srv_opps_init_cntx();

}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_opp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (srv_oppc_p->oppc_cntx.state)
    {
        case SRV_OPC_CONNECTING:
        case SRV_OPC_SENDING:
        case SRV_OPC_ABORTING:
        case SRV_OPC_DISCONNECTING:
            srv_oppc_connection_terminated();
            break;
        default:
            break;
    }

    switch (srv_opps_p->opps_cntx.state)
    {
        case SRV_OPS_AUTHORIZING:
        case SRV_OPS_ACCEPTING:
        case SRV_OPS_ACCEPTED:
        case SRV_OPS_RECEIVING:
        case SRV_OPS_DISCONNECTING:
            srv_opps_connection_terminated();
            SRV_OPS_STATE_TRANS(SRV_OPS_IDLE);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd          [IN]        
 *  dst_dev         [?]         
 *  buffer          [?]         
 *  buf_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_oppc_send_begin(S32 srv_hd, srv_bt_cm_bt_addr *dst_dev, U8 *buffer, U32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oppc_cntx_struct *oppc_cntx = &srv_oppc_p->oppc_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG1(SRV_OPPC_SEND_BEGIN,srv_hd);
    SRV_OPP_LOG_STATE();

    /* Check if the OPC channel is already used */
    if (oppc_cntx->state > SRV_OPC_IDLE)
    {
        return SRV_OPP_RESULT_STATE_BUSY;
    }
    if (buffer == NULL)
    {
        return SRV_OPP_RESULT_INVALID_PARAM;
    }
    oppc_cntx->cm_conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID, dst_dev, NULL);
    if (oppc_cntx->cm_conn_id < 0)
        return SRV_OPP_RESULT_STATE_BUSY;
    oppc_cntx->push_buff = buffer;
    oppc_cntx->dev_addr = *dst_dev;

	oppc_cntx->h_snd = FS_NO_ERROR;
	oppc_cntx->total_obj_len = 0;
	oppc_cntx->remain_put_len = 0;
	oppc_cntx->sending_len = 0;

    srv_oppc_connect_server(oppc_cntx->dev_addr, buf_size);
    return SRV_OPP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_obj
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd      [IN]        
 *  path        [?]         
 *  name        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_oppc_send_obj(S32 srv_hd, U16 *path, U16 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oppc_cntx_struct *oppc_cntx = &srv_oppc_p->oppc_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG1(SRV_OPPC_SEND_OBJ,srv_hd);   
    SRV_OPP_LOG_PATH(path);

    if (path == NULL) return SRV_OPP_RESULT_INVALID_PARAM;

    if (srv_hd <= 0 || srv_oppc_p->srv_hd != srv_hd)
        return SRV_OPP_RESULT_INVALID_HANDLE;
   
    mmi_wcscpy(oppc_cntx->obj_path, path);

    srv_opp_truncate_obj_name(oppc_cntx->obj_name,
            name,
        sizeof(oppc_cntx->obj_name),
            MMI_FALSE);
    srv_oppc_send_first_packet();
    return SRV_OPP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_client_send_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_oppc_send_end(S32 srv_hd) /* here AP need care conn_id or not */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oppc_cntx_struct* oppc_cntx = &srv_oppc_p->oppc_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG1(SRV_OPPC_SEND_END,srv_hd);
    SRV_OPP_LOG_STATE();
    
    if (srv_hd <= 0 || srv_oppc_p->srv_hd != srv_hd)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    if (oppc_cntx->h_snd >= FS_NO_ERROR)
    {
        FS_Close(oppc_cntx->h_snd);
    }
    oppc_cntx->h_snd = (FS_HANDLE) NULL;

    switch (oppc_cntx->state)
    {
        case SRV_OPC_CONNECTING:
            /* disconnect the unestablished connecttion with 0xff goep conn id */
            /* set conn_id = 0xff for disconnect indication/response goep_conn_id check */
            oppc_cntx->goep_conn_id = 0xff;
        case SRV_OPC_CONNECTED:
            SRV_OPC_STATE_TRANS(SRV_OPC_DISCONNECTING);
            srv_oppc_send_disconnect_req(oppc_cntx->goep_conn_id, MMI_FALSE);
            break;

        case SRV_OPC_SENDING:
            oppc_cntx->flag_abt = 1;
            //remember user action aborting and when push rsp back
            //we must abort req because the PTS case
            break;
        case SRV_OPC_ABORTING:
        case SRV_OPC_DISCONNECTING:
            break;

        default:
            MMI_OPP_ASSERT(0);
    }

    srv_bt_cm_reg_pairing_permission(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID, (void*)srv_oppc_passkey_hdler);
    return SRV_OPP_RESULT_OK;
}





/*****************************************************************************
 * FUNCTION
 *  srv_opp_client_is_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_oppc_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(srv_oppc_p->oppc_cntx.state == SRV_OPC_IDLE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_client_is_sending
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.
 *****************************************************************************/
MMI_BOOL srv_oppc_is_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_oppc_p->oppc_cntx.state == SRV_OPC_CONNECTING ||
        srv_oppc_p->oppc_cntx.state == SRV_OPC_SENDING ||
        srv_oppc_p->oppc_cntx.state == SRV_OPC_CONNECTED)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_client_is_aborting
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)
 *****************************************************************************/
MMI_BOOL srv_oppc_is_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_oppc_p->oppc_cntx.state == SRV_OPC_ABORTING || srv_oppc_p->oppc_cntx.state == SRV_OPC_DISCONNECTING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_client_is_disconncting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_oppc_is_disconncting(void)//only for SDK it may remove
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_OPC_DISCONNECTING == srv_oppc_p->oppc_cntx.state)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_opp_server_is_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_opps_is_active(void)//only for SDK
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_opps_p->opps_cntx.state >= SRV_OPS_ACTIVE && srv_opps_p->opps_cntx.state < SRV_OPS_DEACTIVATING)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_server_is_receiving
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)
 *****************************************************************************/
MMI_BOOL srv_opps_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_opps_p->opps_cntx.state >= SRV_OPS_AUTHORIZING)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_server_is_accepted
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)
 *****************************************************************************/
MMI_BOOL srv_opps_is_accepted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_opps_p->opps_cntx.state >= SRV_OPS_ACCEPTED)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_server_is_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_opps_is_idle(void)//only for SDK
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_opps_p->opps_cntx.state == SRV_OPS_IDLE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_opp_server_activate
 * DESCRIPTION
 *  This function is to activate OPS module
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_opps_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG_STATE();
    
    switch(srv_opps_p->opps_cntx.state)
    {
        case SRV_OPS_IDLE:
            SRV_OPS_STATE_TRANS(SRV_OPS_OBEX_REGISTERING);
            /* Register OBEX server instance first, then register SDP service record first */
            srv_opps_obex_register_server_req();
            break;            
        case SRV_OPS_OBEX_REGISTERING:
        case SRV_OPS_SDP_REGISTERING:       
            break;           
        default:
            break;
    }
    //return SRV_OPP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_server_deactivate
 * DESCRIPTION
 *  This function is to deactivate object push profile
 * PARAMETERS
 *  srv_hd      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_opps_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG_STATE();

    switch (srv_opps_p->opps_cntx.state)
    {
        case SRV_OPS_IDLE:
        case SRV_OPS_DEACTIVATING:
            /* notify app */
            /* nothing to do */
            MMI_OPP_ASSERT(0);
            break;
        case SRV_OPS_SDP_REGISTERING:
        case SRV_OPS_OBEX_REGISTERING:
            /* it must not happen, because CM guarantee no deactivation happen while activating */
            MMI_OPP_ASSERT(0);
            break;
        case SRV_OPS_ACTIVE:
        case SRV_OPS_AUTHORIZING:
            /* deregister SDP directly, because no connection yet */
            SRV_OPS_STATE_TRANS(SRV_OPS_DEACTIVATING);
            srv_opps_sdpdb_deregister_req();
            break;
        case SRV_OPS_ACCEPTING:
            srv_opps_reject_connection(MMI_TRUE);
        case SRV_OPS_ACCEPTED:
            /* disconnect OBEX connection */
            //SRV_OPS_STATE_TRANS(SRV_OPS_DEACTIVATING);
            /* Send OPP disconnect request to OBEX */
            //srv_opps_send_disconnect_req(srv_opps_p->opps_cntx.goep_conn_id);
            break;
        case SRV_OPS_RECEIVING:
            /* need to abort ? because we already receive
               disconnect indication before CM invoke srv_opps_deactivate */
            MMI_OPP_ASSERT(0);
            break;
        case SRV_OPS_DISCONNECTING:
            /* wait disconnect response */
            break;
        default:
            MMI_OPP_ASSERT(0);
            break;
    }
    //return SRV_OPP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_server_disconn_client
 * DESCRIPTION
 *  
 * PARAMETERS
 *  g_conn_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_opps_disconn_client(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_hd <= 0 || srv_opps_p->srv_hd != srv_hd)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    srv_opps_send_disconnect_req(srv_opps_p->opps_cntx.goep_conn_id);
    return SRV_OPP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_server_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd      [IN]        
 *  conn_id     [IN]        
 *  path        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_opps_accept(S32 srv_hd, U16 *recv_path)//This function should review
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opps_cntx_struct *opps_cntx = &srv_opps_p->opps_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG_STATE();
    
    if (srv_hd <= 0 || srv_opps_p->srv_hd != srv_hd)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    SRV_OPP_LOG2(SRV_OPPS_ACCEPT, srv_hd, opps_cntx->goep_conn_id);

    if (opps_cntx->state == SRV_OPS_AUTHORIZING)
    {
        srv_opps_authorize_rsp(opps_cntx->goep_conn_id, GOEP_STATUS_SUCCESS);
    }
    else
    {
        if (opps_cntx->state == SRV_OPS_ACCEPTING)
        {
            SRV_OPS_STATE_TRANS(SRV_OPS_ACCEPTED);
        }
        if (recv_path != NULL)
        {
            srv_opps_proc_first_push_data(opps_cntx->push_pkt, recv_path);
        }
        else
        {
            srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_NOT_ACCEPTABLE);
        }
        
        srv_opp_free_push_data();
    }
    return SRV_OPP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_server_reject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd          [IN]        
 *  conn_id         [IN]        
 *  user_reject     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_opps_reject(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opps_cntx_struct* opps_cntx = &srv_opps_p->opps_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG_STATE();
    
    SRV_OPP_LOG2(SRV_OPPS_REJECT, srv_hd, opps_cntx->goep_conn_id);
    
    if (opps_cntx->state <= SRV_OPS_ACTIVE)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    if (opps_cntx->state == SRV_OPS_AUTHORIZING)
    {
        SRV_OPS_STATE_TRANS(SRV_OPS_ACTIVE);
        srv_opps_authorize_rsp(opps_cntx->goep_conn_id, GOEP_SERVICE_UNAVAILABLE);
    }
    else
    {
        if (opps_cntx->state == SRV_OPS_ACCEPTING)
        {
            srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_NOT_ACCEPTABLE);
        }
        else
        {
            /* Send response to OBEX */
            srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);
        }
        
        SRV_OPS_STATE_TRANS(SRV_OPS_ACCEPTED);

        srv_opp_free_push_data();
    }
    return SRV_OPP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_disconnect_ind_handler
 * DESCRIPTION
 *  This function is event handler for OBEX disconnect indication (MSG_ID_GOEP_DISCONNECT_IND)
 * PARAMETERS
 *  msg     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opp_disconnect_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_ind_struct *goep_disconnect_ind = (goep_disconnect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (goep_disconnect_ind->goep_conn_id == srv_oppc_p->oppc_cntx.goep_conn_id)
    {
        srv_oppc_disconnect_ind_handler(msg);
    }
    else if (goep_disconnect_ind->goep_conn_id == srv_opps_p->opps_cntx.goep_conn_id)
    {
        srv_opps_disconnect_ind_handler(msg);
    }
    else if ((srv_oppc_p->oppc_cntx.state == SRV_OPC_IDLE) && (srv_opps_p->opps_cntx.state == SRV_OPS_IDLE))
    {
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_post_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_id        [IN]        
 *  para            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_opp_post_proc(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_event_struct *event = (srv_opp_event_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (event->role == SRV_OPP_ROLE_CLIENT)
    {
        SRV_OPP_LOG(SRV_OPPC_POST_EVENT_PROC);
        srv_oppc_notify_app(event->event_id, event->data);

    }
    else
    {
        SRV_OPP_LOG(SRV_OPPS_POST_EVENT_PROC);
        srv_opps_notify_app(event->event_id, event->data);
    }
    
    if (event->data != NULL)
    {
        OslMfree(event->data);
    }
    
    return MMI_RET_OK;
}



#define MMI_OPP_CLIENT


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_init_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_profile_struct prof_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_oppc_cntx_struct* oppc_cntx = &srv_oppc_p->oppc_cntx;

    oppc_cntx->state = SRV_OPC_IDLE;
    oppc_cntx->goep_conn_id = 0xff;

    prof_struct.profile_id = SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID;
    prof_struct.activater = NULL;
    prof_struct.deactivater = NULL;
    prof_struct.disconnector = srv_oppc_disconnect_from_cm;
    srv_bt_cm_profile_register(&prof_struct);
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_connect_server
 * DESCRIPTION
 *  This function is to connect opp server
 * PARAMETERS
 *  bt_addr         [IN]        
 *  is_sfn(?)       [IN]        
 *  callback(?)     [IN]        
 *  path(?)         [IN]        
 *  dst_dev(?)      [IN]        
 * RETURNS
 *  MMI_OPP_SND_ERR_TYPE(?)
 *****************************************************************************/
static void srv_oppc_connect_server(srv_bt_cm_bt_addr bt_addr, U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG(SRV_OPPC_CONN_SERVER);
    SRV_OPP_LOG_STATE();

    SRV_OPC_STATE_TRANS(SRV_OPC_CONNECTING);

    srv_oppc_send_connect_req((U16) buff_size, bt_addr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_first_packet
 * DESCRIPTION
 *  This function is to send first packet
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_send_first_packet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    srv_opp_snd_notify_struct snd_notify;
    srv_opp_snd_notify_struct *post_notify;
    srv_opp_event_struct event; 
    srv_oppc_cntx_struct* oppc_cntx = &srv_oppc_p->oppc_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Open sending object */
    oppc_cntx->h_snd = FS_Open(oppc_cntx->obj_path, FS_READ_ONLY);
    SRV_OPP_LOG1(SRV_OPPC_SEND_FIRST_PACKET_FS_OPEN, oppc_cntx->h_snd);

    if (oppc_cntx->h_snd < FS_NO_ERROR)
    {
        MMI_FRM_INIT_EVENT(&event, SRV_OPP_EVENT_OPEN_FAIL);
    
        post_notify = OslMalloc(sizeof(srv_opp_snd_notify_struct));
        post_notify->type = SRV_OPP_SND_FAIL;
        
        event.event_id = SRV_OPP_EVENT_SND_NOTIFY;
        event.role = SRV_OPP_ROLE_CLIENT;
        event.data = (void *)post_notify;

        mmi_frm_post_event((mmi_event_struct *)&event, srv_opp_post_proc, NULL);
        return;
    }

    /* Get the object size */
    FS_GetFileSize(oppc_cntx->h_snd, &len);
    oppc_cntx->total_obj_len = len;
    oppc_cntx->remain_put_len = len;
    oppc_cntx->sending_len = 0;	
	FS_Close(oppc_cntx->h_snd);
	oppc_cntx->h_snd = FS_NO_ERROR;

    srv_opp_get_obj_attrib();

    SRV_OPC_STATE_TRANS(SRV_OPC_SENDING);

    /* We don't send real data in the first packet */
    srv_oppc_send_push_req(
        oppc_cntx->goep_conn_id,
        GOEP_FIRST_PKT,
        oppc_cntx->total_obj_len,
        oppc_cntx->obj_name,
        oppc_cntx->obj_mime,
        NULL,
        0);

    snd_notify.type = SRV_OPP_SND_PERSENT;
    snd_notify.info.remain_put_len = oppc_cntx->remain_put_len;
    snd_notify.info.total_obj_len = oppc_cntx->total_obj_len;
    srv_oppc_notify_app(SRV_OPP_EVENT_SND_NOTIFY, (void*)&snd_notify);
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_connect_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OBEX connect response (MSG_ID_BT_GOEP_CONNECT_RSP)
 * PARAMETERS
 *  msg     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_connect_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_connect_rsp_struct *rsp = (goep_connect_rsp_struct*) msg;
    srv_opp_conn_notify_struct conn_notify;
    srv_opp_snd_notify_struct snd_notify;
    srv_oppc_cntx_struct* oppc_cntx = &srv_oppc_p->oppc_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id if match */
    if (rsp->req_id != oppc_cntx->cm_conn_id)
    {
        return;
    }

    if (rsp->rsp_code == GOEP_STATUS_SUCCESS)
    {
        /* Connection is established successfully  */
        switch (oppc_cntx->state)
        {
            case SRV_OPC_CONNECTING:

                SRV_OPC_STATE_TRANS(SRV_OPC_CONNECTED);

                /* The connection is establish for sending object */
                oppc_cntx->goep_conn_id = rsp->goep_conn_id;
                /* Store the max acceptable obex packet size */
                if (rsp->peer_mru != 0)
                {
                    oppc_cntx->opc_mtu =
                        (rsp->peer_mru < OPPC_MAX_OBEX_PACKET_LENGTH ? rsp->peer_mru : OPPC_MAX_OBEX_PACKET_LENGTH);
                }
                else
                {
                    oppc_cntx->opc_mtu = OPPC_MAX_OBEX_PACKET_LENGTH;
                }

                SRV_OPP_LOG1(SRV_OPPC_MAX_PACKET_SIZE, oppc_cntx->opc_mtu);

                conn_notify.bt_addr = oppc_cntx->dev_addr;

                conn_notify.type = SRV_OPP_CONN_SUCC;
                srv_bt_cm_connect_ind(oppc_cntx->cm_conn_id);
                srv_oppc_notify_app(SRV_OPP_EVENT_CONN_NOTIFY, (void*)&conn_notify);

            #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)

                snd_notify.supported_formats = oppc_cntx->supported_formats;

            #endif /* defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__) */ 

                snd_notify.type = SRV_OPP_SND_READY;

                srv_oppc_notify_app(SRV_OPP_EVENT_SND_NOTIFY, (void*)&snd_notify);

                break;

            case SRV_OPC_ABORTING:
                break;
            case SRV_OPC_DISCONNECTING:
                /* race condition, just ignore */
                oppc_cntx->goep_conn_id = rsp->goep_conn_id;
                break;

            default:
                SRV_OPC_LOG_STATE_ERR();
                MMI_OPP_ASSERT(0);
                break;
        }
    }
    else
    {
        SRV_OPC_STATE_TRANS(SRV_OPC_IDLE);

        conn_notify.conn_id = 0xFF;
        if (rsp->rsp_code == GOEP_STATUS_SCO_REJECT)
        {
            conn_notify.type = SRV_OPP_CONN_SCO_REJECT;
        }
        else
        {
            conn_notify.type = SRV_OPP_CONN_FAILED;
        }

        srv_bt_cm_stop_conn(oppc_cntx->cm_conn_id);
        srv_oppc_notify_app(SRV_OPP_EVENT_CONN_NOTIFY, (void*)&conn_notify);

        snd_notify.type = SRV_OPP_SND_DONE;
        srv_oppc_notify_app(SRV_OPP_EVENT_SND_NOTIFY, (void*)&snd_notify);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_push_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OBEX push response
 *  (MSG_ID_GOEP_PUSH_RSP)
 * PARAMETERS
 *  msg     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_push_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_rsp_struct *rsp = (goep_push_rsp_struct*) msg;
    U32 sent = 0, read = 0;
    goep_pkt_type_enum pkt = GOEP_FIRST_PKT;
    S32 retval;
    srv_opp_snd_notify_struct snd_notify;
	//srv_opp_snd_notify_struct *post_notify;
	//srv_opp_event_struct event; 
    srv_oppc_cntx_struct* oppc_cntx = &srv_oppc_p->oppc_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (oppc_cntx->goep_conn_id != rsp->goep_conn_id || oppc_cntx->state != SRV_OPC_SENDING)
    {
        return;
    }

	if (rsp->rsp_code != GOEP_STATUS_SUCCESS)
    {
        SRV_OPC_STATE_TRANS(SRV_OPC_DISCONNECTING);
        srv_oppc_send_disconnect_req(oppc_cntx->goep_conn_id, MMI_TRUE);

        snd_notify.type = SRV_OPP_SND_FAIL_BY_SERVER;
        srv_oppc_notify_app(SRV_OPP_EVENT_SND_NOTIFY, (void*)&snd_notify);
        return;
    }

	if (oppc_cntx->flag_abt == 1)
    {
        srv_oppc_send_abort_req(oppc_cntx->goep_conn_id);
        SRV_OPC_STATE_TRANS(SRV_OPC_ABORTING);
        return;
    }
	
	if (oppc_cntx->h_snd <= FS_NO_ERROR)
	{
		/* Open sending object */
	    oppc_cntx->h_snd = FS_Open(oppc_cntx->obj_path, FS_READ_ONLY);
	    if (oppc_cntx->h_snd < FS_NO_ERROR)
	    {
            /* Read error, we abort this operation */
            SRV_OPC_STATE_TRANS(SRV_OPC_ABORTING);
            srv_oppc_send_abort_req(oppc_cntx->goep_conn_id);
			return;
	    }
	}

    if (oppc_cntx->remain_put_len > 0)
    {
        SRV_OPP_LOG2(
            SRV_OPPC_PUSH_RSP_REMAIN_LEN,
            oppc_cntx->opc_mtu,
            oppc_cntx->remain_put_len);

        if (oppc_cntx->remain_put_len > oppc_cntx->opc_mtu)
        {
            sent = oppc_cntx->opc_mtu;
            pkt = GOEP_NORMAL_PKT;
        }
        else
        {
            sent = oppc_cntx->remain_put_len;
            pkt = GOEP_FINAL_PKT;
        }

        retval = FS_Read(oppc_cntx->h_snd, oppc_cntx->push_buff, sent, &read);
        SRV_OPP_LOG1(SRV_OPPC_PUSH_RSP_FS_READ, retval);

        if (retval < FS_NO_ERROR || read != sent)
        {
            /* Read error, we abort this operation */
            SRV_OPC_STATE_TRANS(SRV_OPC_ABORTING);
            srv_oppc_send_abort_req(oppc_cntx->goep_conn_id);
        }
        else
        {
            srv_oppc_send_push_req(
                oppc_cntx->goep_conn_id,
                pkt,
                oppc_cntx->total_obj_len,
                oppc_cntx->obj_name,
                oppc_cntx->obj_mime,
                (U32*)oppc_cntx->push_buff,
                (U16) sent);

            oppc_cntx->remain_put_len -= sent;
            oppc_cntx->sending_len = sent;
            
            if ( pkt == GOEP_FINAL_PKT)
            {
                snd_notify.type = SRV_OPP_SND_PERSENT;
                snd_notify.info.remain_put_len = oppc_cntx->remain_put_len;
                snd_notify.info.total_obj_len = oppc_cntx->total_obj_len;
                
                srv_oppc_notify_app(SRV_OPP_EVENT_SND_NOTIFY, (void*)&snd_notify);
            }

        }
    }
    else
    {
        SRV_OPC_STATE_TRANS(SRV_OPC_CONNECTED);

        if (oppc_cntx->h_snd >= FS_NO_ERROR)
        {
            FS_Close(oppc_cntx->h_snd);
        }
        oppc_cntx->h_snd = (FS_HANDLE) NULL;
		oppc_cntx->sending_len = 0;

        snd_notify.type = SRV_OPP_SND_PERSENT;
        srv_oppc_notify_app(SRV_OPP_EVENT_SND_NOTIFY, (void*)&snd_notify);

        snd_notify.type = SRV_OPP_SND_SUCC;
        srv_oppc_notify_app(SRV_OPP_EVENT_SND_NOTIFY, (void*)&snd_notify);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_abort_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OBEX abort response (MSG_ID_GOEP_ABORT_RSP)
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_abort_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_rsp_struct *goep_abort_rsp = (goep_abort_rsp_struct*) msg;
    srv_opp_snd_notify_struct snd_notify;
    srv_oppc_cntx_struct* oppc_cntx = &srv_oppc_p->oppc_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (goep_abort_rsp->goep_conn_id != oppc_cntx->goep_conn_id)
    {
        /* do nothing because disconnect indication may already be received */
        return;
    }

    SRV_OPP_LOG1(SRV_OPPC_ABORT_RSP, oppc_cntx->state);

    if (oppc_cntx->state == SRV_OPC_ABORTING)
    {
        if (oppc_cntx->flag_abt == 1)
    {
            srv_oppc_send_disconnect_req(oppc_cntx->goep_conn_id, MMI_TRUE);
            SRV_OPC_STATE_TRANS(SRV_OPC_DISCONNECTING);
            return;
        }

        SRV_OPC_STATE_TRANS(SRV_OPC_CONNECTED);

        if (oppc_cntx->h_snd >= FS_NO_ERROR)
        {
            FS_Close(oppc_cntx->h_snd);
        }
        oppc_cntx->h_snd = (FS_HANDLE) NULL;

        snd_notify.type = SRV_OPP_SND_FAIL;

        srv_oppc_notify_app(SRV_OPP_EVENT_SND_NOTIFY, (void*)&snd_notify);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_disconnect_ind_handler
 * DESCRIPTION
 *  This function is event handler for OBEX client disconnect indication
 * PARAMETERS
 *  msg     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_disconnect_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_ind_struct *ind = (goep_disconnect_ind_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG(SRV_OPPC_DISC_CONN_IND);

    if (srv_oppc_p->oppc_cntx.goep_conn_id != ind->goep_conn_id)
    {
        MMI_OPP_ASSERT(0);
    }

    srv_bt_cm_unreg_pairing_permission(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID);
    
    srv_oppc_connection_terminated();

}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_supported_formats_ind_handler
 * DESCRIPTION
 *  This function is event handler for OBEX server supported formats indication ( MSG_ID_GOEP_OPP_SUPPORTED_FORMATS_IND)
 * PARAMETERS
 *  msg     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_supported_formats_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_opp_supported_formats_ind_struct *ind = (goep_opp_supported_formats_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_oppc_p->oppc_cntx.supported_formats = 0xFF;
    SRV_OPP_LOG1(SRV_OPPC_SUPPORTED_FORMAT,ind->server_supported_formats);
    if (ind->server_supported_formats != 0xFF)
    {
        srv_oppc_p->oppc_cntx.supported_formats = ind->server_supported_formats;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_connect_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX connect request
 * PARAMETERS
 *  opp_client_max_packet_len       [IN]        
 *  dest_addr                       [IN]        
 *  sc_authorise_ind_p      [?](?)
 *  a(?)                    [IN/OUT]        First variable, used as returns(?)
 *  b(?)                    [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_send_connect_req(U16 opp_client_max_packet_len, srv_bt_cm_bt_addr dest_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_connect_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (goep_connect_req_struct*) construct_local_para(sizeof(*req), TD_CTRL);

    req->uuid[0] = '\0';
    req->uuid_len = 0; //BTMMIobex.c msg transfer use...ai!!!
    req->req_id = srv_oppc_p->oppc_cntx.cm_conn_id;
    req->bd_addr = *((goep_bd_addr_struct*)&dest_addr);
    req->tp_type = GOEP_TP_BT;
    req->buf_ptr = srv_oppc_p->oppc_cntx.push_buff;
    req->buf_size = opp_client_max_packet_len;
    req->auth_use = KAL_FALSE;
    req->passwd_len = 0;
    req->realm_len = 0;

    srv_opp_send_ilm(MSG_ID_GOEP_CONNECT_REQ, (local_para_struct*)req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_disconnect_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX disconnect request
 * PARAMETERS
 *  goep_conn_id        [IN]        
 *  tpdisconn_flag      [IN]        
 *  sc_authorise_ind_p      [?](?)
 *  a(?)                    [IN/OUT]        First variable, used as returns(?)
 *  b(?)                    [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_send_disconnect_req(U8 goep_conn_id, MMI_BOOL tpdisconn_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_req_struct *req;
    msg_type msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (goep_disconnect_req_struct*) construct_local_para(sizeof(*req), TD_CTRL);

    req->goep_conn_id = goep_conn_id;
    /* This request ID is only useful while aborting connecting request */
    req->req_id = srv_oppc_p->oppc_cntx.cm_conn_id;
    if (tpdisconn_flag)
    {
        msg_id = MSG_ID_GOEP_TPDISCONNECT_REQ;
    }
    else
    {
        msg_id = MSG_ID_GOEP_DISCONNECT_REQ;
    }
    srv_opp_send_ilm(msg_id, (local_para_struct*)req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_abort_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX abort put request
 * PARAMETERS
 *  goep_conn_id        [IN]        
 *  sc_authorise_ind_p      [?](?)
 *  a(?)                    [IN/OUT]        First variable, used as returns(?)
 *  b(?)                    [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_send_abort_req(U8 goep_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_req_struct *goep_abort_req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    goep_abort_req = (goep_abort_req_struct*) construct_local_para(sizeof(goep_abort_req_struct), TD_CTRL);
    goep_abort_req->goep_conn_id = goep_conn_id;
    srv_opp_send_ilm(MSG_ID_GOEP_ABORT_REQ, (local_para_struct*) goep_abort_req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_push_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX push request
 * PARAMETERS
 *  goep_conn_id        [IN]        
 *  pkt_type            [IN]        
 *  total_obj_len       [IN]        
 *  obj_name            [?]         
 *  obj_mime            [IN]        
 *  frag_ptr            [?]         
 *  frag_len            [IN]        
 *  sc_authorise_ind_p      [?](?)
 *  a(?)                    [IN/OUT]        First variable, used as returns(?)
 *  b(?)                    [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_send_push_req(
                U8 goep_conn_id,
                goep_pkt_type_enum pkt_type,
                U32 total_obj_len,
                U16 *obj_name,
                PS8 obj_mime,
                U32 *frag_ptr,
                U16 frag_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *ilm_ptr;
    goep_push_req_struct *goep_push_req;
    U32 i;
    U8 *name = (U8 *)obj_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    goep_push_req = (goep_push_req_struct*) construct_local_para(sizeof(goep_push_req_struct), TD_CTRL);

    goep_push_req->goep_conn_id = goep_conn_id;
    goep_push_req->pkt_type = pkt_type;
    goep_push_req->put_type = GOEP_PUT_NORMAL;
    memcpy(goep_push_req->obj_mime_type, obj_mime, GOEP_MAX_MIME_TYPE);

    for (i = 0; i < GOEP_MAX_OBJ_NAME - 1; i += 2)
    {
        goep_push_req->obj_name[i] = name[i+1];
        goep_push_req->obj_name[i+1] = name[i];
    }
    goep_push_req->total_obj_len = total_obj_len;
    goep_push_req->frag_ptr = (kal_uint8*) frag_ptr;
    goep_push_req->frag_len = frag_len;

    srv_opp_send_ilm(MSG_ID_GOEP_PUSH_REQ, (local_para_struct*) goep_push_req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_get_sent_info
 * DESCRIPTION
 *  This function is to retrieve the file put progress.
 * PARAMETERS
 *  void
 * RETURNS
 *  1 ~ 100  The percentage of put process.
 *****************************************************************************/
void srv_oppc_get_obj_info(srv_opp_obj_info_struct *obj_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Total length of a object */

    obj_info->total_obj_len = srv_oppc_p->oppc_cntx.total_obj_len;
    obj_info->remain_put_len = srv_oppc_p->oppc_cntx.remain_put_len + srv_oppc_p->oppc_cntx.sending_len;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_connection_terminated
 * DESCRIPTION
 *  This is common function to deal with opc disconnect
 * PARAMETERS
 *  void
 *  cause(?)        [IN]        The cause for connection terminated
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_connection_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_snd_notify_struct snd_notify;
    srv_opp_disconn_notify_struct disconn_notify;
    srv_oppc_cntx_struct* oppc_cntx = &srv_oppc_p->oppc_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG(SRV_OPPC_CONN_TERM);
    SRV_OPP_LOG_STATE();

    if (oppc_cntx->h_snd >= FS_NO_ERROR)
    {
        FS_Close(oppc_cntx->h_snd);
    }
    oppc_cntx->h_snd = (FS_HANDLE) NULL;
    
    switch (oppc_cntx->state)
    {
        case SRV_OPC_IDLE:
            return;

        case SRV_OPC_CONNECTING:
        case SRV_OPC_CONNECTED:
        case SRV_OPC_SENDING:
        case SRV_OPC_ABORTING:
        case SRV_OPC_DISCONNECTING:
            oppc_cntx->goep_conn_id = 0xff;
            oppc_cntx->flag_abt = 0;
            SRV_OPC_STATE_TRANS(SRV_OPC_IDLE);
            break;

        default:
            SRV_OPC_LOG_STATE_ERR();
            break;
    }

    srv_bt_cm_stop_conn(oppc_cntx->cm_conn_id);

    disconn_notify.bt_addr = oppc_cntx->dev_addr;
    srv_oppc_notify_app(SRV_OPP_EVENT_DISCONN_NOTIFY, (void*)&disconn_notify);

    snd_notify.type = SRV_OPP_SND_DONE;
    srv_oppc_notify_app(SRV_OPP_EVENT_SND_NOTIFY, (void*)&snd_notify);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_passkey_hdler
 * DESCRIPTION
 *  this function is used to control whether passkey screen popup,
 *  if return true, it can enter passkey, otherwise not
 * PARAMETERS
 *  bd_addr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_oppc_passkey_hdler(srv_bt_cm_bt_addr bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_oppc_is_aborting())
    {
        if (srv_oppc_p->oppc_cntx.dev_addr.lap == bd_addr.lap &&
            srv_oppc_p->oppc_cntx.dev_addr.nap == bd_addr.nap &&
            srv_oppc_p->oppc_cntx.dev_addr.uap == bd_addr.uap)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_notify_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_id        [IN]        
 *  para            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_notify_app(U32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_oppc_p->srv_hd > 0 && srv_oppc_p->event_mask & event_id)
    {
        srv_oppc_p->notifier(srv_oppc_p->srv_hd, event_id, para);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oppc_disconnect_from_cm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conn_id        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oppc_disconnect_from_cm(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_oppc_cntx_struct* oppc_cntx = &srv_oppc_p->oppc_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (conn_id == srv_oppc_p->oppc_cntx.cm_conn_id)
    {
	    if (oppc_cntx->h_snd >= FS_NO_ERROR)
	    {
	        FS_Close(oppc_cntx->h_snd);
	    }
	    oppc_cntx->h_snd = (FS_HANDLE) NULL;
	    switch (oppc_cntx->state)
	    {
	        case SRV_OPC_CONNECTING:
	            /* disconnect the unestablished connecttion with 0xff goep conn id */
	            /* set conn_id = 0xff for disconnect indication/response goep_conn_id check */
	            oppc_cntx->goep_conn_id = 0xff;
	        case SRV_OPC_CONNECTED:
			case SRV_OPC_SENDING:
	            SRV_OPC_STATE_TRANS(SRV_OPC_DISCONNECTING);
	            srv_oppc_send_disconnect_req(oppc_cntx->goep_conn_id, MMI_TRUE);
	            break;	        
	        default:
	            MMI_OPP_ASSERT(0);
	    }
	}
}

#define MMI_OPP_SERVER


/*****************************************************************************
 * FUNCTION
 *  srv_opps_init_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_profile_struct prof_struct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_opps_cntx_struct* opps_cntx = &srv_opps_p->opps_cntx;
    opps_cntx->state = SRV_OPS_IDLE;
    opps_cntx->h_recv = (FS_HANDLE)NULL;
    opps_cntx->cm_conn_id = 0xff;
    opps_cntx->goep_conn_id = 0xff;
    opps_cntx->push_pkt = NULL;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_SDPDB_REGISTER_CNF, (PsIntFuncPtr)srv_opps_sdpdb_register_cfn_handler, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_SDPDB_DEREGISTER_CNF, (PsIntFuncPtr)srv_opps_sdpdb_deregister_cfn_handler, MMI_TRUE);

    prof_struct.profile_id = SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID;
    prof_struct.activater = srv_opps_activate;
    prof_struct.deactivater = srv_opps_deactivate;
    prof_struct.disconnector = srv_opps_disconnect_from_cm;
    srv_bt_cm_profile_register(&prof_struct);
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_obex_register_server_req
 * DESCRIPTION
 *  This function is to register OBEX server instance
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_obex_register_server_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_register_server_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (goep_register_server_req_struct*) construct_local_para(sizeof(*req), TD_CTRL);

    req->req_id = 1;
    req->uuid[0] = '\0';
    req->uuid_len = 0;
    req->tp_type = GOEP_TP_BT;
    req->need_auth = KAL_FALSE;
    req->buf_ptr = (kal_uint8*) srv_opps_p->opps_cntx.push_buff;
    req->buf_size = OPPS_MAX_OBEX_PACKET_LENGTH;

    srv_opp_send_ilm(MSG_ID_GOEP_REGISTER_SERVER_REQ, (local_para_struct*) req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_obex_register_server_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OPP server OBEX server register rsp (MSG_ID_OBEX_REGISTER_SERVER_RSP)
 * PARAMETERS
 *  msg     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_obex_register_server_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_register_server_rsp_struct *rsp = (goep_register_server_rsp_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the state shall be SRV_OPS_SDP_REGISTERING */
    if (srv_opps_p->opps_cntx.state == SRV_OPS_OBEX_REGISTERING)
    {
        if (rsp->rsp_code == GOEP_STATUS_SUCCESS)
        {
            /* OPP server activating successfully */
            srv_opps_p->opps_cntx.goep_conn_id = rsp->goep_conn_id;
            /* Register OPPS SDP service record */
            srv_opps_sdpdb_register_req();
            SRV_OPS_STATE_TRANS(SRV_OPS_SDP_REGISTERING);
        }
        else
        {
            /* OPP must server activating successfully, otherwise assert(0) */
            MMI_OPP_ASSERT(0);
        }
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_obex_deregister_server_req
 * DESCRIPTION
 *  This function is to deactivate OPP server service
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_obex_deregister_server_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_deregister_server_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (goep_deregister_server_req_struct*) construct_local_para(sizeof(*req), TD_CTRL);

    req->goep_conn_id = srv_opps_p->opps_cntx.goep_conn_id;
    srv_opp_send_ilm(MSG_ID_GOEP_DEREGISTER_SERVER_REQ, (local_para_struct*) req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_obex_deregister_server_rsp_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_obex_deregister_server_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_deregister_server_rsp_struct *rsp = (goep_deregister_server_rsp_struct*) msg;
    srv_opps_cntx_struct* opps_cntx = &srv_opps_p->opps_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (opps_cntx->state == SRV_OPS_DEACTIVATING)
    {
        if (rsp->goep_conn_id == opps_cntx->goep_conn_id)
        {
            srv_bt_cm_deactivate_cnf_hdler((U32) SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID);
            srv_opps_notify_app(SRV_OPP_EVENT_STOP, NULL);
	        opps_cntx->state = SRV_OPS_IDLE;
            opps_cntx->h_recv = (FS_HANDLE) NULL;
            opps_cntx->goep_conn_id = 0xff;
            opps_cntx->cm_conn_id = 0xff;
            opps_cntx->push_pkt = NULL;
        }
        else
        {
            MMI_OPP_ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_sdpdb_register_req
 * DESCRIPTION
 *  This function is to register OPP service SDP record
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_sdpdb_register_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_register_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (bt_sdpdb_register_req_struct*) construct_local_para(sizeof(*req), TD_CTRL);
    req->uuid = SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID;

    srv_opp_send_ilm(MSG_ID_BT_SDPDB_REGISTER_REQ, (local_para_struct*) req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_sdpdb_register_cfn_handler
 * DESCRIPTION
 *  This function is event handler for OPP server SDP record register confirm (MSG_ID_BT_SDPDB_REGISTER_CFN)
 * PARAMETERS
 *  msg     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_opps_sdpdb_register_cfn_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_register_cnf_struct *cnf = (bt_sdpdb_register_cnf_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnf->uuid != SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID)
    {
        /* return MMI_FALSE; */
        return MMI_FALSE;
    }
    /* the state shall be SRV_OPS_SDP_REGISTERING */
    if (srv_opps_p->opps_cntx.state == SRV_OPS_SDP_REGISTERING && cnf->result == 0)
        {
            /* Invoke CM activate confirm callback */
            SRV_OPS_STATE_TRANS(SRV_OPS_ACTIVE);
            srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID);
            srv_opps_notify_app(SRV_OPP_EVENT_START, NULL);
            return MMI_TRUE;
        }
        else
        {
            MMI_OPP_ASSERT(0);
        }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_sdpdb_deregister_req
 * DESCRIPTION
 *  This function is to deregister OPP SDP service record
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_sdpdb_deregister_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_deregister_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (bt_sdpdb_deregister_req_struct*) construct_local_para(sizeof(*req), TD_CTRL);

    req->uuid = SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID;
    srv_opp_send_ilm(MSG_ID_BT_SDPDB_DEREGISTER_REQ, (local_para_struct*) req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_sdpdb_deregister_cfn_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_opps_sdpdb_deregister_cfn_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_deregister_cnf_struct *cnf = (bt_sdpdb_deregister_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnf->uuid != SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID)
    {
        return MMI_FALSE;
    }

    if (srv_opps_p->opps_cntx.state == SRV_OPS_DEACTIVATING)
    {
        if (cnf->uuid == SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID && cnf->result == 0)
        {
            /* Send OPP deactivate request to OBEX */
            srv_opps_obex_deregister_server_req();
            return MMI_TRUE;
        }
    }
    return MMI_FALSE; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_authorize_ind_hdler
 * DESCRIPTION
 *  This function is to handle authorize indication from OBEX stack
 * PARAMETERS
 *  msg     [?]     
 *  sc_authorise_ind_p      [?](?)
 *  a(?)                    [IN/OUT]        First variable, used as returns(?)
 *  b(?)                    [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_authorize_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_authorize_ind_struct *ind = (goep_authorize_ind_struct*) msg;
    srv_opp_authorize_notify_struct auth_notify;
    srv_opps_cntx_struct* opps_cntx= &srv_opps_p->opps_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (opps_cntx->state == SRV_OPS_ACTIVE)
    {
        SRV_OPS_STATE_TRANS(SRV_OPS_AUTHORIZING);
        opps_cntx->goep_conn_id = ind->goep_conn_id;
        opps_cntx->dev_addr = *((srv_bt_cm_bt_addr*)&ind->bd_addr);
    
        auth_notify.conn_id = ind->goep_conn_id;
        strcpy((S8*)auth_notify.dev_name, (S8*)ind->dev_name);
        auth_notify.bt_addr = *((srv_bt_cm_bt_addr*)&ind->bd_addr);

        opps_cntx->cm_conn_id = srv_bt_cm_start_conn(MMI_TRUE, SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID,
            &(auth_notify.bt_addr), (S8*)ind->dev_name);
        if (opps_cntx->cm_conn_id < 0)
        {
            SRV_OPS_STATE_TRANS(SRV_OPS_ACTIVE);
            srv_opps_authorize_rsp(ind->goep_conn_id, GOEP_SERVICE_UNAVAILABLE);
            return;
        }
        srv_opps_notify_app(SRV_OPP_EVENT_AUTHORIZE_NOTIFY, (void*)&auth_notify);
    }
    else
    {
        srv_opps_authorize_rsp(ind->goep_conn_id, GOEP_SERVICE_UNAVAILABLE);
        /* Wrong OPS state */
        SRV_OPS_LOG_STATE_ERR();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_connect_ind_handler
 * DESCRIPTION
 *  This function is event handler for OBEX server connect indication (MSG_ID_BT_GOEP_CONNECT_IND)
 * PARAMETERS
 *  msg     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_connect_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_connect_ind_struct *ind = (goep_connect_ind_struct*) msg;
    srv_opp_conn_notify_struct conn_notify;
    srv_opps_cntx_struct* opps_cntx = &srv_opps_p->opps_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (opps_cntx->goep_conn_id != ind->goep_conn_id) return;
 
    switch (opps_cntx->state)
    {
        case SRV_OPS_AUTHORIZING:
            SRV_OPS_STATE_TRANS(SRV_OPS_CONNECTED);
            srv_opps_connect_rsp(opps_cntx->goep_conn_id, GOEP_STATUS_SUCCESS);

            conn_notify.type = SRV_OPP_CONN_SUCC;
            conn_notify.bt_addr = opps_cntx->dev_addr;

            srv_bt_cm_connect_ind(opps_cntx->cm_conn_id);
            srv_opps_notify_app(SRV_OPP_EVENT_CONN_NOTIFY, (void*)&conn_notify);

            break;
        case SRV_OPS_DISCONNECTING: /* Fall through */
        case SRV_OPS_DEACTIVATING:
            /* Do Nothing */
            break;
        default:
            SRV_OPS_LOG_STATE_ERR();
            srv_opps_connect_rsp(opps_cntx->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_abort_ind_handler
 * DESCRIPTION
 *  This function is event handler for OBEX abort indication (MSG_ID_GOEP_ABORT_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_abort_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_ind_struct *goep_abort_ind = (goep_abort_ind_struct*)msg;
    srv_opp_recv_notify_struct recv_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (goep_abort_ind->uuid_len != 0 || goep_abort_ind->uuid[0] != '\0')
    {
        MMI_OPP_ASSERT(0);
    }        
    
    if (goep_abort_ind->goep_conn_id == srv_opps_p->opps_cntx.goep_conn_id)
    {
        if (srv_opps_p->opps_cntx.state == SRV_OPS_RECEIVING)
        {
            /* close file */
            srv_opp_close_temp_obj();
            recv_notify.type = SRV_OPP_RECV_FAIL;
            recv_notify.u.err_code = SRV_OPP_RECEIVE_FAIL;

            srv_opps_notify_app(SRV_OPP_EVENT_RECV_NOTIFY, (void *)&recv_notify);
            SRV_OPS_STATE_TRANS(SRV_OPS_ACCEPTED);
        }
        /* send abort res to opp client */
        srv_opps_abort_rsp(srv_opps_p->opps_cntx.goep_conn_id, GOEP_STATUS_SUCCESS);
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }
}  


/*****************************************************************************
 * FUNCTION
 *  srv_opps_push_ind_handler
 * DESCRIPTION
 *  This function is OPP server event handler for push object indication (MSG_ID_GOEP_PUSH_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_push_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_ind_struct *ind = (goep_push_ind_struct*)msg;
    srv_opp_recv_notify_struct recv_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind->put_type != GOEP_PUT_NORMAL &&
        ind->put_type != GOEP_CREATEEMPTY)
    {
        /* Wrong put type, need clarify */
        srv_opps_push_rsp(
                srv_opps_p->opps_cntx.goep_conn_id,
                GOEP_STATUS_NOT_SUPPORTED);

        if (ind->pkt_type != GOEP_FIRST_PKT && ind->pkt_type != GOEP_SINGLE_PKT)
        {
            recv_notify.type = SRV_OPP_RECV_FAIL;
            recv_notify.u.err_code = SRV_OPP_PUT_TYPE;

            srv_opps_notify_app(SRV_OPP_EVENT_RECV_NOTIFY, (void *) &recv_notify);
        } 
        return;
    }

    switch (ind->pkt_type)
    {
    case GOEP_FIRST_PKT:
    case GOEP_SINGLE_PKT:
        srv_opps_first_push_ind_handler(ind);
        break;
    case GOEP_NORMAL_PKT:
        srv_opps_normal_push_ind_handler(ind);
        break;
    case GOEP_FINAL_PKT:
        srv_opps_final_push_ind_handler(ind);
        break;
    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_first_push_ind_handler
 * DESCRIPTION
 *  This function is OPP server event handler 
 *        for first push object indication (MSG_ID_GOEP_PUSH_IND)
 * PARAMETERS
 *  ind [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_first_push_ind_handler(goep_push_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_recv_notify_struct recv_notify;
    srv_opps_cntx_struct* opps_cntx = &srv_opps_p->opps_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG1(SRV_OPPS_FIRST_PUSH_IND, srv_opps_p->opps_cntx.state);
    
    switch (opps_cntx->state)
    {
        case SRV_OPS_CONNECTED:

            SRV_OPS_STATE_TRANS(SRV_OPS_ACCEPTING);
            srv_opp_hold_push_data(ind);

            srv_opp_truncate_obj_name(recv_notify.u.detail.name,
                (U16 *)ind->obj_name, sizeof(recv_notify.u.detail.name), MMI_TRUE);
            opps_cntx->obj_type = (U32) srv_fmgr_types_find_type_by_filename_str((WCHAR*)ind->obj_name);
            recv_notify.type = SRV_OPP_RECV_READY;
            recv_notify.conn_id = ind->goep_conn_id;
            recv_notify.bt_addr = opps_cntx->dev_addr;
            recv_notify.u.detail.total_len = ind->total_obj_len;
            strcpy((S8*)recv_notify.u.detail.mime_type, (S8*)ind->obj_mime_type);

            srv_opps_notify_app(SRV_OPP_EVENT_RECV_NOTIFY, (void *)&recv_notify);
            break;

        case SRV_OPS_ACCEPTED:        
            srv_opp_hold_push_data(ind);
            
            recv_notify.type = SRV_OPP_RECV_BEGIN;
            recv_notify.conn_id = ind->goep_conn_id;
            recv_notify.u.detail.total_len = ind->total_obj_len;
            strcpy((S8*)recv_notify.u.detail.mime_type, (S8*)ind->obj_mime_type);
            srv_opp_truncate_obj_name(recv_notify.u.detail.name,
                (U16 *)ind->obj_name, sizeof(recv_notify.u.detail.name), MMI_TRUE);
            opps_cntx->obj_type = (U32) srv_fmgr_types_find_type_by_filename_str((WCHAR*)ind->obj_name);
            srv_opps_notify_app(SRV_OPP_EVENT_RECV_NOTIFY, (void *)&recv_notify);
                  
            break;
            
        case SRV_OPS_DISCONNECTING:
        case SRV_OPS_DEACTIVATING:
            /* Do Nothing */
            break;
            
        default:
            /* Wrong OPS state */
            SRV_OPS_LOG_STATE_ERR();
            srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_next_push_ind_handler
 * DESCRIPTION
 *  This function is event handler for continuous next push object indication (MSG_ID_GOEP_PUSH_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_normal_push_ind_handler(goep_push_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void * data;
    U32 datalen;
    srv_opps_cntx_struct* opps_cntx = &srv_opps_p->opps_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG(SRV_OPPS_NEXT_PUSH_IND);

    if ((opps_cntx->state == SRV_OPS_DISCONNECTING) ||
        (opps_cntx->state == SRV_OPS_DEACTIVATING))
    {
        /* Do Nothing */
        return;
    }

    if (opps_cntx->state != SRV_OPS_RECEIVING)
    {
        /* Wrong OPS state */
        SRV_OPS_LOG_STATE_ERR();
        srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);
        return;
    }

    SRV_OPP_LOG2(SRV_OPPS_NEXT_PUSH_IND_FRAG_LEN, ind->frag_len, ind->total_obj_len);

#ifdef __MMI_BT_RX_ENHANCE__
    if (opps_cntx->stop_recv)
    {
        srv_opps_write_file_fail(opps_cntx->fs_err);
        return;
    }
    
    memcpy(opps_cntx->extra_buff, ind->frag_ptr, ind->frag_len);
    opps_cntx->extra_buflen = ind->frag_len;
    srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_STATUS_SUCCESS);

    data = opps_cntx->extra_buff;
    datalen = opps_cntx->extra_buflen;
#else
    data = ind->frag_ptr;
    datalen = ind->frag_len;
#endif

    if (datalen > 0)
    {
        S32 retval;
        retval = srv_opps_write_file(opps_cntx->h_recv, data, datalen, NULL, ind->pkt_type, MMI_FALSE);
#ifndef __MMI_BT_RX_ENHANCE__
        if (retval >= 0)
        {
            srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_STATUS_SUCCESS);
        }
#endif
    }
    else
    {
        srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_STATUS_SUCCESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_final_push_ind_handler
 * DESCRIPTION
 *  This function is event handler for continuous final push object indication (MSG_ID_GOEP_PUSH_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_final_push_ind_handler(goep_push_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opps_cntx_struct* opps_cntx = &srv_opps_p->opps_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG(SRV_OPPS_FINAL_PUSH_IND);

    if (opps_cntx->state == SRV_OPS_DISCONNECTING ||
        opps_cntx->state == SRV_OPS_DEACTIVATING)
    {
        /* Do Nothing */
        return;
    }

    if (opps_cntx->state != SRV_OPS_RECEIVING)
    {
        /* Wrong OPS state */
        SRV_OPS_LOG_STATE_ERR();
        srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);
        return;
    }

#ifdef __MMI_BT_RX_ENHANCE__
    if (opps_cntx->stop_recv)
    {
        srv_opps_write_file_fail(opps_cntx->fs_err);
        return;
    }
#endif    
    /* Final packet, Receive Finished !! */
    if (ind->frag_len > 0)
    {
        U32 len_written;
        S32 retval;

        retval = srv_opps_write_file(
                    opps_cntx->h_recv,
                    ind->frag_ptr,
                    ind->frag_len,
                    &len_written,
                    ind->pkt_type, MMI_FALSE);
        if (retval < FS_NO_ERROR)
        {
            return;
        }
    }

    if (opps_cntx->h_recv)
    {
        FS_Close(opps_cntx->h_recv);
        opps_cntx->h_recv = (FS_HANDLE)NULL;
    }
        
    srv_opps_obj_receive_ind(opps_cntx->obj_type);
}



/*****************************************************************************
 * FUNCTION
 *  srv_opps_proc_first_push_data
 * DESCRIPTION
 *  This function is process first push data
 * PARAMETERS
 *  ind [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_proc_first_push_data(goep_push_ind_struct *ind, U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 retval;
    srv_opp_recv_notify_struct recv_notify;
    srv_opps_cntx_struct* opps_cntx = &srv_opps_p->opps_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG(SRV_OPPS_PROC_FIRST_PUSH_IND);
   
        retval = FS_Open(path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    
    if (retval < FS_NO_ERROR)
    {
        srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_INTERNAL_SERVER_ERR);

        recv_notify.type = SRV_OPP_RECV_FAIL;
        recv_notify.u.err_code = srv_opp_convert_fs_err_to_opp_err(retval);;
        
        srv_opps_notify_app(SRV_OPP_EVENT_RECV_NOTIFY, (void *)&recv_notify);
        return;
    }
    
    SRV_OPS_STATE_TRANS(SRV_OPS_RECEIVING);
    
    opps_cntx->h_recv = retval;

#ifdef __MMI_BT_RX_ENHANCE__
    opps_cntx->stop_recv = MMI_FALSE;
#endif

    /* Write object context to file */
    if (ind->frag_len > 0)
    {
        U32 len_written;

        retval = srv_opps_write_file(
                        opps_cntx->h_recv,
                        ind->frag_ptr,
                        ind->frag_len,
                        &len_written,
                        ind->pkt_type, MMI_FALSE);
        if (retval < FS_NO_ERROR)
        {
            return;
        }
    }

    if (ind->pkt_type == GOEP_SINGLE_PKT)
    {
        if (opps_cntx->h_recv)
        {
            FS_Close(opps_cntx->h_recv);
            opps_cntx->h_recv = (FS_HANDLE)NULL;
        }
        srv_opps_obj_receive_ind(opps_cntx->obj_type);
    }
    else
    {
        srv_opps_push_rsp(opps_cntx->goep_conn_id, GOEP_STATUS_SUCCESS);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_pull_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_pull_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do not support pull indication */
    srv_opps_pull_rsp(srv_opps_p->opps_cntx.goep_conn_id, GOEP_INTERNAL_SERVER_ERR);
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_disconnect_ind_handler
 * DESCRIPTION
 *  This function is OPP server event handler for OBEX disconnect indication (MSG_ID_GOEP_DISCONNECT_IND)
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_disconnect_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_ind_struct *ind = (goep_disconnect_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG(SRV_OPPS_DISC_CONN_IND);    
        
    if (srv_opps_p->opps_cntx.goep_conn_id != ind->goep_conn_id)
    {
        MMI_OPP_ASSERT(0);
    }        

    if (SRV_OPS_ACTIVE <= srv_opps_p->opps_cntx.state &&
		srv_opps_p->opps_cntx.state <= SRV_OPS_DISCONNECTING)
    {
        /* Clean up padding session (callback, file handler...etc)  */
        srv_opps_connection_terminated();
    }
    else
    {
        SRV_OPS_LOG_STATE_ERR();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_send_disconnect_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX disconnect request
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_send_disconnect_req(U8 goep_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (goep_disconnect_req_struct*)construct_local_para(sizeof(*req), TD_CTRL);
    
    req->goep_conn_id = goep_conn_id;
    
    srv_opp_send_ilm(MSG_ID_GOEP_DISCONNECT_REQ, (local_para_struct*)req);
}


static void srv_opps_reject_connection(MMI_BOOL need_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (need_rsp)
    {
        srv_opps_push_rsp(srv_opps_p->opps_cntx.goep_conn_id, GOEP_NOT_ACCEPTABLE);
    }
    srv_opp_free_push_data();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_ops_connection_terminated
 * DESCRIPTION
 *  This is common function to deal with ops disconnect
 * PARAMETERS
 *  cause       [IN]        The cause for connection terminated
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_connection_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_disconn_notify_struct disconn_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPP_LOG(SRV_OPPS_CONN_TERM);
    SRV_OPP_LOG_STATE();

    srv_opp_close_temp_obj();

    if (srv_opps_p->opps_cntx.state == SRV_OPS_ACCEPTING)
    {
        srv_opps_reject_connection(MMI_FALSE);
    }

    SRV_OPS_STATE_TRANS(SRV_OPS_ACTIVE);

    disconn_notify.bt_addr = srv_opps_p->opps_cntx.dev_addr;

    srv_bt_cm_stop_conn(srv_opps_p->opps_cntx.cm_conn_id);
    srv_opps_notify_app(SRV_OPP_EVENT_DISCONN_NOTIFY,(void *)&disconn_notify);
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_authorize_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX authorize response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_authorize_rsp(U8 conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_authorize_res_struct *res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (goep_authorize_res_struct*)construct_local_para(sizeof(*res), TD_CTRL);
    
    res->goep_conn_id = (kal_uint8)conn_id;
    res->rsp_code = (kal_uint8)rsp_code;
    
    srv_opp_send_ilm(MSG_ID_GOEP_AUTHORIZE_RES, (local_para_struct*)res);
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_connect_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX connect response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_connect_rsp(U8 goep_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *ilm_ptr;
    goep_connect_res_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (goep_connect_res_struct*)construct_local_para(sizeof(*res), TD_CTRL);

    res->goep_conn_id = goep_conn_id;
    res->rsp_code = rsp_code;

    srv_opp_send_ilm(MSG_ID_GOEP_CONNECT_RES, (local_para_struct*)res);
}    


/*****************************************************************************
 * FUNCTION
 *  srv_opps_abort_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX abort response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_abort_rsp(U8 goep_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_res_struct *res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (goep_abort_res_struct*)construct_local_para(sizeof(*res), TD_CTRL);
    
    res->goep_conn_id = goep_conn_id;
    res->rsp_code = rsp_code;

    srv_opp_send_ilm(MSG_ID_GOEP_ABORT_RES, (local_para_struct*)res);
}    

/*****************************************************************************
 * FUNCTION
 *  srv_opps_push_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX push response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_push_rsp(U8 goep_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_res_struct *res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (goep_push_res_struct*)construct_local_para(sizeof(*res), TD_CTRL);
    
    res->goep_conn_id = goep_conn_id;
    res->rsp_code = rsp_code;

    srv_opp_send_ilm(MSG_ID_GOEP_PUSH_RES, (local_para_struct*)res);
}    


/*****************************************************************************
 * FUNCTION
 *  srv_opps_pull_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX pull response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_pull_rsp(U8 conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_pull_res_struct *res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res = (goep_pull_res_struct*)construct_local_para(sizeof(*res), TD_CTRL);
    
    res->goep_conn_id = (kal_uint8)conn_id;
    res->rsp_code = (kal_uint8)rsp_code;

    srv_opp_send_ilm(MSG_ID_GOEP_PULL_RES,(local_para_struct*)res);
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_opp_write_file
 * DESCRIPTION
 *  This function is to write file
 * PARAMETERS
 * void
 * RETURNS
 *  U16
 *****************************************************************************/
static S32 srv_opps_write_file(FS_HANDLE handle, void * data, U32 len, U32 * written, goep_pkt_type_enum pkt_type, 
                    MMI_BOOL close_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 retval;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retval = FS_Write(handle, data, len, written);
    SRV_OPP_LOG3(SRV_OPPS_WRITE_FILE, handle, len, retval);

    if (retval < FS_NO_ERROR)
    {
        srv_opp_close_temp_obj();
        if (pkt_type == GOEP_NORMAL_PKT)
        {
#ifdef __MMI_BT_RX_ENHANCE__  /* __MMI_BT_RX_ENHANCE__ */
            srv_opps_p->opps_cntx.stop_recv = MMI_TRUE;
            srv_opps_p->opps_cntx.fs_err = retval;
            return retval;
#endif
        }
        srv_opps_write_file_fail(retval);
    }
    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opps_write_file_fail
 * DESCRIPTION
 *  This function is to deal with write file failed
 * PARAMETERS
 * void
 * RETURNS
 *  U16
 *****************************************************************************/
static void srv_opps_write_file_fail(S32 fs_err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_recv_notify_struct recv_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SRV_OPS_STATE_TRANS(SRV_OPS_ACCEPTED);
    /* Send response to OBEX */
    srv_opps_push_rsp(srv_opps_p->opps_cntx.goep_conn_id, GOEP_INTERNAL_SERVER_ERR);

    recv_notify.type = SRV_OPP_RECV_FAIL;
    recv_notify.u.err_code = srv_opp_convert_fs_err_to_opp_err(fs_err);
    srv_opps_notify_app(SRV_OPP_EVENT_RECV_NOTIFY, (void *)&recv_notify);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_opp_obj_receive_ind
 * DESCRIPTION
 *  This function is to notify user that opp received a unrecognized object
 * PARAMETERS
 *  void
 *  path_src        [?](?)
 *  filename        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_obj_receive_ind(U32 obj_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_recv_notify_struct recv_notify;  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OPS_STATE_TRANS(SRV_OPS_ACCEPTED);
    srv_opps_push_rsp(srv_opps_p->opps_cntx.goep_conn_id, GOEP_STATUS_SUCCESS);
    recv_notify.type = SRV_OPP_RECV_SUCCESS;
    recv_notify.u.obj.mime = obj_type;
    srv_opps_notify_app(SRV_OPP_EVENT_RECV_NOTIFY, (void *)&recv_notify);
}

static void srv_opps_notify_app(U32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_opps_p->srv_hd >= SRV_OPP_SERVER_HANDLE_BEGIN
        && (srv_opps_p->event_mask & event_id))
        srv_opps_p->notifier(srv_opps_p->srv_hd, event_id, para);
}

#define MMI_OPP_UTILS_FUNC

static void srv_opp_send_ilm(msg_type msg_id, local_para_struct* local_para_p)
{
	srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, msg_id, (void*)local_para_p, NULL);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_gen_recv_path
 * DESCRIPTION
 *  This function is to truncate object name if exceeds max buffer size
 * PARAMETERS
 * new_name    [OUT]
 * old_name    [IN]
 * max_len     [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static void srv_opp_truncate_obj_name(U16 *dst_name, U16 *src_name, U16 max_dst_len, MMI_BOOL convert_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 src_name_len;
    U16 *p_ext, *p1;
    U32 ext_len;
    U32 copy_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_name == NULL)
    {
        mmi_wcscpy(dst_name, (U16*)MMI_OPP_SND_DEFAULT_OBJNAME);
    }
    else
    {
        if (convert_flag)
        {
            p1 = src_name;
        
            for(; *p1; p1++)
            {
                *p1 = srv_opp_ntohs(*p1);
            }
            *p1 = (U16)'\0';
        }

        
        src_name_len = mmi_wcslen(src_name);

        max_dst_len /= ENCODING_LENGTH;

        if (src_name_len < max_dst_len)
        {
            /* need not truncate */
            mmi_wcscpy(dst_name, src_name);   
        }
        else
        {
            /* need truncate */
            
            memset(dst_name, 0, max_dst_len * ENCODING_LENGTH);
            
            /* find filename ext */
            p_ext = (U16 *)mmi_wcsrchr(src_name, L'.');
            if(p_ext)
            {
                ext_len = mmi_wcslen(p_ext);

                if (ext_len > 5)
                {
                    p_ext[5] = L'\0';
                    ext_len = 5;
                }
            }
            else
            {
                ext_len = 0;
            }
            
            /* 1 char for '~'; 1 char for \0 */
            copy_len = max_dst_len - ext_len - 1 - 1 ;
            
            mmi_wcsncpy(dst_name, src_name, copy_len);
            mmi_wcscat(dst_name, (L"~"));
            if (p_ext)
            {
                mmi_wcscat(dst_name, p_ext);
            }
        }
    } 
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_ntohs
 * DESCRIPTION
 *  This function is to convert s.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
static U16 srv_opp_ntohs(U16 s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((s       & 0xFF) << 8) | \
           (((s >> 8) & 0xFF)));
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_get_obj_attrib
 * DESCRIPTION
 *  This function is to get file mimetype.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
static void srv_opp_get_obj_attrib(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BT_SLIM__
    S8 *mime;
    U16 len;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* Get object mime type */
#ifndef __MMI_BT_SLIM__
    mime = srv_opp_get_file_mime_type(srv_oppc_p->oppc_cntx.obj_name);
    if (mime != NULL)
    {
        len = strlen(mime);
        MMI_OPP_ASSERT(len <= OPP_MAX_OBJ_MIME_LENGTH);
        strcpy(srv_oppc_p->oppc_cntx.obj_mime, mime);
    }
    else
#endif
    {
        srv_oppc_p->oppc_cntx.obj_mime[0] = 0;
    }
}

#ifndef __MMI_BT_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_file_mime_type
 * DESCRIPTION
 *  This function is to get MIME type of a file.
 * PARAMETERS
 *  name        [IN]        The input file path
 * RETURNS
 *  void
 *****************************************************************************/
static S8 * srv_opp_get_file_mime_type(U16 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mime_type = applib_mime_get_file_type((kal_wchar*)name);

    if (mime_type == NULL)
    {
        /* OBEX allows to send a object without MIME */
        return NULL;
    }

    return (S8*)mime_type->mime_string;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_opp_close_temp_obj
 * DESCRIPTION
 *  This function is to clean unfinished receive file
 * PARAMETERS
 *  close_only       [IN]             
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_opp_close_temp_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 retval;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_opps_p->opps_cntx.h_recv == (FS_HANDLE)NULL)
    {
        return FS_NO_ERROR;
    }

    retval = FS_Close(srv_opps_p->opps_cntx.h_recv);

    if (retval == FS_INVALID_FILE_HANDLE)
    {
        /* Handle already been invalid(may because of foregroud Format),
            so here we need not to try close again */
        srv_opps_p->opps_cntx.h_recv = (FS_HANDLE)NULL;
        return FS_NO_ERROR;
    }
    if (retval >= FS_NO_ERROR)
    {
        srv_opps_p->opps_cntx.h_recv = (FS_HANDLE)NULL;
    }
    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_convert_fs_err_to_opp_err
 * DESCRIPTION
 *  This function is to set fs error flag
 * PARAMETERS
 *  err     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_opp_convert_fs_err_to_opp_err(S32 err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 opp_err;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (err)
    {            
        case FS_DISK_FULL:
            opp_err = SRV_OPP_DISK_FULL;
            break;
            
        case FS_ROOT_DIR_FULL:
            opp_err = SRV_OPP_ROOT_DIR_FULL;
            break;
            
        case FS_LOCK_MUTEX_FAIL:
        case FS_DEVICE_BUSY:
            opp_err = SRV_OPP_DEVICE_BUSY;
            break;
            
        case FS_MSDC_MOUNT_ERROR:
        case FS_MSDC_READ_SECTOR_ERROR:
        case FS_MSDC_WRITE_SECTOR_ERROR:
        case FS_MSDC_DISCARD_SECTOR_ERROR:
        case FS_MSDC_PRESNET_NOT_READY:
        case FS_MSDC_NOT_PRESENT:
        case FS_MEDIA_CHANGED:
            opp_err = SRV_OPP_MEDIA_CHANGED;
            break;
            
        case FS_WRITE_PROTECTION:
            opp_err = SRV_OPP_WRITE_PROTECT;
            break;
            
        default:
            opp_err = SRV_OPP_WRITE_FAIL;
            break;
    }
    return opp_err;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_hold_push_data
 * DESCRIPTION
 *  This function is to hold push data
 * PARAMETERS
 *  err     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opp_hold_push_data(goep_push_ind_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hold_local_para((local_para_struct *)data);
    srv_opps_p->opps_cntx.push_pkt = data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_opp_free_push_data
 * DESCRIPTION
 *  This function is to free push data
 * PARAMETERS
 *  err     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opp_free_push_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_opps_p->opps_cntx.push_pkt)
    {
        free_local_para((local_para_struct *)srv_opps_p->opps_cntx.push_pkt);
        srv_opps_p->opps_cntx.push_pkt = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_opps_disconnect_from_cm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conn_id        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_opps_disconnect_from_cm(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_opp_recv_notify_struct recv_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (conn_id == srv_opps_p->opps_cntx.cm_conn_id)
    {
        srv_opps_disconn_client(srv_opps_p->srv_hd);
	
		recv_notify.type = SRV_OPP_RECV_FAIL;
	    recv_notify.u.err_code = SRV_OPP_USER_ABORT;
		srv_opps_notify_app(SRV_OPP_EVENT_RECV_NOTIFY, (void *)&recv_notify);
    }
}
#endif /* __MMI_OPP_SUPPORT__ */ 

