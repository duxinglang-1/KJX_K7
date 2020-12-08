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
 *  SatSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains external structures & function prototypes for SAT service layer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SATSRVGPROT_H
#define SATSRVGPROT_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "resource_audio.h"
#include "mmi_res_range_def.h"
#include "kal_general_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* DOM-NOT_FOR_SDK-BEGIN */

/* SIM Toolkit */
typedef enum
{
    SRV_SAT1,
#if (MMI_MAX_SIM_NUM >= 2)
    SRV_SAT2,
#if (MMI_MAX_SIM_NUM >= 3)
    SRV_SAT3,
#if (MMI_MAX_SIM_NUM >= 4)
    SRV_SAT4,
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif /* MMI_MAX_SIM_NUM >= 3 */
#endif /* MMI_MAX_SIM_NUM >= 2 */
    SRV_SAT_TOTAL
} srv_sat_enum;


/* Proactive SIM commands */
typedef enum
{
    SRV_SAT_CMD_NONE,
    SRV_SAT_CMD_DISPLAY_TEXT,
    SRV_SAT_CMD_GET_INKEY,
    SRV_SAT_CMD_GET_INPUT,
    SRV_SAT_CMD_PLAY_TONE,
    SRV_SAT_CMD_REFRESH,
    SRV_SAT_CMD_SETUP_MENU,
    SRV_SAT_CMD_SELECT_ITEM,
    SRV_SAT_CMD_SEND_SMS,
    SRV_SAT_CMD_SEND_SS,
    SRV_SAT_CMD_SEND_SS_RETURN_RESULT,
    SRV_SAT_CMD_SEND_USSD,
    SRV_SAT_CMD_SEND_USSD_RETURN_RESULT,
    SRV_SAT_CMD_SETUP_CALL,
    SRV_SAT_CMD_PROVIDE_LOCAL_INFORMATION,
    SRV_SAT_CMD_SETUP_IDLE_MODE_TEXT,
    SRV_SAT_CMD_RUN_AT_COMMAND,
    SRV_SAT_CMD_SEND_DTMF,
    SRV_SAT_CMD_LANGUAGE_NOTIFICATION,
    SRV_SAT_CMD_LAUNCH_BROWSER,
    SRV_SAT_CMD_OPEN_CHANNEL,
    SRV_SAT_CMD_CLOSE_CHANNEL,
    SRV_SAT_CMD_SEND_DATA,
    SRV_SAT_CMD_RECEIVE_DATA
} srv_sat_cmd_enum;


typedef enum
{
    /* Results '0X' and '1X' indicate that the command has been performed. */
    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_SUCCESSFULLY = 0x00,
    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_WITH_PARTIAL_COMPREHENSION = 0x01,
    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_WITH_MISSING_INFO = 0x02,
    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_WITH_ADDITIONAL_EF_READ = 0x03,
    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_ICON_COULD_NOT_DISPLAY = 0x04,
    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_BUT_MODIFIED_BY_CALL_CTRL_BY_SIM = 0x05,
    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_LIMITED_SERVICE = 0x06,
    SRV_SAT_TERMINAL_RES_CMD_PERFORMED_WITH_MODIFICATION = 0x07,
    SRV_SAT_TERMINAL_RES_PROACTIVE_SESSION_TERMINATED_BY_USER = 0x10,
    SRV_SAT_TERMINAL_RES_BACKWARD_MOVE_IN_PROACTIVE_SESSION_REQUESTED_BY_USER = 0x11,
    SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER = 0x12,
    SRV_SAT_TERMINAL_RES_HELP_INFO_REQUIRED_BY_USER = 0x13,
    SRV_SAT_TERMINAL_RES_USSD_SS_TRANSACTION_TERMINATED_BY_USER = 0x14,
    /* Results '2X' indicate to the SIM that it may be worth re-trying the command at a later opportunity. */
    SRV_SAT_TERMINAL_RES_ME_CURRENTLY_UNABLE_TO_PROCESS_CMD = 0x20,
    SRV_SAT_TERMINAL_RES_NET_CURRENTLY_UNABLE_TO_PROCESS_CMD = 0x21,
    SRV_SAT_TERMINAL_RES_USER_DID_NOT_ACCEPT_PROACTIVE_CMD = 0x22,
    SRV_SAT_TERMINAL_RES_USER_CLEAR_DOWN_CALL_BEFORE_CONNECTION = 0x23,
    SRV_SAT_TERMINAL_RES_ACTION_IN_CONTRACTION_WITH_CURRENT_TIMER_STATE = 0x24,
    SRV_SAT_TERMINAL_RES_INTERACTION_WITH_CALL_CTRL_BY_SIM_TEMPORARY_ERROR = 0x25,
    SRV_SAT_TERMINAL_RES_LAUNCH_BROWER_GENERIC_ERROR_CODE = 0x26,
    /* Results '3X' indicate that it is not worth the SIM re-trying with an identical command,
       as it will only get the same response. */
    SRV_SAT_TERMINAL_RES_CMD_BEYOND_ME_CAPABILITY = 0x30,
    SRV_SAT_TERMINAL_RES_CMD_TYPE_NOT_UNDERSTAND_BY_ME = 0x31,
    SRV_SAT_TERMINAL_RES_CMD_DATA_NOT_UNDERSTAND_BY_ME = 0x32,
    SRV_SAT_TERMINAL_RES_CMD_NUMBER_NOT_KNOWN_BY_ME = 0x33,
    SRV_SAT_TERMINAL_RES_SS_RETURN_ERROR = 0x34,
    SRV_SAT_TERMINAL_RES_SMS_RP_ERROR = 0x35,
    SRV_SAT_TERMINAL_RES_REQUIRED_VALUE_MISSING_ERROR = 0x36,
    SRV_SAT_TERMINAL_RES_USSD_RETURN_ERROR = 0x37,
    SRV_SAT_TERMINAL_RES_MULTICARD_CMD_ERROR = 0x38,
    SRV_SAT_TERMINAL_RES_INTERACTION_WITH_CALL_CTRL_BY_SIM_PERMANENT_ERROR = 0x39,
    SRV_SAT_TERMINAL_RES_BEARER_INDEPENDENT_PROTOCOL_ERROR = 0x3A
} srv_sat_terminal_res_enum;


typedef enum
{
    /* Additional information for ME problem */
    SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE = 0x00,
    SRV_SAT_ADDITIONAL_RES_SCREEN_BUSY = 0x01,
    SRV_SAT_ADDITIONAL_RES_ME_CURRENTLY_BUSY_ON_CALL = 0x02,
    SRV_SAT_ADDITIONAL_RES_ME_CURRENTLY_BUSY_ON_SS_TRANSACTION = 0x03,
    SRV_SAT_ADDITIONAL_RES_NO_SERVICE = 0x04,
    SRV_SAT_ADDITIONAL_RES_ACCESS_CTRL_CLASS_BAR = 0x05,
    SRV_SAT_ADDITIONAL_RES_RR_NOT_GRANTED = 0x06,
    SRV_SAT_ADDITIONAL_RES_NOT_IN_SPEECH_MODE = 0x07,
    SRV_SAT_ADDITIONAL_RES_ME_CURRENTLY_BUSY_ON_USSD_TRANSACTION = 0x08,
    SRV_SAT_ADDITIONAL_RES_ME_CURRENTLY_BUSY_ON_SEND_DTMF_CMD = 0x09,
    /* Additional information for interaction with call control or MO SM control */
    SRV_SAT_ADDITIONAL_RES_ACTION_NOT_ALLOWED = 0x01,
    SRV_SAT_ADDITIONAL_RES_TYPE_OF_REQUEST_CHANGED = 0x02,
    /* Additional information for Launch Browser problem */
    SRV_SAT_ADDITIONAL_RES_BEARER_UNAVAILABLE = 0x01,
    SRV_SAT_ADDITIONAL_RES_BROWSER_UNAVAILABLE = 0x02,
    SRV_SAT_ADDITIONAL_RES_ME_UNABLE_TO_READ_PROVISIONING_DATA = 0x03
} srv_sat_additional_res_enum;


/* Two types of priority (DISPLAY TEXT) */
typedef enum
{
    SRV_SAT_PRIORITY_NORMAL,
    SRV_SAT_PRIORITY_HIGH
} srv_sat_priority_enum;


/* Two clear types (DISPLAY TEXT) */
typedef enum
{
    SRV_SAT_CLEAR_AFTER_SHORT_DELAY,
    SRV_SAT_CLEAR_BY_USER
} srv_sat_clear_enum;


/* Three input types (GET INKEY & GET INPUT) */
typedef enum
{
    SRV_SAT_INPUT_DIGIT_ONLY,
    SRV_SAT_INPUT_SMS_DEFAULT,
    SRV_SAT_INPUT_UCS2,
    SRV_SAT_INPUT_YES_NO
} srv_sat_input_enum;


/* Three dcs types (GET INKEY & GET INPUT) */
typedef enum
{
    SRV_SAT_DCS_SMS_DEFAULT = 0x00,
    SRV_SAT_DCS_8BIT = 0x04,
    SRV_SAT_DCS_UCS2 = 0x08
} srv_sat_dcs_enum;


/* Five refresh types (REFRESH) */
typedef enum
{
    SRV_SAT_REFRESH_INIT_AND_FULL_FILE_CHANGE,
    SRV_SAT_REFRESH_FILE_CHANGE,
    SRV_SAT_REFRESH_INIT_AND_FILE_CHANGE,
    SRV_SAT_REFRESH_INIT,
    SRV_SAT_REFRESH_RESET
} srv_sat_refresh_enum;


/* Three conditions (SETUP CALL) */
typedef enum
{
    SRV_SAT_SETUP_IF_NO_ANOTHER_CALL,
    SRV_SAT_SETUP_WITH_REDIAL_IF_NO_ANOTHER_CALL,
    SRV_SAT_SETUP_PUT_ALL_OTHER_HOLD,
    SRV_SAT_SETUP_WITH_REDIAL_PUT_ALL_OTHER_HOLD,
    SRV_SAT_SETUP_DISCONNECT_ALL_OTHER_CALL,
    SRV_SAT_SETUP_WITH_REDIAL_DISCONNECT_ALL_OTHER_CALL
} srv_sat_setup_enum;


/* Three modes (LAUNCH BROWSER) */
typedef enum
{
    SRV_SAT_LAUNCH_IF_NO_LAUNCHED = 0x00,
    SRV_SAT_LAUNCH_USE_EXISTING = 0x02,
    SRV_SAT_LAUNCH_CLOSE_EXISTING_AND_LAUNCH_NEW = 0x03
} srv_sat_launch_enum;


typedef enum
{
    SRV_SAT_CALL_DISCONNECT_BEFORE_CONNECT,
    SRV_SAT_CALL_DISCONNECT_AFTER_CONNECT
} srv_sat_call_disconnect_enum;


typedef enum
{
    SRV_SAT_BROWSER_USER_TERMINATION,
    SRV_SAT_BROWSER_ERROR_TERMINATION
} srv_sat_browser_termination_enum;


typedef enum
{
    EVT_ID_SRV_SAT_PROACTIVE_SIM = STK_BASE + 1,
    EVT_ID_SRV_SAT_SETUP_MENU,
    EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY,
    EVT_ID_SRV_SAT_SIM_REFRESH,
    EVT_ID_SRV_SAT_SESSION_END,
    EVT_ID_SRV_SAT_SIM_CTRL_INFO
} srv_sat_event_enum;


typedef enum
{
    SRV_SAT_ICON_SELF_EX,
    SRV_SAT_ICON_NOT_SELF_EX
} srv_sat_icon_enum;


#ifdef __SATCE__
typedef enum
{
    SRV_SAT_CLOSE_CHANNEL_FINISHED,
    SRV_SAT_SEND_DATA_FINISHED,
    SRV_SAT_SEND_DATA_TERMINATED,
    SRV_SAT_RECEIVE_DATA_FINISHED,
    SRV_SAT_RECEIVE_DATA_TERMINATED,
    SRV_SAT_DISCONNECT_EVENT_DOWNLOAD
} srv_sat_notify_mmi_enum;
#endif


typedef struct
{
    MMI_BOOL available;
    U8 id;
    srv_sat_icon_enum attr;
    U8 *data;
    MMI_BOOL copy_only;
} srv_sat_icon_struct;


typedef struct
{
    U8 cmd_detail[5];
    srv_sat_priority_enum priority;
    srv_sat_clear_enum clear_type;
    WCHAR *text_string;
    srv_sat_icon_struct icon;
    U32 reserved;
    MMI_BOOL immediate_res;
} srv_sat_display_text_struct;


typedef struct
{
    U8 cmd_detail[5];
    srv_sat_input_enum input_type;
    srv_sat_dcs_enum dcs_type;
    MMI_BOOL help_available;
    WCHAR *text_string;
    srv_sat_icon_struct icon;
} srv_sat_get_inkey_struct;


typedef struct
{
    U8 cmd_detail[5];
    srv_sat_input_enum input_type;
    srv_sat_dcs_enum dcs_type;
    MMI_BOOL echo_mode;
    MMI_BOOL help_available;
    WCHAR *text_string;
    S32 min_length;
    S32 max_length;
    WCHAR *default_text;
    srv_sat_icon_struct icon;
} srv_sat_get_input_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *alpha_id;
    audio_id_enum tone;
    U16 duration;
    srv_sat_icon_struct icon;
} srv_sat_play_tone_struct;


typedef struct
{
    srv_sat_refresh_enum refresh_type;
} srv_sat_refresh_struct;


typedef struct
{
    U8 id;
    WCHAR *alpha_id;
    srv_sat_cmd_enum next_action_ind;
    srv_sat_icon_struct icon;
} srv_sat_item_struct;


typedef struct
{
    U8 cmd_detail[5];
    MMI_BOOL help_available;
    WCHAR *alpha_id;
    S32 num_of_item;
    srv_sat_item_struct *item_list;
    srv_sat_icon_struct icon;
    MMI_BOOL present;
} srv_sat_setup_menu_struct;


typedef struct
{
    U8 cmd_detail[5];
    MMI_BOOL help_available;
    WCHAR *alpha_id;
    S32 num_of_item;
    srv_sat_item_struct *item_list;
    U8 default_id;
    srv_sat_icon_struct icon;
} srv_sat_select_item_struct;


typedef struct
{
    U8 cmd_detail[5];
    MMI_BOOL sms_packed;
    WCHAR *alpha_id;
    U8 addr_len;
    U8 *addr;
    U8 tpdu_len;
    U8 *tpdu;
    srv_sat_icon_struct icon;
} srv_sat_send_sms_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *alpha_id;
    U8 cc_type;
    U8 ss_len;
    U8 *ss_string;
    U8 length;
    U8 *additional_info;
    WCHAR *text_string;
    srv_sat_icon_struct icon;
} srv_sat_send_ss_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *alpha_id;
    U8 cc_type;
    U8 ussd_dcs;
    U8 ussd_len;
    U8 *ussd_string;
    U8 length;
    U8 *additional_info;
    WCHAR *text_string;
    srv_sat_icon_struct icon;
} srv_sat_send_ussd_struct;


typedef struct
{
    U8 cmd_detail[5];
    srv_sat_setup_enum condition;
    srv_sat_call_disconnect_enum disconnect_cause;
    WCHAR *alpha_id1;
    U8 *number;
    U8 cc_type;
    U8 addr_len;
    U8 *addr;
    U8 ccp_len;
    U8 *ccp;
    U8 subadrr_len;
    U8 *subadrr;
    srv_sat_icon_struct icon1;
    WCHAR *alpha_id2;
    srv_sat_icon_struct icon2;
} srv_sat_setup_call_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *text_string;
    srv_sat_icon_struct icon;
    MMI_BOOL present;
} srv_sat_setup_idle_mode_text_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *alpha_id;
    srv_sat_icon_struct icon;
} srv_sat_run_at_command_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *alpha_id;
    U8 dtmf_len;
    U8 *dtmf_string;
    srv_sat_icon_struct icon;
} srv_sat_send_dtmf_struct;


typedef struct
{
    U8 cmd_detail[5];
    U8 is_specified;
    U8 lang[2];
} srv_sat_language_notification_struct;


typedef struct
{
    U8 cmd_detail[5];
    srv_sat_launch_enum browser_mode;
    U8 browser_identity;
    U16 url_len;
    U8 *url;
    U16 bearer_len;
    U8 *bearer;
    U16 gateway_len;
    U8 *gateway;
    WCHAR *alpha_id;
    srv_sat_icon_struct icon;
} srv_sat_launch_browser_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *alpha_id;
    srv_sat_icon_struct icon;
} srv_sat_open_channel_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *alpha_id;
    srv_sat_icon_struct icon;
} srv_sat_close_channel_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *alpha_id;
    srv_sat_icon_struct icon;
} srv_sat_send_data_struct;


typedef struct
{
    U8 cmd_detail[5];
    WCHAR *alpha_id;
    srv_sat_icon_struct icon;
} srv_sat_receive_data_struct;


typedef struct
{
    mmi_sim_enum sim_id;
    srv_sat_cmd_enum cmd_type;
    union
    {
        srv_sat_display_text_struct display_text;
        srv_sat_get_inkey_struct get_inkey;
        srv_sat_get_input_struct get_input;
        srv_sat_play_tone_struct play_tone;
        srv_sat_refresh_struct refresh;
        srv_sat_setup_menu_struct setup_menu;
        srv_sat_select_item_struct select_item;
        srv_sat_send_sms_struct send_sms;
        srv_sat_send_ss_struct send_ss;
        srv_sat_send_ussd_struct send_ussd;
        srv_sat_setup_call_struct setup_call;
        srv_sat_setup_idle_mode_text_struct setup_idle_mode_text;
        srv_sat_run_at_command_struct run_at_command;
        srv_sat_send_dtmf_struct send_dtmf;
        srv_sat_language_notification_struct language_notification;
        srv_sat_launch_browser_struct launch_browser;
        srv_sat_open_channel_struct open_channel;
        srv_sat_close_channel_struct close_channel;
        srv_sat_send_data_struct send_data;
        srv_sat_receive_data_struct receive_data;
    } cmd_data;
} srv_sat_proactive_sim_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_sat_proactive_sim_struct *proactive_sim;
} srv_sat_proactive_sim_event_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_sim_enum sim_id;
    MMI_BOOL present;
} srv_sat_setup_menu_event_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_sim_enum sim_id;
    MMI_BOOL present;
} srv_sat_setup_idle_display_event_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_sim_enum sim_id;
    MMI_BOOL full_change;
    srv_sat_refresh_enum refresh_type;
    S32 num_of_file;
    U16 file_list[120];
} srv_sat_sim_refresh_event_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_sim_enum sim_id;
} srv_sat_session_end_event_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    WCHAR *alpha_id;
} srv_sat_sim_ctrl_info_event_struct;


/*****************************************************************************
 * FUNCTION
 *  srv_sat_init
 * DESCRIPTION
 *  This function is used to register SAT primitives.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_last_proactive_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  srv_sat_proactive_sim_struct*
 *****************************************************************************/
extern const srv_sat_proactive_sim_struct* srv_sat_get_last_proactive_sim(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_free_last_proactive_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  cmd_type:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_free_last_proactive_sim(mmi_sim_enum sim_id, srv_sat_cmd_enum cmd_type);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_setup_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  srv_sat_setup_menu_struct*
 *****************************************************************************/
extern const srv_sat_setup_menu_struct* srv_sat_get_setup_menu(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_setup_idle_mode_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  srv_sat_setup_idle_mode_text_struct*
 *****************************************************************************/
extern const srv_sat_setup_idle_mode_text_struct* srv_sat_get_setup_idle_mode_text(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_display_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_display_text(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                srv_sat_additional_res_enum additional_res);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_get_inkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  is_yes_selected:[IN]        
 *  text_string:    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_get_inkey(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                MMI_BOOL is_yes_selected,
                WCHAR *text_string);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_get_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  text_string:    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_get_input(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                WCHAR *text_string);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_play_tone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_play_tone(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_setup_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_setup_menu(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_select_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  item_id:        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_select_item(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                U8 item_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_sms_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_send_sms_stage1(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_sms_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_send_sms_stage2(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                srv_sat_additional_res_enum additional_res);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_ss_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_send_ss_stage1(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_ss_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  length:         [IN]        
 *  additional_info:[IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_send_ss_stage2(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                U8 length,
                U8 *additional_info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_ussd_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_send_ussd_stage1(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_ussd_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  length:         [IN]        
 *  additional_info:[IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_send_ussd_stage2(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                U8 length,
                U8 *additional_info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_setup_call_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_setup_call_stage1(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_setup_call_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_setup_call_stage2(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                srv_sat_additional_res_enum additional_res);

#ifndef __SAT_LOWCOST_UI_DISABLE__


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_provide_language_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  lang:           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_provide_language_info(mmi_sim_enum sim_id, U8 *lang);

#endif /* __SAT_LOWCOST_UI_DISABLE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_terminal_response_refresh(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_setup_idle_mode_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_setup_idle_mode_text(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_dtmf_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_send_dtmf_stage1(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_dtmf_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_send_dtmf_stage2(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                srv_sat_additional_res_enum additional_res);

#ifndef __SAT_LOWCOST_UI_DISABLE__


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_language_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_language_notification(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res);

#ifdef __SATCC__
#ifdef BROWSER_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_launch_browser_stage1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_launch_browser_stage1(mmi_sim_enum sim_id);

#endif /* BROWSER_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_launch_browser_stage2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_launch_browser_stage2(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                srv_sat_additional_res_enum additional_res);

#endif
#endif /* __SAT_LOWCOST_UI_DISABLE__ */

#ifdef __SATCE__


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_open_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 *  additional_res: [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_open_channel(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res,
                srv_sat_additional_res_enum additional_res);


#ifdef __SRV_SAT_TR_CLOSE_CHANNEL__
/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_close_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_close_channel(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res);
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_send_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_send_data(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_terminal_response_receive_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  terminal_res:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_terminal_response_receive_data(
                mmi_sim_enum sim_id,
                srv_sat_terminal_res_enum terminal_res);

#endif /* __SATCE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_menu_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  item_id:        [IN]        
 *  help_request:   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_envelope_menu_selection(mmi_sim_enum sim_id, U8 item_id, MMI_BOOL help_request);

#ifndef __SAT_LOWCOST_UI_DISABLE__


/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_idle_screen_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_envelope_idle_screen_available(void);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_language_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang:           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_envelope_language_selection(U8 *lang);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_envelope_browser_termination
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  cause:          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_envelope_browser_termination(
                mmi_sim_enum sim_id,
                srv_sat_browser_termination_enum cause);

#endif /* __SAT_LOWCOST_UI_DISABLE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_setup_call_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_setup_call_abort_req(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_dtmf_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_send_dtmf_abort_req(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_is_menu_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_is_menu_present(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_menu_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
extern const WCHAR* srv_sat_get_menu_title(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_menu_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  item_index:     [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
extern const WCHAR* srv_sat_get_menu_item(mmi_sim_enum sim_id, S32 item_index);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_is_idle_display_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_is_idle_display_present(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_idle_display_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
extern const WCHAR* srv_sat_get_idle_display_text(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_idle_display_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  U8*
 *****************************************************************************/
extern const U8* srv_sat_get_idle_display_icon(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_get_call_display_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
extern const WCHAR* srv_sat_get_call_display_text(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_set_call_disconnect_cause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  cause:          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_set_call_disconnect_cause(mmi_sim_enum sim_id, srv_sat_call_disconnect_enum cause);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_session_reset
 * DESCRIPTION
 *  reset SAT session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_session_reset(void);


typedef struct
{
    MMI_BOOL result;
    mmi_sim_enum sim_id;
    U16 timer_id;
    void *user_data;
} srv_sat_callback_struct;


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_sat_callback_func_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_data:  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_sat_callback_func_ptr) (srv_sat_callback_struct *callback_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  timer_id:       [IN]        
 *  duration:       [IN]        
 *  callback:       [IN]        
 *  user_data:      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_start_timer(
                mmi_sim_enum sim_id,
                U16 timer_id,
                U16 duration,
                srv_sat_callback_func_ptr callback,
                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_stop_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  timer_id:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_stop_timer(mmi_sim_enum sim_id, U16 timer_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_pause_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  timer_id:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_pause_timer(mmi_sim_enum sim_id, U16 timer_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_resume_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id:         [IN]        
 *  timer_id:       [IN]        
 *  is_reset:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_resume_timer(mmi_sim_enum sim_id, U16 timer_id, MMI_BOOL is_reset);

/* DOM-NOT_FOR_SDK-END */

#ifdef __cplusplus
}
#endif

#endif /* SATSRVGPROT_H */

