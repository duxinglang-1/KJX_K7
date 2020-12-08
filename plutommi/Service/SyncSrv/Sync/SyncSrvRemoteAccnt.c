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
 * SyncSrvRemoteAccnt.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Remote account object implement file, To speed up the read and write action
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include "MMIDataType.h"

#include "app_datetime.h"

#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "mmi_rp_srv_sync_def.h"
#include "mmi_rp_srv_dtcnt_def.h"

#include "DtcntSrvGprot.h"
#include "SyncSrvGprot.h"

#include "SyncSrvAccnt.h"
#include "SyncSrvRemoteAccnt.h"
#include "SyncSrvDatabaseCfg.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Typedef 
 *****************************************************************************/
typedef nvram_ef_syncml_account_struct srv_sync_remote_accnt_type;

typedef struct{
	srv_sync_remote_accnt_type *recent_accnt;
    U32 last_anchor[NVRAM_EF_SYNCML_ACCOUNT_TOTAL][MAX_SYNCML_DATABASE_NUM];
	U8 recent_index;
}srv_sync_remote_accnt_cntx;

/*****************************************************************************
* Local Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static srv_sync_remote_accnt_cntx g_srv_sync_remote_cntx;
static srv_sync_remote_accnt_type g_srv_sync_remote_accnt;

/*****************************************************************************
* Local Function 
*****************************************************************************/
static U32 srv_sync_remote_clear_clog_callback(void *data, void *usr_data);

void srv_sync_remote_accnt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;
    U8 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_ACCNT_INIT);
	
	if (g_srv_sync_remote_cntx.recent_accnt != NULL)
	{
		return;
	}
	
	g_srv_sync_remote_cntx.recent_accnt = &g_srv_sync_remote_accnt;
	g_srv_sync_remote_cntx.recent_index = 0xFF;

	for (i = 0; i < NVRAM_EF_SYNCML_ACCOUNT_TOTAL; i++)
	{
		accnt = (srv_sync_remote_accnt_type *)srv_sync_remote_read_accnt(i);

		if (accnt->timestamp != 0)
		{
			memcpy(g_srv_sync_remote_cntx.last_anchor[i], 
				   accnt->last_database_anchor, 
				   sizeof(U32) * MAX_SYNCML_DATABASE_NUM);

			srv_sync_remote_set_regular_info(i, accnt);
		}

        srv_sync_remote_set_netid_info(i, accnt);
	}
}

void* srv_sync_remote_read_accnt(U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;
	S16 sError;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(accnt_index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL, NULL);

	SRV_SYNC_LOG2(MMI_SYNC_SRV_RMT_ACCNT_READ, accnt_index, g_srv_sync_remote_cntx.recent_index);

	accnt = g_srv_sync_remote_cntx.recent_accnt;
	if (g_srv_sync_remote_cntx.recent_index != accnt_index)
	{
		ReadRecord(NVRAM_EF_SYNCML_ACCOUNT_LID, 
				   accnt_index + 1, 
				   accnt, 
				   NVRAM_EF_SYNCML_ACCOUNT_SIZE, 
				   &sError);
		
		g_srv_sync_remote_cntx.recent_index = accnt_index;
	}

	return accnt;
}


MMI_BOOL srv_sync_remote_read_accnt_buffer(void *buffer, U32 size, U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S16 sError;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(accnt_index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL, MMI_FALSE);
	RETURN_VAL_IF_FAIL(buffer != NULL, MMI_FALSE);
	RETURN_VAL_IF_FAIL(size == NVRAM_EF_SYNCML_ACCOUNT_SIZE, MMI_FALSE);

	SRV_SYNC_LOG2(MMI_SYNC_SRV_RMT_ACCNT_READ, accnt_index, accnt_index);

	ReadRecord(NVRAM_EF_SYNCML_ACCOUNT_LID, 
			   accnt_index + 1, 
			   buffer, 
			   NVRAM_EF_SYNCML_ACCOUNT_SIZE, 
			   &sError);

	return MMI_TRUE;
}

U16 srv_sync_remote_accnt_operation(const srv_sync_remote_accnt_type *old_accnt, 
											  const srv_sync_remote_accnt_type *new_accnt)
{
	U16 operation;
	
	RETURN_VAL_IF_FAIL(new_accnt != NULL && old_accnt != NULL, SRV_SYNC_ACCNT_OP_TOTAL);
	
	if (new_accnt->timestamp == 0)
	{
		operation = SRV_SYNC_ACCNT_OP_DEL;
	}
	else
	{
		if (old_accnt->timestamp == 0)
		{
			operation = SRV_SYNC_ACCNT_OP_ADD;
		}
		else
		{
			operation = SRV_SYNC_ACCNT_OP_MODIFY;
		}
	}

	return operation;
}

static void srv_sync_accnt_remote_clear_vlog(U8 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	nvram_ef_syncml_view_log_struct *vLog;
	S16 errCode;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL);
	
	vLog = (nvram_ef_syncml_view_log_struct *)OslMalloc(NVRAM_EF_SYNCML_VIEW_LOG_SIZE);

	memset(vLog, 0, NVRAM_EF_SYNCML_VIEW_LOG_SIZE);

	WriteRecord(NVRAM_EF_SYNCML_VIEW_LOG_LID, 
			   (index + 1), 
			   vLog, 
			   NVRAM_EF_SYNCML_VIEW_LOG_SIZE, 
			   &errCode);
	
	OslMfree(vLog);
}

void srv_sync_remote_write_accnt(const void *data, U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt, *new_accnt, *old_accnt;
	S16 sError;
	MMI_BOOL clear_flag = MMI_FALSE;
	
	srv_sync_accnt_op_evt_struct op_evt;
	U16 operation = SRV_SYNC_ACCNT_OP_ADD;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(data != NULL && accnt_index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL);

	SRV_SYNC_LOG2(MMI_SYNC_SRV_RMT_ACCNT_WRITE, accnt_index, g_srv_sync_remote_cntx.recent_index);
	
	new_accnt = (srv_sync_remote_accnt_type *)data;
	
	if (data != g_srv_sync_remote_cntx.recent_accnt)
	{
		old_accnt = g_srv_sync_remote_cntx.recent_accnt;
		
		/* server address has changed */
		if (strcmp((const char *)new_accnt->server_address, (const char *)old_accnt->server_address) != 0)
		{
			clear_flag = MMI_TRUE;
		}
		
		memcpy(g_srv_sync_remote_cntx.recent_accnt, data, NVRAM_EF_SYNCML_ACCOUNT_SIZE);

		operation = srv_sync_remote_accnt_operation(old_accnt, new_accnt);
	}
	else
	{
		old_accnt = (srv_sync_remote_accnt_type *)OslMalloc(sizeof(srv_sync_remote_accnt_type));
		
		srv_sync_remote_read_accnt_buffer(old_accnt, NVRAM_EF_SYNCML_ACCOUNT_SIZE, accnt_index);

		if (strcmp((const char *)old_accnt->server_address, (const char *)new_accnt->server_address) != 0)
		{
			clear_flag = MMI_TRUE;
		}
		
		operation = srv_sync_remote_accnt_operation(old_accnt, new_accnt);

		OslMfree(old_accnt);
		old_accnt = NULL;
	}
	
	new_accnt->regular_sync_notify = 0;
	
	WriteRecord(NVRAM_EF_SYNCML_ACCOUNT_LID, 
			   accnt_index + 1, 
			   (void *)data, 
			   NVRAM_EF_SYNCML_ACCOUNT_SIZE, 
			   &sError);

	g_srv_sync_remote_cntx.recent_index = accnt_index;

	/* update cached data */
	accnt = g_srv_sync_remote_cntx.recent_accnt;
	memcpy(g_srv_sync_remote_cntx.last_anchor[accnt_index], 
		   accnt->last_database_anchor, 
		   sizeof(U32) * MAX_SYNCML_DATABASE_NUM);
    
	srv_sync_remote_set_regular_info(accnt_index, new_accnt);

	/* set regular sync. */
	if (accnt->regular_sync >= SRV_SYNC_REGULAR_EVERY_DAY &&
		accnt->regular_sync <= SRV_SYNC_REGULAR_EVERY_MONTH)
	{
		srv_sync_remote_regular_set_reminder(accnt_index);
	}

    /* set net_id buffer */
    srv_sync_remote_set_netid_info(accnt_index, new_accnt);
    
	/* clear the change log, if the server address has changed. */
	if (clear_flag)
	{
		srv_sync_database_foreach(srv_sync_remote_clear_clog_callback, (void *)accnt_index);
	}

	/* clear view log */
	if (clear_flag || (operation == SRV_SYNC_ACCNT_OP_DEL))
	{
	srv_sync_accnt_remote_clear_vlog(accnt_index);
	}
	
	/* notify about the account change*/
	MMI_FRM_INIT_EVENT(&op_evt, EVT_ID_SRV_SYNC_ACCNT_OP);
	op_evt.index = accnt_index;
	op_evt.operation = operation;
	op_evt.clear = clear_flag;
	op_evt.sync = SRV_SYNC_REMOTE;
	
	MMI_FRM_CB_EMIT_POST_EVENT(&op_evt);

}

static U32 srv_sync_remote_clear_clog_callback(void *data, void *usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_database_cfg_item_type *item = (srv_sync_database_cfg_item_type *)data;
	srv_sync_changelog_type *changelog;
	WCHAR *path;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_ASSERT(item != NULL);
	
	changelog = srv_sync_changelog_create(item->id);

	path = srv_sync_changelog_create_filename(
					changelog,
					SRV_SYNC_REMOTE, 
					(U8)(0xFF & (U32)usr_data));

	srv_sync_changelog_clearall(path);
	srv_sync_changelog_close_filename(changelog, path);

	srv_sync_changelog_destroy(changelog);

	return RET_OK;
}

S32 srv_sync_remote_accnt_new_index(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;
	S32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i <NVRAM_EF_SYNCML_ACCOUNT_TOTAL; i++)
	{
		accnt = (srv_sync_remote_accnt_type *)srv_sync_remote_read_accnt(i);
		if (accnt->timestamp == 0)
		{
			break;
		}
	}

	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_ACCNT_NEW_IDX, i);
	
	return ((i == NVRAM_EF_SYNCML_ACCOUNT_TOTAL) ? -1 : i);
}

U32 srv_sync_remote_accnt_anchor(U8 accnt_index, U8 db_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 anchor;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(accnt_index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL, 0);

	anchor = g_srv_sync_remote_cntx.last_anchor[accnt_index][db_id];

	SRV_SYNC_LOG3(MMI_SYNC_SRV_RMT_ACCNT_ANCHOR, accnt_index, db_id, anchor);

	return anchor;
}


#define INTERFACE
static void *srv_sync_accnt_remote_read(srv_sync_accnt_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);

	return srv_sync_remote_read_accnt(obj->accnt_index);
}

static void srv_sync_accnt_remote_write(srv_sync_accnt_type *obj, const void *data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	if (data != NULL)
	{
		srv_sync_remote_write_accnt(data, obj->accnt_index);	
	}
	else
	{
		srv_sync_remote_accnt_type *accnt;
		
		accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);
		srv_sync_remote_write_accnt(accnt, obj->accnt_index);
	}
}

static U32 srv_sync_accnt_remote_get_anchor(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, 0xFF);

	accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);

	return accnt->last_database_anchor[database_id];
}

static U8 *srv_sync_accnt_remote_db_addr(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);

	accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);
	
	return accnt->database_address[database_id];
}

static void srv_sync_accnt_remote_set_db_addr(srv_sync_accnt_type *obj, const U32 database_id, const U8* buffer, const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);

	if (buffer != accnt->database_address[database_id])
	{
		memcpy(accnt->database_address[database_id], buffer, len);
	}
}


static U8 *srv_sync_accnt_remote_db_usrname(srv_sync_accnt_type *obj, const U32 database_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);
	
	accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);
	
	return accnt->database_username[database_type];

}

static void srv_sync_accnt_remote_set_db_usrname(srv_sync_accnt_type *obj,
											const U32 database_id, 
											const U8* buffer, 
											const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && buffer != NULL);

	accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);

	if (buffer != accnt->database_username[database_id])
	{
		memcpy(accnt->database_username[database_id], buffer, len);
	}	
}


static U8 *srv_sync_accnt_remote_db_pwd(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);

	accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);
	
	return accnt->database_password[database_id];
}

static void srv_sync_accnt_remote_set_db_pwd(srv_sync_accnt_type *obj, 
										const U32 database_id, 
										const U8* buffer, 
										const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);
	
	accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);
	
	if (buffer != accnt->database_password[database_id])
	{
		memcpy(accnt->database_password[database_id], buffer, len);
	}

}

static void srv_sync_accnt_remote_set_anchor(srv_sync_accnt_type *obj, const U32 database_id, const U32 anchor)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);

	accnt->last_database_anchor[database_id] = anchor;
}


static U32 srv_sync_accnt_remote_selected_db(srv_sync_accnt_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, 0);
	
	accnt = GET_OBJ_PRIV(srv_sync_remote_accnt_type, obj);
	
	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_ACCNT_DEL_DB, accnt->app_to_sync);
	
	return accnt->app_to_sync;
}


static void srv_sync_accnt_remote_destroy(srv_sync_accnt_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_ACCNT_DESTROY);
	if (obj != NULL)
	{
		OslMfree(obj);
		obj = NULL;
	}
}


srv_sync_accnt_type * srv_sync_accnt_remote_create(const U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_accnt_type *obj;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	obj = (srv_sync_accnt_type *)OslMalloc(sizeof(srv_sync_accnt_type));

	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_ACCNT_CREATE, accnt_index);
	
	if (obj != NULL)
	{
		memset(obj, 0, sizeof(srv_sync_accnt_type));
		
		obj->read  = srv_sync_accnt_remote_read;
		obj->write = srv_sync_accnt_remote_write;

		obj->db_uri = NULL;
		obj->remote_anchor = NULL; // only the role of server has this field
		obj->selected_db = srv_sync_accnt_remote_selected_db;
		obj->anchor = srv_sync_accnt_remote_get_anchor;
		
		obj->db_addr = srv_sync_accnt_remote_db_addr;
		obj->db_usrname = srv_sync_accnt_remote_db_usrname;
		obj->db_pwd = srv_sync_accnt_remote_db_pwd;
		
		obj->set_anchor = srv_sync_accnt_remote_set_anchor;
		obj->set_db_addr = srv_sync_accnt_remote_set_db_addr;
		obj->set_db_usrname = srv_sync_accnt_remote_set_db_usrname;
		obj->set_db_pwd = srv_sync_accnt_remote_set_db_pwd;
		
		obj->destory = srv_sync_accnt_remote_destroy;

		/* cached accnt. */
		obj->priv = srv_sync_remote_read_accnt(accnt_index);
		obj->accnt_index = accnt_index;
		obj->sync = SRV_SYNC_REMOTE;
	}

	return obj;
}

