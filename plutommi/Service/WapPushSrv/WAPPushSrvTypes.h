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
 * WAPPushSrvTypes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file have the declaration of internally used function.
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#ifndef __PUSH_MSG_SRV_TYPE__
#define __PUSH_MSG_SRV_TYPE__
//#include "MMI_include.h"
#include "wap_adp.h"
//#include "WapProfileGprot.h"
#include "pmg_struct.h"
    #include "custom_phb_config.h"
    #include "MMI_features.h"
    #include "nvram_common_defs.h"
    #include "gui_typedef.h"
    #include "MMIDataType.h"
 //    #if defined(__VODAFONE_R12_LIVE__)
  //  #include "op_custom_wap_config.h"
   //  #endif /* defined(__VODAFONE_R12_LIVE__) */
    #include "common_nvram_editor_data_item.h"
    #include "kal_general_types.h"
    #include "WAPProfileSrvType.h"
 	#include "WAPPushSrvGprots.h"
#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif /*__DM_LAWMO_SUPPORT__*/
#ifdef WAP_SUPPORT

#ifdef __MMI_PUSH_IN_UM__
#include "UmSrvStruct.h"
#endif

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__

#include "CcaSrvGProt.h"

#endif /*__MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__*/
/****************************************  Start of constant defination  ****************************************/

#define SRV_WAP_PUSH_MAX_PHN_LENGTH                 32
#define SRV_WAP_PUSH_IP_PART_MAX_VALUE              255
#define SRV_WAP_PUSH_MAX_PART_IP_ADDRESS            4
#define SI_DATE_N_TIME_STRING_LENGTH                62
#define SRV_WAP_PUSH_MAX_LEN_TIME_STR               (15 + 1 + 10 + 1) /* Date string + 1 space + Time string + NULL terminator*/

#define MAX_NOTIFICATION_INFO_LEN					25

#define SRV_INET_TRC_G4_PUSH                        TRACE_GROUP_4
#define SRV_WAP_PUSH_TRACE_MOD_INET_APP             MOD_MMI_INET_APP

#define MAX_PUSH_PHN_NUM_LEN                        (MMI_PHB_NUMBER_LENGTH + 3)
#define MAX_PUSH_IP_ADDR_NUM_LEN                    16

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
#define SRV_WAP_PUSH_TOTAL_WHITE_LIST_RECORD        NVRAM_EF_PUSH_WHITE_LIST_TOTAL
#endif

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
#define SRV_WAP_PUSH_TOTAL_BLACK_LIST_RECORD        NVRAM_EF_PUSH_BLACK_LIST_TOTAL
#endif

#define SRV_WAP_PUSH_TOTAL_CHAR_TO_DISPLAY_IN_LIST  WAP_PMG_MAX_MSG_LIST_HREF_CHARS


#if ((WAP_PMG_MAX_PUSH_MESSAGES > 0) && (WAP_PMG_MAX_PUSH_MESSAGES < (MAX_ASYNCDYNAMIC_ITEMS_BUFF * 2)))
#define SRV_WAP_PUSH_TOTAL_PUSH_LIST                WAP_PMG_MAX_PUSH_MESSAGES
#else
#define SRV_WAP_PUSH_TOTAL_PUSH_LIST                (MAX_ASYNCDYNAMIC_ITEMS_BUFF * 2)
#endif /* ((WAP_PMG_MAX_PUSH_MESSAGES > 0) && (WAP_PMG_MAX_PUSH_MESSAGES < (MAX_ASYNCDYNAMIC_ITEMS_BUFF * 2))) */

#define SRV_WAP_PUSH_MAX_MEM_SIZE    (1024 + sizeof (srv_wap_push_msg_inbox_struct) + sizeof(srv_wap_push_cntxt_struct) /*+ sizeof(mmi_wap_push_context_struct)*/ + 3*1024)
                                     /*Message queue + inbox structure variables and all + context variables + message display or Unknown dialogue display*/


/****************************************  END of constant defination  *******************************************/

typedef enum
{
    SRV_WAP_PUSH_NOTIFY_NMGR_NOT_NOTIFY = -1,
    SRV_WAP_PUSH_NOTIFY_NMGR_SIM1 = 1,
    SRV_WAP_PUSH_NOTIFY_NMGR_SIM2,
    SRV_WAP_PUSH_NOTIFY_NMGR_SIM3,
    SRV_WAP_PUSH_NOTIFY_NMGR_SIM4,
    SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM1,
    SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM2,
    SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM3,
    SRV_WAP_PUSH_NOTIFY_NMGR_HIGH_SIM4,
    SRV_WAP_PUSH_NOTIFY_NMGR_NOTIFY,

    SRV_WAP_PUSH_NOTIFY_NMGR_END
} srv_wap_push_notify_nmgr_sim_enum;


typedef enum
{
   SRV_WAP_PUSH_EVENT_FAILURE,
   SRV_WAP_PUSH_EVENT_INFO,
   SRV_WAP_PUSH_EVENT_WARNING,
   SRV_WAP_PUSH_EVENT_SUCCESS,
   SRV_WAP_PUSH_EVENT_PROGRESS,
   SRV_WAP_PUSH_EVENT_QUERY,
   SRV_WAP_PUSH_EVENT_MESSAGE_SENT,
   SRV_WAP_PUSH_EVENT_PROPLEM,
   SRV_WAP_PUSH_EVENT_EXPLICITLY_SAVED,
   SRV_WAP_PUSH_EVENT_EXPLICITLY_DELETED,
   SRV_WAP_PUSH_EVENT_CONFIRM,
   SRV_WAP_PUSH_EVENT_BATTERY_WARNING,
   SRV_WAP_PUSH_EVENT_NOT_AVAILABLE,
   SRV_WAP_PUSH_EVENT_ANSPHONE,
   SRV_WAP_PUSH_EVENT_REMIND,
   SRV_WAP_PUSH_EVENT_BATTERY_NOTIFY,
   SRV_WAP_PUSH_EVENT_TOTAL_NUM
} srv_wap_push_event_notify_enum;


typedef enum
{
    PUSH_TRANS_ID_START = 0,
    PUSH_NEW_MSG_DEL_TRANS_ID,
    PUSH_DEL_SL_AFTER_LOAD_TRANS_ID,
    PUSH_NMGR_UNREAD_MSG_CNT_TRANS_ID,
    PUSH_UPDATE_ICON_TRANS_ID,
    PUSH_DEL_MESSAGE_GENERIC_TRANS_ID,
    PUSH_DEL_ALL_MESSAGE_TRANS_ID,
    PUSH_GET_MSG_ON_IDLE_TRANS_ID,
    PUSH_MSG_LIST_INBOX_DSPLY_TRANS_ID,
    PUSH_DISPLAY_INBOX_COUNT_TRANS_ID,
    PUSH_GET_MSG_TO_DISPLAY_TRANS_ID,
    PUSH_GET_MSG_TO_DISPLAY_FROM_UM_TRANS_ID,
    PUSH_GET_MSG_DETAIL_TRANS_ID,
    PUSH_TB_UNREAD_MSG_LIST_TRANS_ID,
    PUSH_TB_UNREAD_MSG_CNT_TRANS_ID,
    PUSH_UPDATE_ICON_AND_TB_STATUS_AT_BOOT_TRANS_ID,
    PUSH_GET_MSG_DATA_FOR_TB_TRANS_ID,
    PUSH_NMGR_UNREAD_COUNT_FOR_SIM2_TRANS_ID,
    PUSH_NMGR_UNREAD_COUNT_FOR_SIM3_TRANS_ID,
    PUSH_NMGR_UNREAD_COUNT_FOR_SIM4_TRANS_ID,
    PUSH_DELETE_ALL_FROM_MESSAGE_OPTIONS,
    PUSH_DELETE_ALL_FOR_LAWMO,
    PUSH_LAUNCH_MSG_URL,
	PUSH_GET_MSG_CONTENT_TRANS_ID,
    PUSH_TRANS_ID_END
} srv_wap_push_trans_id_enum;


typedef enum
{
    SRV_WAP_PUSH_ERROR_SUCCESS = 0,
    SRV_WAP_PUSH_ERROR_DUPLICATE_ENTRY,
    SRV_WAP_PUSH_ERROR_LIST_FULL,
    SRV_WAP_PUSH_ERROR_SCREEN_DELETED,
    SRV_WAP_PUSH_ERROR_USER_CANCEL,
    SRV_WAP_PUSH_ERROR_NULL_ADDR,
    SRV_WAP_PUSH_ERROR_END
} srv_wap_push_add_list_error_enum;


typedef enum
{
    SRV_WAP_PUSH_SL_SETTING_PROMPT = 0,
    SRV_WAP_PUSH_SL_SETTING_AUTO_LAUNCH,
    SRV_WAP_PUSH_SL_SETTING_DISABLED,
    SRV_WAP_PUSH_SL_SETTING_END
} srv_wap_push_service_load_setting_enum;

typedef enum
{
    SRV_WAP_PUSH_SENDER_ADDR_TYPE_NONE = 0,
    SRV_WAP_PUSH_SENDER_ADDR_TYPE_PHONE_NUMBER = WAP_PMG_ADDR_PHONE,
    SRV_WAP_PUSH_SENDER_ADDR_TYPE_IP_ADDRESS = WAP_PMG_ADDR_IP,
    SRV_WAP_PUSH_SENDER_ADDR_TYPE_END
} srv_wap_push_sender_addr_type_enum;

typedef enum
{
    SRV_WAP_PUSH_WHITE_LIST = 0,
    SRV_WAP_PUSH_BLACK_LIST,
    SRV_WAP_PUSH_ADDR_LIST_TYPE_END
} srv_wap_push_addr_list_type_enum;

typedef enum
{
    SRV_WAP_PUSH_OPR_ADD_NEW = 0,
    SRV_WAP_PUSH_OPR_EDIT,
    SRV_WAP_PUSH_OPR_ADD_OTA,
    SRV_WAP_PUSH_OPR_TOTAL
} srv_wap_push_operation_type_enum;

typedef enum
{
    SRV_WAP_PUSH_INBOX_STATE_IDLE,
    SRV_WAP_PUSH_INBOX_STATE_LOADING,
    SRV_WAP_PUSH_INBOX_STATE_LIST_DISPLAYED,
    SRV_WAP_PUSH_INBOX_LIST_READY,
    SRV_WAP_PUSH_INBOX_NEED_REFRESH,

    SRV_WAP_PUSH_INBOX_STATE_END
} srv_wap_push_inbox_state_enum;

typedef enum
{
	SRV_WAP_PUSH_FALSE,
	SRV_WAP_PUSH_TRUE,
	SRV_WAP_PUSH_ASYNC_WAIT,
    SRV_PUSH_END
}srv_wap_push_result_enum;

typedef enum
{
    SRV_WAP_PUSH_DLG_TYPE_SIA = 0,
    SRV_WAP_PUSH_DLG_TYPE_UNKNOWN_ADDR,
    SRV_WAP_PUSH_DLG_TYPE_END
} srv_wap_push_service_dlg_type_enum;

typedef enum
{
    SRV_WAP_PUSH_RESTORE_GEN_SETTINGS = 0,
    SRV_WAP_PUSH_RESTORE_WHITE_LIST,
    SRV_WAP_PUSH_RESTORE_BLACK_LIST,
    SRV_WAP_PUSH_RESTORE_END
} srv_wap_push_restore_state_enum;


typedef enum
{
    SRV_WAP_PUSH_ADD_BKM_ERROR_SUCCESS = 0,
    SRV_WAP_PUSH_ADD_BKM_ERROR_EMPTY_TITLE,
    SRV_WAP_PUSH_ADD_BKM_ERROR_INVALID_TITLE,
    SRV_WAP_PUSH_ADD_BKM_ERROR_INVALID_URL,
    SRV_WAP_PUSH_ADD_BKM_ERROR_PROCESSING,
    SRV_WAP_PUSH_ADD_BKM_ERROR_BOOKMARK_FULL,
    SRV_WAP_PUSH_ADD_BKM_ERROR_EMPTY_URL,
    SRV_WAP_PUSH_ADD_BKM_ERROR_ALREADY_EXISTS,
    SRV_WAP_PUSH_ADD_BKM_ERROR_UNKNOWN_ERROR,
    SRV_WAP_PUSH_ADD_BKM_ERROR_CURRENTLY_NOT_AVAILABLE,
    SRV_WAP_PUSH_ADD_BKM_TITLE_URL_LONG_ERROR,

    SRV_WAP_PUSH_ADD_BKM_ERROR_END
} srv_wap_push_add_bkm_error;


typedef enum
{
    SRV_WAP_PUSH_ACTIVE_SIM_DEFAULT = 0,
    SRV_WAP_PUSH_ACTIVE_SIM_SIM1,
    SRV_WAP_PUSH_ACTIVE_SIM_SIM2,
    SRV_WAP_PUSH_ACTIVE_SIM_ALWAYS_ASK,
    SRV_WAP_PUSH_ACTIVE_SIM_WLAN,

    SRV_WAP_PUSH_ACTIVE_SIM_END
} srv_wap_push_active_sim_enum;

typedef enum
{
    SRV_WAP_PUSH_STATUS_ICON_NO_ICON = 0,
    SRV_WAP_PUSH_STATUS_ICON_SIM1,
    SRV_WAP_PUSH_STATUS_ICON_SIM2,
    SRV_WAP_PUSH_STATUS_ICON_DUAL_SIM,

    SRV_WAP_PUSH_STATUS_ICON_NO_END
} srv_wap_push_status_icon_enum;

typedef enum
{
    SRV_WAP_PUSH_GEN_SET_ENABLE_PUSH = 0,
    SRV_WAP_PUSH_GEN_SET_ENABLE_SL,
    SRV_WAP_PUSH_GEN_SET_ENABLE_WL,
    SRV_WAP_PUSH_GEN_SET_ENABLE_BL,
    SRV_WAP_PUSH_GEN_SET_END
} srv_wap_push_general_setting_enum;


/*********************************************************************/

typedef enum
{
    SRV_WAP_PUSH_SETTING_ENABLE,
    SRV_WAP_PUSH_SETTING_ENABLE_SL,
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    SRV_WAP_PUSH_SETTING_ENABLE_WHITE_LIST,
#endif
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    SRV_WAP_PUSH_SETTING_ENABLE_BLACK_LIST,
#endif /*__MMI_WAP_PUSH_BLACK_LIST__*/
#endif/*__COSMOS_MMI_PACKAGE__*/
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    SRV_WAP_PUSH_SETTING_WHITE_LIST,
#endif
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
#ifdef __COSMOS_MMI_PACKAGE__
    SRV_WAP_PUSH_SETTING_ENABLE_BLACK_LIST,
#endif /*__COSMOS_MMI_PACKAGE__*/
    SRV_WAP_PUSH_SETTING_BLACK_LIST,
#endif

    SRV_WAP_PUSH_SETTING_TOTAL
} srv_wap_push_setting_menu_enum;

typedef enum
{
    SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_ALL,
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    SRV_WAP_PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED,
#endif /* __MMI_WAP_PUSH_WHITE_LIST__  */
    SRV_WAP_PUSH_ENABLE_SETTING_DISABLE,

    SRV_WAP_PUSH_ENABLE_SETTING_TOTAL
} srv_wap_push_enable_setting_menu_enum;

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
typedef enum
{
    SRV_WAP_PUSH_WL_SETTING_DISCARD,
    SRV_WAP_PUSH_WL_SETTING_NOTIFY,
    SRV_WAP_PUSH_WL_SETTING_DISABLE,

    SRV_WAP_PUSH_WL_SETTING_TOTAL
} srv_wap_push_wl_setting_menu_enum;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
typedef enum
{
    SRV_WAP_PUSH_BL_SETTING_NOTIFY,
    SRV_WAP_PUSH_BL_SETTING_DISABLE,

    SRV_WAP_PUSH_BL_SETTING_TOTAL
} srv_wap_push_bl_setting_menu_enum;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

typedef enum
{
    SRV_WAP_PUSH_TL_NO_ERROR,
    SRV_WAP_PUSH_TL_SAME_ENTRY,
    SRV_WAP_PUSH_TL_NO_FIELD_ERROR,
    SRV_WAP_PUSH_TL_INVALID_SENDER,
    SRV_WAP_PUSH_TL_INVALID_SMSC,
    SRV_WAP_PUSH_TL_INVALID_IP,
}srv_wap_push_tl_error_code_enum;



/*************************************************END******************************************/
typedef struct message_queue
{
    U16 msg_type;
    U32 message_id;
	S8 msg_info[MAX_NOTIFICATION_INFO_LEN *ENCODING_LENGTH + 2];
    struct message_queue *next;
} srv_wap_push_idle_messge_queue_struct;

typedef struct push_dlg_queue
{
    U16 dlg_type;
    U32 trans_id;
    S8 dl_info[MAX_NOTIFICATION_INFO_LEN *ENCODING_LENGTH + 2];
    struct push_dlg_queue *next;
} srv_wap_push_dlg_queue_struct;


typedef struct 
{
    wps_pmg_dlg_type_enum dlg_type;    
    union {
        wps_pmg_dlg_sia_confirm_req_struct sia;  /* if dlg_type == WAP_PMG_DLG_SIA_CONFIRM */
        wps_pmg_dlg_unknown_addr_req_struct msg; /* if dlg_type == WAP_PMG_DLG_UNKOWN_ADDR_CONFIRM */
    } dlg_data;
} srv_wap_push_curr_dlg_struct;


 #if (MMI_MAX_SIM_NUM >= 2)
typedef struct
{
    U32 sim_id;
    U32 message_type;
    U32 message_id;
    U8 url[WAP_MAX_URL_LENGTH + 1];
}srv_wap_push_load_msg_struct;
#endif /* __MMI_WAP_DUAL_SIM__ */

typedef struct
{
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    S8 sender_address[MAX_PUSH_PHN_NUM_LEN *ENCODING_LENGTH + 2];
    S8 smsc_address[MAX_PUSH_PHN_NUM_LEN *ENCODING_LENGTH + 2];
    S8 ip_addr[MAX_PUSH_IP_ADDR_NUM_LEN *ENCODING_LENGTH];
    S8 IP1[SRV_WAP_PUSH_MAX_PART_IP_ADDRESS *ENCODING_LENGTH];
    S8 IP2[SRV_WAP_PUSH_MAX_PART_IP_ADDRESS *ENCODING_LENGTH];
    S8 IP3[SRV_WAP_PUSH_MAX_PART_IP_ADDRESS *ENCODING_LENGTH];
    S8 IP4[SRV_WAP_PUSH_MAX_PART_IP_ADDRESS *ENCODING_LENGTH];
    U16 total_wl_entry;
    U16 selected_wl_entry;

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    U16 total_bl_entry;
    U16 selected_bl_entry;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

    U16 selected_list_type;
    U16 slected_opr_type;
    U16 restore_state;
    U16 ota_addr_type;
    U16 num_unknwn_req;
    nvram_push_wl_addr_struct white_list[SRV_WAP_PUSH_TOTAL_WHITE_LIST_RECORD];
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    nvram_push_bl_addr_struct black_list[SRV_WAP_PUSH_TOTAL_BLACK_LIST_RECORD];
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
    nvram_push_general_setting_struct general_set;
} srv_wap_push_setting_cntxt_struct;

typedef struct inbox_struct
{
    U16 title_icon_id;
    U32 start_index;
    U32 end_index;
    U32 curr_index;
    U32 read_index;
    U32 msg_cnt_requested;
    U32 sel_idx;
    U32 num_of_messages;
    srv_wap_push_inbox_state_enum inbox_state;
    pmg_msg_list_struct list_item[SRV_WAP_PUSH_TOTAL_PUSH_LIST];
} srv_wap_push_msg_inbox_struct;

typedef enum
{
    SRV_WAP_PUSH_OK,
    SRV_WAP_PUSH_ERR,

    SRV_WAP_PUSH_END
} srv_wap_push_ret_code_enum;



typedef struct {
	MMI_EVT_PARAM_HEADER
} srv_wap_push_progress_event_struct;

typedef struct {
	MMI_EVT_PARAM_HEADER
    srv_wap_push_event_notify_enum evt_notify;
    U16 str_notify;
} srv_wap_push_popup_event_struct;


typedef struct {
    MMI_EVT_PARAM_HEADER
    
} srv_wap_push_delete_setting_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
} srv_wap_push_ota_list_entry_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_status_enum status;
    srv_wap_push_trans_id_enum trans_id;
    pmg_detailed_msg_struct* new_msg;
    S8 *url;
} srv_wap_push_handle_msg_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    srv_wap_push_trans_id_enum trans_id;
    wps_pmg_msg_list_cnf_struct* msg_list;
} srv_wap_push_msg_list_reply_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_msg_count_cnf_struct *msg_rsp;
    srv_wap_push_trans_id_enum trans_id;
} srv_wap_push_msg_count_rsp_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
} srv_wap_push_draw_unknown_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_dlg_sia_confirm_req_struct* msg; 
} srv_wap_push_service_init_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_dlg_query_cnf_struct* msg; 
} srv_wap_push_handle_dlg_data_rsp_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_delete_ind_struct* msg; 
} srv_wap_push_handle_storage_full_ind_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_delete_folder_ind_struct* msg; 
} srv_wap_push_delete_folder_ind_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    S16 count;
	kal_int32 msg_id;            
} srv_wap_push_msg_deleted_by_server_ind_struct;

typedef struct {

    U32 message_id;
    U32 timestamp;
    U32 sim_id;
   	kal_uint8 sl_setting;
    kal_uint8 addr[WAP_PMG_MAX_ADDR_CHARS+1]; 
} srv_wap_push_handle_sl_on_non_idle_struct;

typedef struct {
    U32 message_id;
    U32 timestamp;
    S8 *url;
    U32 sim_id;
	kal_uint8 sl_setting;
    kal_uint8 addr[WAP_PMG_MAX_ADDR_CHARS+1]; 
} srv_wap_push_handle_sl_on_idle_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    pmg_detailed_msg_struct *new_msg;
    S8 *url;
	kal_uint8 enable_push;
} srv_wap_push_handle_new_service_msg_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
} srv_wap_push_handle_pendig_event_on_idle_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
} srv_wap_push_fetch_dlg_from_queue_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
} srv_wap_push_inbox_init_event_struct;


typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_dlg_unknown_addr_req_struct* msg;
} srv_wap_push_service_unknown_addr_req_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_error_dlg_struct* msg;
} srv_wap_push_error_dlg_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_delete_msg_cnf_struct* msg;
} srv_wap_push_delete_msg_cnf_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    wps_pmg_delete_all_cnf_struct* msg;
} srv_wap_delete_all_cnf_struct;




#ifdef __MMI_PUSH_IN_UM__

typedef struct {
    MMI_EVT_PARAM_HEADER
    srv_um_delete_all_res_struct *msg;
} srv_wap_delete_all_res_struct;


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__


typedef struct {
    MMI_EVT_PARAM_HEADER
    srv_um_entry_mark_several_rsp_struct* msg;
} srv_wap_entry_mark_several_rsp_struct;

#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#endif /* __MMI_PUSH_IN_UM__ */



typedef struct
{
    U8 msg_type;
    U8 priority;
    U8 text_type;
    U8 read;
    U8 has_info;
    U32 msg_id;
    U32 expired;
    U32 created;
    U32 sim_id;
    U8 text[WAP_PMG_MAX_MSG_TEXT_CHARS + 2];
    pmg_addr_struct from;
    pmg_addr_struct smsc;
    S8 url[WAP_PMG_MAX_MSG_HREF_CHARS + 2];
} srv_wap_push_selected_msg_struct;

typedef struct 
{
    MMI_BOOL is_service_ready;
    srv_wap_push_notify_nmgr_sim_enum notify_nmgr;
    MMI_BOOL read_from_um;
    MMI_BOOL is_sim1_valid;
    MMI_BOOL is_sim2_valid; 
    srv_wap_push_idle_messge_queue_struct *message_queue_front;
    srv_wap_push_idle_messge_queue_struct *message_queue_rear;

  	srv_wap_push_dlg_queue_struct  *dlg_front;
	srv_wap_push_dlg_queue_struct  *dlg_rear;
	srv_wap_push_curr_dlg_struct *curr_dlg;
    srv_wap_push_addr_list_type_enum add_list_type;

    srv_wap_push_selected_msg_struct selected_message;
    U32 selected_message_id;

     #if (MMI_MAX_SIM_NUM >= 2)
    srv_wap_push_load_msg_struct launch_instance;  //SRV
    srv_wap_prof_profile_content_struct sim2_profile; //SRV
#endif /* __MMI_WAP_DUAL_SIM__ */
    srv_wap_prof_profile_content_struct sim1_profile; //SRV
 // #if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3)) 
  #if (MMI_MAX_SIM_NUM >= 3)
	 srv_wap_prof_profile_content_struct sim3_profile; //SRV
  #endif

 // #if (defined(GEMINI_PLUS) && (GEMINI_PLUS >= 4))
 #if (MMI_MAX_SIM_NUM >= 4)
	srv_wap_prof_profile_content_struct sim4_profile; //SRV
  #endif
  U32 unread_msgs_count;
  srv_wap_push_update_all_read_callback_func callback_func;
  #ifdef __DM_LAWMO_SUPPORT__
  srv_dm_lawmo_wipe_report_cb_func_type lawmo_cb;
  #endif /* __DM_LAWMO_SUPPORT__ */
 srv_wap_push_get_msg_content_callback_func msg_content_callback;
  void* readstatue_user_data;
  void* msg_content_user_data;
} srv_wap_push_cntxt_struct;


/******************************** Start of wjhite list OTA setting related data structures **********************************/
#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
#define SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT    5
#define SRV_WAP_PUSH_OTA_MAX_TO_PROXY           SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT
#define SRV_WAP_PUSH_OTA_MAX_TO_NAPID           SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT
#define SRV_WAP_PUSH_OTA_PROXY_ID_LEN           41
#define SRV_WAP_PUSH_OTA_MAX_NAPID_LEN          41
#define SRV_WAP_PUSH_OTA_MAX_PXADDR_LEN         MAX_PUSH_PHN_NUM_LEN
#define SRV_WAP_PUSH_OTA_MAX_NAPADDR_LEN        MAX_PUSH_PHN_NUM_LEN

typedef enum
{
    SRV_WAP_PUSH_CCA_NODE_PROXY = 0,
    SRV_WAP_PUSH_CCA_NODE_APP,
    SRV_WAP_PUSH_CCA_NODE_NAPDEF,

    SRV_WAP_PUSH_CCA_NODE_END
} srv_wap_push_ota_cca_tag_symbol_enum;

typedef enum
{
    SRV_WAP_PUSH_OTA_DATA_SRC_PROXY,
    SRV_WAP_PUSH_OTA_DATA_SRC_NAPDEF,

    SRV_WAP_PUSH_OTA_DATA_SRC_END
} srv_wap_push_ota_data_src_enum;

typedef enum
{
    SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_IP,
    SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SENDER,
    SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_SMSC,

    SRV_WAP_PUSH_OTA_TRUSTLIST_TYPE_END
} srv_wap_push_ota_trustlist_type_enum;

typedef enum
{
    SRV_WAP_PUSH_OTA_MODULE_WAITING,
    SRV_WAP_PUSH_OTA_MODULE_READY,

    SRV_WAP_PUSH_OTA_MODULE_STATUS_END
} srv_wap_push_ota_module_status_enum;

typedef struct
{
    U8 app_to_proxy[SRV_WAP_PUSH_OTA_MAX_TO_PROXY][SRV_WAP_PUSH_OTA_PROXY_ID_LEN];
    U8 app_to_napid[SRV_WAP_PUSH_OTA_MAX_TO_NAPID][SRV_WAP_PUSH_OTA_MAX_NAPID_LEN];
} srv_wap_push_application_tag_struct;

typedef struct
{
    S32 px_addrtype;
    U8 px_id[SRV_WAP_PUSH_OTA_PROXY_ID_LEN];
    U8 px_addr[SRV_WAP_PUSH_OTA_MAX_PXADDR_LEN];
} srv_wap_push_ota_proxy_tag_struct;

typedef struct
{
    S32 nap_addrtype;
    U8 nap_id[SRV_WAP_PUSH_OTA_MAX_NAPID_LEN];
    U8 nap_addr[SRV_WAP_PUSH_OTA_MAX_NAPADDR_LEN];
} srv_wap_push_ota_napdef_tag_struct;

typedef struct
{
    S8 crnt_trustlist_index;
    S8 total_trustlist_count;
    cca_status_enum installed_result;
    MMI_BOOL scr_deleted;
    MMI_BOOL cca_status_sent;
    srv_wap_push_application_tag_struct *app_list[SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT];
    srv_wap_push_ota_proxy_tag_struct *proxy_list[SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT];
    srv_wap_push_ota_napdef_tag_struct *nap_address_list[SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT];
    nvram_push_addr_struct *trustlist[SRV_WAP_PUSH_OTA_MAX_TRUSTLIST_COUNT];    /* Keeping 10 entries */
} srv_wap_push_ota_context;
extern srv_wap_push_ota_context g_srv_wap_push_ota_cntxt;
#endif /* __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__ */

#endif /* WAP_SUPPORT */
#endif /* __PUSH_MSG_SRV_TYPE__ */
