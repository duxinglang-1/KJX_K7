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
 * BrowserSrvProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERSRVMAIN_H
#define MMI_BROWSERSRVMAIN_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "BrowserSrvProts.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

#ifdef BRW_MEM_LEAK_DEBUG_MODE
extern void *srv_brw_malloc_ex(U32 mem_size, S8 *filename, U32 line_num);
#else
extern void *srv_brw_malloc_ex(U32 mem_size);
#endif /* BRW_MEM_LEAK_DEBUG_MODE */
extern void srv_brw_free(void *pMemory);
extern void srv_brw_dynamic_list_free_memory(srv_brw_list_type_enum list_type);
extern S32 srv_brw_validate_url(U8 *url_p, U16 url_length);
extern S32 srv_brw_validate_url_ex(U8 *url_p, U16 url_length, MMI_BOOL is_http_scheme_needed);
extern void srv_brw_get_bearer_type (U8 *bearer_type_p);
extern void srv_brw_get_profile_content (void **profile_content_p);
extern void srv_brw_address_list_update_data(srv_brw_list_action_enum act_type, U8 *title_p);
extern void srv_brw_object_properties_reset(void);
extern void srv_brw_set_bearer(MMI_BOOL hold_bearer);
extern MMI_BOOL srv_brw_is_holding_bearer(void);
extern void srv_brw_clear_browser_data_on_sim_change(void);
extern U8 srv_brw_get_active_profile_count(void);
extern void srv_brw_address_list_update_data(srv_brw_list_action_enum act_type, U8 *title_p);
extern void srv_brw_global_context_init(void);
extern void srv_brw_dynamic_context_init(void);
extern void srv_brw_dynamic_context_deinit(void);
extern void srv_brw_free_browser_memory(void **ptr);
extern S16 srv_brw_update_user_defined_homepage(U8* url_p);
extern void srv_brw_free_OSL_memory(void **ptr);
extern void srv_brw_shortcuts_list_update_data(void);
extern void srv_brw_save_user_app_req_data(U16 rsp_msg_id, srv_brw_act_req_struct *app_req_data);

#ifdef __COSMOS_MMI_PACKAGE__
extern void srv_brw_search_list_update_data(void);
extern void srv_brw_search_list_count_number_of_items (void);

#endif /* __COSMOS_MMI_PACKAGE__ */
extern void srv_brw_call_user_app_req_data(U16 rsp_msg_id, U32 result, void *rsp_data);

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSRVMAIN_H */
