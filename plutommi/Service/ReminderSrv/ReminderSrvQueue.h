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
 *  ReminderSrvQueue.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Published interface of reminder queue, which is FIFO queue.
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
#ifndef __REMINDER_Q_SRV_H__
#define __REMINDER_Q_SRV_H__

#include "ReminderSrvGprot.h"

typedef struct
{
	MYTIME time;
	U32 type;
	U32 usr_data;
}srv_reminder_q_node_type;

struct srv_reminder_q_cntx;
typedef struct srv_reminder_q_cntx srv_reminder_q_type;

extern srv_reminder_q_type *srv_reminder_q_create(void);
extern void srv_reminder_q_destroy(srv_reminder_q_type * thiz);
extern void srv_reminder_q_init(srv_reminder_q_type *thiz);
extern void srv_reminder_q_empty(srv_reminder_q_type *thiz);
extern U32  srv_reminder_q_search(srv_reminder_q_type *thiz, const srv_reminder_q_node_type *node);
extern U32  srv_reminder_q_cnt(srv_reminder_q_type *thiz);
extern MMI_BOOL srv_reminder_q_is_empty(srv_reminder_q_type *thiz);

extern srv_reminder_ret_enum srv_reminder_q_add(srv_reminder_q_type *thiz, const srv_reminder_q_node_type *node);
extern srv_reminder_ret_enum srv_reminder_q_add_with_callback(srv_reminder_q_type *thiz, const srv_reminder_q_node_type *node, srv_reminder_compare_funcptr cmp);
extern srv_reminder_ret_enum srv_reminder_q_update(srv_reminder_q_type *thiz, U32 idx, const srv_reminder_q_node_type *node);
extern srv_reminder_ret_enum srv_reminder_q_delete(srv_reminder_q_type *thiz, const srv_reminder_q_node_type *node);
extern srv_reminder_ret_enum srv_reminder_q_delete_by_index(srv_reminder_q_type *thiz, U32 index);
extern srv_reminder_q_node_type *srv_reminder_q_get(srv_reminder_q_type *thiz, U32 index);
extern srv_reminder_ret_enum srv_reminder_q_insert(srv_reminder_q_type *thiz, U32 index, const srv_reminder_q_node_type *node);

#endif /* __REMINDER_Q_SRV_H__ */

