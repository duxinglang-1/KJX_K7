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
 * SyncSrvCM.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * connect manager of sync
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMIDataType.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include "SyncSrvGprot.h"
#include "SyncSrv.h"
#include "SyncSrvCm.h"
#include "BtCMSrvGprot.h"

/*****************************************************************************
 * Typedef 
 *****************************************************************************/

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
void srv_sync_cm_destroy(srv_sync_cm_type *obj)
{
	RETURN_IF_FAIL(obj != NULL);
	
	obj->destroy(obj);
}

void srv_sync_cm_on_ask_conn(srv_sync_cm_type *obj, void *param)
{
	RETURN_IF_FAIL(obj != NULL && param != NULL);
	
	obj->on_ask_conn(obj, param);
}
void srv_sync_cm_on_ask_sync(srv_sync_cm_type *obj, void *param)
{
	RETURN_IF_FAIL(obj != NULL && param != NULL);
	
	obj->on_ask_sync(obj, param);
}

void srv_sync_cm_on_rsp(srv_sync_cm_type *obj, U32 rsp)
{
	obj->on_rsp(obj, rsp);
}

MMI_BOOL srv_sync_cm_connect(srv_sync_cm_type *obj)
{
	RETURN_VAL_IF_FAIL(obj != NULL, MMI_FALSE);
	
	return obj->conn(obj);
}

void srv_sync_cm_on_conn(srv_sync_cm_type *obj, void *param)
{
	RETURN_IF_FAIL(obj != NULL && param != NULL);
	
	obj->on_conn(obj, param);
}

void srv_sync_cm_on_connected(srv_sync_cm_type *obj, void *param)
{
	RETURN_IF_FAIL(obj != NULL && param != NULL);

	obj->on_connected(obj, param);
}

void srv_sync_cm_disconnect(srv_sync_cm_type *obj)
{
	RETURN_IF_FAIL(obj != NULL);

	obj->disconn(obj);
}

void srv_sync_cm_on_disconn(srv_sync_cm_type *obj, void *param)
{
	RETURN_IF_FAIL(obj != NULL);

	obj->on_disconn(obj, param);
}

void srv_sync_cm_on_disconnected(srv_sync_cm_type *obj, void *param)
{
	RETURN_IF_FAIL(obj != NULL && param != NULL);

	obj->on_disconnected(obj, param);
}

