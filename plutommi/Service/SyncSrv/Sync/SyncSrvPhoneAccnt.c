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
 * SyncSrvPhoneAccnt.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Sync service management.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Header files
*****************************************************************************/
#include "MMI_features.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_rp_srv_sync_def.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "SyncSrvGprot.h"

#include "SyncSrvAccnt.h"
#include "SyncSrvPhoneSync.h"
#include "SyncSrvPhoneAccnt.h"

/*****************************************************************************
 * Header files
 *****************************************************************************/

/*****************************************************************************
* Typedef 
*****************************************************************************/
typedef nvram_ef_syncml_device_accnt_struct srv_sync_phone_accnt_type;
typedef Ret (*srv_sync_visist_funcptr)(void *data, void* usr_data);

typedef struct{
	srv_sync_phone_accnt_type *recent_accnt;
	U32 last_anchor[MAX_SYNCML_DEV_NUM][MAX_SYNCML_DATABASE_NUM];
	U8 recent_index;
}srv_sync_phone_accnt_cntx;

/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static srv_sync_phone_accnt_cntx g_srv_sync_phone_cntx;
static srv_sync_phone_accnt_type g_srv_sync_phone_accnt;

void srv_sync_phone_accnt_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;
	U8 i;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (g_srv_sync_phone_cntx.recent_accnt != NULL)
	{
		return;
	}
	
	g_srv_sync_phone_cntx.recent_accnt = &g_srv_sync_phone_accnt;
	g_srv_sync_phone_cntx.recent_index = 0xFF;

	for (i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
		accnt = (srv_sync_phone_accnt_type *)srv_sync_phone_read_accnt(i);

		if (accnt->timestamp != 0)
		{		
			memcpy(g_srv_sync_phone_cntx.last_anchor[i], 
				   accnt->last_database_anchor, 
				   sizeof(U32) * MAX_SYNCML_DATABASE_NUM);
		}
	}

}

void *srv_sync_phone_read_accnt(U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;
	S16 sError;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(accnt_index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL, NULL);

	SRV_SYNC_LOG2(MMI_SRV_SYNC_PHONE_ACCNT_READ, accnt_index, g_srv_sync_phone_cntx.recent_index);
	
	accnt = g_srv_sync_phone_cntx.recent_accnt;

	if (g_srv_sync_phone_cntx.recent_index != accnt_index)
	{
		ReadRecord(NVRAM_EF_SYNCML_DEV_ACCOUNT_LID, 
				   accnt_index + 1, 
				   accnt, 
				   NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE, 
				   &sError);
		
		g_srv_sync_phone_cntx.recent_index = accnt_index;
	}

	return accnt;
}


void srv_sync_phone_write_accnt(const void *data, U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;
	S16 sError;
	srv_sync_accnt_op_evt_struct op_evt;
	srv_sync_accnt_op_enum operation;
	U32 prev_timestamp;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(data != NULL && accnt_index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL);

	SRV_SYNC_LOG2(MMI_SRV_SYNC_PHONE_ACCNT_WRITE, accnt_index, g_srv_sync_phone_cntx.recent_index);
	accnt = (srv_sync_phone_accnt_type *)srv_sync_phone_read_accnt(accnt_index);
	prev_timestamp = accnt->timestamp;

	memcpy(g_srv_sync_phone_cntx.recent_accnt, data, NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE);

	WriteRecord(NVRAM_EF_SYNCML_DEV_ACCOUNT_LID, 
			   accnt_index + 1, 
			   (void *)data, 
			   NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE, 
			   &sError);

	// update cached data
	accnt = g_srv_sync_phone_cntx.recent_accnt;
	
	memcpy(g_srv_sync_phone_cntx.last_anchor[accnt_index], 
		   accnt->last_database_anchor, 
		   sizeof(U32) * MAX_SYNCML_DATABASE_NUM);

	g_srv_sync_phone_cntx.recent_index = accnt_index;

	if (accnt->timestamp == 0)
	{
		operation = SRV_SYNC_ACCNT_OP_DEL;
	}
	else
	{
		if (prev_timestamp == 0)
		{
			operation = SRV_SYNC_ACCNT_OP_ADD;	
		}
		else
		{
			operation = SRV_SYNC_ACCNT_OP_MODIFY;
		}
	}
	
	MMI_FRM_INIT_EVENT(&op_evt, EVT_ID_SRV_SYNC_ACCNT_OP);
	op_evt.index = accnt_index;
	op_evt.operation = operation;
	op_evt.clear = MMI_TRUE;
	op_evt.sync = SRV_SYNC_PHONE;
	
	MMI_FRM_CB_EMIT_POST_EVENT(&op_evt);
}

S32 srv_sync_phone_accnt_new_index(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;
	S32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
		accnt = (srv_sync_phone_accnt_type *)srv_sync_phone_read_accnt(i);
		if (accnt->timestamp == 0)
		{
			break;
		}
	}

	return ((i == MAX_SYNCML_DEV_NUM) ? -1 : i);

}

S32 srv_sync_phone_accnt_foreach(srv_sync_visist_funcptr visit, void *usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;
	S32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < MAX_SYNCML_DEV_NUM; i++)
	{
		accnt = (srv_sync_phone_accnt_type *)srv_sync_phone_read_accnt(i);
		if (visit(accnt, usr_data) == RET_STOP)
		{
			break;
		}
	}

	return ((i == MAX_SYNCML_DEV_NUM) ? -1 : i);
}

MMI_BOOL srv_sync_phone_read_accnt_buffer(void *buffer, U32 size, U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S16 sError;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(accnt_index < NVRAM_EF_SYNCML_DEV_ACCOUNT_TOTAL, MMI_FALSE);
	RETURN_VAL_IF_FAIL(buffer != NULL, MMI_FALSE);
	RETURN_VAL_IF_FAIL(size == NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE, MMI_FALSE);

	ReadRecord(NVRAM_EF_SYNCML_DEV_ACCOUNT_LID, 
			   accnt_index + 1, 
			   buffer, 
			   NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE, 
			   &sError);

	return MMI_TRUE;
}

U32 srv_sync_phone_accnt_anchor(U8 accnt_index, U8 db_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 anchor;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(accnt_index < NVRAM_EF_SYNCML_DEV_ACCOUNT_TOTAL, 0);

	anchor = g_srv_sync_phone_cntx.last_anchor[accnt_index][db_id];

	SRV_SYNC_LOG3(MMI_SRV_SYNC_PHONE_ACCNT_ANCHOR,accnt_index, db_id, anchor);
	
	return anchor;
}

#define INTERFACE
static void *srv_sync_accnt_phone_read(srv_sync_accnt_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);

	return srv_sync_phone_read_accnt(obj->accnt_index);
}

static void srv_sync_accnt_phone_write(srv_sync_accnt_type *obj, const void *data)
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
	srv_sync_phone_write_accnt(data, obj->accnt_index);	
}
	else
	{
		srv_sync_phone_accnt_type *accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);	
		srv_sync_phone_write_accnt(accnt, obj->accnt_index);
	}

}

static U32 srv_sync_accnt_phone_get_anchor(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, 0);

	accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);

	return accnt->last_database_anchor[database_id];
}

static void srv_sync_accnt_phone_set_anchor(srv_sync_accnt_type *obj, const U32 database_id, const U32 anchor)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);

	accnt->last_database_anchor[database_id] = anchor;
}

static U8 *srv_sync_accnt_phone_db_uri(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);
	
	accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);

	return accnt->database_address[database_id];
}

static void srv_sync_accnt_phone_set_db_uri(srv_sync_accnt_type *obj, const U32 database_id, const U8* buffer, const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);

	if (buffer != accnt->database_address[database_id])
	{
		memcpy(accnt->database_address[database_id], buffer, len);
	}
}


static U8 *srv_sync_accnt_phone_remote_anchor(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);
	
	accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);

	return accnt->database_remote_anchor[database_id];
}

static void srv_sync_accnt_phone_set_remote_anchor(srv_sync_accnt_type *obj, const U32 database_id, const U8* buffer, const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);

	if (buffer != accnt->database_remote_anchor[database_id])
	{
		memcpy(accnt->database_remote_anchor[database_id], buffer, len);
	}
}

static U8 *srv_sync_accnt_phone_db_addr(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);

	accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);
	
	return accnt->database_address[database_id];
}

static void srv_sync_accnt_phone_set_db_addr(srv_sync_accnt_type *obj, const U32 database_id, const U8* buffer, const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);

	if (buffer != accnt->database_address[database_id])
	{
		memcpy(accnt->database_address[database_id], buffer, len);
	}
}

static U32 srv_sync_accnt_phone_selected_db(srv_sync_accnt_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_phone_accnt_type *accnt;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, 0);
	
	accnt = GET_OBJ_PRIV(srv_sync_phone_accnt_type, obj);
	
	return accnt->app_to_sync;
}


static void srv_sync_accnt_phone_destroy(srv_sync_accnt_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (obj != NULL)
	{
		OslMfree(obj);
		obj = NULL;
	}
}

srv_sync_accnt_type * srv_sync_accnt_phone_create(const U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_accnt_type *obj;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	obj = (srv_sync_accnt_type *)OslMalloc(sizeof(srv_sync_accnt_type));

	if (obj != NULL)
	{
		memset(obj, 0, sizeof(srv_sync_accnt_type));
		
		obj->read  = srv_sync_accnt_phone_read;
		obj->write = srv_sync_accnt_phone_write;

		obj->db_uri = srv_sync_accnt_phone_db_uri;
		obj->remote_anchor = srv_sync_accnt_phone_remote_anchor;
		obj->selected_db = srv_sync_accnt_phone_selected_db;
		obj->anchor = srv_sync_accnt_phone_get_anchor;
		obj->db_addr = srv_sync_accnt_phone_db_addr;
		
		obj->set_db_uri = srv_sync_accnt_phone_set_db_uri;
		obj->set_remote_anchor = srv_sync_accnt_phone_set_remote_anchor;
		obj->set_anchor = srv_sync_accnt_phone_set_anchor;
		obj->set_db_addr = srv_sync_accnt_phone_set_db_addr;		
		
		obj->destory = srv_sync_accnt_phone_destroy;
		
		obj->priv = srv_sync_phone_read_accnt(accnt_index);
		obj->accnt_index = accnt_index;
		obj->sync = SRV_SYNC_PHONE;
	}

	return obj;
}


