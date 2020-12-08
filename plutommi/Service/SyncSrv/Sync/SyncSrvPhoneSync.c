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
 * AlarmSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm service management.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include "mmi2syncml_struct.h"
#include "mmi_rp_srv_sync_def.h"

#include "SyncSrv.h"
#include "SyncSrvPhoneSync.h"
#include "SyncSrvPhoneAccnt.h"

#include "SyncSrvSync.h"
#include "common_nvram_editor_data_item.h"
#include "BTcmSrvGprot.h"
#include "SyncSrvCm.h"
#include "SyncSrvCmBT.h"
#include "SyncSrvDatabase.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/
typedef struct{
	U8 imei[16];
	U8 sml_role;
	U8 app_to_sync;
	MMI_BOOL is_new;
}srv_sync_phone_cntx;

/*****************************************************************************
* Global Variables 
*****************************************************************************/


/*****************************************************************************
* Local Function 
*****************************************************************************/
static void srv_sync_phone_on_ask_sync_rsp(srv_sync_type *obj, U8 status);

void srv_sync_phone_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	srv_sync_cm_bt_init();
}

void srv_sync_reject_sync_request(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_syncml_device_remoteinfo_res_struct *remote_info;
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 
	remote_info = OslAllocDataPtr(mmi_syncml_device_remoteinfo_res_struct);
	MMI_ASSERT(remote_info != NULL);

	remote_info->result = SRV_SYNC_ANSWER_REJECT; /* 1 or 0 */  

//    mmi_syncml_device_set_state(MMI_SYNCML_DEVICE_STATE_SYNC_ASK_RSP);

    memset(&remote_info->db_info, 0, sizeof(mmi_syncml_device_db_info_struct));
    //mmi_syncml_device_unlock_all_db();   
    
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_DEVICE_REMOTEINFO_RES, (oslParaType *)remote_info, NULL);
}

static srv_sync_ret_enum srv_sync_phone_precheck(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, SRV_SYNC_RET_FAIL);

	return SRV_SYNC_RET_OK;
}

// for device B
Ret srv_sync_find_dev_callback(void *data, void* usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	nvram_ef_syncml_device_accnt_struct *accnt = (nvram_ef_syncml_device_accnt_struct *)data;
	srv_bt_cm_bt_addr *bt_addr = (srv_bt_cm_bt_addr *)usr_data;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	if (accnt->dev_bt_addr.lap == bt_addr->lap &&
		accnt->dev_bt_addr.nap == bt_addr->nap &&
		accnt->dev_bt_addr.uap == bt_addr->uap)
	{
		return RET_STOP;
	}

	return RET_OK;
}

void srv_sync_phone_ask_sync_rsp(srv_sync_type *obj, U16 rsp)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U16 result = rsp;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (obj != NULL &&
		srv_sync_cm_bt_is_state(obj->cm, SRV_SYNC_CM_STATE_SYNC_ASK))
	{
		srv_sync_phone_on_ask_sync_rsp(obj, result);
	}
	else
	{
		//srv_sync_abort(SRV_SYNC_PHONE);
		// the sync has been canceled by other side.
	}
}

static void srv_sync_phone_on_ask_sync_rsp(srv_sync_type *obj, U8 status)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_syncml_device_remoteinfo_res_struct *data_ptr;
	srv_sync_phone_cntx *cntx = GET_OBJ_PRIV(srv_sync_phone_cntx, obj);

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    
	kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_2, "[SYNC]srv_sync_phone_on_ask_sync_rsp()");
	
	data_ptr = OslAllocDataPtr(mmi_syncml_device_remoteinfo_res_struct);  
	data_ptr->result = status; /* 1 or 0 */
    
    if (status == MMI_SYNCML_DEV_SYNC_ACCEPT && cntx != NULL && !cntx->is_new)
    {
		srv_sync_database_type *database;
		U8 i;
		
    	data_ptr->sml_role = cntx->sml_role;
    	// fill database info.
		for(i = 0; i < srv_sync_get_total_database(); i++)
		{
			database = srv_sync_get_database(i);
			srv_sync_database_on_start(database, SRV_SYNC_PHONE, obj->active_accnt, &data_ptr->db_info);
		}

        memcpy(&data_ptr->imei[0], "IMEI:", 5);
        memcpy(&data_ptr->imei[5], cntx->imei, 15);
		
        data_ptr->imei[20] = 0;

    }
    /* If reject or new device, then just return empty */
    else
    {
        memset(&data_ptr->db_info, 0, sizeof(mmi_syncml_device_db_info_struct));
    }
	
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_DEVICE_REMOTEINFO_RES, (oslParaType *)data_ptr, NULL);
}


/* start from device A */
static void srv_sync_phone_start_sync(srv_sync_type *obj, const U8 *imei)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_device_start_sync_req_struct *data_ptr;
	nvram_ef_syncml_device_accnt_struct *accnt;

	srv_sync_database_type *database;
	U8 i;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_2, "[SYNC]srv_sync_phone_start_sync()");

	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_phone_read_accnt(obj->active_accnt);
	
	data_ptr = OslAllocDataPtr(mmi_syncml_device_start_sync_req_struct);

	/* Destination */
	data_ptr->bt_addr_lap = accnt->dev_bt_addr.lap;
	data_ptr->bt_addr_uap = accnt->dev_bt_addr.uap;
	data_ptr->bt_addr_nap = accnt->dev_bt_addr.nap;
	
	data_ptr->sml_role = accnt->role;
	strcpy((CHAR*)data_ptr->device_uri, (CHAR*)accnt->dev_uri);
	
	// fill database info.
	for(i = 0; i < srv_sync_get_total_database(); i++)
	{
		database = srv_sync_get_database(i);
		srv_sync_database_on_start(database, SRV_SYNC_PHONE, obj->active_accnt, &data_ptr->db_info);
	}

	/* Local IMEI */
	memcpy(&data_ptr->imei[0], "IMEI:", 5);
	memcpy(&data_ptr->imei[5], imei, 15);
	data_ptr->imei[20] = 0;

	data_ptr->sync_type = SYNCML_SYNC_TWO_WAY_SYNC;
	
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_DEVICE_START_SYNC_REQ, (oslParaType *)data_ptr, NULL);
}


static void srv_sync_phone_start(srv_sync_type *obj, const U8 *imei)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_2, "[SYNC]srv_sync_phone_start()");
	
	RETURN_IF_FAIL(obj != NULL);

	// ask for sync
	if (srv_sync_cm_bt_role(obj->cm) == MMI_SYNCML_DEV_ROLE_B)
	{
		if (!srv_sync_cm_bt_is_state(obj->cm, SRV_SYNC_CM_STATE_SYNC_ASK_RSP))
		{
			// Wrong CM state.
			return;
		}
		srv_sync_phone_on_ask_sync_rsp(obj, MMI_SYNCML_DEV_SYNC_ACCEPT);
	}
	else
	{
		srv_sync_phone_start_sync(obj, imei);
	}
}


/*****************************************************************************
* FUNCTION
*   srv_sync_phone_on_query
* DESCRIPTION
*	only have this chance to reset the pre-selected database which won't involved by this sync
* PARAMETERS
*	obj		:[IN]	phone sync object
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_phone_on_query(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_cntx *cntx = GET_OBJ_PRIV(srv_sync_phone_cntx, obj);

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	if (srv_sync_cm_bt_role(obj->cm) == MMI_SYNCML_DEV_ROLE_B)
	{
	srv_sync_reset_database((U32)cntx->app_to_sync);
}
}

static void srv_sync_phone_on_finish(srv_sync_type *obj, void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	nvram_ef_syncml_device_accnt_struct *accnt;
	mmi_syncml_finish_sync_ind_struct *finish_info = TYPE_CAST(mmi_syncml_finish_sync_ind_struct, msg);
	srv_sync_phone_cntx *cntx = GET_OBJ_PRIV(srv_sync_phone_cntx, obj);
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	accnt = srv_sync_phone_read_accnt(obj->active_accnt);
	
	kal_wap_trace(MOD_MMI_CONN_APP,
				  TRACE_GROUP_2,
				  "[SYNCML]srv_sync_phone_on_finish()");
	
	if (accnt != NULL)
	{
		nvram_ef_syncml_view_log_struct *vlog;
		const srv_sync_db_info_type *db_info;
		srv_sync_database_type *database;
		S16 err;
		U8 i;

		/* 1. update the selected app */
		if(0 != cntx->app_to_sync)
			{
		  		accnt->app_to_sync = cntx->app_to_sync;
			}
		else
			{
               accnt->app_to_sync = srv_sync_get_total_database_type();
			}
			
		/* 2. Update Remote device info */
		if (finish_info != NULL && finish_info->f_is_device)
		{
			if (strlen((CHAR *)finish_info->d2d_info.device_uri) != 0)
			{
	        	strncpy((CHAR*)accnt->dev_uri, 
						(CHAR*)finish_info->d2d_info.device_uri,
						MAX_SYNCML_SERVER_ADDR_LEN);
			}

			if (finish_info->d2d_info.f_sml_role_updated)
			{
				accnt->role = finish_info->d2d_info.sml_new_role;
			}
		}

		/* 3. Update sync log */
		vlog = SYNC_MALLOC(nvram_ef_syncml_view_log_struct);

    vlog->sync_result = finish_info->result;
    
		vlog->last_sync_time = srv_sync_get_current_time();
		strncpy((CHAR *)vlog->last_sync_server, (CHAR *)accnt->dev_uri, MAX_SYNCML_SERVER_ADDR_LEN);
		
		vlog->app_to_sync = cntx->app_to_sync;
		vlog->db_sync_result = 0;

		for(i = 0; i < srv_sync_get_total_database(); i++)
		{
			database = srv_sync_get_database(i);
			db_info = srv_sync_database_db_info(database);
			if (db_info->fail)
			{
				vlog->db_sync_result |= db_info->db_type;
			}

			vlog->clt_ok_cnt[db_info->id][0] = db_info->ok_cnt[0];
			vlog->clt_ok_cnt[db_info->id][1] = db_info->ok_cnt[1];
			vlog->clt_ok_cnt[db_info->id][2] = db_info->ok_cnt[2];
			vlog->clt_ng_cnt[db_info->id] = db_info->fail_cnt;

			vlog->svr_ok_cnt[db_info->id][0] = db_info->srv_ok_cnt[0];
			vlog->svr_ok_cnt[db_info->id][1] = db_info->srv_ok_cnt[1];
			vlog->svr_ok_cnt[db_info->id][2] = db_info->srv_ok_cnt[2];
			vlog->svr_ng_cnt[db_info->id] = db_info->srv_fail_cnt;
			
		}

		WriteRecord(NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID,
					(obj->active_accnt + 1),
					vlog,
					NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE,
					&err);

		SYNC_MFREE(vlog);

	}

}

static void srv_sync_phone_abort(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);
	srv_sync_send_abort_sync();
}

void srv_sync_on_database_info(srv_sync_type *obj, void *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	nvram_ef_syncml_device_accnt_struct *accnt;
	mmi_syncml_device_sync_db_ind_struct *db_info;
	srv_sync_phone_cntx *cntx = GET_OBJ_PRIV(srv_sync_phone_cntx, obj);
	U16 id;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_2, "[SYNC]srv_sync_on_database_info()");
	
	RETURN_IF_FAIL(obj != NULL);
	
	db_info = (mmi_syncml_device_sync_db_ind_struct *)param;
	cntx->app_to_sync |= db_info->synced_db_type;
	
	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_phone_read_accnt(obj->active_accnt);
	id = srv_sync_get_database_id(db_info->synced_db_type);
	
	strncpy((CHAR *)accnt->database_address[id], (CHAR *)db_info->database_remote_uri, MAX_SYNCML_DATABASE_ADDR_LEN);
}


static U32 srv_sync_phone_get_selected_db(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_cntx *cntx = GET_OBJ_PRIV(srv_sync_phone_cntx, obj);
	nvram_ef_syncml_device_accnt_struct *accnt;	
	U32 app_to_sync;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, 0);

	/* for database B, set all database as selected. */
	if (srv_sync_cm_bt_role(obj->cm) == MMI_SYNCML_DEV_ROLE_B)
	{
		app_to_sync = srv_sync_get_total_database_type();
	}
	else
	{	
		accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_phone_read_accnt(obj->active_accnt);
		app_to_sync = accnt->app_to_sync;
		cntx->app_to_sync = accnt->app_to_sync;
	}
	
	kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_2, "[SYNC]srv_sync_phone_get_selected_db()=%d", app_to_sync);
	
	return app_to_sync;
}

static void srv_sync_phone_destroy(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	kal_wap_trace(MOD_MMI_CONN_APP, 
				  TRACE_GROUP_2, 
				  "[SYNC][SyncSrvPhoneSync.c]srv_sync_phone_destroy()");

	if (obj != NULL)
	{
		srv_sync_cm_destroy(obj->cm);
		
		if (obj->priv != NULL)
		{
			OslMfree(obj->priv);
		}
		
		OslMfree(obj);
		obj = NULL;
	}
}


/*****************************************************************************
* FUNCTION
*	srv_sync_phone_create
* DESCRIPTION
*	create database type
* PARAMETERS
*	accnt_index	:[IN]	account index
*	user_data	:[IN]	user data
* RETURNS
*	srv_sync_type
*****************************************************************************/
srv_sync_type* srv_sync_phone_create(U8 accnt_index, void* user_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_type *obj = (srv_sync_type *)OslMalloc(sizeof(srv_sync_type));
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	kal_wap_trace(MOD_MMI_CONN_APP, 
				  TRACE_GROUP_2, 
				  "[SYNC][SyncSrvPhoneSync.c]srv_sync_phone_create(accnt=%d, user_data=%d)",
				  accnt_index,
				  user_data);

	if (obj != NULL)
	{
		memset(obj, 0, sizeof(srv_sync_type));
		
	obj->on_query = srv_sync_phone_on_query;
	obj->on_finish = srv_sync_phone_on_finish;	
	obj->precheck = srv_sync_phone_precheck;
	
	obj->close = srv_sync_phone_destroy;
	obj->abort = srv_sync_phone_abort;
	obj->start = srv_sync_phone_start;
	
	obj->get_selected_database = srv_sync_phone_get_selected_db;

		obj->sync = SRV_SYNC_PHONE;
	obj->priv = OslMalloc(sizeof(srv_sync_phone_cntx));
	memset(obj->priv, 0, sizeof(srv_sync_phone_cntx));

	if (user_data != NULL)
	{
		obj->cm = (srv_sync_cm_type *)user_data;
		srv_sync_cm_bt_set_role(obj->cm, MMI_SYNCML_DEV_ROLE_B);
	}
	else
	{
		// device A accnt is Added by MMI
		nvram_ef_syncml_device_accnt_struct *accnt;
		
		accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_phone_read_accnt(accnt_index);		

		obj->cm = srv_sync_cm_bt_create(&accnt->dev_bt_addr);
			srv_sync_cm_bt_set_role(obj->cm, MMI_SYNCML_DEV_ROLE_A);
		
			if (!srv_sync_cm_connect(obj->cm))
			{
				srv_sync_destroy(obj);
				
				return NULL;
			}
	}
	
		obj->active_accnt = accnt_index;
	}
	
	return obj;
}

