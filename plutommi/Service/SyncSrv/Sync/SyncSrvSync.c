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
 * AlarmSrv.c
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
#include "SyncSrvSync.h"
#include "SyncSrvRemoteSync.h"
#include "SyncSrvPhoneSync.h"

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
*   srv_sync_database_is_ready
* DESCRIPTION
*	create database type
* PARAMETERS
*	type		:[IN]	database type
* RETURNS
*   srv_sync_database_type
*****************************************************************************/
srv_sync_ret_enum srv_sync_precheck(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	RETURN_VAL_IF_FAIL(obj != NULL, SRV_SYNC_RET_FAIL);

	return obj->precheck(obj);
}


void srv_sync_start_sync(srv_sync_type *obj, const U8 *imei)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	RETURN_IF_FAIL(obj != NULL);

	obj->start(obj, imei);

}
void srv_sync_abort_sync(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	RETURN_IF_FAIL(obj != NULL);

	obj->abort(obj);
}


U32 srv_sync_get_selected_db(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, 0);

	return obj->get_selected_database(obj);
}

MMI_BOOL srv_sync_match(srv_sync_type *obj, srv_sync_enum sync)
{
	RETURN_VAL_IF_FAIL(obj != NULL, MMI_FALSE);

	SRV_SYNC_LOG2(MMI_SRV_SYNC_MATCH_SYNC, sync, obj->sync);

	return (MMI_BOOL)(obj->sync == sync);
}

MMI_BOOL srv_sync_match_accnt(srv_sync_type *obj, U8 accnt_index)
{
	RETURN_VAL_IF_FAIL(obj != NULL, MMI_FALSE);

	SRV_SYNC_LOG2(MMI_SRV_SYNC_MATCH_ACCNT, accnt_index, obj->active_accnt);

	return (MMI_BOOL)(obj->active_accnt == accnt_index);
}


void srv_sync_destroy(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	if (obj != NULL && obj->close != NULL)
	{
		obj->close(obj);
	}
}

void srv_sync_on_query(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	if (obj != NULL && obj->on_query != NULL)
	{
		obj->on_query(obj);
	}
}

void srv_sync_on_finish(srv_sync_type *obj, void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (obj != NULL && obj->close != NULL)
	{
		obj->on_finish(obj, msg);
	}
}

srv_sync_enum srv_sync_active_type(srv_sync_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, SRV_SYNC_TOTAL);

	return obj->sync;
}

srv_sync_type* srv_sync_create(srv_sync_enum sync, U8 accnt_index, void* user_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_type *obj = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	switch(sync)
	{
		case SRV_SYNC_REMOTE:
			obj = srv_sync_remote_create(accnt_index, user_data);
			break;
			
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
		case SRV_SYNC_PHONE:
			obj = srv_sync_phone_create(accnt_index, user_data);
			break;
#endif
		case SRV_SYNC_PC:
		default:
			return NULL;
	}

	return obj;
}

void srv_sync_sync_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	srv_sync_remote_init();
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
	srv_sync_phone_init();
#endif
}

