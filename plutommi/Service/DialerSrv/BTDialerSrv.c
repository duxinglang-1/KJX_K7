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
 * BtDialersrv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM main application flow and utilities.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================*/

#include "MMI_features.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "bluetooth_bm_struct.h"
#include "bt_dm_struct.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "Mmi_frm_mem_gprot.h"
#include "QueueGprot.h"
#include "bt_adp_hf.h"
#include "BtcmSrvGprot.h"
#include "BTDialerSrvGprot.h"
#include "BTDialerSrv.h"
#include "Mdi_audio.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "QueueGprot_Int.h"
#include "BthScoPathSrvGProt.h"
#include "Tst_def.h"
#include "mmi_res_range_def.h"
#include "GpioSrvGprot.h"
#include "VolumeHandler.h"
#define _BT_DIALERSRV_TEST_CODE 1 //test code macro

#ifdef __BT_DIALER_SUPPORT__
#ifdef _BT_DIALERSRV_TEST_CODE
void mmi_dummy_bt_dialer_register_hf_event(int srv_hd , srv_bt_dialer_notify_event_struct notify);
U8  mmi_bt_proc_inject_string(U8 index, kal_uint8* string);
void srv_bt_dialer_dump_trace_info(void *buf, int buf_len);

#endif //_BT_DIALERSRV_TEST_CODE

static srv_bt_dialer_g_struct g_srv_bt_dialer_cntx;
static srv_bt_dialer_g_struct *g_bt_dialer_cntx = &g_srv_bt_dialer_cntx;
static int srv_dialer_handle;


#define SRV_BT_DIALER_STATE_TRANS(x)		(g_bt_dialer_cntx->state = x)
#define SRV_BT_DIALER_SET_CONN_ID(x)		(g_bt_dialer_cntx->conn_id = x)
#define SRV_BT_DIALER_GET_CONN_ID			(g_bt_dialer_cntx->conn_id)
#define SRV_BT_DIALER_SET_CM_CONN_ID(x)		(g_bt_dialer_cntx->cm_conn_id = x)
#define SRV_BT_DIALER_GET_CM_CONN_ID		(g_bt_dialer_cntx->cm_conn_id)
#define SRV_BT_DIALER_SET_HS_CONN(x)		(g_bt_dialer_cntx->hs_conn = x)
#define SRV_BT_DIALER_SRV_HANDLE			(g_bt_dialer_cntx->srv_hd)
#define SRV_BT_DIALER_IS_SRV_HANDLE_VALID	(g_bt_dialer_cntx->srv_hd > 0)

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_init
 * DESCRIPTION
 *  this function is to initialize the BT Dialer global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_profile_struct profile_info_p;
    U32 cm_evt = SRV_BT_CM_EVENT_CONNECT_RES |
                 SRV_BT_CM_EVENT_DISCONNECT_IND;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	profile_info_p.profile_id	= SRV_BT_CM_HF_PROFILE_UUID;
	profile_info_p.activater	= srv_bt_dialer_send_activate_req;
	profile_info_p.deactivater	= srv_bt_dialer_send_deactivate_req;
	profile_info_p.disconnector = srv_bt_dialer_send_disconnect_req;
	srv_bt_cm_profile_register((const srv_bt_cm_profile_struct *)&profile_info_p);

	memset(g_bt_dialer_cntx, 0, sizeof(srv_bt_dialer_g_struct));
	g_bt_dialer_cntx->srv_hd = -1;
	SRV_BT_DIALER_SET_CM_CONN_ID(MMI_HF_INVALID_CONN_ID);	
	SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_IDLE);
	
    srv_bt_cm_set_notify(srv_bt_dailer_cm_notify_hdlr, cm_evt, NULL);
	
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_INIT_OPERATION);
	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CONNECT_IND_REQ, (PsIntFuncPtr)srv_bt_dialer_connect_ind, MMI_TRUE);		
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_DISCONNECT_IND, (PsIntFuncPtr)srv_bt_dialer_disconnect_ind, MMI_TRUE);		
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VGM_CNF, (PsIntFuncPtr)srv_bt_dialer_vgm_cnf_hdlr, MMI_TRUE);			
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VGS_IND, (PsIntFuncPtr)srv_bt_dialer_vgs_ind, MMI_TRUE);				
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VGM_IND, (PsIntFuncPtr)srv_bt_dialer_vgm_ind_hdlr, MMI_TRUE);					
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_RING_IND, (PsIntFuncPtr)srv_bt_dialer_ring_ind_hdlr, MMI_TRUE);	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BSIR_IND, (PsIntFuncPtr)srv_bt_dialer_bsir_ind, MMI_TRUE);		
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_SERVICE_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_service_ind, MMI_TRUE);		
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_CALL_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_call_ind, MMI_TRUE);			
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_CALLSETUP_IND, (PsIntFuncPtr)srv_bt_dialer_callsetup_ind, MMI_TRUE);				
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_CALLHELD_IND, (PsIntFuncPtr)srv_bt_dialer_callheld_ind, MMI_TRUE);					
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_SIGNAL_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_signal_ind, MMI_TRUE);	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_ROAM_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_roam_ind, MMI_TRUE);		
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_BATTCHG_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_battchg_ind, MMI_TRUE);		
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CLIP_IND, (PsIntFuncPtr)srv_bt_dialer_clip_ind, MMI_TRUE);		
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CCWA_IND, (PsIntFuncPtr)srv_bt_dialer_ccwa_ind, MMI_TRUE);			
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BVRA_IND, (PsIntFuncPtr)srv_bt_dialer_bvra_ind, MMI_TRUE);				
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BTRH_IND, (PsIntFuncPtr)srv_bt_dialer_btrh_ind, MMI_TRUE);					
	
	mdi_audio_bt_register_volume_sync_callback(APP_BT_DIALER, MDI_AUD_VOL_LEVEL_NORMAL, srv_bt_dialer_vol_control_callback);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_deinit
 * DESCRIPTION
 * this function is to deinit the BT Dialer global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 speech_vol_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(g_bt_dialer_cntx, 0, sizeof(srv_bt_dialer_g_struct));
	SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_IDLE);
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_DEINIT_OPERATION);
	
	mdi_audio_bt_clear_volume_sync_callback(APP_BT_DIALER);  //Clear Vol callback
    speech_vol_level = MDI_AUD_VOL_GET_EX_LEVEL(srv_speech_get_mode_volume()); //get speech volume
    srv_speech_save_mode_volume(MDI_AUD_VOL_MUTE(speech_vol_level));  //restore speech volume
    mdi_audio_set_mic_volume(); //restore MIC volume
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_open
 * DESCRIPTION
 *  This function is to open BT Dialer context and return service handler to APP.
 * CALLS
 * PARAMETERS
 * RETURNS
 *  int
 *****************************************************************************/
int srv_bt_dialer_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!g_bt_dialer_cntx->alloc)
	{
		g_bt_dialer_cntx->alloc = MMI_TRUE;
		SRV_BT_DIALER_SRV_HANDLE = ++srv_dialer_handle;
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_OPEN_SUCCESS);
		return SRV_BT_DIALER_SRV_HANDLE;
	}
	
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_OPEN_FAIL);
	return SRV_BT_DIALER_SERVICE_UNAVAILABLE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_close
 * DESCRIPTION
 *  this function is to initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_close(int srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((g_bt_dialer_cntx->alloc) && (srv_hd == g_bt_dialer_cntx->srv_hd))	
	{
		g_bt_dialer_cntx->srv_hd = -1;
		g_bt_dialer_cntx->alloc = MMI_FALSE;
		g_bt_dialer_cntx->cb_ptr = NULL;
		if(g_bt_dialer_cntx->hf_cmd != NULL)
		{
			/*free all nodes*/
			srv_bt_dialer_free_atcmd_queue(MMI_TRUE);

		}
		if(g_bt_dialer_cntx->hf_result != NULL)
		{
			/*free all nodes*/
			srv_bt_dialer_free_atcmd_queue(MMI_FALSE);
		}		
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CLOSE_SUCCESS);
	}
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_register_hf_notifier
 * DESCRIPTION
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_register_hf_notifier(int srv_hd, srv_bt_dialer_notify_hf_event cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(SRV_BT_DIALER_SRV_HANDLE != srv_hd )
	{
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_HF_NOTIFIER_FAIL);		
		return SRV_BT_DIALER_FAILURE;
	}
	g_bt_dialer_cntx->cb_ptr = cb_ptr;

	return SRV_BT_DIALER_SUCCESS;	
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_register_indicators
 * DESCRIPTION
 * API for UCM to register specific events to recieve notifications for selected events.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_register_indicators(int srv_hd, U16 ind_event)
		{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(SRV_BT_DIALER_SRV_HANDLE != srv_hd )
			{
		return SRV_BT_DIALER_FAILURE;
		}

	g_bt_dialer_cntx->ind_mask = ind_event;
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_INDICATORS, ind_event);		

	return SRV_BT_DIALER_SUCCESS;

		}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_free_atcmd_queue
 * DESCRIPTION
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_free_atcmd_queue(MMI_BOOL req_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_send_at_cmd_struct *temp = NULL;
	srv_bt_dialer_send_at_cmd_struct *temp2 = NULL;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(req_queue)
	{
		temp = g_bt_dialer_cntx->hf_cmd;
		while((temp != NULL) && (temp->btd_hf_cmd != NULL))
		{
			temp2 = (srv_bt_dialer_send_at_cmd_struct*)temp->Flink;
			OslMfree(temp->btd_hf_cmd);
			OslMfree(temp);			
			temp = temp2;
		}
		g_bt_dialer_cntx->hf_cmd = NULL;
	}
	else
	{
		if(g_bt_dialer_cntx->hf_result != NULL)
		{
			OslMfree(g_bt_dialer_cntx->hf_result);
		}		
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_activate_req
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_activate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_ACTIVATE_REQ);		

	if(g_bt_dialer_cntx->state == SRV_BT_DIALER_STATE_IDLE)
    {
        SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_ACTIVATING);
		mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_ACTIVATE_CNF, (PsIntFuncPtr)srv_bt_dialer_activate_cnf_hdlr, MMI_TRUE);	
		srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_ACTIVATE_REQ, MOD_BT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_activate_cnf_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_activate_cnf_struct *activate_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	activate_rsp = (bt_hf_activate_cnf_struct*) msg;
    ASSERT(activate_rsp);

	if(activate_rsp->result!=0)
	{
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_ACTIVATE_CNF_FAIL);				
		SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_IDLE);	
		return MMI_FALSE;
	}
	if (g_bt_dialer_cntx->state == SRV_BT_DIALER_STATE_ACTIVATING)
    {
		SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_ACTIVATED);	
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_ACTIVATE_CNF_SUCCESS);
        srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_HF_PROFILE_UUID);
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_deactivate_req
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_deactivate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	SRV_BT_DIALER_LOG(SRV_BT_DIALER_DEACTIVATE);		
    SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_DEACTIVATING);
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_DEACTIVATE_CNF, (PsIntFuncPtr)srv_bt_dialer_deactivate_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_DEACTIVATE_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_deactivate_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_deactivate_cnf_struct *deactivate_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	deactivate_rsp = (bt_hf_deactivate_cnf_struct*) msg;
    ASSERT(deactivate_rsp);

	if(deactivate_rsp->result!=0)
	{
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_DEACTIVATE_FAIL);		
		SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_IDLE);	
		return MMI_FALSE;
	}
	if (g_bt_dialer_cntx->state == SRV_BT_DIALER_STATE_DEACTIVATING)
    {
		SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_IDLE);	
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_DEACTIVATED);			
		srv_bt_cm_deactivate_cnf_hdler((U32) SRV_BT_CM_HF_PROFILE_UUID);
	}
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_connect_req
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_connect_req(srv_bt_cm_bt_addr bd_addr)
{
    /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 bt_hf_connect_req_struct *req;
	 S32 cm_conn_id;
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	
	SRV_BT_DIALER_LOG3(SRV_BT_DIALER_CONNECT_REQ,bd_addr.lap, bd_addr.uap, bd_addr.nap );	

	req = (bt_hf_connect_req_struct*)OslConstructDataPtr(sizeof(bt_hf_connect_req_struct));
	 
	g_bt_dialer_cntx->bd_addr.lap = bd_addr.lap;
	g_bt_dialer_cntx->bd_addr.uap = bd_addr.uap;
	g_bt_dialer_cntx->bd_addr.nap = bd_addr.nap;
	
	req->bt_addr.lap = bd_addr.lap;
	req->bt_addr.uap = bd_addr.uap;
	req->bt_addr.nap = bd_addr.nap;	
	 
	req->hs_conn = MMI_FALSE;

    cm_conn_id= srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_HF_PROFILE_UUID, &bd_addr, NULL);
	SRV_BT_DIALER_SET_CM_CONN_ID(cm_conn_id);
	
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CONNECT_CNF, (PsIntFuncPtr)srv_bt_dialer_connect_cnf_hdlr, MMI_TRUE);	
	SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_CONNECTING);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CONNECT_REQ, MOD_BT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_connect_cnf_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_connect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_connect_cnf_struct *rsp= NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_connect_cnf_struct*) msg;
    ASSERT(rsp);

	if(rsp->result != 0)
	{
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CONNECT_CNF_FAIL);	
		SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_ACTIVATED);			
	    srv_bt_cm_stop_conn(SRV_BT_DIALER_GET_CM_CONN_ID);		
		return MMI_FALSE;
	}
	
	SRV_BT_DIALER_SET_CONN_ID(rsp->connection_id);
	SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_CONNECTED);	
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_CONNECT_CNF_PASSED);	
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_connect_ind
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_connect_ind(void *msg)
{
    /*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/
	bt_hf_connect_ind_req_struct *req;
	srv_bt_cm_bt_addr bd_addr;
	S32 cm_conn_id;
	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	 
	req = (bt_hf_connect_ind_req_struct*) msg;
	ASSERT(req);
	 
	SRV_BT_DIALER_LOG3(SRV_BT_DIALER_CONNECT_IND, req->bt_addr.lap, req->bt_addr.uap, req->bt_addr.nap);	
	 
	bd_addr.lap = req->bt_addr.lap;
	bd_addr.uap = req->bt_addr.uap;
	bd_addr.nap = req->bt_addr.nap;
	 
	g_bt_dialer_cntx->bd_addr.lap = req->bt_addr.lap;
	g_bt_dialer_cntx->bd_addr.uap = req->bt_addr.uap;
	g_bt_dialer_cntx->bd_addr.nap = req->bt_addr.nap;
	 
	SRV_BT_DIALER_SET_CONN_ID(req->connection_id);
	SRV_BT_DIALER_SET_HS_CONN(req->hs_conn);

    cm_conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_HF_PROFILE_UUID, &(bd_addr), NULL);
	SRV_BT_DIALER_SET_CM_CONN_ID(cm_conn_id);
	
	srv_bt_dialer_send_connect_ind_rsp(MMI_HF_CONN_CNF);
    srv_bt_cm_connect_ind(SRV_BT_DIALER_GET_CM_CONN_ID);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_connect_ind_rsp
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_connect_ind_rsp(int accept)
{
    /*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/
	bt_hf_connect_ind_res_struct *rsp;
	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	 
 	rsp = (bt_hf_connect_ind_res_struct*)OslConstructDataPtr(sizeof(bt_hf_connect_ind_res_struct));

	rsp->connection_id = SRV_BT_DIALER_GET_CONN_ID;
	rsp->bt_addr.lap = g_bt_dialer_cntx->bd_addr.lap;
	rsp->bt_addr.uap = g_bt_dialer_cntx->bd_addr.uap;
	rsp->bt_addr.nap = g_bt_dialer_cntx->bd_addr.nap;

	rsp->accept = (kal_bool)accept;
	
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_CONNECT_IND_RSP,accept);	
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_deconnect_req
 * DESCRIPTION
 * PARAMETERS
 *  bd_addr     [IN]        
 *  conn_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_disconnect_req(U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_disconnect_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	SRV_BT_DIALER_LOG(SRV_BT_DIALER_DISCONNECT_REQ);	

	req = (bt_hf_disconnect_req_struct*)OslConstructDataPtr(sizeof(bt_hf_disconnect_req_struct));

	req->bt_addr.lap  = g_bt_dialer_cntx->bd_addr.lap;
	req->bt_addr.uap  = g_bt_dialer_cntx->bd_addr.uap;
	req->bt_addr.nap  = g_bt_dialer_cntx->bd_addr.nap;
	
	req->connection_id = SRV_BT_DIALER_GET_CONN_ID;

    SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_DISCONNECTING);
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_DISCONNECT_CNF, (PsIntFuncPtr)srv_bt_dialer_disconnect_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_DISCONNECT_REQ, MOD_BT);
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_disconnect_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_disconnect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_disconnect_cnf_struct *disconnect_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	disconnect_rsp = (bt_hf_disconnect_cnf_struct*) msg;
    ASSERT(disconnect_rsp);

	if(disconnect_rsp->result!=0)
	{
	  SRV_BT_DIALER_LOG(SRV_BT_DIALER_DISCONNECT_FAIL);	
		return MMI_FALSE;
	}
	if (g_bt_dialer_cntx->state == SRV_BT_DIALER_STATE_DISCONNECTING)
    {
		SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_ACTIVATED);	
		srv_bt_cm_stop_conn(SRV_BT_DIALER_GET_CM_CONN_ID);	
		SRV_BT_DIALER_SET_CM_CONN_ID(MMI_HF_INVALID_CONN_ID);	
		SRV_BT_DIALER_SET_CONN_ID(0);
		g_bt_dialer_cntx->hs_conn = MMI_FALSE;
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_disconnect_ind
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_disconnect_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_disconnect_ind_struct *disc_ind = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	disc_ind = (bt_hf_disconnect_ind_struct*) msg;
    ASSERT(disc_ind);

	SRV_BT_DIALER_LOG(SRV_BT_DIALER_DISCONNECT_IND);	

	if ((g_bt_dialer_cntx->state <= SRV_BT_DIALER_STATE_CONNECTED) && 
		(disc_ind->connection_id == SRV_BT_DIALER_GET_CONN_ID))
    {
		SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_DISCONNECTED);	
		srv_bt_cm_stop_conn(SRV_BT_DIALER_GET_CM_CONN_ID);	
		SRV_BT_DIALER_SET_CM_CONN_ID(MMI_HF_INVALID_CONN_ID);	

		memset(&(g_bt_dialer_cntx->bd_addr),0,sizeof(srv_bt_cm_bt_addr));
		
		SRV_BT_DIALER_SET_CONN_ID(0);

		g_bt_dialer_cntx->bsir_enable = MMI_FALSE;
		g_bt_dialer_cntx->hs_conn = MMI_FALSE;
		g_bt_dialer_cntx->ciev_service = MMI_FALSE;
		g_bt_dialer_cntx->bvra_enable = MMI_FALSE;
		g_bt_dialer_cntx->ciev_call = 0;
		g_bt_dialer_cntx->callsetup = 0;
		g_bt_dialer_cntx->callheld = 0;
		g_bt_dialer_cntx->ciev_signal = 0;
		g_bt_dialer_cntx->ciev_roam = 0;
		g_bt_dialer_cntx->ciev_battchg = 0;
		g_bt_dialer_cntx->btrh_n = 0;
    }
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_hf_proc_func
 * DESCRIPTION
 *  this function is to initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void

 *****************************************************************************/
mmi_ret srv_bt_dialer_hf_proc_func(mmi_event_struct *evt)
{	

	SRV_BT_DIALER_LOG(SRV_BT_DIALER_HF_PROC_FUNC);	

	if(g_bt_dialer_cntx->hf_cmd!=NULL)
	{
		srv_bt_dialer_HfExecuteNextCommand();
	}
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_at_command
 * DESCRIPTION
 *  this function is to initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_at_command( int srv_hd,
									srv_bt_dialer_at_cmd_type_enum type,
                                    srv_bt_dialer_AtHfCmd_struct *btd_hf_cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_event_struct evnt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(SRV_BT_DIALER_SRV_HANDLE != srv_hd)
	{
		return SRV_BT_DIALER_FAILURE;
	}

	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_SEND_AT_CMD, type);	
	srv_bt_dialer_add_node_to_list(btd_hf_cmd,type);

    MMI_FRM_INIT_EVENT((mmi_event_struct *)&evnt, SRV_BT_DIALER_AT_CMD_EVENT);	

    mmi_frm_post_event((mmi_event_struct *)&evnt, (mmi_proc_func)srv_bt_dialer_hf_proc_func,NULL);
	return MMI_RET_OK;
}

 /*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_ilm
 * DESCRIPTION
 *  This function is used to send ILM to WPS task
 * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
static void srv_bt_dialer_send_ilm( void *local_para,
									msg_type msg_id, module_type dst_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send5(stack_get_active_module_id(),
			  dst_mod,
			  BT_APP_SAP,
			  msg_id,
			  (local_para_struct *)local_para);

}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_add_node_to_list
 * DESCRIPTION
 *  this function is to initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_add_node_to_list(srv_bt_dialer_AtHfCmd_struct *cmd,
									srv_bt_dialer_at_cmd_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_send_at_cmd_struct *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	temp = (srv_bt_dialer_send_at_cmd_struct*)OslMalloc(sizeof(srv_bt_dialer_send_at_cmd_struct));

	memset((void *)temp,0,sizeof(srv_bt_dialer_send_at_cmd_struct));

  if(cmd !=NULL)
  {
	    temp->btd_hf_cmd = (srv_bt_dialer_AtHfCmd_struct*)OslMalloc(sizeof(srv_bt_dialer_AtHfCmd_struct));
	    memcpy(temp->btd_hf_cmd, cmd,sizeof(srv_bt_dialer_AtHfCmd_struct));
	}

	temp->type = type;
	
    srv_bt_dialer_InsertTailList(temp);

}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_HfGetCurrentCommand
 * DESCRIPTION
 *  This function is used to send ILM to WPS task
 * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
srv_bt_dialer_send_at_cmd_struct * srv_bt_dialer_HfGetCurrentCommand(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_send_at_cmd_struct *temp =g_bt_dialer_cntx->hf_cmd;
	if(temp!=NULL)
	{
		if(temp->Flink!=NULL)
			g_bt_dialer_cntx->hf_cmd = temp->Flink;
		else
			g_bt_dialer_cntx->hf_cmd = NULL;
		return temp;
    }
    return NULL;
}
 /*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_HfExecuteNextCommand
 * DESCRIPTION
 *  This function is used to send ILM to WPS task
 * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_HfExecuteNextCommand(void)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 srv_bt_dialer_send_at_cmd_struct *command;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        command = srv_bt_dialer_HfGetCurrentCommand();
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_EXEC_AT_CMD, command->type);
	if(command == NULL)
		return;

		switch (command->type)
			{
				case SRV_BT_DIALER_AT_DIAL_NUMBER:
				{
				const char *number = command->btd_hf_cmd->dial.number;
				int len = strlen((const char*)command->btd_hf_cmd->dial.number);
					srv_bt_dialer_atd_req(len,(U8*)number);	
			break;
				}
				case SRV_BT_DIALER_AT_DIAL_MEMORY:
				{
				const char *number = command->btd_hf_cmd->dial.number;
				int len = strlen((const char*)command->btd_hf_cmd->dial.number);
					srv_bt_dialer_atmem_req((U32)number);			
					break;
				 }
				case SRV_BT_DIALER_AT_ANSWER:
				{
					srv_bt_dialer_ata_req();
					break;
				}		
				case SRV_BT_DIALER_AT_REDIAL:
				{
					srv_bt_dialer_atbldn_req();
                                        break;
				}
				case SRV_BT_DIALER_AT_HANG_UP:
				{
					srv_bt_dialer_atchup_req();
                                        break;
				}
				case SRV_BT_DIALER_AT_GENERATE_DTMF_TONE:
				{
				srv_bt_dialer_atvts_req(command->btd_hf_cmd->dtmf.tone);
					break;
				}
				case SRV_BT_DIALER_AT_SPEAKER_GAIN:
				{
					srv_bt_dialer_vgs_req(g_bt_dialer_cntx->speakerGain);
					break;
				}
				case SRV_BT_DIALER_AT_MICROPHONE_GAIN:
				{
					srv_bt_dialer_vgm_req(g_bt_dialer_cntx->micGain);
					break;
				}
				case SRV_BT_DIALER_AT_CALL_HOLD:
				{
			U8 number = command->btd_hf_cmd->hold.call;
			srv_bt_dialer_atchld_req(number);
					break;
				}
				case SRV_BT_DIALER_AT_CALL_ID:
				{
				 srv_bt_dialer_atclip_req(command->btd_hf_cmd->callId.enabled);
					 break;
				}
				case SRV_BT_DIALER_AT_CALL_WAIT_NOTIFY:
				{
				srv_bt_dialer_atccwa_req(command->btd_hf_cmd->wait.notify);
					break;
				}	
				case SRV_BT_DIALER_AT_EVENT_REPORTING:
				{
				srv_bt_dialer_atcmee_req((MMI_BOOL)command->btd_hf_cmd->report.ind );
	 				break;
				}	
				case SRV_BT_DIALER_AT_VOICE_TAG:
				{
					srv_bt_dialer_atbinp_req();
					break;
				}
				case SRV_BT_DIALER_AT_VOICE_RECOGNITION:
				{
				srv_bt_dialer_atbvra_req((MMI_BOOL)command->btd_hf_cmd->vrec.enabled);
					break;
				}
				case SRV_BT_DIALER_AT_ECHO_C_AND_NOISE_R:
				{
					srv_bt_dialer_atnrec_req();
					break;
				}
				case SRV_BT_DIALER_AT_RESPONSE_AND_HOLD:
				{
					if(command->btd_hf_cmd->btrh.at_type == SRV_BT_DIALER_ATRESHOLD_READ)
					srv_bt_dialer_atbtrh_read_req();
					else if (command->btd_hf_cmd->btrh.at_type == SRV_BT_DIALER_ATRESHOLD_SET)
				srv_bt_dialer_atbtrh_set_req(command->btd_hf_cmd->btrh.setting);
					break;
				}
				case SRV_BT_DIALER_AT_SUBSCRIBER_NUM:
				{
			srv_bt_dialer_atcnum_req();
					break;
				}
				case SRV_BT_DIALER_AT_LIST_CURRENT_CALLS:
				{
					srv_bt_dialer_atclcc_req();
					break;
				}
				case SRV_BT_DIALER_AT_NETWORK_OPERATOR:
				{
			srv_bt_dialer_atcops_req();
					break;
				}
		case SRV_BT_DIALER_AT_SET_NETWORK_OPERATOR_FORMAT:
		{
			srv_bt_dialer_set_atcops_req();
			break;
		}
				
			}
        if(command !=NULL)
           OslMfree(command);
		}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ata_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_ata_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_ATA_CMD);	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_ATA_CNF, (PsIntFuncPtr)srv_bt_dialer_ata_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_ATA_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ata_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ata_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ata_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ata_cnf_struct*) msg;
    ASSERT(rsp);
	
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ATA_CMD_CNF_HDLR,rsp->result);

		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd, notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atd_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atd_req(U8 size, U8* number )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 bt_hf_atd_num_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	 SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ATD_CMD, number);	

	req = (bt_hf_atd_num_req_struct*)OslConstructDataPtr(sizeof(bt_hf_atd_num_req_struct));

	req->size = size;
	strcpy((char*)req->number,(const char*)number);
	req->number[size] = '\0';
	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_ATD_NUM_CNF, (PsIntFuncPtr)srv_bt_dialer_atd_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_ATD_NUM_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atd_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atd_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_atd_num_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_atd_num_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ATD_CMD_CNF_HDLR,rsp->result);
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atmem_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atmem_req(U32 index )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 bt_hf_atd_mem_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	 SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_MEM, index);	

	req = (bt_hf_atd_mem_req_struct*)OslConstructDataPtr(sizeof(bt_hf_atd_mem_req_struct));
	req->index = index;
	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_ATD_MEM_CNF, (PsIntFuncPtr)srv_bt_dialer_atmem_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_ATD_MEM_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atmem_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atmem_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_atd_mem_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_atd_mem_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ATMEM_CMD_CNF_HDLR,rsp->result);
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbldn_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbldn_req(void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_BLDN);	

	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BLDN_CNF, (PsIntFuncPtr)srv_bt_dialer_atbldn_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_BLDN_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atmem_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbldn_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_bldn_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_bldn_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BLDN_CMD_CNF_HDLR,rsp->result);
		/*notify error to application*/
		/*rsp->cme_errcode*/
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);

	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atchup_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atchup_req(void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_CHUP_CMD);	

	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CHUP_CNF, (PsIntFuncPtr)srv_bt_dialer_atchup_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_CHUP_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atchup_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atchup_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_chup_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_chup_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CHUP_CMD_CNF_HDLR,rsp->result);
		/*notify error to application*/
		/*rsp->cme_errcode*/
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
	              	g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcmee_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atcmee_req(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 bt_hf_cmee_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CMEE, enable);	

	req = (bt_hf_cmee_req_struct*)OslConstructDataPtr(sizeof(bt_hf_cmee_req_struct));
	req->enable = enable;
	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CMEE_CNF, (PsIntFuncPtr)srv_bt_dialer_atcmee_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CMEE_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcmee_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atcmee_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 bt_hf_cmee_cnf_struct *rsp;
	 srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_cmee_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CMEE_CMD_CNF_HDLR,rsp->result);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		/*notify error to application*/
		/*rsp->cme_errcode*/
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		return MMI_FALSE;
	}

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atnrec_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atnrec_req(void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_NREC);	

	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_NREC_CNF, (PsIntFuncPtr)srv_bt_dialer_atnrec_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_NREC_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atnrec_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atnrec_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_nrec_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_nrec_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_NREC_RSP,rsp->result);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		/*notify error to application*/
		/*rsp->cme_errcode*/
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 	
		else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		return MMI_FALSE;
	}

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atnrec_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atvts_req(U8 dtmf )
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 bt_hf_vts_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VTS, dtmf);	

	req = (bt_hf_vts_req_struct*)OslConstructDataPtr(sizeof(bt_hf_vts_req_struct));
	req->dtmf = dtmf;

	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VTS_CNF, (PsIntFuncPtr)srv_bt_dialer_atvts_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_VTS_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atnrec_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atvts_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_vts_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_vts_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VTS_CMD_CNF_HDLR,rsp->result);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		/*notify error to application*/
		/*rsp->cme_errcode*/
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		return MMI_FALSE;
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ring_ind_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ring_ind_hdlr(void *msg)
{
	srv_bt_dialer_notify_event_struct notify;
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_RING_ALERT);
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_IN_BAND_RING_TONE;
	if(g_bt_dialer_cntx->cb_ptr)
	        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); //at caller's end
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgs_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_vgs_req(int gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_vgs_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VGS, gain);	

	req = (bt_hf_vgs_req_struct*)OslConstructDataPtr(sizeof(bt_hf_vgs_req_struct));
	req->gain = gain;
	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VGS_CNF, (PsIntFuncPtr)srv_bt_dialer_vgs_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_VGS_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgs_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_vgs_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_vgs_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_vgs_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VGS_CMD_CNF_HDLR,rsp->result);

	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		return MMI_FALSE;
	}
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgm_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_vgm_req(int gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_vgm_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VGM, gain);	

	req = (bt_hf_vgm_req_struct*)OslConstructDataPtr(sizeof(bt_hf_vgm_req_struct));
	req->gain = gain;
	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_VGM_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgm_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_vgm_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_vgm_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_vgm_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VGM_CMD_CNF_HDLR,rsp->result);

	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		return MMI_FALSE;
	}
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atchld_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atchld_req(U8 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_chld_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CHLD,number);	

	req = (bt_hf_chld_req_struct*)OslConstructDataPtr(sizeof(bt_hf_chld_req_struct));
	req->n = number;
	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CHLD_CNF, (PsIntFuncPtr)srv_bt_dialer_atchld_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CHLD_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  MMI_BOOLsrv_bt_dialer_atchld_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atchld_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_chld_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_chld_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CHLD_CMD_CNF_HDLR,rsp->result);

	if(rsp->result==HF_FINAL_RESULT_CODE_OK)
	{
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
		    SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		return MMI_FALSE;
	}
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atclip_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atclip_req(int enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_clip_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CLIP, enable);	

	req = (bt_hf_clip_req_struct*)OslConstructDataPtr(sizeof(bt_hf_clip_req_struct));
	req->enable = (kal_bool)enable;
	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CLIP_CNF, (PsIntFuncPtr)srv_bt_dialer_atclip_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CLIP_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  MMI_BOOLsrv_bt_dialer_atclip_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atclip_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_clip_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_clip_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CLIP_CMD_CNF_HDLR,rsp->result);

	if(rsp->result != HF_FINAL_RESULT_CODE_OK)
	{
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CALL_ID;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	return MMI_TRUE;
}
	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atccwa_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atccwa_req(U8 enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ccwa_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CCWA, enable);	

	req = (bt_hf_ccwa_req_struct*)OslConstructDataPtr(sizeof(bt_hf_ccwa_req_struct));
	req->enable = (kal_bool)enable;
	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CCWA_CNF, (PsIntFuncPtr)srv_bt_dialer_atccwa_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CCWA_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  MMI_BOOLsrv_bt_dialer_atccwa_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atccwa_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ccwa_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ccwa_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CCWA_CMD_CNF_HDLR,rsp->result);

	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMD_RSP;
		notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		return MMI_FALSE;
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_atcops_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_set_atcops_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_SET_AT_COPS);	

	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_COPS_SET_CNF, (PsIntFuncPtr)srv_bt_dialer_set_atcops_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_COPS_SET_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_atcops_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_set_atcops_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_cops_set_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_cops_set_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_SET_AT_COPS_CNF_HDLR,rsp->result);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_NETWORK_OPERATOR;
	notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode);

	if(g_bt_dialer_cntx->cb_ptr)
		g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		return MMI_FALSE;
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcops_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atcops_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_COPS);	

	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_COPS_CNF, (PsIntFuncPtr)srv_bt_dialer_atcops_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_COPS_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcops_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atcops_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_cops_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;			
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_cops_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SSRV_BT_DIALER_AT_COPS_CNF_HDLR,rsp->result);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}
		if(!rsp->final)
		{
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_NETWORK_OPERATOR;
	notify.result.networkOper_read.mode = 0;
	notify.result.networkOper_read.format = SRV_BT_DIALER_ATOF_LONG_ALPHANUM;	
	notify.result.networkOper_read.oper = (const char*)OslMalloc(rsp->size+1);	
	memset((void*)notify.result.networkOper_read.oper,0, rsp->size +1);		
			strncpy((char *)notify.result.networkOper_read.oper,(char *)rsp->operator, rsp->size);
	if(g_bt_dialer_cntx->cb_ptr)
	        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		
	OslMfree((void*)notify.result.networkOper_read.oper);
		}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcnum_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atcnum_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_CNUM);	

	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CNUM_CNF, (PsIntFuncPtr)srv_bt_dialer_atcnum_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_CNUM_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcnum_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atcnum_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_cnum_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_cnum_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CNUM_CNF,rsp->result);	
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}
	if(!rsp->final)
	{
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_SUBSCRIBER_NUM;
	notify.result.subscribeNum.type = (srv_bt_dialer_AtNumberFormat_enum)rsp->type;
	notify.result.subscribeNum.service = rsp->service;	
		notify.result.subscribeNum.number = (char *)OslMalloc(rsp->size+1);
		memset((void *)notify.result.subscribeNum.number,0,rsp->size+1);
		strncpy((char *)notify.result.subscribeNum.number,(char *)rsp->number,rsp->size);
	if(g_bt_dialer_cntx->cb_ptr)
	        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
	else 
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);

	OslMfree((void*)notify.result.subscribeNum.number);
	}

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbvra_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbvra_req(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_bvra_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BVRA, enable);	

	req = (bt_hf_bvra_req_struct*)OslConstructDataPtr(sizeof(bt_hf_bvra_req_struct));
	req->enable = enable;
	
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BVRA_CNF, (PsIntFuncPtr)srv_bt_dialer_atbvra_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_BVRA_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbvra_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbvra_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_bvra_cnf_struct *rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_bvra_cnf_struct*) msg;
    ASSERT(rsp);

	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BVRA_CNF,rsp->result);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbinp_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbinp_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_BNIP);	

	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BINP_CNF, (PsIntFuncPtr)srv_bt_dialer_atbinp_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_BINP_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbinp_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbinp_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_binp_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_binp_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BNIP_CNF,rsp->result);	
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}
	if(!rsp->final)
	{
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_VOICE_TAG;
		notify.result.voiceTag.number =(char *)OslMalloc(rsp->size+1);
		memset((void *)notify.result.voiceTag.number,0,rsp->size+1);
		strncpy( (char *)notify.result.voiceTag.number , (char *)rsp->number,rsp->size);
	if(g_bt_dialer_cntx->cb_ptr)
		g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	}

		
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbtrh_read_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbtrh_read_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_BTRH);
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BTRH_READ_CNF, (PsIntFuncPtr)srv_bt_dialer_atbtrh_read_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_BTRH_READ_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbtrh_read_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbtrh_read_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_btrh_read_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_btrh_read_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG2(SRV_BT_DIALER_AT_BTRH_CNF,rsp->result,rsp->n);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}
	if(!rsp->final)
	{
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_RESPONSE_AND_HOLD;
	notify.result.btrh.setting = (srv_bt_dialer_AtResponseHold_enum)rsp->n;
	if(g_bt_dialer_cntx->cb_ptr)
		g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	}

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbtrh_set_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbtrh_set_req(int n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_btrh_set_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BTRH_SET,n);
	req = (bt_hf_btrh_set_req_struct*)OslConstructDataPtr(sizeof(bt_hf_btrh_set_req_struct));
	req->n = n;

	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BTRH_SET_CNF, (PsIntFuncPtr)srv_bt_dialer_atbtrh_set_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_BTRH_SET_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbtrh_set_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbtrh_set_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_btrh_set_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_btrh_set_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG2(SRV_BT_DIALER_AT_BTRH_SET_CNF,rsp->result,rsp->n);
	if(rsp->result!=HF_FINAL_RESULT_CODE_OK)
	{
		return MMI_FALSE;
	}
	if(!rsp->final)
	{
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_RESPONSE_AND_HOLD;
	notify.result.btrh.setting = (srv_bt_dialer_AtResponseHold_enum)rsp->n;
	if(g_bt_dialer_cntx->cb_ptr)
		g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	}
	
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atclcc_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atclcc_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  SRV_BT_DIALER_LOG(SRV_BT_DIALER_CLCC_REQ);
	mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CLCC_CNF, (PsIntFuncPtr)srv_bt_dialer_atclcc_cnf_hdlr, MMI_TRUE);	
	srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_CLCC_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atclcc_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atclcc_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_clcc_cnf_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_clcc_cnf_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_CLCC_CNF,rsp->result);

	if(!rsp->final)
	{
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_LIST_CURRENT_CALLS;
	notify.result.currentCalls.index = rsp->index;
	notify.result.currentCalls.dir = rsp->dir;
	notify.result.currentCalls.mode = rsp->mode;
	notify.result.currentCalls.type = (srv_bt_dialer_AtNumberFormat_enum)rsp->type;
	notify.result.currentCalls.state = (srv_bt_dialer_AtCallState_enum)rsp->status;
	notify.result.currentCalls.multiParty = rsp->multiparty;
		notify.result.currentCalls.number = (char *)OslMalloc(rsp->size+1);
		memset((void *)notify.result.currentCalls.number,0,rsp->size+1);
		strncpy((char *)notify.result.currentCalls.number,(char *)rsp->number,rsp->size);
		
	if(g_bt_dialer_cntx->cb_ptr)
		g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);

	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_bsir_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_bsir_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_bsir_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_bsir_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_IN_BAND_RING_IND,rsp->enable);
	g_bt_dialer_cntx->bsir_enable  = rsp->enable;

		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_IN_BAND_RING_TONE;
		notify.result.inBandRing.enabled = g_bt_dialer_cntx->bsir_enable;
   	    

		if(g_bt_dialer_cntx->cb_ptr)
   	                g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);

	return MMI_TRUE;

}



/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_service_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_service_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ciev_service_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ciev_service_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_LOG_CIEV_SERVICE_IND,rsp->service);
	g_bt_dialer_cntx->ciev_service  = (MMI_BOOL)rsp->service;
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
	notify.result.event.indicator = SRV_BT_DIALER_UNMASK_CIEV_SERVICE_INDICATION;
	notify.result.event.value = rsp->service;
	if(g_bt_dialer_cntx->cb_ptr)
	        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); //at caller's end	
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_call_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_call_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ciev_call_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ciev_call_ind_struct*) msg;
    ASSERT(rsp);

	g_bt_dialer_cntx->ciev_call  = rsp->call;
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_LOG_CIEV_CALL_IND,rsp->call);
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
		notify.result.event.indicator = SRV_BT_DIALER_CIEV_CALL_INDICATION;
	notify.result.event.value = rsp->call;
		if(g_bt_dialer_cntx->cb_ptr)
	g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); //at caller's end
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_callsetup_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_callsetup_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ciev_callsetup_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ciev_callsetup_ind_struct*) msg;
    ASSERT(rsp);

	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_CIEV_CALLSETUP_IND,rsp->callsetup);
	g_bt_dialer_cntx->callsetup  = rsp->callsetup;
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
	notify.result.event.indicator = SRV_BT_DIALER_CIEV_CALL_SETUP_INDICATION;
	notify.result.event.value = rsp->callsetup;
	if(g_bt_dialer_cntx->cb_ptr)
	g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_callheld_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_callheld_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ciev_callheld_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ciev_callheld_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_CALL_HELD_IND,rsp->callheld);
	g_bt_dialer_cntx->callheld  = rsp->callheld;
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CALL_HOLD;
	notify.result.hold_test.flags = (srv_bt_dialer_AtHoldFlag_enum)rsp->callheld;
	if(g_bt_dialer_cntx->cb_ptr)
	g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
	else
		SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_signal_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_signal_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ciev_signal_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ciev_signal_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_SIGNAL_IND,rsp->signal);
	g_bt_dialer_cntx->ciev_signal  = rsp->signal;
	if(g_bt_dialer_cntx->ind_mask & SRV_BT_DIALER_UNMASK_CIEV_SIGNAL_INDICATION)
	{
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
		notify.result.event.indicator = SRV_BT_DIALER_UNMASK_CIEV_SIGNAL_INDICATION;
		notify.result.event.value = g_bt_dialer_cntx->ciev_signal;				
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	}		

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_roam_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_roam_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ciev_roam_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ciev_roam_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ROAMING_IND,rsp->roam);
	g_bt_dialer_cntx->ciev_roam  = rsp->roam;

	if(g_bt_dialer_cntx->ind_mask & SRV_BT_DIALER_UNMASK_ROAM_INDICATION)
	{
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
		notify.result.event.indicator = SRV_BT_DIALER_UNMASK_ROAM_INDICATION;
		notify.result.event.value = g_bt_dialer_cntx->ciev_roam;
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_battchg_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_battchg_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ciev_battchg_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ciev_battchg_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_BATTCH_IND,rsp->battchg);
	g_bt_dialer_cntx->ciev_battchg  = rsp->battchg;

	if(g_bt_dialer_cntx->ind_mask & SRV_BT_DIALER_UNMASK_BATTCHG_INDICATION)
	{
		notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
		notify.result.event.indicator = SRV_BT_DIALER_UNMASK_BATTCHG_INDICATION;
		notify.result.event.value = g_bt_dialer_cntx->ciev_battchg;		
		if(g_bt_dialer_cntx->cb_ptr)
		        g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	}	
	return MMI_TRUE;
}


/*************************************************************
 [HF RING]
**************************************************************/
/* MSG_ID_BT_HF_RING_IND */

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_clip_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_clip_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_clip_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_clip_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG(SRV_BT_DIALER_CLIP_IND);
	    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CALL_ID;
		notify.result.callId.type = (srv_bt_dialer_AtNumberFormat_enum)rsp->type;
		notify.result.callId.number = (char *)OslMalloc(rsp->size+1);
		memset((void *)notify.result.callId.number,0,rsp->size+1);
		strncpy((char *)notify.result.callId.number,(char*)rsp->number,rsp->size);
		if(g_bt_dialer_cntx->cb_ptr)
		g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		OslMfree((void*)notify.result.callId.number);

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ccwa_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ccwa_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_ccwa_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_ccwa_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_LOG_CCWA_IND);
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CALL_WAIT_NOTIFY;
		notify.result.wait.number = (const char*)OslMalloc(rsp->size+1);
		memset((void*)notify.result.wait.number,0, rsp->size +1);			
		strncpy((char *)notify.result.wait.number, (char *)rsp->number, rsp->size);
	notify.result.wait.type = (srv_bt_dialer_AtNumberFormat_enum)rsp->type;
		if(g_bt_dialer_cntx->cb_ptr)
	g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
		OslMfree((void*)notify.result.wait.number);
	
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_bvra_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_bvra_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_bvra_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_bvra_ind_struct*) msg;
    ASSERT(rsp);

	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_LOG_BVRA_IND,rsp->enable);
	g_bt_dialer_cntx->bvra_enable  = rsp->enable;
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_VOICE_RECOGNITION;
	notify.result.vrec.enabled = g_bt_dialer_cntx->bvra_enable;
		if(g_bt_dialer_cntx->cb_ptr)
	g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_btrh_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_btrh_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_btrh_ind_struct *rsp;
	srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_btrh_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_LOG_BTRH_IND,rsp->n);
	g_bt_dialer_cntx->btrh_n  = rsp->n;
	notify.event_id = SRV_BT_DIALER_EVT_ID_AT_RESPONSE_AND_HOLD;
	notify.result.btrh.setting = (srv_bt_dialer_AtResponseHold_enum)rsp->n;
		if(g_bt_dialer_cntx->cb_ptr)
	g_bt_dialer_cntx->cb_ptr(g_bt_dialer_cntx->srv_hd,notify); 
		else
			SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgs_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_vgs_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_vgs_ind_struct *rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_vgs_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_VGS_IND,rsp->gain);
	/*call MDI API to notify volume gain*/
    mdi_audio_sync_volume_from_bt(rsp->gain);

	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgm_ind_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_vgm_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_vgm_ind_struct *rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp = (bt_hf_vgm_ind_struct*) msg;
    ASSERT(rsp);
	SRV_BT_DIALER_LOG1(SRV_BT_DIALER_VGM_IND,rsp->gain);
	/*call MDI API to notify volume gain*/
    //mdi_audio_sync_volume_from_bt(rsp->gain);
	return MMI_TRUE;
}


/*---------------------------------------------------------------------------
 *            _srv_bt_dialer_InsertTailList()
 *---------------------------------------------------------------------------
 *
 * Synopsis:  Insert an entry at the tail of the list specified by head.
 *
 * Return:    void
 */
void srv_bt_dialer_InsertTailList(srv_bt_dialer_send_at_cmd_struct* entry)
{
  srv_bt_dialer_send_at_cmd_struct *temp = g_bt_dialer_cntx->hf_cmd;
  if(temp ==NULL)
{
	g_bt_dialer_cntx->hf_cmd = entry;
	g_bt_dialer_cntx->hf_cmd->Flink = NULL;
}
  else
  {
	while(temp->Flink!=NULL)
{
		temp = temp->Flink;
}
	temp->Flink = entry;
}
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dailer_cm_notify_hdlr
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bt_dailer_cm_notify_hdlr(U32 event, void *args)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_hf_connect_ind_res_struct *rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    switch (event) {
    case SRV_BT_CM_EVENT_CONNECT_RES:
        {
            srv_bt_cm_conn_res_struct *ind = 
                (srv_bt_cm_conn_res_struct *)args;

            if (ind->profile_id == SRV_BT_CM_HF_PROFILE_UUID)
            {
				rsp = (bt_hf_connect_ind_res_struct*)OslConstructDataPtr(sizeof(bt_hf_connect_ind_res_struct));
				rsp->bt_addr.lap = ind->dev_addr->lap;
				rsp->bt_addr.uap = ind->dev_addr->uap;
				rsp->bt_addr.nap = ind->dev_addr->nap;			

                if (ind->result == SRV_BT_CM_BTBM_SUCCESS)
                {
					g_bt_dialer_cntx->bd_addr.lap = ind->dev_addr->lap;
					g_bt_dialer_cntx->bd_addr.uap = ind->dev_addr->uap;
					g_bt_dialer_cntx->bd_addr.nap = ind->dev_addr->nap;
					
					SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_CONNECTED);
					rsp->accept = MMI_TRUE;
				}
				else
				{
					SRV_BT_DIALER_STATE_TRANS(SRV_BT_DIALER_STATE_ACTIVATED);	
					rsp->accept = MMI_FALSE;
				}

				rsp->connection_id = SRV_BT_DIALER_GET_CONN_ID;
				srv_bt_dialer_send_ilm((void*)rsp, MSG_ID_BT_HF_CONNECT_IND_RES, MOD_BT);
            }
        }
        break;

    default:
        break;
    }
}

int srv_bt_dialer_convert_error_code(int error)
{
	switch(error)
	{
		case HF_FINAL_RESULT_CODE_OK :
			return SRV_BT_DIALER_ATCME_SUCCESS;
		case HF_FINAL_RESULT_CODE_TIMEOUT:
			return SRV_BT_DIALER_ATCME_TIMEOUT;	
		case HF_FINAL_RESULT_CODE_BUSY:
			return SRV_BT_DIALER_ATCME_SIM_BUSY;
		case HF_FINAL_RESULT_CODE_BLACKLISTED:
			return SRV_BT_DIALER_ATCME_OP_NOT_ALLOWED;
		case HF_FINAL_RESULT_CODE_NO_ANSWER:
			return SRV_BT_DIALER_ATCME_NO_ANSWER;
		case HF_FINAL_RESULT_CODE_NO_CARRIER:
			return SRV_BT_DIALER_ATCME_NO_CONNECTION;
		case HF_FINAL_RESULT_CODE_NO_DIALTONE:
			return SRV_BT_DIALER_ATCME_NO_NETWORK_SERVICE;
	}
 return SRV_BT_DIALER_ATCME_UNKNOWN;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_handle_pending_at_cmd
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_handle_pending_at_cmd(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_event_struct evnt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT((mmi_event_struct *)&evnt, SRV_BT_DIALER_AT_CMD_EVENT);
	if(g_bt_dialer_cntx->hf_cmd!=NULL)
	{
		mmi_frm_post_event((mmi_event_struct *)&evnt, (mmi_proc_func)srv_bt_dialer_hf_proc_func,NULL);
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_ata_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_ata_req(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_ANSWER;
	
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
    }
	
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_dial_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_dial_req(int srv_hd, const char *number)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
	srv_bt_dialer_at_cmd_type_enum type;
	int len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if((srv_hd == g_bt_dialer_cntx->srv_hd) && (number != NULL))
	{
		type = SRV_BT_DIALER_AT_DIAL_NUMBER;
		len = strlen(number);

		btd_hf_cmd.dial.number = (const char*)OslMalloc(len+1);			  

		memset((void *)btd_hf_cmd.dial.number,0, len+1);
		memcpy((char *)btd_hf_cmd.dial.number,number, len+1);

		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, &btd_hf_cmd); 
        
		OslMfree((void*)btd_hf_cmd.dial.number);

		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_hangup_active_calls
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_hangup_active_calls(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_HANG_UP;
		
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,NULL); 

		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_set_clip_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_set_clip_req(int srv_hd, MMI_BOOL enable_callId)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
	srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
{
		type = SRV_BT_DIALER_AT_CALL_ID;
		btd_hf_cmd.callId.enabled = enable_callId;		

		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, &btd_hf_cmd); 

		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_speaker_vol_gain_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_speaker_vol_gain_req(int srv_hd,int gain)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_SPEAKER_GAIN;	
		g_bt_dialer_cntx->speakerGain = gain;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_mic_vol_gain_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_mic_vol_gain_req(int srv_hd,int gain)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_MICROPHONE_GAIN;	
		g_bt_dialer_cntx->micGain = gain;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_generate_dtmf_tone_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_generate_dtmf_tone_req(int srv_hd, U8 tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
	srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_GENERATE_DTMF_TONE;
		btd_hf_cmd.dtmf.tone = tone;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,  &btd_hf_cmd); 
        
		return SRV_BT_DIALER_SUCCESS;
    
	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_voice_recognition_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_voice_recognition_req(int srv_hd, MMI_BOOL enabled_vr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
	srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
  {
		type = SRV_BT_DIALER_AT_VOICE_RECOGNITION;
		btd_hf_cmd.vrec.enabled = enabled_vr;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,  &btd_hf_cmd); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_voice_recognition_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_voice_tag_req(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_VOICE_TAG;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_noise_red_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_noise_red_req(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_ECHO_C_AND_NOISE_R;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_redial_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_redial_req(int srv_hd)
      {
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_REDIAL;

		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_network_operator_format
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_set_network_operator_format(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_SET_NETWORK_OPERATOR_FORMAT;

		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_get_network_operator_info_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_get_network_operator_info_req(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_NETWORK_OPERATOR;

		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_list_current_calls
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_list_current_calls(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_LIST_CURRENT_CALLS;

		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_subscriber_num_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_subscriber_num_req(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_SUBSCRIBER_NUM;

		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_call_wait_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_call_wait_req(int srv_hd, MMI_BOOL wait)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
	srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_CALL_WAIT_NOTIFY;
		btd_hf_cmd.wait.notify = wait;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,  &btd_hf_cmd); 
        
		return SRV_BT_DIALER_SUCCESS;
	}

	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_event_reporting
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_event_reporting(int srv_hd, U8 event)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
	srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_EVENT_REPORTING;
		btd_hf_cmd.report.ind = event;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,  &btd_hf_cmd); 
        
		return SRV_BT_DIALER_SUCCESS;
	}

	return SRV_BT_DIALER_FAILURE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_hold_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_hold_req(int srv_hd, U8 Call)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_CALL_HOLD;

		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, NULL); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_hold_response_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_hold_response_set_req(int srv_hd,int index )
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
	srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_RESPONSE_AND_HOLD;
		btd_hf_cmd.btrh.setting = (srv_bt_dialer_AtResponseHold_enum)index;
		btd_hf_cmd.btrh.at_type = SRV_BT_DIALER_ATRESHOLD_SET;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type,&btd_hf_cmd); 
        
		return SRV_BT_DIALER_SUCCESS;

      }
	return SRV_BT_DIALER_FAILURE;
  }

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_read_hold_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int srv_bt_dialer_send_response_hold_read_req(int srv_hd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_dialer_at_cmd_type_enum type;
	srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_hd == g_bt_dialer_cntx->srv_hd)
	{
		type = SRV_BT_DIALER_AT_RESPONSE_AND_HOLD;
		btd_hf_cmd.btrh.at_type = SRV_BT_DIALER_ATRESHOLD_READ;
		srv_bt_dialer_send_at_command(g_bt_dialer_cntx->srv_hd, type, &btd_hf_cmd); 
        
		return SRV_BT_DIALER_SUCCESS;

	}
	return SRV_BT_DIALER_FAILURE;
}

#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vol_control_callback
 * DESCRIPTION
 *  Volume control from H-Free device
 * PARAMETERS
 *  volume      IN  volume want to set to HF by AG
 *  is_mute     IN  CM doen't not support mute
 * RETURNS
 *  MMI_TRUE    Set volume to CM OK
 *  MMI_FALSE   Speech is off now
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_vol_control_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
         //Please Add trace here to print volume and is_mute
         
    if(srv_bt_cm_get_btdialor_mode() == MMI_TRUE)
    {
        /* Adjust speech volume */
        mmi_vol_set_speech_vol(volume);
    }
    return MMI_TRUE;
}
#endif /* __BT_SPK_VOL_CONTROL__ */


#ifdef _BT_DIALERSRV_TEST_CODE

void mmi_dummy_bt_dialer_register_hf_event(int srv_hd , srv_bt_dialer_notify_event_struct notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch(notify.event_id)
	{
		case SRV_BT_DIALER_EVT_ID_AT_RESPONSE_AND_HOLD:
			kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Response & hold:%d",notify.result.btrh.setting);
			break;
		case SRV_BT_DIALER_EVT_ID_AT_IN_BAND_RING_TONE:
			kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Ring tone ind");
			break;
		case SRV_BT_DIALER_EVT_ID_AT_CALL_ID:
			kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]btd_clip_number:%s",notify.result.callId.number);
			break;
		case SRV_BT_DIALER_EVT_ID_AT_SUBSCRIBER_NUM:
			kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]subscriber number:%s",notify.result.subscribeNum.number);
			break;
		case SRV_BT_DIALER_EVT_ID_AT_NETWORK_OPERATOR:
			kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Operator:%s",notify.result.networkOper_read.oper);
			break;
		case SRV_BT_DIALER_EVT_ID_AT_CALL_HOLD:
			kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Call hold :%d",notify.result.hold_test.flags);
			break;
		case SRV_BT_DIALER_EVT_ID_AT_LIST_CURRENT_CALLS:
			kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Call Listing -CLCC :%s",notify.result.currentCalls.number);
		break;
		case SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT:
			switch(notify.result.event.indicator)
			{
				case SRV_BT_DIALER_UNMASK_BATTCHG_INDICATION:
					kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Battery Charge Ind:%d",notify.result.event.value);
					break;
				case SRV_BT_DIALER_UNMASK_ROAM_INDICATION:
					kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Roaming Ind:%d",notify.result.event.value);
					break;
				case SRV_BT_DIALER_UNMASK_CIEV_SIGNAL_INDICATION:
					kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Signal Strength Ind:%d",notify.result.event.value);
					break;
                                case SRV_BT_DIALER_CIEV_CALL_INDICATION:
                                        if(notify.result.event.value == (srv_bt_dialer_call_ind_enum)SRV_BT_DIALER_CALL_ACTIVE)
					    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Call Active");
                                        if(notify.result.event.value == (srv_bt_dialer_call_ind_enum)SRV_BT_DIALER_CALL_NOT_ACTIVE)
					    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Call Not Active");					
                                       break;
				default:
					break;
			}
			break;
	}

}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_dump_trace_info
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_dump_trace_info(void *buf, int buf_len)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int max_buf_len = 118;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
  if(buf_len > 0)
  {
      while (buf_len > 0)
      {
      	kal_buffer_trace(MMI_CONN_TRC_G7_BT, SRV_BT_DIALER_RECV_BUFFER_TRACE, buf_len, (const kal_uint8*)buf);
      	buf_len = buf_len - max_buf_len;
      }
  }
}

U8  mmi_bt_proc_inject_string(U8 index, kal_uint8* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	static int handler=0;
    if(index==250)   // Enable PortA as 115200
    {                
		char *temp_num;
		int len = 0;
		temp_num = (char *)OslMalloc(sizeof(string));
		strcpy(temp_num,(const char*)string+4);
		len = strlen((const char*)string);
		temp_num[len -4] = '\0';
		
		srv_bt_dialer_send_dial_req(handler, (const char *)temp_num);		
				return 1;														
    }
    else if (strcmp((char*)string, "BTD_setmode") == 0)   // Enable PortA as 115200
   	{
   		 		srv_bt_cm_set_btdialor_mode(MMI_TRUE);
		if(srv_bt_cm_get_btdialor_mode() == MMI_TRUE)
		 kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]BT Dialer mode is set");
				return 1;								
   	}
    else if (strcmp((char*)string, "BTD_resetmode") == 0)   // Enable PortA as 115200
   	{
   		 		srv_bt_cm_set_btdialor_mode(MMI_FALSE);
		if(srv_bt_cm_get_btdialor_mode() == MMI_FALSE)
		kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Normal Mode is set");
				return 1;				
		}
	else if (strcmp((char*)string, "BTD_open") == 0)   // Enable PortA as 115200
	{
   		if(!g_bt_dialer_cntx->alloc)
			handler = srv_bt_dialer_open();
		return 1;
	}
	else if (strcmp((char*)string, "BTD_close") == 0)   // Enable PortA as 115200
	{
   		if(g_bt_dialer_cntx->alloc)
			srv_bt_dialer_close(handler);
		return 1;
	}
	else if (strcmp((char*)string, "BTD_connreq") == 0)
	{
	   srv_bt_dialer_send_connect_req(g_bt_dialer_cntx->bd_addr);
		return 1;
	}
	else if (strcmp((char*)string, "BTD_disconnreq") == 0)
	{
	   srv_bt_dialer_send_disconnect_req(SRV_BT_DIALER_GET_CM_CONN_ID);
		return 1;
}
	else if (strcmp((char*)string, "BTD_connind") == 0)
	{
		bt_hf_connect_ind_req_struct *ind = NULL;
		bt_dm_addr_struct bt_addr;
		bt_addr.nap = g_bt_dialer_cntx->bd_addr.nap;
		bt_addr.uap = g_bt_dialer_cntx->bd_addr.uap;
		bt_addr.lap = g_bt_dialer_cntx->bd_addr.lap;
		ind = (bt_hf_connect_ind_req_struct*)construct_local_para(sizeof(*ind), TD_UL);
		ind->hs_conn = MMI_FALSE;
		ind->bt_addr = bt_addr;
		ind->connection_id = 0;
		srv_bt_dialer_connect_ind(ind);
		return 1;
	}
	else if (strcmp((char*)string, "BTD_disconnind") == 0)
	{
		bt_hf_disconnect_ind_struct *disc_ind = NULL;
		bt_dm_addr_struct bt_addr;
		bt_addr.nap = g_bt_dialer_cntx->bd_addr.nap;
		bt_addr.uap = g_bt_dialer_cntx->bd_addr.uap;
		bt_addr.lap = g_bt_dialer_cntx->bd_addr.lap;
		disc_ind = (bt_hf_disconnect_ind_struct*)construct_local_para(sizeof(*disc_ind), TD_UL);
		disc_ind->bt_addr = bt_addr;
		disc_ind->connection_id = 0;
		srv_bt_dialer_disconnect_ind(disc_ind);
		return 1;
	}
	if (strcmp((char*)string, "BTD_ata") == 0)   // Enable PortA as 115200
    {
		kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Automatic answer incoming call-ATA");
		srv_bt_dialer_send_ata_req(handler);		
		return 1;														
    }
	if (strcmp((char*)string, "BTD_red") == 0)   // Enable PortA as 115200
    {
		kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Call Last Dialer Number-BLDN");
    	srv_bt_dialer_send_redial_req(handler);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_chup") == 0)   // Enable PortA as 115200
    {
		kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Disconnect All Calls-CHUP");
		srv_bt_dialer_hangup_active_calls(handler);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_vts") == 0)   // Enable PortA as 115200
    {
		kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]Set DTMF tone-VTS");
		srv_bt_dialer_send_generate_dtmf_tone_req(handler,index);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_vgs") == 0)   // Enable PortA as 115200
    {
    	srv_bt_dialer_speaker_vol_gain_req( handler, index);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_vgm") == 0)   // Enable PortA as 115200
    {
    	srv_bt_dialer_mic_vol_gain_req( handler, index);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_clip") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_send_set_clip_req(handler, KAL_TRUE );
		return 1;														
}
	if (strcmp((char*)string, "BTD_clcc") == 0)   // Enable PortA as 115200
{
		srv_bt_dialer_list_current_calls(handler);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_nrec") == 0)   // Enable PortA as 115200
  {
		srv_bt_dialer_noise_red_req(handler);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_cnum") == 0)   // Enable PortA as 115200
      {
		srv_bt_dialer_subscriber_num_req(handler);
		return 1;														
      }
	if (strcmp((char*)string, "BTD_setmask") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_register_indicators(handler,21);
		kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mask is set");
		return 1;														
  }
	if (strcmp((char*)string, "BTD_resetmask") == 0)   // Enable PortA as 115200
    {
    	srv_bt_dialer_register_indicators(handler,0);
		kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"mask is reset");
		g_bt_dialer_cntx->ind_mask = 0;
		return 1;														
    }
	if (strcmp((char*)string, "BTD_setcops") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_set_network_operator_format(handler);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_getcops") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_get_network_operator_info_req(handler);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_rhset") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_send_hold_response_set_req(handler,index);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_rhread") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_send_response_hold_read_req(handler);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_enwait") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_send_call_wait_req(handler,MMI_TRUE);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_diswait") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_send_call_wait_req(handler,MMI_FALSE);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_callhold") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_send_hold_req(handler,index);
		return 1;														
    }
	if (strcmp((char*)string, "BTD_regcallback") == 0)   // Enable PortA as 115200
    {
		srv_bt_dialer_register_hf_notifier(handler,mmi_dummy_bt_dialer_register_hf_event);
		if(g_bt_dialer_cntx->cb_ptr)
			kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv]UCM Callback pointer is Set");
		return 1;														
    }
	return 0;
}

#endif


#endif /*__BT_DIALER_SUPPORT__*/


