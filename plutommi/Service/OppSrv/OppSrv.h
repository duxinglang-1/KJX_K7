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
 * OPPMMI.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OPP_SUPPORT__
#ifndef __SRV_OPP_H__
#define __SRV_OPP_H__
#include "MMIDataType.h"
/* auto add by kw_check begin */
#include "OppSrvGprot.h"
#include "bluetooth_struct.h"
#include "mmi_res_range_def.h"
#include "BtcmSrvGprot.h"
#include "fs_type.h"
#include "FileMgrSrvGProt.h"
#include "DebugInitDef_Int.h"
#include "MMI_conn_app_trc.h"
/* auto add by kw_check end */

/* app/srv split */
#define SRV_OPP_MAX_CLIENT_NUM  1
#define SRV_OPP_MAX_SERVER_NUM  1
#define SRV_OPP_SERVER_HANDLE_BEGIN   512       /* from the 513~ox7fff, it is server srv_hd */
/***************************************************************************** 
* Enum Value
*****************************************************************************/

typedef enum
{
    SRV_OPS_IDLE,               /* Initial state */
    SRV_OPS_OBEX_REGISTERING,   /* Registering OBEX instance */
    SRV_OPS_SDP_REGISTERING,    /* Registering OPP SDP */
    SRV_OPS_ACTIVE,             /* OPS service is active */
    SRV_OPS_AUTHORIZING,
    SRV_OPS_CONNECTED,          /* Bearer connection established */
    SRV_OPS_ACCEPTING,
    SRV_OPS_ACCEPTED,           /* Sent successful response */
    SRV_OPS_RECEIVING,          /* Receiving put indication */
    SRV_OPS_DISCONNECTING,      /* Disconnecting current session */
    SRV_OPS_DEACTIVATING        /* Send deactivate request to deactivate OPS service */
} SRV_OPS_STATE;

typedef enum
{
    SRV_OPC_IDLE,           /* Initial state */
    SRV_OPC_CONNECTING,     /* Send connect request to OPC service */
    SRV_OPC_CONNECTED,      /* the result of Connect rsp is success */
    SRV_OPC_SENDING,        /* Send put request to BCHS */
    SRV_OPC_ABORTING,       /* Abort current sending request */
    SRV_OPC_DISCONNECTING   /* Received failed response from peer */
} SRV_OPC_STATE;

typedef enum
{
    OPP_OBJ_ACTION_NONE,
    OPP_OBJ_ACTION_MOVE,
    OPP_OBJ_ACTION_RENAME
} opp_obj_action_enum;


typedef enum
{
    SRV_OPP_EVENT_OPEN_FAIL = OPP_BASE + 1,
    SRV_OPP_EVENT_SDP_REG,
    SRV_OPP_EVENT_MAX
}srv_opp_event_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/

typedef struct
{
    MMI_EVT_PARAM_HEADER
    S32 event_id;
    U8 role;
    void *data;
}srv_opp_event_struct;

/* OPC */

typedef struct
{
    U8 goep_conn_id;
    SRV_OPC_STATE state;/*because state num<256,so sizeof(state) = 1 byte(target)*/
    U8 supported_formats;
    U8 flag_abt; /*for PTS Test case TP/OPH/BV-27-I*/
    S32 cm_conn_id;
    FS_HANDLE h_snd;
    U8 *push_buff;
    U32 opc_mtu;
    U32 total_obj_len;
    U32 remain_put_len;
    U32 sending_len;
    srv_bt_cm_bt_addr dev_addr;
    U16 obj_path[SRV_FMGR_PATH_MAX_LEN + 1];
    U16 obj_name[OPP_MAX_OBJ_NAME_LENGTH];
    S8 obj_mime[OPP_MAX_OBJ_MIME_LENGTH];
}srv_oppc_cntx_struct;

typedef struct
{
    U8 goep_conn_id;
    SRV_OPS_STATE state;
    U32 obj_type;
    FS_HANDLE h_recv;
    S32 cm_conn_id;
    goep_push_ind_struct *push_pkt;
    srv_bt_cm_bt_addr dev_addr;
    U8 push_buff[OPPS_MAX_OBEX_PACKET_LENGTH];
#ifdef __MMI_BT_RX_ENHANCE__
    U8 stop_recv;
    U8 extra_buff[OPPS_MAX_OBEX_PACKET_LENGTH];
    U32 extra_buflen;
    S32 fs_err;
#endif /* __MMI_BT_RX_ENHANCE__ */ 
}srv_opps_cntx_struct;

typedef struct
{
    S32 srv_hd;
    U32 event_mask;
    bt_notify notifier;
    srv_oppc_cntx_struct oppc_cntx;
}srv_oppc_instance_struct;

typedef struct
{
    S32 srv_hd;
    U32 event_mask;
    bt_notify notifier;
    srv_opps_cntx_struct opps_cntx;
}srv_opps_instance_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/*****************************************************************************
* Internal Functions
*****************************************************************************/
static void srv_opp_disconnect_ind_handler(void *msg);
static mmi_ret srv_opp_post_proc(mmi_event_struct* para);
static void srv_oppc_init_cntx(void);
static void srv_oppc_connect_server(srv_bt_cm_bt_addr bt_addr, U32 buff_size);
static void srv_oppc_send_first_packet(void);
static void srv_oppc_connect_rsp_handler(void *msg);
static void srv_oppc_push_rsp_handler(void *msg);
static void srv_oppc_abort_rsp_handler(void *msg);
static void srv_oppc_disconnect_ind_handler(void *msg);
static void srv_oppc_supported_formats_ind_handler(void *msg);
static void srv_oppc_send_connect_req(U16 opp_client_max_packet_len, srv_bt_cm_bt_addr dest_addr);
static void srv_oppc_send_disconnect_req(U8 goep_conn_id, MMI_BOOL tpdisconn_flag);
static void srv_oppc_send_abort_req(U8 goep_conn_id);
static void srv_oppc_send_push_req(
                U8 goep_conn_id,
                goep_pkt_type_enum pkt_type,
                U32 total_obj_len,
                U16 *obj_name,
                PS8 obj_mime,
                U32 *frag_ptr,
                U16 frag_len);
static void srv_oppc_connection_terminated(void);
static MMI_BOOL srv_oppc_passkey_hdler(srv_bt_cm_bt_addr bd_addr);
static void srv_oppc_notify_app(U32 event_id, void *para);
static void srv_oppc_disconnect_from_cm(U32 conn_id);
static void srv_opps_init_cntx(void);
static void srv_opps_obex_register_server_req(void);
static void srv_opps_obex_register_server_rsp_handler(void *msg);
static void srv_opps_obex_deregister_server_req(void);
static void srv_opps_obex_deregister_server_rsp_handler(void *msg);
static void srv_opps_sdpdb_register_req(void);

static U8 srv_opps_sdpdb_register_cfn_handler(void *msg);
static void srv_opps_sdpdb_deregister_req(void);

static U8 srv_opps_sdpdb_deregister_cfn_handler(void *msg);
static void srv_opps_authorize_ind_hdler(void *msg);
static void srv_opps_connect_ind_handler(void *msg);
static void srv_opps_abort_ind_handler(void *msg);
static void srv_opps_push_ind_handler(void *msg);
static void srv_opps_first_push_ind_handler(goep_push_ind_struct *ind);
static void srv_opps_normal_push_ind_handler(goep_push_ind_struct *ind);
static void srv_opps_final_push_ind_handler(goep_push_ind_struct *ind);
static void srv_opps_proc_first_push_data(goep_push_ind_struct *ind, U16 *path);
static void srv_opps_pull_ind_handler(void *msg);
static void srv_opps_disconnect_ind_handler(void *msg);
static void srv_opps_send_disconnect_req(U8 goep_conn_id);
static void srv_opps_reject_connection(MMI_BOOL need_rsp);
static void srv_opps_connection_terminated(void);
static void srv_opps_authorize_rsp(U8 conn_id, U8 rsp_code);
static void srv_opps_connect_rsp(U8 goep_conn_id, U8 rsp_code);
static void srv_opps_abort_rsp(U8 goep_conn_id, U8 rsp_code);
static void srv_opps_push_rsp(U8 goep_conn_id, U8 rsp_code);
static void srv_opps_pull_rsp(U8 conn_id, U8 rsp_code);
static S32 srv_opps_write_file(
            FS_HANDLE handle,
            void *data,
            U32 len,
            U32 *written,
            goep_pkt_type_enum pkt_type,
            MMI_BOOL close_only);
static void srv_opps_write_file_fail(S32 fs_err);
static void srv_opps_obj_receive_ind(U32 obj_type);
static void srv_opp_truncate_obj_name(U16 *dst_name, U16 *src_name, U16 max_dst_len, MMI_BOOL convert_flag);
static U16 srv_opp_ntohs(U16 s);
static void srv_opp_get_obj_attrib(void);
static S8 *srv_opp_get_file_mime_type(U16 *name);
static S32 srv_opp_convert_fs_err_to_opp_err(S32 err);
static void srv_opp_hold_push_data(goep_push_ind_struct *data);
static void srv_opp_free_push_data(void);
static void srv_opps_disconnect_from_cm(U32 conn_id);
static void srv_opps_notify_app(U32 event_id, void *para);
static void srv_opp_send_ilm(msg_type msg_id, local_para_struct* local_para_p);



/***************************************************************************** 
* Defination
*****************************************************************************/
#define MMI_OPP_ASSERT      MMI_ASSERT

#define SRV_OPP_LOG(x) MMI_TRACE(MMI_CONN_TRC_G7_BT, x);

#define SRV_OPP_LOG1(x, x1) MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1);


#define SRV_OPP_LOG2(x, x1, x2) MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2);


#define SRV_OPP_LOG3(x, x1, x2, x3) MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3);


#define SRV_OPP_LOG_PATH(unicode_path)                        \
{                                                         \
        U8 asc_path[SRV_FMGR_PATH_MAX_LEN + 1];                               \
        mmi_ucs2_to_asc((S8 *)asc_path, (S8 *)unicode_path);          \
    SRV_OPP_LOG1(SRV_OPP_PATH_LOG, asc_path);             \
}

#define SRV_OPP_LOG_STATE() \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_OPP_CURR_STATE, srv_opps_p->opps_cntx.state, srv_oppc_p->oppc_cntx.state);

#define SRV_OPS_LOG_STATE_ERR() \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_OPP_STATE_ERROR, srv_opps_p->opps_cntx.state);

#define SRV_OPC_LOG_STATE_ERR() \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_OPP_STATE_ERROR, srv_oppc_p->oppc_cntx.state);

#define SRV_OPS_LOG_STATE(s) \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_OPP_STATE_TRANSITION, srv_opps_p->opps_cntx.state, s);

#define SRV_OPC_LOG_STATE(s) \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_OPP_STATE_TRANSITION, srv_oppc_p->oppc_cntx.state, s);

#define SRV_OPS_STATE_TRANS(s)  do {                                      \
                                    SRV_OPS_LOG_STATE(s);                 \
                                    srv_opps_p->opps_cntx.state = s;    \
                                } while (0);

#define SRV_OPC_STATE_TRANS(s)  do {                                      \
                                    SRV_OPC_LOG_STATE(s);                 \
                                    srv_oppc_p->oppc_cntx.state = s;    \
                                } while (0);

#define MMI_OPP_SND_DEFAULT_OBJNAME L"Noname"
#endif /* __SRV_OPP_H__ */ 

#endif /* __MMI_OPP_SUPPORT__ */ 

