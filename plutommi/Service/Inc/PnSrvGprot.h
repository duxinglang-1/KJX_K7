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
 *   PnSrvGprot.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements Push notification service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __SRV_PNS_GPROT_H__
#define __SRV_PNS_GPROT_H__
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_PNS__
#include "MMIDataType.h"
#include "mmi_cb_mgr_gprot.h"
#include "CbmSrvGprot.h"
/*****************************************************************************
 * Define
 *****************************************************************************/
#define SRV_PNS_REGID_LEN  26 /* include '\0' */
#define SRV_PNS_SENDERID_LEN 37 /* include '\0' */
#define SRV_PNS_ALERT_TEXT_MAX_LEN 250 /* include '\0' */
#define SRV_PNS_ACTION_TEXT_MAX_LEN 51 /* include '\0' */
#define SRV_PNS_MAX_MSGBODY_SIZE 257 /* include '\0' */
#define SRV_PNS_MAX_MPS_ARGS_NUM 3
#define SRV_PNS_MAX_MPS_ARG_LEN 21 /* include '\0' */
#define SRV_PNS_MAX_MPS_RES_STR_LEN 201 /* include '\0' */

/*****************************************************************************
 * Enum
 *****************************************************************************/

typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_PNS_BASE = SRV_PNS,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_SRV_PNS_START_REGISTER,     /* Notify applications to register */

    EVT_ID_SRV_PNS_REGISTER_RSP,
    EVT_ID_SRV_PNS_REGISTRATION_ID_CHANGED,
    EVT_ID_SRV_PNS_DEREGISTER_RSP,
    EVT_ID_SRV_PNS_MESSAGE,
    EVT_ID_SRV_PNS_ENTER_NS,
    EVT_ID_SRV_PNS_FORCE_CLOSED_COMPLETE,

    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_PNS_END
    /* DOM-NOT_FOR_SDK-END */
} srv_pns_notification_event_enum;

typedef enum
{
    SRV_PNS_NO_ERROR                         = 0,
    SRV_PNS_SERVICE_NOT_AVAILABLE            = -1,
    SRV_PNS_INVALID_DATA_CONNECTION          = -2,
    SRV_PNS_TOO_MANY_REGISTRATIONS           = -3,
    SRV_PNS_INVALID_SENDER                   = -4,
    SRV_PNS_INVALID_APPID                    = -5,
    SRV_PNS_LAST_MSG_ON_PROCESSING           = -6,
    SRV_PNS_SYSTEM_ERROR                     = -7,

    SRV_PNS_ALREADY_IN_QUEUE                 = -8,
    SRV_PNS_JSON_PARSING_ERR                 = -9,
    SRV_PNS_JSON_PAYLOAD_FORMAT_ERR          = -10,
    SRV_PNS_JSON_PAYLOAD_NOT_FOUND           = -11,

    SRV_PNS_PARAM_ERR                        = -12,
    SRV_PNS_QUERY_FAIL                       = -13,

    SRV_PNS_NOTIFICATION_OFF                 = -14,
    SRV_PNS_NETWORK_NOT_AVAILABLE            = -15,
    SRV_PNS_ERR_TOTAL                        = -100
} srv_pns_result;

typedef enum
{
    SRV_PNS_SETTING_OFF = 0,
    SRV_PNS_SETTING_ON,

    SRV_PNS_SETTING_END,
} srv_pns_global_setting_enum;

typedef enum
{
    SRV_PNS_INTERVAL_0 = 0,
    SRV_PNS_INTERVAL_1,
    SRV_PNS_INTERVAL_2,
    SRV_PNS_INTERVAL_3,
    SRV_PNS_INTERVAL_4,
    SRV_PNS_INTERVAL_5,
    SRV_PNS_INTERVAL_6,
    SRV_PNS_INTERVAL_7,

    SRV_PNS_INTERVAL_END,
} srv_pns_push_interval_enum;

/*****************************************************************************
 * Structure
 *****************************************************************************/

typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    U32 appId;
    char reg_id[SRV_PNS_REGID_LEN];                 /* registration id*/
    srv_pns_result result;
} srv_pns_reg_rsp_event_struct;

typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    
    U32 appId;
    char reg_id[SRV_PNS_REGID_LEN];   /* registration id*/
} srv_pns_change_reg_event_struc;

typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    
    U32 appId;
    srv_pns_result result;
} srv_pns_dereg_rsp_event_struct;

typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    
    U32 appId;
    S32 msgLen;                 /* message buffer length*/
    char* msgBody;
} srv_pns_msg_event_struct;

typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    
    srv_cbm_result_error_enum error; /* error */
    S32 error_cause; /* network error cause */
} srv_pns_force_close_rsp_event_struct;

typedef struct 
{
    /* alert begin */
    S32 mainLen;
    char main[SRV_PNS_ALERT_TEXT_MAX_LEN];
    S32 hintLen;
    char hint[SRV_PNS_ALERT_TEXT_MAX_LEN];
    S32 mainResId;
    char main_args[SRV_PNS_MAX_MPS_ARGS_NUM][SRV_PNS_MAX_MPS_ARG_LEN];
    S32 main_args_num;

    S32 hintResId;
    char hint_args[SRV_PNS_MAX_MPS_ARGS_NUM][SRV_PNS_MAX_MPS_ARG_LEN];
    S32 hint_args_num;
    /* alert end */
    S32 actionLen;
    char action[SRV_PNS_ACTION_TEXT_MAX_LEN];
    S32 actionResId;

    S32 badge;
    S32 icon;
    S32 sound;
} srv_pns_msg_mps_struct;

typedef struct 
{
    MMI_BOOL dictionary;
    char msgBody[SRV_PNS_MAX_MSGBODY_SIZE];
} srv_pns_msg_value_struct;

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
#endif
/******************************************************************************
 * FUNCTION
 *    srv_sns_init
 * DESCRIPTION
 *    service initialization
 * PARAMETERS
 *    void
 * RETURNS
 *    void
 ******************************************************************************/
void srv_pns_init(void);

/******************************************************************************
 * FUNCTION
 *    srv_pns_register
 * DESCRIPTION
 *    register
 * PARAMETERS
 *    U32 appId
 *    char* senderId
 *    mmi_proc_func cb: callback for response
 *    void* user_data
 * RETURNS
 *    void
 ******************************************************************************/
srv_pns_result srv_pns_register(U32 appId, char* senderId, mmi_proc_func cb, void* user_data);

/******************************************************************************
 * FUNCTION
 *    srv_pns_deregister
 * DESCRIPTION
 *    deregister
 * PARAMETERS
 *    U32 appId
 *    mmi_proc_func cb: callback for response
 *    void* user_data
 * RETURNS
 *    void
 ******************************************************************************/
srv_pns_result srv_pns_deregister(U32 appId, mmi_proc_func cb, void* user_data);

/******************************************************************************
 * FUNCTION
 *    srv_pns_setup_receive_cb
 * DESCRIPTION
 *    deregister
 * PARAMETERS
 *    U32 appId
 *    mmi_proc_func cb: callback for response
 *    void* user_data
 * RETURNS
 *    void
 ******************************************************************************/
srv_pns_result srv_pns_setup_receive_cb(U32 appId, mmi_proc_func cb, void* user_data);

/******************************************************************************
 * FUNCTION
 *    srv_pns_get_mps_info
 * DESCRIPTION
 *    get mps info
 * PARAMETERS
 *    char* msgBody: payload
 *    srv_pns_msg_mps_struct* mpsPtr
 * RETURNS
 *    void
 ******************************************************************************/
srv_pns_result srv_pns_get_mps_info(char* msgBody, srv_pns_msg_mps_struct* mpsPtr);

/******************************************************************************
 * FUNCTION
 *    srv_pns_get_object
 * DESCRIPTION
 *    get object according to specific key
 * PARAMETERS
 *    char* msgBody: payload
 *    char* key: key
 *    srv_pns_msg_value_struct* value
 * RETURNS
 *    void
 ******************************************************************************/
srv_pns_result srv_pns_get_object(char* msgBody, char* key, srv_pns_msg_value_struct* value);

/******************************************************************************
 * FUNCTION
 *    srv_pns_switch_global_setting
 * DESCRIPTION
 *    connect push server or not
 * PARAMETERS
 *    srv_pns_global_setting_enum flag: on/off
 * RETURNS
 *    void
 ******************************************************************************/
void srv_pns_switch_global_setting(srv_pns_global_setting_enum flag);

/******************************************************************************
 * FUNCTION
 *    srv_pns_set_interval
 * DESCRIPTION
 *    set the interval of push notification
 * PARAMETERS
 *    srv_pns_push_interval_enum flag: refer to hpnsPollingTimeList
 * RETURNS
 *    void
 ******************************************************************************/
void srv_pns_set_interval(srv_pns_push_interval_enum flag);

/******************************************************************************
 * FUNCTION
 *    srv_pns_get_global_setting
 * DESCRIPTION
 *    get the setting of push notification connection
 * PARAMETERS
 * RETURNS
 *    srv_pns_global_setting_enum
 ******************************************************************************/
srv_pns_global_setting_enum srv_pns_get_global_setting(void);

/******************************************************************************
 * FUNCTION
 *    srv_pns_get_interval
 * DESCRIPTION
 *    get the interval of push notification
 * PARAMETERS
 * RETURNS
 *    srv_pns_push_interval_enum
 ******************************************************************************/
srv_pns_push_interval_enum srv_pns_get_interval(void);

/******************************************************************************
 * FUNCTION
 *    srv_pns_query_reg
 * DESCRIPTION
 *    query the registration id of this app id
 * PARAMETERS
 *    U32 appId: application id
 *    char* buffer: buffer to put registration id
 *    S32 buffer_size: buffer size. at least SRV_PNS_REGID_LEN
 * RETURNS
 *    srv_pns_push_interval_enum
 ******************************************************************************/
srv_pns_result srv_pns_query_regid(U32 appId, char* buffer, S32 buffer_size);

/******************************************************************************
 * FUNCTION
 *    srv_pns_has_custom_payload
 * DESCRIPTION
 *    Query if there is custom object in the payload
 * PARAMETERS
 *    char* msgBody: payload
 * RETURNS
 *    MMI_TRUE: There is a custom object
 ******************************************************************************/
MMI_BOOL srv_pns_has_custom_payload(char* msgBody);

/******************************************************************************
 * FUNCTION
 *    srv_pns_force_close_connection
 * DESCRIPTION
 *    Force close push notification connection
 * PARAMETERS
 *    mmi_proc_func callback: callback when connection closed
 *    void* user_data: user data
 * RETURNS
 *    MMI_TRUE : Start to close connection
 *    MMI_FALSE: No need to close connection 
 ******************************************************************************/
MMI_BOOL srv_pns_force_close_connection(mmi_proc_func callback, void* user_data);

/******************************************************************************
 * FUNCTION
 *    srv_pns_resume_connection
 * DESCRIPTION
 *    Resume connection
 * PARAMETERS
 * RETURNS
 ******************************************************************************/
void srv_pns_resume_connection();

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
#endif

#endif /* __MMI_PNS__ */
#endif /* __SRV_PNS_GPROT_H__ */
