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
 * SyncSrvUT.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Its a msg simulator to do UT for sync service, it is triggered by Catcher 
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __SYNCML_UT_MSG__

#include "SyncSrvGprot.h"
#include "SyncSrv.h"
#include "mmi2syncml_struct.h"

/*****************************************************************************
* Header files
*****************************************************************************/

/*****************************************************************************
* Typedef 
*****************************************************************************/
typedef enum
{
	START_SYNC_REQ,
	QUERY_LUID_LIST_REQ_IND,
	SET_RECORD_REQ,
	PROGRESS_INFO_IND,
	GET_RECORD_REQ_IND,
	CLEAN_LUID_LIST_REQ_IND,	/* 5 */
	FINISH_SYNC_IND,			/* 6 */
	PS_BUSY_IND,				/* 7 */
	BT_ASK_ACCEPT_CONN_IND,		/* 8 */
	BT_CONNECTED_IND,			/* 9 */
	BT_DISCONNECTED_IND,		/* 10 */
	REMOTEINFO_IND,				/* 11 */
	SYNC_DB_IND_CONT,			/* 12 */
	SYNC_DB_IND_CAL,			/* 13 */
	SYNC_DB_IND_TASK,			/* 14 */
	SYNC_DB_IND_NOTE,			/* 15 */
	SYNC_ANSWER_ACCEPT,			/* 16 */
	SYNC_ANSWER_REJECT,			/* 17 */
	MSG_TOTAL
};

typedef struct
{

	U32 msg_id;
}srv_sync_ut_struct;

#define AllocSyncMsg(type) ((type *)OslMalloc(sizeof(type)))
#define SYNCML_VCARD_PATH     			L"D:\\We.vcf"
#define BUFFER_LEN 1024
/*****************************************************************************
* Global Variables 
*****************************************************************************/

static U16 g_srv_luid_buffer[256];
static U8 g_srv_sync_vcard_buffer[BUFFER_LEN];

extern void srv_sync_bt_msg_simulator(void *msg, U32 msg_id);

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static void *srv_sync_ut_malloc_set_msg(void)
{
	mmi_syncml_set_record_req_ind_struct *set_ind = AllocSyncMsg(mmi_syncml_set_record_req_ind_struct);
	FS_HANDLE fp;
	U32 length = 0;

	set_ind->database_type = SYNCML_DB_PHONEBOOK;
	set_ind->operation_type = SYNCML_RECORD_ADD;
	set_ind->luid = 0;
	set_ind->more_data = 0;
	set_ind->charset = 0;

	fp = FS_Open(SYNCML_VCARD_PATH, FS_READ_ONLY);

	if (fp > FS_NO_ERROR)
	{
		FS_Seek(fp, 0, FS_FILE_BEGIN);
		FS_Read(fp, g_srv_sync_vcard_buffer, BUFFER_LEN, &length);

		FS_Close(fp);
	}
	
	set_ind->data_length = length;
	set_ind->data = g_srv_sync_vcard_buffer;
	
	return set_ind;
}

static void *srv_sync_ut_malloc_get_msg(void)
{
	mmi_syncml_get_record_req_ind_struct *get_ind = AllocSyncMsg(mmi_syncml_get_record_req_ind_struct);

	get_ind->database_type = SYNCML_DB_PHONEBOOK;
	get_ind->luid = 0;
	get_ind->operation_type = SYNCML_RECORD_GET;

	return get_ind;
}

static void *srv_sync_ut_malloc_query_msg(void)
{
	mmi_syncml_query_luid_list_req_ind_struct *query_ind = AllocSyncMsg(mmi_syncml_query_luid_list_req_ind_struct);

	query_ind->database_type = SYNCML_DB_PHONEBOOK;
	query_ind->operation_type = 0;
	query_ind->luid_buf = g_srv_luid_buffer;

	return query_ind;
}

static void *srv_sync_ut_malloc_clear_msg(void)
{
	mmi_syncml_clean_luid_list_req_ind_struct *clean_ind = AllocSyncMsg(mmi_syncml_clean_luid_list_req_ind_struct);

	clean_ind->database_type = SYNCML_DB_PHONEBOOK;

	return clean_ind;
}

static void *srv_sync_ut_malloc_prog_msg(void)
{
	mmi_syncml_progress_info_ind_struct *prog_ind = AllocSyncMsg(mmi_syncml_progress_info_ind_struct);

	prog_ind->numberofchange = 100;
	prog_ind->progress_info = PROGRESS_CONTACT_LOCAL_NOC;

	return prog_ind;
}

static void *srv_sync_ut_malloc_finish_msg(void)
{
	mmi_syncml_finish_sync_ind_struct *msg = AllocSyncMsg(mmi_syncml_finish_sync_ind_struct);

	msg->result = SYNCML_FAIL;
	return msg;
}

#ifdef __MMI_SYNCML_DEVICE_SYNC__
static void *srv_sync_ut_malloc_bt_ask_msg(void)
{
	mmi_syncml_bt_ask_accept_conn_ind_struct *msg = AllocSyncMsg(mmi_syncml_bt_ask_accept_conn_ind_struct);

	msg->bt_addr_lap = 37;
	msg->bt_addr_uap = 23;
	msg->bt_addr_nap = 44;

	msg->device_name[0] = 'A';
	msg->device_name[1] = 0;
	msg->device_name[2] = 'B';
	msg->device_name[3] = 0;
	msg->device_name[4] = 'C';
	msg->device_name[5] = 0;
	msg->device_name[6] = 0;

	return msg;
}

static void *srv_sync_ut_malloc_bt_connected_msg(void)
{
	mmi_syncml_bt_connected_ind_struct *msg = AllocSyncMsg(mmi_syncml_bt_connected_ind_struct);

	msg->cm_id = 0;

	return msg;
}

static void *srv_sync_ut_malloc_bt_disconnected_msg(void)
{
	return NULL;
}

static void *srv_sync_ut_malloc_bt_remoteinfo_msg(void)
{	
	mmi_syncml_device_remoteinfo_ind_struct *msg = AllocSyncMsg(mmi_syncml_device_remoteinfo_ind_struct);

	msg->f_is_phone = 1;
	msg->device_uri[0] = 'a';
	msg->device_uri[1] = 'b';
	msg->device_uri[2] = 0;
	
	return msg;
}

static void *srv_sync_ut_malloc_bt_dbinfo_cont_msg(void)
{
	const U8* uri = ".\\Contact";
	U8 len = strlen(uri);
	
	mmi_syncml_device_sync_db_ind_struct *msg = AllocSyncMsg(mmi_syncml_device_sync_db_ind_struct);

	msg->synced_db_type =  SYNCML_DB_PHONEBOOK;
	
	strcpy(msg->database_remote_uri, uri);
	msg->database_remote_uri[len] = 0;
	
	return msg;
}

static void *srv_sync_ut_malloc_bt_dbinfo_cal_msg(void)
{
	const U8* uri = ".\\Calendar";
	U8 len = strlen(uri);
	
	mmi_syncml_device_sync_db_ind_struct *msg = AllocSyncMsg(mmi_syncml_device_sync_db_ind_struct);

	msg->synced_db_type =  SYNCML_DB_CALENDAR;
	
	strcpy(msg->database_remote_uri, uri);
	msg->database_remote_uri[len] = 0;
	
	return msg;
}

static void *srv_sync_ut_malloc_bt_dbinfo_task_msg(void)
{
	const U8* uri = ".\\Task";
	U8 len = strlen(uri);
	
	mmi_syncml_device_sync_db_ind_struct *msg = AllocSyncMsg(mmi_syncml_device_sync_db_ind_struct);

	msg->synced_db_type =  SYNCML_DB_TASK;
	
	strcpy(msg->database_remote_uri, uri);
	msg->database_remote_uri[len] = 0;
	
	return msg;
}

static void *srv_sync_ut_malloc_bt_dbinfo_note_msg(void)
{
	const U8* uri = ".\\Note";
	U8 len = strlen(uri);
	
	mmi_syncml_device_sync_db_ind_struct *msg = AllocSyncMsg(mmi_syncml_device_sync_db_ind_struct);

	msg->synced_db_type =  SYNCML_DB_NOTE;
	
	strcpy(msg->database_remote_uri, uri);
	msg->database_remote_uri[len] = 0;
	
	return msg;
}
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

void srv_sync_ut(U8 index)
{
	srv_sync_ut_struct *msg = NULL;
	U32 msg_id = MSG_TOTAL;
	
	switch (index)
	{
		case START_SYNC_REQ:
		{
			srv_sync_start(SRV_SYNC_REMOTE, 0, 0, NULL);
			break;
		}
		
		case SET_RECORD_REQ:
		{
			msg = srv_sync_ut_malloc_set_msg();
			msg_id = MSG_ID_MMI_SYNCML_SET_RECORD_REQ_IND;
			break;
		}	
		case GET_RECORD_REQ_IND:
		{
			msg = srv_sync_ut_malloc_get_msg();
			msg_id = MSG_ID_MMI_SYNCML_GET_RECORD_REQ_IND;

			break;
		}
		case QUERY_LUID_LIST_REQ_IND:
		{
			msg = srv_sync_ut_malloc_query_msg();
			msg_id = MSG_ID_MMI_SYNCML_QUERY_LUID_LIST_REQ_IND;
			break;
		}	
		case CLEAN_LUID_LIST_REQ_IND:
		{
			msg = srv_sync_ut_malloc_clear_msg();
			msg_id = MSG_ID_MMI_SYNCML_CLEAN_LUID_LIST_REQ_IND;

			break;
		}	
		case FINISH_SYNC_IND:
		{
			msg = srv_sync_ut_malloc_finish_msg();
			msg_id = MSG_ID_MMI_SYNCML_FINISH_SYNC_IND;

			break;
		}	
		case PROGRESS_INFO_IND:
		{
			msg = srv_sync_ut_malloc_prog_msg();
			msg_id = MSG_ID_MMI_SYNCML_PROGRESS_INFO_IND;
			break;
		}	
#ifdef __MMI_SYNCML_DEVICE_SYNC__
		case BT_ASK_ACCEPT_CONN_IND:
			msg = srv_sync_ut_malloc_bt_ask_msg();
			msg_id = MSG_ID_MMI_SYNCML_BT_ASK_ACCEPT_CONN_IND;
			break;
			
		case BT_CONNECTED_IND:
			msg = srv_sync_ut_malloc_bt_connected_msg();
			msg_id = MSG_ID_MMI_SYNCML_BT_CONNECTED_IND;

			break;
			
		case BT_DISCONNECTED_IND:
			msg = srv_sync_ut_malloc_bt_disconnected_msg();
			msg_id = MSG_ID_MMI_SYNCML_BT_DISCONNECTED_IND;

			break;
			
		case REMOTEINFO_IND:
			msg = srv_sync_ut_malloc_bt_remoteinfo_msg();
			msg_id = MSG_ID_MMI_SYNCML_DEVICE_REMOTEINFO_IND;

			break;
			
		case SYNC_DB_IND_CONT:
			msg = srv_sync_ut_malloc_bt_dbinfo_cont_msg();
			msg_id = MSG_ID_MMI_SYNCML_DEVICE_SYNC_DB_IND;
			break;
			
		case SYNC_DB_IND_CAL:
			msg = srv_sync_ut_malloc_bt_dbinfo_cal_msg();
			msg_id = MSG_ID_MMI_SYNCML_DEVICE_SYNC_DB_IND;
			break;
			
		case SYNC_DB_IND_TASK:
			msg = srv_sync_ut_malloc_bt_dbinfo_task_msg();
			msg_id = MSG_ID_MMI_SYNCML_DEVICE_SYNC_DB_IND;
			break;

		case SYNC_DB_IND_NOTE:
			msg = srv_sync_ut_malloc_bt_dbinfo_note_msg();
			msg_id = MSG_ID_MMI_SYNCML_DEVICE_SYNC_DB_IND;
			break;
			
		case SYNC_ANSWER_ACCEPT:
			srv_sync_answer(SRV_SYNC_ANSWER_ACCEPT);
			break;
			
		case SYNC_ANSWER_REJECT:
			srv_sync_answer(SRV_SYNC_ANSWER_REJECT);
			break;
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
			
		default:
			break;
	}

	if (msg != NULL || (msg_id == MSG_ID_MMI_SYNCML_BT_DISCONNECTED_IND) )
	{
		if (index >= 0 && index <= PS_BUSY_IND)
		{
		srv_sync_msg_simulator(msg, msg_id);
		}
		else
		{
			srv_sync_bt_msg_simulator(msg, msg_id);
		}

		if (msg != NULL)
		{
		OslMfree(msg);
	}
	}

}

#endif /*  __SYNCML_UT_MSG__ */

