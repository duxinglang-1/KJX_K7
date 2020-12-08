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
 * MmsInterfaceSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

// #include "MMI_include.h"
#include "MMI_features.h"

#ifdef __MMI_MMS_2__

#include "mmi_inet_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"
#include "FileMgrSrvGProt.h"
#include "kal_trace.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "GlobalResDef.h"
#include "MmsSrvGprot.h"
#include "MmsSrvProt.h"
#include "MMSMemoryManagerSrv.h"
#include "MmsMsgParseSrv.h"
// #include "IdleAppDef.h"
#include "IdleNotificationManagerGprot.h"
// #include "inlineCuiGprot.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_sms_def.h"
#endif 
#include "UcSrvGprot.h"

#include "WAPProfileSrvGProt.h"
#include "WAPProfileSrvType.h"
#include "WAPprovisioningSrvType.h"

#include "Conversions.h"
#ifdef __MMI_MMS_SIM_USER_PREFERENCE_SUPPORT__
#include "SimAccessGprot.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#include "SimAccessSrvGProt.h"
#endif /* __MMI_MMS_SIM_USER_PREFERENCE_SUPPORT__ */ 
/* for save objects */
//#include "DLAgentDef.h"
//#include "fmt_struct.h"
//#include "MessagesResourceData.h"
//#include "MmsSrvExt.h"
#include "USBSrvGProt.h"
#include "mma_struct.h"
#include "ProfilesSrvGprot.h"
#include "phbsrvgprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#include "mma_api.h"
#include "mms_sap_struct.h"
#include "mmi_frm_mem_gprot.h"
// #include "app_buff_alloc.h"
#include "DebugInitDef_Int.h"
// #include "SimDetectionStruct.h"
#include "MmsXMLDefSrv.h"
#include "mmi_frm_nvram_gprot.h"
#include "DateTimeGprot.h"
#include "ProcedureGprot.h"
#include "nvram_common_defs.h"
#include "custom_mmi_default_value.h"
#include "custom_wap_config.h"
#include "MMI_features_switch.h"
#include "MMI_features_type.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "UcSrvGprot.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_srv_mms_def.h"
#include "mms_api.h"
#include "app_mine.h"
#include "DmSrvGprot.h" 
#include "FileMgrType.h"
#include "mms_adp_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_ltlcom.h" 

#include "kal_public_defs.h" 
#include "mms_adp.h"
#include "app_mem.h"
#include "CustDataRes.h"

#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "UmSrvDefs.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "MMSBGSRSrvProt.h"
#include "mmi_frm_utility_gprot.h"
#include "MMSTemplateGenSrv.h"
#include "MMSSrvSendRcv.h"
#include "App_str.h"
#define MMS_TMP_EXT_LEN 2

extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);

extern void srv_mms_immed_send_req(srv_mms_process_data_struct *process, srv_mms_immed_send_req_struct *para);

extern srv_mms_cntx_struct *g_srv_mms_cntx;
extern BOOL g_is_wap_ready;
extern U8 lite_req_counter;
srv_mms_read_nvram_settings_struct srv_settings_temp_context;
srv_mms_read_nvram_settings_struct *g_srv_mms_settings_context = &srv_settings_temp_context;
extern srv_mms_new_message_cntx_struct *g_srv_new_msg_cntx;
extern srv_mms_process_data_struct g_srv_immed_send;
static srv_mms_save_obj_req_struct g_srv_mms_save_obj_hdlr;

srv_mms_sim_context_struct srv_mms_sim_context_temp;
srv_mms_sim_context_struct *g_srv_mms_sim_context = &srv_mms_sim_context_temp;

static MMI_BOOL is_need_send_refresh;

#ifdef __MMI_MMS_SIM_USER_PREFERENCE_SUPPORT__
srv_mms_sim_settings_struct srv_sim_cntx;
srv_mms_sim_settings_struct *g_srv_sim_settings_cntx = &srv_sim_cntx;
#endif /* __MMI_MMS_SIM_USER_PREFERENCE_SUPPORT__ */ 
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
U8 nvram_mms_prefer_storage;
#endif 
U8 nvram_mms_msg_filter;

static srv_wap_prof_response_funcptr_type g_rsp_callback = NULL;

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
static srv_wap_prof_response_funcptr_type g_rsp_OTA_callback = NULL;
#endif /*__MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
MMI_BOOL refresh_profile_flag = MMI_FALSE;

extern srv_mms_dual_sim_struct *g_srv_dual_sim_cntx;

srv_mms_sync_msg_info_struct sync_msg_info_struct;
srv_mms_sync_msg_info_struct *g_sync_msg_info_struct = &sync_msg_info_struct;

typedef struct
{
    mmi_frm_proc_id_info_struct id_info;
} srv_mms_deinit_shutdown;
srv_mms_deinit_shutdown g_mmi_mms_deinit_cntx;

typedef void *(*umms_sync_op_mem_alloc_fn) (kal_uint32);
typedef void (*umms_sync_op_mem_free_fn) (void *);
extern mma_result_enum mma_mms_get_mms_msg_sync_info(
                        kal_uint32 msg_id,
                        wap_mma_get_mms_msg_info_struct *mms_msg_info,
                        umms_sync_op_mem_alloc_fn mem_alloc_fn,
                        umms_sync_op_mem_free_fn mem_free_fn);
extern kal_uint8 mma_get_mms_read_status(kal_uint32 msg_id);

#if(MMI_MAX_SIM_NUM >= 2)
extern mma_result_enum mma_mms_set_sim_status(kal_uint32 msg_id, kal_uint8 sim_id);
#endif 
extern mma_result_enum mma_mms_get_msg_folder_count(mma_mms_folder_mms_count_status_struct *count);
extern mma_result_enum mma_mms_delete_msg(kal_uint32 msg_id);
extern mma_result_enum mma_mms_move_msg_to_folder(kal_uint32 msg_id, kal_uint8 folder_id);
extern mma_result_enum mma_mms_set_read_status(kal_uint32 msg_id, kal_bool is_read);
extern mma_result_enum mma_mms_set_lock_status(kal_uint32 msg_id, kal_uint8 is_lock, kal_uint8 is_corrupt);
extern mma_result_enum mma_mms_get_mms_msg_thumbnail_info(
                        kal_uint32 msg_id,
                        wap_mma_get_mms_thumbnail_info_struct *mms_msg_info,
                        umms_sync_op_mem_alloc_fn mem_alloc_fn,
                        umms_sync_op_mem_free_fn mem_free_fn);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
extern mma_result_enum mma_mms_get_mms_msg_addr_info(
                        kal_uint32 msg_id,
                        mma_msg_addr_info_struct *mms_msg_addr_info,
                        umms_sync_op_mem_alloc_fn mem_alloc_fn,
                        umms_sync_op_mem_free_fn mem_free_fn);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#ifdef __MMI_MMS_SIM_USER_PREFERENCE_SUPPORT__
static void srv_mms_get_sim_mms_file_access_info_callback(srv_sim_cb_struct *callback_data);
static void srv_mms_get_sim_mms_user_pref_info_callback(srv_sim_cb_struct *callback_data);
#endif /* __MMI_MMS_SIM_USER_PREFERENCE_SUPPORT__ */ 
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
extern kal_uint16 mma_mms_get_unread_report_status(void);
extern mma_result_enum mma_mms_get_report_address(kal_uint32 report_id, mma_msg_addr_info_struct *addr);
#endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
extern mma_result_enum mma_mms_get_msg_report_status_info(
                        kal_uint32 msg_id,
                        wap_mma_mms_msg_report_status_struct *mms_msg_report_info,
                        umms_sync_op_mem_alloc_fn mem_alloc_fn,
                        umms_sync_op_mem_free_fn mem_free_fn);
#endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 
extern kal_bool mma_is_mms_corrupted(kal_uint32 msg_id);

srv_mms_sim_and_profile_context_struct sim_profile_data;
srv_mms_sim_and_profile_context_struct *srv_sim_profile_cntx = &sim_profile_data;
srv_mms_save_object_struct save_object_cntx;
srv_mms_save_object_struct *srv_save_object_cntx = &save_object_cntx;
static mmi_ret srv_mms_save_object_file_callback_proc(mmi_event_struct *msg);
static srv_mms_instance_context_struct g_srv_mms_main_instance[SRV_MMS_VIEWER_MAX_CONTAINER_SIZE];
static srv_mms_instance_context_struct *srv_mms_create_main_instance_with_index(U32 index);
static srv_mms_func_mem_alloc_user_data g_srv_mms_alloc_ext = NULL;
static void *srv_mms_alloc_ext(U32 size);
void *g_ext_user_data = NULL;
extern mma_result_enum mma_mms_get_msg_attribute(kal_uint32 msg_id, mma_sync_msg_attribute_struct *msg_attribute);
extern kal_uint8 mma_get_mms_storage(kal_uint32 msg_id);
extern kal_uint64 mma_get_mms_avaliable_file_space(kal_uint32 *usedBytes, U8 storage);
extern kal_bool mma_is_ascii_string(const char *str);
/*SLIM BGSR*/
extern BOOL srv_mms_slim_bgsr_send_mms_req( U32 sim_id, U32 msg_id, U32 storage_id, BOOL is_read_report);
extern U8 srv_mms_slim_bgsr_download_req(kal_uint8 sim_id, U32 msg_id, U8 storage_type,BOOL un_used);

/* To support XML Removal */
static MMI_BOOL srv_mms_address_data_hdlr(
                    mma_mms_description_header_struct *dst,
                    mma_mms_addr_list_struct *addr,
                    mma_mms_address_group_type_enum addr_group_type,
                    srv_mms_func_mem_alloc_user_data alloc_fn,
                    srv_mms_func_mem_free_user_data free_func,
                    void *user_data);
static char *srv_mms_create_name_from_nonascii_name(
                const char *name,
                U32 counter,
                srv_mms_func_mem_alloc_user_data alloc_fn,
                srv_mms_func_mem_free_user_data free_func,
                void *user_data);

#ifdef __MMI_MV_SUPPORT_REF_ID__

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
#define SRV_UC_INVALID_VALUE (0xFFFFFFFF)
#endif

static mma_mms_slide_ref_object_struct *srv_mms_insert_ref_obj_info_to_tail(
                                            mma_mms_description_body_struct *dst,
                                            mma_mms_slide_struct *slide,
                                            U32 id,
                                            U32 begin,
                                            U32 end,
                                            U32 bg_color,
                                            U32 fg_color,
                                            srv_mms_func_mem_alloc_user_data alloc_fn,
                                            srv_mms_func_mem_free_user_data free_fn,
                                            void *user_data);
#endif /* __MMI_MV_SUPPORT_REF_ID__ */ 


static mma_mms_object_struct *srv_mms_insert_object_to_list_tail(
                                mma_mms_description_body_struct *dst,
                                MMI_BOOL *is_duplicate,
                                U32 id,
                                srv_mms_func_mem_alloc_user_data alloc_fn,
                                srv_mms_func_mem_free_user_data free_fn,
                                void *user_data);

static U32 srv_mms_get_value_digit_number(U32 n);


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_get_msg_info
 * DESCRIPTION
 *  This function gets the detail single msg info from MMA
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_mma_get_msg_info_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_mma_get_msg_info(srv_mms_mma_get_msg_info_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    srv_mms_mma_get_msg_info_req_struct *req = (srv_mms_mma_get_msg_info_req_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);

    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->msg_id == 0) || (req->call_back == NULL))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }

    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_mma_get_msg_info_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_mma_get_msg_info_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_mma_get_msg_info_req(process, req);

    return SRV_MMS_RESULT_OK;
}

extern mma_result_enum mma_mms_get_msg_attribute(kal_uint32 msg_id, mma_sync_msg_attribute_struct *msg_attribute);


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_read_report_after_validation
 * DESCRIPTION
 *  This function sends read report of a MMS
 * PARAMETERS
 *  msg_id              [IN]        
 *  follow_settings     [IN]        
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  TRUE [if Read Report Sent Successfully]
 *  FALSE [o/w]
 *****************************************************************************/
MMI_BOOL srv_mms_send_read_report_after_validation(U32 msg_id, MMI_BOOL follow_settings)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    srv_mms_send_read_report_req_struct msgreq;
    mma_sync_msg_attribute_struct *msg_attr;
    
    MMI_BOOL is_valid_send = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_attr = srv_mms_mem_mgr_app_adm_alloc(sizeof(mma_sync_msg_attribute_struct));
    if (msg_attr == NULL)
    {
        return MMI_FALSE;
    }
    memset(msg_attr, 0, sizeof(mma_sync_msg_attribute_struct));
    mma_mms_get_msg_attribute(msg_id, msg_attr);
    is_valid_send = msg_attr->need_read_report;

    /* Verify Message Type */
    if (msg_attr->msg_type != MMA_MSG_TYPE_MMS)
    {
        is_valid_send = MMI_FALSE;
        goto ERROR;
    }
    /* Verify Box */
    if (msg_attr->folder != MMA_FOLDER_INBOX)
    {
        is_valid_send = MMI_FALSE;
        goto ERROR;
    }
    /* Verify Sender */
    if (!(((applib_is_valid_number_unicode((kal_wchar*) msg_attr->from_address))
           && (msg_attr->from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER))
          || ((applib_is_valid_email_address_unicode((kal_wchar*) msg_attr->from_address))
              && (msg_attr->from_address_type == MMA_ADDR_TYPE_EMAIL))))
    {
        is_valid_send = MMI_FALSE;
        goto ERROR;
    }
    /* Verify Settings */
    if (follow_settings == MMI_TRUE)
    {
        umms_read_report_enum rr_status = (umms_read_report_enum) srv_mms_retrieval_settings_read_report();

        if (rr_status != E_READ_REPORT_SEND_ALWAYS)
        {
            is_valid_send = MMI_FALSE;
            goto ERROR;
        }
    }
    /* Verify Sim */
    if (!srv_mms_is_sim_valid((mmi_sim_enum) msg_attr->msg_sim_id))
    {
        is_valid_send = MMI_FALSE;
        goto ERROR;
    }
  ERROR:
    if (is_valid_send)
    {
        /* send Read report */
        srv_mms_bgsr_set_rr_flag(msg_id);
        memset(&msgreq, 0, sizeof(srv_mms_send_read_report_req_struct));
        msgreq.sim_id = msg_attr->msg_sim_id;
        msgreq.msg_id = msg_id;
        msgreq.storage_location = msg_attr->msg_storage;
        srv_mms_send_read_report_req(&msgreq);
    }
    srv_mms_mem_mgr_app_adm_free(msg_attr);
    return is_valid_send;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_content
 * DESCRIPTION
 *  This function gets the detail single msg data from MMA
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_get_content_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_get_content(srv_mms_get_content_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_process_data_struct *process;
    srv_mms_get_content_req_struct *req = (srv_mms_get_content_req_struct*) para;
    srv_mms_get_content_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->msg_id == 0) || (req->call_back == NULL))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }

    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_get_content_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_get_content_rsp_struct));

    process->cntx = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_get_content_cntx_struct));
    if (NULL == process->cntx)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->cntx, 0, sizeof(srv_mms_get_content_cntx_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    cntx = process->cntx;
    cntx->mode = req->mode;
    cntx->creation_mode = req->creation_mode;

    srv_mms_get_content_info_req(process, req);

    return SRV_MMS_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_num
 * DESCRIPTION
 *  This function gets the MMS number information for various Folders as requested from MMA
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_get_msg_num_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_get_msg_num(srv_mms_get_msg_num_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_msg_num_req_struct *req = (srv_mms_get_msg_num_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }

    if (req->call_back == NULL)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }

    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof
                                                    (   /* srv_mms_mma_get_msg_info_rsp_struct */
                                                     srv_mms_get_msg_num_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_get_msg_num_rsp_struct /* srv_mms_mma_get_msg_info_rsp_struct */ ));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_get_msg_num_req(process, req);

    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_readmark
 * DESCRIPTION
 *  This function set the MMS read/unread status
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_set_readmark_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_set_readmark(srv_mms_set_readmark_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_set_readmark_req_struct *req = (srv_mms_set_readmark_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->msg_id == 0) || (req->call_back == NULL))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_set_readmark_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_set_readmark_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_set_readmark_req(process, req);

    return SRV_MMS_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save
 * DESCRIPTION
 *  This function moves a number of MMS from current folder to specified folder
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_save_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_save(srv_mms_save_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_save_req_struct *req = (srv_mms_save_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->call_back == NULL) || (req->no_of_msg == 0) || (req->no_of_msg > MMA_MAX_MSG_ARRAY_NUM))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_save_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_save_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_save_req(process, req);

    return SRV_MMS_RESULT_OK;

}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete
 * DESCRIPTION
 *  This function deletes a number of MMS
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_delete_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_delete(srv_mms_delete_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_req_struct *req = (srv_mms_delete_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->call_back == NULL) || (req->no_of_msg == 0) || (req->no_of_msg > MMA_MAX_MSG_ARRAY_NUM))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_delete_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_delete_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_delete_req(process, req);

    return SRV_MMS_RESULT_OK;

}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_unread_msg_list
 * DESCRIPTION
 *  This function gets unread MMS list from MMA
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_get_unread_msg_list_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_get_unread_msg_list(srv_mms_get_unread_msg_list_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_unread_msg_list_req_struct *req = (srv_mms_get_unread_msg_list_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->call_back == NULL) || (req->num_of_msg_requested == 0))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_get_unread_msg_list_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_get_unread_msg_list_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_get_unread_msg_list_req(process, req);

    return SRV_MMS_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_property_list
 * DESCRIPTION
 *  This function gets Msg property list from MMA
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_property_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_get_msg_property_list(srv_mms_property_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_property_req_struct *req = (srv_mms_property_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->call_back == NULL) || (req->no_of_msg == 0))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_property_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_property_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_get_msg_property_list_req(process, req);

    return SRV_MMS_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_recent_evt_list
 * DESCRIPTION
 *  This function gets recenet event list from MMA
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_recent_evt_list_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_get_recent_evt_list(srv_mms_recent_evt_list_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_recent_evt_list_req_struct *req = (srv_mms_recent_evt_list_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if (req->call_back == NULL || (req->num_of_evt_requested == 0))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_recent_evt_list_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_recent_evt_list_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_get_recent_evt_list_req(process, req);

    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_recent_event
 * DESCRIPTION
 *  This function deletes recent event
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_delete_recent_evt_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_delete_recent_event(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_recent_evt_req_struct *req = (srv_mms_delete_recent_evt_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->msg_id == 0) || (req->call_back == NULL))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_delete_recent_evt_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_delete_recent_evt_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_delete_recent_event_req(process, req);

    return SRV_MMS_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_obj_ind
 * DESCRIPTION
 *  This function sends object indication to MMA
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_obj_ind_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_send_obj_ind(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_obj_ind_struct *req = (srv_mms_obj_ind_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->call_back == NULL) || (req->mms_filepath[0] == 0))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_obj_res_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_obj_res_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_send_obj_ind_req(process, req);

    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_create
 * DESCRIPTION
 *  This function creates new MMS
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_create_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_create(srv_mms_create_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_create_req_struct *req = (srv_mms_create_req_struct*) para;
    srv_mms_create_cntx_struct *cntx;
    srv_mms_process_data_struct *process;

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    CHAR str_null[MMA_MAX_INTERNAL_FILENAME_LENGTH];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->call_back == NULL))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    if ((req->op_type == SRV_MMS_CREATE_SAVE_MMS) || (req->op_type == SRV_MMS_CREATE_SAVE_TEMPLATE_MMS))
    {
        process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_save_rsp_struct));
    }
    else
    {
        process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_create_rsp_struct));
    }
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    if ((req->op_type == SRV_MMS_CREATE_SAVE_MMS) || (req->op_type == SRV_MMS_CREATE_SAVE_TEMPLATE_MMS))
    {
        memset(process->result, 0, sizeof(srv_mms_save_rsp_struct));
    }
    else
    {
        memset(process->result, 0, sizeof(srv_mms_create_rsp_struct));
    }

    process->cntx = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_create_cntx_struct));
    if (NULL == process->cntx)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->cntx, 0, sizeof(srv_mms_create_cntx_struct));
    cntx = process->cntx;

    process->call_back = req->call_back;
    process->user_data = req->user_data;

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    memset(str_null, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
#endif

    cntx->xml_size = req->xml_size;
    cntx->mode = req->mode;
    cntx->sim_id = req->sim_id;
    cntx->op_type = req->op_type;

    mmi_ucs2ncpy((S8*) cntx->xml_filepath, (S8*) req->xml_filepath, MMA_MAX_INTERNAL_FILENAME_LENGTH);

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    if (mmi_ucs2ncmp((CHAR*) cntx->xml_filepath, (CHAR*) str_null, MMA_MAX_INTERNAL_FILENAME_LENGTH) != 0)
    {
        /*OVERWRITE MODE*/
        cntx->mode = MMA_MODE_VENDOR_XML;
        req->mode = MMA_MODE_VENDOR_XML;
    }
#endif
    srv_mms_create_req(process, req);

    return SRV_MMS_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_all
 * DESCRIPTION
 *  This function deletes all MMS of a folder
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_delete_all_ind_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_delete_all(srv_mms_delete_all_ind_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_all_ind_struct *req = (srv_mms_delete_all_ind_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->msg_type == 0) || (req->call_back == NULL) || (req->msg_box_type == 0))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_delete_all_res_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_delete_all_res_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;
    process->app_id = MMA_APP_ID_MMS_APP;

    srv_mms_delete_all_req(process, req);

    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_folder
 * DESCRIPTION
 *  This function deletes all MMS of a folder
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_delete_folder_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_delete_folder(srv_mms_delete_folder_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_folder_req_struct *req = (srv_mms_delete_folder_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->msg_type == 0) || (req->call_back == NULL) || (req->msg_box_type == 0))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_delete_folder_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_delete_folder_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;
    process->app_id = req->app_id;

    srv_mms_delete_folder_req(process, req);

    return SRV_MMS_RESULT_OK;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_mark_several_screen
 * DESCRIPTION
 *  This function enters Mark Several screen asynchronously
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_delete_all_ind_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_entry_mark_several_screen(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_entry_mark_several_req_struct *req = (srv_mms_entry_mark_several_req_struct*) para;
    srv_mms_process_data_struct *process = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->call_back == NULL) || (req->msg_type == 0) || (req->msg_box_type == 0))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    /*
     * process = srv_mms_get_process_slot();
     * if(NULL == process)
     * {
     * return SRV_MMS_RESULT_MAX_SRV_REACHED;
     * }
     * process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_entry_mark_several_rsp_struct));
     * if(NULL == process->result)
     * {
     * return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
     * }
     * memset(process->result, 0, sizeof(srv_mms_entry_mark_several_rsp_struct));
     * 
     * process->call_back = req->call_back;
     * process->user_data = req->user_data;
     * process->app_id = req->app_id;
     */
    srv_mms_entry_mark_several_req(process, req);

    return SRV_MMS_RESULT_OK;
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_refresh_msg_list
 * DESCRIPTION
 *  This function refreshes UM Msg List
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_um_refresh_ind_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_um_refresh_msg_list(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_um_refresh_ind_struct *req = (srv_mms_um_refresh_ind_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }

    if (req->msg_box_type == 0)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }
    srv_mms_um_refresh_msg_ind(req);
    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_show_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_show_status_icon(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_msg_update_count_and_status_icon();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_cntx->is_srv_ready = MMI_TRUE;

    /* No srv name is because of browser and some other app call this api */
    /* below is ths code for sim_settings will be placed under mmi_umms_init****** */
#ifdef __MMI_MMS_SIM_USER_PREFERENCE_SUPPORT__
    srv_mms_set_sim_mms_settings();
#endif 
    /* srv_mms_get_number_status_icon(); */
    srv_mms_msg_update_count_and_status_icon();

    /*Default Template Initialization*/
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    srv_mms_init_default_templates();
#endif
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_current_mms_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  boot_up     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_current_mms_profile(MMI_BOOL boot_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (boot_up == FALSE)
    {
    
        srv_mms_set_current_profile_req();
    }
    else
    {
        srv_mms_set_current_profile_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_current_profile_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_current_profile_req(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_profile_content_struct *profile_struct;
    U8 mma_sim_id = MMA_SIM_ID_SIM1;

    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* body starts here */

    for (i = 0, mma_sim_id = MMA_SIM_ID_SIM1; i < MMI_SIM_TOTAL; i++, mma_sim_id = mma_sim_id << 1)
    {
        profile_struct = NULL;
        if (srv_mms_is_sim_valid((mmi_sim_enum) mma_sim_id))
        {
            profile_struct =
                (srv_wap_prof_profile_content_struct*) srv_wap_prof_get_profile_content(
                                                        (srv_wap_prof_sim_id_enum) (SRV_WAP_PROF_SIMID_SIM1 + i),
                                                        SRV_WAP_PROF_APPID_MMS,
                                                        (U8) - 1,
                                                        SRV_WAP_PROF_DTCNT_PRIMARY,
                                                        srv_mms_get_active_profile_rsp_callback);
        }

        if (profile_struct)
        {
            refresh_profile_flag = MMI_TRUE;
        #if(MMI_MAX_SIM_NUM >= 2)
            mma_sim_id = srv_mms_convert_wap_sim_id_to_mma_sim_id((srv_wap_prof_sim_id_enum) (SRV_WAP_PROF_SIMID_SIM1 + i));
        #endif 
            srv_mms_set_current_profile_req_by_data(profile_struct, mma_sim_id);
            srv_mms_set_profile_flag((mmi_sim_enum)mma_sim_id);

            OslMfree(profile_struct);
            profile_struct = NULL;

        }
    }
 

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_wap_sim_id_to_mma_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_convert_wap_sim_id_to_mma_sim_id(srv_wap_prof_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case SRV_WAP_PROF_SIMID_SIM1:
            return MMA_SIM_ID_SIM1;
            
    #if(MMI_MAX_SIM_NUM >= 2)
        case SRV_WAP_PROF_SIMID_SIM2:
            return MMA_SIM_ID_SIM2;
            
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 1)) */
    #if(MMI_MAX_SIM_NUM >= 3)
        case SRV_WAP_PROF_SIMID_SIM3:
            return MMA_SIM_ID_SIM3;
            
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
    #if(MMI_MAX_SIM_NUM >= 4)
        case SRV_WAP_PROF_SIMID_SIM4:
            return MMA_SIM_ID_SIM4;
            
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
        default:
            return 0;
            
    }

}




/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_active_profile_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id                  [IN]        
 *  profile_content_p       [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_active_profile_rsp_callback(
        srv_wap_prof_sim_id_enum sim_id,
        srv_wap_prof_profile_content_struct *profile_content_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mma_sim_id = MMA_SIM_ID_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(profile_content_p);
    refresh_profile_flag = MMI_TRUE;
#if(MMI_MAX_SIM_NUM >= 2)
    mma_sim_id = srv_mms_convert_wap_sim_id_to_mma_sim_id(sim_id);
#endif 
    srv_mms_set_current_profile_req_by_data(profile_content_p, mma_sim_id);
    OslMfree(profile_content_p);
    profile_content_p = NULL;
}




/*****************************************************************************
 * FUNCTION
 *  srv_mms_active_mms_profile_change_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profile_content_p       [?]         [?]         [?]
 *  sim_id                  [IN]        
 *  callback                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_active_mms_profile_change_hdlr(
        srv_wap_prof_profile_content_struct *profile_content_p,
        srv_wap_prof_sim_id_enum sim_id,
        srv_wap_prof_response_funcptr_type callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mma_sim_id = MMA_SIM_ID_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(profile_content_p);
    g_rsp_callback = callback;
#if(MMI_MAX_SIM_NUM >= 2)
    mma_sim_id = srv_mms_convert_wap_sim_id_to_mma_sim_id(sim_id);
#endif 
    srv_mms_set_current_profile_req_by_data(profile_content_p, mma_sim_id);
    OslMfree(profile_content_p);
    profile_content_p = NULL;
}




/*****************************************************************************
 * FUNCTION
 *  srv_mms_recieved_set_profile_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inmsg       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_recieved_set_profile_response(void *inmsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_profile_rsp_struct *set_profile_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_profile_rsp = (wap_mma_set_profile_rsp_struct*) inmsg;
    if (set_profile_rsp->app_id == MMA_APP_ID_MMS_APP)
    {
        return;
    }

    if (g_rsp_callback)
    {
        if (set_profile_rsp->result != MMA_RESULT_OK)
        {
            g_rsp_callback(SRV_WAP_PROF_ERR);
        }
        else
        {
            g_rsp_callback(SRV_WAP_PROF_SUCCESS);
        }
    }

}

/* cant change the name as called by mmsadp.c file : */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_refresh_profile_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_refresh_profile_settings(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_wap_prof_profile_content_struct *profile_struct = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (sim_id == MMI_SIM1)
    {
        profile_struct =
            (srv_wap_prof_profile_content_struct*) srv_wap_prof_get_profile_content(
                                                    SRV_WAP_PROF_SIMID_SIM1,
                                                    SRV_WAP_PROF_APPID_MMS,
                                                    (U8) - 1,
                                                    SRV_WAP_PROF_DTCNT_PRIMARY,
                                                    NULL);
    }

#if(MMI_MAX_SIM_NUM >= 2)
    if (sim_id == MMI_SIM2)
    {
        profile_struct =
            (srv_wap_prof_profile_content_struct*) srv_wap_prof_get_profile_content(
                                                    SRV_WAP_PROF_SIMID_SIM2,
                                                    SRV_WAP_PROF_APPID_MMS,
                                                    (U8) - 1,
                                                    SRV_WAP_PROF_DTCNT_PRIMARY,
                                                    NULL);
    }

#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS == 2)) */

#if(MMI_MAX_SIM_NUM >= 3)
    if (sim_id == MMI_SIM3)
    {
        profile_struct =
            (srv_wap_prof_profile_content_struct*) srv_wap_prof_get_profile_content(
                                                    SRV_WAP_PROF_SIMID_SIM3,
                                                    SRV_WAP_PROF_APPID_MMS,
                                                    (U8) - 1,
                                                    SRV_WAP_PROF_DTCNT_PRIMARY,
                                                    NULL);
    }
#endif /* (MMI_MAX_SIM_NUM >= 3) */ 

#if(MMI_MAX_SIM_NUM >= 4)
    if (sim_id == MMI_SIM4)
    {
        profile_struct =
            (srv_wap_prof_profile_content_struct*) srv_wap_prof_get_profile_content(
                                                    SRV_WAP_PROF_SIMID_SIM4,
                                                    SRV_WAP_PROF_APPID_MMS,
                                                    (U8) - 1,
                                                    SRV_WAP_PROF_DTCNT_PRIMARY,
                                                    NULL);
    }
#endif /* (MMI_MAX_SIM_NUM >= 4) */ 



    MMI_ASSERT(profile_struct);
    if (profile_struct)
    {
        refresh_profile_flag = MMI_TRUE;
        srv_mms_set_current_profile_req_by_data(profile_struct, sim_id);

        OslMfree(profile_struct);
        profile_struct = NULL;
    
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_refresh_profile_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_refresh_profile_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    refresh_profile_flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_refresh_profile_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_refresh_profile_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return refresh_profile_flag;
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_send_ota_mms_settings_rsp_to_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_check_send_ota_mms_settings_rsp_to_profile(void *rsp_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_set_settings_rsp_struct *response_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    response_result = (srv_mms_mma_set_settings_rsp_struct*) rsp_data;


    if (g_rsp_OTA_callback)
    {
        if (response_result->result == MMA_RESULT_OK)
        {
            g_rsp_OTA_callback(SRV_WAP_PROF_SUCCESS);
            g_rsp_OTA_callback = NULL;
        }
        else
        {
            g_rsp_OTA_callback(SRV_WAP_PROF_ERR);
            g_rsp_OTA_callback = NULL;
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;

}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_mms_sim_availability_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 *  inMsg       [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_mms_sim_availability_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_sim_ctrl_availability_changed_evt_struct *event_data = (srv_sim_ctrl_availability_changed_evt_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_SIM_AVAILABILITY,
        event_data->sim,
        event_data->is_available_before,
        event_data->is_available_now);
    if (event_data->is_available_before == MMI_TRUE && event_data->is_available_now == MMI_FALSE)
    {
        srv_mms_reset_sim_valid_flag(event_data->sim);
        srv_mms_free_all_sim_related_object_handler_node(event_data->sim);
    }

    if (event_data->is_available_before == MMI_FALSE && event_data->is_available_now == MMI_TRUE &&
        (srv_mode_switch_get_current_mode() & event_data->sim))
    {
        srv_mms_set_sim_valid_flag(event_data->sim);
        srv_mms_init_object_ind_sim_data((U8) event_data->sim);
    }

    srv_mms_send_events(EVT_ID_SRV_HDL_CARD_PLUG_OUT, NULL);

    srv_mms_refresh_profile();

    return MMI_RET_OK;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_power_off
 * DESCRIPTION
 *  This function creates new MMS
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_create_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_power_off(srv_mms_power_off_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_power_off_req_struct *req = (srv_mms_power_off_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }

    if (req->call_back == NULL)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_power_off_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_power_off_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;

    srv_mms_power_off_req(process, req);

    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_use_details_for_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_get_use_details_for_slide(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_use_details_viewer_req_struct *req = (srv_mms_get_use_details_viewer_req_struct*) para;
    srv_mms_process_data_struct *process = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        return SRV_MMS_RESULT_NOT_READY;
    }

    if (req->call_back == NULL)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }
    process = srv_mms_get_process_slot();

    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_get_use_details_viewer_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_get_use_details_viewer_rsp_struct));
    process->call_back = req->call_back;
    process->user_data = req->user_data;

    if (srv_mms_get_use_details_for_slide_ext(process, req) == MMI_TRUE)
    {
        return SRV_MMS_RESULT_NEED_LEAVE_TIMER;
    }

    return SRV_MMS_RESULT_OK;
}

#if(MMI_MAX_SIM_NUM >= 2)


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_dual_sim_struct *srv_mms_get_sim_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_dual_sim_cntx;
}

#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 2)) */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_read_nvram_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_read_nvram_settings(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_srv_mms_settings_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);
    if (g_srv_mms_settings_context->nvram_compose_settings.creation_mode == 0xFF)
    {
        g_srv_mms_settings_context->nvram_compose_settings.creation_mode = (U8) E_CREAT_MODE_FREE;
    }

    if (g_srv_mms_settings_context->nvram_compose_settings.layout == 0xFF)
    {
        g_srv_mms_settings_context->nvram_compose_settings.layout = (U8) E_PICTURE_RESIZE_50KB;
    }

    WriteRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_srv_mms_settings_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);

    ReadRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_srv_mms_settings_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);

    /* supply default values */
#if 0
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_MMS_SIGNATURE__
/* under construction !*/
    #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifndef __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__
/* under construction !*/
    #else 
/* under construction !*/
    #endif 
/* under construction !*/
    #ifdef __DRM_SUPPORT__
/* under construction !*/
    #endif 
/* under construction !*/
    #ifdef __MMI_MMS_SIGNATURE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifndef __MMI_SLIM_MMS_2__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif
    #endif /* __MMI_MMS_SIGNATURE__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    ReadRecord(
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
        1,
        &g_srv_mms_settings_context->nvram_sending_settings,
        NVRAM_UMMS_SENDING_SETTINGS_SIZE,
        &error);

    if (g_srv_mms_settings_context->nvram_sending_settings.send_and_save == 0XFF)
    {
    #ifdef __MMI_MMS_CONVERSATION_BOX_SUPPORT__
        g_srv_mms_settings_context->nvram_sending_settings.send_and_save = (U8) E_ON;
    #else 
        g_srv_mms_settings_context->nvram_sending_settings.send_and_save = (U8) E_OFF;
    #endif 

        WriteRecord(
            NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
            1,
            &g_srv_mms_settings_context->nvram_sending_settings,
            NVRAM_UMMS_SENDING_SETTINGS_SIZE,
            &error);
        ReadRecord(
            NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
            1,
            &g_srv_mms_settings_context->nvram_sending_settings,
            NVRAM_UMMS_SENDING_SETTINGS_SIZE,
            &error);

    }

    if (g_srv_mms_settings_context->nvram_sending_settings.delivery_report == 0xFF)
    {
        g_srv_mms_settings_context->nvram_sending_settings.deadline_for_reply = (U32) 0;
        g_srv_mms_settings_context->nvram_sending_settings.delivery_report =
            (U8) UMMS_DEFAULT_DELIVERY_REPORT_DURING_SENDING;
        g_srv_mms_settings_context->nvram_sending_settings.delivery_time = (U8) E_IMMEDIATE;
        g_srv_mms_settings_context->nvram_sending_settings.hide_sender = (U8) E_OFF;
        g_srv_mms_settings_context->nvram_sending_settings.send_and_save = (U8) E_OFF;
        g_srv_mms_settings_context->nvram_sending_settings.priority = (U8) E_PRIORITY_NORMAL;
        g_srv_mms_settings_context->nvram_sending_settings.read_report = (U8) UMMS_DEFAULT_READ_REPORT_DURING_SENDING;
        g_srv_mms_settings_context->nvram_sending_settings.reply_charging = (U8) E_OFF;
        g_srv_mms_settings_context->nvram_sending_settings.request_type = (U8) E_FULL_MMS;
    #ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
        g_srv_mms_settings_context->nvram_sending_settings.size = (U8) E_SENDING_SIZE_LIMIT_300;
    #else 
        g_srv_mms_settings_context->nvram_sending_settings.size = (U32) 0;
    #endif 
        g_srv_mms_settings_context->nvram_sending_settings.validity_period = (U8) E_VALIDITY_PERIOD_MAX;

        WriteRecord(
            NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
            1,
            &g_srv_mms_settings_context->nvram_sending_settings,
            NVRAM_UMMS_SENDING_SETTINGS_SIZE,
            &error);
        ReadRecord(
            NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
            1,
            &g_srv_mms_settings_context->nvram_sending_settings,
            NVRAM_UMMS_SENDING_SETTINGS_SIZE,
            &error);
    }

    ReadValue(NVRAM_UMMS_RETRIEVAL_SETTINGS, &g_srv_mms_settings_context->nvram_retrieval_settings, DS_DOUBLE, &error);
    if (g_srv_mms_settings_context->nvram_retrieval_settings.home_network == 0xFF)
    {
    #ifdef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
        g_srv_mms_settings_context->nvram_retrieval_settings.home_network = (U8) E_ON;
        g_srv_mms_settings_context->nvram_retrieval_settings.read_report = (U8) E_OFF;
        g_srv_mms_settings_context->nvram_retrieval_settings.delivery_report = (U8) E_OFF;
        g_srv_mms_settings_context->nvram_retrieval_settings.roaming = (U8) E_ON;
    #elif defined(__MMI_OP12_MMS_SUPPORT_SETTINGS__)
        g_srv_mms_settings_context->nvram_retrieval_settings.home_network = (U8) E_ON;
        g_srv_mms_settings_context->nvram_retrieval_settings.read_report =
            (U8) UMMS_DEFAULT_READ_REPORT_DURING_RETRIEVAL;
        g_srv_mms_settings_context->nvram_retrieval_settings.delivery_report = (U8) E_ON;
        g_srv_mms_settings_context->nvram_retrieval_settings.roaming = (U8) E_ON;

    #else 
        g_srv_mms_settings_context->nvram_retrieval_settings.home_network = (U8) UMMS_DEFAULT_HOME_RETRIEVAL_MODE;
        g_srv_mms_settings_context->nvram_retrieval_settings.read_report =
            (U8) UMMS_DEFAULT_READ_REPORT_DURING_RETRIEVAL;
        g_srv_mms_settings_context->nvram_retrieval_settings.delivery_report =
            (U8) UMMS_DEFAULT_DELIVERY_REPORT_DURING_RETRIEVAL;
        g_srv_mms_settings_context->nvram_retrieval_settings.roaming = (U8) UMMS_DEFAULT_ROAMING_RETRIEVAL_MODE;

    #endif 
        g_srv_mms_settings_context->nvram_retrieval_settings.anonymous_filter =
            (U8) UMMS_DEFAULT_ADVERTISEMENT_FILTER_VALUE;
        g_srv_mms_settings_context->nvram_retrieval_settings.advertisement_filter =
            (U8) UMMS_DEFAULT_ADVERTISEMENT_FILTER_VALUE;

        WriteValue(
            NVRAM_UMMS_RETRIEVAL_SETTINGS,
            &g_srv_mms_settings_context->nvram_retrieval_settings,
            DS_DOUBLE,
            &error);
        ReadValue(
            NVRAM_UMMS_RETRIEVAL_SETTINGS,
            &g_srv_mms_settings_context->nvram_retrieval_settings,
            DS_DOUBLE,
            &error);
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    ReadValue(NVRAM_SETTING_PREFER_MMS_STORAGE_MODE, &nvram_mms_prefer_storage, DS_BYTE, &error);
    if (nvram_mms_prefer_storage == 0xFF)
    {
        nvram_mms_prefer_storage = E_PREFER_STORAGE_MODE_PHONE;
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
ReadValue(NVRAM_SETTING_MMS_MSG_FILTER, &nvram_mms_msg_filter, DS_BYTE, &error);
    if (flag)
    {
        /* srv_mms_send_set_settings_to_service(); */
        srv_mms_send_events(EVT_ID_SRV_SET_SETTING, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_read_nvarm_compose_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_read_nvarm_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_srv_mms_settings_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_read_nvram_sending_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_read_nvram_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
        1,
        &g_srv_mms_settings_context->nvram_sending_settings,
        NVRAM_UMMS_SENDING_SETTINGS_SIZE,
        &error);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_read_nvram_retrieval_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_read_nvram_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_UMMS_RETRIEVAL_SETTINGS, &g_srv_mms_settings_context->nvram_retrieval_settings, DS_DOUBLE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_nvram_compose_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_nvram_compose_settings_struct *srv_mms_get_nvram_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_mms_settings_context->nvram_compose_settings;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_nvram_sending_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_nvram_sending_settings_struct *srv_mms_get_nvram_sending_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_mms_settings_context->nvram_sending_settings;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_nvram_retrieval_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_nvram_retrieval_settings_struct *srv_mms_get_nvram_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_mms_settings_context->nvram_retrieval_settings;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_write_nvram_compose_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_write_nvram_compose_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        1,
        &g_srv_mms_settings_context->nvram_compose_settings,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_write_nvram_sending_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_write_nvram_sending_settings()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
        1,
        &g_srv_mms_settings_context->nvram_sending_settings,
        NVRAM_UMMS_SENDING_SETTINGS_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_write_nvram_retrieval_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_write_nvram_retrieval_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_UMMS_RETRIEVAL_SETTINGS, &g_srv_mms_settings_context->nvram_retrieval_settings, DS_DOUBLE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_set_setting(void *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mma_set_settings_req_struct *req_data = (srv_mms_mma_set_settings_req_struct*) req;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        return SRV_MMS_RESULT_NOT_READY;
    }

    if (req_data->call_back == NULL)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }
    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_mma_set_settings_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_mma_set_settings_rsp_struct));

    process->call_back = req_data->call_back;
    process->user_data = req_data->user_data;
    srv_mms_mma_set_settings_req(process, req_data);
    return 1;
}

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_get_list_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_um_get_list_info(void *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_list_info_req_struct *req_data = (srv_mms_get_list_info_req_struct*) req;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if (req_data->call_back == NULL)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }
    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_get_list_info_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_get_list_info_rsp_struct));
    process->app_id = req_data->app_id;
    process->call_back = req_data->call_back;
    process->user_data = req_data->user_data;
    srv_mms_um_get_list_info_req(process, req_data);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_um_get_template_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_um_get_template_msg_info(void *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_msg_info_req_struct *req_data = (srv_mms_get_msg_info_req_struct*) req;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!g_srv_mms_cntx->is_srv_ready)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if (req_data->call_back == NULL)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }
    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_get_msg_info_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_get_msg_info_rsp_struct));
    process->app_id = req_data->app_id;
    process->call_back = req_data->call_back;
    process->user_data = req_data->user_data;
    srv_mms_um_get_template_msg_info_req(process, req_data);
    return 1;

}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_fill_current_settings_for_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msgSet      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_fill_current_settings_for_mma(wap_mma_set_setting_req_struct *msgSet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgSet->compose_sending_setting.creation_mode = srv_mms_compose_settings_creation_mode();
    msgSet->compose_sending_setting.priority = srv_mms_sending_settings_priority();
    msgSet->compose_sending_setting.validity_period = srv_mms_sending_settings_validity_period();
    msgSet->compose_sending_setting.delivery_time = srv_mms_sending_settings_delivery_time();
    msgSet->compose_sending_setting.delivery_report = (kal_bool)srv_mms_sending_settings_delivery_report();
    msgSet->compose_sending_setting.read_report = (kal_bool)srv_mms_sending_settings_read_report();
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    msgSet->compose_sending_setting.max_mms_size = srv_mms_sending_mms_size_limit();
#else 
    msgSet->compose_sending_setting.max_mms_size = wap_custom_get_max_mms_msg_size();
#endif 
    srv_mms_compose_setting_image_resize_info(&msgSet->compose_sending_setting.image_resize);
#ifdef __MMI_MMS_SIGNATURE__
    srv_mms_compose_settings_sign_info(&msgSet->compose_sending_setting.signature);
#endif 
    srv_mms_compose_settings_default_slide_time(&msgSet->compose_sending_setting.sliding_time);
    msgSet->compose_sending_setting.layout = srv_mms_compose_settings_layout();
#ifdef __DRM_SUPPORT__
    msgSet->compose_sending_setting.add_as_drm = srv_mms_compose_settings_add_as_drm();
#else 
    msgSet->compose_sending_setting.add_as_drm = 0;
#endif 
    msgSet->compose_sending_setting.max_no_pages = srv_mms_compose_settings_max_no_pages();
    msgSet->compose_sending_setting.best_page_duration = srv_mms_compose_settings_best_page_duration();
    msgSet->compose_sending_setting.reply_charging = srv_mms_sending_settings_reply_charging_status();
    msgSet->compose_sending_setting.request_type = srv_mms_sending_settings_reply_charging_request_type();
    msgSet->compose_sending_setting.deadline_for_reply = srv_mms_sending_settings_deadline_for_reply();
    msgSet->compose_sending_setting.hide_sender = srv_mms_sending_settings_hide_sender();

    /* msgSet->compose_sending_setting.size = srv_mms_retrieval_settings_msg_size_filter(); */

    msgSet->compose_sending_setting.size = 0;

#ifdef __CMCC_RETRIVAL_MODE_SETTING__
    msgSet->retrieval_setting.home_network = MMA_RETRIEVAL_MODE_IMMED;
#else 
    msgSet->retrieval_setting.home_network = srv_mms_retrieval_settings_home_network_retrieval_mode();
#endif 
    msgSet->retrieval_setting.roaming = srv_mms_retrieval_settings_roaming_retrieval_mode();
    msgSet->retrieval_setting.anonymous_filter = srv_mms_retrieval_settings_anonymous_filter();
    msgSet->retrieval_setting.advertisement_filter = srv_mms_retrieval_settings_advertisment_filter();
    msgSet->retrieval_setting.delivery_report = srv_mms_retrieval_settings_delivery_report();

    /* memory card  */
    /* msgSet->preffered_storage = mmi_umms_app_dtmgr_get_prefered_storage(); */
    /* memory card  */
    msgSet->preffered_storage = srv_mms_get_mms_prefer_storage();
	msgSet->storage_filter = srv_mms_get_msg_filter();
}

/* settings_service_part api */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_mms_prefer_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_msg_storage_type_enum srv_mms_get_mms_prefer_storage(void)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nvram_mms_prefer_storage)
    {
        case E_PREFER_STORAGE_MODE_PHONE:
            return MMA_MSG_STORAGE_PHONE;
            
        case E_PREFER_STORAGE_MODE_CARD:
            return MMA_MSG_STORAGE_CARD1;
            
        default:
            return MMA_MSG_STORAGE_PHONE;

    }
#else /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    return MMA_MSG_STORAGE_PHONE;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_mms_prefer_storage_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_prefer_storage_enum srv_mms_get_mms_prefer_storage_ex(void)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nvram_mms_prefer_storage)
    {
        case E_PREFER_STORAGE_MODE_PHONE:
            return E_PREFER_STORAGE_MODE_PHONE;
            
        case E_PREFER_STORAGE_MODE_CARD:
            return E_PREFER_STORAGE_MODE_CARD;
            
        default:
            return E_PREFER_STORAGE_MODE_PHONE;

    }
#else /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    return E_PREFER_STORAGE_MODE_PHONE;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_retrieval_settings_read_report
 * DESCRIPTION
 *  Retruns the read report status set in retrieval settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_retrieval_settings_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    switch (g_srv_mms_settings_context->nvram_retrieval_settings.read_report)
    {
        case MMI_TRUE:
            return E_READ_REPORT_SEND_ALWAYS;
            
        case MMI_FALSE:
            return E_READ_REPORT_SEND_NEVER;
            
        default:
            return E_READ_REPORT_SEND_ALWAYS;
            
    }

#elif !defined( __MMI_MMS_2_RETRIVAL_MODE_SETTING__)
    switch (g_srv_mms_settings_context->nvram_retrieval_settings.read_report)
    {
        case E_READ_REPORT_SEND_ON_REQUEST:
            return E_READ_REPORT_SEND_ON_REQUEST;
            
        case E_READ_REPORT_SEND_ALWAYS:
            return E_READ_REPORT_SEND_ALWAYS;
            
        case E_READ_REPORT_SEND_NEVER:
            return E_READ_REPORT_SEND_NEVER;
            
        default:
            return E_READ_REPORT_SEND_ON_REQUEST;
            
    }
#else /* __MMI_MMS_2_RETRIVAL_MODE_SETTING__ */ 
    switch (g_srv_mms_settings_context->nvram_retrieval_settings.read_report)
    {
        case MMI_TRUE:
            return E_READ_REPORT_SEND_ON_REQUEST;
            
        case MMI_FALSE:
            return E_READ_REPORT_SEND_NEVER;
            
        default:
            return E_READ_REPORT_SEND_ON_REQUEST;
            
    }
#endif /* __MMI_MMS_2_RETRIVAL_MODE_SETTING__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_settings_creation_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_creation_mode_enum srv_mms_compose_settings_creation_mode(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_mms_settings_context->nvram_compose_settings.creation_mode)
    {
        case E_CREAT_MODE_RESTRICTED:
            return MMA_CREATION_MODE_RESTRICTED;

        case E_CREAT_MODE_WARNING:
            return MMA_CREATION_MODE_WARNING;

        case E_CREAT_MODE_FREE:
            return MMA_CREATION_MODE_FREE;

        default:
            return MMA_CREATION_MODE_FREE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_priority
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_priority_enum srv_mms_sending_settings_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_mms_settings_context->nvram_sending_settings.priority)
    {
        case E_PRIORITY_LOW:
            return MMA_PRIORITY_LOW;
        case E_PRIORITY_NORMAL:
            return MMA_PRIORITY_MEDIUM;
        case E_PRIORITY_HIGH:
            return MMA_PRIORITY_HIGH;
        default:
            return MMA_PRIORITY_MEDIUM;
    }

    

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_setting_image_resize_based_upon_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_umms_picture_size_enum srv_mms_compose_setting_image_resize_based_upon_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_umms_picture_size_enum)srv_mms_compose_settings_layout();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_setting_user_defined_slide_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_compose_setting_user_defined_slide_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mms_compose_settings_max_no_pages(); /* Temp use of this field in FTO for user defined slide time */
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_setting_image_resize_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resize      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_compose_setting_image_resize_info(mma_image_resizing_struct *resize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resize->width = 0;
    resize->height = 0;
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__

    switch (g_srv_mms_settings_context->nvram_compose_settings.image_resize_option)
    {
        case E_IMAGE_RESIZE_OFF:
            resize->enable = KAL_FALSE;
            break;
    #ifndef __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__
    #if defined(__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__) && (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __160x120__)
        case E_IMAGE_RESIZE_160x120:
            resize->enable = KAL_TRUE;
            resize->width = 160;
            resize->height = 120;
            break;
    #elif defined(__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__) && (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __320x240__)
        case E_IMAGE_RESIZE_160x120:
            resize->enable = KAL_TRUE;
            resize->width = 160;
            resize->height = 120;
            break;
        case E_IMAGE_RESIZE_320x240:
            resize->enable = KAL_TRUE;
            resize->width = 320;
            resize->height = 240;
            break;
    #elif defined(__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__) && (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __640x480__)
        case E_IMAGE_RESIZE_160x120:
            resize->enable = KAL_TRUE;
            resize->width = 160;
            resize->height = 120;
            break;
        case E_IMAGE_RESIZE_320x240:
            resize->enable = KAL_TRUE;
            resize->width = 320;
            resize->height = 240;
            break;
        case E_IMAGE_RESIZE_640x480:
            resize->enable = KAL_TRUE;
            resize->width = 640;
            resize->height = 480;
            break;
    #endif 
    #else /* __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__ */ 
        case E_IMAGE_RESIZE_AUTO:
            resize->enable = KAL_TRUE;
            break;
    #endif /* __MMI_UC_AUTO_RESIZE_IMG_BASED_ON_LEFT_MMS_SIZE__ */ 
    }
#else /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
    resize->enable = KAL_FALSE;
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_validity_period
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_expiry_time_enum srv_mms_sending_settings_validity_period(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_mms_settings_context->nvram_sending_settings.validity_period)
    {
        case E_VALIDITY_PERIOD_MAX:
            return MMA_EXPIRY_MAX;
        case E_VALIDITY_PERIOD_1HR:
            return MMA_EXPIRY_1_HOUR;
        case E_VALIDITY_PERIOD_6HRS:
            return MMA_EXPIRY_6_HOURS;
        case E_VALIDITY_PERIOD_12HRS:
            return MMA_EXPIRY_12_HOURS;
        case E_VALIDITY_PERIOD_1DAY:
            return MMA_EXPIRY_1_DAY;
        case E_VALIDITY_PERIOD_1WEEK:
            return MMA_EXPIRY_1_WEEK;
        default:
            return MMA_EXPIRY_MAX;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_delivery_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_delivery_time_enum srv_mms_sending_settings_delivery_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_mms_settings_context->nvram_sending_settings.delivery_time)
    {
        case E_IMMEDIATE:
            return MMA_DELIVERY_IMMEDIATE;
        case E_1_HR:
            return MMA_DELIVERY_1_HOUR;
        case E_2_HR:
            return MMA_DELIVERY_2_HOUR;
        case E_12_HRS:
            return MMA_DELIVERY_12_HOURS;
        case E_24_HRS:
            return MMA_DELIVERY_24_HOURS;
        default:
            return MMA_DELIVERY_IMMEDIATE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_delivery_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_sending_settings_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_sending_settings.delivery_report;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_read_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_sending_settings_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_sending_settings.read_report;
}

#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_mms_size_limit
 * DESCRIPTION
 *  Retruns the current mms sending size limit
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
mma_setting_size_limit_enum srv_mms_sending_mms_size_limit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_mms_settings_context->nvram_sending_settings.size)
    {

        case E_SENDING_SIZE_LIMIT_100:
            return MMA_SETTING_SIZE_LIMIT_100;

        case E_SENDING_SIZE_LIMIT_300:
            return MMA_SETTING_SIZE_LIMIT_300;

        case E_SENDING_SIZE_LIMIT_600:
            return MMA_SETTING_SIZE_LIMIT_600;

        default:
            return MMA_SETTING_SIZE_LIMIT_300;

    }
}

#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_settings_sign_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signature       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_compose_settings_sign_info(mma_signature_struct *signature)
{
#ifdef __MMI_MMS_SIGNATURE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmi_uc_text_path[MMA_MAX_INTERNAL_FILENAME_LENGTH * ENCODING_LENGTH];
    FS_HANDLE file_handle;
    U32 write_len = 0;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(signature, 0, sizeof(mma_signature_struct));

    srv_mms_signature_data_init();

    /* if (g_srv_mms_settings_context->nvram_compose_settings.auto_signature) */
    /* commented for manual signature insert in composer as always provide the signature content */
    {
        if (mmi_ucs2strlen((S8*) g_srv_mms_settings_context->nvram_compose_settings.auto_signature_content))
        {
            U32 utf8_buffer_size =
                (mmi_ucs2strlen((S8*) g_srv_mms_settings_context->nvram_compose_settings.auto_signature_content) * 3 +
                 ENCODING_LENGTH);
            U8 *utf8_buffer = (U8*) OslMalloc(utf8_buffer_size);
            U32 utf8_len = 0;

        #ifdef __USB_IN_NORMAL_MODE__
            if (srv_usb_is_in_mass_storage_mode())
            {
                /* in mass storage mode */
                if (srv_usb_check_path_exported((WCHAR*) L"root"))
                {
                    MMI_UMMS_MAKE_SIGNATURE_FOLDER_PATH(mmi_uc_text_path);
                    mmi_ucs2cat((S8*) mmi_uc_text_path, (S8*) MMI_UMMS_MAKE_SETTINGS_TEXT_FILE_PATH);
                    mmi_ucs2cpy((S8*) signature->text_file, (S8*) mmi_uc_text_path);
                    signature->enable = (kal_bool)g_srv_mms_settings_context->nvram_compose_settings.auto_signature;
                #ifndef __MMI_SLIM_MMS_2__
                    mmi_ucs2cpy(
                        (S8*) signature->img_file,
                        (S8*) g_srv_mms_settings_context->nvram_compose_settings.auto_signature_image_file);
                    mmi_ucs2cpy(
                        (S8*) signature->audio_file,
                        (S8*) g_srv_mms_settings_context->nvram_compose_settings.auto_signature_audio_file);
                    mmi_ucs2cpy(
                        (S8*) signature->video_file,
                        (S8*) g_srv_mms_settings_context->nvram_compose_settings.auto_signature_video_file);
                #endif /* __MMI_SLIM_MMS_2__ */ 
                    OslMfree(utf8_buffer);
                    return;
                }
            }
        #endif /* __USB_IN_NORMAL_MODE__ */ 

            MMI_UMMS_MAKE_SIGNATURE_FOLDER_PATH(mmi_uc_text_path);
            mmi_ucs2cat((S8*) mmi_uc_text_path, (S8*) MMI_UMMS_MAKE_SETTINGS_TEXT_FILE_PATH);
            memset(utf8_buffer, 0, utf8_buffer_size);
            utf8_len = mmi_chset_ucs2_to_utf8_string(
                        utf8_buffer,
                        utf8_buffer_size,
                        g_srv_mms_settings_context->nvram_compose_settings.auto_signature_content);

            file_handle = FS_Open((U16*) mmi_uc_text_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
            if (file_handle < 0)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_TEXT_FAIL);
                OslMfree(utf8_buffer);
                signature->enable = KAL_FALSE;
                return;
                /* MMI_ASSERT(0); */
            }
            result = FS_Write(
                        file_handle,
                        utf8_buffer,
                        utf8_len - 1,   /* null terminator */
                        &write_len);

            if (result == FS_NO_ERROR)
            {
                OslMfree(utf8_buffer);
                FS_Close(file_handle);
                mmi_ucs2cpy((S8*) signature->text_file, (S8*) mmi_uc_text_path);
            }
            else
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_TEXT_WRITE_FAIL);
                OslMfree(utf8_buffer);
                FS_Close(file_handle);
                signature->enable = KAL_FALSE;
                return;
            }
        }
        signature->enable = (kal_bool)g_srv_mms_settings_context->nvram_compose_settings.auto_signature;
    #ifndef __MMI_SLIM_MMS_2__
        mmi_ucs2cpy(
            (S8*) signature->img_file,
            (S8*) g_srv_mms_settings_context->nvram_compose_settings.auto_signature_image_file);
        mmi_ucs2cpy(
            (S8*) signature->audio_file,
            (S8*) g_srv_mms_settings_context->nvram_compose_settings.auto_signature_audio_file);
        mmi_ucs2cpy(
            (S8*) signature->video_file,
            (S8*) g_srv_mms_settings_context->nvram_compose_settings.auto_signature_video_file);
    #endif /* __MMI_SLIM_MMS_2__ */ 
    }
    return;
#endif /* __MMI_MMS_SIGNATURE__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_signature_data_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_signature_data_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    
    U8 folder_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(folder_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
    MMI_UMMS_MAKE_SIGNATURE_FOLDER_PATH(folder_path);   /* d:\signature */
    file_handle = FS_Open((WCHAR*) folder_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
    }
    else
    {
        FS_CreateDir((WCHAR*) folder_path);
        FS_SetAttributes((unsigned short*)folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_settings_default_slide_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  set     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_compose_settings_default_slide_time(mma_setting_struct *set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set->value = g_srv_mms_settings_context->nvram_compose_settings.default_slide_time;
    set->min = 1;
    set->max = UMMS_MAX_DEFAULT_SLIDE_TIME_DURATION;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_settings_layout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_compose_settings_layout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_compose_settings.layout;
}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_settings_add_as_drm
 * DESCRIPTION
 *  Returns the add as drm object status set in compose settings
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_compose_settings_add_as_drm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_compose_settings.add_drm;
}
#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_settings_max_no_pages
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_compose_settings_max_no_pages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_compose_settings.max_no_pages;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_compose_settings_best_page_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_compose_settings_best_page_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__
    return g_srv_mms_settings_context->nvram_compose_settings.best_page_duration;
#else 
    return MMI_TRUE;    /* after hiding the menu of best page duration it is always ON after 9.05 */
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_reply_charging_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_sending_settings_reply_charging_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_sending_settings.reply_charging;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_reply_charging_request_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_sending_settings_reply_charging_request_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_mms_settings_context->nvram_sending_settings.request_type)
    {
        case E_FULL_MMS:
            return 0;
        case E_TEXT_ONLY:
            return 1;
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_deadline_for_reply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_sending_settings_deadline_for_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_sending_settings.deadline_for_reply;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_hide_sender
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_sending_settings_hide_sender(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_sending_settings.hide_sender;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sending_settings_send_and_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_sending_settings_send_and_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_sending_settings.send_and_save;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_retrieval_settings_home_network_retrieval_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_retrieval_mode_enum srv_mms_retrieval_settings_home_network_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
    switch (g_srv_mms_settings_context->nvram_retrieval_settings.home_network)
    {
        case E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE:
            return MMA_RETRIEVAL_MODE_IMMED;
        case E_HOME_NOETWORK_RETRIEVAL_DEFFERED:
            return MMA_RETRIEVAL_MODE_DEFERRED;
        case E_HOME_NOETWORK_RETRIEVAL_RESTRICTED:
            return MMA_RETRIEVAL_MODE_REJECT;
        default:
            return MMA_RETRIEVAL_MODE_IMMED;
    }
#elif defined(__MMI_OP12_MMS_SUPPORT_SETTINGS__)
    switch (g_srv_mms_settings_context->nvram_retrieval_settings.home_network)
    {
        case 0:
            return MMA_RETRIEVAL_MODE_IMMED;
        case 1:
            return MMA_RETRIEVAL_MODE_DEFERRED;
        default:
            return MMA_RETRIEVAL_MODE_IMMED;
    }
#else 

    switch (g_srv_mms_settings_context->nvram_retrieval_settings.home_network)
    {
        case E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE:
            return MMA_RETRIEVAL_MODE_IMMED;
        case E_HOME_NOETWORK_RETRIEVAL_DEFFERED:
            return MMA_RETRIEVAL_MODE_DEFERRED;
        case E_HOME_NOETWORK_RETRIEVAL_RESTRICTED:
            return MMA_RETRIEVAL_MODE_REJECT;
        default:
            return MMA_RETRIEVAL_MODE_IMMED;
    }
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_retrieval_settings_roaming_retrieval_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mma_retrieval_mode_enum srv_mms_retrieval_settings_roaming_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_mms_settings_context->nvram_retrieval_settings.roaming)
    {
    #ifdef __MMI_OP12_MMS_SUPPORT_SETTINGS__
        case 0:
            return MMA_RETRIEVAL_MODE_IMMED;

        case 1:
            return MMA_RETRIEVAL_MODE_DEFERRED;
        default:
            return MMA_RETRIEVAL_MODE_IMMED;
    #elif defined(__MMI_MMS_2_RETRIVAL_MODE_SETTING__)
        case 0:
            return MMA_RETRIEVAL_MODE_REJECT;
        case 1:
            return MMA_RETRIEVAL_MODE_IMMED;
        default:
            return MMA_RETRIEVAL_MODE_IMMED;
    #else 
        case E_ROAMING_RETRIEVAL_AS_HOME:
            return MMA_RETRIEVAL_MODE_AS_HOME;

        case E_ROAMING_RETRIEVAL_IMMEDAITE:
            return MMA_RETRIEVAL_MODE_IMMED;

        case E_ROAMING_RETRIEVAL_DEFFERED:
            return MMA_RETRIEVAL_MODE_DEFERRED;

        case E_ROAMING_RETRIEVAL_RESTRICTED:
            return MMA_RETRIEVAL_MODE_REJECT;
        default:
            return MMA_RETRIEVAL_MODE_AS_HOME;
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_retrieval_settings_anonymous_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_retrieval_settings_anonymous_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_retrieval_settings.anonymous_filter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_retrieval_settings_advertisment_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_retrieval_settings_advertisment_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_retrieval_settings.advertisement_filter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_retrieval_settings_delivery_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_retrieval_settings_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_settings_context->nvram_retrieval_settings.delivery_report;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_nvram_compose_settings_auto_sign_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 *srv_mms_get_nvram_compose_settings_auto_sign_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_SIGNATURE__
    return g_srv_mms_settings_context->nvram_compose_settings.auto_signature_content;
#else 
    return NULL;
#endif 
}

#ifdef __MMI_MMS_SLIM_SETTINGS__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_nvram_compose_settings_auto_sign_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void srv_mms_set_settings_slim(srv_mms_settings_enum app_setting, U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	switch(app_setting)
		{
		case SRV_MMS_SENDING_SETTINGS_READ_REPORT:
			g_srv_mms_settings_context->nvram_sending_settings.read_report = value;
			srv_mms_write_nvram_sending_settings();
			break;
		case SRV_MMS_RETRIEVAL_SETTINGS_HOME_NW:
            g_srv_mms_settings_context->nvram_retrieval_settings.home_network = value;
            srv_mms_write_nvram_retrieval_settings();
            break;
        case SRV_MMS_RETRIEVAL_SETTINGS_ANON:
            g_srv_mms_settings_context->nvram_retrieval_settings.anonymous_filter = value;
			srv_mms_write_nvram_retrieval_settings();
            break;
        case SRV_MMS_RETRIEVAL_SETTINGS_ADV:
            g_srv_mms_settings_context->nvram_retrieval_settings.advertisement_filter = value;
            srv_mms_write_nvram_retrieval_settings();
            break;
        case SRV_MMS_RETRIEVAL_SETTINGS_DELIVERY_REPORT:
            g_srv_mms_settings_context->nvram_retrieval_settings.delivery_report = value;
            srv_mms_write_nvram_retrieval_settings();
            break;
        case SRV_MMS_RETRIEVAL_SETTINGS_READ_REPORT:
            g_srv_mms_settings_context->nvram_retrieval_settings.read_report = value;
            srv_mms_write_nvram_retrieval_settings();
            break;

		}

}

#endif
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_immed_send
 * DESCRIPTION
 *  This function semd  MMS immediate
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_immed_send_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_immed_send(srv_mms_immed_send_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_immed_send_req_struct *req = (srv_mms_immed_send_req_struct*) para;
    srv_mms_process_data_struct *process = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->call_back == NULL) || (req->msg_id == 0))
    {
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    if (g_srv_immed_send.call_back != NULL)
    {
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }

    srv_mms_immed_send_req(process, req);

    return SRV_MMS_RESULT_OK;
}
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send(srv_mms_send_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return;
    }

#if(MMI_MAX_SIM_NUM >= 2)
    mma_mms_set_sim_status(req->msg_id, req->sim_id);
    srv_mms_show_status_icon();
#endif /* (MMI_MAX_SIM_NUM >= 2) */ 

#ifdef __MMI_MMS_LOW_TIER_BGSR_SUPPORT__
	result = srv_mms_slim_bgsr_send_mms_req(req->sim_id, req->msg_id, req->storage_type, FALSE);
	{
		srv_mms_bgsr_result_struct bgsr_result;
		bgsr_result.result = result;
		bgsr_result.bgsr_req_type = MMS_BGSR_REQ_TYPE_SEND;
		srv_mms_send_events(EVT_ID_SRV_BGSR_RESULT, (void *)&bgsr_result);
	}
#else
    req->send_setting = srv_mms_send_setting_to_bgsr_send_setting(req->send_setting);
    result =
        (U8) srv_mms_bgsr_send_req(
                (kal_uint8) req->sim_id,
                req->msg_id,
                (srv_mms_bgsr_send_setting_enum) req->send_setting,
                (kal_uint8) req->storage_type,
                (kal_uint16) MMA_APP_ID_MMS_APP);
    {
        srv_mms_bgsr_result_struct bgsr_result;

        bgsr_result.result = result;
        bgsr_result.bgsr_req_type = MMS_BGSR_REQ_TYPE_SEND;
        srv_mms_send_events(EVT_ID_SRV_BGSR_RESULT, (void*)&bgsr_result);
    }
#endif
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        TRC_MMI_UMMS_BGSR_SEND,
        req->sim_id,
        req->msg_id,
        req->send_setting,
        req->storage_type,
        MMA_APP_ID_MMS_APP,
        result);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_cancel_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_cancel_send(srv_mms_cancel_send_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return;
    }

    result = (U8) srv_mms_bgsr_cancel_send_req(req->msg_id);
    {
        srv_mms_bgsr_result_struct bgsr_result;

        bgsr_result.result = result;
        bgsr_result.bgsr_req_type = MMS_BGSR_REQ_TYPE_CANCEL_SEND;
        srv_mms_send_events(EVT_ID_SRV_BGSR_RESULT, (void*)&bgsr_result);
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_BGSR_CANCEL_SEND, req->msg_id, result);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_read_report_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_read_report_req(srv_mms_send_read_report_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return;
    }
    /* req->msg_folder = srv_mms_mma_folder_to_bgsr_folder(req->msg_folder); */
#ifndef __MMI_MMS_LOW_TIER_BGSR_SUPPORT__
    result = (U8) srv_mms_bgsr_send_rr_req(req->sim_id, req->msg_id, req->storage_location);
#else
    result = srv_mms_slim_bgsr_send_mms_req(req->sim_id, req->msg_id, 0, TRUE);
#endif
    {
        srv_mms_bgsr_result_struct bgsr_result;

        bgsr_result.result = result;
        bgsr_result.bgsr_req_type = MMS_BGSR_REQ_TYPE_SEND_RR;
        srv_mms_send_events(EVT_ID_SRV_BGSR_RESULT, (void*)&bgsr_result);
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_BGSR_SEND_RR, req->sim_id, req->msg_id, req->storage_location, result);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_download
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_download(srv_mms_download_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return;
    }
#if(MMI_MAX_SIM_NUM >= 2)
    mma_mms_set_sim_status(req->msg_id, req->sim_id);
    srv_mms_show_status_icon();
#endif /* (MMI_MAX_SIM_NUM >= 2) */ 

#ifdef __MMI_MMS_LOW_TIER_BGSR_SUPPORT__
    result = (U8)srv_mms_slim_bgsr_download_req(req->sim_id, req->msg_id, req->storage_type, FALSE);
#else
    result = (U8) srv_mms_bgsr_download_req(req->sim_id, req->msg_id, req->storage_type);
#endif
    {
        srv_mms_bgsr_result_struct bgsr_result;

        bgsr_result.result = result;
        bgsr_result.bgsr_req_type = MMS_BGSR_REQ_TYPE_DOWNLOADING;
        srv_mms_send_events(EVT_ID_SRV_BGSR_RESULT, (void*)&bgsr_result);
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_BGSR_DOWNLOAD, req->sim_id, req->msg_id, req->storage_type, result);

}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_download
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_download_without_popup(srv_mms_download_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return;
    }
#if(MMI_MAX_SIM_NUM >= 2)
    mma_mms_set_sim_status(req->msg_id, req->sim_id);
    srv_mms_show_status_icon();
#endif /* (MMI_MAX_SIM_NUM >= 2) */ 

#ifdef __MMI_MMS_LOW_TIER_BGSR_SUPPORT__
    result = (U8)srv_mms_slim_bgsr_download_req(req->sim_id, req->msg_id, req->storage_type, FALSE);
#else
    result = (U8) srv_mms_bgsr_download_req(req->sim_id, req->msg_id, req->storage_type);
#endif
    
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_BGSR_DOWNLOAD, req->sim_id, req->msg_id, req->storage_type, result);

}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_cancel_download
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_cancel_download(srv_mms_cancel_download_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return;
    }
    result = (U8) srv_mms_bgsr_cancel_download_req(req->msg_id);
    {
        srv_mms_bgsr_result_struct bgsr_result;

        bgsr_result.result = result;
        bgsr_result.bgsr_req_type = MMS_BGSR_REQ_TYPE_CANCEL_DOWNLOADING;
        srv_mms_send_events(EVT_ID_SRV_BGSR_RESULT, (void*)&bgsr_result);
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_BGSR_CANCEL_DOWNLOAD, req->msg_id, result);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_app_data
 * DESCRIPTION
 *  This function sets app data for a MMS
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_set_app_data_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_set_app_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_set_app_data_req_struct *req = (srv_mms_set_app_data_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->msg_id == 0) || (req->call_back == NULL))
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_set_app_data_rsp_struct));
    if (NULL == process->result)
    {
        ASSERT(0);
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_set_app_data_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = req->user_data;
    process->app_id = req->app_id;

    srv_mms_set_app_data_req(process, req);

    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_entry_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  sim_id              [IN]        
 *  storage_type        [IN]        
 *  app_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_mms_entry_send_msg(const U32 msg_id, U8 sim_id, U8 storage_type, U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 is_send_and_save = 0;

    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_SEND_MSG, msg_id, sim_id);
#if(MMI_MAX_SIM_NUM >= 2)
    mma_mms_set_sim_status(msg_id, sim_id);
    srv_mms_show_status_icon();
#endif /* (MMI_MAX_SIM_NUM >= 2) */ 
    is_send_and_save = srv_mms_sending_settings_send_and_save();
    {
        if (is_send_and_save > 0)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_SEND_MSG_SEND_SAVE_IS_ON);
#ifdef __MMI_MMS_LOW_TIER_BGSR_SUPPORT__
            result =
                (U8) srv_mms_slim_bgsr_send_mms_req(sim_id, msg_id, storage_type, is_send_and_save);
#else
            result =
                (U8) srv_mms_bgsr_send_req(sim_id, msg_id, SRV_MMS_BGSR_SETTING_SAVE_AND_SEND, storage_type, app_id);
#endif
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_ENTRY_SEND_MSG_SEND_SAVE_IS_OFF);
#ifdef __MMI_MMS_LOW_TIER_BGSR_SUPPORT__
            result = (U8) srv_mms_slim_bgsr_send_mms_req(sim_id, msg_id, storage_type, is_send_and_save);
#else
            result = (U8) srv_mms_bgsr_send_req(sim_id, msg_id, SRV_MMS_BGSR_SETTING_SEND_ONLY, storage_type, app_id);
#endif
        }
    }
    return result;
}

/******************************************************************************/
/**********amit added for sim_settings_info************************************/
/******************************************************************************/

#ifdef __MMI_MMS_SIM_USER_PREFERENCE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_sim_mms_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_sim_mms_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SIM_MMS_SETTING_ENTRY);
    if (SMU_SIM_REPLACED == check_sim_status())
    {
        srv_mms_get_sim_mms_file_access_info();
    }
    else if (SMU_SIM_NOT_READY == check_sim_status())
    {
        StartTimer(UMMS_SETTINGS_TIMER, UMMS_SIM_SETTINGS_REQUEST_TIME, srv_mms_sim_settings_timer_callback);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SIM_MMS_SETTING_EXIT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim_mms_file_access_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_sim_mms_file_access_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL accept_result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SIM_MMS_FILE_ACCESS_INFO);
    g_srv_sim_settings_cntx->sim_settings_progress = MMI_TRUE;

    accept_result = srv_sim_get_file_info(
                        (U8) FILE_MMSUP_IDX,
                        NULL,
                        MMI_SIM1,
                        srv_mms_get_sim_mms_file_access_info_callback,
                        NULL);

    if (MMI_FALSE == accept_result)
    {
        StartTimer(UMMS_SETTINGS_TIMER, UMMS_SIM_SETTINGS_REQUEST_TIME, srv_mms_sim_settings_timer_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim_mms_file_access_info_callback
 * DESCRIPTION
 *  this callback is called from SIM_FILE_INFO_RSP
 * PARAMETERS
 *  callback_data       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_get_sim_mms_file_access_info_callback(srv_sim_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_file_info_struct *file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_info = (srv_sim_file_info_struct*) callback_data->data;

    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_PS_SIM_MMS_FILE_ACCESS_INFO_CALLBACK,
        callback_data->cause,
        file_info->file_size,
        file_info->num_of_rec);
    if ((SIM_CMD_SUCCESS == callback_data->cause) && (file_info->num_of_rec > 0) &&
        ((file_info->file_size) / (file_info->num_of_rec) < UMMS_MAX_SIM_READ_SIZE + 1))
    {

        srv_mms_get_sim_mms_user_pref_info(file_info->file_size, file_info->num_of_rec);
    }
    else
    {
        g_srv_sim_settings_cntx->sim_settings_progress = MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim_mms_user_pref_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  total_file_size     [IN]        
 *  num_records         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_sim_mms_user_pref_info(U16 total_file_size, U16 num_records)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL accept_result = MMI_FALSE;
    U32 record_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SIM_MMS_USER_PREF_INFO, total_file_size, num_records);
    record_size = total_file_size / num_records;
    g_srv_sim_settings_cntx->data_buffer = (U8*) srv_mms_mem_mgr_app_adm_alloc(UMMS_MAX_SIM_READ_SIZE);
    if (NULL == g_srv_sim_settings_cntx->data_buffer)
    {
        MMI_ASSERT(g_srv_sim_settings_cntx->data_buffer != NULL);
    }
    memset(g_srv_sim_settings_cntx->data_buffer, 0, UMMS_MAX_SIM_READ_SIZE);

    accept_result = srv_sim_read_record(
                        (U8) FILE_MMSUP_IDX,
                        NULL,
                        1,
                        record_size,
                        MMI_SIM1,
                        srv_mms_get_sim_mms_user_pref_info_callback,
                        NULL);

    if (MMI_FALSE == accept_result)
    {
        srv_mms_mem_mgr_app_adm_free((U8*) g_srv_sim_settings_cntx->data_buffer);
        g_srv_sim_settings_cntx->data_buffer = NULL;
        StartTimer(UMMS_SETTINGS_TIMER, UMMS_SIM_SETTINGS_REQUEST_TIME, srv_mms_sim_settings_timer_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim_mms_user_pref_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_data       [?]         
 *  read_length(?)      [IN]        
 *  result(?)           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_sim_mms_user_pref_info_callback(srv_sim_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    U8 info_length = 0;
    U8 info_count = 0;
    MMI_BOOL read_fail = MMI_FALSE;
    U8 length = 0;
    U8 temp = 0;
    MMI_BOOL data_found = MMI_FALSE;

    U8 delivery_report = 255;
    U8 read_reply = 255;
    U8 priority = 255;
    U8 visibility = 255;
    U16 delivery_time = 255;
    U16 expiry_time = 255;
    U16 read_length = 0;
    U16 result = 0;
    S16 error = 0;
    srv_sim_data_struct *read_sim_rsp = (srv_sim_data_struct*) callback_data->data;

    read_length = read_sim_rsp->length;
    result = callback_data->cause;

    memcpy(g_srv_sim_settings_cntx->data_buffer, read_sim_rsp->data, UMMS_MAX_SIM_READ_SIZE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SIM_MMS_USER_PREF_INFO_CALLBACK, result, read_length);

    if (SIM_CMD_SUCCESS == result)
    {
        if (read_length > 0 && read_length < UMMS_MAX_SIM_READ_SIZE)
        {

            while ((count + 10 - 1) < read_length)  /* Minimum size of a record can be 10 bytes */
            {
                if ((g_srv_sim_settings_cntx->data_buffer[count] == 0x80) && (g_srv_sim_settings_cntx->data_buffer[count + 1] == 1) && (g_srv_sim_settings_cntx->data_buffer[count + 2] == 1) && (g_srv_sim_settings_cntx->data_buffer[count + 3] == 0x81) && ((count + 3 + 2 + g_srv_sim_settings_cntx->data_buffer[count + 4]) < read_length) &&      /* From start of data buffer length upto tag 0x82 should be less than read_length */
                    (g_srv_sim_settings_cntx->data_buffer[count + 5 + g_srv_sim_settings_cntx->data_buffer[count + 4]] == 0x82) && (count + 3 + 2 + g_srv_sim_settings_cntx->data_buffer[count + 4] + 2 + g_srv_sim_settings_cntx->data_buffer[count + 5 + g_srv_sim_settings_cntx->data_buffer[count + 4] + 1] <= read_length))        /* From start of data buffer upto end of record, total length should be less than or equal to read_length */
                {
                    data_found = MMI_TRUE;
                    break;
                }
                ++count;
            }

            if (data_found)
            {
                temp = g_srv_sim_settings_cntx->data_buffer[count + 4];
                count = count + 3 + 2 + temp + 2;       /* 3 bytes for MMS Implementation tag(1 byte) + length(1 byte) + value(1 byte) + 
                                                           (2 + temp) for MMS User Preference Profile Name Tag(1 byte) + length(1 byte) + value string length(temp bytes) */

                info_length = g_srv_sim_settings_cntx->data_buffer[count - 1];

                while ((info_count < info_length) && (read_fail != MMI_TRUE))
                {
                    MMI_TRACE(
                        MMI_INET_TRC_G6_MMS,
                        MMI_UMMS_PS_SIM_MMS_USER_PREF_INFO_CALLBACK_WHILE,
                        info_count,
                        info_length,
                        count,
                        g_srv_sim_settings_cntx->data_buffer[count + info_count],
                        g_srv_sim_settings_cntx->data_buffer[count + info_count + 1],
                        g_srv_sim_settings_cntx->data_buffer[count + info_count + 2]);
                    switch (g_srv_sim_settings_cntx->data_buffer[count + info_count])
                    {
                        case E_SIM_SETTINGS_DELIVERY_REPORT:
                            if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 1] == 0x80)
                            {
                                delivery_report = E_ON;
                            }
                            else if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 1] == 0x81)
                            {
                                delivery_report = E_OFF;
                            }
                            else
                            {
                                read_fail = MMI_TRUE;
                            }
                            info_count = info_count + 2;
                            break;
                        case E_SIM_SETTINGS_READ_REPLY:
                            if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 1] == 0x80)
                            {
                                read_reply = E_ON;
                            }
                            else if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 1] == 0x81)
                            {
                                read_reply = E_OFF;
                            }
                            else
                            {
                                read_fail = MMI_TRUE;
                            }
                            info_count = info_count + 2;
                            break;
                        case E_SIM_SETTINGS_PRIORITY:
                            if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 1] == 0x80)
                            {
                                priority = E_PRIORITY_LOW;
                            }
                            else if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 1] == 0x81)
                            {
                                priority = E_PRIORITY_NORMAL;
                            }
                            else if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 1] == 0x82)
                            {
                                priority = E_PRIORITY_HIGH;
                            }
                            else
                            {
                                read_fail = MMI_TRUE;
                            }
                            info_count = info_count + 2;
                            break;
                        case E_SIM_SETTINGS_SENDER_VISIBILITY:
                            if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 1] == 0x80)
                            {
                                visibility = E_ON;
                            }
                            else if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 1] == 0x81)
                            {
                                visibility = E_OFF;
                            }
                            else
                            {
                                read_fail = MMI_TRUE;
                            }
                            info_count = info_count + 2;
                            break;
                        case E_SIM_SETTINGS_DELIVERY_TIME:
                            if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 2] == 0x81)
                            {
                                delivery_time =
                                    (U16) srv_mms_get_sim_delivery_time(
                                            count + info_count + 4,
                                            g_srv_sim_settings_cntx->data_buffer[count + info_count + 3]);
                            }
                            else if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 2] != 0x80)
                            {
                                read_fail = MMI_TRUE;
                            }
                            length = g_srv_sim_settings_cntx->data_buffer[count + info_count + 1];
                            info_count = info_count + length + 2;
                            break;
                        case E_SIM_SETTINGS_EXPIRY_TIME:

                            if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 2] == 0x81)
                            {
                                expiry_time =
                                    (U16) srv_mms_get_sim_expiry_time(
                                            count + info_count + 4,
                                            g_srv_sim_settings_cntx->data_buffer[count + info_count + 3]);
                            }
                            else if (g_srv_sim_settings_cntx->data_buffer[count + info_count + 2] != 0x80)
                            {
                                read_fail = MMI_TRUE;
                            }
                            length = g_srv_sim_settings_cntx->data_buffer[count + info_count + 1];
                            info_count = info_count + length + 2;
                            break;
                        default:
                            read_fail = MMI_TRUE;
                            break;

                    }
                }
            }
            else
            {
                read_fail = MMI_TRUE;
            }
        }
        else
        {
            read_fail = MMI_TRUE;
        }
    }
    else
    {
        read_fail = MMI_TRUE;
    }

    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_PS_SIM_MMS_USER_PREF_INFO_CALLBACK_APPLY,
        delivery_report,
        delivery_time,
        visibility,
        priority,
        read_reply,
        expiry_time,
        read_fail);
    if (read_fail != MMI_TRUE)
    {
        srv_mms_read_nvram_settings(MMI_FALSE);
        if (delivery_report != 255)
        {
            g_srv_mms_settings_context->nvram_sending_settings.delivery_report = (U8) delivery_report;
        }
        if (delivery_time != 255)
        {
            g_srv_mms_settings_context->nvram_sending_settings.delivery_time = (U8) delivery_time;
        }
        if (visibility != 255)
        {
            g_srv_mms_settings_context->nvram_sending_settings.hide_sender = (U8) visibility;
        }
        if (priority != 255)
        {
            g_srv_mms_settings_context->nvram_sending_settings.priority = (U8) priority;
        }
        if (read_reply != 255)
        {
            g_srv_mms_settings_context->nvram_sending_settings.read_report = (U8) read_reply;
        }
        if (expiry_time != 255)
        {
            g_srv_mms_settings_context->nvram_sending_settings.validity_period = (U8) expiry_time;
        }

        WriteRecord(
            NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
            1,
            &g_srv_mms_settings_context->nvram_sending_settings,
            NVRAM_UMMS_SENDING_SETTINGS_SIZE,
            &error);

        if (mms_is_ready())
        {
            /* write a code here for setting the global bootup variable to true means not to show the popup after set settings_rsp */
            srv_mms_send_events(EVT_ID_SRV_SET_SETTING, NULL);
        }
    }

    g_srv_sim_settings_cntx->sim_settings_progress = MMI_FALSE;
    srv_mms_mem_mgr_app_adm_free((U8*) g_srv_sim_settings_cntx->data_buffer);
    g_srv_sim_settings_cntx->data_buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim_delivery_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  length      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_mms_get_sim_delivery_time(U32 index, U8 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time_seconds = 0;
    U32 temp_seconds = 0;
    U8 count = 0;
    U8 place_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length > 4)
    {
        while ((count < length - 4) && g_srv_sim_settings_cntx->data_buffer[index + count] == 0)
        {
            ++count;
        }
        if (count < length - 4)
        {
            return E_24_HRS;
        }
        else
        {
            index = index + length - 4;
            length = 4;
        }
    }
    for (count = 0; (count < length) && (time_seconds <= 43200); ++count)
    {
        temp_seconds = g_srv_sim_settings_cntx->data_buffer[index + count];
        for (place_count = 0; place_count < 2 * (length - (count + 1)); ++place_count)
        {
            temp_seconds = temp_seconds * 16;
        }

        time_seconds = time_seconds + temp_seconds;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_GET_SIM_DELIVERY_TIME, index, length, time_seconds);

    if (time_seconds == 0)
    {
        return E_IMMEDIATE;
    }
    if (time_seconds <= 3600)
    {
        return E_1_HR;
    }
    if (time_seconds <= 43200)
    {
        return E_12_HRS;
    }
    return E_24_HRS;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim_expiry_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  length      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_mms_get_sim_expiry_time(U32 index, U8 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time_seconds = 0;
    U32 temp_seconds = 0;
    U8 count = 0;
    U8 place_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length > 4)
    {
        while ((count < length - 4) && g_srv_sim_settings_cntx->data_buffer[index + count] == 0)
        {
            ++count;
        }
        if (count < length - 4)
        {
            return E_VALIDITY_PERIOD_MAX;
        }
        else
        {
            index = index + length - 4;
            length = 4;
        }
    }
    for (count = 0; (count < length) && (time_seconds <= 604800); ++count)
    {
        temp_seconds = g_srv_sim_settings_cntx->data_buffer[index + count];
        for (place_count = 0; place_count < 2 * (length - (count + 1)); ++place_count)
        {
            temp_seconds = temp_seconds * 16;
        }

        time_seconds = time_seconds + temp_seconds;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_GET_SIM_EXPIRY_TIME, index, length, time_seconds);

    if (time_seconds == 0)
    {
        return E_VALIDITY_PERIOD_MAX;
    }
    if (time_seconds <= 3600)
    {
        return E_VALIDITY_PERIOD_1HR;
    }
#ifndef __MMI_OP12_MMS_SUPPORT_SETTINGS__
    if (time_seconds <= 21600)
    {
        return E_VALIDITY_PERIOD_6HRS;
    }
#endif /* __MMI_OP12_MMS_SUPPORT_SETTINGS__ */ 
    if (time_seconds <= 43200)
    {
        return E_VALIDITY_PERIOD_12HRS;
    }
    if (time_seconds <= 86400)
    {
        return E_VALIDITY_PERIOD_1DAY;
    }
    if (time_seconds <= 604800)
    {
        return E_VALIDITY_PERIOD_1WEEK;
    }
    return E_VALIDITY_PERIOD_MAX;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sim_settings_timer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_sim_settings_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SIM_TIMER_CALLBACK);

    StopTimer(UMMS_SETTINGS_TIMER);

    if (SMU_SIM_REPLACED == check_sim_status())
    {
        srv_mms_get_sim_mms_file_access_info();
    }
    else if (SMU_SIM_NOT_READY == check_sim_status())
    {
        StartTimer(UMMS_SETTINGS_TIMER, UMMS_SIM_SETTINGS_REQUEST_TIME, srv_mms_sim_settings_timer_callback);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SIM_TIMER_CALLBACK_EXIT);
    }
}

#endif /* __MMI_MMS_SIM_USER_PREFERENCE_SUPPORT__ */ 

/****************************************************************************/
/* ends here for sim_settings_info ****************************************** */
/****************************************************************************/

/*****************amit starts for save_objects_service***********************/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_object_file_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  copy_result     [IN]        
 *  msg     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_save_object_file_callback(S32 copy_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* mmi_fmt_copy_rsp_strcut *copy_response; */
    
    
    U16 *object_vf = NULL;
    
    
    
    srv_mms_save_obj_rsp_evt_struct rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(srv_dm_lawmo_is_locked())
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
    /* close file handle */
    srv_mms_close_object_file_handle();
    /* virtual file name */
    object_vf = srv_mms_get_virtual_file_name();
    if (object_vf != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(object_vf);
        srv_mms_set_virtual_file_name(NULL);

    }
    
    
    rsp.user_data = (void*)&g_srv_mms_save_obj_hdlr;
    rsp.copy_result = copy_result;
    srv_mms_send_events(EVT_ID_SRV_SAVE_OBJECT_COPY_RESULT_HDL, (void*)&rsp);
    /* copy_response = (mmi_fmt_copy_rsp_strcut*) msg; */
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_make_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     [?]
 *  file_ext        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_make_file_name(S8 *file_name, S8 *file_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 dot[] = { '.', 0, 0, 0};
    S8 temp_ext[UMMS_SIGNATURE_EXT_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_ext != NULL)
    {
        mmi_ucs2cpy(temp_ext, dot);
        mmi_ucs2cat(temp_ext, file_ext);
        mmi_ucs2cat(file_name, temp_ext);
        return;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PS_SETTING_EXT_NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_objects_get_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 *  file_name       [IN]        
 *  flag            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_save_objects_get_file_name(S8 **const file_path, S8 const *const file_name, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 fpath_len = 0;
    S32 fsHandle = -1;
    S32 result;
    U16 *path_buf = NULL;
    int i = 1;
    S8 *file_temp = NULL;
    MMI_BOOL is_rename_done = MMI_FALSE;
    U16 ext_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_temp = srv_mms_mem_mgr_app_adm_alloc((mmi_ucs2strlen(file_name) + 1) * ENCODING_LENGTH);
    memset(file_temp, 0, (mmi_ucs2strlen(file_name) + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy(file_temp, file_name, mmi_ucs2strlen(file_name));
    /* Handling algo for same file name should not be passed to Download Agent */
    /* In case of reentry */
	if (file_temp == NULL)
        {
            srv_mms_send_save_objects_error(STR_GLOBAL_INSUFFICIENT_MEMORY, MMI_EVENT_PROPLEM);
            return MMI_FALSE;
        }
    while (1)
    {
        path_buf = (U16*) srv_mms_mem_mgr_app_adm_alloc((SRV_MMS_XML_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);     /* (312+1)*2 =626 */
        if (path_buf == NULL)
        {
            srv_mms_send_save_objects_error(STR_GLOBAL_INSUFFICIENT_MEMORY, MMI_EVENT_PROPLEM);
			srv_mms_mem_mgr_app_adm_free(file_temp);
			file_temp = NULL;
            return MMI_FALSE;
        }
        if (flag == MMI_FALSE)
        {
            kal_wsprintf(path_buf, "%c:\\%w", SRV_FMGR_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_TEMP);
        }
        else
        {
            kal_wsprintf(path_buf, "%c:\\%w", SRV_FMGR_CARD_DRV, FMGR_DEFAULT_FOLDER_TEMP);
        }
        if (is_rename_done == MMI_FALSE)
        {
            fsHandle = FS_Open((WCHAR*) path_buf, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
            if (fsHandle <= 0)
            {
                result = FS_CreateDir(path_buf);
                if (result < 0)
                {
                    srv_mms_send_events(EVT_ID_SRV_TEMPLATE_ERROR, (void*)&result);
                    g_srv_mms_save_obj_hdlr.fs_error = result;
                    srv_mms_send_events(EVT_ID_SRV_CHECK_AND_DELETE_PROGRESS, (void*)&g_srv_mms_save_obj_hdlr);

					srv_mms_mem_mgr_app_adm_free(file_temp);
					file_temp = NULL;
					srv_mms_mem_mgr_app_adm_free(path_buf);
					path_buf = NULL;
                    return MMI_FALSE;
                }
                FS_SetAttributes((unsigned short*)path_buf, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            }
            else
            {
                FS_Close(fsHandle);
            }
        }
        mmi_ucs2cat((PS8) path_buf, (PS8) file_temp);
        /* Open File only to check file exist or not */
        fsHandle = FS_Open((WCHAR*) path_buf, FS_READ_ONLY | FS_OPEN_SHARED);
        if (fsHandle >= 0)
        {
            U16 *file_ext = NULL, *file_ext_tmp = NULL;

            /* File exists true immediately close file */
            FS_Close(fsHandle);
            srv_mms_mem_mgr_app_adm_free(file_temp);
            file_temp = NULL;
            file_temp = srv_mms_mem_mgr_app_adm_alloc((mmi_ucs2strlen(file_name) + 1 + MMS_TMP_EXT_LEN) * ENCODING_LENGTH);
            memset(file_temp, 0, (mmi_ucs2strlen(file_name) + 1 + MMS_TMP_EXT_LEN) * ENCODING_LENGTH);
            mmi_ucs2ncpy(file_temp, file_name, mmi_ucs2strlen(file_name));
            /* Get File Extension */
            file_ext = (U16*) srv_fmgr_path_get_extension_ptr((WCHAR*) file_temp);
            if (file_ext != NULL)
            {
                if (is_rename_done == MMI_FALSE)
                {
                    ext_len = mmi_ucs2strlen((S8*) file_ext);
                }
                file_ext_tmp = srv_mms_mem_mgr_app_adm_alloc((ext_len + 1) * ENCODING_LENGTH);
                memset(file_ext_tmp, 0, (ext_len + 1) * ENCODING_LENGTH);
                mmi_ucs2ncpy((S8*) file_ext_tmp, (S8*) file_ext, ext_len);
                /* Try to make naming convention of new file as oldFIleName_1.xxx,oldFIleName_2.xxx etc. */
                file_ext--; /* this will let file_ext point to "." so that new file name append can be proceeded */
                /* From "." to avoid memory corruption */
                kal_wsprintf(file_ext, "_%d", i);
            }
            /* Append Extension in file name */
            srv_mms_make_file_name((S8*) file_temp, (S8*) file_ext_tmp);
            /* Free extension buffer */
            srv_mms_mem_mgr_app_adm_free(file_ext_tmp);
            file_ext_tmp = NULL;
            /* Free File Path Buffer because new buffer will be made will new file name */
            srv_mms_mem_mgr_app_adm_free(path_buf);
			path_buf = NULL;
            is_rename_done = MMI_TRUE;
        }
        else
        {
            /* This file name is safe to be passed to DA */
            break;
        }
        i++;
    }
    fpath_len = (mmi_ucs2strlen((S8*) path_buf) + 1) * ENCODING_LENGTH;
    *file_path = (S8*) srv_mms_mem_mgr_app_adm_alloc(fpath_len);
    if (*file_path == NULL)
    {
        srv_mms_send_save_objects_error(STR_GLOBAL_INSUFFICIENT_MEMORY, 0);
		if(file_temp != NULL)
		{
              srv_mms_mem_mgr_app_adm_free(file_temp);
              file_temp = NULL;
		}
	    if(path_buf != NULL)
		{
             srv_mms_mem_mgr_app_adm_free(path_buf);
			 path_buf = NULL;
		}
        return MMI_FALSE;
    }
    mmi_ucs2cpy((S8*) * file_path, (S8*) path_buf);
	if(file_temp != NULL)
		{
    srv_mms_mem_mgr_app_adm_free(file_temp);
    file_temp = NULL;
		}
	if(path_buf != NULL)
		{
    srv_mms_mem_mgr_app_adm_free(path_buf);
			 path_buf = NULL;
		}
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mms_is_ready();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_wap_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_is_wap_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL) g_is_wap_ready;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_save_rsp_to_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_save_rsp_to_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_um_refresh_ind_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
    req.msg_box_type = MMA_FOLDER_SENT;
    req.refresh_type = SRV_UM_REFRESH_NONE;
    srv_mms_um_refresh_msg_list(&req);

}

/*******************save ota settings***********************************************/


#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 

/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_ota_mms_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_setting_content_p                       [?]         [?]
 *  wap_prof_save_mms_setting_rsp_callback      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_save_ota_mms_settings(
        srv_wap_prov_mms_setting_data_list_struct *mms_setting_content_p,
        srv_wap_prof_response_funcptr_type wap_prof_save_mms_setting_rsp_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prov_mms_setting_data_list_struct *settings_p = NULL;
    S16 error = 0;
    U8 update_compose = MMI_FALSE;
    U8 no_set = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mms_setting_content_p);
    MMI_ASSERT(wap_prof_save_mms_setting_rsp_callback);
    settings_p = mms_setting_content_p;
    while (settings_p)
    {
        switch (settings_p->key)
        {
            case SRV_WAP_PROV_MMS_SETTING_CM:
                if (settings_p->value_type == SRV_WAP_PROV_VALUE_TYPE_INT)
                {
                    switch (settings_p->value_i)
                    {
                        case SRV_WAP_PROV_MMS_SETTING_RESTRICTED:
                            if (g_srv_mms_settings_context->nvram_compose_settings.creation_mode !=
                                (U8) E_CREAT_MODE_RESTRICTED)
                            {
                                g_srv_mms_settings_context->nvram_compose_settings.creation_mode =
                                    (U8) E_CREAT_MODE_RESTRICTED;
                                update_compose = MMI_TRUE;
                            }
                            else
                            {
                                no_set = MMI_TRUE;
                            }
                            break;
                        #ifdef __MMI_MMS_2_CREATION_MODE_WARNING_SUPPORT__
                        case SRV_WAP_PROV_MMS_SETTING_WARNING:
                            if (g_srv_mms_settings_context->nvram_compose_settings.creation_mode !=
                                (U8) E_CREAT_MODE_WARNING)
                            {
                                g_srv_mms_settings_context->nvram_compose_settings.creation_mode =
                                    (U8) E_CREAT_MODE_WARNING;
                                update_compose = MMI_TRUE;
                            }
                            else
                            {
                                no_set = MMI_TRUE;
                            }
                            break;
                        #endif /* __MMI_MMS_2_CREATION_MODE_WARNING_SUPPORT__ */ 
                        case SRV_WAP_PROV_MMS_SETTING_FREE:
                            if (g_srv_mms_settings_context->nvram_compose_settings.creation_mode !=
                                (U8) E_CREAT_MODE_FREE)
                            {
                                g_srv_mms_settings_context->nvram_compose_settings.creation_mode =
                                    (U8) E_CREAT_MODE_FREE;
                                update_compose = MMI_TRUE;
                            }
                            else
                            {
                                no_set = MMI_TRUE;
                            }
                            break;
                        default:
                            break;
                    }

                }
                else if (settings_p->value_type == SRV_WAP_PROV_VALUE_TYPE_STR)
                {
                }
                else
                {
                    MMI_ASSERT(0);
                }
                break;
            default:
                break;
        }
        settings_p = settings_p->next;
    }
    if (update_compose)
    {
        WriteRecord(
            NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
            1,
            &g_srv_mms_settings_context->nvram_compose_settings,
            NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
            &error);

        srv_mms_send_events(EVT_ID_SRV_SET_SETTING, NULL);
        g_rsp_OTA_callback = wap_prof_save_mms_setting_rsp_callback;
    }
    else
    {
        if (no_set == MMI_TRUE)
        {
            wap_prof_save_mms_setting_rsp_callback(SRV_WAP_PROF_SUCCESS);
        }
        else
        {
            wap_prof_save_mms_setting_rsp_callback(SRV_WAP_PROF_ERR);
        }
    }

}
#endif

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_mms_prefer_storage_for_hilight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_get_mms_prefer_storage_for_hilight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nvram_mms_prefer_storage;
}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

/*  memory card */

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sd_card_plug_out_hdlr
 * DESCRIPTION
 *  plug out of memory card indication is from FMGR do the required actions
 * PARAMETERS
 *  drive_counter       [IN]        
 *  para(?)             [IN]        
 *  notify_flag(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_sd_card_plug_out_hdlr(U8 drive_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mms_mem_card_plug_in_out_struct *msgSet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_send_events(EVT_ID_SRV_CHK_CARD_PLUG_OUT, NULL);
    msgSet = (mms_mem_card_plug_in_out_struct*) OslConstructDataPtr(sizeof(*msgSet));
    msgSet->drv_count = drive_counter;
    msgSet->drv_list[0] = MMA_MSG_STORAGE_CARD1;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMI_MMS_CARD_PLUG_OUT_IND),
        0,
        MSG_ID_MMI_MMS_CARD_PLUG_OUT_IND,
        (oslParaType*) msgSet,
        NULL);

    srv_mms_bgsr_mem_card_plug_out_notify();

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sd_card_plug_in_hdlr
 * DESCRIPTION
 *  plug in of memory card indication is from FMGR do the required actions
 * PARAMETERS
 *  drive_counter       [IN]        
 *  para(?)             [IN]        
 *  notify_flag(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_sd_card_plug_in_hdlr(U8 drive_counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mms_mem_card_plug_in_out_struct *msgSet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgSet = (mms_mem_card_plug_in_out_struct*) OslConstructDataPtr(sizeof(*msgSet));
    msgSet->drv_count = drive_counter;
    msgSet->drv_list[0] = MMA_MSG_STORAGE_CARD1;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMI_MMS_CARD_PLUG_IN_IND),
        0,
        MSG_ID_MMI_MMS_CARD_PLUG_IN_IND,
        (oslParaType*) msgSet,
        NULL);

}
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_drv_format_hdlr
 * DESCRIPTION
 *  plug in of memory card indication is from FMGR do the required actions
 * PARAMETERS
 *  void
 *  para(?)             [IN](?)
 *  notify_flag(?)      [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_drv_format_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* srv_mms_get_number_status_icon(); */
    srv_mms_msg_update_count_and_status_icon();
}

/* memory card */

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_change_msg_storage
 * DESCRIPTION
 *  srv_mms_change_msg_storage
 * PARAMETERS
 *  action_type     [IN]        
 *  storage         [IN]        
 *  msg_id          [IN]        
 *  inMsg(?)(?)
 *  msg_id(?)       [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_change_msg_storage(U8 action_type, U8 storage, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_change_msg_storage_req_struct *msgSet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgSet =
        (wap_mma_change_msg_storage_req_struct*) OslConstructDataPtr(sizeof(wap_mma_change_msg_storage_req_struct));
    if (storage == MMA_MSG_STORAGE_PHONE)
    {
        msgSet->dest_storage = MMA_MSG_STORAGE_CARD1;
    }
    if (storage == MMA_MSG_STORAGE_CARD1)
    {
        msgSet->dest_storage = MMA_MSG_STORAGE_PHONE;
    }

    msgSet->action_type = action_type;
    msgSet->app_id = MMA_APP_ID_MMS_APP;
    msgSet->req_id = mma_get_request_id();
    msgSet->msg_id = msg_id;
    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_WAP_MMA_CHG_MSG_STORAGE_REQ),
        0,
        MSG_ID_WAP_MMA_CHG_MSG_STORAGE_REQ,
        (oslParaType*) msgSet,
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_prefered_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_prefer_storage_enum     [IN]        
 *  flag                        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_prefered_storage(U8 mms_prefer_storage_enum, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 mms_msg_filter_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_mms_prefer_storage = mms_prefer_storage_enum;
    WriteValue(NVRAM_SETTING_PREFER_MMS_STORAGE_MODE, &nvram_mms_prefer_storage, DS_BYTE, &error);
    mms_msg_filter_flag = srv_mms_get_msg_filter();
    if(mms_prefer_storage_enum == E_PREFER_STORAGE_MODE_PHONE)
    {
        mms_msg_filter_flag = mms_msg_filter_flag | E_MSG_FILTER_PHONE;
    }
    else
    {
        mms_msg_filter_flag = mms_msg_filter_flag | E_MSG_FILTER_CARD;
    }
    srv_mms_set_msg_filter(mms_msg_filter_flag);
    srv_mms_send_events(EVT_ID_SRV_SET_SETTING, NULL);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    srv_mms_show_status_icon();
#endif 

}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_prefered_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_prefer_storage_enum     [IN]        
 *  flag                        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_msg_filter(U8 mms_msg_filter_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_mms_msg_filter = mms_msg_filter_flag;
    WriteValue(NVRAM_SETTING_MMS_MSG_FILTER, &nvram_mms_msg_filter, DS_BYTE, &error);
    srv_mms_send_events(EVT_ID_SRV_SET_SETTING, NULL);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    srv_mms_show_status_icon();
#endif 

}


#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_prefered_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mms_prefer_storage_enum     [IN]        
 *  flag                        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_mms_get_msg_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return(nvram_mms_msg_filter);
}

/***************************call from JSR*****************************************/

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_phone_suit_template_support_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_phone_suit_template_support_callback(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_send_events(EVT_ID_SRV_UPDATE_TEMPLTAE_DEL_FRM_PSUIT_SET_FLAG, (void*)&msg_id);
}
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 

#ifdef __MMI_FTE_SUPPORT__

extern mma_result_enum mma_mms_get_msg_attribute(kal_uint32 msg_id, mma_sync_msg_attribute_struct *msg_attribute);


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_reply_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_is_reply_on(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id);
    if (g_sync_msg_info_struct->msg_id != msg_id)
    {
        memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct));
        result = mma_mms_get_msg_attribute(msg_id, &(g_sync_msg_info_struct->msg_info));
        if (result != MMA_RESULT_OK)
        {
            return MMI_FALSE;
        }
        g_sync_msg_info_struct->msg_id = msg_id;
    }

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if ((g_sync_msg_info_struct->msg_info.folder == MMA_FOLDER_ARCHIVE) &&
        (g_sync_msg_info_struct->msg_info.prev_folder != MMA_FOLDER_INBOX))
    {
		if(g_sync_msg_info_struct->msg_info.prev_folder == MMA_FOLDER_NONE)
			{
               g_sync_msg_info_struct->msg_info.prev_folder = MMA_FOLDER_DRAFT ;
			}
        return MMI_FALSE;
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
    if ((g_sync_msg_info_struct->msg_info.folder == MMA_FOLDER_OUTBOX) ||
        (g_sync_msg_info_struct->msg_info.folder == MMA_FOLDER_SENT))
    {
        return MMI_FALSE;
    }

    if ((g_sync_msg_info_struct->msg_info.from_address[0] == '\0')
        || ((g_sync_msg_info_struct->msg_info.from_address_type != MMA_ADDR_TYPE_PHONE_NUMBER)
            && (g_sync_msg_info_struct->msg_info.from_address_type != MMA_ADDR_TYPE_EMAIL)))
    {
        return MMI_FALSE;
    }
    /* amit added */
    if (g_sync_msg_info_struct->msg_info.msg_type != MMA_MSG_TYPE_MMS)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_forward_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_is_forward_on(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id);
    if(g_sync_msg_info_struct->msg_id != msg_id)
    {
    memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct));
    result = mma_mms_get_msg_attribute(msg_id, &(g_sync_msg_info_struct->msg_info));
    if (result != MMA_RESULT_OK)
    {
        return MMI_FALSE;
    }
    g_sync_msg_info_struct->msg_id = msg_id;
    }
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    if ((g_sync_msg_info_struct->msg_info.folder == MMA_FOLDER_ARCHIVE) &&
        ((g_sync_msg_info_struct->msg_info.prev_folder == MMA_FOLDER_DRAFT) || (g_sync_msg_info_struct->msg_info.prev_folder == MMA_FOLDER_NONE)))
    {
        g_sync_msg_info_struct->msg_info.prev_folder = MMA_FOLDER_DRAFT ;
        return MMI_FALSE;
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
    if (g_sync_msg_info_struct->msg_info.folder == MMA_FOLDER_OUTBOX)
    {
        return MMI_FALSE;
    }

    if ((g_sync_msg_info_struct->msg_info.is_forward_lock) ||
        ((g_sync_msg_info_struct->msg_info.is_follow_phone_mms_content_class == KAL_FALSE)
         && (srv_mms_compose_settings_creation_mode() == MMA_CREATION_MODE_RESTRICTED)))
    {
        return MMI_FALSE;
    }

#ifdef __MMI_MMS_POSTCARD__
    if (g_sync_msg_info_struct->msg_info.msg_type == MMA_MSG_TYPE_POSTCARD)
    {
        return MMI_FALSE;
    }
#endif /* __MMI_MMS_POSTCARD__ */ 
    if (MMI_UMMS_LOCK_MODE_ON == g_sync_msg_info_struct->msg_info.is_lock_mode)
    {
        return MMI_FALSE;
    }
    /* amit added */
    if (g_sync_msg_info_struct->msg_info.msg_type != MMA_MSG_TYPE_MMS)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_edit_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_is_edit_on(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id);
    if (g_sync_msg_info_struct->msg_id != msg_id)
    {
        memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct));
        result = mma_mms_get_msg_attribute(msg_id, &(g_sync_msg_info_struct->msg_info));
        if (result != MMA_RESULT_OK)
        {
            return MMI_FALSE;
        }
        g_sync_msg_info_struct->msg_id = msg_id;
    }

    if (g_sync_msg_info_struct->msg_info.is_forward_lock == KAL_TRUE)
    {
        return MMI_FALSE;

    }
    /* if(srv_mms_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_SENDING)
       {
       return MMI_FALSE;
       } */

    if (MMI_UMMS_LOCK_MODE_ON == g_sync_msg_info_struct->msg_info.is_lock_mode)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_delete_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_is_delete_on(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id);
    if (g_sync_msg_info_struct->msg_id != msg_id)
    {
        memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct));
        result = mma_mms_get_msg_attribute(msg_id, &(g_sync_msg_info_struct->msg_info));
        if (result != MMA_RESULT_OK)
        {
            return MMI_FALSE;
        }
        g_sync_msg_info_struct->msg_id = msg_id;
    }
    if (g_sync_msg_info_struct->msg_info.folder == MMA_FOLDER_TEMPLATE)
    {
        return MMI_FALSE;
    }
    /* if((srv_mms_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_SENDING) 
       || (srv_mms_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_DOWNLOADING))
       {
       return MMI_FALSE;
       } */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_resend_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_is_resend_on(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id);
    if(srv_mms_num_valid_sim() == 0)
    {
        return MMI_FALSE;
    }
    if (g_sync_msg_info_struct->msg_id != msg_id)
    {
        memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct));
        result = mma_mms_get_msg_attribute(msg_id, &(g_sync_msg_info_struct->msg_info));
        if (result != MMA_RESULT_OK)
        {
            return MMI_FALSE;
        }
        g_sync_msg_info_struct->msg_id = msg_id;
    }
    /* if(srv_mms_bgsr_get_msg_status(msg_id) == SRV_MMS_BGSR_STATUS_SENDING)
       {
       return MMI_FALSE;
       } */
    if ((g_sync_msg_info_struct->msg_info.is_forward_lock) ||
        ((g_sync_msg_info_struct->msg_info.is_follow_phone_mms_content_class == KAL_FALSE)
         && (srv_mms_compose_settings_creation_mode() == MMA_CREATION_MODE_RESTRICTED)))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_send_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_is_send_on(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id);
    if (g_sync_msg_info_struct->msg_id != msg_id)
    {
        memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct));
        result = mma_mms_get_msg_attribute(msg_id, &(g_sync_msg_info_struct->msg_info));
        if (result != MMA_RESULT_OK)
        {
            return MMI_FALSE;
        }
        g_sync_msg_info_struct->msg_id = msg_id;
    }
    if (g_sync_msg_info_struct->msg_info.msg_type == MMA_MSG_TYPE_POSTCARD)
    {
        return MMI_FALSE;
    }

    if ((g_sync_msg_info_struct->msg_info.is_forward_lock) ||
        ((g_sync_msg_info_struct->msg_info.is_follow_phone_mms_content_class == KAL_FALSE)
         && (srv_mms_compose_settings_creation_mode() == MMA_CREATION_MODE_RESTRICTED)))
    {
        return MMI_FALSE;
    }

    return MMI_FALSE;   /* return MMI_TRUE;send option removed so disabled in FTE also */
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sync_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_sync_msg_info_struct *srv_mms_get_sync_msg_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_sync_msg_info_struct;
}
#endif /* __MMI_FTE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sync_msg_info_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_sync_msg_info_struct *srv_mms_get_sync_msg_info_ex(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct));
    g_sync_msg_info_struct->result = mma_mms_get_msg_attribute(msg_id, &(g_sync_msg_info_struct->msg_info));

    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_SRV_MMS_SYNC_MSG_INFO_1,
        msg_id,
        g_sync_msg_info_struct->result,
        g_sync_msg_info_struct->msg_info.user_elements_size,
        g_sync_msg_info_struct->msg_info.msg_size,
        g_sync_msg_info_struct->msg_info.timestamp,
        g_sync_msg_info_struct->msg_info.is_follow_phone_mms_content_class);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_SRV_MMS_SYNC_MSG_INFO_2,
        g_sync_msg_info_struct->msg_info.is_forward_lock,
        g_sync_msg_info_struct->msg_info.is_lock_mode,
        g_sync_msg_info_struct->msg_info.is_msg_corrupt,
        g_sync_msg_info_struct->msg_info.msg_type,
        g_sync_msg_info_struct->msg_info.folder,
        g_sync_msg_info_struct->msg_info.msg_sim_id);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_SRV_MMS_SYNC_MSG_INFO_3,
        g_sync_msg_info_struct->msg_info.from_address_type,
        g_sync_msg_info_struct->msg_info.msg_storage,
        g_sync_msg_info_struct->msg_info.prev_folder,
        g_sync_msg_info_struct->msg_info.need_read_report,
        0,
        0);

    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_SRV_MMS_SYNC_MSG_INFO_4,
        g_sync_msg_info_struct->msg_info.from_address[0],
        g_sync_msg_info_struct->msg_info.from_address[1],
        g_sync_msg_info_struct->msg_info.from_address[2],
        g_sync_msg_info_struct->msg_info.from_address[3],
        g_sync_msg_info_struct->msg_info.from_address[4],
        g_sync_msg_info_struct->msg_info.from_address[5],
        g_sync_msg_info_struct->msg_info.from_address[6],
        g_sync_msg_info_struct->msg_info.from_address[7],
        g_sync_msg_info_struct->msg_info.from_address[8],
        g_sync_msg_info_struct->msg_info.from_address[9]);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_SRV_MMS_SYNC_MSG_INFO_4,
        g_sync_msg_info_struct->msg_info.from_address[10],
        g_sync_msg_info_struct->msg_info.from_address[11],
        g_sync_msg_info_struct->msg_info.from_address[12],
        g_sync_msg_info_struct->msg_info.from_address[13],
        g_sync_msg_info_struct->msg_info.from_address[14],
        g_sync_msg_info_struct->msg_info.from_address[15],
        g_sync_msg_info_struct->msg_info.from_address[16],
        g_sync_msg_info_struct->msg_info.from_address[17],
        g_sync_msg_info_struct->msg_info.from_address[18],
        g_sync_msg_info_struct->msg_info.from_address[19]);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_SRV_MMS_SYNC_MSG_INFO_4,
        g_sync_msg_info_struct->msg_info.from_address[20],
        g_sync_msg_info_struct->msg_info.from_address[21],
        g_sync_msg_info_struct->msg_info.from_address[22],
        g_sync_msg_info_struct->msg_info.from_address[23],
        g_sync_msg_info_struct->msg_info.from_address[24],
        g_sync_msg_info_struct->msg_info.from_address[25],
        g_sync_msg_info_struct->msg_info.from_address[26],
        g_sync_msg_info_struct->msg_info.from_address[27],
        g_sync_msg_info_struct->msg_info.from_address[28],
        g_sync_msg_info_struct->msg_info.from_address[29]);

    g_sync_msg_info_struct->msg_id = msg_id;
    return g_sync_msg_info_struct;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_storage
 * DESCRIPTION
 *  This API returns storage of a message
 * PARAMETERS
 *  msg_id      [IN]        - Message ID
 * RETURNS
 *  srv_mms_msg_storage_enum - Message storage. Returns SRV_MMS_STORAGE_NONE for
 *  Error/Fail
 *****************************************************************************/
srv_mms_msg_storage_enum srv_mms_get_msg_storage(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct)); */
    /* g_sync_msg_info_struct->result = mma_mms_get_msg_attribute(msg_id, &(g_sync_msg_info_struct->msg_info)); */

    if (mma_get_mms_storage(msg_id) == MMA_MSG_STORAGE_PHONE)
    {
        return SRV_MMS_STORAGE_PHONE;
    }
    else if (mma_get_mms_storage(msg_id) == MMA_MSG_STORAGE_CARD1)
    {
        return SRV_MMS_STORAGE_CARD1;
    }
    else
    {
        return SRV_MMS_STORAGE_NONE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_reset_sync_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_reset_sync_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_get_sync_msg_info_user_data_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [?]         
 *  alloc_fn        [IN]        
 *  free_fn         [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_mma_get_sync_msg_info_user_data_input(
        U32 msg_id,
        srv_mms_mma_get_msg_info_struct *msg_info,
        srv_mms_func_mem_alloc_user_data alloc_fn,
        srv_mms_func_mem_free free_fn,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_alloc_ext = alloc_fn;
    g_ext_user_data = user_data;
    return srv_mms_mma_get_sync_msg_info(msg_id, msg_info, srv_mms_alloc_ext, free_fn);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_alloc_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_mms_alloc_ext(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_alloc_ext(size, g_ext_user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_get_mms_read_status
 * DESCRIPTION
 *  This API gives message status
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  [TRUE] if message is read
 *  [FALSE]o/w
 *****************************************************************************/
MMI_BOOL srv_mms_mma_get_mms_read_status(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_uint8 read = mma_get_mms_read_status(msg_id);
    if (read)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mma_get_sync_msg_info
 * DESCRIPTION
 *  This API gets a msg information in sync operation
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [?]         
 *  alloc_fn        [IN]        
 *  free_fn         [IN]        
 * RETURNS
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_mma_get_sync_msg_info(
        U32 msg_id,
        srv_mms_mma_get_msg_info_struct *msg_info,
        srv_mms_func_mem_alloc alloc_fn,
        srv_mms_func_mem_free free_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    mma_result_enum result = MMA_RESULT_OK;
    wap_mma_get_mms_msg_info_struct *mms_msg_info;
    U8 ph_num = 0, email_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg_info);
    ASSERT(msg_id);
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }
    mms_msg_info = (wap_mma_get_mms_msg_info_struct*) alloc_fn(sizeof(wap_mma_get_mms_msg_info_struct));
    ASSERT(mms_msg_info);
    memset(mms_msg_info, 0, sizeof(wap_mma_get_mms_msg_info_struct));
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    result = mma_mms_get_mms_msg_sync_info(msg_id, mms_msg_info, alloc_fn, free_fn);
#endif 
    msg_info->storage_type = mms_msg_info->storage_type;

    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_INFO_INFO_1,
        mms_msg_info->user_elements_size,
        mms_msg_info->msg_size,
        mms_msg_info->msg_download_size,
        mms_msg_info->date,
        mms_msg_info->expiry_date,
        mms_msg_info->received_date);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_INFO_INFO_2,
        mms_msg_info->need_read_report,
        mms_msg_info->need_delivery_report,
        mms_msg_info->isRead,
        mms_msg_info->isForwardlock,
        mms_msg_info->is_follow_phone_mms_content_class,
        mms_msg_info->result);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_INFO_INFO_3,
        mms_msg_info->storage_type,
        mms_msg_info->msg_media_type,
        mms_msg_info->from_address_type,
        mms_msg_info->msg_type,
        mms_msg_info->msg_class,
        mms_msg_info->priority);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_INFO_INFO_4,
        mms_msg_info->sim_id,
        mms_msg_info->msg_report_status,
        mms_msg_info->to_addr_count,
        mms_msg_info->cc_addr_count,
        mms_msg_info->bcc_addr_count);

    if (result == MMA_RESULT_OK)
    {
        msg_info->user_elements_size = mms_msg_info->user_elements_size;
        msg_info->msg_size = mms_msg_info->msg_size;
        msg_info->msg_download_size = mms_msg_info->msg_download_size;
        msg_info->date = mms_msg_info->date;
        msg_info->expiry_date = mms_msg_info->expiry_date;
        msg_info->received_date = mms_msg_info->received_date;
        msg_info->need_read_report = mms_msg_info->need_read_report;
    #ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
        msg_info->need_delivery_report = mms_msg_info->need_delivery_report;
    #endif 
        msg_info->isRead = mms_msg_info->isRead;
        msg_info->isForwardlock = mms_msg_info->isForwardlock;
        msg_info->is_follow_phone_mms_content_class = mms_msg_info->is_follow_phone_mms_content_class;
        msg_info->result = mms_msg_info->result;
        msg_info->msg_media_type = mms_msg_info->msg_media_type;
        msg_info->from_address_type = mms_msg_info->from_address_type;
        msg_info->msg_type = mms_msg_info->msg_type;
        msg_info->msg_class = mms_msg_info->msg_class;
        msg_info->priority = mms_msg_info->priority;
        msg_info->sim_id = mms_msg_info->sim_id;
        msg_info->msg_report_status = mms_msg_info->msg_report_status;
        msg_info->to_addr_count = mms_msg_info->to_addr_count;
        msg_info->cc_addr_count = mms_msg_info->cc_addr_count;
        msg_info->bcc_addr_count = mms_msg_info->bcc_addr_count;

        memcpy((PS8) msg_info->app_data, (PS8) mms_msg_info->app_data, MMA_MAX_APP_DATA_LENGTH);

        mmi_ucs2ncpy((PS8) msg_info->java_app_id, (PS8) mms_msg_info->java_app_id, SRV_MMS_MAX_COMM_STRING_LENGTH);

        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            1,
            mms_msg_info->java_app_id[0],
            mms_msg_info->java_app_id[1],
            mms_msg_info->java_app_id[2],
            mms_msg_info->java_app_id[3],
            mms_msg_info->java_app_id[4],
            mms_msg_info->java_app_id[5],
            mms_msg_info->java_app_id[6],
            mms_msg_info->java_app_id[7],
            mms_msg_info->java_app_id[8],
            mms_msg_info->java_app_id[9]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            2,
            mms_msg_info->java_app_id[10],
            mms_msg_info->java_app_id[11],
            mms_msg_info->java_app_id[12],
            mms_msg_info->java_app_id[13],
            mms_msg_info->java_app_id[14],
            mms_msg_info->java_app_id[15],
            mms_msg_info->java_app_id[16],
            mms_msg_info->java_app_id[17],
            mms_msg_info->java_app_id[18],
            mms_msg_info->java_app_id[19]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            3,
            mms_msg_info->java_app_id[20],
            mms_msg_info->java_app_id[21],
            mms_msg_info->java_app_id[22],
            mms_msg_info->java_app_id[23],
            mms_msg_info->java_app_id[24],
            mms_msg_info->java_app_id[25],
            mms_msg_info->java_app_id[26],
            mms_msg_info->java_app_id[27],
            mms_msg_info->java_app_id[28],
            mms_msg_info->java_app_id[29]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            4,
            mms_msg_info->java_app_id[30],
            mms_msg_info->java_app_id[31],
            mms_msg_info->java_app_id[32],
            mms_msg_info->java_app_id[33],
            mms_msg_info->java_app_id[34],
            mms_msg_info->java_app_id[35],
            mms_msg_info->java_app_id[36],
            mms_msg_info->java_app_id[37],
            mms_msg_info->java_app_id[38],
            mms_msg_info->java_app_id[39]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            5,
            mms_msg_info->java_app_id[40],
            mms_msg_info->java_app_id[41],
            mms_msg_info->java_app_id[42],
            mms_msg_info->java_app_id[43],
            mms_msg_info->java_app_id[44],
            mms_msg_info->java_app_id[45],
            mms_msg_info->java_app_id[46],
            mms_msg_info->java_app_id[47],
            mms_msg_info->java_app_id[48],
            mms_msg_info->java_app_id[49]);

        mmi_ucs2ncpy((PS8) msg_info->from_address, (PS8) mms_msg_info->from_address, MMA_MAX_ADDR_LEN);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            11,
            mms_msg_info->from_address[0],
            mms_msg_info->from_address[1],
            mms_msg_info->from_address[2],
            mms_msg_info->from_address[3],
            mms_msg_info->from_address[4],
            mms_msg_info->from_address[5],
            mms_msg_info->from_address[6],
            mms_msg_info->from_address[7],
            mms_msg_info->from_address[8],
            mms_msg_info->from_address[9]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            12,
            mms_msg_info->from_address[10],
            mms_msg_info->from_address[11],
            mms_msg_info->from_address[12],
            mms_msg_info->from_address[13],
            mms_msg_info->from_address[14],
            mms_msg_info->from_address[15],
            mms_msg_info->from_address[16],
            mms_msg_info->from_address[17],
            mms_msg_info->from_address[18],
            mms_msg_info->from_address[19]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            13,
            mms_msg_info->from_address[20],
            mms_msg_info->from_address[21],
            mms_msg_info->from_address[22],
            mms_msg_info->from_address[23],
            mms_msg_info->from_address[24],
            mms_msg_info->from_address[25],
            mms_msg_info->from_address[26],
            mms_msg_info->from_address[27],
            mms_msg_info->from_address[28],
            mms_msg_info->from_address[29]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            14,
            mms_msg_info->from_address[30],
            mms_msg_info->from_address[31],
            mms_msg_info->from_address[32],
            mms_msg_info->from_address[33],
            mms_msg_info->from_address[34],
            mms_msg_info->from_address[35],
            mms_msg_info->from_address[36],
            mms_msg_info->from_address[37],
            mms_msg_info->from_address[38],
            mms_msg_info->from_address[39]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            15,
            mms_msg_info->from_address[40],
            mms_msg_info->from_address[41],
            mms_msg_info->from_address[42],
            mms_msg_info->from_address[43],
            mms_msg_info->from_address[44],
            mms_msg_info->from_address[45],
            mms_msg_info->from_address[46],
            mms_msg_info->from_address[47],
            mms_msg_info->from_address[48],
            mms_msg_info->from_address[49]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            16,
            mms_msg_info->from_address[50],
            mms_msg_info->from_address[51],
            mms_msg_info->from_address[52],
            mms_msg_info->from_address[53],
            mms_msg_info->from_address[54],
            mms_msg_info->from_address[55],
            mms_msg_info->from_address[56],
            mms_msg_info->from_address[57],
            mms_msg_info->from_address[58],
            mms_msg_info->from_address[59]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            17,
            mms_msg_info->from_address[60],
            mms_msg_info->from_address[61],
            mms_msg_info->from_address[62],
            mms_msg_info->from_address[63],
            mms_msg_info->from_address[64],
            mms_msg_info->from_address[65],
            mms_msg_info->from_address[66],
            mms_msg_info->from_address[67],
            mms_msg_info->from_address[68],
            mms_msg_info->from_address[69]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            18,
            mms_msg_info->from_address[70],
            mms_msg_info->from_address[71],
            mms_msg_info->from_address[72],
            mms_msg_info->from_address[73],
            mms_msg_info->from_address[74],
            mms_msg_info->from_address[75],
            mms_msg_info->from_address[76],
            mms_msg_info->from_address[77],
            mms_msg_info->from_address[78],
            mms_msg_info->from_address[79]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            19,
            mms_msg_info->from_address[80],
            mms_msg_info->from_address[81],
            mms_msg_info->from_address[82],
            mms_msg_info->from_address[83],
            mms_msg_info->from_address[84],
            mms_msg_info->from_address[85],
            mms_msg_info->from_address[86],
            mms_msg_info->from_address[87],
            mms_msg_info->from_address[88],
            mms_msg_info->from_address[89]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            20,
            mms_msg_info->from_address[90],
            mms_msg_info->from_address[91],
            mms_msg_info->from_address[92],
            mms_msg_info->from_address[93],
            mms_msg_info->from_address[94],
            mms_msg_info->from_address[95],
            mms_msg_info->from_address[96],
            mms_msg_info->from_address[97],
            mms_msg_info->from_address[98],
            mms_msg_info->from_address[99]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            21,
            mms_msg_info->from_address[100],
            mms_msg_info->from_address[101],
            mms_msg_info->from_address[102],
            mms_msg_info->from_address[103],
            mms_msg_info->from_address[104],
            mms_msg_info->from_address[105],
            mms_msg_info->from_address[106],
            mms_msg_info->from_address[107],
            mms_msg_info->from_address[108],
            mms_msg_info->from_address[109]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            22,
            mms_msg_info->from_address[110],
            mms_msg_info->from_address[111],
            mms_msg_info->from_address[112],
            mms_msg_info->from_address[113],
            mms_msg_info->from_address[114],
            mms_msg_info->from_address[115],
            mms_msg_info->from_address[116],
            mms_msg_info->from_address[117],
            mms_msg_info->from_address[118],
            mms_msg_info->from_address[119]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            23,
            mms_msg_info->from_address[120],
            mms_msg_info->from_address[121],
            mms_msg_info->from_address[122],
            mms_msg_info->from_address[123],
            mms_msg_info->from_address[124],
            mms_msg_info->from_address[125],
            mms_msg_info->from_address[126],
            mms_msg_info->from_address[127],
            255,
            255);

        mmi_ucs2ncpy((PS8) msg_info->subject, (PS8) mms_msg_info->subject, MMA_MAX_SUBJECT_LEN);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            41,
            mms_msg_info->subject[0],
            mms_msg_info->subject[1],
            mms_msg_info->subject[2],
            mms_msg_info->subject[3],
            mms_msg_info->subject[4],
            mms_msg_info->subject[5],
            mms_msg_info->subject[6],
            mms_msg_info->subject[7],
            mms_msg_info->subject[8],
            mms_msg_info->subject[9]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            42,
            mms_msg_info->subject[10],
            mms_msg_info->subject[11],
            mms_msg_info->subject[12],
            mms_msg_info->subject[13],
            mms_msg_info->subject[14],
            mms_msg_info->subject[15],
            mms_msg_info->subject[16],
            mms_msg_info->subject[17],
            mms_msg_info->subject[18],
            mms_msg_info->subject[19]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            43,
            mms_msg_info->subject[20],
            mms_msg_info->subject[21],
            mms_msg_info->subject[22],
            mms_msg_info->subject[23],
            mms_msg_info->subject[24],
            mms_msg_info->subject[25],
            mms_msg_info->subject[26],
            mms_msg_info->subject[27],
            mms_msg_info->subject[28],
            mms_msg_info->subject[29]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            44,
            mms_msg_info->subject[30],
            mms_msg_info->subject[31],
            mms_msg_info->subject[32],
            mms_msg_info->subject[33],
            mms_msg_info->subject[34],
            mms_msg_info->subject[35],
            mms_msg_info->subject[36],
            mms_msg_info->subject[37],
            mms_msg_info->subject[38],
            mms_msg_info->subject[39]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            45,
            mms_msg_info->subject[40],
            255,
            255,
            255,
            255,
            255,
            255,
            255,
            255,
            255);

        mmi_ucs2ncpy((PS8) msg_info->reported_subject, (PS8) mms_msg_info->reported_subject, MMA_MAX_SUBJECT_LEN);

        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            51,
            mms_msg_info->reported_subject[0],
            mms_msg_info->reported_subject[1],
            mms_msg_info->reported_subject[2],
            mms_msg_info->reported_subject[3],
            mms_msg_info->reported_subject[4],
            mms_msg_info->reported_subject[5],
            mms_msg_info->reported_subject[6],
            mms_msg_info->reported_subject[7],
            mms_msg_info->reported_subject[8],
            mms_msg_info->reported_subject[9]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            52,
            mms_msg_info->reported_subject[10],
            mms_msg_info->reported_subject[11],
            mms_msg_info->reported_subject[12],
            mms_msg_info->reported_subject[13],
            mms_msg_info->reported_subject[14],
            mms_msg_info->reported_subject[15],
            mms_msg_info->reported_subject[16],
            mms_msg_info->reported_subject[17],
            mms_msg_info->reported_subject[18],
            mms_msg_info->reported_subject[19]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            53,
            mms_msg_info->reported_subject[20],
            mms_msg_info->reported_subject[21],
            mms_msg_info->reported_subject[22],
            mms_msg_info->reported_subject[23],
            mms_msg_info->reported_subject[24],
            mms_msg_info->reported_subject[25],
            mms_msg_info->reported_subject[26],
            mms_msg_info->reported_subject[27],
            mms_msg_info->reported_subject[28],
            mms_msg_info->reported_subject[29]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            54,
            mms_msg_info->reported_subject[30],
            mms_msg_info->reported_subject[31],
            mms_msg_info->reported_subject[32],
            mms_msg_info->reported_subject[33],
            mms_msg_info->reported_subject[34],
            mms_msg_info->reported_subject[35],
            mms_msg_info->reported_subject[36],
            mms_msg_info->reported_subject[37],
            mms_msg_info->reported_subject[38],
            mms_msg_info->reported_subject[39]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_5,
            55,
            mms_msg_info->reported_subject[40],
            255,
            255,
            255,
            255,
            255,
            255,
            255,
            255,
            255);

        if (mms_msg_info->from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            ph_num++;
        }
        else if (mms_msg_info->from_address_type == MMA_ADDR_TYPE_EMAIL)
        {
            email_num++;
        }
        for (count = 0; count < MMA_MAX_SUPPORT_ADDR_COUNT; ++count)
        {
            if (mms_msg_info->address[count].addr_len > 0)
            {
                msg_info->address[count].addr_len = mms_msg_info->address[count].addr_len;
                msg_info->address[count].addr_group =
                    (kal_uint8) srv_mms_convert_mma_addr_group_to_srv_addr_group((mma_address_group_type_enum)
                                                                                 mms_msg_info->address[count].
                                                                                 addr_group);
                msg_info->address[count].addr_type = srv_mms_convert_mma_addr_type_to_srv_addr_type((mma_addr_type_enum) mms_msg_info->address[count].
                                                                   addr_type);

                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_6,
                    mms_msg_info->address[count].addr_len,
                    mms_msg_info->address[count].addr_group,
                    mms_msg_info->address[count].addr_type);

                mmi_ucs2ncpy(
                    (PS8) msg_info->address[count].address,
                    (PS8) mms_msg_info->address[count].address,
                    MMA_MAX_ADDR_LEN);

                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    61,
                    mms_msg_info->address[count].address[0],
                    mms_msg_info->address[count].address[1],
                    mms_msg_info->address[count].address[2],
                    mms_msg_info->address[count].address[3],
                    mms_msg_info->address[count].address[4],
                    mms_msg_info->address[count].address[5],
                    mms_msg_info->address[count].address[6],
                    mms_msg_info->address[count].address[7],
                    mms_msg_info->address[count].address[8],
                    mms_msg_info->address[count].address[9]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    62,
                    mms_msg_info->address[count].address[10],
                    mms_msg_info->address[count].address[11],
                    mms_msg_info->address[count].address[12],
                    mms_msg_info->address[count].address[13],
                    mms_msg_info->address[count].address[14],
                    mms_msg_info->address[count].address[15],
                    mms_msg_info->address[count].address[16],
                    mms_msg_info->address[count].address[17],
                    mms_msg_info->address[count].address[18],
                    mms_msg_info->address[count].address[19]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    63,
                    mms_msg_info->address[count].address[20],
                    mms_msg_info->address[count].address[21],
                    mms_msg_info->address[count].address[22],
                    mms_msg_info->address[count].address[23],
                    mms_msg_info->address[count].address[24],
                    mms_msg_info->address[count].address[25],
                    mms_msg_info->address[count].address[26],
                    mms_msg_info->address[count].address[27],
                    mms_msg_info->address[count].address[28],
                    mms_msg_info->address[count].address[29]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    64,
                    mms_msg_info->address[count].address[30],
                    mms_msg_info->address[count].address[31],
                    mms_msg_info->address[count].address[32],
                    mms_msg_info->address[count].address[33],
                    mms_msg_info->address[count].address[34],
                    mms_msg_info->address[count].address[35],
                    mms_msg_info->address[count].address[36],
                    mms_msg_info->address[count].address[37],
                    mms_msg_info->address[count].address[38],
                    mms_msg_info->address[count].address[39]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    65,
                    mms_msg_info->address[count].address[40],
                    mms_msg_info->address[count].address[41],
                    mms_msg_info->address[count].address[42],
                    mms_msg_info->address[count].address[43],
                    mms_msg_info->address[count].address[44],
                    mms_msg_info->address[count].address[45],
                    mms_msg_info->address[count].address[46],
                    mms_msg_info->address[count].address[47],
                    mms_msg_info->address[count].address[48],
                    mms_msg_info->address[count].address[49]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    66,
                    mms_msg_info->address[count].address[50],
                    mms_msg_info->address[count].address[51],
                    mms_msg_info->address[count].address[52],
                    mms_msg_info->address[count].address[53],
                    mms_msg_info->address[count].address[54],
                    mms_msg_info->address[count].address[55],
                    mms_msg_info->address[count].address[56],
                    mms_msg_info->address[count].address[57],
                    mms_msg_info->address[count].address[58],
                    mms_msg_info->address[count].address[59]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    67,
                    mms_msg_info->address[count].address[60],
                    mms_msg_info->address[count].address[61],
                    mms_msg_info->address[count].address[62],
                    mms_msg_info->address[count].address[63],
                    mms_msg_info->address[count].address[64],
                    mms_msg_info->address[count].address[65],
                    mms_msg_info->address[count].address[66],
                    mms_msg_info->address[count].address[67],
                    mms_msg_info->address[count].address[68],
                    mms_msg_info->address[count].address[69]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    68,
                    mms_msg_info->address[count].address[70],
                    mms_msg_info->address[count].address[71],
                    mms_msg_info->address[count].address[72],
                    mms_msg_info->address[count].address[73],
                    mms_msg_info->address[count].address[74],
                    mms_msg_info->address[count].address[75],
                    mms_msg_info->address[count].address[76],
                    mms_msg_info->address[count].address[77],
                    mms_msg_info->address[count].address[78],
                    mms_msg_info->address[count].address[79]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    69,
                    mms_msg_info->address[count].address[80],
                    mms_msg_info->address[count].address[81],
                    mms_msg_info->address[count].address[82],
                    mms_msg_info->address[count].address[83],
                    mms_msg_info->address[count].address[84],
                    mms_msg_info->address[count].address[85],
                    mms_msg_info->address[count].address[86],
                    mms_msg_info->address[count].address[87],
                    mms_msg_info->address[count].address[88],
                    mms_msg_info->address[count].address[89]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    70,
                    mms_msg_info->address[count].address[90],
                    mms_msg_info->address[count].address[91],
                    mms_msg_info->address[count].address[92],
                    mms_msg_info->address[count].address[93],
                    mms_msg_info->address[count].address[94],
                    mms_msg_info->address[count].address[95],
                    mms_msg_info->address[count].address[96],
                    mms_msg_info->address[count].address[97],
                    mms_msg_info->address[count].address[98],
                    mms_msg_info->address[count].address[99]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    71,
                    mms_msg_info->address[count].address[100],
                    mms_msg_info->address[count].address[101],
                    mms_msg_info->address[count].address[102],
                    mms_msg_info->address[count].address[103],
                    mms_msg_info->address[count].address[104],
                    mms_msg_info->address[count].address[105],
                    mms_msg_info->address[count].address[106],
                    mms_msg_info->address[count].address[107],
                    mms_msg_info->address[count].address[108],
                    mms_msg_info->address[count].address[109]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    72,
                    mms_msg_info->address[count].address[110],
                    mms_msg_info->address[count].address[111],
                    mms_msg_info->address[count].address[112],
                    mms_msg_info->address[count].address[113],
                    mms_msg_info->address[count].address[114],
                    mms_msg_info->address[count].address[115],
                    mms_msg_info->address[count].address[116],
                    mms_msg_info->address[count].address[117],
                    mms_msg_info->address[count].address[118],
                    mms_msg_info->address[count].address[119]);
                MMI_TRACE(
                    MMI_INET_TRC_G6_MMS,
                    MMI_TRC_UMMS_MSG_INFO_INFO_5,
                    73,
                    mms_msg_info->address[count].address[120],
                    mms_msg_info->address[count].address[121],
                    mms_msg_info->address[count].address[122],
                    mms_msg_info->address[count].address[123],
                    mms_msg_info->address[count].address[124],
                    mms_msg_info->address[count].address[125],
                    mms_msg_info->address[count].address[126],
                    mms_msg_info->address[count].address[127],
                    255,
                    255);

                if (msg_info->address[count].addr_type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    ph_num++;
                }
                else if (msg_info->address[count].addr_type == SRV_MMS_ADDRESS_TYPE_EMAIL)
                {
                    email_num++;
                }
            }
            else
            {
                break;
            }
        }
        msg_info->ph_num = ph_num;
        msg_info->email_num = email_num;

        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_INFO_INFO_7,
            mms_msg_info->app_data[0],
            mms_msg_info->app_data[1],
            mms_msg_info->app_data[2],
            ph_num,
            email_num);
    }
    else
    {
        msg_info->result = result;
    }
    free_fn(mms_msg_info);
    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_mms_msg_addr_info
 * DESCRIPTION
 *  This function gets the detail single msg info from MMA in blocking call
 * PARAMETERS
 *  msg_id          [IN]        Message id
 *  addr_info       [?]         [OUT]Group Address information
 *  to_count        [?]         
 *  cc_count        [?]         
 *  bcc_count       [?]         
 *  alloc_fn        [IN]        Callback func to allocate memory
 *  free_fn         [IN]        Callback func to free memory
 *  user_data       [IN]        User data of caller
 * RETURNS
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_get_mms_msg_addr_info(
        U32 msg_id,
        p_srv_mms_msg_report_status *addr_info,
        S32 *to_count,
        S32 *cc_count,
        S32 *bcc_count,
        srv_mms_func_mem_alloc_user_data alloc_fn,
        srv_mms_func_mem_free free_fn,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    wap_mma_mms_msg_report_status_struct *mms_msg_addr_info = NULL, *temp = NULL;
    int count = -1, base_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ext_user_data = user_data;
    g_srv_mms_alloc_ext = alloc_fn;
    mms_msg_addr_info = alloc_fn(sizeof(wap_mma_mms_msg_report_status_struct), user_data);
    if (mms_msg_addr_info == NULL)
    {
        return 0;
    }
    memset(mms_msg_addr_info, 0, sizeof(wap_mma_mms_msg_report_status_struct));
#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    result = mma_mms_get_msg_report_status_info(msg_id, mms_msg_addr_info, srv_mms_alloc_ext, free_fn);
#endif 
    while (mms_msg_addr_info != NULL)
    {
        if (mms_msg_addr_info->addr_len > 0 && result == MMA_RESULT_OK)
        {
            if (mms_msg_addr_info->addr_group == MMA_ADDRESS_GROUP_TYPE_TO)
            {
                count = ++(*to_count);
                base_index = 0;
            }
            else if (mms_msg_addr_info->addr_group == MMA_ADDRESS_GROUP_TYPE_CC)
            {
                count = ++(*cc_count);
                base_index = 1;
            }
            else if (mms_msg_addr_info->addr_group == MMA_ADDRESS_GROUP_TYPE_BCC)
            {
                count = ++(*bcc_count);
                base_index = 2;
            }
            addr_info[base_index][count].addr_len = mms_msg_addr_info->addr_len;
            addr_info[base_index][count].addr_group = mms_msg_addr_info->addr_group;
            addr_info[base_index][count].addr_type = mms_msg_addr_info->addr_type;
            mmi_ucs2ncpy(
                (PS8) addr_info[base_index][count].address,
                (PS8) mms_msg_addr_info->address,
                MMA_MAX_ADDR_LEN);
        }
        temp = mms_msg_addr_info;
        mms_msg_addr_info = mms_msg_addr_info->next;
        free_fn(temp);
        temp = NULL;
    }
    mms_msg_addr_info = NULL;

	return 0;
}

extern kal_uint8 mma_get_mms_msg_type(U32 msg_id);


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_java_mms
 * DESCRIPTION
 *  This function tells mms type is java or not
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  TRUE :[if message is Java]
 *  FALSE: [O/W]
 *****************************************************************************/
MMI_BOOL srv_mms_is_java_mms(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_type = mma_get_mms_msg_type(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_type == MMA_MSG_TYPE_JAVA)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_msg_exist
 * DESCRIPTION
 *  This function tells mms exists or not
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  TRUE :[if message exist]
 *  FALSE: [O/W]
 *****************************************************************************/
MMI_BOOL srv_mms_is_msg_exist(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_folder_enum msg_box =  mma_get_box(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box == MMA_FOLDER_NONE || msg_box == MMA_FOLDER_HIDDEN)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_delivery_report
 * DESCRIPTION
 *  This function tells mms type is delivery report or not
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  TRUE :[if message is Java]
 *  FALSE: [O/W]
 *****************************************************************************/
MMI_BOOL srv_mms_is_delivery_report(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_type = mma_get_mms_msg_type(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_type == MMA_MSG_TYPE_DELIVERY_REPORT)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_read_report
 * DESCRIPTION
 *  This function tells mms type is read report or not
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  TRUE :[if message is Java]
 *  FALSE: [O/W]
 *****************************************************************************/
MMI_BOOL srv_mms_is_read_report(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_type = mma_get_mms_msg_type(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_type == MMA_MSG_TYPE_READ_REPORT)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_corrupted_mms
 * DESCRIPTION
 *  This function tells mms type is corrupted or not
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  TRUE :[if message is corrupted or unsupported]
 *  FALSE: [O/W]
 *****************************************************************************/
MMI_BOOL srv_mms_is_corrupted_mms(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 msg_type = mma_get_mms_msg_type(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (msg_type == MMA_MSG_TYPE_UNSUPPORTED)
    //{
        return mma_is_mms_corrupted(msg_id);
    //}
    //else
    //{
     //   return MMI_FALSE;
    //}

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_msg_update_count_and_status_icon
 * DESCRIPTION
 *  This API gets message(s) number from MMA in sync operation and updates status icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_msg_update_count_and_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_msg_count_struct msg_count_req;
    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg_count_req, 0, sizeof(srv_mms_get_msg_count_struct));

    srv_mms_fill_msg_num_req_struct(&msg_count_req);
    result = srv_mms_get_msg_count(&msg_count_req);
    if (result == SRV_MMS_RESULT_OK)
    {
        srv_mms_update_folder_msg_num(&msg_count_req);

    /*********************amit added for a bug fix********************************/
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        srv_mms_send_events(EVT_ID_SRV_UPDATE_TEMPLTAE_DEL_FRM_PSUIT, NULL);
    #endif 
        srv_mms_send_events(EVT_ID_SRV_UPDATE_MEM_STATUS, NULL);
        srv_mms_update_status_icon_on_number_rsp();
    #ifdef __COSMOS_MMI_PACKAGE__
        srv_mms_send_mem_full();
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_count
 * DESCRIPTION
 *  This API gets message(s) number from MMA in sync operation
 * PARAMETERS
 *  msg_count_req       [?]     
 * RETURNS
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_get_msg_count(srv_mms_get_msg_count_struct *msg_count_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 n = 0;
    mma_result_enum result = MMA_RESULT_OK;

    /* srv_mms_folder_msg_count_status_struct msg_count; */
    mma_mms_folder_mms_count_status_struct count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        /* ASSERT(0); */
        return SRV_MMS_RESULT_NOT_READY;
    }
    MMI_ASSERT(msg_count_req);
    /* memset(&msg_count, 0, sizeof(srv_mms_folder_msg_count_status_struct)); */
    result = mma_mms_get_msg_folder_count(&count);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_COUNT_1,
        result,
        count.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num,
        count.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num,
        count.folder[MMA_INDEX_FOR_SIM1].inbox_read_msg_num,
        count.folder[MMA_INDEX_FOR_SIM2].inbox_read_msg_num);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_COUNT_1,
        result,
        count.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num,
        count.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num,
        count.folder[MMA_INDEX_FOR_SIM3].inbox_read_msg_num,
        count.folder[MMA_INDEX_FOR_SIM4].inbox_read_msg_num);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_COUNT_2,
        count.folder[1].unsent_msg_num,
        count.folder[2].unsent_msg_num,
        count.folder[1].sent_msg_num,
        count.folder[2].sent_msg_num,
        count.draft_msg_num,
        count.predefined_template_msg_num,
        count.userdefined_template_msg_num);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_COUNT_3,
        count.folder[1].archive_unread_inbox_msg_num,
        count.folder[2].archive_unread_inbox_msg_num,
        count.folder[1].archive_read_inbox_msg_num,
        count.folder[2].archive_read_inbox_msg_num);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_MSG_COUNT_4,
        count.folder[1].archive_sent_msg_num,
        count.folder[2].archive_sent_msg_num,
        count.archive_msg_num,
        count.recent_event_number,
        count.unread_report_msg_num,
        count.total_phone_mms,
        count.total_mcard_mms);

    if (result != MMA_RESULT_OK)
    {
        return SRV_MMS_RESULT_FAIL;
    }

    /* msg_count.inbox_unread_msg_num_sim1         =   count.inbox_unread_msg_num_sim1;
       msg_count.inbox_unread_msg_num_sim2         =   count.inbox_unread_msg_num_sim2;
       msg_count.inbox_read_msg_num_sim1           =   count.inbox_read_msg_num_sim1;
       msg_count.inbox_read_msg_num_sim2           =   count.inbox_read_msg_num_sim2;
       msg_count.unsent_msg_num_sim1               =   count.unsent_msg_num_sim1;
       msg_count.unsent_msg_num_sim2               =   count.unsent_msg_num_sim2;
       msg_count.sent_msg_num_sim1                 =   count.sent_msg_num_sim1;
       msg_count.sent_msg_num_sim2                 =   count.sent_msg_num_sim2;
       msg_count.draft_msg_num                     =   count.draft_msg_num;
       msg_count.predefined_template_msg_num       =   count.predefined_template_msg_num;
       msg_count.userdefined_template_msg_num      =   count.userdefined_template_msg_num;
       msg_count.archive_unread_inbox_msg_num_sim1 =   count.archive_unread_inbox_msg_num_sim1;
       msg_count.archive_unread_inbox_msg_num_sim2 =   count.archive_unread_inbox_msg_num_sim2;
       msg_count.archive_read_inbox_msg_num_sim1   =   count.archive_read_inbox_msg_num_sim1;
       msg_count.archive_read_inbox_msg_num_sim2   =   count.archive_read_inbox_msg_num_sim2;
       msg_count.archive_sent_msg_num_sim1         =   count.archive_sent_msg_num_sim1;
       msg_count.archive_sent_msg_num_sim2         =   count.archive_sent_msg_num_sim2;
       msg_count.archive_msg_num                   =   count.archive_msg_num;  
       msg_count.total_phone_mms                   =   count.total_phone_mms;
       msg_count.total_mcard_mms                   =   count.total_mcard_mms; 
       msg_count.recent_event_number               =   count.recent_event_number; */

    for (n = 0; n < msg_count_req->count; n++)
    {
        switch (msg_count_req->req_tb[n])
        {
            case SRV_MMS_QUERY_UNREAD_INBOX_MSG_SIM1:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num;
                break;
        #if(MMI_MAX_SIM_NUM >= 2)
            case SRV_MMS_QUERY_UNREAD_INBOX_MSG_SIM2:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case SRV_MMS_QUERY_UNREAD_INBOX_MSG_SIM3:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
            case SRV_MMS_QUERY_UNREAD_INBOX_MSG_SIM4:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
            case SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num
        #if(MMI_MAX_SIM_NUM >= 2)
                    + count.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 3)
                    + count.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 4)
                    + count.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num
        #endif 
                    ;
                break;

            case SRV_MMS_QUERY_TOTAL_READ_INBOX_MSG:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].inbox_read_msg_num
        #if(MMI_MAX_SIM_NUM >= 2)
                    + count.folder[MMA_INDEX_FOR_SIM2].inbox_read_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 3)
                    + count.folder[MMA_INDEX_FOR_SIM3].inbox_read_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 4)
                    + count.folder[MMA_INDEX_FOR_SIM4].inbox_read_msg_num
        #endif 
                    ;
                break;
            case SRV_MMS_QUERY_TOTAL_INBOX_SIM1:
                msg_count_req->rsp_tb[n] =
                    count.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM1].inbox_read_msg_num;
                break;
        #if(MMI_MAX_SIM_NUM >= 2)
            case SRV_MMS_QUERY_TOTAL_INBOX_SIM2:
                msg_count_req->rsp_tb[n] =
                    count.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM2].inbox_read_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case SRV_MMS_QUERY_TOTAL_INBOX_SIM3:
                msg_count_req->rsp_tb[n] =
                    count.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM3].inbox_read_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
            case SRV_MMS_QUERY_TOTAL_INBOX_SIM4:
                msg_count_req->rsp_tb[n] =
                    count.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM4].inbox_read_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
            case SRV_MMS_QUERY_TOTAL_INBOX_MSG:
                msg_count_req->rsp_tb[n] =
                    count.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM1].inbox_read_msg_num
        #if(MMI_MAX_SIM_NUM >= 2)
                    + count.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM2].inbox_read_msg_num
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
                    + count.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM3].inbox_read_msg_num
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
                    + count.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM4].inbox_read_msg_num
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
                    ;
                break;
            case SRV_MMS_QUERY_TOTAL_OUTBOX_SIM1:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].unsent_msg_num;
                break;
        #if(MMI_MAX_SIM_NUM >= 2)
            case SRV_MMS_QUERY_TOTAL_OUTBOX_SIM2:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM2].unsent_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case SRV_MMS_QUERY_TOTAL_OUTBOX_SIM3:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM3].unsent_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
            case SRV_MMS_QUERY_TOTAL_OUTBOX_SIM4:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM4].unsent_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 

            case SRV_MMS_QUERY_TOTAL_OUTBOX_MSG:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].unsent_msg_num
        #if(MMI_MAX_SIM_NUM >= 2)
                    + count.folder[MMA_INDEX_FOR_SIM2].unsent_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 3)
                    + count.folder[MMA_INDEX_FOR_SIM3].unsent_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 4)
                    + count.folder[MMA_INDEX_FOR_SIM4].unsent_msg_num
        #endif 
                    ;
                break;
            case SRV_MMS_QUERY_TOTAL_SENT_SIM1:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].sent_msg_num;
                break;
        #if(MMI_MAX_SIM_NUM >= 2)
            case SRV_MMS_QUERY_TOTAL_SENT_SIM2:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM2].sent_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case SRV_MMS_QUERY_TOTAL_SENT_SIM3:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM3].sent_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >=4)
            case SRV_MMS_QUERY_TOTAL_SENT_SIM4:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM4].sent_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >=4) */ 
            case SRV_MMS_QUERY_TOTAL_SENT_MSG:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].sent_msg_num
        #if(MMI_MAX_SIM_NUM >=2)
                    + count.folder[MMA_INDEX_FOR_SIM2].sent_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >=3)
                    + count.folder[MMA_INDEX_FOR_SIM3].sent_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >=4)
                    + count.folder[MMA_INDEX_FOR_SIM4].sent_msg_num
        #endif 
                    ;
                break;
            case SRV_MMS_QUERY_TOTAL_DRAFT_MSG:
                msg_count_req->rsp_tb[n] = count.draft_msg_num;
                break;
            case SRV_MMS_QUERY_UNREAD_ARCHIVE_MSG_SIM1:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].archive_unread_inbox_msg_num;
                break;
        #if(MMI_MAX_SIM_NUM >= 2)
            case SRV_MMS_QUERY_UNREAD_ARCHIVE_MSG_SIM2:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM2].archive_unread_inbox_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case SRV_MMS_QUERY_UNREAD_ARCHIVE_MSG_SIM3:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM3].archive_unread_inbox_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
            case SRV_MMS_QUERY_UNREAD_ARCHIVE_MSG_SIM4:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM4].archive_unread_inbox_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
            case SRV_MMS_QUERY_TOTAL_UNREAD_ARCHIVE_MSG:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].archive_unread_inbox_msg_num
        #if(MMI_MAX_SIM_NUM >= 2)
                    + count.folder[MMA_INDEX_FOR_SIM2].archive_unread_inbox_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 3)
                    + count.folder[MMA_INDEX_FOR_SIM3].archive_unread_inbox_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 4)
                    + count.folder[MMA_INDEX_FOR_SIM4].archive_unread_inbox_msg_num
        #endif 
                    ;
                break;
            case SRV_MMS_QUERY_TOTAL_ARCHIVE_SIM1:
                msg_count_req->rsp_tb[n] =
                    count.folder[MMA_INDEX_FOR_SIM1].archive_read_inbox_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM1].archive_unread_inbox_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM1].archive_sent_msg_num;
                break;
        #if(MMI_MAX_SIM_NUM >= 2)
            case SRV_MMS_QUERY_TOTAL_ARCHIVE_SIM2:
                msg_count_req->rsp_tb[n] =
                    count.folder[MMA_INDEX_FOR_SIM2].archive_read_inbox_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM2].archive_unread_inbox_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM2].archive_sent_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case SRV_MMS_QUERY_TOTAL_ARCHIVE_SIM3:
                msg_count_req->rsp_tb[n] =
                    count.folder[MMA_INDEX_FOR_SIM3].archive_read_inbox_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM3].archive_unread_inbox_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM3].archive_sent_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
            case SRV_MMS_QUERY_TOTAL_ARCHIVE_SIM4:
                msg_count_req->rsp_tb[n] =
                    count.folder[MMA_INDEX_FOR_SIM4].archive_read_inbox_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM4].archive_unread_inbox_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM4].archive_sent_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
            case SRV_MMS_QUERY_TOTAL_ARCHIVE_SENT:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].archive_sent_msg_num
        #if(MMI_MAX_SIM_NUM >= 2)
                    + count.folder[MMA_INDEX_FOR_SIM2].archive_sent_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 3)
                    + count.folder[MMA_INDEX_FOR_SIM3].archive_sent_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 4)
                    + count.folder[MMA_INDEX_FOR_SIM4].archive_sent_msg_num
        #endif 
                    ;
                break;
            case SRV_MMS_QUERY_TOTAL_ARCHIVE_INBOX:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].archive_unread_inbox_msg_num
                    + count.folder[MMA_INDEX_FOR_SIM1].archive_read_inbox_msg_num
        #if(MMI_MAX_SIM_NUM >= 2)
                    + count.folder[MMA_INDEX_FOR_SIM2].archive_unread_inbox_msg_num
                    + count.folder[MMA_INDEX_FOR_SIM2].archive_read_inbox_msg_num
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
                    + count.folder[MMA_INDEX_FOR_SIM3].archive_unread_inbox_msg_num +
                    count.folder[MMA_INDEX_FOR_SIM2].archive_read_inbox_msg_num
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
                    + count.folder[MMA_INDEX_FOR_SIM4].archive_unread_inbox_msg_num
                    + count.folder[MMA_INDEX_FOR_SIM4].archive_read_inbox_msg_num
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
                    ;
                break;
            case SRV_MMS_QUERY_TOTAL_ARCHIVE_UNCLASSIFIED:
                msg_count_req->rsp_tb[n] =
                    count.archive_msg_num - (count.folder[MMA_INDEX_FOR_SIM1].archive_sent_msg_num +
                                             count.folder[MMA_INDEX_FOR_SIM1].archive_unread_inbox_msg_num +
                                             count.folder[MMA_INDEX_FOR_SIM1].archive_read_inbox_msg_num
        #if(MMI_MAX_SIM_NUM >= 2)
                                             + count.folder[MMA_INDEX_FOR_SIM2].archive_sent_msg_num
                                             + count.folder[MMA_INDEX_FOR_SIM2].archive_unread_inbox_msg_num
                                             + count.folder[MMA_INDEX_FOR_SIM2].archive_read_inbox_msg_num
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
                                             + count.folder[MMA_INDEX_FOR_SIM3].archive_sent_msg_num
                                             + count.folder[MMA_INDEX_FOR_SIM3].archive_unread_inbox_msg_num
                                             + count.folder[MMA_INDEX_FOR_SIM3].archive_read_inbox_msg_num
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
                                             + count.folder[MMA_INDEX_FOR_SIM4].archive_sent_msg_num
                                             + count.folder[MMA_INDEX_FOR_SIM4].archive_unread_inbox_msg_num
                                             + count.folder[MMA_INDEX_FOR_SIM4].archive_read_inbox_msg_num
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
                    );
                break;
            case SRV_MMS_QUERY_TOTAL_ARCHIVE_MSG:
                msg_count_req->rsp_tb[n] = count.archive_msg_num;
                break;
            case SRV_MMS_QUERY_TOTAL_USER_DEF_TEMPLATE_MSG:
                msg_count_req->rsp_tb[n] = count.userdefined_template_msg_num;
                break;
            case SRV_MMS_QUERY_TOTAL_PRE_DEF_TEMPLATE_MSG:
                msg_count_req->rsp_tb[n] = count.predefined_template_msg_num;
                break;
            case SRV_MMS_QUERY_TOTAL_UNREAD_MSG:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num
        #if(MMI_MAX_SIM_NUM >= 2)
                    + count.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 3)
                    + count.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num
        #endif 
        #if(MMI_MAX_SIM_NUM >= 4)
                    + count.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num
        #endif 
                    ;
                break;

            case SRV_MMS_QUERY_UNREAD_TOTAL_MSG_SIM1:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num;
                break;
        #if(MMI_MAX_SIM_NUM >= 2)
            case SRV_MMS_QUERY_UNREAD_TOTAL_MSG_SIM2:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */ 
        #if(MMI_MAX_SIM_NUM >= 3)
            case SRV_MMS_QUERY_UNREAD_TOTAL_MSG_SIM3:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
        #if(MMI_MAX_SIM_NUM >= 4)
            case SRV_MMS_QUERY_UNREAD_TOTAL_MSG_SIM4:
                msg_count_req->rsp_tb[n] = count.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num;
                break;
        #endif /* (MMI_MAX_SIM_NUM >= 4) */ 
            case SRV_MMS_QUERY_TOTAL_PHONE_MSG:
                msg_count_req->rsp_tb[n] = count.total_phone_mms;
                break;
            case SRV_MMS_QUERY_TOTAL_CARD_MSG:
                msg_count_req->rsp_tb[n] = count.total_mcard_mms;
                break;
            case SRV_MMS_QUERY_TOTAL_RECENT_EVT_MSG:
                msg_count_req->rsp_tb[n] = count.recent_event_number;
                break;
            default:
                break;
        }
    }
    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_msg
 * DESCRIPTION
 *  This API deletes a msg in sync operation
 * PARAMETERS
 *  msg_id                  [IN]        
 *  result                  [?]         
 *  mma_result_enum(?)      [OUT]       
 * RETURNS
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_delete_msg(U32 msg_id, U8 *result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_folder_enum folder_id = mma_get_box(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }
    *result = (U8) mma_mms_delete_msg(msg_id);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_MSG_SYNC_DELETE, msg_id, *result);
    if ((*result == MMA_RESULT_OK) && (folder_id != MMA_FOLDER_NONE))
    {
        srv_mms_um_refresh_ind_struct req;

        memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
        req.msg_box_type = folder_id;
        req.refresh_type = SRV_UM_REFRESH_MSG_DELETED;
        req.msg_id = msg_id;
        srv_mms_um_refresh_msg_list(&req);
    }

    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_msg
 * DESCRIPTION
 *  This API saves a msg to given box in sync operation
 * PARAMETERS
 *  msg_id                  [IN]        
 *  folder_id               [IN]        
 *  result                  [?]         
 *  mma_result_enum(?)      [OUT]       
 * RETURNS
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_save_msg(U32 msg_id, mma_folder_enum folder_id, U8 *result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }
    *result = (U8) mma_mms_move_msg_to_folder(msg_id, (U8) folder_id);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_MSG_SYNC_SAVE, msg_id, folder_id, *result);
    if (*result == MMA_RESULT_OK)
    {
        srv_mms_um_refresh_ind_struct req;

        memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
        req.msg_box_type = mma_get_box(msg_id);
        req.refresh_type = SRV_UM_REFRESH_MSG_FOLDER_CHANGED;
        req.msg_id = msg_id;
        if (folder_id != MMA_FOLDER_NONE)
        {
            srv_mms_um_refresh_msg_list(&req);
        }
    }

    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_read_status
 * DESCRIPTION
 *  This API sets a msg read status in sync operation. User of this API also
 *  need to refresh message list, if necessary, using UM primitive MSG_ID_MMI_UM_REFRESH_IND
 * PARAMETERS
 *  msg_id                  [IN]        
 *  is_read                 [IN]        
 *  result                  [?]         
 *  mma_result_enum(?)      [OUT]       
 * RETURNS
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_set_read_status(U32 msg_id, MMI_BOOL is_read, U8 *result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }
    *result = (U8) mma_mms_set_read_status(msg_id, is_read);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_MSG_SYNC_READ_STATUS, msg_id, is_read, *result);
    return SRV_MMS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_read_status_and_refresh_list
 * DESCRIPTION
 *  This API sets a msg read status in sync operation and refreshes message list
 * PARAMETERS
 *  msg_id                  [IN]        
 *  is_read                 [IN]        
 *  result                  [?]         
 *  mma_result_enum(?)      [OUT]       
 * RETURNS
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_set_read_status_and_refresh_list(U32 msg_id, MMI_BOOL is_read, U8 *result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_post_refresh_ind evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&evt, 0, sizeof(srv_mms_post_refresh_ind));
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }
    *result = (U8) mma_mms_set_read_status(msg_id, is_read);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_MSG_SYNC_READ_STATUS, msg_id, is_read, *result);

    if (MMI_FALSE == is_need_send_refresh)
    {

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_MMS_SEND_REFRESH);
        evt.folder_id = MMA_FOLDER_INBOX;
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
        is_need_send_refresh = MMI_TRUE;
    }

    return SRV_MMS_RESULT_OK;
}

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_lock_status
 * DESCRIPTION
 *  This API sets lock and corrupt status of a msg in sync operation
 * PARAMETERS
 *  msg_id                  [IN]        
 *  is_lock                 [IN]        
 *  is_corrupt              [IN]        
 *  result                  [?]         
 *  mma_result_enum(?)      [OUT]       
 * RETURNS
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_set_lock_status(U32 msg_id, U8 is_lock, U8 is_corrupt, U8 *result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }
    *result = (U8) mma_mms_set_lock_status(msg_id, is_lock, is_corrupt);

    if(g_sync_msg_info_struct->msg_id == msg_id)
    {
    memset(g_sync_msg_info_struct, 0, sizeof(g_sync_msg_info_struct));
    mma_mms_get_msg_attribute(msg_id, &(g_sync_msg_info_struct->msg_info));

    g_sync_msg_info_struct->msg_id = msg_id;
    }

    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_MSG_SYNC_LOCK_STATUS, msg_id, is_lock, is_corrupt, *result);
    return SRV_MMS_RESULT_OK;
}
#endif/*__MMI_SLIM_MMS_2__*/
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_report_msg
 * DESCRIPTION
 *  This API deletes a report mms entry in sync operation
 * PARAMETERS
 *  msg_id                  [IN]        
 *  result                  [?]         
 *  mma_result_enum(?)      [OUT]       
 * RETURNS
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_delete_report_msg(U32 msg_id, U8 *result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_is_ready())
    {
        ASSERT(0);
        return SRV_MMS_RESULT_NOT_READY;
    }
    *result = (U8) mma_mms_delete_report_msg(msg_id);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_MSG_SYNC_DELETE_REPORT, msg_id, *result);
    return SRV_MMS_RESULT_OK;
}

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__

/*****************************************************************************
 * FUNCTION
 *  srv_mms_query_unread_report_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  result(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_query_unread_report_data(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_nmgr_info_struct info = {0};
    S8 idle_buffer1[MMA_MAX_ADDR_LEN + 40];
    S8 idle_buffer2[MMA_MAX_ADDR_LEN + 40];
    S8 name[MMA_MAX_ADDR_LEN + 40];
    U8 result = 0;
    mma_msg_addr_info_struct addr;
    MMI_BOOL is_found = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(idle_buffer1, 0, MMA_MAX_ADDR_LEN + 40);
    memset(idle_buffer2, 0, MMA_MAX_ADDR_LEN + 40);

    if (srv_mms_is_ready() == MMI_TRUE)
    {
        info.total_num = (S32) mma_mms_get_unread_report_status();

        if (g_srv_new_msg_cntx->msg_type == MMA_MSG_TYPE_DELIVERY_REPORT)
        {
            mmi_ucs2cpy((S8*) idle_buffer1, (S8*) GetString(STR_ID_UMMS_NEW_DR));
        }
        else if (g_srv_new_msg_cntx->msg_type == MMA_MSG_TYPE_READ_REPORT)
        {
            mmi_ucs2cpy((S8*) idle_buffer1, (S8*) GetString(STR_ID_UMMS_NEW_RR));
        }

        if (g_srv_new_msg_cntx->from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            is_found = srv_phb_get_name_by_number(
                        g_srv_new_msg_cntx->from_address,
                        (U16*) name,
                        (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
            if (is_found == MMI_FALSE)
            {
                mmi_ucs2ncpy(
                    (S8*) idle_buffer2,
                    (S8*) g_srv_new_msg_cntx->from_address,
                    (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
            }
            else
            {
                mmi_ucs2ncpy((S8*) idle_buffer2, (S8*) name, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
            }
        }
        else
        {
            mmi_ucs2ncpy((S8*) idle_buffer2, (S8*) g_srv_new_msg_cntx->from_address, (MMA_MAX_ADDR_LEN + 40) / 2 - 1);
        }

        info.idle_text1 = idle_buffer1;
        info.idle_text2 = idle_buffer2;
    #ifndef __COSMOS_MMI_PACKAGE__
        info.image = IMG_NEW_MESSAGE_NOTIFICATION_MSG;
    #else 
        info.image = 0;
    #endif 
        mmi_nmgr_answer(
            MMI_NMGR_APP_MMS_REPORT,    /* menu data type */
            MMI_NMGR_RESULT_OK,         /* result ok */
            &info,                      /* array of unread SMS events */
            srv_mms_new_mms_handle_notification);

        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_MSG_REPORT_INFO_NMGR,
            info.total_num,
            g_srv_new_msg_cntx->tone_id_for_report,
            0 /* dummy */ ,
            g_srv_new_msg_cntx->msg_type,
            g_srv_new_msg_cntx->from_address_type,
            is_found);
    }
    else
    {
        mmi_nmgr_answer(
            MMI_NMGR_APP_MMS_REPORT,    /* menu data type */
            MMI_NMGR_RESULT_NOT_READY,  /* result ok */
            NULL,                       /* array of unread SMS events */
            NULL);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_nmgr_cancel_unread_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_nmgr_cancel_unread_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_new_msg_cntx->is_new_report = MMI_FALSE;
}
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/


#endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_app_is_sending_mms
 * DESCRIPTION
 *  This API informs currently App is sending any MMS or not
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_check_app_is_sending_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = srv_mms_bgsr_get_sending_msg_id();
    if (msg_id == 0)
    {
        return MMI_FALSE;
        /* app is not sending any MMS */
    }
    return MMI_TRUE;    /* App is sending MMS */
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_app_is_receiving_mms
 * DESCRIPTION
 *  This API informs currently App is downloading any MMS or not
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_check_app_is_receiving_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = srv_mms_bgsr_get_downloading_msg_id();
    if (msg_id == 0)
    {
        return MMI_FALSE;
        /* app is not downloading any MMS */
    }
    return MMI_TRUE;    /* App is downloading MMS */
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sim_unavailable_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_mms_sim_unavailable_hdlr(mmi_event_struct *para)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_sim_available_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_mms_sim_available_hdlr(mmi_event_struct *para)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}

#ifdef __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_dwnld_quota_from_bgsr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 *  quota       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_dwnld_quota_from_bgsr(U32 msg_id, U8 result, U8 quota)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 corrupt_data = 0;
    U8 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (quota == 0)
    {

        if (result == SRV_MMS_BGSR_RESULT_FAIL_FILE_CORRUPTED)
        {
            corrupt_data = MMI_UMMS_STOP_CORRUPT_DWNLD; /* Corrupt Notification */
        }
        else
        {
            if ((result == SRV_MMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT) ||
                (result == SRV_MMS_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT))
            {
                corrupt_data = MMI_UMMS_STOP_UNRECONIZED_NOTIFICATION;  /* Unrecognized Notification */
            }
        }
#ifndef __MMI_SLIM_MMS_2__
        srv_mms_set_lock_status(msg_id, 0, corrupt_data, &error);
#endif
    }
}

#endif /* __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt_id          [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_events(mmi_id evt_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, evt_id);
    memset(&evt, 0, sizeof(mmi_event_struct));
    evt.evt_id = evt_id;
    evt.user_data = user_data;
    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_events_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt_id          [IN]        
 *  sender_data     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_events_ex(mmi_id evt_id, void *sender_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_base_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&evt, 0, sizeof(srv_mms_base_event_struct));
    MMI_FRM_INIT_EVENT(&evt, evt_id);
    evt.sender_data = sender_data;
    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_sim1_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_sim1_context(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sim_profile_cntx->is_sim1_valid = flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_sim2_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_sim2_context(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sim_profile_cntx->is_sim2_valid = flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_sim1_profile_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_sim1_profile_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sim_profile_cntx->profile_set_for_sim1 = flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_sim2_profile_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_sim2_profile_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sim_profile_cntx->profile_set_for_sim2 = flag;
}

/***********************get functions**************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim1_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_sim1_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sim_profile_cntx->is_sim1_valid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim2_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_sim2_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sim_profile_cntx->is_sim2_valid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim1_profile_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_sim1_profile_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sim_profile_cntx->profile_set_for_sim1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim2_profile_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_sim2_profile_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sim_profile_cntx->profile_set_for_sim2;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mma_folder_to_umbox_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_um_msg_box_enum srv_mms_convert_mma_folder_to_umbox_type(mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* folder all is used for MMS can exist in folders
       please add here more folders if any more box can contain the mms messages */
    switch (folder_id)
    {
        case MMA_FOLDER_INBOX:
            return SRV_UM_MSG_BOX_INBOX;
        case MMA_FOLDER_OUTBOX:
            return SRV_UM_MSG_BOX_UNSENT;
        case MMA_FOLDER_SENT:
            return SRV_UM_MSG_BOX_SENT;
        case MMA_FOLDER_DRAFT:
            return SRV_UM_MSG_BOX_DRAFT;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            return SRV_UM_MSG_BOX_ARCHIVE;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        case MMA_FOLDER_TEMPLATE:
            return SRV_UM_MSG_BOX_PREDEF_TEMPLATES;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            return SRV_UM_MSG_BOX_USRDEF_TEMPLATES;
    #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
        case MMA_FOLDER_REPORT_BOX:
            return SRV_UM_MSG_BOX_REPORT;
    #endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
    #ifdef __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__
        case (MMA_FOLDER_INBOX | MMA_FOLDER_SENT | MMA_FOLDER_OUTBOX):

    #else /* __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__ */ 
        case (MMA_FOLDER_INBOX | MMA_FOLDER_SENT):
    #endif /* __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__ */ 
            return SRV_UM_MSG_BOX_CONVERSATION;

        case MMA_FOLDER_ALL:
		default:
            return SRV_UM_MSG_BOX_ALL;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_umbox_type_to_mma_folder
 * DESCRIPTION
 *  Convert UM Folder to MMA Folder Type
 * PARAMETERS
 *  um_box_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_mms_convert_umbox_type_to_mma_folder(srv_um_msg_box_enum um_box_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 folder_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (um_box_id)
    {
        case SRV_UM_MSG_BOX_INBOX:
            return MMA_FOLDER_INBOX;
        case SRV_UM_MSG_BOX_UNSENT:
            return MMA_FOLDER_OUTBOX;
        case SRV_UM_MSG_BOX_SENT:
            return MMA_FOLDER_SENT;
        case SRV_UM_MSG_BOX_DRAFT:
            return MMA_FOLDER_DRAFT;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_UM_MSG_BOX_ARCHIVE:
            return MMA_FOLDER_ARCHIVE;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        case SRV_UM_MSG_BOX_PREDEF_TEMPLATES:
            return MMA_FOLDER_TEMPLATE;
        case SRV_UM_MSG_BOX_USRDEF_TEMPLATES:
            return MMA_FOLDER_USRDEF_TEMPLATE;
    #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
        case SRV_UM_MSG_BOX_REPORT:
            return MMA_FOLDER_REPORT_BOX;
    #endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
        case SRV_UM_MSG_BOX_CONVERSATION:
    #ifdef __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__
            folder_id = (MMA_FOLDER_INBOX | MMA_FOLDER_SENT | MMA_FOLDER_OUTBOX);
            return folder_id;
    #else /* __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__ */ 
            folder_id = (MMA_FOLDER_INBOX | MMA_FOLDER_SENT);
            return folder_id;
    #endif /* __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__ */ 
    }
    return MMA_FOLDER_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mma_folder_to_bgsr_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folderID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_convert_mma_folder_to_bgsr_folder(mma_folder_enum folderID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_MMA_TO_BGSR_FOLDER, folderID);

    switch (folderID)
    {
        case MMA_FOLDER_INBOX:
            return SRV_MMS_BGSR_FOLDER_INBOX;
            
        case MMA_FOLDER_OUTBOX:
            return SRV_MMS_BGSR_FOLDER_OUTBOX;
            
        case MMA_FOLDER_ARCHIVE:
            return SRV_MMS_BGSR_FOLDER_ARCHIVE;
            
        default:
            return SRV_MMS_BGSR_FOLDER_NONE;
            
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_mma_addr_type_to_um_addr_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  addr_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_um_addr_enum srv_mms_convert_mma_addr_type_to_um_addr_type(U8 addr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (addr_type)
    {
        case MMA_ADDR_TYPE_PHONE_NUMBER:
            return SRV_UM_ADDR_PHONE_NUMBER;
        case MMA_ADDR_TYPE_EMAIL:
            return SRV_UM_ADDR_EMAIL_ADDRESS;
        case MMA_ADDR_TYPE_IPV4:
            return SRV_UM_ADDR_IP_ADDRESS;
        case MMA_ADDR_TYPE_NONE:
            return SRV_UM_ADDR_EMPTY;
    }
    return SRV_UM_ADDR_END;
}

static MMI_BOOL g_srv_hs_event;
static MMI_BOOL g_srv_hs_active;


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_hs_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  active      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_hs_event(MMI_BOOL active)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_hs_event = active;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_hs_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_hs_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_hs_event;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_hs_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  active      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_hs_active(MMI_BOOL active)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_hs_active = active;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_hs_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_get_hs_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_hs_active;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_translate_mma_simid_to_um_simid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_um_sim_enum srv_mms_translate_mma_simid_to_um_simid(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {

        case MMA_SIM_ID_SIM1:
            return SRV_UM_SIM_GSM_SIM1;
    #if(MMI_MAX_SIM_NUM >= 2)
        case MMA_SIM_ID_SIM2:
            return SRV_UM_SIM_GSM_SIM2;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 1)) */

    #if (MMI_MAX_SIM_NUM >= 3)
        case MMA_SIM_ID_SIM3:
            return SRV_UM_SIM_GSM_SIM3;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 2)) */

    #if (MMI_MAX_SIM_NUM >= 4)
        case MMA_SIM_ID_SIM4:
            return SRV_UM_SIM_GSM_SIM4;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 3)) */

        case MMA_SIM_ID_TOTAL:
            return SRV_UM_SIM_ALL;

        default:
            return SRV_UM_SIM_GSM_SIM1;   /* SRV_UM_SIM_GSM_SIM1 */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_setting_to_bgsr_send_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  send_setting        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_send_setting_to_bgsr_send_setting(
    /* srv_mms_send_setting_enum */ U8 send_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (send_setting)
    {
        case SRV_MMS_SETTING_SEND_ONLY:
            return SRV_MMS_BGSR_SETTING_SEND_ONLY;
            
        case SRV_MMS_SETTING_SAVE_AND_SEND:
            return SRV_MMS_BGSR_SETTING_SAVE_AND_SEND;
            
        default:
            return SRV_MMS_BGSR_SETTING_TOTAL;
            
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_current_utc_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_current_utc_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timeSecs;
    FLOAT tz;
    U32 tzdiff = 0;
    MYTIME t;
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&t);
    timeSecs = mmi_dt_mytime_2_utc_sec(&t, KAL_TRUE);
    tz = mmi_dt_get_tz();
    if (tz < 0)
    {
        time = applib_conv_tz_to_mytime(tz * (-1));
    }
    else
    {
        time = applib_conv_tz_to_mytime(tz);
    }
    tzdiff = time.nHour * 3600 + time.nMin * 60 + time.nSec;
    if (tz > 0)
    {
        return (U32) (timeSecs - tzdiff);
    }
    else
    {
        return (U32) (timeSecs + tzdiff);
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MTK_TARGET__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_TARGET__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object_info     [?]     [?]
 *  user_data       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_save_object(mma_mms_object_struct *object_info, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 len;
    MMI_BOOL bool_result = MMI_FALSE;
    U16 *object_file = NULL;    /* name of virtual file */
    U16 *file_ext;              /* file of object info file name */
    U16 *set_name = NULL;       /* if file name is large then set name by truncating */
    S8 *file_path = NULL;       /* generate the full file path */

    /* for disk info check */
    S32 fs_ret;
    FS_DiskInfo disk_info;
    WCHAR drive_path[4];
    kal_uint64 free_space = 0;
    S32 fmgr_state = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set current object drm type */
    if (user_data)
    {
        memcpy(&g_srv_mms_save_obj_hdlr, user_data, sizeof(srv_mms_save_obj_req_struct));
    }
    srv_save_object_cntx->obj_drm_type = object_info->drm_type;

    len = mmi_ucs2strlen((PS8) object_info->file_name_ucs);
    if (len > SRV_FMGR_PATH_MAX_FILE_NAME_LEN)
    {
        set_name = (U16*) srv_mms_mem_mgr_app_adm_alloc((SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
        if (NULL == set_name)
        {
            goto error;
        }
        memset(set_name, 0, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy(
            (PS8) set_name,
            (PS8) object_info->file_name_ucs,
            SRV_FMGR_PATH_MAX_FILE_NAME_LEN - (SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1));
        file_ext = (U16*) srv_fmgr_path_get_extension_ptr((WCHAR*) object_info->file_name_ucs);
        if (file_ext != NULL)
        {
            mmi_ucs2cat((S8*) set_name, (S8*) L".");
            mmi_ucs2ncat((S8*) set_name, (S8*) file_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        }
    }
    else
    {
        set_name =
            (U16*) srv_mms_mem_mgr_app_adm_alloc(ENCODING_LENGTH +
                                                  (ENCODING_LENGTH * mmi_ucs2strlen((PS8) object_info->file_name_ucs)));
        if (NULL == set_name)
        {
            goto error;
        }
        mmi_ucs2cpy((PS8) set_name, (PS8) object_info->file_name_ucs);
    }
    srv_save_object_cntx->src_file_name = set_name;
    /* file name copying done here */
    /* check disk space */
    drive_path[0] = SRV_FMGR_PUBLIC_DRV;
    drive_path[1] = ':';
    drive_path[2] = '\\';
    drive_path[3] = 0;
    fs_ret = FS_GetDiskInfo((PU16) drive_path, &disk_info, FS_DI_FREE_SPACE);
    if (fs_ret >= 0)
    {
        free_space = (kal_uint64) disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SAVE_OBJECTS_PUBLIC_DISK_INFO_ERROR);
        srv_mms_send_save_objects_error(STR_GLOBAL_ERROR, MMI_EVENT_PROPLEM);
        goto error;
    }

    if (object_info->size <= free_space)
    {
        bool_result = srv_mms_save_objects_get_file_name(&file_path, (S8*) set_name, MMI_FALSE);
    }

    else
    {
        if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
            free_space = 0;
            drive_path[0] = SRV_FMGR_CARD_DRV;
            fs_ret = FS_GetDiskInfo((PU16) drive_path, &disk_info, FS_DI_FREE_SPACE);
            if (fs_ret >= 0)
            {
                free_space =
                    (kal_uint64) disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
            }
            else
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SAVE_OBJECTS_CARD_DISK_INFO_ERROR);
                srv_mms_send_save_objects_error(STR_GLOBAL_ERROR, MMI_EVENT_PROPLEM);
                goto error;
            }
            if (object_info->size <= free_space)
            {
                bool_result = srv_mms_save_objects_get_file_name(&file_path, (S8*) set_name, MMI_TRUE);
            }
            else
            {
                srv_mms_send_save_objects_error(STR_GLOBAL_NOT_ENOUGH_MEMORY, MMI_EVENT_PROPLEM);
                goto error;
            }
        }
        else
        {
            srv_mms_send_save_objects_error(STR_GLOBAL_NOT_ENOUGH_MEMORY, MMI_EVENT_PROPLEM);
            goto error;
        }
    }
    /* file space check done here */
    if (MMI_FALSE == bool_result)
    {
        goto error;
    }

    if (object_info->is_virtual_file != 0)
    {
        FS_HANDLE file_handle;
        S32 result;
        U16 *ptr = NULL;

        /* for virtual file name object_file is used */
        object_file = (U16*) srv_mms_mem_mgr_app_adm_alloc(MMI_MV_VFN_NUM_OF_WCHAR * ENCODING_LENGTH);
        if (NULL == object_file)
        {
            srv_mms_send_save_objects_error(STR_GLOBAL_INSUFFICIENT_MEMORY, MMI_EVENT_PROPLEM);
            goto error;
        }
        file_handle = FS_Open((U16*) (object_info->file_path_ucs), FS_READ_ONLY | FS_OPEN_SHARED);
        /* MMI_ASSERT(file_handle > 0); */
        if (file_handle < 0)
        {
            srv_mms_send_events(EVT_ID_SRV_TEMPLATE_ERROR, (void*)&file_handle);
            g_srv_mms_save_obj_hdlr.fs_error = file_handle;
            srv_mms_send_events(EVT_ID_SRV_CHECK_AND_DELETE_PROGRESS, (void*)&g_srv_mms_save_obj_hdlr);
            goto error;
        }
        result = FS_GenVirtualFileName(
                    file_handle,
                    object_file,
                    (unsigned int)FS_GenVFN_SIZE,
                    object_info->offset,
                    object_info->size);
        MMI_ASSERT(result >= 0);

        ptr = (U16*) srv_fmgr_path_get_extension_ptr((WCHAR*) object_info->file_name_ucs);
        if (ptr != NULL)
        {
            mmi_ucs2cat((S8*) object_file, (S8*) L".");
            mmi_ucs2ncat((S8*) object_file, (S8*) ptr, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        }

        srv_save_object_cntx->fh = file_handle;
        srv_save_object_cntx->virtual_file_name = object_file;

    }
    else
    {
        if (NULL == object_info->file_path_ucs)
        {
            srv_mms_send_save_objects_error(STR_GLOBAL_ERROR, MMI_EVENT_PROPLEM);
            goto error;
        }
        object_file = (U16*) object_info->file_path_ucs;
        /* set the file handle in save objects fs_context */
        srv_save_object_cntx->fh = FS_NO_ERROR;
    }

    srv_save_object_cntx->media_info = object_info;
    srv_save_object_cntx->media_file_path = (U16*) file_path;
    FS_Delete((U16*) srv_save_object_cntx->media_file_path);

    fmgr_state = srv_fmgr_async_copy(
                    (WCHAR*) object_file,
                    (WCHAR*) file_path,
                    0,
                    srv_mms_save_object_file_callback_proc,
                    NULL);
#ifdef __COSMOS_MMI_PACKAGE__
	g_srv_mms_save_obj_hdlr.fs_error = fmgr_state;
#endif
    if (fmgr_state < FS_NO_ERROR)
    {
        srv_mms_send_events(EVT_ID_SRV_TEMPLATE_ERROR, (void*)&fmgr_state);
        g_srv_mms_save_obj_hdlr.fs_error = fmgr_state;
        srv_mms_send_events(EVT_ID_SRV_CHECK_AND_DELETE_PROGRESS, (void*)&g_srv_mms_save_obj_hdlr);
  
        goto error;
    }

    return;

  error:
    if (object_file != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(object_file);
        object_file = NULL;
        srv_save_object_cntx->virtual_file_name = NULL;
    }
    if (file_path != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(file_path);
        file_path = NULL;
        srv_save_object_cntx->media_file_path = NULL;
    }
    if (set_name != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(set_name);
        set_name = NULL;
        srv_save_object_cntx->src_file_name = NULL;
    }
    FS_Close(srv_save_object_cntx->fh);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_object_file_callback_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret srv_mms_save_object_file_callback_proc(mmi_event_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct *async_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg->evt_id)
    {
        case EVT_ID_SRV_FMGR_ASYNC_DONE:

            async_evt = (srv_fmgr_async_done_event_struct*) msg;
            /* ASSERT(async_evt->job_id == ctxt_a->job_id); */

            /* ctxt_a->job_id = 0; */
            srv_mms_save_object_file_callback(async_evt->result);
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_abort_file_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE :if successfully aborted
 *  FALSE :other wise
 *****************************************************************************/
MMI_BOOL srv_mms_abort_file_copy(void)
{
	return srv_fmgr_async_abort(g_srv_mms_save_obj_hdlr.fs_error, MMI_TRUE);
}
/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_virtual_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 *srv_mms_get_virtual_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_save_object_cntx->virtual_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_virtual_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  virtual_file_name       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_virtual_file_name(U16 *virtual_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_save_object_cntx->virtual_file_name = virtual_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_media_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 *srv_mms_get_media_file_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_save_object_cntx->media_file_path;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_media_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_file_path     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_media_file_path(U16 *media_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_save_object_cntx->media_file_path = media_file_path;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_src_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 *srv_mms_get_src_file_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_save_object_cntx->src_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_src_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_file_name       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_src_file_name(U16 *src_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_save_object_cntx->src_file_name = src_file_name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_drm_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_get_drm_type()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_save_object_cntx->obj_drm_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_drm_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drm_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_drm_type(U8 drm_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_save_object_cntx->obj_drm_type = drm_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_file_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
FS_HANDLE srv_mms_get_file_handle()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_save_object_cntx->fh;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_file_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_handle     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_file_handle(FS_HANDLE file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_save_object_cntx->fh = file_handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_close_object_file_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_close_object_file_handle()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_save_object_cntx->fh > FS_NO_ERROR)
    {
        FS_Close(srv_save_object_cntx->fh);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_media_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  media_info      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_media_info(U16 *media_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_save_object_cntx->media_info = (mma_mms_object_struct*) media_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_attachment_list_hilighted_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_attachment_list_hilighted_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_save_object_cntx->hilighted_attachment_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_attachment_list_hilighted_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_mms_get_attachment_list_hilighted_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_save_object_cntx->hilighted_attachment_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_save_objects_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_id        [IN]        
 *  error_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_save_objects_error(U16 error_id, U16 error_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_save_object_event_data_struct error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error.error_id = error_id;
    error.error_type = error_type;
    error.user_data = (void*)&g_srv_mms_save_obj_hdlr;
    srv_mms_send_events(EVT_ID_SRV_SAVE_OBJECTS_ERROR, (void*)&error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mode_switch_finish_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret srv_mms_mode_switch_finish_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *mode_switch = (srv_mode_switch_notify_struct*) evt;
    U8 i;
    U8 sim_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * if((mode_switch->gsm_curr_mode == SRV_MODE_FLIGHT_MODE) && (mode_switch->gsm_select_mode != SRV_MODE_FLIGHT_MODE))   
     * {
     * srv_mms_show_status_icon();
     * }
     * 
     * if((mode_switch->gsm_curr_mode != SRV_MODE_FLIGHT_MODE) && (mode_switch->gsm_select_mode == SRV_MODE_FLIGHT_MODE)) 
     * {
     * srv_mms_status_icon_type_enum result = UMMS_STATUS_OFF;
     * srv_mms_send_events(EVT_ID_SRV_SHOW_STATUS, (void *)&result);  
     * }
     */

    g_srv_mms_sim_context->sim_valid_flag = mode_switch->gsm_select_mode;
    for (i = (U8) MMI_SIM1, sim_count = 0; sim_count < MMI_SIM_TOTAL; i = i << 1, sim_count++)
    {
        if (!(srv_sim_ctrl_is_available((mmi_sim_enum) i)))
        {
            srv_mms_reset_sim_valid_flag((mmi_sim_enum) i);
        }
        if ((!(mode_switch->gsm_curr_mode & i)) && (g_srv_mms_sim_context->sim_valid_flag & i))
        {
            srv_mms_init_object_ind_sim_data(i);
        }

        if ((mode_switch->gsm_curr_mode & i) && (!(g_srv_mms_sim_context->sim_valid_flag & i)))
        {
            srv_mms_free_all_sim_related_object_handler_node(i);
        }
    }

    srv_mms_refresh_profile();

    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_TRC_UMMS_SIM_MODE_SWITCH,
        mode_switch->gsm_curr_mode,
        mode_switch->gsm_select_mode,
        g_srv_mms_sim_context->sim_valid_flag);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_sim_valid_flag
 * DESCRIPTION
 *  This function sets the bit corresponding to the SIM.
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_sim_valid_flag(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_sim_context->sim_valid_flag = g_srv_mms_sim_context->sim_valid_flag | sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_reset_sim_valid_flag
 * DESCRIPTION
 *  This function resets the bit corresponding to the SIM.
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_reset_sim_valid_flag(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_sim_context->sim_valid_flag = g_srv_mms_sim_context->sim_valid_flag & (~sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_sim_valid_flag
 * DESCRIPTION
 *  This function sets the bit corresponding to the SIM.
 * PARAMETERS
 *  void
 *  sim_id(?)       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U8 srv_mms_get_sim_valid_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_sim_context->sim_valid_flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_num_valid_sim
 * DESCRIPTION
 *  This function sets the bit corresponding to the SIM.
 * PARAMETERS
 *  void
 *  sim_id(?)       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U8 srv_mms_num_valid_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i;
    U8 num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = g_srv_mms_sim_context->sim_valid_flag; i > 0; i = i / 2)
    {
        num = num + (i % 2);
    }

    return num;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_sim_valid
 * DESCRIPTION
 *  This function sets the bit corresponding to the SIM.
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_is_sim_valid(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_sim_context->sim_valid_flag & sim_id)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_profile_flag
 * DESCRIPTION
 *  This function sets the bit corresponding to the SIM.
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_profile_flag(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_sim_context->profile_set_flag = g_srv_mms_sim_context->profile_set_flag | sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_reset_profile_flag
 * DESCRIPTION
 *  This function resets the bit corresponding to the SIM.
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_reset_profile_flag(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mms_sim_context->profile_set_flag = g_srv_mms_sim_context->profile_set_flag & (~sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_profile_flag
 * DESCRIPTION
 *  This function sets the bit corresponding to the SIM.
 * PARAMETERS
 *  void
 *  sim_id(?)       [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U8 srv_mms_get_profile_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_sim_context->profile_set_flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_profile_set
 * DESCRIPTION
 *  This function sets the bit corresponding to the SIM.
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_is_profile_set(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_sim_context->profile_set_flag & sim_id)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_refresh_profile
 * DESCRIPTION
 *  This function sets the bit corresponding to the SIM.
 * PARAMETERS
 *  void
 *  sim_id(?)       [IN]        
 * RETURNS
 *  MMI_BOOL(?)
 *****************************************************************************/
void srv_mms_refresh_profile(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    mmi_sim_enum sim_id;
    U8 mma_sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_cntx->is_srv_ready)
    {
        srv_wap_prof_profile_content_struct *profile_struct;

        for (count = 0, sim_id = MMI_SIM1; count < MMI_SIM_TOTAL; sim_id = (mmi_sim_enum) (((U8) sim_id) << 1), count++)
        {
            profile_struct = NULL;
            if (srv_mms_is_sim_valid(sim_id))
            {
                if (!srv_mms_is_profile_set(sim_id))
                {
                    profile_struct =
                        (srv_wap_prof_profile_content_struct*) srv_wap_prof_get_profile_content((srv_wap_prof_sim_id_enum) (SRV_WAP_PROF_SIMID_SIM1 + count), SRV_WAP_PROF_APPID_MMS, (U8) - 1, SRV_WAP_PROF_DTCNT_PRIMARY, srv_mms_get_active_profile_rsp_callback);

                    if (profile_struct)
                    {
                        refresh_profile_flag = MMI_TRUE;
                        mma_sim_id = srv_mms_convert_wap_sim_id_to_mma_sim_id((srv_wap_prof_sim_id_enum)
                                                                     (SRV_WAP_PROF_SIMID_SIM1 + count));
                        srv_mms_set_current_profile_req_by_data(profile_struct, mma_sim_id);
                        srv_mms_set_profile_flag(sim_id);
                        OslMfree(profile_struct);
                        profile_struct = NULL;
                    }
                }
            }
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_status
 * DESCRIPTION
 *  This function returns the status of single msg
 * PARAMETERS
 *  msg_id      [IN]        Message ID
 * RETURNS
 *  srv_mms_msg_status_enum
 * RETURN VALUES
 *  srv_mms_msg_status_enum
 *****************************************************************************/
srv_mms_msg_status_enum srv_mms_get_msg_status(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* wap_mma_get_mms_msg_icon_info_struct mms_msg_icon_info;
       mma_result_enum result = MMA_RESULT_OK;
       memset(&mms_msg_icon_info, 0, sizeof(wap_mma_get_mms_msg_icon_info_struct)); */

    switch (srv_mms_bgsr_get_msg_status(msg_id))
    {
        case SRV_MMS_BGSR_STATUS_DOWNLOADING:
            return SRV_MMS_MSG_STATUS_NOTIFICATION_DOWNLOADING;
        case SRV_MMS_BGSR_STATUS_SENDING:
            return SRV_MMS_MSG_STATUS_SENDING;
        case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND:
        case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD:
            return SRV_MMS_MSG_STATUS_WAITING;
        case SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND:
            return SRV_MMS_MSG_STATUS_PENDING;
        case SRV_MMS_BGSR_STATUS_SEND_FAIL:
            return SRV_MMS_MSG_STATUS_SENDING_FAILED;
    }

    /* result = mma_mms_get_mms_Icon_sync_info(msg_id, &mms_msg_icon_info);
       if(result != MMA_RESULT_OK)
       {
       return SRV_MMS_MSG_STATUS_NONE;
       }
       
       
       if(mms_msg_icon_info.msg_type == MMA_MSG_TYPE_MMS)
       {
       switch(mms_msg_icon_info.priority)
       {
       case MMA_PRIORITY_MEDIUM:
       return SRV_MMS_MSG_STATUS_NORMAL_PRIORITY;
       case MMA_PRIORITY_HIGH:
       return SRV_MMS_MSG_STATUS_HIGH_PRIORITY;
       case MMA_PRIORITY_LOW:
       return SRV_MMS_MSG_STATUS_LOW_PRIORITY;
       }
       }
       
       switch(mms_msg_icon_info.msg_type)
       {
       case MMA_MSG_TYPE_JAVA:
       return SRV_MMS_MSG_STATUS_JAVA;
       case MMA_MSG_TYPE_DELIVERY_REPORT:
       return SRV_MMS_MSG_STATUS_DELIVERY_REPORT;
       case MMA_MSG_TYPE_READ_REPORT:
       return SRV_MMS_MSG_STATUS_READ_REPORT;
       case MMA_MSG_TYPE_NOTIFICATION:
       return SRV_MMS_MSG_STATUS_NOTIFICATION;
       } */
    return SRV_MMS_MSG_STATUS_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_update_ui_status_icons
 * DESCRIPTION
 *  This function updates the status bar icons
 * PARAMETERS
 *  sim_id          [IN]        Mma_sim_id
 *  icon_state      [IN]        Srv_mms_icon_state_enum
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_update_ui_status_icons(U8 sim_id, srv_mms_icon_state_action_enum icon_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_show_hide_icon_struct sh_icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&sh_icon, 0, sizeof(srv_mms_show_hide_icon_struct));
    sh_icon.sim_id = sim_id;
    sh_icon.icon_state = icon_state;
    srv_mms_send_events_ex(EVT_ID_SHOW_HIDE_ICON, (void*)&sh_icon);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_lite_view_data
 * DESCRIPTION
 *  This function gets data corresponding to a message in conversation list
 * PARAMETERS
 *  msg_id      [IN]        U32
 *  data        [OUT]       Srv_mms_get_lite_view_data_struct
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_mms_get_lite_view_data(U32 msg_id, srv_mms_get_lite_view_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    wap_mma_get_mms_thumbnail_info_struct mms_msg_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&mms_msg_info, 0, sizeof(wap_mma_get_mms_thumbnail_info_struct));
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    result = mma_mms_get_mms_msg_thumbnail_info(
                msg_id,
                &mms_msg_info,
                srv_mms_mem_mgr_app_adm_alloc,
                srv_mms_mem_mgr_app_adm_free);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    if (result == MMA_RESULT_OK)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_LITE_DATA_RESULT, msg_id, result);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_LITE_DATA,
            mms_msg_info.thumbnail_info.body_size,
            mms_msg_info.thumbnail_info.body_offset,
            mms_msg_info.thumbnail_info.body_name_len,
            mms_msg_info.thumbnail_info.body_type,
            mms_msg_info.thumbnail_info.is_drm,
            mms_msg_info.msg_download_size);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_LITE_DATA_SUBJECT,
            mms_msg_info.subject[0],
            mms_msg_info.subject[1],
            mms_msg_info.subject[2],
            mms_msg_info.subject[3],
            mms_msg_info.subject[4],
            mms_msg_info.subject[5],
            mms_msg_info.subject[6],
            mms_msg_info.subject[7],
            mms_msg_info.subject[8],
            mms_msg_info.subject[9]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_LITE_DATA_SUBJECT,
            mms_msg_info.subject[10],
            mms_msg_info.subject[11],
            mms_msg_info.subject[12],
            mms_msg_info.subject[13],
            mms_msg_info.subject[14],
            mms_msg_info.subject[15],
            mms_msg_info.subject[16],
            mms_msg_info.subject[17],
            mms_msg_info.subject[18],
            mms_msg_info.subject[19]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_LITE_DATA_SUBJECT,
            mms_msg_info.subject[20],
            mms_msg_info.subject[21],
            mms_msg_info.subject[22],
            mms_msg_info.subject[23],
            mms_msg_info.subject[24],
            mms_msg_info.subject[25],
            mms_msg_info.subject[26],
            mms_msg_info.subject[27],
            mms_msg_info.subject[28],
            mms_msg_info.subject[29]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_LITE_DATA_SUBJECT,
            mms_msg_info.subject[30],
            mms_msg_info.subject[31],
            mms_msg_info.subject[32],
            mms_msg_info.subject[33],
            mms_msg_info.subject[34],
            mms_msg_info.subject[35],
            mms_msg_info.subject[36],
            mms_msg_info.subject[37],
            mms_msg_info.subject[38],
            mms_msg_info.subject[39]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_LITE_DATA_SUBJECT,
            mms_msg_info.subject[40],
            mms_msg_info.subject[31],
            mms_msg_info.subject[32],
            mms_msg_info.subject[33],
            mms_msg_info.subject[34],
            mms_msg_info.subject[35],
            mms_msg_info.subject[36],
            mms_msg_info.subject[37],
            mms_msg_info.subject[38],
            mms_msg_info.subject[39]);

        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_LITE_DATA_BODY_NAME,
            mms_msg_info.thumbnail_info.body_name[0],
            mms_msg_info.thumbnail_info.body_name[1],
            mms_msg_info.thumbnail_info.body_name[2],
            mms_msg_info.thumbnail_info.body_name[3],
            mms_msg_info.thumbnail_info.body_name[4],
            mms_msg_info.thumbnail_info.body_name[5],
            mms_msg_info.thumbnail_info.body_name[6],
            mms_msg_info.thumbnail_info.body_name[7],
            mms_msg_info.thumbnail_info.body_name[8],
            mms_msg_info.thumbnail_info.body_name[9]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_LITE_DATA_BODY_NAME,
            mms_msg_info.thumbnail_info.body_name[10],
            mms_msg_info.thumbnail_info.body_name[11],
            mms_msg_info.thumbnail_info.body_name[12],
            mms_msg_info.thumbnail_info.body_name[13],
            mms_msg_info.thumbnail_info.body_name[14],
            mms_msg_info.thumbnail_info.body_name[15],
            mms_msg_info.thumbnail_info.body_name[16],
            mms_msg_info.thumbnail_info.body_name[17],
            mms_msg_info.thumbnail_info.body_name[18],
            mms_msg_info.thumbnail_info.body_name[19]);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_TRC_UMMS_LITE_DATA_BODY_NAME,
            mms_msg_info.thumbnail_info.body_name[20],
            mms_msg_info.thumbnail_info.body_name[1],
            mms_msg_info.thumbnail_info.body_name[2],
            mms_msg_info.thumbnail_info.body_name[3],
            mms_msg_info.thumbnail_info.body_name[4],
            mms_msg_info.thumbnail_info.body_name[5],
            mms_msg_info.thumbnail_info.body_name[6],
            mms_msg_info.thumbnail_info.body_name[7],
            mms_msg_info.thumbnail_info.body_name[8],
            mms_msg_info.thumbnail_info.body_name[9]);

        data->body_size = mms_msg_info.thumbnail_info.body_size;
        data->body_offset = mms_msg_info.thumbnail_info.body_offset;
        data->body_name_len = mms_msg_info.thumbnail_info.body_name_len;
        data->body_type = mms_msg_info.thumbnail_info.body_type;
        data->is_drm = mms_msg_info.thumbnail_info.is_drm;
        data->msg_download_size = mms_msg_info.msg_download_size;
        mmi_ucs2ncpy((PS8) data->subject, (PS8) mms_msg_info.subject, MMA_MAX_SUBJECT_LEN);
        mmi_ucs2ncpy(
            (PS8) data->body_name,
            (PS8) mms_msg_info.thumbnail_info.body_name,
            MMA_MAX_MMS_BODY_FILE_NAME_LEN);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_LITE_DATA_RESULT, msg_id, result);
        return SRV_MMS_RESULT_FAIL;
    }
    return SRV_MMS_RESULT_OK;

}

#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_mms_copy_to_archive
 * DESCRIPTION
 *  This function copy MMS to Archive
 * PARAMETERS
 *  para        [IN]        Parameters passed by caller Application through struct srv_mms_copy_to_archive_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum
 *****************************************************************************/
S32 srv_mms_copy_to_archive(srv_mms_copy_to_archive_req_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_copy_to_archive_req_struct *req = (srv_mms_copy_to_archive_req_struct*) para;
    srv_mms_process_data_struct *process;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(req);
    if (!srv_mms_is_ready())
    {
        return SRV_MMS_RESULT_NOT_READY;
    }

    if ((req->msg_id == 0) || (req->call_back == NULL))
    {
        return SRV_MMS_RESULT_INVALID_PARA;
    }

    process = srv_mms_get_process_slot();
    if (NULL == process)
    {
        return SRV_MMS_RESULT_MAX_SRV_REACHED;
    }
    process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_copy_to_archive_rsp_struct));
    if (NULL == process->result)
    {
        return SRV_MMS_RESULT_INSUFFICIENT_MEMORY;
    }
    memset(process->result, 0, sizeof(srv_mms_copy_to_archive_rsp_struct));

    process->call_back = req->call_back;
    process->user_data = (void*)req->user_data;
    process->app_id = req->app_id;

    srv_mms_copy_to_archive_req(process, req);

    return SRV_MMS_RESULT_OK;

}
#endif
#if defined(OBIGO_Q03C_MMS_V02) && defined(WAP_SUPPORT)

extern mmi_frm_proc_result_enum mmi_mms_deinit(void *arg, const mmi_frm_proc_id_info_struct id_info);
extern mmi_frm_proc_result_enum mmi_wap_deinit(void *arg, const mmi_frm_proc_id_info_struct id_info);
static void mmi_mms_poweroff_rsp_hdlr(srv_mms_result_enum result, void *rsp_data, void *user_data);
static mmi_ret mmi_mms_wap_deinit_completed(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg         [?]         
 *  id_info     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_mms_deinit(void *arg, const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_power_off_req_struct msg;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_mms_deinit_cntx.id_info = id_info;
    memset(&msg, 0, sizeof(srv_mms_power_off_req_struct));
    msg.user_data = NULL;
    msg.call_back = mmi_mms_poweroff_rsp_hdlr;
    result = srv_mms_power_off((srv_mms_power_off_req_struct*) & msg);
    SetProtocolEventHandler(srv_mms_terminate_ind_hdlr, MSG_ID_WAP_MMA_TERMINATE_IND);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    if (result == SRV_MMS_RESULT_NOT_READY)
    {
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }
    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_poweroff_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mms_poweroff_rsp_hdlr(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_struct proc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_init(&proc, mmi_frm_proc_allocate_id(), mmi_wap_deinit, NULL);

    /* Launch WAP's deinit procedure */
    mmi_frm_proc_post_complete_execute(
        MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_MMS_WAP,
        mmi_mms_wap_deinit_completed,
        &g_mmi_mms_deinit_cntx,
        &proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_wap_deinit_completed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_mms_wap_deinit_completed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_notify_completed(g_mmi_mms_deinit_cntx.id_info);

    return MMI_RET_OK;
}
#endif /* defined(OBIGO_Q03C_MMS_V02) && defined(WAP_SUPPORT) */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_create_main_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cb_fn           [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_create_main_instance(delete_instance_callback cb_fn, void *user_data, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < SRV_MMS_VIEWER_MAX_CONTAINER_SIZE; count++)
    {
        if (g_srv_mms_main_instance[count].is_used == MMI_FALSE)
        {
            g_srv_mms_main_instance[count].is_used = MMI_TRUE;
            g_srv_mms_main_instance[count].index = index;
            g_srv_mms_main_instance[count].delete_cb = cb_fn;
            g_srv_mms_main_instance[count].user_data = user_data;
            g_srv_mms_main_instance[count].viewer_cntx.is_used = MMI_UMMS_TRUE;
            g_srv_mms_main_instance[count].app_cntx.is_used = MMI_UMMS_TRUE;
	    srv_mms_initialize_with_instance(index);
	    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_INSTANCE_FOUND, g_srv_mms_main_instance[count].index);
            return g_srv_mms_main_instance[count].index;
        }
    }
    for (count = 0; count < SRV_MMS_VIEWER_MAX_CONTAINER_SIZE; count++)
    {
        if (g_srv_mms_main_instance[count].delete_cb)
        {
            g_srv_mms_main_instance[count].delete_cb(user_data);
        }
	else
	{
	    ASSERT(0);
	}
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_create_main_instance_with_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_instance_context_struct *srv_mms_create_main_instance_with_index(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < SRV_MMS_VIEWER_MAX_CONTAINER_SIZE; count++)
    {
        if (g_srv_mms_main_instance[count].is_used == MMI_FALSE)
        {
            g_srv_mms_main_instance[count].is_used = MMI_TRUE;
            g_srv_mms_main_instance[count].index = index;
            g_srv_mms_main_instance[count].viewer_cntx.is_used = MMI_UMMS_TRUE;
            g_srv_mms_main_instance[count].app_cntx.is_used = MMI_UMMS_TRUE;
	    srv_mms_initialize_with_instance(index);
            return &g_srv_mms_main_instance[count];
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_instance(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_INSTANCE_TO_BE_DELETED, index);
    for (count = 0; count < SRV_MMS_VIEWER_MAX_CONTAINER_SIZE; count++)
    {
        if (g_srv_mms_main_instance[count].index == index)
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_TRC_UMMS_INSTANCE_ERASED, g_srv_mms_main_instance[count].index);
            if (g_srv_mms_main_instance[count].viewer_cntx.is_used == MMI_TRUE)
            {
                srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_MMS_VIEWER, index);
            }
            if (g_srv_mms_main_instance[count].app_cntx.is_used == MMI_TRUE)
            {
                srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_UMMS, index);
            }

            memset(&g_srv_mms_main_instance[count], 0, sizeof(srv_mms_instance_context_struct));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_instance_context_struct *srv_mms_get_instance(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < SRV_MMS_VIEWER_MAX_CONTAINER_SIZE; count++)
    {
        if (g_srv_mms_main_instance[count].index == index)
        {
            return &g_srv_mms_main_instance[count];
        }
    }
    return srv_mms_create_main_instance_with_index(index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_search_instance_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_search_instance_ext(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < SRV_MMS_VIEWER_MAX_CONTAINER_SIZE; count++)
    {
        if (g_srv_mms_main_instance[count].index == index)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_max_mms_num_on_phone
 * DESCRIPTION
 *  This function returns maximum number of MMS that can be saved on phone
 *  memory
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 * RETURN VALUES
 *  U32
 *****************************************************************************/
U32 srv_mms_get_max_mms_num_on_phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((U32) (wap_custom_get_max_mms_num() - 1));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_max_mms_num_on_card
 * DESCRIPTION
 *  This function returns maximum number of MMS that can be saved on card
 *  memory
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 * RETURN VALUES
 *  U32
 *****************************************************************************/
U32 srv_mms_get_max_mms_num_on_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((U32) wap_custom_get_max_mms_num_on_card());
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_to_address_by_index
 * DESCRIPTION
 *  This API returns To address by address index
 * PARAMETERS
 *  addr_buff       [?]         - Address buffer, already allocated MMA_MAX_ADDR_LEN*2 bytes by caller
 *  msg_id          [IN]        - Message ID
 *  addr_index      [IN]        - To Address Index.Starting from 0 to total To address count -1
 * RETURNS
 *  srv_mms_result_enum - returns SRV_RESULT_MMS_OK only if required address found
 *****************************************************************************/
S32 srv_mms_get_msg_to_address_by_index(U16 *addr_buff, U32 msg_id, U8 addr_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_msg_addr_info_struct *mms_msg_addr_info =
        (mma_msg_addr_info_struct*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_SUPPORT_ADDR_COUNT *
                                                                   sizeof(mma_msg_addr_info_struct));

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mma_result_enum result = mma_mms_get_mms_msg_addr_info(
                                msg_id,
                                mms_msg_addr_info,
                                srv_mms_mem_mgr_app_adm_alloc,
                                srv_mms_mem_mgr_app_adm_free);

    if (result != MMA_RESULT_OK)
    {
        srv_mms_mem_mgr_app_adm_free(mms_msg_addr_info);
        return SRV_MMS_RESULT_FAIL;
    }

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    while (count < MMA_MAX_SUPPORT_ADDR_COUNT)
    {
        if (mms_msg_addr_info[count].addr_group == MMA_ADDRESS_GROUP_TYPE_TO)
        {
            if (index == addr_index)
            {
                mmi_ucs2ncpy((S8*) addr_buff, (S8*) mms_msg_addr_info[count].address, (MMA_MAX_ADDR_LEN - 1));
                srv_mms_mem_mgr_app_adm_free(mms_msg_addr_info);
                return SRV_MMS_RESULT_OK;
            }
            index++;
        }
        ++count;
    }
    srv_mms_mem_mgr_app_adm_free(mms_msg_addr_info);
    return SRV_MMS_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_msg_to_address_count
 * DESCRIPTION
 *  This API returns To address count
 * PARAMETERS
 *  msg_id      [IN]        - Message ID
 * RETURNS
 *  U32 - returns required count
 *****************************************************************************/
U32 srv_mms_get_msg_to_address_count(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U8 counter = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_msg_addr_info_struct *mms_msg_addr_info =
        (mma_msg_addr_info_struct*) srv_mms_mem_mgr_app_adm_alloc(MMA_MAX_SUPPORT_ADDR_COUNT *
                                                                   sizeof(mma_msg_addr_info_struct));
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    mma_result_enum result = mma_mms_get_mms_msg_addr_info(
                                msg_id,
                                mms_msg_addr_info,
                                srv_mms_mem_mgr_app_adm_alloc,
                                srv_mms_mem_mgr_app_adm_free);

    if (result != MMA_RESULT_OK)
    {
        srv_mms_mem_mgr_app_adm_free(mms_msg_addr_info);
        return 0;
    }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
    while (counter < MMA_MAX_SUPPORT_ADDR_COUNT)
    {
        if (mms_msg_addr_info[counter].address[0] != '\0')
        {
            if (mms_msg_addr_info[counter].addr_group == MMA_ADDRESS_GROUP_TYPE_TO)
            {
                count++;
            }
            counter++;
        }
        else
        {
            break;
        }
    }
    srv_mms_mem_mgr_app_adm_free(mms_msg_addr_info);
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_forward_lock
 * DESCRIPTION
 *  This API returns if mms can be forwarded or not
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  BOOL - returns TRUE if MMS can not be forwarded else returns FALSE
 *****************************************************************************/
BOOL srv_mms_is_forward_lock(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info_ex(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sync_info->result == MMA_RESULT_OK)
    {
        return sync_info->msg_info.is_forward_lock;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_has_sending_mms
 * DESCRIPTION
 *  This API returns if currently any mms is sending or not
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL - returns TRUE if currently sending MMS else returns FALSE
 *****************************************************************************/
BOOL srv_mms_has_sending_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_mms_bgsr_get_sending_msg_id() != 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_send_failed_count
 * DESCRIPTION
 *  This API returns count of send failed MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  U32 - Total number of send failed MMS
 *****************************************************************************/
U32 srv_mms_get_send_failed_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((U32) srv_mms_bgsr_get_fail_msg_count());
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_post_refresh_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_mms_post_refresh_cb(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_post_refresh_ind *evt = (srv_mms_post_refresh_ind*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_need_send_refresh)
    {
        srv_mms_um_refresh_ind_struct req;
		memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
        req.msg_box_type = (mma_folder_enum)evt->folder_id;
		req.refresh_type = SRV_UM_REFRESH_MSG_STATUS_CHANGED;
        srv_mms_um_refresh_msg_list(&req);

        is_need_send_refresh = MMI_FALSE;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_mms_notification
 * DESCRIPTION
 *  This function tells msg type is MMS notification or not
 * PARAMETERS
 *  msg_id      [IN]        Message id
 * RETURNS
 *  TRUE :[if message is  MMS notification]
 *  FALSE: [O/W]
 *****************************************************************************/
MMI_BOOL srv_mms_is_mms_notification(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg_type = mma_get_mms_msg_type(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_has_waiting_mms
 * DESCRIPTION
 *  This function tells if any MMS is waiting for send
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE :[if any MMS is waiting for send]
 *  FALSE: [if no MMS is waiting for send]
 *****************************************************************************/
MMI_BOOL srv_mms_has_waiting_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mms_bgsr_is_any_waiting_msg();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_waiting_mms_count
 * DESCRIPTION
 *  This function returns count of MMS waiting for send
 * PARAMETERS
 *  void
 * RETURNS
 *  U32 - Count of MMS waiting for send
 *****************************************************************************/
U32 srv_mms_get_waiting_mms_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U32) srv_mms_bgsr_waiting_msg_count();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_copy_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mma_src         [?]         
 *  dst             [?]         
 *  alloc_fn        [IN]        
 *  free_fn         [IN]        
 *  state           [IN]        
 *  mode_ext        [IN]        
 *  app_mode        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_container_copy_header(
            mma_mms_description_header_struct *mma_src,
            mma_mms_description_header_struct *dst,
            srv_mms_func_mem_alloc_user_data alloc_fn,
            srv_mms_func_mem_free_user_data free_fn,
            mma_mms_state_enum state,
            U8 mode_ext,
            mma_app_mode_enum app_mode,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mode_change_status_enum mode = (srv_mms_mode_change_status_enum) mode_ext;
    mma_mms_description_header_struct *src = mma_src;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FILL THE "TO" FIELD */
    if (src->header->to)
    {
        if (app_mode != MMA_MODE_VIEW &&
            (state == MMA_MMS_STATE_REPLY ||
             state == MMA_MMS_STATE_FORWARD || mode == SRV_MMS_FORWARD_WITHOUT_EDIT_MODE))
        {
            /* Do nothing */
        }
        else
        {
            result = srv_mms_address_data_hdlr(
                        dst,
                        src->header->to,
                        MMA_MMS_ADDRESS_GROUP_TYPE_TO,
                        alloc_fn,
                        free_fn,
                        user_data);
            if (result == MMI_FALSE)
            {
                return result;
            }
        }
    }
    /* FILL THE "CC" FIELD */
    if (src->header->cc)
    {
        if (app_mode != MMA_MODE_VIEW &&
            (state == MMA_MMS_STATE_REPLY ||
             state == MMA_MMS_STATE_FORWARD || mode == SRV_MMS_FORWARD_WITHOUT_EDIT_MODE))
        {
            /* Do nothing */
        }
        else
        {
            result = srv_mms_address_data_hdlr(
                        dst,
                        src->header->cc,
                        MMA_MMS_ADDRESS_GROUP_TYPE_CC,
                        alloc_fn,
                        free_fn,
                        user_data);
            if (result == MMI_FALSE)
            {
                return result;
            }
        }
    }
    /* FILL THE "BCC" FIELD */
    if (src->header->bcc)
    {
        if (app_mode != MMA_MODE_VIEW &&
            (state == MMA_MMS_STATE_REPLY ||
             state == MMA_MMS_STATE_FORWARD || mode == SRV_MMS_FORWARD_WITHOUT_EDIT_MODE))
        {
            /* Do nothing */
        }
        else
        {
            result = srv_mms_address_data_hdlr(
                        dst,
                        src->header->bcc,
                        MMA_MMS_ADDRESS_GROUP_TYPE_BCC,
                        alloc_fn,
                        free_fn,
                        user_data);
            if (result == MMI_FALSE)
            {
                return result;
            }
        }
    }
    /* FILL THE "FROM" FIELD */
    if (src->header->from)
    {
        if ((state == MMA_MMS_STATE_REPLY || state == MMA_MMS_STATE_REPLY_ALL))
        {
            result = srv_mms_address_data_hdlr(
                        dst,
                        (src->header->from),
                        MMA_MMS_ADDRESS_GROUP_TYPE_TO,
                        alloc_fn,
                        free_fn,
                        user_data);
            if (result == MMI_FALSE)
            {
                return result;
            }
        }
    }
    /* FILL THE "SUBJECT" FIELD */
    if (src->header->subject.text)
    {
        /* set the subject in UC context here */
        U32 base64_len = strlen((S8*) src->header->subject.text);

        if (!dst->header->subject.text)
        {
            dst->header->subject.text = alloc_fn((SRV_UM_MAX_SUBJECT_LEN + 1) * 3, user_data);
            if (dst->header->subject.text == NULL)
            {
                return MMI_FALSE;
            }
            memset(dst->header->subject.text, 0, (SRV_UM_MAX_SUBJECT_LEN + 1) * 3);
        }
        if (src->header->subject.text)
        {
            memcpy((S8*) dst->header->subject.text, (S8*) src->header->subject.text, (SRV_UM_MAX_SUBJECT_LEN + 1) * 3);
        }
        dst->header->subject.charset = src->header->subject.charset;
    }
    /* FILL THE READ REPORT FIELD */
    if (app_mode != MMA_MODE_VIEW
        && (state == MMA_MMS_STATE_REPLY ||
            state == MMA_MMS_STATE_REPLY_ALL ||
            state == MMA_MMS_STATE_EDIT_EXISTED_MSG || state == MMA_MMS_STATE_SEND || state == MMA_MMS_STATE_FORWARD))
    {
        /* Use current setting value */
    }
    else
    {
        dst->header->read_reply = src->header->read_reply;
    }
    /* FILL THE DELIVERY REPORT FIELD */
    if (app_mode != MMA_MODE_VIEW
        && (state == MMA_MMS_STATE_REPLY ||
            state == MMA_MMS_STATE_REPLY_ALL ||
            state == MMA_MMS_STATE_EDIT_EXISTED_MSG || state == MMA_MMS_STATE_SEND || state == MMA_MMS_STATE_FORWARD))
    {
        /* Use current setting value */
    }
    else
    {
        dst->header->delivery_report = src->header->delivery_report;
    }
    /* FILL THE PRIORITY FIELD HERE */
    if (app_mode != MMA_MODE_VIEW
        && (state == MMA_MMS_STATE_REPLY ||
            state == MMA_MMS_STATE_REPLY_ALL ||
            (state == MMA_MMS_STATE_EDIT_EXISTED_MSG
             && mode == SRV_MMS_NORMAL_EDIT_MODE) || state == MMA_MMS_STATE_SEND))

    {
        /* Use current setting value */
    }
    else
    {
        dst->header->priority = src->header->priority;
    }
    /* FILL THE EXPIRY FIELD HERE */
    if (app_mode != MMA_MODE_VIEW
        && (state == MMA_MMS_STATE_REPLY ||
            state == MMA_MMS_STATE_REPLY_ALL ||
            state == MMA_MMS_STATE_EDIT_EXISTED_MSG || state == MMA_MMS_STATE_SEND || state == MMA_MMS_STATE_FORWARD))
    {
        /* Use current setting value */
    }
    else
    {
        dst->header->expiry_time = src->header->expiry_time;
    }
    /* FILL THE DELIVERY TIME HERE */
    if (app_mode != MMA_MODE_VIEW
        && (state == MMA_MMS_STATE_REPLY ||
            state == MMA_MMS_STATE_REPLY_ALL ||
            state == MMA_MMS_STATE_EDIT_EXISTED_MSG || state == MMA_MMS_STATE_SEND || state == MMA_MMS_STATE_FORWARD))
    {
        /* Use current setting value */
    }
    else
    {
        dst->header->delivery_time = src->header->delivery_time;
    }
    /* FILL THE VISIBILITY HERE */
    if (app_mode != MMA_MODE_VIEW
        && (state == MMA_MMS_STATE_REPLY ||
            state == MMA_MMS_STATE_REPLY_ALL ||
            state == MMA_MMS_STATE_EDIT_EXISTED_MSG || state == MMA_MMS_STATE_SEND || state == MMA_MMS_STATE_FORWARD))
    {
        /* Use current setting value */
    }
    else
    {
        dst->header->visibility = src->header->visibility;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_container_copy_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mma_mms_body        [?]         
 *  dst                 [?]         
 *  alloc_fn            [IN]        
 *  free_fn             [IN]        
 *  user_data           [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_container_copy_body(
            mma_mms_description_body_struct *mma_mms_body,
            mma_mms_description_body_struct *dst,
            srv_mms_func_mem_alloc_user_data alloc_fn,
            srv_mms_func_mem_free_user_data free_fn,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide_inserted = NULL, *slide_traverse = NULL, *slide_head;
    #ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
    mma_mms_attachment_info_struct *attachment_trv = NULL;
    U16 *id = (U16*) user_data;
    #endif
    mma_mms_description_body_struct *mms_body = mma_mms_body;
    #ifdef __MMI_MV_SUPPORT_REF_ID__
    U32 fg_color = 0;
    U32 bg_color = 0;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* BODY ELEMENT FILL */
    /* BODY BGCOLOR */
  
    dst->bgColor = (mms_body->bgColor);

	/*BODY FGCOLOR*/
	dst->fgColor = (mms_body->fgColor);

 

    /* BODY LAYOUT */
    dst->layout = mms_body->layout;

    /* IMAGE FIT */
    dst->image_fit = mms_body->image_fit;

    /* TEXT FIT */
    dst->text_fit = mms_body->text_fit;
    slide_traverse = dst->slides;
    /* SLIDE INFO IN UC CONTEXT */
    slide_head = mms_body->slides;
    while (slide_head)
    {
        U8 slide_number = 0;

        /* U32 duration = g_srv_mms_uc_settings.sliding_time.value; */
        slide_number = slide_head->slide_num;
        if (slide_number)
        {
            slide_inserted = (mma_mms_slide_struct*) alloc_fn(sizeof(mma_mms_slide_struct), user_data);
            if (slide_inserted == NULL)
            {
                return MMI_FALSE;
            }
            memset(slide_inserted, 0, sizeof(mma_mms_slide_struct));
            if (slide_traverse == NULL)
            {
                dst->slides = slide_traverse = slide_inserted;
                slide_inserted->slide_num = 1;
            }
            else
            {
                while (slide_traverse->next != NULL)
                {
                    slide_traverse = slide_traverse->next;
                }
                slide_traverse->next = slide_inserted;
                slide_inserted->prev = slide_traverse;
                slide_inserted->slide_num = slide_traverse->slide_num + 1;
                slide_traverse = slide_inserted;
            }
            dst->slide_no = slide_inserted->slide_num;
            slide_inserted->duration = slide_head->duration;
        }
        /* if text object present on the current added slide handle here */
        if (slide_head->txt.object)
        {

            slide_inserted->txt.id = slide_head->txt.id;
            slide_inserted->txt.begin = slide_head->txt.begin;
            slide_inserted->txt.end = slide_head->txt.end;
			
            slide_inserted->txt.bg_color = (slide_head->txt.bg_color) ;
            slide_inserted->txt.fg_color = (slide_head->txt.fg_color) ;
			
            slide_inserted->txt.text_style = slide_head->txt.text_style;
            slide_inserted->txt.text_size = ((slide_head->txt.text_size) - 1);
            slide_inserted->txt.object = srv_mms_copy_existing_object(dst, slide_head->txt.object, alloc_fn, free_fn, user_data);
            if (slide_inserted->txt.object == NULL)
            {
                return MMI_FALSE;
            }
            if (slide_head->txt.region_area)
            {
                slide_inserted->txt.region_area = alloc_fn(sizeof(mma_mms_object_area_struct), user_data);
                if (slide_inserted->txt.region_area == NULL)
                {
                    return MMI_FALSE;
                }
                slide_inserted->txt.region_area = memcpy(
                                                    slide_inserted->txt.region_area,
                                                    slide_head->txt.region_area,
                                                    sizeof(mma_mms_object_area_struct));
            }
            slide_inserted->txt.object->type = MMA_MMS_OBJECT_TYPE_TEXT;
        }

        /* if image object present on the current added slide handle here */
        if (slide_head->img.object)
        {
            slide_inserted->img.id = slide_head->img.id;
            slide_inserted->img.begin = slide_head->img.begin;
            slide_inserted->img.end = slide_head->img.end;
            slide_inserted->img.object = srv_mms_copy_existing_object(dst, slide_head->img.object, alloc_fn, free_fn, user_data);
            if (slide_inserted->img.object == NULL)
            {
                return MMI_FALSE;
            }
            if (slide_head->img.region_area)
            {
                slide_inserted->img.region_area = alloc_fn(sizeof(mma_mms_object_area_struct), user_data);
                if (slide_inserted->img.region_area == NULL)
                {
                    return MMI_FALSE;
                }
                slide_inserted->img.region_area = memcpy(
                                                    slide_inserted->img.region_area,
                                                    slide_head->img.region_area,
                                                    sizeof(mma_mms_object_area_struct));
            }
            slide_inserted->img.object->type = MMA_MMS_OBJECT_TYPE_IMAGE;
        }
#ifndef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
        /* if audio object present on the current added slide handle here */
        if (slide_head->aud.object)
        {
            slide_inserted->aud.id = slide_head->aud.id;
            slide_inserted->aud.begin = slide_head->aud.begin;
            slide_inserted->aud.end = slide_head->aud.end;
            slide_inserted->aud.object = srv_mms_copy_existing_object(dst, slide_head->aud.object, alloc_fn, free_fn, user_data);
            if (slide_inserted->aud.object == NULL)
            {
                return MMI_FALSE;
            }
            slide_inserted->aud.object->type = MMA_MMS_OBJECT_TYPE_AUDIO;
        }
#endif
        /* if video object present on the current added slide handle here */
        if (slide_head->vid.object)
        {
            slide_inserted->vid.id = slide_head->vid.id;
            slide_inserted->vid.begin = slide_head->vid.begin;
            slide_inserted->vid.end = slide_head->vid.end;
            slide_inserted->vid.object = srv_mms_copy_existing_object(dst, slide_head->vid.object, alloc_fn, free_fn, user_data);
            if (slide_inserted->vid.object == NULL)
            {
                return MMI_FALSE;
            }
            if (slide_head->vid.region_area)
            {
                slide_inserted->vid.region_area = alloc_fn(sizeof(mma_mms_object_area_struct), user_data);
                if (slide_inserted->vid.region_area == NULL)
                {
                    return MMI_FALSE;
                }
                slide_inserted->vid.region_area = memcpy(
                                                    slide_inserted->vid.region_area,
                                                    slide_head->vid.region_area,
                                                    sizeof(mma_mms_object_area_struct));
            }
            slide_inserted->vid.object->type = MMA_MMS_OBJECT_TYPE_VIDEO;
        }
    #ifdef __MMI_MV_SUPPORT_REF_ID__
        /* if ref object present on the current added slide handle here */
        if (slide_head->ref_items)
        {
            mma_mms_slide_ref_object_struct *ref_items = slide_head->ref_items;

            while (ref_items)
            {
                U32 ref_id = SRV_UC_INVALID_VALUE;
                U32 ref_begin = 0;
                U32 ref_end = 0;
                mma_mms_slide_ref_object_struct *new_ref_obj_info;

                if (dst->total_attach_no < SRV_MMS_UC_MAX_ATTACHMENT_NUM || (*id) == APPLIB_MEM_AP_ID_MMS_VIEWER)
                {

                    ref_id = ref_items->id;
                    ref_begin = ref_items->begin;
                    ref_end = ref_items->end;
	   	bg_color=ref_items->bg_color;
		fg_color=ref_items->fg_color;
                    MMI_ASSERT(ref_id != SRV_UC_INVALID_VALUE);
                    MMI_ASSERT(slide_inserted);
                    new_ref_obj_info = srv_mms_insert_ref_obj_info_to_tail(
                                        dst,
                                        slide_inserted,
                                        ref_id,
                                        ref_begin,
                                        ref_end,
                                        bg_color,
                                        fg_color,
                                        alloc_fn,
                                        free_fn,
                                        user_data);
                    if (new_ref_obj_info == NULL)
                    {
                        return MMI_FALSE;
                    }
                    new_ref_obj_info->object = srv_mms_copy_existing_object(dst, ref_items->object, alloc_fn, free_fn, user_data);
                    if (new_ref_obj_info->object == NULL)
                    {
                        return MMI_FALSE;
                    }
                }
                ref_items = ref_items->next;
            }

        }
    #endif /* __MMI_MV_SUPPORT_REF_ID__ */ 
        slide_head = slide_head->next;
    }
    /* Copy Attachment Here */
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
    attachment_trv = mms_body->attachment;
    while (attachment_trv != NULL)
    {
        /* if object is attachment then set the attachment context */

        /* handle here */
        if (dst->total_attach_no < SRV_MMS_UC_MAX_ATTACHMENT_NUM || (id && (*id) == APPLIB_MEM_AP_ID_MMS_VIEWER))
        {
            mma_mms_attachment_info_struct *att;

            att = srv_mms_insert_attachment(dst, alloc_fn, free_fn, user_data);
            if (att == NULL)
            {
                return MMI_FALSE;
            }
            att->object = srv_mms_copy_existing_object(dst, attachment_trv->object, alloc_fn, free_fn, user_data);
            if (att->object == NULL)
            {
                return MMI_FALSE;
            }
            att->object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
        }

        attachment_trv = attachment_trv->next;
    }
#endif
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_copy_existing_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  obj1            [?]         
 *  alloc_fn        [IN]        
 *  free_fn         [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_object_struct *srv_mms_copy_existing_object(
                        mma_mms_description_body_struct *dst,
                        mma_mms_object_struct *obj1,
                        srv_mms_func_mem_alloc_user_data alloc_fn,
                        srv_mms_func_mem_free_user_data free_fn,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __DRM_SUPPORT__
    applib_mime_type_struct *entry = NULL;
#endif 
    mma_mms_object_struct *object_inserted = NULL;
    U32 file_name_len = (app_ucs2_strlen((kal_int8*) obj1->file_name_ucs) + 1) * 2;
    U32 file_path_len = (app_ucs2_strlen((kal_int8*) obj1->file_path_ucs) + 1) * 2;
    MMI_BOOL is_duplicate = MMI_FALSE;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_inserted = srv_mms_insert_object_to_list_tail(dst, &is_duplicate, obj1->id, alloc_fn, free_fn, user_data);
    if (object_inserted == NULL)
    {
        return NULL;
    }
    if (is_duplicate == MMI_FALSE)
    {
        object_inserted->id = obj1->id;
        object_inserted->type = obj1->type;
        object_inserted->is_virtual_file = obj1->is_virtual_file;
        object_inserted->drm_type = obj1->drm_type;
        object_inserted->size = obj1->size;
        object_inserted->offset = obj1->offset;
        object_inserted->encoding = obj1->encoding;
        object_inserted->is_attachment = obj1->is_attachment;
        object_inserted->is_drm_processed = obj1->is_drm_processed;
        mmi_ucs2ncpy((PS8) object_inserted->drm_ext, (PS8) obj1->drm_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        /* OBJECT FILE NAME */
        object_inserted->file_name_ucs = alloc_fn(file_name_len, user_data);
        if (object_inserted->file_name_ucs == NULL)
        {
            return NULL;
        }
        memset(object_inserted->file_name_ucs, 0, file_name_len);
        memcpy(object_inserted->file_name_ucs, obj1->file_name_ucs, file_name_len);
        object_inserted->charset = obj1->charset;
    #ifdef __DRM_SUPPORT__
        if ((entry = applib_mime_type_look_up((kal_char*) obj1->mime_str, NULL, 0, 0)) != NULL)
        {
            object_inserted->mime_type = entry->mime_type;
        }
        else
        {
            object_inserted->mime_type = MIME_TYPE_UNKNOWN;
        }
    #endif /* __DRM_SUPPORT__ */ 

        /* OBJECT FILE PATH */
        object_inserted->file_path_ucs = alloc_fn(file_path_len, user_data);
        if (object_inserted->file_path_ucs == NULL)
        {
            return NULL;
        }
        memset(object_inserted->file_path_ucs, 0, file_path_len);
        memcpy(object_inserted->file_path_ucs, obj1->file_path_ucs, file_path_len);
    }
    return object_inserted;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_insert_object_to_list_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst                 [?]         
 *  is_duplicate        [?]         
 *  id                  [IN]        
 *  alloc_fn            [IN]        
 *  free_fn             [IN]        
 *  user_data           [?]         
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_object_struct *srv_mms_insert_object_to_list_tail(
                        mma_mms_description_body_struct *dst,
                        MMI_BOOL *is_duplicate,
                        U32 id,
                        srv_mms_func_mem_alloc_user_data alloc_fn,
                        srv_mms_func_mem_free_user_data free_fn,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *new_object;
    U32 object_size;
    U32 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_size = sizeof(mma_mms_object_struct);
    new_object = alloc_fn(object_size, user_data);
    if (new_object == NULL)
    {
        return NULL;
    }
    memset(new_object, 0, object_size);

    /* First object */
    if (dst->objects == NULL)
    {
        dst->objects = new_object;
        new_object->next = NULL;
        new_object->prev = NULL;
    }
    else
    {
        mma_mms_object_struct *cur_object = dst->objects;
        mma_mms_object_struct *temp = NULL;

        while (cur_object)
        {
            i++;
            if (cur_object->id == id)
            {
                free_fn(new_object, user_data);
                new_object = NULL;
                *is_duplicate = MMI_TRUE;
                return cur_object;
            }
            if (cur_object->next == NULL)
                temp = cur_object;

            cur_object = cur_object->next;
        }

        temp->next = new_object;
        new_object->next = NULL;
        new_object->prev = temp;
    }

    dst->obj_no++;
    return new_object;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_insert_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  alloc_fn        [IN]        
 *  free_fn         [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_attachment_info_struct *srv_mms_insert_attachment(
                                    mma_mms_description_body_struct *dst,
                                    srv_mms_func_mem_alloc_user_data alloc_fn,
                                    srv_mms_func_mem_free_user_data free_fn,
                                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
    mma_mms_attachment_info_struct *new_attach;
    U32 attach_size;
    U32 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attach_size = sizeof(mma_mms_attachment_info_struct);
    new_attach = alloc_fn(attach_size, user_data);
    if (new_attach == NULL)
    {
        return NULL;
    }
    memset(new_attach, 0, attach_size);

    if (dst->total_attach_no == 0 || dst->attachment == NULL)
    {
        MMI_ASSERT(dst->attachment == NULL);
        dst->attachment = new_attach;

        new_attach->next = NULL;
        new_attach->prev = NULL;
    }
    else
    {
        mma_mms_attachment_info_struct *cur_attach = dst->attachment;

        MMI_ASSERT(cur_attach);

        for (; cur_attach->next != NULL; cur_attach = cur_attach->next)
        {
            i++;
        }
        cur_attach->next = new_attach;
        new_attach->next = NULL;
        new_attach->prev = cur_attach;
    }

    dst->total_attach_no++;

    return new_attach;
#else

	return NULL;
#endif
}

#ifdef __MMI_MV_SUPPORT_REF_ID__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_insert_ref_obj_info_to_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  slide           [?]         
 *  id              [IN]        
 *  begin           [IN]        
 *  end             [IN]        
 *  bg_color        [IN]        
 *  fg_color        [IN]        
 *  alloc_fn        [IN]        
 *  free_fn         [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_slide_ref_object_struct *srv_mms_insert_ref_obj_info_to_tail(
                                    mma_mms_description_body_struct *dst,
                                    mma_mms_slide_struct *slide,
                                    U32 id,
                                    U32 begin,
                                    U32 end,
                                    U32 bg_color,
                                    U32 fg_color,
                                    srv_mms_func_mem_alloc_user_data alloc_fn,
                                    srv_mms_func_mem_free_user_data free_fn,
                                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_ref_object_struct *new_ref_obj_info;
    U32 ref_obj_info_size;
    U16 *id1 = (U16*) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. new a ref obj info node */
    ref_obj_info_size = sizeof(mma_mms_slide_ref_object_struct);

    new_ref_obj_info = alloc_fn(ref_obj_info_size, user_data);
    if (new_ref_obj_info == NULL)
    {
        return NULL;
    }

    memset(new_ref_obj_info, 0, ref_obj_info_size);
    new_ref_obj_info->id = id;
    new_ref_obj_info->begin = begin;
    new_ref_obj_info->end = end;
    new_ref_obj_info->bg_color = bg_color;
    new_ref_obj_info->fg_color = fg_color;

    /* insert the new ref node to ref_list in this slide */
    if (NULL == slide->ref_items)
    {
        slide->ref_items = new_ref_obj_info;
    }
    else
    {
        mma_mms_slide_ref_object_struct *cur_ref;

        cur_ref = slide->ref_items;

        while (cur_ref->next)
        {
            cur_ref = cur_ref->next;
        }
        cur_ref->next = new_ref_obj_info;
        new_ref_obj_info->next = NULL;
        new_ref_obj_info->prev = cur_ref;
    }

    dst->total_attach_no++;
    if ((*id1) != APPLIB_MEM_AP_ID_MMS_VIEWER)
        MMI_ASSERT(dst->total_attach_no <= SRV_MMS_UC_MAX_ATTACHMENT_NUM);

    return new_ref_obj_info;
}

#endif /* __MMI_MV_SUPPORT_REF_ID__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_address_data_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst                 [?]         
 *  addr                [?]         
 *  addr_group_type     [IN]        
 *  alloc_fn            [IN]        
 *  free_fn             [IN]        
 *  user_data           [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_address_data_hdlr(
            mma_mms_description_header_struct *dst,
            mma_mms_addr_list_struct *addr,
            mma_mms_address_group_type_enum addr_group_type,
            srv_mms_func_mem_alloc_user_data alloc_fn,
            srv_mms_func_mem_free_user_data free_fn,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ucs2;
    U32 ucs2_len;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (addr != NULL)
    {
        if (addr->addr_type == MMA_ADDR_TYPE_IPV4)
        {
            /* Skip do nothing. */
            addr = addr->next;
            continue;
        }

        if (dst->header->to_num >= SRV_MMS_UC_MAX_ADDRESS_NUM)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_XML_DATA_ADDR_HDLR_ADDR_NO_EXCEED);
            break;
        }

        ucs2_len = (strlen(addr->address) + 1) * ENCODING_LENGTH;
        ucs2 = alloc_fn(ucs2_len, user_data);
        if (ucs2 == NULL)
        {
            return MMI_FALSE;
        }
        memset(ucs2, 0, ucs2_len);

        mmi_chset_utf8_to_ucs2_string(ucs2, ucs2_len, (kal_uint8*)addr->address);
        // #ifdef __MMI_SLIM_MMS_2__
        if (addr->group == MMA_MMS_ADDRESS_GROUP_TYPE_FROM)
            addr_group_type = MMA_MMS_ADDRESS_GROUP_TYPE_TO;
        else
            addr_group_type = (mma_mms_address_group_type_enum)addr->group;
        // #endif
        if (addr->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER || addr->addr_type == MMA_ADDR_TYPE_EMAIL)
        {
            result = srv_mms_add_address_ext(dst, ucs2, (mma_addr_type_enum)addr->addr_type, addr_group_type, alloc_fn, free_fn, user_data);
            if (result == MMI_FALSE)
            {
                free_fn(ucs2, user_data);
                return result;
            }
        }
        else
        {
            MMI_ASSERT(0);
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_XML_DATA_ADDR_HDLR_ADDR_TYPE_ERR);
        }
        free_fn(ucs2, user_data);
        addr = addr->next;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_add_address_ext
 * DESCRIPTION
 *  add address function
 * PARAMETERS
 *  dst             [?]         
 *  ucs2_addr       [?]         [?]
 *  type            [IN]        
 *  group           [IN]        
 *  alloc_fn        [IN]        
 *  free_fn         [IN]        
 *  user_data       [?]         
 *  instance(?)     [IN]        
 * RETURNS
 *  TRUE means add successfully. Otherwise FALSE.
 *****************************************************************************/
MMI_BOOL srv_mms_add_address_ext(
            mma_mms_description_header_struct *dst,
            U8 *ucs2_addr,
            mma_addr_type_enum type,
            mma_mms_address_group_type_enum group,
            srv_mms_func_mem_alloc_user_data alloc_fn,
            srv_mms_func_mem_free_user_data free_fn,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_addr_list_struct **addr_head = NULL;
    mma_mms_addr_list_struct *addr_tail = NULL;
    mma_mms_addr_list_struct *addr_new = NULL;
    U8 ascii_addr[SRV_MMS_UC_MAX_EMAIL_LEN + 1];
    U8 addr_num_calculated = 0;
    U8 *addr_num = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (group)
    {
        case MMA_MMS_ADDRESS_GROUP_TYPE_TO:
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        case MMA_MMS_ADDRESS_GROUP_TYPE_CC:
        case MMA_MMS_ADDRESS_GROUP_TYPE_BCC:
    #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
        {
            addr_tail = dst->header->to;
            addr_head = &(dst->header->to);
            addr_num = &(dst->header->to_num);
        }
            break;
    #ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
        case MMA_MMS_ADDRESS_GROUP_TYPE_CC:
        {
            addr_tail = dst->header->cc;
            addr_head = &(dst->header->cc);
            addr_num = &(dst->header->cc_num);
        }
            break;
        case MMA_MMS_ADDRESS_GROUP_TYPE_BCC:
        {
            addr_tail = dst->header->bcc;
            addr_head = &(dst->header->bcc);
            addr_num = &(dst->header->bcc_num);
        }
            break;
    #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
        case MMA_MMS_ADDRESS_GROUP_TYPE_FROM:
        {
            addr_tail = dst->header->from;
            addr_head = &(dst->header->from);
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }

    if (type == MMA_ADDR_TYPE_PHONE_NUMBER
		|| type == MMA_ADDR_TYPE_EMAIL)
    {
        memset(ascii_addr, 0, sizeof(ascii_addr));
        if(type == MMA_ADDR_TYPE_PHONE_NUMBER)
		{
        mmi_ucs2_n_to_asc((S8*) ascii_addr, (S8*) ucs2_addr, SRV_MMS_UC_MAX_PHONE_NUMBER_LEN * ENCODING_LENGTH);
    }
		else 
		{
			mmi_ucs2_n_to_asc((S8*) ascii_addr, (S8*) ucs2_addr, SRV_MMS_UC_MAX_EMAIL_LEN * ENCODING_LENGTH);
		}
    }

    if (group != MMA_MMS_ADDRESS_GROUP_TYPE_FROM)
    {
        if (addr_tail == NULL)
        {
            addr_num_calculated = 0;
        }
        else
        {
            addr_num_calculated = 1;

            for (; addr_tail->next != NULL; addr_tail = addr_tail->next)
            {
                addr_num_calculated++;
            }
        }

        MMI_ASSERT((addr_num_calculated == (*addr_num)));
    }

    addr_new = alloc_fn(sizeof(mma_mms_addr_list_struct), user_data);

    if (addr_new == NULL)
    {
        return MMI_FALSE;
    }
    addr_new->addr_type = type;
    addr_new->group = group;
    addr_new->next = NULL;
	/*Address copy*/
    {
        U16 len = strlen((char*)ascii_addr);
		if (addr_new->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
    	{
        if (len > SRV_MMS_UC_MAX_PHONE_NUMBER_LEN)
        {
            /* this path will not be run if previous mmi_ucs2_n_to_asc((S8*) ascii_addr, (S8*) ucs2_addr, SRV_MMS_UC_MAX_PHONE_NUMBER_LEN * ENCODING_LENGTH); */
            free_fn(addr_new, user_data);
            return MMI_FALSE;
        }
    }
    else if (addr_new->addr_type == MMA_ADDR_TYPE_EMAIL)
    {
        if (len > SRV_MMS_UC_MAX_EMAIL_LEN)
        {
            free_fn(addr_new, user_data);
            return MMI_FALSE;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
        addr_new->address = alloc_fn(len + 1, user_data);
        if (addr_new->address == NULL)
        {
            free_fn(addr_new, user_data);
            return MMI_FALSE;
        }

        memset(addr_new->address, 0, len + 1);
        memcpy(addr_new->address, ascii_addr, len + 1);
    }
	/*Need to update this function*/
    /* First entry */
    if (addr_tail == NULL)
    {
        addr_new->prev = NULL;

        *addr_head = addr_new;
    }
    else
    {
        addr_new->prev = addr_tail;
        addr_tail->next = addr_new;
    }

    if (group != MMA_MMS_ADDRESS_GROUP_TYPE_FROM)
    {
        (*addr_num) = (*addr_num) + 1;
    }
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_viewer_asm_alloc_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size            [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_mms_mem_mgr_viewer_asm_alloc_ext(U32 size, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *id = (U16*) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*id == APPLIB_MEM_AP_ID_MMS_VIEWER)
    {
        return srv_mms_mem_mgr_viewer_asm_alloc(size);
    }
    else if (*id == APPLIB_MEM_AP_ID_UMMS)
    {
        return srv_mms_mem_mgr_app_asm_alloc(size);
    }

	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_viewer_asm_free_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  memory          [?]     
 *  user_data       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_viewer_asm_free_ext(void *memory, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *id = (U16*) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*id == APPLIB_MEM_AP_ID_MMS_VIEWER)
    {
        srv_mms_mem_mgr_viewer_asm_free(memory);
    }
    else if (*id == APPLIB_MEM_AP_ID_UMMS)
    {
        srv_mms_mem_mgr_app_asm_free(memory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_convert_file_name_to_ascii
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj             [?]         
 *  alloc_fn        [IN]        
 *  free_func       [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_convert_file_name_to_ascii(
            mma_mms_object_struct *obj,
            srv_mms_func_mem_alloc_user_data alloc_fn,
            srv_mms_func_mem_free_user_data free_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_is_ascii_string(obj->file_name) == KAL_FALSE)
    {
        temp = obj->file_name;
        obj->file_name = srv_mms_create_name_from_nonascii_name(obj->file_name, obj->id, alloc_fn, free_func, user_data);
        if (obj->file_name != NULL)
        {
            free_func(temp, user_data);
        }
        else
        {
            obj->file_name = temp;
        }
    }

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_create_name_from_nonascii_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name            [IN]        
 *  counter         [IN]        
 *  alloc_fn        [IN]        
 *  free_func       [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
char *srv_mms_create_name_from_nonascii_name(
        const char *name,
        U32 counter,
        srv_mms_func_mem_alloc_user_data alloc_fn,
        srv_mms_func_mem_free_user_data free_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *ext = NULL;
    char *new_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL)
    {
        return NULL;
    }
    ext = strrchr(name, '.');
    if (ext)
    {

        new_name = (char*)alloc_fn(srv_mms_get_value_digit_number(counter) + strlen(ext) + 2, user_data);

        sprintf(new_name, "%d%s", counter, ext);
    }
    else
    {
        new_name = (char*)alloc_fn(srv_mms_get_value_digit_number(counter) + 1, user_data);

        sprintf(new_name, "%d", counter);

    }
    return new_name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_value_digit_number
 * DESCRIPTION
 *  Get positive value digit number
 * PARAMETERS
 *  n       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_value_digit_number(U32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 digit = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n > 0)
    {
        n = n / 10;
        digit++;
    }

    return digit;
}

static MMI_BOOL g_mms_in_use = MMI_FALSE;

/*****************************************************************************
 * FUNCTION
 *  srv_mms_post_refresh_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void srv_mms_set_is_mms_in_use_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mms_in_use =(MMI_BOOL) (g_mms_in_use || flag);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_post_refresh_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
MMI_BOOL srv_mms_if_is_mms_in_open_state(const U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mms_in_use = MMI_FALSE;
    srv_mms_send_events_ex(EVT_ID_SRV_MMS_IN_USE_MSG_ID, (void*)&msg_id);
    return g_mms_in_use;
}

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
srv_mms_card_usage_enum srv_mms_check_memory_usage(U32 download_size)
{

	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U64 card_size_available = 0;
    U8 prefer_storage = 0;
    U64 phone_size_available = mma_get_mms_avaliable_file_space(NULL, MMA_MSG_STORAGE_PHONE);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	prefer_storage = srv_mms_get_mms_prefer_storage();  /* mmi_umms_app_dtmgr_get_prefered_storage(); */
	if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
    {
        card_size_available = mma_get_mms_avaliable_file_space(NULL, MMA_MSG_STORAGE_CARD1);
    }
    else
    {
        /* ask card not present use phone if 
           card is not inserted + prefer storage is card and phone have enough memory to download */
        card_size_available = 0;
        if ((prefer_storage == MMA_MSG_STORAGE_CARD1) && (phone_size_available > download_size))
        {
           return SRV_MMS_CARD_NOT_PRESENT_USE_PHONE;
        }
    }
    /* calculated size available in memory card */
    if ((prefer_storage == MMA_MSG_STORAGE_PHONE)
        && ((phone_size_available < download_size)
            && (card_size_available >= download_size)))
    {
        return SRV_MMS_CARD_PHONE_FULL_USE_CARD_MEM;
    }

    if ((prefer_storage == MMA_MSG_STORAGE_CARD1)
        && ((card_size_available < download_size)
            && (phone_size_available >= download_size)))
    {
        return SRV_MMS_CARD_FULL_USE_PHONE_MEM;
    }

    if (((prefer_storage == MMA_MSG_STORAGE_PHONE) || (prefer_storage == MMA_MSG_STORAGE_CARD1))
        && ((phone_size_available < download_size)
            && (card_size_available < download_size)))
    {
        return SRV_MMS_CARD_NOT_ENOUGH_MEMORY;
    }
    return SRV_MMS_CARD_MEMORY_OK;
}
#endif /*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_lite_viewer_data
 * DESCRIPTION
 *  This function is to get lite viewer data in async
 * PARAMETERS
 *  para:     [IN] Parameters passed by caller Application through struct srv_mms_get_lite_viewer_data_req_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum 
 *****************************************************************************/
S32 srv_mms_get_lite_viewer_data(srv_mms_get_lite_viewer_data_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     srv_mms_process_data_struct *process;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     ASSERT(req);
     if(!srv_mms_is_ready())
     {
         return SRV_MMS_RESULT_NOT_READY;
     }

     if(SRV_MMS_MAX_LITE_REQ == lite_req_counter)
     {
         return SRV_MMS_RESULT_MAX_SRV_REACHED;
     }

     if((req->msg_id == 0) || (req->call_back == NULL))
     {
          return SRV_MMS_RESULT_INVALID_PARA;
     }

     process = srv_mms_get_process_slot();
     if(NULL == process)
     {
         return SRV_MMS_RESULT_MAX_SRV_REACHED;
     }
     process->result = srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_get_lite_viewer_data_rsp_struct));
     if(NULL == process->result)
     {
         MMI_ASSERT(0);
     }
     memset(process->result, 0, sizeof(srv_mms_get_lite_viewer_data_rsp_struct));

     process->call_back = req->call_back;
     process->user_data = req->user_data;
     process->app_id = req->app_id;

     srv_mms_get_lite_viewer_data_req(process, req);

     return SRV_MMS_RESULT_OK;

}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_text_buffer
 * DESCRIPTION
 *  This function is to get lite viewer text in sync
 * PARAMETERS
 *  srv_mms_get_lite_viewer_text_req_struct:     [IN] used by api to extract text path and content
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum 
 *****************************************************************************/
S32 srv_mms_get_text_buffer(srv_mms_get_lite_viewer_text_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U8 *src_buffer;
	 U16 msg_file_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	 U16 msg_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	 U16 txt_vf[FS_GenVFN_SIZE];
	 U32 len = 0;
	 S32 parent_file_handle = 0;
	 S32 file_handle = 0;
	 S32 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 MMI_ASSERT(req);
	 MMI_ASSERT(req->mem);
	 MMI_ASSERT(req->txt_size);
	 MMI_ASSERT(req->txt_data);
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) L"root"))
        {
            return SRV_MMS_RESULT_FILE_OPERATION_FAILED;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
	 if(req->txt_data->body_size == 0)
	 {
		 //should copy no text case
		 return SRV_MMS_RESULT_INVALID_PARA;
	 }
	 if((MMA_MSG_TYPE_MMS  == req->msg_type) || (MMA_MSG_TYPE_JAVA == req->msg_type))
	{
		memset(msg_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
        memset(msg_file_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);            
        mma_get_home_directory(
                      (kal_wchar*) msg_path,
                      MMA_MAX_INTERNAL_FILENAME_LENGTH,
                      req->storage_type);
		mma_get_msg_file_name(req->msg_id, (kal_wchar*) msg_file_path, MMA_MAX_INTERNAL_FILENAME_LENGTH);
		mmi_ucs2cat((CHAR*) msg_path, (CHAR*) "\\");
       mmi_ucs2cat((CHAR*) msg_path, (CHAR*) msg_file_path);
    }
	 else
	 {
		 //here should can assign text for not mms case
		 //should copy no text case
		 return SRV_MMS_RESULT_INVALID_PARA;
	 }
	/* Open Parent File Handle */
    parent_file_handle = FS_Open((WCHAR*) msg_path, FS_READ_ONLY | FS_OPEN_SHARED);
    if (parent_file_handle <= 0)
    {
       return SRV_MMS_RESULT_FILE_OPERATION_FAILED;
    }
	result = FS_GenVirtualFileName(
                    parent_file_handle,
                    (U16*) txt_vf,
                    (unsigned int)FS_GenVFN_SIZE,
                    req->txt_data->body_offset,
                    req->txt_size);

    if (result < 0)
    {
        FS_Close(parent_file_handle);
        return SRV_MMS_RESULT_FILE_OPERATION_FAILED;
	}
    memset(req->mem, 0, (req->txt_size + 1) * ENCODING_LENGTH);
	src_buffer = (U8 *)(req->alloc_fn)(req->txt_size + 1, req->user_data);
    memset(src_buffer, 0, req->txt_size + 1);
	/* Read Src Txt into src buffer */
    //*********************************************************
    //*******************************************************
    file_handle = FS_Open(txt_vf, FS_READ_ONLY | FS_OPEN_SHARED);
    if (file_handle <= 0)
    {
        FS_Close(parent_file_handle);
		req->free_fn(src_buffer);
        return SRV_MMS_RESULT_FILE_OPERATION_FAILED;
    }
    result = FS_Read(file_handle, src_buffer, req->txt_size, &len);
    FS_Close(file_handle);
	if (result == FS_NO_ERROR)
	{
		srv_mms_viewer_change_encoding(src_buffer, (req->txt_size) * ENCODING_LENGTH, (PU8)req->mem, req->txt_data->txt_encoding_scheme);
	}
	if (parent_file_handle != 0)
    {
        FS_Close(parent_file_handle);
    }
	if (result >= 0)
    {
		req->free_fn(src_buffer);       
		return SRV_MMS_RESULT_OK;
    }
	req->free_fn(src_buffer);   
    return SRV_MMS_RESULT_FAIL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_image_buffer
 * DESCRIPTION
 *  This function is to get lite viewer image vfname  in sync
 * PARAMETERS
 *  srv_mms_get_lite_viewer_image_req_struct:     [IN] used by api to extract image  path 
 * RETURNS
 *  S32
 * RETURN VALUES
 *  srv_mms_result_enum 
 *****************************************************************************/

S32 srv_mms_get_image_buffer(srv_mms_get_lite_viewer_image_req_struct *req)
{

 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 U16 msg_file_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	 U16 msg_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	 S32 file_handle = 0;
	 S32 result = 0;
	 PS8 temp_str ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 MMI_ASSERT(req);
	 MMI_ASSERT(req->mem);
	 MMI_ASSERT(req->file_table);

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*) L"root"))
        {
            return SRV_MMS_LITE_VIEWER_OPERATION_FAILED_ERROR;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
	 if(req->image_data->body_size == 0)
	 {
		MMI_ASSERT(0);	
	 }
	 if(req->image_data->body_type == MMA_MEDIA_MSG_VIDEO)
 	 {
          return SRV_MMS_LITE_VIEWER_VIDEO_TYPE ;
	 }
	 if(req->image_data->is_drm != 0)
	 {
         return SRV_MMS_LITE_VIEWER_DRM_TYPE ;
	 }
	 if((MMA_MSG_TYPE_MMS  == req->msg_type) || (MMA_MSG_TYPE_JAVA == req->msg_type))
	{
		memset(msg_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);
        memset(msg_file_path, 0, (MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH);            
        mma_get_home_directory(
                      (kal_wchar*) msg_path,
                      MMA_MAX_INTERNAL_FILENAME_LENGTH,
                      req->storage_type);
		mma_get_msg_file_name(req->msg_id, (kal_wchar*) msg_file_path, MMA_MAX_INTERNAL_FILENAME_LENGTH);
		mmi_ucs2cat((CHAR*) msg_path, (CHAR*) "\\");
       mmi_ucs2cat((CHAR*) msg_path, (CHAR*) msg_file_path);
    }
	 
    file_handle = FS_Open((U16*) msg_path, FS_READ_ONLY | FS_OPEN_SHARED);
	if (file_handle <= 0)
    {
       return SRV_MMS_LITE_VIEWER_OPERATION_FAILED_ERROR;
    }
	
	result = FS_GenVirtualFileName(
                    file_handle,
                    (U16*) req->mem,
                    (unsigned int)FS_GenVFN_SIZE,
                    req->image_data->body_offset,
                    req->image_data->body_size);

    if (result < 0)
    {
        FS_Close(file_handle);
		 MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_VF_FILE_ERROR);
        return SRV_MMS_LITE_VIEWER_OPERATION_FAILED_ERROR; 
	}
	  mmi_ucs2cat((PS8) req->mem, (PS8) ".");
	  temp_str = (S8*) srv_fmgr_path_get_extension_ptr((WCHAR*)req->image_data->body_name);
      ASSERT(temp_str);
      mmi_ucs2ncat((PS8) req->mem, temp_str, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
	  req->file_table->msg_id = req->msg_id;
	  req->file_table->file_handle =  file_handle ;
         
	return SRV_MMS_LITE_VIEWER_RESULT_OK ;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_lite_view_content_req_reached_max
 * DESCRIPTION
 *  This function is to get lite viewer content reached max
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE: if count reached max
 *  MMI_FALSE : o/w
 *****************************************************************************/
MMI_BOOL srv_mms_is_lite_view_content_req_reached_max(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     return (SRV_MMS_MAX_LITE_REQ == lite_req_counter) ? MMI_TRUE : MMI_FALSE; 
}



#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#endif /* __MMI_MMS_2__ */ 

