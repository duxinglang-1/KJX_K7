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
 * SyncSrvDatabasenote.c
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
#include "app_mine.h"
#include "syncml_common_customize.h"
#include "mmi2syncml_struct.h"

#include "mmi_rp_srv_prof_def.h"
#include "AlarmSrvGprot.h"
#include "ReminderSrvGprot.h"

#include "SyncSrv.h"
#include "SyncSrvDatabase.h"

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
* FUNCTION
*   srv_sync_database_note_match
* DESCRIPTION
*	create database type
* PARAMETERS
*	type		:[IN]	database type
* RETURNS
*   srv_sync_database_type
*****************************************************************************/
static MMI_BOOL srv_sync_database_note_match(srv_sync_database_type *obj, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	RETURN_VAL_IF_FAIL(obj != NULL, KAL_FALSE);

	return (type == SYNCML_DB_NOTE);
}

/*****************************************************************************
* FUNCTION
* 	srv_sync_database_note_is_ready
* DESCRIPTION
*	test database ready status
* PARAMETERS
*	type		:[IN]	database type
* RETURNS
*   srv_sync_database_type
*****************************************************************************/
static MMI_BOOL srv_sync_database_note_is_ready(srv_sync_database_type *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	
	return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
* 	srv_sync_database_contact_lock
* DESCRIPTION
*	test database ready status
* PARAMETERS
*	type		:[IN]	database type
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_database_note_lock(srv_sync_database_type *obj)
{
	RETURN_IF_FAIL(obj != NULL);
}


/*****************************************************************************
* FUNCTION
* 	srv_sync_database_contact_unlock
* DESCRIPTION
*	test database ready status
* PARAMETERS
*	type		:[IN]	database type
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_database_note_unlock(srv_sync_database_type *obj)
{
	RETURN_IF_FAIL(obj != NULL);

}

/*****************************************************************************
 * FUNCTION
 * 	srv_sync_database_note_attatch_accnt
 * DESCRIPTION
 *	test database ready status
 * PARAMETERS
 *	type		:[IN]	database type
 * RETURNS
 *   void
 *****************************************************************************/
static void srv_sync_database_note_attatch_accnt(srv_sync_database_type *obj, srv_sync_accnt_type *accnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && accnt!= NULL);

}


/*****************************************************************************
* FUNCTION
*   srv_sync_database_note_on_start
* DESCRIPTION
*	create database type
* PARAMETERS
*	obj		:[IN]	database object
*	msg		:[IN]	message
* RETURNS
*   void
*****************************************************************************/
void srv_sync_database_note_on_start(srv_sync_database_type *obj, srv_sync_enum sync, U8 accnt_index, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_start_sync_req_struct *start_req;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	RETURN_IF_FAIL(obj != NULL &&  msg != NULL);
	start_req = (mmi_syncml_start_sync_req_struct *)msg;

    strcpy((CHAR*)start_req->note_database_uri, 	  obj->db_info.address);
    strcpy((CHAR*)start_req->note_database_username, obj->db_info.username);
    strcpy((CHAR*)start_req->note_database_password, obj->db_info.password);

    if(obj->db_info.mime_type != NULL)
    {
        strcpy((CHAR*)start_req->note_mime_type, obj->db_info.mime_type);
    }
	
    start_req->note_last_anchor = obj->db_info.last_anchor;
    start_req->note_next_anchor = obj->db_info.next_anchor;

    start_req->note_free_id = obj->db_info.free_id;
    start_req->note_free_mem = obj->db_info.free_mem;
	
}

/*****************************************************************************
* FUNCTION
*   srv_sync_database_note_on_query_luid_list
* DESCRIPTION
*	create database type
* PARAMETERS
*	obj		:[IN]	database object
*	msg		:[IN]	message
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_database_note_on_query_luid_list(srv_sync_database_type *obj, void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	RETURN_IF_FAIL(obj != NULL &&  msg != NULL);

}


/*****************************************************************************
* FUNCTION
*   srv_sync_database_note_on_clean_luid_list
* DESCRIPTION
*	create database type
* PARAMETERS
*	obj		:[IN]	database object
*	msg		:[IN]	message
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_database_note_on_clean_luid_list(srv_sync_database_type *obj, void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL &&  msg != NULL);

}


/*****************************************************************************
* FUNCTION
*   srv_sync_database_on_set_record
* DESCRIPTION
*	create database type
* PARAMETERS
*	obj		:[IN]	database object
*	msg		:[IN]	message
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_database_note_on_set_record(srv_sync_database_type *obj, void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL &&  msg != NULL);

}


/*****************************************************************************
* FUNCTION
*   srv_sync_database_on_get_record
* DESCRIPTION
*	create database type
* PARAMETERS
*	obj		:[IN]	database object
*	msg		:[IN]	message
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_database_note_on_get_record(srv_sync_database_type *obj, void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	RETURN_IF_FAIL(obj != NULL &&  msg != NULL);

}

static void srv_sync_database_note_on_progress(srv_sync_database_type *obj, void *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_progress_info_ind_struct *progress_info;
	srv_sync_db_info_type *db_info;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && req != NULL);
	progress_info = (mmi_syncml_progress_info_ind_struct *)req;
	db_info = &obj->db_info;
	
	/*	get numberofchanges and sending progress info*/
	switch (progress_info->progress_info)
	{
		case PROGRESS_NOTE_LOCAL_NOC:
			db_info->send_noc = progress_info->numberofchange;
			break;
			

		case PROGRESS_NOTE_REMOTE_NOC:
			db_info->recv_noc = progress_info->numberofchange;
			break;

		case PROGRESS_NOTE_DATASTORE_FAILED:
			db_info->fail = MMI_TRUE;
			break;

        case PROGRESS_NOTE_DATASTORE_SENDING:
			srv_sync_database_progress_notify(obj, SRV_SYNC_ACTION_SEND);
            break;
			
        case PROGRESS_NOTE_DATASTORE_RECEIVED:			
            srv_sync_database_progress_notify(obj, SRV_SYNC_ACTION_RECV);
            break;

		default:
			break;
			
	}

}

/*****************************************************************************
* FUNCTION
*   srv_sync_database_note_on_finish
* DESCRIPTION
*	create database type
* PARAMETERS
*	obj		:[IN]	database object
*	msg		:[IN]	message
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_database_note_on_finish(srv_sync_database_type *obj, void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_finish_sync_ind_struct *finish_ind;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL &&  msg != NULL);

	finish_ind = (mmi_syncml_finish_sync_ind_struct *)msg;

	if (SYNCML_GET_SYNC_STATUS(finish_ind->result) == SYNCML_OK && !obj->db_info.fail)
	{
		srv_sync_accnt_set_anchor(obj->accnt, SYNCML_DB_ID_NOTE, obj->db_info.next_anchor);
		
#ifdef __SYNCML_DEVICE_SYNC__
		/* is device sync*/
		if (finish_ind->f_is_device)
		{
			srv_sync_accnt_set_db_uri(
				obj->accnt, 
				SYNCML_DB_ID_CAL,
				(const U8 *)finish_ind->d2d_info.note_database_uri,
				MAX_SYNCML_DATABASE_ADDR_LEN);

			srv_sync_accnt_set_remote_anchor(
				obj->accnt,
				SYNCML_DB_ID_CAL,
				(const U8 *)finish_ind->d2d_info.note_remote_anchor,
				MAX_SYNCML_REMOTE_ANCHOR_SIZE);
		}
#endif /* __SYNCML_DEVICE_SYNC__ */

	}
	
	obj->db_info.srv_ok_cnt[0] = finish_ind->svr_note_ok_cnt[0];
	obj->db_info.srv_ok_cnt[1] = finish_ind->svr_note_ok_cnt[1];
	obj->db_info.srv_ok_cnt[2] = finish_ind->svr_note_ok_cnt[2];
	obj->db_info.srv_fail_cnt  = finish_ind->svr_note_ng_cnt;


}

/*****************************************************************************
* FUNCTION
*   srv_sync_database_destroy
* DESCRIPTION
*	create database type
* PARAMETERS
*	obj		:[IN]	database object
* RETURNS
*   void
*****************************************************************************/
static void srv_sync_database_note_destroy(srv_sync_database_type *obj)
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

srv_sync_database_type *srv_sync_database_note_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sync_database_type *obj = (srv_sync_database_type *)OslMalloc(sizeof(srv_sync_database_type));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (obj != NULL)
	{
		memset(obj, 0, sizeof(srv_sync_database_type));
		
		obj->on_query_luid_list = srv_sync_database_note_on_query_luid_list;
		obj->on_clean_luid_list = srv_sync_database_note_on_clean_luid_list;
		obj->on_set_record 		= srv_sync_database_note_on_set_record;
		obj->on_get_record 		= srv_sync_database_note_on_get_record;
		obj->on_finish 			= srv_sync_database_note_on_finish;
		obj->on_start 			= srv_sync_database_note_on_start;
		obj->on_progress		= srv_sync_database_note_on_progress;
	
		obj->match 	  =	srv_sync_database_note_match;
		obj->destroy  = srv_sync_database_note_destroy;
		obj->is_ready = srv_sync_database_note_is_ready;
		obj->lock 	  =	srv_sync_database_note_lock;
		obj->unlock   =	srv_sync_database_note_unlock;

		obj->accatch_accnt = srv_sync_database_note_attatch_accnt;

		obj->db_info.id = SYNCML_DB_ID_NOTE;
		obj->db_info.db_type = SYNCML_DB_NOTE;

	}
	
	return obj;

}

