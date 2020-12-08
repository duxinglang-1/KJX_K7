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
 *  change lig interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SYNC_SRV_CHANGELOG_H__
#define __SYNC_SRV_CHANGELOG_H__

/*****************************************************************************
 * include 
 *****************************************************************************/
#include "MMIDataType.h"

#include "SyncSrvGprot.h"
#include "SyncSrv.h"
/*****************************************************************************
 * Typedef 
 *****************************************************************************/
typedef srv_sync_changelog_type *(*srv_sync_changelog_create_funcptr)(void);
typedef WCHAR* (*srv_sync_changelog_create_filename_funcptr)(srv_sync_changelog_type *obj, const srv_sync_enum sync, const U8 accnt_index);
typedef void (*srv_sync_changelog_close_filename_funcptr)(srv_sync_changelog_type *obj, U16 *filename);
typedef void (*srv_sync_changelog_destroy_funcptr)(srv_sync_changelog_type *obj);
typedef MMI_BOOL (*srv_sync_changelog_is_firstsync_funcptr)(srv_sync_changelog_type *obj, const srv_sync_enum sync, const U8 accnt_index);

struct srv_sync_changelog_cntx
{
	srv_sync_changelog_create_filename_funcptr creat_filename;
	srv_sync_changelog_close_filename_funcptr  close_filename;
	srv_sync_changelog_is_firstsync_funcptr	   is_firstsync;
	srv_sync_changelog_destroy_funcptr destroy;

	U32 db_type;
};


/*****************************************************************************
 * Global function 
 *****************************************************************************/

extern WCHAR *srv_sync_changelog_create_filename(srv_sync_changelog_type *obj, const srv_sync_enum sync, const U8 accnt_index);
extern void srv_sync_changelog_close_filename(srv_sync_changelog_type *obj, U16 *path);
extern void srv_sync_changelog_destroy(srv_sync_changelog_type *obj);
extern MMI_BOOL srv_sync_changelog_is_firstsync(srv_sync_changelog_type *obj, const srv_sync_enum sync, const U8 accnt_index);
extern U16 srv_sync_changelog_query(const WCHAR *path, U8 operation, U16 *luid);

extern void srv_sync_changelog_on_change(srv_sync_changelog_type *obj, U16 operation, U16 luid);
extern void srv_sync_changelog_clearall(const WCHAR *path);
extern U32  srv_sync_changelog_get_current_time(void);
extern srv_sync_changelog_type *srv_sync_changelog_create(const U32 db_id);

#endif /* __SYNC_SRV_CHANGELOG_H__ */

