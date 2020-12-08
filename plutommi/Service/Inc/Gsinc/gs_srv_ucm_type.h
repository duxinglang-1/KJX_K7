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
 *   gs_srv_ucm_type.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IUcm type header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _GS_SRV_UCM_TYPE_
#define _GS_SRV_UCM_TYPE_

/* Maximum number length, including null character ,MUST be same with SRV_UCM_MAX_NUM_URI_LEN+1*/
#define GS_SRV_UCM_MAX_NUM_URI_LEN (42)
/* Maximum error message length */
#define GS_SRV_UCM_MAX_ERR_MSG_LEN (50)
/*Maximum common length*/
#define GS_SRV_COMMON_MAX_LENGTH (64)
/* The maximum length of a file's fullpath,  including null character */
#define GS_SRV_FMGR_PATH_MAX_LEN   (260)
/* Maximum call number in a group */
#define GS_SRV_UCM_MAX_CALL (8)
/* Maximum group number */
#define GS_SRV_UCM_MAX_GROUP (4)

typedef enum
{
    GS_SRV_UCM_IDLE_STATE = 0x00, /* IDLE state */
    GS_SRV_UCM_OUTGOING_STATE = 0x01, /* Outgoing state */
    GS_SRV_UCM_INCOMING_STATE = 0x02, /* Incoming state */
    GS_SRV_UCM_ACTIVE_STATE = 0x04, /* Active state */
    GS_SRV_UCM_HOLD_STATE = 0x08, /* Hold state */
    GS_SRV_UCM_CALL_STATE_END_OF_ENUM /* End of the enum */
} gs_srv_ucm_call_state_enum;

/* All States */
#define GS_SRV_UCM_CALL_STATE_ALL (GS_SRV_UCM_OUTGOING_STATE | GS_SRV_UCM_INCOMING_STATE | GS_SRV_UCM_ACTIVE_STATE | GS_SRV_UCM_HOLD_STATE)

/* Connected States, active state and held state */
#define GS_SRV_UCM_CALL_STATE_CONNECTED (GS_SRV_UCM_ACTIVE_STATE | GS_SRV_UCM_HOLD_STATE)

/* Call type enum */
typedef enum
{
    GS_SRV_UCM_VOICE_CALL_TYPE = 0x01, /* SIM1 voice call type */
    GS_SRV_UCM_VOICE_CALL_TYPE_SIM2 = 0x02, /* SIM2 voice call type */
    GS_SRV_UCM_DATA_CALL_TYPE  = 0x04, /* SIM1 data call type */
    GS_SRV_UCM_DATA_CALL_TYPE_SIM2 = 0x08, /* SIM2 data call type */
    GS_SRV_UCM_CSD_CALL_TYPE   = 0x10, /* SIM1 csd call type */
    GS_SRV_UCM_CSD_CALL_TYPE_SIM2 = 0x20, /* SIM2 csd call type */
    GS_SRV_UCM_VOIP_CALL_TYPE  = 0x40, /* VoIP call type */
    GS_SRV_UCM_VIDEO_CALL_TYPE = 0x80, /* Video call type*/
    GS_SRV_UCM_CALL_TYPE_END_OF_ENUM /* End of the enum */
} gs_srv_ucm_call_type_enum;

/* Total call type */
#define GS_SRV_UCM_TOTAL_CALL_TYPE (8)

/* All SIM1 call types: voice call, data call, csd call */
#define GS_SRV_UCM_SIM1_CALL_TYPE_ALL (GS_SRV_UCM_VOICE_CALL_TYPE | GS_SRV_UCM_DATA_CALL_TYPE | GS_SRV_UCM_CSD_CALL_TYPE)

/* All SIM2 call types: voice call, data call, csd call */
#define GS_SRV_UCM_SIM2_CALL_TYPE_ALL (GS_SRV_UCM_VOICE_CALL_TYPE_SIM2 | GS_SRV_UCM_DATA_CALL_TYPE_SIM2 | GS_SRV_UCM_CSD_CALL_TYPE_SIM2)

/* All voice call types: SIM1 voice call/ SIM2 voice call */
#define GS_SRV_UCM_VOICE_CALL_TYPE_ALL (GS_SRV_UCM_VOICE_CALL_TYPE | GS_SRV_UCM_VOICE_CALL_TYPE_SIM2)

/* All data call types: SIM1 data call/ SIM2 data call */
#define GS_SRV_UCM_DATA_CALL_TYPE_ALL (GS_SRV_UCM_DATA_CALL_TYPE | GS_SRV_UCM_DATA_CALL_TYPE_SIM2)

/* All csd call types: SIM1 csd call/ SIM2 csd call */
#define GS_SRV_UCM_CSD_CALL_TYPE_ALL (GS_SRV_UCM_CSD_CALL_TYPE | GS_SRV_UCM_CSD_CALL_TYPE_SIM2)

/* All call types: all voice calls, csd calls, data calls, voip calls, video calls */
#define GS_SRV_UCM_CALL_TYPE_ALL (GS_SRV_UCM_VOICE_CALL_TYPE_ALL | GS_SRV_UCM_DATA_CALL_TYPE_ALL | GS_SRV_UCM_CSD_CALL_TYPE_ALL | GS_SRV_UCM_VOIP_CALL_TYPE | GS_SRV_UCM_VIDEO_CALL_TYPE)

/* All call types except for csd calls */
#define GS_SRV_UCM_CALL_TYPE_NO_CSD (GS_SRV_UCM_VOICE_CALL_TYPE_ALL | GS_SRV_UCM_DATA_CALL_TYPE_ALL | GS_SRV_UCM_VOIP_CALL_TYPE | GS_SRV_UCM_VIDEO_CALL_TYPE)

/* All call types except for csd calls and data calls*/
#define GS_SRV_UCM_CALL_TYPE_NO_DATA_CSD (GS_SRV_UCM_VOICE_CALL_TYPE_ALL | GS_SRV_UCM_VOIP_CALL_TYPE | GS_SRV_UCM_VIDEO_CALL_TYPE)

/* All call types except for SIM2 call types*/
#define GS_SRV_UCM_CALL_TYPE_NO_SIM2 (GS_SRV_UCM_SIM1_CALL_TYPE_ALL | GS_SRV_UCM_VOIP_CALL_TYPE | GS_SRV_UCM_VIDEO_CALL_TYPE)

/* All csd calls and data calls*/
#define GS_SRV_UCM_CALL_TYPE_DATA_CSD_ALL (GS_SRV_UCM_DATA_CALL_TYPE_ALL | GS_SRV_UCM_CSD_CALL_TYPE_ALL)

/* UCM error cause enum */
typedef enum
{
    GS_SRV_UCM_RESULT_OK, /* OK */
    GS_SRV_UCM_RESULT_UNSPECIFIED_ERROR, /* Unspecified error */
    GS_SRV_UCM_RESULT_CANCEL, /* Cancel */
    GS_SRV_UCM_RESULT_USER_ABORT, /* User abort */
    GS_SRV_UCM_RESULT_ACTION_NOT_ALLOWED, /* Action not allowed */
    GS_SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL, /* Not allowed to dial */
    GS_SRV_UCM_RESULT_NOT_ALLOWED_TO_ACCEPT, /* Not allowed to accept */
    GS_SRV_UCM_RESULT_NO_ACTIVE_CALL, /* No active call */
    GS_SRV_UCM_RESULT_CALLED_PARTY_BUSY, /* Called party busy */
    GS_SRV_UCM_RESULT_NETWORK_NOT_AVAILABLE, /* Network not available */
    GS_SRV_UCM_RESULT_CALLED_PARTY_NOT_ANSWERED, /* Called party not answered */
    GS_SRV_UCM_RESULT_SOS_NUMBER_ONLY, /* SOS number only */
    GS_SRV_UCM_RESULT_INVALID_NUMBER, /* Invalid number */
    GS_SRV_UCM_RESULT_EMPTY_NUMBER, /* Empty number */
    GS_SRV_UCM_RESULT_SOS_CALL_EXISTS, /* Exist SOS call */
    GS_SRV_UCM_RESULT_PREFERRED_MODE_PROHIBIT, /* Preferred mode prohibit */
    GS_SRV_UCM_RESULT_FLIGHT_MODE_PROHIBIT, /* Flight mode prohibit */
    GS_SRV_UCM_RESULT_LOW_BATTERY, /* Low battery */
    GS_SRV_UCM_RESULT_UCM_BUSY, /* Busy */
    GS_SRV_UCM_RESULT_END_OF_ENUM /* end of the enum */
} gs_srv_ucm_result_enum;

/* Module id enum */
typedef enum
{
    GS_SRV_UCM_MODULE_ORIGIN_COMMON = 0, /* normal */
    GS_SRV_UCM_MODULE_ORIGIN_AT, /* From AT */
    GS_SRV_UCM_MODULE_ORIGIN_AT_SIM2, /* From AT SIM2 */
    GS_SRV_UCM_MODULE_ORIGIN_SAT, /* From SAT */
    GS_SRV_UCM_MODULE_ORIGIN_URI_AGENT, /* From URI Agent */
    GS_SRV_UCM_MODULE_ORIGIN_CCBS, /* From CCBS */
    GS_SRV_UCM_MODULE_ORIGIN_VOICE_MAIL, /* From Voice Mail */
    GS_SRV_UCM_MODULE_ORIGIN_TOTAL /* Total enum number */
} gs_srv_ucm_module_origin_enum;

/* Action opcode enum */
typedef enum
{
    GS_SRV_UCM_NO_ACT = 0, /* No action */
    GS_SRV_UCM_DIAL_ACT, /* Dial action, gs_srv_ucm_dial_act_req_struct, gs_srv_ucm_act_rsp_struct*/
    GS_SRV_UCM_ACCEPT_ACT, /* Accept action, gs_srv_ucm_single_call_act_req_struct, gs_srv_ucm_act_rsp_struct*/
    GS_SRV_UCM_HOLD_ACT, /* Hold action, gs_srv_ucm_single_group_act_req_struct, gs_srv_ucm_act_rsp_struct*/
    GS_SRV_UCM_RETRIEVE_ACT, /* Retrieve action, gs_srv_ucm_single_group_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_SWAP_ACT,  /* Swap action, gs_srv_ucm_multiple_group_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_CONFERENCE_ACT, /* Conference action, gs_srv_ucm_multiple_group_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_SPLIT_ACT, /* Split action, gs_srv_ucm_single_call_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_DEFLECT_ACT, /* Deflect action, gs_srv_ucm_cd_or_ct_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_TRANSFER_ACT, /* Transfer action, gs_srv_ucm_cd_or_ct_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, /* ECT action, gs_srv_ucm_ect_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_END_SINGLE_ACT, /* End single action, gs_srv_ucm_single_call_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_END_CONFERENCE_ACT, /* End conference action, gs_srv_ucm_single_group_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_END_ALL_ACT, /* End all action, null, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_END_ALL_ACTIVE_ACT, /* End all active action, null, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_END_ALL_HELD_ACT, /* End all held action, null, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_END_ALL_PROCESSING_ACT, /* End all processing action, null, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_END_ALL_AND_DIAL_ACT, /* End all and dial action, gs_srv_ucm_dial_act_req_struct, gs_srv_ucm_act_rsp_struct*/
    GS_SRV_UCM_END_ALL_AND_ACCEPT_ACT, /* End all and accept action, gs_srv_ucm_single_call_act_req_struct, gs_srv_ucm_act_rsp_struct*/
    GS_SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, /* End all active and retrieve action, gs_srv_ucm_single_group_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT, /* End all active and accept action, gs_srv_ucm_single_call_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_HOLD_AND_DIAL_ACT, /* Hold and dial action, gs_srv_ucm_hold_and_dial_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_HOLD_AND_ACCEPT_ACT, /* Hold and accept action, gs_srv_ucm_hold_and_accept_act_req_struct, gs_srv_ucm_act_rsp_struct */
    GS_SRV_UCM_START_DTMF_ACT, /* Start DTMF action, gs_srv_ucm_dtmf_struct, no response */
    GS_SRV_UCM_STOP_DTMF_ACT, /* Stop DTMF action, null, no response */
    GS_SRV_UCM_ACT_OPCODE_TOTAL /* Total enum number */
} gs_srv_ucm_act_opcode_enum;

/* Action type enum */
typedef enum
{
    GS_SRV_UCM_ACT_TYPE_SINGLE = 0, /* Single action */
    GS_SRV_UCM_ACT_TYPE_COMPOUND, /* Compound action */
    GS_SRV_UCM_ACT_TYPE_COMPOUND_FIRST, /* First action in compound action */
    GS_SRV_UCM_ACT_TYPE_COMPOUND_SECOND, /* Second action in compound action */
    GS_SRV_UCM_ACT_TYPE_TOTAL /* Total enum number */
} gs_srv_ucm_act_type_enum;

/* Action notify type enum */
typedef enum
{
    GS_SRV_UCM_ACT_NOTIFY_TYPE_START = 0, /* Action starts  */
    GS_SRV_UCM_ACT_NOTIFY_TYPE_END, /* Action ends */
    GS_SRV_UCM_ACT_NOTIFY_TYPE_TOTAL /* Total enum number */
} gs_srv_ucm_act_notify_type_enum;

/* Indication opcode enum */
typedef enum
{
    GS_SRV_UCM_INCOMING_CALL_IND = 0, /* gs_srv_ucm_incoming_call_ind_struct */
    GS_SRV_UCM_OUTGOING_CALL_IND, /* gs_srv_ucm_outgoing_call_ind_struct */
    GS_SRV_UCM_ALERT_IND, /* gs_srv_ucm_alert_ind_struct */
    GS_SRV_UCM_NOTIFY_IND, /* gs_srv_ucm_notify_ind_struct */
    GS_SRV_UCM_CONNECT_IND, /* gs_srv_ucm_connect_ind_struct */
    GS_SRV_UCM_DISCONNECTING_IND, /* gs_srv_ucm_disconnecting_ind_struct */
    GS_SRV_UCM_RELEASE_IND, /* gs_srv_ucm_release_ind_struct */
    GS_SRV_UCM_CALL_COST_IND, /* gs_srv_ucm_call_cost_ind_struct */
    GS_SRV_UCM_AUTO_REDIAL_IND, /* gs_srv_ucm_auto_redial_ind_struct */
    GS_SRV_UCM_AUTO_REDIAL_CANCEL_IND, /* null */
    GS_SRV_UCM_START_PROCESSING_IND, /* gs_srv_ucm_start_processing_ind_struct */
    GS_SRV_UCM_STOP_PROCESSING_IND, /* gs_srv_ucm_stop_processing_ind_struct */
    GS_SRV_UCM_QUERY_CANCEL_IND, /* null */
    GS_SRV_UCM_REFRESH_IND, /* null */
    GS_SRV_UCM_IND_OPCODE_TOTAL /* Total enum number */
} gs_srv_ucm_ind_opcode_enum;

/* Confirm indication opcode enum */
typedef enum
{
    GS_SRV_UCM_QUERY_CNF_IND = 0, /* gs_srv_ucm_query_cnf_ind_struct */
    GS_SRV_UCM_CNF_IND_OPCODE_TOTAL /* Total enum number */
} gs_srv_ucm_cnf_ind_opcode_enum;

/* Confirm opcode enum */
typedef enum
{
    GS_SRV_UCM_QUERY_CNF = 0, /* gs_srv_ucm_query_cnf_struct */
    GS_SRV_UCM_CNF_OPCODE_TOTAL /* Total enum number */
} gs_srv_ucm_cnf_opcode_enum;

/* GS_SRV_UCM_QUERY_CNF result enum */
typedef enum
{
    GS_SRV_UCM_QUERY_CNF_NO = 0, /* Query result is no */
    GS_SRV_UCM_QUERY_CNF_YES, /* Query result is yes */
    GS_SRV_UCM_QUERY_CNF_ABORT, /* Query is aborted */
    GS_SRV_UCM_QUERY_CNF_TOTAL /* Total enum number */
} gs_srv_ucm_query_cnf_result_enum;

/* Call process state enum */
typedef enum
{
    GS_SRV_UCM_IDLE_PROCESS_STATE = 0, /* No action performing */
    GS_SRV_UCM_WAIT_PROCESS_STATE, /* Waiting to perform action */
    GS_SRV_UCM_DO_PROCESS_STATE, /* Performing action */
    GS_SRV_UCM_COMP_PROCESS_STATE, /* Already performed action, wait for ohters to finish */
    GS_SRV_UCM_PROCESS_STATE_TOTAL /* Total enum number */
} gs_srv_ucm_process_state_enum;


/* Caller resource type enum */
typedef enum
{
    GS_SRV_UCM_RES_TYPE_IMAGE_ID = 0x01,
    GS_SRV_UCM_RES_TYPE_IMAGE_PATH = 0x02,
    GS_SRV_UCM_RES_TYPE_VIDEO_ID  = 0x04,
    GS_SRV_UCM_RES_TYPE_VIDEO_PATH = 0x08,
    GS_SRV_UCM_RES_TYPE_TONE_ID   = 0x10,
    GS_SRV_UCM_RES_TYPE_TONE_PATH = 0x20,
    GS_SRV_UCM_RES_TYPE_END_OF_ENUM /* End of the enum */
} gs_srv_ucm_res_type_enum;

typedef enum
{
    GS_SRV_UCM__SIM_NONE = 0, /* No bit-wise operation for none case */
    GS_SRV_UCM__SIM1 = 0x0001,
    GS_SRV_UCM__SIM2 = 0x0002,
    GS_SRV_UCM__SIM_END_OF_ENUM
}gs_srv_ucm_sim_enum;

typedef struct
{
    U16 evt_id;                 
    U16 size;                   
    void *user_data;
}gs_srv_event_struct;

typedef S32 (*gs_srv_callback_func) (gs_srv_event_struct *param);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  gs_srv_ucm_cnf_callback_func_ptr
 * DESCRIPTION
 *  Confirm callback function
 *  When UCM sends confirm indication, a confirm is expected
 * PARAMETERS
 *  op_code:         [IN]        Conform opcode
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*gs_srv_ucm_cnf_callback_func_ptr) (gs_srv_ucm_cnf_opcode_enum op_code, void *ptr);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  gs_srv_ucm_callback_func_ptr
 * DESCRIPTION
 *  General callback function
 * PARAMETERS
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*gs_srv_ucm_callback_func_ptr) (void *ptr);

typedef struct
{
    U8 storage_type;
    U8 number_index;
    U16 contact_index;
}gs_srv_ucm_phb_number_id;

typedef gs_srv_ucm_phb_number_id GS_SRV_PHB_ID;

/* Remote info struct */
typedef struct
{
    U16 log_name[GS_SRV_COMMON_MAX_LENGTH]; /* Call log name */
    U16 disp_name[GS_SRV_COMMON_MAX_LENGTH]; /* Display name */
    U8 num_uri[GS_SRV_UCM_MAX_NUM_URI_LEN]; /* Number, ascii */
    U16 line_icon; /* Line icon image id or 0 for none */
    U16 num_type_icon; /* Number type icon image id or 0 for none */
    GS_SRV_PHB_ID phb_id; /* Map to phonebook entry */
} gs_srv_ucm_remote_info_struct;


/* Call id struct, should be unique */
typedef struct
{
    gs_srv_ucm_call_type_enum call_type; /* Call type */
    S16 group_id; /* group id */
    S16 call_id; /* call id*/
} gs_srv_ucm_id_info_struct;


/* Caller resource struct */
typedef struct
{
    gs_srv_ucm_res_type_enum res_type;
    U16 pic_id;                 /* image id, output */
    U16 pic_path[GS_SRV_FMGR_PATH_MAX_LEN];    /* image path, output */
    U16 video_id;                 /* video id, output */
    U16 video_path[GS_SRV_FMGR_PATH_MAX_LEN];    /* video path, output */
    U16 tone_id; /* tone id, output */ 
    U16 tone_path[GS_SRV_FMGR_PATH_MAX_LEN]; /* tone path, output */
    MMI_BOOL is_video_sound;        /* video sound on or off, output */
} gs_srv_ucm_caller_res_struct;


/* Index struct */
typedef struct
{
    S32 group_index; /* Group index in call table */
    S32 call_index; /* Call index in call table */
} gs_srv_ucm_index_info_struct;

typedef struct
{
    U16 nYear;
    U8 nMonth;
    U8 nDay;
    U8 nHour;
    U8 nMin;
    U8 nSec;
    U8 DayIndex; /* 0=Sunday */
} gs_srv_ucm_time_struct;

/* Call info struct */
typedef struct
{
    gs_srv_ucm_id_info_struct uid_info; /* Call id */
    gs_srv_ucm_call_state_enum call_state; /* Call state */
    gs_srv_ucm_remote_info_struct remote_info; /* Remote info */
    gs_srv_ucm_module_origin_enum module_id; /* Initiate module id */
    gs_srv_ucm_process_state_enum proc_state; /* Ongoing process state */
    gs_srv_ucm_act_opcode_enum act_op; /* Ongoing action op-code */
    MMI_BOOL is_disconnecting; /* Disconnecting state */
    gs_srv_ucm_time_struct start_time; /* Call start time */
} gs_srv_ucm_call_info_struct;

/* Group info struct */
typedef struct
{
    S16 group_id; /* Group id */
    gs_srv_ucm_call_type_enum call_type;
    gs_srv_ucm_call_state_enum call_state; /* Call state */
} gs_srv_ucm_group_info_struct;

/* Single call action struct */
typedef struct
{
    gs_srv_ucm_id_info_struct action_uid; /* Call id */
} gs_srv_ucm_single_call_act_req_struct;

/* Single group action struct */
typedef struct
{
    gs_srv_ucm_call_type_enum call_type; /* Call type */
    S16 action_group; /* Group id */
} gs_srv_ucm_single_group_act_req_struct;

/* Multiple group action struct */
typedef struct
{
    S16 active_group; /* Active group id */
    gs_srv_ucm_call_type_enum active_call_type; /* Active call type */
    S16 other_group; /* Other group id */
    gs_srv_ucm_call_type_enum other_call_type; /* Other call type */
} gs_srv_ucm_multiple_group_act_req_struct;

/* ECT action struct */
typedef struct
{
    S16 first_group; /* First group id */
    gs_srv_ucm_call_type_enum first_call_type; /* First call type */
    S16 second_group; /* Second group id */
    gs_srv_ucm_call_type_enum second_call_type; /* Second call type */
} gs_srv_ucm_ect_act_req_struct;

/* Dial action struct */
typedef struct
{
    gs_srv_ucm_call_type_enum call_type; /* Call type */
    U16 num_uri[GS_SRV_UCM_MAX_NUM_URI_LEN]; /* Number, ucs2 */
    gs_srv_ucm_module_origin_enum module_id; /* Initiate module id */
    MMI_BOOL is_ip_dial; /* IP dial, currently only for GSM&3G */
    void *phb_data; /* Bypass phonebook data for call service to query caller info */
} gs_srv_ucm_dial_act_req_struct;

/* Hold and dial action sctuct */
typedef struct
{
    S16 active_group; /* Active call group */
    gs_srv_ucm_call_type_enum active_call_type; /* Active call type */
    gs_srv_ucm_call_type_enum dial_call_type; /* Dial call type */
    U16 num_uri[GS_SRV_UCM_MAX_NUM_URI_LEN]; /* Number, ucs2 */
    gs_srv_ucm_module_origin_enum module_id; /* Initiate module id */
    MMI_BOOL is_ip_dial; /* add comment here, ex. DIAL permit for voip should return FALSE */
    void *phb_data; /* Bypass phonebook data for call service to query caller info */
} gs_srv_ucm_hold_and_dial_act_req_struct;

/* Hold and accept action sctuct */
typedef struct
{
    S16 active_group; /* Active call group */
    gs_srv_ucm_call_type_enum active_call_type; /* Active call type */
    gs_srv_ucm_id_info_struct mt_call_uid; /* MT call id */
} gs_srv_ucm_hold_and_accept_act_req_struct;

/* Call deflect or call transfer action struct */
typedef struct
{
    gs_srv_ucm_id_info_struct action_uid; /* Action call id */
    U16 num_uri[GS_SRV_UCM_MAX_NUM_URI_LEN]; /* Number, ucs2 */
} gs_srv_ucm_cd_or_ct_act_req_struct;

#endif /* _GS_SRV_UCM_TYPE_ */ 

