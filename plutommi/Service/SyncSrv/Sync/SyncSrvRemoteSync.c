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
 * SyncSrvRemoteSync.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements remote sync related part
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
#include "cbm_api.h"
#include "cbm_consts.h"
#include "Wap_adp.h"
#include "DtCntSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "mmi2syncml_struct.h"
#include "SimCtrlSrvGprot.h"
#include "common_nvram_editor_data_item.h"

#include "mmi_rp_srv_sync_def.h"

#include "SyncSrvSync.h"
#include "SyncSrvRemoteSync.h"
#include "SyncSrvRemoteAccnt.h"

#include "SyncSrvDatabase.h"
#include "SyncSrvCmCbm.h"
#include "SyncSrvCm.h"

/*****************************************************************************
* Define
*****************************************************************************/
#define SRV_SYNC_REMOTE_DEFAULT_PORT 9201

typedef enum
{
	SRV_SYNC_REMOTE_STATE_INITED,
	SRV_SYNC_REMOTE_STATE_CHECKING_CONN,
	SRV_SYNC_REMOTE_STATE_SYNCHING,
	SRV_SYNC_REMOTE_STATE_TOTAL
}srv_sync_remote_state_enum;

/*****************************************************************************
* Typedef 
*****************************************************************************/
typedef struct
{
	srv_sync_remote_state_enum sub_state;
	U8 *imei;
}srv_sync_remote_priv_struct;
typedef nvram_ef_syncml_account_struct srv_sync_remote_accnt_type;

/*****************************************************************************
* Global Variables 
*****************************************************************************/

static srv_sync_remote_priv_struct g_srv_rmt_sync_cntx;

/*****************************************************************************
* Local Variables 
*****************************************************************************/

void srv_sync_remote_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_SYNC_INIT);
	srv_sync_cm_cbm_init();
}

static srv_sync_ret_enum srv_sync_remote_precheck(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	//srv_sync_remote_accnt_type *accnt;
	srv_sync_ret_enum ret = SRV_SYNC_RET_OK;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, SRV_SYNC_RET_FAIL);
	
	//accnt = (srv_sync_remote_accnt_type *)srv_sync_remote_read_accnt(obj->active_accnt);
	(srv_sync_remote_accnt_type *)srv_sync_remote_read_accnt(obj->active_accnt);

	/* BT sync needn't check the following condition */
	if (!wap_is_ready() || 
#ifndef __MMI_WLAN_FEATURES__
		!srv_sim_ctrl_any_sim_is_available() ||
#endif
		 MMI_FALSE)
	{
		ret = SRV_SYNC_RET_ERROR_WAP_NOT_READY;
	}	

	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_SYNC_PRECHECK, ret);

	return ret;
}


void srv_sync_remote_start(srv_sync_type *obj, const U8 *imei)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_start_sync_req_struct *local_para;

	srv_dtcnt_prof_proxy_info_struct *proxy_info;
	srv_sync_remote_accnt_type *accnt;
		
	srv_sync_remote_priv_struct *cntx;
	srv_sync_database_type *database;
	srv_dtcnt_sim_type_enum sim_id;
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && imei != NULL);   
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_SYNC_START);

	accnt = srv_sync_remote_read_accnt(obj->active_accnt);
	
	local_para = OslAllocDataPtr(mmi_syncml_start_sync_req_struct);

	strcpy((CHAR*) local_para->server_uri, (CHAR*)accnt->server_address);
	strcpy((CHAR*) local_para->server_username, (CHAR*)accnt->server_username);
	strcpy((CHAR*) local_para->server_password, (CHAR*)accnt->server_password);

	memcpy(&local_para->imei[0], "IMEI:", 5);
	memcpy(&local_para->imei[5], imei, 15);
	local_para->imei[20] = 0;
	
	local_para->sync_type = accnt->sync_type;

	cntx = GET_OBJ_PRIV(srv_sync_remote_priv_struct, obj);
	cntx->sub_state = SRV_SYNC_REMOTE_STATE_SYNCHING;

	local_para->app_id = srv_sync_remote_app_id();

	srv_dtcnt_get_sim_preference(&sim_id);
	if (sim_id == SRV_DTCNT_SIM_TYPE_NONE)
	{
		sim_id = SRV_DTCNT_SIM_TYPE_1;
	}
	
	local_para->net_id = accnt->net_id[sim_id - 1];


	proxy_info = (srv_dtcnt_prof_proxy_info_struct*)OslMalloc(sizeof(srv_dtcnt_prof_proxy_info_struct));
	
	if (srv_dtcnt_get_proxy_info(local_para->net_id, proxy_info, SRV_DTCNT_ACCOUNT_PRIMARY))
	{	
		switch(proxy_info->px_service)
		{
			case SRV_DTCNT_PROF_PX_SRV_CL_WSP:		 /* WSP, Connection less */
			case SRV_DTCNT_PROF_PX_SRV_CO_WSP:		 /* WSP, Connection oriented */
			case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP:	 /* WSP, Connection less, security mode */
			case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP:	 /* WSP, Connection oriented, security mode */
			case SRV_DTCNT_PROF_PX_SRV_CL_SEC_WTA:	 /* WTA, Connection less, security mode */
			case SRV_DTCNT_PROF_PX_SRV_CO_SEC_WTA:	 /* WTA, Connection oriented, security mode */
				local_para->transport_type = SYNCML_TRANS_WSP;
				break;
			default:
				local_para->transport_type = SYNCML_TRANS_HTTP;
				break;
		}		
	}
	else
	{
		SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_WRONG_PX);
		proxy_info->use_proxy = 0;
	}

	if (proxy_info->use_proxy != 0)
	{
		strncpy((CHAR*)local_para->proxy_server_ip, (CHAR*)proxy_info->px_addr, MAX_SYNCML_PROXY_ADDR);
		local_para->proxy_server_port = (local_para->transport_type == SYNCML_TRANS_HTTP) ? proxy_info->px_port : SRV_SYNC_REMOTE_DEFAULT_PORT;
		strncpy((CHAR*)local_para->proxy_username, (CHAR*)proxy_info->px_authid, MAX_SYNCML_PROXY_USERNAME);
		local_para->proxy_username[MAX_SYNCML_PROXY_USERNAME - 1] = 0;
		strncpy((CHAR*)local_para->proxy_password, (CHAR*)proxy_info->px_authpw, MAX_SYNCML_PROXY_PASSWORD);
		local_para->proxy_password[MAX_SYNCML_PROXY_PASSWORD - 1] = 0;
	}
	else
	{
		memset(local_para->proxy_server_ip, 0, MAX_SYNCML_PROXY_ADDR);
		local_para->proxy_server_port = 0;
		memset(local_para->proxy_username, 0, MAX_SYNCML_PROXY_USERNAME);
		memset(local_para->proxy_password, 0, MAX_SYNCML_PROXY_PASSWORD);
	}
	
	OslMfree(proxy_info);


	// only sync know about the start struct, and only database know about address info.
	// sync manager also shouldn't know about start struct
	// different kinds of sync may have different start struct
	for(i = 0; i < srv_sync_get_total_database(); i++)
	{
		database = srv_sync_get_database(i);
		srv_sync_database_on_start(database, SRV_SYNC_REMOTE, obj->active_accnt, local_para);
	}
	
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_START_SYNC_REQ, (oslParaType *)local_para, NULL);
}


static void srv_sync_remote_check_conn(srv_sync_type *obj, const U8 *imei)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_priv_struct *cntx;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	cntx = GET_OBJ_PRIV(srv_sync_remote_priv_struct, obj);
	cntx->sub_state = SRV_SYNC_REMOTE_STATE_CHECKING_CONN;
	
	if (!srv_sync_cm_connect(obj->cm))
	{
		srv_sync_dummy_finish();
	}
}

static mmi_ret srv_sync_remote_post_disconn (mmi_event_struct *param)
{
	srv_sync_type *obj = (srv_sync_type *)param->user_data;
	srv_sync_cm_disconnect(obj->cm);
	
	return MMI_RET_OK;
}

static void srv_sync_remote_abort(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_priv_struct *cntx;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);
	cntx = GET_OBJ_PRIV(srv_sync_remote_priv_struct, obj);
	
	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_SYNC_ABORT, cntx->sub_state);

	/* Only abort @Sync state, or waiting the connection result */
	if (cntx->sub_state == SRV_SYNC_REMOTE_STATE_SYNCHING)
	{
		srv_sync_send_abort_sync();
	}
	else
	{
		// post call to simulate msg flow
		mmi_event_struct evt;

		MMI_FRM_INIT_EVENT(&evt, 0);
		MMI_FRM_POST_EVENT(&evt, srv_sync_remote_post_disconn, obj);
	}
}

static U32 srv_sync_remote_get_selected_db(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, 0);

	accnt = srv_sync_remote_read_accnt(obj->active_accnt);

	MMI_ASSERT(accnt != NULL);

	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_SYNC_SEL_DB, accnt->app_to_sync);
	
	return accnt->app_to_sync;
}

static void srv_sync_remote_close(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_SYNC_DESTROY);
	
	if (obj != NULL)
	{
		if (obj->cm != NULL)
		{
			srv_sync_cm_destroy(obj->cm);			
			obj->cm = NULL;
		}
		
		OslMfree(obj);
		obj = NULL;
	}
}

static MMI_BOOL srv_sync_remote_match(srv_sync_type *obj, srv_sync_enum sync)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, MMI_FALSE);
	
	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_SYNC_MATCH, (obj->sync == sync));
	
	return (MMI_BOOL)(obj->sync == sync);
}

static MMI_BOOL srv_sync_remote_match_accnt(srv_sync_type *obj, U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, MMI_FALSE);
	
	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_SYNC_MATCH_ACCNT, (obj->active_accnt == accnt_index));
	return (MMI_BOOL)(obj->active_accnt == accnt_index);
}


static void srv_sync_remote_on_finish(srv_sync_type *obj, void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;
	mmi_syncml_finish_sync_ind_struct *finish_info;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	accnt = srv_sync_remote_read_accnt(obj->active_accnt);
	
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_SYNC_ON_FINISH);
	
	if (accnt != NULL)
	{
		const srv_sync_db_info_type *db_info;
		srv_sync_database_type *database;
		S16 err;
		U32 i;

		nvram_ef_syncml_view_log_struct *vlog = SYNC_MALLOC(nvram_ef_syncml_view_log_struct);
		memset(vlog, 0, sizeof(nvram_ef_syncml_view_log_struct));
	    finish_info = (mmi_syncml_finish_sync_ind_struct *)msg;
	    
	    vlog->sync_result = finish_info->result;
    
		vlog->last_sync_time = srv_sync_get_current_time();
		strncpy((CHAR *)vlog->last_sync_server, (CHAR *)accnt->server_address, MAX_SYNCML_SERVER_ADDR_LEN);
		
		vlog->app_to_sync = accnt->app_to_sync;
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
			vlog->clt_ng_cnt[db_info->id] =    db_info->fail_cnt;

			vlog->svr_ok_cnt[db_info->id][0] = db_info->srv_ok_cnt[0];
			vlog->svr_ok_cnt[db_info->id][1] = db_info->srv_ok_cnt[1];
			vlog->svr_ok_cnt[db_info->id][2] = db_info->srv_ok_cnt[2];
			vlog->svr_ng_cnt[db_info->id] =    db_info->srv_fail_cnt;
			
		}

		WriteRecord(NVRAM_EF_SYNCML_VIEW_LOG_LID,
					(obj->active_accnt + 1),
					vlog,
					NVRAM_EF_SYNCML_VIEW_LOG_SIZE,
					&err);

		SYNC_MFREE(vlog);

        if (accnt->regular_sync == SRV_SYNC_REGULAR_AT_DATA_CHANGE)
        {
            if (SYNCML_GET_SYNC_STATUS(finish_info->result) == SRV_SYNC_OK)
            {
                srv_sync_remote_unset_regular_notify(obj->active_accnt);
            }
        }
	}
}


/*****************************************************************************
* FUNCTION
*	srv_sync_remote_create
* DESCRIPTION
*	create database type
* PARAMETERS
*	type		:[IN]	database type
* RETURNS
*	srv_sync_database_type
*****************************************************************************/
srv_sync_type* srv_sync_remote_create(U8 accnt_index, void* user_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_type *obj;
	srv_sync_remote_accnt_type *accnt;
	srv_dtcnt_sim_type_enum sim_id;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_SYNC_CREATE);

	obj = (srv_sync_type *)OslMalloc(sizeof(srv_sync_type));
	
	memset(obj, 0, sizeof(srv_sync_type));
	
	obj->precheck = srv_sync_remote_precheck;
	obj->start = srv_sync_remote_check_conn;
	obj->close = srv_sync_remote_close;
	obj->abort = srv_sync_remote_abort;
	obj->match = srv_sync_remote_match;
	obj->match_accnt = srv_sync_remote_match_accnt;		
	obj->get_selected_database = srv_sync_remote_get_selected_db;
	obj->on_finish = srv_sync_remote_on_finish;
	
	obj->sync = SRV_SYNC_REMOTE;
	obj->active_accnt = accnt_index;
	obj->priv = &g_srv_rmt_sync_cntx;

	accnt = (srv_sync_remote_accnt_type *)srv_sync_remote_read_accnt(obj->active_accnt);
	srv_dtcnt_get_sim_preference(&sim_id);
	if (sim_id == SRV_DTCNT_SIM_TYPE_NONE)
	{
		sim_id = SRV_DTCNT_SIM_TYPE_1;
	}

	// The app id of the default account may be invalid.
	if (cbm_get_app_id(accnt->net_id[sim_id - 1]) != srv_sync_remote_app_id())
	{
		U32 i = 0;
		for (; i < MAX_SIM_NUM; i++)
		{
			accnt->net_id[i] = cbm_encode_data_account_id(
												cbm_get_original_account(accnt->net_id[i]),
												(cbm_sim_id_enum)(CBM_SIM_ID_SIM1 + i),
												srv_sync_remote_app_id(),
												KAL_FALSE);
		}

		srv_sync_remote_write_accnt(accnt, accnt_index);
	}
	
	obj->cm = srv_sync_cm_cbm_create((void *)accnt->net_id[sim_id - 1]);
	
	return obj;
}

