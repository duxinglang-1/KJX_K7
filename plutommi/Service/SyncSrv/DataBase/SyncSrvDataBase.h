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
 *  SyncSrvDatabase.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sync service database interface abstract
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SYNC_SRV_DATABASE_H__
#define __SYNC_SRV_DATABASE_H__

/*****************************************************************************
 * include 
 *****************************************************************************/
#include "MMIDataType.h"

#include "SyncSrv.h"
#include "SyncSrvAccnt.h"
/*****************************************************************************
 * Typedef 
 *****************************************************************************/
typedef srv_sync_database_type* (*srv_sync_database_create_funcptr)(void);
typedef MMI_BOOL (*srv_sync_database_is_ready_funcptr)(void);

typedef MMI_BOOL (*srv_sync_database_match_funcptr)(srv_sync_database_type *obj, U32 type);
typedef MMI_BOOL (*srv_sync_database_ready_funcptr)(srv_sync_database_type *obj);
typedef void (*srv_sync_database_fill_log_funcptr)(srv_sync_database_type *obj, void *msg);
typedef void (*srv_sync_database_on_sync_evt_funcptr)(srv_sync_database_type *obj, void *req);
typedef void (*srv_sync_database_on_progress_funcptr)(srv_sync_database_type *obj, void *req);
typedef void (*srv_sync_database_on_finish_funcptr)(srv_sync_database_type *obj, void *msg);
typedef void (*srv_sync_database_on_start_funcptr)(srv_sync_database_type *obj, srv_sync_enum sync, U8 accnt_index, void *msg);
typedef void (*srv_sync_database_destroy_funcptr)(srv_sync_database_type *obj);
typedef void (*srv_sync_database_lock_funcptr)(srv_sync_database_type *obj);
typedef void (*srv_sync_database_unlock_funcptr)(srv_sync_database_type *obj);
typedef void (*srv_sync_database_attatch_accnt_funcptr)(srv_sync_database_type *obj, srv_sync_accnt_type *accnt);
typedef U32 (*srv_sync_database_visit_funcptr)(void *data, void *usr_data);
typedef U32 (*srv_sync_database_visit_ext_funcptr)(U32 idx, void *data, void *usr_data);
typedef U32 (*srv_sync_database_type_funcptr)(srv_sync_database_type *obj);


typedef struct {
	U16 db_type;
	U16 id;
	
	U32 curr_recv;
	U32 recv_noc;	/* number of changed */
	U32 curr_send;
	U32 send_noc;
	U32 ok_cnt[3];		// 0->Add, 1->Modify, 2->Delete
	U32 fail_cnt;
	U32 srv_ok_cnt[3];
	U32 srv_fail_cnt;

	U8 *address;
	U8 *username;
	U8 *password;
	U8 *mime_type;
	U8 *remote_anchor;
	U32 last_anchor;
	U32 next_anchor;
	U32 free_id;
	U32 free_mem;

	MMI_BOOL fail;
}srv_sync_db_info_type;

struct srv_sync_database_cntx{
	srv_sync_database_on_sync_evt_funcptr	on_query_luid_list;
	srv_sync_database_on_sync_evt_funcptr	on_clean_luid_list;
	srv_sync_database_on_sync_evt_funcptr	on_set_record;
	srv_sync_database_on_sync_evt_funcptr	on_get_record;
	srv_sync_database_on_sync_evt_funcptr	on_progress;
	srv_sync_database_on_finish_funcptr 	on_finish;
	srv_sync_database_on_start_funcptr		on_start;	/* fill database related data*/

	srv_sync_database_fill_log_funcptr	fill_log;
	srv_sync_database_destroy_funcptr	destroy;
	srv_sync_database_ready_funcptr		is_ready;
	srv_sync_database_match_funcptr		match;
	srv_sync_database_lock_funcptr		lock;
	srv_sync_database_unlock_funcptr	unlock;
	srv_sync_database_type_funcptr		type;

	srv_sync_database_attatch_accnt_funcptr accatch_accnt;
	
	srv_sync_db_info_type	db_info; /* alloc at runtime */
	srv_sync_accnt_type 	*accnt;

	MMI_BOOL fail_flag;
	
	void *priv;				/* database private infomation */
};

/*****************************************************************************
 * Global Interface
 *****************************************************************************/
extern void srv_sync_database_destroy(srv_sync_database_type *obj);
extern void srv_sync_database_lock(srv_sync_database_type *obj);
extern void srv_sync_database_unlock(srv_sync_database_type *obj);
extern U32 srv_sync_database_get_type(srv_sync_database_type *obj);
extern MMI_BOOL srv_sync_database_match(srv_sync_database_type *obj, U32 type);
extern MMI_BOOL srv_sync_database_is_ready(srv_sync_database_type *obj);
extern void srv_sync_database_attatch_accnt(srv_sync_database_type *obj, srv_sync_accnt_type *accnt);
extern const srv_sync_db_info_type *srv_sync_database_db_info(srv_sync_database_type *obj);

extern void srv_sync_database_on_query_luid_list(srv_sync_database_type *obj, srv_sync_request_struct *req);
extern void srv_sync_database_on_query_luid_list(srv_sync_database_type *obj, srv_sync_request_struct *req);
extern void srv_sync_database_on_set_record(srv_sync_database_type *obj, srv_sync_request_struct *req);
extern void srv_sync_database_on_get_record(srv_sync_database_type *obj, srv_sync_request_struct *req);
extern void srv_sync_database_on_progress(srv_sync_database_type *obj, void *msg);
extern void srv_sync_database_on_finish(srv_sync_database_type *obj, void *msg);
extern void srv_sync_database_on_start(srv_sync_database_type *obj, srv_sync_enum sync, U8 accnt_index, void *msg);
extern void srv_sync_database_on_clean_luid_list(srv_sync_database_type *obj, srv_sync_request_struct *req);

/*****************************************************************************
 * Global function
 *****************************************************************************/
extern U32 srv_sync_database_foreach(srv_sync_database_visit_funcptr visit, void* usr_data);
extern 	U32 srv_sync_database_foreach_ext(srv_sync_database_visit_ext_funcptr visit, void *usr_data);
extern U16 srv_sync_get_database_id(U32 db_type);
extern U32 srv_sync_get_total_database_type(void);
extern void srv_sync_database_update_stat(
				srv_sync_database_type *obj, 
				U16 result, 
				srv_sync_action_enum action);
extern void srv_sync_database_progress_notify(srv_sync_database_type *obj, 
											 srv_sync_action_enum action);

extern U16 srv_sync_database_query_clog(const srv_sync_database_type *obj, U16 *luid_buf, U8 operation);

#endif /* __SYNC_SRV_DATABASE_H__ */

