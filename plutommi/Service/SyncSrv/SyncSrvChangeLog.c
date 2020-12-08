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
 * SyncSrvChangelog.c
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
#include "custom_mmi_default_value.h"

#include "syncml_common_customize.h"
#include "SyncSrvGprot.h"

#include "SyncSrv.h"
#include "SyncSrvChangeLog.h"
#include "SyncSrvDatabaseCfg.h"
#include "SyncSrvSync.h"

/*****************************************************************************
 * Typedef 
 *****************************************************************************/
#define SYNCML_CHANGE_LOG_RECORD_SIZE 7 /* U16(LUID) + U32(timestamp) + U8(operation) */
	
#define SYNCML_CHANGE_LOG_NOT_FOUND -1

/*****************************************************************************
 * Global Variables 
 *****************************************************************************/

/*****************************************************************************
 * Local Variables 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_sync_changelog_prepare_record
 * DESCRIPTION
 *  Prepare the change log data
 * PARAMETERS
 *	record	: [IN]	record buffer
 *	operation	: [IN]	operation
 *	luid		: [IN]	LUID
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sync_changelog_prepare_record(U8 *record, U8 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 s;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(record != NULL);
	
    memcpy(record, (void *)(&luid), sizeof(U16));
    s = srv_sync_get_current_time();
    memcpy(record + sizeof(U16), (void *)(&s), sizeof(U32));
    record[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] = operation;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_search_duplicate_record
 * DESCRIPTION
 *  Search if there is a duplicate change log with the same LUID
 * PARAMETERS
 *  luid                    [IN]            LUID
 *  profile_id              [IN]            profile id
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
static S32 srv_sync_changelog_search_dup_record(const WCHAR *path, const U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fp;
    S32 res = SYNCML_CHANGE_LOG_NOT_FOUND;
    U32 fs_size, read_length, i;
    U8 syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE];
    U16 luid_temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(path != NULL, SYNCML_CHANGE_LOG_NOT_FOUND);
	
	fp = FS_Open(path, FS_READ_ONLY);
	
    if (fp >= 0)
    {
        FS_GetFileSize(fp, &fs_size);

        for (i = 0; i < fs_size; i += SYNCML_CHANGE_LOG_RECORD_SIZE)
        {
            FS_Read(fp, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
            memcpy((void *) &luid_temp, (void*) &syncml_temp[0], sizeof(U16));
            if (luid == luid_temp)
            {
                res = i;
                break;
            }
        }

        FS_Close(fp);
    }
    else
    {
        /* file access error... */
    }

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_changelog_append_record
 * DESCRIPTION
 *  Append the change log data
 * PARAMETERS
 *  profile_id              [IN]            profile id
 *  application_type        [IN]            application/database type
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
static void srv_sync_changelog_append_record(const WCHAR *path, const U8* record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 written_length;
	FS_HANDLE fp;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(path != NULL);
	
	fp = FS_Open(path, FS_CREATE | FS_READ_WRITE);
	RETURN_IF_FAIL(fp >= 0);

    FS_Seek(fp, 0, FS_FILE_END);
    FS_Write(fp, (void *)record, SYNCML_CHANGE_LOG_RECORD_SIZE, &written_length); 
    FS_Close(fp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_changelog_operation_update
 * DESCRIPTION
 *  Check the operation if the change log is duplicted
 * PARAMETERS
 *  old_operation           [IN]            old operation
 *  new_operation           [IN]            new operation
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 srv_sync_changelog_operation_update(U8 old_operation, U8 new_operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rtn = old_operation;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (old_operation)
    {
        case SYNCML_RECORD_ADD:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD: /* error */
                    break;
                case SYNCML_RECORD_MODIFY:
                    rtn = SYNCML_RECORD_ADD;
                    break;
                case SYNCML_RECORD_DELETE:
                    rtn = SYNCML_RECORD_ERASE;
                    break;
                case SYNCML_RECORD_MOVE:
                    break;
            }
            break;
        case SYNCML_RECORD_MODIFY:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD: /* error */
                    break;
                case SYNCML_RECORD_MODIFY:
                    rtn = SYNCML_RECORD_MODIFY;
                    break;
                case SYNCML_RECORD_DELETE:
                    rtn = SYNCML_RECORD_DELETE;
                    break;
                case SYNCML_RECORD_MOVE:
                    break;
            }
            break;
        case SYNCML_RECORD_DELETE:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD:
                    rtn = SYNCML_RECORD_MODIFY;
                    break;
                case SYNCML_RECORD_MODIFY: /* error */
                    break;
                case SYNCML_RECORD_DELETE: /* error */
                    break;
                case SYNCML_RECORD_MOVE: /* error */
                    break;
            }
            break;
        case SYNCML_RECORD_MOVE:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD: /* error */ 
                    break;
                case SYNCML_RECORD_MODIFY: 
                    rtn = SYNCML_RECORD_MODIFY;
                    break;
                case SYNCML_RECORD_DELETE: 
                    rtn = SYNCML_RECORD_DELETE;
                    break;
                case SYNCML_RECORD_MOVE: 
                    break;                 
            }
            break;
    }

    return rtn;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_changelog_clearall
 * DESCRIPTION
 *  clear all items in change log
 * PARAMETERS
 *  profile_id           [IN]            profile id
 *  database             [IN]            application/database type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sync_changelog_clearall(const WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fp;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(path != NULL);
	
	fp = FS_Open(path, FS_READ_WRITE);
	
	RETURN_IF_FAIL(fp >= 0);
	
    if (fp >= 0)
    {
        FS_Seek(fp, 0, FS_FILE_BEGIN);
        FS_Truncate(fp);
        FS_Close(fp);
    }  
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_changelog_query
 * DESCRIPTION
 *  Qurey the change log
 * PARAMETERS
 *  profile_id           [IN]            profile id
 *  database             [IN]            application/database type
 *  luid                 [OUT]           LUID
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sync_changelog_query(const WCHAR *path, U8 operation, U16 *luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read_length, fs_size, i;
    U16 count = 0;
    U8 syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE];
	FS_HANDLE fp;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(path != NULL, 0);
	
	fp = FS_Open(path, FS_READ_ONLY);
	
	RETURN_VAL_IF_FAIL(fp >= 0, 0);

    FS_GetFileSize(fp, &fs_size);

    for (i = 0; i < fs_size; i += SYNCML_CHANGE_LOG_RECORD_SIZE)
    {
        FS_Read(fp, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
        if (syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] == operation)
        {
            *(luid + count) = ((U16*)syncml_temp)[0]; 
            count++;
        }
    }

    FS_Close(fp);
	
    return count;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sync_merge_record
 * DESCRIPTION
 *  Append the change log data
 * PARAMETERS
 *  profile_id              [IN]            profile id
 *  application_type        [IN]            application/database type
 *  fs_index                [IN]            file index
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
static void srv_sync_changelog_merge_record(const WCHAR *path, const U8* record, S32 fs_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fp;
    U32 read_length, written_length, fs_size, i;
    U8 old_operation, new_operation;
    U8 syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE];
    U8 syncml_update[SYNCML_CHANGE_LOG_RECORD_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(path != NULL);
	
	fp = FS_Open(path, FS_READ_WRITE);
	RETURN_IF_FAIL(fp >= 0);

    FS_GetFileSize(fp, &fs_size);

    /* find out the data for merge */
    FS_Seek(fp, fs_index, FS_FILE_BEGIN);
    FS_Read(fp, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
    old_operation = syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE - 1];
    new_operation = record[SYNCML_CHANGE_LOG_RECORD_SIZE - 1];

    memcpy((void*) &syncml_update[0], (void*) &record[0], SYNCML_CHANGE_LOG_RECORD_SIZE);
    syncml_update[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] = srv_sync_changelog_operation_update(old_operation, new_operation);

    /* prepare the updated change log */
    FS_Seek(fp, fs_index, FS_FILE_BEGIN); /* change file content from the modified index */
    if (syncml_update[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] == SYNCML_RECORD_ERASE)
    {
        /* after erase a record, other record need move ahead */
        for (i = fs_index + SYNCML_CHANGE_LOG_RECORD_SIZE; i < fs_size; i += SYNCML_CHANGE_LOG_RECORD_SIZE)
        {
            FS_Seek(fp, SYNCML_CHANGE_LOG_RECORD_SIZE, FS_FILE_CURRENT);
            FS_Read(fp, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
            FS_Seek(fp, 0 - 2 * SYNCML_CHANGE_LOG_RECORD_SIZE, FS_FILE_CURRENT);
            FS_Write(fp, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &written_length);
        }
        FS_Truncate(fp);
    }
    else
    {
        FS_Write(fp, (void*) &syncml_update[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &written_length);
    }

    FS_Close(fp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_changelog_is_writable
 * DESCRIPTION
 *  Whether can write the current account
 * PARAMETERS
 *  obj    [IN]	change log handle
 *  sync	[IN]	sync type
 *  luid	[IN]	local unique ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_sync_changelog_is_writable(
					srv_sync_changelog_type * obj, 
					srv_sync_enum sync, 
					U8 accnt_index)
{
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_type *active_sync = srv_sync_active_sync();
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_CLOG_IS_WRITABLE);

	if (active_sync != NULL)
	{
		if (srv_sync_is_db_synchronizing(obj->db_type) &&
			srv_sync_match(active_sync, sync)&&
			srv_sync_match_accnt(active_sync, accnt_index))
		{
			return MMI_FALSE;
		}

	}

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_changelog_on_sync_change
 * DESCRIPTION
 *  Whether can write the current account
 * PARAMETERS
 *  obj    	 [IN]	 change log handle
 *  sync		 [IN]	 sync type
 *  max_accnt [IN] max account number
 *  operation	 [IN] database opration: Add, Modify, Delete	
 *  luid		 [IN]	 local unique ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void srv_sync_changelog_on_sync_change(
				srv_sync_changelog_type *obj, 
				srv_sync_enum sync,
				U8  max_accnt,
				U16 operation,
				U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 record[SYNCML_CHANGE_LOG_RECORD_SIZE];
    S32 luid_exist;
	WCHAR *path;
	U32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && max_accnt != 0);
	
	for (i = 0; i < max_accnt; i++)
	{
		/* this profile is used to sync before */ 
		if (!srv_sync_changelog_is_firstsync(obj, sync, i)) 
		{
			/* change to write change log even if in syncing 
			 * It is for that in next syncing we can send the data received last time,
			 * This change is from cmcc test requirement.
			 */ 				  
			if (!srv_sync_changelog_is_writable(obj, sync, i) && operation != SYNCML_RECORD_ADD)
			{
				continue;
			}
			
			path = srv_sync_changelog_create_filename(obj, sync, i);

			if (path == NULL)
			{
				continue;
			}
			
			srv_sync_changelog_prepare_record(record, (U8)operation, luid);
			luid_exist = srv_sync_changelog_search_dup_record(path, luid);	
			if (luid_exist >= 0)
			{
				srv_sync_changelog_merge_record(path, record, luid_exist);
			}
			else
			{
				srv_sync_changelog_append_record(path, record);
			}

			srv_sync_changelog_close_filename(obj, path);
		}
	}
	
}


void srv_sync_changelog_on_change(srv_sync_changelog_type *obj, U16 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const U8 sync_max_accnt[SRV_SYNC_TOTAL] = {MAX_SYNCML_SV_PROFILES, MAX_SYNCML_DEV_NUM};
	srv_sync_enum sync;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	RETURN_IF_FAIL(obj != NULL);

	/* every sync has its own changelog. */
	for (sync = SRV_SYNC_REMOTE; sync < SRV_SYNC_TOTAL; sync++)
	{
		srv_sync_changelog_on_sync_change(obj, sync, sync_max_accnt[sync], operation, luid);
	}

}

#define CHANGELOG_INTERFACE
WCHAR *srv_sync_changelog_create_filename(srv_sync_changelog_type *obj, const srv_sync_enum sync, const U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);

	return obj->creat_filename(obj, sync, accnt_index);
}

void srv_sync_changelog_close_filename(srv_sync_changelog_type *obj, U16 *path)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	obj->close_filename(obj, path); 

}

void srv_sync_changelog_destroy(srv_sync_changelog_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	obj->destroy(obj);
}

MMI_BOOL srv_sync_changelog_is_firstsync(srv_sync_changelog_type *obj, const srv_sync_enum sync, const U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, MMI_FALSE);

	return obj->is_firstsync(obj, sync, accnt_index);
}

void srv_sync_changelog_init(srv_sync_changelog_type *obj, U32 *anchor_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


