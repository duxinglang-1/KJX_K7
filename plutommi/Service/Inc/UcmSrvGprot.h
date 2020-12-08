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
 *  UcmSrvGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM 3.0 external interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SRV_UCM_GPROT_H
#define SRV_UCM_GPROT_H

#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "FileMgrSrvGProt.h"
//#include "wgui_categories_list.h"
#include "mmi_res_range_def.h"
#include "custom_mmi_default_value.h" /* for MMI_PHB_NAME_LENGTH */
#include "PhbSrvGprot.h" /* for  srv_phb_caller_res_id_struct */
#include "App_datetime.h"

#if defined(__MMI_UCM__)
    #ifndef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
    #define __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
    #endif
    #ifndef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
    #define __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__
    #endif
    #ifndef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
    #define __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
    #endif
    #ifndef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__
    #define __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_DIAL__
    #endif
    #ifndef __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__
    #define __MMI_UCM_COMPOUND_ACTION_END_ALL_AND_ACCEPT__
    #endif
#endif /* defined(__MMI_UCM__) */

#if defined(__MMI_UCM_SLIM__)
    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
    #undef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
    #endif
    #ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
    #undef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
    #endif
#endif /* defined(__MMI_UCM_SLIM__) */

/* Maximum active group number */
#define SRV_UCM_MAX_ACTIVE_GROUP (1)

/* Maximum held group number */
#define SRV_UCM_MAX_HELD_GROUP (4)

/* Maximum group number */
#define SRV_UCM_MAX_GROUP (4)

/* Maximum call number in a group */
#define SRV_UCM_MAX_CALL_IN_GROUP (5)

/* Maximum call number in a group */
#define SRV_UCM_MAX_CALL (8)

/* Maximum diplay name length */
#define SRV_UCM_MAX_DISP_NAME_LEN (MAX_SUBMENU_CHARACTERS)

/* Maximum number length */
#define SRV_UCM_MAX_NUM_URI_LEN (41)

/* Maximum dtmf string length */
#define SRV_UCM_MAX_DTMF_STR_LEN (41)

/* Maximum auto redial message length */
#define SRV_UCM_MAX_AUTO_REDIAL_MSG_LEN (150)

/* Invalid ID */
#define SRV_UCM_INVALID_ID (255)

/* Invalid Index */
#define SRV_UCM_INVALID_INDEX (-1)

/* Maximum IP number length */
#define SRV_UCM_MAX_IP_NUMBER_LEN (10)

/* Maximum error message length */
#define SRV_UCM_MAX_ERR_MSG_LEN (50)

/* Maximum display message length */
#define SRV_UCM_MAX_DISP_MSG_LEN (150)

/* Need to intercept the outgoing call */
#define SRV_UCM_INTERCEPT_QUERY_RESULT_YES 1

/* NO need to intercept the outgoing call */
#define SRV_UCM_INTERCEPT_QUERY_RESULT_NO MMI_RET_OK

/* For background call, it is ok to exit when the outoging is connected */
#define SRV_UCM_APP_EXIT_QUERY_RESULT_YES MMI_RET_OK

/* For background call, it is not ok to exit when the outoging is connected */
#define SRV_UCM_APP_EXIT_QUERY_RESULT_NO 1


/* Call state enum */
typedef enum
{
    SRV_UCM_IDLE_STATE = 0x00, /* IDLE state */
    SRV_UCM_OUTGOING_STATE = 0x01, /* Outgoing state */
    SRV_UCM_INCOMING_STATE = 0x02, /* Incoming state */
    SRV_UCM_ACTIVE_STATE = 0x04, /* Active state */
    SRV_UCM_HOLD_STATE = 0x08, /* Hold state */
    SRV_UCM_CALL_STATE_END_OF_ENUM /* End of the enum */
} srv_ucm_call_state_enum;

/* All States */
#define SRV_UCM_CALL_STATE_ALL (srv_ucm_call_state_enum) (SRV_UCM_OUTGOING_STATE | SRV_UCM_INCOMING_STATE | SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE)

/* Connected States, active state and held state */
#define SRV_UCM_CALL_STATE_CONNECTED (srv_ucm_call_state_enum) (SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE)

/* Call type enum */
typedef enum
{
    SRV_UCM_INVALID_CALL_TYPE       = 0x0000, /* Invalid call type, for fixing build warnings */
    SRV_UCM_VOICE_CALL_TYPE         = 0x0001, /* SIM1 voice call type */
    SRV_UCM_DATA_CALL_TYPE          = 0x0002, /* SIM1 data call type */
    SRV_UCM_CSD_CALL_TYPE           = 0x0004, /* SIM1 csd call type */
    SRV_UCM_VIDEO_CALL_TYPE         = 0x0008, /* Video call type*/
    SRV_UCM_VOIP_CALL_TYPE          = 0x0010, /* VoIP call type */
    SRV_UCM_VOICE_CALL_TYPE_SIM2    = 0x0020, /* SIM2 voice call type */
    SRV_UCM_DATA_CALL_TYPE_SIM2     = 0x0040, /* SIM2 data call type */
    SRV_UCM_CSD_CALL_TYPE_SIM2      = 0x0080, /* SIM2 csd call type */
    SRV_UCM_VIDEO_CALL_TYPE_SIM2    = 0x0100, /* Video call type*/
    SRV_UCM_VOICE_CALL_TYPE_SIM3    = 0x0200, /* SIM3 voice call type */
    SRV_UCM_DATA_CALL_TYPE_SIM3     = 0x0400, /* SIM3 data call type */
    SRV_UCM_CSD_CALL_TYPE_SIM3      = 0x0800, /* SIM3 csd call type */
    SRV_UCM_VOICE_CALL_TYPE_SIM4    = 0x1000, /* SIM4 voice call type */
    SRV_UCM_DATA_CALL_TYPE_SIM4     = 0x2000, /* SIM4 data call type */
    SRV_UCM_CSD_CALL_TYPE_SIM4      = 0x4000, /* SIM4 csd call type */
    SRV_UCM_CALL_TYPE_END_OF_ENUM /* End of the enum */
} srv_ucm_call_type_enum;

/* Total call type */
#define SRV_UCM_TOTAL_CALL_TYPE (15)

/* All SIM1 call types: voice call, data call, csd call, video call */
#define SRV_UCM_SIM1_CALL_TYPE_ALL (srv_ucm_call_type_enum) (SRV_UCM_VOICE_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE | SRV_UCM_CSD_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE)

/* All SIM2 call types: voice call, data call, csd call */
#define SRV_UCM_SIM2_CALL_TYPE_ALL (srv_ucm_call_type_enum) (SRV_UCM_VOICE_CALL_TYPE_SIM2 | SRV_UCM_DATA_CALL_TYPE_SIM2 | SRV_UCM_CSD_CALL_TYPE_SIM2 | SRV_UCM_VIDEO_CALL_TYPE_SIM2)

/* All SIM3 call types: voice call, data call, csd call */
#define SRV_UCM_SIM3_CALL_TYPE_ALL (srv_ucm_call_type_enum) (SRV_UCM_VOICE_CALL_TYPE_SIM3 | SRV_UCM_DATA_CALL_TYPE_SIM3 | SRV_UCM_CSD_CALL_TYPE_SIM3)

/* All SIM4 call types: voice call, data call, csd call */
#define SRV_UCM_SIM4_CALL_TYPE_ALL (srv_ucm_call_type_enum) (SRV_UCM_VOICE_CALL_TYPE_SIM4 | SRV_UCM_DATA_CALL_TYPE_SIM4 | SRV_UCM_CSD_CALL_TYPE_SIM4)

/* All voice call types: SIM1 voice call/ SIM2 voice call/ SIM3 voice call/SIM4 voice call */
#define SRV_UCM_VOICE_CALL_TYPE_ALL (srv_ucm_call_type_enum) (SRV_UCM_VOICE_CALL_TYPE | SRV_UCM_VOICE_CALL_TYPE_SIM2 | SRV_UCM_VOICE_CALL_TYPE_SIM3 | SRV_UCM_VOICE_CALL_TYPE_SIM4)

/* All data call types: SIM1 data call/ SIM2 data call/ SIM3 data call/ SIM4 data call */
#define SRV_UCM_DATA_CALL_TYPE_ALL (srv_ucm_call_type_enum) (SRV_UCM_DATA_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE_SIM2 | SRV_UCM_DATA_CALL_TYPE_SIM3 | SRV_UCM_DATA_CALL_TYPE_SIM4)

/* All csd call types: SIM1 csd call/ SIM2 csd call/ SIM3 csd call/ SIM4 csd call */
#define SRV_UCM_CSD_CALL_TYPE_ALL (srv_ucm_call_type_enum) (SRV_UCM_CSD_CALL_TYPE | SRV_UCM_CSD_CALL_TYPE_SIM2 | SRV_UCM_CSD_CALL_TYPE_SIM3 | SRV_UCM_CSD_CALL_TYPE_SIM4)

/* All video call types: SIM1 video call/ SIM2 video call */
#define SRV_UCM_VIDEO_CALL_TYPE_ALL (srv_ucm_call_type_enum) (SRV_UCM_VIDEO_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE_SIM2)

/* All call types: all voice calls, csd calls, data calls, voip calls, video calls */
#define SRV_UCM_CALL_TYPE_ALL (srv_ucm_call_type_enum) (SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_DATA_CALL_TYPE_ALL | SRV_UCM_CSD_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE_ALL)

/* All call types except for csd calls */
#define SRV_UCM_CALL_TYPE_NO_CSD (srv_ucm_call_type_enum) (SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_DATA_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE_ALL)

/* All call types except for csd calls and data calls*/
#define SRV_UCM_CALL_TYPE_NO_DATA_CSD (srv_ucm_call_type_enum) (SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE_ALL)

/* All csd calls and data calls*/
#define SRV_UCM_CALL_TYPE_DATA_CSD_ALL (srv_ucm_call_type_enum) (SRV_UCM_DATA_CALL_TYPE_ALL | SRV_UCM_CSD_CALL_TYPE_ALL)

/* UCM error cause enum */
typedef enum
{
    SRV_UCM_RESULT_OK, /* OK */
    SRV_UCM_RESULT_UNSPECIFIED_ERROR, /* Unspecified error */
    SRV_UCM_RESULT_CANCEL, /* Cancel */
    SRV_UCM_RESULT_USER_ABORT, /* User abort */
    SRV_UCM_RESULT_ACTION_NOT_ALLOWED, /* Action not allowed */
    SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL, /* Not allowed to dial */
    SRV_UCM_RESULT_NOT_ALLOWED_TO_ACCEPT, /* Not allowed to accept */
    SRV_UCM_RESULT_NO_ACTIVE_CALL, /* No active call */
    SRV_UCM_RESULT_CALLED_PARTY_BUSY, /* Called party busy */
    SRV_UCM_RESULT_NETWORK_NOT_AVAILABLE, /* Network not available */
    SRV_UCM_RESULT_CALLED_PARTY_NOT_ANSWERED, /* Called party not answered */
    SRV_UCM_RESULT_SOS_NUMBER_ONLY, /* SOS number only */
    SRV_UCM_RESULT_INVALID_NUMBER, /* Invalid number */
    SRV_UCM_RESULT_EMPTY_NUMBER, /* Empty number */
    SRV_UCM_RESULT_SOS_CALL_EXISTS, /* Exist SOS call */
    SRV_UCM_RESULT_PREFERRED_MODE_PROHIBIT, /* Preferred mode prohibit */
    SRV_UCM_RESULT_FLIGHT_MODE_PROHIBIT, /* Flight mode prohibit */
    SRV_UCM_RESULT_LOW_BATTERY, /* Low battery */
    SRV_UCM_RESULT_UCM_BUSY, /* Busy */
    SRV_UCM_RESULT_VT_FALLBACK, /* VT fallback */
    SRV_UCM_RESULT_END_OF_ENUM /* end of the enum */
} srv_ucm_result_enum;

/* Module id enum */
typedef enum
{
    SRV_UCM_MODULE_ORIGIN_COMMON = 0, /* normal */
    SRV_UCM_MODULE_ORIGIN_AT, /* From AT */
    SRV_UCM_MODULE_ORIGIN_AT_SIM2, /* From AT SIM2 */
    SRV_UCM_MODULE_ORIGIN_AT_SIM3, /* From AT SIM3 */
    SRV_UCM_MODULE_ORIGIN_AT_SIM4, /* From AT SIM4 */
    SRV_UCM_MODULE_ORIGIN_SAT, /* From SAT */
    SRV_UCM_MODULE_ORIGIN_URI_AGENT, /* From URI Agent */
    SRV_UCM_MODULE_ORIGIN_CCBS, /* From CCBS */
    SRV_UCM_MODULE_ORIGIN_VOICE_MAIL, /* From Voice Mail */
    SRV_UCM_MODULE_ORIGIN_TOTAL /* Total enum number */
} srv_ucm_module_origin_enum;

/* Action opcode enum */
typedef enum
{
    SRV_UCM_NO_ACT = 0, /* No action */
    SRV_UCM_DIAL_ACT, /* Dial action, srv_ucm_dial_act_req_struct, srv_ucm_act_rsp_struct*/
    SRV_UCM_ACCEPT_ACT, /* Accept action, srv_ucm_single_call_act_req_struct, srv_ucm_act_rsp_struct*/
    SRV_UCM_HOLD_ACT, /* Hold action, srv_ucm_single_group_act_req_struct, srv_ucm_act_rsp_struct*/
    SRV_UCM_RETRIEVE_ACT, /* Retrieve action, srv_ucm_single_group_act_req_struct, srv_ucm_act_rsp_struct */
    SRV_UCM_SWAP_ACT,  /* Swap action, srv_ucm_multiple_group_act_req_struct, srv_ucm_act_rsp_struct */
    SRV_UCM_CONFERENCE_ACT, /* Conference action, srv_ucm_multiple_group_act_req_struct, srv_ucm_act_rsp_struct */
    SRV_UCM_SPLIT_ACT, /* Split action, srv_ucm_single_call_act_req_struct, srv_ucm_act_rsp_struct */
#ifdef __MMI_UCM_DEFLECT__
    SRV_UCM_DEFLECT_ACT, /* Deflect action, srv_ucm_cd_or_ct_act_req_struct, srv_ucm_act_rsp_struct */
#endif /* __MMI_UCM_DEFLECT__ */
#ifdef __MMI_UCM_TRANSFER__
    SRV_UCM_TRANSFER_ACT, /* Transfer action, srv_ucm_cd_or_ct_act_req_struct, srv_ucm_act_rsp_struct */
#endif /* __MMI_UCM_TRANSFER__ */
#ifdef __MMI_UCM_ECT__
    SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT, /* ECT action, srv_ucm_ect_act_req_struct, srv_ucm_act_rsp_struct */
#endif /* __MMI_UCM_ECT__ */
    SRV_UCM_END_SINGLE_ACT, /* End single action, srv_ucm_single_call_act_req_struct, srv_ucm_act_rsp_struct */
    SRV_UCM_END_CONFERENCE_ACT, /* End conference action, srv_ucm_single_group_act_req_struct, srv_ucm_act_rsp_struct */
    SRV_UCM_END_ALL_ACT, /* End all action, null, srv_ucm_act_rsp_struct */
    SRV_UCM_END_ALL_ACTIVE_ACT, /* End all active action, null, srv_ucm_act_rsp_struct */
    SRV_UCM_END_ALL_HELD_ACT, /* End all held action, null, srv_ucm_act_rsp_struct */
    SRV_UCM_END_ALL_PROCESSING_ACT, /* End all processing action, null, srv_ucm_act_rsp_struct */
    SRV_UCM_END_ALL_AND_DIAL_ACT, /* End all and dial action, srv_ucm_dial_act_req_struct, srv_ucm_act_rsp_struct*/
    SRV_UCM_END_ALL_AND_ACCEPT_ACT, /* End all and accept action, srv_ucm_single_call_act_req_struct, srv_ucm_act_rsp_struct*/
    SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT, /* End all active and retrieve action, srv_ucm_single_group_act_req_struct, srv_ucm_act_rsp_struct */
    SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT, /* End all active and accept action, srv_ucm_single_call_act_req_struct, srv_ucm_act_rsp_struct */
    SRV_UCM_HOLD_AND_DIAL_ACT, /* Hold and dial action, srv_ucm_hold_and_dial_act_req_struct, srv_ucm_act_rsp_struct */
    SRV_UCM_HOLD_AND_ACCEPT_ACT, /* Hold and accept action, srv_ucm_hold_and_accept_act_req_struct, srv_ucm_act_rsp_struct */
    SRV_UCM_START_DTMF_ACT, /* Start DTMF action, srv_ucm_dtmf_struct, no response */
    SRV_UCM_STOP_DTMF_ACT, /* Stop DTMF action, null, no response */
    SRV_UCM_SEND_DTMF_DIGITS_ACT, /* Send DTMF string action, srv_ucm_dtmf_digits_struct, srv_ucm_act_rsp_struct */
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    SRV_UCM_VT_FALLTO_VOICE_ACT, /* Accept Video call by Voice call action, srv_ucm_single_call_act_req_struct, srv_ucm_act_rsp_struct*/
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
    SRV_UCM_ACT_OPCODE_TOTAL /* Total enum number */
} srv_ucm_act_opcode_enum;

/* Action type enum */
typedef enum
{
    SRV_UCM_ACT_TYPE_SINGLE = 0, /* Single action */
    SRV_UCM_ACT_TYPE_COMPOUND, /* Compound action */
    SRV_UCM_ACT_TYPE_COMPOUND_FIRST, /* First action in compound action */
    SRV_UCM_ACT_TYPE_COMPOUND_SECOND, /* Second action in compound action */
    SRV_UCM_ACT_TYPE_TOTAL /* Total enum number */
} srv_ucm_act_type_enum;

/* Action notify type enum */
typedef enum
{
    SRV_UCM_ACT_NOTIFY_TYPE_START = 0, /* Action starts  */
    SRV_UCM_ACT_NOTIFY_TYPE_END, /* Action ends */
    SRV_UCM_ACT_NOTIFY_TYPE_TOTAL /* Total enum number */
} srv_ucm_act_notify_type_enum;

/* Indication opcode enum */
typedef enum
{
    SRV_UCM_INCOMING_CALL_IND = 0, /* srv_ucm_incoming_call_ind_struct */
    SRV_UCM_OUTGOING_CALL_IND, /* srv_ucm_outgoing_call_ind_struct */
    SRV_UCM_ALERT_IND, /* srv_ucm_alert_ind_struct */
    SRV_UCM_NOTIFY_IND, /* srv_ucm_notify_ind_struct */
    SRV_UCM_CONNECT_IND, /* srv_ucm_connect_ind_struct */
    SRV_UCM_DISCONNECTING_IND, /* srv_ucm_disconnecting_ind_struct */
    SRV_UCM_RELEASE_IND, /* srv_ucm_release_ind_struct */
    SRV_UCM_CALL_COST_IND, /* srv_ucm_call_cost_ind_struct */
    SRV_UCM_AUTO_REDIAL_IND, /* srv_ucm_auto_redial_ind_struct */
    SRV_UCM_AUTO_REDIAL_CANCEL_IND, /* null */
    SRV_UCM_START_PROCESSING_IND, /* srv_ucm_start_processing_ind_struct */
    SRV_UCM_STOP_PROCESSING_IND, /* srv_ucm_stop_processing_ind_struct */
    SRV_UCM_QUERY_CANCEL_IND, /* null */
    SRV_UCM_REFRESH_IND, /* null */
    SRV_UCM_START_COUNT_IND, /* null */
    SRV_UCM_IND_OPCODE_TOTAL /* Total enum number */
} srv_ucm_ind_opcode_enum;

/* Confirm indication opcode enum */
typedef enum
{
    SRV_UCM_QUERY_CNF_IND = 0, /* srv_ucm_query_cnf_ind_struct */
    SRV_UCM_CNF_IND_OPCODE_TOTAL /* Total enum number */
} srv_ucm_cnf_ind_opcode_enum;

/* Confirm opcode enum */
typedef enum
{
    SRV_UCM_QUERY_CNF = 0, /* srv_ucm_query_cnf_struct */
    SRV_UCM_CNF_OPCODE_TOTAL /* Total enum number */
} srv_ucm_cnf_opcode_enum;

/* SRV_UCM_QUERY_CNF result enum */
typedef enum
{
    SRV_UCM_QUERY_CNF_NO = 0, /* Query result is no */
    SRV_UCM_QUERY_CNF_YES, /* Query result is yes */
    SRV_UCM_QUERY_CNF_ABORT, /* Query is aborted */
    SRV_UCM_QUERY_CNF_TOTAL /* Total enum number */
} srv_ucm_query_cnf_result_enum;

/* Call process state enum */
typedef enum
{
    SRV_UCM_IDLE_PROCESS_STATE = 0, /* No action performing */
    SRV_UCM_WAIT_PROCESS_STATE, /* Waiting to perform action */
    SRV_UCM_DO_PROCESS_STATE, /* Performing action */
    SRV_UCM_COMP_PROCESS_STATE, /* Already performed action, wait for ohters to finish */
    SRV_UCM_PROCESS_STATE_TOTAL /* Total enum number */
} srv_ucm_process_state_enum;


/* Caller resource type enum */
typedef enum
{
    SRV_UCM_RES_TYPE_IMAGE_ID = 0x01,
    SRV_UCM_RES_TYPE_IMAGE_PATH = 0x02,
    SRV_UCM_RES_TYPE_VIDEO_ID  = 0x04,
    SRV_UCM_RES_TYPE_VIDEO_PATH = 0x08,
    SRV_UCM_RES_TYPE_TONE_ID   = 0x10,
    SRV_UCM_RES_TYPE_TONE_PATH = 0x20,
    SRV_UCM_RES_TYPE_END_OF_ENUM /* End of the enum */
} srv_ucm_res_type_enum;


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_ucm_cnf_callback_func_ptr
 * DESCRIPTION
 *  Confirm callback function
 *  When UCM sends confirm indication, a confirm is expected
 * PARAMETERS
 *  op_code:         [IN]        Conform opcode
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_ucm_cnf_callback_func_ptr) (srv_ucm_cnf_opcode_enum op_code, void *ptr);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_ucm_callback_func_ptr
 * DESCRIPTION
 *  General callback function
 * PARAMETERS
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_ucm_callback_func_ptr) (void *ptr);

/* Call id struct, should be unique */
typedef struct
{
    srv_ucm_call_type_enum call_type; /* Call type */
    S16 group_id; /* group id */
    S16 call_id; /* call id*/
} srv_ucm_id_info_struct;

/* Remote info struct */
typedef struct
{
    U16 log_name[MMI_PHB_NAME_LENGTH + 1]; /* Call log name */
    U16 disp_name[SRV_UCM_MAX_DISP_NAME_LEN + 1]; /* Display name */
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
    U16 line_icon; /* Line icon image id or 0 for none */
#ifdef __MMI_UCM_NUMBER_TYPE__
    U16 num_type_icon; /* Number type icon image id or 0 for none */
    mmi_phb_num_type_enum number_type;
#endif /* __MMI_UCM_NUMBER_TYPE__ */
    SRV_PHB_ID phb_id; /* Map to phonebook entry */
} srv_ucm_remote_info_struct;

/* Display info for incoming/outgoing call, include image, video, light, tone, vibration */
typedef struct
{
    U16 ip_num[SRV_UCM_MAX_IP_NUMBER_LEN + 1]; /* IP number, ucs2 */
    U8 alert_type; /* Alert type from user profile */
    U16 light_id; /* LED light id */
} srv_ucm_display_info_struct;

/* Display info for active/held call */
typedef struct
{
    srv_phb_caller_res_id_struct image_info; /* Caller image, video fron phonebook */
} srv_ucm_connected_call_display_info_struct;

/* Result info struct */
typedef struct
{
    srv_ucm_result_enum result; /* Result */
    U16 error_msg[SRV_UCM_MAX_ERR_MSG_LEN + 1]; /* Recommand error message, ucs2 */
} srv_ucm_result_info_struct;

/* Single call action struct */
typedef struct
{
    srv_ucm_id_info_struct action_uid; /* Call id */
} srv_ucm_single_call_act_req_struct;

/* Single group action struct */
typedef struct
{
    srv_ucm_call_type_enum call_type; /* Call type */
    S16 action_group; /* Group id */
} srv_ucm_single_group_act_req_struct;

/* Multiple group action struct */
typedef struct
{
    S16 active_group; /* Active group id */
    srv_ucm_call_type_enum active_call_type; /* Active call type */
    S16 other_group; /* Other group id */
    srv_ucm_call_type_enum other_call_type; /* Other call type */
} srv_ucm_multiple_group_act_req_struct;

/* ECT action struct */
typedef struct
{
    S16 first_group; /* First group id */
    srv_ucm_call_type_enum first_call_type; /* First call type */
    S16 second_group; /* Second group id */
    srv_ucm_call_type_enum second_call_type; /* Second call type */
} srv_ucm_ect_act_req_struct;

/* Dial action struct */
typedef struct
{
    srv_ucm_call_type_enum call_type; /* Call type */
    U16 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number, ucs2 */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
    MMI_BOOL is_ip_dial; /* IP dial, currently only for GSM&3G */
    void *phb_data; /* Bypass phonebook data for call service to query caller info */
} srv_ucm_dial_act_req_struct;

/* Hold and dial action sctuct */
typedef struct
{
    S16 active_group; /* Active call group */
    srv_ucm_call_type_enum active_call_type; /* Active call type */
    srv_ucm_call_type_enum dial_call_type; /* Dial call type */
    U16 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number, ucs2 */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
    MMI_BOOL is_ip_dial; /* add comment here, ex. DIAL permit for voip should return FALSE */
    void *phb_data; /* Bypass phonebook data for call service to query caller info */
} srv_ucm_hold_and_dial_act_req_struct;

/* Hold and accept action sctuct */
typedef struct
{
    S16 active_group; /* Active call group */
    srv_ucm_call_type_enum active_call_type; /* Active call type */
    srv_ucm_id_info_struct mt_call_uid; /* MT call id */
} srv_ucm_hold_and_accept_act_req_struct;

/* Call deflect or call transfer action struct */
typedef struct
{
    srv_ucm_id_info_struct action_uid; /* Action call id */
    U16 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Number, ucs2 */
} srv_ucm_cd_or_ct_act_req_struct;

/* DTMF digit struct */
typedef struct
{
    U16 digit; /* Digit, mmi_keypads_enum */
} srv_ucm_dtmf_struct;

/* DTMF string struct */
typedef struct
{
    U16 length; /* DTMF string length */
    srv_ucm_dtmf_struct dtmf_digits[SRV_UCM_MAX_DTMF_STR_LEN + 1]; /* mmi_keypads_enum */
} srv_ucm_dtmf_digits_struct;

/* Caller resource struct */
typedef struct
{
    srv_ucm_res_type_enum res_type;
    U16 pic_id;                 /* image id, output */
    U16 pic_path[SRV_FMGR_PATH_MAX_LEN + 1];    /* image path, output */
    U16 video_id;                 /* video id, output */
    U16 video_path[SRV_FMGR_PATH_MAX_LEN + 1];    /* video path, output */
    U16 tone_id; /* tone id, output */ 
    U16 tone_path[SRV_FMGR_PATH_MAX_LEN + 1]; /* tone path, output */
    MMI_BOOL is_video_sound;        /* video sound on or off, output */
} srv_ucm_caller_res_struct;


/* Action response struct */
typedef struct
{
    srv_ucm_result_info_struct result_info; /* Result */
    MMI_BOOL no_counter; /* Start to count duration or not, only for accept action */
} srv_ucm_act_rsp_struct;

/* Index struct */
typedef struct
{
    S32 group_index; /* Group index in call table */
    S32 call_index; /* Call index in call table */
} srv_ucm_index_info_struct;

/* Call info struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_call_state_enum call_state; /* Call state */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
    srv_ucm_process_state_enum proc_state; /* Ongoing process state */
    srv_ucm_act_opcode_enum act_op; /* Ongoing action op-code */
    MMI_BOOL is_disconnecting; /* Disconnecting state */
    MYTIME start_time; /* Call start time */
} srv_ucm_call_info_struct;

/* Group info struct */
typedef struct
{
    S16 group_id; /* Group id */
    srv_ucm_call_type_enum call_type;
    srv_ucm_call_state_enum call_state; /* Call state */
} srv_ucm_group_info_struct;

/* Incoming call indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    srv_ucm_display_info_struct display_info; /* Display info */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
} srv_ucm_incoming_call_ind_struct;

/* Outgoing call indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    srv_ucm_display_info_struct display_info; /* Display info */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
} srv_ucm_outgoing_call_ind_struct;

/* Call cost indication struct*/
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    PU8 currency_symbol; /*  Currency symbol, ex: TWD, USD*/
    U32 cost_unit; /* How many unit spent */
    U32 total_cost_unit; /* Total unit spent */
    U32 price_per_unit; /* How much for each unit */
    MMI_BOOL warning; /* Almost no money left */
} srv_ucm_call_cost_ind_struct;

/* Call alert indication struct*/
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    U8 local_gen; /* Require local to generate tone or network will do it */
} srv_ucm_alert_ind_struct;

/* Notify indication stuct */
typedef struct
{
    srv_ucm_call_type_enum call_type; /* Call type */
    U16 disp_msg[SRV_UCM_MAX_DISP_MSG_LEN + 1]; /* Message to user, ucs2 */
    U16 image_id; /* Image to display */
    U16 tone_id; /* Tone to display */
} srv_ucm_notify_ind_struct;

/* Connect indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    MMI_BOOL no_counter; /* Start to count duration or not */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
} srv_ucm_connect_ind_struct;

/* Disconnecting indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
} srv_ucm_disconnecting_ind_struct;

/* Auto redial indication struct */
typedef struct
{
    MMI_BOOL action; /* Need to do post action or not */
    MMI_BOOL is_ip_dial; /* IP dial, currently only for GSM&3G */
    void *phb_data; /* Bypass phonebook data for call service to query caller info */
} srv_ucm_post_action_struct;

/* Release indication struct */
typedef struct
{
    srv_ucm_id_info_struct uid_info; /* Call id */
    srv_ucm_remote_info_struct remote_info; /* Remote info */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
    srv_ucm_call_state_enum previous_state; /* State before being dropped */
    U16 call_end_msg[SRV_UCM_MAX_ERR_MSG_LEN + 1]; /* Call release recommand message according to error cause, ucs2 */
    U16 call_end_image_id; /* Call release image */
    U16 call_end_tone_id; /* Call release tone */
    srv_ucm_result_enum call_end_error_cause; /* Call release error cause */
    MYTIME  start_time; /* Start time */
    applib_time_struct  call_duration; /* Call duration */
    srv_ucm_post_action_struct post_action; /* Need to do post action or not */
} srv_ucm_release_ind_struct;

/* Auto redial indication struct */
typedef struct
{
    U16 display_msg[SRV_UCM_MAX_AUTO_REDIAL_MSG_LEN + 1]; /* Message to inform user, in UCS2 */
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Redial number */
    U8 attempt; /* Redial attempt */
    U8 time; /* Redial after how many seconds */
    FuncPtr abort_hdlr; /* Abort handler */
} srv_ucm_auto_redial_ind_struct;

/* Start processing indication struct */
typedef struct
{
    U16 content[SRV_UCM_MAX_DISP_MSG_LEN + 1]; /* Message display to user, ucs2 */
} srv_ucm_start_processing_ind_struct;

/* Stop processing indication struct */
typedef struct
{
    U16 disp_msg[SRV_UCM_MAX_DISP_MSG_LEN + 1]; /* Message display to user, ucs2 */
    U16 image_id; /* Image display to user */
    U16 tone_id; /* Tone display to user */
} srv_ucm_stop_processing_ind_struct;

/* Query confirm indication struct */
typedef struct
{
    U16 content[SRV_UCM_MAX_DISP_MSG_LEN + 1]; /* The question for user, ucs2 */
} srv_ucm_query_cnf_ind_struct;

/* Query confirm struct */
typedef struct
{
    srv_ucm_query_cnf_result_enum result_info; /* Result */
} srv_ucm_query_cnf_struct;

/* Event id definition */
typedef enum
{
    EVT_ID_SRV_UCM_ACTION_NOTIFY = SRV_UCM_BASE + 1, /* post type, srv_ucm_act_notify_evt_struct, must return MMIO_RET_OK */
    EVT_ID_SRV_UCM_ACTION_RESULT, /* send or post type, srv_ucm_act_result_evt_struct, must return MMIO_RET_OK */
    EVT_ID_SRV_UCM_INDICATION, /* post type, srv_ucm_ind_evt_struct, must return MMIO_RET_OK */
    EVT_ID_SRV_UCM_CNF_INDICATION, /* post type, srv_ucm_cnf_ind_evt_struct, must return MMIO_RET_OK */
    EVT_ID_SRV_UCM_STATUS_CHANGE, /* post type, srv_ucm_status_change_evt_struct, must return MMIO_RET_OK */
    EVT_ID_SRV_UCM_APP_EXIT_QUERY, /* send type, srv_ucm_app_exit_query_evt_struct, return SRV_UCM_APP_EXIT_QUERY_RESULT_YES or SRV_UCM_APP_EXIT_QUERY_RESULT_NO */
    EVT_ID_SRV_UCM_INTERCEPT_QUERY, /* send type, srv_ucm_intercept_query_evt_struct, return SRV_UCM_INTERCEPT_QUERY_RESULT_YES or SRV_UCM_INTERCEPT_QUERY_RESULT_NO */
    EVT_ID_SRV_UCM_SHORT_STRING_CRSS, /* post type, srv_ucm_short_string_crss_evt_struct, return MMI_RET_OK */
    EVT_ID_SRV_UCM_TOTAL
} srv_ucm_event_enum;

/* event structure for EVT_ID_SRV_UCM_ACTION_NOTIFY */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ucm_act_opcode_enum comp_act_op; /* Compound action op-code */
    srv_ucm_act_opcode_enum act_op; /* Action op-code */
    srv_ucm_act_type_enum act_type; /* Action type, single action or compound action */
    srv_ucm_act_notify_type_enum notify_type; /* Start or end */
    void *ptr; /* Data pointer */
} srv_ucm_act_notify_evt_struct;

/* event structure for EVT_ID_SRV_UCM_ACTION_RESULT */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ucm_act_opcode_enum act_op; /* Action op-code */
    void *act_result; /* Action reslut */
} srv_ucm_act_result_evt_struct;

/* event structure for EVT_ID_SRV_UCM_INDICATION */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ucm_ind_opcode_enum ind_type; /* Indication type */
    void *ptr; /* Data pointer */
} srv_ucm_ind_evt_struct;

/* event structure for EVT_ID_SRV_UCM_CNF_INDICATION */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ucm_cnf_ind_opcode_enum op_code; /* Confirm indication opcode */
    void *ptr; /* Data pointer */
    srv_ucm_cnf_callback_func_ptr cnf_callback; /* confirm callback when get the answer */
} srv_ucm_cnf_ind_evt_struct;

/* event structure for EVT_ID_SRV_UCM_INTERCEPT_QUERY */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ucm_call_type_enum call_type; /* Can be bitwise */
    U8 num_uri[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* Dialing number, ascii */
    srv_ucm_module_origin_enum module_id; /* Initiate module id */
} srv_ucm_intercept_query_evt_struct; 

/* event structure for EVT_ID_SRV_UCM_APP_EXIT_QUERY */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
} srv_ucm_app_exit_query_evt_struct;

/* event structure for EVT_ID_SRV_UCM_STATUS_CHANGE */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
} srv_ucm_status_change_evt_struct; 

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_init
 * DESCRIPTION
 *  Initialize UCM service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ucm_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_act_request
 * DESCRIPTION
 *  The function to perform actions in srv_ucm_act_opcode_enum
 * PARAMETERS
 *  act_op:          [IN]        Action op-code
 *  act_data:        [IN]        Action data
 *  user_data:       [IN]        User data
 *  result_callback: [IN]        Result callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ucm_act_request(srv_ucm_act_opcode_enum act_op, void *act_data, void *user_data, mmi_proc_func result_callback);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_act_permit
 * DESCRIPTION
 *  The function to query if the action is permitted
 *  For SRV_UCM_DIAL_ACT, SRV_UCM_DEFLECT_ACT and SRV_UCM_TRANSFER_ACT,
 *  number won't be considered because number is dynamically input by user
 * PARAMETERS
 *  act_op:          [IN]        Action op-code
 *  ptr:             [IN]        Data pointer
 * RETURNS
 *  srv_ucm_result_enum
 *****************************************************************************/
extern srv_ucm_result_enum srv_ucm_query_act_permit(srv_ucm_act_opcode_enum act_op, void *ptr);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_call_count
 * DESCRIPTION
 *  The function to query call information, you can specify call state, call type,
 *  and get call count and index list as return
 *  Call index and group index will be initialized as -1, which means invalid index
 * PARAMETERS
 *  call_state:      [IN]        Call state
 *  call_type:       [IN]        Call type
 *  indexs_list:     [OUT]       Index list, array size is SRV_UCM_MAX_CALL, include group index and call index
 * RETURNS
 *  Call count
 *****************************************************************************/
extern S32 srv_ucm_query_call_count(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, srv_ucm_index_info_struct *index_list);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_disconnecting_call_count
 * DESCRIPTION
 *  The function to query disconnecting call information, you can specify call state, call type,
 *  and get call count and index list as return
 *  Call index and group index will be initialized as -1, which means invalid index
 * PARAMETERS
 *  call_state:      [IN]        Call state
 *  call_type:       [IN]        Call type
 *  indexs_list:     [OUT]       Index list, array size is SRV_UCM_MAX_CALL, include group index and call index
 * RETURNS
 *  Call count
 *****************************************************************************/
extern S32 srv_ucm_query_disconnecting_call_count(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, srv_ucm_index_info_struct *index_list);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_call_data
 * DESCRIPTION
 *  From srv_ucm_query_call_count, you have group index and call index,
 *  this function is for you to get more detail information
 * PARAMETERS
 *  index:           [IN]        Call index and group index
 *  call_info:       [OUT]       Detail information for the specified call 
 * RETURNS
 *  MMI_TRUE means the call is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_call_data(srv_ucm_index_info_struct index, srv_ucm_call_info_struct *call_info);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_group_count
 * DESCRIPTION
 *  The function to query group information, you can specify call state, call type,
 *  and get group count and group index list as return
 *  Group index will be initialized as -1 which means invalid index
 * PARAMETERS
 *  call_state:      [IN]        Call state
 *  call_type:       [IN]        Call type
 *  single_only:     [IN]        Only care the groups with single call in it
 *  index_list:      [OUT]       Group index list, array size is SRV_UCM_MAX_GROUP
 * RETURNS
 *  Group count
 *****************************************************************************/
extern S32 srv_ucm_query_group_count(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, MMI_BOOL single_only, S32 *index_list);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_group_data
 * DESCRIPTION
 *  From srv_ucm_query_group_count, you have group index,
 *  this function is for you to get more detail information
 * PARAMETERS
 *  group_index:     [IN]        Group index
 *  group_info:      [OUT]       Group information
 * RETURNS
 *  Call count in the group
 *****************************************************************************/
extern S32 srv_ucm_query_group_data(S32 group_index, srv_ucm_group_info_struct *group_info);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_call_exist
 * DESCRIPTION
 *  Query if the call exists
 * PARAMETERS 
 *  uid_info:        [IN]        UID
 *  call_state:      [IN]        call state, can be bitwise
 * RETURNS
 *  MMI_TRUE means the call is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_call_exist(srv_ucm_id_info_struct* uid_info, srv_ucm_call_state_enum call_state);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_group_exist
 * DESCRIPTION
 *  Query if the group exists
 * PARAMETERS 
 *  group_id:        [IN]        group id
 *  call_type:       [IN]        call type
 *  call_state:      [IN]        call state, can be bitwise
 * RETURNS
 *  MMI_TRUE means the group is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_group_exist(S32 group_id, srv_ucm_call_type_enum call_type, srv_ucm_call_state_enum call_state);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_index_by_id
 * DESCRIPTION
 *  Get group index and call index from uid
 *  Call index and group index will be initialized as -1, which means invalid index
 * PARAMETERS 
 *  uid_info         [IN]        UID
 *  index:           [OUT]       Index contains group index and call index
 * RETURNS
 *  MMI_TRUE means the call is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_index_by_id(srv_ucm_id_info_struct* uid_info, srv_ucm_index_info_struct* index);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_group_index_by_group_id
 * DESCRIPTION
 *  Get group index from group id
 *  Group index will be initialized as -1, which means invalid index
 * PARAMETERS 
 *  group_id         [IN]        group id
 *  call_type        [IN]        call type, can't be bitwise, should be unique
 *  group_index:     [OUT]       group index
 * RETURNS
 *  MMI_TRUE means the group is found. Otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_group_index_by_group_id(S16 group_id, srv_ucm_call_type_enum call_type, S32* group_index);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_curr_action
 * DESCRIPTION
 *  Query current ongoing action
 * PARAMETERS 
 * 
 * RETURNS
 *  srv_ucm_act_opcode_enum: current action
 *****************************************************************************/
extern srv_ucm_act_opcode_enum srv_ucm_query_curr_action(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_reject_by_sms_permit
 * DESCRIPTION
 *  The function to query if reject by SMS is permitted
 * PARAMETERS
 *  mt_call_uid:     [IN]        MT call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_reject_by_sms_permit(srv_ucm_single_call_act_req_struct mt_call_uid);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_reject_by_sms
 * DESCRIPTION
 *  The function to reject the MT call and send SMS
 * PARAMETERS
 *  mt_call_uid:     [IN]        MT call id
 *  ucs2_content:    [IN]        SMS content
 *  sim_id:          [IN]        Send by which SIM
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_ucm_reject_by_sms(srv_ucm_single_call_act_req_struct mt_call_uid, CHAR* ucs2_content, mmi_sim_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_intercept
 * DESCRIPTION
 *  The function to intercept the outgoing call
 * PARAMETERS
 *  call_type:          [IN]        Call type, can be bitwise
 *  number:          [IN]        Number, SRV_UCM_MAX_NUM_URI_LEN
 *  module_id:        [IN]        Module id, who initiates the outoging call
 * RETURNS
 *  MMI_TRUE means the outgoing call is intercepted, MMI_FALSE means not
 *****************************************************************************/
extern MMI_BOOL srv_ucm_intercept(srv_ucm_call_type_enum call_type, U16 *number, srv_ucm_module_origin_enum module_id);

#ifdef __MMI_BACKGROUND_CALL__
/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_app_exit
 * DESCRIPTION
 *  Query function for if there is any app who doesn't want to exit,
 *  when the background outgoing call is connected
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means all apps can exit
 *  MMI_FALSE means any of apps can't exit
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_app_exit(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_background_call
 * DESCRIPTION
 *  Function to query if it is in background call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is background call. The background call may be outgoing, incoming, active, and held calls.
 *  MMI_FALSE means there is no call, there is foreground call, or there is CSD call.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_background_call(void);
#endif /* __MMI_BACKGROUND_CALL__*/

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_incoming_call
 * DESCRIPTION
 *  check if there is incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is incoming call.
 *  MMI_FALSE means there is no incoming call.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_incoming_call(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_outgoing_call
 * DESCRIPTION
 *  check if there is outgoing call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is outgoing call.
 *  MMI_FALSE means there is no outgoing call.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_outgoing_call(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_any_call
 * DESCRIPTION
 *  check if there is any call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is any call.
 *  MMI_FALSE means there is no call.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_any_call(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_emergency_call
 * DESCRIPTION
 *  check if there is emergency call exists
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is emergency call.
 *  MMI_FALSE means there is no emergency call.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_emergency_call(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_call_srv_available
 * DESCRIPTION
 *  The function to query if the call type service is available now
 * PARAMETERS
 *  call_type:       [IN]        Call type
 * RETURNS
 *  MMI_TRUE means any of input cal types is available
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_call_srv_available(srv_ucm_call_type_enum call_type);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_call_srv_tmp_unavailable
 * DESCRIPTION
 *  The function to query if the call type service is temporarily unavailable now
 * PARAMETERS
 *  call_type:       [IN]        Call type
 * RETURNS
 *  MMI_TRUE means any of input cal types is temporarily unavailable now
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_call_srv_tmp_unavailable(srv_ucm_call_type_enum call_type);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_pending_action
 * DESCRIPTION
 *  The function to query if there is any pending action
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means there is pending action; MMI_FALSE means there is not.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_pending_action(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_busy
 * DESCRIPTION
 *  The function to query if UCM service is busy
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means UCM service is busy; MMI_FALSE means UCM service is not busy.
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_busy(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_valid_number
 * DESCRIPTION
 *  The function to check if the number is valid or not
 * PARAMETERS
 *  call_type:      [IN]        Call type, can use bitwise value to query multiple call types
 *  number:         [IN]        Number, ascii
 * RETURNS
 *  MMI_TRUE means it is valid number for any of input cal types
 *  MMI_FALSE means it is not valid number for any of input cal types
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_valid_number(srv_ucm_call_type_enum call_type, U8 *number);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_emergency_number
 * DESCRIPTION
 *  The function to check if the number is emergency number or not
 * PARAMETERS
 *  call_type:      [IN]        Call type, can use bitwise value to query multiple call types 
 *  number:         [IN]        Number, ascii
 * RETURNS
 *  MMI_TRUE means it is emergency number for any of input cal types
 *  MMI_FALSE means it is not emergency number for any of input cal types
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_emergency_number(srv_ucm_call_type_enum call_type, U8 *number);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_is_valid_dtmf_digit
 * DESCRIPTION
 *  The function to check if the digit is valid DTMF digit or not
 * PARAMETERS
 *  call_type:       [IN]        Call type, can use bitwise value to query multiple call types 
 *  digit:           [IN]        Digit
 * RETURNS
 *  MMI_TRUE means it is valid DTMF digit for any of input cal types
 *  MMI_FALSE means it is not valid DTMF digit for any of input cal types
 *****************************************************************************/
extern MMI_BOOL srv_ucm_is_valid_dtmf_digit(srv_ucm_call_type_enum call_type, U16 digit);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_get_caller_res_info
 * DESCRIPTION
 *  get caller resource information
 * PARAMETERS
 *  call_id:         [IN]         call id
 *  res_info:        [OUT]        resource information
 * RETURNS
 *  MMI_TRUE means res_info is valid
 *  MMI_FALSE means res_info is invalid (get caller res info fails)
 *****************************************************************************/
extern MMI_BOOL srv_ucm_get_caller_res_info(srv_ucm_id_info_struct call_id, srv_ucm_caller_res_struct *res_info);


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_error_message
 * DESCRIPTION
 *  Default error message for srv_ucm_result_enum
 * PARAMETERS
 *  error_cause:     [IN]        Error cause
 * RETURNS
 *  String ID for error message
 *****************************************************************************/
extern U16 srv_ucm_query_error_message(srv_ucm_result_enum error_cause);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_mute_permit
 * DESCRIPTION
 *  The function to query if Mute function is permitted
 * PARAMETERS
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_mute_permit(srv_ucm_id_info_struct call_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_loudspeaker_permit
 * DESCRIPTION
 *  The function to query if Loud Speaker is permitted
 * PARAMETERS
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_loudspeaker_permit(srv_ucm_id_info_struct call_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_sndrec_permit
 * DESCRIPTION
 *  The function to query if Sound Recorder is permitted
 * PARAMETERS
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_sndrec_permit(srv_ucm_id_info_struct call_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_bgs_in_call_permit
 * DESCRIPTION
 *  The function to query if Background Sound during in call is permitted
 * PARAMETERS
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_TRUE means user is permitted to choose Background Sound during active/held call
 *  MMI_FALSE means user is not permitted to choose Background Sound during active/held call
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_bgs_in_call_permit(srv_ucm_id_info_struct call_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_bgs_incoming_call_permit
 * DESCRIPTION
 *  The function to query if Background Sound during incoming call is permitted
 * PARAMETERS
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_TRUE means user is permitted to choose Background Sound during incoming call
 *  MMI_FALSE means user is not permitted to choose Background Sound during incoming call
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_bgs_incoming_call_permit(srv_ucm_id_info_struct call_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_bgs_outgoing_call_permit
 * DESCRIPTION
 *  The function to query if Background Sound before outgoing call is permitted
 * PARAMETERS
 *  call_type:       [IN]        Outgoing call type
 * RETURNS
 *  MMI_TRUE means user is permitted to choose Background Sound before making outgoing call
 *  MMI_FALSE means user is not permitted to choose Background Sound before making outgoing call
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_bgs_outgoing_call_permit(srv_ucm_call_type_enum call_type);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_switch_bt_audio_path_permit
 * DESCRIPTION
 *  The function to query if BT audio path switch function is permitted
 * PARAMETERS
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_switch_bt_audio_path_permit(srv_ucm_id_info_struct call_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_connect_last_bt_device_permit
 * DESCRIPTION
 *  The function to query if Connect Last BT Device is permitted
 * PARAMETERS
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_connect_last_bt_device_permit(srv_ucm_id_info_struct call_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_connect_ctm_permit
 * DESCRIPTION
 *  The function to query if Connect CTM is permitted
 * PARAMETERS
 *  call_id:       [IN]        Call id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_ucm_query_connect_ctm_permit(srv_ucm_id_info_struct call_id);


/*****************************************************************************
 * FUNCTION
 *  srv_ucm_query_voice_type_by_sim
 * DESCRIPTION
 *  Get ucm service voice call type by sim id
 * PARAMETERS
 *  sim_id       [IN]        sim id
 * RETURNS
 *  voice call type
 *****************************************************************************/
srv_ucm_call_type_enum srv_ucm_query_voice_type_by_sim(mmi_sim_enum sim_id);

#endif /* SRV_UCM_GPROT_H */ 

