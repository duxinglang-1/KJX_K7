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
 * SyncSrvMsg.c
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
#include "Mmi_frm_queue_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "mmi_msg_struct.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include "mmi2syncml_struct.h"
#include "syncml_common_customize.h"

#include "mmi_rp_srv_sync_def.h"

#include "FileMgrSrvGProt.h"
#include "SyncSrvGprot.h"
#include "Unicodexdcl.h"

#include "SyncSrv.h"
#include "SyncSrvSync.h"
#include "SyncSrvDataBaseCfg.h"
#include "SyncSrvDatabase.h"
#include "SyncSrvChangelog.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/
#if defined(DEBUG_KAL)
#define __SYNCML_KEEP_TEMP_FILE__
#endif

/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static	srv_sync_request_struct g_sync_req;

/*****************************************************************************
 * Local Function
 *****************************************************************************/
#ifdef __SYNCML_KEEP_TEMP_FILE__
static void srv_sync_get_filepath(WCHAR *filePath)
{
	FS_HANDLE fh;

	kal_wsprintf(filePath, "%c:\\Received\\", SRV_FMGR_PUBLIC_DRV);

    fh = FS_Open(filePath, FS_OPEN_DIR | FS_READ_ONLY);

    // Folder Exists 
    if (fh > 0)
    {
        FS_Close(fh);
    }
	else
	{
    	FS_CreateDir(filePath);
	}

	kal_wsprintf(filePath, "%c:\\Received\\syncvobj.tmp", SRV_FMGR_PUBLIC_DRV);
	
    FS_Delete(filePath);
}


static void srv_sync_dup_temp_file(void)
{
	WCHAR *filePath;
	//FS_HANDLE fh;
    filePath = OslMalloc(((SRV_FMGR_PATH_MAX_LEN + 1) * 2));

	srv_sync_get_filepath(filePath);
	
	srv_fmgr_fs_copy(SYNCML_VOBJ_PATH, filePath);

	OslMfree(filePath);
}


static void srv_sync_save_temp_data(const void *buffer, U32 len)
{
	WCHAR *filePath;
	FS_HANDLE fh;
	U32 wLen;
	
    filePath = OslMalloc(((SRV_FMGR_PATH_MAX_LEN + 1) * 2));

	srv_sync_get_filepath(filePath);
	
	fh = FS_Open(filePath, FS_CREATE | FS_READ_WRITE);
	FS_Seek(fh, 0, FS_FILE_END);
	
    FS_Write(fh, (void *)buffer, len, &wLen);

	FS_SetAttributes(filePath, FS_ATTR_HIDDEN);
	FS_Close(fh);
    
    OslMfree(filePath);
}
#endif /*__SYNCML_KEEP_TEMP_FILE__ */


static void srv_sync_set_record_req(void *info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_database_type *database;
	mmi_syncml_set_record_req_ind_struct *record_req = (mmi_syncml_set_record_req_ind_struct*) info;
	srv_sync_request_struct *sync_req = &g_sync_req;
	U32 written_length;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_SET_RECORD_REQ);
	
	RETURN_IF_FAIL(srv_sync_is_synchronizing());

	sync_req->luid = (record_req->operation_type != SYNCML_RECORD_ADD) ? record_req->luid : 0xFFFF;
	sync_req->operation = record_req->operation_type;
	sync_req->database 	= record_req->database_type;
	sync_req->more_data = record_req->more_data;
	sync_req->charset = record_req->charset;
//	sync_req->parent_luid = record_req->parent_luid;

	/* move and delete hasn't data. */
	if (record_req->operation_type != SYNCML_RECORD_DELETE &&
		record_req->operation_type != SYNCML_RECORD_MOVE)
	{
		FS_HANDLE fp = FS_Open(SYNCML_VOBJ_PATH, FS_CREATE | FS_READ_WRITE);
		FS_Seek(fp, 0, FS_FILE_END);

		if (record_req->data != NULL)
		{
		   FS_Write(fp, (void*) record_req->data, record_req->data_length, &written_length);
		}
		
		FS_Close(fp);

#ifdef __SYNCML_KEEP_TEMP_FILE__
        srv_sync_save_temp_data(record_req->data, record_req->data_length);
#endif /* __SYNCML_KEEP_TEMP_FILE__ */

	}

	if (record_req->more_data != 0)
	{
		sync_req->result = SYNCML_OK;
		srv_sync_set_record_rsp(sync_req);
		
		return;
	}

	/* notify target database. */
	database = srv_sync_find_database(record_req->database_type);
	MMI_ASSERT(database != NULL);
	
	srv_sync_database_on_set_record(database, sync_req);
}


void srv_sync_set_record_rsp(srv_sync_request_struct *sync_req)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_set_record_res_req_struct *local_para;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_SET_RECORD_RSP);
	
    local_para = OslAllocDataPtr(mmi_syncml_set_record_res_req_struct);
    local_para->result = sync_req->result;
    local_para->luid = sync_req->luid;
    local_para->mmi_oprt = sync_req->operation;
	
	mmi_frm_send_ilm(MOD_SYNCML, 
					 MSG_ID_MMI_SYNCML_SET_RECORD_RES_REQ, 
					 (oslParaType *)local_para,
					 NULL);
}


static void srv_sync_get_record_req(void *info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_get_record_req_ind_struct *get_req = (mmi_syncml_get_record_req_ind_struct*) info;
	srv_sync_request_struct *sync_req = &g_sync_req;
	srv_sync_database_type *database;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_GET_RECORD_REQ);
	
	sync_req->luid		  = get_req->luid;
	sync_req->operation   = get_req->operation_type;
	sync_req->database	  = get_req->database_type;

	/* notify target database. */
	database = srv_sync_find_database(get_req->database_type);
	MMI_ASSERT(database != NULL);

	/* if get deletion or move, only to reponse directly without geting data actually. */
	if (get_req->operation_type == SYNCML_RECORD_GET_DEL_NOTIFY ||
		get_req->operation_type == SYNCML_RECORD_GET_MOVE_NOTIFY)
	{
		sync_req->result = SYNCML_OK;
		
		srv_sync_get_record_rsp(sync_req);
		srv_sync_database_update_stat(database, SYNCML_OK, SRV_SYNC_ACTION_SEND);
		srv_sync_database_progress_notify(database, SRV_SYNC_ACTION_SEND);
		return;
	}

	srv_sync_database_on_get_record(database, sync_req);

}


void srv_sync_get_record_rsp(srv_sync_request_struct *req)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_get_record_res_req_struct *local_para;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(req != NULL && srv_sync_is_synchronizing());
	SRV_SYNC_LOG0(MMI_SYNC_SRV_GET_RECORD_RSP);

	local_para = OslAllocDataPtr(mmi_syncml_get_record_res_req_struct);
	local_para->result = req->result;

	if (req->operation != SYNCML_RECORD_GET_DEL_NOTIFY &&
		req->operation != SYNCML_RECORD_GET_MOVE_NOTIFY)

	{
		mmi_ucs2cpy((CHAR*)local_para->file_path, (const CHAR*)SYNCML_VOBJ_PATH);

		#ifdef __SYNCML_KEEP_TEMP_FILE__
		srv_sync_dup_temp_file();
		#endif
	}

	mmi_frm_send_ilm(MOD_SYNCML, 
					 MSG_ID_MMI_SYNCML_GET_RECORD_RES_REQ, 
					 (oslParaType *)local_para, 
					 NULL);
}


static void srv_sync_query_luid_list_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_query_luid_list_req_ind_struct *list_req = (mmi_syncml_query_luid_list_req_ind_struct*)info;
	srv_sync_request_struct *sync_req = &g_sync_req;
	srv_sync_database_type *database;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_QUERY_LUID_REQ);
	
	sync_req->operation = list_req->operation_type;
	sync_req->database = list_req->database_type;
	sync_req->luid_buf = list_req->luid_buf;

	database = srv_sync_find_database(list_req->database_type);
	MMI_ASSERT(database != NULL);
	
	srv_sync_on_query(srv_sync_active_sync());
	
	srv_sync_database_on_query_luid_list(database, sync_req);

}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_query_luid_list_rsp
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sync_query_luid_list_rsp(srv_sync_request_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_query_luid_list_res_req_struct *local_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_QUERY_LUID_RSP);
	
    local_para = OslAllocDataPtr(mmi_syncml_query_luid_list_res_req_struct);
    local_para->luid = req->luid_buf;
    local_para->count = req->count;
//    local_para->parent_luid = req->parent_luid_buf;

    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNC_SRV_QUERY_LOG, req->operation, req->count);

	mmi_frm_send_ilm(MOD_SYNCML, 
					 MSG_ID_MMI_SYNCML_QUERY_LUID_LIST_RES_REQ, 
					 (oslParaType *)local_para, 
					 NULL);
}


void sync_srv_clean_luid_list_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_clean_luid_list_res_req_struct *local_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_CLEAN_LUID_RSP);
    local_para = OslAllocDataPtr(mmi_syncml_clean_luid_list_res_req_struct);
    local_para->result = SYNCML_OK;
	
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_CLEAN_LUID_LIST_RES_REQ, (oslParaType *)local_para, NULL);
}


static void srv_sync_clean_luid_list_req(void *info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_clean_luid_list_req_ind_struct *clean_req = (mmi_syncml_clean_luid_list_req_ind_struct*) info;
	srv_sync_request_struct *sync_req = &g_sync_req;
	srv_sync_database_type *database;
	srv_sync_changelog_type *changelog;
	WCHAR *path;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_CLEAN_LUID_REQ);
	
	RETURN_IF_FAIL(srv_sync_is_synchronizing());

	sync_req->operation = clean_req->operation_type;
	sync_req->database = clean_req->database_type;

	database = srv_sync_find_database(clean_req->database_type);
	MMI_ASSERT(database != NULL);

	srv_sync_database_on_clean_luid_list(database, sync_req);

	/* clear change log*/
	changelog = srv_sync_changelog_create(database->db_info.id);
	path = srv_sync_changelog_create_filename(
						changelog,
						srv_sync_active_type(srv_sync_active_sync()), 
						srv_sync_accnt_index(srv_sync_active_accnt()));
	
	srv_sync_changelog_clearall(path);
	srv_sync_changelog_close_filename(changelog, path);
	
	srv_sync_changelog_destroy(changelog);

	sync_srv_clean_luid_list_rsp();

}


static Ret srv_sync_finish_callback(void *data, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_finish_sync_ind_struct *finish_info;
	srv_sync_database_type *database = (srv_sync_database_type *)data;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(data != NULL && usr_data != NULL, RET_STOP);
	
	srv_sync_database_on_finish((srv_sync_database_type *)data, usr_data);

	finish_info = (mmi_syncml_finish_sync_ind_struct *)usr_data;

	/* For we write change log when receiving data from server,
	* it need clear change log here to avoid log is remained after sync succeed.
	* ex, when in local no data change to send, change log can not be cleared automatically by protocol.
	*/

	if (SYNCML_GET_SYNC_STATUS(finish_info->result) == SYNCML_OK)
	{
		srv_sync_changelog_type *changelog;
		WCHAR *path = NULL;
		const srv_sync_db_info_type *dbinfo = srv_sync_database_db_info(database);
		
		changelog = srv_sync_changelog_create(dbinfo->id);
		path = srv_sync_changelog_create_filename(
							changelog,
							srv_sync_active_type(srv_sync_active_sync()), 
							srv_sync_accnt_index(srv_sync_active_accnt()));
		
		srv_sync_changelog_clearall(path);
		srv_sync_changelog_close_filename(changelog, path);
		
		srv_sync_changelog_destroy(changelog);
	}

	return RET_OK;
}


static void srv_sync_finish_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_syncml_finish_sync_ind_struct *finish_info;
	srv_sync_finish_evt_struct finish_evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_FINISH);
	
    /* delete in case of abnormal abort */
    FS_Delete(SYNCML_VOBJ_PATH);
	
	MMI_FRM_INIT_EVENT(&finish_evt, EVT_ID_SRV_SYNC_FINISH);
	
	srv_sync_foreach_database(srv_sync_finish_callback, info);
	srv_sync_on_finish(srv_sync_active_sync(), info);
	srv_sync_accnt_write(srv_sync_active_accnt(), NULL);
	
	finish_info = (mmi_syncml_finish_sync_ind_struct *)info;
	finish_evt.result = SYNCML_GET_SYNC_STATUS(finish_info->result);

	finish_evt.sync = srv_sync_active_type(srv_sync_active_sync());
	finish_evt.accnt_index = srv_sync_accnt_index(srv_sync_active_accnt());
	
	MMI_FRM_CB_EMIT_POST_EVENT(&finish_evt);

    /*
     * don't trigger regular sync during sync.
     */
    srv_sync_check_regular_sync();
    
	srv_sync_deinit();
}


static Ret srv_sync_prog_callback(void *data, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(data != NULL && usr_data != NULL, RET_STOP);
	
	srv_sync_database_on_progress((srv_sync_database_type *)data, usr_data);

	return RET_OK;
}


static void srv_sync_progress_info_ind(void *info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_syncml_progress_info_ind_struct *prog_info = (mmi_syncml_progress_info_ind_struct*)info;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_PROG, prog_info->progress_info);
	
	if (prog_info->progress_info <= PROGRESS_SESSION_DONE 
		&& prog_info->progress_info >= PROGRESS_LINK_ESTABLISHED)
	{
		return;
	}
	srv_sync_foreach_database(srv_sync_prog_callback, info);
}


void srv_sync_send_abort_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	SRV_SYNC_LOG0(MMI_SYNC_SRV_SEND_ABORT);
	
	mmi_frm_send_ilm(MOD_SYNCML, MSG_ID_MMI_SYNCML_ABORT_SYNC_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  sync_sync_get_imei_rsp
 * DESCRIPTION
 *  Protocol event handler
 * PARAMETERS
 *  info        [IN]            message content
 * RETURNS
 *  void
 *****************************************************************************/
static void sync_sync_get_imei_rsp(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_imei_rsp_struct *imei_rsp = (mmi_nw_get_imei_rsp_struct*)info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_GET_IMEI_RSP);
	
    ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);

	if (srv_sync_is_state(SRV_SYNC_STATE_START))
	{
	    if (imei_rsp->result == 1)
	    {
	    	srv_sync_set_state(SRV_SYNC_STATE_SYNCING);
			
	        srv_sync_start_sync(srv_sync_active_sync(), imei_rsp->imei);
	    }
	    
	    else
	    {
	        MMI_ASSERT(!"[SyncSrv] Get IMEI Fail");
	    }
	}
	else
	{
		// cm
	}
}



/*****************************************************************************
 * FUNCTION
 *  srv_sync_get_imei_req
 * DESCRIPTION
 *  Protocol event sender
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sync_get_imei_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_GET_IMEI_REQ);
	
	SetProtocolEventHandler(sync_sync_get_imei_rsp, MSG_ID_MMI_NW_GET_IMEI_RSP);
	
	mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_NW_GET_IMEI_REQ, NULL, NULL);
}


void srv_sync_dummy_finish(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    mmi_syncml_finish_sync_ind_struct *finish_info;

    /*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    finish_info = SYNC_MALLOC(mmi_syncml_finish_sync_ind_struct);
    memset(finish_info, 0, sizeof(finish_info));

    finish_info->result = SRV_SYNC_FAIL;

    srv_sync_finish_ind(finish_info);

    SYNC_MFREE(finish_info);
}


static void srv_sync_session_aborted_ind(void *param)
{
	SRV_SYNC_LOG0(MMI_SYNC_SRV_SESSION_ABORT);

    if (srv_sync_is_state(SRV_SYNC_STATE_SYNCING))
    {
        srv_sync_dummy_finish();
    }
}

static void srv_sync_ps_busy_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_PS_BUSY);
    
    if (srv_sync_is_state(SRV_SYNC_STATE_SYNCING))
    {
        srv_sync_dummy_finish();
    }
}

void srv_sync_msg_init(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_INIT_MSG);
	
	SetProtocolEventHandler(srv_sync_set_record_req, MSG_ID_MMI_SYNCML_SET_RECORD_REQ_IND);
	SetProtocolEventHandler(srv_sync_get_record_req, MSG_ID_MMI_SYNCML_GET_RECORD_REQ_IND);
	SetProtocolEventHandler(srv_sync_query_luid_list_req, MSG_ID_MMI_SYNCML_QUERY_LUID_LIST_REQ_IND);
	SetProtocolEventHandler(srv_sync_clean_luid_list_req, MSG_ID_MMI_SYNCML_CLEAN_LUID_LIST_REQ_IND);
	SetProtocolEventHandler(srv_sync_finish_ind, MSG_ID_MMI_SYNCML_FINISH_SYNC_IND);
	SetProtocolEventHandler(srv_sync_progress_info_ind, MSG_ID_MMI_SYNCML_PROGRESS_INFO_IND);
	SetProtocolEventHandler(srv_sync_ps_busy_ind_hdlr, MSG_ID_MMI_SYNCML_PS_BUSY_IND);
	SetProtocolEventHandler(srv_sync_session_aborted_ind, 	MSG_ID_MMI_SYNCML_SESSION_ABORTED_IND);
}

#ifdef __SYNCML_UT_MSG__
void srv_sync_msg_simulator(void *msg, U32 msg_id)
{
	switch (msg_id)
	{
		case MSG_ID_MMI_SYNCML_SET_RECORD_REQ_IND:
			srv_sync_set_record_req(msg);
			break;
			
		case MSG_ID_MMI_SYNCML_GET_RECORD_REQ_IND:
			srv_sync_get_record_req(msg);
			break;
			
		case MSG_ID_MMI_SYNCML_QUERY_LUID_LIST_REQ_IND:
			srv_sync_query_luid_list_req(msg);
			break;
			
		case MSG_ID_MMI_SYNCML_CLEAN_LUID_LIST_REQ_IND:
			srv_sync_clean_luid_list_req(msg);
			break;
			
		case MSG_ID_MMI_SYNCML_FINISH_SYNC_IND:
			srv_sync_finish_ind(msg);
			break;
			
		case MSG_ID_MMI_SYNCML_PROGRESS_INFO_IND:
			srv_sync_progress_info_ind(msg);
			break;
			
		case MSG_ID_MMI_SYNCML_PS_BUSY_IND:
			srv_sync_ps_busy_ind_hdlr(msg);
			break;
			
		default:
			break;

	}
}

#endif /* __SYNCML_UT_MSG__ */

