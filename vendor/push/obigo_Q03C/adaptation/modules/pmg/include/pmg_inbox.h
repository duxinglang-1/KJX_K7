/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   pmg_inbox.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains PMG function prototypes, constant/macro/structure definition 
 *   for Push Inbox AP handling
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _pmg_inbox_h
#define _pmg_inbox_h

#include "phs_cfg.h"
//suggested add
    #include "msf_def.h"
    #include "pmg_if.h"
    #include "pmg_struct.h"
   #include "kal_general_types.h"

void pmg_inbox_init(void);

void pmg_inbox_terminate(void);

void pmg_inbox_handle_config_req(void *p);

void pmg_inbox_handle_msg_count_req(void *p);

void pmg_inbox_handle_msg_list_req(void *p);

void pmg_inbox_handle_get_msg_req(void *p);

void pmg_inbox_handle_get_msg_infotag_req(void *p);

void pmg_inbox_handle_delete_msg_req(void *p);

void pmg_inbox_handle_delete_all_req(void *p);

void pmg_inbox_handle_update_msg_req(void *p);

void pmg_inbox_handle_new_msg_rsp(void);

void pmg_inbox_handle_auth_addr_list_req(void *p);

void pmg_inbox_send_wps_pmg_ready_ind(void);

void pmg_inbox_send_wps_pmg_delete_ind(int msgID, MSF_UINT8 msgType);

void pmg_inbox_send_wps_pmg_delete_ind_ext(kal_uint32 size, pmg_msg_id_struct msgs[PMG_MAX_DELETED_MSG_LIST_SIZE]);

void pmg_inbox_send_wps_pmg_new_msg_ind(void *msg);

void pmg_inbox_send_wps_pmg_replace_ind(void *msg);

void pmg_inbox_send_wps_pmg_dlg_sia_confirm_req(pmg_dlg_display_req_t *dlgreq);

void pmg_inbox_send_wps_pmg_dlg_unknown_addr_req(pmg_dlg_display_req_t *dlgreq);

pmg_dlg_display_req_t *pmg_inbox_new_dlg_display_req(void);

void pmg_inbox_release_dlg_display_req(pmg_dlg_display_req_t *dlgreq);

void pmg_inbox_register_dlg(pmg_dlg_display_req_t *dlgreq);

void pmg_inbox_handle_display_dialog_req(void *p);

void pmg_inbox_handle_dlg_sia_confirm(MSF_UINT32 id, MSF_BOOL accept);

void pmg_inbox_handle_dlg_unknown_addr(MSF_UINT32 id, MSF_BOOL accept);

void pmg_inbox_handle_dlg_query_req(void *p);

void pmg_inbox_handle_update_all_msg_req(void *p);

#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
extern void pmg_inbox_send_wps_pmg_dlg_push_storage_full_ind(int msgID, MSF_UINT8 msgType);
#else
extern void pmg_inbox_send_wps_pmg_dlg_push_storage_full_ind();
#endif /*__MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__*/

extern kal_uint8 g_pmg_app_id;

#endif /* _pmg_inbox_h */ 


