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
 * SyncSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Sync manager implemented in this file manage about sync object as follow, all of these obj has abstraced interface,
 *	in its header file. its easy to add a new type of such object.
 *	any type of 
 *	Sync:
 * 		remote sync, phone sync
 *	SyncDatabase: 
 *		cont, cal, task, note
 *	SyncChangeLog: change log
 *	SyncCM:	connection manager
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
#include "app_datetime.h"
#include "syncml_common_customize.h"
#include "custom_mmi_default_value.h"

#include "mmi_rp_srv_sync_def.h"

#include "SyncSrvGprot.h"

#include "SyncSrv.h"
#include "SyncSrvChangelog.h"
#include "SyncSrvDataBaseCfg.h"
#include "SyncSrvSync.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/
typedef struct{
	srv_sync_database_type *database[SYNCML_DB_ID_TOTAL];
	srv_sync_type *sync;
	srv_sync_accnt_type *accnt;
	U32 active_db;
	U32 active_accnt;
	U32 total_db;
	U16 last_error;
	srv_sync_state_enum state;
}srv_sync_mgr_cntx;

/*****************************************************************************
* define
*****************************************************************************/

/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static srv_sync_mgr_cntx g_srv_sync_cntx;

/*****************************************************************************
* FUNCTION
*   srv_sync_reset_cntx
* DESCRIPTION
*	rest sync context
* PARAMETERS
*	void
* RETURNS
*   void
*****************************************************************************/
void srv_sync_reset_cntx(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_RESET_CNTX);
	
	g_srv_sync_cntx.total_db = 0;
	g_srv_sync_cntx.sync = NULL;
	g_srv_sync_cntx.accnt = NULL;
	g_srv_sync_cntx.active_db = 0;
	g_srv_sync_cntx.active_accnt = 0xFF;

	srv_sync_set_state(SRV_SYNC_STATE_IDLE);
}


/*****************************************************************************
* FUNCTION
*   srv_sync_destroy_all_database
* DESCRIPTION
*	void
* PARAMETERS
*	void
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_destroy_all_database(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	for (i = 0; i < g_srv_sync_cntx.total_db; i++)
	{
		srv_sync_database_destroy(g_srv_sync_cntx.database[i]);
		g_srv_sync_cntx.database[i] = NULL;
	}
	
	g_srv_sync_cntx.total_db = 0;
}


/*****************************************************************************
* FUNCTION
*   srv_sync_check_database_callback
* DESCRIPTION
*	check every database
* PARAMETERS
*	data
*	usr_data
* RETURNS
*   void
*****************************************************************************/
static U32 srv_sync_check_database_callback(void *data, void *usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_database_cfg_item_type *item;
	srv_sync_database_type *obj;
	srv_sync_mgr_cntx *cntx;
		
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(data != NULL && usr_data != NULL, RET_STOP);
	
	item = (srv_sync_database_cfg_item_type*)data;
	cntx = (srv_sync_mgr_cntx *)usr_data;
	
	if (item->type & cntx->active_db)
	{
		obj = item->create();
		if (!srv_sync_database_is_ready(obj))
		{
			srv_sync_database_destroy(obj);
			return RET_STOP;
		}
	
		srv_sync_database_attatch_accnt(obj, cntx->accnt);
		
		cntx->database[cntx->total_db] = obj;
		cntx->total_db++;
	}

	return RET_OK;
}


/*****************************************************************************
 * Please refer to SyncSrvGprot.h
 *****************************************************************************/
srv_sync_ret_enum srv_sync_start(srv_sync_enum sync, U8 accnt_index, U32 database, void *usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_ret_enum ret = SRV_SYNC_RET_OK;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG3(MMI_SYNC_SRV_START, sync, accnt_index, database);
	
	RETURN_VAL_IF_FAIL(sync < SRV_SYNC_TOTAL, SRV_SYNC_RET_ERROR_INVALID_SYNC);
	RETURN_VAL_IF_FAIL(srv_sync_is_state(SRV_SYNC_STATE_IDLE), SRV_SYNC_RET_ERROR_BUSY);
	RETURN_VAL_IF_FAIL(accnt_index < MAX_SYNCML_SV_PROFILES, SRV_SYNC_RET_ERROR_INVALID_ACCNT);
		
	g_srv_sync_cntx.sync = srv_sync_create(sync, accnt_index, usr_data);
	RETURN_VAL_IF_FAIL(g_srv_sync_cntx.sync != NULL, SRV_SYNC_RET_FAIL);
	
	srv_sync_set_state(SRV_SYNC_STATE_START);

	g_srv_sync_cntx.accnt =  srv_sync_accnt_create(sync, accnt_index);
	MMI_ASSERT(g_srv_sync_cntx.accnt != NULL);

	/* database is from account */
	if (database == 0)
	{		
		g_srv_sync_cntx.active_db = srv_sync_get_selected_db(g_srv_sync_cntx.sync);
	}
	/* user defined database  */
	else
	{
		g_srv_sync_cntx.active_db = database;
	}
	
	if (g_srv_sync_cntx.active_db != 0)
	{		
		U32 index = srv_sync_database_foreach(srv_sync_check_database_callback, &g_srv_sync_cntx);
		
		if (index == srv_sync_get_database_count())
		{	
			if ((ret = srv_sync_precheck(g_srv_sync_cntx.sync)) == SRV_SYNC_RET_OK)
			{				
				srv_sync_get_imei_req();			
			}
		}
		else
		{
			ret = SRV_SYNC_RET_ERROR_DB_NOT_READY;
		}
	}
	else
	{
		ret = SRV_SYNC_RET_ERROR_NO_SELECTED_DB;
	}	

	if (ret != SRV_SYNC_RET_OK)
	{
		srv_sync_deinit();
	}
	
	SRV_SYNC_LOG1(MMI_SYNC_SRV_START_RET, ret);
	
	return ret;
}


/*****************************************************************************
* FUNCTION
*   srv_sync_reset_database
* DESCRIPTION
*	For device B, database is not know at start sync state. so need to reset database at some time.
* PARAMETERS
*	db_mask		:[IN]	database type
* RETURNS
*   void
*****************************************************************************/
void srv_sync_reset_database(U32 db_mask)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 db_type;
	U32 i = 0, j;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	do
	{
		SRV_SYNC_LOG2(MMI_SYNC_RESET_DB, db_mask, i);
		
		db_type = srv_sync_database_get_type(g_srv_sync_cntx.database[i]);

		/*
		  * pre-selected database is in finial-determined database
		  */
		if (db_type & db_mask)
		{		
			i++;
			continue;
		}
		
		/*
		  * pre-selected database is not in finial-determined database, 
		  *	then delete this database.
		  */

		srv_sync_database_destroy(g_srv_sync_cntx.database[i]);
		
		for (j = i; j < (g_srv_sync_cntx.total_db - 1); j++)
		{
			g_srv_sync_cntx.database[j] = g_srv_sync_cntx.database[j + 1];
		}
		
		g_srv_sync_cntx.database[g_srv_sync_cntx.total_db - 1] = NULL;
		g_srv_sync_cntx.total_db--;

		/* clear the current db mask. */
		g_srv_sync_cntx.active_db &= ~db_type;

	}while(i < g_srv_sync_cntx.total_db);
	
}

/*****************************************************************************
* FUNCTION
*   srv_sync_database_type
* DESCRIPTION
*	Find database obj who has this database type
* PARAMETERS
*	database_type	:[IN]	database type
* RETURNS
*   void
*****************************************************************************/
srv_sync_database_type *srv_sync_find_database(const U32 database_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < g_srv_sync_cntx.total_db; i++)
	{
		if (srv_sync_database_match(g_srv_sync_cntx.database[i], database_type))
		{			
			break;
		}
	}

	if (i < g_srv_sync_cntx.total_db)
	{
		return g_srv_sync_cntx.database[i]; 
	}

	return NULL;
}

srv_sync_database_type *srv_sync_get_database(const U32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	return g_srv_sync_cntx.database[index];
}

U32 srv_sync_get_total_database(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_TOTAL_DB, g_srv_sync_cntx.total_db);
	
	return g_srv_sync_cntx.total_db;
}


/*****************************************************************************
 * Please refer to BootupSrvGprot.h
 *****************************************************************************/
srv_sync_ret_enum srv_sync_abort(srv_sync_enum sync)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_ABORT, sync);
	
	RETURN_VAL_IF_FAIL(g_srv_sync_cntx.sync != NULL, SRV_SYNC_RET_ERROR_INVALID_SYNC);

	if (srv_sync_is_state(SRV_SYNC_STATE_SYNCING))
	{
		srv_sync_abort_sync(g_srv_sync_cntx.sync);
		
		srv_sync_set_state(SRV_SYNC_STATE_ABORTING);
	}
	else if (!srv_sync_is_state(SRV_SYNC_STATE_ABORTING))
	{
		srv_sync_deinit();
		// clean all cntx.
		srv_sync_set_state(SRV_SYNC_STATE_IDLE);
	}
	
	return SRV_SYNC_RET_OK;
}


MMI_BOOL srv_sync_is_state(srv_sync_state_enum state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG2(MMI_SYNC_SRV_IS_STATE, state, g_srv_sync_cntx.state);
	
	return (MMI_BOOL)(g_srv_sync_cntx.state == state);
}

void srv_sync_set_state(srv_sync_state_enum state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_SET_STATE, state);
	
	g_srv_sync_cntx.state = state;
}

U32 srv_sync_foreach_database(srv_sync_visist_funcptr visit, void* usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < g_srv_sync_cntx.active_accnt; i++)
	{
		if (visit(g_srv_sync_cntx.database[i], usr_data) == RET_STOP)
		{
			break;
		}
	}

	return i;
}


/*****************************************************************************
 * Please refer to SyncSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_sync_is_db_synchronizing(U32 database)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_FALSE;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (!srv_sync_is_state(SRV_SYNC_STATE_IDLE) && (g_srv_sync_cntx.active_db & database))
	{
		ret = MMI_TRUE;
	}
	
	SRV_SYNC_LOG3(MMI_SYNC_SRV_IS_SYNC, database, ret, g_srv_sync_cntx.active_db);
	
	return ret;
}

MMI_BOOL srv_sync_is_synchronizing(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	return (MMI_BOOL)(!srv_sync_is_state(SRV_SYNC_STATE_IDLE));
}

MMI_BOOL srv_sync_active_sync_info(srv_sync_enum *sync, U8 *index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL((sync != NULL && index != NULL), MMI_FALSE);
	
	if(g_srv_sync_cntx.state >= SRV_SYNC_STATE_START)
	{
		*sync = srv_sync_active_type(srv_sync_active_sync());
		*index = srv_sync_accnt_index(srv_sync_active_accnt());

		return MMI_TRUE;
	}
	
	return MMI_FALSE;
}

/*****************************************************************************
 * Please refer to BootupSrvGprot.h
 *****************************************************************************/
U16 srv_sync_get_last_error(srv_sync_ret_enum error_no)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	return g_srv_sync_cntx.last_error;
}

void srv_sync_set_last_error(const U16 error_str)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	g_srv_sync_cntx.last_error = error_str;
}

srv_sync_type *srv_sync_active_sync(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	return g_srv_sync_cntx.sync;
}

srv_sync_accnt_type *srv_sync_active_accnt(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	return g_srv_sync_cntx.accnt;
}

/*****************************************************************************
 * FUNCTION
 *	srv_sync_get_current_time
 * DESCRIPTION
 *	get current time.
 * PARAMETERS
 *	void
 * RETURNS
 *	U32
 *****************************************************************************/
U32 srv_sync_get_current_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&t);
	
    return (U32)applib_dt_mytime_2_utc_sec(&t, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_clear_changelog_callback
 * DESCRIPTION
 *  Cear all change log callback
 * PARAMETERS
 *  data		:[IN]	data
 *  usr_data	:[IN]	data
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_sync_clear_changelog_callback(void *data, void *usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_database_cfg_item_type *item = (srv_sync_database_cfg_item_type *)data;
	srv_sync_changelog_type *changelog;
	WCHAR *path;
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_ASSERT(item != NULL);
	
	changelog = srv_sync_changelog_create(item->id);

	for (i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		path = srv_sync_changelog_create_filename(
						changelog,
						SRV_SYNC_REMOTE, 
						i);
	
		srv_sync_changelog_clearall(path);
		srv_sync_changelog_close_filename(changelog, path);
	}

	srv_sync_changelog_destroy(changelog);

	return RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_clear_all_changelog
 * DESCRIPTION
 *  Cear all change log
 * PARAMETERS
 *  evt	:[IN]	event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_sync_clear_all_changelog(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	srv_sync_database_foreach(srv_sync_clear_changelog_callback, NULL);
	
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_init
 * DESCRIPTION
 *  Answer
 * PARAMETERS
 *  evt	:[IN]	event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id srv_sync_init(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	SRV_SYNC_LOG0(MMI_SYNC_SRV_INIT);
	
	srv_sync_msg_init();
	srv_sync_accnt_init();
	srv_sync_reset_cntx();
	srv_sync_sync_init();

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_deinit
 * DESCRIPTION
 *  Deinit sync service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sync_deinit(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_DEINIT);
	
	srv_sync_destroy_all_database();
	srv_sync_destroy(g_srv_sync_cntx.sync);
	srv_sync_accnt_destroy(g_srv_sync_cntx.accnt);

	srv_sync_reset_cntx();
}

