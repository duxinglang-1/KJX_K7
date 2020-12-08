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
 *  SmsSettingSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Setting Handler
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "string.h"
#include "stdio.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "ems.h"
#include "gui_data_types.h"
#include "wgui_touch_screen.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "CustDataRes.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "wgui_categories_inputs.h"
#include "PhbSrvGprot.h"
#include "customer_email_num.h"
#include "custom_phb_config.h"
#include "mmi_msg_context.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "ps_public_enum.h"
#include "SmsAppType.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "mmi_rp_app_phonebook_def.h"
#include "ImeGprot.h"
#include "AlertScreen.h"

#include "SmsSrvGprot.h"
#include "SmsCuiGprot.h"
#include "SmsProtCui.h"
#include "SmsUtilCui.h"
#include "mmi_frm_events_gprot.h"
#include "SmsGenericCui.h"
#include "PhoneBookGprot.h"
#include "PhbCuiGprot.h"
#include "UcmSrvGprot.h"
#include "app_usedetails.h"
#include "FileMgrSrvGProt.h"
#include "SmsGuiInterfaceProt.h"
#include "FSEditorCuiGprot.h"
#include "MenuCuiGprot.h"
#include "SimCtrlSrvGProt.h"
#include "ModeSwitchSrvGprot.h"
#ifdef __SRV_SMS_MULTI_SIM__
#include "NwUsabSrvGprot.h"
#endif
#include "mmi_frm_utility_gprot.h"


#if (MMI_MAX_SIM_NUM >= 3)
#include "SimSelCuiGprot.h"
#endif /* (MMI_MAX_SIM_NUM >= 3) */

/**************************************************************
* MARCO
**************************************************************/
#if defined(__LOW_COST_SUPPORT_COMMON__)
#define CUI_SMS_MAX_SEND_INSTANCE   1
#else
#define CUI_SMS_MAX_SEND_INSTANCE   2
#endif
#define CUI_SMS_MAX_SENDING_CAPTION_LEN     120
#define CUI_SMS_MAX_COMFIRM_LEN             120
#define DEFAULT_LIST_ITEM_NUM               3

/**************************************************************
* Structure Declaration
**************************************************************/
typedef void (*SmsCuiCBFuncPtr) (cui_sms_result_enum, void*);

typedef enum
{
    ENTER_NUMBER_INDEX = 0,
    ADD_FROM_CONTACTS_INDEX,
    ITEM_NUM_ABOVE_LINE
}cui_sms_recipient_item_index_enum;

typedef enum
{
    SEND_FSM_STATE_START,
    SEND_FSM_STATE_SEND_REQ,
    SEND_FSM_STATE_SEND_RSP,
    SEND_FSM_STATE_DEL_SUCC_REQ,
    SEND_FSM_STATE_DEL_SUCC_RSP,
    SEND_FSM_STATE_DEL_FAIL_REQ,
    SEND_FSM_STATE_DEL_FAIL_RSP,
    SEND_FSM_STATE_SAVE_SUCC_REQ,
    SEND_FSM_STATE_SAVE_SUCC_RSP,
    SEND_FSM_STATE_SAVE_FAIL_REQ,
    SEND_FSM_STATE_SAVE_FAIL_RSP,
    SEND_FSM_STATE_FINISH,
    SEND_FSM_STATE_END
}cui_sms_send_fsm_state_enum;

#define DEFAULT_HILITE_WITHOUT_RECIPIENT    ADD_FROM_CONTACTS_INDEX
#define DEFAULT_HILITE_WITH_RECIPIENT       ITEM_NUM_ABOVE_LINE

typedef struct
{
    S8 recipient_data[(CUI_SMS_MAX_ADDR_LEN + 1) *CUI_SMS_MAX_RECIPIENTS_NUM];
    MMI_BOOL valid_flag;
} cui_sms_send_recipient_data_struct;

typedef struct
{
    U16 highlihgt_index;
    MMI_BOOL is_modify;  
    MMI_BOOL is_hide_save_menu;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    cui_sms_address_type_enum addr_type;
    U16 max_email_addr_len;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    U16 pre_total_num;
    U16 invalid_num;
}cui_sms_add_recipient_struct;

typedef struct
{
    U16 curr_send_index;
    U16 total_num;
    S8 *recipient[CUI_SMS_MAX_RECIPIENTS_NUM];
    cui_sms_result_enum send_result[CUI_SMS_MAX_RECIPIENTS_NUM];
    MMI_BOOL is_sending;    //To Control the abort action
    MMI_BOOL is_aborting;   //To Control the Send action
    U16 msg_index;
    U8 *sending_caption_buff;
}cui_sms_send_info_struct;

typedef struct
{
    U16 msg_index;
    MMI_BOOL del_send_succ_flag;        //Whether Delete the sent msg
    MMI_BOOL del_send_fail_flag;        //Whether Delete the send failed msg
    MMI_BOOL save_send_fail_flag;       //Whether Save the send failed msg to Outbox
    MMI_BOOL save_sent_flag;

    cui_sms_send_fsm_state_enum state;
    SmsCuiCBFuncPtr result_func;
    SMS_HANDLE srv_save_handle;
}cui_sms_send_fsm_struct;

typedef struct
{
    mmi_id sms_gid;
    MMI_BOOL is_send_finish;
    cui_sms_result_enum result;
} cui_evt_sms_send_popup_info_struct;

typedef struct
{
    U16 total_num;
    srv_sms_sim_enum sim_id;
    S8 *recipient[CUI_SMS_MAX_RECIPIENTS_NUM];
    cui_sms_add_recipient_struct recipient_info;
    cui_sms_send_info_struct send_info;
    cui_sms_edit_phone_number_struct *edit_num_info;
    cui_sms_send_fsm_struct *send_fsm_info;

    U16 reply_msg_id;
    U16 msg_id;
    srv_sms_send_type_enum send_type;
    srv_sms_command_type_enum cmdtype;

    srv_sms_specify_send_para_enum spec_para;
    srv_sms_para_enum para_flag;
    S8 sc_address[CUI_SMS_MAX_ADDR_LEN + 1];
    U16 src_port;
    U16 dest_port;
    srv_sms_pid_enum pid;
    srv_sms_vp_enum vp;
    srv_sms_dcs_enum dcs;
    srv_sms_class_enum class_type;
    U16 sending_str_id;
    MMI_BOOL is_allow_num_emtpy;
    MMI_BOOL is_allow_sc_emtpy;
    MMI_BOOL status_report;
    MMI_BOOL reply_path;
    MMI_BOOL is_asc_content;
    MMI_BOOL is_mms;
    U16 content_buff_size;
    S8 *content_buff;
    S8 *content_file_path;
    EMSData *content_ems;
} cui_sms_send_handle_data_struct;

typedef struct
{
    mmi_id send_gid;
    mmi_id parent_gid;
    mmi_id child_gid;
    cui_sms_send_hidden_scrn_enum hiden_scrn;
    cui_sms_send_case_enum send_msg_case;
    cui_sms_send_handle_data_struct *data;
    SMS_HANDLE srv_send_handle;
#ifdef __MMI_DUAL_SIM_MASTER__
    MMI_BOOL is_direct_send;
#endif
} cui_sms_send_handle_struct;

/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/
extern EMSTATUS EMSSetMsgClass(EMSData *emsData, kal_uint8 msg_class);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
#ifndef __ULC_SLIM_EMS__
extern void MoveCursorToPosition(EMSData *data, EMSPosition *dst);
#endif
extern MMI_BOOL srv_sms_check_ucs2(S8* ucs2_text_buff, U16 char_num);
extern void mmi_phb_mark_several_for_msg_get_number(U8 *dest, U8 max_dest_len, U16 PhbIndex, U8 num_type);
extern srv_sms_cause_enum srv_sms_read_content_into_ems(
                            EMSData* ems_data,
                            S8* file_path,
                            srv_sms_dcs_enum dcs);
extern srv_sms_cause_enum srv_sms_add_content_into_ems(
                            EMSData* ems_data,
                            S8* content_buff,
                            U16 content_buff_size,
                            srv_sms_dcs_enum dcs,
                            MMI_BOOL is_asc_content);


/**************************************************************
* Static Variables Defination
**************************************************************/

//cui_sms_send_struct *send_gid_data[GRP_ID_SMS_CUI_SEND_MULTI - GRP_ID_SMS_CUI_SEND];
static mmi_id cui_sms_send_instance[CUI_SMS_MAX_SEND_INSTANCE];
static mmi_id cui_sms_send_active_gid = GRP_ID_INVALID;
static U8 send_instance_in_use = 0;
static cui_sms_result_enum popup_result = CUI_SMS_RESULT_OK;
static cui_sms_send_recipient_data_struct recipient_pool[CUI_SMS_MAX_SEND_INSTANCE];
static void *invalid_send_handle = NULL;

/**************************************************************
* Static Function Declaration
**************************************************************/
static mmi_id cui_sms_get_active_send_gid(void);
static void cui_sms_set_active_send_gid(mmi_id sms_gid);
static cui_sms_send_handle_struct* cui_sms_get_send_handle(mmi_id sms_send_gid);
static cui_sms_send_handle_data_struct* cui_sms_get_send_handle_data(mmi_id sms_send_gid);
static cui_sms_edit_phone_number_struct* cui_sms_get_edit_number_info(mmi_id sms_send_gid);
static mmi_ret cui_sms_send_proc(mmi_event_struct* evt);
static void cui_sms_pre_send_entry(mmi_id sms_send_gid);
static void cui_sms_send_entry(mmi_id sms_send_gid);
static mmi_ret cui_sms_pre_send_entry_popup_proc(mmi_event_struct *param);
static void cui_sms_send_deinit_handle(cui_sms_send_handle_struct *handle);
static MMI_BOOL cui_sms_add_recipient(mmi_id sms_send_gid, S8 *ucs2_addr);
static void cui_sms_abort_send_msg(void);
static MMI_BOOL cui_sms_is_send_enable(void);
static void cui_sms_pre_entry_add_recipient(void);
static void cui_sms_entry_add_recipient(mmi_scrn_essential_struct* scrn_data);
static void cui_sms_goback_from_cur_send_proc(void);
static mmi_ret cui_sms_popup_goback_from_edit_sc_proc(mmi_event_struct *param);
static mmi_ret cui_sms_entry_cur_send_scrn_fail_proc(mmi_event_struct *param);
static MMI_BOOL cui_sms_send_is_scrn_present(mmi_id sms_gid);
static MMI_BOOL cui_sms_recipient_set_separator_line(S32 index, U32* flag, U32* flag_ex);
static void cui_sms_recipient_highlight_hdlr(S32 index);
static void cui_sms_recipient_enter_number(void);
static void cui_sms_entry_phone_number_generic(
            U16 screen_id,
            U16 tilte_id,
            cui_sms_address_type_enum addr_type,
            S8 *ucs2_addr,
            U16 max_addr_len,
            SmsFullEditFuncPtr done_func,
            MMI_BOOL is_search_phonebook);
static void cui_sms_send_edit_phone_number(void);
static void cui_sms_entry_phone_number_leave_proc(cui_sms_send_handle_struct *handle);
static void cui_sms_phone_number_empty_handle(cui_sms_send_handle_struct *handle, MMI_BOOL is_empty);

static void cui_sms_phone_number_done(cui_sms_send_handle_struct *handle);
static void cui_sms_search_phonebook(cui_sms_send_handle_struct *handle);
static void cui_sms_get_sc_addr_from_phb(mmi_id sms_gid, S8* name, S8* number);
static S32 cui_sms_recipient_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
static void cui_sms_recipient_enter_number_done(S8 *ucs2_addr);
static void cui_sms_recipient_add_from_contacts(void);
#ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
static void cui_sms_get_addr_from_phb_list(mmi_id sms_send_gid, U16 count, U16 *phb_index, U8 *num_type);
static void cui_sms_get_addr_from_caller_group(mmi_id sms_send_gid, U16 count, U16 *phb_index, U8 *num_type);
static U16 cui_sms_add_phb_number_to_recipient(mmi_id sms_send_gid, U16 count, U16 *phb_index, U8 *num_type);
#endif
static void cui_sms_recipient_get_number_from_phb(mmi_id sms_send_gid, S8* name, S8* number);

static void cui_sms_entry_recipient_exceeded_confirm(mmi_id sms_send_gid, U16 count, MMI_BOOL is_send);
static void cui_sms_recipient_exceeded_handle(void);
static void cui_sms_recipient_exceeded_confirm_go_back(void);
static void cui_sms_entry_add_recipient_options(void);
static mmi_ret cui_sms_add_recipient_entry_hdlr(cui_menu_event_struct *menu_evt);
static mmi_ret cui_sms_add_recipient_select_hdlr(cui_menu_event_struct *menu_evt);
static void cui_sms_pre_send_msg(void);
static void cui_sms_entry_sc_number(void);
static void cui_sms_sc_number_done(S8 *ucs2_num);
#ifdef __MMI_MESSAGES_SMS_EMAIL__
static void cui_sms_entry_email_sc_number(void);
static void cui_sms_email_sc_number_done(S8 *ucs2_num);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
static void cui_sms_send_msg_interal(void);
static void cui_sms_init_send_info_data(mmi_id sms_send_gid);
static void cui_sms_send_curr_msg(mmi_id sms_send_gid);
static void cui_sms_send_msg_fsm(cui_sms_send_handle_struct *handle, cui_sms_send_fsm_struct *data);
static void cui_sms_send_msg_fsm_handle(srv_sms_callback_struct *callback_data);
static void cui_sms_send_msg_req(mmi_id sms_send_gid, SrvSmsCallbackFunc callback_func);
static void cui_sms_send_msg_handle(cui_sms_result_enum result, void *data);
static void cui_sms_save_msg_req(cui_sms_send_handle_struct *cui_send_handle, srv_sms_status_enum set_status, SrvSmsCallbackFunc callback_func);
static MMI_BOOL cui_sms_get_send_finish_popup_info(cui_sms_send_handle_struct *handle, U16 *body_str_id, mmi_event_notify_enum *event_id);
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
static void cui_sms_phb_save_contact(S8 **ascii_addr_list, U16 addr_count);
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */
static void cui_sms_entry_sending(void);
static void cui_sms_entry_abort_sending(void);
static U8* cui_sms_get_sending_caption(mmi_id sms_send_gid);
static void cui_sms_update_sending_caption(mmi_id sms_send_gid);
#ifdef __MMI_DUAL_SIM_MASTER__
static void cui_sms_set_send_select_sim_leaf_item(MMI_ID cui_menu_gid, MMI_MENU_ID menu_id, srv_sms_para_enum para_flag);
static void cui_sms_recipient_opt_send_by_sim(srv_sms_sim_enum sim_id);
#ifndef __MMI_UNIFIED_COMPOSER__
static void cui_sms_set_save_select_sim_leaf_item(MMI_ID cui_menu_gid, MMI_MENU_ID menu_id);
#endif /* __MMI_UNIFIED_COMPOSER__ */

#if (MMI_MAX_SIM_NUM >= 3)
static void cui_sms_recipient_opt_send_by_sim3(void);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
static void cui_sms_recipient_opt_send_by_sim4(void);
#endif
static void cui_sms_dm_pre_send_msg(void);
static void cui_sms_set_send_sim_type(srv_sms_sim_enum sim_id);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __EMS_DYNAMIC_SEG_NUM__
static MMI_BOOL cui_sms_entry_check_dynamic_seg_num(void);
#ifdef __MMI_MESSAGES_SMS_EMAIL__
static U8 cui_sms_get_edit_email_sms_segment_num(EMSData *edit_ems, cui_sms_send_handle_data_struct *hd_data);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
static void cui_sms_entry_long_msg_confirm(mmi_id sms_send_gid, U8 segment_num);
#endif /* __EMS_DYNAMIC_SEG_NUM__ */ 

#if (MMI_MAX_SIM_NUM == 1)
static void cui_sms_recipient_opt_send(void);
#endif
static void cui_sms_recipient_opt_edit(void);
static void cui_sms_recipient_opt_remove(void);
static void cui_sms_recipient_pre_remove(void);
static void cui_sms_recipient_opt_remove_all(void);
static void cui_sms_recipient_pre_remove_all(void);
static void cui_sms_recipient_opt_save_to_drafts(void);
static void cui_sms_edit_curr_recipient(mmi_id sms_send_gid);
static void cui_sms_edit_recipient_done(S8 *ucs2_addr);
static MMI_BOOL cui_sms_append_recipient(mmi_id sms_send_gid, S8 *ucs2_addr);
static void cui_sms_remove_curr_recipient(cui_sms_send_handle_data_struct *hd_data);
static void cui_sms_remove_all_recipient(cui_sms_send_handle_data_struct *hd_data);
#if defined(__EMS_DYNAMIC_SEG_NUM__) || defined(__MMI_MESSAGES_SMS_EMAIL__)
static MMI_BOOL cui_sms_convert_send_content_to_emsdata(cui_sms_send_handle_struct *handle, EMSData *edit_ems_data);
#endif
static void cui_sms_send_evt_send_to_parent(mmi_id sms_gid, MMI_BOOL is_send_finish, cui_sms_result_enum result);
static mmi_ret cui_sms_popup_send_evt_to_parent(mmi_event_struct *param);
static void cui_sms_pre_send_evt_send_to_parent(mmi_id sms_gid, MMI_BOOL is_send_finish, cui_sms_result_enum result);
static void cui_sms_send_evt_send_to_parent_internal(mmi_id sms_gid, MMI_BOOL is_send_finish, cui_sms_result_enum result, MMI_BOOL is_pre_send);
static void cui_sms_send_evt_send_to_parent_internal_ext(mmi_id sms_gid, cui_sms_event_enum send_event, MMI_BOOL is_send_finish, cui_sms_result_enum result, MMI_BOOL is_pre_send);
static MMI_BOOL cui_sms_compare_number(S8* number1, S8* number2);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_sms_fte_add_recipient_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)*/
#if (MMI_MAX_SIM_NUM >= 3)
static void cui_sms_use_sim_selector(void);
#endif

static void cui_sms_set_common_para(
            cui_sms_send_handle_data_struct *data, 
            SMS_HANDLE srv_save_handle);

/**************************************************************
* Function Defination
**************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_malloc_recipient_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S8* cui_sms_send_malloc_recipient_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *recipient_data = NULL;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_SMS_MAX_SEND_INSTANCE; i++)
    {
        if (recipient_pool[i].valid_flag == MMI_FALSE)
        {
            recipient_data = recipient_pool[i].recipient_data;
            recipient_pool[i].valid_flag = MMI_TRUE;
            break;
        }
    }

    return recipient_data;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_reset_recipient_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_send_reset_recipient_data(S8 *recipient_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((S8*) recipient_data, 0, (CUI_SMS_MAX_ADDR_LEN + 1) *CUI_SMS_MAX_RECIPIENTS_NUM);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_free_recipient_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_send_free_recipient_data(S8 *recipient_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_SMS_MAX_SEND_INSTANCE; i++)
    {
        if ((recipient_pool[i].recipient_data == recipient_data) &&
            (recipient_pool[i].valid_flag == MMI_TRUE))
        {
            cui_sms_send_reset_recipient_data(recipient_data);
            recipient_pool[i].valid_flag = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_is_send_busy
 * DESCRIPTION
 *  check if can send
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL cui_sms_is_send_busy(srv_sms_send_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (send_instance_in_use >= CUI_SMS_MAX_SEND_INSTANCE)
    {
        return MMI_FALSE;
    }

    if(type == SRV_SMS_BG_SEND)
    {
        return srv_sms_is_bg_send_action_busy();
    }
    else if(type == SRV_SMS_FG_SEND)
    {
        return srv_sms_is_send_action_busy();
    }
    else if (type == SRV_SMS_BG_SAVE_SEND)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_active_send_gid
 * DESCRIPTION
 *  Cntx mgr get current running sg id
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id
 *****************************************************************************/
static mmi_id cui_sms_get_active_send_gid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /**
         * Now use framework api to get current running sg id. In furture, maybe need to maintain it by itself
         */
    //return mmi_frm_group_get_active_id();
    return cui_sms_send_active_gid;
}


static void cui_sms_set_active_send_gid(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_send_active_gid = sms_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_send_parent_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static cui_sms_send_handle_struct* cui_sms_get_send_handle(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_CUI_SEND_HD, sms_send_gid);

    handle = (cui_sms_send_handle_struct*)mmi_frm_group_get_user_data(sms_send_gid);

    MMI_ASSERT(handle != NULL);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_CUI_SEND_HD_1, handle);

    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_send_parent_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static cui_sms_send_handle_data_struct* cui_sms_get_send_handle_data(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_CUI_SEND_HD_DATA, sms_send_gid);
    handle = cui_sms_get_send_handle(sms_send_gid);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_CUI_SEND_HD_DATA_1, handle->data);
    MMI_ASSERT(handle->data != NULL);
    return handle->data;
}



/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_edit_number_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static cui_sms_edit_phone_number_struct* cui_sms_get_edit_number_info(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_EDIT_PHONE_NUM_INFO, sms_send_gid);

    handle = (cui_sms_send_handle_struct*)mmi_frm_group_get_user_data(sms_send_gid);

    if (sms_send_gid == handle->send_gid)
    {
         MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_EDIT_PHONE_NUM_INFO_1, handle->data->edit_num_info);
        return handle->data->edit_num_info;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_id cui_sms_send_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = GRP_ID_INVALID;
    mmi_id string_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_CUI_SEND_CREATE, parent_gid);

    if ( (srv_sms_is_sms_valid() == MMI_FALSE) ||
        (send_instance_in_use >= CUI_SMS_MAX_SEND_INSTANCE))
    {
        string_id = STR_GLOBAL_NOT_AVAILABLE;
    }
    else if (srv_sms_is_sms_ready() == MMI_FALSE)
    {
        string_id = STR_SMS_MSG_NOT_READY_YET;
    }
    
    if (string_id != 0)
    {
        cui_sms_display_popup_ext(
            string_id,
            MMI_EVENT_FAILURE);
    }
    else
    {
        U32 i;
        S8 *recipient_data;
        cui_sms_send_handle_struct *gid_data = OslMalloc(sizeof(cui_sms_send_handle_struct));

        MMI_ASSERT(gid_data != NULL);
        memset(gid_data, 0, sizeof(cui_sms_send_handle_struct));

        gid_data->parent_gid = parent_gid;

        gid_data->hiden_scrn |= CUI_SMS_SEND_ADD_RECIPIENT_SCR;
        gid_data->hiden_scrn |= CUI_SMS_SEND_SC_SCR;

        gid_data->data = OslMalloc(sizeof(cui_sms_send_handle_data_struct));

        MMI_ASSERT(gid_data->data != NULL);
        memset(gid_data->data, 0, sizeof(cui_sms_send_handle_data_struct));

        recipient_data = cui_sms_send_malloc_recipient_data();

        for (i = 0; i < CUI_SMS_MAX_RECIPIENTS_NUM; i++)
        {
            gid_data->data->recipient[i] = &recipient_data[i * (CUI_SMS_MAX_ADDR_LEN + 1)];
        }

    #ifndef __MMI_DUAL_SIM_MASTER__
        gid_data->data->para_flag |= SRV_SMS_PARA_SIM_ID;
        gid_data->data->sim_id = SRV_SMS_SIM_1;
    #endif

        gid_data->data->reply_msg_id = SRV_SMS_INVALID_MSG_ID;
        gid_data->data->recipient_info.is_hide_save_menu = MMI_TRUE;
        gid_data->data->recipient_info.is_modify = MMI_FALSE;

        gid_data->data->is_allow_sc_emtpy = MMI_TRUE;

        gid_data->data->sending_str_id = 0;

        sms_send_gid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_sms_send_proc, gid_data);

        gid_data->send_gid = sms_send_gid;

        for (i = 0; i< CUI_SMS_MAX_SEND_INSTANCE; i++)
        {
            if (cui_sms_send_instance[i] == 0)
            {
                cui_sms_send_instance[i] = sms_send_gid;
                send_instance_in_use++;
                break;
            }
        }
    }

    return sms_send_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret cui_sms_send_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *send_hd = (cui_sms_send_handle_struct*)evt->user_data;
#ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
    cui_phb_multi_select_contact_result_struct *multi_select_result;
#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */
    cui_phb_select_contact_result_struct *select_result;
    cui_evt_sms_save_struct *save_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_CUI_SEND_PROC, evt->evt_id, send_hd);

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        {
        #if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
            /* register SIM avaiablity change event proc here */
            mmi_frm_cb_reg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, cui_sms_send_proc, send_hd);
        #endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */
            break;
        }

        case EVT_ID_GROUP_ACTIVE:
            cui_sms_set_active_send_gid(send_hd->send_gid);
            if (srv_sim_ctrl_get_one_available_sim() == 0)
            {
                mmi_frm_group_close(send_hd->send_gid);
            }
            break;

        case EVT_ID_GROUP_INACTIVE:
            if ((send_hd->parent_gid != GRP_ID_INVALID)
                && (cui_sms_send_is_scrn_present(send_hd->send_gid) == MMI_FALSE))
            {
                 if (!(mmi_frm_scrn_is_present(send_hd->send_gid, SCR_ID_SMS_ADD_RECIPIENT, MMI_FRM_NODE_ALL_FLAG)))
                {
                    cui_sms_pre_send_evt_send_to_parent(send_hd->send_gid, MMI_TRUE, CUI_SMS_RESULT_GROUP_GOBACK);
                }
            }
            break;

        case EVT_ID_GROUP_DEINIT:
        {
        #if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
            /* deregister SIM avaiablity change event proc here */
            mmi_frm_cb_dereg_event(EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED, cui_sms_send_proc, send_hd);
        #endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */
            /* need addd code to release buffer */
            cui_sms_send_deinit_handle(send_hd);
            break;
        }   
        case EVT_ID_CUI_SMS_SAVE:
            save_event = (cui_evt_sms_save_struct*)evt;
            cui_sms_save_close(send_hd->child_gid);
            if (save_event->save_result == MMI_TRUE)
            {
                cui_sms_pre_send_evt_send_to_parent(send_hd->send_gid, MMI_TRUE, CUI_SMS_RESULT_SAVE_TO_DRAFTS);
            }
            break;

        case EVT_ID_CUI_SMS_SAVE_CANCEL:
            cui_sms_save_close(send_hd->child_gid);
            break;
#ifndef __MMI_MAINLCD_96X64__
    #ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
        case EVT_ID_PHB_SELECT_MULTI_CONTACT:
            multi_select_result = (cui_phb_multi_select_contact_result_struct*) evt;
            if (multi_select_result->is_group)
            {
                cui_sms_get_addr_from_caller_group(
                    send_hd->send_gid,
                    multi_select_result->count,
                    multi_select_result->store_index,
                    multi_select_result->field);
            }
            else
            {
                cui_sms_get_addr_from_phb_list(
                    send_hd->send_gid,
                    multi_select_result->count,
                    multi_select_result->store_index,
                    multi_select_result->field);
            }
            cui_phb_list_group_select_contact_close(send_hd->child_gid);
            break;

        case EVT_ID_PHB_SELECT_MULTI_CONTACT_CANCEL:
            cui_phb_list_group_select_contact_close(send_hd->child_gid);
            break;
    #endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */
#endif
        case EVT_ID_PHB_SELECT_CONTACT:
            select_result = (cui_phb_select_contact_result_struct*) evt;
            if (send_hd->data->edit_num_info == NULL)
            {
                cui_sms_recipient_get_number_from_phb(
                    send_hd->send_gid,
                    (S8*)select_result->name,
                    (S8*)select_result->select_data);
            }
        #ifndef __MMI_SMS_SLIM__
            else
            {
                cui_sms_get_sc_addr_from_phb(
                    send_hd->send_gid,
                    (S8*)select_result->name,
                    (S8*)select_result->select_data);
            }
        #endif
            cui_phb_list_select_contact_close(send_hd->child_gid);
            break;
        
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
            cui_phb_list_select_contact_close(send_hd->child_gid);
            break;

        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            {
                cui_sms_edit_phone_number_struct *edit_num_info = cui_sms_get_edit_number_info(send_hd->send_gid);

                switch (edit_num_info->phone_number_addr_type)
                {
                #ifdef __MMI_MESSAGES_SMS_EMAIL__
                    case CUI_SMS_ADDR_TYPE_EMAIL_ADDR:
                        cui_fseditor_get_text(
                            edit_num_info->editor_gid,
                            (WCHAR*)edit_num_info->phone_number_buff,
                            edit_num_info->phone_number_max_addr_len *ENCODING_LENGTH + ENCODING_LENGTH);
                        break;
                #endif /*  __MMI_MESSAGES_SMS_EMAIL__*/

                    case CUI_SMS_ADDR_TYPE_NUMBER:
                    default:
                        cui_fseditor_get_text(
                            edit_num_info->editor_gid,
                            (WCHAR*)edit_num_info->phone_number_buff,
                            edit_num_info->phone_number_max_addr_len *ENCODING_LENGTH + ENCODING_LENGTH);
                        break;
                }

                if (mmi_ucs2strlen(edit_num_info->phone_number_buff))
                {
                    cui_sms_phone_number_done(send_hd);
                }
            #ifndef __MMI_SMS_SLIM__
                else if (edit_num_info->phone_number_search_flag == MMI_TRUE)
                {
                    cui_sms_search_phonebook(send_hd);
                }
            #endif /* __MMI_SMS_SLIM__ */
            }
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
            {
                MMI_ID editor_gid = send_hd->data->edit_num_info->editor_gid;
                cui_sms_entry_phone_number_leave_proc(send_hd);
			    cui_fseditor_close(editor_gid);
            }
            break;

        case EVT_ID_CUI_FSEDITOR_EMPTY:
            cui_sms_phone_number_empty_handle(send_hd, MMI_TRUE);
            break;

        case EVT_ID_CUI_FSEDITOR_NOT_EMPTY:
            cui_sms_phone_number_empty_handle(send_hd, MMI_FALSE);
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                if (menu_evt->parent_menu_id == MENU_ID_SMS_RECIPIENT_OPTIONS)
                {
                    cui_sms_add_recipient_entry_hdlr(menu_evt);    
                }
            #if (MMI_MAX_SIM_NUM >= 2)
                else if (menu_evt->parent_menu_id == MENU_ID_SMS_RECIPIENT_OPT_SEND)
                {
                    if (send_hd->is_direct_send) /* must compiled with __MMI_DUAL_SIM_MASTER__ */
                    {
                        cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                    }
                    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    {
                        MMI_ID sim_menus[] = {
                                                MENU_ID_SMS_SEND_OPT_BY_SIM1, 
                                                MENU_ID_SMS_SEND_OPT_BY_SIM2,
                                        #if (MMI_MAX_SIM_NUM >= 3)
                                                MENU_ID_SMS_SEND_OPT_BY_SIM3,
                                        #if (MMI_MAX_SIM_NUM >= 4)
                                                MENU_ID_SMS_SEND_OPT_BY_SIM4,
                                        #endif /* (MMI_MAX_SIM_NUM >= 4) */
                                        #endif /* (MMI_MAX_SIM_NUM >= 3) */
                                                    0
                                                };
                    
                        MMI_ID sim_strings[] = {
                                                STR_ID_SMS_BY_SIM1, 
                                                STR_ID_SMS_BY_SIM2,
                    #if (MMI_MAX_SIM_NUM >= 3)
                                                STR_ID_SMS_BY_SIM3,
                    #if (MMI_MAX_SIM_NUM >= 4)
                                                STR_ID_SMS_BY_SIM4,
                    #endif /* (MMI_MAX_SIM_NUM >= 4) */
                    #endif /* (MMI_MAX_SIM_NUM >= 3) */
                                                    0
                                                };
                        mmi_sms_append_sim_name_to_menu_items_and_hide_invalid_sims(menu_evt->sender_id, sim_menus, sim_strings);
                    }
                    #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
                }
            #ifndef __UNIFIED_COMPOSER_SUPPORT__
                else if(menu_evt->parent_menu_id == MENU_ID_SMS_RECIPIENT_OPT_SAVE_TO_DRAFTS)
                {
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                    MMI_ID sim_menus[] = {
                                            MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM1, 
                                            MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM2,
                #if (MMI_MAX_SIM_NUM >= 3)
                                            MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM3,
                #if (MMI_MAX_SIM_NUM >= 4)
                                            MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM4,
                #endif /* (MMI_MAX_SIM_NUM >= 4) */
                #endif /* (MMI_MAX_SIM_NUM >= 3) */
                                                0
                                            };
                
                    MMI_ID sim_strings[] = {
                                            STR_ID_SMS_TO_SIM1, 
                                            STR_ID_SMS_TO_SIM2,
                    #if (MMI_MAX_SIM_NUM >= 3)
                                            STR_ID_SMS_TO_SIM3,
                    #if (MMI_MAX_SIM_NUM >= 4)
                                            STR_ID_SMS_TO_SIM4,
                    #endif /* (MMI_MAX_SIM_NUM >= 4) */
                    #endif /* (MMI_MAX_SIM_NUM >= 3) */
                                                0
                                            };
                    mmi_sms_append_sim_name_to_menu_items_and_hide_invalid_sims(menu_evt->sender_id, sim_menus, sim_strings);
                #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
                }
            #endif /* __UNIFIED_COMPOSER_SUPPORT__ */
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

                cui_sms_add_recipient_select_hdlr(menu_evt);

            #if ((MMI_MAX_SIM_NUM == 2) || defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__))
                if ((MENU_ID_SMS_SEND_OPT_BY_SIM1 == menu_evt->highlighted_menu_id)  
                    ||(MENU_ID_SMS_SEND_OPT_BY_SIM2 == menu_evt->highlighted_menu_id) 
                #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                #if (MMI_MAX_SIM_NUM >= 3)
                    ||(MENU_ID_SMS_SEND_OPT_BY_SIM3 == menu_evt->highlighted_menu_id) 
                #endif /* 3 */
                #if (MMI_MAX_SIM_NUM >= 4)
                    ||(MENU_ID_SMS_SEND_OPT_BY_SIM4 == menu_evt->highlighted_menu_id)
                #endif /* 4 */
                #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
                    )
                {
                    if (send_hd->is_direct_send) /* must compiled with (MMI_MAX_SIM_NUM >= 2) */
                    {
                        cui_menu_close(menu_evt->sender_id);
                    }
                }
            #endif /* ((MMI_MAX_SIM_NUM == 2) || defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)) */
            }
            break;

    #if (MMI_MAX_SIM_NUM >= 3)
        /* SIM selector event */
        case EVT_ID_CUI_SIM_SEL_RESULT:
        {
            cui_sim_sel_result_event_struct* sim_sel_evt = NULL;
            sim_sel_evt = (cui_sim_sel_result_event_struct*)evt;
            cui_sim_sel_close(sim_sel_evt->sender_id);

            if (sim_sel_evt->result == CUI_SIM_SEL_OK)
            {
                cui_sms_recipient_opt_send_by_sim(sim_sel_evt->sim_id | MMI_GSM);
            }
        }
        break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
        }
        break;
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
        case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
        {
            srv_sim_ctrl_availability_changed_evt_struct * sim_evt =
                (srv_sim_ctrl_availability_changed_evt_struct *)evt;
            if (sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE
                || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE
                || sim_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED
                || sim_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
            {
                mmi_frm_group_close(send_hd->send_gid);
            }
             break;
        }
#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */
        default:
            break;
    }
 
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_send_run(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_send_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_enter(sms_send_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        cui_sms_pre_send_entry(sms_send_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_send_close(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_CLOSE_SEND_GROUP, sms_send_gid);

    mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_ADD_RECIPIENT);
    mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_SENDING);
    mmi_frm_group_close(sms_send_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void cui_sms_send_deinit_handle(cui_sms_send_handle_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_id sms_send_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_DEINIT_CUI_SEND_HANDLE, handle);

    MMI_ASSERT(handle != NULL);
    sms_send_gid = handle->send_gid;

    if(handle != NULL)
    {
        if (handle->srv_send_handle != NULL)
        {
            srv_sms_clear_send_callback(handle->srv_send_handle);
        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            if (handle->data->send_type == SRV_SMS_BG_SAVE_SEND)
            {
                srv_sms_set_mms(handle->srv_send_handle, MMI_FALSE);
            }
            else
        #endif
            {
                srv_sms_abort_send(handle->srv_send_handle);
            }
        }

        if(handle->data != NULL)
        {
            U8 *sending_caption_buff = handle->data->send_info.sending_caption_buff;
            if (sending_caption_buff != NULL)
            {
                OslMfree(sending_caption_buff);
                handle->data->send_info.sending_caption_buff = NULL;
            }

            if (handle->data->recipient[0] != NULL)
            {
                cui_sms_remove_all_recipient(handle->data);
                cui_sms_send_free_recipient_data(handle->data->recipient[0]);
                handle->data->recipient[0] = NULL;
            }

            if (handle->data->content_file_path != NULL)
            {
                OslMfree(handle->data->content_file_path);
                handle->data->content_file_path = NULL;
            }

            if (handle->data->send_fsm_info != NULL)
            {
                if ((handle->data->send_fsm_info->state == SEND_FSM_STATE_SAVE_FAIL_RSP)
                    ||(handle->data->send_fsm_info->state == SEND_FSM_STATE_SAVE_SUCC_RSP)
                    ||(handle->data->send_fsm_info->state == SEND_FSM_STATE_DEL_FAIL_RSP)
                    ||(handle->data->send_fsm_info->state == SEND_FSM_STATE_DEL_SUCC_RSP))
                {
                    invalid_send_handle = (void*)handle;
                }

                OslMfree(handle->data->send_fsm_info);
                handle->data->send_fsm_info = NULL;
            }

            if (handle->data->edit_num_info != NULL)
            {
                if (handle->data->edit_num_info->phone_number_buff != NULL)
                {
                    OslMfree(handle->data->edit_num_info->phone_number_buff);
                    handle->data->edit_num_info->phone_number_buff = NULL;
                }
                OslMfree(handle->data->edit_num_info);
                handle->data->edit_num_info = NULL;
            }

            OslMfree(handle->data);
            handle->data = NULL;
        }

        OslMfree(handle);
        handle = NULL;
    }

    for (i = 0; i< CUI_SMS_MAX_SEND_INSTANCE; i++)
    {
        if (cui_sms_send_instance[i] == sms_send_gid)
        {
            cui_sms_send_instance[i] = 0;
            send_instance_in_use--;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void cui_sms_pre_send_entry(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *send_hd;
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_ENTRY, sms_send_gid);

    send_hd = cui_sms_get_send_handle(sms_send_gid);
    hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    if (hd_data->recipient_info.pre_total_num > CUI_SMS_MAX_RECIPIENTS_NUM)
    {
    #ifdef __MMI_SMS_SLIM__
        cui_sms_recipient_exceeded_handle();
    #else
        cui_sms_entry_recipient_exceeded_confirm(sms_send_gid, CUI_SMS_MAX_RECIPIENTS_NUM, MMI_TRUE);
    #endif
    }
    else
    {
        /* Need to entry send? */
        MMI_BOOL is_entry = MMI_TRUE; 
        if (hd_data->recipient_info.invalid_num > 0)
        {
            /* if no valid recipient left, show invlid nubmer removed */
            MMI_ID string = STR_ID_SMS_INVLAID_NUMBERS_REMOVED; 
            if ((hd_data->total_num == 0) && (hd_data->recipient_info.invalid_num == 1))
            {
                /* if only one, show removed */
                string = STR_GLOBAL_INVALID_NUMBER;
            }
            /* If popup is not shown, need to entry sender directly */
            is_entry = (!cui_sms_display_popupcallback_sg(
                    sms_send_gid,
                    (WCHAR*)GetString(string),
                    MMI_EVENT_INFO,
                    cui_sms_pre_send_entry_popup_proc,
                    send_hd,
                    0));
        }
        if (is_entry)
        {
            cui_sms_send_entry(sms_send_gid);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void cui_sms_send_entry(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *send_hd = NULL;
    cui_sms_send_handle_data_struct *hd_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_hd = cui_sms_get_send_handle(sms_send_gid);

    cui_sms_set_active_send_gid(sms_send_gid);

    if (send_hd != NULL)
    {
        hd_data = send_hd->data;

        if (hd_data->recipient_info.pre_total_num <= CUI_SMS_MAX_RECIPIENTS_NUM)
        {
            if ((hd_data->total_num == 0)
                || ((send_hd->hiden_scrn & CUI_SMS_SEND_ADD_RECIPIENT_SCR) != CUI_SMS_SEND_ADD_RECIPIENT_SCR))
            {
                cui_sms_pre_entry_add_recipient();
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else
            {
                cui_sms_dm_pre_send_msg();
            }
        #else
            else
            {
                cui_sms_pre_send_msg();
            }
        #endif
        }
        else
        {
            cui_sms_send_evt_send_to_parent(sms_send_gid, MMI_TRUE, CUI_SMS_RESULT_GROUP_GOBACK);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret cui_sms_pre_send_entry_popup_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*)param;
    cui_sms_send_handle_struct *send_hd = (cui_sms_send_handle_struct*) alert_result->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(EVT_ID_POPUP_QUIT == param->evt_id)
    {
        if (send_hd != NULL)
        {
        	cui_sms_send_entry(cui_sms_get_active_send_gid());
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_unhide_add_recipient_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_unhide_add_recipient_scrn(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_UNHIDE_ADD_RECIPIENT_SCREEN, sms_gid);
    if (sms_gid != GRP_ID_INVALID)
    {
        handle = cui_sms_get_send_handle(sms_gid);

        handle->hiden_scrn &= 0xFE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_unhide_save_menu
 * DESCRIPTION
 *  SMS internal use
 * PARAMETERS
 *  sms_gid       [IN]               
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_set_send_unhide_save_menu(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_UNHIDE_SAVE_MENU, sms_gid);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->recipient_info.is_hide_save_menu = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_data
 * DESCRIPTION
 *  8bit
 * PARAMETERS
 *  void
 * RETURNS
 *  
 ****************************************************************************/
void cui_sms_set_send_content_data(mmi_id sms_gid, S8 *content_buff, U16 content_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_DATA, sms_gid);
    
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_DCS;

        hd_data->para_flag |= SRV_SMS_PARA_CONTENT_BUFF;

        hd_data->dcs = SRV_SMS_DCS_8BIT;
        hd_data->content_buff = content_buff;
        hd_data->content_buff_size = content_size;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_data_file
 * DESCRIPTION
 *  file path DCS is UCS2,content must be 8bit characters
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_content_data_file(mmi_id sms_gid, U16 *content_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;
    S32 file_path_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_DATA_FILE, sms_gid);
    
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_DCS;
        hd_data->para_flag |= SRV_SMS_PARA_CONTENT_FILE;
        hd_data->dcs = SRV_SMS_DCS_8BIT;

        file_path_len = mmi_ucs2strlen((S8*)content_file_path);

        if (file_path_len > SRV_FMGR_PATH_MAX_LEN)
        {
            file_path_len = SRV_FMGR_PATH_MAX_LEN;
        }

        hd_data->content_file_path = OslMalloc((file_path_len +1) *ENCODING_LENGTH);

        mmi_ucs2ncpy((S8*)hd_data->content_file_path, (S8*) content_file_path, (U32)file_path_len);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_append_recipient
 * DESCRIPTION
 *  Append Recipient to the Recipient List
 * PARAMETERS
 *  ucs2_addr       [IN]    UCS2 Address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL cui_sms_add_recipient(mmi_id sms_send_gid, S8 *ucs2_addr)
{
    return cui_sms_append_recipient(sms_send_gid, ucs2_addr);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_address
 * DESCRIPTION
 *  CUI for send and save
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_address(mmi_id sms_gid, U16 **ucs2_addr_list, U16 addr_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_ADDE_LIST, sms_gid, addr_count);

    if (sms_gid != GRP_ID_INVALID)
    {
        if ((ucs2_addr_list != NULL) && (addr_count > 0))
        {
            for (i = 0; i < addr_count; i++)
            {
                WCHAR temp_ucs2[CUI_SMS_MAX_ADDR_LEN + 1] = {0};
                S8 *ucs2_addr = ((S8*)ucs2_addr_list + (CUI_SMS_MAX_ADDR_LEN +1) *ENCODING_LENGTH *i);
                mmi_ucs2ncpy((CHAR *)temp_ucs2, (const CHAR*)ucs2_addr, CUI_SMS_MAX_ADDR_LEN);
                cui_sms_set_send_each_address(sms_gid, (U16 *)temp_ucs2);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_each_address
 * DESCRIPTION
 *  CUI for send
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_each_address(mmi_id sms_gid, U16 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_ADDE_LIST, sms_gid, hd_data->total_num);

    if (sms_gid != GRP_ID_INVALID)
    {
     #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (hd_data->pid == SRV_SMS_PID_EMAIL)
        {
            if ((MMI_BOOL)applib_is_valid_email_address_unicode((kal_wchar*)ucs2_addr) == MMI_FALSE)
            {
                hd_data->recipient_info.invalid_num++;
            }
            else
            {
                cui_sms_add_recipient(sms_gid, (S8*)ucs2_addr);
            }
        }
        else
     #endif /* */
        {
            if ((srv_sms_check_ucs2_number((S8*)ucs2_addr) == MMI_FALSE) || 
                (cui_sms_add_recipient(sms_gid, (S8*)ucs2_addr) == MMI_FALSE))
            {
                hd_data->recipient_info.invalid_num++;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_send_address
 * DESCRIPTION
 *  Get send recipeint number list, caller need molloc buffer for ucs2_addr_list, SMS CUI only
 *  add number to this list.
 * PARAMETERS
 *  ucs2_addr_list      [IN/OUT]        U16 ucs2_addr_list[CUI_SMS_MAX_RECIPIENTS_NUM][CUI_SMS_MAX_ADDR_LEN + 1];
 *  addr_count          [IN/OUT]        addess count, U16 *addr_count
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_get_send_address(mmi_id sms_gid, U16 **ucs2_addr_list, U16 *addr_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    cui_sms_send_handle_data_struct *hd_data;
    S8 *list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        *addr_count = hd_data->total_num;
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_SEND_ADDE_LIST, sms_gid, addr_count);

        for (i = 0; i< hd_data->total_num; i++)
        {
            U16 length;
            list = ((S8*)ucs2_addr_list + (CUI_SMS_MAX_ADDR_LEN +1) *ENCODING_LENGTH *i);
            length = mmi_asc_n_to_ucs2(list, (S8*)hd_data->recipient[i], CUI_SMS_MAX_ADDR_LEN);
            memset(&list[length], 0, ENCODING_LENGTH);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_text
 * DESCRIPTION
 *  CUI for send and save, content buffer DCS is ucs2
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_content_text(mmi_id sms_gid, U16 *content_buff, U16 content_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_CONTENT_TEXT, sms_gid);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_DCS;
        hd_data->dcs = SRV_SMS_DCS_7BIT;

        hd_data->para_flag |= SRV_SMS_PARA_CONTENT_BUFF;

        hd_data->content_buff = (S8*)content_buff;
        hd_data->content_buff_size = content_size;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_text_file
 * DESCRIPTION
 *  CUI for send and save,content_file_path dcs is UCS2, file content is ucs2 characters
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_content_text_file(mmi_id sms_gid, U16 *content_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;
    S32 file_path_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_CONTENT_TEXT_FILE, sms_gid);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_DCS;
        hd_data->para_flag |= SRV_SMS_PARA_CONTENT_FILE;

        hd_data->dcs = SRV_SMS_DCS_UCS2;

        file_path_len = mmi_ucs2strlen((S8*)content_file_path);

        if (file_path_len > SRV_FMGR_PATH_MAX_LEN)
        {
            file_path_len = SRV_FMGR_PATH_MAX_LEN;
        }

        hd_data->content_file_path = OslMalloc((file_path_len +1) *ENCODING_LENGTH);

        mmi_ucs2ncpy((S8*)hd_data->content_file_path, (S8*) content_file_path, (U32)file_path_len);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_ems
 * DESCRIPTION
 *  CUI for send and save
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_content_ems(mmi_id sms_gid, void *content_ems)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_CONTENT_EMS, sms_gid);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);
        
        hd_data->para_flag |= SRV_SMS_PARA_CONTENT_EMS;
        hd_data->content_ems = content_ems;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_sim_id
 * DESCRIPTION
 *  CUI for send and save
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_sim_id(mmi_id sms_gid, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_SIM_ID, sms_gid, sim_id);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_SIM_ID;
        hd_data->sim_id = sim_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_msg_id
 * DESCRIPTION
 *  CUI for send
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_msg_id(mmi_id sms_gid, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_MSG_ID, sms_gid, msg_id);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->send_info.msg_index = msg_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_status_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_status_report(mmi_id sms_gid, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_STATUS_REPORT, sms_gid, is_set);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->spec_para |= SRV_SMS_SPEC_SEND_STATUS_REPORT;
        hd_data->para_flag |= SRV_SMS_PARA_STATUS_REPORT;
        hd_data->status_report = is_set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_sc_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_sc_address(mmi_id sms_gid, U16 *sc_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_SC_ADDR, sms_gid);
    if (sms_gid != GRP_ID_INVALID)
    {
        U16 addr_len;
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->spec_para |= SRV_SMS_SPEC_SEND_SCA;
        hd_data->para_flag |= SRV_SMS_PARA_SCA;
        addr_len = mmi_ucs2_n_to_asc(hd_data->sc_address, (S8*)sc_addr, CUI_SMS_MAX_ADDR_LEN * ENCODING_LENGTH);
        hd_data->sc_address[addr_len] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_vp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_vp(mmi_id sms_gid, srv_sms_vp_enum vp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_VP, sms_gid, vp);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->spec_para |= SRV_SMS_SPEC_SEND_VP;
        hd_data->para_flag |= SRV_SMS_PARA_VP;
        hd_data->vp = vp;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_text_dcs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_content_text_dcs(mmi_id sms_gid, srv_sms_dcs_enum dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_DCS;
        hd_data->dcs = dcs;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_sending_string_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_sending_string_id(mmi_id sms_gid, U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->sending_str_id = string_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_pid(mmi_id sms_gid, srv_sms_pid_enum pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_PID, sms_gid, pid);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->spec_para |= SRV_SMS_SPEC_SEND_PID;
        hd_data->para_flag |= SRV_SMS_PARA_PID;
        hd_data->pid = pid;

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        hd_data->recipient_info.addr_type = CUI_SMS_ADDR_TYPE_NUMBER;
        if (SRV_SMS_PID_EMAIL == pid)
        {
            hd_data->recipient_info.addr_type = CUI_SMS_ADDR_TYPE_EMAIL_ADDR;
        }
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_class_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_class_type(mmi_id sms_gid, srv_sms_class_enum class_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_CLASS_TYPE, sms_gid, class_type);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_CLASS;
        hd_data->class_type = class_type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_reply_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_reply_path(mmi_id sms_gid, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_REPLY_PATH, sms_gid, is_set);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->spec_para |= SRV_SMS_SPEC_SEND_REPLY_PATH;
        hd_data->para_flag |= SRV_SMS_PARA_REPLY_PATH;
        hd_data->reply_path = is_set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_data_port
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_data_port(mmi_id sms_gid, U16 src_port, U16 dest_port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_DATA_PORT, sms_gid);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_PORT;
        hd_data->src_port = src_port;
        hd_data->dest_port = dest_port;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_reply_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_reply_msg_id(mmi_id sms_gid, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_REPLY_MSG_ID, sms_gid, msg_id);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->reply_msg_id= msg_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_type
 * DESCRIPTION
 *  Only for send
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_type(mmi_id sms_gid, srv_sms_send_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_TYPE, sms_gid, type);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

    #ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        if (type == SRV_SMS_BG_SEND)
        {
            type = SRV_SMS_FG_SEND;
        }
    #endif

        hd_data->send_type = type;
    }
}



/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_mms
 * DESCRIPTION
 *  Only for send
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_mms(mmi_id sms_gid, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_MMS, sms_gid);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->is_mms = is_set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_msg_case
 * DESCRIPTION
 *  Only for send
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_send_msg_case(mmi_id sms_gid, cui_sms_send_case_enum send_msg_case)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SEND_MSG_CASE, sms_gid, send_msg_case);
    if (sms_gid != GRP_ID_INVALID)
    {
        handle = cui_sms_get_send_handle(sms_gid);

        handle->send_msg_case = send_msg_case;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_not_allow_empty_sc
 * DESCRIPTION
 *  Only for send
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_not_allow_empty_sc(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_NOT_ALLOW_EMPTY_SC, sms_gid);
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_send_handle_data(sms_gid);

        hd_data->is_allow_sc_emtpy = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_abort_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void cui_sms_abort_send_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ABORT_SEND_MSG, sms_send_gid);

    cui_sms_abort_send(sms_send_gid, CUI_SMS_ABORT_WITH_FINISH_IND);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_abort_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_abort_send(mmi_id sms_gid, cui_sms_abort_send_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *cui_send_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_send_handle = cui_sms_get_send_handle(sms_gid);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ABORT_SEND, sms_gid, type);

    cui_send_handle->data->send_info.is_aborting = MMI_TRUE;

    if (cui_send_handle->data->send_info.is_sending == MMI_TRUE)
    {
        cui_sms_entry_abort_sending();
    }

    if (cui_send_handle->srv_send_handle)
    {
        srv_sms_abort_send(cui_send_handle->srv_send_handle);

        if (type == CUI_SMS_ABORT_WITHOUT_FINISH_IND)
        {
            srv_sms_clear_send_callback(cui_send_handle->srv_send_handle);

            cui_sms_send_evt_send_to_parent(sms_gid, MMI_TRUE, CUI_SMS_RESULT_CANCEL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_is_send_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL cui_sms_is_send_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = (MMI_BOOL)srv_sms_is_sms_valid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_IS_SEND_ENABLE, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_pre_entry_add_recipient
 * DESCRIPTION
 *  Pre-Entry Add Recipient Screen Function
 * PARAMETERS
 *  is_external     [IN] Is from other application (TRUE) or SMS application (FALSE)
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_pre_entry_add_recipient(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();
    hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_PRE_ENTRY_ADD_RECIPIENT);

    hd_data->recipient_info.is_modify = MMI_FALSE;

#ifndef __MMI_UNIFIED_COMPOSER__ 
#ifdef __EMS_DYNAMIC_SEG_NUM__
    {
        EMSData *edit_ems_data;

        if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) == SRV_SMS_PARA_CONTENT_EMS)
        {  
             edit_ems_data = hd_data->content_ems;
        }
        else
        {
            MMI_BOOL result;
            cui_sms_send_handle_struct *handle;

            edit_ems_data = (EMSData*)srv_sms_malloc_ems_data();

            if (edit_ems_data == NULL)
            {
                MMI_ASSERT(0);
            }
            
            handle = cui_sms_get_send_handle(sms_send_gid);
            result = cui_sms_convert_send_content_to_emsdata(handle, edit_ems_data);

            if (result == MMI_FALSE)
            {
                if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) != SRV_SMS_PARA_CONTENT_EMS)
                {
                    if (edit_ems_data != NULL)
                    {
                        srv_sms_free_ems_data((void*)edit_ems_data);
                    }
                }
                return;
            }
        }

        if (srv_sms_set_cur_segment(edit_ems_data, hd_data->sim_id) != EMS_OK)
        {
            popup_result = CUI_SMS_RESULT_DATA_EXCEED;

            if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) != SRV_SMS_PARA_CONTENT_EMS)
            {
                if (edit_ems_data != NULL)
                {
                    srv_sms_free_ems_data((void*)edit_ems_data);
                }
            }

            cui_sms_display_popupcallback_sg_ext(
                sms_send_gid,
                STR_SMS_FAILURE_DATA_EXCEED,
                MMI_EVENT_FAILURE,
                cui_sms_entry_cur_send_scrn_fail_proc,
                NULL,
                0);

            return;
        }

        if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) != SRV_SMS_PARA_CONTENT_EMS)
        {
            if (edit_ems_data != NULL)
            {
                srv_sms_free_ems_data((void*)edit_ems_data);
            }
        }
    }
#endif /* __EMS_DYNAMIC_SEG_NUM__ */ 

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (hd_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
    {
        U16 remaining_len;
        EMSData *edit_ems_data;
        MMI_BOOL is_enough_space = MMI_TRUE;

        if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) == SRV_SMS_PARA_CONTENT_EMS)
        {  
             edit_ems_data = hd_data->content_ems;
        }
        else
        {
            MMI_BOOL result;
            cui_sms_send_handle_struct *handle;

            edit_ems_data = (EMSData*)srv_sms_malloc_ems_data();

            MMI_ASSERT(edit_ems_data != NULL);
            
            handle = cui_sms_get_send_handle(sms_send_gid);
            result = cui_sms_convert_send_content_to_emsdata(handle, edit_ems_data);

            if (result == MMI_FALSE)
            {
                if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) != SRV_SMS_PARA_CONTENT_EMS)
                {
                    if (edit_ems_data != NULL)
                    {
                        srv_sms_free_ems_data((void*)edit_ems_data);
                    }
                }
                return;
            }
        }

        remaining_len = cui_sms_get_ems_remaining_length(edit_ems_data);

        if (remaining_len <= 3)
        {
            is_enough_space = MMI_FALSE;
        }
        else
        {
            U16 i;

            for (i = 0; i < hd_data->total_num; i++)
            {
                if ((U16)strlen(hd_data->recipient[i]) > (remaining_len - 1))
                {
                    is_enough_space = MMI_FALSE;
                }
            }
        }

        if (is_enough_space == MMI_FALSE)
        {
            popup_result = CUI_SMS_RESULT_EMAIL_NO_SPACE;

            if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) != SRV_SMS_PARA_CONTENT_EMS)
            {
                if (edit_ems_data != NULL)
                {
                    srv_sms_free_ems_data((void*)edit_ems_data);
                }
            }

            cui_sms_display_popupcallback_sg_ext(
                sms_send_gid,
                STR_SMS_EMAIL_NO_SPACE,
                MMI_EVENT_FAILURE,
                cui_sms_entry_cur_send_scrn_fail_proc,
                NULL,
                0);

            return;
        }
        else
        {
            /* the format of a SMS email is as [Email Address][SP][Content],
             * so we need a more remaining SPACE character
             */
            if ((remaining_len - 1) < CUI_SMS_MAX_ADDR_LEN)
            {
                hd_data->recipient_info.max_email_addr_len = remaining_len - 1;
            }
            else
            {
                hd_data->recipient_info.max_email_addr_len = CUI_SMS_MAX_ADDR_LEN;
            }
        }

        if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) != SRV_SMS_PARA_CONTENT_EMS)
        {
            if (edit_ems_data != NULL)
            {
                srv_sms_free_ems_data((void*)edit_ems_data);
            }
        }
    }
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#endif /* __MMI_UNIFIED_COMPOSER__ */

    //cui_sms_set_current_send_gid(sms_send_gid);
    mmi_frm_scrn_first_enter(sms_send_gid, SCR_ID_SMS_ADD_RECIPIENT, (FuncPtr)cui_sms_entry_add_recipient, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_add_recipient
 * DESCRIPTION
 *  Entry Add Recipient Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_add_recipient(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem;
    S32 numitem;
    mmi_id sms_send_gid;
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = scrn_data->group_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTRY_ADD_RECIPIENT, sms_send_gid);

    if (mmi_frm_scrn_enter(
            scrn_data->group_id,
            SCR_ID_SMS_ADD_RECIPIENT,
            NULL,
            (FuncPtr)cui_sms_entry_add_recipient,
            MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(sms_send_gid, SCR_ID_SMS_ADD_RECIPIENT);

        hd_data = cui_sms_get_send_handle_data(sms_send_gid);

        if (hd_data->total_num == 0)
        {
            numitem = DEFAULT_LIST_ITEM_NUM;
        }
        else
        {
            numitem = hd_data->total_num + ITEM_NUM_ABOVE_LINE;
        }

        if (guiBuffer == NULL)
        {
            if (hd_data->total_num == 0)
            {
                hiliteitem = DEFAULT_HILITE_WITHOUT_RECIPIENT;
            }
            else
            {
                hiliteitem = DEFAULT_HILITE_WITH_RECIPIENT;
            }
        }
        else
        {
            list_menu_category_history *h = (list_menu_category_history*)guiBuffer;

            hiliteitem = hd_data->recipient_info.highlihgt_index;

            h->highlighted_item = hiliteitem;
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTRY_ADD_RECIPIENT_1, numitem, hiliteitem);

        RegisterHighlightHandler(cui_sms_recipient_highlight_hdlr);
        wgui_fixed_list_register_get_flags_handler(cui_sms_recipient_set_separator_line);

        EnableCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);

    wgui_cat1032_show(
        (WCHAR *)GetString(STR_ID_SMS_ADD_RECIPIENT),
        (PU8)GetImage(IMG_SMS_ENTRY_SCRN_CAPTION),
        (WCHAR *)GetString(STR_GLOBAL_OK),
        (PU8)GetImage(IMG_GLOBAL_OK),
        (WCHAR *)GetString(STR_GLOBAL_BACK),
        (PU8)GetImage(IMG_GLOBAL_BACK),
        numitem,
        cui_sms_recipient_get_item,
        NULL,
        hiliteitem,
        0,    
        IMG_STORAGE_HANDSET,
        0,
        guiBuffer,
        NULL);
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
#endif
        SetRightSoftkeyFunction(cui_sms_goback_from_cur_send_proc, KEY_EVENT_UP);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_list_tap_callback(mmi_sms_fte_add_recipient_tap_callback);
    #endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)    */
    }
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_fte_add_recipient_tap_callback
 * DESCRIPTION
 *  Set intuitive command function for Add recipient Screen
 * PARAMETERS
 *  tap_type: [IN]   The current tap menu status highlight or not
 *  index   : [IN]   The tap menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_fte_add_recipient_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    switch(index)
    {
        case ENTER_NUMBER_INDEX:
            cui_sms_recipient_enter_number();
            break;
        case ADD_FROM_CONTACTS_INDEX:
            cui_sms_recipient_add_from_contacts();
            break;

        default:
            if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
            {
                cui_sms_recipient_opt_edit();
            }
            break;
    }

}
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)*/


/*****************************************************************************
 * FUNCTION
 *  cui_sms_goback_from_cur_send_proc
 * DESCRIPTION
 *  The sendind screen delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static void cui_sms_goback_from_cur_send_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GOBACK_FROM_CUR_SEND_SCRN, sms_send_gid);

    if ((mmi_frm_scrn_get_active_id() == SCR_ID_SMS_ADD_RECIPIENT)
        ||!(mmi_frm_scrn_is_present(sms_send_gid, SCR_ID_SMS_ADD_RECIPIENT, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG)))
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GOBACK_FROM_CUR_SEND_SCRN_1);
        cui_sms_pre_send_evt_send_to_parent(sms_send_gid, MMI_TRUE, CUI_SMS_RESULT_GROUP_GOBACK);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GOBACK_FROM_CUR_SEND_SCRN_2);
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_popup_goback_from_edit_sc_proc
 * DESCRIPTION
 *  The sendind screen delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret cui_sms_popup_goback_from_edit_sc_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            mmi_id sms_send_gid = cui_sms_get_active_send_gid();

            if (!(mmi_frm_scrn_is_present(sms_send_gid, SCR_ID_SMS_ADD_RECIPIENT, MMI_FRM_NODE_ALL_FLAG)))
            {
                cui_sms_pre_send_evt_send_to_parent(sms_send_gid, MMI_TRUE, CUI_SMS_RESULT_GROUP_GOBACK);
            }
            else
            {
                mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_SC_NUMBER);
                mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_EMAIL_SC_NUMBER);
            }
            break;
        }
        default:
    	break;	
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_cur_send_scrn_fail_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret cui_sms_entry_cur_send_scrn_fail_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTRY_CUR_SEND_SCRN_FAIL, sms_send_gid, popup_result);

    if(EVT_ID_POPUP_QUIT == param->evt_id)
    {
        if (!(mmi_frm_scrn_is_present(sms_send_gid, SCR_ID_SMS_ADD_RECIPIENT, MMI_FRM_NODE_ALL_FLAG)))
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTRY_CUR_SEND_SCRN_FAIL_1);
            cui_sms_pre_send_evt_send_to_parent(sms_send_gid, MMI_TRUE, popup_result);
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_is_scrn_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static MMI_BOOL cui_sms_send_is_scrn_present(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(sms_gid, SCR_ID_SMS_ADD_RECIPIENT, MMI_FRM_NODE_ALL_FLAG)
        || mmi_frm_scrn_is_present(sms_gid, SCR_ID_SMS_ENTER_NUMBER, MMI_FRM_NODE_ALL_FLAG)
        || mmi_frm_scrn_is_present(sms_gid, SCR_ID_SMS_SC_NUMBER, MMI_FRM_NODE_ALL_FLAG)
        || mmi_frm_scrn_is_present(sms_gid, SCR_ID_SMS_EMAIL_SC_NUMBER, MMI_FRM_NODE_ALL_FLAG)
        || mmi_frm_scrn_is_present(sms_gid, SCR_ID_SMS_EDIT_RECIPIENT, MMI_FRM_NODE_ALL_FLAG)
        || mmi_frm_scrn_is_present(sms_gid, SCR_ID_SMS_SENDING, MMI_FRM_NODE_ALL_FLAG)
        || mmi_frm_scrn_is_present(sms_gid, SCR_ID_SMS_ABORT_SENDING, MMI_FRM_NODE_ALL_FLAG)
        )
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
 *  cui_sms_recipient_set_separator_line
 * DESCRIPTION
 *  Set the separator line in the add recipient screen
 * PARAMETERS
 *  index       [IN]    The list item index
 *  flag        [OUT]   UI Menu Item Flag
 *  flag_ex     [OUT]   UI Menu Item Extension Flag
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL cui_sms_recipient_set_separator_line(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < ITEM_NUM_ABOVE_LINE)
    {
        *flag |= UI_MENUITEM_DISABLE_ICON;
    }
    if (index == ADD_FROM_CONTACTS_INDEX)
    {
        *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE;
    }
    if ((index == ITEM_NUM_ABOVE_LINE))
    {
        if (hd_data->total_num == 0)
        {
            *flag |= UI_MENUITEM_DISABLE_ICON;
            *flag |= UI_MENUITEM_STATE_DISABLED;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_highlight_hdlr
 * DESCRIPTION
 *  List Item Highlight Handler Function of The Add Recipient Screen 
 * PARAMETERS
 *  index       [IN]    The highlihgt item index
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);
    hd_data->recipient_info.highlihgt_index = index;

    switch (index)
    {
        case ENTER_NUMBER_INDEX:
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(cui_sms_recipient_enter_number, KEY_EVENT_UP);
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
            SetLeftSoftkeyFunction(cui_sms_recipient_enter_number, KEY_EVENT_UP);
        	SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_DOWN);
            break;
        }

        case ADD_FROM_CONTACTS_INDEX:
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(cui_sms_recipient_add_from_contacts, KEY_EVENT_UP);
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_SMS_COMMON_NOIMAGE);
            SetLeftSoftkeyFunction(cui_sms_recipient_add_from_contacts, KEY_EVENT_UP);
        	SetKeyHandler(NULL, KEY_SEND, KEY_EVENT_DOWN);
            break;
        }

        default:
        {
            ChangeCenterSoftkey(0, IMG_GLOBAL_SEND_MSG_CSK);
        #if (MMI_MAX_SIM_NUM >= 3)
	        SetCenterSoftkeyFunction(cui_sms_use_sim_selector, KEY_EVENT_UP);
	    #elif (MMI_MAX_SIM_NUM == 2)
            SetCenterSoftkeyFunction(cui_sms_dm_pre_send_msg, KEY_EVENT_UP);
        #else 
            SetCenterSoftkeyFunction(cui_sms_pre_send_msg, KEY_EVENT_UP);
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_SMS_COMMON_NOIMAGE);
            SetLeftSoftkeyFunction(cui_sms_entry_add_recipient_options, KEY_EVENT_UP);
        #ifdef __MMI_DUAL_SIM_MASTER__
        	SetKeyHandler(cui_sms_dm_pre_send_msg, KEY_SEND, KEY_EVENT_DOWN);
        #else /* __MMI_DUAL_SIM_MASTER__ */
        	SetKeyHandler(cui_sms_pre_send_msg, KEY_SEND, KEY_EVENT_DOWN);
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_enter_number
 * DESCRIPTION
 *  "Enter number" item LSK Handler Funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_enter_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    U16 title_id;
    U16 max_addr_len;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_ENTER_NUMBER, sms_send_gid);

    if (hd_data->total_num == MMI_SMS_MAX_RECIPIENTS_NUM)
    {
        mmi_popup_display_simple_ext(
            STR_ID_SMS_RECIPIENTS_FULL,
            MMI_EVENT_FAILURE,
            sms_send_gid,
            NULL);
    }
    else
    {
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (hd_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_NUMBER)
        {
            title_id = STR_ID_SMS_ENTER_NUMBER;
            max_addr_len = CUI_SMS_MAX_NUM_LEN;
        }
        else
        {
            title_id = STR_ID_SMS_ENTER_EMAIL_ADDRESS;
            max_addr_len = hd_data->recipient_info.max_email_addr_len;
        }

        cui_sms_entry_phone_number_generic(
            SCR_ID_SMS_ENTER_NUMBER,
            title_id,
            hd_data->recipient_info.addr_type,
            NULL,
            max_addr_len,
            cui_sms_recipient_enter_number_done,
            MMI_FALSE);
    #else /* __MMI_MESSAGES_SMS_EMAIL__ */
        cui_sms_entry_phone_number_generic(
            SCR_ID_SMS_ENTER_NUMBER,
            STR_ID_SMS_ENTER_NUMBER,
            CUI_SMS_ADDR_TYPE_NUMBER,
            NULL,
            CUI_SMS_MAX_NUM_LEN,
            cui_sms_recipient_enter_number_done,
            MMI_FALSE);
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_phone_number_generic
 * DESCRIPTION
 *  Entry Phone Number/Address Full Edit screen Generic Function
 * PARAMETERS
 *  screen_id           [IN]    Screen ID
 *  tilte_id            [IN]    Title String ID
 *  addr_type           [IN]    Address Type (SMS Phone Number / Email Address)
 *  ucs2_addr           [IN]    The original Address
 *  done_func           [IN]    Edit Finish Callback Function
 *  is_search_phonebook [IN]    Whether Allow to search Phonebook Or Not
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_phone_number_generic(
            U16 screen_id,
            U16 tilte_id,
            cui_sms_address_type_enum addr_type,
            S8 *ucs2_addr,
            U16 max_addr_len,
            SmsFullEditFuncPtr done_func,
            MMI_BOOL is_search_phonebook)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_edit_phone_number_struct *edit_num_info = OslMalloc(sizeof(cui_sms_edit_phone_number_struct));
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);
    hd_data->edit_num_info = edit_num_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTER_PHONE_NUMBER_GENERIC, sms_send_gid);

    edit_num_info->editor_gid = GRP_ID_INVALID;
    edit_num_info->phone_number_title_id = tilte_id;
    edit_num_info->phone_number_done_func = done_func;
    edit_num_info->phone_number_search_flag = is_search_phonebook;
    edit_num_info->phone_number_addr_type = addr_type;
    edit_num_info->phone_number_max_addr_len = max_addr_len;
    edit_num_info->is_refresh_scrn = MMI_FALSE;

    edit_num_info->phone_number_buff = OslMalloc((edit_num_info->phone_number_max_addr_len + 1) * ENCODING_LENGTH);

    mmi_ucs2cpy(edit_num_info->phone_number_buff, ucs2_addr);

    cui_sms_send_edit_phone_number();
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_edit_phone_number
 * DESCRIPTION
 *  Entry Phone Number/Address Full Edit Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_send_edit_phone_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_struct *handle = cui_sms_get_send_handle(sms_send_gid);
    cui_sms_edit_phone_number_struct *edit_num_info = cui_sms_get_edit_number_info(sms_send_gid);
    MMI_ID editor_gid = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_gid = edit_num_info->editor_gid = cui_fseditor_create(sms_send_gid);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTER_PHONE_NUMBER, sms_send_gid);

    if (editor_gid != GRP_ID_INVALID)
    {
        U32 input_type = IMM_INPUT_TYPE_SIM_NUMERIC | INPUT_TYPE_PLUS_CHARACTER_HANDLING;
        U32 max_char_num = edit_num_info->phone_number_max_addr_len;

        cui_fseditor_set_title(editor_gid, edit_num_info->phone_number_title_id, IMG_SMS_ENTRY_SCRN_CAPTION);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (edit_num_info->phone_number_addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
        {
            input_type = IMM_INPUT_TYPE_EMAIL;
            max_char_num = edit_num_info->phone_number_max_addr_len + 1;
        }
#endif /*  __MMI_MESSAGES_SMS_EMAIL__*/

        cui_fseditor_set_text(editor_gid, (WCHAR*)edit_num_info->phone_number_buff, max_char_num * ENCODING_LENGTH, max_char_num - 1);
        cui_fseditor_set_input_method(editor_gid, input_type, NULL, 0);
        {
            MMI_ID lsk_string = STR_GLOBAL_OK;
            if ((mmi_ucs2strlen(edit_num_info->phone_number_buff) == 0) && (edit_num_info->phone_number_search_flag == MMI_TRUE))
            {
                lsk_string = STR_GLOBAL_SEARCH;
            }
            cui_fseditor_set_softkey_text(editor_gid, MMI_LEFT_SOFTKEY, lsk_string);
            cui_fseditor_set_softkey_icon(editor_gid, MMI_LEFT_SOFTKEY, IMG_SMS_COMMON_NOIMAGE);
            cui_fseditor_run(editor_gid);
        }
    }
    else
    {
        cui_sms_entry_phone_number_leave_proc(handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_phone_number_leave_proc
 * DESCRIPTION
 *  Phone Number Editor Screen Delete Callback Function
 * PARAMETERS
 *  dummy   [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
static void cui_sms_entry_phone_number_leave_proc(cui_sms_send_handle_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *data = handle->data;
    cui_sms_edit_phone_number_struct *edit_num_info = data->edit_num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTER_PHONE_NUMBER_LEAVE_PROC, handle->send_gid);

    if (edit_num_info != NULL)
    {
        if (edit_num_info->phone_number_buff != NULL)
        {
            OslMfree(edit_num_info->phone_number_buff);
            edit_num_info->phone_number_buff = NULL;
        }
        OslMfree(data->edit_num_info);
        data->edit_num_info = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_phone_number_empty_handle
 * DESCRIPTION
 *  Phone Number Editor Empty LSK Hanlder Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_phone_number_empty_handle(cui_sms_send_handle_struct *handle, MMI_BOOL is_empty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_edit_phone_number_struct *edit_num_info = handle->data->edit_num_info;
    if (NULL != edit_num_info)
    {
        MMI_ID editor_gid = edit_num_info->editor_gid;
        MMI_ID lsk_string = STR_GLOBAL_OK;
        MMI_ID csk_img = IMG_GLOBAL_COMMON_CSK;
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        MMI_ASSERT(edit_num_info != NULL);

        if (is_empty)
        {
            if (edit_num_info->phone_number_search_flag == MMI_TRUE)
            {
                lsk_string = STR_GLOBAL_SEARCH;
            }
            else
            {
                lsk_string = 0;
            }
            csk_img = IMG_SMS_COMMON_NOIMAGE;
        }
        cui_fseditor_set_softkey_text(editor_gid, MMI_LEFT_SOFTKEY, lsk_string);
        cui_fseditor_set_softkey_icon(editor_gid, MMI_LEFT_SOFTKEY, IMG_SMS_COMMON_NOIMAGE);
        cui_fseditor_set_softkey_icon(editor_gid, MMI_CENTER_SOFTKEY, csk_img);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_phone_number_done
 * DESCRIPTION
 *  Edit Finish Hanlde Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_phone_number_done(cui_sms_send_handle_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = handle->send_gid;
    cui_sms_edit_phone_number_struct *edit_num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_PHONE_NUMBER_DONE, sms_send_gid);

    edit_num_info = cui_sms_get_edit_number_info(sms_send_gid);

    MMI_ASSERT(edit_num_info != NULL);

    if (cui_sms_is_valid_address(edit_num_info->phone_number_buff, edit_num_info->phone_number_addr_type) == MMI_FALSE)
    {
        U16 string_id = STR_GLOBAL_INVALID_NUMBER;

#ifdef __MMI_MESSAGES_SMS_EMAIL__
        switch (edit_num_info->phone_number_addr_type)
        {
            case CUI_SMS_ADDR_TYPE_EMAIL_ADDR:
                string_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
                break;
            default:
                string_id = STR_GLOBAL_INVALID_NUMBER;
                break;
        }
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        mmi_popup_display_simple_ext(
            string_id,
            MMI_EVENT_FAILURE,
            sms_send_gid,
            NULL);
    }
    else
    {
        edit_num_info->phone_number_done_func(edit_num_info->phone_number_buff);
    }
}


#ifndef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_search_phonebook
 * DESCRIPTION
 *  Entry Phonebook List to Search Address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_search_phonebook(cui_sms_send_handle_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filter_type = SRV_PHB_ENTRY_FIELD_GSM_NUM;
    mmi_id sms_send_gid = handle->send_gid;
    cui_sms_edit_phone_number_struct *edit_num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEARCH_PHB, sms_send_gid);

    edit_num_info = cui_sms_get_edit_number_info(sms_send_gid);

    MMI_ASSERT(edit_num_info != NULL);
    
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (edit_num_info->phone_number_addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
    {
        filter_type = SRV_PHB_ENTRY_FIELD_GSM_NUM;
    }
#endif

    handle->child_gid = cui_phb_list_select_contact_create(sms_send_gid);

    if (handle->child_gid != GRP_ID_INVALID)
    {
        cui_phb_list_select_contact_set_field_filter(handle->child_gid, filter_type);
        cui_phb_list_select_contact_run(handle->child_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_sc_addr_from_phb
 * DESCRIPTION
 *  Get Phonebook Number Callback function
 * PARAMETERS
 *  name        [IN]        Name
 *  number      [IN]        Number
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_get_sc_addr_from_phb(mmi_id sms_gid, S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;
    cui_sms_edit_phone_number_struct *edit_num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_SC_FROM_PHB, sms_send_gid);

    edit_num_info = cui_sms_get_edit_number_info(sms_send_gid);

    MMI_ASSERT(edit_num_info != NULL);

    if (cui_sms_is_valid_address(number, edit_num_info->phone_number_addr_type) == MMI_FALSE)
    {
        U16 string_id;

        switch (edit_num_info->phone_number_addr_type)
        {
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            case CUI_SMS_ADDR_TYPE_EMAIL_ADDR:
                string_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
                break;
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

            case CUI_SMS_ADDR_TYPE_NUMBER:
            default:
                string_id = STR_GLOBAL_INVALID_NUMBER;
                break;
        }

        mmi_popup_display_simple_ext(
            string_id,
            MMI_EVENT_FAILURE,
            sms_send_gid,
            NULL);
    }
    else
    {
        U32 max_char_num;
        mmi_ucs2cpy(edit_num_info->phone_number_buff, number);

        switch (edit_num_info->phone_number_addr_type)
        {
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            case CUI_SMS_ADDR_TYPE_EMAIL_ADDR:
                max_char_num = edit_num_info->phone_number_max_addr_len + 1;
                break;
        #endif /*  __MMI_MESSAGES_SMS_EMAIL__*/

            case CUI_SMS_ADDR_TYPE_NUMBER:
            default:
                max_char_num = edit_num_info->phone_number_max_addr_len;
                break;
        }

        cui_fseditor_set_text(edit_num_info->editor_gid, (WCHAR*)edit_num_info->phone_number_buff, max_char_num * ENCODING_LENGTH, max_char_num - 1);
    }
}
#endif /*  __MMI_SMS_SLIM__ */

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
            #ifdef __MMI_MESSAGES_SMS_EMAIL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_get_item
 * DESCRIPTION
 *  Get List Item of The Add Recipient Screen 
 * PARAMETERS
 *  item_index          [IN]            Item index
 *  str_buff            [OUT]            String buffer
 *  img_buff_p          [OUT]             Image buffer
 *  str_img_mask        [IN]            String image mask    
 * RETURNS
 * pBOOL
 *****************************************************************************/
static S32 cui_sms_recipient_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);
    S32 item_index = 0;
    S32 local_index = 0; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_GET_ITEM, sms_send_gid);
    for(; local_index < data_size; ++local_index)
    {
        item_index = start_index + local_index;
        if ((item_index < 0) || ((hd_data->total_num == 0) && (item_index > ITEM_NUM_ABOVE_LINE)) ||
            ((hd_data->total_num > 0) && (item_index > (hd_data->total_num + ITEM_NUM_ABOVE_LINE))))
        {
            return local_index;
        }
        else
        {
            
            MMI_BOOL is_recipient = MMI_FALSE;
            UI_string_type str_buff;
            PU8 *img_buff_p;
            
            str_buff = menu_data[local_index].item_list[0];
            img_buff_p = &menu_data[local_index].image_list[0];

            switch (item_index)
            {
                case ENTER_NUMBER_INDEX:
                {
            #ifdef __MMI_MESSAGES_SMS_EMAIL__
                    if (hd_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
                    {
                        mmi_ucs2ncpy(
                            (S8*)str_buff,
                            (S8*)(S8*)GetString(STR_ID_SMS_ENTER_EMAIL_ADDRESS),
                            MAX_SUBMENU_CHARACTERS);
                    }
                    else
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
                    {
                        mmi_ucs2ncpy(
                            (S8*)str_buff,
                            (S8*)(S8*)GetString(STR_ID_SMS_ENTER_NUMBER),
                            MAX_SUBMENU_CHARACTERS);
                    }
                    break;
                }
                
                case ADD_FROM_CONTACTS_INDEX:
                {
                    mmi_ucs2ncpy((S8*)str_buff, (S8*)GetString(STR_ID_SMS_ADD_FROM_CONTACTS), MAX_SUBMENU_CHARACTERS);
                    break;
                }

                default:
                {
                    if (hd_data->total_num == 0)
                    {
                        mmi_ucs2ncpy((S8*)str_buff, (S8*)GetString(STR_GLOBAL_EMPTY_LIST), MAX_SUBMENU_CHARACTERS);
                    }
                    else
                    {
                        is_recipient = MMI_TRUE;
                    }
                    break;
                }
            }

            if (is_recipient == MMI_TRUE)
            {
                S8 ucs2_num[(CUI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];

                MMI_ASSERT(item_index >= ITEM_NUM_ABOVE_LINE);
                mmi_asc_to_ucs2(
                    ucs2_num,
                    hd_data->recipient[item_index - ITEM_NUM_ABOVE_LINE]);

        #ifdef __MMI_MESSAGES_SMS_EMAIL__
                if (hd_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
                {
                    mmi_ucs2ncpy((S8*)str_buff, ucs2_num, MAX_SUBMENU_CHARACTERS);
                    //Handle get Email Address name for Phonebook
                }
                else
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
                {
                    srv_phb_get_name_by_number((U16 *)ucs2_num, (U16 *)str_buff, MAX_SUBMENU_CHARACTERS);

                    if (!mmi_ucs2strlen((S8*)str_buff))
                    {
                        mmi_ucs2ncpy((S8*)str_buff, (S8*)ucs2_num, MAX_SUBMENU_CHARACTERS);
                    }
                }

                //Should be replaced to the right image
                *img_buff_p = get_image(IMG_STORAGE_HANDSET);;
            }
        }
    }

        return data_size;
}

/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_enter_number_done
 * DESCRIPTION
 *  Enter Number finish function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_enter_number_done(S8 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;
    cui_sms_send_handle_struct *handle;
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_ENTER_NUMBER_DONE, sms_send_gid);

    handle = cui_sms_get_send_handle(sms_send_gid);

    MMI_ASSERT(handle != NULL);

    hd_data = handle->data;

    MMI_ASSERT(hd_data != NULL);

    cui_sms_append_recipient(sms_send_gid, ucs2_addr);

    hd_data->recipient_info.highlihgt_index = hd_data->total_num + ITEM_NUM_ABOVE_LINE - 1;

    cui_fseditor_close(hd_data->edit_num_info->editor_gid);
    cui_sms_entry_phone_number_leave_proc(handle);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_add_from_contacts
 * DESCRIPTION
 *  "Add from contacts" item LSK Handler Funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_add_from_contacts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;
    cui_sms_send_handle_struct *handle;
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_ADD_FROM_CONTACTS, sms_send_gid);

    handle = cui_sms_get_send_handle(sms_send_gid);
    hd_data = handle->data;

    MMI_ASSERT(hd_data != NULL);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_ADD_FROM_CONTACTS_1, hd_data);

    if (hd_data->total_num == CUI_SMS_MAX_RECIPIENTS_NUM)
    {
        mmi_popup_display_simple_ext(
            STR_ID_SMS_RECIPIENTS_FULL,
            MMI_EVENT_FAILURE,
            sms_send_gid,
            NULL);
    }
    else
    {
        U32 filter_type;
    #ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
        U16 remaining_num;
    #endif

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (hd_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
        {
            filter_type = SRV_PHB_ENTRY_FIELD_EMAIL;
        }
        else
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        {
            filter_type = SRV_PHB_ENTRY_FIELD_NUMBER;
        }
#ifndef __MMI_MAINLCD_96X64__
    #ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
        handle->child_gid = cui_phb_list_group_select_contact_create(sms_send_gid);
        if (handle->child_gid != GRP_ID_INVALID)
        {
            remaining_num = CUI_SMS_MAX_RECIPIENTS_NUM - hd_data->total_num;
            cui_phb_list_select_contact_set_count(handle->child_gid, remaining_num);
            cui_phb_list_select_contact_set_field_filter(handle->child_gid, filter_type);
            cui_phb_list_group_select_contact_run(handle->child_gid);
        }
    #else /* __MMI_PHB_GENERIC_MULTI_SELECT__ */
        handle->child_gid = cui_phb_list_select_contact_create(sms_send_gid);
        if (handle->child_gid != GRP_ID_INVALID)
        {
            cui_phb_list_select_contact_set_field_filter(handle->child_gid, filter_type);
            cui_phb_list_select_contact_run(handle->child_gid);
        }
    #endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */
#else
handle->child_gid = cui_phb_list_select_contact_create(sms_send_gid);
        if (handle->child_gid != GRP_ID_INVALID)
        {
            cui_phb_list_select_contact_set_field_filter(handle->child_gid, filter_type);
            cui_phb_list_select_contact_run(handle->child_gid);
        }

#endif

    }
}


#ifdef __MMI_PHB_GENERIC_MULTI_SELECT__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_addr_from_phb_list
 * DESCRIPTION
 *  Get Number from Phonebook
 * PARAMETERS
 *  count       [IN]    total number
 *  phb_index   [IN]    Phonebook number entry index
 *  num_type    [IN]    number type
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_get_addr_from_phb_list(mmi_id sms_send_gid, U16 count, U16 *phb_index, U8 *num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 invalid_count;
    cui_sms_send_handle_data_struct *handle_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_ADDR_FROM_PHB_LIST, sms_send_gid, count);

    handle_data = cui_sms_get_send_handle_data(sms_send_gid);

    invalid_count = cui_sms_add_phb_number_to_recipient(sms_send_gid, count, phb_index, num_type);

    handle_data->recipient_info.highlihgt_index =handle_data->total_num + ITEM_NUM_ABOVE_LINE - 1;

    //GoBackToHistory(SCR_ID_SMS_ADD_RECIPIENT); /* ?? */

    if (invalid_count > 0)
    {
        U16 string_id;

        if (count == 1)
        {
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            if (handle_data->recipient_info.addr_type == SMS_ADDR_TYPE_EMAIL_ADDR)
            {
                string_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
            }
            else
            {
                string_id = STR_GLOBAL_INVALID_NUMBER;
            }
        #else /* __MMI_MESSAGES_SMS_EMAIL__ */
            string_id = STR_GLOBAL_INVALID_NUMBER;
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

            mmi_popup_display_simple_ext(
                string_id,
                MMI_EVENT_FAILURE,
                sms_send_gid,
                NULL);
        }
        else
        {
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            if (handle_data->recipient_info.addr_type == SMS_ADDR_TYPE_EMAIL_ADDR)
            {
                string_id = STR_ID_SMS_INVLAID_ADDRESS_REMOVED;
            }
            else
            {
                string_id = STR_ID_SMS_INVLAID_NUMBERS_REMOVED;
            }
        #else /* __MMI_MESSAGES_SMS_EMAIL__ */
            string_id = STR_ID_SMS_INVLAID_NUMBERS_REMOVED;
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

            mmi_popup_display_simple_ext(
                string_id,
                MMI_EVENT_INFO,
                sms_send_gid,
                NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_addr_from_caller_group
 * DESCRIPTION
 *  Get Number from Phonebook Caller group
 * PARAMETERS
 *  count       [IN]    total number
 *  phb_index   [IN]    Phonebook number entry index
 *  num_type    [IN]    number type
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_get_addr_from_caller_group(mmi_id sms_send_gid, U16 count, U16 *phb_index, U8 *num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *handle_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_ADDR_FROM_CALLER_GROUP, sms_send_gid, count);

    handle_data = cui_sms_get_send_handle_data(sms_send_gid);

    if (count == 0)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_EMPTY,
            MMI_EVENT_FAILURE,
            sms_send_gid,
            NULL);
    }
    else
    {
        U16 pre_total_num = handle_data->total_num;
        U16 rest_recipient_num = CUI_SMS_MAX_RECIPIENTS_NUM - pre_total_num;
        U16 invalid_count;
        U16 add_count;

        if (rest_recipient_num > count)
        {
            add_count = count;
        }
        else
        {
            add_count = rest_recipient_num;
        }

        invalid_count = cui_sms_add_phb_number_to_recipient(sms_send_gid, add_count, phb_index, num_type);
    
        if (count > rest_recipient_num)
        {
            handle_data->recipient_info.pre_total_num = pre_total_num;
            handle_data->recipient_info.invalid_num = invalid_count;
            cui_sms_entry_recipient_exceeded_confirm(sms_send_gid, rest_recipient_num, MMI_FALSE);
        }
        else
        {
            handle_data->recipient_info.highlihgt_index = handle_data->total_num + ITEM_NUM_ABOVE_LINE - 1;

            //GoBackToHistory(SCR_ID_SMS_ADD_RECIPIENT);  /* ???? */

            if (invalid_count > 0)
            {
                mmi_popup_display_simple_ext(
                    STR_ID_SMS_INVLAID_NUMBERS_REMOVED,
                    MMI_EVENT_INFO,
                    sms_send_gid,
                    NULL);
            }
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  cui_sms_add_phb_number_to_recipient
 * DESCRIPTION
 *  Get Number from Phonebook
 * PARAMETERS
 *  count       [IN]    total number
 *  phb_index   [IN]    Phonebook number entry index
 *  num_type    [IN]    number type
 * RETURNS
 *  void
 *****************************************************************************/
static U16 cui_sms_add_phb_number_to_recipient(mmi_id sms_send_gid, U16 count, U16 *phb_index, U8 *num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 phb_numer[(MMI_PHB_EMAIL_LENGTH + 1) * ENCODING_LENGTH];
    U16 i;
    U16 invalid_recipient_num = 0;
    cui_sms_send_handle_data_struct *handle_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ADD_PHB_NUM_TO_RECIPIENT, sms_send_gid);

    handle_data = cui_sms_get_send_handle_data(sms_send_gid);

    if (count > 0)
    {
        for (i = 0; i < count; i++)
        {
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            if (handle_data->recipient_info.addr_type == SMS_ADDR_TYPE_EMAIL_ADDR)
            {
                mmi_phb_mark_several_for_msg_get_number(
                    phb_numer,
                    MMI_PHB_EMAIL_LENGTH,
                    phb_index[i],
                    num_type[i]);
            }
            else
        #endif
            {
                mmi_phb_mark_several_for_msg_get_number(
                    phb_numer,
                    MMI_PHB_NUMBER_LENGTH,
                    phb_index[i],
                    num_type[i]);
            }

        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            if ((cui_sms_is_valid_address((S8*)phb_numer, handle_data->recipient_info.addr_type) == MMI_FALSE) ||
                ((handle_data->recipient_info.addr_type == SMS_ADDR_TYPE_EMAIL_ADDR) &&
                 (mmi_ucs2strlen((S8*)phb_numer) > handle_data->recipient_info.max_email_addr_len)))
        #else /* __MMI_MESSAGES_SMS_EMAIL__ */
            if (cui_sms_check_sms_number((S8*)phb_numer) == MMI_FALSE)
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
            {
                invalid_recipient_num++;
            }
            else
            {
                if (cui_sms_append_recipient(sms_send_gid, (S8*)phb_numer) == MMI_FALSE)
                {
                    break;
                }
                else
                {
                    handle_data->recipient_info.is_modify = MMI_TRUE;
                }
            }
        }
    }

    return invalid_recipient_num;
}
#endif /* __MMI_PHB_GENERIC_MULTI_SELECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_recipient_get_number_from_phb
 * DESCRIPTION
 *  Get Number from Phonebook
 * PARAMETERS
 *  name        [IN]        Phonebook name
 *  number      [IN]        Phonebook number
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_get_number_from_phb(mmi_id sms_send_gid, S8* name, S8* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    U16 string_id = 0;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    cui_sms_send_handle_data_struct *handle_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_GET_NUM_FROM_PHB, sms_send_gid);

    handle_data = cui_sms_get_send_handle_data(sms_send_gid);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (cui_sms_is_valid_address((S8*)number, handle_data->recipient_info.addr_type) == MMI_FALSE)
    {
        if (handle_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
        {
            string_id = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
        }
        else
        {
            string_id = STR_GLOBAL_INVALID_NUMBER;
        }
    }
    else
    {
        if ((handle_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR) &&
            (mmi_ucs2strlen(number) > handle_data->recipient_info.max_email_addr_len))
        {
            string_id = STR_ID_SMS_ADDRESS_LEN_EXCEEDED;
        }
    }

    if (string_id != 0)
    {
        mmi_popup_display_simple_ext(
            string_id,
            MMI_EVENT_FAILURE,
            sms_send_gid,
            NULL);
    }
#else /* __MMI_MESSAGES_SMS_EMAIL__ */
    if (cui_sms_check_sms_number(number) == MMI_FALSE)
    {
        mmi_popup_display_simple_ext(
            STR_GLOBAL_INVALID_NUMBER,
            MMI_EVENT_FAILURE,
            sms_send_gid,
            NULL);
    }
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    else
    {
        cui_sms_append_recipient(sms_send_gid, number);
        handle_data->recipient_info.is_modify = MMI_TRUE;
        handle_data->recipient_info.highlihgt_index = handle_data->total_num + ITEM_NUM_ABOVE_LINE - 1;
        //GoBackToHistory(SCR_ID_SMS_ADD_RECIPIENT); /* ???? */
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_recipient_exceeded_confirm
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_recipient_exceeded_confirm(mmi_id sms_send_gid, U16 count, MMI_BOOL is_send)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *confirm_str_buff;
    S8 asc_str[10];
    S8 ucs2_str[10 * ENCODING_LENGTH];
    U16 front_str_id = STR_ID_SMS_CAN_ONLY_ADD_FIRST;
    U16 last_str_id = STR_ID_SMS_CONTACTS_CONTINUE_QUERY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_EXCEEDED_CONFIRM, count, is_send);

    confirm_str_buff = OslMalloc(CUI_SMS_MAX_COMFIRM_LEN * ENCODING_LENGTH);

    if (is_send == MMI_TRUE)
    {
        front_str_id = STR_ID_SMS_CAN_ONLY_SEND_TO_FIRST;
    }

    mmi_ucs2cpy(confirm_str_buff, (S8*)GetString(front_str_id));

    sprintf(asc_str, "%d", count);
    mmi_asc_to_ucs2(ucs2_str, asc_str);

    mmi_ucs2cat(confirm_str_buff, (S8*)ucs2_str);

    if (count == 1)
    {
        last_str_id = STR_ID_SMS_CONTACT_CONTINUE_QUERY;
    }

    mmi_ucs2cat(confirm_str_buff, (S8*)GetString(last_str_id));

    cui_sms_entry_confirm_sg_ext(
        sms_send_gid,
        (WCHAR*)confirm_str_buff,
        cui_sms_recipient_exceeded_handle,
        cui_sms_recipient_exceeded_confirm_go_back);

    OslMfree(confirm_str_buff);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_exceeded_confirm_go_back
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_exceeded_confirm_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);
    U16 rollback_num = hd_data->total_num - hd_data->recipient_info.pre_total_num;
    U16 start_index = hd_data->recipient_info.pre_total_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_EXCEEDED_GOBACK, sms_send_gid);

    if (rollback_num > 0 && start_index < CUI_SMS_MAX_RECIPIENTS_NUM)
    {
        if (rollback_num > (CUI_SMS_MAX_RECIPIENTS_NUM - start_index))
        {
            rollback_num = CUI_SMS_MAX_RECIPIENTS_NUM - start_index;
        }

        memset(
            hd_data->recipient[start_index],
            0,
            (CUI_SMS_MAX_ADDR_LEN + 1) * rollback_num);

        hd_data->total_num = hd_data->recipient_info.pre_total_num;
    }

    if (mmi_frm_scrn_is_present(sms_send_gid, SCR_ID_SMS_ADD_RECIPIENT, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_exceeded_handle
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_exceeded_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_EXCEEDED_HANDLE, sms_send_gid, hd_data->total_num);

    hd_data->recipient_info.highlihgt_index = hd_data->total_num + ITEM_NUM_ABOVE_LINE - 1;

    if (mmi_frm_scrn_is_present(sms_send_gid, SCR_ID_SMS_ADD_RECIPIENT, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {
        mmi_frm_scrn_close_active_id();
    }

    if (hd_data->recipient_info.invalid_num > 0)
    {
        mmi_popup_display_simple_ext(
            (STR_ID_SMS_INVLAID_NUMBERS_REMOVED),
            MMI_EVENT_INFO,
            sms_send_gid,
            NULL);
    }

    hd_data->recipient_info.pre_total_num = 0;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_add_recipient_options
 * DESCRIPTION
 *  Entry "Add Recipient" Options Screen Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_add_recipient_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;
#ifdef __MMI_DUAL_SIM_MASTER__
    cui_sms_send_handle_struct *send_hd;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();
#ifdef __MMI_DUAL_SIM_MASTER__
    send_hd = cui_sms_get_send_handle(sms_send_gid);
    send_hd->is_direct_send = MMI_FALSE;
#endif

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTRY_ADD_RECIPIENT_OPTIONS, sms_send_gid);

    cui_menu_create_and_run(
                        sms_send_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,
                        MENU_ID_SMS_RECIPIENT_OPTIONS,
                        MMI_FALSE,
                        NULL);
}


/*****************************************************************************
* FUNCTION
*  cui_sms_add_recipient_entry_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_sms_add_recipient_entry_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sms_send_gid;
    cui_sms_send_handle_data_struct *hd_data;
    MMI_ID cui_menu_gid = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTRY_ADD_RECIPIENT_OPTIONS, sms_send_gid);

    hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    if (cui_sms_is_send_enable() == MMI_TRUE)
    {
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        if (srv_sim_ctrl_get_num_of_inserted()==0)
        {
            cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_RECIPIENT_OPT_SEND, MMI_FALSE);
        }
else
#endif
        {
             cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_RECIPIENT_OPT_SEND, MMI_FALSE);
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        cui_sms_set_send_select_sim_leaf_item(cui_menu_gid, MENU_ID_SMS_RECIPIENT_OPT_SEND, hd_data->para_flag);
    #endif
#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
        if (SRV_UM_SIM_UNCLASSIFIED != srv_um_get_prefer_sim())
        {
            cui_menu_set_non_leaf_item(cui_menu_gid, MENU_ID_SMS_RECIPIENT_OPT_SEND, MMI_FALSE);
        }
#endif
    }
    else
    {
        cui_menu_set_item_disabled(cui_menu_gid, MENU_ID_SMS_RECIPIENT_OPT_SEND, MMI_TRUE);
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_RECIPIENT_OPT_SEND, MMI_TRUE);
    }

#ifndef __MMI_UNIFIED_COMPOSER__    
    if (hd_data->recipient_info.is_hide_save_menu == MMI_TRUE)
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_RECIPIENT_OPT_SAVE_TO_DRAFTS, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_menu_gid, MENU_ID_SMS_RECIPIENT_OPT_SAVE_TO_DRAFTS, MMI_FALSE);
    #ifdef __MMI_DUAL_SIM_MASTER__
        cui_sms_set_save_select_sim_leaf_item(cui_menu_gid, MENU_ID_SMS_RECIPIENT_OPT_SAVE_TO_DRAFTS);
    #endif
    }
#endif /* __MMI_UNIFIED_COMPOSER__ */

	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  cui_sms_add_recipient_select_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret cui_sms_add_recipient_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *cui_menu_evt = menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (cui_menu_evt->highlighted_menu_id)
    {
        case MENU_ID_SMS_RECIPIENT_OPT_SEND:
            #if (MMI_MAX_SIM_NUM == 1)
                cui_sms_recipient_opt_send();
            #endif
            #if ((MMI_MAX_SIM_NUM == 2) ||defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__))
            /* can only be selected when only one sim is availale*/
            {
                MMI_ID sms_send_gid = cui_sms_get_active_send_gid();
                cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);

                if(mmi_sms_get_valid_sim_op_count(srv_nw_usab_is_usable) == 1 
                   || (hd_data->para_flag & SRV_SMS_PARA_SIM_ID))
                {
                    cui_sms_dm_pre_send_msg();
                }
                
            #if (defined(__OP01__))
                 else if (SRV_UM_SIM_UNCLASSIFIED != srv_um_get_prefer_sim())
                {
                    cui_sms_recipient_opt_send_by_sim(mmi_sms_um_sim_to_sms_sim(srv_um_get_prefer_sim()));
                }
            #endif
            }
            #endif
            
        #ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        /* for dynamic sim ui, there will be sim select 2nd level menu */
            #if (MMI_MAX_SIM_NUM >= 3)
            cui_sms_use_sim_selector();
            #endif
        #endif
            break;

        case MENU_ID_SMS_RECIPIENT_OPT_EDIT:
            cui_sms_recipient_opt_edit();
            break;

        case MENU_ID_SMS_RECIPIENT_OPT_REMOVE:
            cui_sms_recipient_opt_remove();
            break;

        case MENU_ID_SMS_RECIPIENT_OPT_REMOVE_ALL:
            cui_sms_recipient_opt_remove_all();
            break;

    #ifndef __UNIFIED_COMPOSER_SUPPORT__
        case MENU_ID_SMS_RECIPIENT_OPT_SAVE_TO_DRAFTS:
            #ifdef __MMI_DUAL_SIM_MASTER__
            {
                U8 menuitems = 0;
                MMI_BOOL is_sim1_valid = srv_sim_ctrl_is_available(MMI_SIM1);
                MMI_BOOL is_sim2_valid = srv_sim_ctrl_is_available(MMI_SIM2);
            #if (MMI_MAX_SIM_NUM >= 3)
                MMI_BOOL is_sim3_valid = srv_sim_ctrl_is_available(MMI_SIM3);
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)            
                MMI_BOOL is_sim4_valid = srv_sim_ctrl_is_available(MMI_SIM4);                
            #endif

                if (is_sim1_valid)
                {
                    menuitems++;
                }
                if (is_sim2_valid)
                {
                    menuitems++;
                }
                #if (MMI_MAX_SIM_NUM >= 3)
                if (is_sim3_valid)
                {
                    menuitems++;
                }
                #endif                    
                #if (MMI_MAX_SIM_NUM >= 4)                    
                if (is_sim4_valid)
                {
                    menuitems++;
                }
                #endif                
			
                if (menuitems < 2)
                {
                    cui_sms_recipient_opt_save_to_drafts();
                }
            }
            #else
            cui_sms_recipient_opt_save_to_drafts();
            #endif
            break;
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */

    #if (MMI_MAX_SIM_NUM == 2) || defined (__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
        case MENU_ID_SMS_SEND_OPT_BY_SIM1:
            cui_sms_recipient_opt_send_by_sim(SRV_SMS_SIM_1);
            break;
        case MENU_ID_SMS_SEND_OPT_BY_SIM2:
            cui_sms_recipient_opt_send_by_sim(SRV_SMS_SIM_2);
            break;
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_SMS_SEND_OPT_BY_SIM3:
            cui_sms_recipient_opt_send_by_sim(SRV_SMS_SIM_3);
            break;
            
    #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_SMS_SEND_OPT_BY_SIM4:
            cui_sms_recipient_opt_send_by_sim(SRV_SMS_SIM_4);
            break;
    #endif /* MMI_MAX_SIM_NUM == 4 */
    #endif /* MMI_MAX_SIM_NUM == 3 */
    #endif __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    #endif /* MMI_MAX_SIM_NUM == 2 */
    
    #ifndef __UNIFIED_COMPOSER_SUPPORT__
    #if (MMI_MAX_SIM_NUM >= 2)
        case MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM1:
            {
                MMI_ID sms_send_gid = cui_sms_get_active_send_gid();
                cui_sms_set_send_sim_id(sms_send_gid, SRV_SMS_SIM_1);
                cui_sms_recipient_opt_save_to_drafts();
            }
            break;
        case MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM2:
            {
                MMI_ID sms_send_gid = cui_sms_get_active_send_gid();
                cui_sms_set_send_sim_id(sms_send_gid, SRV_SMS_SIM_2);
                cui_sms_recipient_opt_save_to_drafts();
            }
            break;
    #if (MMI_MAX_SIM_NUM >= 3)            
        case MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM3:
            {
                MMI_ID sms_send_gid = cui_sms_get_active_send_gid();
                cui_sms_set_send_sim_id(sms_send_gid, SRV_SMS_SIM_3);
                cui_sms_recipient_opt_save_to_drafts();
            }
            break;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM4:
            {
                MMI_ID sms_send_gid = cui_sms_get_active_send_gid();
                cui_sms_set_send_sim_id(sms_send_gid, SRV_SMS_SIM_4);
                cui_sms_recipient_opt_save_to_drafts();
            }
            break;            
    #endif            
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */

        default:
            break;
    }

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_pre_send_msg
 * DESCRIPTION
 *  Pre Send message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void cui_sms_pre_send_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;
    cui_sms_send_handle_data_struct *hd_data;
    srv_sms_setting_struct default_setting;
    S8 *sc_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_PRE_SEND_MSG, sms_send_gid);

    hd_data = cui_sms_get_send_handle_data(sms_send_gid);
    //Check whether SC Number is empty
    if((hd_data->spec_para & SRV_SMS_SPEC_SEND_SCA) == SRV_SMS_SPEC_SEND_SCA)
    {
        sc_number = hd_data->sc_address;
    }
    else
    {
        memcpy(&default_setting, srv_sms_get_default_setting(hd_data->sim_id), sizeof(srv_sms_setting_struct));
        sc_number = default_setting.sc_addr;
    }
    if (sc_number == NULL || strlen((S8*)sc_number) == 0)
    {
        if (hd_data->is_allow_sc_emtpy == MMI_FALSE)
        {
            cui_evt_sms_send_popup_info_struct *param = OslMalloc(sizeof(cui_evt_sms_send_popup_info_struct));
            param->sms_gid = sms_send_gid;
            param->is_send_finish = MMI_TRUE;
            param->result = CUI_SMS_RESULT_ERROR;

            cui_sms_display_popupcallback_sg_ext(
                sms_send_gid,
                STR_SMS_FAILURE_SC_NUM_EMPTY,
                MMI_EVENT_FAILURE,
                cui_sms_popup_send_evt_to_parent,
                param,
                0);
        }
        else
        {
        /* clear SRV_SMS_PARA_SIM_ID not clear sim_id, when save can use sim_id, back can select SIM,*/
        #ifdef __MMI_DUAL_SIM_MASTER__
            hd_data->para_flag &= (~SRV_SMS_PARA_SIM_ID);
        #endif
        #ifdef __MMI_SMS_SLIM__
            cui_sms_display_popup_ext(
                STR_SMS_FAILURE_SC_NUM_EMPTY,
                MMI_EVENT_FAILURE);
        #else /* __MMI_SMS_SLIM__ */
            cui_sms_entry_confirm(
                sms_send_gid,
                STR_ID_SMS_SET_SC_NUMBER_QUERY,
                cui_sms_entry_sc_number,
                cui_sms_goback_from_cur_send_proc,
                MMI_TRUE);
        #endif /* __MMI_SMS_SLIM__ */ 
        }
    }
    else
    {
#ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (hd_data->pid == SRV_SMS_PID_EMAIL)
        {
            sc_number = (S8*)srv_sms_get_email_sc_address();

            if (mmi_ucs2strlen((S8*)sc_number) == 0)
            {
                cui_sms_entry_confirm(
                    sms_send_gid,
                    STR_ID_SMS_SET_EMAIL_SC_NUM_QUERY,
                    cui_sms_entry_email_sc_number,
                    cui_sms_goback_from_cur_send_proc,
                    MMI_TRUE);
            }
            else
            {
    #ifdef __EMS_DYNAMIC_SEG_NUM__
                if (cui_sms_entry_check_dynamic_seg_num() == MMI_FALSE)
    #endif /* __EMS_DYNAMIC_SEG_NUM__ */
                {
                    cui_sms_send_msg_interal();
                }
            }
        }
        else
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        {
#ifdef __EMS_DYNAMIC_SEG_NUM__
            if (cui_sms_entry_check_dynamic_seg_num() == MMI_FALSE)
#endif /* __EMS_DYNAMIC_SEG_NUM__ */
            {
                cui_sms_send_msg_interal();
            }
        }
    }
    
}


#ifndef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_sc_number
 * DESCRIPTION
 *  Entry SC Number Editor Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_sc_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_SMS_MAX_SEND_INSTANCE; i++)
    {
        if (cui_sms_send_instance[i] != 0)
        {
            mmi_frm_scrn_close(cui_sms_send_instance[i], SCR_ID_SMS_SC_NUMBER);
        }
    }

    cui_sms_entry_phone_number_generic(
        SCR_ID_SMS_SC_NUMBER,
        STR_ID_SMS_PROFILE_SC,
        CUI_SMS_ADDR_TYPE_NUMBER,
        NULL,
        SRV_SMS_MAX_ADDR_LEN,
        cui_sms_sc_number_done,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_active_sc_callback
 * DESCRIPTION
 *  Set Active SC Number Callback Function
 * PARAMETERS
 *  result          [IN]    The Save Result
 *  data            [IN]    Dummy
 * RETURNS
 *  void
*****************************************************************************/
static void cui_sms_set_active_sc_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *sms_handle = (cui_sms_send_handle_struct*)callback_data->user_data;
    MMI_ID prompt_string = STR_GLOBAL_SAVED;
    mmi_event_notify_enum event_type = MMI_EVENT_SUCCESS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_ACTIVE_SC_CALLBACK, sms_handle->send_gid);

    if (callback_data->result != MMI_TRUE)
    {
            prompt_string = STR_GLOBAL_UNFINISHED;
            event_type = MMI_EVENT_FAILURE;
    }

    cui_sms_display_popupcallback_sg_ext(
        sms_handle->send_gid,
        prompt_string,
        event_type,
        cui_sms_popup_goback_from_edit_sc_proc,
        sms_handle,
        0);
    cui_fseditor_close(sms_handle->data->edit_num_info->editor_gid);
    cui_sms_entry_phone_number_leave_proc(sms_handle);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_sc_number_done
 * DESCRIPTION
 *  Edit SC Number Finish Function
 * PARAMETERS
 *  ucs2_num    [IN]    UCS2 Address
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_sc_number_done(S8 *ucs2_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;
    cui_sms_send_handle_struct *sms_handle;
    mmi_id sms_send_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_EDIT_SC_DONE, sms_send_gid);

    sms_handle = cui_sms_get_send_handle(sms_send_gid);
    hd_data = sms_handle->data;

    MMI_ASSERT(hd_data != NULL);

    srv_sms_set_setting_para(
        SRV_SMS_ACTIVE_SC_ADDR,
        (void*)ucs2_num,
        hd_data->sim_id,
        cui_sms_set_active_sc_callback,
        sms_handle);
}


#ifdef __MMI_MESSAGES_SMS_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_active_email_sc_callback
 * DESCRIPTION
 *  Set Active SMS Email SC Number Callback Function
 * PARAMETERS
 *  result          [IN]    The Save Result
 *  data            [IN]    Dummy
 * RETURNS
 *  void
*****************************************************************************/
static void cui_sms_set_active_email_sc_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_struct *sms_handle = (cui_sms_send_handle_struct*)callback_data->user_data;
    MMI_ID prompt_string = STR_GLOBAL_SAVED;
    mmi_event_notify_enum event_type = MMI_EVENT_SUCCESS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_ACTIVE_EMAIL_SC_CALLBACK, sms_handle->send_gid);

    if (callback_data->result != MMI_TRUE)
    {
        prompt_string = STR_GLOBAL_UNFINISHED;
        event_type = MMI_EVENT_FAILURE;
    }
    cui_sms_display_popupcallback_sg_ext(
        sms_handle->send_gid,
        prompt_string,
        event_type,
        cui_sms_popup_goback_from_edit_sc_proc,
        sms_handle,
        0);

    cui_fseditor_close(sms_handle->data->edit_num_info->editor_gid);
    cui_sms_entry_phone_number_leave_proc(sms_handle);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_email_sc_number
 * DESCRIPTION
 *  Entry SMS Email SC Number Editor Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_email_sc_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CUI_SMS_MAX_SEND_INSTANCE; i++)
    {
        if (cui_sms_send_instance[i] != 0)
        {
            mmi_frm_scrn_close(cui_sms_send_instance[i], SCR_ID_SMS_EMAIL_SC_NUMBER);
        }
    }

    cui_sms_entry_phone_number_generic(
        SCR_ID_SMS_EMAIL_SC_NUMBER,
        STR_ID_SMS_EMAIL_SC,
        CUI_SMS_ADDR_TYPE_NUMBER,
        NULL,
        SRV_SMS_MAX_ADDR_LEN,
        cui_sms_email_sc_number_done,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_email_sc_number_done
 * DESCRIPTION
 *  Edit SMS Email SC Number Finish Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_email_sc_number_done(S8 *ucs2_num)
{
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *hd_data;
    cui_sms_send_handle_struct *sms_handle;
    mmi_id sms_send_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_EDIT_EMAIL_SC_DONE, sms_send_gid);

    sms_handle = cui_sms_get_send_handle(sms_send_gid);
    hd_data = sms_handle->data;

    srv_sms_set_setting_para(
        SRV_SMS_ACTIVE_EMAIL_SC_ADDR,
        (void*)ucs2_num,
        hd_data->sim_id,
        cui_sms_set_active_email_sc_callback,
        sms_handle);
}
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#endif /* __MMI_SMS_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_msg_interal
 * DESCRIPTION
 *  Send Message in the SMS Application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_send_msg_interal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_MSG_INTERNAL, sms_send_gid);

    cui_sms_init_send_info_data(sms_send_gid);

    cui_sms_send_curr_msg(sms_send_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_init_send_info_data
 * DESCRIPTION
 *  Init the send info data before send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_init_send_info_data(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 send_total_num = 0;
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_INIT_SEND_INFO_DATA, sms_send_gid);

    hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    for (i = 0; i < hd_data->total_num; i++)
    {
        MMI_BOOL is_duplicated = MMI_FALSE;
        U16 j;
        S8 *src_addr = hd_data->recipient[i];

        for (j = 0; j < i; j++)
        {
            S8 *dest_addr = hd_data->recipient[j];

        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            if (hd_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
            {
                if (strcmp((S8*)src_addr, (S8*)dest_addr) == 0)
                {
                    is_duplicated = MMI_TRUE;
                    break;
                }
            }
            else
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
            if (cui_sms_compare_number((S8*)src_addr, (S8*)dest_addr))
            {
                is_duplicated = MMI_TRUE;
                break;
            }
        }

        if (is_duplicated == MMI_FALSE)
        {
            hd_data->send_info.recipient[send_total_num] = hd_data->recipient[i];
            send_total_num++;
        }
    }

    hd_data->send_info.total_num = send_total_num;

    hd_data->send_info.curr_send_index = 0;
    hd_data->send_info.is_sending = MMI_TRUE;
    hd_data->send_info.is_aborting = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_curr_msg
 * DESCRIPTION
 *  Send the current index's message to network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_send_curr_msg(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_fsm_struct fsm_data;
    cui_sms_send_handle_struct *handle = cui_sms_get_send_handle(sms_send_gid);
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);
    cui_sms_send_case_enum send_msg_case = handle->send_msg_case;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(hd_data != NULL);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_CURR_MSG, hd_data->send_info.curr_send_index);

    /* Only consider it as a reply case  don't add or modify
       the recipient when reply a sms */
    if ((hd_data->send_info.total_num != 1) ||
        (hd_data->recipient_info.is_modify != MMI_FALSE)
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        || (hd_data->pid != SRV_SMS_PID_DEFAULT)
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        )
    {
        hd_data->reply_msg_id = SRV_SMS_INVALID_MSG_ID;
    }

    fsm_data.msg_index = hd_data->send_info.msg_index;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_CURR_MSG_1, hd_data->reply_msg_id);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_CURR_MSG_2, fsm_data.msg_index);

    if (hd_data->send_info.curr_send_index == 0)
    {
        cui_sms_entry_sending();
    }
    else
    {
        cui_sms_update_sending_caption(sms_send_gid);
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        fsm_data.save_sent_flag = MMI_FALSE;
        fsm_data.save_send_fail_flag = MMI_FALSE;
#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    if ((send_msg_case == CUI_SMS_SEND_CASE_SEND_FROM_OTHER_APP)
        || (send_msg_case == CUI_SMS_SEND_CASE_SEND_DATA_MSG)
        || (hd_data->send_type == SRV_SMS_BG_SEND))
    {
        fsm_data.save_send_fail_flag = MMI_FALSE;
        fsm_data.save_sent_flag = MMI_FALSE;
    }
    else
    {
        fsm_data.save_send_fail_flag = MMI_TRUE;
    
        /* Only save the first SMS if all of the SMS is sent. */
        if ((hd_data->send_info.curr_send_index == 0) 
            && (srv_sms_is_save_sent_sms_setting(hd_data->sim_id) == MMI_TRUE))
        {
            fsm_data.save_sent_flag = MMI_TRUE;
        }
        else
        {
            fsm_data.save_sent_flag = MMI_FALSE;
        }
    }
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_CURR_MSG_3, fsm_data.save_sent_flag);

    if (((send_msg_case == CUI_SMS_SEND_CASE_EDIT_UNSENT) ||
         (send_msg_case == CUI_SMS_SEND_CASE_RESEND) ||
         (send_msg_case == CUI_SMS_SEND_CASE_EDIT_DRAFT) ||
         (send_msg_case == CUI_SMS_SEND_CASE_SEND_DRAFT)) &&
        ((hd_data->send_info.curr_send_index + 1) == hd_data->send_info.total_num))
    {
        fsm_data.del_send_fail_flag = MMI_TRUE;
        fsm_data.del_send_succ_flag = MMI_TRUE;
    }
    else
    {
        fsm_data.del_send_fail_flag = MMI_FALSE;
        fsm_data.del_send_succ_flag = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_CURR_MSG_4, fsm_data.del_send_fail_flag, fsm_data.del_send_succ_flag);

    fsm_data.state = SEND_FSM_STATE_START;
    fsm_data.srv_save_handle = NULL;
    fsm_data.result_func = cui_sms_send_msg_handle;
    cui_sms_send_msg_fsm(handle, &fsm_data);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_msg_fsm
 * DESCRIPTION
 *  Send Msg FSM
 * PARAMETERS
 *  data        [IN]    The Send MSG FSM Data
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_send_msg_fsm(cui_sms_send_handle_struct *handle, cui_sms_send_fsm_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_callback_struct cb_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_MSG_FSM, handle->data);

    memset(&cb_data, 0, sizeof(srv_sms_callback_struct));

    if (handle->data->send_fsm_info != NULL)
    {
        OslMfree(handle->data->send_fsm_info);
        handle->data->send_fsm_info = NULL;
    }

    handle->data->send_fsm_info = OslMalloc(sizeof(cui_sms_send_fsm_struct));

    memcpy(handle->data->send_fsm_info, data, sizeof(cui_sms_send_fsm_struct));

    handle->data->send_fsm_info->state = SEND_FSM_STATE_START;

    cb_data.result = MMI_TRUE;
    cb_data.user_data = (void*) handle;

    cui_sms_send_msg_fsm_handle(&cb_data);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_msg_fsm_handle
 * DESCRIPTION
 *  Send Msg FSM Handle Function
 * PARAMETERS
 *  data        [IN] Dummy
 *  mod         [IN] The Module Type
 *  result      [IN] The SMS Framework Result
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_send_msg_fsm_handle(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum cause = callback_data->cause;
    cui_sms_send_handle_struct *handle = (cui_sms_send_handle_struct*) callback_data->user_data;
    cui_sms_send_fsm_struct *send_fsm_info;
    cui_sms_send_fsm_state_enum fsm_state;
    SmsCuiCBFuncPtr send_result_func;
    MMI_BOOL is_waiting_rsp = MMI_FALSE;
    cui_sms_result_enum send_result = CUI_SMS_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_MSG_FSM_HANDLE, cause);

    if ((invalid_send_handle != NULL) && (invalid_send_handle == handle))
    {
        invalid_send_handle = NULL;
        return;
    }

    send_fsm_info = handle->data->send_fsm_info;
    fsm_state = send_fsm_info->state;
    send_result_func = send_fsm_info->result_func;

    while ((is_waiting_rsp == MMI_FALSE) && (fsm_state != SEND_FSM_STATE_END))
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_MSG_FSM_HANDLE_1, send_fsm_info->state);

        switch(send_fsm_info->state)
        {
            case SEND_FSM_STATE_START:
            {
                send_fsm_info->state = SEND_FSM_STATE_SEND_REQ;
                fsm_state = send_fsm_info->state;
                break;
            }

            case SEND_FSM_STATE_SEND_REQ:
            {
                send_fsm_info->state = SEND_FSM_STATE_SEND_RSP;
                fsm_state = send_fsm_info->state;
                is_waiting_rsp = MMI_TRUE;
                cui_sms_send_msg_req(handle->send_gid, cui_sms_send_msg_fsm_handle);
                break;
            }

            case SEND_FSM_STATE_SEND_RSP:
            {
                handle->srv_send_handle = NULL;

                if (result == MMI_TRUE)
                {
                    if (send_fsm_info->del_send_succ_flag == MMI_TRUE)
                    {
                        send_fsm_info->state = SEND_FSM_STATE_DEL_SUCC_REQ;
                        fsm_state = send_fsm_info->state;
                    }
                    else
                    {
                        if (send_fsm_info->save_sent_flag == MMI_TRUE)
                        {
                            send_fsm_info->state = SEND_FSM_STATE_SAVE_SUCC_REQ;
                            fsm_state = send_fsm_info->state;
                        }
                        else
                        {
                            send_fsm_info->state = SEND_FSM_STATE_FINISH;
                            fsm_state = send_fsm_info->state;
                        }
                    }
                }
                else
                {
                    switch (cause)
                    {
                        case SRV_SMS_CAUSE_DATA_EXCEED:
                        {
                            send_result = CUI_SMS_RESULT_DATA_EXCEED;
                            send_fsm_info->state = SEND_FSM_STATE_END;
                            fsm_state = send_fsm_info->state;
                            if (send_result_func != NULL)
                            {
                                send_result_func(send_result, (void*)callback_data);
                            }
                            break;
                        }

                        case SRV_SMS_CAUSE_NOT_READY:
                        case SRV_SMS_CAUSE_SEND_BUSY:
                        case SRV_SMS_CAUSE_ERROR_FDN_ENABLED:
                        {
                            send_result = CUI_SMS_RESULT_NOT_READY;
                            if (SRV_SMS_CAUSE_ERROR_FDN_ENABLED == cause)
                            {
                                send_result = CUI_SMS_CAUSE_ERROR_FDN_ENABLED;
                            }
                            send_fsm_info->state = SEND_FSM_STATE_END;
                            fsm_state = send_fsm_info->state;
                            if (send_result_func != NULL)
                            {
                                send_result_func(send_result, (void*)callback_data);
                            }
                            break;
                        }

                        case SRV_SMS_CAUSE_SEND_ABORT:
                        {
                            send_result = CUI_SMS_RESULT_CANCEL;
                            send_fsm_info->state = SEND_FSM_STATE_END;
                            fsm_state = send_fsm_info->state;
                            if (send_result_func != NULL)
                            {
                                send_result_func(send_result, (void*)callback_data);
                            }
                            break;
                        }

                    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                        case SRV_SMS_CAUSE_MEM_FULL:
                        {
                            send_result = CUI_SMS_RESULT_MEM_FULL;
                            send_fsm_info->state = SEND_FSM_STATE_FINISH;
                            fsm_state = send_fsm_info->state;
                            break;
                        }
                    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

                        default:
                        {
                            /* 1> Delete first, then save
                             * 2> If need to delete the send failed message, 
                             *    it also need to save it to oubox
                             */
                            if (send_fsm_info->del_send_fail_flag == MMI_TRUE)
                            {
                                send_fsm_info->state = SEND_FSM_STATE_DEL_FAIL_REQ;
                                fsm_state = send_fsm_info->state;
                            }
                            else
                            {
                                /* whether need save the send failed message to outbox */
                                if (send_fsm_info->save_send_fail_flag == MMI_TRUE)
                                {
                                    send_fsm_info->state = SEND_FSM_STATE_SAVE_FAIL_REQ;
                                    fsm_state = send_fsm_info->state;
                                }
                                else
                                {
                                    send_result = CUI_SMS_RESULT_ERROR;
                                    send_fsm_info->state = SEND_FSM_STATE_FINISH;
                                    fsm_state = send_fsm_info->state;
                                }
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case SEND_FSM_STATE_DEL_SUCC_REQ:
            {
                send_fsm_info->state = SEND_FSM_STATE_DEL_SUCC_RSP;
                fsm_state = send_fsm_info->state;
                is_waiting_rsp = MMI_TRUE;
                srv_sms_delete_msg(send_fsm_info->msg_index, cui_sms_send_msg_fsm_handle, (void*)handle);
                break;
            }

            case SEND_FSM_STATE_DEL_SUCC_RSP:
            {
                if (send_fsm_info->save_sent_flag == MMI_TRUE)
                {
                    send_fsm_info->state = SEND_FSM_STATE_SAVE_SUCC_REQ;
                    fsm_state = send_fsm_info->state;
                }
                else
                {
                    send_result = CUI_SMS_RESULT_OK;
                    send_fsm_info->state = SEND_FSM_STATE_FINISH;
                    fsm_state = send_fsm_info->state;
                }
                break;
            }

            case SEND_FSM_STATE_DEL_FAIL_REQ:
            {
                send_fsm_info->state = SEND_FSM_STATE_DEL_FAIL_RSP;
                fsm_state = send_fsm_info->state;
                is_waiting_rsp = MMI_TRUE;
                srv_sms_delete_msg(send_fsm_info->msg_index, cui_sms_send_msg_fsm_handle, (void*)handle);
                break;
            }

            case SEND_FSM_STATE_DEL_FAIL_RSP:
            {
                send_fsm_info->state = SEND_FSM_STATE_SAVE_FAIL_REQ;
                fsm_state = send_fsm_info->state;
                break;
            }

            case SEND_FSM_STATE_SAVE_SUCC_REQ:
            {
                send_fsm_info->state = SEND_FSM_STATE_SAVE_SUCC_RSP;
                fsm_state = send_fsm_info->state;
                is_waiting_rsp = MMI_TRUE;
                cui_sms_save_msg_req(handle, SRV_SMS_STATUS_SENT, cui_sms_send_msg_fsm_handle);
                break;
            }

            case SEND_FSM_STATE_SAVE_SUCC_RSP:
            {
                if (result == MMI_TRUE)
                {
                    send_result = CUI_SMS_RESULT_SENT_AND_SAVED;
                }
                else
                {
                    send_result = CUI_SMS_RESULT_SENT_BUT_SAVE_FAIL;
                }
                send_fsm_info->state = SEND_FSM_STATE_FINISH;
                fsm_state = send_fsm_info->state;
                break;
            }

            case SEND_FSM_STATE_SAVE_FAIL_REQ:
            {
                send_fsm_info->state = SEND_FSM_STATE_SAVE_FAIL_RSP;
                fsm_state = send_fsm_info->state;
                is_waiting_rsp = MMI_TRUE;
                cui_sms_save_msg_req(handle, SRV_SMS_STATUS_UNSENT, cui_sms_send_msg_fsm_handle);
                break;
            }

            case SEND_FSM_STATE_SAVE_FAIL_RSP:
            {
                if (result == MMI_TRUE)
                {
                    send_result = CUI_SMS_RESULT_SEND_FAIL_BUT_SAVED;
                }
                else
                {
                    send_result = CUI_SMS_RESULT_SEND_FAIL_AND_SAVE_FAIL;
                }

                send_fsm_info->state = SEND_FSM_STATE_END;
                fsm_state = send_fsm_info->state;
                if (send_result_func != NULL)
                {
                    send_result_func(send_result, (void*)callback_data);
                }

                break;
            }

            case SEND_FSM_STATE_FINISH:
            {
                send_fsm_info->state = SEND_FSM_STATE_END;
                fsm_state = send_fsm_info->state;
                if (send_result_func != NULL)
                {
                    send_result_func(send_result, (void*)callback_data);
                }
                break;
            }

            default:
            {
                MMI_ASSERT(0);
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_msg_req
 * DESCRIPTION
 *  Send Msg Request
 * PARAMETERS
 *  req_data        [IN]    Send Request Data
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_send_msg_req(mmi_id sms_send_gid, SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE srv_send_handle;
    cui_sms_send_handle_struct *cui_send_handle = cui_sms_get_send_handle(sms_send_gid);
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(hd_data != NULL);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_MSG_REQ, hd_data->send_info.curr_send_index);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (hd_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
    {
        EMSData *ems_data;
        S32 email_len = 0;
        U16 tmpLen = 0;
        U8 temp[63];
        U8 email_address[63 * ENCODING_LENGTH];
        U16 result = 0;

        GetEMSDataForEdit(&ems_data, 0);

        strcpy((char*)temp, (const char*)hd_data->send_info.recipient[hd_data->send_info.curr_send_index]);
        strcat((char*)temp, (const char*)" ");
        email_len = strlen((const char*)hd_data->send_info.recipient[hd_data->send_info.curr_send_index]) + 1;
        mmi_asc_to_ucs2((S8*) email_address, (S8*) temp);
        tmpLen = ems_data->CurrentPosition.OffsetToText;
        ResetCurrentPosition(ems_data);
        result = AddString(ems_data, (U8*) email_address, (U16) email_len, NULL);
        ResetCurrentPosition(ems_data);
        ForwardCurrentPosition(ems_data, (U16) (tmpLen >> 1));

        if (result != EMS_OK)
        {
            cui_sms_display_popup_ext(
                (STR_SMS_FAILURE_DATA_EXCEED),
                MMI_EVENT_FAILURE);

            cui_sms_send_evt_send_to_parent(sms_send_gid, MMI_TRUE, CUI_SMS_RESULT_DATA_EXCEED);
            return;
        }

        srv_send_handle = srv_sms_get_send_handle();
        srv_sms_set_address(srv_send_handle, (S8*)srv_sms_get_email_sc_address());
    }
    else
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */ 
    {
        S8 ucs2_addr[(SRV_SMS_MAX_ADDR_LEN +1) *ENCODING_LENGTH];
        srv_send_handle = srv_sms_get_send_handle();
        mmi_asc_n_to_ucs2((S8*)ucs2_addr, hd_data->send_info.recipient[hd_data->send_info.curr_send_index], SRV_SMS_MAX_ADDR_LEN +1);
        srv_sms_set_address(srv_send_handle, ucs2_addr);
    }

    cui_send_handle->srv_send_handle = srv_send_handle;
    cui_sms_set_common_para(hd_data, srv_send_handle);
    {
        srv_sms_para_enum para_flag = hd_data->para_flag;
        srv_sms_specify_send_para_enum spec_para = hd_data->spec_para;
        if (para_flag & SRV_SMS_PARA_PORT)
        {
            srv_sms_set_data_port(srv_send_handle, hd_data->src_port, hd_data->dest_port);
        }

        if (spec_para & SRV_SMS_SPEC_SEND_STATUS_REPORT)
        {
            srv_sms_set_status_report(srv_send_handle, hd_data->status_report);
        }

        if (spec_para & SRV_SMS_SPEC_SEND_SCA)
        {
            srv_sms_set_sc_address(srv_send_handle, hd_data->sc_address);
        }

        if (spec_para & SRV_SMS_SPEC_SEND_VP)
        {
            srv_sms_set_vp(srv_send_handle, hd_data->vp);
        }

        if (para_flag & SRV_SMS_PARA_CLASS)
        {
            srv_sms_set_class_type(srv_send_handle, hd_data->class_type);
        }

        if (spec_para & SRV_SMS_SPEC_SEND_REPLY_PATH)
        {
            srv_sms_set_reply_path(srv_send_handle, hd_data->reply_path);
        }

        if (hd_data->reply_msg_id != SRV_SMS_INVALID_MSG_ID)
        {
            srv_sms_set_reply_msg_id(srv_send_handle, hd_data->reply_msg_id);
        }

        if (hd_data->send_type == SRV_SMS_BG_SEND)
        {
            srv_sms_set_send_type(srv_send_handle, SRV_SMS_FG_SEND);
        }
        else
        {
            srv_sms_set_send_type(srv_send_handle, hd_data->send_type);
        }

        if (hd_data->send_info.curr_send_index + 1 < hd_data->send_info.total_num)
        {
           srv_sms_set_mms(srv_send_handle, MMI_TRUE/*hd_data->is_mms*/);/*cgxtst*/
           
        }
		else
		{
            srv_sms_set_mms(srv_send_handle, MMI_FALSE); /*cgxtst*/
        }

        if (spec_para & SRV_SMS_SPEC_SEND_WITHOUT_ICON)
        {
            srv_sms_set_no_sending_icon(srv_send_handle);
        }

        if (spec_para & SRV_SMS_SPEC_SEND_COUNTER_WITHOUT_CHANGE)
        {
            srv_sms_set_counter_without_change(srv_send_handle);
        }

        if (spec_para & SRV_SMS_SPEC_SEND_NOT_ALLOW_SC_EMPTY)
        {
            srv_sms_set_not_allow_empty_sc(srv_send_handle);
        }
    }
    srv_sms_send_msg(srv_send_handle, callback_func, (void*)cui_send_handle);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_msg_handle
 * DESCRIPTION
 *  Send message handle function
 * PARAMETERS
 *  result          [IN]    The Save Result
 *  data            [IN]    Dummy
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_send_msg_handle(cui_sms_result_enum result, void *data)
#if 1
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_finished = MMI_TRUE;
    srv_sms_callback_struct *callback_data = (srv_sms_callback_struct*) data;
    cui_sms_send_handle_struct *handle = (cui_sms_send_handle_struct*) callback_data->user_data;
    mmi_id sms_send_gid = handle->send_gid;
    cui_sms_send_handle_data_struct *hd_data = handle->data;
    cui_sms_send_info_struct *send_info = &(handle->data->send_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_info->send_result[send_info->curr_send_index] = result;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_MSG_HANDLE, result);
    {
        /* extract special cases from main switch to save code */
        MMI_ID string = 0;
        if (CUI_SMS_RESULT_NOT_READY == result)
        {
            string = STR_SMS_MSG_NOT_READY_YET;
        }
        else if ((CUI_SMS_RESULT_DATA_EXCEED == result))
        {
            string = STR_SMS_FAILURE_MSG_LEN_EXCEEDED;
        }
        else if (CUI_SMS_RESULT_MEM_FULL == result)
        {
            /* Aborting the last messages */
            if (send_info->is_aborting == MMI_TRUE)
            {
                mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_ABORT_SENDING);
            }
            string = STR_GLOBAL_MEMORY_FULL;
        }
        else if (CUI_SMS_CAUSE_ERROR_FDN_ENABLED == result)
        {
            string = STR_ID_SMS_FDN_FAIL;
        }
        if (0 != string)
        {
            cui_sms_send_evt_send_to_parent(sms_send_gid, MMI_TRUE, result);
            cui_sms_display_popup_ext(
              (string),
              MMI_EVENT_FAILURE);
            return;
        }
        
    }
    switch (result)
    {
        case CUI_SMS_RESULT_OK:
        case CUI_SMS_RESULT_ERROR:
        case CUI_SMS_RESULT_SENT_AND_SAVED:
        case CUI_SMS_RESULT_SENT_BUT_SAVE_FAIL:
        case CUI_SMS_RESULT_SEND_FAIL_BUT_SAVED:
        case CUI_SMS_RESULT_SEND_FAIL_AND_SAVE_FAIL:
        {
            if ((send_info->curr_send_index + 1) < send_info->total_num)
            {
                 send_info->curr_send_index++;

            #ifdef __MMI_MESSAGES_SMS_EMAIL__
                if ((hd_data->pid == SRV_SMS_PID_EMAIL)
                    && ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) == SRV_SMS_PARA_CONTENT_EMS))
                {
                    EMSData *edit_ems_data;
                    U16 addr_length = 0;
                    edit_ems_data = hd_data->content_ems;
                    
            		mmi_msg_get_email_and_subject_from_msgtxt(
                        (S8 *)edit_ems_data->textBuffer,
                        edit_ems_data->textLength,
            			NULL,
            			(MMI_SMS_MAX_EMAIL_ADDR_LEN * ENCODING_LENGTH),
            			NULL,
            			0,
            			&addr_length, 
            			NULL);
                    
                    mmi_msg_remove_email_address_from_msgtxt(edit_ems_data, addr_length);
                }
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

                if (send_info->is_aborting == MMI_TRUE)
                {
                    cui_sms_display_popup_ext(
                        (STR_ID_SMS_CANCELLED),
                        MMI_EVENT_SUCCESS);

                #ifdef __MMI_DUAL_SIM_MASTER__
                    hd_data->para_flag &= (~SRV_SMS_PARA_SIM_ID);
                    hd_data->sim_id = 0;
                #endif

                {
                    MMI_BOOL is_recipient_editor_present = 
                                mmi_frm_scrn_is_present(
                                                    sms_send_gid, 
                                                    SCR_ID_SMS_ADD_RECIPIENT, 
                                                    MMI_FRM_NODE_ALL_FLAG);
                    cui_sms_send_evt_send_to_parent(sms_send_gid, !is_recipient_editor_present, CUI_SMS_RESULT_CANCEL);
                }
                    mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_ABORT_SENDING);
                    mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_SENDING);
                }
                else
                {
                    is_finished = MMI_FALSE;
                    cui_sms_send_evt_send_to_parent(sms_send_gid, MMI_FALSE, result);

                    cui_sms_send_curr_msg(sms_send_gid);
                }
            }
            else
            {
                U16 body_str_id;
                mmi_event_notify_enum event_id;
            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                MMI_BOOL is_show_popup = MMI_TRUE;

                is_show_popup = cui_sms_get_send_finish_popup_info(handle, &body_str_id, &event_id);

                if (is_show_popup == MMI_TRUE)
                {
                    cui_sms_display_popup_ext(
                        (body_str_id),
                        event_id);
                }
                else if (hd_data->send_type == SRV_SMS_BG_SAVE_SEND)
                {
                    mmi_popup_property_struct arg;
                    mmi_popup_property_init(&arg);
                    arg.msg_icon = 0;
                     #ifndef __MMI_BASIC_UI_STYLE__
                    arg.msg_icon = IMG_NEW_SMS_SEND;
		    #endif
                    
                    mmi_popup_display_ext(STR_GLOBAL_SENDING, MMI_EVENT_PROGRESS, &arg);  
                }

            #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
            #ifdef __MMI_MESSAGES_SMS_EMAIL__
                if (hd_data->pid == SRV_SMS_PID_DEFAULT)
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
                {
                    cui_sms_phb_save_contact(hd_data->send_info.recipient, hd_data->send_info.total_num);
                }
            #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */

                /* If there is a UC editor, and it may save it content by use the EMS Edit Buffer,
                 *  so don't release it, otherwise, it may save a emty message to Drafts.
                 */

                /* Aborting the last messages */
                if (send_info->is_aborting == MMI_TRUE)
                {
                    mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_ABORT_SENDING);
                }

                /* send evt to parent group */
                cui_sms_send_evt_send_to_parent(sms_send_gid, MMI_TRUE, result);
            #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

                cui_sms_get_send_finish_popup_info(handle, &body_str_id, &event_id);

                cui_sms_display_popup_ext(
                    (body_str_id),
                    event_id);

                if (send_info->is_aborting == MMI_TRUE)
                {
                    mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_ABORT_SENDING);
                }

            #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
            #ifdef __MMI_MESSAGES_SMS_EMAIL__
                if (hd_data->pid == SRV_SMS_PID_DEFAULT)
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
                {
                    cui_sms_phb_save_contact(hd_data->send_info.recipient, hd_data->send_info.total_num);
                }
            #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */

                cui_sms_send_evt_send_to_parent(sms_send_gid, MMI_TRUE, result);
            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
            }

            break;
        }
        case CUI_SMS_RESULT_CANCEL:
        {
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            if ((hd_data->pid == SRV_SMS_PID_EMAIL)
                && ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) == SRV_SMS_PARA_CONTENT_EMS))
            {

                EMSData *edit_ems_data;
                U16 addr_length = 0;
                edit_ems_data = hd_data->content_ems;
                
                mmi_msg_get_email_and_subject_from_msgtxt(
                    (S8 *)edit_ems_data->textBuffer,
                    edit_ems_data->textLength,
                    NULL,
                    (MMI_SMS_MAX_EMAIL_ADDR_LEN * ENCODING_LENGTH),
                    NULL,
                    0,
                    &addr_length, 
                    NULL);
                
                mmi_msg_remove_email_address_from_msgtxt(edit_ems_data, addr_length);
            }
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

            cui_sms_display_popup_ext(
                (STR_ID_SMS_CANCELLED),
                MMI_EVENT_SUCCESS);

        #ifdef __MMI_DUAL_SIM_MASTER__
            hd_data->para_flag &= (~SRV_SMS_PARA_SIM_ID);
            hd_data->sim_id = 0;
        #endif
            {
                MMI_BOOL is_recipient_editor_present = 
                            mmi_frm_scrn_is_present(
                                                sms_send_gid, 
                                                SCR_ID_SMS_ADD_RECIPIENT, 
                                                MMI_FRM_NODE_ALL_FLAG);
                cui_sms_send_evt_send_to_parent(sms_send_gid, !is_recipient_editor_present, CUI_SMS_RESULT_CANCEL);

                mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_ABORT_SENDING);
                mmi_frm_scrn_close(sms_send_gid, SCR_ID_SMS_SENDING);
                break;
            }
        }
        default:
            break;
    }
    if (is_finished == MMI_TRUE)
    {
        send_info->is_sending = MMI_FALSE;
    }
    
}
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_MESSAGES_SMS_EMAIL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                           #ifndef __MMI_BASIC_UI_STYLE__
/* under construction !*/
			#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
            #ifdef __MMI_MESSAGES_SMS_EMAIL__
/* under construction !*/
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
            #ifdef __MMI_MESSAGES_SMS_EMAIL__
/* under construction !*/
            #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */
/* under construction !*/
/* under construction !*/
            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_MESSAGES_SMS_EMAIL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_msg_req
 * DESCRIPTION
 *  Send Msg Request
 * PARAMETERS
 *  req_data        [IN]    Send Request Data
 *  callback_func   [IN]    Callback Function
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_save_msg_req(cui_sms_send_handle_struct *cui_send_handle, srv_sms_status_enum set_status, SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_send_handle_data_struct *data = cui_send_handle->data;
    SMS_HANDLE srv_save_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SAVE_AFTER_SEND, set_status);

    srv_save_handle = srv_sms_get_save_handle();

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_NUMBER)
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    {
        S8 ucs2_addr[(SRV_SMS_MAX_ADDR_LEN + 1) *ENCODING_LENGTH];
        mmi_asc_n_to_ucs2(ucs2_addr, data->send_info.recipient[data->send_info.curr_send_index], SRV_SMS_MAX_ADDR_LEN);
        srv_sms_set_address(srv_save_handle, ucs2_addr);
    }
    srv_sms_set_status(srv_save_handle, set_status);
    cui_sms_set_common_para(data, srv_save_handle);
    cui_sms_send_evt_send_to_parent_internal_ext(cui_send_handle->send_gid, EVT_ID_CUI_SMS_SEND_START_SAVING, MMI_FALSE, CUI_SMS_RESULT_SAVE_TO_DRAFTS, MMI_FALSE);
    srv_sms_save_msg(srv_save_handle, callback_func, (void*)cui_send_handle);
}


static void cui_sms_set_common_para(
            cui_sms_send_handle_data_struct *data, 
            SMS_HANDLE srv_save_handle)
{
    
    srv_sms_para_enum para_flag = data->para_flag;
    if (para_flag & SRV_SMS_PARA_DCS)
    {
        srv_sms_set_content_dcs(srv_save_handle, data->dcs);
    }

    if (para_flag & SRV_SMS_PARA_CONTENT_EMS)
    {
        srv_sms_set_content_ems(srv_save_handle, (void*)data->content_ems);
    }
    else if (para_flag & SRV_SMS_PARA_CONTENT_BUFF)
    {
        srv_sms_set_content(srv_save_handle, data->content_buff, data->content_buff_size);
    }
    else if (para_flag & SRV_SMS_PARA_CONTENT_FILE)
    {
        srv_sms_set_content_file(srv_save_handle, data->content_file_path);
    }

    if (para_flag & SRV_SMS_PARA_SIM_ID)
    {
        srv_sms_set_sim_id(srv_save_handle, data->sim_id);
    }

    if (data->spec_para & SRV_SMS_SPEC_SEND_PID)
    {
        srv_sms_set_pid(srv_save_handle, data->pid);
    }

}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_send_finish_popup_info
 * DESCRIPTION
 *  Get the popup information for sending fininsh notification  
 * PARAMETERS
 *  body_str_id     [IN] Body string ID Pointer
 *  image_id        [IN] Image ID Pointer
 *  tone_id         [IN] Tone ID Pointer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL cui_sms_get_send_finish_popup_info(cui_sms_send_handle_struct *handle, U16 *body_str_id, mmi_event_notify_enum *event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 sent_num = 0;
    U16 sent_but_save_fail_num = 0;
    U16 send_fail_but_saved_num = 0;
    U16 send_fail_and_save_fail_num = 0;
    U16 send_fail_num = 0;
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    MMI_BOOL is_show_popup = MMI_TRUE;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    cui_sms_send_handle_data_struct *hd_data = handle->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < hd_data->send_info.total_num; i++)
    {
        cui_sms_result_enum send_result = hd_data->send_info.send_result[i];

        switch (send_result)
        {
            case CUI_SMS_RESULT_OK:
                sent_num++;
                break;

            case CUI_SMS_RESULT_SENT_AND_SAVED:
                sent_num++;
                break;

            case CUI_SMS_RESULT_SENT_BUT_SAVE_FAIL:
                sent_but_save_fail_num++;
                break;

            case CUI_SMS_RESULT_SEND_FAIL_BUT_SAVED:
                send_fail_but_saved_num++;
                break;

            case CUI_SMS_RESULT_SEND_FAIL_AND_SAVE_FAIL:
                send_fail_and_save_fail_num++;
                break;

            case CUI_SMS_RESULT_ERROR:
                send_fail_num++;
                break;
            
            default:
                MMI_ASSERT(0);
                break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_SEND_FINISH_POPUP_INFO, sent_num, send_fail_num);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_SEND_FINISH_POPUP_INFO_1, send_fail_but_saved_num, send_fail_and_save_fail_num);

    /* Don't need to save send failed message case */
    if (send_fail_num > 0)
    {
        *body_str_id = STR_GLOBAL_FAILED_TO_SEND;
        *event_id = MMI_EVENT_PROPLEM;
    }
    else if (sent_num == hd_data->send_info.total_num)           
    {
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        if ((handle->send_msg_case == CUI_SMS_SEND_CASE_SEND_FROM_OTHER_APP)
            || (handle->send_msg_case == CUI_SMS_SEND_CASE_SEND_DATA_MSG)
            || (hd_data->send_type != SRV_SMS_BG_SAVE_SEND))
        {
            *body_str_id = STR_GLOBAL_SENT;
            *event_id = MMI_EVENT_MESSAGE_SENT;
        }
        else
        {
            is_show_popup = MMI_FALSE;
        }
    #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        *body_str_id = STR_GLOBAL_SENT;
        *event_id = MMI_EVENT_MESSAGE_SENT;
    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    }
    else if ((sent_num + sent_but_save_fail_num) == hd_data->send_info.total_num)
    {
        *body_str_id = STR_SMS_SEND_SUCESS_SAVE_FAILED;
        *event_id = MMI_EVENT_MESSAGE_SENT;
    }
    else if ((sent_num + send_fail_but_saved_num) == hd_data->send_info.total_num)
    {
        *body_str_id = STR_UM_SEND_FAILED_SAVE_SUCCESS_ID;
        *event_id = MMI_EVENT_PROPLEM;
    }
    else
    {
        *body_str_id = STR_SMS_SEND_SAVE_FAILED;
        *event_id = MMI_EVENT_PROPLEM;
    }

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    return is_show_popup;
#else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    return MMI_TRUE;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

}


#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_phb_save_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  asc_num      [IN]   if it set to NULL, means send to many
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_phb_save_contact(S8 **ascii_addr_list, U16 addr_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SAVE_CONTACT_TO_PHB);
    if (mmi_phb_is_save_contact_notify_on())
    {
        U16 i;

        for (i = 0; i < addr_count; i++)
        {
            S8 ucs2_num[(MMI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];

            mmi_asc_to_ucs2(ucs2_num, ascii_addr_list[i]);

            if (mmi_phb_is_num_in_phb((U16*)ucs2_num) == MMI_FALSE)
            {
                srv_phb_contact_data_struct phb_data;

                mmi_phb_unsaved_data_init(&phb_data);

                phb_data.number = (U16 *)ucs2_num;

                mmi_phb_add_data_to_unsaved_list(PHB_STORAGE_MAX, SRV_PHB_ENTRY_FIELD_NUMBER, &phb_data);
            }

            if (mmi_phb_get_unsaved_data_num() > 0)
            {
                mmi_phb_add_unsaved_data_confirm_to_history();
            }
        }
    }
}
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_sending
 * DESCRIPTION
 *  Entry sending SMS screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *caption_str;
    mmi_id sms_send_gid;
    U16 img_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTRY_SENDING_SCEN, sms_send_gid);

    if (mmi_frm_scrn_enter(
            sms_send_gid,
            SCR_ID_SMS_SENDING,
            NULL,
            cui_sms_entry_sending,
            MMI_FRM_SMALL_SCRN))
    {
        MMI_ID rsk_str_id = STR_GLOBAL_CANCEL;

        cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);

        if (hd_data->send_type == SRV_SMS_BG_SAVE_SEND)
        {
            rsk_str_id = 0;
        }

        caption_str = cui_sms_get_sending_caption(sms_send_gid);
         #ifndef __MMI_BASIC_UI_STYLE__
        img_id = IMG_NEW_SMS_SEND;
        #endif
        ShowCategory66Screen(
            0, /*STR_GLOBAL_SENDING, */
            0, /* IMG_SMS_ENTRY_SCRN_CAPTION, */
            0,
            0,
            rsk_str_id,
            IMG_SMS_COMMON_NOIMAGE,
            caption_str,
            img_id,
            NULL);

        if (hd_data->send_type != SRV_SMS_BG_SAVE_SEND)
        {
            SetRightSoftkeyFunction(cui_sms_abort_send_msg, KEY_EVENT_UP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_abort_sending
 * DESCRIPTION
 *  Entry abort sending SMS screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_abort_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr end_key_func;
    U16 image_id;
    mmi_id sms_send_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_ENTRY_ABORT_SENDING_SCRN, sms_send_gid);

    if (mmi_frm_scrn_enter(
            sms_send_gid,
            SCR_ID_SMS_ABORT_SENDING,
            NULL,
            cui_sms_entry_abort_sending,
            MMI_FRM_SMALL_SCRN))
    {
        image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);

        ShowCategory8Screen(
            0, /* STR_GLOBAL_CANCELLING, */
            0, /* IMG_SMS_ENTRY_SCRN_CAPTION, */
            0,
            0,
            0,
            0,
            STR_GLOBAL_PLEASE_WAIT,
            image_id,
            NULL);

        end_key_func = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);

        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
        {
            SetKeyHandler(end_key_func, KEY_END, KEY_EVENT_DOWN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_sending_caption
 * DESCRIPTION
 *  Get the sending screen's body string
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static U8* cui_sms_get_sending_caption(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ucs2_num[CUI_SMS_MAX_ADDR_LEN + 1];
    S8 temp_ucs2_buff[3 * ENCODING_LENGTH];
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);
    U8 *sending_caption_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_SENDING_CAPTION, sms_send_gid, hd_data);

    if (hd_data->send_info.sending_caption_buff == NULL)
    {
        hd_data->send_info.sending_caption_buff = OslMalloc((CUI_SMS_MAX_SENDING_CAPTION_LEN + 1) * ENCODING_LENGTH);
    }

    sending_caption_buff = hd_data->send_info.sending_caption_buff;

    if (hd_data->sending_str_id != 0)
    {
        mmi_ucs2cpy((S8*)sending_caption_buff, (S8*)GetString(hd_data->sending_str_id));
    }
    else if (hd_data->send_type == SRV_SMS_BG_SAVE_SEND)
    {
        mmi_ucs2cpy((S8*)sending_caption_buff, (S8*)GetString(STR_GLOBAL_SENDING));  
    }
    else
    {
        mmi_ucs2cpy((S8*)sending_caption_buff, (S8*)GetString(STR_ID_SMS_SENDING_TO_CAPTION));

        mmi_asc_to_ucs2(temp_ucs2_buff, (S8*)"\n");

        mmi_ucs2cat((S8*)sending_caption_buff, temp_ucs2_buff);

        mmi_asc_to_ucs2((S8*)ucs2_num, hd_data->send_info.recipient[hd_data->send_info.curr_send_index]);

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (hd_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
        {
            mmi_ucs2cat((S8*)sending_caption_buff, (S8*)ucs2_num);
        }
        else
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
        {
            U16 name[MMI_PHB_NAME_LENGTH + 1];

            srv_phb_get_name_by_number(ucs2_num, name, MMI_PHB_NAME_LENGTH);

            if (!mmi_ucs2strlen((S8*)name))
            {
                mmi_ucs2cat((S8*)sending_caption_buff, (S8*)ucs2_num);
            }
            else
            {
                name[MMI_PHB_NAME_LENGTH] = 0;
                mmi_ucs2cat((S8*)sending_caption_buff, (S8*)name);
            }
        }
    }

    return sending_caption_buff;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_update_sending_caption
 * DESCRIPTION
 *  Update the sending screen's body
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_update_sending_caption(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_UPDATE_SENDING_CAPTION);

    if ((sms_send_gid == mmi_frm_group_get_active_id())
        ||(SCR_ID_SMS_SENDING == mmi_frm_scrn_get_active_id())
        )
    {
        cui_sms_get_sending_caption(sms_send_gid);
        cat66_update_progress_string();
    }
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_select_sim_leaf_item
 * DESCRIPTION
 *  Entry Send SIM Card Select Options Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_set_send_select_sim_leaf_item(MMI_ID cui_menu_gid, MMI_MENU_ID menu_id, srv_sms_para_enum para_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
	U8 menuitems = 0;
    MMI_BOOL if_need_to_set_leaf;    /* MMI_TRUE means do not need to show submenu */
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < MMI_SIM_TOTAL; ++i)
	{
        if (srv_nw_usab_is_usable(mmi_frm_index_to_sim(i)))
        {
            ++menuitems;
        }
    }
    /* if only one sim avaible or certain SIM is assigned, no need to show submenu */
    if_need_to_set_leaf = (menuitems < 2) || (para_flag & SRV_SMS_PARA_SIM_ID);
    /* set non leaf, means to show submenu */
    cui_menu_set_non_leaf_item(cui_menu_gid, menu_id, !if_need_to_set_leaf);
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}

#ifndef __MMI_UNIFIED_COMPOSER__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_select_sim_leaf_item
 * DESCRIPTION
 *  Entry Send SIM Card Select Options Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_set_save_select_sim_leaf_item(MMI_ID cui_menu_gid, MMI_MENU_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sim_menu_item[MMI_SIM_TOTAL] = {
         MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM1
        ,MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM2
#if (MMI_MAX_SIM_NUM >= 3)        
        ,MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM3
#if (MMI_MAX_SIM_NUM >= 4)
        ,MENU_ID_SMS_RECIPIENT_SAVE_OPT_BY_SIM4
#endif
#endif
        };
	U8 menuitems = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if (MMI_MAX_SIM_NUM >= 2)
    #ifndef __UNIFIED_COMPOSER_SUPPORT__
    {
        S32 i = 0;
        MMI_BOOL is_sim_valid;
        for (; i < MMI_SIM_TOTAL; ++i)
    	{
            is_sim_valid = srv_nw_usab_is_usable(mmi_frm_index_to_sim(i));
            if (is_sim_valid)
            {
                ++menuitems;
            }
            /* hide menu if sim is not avaiable */
            cui_menu_set_non_leaf_item(cui_menu_gid, sim_menu_item[i], !is_sim_valid);
        }
    }
    #endif /* __UNIFIED_COMPOSER_SUPPORT__ */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    /* if more than one sim usable, non-leaf menu, use submenu */
    cui_menu_set_non_leaf_item(cui_menu_gid, menu_id, (menuitems >= 2));
}
#endif /* __MMI_UNIFIED_COMPOSER__ */


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_send_select_sim_options
 * DESCRIPTION
 *  Entry Send SIM Card Select Options Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_send_select_sim_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    mmi_id sms_send_gid;
#ifdef __MMI_DUAL_SIM_MASTER__
    cui_sms_send_handle_struct *send_hd;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();
#ifdef __MMI_DUAL_SIM_MASTER__
    send_hd = cui_sms_get_send_handle(sms_send_gid);
    send_hd->is_direct_send = MMI_TRUE;
#endif

    menu_cui_gid = cui_menu_create(
                        sms_send_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,
                        MENU_ID_SMS_RECIPIENT_OPT_SEND,
                        MMI_FALSE,
                        NULL);

    cui_menu_set_default_title_by_id(
        menu_cui_gid,
        STR_GLOBAL_SEND,
        IMG_SMS_ENTRY_SCRN_CAPTION);

    /* cui_menu_enable_cascading_option_menu(menu_cui_gid); */
    cui_menu_set_default_left_softkey_by_id(menu_cui_gid, STR_GLOBAL_SELECT);
    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_opt_send_by_sim
 * DESCRIPTION
 *  Send Msg By SIM1
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_opt_send_by_sim(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_sms_set_send_sim_type(sim_id);
    cui_sms_pre_send_msg();
}


#if  (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_opt_send_by_sim3
 * DESCRIPTION
 *  Send Msg By SIM2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_opt_send_by_sim3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_MULTI_SIM_SEND_BY_SIM2);

    cui_sms_set_send_sim_type(SRV_SMS_SIM_3);
    cui_sms_pre_send_msg();
}
#endif


#if  (MMI_MAX_SIM_NUM >= 4)
/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_opt_send_by_sim4
 * DESCRIPTION
 *  Send Msg By SIM2
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_opt_send_by_sim4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_MULTI_SIM_SEND_BY_SIM2);

    cui_sms_set_send_sim_type(SRV_SMS_SIM_4);
    cui_sms_pre_send_msg();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_sms_dm_pre_send_msg
 * DESCRIPTION
 *  Pre Send Msg In the Dual SIM Version
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void cui_sms_dm_pre_send_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;
    cui_sms_send_handle_data_struct *hd_data;
    MMI_BOOL need_select_sim = MMI_TRUE;
    mmi_sim_enum sim_to_use = MMI_SIM_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_MULTI_SIM_SEND_MSG);

    sms_send_gid = cui_sms_get_active_send_gid();
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_MULTI_SIM_SEND_MSG_1, sms_send_gid);
    hd_data = cui_sms_get_send_handle_data(sms_send_gid);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_MULTI_SIM_SEND_MSG_2, hd_data);

    if (hd_data->sim_id == 0) /* no sim is set */
    {
        S32 usable_sim_amount = 0;
        S32 i = 0;
        for (; i < MMI_SIM_TOTAL; ++i)
        {
            
            mmi_sim_enum current_sim = mmi_frm_index_to_sim(i);
            /* detect how many sim is avaiable */
            if (srv_nw_usab_is_usable(current_sim))
            {   
                sim_to_use = current_sim;
                ++usable_sim_amount;
            }
        }
        if (1 == usable_sim_amount)/* only one sim avaible, do not need to select */
        {
            need_select_sim = MMI_FALSE;
        }
    }
    else
    {       
        S32 i = 0;
        for (; i < MMI_SIM_TOTAL; ++i)
        {
            sim_to_use = (mmi_frm_index_to_sim(i));
            if (srv_nw_usab_is_usable(mmi_frm_index_to_sim(i)))
            {
                if (SRV_SMS_SMS_SIM_TO_MMI(hd_data->sim_id) == sim_to_use)
                {
                    need_select_sim = MMI_FALSE;
                    break;
                }
            }
        }
    }
    if (need_select_sim)
    {
        cui_sms_entry_send_select_sim_options();
    }
    else
    {
        cui_sms_recipient_opt_send_by_sim(SRV_SMS_MMI_SIM_TO_SMS(sim_to_use));
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_sim_type
 * DESCRIPTION
 *  Set the SIM Type for Sending
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_set_send_sim_type(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SET_SIM_TYPE, sim_id);

    sms_send_gid = cui_sms_get_active_send_gid();
    hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    hd_data->para_flag |= SRV_SMS_PARA_SIM_ID;
    hd_data->sim_id = sim_id;
}


#endif /* __MMI_DUAL_SIM_MASTER__ */


#ifdef __EMS_DYNAMIC_SEG_NUM__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_check_dynamic_seg_num
 * DESCRIPTION
 *  Entry Check dynamic seg num
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL cui_sms_entry_check_dynamic_seg_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 segment_num;
    EMSData *edit_ems_data;
    MMI_BOOL is_send_directly = MMI_FALSE;
    MMI_BOOL result = MMI_FALSE;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    U8 orignal_segment = 0;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    mmi_id sms_send_gid;
    cui_sms_send_handle_struct *handle;
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_CHECK_SEG_NUM);

    sms_send_gid = cui_sms_get_active_send_gid();

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_CHECK_SEG_NUM_1, sms_send_gid);

    handle = cui_sms_get_send_handle(sms_send_gid);
    hd_data = handle->data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_CHECK_SEG_NUM_2, hd_data);

    /* If not EMSdata, need pack to EMSdata for check */
    if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) == SRV_SMS_PARA_CONTENT_EMS)
    {
        edit_ems_data = hd_data->content_ems;
    }
    else
    {
        MMI_BOOL result;
        edit_ems_data = (EMSData*)srv_sms_malloc_ems_data();

        if (edit_ems_data == NULL)
        {
            MMI_ASSERT(0);
        }

        result = cui_sms_convert_send_content_to_emsdata(handle, edit_ems_data);

        if (result == MMI_FALSE)
        {
            if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) != SRV_SMS_PARA_CONTENT_EMS)
            {
                if (edit_ems_data != NULL)
                {
                    srv_sms_free_ems_data((void*)edit_ems_data);
                }
            }
            return MMI_TRUE;
        }
    }

    /* Sending Directly Case */
    if (mmi_frm_scrn_is_present(sms_send_gid, SCR_ID_SMS_ADD_RECIPIENT, MMI_FRM_NODE_ALL_FLAG) == MMI_FALSE)
    {
        is_send_directly = MMI_TRUE;

        if ((edit_ems_data->dcs == SMSAL_UCS2_DCS) &&
            (srv_sms_check_ucs2((S8*)edit_ems_data->textBuffer, (U16)(edit_ems_data->textLength >> 1)) == MMI_FALSE))
        {
            EMSSetDCS(edit_ems_data, SMSAL_DEFAULT_DCS);
        }
    }

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (hd_data->pid == SRV_SMS_PID_EMAIL)
    {
        orignal_segment =  edit_ems_data->Reminder.requiredSegment;

        segment_num = cui_sms_get_edit_email_sms_segment_num(edit_ems_data, hd_data);
    }
    else
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    {
        segment_num = edit_ems_data->Reminder.requiredSegment;
    }

    if (segment_num > 1)
    {
        if ((is_send_directly == MMI_TRUE) && 
            (srv_sms_is_long_sms_dynamic_seg_setting(hd_data->sim_id) == FALSE))
        {
            if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) != SRV_SMS_PARA_CONTENT_EMS)
            {
                if (edit_ems_data != NULL)
                {
                    srv_sms_free_ems_data((void*)edit_ems_data);
                }
            }

        #ifdef __MMI_MESSAGES_SMS_EMAIL__
            if ((hd_data->pid == SRV_SMS_PID_EMAIL) && (orignal_segment == 1))
            {
                popup_result = CUI_SMS_RESULT_EMAIL_NO_SPACE;

                cui_sms_display_popupcallback_sg_ext(
                    sms_send_gid,
                    STR_SMS_EMAIL_NO_SPACE,
                    MMI_EVENT_FAILURE,
                    cui_sms_entry_cur_send_scrn_fail_proc,
                    NULL,
                    0);
            }
            else
        #endif /* __MMI_MESSAGES_SMS_EMAIL__ */
            {
                popup_result = CUI_SMS_RESULT_DATA_EXCEED;

                cui_sms_display_popupcallback_sg_ext(
                    sms_send_gid,
                    STR_SMS_FAILURE_DATA_EXCEED,
                    MMI_EVENT_FAILURE,
                    cui_sms_entry_cur_send_scrn_fail_proc,
                    NULL,
                    0);
            }
        }
        else
        {
            cui_sms_entry_long_msg_confirm(sms_send_gid, segment_num);
        }

        result = MMI_TRUE;
    }

    if ((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) != SRV_SMS_PARA_CONTENT_EMS)
    {
        if (edit_ems_data != NULL)
        {
            srv_sms_free_ems_data((void*)edit_ems_data);
        }
    }

    return result;
}


#ifdef __MMI_MESSAGES_SMS_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_edit_email_sms_segment_num
 * DESCRIPTION
 *  get the segment number from the EMS data of the Email SMS
 * PARAMETERS
 *  edit_ems        [IN]    Edit EMS Data       
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 cui_sms_get_edit_email_sms_segment_num(EMSData *edit_ems, cui_sms_send_handle_data_struct *hd_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 segment_num;
    U16 i;
    S8 addr_buff[(CUI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    S8 *max_addr = NULL;
    U16 max_addr_len = 0;
    EMSPosition position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_GET_EMAIL_SMS_SEGMENT_NUM, hd_data);

    for (i = 0; i < hd_data->total_num; i++)
    {
        S8 *addr = hd_data->recipient[i];
        U16 addr_len = (U16)strlen(addr);
    
        if (addr_len > max_addr_len)
        {
            max_addr = addr;
            max_addr_len = addr_len;
        }
    }

    position = edit_ems->CurrentPosition;

    mmi_asc_to_ucs2(addr_buff, max_addr);

    /* add the email address to the ems edit buffer to count the total segment */
    ResetCurrentPosition(edit_ems);
    AddString(edit_ems, (U8*)addr_buff, max_addr_len, NULL);
    AddString(edit_ems, (U8*)L" ", 1, NULL);

    /* Get the segment total number */
    segment_num = edit_ems->Reminder.requiredSegment;

    /* Restore */
    ResetCurrentPosition(edit_ems);
	ForwardCurrentPosition(edit_ems, (U16)(max_addr_len + 1));			
	CancelCurrentPosition(edit_ems, (U16)(max_addr_len + 1));
    MoveCursorToPosition(edit_ems, &position);

    return segment_num;
}
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_long_msg_confirm
 * DESCRIPTION
 *  Entry Long Msg Confirm Screen
 * PARAMETERS
 *  segment_num     [IN]    Segment Number
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_long_msg_confirm(mmi_id sms_send_gid, U8 segment_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *confirm_str_buff;
    S8 asc_str[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_LONG_MSG_CONFIRM);

    confirm_str_buff = OslMalloc(CUI_SMS_MAX_COMFIRM_LEN * ENCODING_LENGTH);

    sprintf(asc_str, "%d", segment_num);
    mmi_asc_to_ucs2(confirm_str_buff, asc_str);

    mmi_ucs2cat(confirm_str_buff, (S8*)GetString(STR_ID_SMS_SEND_LONG_MSG_QUERY_ID));

    cui_sms_entry_confirm_sg_ext(
        sms_send_gid,
        (WCHAR*)confirm_str_buff,
        cui_sms_send_msg_interal,
        cui_sms_goback_from_cur_send_proc);

    OslMfree(confirm_str_buff);
}
#endif /* __EMS_DYNAMIC_SEG_NUM__ */ 


#if (MMI_MAX_SIM_NUM == 1)
/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_opt_send
 * DESCRIPTION
 *  "Send" (Add Recipient Options)item LSK Handler Funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_opt_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_RECIPIENT_OPT_SEND);

    cui_sms_pre_send_msg();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_opt_edit
 * DESCRIPTION
 *  "Edit recipient" (Add Recipient Options) item LSK Handler Funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_opt_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_send_gid = cui_sms_get_active_send_gid();

    cui_sms_edit_curr_recipient(sms_send_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_opt_remove
 * DESCRIPTION
 *  "Remove recipient" (Add Recipient Options) item LSK Handler Funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_opt_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_entry_confirm(
        sms_send_gid,
        STR_ID_SMS_REMOVE_RECIPIENT_QUERY,
        cui_sms_recipient_pre_remove,
        cui_sms_goback_from_cur_send_proc,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_pre_remove
 * DESCRIPTION
 *  "Remove recipient" (Add Recipient Options) item LSK Handler Funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_pre_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_remove_curr_recipient(hd_data);

    if (hd_data->total_num == 0)
    {
        hd_data->recipient_info.highlihgt_index = DEFAULT_HILITE_WITHOUT_RECIPIENT;
    }
    else
    {
        /* Remove the last recipient */
        if (hd_data->recipient_info.highlihgt_index == (hd_data->total_num + ITEM_NUM_ABOVE_LINE))
        {
            hd_data->recipient_info.highlihgt_index--;
        }
    }

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_opt_remove_all
 * DESCRIPTION
 *  "Remove all recipient" (Add Recipient Options) item LSK Handler Funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_opt_remove_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_entry_confirm(
        sms_send_gid,
        STR_ID_SMS_REMOVE_ALL_RECIPIENT_QUERY,
        cui_sms_recipient_pre_remove_all,
        cui_sms_goback_from_cur_send_proc,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_pre_remove_all
 * DESCRIPTION
 *  "Remove all recipient" (Add Recipient Options) item LSK Handler Funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_pre_remove_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_remove_all_recipient(hd_data);

    hd_data->recipient_info.highlihgt_index = DEFAULT_HILITE_WITHOUT_RECIPIENT;

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_recipient_opt_save_to_drafts
 * DESCRIPTION
 *  "Save to Drafts" (Add Recipient Options) item LSK Handler Funciton
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_recipient_opt_save_to_drafts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_save_gid;
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_struct *handle = cui_sms_get_send_handle(sms_send_gid);
    cui_sms_send_handle_data_struct *hd_data = handle->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(hd_data != NULL);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SAVE_TO_DRAFT, hd_data);

    sms_save_gid = cui_sms_save_create(sms_send_gid);

    if(sms_save_gid != GRP_ID_INVALID)
    {
        handle->child_gid = sms_save_gid;

        if((hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS) == SRV_SMS_PARA_CONTENT_EMS)
        {
            cui_sms_set_save_content_ems(sms_save_gid, hd_data->content_ems);
        }
        else if((hd_data->para_flag & SRV_SMS_PARA_CONTENT_BUFF) == SRV_SMS_PARA_CONTENT_BUFF)
        {
            cui_sms_set_save_content_text(sms_save_gid, (U16*)hd_data->content_buff, hd_data->content_buff_size);
        }
        else if((hd_data->para_flag & SRV_SMS_PARA_CONTENT_FILE) == SRV_SMS_PARA_CONTENT_FILE)
        {
            cui_sms_set_save_content_text_file(sms_save_gid, (U16*)hd_data->content_file_path);
        }

        cui_sms_set_save_msg_status(sms_save_gid, SRV_SMS_STATUS_DRAFT);

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (hd_data->para_flag & SRV_SMS_PARA_PID)
        {
            cui_sms_set_save_pid(sms_save_gid, SRV_SMS_PID_EMAIL);
        }
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    if (hd_data->para_flag & SRV_SMS_PARA_SIM_ID)
    {
        cui_sms_set_save_sim_id(sms_save_gid, hd_data->sim_id);
    }
#ifdef __OP01__
    if (mmi_ucs2strlen((const CHAR *)hd_data->recipient[0]))
    {
        WCHAR ucs2_address[CUI_SMS_MAX_ADDR_LEN + 1] = { 0 };
        mmi_asc_n_to_ucs2((CHAR *)ucs2_address, ((CHAR *)hd_data->recipient[0]), CUI_SMS_MAX_ADDR_LEN);
        cui_sms_set_save_address(sms_save_gid, (U16 *)ucs2_address);
    }
#endif
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        cui_sms_set_save_title_id(sms_save_gid, STR_SMS_SAVE_TO_DRAFTS_MENU_ITEM);
    #else /*__MMI_MESSAGES_DRAFT_BOX__*/
        cui_sms_set_save_title_id(sms_save_gid, STR_GLOBAL_SAVE);
    #endif /*__MMI_MESSAGES_DRAFT_BOX__*/

        cui_sms_save_run(sms_save_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_edit_curr_recipient
 * DESCRIPTION
 *  Edit the Current Highlight Recipient
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_edit_curr_recipient(mmi_id sms_send_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ucs2_addr[(MMI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    U16 max_addr_len;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    cui_sms_send_handle_data_struct *hd_data = cui_sms_get_send_handle_data(sms_send_gid);
    U16 edit_index = hd_data->recipient_info.highlihgt_index - ITEM_NUM_ABOVE_LINE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_EDIT_CURR_RECIPIENT, edit_index);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    mmi_asc_to_ucs2(ucs2_addr, hd_data->recipient[edit_index]);

    if (hd_data->recipient_info.addr_type == CUI_SMS_ADDR_TYPE_EMAIL_ADDR)
    {
        max_addr_len = hd_data->recipient_info.max_email_addr_len;
    }
    else
    {
        max_addr_len = CUI_SMS_MAX_NUM_LEN;
    }

    cui_sms_entry_phone_number_generic(
        SCR_ID_SMS_EDIT_RECIPIENT,
        STR_ID_SMS_EDIT_RECIPIENT,
        hd_data->recipient_info.addr_type,
        ucs2_addr,
        max_addr_len,
        cui_sms_edit_recipient_done,
        MMI_FALSE);
#else /* __MMI_MESSAGES_SMS_EMAIL__ */
    mmi_asc_to_ucs2(ucs2_addr, hd_data->recipient[edit_index]);

    cui_sms_entry_phone_number_generic(
        SCR_ID_SMS_EDIT_RECIPIENT,
        STR_ID_SMS_EDIT_RECIPIENT,
        CUI_SMS_ADDR_TYPE_NUMBER,
        ucs2_addr,
        CUI_SMS_MAX_NUM_LEN,
        cui_sms_edit_recipient_done,
        MMI_FALSE);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_edit_recipient_done
 * DESCRIPTION
 *  Edit the Current Highlight Recipient Finish Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_edit_recipient_done(S8 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_send_gid = cui_sms_get_active_send_gid();
    cui_sms_send_handle_struct *handle = cui_sms_get_send_handle(sms_send_gid);
    cui_sms_send_handle_data_struct *hd_data = handle->data;
    U16 edit_index = hd_data->recipient_info.highlihgt_index - ITEM_NUM_ABOVE_LINE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_EDIT_RECIPIENT_DONE, edit_index);

    mmi_ucs2_to_asc(hd_data->recipient[edit_index], ucs2_addr);

    hd_data->recipient_info.is_modify = MMI_TRUE;

    cui_fseditor_close(hd_data->edit_num_info->editor_gid);
    cui_sms_entry_phone_number_leave_proc(handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_append_recipient
 * DESCRIPTION
 *  Append Recipient to the Recipient List
 * PARAMETERS
 *  ucs2_addr       [IN]    UCS2 Address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL cui_sms_append_recipient(mmi_id sms_send_gid, S8 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    cui_sms_send_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_APPEND_CURR_RECIPIENT, sms_send_gid);

    hd_data = cui_sms_get_send_handle_data(sms_send_gid);

    ASSERT(hd_data != NULL);

    if (hd_data->total_num < CUI_SMS_MAX_RECIPIENTS_NUM)
    {
        if (mmi_ucs2strlen(ucs2_addr) > 0)
        {
            S8 *ascii_addr = hd_data->recipient[hd_data->total_num];
            U16 addr_len;

            addr_len = mmi_ucs2_n_to_asc(ascii_addr, ucs2_addr, CUI_SMS_MAX_ADDR_LEN * ENCODING_LENGTH);
            ascii_addr[addr_len] = '\0';

            hd_data->total_num++;
        }

        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_APPEND_CURR_RECIPIENT_1, result, hd_data->total_num);

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  cui_sms_remove_curr_recipient
 * DESCRIPTION
 *  Remove the Current Highlight Recipient
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_remove_curr_recipient(cui_sms_send_handle_data_struct *hd_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 remove_index = hd_data->recipient_info.highlihgt_index - ITEM_NUM_ABOVE_LINE;
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_REMOVE_CURR_RECIPIENT, hd_data);

    MMI_ASSERT(hd_data->total_num <= CUI_SMS_MAX_RECIPIENTS_NUM);
    
    for (i = remove_index; i < (hd_data->total_num - 1); i++)
    {
        memcpy(
            hd_data->recipient[i],
            hd_data->recipient[i + 1],
            (CUI_SMS_MAX_ADDR_LEN + 1));
    }
    
    hd_data->total_num--;
    hd_data->recipient_info.is_modify = MMI_TRUE;

    memset(
        hd_data->recipient[hd_data->total_num],
        0,
        (MMI_SMS_MAX_ADDR_LEN + 1));
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_remove_all_recipient
 * DESCRIPTION
 *  Remove All Recipient in the Recipients List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_remove_all_recipient(cui_sms_send_handle_data_struct *hd_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_REMOVE_ALL_RECIPIENT, hd_data);

    for (i = 0; i < hd_data->total_num; i++)
    {
         memset(hd_data->recipient[i], 0, (CUI_SMS_MAX_ADDR_LEN + 1));
    }

    hd_data->total_num = 0;
    hd_data->recipient_info.is_modify = MMI_TRUE;
}


#if defined(__EMS_DYNAMIC_SEG_NUM__) || defined(__MMI_MESSAGES_SMS_EMAIL__)
/*****************************************************************************
 * FUNCTION
 *  cui_sms_convert_send_content_to_emsdata
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL cui_sms_convert_send_content_to_emsdata(cui_sms_send_handle_struct *handle, EMSData *edit_ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;
    cui_sms_send_handle_data_struct *hd_data = handle->data;
    EMSTATUS ems_result = EMS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_CONVERT_CONTENT_TO_EMSDATA);

    if (hd_data->para_flag & SRV_SMS_PARA_PORT)
    {
        ems_result = EMSSetPortNum(edit_ems_data, hd_data->src_port, hd_data->dest_port);

        if (ems_result != EMS_OK)
        {
            cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
        }
    }

    if (hd_data->para_flag & SRV_SMS_PARA_CLASS)
    {
        ems_result = EMSSetMsgClass(edit_ems_data, (U8)hd_data->class_type);

        if (ems_result != EMS_OK)
        {
            cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
        }
    }

    if (ems_result == EMS_OK)
    {
        if((hd_data->para_flag & SRV_SMS_PARA_CONTENT_FILE) == SRV_SMS_PARA_CONTENT_FILE)
        {
            cause = srv_sms_read_content_into_ems(
                        edit_ems_data,
                        hd_data->content_file_path,
                        hd_data->dcs);
        }
        else if((hd_data->para_flag & SRV_SMS_PARA_CONTENT_BUFF) == SRV_SMS_PARA_CONTENT_BUFF)
        {
            cause = srv_sms_add_content_into_ems(
                        edit_ems_data,
                        hd_data->content_buff,
                        hd_data->content_buff_size,
                        hd_data->dcs,
                        MMI_FALSE);
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_CONVERT_CONTENT_TO_EMSDATA_1, cause);

    if (cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        /* for reason SRV_SMS_CAUSE_DATA_EXCEED */
        MMI_ID error_string = STR_SMS_FAILURE_MSG_LEN_EXCEEDED; 
        popup_result = CUI_SMS_RESULT_DATA_EXCEED;
        if (cause != SRV_SMS_CAUSE_DATA_EXCEED)
        {
                error_string = STR_SMS_FAILURE_DATA_INVALID;
                popup_result = CUI_SMS_RESULT_DATA_INVALID;
        }
        cui_sms_display_popupcallback_sg_ext(
            handle->send_gid,
            error_string,
            MMI_EVENT_FAILURE,
            cui_sms_entry_cur_send_scrn_fail_proc,
            NULL,
            0);
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_evt_send_to_parent_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void cui_sms_send_evt_send_to_parent(mmi_id sms_gid, MMI_BOOL is_send_finish, cui_sms_result_enum result)
{
    cui_sms_send_evt_send_to_parent_internal(sms_gid, is_send_finish, result, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_evt_send_to_parent_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void cui_sms_send_evt_send_to_parent_internal(mmi_id sms_gid, MMI_BOOL is_send_finish, cui_sms_result_enum result, MMI_BOOL is_pre_send)
{
    cui_sms_send_evt_send_to_parent_internal_ext(sms_gid, EVT_ID_CUI_SMS_SEND, is_send_finish, result, is_pre_send);
}


static void cui_sms_send_evt_send_to_parent_internal_ext(mmi_id sms_gid, cui_sms_event_enum send_event, MMI_BOOL is_send_finish, cui_sms_result_enum result, MMI_BOOL is_pre_send)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_evt_sms_send_struct evt;
    cui_sms_send_handle_struct *handle = NULL;
    cui_sms_send_handle_data_struct *handle_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_EVT_TO_PARENT, sms_gid, is_send_finish, result);

    handle = cui_sms_get_send_handle(sms_gid);

    if (handle != NULL)
    {
        handle_data = handle->data;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_CUI_SMS_SENDER_SEND_EVT_TO_PARENT_1, handle, handle_data);

    if (handle != NULL)
    {
        evt.evt_id = send_event;
        evt.parent_gid = handle->parent_gid;
        evt.send_gid = handle->send_gid;
        evt.is_send_finish = is_send_finish;
        if (is_pre_send)
        {
            evt.total_num = handle_data->total_num;
            evt.send_num = 0;
            evt.cur_send_index = 0;
        }
        else
        {
            evt.total_num = handle_data->send_info.total_num;
            evt.send_num = handle_data->send_info.curr_send_index + 1;
            evt.cur_send_index = handle_data->send_info.curr_send_index;
        }
        evt.cur_send_result = result;

        if (is_send_finish == MMI_TRUE)
        {
            handle->parent_gid = GRP_ID_INVALID;
        }

        mmi_frm_group_send_to_parent(sms_gid, (mmi_group_event_struct*)&evt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_popup_send_evt_to_parent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret cui_sms_popup_send_evt_to_parent(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*)param;
    cui_evt_sms_send_popup_info_struct *info = (cui_evt_sms_send_popup_info_struct*)alert_result->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(EVT_ID_POPUP_QUIT == param->evt_id)
    {
            cui_sms_send_evt_send_to_parent(info->sms_gid, info->is_send_finish, info->result);
            OslMfree(info);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_pre_send_evt_send_to_parent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void cui_sms_pre_send_evt_send_to_parent(mmi_id sms_gid, MMI_BOOL is_send_finish, cui_sms_result_enum result)
{
    cui_sms_send_evt_send_to_parent_internal(sms_gid, is_send_finish, result, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_compare_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL cui_sms_compare_number(S8* number1, S8* number2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 src_addr[CUI_SMS_MAX_ADDR_LEN + 1];
    U16 dest_addr[CUI_SMS_MAX_ADDR_LEN + 1];
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_wcs(src_addr, number1, CUI_SMS_MAX_ADDR_LEN);
    mmi_asc_n_to_wcs(dest_addr, number2, CUI_SMS_MAX_ADDR_LEN);

    result = srv_phb_compare_number(src_addr, dest_addr);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_ems_remaining_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
S32 cui_sms_get_ems_remaining_length(void *ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMSData *data = (EMSData*)ems_data;

    if (data->dcs == SMSAL_DEFAULT_DCS)
#ifdef __MMI_MESSAGES_CONCAT_SMS__
    return (data->Reminder.totalRemainingOctet -
            (data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num() -
             data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num()));
#else /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
    return (data->Reminder.totalRemainingOctet -
            (mmi_msg_get_seg_num() * 153 - 160));
#endif /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
else
#ifdef __MMI_MESSAGES_CONCAT_SMS__
    return (data->Reminder.totalRemainingOctet -
            (data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num() -
             data->Reminder.maxUsableLenPerSeg * mmi_msg_get_seg_num())) >> 1;
#else /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
    return (data->Reminder.totalRemainingOctet -
            (((mmi_msg_get_seg_num() * 67) << 1) - (70 << 1))) >> 1;
#endif /* defined(__MMI_MESSAGES_CONCAT_SMS__) */ 
}


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  cui_sms_use_sim_selector
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_use_sim_selector(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_id sim_sel_gid;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    if ((srv_mode_switch_get_current_mode() == MMI_SIM1)
        || (srv_mode_switch_get_current_mode() == MMI_SIM2)
        || (srv_mode_switch_get_current_mode() == MMI_SIM3)
    #if (MMI_MAX_SIM_NUM >= 4)
        || (srv_mode_switch_get_current_mode() == MMI_SIM4)
    #endif
         )
    {
        mmi_sim_enum sim_id = (mmi_sim_enum)srv_mode_switch_get_current_mode();
        switch(sim_id)
        {
            case MMI_SIM1:
            case MMI_SIM2:
            case MMI_SIM3:
            #if (MMI_MAX_SIM_NUM >= 4)
            case MMI_SIM4:
            #endif
            cui_sms_recipient_opt_send_by_sim(sim_id | MMI_GSM);
                break;

            default:
                MMI_ASSERT(0);
                break;
        }
    }
    else
    {
        mmi_id sms_send_gid = cui_sms_get_active_send_gid();
        sim_sel_gid = cui_sim_sel_create(sms_send_gid, MMI_SIM1 | MMI_SIM2 | MMI_SIM3 | MMI_SIM4, NULL);
        cui_sim_sel_run(sim_sel_gid);
    }
}
#endif
#endif /* __MOD_SMSAL__ */
