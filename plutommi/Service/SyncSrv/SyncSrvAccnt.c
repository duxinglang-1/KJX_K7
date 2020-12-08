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
 * SyncSrvAccnt.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Header files
*****************************************************************************/
#include "SyncSrvAccnt.h"
#include "SyncSrvRemoteAccnt.h"
#include "SyncSrvPhoneAccnt.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/


/*****************************************************************************
* Global Variables 
*****************************************************************************/

/*****************************************************************************
* Local Variables 
*****************************************************************************/
#define FUNCTION

void srv_sync_accnt_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  	*/
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  	*/
	/*----------------------------------------------------------------*/
	srv_sync_remote_accnt_init();
	
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
	srv_sync_phone_accnt_init();
#endif
}

/*****************************************************************************
 * FUNCTION
 *	srv_sync_read_accnt
 * DESCRIPTION
 *	Answer
 * PARAMETERS
 *	answer	:[IN]	answer enum
 * RETURNS
 *	void
 *****************************************************************************/
void *srv_sync_read_accnt(srv_sync_enum sync, U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	void *accnt = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch (sync)
	{
		case SRV_SYNC_REMOTE:
			accnt = srv_sync_remote_read_accnt(accnt_index);
			break;
			
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
		case SRV_SYNC_PHONE:
			accnt = srv_sync_phone_read_accnt(accnt_index);
			break;
#endif
		case SRV_SYNC_PC:
		default:
			break;
	}

	return accnt;
}

MMI_BOOL srv_sync_read_accnt_buffer(void *buffer, U32 size, srv_sync_enum sync, U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_FALSE;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch (sync)
	{
		case SRV_SYNC_REMOTE:
			ret = srv_sync_remote_read_accnt_buffer(buffer, size ,accnt_index);
			break;
			
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
		case SRV_SYNC_PHONE:
			ret = srv_sync_phone_read_accnt_buffer(buffer, size ,accnt_index);
			break;
#endif
		case SRV_SYNC_PC:
		default:
			break;
	}

	return ret;

}

S32 srv_sync_accnt_new_index(srv_sync_enum sync)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 new_index = -1;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch (sync)
	{
		case SRV_SYNC_REMOTE:
			new_index = srv_sync_remote_accnt_new_index();
			break;
			
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
		case SRV_SYNC_PHONE:
			new_index = srv_sync_phone_accnt_new_index();
			break;
#endif
		case SRV_SYNC_PC:
		default:
			break;
	}

	return new_index;

}

/*****************************************************************************
 * FUNCTION
 *	srv_sync_write_accnt
 * DESCRIPTION
 *	Answer
 * PARAMETERS
 *	sync	 :[IN]	sync
 *	sync :[IN]	accnt_index
 *	void	 :[IN]	accnt
 * RETURNS
 *	void
 *****************************************************************************/
void srv_sync_write_accnt(srv_sync_enum sync, void *accnt, U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch (sync)
	{
	case SRV_SYNC_REMOTE:
		srv_sync_remote_write_accnt(accnt, accnt_index);
		break;
		
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
	case SRV_SYNC_PHONE:
		srv_sync_phone_write_accnt(accnt, accnt_index);
		break;
#endif
	case SRV_SYNC_PC:
	default:
		break;
	}
}


/* account factory */
srv_sync_accnt_type * srv_sync_accnt_create(const srv_sync_enum sync, const U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_sync_accnt_type *obj = NULL;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	switch (sync)
	{
		case SRV_SYNC_REMOTE:
			obj = srv_sync_accnt_remote_create(accnt_index);
			break;
			
#ifdef	__MMI_SYNCML_DEVICE_SYNC__
		case SRV_SYNC_PHONE:
			obj = srv_sync_accnt_phone_create(accnt_index);
			break;
#endif
		case SRV_SYNC_PC:
			break;
		default:
			break;
	}

	return obj;

}

#define ACCNT_INTERFACE

void *srv_sync_accnt_read(srv_sync_accnt_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL && obj->read != NULL, NULL);

	return obj->read(obj);
}

void srv_sync_accnt_write(srv_sync_accnt_type *obj, const void *data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && obj->write != NULL);

	obj->write(obj, data);	
}

U32 srv_sync_accnt_anchor(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL && obj->anchor != NULL, 0);

	return obj->anchor(obj, database_id);
}


void srv_sync_accnt_set_anchor(srv_sync_accnt_type *obj, const U32 database_id, const U32 anchor)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && obj->set_anchor != NULL);
	
	obj->set_anchor(obj, database_id, anchor);
}

U8 *srv_sync_accnt_db_uri(srv_sync_accnt_type *obj, const U32 database_type)
{
	RETURN_VAL_IF_FAIL(obj != NULL && obj->db_uri != NULL, NULL);

	return obj->db_uri(obj, database_type);
}

void srv_sync_accnt_set_db_uri(srv_sync_accnt_type *obj, const U32 database_type, const U8* uri, const U8 len)
{
	RETURN_IF_FAIL(obj != NULL && obj->set_db_uri != NULL);

	obj->set_db_uri(obj, database_type, uri, len);
}

U8 *srv_sync_accnt_remote_anchor(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL && obj->remote_anchor != NULL, NULL);

	return obj->remote_anchor(obj, database_id);
}

void srv_sync_accnt_set_remote_anchor(srv_sync_accnt_type *obj, const U32 database_type, const U8* uri, const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && obj->set_remote_anchor != NULL);


	obj->set_remote_anchor(obj, database_type, uri, len);
}


void srv_sync_accnt_destroy(srv_sync_accnt_type *obj)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL);

	obj->destory(obj);

}

U8 *srv_sync_accnt_db_addr(srv_sync_accnt_type *obj, const U32 database_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL && obj->db_addr != NULL, NULL);

	return obj->db_addr(obj, database_type);
}

void srv_sync_accnt_set_db_addr(srv_sync_accnt_type *obj, const U32 database_type, const U8* addr, const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && obj->set_db_addr != NULL);

	obj->set_db_addr(obj, database_type, addr, len);
}


U8 *srv_sync_accnt_db_usrname(srv_sync_accnt_type *obj, const U32 database_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL && obj->db_usrname != NULL, NULL);

	return obj->db_usrname(obj, database_type);

}

void srv_sync_accnt_set_db_usrname(srv_sync_accnt_type *obj,
											const U32 database_type, 
											const U8* buffer, 
											const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && obj->set_db_usrname != NULL);

	obj->set_db_usrname(obj, database_type, buffer, len);
}


U8 *srv_sync_accnt_db_pwd(srv_sync_accnt_type *obj, const U32 database_id)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL && obj->db_pwd!= NULL, NULL);

	return obj->db_pwd(obj, database_id);

}

void srv_sync_accnt_set_db_pwd(srv_sync_accnt_type *obj, 
										const U32 database_id, 
										const U8* pwd, 
										const U8 len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(obj != NULL && obj->set_db_pwd != NULL);

	obj->set_db_pwd(obj, database_id, pwd, len);
}

U32 srv_sync_accnt_selected_db(srv_sync_accnt_type *obj)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL && obj->selected_db != NULL, 0);
	
	return obj->selected_db(obj);
}

srv_sync_enum srv_sync_accnt_sync(srv_sync_accnt_type *obj)
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

U8 srv_sync_accnt_index(srv_sync_accnt_type *obj)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(obj != NULL, 0);
	
	return obj->accnt_index;
}

