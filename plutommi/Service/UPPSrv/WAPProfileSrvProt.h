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

/*******************************************************************************
 * Filename:
 * ---------
 * WAPProfileSrvProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This declares the function prototypes for UPP profile module.
 *
 * Author: Ramneek Kalra
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
#ifndef _WAPPROFILESRVPROT_H
#define _WAPPROFILESRVPROT_H

#include "MMI_features.h"
#include "MMIDataType.h"

//------------------------------ suggest Add ------------------------------
#include "wgui_categories_list.h"
 // ------------------------------ suggest Add ------------------------------
#ifdef WAP_SUPPORT
#include "WAPProfileSrvType.h"
#include "WAPProvisioningSrvType.h"
#include "kal_general_types.h"


extern MMI_BOOL srv_wap_prof_get_module_status(srv_wap_prof_module_status_enum *module_status);
extern srv_wap_prof_profile_source_enum srv_wap_prof_get_profile_source(void);
extern MMI_BOOL srv_wap_prof_set_module_status(void);

extern void srv_wap_prof_deinit(void);
extern void srv_wap_prof_reset_status(void);
extern void srv_wap_prof_process_init_event(void);
extern MMI_BOOL srv_wap_prof_is_subscribe_dtcnt(void);

#if 0
/* under construction !*/
#endif

extern void srv_wap_prof_set_cbm_app(srv_wap_prof_sim_id_enum sim_id , srv_wap_prof_app_id_enum app_id,  U8 cbm_app_id);
extern U8 srv_wap_prof_get_cbm_app_id(srv_wap_prof_app_id_enum app_id, srv_wap_prof_sim_id_enum  sim_info);

#ifndef __SRV_UPP_SLIM__
extern void srv_wap_prof_delete_job(void);
extern void srv_wap_prof_process_job(void);
extern void srv_wap_prof_process_job_queue_ind_hdlr(void *msg);
extern void srv_wap_prof_send_process_job_queue_ind(void);
#endif

extern MMI_BOOL srv_wap_prof_is_re_entry_allowed(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id);

extern MMI_BOOL srv_wap_prof_bool_result(MMI_BOOL result);


extern kal_bool srv_wap_prof_is_active_profile_in_use(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id); /* MAUI_1420567 */

extern void srv_wap_prof_set_active_profile_index(
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_app_id_enum app_id,
                U32 index_value,
                MMI_BOOL commit_flag);

extern S16 srv_wap_prof_validate_url(U8 *url_p, MMI_BOOL b_blank_url_is_valid);

extern U8 srv_wap_prof_get_data_account_list_bearer_scope(srv_wap_prof_app_id_enum app_id);
extern void *srv_wap_prof_mem_allocate(U32 size);
extern void srv_wap_prof_mem_free(void *ptr);
extern srv_wap_prof_action_enum srv_wap_prof_get_action(void);
extern srv_wap_prof_app_id_enum srv_wap_prof_get_app_id(void);


extern void srv_wap_prof_nvram_read_active_profile_index(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id);
extern void srv_wap_prof_nvram_write_active_profile_index(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id);


/* Interface / Msg Handler API. */

extern void srv_wap_prof_send_msg(U16 dst_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

extern void srv_wap_prof_active_profile_changed(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id);

extern void srv_wap_prof_active_profile_change_confirmation_callback(srv_wap_prof_result_enum result);
extern void srv_wap_prof_active_mms_profile_chg_ind_callback(
                srv_wap_prof_profile_content_struct *profile_content_p,
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_response_funcptr_type callback);
extern void srv_wap_prof_active_brw_profile_chg_ind_callback(
                srv_wap_prof_profile_content_struct *profile_content_p,
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_response_funcptr_type callback);

extern MMI_BOOL srv_wap_prof_target_app_is_ready(srv_wap_prof_app_id_enum app_id);


extern void srv_wap_prov_continue_provisioning(void);

extern void srv_wap_prof_send_activate_account_ind(U32 account_id,
									            MMI_BOOL inform_other,
												srv_wap_prof_sim_id_enum sim_id,
												srv_wap_prof_app_id_enum app_id);

U32 srv_wap_prof_encode_dtcnt(U8 primary_index, U8 secondary_index, srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id );

void srv_wap_prof_dtcnt_updated_ind_hdlr(mmi_event_struct *param);
void srv_wap_prof_dtcnt_deleted_ind_hdlr(mmi_event_struct *param);

#ifdef __MMI_BROWSER_2__
void srv_wap_prof_wlan_account_updated_ind_hdlr(mmi_event_struct *param);
#endif

/* API definitions in MACROS */
/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_get_active_dtcnt_index
 * DESCRIPTION
 *  THis API returns the active profile index, based on SIMID and APPID.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8    active profile index
 *****************************************************************************/
#define srv_wap_prof_get_active_dtcnt_index(sim_id, app_id) g_srv_wap_prof_cntx.active_dtcnt_index[(sim_id)][(app_id)]


/*****************************************************************************
 * FUNCTION
 *  mmi_wap_prof_get_active_dtcnt_index
 * DESCRIPTION
 *  THis API returns the  smart profile index, based on SIMID and APPID.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8    active profile index
 *****************************************************************************/
#define srv_wap_prof_get_smart_dtcnt_index(sim_id, app_id) g_srv_wap_prof_cntx.smart_dtcnt_index[(sim_id)][(app_id)]

/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_get_active_profile_content_value
 * DESCRIPTION
 *  Returns pointer to active profile content (from cntx). API used to make single entry point.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
#define srv_wap_prof_get_active_profile_content_value(sim_id, app_id) &(g_srv_wap_prof_cntx.active_profile_content[(sim_id)][(app_id)])





#endif /* WAP_SUPPORT */ 
#endif /* _WAPPROFILEPROT_H */ 
