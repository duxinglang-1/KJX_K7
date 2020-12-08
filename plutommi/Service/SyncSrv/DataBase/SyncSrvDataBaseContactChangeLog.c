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
 * SyncSrvDatabaseContactChangeLog.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Contact change log
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
#include "PhbSrvGprot.h"

#include "SyncSrv.h"
#include "SyncSrvChangelog.h"
#include "SyncSrvDataBase.h"

#include "SyncSrvRemoteAccnt.h"
#include "SyncSrvPhoneAccnt.h"
#include "SyncSrvDataBaseContact.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/

#define SYNC_PHB_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\syncphbk"
#define SYNC_PHB_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\syncphbk1.log"

#define SYNC_DEV_PHB_CHANGE_LOG_FILE_PREFIX L"Z:\\@SyncML\\syncdev_phb"
#define SYNC_DEV_PHB_CHANGE_LOG_FILE_PATH   L"Z:\\@SyncML\\syncdev_phb1.log"


/*****************************************************************************
* Global Variables 
*****************************************************************************/
srv_sync_changelog_type *srv_sync_changelog_conatct_create(void);

/*****************************************************************************
* Local Variables 
*****************************************************************************/

static WCHAR *srv_sync_changelog_contact_create_filename(
					srv_sync_changelog_type *obj, 
					const srv_sync_enum sync, 
					const U8 accnt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR *path;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, NULL);
	
	switch(sync)
	{
		case SRV_SYNC_REMOTE:
		{
			path = OslMalloc(sizeof(SYNC_PHB_CHANGE_LOG_FILE_PATH));
		
			mmi_ucs2cpy(path, (CHAR*) SYNC_PHB_CHANGE_LOG_FILE_PATH);
			*(path + sizeof(SYNC_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + accnt_index;
			break;
		}
		
		case SRV_SYNC_PHONE:
		{
			path = OslMalloc(sizeof(SYNC_DEV_PHB_CHANGE_LOG_FILE_PATH));
		
			mmi_ucs2cpy(path, (CHAR*) SYNC_DEV_PHB_CHANGE_LOG_FILE_PATH);
			*(path + sizeof(SYNC_DEV_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + accnt_index;	
		
			break;
		}
		
		default:
		{
			path = NULL;
			break;
		}
	}

	
	return (WCHAR *)path;
}

static void srv_sync_changelog_contact_close_filename(srv_sync_changelog_type *obj, WCHAR *path)
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

static MMI_BOOL srv_sync_changelog_contact_is_firstsync(srv_sync_changelog_type *obj, const srv_sync_enum sync, const U8 accnt_index)
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
			last_anchor = srv_sync_remote_accnt_anchor(accnt_index, SYNCML_DB_ID_CON);
			break;
			
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
		case SRV_SYNC_PHONE:
			last_anchor = srv_sync_phone_accnt_anchor(accnt_index, SYNCML_DB_ID_CON);
			break;
#endif
		default:
			break;
	}
	
	SRV_SYNC_LOG3(MMI_SYNC_SRV_CLOG_CONT_FIRST_SYNC, sync, accnt_index, last_anchor);
	
	return (MMI_BOOL)(last_anchor == 0);
}

/*****************************************************************************
 * FUNCTION
 *  srv_sync_contact_addition_notification
 * DESCRIPTION
 *  addition notification for mmi framework register
 * PARAMETERS
 *  event              [IN]            event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_sync_contact_addition_notification(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct *evt = (srv_phb_op_evt_struct*)param;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_CLOG_CONT_ADD, evt->store_index);
	
	if (srv_phb_get_storage(evt->store_index) == PHB_STORAGE_NVRAM)
    {
	    srv_sync_changelog_type *obj;

		obj = srv_sync_changelog_contact_create();
		srv_sync_changelog_on_change(obj, 
									 SYNCML_RECORD_ADD, 
									 evt->store_index);

		srv_sync_changelog_destroy(obj);

		srv_sync_remote_regular_check(SRV_SYNC_REGULAR_AT_DATA_CHANGE, SYNCML_DB_PHONEBOOK);
    }
	
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_contact_deletion_notification
 * DESCRIPTION
 *  deletion notification for mmi framework register
 * PARAMETERS
 *  event              [IN]            event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_sync_contact_deletion_notification(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct *evt = (srv_phb_op_evt_struct*)param;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_CLOG_CONT_DELETE, evt->store_index);
	if (srv_phb_get_storage(evt->store_index) == PHB_STORAGE_NVRAM)
    {
    	srv_sync_changelog_type *obj;

		obj = srv_sync_changelog_contact_create();
        srv_sync_changelog_on_change(obj, 
									 SYNCML_RECORD_DELETE, 
									 evt->store_index);
		srv_sync_changelog_destroy(obj);

		srv_sync_remote_regular_check(SRV_SYNC_REGULAR_AT_DATA_CHANGE, SYNCML_DB_PHONEBOOK);
	}	
	
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sync_contact_modification_notification
 * DESCRIPTION
 *  modification notification for mmi framework register
 * PARAMETERS
 *  event              [IN]            event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_sync_contact_modification_notification(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)param;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_CLOG_CONT_MODIFY, evt->store_index);
	if (srv_phb_get_storage(evt->store_index) == PHB_STORAGE_NVRAM)
    {
		srv_sync_changelog_type *obj;

    	obj = srv_sync_changelog_contact_create();
        srv_sync_changelog_on_change(obj,
									 SYNCML_RECORD_MODIFY, 
									 evt->store_index);
		srv_sync_changelog_destroy(obj);

		srv_sync_remote_regular_check(SRV_SYNC_REGULAR_AT_DATA_CHANGE, SYNCML_DB_PHONEBOOK);
	}
	
    return MMI_RET_OK;
}


static void srv_sync_changelog_contact_destroy(srv_sync_changelog_type *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_CLOG_CONT_DESTROY);
	
	if (obj != NULL)
	{
		OslMfree(obj);
		obj = NULL;
	}
}

srv_sync_changelog_type *srv_sync_changelog_contact_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sync_changelog_type *obj = (srv_sync_changelog_type *)OslMalloc(sizeof(srv_sync_changelog_type));
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG0(MMI_SYNC_SRV_CLOG_CONT_CREATE);
	
	obj->creat_filename = srv_sync_changelog_contact_create_filename;
	obj->close_filename = srv_sync_changelog_contact_close_filename;
	obj->is_firstsync 	= srv_sync_changelog_contact_is_firstsync;
	obj->destroy 		= srv_sync_changelog_contact_destroy;

	obj->db_type = SYNCML_DB_PHONEBOOK;
	
	return obj;
}

