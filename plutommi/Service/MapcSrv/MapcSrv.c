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
 * Btmapc_srv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for bluetooth map client profile and used by any application
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
 *-------------------------------------------------------------------------------------------*/


#include "MMI_features.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "Mmi_frm_mem_gprot.h"
#include "QueueGprot.h"
#ifdef __BT_MAP_CLIENT__
#include "MapcSrv.h"
#endif 
#include "Bluetooth_struct.h"
#include "DebugInitDef_Int.h"
#include "BTMMIScrGprots.h"
#ifdef __BT_MAP_CLIENT__
#define MMI_MAPC_STATE_TRANS(x)  \
{                                \
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_STATE_CHANGE,gmap_client_cntx_p->state,x);\
    gmap_client_cntx_p->state = (x);  \
}

srv_map_client_cntx_struct g_gmap_client_cntx;
srv_map_client_cntx_struct *gmap_client_cntx_p = &g_gmap_client_cntx;

typedef void (*srv_bt_mapc_notify_cb)(S32 srv_hd, srv_bt_mapc_cbevent_enum event, void* para);

void srv_bt_mapc_get_message_listing(U8 *child_folder);

/*****************************************************************************
 * FUNCTION
 * srv_mapc_send_msg
 * DESCRIPTION
 * response 
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_send_msg(msg_type msg_id, void *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send5(
        MOD_MMI,
        MOD_BT,
        BT_APP_SAP,
        (msg_type)msg_id,
        (local_para_struct*)p_local_para);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_disconnect_req
 * DESCRIPTION
 * response 
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_disconnect_req(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_disconnect_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_DISCONNECT,conn_id);

	msg=construct_local_para(sizeof(bt_mapc_disconnect_req_struct), TD_CTRL);
	if(gmap_client_cntx_p->mas_id >=0 && gmap_client_cntx_p->mas_id ==conn_id)
	{

	msg->addr.lap=gmap_client_cntx_p->bd_addr.lap;
	msg->addr.uap=gmap_client_cntx_p->bd_addr.uap;
	msg->addr.nap=gmap_client_cntx_p->bd_addr.nap;
	msg->mas_id=gmap_client_cntx_p->mas_id;
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_DISCONNECTING);
	srv_mapc_send_msg(MSG_ID_BT_MAPC_DISCONNECT_REQ,msg);
	}
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_activate_req
 * DESCRIPTION
 * Send mapc activate request
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_activate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(gmap_client_cntx_p->state == SRV_MAPC_STATE_INIT);
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ACTIVATE_REQ);
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_ACTIVATING);
    srv_mapc_send_msg(MSG_ID_BT_MAPC_ACTIVATE_REQ,NULL);


}
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_deactivate_req
 * DESCRIPTION
 * Send mapc deactivate request
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_deactivate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
		MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_DEACTIVATE_REQ);
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_DEACTIVATING);
		srv_mapc_send_msg(MSG_ID_BT_MAPC_DEACTIVATE_REQ,NULL);

}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_mapc_init
 * DESCRIPTION
 *  This function is to initialize MAP context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_profile_struct mapc_tbl;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_INIT);

	mapc_tbl.profile_id = SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID;
  mapc_tbl.activater = srv_bt_mapc_activate_req;
  mapc_tbl.deactivater = srv_bt_mapc_deactivate_req;
  mapc_tbl.disconnector = srv_bt_mapc_disconnect_req;

	memset( gmap_client_cntx_p, 0, sizeof(srv_map_client_cntx_struct));
	gmap_client_cntx_p->mas_id= -1;
	gmap_client_cntx_p->srv_hd= -1;
	gmap_client_cntx_p->user_data=NULL;
	gmap_client_cntx_p->srv_map_callback=NULL;
	gmap_client_cntx_p->mns_registration=SRV_MAPC_MNS_STATE_FALSE;
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_INIT);
	
	srv_bt_cm_profile_register((const srv_bt_cm_profile_struct*)&mapc_tbl);
  srv_mapc_set_event_hdlr();
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_mapc_deinit
 * DESCRIPTION
 *  This function is to initialize MAP context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_DEINIT);

	memset(gmap_client_cntx_p, 0,sizeof(srv_map_client_cntx_struct));
	gmap_client_cntx_p->mas_id= -1;
	gmap_client_cntx_p->srv_hd= -1;
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_INIT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_mapc_open
 * DESCRIPTION
 *  This function is to initialize MAP context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_mapc_open(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_OPEN,gmap_client_cntx_p->srv_hd);

	if(gmap_client_cntx_p->srv_hd <=0)
	{	gmap_client_cntx_p->srv_hd =MMI_TRUE;
		gmap_client_cntx_p->app_id=app_id;
		return MMI_TRUE;
	}
	else
		return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mapc_close
 * DESCRIPTION
 *  This function is to initialize MAP context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_mapc_close(U32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CLOSE,gmap_client_cntx_p->srv_hd);

	if(gmap_client_cntx_p->srv_hd ==srv_hd)
	{	gmap_client_cntx_p->srv_hd =-1;
		gmap_client_cntx_p->app_id=0;
		return MMI_TRUE;
	}
	else
		return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_mapc_register_callback
 * DESCRIPTION
 *  This function is to register the callback so that we can inform the above
 *  application about the events by calling this callback
 * PARAMETERS
 * srv_hd
 * srv_map_callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_register_callback(S32 srv_hd, srv_bt_mapc_notify_cb srv_map_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_map_callback!=NULL)
	{
	gmap_client_cntx_p->srv_map_callback=srv_map_callback;
	gmap_client_cntx_p->srv_hd=srv_hd;
	}
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
 #endif 
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_connect_req
 * DESCRIPTION
 * To start connection we need to have a connect req function 
 * PARAMETERS
 * dev_addr
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_connect_req(srv_bt_cm_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_connect_req_struct *msg;
	//bt_map_addr_struct bd_addr;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CONNECT,dev_addr.lap,dev_addr.uap,dev_addr.nap);
//	if(gmap_client_cntx_p->state == SRV_MAPC_STATE_CONNECTING)
   // {
  //      return;
  //  }
	ASSERT(gmap_client_cntx_p->state >= SRV_MAPC_STATE_ACTIVATED);
	if (gmap_client_cntx_p->state>=SRV_MAPC_STATE_CONNECTING||gmap_client_cntx_p->srv_map_callback==NULL)
		return; 
	
    gmap_client_cntx_p->mas_id=srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID, &dev_addr, NULL);
	
	
	msg=construct_local_para(sizeof(bt_mapc_connect_req_struct), TD_CTRL);
	
	msg->addr.lap= dev_addr.lap;
	msg->addr.nap= dev_addr.nap;
	msg->addr.uap= dev_addr.uap;
	msg->mas_id=gmap_client_cntx_p->mas_id;
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CONNECT,dev_addr.lap,dev_addr.uap,dev_addr.nap,msg->mas_id);
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_CONNECTING);
	
	srv_mapc_send_msg(MSG_ID_BT_MAPC_CONNECT_REQ,msg);
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_is_new_connection
 * DESCRIPTION
 * To start connection we need to have a connect req function 
 * PARAMETERS
 * dev_addr
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_mapc_is_new_connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(gmap_client_cntx_p->bd_addr.lap==gmap_client_cntx_p->prev_bd_addr.lap&&
		gmap_client_cntx_p->bd_addr.nap==gmap_client_cntx_p->prev_bd_addr.nap&&
		gmap_client_cntx_p->bd_addr.uap==gmap_client_cntx_p->prev_bd_addr.uap)
		return MMI_FALSE;
		return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 * srv_mapc_set_notify_registration_req
 * DESCRIPTION
 * To register at server end about the notification server receives from operator
 * and informs the client if client registers for notification 
 * PARAMETERS
 * val
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_set_notify_registration_req(MMI_BOOL val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
bt_mapc_set_notify_registration_req_struct *msg;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_REGISTRATION_REQ,gmap_client_cntx_p->state,val);
	
	if(gmap_client_cntx_p->state>= SRV_MAPC_STATE_CONNECTED)
	{
		msg=construct_local_para(sizeof(bt_mapc_set_notify_registration_req_struct), TD_CTRL);
		
	msg->mas_id=gmap_client_cntx_p->mas_id;
	msg->addr.lap=gmap_client_cntx_p->bd_addr.lap;
	msg->addr.uap=gmap_client_cntx_p->bd_addr.uap;
	msg->addr.nap=gmap_client_cntx_p->bd_addr.nap;
	msg->on=val;
	if(val==MMI_TRUE)
		gmap_client_cntx_p->mns_registration=SRV_MAPC_MNS_SETTING_TRUE;
	else
		gmap_client_cntx_p->mns_registration=SRV_MAPC_MNS_SETTING_FALSE;
		MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_SET_NOTIFY_REGISTRATION);
	srv_mapc_send_msg(MSG_ID_BT_MAPC_SET_NOTIFY_REGISTRATION_REQ,msg);
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_connect_cnf
 * DESCRIPTION
 * response 
 * PARAMETERS
 * dev_addr
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_connect_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_connect_cnf_struct *msg_p=NULL;
	srv_bt_mapc_connect_rsp  msg_u;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p=(bt_mapc_connect_cnf_struct *)msg;
	msg_u.Error=(srv_bt_mapc_result_enum)msg_p->result;
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CONNECT_CNF,gmap_client_cntx_p->state,msg_p->result);

	if((msg_p != NULL ) && (msg_p->result == SRV_BT_MAPC_SUCCESS))
	{
	//gmap_client_cntx_p->mas_id=msg_p->mas_id;
	gmap_client_cntx_p->bd_addr.lap=msg_p->addr.lap;
	gmap_client_cntx_p->bd_addr.nap=msg_p->addr.nap;
	gmap_client_cntx_p->bd_addr.uap=msg_p->addr.uap;
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_CONNECTED);
	//srv_mapc_set_notify_registration_req(MMI_TRUE);
	//(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_CONNECT_RSP,&msg_u);
	//notify application about the connection
	srv_mapc_set_notify_registration_req(MMI_TRUE);
	}
	else
	{
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_ACTIVATED);
	srv_bt_cm_stop_conn(gmap_client_cntx_p->mas_id);
	//gmap_client_cntx_p->mas_id=-1;
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_CONNECT_RSP,&msg_u);
	}
}



/*****************************************************************************
 * FUNCTION
 * srv_mapc_disconnect
 * DESCRIPTION
 * response 
 * PARAMETERS
 * dev_addr
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_disconnect(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gmap_client_cntx_p->user_data=user_data;
	srv_bt_mapc_disconnect_req(gmap_client_cntx_p->mas_id);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_disconnect_ind
 * DESCRIPTION
 * To inform the application about the disconnect indication and accordingly 
 * inform bt cm  
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/

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
#endif 
 void srv_bt_mapc_disconnect_ind(void *msg)
{
		bt_mapc_disconnect_ind_struct *msg_p= NULL;
		msg_p=(bt_mapc_disconnect_ind_struct *)msg;
		MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_DISCONNECT_IND,gmap_client_cntx_p->state,msg_p->mas_id);
		if((gmap_client_cntx_p->mas_id== msg_p->mas_id))
		{
  		srv_bt_cm_stop_conn(msg_p->mas_id );
  		//gmap_client_cntx_p->mas_id = -1;
		gmap_client_cntx_p->prev_bd_addr.lap=gmap_client_cntx_p->bd_addr.lap;
		gmap_client_cntx_p->prev_bd_addr.nap=gmap_client_cntx_p->bd_addr.nap;
		gmap_client_cntx_p->prev_bd_addr.uap=gmap_client_cntx_p->bd_addr.uap;
    	gmap_client_cntx_p->bd_addr.lap = 0;
    	gmap_client_cntx_p->bd_addr.uap = 0;
    	gmap_client_cntx_p->bd_addr.nap = 0;
    	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_ACTIVATED);
    	if(gmap_client_cntx_p->srv_map_callback!=NULL)
		(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_DISCONNECT_IND, NULL);
		}	

}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_disconnect_cnf
 * DESCRIPTION
 * Handle the disconnect confirmation from server side 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_disconnect_cnf(void *msg)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_DISCONNECT_CNF,gmap_client_cntx_p->state);	
	
	switch (gmap_client_cntx_p->state)
    {
        case SRV_MAPC_STATE_DISCONNECTING:
        case SRV_MAPC_STATE_DEACTIVATING:
        {		srv_bt_mapc_disconnect_rsp  msg_u;
        		bt_mapc_disconnect_cnf_struct *msg_w=NULL;
				msg_w= (bt_mapc_disconnect_cnf_struct *)msg;
				MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_DISCONNECT_IND,gmap_client_cntx_p->state,msg_w->mas_id);
				msg_u.Error=(srv_bt_mapc_result_enum)msg_w->result;
				msg_u.user_data=gmap_client_cntx_p->user_data;
				if((msg_w != NULL )&& (gmap_client_cntx_p->mas_id== msg_w->mas_id) && (msg_u.Error==SRV_BT_MAPC_SUCCESS))
				{
  				srv_bt_cm_stop_conn(msg_w->mas_id);
  				//gmap_client_cntx_p->mas_id = -1;
    			//gmap_client_cntx_p->mas_id = -1;
				gmap_client_cntx_p->prev_bd_addr.lap=gmap_client_cntx_p->bd_addr.lap;
				gmap_client_cntx_p->prev_bd_addr.nap=gmap_client_cntx_p->bd_addr.nap;
				gmap_client_cntx_p->prev_bd_addr.uap=gmap_client_cntx_p->bd_addr.uap;
    			gmap_client_cntx_p->bd_addr.lap = 0;
    			gmap_client_cntx_p->bd_addr.uap = 0;
    			gmap_client_cntx_p->bd_addr.nap = 0;
    			MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_ACTIVATED);
				}
				else
					MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_IDLE);
				if(gmap_client_cntx_p->srv_map_callback!=NULL)
				(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_DISCONNECT_RSP,&msg_u);
           
    		}
        default:
            break;       
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_abort_cnf
 * DESCRIPTION
 * Handle the abort request of any ongoing operation  
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_abort_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_abort_cnf_struct  *msg_p= NULL;
	srv_mapc_abort_cnf msg_u;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p= (bt_mapc_abort_cnf_struct *)msg;
	if(msg_p==NULL)
		return;
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ABORT_CNF,msg_p->result);	
	msg_u.Error=(srv_bt_mapc_result_enum)msg_p->result;
	msg_u.user_data=gmap_client_cntx_p->user_data;
	if(gmap_client_cntx_p->mas_id==msg_p->mas_id)
	{
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_ABORT_RSP,&msg_u);
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_abort_req
 * DESCRIPTION
 * To send the abort request for an ongoing operation at server end 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_abort_req(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_abort_req_struct  *msg_p;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ABORT_REQ,gmap_client_cntx_p->state);	

	msg_p=construct_local_para(sizeof(bt_mapc_abort_req_struct), TD_CTRL);

	if(gmap_client_cntx_p->state >= SRV_MAPC_STATE_IDLE)
	{
	msg_p->addr.lap=gmap_client_cntx_p->bd_addr.lap;
	msg_p->addr.uap=gmap_client_cntx_p->bd_addr.uap;
	msg_p->addr.nap=gmap_client_cntx_p->bd_addr.nap;
	msg_p->mas_id=gmap_client_cntx_p->mas_id;
	gmap_client_cntx_p->user_data=user_data;
	srv_mapc_send_msg(MSG_ID_BT_MAPC_ABORT_REQ,(void *)&msg_p);
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_folder_req
 * DESCRIPTION
 * To send the set folder request while folder navigation at server end
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_folder_req( U8 *folder,srv_btmapc_folder_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_set_folder_req_struct *msg;
	srv_bt_mapc_set_folder_res msg_rsp;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_FOLDER_REQ,gmap_client_cntx_p->state);

	msg=construct_local_para(sizeof(bt_mapc_set_folder_req_struct), TD_CTRL);
	if(flag == SRV_BT_MAPC_BACK &&gmap_client_cntx_p->folder_depth ==MAPC_ROOT_FOLDER_DEPTH)
	{
		msg_rsp.Error=SRV_BT_MAPC_FAIL_INVALID_PARAMETER;
		msg_rsp.user_data=gmap_client_cntx_p->user_data;
		(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_SET_FOLDER_RSP,&msg_rsp);
	}
	else if(gmap_client_cntx_p->state>=SRV_MAPC_STATE_IDLE)
	{
	msg->addr.lap=gmap_client_cntx_p->bd_addr.lap;
	msg->addr.uap=gmap_client_cntx_p->bd_addr.uap;
	msg->addr.nap=gmap_client_cntx_p->bd_addr.nap;
	msg->mas_id=gmap_client_cntx_p->mas_id;
	msg->flag=(bt_map_folder_op_enum)flag;
	app_ucs2_strncpy((kal_int8 *)msg->folder,(const kal_int8 *)folder,BT_MAP_MAX_FOLDER_NAME_LEN);
	app_ucs2_strcat((kal_int8 *)msg->folder,(const kal_int8 *)L"\0");
	app_ucs2_strncpy((kal_int8 *)gmap_client_cntx_p->child_folder,(const kal_int8 *)folder,BT_MAP_MAX_FOLDER_NAME_LEN);
	app_ucs2_strcat((kal_int8 *)gmap_client_cntx_p->child_folder,(const kal_int8 *)L"\0");	
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_GETTING_FOLDER);
	srv_mapc_send_msg(MSG_ID_BT_MAPC_SET_FOLDER_REQ,msg);
	}
}


// folder should name of the folder on which operation is taking place 
/*****************************************************************************
 * FUNCTION
 * srv_mapc_change_folder
 * DESCRIPTION
 * To send the set folder request while folder navigation at server end
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_mapc_change_folder(U8 *folder,srv_btmapc_folder_flag_enum flag,srv_bt_mapc_listing_enum list_type,void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CHANGE_FOLDER_REQ,gmap_client_cntx_p->state);
	if(gmap_client_cntx_p->state<SRV_MAPC_STATE_IDLE)
		return MMI_FALSE;
	if(flag<SRV_BT_MAPC_END)
	{
	gmap_client_cntx_p->user_data=user_data;
	gmap_client_cntx_p->get_msg_lst=list_type;
	gmap_client_cntx_p->folder_flag=flag;
	srv_bt_mapc_set_folder_req(folder,flag);
	}
	else if (flag ==SRV_BT_MAPC_END && list_type==SRV_BT_MAPC_MESSAGE_LIST_ONLY&& folder!=NULL)
	{
		srv_bt_mapc_get_message_listing((U8*)folder);
	}
	else
	{
		return MMI_FALSE;
	}
		return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_listing
 * DESCRIPTION
 * To send request to get message listing in a particular folder and first 
 * get folder listing size 
 * PARAMETERS
 * child_folder
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_message_listing(U8 *child_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_get_message_listing_size_req_struct *msg;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	msg=construct_local_para(sizeof(bt_mapc_get_message_listing_size_req_struct), TD_CTRL);

	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_LISTING_SIZE_REQ,gmap_client_cntx_p->state,(char*)msg->child_folder);
	
	if(gmap_client_cntx_p->state>=SRV_MAPC_STATE_IDLE)
	{
	msg->mas_id=gmap_client_cntx_p->mas_id;
	msg->addr.lap=gmap_client_cntx_p->bd_addr.lap;
	msg->addr.uap=gmap_client_cntx_p->bd_addr.uap;
	msg->addr.nap=gmap_client_cntx_p->bd_addr.nap;
	//app_ucs2_strncpy((char*),(const char *)child_folder,BT_MAP_MAX_FOLDER_NAME_LEN);
	app_ucs2_strcpy((kal_int8 * )msg->child_folder,(const kal_int8 *) child_folder);
	app_ucs2_strcat((kal_int8 * )msg->child_folder,(const kal_int8 *)L"\0");	
		MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_GETTING_MESSAGE_LISTING);

	srv_mapc_send_msg(MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_SIZE_REQ,msg);
	}
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_folder_cnf
 * DESCRIPTION
 * To handle the set folder req and send the folder listing size req 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_folder_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_set_folder_cnf_struct *msg_p= NULL;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	msg_p= (bt_mapc_set_folder_cnf_struct *)msg;

	ASSERT(msg_p);

	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_FOLDER_CNF,gmap_client_cntx_p->state,msg_p->result,gmap_client_cntx_p->get_msg_lst);
	
	if(msg_p->result==SRV_BT_MAPC_SUCCESS &&(gmap_client_cntx_p->get_msg_lst==SRV_BT_MAPC_MESSAGE_LIST_ONLY)&&
		(gmap_client_cntx_p->folder_flag==SRV_BT_MAPC_NEXT||gmap_client_cntx_p->folder_flag==SRV_BT_MAPC_FORWARD))
	{
		srv_bt_mapc_get_message_listing(gmap_client_cntx_p->child_folder);
	}
	else
	{
		srv_bt_mapc_set_folder_res msg_rsp;
		
		if(msg_p->result==SRV_BT_MAPC_SUCCESS)
		{
			if(gmap_client_cntx_p->folder_flag==SRV_BT_MAPC_ROOT)
		{
				//srv_mapc_change_folder(MAPC_ROOT_FOLDER2)
					U8 child_folder[SRV_BT_MAP_MAX_FOLDER_NAME_LEN+1];
					gmap_client_cntx_p->folder_depth=0;
					app_ucs2_strcpy((kal_int8 * )child_folder,(const kal_int8 *) L"telecom");
					app_ucs2_strcat((kal_int8 * )child_folder,(const kal_int8 *)L"\0");
					gmap_client_cntx_p->folder_flag=SRV_BT_MAPC_FORWARD;
					srv_bt_mapc_set_folder_req(child_folder,SRV_BT_MAPC_FORWARD);
					return;
		}
			else if(gmap_client_cntx_p->folder_flag==SRV_BT_MAPC_FORWARD&&gmap_client_cntx_p->folder_depth==0)
		{			U8 child_folder[SRV_BT_MAP_MAX_FOLDER_NAME_LEN+1];
					gmap_client_cntx_p->folder_depth++;
					app_ucs2_strcpy((kal_int8 *) child_folder,(const kal_int8 *) L"msg");
					app_ucs2_strcat((kal_int8 *) child_folder,(const kal_int8 *)L"\0");
					gmap_client_cntx_p->folder_flag=SRV_BT_MAPC_FORWARD;
					srv_bt_mapc_set_folder_req(child_folder,SRV_BT_MAPC_FORWARD);
					return;
		}
			else if(gmap_client_cntx_p->folder_flag==SRV_BT_MAPC_FORWARD)
		{
			gmap_client_cntx_p->folder_depth++;
		}
			else if(gmap_client_cntx_p->folder_flag==SRV_BT_MAPC_BACK)
			{
				gmap_client_cntx_p->folder_depth--;
			}
		}
		msg_rsp.Error=(srv_bt_mapc_result_enum)msg_p->result;
		msg_rsp.user_data=gmap_client_cntx_p->user_data;
		
		MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_FOLDER_CNF1,gmap_client_cntx_p->folder_depth);
		(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_SET_FOLDER_RSP,&msg_rsp);
	}	
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_folder_listing_cnf
 * DESCRIPTION
 * To handle the set folder listing req and send the get folder listing req 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif 

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_listing_size_cnf
 * DESCRIPTION
 * To send request to get message listing size  in a particular folder and then request 
 * for getting the folder listing size 
 * PARAMETERS
 * child_folder
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_message_listing_size_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_get_message_listing_req_struct *msg_req;
	bt_mapc_get_message_listing_size_cnf_struct *msg_p = NULL;
	srv_bt_mapc_set_msg_listing_prop_struct msg_list_prop=gmap_client_cntx_p->msg_lst_prop;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p=(bt_mapc_get_message_listing_size_cnf_struct *)msg;
	
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_LISTING_SIZE_CNF,gmap_client_cntx_p->state,msg_p->result);
	
	if(msg_p->result==SRV_BT_MAPC_SUCCESS)
	{
		msg_req=construct_local_para(sizeof(bt_mapc_get_message_listing_req_struct), TD_CTRL);
	
		msg_req->mas_id=gmap_client_cntx_p->mas_id;
		msg_req->addr.lap=gmap_client_cntx_p->bd_addr.lap;
		msg_req->addr.uap=gmap_client_cntx_p->bd_addr.uap;
		msg_req->addr.nap=gmap_client_cntx_p->bd_addr.nap;
		app_ucs2_strncpy((kal_int8 *)msg_req->child_folder,(const kal_int8 *)gmap_client_cntx_p->child_folder,BT_MAP_MAX_FOLDER_NAME_LEN);
		
		msg_req->list_offset=msg_list_prop.ListStartOffset;
		if(msg_p->list_size>msg_list_prop.Maxlistcount)
		{
			msg_req->list_size=msg_list_prop.Maxlistcount;
		}
		else
		{
		msg_req->list_size=msg_p->list_size;
		}
		msg_req->max_subject_len=msg_list_prop.SubjectLength;
		msg_req->mask=msg_list_prop.ParameterMask;
		msg_req->filter_msg=msg_list_prop.FilterMessageType;
		app_ucs2_strncpy((kal_int8 *)msg_req->filter_begin,(const kal_int8 *)msg_list_prop.FilterPeriodBegin,SRV_BT_MAP_MAX_DATE_STR_LEN);
		app_ucs2_strncpy((kal_int8 *)msg_req->filter_end,(const kal_int8 *)msg_list_prop.FilterPeriodEnd,SRV_BT_MAP_MAX_DATE_STR_LEN);
		msg_req->filter_status=(bt_map_filter_status_enum)msg_list_prop.FilterReadStatus;
		app_ucs2_strncpy((kal_int8 *)msg_req->filter_rec,(const kal_int8 *)msg_list_prop.FilterRecipient,SRV_BT_MAP_MAX_CONTACT_STR_LEN);
		app_ucs2_strncpy((kal_int8 *)msg_req->filter_orig,(const kal_int8 *)msg_list_prop.FilterOriginator,SRV_BT_MAP_MAX_CONTACT_STR_LEN);
		msg_req->filter_prio=(bt_map_filter_prio_enum)msg_list_prop.FilterPriority;
		MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_GETTING_MESSAGE_LISTING);
		srv_mapc_send_msg(MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_REQ,msg_req);

	}
	
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_listing_size_cnf
 * DESCRIPTION
 * To handle the message listing confirmation from server
 * PARAMETERS
 * child_folder
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_message_listing_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_mapc_message_listing_cnf msg_cnf;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bt_mapc_get_message_listing_cnf_struct *msg_p= (bt_mapc_get_message_listing_cnf_struct *)msg;

	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_LISTING_CNF,gmap_client_cntx_p->state,msg_p->result);
	gmap_client_cntx_p->get_msg_lst=SRV_BT_MAPC_NONE;
	msg_cnf.user_data=gmap_client_cntx_p->user_data;
	if(msg_p->result==SRV_BT_MAPC_SUCCESS)
	{
	msg_cnf.result=(srv_bt_mapc_result_enum)msg_p->result;
	msg_cnf.unread=msg_p->unread;
	msg_cnf.list_size=msg_p->list_size;
	app_ucs2_strncpy((kal_int8 *)msg_cnf.file,(const kal_int8 *)msg_p->file,BT_MAP_MAX_TEMP_FILE_NAME_LEN);
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_GET_MSG_LISTING_RSP,&msg_cnf);
	
	}
	else
	{
	//error handling need to update the application
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_ERROR,msg_p);
	}
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_IDLE);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_request
 * DESCRIPTION
 * To send request to a particular message 
 * PARAMETERS
 * child_folder
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_msg_req(U8 *handle,MMI_BOOL attachment,srv_bt_map_charset_enum charset,void *user_data)
{
	
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_get_message_req_struct *msg_req;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_REQ,handle,attachment,charset);
	
	if(gmap_client_cntx_p->state>= SRV_MAPC_STATE_IDLE)
	{
		msg_req=construct_local_para(sizeof(bt_mapc_get_message_req_struct), TD_CTRL);
	msg_req->mas_id=gmap_client_cntx_p->mas_id;
	msg_req->addr.lap=gmap_client_cntx_p->bd_addr.lap;
	msg_req->addr.uap=gmap_client_cntx_p->bd_addr.uap;
	msg_req->addr.nap=gmap_client_cntx_p->bd_addr.nap;
	app_ucs2_strncpy((kal_int8 *)msg_req->handle,(const kal_int8 *)handle,BT_MAP_MAX_HANDLE_STR_LEN);
	msg_req->attachment=attachment;
	msg_req->charset=(bt_map_charset_enum)charset;
	msg_req->fraction_req=BT_MAP_FRACTION_REQ_FIRST;
	gmap_client_cntx_p->user_data=user_data;	
		MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_GETTING_MESSAGE);

	srv_mapc_send_msg(MSG_ID_BT_MAPC_GET_MESSAGE_REQ,msg_req);
	}
	else
	{
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_ERROR,NULL);
	}

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_cnf
 * DESCRIPTION
 * To handle get message confirmation from server 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_message_cnf(void *msg)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_mapc_message_cnf_struct msg_cnf;
	bt_mapc_get_message_req_struct *msg_req;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bt_mapc_get_message_cnf_struct *msg_p=(bt_mapc_get_message_cnf_struct *)msg;

	
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_CNF,msg_p->result,msg_p->fraction_rsp);
	
	msg_cnf.Error=SRV_BT_MAPC_FAIL;
	msg_cnf.user_data=gmap_client_cntx_p->user_data;
	if(msg_p->result==SRV_BT_MAPC_SUCCESS)
	{
	if(msg_p->fraction_rsp==BT_MAP_FRACTION_RSP_MORE)
	{
			msg_req=construct_local_para(sizeof(bt_mapc_get_message_req_struct), TD_CTRL);
	msg_req->mas_id=gmap_client_cntx_p->mas_id;
	msg_req->addr.lap=gmap_client_cntx_p->bd_addr.lap;
	msg_req->addr.uap=gmap_client_cntx_p->bd_addr.uap;
	msg_req->addr.nap=gmap_client_cntx_p->bd_addr.nap;
	msg_req->attachment=MMI_FALSE;
	msg_req->charset=BT_MAP_CHARSET_UTF8;
	msg_req->fraction_req=BT_MAP_FRACTION_REQ_NEXT;
			MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_GETTING_MESSAGE);
	srv_mapc_send_msg(MSG_ID_BT_MAPC_GET_MESSAGE_REQ,msg_req);
	}
	else if(msg_p->fraction_rsp==BT_MAP_FRACTION_RSP_LAST)
	{
	msg_cnf.Error=(srv_bt_mapc_result_enum)msg_p->result;
	msg_cnf.data_size=msg_p->data_size;
	app_ucs2_strncpy((kal_int8 *)msg_cnf.file,(const kal_int8 *)msg_p->file,SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN);
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_GET_MSG_RSP,&msg_cnf);
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_IDLE);
	}
	
	}
	else
	//update application about the error in retrieving the message.
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_GET_MSG_RSP,&msg_cnf);
	
}



/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_message_status_req
 * DESCRIPTION
 * To update the status of the message like delete or make it as read or unread 
 * PARAMETERS
 * status_val
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_message_status_req(U8 *handle,srv_bt_mapc_msg_status_enum status_val,void *user_data)
{	
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_set_message_status_req_struct *msg;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_MSG_STATUS,handle,status_val,gmap_client_cntx_p->state);
	//kal_wap_trace("BTaddr: lap %d  uap %d nap %d ",gmap_client_cntx_p->bd_addr.lap,(int)gmap_client_cntx_p->bd_addr.uap,(int)gmap_client_cntx_p->bd_addr.nap);
	if(gmap_client_cntx_p->state >=SRV_MAPC_STATE_IDLE)
	{	
		msg=construct_local_para(sizeof(bt_mapc_set_message_status_req_struct), TD_CTRL);		
		msg->mas_id=gmap_client_cntx_p->mas_id;
		msg->addr.lap=gmap_client_cntx_p->bd_addr.lap;
		msg->addr.uap=gmap_client_cntx_p->bd_addr.uap;
		msg->addr.nap=gmap_client_cntx_p->bd_addr.nap;
		app_ucs2_strncpy((kal_int8 *)msg->handle,(const kal_int8 *)handle,BT_MAP_MAX_HANDLE_STR_LEN+2);
		msg->status=(bt_map_msg_status_enum)status_val;
		gmap_client_cntx_p->user_data=user_data;
		MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_SET_MESSAGE_STATUS);
		srv_mapc_send_msg(MSG_ID_BT_MAPC_SET_MESSAGE_STATUS_REQ,msg);
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_push_message_req
 * DESCRIPTION
 * To push message which is composed at client end to the server 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_push_message_req(srv_bt_mapc_push_message_req_struct *msg,void *user_data)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_push_message_req_struct *msg_req;
	srv_bt_mapc_push_message_status_res msg_res;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	srv_bt_mapc_push_message_req_struct *msg_p= (srv_bt_mapc_push_message_req_struct *)msg;

	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_PUSH_MSG_REQ,msg_p->child_folder,gmap_client_cntx_p->state);
	
	if(gmap_client_cntx_p->state >=SRV_MAPC_STATE_IDLE)
	{
		msg_req=construct_local_para(sizeof(bt_mapc_push_message_req_struct), TD_CTRL);		
		msg_req->mas_id=gmap_client_cntx_p->mas_id;
		msg_req->addr.lap=gmap_client_cntx_p->bd_addr.lap;
		msg_req->addr.uap=gmap_client_cntx_p->bd_addr.uap;
		msg_req->addr.nap=gmap_client_cntx_p->bd_addr.nap;
		app_ucs2_strncpy((kal_int8 *)msg_req->child_folder,(const kal_int8 *)msg_p->child_folder,SRV_BT_MAP_MAX_FOLDER_NAME_LEN);
		msg_req->sent_op=BT_MAP_SENT;
		msg_req->retry=MMI_FALSE;
		msg_req->charset=BT_MAP_CHARSET_UTF8;
		app_ucs2_strncpy((kal_int8 *)msg_req->file,(const kal_int8 *)msg_p->file,BT_MAP_MAX_TEMP_FILE_NAME_LEN);
		msg_req->data_size=msg_p->data_size;
		gmap_client_cntx_p->user_data=user_data;
		MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_PUSHING_MESSAGE);	
		srv_mapc_send_msg(MSG_ID_BT_MAPC_PUSH_MESSAGE_REQ,msg_req);
	
	}
	else
	{
	//send application failure of message if not connected
	msg_res.Error=SRV_BT_MAPC_FAIL;
	memset(msg_res.Handle,0,MAP_MAX_HANDLE_STR_UCS2_LEN+2);
	msg_res.user_data=msg_p->user_data;
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_PUSH_MSG_RSP,&msg_res);
	}
	

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_push_message_cnf
 * DESCRIPTION
 * To handle the rsp from server about the push message feature
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_push_message_cnf(void *msg)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_mapc_push_message_status_res msg_res;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	bt_mapc_push_message_cnf_struct  *msg_p= (bt_mapc_push_message_cnf_struct  *)msg;
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_PUSH_MSG_CNF,msg_p->result);
	msg_res.Error=(srv_bt_mapc_result_enum)msg_p->result;
	app_ucs2_strncpy((kal_int8 *)msg_res.Handle,(const kal_int8 *)msg_p->handle,MAP_MAX_HANDLE_STR_UCS2_LEN+2);
	msg_res.user_data=gmap_client_cntx_p->user_data;
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_PUSH_MSG_RSP,&msg_res);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_update_inbox_req
 * DESCRIPTION
 * To send request to server so that it can update the inbox and we can get the latest 
 * message 
 * PARAMETERS
 * void 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_update_inbox_req(void )
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_update_inbox_req_struct *msg;
	srv_bt_mapc_update_inbox_res msg_w;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_UPDATE_INBOX,gmap_client_cntx_p->state);
	if(gmap_client_cntx_p->state >=SRV_MAPC_STATE_IDLE)
	{
		msg=construct_local_para(sizeof(bt_mapc_update_inbox_req_struct), TD_CTRL);
		msg->mas_id=gmap_client_cntx_p->mas_id;
		msg->addr.lap=gmap_client_cntx_p->bd_addr.lap;
		msg->addr.uap=gmap_client_cntx_p->bd_addr.uap;
		msg->addr.nap=gmap_client_cntx_p->bd_addr.nap;
		MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_UPDATING_INBOX);
		srv_mapc_send_msg(MSG_ID_BT_MAPC_UPDATE_INBOX_REQ,msg);
	}
	else
	{
		msg_w.Error=SRV_BT_MAPC_FAIL;
		msg_w.user_data=NULL;
	// unable to update the inbox from first check connection
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_UPDATE_INBOX_RSP,&msg_w);
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_update_inbox_req
 * DESCRIPTION
 * To handle the inbox update request 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_update_inbox_cnf(void *msg)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_update_inbox_cnf_struct *msg_p=(bt_mapc_update_inbox_cnf_struct *)msg;
	srv_bt_mapc_update_inbox_res msg_w;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_UPDATE_INBOX_CNF,msg_p->result);
	msg_w.Error=(srv_bt_mapc_result_enum)msg_p->result;
	msg_w.user_data=gmap_client_cntx_p->user_data;
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_UPDATE_INBOX_RSP,&msg_w);

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_notify_registration_cnf
 * DESCRIPTION
 * To notify server to start notification service so that it can inform client 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_notify_registration_cnf(void *msg)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*------------------------------btmmiscr----------------------------------*/
	 srv_bt_mapc_connect_rsp  msg_u;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bt_mapc_set_notify_registration_cnf_struct *msg_p=(bt_mapc_set_notify_registration_cnf_struct *)msg;

MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_NOTIFY_REG_CNF,msg_p->result);

	if(msg_p->result==SRV_BT_MAPC_SUCCESS&&msg_p->mas_id==gmap_client_cntx_p->mas_id)
	{
		if(gmap_client_cntx_p->mns_registration==SRV_MAPC_MNS_SETTING_TRUE)
			gmap_client_cntx_p->mns_registration=SRV_MAPC_MNS_STATE_TRUE;
		else
			gmap_client_cntx_p->mns_registration=SRV_MAPC_MNS_STATE_FALSE;
		
	}
	msg_u.Error=SRV_BT_MAPC_SUCCESS;
	msg_u.user_data=gmap_client_cntx_p->user_data;
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_IDLE);
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_CONNECT_RSP,&msg_u);

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_message_status_cnf
 * DESCRIPTION
 * To handle the set message status request's response  
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_message_status_cnf(void *msg)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_mapc_set_message_status_rsp msg_rsp;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	bt_mapc_set_message_status_cnf_struct *msg_p=(bt_mapc_set_message_status_cnf_struct*)msg;

	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_MSG_STATUS_CNF,msg_rsp.Error);

	msg_rsp.Error=(srv_bt_mapc_result_enum)msg_p->result;
	msg_rsp.user_data=gmap_client_cntx_p->user_data;
	MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_IDLE);
	(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_SET_MSG_STATUS_RSP,(void *)&msg_rsp);
		
}


/*****************************************************************************
 * FUNCTION
 * srv_mapc_mns_authorize_ind
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif 

/*****************************************************************************
 * FUNCTION
 * srv_mapc_activate_cnf
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_activate_cnf(void *msg)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		bt_mapc_activate_cnf_struct *msg_p = (bt_mapc_activate_cnf_struct*) msg;
   MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ACTIVATE_CNF,gmap_client_cntx_p->state,msg_p->result);

    if (msg_p->result == SRV_BT_MAPC_SUCCESS)
    {
        if (gmap_client_cntx_p->state == SRV_MAPC_STATE_ACTIVATING)
        {
            MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_ACTIVATED);
            srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID);// ITS VALUE IS 0X1132
        }
    }
	else
	{
		MMI_ASSERT(0);
	}
	
}

/*****************************************************************************
 * FUNCTION
 * srv_mapc_deactivate_cnf
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_deactivate_cnf(void *msg)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bt_mapc_deactivate_cnf_struct *msg_p = (bt_mapc_deactivate_cnf_struct*) msg;

   	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ACTIVATE_CNF,gmap_client_cntx_p->state,msg_p->result);
 
    if (gmap_client_cntx_p->state == SRV_MAPC_STATE_DEACTIVATING)
    {
        if (msg_p->result == SRV_BT_MAPC_SUCCESS)
        {
            MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_INIT);
            srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID);
        }
    }
	else
	{
		MMI_ASSERT(0);
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_mns_send_event_ind
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_mns_send_event_ind(void *msg)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_mapc_mns_send_event_ind_struct msg_ind;
	srv_bt_mapc_mns_send_event_rsp_struct ind_rsp;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bt_mapc_mns_send_event_ind_struct *msg_p= (bt_mapc_mns_send_event_ind_struct *)msg;

	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_MNS_EVENT_IND,gmap_client_cntx_p->state,(char*)msg_p->file);
	if (gmap_client_cntx_p->state >= SRV_MAPC_STATE_IDLE)
	{
			msg_ind.data_size=msg_p->data_size;
			app_ucs2_strncpy((kal_int8 *)msg_ind.file,(const kal_int8 *)msg_p->file,SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN);
			(*gmap_client_cntx_p->srv_map_callback)(gmap_client_cntx_p->srv_hd,SRV_BT_MAPC_EVT_ID_MNS_IND,(void *)&msg_ind);
	}
	else
	{
			ind_rsp.result=SRV_BT_MAPC_FAIL;
			srv_bt_mapc_mns_send_event_rsp(ind_rsp);
	}	
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_mns_send_event_rsp
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_mns_send_event_rsp (srv_bt_mapc_mns_send_event_rsp_struct indication_rsp)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_mns_send_event_rsp_struct *msg_rsp;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	msg_rsp=construct_local_para(sizeof(bt_mapc_mns_send_event_rsp_struct), TD_CTRL);
	msg_rsp->result= (bt_map_result_enum)indication_rsp.result;
	
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_MNS_EVENT_IND_RSP,msg_rsp->result);
	
	msg_rsp->addr.lap=gmap_client_cntx_p->bd_addr.lap;
	msg_rsp->addr.uap=gmap_client_cntx_p->bd_addr.uap;
	msg_rsp->addr.nap=gmap_client_cntx_p->bd_addr.nap;
	msg_rsp->mas_id=gmap_client_cntx_p->mas_id;
	srv_mapc_send_msg(MSG_ID_BT_MAPC_MNS_SEND_EVENT_RSP,msg_rsp);
}

/*****************************************************************************
 * FUNCTION
 * srv_mapc_set_event_hdlr
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_set_event_hdlr(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SetProtocolEventHandler((PsFuncPtr) srv_mapc_activate_cnf, MSG_ID_BT_MAPC_ACTIVATE_CNF);
	SetProtocolEventHandler((PsFuncPtr) srv_mapc_deactivate_cnf, MSG_ID_BT_MAPC_DEACTIVATE_CNF);
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_connect_cnf, MSG_ID_BT_MAPC_CONNECT_CNF);
	#if 0
/* under construction !*/
	#endif
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_disconnect_cnf, MSG_ID_BT_MAPC_DISCONNECT_CNF);
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_disconnect_ind, MSG_ID_BT_MAPC_DISCONNECT_IND);
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_mns_send_event_ind, MSG_ID_BT_MAPC_MNS_SEND_EVENT_IND);
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_abort_cnf, MSG_ID_BT_MAPC_ABORT_CNF);
	
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_set_folder_cnf, MSG_ID_BT_MAPC_SET_FOLDER_CNF);
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif 
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_get_message_listing_size_cnf, MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_SIZE_CNF);
	
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_get_message_listing_cnf, MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_CNF);
	
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_get_message_cnf, MSG_ID_BT_MAPC_GET_MESSAGE_CNF);
	
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_set_notify_registration_cnf, MSG_ID_BT_MAPC_SET_NOTIFY_REGISTRATION_CNF);
	
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_update_inbox_cnf, MSG_ID_BT_MAPC_UPDATE_INBOX_CNF);
	
	SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_set_message_status_cnf, MSG_ID_BT_MAPC_SET_MESSAGE_STATUS_CNF);
	
	
	
}

S8 srv_bt_mapc_set_msg_listing_prop(srv_bt_mapc_set_msg_listing_prop_struct * msg)
{
	srv_bt_mapc_set_msg_listing_prop_struct *msg_p=NULL;
	msg_p=(srv_bt_mapc_set_msg_listing_prop_struct *)msg;
	
	if (gmap_client_cntx_p->state >= SRV_MAPC_STATE_IDLE)
	{
		gmap_client_cntx_p->msg_lst_prop.FilterMessageType=msg_p->FilterMessageType;
		gmap_client_cntx_p->msg_lst_prop.Maxlistcount=msg_p->Maxlistcount;
		gmap_client_cntx_p->msg_lst_prop.ListStartOffset=msg_p->ListStartOffset;
		gmap_client_cntx_p->msg_lst_prop.FilterReadStatus=msg_p->FilterReadStatus;
		gmap_client_cntx_p->msg_lst_prop.FilterPriority=msg_p->FilterPriority;
		gmap_client_cntx_p->msg_lst_prop.SubjectLength=msg_p->SubjectLength;
		app_ucs2_strncpy((kal_int8 *)gmap_client_cntx_p->msg_lst_prop.FilterPeriodBegin,(const kal_int8 *)msg_p->FilterPeriodBegin,SRV_BT_MAP_MAX_DATE_STR_LEN);
		app_ucs2_strncpy((kal_int8 *)gmap_client_cntx_p->msg_lst_prop.FilterPeriodEnd,(const kal_int8 *)msg_p->FilterPeriodEnd,SRV_BT_MAP_MAX_DATE_STR_LEN);
		app_ucs2_strncpy((kal_int8 *)gmap_client_cntx_p->msg_lst_prop.FilterRecipient,(const kal_int8 *)msg_p->FilterRecipient,SRV_BT_MAPC_FILTER_SIZE);
		app_ucs2_strncpy((kal_int8 *)gmap_client_cntx_p->msg_lst_prop.FilterOriginator,(const kal_int8 *)msg_p->FilterOriginator,SRV_BT_MAPC_FILTER_SIZE);
		MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_SET_MSG_LISTING_PROPERTY)
		return 0;
		
	}
	else
	{
		return (S8)-1;
	}

}


/*****************************************************************************
 * FUNCTION
 * srv_mapc_event_handle
 * DESCRIPTION
 * Main handler function to handle all the events and messages  
 * of any events 
 * message 
 * PARAMETERS
 * msg_id
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
/* 
void srv_mapc_event_handle(msg_type msg_id, void *msg)
{
   switch (msg_id)
   {
   case MSG_ID_BT_MAPC_ACTIVATE_CNF:
   {
   
   bt_mapc_activate_cnf_struct *msg_p = (bt_mapc_activate_cnf_struct*) msg;
   
    if (msg_p->result == SRV_BT_MAPC_SUCCESS)
    {
        if (gmap_client_cntx_p->state == SRV_MAPC_STATE_ACTIVATING)
        {
            MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_ACTIVATED);
            srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID);// ITS VALUE IS 0X1132
        }
    }
    else
    {
        ASSERT(0);
    }
	
   MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_ACTIVATED);
   }
   break;
   
   
   
   case MSG_ID_BT_MAPC_DEACTIVATE_CNF:
   	{
       
    bt_mapc_deactivate_cnf_struct *msg_p = (bt_mapc_deactivate_cnf_struct*) msg;

    if (gmap_client_cntx_p->state == SRV_MAPC_STATE_DEACTIVATING)
    {
        if (msg_p->result == SRV_BT_MAPC_SUCCESS)
        {
            MMI_MAPC_STATE_TRANS(SRV_MAPC_STATE_IDLE);
            srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID);
        }
        else
        {
            ASSERT(0);
        }
    }
  	}
		break;
	
	
	
		case MSG_ID_BT_MAPC_CONNECT_CNF:
		{
		srv_bt_mapc_connect_cnf(&msg);
		}
		break;
	
	
		case MSG_ID_BT_MAPC_MNS_AUTHORIZE_IND:
		{
		srv_mapc_mns_authorize_ind(&msg);
		}
		break;
	
	
		case MSG_ID_BT_MAPC_DISCONNECT_CNF:
		{
		srv_bt_mapc_disconnect_cnf(&msg);
		}
		break;
	
	
		case MSG_ID_BT_MAPC_DISCONNECT_IND:
		{
		srv_bt_mapc_disconnect_ind(&msg);
		}
		break;
	
	
		case MSG_ID_BT_MAPC_ABORT_CNF:
		{
		srv_bt_mapc_abort_cnf(&msg);
		}
		break;
	
	
		case MSG_ID_BT_MAPC_SET_FOLDER_CNF:
		{
		srv_bt_mapc_set_folder_cnf(&msg);
		}
		break;
	
		case MSG_ID_BT_MAPC_GET_FOLDER_LISTING_SIZE_CNF:
		{
		srv_bt_mapc_get_folder_listing_size_cnf(&msg);
		}
		break;
	
	
		case MSG_ID_BT_MAPC_GET_FOLDER_LISTING_CNF:
		{	
			srv_bt_mapc_get_folder_listing_cnf(&msg);
		
		}
		break;
	
	
		case MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_SIZE_CNF:
		{
		srv_bt_mapc_get_message_listing_size_cnf(&msg);
		}
		break;
   
   case MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_CNF:
  	{
   	srv_bt_mapc_get_message_listing_cnf(&msg);
   
  	}
   
   break;
   case MSG_ID_BT_MAPC_GET_MESSAGE_CNF:
   	{
   	srv_bt_mapc_get_message_cnf(&msg);
  	}
   break;
   
   
   
   case MSG_ID_BT_MAPC_SET_NOTIFY_REGISTRATION_CNF:
   	{
   	srv_bt_mapc_set_notify_registration_cnf(&msg);
  	}
   break;
   case MSG_ID_BT_MAPC_UPDATE_INBOX_CNF:
   {
   	srv_bt_mapc_update_inbox_cnf(&msg);
  	}
   break;
   case MSG_ID_BT_MAPC_SET_MESSAGE_STATUS_CNF:
   	{
   	srv_bt_mapc_set_message_status_cnf(&msg);
  	}
   break;
   }
}
*/
#endif 
