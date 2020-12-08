/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  CnmgrSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  These are the external services provided by connection management service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CNMGR_SRV_GPROT_H
#define CNMGR_SRV_GPROT_H

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "abm_api.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/* Maximum number of active bearers (GPRS + CSD + WIFI) */
#if (MAX_ACTIVE_BEARER_NUM >= 1)
#define SRV_CNMGR_MAX_BEARER_NUM    (MAX_ACTIVE_BEARER_NUM)
#else
#define SRV_CNMGR_MAX_BEARER_NUM    (1)
#endif

/* Maximum number of supported SIM cards */
#define SRV_CNMGR_SIM_TOTAL         (MMI_MAX_SIM_NUM)

/* Default timer interval that Connection Management service request connection data and update to application */
#define SRV_CNMGR_DATA_UPDATE_INTERVAL_DEFAULT_VALUE    (30000)

/* Connection Management service request connection data and update to application every second */
#define SRV_CNMGR_DATA_UPDATE_INTERVAL_1_SEC            (1000)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* Connection Management service result enum */
typedef enum
{
    SRV_CNMGR_RESULT_SUCCESS = 0,           /* Success */
    SRV_CNMGR_RESULT_WAIT_FOR_RSP,          /* Connection Management service will call application's callback after job is done */
    SRV_CNMGR_RESULT_NOT_SUPPORT,           /* Not support the functionality */
    SRV_CNMGR_RESULT_FAILED,                /* General failed case */
    SRV_CNMGR_RESULT_INVALID_INPUT,         /* The input parameter is invalid */
    SRV_CNMGR_RESULT_INVALID_BEARER,        /* Bearer data is invalid */
    SRV_CNMGR_RESULT_REACH_MAX_SUPPORT_NUM, /* Can not support this request because the number of request has reached the maximum value */
    SRV_CNMGR_RESULT_NO_CONNECTION,         /* No connection exists */
    SRV_CNMGR_RESULT_TOTAL
} srv_cnmgr_result_enum;

/* Connection type enum */
typedef enum
{
    SRV_CNMGR_CONNECT_TYPE_LOCAL = 0,       /* Local connection type */
    SRV_CNMGR_CONNECT_TYPE_DIALUP,          /* Dial-up connection type */
    SRV_CNMGR_CONNECT_TYPE_TOTAL
} srv_cnmgr_connect_type_enum;

/* Bearer status enum */
typedef enum 
{
    SRV_CNMGR_BEARER_STATUS_DEACTIVE = 0,   /* Deactive state */
    SRV_CNMGR_BEARER_STATUS_ACTIVATING,     /* Activating state */
    SRV_CNMGR_BEARER_STATUS_ACTIVE,         /* Active state */
    SRV_CNMGR_BEARER_STATUS_DEACTIVATING,   /* Deactivating state */
    SRV_CNMGR_BEARER_STATUS_TOTAL
} srv_cnmgr_bearer_status_enum;

/* Bearer type enum */
typedef enum
{
    SRV_CNMGR_BEARER_TYPE_NONE   = 0x00,
    SRV_CNMGR_BEARER_TYPE_CSD    = 0x01,     /* CSD bearer */
    SRV_CNMGR_BEARER_TYPE_GPRS   = 0x02,     /* GPRS bearer */
    SRV_CNMGR_BEARER_TYPE_SIM_PS = 0x03,     /* CSD + GPRS */
    SRV_CNMGR_BEARER_TYPE_WIFI   = 0x04,     /* WIFI bearer */
    SRV_CNMGR_BEARER_TYPE_TOTAL  = 0x07
} srv_cnmgr_bearer_type_enum;

/* SIM bearer type enum */
typedef enum
{
    SRV_CNMGR_SIM_BEARER_TYPE_LOCAL_CSD = 0,    /* CSD bearer */
    SRV_CNMGR_SIM_BEARER_TYPE_LOCAL_GPRS,       /* GPRS bearer */
    SRV_CNMGR_SIM_BEARER_TYPE_LOCAL_SIM_PS,     /* CSD + GPRS */
    SRV_CNMGR_SIM_BEARER_TYPE_DIALUP,           /* Dial-up bearer */
    SRV_CNMGR_SIM_BEARER_TYPE_TOTAL
} srv_cnmgr_sim_bearer_type_enum;

/* Connection Management connection data enum */
typedef enum
{
    SRV_CNMGR_CONNECT_DATA_LAST_CONNECT_DURATION    = 0x01, /* Last connection duration */
    SRV_CNMGR_CONNECT_DATA_LAST_RECV_SIZE           = 0x02, /* Last received size */
    SRV_CNMGR_CONNECT_DATA_LAST_SENT_SIZE           = 0x04, /* Last sent size */
    SRV_CNMGR_CONNECT_DATA_LAST_DATA                = 0x07, /* SRV_CNMGR_CONNECT_DATA_LAST_CONNECT_DURATION | SRV_CNMGR_CONNECT_DATA_LAST_RECV_SIZE | SRV_CNMGR_CONNECT_DATA_LAST_SENT_SIZE */
    SRV_CNMGR_CONNECT_DATA_TOTAL_CONNECT_DURATION   = 0x08, /* Total connection duration */
    SRV_CNMGR_CONNECT_DATA_TOTAL_RECV_SIZE          = 0x10, /* Total received size */
    SRV_CNMGR_CONNECT_DATA_TOTAL_SENT_SIZE          = 0x20, /* Total sent size */
    SRV_CNMGR_CONNECT_DATA_TOTAL_DATA               = 0x38, /* SRV_CNMGR_CONNECT_DATA_TOTAL_CONNECT_DURATION | SRV_CNMGR_CONNECT_DATA_TOTAL_RECV_SIZE | SRV_CNMGR_CONNECT_DATA_TOTAL_SENT_SIZE */
    SRV_CNMGR_CONNECT_DATA_ALL_CONNECT_DURATION     = 0x09, /* SRV_CNMGR_CONNECT_DATA_LAST_CONNECT_DURATION | SRV_CNMGR_CONNECT_DATA_TOTAL_CONNECT_DURATION */
    SRV_CNMGR_CONNECT_DATA_ALL_RECV_SIZE            = 0x12, /* SRV_CNMGR_CONNECT_DATA_LAST_RECV_SIZE | SRV_CNMGR_CONNECT_DATA_TOTAL_RECV_SIZE */
    SRV_CNMGR_CONNECT_DATA_ALL_SENT_SIZE            = 0x24, /* SRV_CNMGR_CONNECT_DATA_LAST_SENT_SIZE | SRV_CNMGR_CONNECT_DATA_TOTAL_SENT_SIZE */
    SRV_CNMGR_CONNECT_DATA_ALL_DATA                 = 0x3F  /* SRV_CNMGR_CONNECT_DATA_LAST_DATA | SRV_CNMGR_CONNECT_DATA_TOTAL_DATA */
} srv_cnmgr_connect_data_enum;

/* SCRI check timer type */
typedef enum
{
    SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON = 0,
    SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF,
    SRV_CNMGR_SCRI_CHECK_TIMER_TOTAL
} srv_cnmgr_scri_check_timer_enum;

/* This structure contains connection data in detail */
typedef struct
{
    U64 last_sent_size;         /* Last sent size */
    U64 last_recv_size;         /* Last received size */
    U64 last_connect_duration;  /* Last connection duration */
    U64 total_sent_size;        /* Total sent size */
    U64 total_recv_size;        /* Total received size */
    U64 total_connect_duration; /* Total connection duration */
} srv_cnmgr_connect_data_detail_struct;

/* This structure is used for connection data query request */
typedef struct
{
    mmi_sim_enum                sim_id;         /* SIM id */
    srv_cnmgr_bearer_type_enum  bearer_type;    /* Bearer type */
} srv_cnmgr_connect_data_query_struct;

/* This structure is used to reply connection data to application */
typedef struct
{
    srv_cnmgr_connect_data_query_struct  query;                                /* Connection data query request */
    srv_cnmgr_connect_data_detail_struct data[SRV_CNMGR_CONNECT_TYPE_TOTAL];   /* Connection data */
} srv_cnmgr_connect_data_rsp_struct;

/* This structure is used for connection data reset request */
typedef struct
{
    mmi_sim_enum                sim_id;         /* SIM id */
    srv_cnmgr_bearer_type_enum  bearer_type;    /* Bearer type */
    srv_cnmgr_connect_type_enum connect_type;   /* Connection type */
    srv_cnmgr_connect_data_enum data_type;      /* Reset data type */
} srv_cnmgr_reset_data_req_struct;

/* This structure is used for connection data update notify */
typedef struct
{
    srv_cnmgr_connect_data_detail_struct sim_data[SRV_CNMGR_SIM_TOTAL][SRV_CNMGR_SIM_BEARER_TYPE_TOTAL];
    srv_cnmgr_connect_data_detail_struct wifi_data;
} srv_cnmgr_connect_data_notify_struct;


typedef struct
{
    MMI_BOOL uplink;
    MMI_BOOL downlink;
}srv_cnmgr_data_transfer_flag_struct;

/* This evt used to notify nwinfo app if highlight uplink and downlink icon*/
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				
    U16 size;               
    void *user_data;	    
#endif
	MMI_EVT_PARAM_HEADER		
    srv_cnmgr_data_transfer_flag_struct  flag[SRV_CNMGR_SIM_TOTAL];
} srv_cnmgr_notify_nwinfo_evt_struct;

/***************************************************************************** 
 * Callback function prototypes
 *****************************************************************************/

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_cnmgr_connect_data_cb_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function which is called to
 *  provide connection data.
 * PARAMETERS
 *  connect_data :      [IN]    Connection data
 *  user_data :         [IN]    User data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_cnmgr_connect_data_cb_funcptr_type)(srv_cnmgr_connect_data_rsp_struct *connect_data, void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_cnmgr_reset_data_cb_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function which is called after
 *  connection data is reset.
 * PARAMETERS
 *  reset_req :         [IN]    Reset connection data request
 *  result :            [IN]    Execution result
 *  user_data :         [IN]    User data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_cnmgr_reset_data_cb_funcptr_type)(srv_cnmgr_reset_data_req_struct *reset_req, srv_cnmgr_result_enum result, void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_cnmgr_connect_data_notify_cb_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function which is called to
 *  provide connection data periodically.
 * PARAMETERS
 *  connect_data :      [IN]    Connection data
 *  user_data :         [IN]    User data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_cnmgr_connect_data_notify_cb_funcptr_type)(srv_cnmgr_connect_data_notify_struct *connect_data, void *user_data);


/***************************************************************************** 
 * External interfaces (User : Apps)
 *****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_init
 * DESCRIPTION
 *  This API is used to initialize connection management service.
 * PARAMETERS
 *  evt	:	        [IN]	Init event notification
 * RETURN VALUES
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret srv_cnmgr_init(mmi_event_struct *evt);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_connection_data
 * DESCRIPTION
 *  This API is used to get connection data.
 * PARAMETERS
 *  query :         [IN]    The connection data that application wants to query
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_get_connection_data(
                                srv_cnmgr_connect_data_query_struct *query,
                                srv_cnmgr_connect_data_cb_funcptr_type cb_func,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_reset_connection_data
 * DESCRIPTION
 *  This API is used to reset connection data.
 * PARAMETERS
 *  reset_req :     [IN]    Reset connection data request
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_reset_connection_data(
                                srv_cnmgr_reset_data_req_struct *reset_req,
                                srv_cnmgr_reset_data_cb_funcptr_type cb_func,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_register_connection_data_notify
 * DESCRIPTION
 *  This API is used to register application's callback function to let CNMGR
 *  service notify connection data periodically.
 * PARAMETERS
 *  interval :      [IN]	Notification interval (unit: millisecond)
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  MMI_TRUE : Register successfully
 *  MMI_FALSE : Fail to register
 *****************************************************************************/
extern MMI_BOOL srv_cnmgr_register_connection_data_notify(
                    U32 interval,
                    srv_cnmgr_connect_data_notify_cb_funcptr_type cb_func,
                    void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_deregister_connection_data_notify
 * DESCRIPTION
 *  This API is used to deregister application's callback which is registered by
 *  calling srv_cnmgr_register_connection_data_notify().
 * PARAMETERS
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_deregister_connection_data_notify(
                                srv_cnmgr_connect_data_notify_cb_funcptr_type cb_func,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_set_scri_send_check_interval
 * DESCRIPTION
 *  This API is used to set the check interval for sending SCRI to network.
 *
 *  Before 3G Gemini 2.0 is ready, SCRI is usd to disconnecting RRC connection.
 *  CNMGR SRV will send RRC connection disconnect request to protocol if no data
 *  is transmitted for a period of time. The period is the maximum value of all
 *  check intervals set by applications.
 *
 *  After 3G Gemini 2.0 is ready, SCRI is used only for power-saving. CNMGR SRV
 *  will send fast dormancy request to protocol if no data
 *  is transmitted for a period of time. The period is the maximum value of all
 *  check intervals set by applications.
 * PARAMETERS
 *  type :          [IN]    SCRI check timer type
 *  interval :      [IN]	SCRI send check interval (unit: millisecond)
 *  id :            [OUT]   If set successfully, id is used to unset SCRI send check interval
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_set_scri_send_check_interval(
                                srv_cnmgr_scri_check_timer_enum type,
                                U32 interval,
                                U32 *id);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_scri_send_check_interval
 * DESCRIPTION
 *  This API is used to get the check interval for sending SCRI to network.
 * PARAMETERS
 *  type :          [IN]    SCRI check timer type
 *  interval :      [OUT]   SCRI send check interval (unit: millisecond)
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_get_scri_send_check_interval(srv_cnmgr_scri_check_timer_enum type, U32 *interval);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_unset_scri_send_check_interval
 * DESCRIPTION
 *  This API is used to unset the check interval for sending SCRI to network.
 * PARAMETERS
 *  id :            [IN]    id returned by set function
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_unset_scri_send_check_interval(U32 id);

#endif /* CNMGR_SRV_GPROT_H */
