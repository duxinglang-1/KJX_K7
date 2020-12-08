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
 *  SyncSrvPhoneSync.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SYNC_SRV_PHONE_SYNC_H__
#define __SYNC_SRV_PHONE_SYNC_H__

/*****************************************************************************
 * include 
 *****************************************************************************/
#include "MMIDataType.h"

#include "SyncSrv.h"

/*****************************************************************************
 * Typedef 
 *****************************************************************************/
#define MMI_SYNCML_DEV_ROLE_NONE   0
#define MMI_SYNCML_DEV_ROLE_A 1
#define MMI_SYNCML_DEV_ROLE_B 2

#define MMI_SYNCML_DEV_SYNC_ACCEPT 1
#define MMI_SYNCML_DEV_SYNC_REJECT 0

#define MMI_SYNCML_DEV_CONN_ACCEPT 1
#define MMI_SYNCML_DEV_CONN_REJECT 0

#define MAX_MMI_SYNCML_DEV_STR_LEN 96

#define SYNCML_DEV_BTCM_OPR_MASK_DEACTIVE	0x01
#define SYNCML_DEV_BTCM_OPR_MASK_DISCONN	0x02
#define SYNCML_DEV_BTCM_OPR_MASK_DEINIT	    0x04

#define MMI_SYNCML_DEV_INVALID_CONN_ID 0XFFFF

/*****************************************************************************
 * Global function 
 *****************************************************************************/
extern srv_sync_type* srv_sync_phone_create(U8 accnt_index, void* user_data);
extern void srv_sync_phone_ask_sync_rsp(srv_sync_type *obj, U16 rsp);
extern void srv_sync_on_database_info(srv_sync_type *obj, void *param);
extern void srv_sync_reject_sync_request(srv_sync_type *obj);

extern void srv_sync_phone_init(void);
#endif /* __SYNC_SRV_PHONE_SYNC_H__ */

