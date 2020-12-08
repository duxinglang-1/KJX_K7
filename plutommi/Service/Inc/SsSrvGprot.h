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
 *  SsSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS service global prototypes
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SRV_SS_GPROT_H
#define SRV_SS_GPROT_H

#include "mmi_rp_srv_ss_def.h" /* event id */

#include "UcmSrvGprot.h" /* SRV_UCM_MAX_NUM_URI_LEN */

#include "l4c_common_enum.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "l3_inc_enums.h"
#include "kal_non_specific_general_types.h"
#include "MMI_features.h"

/****************************************************************************
* Define
*****************************************************************************/

/* Maximum ss string length */
#define SRV_SS_MAX_LENGTH (MAX_DIGITS_USSD - 1)

/* Maximum call forwarding number length */
#define SRV_SS_MAX_FWD_ADDR_LEN          29

/* Maximum ss cause string length */
#define SRV_SS_MAX_CAUSE_LENGTH 80

/* Maximum password length */
#define SRV_SS_PASSWORD_MAX_LENTH 4

/* Maximum number of basic service */
#define SRV_SS_MAX_BS_LIST_NUM 13

/* Maximum CFNRY time, in second */
#define SRV_SS_MAX_CFNRY_TIME 30

/* Minimum CFNRY time, in second */
#define SRV_SS_MIN_CFNRY_TIME 5

/* SS service original information header */
#define SRV_SS_ORI_HEADER     \
    mmi_sim_enum sim; /* target sim */  \
    srv_ss_source_id_enum source; /* source module */

/* Protocol stack cause */
#define srv_ss_ps_cause_enum ps_cause_enum


/****************************************************************************
* Typedef                                                            
*****************************************************************************/

/* 
 * SS action
 */
typedef enum
{
    SRV_SS_ACT_IDLE = 0, /* no action */
    SRV_SS_ACT_CALL_FORWARD,    /* call forwarding. srv_ss_call_forward_req_struct, srv_ss_call_forward_rsp_struct */
    SRV_SS_ACT_CALL_BAR,    /* call barring. srv_ss_call_bar_req_struct, srv_ss_call_bar_rsp_struct */
    SRV_SS_ACT_CALL_WAIT,   /* call waiting. srv_ss_call_wait_req_struct, srv_ss_call_wait_rsp_struct */
    SRV_SS_ACT_CALL_IDENTIFICATION, /* calling/connected line dentification. request is not supported for now (use SRV_SS_ACT_SS_OPERATION instead), srv_ss_call_id_rsp_struct */
    SRV_SS_ACT_CNAP, /* calling name presentation. request is not supported for now (use SRV_SS_ACT_SS_OPERATION instead), srv_ss_cnap_rsp_struct */
    SRV_SS_ACT_CCBS, /* completion of calls to busy subscriber. request is not supported for now (use SRV_SS_ACT_SS_OPERATION instead), srv_ss_ccbs_rsp_struct */
    SRV_SS_ACT_EMLPP, /* eMLPP. request is not supported for now (use SRV_SS_ACT_SS_OPERATION instead), srv_ss_emlpp_rsp_struct */
    SRV_SS_ACT_USSD, /* USSD. use SRV_SS_ACT_SS_OPERATION for request, srv_ss_ussd_rsp_struct */
    SRV_SS_ACT_SS_OPERATION, /* send any ss strings. srv_ss_operation_req_struct, cast according to opcode in srv_ss_rsp_struct */
    SRV_SS_ACT_ABORT, /* abort ss session. srv_ss_abort_req_struct, NULL (always success) */
    SRV_SS_ACT_TOTAL /* max enum */
} srv_ss_act_enum;


#ifdef __BUILD_DOM__
/* 
 * Event id definition
 */
typedef enum
{
    EVT_ID_SRV_SS_INDICATION = SRV_SS_BASE + 1, /* post type, srv_ss_ind_evt_struct, must return MMI_RET_OK */
    EVT_ID_SRV_SS_ACT_RESPONSE, /* post type, srv_ss_rsp_evt_struct, must return MMI_RET_OK */
    EVT_ID_SRV_SS_ACT_NOTIFY, /* post type, srv_ss_act_notify_evt_struct, must return MMI_RET_OK */
    EVT_ID_SRV_SS_TOTAL /* max enum */
} srv_ss_event_enum;
#endif /* __BUILD_DOM__ */


/* 
 * SS action notification type
 */
typedef enum
{
    SRV_SS_ACT_NOTIFY_START,
    SRV_SS_ACT_NOTIFY_END,
    SRV_SS_ACT_NOTIFY_TOTAL
} srv_ss_act_notify_enum;


/* 
 * SS indication type
 */
typedef enum
{
    SRV_SS_IND_USSN, /* indication for USSN. srv_ss_ussn_ind_struct */
    SRV_SS_IND_USSR, /* indication for USSR. srv_ss_ussr_ind_struct */
    SRV_SS_IND_ABORT, /* indication for abort SS session. srv_ss_abort_ind_struct */
    SRV_SS_IND_TOTAL /* max enum */
} srv_ss_ind_enum;


/* 
 * source id
 */
typedef enum
{
    SRV_SS_SRC_COMMON = 0, /* screen display is handled by ss app */
    SRV_SS_SRC_MCARE, /* screen display is handled by mcare */
    SRV_SS_SRC_CALLSET, /* screen display is handled by call setting app */
    SRV_SS_SRC_ID_TOTAL /* max enum */
} srv_ss_source_id_enum;


/* 
 * SS direction
 */
typedef enum
{
    SRV_SS_DIR_MO,  /* MO SS */
    SRV_SS_DIR_MT,  /* MT SS */
    SRV_SS_DIR_NONE /* none */
} srv_ss_direction_enum;


/* 
 * SS action type
 */
typedef enum
{
    SRV_SS_ACTION_TYPE_ACTIVATE,   /* activation */
    SRV_SS_ACTION_TYPE_DEACTIVATE, /* registration */
    SRV_SS_ACTION_TYPE_QUERY, /* interrogation */
    SRV_SS_ACTION_TYPE_CHANGE_PASSWD, /* change password, igore bar_type */
    SRV_SS_ACTION_TYPE_TOTAL /* max enum */
} srv_ss_action_type_enum;


/* 
 * call barring type
 */
typedef enum
{
   SRV_SS_CALL_BAR_BAOC,    /* call barring all outgoing calls */
   SRV_SS_CALL_BAR_BOIC,   /* call barring all outgoing international calls */
   SRV_SS_CALL_BAR_BOICEXHC,   /* call barring all outgoing international calls except home */
   SRV_SS_CALL_BAR_BAIC,    /* call barring all incoming calls */
   SRV_SS_CALL_BAR_BAICROAM,    /* call barring all incoming roaming calls */
   SRV_SS_CALL_BAR_BAC, /* call barring all calls */
   SRV_SS_CALL_BAR_BOC, /* call barring all outgoing calls */
   SRV_SS_CALL_BAR_BIC, /* call barring all incoming calls */

   SRV_SS_CALL_BAR_TYPE_UNKNOWN /* max enum */
} srv_ss_call_bar_type_enum;


/* 
 * call forwarding type
 */
typedef enum
{
   SRV_SS_CALL_FORWARD_CFU, /* call forward unconditional */
   SRV_SS_CALL_FORWARD_CFB, /* Call forwarding on mobile subscriber busy */
   SRV_SS_CALL_FORWARD_CFNRY,   /* Call forwarding on no reply */
   SRV_SS_CALL_FORWARD_CFNRC,   /* Call forwarding on mobile subscriber not reachable */
   SRV_SS_CALL_FORWARD_CFALL,   /* call forward all */
   SRV_SS_CALL_FORWARD_CFALLCONDITIONAL, /* call forward all conditional, not support for now */
   SRV_SS_CALL_FORWARD_TYPE_UNKNOWN /* max enum */
} srv_ss_call_forward_type_enum;


/* 
 * call identification type
 */
typedef enum
{
   SRV_SS_CALL_ID_CLIP, /* Calling Line Identification Presentation */
   SRV_SS_CALL_ID_CLIR, /* Calling Line Identification Restriction */
   SRV_SS_CALL_ID_COLP, /* Connected Line Identification Presentation */
   SRV_SS_CALL_ID_COLR, /* Connected Line Identification Restriction */
   SRV_SS_CALL_ID_TYPE_TOTAL /* max enum */
} srv_ss_call_id_type_enum;


/* 
 * call type
 */
typedef enum
{
   SRV_SS_VOICE_CALL, /* voice call */
   SRV_SS_VIDEO_CALL, /* video call */
   SRV_SS_DATA_CALL, /* data call */
   SRV_SS_ALL_CALL, /* all call */
   SRV_SS_CALL_TYPE_TOTAL /* max enum */
} srv_ss_call_type_enum;


/* 
 * SS Basic Service group number
 */
typedef enum {                            
   SRV_SS_BS_CODE_ALL_TELESERVICES, /* bs code */
   SRV_SS_BS_CODE_TELEPHONY,    /* bs code */
   SRV_SS_BS_CODE_ALL_DATA_TELESERVICES,        /* bs code */
   SRV_SS_BS_CODE_FACSIMILE_SERVICES,   /* bs code */
   SRV_SS_BS_CODE_SHORT_MESSAGE_SERVICES,   /* bs code */
   SRV_SS_BS_CODE_ALL_TELESERVICES_EXCEPT_SMS,  /* bs code */
   SRV_SS_BS_CODE_VOICE_GROUP_CALL_SERVICE, /* bs code */	
   SRV_SS_BS_CODE_VOICE_BROADCAST_SERVICE,  /* bs code */
   SRV_SS_BS_CODE_ALL_BEARER_SERVICES,  /* bs code */
   SRV_SS_BS_CODE_ALL_ASYNC_SERVICES,   /* bs code */
   SRV_SS_BS_CODE_ALL_SYNC_SERVICES,    /* bs code */
   SRV_SS_BS_CODE_ALL_DATA_CIRCUIT_SYNC,    /* bs code */
   SRV_SS_BS_CODE_ALL_DATA_CIRCUIT_ASYNC,   /* bs code */
   SRV_SS_BS_CODE_ALL_GPRS_BEARER_SERVICES, /* bs code */
   SRV_SS_BS_CODE_ALLPADACCESSCA_SERVICES,  /* bs code */
   SRV_SS_BS_CODE_ALLDATAPDS_SERVICES,  /* bs code */
   SRV_SS_BS_CODE_AUXILIARY_TELEPHONY,  /* bs code */
   SRV_SS_BS_CODE_TOTAL /* max enum */
} srv_ss_bs_code_enum;


/* 
 * ss general result cause
 */
typedef enum
{
    SRV_SS_RESULT_OK = 0 ,  /* success. result is OK */
    SRV_SS_RESULT_INVALID_INPUT,    /* fail. the input parameter is invalid input */
    SRV_SS_RESULT_BUSY, /* fail. ss service is waiting for response or is in ss session */
    SRV_SS_RESULT_NOT_AVAILABLE, /* fail. not available */
    SRV_SS_RESULT_ABORT, /* fail. action is aborted */
    SRV_SS_RESULT_INVALID_NUMBER,      /* fail. the input parameter is invalid number */
    SRV_SS_RESULT_CMD_NOT_SUPPORT, /* fail. the command is not supported by ss service for now */
    SRV_SS_RESULT_PASSWD_WRONG, /* fail. wrong password */
    SRV_SS_RESULT_PASSWD_BLOCK, /* fail. password blocked */ 
    SRV_SS_RESULT_AUTO_REJECT,  /* fail. it's caused by auto reject */
    SRV_SS_RESULT_FDN_FAIL, /* fail. FDN blocked */
    SRV_SS_RESULT_SESSION_NOT_EXIST, /* ss session doesn't exist */
    SRV_SS_RESULT_ERROR_WITH_PS_CAUSE,    /* fail. error with ps cause, used in responses by the protocol stack */
    SRV_SS_RESULT_UNSPECIFIED_ERROR,    /* fail. it's general error */
    SRV_SS_RESULT_END_OF_ENUM   /* Max result cause */
} srv_ss_result_enum;


/* 
 * SS status
 */
typedef enum
{
    SRV_SS_STATUS_ACTIVATED,   /* actived */
    SRV_SS_STATUS_ACTIVATED_PERMANTLY, /* activated permantly */
    SRV_SS_STATUS_ACTIVATED_BY_DEFAULT, /* activated by default */
    SRV_SS_STATUS_DEACTIVATED, /* deactived */
    SRV_SS_STATUS_DEACTIVATED_BY_DEFAULT, /* deactivated by default */
    SRV_SS_STATUS_PROVIDED, /* provided */
    SRV_SS_STATUS_NOT_PROVIDED, /* unprovided */
    SRV_SS_STATUS_STATUS_TOTAL /* max enum */
} srv_ss_status_enum;


/****************************************************************************
 * structure                                                            
 *****************************************************************************/


/* 
 * SS response structure
 *   data = NULL when result is not OK
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_SS_ORI_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ss_result_enum result;  /* result cause */
    srv_ss_ps_cause_enum ps_cause;
    srv_ss_act_enum opcode;
    void *data; /* if result == SRV_SS_RESULT_OK, cast according to opcode */
                /* if result != SRV_SS_RESULT_OK, data is NULL */
} srv_ss_rsp_struct;


/* 
 * SS response event structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER /* event parameter header */
    /* DOM-NOT_FOR_SDK-END */
    srv_ss_rsp_struct rsp;
} srv_ss_rsp_evt_struct;


/* 
 * SS action request structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_SS_ORI_HEADER
    /* DOM-NOT_FOR_SDK-END */
} srv_ss_act_req_struct;


/* 
 * SS call forward request structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_SS_ORI_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ss_call_forward_type_enum type; /* call forward type */
    srv_ss_call_type_enum call_type; /* call type to apply call forwarding */
    srv_ss_action_type_enum action;  /* ss action */
    WCHAR forward_number[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* number in ucs2 */
    U8 no_reply_timer; /* no reply timer, SRV_SS_MIN_CFNRY_TIME~SRV_SS_MAX_CFNRY_TIME */
} srv_ss_call_forward_req_struct;


/* 
 * SS call forward result list structure
 */
typedef struct {
   srv_ss_bs_code_enum bs_code; /* basic service code */
   srv_ss_status_enum status; /* ss status */
   WCHAR number[SRV_UCM_MAX_NUM_URI_LEN + 1]; /* forworeded-to number, in ucs2 */
   U8 no_reply_timer; /* no reply timer, in seconds */
} srv_ss_call_forward_list_struct;

                                                       
/* 
 * SS call forward action response structure
 */
typedef struct
{
    srv_ss_call_forward_type_enum type; /* call forward type */
    U8 result_list_count;   /* result list count; 0 implies status == SRV_SS_STATUS_DEACTIVATED */
    srv_ss_call_forward_list_struct result_list[SRV_SS_MAX_BS_LIST_NUM];  /* result list */
} srv_ss_call_forward_rsp_struct;


/* 
 * SS call barring request structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_SS_ORI_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ss_call_bar_type_enum type; /* call bar type; ignore when action is SRV_SS_ACTION_TYPE_CHANGE_PASSWD */
    srv_ss_call_type_enum call_type; /* call type to apply call barring */
    srv_ss_action_type_enum action; /* ss action */
    WCHAR password_old[SRV_SS_PASSWORD_MAX_LENTH + 1]; /* old password, used in activation / deactivation / change password */
    WCHAR password_new[SRV_SS_PASSWORD_MAX_LENTH + 1]; /* new password, used only in change password */
    WCHAR password_cnf[SRV_SS_PASSWORD_MAX_LENTH + 1]; /* password, used only in change password */
} srv_ss_call_bar_req_struct;


/* 
 * SS call barring result list structure
 */
typedef struct {
   srv_ss_bs_code_enum bs_code; /* basic service code */
   srv_ss_status_enum status; /* ss status */
} srv_ss_call_bar_list_struct;


/* 
 * SS call barring action response structure
 */
typedef struct
{
    MMI_BOOL change_passwd; /* MMI_TRUE if the operation is changeing password; app may ignore type / bs_list info in this case */
    srv_ss_call_bar_type_enum type; /* call bar type */
    U8 result_list_count;   /* result list count; 0 implies status == SRV_SS_STATUS_DEACTIVATED */
    srv_ss_call_bar_list_struct result_list[SRV_SS_MAX_BS_LIST_NUM];  /* result list */
} srv_ss_call_bar_rsp_struct;


/* 
 * SS call waiting request structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_SS_ORI_HEADER
    /* DOM-NOT_FOR_SDK-END */
    /*srv_ss_call_type_enum call_type;*/ /* call type to apply call waiting, not support for now */
    srv_ss_action_type_enum  action; /* ss action */    
} srv_ss_call_wait_req_struct;

              
/* 
 * SS call wait action response structure
 */
typedef struct
{
    srv_ss_status_enum status; /* ss status */
    U8 bs_list_count;   /* result list count */
    srv_ss_bs_code_enum bs_list[SRV_SS_MAX_BS_LIST_NUM];  /* list of base service code */
} srv_ss_call_wait_rsp_struct;


/* 
 * SS call identification response structure
 */
typedef struct
{
    srv_ss_call_id_type_enum type; /* CID type */
    srv_ss_status_enum status;  /* ss status */
} srv_ss_call_id_rsp_struct;


/* 
 * SS CNAP response structure
 */
typedef struct
{
    srv_ss_status_enum status;  /* ss status */
} srv_ss_cnap_rsp_struct;


/* 
 * SS CCBS response structure
 */
typedef struct
{
    srv_ss_status_enum status;  /* ss status */
} srv_ss_ccbs_rsp_struct;


/* 
 * SS eMLPP response structure
 */
typedef struct
{
    srv_ss_status_enum status;  /* ss status */
    U8 default_pri; /* default priority */
    U8 max_pri; /* maximum priority */
} srv_ss_emlpp_rsp_struct;


/* 
 * USSD response indication structure
 */
typedef struct
{
    MMI_BOOL end_of_session; /* MMI_TRUE if ss session is closed; app may check this flag to decide wheather the result display is needed */
    WCHAR string[SRV_SS_MAX_LENGTH + 1];     /* ussd string in ucs2 */
} srv_ss_ussd_rsp_struct;


/* 
 * SS operation request structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_SS_ORI_HEADER
    /* DOM-NOT_FOR_SDK-END */
    WCHAR string[SRV_SS_MAX_LENGTH + 1];  /* ss / ussd string in ucs2 */
} srv_ss_operation_req_struct;


/* 
 * SS abort request structure
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_SS_ORI_HEADER
    /* DOM-NOT_FOR_SDK-END */
} srv_ss_abort_req_struct;


/* 
 * event structure for EVT_ID_SRV_SS_INDICATION
 */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER /* event parameter header */
    SRV_SS_ORI_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ss_ind_enum ind_type; /* Indication type */
    void *data; /* Data pointer */
} srv_ss_ind_evt_struct;


/* 
 * event structure for EVT_ID_SRV_SS_ACT_NOTIFY
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER /* event parameter header */
    /* DOM-NOT_FOR_SDK-END */
    srv_ss_act_notify_enum type;
    srv_ss_act_enum act_op; /* action operation code */
    void *info; /* for ACT_START, request information which is casted according to act_op */
                /* for ACT_END, response information, srv_ss_rsp_struct */
} srv_ss_act_notify_evt_struct;


/* 
 * SS USSN indication structure
 */
typedef struct
{
    srv_ss_direction_enum direction; /* MO/MT */
    WCHAR string[SRV_SS_MAX_LENGTH + 1];     /* ussd string in ucs2 */   
} srv_ss_ussn_ind_struct;


/* 
 * SS USSR indication structure
 */
typedef struct
{
    srv_ss_direction_enum direction; /* MO/MT */
    WCHAR string[SRV_SS_MAX_LENGTH + 1];  /* ussd string in ucs2 */   
} srv_ss_ussr_ind_struct;


/* 
 * SS abort indication structure
 */
typedef struct
{
    srv_ss_result_enum result;  /* result cause */
    srv_ss_ps_cause_enum ps_cause;
} srv_ss_abort_ind_struct;


/* 
 * SS result string structure
 */
typedef struct
{
    WCHAR string[SRV_SS_MAX_CAUSE_LENGTH + 1];  /* string in ucs2 */   
} srv_ss_cause_str_struct;



/****************************************************************************
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ss_act_req
 * DESCRIPTION
 *  to request the ss action
 * PARAMETERS
 *  act_op : [IN] action operation code
 *  act_data : [IN] action parameters
 *  callback : [IN] callback to notify the result, srv_ss_rsp_evt_struct, can be NULL
 *  user_data : [IN] user data, can be NULL
 * RETURNS
 *  srv_ss_result_enum, not OK if the request is rejected directly by ss service
 *  The caller app shall handle the error pop-up if the request is rejected directly by ss service.
 *  Ss srv sends rsp but doesn't act start / act_end if the op is rejected directly by ss srv
 *  In other cases, ss app takes charge of the requesting and result display
 *****************************************************************************/
extern srv_ss_result_enum srv_ss_act_req(srv_ss_act_enum act_op, void *act_data, mmi_proc_func callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_is_available
 * DESCRIPTION
 *  to check if ss service is available
 * PARAMETERS
 *  sim : [IN] target sim
 * RETURNS
 *  MMI_TRUE if ss service is available
 *****************************************************************************/
extern MMI_BOOL srv_ss_is_available(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_is_valid_ss_string
 * DESCRIPTION
 *  to check if str is valid ss string
 * PARAMETERS
 *  sim : [IN] target sim
 *  length : [IN] string length
 *  WCHAR : [IN] string
 * RETURNS
 *  MMI_TRUE if it is valid ss string
 *****************************************************************************/
extern MMI_BOOL srv_ss_is_valid_ss_string(mmi_sim_enum sim, U8 length, WCHAR * str);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_is_valid_call_forward_number
 * DESCRIPTION
 *  to check if str is valid call forwarding number
 * PARAMETERS
 *  sim : [IN] target sim
 *  length : [IN] string length
 *  WCHAR : [IN] string
 * RETURNS
 *  MMI_TRUE if it is valid call forwarding number
 *****************************************************************************/
extern MMI_BOOL srv_ss_is_valid_call_forward_number(mmi_sim_enum sim, U8 length, WCHAR * str);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_result_string
 * DESCRIPTION
 *  to get the SS default result string
 * PARAMETERS
 *  result : [IN] result
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_result_string(srv_ss_result_enum result);


#ifdef __MMI_SS_SHOW_CAUSE__
/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_cause_string
 * DESCRIPTION
 *  to get the SS default error cause string
 * PARAMETERS
 *  cause : [IN] error cause
 *  str : [OUT] result string
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_ss_get_cause_string(srv_ss_ps_cause_enum cause, srv_ss_cause_str_struct *str);
#endif /* __MMI_SS_SHOW_CAUSE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_status_string
 * DESCRIPTION
 *  to get the SS default status string
 * PARAMETERS
 *  status : [IN] status
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_status_string(srv_ss_status_enum status);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_bs_string
 * DESCRIPTION
 *  to get the SS default basic service string
 * PARAMETERS
 *  bs_code : [IN] basic service code
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_bs_string(srv_ss_bs_code_enum bs_code);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_call_forward_type_string
 * DESCRIPTION
 *  to get the call forwarding type string
 * PARAMETERS
 *  type : [IN] call forward type
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_call_forward_type_string(srv_ss_call_forward_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_call_bar_type_string
 * DESCRIPTION
 *  to get the call barring type string
 * PARAMETERS
 *  type : [IN] call bar type
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_call_bar_type_string(srv_ss_call_bar_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_call_wait_string
 * DESCRIPTION
 *  to get the call waiting string
 * PARAMETERS
 *  void
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_call_wait_string(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_call_id_type_string
 * DESCRIPTION
 *  to get the call identification type string
 * PARAMETERS
 *  type : [IN] call id type
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_call_id_type_string(srv_ss_call_id_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_cnap_string
 * DESCRIPTION
 *  to get the cnap string
 * PARAMETERS
 *  void
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_cnap_string(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_ccbs_string
 * DESCRIPTION
 *  to get the ccbs string
 * PARAMETERS
 *  void
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_ccbs_string(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_get_emlpp_string
 * DESCRIPTION
 *  to get the emlpp string
 * PARAMETERS
 *  void
 * RETURNS
 *  string ID
 *****************************************************************************/ 
extern U16 srv_ss_get_emlpp_string(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ss_check_capability
 * DESCRIPTION
 *  check ss capability
 * PARAMETERS
 *  sim : [IN]    target sim
 *  op : [IN] operation
 *  type : [IN] ss type
 *  call_type : [IN] call type
 * RETURNS
 *  MMI_TRUE if SIM supports the SS
 *****************************************************************************/
extern MMI_BOOL srv_ss_check_capability(mmi_sim_enum sim, srv_ss_act_enum op, U8 type, srv_ss_call_type_enum call_type);


#endif /* SRV_SS_GPROT_H */ 

