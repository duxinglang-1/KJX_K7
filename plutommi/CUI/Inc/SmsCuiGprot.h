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
 *  SmsSenderCui.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * SMS sender common UI 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __CUI_SMS_GPROT_H__
#define __CUI_SMS_GPROT_H__
#include "MMI_features.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "custom_mmi_default_value.h"

#include "SmsSrvGprot.h"

#define CUI_SMS_MAX_NUM_LEN             SRV_SMS_MAX_ADDR_LEN  /* Max number length */

#ifdef __MMI_MESSAGES_SMS_EMAIL__
#define CUI_SMS_MAX_EMAIL_ADDR_LEN      60      /* Max email address length */
#define CUI_SMS_MAX_ADDR_LEN            CUI_SMS_MAX_EMAIL_ADDR_LEN /* Max address length */
#else /* __MMI_MESSAGES_SMS_EMAIL__ */
#define CUI_SMS_MAX_ADDR_LEN            CUI_SMS_MAX_NUM_LEN    /* Max address length */
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

#ifdef __OP01__
#define CUI_SMS_MAX_RECIPIENTS_NUM      50    /* Max recipeint number */
#else /* normal */
#define CUI_SMS_MAX_RECIPIENTS_NUM      20    /* Max recipeint number */
#endif  /* OP01 */

/* Define CUI event Id */
typedef enum
{
#ifdef __COSMOS_MMI_PACKAGE__
    EVT_ID_CUI_SMS_SEND = SRV_SMS + 40,
#else
    EVT_ID_CUI_SMS_SEND = SMS_BASE + 50,
#endif
    EVT_ID_CUI_SMS_SEND_START_SAVING,

    EVT_ID_CUI_SMS_SAVE,          /* event ID of SMS save CUI */
    EVT_ID_CUI_SMS_SAVE_CANCEL,   /* event ID of SMS send CUI */
    EVT_ID_CUI_SMS_TEMPLATE_LIST, /* event ID of SMS template list CUI */
    
    EVT_ID_SMS_MAX
} cui_sms_event_enum;

/* SMS send CUI send result */
typedef enum
{
    CUI_SMS_RESULT_OK,    /*send success*/
    CUI_SMS_RESULT_ERROR,   /* send error */
    CUI_SMS_RESULT_NOT_READY,   /* send fail because SMS not ready */
    CUI_SMS_RESULT_DATA_EXCEED,    /* send fail because SMS data content exceeded */
    CUI_SMS_RESULT_DATA_INVALID,    /* send fail because SMS data content invalid */
    CUI_SMS_RESULT_EMAIL_NO_SPACE,  /* send fail because no content space for email address */
    CUI_SMS_RESULT_MEM_FULL,    /* send fail because SMS memory full */
    CUI_SMS_RESULT_SAVE_TO_DRAFTS,  /* SMS saved to drafts */
    CUI_SMS_RESULT_GROUP_GOBACK,    /* SMS send cui goback group */
    CUI_SMS_RESULT_CANCEL,          /* SMS send cancled */
    CUI_SMS_RESULT_SENT_AND_SAVED,  /* SMS send and save success */
    CUI_SMS_RESULT_SENT_BUT_SAVE_FAIL,  /* send success but save failed */
    CUI_SMS_RESULT_SEND_FAIL_BUT_SAVED, /* send failed but saved success */
    CUI_SMS_RESULT_SEND_FAIL_AND_SAVE_FAIL, /* send fail and save failed */
    CUI_SMS_CAUSE_ERROR_FDN_ENABLED,
    CUI_SMS_RESULT_TOTAL
} cui_sms_result_enum;

/* Send CUI event structure */ 
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_id parent_gid;      /* Caller's group id */
    mmi_id send_gid;         /* current send cui's group id */
    MMI_BOOL is_send_finish; /* if MMI_TRUE, need caller close sms send CUI, send end here */
    U16 total_num;           /* total need send recipient number*/
    U16 send_num;        /* if send_number ==total_num, indicate all recipient have been sent, normal send end */
    U16 cur_send_index;     /* current have been sent recipient index, from 0 to total_num-1 */
    cui_sms_result_enum cur_send_result; /* current send recipient's send result */
} cui_evt_sms_send_struct;

/* Save CUI event structure */ 
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_id parent_gid;        /* save CUI's parent group id */
    MMI_BOOL save_result;     /* save result */
    srv_sms_cause_enum cause; /* save fail casue */
    U16 saved_msg_id;         /* save message id when save sms success */
} cui_evt_sms_save_struct; 

/* Tempate event information structure */ 
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    WGUI_SOFTKEY_ENUM key_pressed;      /* Caller's group id */
} cui_sms_template_evt_struct;

/* SMS send CUI hide screen enum */
typedef enum
{
    CUI_SMS_NO_SEND_HIDDEN_SCR      = 0x00, /* hide non screen */
    CUI_SMS_SEND_ADD_RECIPIENT_SCR  = 0x01, /* hide add recipeint screen */
    CUI_SMS_SEND_SELECT_SIM_SCR     = 0x02, /* hide select sim screen when open dual sim */
    CUI_SMS_SEND_SC_SCR             = 0x04 /* hide edit sc screen */
} cui_sms_send_hidden_scrn_enum;

/* SMS send CUI send case enum */
typedef enum
{
	CUI_SMS_SEND_CASE_NONE,
	CUI_SMS_SEND_CASE_WRITE_NEW_MSG,    /* write new sms */
    CUI_SMS_SEND_CASE_REPLY,            /* reply inbox sms */
    CUI_SMS_SEND_CASE_ARCHIVE_REPLY,    /* reply archive sms */
	CUI_SMS_SEND_CASE_EDIT_DRAFT,       /* edit drafts sms */
	CUI_SMS_SEND_CASE_EDIT_UNSENT,      /* edit outbox unsent sms */
	CUI_SMS_SEND_CASE_FORWARD,          /* forward sms */
	CUI_SMS_SEND_CASE_RESEND,           /* resend sms */
	CUI_SMS_SEND_CASE_SEND_DRAFT,       /* send drafts sms */

	CUI_SMS_SEND_CASE_WRITE_FROM_OTHER_APP, /* non-SMS AP write new sms */
	CUI_SMS_SEND_CASE_SEND_FROM_OTHER_APP,  /* non-SMS AP send sms */
    CUI_SMS_SEND_CASE_SEND_DATA_MSG,       /* send data port SMS */

    CUI_SMS_SEND_CASE_TOTAL
} cui_sms_send_case_enum;

/* SMS send CUI abort send type enum */
typedef enum
{
    CUI_SMS_ABORT_WITH_FINISH_IND,    /* Abort sms send and wait service's callback */
    CUI_SMS_ABORT_WITHOUT_FINISH_IND, /* Abort sms send and clear service's callback */

    CUI_SMS_ABORT_TOTAL
} cui_sms_abort_send_enum;

/* Template type enum */
typedef enum
{
    CUI_SMS_TEMPLATE_NONE = 0,
    CUI_SMS_TEMPLATE_USER_DEFINED, /* user define template */
    CUI_SMS_TEMPLATE_DEFAULT,      /* pre-defined template */
    CUI_SMS_TEMPLATE_TOTAL
}cui_sms_template_type_enum;

/*****************************************************************************
 * FUNCTION
 *  cui_sms_is_send_busy
 * DESCRIPTION
 *  check if can send
 * PARAMETERS
 *  type  :      [IN]        Send Type enum
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL cui_sms_is_send_busy(srv_sms_send_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_create
 * DESCRIPTION
 *  Create SMS send Common UI
 * PARAMETERS
 *  parent_gid    :          [IN]      SMS Send CUI parent group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_id cui_sms_send_create(mmi_id parent_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_run
 * DESCRIPTION
 *  Run SMS send Common UI
 * PARAMETERS
 *  sms_send_gid    :          [IN]      SMS Send CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_send_run(mmi_id sms_send_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_close
 * DESCRIPTION
 *  Close SMS send Common UI
 * PARAMETERS
 *  sms_send_gid    :          [IN]      SMS Send CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_send_close(mmi_id sms_send_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_address
 * DESCRIPTION
 *  Set send SMS Common UI recipeint address list
 * PARAMETERS
 *  sms_gid         :      [IN]        SMS Send CUI group ID
 *  ucs2_addr_list  :      [IN]        U16 ucs2_addr_list[addr_count][CUI_SMS_MAX_ADDR_LEN +1]
 *  addr_count      :      [IN]        addess count
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_address(mmi_id sms_gid, U16 **ucs2_addr_list, U16 addr_count);


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_each_address
 * DESCRIPTION
 *  CUI for send
 *  This API can be used to set address in for(i=0; i< CUI_SMS_MAX_RECIPIENTS_NUM; i++)
 *  so max can set CUI_SMS_MAX_RECIPIENTS_NUM recipient, otherwise buffer overflow
 * PARAMETERS
 *  sms_gid         :      [IN]        SMS Send CUI group ID
 *  ucs2_addr       :      [IN]        U16 ucs2_addr[CUI_SMS_MAX_ADDR_LEN +1]
 * RETURNS
 *  
 *****************************************************************************/
extern void cui_sms_set_send_each_address(mmi_id sms_gid, U16 *ucs2_addr);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_send_address
 * DESCRIPTION
 *  Get send recipeint number list, caller need molloc buffer for ucs2_addr_list, SMS CUI ony add number to this list.
 *  IF caller need know recipient info, can call this interface
 * PARAMETERS
 *  sms_gid         :      [IN]            SMS Send CUI group ID
 *  ucs2_addr_list  :      [IN/OUT]        U16 ucs2_addr_list[CUI_SMS_MAX_RECIPIENTS_NUM][CUI_SMS_MAX_ADDR_LEN + 1];
 *  addr_count      :      [IN/OUT]        addess count, U16 *addr_count
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_get_send_address(mmi_id sms_gid, U16 **ucs2_addr_list, U16 *addr_count);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_text
 * DESCRIPTION
 *  Set send SMS Common UI text content
 *  Content must be convert to UCS2 when set, parameter content_buff must be a U16* buffer.
 *  SMS service will anto check content's real dcs when send this message.
 *  If content characters only contain 7bit character, SMS service will send it as 7BIT DCS.
 *  If content characters contain UCS2 character, SMS service will send it as UCS2 DCS.
 *  IF content characters only contain 7bit character, but need send as UCS2 DCS, then must set DCS.
 *  Set DCS can use API cui_sms_set_send_content_text_dcs(), this API need be use after set content text.
 * PARAMETERS
 *  sms_gid         :        [IN]       SMS Send CUI group ID
 *  content_buff    :        [IN]       U16 content_buff[(content_size + ENCODING_LENGTH) / 2] 
 *  content_size    :        [IN]       content buffer size, size of Bytes
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_content_text(mmi_id sms_gid, U16 *content_buff, U16 content_size);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_text_file
 * DESCRIPTION
 *  Set send SMS Common UI text file path
 * PARAMETERS
 *  sms_gid             :        [IN]       SMS Send CUI group ID
 *  content_file_path   :        [IN]       file path must be ucs2 dcs, file content must also be ucs2 dcs
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_content_text_file(mmi_id sms_gid, U16 *content_file_path);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_ems
 * DESCRIPTION
 *  Set send SMS Common UI content with EMSData
 * PARAMETERS
 *  sms_gid     :              [IN]       SMS Send CUI group ID
 *  content_ems :              [IN]       EMSData content infomation
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_content_ems(mmi_id sms_gid, void *content_ems);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_sim_id
 * DESCRIPTION
 *  Set send SMS Common UI SIM ID
 * PARAMETERS
 *  sms_gid :                  [IN]       SMS Send CUI group ID
 *  sim_id  :                   [IN]       srv_sms_sim_enum, dual SIM project can set
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_sim_id(mmi_id sms_gid, srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_msg_id
 * DESCRIPTION
 *  Set send SMS Common UI Message ID
 * PARAMETERS
 *  sms_gid :                  [IN]       SMS Send CUI group ID
 *  msg_id  :                   [IN]       Message ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_msg_id(mmi_id sms_gid, U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_data
 * DESCRIPTION
 *  Set send SMS Common UI content data for sending port SMS
 * PARAMETERS
 *  sms_gid         :        [IN]       SMS Send CUI group ID
 *  content_buff    :        [IN]       Content must be 8BIT DCS 
 *  content_size    :        [IN]       content buffer size, size of Bytes
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_content_data(mmi_id sms_gid, S8 *content_buff, U16 content_size);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_data_file
 * DESCRIPTION
 *  Only be used to set send SMS Common UI parameter.
 *  Set send SMS Common UI content data with file path,
 *  parameter content_file_path must be UCS2 dcs content, file content must  be 8BIT dcs.
 * PARAMETERS
 *  sms_gid             :        [IN]       SMS Send CUI group ID
 *  content_file_path   :        [IN]       file path must be ucs2 dcs, fiel content must be 8BIT dcs 
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_content_data_file(mmi_id sms_gid, U16 *content_file_path);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_data_port
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  If send data message, need set AP's port number.
 * PARAMETERS
 *  sms_gid     :                [IN]       SMS Send CUI group ID
 *  src_port    :                [IN]       Source port number
 *  dest_port   :                [IN]       Dest port number
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_data_port(mmi_id sms_gid, U16 src_port, U16 dest_port);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_status_report
 * DESCRIPTION
 *  Only be used to set send Common UI parameter.
 *  If need set status report, set MMI_TRUE, else MMI_FALSE; 
 *  if do not care, please do not use this API to set, sms service will use common setting's set.
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  is_set  :                 [IN]            set status report's status
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_status_report(mmi_id sms_gid, MMI_BOOL is_set);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_sc_address
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  This function is used to set SMSC address, parameter sc_addr is a ucs2 contern buffer.
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  sc_addr :                 [IN]            sc address, should be ucs2 dcs number
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_sc_address(mmi_id sms_gid, U16 *sc_addr);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_vp
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  This function is used to set this send sms's validity period.
 *  If not set, will use sms service's active profile validity period.
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  vp      :                 [IN]            set validity period
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_vp(mmi_id sms_gid, srv_sms_vp_enum vp);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_content_text_dcs
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  This function is used to set text content's DCS.
 *  This API only can be used when AP use cui_sms_set_send_content_text() 
 *  to set content characters only contain 7BIT character, no UCS2 character, but need to send this
 *  message with UCS2 DCS. This API must be used after cui_sms_set_send_content_text().
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  dcs     :                 [IN]            set validity period
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_content_text_dcs(mmi_id sms_gid, srv_sms_dcs_enum dcs);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_sending_string_id
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  Set Sending Screen String id if AP need customize sending screen's string.
 * PARAMETERS
 *  sms_gid     :               [IN]            SMS Send CUI group ID
 *  string_id   :               [IN]            set Sending screen showing string
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_sending_string_id(mmi_id sms_gid, U16 string_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_pid
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  This function is used to set message type.
 *  If not set, will use active prfile setting's message type.
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  pid     :                 [IN]            set message type
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_pid(mmi_id sms_gid, srv_sms_pid_enum pid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_class_type
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  This function is used to set send message class type. 
 * PARAMETERS
 *  sms_gid     :              [IN]            SMS Send CUI group ID
 *  class_type  :              [IN]            set send message class type
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_class_type(mmi_id sms_gid, srv_sms_class_enum class_type);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_reply_path
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  This function is used to set if need reply path. If not set, default use SMS common setting's set.
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  is_set  :                 [IN]            set send message reply path
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_reply_path(mmi_id sms_gid, MMI_BOOL is_set);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_reply_msg_id
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  IF this send is reply inbox sms, need set reply message ID
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  msg_id  :                 [IN]            If this is SMS reply, need set reply message ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_reply_msg_id(mmi_id sms_gid, U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_type
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  If send type is background send but not save, no need set this parameter.
 *  This API is only used by SMS module, distinguish SMS send and other AP's send.
 *  If need foreground send , or save and send, need call this API.
 *  For exam: UC background send need set it as SRV_SMS_BG_SAVE_SEND.
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  type    :                 [IN]            srv_sms_send_type_enum type               
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_type(mmi_id sms_gid, srv_sms_send_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_mms
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  for send to many recipient, send one by one using common UI.
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  is_set  :                 [IN]            is more message need send
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_mms(mmi_id sms_gid, MMI_BOOL is_set);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_msg_case
 * DESCRIPTION
 *  Only be used to set send Common UI parameter
 *  This function is used for SMS internal to distinguish send case.
 * PARAMETERS
 *  sms_gid         :           [IN]            SMS Send CUI group ID
 *  send_msg_case   :           [IN]            cui_sms_send_case_enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_msg_case(mmi_id sms_gid, cui_sms_send_case_enum send_msg_case);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_unhide_add_recipient_scrn
 * DESCRIPTION
 *  Only be used to set send SMS Common UI parameter
 *  If call this API will always show add recipient screen
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_unhide_add_recipient_scrn(mmi_id sms_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_unhide_save_menu
 * DESCRIPTION
 *  Only be used to set send SMS Common UI parameter
 *  If call this API will always show add recipient options' menu "save to drafts".
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID               
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_send_unhide_save_menu(mmi_id sms_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_abort_send
 * DESCRIPTION
 *  This function is used to abort send mesage.
 * PARAMETERS
 *  sms_gid :                 [IN]            SMS Send CUI group ID
 *  type    :                 [IN]            cui_sms_abort_send_enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_abort_send(mmi_id sms_gid, cui_sms_abort_send_enum type);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_create
 * DESCRIPTION
 *  This function is used to create SMS save message common UI
 * PARAMETERS
 *  parent_gid :             [IN]            Parent group ID
 * RETURNS
 *  mmi_id
 *****************************************************************************/
extern mmi_id cui_sms_save_create(mmi_id parent_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_run
 * DESCRIPTION
 *  This functions is used to run sms save common UI.
 * PARAMETERS
 *  sms_save_gid :                 [IN]            SMS Save CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_save_run(mmi_id sms_save_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_close
 * DESCRIPTION
 *  This functions is used to close SMS save common UI.
 * PARAMETERS
 *  sms_save_gid :                 [IN]            SMS Save CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_save_close(mmi_id sms_save_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_address
 * DESCRIPTION
 *  This function is used to set the saving message recipient address.
 * PARAMETERS
 *  sms_gid   :               [IN]            SMS Save CUI group ID
 *  ucs2_addr :               [IN]            ucs2 number, ucs2_addr[SRV_SMS_MAX_ADDR_LEN + 1]
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_save_address(mmi_id sms_gid, U16 *ucs2_addr);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_sc_addr
 * DESCRIPTION
 *   If need specify this message SMSC address, can call this function to set sc address.
 * PARAMETERS
 *  sms_gid   :               [IN]            SMS Save CUI group ID
 *  ucs2_addr :               [IN]            ucs2 number, ucs2_addr[SRV_SMS_MAX_ADDR_LEN + 1]
 * RETURNS
 *  
 *****************************************************************************/
extern void cui_sms_set_save_sc_addr(mmi_id sms_gid, U16 *ucs2_addr);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_content_text
 * DESCRIPTION
 *  Set save SMS Common UI text content
 *  Content must be convert to UCS2 when set, parameter content_buff must be a U16* buffer.
 *  SMS service will anto check content's real dcs when save this message.
 *  If content characters only contain 7bit character, SMS service will save it as 7BIT DCS.
 *  If content characters contain UCS2 character, SMS service will save it as UCS2 DCS.
 * PARAMETERS
 *  sms_gid      :            [IN]            SMS Save CUI group ID
 *  content_buff :            [IN]            U16 content_buff[(content_size + ENCODING_LENGTH) / 2]
 *  content_size :            [IN]            size of Bytes
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_save_content_text(mmi_id sms_gid, U16 *content_buff, U16 content_size);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_content_text_file
 * DESCRIPTION
 *  Set save SMS Common UI text file path
 * PARAMETERS
 *  sms_gid           :           [IN]            SMS Save CUI group ID
 *  content_file_path :           [IN]            file path must be ucs2 dcs, file content must also be ucs2 dcs
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_save_content_text_file(mmi_id sms_gid, U16 *content_file_path);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_content_ems
 * DESCRIPTION
 *  Set save SMS Common UI content with EMSData
 * PARAMETERS
 *  sms_gid     :                 [IN]            SMS Save CUI group ID
 *  content_ems :                 [IN]            EMSData*
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_save_content_ems(mmi_id sms_gid, void *content_ems);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_sim_id
 * DESCRIPTION
 *  This function is used to set  save message by wich SIM if dual SIM open.
 * PARAMETERS
 *  sms_gid :                     [IN]            SMS Save CUI group ID
 *  sim_id  :                     [IN]            srv_sms_sim_enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_save_sim_id(mmi_id sms_gid, srv_sms_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_status_report
 * DESCRIPTION
 *  This function is used to set status report parameter.
 *  If not call this API set, if send will use SMS common setting's value.
 * PARAMETERS
 *  sms_gid :                     [IN]            SMS Save CUI group ID
 *  is_set  :                     [IN]            status report parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_save_status_report(mmi_id sms_gid, MMI_BOOL is_set);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_reply_path
 * DESCRIPTION
 *  This function is used to set status report parameter.
 *  If not call this API set, if send will use SMS common setting's value.
 * PARAMETERS
 *  sms_gid :                    [IN]            SMS Save CUI group ID
 *  is_set  :                    [IN]            reply path parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_save_reply_path(mmi_id sms_gid, MMI_BOOL is_set);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_msg_status
 * DESCRIPTION
 *  This function is used to set message status.
 * PARAMETERS
 *  sms_gid :                     [IN]            SMS Save CUI group ID
 *  status  :                     [IN]            message status, srv_sms_status_enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_set_save_msg_status(mmi_id sms_gid, srv_sms_status_enum status);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_pid
 * DESCRIPTION
 *  This function is used to set message type.
 *  Currently only used when save "send as email" message
 * PARAMETERS
 *  sms_gid :                     [IN]            SMS Save CUI group ID
 *  pid     :                     [IN]            message type, srv_sms_pid_enum
 * RETURNS
 *  
 *****************************************************************************/
extern void cui_sms_set_save_pid(mmi_id sms_gid, srv_sms_pid_enum pid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_timestamp
 * DESCRIPTION
 *  This function is used to set message time.
 * PARAMETERS
 *  sms_gid   :                   [IN]            SMS Save CUI group ID
 *  timestamp :                   [IN]            message's time
 * RETURNS
 *  
 *****************************************************************************/
extern void cui_sms_set_save_timestamp(mmi_id sms_gid, MYTIME *timestamp);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_title_id
 * DESCRIPTION
 *  Default Save tille is STR_SMS_SAVE_TO_DRAFTS_MENU_ITEM,
 *  If need use other Title id need set this parameter.
 * PARAMETERS
 *  sms_gid  :                    [IN]            SMS Save CUI group ID
 *  title_id :                    [IN]            Title string ID
 * RETURNS
 *  
 *****************************************************************************/
extern void cui_sms_set_save_title_id(mmi_id sms_gid, U16 title_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_edit_draft
 * DESCRIPTION
 *  If current need save message is edit a draft message, before save, need
 *  first delete the draft message, then save this message as a new message.
 *  Each message have a unique message ID, when delete message using this 
 * PARAMETERS
 *  sms_gid :                     [IN]            SMS Save CUI group ID
 *  msg_id  :                     [IN]            message ID
 * RETURNS
 *  
 *****************************************************************************/
extern void cui_sms_set_save_edit_draft_msg_id(mmi_id sms_gid, U16 msg_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_success_popup_string_id
 * DESCRIPTION
 *  This function is used to set the popup string ID when save message suceess.
 *  Default popup string is "Saved".
 * PARAMETERS
 *  sms_gid   :                   [IN]            SMS Save CUI group ID
 *  string_id :                   [IN]            string ID
 * RETURNS
 *  
 *****************************************************************************/
extern void cui_sms_set_save_success_popup_string_id(mmi_id sms_gid, U16 string_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_ems_remaining_length
 * DESCRIPTION
 *  This function is used to get EMSData text buffer remaining unused buffer length.
 * PARAMETERS
 *  ems_data    :                    [IN]            EMSData* ems_data
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 cui_sms_get_ems_remaining_length(void *ems_data);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_create
 * DESCRIPTION
 *  1.Create SMS template common UI, this CUI only support one instance;
 *  2.If create fail because template not support, show popup "Not support", return GRP_ID_INVALID;
 *    If create fail because template list init failed, show popup "Not support", return GRP_ID_INVALID;
 *    So if create return GRP_ID_INVALID, shall not run this cui.
 *  3.If AP don't allow template list is empty, can set is_allow_empty = MMI_FALSE, then if template number
 *    is 0, will create fail popup "Empty", return GRP_ID_INVALID.
 *  4.If create fail, need template show popup, set as MMI_TRUE, otherwise set as MMI_FALSE;
 *  5.There are two type of template, if all support, will list select type template, but if only support one
 *    type of two, will list support type template ignore parameter "type".
 *  6.This CUI only a template list screen, all key response need caller deal with.
 *    Create intialize: LSK is "OK", CSK is IMG_GLOBAL_COMMON_CSK. if need reset, need call set corresponde API.
 * PARAMETERS
 *  parent_gid        :                [IN]            Parent group ID
 *  allow_empty_list  :                [IN]            allow template list empty
 *  templ_type        :                [IN]            Priority list template type
 *  is_show_popup     :                [IN]            if create fail, allow show popup or not
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID cui_sms_template_list_create(MMI_ID parent_gid, MMI_BOOL allow_empty_list, cui_sms_template_type_enum templ_type, MMI_BOOL is_show_popup);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_runs
 * DESCRIPTION
 *  Run template CUI
 * PARAMETERS
 *  template_gid     :                [IN]           SMS template CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_template_list_run(MMI_ID template_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_close
 * DESCRIPTION
 *  Close template CUI
 * PARAMETERS
 *  template_gid     :                [IN]           SMS template CUI group ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_template_close(MMI_ID template_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_get_select_content
 * DESCRIPTION
 *  Get select template comtent
 * PARAMETERS
 *  template_gid     :                [IN]           SMS template CUI group ID
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
extern WCHAR* cui_sms_template_list_get_select_content(MMI_ID template_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_set_left_softkey
 * DESCRIPTION
 *  Set template list screen LSK
 * PARAMETERS
 *  template_gid      :                [IN]           SMS template CUI group ID
 *  left_string_id    :                [IN]           LSK string id
 *  left_icon_id      :                [IN]           LSK icon id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_template_list_set_left_softkey(MMI_ID template_gid, U16 left_string_id, U16 left_icon_id);

/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_set_csk_softkey
 * DESCRIPTION
 *  Set template list screen CSK
 * PARAMETERS
 *  template_gid     :                [IN]           SMS template CUI group ID
 *  csk_string_id    :                [IN]           csk string id
 *  csk_icon_id      :                [IN]           csk icon id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sms_template_list_set_csk_softkey(MMI_ID template_gid, U16 csk_string_id, U16 csk_icon_id);

#endif /* __SRV_SMS_SEND_HANDLER_H__ */ 


