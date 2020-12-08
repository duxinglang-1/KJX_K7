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
 * SyncSrvCM.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * connect manager of sync
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMIDataType.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include "custom_mmi_default_value.h"
#include "mmi2syncml_struct.h"

#include "mmi_rp_srv_sync_def.h"
#include "Conversions.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "BtCMSrvGprot.h"

#include "SyncSrvGprot.h"
#include "SyncSrv.h"
#include "SyncSrvCm.h"
#include "SyncSrvDatabase.h"
#include "SyncSrvSync.h"

#include "SyncSrvPhoneSync.h"
#include "SyncSrvCmBT.h"
#include "Unicodexdcl.h" 

/*****************************************************************************
 * Typedef 
 *****************************************************************************/
#define MMI_SYNCML_DEV_CONN_ACCEPT 1
#define MMI_SYNCML_DEV_CONN_REJECT 0

#define MAX_MMI_SYNCML_DEV_STR_LEN 96

#define SYNCML_DEV_BTCM_OPR_MASK_DEACTIVE	0x01
#define SYNCML_DEV_BTCM_OPR_MASK_DISCONN	0x02
#define SYNCML_DEV_BTCM_OPR_MASK_DEINIT	    0x04

/*****************************************************************************
* Typedef 
*****************************************************************************/

typedef struct
{
	U8	cm_opr_flag;
	/* If device B, then after data exchange, sync state will be reset */
	MMI_BOOL is_state_reset;
	U8	dev_role;
	
	srv_sync_cm_state_enum curr_state;
	srv_bt_cm_bt_addr remote_bt_addr;
	U32 cm_conn_id;
	srv_sync_type *sync;

	U8 imei[21];
	/* remote bt name that saved in local device */
	CHAR	remote_dev_name[(MAX_SYNCML_DEV_NAME_LEN + 1) * ENCODING_LENGTH];
	CHAR	remote_uri[MAX_SYNCML_SERVER_ADDR_LEN];
}srv_sync_cm_bt_cntx;

/* Bt control contact */
typedef struct{
	srv_sync_cm_state_enum bt_state;
	srv_sync_cm_type *active_cm;
}srv_sync_bt_cntx;

/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
#define SRV_SYNC_SET_ACTIVE_CM(_cm) (g_srv_sync_bt_cntx.active_cm = (_cm))
#define SRV_SYNC_GET_ACTIVE_CM() (g_srv_sync_bt_cntx.active_cm)
#define SRV_SYNC_SET_BT_STATE(_state) (g_srv_sync_bt_cntx.bt_state = (_state))
#define SRV_SYNC_GET_BT_STATE() (g_srv_sync_bt_cntx.bt_state)
#define SRV_SYNC_IS_BT_STATE(_state) (g_srv_sync_bt_cntx.bt_state == (_state))

static srv_sync_bt_cntx g_srv_sync_bt_cntx;

/*****************************************************************************
 * Local Function 
 *****************************************************************************/
static MMI_BOOL srv_sync_cm_bt_conn(srv_sync_cm_type *obj);
static void srv_sync_cm_bt_on_ask_sync(srv_sync_cm_type *obj, void *param);
static void srv_sync_cm_bt_on_disconnected(srv_sync_cm_type *obj, void *param);
static void srv_sync_cm_bt_on_connnected(srv_sync_cm_type *obj, void *param);
static void srv_sync_cm_bt_set_name(srv_sync_cm_type *obj, const CHAR *name);


static void srv_sync_cm_bt_pwr_switch_notify(U8 bt_state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    oslMsgType msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	SRV_SYNC_LOG1(MMI_SRV_SYNC_CM_PWR_SWITCH, bt_state);

    if (bt_state == SRV_SYNC_CM_STATE_BT_ON)
    {
        msg_id = MSG_ID_MMI_SYNCML_BT_POWER_ON_NOTIFY_REQ;
	}
    else //if(bt_state == SRV_SYNC_CM_STATE_READY)
	{
        msg_id = MSG_ID_MMI_SYNCML_BT_POWER_OFF_NOTIFY_REQ;
    }

#ifdef __MTK_TARGET__
    mmi_frm_send_ilm(MOD_SYNCML, msg_id, NULL, NULL);
#endif
}

MMI_BOOL srv_sync_cm_bt_is_state(srv_sync_cm_type *obj, U16 state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, MMI_FALSE);

	cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	SRV_SYNC_LOG2(MMI_SRV_SYNC_CM_BT_IS_STATE, cntx->curr_state, state);
	
	return (MMI_BOOL)(cntx->curr_state == state);
}

void srv_sync_cm_bt_set_state(srv_sync_cm_type *obj, U16 state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);
	cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	cntx->curr_state = (srv_sync_cm_state_enum)state;
}

void srv_sync_cm_bt_set_mask(srv_sync_cm_type *obj, U32 mask)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);
	cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	cntx->cm_opr_flag |= mask;
}

static void srv_sync_cm_bt_ask_conn_rsp(srv_sync_cm_type *obj, U8 status)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_syncml_bt_ask_accept_conn_res_struct *ask_res_ptr;
    	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	ask_res_ptr = OslAllocDataPtr(mmi_syncml_bt_ask_accept_conn_res_struct);

    if (status == SRV_SYNC_ANSWER_ACCEPT && obj != NULL)
	{
    	srv_sync_cm_bt_cntx *cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
    	cntx->dev_role = MMI_SYNCML_DEV_ROLE_B;
        
        /* Only consider the three database now, only used when bt act as role B */
        //mmi_syncml_device_lock_all_db(); srv_sync_phone_lock_db()

        srv_sync_cm_bt_set_state(obj, SRV_SYNC_CM_STATE_CONNECTING);
	}
    else
	{
        srv_sync_cm_destroy(obj);
	
		SRV_SYNC_SET_BT_STATE(SRV_SYNC_CM_STATE_BT_ON);
	}

	ask_res_ptr->result = status; /* 1 or 0 */

#ifdef __MTK_TARGET__
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_BT_ASK_ACCEPT_CONN_RES, (oslParaType *)ask_res_ptr, NULL);
#endif
}

static void srv_sync_cm_bt_ask_sync_rsp(srv_sync_cm_type *obj, U16 rsp)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	//U16 result = rsp;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (rsp == MMI_SYNCML_DEV_SYNC_REJECT ||
		!srv_sync_cm_bt_is_state(obj, SRV_SYNC_CM_STATE_SYNC_ASK))
	{
		srv_sync_reject_sync_request(NULL);
		srv_sync_cm_destroy(obj);
		
		SRV_SYNC_SET_BT_STATE(SRV_SYNC_CM_STATE_BT_ON);

	}
	else
	{
		srv_sync_cm_bt_set_state(obj, SRV_SYNC_CM_STATE_SYNC_ASK_RSP);
	}
}

static void srv_sync_cm_bt_activate(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SRV_SYNC_CM_BT_ACTIVE, g_srv_sync_bt_cntx.bt_state);

	if (g_srv_sync_bt_cntx.bt_state == SRV_SYNC_CM_STATE_READY)
	{
		g_srv_sync_bt_cntx.bt_state = SRV_SYNC_CM_STATE_BT_ON;

		/* start obex server at syncml task */
		srv_sync_cm_bt_pwr_switch_notify(SRV_SYNC_CM_STATE_BT_ON);
	}
	
	srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_SYNCML_DEV_PROFILE_UUID);
}

static void srv_sync_cm_bt_deactivate(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SRV_SYNC_CM_BT_DEACTIVE, g_srv_sync_bt_cntx.bt_state);

    if (g_srv_sync_bt_cntx.bt_state > SRV_SYNC_CM_STATE_READY)
    {
    	if (g_srv_sync_bt_cntx.active_cm != NULL) 
        {
        /* The conf handler will be called after the sync finshed*/
           // mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_DEACTIVE);
            srv_sync_cm_bt_set_mask(g_srv_sync_bt_cntx.active_cm, SYNCML_DEV_BTCM_OPR_MASK_DEACTIVE);
			srv_sync_cm_on_disconn(g_srv_sync_bt_cntx.active_cm, NULL);
		
            return;
        }
        else
        {
            g_srv_sync_bt_cntx.bt_state = SRV_SYNC_CM_STATE_READY;
            srv_sync_cm_bt_pwr_switch_notify(SRV_SYNC_CM_STATE_READY);
        }
    }

    	srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID);

}

static void srv_sync_cm_bt_disconn(U32 conn_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_srv_sync_bt_cntx.active_cm != NULL) 
	{
		srv_sync_cm_on_disconn(g_srv_sync_bt_cntx.active_cm, &conn_id);
	}
	else
	{
		//
	}
}

static void srv_sync_on_bt_ask_conn(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_syncml_bt_ask_accept_conn_ind_struct *ask_conn;
	srv_bt_cm_bt_addr bt_addr;
	srv_sync_cm_type *active_cm;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SRV_SYNC_CM_BT_ASK_CONN);
	
    if (srv_sync_is_synchronizing()) //  emit.
    {
        srv_sync_cm_bt_ask_conn_rsp(NULL, MMI_SYNCML_DEV_CONN_REJECT);
		
        return;
    }
	
	ask_conn = (mmi_syncml_bt_ask_accept_conn_ind_struct *)param;
    bt_addr.lap = ask_conn->bt_addr_lap;
    bt_addr.nap = ask_conn->bt_addr_nap;
    bt_addr.uap = ask_conn->bt_addr_uap;

#ifdef __MMI_BT_AUTHORIZE__
	if (srv_bt_cm_get_authorize(&bt_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_REJECT)
	{
		srv_sync_cm_bt_ask_conn_rsp(NULL, MMI_SYNCML_DEV_CONN_REJECT);
		
		return;
	}
#endif /* __MMI_BT_AUTHORIZE__ */

	active_cm = srv_sync_cm_bt_create(&bt_addr);
	srv_sync_cm_bt_set_role(active_cm, MMI_SYNCML_DEV_ROLE_B);
	srv_sync_cm_bt_set_name(active_cm, (const CHAR *)ask_conn->device_name);
	
	if (!srv_sync_cm_connect(active_cm))
	{
		SRV_SYNC_LOG0(MMI_SRV_SYNC_CM_BT_ASK_CONN_FAIL);

		srv_sync_cm_destroy(active_cm);
		srv_sync_cm_bt_ask_conn_rsp(NULL, MMI_SYNCML_DEV_CONN_REJECT);

		return;
	}
	
	g_srv_sync_bt_cntx.active_cm = active_cm;
	srv_sync_cm_on_ask_conn(g_srv_sync_bt_cntx.active_cm, param);
	
}


static void srv_sync_connected_ind_hdlr(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SRV_SYNC_CM_CONN_IND, g_srv_sync_bt_cntx.bt_state);
	

	if (g_srv_sync_bt_cntx.active_cm != NULL)
	{
		srv_sync_cm_bt_on_connnected(g_srv_sync_bt_cntx.active_cm, param);
	}
}

static void srv_sync_disconnected_ind_hdlr(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (g_srv_sync_bt_cntx.active_cm != NULL)
	{
		srv_sync_cm_bt_on_disconnected(g_srv_sync_bt_cntx.active_cm, param);
	}
}

static void srv_sync_ask_sync_ind_hdlr(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (g_srv_sync_bt_cntx.active_cm != NULL)
	{
		srv_sync_cm_bt_on_ask_sync(g_srv_sync_bt_cntx.active_cm, param);
	}
}

static void srv_sync_ask_database_ind_hdlr(void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	srv_sync_on_database_info(srv_sync_active_sync(), param);
}

void srv_sync_cm_bt_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_bt_cm_profile_struct syncml_profile;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
	SRV_SYNC_LOG0(MMI_SRV_SYNC_CM_BT_INIT);
	
	g_srv_sync_bt_cntx.bt_state = SRV_SYNC_CM_STATE_READY;
	
	syncml_profile.profile_id = SRV_BT_CM_SYNCML_DEV_PROFILE_UUID;
	syncml_profile.activater = srv_sync_cm_bt_activate;
	syncml_profile.deactivater = srv_sync_cm_bt_deactivate;
	syncml_profile.disconnector = srv_sync_cm_bt_disconn;
	
	if (srv_bt_cm_profile_register(&syncml_profile))
	{
	    SetProtocolEventHandler(srv_sync_on_bt_ask_conn, 		MSG_ID_MMI_SYNCML_BT_ASK_ACCEPT_CONN_IND);
		SetProtocolEventHandler(srv_sync_connected_ind_hdlr, 	MSG_ID_MMI_SYNCML_BT_CONNECTED_IND);
		SetProtocolEventHandler(srv_sync_disconnected_ind_hdlr, MSG_ID_MMI_SYNCML_BT_DISCONNECTED_IND);
		SetProtocolEventHandler(srv_sync_ask_sync_ind_hdlr, 	MSG_ID_MMI_SYNCML_DEVICE_REMOTEINFO_IND);
		SetProtocolEventHandler(srv_sync_ask_database_ind_hdlr, MSG_ID_MMI_SYNCML_DEVICE_SYNC_DB_IND);
	}
	else
	{
		MMI_ASSERT(!"[SyncSrvCmBt.c]reg bt profile fail.");
	}
}

U8 srv_sync_cm_bt_role(srv_sync_cm_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   RETURN_VAL_IF_FAIL(obj != NULL, 0);

   return cntx->dev_role;
}

void srv_sync_cm_bt_set_role(srv_sync_cm_type *obj, U8 role)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
   RETURN_IF_FAIL(obj != NULL);

   cntx->dev_role = role;
}

static void srv_sync_cm_bt_set_name(srv_sync_cm_type *obj, const CHAR *name)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	mmi_ucs2ncpy((CHAR *)cntx->remote_dev_name, name, MAX_SYNCML_DEV_NAME_LEN);
}


void *srv_sync_cm_bt_addr(srv_sync_cm_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	return &cntx->remote_bt_addr;
}

#define CM_BT
static void srv_sync_cm_bt_on_ask_conn(srv_sync_cm_type *obj, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

    /* If the device has been authorized, than device B will accept this sync automatically */
#ifdef __MMI_BT_AUTHORIZE__
	if (srv_bt_cm_get_authorize(&cntx->remote_bt_addr) == SRV_BT_CM_AUTHORIZE_ALWAYS_CONNECT)
    {
        srv_sync_cm_bt_ask_conn_rsp(obj, MMI_SYNCML_DEV_CONN_ACCEPT);
    }
    else
#endif /* __MMI_BT_AUTHORIZE__ */
    {
			srv_sync_ask_conn_evt_struct ask_evt;

			MMI_FRM_INIT_EVENT(&ask_evt, EVT_ID_SRV_SYNC_ASK_CONN);
			
			ask_evt.lap = cntx->remote_bt_addr.lap;
			ask_evt.uap = cntx->remote_bt_addr.uap;
			ask_evt.nap = cntx->remote_bt_addr.nap;

			srv_sync_cm_bt_set_state(obj, SRV_SYNC_CM_STATE_CONN_ASK);

			MMI_FRM_CB_EMIT_POST_EVENT(&ask_evt);
		}
}

static void srv_sync_cm_bt_on_ask_sync(srv_sync_cm_type *obj, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_device_remoteinfo_ind_struct *remote_info_ptr;
	srv_sync_cm_bt_cntx *cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
		
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	remote_info_ptr = (mmi_syncml_device_remoteinfo_ind_struct *)param;

	if (remote_info_ptr->f_is_phone == 1)
	{
		memcpy(cntx->remote_uri, (void *)remote_info_ptr->device_uri, MAX_SYNCML_SERVER_ADDR_LEN);

		/* Error state, the conn has been disconnected*/
		if (SRV_SYNC_CM_STATE_CONNECTING != cntx->curr_state)
		{
			srv_sync_reject_sync_request(NULL);
			
			return;
		}
		else
		{
			srv_sync_ask_sync_evt_struct ask_evt;
			
			MMI_FRM_INIT_EVENT(&ask_evt, EVT_ID_SRV_SYNC_ASK_SYNC);
			
			ask_evt.sync = SRV_SYNC_PHONE;
			ask_evt.regular = MMI_FALSE;
			ask_evt.accnt_index = 0xFF;
			
			ask_evt.lap = cntx->remote_bt_addr.lap;
			ask_evt.uap = cntx->remote_bt_addr.uap;
			ask_evt.nap = cntx->remote_bt_addr.nap;
			
			ask_evt.user_data = obj;
			
			MMI_FRM_CB_EMIT_POST_EVENT(&ask_evt);
			srv_sync_cm_bt_set_state(obj, SRV_SYNC_CM_STATE_SYNC_ASK);
		}
	}
	else
	{
		srv_sync_cm_bt_ask_sync_rsp(obj, SRV_SYNC_ANSWER_REJECT);
	}
}


/*****************************************************************************
 * Please refer to SyncSrvGprot.h
*****************************************************************************/
void srv_sync_answer(srv_sync_answer_enum answer)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (g_srv_sync_bt_cntx.active_cm != NULL)
	{
		srv_sync_cm_on_rsp(g_srv_sync_bt_cntx.active_cm, answer);
	}
}

static void srv_sync_cm_bt_on_rsp(srv_sync_cm_type *obj, U32 rsp)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);
	cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);

	switch (cntx->curr_state)
	{
		case SRV_SYNC_CM_STATE_CONN_ASK:
			srv_sync_cm_bt_ask_conn_rsp(obj, rsp);
			break;

		case SRV_SYNC_CM_STATE_SYNC_ASK:
			srv_sync_cm_bt_ask_sync_rsp(obj, rsp);
			break;

		default:
			break;
	}
}


static void srv_sync_cm_bt_on_conn(srv_sync_cm_type *obj, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	RETURN_IF_FAIL(obj != NULL);
}

static MMI_BOOL srv_sync_cm_bt_conn(srv_sync_cm_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_cntx *cntx;
	CHAR name_buff[MAX_SYNCML_DEV_NAME_LEN + 1];
	S32 conn_id;
	CHAR *name_ptr;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	RETURN_VAL_IF_FAIL(obj != NULL, MMI_FALSE);

	cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	/*
	  * for out-going connect, set name_ptr as NULL, 
	  *	if the device is newly searched, it didn't has the name in CM
	  */
	if (cntx->dev_role == MMI_SYNCML_DEV_ROLE_B)
	{
    srv_bt_cm_get_dev_name(
        &cntx->remote_bt_addr,
        (MAX_SYNCML_DEV_NAME_LEN + 1), 
        (U8*)name_buff);

		name_ptr = (CHAR *)name_buff;
	}
	else
	{
		name_ptr = NULL;
	}
	
	conn_id = srv_bt_cm_start_conn((MMI_BOOL)(cntx->dev_role == MMI_SYNCML_DEV_ROLE_B), 
						 SRV_BT_CM_SYNCML_DEV_PROFILE_UUID,
						 &cntx->remote_bt_addr,
						 name_ptr);
	//Modis test code
#ifndef __MTK_TARGET__
	conn_id = 0;
#endif

	if (conn_id < 0)
	{
		return MMI_FALSE;
	}

	cntx->cm_conn_id = (U32)conn_id;
	
	return MMI_TRUE;
}

static void srv_sync_cm_bt_on_connnected(srv_sync_cm_type *obj, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_bt_cm_bt_addr *bt_addr;
	srv_sync_cm_bt_cntx *cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	srv_sync_cm_evt_struct cm_evt;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SRV_SYNC_CM_BT_CONNECTED, g_srv_sync_bt_cntx.bt_state);

	MMI_ASSERT(param != NULL);

	bt_addr = (srv_bt_cm_bt_addr *)&cntx->remote_bt_addr;
	
	if (bt_addr->lap ==0 && bt_addr->uap == 0 && bt_addr->nap == 0)
	{
		MMI_ASSERT(!"[SyncSrvBT.c]ERRROR BT ADDR!");
	}

	srv_bt_cm_connect_ind(cntx->cm_conn_id);

	/* Notify MMI about connected */	

	MMI_FRM_INIT_EVENT(&cm_evt, EVT_ID_SRV_SYNC_CM);
	cm_evt.notify = SRV_SYNC_CM_NOTIFY_CONN;

	MMI_FRM_CB_EMIT_POST_EVENT(&cm_evt);

}


static void srv_sync_cm_bt_disconnect(srv_sync_cm_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	SRV_SYNC_LOG1(MMI_SRV_SYNC_CM_BT_DISCONNECTED, g_srv_sync_bt_cntx.bt_state);

	RETURN_IF_FAIL(obj != NULL);
}

// disconn by bt
void srv_sync_cm_bt_on_disconn(srv_sync_cm_type *obj, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_type *sync = srv_sync_active_sync();

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	SRV_SYNC_LOG1(MMI_SRV_SYNC_CM_BT_ON_DISCONN, g_srv_sync_bt_cntx.bt_state);

	RETURN_IF_FAIL(obj != NULL);
	
	
    if (sync != NULL && srv_sync_match(sync, SRV_SYNC_PHONE))
	{        
        srv_sync_cm_bt_set_state(obj, SRV_SYNC_CM_STATE_DISCONN);
		
		srv_sync_abort(SRV_SYNC_PHONE);
    }
}

// finish disconnedted
static void srv_sync_cm_bt_on_disconnected(srv_sync_cm_type *obj, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sync_cm_evt_struct cm_evt;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);
	
	/* Notify MMI about disconn */	
	
	MMI_FRM_INIT_EVENT(&cm_evt, EVT_ID_SRV_SYNC_CM);
	cm_evt.notify = SRV_SYNC_CM_NOTIFY_DISCONN;
	
	MMI_FRM_CB_EMIT_POST_EVENT(&cm_evt);
	
	/* Disconn is coming before sync confirmation */
	if (srv_sync_cm_bt_is_state(obj, SRV_SYNC_CM_STATE_CONNECTING))
	{
		srv_sync_cm_destroy(obj);
	}
}

static void srv_sync_cm_bt_reset(srv_sync_cm_type *obj)
{	
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/  
	srv_sync_cm_bt_cntx *cntx = GET_OBJ_PRIV(srv_sync_cm_bt_cntx, obj);
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	if (cntx->cm_conn_id != MMI_SYNCML_DEV_INVALID_CONN_ID)
	{       
		srv_bt_cm_stop_conn(cntx->cm_conn_id);
	}
	
	SRV_SYNC_SET_BT_STATE(SRV_SYNC_CM_STATE_BT_ON);

	/* BT power off case this finish sync */
	if (cntx->cm_opr_flag & SYNCML_DEV_BTCM_OPR_MASK_DEACTIVE)
	{
		SRV_SYNC_SET_BT_STATE(SRV_SYNC_CM_STATE_READY);
		
		srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_SYNCML_DEV_PROFILE_UUID);
        srv_sync_cm_bt_pwr_switch_notify(SRV_SYNC_CM_STATE_READY);
	}
}

static void srv_sync_cm_bt_destroy(srv_sync_cm_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (obj != NULL)
	{
		srv_sync_cm_bt_reset(obj);
		
		if (obj->priv != NULL)
		{
			OslMfree(obj->priv);
			obj->priv = NULL;
		}

		OslMfree(obj);
		obj = NULL;
	}
	
	SRV_SYNC_SET_ACTIVE_CM(NULL);
}

srv_sync_cm_type *srv_sync_cm_bt_create(void *addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sync_cm_type *obj;
	srv_sync_cm_bt_cntx *cntx;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
	obj = (srv_sync_cm_type *)OslMalloc(sizeof(srv_sync_cm_type));

	obj->destroy = srv_sync_cm_bt_destroy;
	
	obj->on_ask_conn = srv_sync_cm_bt_on_ask_conn;
	obj->on_ask_sync = srv_sync_cm_bt_on_ask_sync;

	obj->conn = 		srv_sync_cm_bt_conn;
	obj->on_conn = 		srv_sync_cm_bt_on_conn;
	obj->on_connected = srv_sync_cm_bt_on_connnected;

	obj->disconn = 	  	   srv_sync_cm_bt_disconnect;
	obj->on_disconn = 	   srv_sync_cm_bt_on_disconn;
	obj->on_disconnected = srv_sync_cm_bt_on_disconnected;

	obj->on_rsp = srv_sync_cm_bt_on_rsp;

	cntx = (srv_sync_cm_bt_cntx *)OslMalloc(sizeof(srv_sync_cm_bt_cntx));
	memset(cntx, 0, sizeof(srv_sync_cm_bt_cntx));
	cntx->curr_state = SRV_SYNC_GET_BT_STATE();
	cntx->cm_conn_id = MMI_SYNCML_DEV_INVALID_CONN_ID;
	
	memcpy(&cntx->remote_bt_addr, addr, sizeof(srv_bt_cm_bt_addr));
	
	obj->priv = cntx;

	SRV_SYNC_SET_ACTIVE_CM(obj);
	
	return obj;
}

#ifdef __SYNCML_UT_MSG__
void srv_sync_bt_msg_simulator(void *msg, U32 msg_id)
{
	switch (msg_id)
	{
		case MSG_ID_MMI_SYNCML_BT_ASK_ACCEPT_CONN_IND:
			srv_sync_on_bt_ask_conn(msg);
			break;
			
		case MSG_ID_MMI_SYNCML_BT_CONNECTED_IND:
			srv_sync_connected_ind_hdlr(msg);
			break;
			
		case MSG_ID_MMI_SYNCML_BT_DISCONNECTED_IND:
			srv_sync_disconnected_ind_hdlr(msg);
			break;
			
		case MSG_ID_MMI_SYNCML_DEVICE_REMOTEINFO_IND:
			srv_sync_ask_sync_ind_hdlr(msg);
			break;
		case MSG_ID_MMI_SYNCML_DEVICE_SYNC_DB_IND:
			srv_sync_ask_database_ind_hdlr(msg);
			break;			
		default:
			break;

	}
}

#endif /*  __SYNCML_UT_MSG__ */

