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
 *  CallSetSrvGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Call setting service global prototypes
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SRV_CALLSET_GPROT_H
#define SRV_CALLSET_GPROT_H

#include "mmi_rp_srv_callset_def.h" /* event id */

#include "UcmSrvGprot.h" /* SRV_UCM_MAX_NUM_URI_LEN */

#include "MMI_features.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"


/****************************************************************************
* Define
*****************************************************************************/

#ifdef __MMI_CALLSET_CUG__
/* Maximum number of closed user group */
#define  SRV_CALLSET_CUG_MAX_GROUP_NUM 10

/* Maximum closed user group name length */
#define  SRV_CALLSET_CUG_MAX_NAME_LENGTH 16
#endif /* __MMI_CALLSET_CUG__ */

#ifdef __MMI_CM_BLACK_LIST__
/* Maximum number of blacklist item */
#define SRV_CALLSET_BLACKLIST_MAX_ITEM 20
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __MMI_CM_WHITE_LIST__
/* Maximum number of whitelist item */
#define SRV_CALLSET_WHITELIST_MAX_ITEM 20
#endif /* __MMI_CM_WHITE_LIST__ */

#ifdef __IP_NUMBER__
/* Maximum number of ip number */
#define SRV_CALLSET_MAX_IP_NUMBER      3

/* Maximum ip number length */
#define SRV_CALLSET_MAX_IP_NUMBER_LEN  10
#else /* __IP_NUMBER__ */
/* Maximum ip number length when __IP_NUMBER__ is off, for category usage */
#define SRV_CALLSET_MAX_IP_NUMBER_LEN  0
#endif /* __IP_NUMBER__ */

/* Minimum time of call time reminder single mode */
#define SRV_CALLSET_CTR_MIN_SINGLE_TIME 1

/* Maximum time of call time reminder single mode */
#define SRV_CALLSET_CTR_MAX_SINGLE_TIME 3000

/* Minimum time of call time reminder periodic mode */
#define SRV_CALLSET_CTR_MIN_PERIODIC_TIME 30

/* Maximum time of call time reminder periodic mode */
#define SRV_CALLSET_CTR_MAX_PERIODIC_TIME 60

#ifdef __MMI_CH_QUICK_END__
/* Minimum time of auto quick end */
#define SRV_CALLSET_AUTO_QUICK_END_MIN 1

/* Maximum time of auto quick end */
#define SRV_CALLSET_AUTO_QUICK_END_MAX 9999
#endif /* __MMI_CH_QUICK_END__ */

/* Maximum line count */
#define SRV_CALLSET_MAX_LINE 2



/****************************************************************************
* Typedef                                                            
*****************************************************************************/

#ifdef __BUILD_DOM__
/* 
 * event id
 */
typedef enum
{
    EVT_ID_SRV_CALLSET_ACT_RESPONSE = SRV_CALLSET_BASE + 1, /* srv_callset_rsp_evt_struct */
    EVT_ID_SRV_CALLSET_LINE_SWITCHED, /* srv_callset_line_switched_evt_struct */
    EVT_ID_SRV_CALLSET_CFU_STATUS_IND, /* srv_callset_cfu_status_evt_struct */
    EVT_ID_SRV_CALLSET_CTM_SETTING_CHANGED, /* srv_callset_ctm_setting_changed_evt_struct */

    EVT_ID_SRV_CALLSET_TOTAL
} srv_callset_evt_enum;
#endif /* __BUILD_DOM__ */

#ifdef MOTION_SENSOR_SUPPORT
typedef enum
{
    EVT_ID_SRV_FLIP_TO_MUTE_CALL_EX = EVT_ID_SRV_FLIP_TO_MUTE_CALL,
    EVT_ID_SRV_FLIP_TO_MUTE_CALL_TOTAL
} srv_callset_flip_to_mute_call_enum;

typedef enum
{
    EVT_ID_SRV_TAP_TAP_TO_RECORD_IN_CALL_EX = EVT_ID_SRV_TAP_TAP_TO_RECORD_IN_CALL,
    EVT_ID_SRV_TAP_TAP_TO_RECORD_IN_CALL_TOTAL
} srv_callset_tap_tap_to_record_in_call_enum;
#endif 


#ifdef __MMI_CALLSET_CALLER_ID__
/* 
 * Caller id mode
 */
typedef enum
{
    SRV_CALLSET_CALLER_ID_HIDE, /* hide caller ID */
    SRV_CALLSET_CALLER_ID_SHOW, /* show caller ID */
    SRV_CALLSET_CALLER_ID_BY_NETWORK, /* decide by the network */
    SRV_CALLSET_CALLER_ID_TOTAL /* max enum */
} srv_callset_caller_id_mode_enum;
#endif /* __MMI_CALLSET_CALLER_ID__ */


/* 
 * Line type
 */
typedef enum
{
    SRV_CALLSET_LINE_NOT_SUPPORT, /* not support */
    SRV_CALLSET_LINE1, /* line 1 */
    SRV_CALLSET_LINE2, /* line 2 */
    SRV_CALLSET_LINE_END_OF_ENUM /* End of the enum */
} srv_callset_line_id_enum;


/* 
 * CFU status
 */
typedef enum
{
    SRV_CALLSET_CFU_NOT_SUPPORT = 0x00, /* CFU not support */
    SRV_CALLSET_CFU_OFF = 0x01, /* CFU off */
    SRV_CALLSET_CFU_LINE1_ACTIVATED = 0x02, /* line1 CFU activated */
    SRV_CALLSET_CFU_LINE2_ACTIVATED = 0x04, /* line2 CFU activated */
    SRV_CALLSET_CFU_STATUS_END_OF_ENUM = 0xff /* End of the enum */
} srv_callset_cfu_status_enum;


#ifdef __MMI_CALLSET_CUG__
/* 
 * Closed user group status
 */
typedef enum
{
    SRV_CALLSET_CUG_DEACTIVATED = 0, /* deactivated */
    SRV_CALLSET_CUG_ACTIVATED, /* activated */
    SRV_CALLSET_CUG_STATUS_TOTAL /* max enum */
} srv_callset_cug_status_enum;
#endif /* __MMI_CALLSET_CUG__ */


/* 
 * call type
 */
typedef enum
{
   SRV_CALLSET_VOICE_CALL = 0x01, /* voice call */
   SRV_CALLSET_VIDEO_CALL = 0x02, /* video call */
   SRV_CALLSET_CALL_TYPE_INVALID = 0x00 /* max enum */
} srv_callset_call_type_enum;
#define SRV_CALLSET_ALL_CALL ((srv_callset_call_type_enum)(SRV_CALLSET_VOICE_CALL | SRV_CALLSET_VIDEO_CALL))


#ifdef __MMI_CM_BLACK_LIST__
/* 
 * Blacklist mode
 */
typedef enum
{
    SRV_CALLSET_BLACKLIST_OFF = 0x00, /* blacklist is off */
    SRV_CALLSET_BLACKLIST_FROM_LIST = 0x01, /* reject the numbers in the list */
    SRV_CALLSET_BLACKLIST_UNKNOWN_CALLER = 0x02, /* reject unknown numbers  */
    SRV_CALLSET_BLACKLIST_REJECT_ALL = 0x04, /* reject all numbers */
    SRV_CALLSET_BLACKLIST_MODE_END_OF_ENUM = 0x08 /* max enum */
} srv_callset_blacklist_mode_enum;
#endif /* __MMI_CM_BLACK_LIST__ */


#ifdef __MMI_CM_WHITE_LIST__
/* 
 * Whitelist mode
 */
typedef enum
{
    SRV_CALLSET_WHITELIST_OFF = 0x00, /* whitelist is off */
    SRV_CALLSET_WHITELIST_FROM_LIST = 0x01, /* auto answer the numbers in the list */
    SRV_CALLSET_WHITELIST_MODE_END_OF_ENUM = 0x02 /* max enum */
} srv_callset_whitelist_mode_enum;
#endif /* __MMI_CM_WHITE_LIST__ */


/* 
 * Call time reminder mode
 */
typedef enum
{
    SRV_CALLSET_CTR_MODE_OFF = 0, /* call time reminder is off */
    SRV_CALLSET_CTR_MODE_SINGLE, /* call time reminder is single reminder */
    SRV_CALLSET_CTR_MODE_PERIODIC, /* call time reminder is periodic remidner */
    SRV_CALLSET_CTR_MODE_TOTAL /* max enum */
} srv_callset_ctr_mode_enum;


/* 
 * Answer mode
 */
typedef enum
{
    SRV_CALLSET_ANSWER_MODE_OFF = 0x00, /* no specific answering mode */
    SRV_CALLSET_ANSWER_MODE_CLAMSHELL = 0x01, /* answer when opening clamshell */
    SRV_CALLSET_ANSWER_MODE_ANYKEY = 0x02, /* answer by any key */
    SRV_CALLSET_ANSWER_MODE_AUTO = 0x04, /* auto answer when headset is plugged in */
    SRV_CALLSET_ANSWER_MODE_END_OF_ENUM = 0x08 /* max enum */
} srv_callset_answer_mode_enum;


#ifdef __IP_NUMBER__
/* 
 * IP number status
 */
typedef enum
{
    SRV_CALLSET_IP_NUMBER_OFF = 0x00, /* off */
    SRV_CALLSET_IP_NUMBER_SIM1_ACTIVATED = 0x01, /* sim1 activated */
    SRV_CALLSET_IP_NUMBER_SIM2_ACTIVATED = 0x02, /* sim2 activated */
    SRV_CALLSET_IP_NUMBER_SIM3_ACTIVATED = 0x04, /* sim3 activated */
    SRV_CALLSET_IP_NUMBER_SIM4_ACTIVATED = 0x08, /* sim4 activated */
    SRV_CALLSET_IP_NUMBER_STATUS_END_OF_ENUM  /* max enum */
} srv_callset_ip_number_status_enum;
#endif /* __IP_NUMBER__ */


/* 
 * Call setting general result cause
 */
typedef enum
{
    SRV_CALLSET_RESULT_OK = 0, /* success. result is OK */
    SRV_CALLSET_RESULT_BUSY, /* fail. busy */
    SRV_CALLSET_RESULT_NOT_AVAILABLE, /* fail. service is unavailable */
    SRV_CALLSET_RESULT_NOT_AVAILABLE_INCALL, /* fail. service is unavailable during incall */
    SRV_CALLSET_RESULT_FULL, /* fail. record full, can't add more data */
    SRV_CALLSET_RESULT_TOO_LONG, /* fail. the input number is too long */
    SRV_CALLSET_RESULT_EMPTY, /* fail. the input number is empty */
    SRV_CALLSET_RESULT_INVALID_FORMAT, /* fail. the input number is invalid format */
    SRV_CALLSET_RESULT_INVALID_INPUT, /* fail. the input parameter is invalid input */
    SRV_CALLSET_RESULT_DUPLICATE, /* fail. already in the list */
    SRV_CALLSET_RESULT_NOT_FOUND, /* fail. not found in the list */
    SRV_CALLSET_RESULT_UNKNOWN_ERROR, /* fail. it's general error */
    SRV_CALLSET_RESULT_END_OF_ENUM  /* Max result cause */
} srv_callset_result_enum;


#ifdef __CTM_SUPPORT__
/* 
 * CTM setting
 */
typedef enum
{
    SRV_CALLSET_CTM_SETTING_BAUDOT, /* baudot mode */
    SRV_CALLSET_CTM_SETTING_HCO, /* HCO mode */
    SRV_CALLSET_CTM_SETTING_VCO, /* VCO mode */
    SRV_CALLSET_CTM_SETTING_MANUAL_DIRECT, /* manual mode */
    SRV_CALLSET_CTM_SETTING_AUTO_DIRECT, /* auto mode */
    SRV_CALLSET_CTM_SETTING_UNKNOWN /* unknown */
} srv_callset_ctm_setting_enum;  
#endif /* __CTM_SUPPORT__ */


/* 
 * Redial mode
 */
typedef enum
{
    SRV_CALLSET_REDIAL_OFF, /* no redial after call release */
    SRV_CALLSET_REDIAL_AUTO, /* redial automatically according to the call release cause */
    SRV_CALLSET_REDIAL_CONFIRM, /* only redial after the user confirmation */
    SRV_CALLSET_REDIAL_UNKNOWN /* unknown */
} srv_callset_redial_mode_enum; 


/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_VIDEO_TELEPHONY__
/* 
 * VT answer mode
 */
typedef enum
{
    SRV_CALLSET_VT_ANSWER_MODE_PROMPT,
    SRV_CALLSET_VT_ANSWER_MODE_START_CAMERA,
    SRV_CALLSET_VT_ANSWER_MODE_STOP_CAMERA,
    SRV_CALLSET_VT_ANSWER_MODE_END_OF_ENUM
} srv_callset_vt_answer_mode_enum;


/* 
 * VT dial mode
 */
typedef enum
{
    SRV_CALLSET_VT_DIAL_MODE_START_CAMERA,
    SRV_CALLSET_VT_DIAL_MODE_STOP_CAMERA,
    SRV_CALLSET_VT_DIAL_MODE_END_OF_ENUM
} srv_callset_vt_dial_mode_enum;


/* 
 * VT camera mode
 */
typedef enum
{
    SRV_CALLSET_VT_CAMERA_OFF,
    SRV_CALLSET_VT_CAMERA_FRONT,
    SRV_CALLSET_VT_CAMERA_BACK,
    SRV_CALLSET_VT_CAMERA_END_OF_ENUM
} srv_callset_vt_camera_mode_enum;

/*
 * VT EV
 */
typedef enum
{
    SRV_CALLSET_VT_EV_0 = 0,
    SRV_CALLSET_VT_EV_P1 = 0x01,
    SRV_CALLSET_VT_EV_P2,
    SRV_CALLSET_VT_EV_P3,
    SRV_CALLSET_VT_EV_P4,
    SRV_CALLSET_VT_EV_N1 = 0x11,
    SRV_CALLSET_VT_EV_N2,
    SRV_CALLSET_VT_EV_N3,
    SRV_CALLSET_VT_EV_N4,
    SRV_CALLSET_VT_EV_INVALID = 0xff
} srv_callset_vt_ev_enum;
#endif /* __MMI_VIDEO_TELEPHONY__ */
/* DOM-NOT_FOR_SDK-END */


#ifdef __MMI_UCM_REJECT_BY_SMS__
/* 
 * Reject by sms setting enum
 */
typedef enum
{
    SRV_CALLSET_REJ_BY_SMS_DEFAULT, /* end call before send sms */
    SRV_CALLSET_REJ_BY_SMS_END_CALL_AFTER_SEND, /* end call after send sms */
    SRV_CALLSET_REJ_BY_SMS_UNKNOWN /* unknown */
} srv_callset_rej_by_sms_setting_enum;
#endif /* __MMI_UCM_REJECT_BY_SMS__ */


/****************************************************************************
* structure                                                            
*****************************************************************************/
#ifdef __MMI_CALLSET_CUG__
/* 
 * Closed user group set item structure
 */
typedef struct
{
    U8 cug_id; /* closed user group id */
    WCHAR name[SRV_CALLSET_CUG_MAX_NAME_LENGTH + 1]; /* name to describe a closed user group, in ucs2 */
} srv_callset_cug_set_item_struct;


/* 
 * Closed user group get item structure
 */
typedef struct
{
    WCHAR name[SRV_CALLSET_CUG_MAX_NAME_LENGTH + 1]; /* name to describe a closed user group, in ucs2 */
    srv_callset_cug_status_enum status; /* status */
} srv_callset_cug_get_item_struct;


/* 
 * CUG delete structure
 */
typedef struct
{
    mmi_sim_enum sim; /* target sim */
    U8 index; /* CUG index */
} srv_callset_cug_delete_struct;


/* 
 * CUG activate structure
 */
typedef struct
{
    mmi_sim_enum sim; /* target sim */
    U8 cug_id; /* CUG ID */
} srv_callset_cug_activate_struct;


/* 
 * CUG deactivate structure
 */
typedef struct
{
    mmi_sim_enum sim; /* target sim */
    U8 cug_id; /* CUG ID */
} srv_callset_cug_deactivate_struct;
#endif /* __MMI_CALLSET_CUG__ */


#ifdef __MMI_CM_BLACK_LIST__
/* 
 * Black list parameter structure
 *     There may be extended elements in the future
 *     Users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 */
typedef struct
{
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_call_type_enum call_type; 
    /* blacklist for the specific call type
     * default value is SRV_CALLSET_ALL_CALL when adv_param is not used
     */
#endif /* __MMI_CM_BLACK_LIST_EXT__ */
    U32 reserved; /* reserved */
} srv_callset_blacklist_adv_param_struct;


/* 
 * Number item structure for blacklist
 */
typedef struct 
{
    U8 index; /* index in the number list. INPUT for set_item apis. INPUT/OUTPUT for get_item apis */
    WCHAR number[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* number in ucs2 */
    srv_callset_blacklist_adv_param_struct *adv_param; 
    /* advanced parameter    
     *     Pointer for advanced parameter structure
     *        can be NULL for default behavior             
     *     There may be extended elements in the future
     *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
     *     to make sure all the parameters are initiated properly
     */
} srv_callset_bl_item_struct;
#endif /* __MMI_CM_BLACK_LIST__ */


#ifdef __IP_NUMBER__
/* 
 * IP number item structure
 */
typedef struct 
{
    U8 index; /* index in the number list */
    WCHAR number[SRV_CALLSET_MAX_IP_NUMBER_LEN + 1]; /* number in ucs2 */
    srv_callset_ip_number_status_enum status; /* status */
} srv_callset_ip_number_item_struct;


/* 
 * IP number structure
 */
typedef struct 
{
    WCHAR number[SRV_CALLSET_MAX_IP_NUMBER_LEN + 1]; /* number in ucs2 */
} srv_callset_ip_number_struct;
#endif /* __IP_NUMBER__ */


#ifdef __MMI_CM_WHITE_LIST__
/* 
 * White list parameter structure
 *     There may be extended elements in the future
 *     Users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 */
typedef struct
{
    /* for extension */
#ifdef __MMI_CM_WHITE_LIST_EXT__
    srv_callset_call_type_enum call_type; 
    /* blacklist for the specific call type
     * default value is SRV_CALLSET_ALL_CALL when adv_param is not used
     */
#endif /* __MMI_CM_WHITE_LIST_EXT__ */
    U32 reserved; /* reserved */
} srv_callset_whitelist_adv_param_struct;


/* 
 * Number item structure for whitelist
 */
typedef struct 
{
    U8 index; /* index in the number list. INPUT for set_item apis. INPUT/OUTPUT for get_item apis */
    WCHAR number[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* number in ucs2 */
    srv_callset_whitelist_adv_param_struct *adv_param; 
    /* advanced parameter    
     *     Pointer for advanced parameter structure
     *        can be NULL if don't default behavior             
     *     There may be extended elements in the future
     *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
     *     to make sure all the parameters are initiated properly
     */
} srv_callset_wl_item_struct;


/* 
 * Whitelist structure
 */
typedef struct 
{
    U8 count; /* number of the items in the list */
    srv_callset_wl_item_struct list[SRV_CALLSET_WHITELIST_MAX_ITEM + 1]; /* list */
} srv_callset_whitelist_struct;
#endif /* __MMI_CM_WHITE_LIST__ */


#ifdef __MMI_CALLSET_CALLER_ID__
/* 
 * Caller ID set mode structure
 */
typedef struct
{
    mmi_sim_enum sim; /* target sim */
    srv_callset_caller_id_mode_enum mode; /* caller ID mode */
} srv_callset_cid_set_mode_struct;
#endif /* __MMI_CALLSET_CALLER_ID__ */


/* 
 * Caller ID set mode structure
 */
typedef struct
{
    mmi_sim_enum sim; /* target sim */
    srv_callset_line_id_enum line_id; /* line ID */
} srv_callset_line_switch_struct;


/* 
 * Call time reminder structure
 */
typedef struct
{
    srv_callset_ctr_mode_enum mode; /* mode */
    U16 time; /* time, for single mode: SRV_CALLSET_CTR_MIN_SINGLE_TIME ~ SRV_CALLSET_CTR_MAX_SINGLE_TIME; for periodic mode: SRV_CALLSET_CTR_MIN_PERIODIC_TIME ~ SRV_CALLSET_CTR_MAX_PERIODIC_TIME */
} srv_callset_ctr_struct;


/* 
 * call setting general result response strucures
 */
typedef struct
{
    mmi_sim_enum sim; /* target sim */
    srv_callset_result_enum result;  /* result cause */
} srv_callset_result_struct;


/* 
 * SS response event structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER /* event parameter header */
    /* DOM-NOT_FOR_SDK-END */
    void *data; /* data */
} srv_callset_rsp_evt_struct;


/* 
 * line switched indication event structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER /* event parameter header */
    /* DOM-NOT_FOR_SDK-END */
    mmi_sim_enum sim;
    srv_callset_line_id_enum active_line;
} srv_callset_line_switched_evt_struct;


/* 
 * CFU status indication event structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER /* event parameter header */
    /* DOM-NOT_FOR_SDK-END */
    mmi_sim_enum sim;
    srv_callset_cfu_status_enum status;
} srv_callset_cfu_status_evt_struct;


#ifdef __CTM_SUPPORT__
/* 
 * CTM setting structure
 */
typedef struct
{
    MMI_BOOL mode; /* MMI_TRUE: on */
    srv_callset_ctm_setting_enum setting; /* CTM setting */
} srv_callset_ctm_setting_struct;


/* 
 * CTM indication event structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER /* event parameter header */
    /* DOM-NOT_FOR_SDK-END */
} srv_callset_ctm_setting_changed_evt_struct;
#endif /* __CTM_SUPPORT__ */

#ifdef MOTION_SENSOR_SUPPORT
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER /* event parameter header */
    /* DOM-NOT_FOR_SDK-END */
} srv_callset_flip_to_mute_call_changed_evt_struct;

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER /* event parameter header */
    /* DOM-NOT_FOR_SDK-END */
} srv_callset_tap_tap_to_record_in_call_changed_evt_struct;
#endif

/****************************************************************************
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_callset_get_result_string_id
 * DESCRIPTION
 *  to get the corresponding string id for a specific result cause
 * PARAMETERS
 *  cause : [IN] the result cause
 * RETURNS
 *  U16 : the corresponding string id for the result cause
 *****************************************************************************/ 
extern U16 srv_callset_get_result_string_id(srv_callset_result_enum cause);


#ifdef __MMI_CALLSET_CALLER_ID__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_caller_id_set_mode
 * DESCRIPTION
 *  to set caller id mode.
 * PARAMETERS
 *  info : [IN] parameters
 *  callback : [IN] scallback to notify the result. srv_callset_rsp_evt_struct(srv_callset_result_struct)
 *  user_data : [IN] user data
 * RETURNS
 *  srv_callset_result_enum, not OK if the request is rejected directly by callset service
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_caller_id_set_mode(srv_callset_cid_set_mode_struct *info, mmi_proc_func callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_caller_id_get_mode
 * DESCRIPTION
 *  to get caller id mode.
 * PARAMETERS
 *  sim : [IN] which sim
 * RETURNS
 *  srv_callset_caller_id_mode_enum : caller id mode
 *****************************************************************************/
extern srv_callset_caller_id_mode_enum srv_callset_caller_id_get_mode(mmi_sim_enum sim);
#endif /* __MMI_CALLSET_CALLER_ID__ */

/*****************************************************************************
 * FUNCTION
 *  srv_callset_line_switch_set_id
 * DESCRIPTION
 *  to set line switch mode.
 * PARAMETERS
 *  info : [IN] parameters
 *  callback : [IN] callback to notify the result. srv_callset_rsp_evt_struct(srv_callset_result_struct)
 *  user_data : [IN] user data
 * RETURNS
 *  srv_callset_result_enum, not OK if the request is rejected directly by callset service
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_line_switch_set_id(srv_callset_line_switch_struct *info, mmi_proc_func callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_line_switch_get_id
 * DESCRIPTION
 *  to get line switch mode.
 * PARAMETERS
 *  sim : [IN] which sim
 * RETURNS
 *  srv_callset_line_id_enum : line id
 *****************************************************************************/
extern srv_callset_line_id_enum srv_callset_line_switch_get_id(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cfu_get_status
 * DESCRIPTION
 *  to get cfu status.
 * PARAMETERS
 *  sim : [IN] which sim
 * RETURNS
 *  srv_callset_cfu_status_enum : cfu status
 *****************************************************************************/
extern srv_callset_cfu_status_enum srv_callset_cfu_get_status(mmi_sim_enum sim);


#ifdef __MMI_CALLSET_CUG__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_modify
 * DESCRIPTION
 *  to modify the CUG name of a specific CUG index
 * PARAMETERS
 *  sim : [IN] which sim
 *  item : [IN] new CUG name and cug_id. 
 *              name is allowed to be empty
 *              PLEASE NOTE THAT cug is still allowed to be activated when name is empty
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_cug_set_item(mmi_sim_enum sim, srv_callset_cug_set_item_struct *item);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_get_item
 * DESCRIPTION
 *  to get the cug item by index
 * PARAMETERS
 *  sim : [IN] which sim
 *  cug_id : [IN] CUG ID
 *  item : [OUT] CUG item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_cug_get_item(mmi_sim_enum sim, U8 cug_id, srv_callset_cug_get_item_struct *item);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_get_actviated_item
 * DESCRIPTION
 *  to get the activated CUG ID
 * PARAMETERS
 *  sim : [IN] which sim 
 * RETURNS
 *  U8 : activated index (0~9), 0xff if no activated item
 *****************************************************************************/
extern U8 srv_callset_cug_get_actviated_id(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_activate
 * DESCRIPTION
 *  to activate the CUG index. the original activated CUG will be deactivated as well.
 * PARAMETERS
 *  info : [IN] parameters
 *  callback : [IN] callback to notify the result. srv_callset_rsp_evt_struct(srv_callset_result_struct)
 *  user_data : [IN] user data
 * RETURNS
 *  srv_callset_result_enum, not OK if the request is rejected directly by callset service
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_cug_activate(srv_callset_cug_activate_struct *info, mmi_proc_func callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_cug_deactivate
 * DESCRIPTION
 *  to deactivate the CUG index
 * PARAMETERS
 *  info : [IN] parameters
 *  callback : [IN] callback to notify the result. srv_callset_rsp_evt_struct(srv_callset_result_struct)
 *  user_data : [IN] user data
 * RETURNS
 *  srv_callset_result_enum, not OK if the request is rejected directly by callset service
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_cug_deactivate(srv_callset_cug_deactivate_struct *info, mmi_proc_func callback, void *user_data);
#endif /* __MMI_CALLSET_CUG__ */


#ifdef __MMI_CM_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_init_advanced_param
 * DESCRIPTION
 *  to initialize the blacklist advanced parameters for the next operation
 * PARAMETERS
 *  adv_param : [OUT] pointer for advanced parameter structure
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_blacklist_init_advanced_param(srv_callset_blacklist_adv_param_struct *adv_param);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_set_mode
 * DESCRIPTION
 *  to set the blacklist mode to the input value (turn on or turn off)
 * PARAMETERS
 *  mode : [IN] mode, bitwise
 *  adv_param : [IN] pointer for advanced parameter structure
 *                   can be NULL for default behavior
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_blacklist_set_mode(srv_callset_blacklist_mode_enum mode, srv_callset_blacklist_adv_param_struct *adv_param);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_get_mode
 * DESCRIPTION
 *  to get blacklist mode
 * PARAMETERS
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior       
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_blacklist_mode_enum, bitwise
 *****************************************************************************/ 
extern srv_callset_blacklist_mode_enum srv_callset_blacklist_get_mode(srv_callset_blacklist_adv_param_struct *adv_param);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_switch_mode
 * DESCRIPTION
 *  to turn on or turn off the specific blacklist mode
 * PARAMETERS
 *  mode :   [IN]    the specific mode
 *  switch_on : [IN]    MMI_TRUE for switch on; MMI_FALSE for switch off
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_result_enum
 *      result is the first invalid value when call type is bitwised
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_blacklist_switch_mode(srv_callset_blacklist_mode_enum mode, MMI_BOOL switch_on, srv_callset_blacklist_adv_param_struct *adv_param);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_set_number
 * DESCRIPTION
 *  to set a blacklist number
 *  call type is allowed to be bitwised (set number to each call type)
 * PARAMETERS
 *  item : [IN] number item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_blacklist_set_number(srv_callset_bl_item_struct *item);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_get_item
 * DESCRIPTION
 *  to get the blacklist item by index
 * PARAMETERS
 *  item : [IN][OUT] number item
 *  call type is NOT allowed to be bitwised
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_blacklist_get_item(srv_callset_bl_item_struct *item);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_add_number
 * DESCRIPTION
 *  to add a number into black list
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN
 *  number : [IN] the point for the blocked number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior       
 *                   call type is allowed to be bitwised (add number to each call type),
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 *  index : [OUT] assigned index, can be NULL (don't care about the index)
 *                   index is invalid when call type is bitwised
 * RETURNS
 *  srv_callset_result_enum
 *      result is the first invalid value when call type is bitwised
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_blacklist_add_number(U8 length, WCHAR *number, srv_callset_blacklist_adv_param_struct *adv_param, PU8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_delete_number
 * DESCRIPTION
 *  to delete a number from black list
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN
 *  number : [IN] the point for the blocked number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior       
 *                   call type is allowed to be bitwised (add number to each call type),
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 *  index : [OUT] index of delete target, can be NULL (don't care about the index)
 *                   index is invalid when call type is bitwised
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_blacklist_delete_number(U8 length, WCHAR *number, srv_callset_blacklist_adv_param_struct *adv_param, PU8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_blacklist_is_blocked_number
 * DESCRIPTION
 *  to check if the number is a blocked number
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN; allowed to be 0 (Unknown number)
 *  number : [IN] the point for the blocked number, in UCS2; allowed to be NULL (Unknown number)
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior   
 *                   call type is allowed to be bitwised (query for each call type)
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_blacklist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  MMI_BOOL : TRUE if yes, FALSE if no
 *****************************************************************************/
extern MMI_BOOL srv_callset_blacklist_is_blocked_number(U8 length, WCHAR *number, srv_callset_blacklist_adv_param_struct *adv_param);
#endif /* __MMI_CM_BLACK_LIST__ */


#ifdef __MMI_CM_WHITE_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_init_advanced_param
 * DESCRIPTION
 *  to initialize the whitelist advanced parameters for the next operation
 * PARAMETERS
 *  adv_param : [OUT] pointer for advanced parameter structure
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_whitelist_init_advanced_param(srv_callset_whitelist_adv_param_struct *adv_param);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_set_mode
 * DESCRIPTION
 *  to set whitelist mode
 * PARAMETERS
 *  mode : [IN] mode, bitwise
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior    
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_whitelist_set_mode(srv_callset_whitelist_mode_enum mode, srv_callset_whitelist_adv_param_struct *adv_param);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_get_mode
 * DESCRIPTION
 *  to get whitelist mode
 * PARAMETERS
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior  
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_whitelist_mode_enum, bitwise
 *****************************************************************************/ 
extern srv_callset_whitelist_mode_enum srv_callset_whitelist_get_mode(srv_callset_whitelist_adv_param_struct *adv_param);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_switch_mode
 * DESCRIPTION
 *  to turn on or turn off the specific whitelist mode
 * PARAMETERS
 *  mode    [IN]    the specific mode
 *  switch_on [IN]    MMI_TRUE for switch on; MMI_FALSE for switch off
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior   
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_whitelist_switch_mode(srv_callset_whitelist_mode_enum mode, MMI_BOOL switch_on, srv_callset_whitelist_adv_param_struct *adv_param);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_set_number
 * DESCRIPTION
 *  to set a whitelist number
 * PARAMETERS
 *  item : [IN] number item
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_whitelist_set_number(srv_callset_wl_item_struct *item);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_get_item
 * DESCRIPTION
 *  to get the whitelist item by index
 *  call type is allowed to be bitwised (set number to each call type)
 * PARAMETERS
 *  item : [IN][OUT] whitelist item
 *  call type is NOT allowed to be bitwised
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_whitelist_get_item(srv_callset_wl_item_struct *item);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_add_number
 * DESCRIPTION
 *  to add a number into white list
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN
 *  number : [IN] the point for the blocked number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior       
 *                   call type is allowed to be bitwised (add number to each call type),
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 *  index : [OUT] assigned index, can be NULL (don't care about the index)
 *                   index is invalid when call type is bitwised
 * RETURNS
 *  srv_callset_result_enum
 *      result is the first invalid value when call type is bitwised
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_whitelist_add_number(U8 length, WCHAR *number, srv_callset_whitelist_adv_param_struct *adv_param, PU8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_delete_number
 * DESCRIPTION
 *  to delete a number from white list
 * PARAMETERS
 *  length : [IN] number length, shall <= SRV_UCM_MAX_NUM_URI_LEN
 *  number : [IN] the point for the auto answer number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior       
 *                   call type is allowed to be bitwised (add number to each call type),
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 *  index : [OUT] index of delete target, can be NULL (don't care about the index)
 *                   index is invalid when call type is bitwised
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_whitelist_delete_number(U8 length, WCHAR *number, srv_callset_whitelist_adv_param_struct *adv_param, PU8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_whitelist_is_auto_answer_number
 * DESCRIPTION
 *  to check if the number is an auto answer number
 * PARAMETERS
 *  length : [IN] number length, shall <= 41
 *  number : [IN] the point for the blocked number, in UCS2
 *  adv_param : [IN] pointer for advanced parameter structure, can be NULL
 *                   can be NULL for default behavior 
 *     There may be extended elements in the future
 *     If adv_param is used, users shall call srv_callset_whitelist_init_advanced_param() first 
 *     to make sure all the parameters are initiated properly
 * RETURNS
 *  MMI_BOOL : TRUE if yes, FALSE if no
 *****************************************************************************/ 
extern MMI_BOOL srv_callset_whitelist_is_auto_answer_number(U8 length, WCHAR *number, srv_callset_whitelist_adv_param_struct *adv_param);
#endif /* __MMI_CM_WHITE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_callset_redial_set_mode
 * DESCRIPTION
 *  to set redial mode
 * PARAMETERS
 *  srv_callset_redial_mode : [IN] redial mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_callset_redial_set_mode(srv_callset_redial_mode_enum mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_redial_get_mode
 * DESCRIPTION
 *  to get redial mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL: TRUE if on, FALSE if off
 *****************************************************************************/
extern srv_callset_redial_mode_enum srv_callset_redial_get_mode(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_redial_set_mode
 * DESCRIPTION
 *  to set auto redial mode, off/on
 *  redial automatically according to the call release cause
 *  equivalent to srv_callset_redial_set_mode(SRV_CALLSET_REDIAL_OFF / SRV_CALLSET_REDIAL_AUTO)
 *  only for backward compatible
 * PARAMETERS
 *  MMI_BOOL : [IN] MMI_TRUE for on, MMI_FALSE for off
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_callset_auto_redial_set_mode(MMI_BOOL mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_redial_get_mode
 * DESCRIPTION
 *  to get auto redial mode, off/on
 *  redial automatically according to the call release cause
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL: TRUE if on, FALSE if off
 *  equivalent to the return value SRV_CALLSET_REDIAL_OFF / SRV_CALLSET_REDIAL_AUTO in srv_callset_redial_get_mode()
 *  only for backward compatible
 *****************************************************************************/
extern MMI_BOOL srv_callset_auto_redial_get_mode(void);


#ifdef __IP_NUMBER__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_activate
 * DESCRIPTION
 *  to actviate an specific ip number with ip_index
 * PARAMETERS
 *  sim: [IN] apply to which SIM.
 *  index: [IN] the index of the ip number, 1~SRV_CALLSET_MAX_IP_NUMBER
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_ip_number_activate(mmi_sim_enum sim, U8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_deactivate
 * DESCRIPTION
 *  to deactviate an specific ip number with ip_index, will deactivate the original activated number first
 * PARAMETERS
 *  sim: [IN] apply to which SIM.
 *  index: [IN] the index of the ip number, 1~SRV_CALLSET_MAX_IP_NUMBER
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_ip_number_deactivate(mmi_sim_enum sim, U8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_set_num
 * DESCRIPTION
 *  to set an ip number.
 * PARAMETERS
 *  index : [IN] index of the ip number, 0~(SRV_CALLSET_MAX_IP_NUMBER-1)
 *  length : [IN] length of the ip number, must <= SRV_CALLSET_MAX_IP_NUMBER_LEN; can be 0
 *  ip_num : [IN] the point for the ip number string; shall not be NULL; can be empty string
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_ip_number_set_number(U8 index, U8 length, WCHAR *ip_num);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_get_item
 * DESCRIPTION
 *  to get the ip number item
 * PARAMETERS
 *  index : [IN] index, 0~(SRV_CALLSET_MAX_IP_NUMBER-1)
 *  item : [OUT] ip number item, doesn't need to be initialized / reset
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_ip_number_get_item(U8 index, srv_callset_ip_number_item_struct *item);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ip_number_get_activated_number
 * DESCRIPTION
 *  to get current activated ip number.
 * PARAMETERS
 *  sim : [IN] apply to which SIM.
 *  ip_num : [OUT] the point for the returned ip number, in UCS2
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_ip_number_get_activated_number(mmi_sim_enum sim, srv_callset_ip_number_struct *ip_num);
#endif /* __IP_NUMBER__ */


/*****************************************************************************
 * FUNCTION
 *  srv_callset_call_time_display_set_mode
 * DESCRIPTION
 *  to set call time display status, off/on
 * PARAMETERS
 *  mode : [IN] call time display mode, MMI_TRUE for on
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_callset_call_time_display_set_mode(MMI_BOOL mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_call_time_display_get_mode
 * DESCRIPTION
 *  to get call time display status, off/on
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if the mode is on, MMI_FALSE if the mode is off or not available
 *****************************************************************************/
extern MMI_BOOL srv_callset_call_time_display_get_mode(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctr_set_mode
 * DESCRIPTION
 *  to set call time reminder mode and time
 * PARAMETERS
 *  info : [IN] parameters
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_ctr_set_mode(srv_callset_ctr_struct *info);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctr_get_time
 * DESCRIPTION
 *  to get call time reminder time in sec.
 * PARAMETERS
 *  info : [OUT] ctr mode and time
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_ctr_get_mode(srv_callset_ctr_struct *info);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_answer_mode_set_mode
 * DESCRIPTION
 *  to set answer mode
 * PARAMETERS
 *  mode : [IN] answer mode (bitwised)
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_answer_mode_set_mode(srv_callset_answer_mode_enum mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_answer_mode_get_mode
 * DESCRIPTION
 *  to get answer mode (bitwised)
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_answer_mode_enum (bitwised)
 *  Please note that auto mode is on ONLY means the setting is turned on
 *  Auto answer is allowed when both the following criteria are met:
 *      1. Auto mode is turned on
 *      2. The earphone is plugged in OR test SIM is used
 *  To check auto answer is allowed, please use srv_callset_answer_mode_get_status instead
 *****************************************************************************/
extern srv_callset_answer_mode_enum srv_callset_answer_mode_get_mode(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_answer_mode_get_status
 * DESCRIPTION
 *  to check the answer mode status
 *      - Answer when clamshell on is allowed when clamshell setting is turnned on
 *      - Answer by any key is allowed when anykey setting is turnned on
 *      - Auto answer is allowed ONLY when both the following criteria are met:
 *          1. Auto answer setting is turned on
 *          2. The earphone is plugged in OR test SIM is used
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_answer_mode_enum (bitwised)
 *****************************************************************************/
extern srv_callset_answer_mode_enum srv_callset_answer_mode_get_status(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_answer_mode_switch_mode
 * DESCRIPTION
 *  to turn on or turn off the specific answer mode
 * PARAMETERS
 *  mode    [IN]    the specific mode (bitwised)
 *  switch_on [IN]    MMI_TRUE for switch on; MMI_FALSE for switch off
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_answer_mode_switch_mode(srv_callset_answer_mode_enum mode, MMI_BOOL switch_on);


#ifdef __MMI_CH_QUICK_END__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_quick_end_set_mode
 * DESCRIPTION
 *  to set auto quick end mode and time
 * PARAMETERS
 *  mode : [IN] auto quick end mode, MMI_TRUE if mode is on
 *  time : [IN] auto quick end time, SRV_CALLSET_AUTO_QUICK_END_MIN ~ SRV_CALLSET_AUTO_QUICK_END_MAX
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_auto_quick_end_set_mode(MMI_BOOL mode, U16 time);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_quick_end_get_mode
 * DESCRIPTION
 *  to get auto quick end mode and time
 * PARAMETERS
 *  mode : [OUT] auto quick end mode, MMI_TRUE if mode is on
 *  time : [OUT] auto quick end time, SRV_CALLSET_AUTO_QUICK_END_MIN ~ SRV_CALLSET_AUTO_QUICK_END_MAX
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_auto_quick_end_get_mode(MMI_BOOL *mode, U16 *time);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_auto_quick_end_get_time
 * DESCRIPTION
 *  to get auto quick end time in sec.
 * PARAMETERS
 *  void
 * RETURNS
 *  auto quick end time; 0 if the mode is off; 
 *****************************************************************************/
extern U16 srv_callset_auto_quick_end_get_time(void);
#endif /* __MMI_CH_QUICK_END__ */


#ifdef __MMI_UCM_REJECT_BY_SMS__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_reject_by_sms_set_mode
 * DESCRIPTION
 *  to set the reject by sms mode
 * PARAMETERS
 *  mode : [IN] MMI_TRUE if on, MMI_FALSE if off
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_callset_reject_by_sms_set_mode(MMI_BOOL mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_reject_by_sms_get_mode
 * DESCRIPTION
 *  to set the reject by sms mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE if the mode is on; MMI_FALSE if the mode is off or not available
 *****************************************************************************/ 
extern MMI_BOOL srv_callset_reject_by_sms_get_mode(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_reject_by_sms_get_setting
 * DESCRIPTION
 *  to set the reject by sms setting
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_rej_by_sms_setting_enum
 *****************************************************************************/
extern srv_callset_rej_by_sms_setting_enum srv_callset_reject_by_sms_get_setting(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_reject_by_sms_set_setting
 * DESCRIPTION
 *  to set the reject by sms setting
 * PARAMETERS
 *  setting : [IN] srv_callset_rej_by_sms_setting_enum
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/ 
extern srv_callset_result_enum srv_callset_reject_by_sms_set_setting(srv_callset_rej_by_sms_setting_enum setting);
#endif /* __MMI_UCM_REJECT_BY_SMS__ */


#ifdef __MMI_CONNECT_NOTICE__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_connect_notice_set_mode
 * DESCRIPTION
 *  to set the connect notice mode
 * PARAMETERS
 *  mode : [IN] MMI_TRUE if on, MMI_FALSE if off
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_callset_connect_notice_set_mode(MMI_BOOL mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_connect_notice_get_mode
 * DESCRIPTION
 *  to set the connect notice mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE if the mode is on; MMI_FALSE if the mode is off or not available
 *****************************************************************************/ 
extern MMI_BOOL srv_callset_connect_notice_get_mode(void);
#endif /* __MMI_CONNECT_NOTICE__ */


#ifdef __CTM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_get_mode
 * DESCRIPTION
 *  get CTM mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if ctm is on
 *****************************************************************************/
extern MMI_BOOL srv_callset_ctm_get_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_get_setting
 * DESCRIPTION
 *  get CTM setting
 * PARAMETERS
 *  void    
 * RETURNS
 *  ctm setting
 *****************************************************************************/
extern srv_callset_ctm_setting_enum srv_callset_ctm_get_setting(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_permit_set_mode
 * DESCRIPTION
 *  check if it is allowed to switch CTM setting
 * PARAMETERS
 *  void
 * RETURNS
 *  SRV_CALLSET_RESULT_OK if switching to any CTM setting is allowed
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_ctm_permit_switch_setting(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_permit_set_mode
 * DESCRIPTION
 *  check if change CTM mode or setting is allowed
 * PARAMETERS
 *  info    [IN]    srv_callset_ctm_setting_struct    
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_ctm_permit_set_mode(srv_callset_ctm_setting_struct *info);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_set_mode
 * DESCRIPTION
 *  set CTM setting
 * PARAMETERS
 *  info    [IN]    srv_callset_ctm_setting_struct    
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_ctm_set_mode(srv_callset_ctm_setting_struct *info);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_ctm_is_tty_on
 * DESCRIPTION
 *  check if ctm is turned on using tty mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if ctm is turned on using tty mode
 *****************************************************************************/
extern MMI_BOOL srv_callset_ctm_is_tty_on(void);
#endif /* __CTM_SUPPORT__ */


/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_dial_mode
 * DESCRIPTION
 *  get vt dial mode
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_vt_dial_mode_enum
 *****************************************************************************/
extern srv_callset_vt_dial_mode_enum srv_callset_vt_get_dial_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_dial_mode
 * DESCRIPTION
 *  set vt dial mode
 * PARAMETERS
 *  mode    [IN]    srv_callset_result_enum
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_set_dial_mode(srv_callset_vt_dial_mode_enum mode);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_answer_mode
 * DESCRIPTION
 *  get vt answer mode
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_vt_answer_mode_enum
 *****************************************************************************/
extern srv_callset_vt_answer_mode_enum srv_callset_vt_get_answer_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_answer_mode
 * DESCRIPTION
 *  set vt answer mode
 * PARAMETERS
 *  mode    [IN]    srv_callset_result_enum
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_set_answer_mode(srv_callset_vt_answer_mode_enum mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_mic_mode
 * DESCRIPTION
 *  get vt mic mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means mic is on
 *****************************************************************************/
extern MMI_BOOL srv_callset_vt_get_mic_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_mic_mode
 * DESCRIPTION
 *  set vt mic mode
 * PARAMETERS
 *  mode    [IN]    MMI_BOOL, MMI_TRUE means mic is on
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_set_mic_mode(MMI_BOOL mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_speaker_mode
 * DESCRIPTION
 *  get vt speaker mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means speaker is on
 *****************************************************************************/
extern MMI_BOOL srv_callset_vt_get_speaker_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_speaker_mode
 * DESCRIPTION
 *  set vt speaker mode
 * PARAMETERS
 *  mode    [IN]    MMI_BOOL, MMI_TRUE means speaker is on
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_set_speaker_mode(MMI_BOOL mode);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_night_mode
 * DESCRIPTION
 *  get vt night mode
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 * RETURNS
 *  MMI_TRUE means night mode is on
 *****************************************************************************/
extern MMI_BOOL srv_callset_vt_get_night_mode(srv_callset_vt_camera_mode_enum cam_mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_night_mode
 * DESCRIPTION
 *  set vt night mode
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 *  mode    [IN]    MMI_BOOL, MMI_TRUE means night mode is on
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_set_night_mode(srv_callset_vt_camera_mode_enum cam_mode, MMI_BOOL mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_ev
 * DESCRIPTION
 *  get vt ev
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 * RETURNS
 *  EV value for the specific camera mode
 *****************************************************************************/
extern srv_callset_vt_ev_enum srv_callset_vt_get_ev(srv_callset_vt_camera_mode_enum cam_mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_ev
 * DESCRIPTION
 *  set vt ev
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 *  ev    [IN]    ev value
 * RETURNS
 *  result
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_set_ev(srv_callset_vt_camera_mode_enum cam_mode, srv_callset_vt_ev_enum ev);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_zoom
 * DESCRIPTION
 *  get vt zoom
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 * RETURNS
 *  Zoom value for the specific camera mode, 0xff if invalid
 *****************************************************************************/
extern U8 srv_callset_vt_get_zoom(srv_callset_vt_camera_mode_enum cam_mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_zoom
 * DESCRIPTION
 *  set vt zoom
 * PARAMETERS
 *  cam_mode    [IN]    camera mode
 *  zoom    [IN]    zoom value
 * RETURNS
 *  result
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_set_zoom(srv_callset_vt_camera_mode_enum cam_mode, U8 zoom);



/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_camera_mode
 * DESCRIPTION
 *  get vt camera mode
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_callset_vt_camera_mode_enum
 *****************************************************************************/
extern srv_callset_vt_camera_mode_enum srv_callset_vt_get_camera_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_camera_mode
 * DESCRIPTION
 *  set vt camera mode
 * PARAMETERS
 *  mode    [IN]    srv_callset_result_enum
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_set_camera_mode(srv_callset_vt_camera_mode_enum mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_set_incall_image_path
 * DESCRIPTION
 *  set vt incall image path
 * PARAMETERS
 *  length  [IN]    path length in characters (NOT bytes and NOT including the null terminater)
 *  path    [IN]    file path
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_set_incall_image_path(U32 length, PU16 path);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_vt_get_incall_image_path
 * DESCRIPTION
 *  set vt incall image path
 * PARAMETERS
 *  length  [IN]    path length in characters (NOT bytes and NOT including the null terminater)
 *  path    [OUT]    file path buffer, shall be allocated by the caller
 * RETURNS
 *  srv_callset_result_enum
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_vt_get_incall_image_path(U32 length, PU16 path);
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_delay_dial_get_time
 * DESCRIPTION
 *  get delay dial time
 * PARAMETERS
 *  void
 * RETURNS
 *  delay dial time (dial after 1~255 seconds, 0 means OFF)
 *****************************************************************************/
extern U8 srv_callset_delay_dial_get_time(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_delay_dial_set_time
 * DESCRIPTION
 *  set delay dial time
 * PARAMETERS
 *  time [IN] delay dial time (dial after 1~255 seconds, 0 means OFF)
 * RETURNS
 *  result
 *****************************************************************************/
extern srv_callset_result_enum srv_callset_delay_dial_set_time(U8 time);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_fwp_get_offhook_reminder
 * DESCRIPTION
 *  Fixed Wireless telePhone feature: get offhook reminder setting
 * PARAMETERS
 *  timeout [OUT] off-hook timeout in seconds to start the reminder, could be NULL
 *  duration [OUT] off-hook reminder duration in seconds, could be NULL
 * RETURNS
 *  result
 *****************************************************************************/
srv_callset_result_enum srv_callset_fwp_get_offhook_reminder(U8 *timeout, U8 *duration);

/*****************************************************************************
 * FUNCTION
 *  srv_callset_fwp_set_offhook_reminder
 * DESCRIPTION
 *  Fixed Wireless telePhone feature: set offhook reminder setting
 * PARAMETERS
 *  timeout [IN] off-hook timeout in seconds to start the reminder
 *  duration [IN] off-hook reminder duration in seconds
 * RETURNS
 *  result
 *****************************************************************************/
srv_callset_result_enum srv_callset_fwp_set_offhook_reminder(U8 timeout, U8 duration);
#endif /* __OP01_FWPBW__ */
/* DOM-NOT_FOR_SDK-END */


#ifdef MOTION_SENSOR_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_callset_flip_to_mute_call_get_mode
 * DESCRIPTION
 *  to set the flip to mute call mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE if the mode is on; MMI_FALSE if the mode is off or not available
 *****************************************************************************/
MMI_BOOL srv_callset_flip_to_mute_call_get_mode(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_flip_to_mute_call_set_mode
 * DESCRIPTION
 *  to set the flip to mute call mode, if the new mode is not same as old emit a event
 * PARAMETERS
 *  mode : [IN] MMI_TRUE if on, MMI_FALSE if off
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_callset_flip_to_mute_call_set_mode(MMI_BOOL mode);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_tap_tap_to_record_in_call_get_mode
 * DESCRIPTION
 *  to set the tap-tap to record in-call mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE if the mode is on; MMI_FALSE if the mode is off or not available
 *****************************************************************************/
MMI_BOOL srv_callset_tap_tap_to_record_in_call_get_mode(void);


/*****************************************************************************
 * FUNCTION
 *  srv_callset_tap_tap_to_record_in_call_set_mode
 * DESCRIPTION
 *  to set the flip to mute call mode, if the new mode is not same as old emit a event
 * PARAMETERS
 *  mode : [IN] MMI_TRUE if on, MMI_FALSE if off
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_callset_tap_tap_to_record_in_call_set_mode(MMI_BOOL mode);
#endif

#endif /* SRV_CALLSET_GPROT_H */ 

