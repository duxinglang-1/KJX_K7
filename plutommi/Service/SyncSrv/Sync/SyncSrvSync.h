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
 *  SyncSrvChangeLog.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Published interface of syncml service.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SYNC_SRV_SYNC_H__
#define __SYNC_SRV_SYNC_H__

/*****************************************************************************
 * include 
 *****************************************************************************/
#include "MMIDataType.h"

#include "SyncSrvGprot.h"
#include "SyncSrv.h"

/*****************************************************************************
 * Typedef 
 *****************************************************************************/

typedef srv_sync_type* (*srv_sync_create_funcptr)(U8 accnt_index);

typedef srv_sync_ret_enum (*srv_sync_precheck_funcptr)(srv_sync_type *obj);
typedef void (*srv_sync_start_funcptr)(srv_sync_type *obj, const U8 *imei);
typedef void (*srv_sync_obj_funcptr)(srv_sync_type *obj);
typedef void (*srv_sync_obj_void_funcptr)(srv_sync_type *obj, void* msg);
typedef void (*srv_sync_setup_cm_funcptr)(srv_sync_cm_type *cm);
typedef void (*srv_sync_attatch_database_funcptr)(srv_sync_type *obj, srv_sync_database_type *database, U8 count);

typedef void (*srv_sync_read_sync_accnt_funcptr)(srv_sync_type *obj, U8 accnt_index);
typedef void (*srv_sync_write_sync_accnt_funcptr)(srv_sync_type *obj, U8 accnt_index, void *accnt);
typedef MMI_BOOL (*srv_sync_match_funcptr)(srv_sync_type *obj, srv_sync_enum sync);
typedef MMI_BOOL (*srv_sync_match_accnt_funcptr)(srv_sync_type *obj, U8 accnt_index);
typedef U32 (*srv_sync_get_selected_db_funcptr)(srv_sync_type *obj);

struct srv_sync_cntx{
	srv_sync_obj_funcptr on_query;
	srv_sync_obj_void_funcptr on_finish;

	srv_sync_get_selected_db_funcptr get_selected_database;
	srv_sync_precheck_funcptr precheck;
	srv_sync_start_funcptr start;
	srv_sync_obj_funcptr abort;
	srv_sync_obj_funcptr close;

	srv_sync_match_funcptr 		 match;
	srv_sync_match_accnt_funcptr match_accnt;
	srv_sync_setup_cm_funcptr 	 setup_cm;
	
	srv_sync_cm_type *cm;
	srv_sync_enum sync;
	U8 active_accnt;
	U16 type;			/* sync type */
		
	void *priv;
};

/*****************************************************************************
 * Interface
 *****************************************************************************/
extern srv_sync_type* srv_sync_create(srv_sync_enum sync, U8 accnt_index, void* user_data);
extern srv_sync_ret_enum srv_sync_precheck(srv_sync_type *obj);
extern void srv_sync_start_sync(srv_sync_type *obj, const U8 *imei);
extern void srv_sync_abort_sync(srv_sync_type *obj);
extern U32 srv_sync_setup_cm(srv_sync_cm_type *cm);
extern void srv_sync_destroy(srv_sync_type *obj);
extern void srv_sync_on_finish(srv_sync_type *obj, void *msg);
extern MMI_BOOL srv_sync_match(srv_sync_type *obj, srv_sync_enum sync);
extern MMI_BOOL srv_sync_match_accnt(srv_sync_type *obj, U8 accnt_index);
extern U32 srv_sync_get_selected_db(srv_sync_type *obj);
extern void srv_sync_on_query(srv_sync_type *obj);
extern srv_sync_enum srv_sync_active_type(srv_sync_type *obj);

/*****************************************************************************
 * Global function
 *****************************************************************************/
extern void *srv_sync_read_sync_accnt(srv_sync_enum sync, U8 accnt_index);
extern void srv_sync_write_sync_accnt(srv_sync_enum sync, U8 accnt_index, void *accnt);
extern void srv_sync_sync_init(void);

#endif /* __SYNC_SRV_SYNC_H__ */

