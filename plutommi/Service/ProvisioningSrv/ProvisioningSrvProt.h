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
 * ProvisioningSrvProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   header file for internal API of ProvisioningSrv
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
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"
#ifndef _PROVISIONINGSRVPROT_H
#define _PROVISIONINGSRVPROT_H

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__

#include "ProvisioningSrvMain.h"
#include "ProvisioningSrvConfiguringSrc.h"

//------------------------------ suggest Add ------------------------------
#include "CcaSrvGprot.h"
#include "MMI_features.h"
#include "MMIDataType.h"
//------------------------------ usage ------------------------------

extern void srv_prov_cca_invalid_setting_ind_req(srv_cca_status_enum status);
/* extern void srv_prov_cca_new_setting_ind_req(void); USIM */
#ifndef __MMI_PROV_MESSAGE_SUPPORT__
extern void srv_prov_cca_new_setting_ind_req(U16 sim_id, S32 *trans_id);    /* USIM */
#endif
extern void srv_prov_free_memory(void);
extern SRV_PROV_RETCODE srv_prov_copy_utf8_str(U8 **dest_str, U8 *src_str) ;

#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__

extern void srv_prov_cca_ui_auth_req(srv_cca_status_enum status);
/* extern void srv_prov_cca_ui_auth_rsp_hdlr(void *msg); */
extern void srv_prov_convert_to_semi_octet(U8 *input, U8 *output);
extern void srv_prov_get_imsi_req(void);
extern U8 srv_prov_get_imsi_rsp_hdlr(void *msg);
extern void srv_prov_convert_ascii_mac_to_hex_mac(S8 *s_ascii_mac, S8 *s_hex_mac);
extern void srv_prov_handle_pin(S8 *s_pin);
extern S32 srv_prov_char_to_nibble(S8 c);

#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 

extern void srv_prov_cca_new_doc_ind_req(S32 hdoc_config);
extern SRV_PROV_RETCODE srv_prov_appauth_param_authlevel_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern void srv_prov_delete_queue_entry(void);
extern MMI_BOOL srv_prov_queue_is_not_empty(void);

extern SRV_PROV_RETCODE srv_prov_app_param_ma_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_app_param_cm_and_rm_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_napauthinfo_param_authentity_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_napdef_param_bearer_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_napdef_param_calltype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_port_param_service_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_proxy_param_ppgauth_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_proxy_param_pushpullenabled_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_proxy_param_pxaddrtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_param_addrtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_param_authtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_add_cca_characteristic_node(const S8 *tag_str, const S8 *tag_str_val, S32 node_id);
extern SRV_PROV_RETCODE srv_prov_add_cca_param_value(const S8 *tag_str, const S8 *tag_str_val);
extern SRV_PROV_RETCODE srv_prov_characteristic_root_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);

extern SRV_PROV_RETCODE srv_prov_characteristic_pxphysical_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_pxlogical_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_port_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_pxauthinfo_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_application_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_resource_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_appaddr_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_appauth_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_bootstrap_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_napdef_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_napauthinfo_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_validity_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_access_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_end_tag_hdlr(U8 cur_node_level);
extern SRV_PROV_RETCODE srv_prov_attach_node_to_sibling_node_list(S32 cur_node_h, S32 par_cca_node_h);
extern SRV_PROV_RETCODE srv_prov_add_nodedata_str_to_sibling_node_list(S32 cur_node_h, U16 cca_symbol, S8 *valuPtr);
extern SRV_PROV_RETCODE srv_prov_add_nodedata_int_to_sibling_node_list(S32 cur_node_h, U16 cca_symbol, S32 value);
extern SRV_PROV_RETCODE srv_prov_release_sibling_node_from_node_list(S32 *cur_node_h, SRV_PROV_RETCODE retCode);
extern SRV_PROV_RETCODE srv_prov_add_sibling_node_to_node_list(S32 cur_node_h, S32 node_h);
extern SRV_PROV_RETCODE srv_prov_application_param_tonapid_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern void srv_prov_remove_deprel_nodes(S32 cur_node_h);
extern SRV_PROV_RETCODE srv_prov_fix_cca_doc(S32 hroot, SRV_PROV_RETCODE retcode);
extern SRV_PROV_RETCODE srv_prov_create_dependency_relationship(S32 hroot, SRV_PROV_RETCODE retcode);
extern U16 srv_prov_get_enum_from_str_enum_table(
            U16 *attrValue,
            const srv_prov_convert_str_to_cca_enum_struct strEnumTable[]);

extern SRV_PROV_RETCODE srv_prov_root_end_tag_hdlr(SRV_PROV_RETCODE retcode);
extern SRV_PROV_RETCODE srv_prov_add_cca_nodeid(S32 crtHNode, U16 *charTagName);
extern SRV_PROV_RETCODE srv_prov_add_nodedata_enum_to_cca_node(S32 curccanode_h, U16 cca_symbol, S32 value);
extern SRV_PROV_RETCODE srv_prov_add_nodedata_int_to_cca_node(S32 curccanode_h, U16 cca_symbol, U16 *valuPtr);
extern SRV_PROV_RETCODE srv_prov_add_nodedata_str_to_cca_node(S32 curccanode_h, U16 cca_symbol, U16 *valuPtr);
extern SRV_PROV_RETCODE srv_prov_handle_unknown_characteristic_tag(
                            const S8 *tag_str,
                            const S8 *tag_str_val,
                            S32 node_id,
                            SRV_PROV_RETCODE retcode);
extern SRV_PROV_RETCODE srv_prov_check_dup_application_param_tonapid_value(U8 *attr_value);
extern void srv_prov_free_application_param_tonapid_value(void);
extern void srv_prov_handle_error(SRV_PROV_RETCODE i_ret);
extern void srv_prov_context_initialize(void);

extern SRV_PROV_RETCODE srv_prov_handle_provisioning_setting(void);

/* extern void srv_prov_cca_new_setting_rsp_hdlr(void *msg); */
/* extern void srv_prov_cca_new_doc_rsp_hdlr(void *msg); */
extern void srv_prov_start_setting_parser(void);
extern srv_prov_queue_data_struct **srv_prov_get_current_queue_data(void);

extern SRV_PROV_RETCODE srv_prov_handle_characteristic_end_tag_value(
                            const S8 *tag_str,
                            const S8 *tag_str_val,
                            S32 node_h);

#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)

extern SRV_PROV_RETCODE srv_prov_param_pxsip_codec_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_characteristic_pxsip_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_wifi_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_access_point_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_adhoc_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_wifi_profile_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);

#endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) */ 

#ifdef __PROV_NOKIA_OTA_SUPPORT__

extern SRV_PROV_RETCODE srv_prov_characteristic_ne_address_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_ne_url_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_ne_mmsurl_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_ne_bookmark_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_ne_id_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_characteristic_ne_name_tag_hdlr(
                            S32 *root,
                            srv_prov_characteristic_status_enum charac_status);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_sms_smsc_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_ussd_sevice_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_gprs_accesspoint_tag_hdlr(
                            U16 *attr_value,
                            S32 *root,
                            U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_ppp_authtype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_ppp_logintype_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_logintype_tag_hdlr(
                            U16 *attr_value,
                            S32 *root,
                            U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_ppp_authname_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_ppp_authsecret_tag_hdlr(
                            U16 *attr_value,
                            S32 *root,
                            U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_authname_tag_hdlr(
                            U16 *attr_value,
                            S32 *root,
                            U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_authsecret_tag_hdlr(
                            U16 *attr_value,
                            S32 *root,
                            U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_port_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_name_param_name_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_create_node_list(srv_prov_cca_ne_node_list_struct **head, S32 node_h);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_address_param_proxy_type_tag_hdlr(U16 *attr_value, S32 *root, U16 *ret_value);
extern SRV_PROV_RETCODE srv_prov_ne_post_parsing_operation(S32 root_h);

#endif /* __PROV_NOKIA_OTA_SUPPORT__ */ 

/* Common Items */
extern void srv_prov_init_adm(void);
extern void srv_prov_deinit_adm(void);
extern void *srv_prov_mem_alloc(U32 i_size);
extern void srv_prov_mem_free(void *ptr);
extern S32 srv_prov_get_char_occurence(const S8 *buffer, S32 ch, S32 index);
extern S32 srv_prov_index_of_char(S8 ch, const S8 *buffer, S32 start);
extern S32 srv_prov_check_if_substring(const S8 *string_p, const S8 *sub_string_p);

/* WBXML api */
extern SRV_PROV_RETCODE srv_prov_wbxml_parser_handler(void);


extern srv_prov_retcode_enum srv_prov_process_new_provisioning_message(PU16 filename, S32 action_type, PS8 mime_type_str_string, const S8* wap_addr);

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

extern void srv_prov_send_provbox_save_msg_req(U8 sim_id, PU16 filename, PS8 mime_type_str_string, const S8* wap_addr);
extern void srv_prov_send_provbox_get_msg_data_req(U32 msg_id);
extern void srv_prov_send_cca_source_install_prov_msg_cnf(U32 msg_id, S32 trans_id, U16 sim_id,
                        U8 prov_type, U32 prov_flag, srv_cca_status_enum status);

extern U8 srv_prov_provbox_save_msg_cnf_hdlr(void *msg);
extern U8 srv_prov_provbox_get_msg_data_cnf_hdlr(void *msg);
extern void srv_prov_cca_source_install_prov_msg_req_hdlr(void *msg);
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
#endif /* __PROVISIONING_SERVICE_SUPPORT__ */ 
#endif /* _PROVSERVICEPROT_H */ 

