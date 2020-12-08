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
 *  SyncSrvAccnt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Published interface of syncml service account.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SYNC_SRV_ACCNT_H__
#define __SYNC_SRV_ACCNT_H__

/*****************************************************************************
 * include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "SyncSrvGprot.h"
#include "SyncSrv.h"

/*****************************************************************************
 * Typedef 
 *****************************************************************************/

typedef srv_sync_accnt_type * (*srv_sync_accnt_create_funcptr)(const srv_sync_enum sync, const U8 accnt_index);
typedef void (*srv_sync_accnt_destroy_funcptr)(srv_sync_accnt_type *obj);
typedef void *(*srv_sync_accnt_read_funcptr)(srv_sync_accnt_type *obj);
typedef U32 (*srv_sync_accnt_selected_db_funcptr)(srv_sync_accnt_type *obj);
typedef void (*srv_sync_accnt_write_funcptr)(srv_sync_accnt_type *obj, const void *data);
typedef U32 (*srv_sync_accnt_anchor_funcptr)(srv_sync_accnt_type *obj, const U32 database_id);
typedef void (*srv_sync_accnt_set_anchor_funcptr)(srv_sync_accnt_type *obj, const U32 database_id, const U32 anchor);
typedef U8 *(*srv_sync_accnt_db_get_string)(srv_sync_accnt_type *obj, const U32 database_id);
typedef void (*srv_sync_accnt_db_set_string)(srv_sync_accnt_type *obj, const U32 database_id, const U8* buffer, const U8 len);

struct srv_sync_accnt_cntx{	
	srv_sync_accnt_read_funcptr 	read;
	srv_sync_accnt_write_funcptr 	write;
	srv_sync_accnt_selected_db_funcptr selected_db;
	
	srv_sync_accnt_anchor_funcptr 	anchor;
	srv_sync_accnt_set_anchor_funcptr set_anchor;
	
	srv_sync_accnt_db_get_string db_uri;
	srv_sync_accnt_db_set_string set_db_uri;
	srv_sync_accnt_db_get_string remote_anchor;
	srv_sync_accnt_db_set_string set_remote_anchor;
	srv_sync_accnt_db_get_string db_addr;
	srv_sync_accnt_db_set_string set_db_addr;
	srv_sync_accnt_db_get_string db_usrname;
	srv_sync_accnt_db_set_string set_db_usrname;
	srv_sync_accnt_db_get_string db_pwd;
	srv_sync_accnt_db_set_string set_db_pwd;
	
	srv_sync_accnt_destroy_funcptr destory;
	
	srv_sync_enum sync;
	U8 accnt_index;
	U8 unused[2];
	
	void *priv;	/* private infomation */
};
/*****************************************************************************
 * Global function 
 *****************************************************************************/
extern void srv_sync_accnt_init(void);
extern void *srv_sync_read_accnt(srv_sync_enum sync, U8 accnt_index);
extern void srv_sync_write_accnt(srv_sync_enum sync, void *accnt, U8 accnt_index);

extern U32 srv_sync_accnt_selected_db(srv_sync_accnt_type *obj);
extern void *srv_sync_accnt_read(srv_sync_accnt_type *obj);
extern void srv_sync_accnt_write(srv_sync_accnt_type *obj, const void *data);
extern U32 srv_sync_accnt_anchor(srv_sync_accnt_type *obj, const U32 database_type);
extern void srv_sync_accnt_set_anchor(srv_sync_accnt_type *obj, const U32 database_id, const U32 anchor);
extern U8 *srv_sync_accnt_remote_anchor(srv_sync_accnt_type *obj, const U32 database_type);
extern void srv_sync_accnt_set_remote_anchor(srv_sync_accnt_type *obj, const U32 database_type, const U8* pwd, const U8 len);
extern void srv_sync_accnt_destroy(srv_sync_accnt_type *obj);
extern U8 *srv_sync_accnt_db_addr(srv_sync_accnt_type *obj, const U32 database_type);
extern void srv_sync_accnt_set_db_addr(srv_sync_accnt_type *obj, const U32 database_type, const U8* addr, const U8 len);
extern 	U8 *srv_sync_accnt_db_usrname(srv_sync_accnt_type *obj, const U32 database_type);
extern void srv_sync_accnt_set_db_usrname(srv_sync_accnt_type *obj, const U32 database_type, const U8* buffer, const U8 len);
extern U8 *srv_sync_accnt_db_pwd(srv_sync_accnt_type *obj, const U32 database_type);
extern void srv_sync_accnt_set_db_pwd(srv_sync_accnt_type *obj, const U32 database_type, const U8* pwd, const U8 len);
extern U8 *srv_sync_accnt_db_uri(srv_sync_accnt_type *obj, const U32 database_type);
extern void srv_sync_accnt_set_db_uri(srv_sync_accnt_type *obj, const U32 database_type, const U8* pwd, const U8 len);

extern srv_sync_enum srv_sync_accnt_sync(srv_sync_accnt_type *obj);
extern U8 srv_sync_accnt_index(srv_sync_accnt_type *obj);

extern srv_sync_accnt_type * srv_sync_accnt_create(const srv_sync_enum sync, const U8 accnt_index);

#endif /* __SYNC_SRV_ACCNT_H__ */

