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
 * OppSrv.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI BIP service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OPP_SUPPORT__
#ifndef __SRV_OPP_GPROT_H__
#define __SRV_OPP_GPROT_H__
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "BtcmSrvGprot.h"
#include "stack_msgs.h"
/* auto add by kw_check end */
typedef S32(*bt_notify) (S32 srv_hd, U32 event, void *para);

/* The result that service gives to MMI, it means success */
#define SRV_OPP_RESULT_OK       0
/* The result that service gives to MMI, it means the service handle that MMI supports is invalid */
#define SRV_OPP_RESULT_INVALID_HANDLE  -1
/* The result that service gives to MMI, it means the parameter that MMI supports is invalid */
#define SRV_OPP_RESULT_INVALID_PARAM   -2
/* The result that service gives to MMI, it means servuce is busy */
#define SRV_OPP_RESULT_STATE_BUSY  -3

/* The max length of OPP receiving object's name */
#define OPP_MAX_OBJ_NAME_LENGTH  128
/* The max length of OPP receiving object's type */
#define OPP_MAX_OBJ_MIME_LENGTH  80
/* The max length of device */
#define MAX_DEV_NAME  80

/* The max packet length of OPP client supports */
#ifdef __LOW_COST_SUPPORT_COMMON__
#define OPPC_MAX_OBEX_PACKET_LENGTH 7168
#define OPPS_MAX_OBEX_PACKET_LENGTH 7168
#else
#define OPPC_MAX_OBEX_PACKET_LENGTH 14336
#define OPPS_MAX_OBEX_PACKET_LENGTH 14336
#endif

/* OPP client default type */
#define MMI_OPP_SND_DEFAULT_OBJTYPE "Unknown"

/* Event that serveice uses to notify MMI, it means activing OPP successfully */
#define SRV_OPP_EVENT_START     0x00000001
/* Event that serveice uses to notify MMI, it means deactiving OPP successfully */
#define SRV_OPP_EVENT_STOP      0x00000002
/* Event that serveice uses to notify MMI, it means connecting successfully */
#define SRV_OPP_EVENT_CONN_NOTIFY   0x00000004
/* Event that serveice uses to notify MMI, it tells sending status */
#define SRV_OPP_EVENT_SND_NOTIFY    0x00000008
/* Event that serveice uses to notify MMI, it means disconnecting successfully */
#define SRV_OPP_EVENT_DISCONN_NOTIFY   0x00000010
/* Event that serveice uses to notify MMI, it means authorizing successfully */
#define SRV_OPP_EVENT_AUTHORIZE_NOTIFY  0x00000020
/* Event that serveice uses to notify MMI, it tells receiving status */
#define SRV_OPP_EVENT_RECV_NOTIFY   0x00000040

/***************************************************************************** 
* enum
*****************************************************************************/
/* OPP role enum */
typedef enum
{
    SRV_OPP_ROLE_CLIENT = 1,                            /* OPP client */
    SRV_OPP_ROLE_SERVER,                                /* OPP server */
    SRV_OPP_ROLE_END
} srv_opp_role_enmu;
/* OPP error enum */
typedef enum
{
    SRV_OPP_PUT_TYPE = 1,                               /* unknown file type */
    SRV_OPP_DRM,                                        /* DRM prohibited */
    SRV_OPP_DISK_FULL,                                  /* disk full */
    SRV_OPP_ROOT_DIR_FULL,                              /* root directory full */
    SRV_OPP_DEVICE_BUSY,                                /* device busy */
    SRV_OPP_MEDIA_CHANGED,                              /* no memory card */
    SRV_OPP_WRITE_PROTECT,                              /* write protected */
    SRV_OPP_WRITE_FAIL,                                 /* write file fail */
    SRV_OPP_USER_ABORT,                                 /* receive file fail */
    SRV_OPP_RECEIVE_FAIL,
    SRV_OPP_ALL_ERR_END
} srv_opp_err_enum;
/* OPP connect result enum */
typedef enum
{
    SRV_OPP_CONN_SUCC,                                  /* connect successfully */
    SRV_OPP_CONN_FAILED,                                /* connect failed maybe some reason exclude user abort */
    SRV_OPP_CONN_SCO_REJECT,                            /* connect failed because of sco-link */
    SRV_OPP_CONN_END
} srv_opp_conn_type_enum;
/* OPP client send status enum */
typedef enum
{
    SRV_OPP_SND_READY,                                  /* ready to send */
    SRV_OPP_SND_SUCC,                                   /* send successfully */
    SRV_OPP_SND_FAIL,                                   /* fail to send */
    SRV_OPP_SND_FAIL_BY_SERVER,                         /* server error */
    SRV_OPP_SND_PERSENT,                                /* notify MMI to update percent when sending first and last packet */
    SRV_OPP_SND_DONE,                                   /* finish sending */
    SRV_OPP_SND_END
} srv_opp_snd_type_enum;
/* OPP server receive status enum */
typedef enum
{
    SRV_OPP_RECV_READY,                                 /* ready to receive */
    SRV_OPP_RECV_BEGIN,                                 /* start to receive */
    SRV_OPP_RECV_SUCCESS,                               /* ready successfully */
    SRV_OPP_RECV_FAIL,                                  /* fail to receive */
    SRV_OPP_RECV_END
} srv_opp_recv_type_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/
/* stuct for calculate percent */
typedef struct
{
    U32 total_obj_len;                                 /* total length of sending object */
    U32 remain_put_len;                                /* remain length of sending object */
} srv_opp_obj_info_struct;
/* stuct for object detail */
typedef struct
{
    U32 total_len;                                     /* total length of object */
    U16 name[OPP_MAX_OBJ_NAME_LENGTH];                 /* object name */
    U8 mime_type[OPP_MAX_OBJ_MIME_LENGTH];             /* object type */
}srv_opp_obj_detail_struct;

/* stuct for OPP server service to notify MMI connecting */
typedef struct
{
    U8 type;                                           /* srv_opp_conn_type_enum */
    U32 conn_id;                                       /* cm conn_id, UI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;                         /* server UI used to notify cm, */
    //U8 dev_name[MAX_DEV_NAME];                       /* server UI used, if not paired device, ui use the it */
} srv_opp_conn_notify_struct;
/* stuct for service to notify MMI disconnecting */
typedef struct
{
    U32 conn_id;                                       /* cm conn_id, MMI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;                         /* device address */
} srv_opp_disconn_notify_struct;
/* stuct for OPP client service to notify MMI*/
typedef struct
{
    U8 type;                                           /* srv_opp_snd_type_enum */
    //S32 err_code;
    U8 supported_formats;                              /* store OPP server supported formats */
    srv_opp_obj_info_struct info;                      /* the object's sending info */
} srv_opp_snd_notify_struct;
/* stuct for service to notify MMI authorizing status */
typedef struct
{
    U32 conn_id;                                       /* cm conn_id, UI use it to notify cm */
    U8 dev_name[MAX_DEV_NAME];                         /* server UI used, if not paired device, ui use it */
    srv_bt_cm_bt_addr bt_addr;                         /* device address */
} srv_opp_authorize_notify_struct;
/* stuct for OPP server service to notify MMI receiving status */
typedef struct
{
    U8 type;                                           /* srv_opp_recv_type_enum */
    U32 conn_id;                                       /* cm conn_id, MMI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;                         /* device address */
    union
    {
        struct{
            U32 mime;                                  /* object type */
            U16 *recv_path;                            /* object receive path */
        }obj;                                          /* receiving object info */
        srv_opp_obj_detail_struct detail;              /* receiving object detail */
        S32 err_code;                                  /* error code */
    }u;
}srv_opp_recv_notify_struct;


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_opp_event_hdlr
 * DESCRIPTION
 *  This function is to handle OPP event from OBEX.
 * PARAMETERS
 *  msg_id:          message id
 *  msg:             message info
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_opp_event_hdlr(msg_type msg_id, void *msg);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_opp_init
 * DESCRIPTION
 *  This function is to initialize OPP service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_opp_init(void);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_opp_deinit
 * DESCRIPTION
 *  This function is to de-initialize OPP service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_opp_deinit(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_opp_open
 * DESCRIPTION
 *  This function is to open an OPP service handle.
 * PARAMETERS
 *  role:          srv_opp_role_enmu, OPP client or server
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_opp_open(U8 role);
/*****************************************************************************
 * FUNCTION
 *  srv_opp_close
 * DESCRIPTION
 *  This function is to close an OPP service handle.
 * PARAMETERS
 *  srv_hd:          service handle to be closed
 * RETURNS
 *  S32:             0 for ok, or it means fail
 *****************************************************************************/
extern S32 srv_opp_close(S32 srv_hd);
/*****************************************************************************
 * FUNCTION
 *  srv_opp_set_notify
 * DESCRIPTION
 *  This function is to set the function which will execute service's event.
 * PARAMETERS
 *  srv_hd:          service handle
 *  event_mask:      the event which will be received
 *  notifier:        the event handler
 * RETURNS
 *  S32:             0 for ok, or it means fail
 *****************************************************************************/
extern S32 srv_opp_set_notify(S32 srv_hd, U32 event_mask, bt_notify notifier);
/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_begin
 * DESCRIPTION
 *  This function is to start sending, it will send connnect request to server.
 * PARAMETERS
 *  srv_hd:          service handle
 *  dst_dev:         server address
 *  buffer:          the information to be sent
 *  buf_size:        the size of buffer
 * RETURNS
 *  S32:             0 for ok, or it means fail
 *****************************************************************************/
extern S32 srv_oppc_send_begin(S32 srv_hd, srv_bt_cm_bt_addr *dst_dev, U8 *buffer, U32 buf_size);
/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_obj
 * DESCRIPTION
 *  This function is to start sending object.
 * PARAMETERS
 *  srv_hd:          service handle
 *  path:            the path of the sending object
 *  name:            the name of the sending object
 * RETURNS
 *  S32:             0 for ok, or it means fail
 *****************************************************************************/
extern S32 srv_oppc_send_obj(S32 srv_hd, U16 *path, U16 *name);
/*****************************************************************************
 * FUNCTION
 *  srv_oppc_send_end
 * DESCRIPTION
 *  This function is to end sending object.
 * PARAMETERS
 *  srv_hd:          service handle
 * RETURNS
 *  S32:             0 for ok, or it means fail
 *****************************************************************************/
extern S32 srv_oppc_send_end(S32 srv_hd);
/*****************************************************************************
 * FUNCTION
 *  srv_opps_accept
 * DESCRIPTION
 *  This function is to accept the connect request.
 * PARAMETERS
 *  srv_hd:          service handle
 *  conn_id:         connect id
 *  path:            the path of the receiving object
 * RETURNS
 *  S32:             0 for ok, or it means fail
 *****************************************************************************/
extern S32 srv_opps_accept(S32 srv_hd, U16 *path);
/*****************************************************************************
 * FUNCTION
 *  srv_opps_reject
 * DESCRIPTION
 *  This function is to reject the connect request.
 * PARAMETERS
 *  srv_hd:          service handle
 * RETURNS
 *  S32:             0 for ok, or it means fail
 *****************************************************************************/
extern S32 srv_opps_reject(S32 srv_hd);
/*****************************************************************************
 * FUNCTION
 *  srv_oppc_is_idle
 * DESCRIPTION
 *  This function is to check if OPP client is idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:             MMI_TRUE for yes, MMI_FALSE for no
 *****************************************************************************/
extern MMI_BOOL srv_oppc_is_idle(void);
/*****************************************************************************
 * FUNCTION
 *  srv_oppc_is_sending
 * DESCRIPTION
 *  This function is to check if OPP client is sending.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:             MMI_TRUE for yes, MMI_FALSE for no
 *****************************************************************************/
extern MMI_BOOL srv_oppc_is_sending(void);
/*****************************************************************************
 * FUNCTION
 *  srv_oppc_is_aborting
 * DESCRIPTION
 *  This function is to check if OPP client is aborting.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:             MMI_TRUE for yes, MMI_FALSE for no
 *****************************************************************************/
extern MMI_BOOL srv_oppc_is_aborting(void);
/*****************************************************************************
 * FUNCTION
 *  srv_oppc_is_disconncting
 * DESCRIPTION
 *  This function is to check if OPP client is disconnecting.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:             MMI_TRUE for yes, MMI_FALSE for no
 *****************************************************************************/
extern MMI_BOOL srv_oppc_is_disconncting(void);
/*****************************************************************************
 * FUNCTION
 *  srv_oppc_get_obj_info
 * DESCRIPTION
 *  This function is to get sending object information.
 * PARAMETERS
 *  obj_info:            the sending information
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_oppc_get_obj_info(srv_opp_obj_info_struct *obj_info);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_opps_is_idle
 * DESCRIPTION
 *  This function is to check if OPP server is idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:             MMI_TRUE for yes, MMI_FALSE for no
 *****************************************************************************/
extern MMI_BOOL srv_opps_is_idle(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_opps_is_active
 * DESCRIPTION
 *  This function is to check if OPP server is active.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:             MMI_TRUE for yes, MMI_FALSE for no
 *****************************************************************************/
extern MMI_BOOL srv_opps_is_active(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_opps_is_receiving
 * DESCRIPTION
 *  This function is to check if OPP server is receiving.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:             MMI_TRUE for yes, MMI_FALSE for no
 *****************************************************************************/
extern MMI_BOOL srv_opps_is_receiving(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_opps_is_accepted
 * DESCRIPTION
 *  This function is to check if OPP server is accepted.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL:             MMI_TRUE for yes, MMI_FALSE for no
 *****************************************************************************/
extern MMI_BOOL srv_opps_is_accepted(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_opps_activate
 * DESCRIPTION
 *  This function is to activate OPP.
 * PARAMETERS
 *  srv_hd:               service handler
 * RETURNS
 *  S32:                  0 for ok, or it means fail
 *****************************************************************************/
extern void srv_opps_activate(void);
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_opps_activate
 * DESCRIPTION
 *  This function is to deactivate OPP.
 * PARAMETERS
 *  srv_hd:               service handler
 * RETURNS
 *  S32:                  0 for ok, or it means fail
 *****************************************************************************/
extern void srv_opps_deactivate(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_opp_close_temp_obj
 * DESCRIPTION
 *  This function is for OPP server to close the receiving file handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32:                  0 for ok, or it means fail
 *****************************************************************************/
extern S32 srv_opp_close_temp_obj(void);
/*****************************************************************************
 * FUNCTION
 *  srv_opps_disconn_client
 * DESCRIPTION
 *  This function is for OPP server to disconnect the client.
 * PARAMETERS
 *  S32
 * RETURNS
 *  S32:                  0 for ok, or it means fail
 *****************************************************************************/
extern S32 srv_opps_disconn_client(S32 srv_hd);


#ifdef __cplusplus
}
#endif

#endif /* __SRV_OPP_GPROT_H__ */ /* __SRV_OPP_GPROTS_H__ */
#endif /* __MMI_OPP_SUPPORT__ */ 

