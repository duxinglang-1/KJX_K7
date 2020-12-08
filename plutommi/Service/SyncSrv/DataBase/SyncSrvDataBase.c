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
 * SyncSrvDatabase.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Sync service database interface abstract
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
#include "syncml_common_customize.h"
#include "mmi_rp_srv_sync_def.h"

#include "SyncSrvChangelog.h"
#include "SyncSrvDataBase.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/

/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
/*****************************************************************************
 * Interface
 *****************************************************************************/
MMI_BOOL srv_sync_database_is_ready(srv_sync_database_type *obj)
{
	RETURN_VAL_IF_FAIL(obj != NULL, KAL_FALSE);

	return obj->is_ready(obj);
}

MMI_BOOL srv_sync_database_match(srv_sync_database_type *obj, U32 type)
{
	RETURN_VAL_IF_FAIL(obj != NULL, KAL_FALSE);

	return obj->match(obj, type);
}

U32 srv_sync_database_get_type(srv_sync_database_type *obj)
{
	RETURN_VAL_IF_FAIL(obj != NULL, 0xFF);

	return obj->db_info.db_type;
}

void srv_sync_database_destroy(srv_sync_database_type *obj)
{
	if (obj != NULL && obj->destroy != NULL)
	{
		obj->destroy(obj);
	}
}

void srv_sync_database_lock(srv_sync_database_type *obj)
{
	RETURN_IF_FAIL(obj != NULL);

	obj->lock(obj);
}

void srv_sync_database_unlock(srv_sync_database_type *obj)

{
	RETURN_IF_FAIL(obj != NULL);

	obj->unlock(obj);
}

void srv_sync_database_on_query_luid_list(srv_sync_database_type *obj, srv_sync_request_struct *req)
{
	RETURN_IF_FAIL(obj != NULL &&  req != NULL);

	obj->on_query_luid_list(obj, req);
}

void srv_sync_database_on_clean_luid_list(srv_sync_database_type *obj, srv_sync_request_struct *req)
{
	RETURN_IF_FAIL(obj != NULL &&  req != NULL);

	obj->on_clean_luid_list(obj, req);
}

void srv_sync_database_on_set_record(srv_sync_database_type *obj, srv_sync_request_struct *req)
{
	RETURN_IF_FAIL(obj != NULL &&  req != NULL);

	obj->on_set_record(obj, req);
}

void srv_sync_database_on_get_record(srv_sync_database_type *obj, srv_sync_request_struct *req)
{
	RETURN_IF_FAIL(obj != NULL &&  req != NULL);

	obj->on_get_record(obj, req);
}

void srv_sync_database_on_progress(srv_sync_database_type *obj, void *msg)
{
	RETURN_IF_FAIL(obj != NULL &&  msg != NULL);

	obj->on_progress(obj, msg);
}

void srv_sync_database_on_start(srv_sync_database_type *obj, srv_sync_enum sync, U8 accnt_index, void *msg)
{
	RETURN_IF_FAIL(obj != NULL &&  msg != NULL);
	
	obj->on_start(obj, sync, accnt_index, msg);
}

void srv_sync_database_on_finish(srv_sync_database_type *obj, void *msg)
{
	RETURN_IF_FAIL(obj != NULL &&  msg != NULL);

	obj->on_finish(obj, msg);
}

void srv_sync_database_attatch_accnt(srv_sync_database_type *obj, srv_sync_accnt_type *accnt)
{
	RETURN_IF_FAIL(obj != NULL &&  accnt != NULL);

	obj->accatch_accnt(obj, accnt);
}

const srv_sync_db_info_type *srv_sync_database_db_info(srv_sync_database_type *obj)
{
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);

	return &(obj->db_info);
}

/*****************************************************************************
 * Helper function
 *****************************************************************************/
void srv_sync_database_update_stat(
				srv_sync_database_type *obj, 
				U16 result, 
				srv_sync_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sync_request_struct *req = (srv_sync_request_struct *)obj->priv;
	srv_sync_db_info_type *db_info = &(obj->db_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(srv_sync_is_db_synchronizing(db_info->db_type));
	RETURN_IF_FAIL(obj != NULL);
	
	/* SET */
	if (action == SRV_SYNC_ACTION_RECV)
	{
    if (result == SYNCML_OK)
    {
    	if (req->more_data == 0)
    	{
    		db_info->ok_cnt[req->operation - SYNCML_RECORD_ADD]++;
    	}
    }
		/* for the not-find item, don't */
	else if (result != SYNCML_NOT_FOUND)
	{
		db_info->fail_cnt++;
	}

		
    	if (req->more_data == 0)
    	{
    		db_info->curr_recv++;
		}
	}
	/* GET */
	else
	{
		db_info->curr_send++;
	}
}


void srv_sync_database_progress_notify(srv_sync_database_type *obj, srv_sync_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
	srv_sync_progress_evt_struct progress_evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					*/
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	MMI_FRM_INIT_EVENT(&progress_evt, EVT_ID_SRV_SYNC_PROGRESS);
	progress_evt.db_id = obj->db_info.id;
	progress_evt.action = action;
	
	switch (action)
	{
		case SRV_SYNC_ACTION_RECV:
		{
			progress_evt.curr = obj->db_info.curr_recv;
			progress_evt.total = obj->db_info.recv_noc;
			
			break;
		}
		
		case SRV_SYNC_ACTION_SEND:
		{
			progress_evt.curr = obj->db_info.curr_send;
			progress_evt.total = obj->db_info.send_noc;
			break;
		}
		
		default:
			MMI_ASSERT(!"Wrong action!");
			break;
	}
	
	MMI_FRM_CB_EMIT_POST_EVENT(&progress_evt);
}


U16 srv_sync_database_query_clog(const srv_sync_database_type *obj, U16 *luid_buf, U8 operation)
{
	srv_sync_changelog_type *changelog = srv_sync_changelog_create(obj->db_info.id);
	
	WCHAR *path = srv_sync_changelog_create_filename(
						changelog,
						srv_sync_accnt_sync(obj->accnt), 
						srv_sync_accnt_index(obj->accnt));
	
	U16 count = srv_sync_changelog_query(path, operation, luid_buf);
	srv_sync_changelog_close_filename(changelog, path);
	
	srv_sync_changelog_destroy(changelog);

	return count;
}

