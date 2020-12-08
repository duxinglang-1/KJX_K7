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
 *  CnmgrSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  These are the internal services provided by connection management service.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CNMGR_SRV_IPROT_H
#define CNMGR_SRV_IPROT_H

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "CnmgrSrvGprot.h"
#include "abm_api.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/* Maximum number of supported applications */
#define SRV_CNMGR_MAX_SUPPORT_APP_NUM   (3)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* This structure is used to identify bearer */
typedef struct
{
    U32 account_id;     /* Account id */
    U8  connect_type;   /* Connection type: srv_cnmgr_connect_type_enum */
} srv_cnmgr_bearer_id_struct;

/* This structure is used to provide bearer data */
typedef struct
{
    U32 account_id;     /* Account id */
    U64 all_data_size;  /* All transmission data size */
    U64 connect_time;   /* Connection time */
    U8  connect_type;   /* Connection type: srv_cnmgr_connect_type_enum */
    U8  dialup_type;    /* Dial-up type: l4c_dialup_bearer_enum */
} srv_cnmgr_bearer_node_struct;

/* This structure is used to provide bearer list to CNMGR application */
typedef struct
{
    srv_cnmgr_bearer_node_struct node[SRV_CNMGR_MAX_BEARER_NUM];
    U8                           active_node_num;
} srv_cnmgr_bearer_list_struct;

/* This structure is used to provide detailed bearer data */
typedef struct
{
    U64 all_data_size;  /* All transmission data size */
    U64 recv_data_size; /* Received data size */
    U64 sent_data_size; /* Sent data size */
    U64 upload_rate;    /* Upload rate */
    U64 download_rate;  /* Download rate */
    U64 connect_time;   /* Connection time */
    U8  bearer_status;  /* Bearer status: srv_cnmgr_bearer_status_enum */
} srv_cnmgr_bearer_data_struct;


/***************************************************************************** 
 * Callback function prototypes
 *****************************************************************************/

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_cnmgr_notify_cb_funcptr_type
 * DESCRIPTION
 *  This type is used to define the notify callback function.
 * PARAMETERS
 *  user_data :     [IN]    User data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_cnmgr_notify_cb_funcptr_type)(void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 *
 * FUNCTION
 *  srv_cnmgr_cb_funcptr_type
 * DESCRIPTION
 *  This type is used to define the callback function.
 * PARAMETERS
 *  result :        [IN]    Execution result
 *  user_data :     [IN]    User data
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_cnmgr_cb_funcptr_type)(U8 result, void *user_data);


/***************************************************************************** 
 * Internal interfaces (User : Connection Management Application)
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_active_bearer_list
 * DESCRIPTION
 *  This API is used to get active bearer list.
 * PARAMETERS
 *  bearer_list	:   [OUT]   Active bearers
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_cnmgr_get_active_bearer_list(srv_cnmgr_bearer_list_struct *bearer_list);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_bearer_connection_data
 * DESCRIPTION
 *  This API is used to get bearer connection data.
 * PARAMETERS
 *  bearer :        [IN]    Bearer info (account id and connection type)
 *  bearer_data :   [OUT]   Bearer connection data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_get_bearer_connection_data(
                                srv_cnmgr_bearer_id_struct *bearer,
                                srv_cnmgr_bearer_data_struct *bearer_data);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_disconnect_all_bearer
 * DESCRIPTION
 *  This API is used to disconnect all bearer.
 * PARAMETERS
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_disconnect_all_bearer(srv_cnmgr_cb_funcptr_type cb_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_disconnect_bearer
 * DESCRIPTION
 *  This API is used to disconnect one bearer.
 * PARAMETERS
 *  bearer :        [IN]    Bearer
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_disconnect_bearer(
                                srv_cnmgr_bearer_id_struct *bearer,
                                srv_cnmgr_cb_funcptr_type cb_func,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_register_bearer_data_update_notify
 * DESCRIPTION
 *  This API is used to register application's callback for getting notification
 *  when bearer data is updated.
 * PARAMETERS
 *  interval :      [IN]    Data update interval (unit: millisecond)
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  MMI_TRUE : Register successfully
 *  MMI_FALSE : Fail to register
 *****************************************************************************/
extern MMI_BOOL srv_cnmgr_register_bearer_data_update_notify(
                    U32 interval,
                    srv_cnmgr_notify_cb_funcptr_type cb_func,
                    void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_deregister_bearer_data_update_notify
 * DESCRIPTION
 *  This API is used to deregister application's callback for getting notification
 *  when bearer data is updated.
 * PARAMETERS
 *  cb_func :       [IN]    Callback function
 *  user_data :     [IN]    User data
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_deregister_bearer_data_update_notify(srv_cnmgr_notify_cb_funcptr_type cb_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_cnmgr_get_bearer_status
 * DESCRIPTION
 *  This API is used to get bearer status.
 * PARAMETERS
 *  acct_id :       [IN]    Data account id
 *  bearer_status : [OUT]   Bearer status
 * RETURN VALUES
 *  srv_cnmgr_result_enum
 *****************************************************************************/
extern srv_cnmgr_result_enum srv_cnmgr_get_bearer_status(U32 acct_id, U8 *bearer_status);

#endif /* CNMGR_SRV_IPROT_H */
