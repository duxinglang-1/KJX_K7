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
 *  SyncSrvCm.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SYNC_SRV_CM_H__
#define __SYNC_SRV_CM_H__

/*****************************************************************************
 * include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "SyncSrv.h"

/*****************************************************************************
 * Typedef 
 *****************************************************************************/

typedef void (*srv_sync_cm_funcptr)(srv_sync_cm_type *obj);
typedef U8 (*srv_sync_cm_u8_funcptr)(srv_sync_cm_type *obj);
typedef MMI_BOOL (*srv_sync_cm_bool_funcptr)(srv_sync_cm_type *obj);
typedef void (*srv_sync_cm_on_rsp_funcptr)(srv_sync_cm_type *obj, U32 rsp);
typedef void (*srv_sync_cm_on_funcptr)(srv_sync_cm_type *obj, void *param);

struct srv_sync_cm_cntx{
	srv_sync_cm_funcptr destroy;
	srv_sync_cm_u8_funcptr role;
	
	srv_sync_cm_on_funcptr on_ask_conn;
	srv_sync_cm_on_funcptr on_ask_sync;
	srv_sync_cm_on_rsp_funcptr on_rsp;
	
	srv_sync_cm_bool_funcptr conn;
	srv_sync_cm_on_funcptr on_conn;
	srv_sync_cm_on_funcptr on_connected;
	
	srv_sync_cm_funcptr    disconn;
	srv_sync_cm_on_funcptr on_disconn;
	srv_sync_cm_on_funcptr on_disconnected;

	void *priv;
};

/*****************************************************************************
 * Global function 
 *****************************************************************************/
extern void srv_sync_cm_destroy(srv_sync_cm_type *obj);

extern void srv_sync_cm_on_ask_conn(srv_sync_cm_type *obj, void *param);
extern void srv_sync_cm_on_ask_sync(srv_sync_cm_type *obj, void *param);
extern void srv_sync_cm_on_rsp(srv_sync_cm_type *obj, U32 rsp);

extern MMI_BOOL srv_sync_cm_connect(srv_sync_cm_type *obj);
extern void srv_sync_cm_on_conn(srv_sync_cm_type *obj, void *param);
extern void srv_sync_cm_on_connected(srv_sync_cm_type *obj, void *param);

extern void srv_sync_cm_disconnect(srv_sync_cm_type *obj);
extern void srv_sync_cm_on_disconn(srv_sync_cm_type *obj, void *param);
extern void srv_sync_cm_on_disconnected(srv_sync_cm_type *obj, void *param);
extern U8 srv_sync_cm_role(srv_sync_cm_type *obj);

#endif /* __SYNC_SRV_CM_H__ */

