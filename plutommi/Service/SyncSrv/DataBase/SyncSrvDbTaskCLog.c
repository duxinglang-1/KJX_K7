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
 * SyncSrvDbTaskCLog.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * task change log
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
#include "syncml_common_customize.h"
#include "mmi2syncml_struct.h"

#include "TodolistSrvGprot.h"

#include "SyncSrvChangelog.h"
#include "SyncSrvDataBase.h"

#include "SyncSrvRemoteAccnt.h"
#include "SyncSrvPhoneAccnt.h"

#include "SyncSrvDbTask.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/

#define SYNC_TASK_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\synctask"
#define SYNC_TASK_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\synctask1.log"

#define SYNC_DEV_TASK_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\syncdev_task"
#define SYNC_DEV_TASK_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\syncdev_task1.log"

/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/

static WCHAR *srv_sync_changelog_task_create_filename(
					srv_sync_changelog_type *obj, 
					const srv_sync_enum sync, 
					const U8 accnt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR *path = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch(sync)
	{
		case SRV_SYNC_REMOTE:
		{
			path = OslMalloc(sizeof(SYNC_TASK_CHANGE_LOG_FILE_PATH));
		
			mmi_ucs2cpy((CHAR*)path, (CHAR*)SYNC_TASK_CHANGE_LOG_FILE_PATH);
			*(path + sizeof(SYNC_TASK_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + accnt_index;
			break;
		}
		
		case SRV_SYNC_PHONE:
		{
			path = OslMalloc(sizeof(SYNC_DEV_TASK_CHANGE_LOG_FILE_PATH));
		
			mmi_ucs2cpy((CHAR*)path, (CHAR*) SYNC_DEV_TASK_CHANGE_LOG_FILE_PATH);
			*(path + sizeof(SYNC_DEV_TASK_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + accnt_index;	
		
			break;
		}
		
		default:
			break;
	}

	
	return (WCHAR *)path;
}

static void srv_sync_changelog_task_close_filename(srv_sync_changelog_type *obj, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && path != NULL);
	
	OslMfree(path);
}

static MMI_BOOL srv_sync_changelog_task_is_firstsync(srv_sync_changelog_type *obj, const srv_sync_enum sync, const U8 accnt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 last_anchor = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL && accnt_index < MAX_SYNCML_SV_PROFILES, MMI_FALSE);

	switch (sync)
	{
		case SRV_SYNC_REMOTE:
			last_anchor = srv_sync_remote_accnt_anchor(accnt_index, SYNCML_DB_ID_TASK);
			break;
			
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
		case SRV_SYNC_PHONE:
			last_anchor = srv_sync_phone_accnt_anchor(accnt_index, SYNCML_DB_ID_TASK);
			break;
#endif
		default:
			break;
	}
	
	SRV_SYNC_LOG3(MMI_SYNC_SRV_CLOG_CONT_FIRST_SYNC, sync, accnt_index, last_anchor);
	
	return (MMI_BOOL)(last_anchor == 0);

}

mmi_ret srv_sync_task_op_notify(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_op_evt_struct *evt = (srv_tdl_op_evt_struct*)param;
	srv_sync_changelog_type *obj;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_CLOG_CONT_ADD, evt->store_idx);

	if (evt->vcal_type == SRV_TDL_VCAL_TASK)
	{
		obj = srv_sync_changelog_task_create();
		srv_sync_changelog_on_change(obj,
								 (SYNCML_RECORD_ADD + (evt->op_type - SRV_TDL_OP_ADD)), 
								 evt->store_idx);

		srv_sync_changelog_destroy(obj);
	
		srv_sync_remote_regular_check(SRV_SYNC_REGULAR_AT_DATA_CHANGE, SYNCML_DB_TASK);
	}
	
	return MMI_RET_OK;
}


static void srv_sync_changelog_task_destroy(srv_sync_changelog_type *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (obj != NULL)
	{
		OslMfree(obj);
		obj = NULL;
	}
}

srv_sync_changelog_type *srv_sync_changelog_task_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sync_changelog_type *obj = (srv_sync_changelog_type *)OslMalloc(sizeof(srv_sync_changelog_type));
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	obj->creat_filename = srv_sync_changelog_task_create_filename;
	obj->close_filename = srv_sync_changelog_task_close_filename;
	obj->is_firstsync 	= srv_sync_changelog_task_is_firstsync;
	obj->destroy 		= srv_sync_changelog_task_destroy;

	obj->db_type = SYNCML_DB_TASK;
	
	return obj;
}

