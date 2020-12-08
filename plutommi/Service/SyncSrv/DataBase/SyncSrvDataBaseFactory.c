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

#include "SyncSrvDataBase.h"
#include "SyncSrvDatabaseCfg.h"
#include "SyncSrvDatabaseContact.h"

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
#include "SyncSrvDatabaseEvent.h"
#endif

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
#include "SyncSrvDbTask.h"
#endif

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
#include "SyncSrvDbNote.h"
#endif

#include "SyncSrvDatabaseFactory.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/
#define SRV_SYNC_GET_DB_ITEM(_idx) g_srv_sync_db_cfg_table[_idx]
#define CREATE_FUNC(_name) srv_sync_database_##_name##_create
#define CREATE_CLOG_FUNC(_name) srv_sync_changelog_##_name##_create
#define DB_READY_FUNC(_name) srv_sync_database_##_name##_is_ready
#define SRV_SYNC_DB_TOTAL (sizeof(g_srv_sync_db_cfg_table) / sizeof(srv_sync_database_cfg_item_type))

/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
static srv_sync_database_cfg_item_type g_srv_sync_db_cfg_table[] =
{
	{
		SYNCML_DB_ID_CON, 
		"text/x-vcard", 
		SYNCML_DB_PHONEBOOK, 
		CREATE_FUNC(contact),
		CREATE_CLOG_FUNC(contact),
		DB_READY_FUNC(contact)
	},
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__		
	{	
		SYNCML_DB_ID_CAL, 
		"text/x-vcalendar",
		SYNCML_DB_CALENDAR, 
		CREATE_FUNC(event),
		CREATE_CLOG_FUNC(event),
		NULL,
	},
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__	
	{
		SYNCML_DB_ID_TASK,
		"text/x-vcalendar",
		SYNCML_DB_TASK,
		CREATE_FUNC(task),
		CREATE_CLOG_FUNC(task),
		NULL,
	},
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
	{
		SYNCML_DB_ID_NOTE,
		"text/plain",
		SYNCML_DB_NOTE,
		CREATE_FUNC(note),
		CREATE_CLOG_FUNC(note),
		NULL
	},
#endif
};

/*****************************************************************************
 * Global function
 *****************************************************************************/

U32 srv_sync_database_foreach(srv_sync_database_visit_funcptr visit, void *usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < SRV_SYNC_DB_TOTAL; i++)
	{
		if (visit(&SRV_SYNC_GET_DB_ITEM(i), usr_data) == RET_STOP)
		{
			break;
		}
	}

	return i;
}

U32 srv_sync_database_foreach_ext(srv_sync_database_visit_ext_funcptr visit, void *usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < SRV_SYNC_DB_TOTAL; i++)
	{
		if (visit(i, &SRV_SYNC_GET_DB_ITEM(i), usr_data) == RET_STOP)
		{
			break;
		}
	}

	return i;
}

U16 srv_sync_get_database_id(U32 db_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_database_cfg_item_type *item;	
	U32 i;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < SRV_SYNC_DB_TOTAL; i++)
	{
		item = &SRV_SYNC_GET_DB_ITEM(i);
		if (item->type == db_type)
		{
			return item->id;
		}
	}

	return 0xFF;
}


U32 srv_sync_get_total_database_type(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_database_cfg_item_type *item;	
	U32 i;
	U32 total_type = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < SRV_SYNC_DB_TOTAL; i++)
	{
		item = &SRV_SYNC_GET_DB_ITEM(i);
		total_type |= item->type;
	}

	return total_type;
}


/* change log factory*/
srv_sync_changelog_type *srv_sync_changelog_create(const U32 db_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_database_cfg_item_type *item;	
	U32 i;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < SRV_SYNC_DB_TOTAL; i++)
	{
		item = &SRV_SYNC_GET_DB_ITEM(i);
		if (item->id == db_id)
		{
			return item->create_clog();
		}
	}

	return NULL;
}


/*****************************************************************************
 * Please refer to SyncSrvGprot.h
 *****************************************************************************/
U32 srv_sync_get_database_count(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	return SRV_SYNC_DB_TOTAL;
}

MMI_BOOL srv_sync_is_database_ready(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_database_cfg_item_type *item;	
	U32 i;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for (i = 0; i < SRV_SYNC_DB_TOTAL; i++)
	{
		item = &SRV_SYNC_GET_DB_ITEM(i);
		if (item->is_ready != NULL && !item->is_ready())
		{
			return MMI_FALSE;
		}
	}

	return MMI_TRUE;
}

