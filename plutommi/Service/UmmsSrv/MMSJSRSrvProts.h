/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * MMSJsrSrvProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file intends for handling the JSR messages.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _JSR_PROTS_H
#define _JSR_PROTS_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

/* if some header should be include before this one */
/***************************************************************************** 
* Define
*****************************************************************************/
/*
 * MMA and JSR interfaces and call back
 * MSG_ID_WAP_MMA_GET_MSG_LSIT_REQ     -> srv_mms_jsr_get_message_list_rsp
 * MSG_ID_WAP_MMA_GET_MSG_INFO_REQ     -> srv_mms_jsr_get_msg_info_rsp
 * MSG_ID_MMI_UM_GET_MSG_NUM_REQ   -> srv_mms_jsr_get_msg_num_rsp
 * MSG_ID_WAP_MMA_CREATE_REQ        -> srv_mms_jsr_create_message_rsp
 * MSG_ID_MMI_UM_REFRESH_IND
 * MSG_ID_WAP_MMA_DELETE_REQ        -> srv_mms_jsr_delete_mms_rsp
 * MSG_ID_WAP_MMA_CANCEL_SEND_REQ      -> srv_mms_jsr_cancel_send_mms_rsp   
 * MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ -> srv_mms_jsr_get_active_mms_attachment_req
 * MSG_ID_WAP_MMA_SEND_REQ          -> srv_mms_jsr_send_msg_rsp
 * MSG_ID_WAP_MMA_GET_CONTENT_REQ      -> srv_mms_jsr_get_msg_content_rsp
 */

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#include "MMSJSRSrvTypes.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "mmc_struct.h"
#include "MMIDataType.h"

extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);

extern void JsrCleanContext(void);
extern KAL_ADM_ID umms_get_kal_mem_id(void);

/* read folder */
extern void srv_mms_jsr_init(void);
extern void srv_mms_jsr_read_folder_status_req_hldr(void *msg, int mod_id);
extern void srv_mms_jsr_read_folder_status_output_req_hldr(
                mmc_result_enum result,
                JsrFolderInfo *folderInfo,
                int mod_id);
extern void srv_mms_jsr_fill_folder_info_output_req(void);

/* upload folder */
extern void srv_mms_jsr_upload_msg_req_hldr(void *msg, int mod_id);
extern void srv_mms_jsr_upload_msg_output_req_hldr(mmc_result_enum result, U32 msgId, int mod_id);

/* delete folder */
extern void srv_mms_jsr_delete_msg_req_hldr(void *msg, int mod_id);
extern void srv_mms_jsr_delete_msg_output_req_hldr(mmc_result_enum result, int mod_id);

extern void srv_mms_jsr_read_msg_path_req_hdlr(void *msgpathreq, int mod_id);
extern void srv_mms_jsr_read_msg_path_rsp(kal_uint32 msgId, kal_uint8 msg_path[], kal_uint8 result, int mod_id);

#ifdef __MMI_UMMS_JSR205__
extern MMI_BOOL srv_mms_jsr_mma_ready_ind_hdlr(void);
extern void srv_mms_jsr_mma_terminate_ind_hdlr(void);

/* send message */
extern void srv_mms_jsr_send_appmms_req_hldr(void *msg, int not_used, void *peerBuf);
extern void srv_mms_jsr_send_post_appmms_msg_part_ind(mmc_result_enum result, int mod_id);
extern void srv_mms_jsr_send_post_appmms_msg_part_rsp(void *msg, int mod_id);
extern void srv_mms_jsr_send_appmms_rsp(mmc_result_enum result, int mod_id);

/* receive message */
extern void srv_mms_jsr_receive_appmms_req_hldr(void *msg, int mod_id);
extern void srv_mms_jsr_receive_appmms_post_req_hldr(void *resp, S8 *buffer, U32 buffer_size, int mod_id);
extern void srv_mms_jsr_receive_appmms_rsp(
                wap_mmc_recv_appmms_rsp_struct *response_struct,
                S8 *buffer,
                U32 buffer_size,
                int mod_id);
extern void srv_mms_jsr_read_appmms_msg_part_req(void *msg, int mod_id);
extern void srv_mms_jsr_read_appmms_msg_part_rsp(wap_mmc_read_appmms_msg_part_rsp_struct *response, int mod_id);

/* abort reqest */
extern void srv_mms_jsr_abort_appmms_req(void *msg, int mod_id);
extern void srv_mms_jsr_abort_appmms_rsp(mmc_result_enum result, int mod_id);

/* profile req */
extern void srv_mms_jsr_get_mms_profile_req(void *msg, int mod_id);
extern void srv_mms_jsr_get_mms_profile_rsp(U8 result, U8 *value, U8 value_length, int mod_id);

/* configure app id */
extern void srv_mms_jsr_cfg_appmms_appid_req(void *msg, int mod_id);
extern void srv_mms_jsr_cfg_appmms_appid_rsp(mmc_result_enum result, int mod_id, int vm_id);
extern mmc_result_enum srv_mms_jsr_cfg_app_id(U8 *app_id, U8 app_id_length, U8 is_remove);

/* new message ind */
extern void srv_mms_jsr_send_appmms_new_mms_ind(U8 *appId, U32 length);

/* check app di message */
extern void srv_mms_jsr_check_appmms_coming_req(void *msg, int mod_id);
extern void srv_mms_jsr_check_appmms_coming_rsp(MMI_BOOL result, int mod_id);
extern MMI_BOOL srv_mms_jsr_check_appid_msgs(U8 *app_id, U8 app_id_length, U8 is_new);

/* add JAVA mms */
extern MMI_BOOL srv_mms_jsr_add_recv_java_mms_content(U32 msgId, U8 *contentType);
extern MMI_BOOL srv_mms_jsr_insert_msgId_to_appId_list(U32 msgId, U8 *appId, BOOL is_checked);
#endif /* __MMI_UMMS_JSR205__ */ 

/* generic functions */
extern void srv_mms_jsr_get_active_mms_attachment_req(void *in_msg, int mod_id);
extern MMI_BOOL srv_mms_jsr_get_file_name(S8 **const file_path, S8 const *const file_name);

extern void srv_mms_jsr_get_msg_list_req(void);
extern MMI_BOOL srv_mms_jsr_get_message_list_rsp(void *msgRsp);

extern void srv_mms_jsr_get_msg_info_req(void);
extern MMI_BOOL srv_mms_jsr_get_msg_info_rsp(void *msgRsp);

extern void srv_mms_jsr_create_mms_msg_req(kal_wchar *fname);
extern MMI_BOOL srv_mms_jsr_create_mms_msg_rsp(void *inMsg);

extern void srv_mms_jsr_um_refresh_ind(U32 folderID, U32 msg_id, U8 refresh_type);

extern void srv_mms_jsr_delete_msg_req(U32 folderId, U32 msgId);
extern MMI_BOOL srv_mms_jsr_delete_msg_rsp(void *delmsg);
extern MMI_BOOL srv_mms_jsr_delete_folder_rsp(void *delfolder);

extern void srv_mms_jsr_get_msg_num_req(void);
extern MMI_BOOL srv_mms_jsr_get_msg_num_rsp(void *msgRsp);

extern void srv_mms_jsr_post_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);

#ifdef __MMI_UMMS_JSR205__
extern void srv_mms_jsr_send_msg_req(U32 msg_id);
extern void srv_mms_jsr_send_msg_rsp(U32 msg_id, U8 result);
extern void srv_mms_jsr_update_send_msg_icon(U32 msg_id, U32 status);

extern void srv_mms_jsr_cancel_send_msg_req(void);
extern void srv_mms_jsr_cancel_send_msg_rsp(U8 result);

extern MMI_BOOL srv_mms_jsr_get_msg_content_rsp(void *msgRsp);

extern void srv_mms_jsr_read_object_list_from_file(void);
extern MMI_BOOL srv_mms_jsr_remove_msgId_from_appId_list(U32 msgId);
#endif /* __MMI_UMMS_JSR205__ */ 
extern S32 srv_mms_jsr_convert_phsuite_folder_to_jsr_folder(S32 folder);
extern S32 srv_mms_jsr_convert_um_folder_to_jsr_folder(S32 folder);

/* testing purpose */
extern void srv_mms_jsr_testing(void);
extern void srv_mms_init_jsr_folder(void);
extern void srv_mms_jsr_terminate_req_handler(void);
extern MMI_BOOL srv_mms_jsr_terminate_ind_handler(void);

#ifdef __MMI_UMMS_JSR205__
extern kal_bool srv_mms_jsr_check_jsr_in_sending_state(U8 sim_id);
extern mmc_result_enum srv_mms_jsr_translate_bgsr_to_mmc_result(U8 result);
extern kal_uint8 srv_mms_jsr_translate_mmc_sim_id_to_mma(kal_uint8 sim_id);
#endif /* __MMI_UMMS_JSR205__ */ 

#endif /* __MMI_MMS_2__ */ 
#endif /* _JSR_PROTS_H */ 

