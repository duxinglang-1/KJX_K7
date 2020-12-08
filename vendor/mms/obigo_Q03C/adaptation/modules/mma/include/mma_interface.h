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
 *   mma_interface.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file declares JTA modules thread related structures and definitions
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
#ifndef MMA_INTERFACE_H
#define MMA_INTERFACE_H

//#include "MMSMsgCommonProt.h"
/* Unified Message SAP */

#include "kal_general_types.h"
#include "kal_public_defs.h" 
#include "mma_api.h"
#include "mma_struct.h"
#include "MMI_features.h"
#include "UmSrvStruct.h"
#include "mms_adp_struct.h"
#include "stack_ltlcom.h" 
#include "mms_def.h"   
#include "mma_cfg.h"
extern void mms_mma_send_um_ready_ind(module_type dest_id, kal_bool result);
extern void mms_mma_send_um_new_msg_ind(
                module_type dest_id,
                kal_uint32 folder,
                kal_uint32 msg_id,
                kal_uint32 timestamp,
                kal_uint8  tone_id,
                kal_uint32 msg_sim_id);

extern void mms_mma_send_um_refresh_ind(module_type dest_id, mma_folder_enum folder_id);
extern void mms_mma_send_um_highlight_decide_by_um_ind(
                module_type dest_id,
                mma_folder_enum folder_id,
                kal_uint32 msg_index);
/* MMA SAP */
extern void mms_mma_send_cancel_send_rsp(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint32 msg_id,
                kal_uint8 result);
extern void mms_mma_send_send_rsp(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint32 msg_id,
                kal_uint8 result,
                char *response_text);
extern void mms_mma_send_start_immed_retrieval_ind(module_type dest, kal_uint32 msg_id, kal_uint8 sim_id);
extern void mms_mma_send_stop_immed_retrieval_ind(
                module_type dest,
                kal_uint32 msg_id,
                kal_uint8 result /* mma_result_enum */ ,
                kal_uint8 sim_id,
                kal_uint32 error_cause,
                kal_wchar *response_text /* Encoded by UCS2, max length is MMA_MAX_RESPONSE_TEXT_LENGTH */ );
extern void mms_mma_send_send_ind(
                module_type dest_id,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint32 msg_id,
                kal_uint8 retry,
                kal_uint8 percent,
                kal_uint8 sim_id);
extern void mms_mma_send_download_ind(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint32 msg_id,
                kal_uint8 retry,
                kal_uint8 percent,
                kal_uint32 bytes_received,
                kal_uint8 sim_id);
extern void mms_mma_send_download_rsp(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint32 msg_id,
                kal_uint32 new_msg_id,
                kal_uint8 result,
                char *response_text);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void mms_mma_send_set_app_data_rsp(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint32 msg_id,
                mma_result_enum result);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void mms_mma_send_cancel_download_rsp(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint32 msg_id,
                kal_uint8 result);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void mms_mma_send_set_readmark_rsp(
                module_type dst_id,
                kal_uint32 app_id,
                kal_uint32 req_id,
                mma_result_enum result);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void mms_mma_send_um_get_msg_num_rsp(
                module_type dest,
                kal_uint32 app_id,
                kal_bool result,
                /* KAL_TRUE means OK; KAL_FALSE means failed */ kal_uint16 msg_type,
                /* srv_um_msg_enum */ kal_uint16 inbox_unread_msg_number,
                kal_uint16 inbox_read_msg_number,
                kal_uint16 unsent_msg_number,
                kal_uint16 sent_msg_number,
                kal_uint16 draft_msg_number,
                kal_uint16 predefined_template_msg_number,
                kal_uint16 userdefined_template_msg_number,
                kal_uint16 archive_msg_number,
                kal_uint16 report_msg_number);
extern void mms_mma_send_um_get_list_rsp(
                module_type dest,
                kal_uint32 app_id,
                /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */ kal_bool result,
                /* KAL_TRUE means OK; KAL_FALSE means failed */ kal_uint32 msg_type,
                /* srv_um_msg_enum */ kal_uint32 msg_box_type,
                /* Type of message box srv_um_msg_box_enum */ kal_uint16 start_entry,
                kal_uint16 msg_number,
                /* Number of messages in this response primitive */ void *list_info,
                /* srv_um_msg_list_struct list_info[SRV_UM_MAX_GET_MSG_LIST_NUMBER] */ kal_bool more, /* If there are more msgs besides this response primitive */
                void* list_idx_data, kal_uint16 list_idx_type);

#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
extern void mms_mma_send_get_msg_num_rsp(
        module_type source,
        kal_uint32 app_id,
		kal_uint32 req_id,
        kal_bool result,
        wap_mma_get_msg_num_rsp_struct get_msg_num_rsp);
extern void mms_mma_send_get_msg_info_rsp(
                module_type source,
                kal_uint8 app_id,  /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */ 
                kal_uint8 result,  /* mma_result_enum */
                kal_uint32 req_id,
                kal_uint32 msg_id,
                kal_uint8 from_address_type, /* mma_addr_type_enum */ 
                kal_wchar *from_address, /* Encoded by USC2, MMA_MAX_ADDR_LEN */ 
                kal_wchar *subject,  /* Encoded by USC2, length is MMA_MAX_SUBJECT_LEN */
                kal_uint8 msg_type,  /* mma_msg_type_enum */ 
                kal_uint8 priority,  /* mma_priority_enum */ 
                kal_uint32 msg_size,
                kal_uint32 user_elements_size,
                kal_uint32 date,
                kal_uint32 expiry_date,
                kal_uint32 received_date,
                kal_bool need_read_report,
                kal_bool is_read,
                kal_bool is_forward_lock,
                /* When MMS contain any DRM forward-lock or combine-delivery object, the value is KAL_TRUE. Because sepertae-delivery DRM object can be forwarded. */ kal_bool is_drm,
                /* When MMS contain any DRM object, the value is KAL_TRUE */ 
                kal_bool is_follow_phone_mms_content_class,
                kal_bool has_attachment,
                kal_uint8 *app_data, /* kal_uint8   app_data[MMA_MAX_APP_DATA_LENGTH] */ 
                kal_uint8 *java_app_id,/* For JSR205  Encoded by ASCII, length is 100 */ 
                kal_uint8 *java_reply_app_id, /* For JSR205  Encoded by ASCII, , length is 100 */ 
                kal_uint8 msg_media_type, /* mma_media_msg_enum */
                kal_uint8 msg_storage,
                kal_uint8 msg_sim_id,
                kal_uint8 msg_class);
extern void mms_mma_send_get_msg_list_rsp(
                module_type source,
                kal_uint8 app_id,
                kal_uint8 result,
                kal_uint32 req_id,
                kal_uint32 no_of_msg,
                kal_uint32 *msg_id,
                kal_bool more);
#endif /* MMA_JSR_PST_MMS_OPERATON_SUPPORT */

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void mms_mma_send_delete_msg_rsp(
                module_type source,
                kal_uint8 app_id,
                kal_uint32 *result,
                kal_uint32 req_id,
                kal_uint32 *msg_id,
				kal_uint32 num_of_msg);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void mms_mma_send_delete_folder_rsp(
                module_type source,
                kal_uint32 app_id,
                kal_uint32 msg_type,
                /* srv_um_msg_enum */ kal_bool result);
extern void mms_mma_send_save_rsp(
                module_type source,
                kal_uint8 app_id,
                kal_uint32 *result,
                kal_uint32 req_id,
                kal_uint32 *msg_id,
				kal_uint32 num_of_msg);
extern void mms_mma_send_get_mem_status_rsp(
                module_type dst_id,
                kal_uint8 app_id,
                kal_uint32 req_id,
                mma_result_enum result,
                kal_uint32 used_size,
                kal_uint64 free_size);
extern void mms_mma_send_exit_usb_rsp(module_type dest);
extern void mms_mma_send_enter_usb_rsp(module_type dest);
extern void mms_mma_send_get_content_rsp(
                module_type dst_id,
                wap_mma_get_content_rsp_struct *para,
                kal_uint8 *xml_content);
extern void mms_mma_send_create_rsp(module_type dst_id, wap_mma_create_rsp_struct *para);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void mms_mma_send_get_msg_attr_and_thumbnail_info_rsp(
				module_type source,
				kal_uint8 app_id,
				kal_uint8 result,
				kal_uint32 req_id,
				kal_uint32 msg_id,
				wap_mma_get_mms_thumbnail_and_attr_info_struct *msg_info);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void mms_mma_send_set_profile_rsp(
                module_type dst_id,
                kal_uint8 app_id,
                kal_uint32 req_id,
                mma_result_enum result);
extern void mms_mma_send_set_mms_setting_rsp(module_type dst_id, kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result);
extern void mms_mma_send_get_setting_rsp(module_type source, wap_mma_get_setting_rsp_struct *get_setting_rsp_p);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void mms_mma_send_msg_is_valid_rsp(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint8 result,
                kal_uint8 *msg_validity_list,
                kal_uint16 *box_list);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void mms_mma_send_storage_full_ind(kal_uint8 result);
extern void mms_mma_send_notify_event_ind(module_type dest, kal_uint8 app_id, kal_uint16 event, void *event_info);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void mms_mma_send_get_unread_msg_list_rsp(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint8 result,
                kal_uint8 more,
                kal_uint32 total_num_of_unread_msg,
                kal_uint32 num_of_unread_msg,
                void *unread_msg_list);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void mms_mma_send_get_recent_evt_list_rsp(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint8 result,
                kal_uint8 more,
                kal_uint32 total_num_of_evt,
                kal_uint32 num_of_evt,
                void *event_list);
extern void mms_mma_send_delete_recent_evt_rsp(
                module_type dest,
                kal_uint8 app_id,
                kal_uint32 req_id,
                kal_uint8 result,
                kal_uint32 msg_id);

extern void mms_mma_send_mms_obj_rsp(module_type dest, kal_uint8 app_id, kal_uint32 req_id, kal_uint8 result);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void mms_mma_send_get_msg_property_rsp(
				module_type source,
				kal_uint8 app_id,
				kal_uint8 result,
				kal_uint32 req_id,
				kal_uint32 num_of_msg,
				mma_msg_property_struct *msg_property);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void mms_mma_send_um_get_msg_info_rsp(
		        module_type source,
		        kal_uint32 app_id,
		        kal_bool *result,
		        kal_uint32 *msg_id,
		        kal_uint32 msg_type,
		        kal_uint32 msg_box_type,
                kal_uint16 msg_number,
		        void *msg_info );
#ifdef __MMI_MMS_CONVERSATION_BOX_SUPPORT__
extern void mms_mma_send_um_get_conv_list_rsp(
                module_type dst_id,
                kal_uint32 app_id,
                kal_bool result,
                kal_uint16 msg_number,
                kal_bool more);
#endif
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void mms_mma_send_chg_mms_storage_rsp(module_type dst_id, kal_uint32 app_id, kal_uint32 req_id, kal_uint32 msg_id, kal_uint32 action_type, mma_result_enum result);
#endif
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void mms_mma_send_mark_rr_rsp(module_type dst_id, kal_uint32 app_id, kal_uint32 req_id, mma_result_enum result);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void MMAif_setProfile(module_type source, wap_mma_set_profile_req_struct *profile_req);
extern void MMAif_setSetting(module_type source, wap_mma_set_setting_req_struct *mms_mma_set_mms_setting_p);
extern void MMAif_getSetting(module_type source, wap_mma_get_setting_req_struct *get_setting_req);
extern void MMAif_sendMessage(module_type source, wap_mma_send_req_struct *mms_mma_send_req_p);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void MMAif_SetAppData(module_type source, wap_mma_set_app_data_req_struct *set_appdata_req);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void MMAif_cancelSendMessage(module_type source, wap_mma_cancel_send_req_struct *mms_mma_cancel_send_req_p);
extern void MMAif_downloadMessage(module_type source, wap_mma_download_req_struct *mms_mma_download_req_p);
extern void MMAif_downloadProgress(module_type source, wap_mma_download_res_struct *mms_mma_download_res_p);
extern void MMAif_cancelDownloadMessage(
                module_type source,
                wap_mma_cancel_download_req_struct *mms_mma_cancel_download_req_p);
extern void MMAif_sendProgressInd(void *progressData);
extern void MMAif_deleteFolder(module_type source, srv_um_delete_folder_req_struct *delete_folder_req);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void MMAif_deleteMsg(module_type source, wap_mma_delete_req_struct *delete_req);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void MMAif_getUmMsgNum(module_type source, srv_um_get_msg_num_req_struct *get_um_msg_num_req);
extern void MMAif_getUmMsgList(module_type source, srv_um_get_msg_list_req_struct *get_list_req);
extern void MMAif_getUmMsgInfo(module_type source, srv_um_get_msg_info_req_struct *get_um_msg_info_req);
#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
extern void MMAif_getMsgInfo(module_type source, wap_mma_get_msg_info_req_struct *get_msg_info_req);
extern void MMAif_getUmmsMsgNum(module_type source, wap_mma_get_msg_num_req_struct * get_msg_num_req);
extern void MMAif_getMsgList(module_type source, wap_mma_get_msg_list_req_struct *get_list_req);
#endif /* MMA_JSR_PST_MMS_OPERATON_SUPPORT */
extern void MMAif_getMemStatus(module_type source, wap_mma_get_mem_status_req_struct *get_mem_status_req);
extern void MMAif_saveMsg(module_type source, wap_mma_save_req_struct *save_req);
extern void MMAif_parseMsg(module_type source, wap_mma_get_content_req_struct *parse_req);
extern void MMAif_createMsg(module_type source, wap_mma_create_req_struct *create_req);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void MMAif_getMsgAttrTMBReq(module_type source, wap_mma_get_mms_thumbnail_and_attr_info_req_struct *get_msg_attr_tmb_p);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void MMAif_enterUSBMode(void);
extern void MMAif_exitUSBMode(void);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void MMAif_ValidateMsg(module_type source, wap_mma_msg_is_valid_req_struct *msg_is_valid_req);
extern void MMAif_SetReadmark(module_type source, wap_mma_set_readmark_req_struct *set_readmark_req);
extern void MMAif_getMsgProperty(module_type source, wap_mma_get_msg_property_req_struct *get_msg_property_p);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void MMAif_getUnreadMsgList(
                module_type source,
                wap_mma_get_unread_msg_list_req_struct *get_unread_msg_list_req);
extern void MMAif_getRecentEvtList(
                module_type source,
                wap_mma_get_recent_evt_list_req_struct *get_recent_evt_list_req);
extern void MMAif_deleteRecentEvt(module_type source, wap_mma_delete_recent_evt_req_struct *delete_recent_evt_req);
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
extern void MMAif_drmEncodeDone(module_type source, wap_mma_drm_encode_done_ind_struct *encode_done_p);
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
extern void MMAif_recvObjInd(module_type source, wap_mma_mms_obj_ind_struct *obj_ind_req);

extern char *MMAlib_getMessageFullPath(MSF_UINT32 msg_id);
extern char *MMAlib_getMessageInfoFullPath(MSF_UINT32 msg_id);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern kal_bool MMAlib_getMessageFullPathExt(MSF_UINT32 msg_id, char *dest, kal_uint32 dest_len);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern void MMAif_deleteMessage(mma_submodule_enum source, MSF_UINT32 msgId);
extern void MMAif_downloadRes(module_type source, wap_mma_download_res_struct *mms_mma_download_ind_res_p);
extern void MMAif_handle_target_dat_ind(module_type source, mms_target_data_ind_struct *target_data_ind_p, peer_buff_struct *peer_buffer_p);
extern void MMAif_freeContentMem(module_type source, wap_mma_free_content_info_struct *free_req);

#ifdef __MMI_VCARD__
extern void MMAif_isvcardrestricted(char *filepath, kal_uint32 size, kal_uint32 offset, kal_uint8 storage);
#endif // __MMI_VCARD__
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void MMAif_markRRStatus(module_type source, wap_mma_rr_mark_req_struct *mark_rr_req);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void MMAif_chgMsgStorage(module_type source, wap_mma_change_msg_storage_req_struct *chg_msg_storage);
extern void MMAif_handleMemCardPlugInReq(mms_mem_card_plug_in_out_struct *card_info);
extern void MMAif_handleMemCardPlugOutReq(mms_mem_card_plug_in_out_struct *card_info);
extern void MMAif_MemCradPlugOutRes(mma_result_enum result, mma_msg_storage_type_enum  card_enum);
extern void MMAif_MemCradPlugInRes(mma_result_enum result, mma_msg_storage_type_enum  card_enum);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__ 
extern void mma_send_fmt_format_rsp(kal_uint8 drive_enum);
extern void MMAif_SendFmtFormatInd(void *p);
#endif /* __MMI_FMGR_HIDE_FORMAT_DRIVE__ */
#ifdef __MMI_MMS_USE_ASM__
extern void MMAif_getAsmMemory(kal_uint32 req_id);
extern void MMAif_freeAsmMemory(void);
extern void MMAif_senddeinitasmMem(void);
extern void MMAif_asmMemRsp(/*wap_mma_get_asm_pool_rsp_struct*/void *get_asm_pool_rsp_struct);
extern void MMAif_deinitasmMem(/*wap_mma_get_deinit_asm_pool_req_struct*/void * deinit_asm_req_struct);
#endif /* __MMI_MMS_USE_ASM__ */
#ifdef __MMI_MMS_CONVERSATION_BOX_SUPPORT__
extern void MMAif_UMtraverseMmsList(module_type source, srv_um_traverse_msg_req_struct *um_traverse_list_req);
#endif
extern void mms_mma_send_insufficient_memory_ind(void);
extern void MMAif_SyncDeleteMsg(mms_sync_delete_msg_ind_struct *sync_delete_ind);
extern void MMAif_CopyMsgToArchive(module_type source, wap_mma_cpy_msg_to_archive_folder_req_struct *copy_msg_archive_req);
extern void mms_mma_send_copy_msg_to_archive_rsp(module_type dst_id, kal_uint32 app_id, kal_uint32 req_id, kal_uint32 msg_id, mma_result_enum result);
#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
extern void MMAif_mmsCheckTemplateRsp(wap_mma_check_template_rsp_struct *template_rsp);
#endif  /* __COSMOS_MMI_PACKAGE__ */
#endif /* MMA_INTERFACE_H */ 

