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
 * WAPProvisioningSrvProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This declares the function prototypes for UPP provisioning module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "WAPProfileSrvType.h"
#ifdef PROV_SUPPORT
#ifndef _WAPPROVISIONINGSRVPROT_H
#define _WAPPROVISIONINGSRVPROT_H

#include "MMI_features.h"
#include "MMIDataType.h"

#ifdef WAP_SUPPORT

#include "WAPprovisioningSrvType.h"


#include "CcaSrvGprot.h"

extern void srv_wap_prof_add_bookmark_rsp_hdlr(void *msg);
extern void srv_wap_prof_save_mms_setting_rsp_hdlr(void *msg);
extern void srv_wap_prov_add_bookmark(U8 *name, U8 *url);
extern void srv_wap_prov_save_ota_mms_setting(srv_wap_prov_mms_setting_data_list_struct *data);
extern void srv_wap_prov_provisioning_ui_done(MMI_BOOL screen_exists);

extern void srv_wap_prov_set_srn_delete_status(srv_wap_prov_scrn_delete_status_enum delete_status);
extern void srv_wap_prov_reset_status(void);
void srv_wap_prof_prov_get_displayable_data(U8 *out_buffer, const S8* input_buffer, U8 input_dcs);

extern U32 srv_wap_prov_get_profile_count(void);
extern void srv_wap_prov_install_bookmark(srv_wap_prof_result_enum result);
extern void srv_wap_prov_app_continue_provisioning(void);
extern U8 srv_wap_prov_get_current_bkm_mms_index(void);
extern S16 srv_wap_prov_get_bkm_cnt(void);
extern S8 *srv_wap_prov_get_bm_title(S32 bkm_index);
extern srv_wap_prov_mms_setting_data_list_struct *srv_wap_prov_get_mms_setting_data(void);
extern srv_wap_prof_app_id_enum srv_wap_prov_get_app_id(void);
extern S8 *srv_wap_prov_get_bm_url(S32 bkm_index);
extern void srv_wap_prof_prov_dtcnt_ready_callback(void);
extern void srv_wap_prov_get_status_sent(MMI_BOOL *status_sent);
extern void srv_wap_prof_prov_reset_info_on_back(void);

extern srv_cca_status_enum srv_wap_prov_process_browser_nodes_callback(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        srv_cca_iterator_struct *iter_datalist,
                        void *user_data);

extern srv_cca_status_enum srv_prov_process_mms_nodes_callback(
                        S32 hConfig,
                        S32 hNode,
                        U16 node_symbol,
                        srv_cca_iterator_struct *iter_datalist,
                        void *user_data);

extern void srv_wap_prov_merge_proxy_application_node_list(void);

extern void srv_wap_prov_handle_proxy_params(
                srv_wap_prov_proxy_content_struct *proxy_content,
                srv_cca_core_data_struct *data);
extern void srv_wap_prov_browser_handle_application_params(
                srv_wap_prov_application_content_struct *application_content,
                srv_cca_core_data_struct *data);
extern void srv_wap_prov_browser_handle_resource_params(
                srv_wap_prov_application_content_struct *application_content,
                srv_cca_iterator_struct *iter_datalist);


extern void srv_wap_prov_fill_url_parm(
                srv_wap_prov_application_content_struct *app_node,
                srv_wap_prov_proxy_content_struct *proxy_node);
extern void srv_wap_prov_fill_other_parm(srv_wap_prov_proxy_content_struct *proxy_node);
extern void srv_wap_prov_fill_bookmark_parm(srv_wap_prov_application_content_struct *app_node);

extern void srv_wap_prov_free_proxy_app_nodes(void);
extern void srv_wap_prov_send_response(srv_cca_status_enum status, srv_cca_app_configure_ind_struct **cca_doc);

#ifdef SYNCML_DM_SUPPORT

extern srv_cca_status_enum srv_wap_prov_dm_handle_update_profile(S32 hConfig, srv_wap_prof_app_id_enum profile_type);
extern void srv_wap_prof_prov_send_cca_app_get_prof_rsp(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, srv_cca_status_enum result);
extern void srv_wap_prof_prov_send_cca_app_update_prof_rsp(U16 sim_id, U16 app_id, S32 prof_id, S32 hConfig, srv_cca_status_enum result);
extern S32 srv_wap_prof_prov_dm_contruct_doc(
	S8* profile_url,
	S32 prof_index,
	srv_cca_status_enum status,
	srv_wap_prof_app_id_enum app_id);

#endif /* SYNCML_DM_SUPPORT */ 

extern void srv_wap_prof_prov_init(void);
extern void srv_wap_prov_skip_profile(void);

extern void srv_wap_prov_handle_mms_setting_data(
                srv_wap_prov_application_content_struct *application_content,
                srv_cca_core_data_struct *data);

extern void srv_wap_prof_send_add_bookmark_ind(
                U8 *bookmark_name,
                U8 *url,
                srv_wap_prof_response_funcptr_type callback);



extern void srv_wap_prov_save_mms_setting_rsp_callback(srv_wap_prof_result_enum result);

extern void srv_wap_prov_add_bookmark_rsp_callback(srv_wap_prof_result_enum result);
extern void srv_wap_prov_install_setting(void);
extern MMI_BOOL srv_wap_prof_prov_process_job_sim_profile_status(
                    srv_wap_prof_sim_id_enum sim_id,
                    srv_wap_prof_app_id_enum app_id,
                    U32 prov_flag,
                    MMI_BOOL sim_status_chg_ind);


extern void srv_wap_prov_update_provisioning_response_to_cca(srv_wap_prof_prov_result_enum  status);
extern mmi_ret srv_wap_prof_prov_delete_info_scr_hdlr_callback(mmi_event_struct *param);

extern void srv_wap_prov_update_remaining_profile_count(void);
extern void srv_wap_prov_mem_allocate_prov_profile(void);
extern void srv_wap_prof_prov_mem_free_profile_list(void);









#endif /* WAP_SUPPORT */ 
#endif /* _WAPPROVISIONINGPROT_H */ 
#endif
